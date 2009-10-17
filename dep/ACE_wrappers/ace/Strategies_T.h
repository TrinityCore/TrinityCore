// -*- C++ -*-
//=============================================================================
/**
 *  @file   Strategies_T.h
 *
 *  $Id: Strategies_T.h 81954 2008-06-15 13:24:16Z johnnyw $
 *
 *  @author Douglas C. Schmidt <schmidt@cs.wustl.edu>
 */
//=============================================================================
#ifndef ACE_STRATEGIES_T_H
#define ACE_STRATEGIES_T_H
#include /**/ "ace/pre.h"
#include "ace/Hash_Map_Manager_T.h"
#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */
#include "ace/Reactor.h"
#include "ace/Thread_Manager.h"
#include "ace/Connection_Recycling_Strategy.h"
#include "ace/Refcountable.h"
#include "ace/Hashable.h"
#include "ace/Recyclable.h"
#include "ace/Reverse_Lock_T.h"
// Needed for broken linkers that can't grok long symbols.
#define ACE_Refcounted_Hash_Recyclable ARHR
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
class ACE_Service_Repository;
/**
 * @class ACE_Recycling_Strategy
 *
 * @brief Defines the interface (and default implementation) for
 * specifying a recycling strategy for a SVC_HANDLER.
 *
 * Acts as a consular to the Svc_Handler, preparing it for the
 * tough times ahead when the Svc_Handler will be recycled.
 */
template<class SVC_HANDLER>
class ACE_Recycling_Strategy
{
public:
  // Useful STL-style traits.
  typedef typename SVC_HANDLER::addr_type    addr_type;
  typedef SVC_HANDLER                        handler_type;
  typedef typename SVC_HANDLER::stream_type  stream_type;
  /// Virtual Destructor
  virtual ~ACE_Recycling_Strategy (void);
  /// Tell the Svc_Handler something about the recycler, so that it can
  /// reach the recycler when necessary.
  virtual int assign_recycler (SVC_HANDLER *svc_handler,
                               ACE_Connection_Recycling_Strategy *recycler,
                               const void *recycling_act);
  /// This allows us to prepare the svc_handler for recycling.
  virtual int prepare_for_recycling (SVC_HANDLER *svc_handler);
};
/**
 * @class ACE_Creation_Strategy
 *
 * @brief Defines the interface for specifying a creation strategy for
 * a SVC_HANDLER.
 *
 * The default behavior is to make a new SVC_HANDLER.  However,
 * subclasses can override this strategy to perform SVC_HANDLER
 * creation in any way that they like (such as creating subclass
 * instances of SVC_HANDLER, using a singleton, dynamically
 * linking the handler, etc.).
 */
template <class SVC_HANDLER>
class ACE_Creation_Strategy
{
public:
  // Useful STL-style traits.
  typedef typename SVC_HANDLER::addr_type    addr_type;
  typedef SVC_HANDLER                        handler_type;
  typedef typename SVC_HANDLER::stream_type  stream_type;
  // = Initialization and termination methods.
  /// Default constructor.
  ACE_Creation_Strategy (ACE_Thread_Manager * = 0,
                         ACE_Reactor * = ACE_Reactor::instance ());
  /// An ACE_Thread_Manager is useful when creating active objects and
  /// the ACE_Reactor is used to initialize the service handler's reactor.
  int open (ACE_Thread_Manager * = 0,
            ACE_Reactor * = ACE_Reactor::instance ());
  virtual ~ACE_Creation_Strategy (void);
  // = Factory method.
  /**
   * Create a SVC_HANDLER with the appropriate creation strategy.  The
   * default behavior of this method is to make a new SVC_HANDLER if
   * @a sh == 0 (passing in the <Thread_Manager>), else @a sh is
   * unchanged.  Returns -1 on failure, else 0.
   */
  virtual int make_svc_handler (SVC_HANDLER *&sh);
  /// Dump the state of an object.
  void dump (void) const;
  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;
protected:
  /// Pointer to a thread manager.
  ACE_Thread_Manager *thr_mgr_;
  /// Pointer to an ACE_Reactor.
  ACE_Reactor *reactor_;
};
/**
 * @class ACE_Singleton_Strategy
 *
 * @brief Defines the interface for specifying a creation strategy for
 * a SVC_HANDLER that always returns the same SVC_HANDLER (i.e.,
 * it's a Singleton).
 *
 * Note that this class takes over the ownership of the
 * SVC_HANDLER passed into it as a parameter and it becomes
 * responsible for deleting this object.
 */
