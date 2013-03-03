// $Id: Log_Msg_UNIX_Syslog.cpp 92791 2010-12-04 16:25:22Z shuston $

#include "ace/config-all.h"

#if !defined (ACE_LACKS_UNIX_SYSLOG)

#include "ace/ACE.h"
#include "ace/Log_Msg.h"
#include "ace/Log_Msg_UNIX_Syslog.h"
#include "ace/Log_Record.h"
#include "ace/OS_NS_string.h"
#include "ace/os_include/os_syslog.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

// NOTE:
//   The ACE_Log_Msg_UNIX_Syslog class can use the openlog(),
//   setlogmask(), syslog() and closelog() routines in a thread safe
//   manner (versus using openlog_r(), et. al.), as the ACE_Log_Msg
//   class uses the lock provided by its local ACE_Log_Msg_Manager
//   class when calling the methods of the backend classes.  As a
//   result, logging semantics with respect to the UNIX syslog
//   facility, will be the same for all threads in a process.  This
//   should not be too limiting, as the ACE_Log_Msg class itself can
//   be used to control thread specific logging behavior.

ACE_Log_Msg_UNIX_Syslog::ACE_Log_Msg_UNIX_Syslog (void)
{
}

ACE_Log_Msg_UNIX_Syslog::~ACE_Log_Msg_UNIX_Syslog (void)
{
  (void) this->close ();
}

int
ACE_Log_Msg_UNIX_Syslog::open (const ACE_TCHAR * logger_key)
{
  if (logger_key == 0)
    logger_key = ACE_Log_Msg::program_name ();

  // Initialize the UNIX syslog facility.  Default the syslog log
  // options LOG_CONS and LOG_PID to be set.  There really should be a
  // logging strategy option to control the syslog log options,
  // however, we'll take the easy way out for now.
#if defined (ACE_USES_WCHAR)
  openlog (ACE_TEXT_ALWAYS_CHAR (logger_key),
           LOG_CONS|LOG_PID,
           ACE_DEFAULT_SYSLOG_FACILITY);
#else
  openlog (const_cast<char *> (logger_key),
           LOG_CONS|LOG_PID,
           ACE_DEFAULT_SYSLOG_FACILITY);
#endif /* ACE_USES_WCHAR */

  // Enable logging of all syslog priorities.  If logging of all
  // priorities is not desired, use the ACE_Log_Msg::priority_mask()
  // method to control the log output sent to the syslog daemon via
  // the log() method, or use the system's syslog.conf file to select
  // desired level of information.

#if !defined (ACE_LACKS_SETLOGMASK)
  (void) setlogmask (LOG_UPTO (LOG_DEBUG));
#endif /* ACE_LACKS_SETLOGMASK */

  return 0;
}

int
ACE_Log_Msg_UNIX_Syslog::reset (void)
{
  return this->close ();
}

int
ACE_Log_Msg_UNIX_Syslog::close (void)
{
  closelog();
  return 0;
}

