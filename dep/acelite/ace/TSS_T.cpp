// $Id: TSS_T.cpp 91693 2010-09-09 12:57:54Z johnnyw $

#ifndef ACE_TSS_T_CPP
#define ACE_TSS_T_CPP

#include "ace/TSS_T.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if !defined (__ACE_INLINE__)
#include "ace/TSS_T.inl"
#endif /* __ACE_INLINE__ */

#include "ace/Thread.h"
#include "ace/Log_Msg.h"
#include "ace/Guard_T.h"
#include "ace/OS_NS_stdio.h"

#if defined (ACE_HAS_THR_C_DEST)
#  include "ace/TSS_Adapter.h"
#endif /* ACE_HAS_THR_C_DEST */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_ALLOC_HOOK_DEFINE(ACE_TSS)

#if defined (ACE_HAS_THREADS) && (defined (ACE_HAS_THREAD_SPECIFIC_STORAGE) || defined (ACE_HAS_TSS_EMULATION))
# if defined (ACE_HAS_THR_C_DEST)
extern "C" void ACE_TSS_C_cleanup (void *);
# endif /* ACE_HAS_THR_C_DEST */
#endif /* defined (ACE_HAS_THREADS) && (defined (ACE_HAS_THREAD_SPECIFIC_STORAGE) || defined (ACE_HAS_TSS_EMULATION)) */

template <class TYPE>
ACE_TSS<TYPE>::~ACE_TSS (void)
{
#if defined (ACE_HAS_THREADS) && (defined (ACE_HAS_THREAD_SPECIFIC_STORAGE) || defined (ACE_HAS_TSS_EMULATION))
  if (this->once_)
  {
# if defined (ACE_HAS_THR_C_DEST)
    ACE_TSS_Adapter *tss_adapter = this->ts_value ();
    this->ts_value (0);
    ACE_TSS_C_cleanup (tss_adapter);
# else
    TYPE *ts_obj = this->ts_value ();
    this->ts_value (0);
    ACE_TSS<TYPE>::cleanup (ts_obj);
# endif /* ACE_HAS_THR_C_DEST */

    ACE_OS::thr_key_detach (this->key_);
    ACE_OS::thr_keyfree (this->key_);
  }
#else // defined (ACE_HAS_THREADS) && (defined (ACE_HAS_THREAD_SPECIFIC_STORAGE) || defined (ACE_HAS_TSS_EMULATION))
  // We own it, we need to delete it.
  delete type_;
#endif // defined (ACE_HAS_THREADS) && (defined (ACE_HAS_THREAD_SPECIFIC_STORAGE) || defined (ACE_HAS_TSS_EMULATION))
}

template <class TYPE> TYPE *
ACE_TSS<TYPE>::operator-> () const
{
  return this->ts_get ();
}

template <class TYPE>
ACE_TSS<TYPE>::operator TYPE *(void) const
{
  return this->ts_get ();
}

template <class TYPE> TYPE *
ACE_TSS<TYPE>::make_TSS_TYPE (void) const
{
  TYPE *temp = 0;
  ACE_NEW_RETURN (temp,
                  TYPE,
                  0);
  return temp;
}

template <class TYPE> void
ACE_TSS<TYPE>::dump (void) const
{
#if defined (ACE_HAS_DUMP)
#if defined (ACE_HAS_THREADS) && (defined (ACE_HAS_THREAD_SPECIFIC_STORAGE) || defined (ACE_HAS_TSS_EMULATION))
  ACE_DEBUG ((LM_DEBUG, ACE_BEGIN_DUMP, this));
  this->keylock_.dump ();
  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("key_ = %d\n"), this->key_));
  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("\nonce_ = %d\n"), this->once_));
  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
#endif /* defined (ACE_HAS_THREADS) && (defined (ACE_HAS_THREAD_SPECIFIC_STORAGE) || defined (ACE_HAS_TSS_EMULATION)) */
#endif /* ACE_HAS_DUMP */
}

#if defined (ACE_HAS_THREADS) && (defined (ACE_HAS_THREAD_SPECIFIC_STORAGE) || defined (ACE_HAS_TSS_EMULATION))

