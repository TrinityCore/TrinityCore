// -*- C++ -*-

//=============================================================================
/**
 *  @file   Svc_Handler.h
 *
 *  $Id: Svc_Handler.h 81740 2008-05-20 17:56:02Z elliott_c $
 *
 *  @author Douglas Schmidt <schmidt@uci.edu>
 *  @author Irfan Pyarali <irfan@cs.wustl.edu>
 */
//=============================================================================

#ifndef ACE_SVC_HANDLER_H
#define ACE_SVC_HANDLER_H

#include /**/ "ace/pre.h"

#include "ace/Synch_Options.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/Task.h"
#include "ace/Recyclable.h"
#include "ace/Reactor.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

// Forward decls.
class ACE_Connection_Recycling_Strategy;

// This enum is used as the flags parameter when calling the close()
// method on the ACE_Svc_Handler.
enum ACE_Svc_Handler_Close { NORMAL_CLOSE_OPERATION = 0x00,
                             CLOSE_DURING_NEW_CONNECTION = 0x01
                           };

/**
 * @class ACE_Svc_Handler
 *
 * @brief Defines the interface for a service that exchanges data with
 * its connected peer.
 *
 * This class provides a well-defined interface that the
 * Acceptor and Connector pattern factories use as their target.
 * Typically, client applications will subclass ACE_Svc_Handler
 * and do all the interesting work in the subclass.  One thing
 * that the ACE_Svc_Handler does contain is a PEER_STREAM
 * endpoint that is initialized by an ACE_Acceptor or
 * ACE_Connector when a connection is established successfully.
 * This endpoint is used to exchange data between a
 * ACE_Svc_Handler and the peer it is connected with.
 */
template <ACE_PEER_STREAM_1, ACE_SYNCH_DECL>
class ACE_Svc_Handler : public ACE_Task<ACE_SYNCH_USE>
{
public:

  // Useful STL-style traits.
  typedef ACE_PEER_STREAM_ADDR addr_type;
  typedef ACE_PEER_STREAM      stream_type;

  /**
   * Constructor initializes the @a thr_mgr and @a mq by passing them
   * down to the ACE_Task base class.  The @a reactor is passed to
   * the ACE_Event_Handler.
   */
  ACE_Svc_Handler (ACE_Thread_Manager *thr_mgr = 0,
                   ACE_Message_Queue<ACE_SYNCH_USE> *mq = 0,
                   ACE_Reactor *reactor = ACE_Reactor::instance ());

  /// Destructor.
  virtual ~ACE_Svc_Handler (void);

  /// Activate the client handler.  This is typically called by the
  /// ACE_Acceptor or ACE_Connector.
  virtual int open (void * = 0);

  /**
   * Object termination hook -- application-specific cleanup code goes
   * here. This function is called by the idle() function if the object
   * does not have a ACE_Connection_Recycling_Strategy associated with it.
   * Also, due to this class's derivation from ACE_Task, close() is
   * also called when a thread activated with this object exits. See
   * ACE_Task::close() for further details. The default action of this
   * function is to call handle_close() with the default arguments.
   */
  virtual int close (u_long flags = 0);

  /**
   * Call this method if you want to recycling the @c Svc_Handler
   * instead of closing it. If the object does not have a recycler,
   * it will be closed.
   */
  virtual int idle (u_long flags = 0);

  /**
   * Call this method if you want to get/set the state of the
   * @c Svc_Handler.  If the object does not have a recycler, this call
   * will have no effect (and the accessor will return
   * ACE_RECYCLABLE_UNKNOWN).
   */
  virtual ACE_Recyclable_State recycle_state (void) const;
  virtual int recycle_state (ACE_Recyclable_State new_state);

  /**
   * When the svc_handle is no longer needed around as a hint, call
   * this method. In addition, reset @c *act_holder to zero if
   * @a act_holder != 0.
   */
  virtual void cleanup_hint (void **act_holder = 0);

  // = Dynamic linking hooks.
  /// Default version does no work and returns -1.  Must be overloaded
  /// by application developer to do anything meaningful.
  virtual int init (int argc, ACE_TCHAR *argv[]);

  /// Default version does no work and returns -1.  Must be overloaded
  /// by application developer to do anything meaningful.
  virtual int fini (void);

