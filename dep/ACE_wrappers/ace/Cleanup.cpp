// $Id: Cleanup.cpp 80826 2008-03-04 14:51:23Z wotte $
#include "ace/Cleanup.h"
ACE_RCSID (ace,
           Cleanup,
           "$Id: Cleanup.cpp 80826 2008-03-04 14:51:23Z wotte $")
#if !defined (ACE_HAS_INLINED_OSCALLS)
# include "ace/Cleanup.inl"
#endif /* ACE_HAS_INLINED_OSCALLS */
#include "ace/OS_Memory.h"
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
void
ACE_Cleanup::cleanup (void *)
{
  delete this;
}

ACE_Cleanup::~ACE_Cleanup (void)
{
}
/*****************************************************************************/
extern "C" void
ACE_CLEANUP_DESTROYER_NAME (ACE_Cleanup *object, void *param)
{
  object->cleanup (param);
}
/*****************************************************************************/
ACE_Cleanup_Info::ACE_Cleanup_Info (void)
  : object_ (0),
    cleanup_hook_ (0),
    param_ (0)
{
}
bool
ACE_Cleanup_Info::operator== (const ACE_Cleanup_Info &o) const
{
  return o.object_ == this->object_
    && o.cleanup_hook_ == this->cleanup_hook_
    && o.param_ == this->param_;
}
bool
ACE_Cleanup_Info::operator!= (const ACE_Cleanup_Info &o) const
{
  return !(*this == o);
}
/*****************************************************************************/
/**
 * @class ACE_Cleanup_Info_Node
 *
 * @brief For maintaining a list of ACE_Cleanup_Info items.
 *
 * For internal use by ACE_Object_Manager.
 */
class ACE_Cleanup_Info_Node
{
public:
  ACE_Cleanup_Info_Node (void);
  ACE_Cleanup_Info_Node (const ACE_Cleanup_Info &new_info,
                         ACE_Cleanup_Info_Node *next);
  ~ACE_Cleanup_Info_Node (void);
  ACE_Cleanup_Info_Node *insert (const ACE_Cleanup_Info &);
private:
  ACE_Cleanup_Info cleanup_info_;
  ACE_Cleanup_Info_Node *next_;
  friend class ACE_OS_Exit_Info;
};
ACE_Cleanup_Info_Node::ACE_Cleanup_Info_Node (void)
  : cleanup_info_ (),
    next_ (0)
{
}
ACE_Cleanup_Info_Node::ACE_Cleanup_Info_Node (const ACE_Cleanup_Info &new_info,
                                              ACE_Cleanup_Info_Node *next)
  : cleanup_info_ (new_info),
    next_ (next)
{
}
ACE_Cleanup_Info_Node::~ACE_Cleanup_Info_Node (void)
{
  delete next_;
}
ACE_Cleanup_Info_Node *
ACE_Cleanup_Info_Node::insert (const ACE_Cleanup_Info &new_info)
{
  ACE_Cleanup_Info_Node *new_node = 0;
  ACE_NEW_RETURN (new_node,
                  ACE_Cleanup_Info_Node (new_info, this),
                  0);
  return new_node;
}
/*****************************************************************************/
ACE_OS_Exit_Info::ACE_OS_Exit_Info (void)
{
  ACE_NEW (registered_objects_, ACE_Cleanup_Info_Node);
}
ACE_OS_Exit_Info::~ACE_OS_Exit_Info (void)
{
  delete registered_objects_;
  registered_objects_ = 0;
}
int
ACE_OS_Exit_Info::at_exit_i (void *object,
                             ACE_CLEANUP_FUNC cleanup_hook,
                             void *param)
{
  ACE_Cleanup_Info new_info;
  new_info.object_ = object;
  new_info.cleanup_hook_ = cleanup_hook;
  new_info.param_ = param;
  // Return -1 and sets errno if unable to allocate storage.  Enqueue
  // at the head and dequeue from the head to get LIFO ordering.
  ACE_Cleanup_Info_Node *new_node = 0;
  if ((new_node = registered_objects_->insert (new_info)) == 0)
    return -1;
  else
    {
      registered_objects_ = new_node;
      return 0;
    }
}
int
ACE_OS_Exit_Info::find (void *object)
{
  // Check for already in queue, and return 1 if so.
  for (ACE_Cleanup_Info_Node *iter = registered_objects_;
       iter  &&  iter->next_ != 0;
       iter = iter->next_)
    {
      if (iter->cleanup_info_.object_ == object)
        {
          // The object has already been registered.
          return 1;
        }
    }
  return 0;
}
void
ACE_OS_Exit_Info::call_hooks (void)
{
  // Call all registered cleanup hooks, in reverse order of
  // registration.
  for (ACE_Cleanup_Info_Node *iter = registered_objects_;
       iter  &&  iter->next_ != 0;
       iter = iter->next_)
    {
      ACE_Cleanup_Info &info = iter->cleanup_info_;
      if (info.cleanup_hook_ == reinterpret_cast<ACE_CLEANUP_FUNC> (
            ACE_CLEANUP_DESTROYER_NAME))
        // The object is an ACE_Cleanup.
        ACE_CLEANUP_DESTROYER_NAME (
          reinterpret_cast<ACE_Cleanup *> (info.object_),
          info.param_);
      else if (info.object_ == &ace_exit_hook_marker)
        // The hook is an ACE_EXIT_HOOK.
        (* reinterpret_cast<ACE_EXIT_HOOK> (info.cleanup_hook_)) ();
      else
        (*info.cleanup_hook_) (info.object_, info.param_);
    }
}
ACE_END_VERSIONED_NAMESPACE_DECL

