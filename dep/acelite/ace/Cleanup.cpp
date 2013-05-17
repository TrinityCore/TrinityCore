// $Id: Cleanup.cpp 91368 2010-08-16 13:03:34Z mhengstmengel $

#include "ace/Cleanup.h"

#if !defined (ACE_HAS_INLINED_OSCALLS)
# include "ace/Cleanup.inl"
#endif /* ACE_HAS_INLINED_OSCALLS */

#include "ace/OS_Memory.h"
#include "ace/OS_NS_string.h"
#include "ace/os_include/os_typeinfo.h"

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

ACE_Cleanup_Info_Node::ACE_Cleanup_Info_Node (void)
  : object_ (0),
    cleanup_hook_ (0),
    param_ (0),
    name_ (0)
{
}

ACE_Cleanup_Info_Node::ACE_Cleanup_Info_Node (void *object,
                                              ACE_CLEANUP_FUNC cleanup_hook,
                                              void *param,
                                              const char *name)
  : object_ (object),
    cleanup_hook_ (cleanup_hook),
    param_ (param),
    name_ (name ? ACE_OS::strdup (name) : 0)
{
}

ACE_Cleanup_Info_Node::~ACE_Cleanup_Info_Node (void)
{
  if (this->name_)
    ACE_OS::free ((void *) name_);
}

bool
ACE_Cleanup_Info_Node::operator== (const ACE_Cleanup_Info_Node &o) const
{
  return o.object_ == this->object_
    && o.cleanup_hook_ == this->cleanup_hook_
    && o.param_ == this->param_;
}

bool
ACE_Cleanup_Info_Node::operator!= (const ACE_Cleanup_Info_Node &o) const
{
  return !(*this == o);
}


/*****************************************************************************/

ACE_OS_Exit_Info::ACE_OS_Exit_Info (void)
{
}

ACE_OS_Exit_Info::~ACE_OS_Exit_Info (void)
{
}

int
ACE_OS_Exit_Info::at_exit_i (void *object,
                             ACE_CLEANUP_FUNC cleanup_hook,
                             void *param,
                             const char* name)
{
  // Return -1 and sets errno if unable to allocate storage.  Enqueue
  // at the head and dequeue from the head to get LIFO ordering.
  ACE_Cleanup_Info_Node *new_node = 0;

  ACE_NEW_RETURN (new_node,
                  ACE_Cleanup_Info_Node (object, cleanup_hook, param, name),
                  -1);

  registered_objects_.push_front (new_node);

  return 0;
}

bool
ACE_OS_Exit_Info::find (void *object)
{
  for (ACE_Cleanup_Info_Node *iter = registered_objects_.head ();
       iter != 0;
       iter = iter->next ())
    {
      if (iter->object () == object)
        {
          // The object has already been registered.
          return true;
        }
    }

  return false;
}

bool
ACE_OS_Exit_Info::remove (void *object)
{
  ACE_Cleanup_Info_Node *node = 0;
  for (ACE_Cleanup_Info_Node *iter = registered_objects_.head ();
       iter != 0;
       iter = iter->next ())
    {
      if (iter->object () == object)
        {
          node = iter;
          break;
        }
    }

  if (node)
    {
      registered_objects_.remove (node);
      delete node;
      return true;
    }

  return false;
}


void
ACE_OS_Exit_Info::call_hooks (void)
{
  // Call all registered cleanup hooks, in reverse order of
  // registration.
  for (ACE_Cleanup_Info_Node *iter = registered_objects_.pop_front ();
       iter != 0;
       iter = registered_objects_.pop_front ())
    {
      if (iter->cleanup_hook () == reinterpret_cast<ACE_CLEANUP_FUNC> (
            ACE_CLEANUP_DESTROYER_NAME))
        {
          // The object is an ACE_Cleanup.
          ACE_CLEANUP_DESTROYER_NAME (
            reinterpret_cast<ACE_Cleanup *> (iter->object ()),
            iter->param ());
        }
      else if (iter->object () == &ace_exit_hook_marker)
        {
          // The hook is an ACE_EXIT_HOOK.
          (* reinterpret_cast<ACE_EXIT_HOOK> (iter->cleanup_hook ())) ();
        }
      else
        {
          (*iter->cleanup_hook ()) (iter->object (), iter->param ());
        }
      delete iter;
    }
}

ACE_END_VERSIONED_NAMESPACE_DECL
