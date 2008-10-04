// -*- C++ -*-

//=============================================================================
/**
 *  @file    Basic_Types.h
 *
 *  $Id: Basic_Types.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author David L. Levine
 *
 *  #defines the list of preprocessor macros below.  The config.h file can
 *  pre-define any of these to short-cut the definitions.  This is usually
 *  only necessary if the preprocessor does all of its math using integers.
 *
 *  Sizes of built-in types:
 *    - ACE_SIZEOF_CHAR
 *    - ACE_SIZEOF_WCHAR
 *    - ACE_SIZEOF_SHORT
 *    - ACE_SIZEOF_INT
 *    - ACE_SIZEOF_LONG
 *    - ACE_SIZEOF_LONG_LONG
 *    - ACE_SIZEOF_VOID_P
 *    - ACE_SIZEOF_FLOAT
 *    - ACE_SIZEOF_DOUBLE
 *    - ACE_SIZEOF_LONG_DOUBLE
 *
 *  Wrappers for built-in types of specific sizes:
 *    - ACE_USHORT16 (For backward compatibility.  Use ACE_UINT16 instead.)
 *    - ACE_INT8
 *    - ACE_UINT8
 *    - ACE_INT16
 *    - ACE_UINT16
 *    - ACE_INT32
 *    - ACE_UINT32
 *    - ACE_UINT64
 *  (@note ACE_INT64 is partly defined, there is no ACE_LongLong for
 *   platforms that don't have a native 8-byte integer type.)
 *
 *  Byte-order (endian-ness) determination:
 *    ACE_BYTE_ORDER, to either ACE_BIG_ENDIAN or ACE_LITTLE_ENDIAN
 *
 *
 */
//=============================================================================

#include "ace/config-lite.h"

#ifndef ACE_BASIC_TYPES_H
# define ACE_BASIC_TYPES_H

# include /**/ "ace/pre.h"

# if !defined (ACE_LACKS_PRAGMA_ONCE)
#   pragma once
# endif /* ACE_LACKS_PRAGMA_ONCE */

// Pull in definitions
# include "ace/os_include/os_limits.h"     // Integer limits
# include "ace/os_include/os_float.h"      // Floating point limits
# include "ace/os_include/os_stdlib.h"     // Other types
# include "ace/os_include/os_stddef.h"     // Get ptrdiff_t - see further comments below

# if defined(ACE_LACKS_LONGLONG_T)
#   include "ace/os_include/os_stdio.h"  // For long long emulation
# endif  /* ACE_LACKS_LONGLONG_T */

# include "ace/os_include/sys/os_types.h"

# if !defined (ACE_LACKS_SYS_PARAM_H)
#  include /**/ <sys/param.h>
# endif /* ACE_LACKS_SYS_PARAM_H */

# include "ace/ACE_export.h"

# if !defined (ACE_LACKS_STDINT_H)
#  include <stdint.h>
# endif
# if !defined (ACE_LACKS_INTTYPES_H)
#  include <inttypes.h>
# endif

#ifdef ACE_LACKS_INTPTR_T
# include "ace/If_Then_Else.h"

// This intptr_t typedef is here instead of
// <ace/os_include/os_inttypes.h> since it depends on the template
// metaprogramming in <ace/If_Then_Else.h>.

// We could compare ACE_SIZEOF_VOID_P against ACE_SIZEOF_LONG, etc.
// However, that depends on the ACE preprocessor symbol definitions in
// the platform-specific configuration header being correct.
// The template meta-programming approach we take below,
// i.e. determining the type at compile-time rather than at
// preprocessing-time, will work for all platforms, and does not
// depend on ACE developer-defined configuration parameters.

typedef ACE::If_Then_Else<
  (sizeof (void*) == sizeof (signed int)),
  signed int,
  ACE::If_Then_Else<
    (sizeof (void*) == sizeof (signed long)),
    signed long,
#ifdef ACE_LACKS_LONGLONG_T
    void  /* Unknown. Force an invalid type */
#else
    ACE::If_Then_Else<
      (sizeof (void*) == sizeof (signed long long)),
      signed long long,
      void /* Unknown. Force an invalid type */
      >::result_type
#endif  /* ACE_LACKS_LONGLONG_T */
    >::result_type
  >::result_type intptr_t;

typedef ACE::If_Then_Else<
  (sizeof (void*) == sizeof (unsigned int)),
  unsigned int,
  ACE::If_Then_Else<
    (sizeof (void*) == sizeof (unsigned long)),
    unsigned long,
#ifdef ACE_LACKS_UNSIGNEDLONGLONG_T
    void  /* Unknown. Force an invalid type */
#else
    ACE::If_Then_Else<
      (sizeof (void*) == sizeof (unsigned long long)),
      unsigned long long,
      void /* Unknown. Force an invalid type */
      >::result_type
#endif  /* ACE_LACKS_UNSIGNEDLONGLONG_T */
    >::result_type
  >::result_type uintptr_t;

#endif  /* ACE_LACKS_INTPTR_T */

// A char always has 1 byte, by definition.
# define ACE_SIZEOF_CHAR 1

