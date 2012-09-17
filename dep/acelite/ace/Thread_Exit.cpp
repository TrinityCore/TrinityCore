// $Id: Thread_Exit.cpp 92580 2010-11-15 09:48:02Z johnnyw $

#include "ace/Thread_Exit.h"
#include "ace/Managed_Object.h"
#include "ace/Thread_Manager.h"
#include "ace/Guard_T.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

bool ACE_Thread_Exit::is_constructed_ = false;

void
ACE_Thread_Exit::cleanup (void *instance)
{
  ACE_OS_TRACE ("ACE_Thread_Exit::cleanup");

  delete (ACE_TSS_TYPE (ACE_Thread_Exit) *) instance;

  // Set the thr_exit_ static to null to keep things from crashing if
  // ACE::fini() is enabled here.
  ACE_Thread_Manager::thr_exit_ = 0;

  ACE_Thread_Exit::is_constructed_ = false;
  // All TSS objects have been destroyed.  Reset this flag so
  // ACE_Thread_Exit singleton can be created again.
}

// NOTE: this preprocessor directive should match the one in
// ACE_Task_Base::svc_run () below.  This prevents the two statics
// from being defined.

ACE_Thread_Exit *
ACE_Thread_Exit::instance (void)
{
#if defined (ACE_HAS_THREAD_SPECIFIC_STORAGE) || defined (ACE_HAS_TSS_EMULATION)
  ACE_OS_TRACE ("ACE_Thread_Exit::instance");

  // Determines if we were dynamically allocated.
  static ACE_TSS_TYPE (ACE_Thread_Exit) * volatile instance_;

  // Implement the Double Check pattern.

  if (!ACE_Thread_Exit::is_constructed_)
    {
      ACE_MT (ACE_Thread_Mutex *lock =
              ACE_Managed_Object<ACE_Thread_Mutex>::get_preallocated_object
                (ACE_Object_Manager::ACE_THREAD_EXIT_LOCK);
              ACE_GUARD_RETURN (ACE_Thread_Mutex, ace_mon, *lock, 0));

      if (!ACE_Thread_Exit::is_constructed_)
        {
          ACE_NEW_RETURN (instance_,
                          ACE_TSS_TYPE (ACE_Thread_Exit),
                          0);

          ACE_Thread_Exit::is_constructed_ = true;

          ACE_Thread_Manager::set_thr_exit (instance_);
        }
    }

  return ACE_TSS_GET (instance_, ACE_Thread_Exit);
#else
  return 0;
#endif /* ACE_HAS_THREAD_SPECIFIC_STORAGE || ACE_HAS_TSS_EMULATION */
}

// Grab hold of the Task * so that we can close() it in the
// destructor.

ACE_Thread_Exit::ACE_Thread_Exit (void)
{
  ACE_OS_TRACE ("ACE_Thread_Exit::ACE_Thread_Exit");
}

// Set the this pointer...

void
ACE_Thread_Exit::thr_mgr (ACE_Thread_Manager *tm)
{
  ACE_OS_TRACE ("ACE_Thread_Exit::thr_mgr");

  if (tm != 0)
    this->thread_control_.insert (tm, 0);
}

// When this object is destroyed the Task is automatically closed
// down!

ACE_Thread_Exit::~ACE_Thread_Exit (void)
{
  ACE_OS_TRACE ("ACE_Thread_Exit::~ACE_Thread_Exit");
}

ACE_Thread_Exit_Maybe::ACE_Thread_Exit_Maybe (int flag)
  : instance_ (0)
{
  if (flag)
    {
      ACE_NEW (instance_, ACE_Thread_Exit);
    }
}

ACE_Thread_Exit_Maybe::~ACE_Thread_Exit_Maybe (void)
{
  delete this->instance_;
}

ACE_Thread_Exit *
ACE_Thread_Exit_Maybe::operator -> (void) const
{
  return this->instance_;
}

ACE_Thread_Exit *
ACE_Thread_Exit_Maybe::instance (void) const
{
  return this->instance_;
}

ACE_END_VERSIONED_NAMESPACE_DECL
