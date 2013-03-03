// -*- C++ -*-

//=============================================================================
/**
 *  @file    Timer_Wheel.h
 *
 *  $Id: Timer_Wheel.h 95335 2011-12-15 13:13:17Z msmit $
 *
 *  @author Darrell Brunsch (brunsch@cs.wustl.edu)
 */
//=============================================================================


#ifndef ACE_TIMER_WHEEL_H
#define ACE_TIMER_WHEEL_H
#include /**/ "ace/pre.h"

#include "ace/Timer_Wheel_T.h"
#include "ace/Event_Handler_Handle_Timeout_Upcall.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

// The following typedefs are here for ease of use and backward
// compatibility.

typedef ACE_Timer_Wheel_T<ACE_Event_Handler *,
                         ACE_Event_Handler_Handle_Timeout_Upcall,
                         ACE_SYNCH_RECURSIVE_MUTEX>
        ACE_Timer_Wheel;

typedef ACE_Timer_Wheel_Iterator_T<ACE_Event_Handler *,
                                   ACE_Event_Handler_Handle_Timeout_Upcall,
                                   ACE_SYNCH_RECURSIVE_MUTEX,
                                   ACE_Default_Time_Policy>
        ACE_Timer_Wheel_Iterator;

ACE_END_VERSIONED_NAMESPACE_DECL

#include /**/ "ace/post.h"
#endif /* ACE_TIMER_WHEEL_H */
