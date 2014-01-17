// -*- C++ -*-
// $Id: ETCL_Constraint.cpp 92173 2010-10-07 12:36:17Z olli $

#include "ace/ACE.h"

#include "ace/ETCL/ETCL_Constraint.h"
#include "ace/ETCL/ETCL_Constraint_Visitor.h"

#if ! defined (__ACE_INLINE__)
#include "ace/ETCL/ETCL_Constraint.inl"
#endif /* __ACE_INLINE__ */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ETCL_Constraint::ETCL_Constraint (void)
{
}

ETCL_Constraint::~ETCL_Constraint (void)
{
}

int
ETCL_Constraint::accept (ETCL_Constraint_Visitor * /* visitor */)
{
  return 0;
}

// ****************************************************************

ETCL_Literal_Constraint::ETCL_Literal_Constraint (
    const ETCL_Literal_Constraint & lit
  )
  : ETCL_Constraint(),
    type_ (ACE_ETCL_UNKNOWN)
{
  this->copy (lit);
}

ETCL_Literal_Constraint::ETCL_Literal_Constraint (
    ACE_CDR::ULong uinteger) : type_ (ACE_ETCL_UNSIGNED)
{
  this->op_.uinteger_ = uinteger;
}

ETCL_Literal_Constraint::ETCL_Literal_Constraint (
    ACE_CDR::Long integer) : type_ (ACE_ETCL_SIGNED)
{
  this->op_.integer_ = integer;
}

ETCL_Literal_Constraint::ETCL_Literal_Constraint (
    ACE_CDR::Boolean boolean
  )
  : type_ (ACE_ETCL_BOOLEAN)
{
  this->op_.bool_ = boolean;
}

ETCL_Literal_Constraint::ETCL_Literal_Constraint (
    ACE_CDR::Double doub) : type_ (ACE_ETCL_DOUBLE)
{
  this->op_.double_ = doub;
}

ETCL_Literal_Constraint::ETCL_Literal_Constraint (
    const char* str) : type_ (ACE_ETCL_STRING)
{
  this->op_.str_ = ACE::strnew (str);
}

ETCL_Literal_Constraint::~ETCL_Literal_Constraint (void)
{
  if (this->type_ == ACE_ETCL_STRING)
    {
      ACE::strdelete (this->op_.str_);
    }
}

int
ETCL_Literal_Constraint::accept (ETCL_Constraint_Visitor* visitor)
{
  return visitor->visit_literal (this);
}

Literal_Type
ETCL_Literal_Constraint::expr_type (void) const
{
  return this->type_;
}

void
ETCL_Literal_Constraint::operator= (const ETCL_Literal_Constraint& co)
{
  this->copy (co);
}

ETCL_Literal_Constraint::operator ACE_CDR::Boolean (void) const
{
  return (this->type_ == ACE_ETCL_BOOLEAN) ? this->op_.bool_ : false;
}

ETCL_Literal_Constraint::operator ACE_CDR::ULong (void) const
{
  switch (this->type_)
  {
    case ACE_ETCL_UNSIGNED:
      return this->op_.uinteger_;
    case ACE_ETCL_SIGNED:
    case ACE_ETCL_INTEGER:
      return
        (this->op_.integer_ > 0) ? (ACE_CDR::ULong) this->op_.integer_ : 0;
    case ACE_ETCL_DOUBLE:
      return
        (this->op_.double_ > 0) ?
        ((this->op_.double_ > ACE_UINT32_MAX) ?
         ACE_UINT32_MAX :
         (ACE_CDR::ULong) this->op_.double_)
        : 0;
    default:
      return 0;
  }
}

