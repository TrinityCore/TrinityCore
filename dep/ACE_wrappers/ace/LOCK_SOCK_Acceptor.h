// -*- C++ -*-

//=============================================================================
/**
 *  @file    LOCK_SOCK_Acceptor.h
 *
 *  $Id: LOCK_SOCK_Acceptor.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author James Hu and Irfan Pyarali
 */
//=============================================================================


#ifndef ACE_LOCK_SOCK_ACCEPTOR_H
#define ACE_LOCK_SOCK_ACCEPTOR_H
#include /**/ "ace/pre.h"

#include "ace/SOCK_Acceptor.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class ACE_LOCK_SOCK_Acceptor
 *
 * @brief Specialize ACE_SOCK_Acceptor to lock around <accept>;
 *
 * This class is necessary since some OS platforms (e.g.,
 * Solaris 2.5) do not allow multiple threads/processes to
 * simultaneously call <accept> on the same listen-mode
 * port/socket.  Thus, we need to protect against multiple
 * concurrent accesses by using the appropriate type of lock.
 */
template <class ACE_LOCK>
class ACE_LOCK_SOCK_Acceptor : public ACE_SOCK_Acceptor
{
public:
  /// Accept the connection under the control of the <ACE_LOCK>.
  int accept (ACE_SOCK_Stream &new_stream,
              ACE_Addr *remote_addr = 0,
              ACE_Time_Value *timeout = 0,
              int restart = 1,
              int reset_new_handle = 0) const;

  /// Return a reference to the lock.
  ACE_LOCK &lock (void);

protected:
  /// Type of locking mechanism.
  ACE_LOCK lock_;
};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (ACE_TEMPLATES_REQUIRE_SOURCE)
#include "ace/LOCK_SOCK_Acceptor.cpp"
#endif /* ACE_TEMPLATES_REQUIRE_SOURCE */

#if defined (ACE_TEMPLATES_REQUIRE_PRAGMA)
#pragma implementation ("LOCK_SOCK_Acceptor.cpp")
#endif /* ACE_TEMPLATES_REQUIRE_PRAGMA */

#include /**/ "ace/post.h"
#endif /* ACE_LOCK_SOCK_ACCEPTOR_H */
