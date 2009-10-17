// -*- C++ -*-
//=============================================================================
/**
 *  @file    Process.h
 *
 *  $Id: Process.h 82233 2008-07-01 22:49:26Z shuston $
 *
 *  @author Tim Harrison <harrison@cs.wustl.edu>
 */
//=============================================================================
#ifndef ACE_PROCESS_H
#define ACE_PROCESS_H
#include /**/ "ace/pre.h"
#include /**/ "ace/ACE_export.h"
#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */
#include "ace/Handle_Set.h"
#include "ace/Global_Macros.h"
#include "ace/os_include/sys/os_types.h"
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
// Forward declaration
class ACE_Time_Value;
/**
 * @class ACE_Process_Options
 *
 * @brief Process Options
 *
 * This class controls the options passed to <CreateProcess> (or <fork>
 * and <exec>).
 * Notice that on Windows CE, creating a process merely means
 * instantiating a new process.  You can't set the handles (since
 * there's no stdin, stdout and stderr,) specify process/thread
 * options, set environment,...  So, basically, this class only
 * set the command line and nothing else.
 * Notice that on UNIX platforms, if the <setenv> is used, the
 * <spawn> is using the <execve> system call. It means that the
 * <command_line> should include a full path to the program file
 * (<execve> does not search the PATH).  If <setenv> is not used
 * then, the <spawn> is using the <execvp> which searches for the
 * program file in the PATH variable.
 */
