// -*- C++ -*-

//=============================================================================
/**
 * @file    Array_Map.h
 *
 * $Id: Array_Map.h 80826 2008-03-04 14:51:23Z wotte $
 *
 * Light weight array-based map with fast iteration but linear
 * (i.e. O(n)) search times.  STL-style interface is exposed.
 *
 * @note This class requires the STL generic algorithms and
 *       reverse_iterator adapter.
 *
 * @author  Ossama Othman
 */
//=============================================================================


#ifndef ACE_ARRAY_MAP_H
#define ACE_ARRAY_MAP_H

#include /**/ "ace/pre.h"

#include "ace/config-lite.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include <utility>
#include <iterator>
#include <functional>

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class ACE_Array_Map
 *
 * @brief Light weight array-based map with fast iteration, but linear
 *        (i.e. O(n)) search times.
 *
 * Map implementation that focuses on small footprint and fast
 * iteration.  Search times are, however, linear (O(n)) meaning that
 * this map isn't suitable for large data sets that will be searched
 * in performance critical areas of code.  Iteration over large data
 * sets, however, is faster than linked list-based maps, for example,
 * since spatial locality is maximized through the use of contiguous
 * arrays as the underlying storage.
 * @par
 * An @c ACE_Array_Map is a unique associative container, meaning that
 * duplicate values may not be added to the map.  It is also pair
 * associative (value_type is a std::pair<>).  It is not a sorted
 * container.
 * @par
 * An STL @c std::map -like interface is exposed by this class
 * portability.  Furthermore, this map's iterators are compatible with
 * STL algorithms.
 * @par
 * <b> Requirements and Performance Characteristics</b>
 *   - Internal Structure
 *       Array
 *   - Duplicates allowed?
 *       No
 *   - Random access allowed?
 *       Yes
 *   - Search speed
 *       O(n)
 *   - Insert/replace speed
 *       O(n), can be longer if the map has to resize
 *   - Iterator still valid after change to container?
 *       No
 *   - Frees memory for removed elements?
 *       Yes
 *   - Items inserted by
 *       Value
 *   - Requirements for key type
 *       -# Default constructor
 *       -# Copy constructor
 *       -# operator=
 *       -# operator==
 *   - Requirements for object type
 *       -# Default constructor
 *       -# Copy constructor
 *       -# operator=
 */
template<typename Key, typename Value, class EqualTo = std::equal_to<Key> >
class ACE_Array_Map
{
public:

  // STL-style typedefs/traits.
  typedef Key                            key_type;
  typedef Value                          data_type;
  typedef std::pair<key_type, data_type> value_type;
  typedef value_type *                   iterator;
  typedef value_type const *             const_iterator;
  typedef value_type &                   reference;
  typedef value_type const &             const_reference;
  typedef value_type *                   pointer;
  typedef value_type const *             const_pointer;
  typedef ptrdiff_t                      difference_type;
  typedef size_t                         size_type;

  ACE_DECLARE_STL_REVERSE_ITERATORS

  /// Default Constructor.
  /**
   * Create an empty map with a preallocated buffer of size @a s.
   */
  ACE_Array_Map (size_type s = 0);

#ifndef ACE_LACKS_MEMBER_TEMPLATES
  template<typename InputIterator>
  ACE_Array_Map (InputIterator f, InputIterator l);
#else
  ACE_Array_Map (const_iterator f, const_iterator l);
#endif  /* !ACE_LACKS_MEMBER_TEMPLATES */

  ACE_Array_Map (ACE_Array_Map const & map);
  ACE_Array_Map & operator= (ACE_Array_Map const & map);

  /// Destructor.
  ~ACE_Array_Map (void);

  /**
   * @name Forward Iterator Accessors
   *
   * Forward iterator accessors.
   */
  //@{
  iterator begin (void);
  iterator end   (void);
  const_iterator begin (void) const;
  const_iterator end   (void) const;
  //@}

  /**
   * @name Reverse Iterator Accessors
   *
   * Reverse iterator accessors.
   */
  //@{
  reverse_iterator rbegin (void);
  reverse_iterator rend   (void);
  const_reverse_iterator rbegin (void) const;
  const_reverse_iterator rend   (void) const;
  //@}