template <class TYPE> void
ACE_TSS<TYPE>::cleanup (void *ptr)
{
  // Cast this to the concrete TYPE * so the destructor gets called.
  delete (TYPE *) ptr;
}

template <class TYPE> int
ACE_TSS<TYPE>::ts_init (void)
{
  // Ensure that we are serialized!
  ACE_GUARD_RETURN (ACE_Thread_Mutex, ace_mon, this->keylock_, 0);

  // Use the Double-Check pattern to make sure we only create the key
  // once!
  if (!this->once_)
    {
      if (ACE_Thread::keycreate (&this->key_,
#if defined (ACE_HAS_THR_C_DEST)
                                 &ACE_TSS_C_cleanup
#else
                                 &ACE_TSS<TYPE>::cleanup
#endif /* ACE_HAS_THR_C_DEST */
                                 ) != 0)
        return -1; // Major problems, this should *never* happen!
      else
        {
          // This *must* come last to avoid race conditions!
          this->once_ = true;
          return 0;
        }
    }

  return 0;
}

template <class TYPE>
ACE_TSS<TYPE>::ACE_TSS (TYPE *ts_obj)
  : once_ (false),
    key_ (ACE_OS::NULL_key)
{
  // If caller has passed us a non-NULL TYPE *, then we'll just use
  // this to initialize the thread-specific value.  Thus, subsequent
  // calls to operator->() will return this value.  This is useful
  // since it enables us to assign objects to thread-specific data
  // that have arbitrarily complex constructors!

  if (ts_obj != 0)
    {
      if (this->ts_init () == -1)
        {
          // Save/restore errno.
          ACE_Errno_Guard error (errno);
          // What should we do if this call fails?!
#if defined (ACE_HAS_WINCE)
          ::MessageBox (0,
                        ACE_TEXT ("ACE_Thread::keycreate() failed!"),
                        ACE_TEXT ("ACE_TSS::ACE_TSS"),
                        MB_OK);
#else
          ACE_OS::fprintf (stderr,
                           "ACE_Thread::keycreate() failed!");
#endif /* ACE_HAS_WINCE */
          return;
        }

#if defined (ACE_HAS_THR_C_DEST)
      // Encapsulate a ts_obj and it's destructor in an
      // ACE_TSS_Adapter.
      ACE_TSS_Adapter *tss_adapter = 0;
      ACE_NEW (tss_adapter,
               ACE_TSS_Adapter ((void *) ts_obj,
                                ACE_TSS<TYPE>::cleanup));

      // Put the adapter in thread specific storage
      if (this->ts_value (tss_adapter) == -1)
        {
          delete tss_adapter;
        }
#else
      this->ts_value (ts_obj);
#endif /* ACE_HAS_THR_C_DEST */
    }
}

template <class TYPE> TYPE *
ACE_TSS<TYPE>::ts_get (void) const
{
  if (!this->once_)
    {
      // Create and initialize thread-specific ts_obj.
      if (const_cast< ACE_TSS < TYPE > * >(this)->ts_init () == -1)
        // Seriously wrong..
        return 0;
    }

  TYPE *ts_obj = 0;

#if defined (ACE_HAS_THR_C_DEST)
  ACE_TSS_Adapter *tss_adapter = this->ts_value ();
  ACE_TSS_Adapter *fake_tss_adapter = 0;

  // If tss_adapter is not 0 but its ts_obj_ is 0 then we still need to create
  // a proper ts_obj. That's the intent of this member function.
  if (tss_adapter != 0 && tss_adapter->ts_obj_ == 0)
    {
      fake_tss_adapter = tss_adapter;
      tss_adapter = 0;
    }

  // Check to see if this is the first time in for this thread.
  if (tss_adapter == 0)
#else
  ts_obj = this->ts_value ();

  // Check to see if this is the first time in for this thread.
  if (ts_obj == 0)
#endif /* ACE_HAS_THR_C_DEST */
    {
      // Allocate memory off the heap and store it in a pointer in
      // thread-specific storage (on the stack...).

      ts_obj = this->make_TSS_TYPE ();

      if (ts_obj == 0)
        return 0;

#if defined (ACE_HAS_THR_C_DEST)
      // Encapsulate a ts_obj and it's destructor in an
      // ACE_TSS_Adapter.
      ACE_NEW_RETURN (tss_adapter,
                      ACE_TSS_Adapter (ts_obj,
                                       ACE_TSS<TYPE>::cleanup), 0);

      // Put the adapter in thread specific storage
      if (this->ts_value (tss_adapter) == -1)
        {
          delete tss_adapter;
          delete ts_obj;
          return 0; // Major problems, this should *never* happen!
        }
#else
      // Store the dynamically allocated pointer in thread-specific
      // storage.
      if (this->ts_value (ts_obj) == -1)
        {
          delete ts_obj;
          return 0; // Major problems, this should *never* happen!
        }
#endif /* ACE_HAS_THR_C_DEST */
    }

#if defined (ACE_HAS_THR_C_DEST)
  // Delete the adapter that didn't actually have a real ts_obj.
  delete fake_tss_adapter;
  // Return the underlying ts object.
  return static_cast <TYPE *> (tss_adapter->ts_obj_);
#else
  return ts_obj;
#endif /* ACE_HAS_THR_C_DEST */
}

