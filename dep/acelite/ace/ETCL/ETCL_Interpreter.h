// -*- C++ -*-

//=============================================================================
/**
 *  @file    ETCL_Interpreter.h
 *
 *  $Id: ETCL_Interpreter.h 82434 2008-07-28 11:40:36Z johnnyw $
 *
 *  @author Jeff Parsons <parsons@cs.wustl.edu> based on previous work by
 *  @author Seth Widoff <sbw1@cs.wustl.edu>
 */
//=============================================================================


#ifndef ETCL_INTERPRETER_H
#define ETCL_INTERPRETER_H

#include /**/ "ace/pre.h"

#include "ace/Thread_Mutex.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/Synch_Traits.h"

#include "etcl_parser_export.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

class ETCL_Constraint;

ACE_END_VERSIONED_NAMESPACE_DECL

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class ETCL_Interpreter
 *
 * @brief ETCL_Interpreter is the superclass for all ETCL interpreters.
 * Its build tree method invokes the yacc parser to parse a constraint
 * or preference string.
 */
class ETCL_Parser_Export ETCL_Interpreter
{
protected:
  // = Initialization and termination methods.
  /// Constructor.
  ETCL_Interpreter (void);

  /// Destructor.
  virtual ~ETCL_Interpreter (void);

  /// Using the Yacc generated parser, construct an expression tree
  /// representing @a constraints from the tokens returned by it.
  int build_tree (const char* constraints);

  static int is_empty_string (const char* str);

  /// The root of the expression tree, not equal to null if build_tree
  /// successfully builds a tree from the constraints.
  ETCL_Constraint* root_;
private:
  /// This mutex protects the <build_tree> method from reentrance.
  static ACE_SYNCH_MUTEX parserMutex__;
};


// Functions we need for parsing.
extern int yyparse (void);
extern void yyrestart (FILE*);
extern int yylex (void);

// Have yylex read from the constraint string, not from stdin.
#undef YY_INPUT
#define YY_INPUT(b, r, ms) (r = Lex_String_Input::copy_into(b, ms))

/**
 * @class Lex_String_Input
 *
 * @brief Have Lex read from a string and not from stdin. Essentially,
 * the interpreter needs to call yylex() until EOF, and call
 * TAO_Lex_String_Input::reset() with the new string, prior to
 * calling yyparse.
 */
class Lex_String_Input
{
public:
  /// Reset the lex input.
  static void reset (char* input_string);

  /// Method lex will call to read from the input string.
  static int copy_into (char* buf, int max_size);

private:

  /// Pointers to keep track of the input string.
  static char* string_;
  static char* current_;
  static char* end_;
};

/// The union used by lex and bison to build the Abstract Syntax Tree.
typedef union
{
  ACE_VERSIONED_NAMESPACE_NAME::ETCL_Constraint* constraint;
} YYSTYPE;

extern YYSTYPE yylval;
extern YYSTYPE yyval;

ACE_END_VERSIONED_NAMESPACE_DECL

#include /**/ "ace/post.h"

#endif // ETCL_INTERPRETER_H
