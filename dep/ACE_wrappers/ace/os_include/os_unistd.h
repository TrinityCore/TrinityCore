// -*- C++ -*-

//=============================================================================
/**
 *  @file    os_unistd.h
 *
 *  standard symbolic constants and types
 *
 *  $Id: os_unistd.h 81697 2008-05-14 18:33:11Z johnnyw $
 *
 *  @author Don Hinton <dhinton@dresystems.com>
 *  @author This code was originally in various places including ace/OS.h.
 */
//=============================================================================

#ifndef ACE_OS_INCLUDE_OS_UNISTD_H
#define ACE_OS_INCLUDE_OS_UNISTD_H

#include /**/ "ace/pre.h"

#include "ace/config-lite.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/os_include/sys/os_types.h"
#include "ace/os_include/os_inttypes.h"

#if defined (__BORLANDC__)
#  include "ace/os_include/os_fcntl.h"
#endif /* __BORLANDC */

#if defined (ACE_WIN32) && !defined (ACE_HAS_WINCE)
#  include /**/ <process.h>
#  include /**/ <io.h>
#endif /* ACE_WIN32 && !ACE_HAS_WINCE */

#if defined (ACE_HAS_SYS_SYSTEMINFO_H)
#  include /**/ <sys/systeminfo.h>
#endif /* ACE_HAS_SYS_SYSTEMINFO_H */

#if !defined (ACE_LACKS_UNISTD_H)
#  include /**/ <unistd.h>
#endif /* !ACE_LACKS_UNISTD_H */

#if defined (ACE_VXWORKS)
#  if !defined (__RTP__)
    // for unlink(), close(), read(), write(), lseek(), chdir(), getcwd(),
   // getwd(), and isatty()
   #  include /**/ <ioLib.h>
#  endif
// for gethostname()
#  include /**/ <hostLib.h>
#endif /* ACE_VXWORKS */

// Place all additions (especially function declarations) within extern "C" {}
#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

#if defined (ACE_WIN32)
// The following are #defines and #includes that are specific to
// WIN32.
#  if defined (ACE_HAS_WINCE)
#    define ACE_STDIN  _fileno (stdin)
#    define ACE_STDOUT _fileno (stdout)
#    define ACE_STDERR _fileno (stderr)
#  else
#    define ACE_STDIN GetStdHandle (STD_INPUT_HANDLE)
#    define ACE_STDOUT GetStdHandle (STD_OUTPUT_HANDLE)
#    define ACE_STDERR GetStdHandle (STD_ERROR_HANDLE)
#  endif  // ACE_HAS_WINCE
// The following are #defines and #includes that are specific to UNIX.
#else /* !ACE_WIN32 */
#  if defined (STDIN_FILENO)
#    define ACE_STDIN STDIN_FILENO
#  else
#    define ACE_STDIN 0
#  endif
#  if defined (STDOUT_FILENO)
#    define ACE_STDOUT STDOUT_FILENO
#  else
#    define ACE_STDOUT 1
#  endif
#  if defined (STDERR_FILENO)
#    define ACE_STDERR STDERR_FILENO
#  else
#    define ACE_STDERR 2
#  endif
#endif /* ACE_WIN32 */

#if (!defined (_BSD_SOURCE) && \
    !defined (_XOPEN_SOURCE) && !defined (_XOPEN_SOURCE_EXTENDED)) \
    || (defined (_XOPEN_SOURCE) && defined (__GNUC__))

# if defined (ACE_LACKS_SETREUID_PROTOTYPE)
  extern int setreuid (uid_t ruid, uid_t euid);
# endif /* ACE_LACKS_SETREUID_PROTOTYPE */

# if defined (ACE_LACKS_SETREGID_PROTOTYPE)
  extern int setregid (gid_t rgid, gid_t egid);
# endif /* ACE_LACKS_SETREGID_PROTOTYPE */
#endif  /* !_BSD_SOURCE && !_XOPEN_SOURCE && !_XOPEN_SOURCE_EXTENDED
           || _XOPEN_SOURCE && __GNUC__ */

  // for use by access()