// Get the thread-specific object for the key associated with this
// object.  Returns 0 if the ts_obj has never been initialized,
// otherwise returns a pointer to the ts_obj.

template <class TYPE> TYPE *
ACE_TSS<TYPE>::ts_object (void) const
{
  if (!this->once_) // Return 0 if we've never been initialized.
    return 0;

  TYPE *ts_obj = 0;

#if defined (ACE_HAS_THR_C_DEST)
  ACE_TSS_Adapter *tss_adapter = this->ts_value ();

  if (tss_adapter != 0)
    {
      // Extract the real TS object.
      ts_obj = static_cast <TYPE *> (tss_adapter->ts_obj_);
    }
#else
  ts_obj = this->ts_value ();
#endif /* ACE_HAS_THR_C_DEST */

  return ts_obj;
}

template <class TYPE> TYPE *
ACE_TSS<TYPE>::ts_object (TYPE *new_ts_obj)
{
  // Note, we shouldn't hold the keylock at this point because
  // <ts_init> does it for us and we'll end up with deadlock
  // otherwise...
  if (!this->once_)
    {
      // Create and initialize thread-specific ts_obj.
      if (this->ts_init () == -1)
        return 0;
    }

  TYPE *ts_obj = 0;

#if defined (ACE_HAS_THR_C_DEST)
  ACE_TSS_Adapter *tss_adapter = this->ts_value ();

  if (tss_adapter != 0)
    {
      ts_obj = static_cast <TYPE *> (tss_adapter->ts_obj_);
      // Don't delete tss_adapter yet. It can be double-deleted
      // in case setspecific below fails.
    }

  ACE_TSS_Adapter *new_tss_adapter = 0;
  ACE_NEW_RETURN (new_tss_adapter,
                  ACE_TSS_Adapter ((void *) new_ts_obj,
                                   ACE_TSS<TYPE>::cleanup),
                  0);

  if (this->ts_value (new_tss_adapter) == -1)
    {
      delete new_tss_adapter;
    }
  else
    {
      // Now it's fine to delete the old tss_adapter.
      delete tss_adapter;
    }
#else
  ts_obj = this->ts_value ();
  this->ts_value (new_ts_obj);
#endif /* ACE_HAS_THR_C_DEST */

  return ts_obj;
}

ACE_ALLOC_HOOK_DEFINE(ACE_TSS_Guard)

template <class ACE_LOCK> void
ACE_TSS_Guard<ACE_LOCK>::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_DEBUG ((LM_DEBUG, ACE_BEGIN_DUMP, this));
  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("key_ = %d\n"), this->key_));
  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
#endif /* ACE_HAS_DUMP */
}

template <class ACE_LOCK> void
ACE_TSS_Guard<ACE_LOCK>::init_key (void)
{
  this->key_ = ACE_OS::NULL_key;
  ACE_Thread::keycreate (&this->key_,
#if defined (ACE_HAS_THR_C_DEST)
                         &ACE_TSS_C_cleanup,
#else
                         &ACE_TSS_Guard<ACE_LOCK>::cleanup,
#endif /* ACE_HAS_THR_C_DEST */
                         (void *) this);
}

