// -*- C++ -*-

//=============================================================================
/**
 *  @file Unbounded_Queue.h
 *
 *  $Id: Unbounded_Queue.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Douglas C. Schmidt <schmidt@cs.wustl.edu>
 */
//=============================================================================

#ifndef ACE_UNBOUNDED_QUEUE_H
#define ACE_UNBOUNDED_QUEUE_H
#include /**/ "ace/pre.h"

#include "ace/Node.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/os_include/os_stddef.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

class ACE_Allocator;

template <class T>
class ACE_Unbounded_Queue;

/**
 * @class ACE_Unbounded_Queue_Iterator
 *
 * @brief Implement an iterator over an unbounded queue.
 */
template <class T>
class ACE_Unbounded_Queue_Iterator
{
public:
  // = Initialization method.
  ACE_Unbounded_Queue_Iterator (ACE_Unbounded_Queue<T> &q, int end = 0);

  // = Iteration methods.

  /// Pass back the @a next_item that hasn't been seen in the queue.
  /// Returns 0 when all items have been seen, else 1.
  int next (T *&next_item);

  /// Move forward by one element in the set.  Returns 0 when all the
  /// items in the queue have been seen, else 1.
  int advance (void);

  /// Move to the first element in the queue.  Returns 0 if the
  /// queue is empty, else 1.
  int first (void);

  /// Returns 1 when all items have been seen, else 0.
  int done (void) const;

  /// Dump the state of an object.
  void dump (void) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

private:
  /// Pointer to the current node in the iteration.
  ACE_Node<T> *current_;

  /// Pointer to the queue we're iterating over.
  ACE_Unbounded_Queue<T> &queue_;
};

/**
 * @class ACE_Unbounded_Queue_Const_Iterator
 *
 * @brief Implement an iterator over an const unbounded queue.
 */
template <class T>
class ACE_Unbounded_Queue_Const_Iterator
{
public:
  // = Initialization method.
  ACE_Unbounded_Queue_Const_Iterator (const ACE_Unbounded_Queue<T> &q, int end = 0);

  // = Iteration methods.

  /// Pass back the @a next_item that hasn't been seen in the queue.
  /// Returns 0 when all items have been seen, else 1.
  int next (T *&next_item);

  /// Move forward by one element in the set.  Returns 0 when all the
  /// items in the queue have been seen, else 1.
  int advance (void);

  /// Move to the first element in the queue.  Returns 0 if the
  /// queue is empty, else 1.
  int first (void);

  /// Returns 1 when all items have been seen, else 0.
  int done (void) const;

  /// Dump the state of an object.
  void dump (void) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

private:
  /// Pointer to the current node in the iteration.
  ACE_Node<T> *current_;

  /// Pointer to the queue we're iterating over.
  const ACE_Unbounded_Queue<T> &queue_;
};

/**
 * @class ACE_Unbounded_Queue
 *
 * @brief A Queue of "infinite" length.
 *
 * This implementation of an unbounded queue uses a circular
 * linked list with a dummy node.
 *
 * <b> Requirements and Performance Characteristics</b>
 *   - Internal Structure
 *       Circular linked list
 *   - Duplicates allowed?
 *       Yes
 *   - Random access allowed?
 *       No
 *   - Search speed
 *       N/A
 *   - Insert/replace speed
 *       N/A
 *   - Iterator still valid after change to container?
 *       Yes
 *   - Frees memory for removed elements?
 *       Yes
 *   - Items inserted by
 *       Value
 *   - Requirements for contained type
 *       -# Default constructor
 *       -# Copy constructor
 *       -# operator=
 *
 */
template <class T>
class ACE_Unbounded_Queue
{
public:
  friend class ACE_Unbounded_Queue_Iterator<T>;
  friend class ACE_Unbounded_Queue_Const_Iterator<T>;

  // Trait definition.
  typedef ACE_Unbounded_Queue_Iterator<T> ITERATOR;
  typedef ACE_Unbounded_Queue_Const_Iterator<T> CONST_ITERATOR;

