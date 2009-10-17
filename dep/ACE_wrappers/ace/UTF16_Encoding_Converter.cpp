// $Id: UTF16_Encoding_Converter.cpp 80826 2008-03-04 14:51:23Z wotte $
// ======================================================================
//
// The actual conversion methods are covered by the copyright information
// below.  It is not the actual code provided by Unicode, Inc. but is an
// ACE-ified and only slightly modified version.
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
#include "ace/UTF16_Encoding_Converter.h"
#if defined (ACE_USES_WCHAR)
#include "ace/OS_NS_stdio.h"
#include "ace/OS_Memory.h"
#include "ace/Min_Max.h"
#if !defined (__ACE_INLINE__)
#include "ace/UTF16_Encoding_Converter.inl"
#endif /* __ACE_INLINE__ */
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
static const ACE_UINT32 halfShift = 10;
static const ACE_UINT32 halfBase  = 0x00010000;
static const ACE_UINT32 halfMask  = 0x000003FF;
static const ACE_UINT32 UNI_SUR_HIGH_START   = 0x0000D800;
static const ACE_UINT32 UNI_SUR_HIGH_END     = 0x0000DBFF;
static const ACE_UINT32 UNI_SUR_LOW_START    = 0x0000DC00;
static const ACE_UINT32 UNI_SUR_LOW_END      = 0x0000DFFF;
static const ACE_UINT32 UNI_REPLACEMENT_CHAR = 0x0000FFFD;
static const ACE_UINT32 UNI_MAX_BMP          = 0x0000FFFF;
static const ACE_UINT32 UNI_MAX_UTF16        = 0x0010FFFF;
// Once the bits are split out into bytes of UTF-8, this is a mask OR-ed
// into the first byte, depending on how many bytes follow.  There are
// as many entries in this table as there are UTF-8 sequence types.
// (I.e., one byte sequence, two byte... etc.). Remember that sequencs
// for *legal* UTF-8 will be 4 or fewer bytes total.
static const ACE_Byte firstByteMark[7] = { 0x00, 0x00, 0xC0,
                                           0xE0, 0xF0, 0xF8, 0xFC };
// Index into the table below with the first byte of a UTF-8 sequence to
// get the number of trailing bytes that are supposed to follow it.
// Note that *legal* UTF-8 values can't have 4 or 5-bytes. The table is
// left as-is for anyone who may want to do such conversion, which was
// allowed in earlier algorithms.
static const ACE_Byte trailingBytesForUTF8[256] = {
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
    2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2, 3,3,3,3,3,3,3,3,4,4,4,4,5,5,5,5
};
// Magic values subtracted from a buffer value during UTF8 conversion.
// This table contains as many values as there might be trailing bytes
// in a UTF-8 sequence.
static const ACE_UINT32 offsetsFromUTF8[6] = { 0x00000000, 0x00003080,
                                               0x000E2080, 0x03C82080,
                                               0xFA082080, 0x82082080 };

