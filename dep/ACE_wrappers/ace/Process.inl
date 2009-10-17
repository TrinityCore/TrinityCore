// -*- C++ -*-
//
// $Id: Process.inl 80826 2008-03-04 14:51:23Z wotte $

#include "ace/ACE.h"
#include "ace/OS_NS_sys_wait.h"
#include "ace/OS_NS_signal.h"
#include "ace/OS_NS_pwd.h"
#include "ace/OS_NS_string.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

#if defined (ACE_WIN32)

ACE_INLINE PROCESS_INFORMATION
ACE_Process::process_info (void)
{
  return process_info_;
}
#endif /* ACE_WIN32 */

ACE_INLINE ACE_HANDLE
ACE_Process::gethandle (void) const
{
#if defined (ACE_WIN32)
  return process_info_.hProcess;
#else
  return ACE_HANDLE (child_id_);
#endif /* ACE_WIN32 */
}

ACE_INLINE pid_t
ACE_Process::getpid (void)
    const
{
#if defined (ACE_WIN32)
  return process_info_.dwProcessId;
#else /* ACE_WIN32 */
  return child_id_;
#endif /* ACE_WIN32 */
}

ACE_INLINE pid_t
ACE_Process::wait (ACE_exitcode *status,
                   int wait_options)
{
  pid_t retv =
    ACE_OS::wait (this->getpid (),
                  &this->exit_code_,
                  wait_options
#if defined (ACE_WIN32)
                  , process_info_.hProcess
#endif /* ACE_WIN32 */
                  );
  if (status != 0)
    *status = this->exit_code_;

  return retv;
}

ACE_INLINE int
ACE_Process::kill (int signum)
{
  if (this->getpid () != -1)
    return ACE_OS::kill (this->getpid (), signum);
  else
    return -1;
}

ACE_INLINE int
ACE_Process::terminate (void)
{
  if (this->getpid () != -1)
    return ACE::terminate_process (this->getpid ());
  else
    return -1;
}

ACE_INLINE int
ACE_Process::return_value (void) const
{
#if defined (ACE_WIN32)
  return this->exit_code_;
#else
  return WEXITSTATUS (this->exit_code_);
#endif /* ACE_WIN32 */
}

ACE_INLINE ACE_exitcode
ACE_Process::exit_code (void) const
{
  return this->exit_code_;
}

ACE_INLINE void
ACE_Process::exit_code (ACE_exitcode code)
{
  this->exit_code_ = code;
}

ACE_INLINE u_long
ACE_Process_Options::creation_flags (void) const
{
#if defined (ACE_USES_WCHAR) && defined (ACE_WIN32) && !defined (ACE_HAS_WINCE)
  return creation_flags_ | CREATE_UNICODE_ENVIRONMENT;
#else
  return creation_flags_;
#endif /* ACE_USES_WCHAR */
}

ACE_INLINE void
ACE_Process_Options::creation_flags (u_long cf)
{
  creation_flags_ = cf;
}

ACE_INLINE pid_t
ACE_Process_Options::getgroup (void) const
{
  return process_group_;
}

ACE_INLINE pid_t
ACE_Process_Options::setgroup (pid_t pgrp)
{
  pid_t old = process_group_;
  process_group_ = pgrp;
  return old;
}

ACE_INLINE int
ACE_Process_Options::handle_inheritence (void)
{
#if defined (ACE_WIN32) && !defined (ACE_HAS_WINCE)
  return handle_inheritence_;
#else
  ACE_NOTSUP_RETURN (0);  // This is a benign error.
#endif /* ACE_WIN32 && ! ACE_HAS_WINCE */
}

ACE_INLINE void
ACE_Process_Options::handle_inheritence (int hi)
{
#if defined (ACE_WIN32) &&  !defined (ACE_HAS_WINCE)
  handle_inheritence_ = hi;
#else
  ACE_UNUSED_ARG (hi);
  ACE_NOTSUP;
#endif /* !ACE_HAS_WINCE */
}

ACE_INLINE int
ACE_Process_Options::avoid_zombies (void)
{
  return avoid_zombies_;
}
ACE_INLINE void
ACE_Process_Options::avoid_zombies (int avoid_zombies)
{
  avoid_zombies_ = avoid_zombies;
}

#if defined (ACE_WIN32)

ACE_INLINE ACE_TEXT_STARTUPINFO *
ACE_Process_Options::startup_info (void)
{
#if !defined (ACE_HAS_WINCE)
  return &startup_info_;
#else
  return 0;
#endif /* !ACE_HAS_WINCE */
}

ACE_INLINE LPSECURITY_ATTRIBUTES
ACE_Process_Options::get_process_attributes (void) const
{
#if !defined (ACE_HAS_WINCE)
  return process_attributes_;
#else
  return 0;
#endif /* !ACE_HAS_WINCE */
}

ACE_INLINE LPSECURITY_ATTRIBUTES
ACE_Process_Options::set_process_attributes (void)
{
#if !defined (ACE_HAS_WINCE)
  process_attributes_ = &security_buf1_;
  return process_attributes_;
#else
  return 0;
#endif /* !ACE_HAS_WINCE */
}

ACE_INLINE LPSECURITY_ATTRIBUTES
ACE_Process_Options::get_thread_attributes (void) const
{
#if !defined (ACE_HAS_WINCE)
  return thread_attributes_;
#else
  return 0;
#endif /* !ACE_HAS_WINCE */
}

