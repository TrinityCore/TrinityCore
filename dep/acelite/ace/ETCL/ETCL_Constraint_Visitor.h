// -*- C++ -*-
//=============================================================================
/**
 * @file ETCL_Constraint_Visitor.h
 *
 * $Id: ETCL_Constraint_Visitor.h 81653 2008-05-08 21:08:49Z parsons $
 *
 * @author Carlos O'Ryan <coryan@cs.wustl.edu>
 * @author Jeff Parsons <j.parsons@vanderbilt.edu>
 */
//=============================================================================

#ifndef ACE_ETCL_CONSTRAINT_VISITOR_H
#define ACE_ETCL_CONSTRAINT_VISITOR_H

#include /**/ "ace/pre.h"

#include "ace/ETCL/ace_etcl_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

class ETCL_Literal_Constraint;
class ETCL_Identifier;
class ETCL_Union_Value;
class ETCL_Union_Pos;
class ETCL_Component_Pos;
class ETCL_Component_Assoc;
class ETCL_Component_Array;
class ETCL_Special;
class ETCL_Component;
class ETCL_Dot;
class ETCL_Eval;
class ETCL_Default;
class ETCL_Exist;
class ETCL_Unary_Expr;
class ETCL_Binary_Expr;
class ETCL_Preference;

class ACE_ETCL_Export ETCL_Constraint_Visitor
{
public:
  virtual ~ETCL_Constraint_Visitor (void);

  virtual int visit_literal (ETCL_Literal_Constraint *);
  virtual int visit_identifier (ETCL_Identifier *);
  virtual int visit_union_value (ETCL_Union_Value *);
  virtual int visit_union_pos (ETCL_Union_Pos *);
  virtual int visit_component_pos (ETCL_Component_Pos *);
  virtual int visit_component_assoc (ETCL_Component_Assoc *);
  virtual int visit_component_array (ETCL_Component_Array *);
  virtual int visit_special (ETCL_Special *);
  virtual int visit_component (ETCL_Component *);
  virtual int visit_dot (ETCL_Dot *);
  virtual int visit_eval (ETCL_Eval *);
  virtual int visit_default (ETCL_Default *);
  virtual int visit_exist (ETCL_Exist *);
  virtual int visit_unary_expr (ETCL_Unary_Expr *);
  virtual int visit_binary_expr (ETCL_Binary_Expr *);
  virtual int visit_preference (ETCL_Preference *);
};

ACE_END_VERSIONED_NAMESPACE_DECL

#include /**/ "ace/post.h"

#endif // ACE_ETCL_CONSTRAINT_VISITOR_H
