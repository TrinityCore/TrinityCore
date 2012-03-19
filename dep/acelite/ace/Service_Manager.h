// -*- C++ -*-

//=============================================================================
/**
 *  @file    Service_Manager.h
 *
 *  $Id: Service_Manager.h 81388 2008-04-23 14:02:05Z johnnyw $
 *
 *  @author Douglas C. Schmidt <schmidt@cs.wustl.edu>
 */
//=============================================================================

#ifndef ACE_SERVICE_MANAGER_H
#define ACE_SERVICE_MANAGER_H
#include /**/ "ace/pre.h"

#include "ace/SOCK_Stream.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/SOCK_Acceptor.h"
#include "ace/INET_Addr.h"
#include "ace/Service_Object.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class ACE_Service_Manager
 *
 * @brief Provide a standard ACE service for managing all the services
 * configured in an ACE_Service_Repository.
 *
 * This implementation is simple and just handles each client
 * request one at a time.  There are currently 3 types of requests:
 * - List services: If the string "help" is sent, return a list of all
 *   the services supported by the Service Configurator.
 * - Reconfigure: If the string "reconfigure" is sent trigger a
 *   reconfiguration, which will re-read the local <svc.conf> file.
 * - Process directive: If neither "help" nor "reconfigure" is sent,
 *   simply treat the incoming string as a process directive and pass
 *   it along to <ACE_Service_Config::process_directive>.  This allows
 *   remote configuration via command-line instructions like
 *   % echo suspend My_Remote_Service | telnet hostname 3911
 *
 * Each request is associated with a new connection, which is closed
 * when the request is processed.  In addition, you must be using the
 * singleton <ACE_Reactor::instance> in order to trigger
 * reconfigurations.
 */
class ACE_Export ACE_Service_Manager : public ACE_Service_Object
{
public:
  // = Initialization and termination hooks.
  /// Constructor.
  ACE_Service_Manager (void);

  /// Destructor.
  virtual ~ACE_Service_Manager (void);

protected:
  // = Perform the various meta-services.

  /// Trigger a reconfiguration of the Service Configurator by
  /// re-reading its local <svc.conf> file.
  virtual int reconfigure_services (void);

  /// Determine all the services offered by this daemon and return the
  /// information back to the client.
  virtual int list_services (void);

  // = Dynamic linking hooks.
  virtual int init (int argc, ACE_TCHAR *argv[]);
  virtual int info (ACE_TCHAR **info_string, size_t length) const;
  virtual int fini (void);

  // = Scheduling hooks.
  virtual int suspend (void);
  virtual int resume (void);

  /// Dump the state of an object.
  void dump (void) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

protected:
  int open (const ACE_INET_Addr &sia);

  // = Demultiplexing hooks.
  virtual ACE_HANDLE get_handle (void) const;
  virtual int handle_input (ACE_HANDLE fd);
  virtual int handle_close (ACE_HANDLE fd, ACE_Reactor_Mask);
  virtual int handle_signal (int signum, siginfo_t *, ucontext_t *);

  /// Handle one request.
  virtual void process_request (ACE_TCHAR *request);

  /// Connection to the client (we only support one client connection
  /// at a time).
  ACE_SOCK_Stream client_stream_;

  /// Acceptor instance.
  ACE_SOCK_Acceptor acceptor_;

  /// Keep track whether we debug or not.
  bool debug_;

  /// The signal used to trigger reconfiguration.
  int signum_;

  /// Default port for the Acceptor to listen on.
  static u_short DEFAULT_PORT_;
};

ACE_END_VERSIONED_NAMESPACE_DECL

#include /**/ "ace/post.h"
#endif /* _SERVICE_MANAGER_H */
