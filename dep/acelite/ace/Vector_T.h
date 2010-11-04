// -*- C++ -*-

//==========================================================================
/**
 *  @file    Vector_T.h
 *
 *  $Id: Vector_T.h 92069 2010-09-28 11:38:59Z johnnyw $
 *
 *  @author Craig L. Ching <cching@mqsoftware.com>
 *  @author Gonzalo Diethelm <gonzalo.diethelm@aditiva.com>
 */
//==========================================================================

#ifndef ACE_VECTOR_T_H
#define ACE_VECTOR_T_H

#include /**/ "ace/pre.h"

#include "ace/Containers_T.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/*
 * Default size for an ACE_Vector.
 */
static const size_t ACE_VECTOR_DEFAULT_SIZE = 32;

// Forward declaration.
template <class T, size_t DEFAULT_SIZE> class ACE_Vector_Iterator;

/**
 * @class ACE_Vector
 *
 * @brief Defines an STL-like vector container.
 *
 * This is an STL-like template vector container, a wrapper around
 * ACE_Array.  It provides at least the basic std::vector look and
 * feel: push_back(), clear(), resize(), capacity().  This template
 * class uses the copy semantic paradigm, though it is okay to use
 * reference counted smart pointers (see ACE_Ptr&lt;T&gt;) with this
 * template class.
 *
 * <b> Requirements and Performance Characteristics</b>
 *   - Internal Structure
 *       ACE_Array
 *   - Duplicates allowed?
 *       Yes
 *   - Random access allowed?
 *       No
 *   - Search speed
 *       N/A
 *   - Insert/replace speed
 *       Linear
 *   - Iterator still valid after change to container?
 *       Yes
 *   - Frees memory for removed elements?
 *       No
 *   - Items inserted by
 *       Value
 *   - Requirements for contained type
 *       -# Default constructor
 *       -# Copy constructor
 *       -# operator=
 */
template<class T, size_t DEFAULT_SIZE = ACE_VECTOR_DEFAULT_SIZE>
class ACE_Vector : public ACE_Array<T>
{
public:
  /**
   * A short name for iterator for ACE_Vector.
   */
  typedef ACE_Vector_Iterator<T, DEFAULT_SIZE> Iterator;


  /**
   * General constructor.
   *
   * @param init_size Initial size of the vector with the default
   *                  value of DEFAULT_SIZE
   * @param alloc Pointer to an ACE allocator.  If it is NULL then the
   *              default ACE allocator is used
   */
  ACE_Vector (const size_t init_size = DEFAULT_SIZE,
              ACE_Allocator* alloc = 0);

  /**
   * Destructor.
   */
  ~ACE_Vector ();

  /**
   * Returns the current vector capacity, that is, the currently
   * allocated buffer size.
   *
   * @return Current buffer size of the vector
   */
  size_t capacity (void) const;

  /**
   * Returns the vector's dynamic size / actual current size of the
   * vector.  Do not confuse it with ACE_Array::size(), which returns
   * the array's capacity.  Unfortunately, ACE is not very consistent
   * with the function names.
   *
   * @return Dynamic size / actual current size of the vector.
   */
  size_t size (void) const;

  /**
   * Clears out the vector.  It does not reallocate the vector's
   * buffer, it is just sets the vector's dynamic size to 0.
   */
  void clear (void);

  /**
   * Resizes the vector to the new capacity.  If the vector's current
   * capacity is smaller than the size to be specified, then the
   * buffer gets reallocated.  If the new capacity is less than the
   * current capacity of the vector, the buffer size stays the same.
   *
   * @param new_size New capacity of the vector
   * @param t A filler value (of the class T) for initializing the
   *          elements of the vector with.  By default, if this
   *          parameter is not specified, the default value of the
   *          class T will be used (for more detail, see the
   *          initialization clause for this parameter).
   */
  void resize (const size_t new_size,
               const T& t);