class ACE_Export ACE_Process_Options
{
public:
  enum
  {
    DEFAULT_COMMAND_LINE_BUF_LEN = 1024,
    // UNIX process creation flags.
#if defined (ACE_WIN32)
    NO_EXEC = 0
#else
    NO_EXEC = 1
#endif /* ACE_WIN32 */
  };
protected:
  // = Default settings not part of public Interface.
  //
  /// @todo These sizes should be taken from the appropriate
  /// POSIX/system header files and/or defined dynamically.
  enum
  {
    MAX_COMMAND_LINE_OPTIONS = 128,
    ENVIRONMENT_BUFFER = 16 * 1024, // 16K
    MAX_ENVIRONMENT_ARGS = 512 //
  };
public:
  /**
   * If @a inherit_environment == true, the new process will inherit the
   * environment of the current process.  @a command_line_buf_len is the
   * max strlen for command-line arguments.
   */
  ACE_Process_Options (bool inherit_environment = true,
                       int command_line_buf_len = DEFAULT_COMMAND_LINE_BUF_LEN,
                       int env_buf_len = ENVIRONMENT_BUFFER,
                       int max_env_args = MAX_ENVIRONMENT_ARGS);
  /// Destructor.
  ~ACE_Process_Options (void);
  // = Methods to set process creation options portably.
  /**
   * Set the standard handles of the new process to the respective
   * handles.  If you want to affect a subset of the handles, make
   * sure to set the others to ACE_INVALID_HANDLE.  Returns 0 on
   * success, -1 on failure.
   */
  int set_handles (ACE_HANDLE std_in,
                   ACE_HANDLE std_out = ACE_INVALID_HANDLE,
                   ACE_HANDLE std_err = ACE_INVALID_HANDLE);
  /// Release the standard handles previously set with set_handles;
  void release_handles (void);
  /// @param format must be of the form "VARIABLE=VALUE".  There can not be
  /// any spaces between VARIABLE and the equal sign.
  int setenv (const ACE_TCHAR *format,
              ...);
  /**
   * Set a single environment variable, @a variable_name.  Since
   * different platforms separate each environment variable
   * differently, you must call this method once for each variable.
   * <format> can be any printf format string.  So options->setenv
   * ("FOO","one + two = %s", "three") will result in "FOO=one + two =
   * three".
   */
  int setenv (const ACE_TCHAR *variable_name,
              const ACE_TCHAR *format,
              ...);
  /// Same as above with argv format.  @a envp must be null terminated.
  int setenv (ACE_TCHAR *envp[]);
  /// Set the working directory for the process.  strlen of @a wd must
  /// be <= MAXPATHLEN.
  void working_directory (const char *wd);
#if defined (ACE_HAS_WCHAR)
  /// wchar_t version of working_directory
  void working_directory (const wchar_t *wd);
#endif /* ACE_HAS_WCHAR */
  /**
   * Set the command-line arguments.  @a format can use any printf
   * formats.  The first token in @a format should be the path to the
   * application.  This can either be a full path, relative path, or
   * just an executable name.  If an executable name is used, we rely
   * on the platform's support for searching paths.  Since we need a
   * path to run a process, this method *must* be called!  Returns 0
   * on success, -1 on failure.
   */
  int command_line (const ACE_TCHAR *format, ...);
#if defined (ACE_HAS_WCHAR) && !defined (ACE_HAS_WINCE)
  /// Anti-TChar version of command_line ()
  int command_line (const ACE_ANTI_TCHAR *format, ...);
#endif /* ACE_HAS_WCHAR && !ACE_HAS_WINCE */
  /// Same as above in argv format.  @a argv must be null terminated.
  int command_line (const ACE_TCHAR * const argv[]);
  /**
   * Specify the full path or relative path, or just the executable
   * name for the process. If this is set, then @a name will be used to
   * create the process instead of argv[0] set in the command
   * line. This is here so that you can supply something other than
   * executable name as argv[0].
   */
  void process_name (const ACE_TCHAR *name);
  /// Return the process_name.  If the <process_name(name)> set
  /// method is not called, this method will return argv[0].
  const ACE_TCHAR *process_name (void);
  /// Get the creation flags.
  u_long creation_flags (void) const;
  /**
   * Set the creation flags to affect how a new process is spawned.
   * The only ACE-defined flag is @c NO_EXEC which prevents the new process
   * from executing a new program image; this is a simple POSIX fork().
   * The @c NO_EXEC option has no affect on Windows; on other platforms where
   * a POSIX fork is not possible, specifying @c NO_EXEC will cause
   * ACE_Process::spawn() to fail.
   *
   * On Windows, the value of creation_flags is passed to the @c CreateProcess
   * system call as the value of the @c dwCreationFlags parameter.
   */
  void creation_flags (u_long);
  /// Current working directory.  Returns "" if nothing has been set.
  ACE_TCHAR *working_directory (void);
  /// Buffer of command-line options.  Returns a pointer to a buffer that
  /// contains the list of command line options.  Prior to a call to
  /// command_line_argv(), this is a single string of space separated
  /// arguments independent of which form of command_line() was used to
  /// create it.  After a call to command_line_argv(), this is a list of
  /// strings each terminated by '\0'.  [Note: spawn() will call
  /// command_line_argv().]  The total length of all these strings is the
  /// same as the single string in the prior case and can be obtained by
  /// providing max_len. @arg max_len, if non-zero, provides a location
  /// into which the total length of the command line buffer is returned.
  ACE_TCHAR *command_line_buf (int *max_len = 0);
  /**
   * argv-style command-line options.  Parses and modifies the string
   * created from <command_line_>.  All spaces not in quotes ("" or
   * '') are replaced with null (\0) bytes.  An argv array is built
   * and returned with each entry pointing to the start of
   * null-terminated string.  Returns { 0 } if nothing has been set.
   */
  ACE_TCHAR * const *command_line_argv (void);
  /**
   * Null-terminated buffer of null terminated strings.  Each string
   * is an environment assignment "VARIABLE=value".  This buffer
   * should end with two null characters.
   */
  ACE_TCHAR *env_buf (void);
  /// Get the process group.  On UNIX, these methods are used by the
  /// ACE_Process_Manager to manage groups of processes.
  pid_t getgroup (void) const;
  /// Set the process group.  On UNIX, these methods are used by the
  /// ACE_Process_Manager to manage groups of processes.
  pid_t setgroup (pid_t pgrp);
  /// Allows disabling of handle inheritence, default is TRUE.
  int handle_inheritence (void);
  void handle_inheritence (int);
  /// Cause the specified handle to be passed to a child process
  /// when it runs a new program image.
  /**
   * The specified handle value will be included in the spawned
   * process's command line as @arg +H @arg handle, if a new
   * program is spawned (always on Win32; else if NO_EXEC is not
   * set in creation flags).  The passed handle value will be
   * duplicated if on Win32 less capable than NT.
   * @return 0 if success, -1 if failure.
   */
  int pass_handle (ACE_HANDLE);
  /// Get a copy of the handles the ACE_Process_Options duplicated
  /// for the spawned process.
  /**
   * Any handles created through duplication of those passed into
   * @arg pass_handle are returned in @arg set.
   * @return 0 if there were no handles to return; 1 if there were.
   */
  int dup_handles (ACE_Handle_Set &set) const;
  /// Get a copy of the handles passed to the spawned process. This
  /// will be the set of handles previously passed to @arg pass_handle().
  /**
   * Any handles previously passed to @arg pass_handle are returned
   * in @arg set.
   * @return 0 if there were no handles to return; 1 if there were.
   */
  int passed_handles (ACE_Handle_Set &set) const;
  /// Set value for avoid_zombies (has no real effect except on *nix).
  void avoid_zombies (int);
  /// Get current value for avoid_zombies.
  int avoid_zombies (void);
  /// Enable the use of a Unicode environment.  This only makes sense
  /// for Win32 when ACE_USES_WCHAR is not defined.
  void enable_unicode_environment (void);
  /// Disable the use of a Unicode environment.
  void disable_unicode_environment (void);
  /// Return the unicode environment status
  bool use_unicode_environment (void) const;
#if defined (ACE_WIN32)
  // = Non-portable accessors for when you "just have to use them."
  /// Used for setting and getting.
  ACE_TEXT_STARTUPINFO *startup_info (void);
  /// Get the process_attributes.  Returns NULL if
  /// set_process_attributes has not been set.
  LPSECURITY_ATTRIBUTES get_process_attributes (void) const;
  /// If this is called, a non-null process attributes is sent to
  /// CreateProcess.
  LPSECURITY_ATTRIBUTES set_process_attributes (void);
  /// Get the thread_attributes.  Returns NULL if set_thread_attributes
  /// has not been set.
  LPSECURITY_ATTRIBUTES get_thread_attributes (void) const;
  /// If this is called, a non-null thread attributes is sent to
  /// CreateProcess.
  LPSECURITY_ATTRIBUTES set_thread_attributes (void);
#else /* All things not WIN32 */
  /// argv-style array of environment settings.
  ACE_TCHAR *const *env_argv (void);
  // = Accessors for the standard handles.
  ACE_HANDLE get_stdin (void) const;
  ACE_HANDLE get_stdout (void) const;
  ACE_HANDLE get_stderr (void) const;
  // = Set/get real & effective user & group id associated with user.
  int setreugid (const ACE_TCHAR* user);
  void setruid (uid_t id);
  void seteuid (uid_t id);
  void setrgid (uid_t id);
  void setegid (uid_t id);
  uid_t getruid (void) const;
  uid_t geteuid (void) const;
  uid_t getrgid (void) const;
  uid_t getegid (void) const;
  /**
   * Get the inherit_environment flag.
   */
  bool inherit_environment (void) const;
  /**
   * Set the inherit_environment flag.
   */
  void inherit_environment (bool nv);
#endif /* ACE_WIN32 */
protected:
#if !defined (ACE_HAS_WINCE)
  /// Add @a assignment to environment_buf_ and adjust
  /// environment_argv_.  @a len is the strlen of @a assignment.
  int setenv_i (ACE_TCHAR *assignment, size_t len);
  /// Whether the child process inherits the current process
  /// environment.
  bool inherit_environment_;
#endif /* !ACE_HAS_WINCE */
  /// Default 0.
  u_long creation_flags_;
  /// Avoid zombies for spawned processes.
  int avoid_zombies_;
#if defined (ACE_WIN32) && !defined (ACE_HAS_WINCE)
  /// Helper function to grab win32 environment and stick it in
  /// environment_buf_ using this->setenv_i.
  void inherit_environment (void);
  /// Ensures once only call to inherit environment.
  int environment_inherited_;
  ACE_TEXT_STARTUPINFO startup_info_;
  /// Default TRUE.
  BOOL handle_inheritence_;
  /// Pointer to security_buf1_.
  LPSECURITY_ATTRIBUTES process_attributes_;
  /// Pointer to security_buf2_.
  LPSECURITY_ATTRIBUTES thread_attributes_;
  /// Data for process_attributes_.
  SECURITY_ATTRIBUTES security_buf1_;
  /// Data for thread_attributes_.
  SECURITY_ATTRIBUTES security_buf2_;
#else /* !ACE_WIN32 */
  ACE_HANDLE stdin_;
  ACE_HANDLE stdout_;
  ACE_HANDLE stderr_;
  // = Real & effective user & group id's.
  //   These should be set to -1 to leave unchanged (default).
  uid_t ruid_;
  uid_t euid_;
  uid_t rgid_;
  uid_t egid_;
#endif /* ACE_WIN32 */
#if !defined (ACE_HAS_WINCE)
  /// Is 1 if stdhandles was called.
  int set_handles_called_;
  /// Pointer into environment_buf_.  This should point to the next
  /// free spot.
  size_t environment_buf_index_;
  /// Pointer to environment_argv_.
  int environment_argv_index_;
  /// Pointer to buffer of the environment settings.
  ACE_TCHAR *environment_buf_;
  /// Size of the environment buffer. Configurable
  size_t environment_buf_len_;
  /// Pointers into environment_buf_.
  ACE_TCHAR **environment_argv_;
  /// Maximum number of environment variables. Configurable
  int max_environment_args_;
  /// Maximum index of environment_argv_ buffer
  int max_environ_argv_index_;
  /// The current working directory.
  ACE_TCHAR working_directory_[MAXPATHLEN + 1];
#endif /* !ACE_HAS_WINCE */
  /// Ensures command_line_argv is only calculated once.
  int command_line_argv_calculated_;
  /// Pointer to buffer of command-line arguments.  E.g., "-f foo -b bar".
  ACE_TCHAR *command_line_buf_;
  /// Pointer to copy of command-line arguments, which is needed when
  /// converting a command-line string into a command-line argv.
  ACE_TCHAR *command_line_copy_;
  /// Max length of command_line_buf_
  int command_line_buf_len_;
  /// Argv-style command-line arguments.
  ACE_TCHAR *command_line_argv_[MAX_COMMAND_LINE_OPTIONS];
  /// Process-group on Unix; unused on Win32.
  pid_t process_group_;
  /// Set of handles that were passed in pass_handle ().
  ACE_Handle_Set handles_passed_;
  /// Results of duplicating handles passed in pass_handle ().
  ACE_Handle_Set dup_handles_;
  /// Pathname for the process. Relative path or absolute path or just
  /// the program name.
  ACE_TCHAR process_name_[MAXPATHLEN + 1];
  /// Indicate if a Unicode environment should be used
  bool use_unicode_environment_;
};
//class ACE_Process_Manager;
/**
 * @class ACE_Process
 *
 * @brief Process
 *
 * A Portable encapsulation for creating new processes.
 * Notice that on UNIX platforms, if the <setenv> is used, the
 * <spawn> is using the <execve> system call. It means that the
 * <command_line> should include a full path to the program file
 * (<execve> does not search the PATH).  If <setenv> is not used
 * then, the <spawn> is using the <execvp> which searches for the
 * program file in the PATH variable.
 */
