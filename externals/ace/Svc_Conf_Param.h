// -*- C++ -*-

//=============================================================================
/**
 *  @file    Svc_Conf_Param.h
 *
 *  $Id: Svc_Conf_Param.h 81312 2008-04-09 21:01:34Z iliyan $
 *
 *  @author Iliyan Jeliazkov <iliyan@ociweb.com>
 *  @author Based on code originally found in Svc_Conf.h by Doug
            Schmidt and Ossama Othman.
 */
//=============================================================================


#ifndef ACE_SVC_CONF_PARAM_H
#define ACE_SVC_CONF_PARAM_H

#include /**/ "ace/pre.h"

// Globally visible macros, type decls, and extern var decls for
// Service Configurator utility.

#include "ace/Obstack.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

// Forward declarations.
struct ace_yy_buffer_state;
class ACE_Service_Gestalt;

extern void ace_yy_delete_buffer (ace_yy_buffer_state *buffer);

/**
 * @class ACE_Svc_Conf_Param
 *
 * @brief An instance of this object will be passed down to the
 *        yyparse() and yylex() functions.
 *
 * This is intended for internal use within ACE service configuration
 * framework only.
 *
 * This class retains the state for a given parse/scan.  It primarily
 * makes it possible to hold the static object lock in the scanner
 * for as short a period of time as possible.  The resulting finer
 * grained locking prevents deadlocks from occuring when scanning a
 * `svc.conf' file and activating an ACE_Task, for example, as a
 * result of processing the directives in that file.
 */
class ACE_Svc_Conf_Param
{
public:

  enum SVC_CONF_PARAM_TYPE
    {
      /// The lexer will scan a file containing one or more directives.
      SVC_CONF_FILE,

      /// The lexer will scan a string containing a directive.
      SVC_CONF_DIRECTIVE
    };

  /// Constructor
  ACE_Svc_Conf_Param (ACE_Service_Gestalt* config, FILE *file)
    : type (SVC_CONF_FILE),
      yyerrno (0),
      yylineno (1),
      buffer (0),
      obstack (),
      config (config)
  {
    source.file = file;
  }

  /// Constructor
  ACE_Svc_Conf_Param (ACE_Service_Gestalt* config, const ACE_TCHAR *directive)
    : type (SVC_CONF_DIRECTIVE),
      yyerrno (0),
      yylineno (1),
      buffer (0),
      obstack (),
      config (config)
  {
    source.directive = directive;
  }

  ~ACE_Svc_Conf_Param (void)
  {
    ace_yy_delete_buffer (this->buffer);
  }

public:

  union
  {
    /// FILE stream from which directives will be scanned and parsed.
    FILE *file;

    /// String containing directive that will be scanned and parsed.
    const ACE_TCHAR *directive;

  } source;

  /// Discriminant use to determine which union member to use.
  SVC_CONF_PARAM_TYPE type;

  /// Keeps track of the number of errors encountered so far.
  int yyerrno;

  /// Keeps track of the current line number for error-handling routine.
  int yylineno;

  /// Lexer buffer that corresponds to the current Service
  /// Configurator file/direct scan.
  ace_yy_buffer_state *buffer;

  /// Obstack used for efficient memory allocation when
  /// parsing/scanning a service configurator directive.
  ACE_Obstack_T<ACE_TCHAR> obstack;

  /// A reference to the configuration
  ACE_Service_Gestalt *config;
};


// Parameter that is passed down to the yyparse() function, and
// eventually to yylex().
#define YYPARSE_PARAM ace_svc_conf_parameter

#define YYLEX_PARAM YYPARSE_PARAM

#define ACE_SVC_CONF_PARAM (static_cast<ACE_Svc_Conf_Param *> (YYLEX_PARAM))

ACE_END_VERSIONED_NAMESPACE_DECL

#include /**/ "ace/post.h"

#endif /* ACE_SVC_CONF_PARAM_H */
