// -*- C++ -*-

//=============================================================================
/**
 *  @file    Log_Msg_UNIX_Syslog.h
 *
 *  $Id: Log_Msg_UNIX_Syslog.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Jerry D. De Master <jdemaster@rite-solutions.com>
 */
//=============================================================================

#ifndef ACE_LOG_MSG_UNIX_SYSLOG_H
#define ACE_LOG_MSG_UNIX_SYSLOG_H
#include /**/ "ace/pre.h"

#include /**/ "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if !defined (ACE_LACKS_UNIX_SYSLOG)

#include "ace/Log_Msg_Backend.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class ACE_Log_Msg_UNIX_Syslog
 *
 * @brief Implements an ACE_Log_Msg_Backend that logs messages to a UNIX
 * system's syslog facility.
 */
class ACE_Export ACE_Log_Msg_UNIX_Syslog : public ACE_Log_Msg_Backend
{
public:
  /// Constructor
  ACE_Log_Msg_UNIX_Syslog (void);

  /// Destructor
  virtual ~ACE_Log_Msg_UNIX_Syslog (void);

  /// Open a new event log.
  /**
   * Initialize the event logging facility.
   * @param logger_key The name of the calling program. This name is
   *                   used as the @c ident in the syslog entries. If
   *                   it is 0 (no name), the application name as
   *                   returned from ACE_Log_Msg::program_name() is used.
   */
  virtual int open (const ACE_TCHAR *logger_key);

  /// Reset the backend.
  virtual int reset (void);

  /// Close the backend completely.
  virtual int close (void);

  /// This is called when we want to log a message.
  virtual ssize_t log (ACE_Log_Record &log_record);

private:
  /// Convert an ACE_Log_Priority value to the corresponding syslog priority.
  int convert_log_priority (ACE_UINT32 lm_priority);

  /// Convert an ACE_Log_Priority mask to the corresponding syslog mask value.
  int convert_log_mask (int lm_mask);
};

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* !ACE_LACKS_UNIX_SYSLOG */

#include /**/ "ace/post.h"
#endif /* ACE_LOG_MSG_UNIX_SYSLOG_H */
