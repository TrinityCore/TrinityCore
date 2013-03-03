// -*- C++ -*-

//=============================================================================
/**
 *  @file    LSOCK_CODgram.h
 *
 *  $Id: LSOCK_CODgram.h 84419 2009-02-11 22:28:11Z shuston $
 *
 *  @author Douglas C. Schmidt <schmidt@cs.wustl.edu>
 */
//=============================================================================


#ifndef ACE_LOCAL_SOCK_CODGRAM_H
#define ACE_LOCAL_SOCK_CODGRAM_H
#include /**/ "ace/pre.h"

#include /**/ "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if !defined (ACE_LACKS_UNIX_DOMAIN_SOCKETS)

#include "ace/LSOCK.h"
#include "ace/SOCK_CODgram.h"
#include "ace/Addr.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class ACE_LSOCK_CODgram
 *
 * @brief Defines a fully specified (sometimes called "connected") UNIX-domain
 * datagram abstraction.
 *
 * ACE_LSOCK_CODgram provides a way to use a UNIX-domain datagram socket in
 * a situation where the local and peer addresses are fully known in advance.
 * The "connection-oriented" part of "CODgram" is a misnomer. There is no
 * connection used on this type of socket. It merely specifies that both
 * endpoint addresses are known in advance of use. Furthermore, this class
 * is more suited for use cases where a local endpoint wishes to communicate
 * with a single, known peer and may or may not have a specified local address.
 *
 * If your use case requires receiving datagrams from multiple peers without
 * previously known addresses, consider using ACE_LSOCK_Dgram instead.
 */
class ACE_Export ACE_LSOCK_CODgram : public ACE_SOCK_CODgram, public ACE_LSOCK
{
public:
  /// Default constructor; requires a call to open() prior to communication.
  ACE_LSOCK_CODgram (void);

  /**
   * @name Initialization methods
   */
  //@{
  /**
   * Initialize a fully-specified datagram socket.
   *
   * @param remote_sap  Remote/peer address. This should be an ACE_UNIX_Addr
   *                    object. It specifies where all sent datagrams will
   *                    be sent to.
   * @param local_sap   Local address. The local address to receive datagrams
   *                    at. If not specified, an unused address is selected.
   *                    If specified, should be an ACE_UNIX_Addr object.
   *
   * @sa ACE_UNIX_Addr
   */
  ACE_LSOCK_CODgram (const ACE_Addr &remote_sap,
                     const ACE_Addr &local_sap = ACE_Addr::sap_any,
                     int protocol_family = PF_UNIX,
                     int protocol = 0);

  /**
   * Initialize a fully-specified datagram socket.
   *
   * @retval 0 if no error.
   * @retval -1 on error; check errno for an error reason.
   */
  int open (const ACE_Addr &remote_sap,
            const ACE_Addr &local_sap = ACE_Addr::sap_any,
            int protocol_family = PF_UNIX,
            int protocol = 0);
  //@}

  /// Get underlying handle.
  ACE_HANDLE get_handle (void) const;

  /// Set underlying handle.
  void set_handle (ACE_HANDLE);

  /// Dump the state of an object.
  void dump (void) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;
};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ace/LSOCK_CODgram.inl"
#endif /* __ACE_INLINE__ */

#endif /* ACE_LACKS_UNIX_DOMAIN_SOCKETS */
#include /**/ "ace/post.h"
#endif /* ACE_LOCAL_SOCK_CODGRAM_H */
