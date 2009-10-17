// -*- C++ -*-

//=============================================================================
/**
 *  @file    UPIPE_Stream.h
 *
 *  $Id: UPIPE_Stream.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Gerhard Lenzer
 *  @author Douglas C. Schmidt
 */
//=============================================================================


#ifndef ACE_UPIPE_STREAM_H
#define ACE_UPIPE_STREAM_H
#include /**/ "ace/pre.h"

#include "ace/Stream.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if defined (ACE_HAS_THREADS)

#include "ace/SPIPE.h"
#include "ace/Message_Queue.h"
#include "ace/UPIPE_Addr.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class ACE_UPIPE_Stream
 *
 * @brief Defines the method that transfer data on a UPIPE.
 */
class ACE_Export ACE_UPIPE_Stream : public ACE_SPIPE
{
public:
  friend class ACE_UPIPE_Acceptor;
  friend class ACE_UPIPE_Connector;

  typedef ACE_Stream<ACE_SYNCH> MT_Stream;

  // = Initialization and Termination.

  ACE_UPIPE_Stream (void);

  virtual ~ACE_UPIPE_Stream (void);

  /// Shut down the UPIPE and release resources.
  int close (void);

  /// Return the underlying I/O handle.
  ACE_HANDLE get_handle (void) const;

  // = Send/recv ACE Message_Blocks.
  /// Send a message through the message queue.  Returns -1 on error,
  /// else 0.
  int send (ACE_Message_Block *mb_p,
            ACE_Time_Value *timeout  = 0);

  /// Recv a message from the message queue.  Returns -1 on error, else
  /// 0.
  int recv (ACE_Message_Block *&mb_p,
            ACE_Time_Value *timeout  = 0);

  // = Send/recv char buffers.
  /// Send a buffer of @a n bytes through the message queue.  Returns -1
  /// on error, else number of bytes sent.
  ssize_t send (const char *buffer,
                size_t n,
                ACE_Time_Value *timeout = 0);

  /// Recv a buffer of upto @a n bytes from the message queue.  Returns
  /// -1 on error, else number of bytes read.
  ssize_t recv (char *buffer,
                size_t n,
                ACE_Time_Value *timeout = 0);

  /// Send a buffer of exactly @a n bytes to the message queue.  Returns
  /// -1 on error, else number of bytes written (which should == n).
  ssize_t send_n (const char *buffer,
                  size_t n,
                  ACE_Time_Value *timeout = 0);

  /// Recv a buffer of exactly @a n bytes from the message queue.
  /// Returns -1 on error, else the number of bytes read.
  ssize_t recv_n (char *buffer,
                  size_t n,
                  ACE_Time_Value *timeout = 0);

  /// Perform control operations on the UPIPE_Stream.
  int control (int cmd, void *val) const;

  /// Return the remote address we are connected to.
  int get_remote_addr (ACE_UPIPE_Addr &remote_sap) const;

  /// Dump the state of an object.
  void dump (void) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

  // = Meta-type info
  typedef ACE_UPIPE_Addr PEER_ADDR;

private:
  /// To hold the last ACE_Message_Block read out of the stream. Thus
  /// allowing subsequent reads from one ACE_Message_Block
  ACE_Message_Block *mb_last_;

  /// Address of who we are connected to.
  ACE_UPIPE_Addr remote_addr_;

  /// Stream component used by the @c UPIPE_Acceptor and
  /// @c UPIPE_Connector to link together two UPIPE_Streams.
  MT_Stream stream_;

  /// Keep track of whether the sender and receiver have both shutdown.
  int reference_count_;

#if defined (ACE_MT_SAFE) && (ACE_MT_SAFE != 0)
  /// Ensure that we are thread-safe.
  ACE_Thread_Mutex lock_;
#endif /* ACE_MT_SAFE */
};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ace/UPIPE_Stream.inl"
#endif /* __ACE_INLINE__ */

#endif /* ACE_HAS_THREADS */

#include /**/ "ace/post.h"

#endif /*ACE_UPIPE_STREAM_H */

