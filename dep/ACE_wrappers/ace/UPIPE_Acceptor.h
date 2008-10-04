// -*- C++ -*-

//=============================================================================
/**
 *  @file    UPIPE_Acceptor.h
 *
 *  $Id: UPIPE_Acceptor.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Gerhard Lenzer
 *  @author Douglas C. Schmidt
 */
//=============================================================================


#ifndef ACE_UPIPE_ACCEPTOR_H
#define ACE_UPIPE_ACCEPTOR_H
#include /**/ "ace/pre.h"

#include "ace/UPIPE_Stream.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if defined (ACE_HAS_THREADS)

#include "ace/SPIPE_Acceptor.h"
#include "ace/Thread_Manager.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class ACE_UPIPE_Acceptor
 *
 * @brief Defines the format and interface for the listener side of the
 * ACE_UPIPE_Stream.
 */
class ACE_Export ACE_UPIPE_Acceptor : public ACE_SPIPE_Acceptor
{
public:
  // = Initialization and termination.
  /// Default constructor.
  ACE_UPIPE_Acceptor (void);

  /// Initialize passive endpoint.
  ACE_UPIPE_Acceptor (const ACE_UPIPE_Addr &local_sap,
                      int reuse_addr = 0);

  /// Initialize passive endpoint.
  int open (const ACE_UPIPE_Addr &local_sap,
            int reuse_addr = 0);

  /// Close down and release resources.
  ~ACE_UPIPE_Acceptor (void);

  /// Close down and release resources.
  int close (void);

  /// Close down and release resources and remove the underlying SPIPE
  /// rendezvous point.
  int remove (void);

  // = Passive connection acceptance method.
  /**
   * Accept a new data transfer connection.  A @a timeout of 0 means
   * block forever, a @a timeout of {0, 0} means poll.  @a restart == 1
   * means "restart if interrupted."
   */
  int accept (ACE_UPIPE_Stream &server_stream,
              ACE_UPIPE_Addr *remote_addr = 0,
              ACE_Time_Value *timeout = 0,
              int restart = 1,
              int reset_new_handle = 0);

  /// Dump the state of an object.
  void dump (void) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

private:
  /// Manage threads.
  ACE_Thread_Manager tm;

  /// To confirm connection establishment.
  ACE_Message_Block mb_;
};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ace/UPIPE_Acceptor.inl"
#endif /* __ACE_INLINE__ */

#endif /* ACE_HAS_THREADS */

#include /**/ "ace/post.h"

#endif /* ACE_UPIPE_ACCEPTOR_H */
