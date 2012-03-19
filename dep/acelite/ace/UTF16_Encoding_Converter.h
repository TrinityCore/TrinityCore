// -*- C++ -*-

//=========================================================================
/**
 * @file UTF16_Encoding_Converter.h
 *
 * $Id: UTF16_Encoding_Converter.h 80826 2008-03-04 14:51:23Z wotte $
 *
 * This class contains declarations for methods that convert between
 * UTF-16 (both BE and LE) and UTF-8
 *
 * @author Chad Elliott <elliott_c@ociweb.com>
 */
//=========================================================================

#ifndef ACE_UTF16_ENCODING_CONVERTER_H
#define ACE_UTF16_ENCODING_CONVERTER_H

#include /**/ "ace/pre.h"

#include "ace/Encoding_Converter.h"

#if defined (ACE_USES_WCHAR)
ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/** Convert from UTF-16 to UTF-8 and from UTF-8 to UTF-16.
 * This class implements the ACE_Encoding_Converter interface.
 */
class ACE_UTF16_Encoding_Converter: public ACE_Encoding_Converter
{
public:
  /// The swap parameter determines whether we need to swap byte order on
  /// the stream as each word is pulled off when converting to UTF-8.
  ACE_UTF16_Encoding_Converter (bool swap = false);

  /// This is a do nothing destructor.
  virtual ~ACE_UTF16_Encoding_Converter (void);

  /// Convert the source from UTF-16 to UTF-8 and store it in the
  /// provided target buffer.
  virtual Result to_utf8 (const void* source,
                          size_t source_size,
                          ACE_Byte* target,
                          size_t target_size,
                          bool strict = true);

  /// Convert the UTF-8 source into a UTF-16 encoding and store it
  /// in the provided target buffer.
  virtual Result from_utf8 (const ACE_Byte* source,
                            size_t source_size,
                            void* target,
                            size_t target_size,
                            bool strict = true);

  /// This factory helper method determines if the source stream is UTF-16
  /// encoded.  If it is, allocate an ACE_UTF16_Encoding_Converter and
  /// return it.  The caller then owns the allocated object.
  static ACE_UTF16_Encoding_Converter* encoded (const ACE_Byte* source,
                                                size_t source_size);

protected:
  /// Determines if the source buffer is legal UTF-8
  bool is_legal_utf8 (const ACE_Byte* source,
                      size_t length) const;

  static ACE_UINT32 get_UNI_SUR_HIGH_START (void);
  static ACE_UINT32 get_UNI_SUR_LOW_END (void);
  static ACE_UINT32 get_UNI_REPLACEMENT_CHAR (void);
  static const ACE_Byte* get_first_byte_mark (void);
  static const ACE_Byte* get_trailing_bytes_for_utf8 (void);
  static const ACE_UINT32* get_offsets_from_utf8 (void);

  bool swap_;
};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ace/UTF16_Encoding_Converter.inl"
#endif /* __ACE_INLINE__ */

#endif /* ACE_USES_WCHAR */

#include /**/ "ace/post.h"

#endif /* ACE_UTF16_ENCODING_CONVERTER_H */
