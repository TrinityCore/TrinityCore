/**
 * @file Recursive_Thread_Mutex.cpp
 *
 * $Id: Recursive_Thread_Mutex.cpp 82253 2008-07-04 20:18:14Z shuston $
 *
 * Originally in Synch.cpp
 *
 * @author Douglas C. Schmidt <schmidt@cs.wustl.edu>
 */

#include "ace/Recursive_Thread_Mutex.h"

#if defined (ACE_HAS_THREADS)

#if !defined (__ACE_INLINE__)
#include "ace/Recursive_Thread_Mutex.inl"
#endif /* __ACE_INLINE__ */

#include "ace/Log_Msg.h"

ACE_RCSID(ace, Recursive_Thread_Mutex, "$Id: Recursive_Thread_Mutex.cpp 82253 2008-07-04 20:18:14Z shuston $")

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_ALLOC_HOOK_DEFINE(ACE_Recursive_Thread_Mutex)

ACE_Recursive_Thread_Mutex::ACE_Recursive_Thread_Mutex (const ACE_TCHAR *name,
                                                        ACE_mutexattr_t *arg)
  : removed_ (false)
{
  // ACE_TRACE ("ACE_Recursive_Thread_Mutex::ACE_Recursive_Thread_Mutex");
   if (ACE_OS::recursive_mutex_init (&this->lock_,
                                     name,
                                     arg) == -1)
     ACE_ERROR ((LM_ERROR,
                 ACE_TEXT ("%p\n"),
                 ACE_TEXT ("recursive_mutex_init")));
}

ACE_Recursive_Thread_Mutex::~ACE_Recursive_Thread_Mutex (void)
{
  // ACE_TRACE ("ACE_Recursive_Thread_Mutex::~ACE_Recursive_Thread_Mutex");
  this->remove ();
}

int
ACE_Recursive_Thread_Mutex::remove (void)
{
// ACE_TRACE ("ACE_Recursive_Thread_Mutex::remove");
  int result = 0;
  if (this->removed_ == false)
    {
      this->removed_ = true;
      result = ACE_OS::recursive_mutex_destroy (&this->lock_);
    }
  return result;
}

// The counter part of the following two functions for Win32 are
// located in file Synch.i
ACE_thread_t
ACE_Recursive_Thread_Mutex::get_thread_id (void)
{
  // ACE_TRACE ("ACE_Recursive_Thread_Mutex::get_thread_id");
#if defined (ACE_HAS_RECURSIVE_MUTEXES)
  // @@ The structure CriticalSection in Win32 doesn't hold the thread
  // handle of the thread that owns the lock.  However it is still not
  // clear at this point how to translate a thread handle to its
  // corresponding thread id.
  errno = ENOTSUP;
  return ACE_OS::NULL_thread;
#else
  ACE_thread_t owner_id;
  ACE_OS::mutex_lock (&this->lock_.nesting_mutex_);
  owner_id = this->lock_.owner_id_;
  ACE_OS::mutex_unlock (&this->lock_.nesting_mutex_);
  return owner_id;
#endif /* ACE_WIN32 */
}

int
ACE_Recursive_Thread_Mutex::get_nesting_level (void)
{
  // ACE_TRACE ("ACE_Recursive_Thread_Mutex::get_nesting_level");
#if defined (ACE_HAS_WINCE) || defined (ACE_HAS_VXTHREADS) || defined (ACE_HAS_PHARLAP)
  ACE_NOTSUP_RETURN (-1);
#elif defined (ACE_HAS_RECURSIVE_MUTEXES)
# if defined (ACE_WIN32)
  // This is really a Win32-ism...
  // Nothing inside of a CRITICAL_SECTION object should ever be
  // accessed directly.  It is documented to change at any time.
  //
  // It has been reported that this this works for all three
  // architectures.  However, this does not work on Win64 before SP1.
  return this->lock_.RecursionCount;
# else
  ACE_NOTSUP_RETURN (-1);
# endif /* ACE_WIN32 */
#else
  int nesting_level = 0;
  ACE_OS::mutex_lock (&this->lock_.nesting_mutex_);
  nesting_level = this->lock_.nesting_level_;
  ACE_OS::mutex_unlock (&this->lock_.nesting_mutex_);
  return nesting_level;
#endif /* !ACE_HAS_WINCE */
}

ACE_Recursive_Thread_Mutex::ACE_Recursive_Thread_Mutex (const ACE_Recursive_Thread_Mutex &)
{
}

void
ACE_Recursive_Thread_Mutex::dump (void) const
{
#if defined (ACE_HAS_DUMP)
// ACE_TRACE ("ACE_Recursive_Thread_Mutex::dump");

  ACE_DEBUG ((LM_DEBUG, ACE_BEGIN_DUMP, this));
  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
#endif /* ACE_HAS_DUMP */
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_HAS_THREADS */

