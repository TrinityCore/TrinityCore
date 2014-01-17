%{
// $Id: Svc_Conf.y 94034 2011-05-09 19:11:03Z johnnyw $

#include "ace/Svc_Conf.h"

#if (ACE_USES_CLASSIC_SVC_CONF == 1)

#include "ace/Module.h"
#include "ace/Stream.h"
#include "ace/Service_Types.h"
#include "ace/ace_wchar.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

// Prototypes.

static ACE_Module_Type *
  ace_get_module (ACE_Service_Type const * sr,
                  ACE_TCHAR const * svc_name,
                  int & ace_yyerrno);

#define YYDEBUG_LEXER_TEXT (yytext[yyleng] = '\0', yytext)

// Force the pretty debugging code to compile.
// #define YYDEBUG 1

// Bison 2.3 template contains switch statement with a "default:", but
// without a "case:" label. Suppressing a compiler warning for Visual
// C++.
#if defined (_MSC_VER)
#   pragma warning ( disable : 4065 )
#endif

// Normalize the message literal's type to match yyerror() prototype
#define YY_ ACE_TEXT

// Prevent yacc(1) from declaring a trivial YYSTYPE just because
// YYSTYPE is not a macro definition. On the other hand we want
// YYSTYPE_IS_DECLARED to be as localized as possible to avoid
// poluting the global namespace - there may be other yacc(1) parsers
// that want to play nice with ACE
#define YYSTYPE_IS_DECLARED

ACE_END_VERSIONED_NAMESPACE_DECL

%}

%token ACE_DYNAMIC ACE_STATIC ACE_SUSPEND ACE_RESUME ACE_REMOVE ACE_USTREAM
%token ACE_MODULE_T ACE_STREAM_T ACE_SVC_OBJ_T ACE_ACTIVE ACE_INACTIVE
%token ACE_PATHNAME ACE_IDENT ACE_STRING

%start svc_config_entries

%type <ident_> ACE_IDENT ACE_STRING ACE_PATHNAME pathname parameters_opt
%type <type_> type status
%type <parse_node_> dynamic static suspend resume remove module_list stream
%type <parse_node_> stream_modules module svc_config_entry
%type <static_node_> stream_ops
%type <svc_record_> svc_location
%type <location_node_> svc_initializer

// Generate a pure (reentrant) parser -- GNU Bison only
%pure_parser

%%

svc_config_entries
  : svc_config_entries svc_config_entry
    {
      if ($2 != 0)
      {
        $2->apply (ACE_SVC_CONF_PARAM->config, ACE_SVC_CONF_PARAM->yyerrno);
        delete $2;
      }
      ACE_SVC_CONF_PARAM->obstack.release ();
    }
  | svc_config_entries error
    {
      ACE_SVC_CONF_PARAM->obstack.release ();
    }
  | /* EMPTY */
  ;

svc_config_entry
  : dynamic
  | static
  | suspend
  | resume
  | remove
  | stream
  ;

dynamic
  : ACE_DYNAMIC svc_location parameters_opt
    {
      if ($2 != 0)
        $$ = new ACE_Dynamic_Node ($2, $3);
      else
        $$ = 0;
    }
  ;

static
  : ACE_STATIC ACE_IDENT parameters_opt
    {
      $$ = new ACE_Static_Node ($2, $3);
    }
  ;

suspend
  : ACE_SUSPEND ACE_IDENT
    {
      $$ = new ACE_Suspend_Node ($2);
    }
  ;

resume
  : ACE_RESUME ACE_IDENT
    {
      $$ = new ACE_Resume_Node ($2);
    }
  ;

remove
  : ACE_REMOVE ACE_IDENT
    {
      $$ = new ACE_Remove_Node ($2);
    }
  ;

stream
  : ACE_USTREAM stream_ops stream_modules
    {
      $$ = new ACE_Stream_Node ($2, $3);
    }
  | ACE_USTREAM ACE_IDENT { $<static_node_>$ = new ACE_Static_Node ($2); } stream_modules
    {
      $$ = new ACE_Dummy_Node ($<static_node_>3, $4);
    }
  ;

stream_ops
  : dynamic
    {
    }
  | static
    {
    }
  ;

stream_modules
  : '{'
    {
      // Initialize left context...
      $<static_node_>$ = $<static_node_>0;
    }
   module_list '}'
    {
      ACE_UNUSED_ARG ($2);
      $$ = $3;
    }
  | /* EMPTY */ { $$ = 0; }
  ;

module_list
  : module_list module
    {
      if ($2 != 0)
        {
          $2->link ($1);
          $$ = $2;
        }
    }
  | /* EMPTY */ { $$ = 0; }
  ;

