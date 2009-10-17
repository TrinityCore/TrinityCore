// -*- C++ -*-

//=============================================================================
/**
 *  @file    Acceptor.h
 *
 *  $Id: Acceptor.h 81460 2008-04-28 11:34:23Z elliott_c $
 *
 *  @author Douglas C. Schmidt <schmidt@cs.wustl.edu>
 */
//=============================================================================

#ifndef ACE_ACCEPTOR_H
#define ACE_ACCEPTOR_H

#include /**/ "ace/pre.h"

#include "ace/Service_Object.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/Strategies_T.h"
#include "ace/Synch_Options.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class ACE_Acceptor
 *
 * @brief Abstract factory for creating a service handler
 * (SVC_HANDLER), accepting into the SVC_HANDLER, and
 * activating the SVC_HANDLER.
 *
 * Implements the basic strategy for passively establishing
 * connections with clients.  An ACE_Acceptor is parameterized
 * by concrete types that conform to the interfaces of
 * PEER_ACCEPTOR and SVC_HANDLER.  The PEER_ACCEPTOR is
 * instantiated with a transport mechanism that passively
 * establishes connections.  The SVC_HANDLER is instantiated
 * with a concrete type that performs the application-specific
 * service.  An ACE_Acceptor inherits from ACE_Service_Object,
 * which in turn inherits from ACE_Event_Handler.  This enables
 * the ACE_Reactor to dispatch the ACE_Acceptor's handle_input
 * method when connection events occur.  The handle_input method
 * performs the ACE_Acceptor's default creation, connection
 * establishment, and service activation strategies.  These
 * strategies can be overridden by subclasses individually or as
 * a group.
 */
template <class SVC_HANDLER, ACE_PEER_ACCEPTOR_1>
class ACE_Acceptor : public ACE_Service_Object
{
public:

  // Useful STL-style traits.
  typedef ACE_PEER_ACCEPTOR_ADDR            addr_type;
  typedef ACE_PEER_ACCEPTOR                 acceptor_type;
  typedef SVC_HANDLER                       handler_type;
  typedef typename SVC_HANDLER::stream_type stream_type;

  /// "Do-nothing" constructor.
  ACE_Acceptor (ACE_Reactor * = 0,
                int use_select = 1);

  /**
   * Open the contained @c PEER_ACCEPTOR object to begin listening, and
   * register with the specified reactor for accept events.  An
   * acceptor can only listen to one port at a time, so make sure to
   * @c close() the acceptor before calling @c open() again.
   *
   * The @c PEER_ACCEPTOR handle is put into non-blocking mode as a
   * safeguard against the race condition that can otherwise occur
   * between the time when the passive-mode socket handle is "ready"
   * and when the actual @c accept() call is made.  During this
   * interval, the client can shutdown the connection, in which case,
   * the @c accept() call can hang.
   *
   * @param local_addr The address to listen at.
   * @param reactor    Pointer to the ACE_Reactor instance to register
   *                   this object with. The default is the singleton.
   * @param flags      Flags to control what mode an accepted socket
   *                   will be put into after it is accepted. The only
   *                   legal value for this argument is @c ACE_NONBLOCK,
   *                   which enables non-blocking mode on the accepted
   *                   peer stream object in @c SVC_HANDLER.  The default
   *                   is 0.
   * @param use_select Affects behavior when called back by the reactor
   *                   when a connection can be accepted.  If non-zero,
   *                   this object will accept all pending connections,
   *                   intead of just the one that triggered the reactor
   *                   callback.  Uses ACE_OS::select() internally to
   *                   detect any remaining acceptable connections.
   *                   The default is 1.
   * @param reuse_addr Passed to the @c PEER_ACCEPTOR::open() method with
   *                   @p local_addr.  Generally used to request that the
   *                   OS allow reuse of the listen port.  The default is 1.
   */
  ACE_Acceptor (const ACE_PEER_ACCEPTOR_ADDR &local_addr,
                ACE_Reactor *reactor = ACE_Reactor::instance (),
                int flags = 0,
                int use_select = 1,
                int reuse_addr = 1);