# if !defined (R_OK)
#   define R_OK    04      /* Test for Read permission. */
# endif /* R_OK */

# if !defined (W_OK)
#   define W_OK    02      /* Test for Write permission. */
# endif /* W_OK */

# if !defined (X_OK)
#   if defined (ACE_WIN32)
      /* Windows has no test for X_OK - use R_OK instead */
#     define X_OK    R_OK      /* Test for eXecute permission. */
#   else  /* ACE_WIN32 */
#     define X_OK    01      /* Test for eXecute permission. */
#   endif /* ACE_WIN32 */
# endif /* X_OK */

# if !defined (F_OK)
#   define F_OK    0       /* Test for existence of File. */
# endif /* F_OK */

#if defined (ACE_LACKS_UALARM_PROTOTYPE)
   u_int ualarm (u_int usecs, u_int interval);
#endif /* ACE_LACKS_UALARM_PROTOTYPE */

#if defined (ACE_LACKS_PREAD_PROTOTYPE) && (_XOPEN_SOURCE - 0) < 500
   // _XOPEN_SOURCE == 500    Single Unix conformance
   // It seems that _XOPEN_SOURCE == 500 means that the prototypes are
   // already defined in the system headers.
   ssize_t pread (int fd,
                  void *buf,
                  size_t nbytes,
                  ACE_OFF_T offset);

   ssize_t pwrite (int fd,
                   const void *buf,
                   size_t n,
                   ACE_OFF_T offset);
#endif  /* ACE_LACKS_PREAD_PROTOTYPE && (_XOPEN_SOURCE - 0) < 500 */

#if defined (ACE_LACKS_GETPGID_PROTOTYPE) && \
    !defined (_XOPEN_SOURCE) && !defined (_XOPEN_SOURCE_EXTENDED)
   pid_t getpgid (pid_t pid);
#endif  /* ACE_LACKS_GETPGID_PROTOTYPE &&
           !_XOPEN_SOURCE && !_XOPEN_SOURCE_EXTENDED */

#if !defined (_LARGEFILE64_SOURCE)
#  if defined (ACE_LACKS_LSEEK64_PROTOTYPE) && \
      defined (ACE_LACKS_LLSEEK_PROTOTYPE)
#    error Define either ACE_LACKS_LSEEK64_PROTOTYPE or ACE_LACKS_LLSEEK_PROTOTYPE, not both!
#  elif defined (ACE_LACKS_LSEEK64_PROTOTYPE)
     ACE_LOFF_T lseek64 (int fd, ACE_LOFF_T offset, int whence);
#  elif defined (ACE_LACKS_LLSEEK_PROTOTYPE)
     ACE_LOFF_T llseek (int fd, ACE_LOFF_T offset, int whence);
#  endif
#endif  /* _LARGEFILE64_SOURCE */

#if defined (__BORLANDC__)
#  if (__BORLANDC__ <= 0x540)
#    define _getcwd getcwd
#    define _chdir chdir
#    undef _access
#    define _access access
#  endif
#  define _isatty isatty
#endif /* __BORLANDC__ */

# if defined (ACE_LACKS_TIMEDWAIT_PROTOTYPES)

  ssize_t read_timedwait (ACE_HANDLE handle,
                          char *buf,
                          size_t n,
                          struct timespec *timeout);

  ssize_t write_timedwait (ACE_HANDLE handle,
                           const void *buf,
                           size_t n,
                           struct timespec *timeout);

# endif /* ACE_LACKS_TIMEDWAIT_PROTOTYPES */

#if defined (ACE_LACKS_SWAB_PROTOTYPE)
  void swab(const void *, void *, ssize_t);
#endif /* ACE_LACKS_SWAB_PROTOTYPE */

#if defined (ACE_LACKS_GETOPT_PROTOTYPE)
  int getopt(int, char * const [], const char *);
#endif /* ACE_LACKS_GETOPT_PROTOTYPE */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#include /**/ "ace/post.h"
#endif /* ACE_OS_INCLUDE_OS_UNISTD_H */
