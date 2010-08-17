// $Id: Reverse_Lock_T.cpp 80826 2008-03-04 14:51:23Z wotte $

#ifndef ACE_REVERSE_LOCK_T_CPP
#define ACE_REVERSE_LOCK_T_CPP

#include "ace/Reverse_Lock_T.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if !defined (__ACE_INLINE__)
#include "ace/Reverse_Lock_T.inl"
#endif /* __ACE_INLINE__ */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

template <class ACE_LOCKING_MECHANISM>
ACE_Reverse_Lock<ACE_LOCKING_MECHANISM>::~ACE_Reverse_Lock (void)
{
}

// Explicitly destroy the lock.
template <class ACE_LOCKING_MECHANISM> int
ACE_Reverse_Lock<ACE_LOCKING_MECHANISM>::remove (void)
{
  return this->lock_.remove ();
}

// Release the lock.
template <class ACE_LOCKING_MECHANISM> int
ACE_Reverse_Lock<ACE_LOCKING_MECHANISM>::acquire (void)
{
  return this->lock_.release ();
}

// Release the lock.
template <class ACE_LOCKING_MECHANISM> int
ACE_Reverse_Lock<ACE_LOCKING_MECHANISM>::tryacquire (void)
{
  ACE_NOTSUP_RETURN (-1);
}

// Acquire the lock.
template <class ACE_LOCKING_MECHANISM> int
ACE_Reverse_Lock<ACE_LOCKING_MECHANISM>::release (void)
{
  if (this->acquire_method_ == ACE_Acquire_Method::ACE_READ)
    return this->lock_.acquire_read ();
  else if (this->acquire_method_ == ACE_Acquire_Method::ACE_WRITE)
    return this->lock_.acquire_write ();
  else
    return this->lock_.acquire ();
}

// Release the lock.
template <class ACE_LOCKING_MECHANISM> int
ACE_Reverse_Lock<ACE_LOCKING_MECHANISM>::acquire_read (void)
{
  ACE_NOTSUP_RETURN (-1);
}

// Release the lock.
template <class ACE_LOCKING_MECHANISM> int
ACE_Reverse_Lock<ACE_LOCKING_MECHANISM>::acquire_write (void)
{
  ACE_NOTSUP_RETURN (-1);
}

// Release the lock.
template <class ACE_LOCKING_MECHANISM> int
ACE_Reverse_Lock<ACE_LOCKING_MECHANISM>::tryacquire_read (void)
{
  ACE_NOTSUP_RETURN (-1);
}

// Release the lock.
template <class ACE_LOCKING_MECHANISM> int
ACE_Reverse_Lock<ACE_LOCKING_MECHANISM>::tryacquire_write (void)
{
  ACE_NOTSUP_RETURN (-1);
}

// Release the lock.
template <class ACE_LOCKING_MECHANISM> int
ACE_Reverse_Lock<ACE_LOCKING_MECHANISM>::tryacquire_write_upgrade (void)
{
  ACE_NOTSUP_RETURN (-1);
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_REVERSE_LOCK_T_CPP */
