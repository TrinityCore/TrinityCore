/* -*- C++ -*- */

//=============================================================================
/**
 *  @file    Event_Handler_T.h
 *
 *  $Id: Event_Handler_T.h 83891 2008-11-28 11:01:50Z johnnyw $
 *
 *  @author Douglas C. Schmidt <schmidt@cs.wustl.edu>
 */
//=============================================================================

#ifndef ACE_EVENT_HANDLER_T_H
#define ACE_EVENT_HANDLER_T_H
#include /**/ "ace/pre.h"

#include "ace/Event_Handler.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if defined (ACE_HAS_TEMPLATE_TYPEDEFS)

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class ACE_Event_Handler_T
 *
 * @brief Enable a class that doesn't inherit from the
 * ACE_Event_Handler to be incorporated into the ACE_Reactor
 * framework.  Thanks to Greg Lavender (g.lavender@isode.com)
 * for sharing this idea.
 *
 * It is sometimes the case that an application has a hierarchy
 * of operation dispatcher classes that have their own
 * inheritance hierarchy but also would like to integrate with
 * the ACE_Reactor.  Rather than adopt a "mixin" approach, it is
 * often cleaner to define a template as a subclass of
 * ACE_Event_Handler and parameterize it with an operation
 * dispatcher type.
 * When constructing an instantiation of the ACE_Event_Handler_T
 * object, a set of pointers to member functions must be
 * provided so that when one of the handle_* methods is called
 * by the ACE_Reactor, the appropriate method is called on the
 * underlying operations object.  This is done since in some
 * cases it is useful to map any event that happens to the same
 * method on an object.
 * The ACE_Event_Handler_T template is instantiated by an
 * operations object and registered with the ACE_Reactor, and it
 * then calls the appropriate op_handler.  So, it's basically
 * just another level of indirection in event dispatching. The
 * coupling betweent the ultimate handler of the event and the
 * ACE_Event_Handler class is relaxed a bit by have this
 * intermediate <op_handler_> object of type <T> around. The
 * client object can then dynamically change the bindings for
 * the various handlers so that during the life of one of the
 * operation objects, it can change how it wants events to be
 * handled. It just instantiates a new instance of the template
 * with different bindings and reregisters this new object with
 * the ACE_Reactor.
 */
template <class T>
class ACE_Event_Handler_T : public ACE_Event_Handler
{
public:
  // = Typedefs to simplify pointer-to-member-function registration.

  // Get/set the underlying handle.
  typedef ACE_HANDLE (T::*GET_HANDLE) (void) const;
  typedef void (T::*SET_HANDLE) (ACE_HANDLE);

  /// Handle I/O events.
  typedef int (T::*IO_HANDLER) (ACE_HANDLE);

  /// Handle timeout events.
  typedef int (T::*TO_HANDLER) (const ACE_Time_Value &, const void *);

  /// Handle close events.
  typedef int (T::*CL_HANDLER) (ACE_HANDLE, ACE_Reactor_Mask);

  /// = Initialization and termination methods.
  typedef int (T::*SIG_HANDLER) (int, siginfo_t*, ucontext_t*);

  /// Initialize the op_handler.
  ACE_Event_Handler_T (T *op_handler,
                       int delete_handler,
                       GET_HANDLE get_handle = 0,
                       IO_HANDLER input = 0,
                       CL_HANDLER close = 0,
                       SIG_HANDLER sig = 0,
                       TO_HANDLER timeout = 0,
                       IO_HANDLER output = 0,
                       SET_HANDLE set_handle = 0,
                       IO_HANDLER except = 0);

  /// Close down and delete the <op_handler>
  ~ACE_Event_Handler_T (void);

  // = Override all the ACE_Event_Handler methods.

  // These methods all delegate down to the <T> operations handler.
  virtual ACE_HANDLE get_handle (void) const;
  virtual void set_handle (ACE_HANDLE);
  virtual int handle_input (ACE_HANDLE fd = ACE_INVALID_HANDLE);
  virtual int handle_output (ACE_HANDLE fd = ACE_INVALID_HANDLE);
  virtual int handle_exception (ACE_HANDLE fd = ACE_INVALID_HANDLE);
  virtual int handle_timeout (const ACE_Time_Value &tv, const void *arg = 0);
  virtual int handle_close (ACE_HANDLE fd, ACE_Reactor_Mask close_mask);
  virtual int handle_signal (int signum, siginfo_t * = 0, ucontext_t * = 0);

  // = Get/set the operations handler.
  T *op_handler (void);
  void op_handler (T *);

  // = Get/set the target pointer-to-method used for dispatching.

  GET_HANDLE handle_get (void);
  void handle_get (GET_HANDLE);

  SET_HANDLE handle_set (void);
  void handle_set (SET_HANDLE);

  IO_HANDLER input_handler (void);
  void input_handler (IO_HANDLER);

  IO_HANDLER output_handler (void);
  void output_handler (IO_HANDLER);

  IO_HANDLER except_handler (void);
  void except_handler (IO_HANDLER);

  TO_HANDLER to_handler (void);
  void to_handler (TO_HANDLER);

  CL_HANDLER cl_handler (void);
  void cl_handler (CL_HANDLER);

  SIG_HANDLER sig_handler (void);
  void sig_handler (SIG_HANDLER);

  /// Dump the state of an object.
  void dump (void) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

protected:
  /// Pointer to the object that handles all the delegated operations.
  T *op_handler_;

  // = Handle input, output, and exception events.
  IO_HANDLER input_handler_;
  IO_HANDLER output_handler_;
  IO_HANDLER except_handler_;

  /// Handle timeout events.
  TO_HANDLER to_handler_;

  /// Handle close events.
  CL_HANDLER cl_handler_;

  /// Handle signal events.
  SIG_HANDLER sig_handler_;

  /// Keeps track of whether we need to delete the handler in the
  /// destructor.
  int delete_handler_;

  // = Get/set underlying handle.
  SET_HANDLE set_handle_;
  GET_HANDLE get_handle_;
};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ace/Event_Handler_T.inl"
#endif /* __ACE_INLINE__ */

#if defined (ACE_TEMPLATES_REQUIRE_SOURCE)
#include "ace/Event_Handler_T.cpp"
#endif /* ACE_TEMPLATES_REQUIRE_SOURCE */

#if defined (ACE_TEMPLATES_REQUIRE_PRAGMA)
#pragma implementation ("Event_Handler_T.cpp")
#endif /* ACE_TEMPLATES_REQUIRE_PRAGMA */

#endif /* ACE_HAS_TEMPLATE_TYPEDEFS */
#include /**/ "ace/post.h"
#endif /* ACE_EVENT_HANDLER_H */
