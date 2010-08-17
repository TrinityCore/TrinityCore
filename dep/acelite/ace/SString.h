// -*- C++ -*-

//=============================================================================
/**
 *  @file    SString.h
 *
 *  $Id: SString.h 91058 2010-07-12 08:20:09Z johnnyw $
 *
 *  @author Douglas C. Schmidt (schmidt@cs.wustl.edu)
 */
//=============================================================================

#ifndef ACE_SSTRING_H
#define ACE_SSTRING_H
#include /**/ "ace/pre.h"

#include "ace/SStringfwd.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/String_Base.h"

#if !defined (ACE_DEFAULT_GROWSIZE)
#define ACE_DEFAULT_GROWSIZE 32
#endif /* ACE_DEFAULT_GROWSIZE */

#if !defined (ACE_LACKS_IOSTREAM_TOTALLY)
#include "ace/iosfwd.h"
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
ACE_Export ACE_OSTREAM_TYPE &operator << (ACE_OSTREAM_TYPE &, const ACE_CString &);
ACE_Export ACE_OSTREAM_TYPE &operator << (ACE_OSTREAM_TYPE &, const ACE_WString &);
ACE_END_VERSIONED_NAMESPACE_DECL
#endif /* ! ACE_LACKS_IOSTREAM_TOTALLY */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

#if defined ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION_EXPORT
template class ACE_Export ACE_String_Base<char>;
template class ACE_Export ACE_String_Base<ACE_WSTRING_TYPE>;

template class ACE_Export ACE_String_Base_Iterator<char>;
template class ACE_Export ACE_String_Base_Iterator<ACE_WSTRING_TYPE>;

template class ACE_Export ACE_String_Base_Const_Iterator<char>;
template class ACE_Export ACE_String_Base_Const_Iterator<ACE_WSTRING_TYPE>;
#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION_EXPORT */

/**
 * @class ACE_NS_WString
 *
 * @brief This class retain the backward compatibility for
 *        ACE_Naming_Context and related classes.  The only addition to
 *        ACE_WString is a very naive "wchar" to "char" conversion
 *        function.
 */
class ACE_Export ACE_NS_WString : public ACE_WString
{
public:

  using ACE_WString::size_type;

  /// Default constructor.
  ACE_NS_WString (ACE_Allocator *alloc = 0);

  /// Constructor that copies @a s into dynamically allocated memory.
  ACE_NS_WString (const char *s,
                  ACE_Allocator *alloc = 0);

  /// Constructor that copies @a s into dynamically allocated memory.
  ACE_NS_WString (const ACE_WSTRING_TYPE *s,
                  ACE_Allocator *alloc = 0);

#if defined (ACE_WSTRING_HAS_USHORT_SUPPORT)
  /// Constructor that takes in a ushort16 string (mainly used by the
  /// ACE Name_Space classes)
  ACE_NS_WString (const ACE_USHORT16 *s,
                  size_type len,
                  ACE_Allocator *alloc = 0);
#endif /* ACE_WSTRING_HAS_USHORT_SUPPORT */

  /// Constructor that copies @a len ACE_WSTRING_TYPE's of @a s into dynamically
  /// allocated memory (will NUL terminate the result).
  ACE_NS_WString (const ACE_WSTRING_TYPE *s,
                  size_type len,
                  ACE_Allocator *alloc = 0);

  /// Constructor that dynamically allocates memory for @a len + 1
  /// ACE_WSTRING_TYPE characters. The newly created memory is set memset to 0.
  ACE_NS_WString (size_type len, ACE_Allocator *alloc = 0);

  /// Copy constructor.
  ACE_NS_WString (const ACE_NS_WString &s);

  /// Constructor that copies @a c into dynamically allocated memory.
  ACE_NS_WString (ACE_WSTRING_TYPE c, ACE_Allocator *alloc = 0);

  /// Transform into a copy of the ASCII character representation.
  /// (caller must delete)
  char *char_rep (void) const;

  /// Transform into a copy of a USHORT16 representation (caller must
  /// delete).  Note, behavior is undefined when sizeof (wchar_t) != 2.
  ACE_USHORT16 *ushort_rep (void) const;
};

ACE_Export
ACE_NS_WString operator + (const ACE_NS_WString &,
                           const ACE_NS_WString &);

// -----------------------------------------------------------------

/**
 * @class ACE_SString
 *
 * @brief A very Simple String ACE_SString class.  This is not a
 * general-purpose string class, and you should probably consider
 * using ACE_CString is you don't understand why this class
 * exists...
 *
 * This class is optimized for efficiency, so it doesn't provide
 * any internal locking.
 * CAUTION: This class is only intended for use with applications
 * that understand how it works.  In particular, its destructor
 * does not deallocate its memory when it is destroyed...  We need
 * this class since the ACE_Map_Manager requires an object that
 * supports the operator == and operator !=.  This class uses an
 * ACE_Allocator to allocate memory.  The user can make this a
 * persistant class by providing an ACE_Allocator with a
 * persistable memory pool.
 */
class ACE_Export ACE_SString
{
public:

  typedef ACE_Allocator::size_type size_type;

