// -*- C++ -*-

//=============================================================================
/**
 *  @file    XtReactor.h
 *
 *  $Id: XtReactor.h 91743 2010-09-13 18:24:51Z johnnyw $
 *
 *  @author Eric C. Newton <ecn@clark.net>
 *  @author Kirill Rybaltchenko <Kirill.Rybaltchenko@cern.ch>
 *  @author Douglas C. Schmidt <schmidt@cs.wustl.edu>
 */
//=============================================================================


#ifndef ACE_XTREACTOR_H
#define ACE_XTREACTOR_H
#include /**/ "ace/pre.h"

#include /**/ "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */
#include "ace/XtReactor/ACE_XtReactor_export.h"
#include "ace/Select_Reactor.h"

#include /**/ <X11/Intrinsic.h>

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class ACE_XtReactorID
 *
 * @brief This little class is necessary due to the way that Microsoft
 * implements sockets to be pointers rather than indices.
 */
class ACE_XtReactor_Export ACE_XtReactorID
{
public:
  /// Magic cookie.
  XtInputId id_;

  /// Underlying handle.
  ACE_HANDLE handle_;

  /// Pointer to next node in the linked list.
  ACE_XtReactorID *next_;
};

/**
 * @class ACE_XtReactor
 *
 * @brief An object-oriented event demultiplexor and event handler
 * dispatcher that uses the X Toolkit functions.
 */
class ACE_XtReactor_Export ACE_XtReactor : public ACE_Select_Reactor
{
public:
  // = Initialization and termination methods.
  ACE_XtReactor (XtAppContext context = 0,
                 size_t size = DEFAULT_SIZE,
                 bool restart = false,
                 ACE_Sig_Handler * = 0);
  virtual ~ACE_XtReactor (void);

  XtAppContext context (void) const;
  void context (XtAppContext);

  // = Timer operations.
  virtual long schedule_timer (ACE_Event_Handler *event_handler,
                               const void *arg,
                               const ACE_Time_Value &delay,
                               const ACE_Time_Value &interval);
  virtual int reset_timer_interval (long timer_id,
                                    const ACE_Time_Value &interval);
  virtual int cancel_timer (ACE_Event_Handler *handler,
                            int dont_call_handle_close = 1);

  virtual int cancel_timer (long timer_id,
                            const void **arg = 0,
                            int dont_call_handle_close = 1);

protected:
  // = Register timers/handles with Xt.
  /// Register a single @a handler.
  virtual int register_handler_i (ACE_HANDLE handle,
                                  ACE_Event_Handler *handler,
                                  ACE_Reactor_Mask mask);

  /// Register a set of <handlers>.
  virtual int register_handler_i (const ACE_Handle_Set &handles,
                                  ACE_Event_Handler *handler,
                                  ACE_Reactor_Mask mask);

  /// Remove the @a handler associated with this @a handle.
  virtual int remove_handler_i (ACE_HANDLE handle,
                                ACE_Reactor_Mask mask);

  /// Remove a set of <handles>.
  virtual int remove_handler_i (const ACE_Handle_Set &handles,
                                ACE_Reactor_Mask);

  /// Suspend the <Event_Handler> associated with @a handle
  virtual int suspend_i (ACE_HANDLE handle);

  /// Resume the <Event_Handler> associated with @a handle
  virtual int resume_i (ACE_HANDLE handle);

  /// Synchronize XtInputHandler for @a handle
  virtual void synchronize_XtInput(ACE_HANDLE handle);

  /// Compute needed Xt condition by looking at base class wait set.
  virtual int compute_Xt_condition(ACE_HANDLE handle);

  /// Wait for events to occur.
  virtual int wait_for_multiple_events (ACE_Select_Reactor_Handle_Set &,
                                        ACE_Time_Value *);

  ///Wait for Xt events to occur.
  virtual int XtWaitForMultipleEvents (int,
                                       ACE_Select_Reactor_Handle_Set &,
                                       ACE_Time_Value *);

  XtAppContext context_;
  ACE_XtReactorID *ids_;
  XtIntervalId timeout_;

private:
  /// This method ensures there's an Xt timeout for the first timeout
  /// in the Reactor's Timer_Queue.
  void reset_timeout (void);

  // = Integrate with the X callback function mechanism.
  static void TimerCallbackProc (XtPointer closure, XtIntervalId *id);
  static void InputCallbackProc (XtPointer closure, int* source, XtInputId *id);

  /// Deny access since member-wise won't work...
  ACE_XtReactor (const ACE_XtReactor &);
  ACE_XtReactor &operator = (const ACE_XtReactor &);
};

ACE_END_VERSIONED_NAMESPACE_DECL

#include /**/ "ace/post.h"

#endif /* ACE_XTREACTOR_H */