ETCL_Literal_Constraint::operator ACE_CDR::Long (void) const
{
  switch (this->type_)
  {
    case ACE_ETCL_SIGNED:
    case ACE_ETCL_INTEGER:
      return this->op_.integer_;
    case ACE_ETCL_UNSIGNED:
      return
        (this->op_.uinteger_ > (ACE_CDR::ULong) ACE_INT32_MAX) ?
        ACE_INT32_MAX : (ACE_CDR::Long) this->op_.uinteger_;
    case ACE_ETCL_DOUBLE:
      return
        (this->op_.double_ > 0) ?
         ((this->op_.double_ > ACE_INT32_MAX) ?
          ACE_INT32_MAX :
          (ACE_CDR::Long) this->op_.double_) :
          ((this->op_.double_ < ACE_INT32_MIN) ?
           ACE_INT32_MIN :
           (ACE_CDR::Long) this->op_.double_);
    default:
      return 0;
  }
}

ETCL_Literal_Constraint::operator ACE_CDR::Double (void) const
{
  switch (this->type_)
  {
    case ACE_ETCL_DOUBLE:
      return this->op_.double_;
    case ACE_ETCL_SIGNED:
    case ACE_ETCL_INTEGER:
      return (ACE_CDR::Double) this->op_.integer_;
    case ACE_ETCL_UNSIGNED:
      return (ACE_CDR::Double) this->op_.uinteger_;
    default:
      return 0.0;
  }
}

ETCL_Literal_Constraint::operator const char* (void) const
{
  switch (this->type_)
  {
    case ACE_ETCL_STRING:
      return this->op_.str_;
    default:
      return 0;
  }
}

bool
ETCL_Literal_Constraint::operator== (const ETCL_Literal_Constraint & rhs)
{
  bool return_value = false;
  Literal_Type widest_type = this->widest_type (rhs);

  switch (widest_type)
    {
    case ACE_ETCL_STRING:
      return_value = (ACE_OS::strcmp ((const char*) *this, (const char*) rhs) == 0);
      break;
    case ACE_ETCL_DOUBLE:
      return_value = ACE::is_equal ((ACE_CDR::Double) *this, (ACE_CDR::Double) rhs);
      break;
    case ACE_ETCL_INTEGER:
    case ACE_ETCL_SIGNED:
      return_value = (ACE_CDR::Long) *this == (ACE_CDR::Long) rhs;
      break;
    case ACE_ETCL_UNSIGNED:
      return_value = (ACE_CDR::ULong) *this == (ACE_CDR::ULong) rhs;
      break;
    case ACE_ETCL_BOOLEAN:
      return_value = (ACE_CDR::Boolean) *this == (ACE_CDR::Boolean) rhs;
      break;
    default:
     break;
    }

  return return_value;
}

bool
ETCL_Literal_Constraint::operator< (const ETCL_Literal_Constraint & rhs)
{
  bool return_value = false;
  Literal_Type widest_type = this->widest_type (rhs);

  switch (widest_type)
    {
    case ACE_ETCL_STRING:
      return_value = (ACE_OS::strcmp ((const char*) *this, (const char*) rhs) < 0);
      break;
    case ACE_ETCL_DOUBLE:
      return_value = (ACE_CDR::Double) *this < (ACE_CDR::Double) rhs;
      break;
    case ACE_ETCL_INTEGER:
    case ACE_ETCL_SIGNED:
      return_value = (ACE_CDR::Long) *this < (ACE_CDR::Long) rhs;
      break;
    case ACE_ETCL_UNSIGNED:
      return_value = (ACE_CDR::ULong) *this < (ACE_CDR::ULong) rhs;
      break;
    case ACE_ETCL_BOOLEAN:
      return_value = (ACE_CDR::Boolean) *this < (ACE_CDR::Boolean) rhs;
      break;
    default:
      break;
    }

  return return_value;
}

