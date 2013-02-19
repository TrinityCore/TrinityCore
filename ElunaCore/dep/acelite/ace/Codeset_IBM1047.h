// -*- C++ -*-

//=============================================================================
/**
 *  @file    Codeset_IBM1047.h
 *
 *  $Id: Codeset_IBM1047.h 81388 2008-04-23 14:02:05Z johnnyw $
 *
 *  Declares the arrays required to convert between ISO8859 (aka
 *  Latin/1) and IBM1047 (aka EBCDIC).
 *
 *  @author Jim Rogers (jrogers@viasoft.com)
 */
//=============================================================================


#ifndef ACE_CODESET_IMB1047_H
#define ACE_CODESET_IMB1047_H
#include /**/ "ace/pre.h"

#include /**/ "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if defined (ACE_HAS_EBCDIC)

#include "ace/CDR_Stream.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

// ****************************************************************

/**
 * @class ACE_IBM1047_ISO8859
 *
 * @brief Codeset translation specialization.
 *
 * This class performs the codeset translation:
 *   - Native:        IBM_1047 (i.e. EBCDIC)
 *   - Stream:        ISO-8859 (i.e. Latin/1)
 */
class ACE_Export ACE_IBM1047_ISO8859 : public ACE_Char_Codeset_Translator
{
public:
  /// A do nothing constructor.
  ACE_IBM1047_ISO8859 (void);

  /// Virtual destruction
  virtual ~ACE_IBM1047_ISO8859 (void);

  // = Documented in $ACE_ROOT/ace/CDR_Stream.h
  virtual ACE_CDR::Boolean read_char (ACE_InputCDR &,
                                      ACE_CDR::Char &);
  virtual ACE_CDR::Boolean read_string (ACE_InputCDR &,
                                        ACE_CDR::Char *&);
  virtual ACE_CDR::Boolean read_char_array (ACE_InputCDR &,
                                            ACE_CDR::Char *,
                                            ACE_CDR::ULong);
  virtual ACE_CDR::Boolean write_char (ACE_OutputCDR &,
                                       ACE_CDR::Char);
  virtual ACE_CDR::Boolean write_string (ACE_OutputCDR &,
                                         ACE_CDR::ULong,
                                         const ACE_CDR::Char *);
  virtual ACE_CDR::Boolean write_char_array (ACE_OutputCDR &,
                                             const ACE_CDR::Char *,
                                             ACE_CDR::ULong);

  /// Return the native codeset ID as defined in the OSF code and character
  /// set registry, 0x10020417
  virtual ACE_CDR::ULong ncs ();
  /// Return the translated codeset ID as defined in the OSF code and character
  /// set registry, 0x00010001
  virtual ACE_CDR::ULong tcs ();
};

/**
 * @class ACE_ISO8859_IBM1047
 *
 * @brief Codeset translation specialization.
 *
 * This class performs the codeset translation:
 *   - Native:        ISO-8859 (i.e. Latin/1)
 *   - Stream:        IBM-1047 (i.e. EBCDIC)
 */
class ACE_Export ACE_ISO8859_IBM1047 : public ACE_Char_Codeset_Translator
{
public:
  /// A do nothing constructor.
  ACE_ISO8859_IBM1047 (void);

  /// Virtual destruction
  virtual ~ACE_ISO8859_IBM1047 (void);

  // = Documented in $ACE_ROOT/ace/CDR_Stream.h
  virtual ACE_CDR::Boolean read_char (ACE_InputCDR &,
                                      ACE_CDR::Char &);
  virtual ACE_CDR::Boolean read_string (ACE_InputCDR &,
                                        ACE_CDR::Char *&);
  virtual ACE_CDR::Boolean read_char_array (ACE_InputCDR &,
                                            ACE_CDR::Char *,
                                            ACE_CDR::ULong);
  virtual ACE_CDR::Boolean write_char (ACE_OutputCDR &,
                                       ACE_CDR::Char);
  virtual ACE_CDR::Boolean write_string (ACE_OutputCDR &,
                                         ACE_CDR::ULong,
                                         const ACE_CDR::Char *);
  virtual ACE_CDR::Boolean write_char_array (ACE_OutputCDR &,
                                             const ACE_CDR::Char *,
                                             ACE_CDR::ULong);

  /// Return the native codeset ID as defined in the OSF code and character
  /// set registry, 0x00010001
  virtual ACE_CDR::ULong ncs ();
  /// Return the translated codeset ID as defined in the OSF code and character
  /// set registry, 0x10020417
  virtual ACE_CDR::ULong tcs ();
};

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_EBCDIC */

#include /**/ "ace/post.h"

#endif /* ACE_CODESET_IMB1047_H */