  /**
   * Open the contained @c PEER_ACCEPTOR object to begin listening, and
   * register with the specified reactor for accept events.  An
   * acceptor can only listen to one port at a time, so make sure to
   * @c close() the acceptor before calling @c open() again.
   *
   * The @c PEER_ACCEPTOR handle is put into non-blocking mode as a
   * safeguard against the race condition that can otherwise occur
   * between the time when the passive-mode socket handle is "ready"
   * and when the actual @c accept() call is made.  During this
   * interval, the client can shutdown the connection, in which case,
   * the @c accept() call can hang.
   *
   * @param local_addr The address to listen at.
   * @param reactor    Pointer to the ACE_Reactor instance to register
   *                   this object with. The default is the singleton.
   * @param flags      Flags to control what mode an accepted socket
   *                   will be put into after it is accepted. The only
   *                   legal value for this argument is @c ACE_NONBLOCK,
   *                   which enables non-blocking mode on the accepted
   *                   peer stream object in @c SVC_HANDLER.  The default
   *                   is 0.
   * @param use_select Affects behavior when called back by the reactor
   *                   when a connection can be accepted.  If non-zero,
   *                   this object will accept all pending connections,
   *                   intead of just the one that triggered the reactor
   *                   callback.  Uses ACE_OS::select() internally to
   *                   detect any remaining acceptable connections.
   *                   The default is 1.
   * @param reuse_addr Passed to the @c PEER_ACCEPTOR::open() method with
   *                   @p local_addr.  Generally used to request that the
   *                   OS allow reuse of the listen port.  The default is 1.
   *
   * @retval 0  Success
   * @retval -1 Failure, @c errno contains an error code.
   */
  virtual int open (const ACE_PEER_ACCEPTOR_ADDR &local_addr,
                    ACE_Reactor *reactor = ACE_Reactor::instance (),
                    int flags = 0,
                    int use_select = 1,
                    int reuse_addr = 1);

  /// Close down the Acceptor's resources.
  virtual ~ACE_Acceptor (void);

  /// Return the underlying PEER_ACCEPTOR object.
  virtual operator ACE_PEER_ACCEPTOR &() const;

  /// Return the underlying PEER_ACCEPTOR object.
  virtual ACE_PEER_ACCEPTOR &acceptor (void) const;

  /// Returns the listening acceptor's {ACE_HANDLE}.
  virtual ACE_HANDLE get_handle (void) const;

  /// Close down the Acceptor
  virtual int close (void);

  /// In the event that an accept fails, this method will be called and
  /// the return value will be returned from handle_input().
  virtual int handle_accept_error (void);

  /// Dump the state of an object.
  void dump (void) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

protected:
  // = The following three methods define the Acceptor's strategies
  // for creating, accepting, and activating SVC_HANDLER's,
  // respectively.

  /**
   * Bridge method for creating a SVC_HANDLER.  The default is to
   * create a new {SVC_HANDLER} if {sh} == 0, else {sh} is unchanged.
   * However, subclasses can override this policy to perform
   * SVC_HANDLER creation in any way that they like (such as creating
   * subclass instances of SVC_HANDLER, using a singleton, dynamically
   * linking the handler, etc.).  Returns -1 on failure, else 0.
   */
  virtual int make_svc_handler (SVC_HANDLER *&sh);

  /**
   * Bridge method for accepting the new connection into the
   * <svc_handler>.  The default behavior delegates to the
   * PEER_ACCEPTOR::accept.
   */
  virtual int accept_svc_handler (SVC_HANDLER *svc_handler);

