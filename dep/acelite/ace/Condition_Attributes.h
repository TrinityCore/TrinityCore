// -*- C++ -*-

//==========================================================================
/**
 *  @file    Condition_Attributes.h
 *
 *  $Id: Condition_Attributes.h 96265 2012-11-13 13:31:10Z johnnyw $
 *
 *   Moved from Synch.h.
 *
 *  @author Douglas C. Schmidt <schmidt@cs.wustl.edu>
 */
//==========================================================================

#ifndef ACE_CONDITION_ATTRIBUTES_H
#define ACE_CONDITION_ATTRIBUTES_H
#include /**/ "ace/pre.h"

#include /**/ "ace/ACE_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/OS_NS_Thread.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

class ACE_Export ACE_Condition_Attributes
{
public:
  /// Constructor
  ACE_Condition_Attributes (int type = ACE_DEFAULT_SYNCH_TYPE);

  /// Destructor
  ~ACE_Condition_Attributes (void);

  /// Accessor for retrieving the current attributes
  const ACE_condattr_t& attributes (void) const;

protected:
  /// The attributes
  ACE_condattr_t attributes_;

private:
  // = Prevent assignment and initialization.
  void operator= (const ACE_Condition_Attributes &);
  ACE_Condition_Attributes (const ACE_Condition_Attributes &);
};

template <class TIME_POLICY>
class ACE_Condition_Attributes_T : public ACE_Condition_Attributes
{
public:
  /// Constructor
  ACE_Condition_Attributes_T (int type = ACE_DEFAULT_SYNCH_TYPE)
    : ACE_Condition_Attributes (type)
  {}

  /// Destructor
  ~ACE_Condition_Attributes_T (void) {}

private:
  // = Prevent assignment and initialization.
  void operator= (const ACE_Condition_Attributes_T<TIME_POLICY> &);
  ACE_Condition_Attributes_T (const ACE_Condition_Attributes_T<TIME_POLICY> &);
};

class ACE_Monotonic_Time_Policy;

template <>
class ACE_Export ACE_Condition_Attributes_T<ACE_Monotonic_Time_Policy>
  : public ACE_Condition_Attributes
{
public:
  /// Constructor
  ACE_Condition_Attributes_T (int type = ACE_DEFAULT_SYNCH_TYPE);

  /// Destructor
  ~ACE_Condition_Attributes_T (void);

private:
  // = Prevent assignment and initialization.
  void operator= (const ACE_Condition_Attributes_T<ACE_Monotonic_Time_Policy> &);
  ACE_Condition_Attributes_T (const ACE_Condition_Attributes_T<ACE_Monotonic_Time_Policy> &);
};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ace/Condition_Attributes.inl"
#endif /* __ACE_INLINE__ */

#include /**/ "ace/post.h"
#endif /* ACE_CONDITION_ATTRIBUTES_H */
