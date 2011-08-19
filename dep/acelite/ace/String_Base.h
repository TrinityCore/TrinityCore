// -*- C++ -*-

//=============================================================================
/**
 *  @file    String_Base.h
 *
 *  $Id: String_Base.h 92057 2010-09-27 14:52:00Z johnnyw $
 *
 *  @author Douglas C. Schmidt (schmidt@cs.wustl.edu)
 *  @author Nanbor Wang <nanbor@cs.wustl.edu>
 */
//=============================================================================

#ifndef ACE_STRING_BASE_H
#define ACE_STRING_BASE_H

#include /**/ "ace/pre.h"

#include "ace/Global_Macros.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/String_Base_Const.h"
#include <iterator>

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

// Forward decl.
template <class ACE_CHAR_T>
class ACE_String_Base_Iterator;

// Forward decl.
template <class ACE_CHAR_T>
class ACE_String_Base_Const_Iterator;

/**
 * @class ACE_String_Base
 *
 * @brief This class provides a wrapper facade for C strings.
 *
 * This class uses an ACE_Allocator to allocate memory.  The
 * user can make this a persistant class by providing an
 * ACE_Allocator with a persistable memory pool.  This class is
 * optimized for efficiency, so it doesn't provide any internal
 * locking.
 * @note If an instance of this class is constructed from or
 * assigned an empty string (with first element of '\0'), then it
 * is not allocated new space.  Instead, its internal
 * representation is set equal to a global empty string.
 * CAUTION: in cases when ACE_String_Base is constructed from a
 * provided buffer with the release parameter set to false,
 * ACE_String_Base is not guaranteed to be '\0' terminated.
 *
 * \li Do not use a "@c -1" magic number to refer to the "no position"
 *     condition.  This was never the right thing to do.  The "@c npos"
 *     constant should be used in such cases.
 * \li Do not assign or pass string positions to or from signed types.
 *     Use the "@c size_type" @c typedef found in all ACE string
 *     classes.  This typedef is analogous to the "@c size_type"
 *     @c typedef found in the standard C++ string class as well as
 *     many STL class templates.  If you find yourself casting you're
 *     probably doing something wrong.
 */
template <class ACE_CHAR_T>
class ACE_String_Base : public ACE_String_Base_Const
{
public:
  using ACE_String_Base_Const::size_type;

  friend class ACE_String_Base_Iterator <ACE_CHAR_T>;
  friend class ACE_String_Base_Const_Iterator <ACE_CHAR_T>;

  // ACE-style iterators
  typedef ACE_String_Base_Iterator <ACE_CHAR_T> ITERATOR;
  typedef ACE_String_Base_Const_Iterator <ACE_CHAR_T> CONST_ITERATOR;

  // STL-style iterators
  typedef ACE_String_Base_Iterator <ACE_CHAR_T> iterator;
  typedef ACE_String_Base_Const_Iterator <ACE_CHAR_T> const_iterator;

   /**
    *  Default constructor.
    *
    *  @param the_allocator ACE_Allocator associated with string
    *  @return Default ACE_String_Base string.
    */
  ACE_String_Base (ACE_Allocator *the_allocator = 0);

  /**
   * Constructor that copies @a s into dynamically allocated memory.
   *
   * if release == true then a new buffer is allocated internally, and
   *   s is copied to the internal buffer.
   * if release == false then the s buffer is used directly. If s == 0
   *   then it will _not_ be used, and instead the internal buffer
   *   is set to NULL_String_.
   *
   * @param s Zero terminated input string
   * @param the_allocator ACE_Allocator associated with string
   * @param release Allocator responsible(true)/not responsible(false) for
   *    freeing memory.
   * @return ACE_String_Base containing const ACE_CHAR_T *s
   */
  ACE_String_Base (const ACE_CHAR_T *s,
                   ACE_Allocator *the_allocator = 0,
                   bool release = true);