  /**
   * Bridge method for activating a {svc_handler} with the appropriate
   * concurrency strategy.  The default behavior of this method is to
   * activate the SVC_HANDLER by calling its {open} method (which
   * allows the SVC_HANDLER to define its own concurrency strategy).
   * However, subclasses can override this strategy to do more
   * sophisticated concurrency activations (such as making the
   * SVC_HANDLER as an "active object" via multi-threading or
   * multi-processing).
   */
  virtual int activate_svc_handler (SVC_HANDLER *svc_handler);

  // = Demultiplexing hooks.
  /// Perform termination activities when {this} is removed from the
  /// {reactor}.
  virtual int handle_close (ACE_HANDLE = ACE_INVALID_HANDLE,
                            ACE_Reactor_Mask = ACE_Event_Handler::ALL_EVENTS_MASK);

  /// Accepts all pending connections from clients, and creates and
  /// activates SVC_HANDLERs.
  virtual int handle_input (ACE_HANDLE);

  // = Dynamic linking hooks.
  /// Default version does no work and returns -1.  Must be overloaded
  /// by application developer to do anything meaningful.
  virtual int init (int argc, ACE_TCHAR *argv[]);

  /// Calls {handle_close}.
  virtual int fini (void);

  /// Default version returns address info in {buf}.
  virtual int info (ACE_TCHAR **buf, size_t) const;

public:
  // = Service management hooks.
  /// This method calls {Reactor::suspend}.
  virtual int suspend (void);

  /// This method calls {Reactor::resume}.
  virtual int resume (void);

protected:
  /// Concrete factory for accepting connections from clients...
  ACE_PEER_ACCEPTOR peer_acceptor_;

  /// Needed to reopen the socket if {accept} fails.
  ACE_PEER_ACCEPTOR_ADDR peer_acceptor_addr_;

  /**
   * Flags that indicate how {SVC_HANDLER}'s should be initialized
   * prior to being activated.  Right now, the only flag that is
   * processed is {ACE_NONBLOCK}, which enabled non-blocking I/O on
   * the {SVC_HANDLER} when it is opened.
   */
  int flags_;

  /// Flag that indicates whether it shall use {select} in the
  /// {accept}-loop.
  int use_select_;

  /// Needed to reopen the socket if {accept} fails.
  int reuse_addr_;
};

/**
 * @class ACE_Strategy_Acceptor
 *
 * @brief Abstract factory for creating a service handler
 * (SVC_HANDLER), accepting into the SVC_HANDLER, and activating
 * the SVC_HANDLER.
 *
 * Implements a flexible and extensible set of strategies for
 * passively establishing connections with clients.  There are
 * three main strategies: (1) creating a SVC_HANDLER, (2)
 * passively accepting a new connection from a client into the
 * SVC_HANDLER, and (3) activating the SVC_HANDLER with a
 * particular concurrency mechanism.
 */
