// $Id: NT_Service.cpp 81862 2008-06-09 10:41:41Z sma $

#include "ace/config-all.h"
#if defined (ACE_WIN32) && !defined (ACE_LACKS_WIN32_SERVICES)

#include "ace/NT_Service.h"

#if !defined (__ACE_INLINE__)
#include "ace/NT_Service.inl"
#endif /* __ACE_INLINE__ */

#include "ace/Log_Msg.h"
#include "ace/Service_Object.h"
#include "ace/OS_NS_errno.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_ALLOC_HOOK_DEFINE(ACE_NT_Service)

// ACE_NT_Service destructor.

ACE_NT_Service::~ACE_NT_Service (void)
{
  if (this->svc_sc_handle_ != 0)
    {
      CloseServiceHandle (this->svc_sc_handle_);
      this->svc_sc_handle_ = 0;
    }
  delete [] this->desc_;
  delete [] this->name_;
  delete [] this->host_;
}

// This default implementation of ACE_NT_Service::open sets the
// service's status to START_PENDING with the estimated time until
// STARTED set to the value given when this object was constructed.
// Then the svc function is called, which implements the guts of the
// service.  Note that this function is running in a thread created by
// the OS, not by ACE_Thread_Manager.  The thread manager does not
// know anything about this thread.  The service can, however, use
// ACE_Thread_Manager to start more threads if desired.  When the svc
// function returns, the service status is set to STOPPED, and exit
// codes set based on errno/GetLastError if the svc function returns
// -1.
//
// The svc function is expected to set the service status to SERVICE_RUNNING
// after it initializes.
//
// The handle_control function will be called for each time there is a
// request for the service.  It is up to that function and svc to
// cooperate to both respond appropriately to the request (by at least
// updating the service's status) and to fulfill the request.

int
ACE_NT_Service::open (void *args)
{
  ACE_UNUSED_ARG (args);
  this->report_status (SERVICE_START_PENDING, 0);

  int svc_return = this->svc ();
  if (svc_return == 0)
    {
      this->svc_status_.dwWin32ExitCode = NO_ERROR;
      this->svc_status_.dwServiceSpecificExitCode = 0;
    }
  else
    {
      if (errno == 0)
        {
          this->svc_status_.dwWin32ExitCode = GetLastError ();
        }
      else
        {
          this->svc_status_.dwWin32ExitCode = ERROR_SERVICE_SPECIFIC_ERROR;
          this->svc_status_.dwServiceSpecificExitCode = errno;
        }
    }

  return svc_return;

}

int
ACE_NT_Service::fini (void)
{
  return this->report_status (SERVICE_STOPPED, 0);
}

void
ACE_NT_Service::handle_control (DWORD control_code)
{
  switch (control_code)
    {
    case SERVICE_CONTROL_SHUTDOWN:
    case SERVICE_CONTROL_STOP:
      this->stop_requested (control_code);
      break;

    case SERVICE_CONTROL_PAUSE:
      this->pause_requested (control_code);
      break;

    case SERVICE_CONTROL_CONTINUE:
      this->continue_requested (control_code);
      break;

    case SERVICE_CONTROL_INTERROGATE:
      this->interrogate_requested (control_code);
      break;
    }
}

void
ACE_NT_Service::stop_requested (DWORD)
{
  this->report_status (SERVICE_STOP_PENDING);
  /* how to cancel? */
}

void
ACE_NT_Service::pause_requested (DWORD)
{
  this->report_status (SERVICE_PAUSE_PENDING);
  this->suspend ();
  this->report_status (SERVICE_PAUSED);
}

void
ACE_NT_Service::continue_requested (DWORD)
{
  this->report_status (SERVICE_CONTINUE_PENDING);
  this->resume ();
  this->report_status (SERVICE_RUNNING);
}

void
ACE_NT_Service::interrogate_requested (DWORD)
{
  this->report_status (0);
}

void
ACE_NT_Service::name (const ACE_TCHAR *name, const ACE_TCHAR *desc)
{
  delete [] this->desc_;
  delete [] this->name_;

  if (desc == 0)
    desc = name;

  this->name_ = ACE::strnew (name);
  this->desc_ = ACE::strnew (desc);
}

