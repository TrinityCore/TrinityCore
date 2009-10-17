// -*- C++ -*-
//=============================================================================
/**
 *  @file    Connector.h
 *
 *  $Id: Connector.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Douglas C. Schmidt <schmidt@cs.wustl.edu>
 */
//=============================================================================
#ifndef ACE_CONNECTOR_H
#define ACE_CONNECTOR_H
#include /**/ "ace/pre.h"
#include "ace/Service_Object.h"
#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */
#include "ace/Strategies_T.h"
#include "ace/Synch_Options.h"
#include "ace/Unbounded_Set.h"
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
/**
 * @class ACE_Connector_Base
 *
 * @brief This base interface allows ACE_NonBlocking_Connect_Handler
 * to only care about the SVC_HANDLER template parameter of the
 * ACE_Connector.  Otherwise, ACE_NonBlocking_Connect_Handler would
 * have to be configured with all the template parameters that
 * ACE_Connector is configured with.
 */
template <class SVC_HANDLER>
class ACE_Connector_Base
{
public:
  virtual ~ACE_Connector_Base (void) {}
  /// Initialize the Svc_Handler.
  virtual void initialize_svc_handler (ACE_HANDLE handle,
                                       SVC_HANDLER *svc_handler) = 0;
  /// Return the handle set representing the non-blocking connects in
  /// progress.
  virtual ACE_Unbounded_Set<ACE_HANDLE> &non_blocking_handles (void) = 0;
};
/**
 * @class ACE_NonBlocking_Connect_Handler
 *
 * @brief Performs non-blocking connects on behalf of the Connector.
 */
template <class SVC_HANDLER>
class ACE_NonBlocking_Connect_Handler : public ACE_Event_Handler
{
public:
  /// Constructor.
  ACE_NonBlocking_Connect_Handler (ACE_Connector_Base<SVC_HANDLER> &connector,
                                   SVC_HANDLER *,
                                   long timer_id);
  /// Close up and return underlying SVC_HANDLER through @c sh.
  /**
   * If the return value is true the close was performed succesfully,
   * implying that this object was removed from the reactor and thereby
   * (by means of reference counting decremented to 0) deleted.
   * If the return value is false, the close was not successful.
   * The @c sh does not have any connection to the return
   * value. The argument will return a valid svc_handler object if a
   * valid one exists within the object. Returning a valid svc_handler
   * pointer also invalidates the svc_handler contained in this
   * object.
   */
  bool close (SVC_HANDLER *&sh);
  /// Get SVC_HANDLER.
  SVC_HANDLER *svc_handler (void);
  /// Get handle.
  ACE_HANDLE handle (void);
  /// Set handle.
  void handle (ACE_HANDLE);
  /// Get timer id.
  long timer_id (void);
  /// Set timer id.
  void timer_id (long timer_id);
  /// Called by ACE_Reactor when asynchronous connections fail.
  virtual int handle_input (ACE_HANDLE);
  /// Called by ACE_Reactor when asynchronous connections succeed.
  virtual int handle_output (ACE_HANDLE);
  /// Called by ACE_Reactor when asynchronous connections suceeds (on
  /// some platforms only).
  virtual int handle_exception (ACE_HANDLE fd);
  /// This method is called if a connection times out before
  /// completing.
  virtual int handle_timeout (const ACE_Time_Value &tv, const void *arg);
  /// Should Reactor resume us if we have been suspended before the upcall?
  virtual int resume_handler (void);
  /// Dump the state of an object.
  void dump (void) const;
  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;
private:
  /// Connector base.
  ACE_Connector_Base<SVC_HANDLER> &connector_;
  /// Associated SVC_HANDLER.
  SVC_HANDLER *svc_handler_;
  /// Associated timer id.
  long timer_id_;
};
/**
 * @class ACE_Connector
 *
 * @brief Generic factory for actively connecting clients and creating
 * service handlers (SVC_HANDLERs).
 *
 * Implements the strategy for actively establishing connections with
 * clients.  An ACE_Connector is parameterized by concrete types that
 * conform to the interfaces of PEER_CONNECTOR and SVC_HANDLER.  The
 * PEER_CONNECTOR is instantiated with a transport mechanism that
 * actively establishes connections.  The SVC_HANDLER is instantiated
 * with a concrete type that performs the application-specific
 * service.  Both blocking and non-blocking connects are supported.
 * Further, non-blocking connects support timeouts.
 */