template <class SVC_HANDLER, ACE_PEER_ACCEPTOR_1>
class ACE_Strategy_Acceptor
  : public ACE_Acceptor <SVC_HANDLER, ACE_PEER_ACCEPTOR_2>
{
public:

  // Useful STL-style traits.
  typedef ACE_Creation_Strategy<SVC_HANDLER>
          creation_strategy_type;
  typedef ACE_Accept_Strategy<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>
          accept_strategy_type;
  typedef ACE_Concurrency_Strategy<SVC_HANDLER>
          concurrency_strategy_type;
  typedef ACE_Scheduling_Strategy<SVC_HANDLER> scheduling_strategy_type;
  typedef ACE_Acceptor <SVC_HANDLER, ACE_PEER_ACCEPTOR_2>
          base_type;

  // = Define some useful (old style) traits.
  typedef ACE_Creation_Strategy<SVC_HANDLER> CREATION_STRATEGY;
  typedef ACE_Accept_Strategy<SVC_HANDLER, ACE_PEER_ACCEPTOR_2> ACCEPT_STRATEGY;
  typedef ACE_Concurrency_Strategy<SVC_HANDLER> CONCURRENCY_STRATEGY;
  typedef ACE_Scheduling_Strategy<SVC_HANDLER> SCHEDULING_STRATEGY;



  /// Default constructor.
  ACE_Strategy_Acceptor (const ACE_TCHAR service_name[] = 0,
                         const ACE_TCHAR service_description[] = 0,
                         int use_select = 1,
                         int reuse_addr = 1);

  /**
   * Initialize the appropriate strategies for creation, passive
   * connection acceptance, and concurrency, and then register {this}
   * with the Reactor and listen for connection requests at the
   * designated {local_addr}.
   */
  ACE_Strategy_Acceptor (const ACE_PEER_ACCEPTOR_ADDR &local_addr,
                         ACE_Reactor * = ACE_Reactor::instance (),
                         ACE_Creation_Strategy<SVC_HANDLER> * = 0,
                         ACE_Accept_Strategy<SVC_HANDLER, ACE_PEER_ACCEPTOR_2> * = 0,
                         ACE_Concurrency_Strategy<SVC_HANDLER> * = 0,
                         ACE_Scheduling_Strategy<SVC_HANDLER> * = 0,
                         const ACE_TCHAR service_name[] = 0,
                         const ACE_TCHAR service_description[] = 0,
                         int use_select = 1,
                         int reuse_addr = 1);

  /**
   * Open the contained @c PEER_ACCEPTOR object to begin listening, and
   * register with the specified reactor for accept events.
   *
   * The @c PEER_ACCEPTOR handle is put into non-blocking mode as a
   * safeguard against the race condition that can otherwise occur
   * between the time when the passive-mode socket handle is "ready"
   * and when the actual @c accept call is made.  During this
   * interval, the client can shutdown the connection, in which case,
   * the {accept} call can hang.
   *
   * @param local_addr   The address to listen at.
   * @param reactor      Pointer to the ACE_Reactor instance to register
   *                     this object with. The default is the singleton.
   * @param flags        Flags to control what mode an accepted socket
   *                     will be put into after it is accepted. The only
   *                     legal value for this argument is @c ACE_NONBLOCK,
   *                     which enables non-blocking mode on the accepted
   *                     peer stream object in @c SVC_HANDLER.  The default
   *                     is 0.
   * @param use_select   Affects behavior when called back by the reactor
   *                     when a connection can be accepted.  If non-zero,
   *                     this object will accept all pending connections,
   *                     intead of just the one that triggered the reactor
   *                     callback.  Uses ACE_OS::select() internally to
   *                     detect any remaining acceptable connections.
   *                     The default is 1.
   * @param reuse_addr   Passed to the @c PEER_ACCEPTOR::open() method with
   *                     @p local_addr.  Generally used to request that the
   *                     OS allow reuse of the listen port.  The default is 1.
   *
   * @retval 0  Success
   * @retval -1 Failure, @c errno contains an error code.
   */
  virtual int open (const ACE_PEER_ACCEPTOR_ADDR &local_addr,
                    ACE_Reactor *reactor,
                    int flags = 0,
                    int use_select = 1,
                    int reuse_addr = 1);

  /**
   * Initialize the appropriate strategies for creation, passive
   * connection acceptance, and concurrency, and then register {this}
   * with the Reactor and listen for connection requests at the
   * designated {local_addr}.
   */
  virtual int open (const ACE_PEER_ACCEPTOR_ADDR &,
                    ACE_Reactor * = ACE_Reactor::instance (),
                    ACE_Creation_Strategy<SVC_HANDLER> * = 0,
                    ACE_Accept_Strategy<SVC_HANDLER, ACE_PEER_ACCEPTOR_2> * =0,
                    ACE_Concurrency_Strategy<SVC_HANDLER> * = 0,
                    ACE_Scheduling_Strategy<SVC_HANDLER> * = 0,
                    const ACE_TCHAR *service_name = 0,
                    const ACE_TCHAR *service_description = 0,
                    int use_select = 1,
                    int reuse_addr = 1);

  /// Close down the Strategy_Acceptor's resources.
  virtual ~ACE_Strategy_Acceptor (void);

  /// Return the underlying PEER_ACCEPTOR object.
  virtual operator ACE_PEER_ACCEPTOR &() const;

  /// Return the underlying PEER_ACCEPTOR object.
  virtual ACE_PEER_ACCEPTOR &acceptor (void) const;

  /// Returns the listening acceptor's {ACE_HANDLE}.
  virtual ACE_HANDLE get_handle (void) const;

  /// Dump the state of an object.
  void dump (void) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

  // = Service management hooks.

  /// This method delegates to the {Scheduling_Strategy}'s {suspend}
  /// method.
  virtual int suspend (void);

  /// This method delegates to the {Scheduling_Strategy}'s {resume}
  /// method.
  virtual int resume (void);

protected:

  /// Calls {handle_close} when dynamically unlinked.
  virtual int fini (void);

  /// Default version returns address info in {buf}.
  virtual int info (ACE_TCHAR **buf, size_t) const;

  // = The following three methods define the {Acceptor}'s strategies
  // for creating, accepting, and activating {SVC_HANDLER}'s,
  // respectively.

  /**
   * Bridge method for creating a {SVC_HANDLER}.  The strategy for
   * creating a {SVC_HANDLER} are configured into the Acceptor via
   * it's {creation_strategy_}.  The default is to create a new
   * {SVC_HANDLER} if {sh} == 0, else {sh} is unchanged.  However,
   * subclasses can override this policy to perform {SVC_HANDLER}
   * creation in any way that they like (such as creating subclass
   * instances of {SVC_HANDLER}, using a singleton, dynamically
   * linking the handler, etc.).  Returns -1 on failure, else 0.
   */
  virtual int make_svc_handler (SVC_HANDLER *&);

  /**
   * Bridge method for accepting the new connection into the
   * {SVC_HANDLER}.  The default behavior delegates to the
   * {PEER_ACCEPTOR::accept} in the {Acceptor_Strategy}.
   */
  virtual int accept_svc_handler (SVC_HANDLER *svc_handler);

  /**
   * Bridge method for activating a {SVC_HANDLER} with the appropriate
   * concurrency strategy.  The default behavior of this method is to
   * activate the {SVC_HANDLER} by calling its {open} method (which
   * allows the {SVC_HANDLER} to define its own concurrency strategy).
   * However, subclasses can override this strategy to do more
   * sophisticated concurrency activations (such as creating the
   * {SVC_HANDLER} as an "active object" via multi-threading or
   * multi-processing).
   */
  virtual int activate_svc_handler (SVC_HANDLER *svc_handler);

  // = Demultiplexing hooks.
  /// Perform termination activities when {this} is removed from the
  /// {Reactor}.
  virtual int handle_close (ACE_HANDLE = ACE_INVALID_HANDLE,
                            ACE_Reactor_Mask = ACE_Event_Handler::ALL_EVENTS_MASK);

  /// Handle SIGINT.
  virtual int handle_signal (int signum, siginfo_t *, ucontext_t *);

  // = These data members are "logically private" but are put in the
  // protected part in case subclasses want to access them.

  // = Strategy objects.

  /// Creation strategy for an Acceptor.
  CREATION_STRATEGY *creation_strategy_;

  /// true if {Acceptor} created the creation strategy and thus should
  /// delete it, else false.
  bool delete_creation_strategy_;

  /// Accept strategy for an {Acceptor}.
  ACCEPT_STRATEGY *accept_strategy_;

  /// true if {Acceptor} created the accept strategy and thus should delete
  /// it, else false.
  bool delete_accept_strategy_;

  /// Concurrency strategy for an {Acceptor}.
  CONCURRENCY_STRATEGY *concurrency_strategy_;

  /// true if {Acceptor} created the concurrency strategy and thus should
  /// delete it, else false.
  bool delete_concurrency_strategy_;

  /// Scheduling strategy for an {Acceptor}.
  SCHEDULING_STRATEGY *scheduling_strategy_;

  /// true if {Acceptor} created the scheduling strategy and thus should
  /// delete it, else false.
  bool delete_scheduling_strategy_;

  // = Service information objects.

  /// Name of the service.
  ACE_TCHAR *service_name_;

  /// Description of the service.
  ACE_TCHAR *service_description_;

  /// Address that the {Strategy_Acceptor} uses to listen for
  /// connections.
  ACE_PEER_ACCEPTOR_ADDR service_addr_;
};

