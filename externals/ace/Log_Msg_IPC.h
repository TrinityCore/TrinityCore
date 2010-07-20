// -*- C++ -*-

//=============================================================================
/**
 *  @file    Log_Msg_IPC.h
 *
 *  $Id: Log_Msg_IPC.h 84536 2009-02-20 09:28:48Z johnnyw $
 *
 *  @author Carlos O'Ryan <coryan@uci.edu>
 */
//=============================================================================

#ifndef ACE_LOG_MSG_LOGGER_H
#define ACE_LOG_MSG_LOGGER_H
#include /**/ "ace/pre.h"

#include "ace/Log_Msg_Backend.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/Default_Constants.h"

// IPC conduit between sender and client daemon.  This should be
// included in the ACE_Log_Msg class, but due to "order of include"
// problems it can't be...
#if (ACE_HAS_STREAM_LOG_MSG_IPC == 1)
# include "ace/SPIPE_Connector.h"
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
typedef ACE_SPIPE_Stream ACE_LOG_MSG_IPC_STREAM;
typedef ACE_SPIPE_Connector ACE_LOG_MSG_IPC_CONNECTOR;
typedef ACE_SPIPE_Addr ACE_LOG_MSG_IPC_ADDR;
ACE_END_VERSIONED_NAMESPACE_DECL
#else
# include "ace/SOCK_Connector.h"
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
typedef ACE_SOCK_Stream ACE_LOG_MSG_IPC_STREAM;
typedef ACE_SOCK_Connector ACE_LOG_MSG_IPC_CONNECTOR;
typedef ACE_INET_Addr ACE_LOG_MSG_IPC_ADDR;
ACE_END_VERSIONED_NAMESPACE_DECL
#endif /* ACE_HAS_STREAM_PIPES */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/// Defines the interfaces for ACE_Log_Msg backend.
/**
 * Implement an ACE_Log_Msg_Backend that logs to a remote logging
 * process.
 */
class ACE_Export ACE_Log_Msg_IPC : public ACE_Log_Msg_Backend
{
public:
  /// Constructor
  ACE_Log_Msg_IPC (void);

  /// Destructor
  virtual ~ACE_Log_Msg_IPC (void);

  /// Open a new connection
  virtual int open (const ACE_TCHAR *logger_key);

  /**
   * Reset the backend.  When changing the logging destination the
   * backend may need to properly disconnect from the remote logging
   * daemon and reclaim some local resources.  But we try to reduce
   * the number of local allocations/deallocations.
   */
  virtual int reset (void);

  virtual int close (void);
  virtual ssize_t log (ACE_Log_Record &log_record);

private:
  ACE_LOG_MSG_IPC_STREAM message_queue_;
};

ACE_END_VERSIONED_NAMESPACE_DECL

#include /**/ "ace/post.h"
#endif /* ACE_LOG_MSG_H */
