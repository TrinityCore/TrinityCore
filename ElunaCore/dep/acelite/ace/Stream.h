// -*- C++ -*-

//==========================================================================
/**
 *  @file    Stream.h
 *
 *  $Id: Stream.h 96070 2012-08-17 09:07:16Z mcorino $
 *
 *  @author Douglas C. Schmidt <schmidt@uci.edu>
 */
//==========================================================================

#ifndef ACE_STREAM_H
#define ACE_STREAM_H

#include /**/ "ace/pre.h"

#include /**/ "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/IO_Cntl_Msg.h"
#include "ace/Message_Block.h"
#include "ace/Module.h"
#if defined (ACE_HAS_THREADS)
# include "ace/Condition_Attributes.h"
#endif

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

// Forward decls.
template<ACE_SYNCH_DECL, class TIME_POLICY> class ACE_Stream_Iterator;
class ACE_Time_Value;

/**
 * @class ACE_Stream
 *
 * @brief This class is the primary abstraction for the ASX framework.
 * It is moduled after System V Stream.
 *
 * A Stream consists of a stack of @c ACE_Modules, each of which
 * contains two @c ACE_Tasks.  Even though the methods in this
 * class are virtual, this class isn't really intended for
 * subclassing unless you know what you are doing.  In
 * particular, the ACE_Stream destructor calls <close>, which
 * won't be overridden properly unless you call it in a subclass
 * destructor.
 */
template <ACE_SYNCH_DECL, class TIME_POLICY = ACE_System_Time_Policy>
class ACE_Stream
{
public:
  friend class ACE_Stream_Iterator<ACE_SYNCH_USE, TIME_POLICY>;

  enum
  {
    /// Indicates that @c close() deletes the Tasks.  Don't change this
    /// value without updating the same enum in class ACE_Module...
    M_DELETE = 3
  };

  // = Initializatation and termination methods.
  /**
   * Create a Stream consisting of @a head and @a tail as the Stream
   * head and Stream tail, respectively.  If these are 0 then the
   * ACE_Stream_Head and ACE_Stream_Tail are used, respectively.
   * @a arg is the value past in to the <open> methods of the tasks.
   */
  ACE_Stream (void *arg = 0,
              ACE_Module<ACE_SYNCH_USE, TIME_POLICY> *head = 0,
              ACE_Module<ACE_SYNCH_USE, TIME_POLICY> *tail = 0);

  /**
   * Create a Stream consisting of @a head and @a tail as the Stream
   * head and Stream tail, respectively.  If these are 0 then the
   * ACE_Stream_Head and ACE_Stream_Tail are used, respectively.
   * @a arg is the value past in to the @c open() methods of the tasks.
   */
  virtual int open (void *arg,
                    ACE_Module<ACE_SYNCH_USE, TIME_POLICY> *head = 0,
                    ACE_Module<ACE_SYNCH_USE, TIME_POLICY> *tail = 0);

  /// Close down the stream and release all the resources.
  virtual int close (int flags = M_DELETE);

  /// Close down the stream and release all the resources.
  virtual ~ACE_Stream (void);

  // = ACE_Stream plumbing operations

  /// Add a new module @a mod right below the Stream head.  The
  /// @c open() hook methods of the @c ACE_Tasks in this ACE_Module
  /// are invoked to initialize the tasks.
  virtual int push (ACE_Module<ACE_SYNCH_USE, TIME_POLICY> *mod);

  /// Remove the @a mod right below the Stream head and close it down.
  //  The <close()> hook methods of the <ACE_Tasks> in this ACE_Module
  /// are invoked to cleanup the tasks.
  virtual int pop (int flags = M_DELETE);

  /// Return the top module on the stream (right below the stream
  /// head).
  virtual int top (ACE_Module<ACE_SYNCH_USE, TIME_POLICY> *&mod);

  /// Insert a new module @a mod below the named module @a prev_name.
  virtual int insert (const ACE_TCHAR *prev_name,
                      ACE_Module<ACE_SYNCH_USE, TIME_POLICY> *mod);

  /// Replace the named module @a replace_name with a new module @a mod.
  virtual int replace (const ACE_TCHAR *replace_name,
                       ACE_Module<ACE_SYNCH_USE, TIME_POLICY> *mod,
                       int flags = M_DELETE);

  /// Remove the named module @a mod from the stream.  This bypasses the
  /// strict LIFO ordering of @c push and @c pop.
  virtual int remove (const ACE_TCHAR *mod,
                      int flags = M_DELETE);

  /// Return current stream head.
  virtual ACE_Module<ACE_SYNCH_USE, TIME_POLICY> *head (void);