module
  : dynamic
    {
            }
  | static
    {
      ACE_Static_Node *sn = $<static_node_>-1;
      ACE_Module_Type *mt = ace_get_module (sn->record (ACE_SVC_CONF_PARAM->config),
                                            $<static_node_>1->name (),
                                            ACE_SVC_CONF_PARAM->yyerrno);

      if (((ACE_Stream_Type *) sn->record (ACE_SVC_CONF_PARAM->config)->type ())->push (mt) == -1)
        {
          ACE_ERROR ((LM_ERROR,
                      ACE_TEXT ("Problem with static\n")));
          ACE_SVC_CONF_PARAM->yyerrno++;
        }
    }
  | suspend
    {
      ACE_Static_Node *sn = $<static_node_>-1;
      ACE_Module_Type *mt = ace_get_module (sn->record (ACE_SVC_CONF_PARAM->config),
                                            sn->name (),
                                            ACE_SVC_CONF_PARAM->yyerrno);
      if (mt != 0)
        mt->suspend ();
    }
  | resume
    {
      ACE_Static_Node *sn = $<static_node_>-1;
      ACE_Module_Type *mt = ace_get_module (sn->record (ACE_SVC_CONF_PARAM->config),
                                            $<static_node_>1->name (),
                                            ACE_SVC_CONF_PARAM->yyerrno);
      if (mt != 0)
        mt->resume ();
    }
  | remove
    {
      ACE_Static_Node *stream = $<static_node_>-1;
      ACE_Static_Node *module = $<static_node_>1;
      ACE_Module_Type *mt = ace_get_module (stream->record (ACE_SVC_CONF_PARAM->config),
                                            module->name (),
                                            ACE_SVC_CONF_PARAM->yyerrno);

      ACE_Stream_Type *st =
        dynamic_cast<ACE_Stream_Type *> (const_cast<ACE_Service_Type_Impl *> (stream->record (ACE_SVC_CONF_PARAM->config)->type ()));
      if (!st || (mt != 0 && st->remove (mt) == -1))
        {
          ACE_ERROR ((LM_ERROR,
                      ACE_TEXT ("cannot remove Module_Type %s from STREAM_Type %s\n"),
                      module->name (),
                      stream->name ()));
          ACE_SVC_CONF_PARAM->yyerrno++;
        }
    }
  ;

svc_location
  : ACE_IDENT type svc_initializer status
    {
      $$ = new ACE_Service_Type_Factory ($1, $2, $3, $4);
    }
  ;

status
  : ACE_ACTIVE
    {
      $$ = 1;
    }
  | ACE_INACTIVE
    {
      $$ = 0;
    }
  | /* EMPTY */
    {
      $$ = 1;
    }
  ;

svc_initializer
  : pathname ':' ACE_IDENT
    {
      $$ = new ACE_Object_Node ($1, $3);
    }
  | pathname ':' ACE_IDENT '(' ')'
    {
      $$ = new ACE_Function_Node ($1, $3);
    }
  | ':' ACE_IDENT '(' ')'
    {
      $$ = new ACE_Static_Function_Node ($2);
    }
  ;

type
  : ACE_MODULE_T '*'
    {
      $$ = ACE_MODULE_T;
    }
  | ACE_SVC_OBJ_T '*'
    {
      $$ = ACE_SVC_OBJ_T;
    }
  | ACE_STREAM_T '*'
    {
      $$ = ACE_STREAM_T;
    }
  ;

parameters_opt
  : ACE_STRING
  | /* EMPTY */ { $$ = 0; }
  ;

pathname
  : ACE_PATHNAME
  | ACE_IDENT
  | ACE_STRING
  ;

%%

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

// Prints the error string to standard output.  Cleans up the error
// messages.

void
yyerror (int yyerrno, int yylineno, ACE_TCHAR const * s)
{
#if defined (ACE_NLOGGING)
  ACE_UNUSED_ARG (yyerrno);
  ACE_UNUSED_ARG (yylineno);
  ACE_UNUSED_ARG (s);
#endif /* ACE_NLOGGING */

  ACE_ERROR ((LM_ERROR,
              ACE_TEXT ("ACE (%P|%t) [error %d] on line %d: %C\n"),
              yyerrno,
              yylineno,
              s));
}

void
yyerror (ACE_TCHAR const * s)
{
  yyerror (-1, -1, s);
}

// Note that SRC_REC represents left context, which is the STREAM *
// record.

static ACE_Module_Type *
ace_get_module (ACE_Service_Type const * sr,
                ACE_TCHAR const * svc_name,
                int & yyerrno)
{
  ACE_Stream_Type const * const st =
    (sr == 0
     ? 0
     : dynamic_cast<ACE_Stream_Type const *> (sr->type ()));
  ACE_Module_Type const * const mt = (st == 0 ? 0 : st->find (svc_name));

  if (sr == 0 || st == 0 || mt == 0)
    {
      ACE_ERROR ((LM_ERROR,
                  ACE_TEXT ("cannot locate Module_Type %s ")
                  ACE_TEXT ("in STREAM_Type %s\n"),
                  svc_name,
                  (sr ? sr->name () : ACE_TEXT ("(nil)"))));
      ++yyerrno;
    }

  return const_cast<ACE_Module_Type *> (mt);
}

#if defined (SVC_CONF_Y_DEBUGGING)
// Main driver program.

int
ACE_TMAIN (int argc, ACE_TCHAR *argv[])
{
  ACE_Svc_Conf_Param param (0, stdin);

  // Try to reopen any filename argument to use YYIN.
  if (argc > 1 && (yyin = freopen (argv[1], "r", stdin)) == 0)
    (void) ACE_OS::fprintf (stderr, ACE_TEXT ("usage: %s [file]\n"), argv[0]), ACE_OS::exit (1);

  return ::yyparse (&param);
}
#endif /* SVC_CONF_Y_DEBUGGING */

ACE_END_VERSIONED_NAMESPACE_DECL

#endif  /* ACE_USES_CLASSIC_SVC_CONF == 1 */
