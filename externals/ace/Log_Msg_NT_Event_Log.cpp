// $Id: Log_Msg_NT_Event_Log.cpp 87683 2009-11-20 18:14:36Z schmidt $

#include "ace/config-all.h"

#if defined (ACE_HAS_LOG_MSG_NT_EVENT_LOG)

#include "ace/Log_Msg_NT_Event_Log.h"
#include "ace/Log_Msg.h"
#include "ace/Log_Record.h"
#include "ace/OS_NS_stdio.h"
#include "ace/OS_NS_string.h"

ACE_RCSID(ace, Log_Msg_NT_Event_Log, "$Id: Log_Msg_NT_Event_Log.cpp 87683 2009-11-20 18:14:36Z schmidt $")

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_Log_Msg_NT_Event_Log::ACE_Log_Msg_NT_Event_Log (void)
  : evlog_handle_(0)
{
}

ACE_Log_Msg_NT_Event_Log::~ACE_Log_Msg_NT_Event_Log (void)
{
  this->close ();
}

int
ACE_Log_Msg_NT_Event_Log::open (const ACE_TCHAR *logger_key)
{
  // ACE's "resource module" contains the message resource required
  // for event logging.
  ACE_TCHAR msg_file [MAXPATHLEN];

  if (!ACE_TEXT_GetModuleFileName (ACE_OS::get_win32_resource_module (),
                                   msg_file,
                                   MAXPATHLEN))
    return -1;
  DWORD msg_file_length =
    static_cast<DWORD> ((ACE_OS::strlen (msg_file) + 1) * sizeof (ACE_TCHAR));

  // If a logger_key has been supplied then we use that as the event
  // source name, otherwise we default to the program name.
  const ACE_TCHAR *event_source_name = logger_key ? logger_key : ACE_Log_Msg::program_name ();

  // Information is stored in the registry at a location based on the
  // program name.
  ACE_TCHAR reg_key [MAXPATHLEN];
  ACE_OS::strcpy (reg_key,
                  ACE_TEXT ("SYSTEM\\CurrentControlSet\\Services\\EventLog\\Application\\"));
  size_t reg_key_length = ACE_OS::strlen(reg_key);
  ACE_OS::strncat (reg_key,
                   event_source_name,
                   MAXPATHLEN - reg_key_length);

  // Add the event source to the registry. Note that if this fails it
  // is not fatal. The application will still be able to write entries
  // to the event log, they just won't be formatted correctly.
  HKEY hkey;
  ACE_TEXT_RegCreateKey (HKEY_LOCAL_MACHINE,
                         reg_key,
                         &hkey);
  DWORD flags = EVENTLOG_ERROR_TYPE | EVENTLOG_WARNING_TYPE | EVENTLOG_INFORMATION_TYPE;
  ACE_TEXT_RegSetValueEx (hkey,
                          ACE_TEXT ("TypesSupported"),
                          0,
                          REG_DWORD,
                          (LPBYTE) &flags,
                          sizeof (DWORD));
  ACE_TEXT_RegSetValueEx (hkey,
                          ACE_TEXT ("EventMessageFile"),
                          0,
                          REG_SZ,
                          (LPBYTE) msg_file,
                          msg_file_length);
  RegCloseKey (hkey);

  // Obtain a handle to the event source.
  this->evlog_handle_ = ACE_TEXT_RegisterEventSource (0,
                                                      event_source_name);
  return this->evlog_handle_ ? 0 : -1;
}

int
ACE_Log_Msg_NT_Event_Log::reset (void)
{
  return this->close ();
}

int
ACE_Log_Msg_NT_Event_Log::close (void)
{
  if (this->evlog_handle_ == 0
      || DeregisterEventSource (this->evlog_handle_))
    {
      this->evlog_handle_ = 0;
      return 0;
    }
  else
    return -1;
}

ssize_t
ACE_Log_Msg_NT_Event_Log::log (ACE_Log_Record &log_record)
{
  // Make a copy of the log text and replace any newlines with
  // CR-LF. Newline characters on their own do not appear correctly in
  // the event viewer. We allow for a doubling in the size of the msg
  // data for the worst case of all newlines.
  const ACE_TCHAR *src_msg_data = log_record.msg_data ();
  ACE_TCHAR msg_data [(ACE_Log_Record::MAXLOGMSGLEN * 2) + 1];

  size_t maxlen = ACE_Log_Record::MAXLOGMSGLEN;
  if (ACE_Log_Record::MAXLOGMSGLEN > log_record.msg_data_len ())
    maxlen = log_record.msg_data_len ();

  size_t end = 0;
  for (size_t i = 0, j = 0;
       i < maxlen;
       ++i)
    {
      if (src_msg_data[i] == '\n')
        {
          msg_data[j++] = '\r';
          msg_data[j++] = '\n';
        }
      else
        msg_data[j++] = src_msg_data[i];

      end = j;
    }
  msg_data[end] = '\0';

  // Map the ACE log record type to an event log type.
  WORD event_type;
  switch (log_record.type ())
  {
  case LM_STARTUP:
  case LM_SHUTDOWN:
  case LM_TRACE:
  case LM_DEBUG:
  case LM_INFO:
    event_type = EVENTLOG_INFORMATION_TYPE;
    break;
  case LM_NOTICE:
  case LM_WARNING:
    event_type = EVENTLOG_WARNING_TYPE;
    break;
  case LM_ERROR:
  case LM_CRITICAL:
  case LM_ALERT:
  case LM_EMERGENCY:
  default:
    event_type = EVENTLOG_ERROR_TYPE;
    break;
  }

  // Send the log message to the system event log.
  const ACE_TCHAR* msgs [1];
  msgs[0] = msg_data;

  if (ACE_TEXT_ReportEvent (this->evlog_handle_,
                            event_type, 0, 0, 0, 1, 0, msgs, 0) == 0)
    return -1;
  else
    return 0;
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_HAS_LOG_MSG_NT_EVENT_LOG */
