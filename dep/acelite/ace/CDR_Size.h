// -*- C++ -*-

//=============================================================================
/**
 *  @file   CDR_Size.h
 *
 *  $Id: CDR_Size.h 93359 2011-02-11 11:33:12Z mcorino $
 *
 *
 * ACE Common Data Representation (CDR) size-calculating stream.
 *
 *
 * The current implementation assumes that the host has 1-byte,
 * 2-byte and 4-byte integral types, and that it has single
 * precision and double precision IEEE floats.
 * Those assumptions are pretty good these days, with Crays being
 * the only known exception.
 *
 *
 *  @author Boris Kolpackov <boris@kolpackov.net>
 *
 */
//=============================================================================

#ifndef ACE_CDR_SIZE_H
#define ACE_CDR_SIZE_H

#include /**/ "ace/pre.h"

#include "ace/CDR_Base.h"
#include "ace/CDR_Stream.h" // for ACE_OutputCDR::from_*

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/SStringfwd.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class ACE_SizeCDR
 *
 * @brief A CDR stream for calculating size of the representation.
 *
 */
class ACE_Export ACE_SizeCDR
{
public:
  /// Default constructor.
  ACE_SizeCDR (ACE_CDR::Octet major_version = ACE_CDR_GIOP_MAJOR_VERSION,
               ACE_CDR::Octet minor_version = ACE_CDR_GIOP_MINOR_VERSION);

  /// Returns @c false if an error has ocurred.
  bool good_bit (void) const;


  /// Reset current size.
  void reset (void);


  /// Return current size.
  size_t total_length (void) const;


  // Return 0 on failure and 1 on success.
  //@{ @name Size-calculating pseudo-write operations
  ACE_CDR::Boolean write_boolean (ACE_CDR::Boolean x);
  ACE_CDR::Boolean write_char (ACE_CDR::Char x);
  ACE_CDR::Boolean write_wchar (ACE_CDR::WChar x);
  ACE_CDR::Boolean write_octet (ACE_CDR::Octet x);
  ACE_CDR::Boolean write_short (ACE_CDR::Short x);
  ACE_CDR::Boolean write_ushort (ACE_CDR::UShort x);
  ACE_CDR::Boolean write_long (ACE_CDR::Long x);
  ACE_CDR::Boolean write_ulong (ACE_CDR::ULong x);
  ACE_CDR::Boolean write_longlong (const ACE_CDR::LongLong &x);
  ACE_CDR::Boolean write_ulonglong (const ACE_CDR::ULongLong &x);
  ACE_CDR::Boolean write_float (ACE_CDR::Float x);
  ACE_CDR::Boolean write_double (const ACE_CDR::Double &x);
  ACE_CDR::Boolean write_longdouble (const ACE_CDR::LongDouble &x);

  /// For string we offer methods that accept a precomputed length.
  ACE_CDR::Boolean write_string (const ACE_CDR::Char *x);
  ACE_CDR::Boolean write_string (ACE_CDR::ULong len,
                                 const ACE_CDR::Char *x);
  ACE_CDR::Boolean write_string (const ACE_CString &x);
  ACE_CDR::Boolean write_wstring (const ACE_CDR::WChar *x);
  ACE_CDR::Boolean write_wstring (ACE_CDR::ULong length,
                                  const ACE_CDR::WChar *x);
  //@}

  /// @note the portion written starts at <x> and ends
  ///    at <x + length>.
  /// The length is *NOT* stored into the CDR stream.
  //@{ @name Array write operations
  ACE_CDR::Boolean write_boolean_array (const ACE_CDR::Boolean *x,
                                        ACE_CDR::ULong length);
  ACE_CDR::Boolean write_char_array (const ACE_CDR::Char *x,
                                     ACE_CDR::ULong length);
  ACE_CDR::Boolean write_wchar_array (const ACE_CDR::WChar* x,
                                      ACE_CDR::ULong length);
  ACE_CDR::Boolean write_octet_array (const ACE_CDR::Octet* x,
                                      ACE_CDR::ULong length);
  ACE_CDR::Boolean write_short_array (const ACE_CDR::Short *x,
                                      ACE_CDR::ULong length);
  ACE_CDR::Boolean write_ushort_array (const ACE_CDR::UShort *x,
                                       ACE_CDR::ULong length);
  ACE_CDR::Boolean write_long_array (const ACE_CDR::Long *x,
                                     ACE_CDR::ULong length);
  ACE_CDR::Boolean write_ulong_array (const ACE_CDR::ULong *x,
                                      ACE_CDR::ULong length);
  ACE_CDR::Boolean write_longlong_array (const ACE_CDR::LongLong* x,
                                         ACE_CDR::ULong length);
  ACE_CDR::Boolean write_ulonglong_array (const ACE_CDR::ULongLong *x,
                                          ACE_CDR::ULong length);
  ACE_CDR::Boolean write_float_array (const ACE_CDR::Float *x,
                                      ACE_CDR::ULong length);
  ACE_CDR::Boolean write_double_array (const ACE_CDR::Double *x,
                                       ACE_CDR::ULong length);
  ACE_CDR::Boolean write_longdouble_array (const ACE_CDR::LongDouble* x,
                                           ACE_CDR::ULong length);

