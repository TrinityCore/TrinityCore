#include "ace/Codecs.h"
#include "ace/Log_Msg.h"
#include "ace/OS_Memory.h"
#include "ace/OS_NS_ctype.h"
ACE_RCSID (ace,
           Codecs,
           "$Id: Codecs.cpp 80826 2008-03-04 14:51:23Z wotte $")
namespace
{
  // Just in case ...
#undef alphabet
#undef pad
#undef max_columns
  // Symbols which form the Base64 alphabet (Defined as per RFC 2045)
  ACE_Byte const alphabet[] =
     "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
  // The padding character used in the encoding
  ACE_Byte const pad = '=';
  // Number of columns per line of encoded output (Can have a maximum
  // value of 76).
  int const max_columns = 72;
}
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
bool ACE_Base64::init_ = false;
ACE_Byte ACE_Base64::decoder_[256];
ACE_Byte ACE_Base64::member_[256];
ACE_Byte*
ACE_Base64::encode (const ACE_Byte* input,
                    const size_t input_len,
                    size_t* output_len,
                    bool is_chunked)
{
  if (!ACE_Base64::init_)
    ACE_Base64::init();
  if (!input)
    return 0;
  ACE_Byte* result = 0;
  size_t length = ((input_len + 2) / 3) * 4;
  size_t num_lines = length / max_columns + 1;
  length += num_lines + 1;
  ACE_NEW_RETURN (result, ACE_Byte[length], 0);
  int char_count = 0;
  int bits = 0;
  size_t pos = 0;
  int cols = 0;
  for (size_t i = 0; i < input_len; ++i)
    {
      bits += input[i];
      ++char_count;
      if (char_count == 3)
        {
          result[pos++] = alphabet[bits >> 18];
          result[pos++] = alphabet[(bits >> 12) & 0x3f];
          result[pos++] = alphabet[(bits >> 6) & 0x3f];
          result[pos++] = alphabet[bits & 0x3f];
          cols += 4;
          if (cols == max_columns) {
            if (is_chunked)
              result[pos++] = '\n';
            cols = 0;
          }
          bits = 0;
          char_count = 0;
        }
      else
        {
          bits <<= 8;
        }
    }
  if (char_count != 0)
    {
      bits <<= (16 - (8 * char_count));
      result[pos++] = alphabet[bits >> 18];
      result[pos++] = alphabet[(bits >> 12) & 0x3f];
      cols += 2;
      if (char_count == 1)
        {
          result[pos++] = pad;
          result[pos++] = pad;
          cols += 2;
        }
      else
        {
          result[pos++] = alphabet[(bits >> 6) & 0x3f];
          result[pos++] = pad;
          cols += 2;
        }
    }
  if (cols > 0 && is_chunked)
    result[pos++] = '\n';
  result[pos] = 0;
  *output_len = pos;
  return result;
}
size_t
ACE_Base64::length (const ACE_Byte* input)
{
  if (!ACE_Base64::init_)
    ACE_Base64::init();
  ACE_Byte* ptr = const_cast<ACE_Byte*> (input);
  while (*ptr != 0 &&
         (member_[*(ptr)] == 1 || *ptr == pad
          || ACE_OS::ace_isspace (*ptr)))
    ++ptr;
  size_t len = ptr - input;
  len = ((len + 3) / 4) * 3 + 1 ;
  return len;
}
ACE_Byte*
ACE_Base64::decode (const ACE_Byte* input, size_t* output_len)
{
  if (!ACE_Base64::init_)
    ACE_Base64::init();
  if (!input)
    return 0;
  size_t result_len = ACE_Base64::length (input);
  ACE_Byte* result = 0;
  ACE_NEW_RETURN (result, ACE_Byte[result_len], 0);
  ACE_Byte* ptr = const_cast<ACE_Byte*> (input);
  while (*ptr != 0 &&
         (member_[*(ptr)] == 1 || *ptr == pad
          || ACE_OS::ace_isspace (*ptr)))
    ++ptr;
  size_t input_len = ptr - input;
  int char_count = 0;
  int bits = 0;
  size_t pos = 0;
  size_t i = 0;
  for (; i < input_len; ++i)
    {
      if (input[i] == pad)
        break;
      if (!ACE_Base64::member_[input[i]])
        continue;
      bits += decoder_[input[i]];
      ++char_count;
      if (char_count == 4)
        {
          result[pos++] = static_cast<ACE_Byte> (bits >> 16);
          result[pos++] = static_cast<ACE_Byte> ((bits >> 8) & 0xff);
          result[pos++] = static_cast<ACE_Byte> (bits & 0xff);
          bits = 0;
          char_count = 0;
        }
      else
        {
          bits <<= 6;
        }
    }
  int errors = 0;
  if ( i == input_len)
    {
      if (char_count)
        {
          ACE_ERROR ((LM_ERROR,
                      ACE_TEXT ("Decoding incomplete: atleast %d bits truncated\n"),
                      (4 - char_count) * 6));
          ++errors;
        }
    }
  else
    {
      switch (char_count)
        {
        case 1:
          ACE_ERROR ((LM_ERROR,
                      ACE_TEXT ("Decoding incomplete: atleast 2 bits missing\n")));
          ++errors;
          break;
        case 2:
          result[pos++] = static_cast<ACE_Byte> (bits >> 10);
          break;
        case 3:
          result[pos++] = static_cast<ACE_Byte> (bits >> 16);
          result[pos++] = static_cast<ACE_Byte> ((bits >> 8) & 0xff);
          break;
        }
    }
  if (errors)
    {
      delete[] result;
      return 0;
    }
  result[pos] = 0;
  *output_len = pos;
  return result;
}
void
ACE_Base64::init ()
{
  if (!ACE_Base64::init_)
    {
      for (ACE_Byte i = 0; i < sizeof (alphabet); ++i)
        {
          ACE_Base64::decoder_[alphabet[i]] = i;
          ACE_Base64::member_ [alphabet[i]] = 1;
        }
      ACE_Base64::init_ = true;
    }
  return;
}
ACE_END_VERSIONED_NAMESPACE_DECL