  /// Default version does no work and returns -1.  Must be overloaded
  /// by application developer to do anything meaningful.
  virtual int info (ACE_TCHAR **info_string, size_t length) const;

  // = Demultiplexing hooks.

  /**
   * Perform termination activities on the SVC_HANDLER.  The default
   * behavior is to close down the <peer_> (to avoid descriptor leaks)
   * and to <destroy> this object (to avoid memory leaks)!  If you
   * don't want this behavior make sure you override this method...
   */
  virtual int handle_close (ACE_HANDLE = ACE_INVALID_HANDLE,
                            ACE_Reactor_Mask = ACE_Event_Handler::ALL_EVENTS_MASK);

  /// Default behavior when timeouts occur is to close down the
  /// <Svc_Handler> by calling <handle_close>.
  virtual int handle_timeout (const ACE_Time_Value &time,
                              const void *);

  /// Get the underlying handle associated with the <peer_>.
  virtual ACE_HANDLE get_handle (void) const;

  /// Set the underlying handle associated with the <peer_>.
  virtual void set_handle (ACE_HANDLE);

  /// Returns the underlying PEER_STREAM.  Used by
  /// <ACE_Acceptor::accept> and <ACE_Connector::connect> factories
  ACE_PEER_STREAM &peer (void) const;

  /// Overloaded new operator.  This method unobtrusively records if a
  /// <Svc_Handler> is allocated dynamically, which allows it to clean
  /// itself up correctly whether or not it's allocated statically or
  /// dynamically.
  void *operator new (size_t n);

#if defined (ACE_HAS_NEW_NOTHROW)
  /// Overloaded new operator, nothrow_t variant. Unobtrusively records if a
  /// <Svc_Handler> is allocated dynamically, which allows it to clean
  /// itself up correctly whether or not it's allocated statically or
  /// dynamically.
  void *operator new (size_t n, const ACE_nothrow_t&) throw();
#if !defined (ACE_LACKS_PLACEMENT_OPERATOR_DELETE)
  void operator delete (void *p, const ACE_nothrow_t&) throw ();
#endif /* ACE_LACKS_PLACEMENT_OPERATOR_DELETE */
#endif

  /// This operator permits "placement new" on a per-object basis.
  void * operator new (size_t n, void *p);

  /**
   * Call this to free up dynamically allocated <Svc_Handlers>
   * (otherwise you will get memory leaks).  In general, you should
   * call this method rather than <delete> since this method knows
   * whether or not the object was allocated dynamically, and can act
   * accordingly (i.e., deleting it if it was allocated dynamically).
   */
  virtual void destroy (void);

  /**
   * This really should be private so that users are forced to call
   * <destroy>.  Unfortunately, the C++ standard doesn't allow there
   * to be a public new and a private delete.  It is a bad idea to
   * call this method directly, so use <destroy> instead, unless you
   * know for sure that you've allocated the object dynamically.
   */
  void operator delete (void *);

#if !defined (ACE_LACKS_PLACEMENT_OPERATOR_DELETE)
  /**
   * This operator is necessary to complement the class-specific
   * operator new above.  Unfortunately, it's not portable to all C++
   * compilers...
   */
  void operator delete (void *, void *);
#endif /* ACE_LACKS_PLACEMENT_OPERATOR_DELETE */

  /// Close down the descriptor and unregister from the Reactor
  void shutdown (void);

  /// Dump the state of an object.
  void dump (void) const;

public:

  // = The following methods are not suppose to be public.

  // Because friendship is *not* inherited in C++, these methods have
  // to be public.

  // = Accessors to set/get the connection recycler.

  /// Set the recycler and the @a recycling_act that is used during
  /// purging and caching.
  virtual void recycler (ACE_Connection_Recycling_Strategy *recycler,
                         const void *recycling_act);

  /// Get the recycler.
  virtual ACE_Connection_Recycling_Strategy *recycler (void) const;

  /// Get the recycling act.
  virtual const void *recycling_act (void) const;

  /**
   * Upcall made by the recycler when it is about to recycle the
   * connection.  This gives the object a chance to prepare itself for
   * recycling.  Return 0 if the object is ready for recycling, -1 on
   * failures.
   */
  virtual int recycle (void * = 0);

protected:
  /// Maintain connection with client.
  ACE_PEER_STREAM peer_;

