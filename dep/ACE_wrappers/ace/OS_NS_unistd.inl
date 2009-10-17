// -*- C++ -*-
//
// $Id: OS_NS_unistd.inl 81696 2008-05-14 18:15:31Z johnnyw $
#include "ace/OS_NS_sys_utsname.h"
#include "ace/OS_NS_string.h"
#include "ace/OS_NS_errno.h"
#include "ace/OS_NS_macros.h"
#include "ace/OS_NS_fcntl.h"
#include "ace/Default_Constants.h"
#include "ace/OS_Memory.h"
#include "ace/Truncate.h"
#if defined (ACE_HAS_CLOCK_GETTIME)
# include "ace/os_include/os_time.h"
#endif /* ACE_HAS_CLOCK_GETTIME */
#if defined (ACE_LACKS_ACCESS)
#  include "ace/OS_NS_stdio.h"
#endif /* ACE_LACKS_ACCESS */
#if defined (ACE_VXWORKS) || defined (ACE_HAS_WINCE)
#  include "ace/os_include/os_unistd.h"
#  if defined (ACE_VXWORKS) && (((ACE_VXWORKS >= 0x620) && (ACE_VXWORKS <= 0x660)) || defined (ACE_HAS_VXWORKS551_MEDUSA))
#    if defined (__RTP__)
#      include "ace/os_include/os_strings.h"
#    else
#      include "ace/os_include/os_string.h"
#    endif
#  endif
#endif /* VXWORKS || ACE_HAS_WINCE */
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
ACE_INLINE int
ACE_OS::access (const char *path, int amode)
{
  ACE_OS_TRACE ("ACE_OS::access");
#if defined (ACE_LACKS_ACCESS)
#  if defined (ACE_HAS_WINCE) || defined (ACE_VXWORKS)
  // @@ WINCE: There should be a Win32 API that can do this.
  // Hard coded read access here.
  ACE_UNUSED_ARG (amode);
  FILE* handle = ACE_OS::fopen (ACE_TEXT_CHAR_TO_TCHAR(path),
                                ACE_TEXT ("r"));
  if (handle != 0)
    {
      ACE_OS::fclose (handle);
      return 0;
    }
  return (-1);
#  else
    ACE_UNUSED_ARG (path);
    ACE_UNUSED_ARG (amode);
    ACE_NOTSUP_RETURN (-1);
#  endif  // ACE_HAS_WINCE
#elif defined(ACE_WIN32)
  // Windows doesn't support checking X_OK(6)
  ACE_OSCALL_RETURN (::access (path, amode & 6), int, -1);
#else
  ACE_OSCALL_RETURN (::access (path, amode), int, -1);
#endif /* ACE_LACKS_ACCESS */
}