template <class ACE_LOCK>
ACE_TSS_Guard<ACE_LOCK>::ACE_TSS_Guard (void)
{
  this->init_key ();
}

template <class ACE_LOCK> int
ACE_TSS_Guard<ACE_LOCK>::release (void)
{
  Guard_Type *guard = 0;

#if defined (ACE_HAS_THR_C_DEST)
  ACE_TSS_Adapter *tss_adapter = 0;
  void *temp = tss_adapter; // Need this temp to keep G++ from complaining.
  ACE_Thread::getspecific (this->key_, &temp);
  tss_adapter = static_cast <ACE_TSS_Adapter *> (temp);
  guard = static_cast <Guard_Type *> (tss_adapter->ts_obj_);
#else
  void *temp = guard; // Need this temp to keep G++ from complaining.
  ACE_Thread::getspecific (this->key_, &temp);
  guard = static_cast <Guard_Type *> (temp);
#endif /* ACE_HAS_THR_C_DEST */

  return guard->release ();
}

template <class ACE_LOCK> int
ACE_TSS_Guard<ACE_LOCK>::remove (void)
{
  Guard_Type *guard = 0;

#if defined (ACE_HAS_THR_C_DEST)
  ACE_TSS_Adapter *tss_adapter = 0;
  void *temp = tss_adapter; // Need this temp to keep G++ from complaining.
  ACE_Thread::getspecific (this->key_, &temp);
  tss_adapter = static_cast <ACE_TSS_Adapter *> (temp);
  guard = static_cast <Guard_Type *> (tss_adapter->ts_obj_);
#else
  void *temp = guard; // Need this temp to keep G++ from complaining.
  ACE_Thread::getspecific (this->key_, &temp);
  guard = static_cast <Guard_Type *> (temp);
#endif /* ACE_HAS_THR_C_DEST */

  return guard->remove ();
}

template <class ACE_LOCK>
ACE_TSS_Guard<ACE_LOCK>::~ACE_TSS_Guard (void)
{
  Guard_Type *guard = 0;

#if defined (ACE_HAS_THR_C_DEST)
  ACE_TSS_Adapter *tss_adapter = 0;
  void *temp = tss_adapter; // Need this temp to keep G++ from complaining.
  ACE_Thread::getspecific (this->key_, &temp);
  tss_adapter = static_cast <ACE_TSS_Adapter *> (temp);
  guard = static_cast <Guard_Type *> (tss_adapter->ts_obj_);
#else
  void *temp = guard; // Need this temp to keep G++ from complaining.
  ACE_Thread::getspecific (this->key_, &temp);
  guard = static_cast <Guard_Type *> (temp);
#endif /* ACE_HAS_THR_C_DEST */

  // Make sure that this pointer is NULL when we shut down...
  ACE_Thread::setspecific (this->key_, 0);
  ACE_Thread::keyfree (this->key_);
  // Destructor releases lock.
  delete guard;
}

template <class ACE_LOCK> void
ACE_TSS_Guard<ACE_LOCK>::cleanup (void *ptr)
{
  // Destructor releases lock.
  delete (Guard_Type *) ptr;
}

template <class ACE_LOCK>
ACE_TSS_Guard<ACE_LOCK>::ACE_TSS_Guard (ACE_LOCK &lock, bool block)
{
  this->init_key ();
  Guard_Type *guard = 0;
  ACE_NEW (guard,
           Guard_Type (lock, block));

#if defined (ACE_HAS_THR_C_DEST)
  ACE_TSS_Adapter *tss_adapter = 0;
  ACE_NEW (tss_adapter,
           ACE_TSS_Adapter ((void *) guard,
                            ACE_TSS_Guard<ACE_LOCK>::cleanup));
  ACE_Thread::setspecific (this->key_,
                           (void *) tss_adapter);
#else
  ACE_Thread::setspecific (this->key_,
                           (void *) guard);
#endif /* ACE_HAS_THR_C_DEST */
}