  ///
  /// Adjust to @a size and count <size> octets.
  void adjust (size_t size);

  /// As above, but now the size and alignment requirements may be
  /// different.
  void adjust (size_t size,
               size_t align);

private:
  /// disallow copying...
  ACE_SizeCDR (const ACE_SizeCDR& rhs);
  ACE_SizeCDR& operator= (const ACE_SizeCDR& rhs);

  ACE_CDR::Boolean write_1 (const ACE_CDR::Octet *x);
  ACE_CDR::Boolean write_2 (const ACE_CDR::UShort *x);
  ACE_CDR::Boolean write_4 (const ACE_CDR::ULong *x);
  ACE_CDR::Boolean write_8 (const ACE_CDR::ULongLong *x);
  ACE_CDR::Boolean write_16 (const ACE_CDR::LongDouble *x);

  /**
   * write an array of @a length elements, each of @a size bytes and the
   * start aligned at a multiple of <align>. The elements are assumed
   * to be packed with the right alignment restrictions.  It is mostly
   * designed for buffers of the basic types.
   *
   * This operation uses <memcpy>; as explained above it is expected
   * that using assignment is faster that <memcpy> for one element,
   * but for several elements <memcpy> should be more efficient, it
   * could be interesting to find the break even point and optimize
   * for that case, but that would be too platform dependent.
   */
  ACE_CDR::Boolean write_array (const void *x,
                                size_t size,
                                size_t align,
                                ACE_CDR::ULong length);


  ACE_CDR::Boolean write_wchar_array_i (const ACE_CDR::WChar* x,
                                        ACE_CDR::ULong length);

private:
  /// Set to false when an error ocurrs.
  bool good_bit_;

  /// Current size.
  size_t size_;

protected:
  /// GIOP version information
  ACE_CDR::Octet major_version_;
  ACE_CDR::Octet minor_version_;
};

// @@ This operator should not be inlined since they force SString.h
//    to be included in this header.
extern ACE_Export ACE_CDR::Boolean operator<< (ACE_SizeCDR &ss,
                                               const ACE_CString &x);

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
# include "ace/CDR_Size.inl"
#else /* __ACE_INLINE__ */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

// Not used by CORBA or TAO
extern ACE_Export ACE_CDR::Boolean operator<< (ACE_SizeCDR &ss,
                                               ACE_CDR::Char x);

// CDR size-calculating output operators for primitive types

extern ACE_Export ACE_CDR::Boolean operator<< (ACE_SizeCDR &ss,
                                               ACE_CDR::Short x);
extern ACE_Export ACE_CDR::Boolean operator<< (ACE_SizeCDR &ss,
                                               ACE_CDR::UShort x);
extern ACE_Export ACE_CDR::Boolean operator<< (ACE_SizeCDR &ss,
                                               ACE_CDR::Long x);
extern ACE_Export ACE_CDR::Boolean operator<< (ACE_SizeCDR &ss,
                                               ACE_CDR::ULong x);
extern ACE_Export ACE_CDR::Boolean operator<< (ACE_SizeCDR &ss,
                                               ACE_CDR::LongLong x);
extern ACE_Export ACE_CDR::Boolean operator<< (ACE_SizeCDR &ss,
                                               ACE_CDR::ULongLong x);
extern ACE_Export ACE_CDR::Boolean operator<< (ACE_SizeCDR& ss,
                                               ACE_CDR::LongDouble x);
extern ACE_Export ACE_CDR::Boolean operator<< (ACE_SizeCDR &ss,
                                               ACE_CDR::Float x);
extern ACE_Export ACE_CDR::Boolean operator<< (ACE_SizeCDR &ss,
                                               ACE_CDR::Double x);

// CDR size-calculating output operator from helper classes

extern ACE_Export ACE_CDR::Boolean operator<< (ACE_SizeCDR &ss,
                                               ACE_OutputCDR::from_boolean x);
extern ACE_Export ACE_CDR::Boolean operator<< (ACE_SizeCDR &ss,
                                               ACE_OutputCDR::from_char x);
extern ACE_Export ACE_CDR::Boolean operator<< (ACE_SizeCDR &ss,
                                               ACE_OutputCDR::from_wchar x);
extern ACE_Export ACE_CDR::Boolean operator<< (ACE_SizeCDR &ss,
                                               ACE_OutputCDR::from_octet x);
extern ACE_Export ACE_CDR::Boolean operator<< (ACE_SizeCDR &ss,
                                               ACE_OutputCDR::from_string x);
extern ACE_Export ACE_CDR::Boolean operator<< (ACE_SizeCDR &ss,
                                               ACE_OutputCDR::from_wstring x);
extern ACE_Export ACE_CDR::Boolean operator<< (ACE_SizeCDR &ss,
                                               const ACE_CDR::Char* x);
extern ACE_Export ACE_CDR::Boolean operator<< (ACE_SizeCDR &ss,
                                               const ACE_CDR::WChar* x);

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* __ACE_INLINE__ */


#include /**/ "ace/post.h"

#endif /* ACE_CDR_SIZE_H */
