// -*- C++ -*-

//=========================================================================
/**
 * @file UTF8_Encoding_Converter.h
 *
 * $Id: UTF8_Encoding_Converter.h 80826 2008-03-04 14:51:23Z wotte $
 *
 * This class contains declarations for methods that convert between
 * UTF-8 and the native ACE_TCHAR representation.
 *
 * @author Chad Elliott <elliott_c@ociweb.com>
 */
//=========================================================================

#ifndef ACE_UTF8_ENCODING_CONVERTER_H
#define ACE_UTF8_ENCODING_CONVERTER_H

#include /**/ "ace/pre.h"

#include "ace/Encoding_Converter.h"

#if defined (ACE_USES_WCHAR)
ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/** Convert from UTF-16 or UTF-32 to UTF-8.
 * This class implements the ACE_Encoding_Converter interface.
 */
class ACE_UTF8_Encoding_Converter: public ACE_Encoding_Converter
{
public:
  /// Allocate the converter to be used by the from_utf8() method based
  /// on the size of the native wide character.
  ACE_UTF8_Encoding_Converter (void);

  /// De-allocate the native converter.
  virtual ~ACE_UTF8_Encoding_Converter (void);

  /// Since the source *must be* UTF-8, there is no conversion required.
  /// This method just copies the source to the target given that there
  /// is enough space.
  virtual Result to_utf8 (const void* source,
                          size_t source_size,
                          ACE_Byte* target,
                          size_t target_size,
                          bool strict = true);

  /// Utilize the native converter to convert the UTF-8 source into an
  /// alternate encoding and store it in the provided target buffer.
  virtual Result from_utf8 (const ACE_Byte* source,
                            size_t source_size,
                            void* target,
                            size_t target_size,
                            bool strict = true);

  /// This factory helper method determines if the source stream is UTF-8
  /// encoded.  If it is, allocate an ACE_UTF8_Encoding_Converter and
  /// return it.  The caller then owns the allocated object.
  static ACE_UTF8_Encoding_Converter* encoded (const ACE_Byte* source,
                                               size_t source_size);

private:
  ACE_Encoding_Converter* native_;
};

ACE_END_VERSIONED_NAMESPACE_DECL
#endif /* ACE_USES_WCHAR */

#include /**/ "ace/post.h"

#endif /* ACE_UTF8_ENCODING_CONVERTER_H */

