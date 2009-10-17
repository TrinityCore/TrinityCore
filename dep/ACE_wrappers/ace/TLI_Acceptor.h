// -*- C++ -*-

//=============================================================================
/**
 *  @file    TLI_Acceptor.h
 *
 *  $Id: TLI_Acceptor.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Doug Schmidt
 */
//=============================================================================


#ifndef ACE_TLI_ACCEPTOR_H
#define ACE_TLI_ACCEPTOR_H
#include /**/ "ace/pre.h"

#include "ace/TLI.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/TLI_Stream.h"
#include "ace/Default_Constants.h"

#if defined (ACE_HAS_TLI)

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

// Forward reference...
class ACE_TLI_Request_Queue;
class ACE_Time_Value;

/**
 * @class ACE_TLI_Acceptor
 *
 * @brief Defines the member functions for ACE_TLI_Acceptor abstraction.
 *
 * This class implements the algorithm described in Steve Rago's
 * book on System V UNIX network programming.  It basically
 * makes TLI look like the C++ SOCK_SAP socket wrappers with
 * respect to establishing passive-mode listener endpoints.
 */
class ACE_Export ACE_TLI_Acceptor : public ACE_TLI
{
public:
  friend class ACE_Request_Queue;

  // = Initialization and termination methods.
  /// Default constructor.
  ACE_TLI_Acceptor (void);

  /// Initiate a passive mode socket.
  ACE_TLI_Acceptor (const ACE_Addr &remote_sap,
                    int reuse_addr = 0,
                    int oflag = O_RDWR,
                    struct t_info *info = 0,
                    int backlog = ACE_DEFAULT_BACKLOG,
                    const char device[] = ACE_TLI_TCP_DEVICE);

  /// Initiate a passive mode socket.
  ACE_HANDLE open (const ACE_Addr &remote_sap,
                   int reuse_addr = 0,
                   int oflag = O_RDWR,
                   struct t_info *info = 0,
                   int backlog = ACE_DEFAULT_BACKLOG,
                   const char device[] = ACE_TLI_TCP_DEVICE);

  /// Close down the acceptor and release resources.
  int close (void);

  // = Passive connection acceptance method.

  /**
   * Accept a new data transfer connection.  A @a timeout of 0 means
   * block forever, a @a timeout of {0, 0} means poll.  <restart> == 1
   * means "restart if interrupted."
   */
  int accept (ACE_TLI_Stream &new_tli_sap,
              ACE_Addr *remote_addr = 0,
              ACE_Time_Value *timeout = 0,
              int restart = 1,
              int reset_new_handle = 0,
              int rwflag = 1,
              netbuf *udata = 0,
              netbuf *opt = 0);

  // = Meta-type info
  typedef ACE_INET_Addr PEER_ADDR;
  typedef ACE_TLI_Stream PEER_STREAM;

  /// Dump the state of an object.
  void dump (void) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

private:
  /// Network "device" we are using.
  const char *device_;

  /// Number of connections to queue.
  int backlog_;

  /// Are we using "tirdwr" mod?
  int rwflag_;

  /// Handle TLI accept insanity...
  int handle_async_event (int restart, int rwflag);

  /// Used for queueing up pending requests.
  ACE_TLI_Request_Queue *queue_;

  /// Used for handling disconnects
  struct t_discon *disp_;
};

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_HAS_TLI */
#include /**/ "ace/post.h"
#endif /* ACE_TLI_ACCEPTOR_H */