#if defined (ACE_HAS_WCHAR)
ACE_INLINE int
ACE_OS::access (const wchar_t *path, int amode)
{
#if defined (ACE_WIN32) && !defined (ACE_HAS_WINCE)
  ACE_OSCALL_RETURN (::_waccess (path, amode), int, -1);
#else /* ACE_WIN32 && !ACE_HAS_WINCE */
  return ACE_OS::access (ACE_Wide_To_Ascii (path).char_rep (), amode);
#endif /* ACE_WIN32 && !ACE_HAS_WINCE */
}
#endif /* ACE_HAS_WCHAR */
ACE_INLINE u_int
ACE_OS::alarm (u_int secs)
{
  ACE_OS_TRACE ("ACE_OS::alarm");
#if defined (ACE_LACKS_ALARM)
  ACE_UNUSED_ARG (secs);
  ACE_NOTSUP_RETURN (0);
#else
  return ::alarm (secs);
#endif /* ACE_LACKS_ALARM */
}
ACE_INLINE long
ACE_OS::getpagesize (void)
{
  ACE_OS_TRACE ("ACE_OS::getpagesize");
#if defined (ACE_WIN32) && !defined (ACE_HAS_PHARLAP)
  SYSTEM_INFO sys_info;
  ::GetSystemInfo (&sys_info);
  return (long) sys_info.dwPageSize;
#elif defined (_SC_PAGESIZE) && !defined (ACE_HAS_NOTSUP_SC_PAGESIZE)
  return ::sysconf (_SC_PAGESIZE);
#elif defined (ACE_HAS_GETPAGESIZE)
  return ::getpagesize ();
#else
  // Use the default set in config.h
  return ACE_PAGE_SIZE;
#endif /* ACE_WIN32 */
}
ACE_INLINE long
ACE_OS::allocation_granularity (void)
{
#if defined (ACE_WIN32)
  SYSTEM_INFO sys_info;
  ::GetSystemInfo (&sys_info);
  return sys_info.dwAllocationGranularity;
#else
  return ACE_OS::getpagesize ();
#endif /* ACE_WIN32 */
}
#if !defined (ACE_LACKS_CHDIR)
ACE_INLINE int
ACE_OS::chdir (const char *path)
{
  ACE_OS_TRACE ("ACE_OS::chdir");
#if defined (ACE_HAS_NONCONST_CHDIR)
  ACE_OSCALL_RETURN (::chdir (const_cast<char *> (path)), int, -1);
#elif defined (ACE_HAS_WINCE)
  ACE_UNUSED_ARG (path);
  ACE_NOTSUP_RETURN (-1);
#else
  ACE_OSCALL_RETURN (::chdir (path), int, -1);
#endif /* ACE_HAS_NONCONST_CHDIR */
}
#if defined (ACE_HAS_WCHAR)
ACE_INLINE int
ACE_OS::chdir (const wchar_t *path)
{
#if defined (ACE_WIN32) && !defined (ACE_HAS_WINCE)
  ACE_OSCALL_RETURN (::_wchdir (path), int, -1);
#else /* ACE_WIN32 */
  return ACE_OS::chdir (ACE_Wide_To_Ascii (path).char_rep ());
#endif /* ACE_WIN32 */
}
#endif /* ACE_HAS_WCHAR */
#endif /* ACE_LACKS_CHDIR */
ACE_INLINE int
ACE_OS::rmdir (const char *path)
{
#if defined (ACE_HAS_WINCE)
  ACE_WIN32CALL_RETURN (ACE_ADAPT_RETVAL (::RemoveDirectory (ACE_TEXT_CHAR_TO_TCHAR (path)),
                                          ace_result_),
                        int, -1);
#else
  ACE_OSCALL_RETURN (::rmdir (path), int, -1);
#endif /* ACE_WIN32 */
}
#if defined (ACE_HAS_WCHAR)
ACE_INLINE int
ACE_OS::rmdir (const wchar_t *path)
{
#if defined (ACE_HAS_WINCE)
  ACE_WIN32CALL_RETURN (ACE_ADAPT_RETVAL (::RemoveDirectoryW (path),
                                          ace_result_),
                        int, -1);
#elif defined (ACE_WIN32)
  ACE_OSCALL_RETURN (::_wrmdir (path), int, -1);
#else
  ACE_Wide_To_Ascii n_path (path);
  return ACE_OS::rmdir (n_path.char_rep ());
#endif /* ACE_HAS_WINCE */
}
#endif /* ACE_HAS_WCHAR */
// @todo: which 4 and why???  dhinton
// NOTE: The following four function definitions must appear before
// ACE_OS::sema_init ().
ACE_INLINE int
ACE_OS::close (ACE_HANDLE handle)
{
  ACE_OS_TRACE ("ACE_OS::close");
#if defined (ACE_WIN32)
  ACE_WIN32CALL_RETURN (ACE_ADAPT_RETVAL (::CloseHandle (handle), ace_result_), int, -1);
#else
  ACE_OSCALL_RETURN (::close (handle), int, -1);
#endif /* ACE_WIN32 */
}
ACE_INLINE ACE_HANDLE
ACE_OS::dup (ACE_HANDLE handle)
{
  ACE_OS_TRACE ("ACE_OS::dup");
#if defined (ACE_WIN32) && !defined (ACE_HAS_WINCE)
  ACE_HANDLE new_fd;
  if (::DuplicateHandle(::GetCurrentProcess (),
                        handle,
                        ::GetCurrentProcess(),
                        &new_fd,
                        0,
                        TRUE,
                        DUPLICATE_SAME_ACCESS))
    return new_fd;
  else
    ACE_FAIL_RETURN (ACE_INVALID_HANDLE);
  /* NOTREACHED */
#elif defined (ACE_LACKS_DUP)
  ACE_UNUSED_ARG (handle);
  ACE_NOTSUP_RETURN (-1);
#elif defined (ACE_HAS_WINCE)
  ACE_UNUSED_ARG (handle);
  ACE_NOTSUP_RETURN (0);
#else
  ACE_OSCALL_RETURN (::dup (handle), ACE_HANDLE, ACE_INVALID_HANDLE);
#endif /* ACE_WIN32 && !ACE_HAS_WINCE */
}
ACE_INLINE int
ACE_OS::dup2 (ACE_HANDLE oldhandle, ACE_HANDLE newhandle)
{
  ACE_OS_TRACE ("ACE_OS::dup2");
#if defined (ACE_LACKS_DUP2)
  // msvcrt has _dup2 ?!
  ACE_UNUSED_ARG (oldhandle);
  ACE_UNUSED_ARG (newhandle);
  ACE_NOTSUP_RETURN (-1);
#else
  ACE_OSCALL_RETURN (::dup2 (oldhandle, newhandle), int, -1);
#endif /* ACE_LACKS_DUP2 */
}
ACE_INLINE int
ACE_OS::execv (const char *path,
               char *const argv[])
{
  ACE_OS_TRACE ("ACE_OS::execv");
#if defined (ACE_LACKS_EXEC)
  ACE_UNUSED_ARG (path);
  ACE_UNUSED_ARG (argv);
  ACE_NOTSUP_RETURN (-1);
#elif defined (ACE_WIN32)
# if defined (__BORLANDC__) /* VSB */
  return ::execv (path, argv);
# elif defined (__MINGW32__)
  return ::_execv (path, (char *const *) argv);
# else
  // Why this odd-looking code? If execv() returns at all, it's an error.
  // Windows defines this as returning an intptr_t rather than a simple int,
  // and the conversion triggers compile warnings. So just return -1 if
  // the call returns.
  ::_execv (path, (const char *const *) argv);
  return -1;
# endif /* __BORLANDC__ */
#else
  ACE_OSCALL_RETURN (::execv (path, argv), int, -1);
#endif /* ACE_LACKS_EXEC */
}
ACE_INLINE int
ACE_OS::execve (const char *path,
                char *const argv[],
                char *const envp[])
{
  ACE_OS_TRACE ("ACE_OS::execve");
#if defined (ACE_LACKS_EXEC)
  ACE_UNUSED_ARG (path);
  ACE_UNUSED_ARG (argv);
  ACE_UNUSED_ARG (envp);
  ACE_NOTSUP_RETURN (-1);
#elif defined (ACE_WIN32)
# if defined (__BORLANDC__) /* VSB */
  return ::execve (path, argv, envp);
# elif defined (__MINGW32__)
  return ::_execve (path, (char *const *) argv, (char *const *) envp);
# else
  // Why this odd-looking code? If execv() returns at all, it's an error.
  // Windows defines this as returning an intptr_t rather than a simple int,
  // and the conversion triggers compile warnings. So just return -1 if
  // the call returns.
  ::_execve (path, (const char *const *) argv, (const char *const *) envp);
  return -1;
# endif /* __BORLANDC__ */
#else
  ACE_OSCALL_RETURN (::execve (path, argv, envp), int, -1);
#endif /* ACE_LACKS_EXEC */
}
ACE_INLINE int
ACE_OS::execvp (const char *file,
                char *const argv[])
{
  ACE_OS_TRACE ("ACE_OS::execvp");
#if defined (ACE_LACKS_EXEC)
  ACE_UNUSED_ARG (file);
  ACE_UNUSED_ARG (argv);
  ACE_NOTSUP_RETURN (-1);
#elif defined (ACE_WIN32)
# if defined (__BORLANDC__) /* VSB */
  return ::execvp (file, argv);
# elif defined (__MINGW32__)
  return ::_execvp (file, (char *const *) argv);
# else
  // Why this odd-looking code? If execv() returns at all, it's an error.
  // Windows defines this as returning an intptr_t rather than a simple int,
  // and the conversion triggers compile warnings. So just return -1 if
  // the call returns.
  ::_execvp (file, (const char *const *) argv);
  return -1;
# endif /* __BORLANDC__ */
#else
  ACE_OSCALL_RETURN (::execvp (file, argv), int, -1);
#endif /* ACE_LACKS_EXEC */
}
ACE_INLINE pid_t
ACE_OS::fork (void)
{
  ACE_OS_TRACE ("ACE_OS::fork");
#if defined (ACE_LACKS_FORK)
  ACE_NOTSUP_RETURN (pid_t (-1));
#else
  ACE_OSCALL_RETURN (::fork (), pid_t, -1);
#endif /* ACE_LACKS_FORK */
}
ACE_INLINE int
ACE_OS::fsync (ACE_HANDLE handle)
{
  ACE_OS_TRACE ("ACE_OS::fsync");
# if defined (ACE_LACKS_FSYNC)
  ACE_UNUSED_ARG (handle);
  ACE_NOTSUP_RETURN (-1);
# elif defined (ACE_WIN32)
  ACE_WIN32CALL_RETURN (ACE_ADAPT_RETVAL (::FlushFileBuffers (handle), ace_result_), int, -1);
# else
  ACE_OSCALL_RETURN (::fsync (handle), int, -1);
# endif /* ACE_LACKS_FSYNC */
}
ACE_INLINE int
ACE_OS::ftruncate (ACE_HANDLE handle, ACE_OFF_T offset)
{
  ACE_OS_TRACE ("ACE_OS::ftruncate");
#if defined (ACE_WIN32)
#  if !defined (ACE_LACKS_WIN32_SETFILEPOINTEREX)
  LARGE_INTEGER loff;
  loff.QuadPart = offset;
  if (::SetFilePointerEx (handle, loff, 0, FILE_BEGIN))
#  else
  if (::SetFilePointer (handle,
                        offset,
                        0,
                        FILE_BEGIN) != INVALID_SET_FILE_POINTER)
#  endif
    ACE_WIN32CALL_RETURN (ACE_ADAPT_RETVAL (::SetEndOfFile (handle), ace_result_), int, -1);
  else
    ACE_FAIL_RETURN (-1);
#else
  ACE_OSCALL_RETURN (::ftruncate (handle, offset), int, -1);
#endif /* ACE_WIN32 */
}
ACE_INLINE char *
ACE_OS::getcwd (char *buf, size_t size)
{
  ACE_OS_TRACE ("ACE_OS::getcwd");
#if defined (ACE_LACKS_GETCWD)
  ACE_UNUSED_ARG (buf);
  ACE_UNUSED_ARG (size);
  ACE_NOTSUP_RETURN (0);
#elif defined (ACE_WIN32)
  return ::getcwd (buf, static_cast<int> (size));
#else
  ACE_OSCALL_RETURN (::getcwd (buf, size), char *, 0);
#endif /* ACE_LACKS_GETCWD */
}
#if defined (ACE_HAS_WCHAR)
ACE_INLINE wchar_t *
ACE_OS::getcwd (wchar_t *buf, size_t size)
{
#  if defined (ACE_HAS_WINCE)
  ACE_UNUSED_ARG (buf);
  ACE_UNUSED_ARG (size);
  ACE_NOTSUP_RETURN (0);
#  elif defined (ACE_WIN32)
  return ::_wgetcwd (buf, static_cast<int> (size));
#  else
  char *narrow_buf = new char[size];
  char *result = 0;
  result = ACE_OS::getcwd (narrow_buf, size);
  ACE_Ascii_To_Wide wide_buf (result);
  delete [] narrow_buf;
  if (result != 0)
    ACE_OS::strsncpy (buf, wide_buf.wchar_rep (), size);
  return result == 0 ? 0 : buf;
#  endif /* ACE_WIN32 */
}
#endif /* ACE_HAS_WCHAR */
ACE_INLINE gid_t
ACE_OS::getgid (void)
{
  ACE_OS_TRACE ("ACE_OS::getgid");
#if defined (ACE_LACKS_GETGID)
  ACE_NOTSUP_RETURN (static_cast<gid_t> (-1));
# else
  ACE_OSCALL_RETURN (::getgid (), gid_t, static_cast<gid_t> (-1));
# endif /* ACE_LACKS_GETGID */
}
ACE_INLINE gid_t
ACE_OS::getegid (void)
{
  ACE_OS_TRACE ("ACE_OS::getegid");
#if defined (ACE_LACKS_GETEGID)
  ACE_NOTSUP_RETURN (static_cast<gid_t> (-1));
# else
  ACE_OSCALL_RETURN (::getegid (), gid_t, static_cast<gid_t> (-1));
# endif /* ACE_LACKS_GETEGID */
}
ACE_INLINE int
ACE_OS::getopt (int argc, char *const *argv, const char *optstring)
{
  ACE_OS_TRACE ("ACE_OS::getopt");
#if defined (ACE_LACKS_GETOPT)
  ACE_UNUSED_ARG (argc);
  ACE_UNUSED_ARG (argv);
  ACE_UNUSED_ARG (optstring);
  ACE_NOTSUP_RETURN (-1);
# else
  ACE_OSCALL_RETURN (::getopt (argc, argv, optstring), int, -1);
# endif /* ACE_LACKS_GETOPT */
}
ACE_INLINE pid_t
ACE_OS::getpgid (pid_t pid)
{
  ACE_OS_TRACE ("ACE_OS::getpgid");
#if defined (ACE_LACKS_GETPGID)
  ACE_UNUSED_ARG (pid);
  ACE_NOTSUP_RETURN (-1);
#elif defined (linux) && __GLIBC__ > 1 && __GLIBC_MINOR__ >= 0
  // getpgid() is from SVR4, which appears to be the reason why GLIBC
  // doesn't enable its prototype by default.
  // Rather than create our own extern prototype, just use the one
  // that is visible (ugh).
  ACE_OSCALL_RETURN (::__getpgid (pid), pid_t, -1);
#else
  ACE_OSCALL_RETURN (::getpgid (pid), pid_t, -1);
#endif /* ACE_LACKS_GETPGID */
}
ACE_INLINE pid_t
ACE_OS::getpid (void)
{
  // ACE_OS_TRACE ("ACE_OS::getpid");
#if defined (ACE_LACKS_GETPID)
  ACE_NOTSUP_RETURN (-1);
#elif defined (ACE_WIN32)
  return ::GetCurrentProcessId ();
#else
  ACE_OSCALL_RETURN (::getpid (), int, -1);
#endif /* ACE_LACKS_GETPID */
}
ACE_INLINE pid_t
ACE_OS::getppid (void)
{
  ACE_OS_TRACE ("ACE_OS::getppid");
#if defined (ACE_LACKS_GETPPID)
  ACE_NOTSUP_RETURN (-1);
#else
  ACE_OSCALL_RETURN (::getppid (), pid_t, -1);
#endif /* ACE_LACKS_GETPPID */
}
ACE_INLINE uid_t
ACE_OS::getuid (void)
{
  ACE_OS_TRACE ("ACE_OS::getuid");
#if defined (ACE_LACKS_GETUID)
  ACE_NOTSUP_RETURN (static_cast<uid_t> (-1));
# else
  ACE_OSCALL_RETURN (::getuid (), uid_t, static_cast<uid_t> (-1));
# endif /* ACE_LACKS_GETUID*/
}
ACE_INLINE uid_t
ACE_OS::geteuid (void)
{
  ACE_OS_TRACE ("ACE_OS::geteuid");
#if defined (ACE_LACKS_GETEUID)
  ACE_NOTSUP_RETURN (static_cast<uid_t> (-1));
# else
  ACE_OSCALL_RETURN (::geteuid (), uid_t, (uid_t) -1);
# endif /* ACE_LACKS_GETEUID */
}
ACE_INLINE int
ACE_OS::hostname (char name[], size_t maxnamelen)
{
  ACE_OS_TRACE ("ACE_OS::hostname");
#if defined (ACE_HAS_PHARLAP)
  // PharLap only can do net stuff with the RT version.
#   if defined (ACE_HAS_PHARLAP_RT)
  // @@This is not at all reliable... requires ethernet and BOOTP to be used.
  // A more reliable way is to go thru the devices w/ EtsTCPGetDeviceCfg until
  // a legit IP address is found, then get its name w/ gethostbyaddr.
  ACE_SOCKCALL_RETURN (gethostname (name, maxnamelen), int, SOCKET_ERROR);
#   else
  ACE_UNUSED_ARG (name);
  ACE_UNUSED_ARG (maxnamelen);
  ACE_NOTSUP_RETURN (-1);
#   endif /* ACE_HAS_PHARLAP_RT */
#elif defined (ACE_VXWORKS) || defined (ACE_HAS_WINCE)
  ACE_OSCALL_RETURN (::gethostname (name, maxnamelen), int, -1);
#elif defined (ACE_WIN32)
  if (::gethostname (name, ACE_Utils::truncate_cast<int> (maxnamelen)) == 0)
  {
    return 0;
  }
  else
  {
    ACE_WIN32CALL_RETURN (ACE_ADAPT_RETVAL (::GetComputerNameA (name,
                                            LPDWORD (&maxnamelen)),
                                            ace_result_), int, -1);
  }
#else /* ACE_HAS_PHARLAP */
  ACE_utsname host_info;
  if (ACE_OS::uname (&host_info) == -1)
    return -1;
  else
    {
      ACE_OS::strsncpy (name, host_info.nodename, maxnamelen);
      return 0;
    }
#endif /* ACE_HAS_PHARLAP */
}
#if defined (ACE_HAS_WCHAR)
ACE_INLINE int
ACE_OS::hostname (wchar_t name[], size_t maxnamelen)
{
#if defined (ACE_WIN32) && !defined (ACE_HAS_WINCE)
  ACE_WIN32CALL_RETURN (ACE_ADAPT_RETVAL (GetComputerNameW (name,
                                                        LPDWORD (&maxnamelen)),
                                          ace_result_), int, -1);
#else /* ACE_WIN32 && !ACE_HAS_WINCE */
  // Emulate using the char version
  char *char_name = 0;
  int result = 0;
  ACE_NEW_RETURN (char_name, char[maxnamelen], -1);
  result = ACE_OS::hostname(char_name, maxnamelen);
  ACE_OS::strcpy (name, ACE_Ascii_To_Wide (char_name).wchar_rep ());
  delete [] char_name;
  return result;
#endif /* ACE_WIN32 && !ACE_HAS_WINCE */
}
#endif /* ACE_HAS_WCHAR */
ACE_INLINE int
ACE_OS::isatty (int handle)
{
  ACE_OS_TRACE ("ACE_OS::isatty");
#if defined (ACE_LACKS_ISATTY)
  ACE_UNUSED_ARG (handle);
  return 0;
# elif defined (ACE_WIN32)
  return ::_isatty (handle);
# else
  ACE_OSCALL_RETURN (::isatty (handle), int, -1);
# endif /* ACE_LACKS_ISATTY */
}
#if defined (ACE_WIN32)
ACE_INLINE int
ACE_OS::isatty (ACE_HANDLE handle)
{
#if defined (ACE_LACKS_ISATTY)
  ACE_UNUSED_ARG (handle);
  return 0;
#else
  int fd = ::_open_osfhandle (intptr_t (handle), 0);
  int status = ::_isatty (fd);
  ::_close (fd);
  return status;
#endif /* ACE_LACKS_ISATTY */
}
#endif /* ACE_WIN32 */
ACE_INLINE ACE_OFF_T
ACE_OS::lseek (ACE_HANDLE handle, ACE_OFF_T offset, int whence)
{
  ACE_OS_TRACE ("ACE_OS::lseek");
#if defined (ACE_WIN32)
# if SEEK_SET != FILE_BEGIN || SEEK_CUR != FILE_CURRENT || SEEK_END != FILE_END
  //#error Windows NT is evil AND rude!
  switch (whence)
    {
    case SEEK_SET:
      whence = FILE_BEGIN;
      break;
    case SEEK_CUR:
      whence = FILE_CURRENT;
      break;
    case SEEK_END:
      whence = FILE_END;
      break;
    default:
      errno = EINVAL;
      return static_cast<ACE_OFF_T> (-1); // rather safe than sorry
    }
# endif  /* SEEK_SET != FILE_BEGIN || SEEK_CUR != FILE_CURRENT || SEEK_END != FILE_END */
  LONG low_offset = ACE_LOW_PART(offset);
  LONG high_offset = ACE_HIGH_PART(offset);
  DWORD const result =
    ::SetFilePointer (handle, low_offset, &high_offset, whence);
  if (result == INVALID_SET_FILE_POINTER && GetLastError() != NO_ERROR)
    ACE_FAIL_RETURN (static_cast<ACE_OFF_T> (-1));
  else
    return result;
#else
  ACE_OSCALL_RETURN (::lseek (handle, offset, whence), ACE_OFF_T, -1);
#endif /* ACE_WIN32 */
}
#if defined (ACE_HAS_LLSEEK) || defined (ACE_HAS_LSEEK64)
ACE_INLINE ACE_LOFF_T
ACE_OS::llseek (ACE_HANDLE handle, ACE_LOFF_T offset, int whence)
{
  ACE_OS_TRACE ("ACE_OS::llseek");
#if ACE_SIZEOF_LONG == 8
  /* The native lseek is 64 bit.  Use it. */
  return ACE_OS::lseek (handle, offset, whence);
#elif defined (ACE_HAS_LLSEEK) && defined (ACE_HAS_LSEEK64)
# error Either ACE_HAS_LSEEK64 and ACE_HAS_LLSEEK should be defined, not both!
#elif defined (ACE_HAS_LSEEK64)
  ACE_OSCALL_RETURN (::lseek64 (handle, offset, whence), ACE_LOFF_T, -1);
#elif defined (ACE_HAS_LLSEEK)
# if defined (ACE_WIN32)
#  ifndef ACE_LACKS_WIN32_SETFILEPOINTEREX
  LARGE_INTEGER distance, new_file_pointer;
  distance.QuadPart = offset;
  return
    (::SetFilePointerEx (handle, distance, &new_file_pointer, whence)
     ? new_file_pointer.QuadPart
     : static_cast<ACE_LOFF_T> (-1));
#  else
  LARGE_INTEGER l_offset;
  l_offset.QuadPart = offset;
  LONG low_offset = l_offset.LowPart;
  LONG high_offset = l_offset.HighPart;
  l_offset.LowPart = ::SetFilePointer (handle,
                                       low_offset,
                                       &high_offset,
                                       whence);
  if (l_offset.LowPart == INVALID_SET_FILE_POINTER &&
      GetLastError () != NO_ERROR)
    return static_cast<ACE_LOFF_T> (-1);
  l_offset.HighPart = high_offset;
  return l_offset.QuadPart;
#  endif  /* ACE_LACKS_WIN32_SETFILEPOINTEREX */
# else
    ACE_OSCALL_RETURN (::llseek (handle, offset, whence), ACE_LOFF_T, -1);
# endif /* WIN32 */
#endif
}
#endif /* ACE_HAS_LLSEEK || ACE_HAS_LSEEK64 */
ACE_INLINE ssize_t
ACE_OS::read (ACE_HANDLE handle, void *buf, size_t len)
{
  ACE_OS_TRACE ("ACE_OS::read");
#if defined (ACE_WIN32)
  DWORD ok_len;
  if (::ReadFile (handle, buf, static_cast<DWORD> (len), &ok_len, 0))
    return (ssize_t) ok_len;
  else
    ACE_FAIL_RETURN (-1);
#else
  ssize_t result;
# if defined (ACE_HAS_CHARPTR_SOCKOPT)
  ACE_OSCALL (::read (handle, static_cast <char *> (buf), len), ssize_t, -1, result);
# else
  ACE_OSCALL (::read (handle, buf, len), ssize_t, -1, result);
# endif /* ACE_HAS_CHARPTR_SOCKOPT */
# if !(defined (EAGAIN) && defined (EWOULDBLOCK) && EAGAIN == EWOULDBLOCK)
  // Optimize this code out if we can detect that EAGAIN ==
  // EWOULDBLOCK at compile time.  If we cannot detect equality at
  // compile-time (e.g. if EAGAIN or EWOULDBLOCK are not preprocessor
  // macros) perform the check at run-time.  The goal is to avoid two
  // TSS accesses in the _REENTRANT case when EAGAIN == EWOULDBLOCK.
  if (result == -1
#  if !defined (EAGAIN) || !defined (EWOULDBLOCK)
      && EAGAIN != EWOULDBLOCK
#  endif  /* !EAGAIN || !EWOULDBLOCK */
      && errno == EAGAIN)
    {
      errno = EWOULDBLOCK;
    }
# endif /* EAGAIN != EWOULDBLOCK*/
  return result;
#endif /* ACE_WIN32 */
}
ACE_INLINE ssize_t
ACE_OS::read (ACE_HANDLE handle, void *buf, size_t len,
              ACE_OVERLAPPED *overlapped)
{
  ACE_OS_TRACE ("ACE_OS::read");
  overlapped = overlapped;
#if defined (ACE_WIN32)
  DWORD ok_len;
  DWORD short_len = static_cast<DWORD> (len);
  if (::ReadFile (handle, buf, short_len, &ok_len, overlapped))
    return (ssize_t) ok_len;
  else
    ACE_FAIL_RETURN (-1);
#else
  return ACE_OS::read (handle, buf, len);
#endif /* ACE_WIN32 */
}
ACE_INLINE ssize_t
ACE_OS::readlink (const char *path, char *buf, size_t bufsiz)
{
  ACE_OS_TRACE ("ACE_OS::readlink");
# if defined (ACE_LACKS_READLINK)
  ACE_UNUSED_ARG (path);
  ACE_UNUSED_ARG (buf);
  ACE_UNUSED_ARG (bufsiz);
  ACE_NOTSUP_RETURN (-1);
# else
#   if !defined(ACE_HAS_NONCONST_READLINK)
      ACE_OSCALL_RETURN (::readlink (path, buf, bufsiz), ssize_t, -1);
#   else
      ACE_OSCALL_RETURN (
        ::readlink (const_cast <char *>(path), buf, bufsiz), ssize_t, -1);
#   endif
# endif /* ACE_LACKS_READLINK */
}
ACE_INLINE int
ACE_OS::pipe (ACE_HANDLE fds[])
{
  ACE_OS_TRACE ("ACE_OS::pipe");
# if defined (ACE_LACKS_PIPE)
  ACE_UNUSED_ARG (fds);
  ACE_NOTSUP_RETURN (-1);
# elif defined (ACE_WIN32)
  ACE_WIN32CALL_RETURN (ACE_ADAPT_RETVAL
                        (::CreatePipe (&fds[0], &fds[1], 0, 0),
                         ace_result_), int, -1);
# else
  ACE_OSCALL_RETURN (::pipe (fds), int, -1);
# endif /* ACE_LACKS_PIPE */
}
ACE_INLINE void *
ACE_OS::sbrk (intptr_t brk)
{
#if defined (ACE_LACKS_SBRK)
  ACE_UNUSED_ARG (brk);
  ACE_NOTSUP_RETURN (0);
#else
  ACE_OSCALL_RETURN (::sbrk (brk), void *, 0);
#endif /* ACE_LACKS_SBRK */
}
ACE_INLINE int
ACE_OS::setgid (gid_t gid)
{
  ACE_OS_TRACE ("ACE_OS::setgid");
#if defined (ACE_LACKS_SETGID)
  ACE_UNUSED_ARG (gid);
  ACE_NOTSUP_RETURN (-1);
# else
  ACE_OSCALL_RETURN (::setgid (gid), int,  -1);
# endif /* ACE_LACKS_SETGID */
}
ACE_INLINE int
ACE_OS::setegid (gid_t gid)
{
  ACE_OS_TRACE ("ACE_OS::setegid");
#if defined (ACE_LACKS_SETEGID)
  ACE_UNUSED_ARG (gid);
  ACE_NOTSUP_RETURN (-1);
# else
  ACE_OSCALL_RETURN (::setegid (gid), int,  -1);
# endif /* ACE_LACKS_SETEGID */
}
ACE_INLINE int
ACE_OS::setpgid (pid_t pid, pid_t pgid)
{
  ACE_OS_TRACE ("ACE_OS::setpgid");
#if defined (ACE_LACKS_SETPGID)
  ACE_UNUSED_ARG (pid);
  ACE_UNUSED_ARG (pgid);
  ACE_NOTSUP_RETURN (-1);
#else
  ACE_OSCALL_RETURN (::setpgid (pid, pgid), int, -1);
#endif /* ACE_LACKS_SETPGID */
}
ACE_INLINE int
ACE_OS::setregid (gid_t rgid, gid_t egid)
{
  ACE_OS_TRACE ("ACE_OS::setregid");
#if defined (ACE_LACKS_SETREGID)
  ACE_UNUSED_ARG (rgid);
  ACE_UNUSED_ARG (egid);
  ACE_NOTSUP_RETURN (-1);
#else
  ACE_OSCALL_RETURN (::setregid (rgid, egid), int, -1);
#endif /* ACE_LACKS_SETREGID */
}
ACE_INLINE int
ACE_OS::setreuid (uid_t ruid, uid_t euid)
{
  ACE_OS_TRACE ("ACE_OS::setreuid");
#if defined (ACE_LACKS_SETREUID)
  ACE_UNUSED_ARG (ruid);
  ACE_UNUSED_ARG (euid);
  ACE_NOTSUP_RETURN (-1);
#else
  ACE_OSCALL_RETURN (::setreuid (ruid, euid), int, -1);
#endif /* ACE_LACKS_SETREUID */
}
ACE_INLINE pid_t
ACE_OS::setsid (void)
{
  ACE_OS_TRACE ("ACE_OS::setsid");
#if defined (ACE_LACKS_SETSID)
  ACE_NOTSUP_RETURN (-1);
#else
  ACE_OSCALL_RETURN (::setsid (), int, -1);
# endif /* ACE_LACKS_SETSID */
}
ACE_INLINE int
ACE_OS::setuid (uid_t uid)
{
  ACE_OS_TRACE ("ACE_OS::setuid");
#if defined (ACE_LACKS_SETUID)
  ACE_UNUSED_ARG (uid);
  ACE_NOTSUP_RETURN (-1);
# else
  ACE_OSCALL_RETURN (::setuid (uid), int,  -1);
# endif /* ACE_LACKS_SETUID */
}
ACE_INLINE int
ACE_OS::seteuid (uid_t uid)
{
  ACE_OS_TRACE ("ACE_OS::seteuid");
#if defined (ACE_LACKS_SETEUID)
  ACE_UNUSED_ARG (uid);
  ACE_NOTSUP_RETURN (-1);
# else
  ACE_OSCALL_RETURN (::seteuid (uid), int,  -1);
# endif /* ACE_LACKS_SETEUID */
}
ACE_INLINE int
ACE_OS::sleep (u_int seconds)
{
  ACE_OS_TRACE ("ACE_OS::sleep");
#if defined (ACE_WIN32)
  ::Sleep (seconds * ACE_ONE_SECOND_IN_MSECS);
  return 0;
#elif defined (ACE_HAS_CLOCK_GETTIME)
  struct timespec rqtp;
  // Initializer doesn't work with Green Hills 1.8.7
  rqtp.tv_sec = seconds;
  rqtp.tv_nsec = 0L;
  //FUZZ: disable check_for_lack_ACE_OS
  ACE_OSCALL_RETURN (::nanosleep (&rqtp, 0), int, -1);
  //FUZZ: enable check_for_lack_ACE_OS
#else
  ACE_OSCALL_RETURN (::sleep (seconds), int, -1);
#endif /* ACE_WIN32 */
}
ACE_INLINE int
ACE_OS::sleep (const ACE_Time_Value &tv)
{
  ACE_OS_TRACE ("ACE_OS::sleep");
#if defined (ACE_WIN32)
  ::Sleep (tv.msec ());
  return 0;
#elif defined (ACE_HAS_CLOCK_GETTIME)
  timespec_t rqtp = tv;
  //FUZZ: disable check_for_lack_ACE_OS
  ACE_OSCALL_RETURN (::nanosleep (&rqtp, 0), int, -1);
  //FUZZ: enable check_for_lack_ACE_OS
#else
# if defined (ACE_HAS_NONCONST_SELECT_TIMEVAL)
  // Copy the timeval, because this platform doesn't declare the timeval
  // as a pointer to const.
  timeval tv_copy = tv;
#  if defined(ACE_TANDEM_T1248_PTHREADS)
     ACE_OSCALL_RETURN (::spt_select (0, 0, 0, 0, &tv_copy), int, -1);
#  else
     //FUZZ: disable check_for_lack_ACE_OS
     ACE_OSCALL_RETURN (::select (0, 0, 0, 0, &tv_copy), int, -1);
     //FUZZ: enable check_for_lack_ACE_OS
#  endif
# else  /* ! ACE_HAS_NONCONST_SELECT_TIMEVAL */
  const timeval *tvp = tv;
  //FUZZ: disable check_for_lack_ACE_OS
  ACE_OSCALL_RETURN (::select (0, 0, 0, 0, tvp), int, -1);
  //FUZZ: enable check_for_lack_ACE_OS
# endif /* ACE_HAS_NONCONST_SELECT_TIMEVAL */
#endif /* ACE_WIN32 */
}
ACE_INLINE void
ACE_OS::swab (const void *src,
              void *dest,
              ssize_t length)
{
#if defined (ACE_LACKS_SWAB)
  // ------------------------------------------------------------
  // The following copyright notice applies to the swab()
  // implementation within this "ACE_LACKS_SWAB" block of code.
  // ------------------------------------------------------------
  /*
    Copyright (c) 1994-2006  Red Hat, Inc. All rights reserved.
    This copyrighted material is made available to anyone wishing to
    use, modify, copy, or redistribute it subject to the terms and
    conditions of the BSD License.   This program is distributed in
    the hope that it will be useful, but WITHOUT ANY WARRANTY
    expressed or implied, including the implied warranties of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  A copy of
    this license is available at
    http://www.opensource.org/licenses. Any Red Hat trademarks that
    are incorporated in the source code or documentation are not
    subject to the BSD License and may only be used or replicated with
    the express permission of Red Hat, Inc.
  */
  const char *from = static_cast<const char*> (src);
  char *to = static_cast<char *> (dest);
  ssize_t ptr = 0;
  for (ptr = 1; ptr < length; ptr += 2)
    {
      char p = from[ptr];
      char q = from[ptr-1];
      to[ptr-1] = p;
      to[ptr  ] = q;
    }
  if (ptr == length) /* I.e., if length is odd, */
    to[ptr-1] = 0;   /* then pad with a NUL. */
#elif defined (ACE_HAS_NONCONST_SWAB)
  const char *tmp = static_cast<const char*> (src);
  char *from = const_cast<char *> (tmp);
  char *to = static_cast<char *> (dest);
  ::swab (from, to, length);
#elif defined (ACE_HAS_CONST_CHAR_SWAB)
  const char *from = static_cast<const char*> (src);
  char *to = static_cast<char *> (dest);
  ::swab (from, to, length);
#else
  ::swab (src, dest, length);
#endif /* ACE_LACKS_SWAB */
}
ACE_INLINE long
ACE_OS::sysconf (int name)
{
  ACE_OS_TRACE ("ACE_OS::sysconf");
#if defined (ACE_LACKS_SYSCONF)
  ACE_UNUSED_ARG (name);
  ACE_NOTSUP_RETURN (-1);
#else
  ACE_OSCALL_RETURN (::sysconf (name), long, -1);
#endif /* ACE_LACKS_SYSCONF */
}
ACE_INLINE long
ACE_OS::sysinfo (int cmd, char *buf, long count)
{
  ACE_OS_TRACE ("ACE_OS::sysinfo");
#if defined (ACE_HAS_SYSINFO)
  ACE_OSCALL_RETURN (::sysinfo (cmd, buf, count), long, -1);
#else
  ACE_UNUSED_ARG (cmd);
  ACE_UNUSED_ARG (buf);
  ACE_UNUSED_ARG (count);
  ACE_NOTSUP_RETURN (0);
#endif /* ACE_HAS_SYSINFO */
}
ACE_INLINE int
ACE_OS::truncate (const ACE_TCHAR *filename,
                  ACE_OFF_T offset)
{
  ACE_OS_TRACE ("ACE_OS::truncate");
#if defined (ACE_WIN32)
  ACE_HANDLE handle = ACE_OS::open (filename,
                                    O_WRONLY,
                                    ACE_DEFAULT_FILE_PERMS);
#  if !defined (ACE_LACKS_WIN32_SETFILEPOINTEREX)
  LARGE_INTEGER loffset;
  loffset.QuadPart = offset;
#else
  LONG low_offset = ACE_LOW_PART(offset);
  LONG high_offset = ACE_HIGH_PART(offset);
#endif
  if (handle == ACE_INVALID_HANDLE)
    ACE_FAIL_RETURN (-1);
#  if !defined (ACE_LACKS_WIN32_SETFILEPOINTEREX)
  else if (::SetFilePointerEx (handle,
                               loffset,
                               0,
                               FILE_BEGIN))
#  else
  else if (::SetFilePointer (handle,
                             low_offset,
                             &high_offset,
                             FILE_BEGIN) != INVALID_SET_FILE_POINTER
           || GetLastError () == NO_ERROR)
#  endif /* ACE_LACKS_WIN32_SETFILEPOINTEREX */
    {
      BOOL result = ::SetEndOfFile (handle);
      ::CloseHandle (handle);
      ACE_WIN32CALL_RETURN (ACE_ADAPT_RETVAL (result, ace_result_), int, -1);
    }
  else
    {
      ::CloseHandle (handle);
      ACE_FAIL_RETURN (-1);
    }
  /* NOTREACHED */
#elif !defined (ACE_LACKS_TRUNCATE)
  ACE_OSCALL_RETURN
    (::truncate (ACE_TEXT_ALWAYS_CHAR (filename), offset), int, -1);
#else
  ACE_UNUSED_ARG (filename);
  ACE_UNUSED_ARG (offset);
  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_WIN32 */
}
ACE_INLINE useconds_t
ACE_OS::ualarm (useconds_t usecs, useconds_t interval)
{
  ACE_OS_TRACE ("ACE_OS::ualarm");
#if defined (ACE_HAS_UALARM)
  return ::ualarm (usecs, interval);
#elif !defined (ACE_LACKS_UNIX_SIGNALS)
  ACE_UNUSED_ARG (interval);
  return ::alarm (usecs * ACE_ONE_SECOND_IN_USECS);
#else
  ACE_UNUSED_ARG (usecs);
  ACE_UNUSED_ARG (interval);
  ACE_NOTSUP_RETURN (0);
#endif /* ACE_HAS_UALARM */
}
ACE_INLINE useconds_t
ACE_OS::ualarm (const ACE_Time_Value &tv,
                const ACE_Time_Value &tv_interval)
{
  ACE_OS_TRACE ("ACE_OS::ualarm");
#if defined (ACE_HAS_UALARM)
  useconds_t usecs = (tv.sec () * ACE_ONE_SECOND_IN_USECS) + tv.usec ();
  useconds_t interval =
    (tv_interval.sec () * ACE_ONE_SECOND_IN_USECS) + tv_interval.usec ();
  return ::ualarm (usecs, interval);
#elif !defined (ACE_LACKS_UNIX_SIGNALS)
  ACE_UNUSED_ARG (tv_interval);
  return ::alarm (tv.sec ());
#else
  ACE_UNUSED_ARG (tv_interval);
  ACE_UNUSED_ARG (tv);
  ACE_NOTSUP_RETURN (0);
#endif /* ACE_HAS_UALARM */
}
ACE_INLINE int
ACE_OS::unlink (const char *path)
{
  ACE_OS_TRACE ("ACE_OS::unlink");
# if defined (ACE_HAS_NONCONST_UNLINK)
  ACE_OSCALL_RETURN (::unlink (const_cast<char *> (path)), int, -1);
# elif defined (ACE_HAS_WINCE)
  // @@ The problem is, DeleteFile is not actually equals to unlink. ;(
  ACE_WIN32CALL_RETURN (ACE_ADAPT_RETVAL (::DeleteFile (ACE_TEXT_CHAR_TO_TCHAR (path)), ace_result_),
                        int, -1);
# elif defined (ACE_LACKS_UNLINK)
  ACE_UNUSED_ARG (path);
  ACE_NOTSUP_RETURN (-1);
# else
  ACE_OSCALL_RETURN (::unlink (path), int, -1);
# endif /* ACE_HAS_NONCONST_UNLINK */
}
#if defined (ACE_HAS_WCHAR)
ACE_INLINE int
ACE_OS::unlink (const wchar_t *path)
{
  ACE_OS_TRACE ("ACE_OS::unlink");
# if defined (ACE_HAS_WINCE)
  // @@ The problem is, DeleteFile is not actually equals to unlink. ;(
  ACE_WIN32CALL_RETURN (ACE_ADAPT_RETVAL (::DeleteFileW (path), ace_result_),
                        int, -1);
# elif defined (ACE_WIN32)
  ACE_OSCALL_RETURN (::_wunlink (path), int, -1);
# else
  ACE_Wide_To_Ascii npath (path);
  return ACE_OS::unlink (npath.char_rep ());
# endif /* ACE_HAS_WINCE */
}
#endif /* ACE_HAS_WCHAR */
ACE_INLINE ssize_t
ACE_OS::write (ACE_HANDLE handle, const void *buf, size_t nbyte)
{
  ACE_OS_TRACE ("ACE_OS::write");
#if defined (ACE_WIN32)
  DWORD bytes_written; // This is set to 0 byte WriteFile.
  // Strictly correctly, we should loop writing all the data if more
  // than a DWORD length can hold.
  DWORD short_nbyte = static_cast<DWORD> (nbyte);
  if (::WriteFile (handle, buf, short_nbyte, &bytes_written, 0))
    return (ssize_t) bytes_written;
  else
    ACE_FAIL_RETURN (-1);
#else
# if defined (ACE_HAS_CHARPTR_SOCKOPT)
  ACE_OSCALL_RETURN (::write (handle, static_cast <char *> (const_cast <void *> (buf)), nbyte), ssize_t, -1);
# else
  ACE_OSCALL_RETURN (::write (handle, buf, nbyte), ssize_t, -1);
# endif /* ACE_HAS_CHARPTR_SOCKOPT */
#endif /* ACE_WIN32 */
}
ACE_INLINE ssize_t
ACE_OS::write (ACE_HANDLE handle,
               const void *buf,
               size_t nbyte,
               ACE_OVERLAPPED *overlapped)
{
  ACE_OS_TRACE ("ACE_OS::write");
  overlapped = overlapped;
#if defined (ACE_WIN32)
  DWORD bytes_written; // This is set to 0 byte WriteFile.
  DWORD short_nbyte = static_cast<DWORD> (nbyte);
  if (::WriteFile (handle, buf, short_nbyte, &bytes_written, overlapped))
    return (ssize_t) bytes_written;
  else
    ACE_FAIL_RETURN (-1);
#else
  return ACE_OS::write (handle, buf, nbyte);
#endif /* ACE_WIN32 */
}
ACE_END_VERSIONED_NAMESPACE_DECL
