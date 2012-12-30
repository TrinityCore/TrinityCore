// -*- C++ -*-

//==========================================================================
/**
 *  @file    Event.h
 *
 *  $Id: Event.h 96220 2012-11-06 10:03:41Z mcorino $
 *
 *   Moved from Synch.h.
 *
 *  @author Douglas C. Schmidt <schmidt@cs.wustl.edu>
 */
//==========================================================================

#ifndef ACE_EVENT_H
#define ACE_EVENT_H
#include /**/ "ace/pre.h"

#include /**/ "ace/ACE_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/Event_Base.h"
#include "ace/Time_Policy.h"
#include "ace/Time_Value_T.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class ACE_Event_T
 *
 * @brief A wrapper around the Win32 event locking mechanism.
 *
 * Portable implementation of an Event mechanism, which is native to
 * Win32, but must be emulated on UNIX.  All platforms support
 * process-scope locking support.  However, only Win32 platforms
 * support global naming and system-scope locking support.
 */
template <class TIME_POLICY = ACE_System_Time_Policy>
class ACE_Event_T : public ACE_Event_Base
{
public:
  /// Constructor that creates event.
  ACE_Event_T (int manual_reset = 0,
               int initial_state = 0,
               int type = USYNC_THREAD,
               const ACE_TCHAR *name = 0,
               void *arg = 0,
               LPSECURITY_ATTRIBUTES sa = 0);

  /// Implicitly destroy the event variable.
  virtual ~ACE_Event_T (void);

  /// Get the current time of day according to the queue's TIME_POLICY.
  /// Allows users to initialize timeout values using correct time policy.
  ACE_Time_Value_T<TIME_POLICY> gettimeofday (void) const;

  /// Allows applications to control how the event gets the time
  /// of day.
  void set_time_policy (TIME_POLICY const & time_policy);

  /// Declare the dynamic allocation hooks
  ACE_ALLOC_HOOK_DECLARE;

protected:

  /// The policy to return the current time of day
  TIME_POLICY time_policy_;

private:
  // = Prevent copying.
  ACE_Event_T (const ACE_Event_T<TIME_POLICY>& event);
  const ACE_Event_T &operator= (const ACE_Event_T<TIME_POLICY> &rhs);
};

typedef ACE_Event_T<ACE_System_Time_Policy> ACE_Event;

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ace/Event.inl"
#endif /* __ACE_INLINE__ */

#if defined (ACE_TEMPLATES_REQUIRE_SOURCE)
#include "ace/Event.cpp"
#endif /* ACE_TEMPLATES_REQUIRE_SOURCE */

#if defined (ACE_TEMPLATES_REQUIRE_PRAGMA)
#pragma implementation ("Event.cpp")
#endif /* ACE_TEMPLATES_REQUIRE_PRAGMA */

#include /**/ "ace/post.h"
#endif /* ACE_EVENT_H */