  /**
   * Appends a new element to the vector ("push back").  If the
   * dynamic size of the vector is equal to the capacity of the vector
   * (vector is at capacity), the vector automatically doubles its
   * capacity.
   *
   * @param elem A reference to the new element to be appended.  By
   *             default, this parameters gets initialized with the
   *             default value of the class T.
   */
  void push_back (const T& elem);

  /**
   * Deletes the last element from the vector ("pop back").  What this
   * function really does is decrement the dynamic size of the
   * vector.  The vector's buffer does not get reallocated for
   * performance.
   */
  void pop_back (void);

  /**
   * This function dumps the content of the vector.  TO BE MOVED out
   * of this class.  It needs to be implemented as a global template
   * function that accepts a const ACE_Vector&lt;T&gt;, in order to
   * make instances of this class compile on Linux, AIX.  G++ and xlC
   * have template instantiation algoriths, which are different from
   * the one in Visual C++.  The algorithms try to instantiate ALL
   * methods declared in the template class, regardless of whether the
   * functions are used or not.  That is, all of the classes, that are
   * used as elements in ACE_Vector's, have to have the dump() methods
   * defined in them (seems to be overkill).
   *
   * This function calls T::dump() for each element of the vector.
   */
  void dump (void) const;

  // = Compare operators

  /// Equality comparison operator.
  /**
   * Compare this vector with @arg s for equality.  Two vectors are equal
   * if their sizes are equal and all the elements are equal.
   */
  bool operator== (const ACE_Vector<T, DEFAULT_SIZE> &s) const;

  /// Inequality comparison operator.
  /**
   * Compare this vector with @arg s for inequality such that @c *this !=
   * @arg s is always the complement of the boolean return value of
   * @c *this == @arg s.
   */
  bool operator!= (const ACE_Vector<T, DEFAULT_SIZE> &s) const;

  void swap (ACE_Vector &rhs);

protected:

  /**
   * Dynamic size (length) of the vector.
   */
  size_t length_;

  /**
   * Current capacity (buffer size) of the vector.
   */
  size_t curr_max_size_;

  friend class ACE_Vector_Iterator<T, DEFAULT_SIZE>;
};

/**
 * @class ACE_Vector_Iterator
 *
 * @brief Implement an iterator over an ACE_Vector.
 *
 * This iterator is safe in the face of vector element deletions.
 * But it is NOT safe if the vector is resized via the assignment
 * operator during iteration.  That would be very odd, and dangerous.
 */
template <class T, size_t DEFAULT_SIZE = ACE_VECTOR_DEFAULT_SIZE>
class ACE_Vector_Iterator
{
public:
  // = Initialization method.
  ACE_Vector_Iterator (ACE_Vector<T, DEFAULT_SIZE> &);

  // = Iteration methods.

  /// Pass back the @a next_item that hasn't been seen in the vector.
  /// Returns 0 when all items have been seen, else 1.
  int next (T *&next_item);

  /// Move forward by one element in the vector.  Returns 0 when all the
  /// items in the vector have been seen, else 1.
  int advance (void);

  /// Returns 1 when all items have been seen, else 0.
  int done (void) const;

  /// Dump the state of an object.
  void dump (void) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

private:
  /// Pointer to the current item in the iteration.
  size_t current_;

  /// Reference to the vector we're iterating over.
  ACE_Vector<T, DEFAULT_SIZE> &vector_;
};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ace/Vector_T.inl"
#endif /* __ACE_INLINE__ */

#if defined (ACE_TEMPLATES_REQUIRE_SOURCE)
#include "ace/Vector_T.cpp"
#endif /* ACE_TEMPLATES_REQUIRE_SOURCE */

#if defined (ACE_TEMPLATES_REQUIRE_PRAGMA)
#pragma implementation ("Vector_T.cpp")
#endif /* ACE_TEMPLATES_REQUIRE_PRAGMA */

#include /**/ "ace/post.h"

#endif /* ACE_VECTOR_T_H */
