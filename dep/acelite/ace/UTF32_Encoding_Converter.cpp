// $Id: UTF32_Encoding_Converter.cpp 80826 2008-03-04 14:51:23Z wotte $

// ======================================================================
//
// The actual conversion methods are covered by the copyright information
// below.  It is not the actual code provided by Unicode, Inc. but is an
// ACE-ified and only slightly modified version.
//
// Chad Elliott 4/28/2005
//
// Copyright 2001-2004 Unicode, Inc.
//
// Limitations on Rights to Redistribute This Code
//
// Unicode, Inc. hereby grants the right to freely use the information
// supplied in this file in the creation of products supporting the
// Unicode Standard, and to make copies of this file in any form
// for internal or external distribution as long as this notice
// remains attached.
//
// ======================================================================

#include "ace/UTF32_Encoding_Converter.h"

#if defined (ACE_USES_WCHAR)
#include "ace/OS_NS_stdio.h"
#include "ace/OS_Memory.h"
#include "ace/Min_Max.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

static const ACE_UINT32 UNI_MAX_LEGAL_UTF32 = 0x0010FFFF;

ACE_UTF32_Encoding_Converter::ACE_UTF32_Encoding_Converter (bool swap)
 : ACE_UTF16_Encoding_Converter (swap)
{
}

ACE_UTF32_Encoding_Converter::~ACE_UTF32_Encoding_Converter (void)
{
}

ACE_UTF32_Encoding_Converter::Result
ACE_UTF32_Encoding_Converter::to_utf8 (const void* source,
                                       size_t source_size,
                                       ACE_Byte* target,
                                       size_t target_size,
                                       bool strict)
{
  static const ACE_UINT32 byteMask = 0xBF;
  static const ACE_UINT32 byteMark = 0x80;
  static const ACE_UINT32 UNI_SUR_HIGH_START = get_UNI_SUR_HIGH_START ();
  static const ACE_UINT32 UNI_SUR_LOW_END = get_UNI_SUR_LOW_END ();
  static const ACE_Byte* firstByteMark = get_first_byte_mark ();

  Result result = CONVERSION_OK;
  ACE_Byte* targetEnd = target + target_size;
  const ACE_UINT32* sourceStart = static_cast<const ACE_UINT32*> (source);
  const ACE_UINT32* sourceEnd = sourceStart + (source_size / sizeof (ACE_UINT32));

  while (sourceStart < sourceEnd)
    {
      ACE_UINT32 nw = *sourceStart++;
      ACE_UINT32 ch = (this->swap_ ? ACE_SWAP_LONG (nw) : nw);
      unsigned short bytesToWrite = 0;

      if (strict)
        {
          // UTF-16 surrogate values are illegal in UTF-32
          if (ch >= UNI_SUR_HIGH_START && ch <= UNI_SUR_LOW_END)
            {
              result = SOURCE_ILLEGAL;
              break;
            }
        }

      // Figure out how many bytes the result will require. Turn any
      // illegally large ACE_UINT32 things (> Plane 17) into replacement
      // chars.
      if (ch < 0x80)
        {
          bytesToWrite = 1;
        }
      else if (ch < 0x800)
        {
          bytesToWrite = 2;
        }
      else if (ch < 0x10000)
        {
          bytesToWrite = 3;
        }
      else if (ch <= UNI_MAX_LEGAL_UTF32)
        {
          bytesToWrite = 4;
        }
      else
        {
          result = SOURCE_ILLEGAL;
          break;
        }

      target += bytesToWrite;
      if (target > targetEnd)
        {
          result = TARGET_EXHAUSTED;
          break;
        }

      // NOTE: everything falls through.
      switch (bytesToWrite)
        {
        case 4:
          *--target = (ACE_Byte)((ch | byteMark) & byteMask);
          ch >>= 6;
        case 3:
          *--target = (ACE_Byte)((ch | byteMark) & byteMask);
          ch >>= 6;
        case 2:
          *--target = (ACE_Byte)((ch | byteMark) & byteMask);
          ch >>= 6;
        case 1:
          *--target = (ACE_Byte) (ch | firstByteMark[bytesToWrite]);
      }
      target += bytesToWrite;
    }

  return result;
}