void
ACE_NT_Service::host (const ACE_TCHAR *host)
{
  delete [] this->host_;

  if (this->svc_sc_handle_ != 0)
    {
      CloseServiceHandle (this->svc_sc_handle_);
      this->svc_sc_handle_ = 0;
    }

  if (host == 0)
    {
      this->host_ = 0;
    }
  else
    {
      this->host_ = ACE::strnew (host);
    }
}

int
ACE_NT_Service::insert (DWORD start_type,
                        DWORD error_control,
                        const ACE_TCHAR *exe_path,
                        const ACE_TCHAR *group_name,
                        LPDWORD tag_id,
                        const ACE_TCHAR *dependencies,
                        const ACE_TCHAR *account_name,
                        const ACE_TCHAR *password,
                        DWORD desired_access)
{
  ACE_TCHAR this_exe[MAXPATHLEN + 2];

  // Insure ACE_OS::last_error finds GetLastError unless we set errno.
  errno = 0;

  if (exe_path == 0)
    {
      if (ACE_TEXT_GetModuleFileName (0, this_exe + 1, MAXPATHLEN) == 0)
        return -1;
      // Make sure that this_exe is quoted
      this_exe[0] = ACE_TEXT ('\"');
      ACE_OS::strcat (this_exe, ACE_TEXT ("\""));
      exe_path = this_exe;
    }

  SC_HANDLE sc_mgr = ACE_TEXT_OpenSCManager (this->host (),
                                             0,
                                             SC_MANAGER_ALL_ACCESS);
  if (sc_mgr == 0)
    return -1;

  SC_HANDLE sh = ACE_TEXT_CreateService (sc_mgr,
                                         this->name (),
                                         this->desc (),
                                         desired_access,
                                         this->svc_status_.dwServiceType,
                                         start_type,
                                         error_control,
                                         exe_path,
                                         group_name,
                                         tag_id,
                                         dependencies,
                                         account_name,
                                         password);
  // If there was an error, stash GetLastError before CloseServiceHandle
  // smashes it. ACE_OS::last_error will find the saved error value.
  if (sh == 0)
    ACE_OS::set_errno_to_last_error ();

  CloseServiceHandle (sc_mgr);

  if (sh == 0)
    return -1;

  if (this->svc_sc_handle_ != 0)
    CloseServiceHandle (this->svc_sc_handle_);
  this->svc_sc_handle_ = sh;

  return 0;

}

int
ACE_NT_Service::remove (void)
{
  if (this->svc_sc_handle () == 0)
    return -1;

  if (DeleteService (this->svc_sc_handle()) == 0
      && GetLastError () != ERROR_SERVICE_MARKED_FOR_DELETE)
    return -1;

  return 0;
}

// Sets the startup type for the service.  Returns -1 on error, 0 on
// success.
int
ACE_NT_Service::startup (DWORD startup)
{
  SC_HANDLE svc = this->svc_sc_handle ();
  if (svc == 0)
    return -1;

  BOOL ok =
    ChangeServiceConfig (svc,
                         (DWORD) SERVICE_NO_CHANGE,// No change to service type
                         startup,                  // New startup type
                         (DWORD) SERVICE_NO_CHANGE,// No change to error ctrl
                         0,                        // No change to pathname
                         0,                        // No change to load group
                         0,                        // No change to tag
                         0,                        // No change to dependencies
                         0, 0,                     // No change to acct/passwd
                         0);                       // No change to name

  return ok ? 0 : -1;
}

// Returns the current startup type.

DWORD
ACE_NT_Service::startup (void)
{
  // The query buffer will hold strings as well as the defined struct.
  // The string pointers in the struct point to other areas in the
  // passed memory area, so it has to be large enough to hold the
  // struct plus all the strings.
  char cfgbuff[1024];
  LPQUERY_SERVICE_CONFIG cfg;
  DWORD cfgsize, needed_size;

  SC_HANDLE svc = this->svc_sc_handle ();
  if (svc == 0)
  {
    // To distinguish this error from the QueryServiceConfig failure
    // below, return the DWORD equivalent of -2, rather than -1.
    return MAXDWORD - 1;
  }
  cfgsize = sizeof cfgbuff;
  cfg = (LPQUERY_SERVICE_CONFIG) cfgbuff;
  BOOL ok = QueryServiceConfig (svc, cfg, cfgsize, &needed_size);
  if (ok)
    return cfg->dwStartType;
  // Zero is a valid return value for QueryServiceConfig, so if
  // QueryServiceConfig fails, return the DWORD equivalent of -1.
  return MAXDWORD;

}

