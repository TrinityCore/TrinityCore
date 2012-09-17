// $Id: Constraint_Visitor.cpp 86518 2009-08-18 12:30:56Z olli $

#include "ace/Monitor_Control/Constraint_Visitor.h"

#if defined (ACE_HAS_MONITOR_FRAMEWORK) && (ACE_HAS_MONITOR_FRAMEWORK == 1)

#include "ace/ETCL/ETCL_y.h"
#include "ace/ETCL/ETCL_Constraint.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

namespace ACE
{
  namespace Monitor_Control
  {
    Constraint_Visitor::Constraint_Visitor (
      const Monitor_Control_Types::Data& data)
      : data_ (data)
    {}

    Constraint_Visitor::~Constraint_Visitor (void)
    {}

    ACE_CDR::Boolean
    Constraint_Visitor::evaluate_constraint (ETCL_Constraint *root)
    {
      ACE_CDR::Boolean result = false;
      this->queue_.reset ();

      // Evaluate the constraint in root_;
      if (root != 0)
      {
        if (root->accept (this) == 0 && !this->queue_.is_empty ())
        {
          ETCL_Literal_Constraint top;
          this->queue_.dequeue_head (top);
          result = (ACE_CDR::Boolean) top;
        }
      }

      // If a property couldn't be evaluated we must return FALSE.
      return result;
    }

    int
    Constraint_Visitor::visit_literal (ETCL_Literal_Constraint *constraint)
    {
      this->queue_.enqueue_head (*constraint);
      return 0;
    }

    int
    Constraint_Visitor::visit_identifier (ETCL_Identifier *ident)
    {
      /// TODO - check for strings related to other identifiers
      /// relevant in MonitorControl, for example the data timestamp.
      if (ACE_OS::strcmp (ident->value (), "value") == 0)
        {
          this->queue_.enqueue_head (
            ETCL_Literal_Constraint (this->data_.value_));

          return 0;
        }

      return -1;
    }

    int
    Constraint_Visitor::visit_unary_expr (ETCL_Unary_Expr *unary_expr)
    {
      ETCL_Constraint *subexpression = unary_expr->subexpr ();

      /// Call to accept() puts the subexpression's evaluation on our queue.
      if (subexpression->accept (this) == 0)
        {
          ETCL_Literal_Constraint subexpr_result;
          ACE_CDR::Boolean result = 0;
          int op_type = unary_expr->type ();

          switch (op_type)
          {
            case ETCL_NOT:
              this->queue_.dequeue_head (subexpr_result);
              result = ! (ACE_CDR::Boolean) subexpr_result;
              this->queue_.enqueue_head (ETCL_Literal_Constraint (result));
              return 0;
            case ETCL_MINUS:
              /// The leading '-' was parsed separately, so we have to pull
              /// the literal constraint off the queue, apply the class' own
              /// unary minus operator, and put it back.
              this->queue_.dequeue_head (subexpr_result);
              this->queue_.enqueue_head (-subexpr_result);
              return 0;
            case ETCL_PLUS:
              /// Leave the literal constraint on the queue. The leading
              /// '+' was just syntactic sugar - no action is necessary.
              return 0;
            default:
              /// The parser should never construct a ETCL_Unary_Constraint
              /// behind any operators except the above three.
              return -1;
          }
        }

      return -1;
    }

    int
    Constraint_Visitor::visit_binary_expr (ETCL_Binary_Expr *binary_expr)
    {
      int bin_op_type = binary_expr->type ();

      switch (bin_op_type)
        {
          case ETCL_OR:
            return this->visit_or (binary_expr);
          case ETCL_AND:
            return this->visit_and (binary_expr);
          case ETCL_LT:
          case ETCL_LE:
          case ETCL_GT:
          case ETCL_GE:
          case ETCL_EQ:
          case ETCL_NE:
          case ETCL_PLUS:
          case ETCL_MINUS:
          case ETCL_MULT:
          case ETCL_DIV:
            return this->visit_binary_op (binary_expr, bin_op_type);
          /// These last two are not supported in non_CORBA ETCL.
          case ETCL_TWIDDLE:
          case ETCL_IN:
          default:
            return -1;
        }
    }

