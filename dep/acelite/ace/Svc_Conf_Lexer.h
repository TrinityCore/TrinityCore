// -*- C++ -*-

//=========================================================================
/**
 * @file Svc_Conf_Lexer.h
 *
 * $Id: Svc_Conf_Lexer.h 81312 2008-04-09 21:01:34Z iliyan $
 *
 * This class is a hand-coded replacement for the lexer generated from
 * Svc_Conf.l that correctly supports Unicode.
 *
 * @author Chad Elliott <elliott_c@ociweb.com>
 */
//=========================================================================

#ifndef SVC_CONF_LEXER_H
#define SVC_CONF_LEXER_H

#include /**/ "ace/pre.h"
#include "ace/Svc_Conf.h"

#if (ACE_USES_CLASSIC_SVC_CONF == 1)
#include "ace/Encoding_Converter_Factory.h"

class ACE_Encoding_Converter;

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/** This class lexes the classic ACE Service Configurator language.
 * The entry point is similar to what flex would generate.  However, it
 * is a static method in this class (which is really just name space).
 */
class ACE_Svc_Conf_Lexer
{
public:
  /// This is similar to the C function, ace_yylex, which a bison
  /// generated parser expects.  It returns information in the ace_yylval
  /// parameter and uses input stored in the param parameter.
  static int yylex (YYSTYPE* ace_yylval,
                    ACE_Svc_Conf_Param* param);

private:
  static size_t input(ACE_Svc_Conf_Param* param, char* buf, size_t max_size);

  static int scan (YYSTYPE* ace_yylval, ACE_Svc_Conf_Param* param);

#if defined (ACE_USES_WCHAR)
  static bool convert_to_utf8 (
                   ACE_Svc_Conf_Param* param,
                   size_t skip_bytes,
                   ACE_Encoding_Converter_Factory::Encoding_Hint hint);
  static bool convert_from_utf8 (ACE_Encoding_Converter* converter,
                                 const char* source,
                                 size_t source_size,
                                 ACE_TCHAR* target,
                                 size_t target_size,
                                 size_t& length);
  static ACE_Encoding_Converter_Factory::Encoding_Hint
                   locate_bom (char* source,
                               size_t source_size,
                               size_t& bytes_used);
#endif /* ACE_USES_WCHAR */
};

ACE_END_VERSIONED_NAMESPACE_DECL
#endif /* ACE_USES_CLASSIC_SVC_CONF = 1 */

#include /**/ "ace/post.h"

#endif /* SVC_CONF_LEXER_H */