ssize_t
ACE_Log_Msg_UNIX_Syslog::log (ACE_Log_Record &log_record)
{
  int syslog_priority = this->convert_log_priority (log_record.type ());
  u_long flags = ACE_LOG_MSG->flags ();

  // The UNIX syslog() facility does not support multi-line messages.
  // Break up the message data into separate lines and send each line
  // to the syslog daemon.

  ACE_TCHAR message[ACE_Log_Record::MAXVERBOSELOGMSGLEN];
  ACE_OS::strcpy (message, log_record.msg_data ());
  ACE_TCHAR *strtokp = 0;

  for (ACE_TCHAR *line = ACE_OS::strtok_r (message,
                                           ACE_TEXT ("\n"),
                                           &strtokp);
       line != 0;
       line = ACE_OS::strtok_r (0,
                                ACE_TEXT ("\n"),
                                &strtokp))
    {
      // Format the message line.  Note that the processing for
      // VERBOSE is the same as for VERBOSE_LITE, since syslog()
      // already provides us with the hostname and PID.  However, the
      // timestamp is duplicated (albeit a shortened version) to
      // provide a timestamp with greater precision than that provided
      // by syslog().
      if (ACE_BIT_ENABLED (flags, ACE_Log_Msg::VERBOSE)
          || ACE_BIT_ENABLED (flags, ACE_Log_Msg::VERBOSE_LITE))
        {
          ACE_TCHAR date_and_time[27];
          if (0 == ACE::timestamp (date_and_time, sizeof (date_and_time), 1))
            ACE_OS::strcpy (date_and_time, ACE_TEXT ("<time error>"));
          const ACE_TCHAR *prio_name =
            ACE_Log_Record::priority_name(ACE_Log_Priority(log_record.type()));
          syslog (syslog_priority,
                  "%s: %s: %s",
                  ACE_TEXT_ALWAYS_CHAR (date_and_time),
                  ACE_TEXT_ALWAYS_CHAR (prio_name),
                  ACE_TEXT_ALWAYS_CHAR (line));
        }
      else // No formatting required.
        syslog (syslog_priority, "%s", ACE_TEXT_ALWAYS_CHAR (line));
    }

  return 0;
}

int
ACE_Log_Msg_UNIX_Syslog::convert_log_priority (ACE_UINT32 lm_priority)
{
  int syslog_priority;
  switch (lm_priority)
  {
  case LM_TRACE:
  case LM_DEBUG:
    syslog_priority = LOG_DEBUG;
    break;
  case LM_STARTUP:
  case LM_SHUTDOWN:
  case LM_INFO:
    syslog_priority = LOG_INFO;
    break;
  case LM_NOTICE:
    syslog_priority = LOG_NOTICE;
    break;
  case LM_WARNING:
    syslog_priority = LOG_WARNING;
    break;
  case LM_CRITICAL:
    syslog_priority = LOG_CRIT;
    break;
  case LM_ALERT:
    syslog_priority = LOG_ALERT;
    break;
  case LM_EMERGENCY:
    syslog_priority = LOG_EMERG;
    break;
  case LM_ERROR:
  default:
    syslog_priority = LOG_ERR;
    break;
  }

  return syslog_priority;
}

int
ACE_Log_Msg_UNIX_Syslog::convert_log_mask (int lm_mask)
{
  int syslog_mask = 0;

  if (ACE_BIT_ENABLED (lm_mask, LM_TRACE)
      || ACE_BIT_ENABLED (lm_mask, LM_DEBUG))
    ACE_SET_BITS (syslog_mask, LOG_MASK(LOG_DEBUG));

  if (ACE_BIT_ENABLED (lm_mask, LM_STARTUP)
      || ACE_BIT_ENABLED (lm_mask, LM_SHUTDOWN)
      || ACE_BIT_ENABLED (lm_mask, LM_INFO))
    ACE_SET_BITS (syslog_mask, LOG_MASK(LOG_INFO));

  if (ACE_BIT_ENABLED (lm_mask, LM_NOTICE))
    ACE_SET_BITS (syslog_mask, LOG_MASK(LOG_NOTICE));

  if (ACE_BIT_ENABLED (lm_mask, LM_ERROR))
    ACE_SET_BITS (syslog_mask, LOG_MASK(LOG_ERR));

  if (ACE_BIT_ENABLED (lm_mask, LM_WARNING))
    ACE_SET_BITS (syslog_mask, LOG_MASK(LOG_WARNING));

  if (ACE_BIT_ENABLED (lm_mask, LM_CRITICAL))
    ACE_SET_BITS (syslog_mask, LOG_MASK(LOG_CRIT));

  if (ACE_BIT_ENABLED (lm_mask, LM_ALERT))
    ACE_SET_BITS (syslog_mask, LOG_MASK(LOG_ALERT));

  if (ACE_BIT_ENABLED (lm_mask, LM_EMERGENCY))
    ACE_SET_BITS (syslog_mask, LOG_MASK(LOG_EMERG));

  return syslog_mask;
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* !ACE_LACKS_UNIX_SYSLOG */