  /**
   * Constructor that copies @a len CHARs of @a s into dynamically
   * allocated memory (will zero terminate the result).
   *
   * if release == true then a new buffer is allocated internally.
   *   s is copied to the internal buffer.
   * if release == false then the s buffer is used directly. If s == 0
   *   then it will _not_ be used, and instead the internal buffer
   *   is set to NULL_String_.
   *
   * @param s Non-zero terminated input string
   * @param len Length of non-zero terminated input string
   * @param the_allocator ACE_Allocator associated with string
   * @param release Allocator responsible(true)/not responsible(false) for
   *    freeing memory.
   * @return ACE_String_Base containing const ACE_CHAR_T *s
   */
  ACE_String_Base (const ACE_CHAR_T *s,
                   size_type len,
                   ACE_Allocator *the_allocator = 0,
                   bool release = true);

  /**
   *  Copy constructor.
   *
   *  @param s Input ACE_String_Base string to copy
   *  @return Copy of input string @a s
   */
  ACE_String_Base (const ACE_String_Base < ACE_CHAR_T > &s);

  /**
   *  Constructor that copies @a c into dynamically allocated memory.
   *
   *  @param c Single input character.
   *  @param the_allocator ACE_Allocator associated with string
   *  @return ACE_String_Base containing ACE_CHAR_T 'c'
   */
  ACE_String_Base (ACE_CHAR_T c, ACE_Allocator *the_allocator = 0);

  /**
   *  Constructor that allocates a len long string.
   *
   *  Warning : This constructor was incorrectly documented in the past.
   *  It simply calls resize(len, c).
   *  It is probably not advisable to use the second parameter. See
   *  resize() for more information.
   *
   *  @param len Amount of space to reserve for the string.
   *  @param c The array is filled with c's
   *  @param the_allocator ACE_Allocator associated with string
   *  @return Empty ACE_String_Base with room for len CHARs
   */
  ACE_String_Base (size_type len,
                   ACE_CHAR_T c = 0,
                   ACE_Allocator *the_allocator = 0);

  /**
   *  Deletes the memory...
   */
  ~ACE_String_Base (void);

  /**
   * Return the <slot'th> character in the string (doesn't perform
   * bounds checking).
   *
   * @param slot Index of the desired character
   * @return The character at index @a slot
   */
  const ACE_CHAR_T & operator[] (size_type slot) const;

  /**
   * Return the <slot'th> character by reference in the string
   * (doesn't perform bounds checking).
   *
   * @param slot Index of the desired character
   * @return The character at index @a slot
   */
  ACE_CHAR_T & operator[] (size_type slot);

  /**
   *  Assignment operator (does copy memory).
   *
   *  @param s Input null-terminated ACE_CHAR_T string to assign to this object.
   *  @return Return a copy of the this string.
   */
  ACE_String_Base < ACE_CHAR_T > &operator = (const ACE_CHAR_T * s);

  /**
   *  Assignment operator (does copy memory).
   *
   *  @param s Input ACE_String_Base string to assign to this object.
   *  @return Return a copy of the this string.
   */
  ACE_String_Base < ACE_CHAR_T > &operator = (const ACE_String_Base < ACE_CHAR_T > &s);

  /**
   *  Assignment alternative method (does not copy memory).
   *
   *  @param s Input ACE_String_Base string to assign to this object.
   *  @return Return this string.
   */
  ACE_String_Base < ACE_CHAR_T > &assign_nocopy (const ACE_String_Base < ACE_CHAR_T > &s);

  /**
   * Copy @a s into this @a ACE_String_Base.
   *
   * If release == true then a new buffer is allocated internally if the
   *   existing one is not big enough to hold s. If the existing
   *   buffer is big enough, then it will be used. This means that
   *   set(*, 1) can be illegal when the string is constructed with a
   *   const char*. (e.g. ACE_String_Base("test", 0, false)).
   *
   * if release == false then the s buffer is used directly, and any
   *   existing buffer is destroyed. If s == 0 then it will _not_ be
   *   used, and instead the internal buffer is set to NULL_String_.
   *
   * @param s Null terminated input string
   * @param release Allocator responsible(true)/not responsible(false) for
   *    freeing memory.
   */
  void set (const ACE_CHAR_T * s, bool release = true);

