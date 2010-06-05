// $Id: Process.cpp 82499 2008-08-04 20:01:17Z shuston $

#include "ace/Process.h"

#if !defined (__ACE_INLINE__)
#include "ace/Process.inl"
#endif /* __ACE_INLINE__ */

#include "ace/ARGV.h"
#include "ace/Auto_Ptr.h"
#include "ace/Signal.h"
#include "ace/SString.h"
#include "ace/Log_Msg.h"
#include "ace/OS_NS_stdio.h"
#include "ace/OS_NS_stdlib.h"
#include "ace/OS_NS_sys_socket.h"
#include "ace/OS_NS_errno.h"
#include "ace/OS_NS_string.h"
#include "ace/OS_NS_unistd.h"
#include "ace/OS_Memory.h"
#include "ace/Countdown_Time.h"
#include "ace/Truncate.h"
#include "ace/Vector_T.h"

#if defined (ACE_VXWORKS) && (ACE_VXWORKS > 0x600) && defined (__RTP__)
# include <rtpLib.h>
# include <taskLib.h>
#endif

ACE_RCSID (ace, Process, "$Id: Process.cpp 82499 2008-08-04 20:01:17Z shuston $")

// This function acts as a signal handler for SIGCHLD. We don't really want
// to do anything with the signal - it's just needed to interrupt a sleep.
// See wait() for more info.
#if !defined (ACE_WIN32) && !defined(ACE_LACKS_UNIX_SIGNALS)
static void
sigchld_nop (int, siginfo_t *, ucontext_t *)
{
  return;
}
#endif /* ACE_WIN32 */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_Process::ACE_Process (void)
  :
#if !defined (ACE_WIN32)
  child_id_ (ACE_INVALID_PID),
#endif /* !defined (ACE_WIN32) */
  exit_code_ (0)
{
#if defined (ACE_WIN32)
  ACE_OS::memset ((void *) &this->process_info_,
                  0,
                  sizeof this->process_info_);
#endif /* ACE_WIN32 */
}

ACE_Process::~ACE_Process (void)
{
#if defined (ACE_WIN32)
  // Free resources allocated in kernel.
  ACE_OS::close (this->process_info_.hThread);
  ACE_OS::close (this->process_info_.hProcess);
#endif /* ACE_WIN32 */
  // If any handles were duplicated for the child process and
  // still not closed, get them now.
  this->close_dup_handles ();
}

int
ACE_Process::prepare (ACE_Process_Options &)
{
  return 0;
}