template <class SVC_HANDLER>
class ACE_Singleton_Strategy : public ACE_Creation_Strategy<SVC_HANDLER>
{
public:
  // Useful STL-style traits.
  typedef ACE_Creation_Strategy<SVC_HANDLER> base_type;
  // = Initialization and termination methods.
  ACE_Singleton_Strategy (SVC_HANDLER * = 0,
                          ACE_Thread_Manager * = 0);
  int open (SVC_HANDLER *,
            ACE_Thread_Manager * = 0);
  virtual ~ACE_Singleton_Strategy (void);
  // = Factory method.
  /// Create a Singleton SVC_HANDLER by always returning the same
  /// SVC_HANDLER.  Returns -1 on failure, else 0.
  virtual int make_svc_handler (SVC_HANDLER *&);
  /// Dump the state of an object.
  void dump (void) const;
  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;
protected:
  /// Pointer to the Singleton svc_handler.
  SVC_HANDLER *svc_handler_;
  /// Keep track of whether we need to delete the SVC_HANDLER.
  bool delete_svc_handler_;
};
/**
 * @class ACE_DLL_Strategy
 *
 * @brief Defines the interface for specifying a creation strategy for
 * a SVC_HANDLER based on dynamic linking of the SVC_HANDLER.
 */
template <class SVC_HANDLER>
class ACE_DLL_Strategy : public ACE_Creation_Strategy<SVC_HANDLER>
{
public:
  // Useful STL-style traits.
  typedef ACE_Creation_Strategy<SVC_HANDLER> base_type;
  // = Intialization and termination methods.
  /// "Do-nothing" constructor.
  ACE_DLL_Strategy (void);
  /// Initialize the DLL strategy based upon the service's DLL
  /// information contained in the <svc_dll_info> string.
  ACE_DLL_Strategy (const ACE_TCHAR dll_name[],
                    const ACE_TCHAR factory_function[],
                    const ACE_TCHAR svc_name[],
                    ACE_Service_Repository *,
                    ACE_Thread_Manager * = 0);
  /// Initialize the DLL strategy based upon the service's DLL
  /// information contained in the <svc_dll_info> string.
  int open (const ACE_TCHAR dll_name[],
            const ACE_TCHAR factory_function[],
            const ACE_TCHAR svc_name[],
            ACE_Service_Repository *,
            ACE_Thread_Manager * = 0);
  // = Factory method.
  /// Create a SVC_HANDLER by dynamically linking it from a DLL.
  /// Returns -1 on failure, else 0.
  virtual int make_svc_handler (SVC_HANDLER *&);
  /// Dump the state of an object.
  void dump (void) const;
  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;
protected:
  typedef ACE_Creation_Strategy<SVC_HANDLER> inherited;
  /// Name of the DLL to dynamically link.
  ACE_TCHAR dll_name_[MAXPATHLEN + 1];
  /// Name of the factory function in the shared library to use to
  /// obtain a pointer to the new SVC_HANDLER.
  ACE_TCHAR factory_function_[MAXPATHLEN + 1];
  /// Name of the service.
  ACE_TCHAR svc_name_[MAXNAMELEN + 1];
  /// Pointer to the <Service_Repository>.
  ACE_Service_Repository *svc_rep_;
};
/**
 * @class ACE_Concurrency_Strategy
 *
 * @brief Defines the interface for specifying a concurrency strategy
 * for a SVC_HANDLER.
 *
 * Default behavior is to activate the SVC_HANDLER by calling
 * its <open> method (which allows the SVC_HANDLER to define its
 * own concurrency strategy).  However, subclasses can override
 * this default strategy to do more sophisticated concurrency
 * activations (such as creating the SVC_HANDLER as an active
 * object via multi-threading or multi-processing).
 */
template <class SVC_HANDLER>
class ACE_Concurrency_Strategy
{
public:
  // Useful STL-style traits.
  typedef typename SVC_HANDLER::addr_type    addr_type;
  typedef SVC_HANDLER                        handler_type;
  typedef typename SVC_HANDLER::stream_type  stream_type;
  /// Constructor
  ACE_Concurrency_Strategy (int flags = 0);
  // = Factory method.
  /**
   * Activate the <svc_handler> with an appropriate concurrency
   * strategy.  The default behavior of this method is to activate the
   * SVC_HANDLER by calling its <open> method (which allows the
   * SVC_HANDLER to define its own concurrency strategy).
   */
  virtual int activate_svc_handler (SVC_HANDLER *svc_handler,
                                    void *arg = 0);
  virtual ~ACE_Concurrency_Strategy (void);
  /// Dump the state of an object.
  void dump (void) const;
  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;
protected:
  /// Flags that are parsed to set options for the connected
  /// SVC_HANDLER.
  int flags_;
};
/**
 * @class ACE_Reactive_Strategy
 *
 * @brief Defines the interface for specifying a reactive concurrency
 * strategy for a SVC_HANDLER, where all upcalls to @c handle_*()
 * methods run in the reactor's thread of control.
 *
 * This class provides a strategy that registers the
 * SVC_HANDLER with a <Reactor>.
 */
