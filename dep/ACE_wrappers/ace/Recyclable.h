// -*- C++ -*-
//=============================================================================
/**
 *  @file   Recyclable.h
 *
 *  $Id: Recyclable.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Doug Schmidt
 */
//=============================================================================
#ifndef ACE_RECYCLABLE_H
#define ACE_RECYCLABLE_H
#include /**/ "ace/pre.h"
#include /**/ "ace/ACE_export.h"
#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
/// States of a recyclable object.
enum ACE_Recyclable_State
{
  /// Idle and can be purged.
  ACE_RECYCLABLE_IDLE_AND_PURGABLE,
  /// Idle but cannot be purged.
  ACE_RECYCLABLE_IDLE_BUT_NOT_PURGABLE,
  /// Can be purged, but is not idle (mostly for debugging).
  ACE_RECYCLABLE_PURGABLE_BUT_NOT_IDLE,
  /// Busy (i.e., cannot be recycled or purged).
  ACE_RECYCLABLE_BUSY,
  /// Closed.
  ACE_RECYCLABLE_CLOSED,
  /// Unknown state.
  ACE_RECYCLABLE_UNKNOWN
};
/**
 * @class ACE_Recyclable
 */
class ACE_Export ACE_Recyclable
{
public:
  /// Destructor.
  virtual ~ACE_Recyclable (void);
  /// Get the recyclable bit
  ACE_Recyclable_State recycle_state (void) const;
  /// Set the recyclable bit
  void recycle_state (ACE_Recyclable_State new_state);
protected:
  /// Constructor.
  ACE_Recyclable (ACE_Recyclable_State initial_state);
protected:
  /// Our state.
  ACE_Recyclable_State recycle_state_;
};
ACE_END_VERSIONED_NAMESPACE_DECL
#if defined (__ACE_INLINE__)
#include "ace/Recyclable.inl"
#endif /* __ACE_INLINE __ */
#include /**/ "ace/post.h"
#endif /*ACE_RECYCLABLE_STATE_H*/