pid_t
ACE_Process::spawn (ACE_Process_Options &options)
{
  if (this->prepare (options) < 0)
    return ACE_INVALID_PID;

  // Stash the passed/duped handle sets away in this object for later
  // closing if needed or requested. At the same time, figure out which
  // ones to include in command line options if that's needed below.
  ACE_Handle_Set *set_p = 0;
  if (options.dup_handles (this->dup_handles_))
    set_p = &this->dup_handles_;
  else if (options.passed_handles (this->handles_passed_))
    set_p = &this->handles_passed_;

  // If we are going to end up running a new program (i.e. Win32, or
  // NO_EXEC option is set) then get any handles passed in the options,
  // and tack them onto the command line with +H <handle> options,
  // unless the command line runs out of space.
  // Note that we're using the knowledge that all the options, argvs, etc.
  // passed to the options are all sitting in the command_line_buf. Any
  // call to get the argv then splits them out. So, regardless of the
  // platform, tack them all onto the command line buf and take it
  // from there.
  if (set_p && !ACE_BIT_ENABLED (options.creation_flags (),
                                 ACE_Process_Options::NO_EXEC))
    {
      int maxlen = 0;
      ACE_TCHAR *cmd_line_buf = options.command_line_buf (&maxlen);
      size_t max_len = static_cast<size_t> (maxlen);
      size_t curr_len = ACE_OS::strlen (cmd_line_buf);
      ACE_Handle_Set_Iterator h_iter (*set_p);
      // Because the length of the to-be-formatted +H option is not
      // known, and we don't have a snprintf, guess at the space
      // needed (20 chars), and use that as a limit.
      for (ACE_HANDLE h = h_iter ();
           h != ACE_INVALID_HANDLE && curr_len + 20 < max_len;
           h = h_iter ())
        {
#if defined (ACE_WIN32)
# if defined (ACE_WIN64)
          curr_len += ACE_OS::sprintf (&cmd_line_buf[curr_len],
                                       ACE_TEXT (" +H %I64p"),
                                       h);
# else
          curr_len += ACE_OS::sprintf (&cmd_line_buf[curr_len],
                                       ACE_TEXT (" +H %p"),
                                       h);
# endif  /* ACE_WIN64 */
#else
          curr_len += ACE_OS::sprintf (&cmd_line_buf[curr_len],
                                       ACE_TEXT (" +H %d"),
                                       h);
#endif /* ACE_WIN32 */
        }
    }

#if defined (ACE_HAS_WINCE)
  // Note that WinCE does not have process name included in the command line as argv[0]
  // like other OS environment.  Therefore, it is user's whole responsibility to call
  // 'ACE_Process_Options::process_name(const ACE_TCHAR *name)' to set the proper
  // process name (the execution file name with path if needed).

  BOOL fork_result =
    ACE_TEXT_CreateProcess (options.process_name(),
                            options.command_line_buf(),
                            options.get_process_attributes(),  // must be NULL in CE
                            options.get_thread_attributes(),   // must be NULL in CE
                            options.handle_inheritence(),      // must be false in CE
                            options.creation_flags(),          // must be NULL in CE
                            options.env_buf(),                 // environment variables, must be NULL in CE
                            options.working_directory(),       // must be NULL in CE
                            options.startup_info(),            // must be NULL in CE
                            &this->process_info_);

  if (fork_result)
    {
      parent (this->getpid ());
      return this->getpid ();
    }
  return ACE_INVALID_PID;

#elif defined (ACE_WIN32)
  void* env_buf = options.env_buf ();
  DWORD flags = options.creation_flags ();
# if defined (ACE_HAS_WCHAR) && !defined (ACE_USES_WCHAR)
  wchar_t* wenv_buf = 0;
  if (options.use_unicode_environment ())
    {
      wenv_buf = this->convert_env_buffer (options.env_buf ());
      env_buf = wenv_buf;
      flags |= CREATE_UNICODE_ENVIRONMENT;
    }
# endif

  BOOL fork_result =
    ACE_TEXT_CreateProcess (0,
                            options.command_line_buf (),
                            options.get_process_attributes (),
                            options.get_thread_attributes (),
                            options.handle_inheritence (),
                            flags,
                            env_buf, // environment variables
                            options.working_directory (),
                            options.startup_info (),
                            &this->process_info_);

# if defined (ACE_HAS_WCHAR) && !defined (ACE_USES_WCHAR)
  if (options.use_unicode_environment ())
    delete wenv_buf;
# endif

  if (fork_result)
    {
      parent (this->getpid ());
      return this->getpid ();
    }
  return ACE_INVALID_PID;

#elif defined(ACE_OPENVMS)
  if (ACE_BIT_ENABLED (options.creation_flags (),
                       ACE_Process_Options::NO_EXEC))
    ACE_NOTSUP_RETURN (ACE_INVALID_PID);

  int saved_stdin = ACE_STDIN;
  int saved_stdout = ACE_STDOUT;
  int saved_stderr = ACE_STDERR;
  // Save STD file descriptors and redirect
  if (options.get_stdin () != ACE_INVALID_HANDLE) {
    if ((saved_stdin = ACE_OS::dup (ACE_STDIN)) == -1 && errno != EBADF)
      ACE_OS::exit (errno);
    if (ACE_OS::dup2 (options.get_stdin (), ACE_STDIN) == -1)
      ACE_OS::exit (errno);
  }
  if (options.get_stdout () != ACE_INVALID_HANDLE) {
    if ((saved_stdout = ACE_OS::dup (ACE_STDOUT)) == -1 && errno != EBADF)
      ACE_OS::exit (errno);
    if (ACE_OS::dup2 (options.get_stdout (), ACE_STDOUT) == -1)
      ACE_OS::exit (errno);
  }
  if (options.get_stderr () != ACE_INVALID_HANDLE) {
    if ((saved_stderr = ACE_OS::dup (ACE_STDERR)) == -1 && errno != EBADF)
      ACE_OS::exit (errno);
    if (ACE_OS::dup2 (options.get_stderr (), ACE_STDERR) == -1)
      ACE_OS::exit (errno);
  }

  if (options.working_directory () != 0)
    ACE_NOTSUP_RETURN (ACE_INVALID_PID);

  this->child_id_ = vfork();
  if (this->child_id_ == 0) {
      ACE_OS::execvp (options.process_name (),
                options.command_line_argv ());
      // something went wrong
      this->child_id_ = ACE_INVALID_PID;
  }

  // restore STD file descriptors (if necessary)
  if (options.get_stdin () != ACE_INVALID_HANDLE) {
    if (saved_stdin == -1)
      ACE_OS::close (ACE_STDIN);
    else
      ACE_OS::dup2 (saved_stdin, ACE_STDIN);
  }
  if (options.get_stdout () != ACE_INVALID_HANDLE) {
    if (saved_stdout == -1)
      ACE_OS::close (ACE_STDOUT);
    else
      ACE_OS::dup2 (saved_stdout, ACE_STDOUT);
  }
  if (options.get_stderr () != ACE_INVALID_HANDLE) {
    if (saved_stderr == -1)
      ACE_OS::close (ACE_STDERR);
    else
      ACE_OS::dup2 (saved_stderr, ACE_STDERR);
  }

  return this->child_id_;
#elif (defined (ACE_VXWORKS) && (ACE_VXWORKS > 0x600)) && defined (__RTP__)
  if (ACE_BIT_ENABLED (options.creation_flags (),
                       ACE_Process_Options::NO_EXEC))
    ACE_NOTSUP_RETURN (ACE_INVALID_PID);

  if (options.working_directory () != 0)
    ACE_NOTSUP_RETURN (ACE_INVALID_PID);

  int saved_stdin = ACE_STDIN;
  int saved_stdout = ACE_STDOUT;
  int saved_stderr = ACE_STDERR;
  // Save STD file descriptors and redirect
  if (options.get_stdin () != ACE_INVALID_HANDLE) {
    if ((saved_stdin = ACE_OS::dup (ACE_STDIN)) == -1 && errno != EBADF)
      ACE_OS::exit (errno);
    if (ACE_OS::dup2 (options.get_stdin (), ACE_STDIN) == -1)
      ACE_OS::exit (errno);
  }
  if (options.get_stdout () != ACE_INVALID_HANDLE) {
    if ((saved_stdout = ACE_OS::dup (ACE_STDOUT)) == -1 && errno != EBADF)
      ACE_OS::exit (errno);
    if (ACE_OS::dup2 (options.get_stdout (), ACE_STDOUT) == -1)
      ACE_OS::exit (errno);
  }
  if (options.get_stderr () != ACE_INVALID_HANDLE) {
    if ((saved_stderr = ACE_OS::dup (ACE_STDERR)) == -1 && errno != EBADF)
      ACE_OS::exit (errno);
    if (ACE_OS::dup2 (options.get_stderr (), ACE_STDERR) == -1)
      ACE_OS::exit (errno);
  }

  // Wide-char builds need narrow-char strings for commandline and
  // environment variables.
# if defined (ACE_USES_WCHAR)
  wchar_t * const *wargv = options.command_line_argv ();
  size_t vcount, i;
  for (vcount = 0; wargv[vcount] != 0; ++vcount)
    ;
  char **procargv = new char *[vcount + 1];  // Need 0 at the end
  procargv[vcount] = 0;
  for (i = 0; i < vcount; ++i)
    procargv[i] = ACE_Wide_To_Ascii::convert (wargv[i]);

  char **procenv = 0;
  if (options.inherit_environment ())
    {
      wargv = options.env_argv ();
      for (vcount = 0; wargv[vcount] != 0; ++vcount)
        ;
      procenv = new char *[vcount + 1];  // Need 0 at the end
      procenv[vcount] = 0;
      for (i = 0; i < vcount; ++i)
        procenv[i] = ACE_Wide_To_Ascii::convert (wargv[i]);
    }
# else
  const char **procargv = const_cast<const char**> (options.command_line_argv ());
  const char **procenv = const_cast<const char**> (options.env_argv ());
# endif /* ACE_USES_WCHAR */

  this->child_id_ = ::rtpSpawn (procargv[0],
                                procargv,
                                procenv,
                                200,          // priority
                                0x10000,      // uStackSize
                                0,            // options
                                VX_FP_TASK);  // taskOptions
  int my_errno_ = errno;
  if (this->child_id_ == ERROR) {
      // something went wrong
      this->child_id_ = ACE_INVALID_PID;
  }

# if defined (ACE_USES_WCHAR)
  if (procenv)
    delete procenv;
# endif /* ACE_USES_WCHAR */

  // restore STD file descriptors (if necessary)
  if (options.get_stdin () != ACE_INVALID_HANDLE) {
    if (saved_stdin == -1)
      ACE_OS::close (ACE_STDIN);
    else
      ACE_OS::dup2 (saved_stdin, ACE_STDIN);
  }
  if (options.get_stdout () != ACE_INVALID_HANDLE) {
    if (saved_stdout == -1)
      ACE_OS::close (ACE_STDOUT);
    else
      ACE_OS::dup2 (saved_stdout, ACE_STDOUT);
  }
  if (options.get_stderr () != ACE_INVALID_HANDLE) {
    if (saved_stderr == -1)
      ACE_OS::close (ACE_STDERR);
    else
      ACE_OS::dup2 (saved_stderr, ACE_STDERR);
  }

  if (this->child_id_ == ACE_INVALID_PID)
    {
      errno = my_errno_;
    }

  return this->child_id_;
#else /* ACE_WIN32 */
  // Fork the new process.
  this->child_id_ = ACE::fork (options.process_name (),
                               options.avoid_zombies ());

  if (this->child_id_ == 0)
    {
# if !defined (ACE_LACKS_SETPGID)
      // If we're the child and the options specified a non-default
      // process group, try to set our pgid to it.  This allows the
      // <ACE_Process_Manager> to wait for processes by their
      // process-group.
      if (options.getgroup () != ACE_INVALID_PID
          && ACE_OS::setpgid (0,
                              options.getgroup ()) < 0)
        {
#if !defined (ACE_HAS_THREADS)
          // We can't emit this log message because ACE_ERROR(), etc.
          // will invoke async signal unsafe functions, which results
          // in undefined behavior in threaded programs.
          ACE_ERROR ((LM_ERROR,
                      ACE_TEXT ("%p.\n"),
                      ACE_TEXT ("ACE_Process::spawn: setpgid failed.")));
#endif
        }
# endif /* ACE_LACKS_SETPGID */

# if !defined (ACE_LACKS_SETREGID)
      if (options.getrgid () != (uid_t) -1
          || options.getegid () != (uid_t) -1)
        if (ACE_OS::setregid (options.getrgid (),
                              options.getegid ()) == -1)
          {
#if !defined (ACE_HAS_THREADS)
            // We can't emit this log message because ACE_ERROR(), etc.
            // will invoke async signal unsafe functions, which results
            // in undefined behavior in threaded programs.
            ACE_ERROR ((LM_ERROR,
                        ACE_TEXT ("%p.\n"),
                        ACE_TEXT ("ACE_Process::spawn: setregid failed.")));
#endif
          }
# endif /* ACE_LACKS_SETREGID */

# if !defined (ACE_LACKS_SETREUID)
      // Set user and group id's.
      if (options.getruid () != (uid_t) -1
          || options.geteuid () != (uid_t) -1)
        if (ACE_OS::setreuid (options.getruid (),
                              options.geteuid ()) == -1)
          {
#if !defined (ACE_HAS_THREADS)
            // We can't emit this log message because ACE_ERROR(), etc.
            // will invoke async signal unsafe functions, which results
            // in undefined behavior in threaded programs.
            ACE_ERROR ((LM_ERROR,
                        ACE_TEXT ("%p.\n"),
                        ACE_TEXT ("ACE_Process::spawn: setreuid failed.")));
#endif
          }
# endif /* ACE_LACKS_SETREUID */

      this->child (ACE_OS::getppid ());
    }
  else if (this->child_id_ != -1)
    this->parent (this->child_id_);

  // If we're not supposed to exec, return the process id.
  if (ACE_BIT_ENABLED (options.creation_flags (),
                       ACE_Process_Options::NO_EXEC))
    return this->child_id_;

  switch (this->child_id_)
    {
    case -1:
      // Error.
      return ACE_INVALID_PID;
    case 0:
      // Child process...exec the
      {
        if (options.get_stdin () != ACE_INVALID_HANDLE
            && ACE_OS::dup2 (options.get_stdin (),
                             ACE_STDIN) == -1)
          ACE_OS::exit (errno);
        else if (options.get_stdout () != ACE_INVALID_HANDLE
                 && ACE_OS::dup2 (options.get_stdout (),
                                  ACE_STDOUT) == -1)
          ACE_OS::exit (errno);
        else if (options.get_stderr () != ACE_INVALID_HANDLE
                 && ACE_OS::dup2 (options.get_stderr (),
                                  ACE_STDERR) == -1)
          ACE_OS::exit (errno);

        // close down unneeded descriptors
        ACE_OS::close (options.get_stdin ());
        ACE_OS::close (options.get_stdout ());
        ACE_OS::close (options.get_stderr ());

        // If we must, set the working directory for the child
        // process.
        if (options.working_directory () != 0)
          ACE_OS::chdir (options.working_directory ());
        // Should check for error here!

        // Child process executes the command.
        int result = 0;

        // Wide-char builds not on Windows need narrow-char strings for
        // exec() and environment variables. Don't need to worry about
        // releasing any of the converted string memory since this
        // process will either exec() or exit() shortly.
# if defined (ACE_USES_WCHAR)
        ACE_Wide_To_Ascii n_procname (options.process_name ());
        const char *procname = n_procname.char_rep ();

        wchar_t * const *wargv = options.command_line_argv ();
        size_t vcount, i;
        for (vcount = 0; wargv[vcount] != 0; ++vcount)
          ;
        char **procargv = new char *[vcount + 1];  // Need 0 at the end
        procargv[vcount] = 0;
        for (i = 0; i < vcount; ++i)
          procargv[i] = ACE_Wide_To_Ascii::convert (wargv[i]);

        wargv = options.env_argv ();
        for (vcount = 0; wargv[vcount] != 0; ++vcount)
          ;
        char **procenv = new char *[vcount + 1];  // Need 0 at the end
        procenv[vcount] = 0;
        for (i = 0; i < vcount; ++i)
          procenv[i] = ACE_Wide_To_Ascii::convert (wargv[i]);
# else
        const char *procname = options.process_name ();
        char *const *procargv = options.command_line_argv ();
        char *const *procenv = options.env_argv ();
# endif /* ACE_USES_WCHAR */

        if (options.inherit_environment ())
          {
            // Add the new environment variables to the environment
            // context of the context before doing an <execvp>.
            for (size_t i = 0; procenv[i] != 0; i++)
              if (ACE_OS::putenv (procenv[i]) != 0)
                return ACE_INVALID_PID;

            // Now the forked process has both inherited variables and
            // the user's supplied variables.
            result = ACE_OS::execvp (procname, procargv);
          }
        else
          {
# if defined (ghs)
            // GreenHills 1.8.8 (for VxWorks 5.3.x) can't compile this
            // code.  Processes aren't supported on VxWorks anyways.
            ACE_NOTSUP_RETURN (ACE_INVALID_PID);
# else
            result = ACE_OS::execve (procname, procargv, procenv);
# endif /* ghs */
          }
        if (result == -1)
          {
            // If the execv fails, this child needs to exit.

            // Exit with the errno so that the calling process can
            // catch this and figure out what went wrong.
            ACE_OS::_exit (errno);
          }
        // ... otherwise, this is never reached.
        return 0;
      }
    default:
      // Server process.  The fork succeeded.
      return this->child_id_;
    }
#endif /* ACE_WIN32 */
}