template <class ACE_LOCK> int
ACE_TSS_Guard<ACE_LOCK>::acquire (void)
{
  Guard_Type *guard = 0;

#if defined (ACE_HAS_THR_C_DEST)
  ACE_TSS_Adapter *tss_adapter = 0;
  void *temp = tss_adapter; // Need this temp to keep G++ from complaining.
  ACE_Thread::getspecific (this->key_, &temp);
  tss_adapter = static_cast <ACE_TSS_Adapter *> (temp);
  guard = static_cast <Guard_Type *> (tss_adapter->ts_obj_);
#else
  void *temp = guard; // Need this temp to keep G++ from complaining.
  ACE_Thread::getspecific (this->key_, &temp);
  guard = static_cast <Guard_Type *> (temp);
#endif /* ACE_HAS_THR_C_DEST */

  return guard->acquire ();
}

template <class ACE_LOCK> int
ACE_TSS_Guard<ACE_LOCK>::tryacquire (void)
{
  Guard_Type *guard = 0;

#if defined (ACE_HAS_THR_C_DEST)
  ACE_TSS_Adapter *tss_adapter = 0;
  void *temp = tss_adapter; // Need this temp to keep G++ from complaining.
  ACE_Thread::getspecific (this->key_, &temp);
  tss_adapter = static_cast <ACE_TSS_Adapter *> (temp);
  guard = static_cast <Guard_Type *> (tss_adapter->ts_obj_);
#else
  void *temp = guard; // Need this temp to keep G++ from complaining.
  ACE_Thread::getspecific (this->key_, &temp);
  guard = static_cast <Guard_Type *> (temp);
#endif /* ACE_HAS_THR_C_DEST */

  return guard->tryacquire ();
}

template <class ACE_LOCK>
ACE_TSS_Write_Guard<ACE_LOCK>::ACE_TSS_Write_Guard (ACE_LOCK &lock,
                                                    bool block)
{
  this->init_key ();
  Guard_Type *guard = 0;
  ACE_NEW (guard,
           Write_Guard_Type (lock, block));

#if defined (ACE_HAS_THR_C_DEST)
  ACE_TSS_Adapter *tss_adapter = 0;
  ACE_NEW (tss_adapter,
           ACE_TSS_Adapter ((void *) guard,
                            ACE_TSS_Guard<ACE_LOCK>::cleanup));
  ACE_Thread::setspecific (this->key_, (void *) tss_adapter);
#else
  ACE_Thread::setspecific (this->key_, (void *) guard);
#endif /* ACE_HAS_THR_C_DEST */
}

template <class ACE_LOCK> int
ACE_TSS_Write_Guard<ACE_LOCK>::acquire (void)
{
  Write_Guard_Type *guard = 0;

#if defined (ACE_HAS_THR_C_DEST)
  ACE_TSS_Adapter *tss_adapter = 0;
  void *temp = tss_adapter; // Need this temp to keep G++ from complaining.
  ACE_Thread::getspecific (this->key_, &temp);
  tss_adapter = static_cast <ACE_TSS_Adapter *> (temp);
  guard = static_cast <Write_Guard_Type *> (tss_adapter->ts_obj_);
#else
  void *temp = guard; // Need this temp to keep G++ from complaining.
  ACE_Thread::getspecific (this->key_, &temp);
  guard = static_cast <Write_Guard_Type *> (temp);
#endif /* ACE_HAS_THR_C_DEST */

  return guard->acquire_write ();
}

template <class ACE_LOCK> int
ACE_TSS_Write_Guard<ACE_LOCK>::tryacquire (void)
{
  Write_Guard_Type *guard = 0;

#if defined (ACE_HAS_THR_C_DEST)
  ACE_TSS_Adapter *tss_adapter = 0;
  void *temp = tss_adapter; // Need this temp to keep G++ from complaining.
  ACE_Thread::getspecific (this->key_, &temp);
  tss_adapter = static_cast <ACE_TSS_Adapter *> (temp);
  guard = static_cast <Write_Guard_Type *> (tss_adapter->ts_obj_);
#else
  void *temp = guard; // Need this temp to keep G++ from complaining.
  ACE_Thread::getspecific (this->key_, &temp);
  guard = static_cast <Write_Guard_Type *> (temp);
#endif /* ACE_HAS_THR_C_DEST */

  return guard->tryacquire_write ();
}

