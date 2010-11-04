
//=============================================================================
/**
 *  @file    Codeset_IBM1047.cpp
 *
 *  $Id: Codeset_IBM1047.cpp 91286 2010-08-05 09:04:31Z johnnyw $
 *
 *  Defines the arrays required to convert between ISO8859 (aka
 *  Latin/1) and IBM1047 (aka EBCDIC).
 *
 *
 *  @author Jim Rogers (jrogers@viasoft.com)
 */
//=============================================================================


#include "ace/Codeset_IBM1047.h"

#if defined (ACE_HAS_EBCDIC)

#include "ace/OS_Memory.h"
#include "ace/OS_NS_string.h"

namespace
{
  char const to_IBM1047[] =
    {
  "\x00\x01\x02\x03\x37\x2D\x2E\x2F\x16\x05\x25\x0B\x0C\x0D\x0E\x0F" // 00-0F
  "\x10\x11\x12\x13\x3C\x3D\x32\x26\x18\x19\x3F\x27\x22\x1D\x35\x1F" // 10-1F
  "\x40\x5A\x7F\x7B\x5B\x6C\x50\x7D\x4D\x5D\x5C\x4E\x6B\x60\x4B\x61" // 20-2F
  "\xF0\xF1\xF2\xF3\xF4\xF5\xF6\xF7\xF8\xF9\x7A\x5E\x4C\x7E\x6E\x6F" // 30-3F
  "\x7C\xC1\xC2\xC3\xC4\xC5\xC6\xC7\xC8\xC9\xD1\xD2\xD3\xD4\xD5\xD6" // 40-4F
  "\xD7\xD8\xD9\xE2\xE3\xE4\xE5\xE6\xE7\xE8\xE9\xAD\xE0\xBD\x5F\x6D" // 50-5F
  "\x79\x81\x82\x83\x84\x85\x86\x87\x88\x89\x91\x92\x93\x94\x95\x96" // 60-6F
  "\x97\x98\x99\xA2\xA3\xA4\xA5\xA6\xA7\xA8\xA9\xC0\x4F\xD0\xA1\x07" // 70-7F
  "\x43\x20\x21\x1C\x23\xEB\x24\x9B\x71\x28\x38\x49\x90\xBA\xEC\xDF" // 80-8F
  "\x45\x29\x2A\x9D\x72\x2B\x8A\x9A\x67\x56\x64\x4A\x53\x68\x59\x46" // 90-9F
  "\xEA\xDA\x2C\xDE\x8B\x55\x41\xFE\x58\x51\x52\x48\x69\xDB\x8E\x8D" // A0-AF
  "\x73\x74\x75\xFA\x15\xB0\xB1\xB3\xB4\xB5\x6A\xB7\xB8\xB9\xCC\xBC" // B0-BF
  "\xAB\x3E\x3B\x0A\xBF\x8F\x3A\x14\xA0\x17\xCB\xCA\x1A\x1B\x9C\x04" // C0-CF
  "\x34\xEF\x1E\x06\x08\x09\x77\x70\xBE\xBB\xAC\x54\x63\x65\x66\x62" // D0-DF
  "\x30\x42\x47\x57\xEE\x33\xB6\xE1\xCD\xED\x36\x44\xCE\xCF\x31\xAA" // E0-EF
  "\xFC\x9E\xAE\x8C\xDD\xDC\x39\xFB\x80\xAF\xFD\x78\x76\xB2\x9F\xFF" // F0-FF
};

