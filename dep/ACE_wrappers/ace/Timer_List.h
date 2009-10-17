// -*- C++ -*-

//=============================================================================
/**
 *  @file    Timer_List.h
 *
 *  $Id: Timer_List.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Doug Schmidt
 */
//=============================================================================


#ifndef ACE_TIMER_LIST_H
#define ACE_TIMER_LIST_H
#include /**/ "ace/pre.h"

#include "ace/Timer_List_T.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

// The following typedefs are here for ease of use and backward
// compatibility.

typedef ACE_Timer_List_T<ACE_Event_Handler *,
                         ACE_Event_Handler_Handle_Timeout_Upcall<ACE_SYNCH_RECURSIVE_MUTEX>,
                         ACE_SYNCH_RECURSIVE_MUTEX>
        ACE_Timer_List;

typedef ACE_Timer_List_Iterator_T<ACE_Event_Handler *,
                                  ACE_Event_Handler_Handle_Timeout_Upcall<ACE_SYNCH_RECURSIVE_MUTEX>,
                                  ACE_SYNCH_RECURSIVE_MUTEX>
        ACE_Timer_List_Iterator;

ACE_END_VERSIONED_NAMESPACE_DECL

#include /**/ "ace/post.h"
#endif /* ACE_TIMER_LIST_H */

