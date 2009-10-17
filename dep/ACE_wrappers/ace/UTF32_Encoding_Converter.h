// -*- C++ -*-

//=========================================================================
/**
 * @file UTF32_Encoding_Converter.h
 *
 * $Id: UTF32_Encoding_Converter.h 80826 2008-03-04 14:51:23Z wotte $
 *
 * This class contains declarations for methods that convert between
 * UTF-32 (both BE and LE) and UTF-8
 *
 * @author Chad Elliott <elliott_c@ociweb.com>
 */
//=========================================================================

#ifndef ACE_UTF32_ENCODING_CONVERTER_H
#define ACE_UTF32_ENCODING_CONVERTER_H

#include /**/ "ace/pre.h"

#include "ace/UTF16_Encoding_Converter.h"

#if defined (ACE_USES_WCHAR)
ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/** Convert from UTF-32 to UTF-8 and from UTF-8 to UTF-32.
 * This class implements the ACE_Encoding_Converter interface.
 */
class ACE_UTF32_Encoding_Converter: public ACE_UTF16_Encoding_Converter
{
public:
  /// This class has some similarities to the UTF16 converter, so
  /// we just construct our base class and pass the swap parameter.
  ACE_UTF32_Encoding_Converter (bool swap = false);

  /// This is a do nothing destructor.
  virtual ~ACE_UTF32_Encoding_Converter (void);

  /// Convert the source from UTF-32 to UTF-8 and store it in the
  /// provided target buffer.
  virtual Result to_utf8 (const void* source,
                          size_t source_size,
                          ACE_Byte* target,
                          size_t target_size,
                          bool strict = true);

  /// Convert the UTF-8 source into a UTF-32 encoding and store it
  /// in the provided target buffer.
  virtual Result from_utf8 (const ACE_Byte* source,
                            size_t source_size,
                            void* target,
                            size_t target_size,
                            bool strict = true);

  /// This factory helper method determines if the source stream is UTF-32
  /// encoded.  If it is, allocate an ACE_UTF32_Encoding_Converter and
  /// return it.  The caller then owns the allocated object.
  static ACE_UTF32_Encoding_Converter* encoded (const ACE_Byte* source,
                                                size_t source_size);
};

ACE_END_VERSIONED_NAMESPACE_DECL
#endif /* ACE_USES_WCHAR */

#include /**/ "ace/post.h"

#endif /* ACE_UTF32_ENCODING_CONVERTER_H */