// Unfortunately, there isn't a portable way to determine the size of a wchar.
// So we just define them on a platform basis. If the platform doesn't
// define it and it's an XPG4 system, assume wchar_t is 4 bytes. Some code
// uses ACE_SIZEOF_WCHAR in preprocessor statements, so sizeof() isn't valid.
// If the platform config doesn't set this, and this guess is wrong,
// Basic_Types_Test should catch the inconsistency.
# if defined (ACE_HAS_WCHAR)
#   if !defined (ACE_SIZEOF_WCHAR)
#     if defined (ACE_HAS_XPG4_MULTIBYTE_CHAR)
#       define ACE_SIZEOF_WCHAR 4
#     else
// 0 so the Basic_Types test will catch this.
#       define ACE_SIZEOF_WCHAR 0
#     endif /* ACE_HAS_XPG4_MULTIBYTE_CHAR */
#   endif /* !ACE_SIZEOF_WCHAR */
# endif /* ACE_HAS_WCHAR */

// The number of bytes in a short.
# if !defined (ACE_SIZEOF_SHORT)
#   if (USHRT_MAX) == 255U
#     define ACE_SIZEOF_SHORT 1
#   elif (USHRT_MAX) == 65535U
#     define ACE_SIZEOF_SHORT 2
#   elif (USHRT_MAX) == 4294967295U
#     define ACE_SIZEOF_SHORT 4
#   elif (USHRT_MAX) == 18446744073709551615U
#     define ACE_SIZEOF_SHORT 8
#   else
#     error: unsupported short size, must be updated for this platform!
#   endif /* USHRT_MAX */
# endif /* !defined (ACE_SIZEOF_SHORT) */

// The number of bytes in an int.
# if !defined (ACE_SIZEOF_INT)
#   if (UINT_MAX) == 65535U
#     define ACE_SIZEOF_INT 2
#   elif (UINT_MAX) == 4294967295U
#     define ACE_SIZEOF_INT 4
#   elif (UINT_MAX) == 18446744073709551615U
#     define ACE_SIZEOF_INT 8
#   else
#     error: unsupported int size, must be updated for this platform!
#   endif /* UINT_MAX */
# endif /* !defined (ACE_SIZEOF_INT) */

// The number of bytes in a long.
# if !defined (ACE_SIZEOF_LONG)
#   if (ULONG_MAX) == 65535UL
#     define ACE_SIZEOF_LONG 2
#   elif ((ULONG_MAX) == 4294967295UL)
#     define ACE_SIZEOF_LONG 4
#   elif ((ULONG_MAX) == 18446744073709551615UL)
#     define ACE_SIZEOF_LONG 8
#   else
#     error: unsupported long size, must be updated for this platform!
#   endif /* ULONG_MAX */
# endif /* !defined (ACE_SIZEOF_LONG) */

// The number of bytes in a long long.
# if !defined (ACE_SIZEOF_LONG_LONG)
#   if defined (ACE_LACKS_LONGLONG_T)
#     define ACE_SIZEOF_LONG_LONG 8
#   elif defined (ULLONG_MAX)
#     if ((ULLONG_MAX) == 4294967295ULL)
#       define ACE_SIZEOF_LONG_LONG 4
#     elif ((ULLONG_MAX) == 18446744073709551615ULL)
#       define ACE_SIZEOF_LONG_LONG 8
#     endif
#   elif defined (ULONGLONG_MAX)
#     if ((ULONGLONG_MAX) == 4294967295ULL)
#       define ACE_SIZEOF_LONG_LONG 4
#     elif ((ULONGLONG_MAX) == 18446744073709551615ULL)
#       define ACE_SIZEOF_LONG_LONG 8
#     endif
#   endif
#   // If we can't determine the size of long long, assume it is 8
#   // instead of erroring out.  (Either ULLONG_MAX and ULONGLONG_MAX
#   // may not be supported; or an extended C/C++ dialect may need to
#   // be selected.  If this assumption is wrong, it can be addressed
#   // in the platform-specific config header.
#   if !defined (ACE_SIZEOF_LONG_LONG)
#     define ACE_SIZEOF_LONG_LONG 8
#   endif
# endif /* !defined (ACE_SIZEOF_LONG_LONG) */


ACE_BEGIN_VERSIONED_NAMESPACE_DECL

// The sizes of the commonly implemented types are now known.  Set up
// typedefs for whatever we can.  Some of these are needed for certain
// cases of ACE_UINT64, so do them before the 64-bit stuff.

#if defined (ACE_INT8_TYPE)
  typedef ACE_INT8_TYPE         ACE_INT8;
#elif defined (ACE_HAS_INT8_T)
  typedef int8_t                ACE_INT8;
#elif !defined (ACE_LACKS_SIGNED_CHAR)
  typedef signed char           ACE_INT8;
#else
  typedef char                  ACE_INT8;
#endif /* defined (ACE_INT8_TYPE) */

#if defined (ACE_UINT8_TYPE)
  typedef ACE_UINT8_TYPE        ACE_UINT8;
#elif defined (ACE_HAS_UINT8_T)
  typedef uint8_t               ACE_UINT8;
#else
  typedef unsigned char         ACE_UINT8;
#endif /* defined (ACE_UINT8_TYPE) */

#if defined (ACE_INT16_TYPE)
  typedef ACE_INT16_TYPE        ACE_INT16;