  /// No position constant
  static const size_type npos;

  /// Default constructor.
  ACE_SString (ACE_Allocator *alloc = 0);

  /// Constructor that copies @a s into dynamically allocated memory.
  ACE_SString (const char *s, ACE_Allocator *alloc = 0);

  /// Constructor that copies @a len chars of @a s into dynamically
  /// allocated memory (will NUL terminate the result).
  ACE_SString (const char *s, size_type len, ACE_Allocator *alloc = 0);

  /// Copy constructor.
  ACE_SString (const ACE_SString &);

  /// Constructor that copies @a c into dynamically allocated memory.
  ACE_SString (char c, ACE_Allocator *alloc = 0);

  /// Default destructor.
  ~ACE_SString (void);

  /// Return the <slot'th> character in the string (doesn't perform
  /// bounds checking).
  char operator [] (size_type slot) const;

  /// Return the <slot'th> character by reference in the string
  /// (doesn't perform bounds checking).
  char &operator [] (size_type slot);

  /// Assignment operator (does copy memory).
  ACE_SString &operator = (const ACE_SString &);

  /**
   * Return a substring given an offset and length, if length == npos
   * use rest of str return empty substring if offset or offset/length
   * are invalid
   */
  ACE_SString substring (size_type offset, size_type length = npos) const;

  /// Same as substring
  ACE_SString substr (size_type offset, size_type length = npos) const;

  /// Returns a hash value for this string.
  u_long hash (void) const;

  /// Return the length of the string.
  size_type length (void) const;

  /// Set the underlying pointer.  Since this does not copy memory or
  /// delete existing memory use with extreme caution!!!
  void rep (char *s);

  /// Get the underlying pointer.
  const char *rep (void) const;

  /// Get the underlying pointer.
  const char *fast_rep (void) const;

  /// Same as STL String's c_str() and fast_rep().
  const char *c_str (void) const;

  /// Comparison operator that will match substrings.  Returns the
  /// slot of the first location that matches, else @c npos.
  size_type strstr (const ACE_SString &s) const;

  /// Find @a str starting at pos.  Returns the slot of the first
  /// location that matches (will be >= pos), else npos.
  size_type find (const ACE_SString &str, size_type pos = 0) const;

  /// Find <s> starting at pos.  Returns the slot of the first
  /// location that matches (will be >= pos), else npos.
  size_type find (const char *s, size_type pos = 0) const;

  /// Find @a c starting at pos.  Returns the slot of the first
  /// location that matches (will be >= pos), else npos.
  size_type find (char c, size_type pos = 0) const;

  /// Find @a c starting at pos (counting from the end).  Returns the
  /// slot of the first location that matches, else npos.
  size_type rfind (char c, size_type pos = npos) const;

  /// Equality comparison operator (must match entire string).
  bool operator == (const ACE_SString &s) const;

  /// Less than comparison operator.
  bool operator < (const ACE_SString &s) const;

  /// Greater than comparison operator.
  bool operator > (const ACE_SString &s) const;

  /// Inequality comparison operator.
  bool operator != (const ACE_SString &s) const;

  /// Performs a strcmp()-style comparison.
  int compare (const ACE_SString &s) const;

  /// Dump the state of an object.
  void dump (void) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

private:
  /// Pointer to a memory allocator.
  ACE_Allocator *allocator_;

  /// Length of the ACE_SString (not counting the trailing '\\0').
  size_type len_;

  /// Pointer to data.
  char *rep_;
};

#if !defined (ACE_LACKS_IOSTREAM_TOTALLY)
ACE_Export ACE_OSTREAM_TYPE &operator << (ACE_OSTREAM_TYPE &, const ACE_SString &);
#endif /* ! ACE_LACKS_IOSTREAM_TOTALLY */

// This allows one to use W or C String based on the Unicode
// setting
#if defined (ACE_USES_WCHAR)
typedef ACE_WString ACE_TString;
#else /* ACE_USES_WCHAR */
typedef ACE_CString ACE_TString;
#endif /* ACE_USES_WCHAR */

// ****************************************************************

/**
 * @class ACE_Auto_String_Free
 *
 * @brief Simple class to automatically de-allocate strings
 *
 * Keeps a pointer to a string and deallocates it (using
 * <ACE_OS::free>) on its destructor.
 * If you need to delete using "delete[]" the
 * ACE_Auto_Array_Ptr<char> is your choice.
 * The class plays the same role as auto_ptr<>
 */
class ACE_Export ACE_Auto_String_Free
{
public:
  explicit ACE_Auto_String_Free (char* p = 0);
  ACE_Auto_String_Free (ACE_Auto_String_Free &rhs);
  ACE_Auto_String_Free& operator= (ACE_Auto_String_Free &rhs);
  ~ACE_Auto_String_Free (void);

  char* operator* () const;
  char operator[] (size_t i) const;
  char* get (void) const;
  char* release (void);
  void reset (char* p = 0);

private:
  char* p_;
};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ace/SString.inl"
#endif /* __ACE_INLINE__ */

#include /**/ "ace/post.h"
#endif /* ACE_SSTRING_H */
