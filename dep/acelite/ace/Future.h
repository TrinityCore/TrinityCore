// -*- C++ -*-

//=============================================================================
/**
 *  @file    Future.h
 *
 *  $Id: Future.h 91626 2010-09-07 10:59:20Z johnnyw $
 *
 *  @author Andres Kruse <Andres.Kruse@cern.ch>
 *  @author Douglas C. Schmidt <schmidt@cs.wustl.edu>
 *  @author Per Andersson <Per.Andersson@hfera.ericsson.se> and
 *  @author John Tucker <johnny_tucker@yahoo.com>
 */
//=============================================================================

#ifndef ACE_FUTURE_H
#define ACE_FUTURE_H

#include /**/ "ace/pre.h"

#include "ace/Unbounded_Set.h"
#include "ace/Strategies_T.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if defined (ACE_HAS_THREADS)

#include "ace/Synch_Traits.h"
#include "ace/Recursive_Thread_Mutex.h"
#include "ace/Condition_Recursive_Thread_Mutex.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

// Forward decl.
template <class T> class ACE_Future_Holder;
template <class T> class ACE_Future_Observer;
template <class T> class ACE_Future_Rep;
template <class T> class ACE_Future;

/**
 * @class ACE_Future_Holder
 *
 * @brief Implementation of object that holds an ACE_Future.
 */
template <class T>
class ACE_Future_Holder
{
public:
  ACE_Future_Holder (const ACE_Future<T> &future);
  ~ACE_Future_Holder (void);

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

  ACE_Future<T> item_;

protected:
  ACE_Future_Holder (void);
};

/**
 * @class ACE_Future_Observer
 *
 * @brief ACE_Future_Observer<T>
 *
 * An ACE_Future_Observer object implements an object that is
 * subscribed with an ACE_Future object so that it may be notified
 * when the value of the ACE_Future object is written to by a writer
 * thread.  It uses the Observer pattern.
 */
template <class T>
class ACE_Future_Observer
{
public:
  /// Destructor
  virtual ~ACE_Future_Observer (void);

  /// Called by the ACE_Future in which we are subscribed to when
  /// its value is written to.
  virtual void update (const ACE_Future<T> &future) = 0;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;
protected:

  /// Constructor
  ACE_Future_Observer (void);
};

/**
 * @class ACE_Future_Rep
 *
 * @internal
 *
 * @brief ACE_Future_Rep<T>
 *
 * An ACE_Future_Rep<T> object encapsules a pointer to an object
 * of class T which is the result of an asynchronous method
 * invocation. It is pointed to by ACE_Future<T> object[s] and
 * only accessible through them.
 */
template <class T>
class ACE_Future_Rep
{
private:
  friend class ACE_Future<T>;

  /**
   * Set the result value.  The specified @a caller represents the
   * future that invoked this <set> method, which is used to notify
   * the list of future observers. Returns 0 for success, -1 on error.
   * This function only has an effect the first time it is called for
   * the object. Subsequent calls return 0 (success) but have no effect.
   */
  int set (const T &r,
           ACE_Future<T> &caller);

  /// Wait up to @a tv time to get the @a value.  Note that @a tv must be
  /// specified in absolute time rather than relative time.
  int get (T &value,
           ACE_Time_Value *tv) const;

  /**
   * Attaches the specified observer to a subject (i.e., the ACE_Future_Rep).
   * The update method of the specified subject will be invoked with a copy of
   * the written-to ACE_Future as input when the result gets set.
   *
   * Returns 0 if the observer is successfully attached, 1 if the
   * observer is already attached, and -1 if failures occur.
   */
  int attach (ACE_Future_Observer<T> *observer,
               ACE_Future<T> &caller);

