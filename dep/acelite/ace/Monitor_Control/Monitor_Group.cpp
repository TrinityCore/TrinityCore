// $Id: Monitor_Group.cpp 93390 2011-02-15 14:44:58Z johnnyw $

#include "ace/Monitor_Control/Monitor_Group.h"

#if defined (ACE_HAS_MONITOR_FRAMEWORK) && (ACE_HAS_MONITOR_FRAMEWORK == 1)

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

namespace ACE
{
  namespace Monitor_Control
  {
    Monitor_Group::Monitor_Group (const char* name)
      : Monitor_Base (name, Monitor_Control_Types::MC_GROUP)
    {}

    void
    Monitor_Group::add_member (Monitor_Base* member)
    {
      this->members_.enqueue_tail (member);
    }

    void
    Monitor_Group::update (void)
    {
      for (MEMBERS_ITERATOR i (this->members_); !i.done (); i.advance ())
        {
          Monitor_Base **member;
          i.next (member);
          (*member)->update ();
        }
    }

    void
    Monitor_Group::receive (double /* data */)
    {
      /// No-op, should always call update().
    }

    void
    Monitor_Group::receive (size_t /* data */)
    {
      /// No-op, should always call update().
    }

    void
    Monitor_Group::receive (const Monitor_Control_Types::NameList& /* data */)
    {
      /// No-op, should always call update().
    }

    void
    Monitor_Group::clear (void)
    {
      for (MEMBERS_ITERATOR i (this->members_); !i.done (); i.advance ())
        {
          Monitor_Base **member = 0;
          i.next (member);
          (*member)->clear ();
        }
    }
  }
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_HAS_MONITOR_FRAMEWORK==1 */
