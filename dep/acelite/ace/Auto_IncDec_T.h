// -*- C++ -*-

//=============================================================================
/**
 *  @file    Auto_IncDec_T.h
 *
 *  $Id: Auto_IncDec_T.h 92353 2010-10-25 06:34:35Z johnnyw $
 *
 *  @author Edan Ayal <EdanA@cti2.com>
 */
//=============================================================================


#ifndef ACE_AUTO_INCDEC_T_H
#define ACE_AUTO_INCDEC_T_H

#include /**/ "ace/pre.h"

#include /**/ "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/Global_Macros.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class ACE_Auto_IncDec
 *
 * @brief This class automatically increments and decrements a
 * parameterized counter.
 *
 * This data structure is meant to be used within a method,
 * function, or scope.  The actual parameter given for the
 * @c ACE_SAFELY_INCREMENTABLE_DECREMENTABLE template parameter
 * must provide at least operators ++ and --.
 */
template <class ACE_SAFELY_INCREMENTABLE_DECREMENTABLE>
class ACE_Auto_IncDec : private ACE_Copy_Disabled
{
public:
  /// Implicitly increment the counter.
  ACE_Auto_IncDec (ACE_SAFELY_INCREMENTABLE_DECREMENTABLE &counter);

  /// Implicitly decrement the counter.
  ~ACE_Auto_IncDec (void);

  /// Dump the state of an object.
  void dump (void) const;

protected:
  /// Reference to the @c ACE_SAFELY_INCREMENTABLE_DECREMENTABLE counter
  /// we're incrementing/decrementing.
  ACE_SAFELY_INCREMENTABLE_DECREMENTABLE &counter_;
};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ace/Auto_IncDec_T.inl"
#endif /* __ACE_INLINE__ */

#if defined (ACE_TEMPLATES_REQUIRE_SOURCE)
#include "ace/Auto_IncDec_T.cpp"
#endif /* ACE_TEMPLATES_REQUIRE_SOURCE */

#if defined (ACE_TEMPLATES_REQUIRE_PRAGMA)
#pragma implementation ("Auto_IncDec_T.cpp")
#endif /* ACE_TEMPLATES_REQUIRE_PRAGMA */

#include /**/ "ace/post.h"

#endif /* ACE_AUTO_INCDEC_T_H */