  /**
   * Detaches the specified observer from a subject (i.e., the ACE_Future_Rep).
   * The update method of the specified subject will not be invoked when the
   * ACE_Future_Reps result gets set.  Returns 1 if the specified observer was
   * actually attached to the subject prior to this call and 0 if was not.
   *
   * Returns 0 if the observer was successfully detached, and -1 if the
   * observer was not attached in the first place.
   */
  int detach (ACE_Future_Observer<T> *observer);

  /**
   * Type conversion. will block forever until the result is
   * available.  Note that this method is going away in a subsequent
   * release since it doesn't distinguish between failure results and
   * success results (exceptions should be used, but they aren't
   * portable...).  The <get> method should be used instead since it
   * separates the error value from the result, and also permits
   * timeouts.
   */
  operator T ();

  /// Dump the state of an object.
  void dump (void) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

  // = Encapsulate reference count and object lifetime of instances.

  // These methods must go after the others to work around a bug with
  // Borland's C++ Builder...

  /// Allocate a new ACE_Future_Rep<T> instance, returning NULL if it
  /// cannot be created.
  static ACE_Future_Rep<T> *internal_create (void);

  /// Create a ACE_Future_Rep<T> and initialize the reference count.
  static ACE_Future_Rep<T> *create (void);

  /**
   * Increase the reference count and return argument. Uses the
   * attribute "value_ready_mutex_" to synchronize reference count
   * updating.
   *
   * Precondition (rep != 0).
   */
  static ACE_Future_Rep<T> *attach (ACE_Future_Rep<T> *&rep);

  /**
   * Decreases the reference count and deletes rep if there are no
   * more references to rep.
   *
   * Precondition (rep != 0)
   */
  static void detach (ACE_Future_Rep<T> *&rep);

  /**
   * Decreases the rep's reference count and deletes rep if there
   * are no more references to rep. Then assigns new_rep to rep.
   *
   * Precondition (rep != 0 && new_rep != 0)
   */
  static void assign (ACE_Future_Rep<T> *&rep, ACE_Future_Rep<T> *new_rep);

  /// Is result available?
  int ready (void) const;

  /// Pointer to the result.
  T *value_;

  /// Reference count.
  int ref_count_;

  typedef ACE_Future_Observer<T> OBSERVER;

  typedef ACE_Unbounded_Set<OBSERVER *> OBSERVER_COLLECTION;

  /// Keep a list of ACE_Future_Observers unread by client's reader thread.
  OBSERVER_COLLECTION observer_collection_;

  // = Condition variable and mutex that protect the <value_>.
  mutable ACE_SYNCH_RECURSIVE_MUTEX value_ready_mutex_;
  mutable ACE_SYNCH_RECURSIVE_CONDITION value_ready_;

private:

  ACE_Future_Rep (void);

protected:

  ~ACE_Future_Rep (void);

};

/**
 * @class ACE_Future
 *
 * @brief This class implements a ``single write, multiple read''
 * pattern that can be used to return results from asynchronous
 * method invocations.
 */
template <class T>
class ACE_Future
{
public:
  // = Initialization and termination methods.
  /// Constructor.
  ACE_Future (void);

  /// Copy constructor binds @a this and @a r to the same
  /// ACE_Future_Rep. An ACE_Future_Rep is created if necessary.
  ACE_Future (const ACE_Future<T> &r);

  /// Constructor that initialises an ACE_Future to point to the
  /// result @a r immediately.
  ACE_Future (const T &r);

  /// Destructor.
  ~ACE_Future (void);

  /// Assignment operator that binds @a this and @a r to the same
  /// ACE_Future_Rep. An ACE_Future_Rep is created if necessary.
  void operator = (const ACE_Future<T> &r);

  /// Cancel an ACE_Future and assign the value @a r.  It is used if a
  /// client does not want to wait for the value to be produced.
  int cancel (const T &r);

  /**
   * Cancel an ACE_Future.  Put the future into its initial
   * state. Returns 0 on succes and -1 on failure. It is now possible
   * to reuse the ACE_Future. But remember, the ACE_Future
   * is now bound to a new ACE_Future_Rep.
   */
  int cancel (void);

