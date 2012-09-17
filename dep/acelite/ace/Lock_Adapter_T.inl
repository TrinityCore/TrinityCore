// -*- C++ -*-
//
// $Id: Lock_Adapter_T.inl 93385 2011-02-14 20:21:20Z mitza $

#include "ace/OS_Memory.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

template <class ACE_LOCKING_MECHANISM>
ACE_INLINE
ACE_Lock_Adapter<ACE_LOCKING_MECHANISM>::ACE_Lock_Adapter (
  ACE_LOCKING_MECHANISM &lock)
  : lock_ (&lock),
    delete_lock_ (false)
{
}

template <class ACE_LOCKING_MECHANISM>
ACE_INLINE
ACE_Lock_Adapter<ACE_LOCKING_MECHANISM>::ACE_Lock_Adapter (void)
  : lock_ (0),
    delete_lock_ (true)
{
  ACE_NEW (this->lock_,
           ACE_LOCKING_MECHANISM);
}

ACE_END_VERSIONED_NAMESPACE_DECL
