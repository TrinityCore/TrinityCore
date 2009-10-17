// -*- C++ -*-
//=============================================================================
/**
 *  @file    Timer_Queuefwd.h
 *
 *  $Id: Timer_Queuefwd.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  Forward declarations and typedefs of ACE_Timer_Queue class.
 *
 *  @author Ossama Othman <ossama@dre.vanderbilt.edu>
 */
//=============================================================================
#ifndef ACE_TIMER_QUEUE_FWD_H
#define ACE_TIMER_QUEUE_FWD_H
#include /**/ "ace/pre.h"
#include "ace/Synch_Traits.h"
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
template <class TYPE, class FUNCTOR, class ACE_LOCK> class ACE_Timer_Queue_T;
template <class ACE_LOCK> class ACE_Event_Handler_Handle_Timeout_Upcall;
class ACE_Event_Handler;
typedef ACE_Timer_Queue_T<ACE_Event_Handler *,
                          ACE_Event_Handler_Handle_Timeout_Upcall<ACE_SYNCH_RECURSIVE_MUTEX>,
                          ACE_SYNCH_RECURSIVE_MUTEX>
        ACE_Timer_Queue;
ACE_END_VERSIONED_NAMESPACE_DECL
#include /**/ "ace/post.h"
#endif  /* ACE_TIMER_QUEUE_FWD_H */