template <class ACE_LOCK> int
ACE_TSS_Write_Guard<ACE_LOCK>::acquire_write (void)
{
  return this->acquire ();
}

template <class ACE_LOCK> int
ACE_TSS_Write_Guard<ACE_LOCK>::tryacquire_write (void)
{
  return this->tryacquire ();
}

template <class ACE_LOCK> void
ACE_TSS_Write_Guard<ACE_LOCK>::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TSS_Guard<ACE_LOCK>::dump ();
#endif /* ACE_HAS_DUMP */
}

template <class ACE_LOCK>
ACE_TSS_Read_Guard<ACE_LOCK>::ACE_TSS_Read_Guard (ACE_LOCK &lock, bool block)
{
  this->init_key ();
  Guard_Type *guard = 0;
  ACE_NEW (guard,
           Read_Guard_Type (lock, block));
#if defined (ACE_HAS_THR_C_DEST)
  ACE_TSS_Adapter *tss_adapter;
  ACE_NEW (tss_adapter,
           ACE_TSS_Adapter ((void *)guard,
                            ACE_TSS_Guard<ACE_LOCK>::cleanup));
  ACE_Thread::setspecific (this->key_,
                           (void *) tss_adapter);
#else
  ACE_Thread::setspecific (this->key_,
                           (void *) guard);
#endif /* ACE_HAS_THR_C_DEST */
}

template <class ACE_LOCK> int
ACE_TSS_Read_Guard<ACE_LOCK>::acquire (void)
{
  Read_Guard_Type *guard = 0;

#if defined (ACE_HAS_THR_C_DEST)
  ACE_TSS_Adapter *tss_adapter = 0;
  void *temp = tss_adapter; // Need this temp to keep G++ from complaining.
  ACE_Thread::getspecific (this->key_, &temp);
  tss_adapter = static_cast <ACE_TSS_Adapter *> (temp);
  guard = static_cast <Read_Guard_Type *> (tss_adapter->ts_obj_);
#else
  void *temp = guard; // Need this temp to keep G++ from complaining.
  ACE_Thread::getspecific (this->key_, &temp);
  guard = static_cast <Read_Guard_Type *> (temp);
#endif /* ACE_HAS_THR_C_DEST */

  return guard->acquire_read ();
}

template <class ACE_LOCK> int
ACE_TSS_Read_Guard<ACE_LOCK>::tryacquire (void)
{
  Read_Guard_Type *guard = 0;

#if defined (ACE_HAS_THR_C_DEST)
  ACE_TSS_Adapter *tss_adapter = 0;
  void *temp = tss_adapter; // Need this temp to keep G++ from complaining.
  ACE_Thread::getspecific (this->key_, &temp);
  tss_adapter = static_cast <ACE_TSS_Adapter *> (temp);
  guard = static_cast <Read_Guard_Type *> (tss_adapter->ts_obj_);
#else
  void *temp = guard; // Need this temp to keep G++ from complaining.
  ACE_Thread::getspecific (this->key_, &temp);
  guard = static_cast <Read_Guard_Type *> (temp);
#endif /* ACE_HAS_THR_C_DEST */

  return guard->tryacquire_read ();
}

template <class ACE_LOCK> int
ACE_TSS_Read_Guard<ACE_LOCK>::acquire_read (void)
{
  return this->acquire ();
}

template <class ACE_LOCK> int
ACE_TSS_Read_Guard<ACE_LOCK>::tryacquire_read (void)
{
  return this->tryacquire ();
}

template <class ACE_LOCK> void
ACE_TSS_Read_Guard<ACE_LOCK>::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TSS_Guard<ACE_LOCK>::dump ();
#endif /* ACE_HAS_DUMP */
}

#endif /* defined (ACE_HAS_THREADS) && (defined (ACE_HAS_THREAD_SPECIFIC_STORAGE) || defined (ACE_HAS_TSS_EMULATION)) */

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_TSS_T_CPP */