void
ACE_Process::parent (pid_t)
{
  // nothing to do
}

void
ACE_Process::child (pid_t)
{
  // nothing to do
}

void
ACE_Process::unmanage (void)
{
  // nothing to do
}

int
ACE_Process::running (void) const
{
#if defined (ACE_WIN32)
    DWORD code;

    BOOL result = ::GetExitCodeProcess (this->gethandle (),
                                        &code);
    return result && code == STILL_ACTIVE;
#else
  if (ACE_INVALID_PID == this->getpid ())
    return 0;
  else
    return ACE_OS::kill (this->getpid (),
                         0) == 0
      || errno != ESRCH;
#endif /* ACE_WIN32 */
}

pid_t
ACE_Process::wait (const ACE_Time_Value &tv,
                   ACE_exitcode *status)
{
#if defined (ACE_WIN32)
  // Don't try to get the process exit status if wait failed so we can
  // keep the original error code intact.
  switch (::WaitForSingleObject (process_info_.hProcess,
                                 tv.msec ()))
    {
    case WAIT_OBJECT_0:
        // The error status of <GetExitCodeProcess> is nonetheless not
        // tested because we don't know how to return the value.
        ::GetExitCodeProcess (process_info_.hProcess,
                              &this->exit_code_);
      if (status != 0)
        *status = this->exit_code_;
      return this->getpid ();
    case WAIT_TIMEOUT:
      errno = ETIME;
      return 0;
    default:
      ACE_OS::set_errno_to_last_error ();
      return -1;
    }
#elif defined(ACE_LACKS_UNIX_SIGNALS)
  if (tv == ACE_Time_Value::zero)
    {
      pid_t retv =
        ACE_OS::waitpid (this->child_id_,
                         &this->exit_code_,
                         WNOHANG);
      if (status != 0)
        *status = this->exit_code_;

      return retv;
    }

  if (tv == ACE_Time_Value::max_time)
# if defined (ACE_VXWORKS)
    {
      pid_t retv;
      while ( (retv = this->wait (status)) == ACE_INVALID_PID && errno == EINTR ) ;
      return retv;
    }
# else
     return this->wait (status);
# endif

  pid_t pid = 0;
  ACE_Time_Value sleeptm (1);    // 1 msec
  if (sleeptm > tv)              // if sleeptime > waittime
      sleeptm = tv;
  ACE_Time_Value tmo (tv);       // Need one we can change
  for (ACE_Countdown_Time time_left (&tmo); tmo > ACE_Time_Value::zero ; time_left.update ())
    {
      pid = ACE_OS::waitpid (this->getpid (),
                             &this->exit_code_,
                             WNOHANG);
      if (status != 0)
        *status = this->exit_code_;

      if (pid > 0 || pid == ACE_INVALID_PID)
        break;          // Got a child or an error - all done

      // pid 0, nothing is ready yet, so wait.
      // Do a (very) short sleep (only this thread sleeps).
      ACE_OS::sleep (sleeptm);
    }

  return pid;
#else /* !ACE_WIN32 && !ACE_LACKS_UNIX_SIGNALS */
  if (tv == ACE_Time_Value::zero)
    {
      pid_t retv =
        ACE_OS::waitpid (this->child_id_,
                         &this->exit_code_,
                         WNOHANG);
      if (status != 0)
        *status = this->exit_code_;

      return retv;
    }

  if (tv == ACE_Time_Value::max_time)
    return this->wait (status);

  // Need to wait but limited to specified time.
  // Force generation of SIGCHLD, even though we don't want to
  // catch it - just need it to interrupt the sleep below.
  // If this object has a reactor set, assume it was given at
  // open(), and there's already a SIGCHLD action set, so no
  // action is needed here.
  ACE_Sig_Action old_action;
  ACE_Sig_Action do_sigchld ((ACE_SignalHandler)sigchld_nop);
  do_sigchld.register_action (SIGCHLD, &old_action);

  pid_t pid;
  ACE_Time_Value tmo (tv);       // Need one we can change
  for (ACE_Countdown_Time time_left (&tmo); ; time_left.update ())
    {
      pid = ACE_OS::waitpid (this->getpid (),
                             &this->exit_code_,
                             WNOHANG);
      if (status != 0)
        *status = this->exit_code_;

      if (pid > 0 || pid == ACE_INVALID_PID)
        break;          // Got a child or an error - all done

      // pid 0, nothing is ready yet, so wait.
      // Do a sleep (only this thread sleeps) til something
      // happens. This relies on SIGCHLD interrupting the sleep.
      // If SIGCHLD isn't delivered, we'll need to do something
      // with sigaction to force it.
      if (-1 == ACE_OS::sleep (tmo) && errno == EINTR)
        continue;
      // Timed out
      pid = 0;
      break;
    }

  // Restore the previous SIGCHLD action if it was changed.
  old_action.register_action (SIGCHLD);

  return pid;
#endif /* ACE_WIN32 */
}