template <class SVC_HANDLER>
class ACE_Reactive_Strategy : public ACE_Concurrency_Strategy <SVC_HANDLER>
{
public:
  // Useful STL-style traits.
  typedef ACE_Concurrency_Strategy<SVC_HANDLER> base_type;
  // = Intialization and termination methods.
  /// "Do-nothing constructor"
  ACE_Reactive_Strategy (int flags = 0);
  /// Initialize the strategy.
  ACE_Reactive_Strategy (ACE_Reactor *reactor,
                         ACE_Reactor_Mask = ACE_Event_Handler::READ_MASK,
                         int flags = 0);
  /// Initialize the strategy.
  virtual int open (ACE_Reactor *reactor,
                    ACE_Reactor_Mask = ACE_Event_Handler::READ_MASK,
                    int flags = 0);
  /// Destructor.
  virtual ~ACE_Reactive_Strategy (void);
  // = Factory method.
  /// Activate the <svc_handler> by registering it with the <Reactor>
  /// and then calling it's <open> hook.
  virtual int activate_svc_handler (SVC_HANDLER *svc_handler,
                                    void *arg = 0);
  /// Dump the state of an object.
  void dump (void) const;
  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;
protected:
  typedef ACE_Concurrency_Strategy<SVC_HANDLER> inherited;
  /// Pointer to the Reactor we'll use to register the SVC_HANDLER.
  ACE_Reactor *reactor_;
  /// The mask that we pass to the <Reactor> when we register the
  /// SVC_HANDLER.
  ACE_Reactor_Mask mask_;
};
/**
 * @class ACE_Thread_Strategy
 *
 * @brief Defines the interface for specifying a concurrency strategy
 * for a SVC_HANDLER based on multithreading.
 *
 * This class provides a strategy that manages the creation of threads
 * to handle requests from clients concurrently via a
 * thread-per-connection model.  It behaves as a "thread factory",
 * spawning threads "on-demand" to run the service specified by a
 * user-supplied SVC_HANDLER.
 */
template <class SVC_HANDLER>
class ACE_Thread_Strategy : public ACE_Concurrency_Strategy<SVC_HANDLER>
{
public:
  // Useful STL-style traits.
  typedef ACE_Concurrency_Strategy<SVC_HANDLER> base_type;
  // = Intialization and termination methods.
  /// "Do-nothing constructor"
  ACE_Thread_Strategy (int flags = 0);
  /// Initialize the strategy.
  ACE_Thread_Strategy (ACE_Thread_Manager *tm,
                       long thr_flags,
                       int n_threads = 1,
                       int flags = 0);
  /// Initialize the strategy.
  virtual int open (ACE_Thread_Manager *tm,
                    long thr_flags,
                    int n_threads = 1,
                    int flags = 0);
  virtual ~ACE_Thread_Strategy (void);
  // = Factory method.
  /**
   * Activate the @a svc_handler with an appropriate concurrency
   * strategy.  This method activates the SVC_HANDLER by first calling
   * its <open> method and then calling its <activate> method to turn
   * it into an active object.
   */
  virtual int activate_svc_handler (SVC_HANDLER *svc_handler,
                                    void *arg = 0);
  /// Dump the state of an object.
  void dump (void) const;
  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;
protected:
  typedef ACE_Concurrency_Strategy<SVC_HANDLER> inherited;
  /// Thread manager for this class (must be provided).
  ACE_Thread_Manager *thr_mgr_;
  /// Flags to pass into the <SVC_HANDLER::activate> method.
  long thr_flags_;
  /// Number of threads to spawn.
  int n_threads_;
};
/**
 * @class ACE_Process_Strategy
 *
 * @brief Defines the interface for specifying a concurrency strategy
 * for a @c SVC_HANDLER based on multiprocessing.
 *
 * This class provides a strategy that manages the creation of
 * processes to handle requests from clients concurrently using a
 * process-per-connection model.  It behaves as a "process factory",
 * using @c ACE::fork() to fork threads "on-demand" to run the service
 * specified by a user-supplied @c SVC_HANDLER in a separate process.
 */
