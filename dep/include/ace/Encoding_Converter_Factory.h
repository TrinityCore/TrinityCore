// -*- C++ -*-

//=========================================================================
/**
 * @file Encoding_Converter_Factory.h
 *
 * $Id: Encoding_Converter_Factory.h 80826 2008-03-04 14:51:23Z wotte $
 *
 * This class can be used to create encoding converters of various types.
 *
 * @author Chad Elliott <elliott_c@ociweb.com>
 */
//=========================================================================

#ifndef ACE_ENCODING_CONVERTER_FACTORY_H
#define ACE_ENCODING_CONVERTER_FACTORY_H

#include /**/ "ace/pre.h"

#include "ace/Basic_Types.h"

#if defined (ACE_USES_WCHAR)
#include /**/ "ace/ACE_export.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

class ACE_Encoding_Converter;

/** Create an encoding converter based on the source or hint.
 * This class allows users to avoid knowing any concrete converter types.
 */
class ACE_Export ACE_Encoding_Converter_Factory
{
public:
  /// This enum is used to tell what type of converter to create.
  enum Encoding_Hint { ACE_UTF_32BE, ACE_UTF_32LE,
                       ACE_UTF_16BE, ACE_UTF_16LE,
                       ACE_UTF_8, ACE_NONE
                     };

  /// Create an encoding converter based on the source.  If a hint is
  /// given, it just creates the specified type of converter without looking
  /// at the source.
  static ACE_Encoding_Converter* create (const ACE_Byte* source,
                                         size_t source_size,
                                         Encoding_Hint hint = ACE_NONE);
};

ACE_END_VERSIONED_NAMESPACE_DECL
#endif /* ACE_USES_WCHAR */

#include /**/ "ace/post.h"

#endif /* ACE_ENCODING_CONVERTER_FACTORY_H */

