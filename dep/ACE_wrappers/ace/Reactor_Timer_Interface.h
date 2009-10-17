// -*- C++ -*-
//=============================================================================
/**
 *  @file    Reactor_Timer_Interface.h
 *
 *  $Id: Reactor_Timer_Interface.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Irfan Pyarali <irfan@oomworks.com>
 */
//=============================================================================
#ifndef ACE_REACTOR_TIMER_INTERFACE_H
#define ACE_REACTOR_TIMER_INTERFACE_H
#include /**/ "ace/pre.h"
#include "ace/Time_Value.h"
#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
class ACE_Event_Handler;
/**
 * @class ACE_Reactor_Timer_Interface
 *
 * @brief Interface for timer related methods on the Reactor.
 */
class ACE_Export ACE_Reactor_Timer_Interface
{
public:
  virtual ~ACE_Reactor_Timer_Interface (void);
  virtual long schedule_timer (ACE_Event_Handler *event_handler,
                               const void *arg,
                               const ACE_Time_Value &delay,
                               const ACE_Time_Value &interval = ACE_Time_Value::zero) = 0;
  virtual int reset_timer_interval (long timer_id,
                                    const ACE_Time_Value &interval) = 0;
  virtual int cancel_timer (long timer_id,
                            const void **arg = 0,
                            int dont_call_handle_close = 1) = 0;
  virtual int cancel_timer (ACE_Event_Handler *event_handler,
                            int dont_call_handle_close = 1) = 0;
};
ACE_END_VERSIONED_NAMESPACE_DECL
#include /**/ "ace/post.h"
#endif /* ACE_REACTOR_TIMER_INTERFACE_H */