/**
 * @class ACE_Oneshot_Acceptor
 *
 * @brief Generic factory for passively connecting clients and creating
 * exactly one service handler (SVC_HANDLER).
 *
 * This class works similarly to the regular {ACE_Acceptor},
 * with the following differences:
 * 1. This class doesn't automagically register {this} with the
 * {ACE_Reactor} since it expects to have its {accept} method
 * called directly.  However, it stashes the {ACE_Reactor}
 * pointer away in case it's needed later to finish accepting
 * a connection asynchronously.
 * 2. The class doesn't need an {ACE_Creation_Strategy} (since
 * the user supplies the SVC_HANDLER) or an
 * {ACE_Accept_Strategy} (since this class only accepts one
 * connection and then removes all traces of itself from the
 * {ACE_Reactor} if it was registered for asynchronous
 * accepts).
 */
template <class SVC_HANDLER, ACE_PEER_ACCEPTOR_1>
class ACE_Oneshot_Acceptor : public ACE_Service_Object
{
public:

  // Useful STL-style traits.
  typedef ACE_PEER_ACCEPTOR_ADDR            addr_type;
  typedef ACE_PEER_ACCEPTOR                 acceptor_type;
  typedef SVC_HANDLER                       handler_type;
  typedef typename SVC_HANDLER::stream_type stream_type;