ACE_UTF32_Encoding_Converter::Result
ACE_UTF32_Encoding_Converter::from_utf8 (const ACE_Byte* source,
                                         size_t source_size,
                                         void* target,
                                         size_t target_size,
                                         bool strict)
{
  static const ACE_UINT32 UNI_SUR_HIGH_START = get_UNI_SUR_HIGH_START ();
  static const ACE_UINT32 UNI_SUR_LOW_END = get_UNI_SUR_LOW_END ();
  static const ACE_UINT32 UNI_REPLACEMENT_CHAR = get_UNI_REPLACEMENT_CHAR ();
  static const ACE_Byte* trailingBytesForUTF8 = get_trailing_bytes_for_utf8 ();
  static const ACE_UINT32* offsetsFromUTF8 = get_offsets_from_utf8 ();

  Result result = CONVERSION_OK;
  const ACE_Byte* sourceEnd = source + source_size;
  ACE_UINT32* targetStart = static_cast<ACE_UINT32*> (target);
  ACE_UINT32* targetEnd   = targetStart + target_size;

  while (source < sourceEnd)
    {
      ACE_UINT32 ch = 0;
      unsigned short extraBytesToRead = trailingBytesForUTF8[*source];
      if (source + extraBytesToRead >= sourceEnd)
        {
          result = SOURCE_EXHAUSTED;
          break;
        }

      // Do this check whether lenient or strict
      if (!this->is_legal_utf8 (source, extraBytesToRead + 1))
        {
          result = SOURCE_ILLEGAL;
          break;
        }

      // The cases all fall through. See "Note A" below.
      switch (extraBytesToRead)
        {
        case 5:
          ch += *source++;
          ch <<= 6;
        case 4:
          ch += *source++;
          ch <<= 6;
        case 3:
          ch += *source++;
          ch <<= 6;
        case 2:
          ch += *source++;
          ch <<= 6;
        case 1:
          ch += *source++;
          ch <<= 6;
        case 0:
          ch += *source++;
      }
      ch -= offsetsFromUTF8[extraBytesToRead];

      if (targetStart >= targetEnd)
        {
          result = TARGET_EXHAUSTED;
          break;
        }

      if (ch <= UNI_MAX_LEGAL_UTF32)
        {
          // UTF-16 surrogate values are illegal in UTF-32, and anything
          // over Plane 17 (> 0x10FFFF) is illegal.
          if (ch >= UNI_SUR_HIGH_START && ch <= UNI_SUR_LOW_END)
            {
              if (strict)
                {
                  result = SOURCE_ILLEGAL;
                  break;
                }
              else
                {
                  *targetStart++ = UNI_REPLACEMENT_CHAR;
                }
            }
          else
            {
              *targetStart++ = ch;
            }
        }
      else
        {
          result = SOURCE_ILLEGAL;
          break;
        }
    }

  return result;
}

ACE_UTF32_Encoding_Converter*
ACE_UTF32_Encoding_Converter::encoded (const ACE_Byte* source,
                                       size_t source_size)
{
  static const size_t begin = 16;
  static const size_t converted = begin * 4;

  ACE_Byte target[converted];
  ACE_UTF32_Encoding_Converter* converter = 0;
  ACE_NEW_RETURN (converter,
                  ACE_UTF32_Encoding_Converter (false),
                  0);

  if (converter->to_utf8 (source,
                          ACE_MIN (begin, source_size),
                          target,
                          converted) == CONVERSION_OK)
    {
      return converter;
    }
  else
    {
      delete converter;
    }

  return 0;
}

ACE_END_VERSIONED_NAMESPACE_DECL
#endif /* ACE_USES_WCHAR */