  /// Have we been dynamically created?
  bool dynamic_;

  /// Keeps track of whether we are in the process of closing (required
  /// to avoid circular calls to <handle_close>).
  bool closing_;

  /// Pointer to the connection recycler.
  ACE_Connection_Recycling_Strategy *recycler_;

  /// Asynchronous Completion Token (ACT) to be used to when talking to
  /// the recycler.
  const void *recycling_act_;
};

/**
 * @class ACE_Buffered_Svc_Handler
 *
 * @brief Defines the interface for a service that exchanges data with
 * its connected peer and supports buffering.
 *
 * The buffering feature makes it possible to queue up
 * ACE_Message_Blocks in an ACE_Message_Queue until (1) the
 * queue is "full" or (2) a period of time elapses, at which
 * point the queue is "flushed" via <sendv_n> to the peer.
 */
template <ACE_PEER_STREAM_1, ACE_SYNCH_DECL>
class ACE_Buffered_Svc_Handler : public ACE_Svc_Handler<ACE_PEER_STREAM_2, ACE_SYNCH_USE>
{
public:
  // = Initialization and termination methods.
  /**
   * Constructor initializes the @a thr_mgr and @a mq by passing them
   * down to the ACE_Task base class.  The @a reactor is passed to
   * the ACE_Event_Handler.  The @a max_buffer_size and
   * @a relative_timeout are used to determine at what point to flush
   * the @a mq.  By default, there's no buffering at all.  The
   * @a relative_timeout value is interpreted to be in a unit that's
   * relative to the current time returned by <ACE_OS::gettimeofday>.
   */
  ACE_Buffered_Svc_Handler (ACE_Thread_Manager *thr_mgr = 0,
                            ACE_Message_Queue<ACE_SYNCH_USE> *mq = 0,
                            ACE_Reactor *reactor = ACE_Reactor::instance (),
                            size_t max_buffer_size = 0,
                            ACE_Time_Value *relative_timeout = 0);

  /// Destructor, which calls <flush>.
  virtual ~ACE_Buffered_Svc_Handler (void);

  /**
   * Insert the ACE_Message_Block chain rooted at @a message_block
   * into the ACE_Message_Queue with the designated @a timeout.  The
   * <flush> method will be called if this <put> causes the number of
   * bytes to exceed the maximum buffer size or if the timeout period
   * has elapsed.
   */
  virtual int put (ACE_Message_Block *message_block,
                   ACE_Time_Value *timeout = 0);

  /// Flush the ACE_Message_Queue, which writes all the queued
  /// ACE_Message_Blocks to the <PEER_STREAM>.
  virtual int flush (void);

  /// This method is not currently implemented -- this is where the
  /// integration with the <Reactor> would occur.
  virtual int handle_timeout (const ACE_Time_Value &time,
                              const void *);

  /// Dump the state of an object.
  void dump (void) const;

protected:
  /// Implement the flush operation on the ACE_Message_Queue, which
  /// writes all the queued ACE_Message_Blocks to the <PEER_STREAM>.
  /// Assumes that the caller holds the lock.
  virtual int flush_i (void);

  /// Maximum size the <Message_Queue> can be before we have to flush
  /// the buffer.
  size_t maximum_buffer_size_;

  /// Current size in bytes of the <Message_Queue> contents.
  size_t current_buffer_size_;

  /// Timeout value used to control when the buffer is flushed.
  ACE_Time_Value next_timeout_;

  /// Interval of the timeout.
  ACE_Time_Value interval_;

  /// Timeout pointer.
  ACE_Time_Value *timeoutp_;
};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (ACE_TEMPLATES_REQUIRE_SOURCE)
#include "ace/Svc_Handler.cpp"
#endif /* ACE_TEMPLATES_REQUIRE_SOURCE */

#if defined (ACE_TEMPLATES_REQUIRE_PRAGMA)
#pragma implementation ("Svc_Handler.cpp")
#endif /* ACE_TEMPLATES_REQUIRE_PRAGMA */

#include /**/ "ace/post.h"

#endif /* ACE_SVC_HANDLER_H */

