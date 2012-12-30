// -*- C++ -*-

//==========================================================================
/**
 *  @file    Auto_Event.h
 *
 *  $Id: Auto_Event.h 96220 2012-11-06 10:03:41Z mcorino $
 *
 *   Moved from Synch.h.
 *
 *  @author Douglas C. Schmidt <schmidt@cs.wustl.edu>
 */
//==========================================================================

#ifndef ACE_AUTO_EVENT_H
#define ACE_AUTO_EVENT_H
#include /**/ "ace/pre.h"

#include /**/ "ace/ACE_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/Event.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class ACE_Auto_Event
 *
 * @brief Auto Events.
 *
 * Specialization of Event mechanism which wakes up one waiting
 * thread on @c signal.  All platforms support process-scope locking
 * support.  However, only Win32 platforms support global naming and
 * system-scope locking support.
 */
template <class TIME_POLICY = ACE_System_Time_Policy>
class ACE_Auto_Event_T : public ACE_Event_T<TIME_POLICY>
{
public:
  /// Constructor which will create auto event
  ACE_Auto_Event_T (int initial_state = 0,
                    int type = USYNC_THREAD,
                    const char *name = 0,
                    void *arg = 0);

#if defined (ACE_HAS_WCHAR)
  /// Constructor which will create auto event (wchar_t version)
  ACE_Auto_Event_T (int initial_state,
                    int type,
                    const wchar_t *name,
                    void *arg = 0);
#endif /* ACE_HAS_WCHAR */

  /// Default dtor.
  virtual ~ACE_Auto_Event_T (void);

  /// Dump the state of an object.
  void dump (void) const;

  /// Declare the dynamic allocation hooks
  ACE_ALLOC_HOOK_DECLARE;
};

class ACE_Auto_Event :
  public ACE_Auto_Event_T<ACE_System_Time_Policy>
{
public:
  /// Constructor which will create auto event
  ACE_Auto_Event (int initial_state = 0,
                  int type = USYNC_THREAD,
                  const char *name = 0,
                  void *arg = 0)
  : ACE_Auto_Event_T<ACE_System_Time_Policy> (initial_state, type, name, arg)
  {}

#if defined (ACE_HAS_WCHAR)
  /// Constructor which will create auto event (wchar_t version)
  ACE_Auto_Event (int initial_state,
                  int type,
                  const wchar_t *name,
                  void *arg = 0)
  : ACE_Auto_Event_T<ACE_System_Time_Policy> (initial_state, type, name, arg)
  {}
#endif /* ACE_HAS_WCHAR */

  /// Default dtor.
  virtual ~ACE_Auto_Event (void) {}
};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ace/Auto_Event.inl"
#endif /* __ACE_INLINE__ */

#if defined (ACE_TEMPLATES_REQUIRE_SOURCE)
#include "ace/Auto_Event.cpp"
#endif /* ACE_TEMPLATES_REQUIRE_SOURCE */

#if defined (ACE_TEMPLATES_REQUIRE_PRAGMA)
#pragma implementation ("Auto_Event.cpp")
#endif /* ACE_TEMPLATES_REQUIRE_PRAGMA */

#include /**/ "ace/post.h"
#endif /* ACE_AUTO_EVENT_H */
