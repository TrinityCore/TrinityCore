/* -*- C-*- */

//=============================================================================
/**
 *  @file   FoxReactor.h
 *
 *  $Id: FoxReactor.h 93117 2011-01-20 12:11:28Z mcorino $
 *
 *  @author Dmitriy Nikitinskiy <nick@bel.ru>
 *  @author Based in part in the ACE_XtReactor implementation by
 *  @author Eric C. Newton's <ecn@clark.net>
 *  @author Kirill Rybaltchenko <Kirill.Rybaltchenko@cern.ch>
 *  @author Douglas C. Schmidt <schmidt@cs.wustl.edu>
 */
//=============================================================================


#ifndef ACE_FOXREACTOR_H
#define ACE_FOXREACTOR_H
#include /**/ "ace/pre.h"

#include "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/Select_Reactor.h"
#include "ace/FoxReactor/ACE_FoxReactor_export.h"

#include <fx.h>

/**
 * @class ACE_FoxReactor
 *
 * @brief A Reactor implementation that uses the FOX toolkit (www.fox-toolkit.org)
 * for event demultiplexing.  This will let us integrate the FOX
 * toolkit with ACE and/or TAO.
 *
 */
class ACE_FoxReactor_Export ACE_FoxReactor : public FXObject, public ACE_Select_Reactor
{
  FXDECLARE(ACE_FoxReactor)
public:
  // = Initialization and termination methods.
  ACE_FoxReactor (FXApp* a=0,
                 size_t size = DEFAULT_SIZE,
                 bool restart = false,
                 ACE_Sig_Handler * = 0);
  virtual ~ACE_FoxReactor (void);

  void fxapplication(FXApp* a);

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

  // = Integrate with the Fox callback function mechanism.
  long onFileEvents (FXObject*, FXSelector, void*);
  long onTimerEvents (FXObject*, FXSelector, void*);


protected:
  // = Register timers/handles with Fox.
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

  int FoxWaitForMultipleEvents (int,ACE_Select_Reactor_Handle_Set &,ACE_Time_Value *);

private:
  /// This method ensures there's an Fox timeout for the first timeout
  /// in the Reactor's Timer_Queue.
  void reset_timeout (void);

  FXApp *fxapp;

  /// Deny access since member-wise won't work...
  ACE_FoxReactor (const ACE_FoxReactor &);
  ACE_FoxReactor &operator = (const ACE_FoxReactor &);
};

#include /**/ "ace/post.h"
#endif /* ACE_FOXREACTOR_H */

