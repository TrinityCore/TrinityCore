// -*- C++ -*-
//=============================================================================
/**
 *  @file    Name_Proxy.h
 *
 *  $Id: Name_Proxy.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  Proxy for dealing with remote server process managing NET_LOCAL
 *  Name_Bindings.
 *
 *
 *  @author Gerhard Lenzer
 *  @author Douglas C. Schmidt
 *  @author Prashant Jain
 */
//=============================================================================

#ifndef ACE_NAME_PROXY_H
#define ACE_NAME_PROXY_H
#include /**/ "ace/pre.h"
#include "ace/INET_Addr.h"
#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */
#include "ace/SOCK_Connector.h"
#include "ace/SOCK_Stream.h"
#include "ace/Service_Config.h"
#include "ace/Synch_Options.h"
#include "ace/Name_Request_Reply.h"
#include "ace/Event_Handler.h"
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
/**
 * @class ACE_Name_Proxy
 *
 * @brief Proxy for dealing with remote server process managing NET_LOCAL
 * NameBindings.
 *
 * Shields applications from details of interacting with the
 * ACE_Name Server.
 */
class ACE_Export ACE_Name_Proxy : public ACE_Event_Handler
{
public:
  /// Default constructor.
  ACE_Name_Proxy (void);
  // = Establish a binding with the ACE_Name Server.
  ACE_Name_Proxy (const ACE_INET_Addr &remote_addr, // Address of ACE_Name Server.
                  ACE_Synch_Options& options =
                  ACE_Synch_Options::defaults);
  int open (const ACE_INET_Addr &remote_addr,  // Address of ACE_Name Server.
            ACE_Synch_Options& options =
            ACE_Synch_Options::defaults);
  /// Perform the request and wait for the reply.
  int request_reply (ACE_Name_Request &request);
  /// Perform the request.
  int send_request (ACE_Name_Request &request);
  /// Receive the reply.
  int recv_reply (ACE_Name_Request &reply);
  /// Obtain underlying handle.
  virtual ACE_HANDLE get_handle (void) const;
  /// Close down the connection to the server.
  virtual ~ACE_Name_Proxy (void);
  /// Dump the state of the object;
  void dump (void) const;
private:
  /// ACE_Connector factory used to establish connections actively.
  ACE_SOCK_Connector connector_;
  /// Connection to ACE_Name Server peer.
  ACE_SOCK_Stream peer_;
  /// Pointer to ACE_Reactor (used if we are run in "reactive-mode").
  ACE_Reactor *reactor_;
private:
  // Prevent copying
  ACE_Name_Proxy (const ACE_Name_Proxy &);
  ACE_Name_Proxy &operator= (const ACE_Name_Proxy &);
};
ACE_END_VERSIONED_NAMESPACE_DECL
#include /**/ "ace/post.h"
#endif /* ACE_NAME_PROXY_H */