template <class SVC_HANDLER, ACE_PEER_CONNECTOR_1>
class ACE_Connector : public ACE_Connector_Base<SVC_HANDLER>, public ACE_Service_Object
{
public:
  // Useful STL-style traits.
  typedef typename SVC_HANDLER::addr_type        addr_type;
  typedef ACE_PEER_CONNECTOR                     connector_type;
  typedef SVC_HANDLER                            handler_type;
  typedef typename SVC_HANDLER::stream_type      stream_type;
  typedef typename ACE_PEER_CONNECTOR::PEER_ADDR peer_addr_type;
  typedef ACE_PEER_CONNECTOR_ADDR                ACE_PEER_ADDR_TYPEDEF;
  /**
   * Initialize a connector.  @a flags indicates how SVC_HANDLER's
   * should be initialized prior to being activated.  Right now, the
   * only flag that is processed is ACE_NONBLOCK, which enabled
   * non-blocking I/O on the SVC_HANDLER when it is opened.
   */
  ACE_Connector (ACE_Reactor *r = ACE_Reactor::instance (),
                 int flags = 0);
  /**
   * Initialize a connector.  @a flags indicates how SVC_HANDLER's
   * should be initialized prior to being activated.  Right now, the
   * only flag that is processed is ACE_NONBLOCK, which enabled
   * non-blocking I/O on the SVC_HANDLER when it is opened.
   */
  virtual int open (ACE_Reactor *r = ACE_Reactor::instance (),
                    int flags = 0);
  /// Shutdown a connector and release resources.
  virtual ~ACE_Connector (void);
  // = Connection establishment methods.
  /**
   * Initiate connection of @a svc_handler to peer at @a remote_addr
   * using @a synch_options.  If the caller wants to designate the
   * selected @a local_addr they can (and can also insist that the
   * @a local_addr be reused by passing a value @a reuse_addr ==
   * 1). @a flags and @a perms can be used to pass any flags that are
   * needed to perform specific operations such as opening a file
   * within connect with certain permissions.  If the connection fails
   * the <close> hook on the <svc_handler> will be called
   * automatically to prevent resource leaks.
   */
  virtual int connect (SVC_HANDLER *&svc_handler,
                       const ACE_PEER_CONNECTOR_ADDR &remote_addr,
                       const ACE_Synch_Options &synch_options = ACE_Synch_Options::defaults,
                       const ACE_PEER_CONNECTOR_ADDR &local_addr
                       = (peer_addr_type &) ACE_PEER_CONNECTOR_ADDR_ANY,
                       int reuse_addr = 0,
                       int flags = O_RDWR,
                       int perms = 0);
  /**
   * This is a variation on the previous <connect> method.  On cached
   * connectors the @a svc_handler_hint variable can be used as a hint
   * for future lookups.  Since this variable is modified in the
   * context of the internal cache its use is thread-safe.  But the
   * actual svc_handler for the current connection is returned in the
   * second parameter @a svc_handler.  If the connection fails the
   * <close> hook on the <svc_handler> will be called automatically to
   * prevent resource leaks.
   */
  virtual int connect (SVC_HANDLER *&svc_handler_hint,
                       SVC_HANDLER *&svc_handler,
                       const ACE_PEER_CONNECTOR_ADDR &remote_addr,
                       const ACE_Synch_Options &synch_options = ACE_Synch_Options::defaults,
                       const ACE_PEER_CONNECTOR_ADDR &local_addr
                       = (peer_addr_type &) ACE_PEER_CONNECTOR_ADDR_ANY,
                       int reuse_addr = 0,
                       int flags = O_RDWR,
                       int perms = 0);
  /**
   * Initiate connection of @a n @a svc_handlers to peers at
   * @a remote_addrs using @a synch_options.  Returns -1 if failure
   * occurs and 0 otherwise.  If @a failed_svc_handlers is non-NULL, a
   * 1 is placed in the corresponding index of @a failed_svc_handlers
   * for each <svc_handlers[i]> that failed to connect, else a 0 is
   * placed in that index.
   */
  virtual int connect_n (size_t n,
                         SVC_HANDLER *svc_handlers[],
                         ACE_PEER_CONNECTOR_ADDR remote_addrs[],
                         ACE_TCHAR *failed_svc_handlers = 0,
                         const ACE_Synch_Options &synch_options =
                         ACE_Synch_Options::defaults);
  /**
   * Cancel the @a svc_handler that was started asynchronously. Note that
   * this is the only case when the Connector does not actively close
   * the @a svc_handler. It is left up to the caller of <cancel> to
   * decide the fate of the @a svc_handler.
   */
  virtual int cancel (SVC_HANDLER *svc_handler);
  /// Close down the Connector.  All pending non-blocking connects are
  /// canceled and the corresponding svc_handler is closed.
  virtual int close (void);
  /// Return the underlying PEER_CONNECTOR object.
  virtual ACE_PEER_CONNECTOR &connector (void) const;
  /// Initialize Svc_Handler.
  virtual void initialize_svc_handler (ACE_HANDLE handle,
                                       SVC_HANDLER *svc_handler);
  /// Set Reactor.
  virtual void reactor (ACE_Reactor *reactor);
  /// Get Reactor.
  virtual ACE_Reactor *reactor (void) const;
  /// Dump the state of an object.
  void dump (void) const;
  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;
protected:
  // = Helpful typedefs.
  typedef ACE_NonBlocking_Connect_Handler<SVC_HANDLER> NBCH;
  // = The following two methods define the Connector's strategies for
  // creating, connecting, and activating SVC_HANDLER's, respectively.
  /**
   * Bridge method for creating a SVC_HANDLER.  The default is to
   * create a new SVC_HANDLER only if @a sh == 0, else @a sh is
   * unchanged.  However, subclasses can override this policy to
   * perform SVC_HANDLER creation in any way that they like (such as
   * creating subclass instances of SVC_HANDLER, using a singleton,
   * dynamically linking the handler, etc.).  Returns -1 if failure,
   * else 0.
   */
  virtual int make_svc_handler (SVC_HANDLER *&sh);
  /**
   * Bridge method for connecting the @a svc_handler to the
   * @a remote_addr.  The default behavior delegates to the
   * <PEER_CONNECTOR::connect>.
   */
  virtual int connect_svc_handler (SVC_HANDLER *&svc_handler,
                                   const ACE_PEER_CONNECTOR_ADDR &remote_addr,
                                   ACE_Time_Value *timeout,
                                   const ACE_PEER_CONNECTOR_ADDR &local_addr,
                                   int reuse_addr,
                                   int flags,
                                   int perms);
  virtual int connect_svc_handler (SVC_HANDLER *&svc_handler,
                                   SVC_HANDLER *&sh_copy,
                                   const ACE_PEER_CONNECTOR_ADDR &remote_addr,
                                   ACE_Time_Value *timeout,
                                   const ACE_PEER_CONNECTOR_ADDR &local_addr,
                                   int reuse_addr,
                                   int flags,
                                   int perms);
  /**
   * Bridge method for activating a @a svc_handler with the appropriate
   * concurrency strategy.  The default behavior of this method is to
   * activate the SVC_HANDLER by calling its <open> method (which
   * allows the SVC_HANDLER to define its own concurrency strategy).
   * However, subclasses can override this strategy to do more
   * sophisticated concurrency activations (such as creating the
   * SVC_HANDLER as an "active object" via multi-threading or
   * multi-processing).
   */
  virtual int activate_svc_handler (SVC_HANDLER *svc_handler);
  /// Creates and registers ACE_NonBlocking_Connect_Handler.
  int nonblocking_connect (SVC_HANDLER *,
                           const ACE_Synch_Options &);
  /// Implementation of the connect methods.
  virtual int connect_i (SVC_HANDLER *&svc_handler,
                         SVC_HANDLER **sh_copy,
                         const ACE_PEER_CONNECTOR_ADDR &remote_addr,
                         const ACE_Synch_Options &synch_options,
                         const ACE_PEER_CONNECTOR_ADDR &local_addr,
                         int reuse_addr,
                         int flags,
                         int perms);
  /// Return the handle set representing the non-blocking connects in
  /// progress.
  ACE_Unbounded_Set<ACE_HANDLE> &non_blocking_handles (void);
  // = Dynamic linking hooks.
  /// Default version does no work and returns -1.  Must be overloaded
  /// by application developer to do anything meaningful.
  virtual int init (int argc, ACE_TCHAR *argv[]);
  /// Calls handle_close() to shutdown the Connector gracefully.
  virtual int fini (void);
  /// Default version returns address info in @a buf.
  virtual int info (ACE_TCHAR **strp, size_t length) const;
  // = Service management hooks.
  /// Default version does no work and returns -1.  Must be overloaded
  /// by application developer to do anything meaningful.
  virtual int suspend (void);
  /// Default version does no work and returns -1.  Must be overloaded
  /// by application developer to do anything meaningful.
  virtual int resume (void);
private:
  /// This is the peer connector factory.
  ACE_PEER_CONNECTOR connector_;
  /**
   * Flags that indicate how SVC_HANDLER's should be initialized
   * prior to being activated.  Right now, the only flag that is
   * processed is ACE_NONBLOCK, which enabled non-blocking I/O on
   * the SVC_HANDLER when it is opened.
   */
  int flags_;
  /// Pointer to the Reactor.
  ACE_Reactor *reactor_;
  /// Handle set representing the non-blocking connects in progress.
  ACE_Unbounded_Set<ACE_HANDLE> non_blocking_handles_;
};
/**
 * @class ACE_Strategy_Connector
 *
 * @brief Abstract factory for creating a service handler
 * (SVC_HANDLER), connecting the SVC_HANDLER, and activating the
 * SVC_HANDLER.
 *
 * Implements a flexible and extensible set of strategies for
 * actively establishing connections with clients.  There are
 * three main strategies: (1) creating a SVC_HANDLER, (2)
 * actively initiating a new connection from the client,
 * and (3) activating the SVC_HANDLER with a
 * particular concurrency mechanism after the connection is established.
 */