void
ACE_Process::close_dup_handles (void)
{
  if (this->dup_handles_.num_set () > 0)
    {
      ACE_Handle_Set_Iterator h_iter (this->dup_handles_);
      for (ACE_HANDLE h = h_iter ();
           h != ACE_INVALID_HANDLE;
           h = h_iter ())
        ACE_OS::closesocket (h);
      this->dup_handles_.reset ();
    }
  return;
}

void
ACE_Process::close_passed_handles (void)
{
  if (this->handles_passed_.num_set () > 0)
    {
      ACE_Handle_Set_Iterator h_iter (this->handles_passed_);
      for (ACE_HANDLE h = h_iter ();
           h != ACE_INVALID_HANDLE;
           h = h_iter ())
        ACE_OS::closesocket (h);
      this->handles_passed_.reset ();
    }
  return;
}

#if defined (ACE_WIN32) && \
    defined (ACE_HAS_WCHAR) && !defined (ACE_USES_WCHAR) && \
    !defined (ACE_HAS_WINCE)
wchar_t*
ACE_Process::convert_env_buffer (const char* env) const
{
  // Total starts out at 1 due to the final block nul terminator
  size_t total = 1;

  // Convert each individual character string to the equivalent wide
  // character string.
  ACE_Vector<wchar_t*> buffer;
  size_t start = 0;
  size_t i = 0;
  while (true)
    {
      if (env[i] == '\0')
        {
          // Convert the char string to wchar_t
          wchar_t* str = ACE_Ascii_To_Wide::convert (env + start);

          // Add the length of the string plus the nul terminator
          total += ACE_OS::strlen (str) + 1;

          // Save it and set up for the next string
          buffer.push_back (str);
          start = ++i;
          if (env[start] == '\0')
            break;
        }
      else
        {
          i += ACE_OS::strlen (env + i);
        }
    }

  // Copy each string into the buffer leaving a nul terminator between
  // each string and adding a second nul terminator at the end
  start = 0;
  wchar_t* wenv = new wchar_t[total];
  size_t length = buffer.size ();
  for (i = 0; i < length; ++i)
    {
      ACE_OS::strcpy(wenv + start, buffer[i]);
      start += ACE_OS::strlen (buffer[i]) + 1;
      delete [] buffer[i];
    }
  wenv[start] = 0;
  return wenv;
}
#endif

