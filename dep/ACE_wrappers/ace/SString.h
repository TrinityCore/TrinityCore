// -*- C++ -*-

//=============================================================================
/**
 *  @file    SString.h
 *
 *  $Id: SString.h 80826 2008-03-04 14:51:23Z wotte $
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

  /// Constructor that copies @a len chars of  @s  into dynamically
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

  /// Same as STL String's <c_str> and <fast_rep>.
  const char *c_str (void) const;

  /// Comparison operator that will match substrings.  Returns the
  /// slot of the first location that matches, else @c npos.
  size_type strstr (const ACE_SString &s) const;

  /// Find <str> starting at pos.  Returns the slot of the first
  /// location that matches (will be >= pos), else npos.
  size_type find (const ACE_SString &str, size_type pos = 0) const;

  /// Find <s> starting at pos.  Returns the slot of the first
  /// location that matches (will be >= pos), else npos.
  size_type find (const char *s, size_type pos = 0) const;

  /// Find <c> starting at pos.  Returns the slot of the first
  /// location that matches (will be >= pos), else npos.
  size_type find (char c, size_type pos = 0) const;

  /// Find <c> starting at pos (counting from the end).  Returns the
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

  /// Performs a <strcmp>-style comparison.
  int compare (const ACE_SString &s) const;

  /// Dump the state of an object.
  void dump (void) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

private:
  /// Pointer to a memory allocator.
  ACE_Allocator *allocator_;

  /// Length of the ACE_SString (not counting the trailing '\0').
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


// ************************************************************

/**
 * @class ACE_Tokenizer
 *
 * @brief Tokenizer
 *
 * Tokenizes a buffer.  Allows application to set delimiters and
 * preserve designators.  Does not allow special characters, yet
 * (e.g., printf ("\"like a quoted string\"")).
 */
class ACE_Export ACE_Tokenizer
{
public:
  /**
   * \a buffer will be parsed.  Notice that ACE_Tokenizer will modify
   * \a buffer if you use <code> delimiter_replace </code> or <code>
   * preserve_designators </code> to do character substitution.
   * @note You should NOT pass a constant string or string literal
   * to this constructor, since ACE_Tokenizer will try to modify
   * the string.
   * \sa preserve_designators
   * \sa preserve_designators
   */
  ACE_Tokenizer (ACE_TCHAR *buffer);

  /**
   * \a d is a delimiter.
   * \return Returns 0 on success, -1 if there is no memory left.
   *
   * <B>Example:</B>
   * \verbatim
     char buf[30];
     ACE_OS::strcpy(buf, "William/Joseph/Hagins");

     ACE_Tokenizer tok (buf);
     tok.delimiter ('/');
     for (char *p = tok.next (); p; p = tok.next ())
      cout << p << endl;
    \endverbatim
   *
   * This will print out:
   * \verbatim
     William/Joseph/Hagins
      Joseph/Hagins
      Hagins \endverbatim
   */
  int delimiter (ACE_TCHAR d);

  /**
   * \a d is a delimiter and, when found, will be replaced by
   * \a replacement.
   * \return 0 on success, -1 if there is no memory left.
   *
   * <B>Example:</B>
   * \verbatim
     char buf[30];
     ACE_OS::strcpy(buf, "William/Joseph/Hagins");

     ACE_Tokenizer tok (buf);
     tok.delimiter_replace ('/', 0);
     for (char *p = tok.next (); p; p = tok.next ())
       cout << p << endl;
    \endverbatim
   *
   * This will print out:
   * \verbatim
       William
       Joseph
       Hagins \endverbatim
 */
  int delimiter_replace (ACE_TCHAR d, ACE_TCHAR replacement);

  /**
   * Extract string between a pair of designator characters.
   * For instance, quotes, or '(' and ')'.
   * \a start specifies the begin designator.
   * \a stop specifies the end designator.
   * \a strip If \a strip == 1, then the preserve
   * designators will be stripped from the tokens returned by next.
   * \return 0 on success, -1 if there is no memory left.
   *
   * <B>Example with strip = 0:</B>
   * \verbatim
     char buf[30];
     ACE_OS::strcpy(buf, "William(Joseph)Hagins");

     ACE_Tokenizer tok (buf);
     tok.preserve_designators ('(', ')', 0);
     for (char *p = tok.next (); p; p = tok.next ())
       cout << p << endl;
    \endverbatim
   *
   * This will print out:
   * \verbatim
      William(Joseph)Hagins
      (Joseph)Hagins
      )Hagins \endverbatim
   *
   * <B>Example with strip = 1:</B>
   * \verbatim
     char buf[30];
     ACE_OS::strcpy(buf, "William(Joseph)Hagins");

     ACE_Tokenizer tok (buf);
     tok.preserve_designators ('(', ')', 1);
     for (char *p = tok.next (); p; p = tok.next ())
       cout << p << endl;
    \endverbatim
   *
   * This will print out:
   * \verbatim
      William
      Joseph
      Hagins \endverbatim
   */
  int preserve_designators (ACE_TCHAR start, ACE_TCHAR stop, int strip=1);

  /// Returns the next token.
  ACE_TCHAR *next (void);

  enum {
    MAX_DELIMITERS=16,
    MAX_PRESERVES=16
  };

protected:
  /// Returns 1 if <d> is a delimiter, 0 otherwise.  If <d> should be
  /// replaced with @a r, <replace> is set to 1, otherwise 0.
  int is_delimiter (ACE_TCHAR d, int &replace, ACE_TCHAR &r);

  /**
   * If <start> is a start preserve designator, returns 1 and sets
   * <stop> to the stop designator.  Returns 0 if <start> is not a
   * preserve designator.
   */
  int is_preserve_designator (ACE_TCHAR start, ACE_TCHAR &stop, int &strip);

  ACE_TCHAR *buffer_;
  int index_;

  /**
   * @class Preserve_Entry
   *
   * @brief Preserve Entry
   *
   * Defines a set of characters that designate an area that
   * should not be parsed, but should be treated as a complete
   * token.  For instance, in: (this is a preserve region), start
   * would be a left paren -(- and stop would be a right paren
   * -)-.  The strip determines whether the designators should be
   * removed from the token.
   */
  class Preserve_Entry
  {
  public:
    /**
     * E.g., "(".
     * E.g., ")".
     * Whether the designators should be removed from the token.
     */
    ACE_TCHAR start_;
    ACE_TCHAR stop_;
    int strip_;
  };

  /// The application can specify MAX_PRESERVES preserve designators.
  Preserve_Entry preserves_[MAX_PRESERVES];

  /// Pointer to the next free spot in preserves_.
  int preserves_index_;

  /**
   * @class Delimiter_Entry
   *
   * @brief Delimiter Entry
   *
   * Describes a delimiter for the tokenizer.
   */
  class Delimiter_Entry
  {
  public:
    /**
     * Most commonly a space ' '.
     * What occurrences of delimiter_ should be replaced with.
     * Whether replacement_ should be used.  This should be replaced
     * with a technique that sets replacement_ = delimiter by
     * default.  I'll do that next iteration.
     */
    ACE_TCHAR delimiter_;
    ACE_TCHAR replacement_;
    int replace_;
  };

  /// The tokenizer allows MAX_DELIMITERS number of delimiters.
  Delimiter_Entry delimiters_[MAX_DELIMITERS];

  /// Pointer to the next free space in delimiters_.
  int delimiter_index_;
};

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