template <class SVC_HANDLER>
class ACE_Process_Strategy : public ACE_Concurrency_Strategy<SVC_HANDLER>
{
public:
  // Useful STL-style traits.
  typedef ACE_Concurrency_Strategy<SVC_HANDLER> base_type;
  // = Intialization and termination methods.
  /// Initialize the strategy.  If @a avoid_zombies is non-0 then set a
  /// flag to ACE::fork() to avoid zombies.
  ACE_Process_Strategy (size_t n_processes = 1,
                        ACE_Event_Handler *acceptor = 0,
                        ACE_Reactor * = 0,
                        int avoid_zombies = 0);
  /// Initialize the strategy.  If @a avoid_zombies is non-0 then set a
  /// flag to ACE::fork() to avoid zombies.
  virtual int open (size_t n_processes = 1,
                    ACE_Event_Handler *acceptor = 0,
                    ACE_Reactor * = 0,
                    int avoid_zombies = 0);
  virtual ~ACE_Process_Strategy (void);
  // = Factory method.
  /**
   * Activate the @a svc_handler with an appropriate concurrency
   * strategy.  This method activates the SVC_HANDLER by first forking
   * and then calling the @c open() method of the SVC_HANDLER in the
   * child.
   */
  virtual int activate_svc_handler (SVC_HANDLER *svc_handler,
                                    void *arg = 0);
  /// Dump the state of an object.
  void dump (void) const;
  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;
protected:
  typedef ACE_Concurrency_Strategy<SVC_HANDLER> inherited;
  /// Number of processes to spawn.
  size_t n_processes_;
  /**
   * This is the @c Acceptor in the parent is listening on.  We need to
   * make sure that we remove it from the Reactor and close it down in
   * the child.
   */
  ACE_Event_Handler *acceptor_;
  /**
   * This is the reactor the child is using in conjunction with the
   * acceptor.  We need to remove the acceptor from this reactor
   * in the child.
   */
  ACE_Reactor *reactor_;
};
/**
 * @class ACE_Accept_Strategy
 *
 * @brief Defines the interface for specifying a passive connection
 * acceptance strategy for a SVC_HANDLER.
 *
 * This class provides a strategy that manages passive
 * connection acceptance of a client.
 */
template <class SVC_HANDLER, ACE_PEER_ACCEPTOR_1>
class ACE_Accept_Strategy
{
public:
  // Useful STL-style traits.
  typedef ACE_PEER_ACCEPTOR_ADDR             addr_type;
  typedef ACE_PEER_ACCEPTOR                  acceptor_type;
  typedef SVC_HANDLER                        handler_type;
  typedef typename SVC_HANDLER::stream_type  stream_type;
  // = Initialization and termination methods.
  /// Default constructor.
  ACE_Accept_Strategy (ACE_Reactor *reactor = ACE_Reactor::instance ());
  /// Initialize the @c peer_acceptor_ with @a local_addr.
  ACE_Accept_Strategy (const ACE_PEER_ACCEPTOR_ADDR &local_addr,
                       int restart = 0,
                       ACE_Reactor *reactor = ACE_Reactor::instance ());
  /// Initialize the <peer_acceptor_> with @a local_addr, indicating
  /// whether to @a reuse_addr if it's already in use.
  virtual int open (const ACE_PEER_ACCEPTOR_ADDR &local_addr,
                    int reuse_addr = 0);
  /// Return the underlying ACE_HANDLE of the <peer_acceptor_>.
  virtual ACE_HANDLE get_handle (void) const;
  /// Return a reference to the <peer_acceptor_>.
  virtual ACE_PEER_ACCEPTOR &acceptor (void) const;
  virtual ~ACE_Accept_Strategy (void);
  // = Factory method.
  /// The default behavior delegates to the <accept> method of the
  /// PEER_ACCEPTOR.
  virtual int accept_svc_handler (SVC_HANDLER *);
  /// Dump the state of an object.
  void dump (void) const;
  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;
protected:
  /// Factory that establishes connections passively.
  ACE_PEER_ACCEPTOR peer_acceptor_;
  /// Pointer to the reactor used by the Acceptor.
  ACE_Reactor *reactor_;
  /// Needed to reopen the socket if <accept> fails.
  int reuse_addr_;
  /// Needed to reopen the socket if <accept> fails.
  ACE_PEER_ACCEPTOR_ADDR peer_acceptor_addr_;
};
/**
 * @class ACE_Connect_Strategy
 *
 * @brief Defines the interface for specifying an active
 * connection establishment strategy for a SVC_HANDLER.
 *
 * This class provides a strategy that manages active
 * connection establishment to a server.
 */