ACE_Process_Options::ACE_Process_Options (bool inherit_environment,
                                          int command_line_buf_len,
                                          int env_buf_len,
                                          int max_env_args)
  :
#if !defined (ACE_HAS_WINCE)
    inherit_environment_ (inherit_environment),
#endif /* ACE_HAS_WINCE */
    creation_flags_ (0),
    avoid_zombies_ (0),
#if !defined (ACE_HAS_WINCE)
#if defined (ACE_WIN32)
    environment_inherited_ (0),
    handle_inheritence_ (TRUE),
    process_attributes_ (0),
    thread_attributes_ (0),
#else /* ACE_WIN32 */
    stdin_ (ACE_INVALID_HANDLE),
    stdout_ (ACE_INVALID_HANDLE),
    stderr_ (ACE_INVALID_HANDLE),
    ruid_ ((uid_t) -1),
    euid_ ((uid_t) -1),
    rgid_ ((uid_t) -1),
    egid_ ((uid_t) -1),
#endif /* ACE_WIN32 */
    set_handles_called_ (0),
    environment_buf_index_ (0),
    environment_argv_index_ (0),
    environment_buf_ (0),
    environment_buf_len_ (env_buf_len),
    max_environment_args_ (max_env_args),
    max_environ_argv_index_ (max_env_args - 1),