#elif defined (ACE_HAS_INT16_T)
  typedef int16_t               ACE_INT16;
#elif ACE_SIZEOF_SHORT == 2
  typedef short                 ACE_INT16;
#elif ACE_SIZEOF_INT == 2
  typedef int                   ACE_INT16;
#else
# error Have to add to the ACE_INT16 type setting
#endif  /* defined (ACE_INT16_TYPE) */

#if defined (ACE_UINT16_TYPE)
  typedef ACE_UINT16_TYPE       ACE_UINT16;
#elif defined (ACE_HAS_UINT16_T)
  typedef uint16_t              ACE_UINT16;
#elif ACE_SIZEOF_SHORT == 2
  typedef unsigned short        ACE_UINT16;
#elif ACE_SIZEOF_INT == 2
  typedef unsigned int          ACE_UINT16;
#else
# error Have to add to the ACE_UINT16 type setting
#endif /* defined (ACE_UINT16_TYPE) */

#if defined (ACE_INT32_TYPE)
  typedef ACE_INT32_TYPE        ACE_INT32;
#elif defined (ACE_HAS_INT32_T)
  typedef int32_t               ACE_INT32;
#elif ACE_SIZEOF_INT == 4
  typedef int                   ACE_INT32;
#elif ACE_SIZEOF_LONG == 4
  typedef long                  ACE_INT32;
#else
# error Have to add to the ACE_INT32 type setting
#endif /* defined (ACE_INT32_TYPE) */

#if defined (ACE_UINT32_TYPE)
  typedef ACE_UINT32_TYPE       ACE_UINT32;
#elif defined (ACE_HAS_UINT32_T)
  typedef uint32_t              ACE_UINT32;
#elif ACE_SIZEOF_INT == 4
  typedef unsigned int          ACE_UINT32;
#elif ACE_SIZEOF_LONG == 4
  typedef unsigned long         ACE_UINT32;
#else
# error Have to add to the ACE_UINT32 type setting
#endif /* defined (ACE_UINT32_TYPE) */

#if defined (ACE_INT64_TYPE)
  typedef ACE_INT64_TYPE        ACE_INT64;
#elif defined (ACE_HAS_INT64_T)
  typedef int64_t               ACE_INT64;
#elif ACE_SIZEOF_LONG == 8
  typedef long                  ACE_INT64;
#elif !defined (ACE_LACKS_LONGLONG_T) && ACE_SIZEOF_LONG_LONG == 8
# ifdef __GNUC__
  // Silence g++ "-pedantic" warnings regarding use of "long long"
  // type.
  __extension__
# endif  /* __GNUC__ */
  typedef long long             ACE_INT64;
#endif /* defined (ACE_INT64_TYPE) */

#if !(defined (ACE_LACKS_LONGLONG_T) || defined (ACE_LACKS_UNSIGNEDLONGLONG_T))
/* See matching #if around ACE_U_LongLong class declaration below */

#  if defined (ACE_UINT64_TYPE)
  typedef ACE_UINT64_TYPE       ACE_UINT64;
#  elif defined (ACE_HAS_UINT64_T)
  typedef uint64_t              ACE_UINT64;
#  elif ACE_SIZEOF_LONG == 8
  typedef unsigned long         ACE_UINT64;
#  elif ACE_SIZEOF_LONG_LONG == 8
# ifdef __GNUC__
  // Silence g++ "-pedantic" warnings regarding use of "long long"
  // type.
  __extension__
# endif  /* __GNUC__ */
  typedef unsigned long long    ACE_UINT64;
#  endif /* defined (ACE_UINT64_TYPE) */
#endif /* !(ACE_LACKS_LONGLONG_T || ACE_LACKS_UNSIGNEDLONGLONG_T) */


typedef ACE_UINT16 ACE_USHORT16;  // @@ Backward compatibility.

// Define a generic byte for use in codecs
typedef unsigned char ACE_Byte;

// Define a pseudo wide character type when wchar is not supported so we
// can support basic wide character string operations.

# if defined (ACE_HAS_WCHAR) || defined (ACE_HAS_XPG4_MULTIBYTE_CHAR)
#   define ACE_WINT_T wint_t
#   define ACE_WCHAR_T wchar_t
# else
#   define ACE_WINT_T ACE_UINT16
#   define ACE_WCHAR_T ACE_UINT16
# endif /* ACE_HAS_WCHAR */

// The number of bytes in a void *.
# ifndef ACE_SIZEOF_VOID_P
#   define ACE_SIZEOF_VOID_P ACE_SIZEOF_LONG
# endif /* ACE_SIZEOF_VOID_P */

// Type for doing arithmetic on pointers ... as elsewhere, we assume
// that unsigned versions of a type are the same size as the signed
// version of the same type.
# if defined (ACE_HAS_WINCE) && (_WIN32_WCE < 400)
typedef unsigned long ptrdiff_t;    // evc3, PocketPC don't defined ptrdiff_t
# endif

ACE_END_VERSIONED_NAMESPACE_DECL