  // = Initialization and termination methods.
  /// Construction.  Use user specified allocation strategy
  /// if specified.
  /**
   * Initialize an empty queue using the strategy provided.
   */
  ACE_Unbounded_Queue (ACE_Allocator *alloc = 0);

  /// Copy constructor.
  /**
   * Initialize the queue to be a copy of the provided queue.
   */
  ACE_Unbounded_Queue (const ACE_Unbounded_Queue<T> &);

  /// Assignment operator.
  /**
   * Perform a deep copy of rhs.
   */
  void operator= (const ACE_Unbounded_Queue<T> &);

  /// Destructor.
  /**
   * Clean up the memory for the queue.
   */
  ~ACE_Unbounded_Queue (void);

  // = Check boundary conditions.

  /// Returns 1 if the container is empty, otherwise returns 0.
  /**
   * Constant time check to see if the queue is empty.
   */
  int is_empty (void) const;

  /// Returns 0.
  /**
   * The queue cannot be full, so it always returns 0.
   */
  int is_full (void) const;

  // = Classic queue operations.

  /// Adds @a new_item to the tail of the queue.  Returns 0 on success,
  /// -1 on failure.
  /**
   * Insert an item at the end of the queue.
   */
  int enqueue_tail (const T &new_item);

  /// Adds @a new_item to the head of the queue.  Returns 0 on success,
  /// -1 on failure.
  /**
   * Insert an item at the head of the queue.
   */
  int enqueue_head (const T &new_item);

  /// Removes and returns the first @a item on the queue.  Returns 0 on
  /// success, -1 if the queue was empty.
  /**
   * Remove an item from the head of the queue.
   */
  int dequeue_head (T &item);

  // = Additional utility methods.

  /// Reset the ACE_Unbounded_Queue to be empty and release all its
  /// dynamically allocated resources.
  /**
   * Delete the queue nodes.
   */
  void reset (void);

  /// Get the @a slot th element in the set.  Returns -1 if the element
  /// isn't in the range {0..#cur_size_ - 1}, else 0.
  /**
   * Find the item in the queue between 0 and the provided index of the
   * queue.
   */
  int get (T *&item, size_t slot = 0) const;

  /// Set the @a slot th element of the queue to @a item.
  /**
   * Set the @a slot th element in the set.  Will pad out the set with
   * empty nodes if @a slot is beyond the range {0..#cur_size_ - 1}.
   * Returns -1 on failure, 0 if @a slot isn't initially in range, and
   * 0 otherwise.
   */
  int set (const T &item, size_t slot);

  /// The number of items in the queue.
  /**
   * Return the size of the queue.
   */
  size_t size (void) const;

  /// Dump the state of an object.
  void dump (void) const;

  // = STL-styled unidirectional iterator factory.
  ACE_Unbounded_Queue_Iterator<T> begin (void);
  ACE_Unbounded_Queue_Iterator<T> end (void);

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

protected:
  /// Delete all the nodes in the queue.
  void delete_nodes (void);

  /// Copy nodes into this queue.
  void copy_nodes (const ACE_Unbounded_Queue<T> &);

  /// Pointer to the dummy node in the circular linked Queue.
  ACE_Node<T> *head_;

  /// Current size of the queue.
  size_t cur_size_;

  /// Allocation Strategy of the queue.
  ACE_Allocator *allocator_;
};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ace/Unbounded_Queue.inl"
#endif /* __ACE_INLINE__ */

#if defined (ACE_TEMPLATES_REQUIRE_SOURCE)
#include "ace/Unbounded_Queue.cpp"
#endif /* ACE_TEMPLATES_REQUIRE_SOURCE */

#if defined (ACE_TEMPLATES_REQUIRE_PRAGMA)
#pragma implementation ("Unbounded_Queue.cpp")
#endif /* ACE_TEMPLATES_REQUIRE_PRAGMA */

#include /**/ "ace/post.h"
#endif /* ACE_UNBOUNDED_QUEUE_H */