class ACE_Export ACE_Process
{
public:
  friend class ACE_Process_Manager;
  /// Default construction.  Must use <ACE_Process::spawn> to start.
  ACE_Process (void);
  /// Destructor.
  virtual ~ACE_Process (void);
  /**
   * Called just before <ACE_OS::fork> in the <spawn>.  If this
   * returns non-zero, the <spawn> is aborted (and returns
   * ACE_INVALID_PID).  The default simply returns zero.
   */
  virtual int prepare (ACE_Process_Options &options);
  /**
   * Launch a new process as described by @a options. On success,
   * returns 1 if the option avoid_zombies is set, else returns the
   * process id of the newly spawned child. Returns -1 on
   * failure. This will be fixed in the future versions of ACE when
   * the process id of the child will be returned regardless of the option.
   */
  virtual pid_t spawn (ACE_Process_Options &options);
  /// Called just after <ACE_OS::fork> in the parent's context, if the
  /// <fork> succeeds.  The default is to do nothing.
  virtual void parent (pid_t child);
  /**
   * Called just after <ACE_OS::fork> in the child's context.  The
   * default does nothing.  This function is *not* called on Win32
   * because the process-creation scheme does not allow it.
   */
  virtual void child (pid_t parent);
  /// Called by a <Process_Manager> that is removing this Process from
  /// its table of managed Processes.  Default is to do nothing.
  virtual void unmanage (void);
  /**
   * Wait for the process we've created to exit.  If <status> != 0, it
   * points to an integer where the function store the exit status of
   * child process to.  If <wait_options> == <WNOHANG> then return 0
   * and don't block if the child process hasn't exited yet.  A return
   * value of -1 represents the <wait> operation failed, otherwise,
   * the child process id is returned.
   */
  pid_t wait (ACE_exitcode *status = 0,
              int wait_options = 0);
  /**
   * Timed wait for the process we've created to exit.  A return value
   * of -1 indicates that the something failed; 0 indicates that a
   * timeout occurred.  Otherwise, the child's process id is returned.
   * If <status> != 0, it points to an integer where the function
   * stores the child's exit status.
   *
   * @note On UNIX platforms this function uses <ualarm>, i.e., it
   * overwrites any existing alarm.  In addition, it steals all
   * <SIGCHLD>s during the timeout period, which will break another
   * <ACE_Process_Manager> in the same process that's expecting
   * <SIGCHLD> to kick off process reaping.
   */
  pid_t wait (const ACE_Time_Value &tv,
              ACE_exitcode *status = 0);
  /// Send the process a signal.  This is only portable to operating
  /// systems that support signals, such as UNIX/POSIX.
  int kill (int signum = SIGINT);
  /**
   * Terminate the process abruptly using <ACE::terminate_process>.
   * This call doesn't give the process a chance to cleanup, so use it
   * with caution...
   */
  int terminate (void);
  /// Return the process id of the new child process.
  pid_t getpid (void) const;
  /// Return the handle of the process, if it has one.
  ACE_HANDLE gethandle (void) const;
  /// Return 1 if running; 0 otherwise.
  int running (void) const;
  /// Return the Process' exit code.  This method returns the raw
  /// exit status returned from system APIs (such as <wait> or
  /// <waitpid>).  This value is system dependent.
  ACE_exitcode exit_code (void) const;
  /// Return the Process' return value.  This method returns the
  /// actual return value that a child process returns or <exit>s.
  int return_value (void) const;
  /// Close all the handles in the set obtained from the
  /// @arg ACE_Process_Options::dup_handles object used to spawn
  /// the process.
  void close_dup_handles (void);
  /// Close all the handles in the set obtained from the
  /// @arg ACE_Process_Options::passed_handles object used to spawn
  /// the process.
  void close_passed_handles (void);
#if defined (ACE_WIN32)
  PROCESS_INFORMATION process_info (void);
#endif /* ACE_WIN32 */
private:
  // Disallow copying and assignment since we don't support this (yet).
  ACE_Process (const ACE_Process &);
  void operator= (const ACE_Process &);
protected:
  /// Set this process' <exit_code_>.  ACE_Process_Manager uses this
  /// method to set the <exit_code_> after successfully waiting for
  /// this process to exit.
  void exit_code (ACE_exitcode code);
#if defined (ACE_WIN32)
  PROCESS_INFORMATION process_info_;
#else /* ACE_WIN32 */
  /// Process id of the child.
  pid_t child_id_;
#endif /* ACE_WIN32 */
  ACE_exitcode exit_code_;
  /// Set of handles that were passed to the child process.
  ACE_Handle_Set handles_passed_;
  /// Handle duplicates made for the child process.
  ACE_Handle_Set dup_handles_;
private:
#if defined (ACE_WIN32) && \
    defined (ACE_HAS_WCHAR) && !defined (ACE_USES_WCHAR) && \
    !defined (ACE_HAS_WINCE)
  wchar_t* convert_env_buffer (const char* env) const;
#endif
};

/**
 * @class ACE_Managed_Process
 *
 * @brief A process easily managed by ACE_Process_Manager.
 *
 * @arg ACE_Managed_Process is just an @arg ACE_Process with an
 * @arg unmanage() method that deletes the instance.
 * This class is only valid for use as a dynamically-allocated object!
 */
class ACE_Export ACE_Managed_Process : public ACE_Process
{
public:
  /// Cleanup by deleting @c this.
  virtual void unmanage (void);
protected:
  /// Make sure that we're allocated dynamically!
  virtual ~ACE_Managed_Process (void);
};
ACE_END_VERSIONED_NAMESPACE_DECL
#if defined (__ACE_INLINE__)
#include "ace/Process.inl"
#endif /* __ACE_INLINE__ */
#include /**/ "ace/post.h"
#endif /* ACE_PROCESS_H */