  /**
   * Equality operator that returns @c true if both ACE_Future objects
   * point to the same ACE_Future_Rep object.
   *
   * @note It also returns @c true if both objects have just been
   *       instantiated and not used yet.
   */
  bool operator == (const ACE_Future<T> &r) const;

  /// Inequality operator, which is the opposite of equality.
  bool operator != (const ACE_Future<T> &r) const;

  /**
   * Make the result available. Is used by the server thread to give
   * the result to all waiting clients. Returns 0 for success, -1 on failure.
   * This function only has an effect the first time it is called for
   * the object (actually, the first time the underlying ACE_Future_Rep has a
   * value assigned to it). Subsequent calls return 0 (success) but have no
   * effect.
   */
  int set (const T &r);

  /**
   * Wait to get the object's value.
   *
   * @param value Receives the value of this ACE_Future when it is set.
   * @param tv    Pointer to an ACE_Time_Value containing the absolute
   *              time to wait until for the value to be set. If @a tv
   *              is 0, the call waits indefinitely for the value to be
   *              set, unless an error occurs.
   *
   * @retval  0   Success; @a value contains the value of the ACE_Future.
   * @retval -1   Error; check ACE_OS::last_error() for an error code.
   */
  int get (T &value, ACE_Time_Value *tv = 0) const;

  /**
   * @deprecated  Note that this method is going away in a subsequent
   *              release since it doesn't distinguish between failure
   *              results and success results (exceptions should be
   *              used, but they aren't portable...).
   * Type conversion, which obtains the result of the asynchronous
   * method invocation.  Will block forever. The get() method should be
   * used instead since it separates the error value from the result,
   * and also permits timeouts.
   */
  operator T ();

  /// Check if the result is available.
  int ready (void) const;

  /**
   * Attaches the specified observer to a subject (this ACE_Future).
   * The update method of the specified subject will be invoked with a copy of
   * the associated ACE_Future as input when the result gets set.  If the
   * result is already set when this method gets invoked, then the update
   * method of the specified subject will be invoked immediately.
   *
   * @param observer The observer to attach to the subject.
   *
   * @retval  0   Success.
   * @retval  1   The observer was already attached.
   * @retval -1   Error; check ACE_OS::last_error() for an error code.
   */
  int attach (ACE_Future_Observer<T> *observer);

  /**
   * Detaches the specified observer from a subject (this ACE_Future).
   * The update method of the specified subject will not be invoked when the
   * ACE_Future_Rep result gets set.
   *
   * @param observer The observer to attach to the subject.
   *
   * @retval  0   The observer was successfully detached.
   * @retval -1   Error, including the observer not attached prior
   *              to calling this method.
   */
  int detach (ACE_Future_Observer<T> *observer);

  /// Dump the state of an object.
  void dump (void) const;

  /**
   * Get the underlying ACE_Future_Rep pointer. Note that this method should
   * rarely, if ever, be used and that modifying the underlying
   * ACE_Future_Rep should be done with extreme caution.
   */
  ACE_Future_Rep<T> *get_rep (void);

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

private:

  /// The ACE_Future_Rep
  /// Protect operations on the <Future>.
  typedef ACE_Future_Rep<T> FUTURE_REP;
  FUTURE_REP *future_rep_;
};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (ACE_TEMPLATES_REQUIRE_SOURCE)
#include "ace/Future.cpp"
#endif /* ACE_TEMPLATES_REQUIRE_SOURCE */

#if defined (ACE_TEMPLATES_REQUIRE_PRAGMA)
#pragma implementation ("Future.cpp")
#endif /* ACE_TEMPLATES_REQUIRE_PRAGMA */

#endif /* ACE_HAS_THREADS */

#include /**/ "ace/post.h"

#endif /* ACE_FUTURE_H */
