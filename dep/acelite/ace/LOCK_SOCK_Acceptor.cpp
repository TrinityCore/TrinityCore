// $Id: LOCK_SOCK_Acceptor.cpp 82723 2008-09-16 09:35:44Z johnnyw $

#ifndef ACE_LOCK_SOCK_ACCEPTOR_CPP
#define ACE_LOCK_SOCK_ACCEPTOR_CPP

#include "ace/Guard_T.h"
#include "ace/LOCK_SOCK_Acceptor.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

template <class ACE_LOCK> int
ACE_LOCK_SOCK_Acceptor<ACE_LOCK>::accept (ACE_SOCK_Stream &stream,
                                          ACE_Addr *remote_address,
                                          ACE_Time_Value *timeout,
                                          bool restart,
                                          bool reset_new_handle) const
{
  ACE_GUARD_RETURN (ACE_LOCK, ace_mon, (ACE_LOCK &) this->lock_, -1);

  return ACE_SOCK_Acceptor::accept (stream,
                                    remote_address,
                                    timeout,
                                    restart,
                                    reset_new_handle);
}

template <class ACE_LOCK> ACE_LOCK &
ACE_LOCK_SOCK_Acceptor<ACE_LOCK>::lock (void)
{
  return this->lock_;
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_LOCK_SOCK_ACCEPTOR_CPP */
