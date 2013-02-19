// -*- C++ -*-

//=============================================================================
/**
 *  @file Unbounded_Set_Ex.h
 *
 *  $Id: Unbounded_Set_Ex.h 88978 2010-02-13 16:03:31Z hillj $
 *
 *  @author Douglas C. Schmidt <schmidt@cs.wustl.edu>
 */
//=============================================================================

#ifndef ACE_UNBOUNDED_SET_EX_H
#define ACE_UNBOUNDED_SET_EX_H
#include /**/ "ace/pre.h"

#include "ace/Node.h"
#include "ace/os_include/os_stddef.h"
#include <iterator>

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

class ACE_Allocator;

template <class T, class C>
class ACE_Unbounded_Set_Ex_Iterator;

template <class T, class C>
class ACE_Unbounded_Set_Ex_Const_Iterator;

template <class T, class C>
class ACE_Unbounded_Set_Ex;

/**
 * @class ACE_Unbounded_Set_Ex_Iterator
 *
 * @brief Implement an iterator over an unbounded set.
 */
template <class T, class C>
class ACE_Unbounded_Set_Ex_Iterator
{
public:
  /// Type definition of the container type.
  typedef ACE_Unbounded_Set_Ex<T, C> container_type;

  // = std::iterator_traits typedefs/traits.
  typedef std::forward_iterator_tag                iterator_category;
  typedef typename container_type::value_type      value_type;
  typedef typename container_type::reference       reference;
  typedef typename container_type::pointer         pointer;
  typedef typename container_type::difference_type difference_type;

  // = Initialization method.
  ACE_Unbounded_Set_Ex_Iterator (ACE_Unbounded_Set_Ex<T, C> &s, bool end = false);

  // = Iteration methods.

  /// Pass back the @a next_item that hasn't been seen in the Set.
  /// Returns 0 when all items have been seen, else 1.
  int next (T *&next_item);

  /// Move forward by one element in the set.  Returns 0 when all the
  /// items in the set have been seen, else 1.
  int advance (void);

  /// Move to the first element in the set.  Returns 0 if the
  /// set is empty, else 1.
  int first (void);

  /// Returns 1 when all items have been seen, else 0.
  int done (void) const;

  /// Dump the state of an object.
  void dump (void) const;

  // = STL styled iteration, compare, and reference functions.

  /// Postfix advance.
  ACE_Unbounded_Set_Ex_Iterator<T, C> operator++ (int);

  /// Prefix advance.
  ACE_Unbounded_Set_Ex_Iterator<T, C>& operator++ (void);

  /// Returns a reference to the internal element @c this is pointing to.
  T& operator* (void);

  /// Check if two iterators point to the same position
  bool operator== (const ACE_Unbounded_Set_Ex_Iterator<T, C> &) const;
  bool operator!= (const ACE_Unbounded_Set_Ex_Iterator<T, C> &) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

private:

  /// Pointer to the current node in the iteration.
  ACE_Node<T, C> *current_;

  /// Pointer to the set we're iterating over.
  ACE_Unbounded_Set_Ex<T, C> *set_;
};

/**
 * @class ACE_Unbounded_Set_Ex_Const_Iterator
 *
 * @brief Implement an const iterator over an unbounded set.
 */
template <class T, class C>
class ACE_Unbounded_Set_Ex_Const_Iterator
{
public:
  typedef ACE_Unbounded_Set_Ex<T, C> container_type;

  // = std::iterator_traits typedefs/traits.
  typedef std::forward_iterator_tag                 iterator_category;
  typedef typename container_type::const_value_type value_type;
  typedef typename container_type::const_reference  reference;
  typedef typename container_type::const_pointer    pointer;
  typedef typename container_type::difference_type  difference_type;

  // = Initialization method.
  ACE_Unbounded_Set_Ex_Const_Iterator (const ACE_Unbounded_Set_Ex<T, C> &s,
                                       bool end = false);

  // = Iteration methods.

  /// Pass back the @a next_item that hasn't been seen in the Set.
  /// @return Returns 0 when all items have been seen, else 1.
  int next (T *&next_item);

  /// Move forward by one element in the set.  Returns 0 when all the
  /// items in the set have been seen, else 1.
  int advance (void);

  /// Move to the first element in the set.  Returns 0 if the
  /// set is empty, else 1.
  int first (void);

  /// Returns 1 when all items have been seen, else 0.
  int done (void) const;

  /// Dump the state of an object.
  void dump (void) const;

  // = STL styled iteration, compare, and reference functions.

  /// Postfix advance.
  ACE_Unbounded_Set_Ex_Const_Iterator<T, C> operator++ (int);

  /// Prefix advance.
  ACE_Unbounded_Set_Ex_Const_Iterator<T, C>& operator++ (void);

  /// Returns a reference to the internal element @c this is pointing to.
  T& operator* (void);

  /// Check if two iterators point to the same position
  bool operator== (const ACE_Unbounded_Set_Ex_Const_Iterator<T, C> &) const;
  bool operator!= (const ACE_Unbounded_Set_Ex_Const_Iterator<T, C> &) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

private:

  /// Pointer to the current node in the iteration.
  ACE_Node<T, C> *current_;

  /// Pointer to the set we're iterating over.
  const ACE_Unbounded_Set_Ex<T, C> *set_;
};