// Byte-order (endian-ness) determination.
# if defined (BYTE_ORDER)
#   if (BYTE_ORDER == LITTLE_ENDIAN)
#     define ACE_LITTLE_ENDIAN 0x0123
#     define ACE_BYTE_ORDER ACE_LITTLE_ENDIAN
#   elif (BYTE_ORDER == BIG_ENDIAN)
#     define ACE_BIG_ENDIAN 0x3210
#     define ACE_BYTE_ORDER ACE_BIG_ENDIAN
#   else
#     error: unknown BYTE_ORDER!
#   endif /* BYTE_ORDER */
# elif defined (_BYTE_ORDER)
#   if (_BYTE_ORDER == _LITTLE_ENDIAN)
#     define ACE_LITTLE_ENDIAN 0x0123
#     define ACE_BYTE_ORDER ACE_LITTLE_ENDIAN
#   elif (_BYTE_ORDER == _BIG_ENDIAN)
#     define ACE_BIG_ENDIAN 0x3210
#     define ACE_BYTE_ORDER ACE_BIG_ENDIAN
#   else
#     error: unknown _BYTE_ORDER!
#   endif /* _BYTE_ORDER */
# elif defined (__BYTE_ORDER)
#   if (__BYTE_ORDER == __LITTLE_ENDIAN)
#     define ACE_LITTLE_ENDIAN 0x0123
#     define ACE_BYTE_ORDER ACE_LITTLE_ENDIAN
#   elif (__BYTE_ORDER == __BIG_ENDIAN)
#     define ACE_BIG_ENDIAN 0x3210
#     define ACE_BYTE_ORDER ACE_BIG_ENDIAN
#   else
#     error: unknown __BYTE_ORDER!
#   endif /* __BYTE_ORDER */
# else /* ! BYTE_ORDER && ! __BYTE_ORDER */
  // We weren't explicitly told, so we have to figure it out . . .
#   if defined (i386) || defined (__i386__) || defined (_M_IX86) || \
     defined (vax) || defined (__alpha) || defined (__LITTLE_ENDIAN__) || \
     defined (ARM) || defined (_M_IA64) || defined (__ia64__) || \
     defined (_M_AMD64) || defined (__amd64)
    // We know these are little endian.
#     define ACE_LITTLE_ENDIAN 0x0123
#     define ACE_BYTE_ORDER ACE_LITTLE_ENDIAN
#   else
    // Otherwise, we assume big endian.
#     define ACE_BIG_ENDIAN 0x3210
#     define ACE_BYTE_ORDER ACE_BIG_ENDIAN
#   endif
# endif /* ! BYTE_ORDER && ! __BYTE_ORDER */

// Byte swapping macros to deal with differences between little endian
// and big endian machines.  Note that "long" here refers to 32 bit
// quantities.
# define ACE_SWAP_LONG(L) ((ACE_SWAP_WORD ((L) & 0xFFFF) << 16) \
            | ACE_SWAP_WORD(((L) >> 16) & 0xFFFF))
# define ACE_SWAP_WORD(L) ((((L) & 0x00FF) << 8) | (((L) & 0xFF00) >> 8))

# if defined (ACE_LITTLE_ENDIAN)
#   define ACE_HTONL(X) ACE_SWAP_LONG (X)
#   define ACE_NTOHL(X) ACE_SWAP_LONG (X)
#   define ACE_IDL_NCTOHL(X) (X)
#   define ACE_IDL_NSTOHL(X) (X)
# else
#   define ACE_HTONL(X) X
#   define ACE_NTOHL(X) X
#   define ACE_IDL_NCTOHL(X) (X << 24)
#   define ACE_IDL_NSTOHL(X) ((X) << 16)
# endif /* ACE_LITTLE_ENDIAN */

# if defined (ACE_LITTLE_ENDIAN)
#   define ACE_HTONS(x) ACE_SWAP_WORD(x)
#   define ACE_NTOHS(x) ACE_SWAP_WORD(x)
# else
#   define ACE_HTONS(x) x
#   define ACE_NTOHS(x) x
# endif /* ACE_LITTLE_ENDIAN */

#if defined (ACE_LACKS_LONGLONG_T)
  // This throws away the high 32 bits.  It's very unlikely that a
  // pointer will be more than 32 bits wide if the platform does not
  // support 64-bit integers.
# define ACE_LONGLONG_TO_PTR(PTR_TYPE, L) \
  reinterpret_cast<PTR_TYPE> (L.lo ())
#elif defined (ACE_OPENVMS) && (!defined (__INITIAL_POINTER_SIZE) || (__INITIAL_POINTER_SIZE < 64))
# define ACE_LONGLONG_TO_PTR(PTR_TYPE, L) \
  reinterpret_cast<PTR_TYPE> (static_cast<int> (L))
#else  /* ! ACE_LACKS_LONGLONG_T */
# define ACE_LONGLONG_TO_PTR(PTR_TYPE, L) \
  reinterpret_cast<PTR_TYPE> (static_cast<intptr_t> (L))
#endif /* ! ACE_LACKS_LONGLONG_T */

