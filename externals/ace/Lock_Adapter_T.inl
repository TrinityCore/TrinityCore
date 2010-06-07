// -*- C++ -*-
//
// $Id: Lock_Adapter_T.inl 80826 2008-03-04 14:51:23Z wotte $

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

template <class ACE_LOCKING_MECHANISM>
ACE_INLINE
ACE_Lock_Adapter<ACE_LOCKING_MECHANISM>::ACE_Lock_Adapter (
  ACE_LOCKING_MECHANISM &lock)
  : lock_ (&lock),
    delete_lock_ (false)
{
}

ACE_END_VERSIONED_NAMESPACE_DECL