ACE_UTF16_Encoding_Converter::ACE_UTF16_Encoding_Converter (bool swap)
 : swap_ (swap)
{
}
ACE_UTF16_Encoding_Converter::~ACE_UTF16_Encoding_Converter (void)
{
}
ACE_UTF16_Encoding_Converter::Result
ACE_UTF16_Encoding_Converter::to_utf8 (const void* source,
                                       size_t source_size,
                                       ACE_Byte* target,
                                       size_t target_size,
                                       bool strict)
{
  static const ACE_UINT32 byteMask = 0xBF;
  static const ACE_UINT32 byteMark = 0x80;
  Result result = CONVERSION_OK;
  ACE_Byte* targetEnd = target + target_size;
  const ACE_UINT16* sourceStart = static_cast<const ACE_UINT16*> (source);
  const ACE_UINT16* sourceEnd   = sourceStart +
                                  (source_size / sizeof (ACE_UINT16));
  while (sourceStart < sourceEnd)
    {
      ACE_UINT16 nw = *sourceStart++;
      ACE_UINT32 ch = (this->swap_ ? ACE_SWAP_WORD (nw) : nw);
      // If we have a surrogate pair, convert to ACE_UINT32 first.
      if (ch >= UNI_SUR_HIGH_START && ch <= UNI_SUR_HIGH_END)
        {
          // If the 16 bits following the high surrogate are in the
          // sourceStart buffer...
          if (sourceStart < sourceEnd)
            {
              ACE_UINT32 ch2 = (this->swap_ ? ACE_SWAP_WORD (*sourceStart) :
                                              *sourceStart);
              // If it's a low surrogate, convert to ACE_UINT32.
              if (ch2 >= UNI_SUR_LOW_START && ch2 <= UNI_SUR_LOW_END)
                {
                  ch = ((ch - UNI_SUR_HIGH_START) << halfShift)
                    + (ch2 - UNI_SUR_LOW_START) + halfBase;
                  ++sourceStart;
                }
              else if (strict)
                {
                  // it's an unpaired high surrogate
                  result = SOURCE_ILLEGAL;
                  break;
                }
            }
          else
            {
              // We don't have the 16 bits following the high surrogate.
              result = SOURCE_EXHAUSTED;
              break;
            }
        }
      else if (strict)
        {
          // UTF-16 surrogate values are illegal in UTF-32
          if (ch >= UNI_SUR_LOW_START && ch <= UNI_SUR_LOW_END)
            {
              result = SOURCE_ILLEGAL;
              break;
            }
        }
      // Figure out how many bytes the result will require
      unsigned short bytesToWrite = 0;
      if (ch < 0x80)
        bytesToWrite = 1;
      else if (ch < 0x800)
        bytesToWrite = 2;
      else if (ch < 0x10000)
        bytesToWrite = 3;
      else if (ch < 0x110000)
        bytesToWrite = 4;
      else
        {
          bytesToWrite = 3;
          ch = UNI_REPLACEMENT_CHAR;
        }
      target += bytesToWrite;
      if (target > targetEnd)
        {
          result = TARGET_EXHAUSTED;
          break;
        }
      // NOTE: Everything falls through for efficiency purposes.
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
          *--target = (ACE_Byte)(ch | firstByteMark[bytesToWrite]);
        }
      target += bytesToWrite;
    }
  return result;
}
ACE_UTF16_Encoding_Converter::Result
ACE_UTF16_Encoding_Converter::from_utf8 (const ACE_Byte* source,
                                         size_t source_size,
                                         void* target,
                                         size_t target_size,
                                         bool strict)
{
  Result result = CONVERSION_OK;
  const ACE_Byte* sourceEnd = source + source_size;
  ACE_UINT16* targetStart   = static_cast<ACE_UINT16*> (target);
  ACE_UINT16* targetEnd     = targetStart + target_size;
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
        case 5: // remember, illegal UTF-8
          ch += *source++;
          ch <<= 6;
        case 4: // remember, illegal UTF-8
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
      if (ch <= UNI_MAX_BMP) // Target is a character <= 0xFFFF
        {
          // UTF-16 surrogate values are illegal in UTF-32
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
              *targetStart++ = (ACE_UINT16)ch;
            }
        }
      else if (ch > UNI_MAX_UTF16)
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
          // targetStart is a character in range 0xFFFF - 0x10FFFF.
          if (targetStart + 1 >= targetEnd)
            {
              result = TARGET_EXHAUSTED;
              break;
            }
          ch -= halfBase;
          *targetStart++ = (ACE_UINT16)((ch >> halfShift) + UNI_SUR_HIGH_START);
          *targetStart++ = (ACE_UINT16)((ch & halfMask) + UNI_SUR_LOW_START);
        }
    }
  return result;
}
ACE_UTF16_Encoding_Converter*
ACE_UTF16_Encoding_Converter::encoded (const ACE_Byte* source,
                                       size_t source_size)
{
  static const size_t begin = 16;
  static const size_t converted = begin * 4;
  ACE_Byte target[converted];
  ACE_UTF16_Encoding_Converter* converter;
  ACE_NEW_RETURN (converter,
                  ACE_UTF16_Encoding_Converter (false),
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
ACE_UINT32
ACE_UTF16_Encoding_Converter::get_UNI_SUR_HIGH_START (void)
{
  return UNI_SUR_HIGH_START;
}
ACE_UINT32
ACE_UTF16_Encoding_Converter::get_UNI_SUR_LOW_END (void)
{
  return UNI_SUR_LOW_END;
}
ACE_UINT32
ACE_UTF16_Encoding_Converter::get_UNI_REPLACEMENT_CHAR (void)
{
  return UNI_REPLACEMENT_CHAR;
}
const ACE_Byte*
ACE_UTF16_Encoding_Converter::get_first_byte_mark (void)
{
  return firstByteMark;
}
const ACE_Byte*
ACE_UTF16_Encoding_Converter::get_trailing_bytes_for_utf8 (void)
{
  return trailingBytesForUTF8;
}
const ACE_UINT32*
ACE_UTF16_Encoding_Converter::get_offsets_from_utf8 (void)
{
  return offsetsFromUTF8;
}
ACE_END_VERSIONED_NAMESPACE_DECL
#endif /* ACE_USES_WCHAR */