  /// Return current stream tail.
  virtual ACE_Module<ACE_SYNCH_USE, TIME_POLICY> *tail (void);

  /// Find a particular ACE_Module.
  virtual ACE_Module<ACE_SYNCH_USE, TIME_POLICY> *find (const ACE_TCHAR *mod);

  /// Create a pipe between two Streams.
  virtual int link (ACE_Stream<ACE_SYNCH_USE, TIME_POLICY> &);

  /// Remove a pipe formed between two Streams.
  virtual int unlink (void);

  // = Blocking data transfer operations
  /**
   * Send the message @a mb down the stream, starting at the Module
   * below the Stream head.  Wait for upto @a timeout amount of
   * absolute time for the operation to complete (or block forever if
   * @a timeout == 0).
   */
  virtual int put (ACE_Message_Block *mb,
                   ACE_Time_Value *timeout = 0);

  /**
   * Read the message @a mb that is stored in the stream head.
   * Wait for upto @a timeout amount of absolute time for the operation
   * to complete (or block forever if @a timeout == 0).
   */
  virtual int get (ACE_Message_Block *&mb,
                   ACE_Time_Value *timeout = 0);

  /// Send control message down the stream.
  virtual int control (ACE_IO_Cntl_Msg::ACE_IO_Cntl_Cmds cmd,
                       void *args);

  /// Synchronize with the final close of the stream.
  virtual int wait (void);

  /// Dump the state of an object.
  virtual void dump (void) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

private:
  /// Actually perform the unlinking of two Streams (must be called
  /// with locks held).
  int unlink_i (void);

  /// Actually perform the linking of two Streams (must be called with
  /// locks held).
  int link_i (ACE_Stream<ACE_SYNCH_USE, TIME_POLICY> &);

  /// Must a new module onto the Stream.
  int push_module (ACE_Module<ACE_SYNCH_USE, TIME_POLICY> *,
                   ACE_Module<ACE_SYNCH_USE, TIME_POLICY> * = 0,
                   ACE_Module<ACE_SYNCH_USE, TIME_POLICY> * = 0);

  /// Pointer to the head of the stream.
  ACE_Module<ACE_SYNCH_USE, TIME_POLICY> *stream_head_;

  /// Pointer to the tail of the stream.
  ACE_Module<ACE_SYNCH_USE, TIME_POLICY> *stream_tail_;

  /// Pointer to an adjoining linked stream.
  ACE_Stream<ACE_SYNCH_USE, TIME_POLICY> *linked_us_;

  // = Synchronization objects used for thread-safe streams.
  /// Protect the stream against race conditions.
  ACE_SYNCH_MUTEX_T lock_;

#if defined (ACE_HAS_THREADS)
  /// Attributes to initialize condition with.
  /* We only need this because some crappy compilers can't
     properly handle initializing the conditions with
     temporary objects. */
  ACE_Condition_Attributes_T<TIME_POLICY> cond_attr_;
#endif

  /// Use to tell all threads waiting on the close that we are done.
  ACE_SYNCH_CONDITION_T final_close_;
};

/**
 * @class ACE_Stream_Iterator
 *
 * @brief Iterate through an ACE_Stream.
 */
template <ACE_SYNCH_DECL, class TIME_POLICY = ACE_System_Time_Policy>
class ACE_Stream_Iterator
{
public:
  // = Initialization method.
  ACE_Stream_Iterator (const ACE_Stream<ACE_SYNCH_USE, TIME_POLICY> &sr);

  // = Iteration methods.

  /// Pass back the @a next_item that hasn't been seen in the set.
  /// Returns 0 when all items have been seen, else 1.
  int next (const ACE_Module<ACE_SYNCH_USE, TIME_POLICY> *&next_item);

  /// Returns 1 when all items have been seen, else 0.
  int done (void) const;

  /// Move forward by one element in the set.  Returns 0 when all the
  /// items in the set have been seen, else 1.
  int advance (void);

private:
  /// Next ACE_Module that we haven't yet seen.
  ACE_Module<ACE_SYNCH_USE, TIME_POLICY> *next_;
};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ace/Stream.inl"
#endif /* __ACE_INLINE__ */

#if defined (ACE_TEMPLATES_REQUIRE_SOURCE)
#include "ace/Stream.cpp"
#endif /* ACE_TEMPLATES_REQUIRE_SOURCE */

#if defined (ACE_TEMPLATES_REQUIRE_PRAGMA)
#pragma implementation ("Stream.cpp")
#endif /* ACE_TEMPLATES_REQUIRE_PRAGMA */

#include /**/ "ace/post.h"

#endif /* ACE_STREAM_H */
