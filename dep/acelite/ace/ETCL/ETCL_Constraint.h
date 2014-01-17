// -*- C++ -*-

//=============================================================================
/**
 *  @file    ETCL_Constraint.h
 *
 *  $Id: ETCL_Constraint.h 94030 2011-05-08 17:58:47Z johnnyw $
 *
 *  @author Carlos O'Ryan (coryan@cs.wustl.edu)
 *  @author Jeff Parsons (j.parsons@vanderbilt.edu)
 */
//=============================================================================

#ifndef ACE_ETCL_CONSTRAINT_H
#define ACE_ETCL_CONSTRAINT_H

#include /**/ "ace/pre.h"

#include "ace/SString.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/CDR_Base.h"

#include "ace/ETCL/ace_etcl_export.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

typedef unsigned long Literal_Type;

class ETCL_Constraint_Visitor;

class ACE_ETCL_Export ETCL_Constraint
{
public:
  /// Constructor and destructor
  ETCL_Constraint (void);
  virtual ~ETCL_Constraint (void);

  virtual int accept (ETCL_Constraint_Visitor *visitor);

protected:
  enum
  {
    ACE_ETCL_STRING,
    ACE_ETCL_DOUBLE,
    ACE_ETCL_UNSIGNED,
    ACE_ETCL_SIGNED,
    ACE_ETCL_INTEGER,
    ACE_ETCL_BOOLEAN,
    ACE_ETCL_COMPONENT,
    ACE_ETCL_UNKNOWN
  };
};

// ****************************************************************

class ACE_ETCL_Export ETCL_Literal_Constraint
  : public ETCL_Constraint
{
public:
  ETCL_Literal_Constraint (void);

  // = Constructors for each of the various types of literals.

  explicit ETCL_Literal_Constraint (ACE_CDR::ULong uinteger);
  explicit ETCL_Literal_Constraint (ACE_CDR::Long integer);
  explicit ETCL_Literal_Constraint (ACE_CDR::Boolean boolean);
  explicit ETCL_Literal_Constraint (ACE_CDR::Double doub);
  explicit ETCL_Literal_Constraint (const char* str);

  /// Copy constructor
  ETCL_Literal_Constraint (const ETCL_Literal_Constraint& lit);

  /// Destructor.
  virtual ~ETCL_Literal_Constraint(void);

  /// Visitor accept method.
  virtual int accept (ETCL_Constraint_Visitor* visitor);

  Literal_Type expr_type (void) const;

  /// Assignment operator.
  void operator= (const ETCL_Literal_Constraint& co);

  // Conversion routines.
  operator ACE_CDR::Boolean (void) const;
  operator ACE_CDR::ULong (void) const;
  operator ACE_CDR::Long (void) const;
  operator ACE_CDR::Double (void) const;
  operator const char* (void) const;

  // Return the type represented by this MysteryOperand.

  // = Boolean operators.

  bool
  operator< (const ETCL_Literal_Constraint& rhs);

  bool
  operator<= (const ETCL_Literal_Constraint& rhs);

  bool
  operator> (const ETCL_Literal_Constraint& rhs);

  bool
  operator>= (const ETCL_Literal_Constraint& rhs);

  bool
  operator== (const ETCL_Literal_Constraint& rhs);

  bool
  operator!= (const ETCL_Literal_Constraint& rhs);

  // = Arithmetic operators.

  ETCL_Literal_Constraint
  operator+ (const ETCL_Literal_Constraint& rhs);

  ETCL_Literal_Constraint
  operator- (const ETCL_Literal_Constraint& rhs);

  ETCL_Literal_Constraint
  operator* (const ETCL_Literal_Constraint& rhs);

  ETCL_Literal_Constraint
  operator/ (const ETCL_Literal_Constraint& rhs);

  // Unary minus.
  ETCL_Literal_Constraint
  operator- (void);

  /// Ensure both operands are of the same simple numeric type.
  virtual Literal_Type
  widest_type (const ETCL_Literal_Constraint& rhs);

protected:
  /// Private copy method.
  void copy (const ETCL_Literal_Constraint& co);

  /// Union of the possible literal types.
  union
  {
    char* str_;
    ACE_CDR::ULong uinteger_;
    ACE_CDR::Long integer_;
    ACE_CDR::Boolean bool_;
    ACE_CDR::Double double_;
  } op_;

  /// The actual types of the ETCL_Literal_Constraint.
  Literal_Type type_;
};