/**
 * @class ACE_Unbounded_Set_Ex
 *
 * @brief Implement a simple unordered set of <T> of unbounded size.
 *
 * This implementation of an unordered set uses a circular
 * linked list with a dummy node.  This implementation does not
 * allow duplicates, but it maintains FIFO ordering of insertions.
 *
 * This implementation may also be parameterized with a comparator
 * functor, which must implement bool operator () (const T&, const T&) const,
 * returning true if the given items are equivalent.  The default comparator
 * is sufficient for objects reliably compared with operator==.
 *
 * <b> Requirements and Performance Characteristics</b>
 *   - Internal Structure
 *       Circular linked list
 *   - Duplicates allowed?
 *       No
 *   - Random access allowed?
 *       No
 *   - Search speed
 *       Linear
 *   - Insert/replace speed
 *       Linear
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
 *       -# operator== const
 *
 */
template <class T, class C>
class ACE_Unbounded_Set_Ex
{
public:
  friend class ACE_Unbounded_Set_Ex_Iterator<T, C>;
  friend class ACE_Unbounded_Set_Ex_Const_Iterator<T, C>;

  // Trait definition.
  typedef ACE_Unbounded_Set_Ex_Iterator<T, C> ITERATOR;
  typedef ACE_Unbounded_Set_Ex_Iterator<T, C> iterator;
  typedef ACE_Unbounded_Set_Ex_Const_Iterator<T, C> CONST_ITERATOR;
  typedef ACE_Unbounded_Set_Ex_Const_Iterator<T, C> const_iterator;
  typedef C COMP;
  typedef ACE_Node<T, C> NODE;

  // = STL typedefs/traits.
  typedef T                   value_type;
  typedef T const             const_value_type;
  typedef value_type &        reference;
  typedef const_value_type &  const_reference;
  typedef value_type *        pointer;
  typedef const_value_type *  const_pointer;
  typedef ptrdiff_t           difference_type;

  // = Initialization and termination methods.
  /// Constructor.  Use user specified allocation strategy
  /// if specified.
  /**
   * Initialize an empty set using the allocation strategy of the user if
   * provided.
   */
  ACE_Unbounded_Set_Ex (ACE_Allocator *alloc = 0);

  /**
   * Initialize an empty set using the allocation strategy of the user if
   * provided, and a given comparator functor.
   */
  ACE_Unbounded_Set_Ex (const C &comparator, ACE_Allocator *alloc = 0);

  /// Copy constructor.
  /**
   * Initialize this set to be an exact copy of the set provided.
   */
  ACE_Unbounded_Set_Ex (const ACE_Unbounded_Set_Ex<T, C> &);

  /// Assignment operator.
  /**
   * Perform a deep copy of the rhs into the lhs.
   */
  ACE_Unbounded_Set_Ex<T, C> & operator= (const ACE_Unbounded_Set_Ex<T, C> &);

  /// Destructor.
  /**
   * Destroy the nodes of the set.
   */
  ~ACE_Unbounded_Set_Ex (void);

  // = Check boundary conditions.

  /// Returns @c true if the container is empty, otherwise returns @c false.
  /**
   * Constant time is_empty check.
   */
  bool is_empty (void) const;

  /// Returns @c false.
  /**
   * Always returns @c false since the set can never fill up.
   */
  bool is_full (void) const;

  // = Classic unordered set operations.

  /// Linear insertion of an item.
  /**
   * Insert @a new_item into the set (doesn't allow duplicates).
   * Returns -1 if failures occur, 1 if item is already present, else
   * 0.
   */
  int insert (const T &new_item);

  /// Insert @a item at the tail of the set (doesn't check for
  /// duplicates).
  /**
   * Constant time insert at the end of the set.
   */
  int insert_tail (const T &item);

  /// Linear remove operation.
  /**
   * Remove first occurrence of @a item from the set.  Returns 0 if
   * it removes the item, -1 if it can't find the item, and -1 if a
   * failure occurs.
   */
  int remove (const T &item);

  /// Finds if @a item occurs in the set.  Returns 0 if find succeeds,
  /// else -1.
  /**
   * Performs a linear find operation.
   */
  int find (const T &item) const;

  /// Size of the set.
  /**
   * Access the size of the set.
   */
  size_t size (void) const;

  /// Dump the state of an object.
  void dump (void) const;

  /// Reset the ACE_Unbounded_Set_Ex to be empty.
  /**
   * Delete the nodes of the set.
   */
  void reset (void);

  // = STL-styled unidirectional iterator factory.
  iterator begin (void);
  iterator end (void);
  const_iterator begin (void) const;
  const_iterator end (void) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

private:
  /// Delete all the nodes in the Set.
  void delete_nodes (void);

  /// Copy nodes into this set.
  void copy_nodes (const ACE_Unbounded_Set_Ex<T, C> &);

  /// Head of the linked list of Nodes.
  NODE *head_;

  /// Current size of the set.
  size_t cur_size_;

  /// Allocation strategy of the set.
  ACE_Allocator *allocator_;

  /// Comparator to be used
  COMP comp_;
};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ace/Unbounded_Set_Ex.inl"
#endif /* __ACE_INLINE__ */

#if defined (ACE_TEMPLATES_REQUIRE_SOURCE)
#include "ace/Unbounded_Set_Ex.cpp"
#endif /* ACE_TEMPLATES_REQUIRE_SOURCE */

#if defined (ACE_TEMPLATES_REQUIRE_PRAGMA)
#pragma implementation ("Unbounded_Set_Ex.cpp")
#endif /* ACE_TEMPLATES_REQUIRE_PRAGMA */

#include /**/ "ace/post.h"
#endif /* ACE_UNBOUNDED_SET_H */