ACE_INLINE LPSECURITY_ATTRIBUTES
ACE_Process_Options::set_thread_attributes (void)
{
#if !defined (ACE_HAS_WINCE)
  thread_attributes_ = &security_buf2_;
  return thread_attributes_;
#else
  return 0;
#endif /* !ACE_HAS_WINCE */
}

#else /* !defined (ACE_WIN32) */

ACE_INLINE ACE_HANDLE
ACE_Process_Options::get_stdin (void) const
{
  return stdin_;
}

ACE_INLINE ACE_HANDLE
ACE_Process_Options::get_stdout (void) const
{
  return stdout_;
}

ACE_INLINE ACE_HANDLE
ACE_Process_Options::get_stderr (void) const
{
  return stderr_;
}

ACE_INLINE bool
ACE_Process_Options::inherit_environment (void) const
{
  return inherit_environment_;
}

ACE_INLINE void
ACE_Process_Options::inherit_environment (bool nv)
{
  inherit_environment_ = nv;
}

ACE_INLINE int
ACE_Process_Options::setreugid (const ACE_TCHAR* user)
{
#if !defined (ACE_LACKS_PWD_FUNCTIONS)
  struct passwd *ent = ACE_OS::getpwnam (ACE_TEXT_ALWAYS_CHAR (user));

  if (ent != 0)
    {
      this->euid_ = ent->pw_uid;
      this->ruid_ = ent->pw_uid;
      this->egid_ = ent->pw_gid;
      this->rgid_ = ent->pw_gid;
      return 0;
    }
  else
    return -1;
#else
  ACE_UNUSED_ARG (user);
  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_LACKS_PWD_FUNCTIONS */
}

ACE_INLINE void
ACE_Process_Options::setruid (uid_t id)
{
  this->ruid_ = id;
}

ACE_INLINE void
ACE_Process_Options::seteuid (uid_t id)
{
  this->euid_ = id;
}

ACE_INLINE void
ACE_Process_Options::setrgid (uid_t id)
{
  this->rgid_ = id;
}

ACE_INLINE void
ACE_Process_Options::setegid (uid_t id)
{
  this->egid_ = id;
}

ACE_INLINE uid_t
ACE_Process_Options::getruid (void) const
{
  return this->ruid_;
}

ACE_INLINE uid_t
ACE_Process_Options::geteuid (void) const
{
  return this->euid_;
}

ACE_INLINE uid_t
ACE_Process_Options::getrgid (void) const
{
  return this->rgid_;
}

ACE_INLINE uid_t
ACE_Process_Options::getegid (void) const
{
  return this->egid_;
}
#endif /* ACE_WIN32 */

ACE_INLINE ACE_TCHAR *
ACE_Process_Options::command_line_buf (int *max_lenp)
{
  if (max_lenp != 0)
    *max_lenp = this->command_line_buf_len_;
  return this->command_line_buf_;
}

ACE_INLINE ACE_TCHAR *
ACE_Process_Options::working_directory (void)
{
#if !defined (ACE_HAS_WINCE)
  if (working_directory_[0] == '\0')
    return 0;
  else
    return working_directory_;
#else
  return 0;
#endif /* !ACE_HAS_WINCE */
}

ACE_INLINE void
ACE_Process_Options::working_directory (const char *wd)
{
#if !defined(ACE_HAS_WINCE)
  ACE_OS::strcpy (working_directory_, ACE_TEXT_CHAR_TO_TCHAR (wd));
#else
  ACE_UNUSED_ARG (wd);
#endif /* !ACE_HAS_WINCE */
}

#if defined (ACE_HAS_WCHAR)
ACE_INLINE void
ACE_Process_Options::working_directory (const wchar_t *wd)
{
#if !defined(ACE_HAS_WINCE)
  ACE_OS::strcpy (working_directory_, ACE_TEXT_WCHAR_TO_TCHAR (wd));
#else
  ACE_UNUSED_ARG (wd);
#endif /* !ACE_HAS_WINCE */
}
#endif /* ACE_HAS_WCHAR */

ACE_INLINE void
ACE_Process_Options::process_name (const ACE_TCHAR *p)
{
  ACE_OS::strcpy (this->process_name_, p);
}

ACE_INLINE const ACE_TCHAR *
ACE_Process_Options::process_name (void)
{
  if (process_name_[0] == '\0')
    this->process_name (this->command_line_argv ()[0]);

  return this->process_name_;
}

#if defined (ACE_HAS_WINCE)
// Here is a collection of inline functions which are defined only
// under CE.  They are not empty on most other platforms.

ACE_INLINE int
ACE_Process_Options::setenv (ACE_TCHAR * /* envp */[])
{
  return -1;
}

ACE_INLINE int
ACE_Process_Options::setenv (const ACE_TCHAR * /* format */, ...)
{
  return -1;
}

ACE_INLINE int
ACE_Process_Options::setenv (const ACE_TCHAR * /* variable_name */,
                             const ACE_TCHAR * /* format */,
                             ...)
{
  return -1;
}

ACE_INLINE int
ACE_Process_Options::set_handles (ACE_HANDLE /* std_in */,
                                  ACE_HANDLE /* std_out */,
                                  ACE_HANDLE /* std_err */)
{
  return -1;
}

#endif /* ACE_HAS_WINCE */

ACE_END_VERSIONED_NAMESPACE_DECL