  /// Return current size of map.
  /**
   * @return The number of elements in the map.
   */
  size_type size (void) const;

  /// Maximum number of elements the map can hold.
  size_type max_size (void) const;

  /// Return @c true if the map is empty, else @c false.
  bool is_empty (void) const;  // ACE style

  /**
   * Return @c true if the map is empty, else @c false.  We recommend
   * using @c is_empty() instead since it's more consistent with the
   * ACE container naming conventions.
   */
  bool empty (void) const;  // STL style

  /// Swap the contents of this map with the given @a map in an
  /// exception-safe manner.
  void swap (ACE_Array_Map & map);

  /// Insert the value @a x into the map.
  /**
   * STL-style map insertion method.
   *
   * @param x @c std::pair containing key and datum.
   *
   * @return @c std::pair::second will be @c false if the map already
   *         contains a value with the same key as @a x.
   */
  std::pair<iterator, bool> insert (value_type const & x);

#ifndef ACE_LACKS_MEMBER_TEMPLATES
  /// Insert range of elements into map.
  template<typename InputIterator>
  void insert (InputIterator f, InputIterator l);
#else
  /// Insert range of elements into map.
  void insert (const_iterator f, const_iterator l);
#endif  /* ACE_LACKS_MEMBER_TEMPLATES */

  /// Remove element at position @a pos from the map.
  void erase (iterator pos);

  /// Remove element corresponding to key @a k from the map.
  /**
   * @return Number of elements that were erased.
   */
  size_type erase (key_type const & k);

  /// Remove range of elements [@a first, @a last) from the map.
  /**
   * @note [@a first, @a last) must be valid range within the map.
   */
  void erase (iterator first, iterator last);

  /// Clear contents of map.
  /**
   * @note This a constant time (O(1)) operation.
   */
  void clear (void);

  /**
   * @name Search Operations
   *
   * Search the map for data corresponding to key @a k.
   */
  //@{
  /**
   * @return @c end() if data corresponding to key @a k is not in the
   *         map.
   */
  iterator find (key_type const & k);

  /**
   * @return @c end() if data corresponding to key @a k is not in the
   *         map.
   */
  const_iterator find (key_type const & k) const;
  //@}

  /// Count the number of elements corresponding to key @a k.
  /**
   * @return In the case of this map, the count will always be one if
   *         such exists in the map.
   */
  size_type count (key_type const & k);

  /// Convenience array index operator.
  /**
   * Array index operator that allows insertion and retrieval of
   * elements using an array index syntax, such as:
   * @par
   * map["Foo"] = 12;
   */
  data_type & operator[] (key_type const & k);

private:

  /// Increase size of underlying buffer by @a s.
  void grow (size_type s);

private:

  /// Number of elements in the map.
  size_type size_;

  /// Current size of underlying array.
  /**
   * @note @c capacity_ is always greater than or equal to @c size_;
   */
  size_type capacity_;

  /// Underlying array containing keys and data.
  value_type * nodes_;

};

// --------------------------------------------------------------

/// @c ACE_Array_Map equality operator.
template <typename Key, typename Value, class EqualTo>
bool operator== (ACE_Array_Map<Key, Value, EqualTo> const & lhs,
                 ACE_Array_Map<Key, Value, EqualTo> const & rhs);

/// @c ACE_Array_Map lexicographical comparison operator.
template <typename Key, typename Value, class EqualTo>
bool operator<  (ACE_Array_Map<Key, Value, EqualTo> const & lhs,
                 ACE_Array_Map<Key, Value, EqualTo> const & rhs);

// --------------------------------------------------------------

ACE_END_VERSIONED_NAMESPACE_DECL

#ifdef __ACE_INLINE__
# include "ace/Array_Map.inl"
#endif /* __ACE_INLINE__ */

#if defined (ACE_TEMPLATES_REQUIRE_SOURCE)
# include "ace/Array_Map.cpp"
#endif /* ACE_TEMPLATES_REQUIRE_SOURCE */

#if defined (ACE_TEMPLATES_REQUIRE_PRAGMA)
#pragma implementation ("Array_Map.cpp")
#endif /* ACE_TEMPLATES_REQUIRE_PRAGMA */

#include /**/ "ace/post.h"

#endif  /* ACE_ARRAY_MAP_H */