  /// Constructor.
  ACE_Oneshot_Acceptor (void);

  /**
   * Initialize the appropriate strategies for concurrency and then
   * open the {peer_acceptor} at the designated {local_addr}.  Note
   * that unlike the {ACE_Acceptor} and {ACE_Strategy_Acceptor}, this
   * method does NOT register {this} acceptor with the {reactor} at
   * this point -- it just stashes the {reactor} away in case it's
   * needed later.
   */
  ACE_Oneshot_Acceptor (const ACE_PEER_ACCEPTOR_ADDR &local_addr,
                        ACE_Reactor *reactor = ACE_Reactor::instance (),
                        ACE_Concurrency_Strategy<SVC_HANDLER> * = 0);

  /**
   * Initialize the appropriate strategies for concurrency and then
   * open the {peer_acceptor} at the designated {local_addr}.  Note
   * that unlike the {ACE_Acceptor} and {ACE_Strategy_Acceptor}, this
   * method does NOT register {this} acceptor with the {reactor} at
   * this point -- it just stashes the {reactor} away in case it's
   * needed later.
   */
  int open (const ACE_PEER_ACCEPTOR_ADDR &,
            ACE_Reactor *reactor = ACE_Reactor::instance (),
            ACE_Concurrency_Strategy<SVC_HANDLER> * = 0);

  /// Close down the {Oneshot_Acceptor}.
  virtual ~ACE_Oneshot_Acceptor (void);

  // = Explicit factory operation.
  /// Create a {SVC_HANDLER}, accept the connection into the
  /// {SVC_HANDLER}, and activate the {SVC_HANDLER}.
  virtual int accept (SVC_HANDLER * = 0,
                      ACE_PEER_ACCEPTOR_ADDR *remote_addr = 0,
                      const ACE_Synch_Options &synch_options = ACE_Synch_Options::defaults,
                      int restart = 1,
                      int reset_new_handle = 0);

  /// Cancel a oneshot acceptor that was started asynchronously.
  virtual int cancel (void);

