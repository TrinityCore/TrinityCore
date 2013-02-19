// -*- C++ -*-
//=============================================================================
/**
 * @file ETCL_Constraint_Visitor.cpp
 *
 * $Id: ETCL_Constraint_Visitor.cpp 81653 2008-05-08 21:08:49Z parsons $
 *
 * @author Jeff Parsons <j.parsons@vanderbilt.edu>
 */
//=============================================================================

#include "ace/ETCL/ETCL_Constraint_Visitor.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ETCL_Constraint_Visitor::~ETCL_Constraint_Visitor (void)
{
}

int
ETCL_Constraint_Visitor::visit_literal (ETCL_Literal_Constraint *)
{
  return 0;
}

int
ETCL_Constraint_Visitor::visit_identifier (ETCL_Identifier *)
{
  return 0;
}

int
ETCL_Constraint_Visitor::visit_union_value (ETCL_Union_Value *)
{
  return 0;
}

int
ETCL_Constraint_Visitor::visit_union_pos (ETCL_Union_Pos *)
{
  return 0;
}

int
ETCL_Constraint_Visitor::visit_component_pos (ETCL_Component_Pos *)
{
  return 0;
}

int
ETCL_Constraint_Visitor::visit_component_assoc (ETCL_Component_Assoc *)
{
  return 0;
}

int
ETCL_Constraint_Visitor::visit_component_array (ETCL_Component_Array *)
{
  return 0;
}

int
ETCL_Constraint_Visitor::visit_special (ETCL_Special *)
{
  return 0;
}

int
ETCL_Constraint_Visitor::visit_component (ETCL_Component *)
{
  return 0;
}

int
ETCL_Constraint_Visitor::visit_dot (ETCL_Dot *)
{
  return 0;
}

int
ETCL_Constraint_Visitor::visit_eval (ETCL_Eval *)
{
  return 0;
}

int
ETCL_Constraint_Visitor::visit_default (ETCL_Default *)
{
  return 0;
}

int
ETCL_Constraint_Visitor::visit_exist (ETCL_Exist *)
{
  return 0;
}

int
ETCL_Constraint_Visitor::visit_unary_expr (ETCL_Unary_Expr *)
{
  return 0;
}

int
ETCL_Constraint_Visitor::visit_binary_expr (ETCL_Binary_Expr *)
{
  return 0;
}

int
ETCL_Constraint_Visitor::visit_preference (ETCL_Preference *)
{
  return 0;
}

ACE_END_VERSIONED_NAMESPACE_DECL