  /**
   *  Copy @a len bytes of @a s (will zero terminate the result).
   *
   * If release == true then a new buffer is allocated internally if the
   *   existing one is not big enough to hold s. If the existing
   *   buffer is big enough, then it will be used. This means that
   *   set(*, *, 1) is illegal when the string is constructed with a
   *   non-owned const char*. (e.g. ACE_String_Base("test", 0, 0))
   *
   * If release == false then the s buffer is used directly, and any
   *   existing buffer is destroyed. If s == 0 then it will _not_ be
   *   used, and instead the internal buffer is set to NULL_String_.
   *
   *  @param s Non-zero terminated input string
   *  @param len Length of input string 's'
   *  @param release Allocator responsible(true)/not responsible(false) for
   *    freeing memory.
   */
  void set (const ACE_CHAR_T * s, size_type len, bool release);

  /**
   * Clear this string. Memory is _not_ freed if @a release is false.
   *
   * Warning: This method was incorrectly documented in the past, but
   * the current implementation has been changed to match the documented
   * behavior.
   *
   * Warning: clear(false) behaves like fast_clear() below.
   *
   * @param release Memory is freed if true, and not freed if false.
   */
  void clear (bool release = false);

  /**
   * A more specialized version of clear(): "fast clear". fast_clear()
   * resets the string to 0 length. If the string owns the buffer
   * (@arg release_== true):
   *  - the string buffer is not freed
   *  - the first character of the buffer is set to 0.
   *
   * If @arg release_ is false (this object does not own the buffer):
   *  - the buffer pointer is reset to the NULL_String_ and does not
   *    maintain a pointer to the caller-supplied buffer on return
   *  - the maximum string length is reset to 0.
   *
   * Warning : Calling clear(false) or fast_clear() can have unintended
   *   side-effects if the string was constructed (or set()) with an
   *   external buffer. The string will be disassociated with the buffer
   *   and the next append() or +=() will cause a new buffer to be
   *   allocated internally.
   */
  void fast_clear (void);

  /**
   * Return a substring given an offset and length.
   * If length == @c npos use rest of str.  Return empty substring if
   * offset or offset/length are invalid.
   *
   * @param offset Index of first desired character of the substring.
   * @param length How many characters to return starting at the offset.
   * @return The string containing the desired substring
   */
  ACE_String_Base < ACE_CHAR_T > substring (size_type offset,
                                      size_type length = npos) const;

  /**
   *  Same as <substring>.
   *
   * @param offset Index of first desired character of the substring.
   * @param length How many characters to return starting at the offset.
   * @return The string containing the desired substring
   */
  ACE_String_Base < ACE_CHAR_T > substr (size_type offset,
                                   size_type length = npos) const;

  /**
   *  Concat operator (copies memory).
   *
   *  @param s Input ACE_String_Base string to concatenate to this string.
   *  @return The combined string (input append to the end of the old). New
   *    string is zero terminated.
   */
  ACE_String_Base < ACE_CHAR_T > &operator += (const ACE_String_Base < ACE_CHAR_T > &s);

  /**
   *  Concat operator (copies memory).
   *
   *  @param s Input C string to concatenate to this string.
   *  @return The combined string (input append to the end of the old). New
   *    string is zero terminated.
   */
  ACE_String_Base < ACE_CHAR_T >& operator += (const ACE_CHAR_T* s);

  /**
   *  Concat operator (copies memory).
   *
   *  @param c Input ACE_CHAR_T to concatenate to this string.
   *  @return The combined string (input append to the end of the old). New
   *    string is zero terminated.
   */
  ACE_String_Base < ACE_CHAR_T >& operator += (const ACE_CHAR_T c);

  /**
   *  Append function (copies memory).
   *
   *  @param s Input ACE_CHAR_T array to concatenate to this string.
   *  @param slen The length of the array.
   *  @return The combined string (input append to the end of the old). New
   *    string is zero terminated.
   */
  ACE_String_Base < ACE_CHAR_T >& append (const ACE_CHAR_T* s, size_type slen);

  /**
   *  Returns a hash value for this string.
   *
   *  @return Hash value of string
   */
  u_long hash (void) const;

  /**
   *  Return the length of the string.
   *
   *  @return Length of stored string
   */
  size_type length (void) const;

  /**
   *  Return the number of allocated CHARs in the string object.
   *  This may be greater than the current length of the string.
   *
   *  @return Maximum number of ACE_CHAR_T units that can be stored, including
   *          any terminating nul that may be needed.
   */
  size_t capacity (void) const;