template <class SVC_HANDLER, ACE_PEER_CONNECTOR_1>
class ACE_Connect_Strategy
{
public:
  // Useful STL-style traits.
  typedef ACE_PEER_CONNECTOR_ADDR            addr_type;
  typedef ACE_PEER_CONNECTOR                 connector_type;
  typedef SVC_HANDLER                        handler_type;
  typedef typename SVC_HANDLER::stream_type  stream_type;
  // = Initialization and termination methods.
  /// Default constructor.
  ACE_Connect_Strategy (void);
  /// Return a reference to the <peer_connector_>.
  virtual ACE_PEER_CONNECTOR &connector (void) const;
  virtual ~ACE_Connect_Strategy (void);
  // = Factory method.
  /// The default behavior delegates to the <connect> method of the
  /// <PEER_CONNECTOR::connect>.
  virtual int connect_svc_handler (SVC_HANDLER *&sh,
                                   const ACE_PEER_CONNECTOR_ADDR &remote_addr,
                                   ACE_Time_Value *timeout,
                                   const ACE_PEER_CONNECTOR_ADDR &local_addr,
                                   int reuse_addr,
                                   int flags,
                                   int perms);
  /**
   * The default behavior delegates to the <connect> method of the
   * <PEER_CONNECTOR::connect>.
   * Please check the documentation in Connector.h for more details.
   */
  virtual int connect_svc_handler (SVC_HANDLER *&sh,
                                   SVC_HANDLER *&sh_copy,
                                   const ACE_PEER_CONNECTOR_ADDR &remote_addr,
                                   ACE_Time_Value *timeout,
                                   const ACE_PEER_CONNECTOR_ADDR &local_addr,
                                   int reuse_addr,
                                   int flags,
                                   int perms);
  /// Dump the state of an object.
  void dump (void) const;
  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;
protected:
  /// Factory that establishes connections actively.
  ACE_PEER_CONNECTOR connector_;
};
/**
 * @class ACE_Scheduling_Strategy
 *
 * @brief Defines the interface for specifying how to suspend and
 * resume a service .
 *
 * This class provides a strategy that allows arbitrarily
 * sophisticated service suspension and resumption.  The default
 * behavior is to do nothing...
 */
template <class SVC_HANDLER>
class ACE_Scheduling_Strategy
{
public:
  // Useful STL-style traits.
  typedef typename SVC_HANDLER::addr_type    addr_type;
  typedef SVC_HANDLER                        handler_type;
  typedef typename SVC_HANDLER::stream_type  stream_type;
  // = Initialization and termination methods.
  /// Constructor
  ACE_Scheduling_Strategy (SVC_HANDLER * = 0);
  /// Destructor
  virtual ~ACE_Scheduling_Strategy (void);
  // = Scheduling methods
  /// Suspend hook.
  virtual int suspend (void);
  /// Resume hook.
  virtual int resume (void);
  /// Dump the state of the object.
  virtual void dump (void) const;
};
/**
 * @class ACE_Schedule_All_Reactive_Strategy
 *
 * @brief Defines the interface for specifying how to suspend and
 * resume a single-threaded reactive service .
 *
 * This class provides a strategy that suspends and resumes all
 * the Event_Handlers in a Reactor in one fell swoop.
 */
template <class SVC_HANDLER>
class ACE_Schedule_All_Reactive_Strategy
  : public ACE_Scheduling_Strategy<SVC_HANDLER>
{
public:
  // Useful STL-style traits.
  typedef ACE_Scheduling_Strategy<SVC_HANDLER> base_type;
  // = Initialization and termination methods.
  /// Constructor
  ACE_Schedule_All_Reactive_Strategy (SVC_HANDLER * = 0);
  // = Scheduling methods
  /// Suspend hook.
  virtual int suspend (void);
  /// Resume hook.
  virtual int resume (void);
  /// Dump the state of the object.
  virtual void dump (void) const;
protected:
  /// Reactor
  ACE_Reactor *reactor_;
};
/**
 * @class ACE_Schedule_All_Threaded_Strategy
 *
 * @brief Defines the interface for specifying how to suspend and
 * resume a multithreaded service .
 *
 * This class provides a strategy that suspends and resumes all
 * the Event_Handlers controlled by a Thread_Manager in one fell swoop.
 */
