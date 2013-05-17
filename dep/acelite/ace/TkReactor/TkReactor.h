// -*- C++ -*-

//=============================================================================
/**
 *  @file    TkReactor.h
 *
 *  $Id: TkReactor.h 82723 2008-09-16 09:35:44Z johnnyw $
 *
 *  @author Nagarajan Surendran <naga@cs.wustl.edu>
 */
//=============================================================================


#ifndef ACE_TKREACTOR_H
#define ACE_TKREACTOR_H
#include /**/ "ace/pre.h"

#include /**/ "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/TkReactor/ACE_TkReactor_export.h"
#include "ace/Select_Reactor.h"
#include /**/ <tk.h>

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class ACE_TkReactorID
 *
 * @brief This little class is necessary due to the way that Microsoft
 * implements sockets to be pointers rather than indices.
 */
class ACE_TkReactor_Export ACE_TkReactorID
{
public:
  /// Underlying handle.
  ACE_HANDLE handle_;

  /// Pointer to next node in the linked list.
  ACE_TkReactorID *next_;
};

class ACE_TkReactor;

class ACE_TkReactor_Export ACE_TkReactor_Input_Callback
{
public:
  ACE_TkReactor *reactor_;
  ACE_HANDLE handle_;
};

/**
 * @class ACE_TkReactor
 *
 * @brief An object-oriented event demultiplexor and event handler
 * dispatcher that uses the Tk functions.
 */
class ACE_TkReactor_Export ACE_TkReactor : public ACE_Select_Reactor
{
public:
  // = Initialization and termination methods.
  ACE_TkReactor (size_t size = DEFAULT_SIZE,
                 bool restart = false,
                 ACE_Sig_Handler * = 0);

  virtual ~ACE_TkReactor (void);

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
  // = Register timers/handles with Tk.
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

  /// Removes an Tk FileHandler.
  virtual void remove_TkFileHandler (ACE_HANDLE handle);

  /// Wait for events to occur.
  virtual int wait_for_multiple_events (ACE_Select_Reactor_Handle_Set &,
                                        ACE_Time_Value *);

  ///Wait for Tk events to occur.
  virtual int TkWaitForMultipleEvents (int,
                                       ACE_Select_Reactor_Handle_Set &,
                                       ACE_Time_Value *);

  ACE_TkReactorID *ids_;
  Tk_TimerToken timeout_;

private:
  /// This method ensures there's a Tk timeout for the first timeout in
  /// the Reactor's Timer_Queue.
  void reset_timeout (void);

  // = Integrate with the X callback function mechanism.
  static void TimerCallbackProc (ClientData cd);
  static void InputCallbackProc (ClientData cd,int mask);

  /// Deny access since member-wise won't work...
  ACE_TkReactor (const ACE_TkReactor &);
  ACE_TkReactor &operator = (const ACE_TkReactor &);
};

ACE_END_VERSIONED_NAMESPACE_DECL

#include /**/ "ace/post.h"
#endif /* ACE_TK_REACTOR_H */
