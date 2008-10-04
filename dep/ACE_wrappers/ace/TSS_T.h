// -*- C++ -*-

//==========================================================================
/**
 *  @file    TSS_T.h
 *
 *  $Id: TSS_T.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *   Moved from Synch.h.
 *
 *  @author Douglas C. Schmidt <schmidt@cs.wustl.edu>
 */
//==========================================================================

#ifndef ACE_TSS_T_H
#define ACE_TSS_T_H
#include /**/ "ace/pre.h"

#include "ace/Lock.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

// This should probably go somewhere else, but it's only used here and
// in Thread_Manager.
// Note there is no ACE_TSS_SET because one would typicaly do
// 'ACE_TSS_GET()->xyz_ = value', so the macro would have been too
// complicated.
# if defined (ACE_HAS_THREADS) && (defined (ACE_HAS_THREAD_SPECIFIC_STORAGE) || defined (ACE_HAS_TSS_EMULATION))
#   define ACE_TSS_TYPE(T) ACE_TSS< T >
#   define ACE_TSS_GET(I, T) ((I)->operator T * ())
# else
#   define ACE_TSS_TYPE(T) T
#   define ACE_TSS_GET(I, T) (I)
# endif /* ACE_HAS_THREADS && (ACE_HAS_THREAD_SPECIFIC_STORAGE || ACE_HAS_TSS_EMULATION) */

#include "ace/Thread_Mutex.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class ACE_TSS
 *
 * @brief Allows objects that are "physically" in thread specific
 * storage (i.e., private to a thread) to be accessed as though
 * they were "logically" global to a program.
 *
 * This class helps to maintain a separate copy of an object for each thread
 * that needs access to it. All threads access a single instance of ACE_TSS
 * to obtain a pointer to a thread-specific copy of a TYPE object. Using
 * a pointer to TYPE in TSS instead of TYPE itself is useful because,
 * in addition to avoiding copies on what may be a complex class, it allows
 * assignment of objects to thread-specific data that have arbitrarily
 * complex constructors.
 *
 * When the ACE_TSS object is destroyed, all threads's instances of the
 * data are deleted.
 *
 * Modern compilers have no problem using a built-in type for @c TYPE.
 * However, if you must use an older compiler that won't work with a built-in
 * type, the ACE_TSS_Type_Adapter class template, below, can be used for
 * adapting built-in types to work with ACE_TSS.
 *
 * @note Beware when creating static instances of this type
 * (as with any other, btw). The unpredictable order of initialization
 * across different platforms may cause a situation where one uses
 * the instance before it is fully initialized. That's why typically
 * instances of this type are dynamicaly allocated. On the stack it is
 * typically allocated inside the ACE_Thread::svc() method which
 * limits its lifetime appropriately.
 *
 */
template <class TYPE>
class ACE_TSS
{
public:
  /**
   * Default constructor. Can also initialize this ACE_TSS instance,
   * readying it for use by the calling thread as well as all other
   * threads in the process. If the constructor does not initialize this
   * object, the first access to it will perform the initialization, which
   * could possibly (under odd error conditions) fail.
   *
   * @param ts_obj   If non-zero, this object is initialized for use by
   *                 all threads and @a ts_obj is used to set the
   *                 thread-specific value for the calling thread. Other
   *                 threads use the ts_object (TYPE *) method to set
   *                 a specific value.
   */
  ACE_TSS (TYPE *ts_obj = 0);

  /// Deregister this object from thread-specific storage administration.
  /// Will cause all threads' copies of TYPE to be destroyed.
  virtual ~ACE_TSS (void);

  /**
   * Set the thread-specific object for the calling thread.
   * If this object has not been initialized yet, this method performs the
   * initialization.
   *
   * @param new_ts_obj  The new value for the calling thread's copy of
   *                    this object.
   *
   * @return  The previous value of the calling thread's copy of this
   *          object; 0 if there was no previous value. This method also
   *          returns 0 on errors. To tell the difference between an error
   *          and a returned 0 pointer, it's recommended that one set errno
   *          to 0 prior to calling ts_object() and check for a new errno
   *          value if ts_object() returns 0.
   */
  TYPE *ts_object (TYPE *new_ts_obj);

  /** @name Accessors
   *
   * All accessors return a pointer to the calling thread's copy of the
   * TYPE data. The pointer may be 0 on error conditions or if the calling
   * thread's copy of the data has not yet been set. See specific method
   * descriptions for complete details.
   */
  //@{
  /**
   * Get the thread-specific object for this object.
   *
   * @return  0 if the object has never been initialized, otherwise returns
   *          the calling thread's copy of the data. The returned pointer
   *          may be 0 under odd error conditions; check errno for further
   *          information.
   */
  TYPE *ts_object (void) const;

