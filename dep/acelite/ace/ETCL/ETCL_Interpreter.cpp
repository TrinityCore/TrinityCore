// -*- C++ -*-
// $Id: ETCL_Interpreter.cpp 91813 2010-09-17 07:52:52Z johnnyw $

#include "ace/Guard_T.h"
#include "ace/Truncate.h"

#include "ace/ETCL/ETCL_Interpreter.h"
#include "ace/ETCL/ETCL_Constraint.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ETCL_Parser_Export ACE_SYNCH_MUTEX ETCL_Interpreter::parserMutex__;

ETCL_Interpreter::ETCL_Interpreter (void)
  : root_ (0)
{
}

ETCL_Interpreter::~ETCL_Interpreter (void)
{
  delete this->root_;
}

int
ETCL_Interpreter::build_tree (const char* constraints)
{
  ACE_GUARD_RETURN (ACE_SYNCH_MUTEX,
                    guard,
                    ETCL_Interpreter::parserMutex__,
                    -1);

  Lex_String_Input::reset ((char*)constraints);

  yyval.constraint = 0;
  int return_value = ::yyparse ();

  if (return_value == 0 && yyval.constraint != 0)
    {
      this->root_ = yyval.constraint;
    }
  else
    {
      this->root_ = 0;
    }

  return return_value;
}

int
ETCL_Interpreter::is_empty_string (const char* str)
{
  int return_value = 0;

  if (str != 0)
    {
      int i = 0;

      while (str[i] != '\0')
        {
          if (str[i] != ' ')
            {
              break;
            }

          ++i;
        }

      if (str[i] == '\0')
        {
          return_value = 1;
        }
    }

  return return_value;
}

char* Lex_String_Input::string_ = 0;
char* Lex_String_Input::current_ = 0;
char* Lex_String_Input::end_ = 0;

// Routine to have Lex read its input from the constraint string.

int
Lex_String_Input::copy_into (char* buf,
                             int max_size)
{
  int const chars_left =
    ACE_Utils::truncate_cast<int> (
      Lex_String_Input::end_ - Lex_String_Input::current_);

  int const n = max_size > chars_left ? chars_left : max_size;

  if (n > 0)
    {
      ACE_OS::memcpy (buf,
                      Lex_String_Input::current_,
                      n);
      Lex_String_Input::current_ += n;
    }

  return n;
}

void
Lex_String_Input::reset (char* input_string)
{
  Lex_String_Input::string_ = input_string;
  Lex_String_Input::current_ = input_string;
  Lex_String_Input::end_ =
    input_string + ACE_OS::strlen (Lex_String_Input::string_);
}

ACE_END_VERSIONED_NAMESPACE_DECL
