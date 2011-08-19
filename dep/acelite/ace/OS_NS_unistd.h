// -*- C++ -*-

//=============================================================================
/**
 *  @file   OS_NS_unistd.h
 *
 *  $Id: OS_NS_unistd.h 91066 2010-07-12 11:05:04Z johnnyw $
 *
 *  @author Douglas C. Schmidt <schmidt@cs.wustl.edu>
 *  @author Jesper S. M|ller<stophph@diku.dk>
 *  @author and a cast of thousands...
 *
 *  Originally in OS.h.
 */
//=============================================================================

#ifndef ACE_OS_NS_UNISTD_H
# define ACE_OS_NS_UNISTD_H

# include /**/ "ace/pre.h"

# include "ace/config-all.h"

# if !defined (ACE_LACKS_PRAGMA_ONCE)
#  pragma once
# endif /* ACE_LACKS_PRAGMA_ONCE */

#include /**/ "ace/ACE_export.h"
#include "ace/Time_Value.h"
#include "ace/Basic_Types.h"
#include "ace/os_include/os_unistd.h"
#include "ace/os_include/os_stdio.h"


#if defined (ACE_EXPORT_MACRO)
#  undef ACE_EXPORT_MACRO
#endif
#define ACE_EXPORT_MACRO ACE_Export

// This should go in os_unistd.h, but since we don't yet implement any code
// at that level, we put it here.  It used to be in OS.i.
#if defined (ACE_NEEDS_FTRUNCATE)
extern "C" ACE_Export int ftruncate (ACE_HANDLE handle, long len);
#endif /* ACE_NEEDS_FTRUNCATE */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

namespace ACE_OS
{

  ACE_NAMESPACE_INLINE_FUNCTION
  int access (const char *path, int amode);

#if defined (ACE_HAS_WCHAR)
  ACE_NAMESPACE_INLINE_FUNCTION
  int access (const wchar_t *path, int amode);
#endif /* ACE_HAS_WCHAR */

  ACE_NAMESPACE_INLINE_FUNCTION
  unsigned int alarm (u_int secs);

  ACE_NAMESPACE_INLINE_FUNCTION
  long allocation_granularity (void);

  /// used by ARGV::argv_to_string() and ACE_OS::fork_exec()
  extern ACE_Export
  int argv_to_string (int argc,
                      ACE_TCHAR **argv,
                      ACE_TCHAR *&buf,
                      bool substitute_env_args = true,
                      bool quote_args = false);

  extern ACE_Export
  int argv_to_string (ACE_TCHAR **argv,
                      ACE_TCHAR *&buf,
                      bool substitute_env_args = true,
                      bool quote_args = false);

  ACE_NAMESPACE_INLINE_FUNCTION
  int chdir (const char *path);

#if defined (ACE_HAS_WCHAR)
  ACE_NAMESPACE_INLINE_FUNCTION
  int chdir (const wchar_t *path);
#endif /* ACE_HAS_WCHAR */

  ACE_NAMESPACE_INLINE_FUNCTION
  int rmdir (const char *path);

#if defined (ACE_HAS_WCHAR)
  ACE_NAMESPACE_INLINE_FUNCTION
  int rmdir (const wchar_t *path);
#endif /* ACE_HAS_WCHAR */

  ACE_NAMESPACE_INLINE_FUNCTION
  int close (ACE_HANDLE handle);

  ACE_NAMESPACE_INLINE_FUNCTION
  ACE_HANDLE dup (ACE_HANDLE handle);

  ACE_NAMESPACE_INLINE_FUNCTION
  ACE_HANDLE dup (ACE_HANDLE handle, pid_t pid);

  ACE_NAMESPACE_INLINE_FUNCTION
  int dup2 (ACE_HANDLE oldfd,
            ACE_HANDLE newfd);

  extern ACE_Export
  int execl (const char *path,
             const char *arg0, ...);

  extern ACE_Export
  int execle (const char *path,
              const char *arg0, ...);

  extern ACE_Export
  int execlp (const char *file,
              const char *arg0, ...);

  ACE_NAMESPACE_INLINE_FUNCTION
  int execv (const char *path,
             char *const argv[]);

  ACE_NAMESPACE_INLINE_FUNCTION
  int execve (const char *path,
              char *const argv[],
              char *const envp[]);

  ACE_NAMESPACE_INLINE_FUNCTION
  int execvp (const char *file,
              char *const argv[]);

