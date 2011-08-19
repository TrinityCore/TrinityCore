/* -*- C++ -*- */

//=============================================================================
/**
 *  @file    LSOCK_Acceptor.h
 *
 *  $Id: LSOCK_Acceptor.h 82723 2008-09-16 09:35:44Z johnnyw $
 *
 *  @author Doug Schmidt
 */
//=============================================================================


#ifndef ACE_LOCAL_SOCK_ACCEPTOR_H
#define ACE_LOCAL_SOCK_ACCEPTOR_H
#include /**/ "ace/pre.h"

#include /**/ "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if !defined (ACE_LACKS_UNIX_DOMAIN_SOCKETS)

#include "ace/SOCK_Acceptor.h"
#include "ace/UNIX_Addr.h"
#include "ace/LSOCK_Stream.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

// Forward decl.
class ACE_Reactor;

/**
 * @class ACE_LSOCK_Acceptor
 *
 * @brief Defines the format and interface for the acceptor side of the
 * local ACE_SOCK ACE_Stream.
 */
class ACE_Export ACE_LSOCK_Acceptor : public ACE_SOCK_Acceptor
{
public:
  // = Initialization methods.
  /// Default constructor.
  ACE_LSOCK_Acceptor (void);

  /// Initiate a passive mode socket.
  ACE_LSOCK_Acceptor (const ACE_Addr &local_sap,
                      int reuse_addr = 0,
                      int protocol_family = PF_UNIX,
                      int backlog = ACE_DEFAULT_BACKLOG,
                      int protocol = 0);

  /// Initiate a passive mode socket.
  int open (const ACE_Addr &local_sap,
            int reuse_addr = 0,
            int protocol_family = PF_UNIX,
            int backlog = ACE_DEFAULT_BACKLOG,
            int protocol = 0);

  /// Accept a new data transfer connection.
  int accept (ACE_LSOCK_Stream &new_ipc_sap,
              ACE_Addr * = 0,
              ACE_Time_Value *timeout = 0,
              bool restart = true,
              bool reset_new_handle = false) const;

  /// Close down the ACE_LSOCK and remove the rendezvous point from the
  /// file system.
  int remove (void);

  /// Return the local endpoint address.
  int get_local_addr (ACE_Addr &) const;

  // = Meta-type info
  typedef ACE_UNIX_Addr PEER_ADDR;
  typedef ACE_LSOCK_Stream PEER_STREAM;

  /// Dump the state of an object.
  void dump (void) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

private:
  /// Address of our rendezvous point.
  ACE_UNIX_Addr local_addr_;
};

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_LACKS_UNIX_DOMAIN_SOCKETS */
#include /**/ "ace/post.h"
#endif /* ACE_LOCAL_SOCK_ACCEPTOR_H */
