// -*- C++ -*-

//=============================================================================
/**
 *  @file    ATM_Acceptor.h
 *
 *  $Id: ATM_Acceptor.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Joe Hoffert
 */
//=============================================================================


#ifndef ACE_ATM_ACCEPTOR_H
#define ACE_ATM_ACCEPTOR_H
#include /**/ "ace/pre.h"

#include /**/ "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if defined (ACE_HAS_ATM)

#include "ace/ATM_Stream.h"
#include "ace/ATM_Params.h"
#include "ace/ATM_QoS.h"

#if defined (ACE_HAS_LINUX_ATM)
#include /**/ "atm.h"
#endif /* ACE_HAS_LINUX_ATM */

#if defined (ACE_HAS_FORE_ATM_WS2) || defined (ACE_HAS_LINUX_ATM)
#include "ace/SOCK_Acceptor.h"
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
typedef ACE_SOCK_Acceptor ATM_Acceptor;
ACE_END_VERSIONED_NAMESPACE_DECL
#elif defined (ACE_HAS_FORE_ATM_XTI)
#include "ace/TLI_Acceptor.h"
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
typedef ACE_TLI_Acceptor ATM_Acceptor;
ACE_END_VERSIONED_NAMESPACE_DECL
#endif // ACE_HAS_FORE_ATM_WS2 || ACE_HAS_LINUX_ATM

// Open versioned namespace, if enabled by the user.
ACE_BEGIN_VERSIONED_NAMESPACE_DECL

// Forward declarations.
class ACE_Time_Value;

/**
 * @class ACE_ATM_Acceptor
 *
 * @brief Defines the member functions for ACE_ATM_Acceptor abstraction.
 *
 * This class wraps up the ACE_SOCK_Acceptor and ACE_TLI_Acceptor
 * to make the mechanism for the ATM protocol transparent.
 */
class ACE_Export ACE_ATM_Acceptor
{

public:
  // = Initialization and termination methods.
  /// Default constructor.
  ACE_ATM_Acceptor (void);

  ~ACE_ATM_Acceptor ();

  /// Initiate a passive mode connection.
  ACE_ATM_Acceptor (const ACE_Addr &remote_sap,
                    int backlog = ACE_DEFAULT_BACKLOG,
                    ACE_ATM_Params params = ACE_ATM_Params());

  /// Initiate a passive mode socket.
  ACE_HANDLE open (const ACE_Addr &remote_sap,
                   int backlog = ACE_DEFAULT_BACKLOG,
                   ACE_ATM_Params params = ACE_ATM_Params());

  /// Close down the acceptor and release resources.
  int close (void);

  // = Passive connection acceptance method.

  /// Accept a new data transfer connection.  A @a timeout of 0 means
  /// block forever, a @a timeout of {0, 0} means poll. @a restart == 1
  /// means "restart if interrupted."
  int accept (ACE_ATM_Stream &new_sap,
              ACE_Addr *remote_addr = 0,
              ACE_Time_Value *timeout = 0,
              int restart = 1,
              int reset_new_handle = 0,
              ACE_ATM_Params params = ACE_ATM_Params(),
              ACE_ATM_QoS qos = ACE_ATM_QoS());

  /// Get the local address currently listening on
  int get_local_addr( ACE_ATM_Addr &local_addr );

  // = Meta-type info
  typedef ACE_ATM_Addr PEER_ADDR;
  typedef ACE_ATM_Stream PEER_STREAM;

  /// Dump the state of an object.
  void dump (void) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

private:
  ATM_Acceptor acceptor_;
};

// Close versioned namespace, if enabled by the user.
ACE_END_VERSIONED_NAMESPACE_DECL


#if defined (__ACE_INLINE__)
#include "ace/ATM_Acceptor.inl"
#endif /* __ACE_INLINE__ */

#endif /* ACE_HAS_ATM */
#include /**/ "ace/post.h"
#endif /* ACE_ATM_ACCEPTOR_H */