  //@{
  /// Forks and exec's a process in a manner that works on Solaris and
  /// NT.  argv[0] must be the full path name to the executable.
  ACE_NAMESPACE_INLINE_FUNCTION
  pid_t fork (void);

  // not in susv3
  extern ACE_Export
  pid_t fork (const ACE_TCHAR *program_name);

  extern ACE_Export
  pid_t fork_exec (ACE_TCHAR *argv[]);
  //@}

  ACE_NAMESPACE_INLINE_FUNCTION
  int fsync (ACE_HANDLE handle);

  ACE_NAMESPACE_INLINE_FUNCTION
  int ftruncate (ACE_HANDLE handle, ACE_OFF_T offset);

  ACE_NAMESPACE_INLINE_FUNCTION
  char *getcwd (char *, size_t);

#if defined (ACE_HAS_WCHAR)
  ACE_NAMESPACE_INLINE_FUNCTION
  wchar_t *getcwd (wchar_t *, size_t);
#endif /* ACE_HAS_WCHAR */

  ACE_NAMESPACE_INLINE_FUNCTION
  gid_t getgid (void);

  ACE_NAMESPACE_INLINE_FUNCTION
  gid_t getegid (void);

  ACE_NAMESPACE_INLINE_FUNCTION
  int getopt (int argc,
              char *const *argv,
              const char *optstring);

  ACE_NAMESPACE_INLINE_FUNCTION
  long getpagesize (void);

  ACE_NAMESPACE_INLINE_FUNCTION
  pid_t getpgid (pid_t pid);

  ACE_NAMESPACE_INLINE_FUNCTION
  pid_t getpid (void);

  ACE_NAMESPACE_INLINE_FUNCTION
  pid_t getppid (void);

  ACE_NAMESPACE_INLINE_FUNCTION
  uid_t getuid (void);

  ACE_NAMESPACE_INLINE_FUNCTION
  uid_t geteuid (void);

  // should call gethostname()
  ACE_NAMESPACE_INLINE_FUNCTION
  int hostname (char name[],
                size_t maxnamelen);

#if defined (ACE_HAS_WCHAR)
  ACE_NAMESPACE_INLINE_FUNCTION
  int hostname (wchar_t name[],
                size_t maxnamelen);
#endif /* ACE_HAS_WCHAR */

  ACE_NAMESPACE_INLINE_FUNCTION
  int isatty (int handle);

#if defined (ACE_WIN32)
  ACE_NAMESPACE_INLINE_FUNCTION
  int isatty (ACE_HANDLE handle);
#endif /* ACE_WIN32 */

  ACE_NAMESPACE_INLINE_FUNCTION
  ACE_OFF_T lseek (ACE_HANDLE handle,
                   ACE_OFF_T offset,
                   int whence);

#if defined (ACE_HAS_LLSEEK) || defined (ACE_HAS_LSEEK64)
  ACE_NAMESPACE_INLINE_FUNCTION
  ACE_LOFF_T llseek (ACE_HANDLE handle,
                     ACE_LOFF_T offset,
                     int whence);
#endif /* ACE_HAS_LLSEEK */

  /// Get the number of CPUs configured in the machine.
  extern ACE_Export
  long num_processors (void);

  /// Get the number of CPUs currently online.
  extern ACE_Export
  long num_processors_online (void);

  ACE_NAMESPACE_INLINE_FUNCTION
  int pipe (ACE_HANDLE handles[]);

  extern ACE_Export
  ssize_t pread (ACE_HANDLE handle,
                 void *buf,
                 size_t nbyte,
                 ACE_OFF_T offset);

  extern ACE_Export
  ssize_t pwrite (ACE_HANDLE handle,
                  const void *buf,
                  size_t nbyte,
                  ACE_OFF_T offset);

  ACE_NAMESPACE_INLINE_FUNCTION
  ssize_t read (ACE_HANDLE handle,
                void *buf,
                size_t len);

  ACE_NAMESPACE_INLINE_FUNCTION
  ssize_t read (ACE_HANDLE handle,
                void *buf,
                size_t len,
                ACE_OVERLAPPED *);

  /**
   * Receive @a len bytes into @a buf from @a handle (uses the
   * <ACE_OS::read> call, which uses the <read> system call on UNIX
   * and the <ReadFile> call on Win32). If errors occur, -1 is
   * returned.  If EOF occurs, 0 is returned.  Whatever data has been
   * read will be returned to the caller through @a bytes_transferred.
   *
   */
  extern ACE_Export
  ssize_t read_n (ACE_HANDLE handle,
                  void *buf,
                  size_t len,
                  size_t *bytes_transferred = 0);

