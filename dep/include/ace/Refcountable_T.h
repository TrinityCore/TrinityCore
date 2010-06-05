// -*- C++ -*-

//=============================================================================
/**
 *  @file   Refcountable_T.h
 *
 *  $Id: Refcountable_T.h 81409 2008-04-24 08:30:48Z johnnyw $
 *
 * @author Doug Schmidt
 * @author Johnny Willemsen
 */
//=============================================================================
#ifndef ACE_REFCOUNTABLE_T_H
#define ACE_REFCOUNTABLE_T_H
#include /**/ "ace/pre.h"

#include /**/ "ace/ACE_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/Atomic_Op.h"
#include "ace/Synch_Traits.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

template <class ACE_LOCK>
class ACE_Refcountable_T
{
public:
  /// Destructor.
  virtual ~ACE_Refcountable_T (void);

  // = Increment/Decrement refcount
  long increment (void);
  long decrement (void);

  /// Returns the current refcount.
  long refcount (void) const;

protected:
  /// Protected constructor.
  ACE_Refcountable_T (long refcount);

  /// Current refcount.
  ACE_Atomic_Op <ACE_LOCK, long> refcount_;
};

typedef ACE_Refcountable_T<ACE_Null_Mutex> ACE_Refcountable;

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ace/Refcountable_T.inl"
#endif /* __ACE_INLINE__ */

#if defined (ACE_TEMPLATES_REQUIRE_SOURCE)
#include "ace/Refcountable_T.cpp"
#endif /* ACE_TEMPLATES_REQUIRE_SOURCE */

#if defined (ACE_TEMPLATES_REQUIRE_PRAGMA)
#pragma implementation ("Refcountable_T.cpp")
#endif /* ACE_TEMPLATES_REQUIRE_PRAGMA */

#include /**/ "ace/post.h"
#endif /*ACE_REFCOUNTABLE_T_H*/