// If the platform lacks an unsigned long long, define one.
#if defined (ACE_LACKS_LONGLONG_T) || defined (ACE_LACKS_UNSIGNEDLONGLONG_T)
// Forward declaration for streams
#   include "ace/iosfwd.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class ACE_U_LongLong
 *
 * @brief Unsigned long long for platforms that don't have one.
 *
 * Provide our own unsigned long long.  This is intended to be
 * use with ACE_High_Res_Timer, so the division operator assumes
 * that the quotient fits into a u_long.
 * Please note that the constructor takes (optionally) two values.
 * The high one contributes 0x100000000 times its value.  So,
 * for example, (0, 2) is _not_ 20000000000, but instead
 * 0x200000000.  To emphasize this, the default values are expressed
 * in hex, and output () dumps the value in hex.
 */
  class ACE_Export ACE_U_LongLong
  {
  public:
    // = Initialization and termination methods.
#if defined (ACE_LACKS_UNSIGNEDLONGLONG_T)
    ACE_U_LongLong (const long long value = 0x0);
#else
    ACE_U_LongLong (const ACE_UINT32 lo = 0x0, const ACE_UINT32 hi = 0x0);
#endif
    ACE_U_LongLong (const ACE_U_LongLong &);
    ACE_U_LongLong &operator= (const ACE_U_LongLong &);
    ACE_U_LongLong &operator= (const ACE_INT32 &);
    ACE_U_LongLong &operator= (const ACE_UINT32 &);
    ~ACE_U_LongLong (void);

    // = Overloaded relation operators.
    bool operator== (const ACE_U_LongLong &) const;
    bool operator== (const ACE_UINT32) const;
    bool operator!= (const ACE_U_LongLong &) const;
    bool operator!= (const ACE_UINT32) const;
    bool operator< (const ACE_U_LongLong &) const;
    bool operator< (const ACE_UINT32) const;
    bool operator<= (const ACE_U_LongLong &) const;
    bool operator<= (const ACE_UINT32) const;
    bool operator> (const ACE_U_LongLong &) const;
    bool operator> (const ACE_UINT32) const;
    bool operator>= (const ACE_U_LongLong &) const;
    bool operator>= (const ACE_UINT32) const;

    ACE_U_LongLong operator+ (const ACE_U_LongLong &) const;
    ACE_U_LongLong operator+ (const ACE_UINT32) const;
    ACE_U_LongLong operator- (const ACE_U_LongLong &) const;
    ACE_U_LongLong operator- (const ACE_UINT32) const;
    ACE_U_LongLong operator* (const ACE_UINT32) const;
    ACE_U_LongLong &operator*= (const ACE_UINT32);

    ACE_U_LongLong operator<< (const unsigned int) const;
    ACE_U_LongLong &operator<<= (const unsigned int);
    ACE_U_LongLong operator>> (const unsigned int) const;
    ACE_U_LongLong &operator>>= (const unsigned int);

    double operator/ (const double) const;

    ACE_U_LongLong &operator+= (const ACE_U_LongLong &);
    ACE_U_LongLong &operator+= (const ACE_UINT32);
    ACE_U_LongLong &operator-= (const ACE_U_LongLong &);
    ACE_U_LongLong &operator-= (const ACE_UINT32);
    ACE_U_LongLong &operator++ ();
    ACE_U_LongLong &operator-- ();
    const ACE_U_LongLong operator++ (int);
    const ACE_U_LongLong operator-- (int);
    ACE_U_LongLong &operator|= (const ACE_U_LongLong);
    ACE_U_LongLong &operator|= (const ACE_UINT32);
    ACE_U_LongLong &operator&= (const ACE_U_LongLong);
    ACE_U_LongLong &operator&= (const ACE_UINT32);

    // Note that the following take ACE_UINT32 arguments.  These are
    // typical use cases, and easy to implement.  But, they limit the
    // return values to 32 bits as well.  There are no checks for
    // overflow.
    ACE_UINT32 operator/ (const ACE_UINT32) const;
    ACE_UINT32 operator% (const ACE_UINT32) const;

    // The following only operate on the lower 32 bits (they take only
    // 32 bit arguments).
    ACE_UINT32 operator| (const ACE_INT32) const;
    ACE_UINT32 operator& (const ACE_INT32) const;

    // The following operators convert their arguments to
    // ACE_UINT32.  So, there may be information loss if they are
    // used.
    ACE_U_LongLong operator* (const ACE_INT32) const;
    ACE_U_LongLong &operator*= (const ACE_INT32);
    ACE_UINT32 operator/ (const ACE_INT32) const;
#   if ACE_SIZEOF_INT == 4
    ACE_UINT32 operator/ (const unsigned long) const;
    ACE_UINT32 operator/ (const long) const;
#   else  /* ACE_SIZEOF_INT != 4 */
    ACE_UINT32 operator/ (const unsigned int) const;
    ACE_UINT32 operator/ (const int) const;
#   endif /* ACE_SIZEOF_INT != 4 */

    // = Helper methods.
    /// Outputs the value to the FILE, in hex.
    void output (FILE * = stdout) const;

    ACE_TCHAR *as_string (ACE_TCHAR *string,
                          unsigned int base = 10,
                          unsigned int uppercase = 0) const;

    ACE_UINT32 hi (void) const;
    ACE_UINT32 lo (void) const;

    void hi (const ACE_UINT32 hi);
    void lo (const ACE_UINT32 lo);

#if defined (ACE_LACKS_UNSIGNEDLONGLONG_T)
    long long to_int64 (void) const;
#   endif

  private:

#if defined (ACE_LACKS_UNSIGNEDLONGLONG_T)
    long long data_;
#else
  public:
    struct ace_hi_lo_correct_endian
    {
#  if defined (ACE_BIG_ENDIAN)
      /// High 32 bits.
      ACE_UINT32 hi_;
      /// Low 32 bits.
      ACE_UINT32 lo_;

#  else

      /// Low 32 bits.
      ACE_UINT32 lo_;
      /// High 32 bits.
      ACE_UINT32 hi_;
#  endif /* ! ACE_BIG_ENDIAN */
    };
  private:
    union
    {
      struct ace_hi_lo_correct_endian data_;

      /// To ensure alignment on 8-byte boundary.
      double for_alignment_;
    };

    // @note  the following four accessors are inlined here in
    // order to minimize the extent of the data_ struct.  It's
    // only used here; the .i and .cpp files use the accessors.

    /// Internal utility function to hide access through struct.
    const ACE_UINT32 &h_ () const { return data_.hi_; }

    /// Internal utility function to hide access through struct.
    ACE_UINT32 &h_ () { return data_.hi_; }

    /// Internal utility function to hide access through struct.
    const ACE_UINT32 &l_ () const { return data_.lo_; }

    /// Internal utility function to hide access through struct.
    ACE_UINT32 &l_ () { return data_.lo_; }

    // @note  the above four accessors are inlined here in
    // order to minimize the extent of the data_ struct.  It's
    // only used here; the .inl and .cpp files use the accessors.

    /// These functions are used to implement multiplication.
    ACE_UINT32 ul_shift (ACE_UINT32 a,
                         ACE_UINT32 c_in,
                         ACE_UINT32 *c_out) const;
    ACE_U_LongLong ull_shift (ACE_U_LongLong a,
                              ACE_UINT32 c_in,
                              ACE_UINT32 *c_out) const;
    ACE_U_LongLong ull_add (ACE_U_LongLong a,
                            ACE_U_LongLong b,
                            ACE_UINT32 *carry) const;
    ACE_U_LongLong ull_mult (ACE_U_LongLong a,
                             ACE_UINT32 b,
                             ACE_UINT32 *carry) const;
#endif // ACE_LACKS_UNSIGNEDLONGLONG_T
  };

  typedef ACE_U_LongLong ACE_UINT64;