  ACE_NAMESPACE_INLINE_FUNCTION
  ssize_t readlink (const char *path,
                    char *buf,
                    size_t bufsiz);

  ACE_NAMESPACE_INLINE_FUNCTION
  void *sbrk (intptr_t brk);

  ACE_NAMESPACE_INLINE_FUNCTION
  int setgid (gid_t);

  ACE_NAMESPACE_INLINE_FUNCTION
  int setegid (gid_t);

  ACE_NAMESPACE_INLINE_FUNCTION
  int setpgid (pid_t pid, pid_t pgid);

  ACE_NAMESPACE_INLINE_FUNCTION
  int setregid (gid_t rgid, gid_t egid);

  ACE_NAMESPACE_INLINE_FUNCTION
  int setreuid (uid_t ruid, uid_t euid);

  ACE_NAMESPACE_INLINE_FUNCTION
  pid_t setsid (void);

  ACE_NAMESPACE_INLINE_FUNCTION
  int setuid (uid_t);

  ACE_NAMESPACE_INLINE_FUNCTION
  int seteuid (uid_t);

  ACE_NAMESPACE_INLINE_FUNCTION
  int sleep (u_int seconds);

  ACE_NAMESPACE_INLINE_FUNCTION
  int sleep (const ACE_Time_Value &tv);

  // used by ARGV::string_to_argv
  extern ACE_Export
  int string_to_argv (ACE_TCHAR *buf,
                      int &argc,
                      ACE_TCHAR **&argv,
                      bool substitute_env_args = true);

  ACE_NAMESPACE_INLINE_FUNCTION
  void swab (const void *src, void *dest, ssize_t n);

  ACE_NAMESPACE_INLINE_FUNCTION
  long sysconf (int);

  // not in susv3
  ACE_NAMESPACE_INLINE_FUNCTION
  long sysinfo (int cmd,
                char *buf,
                long count);

  ACE_NAMESPACE_INLINE_FUNCTION
  int truncate (const ACE_TCHAR *filename, ACE_OFF_T length);

  ACE_NAMESPACE_INLINE_FUNCTION
  useconds_t ualarm (useconds_t usecs,
                     useconds_t interval = 0);

  ACE_NAMESPACE_INLINE_FUNCTION
  useconds_t ualarm (const ACE_Time_Value &tv,
                     const ACE_Time_Value &tv_interval = ACE_Time_Value::zero);

  ACE_NAMESPACE_INLINE_FUNCTION
  int unlink (const char *path);

#if defined (ACE_HAS_WCHAR)
  ACE_NAMESPACE_INLINE_FUNCTION
  int unlink (const wchar_t *path);
#endif /* ACE_HAS_WCHAR */

  ACE_NAMESPACE_INLINE_FUNCTION
  ssize_t write (ACE_HANDLE handle,
                 const void *buf,
                 size_t nbyte);

  ACE_NAMESPACE_INLINE_FUNCTION
  ssize_t write (ACE_HANDLE handle,
                 const void *buf,
                 size_t nbyte,
                 ACE_OVERLAPPED *);

  /**
   * Send @a len bytes from @a buf to @a handle (uses the <ACE_OS::write>
   * calls, which is uses the <write> system call on UNIX and the
   * <WriteFile> call on Win32).  If errors occur, -1 is returned.  If
   * EOF occurs, 0 is returned.  Whatever data has been transmitted
   * will be returned to the caller through @a bytes_transferred.
   */
  extern ACE_Export
  ssize_t write_n (ACE_HANDLE handle,
                   const void *buf,
                   size_t len,
                   size_t *bytes_transferred = 0);

} /* namespace ACE_OS */

ACE_END_VERSIONED_NAMESPACE_DECL

# if defined (ACE_HAS_INLINED_OSCALLS)
#   if defined (ACE_INLINE)
#     undef ACE_INLINE
#   endif /* ACE_INLINE */
#   define ACE_INLINE inline
#   include "ace/OS_NS_unistd.inl"
# endif /* ACE_HAS_INLINED_OSCALLS */

# include /**/ "ace/post.h"
#endif /* ACE_OS_NS_UNISTD_H */
