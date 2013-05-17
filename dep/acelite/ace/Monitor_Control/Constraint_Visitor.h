// -*- C++ -*-

//=============================================================================
/**
 * @file Constraint_Visitor.h
 *
 * $Id: Constraint_Visitor.h 86518 2009-08-18 12:30:56Z olli $
 *
 * @author Jeff Parsons <j.parsons@vanderbilt.edu>
 */
//=============================================================================

#ifndef CONSTRAINT_VISITOR_H
#define CONSTRAINT_VISITOR_H

#include /**/ "ace/pre.h"

#include "ace/CDR_Base.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if defined (ACE_HAS_MONITOR_FRAMEWORK) && (ACE_HAS_MONITOR_FRAMEWORK == 1)

#include "ace/Monitor_Control_Types.h"

#include "ace/ETCL/ETCL_Constraint.h"
#include "ace/ETCL/ETCL_Constraint_Visitor.h"

#include "ace/Monitor_Control/Monitor_Control_export.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

class ETCL_Literal_Constraint;
class ETCL_Identifier;
class ETCL_Unary_Expr;
class ETCL_Binary_Expr;
class ETCL_Constraint;

namespace ACE
{
  namespace Monitor_Control
  {
    /**
     * @class Constraint_Visitor
     *
     * @brief Backend for the non-CORBA ETCL frontend, specific to
     *        MonitorControl and supporting only basic types not
              specific to CORBA.
     */
    class MONITOR_CONTROL_Export Constraint_Visitor
      : public ETCL_Constraint_Visitor
    {
    public:
      Constraint_Visitor (const Monitor_Control_Types::Data& data);
      virtual ~Constraint_Visitor (void);

      ACE_CDR::Boolean evaluate_constraint (ETCL_Constraint *root);

      virtual int visit_literal (ETCL_Literal_Constraint *);
      virtual int visit_identifier (ETCL_Identifier *);
      virtual int visit_unary_expr (ETCL_Unary_Expr *);
      virtual int visit_binary_expr (ETCL_Binary_Expr *);

    private:
      /// Sub-methods for visit_binary_expr().
      int visit_or (ETCL_Binary_Expr *);
      int visit_and (ETCL_Binary_Expr *);
      int visit_binary_op (ETCL_Binary_Expr *binary_expr,
                           int op_type);

    private:
      const Monitor_Control_Types::Data& data_;
      ACE_Unbounded_Queue<ETCL_Literal_Constraint> queue_;
    };
  }
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_HAS_MONITOR_FRAMEWORK==1 */

#include /**/ "ace/post.h"

#endif // CONSTRAINT_VISITOR_H