  /**
   * Return @c true if the length of the string is zero, else @c false.
   */
  bool is_empty (void) const;

  /**
   * Return @c true if the length of the string is zero, else @c
   * false.  We recommend using @c is_empty() instead since it's more
   * consistent with the ACE container naming conventions.
   */
  bool empty (void) const;

  /**
   * Get a copy of the underlying representation.
   *
   * This method allocates memory for a copy of the string and returns
   * a pointer to the new area. The caller is responsible for freeing
   * the memory when finished; use delete []
   *
   * @return Pointer reference to the string data. Returned string is
   *    zero terminated.
   */
  ACE_CHAR_T *rep (void) const;

  /**
   * Get at the underlying representation directly!
   * _Don't_ even think about casting the result to (char *) and modifying it,
   * if it has length 0!
   *
   * @return Pointer reference to the stored string data. No guarantee is
   *    that the string is zero terminated.
   *
   */
  const ACE_CHAR_T *fast_rep (void) const;

  /**
   *  Same as STL String's c_str() and fast_rep().
   */
  const ACE_CHAR_T *c_str (void) const;

  /**
   *  Comparison operator that will match substrings.  Returns the
   *  slot of the first location that matches, else @c npos.
   *
   *  @param s Input ACE_String_Base string
   *  @return Integer index value of the first location of string @a s or
   *          @c npos (not found).
   */
  size_type strstr (const ACE_String_Base<ACE_CHAR_T> &s) const;

  /**
   *  Find @a str starting at pos.  Returns the slot of the first
   *  location that matches (will be >= pos), else @c npos.
   *
   *  @param str Input ACE_String_Base string to search for in stored string.
   *  @param pos Starting index position to start searching for string @a str.
   *  @return Index value of the first location of string @a str else
   *          @c npos.
   */
  size_type find (const ACE_String_Base<ACE_CHAR_T> &str, size_type pos = 0) const;

  /**
   *  Find @a s starting at @a pos.  Returns the slot of the first
   *  location that matches (will be >= pos), else @c npos.
   *
   *  @param s non-zero input string to search for in stored string.
   *  @param pos Starting index position to start searching for string @a str.
   *  @return Index value of the first location of string @a str else
   *          @c npos.
   */
  size_type find (const ACE_CHAR_T *s, size_type pos = 0) const;

  /**
   *  Find @a c starting at @a pos.  Returns the slot of the first
   *  location that matches (will be >= pos), else @c npos.
   *
   *  @param c Input character to search for in stored string.
   *  @param pos Starting index position to start searching for string @a str.
   *  @return Index value of the first location of string @a str else
   *          @c npos.
   */
  size_type find (ACE_CHAR_T c, size_type pos = 0) const;

  /**
   *  Find @a c starting at @a pos (counting from the end).  Returns the
   *  slot of the first location that matches, else @c npos.
   *
   *  @param c Input character to search for in stored string.
   *  @param pos Starting index position to start searching for string @a str.
   *  @return Index value of the first location of string @a str else
   *          @c npos.
   */
  size_type rfind (ACE_CHAR_T c, size_type pos = npos) const;

  /**
   *  Equality comparison operator (must match entire string).
   *
   * @param s Input ACE_String_Base string to compare against stored string.
   * @return @c true if equal, @c false otherwise.
   */
  bool operator == (const ACE_String_Base<ACE_CHAR_T> &s) const;

  /**
   *  Equality comparison operator (must match entire string).
   *
   * @param s Null terminated string to compare against stored string.
   * @return @c true if equal, @c false otherwise.
   */
  bool operator == (const ACE_CHAR_T *s) const;

  /**
   *  Less than comparison operator.
   *
   *  @param s Input ACE_String_Base string to compare against stored string.
   *  @return @c true if less than, @c false otherwise.
   */
  bool operator < (const ACE_String_Base<ACE_CHAR_T> &s) const;

  /**
   *  Greater than comparison operator.
   *
   *  @param s Input ACE_String_Base string to compare against stored string.
   *  @return @c true if greater than, @c false otherwise.
   */
  bool operator > (const ACE_String_Base<ACE_CHAR_T> &s) const;

