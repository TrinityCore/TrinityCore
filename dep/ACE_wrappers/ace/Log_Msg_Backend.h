// -*- C++ -*-

//=============================================================================
/**
 *  @file    Log_Msg_Backend.h
 *
 *  $Id: Log_Msg_Backend.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Douglas C. Schmidt <schmidt@cs.wustl.edu>
 */
//=============================================================================

#ifndef ACE_LOG_MSG_BACKEND_H
#define ACE_LOG_MSG_BACKEND_H
#include /**/ "ace/pre.h"

#include /**/ "ace/ACE_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/os_include/sys/os_types.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

class ACE_Log_Record;

/**
 * @class ACE_Log_Msg_Backend
 *
 * @brief Defines the interface for ACE_Log_Msg back end processing.
 *
 * The ACE_Log_Msg class uses ACE_Log_Msg_Backend as the target interface
 * for back end log record procesing. In addition to the classes ACE
 * derives from this (ACE_Log_Msg_NT_Event_Log, ACE_Log_Msg_UNIX_Syslog, and
 * ACE_Log_Msg_IPC) users can derive classes from ACE_Log_Msg_Backend for
 * use as a custom logger back end.
 */
class ACE_Export ACE_Log_Msg_Backend
{
public:
  /// No-op virtual destructor.
  virtual ~ACE_Log_Msg_Backend (void);

  /**
   * Open the back end object. Perform any actions needed to prepare
   * the object for later logging operations.
   *
   * @param logger_key  The character string passed to ACE_Log_Msg::open().
   *                    If the @c LOGGER logging destination is not being
   *                    used, any string can be passed through to the back end.
   *
   * @retval 0 for success.
   * @retval -1 for failure.
   */
  virtual int open (const ACE_TCHAR *logger_key) = 0;

  /**
   * Reset the backend.  If ACE_Log_Msg is reopened during execution, this
   * hook will be called. This method should perform any needed cleanup
   * activity (similar to close()) because this object won't be reopened
   * if the new open call does not specify use of this back end being reset.
   *
   * @retval Currently ignored, but to be safe, return 0 for success;
   *         -1 for failure.
   */
  virtual int reset (void) = 0;

  /// Close the backend completely.
  virtual int close (void) = 0;

  /**
   * Process a log record.
   *
   * @param log_record   The ACE_Log_Record to process.
   *
   * @retval -1 for failure; else it is customarily the number of bytes
   *         processed, but can also be 0 to signify success.
   */
  virtual ssize_t log (ACE_Log_Record &log_record) = 0;
};

ACE_END_VERSIONED_NAMESPACE_DECL

#include /**/ "ace/post.h"
#endif /* ACE_LOG_MSG_BACKEND_H */