#endif /* !ACE_HAS_WINCE */
    command_line_argv_calculated_ (0),
    command_line_buf_ (0),
    command_line_copy_ (0),
    command_line_buf_len_ (command_line_buf_len),
    process_group_ (ACE_INVALID_PID),
    use_unicode_environment_ (false)
{
  ACE_NEW (command_line_buf_,
           ACE_TCHAR[command_line_buf_len]);
  command_line_buf_[0] = '\0';

#if !defined (ACE_HAS_WINCE)
  working_directory_[0] = '\0';
  ACE_NEW (environment_buf_,
           ACE_TCHAR[env_buf_len]);
  ACE_NEW (environment_argv_,
           ACE_TCHAR *[max_env_args]);
  environment_buf_[0] = '\0';
  environment_argv_[0] = 0;
  process_name_[0] = '\0';
#if defined (ACE_WIN32)
  ACE_OS::memset ((void *) &this->startup_info_,
                  0,
                  sizeof this->startup_info_);
  this->startup_info_.cb = sizeof this->startup_info_;
#endif /* ACE_WIN32 */
#endif /* !ACE_HAS_WINCE */
}

#if !defined (ACE_HAS_WINCE)
#if defined (ACE_WIN32)
void
ACE_Process_Options::inherit_environment (void)
{
  // Ensure only once execution.
  if (environment_inherited_)
    return;
  environment_inherited_ = 1;

  // Get the existing environment.
  ACE_TCHAR *existing_environment = 0;
#if defined (ACE_HAS_WCHAR) && !defined (ACE_USES_WCHAR)
  WCHAR *existing_wide_env = 0;
  ACE_Vector<char> temp_narrow_env;
  if (this->use_unicode_environment_)
    {
      existing_wide_env = ::GetEnvironmentStringsW ();
      for (WCHAR *iter = existing_wide_env; *iter; ++iter)
        {
          ACE_Wide_To_Ascii wta (iter);
          size_t len = ACE_OS::strlen (wta.char_rep ());
          size_t idx = temp_narrow_env.size ();
          temp_narrow_env.resize (idx + len + 1, 0);
          ACE_OS::strncpy (&temp_narrow_env[idx], wta.char_rep (), len);
          iter += len;
        }
      temp_narrow_env.push_back (0);
      existing_environment = &temp_narrow_env[0];
    }
  else
#endif
  existing_environment = ACE_OS::getenvstrings ();

  size_t slot = 0;

  while (existing_environment[slot] != '\0')
    {
      size_t len = ACE_OS::strlen (existing_environment + slot);

      // Add the string to our env buffer.
      if (this->setenv_i (existing_environment + slot, len) == -1)
        {
          ACE_ERROR ((LM_ERROR,
                      ACE_TEXT ("%p.\n"),
                      ACE_TEXT ("ACE_Process_Options::ACE_Process_Options")));
          break;
        }

      // Skip to the next word.
      slot += len + 1;
    }

#if defined (ACE_HAS_WCHAR) && !defined (ACE_USES_WCHAR)
  if (this->use_unicode_environment_)
    ::FreeEnvironmentStringsW (existing_wide_env);
  else
#endif
  ACE_TEXT_FreeEnvironmentStrings (existing_environment);
}

#else /* defined ACE_WIN32 */

ACE_TCHAR * const *
ACE_Process_Options::env_argv (void)
{
  return environment_argv_;
}

#endif /* ACE_WIN32 */

void
ACE_Process_Options::enable_unicode_environment (void)
{
  this->use_unicode_environment_ = true;
}

void
ACE_Process_Options::disable_unicode_environment (void)
{
  this->use_unicode_environment_ = false;
}

bool
ACE_Process_Options::use_unicode_environment (void) const
{
  return this->use_unicode_environment_;
}

int
ACE_Process_Options::setenv (ACE_TCHAR *envp[])
{
  int i = 0;
  while (envp[i])
    {
      if (this->setenv_i (envp[i],
                          ACE_OS::strlen (envp[i])) == -1)
        return -1;
      i++;
    }

#if defined (ACE_WIN32)
  if (inherit_environment_)
    this->inherit_environment ();
#endif /* ACE_WIN32 */

  return 0;
}

int
ACE_Process_Options::setenv (const ACE_TCHAR *format, ...)
{
  ACE_TCHAR stack_buf[DEFAULT_COMMAND_LINE_BUF_LEN];

  // Start varargs.
  va_list argp;
  va_start (argp, format);

  // Add the rest of the varargs.
  ACE_OS::vsprintf (stack_buf,
                    format,
                    argp);
  // End varargs.
  va_end (argp);

  // Append the string to are environment buffer.
  if (this->setenv_i (stack_buf,
                      ACE_OS::strlen (stack_buf)) == -1)
    return -1;

#if defined (ACE_WIN32)
  if (inherit_environment_)
    this->inherit_environment ();
#endif /* ACE_WIN32 */

  return 0;
}