bool
ETCL_Literal_Constraint::operator> (const ETCL_Literal_Constraint & rhs)
{
  bool return_value = false;
  Literal_Type widest_type = this->widest_type (rhs);

  switch (widest_type)
    {
    case ACE_ETCL_STRING:
      return_value = (ACE_OS::strcmp ((const char*) *this, (const char*) rhs) > 0);
      break;
    case ACE_ETCL_DOUBLE:
      return_value = (ACE_CDR::Double) *this > (ACE_CDR::Double) rhs;
      break;
    case ACE_ETCL_INTEGER:
    case ACE_ETCL_SIGNED:
      return_value = (ACE_CDR::Long) *this > (ACE_CDR::Long) rhs;
      break;
    case ACE_ETCL_UNSIGNED:
      return_value = (ACE_CDR::ULong) *this > (ACE_CDR::ULong) rhs;
      break;
    default:
      break;
    }

  return return_value;
}

ETCL_Literal_Constraint
ETCL_Literal_Constraint::operator+ (const ETCL_Literal_Constraint & rhs)
{
  Literal_Type widest_type = this->widest_type (rhs);

  switch (widest_type)
    {
    case ACE_ETCL_DOUBLE:
      {
        ACE_CDR::Double result = (ACE_CDR::Double) *this + (ACE_CDR::Double) rhs;
        return ETCL_Literal_Constraint ((ACE_CDR::Double) result);
      }
    case ACE_ETCL_INTEGER:
    case ACE_ETCL_SIGNED:
      {
        ACE_CDR::Long result = (ACE_CDR::Long) *this + (ACE_CDR::Long) rhs;
        return ETCL_Literal_Constraint ((ACE_CDR::Long) result);
      }
    case ACE_ETCL_UNSIGNED:
      {
        ACE_CDR::ULong result = (ACE_CDR::ULong) *this + (ACE_CDR::ULong) rhs;
        return ETCL_Literal_Constraint ((ACE_CDR::ULong) result);
      }
    default:
      return ETCL_Literal_Constraint ((ACE_CDR::Long) 0);
    }
}

ETCL_Literal_Constraint
ETCL_Literal_Constraint::operator- (const ETCL_Literal_Constraint & rhs)
{
  Literal_Type widest_type = this->widest_type (rhs);

  switch (widest_type)
    {
    case ACE_ETCL_DOUBLE:
      {
        ACE_CDR::Double result = (ACE_CDR::Double) *this - (ACE_CDR::Double) rhs;
        return ETCL_Literal_Constraint ((ACE_CDR::Double) result);
      }
    case ACE_ETCL_INTEGER:
    case ACE_ETCL_SIGNED:
      {
        ACE_CDR::Long result = (ACE_CDR::Long) *this - (ACE_CDR::Long) rhs;
        return ETCL_Literal_Constraint ((ACE_CDR::Long) result);
      }
    case ACE_ETCL_UNSIGNED:
      {
        ACE_CDR::ULong result = (ACE_CDR::ULong) *this - (ACE_CDR::ULong) rhs;
        return ETCL_Literal_Constraint ((ACE_CDR::ULong) result);
      }
    default:
      return ETCL_Literal_Constraint ((ACE_CDR::Long) 0);
    }
}

ETCL_Literal_Constraint
ETCL_Literal_Constraint::operator* (const ETCL_Literal_Constraint & rhs)
{
  Literal_Type widest_type = this->widest_type (rhs);

  switch (widest_type)
    {
    case ACE_ETCL_DOUBLE:
      {
        ACE_CDR::Double result = (ACE_CDR::Double) *this * (ACE_CDR::Double) rhs;
        return ETCL_Literal_Constraint ((ACE_CDR::Double) result);
      }
    case ACE_ETCL_INTEGER:
    case ACE_ETCL_SIGNED:
      {
        ACE_CDR::Long result = (ACE_CDR::Long) *this * (ACE_CDR::Long) rhs;
        return ETCL_Literal_Constraint ((ACE_CDR::Long) result);
      }
    case ACE_ETCL_UNSIGNED:
      {
        ACE_CDR::ULong result = (ACE_CDR::ULong) *this * (ACE_CDR::ULong) rhs;
        return ETCL_Literal_Constraint ((ACE_CDR::ULong) result);
      }
    default:
      return ETCL_Literal_Constraint ((ACE_CDR::Long) 0);
    }
}