#if !defined (ACE_LACKS_IOSTREAM_TOTALLY)
  ostream &operator<< (ostream &, const ACE_U_LongLong &);
#endif /* ! ACE_LACKS_IOSTREAM_TOTALLY */

ACE_END_VERSIONED_NAMESPACE_DECL

# endif /* ACE_LACKS_LONGLONG_T */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

// Conversions from ACE_UINT64 to ACE_UINT32.  ACE_CU64_TO_CU32 should
// be used on const ACE_UINT64's.
# if defined (ACE_LACKS_LONGLONG_T) || defined (ACE_LACKS_UNSIGNEDLONGLONG_T)
inline ACE_UINT32
ACE_U64_TO_U32 (ACE_U_LongLong const & n)
{
  /**
   * @note We could add a cast operator to ACE_U_LongLong but that may
   *       cause more problems than it solves.  Force users to perform
   *       an explicit cast via ACE_{C}U64_TO_{C}U32.
   */
  return n.lo ();
}

inline ACE_UINT32
ACE_CU64_TO_CU32 (ACE_U_LongLong const & n)
{
  return ACE_U64_TO_U32 (n);
}
# else  /* ! ACE_LACKS_LONGLONG_T */
inline ACE_UINT32
ACE_U64_TO_U32 (ACE_UINT64 n)
{
  return static_cast<ACE_UINT32> (n);
}

inline ACE_UINT32
ACE_CU64_TO_CU32 (ACE_UINT64 n)
{
  return static_cast<ACE_UINT32> (n);
}
# endif /* ! ACE_LACKS_LONGLONG_T */

ACE_END_VERSIONED_NAMESPACE_DECL

// 64-bit literals require special marking on some platforms.
# if defined (ACE_LACKS_LONGLONG_T)
    // Can only specify 32-bit arguments.
#   define ACE_UINT64_LITERAL(n) n ## UL
      // This one won't really work, but it'll keep
      // some compilers happy until we have better support
#   define ACE_INT64_LITERAL(n) n ## L
# elif defined (ACE_WIN32)
#  if defined (__MINGW32__)
#   define ACE_UINT64_LITERAL(n) n ## ull
#   define ACE_INT64_LITERAL(n) n ## ll
#  else
#   define ACE_UINT64_LITERAL(n) n ## ui64
#   define ACE_INT64_LITERAL(n) n ## i64
#  endif /* defined (__MINGW32__) */
# elif defined (__TANDEM)
#   define ACE_UINT64_LITERAL(n) n ## LL
#   define ACE_INT64_LITERAL(n) n ## LL
# else  /* ! ACE_WIN32  &&  ! ACE_LACKS_LONGLONG_T */
#   define ACE_UINT64_LITERAL(n) n ## ull
#   define ACE_INT64_LITERAL(n) n ## ll
# endif /* ! ACE_WIN32  &&  ! ACE_LACKS_LONGLONG_T */