  /**
   *  Inequality comparison operator.
   *
   *  @param s String to compare against stored string.
   *  @return @c true if not equal, @c false otherwise.
   */
  bool operator != (const ACE_String_Base<ACE_CHAR_T> &s) const;

  /**
   *  Inequality comparison operator.
   *
   *  @param s Null terminated string to compare against stored string.
   *  @return @c true if not equal, @c false otherwise.
   */
  bool operator != (const ACE_CHAR_T *s) const;

  /**
   *  Performs a strncmp comparison.
   *
   *  @param s Input ACE_String_Base string to compare against stored string.
   *  @return Integer value of result (less than 0, 0, greater than 0)
   *    depending on how input string @a s is to the stored string.
   */
  int compare (const ACE_String_Base<ACE_CHAR_T> &s) const;

  /**
   *  Dump the state of an object.
   */
  void dump (void) const;

  /**
   * This method is designed for high-performance. Please use with
   * care ;-)
   *
   * Warning : This method was documented incorrectly in the past.
   * The original intention was to change the length of the string to
   * len, and to fill the whole thing with c CHARs.
   * However, what was actually done was to set the length of the
   * string to zero, and fill the buffer with c's. The buffer was
   * also not null-terminated unless c happened to be zero.
   * Rather than fix the method to work as documented, the code is
   * left as is, but the second parameter should probably not be used.
   *
   * fast_resize just adjusts the buffer if needed and sets the length,
   * it doesn't fill the buffer, so is much faster.
   *
   * @param len The number of CHARs to reserve
   * @param c The ACE_CHAR_T to use when filling the string.
   */
  void resize (size_type len, ACE_CHAR_T c = 0);
  void fast_resize (size_t len);

  /// Swap the contents of this @c ACE_String_Base with @a str.
  /**
   * @note This is non-throwing operation.
   */
  void swap (ACE_String_Base<ACE_CHAR_T> & str);

  iterator begin (void);
  const_iterator begin (void) const;

  iterator end (void);
  const_iterator end (void) const;

  /**
   *  Declare the dynamic allocation hooks.
   */
  ACE_ALLOC_HOOK_DECLARE;

protected:
  /**
   *  Pointer to a memory allocator.
   */
  ACE_Allocator *allocator_;

  /**
   *  Length of the ACE_String_Base data (not counting the trailing '\0').
   */
  size_type len_;

  /**
   *  Length of the ACE_String_Base data buffer.  Keeping track of the
   *  length allows to avoid unnecessary dynamic allocations.
   */
  size_type buf_len_;

  /**
   *  Pointer to data.
   */
  ACE_CHAR_T *rep_;

  /**
   *  Flag that indicates if we own the memory
   */
  bool release_;

  /**
   *  Represents the "NULL" string to simplify the internal logic.
   */
  static ACE_CHAR_T NULL_String_;
};

/**
 * @class ACE_String_Base_Iterator
 *
 * @brief Iterator class for the ACE_String_Base class.
 *
 * This class is an implementation of an iterator that allows client
 * applications it iterator over the contents of a string. Currently,
 * now this iterator fall under the std::bidirectional_iterator_tag
 * category. Future versions of the class will support the operations
 * of std::random_access_iterator_tag.
 */
template <class ACE_CHAR_T>
class ACE_String_Base_Iterator
{
public:
  // = std::iterator_traits typedefs/traits.
  typedef std::bidirectional_iterator_tag iterator_category;
  typedef ACE_CHAR_T                            value_type;
  typedef ACE_CHAR_T &                          reference;
  typedef ACE_CHAR_T *                          pointer;
  typedef ptrdiff_t                       difference_type;

  /**
   * Initializing constructor
   *
   * @param[in]       str         Target string for iterator.
   */
  ACE_String_Base_Iterator (ACE_String_Base <ACE_CHAR_T> & str, int end = 0);

  /**
   * Copy constructor
   *
   * @param[in]       iter        Iterator to copy.
   */
  ACE_String_Base_Iterator (const ACE_String_Base_Iterator <ACE_CHAR_T> & iter);

  /// Destructor.
  ~ACE_String_Base_Iterator (void);