ETCL_Literal_Constraint
ETCL_Literal_Constraint::operator/ (const ETCL_Literal_Constraint & rhs)
{
  Literal_Type widest_type = this->widest_type (rhs);

  switch (widest_type)
    {
    case ACE_ETCL_DOUBLE:
      {
        if (ACE::is_equal ((ACE_CDR::Double) rhs, 0.0))
          return ETCL_Literal_Constraint ((ACE_CDR::Double) 0.0);

        ACE_CDR::Double result = (ACE_CDR::Double) *this / (ACE_CDR::Double) rhs;
        return ETCL_Literal_Constraint ((ACE_CDR::Double) result);
      }
    case ACE_ETCL_INTEGER:
    case ACE_ETCL_SIGNED:
      {
        if ((ACE_CDR::Long) rhs == 0)
          return ETCL_Literal_Constraint ((ACE_CDR::Long) 0);

        ACE_CDR::Long result = (ACE_CDR::Long) *this / (ACE_CDR::Long) rhs;
        return ETCL_Literal_Constraint ((ACE_CDR::Long) result);
      }
    case ACE_ETCL_UNSIGNED:
      {
        if ((ACE_CDR::ULong) rhs == 0)
          return ETCL_Literal_Constraint ((ACE_CDR::ULong) 0);

        ACE_CDR::ULong result = (ACE_CDR::ULong) *this / (ACE_CDR::ULong) rhs;
        return ETCL_Literal_Constraint ((ACE_CDR::ULong) result);
      }
    default:
      return ETCL_Literal_Constraint ((ACE_CDR::Long) 0);
    }
}

ETCL_Literal_Constraint
ETCL_Literal_Constraint::operator- (void)
{
  switch (this->type_)
  {
    case ACE_ETCL_DOUBLE:
      return ETCL_Literal_Constraint (- this->op_.double_);
    case ACE_ETCL_INTEGER:
    case ACE_ETCL_SIGNED:
      return ETCL_Literal_Constraint (- this->op_.integer_);
    case ACE_ETCL_UNSIGNED:
      return ETCL_Literal_Constraint (- (ACE_CDR::Long) this->op_.uinteger_);
    default:
      return ETCL_Literal_Constraint ((ACE_CDR::Long) 0);
  }
}

Literal_Type
ETCL_Literal_Constraint::widest_type (const ETCL_Literal_Constraint & rhs)
{
  Literal_Type rhs_type = rhs.expr_type ();
  Literal_Type return_value = rhs_type;

  if (rhs_type != this->type_)
    {
      if (rhs_type > this->type_)
        {
          return_value = rhs_type;
        }
      else
        {
          return_value = this->type_;
        }
    }

  return return_value;
}

void
ETCL_Literal_Constraint::copy (const ETCL_Literal_Constraint &lit)
{
  if (this->type_ == ACE_ETCL_STRING)
    {
      ACE::strdelete (this->op_.str_);
    }

  this->type_ = lit.type_;

  switch (this->type_)
  {
  case ACE_ETCL_STRING:
    this->op_.str_ = ACE::strnew (lit.op_.str_);
    break;
  case ACE_ETCL_DOUBLE:
    this->op_.double_ = lit.op_.double_;
    break;
  case ACE_ETCL_UNSIGNED:
    this->op_.uinteger_ = lit.op_.uinteger_;
    break;
  case ACE_ETCL_INTEGER:
  case ACE_ETCL_SIGNED:
    this->op_.integer_ = lit.op_.integer_;
    break;
  case ACE_ETCL_BOOLEAN:
    this->op_.bool_ = lit.op_.bool_;
    break;
  default:
    this->type_ = ACE_ETCL_UNKNOWN;
    break;
  }
}

// ****************************************************************