template <class SVC_HANDLER, ACE_PEER_CONNECTOR_1>
class ACE_Strategy_Connector
  : public ACE_Connector <SVC_HANDLER, ACE_PEER_CONNECTOR_2>
{
public:
  // Useful STL-style traits.
  typedef ACE_Creation_Strategy<SVC_HANDLER>
  creation_strategy_type;
  typedef ACE_Connect_Strategy<SVC_HANDLER, ACE_PEER_CONNECTOR_2>
  connect_strategy_type;
  typedef ACE_Concurrency_Strategy<SVC_HANDLER>
  concurrency_strategy_type;
  typedef ACE_Connector <SVC_HANDLER, ACE_PEER_CONNECTOR_2>
  base_type;
  // = Define some useful (old style) traits.
  typedef ACE_Creation_Strategy<SVC_HANDLER>
  CREATION_STRATEGY;
  typedef ACE_Connect_Strategy<SVC_HANDLER, ACE_PEER_CONNECTOR_2>
  CONNECT_STRATEGY;
  typedef ACE_Concurrency_Strategy<SVC_HANDLER>
  CONCURRENCY_STRATEGY;
  typedef ACE_Connector <SVC_HANDLER, ACE_PEER_CONNECTOR_2>
  SUPER;
  /**
   * Initialize a connector.  @a flags indicates how <SVC_HANDLER>'s
   * should be initialized prior to being activated.  Right now, the
   * only flag that is processed is ACE_NONBLOCK, which enabled
   * non-blocking I/O on the SVC_HANDLER when it is opened.
   */
  ACE_Strategy_Connector (ACE_Reactor *r = ACE_Reactor::instance (),
                          ACE_Creation_Strategy<SVC_HANDLER> * = 0,
                          ACE_Connect_Strategy<SVC_HANDLER, ACE_PEER_CONNECTOR_2> * = 0,
                          ACE_Concurrency_Strategy<SVC_HANDLER> * = 0,
                          int flags = 0);
  /**
   * Initialize a connector.  @a flags indicates how SVC_HANDLER's
   * should be initialized prior to being activated.  Right now, the
   * only flag that is processed is ACE_NONBLOCK, which enabled
   * non-blocking I/O on the SVC_HANDLER when it is opened.
   * Default strategies would be created and used.
   */
  virtual int open (ACE_Reactor *r,
                    int flags);
  /**
   * Initialize a connector.  @a flags indicates how SVC_HANDLER's
   * should be initialized prior to being activated.  Right now, the
   * only flag that is processed is ACE_NONBLOCK, which enabled
   * non-blocking I/O on the SVC_HANDLER when it is opened.
   */
  virtual int open (ACE_Reactor *r = ACE_Reactor::instance (),
                    ACE_Creation_Strategy<SVC_HANDLER> * = 0,
                    ACE_Connect_Strategy<SVC_HANDLER, ACE_PEER_CONNECTOR_2> * = 0,
                    ACE_Concurrency_Strategy<SVC_HANDLER> * = 0,
                    int flags = 0);
  /// Shutdown a connector and release resources.
  virtual ~ACE_Strategy_Connector (void);
  /// Close down the Connector
  virtual int close (void);
  // = Strategies accessors
  virtual ACE_Creation_Strategy<SVC_HANDLER> *creation_strategy (void) const;
  virtual ACE_Connect_Strategy<SVC_HANDLER, ACE_PEER_CONNECTOR_2> *connect_strategy (void) const;
  virtual ACE_Concurrency_Strategy<SVC_HANDLER> *concurrency_strategy (void) const;
protected:
  // = The following three methods define the <Connector>'s strategies
  // for creating, connecting, and activating SVC_HANDLER's,
  // respectively.
  /**
   * Bridge method for creating a SVC_HANDLER.  The strategy for
   * creating a SVC_HANDLER are configured into the Connector via
   * it's <creation_strategy_>.  The default is to create a new
   * SVC_HANDLER only if @a sh == 0, else @a sh is unchanged.
   * However, subclasses can override this policy to perform
   * SVC_HANDLER creation in any way that they like (such as
   * creating subclass instances of SVC_HANDLER, using a singleton,
   * dynamically linking the handler, etc.).  Returns -1 if failure,
   * else 0.
   */
  virtual int make_svc_handler (SVC_HANDLER *&sh);
  /**
   * Bridge method for connecting the new connection into the
   * SVC_HANDLER.  The default behavior delegates to the
   * <PEER_CONNECTOR::connect> in the <Connect_Strategy>.
   */
  virtual int connect_svc_handler (SVC_HANDLER *&sh,
                                   const ACE_PEER_CONNECTOR_ADDR &remote_addr,
                                   ACE_Time_Value *timeout,
                                   const ACE_PEER_CONNECTOR_ADDR &local_addr,
                                   int reuse_addr,
                                   int flags,
                                   int perms);
  /**
   * Bridge method for connecting the new connection into the
   * SVC_HANDLER.  The default behavior delegates to the
   * <PEER_CONNECTOR::connect> in the <Connect_Strategy>.
   * @a sh_copy is used to obtain a copy of the @a sh pointer, but that
   * can be kept in the stack; the motivation is a bit too long to
   * include here, but basically we want to modify @a sh safely, using
   * the internal locks in the Connect_Strategy, while saving a TSS
   * copy in @a sh_copy, usually located in the stack.
   */
  virtual int connect_svc_handler (SVC_HANDLER *&sh,
                                   SVC_HANDLER *&sh_copy,
                                   const ACE_PEER_CONNECTOR_ADDR &remote_addr,
                                   ACE_Time_Value *timeout,
                                   const ACE_PEER_CONNECTOR_ADDR &local_addr,
                                   int reuse_addr,
                                   int flags,
                                   int perms);
  /**
   * Bridge method for activating a SVC_HANDLER with the appropriate
   * concurrency strategy.  The default behavior of this method is to
   * activate the SVC_HANDLER by calling its <open> method (which
   * allows the SVC_HANDLER to define its own concurrency strategy).
   * However, subclasses can override this strategy to do more
   * sophisticated concurrency activations (such as creating the
   * SVC_HANDLER as an "active object" via multi-threading or
   * multi-processing).
   */
  virtual int activate_svc_handler (SVC_HANDLER *svc_handler);
  // = Strategy objects.
  /// Creation strategy for an Connector.
  CREATION_STRATEGY *creation_strategy_;
  /// true if Connector created the creation strategy and thus should
  /// delete it, else false.
  bool delete_creation_strategy_;
  /// Connect strategy for a Connector.
  CONNECT_STRATEGY *connect_strategy_;
  /// true if Connector created the connect strategy and thus should
  /// delete it, else false.
  bool delete_connect_strategy_;
  /// Concurrency strategy for an <Connector>.
  CONCURRENCY_STRATEGY *concurrency_strategy_;
  /// true if Connector created the concurrency strategy and thus should
  /// delete it, else false.
  bool delete_concurrency_strategy_;
};
ACE_END_VERSIONED_NAMESPACE_DECL
#if defined (ACE_TEMPLATES_REQUIRE_SOURCE)
#include "ace/Connector.cpp"
#endif /* ACE_TEMPLATES_REQUIRE_SOURCE */
#if defined (ACE_TEMPLATES_REQUIRE_PRAGMA)
#pragma implementation ("Connector.cpp")
#endif /* ACE_TEMPLATES_REQUIRE_PRAGMA */
#include /**/ "ace/post.h"
#endif /* ACE_CONNECTOR_H */