int
ACE_Process_Options::setenv (const ACE_TCHAR *variable_name,
                             const ACE_TCHAR *format, ...)
{
  // To address the potential buffer overflow,
  // we now allocate the buffer on heap with a variable size.
  size_t const buflen = ACE_OS::strlen (variable_name) + ACE_OS::strlen (format) + 2;
  ACE_TCHAR *newformat = 0;
  ACE_NEW_RETURN (newformat, ACE_TCHAR[buflen], -1);
  ACE_Auto_Basic_Array_Ptr<ACE_TCHAR> safe_newformat (newformat);

  // Add in the variable name.
  ACE_OS::sprintf (safe_newformat.get (),
                   ACE_TEXT ("%s=%s"),
                   variable_name,
                   format);

  // Start varargs.
  va_list argp;
  va_start (argp, format);

  // Add the rest of the varargs.
  size_t tmp_buflen = DEFAULT_COMMAND_LINE_BUF_LEN > buflen
                      ? static_cast<size_t> (DEFAULT_COMMAND_LINE_BUF_LEN) : buflen;
  int retval = 0;

  ACE_TCHAR *stack_buf = 0;
  ACE_NEW_RETURN (stack_buf, ACE_TCHAR[tmp_buflen], -1);
  ACE_Auto_Basic_Array_Ptr<ACE_TCHAR> safe_stack_buf (stack_buf);

  do
    {
      retval = ACE_OS::vsnprintf (safe_stack_buf.get (), tmp_buflen, safe_newformat.get (), argp);
      if (retval > ACE_Utils::truncate_cast<int> (tmp_buflen))
        {
          tmp_buflen *= 2;
          ACE_NEW_RETURN (stack_buf, ACE_TCHAR[tmp_buflen], -1);
          safe_stack_buf.reset (stack_buf);
        }
      else
        break;
    }
  while (1);

  if (retval == -1)
    {
      // In case that vsnprintf is not supported,
      // e.g., LynxOS and VxWorks 5, we have to
      // fall back to vsprintf.
      if (errno == ENOTSUP)
        {
          // ALERT: Since we have to use vsprintf here, there is still a chance that
          // the stack_buf overflows, i.e., the length of the resulting string
          // can still possibly go beyond the allocated stack_buf.
          retval = ACE_OS::vsprintf (safe_stack_buf.get (), safe_newformat.get (), argp);
          if (retval == -1)
            // vsprintf is failed.
            return -1;
        }
      else
        // vsnprintf is failed.
        return -1;
    }

  // End varargs.
  va_end (argp);

  // Append the string to our environment buffer.
  if (this->setenv_i (safe_stack_buf.get (),
                      ACE_OS::strlen (safe_stack_buf.get ())) == -1)
    return -1;

#if defined (ACE_WIN32)
  if (inherit_environment_)
    this->inherit_environment ();
#endif /* ACE_WIN32 */

  return 0;
}

int
ACE_Process_Options::setenv_i (ACE_TCHAR *assignment,
                               size_t len)
{
  // Add one for the null char.
  ++len;

  // If environment larger than allocated buffer return. Also check to
  // make sure we have enough room.
  if (environment_argv_index_ == max_environ_argv_index_
      || (len + environment_buf_index_) >= environment_buf_len_)
    return -1;

  // Copy the new environment string.
  ACE_OS::memcpy (environment_buf_ + environment_buf_index_,
                  assignment,
                  len * sizeof (ACE_TCHAR));

  // Update the argv array.
  environment_argv_[environment_argv_index_++] =
    environment_buf_ + environment_buf_index_;
  environment_argv_[environment_argv_index_] = 0;

  // Update our index.
  environment_buf_index_ += len;

  // Make sure the buffer is null-terminated.
  environment_buf_[environment_buf_index_] = '\0';
  return 0;
}

int
ACE_Process_Options::set_handles (ACE_HANDLE std_in,
                                  ACE_HANDLE std_out,
                                  ACE_HANDLE std_err)
{
  this->set_handles_called_ = 1;
#if defined (ACE_WIN32)

  // Tell the new process to use our std handles.
  this->startup_info_.dwFlags = STARTF_USESTDHANDLES;

  if (std_in == ACE_INVALID_HANDLE)
    std_in = ACE_STDIN;
  if (std_out == ACE_INVALID_HANDLE)
    std_out = ACE_STDOUT;
  if (std_err == ACE_INVALID_HANDLE)
    std_err = ACE_STDERR;

  if (!::DuplicateHandle (::GetCurrentProcess (),
                          std_in,
                          ::GetCurrentProcess (),
                          &this->startup_info_.hStdInput,
                          0,
                          TRUE,
                          DUPLICATE_SAME_ACCESS))
    return -1;

  if (!::DuplicateHandle (::GetCurrentProcess (),
                          std_out,
                          ::GetCurrentProcess (),
                          &this->startup_info_.hStdOutput,
                          0,
                          TRUE,
                          DUPLICATE_SAME_ACCESS))
    return -1;

  if (!::DuplicateHandle (::GetCurrentProcess (),
                          std_err,
                          ::GetCurrentProcess (),
                          &this->startup_info_.hStdError,
                          0,
                          TRUE,
                          DUPLICATE_SAME_ACCESS))
    return -1;
#else /* ACE_WIN32 */
  this->stdin_ = ACE_OS::dup (std_in);
  this->stdout_ = ACE_OS::dup (std_out);
  this->stderr_ = ACE_OS::dup (std_err);
#endif /* ACE_WIN32 */

  return 0; // Success.
}

void
ACE_Process_Options::release_handles ()
{
  if (set_handles_called_)
    {
#if defined (ACE_WIN32)
      ACE_OS::close (startup_info_.hStdInput);
      ACE_OS::close (startup_info_.hStdOutput);
      ACE_OS::close (startup_info_.hStdError);
#else /* ACE_WIN32 */
      ACE_OS::close (stdin_);
      ACE_OS::close (stdout_);
      ACE_OS::close (stderr_);
#endif /* ACE_WIN32 */
      set_handles_called_ = 0;
    }
}
#endif /* !ACE_HAS_WINCE */

ACE_Process_Options::~ACE_Process_Options (void)
{
#if !defined (ACE_HAS_WINCE)
  release_handles();
  delete [] environment_buf_;
  delete [] environment_argv_;
#endif /* !ACE_HAS_WINCE */
  delete [] command_line_buf_;
  ACE::strdelete (command_line_copy_);
}

int
ACE_Process_Options::command_line (const ACE_TCHAR *const argv[])
{
  // @@ Factor out the code between this
  int i = 0;

  if (argv[i])
    {
      ACE_OS::strcat (command_line_buf_, argv[i]);
      while (argv[++i])
        {
          ACE_OS::strcat (command_line_buf_,
                          ACE_TEXT (" "));
          ACE_OS::strcat (command_line_buf_,
                          argv[i]);
        }
    }

  command_line_argv_calculated_ = 0;
  return 0; // Success.
}