  /**
   * Use a "smart pointer" to get the thread-specific data associated
   * with this object.
   * If this ACE_TSS object hasn't been initialized, this method
   * will initialize it as a side-affect. If the calling thread has not
   * set a value, a default-constructed instance of TYPE is allocated and it
   * becomes the thread's instance.
   *
   * @return  The calling thread's copy of the data. The returned pointer
   *          may be 0 under odd error conditions; check errno for further
   *          information.
   */
  TYPE *operator-> () const;

  /**
   * Obtain a pointer to the calling thread's TYPE object.
   * If this ACE_TSS object hasn't been initialized, this method
   * will initialize it as a side-affect. If the calling thread has not
   * set a value, a default-constructed instance of TYPE is allocated and it
   * becomes the thread's instance.
   *
   * @return  The calling thread's copy of the data. The returned pointer
   *          may be 0 under odd error conditions; check errno for further
   *          information.
   */
  operator TYPE *(void) const;

  //@}

  /// Hook for construction parameters.
  virtual TYPE *make_TSS_TYPE (void) const;

  // = Utility methods.

  /// Dump the state of an object.
  void dump (void) const;

  // ACE_ALLOC_HOOK_DECLARE;
  // Declare the dynamic allocation hooks.

protected:
  /// Actually implements the code that retrieves the object from
  /// thread-specific storage.
  TYPE *ts_get (void) const;

  /// Factors out common code for initializing TSS.  This must NOT be
  /// called with the lock held...
  int ts_init (void);

#if !(defined (ACE_HAS_THREADS) && (defined (ACE_HAS_THREAD_SPECIFIC_STORAGE) || defined (ACE_HAS_TSS_EMULATION)))
  /// This implementation only works for non-threading systems...
  TYPE *type_;
#else
  /// Avoid race conditions during initialization.
  ACE_Thread_Mutex keylock_;

  /// "First time in" flag.
  volatile bool once_;

  /// Key for the thread-specific error data.
  ACE_thread_key_t key_;

  /// "Destructor" that deletes internal TYPE * when thread exits.
  static void cleanup (void *ptr);
#endif /* defined (ACE_HAS_THREADS) && (defined (ACE_HAS_THREAD_SPECIFIC_STORAGE) || defined (ACE_HAS_TSS_EMULATION)) */
  // = Disallow copying...
  ACE_UNIMPLEMENTED_FUNC (void operator= (const ACE_TSS<TYPE> &))
  ACE_UNIMPLEMENTED_FUNC (ACE_TSS (const ACE_TSS<TYPE> &))
};

/**
 * @class ACE_TSS_Type_Adapter
 *
 * @brief Adapter that allows built-in types to be used with ACE_TSS.
 *
 * Wraps a value of a built-in type, providing conversions to
 * and from the type.  Example use with ACE_TSS:
 * ACE_TSS<ACE_TSS_Type_Adapter<int> > i;
 * *i = 37;
 * ACE_OS::fprintf (stderr, "%d\n", *i);
 * Unfortunately, though, some compilers have trouble with the
 * implicit type conversions.  This seems to work better:
 * ACE_TSS<ACE_TSS_Type_Adapter<int> > i;
 * i->operator int & () = 37;
 * ACE_OS::fprintf (stderr, "%d\n", i->operator int ());
 */
template <class TYPE>
class ACE_TSS_Type_Adapter
{
public:
  /// Constructor.  Inlined here so that it should _always_ be inlined.
  ACE_TSS_Type_Adapter (const TYPE value = 0): value_ (value) {}

  /// TYPE conversion.  Inlined here so that it should _always_ be
  /// inlined.
  operator TYPE () const { return value_; };

  /// TYPE & conversion.  Inlined here so that it should _always_ be
  /// inlined.
  operator TYPE &() { return value_; };

private:
  /// The wrapped value.
  TYPE value_;
};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ace/TSS_T.inl"
#endif /* __ACE_INLINE__ */

#if defined (ACE_TEMPLATES_REQUIRE_SOURCE)
#include "ace/TSS_T.cpp"
#endif /* ACE_TEMPLATES_REQUIRE_SOURCE */

#if defined (ACE_TEMPLATES_REQUIRE_PRAGMA)
#pragma implementation ("TSS_T.cpp")
#endif /* ACE_TEMPLATES_REQUIRE_PRAGMA */

#include /**/ "ace/post.h"
#endif /* ACE_TSS_T_H */