    int
    Constraint_Visitor::visit_or (ETCL_Binary_Expr *binary)
    {
      int return_value = -1;
      ACE_CDR::Boolean result = false;
      ETCL_Constraint *lhs = binary->lhs ();

      /// Call to accept() puts the lhs (or its evaluation) on our queue.
      if (lhs->accept (this) == 0)
        {
          ETCL_Literal_Constraint lhs_result;
          this->queue_.dequeue_head (lhs_result);
          result = (ACE_CDR::Boolean) lhs_result;

          /// Short-circuiting OR.
          if (!result)
            {
              ETCL_Constraint *rhs = binary->rhs ();

              if (rhs->accept (this) == 0)
              {
                ETCL_Literal_Constraint rhs_result;
                this->queue_.dequeue_head (rhs_result);
                result = (ACE_CDR::Boolean) rhs_result;
                return_value = 0;
              }
            }
          else
            {
              return_value = 0;
            }
        }

      if (return_value == 0)
        {
          this->queue_.enqueue_head (ETCL_Literal_Constraint (result));
        }

      return return_value;
    }

    int
    Constraint_Visitor::visit_and (ETCL_Binary_Expr *binary)
    {
      int return_value = -1;
      ACE_CDR::Boolean result = false;
      ETCL_Constraint *lhs = binary->lhs ();

      /// Call to accept() puts the lhs (or its evaluation) on our queue.
      if (lhs->accept (this) == 0)
        {
          ETCL_Literal_Constraint lhs_result;
          this->queue_.dequeue_head (lhs_result);
          result = (ACE_CDR::Boolean) lhs_result;

          /// Short-circuiting AND.
          if (result == true)
            {
              ETCL_Constraint *rhs = binary->rhs ();

              if (rhs->accept (this) == 0)
              {
                ETCL_Literal_Constraint rhs_result;
                this->queue_.dequeue_head (rhs_result);
                result = (ACE_CDR::Boolean) rhs_result;
                return_value = 0;
              }
            }
          else
            {
              return_value = 0;
            }
        }

      if (return_value == 0)
        {
          this->queue_.enqueue_head (ETCL_Literal_Constraint (result));
        }

      return return_value;
    }

    int
    Constraint_Visitor::visit_binary_op (ETCL_Binary_Expr *binary,
                                         int op_type)
    {
      int return_value = -1;
      ETCL_Constraint *lhs = binary->lhs ();
      ACE_CDR::Boolean result = false;

      /// Perform an operation on the results of evaluating the left and
      /// right branches of this subtree. The evaluations go on our queue.
      if (lhs->accept (this) == 0)
        {
          ETCL_Literal_Constraint left_operand;
          this->queue_.dequeue_head (left_operand);
          ETCL_Constraint *rhs = binary->rhs ();

          if (rhs->accept (this) == 0)
            {
              ETCL_Literal_Constraint right_operand;
              this->queue_.dequeue_head (right_operand);
              return_value = 0;

              switch (op_type)
                {
                  case ETCL_LT:
                    result = left_operand < right_operand;
                    this->queue_.enqueue_head (
                      ETCL_Literal_Constraint (result));
                    break;
                  case ETCL_LE:
                    result = left_operand <= right_operand;
                    this->queue_.enqueue_head (
                      ETCL_Literal_Constraint (result));
                    break;
                  case ETCL_GT:
                    result = left_operand > right_operand;
                    this->queue_.enqueue_head (
                      ETCL_Literal_Constraint (result));
                    break;
                  case ETCL_GE:
                    result = left_operand >= right_operand;
                    this->queue_.enqueue_head (
                      ETCL_Literal_Constraint (result));
                    break;
                  case ETCL_EQ:
                    result = left_operand == right_operand;
                    this->queue_.enqueue_head (
                      ETCL_Literal_Constraint (result));
                    break;
                  case ETCL_NE:
                    result = left_operand != right_operand;
                    this->queue_.enqueue_head (
                      ETCL_Literal_Constraint (result));
                    break;
                  case ETCL_PLUS:
                    this->queue_.enqueue_head (
                      left_operand + right_operand);
                    break;
                  case ETCL_MINUS:
                    this->queue_.enqueue_head (
                      left_operand - right_operand);
                    break;
                  case ETCL_MULT:
                    this->queue_.enqueue_head (
                      left_operand * right_operand);
                    break;
                  case ETCL_DIV:
                    this->queue_.enqueue_head (
                      left_operand / right_operand);
                    break;
                  default:
                    return_value = -1;
                    break;
                }
            }
        }

      return return_value;
    }
  }
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_HAS_MONITOR_FRAMEWORK==1 */