template <class SVC_HANDLER>
class ACE_Schedule_All_Threaded_Strategy
  : public ACE_Scheduling_Strategy<SVC_HANDLER>
{
public:
  // Useful STL-style traits.
  typedef ACE_Scheduling_Strategy<SVC_HANDLER> base_type;
  // = Initialization and termination methods.
  /// Constructor
  ACE_Schedule_All_Threaded_Strategy (SVC_HANDLER * = 0);
  // = Scheduling methods
  /// Suspend hook.
  virtual int suspend (void);
  /// Resume hook.
  virtual int resume (void);
  /// Dump the state of the object.
  virtual void dump (void) const;
protected:
  /// Thread Manager
  ACE_Thread_Manager *thr_mgr_;
};
/**
 * @class ACE_NOOP_Creation_Strategy
 *
 * @brief Implements a no-op creation strategy in order to defer
 * decisions regarding creation to some later point in time, such
 * as in connect or accept strategy.
 *
 * An example of the use of this is in the
 * ACE_Cached_Connect_Strategy, which only returns a single
 * connection for a given endpoint.
 */
template <class SVC_HANDLER>
class ACE_NOOP_Creation_Strategy : public ACE_Creation_Strategy<SVC_HANDLER>
{
public:
  // Useful STL-style traits.
  typedef ACE_Creation_Strategy<SVC_HANDLER> base_type;
  /// This is a no-op.
  virtual int make_svc_handler (SVC_HANDLER *&);
};
/**
 * @class ACE_NOOP_Concurrency_Strategy
 *
 * @brief Implements a no-op activation strategy in order to avoid
 * calling open on a svc_handler multiple times.
 *
 * An example of the use of this is in the
 * ACE_Cached_Connect_Strategy, which reuses svc_handlers.
 * Therefore we don't want to call open on the recycled
 * svc_handler more than once.
 */
template <class SVC_HANDLER>
class ACE_NOOP_Concurrency_Strategy
  : public ACE_Concurrency_Strategy<SVC_HANDLER>
{
public:
  // Useful STL-style traits.
  typedef ACE_Concurrency_Strategy<SVC_HANDLER> base_type;
  // = Factory method.
  /// This is a no-op.
  virtual int activate_svc_handler (SVC_HANDLER *svc_handler,
                                    void *arg = 0);
};
template <class T>
class ACE_Refcounted_Hash_Recyclable :  public ACE_Refcountable,
                                        public ACE_Hashable,
                                        public ACE_Recyclable
{
public:
  /// Default constructor.
  ACE_Refcounted_Hash_Recyclable (void);
  /// Constructor.
  ACE_Refcounted_Hash_Recyclable (const T &t,
                                  long refcount = 0,
                                  ACE_Recyclable_State state = ACE_RECYCLABLE_UNKNOWN);
  /// Destructor
  virtual ~ACE_Refcounted_Hash_Recyclable (void);
  /// Compares two instances.
  bool operator== (const ACE_Refcounted_Hash_Recyclable<T> &rhs) const;
  bool operator!= (const ACE_Refcounted_Hash_Recyclable<T> &rhs) const;
  T &subject ();
protected:
  /// Computes and returns hash value.
  u_long hash_i (void) const;
  T t_;
};
/**
 * @class ACE_Cached_Connect_Strategy
 *
 * @brief A connection strategy which caches connections to peers
 * (represented by SVC_HANDLER instances), thereby allowing
 * subsequent re-use of unused, but available, connections.
 *
 * <ACE_Cached_Connect_Strategy> is intended to be used as a
 * plug-in connection strategy for ACE_Strategy_Connector.
 * It's added value is re-use of established connections.
 */