  /// Return the underlying {PEER_ACCEPTOR} object.
  virtual operator ACE_PEER_ACCEPTOR &() const;

  /// Return the underlying {PEER_ACCEPTOR} object.
  virtual ACE_PEER_ACCEPTOR &acceptor (void) const;

  /// Close down the {Oneshot_Acceptor}.
  virtual int close (void);

  /// Dump the state of an object.
  void dump (void) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

protected:
  /**
   * Bridge method for activating a {svc_handler} with the appropriate
   * concurrency strategy.  Default behavior is to activate the
   * {SVC_HANDLER} as a "passive object."  However, subclasses can
   * override this strategy to do more sophisticated concurrency
   * activations (such as creating the {SVC_HANDLER} as an "active
   * object" via multi-threading or multi-processing).
   */
  virtual int activate_svc_handler (SVC_HANDLER *svc_handler);

  /// Factors out the code shared between the {accept} and
  /// {handle_input} methods.
  int shared_accept (SVC_HANDLER *svc_handler,
                     ACE_PEER_ACCEPTOR_ADDR *remote_addr,
                     ACE_Time_Value *timeout,
                     int restart,
                     int reset_new_handle);

  // = Demultiplexing hooks.
  /// Returns the listening acceptor's {ACE_HANDLE}.
  virtual ACE_HANDLE get_handle (void) const;

  /// Perform termination activities when {this} is removed from the
  /// {reactor}.
  virtual int handle_close (ACE_HANDLE = ACE_INVALID_HANDLE,
                            ACE_Reactor_Mask = ACE_Event_Handler::ALL_EVENTS_MASK);

  /// Accept one connection from a client and activates the
  /// SVC_HANDLER.
  virtual int handle_input (ACE_HANDLE);

  /// Called when an acceptor times out...
  virtual int handle_timeout (const ACE_Time_Value &tv,
                              const void *arg);

  // = Dynamic linking hooks.
  /// Default version does no work and returns -1.  Must be overloaded
  /// by application developer to do anything meaningful.
  virtual int init (int argc, ACE_TCHAR *argv[]);

  /// Default version does no work and returns -1.  Must be overloaded
  /// by application developer to do anything meaningful.
  virtual int fini (void);

  /// Default version returns address info in {buf}.
  virtual int info (ACE_TCHAR **, size_t) const;

  // = Service management hooks.
  /// Default version does no work and returns -1.  Must be overloaded
  /// by application developer to do anything meaningful.
  virtual int suspend (void);

  /// Default version does no work and returns -1.  Must be overloaded
  /// by application developer to do anything meaningful.
  virtual int resume (void);

private:
  /**
   * Insert ourselves into the {ACE_Reactor} so that we can continue
   * accepting this connection asynchronously.  This method should NOT
   * be called by developers directly.
   */
  int register_handler (SVC_HANDLER *svc_handler,
                        const ACE_Synch_Options &options,
                        int restart);

  /// Hold the svc_handler_ across asynchrony boundaries.
  SVC_HANDLER *svc_handler_;

  /// Hold the restart flag across asynchrony boundaries.
  int restart_;

  /// Factory that establishes connections passively.
  ACE_PEER_ACCEPTOR peer_acceptor_;

  /// Concurrency strategy for an Acceptor.
  ACE_Concurrency_Strategy<SVC_HANDLER> *concurrency_strategy_;

  /// true if Acceptor created the concurrency strategy and thus should
  /// delete it, else false.
  bool delete_concurrency_strategy_;
};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (ACE_TEMPLATES_REQUIRE_SOURCE)
#include "ace/Acceptor.cpp"
#endif /* ACE_TEMPLATES_REQUIRE_SOURCE */

#if defined (ACE_TEMPLATES_REQUIRE_PRAGMA)
#pragma implementation ("Acceptor.cpp")
#endif /* ACE_TEMPLATES_REQUIRE_PRAGMA */

#include /**/ "ace/post.h"

#endif /* ACE_ACCEPTOR_H */

