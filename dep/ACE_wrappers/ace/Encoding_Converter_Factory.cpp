// $Id: Encoding_Converter_Factory.cpp 80826 2008-03-04 14:51:23Z wotte $
#include "ace/Encoding_Converter_Factory.h"

#if defined (ACE_USES_WCHAR)
#include "ace/UTF32_Encoding_Converter.h"
#include "ace/UTF16_Encoding_Converter.h"
#include "ace/UTF8_Encoding_Converter.h"
#include "ace/OS_Memory.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_Encoding_Converter*
ACE_Encoding_Converter_Factory::create (
                       const ACE_Byte* source,
                       size_t source_size,
                       ACE_Encoding_Converter_Factory::Encoding_Hint hint)
{
#if defined (ACE_BIG_ENDIAN)
  bool const convert_for_bigendian = true;
#else
  bool const convert_for_bigendian = false;
#endif /* ACE_BIG_ENDIAN */
  ACE_Encoding_Converter* converter = 0;

  switch (hint)
    {
    case ACE_UTF_32BE:
      ACE_NEW_RETURN (converter,
                      ACE_UTF32_Encoding_Converter (!convert_for_bigendian),
                      0);
      break;
    case ACE_UTF_32LE:
      ACE_NEW_RETURN (converter,
                      ACE_UTF32_Encoding_Converter (convert_for_bigendian),
                      0);
      break;
    case ACE_UTF_16BE:
      ACE_NEW_RETURN (converter,
                      ACE_UTF16_Encoding_Converter (!convert_for_bigendian),
                      0);
      break;
    case ACE_UTF_16LE:
      ACE_NEW_RETURN (converter,
                      ACE_UTF16_Encoding_Converter (convert_for_bigendian),
                      0);
      break;
    case ACE_UTF_8:
      ACE_NEW_RETURN (converter,
                      ACE_UTF8_Encoding_Converter,
                      0);
      break;
    default:
      // First check for ASCII since much of ASCII text will appear to
      // convert from UTF-16 to UTF-8.
      converter = ACE_UTF8_Encoding_Converter::encoded (source, source_size);
      if (converter != 0)
        return converter;

      // Check for UTF-32
      converter = ACE_UTF32_Encoding_Converter::encoded (source, source_size);
      if (converter != 0)
        return converter;

      // Check for UTF-16
      converter = ACE_UTF16_Encoding_Converter::encoded (source, source_size);
      if (converter != 0)
        return converter;
    }

  return converter;
}

ACE_END_VERSIONED_NAMESPACE_DECL
#endif /* ACE_USES_WCHAR */