template <class SVC_HANDLER, ACE_PEER_CONNECTOR_1, class MUTEX>
class ACE_Cached_Connect_Strategy
  : public ACE_Connection_Recycling_Strategy,
    public ACE_Connect_Strategy<SVC_HANDLER, ACE_PEER_CONNECTOR_2>
{
public:
  // Useful STL-style traits.
  typedef ACE_Creation_Strategy<SVC_HANDLER>
          creation_strategy_type;
  typedef ACE_Connect_Strategy<SVC_HANDLER, ACE_PEER_CONNECTOR_2>
          connect_strategy_type;
  typedef ACE_Concurrency_Strategy<SVC_HANDLER>
          concurrency_strategy_type;
  typedef ACE_Recycling_Strategy<SVC_HANDLER> recycling_strategy_type;
  // = Define some useful (old style) traits.
  typedef ACE_Creation_Strategy<SVC_HANDLER>
          CREATION_STRATEGY;
  typedef ACE_Concurrency_Strategy<SVC_HANDLER>
          CONCURRENCY_STRATEGY;
  typedef ACE_Recycling_Strategy<SVC_HANDLER>
          RECYCLING_STRATEGY;
  // = Super class
  typedef ACE_Connect_Strategy<SVC_HANDLER, ACE_PEER_CONNECTOR_2>
          CONNECT_STRATEGY;

  typedef ACE_Cached_Connect_Strategy<SVC_HANDLER, ACE_PEER_CONNECTOR_2, MUTEX> SELF;
  /// Constructor
  ACE_Cached_Connect_Strategy (ACE_Creation_Strategy<SVC_HANDLER> *cre_s = 0,
                               ACE_Concurrency_Strategy<SVC_HANDLER> *con_s = 0,
                               ACE_Recycling_Strategy<SVC_HANDLER> *rec_s = 0,
                               MUTEX *mutex = 0,
                               bool delete_lock = false);
  /// Destructor
  virtual ~ACE_Cached_Connect_Strategy (void);
  /// This methods allow you to change the strategies used by the
  /// cached connector.
  virtual int open (ACE_Creation_Strategy<SVC_HANDLER> *cre_s,
                    ACE_Concurrency_Strategy<SVC_HANDLER> *con_s,
                    ACE_Recycling_Strategy<SVC_HANDLER> *rec_s);
  /// Template method for making a new <svc_handler>
  virtual int make_svc_handler (SVC_HANDLER *&sh);
  /// Template method for activating a new <svc_handler>
  virtual int activate_svc_handler (SVC_HANDLER *svc_handler);
  /// Template method for setting the recycler information of the
  /// svc_handler.
  virtual int assign_recycler (SVC_HANDLER *svc_handler,
                               ACE_Connection_Recycling_Strategy *recycler,
                               const void *recycling_act);
  /// Template method for preparing the svc_handler for recycling.
  virtual int prepare_for_recycling (SVC_HANDLER *svc_handler);
  /**
   * Checks to see if there is already a <SVC_HANDLER> in the cache
   * connected to the <remote_addr>.  If so, we return this pointer.
   * Otherwise we establish the connection, put it into the cache, and
   * return the SVC_HANDLER pointer.  <[NOTE]>: the <{reuse_addr}>
   * argument does NOT control re-use of addresses in the cache.
   * Rather, if the underlying protocol requires a "dead time" prior
   * to re-use of its addresses (TCP is a classic example of this),
   * <{and}> the protocol provides a means by which to defeat the dead
   * time, setting this argument to non-zero will defeat the dead-time
   * requirement.  <{Dev. Note: We might want to consider enhancing
   * the interface at some point so that this also controls re-use of
   * the cache.}>
   */
  virtual int connect_svc_handler (SVC_HANDLER *&sh,
                                   const ACE_PEER_CONNECTOR_ADDR &remote_addr,
                                   ACE_Time_Value *timeout,
                                   const ACE_PEER_CONNECTOR_ADDR &local_addr,
                                   int reuse_addr,
                                   int flags,
                                   int perms);
  virtual int connect_svc_handler (SVC_HANDLER *&sh,
                                   SVC_HANDLER *&sh_copy,
                                   const ACE_PEER_CONNECTOR_ADDR &remote_addr,
                                   ACE_Time_Value *timeout,
                                   const ACE_PEER_CONNECTOR_ADDR &local_addr,
                                   int reuse_addr,
                                   int flags,
                                   int perms);
  /// Remove from cache.
  virtual int purge (const void *recycling_act);
  /// Add to cache.
  virtual int cache (const void *recycling_act);
  /// Get/Set <recycle_state>.
  virtual int recycle_state (const void *recycling_act,
                             ACE_Recyclable_State new_state);
  virtual ACE_Recyclable_State recycle_state (const void *recycling_act) const;
  /// Mark as closed.
  virtual int mark_as_closed (const void *recycling_act);
  /**
   * Mark as closed (non-locking version). This method needs to be public
   * as it is used in the cleanup of handlers where teh locked version causes
   * a deadlock.
   */
  virtual int mark_as_closed_i (const void *recycling_act);
  /// Cleanup hint and reset <*act_holder> to zero if <act_holder != 0>.
  virtual int cleanup_hint (const void *recycling_act,
                            void **act_holder = 0);
  // = Traits for managing the map
  typedef ACE_Refcounted_Hash_Recyclable<ACE_PEER_CONNECTOR_ADDR>
          REFCOUNTED_HASH_RECYCLABLE_ADDRESS;
  typedef ACE_Hash_Map_Manager_Ex<REFCOUNTED_HASH_RECYCLABLE_ADDRESS, SVC_HANDLER *, ACE_Hash<REFCOUNTED_HASH_RECYCLABLE_ADDRESS>, ACE_Equal_To<REFCOUNTED_HASH_RECYCLABLE_ADDRESS>, ACE_Null_Mutex>
          CONNECTION_MAP;
  typedef typename CONNECTION_MAP::ITERATOR CONNECTION_MAP_ITERATOR;
  typedef typename CONNECTION_MAP::ENTRY CONNECTION_MAP_ENTRY;
  typedef ACE_Reverse_Lock<MUTEX> REVERSE_MUTEX;
  // = Strategy accessors
  virtual ACE_Creation_Strategy<SVC_HANDLER> *creation_strategy (void) const;
  virtual ACE_Recycling_Strategy<SVC_HANDLER> *recycling_strategy (void) const;
  virtual ACE_Concurrency_Strategy<SVC_HANDLER> *concurrency_strategy (void) const;
protected:
  /// Creates a new connection.
  virtual int new_connection (SVC_HANDLER *&sh,
                              const ACE_PEER_CONNECTOR_ADDR &remote_addr,
                              ACE_Time_Value *timeout,
                              const ACE_PEER_CONNECTOR_ADDR &local_addr,
                              int reuse_addr,
                              int flags,
                              int perms);
  /// Find an idle handle.
  int find (REFCOUNTED_HASH_RECYCLABLE_ADDRESS &search_addr,
            CONNECTION_MAP_ENTRY *&entry);
  /// Remove from cache (non-locking version).
  virtual int purge_i (const void *recycling_act);
  /// Add to cache (non-locking version).
  virtual int cache_i (const void *recycling_act);
  /// Set <recycle_state> (non-locking version).
  virtual int recycle_state_i (const void *recycling_act,
                               ACE_Recyclable_State new_state);
  /// Get <recycle_state> (non-locking version).
  virtual ACE_Recyclable_State recycle_state_i (const void *recycling_act) const;
  /// Cleanup hint and reset <*act_holder> to zero if <act_holder != 0>.
  virtual int cleanup_hint_i (const void *recycling_act,
                              void **act_holder);
  // = Helpers
  int check_hint_i (SVC_HANDLER *&sh,
                    const ACE_PEER_CONNECTOR_ADDR &remote_addr,
                    ACE_Time_Value *timeout,
                    const ACE_PEER_CONNECTOR_ADDR &local_addr,
                    int reuse_addr,
                    int flags,
                    int perms,
                    CONNECTION_MAP_ENTRY *&entry,
                    int &found);
  int find_or_create_svc_handler_i (SVC_HANDLER *&sh,
                                    const ACE_PEER_CONNECTOR_ADDR &remote_addr,
                                    ACE_Time_Value *timeout,
                                    const ACE_PEER_CONNECTOR_ADDR &local_addr,
                                    int reuse_addr,
                                    int flags,
                                    int perms,
                                    CONNECTION_MAP_ENTRY *&entry,
                                    int &found);
  virtual int connect_svc_handler_i (
    SVC_HANDLER *&sh,
    const ACE_PEER_CONNECTOR_ADDR &remote_addr,
    ACE_Time_Value *timeout,
    const ACE_PEER_CONNECTOR_ADDR &local_addr,
    int reuse_addr,
    int flags,
    int perms,
    int &found);
  /// Table that maintains the cache of connected SVC_HANDLERs.
  CONNECTION_MAP connection_map_;
  /// Mutual exclusion for this object.
  MUTEX *lock_;
  /// Mutual exclusion for this object.
  bool delete_lock_;
  /// Reverse lock.
  REVERSE_MUTEX *reverse_lock_;
  // = Strategy objects.
  /// Creation strategy for an <Connector>.
  CREATION_STRATEGY *creation_strategy_;
  /// true if <Connector> created the creation strategy and thus should
  /// delete it, else false.
  bool delete_creation_strategy_;
  /// Concurrency strategy for an <Connector>.
  CONCURRENCY_STRATEGY *concurrency_strategy_;
  /// true if <Connector> created the concurrency strategy and thus should
  /// delete it, else false.
  bool delete_concurrency_strategy_;
  /// Recycling strategy for an <Connector>.
  RECYCLING_STRATEGY *recycling_strategy_;
  /// true if <Connector> created the recycling strategy and thus should
  /// delete it, else false.
  bool delete_recycling_strategy_;
};
ACE_END_VERSIONED_NAMESPACE_DECL
#if defined (__ACE_INLINE__)
#include "ace/Strategies_T.inl"
#endif /* __ACE_INLINE__ */
#if defined (ACE_TEMPLATES_REQUIRE_SOURCE)
#include "ace/Strategies_T.cpp"
#endif /* ACE_TEMPLATES_REQUIRE_SOURCE */
#if defined (ACE_TEMPLATES_REQUIRE_PRAGMA)
#pragma implementation ("Strategies_T.cpp")
#endif /* ACE_TEMPLATES_REQUIRE_PRAGMA */
#include /**/ "ace/post.h"
#endif /* ACE_STRATEGIES_T_H */

