// -*- C++ -*-

//=========================================================================
/**
 * @file Encoding_Converter.h
 *
 * $Id: Encoding_Converter.h 80826 2008-03-04 14:51:23Z wotte $
 *
 * This class is the base class for all encoding converters that convert
 * to and from UTF-8.
 *
 * @author Chad Elliott <elliott_c@ociweb.com>
 */
//=========================================================================

#ifndef ACE_ENCODING_CONVERTER_H
#define ACE_ENCODING_CONVERTER_H

#include /**/ "ace/pre.h"

#include "ace/Basic_Types.h"

#if defined (ACE_USES_WCHAR)
#include /**/ "ace/ACE_export.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/** The base class for all ACE UTF Encoding Converters.
 * This class provides a generic interface that is used to implement
 * various UTF encoding conversion classes.
 */
class ACE_Export ACE_Encoding_Converter
{
public:
  /// This enum describes the various states that can be returned
  /// from the to_utf8() and from_utf8() methods which depends on
  /// both the source buffer and the size of the target buffer.
  enum Result {CONVERSION_OK,
               SOURCE_EXHAUSTED,
               TARGET_EXHAUSTED,
               SOURCE_ILLEGAL
              };

  /// This destructor is here (and virtual) because we have virtual
  /// functions.
  virtual ~ACE_Encoding_Converter (void);

  /// Convert the source (which can be in any encoding) to UTF-8 and
  /// store it in the provided target buffer.
  virtual Result to_utf8 (const void* source,
                          size_t source_size,
                          ACE_Byte* target,
                          size_t target_size,
                          bool strict = true) = 0;

  /// Convert the UTF-8 source into an alternate encoding and store it
  /// in the provided target buffer.
  virtual Result from_utf8 (const ACE_Byte* source,
                            size_t source_size,
                            void* target,
                            size_t target_size,
                            bool strict = true) = 0;
};

ACE_END_VERSIONED_NAMESPACE_DECL
#endif /* ACE_USES_WCHAR */

#include /**/ "ace/post.h"

#endif /* ACE_ENCODING_CONVERTER_H */