  /**
   * Test if the iterator has seen all characters.
   *
   * @retval          0         Characters still remain.
   * @retval          1         All characters have been seen.
   */
  int done (void) const;

  /**
   * Get the current character.
   *
   * @param[out]     ch         The current character.
   * @retval         0          All characters have been seen.
   * @retval         1          Items still remain to be seen.
   */
  int next (ACE_CHAR_T * & ch) const;

  /**
   * Move to the next character in the string.
   *
   * @retval         0          All characters have been seen.
   * @retval         1          Items still remain to be seen.
   */
  int advance (void);

  /**
   * Assignment operator
   *
   * @param[in]       iter      Right-hand side of operator.
   * @return          Reference to self.
   */
  const ACE_String_Base_Iterator <ACE_CHAR_T> & operator = (const ACE_String_Base_Iterator <ACE_CHAR_T> & iter);

  /**
   * Dereference operator
   *
   * @return          Reference to current character seen by iterator.
   */
  ACE_CHAR_T & operator * (void);

  /**
   * Prefix operator
   */
  ACE_String_Base_Iterator <ACE_CHAR_T> & operator ++ (void);

  /**
   * Postfix operator
   */
  ACE_String_Base_Iterator <ACE_CHAR_T> operator ++ (int);

  /**
   * Prefix operator
   */
  ACE_String_Base_Iterator <ACE_CHAR_T> & operator -- (void);

  /**
   * Postfix operator
   */
  ACE_String_Base_Iterator <ACE_CHAR_T> operator -- (int);

  /**
   * Eqaulity comparison operator
   *
   * @param[in]       rhs       Right-hand side of operator.
   */
  bool operator == (const ACE_String_Base_Iterator <ACE_CHAR_T> & rhs) const;

  /**
   * Ineqaulity comparison operator
   *
   * @param[in]       rhs       Right-hand side of operator.
   */
  bool operator != (const ACE_String_Base_Iterator <ACE_CHAR_T> & rhs) const;

  bool operator < (const ACE_String_Base_Iterator <ACE_CHAR_T> & rhs) const;
  bool operator > (const ACE_String_Base_Iterator <ACE_CHAR_T> & rhs) const;

  bool operator <= (const ACE_String_Base_Iterator <ACE_CHAR_T> & rhs) const;
  bool operator >= (const ACE_String_Base_Iterator <ACE_CHAR_T> & rhs) const;

private:
  /// Target string to iterate over.
  ACE_String_Base <ACE_CHAR_T> * str_;

  /// Current location in the string.
  size_t index_;
};

/**
 * @class ACE_String_Base_Const_Iterator
 *
 * @brief Const iterator class for the ACE_String_Base class.
 *
 * This class is an implementation of an iterator that allows client
 * applications it iterator over the contents of a string. Currently,
 * now this iterator fall under the std::bidirectional_iterator_tag
 * category. Future versions of the class will support the operations
 * of std::random_access_iterator_tag.
 */
template <class ACE_CHAR_T>
class ACE_String_Base_Const_Iterator
{
public:
  // = std::iterator_traits typedefs/traits.
  typedef std::bidirectional_iterator_tag iterator_category;
  typedef const ACE_CHAR_T                      value_type;
  typedef const ACE_CHAR_T &                    reference;
  typedef const ACE_CHAR_T *                    pointer;
  typedef ptrdiff_t                       difference_type;

  /**
   * Initializing constructor
   *
   * @param[in]       str         Target string for iterator.
   */
  ACE_String_Base_Const_Iterator (const ACE_String_Base <ACE_CHAR_T> & str, int end = 0);

  /**
   * Copy constructor
   *
   * @param[in]       iter        Iterator to copy.
   */
  ACE_String_Base_Const_Iterator (const ACE_String_Base_Const_Iterator <ACE_CHAR_T> & iter);

  /// Destructor.
  ~ACE_String_Base_Const_Iterator (void);

  /**
   * Test if the iterator has seen all characters.
   *
   * @retval          0         Characters still remain.
   * @retval          1         All characters have been seen.
   */
  int done (void) const;

  /**
   * Get the current character.
   *
   * @param[out]     ch         The current character.
   * @retval         0          All characters have been seen.
   * @retval         1          Items still remain to be seen.
   */
  int next (const ACE_CHAR_T * & ch) const;