#if !defined (ACE_INT8_FORMAT_SPECIFIER)
#  if defined (PRId8)
#    define ACE_INT8_FORMAT_SPECIFIER ACE_TEXT ("%") ACE_TEXT (PRId8)
#  else
#    define ACE_INT8_FORMAT_SPECIFIER ACE_TEXT ("%d")
#  endif /* defined (PRId8) */
#endif /* ACE_INT8_FORMAT_SPECIFIER */

#if !defined (ACE_UINT8_FORMAT_SPECIFIER)
#  if defined (PRIu8)
#    define ACE_UINT8_FORMAT_SPECIFIER ACE_TEXT ("%") ACE_TEXT (PRIu8)
#  else
#    define ACE_UINT8_FORMAT_SPECIFIER ACE_TEXT ("%u")
#  endif /* defined (PRIu8) */
#endif /* ACE_UINT8_FORMAT_SPECIFIER */

#if !defined (ACE_INT16_FORMAT_SPECIFIER)
#  if defined (PRId16)
#    define ACE_INT16_FORMAT_SPECIFIER ACE_TEXT ("%") ACE_TEXT (PRId16)
#  else
#    define ACE_INT16_FORMAT_SPECIFIER ACE_TEXT ("%d")
#  endif /* defined (PRId16) */
#endif /* ACE_INT16_FORMAT_SPECIFIER */

#if !defined (ACE_UINT16_FORMAT_SPECIFIER)
#  if defined (PRIu16)
#    define ACE_UINT16_FORMAT_SPECIFIER ACE_TEXT ("%") ACE_TEXT (PRIu16)
#  else
#    define ACE_UINT16_FORMAT_SPECIFIER ACE_TEXT ("%u")
#  endif /* defined (PRIu16) */
#endif /* ACE_UINT16_FORMAT_SPECIFIER */

#if !defined (ACE_INT32_FORMAT_SPECIFIER)
#  if defined (PRId32)
#    define ACE_INT32_FORMAT_SPECIFIER ACE_TEXT ("%") ACE_TEXT (PRId32)
#  elif ACE_SIZEOF_INT == 4
#    define ACE_INT32_FORMAT_SPECIFIER ACE_TEXT ("%d")
#  else
#    define ACE_INT32_FORMAT_SPECIFIER ACE_TEXT ("%ld")
#  endif /* defined (PRId32) */
#endif /* ACE_INT32_FORMAT_SPECIFIER */

#if !defined (ACE_UINT32_FORMAT_SPECIFIER)
#  if defined (PRIu32)
#    define ACE_UINT32_FORMAT_SPECIFIER ACE_TEXT ("%") ACE_TEXT (PRIu32)
#  elif ACE_SIZEOF_INT == 4
#    define ACE_UINT32_FORMAT_SPECIFIER ACE_TEXT ("%u")
#  else
#    define ACE_UINT32_FORMAT_SPECIFIER ACE_TEXT ("%lu")
#  endif /* defined (PRIu32) */
#endif /* ACE_UINT32_FORMAT_SPECIFIER */

#if !defined (ACE_INT64_FORMAT_SPECIFIER)
#  if defined (PRId64)
#    define ACE_INT64_FORMAT_SPECIFIER ACE_TEXT ("%") ACE_TEXT (PRId64)
#  elif ACE_SIZEOF_LONG == 8
#    define ACE_INT64_FORMAT_SPECIFIER ACE_TEXT ("%ld")
#  else
#    define ACE_INT64_FORMAT_SPECIFIER ACE_TEXT ("%lld")
#  endif /* defined (PRId64) */
#endif /* ACE_INT64_FORMAT_SPECIFIER */

#if !defined (ACE_UINT64_FORMAT_SPECIFIER)
#  if defined (PRIu64)
#    define ACE_UINT64_FORMAT_SPECIFIER ACE_TEXT ("%") ACE_TEXT (PRIu64)
#  elif ACE_SIZEOF_LONG == 8
#    define ACE_UINT64_FORMAT_SPECIFIER ACE_TEXT ("%lu")
#  else
#    define ACE_UINT64_FORMAT_SPECIFIER ACE_TEXT ("%llu")
#  endif /* defined (PRIu64) */
#endif /* ACE_UINT64_FORMAT_SPECIFIER */

#if !defined (ACE_SSIZE_T_FORMAT_SPECIFIER)
# if defined (ACE_WIN64)
#  define ACE_SSIZE_T_FORMAT_SPECIFIER ACE_TEXT ("%I64d")
# else
#  define ACE_SSIZE_T_FORMAT_SPECIFIER ACE_TEXT ("%d")
# endif /* ACE_WIN64 */
#endif /* ACE_SSIZE_T_FORMAT_SPECIFIER */

#if !defined (ACE_SIZE_T_FORMAT_SPECIFIER)
# if defined (ACE_WIN64)
#  define ACE_SIZE_T_FORMAT_SPECIFIER ACE_TEXT ("%I64u")
# else
#  define ACE_SIZE_T_FORMAT_SPECIFIER ACE_TEXT ("%u")
# endif /* ACE_WIN64 */
#endif /* ACE_SIZE_T_FORMAT_SPECIFIER */