// ****************************************************************

class ACE_ETCL_Export ETCL_Identifier : public ETCL_Constraint
{
public:
  ETCL_Identifier (const char *value);

  /// Get the value
  const char *value (void) const;

  // = The Constraint methods.
  int accept (ETCL_Constraint_Visitor *visitor);

private:
  /// The value
  ACE_CString string_;
};

// ****************************************************************

class ACE_ETCL_Export ETCL_Union_Value : public ETCL_Constraint
{
public:
  ETCL_Union_Value (int sign,
                    ETCL_Constraint *integer);
  explicit ETCL_Union_Value (ETCL_Constraint *string = 0);
  virtual ~ETCL_Union_Value (void);

  int sign (void) const;
  ETCL_Literal_Constraint *integer (void) const;
  ETCL_Literal_Constraint *string (void) const;

  virtual int accept (ETCL_Constraint_Visitor *visitor);

private:
  int sign_;
  ETCL_Literal_Constraint *integer_;
  ETCL_Literal_Constraint *string_;
};

class ACE_ETCL_Export ETCL_Union_Pos : public ETCL_Constraint
{
public:
  ETCL_Union_Pos (ETCL_Constraint *union_value = 0,
                  ETCL_Constraint *component = 0);
  virtual ~ETCL_Union_Pos (void);

  ETCL_Union_Value *union_value (void) const;
  ETCL_Constraint *component (void) const;

  virtual int accept (ETCL_Constraint_Visitor *visitor);

private:
  ETCL_Union_Value *union_value_;
  ETCL_Constraint *component_;
};

class ACE_ETCL_Export ETCL_Component_Pos : public ETCL_Constraint
{
public:
  ETCL_Component_Pos (ETCL_Constraint *integer = 0,
                      ETCL_Constraint *component = 0);
  virtual ~ETCL_Component_Pos (void);

  ETCL_Literal_Constraint *integer (void) const;
  ETCL_Constraint *component (void) const;

  virtual int accept (ETCL_Constraint_Visitor *visitor);

private:
  ETCL_Literal_Constraint *integer_;
  ETCL_Constraint *component_;
};

class ACE_ETCL_Export ETCL_Component_Assoc : public ETCL_Constraint
{
public:
  ETCL_Component_Assoc (ETCL_Constraint *identifier = 0,
                        ETCL_Constraint *component = 0);
  virtual ~ETCL_Component_Assoc (void);

  ETCL_Identifier *identifier (void) const;
  ETCL_Constraint *component (void) const;

  virtual int accept (ETCL_Constraint_Visitor *visitor);

private:
  ETCL_Identifier *identifier_;
  ETCL_Constraint *component_;
};

class ACE_ETCL_Export ETCL_Component_Array : public ETCL_Constraint
{
public:
  ETCL_Component_Array (ETCL_Constraint *integer = 0,
                        ETCL_Constraint *component = 0);
  virtual ~ETCL_Component_Array (void);

  ETCL_Literal_Constraint *integer (void) const;
  ETCL_Constraint *component (void) const;

  virtual int accept (ETCL_Constraint_Visitor *visitor);

private:
  ETCL_Literal_Constraint *integer_;
  ETCL_Constraint *component_;
};

class ACE_ETCL_Export ETCL_Special : public ETCL_Constraint
{
public:
  ETCL_Special (void);
  ETCL_Special (int type);
  virtual ~ETCL_Special (void);