int
ETCL_Identifier::accept (ETCL_Constraint_Visitor *visitor)
{
  return visitor->visit_identifier (this);
}

// ****************************************************************

ETCL_Union_Value::~ETCL_Union_Value (void)
{
  delete this->string_;
  delete this->integer_;
}

int
ETCL_Union_Value::accept (ETCL_Constraint_Visitor *visitor)
{
  return visitor->visit_union_value (this);
}

// ****************************************************************

ETCL_Union_Pos::~ETCL_Union_Pos (void)
{
  delete this->component_;
  delete this->union_value_;
}

int
ETCL_Union_Pos::accept (ETCL_Constraint_Visitor *visitor)
{
  return visitor->visit_union_pos (this);
}

// ****************************************************************

ETCL_Component_Pos::~ETCL_Component_Pos (void)
{
  delete this->component_;
  delete this->integer_;
}

int
ETCL_Component_Pos::accept (ETCL_Constraint_Visitor *visitor)
{
  return visitor->visit_component_pos (this);
}

// ****************************************************************

ETCL_Component_Assoc::~ETCL_Component_Assoc (void)
{
  delete this->component_;
  delete this->identifier_;
}

int
ETCL_Component_Assoc::accept (ETCL_Constraint_Visitor *visitor)
{
  return visitor->visit_component_assoc (this);
}

// ****************************************************************

ETCL_Component_Array::~ETCL_Component_Array (void)
{
  delete this->component_;
  delete this->integer_;
}

int
ETCL_Component_Array::accept (ETCL_Constraint_Visitor *visitor)
{
  return visitor->visit_component_array (this);
}

// ****************************************************************

ETCL_Special::~ETCL_Special (void)
{}

int
ETCL_Special::accept (ETCL_Constraint_Visitor *visitor)
{
  return visitor->visit_special (this);
}

// ****************************************************************

ETCL_Component::~ETCL_Component (void)
{
  delete this->component_;
  delete this->identifier_;
}

int
ETCL_Component::accept (ETCL_Constraint_Visitor *visitor)
{
  return visitor->visit_component (this);
}

// ****************************************************************

ETCL_Dot::~ETCL_Dot (void)
{
  delete this->component_;
}

int
ETCL_Dot::accept (ETCL_Constraint_Visitor *visitor)
{
  return visitor->visit_dot (this);
}

// ****************************************************************

ETCL_Eval::~ETCL_Eval (void)
{
  delete this->component_;
}

int
ETCL_Eval::accept (ETCL_Constraint_Visitor *visitor)
{
  return visitor->visit_eval (this);
}

// ****************************************************************

ETCL_Default::~ETCL_Default (void)
{
  delete this->component_;
}

int
ETCL_Default::accept (ETCL_Constraint_Visitor *visitor)
{
  return visitor->visit_default (this);
}

// ****************************************************************

ETCL_Exist::~ETCL_Exist (void)
{
  delete this->component_;
}

int
ETCL_Exist::accept (ETCL_Constraint_Visitor *visitor)
{
  return visitor->visit_exist (this);
}

// ****************************************************************

ETCL_Unary_Expr::~ETCL_Unary_Expr (void)
{
  delete this->subexpr_;
}

int
ETCL_Unary_Expr::accept (ETCL_Constraint_Visitor *visitor)
{
  return visitor->visit_unary_expr (this);
}

// ****************************************************************

ETCL_Binary_Expr::~ETCL_Binary_Expr (void)
{
  delete this->lhs_;
  delete this->rhs_;
}

int
ETCL_Binary_Expr::accept (ETCL_Constraint_Visitor *visitor)
{
  return visitor->visit_binary_expr (this);
}

// ****************************************************************

ETCL_Preference::~ETCL_Preference (void)
{
  delete this->subexpr_;
}

int
ETCL_Preference::accept (ETCL_Constraint_Visitor *visitor)
{
  return visitor->visit_preference (this);
}

ACE_END_VERSIONED_NAMESPACE_DECL
