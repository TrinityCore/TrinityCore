/* -*- C++ -*- */

//=============================================================================
/**
 *  @file   FlReactor.h
 *
 *  $Id: FlReactor.h 82723 2008-09-16 09:35:44Z johnnyw $
 *
 *  @author Carlos O'Ryan <coryan@cs.wustl.edu>
 *  @author Based in part in the ACE_XtReactor implementation by
 *  @author Eric C. Newton's <ecn@clark.net>
 *  @author Kirill Rybaltchenko <Kirill.Rybaltchenko@cern.ch>
 *  @author Douglas C. Schmidt <schmidt@cs.wustl.edu>
 */
//=============================================================================


#ifndef ACE_FLREACTOR_H
#define ACE_FLREACTOR_H
#include /**/ "ace/pre.h"

#include /**/ "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/FlReactor/ACE_FlReactor_export.h"
#include "ace/Select_Reactor.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class ACE_FlReactor
 *
 * @brief A Reactor implementation that uses the Fast-Light (FL) toolkit
 * for event demultiplexing.  This will let us integrate the FL
 * toolkit with ACE and/or TAO.
 *
 * As many other GUI toolkits FL supports a minimal set of
 * callbacks to handle event demultiplexing, namely simple methods
 * to add file descriptors to the event demuxing set or timeout
 * events.  This class adapts this simple mechanisms so they are
 * compatible with ACE's Reactor.
 */
class ACE_FlReactor_Export ACE_FlReactor : public ACE_Select_Reactor
{

public:
  // = Initialization and termination methods.
  ACE_FlReactor (size_t size = DEFAULT_SIZE,
                 bool restart = false,
                 ACE_Sig_Handler * = 0);
  virtual ~ACE_FlReactor (void);

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
  // = Register timers/handles with Fl.
  /// Register a single @a handler.
  virtual int register_handler_i (ACE_HANDLE handle,
                                  ACE_Event_Handler *handler,
                                  ACE_Reactor_Mask mask);

  /// Register a set of <handlers>.
  virtual int register_handler_i (const ACE_Handle_Set &handles,
                                  ACE_Event_Handler *handler,
                                  ACE_Reactor_Mask mask);

  /// Remove the <handler> associated with this @a handle.
  virtual int remove_handler_i (ACE_HANDLE handle,
                                ACE_Reactor_Mask mask);

  /// Remove a set of <handles>.
  virtual int remove_handler_i (const ACE_Handle_Set &handles,
                                ACE_Reactor_Mask);

  /// Wait for events to occur.
  virtual int wait_for_multiple_events (ACE_Select_Reactor_Handle_Set &,
                                        ACE_Time_Value *);

private:
  /// This method ensures there's an Fl timeout for the first timeout
  /// in the Reactor's Timer_Queue.
  void reset_timeout (void);

  // = Integrate with the FL callback function mechanism.
  static void fl_io_proc (int fd, void*);
  static void fl_timeout_proc (void*);

  /// Deny access since member-wise won't work...
  ACE_FlReactor (const ACE_FlReactor &);
  ACE_FlReactor &operator = (const ACE_FlReactor &);
};

ACE_END_VERSIONED_NAMESPACE_DECL

#include /**/ "ace/post.h"
#endif /* ACE_FLREACTOR_H */