// Cast from UINT64 to a double requires an intermediate cast to INT64
// on some platforms.
# if defined (ACE_LACKS_LONGLONG_T)
   // Only use the low 32 bits.
#   define ACE_UINT64_DBLCAST_ADAPTER(n) ACE_U64_TO_U32 (n)
# elif defined (ACE_LACKS_UNSIGNEDLONGLONG_T)
#   define ACE_UINT64_DBLCAST_ADAPTER(n) ((n).to_int64 ())
# elif defined (ACE_WIN32)
#   define ACE_UINT64_DBLCAST_ADAPTER(n) static_cast<__int64> (n)
# else  /* ! ACE_WIN32 && ! ACE_LACKS_LONGLONG_T */
#   define ACE_UINT64_DBLCAST_ADAPTER(n) (n)
# endif /* ! ACE_WIN32 && ! ACE_LACKS_LONGLONG_T */


// The number of bytes in a float.
# ifndef ACE_SIZEOF_FLOAT
#   if FLT_MAX_EXP == 128
#     define ACE_SIZEOF_FLOAT 4
#   elif FLT_MAX_EXP == 1024
#     define ACE_SIZEOF_FLOAT 8
#   else
#     error: unsupported float size, must be updated for this platform!
#   endif /* FLT_MAX_EXP */
# endif /* ACE_SIZEOF_FLOAT */

// The number of bytes in a double.
# ifndef ACE_SIZEOF_DOUBLE
#   if DBL_MAX_EXP == 128
#     define ACE_SIZEOF_DOUBLE 4
#   elif DBL_MAX_EXP == 1024
#     define ACE_SIZEOF_DOUBLE 8
#   else
#     error: unsupported double size, must be updated for this platform!
#   endif /* DBL_MAX_EXP */
# endif /* ACE_SIZEOF_DOUBLE */

// The number of bytes in a long double.
# ifndef ACE_SIZEOF_LONG_DOUBLE
#   if LDBL_MAX_EXP == 128
#     define ACE_SIZEOF_LONG_DOUBLE 4
#   elif LDBL_MAX_EXP == 1024
#     define ACE_SIZEOF_LONG_DOUBLE 8
#   elif LDBL_MAX_EXP == 16384
#     if defined (LDBL_DIG)  &&  LDBL_DIG == 18
#       if defined (__ia64) || defined (__x86_64)
#         define ACE_SIZEOF_LONG_DOUBLE 16
#       else /* ! __ia64 */
#       define ACE_SIZEOF_LONG_DOUBLE 12
#       endif /* __ia64 */
#     else  /* ! LDBL_DIG  ||  LDBL_DIG != 18 */
#       define ACE_SIZEOF_LONG_DOUBLE 16
#     endif /* ! LDBL_DIG  ||  LDBL_DIG != 18 */
#   else
#     error: unsupported double size, must be updated for this platform!
#   endif /* LDBL_MAX_EXP */
# endif /* ACE_SIZEOF_LONG_DOUBLE */

// Max and min sizes for the ACE integer types.
#define ACE_CHAR_MAX 0x7F
#define ACE_CHAR_MIN -(ACE_CHAR_MAX)-1
#define ACE_OCTET_MAX 0xFF
#define ACE_INT16_MAX 0x7FFF
#define ACE_INT16_MIN -(ACE_INT16_MAX)-1
#define ACE_UINT16_MAX 0xFFFF
#define ACE_WCHAR_MAX ACE_UINT16_MAX
#define ACE_INT32_MAX 0x7FFFFFFF
#define ACE_INT32_MIN -(ACE_INT32_MAX)-1
#define ACE_UINT32_MAX 0xFFFFFFFF
#define ACE_INT64_MAX ACE_INT64_LITERAL(0x7FFFFFFFFFFFFFFF)
#define ACE_INT64_MIN -(ACE_INT64_MAX)-1

#if defined (ACE_LACKS_UNSIGNEDLONGLONG_T)
// ACE_U_LongLong's constructor accepts a "long long" in this
// case.  Set it to ACE_U_LongLong (-1) since the bit pattern for long
// long (-1) is the same as the maximum unsigned long long value.
# define ACE_UINT64_MAX ACE_U_LongLong (ACE_INT64_LITERAL (0xFFFFFFFFFFFFFFFF))
#elif defined (ACE_LACKS_LONGLONG_T)
// ACE_U_LongLong's constructor accepts an ACE_UINT32 low and high
// pair of parameters.
# define ACE_UINT64_MAX ACE_U_LongLong (0xFFFFFFFFu, 0xFFFFFFFFu)
#else
# define ACE_UINT64_MAX ACE_UINT64_LITERAL (0xFFFFFFFFFFFFFFFF)
#endif  /* ACE_LACKS_UNSIGNEDLONGLONG_T */

// These use ANSI/IEEE format.
#define ACE_FLT_MAX 3.402823466e+38F
#define ACE_FLT_MIN 1.175494351e-38F
#define ACE_DBL_MAX 1.7976931348623158e+308
#define ACE_DBL_MIN 2.2250738585072014e-308

# if defined (__ACE_INLINE__)
#   include "ace/Basic_Types.inl"
# endif /* __ACE_INLINE__ */

# include /**/ "ace/post.h"
#endif /* ACE_BASIC_TYPES_H */