  char const from_IBM1047[] =
    {
  "\x00\x01\x02\x03\xCF\x09\xD3\x7F\xD4\xD5\xC3\x0B\x0C\x0D\x0E\x0F" // 00-0F
  "\x10\x11\x12\x13\xC7\xB4\x08\xC9\x18\x19\xCC\xCD\x83\x1D\xD2\x1F" // 10-1F
  "\x81\x82\x1C\x84\x86\x0A\x17\x1B\x89\x91\x92\x95\xA2\x05\x06\x07" // 20-2F
  "\x20\xEE\x16\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\xC1\x1A" // 30-3F
  "\x20\xA6\xE1\x80\xEB\x90\x9F\xE2\xAB\x8B\x9B\x2E\x3C\x28\x2B\x7C" // 40-4F
  "\x26\xA9\xAA\x9C\xDB\xA5\x99\xE3\xA8\x9E\x21\x24\x2A\x29\x3B\x5E" // 50-5F
  "\x2D\x2F\xDF\xDC\x9A\xDD\xDE\x98\x9D\xAC\xBA\x2C\x25\x5F\x3E\x3F" // 60-6F
  "\xD7\x88\x94\xB0\xB1\xB2\xFC\xD6\xFB\x60\x3A\x23\x40\x27\x3D\x22" // 70-7F
  "\xF8\x61\x62\x63\x64\x65\x66\x67\x68\x69\x96\xA4\xF3\xAF\xAE\xC5" // 80-8F
  "\x8C\x6A\x6B\x6C\x6D\x6E\x6F\x70\x71\x72\x97\x87\xCE\x93\xF1\xFE" // 90-9F
  "\xC8\x7E\x73\x74\x75\x76\x77\x78\x79\x7A\xEF\xC0\xDA\x5B\xF2\xF9" // A0-AF
  "\xB5\xB6\xFD\xB7\xB8\xB9\xE6\xBB\xBC\xBD\x8D\xD9\xBF\x5D\xD8\xC4" // B0-BF
  "\x7B\x41\x42\x43\x44\x45\x46\x47\x48\x49\xCB\xCA\xBE\xE8\xEC\xED" // C0-CF
  "\x7D\x4A\x4B\x4C\x4D\x4E\x4F\x50\x51\x52\xA1\xAD\xF5\xF4\xA3\x8F" // D0-DF
  "\x5C\xE7\x53\x54\x55\x56\x57\x58\x59\x5A\xA0\x85\x8E\xE9\xE4\xD1" // E0-EF
  "\x30\x31\x32\x33\x34\x35\x36\x37\x38\x39\xB3\xF7\xF0\xFA\xA7\xFF" // F0-FF
    };
}

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_IBM1047_ISO8859::ACE_IBM1047_ISO8859 (void)
{
}

ACE_IBM1047_ISO8859::~ACE_IBM1047_ISO8859 (void)
{
}

ACE_CDR::ULong
ACE_IBM1047_ISO8859::ncs ()
{
  return 0x10020417;
}

ACE_CDR::ULong
ACE_IBM1047_ISO8859::tcs ()
{
  return 0x00010001;
}

ACE_CDR::Boolean
ACE_IBM1047_ISO8859::read_char (ACE_InputCDR &in,
                                ACE_CDR::Char &x)
{
  if (this->read_1 (in, reinterpret_cast<ACE_CDR::Octet*> (&x)))
    {
      x = to_IBM1047[x];
      return 1;
    }
  return 0;
}

ACE_CDR::Boolean
ACE_IBM1047_ISO8859::read_string (ACE_InputCDR& in,
                                  ACE_CDR::Char *& x)
{
  ACE_CDR::ULong len;

  in.read_ulong (len);

  if (len > 0)
    {
      ACE_NEW_RETURN (x,
                      ACE_CDR::Char[len],
                      0);

      if (this->read_char_array (in, x, len))
        return 1;

      delete [] x;
    }

  x = 0;
  return 0;
}

ACE_CDR::Boolean
ACE_IBM1047_ISO8859::read_char_array (ACE_InputCDR& in,
                                      ACE_CDR::Char* x,
                                      ACE_CDR::ULong len)
{
  if (this->read_array (in,
                        x,
                        ACE_CDR::OCTET_SIZE,
                        ACE_CDR::OCTET_ALIGN,
                        len))
    {
      for (ACE_CDR::ULong i = 0; i != len; ++i)
        x[i] = to_IBM1047[x[i]];

      return 1;
    }

  return 0;
}

ACE_CDR::Boolean
ACE_IBM1047_ISO8859::write_char (ACE_OutputCDR& out,
                                 ACE_CDR::Char x)
{
  return
    this->write_1 (out,
                   reinterpret_cast<const ACE_CDR::Octet*> (&from_IBM1047[x]));
}