int
ACE_Process_Options::command_line (const ACE_TCHAR *format, ...)
{
  // Store all ... args in argp.
  va_list argp;
  va_start (argp, format);

  if (command_line_buf_len_ < 1)
    return -1;

#if !defined (ACE_LACKS_VSNPRINTF) || defined (ACE_HAS_TRIO)
  // vsnprintf the format and args into command_line_buf__.
  ACE_OS::vsnprintf (command_line_buf_,
                     command_line_buf_len_,
                     format,
                     argp);
#else
  // sprintf the format and args into command_line_buf__.
  ACE_OS::vsprintf (command_line_buf_,
                    format,
                    argp);
#endif

  // Useless macro.
  va_end (argp);

  command_line_argv_calculated_ = 0;
  return 0;
}

#if defined (ACE_HAS_WCHAR) && !defined (ACE_HAS_WINCE)
/**
 * @note Not available on Windows CE because it doesn't have a char version of
 * vsprintf.
 */
int
ACE_Process_Options::command_line (const ACE_ANTI_TCHAR *format, ...)
{
  ACE_ANTI_TCHAR *anti_clb;
  ACE_NEW_RETURN (anti_clb,
                  ACE_ANTI_TCHAR[this->command_line_buf_len_],
                  -1);

  // Store all ... args in argp.
  va_list argp;
  va_start (argp, format);

  // sprintf the format and args into command_line_buf_.
  ACE_OS::vsprintf (anti_clb,
                    format,
                    argp);

  // Useless macro.
  va_end (argp);

  ACE_OS::strcpy (this->command_line_buf_,
                  ACE_TEXT_ANTI_TO_TCHAR (anti_clb));

  delete [] anti_clb;

  command_line_argv_calculated_ = 0;
  return 0;
}
#endif /* ACE_HAS_WCHAR && !ACE_HAS_WINCE */

ACE_TCHAR *
ACE_Process_Options::env_buf (void)
{
#if !defined (ACE_HAS_WINCE)
  if (environment_buf_[0] == '\0')
    return 0;
  else
    return environment_buf_;
#else
  return 0;
#endif /* !ACE_HAS_WINCE */
}

ACE_TCHAR * const *
ACE_Process_Options::command_line_argv (void)
{
  if (command_line_argv_calculated_ == 0)
    {
      command_line_argv_calculated_ = 1;

      // We need to free up any previous allocated memory first.
      ACE::strdelete (command_line_copy_);

      // We need to make a dynamically allocated copy here since
      // ACE_Tokenizer modifies its arguments.
      command_line_copy_ = ACE::strnew (command_line_buf_);
      // This tokenizer will replace all spaces with end-of-string
      // characters and will preserve text between "" and '' pairs.
      ACE_Tokenizer parser (command_line_copy_);
      parser.delimiter_replace (' ', '\0');
      parser.preserve_designators ('\"', '\"'); // "
      parser.preserve_designators ('\'', '\'');

      int x = 0;
      do
        command_line_argv_[x] = parser.next ();
      while (command_line_argv_[x] != 0
             // substract one for the ending zero.
             && ++x < MAX_COMMAND_LINE_OPTIONS - 1);

      command_line_argv_[x] = 0;
    }

  return command_line_argv_;
}

// Cause the specified handle to be passed to a child process
// when it's spawned.
int
ACE_Process_Options::pass_handle (ACE_HANDLE h)
{
# if defined (ACE_WIN32)
#  if defined (ACE_HAS_WINCE)
  ACE_NOTSUP_RETURN (-1);
#  else

  // This is oriented towards socket handles... may need some adjustment
  // for non-sockets.
  // This is all based on an MSDN article:
  // http://support.microsoft.com/support/kb/articles/Q150/5/23.asp
  // If on Win95/98, the handle needs to be duplicated for the to-be-spawned
  // process. On WinNT, they get inherited by the child process automatically.
  // If the handle is duplicated, remember the duplicate so it can be
  // closed later. Can't be closed now, or the child won't get it.
  ACE_TEXT_OSVERSIONINFO osvi;
  ZeroMemory (&osvi, sizeof (osvi));
  osvi.dwOSVersionInfoSize = sizeof (ACE_TEXT_OSVERSIONINFO);
  // If this is Win95/98 or we can't tell, duplicate the handle.
  if (!ACE_TEXT_GetVersionEx (&osvi) || osvi.dwPlatformId != VER_PLATFORM_WIN32_NT)
    {
      HANDLE dup_handle;
      if (!DuplicateHandle (GetCurrentProcess (),
                            static_cast<HANDLE> (h),
                            GetCurrentProcess (),
                            &dup_handle,
                            0,
                            TRUE,   // Inheritable
                            DUPLICATE_SAME_ACCESS))
        return -1;
      dup_handles_.set_bit (static_cast<ACE_HANDLE> (dup_handle));
    }
#  endif /* ACE_HAS_WINCE */
#endif /* ACE_WIN32 */

  this->handles_passed_.set_bit (h);

  return 0;
}

// Get a copy of the handles the ACE_Process_Options duplicated
// for the spawned process.
int
ACE_Process_Options::dup_handles (ACE_Handle_Set &set) const
{
  if (this->dup_handles_.num_set () == 0)
    return 0;
  set.reset ();
  set = this->dup_handles_;
  return 1;
}

// Get a copy of the handles passed to the spawned process. This
// will be the set of handles previously passed to @arg pass_handle().
int
ACE_Process_Options::passed_handles (ACE_Handle_Set &set) const
{
  if (this->handles_passed_.num_set () == 0)
    return 0;
  set.reset ();
  set = this->handles_passed_;
  return 1;
}

ACE_Managed_Process::~ACE_Managed_Process (void)
{
}

void
ACE_Managed_Process::unmanage (void)
{
  delete this;
}

ACE_END_VERSIONED_NAMESPACE_DECL

