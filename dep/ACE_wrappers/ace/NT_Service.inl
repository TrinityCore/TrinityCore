// -*- C++ -*-
//
// $Id: NT_Service.inl 80826 2008-03-04 14:51:23Z wotte $
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
ACE_INLINE
ACE_NT_Service::ACE_NT_Service (DWORD start_timeout,
                                DWORD service_type,
                                DWORD controls_mask) :
                                 start_time_(start_timeout),
                                 svc_handle_(0),
                                 svc_sc_handle_(0),
                                 name_(0),
                                 desc_(0),
                                 host_(0)
{
  svc_status_.dwServiceType = service_type;
  svc_status_.dwCurrentState = 0;
  svc_status_.dwControlsAccepted = controls_mask;
  svc_status_.dwWin32ExitCode = NO_ERROR;
  svc_status_.dwServiceSpecificExitCode = 0;
  svc_status_.dwCheckPoint = 0;
  svc_status_.dwWaitHint = 0;
}

ACE_INLINE
ACE_NT_Service::ACE_NT_Service (const ACE_TCHAR *name,
                                const ACE_TCHAR *desc,
                                DWORD start_timeout,
                                DWORD service_type,
                                DWORD controls_mask) :
                                 start_time_(start_timeout),
                                 svc_handle_(0),
                                 svc_sc_handle_(0),
                                 name_(ACE::strnew(name)),
                                 desc_(ACE::strnew(desc)),
                                 host_(0)
{
  svc_status_.dwServiceType = service_type;
  svc_status_.dwCurrentState = 0;
  svc_status_.dwControlsAccepted = controls_mask;
  svc_status_.dwWin32ExitCode = NO_ERROR;
  svc_status_.dwServiceSpecificExitCode = 0;
  svc_status_.dwCheckPoint = 0;
}

ACE_INLINE int
ACE_NT_Service::svc (void)
{
  return -1;
}

ACE_INLINE
const ACE_TCHAR *
ACE_NT_Service::name (void) const
{
  return name_;
}
ACE_INLINE
const ACE_TCHAR *
ACE_NT_Service::desc (void) const
{
  return desc_;
}
ACE_INLINE
const ACE_TCHAR *
ACE_NT_Service::host (void) const
{
  return host_;
}
ACE_INLINE void
ACE_NT_Service::svc_handle(const SERVICE_STATUS_HANDLE new_svc_handle)
{
  this->svc_handle_ = new_svc_handle;
  return;
}
ACE_END_VERSIONED_NAMESPACE_DECL