  int type (void) const;

  virtual int accept (ETCL_Constraint_Visitor *visitor);

private:
  int type_;
};

class ACE_ETCL_Export ETCL_Component : public ETCL_Constraint
{
public:
  ETCL_Component (ETCL_Constraint *identifier = 0,
                  ETCL_Constraint *component = 0);
  virtual ~ETCL_Component (void);

  ETCL_Identifier *identifier (void) const;
  ETCL_Constraint *component (void) const;

  virtual int accept (ETCL_Constraint_Visitor *visitor);

private:
  ETCL_Identifier *identifier_;
  ETCL_Constraint *component_;
};

class ACE_ETCL_Export ETCL_Dot : public ETCL_Constraint
{
public:
  explicit ETCL_Dot (ETCL_Constraint *component = 0);
  virtual ~ETCL_Dot (void);

  ETCL_Constraint *component (void) const;

  virtual int accept (ETCL_Constraint_Visitor *visitor);

private:
  ETCL_Constraint *component_;
};

class ACE_ETCL_Export ETCL_Eval : public ETCL_Constraint
{
public:
  explicit ETCL_Eval (ETCL_Constraint *component = 0);
  virtual ~ETCL_Eval (void);

  ETCL_Constraint *component (void) const;

  virtual int accept (ETCL_Constraint_Visitor *visitor);

private:
  ETCL_Constraint *component_;
};

class ACE_ETCL_Export ETCL_Default : public ETCL_Constraint
{
public:
  explicit ETCL_Default (ETCL_Constraint *component = 0);
  virtual ~ETCL_Default (void);

  ETCL_Constraint *component (void) const;

  virtual int accept (ETCL_Constraint_Visitor *visitor);

private:
  ETCL_Constraint *component_;
};

class ACE_ETCL_Export ETCL_Exist : public ETCL_Constraint
{
public:
  explicit ETCL_Exist (ETCL_Constraint *component = 0);
  virtual ~ETCL_Exist (void);

  ETCL_Constraint *component (void) const;

  virtual int accept (ETCL_Constraint_Visitor *visitor);

private:
  ETCL_Constraint *component_;
};

class ACE_ETCL_Export ETCL_Unary_Expr : public ETCL_Constraint
{
public:
  ETCL_Unary_Expr (int type,
                   ETCL_Constraint *subexpr);
  virtual ~ETCL_Unary_Expr (void);

  int type (void) const;
  ETCL_Constraint *subexpr (void) const;

  int accept (ETCL_Constraint_Visitor *visitor);

private:
  int type_;
  ETCL_Constraint *subexpr_;
};

class ACE_ETCL_Export ETCL_Binary_Expr : public ETCL_Constraint
{
public:
  ETCL_Binary_Expr (int type,
                    ETCL_Constraint *lhs,
                    ETCL_Constraint *rhs);
  virtual ~ETCL_Binary_Expr (void);

  int type (void) const;
  ETCL_Constraint *rhs (void) const;
  ETCL_Constraint *lhs (void) const;

  int accept (ETCL_Constraint_Visitor *visitor);

private:
  int type_;
  ETCL_Constraint *lhs_;
  ETCL_Constraint *rhs_;
};

class ACE_ETCL_Export ETCL_Preference : public ETCL_Constraint
{
public:
  ETCL_Preference (void);
  ETCL_Preference (int type,
                   ETCL_Constraint *subexpr = 0);
  virtual ~ETCL_Preference (void);

  int type (void) const;
  ETCL_Constraint *subexpr (void) const;

  virtual int accept (ETCL_Constraint_Visitor *visitor);

private:
  int type_;
  ETCL_Constraint *subexpr_;
};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ace/ETCL/ETCL_Constraint.inl"
#endif /* __ACE_INLINE__ */

#include /**/ "ace/post.h"

#endif // ACE_ETCL_CONSTRAINT_H