void
ACE_NT_Service::capture_log_msg_attributes (void)
{
  ACE_Log_Msg::init_hook (this->log_msg_attributes_);
}

void
ACE_NT_Service::inherit_log_msg_attributes (void)
{
  // There's no thread descriptor involved with a NT-started
  // thread, so the first arg is 0.
  ACE_Log_Msg::inherit_hook (0, this->log_msg_attributes_);
}

int
ACE_NT_Service::start_svc (ACE_Time_Value *wait_time,
                           DWORD *svc_state,
                           DWORD argc, const ACE_TCHAR **argv)
{
  SC_HANDLE svc = this->svc_sc_handle ();
  if (svc == 0)
    return -1;

  if (!ACE_TEXT_StartService (svc, argc, argv))
    return -1;

  this->wait_for_service_state (SERVICE_RUNNING, wait_time);
  if (svc_state != 0)
    *svc_state = this->svc_status_.dwCurrentState;

  return 0;
}

int
ACE_NT_Service::stop_svc (ACE_Time_Value *wait_time,
                          DWORD *svc_state)
{
  SC_HANDLE svc = this->svc_sc_handle ();
  if (svc == 0)
    return -1;

  if (!ControlService (svc,
                       SERVICE_CONTROL_STOP,
                       &this->svc_status_))
    return -1;

  this->wait_for_service_state (SERVICE_STOPPED,
                                wait_time);
  if (svc_state != 0)
    *svc_state = this->svc_status_.dwCurrentState;

  return 0;
}

int
ACE_NT_Service::pause_svc (ACE_Time_Value *wait_time,
                           DWORD *svc_state)
{
  SC_HANDLE svc = this->svc_sc_handle ();
  if (svc == 0)
    return -1;

  if (!ControlService (svc,
                       SERVICE_CONTROL_PAUSE,
                       &this->svc_status_))
    return -1;

  this->wait_for_service_state (SERVICE_PAUSED,
                                wait_time);
  if (svc_state != 0)
    *svc_state = this->svc_status_.dwCurrentState;

  return 0;
}

int
ACE_NT_Service::continue_svc (ACE_Time_Value *wait_time,
                              DWORD *svc_state)
{
  SC_HANDLE svc = this->svc_sc_handle ();
  if (svc == 0)
    return -1;

  if (!ControlService (svc,
                       SERVICE_CONTROL_CONTINUE,
                       &this->svc_status_))
    return -1;

  this->wait_for_service_state (SERVICE_RUNNING,
                                wait_time);
  if (svc_state != 0)
    *svc_state = this->svc_status_.dwCurrentState;

  return 0;
}

DWORD
ACE_NT_Service::state (ACE_Time_Value *wait_hint)
{
  DWORD curr_state;

  if (this->state (&curr_state,
                   wait_hint) == -1)
    return 0;
  return curr_state;
}

int
ACE_NT_Service::state (DWORD *pstate,
                       ACE_Time_Value *wait_hint)
{
  SC_HANDLE svc = this->svc_sc_handle ();

  if (svc == 0)
    return -1;

  // Need to create a temporary copy of this variable since the
  // QueryServiceStatus call will modify the setting depending on the
  // current state of the Service.  If the service is currently
  // STOPPED, the value will be cleared.
  DWORD controls_accepted = this->svc_status_.dwControlsAccepted;

  if (QueryServiceStatus (svc,
                          &this->svc_status_) == 0)
    return -1;

  if (wait_hint != 0)
    wait_hint->msec (static_cast<long> (this->svc_status_.dwWaitHint));

  *pstate = this->svc_status_.dwCurrentState;
  this->svc_status_.dwControlsAccepted = controls_accepted;
  return 0;
}

// test_access
//
// Open a new handle, ignoring any handle open in svc_sc_handle_.
// This function's results are returned without leaving the handle
// open.

int
ACE_NT_Service::test_access (DWORD desired_access)
{
  int status = -1;     // Guilty until proven innocent

  SC_HANDLE sc_mgr = ACE_TEXT_OpenSCManager (this->host (),
                                             0,
                                             GENERIC_READ);
  if (sc_mgr != 0)
    {
      SC_HANDLE handle = ACE_TEXT_OpenService (sc_mgr,
                                               this->name (),
                                               desired_access);
      CloseServiceHandle (sc_mgr);
      if (handle != 0)
        {
          status = 0;
          CloseServiceHandle (handle);
        }
    }

  return status;
}

