// $Id: Monitor_Point_Registry.cpp 81833 2008-06-04 14:44:53Z parsons $
#include "ace/Monitor_Point_Registry.h"
#if defined (ACE_HAS_MONITOR_FRAMEWORK) && (ACE_HAS_MONITOR_FRAMEWORK == 1)
#include "ace/Monitor_Base.h"
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
namespace ACE
{
  namespace Monitor_Control
  {
    Monitor_Point_Registry*
    Monitor_Point_Registry::instance (void)
    {
      return
        ACE_Singleton<Monitor_Point_Registry, ACE_SYNCH_MUTEX>::instance ();
    }
    Monitor_Point_Registry::Monitor_Point_Registry (void)
      : constraint_id_ (0)
    {
    }
    bool
    Monitor_Point_Registry::add (Monitor_Base* type)
    {
      if (type == 0)
        {
          ACE_ERROR_RETURN ((LM_ERROR,
                             "registry add: null type\n"),
                            false);
        }
      int status = 0;
      {
        ACE_GUARD_RETURN (ACE_SYNCH_MUTEX, guard, this->mutex_, false);
        type->add_ref ();
        status = this->map_.bind (type->name (), type);
        /// Temporary debugging code.
//        ACE_DEBUG ((LM_DEBUG, "adding %s\n", type->name ()));
      }
      if (status == -1)
        {
          ACE_ERROR_RETURN ((LM_ERROR,
                             "registry add: map bind failed\n"),
                            false);
        }
      return (status == 0);
    }
    bool
    Monitor_Point_Registry::remove (const char* name)
    {
      if (name == 0)
        {
          ACE_ERROR_RETURN ((LM_ERROR,
                             "registry remove: null name\n"),
                            false);
        }
      int status = 0;
      Map::data_type mp = 0;
      {
        ACE_GUARD_RETURN (ACE_SYNCH_MUTEX, guard, this->mutex_, false);
        ACE_CString name_str (name, 0, false);
        status = this->map_.unbind (name_str, mp);
        /// Temporary debugging code.
//        ACE_DEBUG ((LM_DEBUG, "removing %s\n", name_str.c_str ()));
      }
      if (status == -1)
        {
// (JP) There is a problem with this failing on a single ACE_Message_Queue
//      monitor per process. I think it is the message queue associated
//      with the default reactor, maybe because at that low level, ACE
//      is using malloc with placement, then free, which may bypass the
//      normal destructors. In any case, it happens only at shutdown
//      and there seems to be no memory leak.
//          ACE_ERROR_RETURN ((LM_ERROR,
//                             "registry remove: unbind failed for %s\n",
//                             name),
//                            false);
        }
      else
        {
          mp->remove_ref ();
        }
      return (status == 0);
    }
    Monitor_Control_Types::NameList
    Monitor_Point_Registry::names (void)
    {
      Monitor_Control_Types::NameList name_holder_;
      {
        ACE_GUARD_RETURN (ACE_SYNCH_MUTEX, guard, this->mutex_, 0);
        for (Map::CONST_ITERATOR i (this->map_); !i.done (); i.advance ())
          {
            name_holder_.push_back (i->key ());
          }
      }
      return name_holder_;
    }
    Monitor_Base*
    Monitor_Point_Registry::get (const ACE_CString& name) const
    {
      Map::data_type mp = 0;
      {
        ACE_GUARD_RETURN (ACE_SYNCH_MUTEX, guard, this->mutex_, 0);
        this->map_.find (name, mp);
      }
      if (mp != 0)
        {
          mp->add_ref ();
        }
      return mp;
    }
    long
    Monitor_Point_Registry::constraint_id (void)
    {
      long retval = 0;
      {
        ACE_GUARD_RETURN (ACE_SYNCH_MUTEX, guard, this->mutex_, -1);
        retval = this->constraint_id_++;
      }
      return retval;
    }
    void
    Monitor_Point_Registry::cleanup (void)
    {
      for (Map::ITERATOR i = this->map_.begin ();
           i != this->map_.end ();
           i.advance ())
        {
          Map::ENTRY* entry = 0;
          i.next (entry);
          entry->int_id_->remove_ref ();
        }
    }
  }
}
ACE_END_VERSIONED_NAMESPACE_DECL
#endif /* ACE_HAS_MONITOR_FRAMEWORK==1 */