ACE_CDR::Boolean
ACE_IBM1047_ISO8859::write_string (ACE_OutputCDR& out,
                                   ACE_CDR::ULong len,
                                   const ACE_CDR::Char* x)
{
  if (out.write_ulong (len + 1))
    return this->write_char_array (out, x, len + 1);
  return 0;
}

ACE_CDR::Boolean
ACE_IBM1047_ISO8859::write_char_array (ACE_OutputCDR& out,
                                       const ACE_CDR::Char* x,
                                       ACE_CDR::ULong len)
{
  char *buf = 0;
  if (this->adjust (out, len, 1, buf) == 0)
    {
      ACE_OS::memcpy (buf, x, len);

      for (ACE_CDR::ULong i = 0; i != len; ++i)
        buf[i] = from_IBM1047[buf[i]];

      return 1;
    }

  this->good_bit(out, 0);
  return 0;
}

// ****************************************************************

ACE_ISO8859_IBM1047::ACE_ISO8859_IBM1047 (void)
{
}

ACE_ISO8859_IBM1047::~ACE_ISO8859_IBM1047 (void)
{
}

ACE_CDR::ULong
ACE_ISO8859_IBM1047::ncs ()
{
  return 0x00010001;
}

ACE_CDR::ULong
ACE_ISO8859_IBM1047::tcs ()
{
  return 0x10020417;
}

ACE_CDR::Boolean
ACE_ISO8859_IBM1047::read_char (ACE_InputCDR& in,
                                ACE_CDR::Char& x)
{
  if (this->read_1 (in, reinterpret_cast<ACE_CDR::Octet*> (&x)))
    {
      x = from_IBM1047[x];
      return 1;
    }
  return 0;
}

ACE_CDR::Boolean
ACE_ISO8859_IBM1047::read_string (ACE_InputCDR &in,
                                  ACE_CDR::Char *&x)
{
  ACE_CDR::ULong len;

  in.read_ulong (len);

  if (len > 0)
    {
      ACE_NEW_RETURN (x,
                      ACE_CDR::Char[len],
                      0);

      if (this->read_char_array (in, x, len))
        return 1;

      delete [] x;
    }

  x = 0;
  return 0;
}

ACE_CDR::Boolean
ACE_ISO8859_IBM1047::read_char_array (ACE_InputCDR &in,
                                      ACE_CDR::Char *x,
                                      ACE_CDR::ULong len)
{
  if (this->read_array (in,
                        x,
                        ACE_CDR::OCTET_SIZE,
                        ACE_CDR::OCTET_ALIGN,
                        len))
    {
      for (ACE_CDR::ULong i = 0; i != len; ++i)
        x[i] = from_IBM1047[x[i]];

      return 1;
    }

  return 0;
}

ACE_CDR::Boolean
ACE_ISO8859_IBM1047::write_char (ACE_OutputCDR &out,
                                 ACE_CDR::Char x)
{
  return
    this->write_1 (out,
                   reinterpret_cast<const ACE_CDR::Octet *> (&to_IBM1047[x]));
}

ACE_CDR::Boolean
ACE_ISO8859_IBM1047::write_string (ACE_OutputCDR& out,
                                   ACE_CDR::ULong len,
                                   const ACE_CDR::Char* x)
{
  if (out.write_ulong (len + 1))
    return this->write_char_array (out, x, len + 1);
  else
    return 0;
}

ACE_CDR::Boolean
ACE_ISO8859_IBM1047::write_char_array (ACE_OutputCDR &out,
                                       const ACE_CDR::Char *x,
                                       ACE_CDR::ULong len)
{
  char *buf = 0;

  if (this->adjust (out, len, 1, buf) == 0)
    {
      ACE_OS::memcpy (buf, x, len);

      for (ACE_CDR::ULong i = 0; i != len; ++i)
        buf[i] = to_IBM1047[buf[i]];

      return 1;
    }

  this->good_bit (out, 0);
  return 0;
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_HAS_EBCDIC */
