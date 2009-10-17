// -*- C++ -*-
//=============================================================================
/**
 *  @file    Svc_Conf.h
 *
 *  $Id: Svc_Conf.h 81332 2008-04-10 22:47:04Z iliyan $
 *
 *  @author Doug Schmidt
 */
//=============================================================================

#ifndef ACE_SVC_CONF_H
#define ACE_SVC_CONF_H
#include /**/ "ace/pre.h"
#include "ace/Service_Config.h"
#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */
#include "ace/Parse_Node.h"
#include "ace/Svc_Conf_Param.h"
// Make sure the yacc(1) function declarations are _outside_
// any ACE versioned namespace. The block below is verbatim
// from the template that comes with bison (ver. 2.3).
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int ace_yyparse (void *YYPARSE_PARAM);
#else
int ace_yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int ace_yyparse (void);
#else
int ace_yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL
#if (ACE_USES_CLASSIC_SVC_CONF == 1)
// The following yylex() declarations require support for reentrant
// parser generation (e.g. from GNU Bison).
#define YY_DECL extern "C" int ace_yylex (YYSTYPE *ace_yylval, void *YYLEX_PARAM)
// Forward declarations
class ACE_Location_Node;
class ACE_Parse_Node;
class ACE_Static_Node;
class ACE_Service_Type_Factory;
// The following definition for the YYSTYPE must occur before
// YY_DECL is declared since YY_DECL expands to function
// prototypes that use YYSTYPE.
typedef union
{
  int type_;
  ACE_Location_Node *location_node_;
  ACE_Parse_Node *parse_node_;
  ACE_Static_Node *static_node_;
  ACE_Service_Type_Factory *svc_record_;
  ACE_TCHAR *ident_;
} YYSTYPE;
#define YYSTYPE_IS_DECLARED
// Forward declaration
struct ace_yy_buffer_state;
/// Performs the lexical analysis
YY_DECL;
/// Name of input stream
extern FILE *ace_yyin;
/// Error handling routines required by YACC or BISON
extern void ace_yyerror (ACE_TCHAR const *);
extern void ace_yyerror (int yyerrno, int yylineno, ACE_TCHAR const *);
/// Holds the lexeme for the current token
extern ACE_TCHAR *ace_yytext;
/// Holds the length of the lexeme for the current token
extern int ace_yyleng;
#endif /* ACE_USES_CLASSIC_SVC_CONF == 1 */
/// Factory that creates a new ACE_Service_Type_Impl.
extern ACE_Service_Type_Impl *
ace_create_service_type (ACE_TCHAR const *,
                         int,
                         void *,
                         unsigned int,
                         ACE_Service_Object_Exterminator = 0);

ACE_END_VERSIONED_NAMESPACE_DECL
#include /**/ "ace/post.h"
#endif /* ACE_SVC_CONF_H */