// report_status
//
// Reports the current status.  If new_status is not 0, it sets the
// status to the new value before reporting.  NOTE - this assumes that
// no actual service status values have the value 0.  This is true in
// WinNT 4.  If the status is a 'pending' type, the supplied time hint
// is used unless it's 0, in which case the existing hint is used.
// The dwWaitHint is not updated by this function.  The checkpoint is
// incremented by one after a pending report.

int
ACE_NT_Service::report_status (DWORD new_status,
                               DWORD time_hint)
{
  int bump_checkpoint = 0;
  int retval = 0;
  DWORD save_controls = 0;

  if (new_status != 0)
    this->svc_status_.dwCurrentState = new_status;
  switch (this->svc_status_.dwCurrentState)
    {
  case SERVICE_START_PENDING:
    save_controls = this->svc_status_.dwControlsAccepted;
    this->svc_status_.dwControlsAccepted = 0;
    /* Fall through */
  case SERVICE_STOP_PENDING:
  case SERVICE_CONTINUE_PENDING:
  case SERVICE_PAUSE_PENDING:
    this->svc_status_.dwWaitHint = time_hint ? time_hint : this->start_time_;
    bump_checkpoint = 1;
    break;

  default:
    this->svc_status_.dwCheckPoint = 0;
  }

  retval = SetServiceStatus (this->svc_handle_,
                             &this->svc_status_) ? 0 : -1;

  if (save_controls != 0)
    this->svc_status_.dwControlsAccepted = save_controls;

  if (bump_checkpoint)
    ++this->svc_status_.dwCheckPoint;

  return retval;
}

SC_HANDLE
ACE_NT_Service::svc_sc_handle (void)
{
  if (this->svc_sc_handle_ == 0)
    {
      SC_HANDLE sc_mgr = ACE_TEXT_OpenSCManager (this->host (),
                                                 0,
                                                 SC_MANAGER_ALL_ACCESS);
      if (sc_mgr != 0)
        {
          this->svc_sc_handle_ = ACE_TEXT_OpenService (sc_mgr,
                                                       this->name (),
                                                       SERVICE_ALL_ACCESS);
          if (this->svc_sc_handle_ == 0)
            ACE_OS::set_errno_to_last_error ();
          CloseServiceHandle (sc_mgr);
        }
      else
        ACE_OS::set_errno_to_last_error ();
    }

  return this->svc_sc_handle_;
}

void
ACE_NT_Service::wait_for_service_state (DWORD desired_state,
                                        ACE_Time_Value *wait_time)
{
  DWORD last_state = 0;
  DWORD last_check_point = 0;
  int first_time = 1;
  int service_ok;

  ACE_Time_Value time_out = ACE_OS::gettimeofday ();
  if (wait_time != 0)
    time_out += *wait_time;

  // Poll until the service reaches the desired state.
  for (;;)
    {
      service_ok = 0 != QueryServiceStatus (this->svc_sc_handle_,
                                            &this->svc_status_);

      // If we cannot query the service, we are done.
      if (!service_ok)
        break;

      // If the service has the desired state, we are done.
      if (desired_state == this->svc_status_.dwCurrentState)
        break;

      // If we time-out, we are done
      if (wait_time != 0 && ACE_OS::gettimeofday () > time_out )
        {
          errno = ETIME;
          break;
        }

      if (first_time)
        {
          // remember the service state, the first time we wait
          last_state       = this->svc_status_.dwCurrentState;
          last_check_point = this->svc_status_.dwCheckPoint;
          first_time = 0;
        }
      else
        {
          // update the state change.
          if (last_state != this->svc_status_.dwCurrentState)
            {
              last_state       = this->svc_status_.dwCurrentState;
              last_check_point = this->svc_status_.dwCheckPoint;
            }
          else
            {
              // The check-point should have increased
              if (this->svc_status_.dwCheckPoint > last_check_point)
                last_check_point = this->svc_status_.dwCheckPoint;
              else
                {
                  // Service control failure, we are done.
                  service_ok = 0;
                  break;
                }
            }
        }

      ::Sleep (this->svc_status_.dwWaitHint);
    }

  return;
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_WIN32 && !ACE_LACKS_WIN32_SERVICES */