  /**
   * Move to the next character in the string.
   *
   * @retval         0          All characters have been seen.
   * @retval         1          Items still remain to be seen.
   */
  int advance (void);

  /**
   * Assignment operator
   *
   * @param[in]       iter      Right-hand side of operator.
   * @return          Reference to self.
   */
  const ACE_String_Base_Const_Iterator <ACE_CHAR_T> & operator = (const ACE_String_Base_Const_Iterator <ACE_CHAR_T> & iter);

  /**
   * Dereference operator
   *
   * @return          Reference to current character seen by iterator.
   */
  const ACE_CHAR_T & operator * (void);

  /**
   * Prefix operator
   */
  ACE_String_Base_Const_Iterator <ACE_CHAR_T> & operator ++ (void);

  /**
   * Postfix operator
   */
  ACE_String_Base_Const_Iterator <ACE_CHAR_T> operator ++ (int);

  /**
   * Prefix operator
   */
  ACE_String_Base_Const_Iterator <ACE_CHAR_T> & operator -- (void);

  /**
   * Postfix operator
   */
  ACE_String_Base_Const_Iterator <ACE_CHAR_T> operator -- (int);

  /**
   * Eqaulity comparison operator
   *
   * @param[in]       rhs       Right-hand side of operator.
   */
  bool operator == (const ACE_String_Base_Const_Iterator <ACE_CHAR_T> & rhs) const;

  /**
   * Ineqaulity comparison operator
   *
   * @param[in]       rhs       Right-hand side of operator.
   */
  bool operator != (const ACE_String_Base_Const_Iterator <ACE_CHAR_T> & rhs) const;

  bool operator < (const ACE_String_Base_Const_Iterator <ACE_CHAR_T> & rhs) const;
  bool operator > (const ACE_String_Base_Const_Iterator <ACE_CHAR_T> & rhs) const;

  bool operator <= (const ACE_String_Base_Const_Iterator <ACE_CHAR_T> & rhs) const;
  bool operator >= (const ACE_String_Base_Const_Iterator <ACE_CHAR_T> & rhs) const;

private:
  /// Target string to iterate over.
  const ACE_String_Base <ACE_CHAR_T> * str_;

  /// Current location in the string.
  size_t index_;
};

template < class ACE_CHAR_T >
  ACE_String_Base < ACE_CHAR_T > operator + (const ACE_String_Base < ACE_CHAR_T > &,
                                       const ACE_String_Base < ACE_CHAR_T > &);
template < class ACE_CHAR_T >
  ACE_String_Base < ACE_CHAR_T > operator + (const ACE_String_Base < ACE_CHAR_T > &,
                                       const ACE_CHAR_T *);
template < class ACE_CHAR_T >
  ACE_String_Base < ACE_CHAR_T > operator + (const ACE_CHAR_T *,
                                       const ACE_String_Base < ACE_CHAR_T > &);

template < class ACE_CHAR_T >
  ACE_String_Base < ACE_CHAR_T > operator + (const ACE_String_Base < ACE_CHAR_T > &t,
                                       const ACE_CHAR_T c);

template < class ACE_CHAR_T >
  ACE_String_Base < ACE_CHAR_T > operator + (const ACE_CHAR_T c,
                                       const ACE_String_Base < ACE_CHAR_T > &t);

template <class ACE_CHAR_T>
  bool operator == (const ACE_CHAR_T *s,
                    const ACE_String_Base<ACE_CHAR_T> &t);

template <class ACE_CHAR_T>
  bool operator != (const ACE_CHAR_T *s,
                    const ACE_String_Base<ACE_CHAR_T> &t);

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ace/String_Base.inl"
#endif /* __ACE_INLINE__ */

#if defined (ACE_TEMPLATES_REQUIRE_SOURCE)
#include "ace/String_Base.cpp"
#endif /* ACE_TEMPLATES_REQUIRE_SOURCE */

#if defined (ACE_TEMPLATES_REQUIRE_PRAGMA)
#pragma implementation ("String_Base.cpp")
#endif /* ACE_TEMPLATES_REQUIRE_PRAGMA */

#include /**/ "ace/post.h"

#endif /* ACE_STRING_BASE_H */
