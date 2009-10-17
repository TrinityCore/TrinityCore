// $Id: UTF8_Encoding_Converter.cpp 80826 2008-03-04 14:51:23Z wotte $
#include "ace/UTF8_Encoding_Converter.h"
#if defined (ACE_USES_WCHAR)
#include "ace/UTF16_Encoding_Converter.h"
#include "ace/UTF32_Encoding_Converter.h"
#include "ace/OS_NS_string.h"
#include "ace/OS_Memory.h"
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
ACE_UTF8_Encoding_Converter::ACE_UTF8_Encoding_Converter (void)
 : native_ (0)
{
  // Choose a converter for the ASCII or UTF-8 string to a wide character
  // string which we will use in from_utf8.  We have to make an
  // assumption here about the encoding based on the size of ACE_TCHAR.
  switch (sizeof (ACE_TCHAR))
    {
    case 4:
      ACE_NEW(this->native_, ACE_UTF32_Encoding_Converter);
      break;
    case 2:
      ACE_NEW(this->native_, ACE_UTF16_Encoding_Converter);
      break;
    }
}
ACE_UTF8_Encoding_Converter::~ACE_UTF8_Encoding_Converter (void)
{
  delete native_;
}
ACE_UTF8_Encoding_Converter::Result
ACE_UTF8_Encoding_Converter::to_utf8 (const void* source,
                                      size_t source_size,
                                      ACE_Byte* target,
                                      size_t target_size,
                                      bool /*strict*/)
{
  if (target_size >= source_size)
    {
      ACE_OS::memcpy (target, source, source_size);
      return CONVERSION_OK;
    }
  return TARGET_EXHAUSTED;
}
ACE_UTF8_Encoding_Converter::Result
ACE_UTF8_Encoding_Converter::from_utf8 (const ACE_Byte* source,
                                        size_t source_size,
                                        void* target,
                                        size_t target_size,
                                        bool strict)
{
  if (this->native_ != 0)
    {
      return this->native_->from_utf8(source, source_size,
                                      target, target_size, strict);
    }
  ACE_TCHAR* targetStart = static_cast<ACE_TCHAR*> (target);
  ACE_OS::strncpy (targetStart,
                   ACE_TEXT_CHAR_TO_TCHAR (
                     reinterpret_cast<const char*> (source)),
                   source_size);
  targetStart[source_size] = 0;
  return CONVERSION_OK;
}
ACE_UTF8_Encoding_Converter*
ACE_UTF8_Encoding_Converter::encoded (const ACE_Byte* source,
                                      size_t source_size)
{
  for(size_t i = 0; i < source_size; i++)
    {
      if (source[i] < 0x01 || source[i] > 0x7f)
        return 0;
    }
  // All characters are "valid" ASCII
  ACE_UTF8_Encoding_Converter* converter = 0;
  ACE_NEW_RETURN (converter,
                  ACE_UTF8_Encoding_Converter,
                  0);
  return converter;
}
ACE_END_VERSIONED_NAMESPACE_DECL
#endif /* ACE_USES_WCHAR */

