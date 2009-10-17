// -*- C++ -*-

//=============================================================================
/**
 *  @file   Codecs.h
 *
 *  $Id: Codecs.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Krishnakumar B <kitty@cs.wustl.edu>
 *
 *  Codecs is a generic wrapper for various encoding and decoding
 *  mechanisms. Currently it includes Base64 content transfer-encoding as
 *  specified by RFC 2045, Multipurpose Internet Mail Extensions (MIME) Part
 *  One: Format of Internet Message Bodies.
 *
 */
//=============================================================================

#ifndef ACE_CODECS_H
#define ACE_CODECS_H

#include /**/ "ace/pre.h"

#include /**/ "ace/ACE_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/Basic_Types.h"
#include "ace/Global_Macros.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class ACE_Base64
 *
 * @brief Encode/Decode a stream of bytes according to Base64 encoding.
 *
 * This class provides methods to encode or decode a stream of bytes
 * to/from Base64 encoding. It doesn't convert the input stream to a
 * canonical form before encoding.
 *
 */
class ACE_Export ACE_Base64
{
public:

  //@{

  /**
   * Encodes a stream of bytes to Base64 data
   *
   * @param input Binary data in byte stream.
   * @param input_len Length of the byte stream.
   * @param output_len Length of the encoded Base64 byte stream.
   * @param is_chunked If true, terminate 72 character blocks with newline
   * @return Encoded Base64 data in byte stream or NULL if input data cannot
   *         be encoded.
   */

  static ACE_Byte* encode (const ACE_Byte* input,
                           const size_t input_len,
                           size_t* output_len,
                           bool is_chunked = true);
  /**
   * Decodes a stream of Base64 to bytes data
   *
   * @param input Encoded Base64 data in byte stream.
   * @param output_len Length of the binary byte stream.
   * @return Binary data in byte stream or NULL if input data cannot
   *         be encoded.
   */
  static ACE_Byte* decode (const ACE_Byte* input,
                           size_t* output_len);

  /**
   * Return the length of the encoded input data
   *
   * @param input Encoded Base64 data in byte stream.
   * @return Length of the encoded Base64 data.
   *
   */
  static size_t length (const ACE_Byte* input);

  //@}

protected:

  // Prevent default construction.
  ACE_Base64 (void) {}

private:

  // Preventing copying and assignment.
  ACE_Base64 (ACE_Base64 const &);
  ACE_Base64 & operator= (ACE_Base64 const &);

  /// Initialize the tables for encoding/decoding.
  static void init (void);

private:

  /// Alphabet used for decoding i.e decoder_[alphabet_[i = 0..63]] = i
  static ACE_Byte decoder_[];

  /// Alphabet used to check valid range of encoded input i.e
  /// member_[alphabet_[0..63]] = 1
  static ACE_Byte member_[];

  /// Boolean to denote whether initialization is complete
  static bool init_;

};

ACE_END_VERSIONED_NAMESPACE_DECL

#include /**/ "ace/post.h"

#endif /* ACE_CODECS_H */

