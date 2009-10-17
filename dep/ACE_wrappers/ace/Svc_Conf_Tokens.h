// -*- C++ -*-
//====================================================================
/**
 *  @file    Svc_Conf_Tokens.h
 *
 *  $Id: Svc_Conf_Tokens.h 81335 2008-04-11 01:53:36Z iliyan $
 *
 *  @author Iliyan Jeliazkov <iliyan@ociweb.com>
 */
//====================================================================

#ifndef BISON_SVC_CONF_TAB_H
#  define BISON_SVC_CONF_TAB_H
/// This file "wraps" around the one produced by yacc(1) and ensures
/// that various symbols do not polute the global namespace. This
/// allows ACE-based applications to incorporate other yacc(1)-derived
/// parsers.
#  if !defined (YYSTYPE_IS_DECLARED)
#    define YYSTYPE_IS_DECLARED 1
#  endif
#  include "ace/Svc_Conf_Token_Table.h"
#  undef YYSTYPE_IS_DECLARED
#endif /* ifndef BISON_SVC_CONF_TAB_H */

