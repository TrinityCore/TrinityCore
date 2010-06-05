// -*- C++ -*-
//
// $Id: OS_NS_stdio.inl 82444 2008-07-28 13:33:07Z johnnyw $

#include "ace/OS_NS_unistd.h"
#include "ace/OS_NS_stdlib.h"
#include "ace/OS_NS_fcntl.h"
#include "ace/OS_NS_errno.h"
#include "ace/OS_NS_string.h"
#include "ace/OS_NS_pwd.h"
#include "ace/OS_NS_macros.h"
#include "ace/OS_NS_sys_stat.h"
#include "ace/OS_Memory.h"

#if defined (ACE_HAS_TRIO)
#  include <trio.h>
#endif /* ACE_HAS_TRIO */

/*****************************************************************************/

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

#if defined (ACE_WIN32)
ACE_INLINE void
ACE_OS::flock_adjust_params (ACE_OS::ace_flock_t *lock,
                             short whence,
                             ACE_OFF_T &start,
                             ACE_OFF_T &len)
{
  switch (whence)
    {
    case SEEK_SET:
      break;
    case SEEK_CUR:
      {
        LARGE_INTEGER offset;
# if !defined (ACE_LACKS_WIN32_SETFILEPOINTEREX)
        LARGE_INTEGER distance;
        distance.QuadPart = 0;
        if (!::SetFilePointerEx (lock->handle_,
                                 distance,
                                 &offset,
                                 FILE_CURRENT))
          {
            ACE_OS::set_errno_to_last_error ();
            return;
          }
# else
        offset.LowPart = ::SetFilePointer (lock->handle_,
                                           0,
                                           &offset.HighPart,
                                           FILE_CURRENT);
        if (offset.LowPart == INVALID_SET_FILE_POINTER &&
            ::GetLastError() != NO_ERROR)
          {
            ACE_OS::set_errno_to_last_error ();
            return;
          }
# endif /* ACE_LACKS_WIN32_SETFILEPOINTEREX */

# if defined (_FILE_OFFSET_BITS) && _FILE_OFFSET_BITS == 64
        start += offset.QuadPart;
# else
        start += offset.LowPart;
# endif /* _FILE_OFFSET_BITS == 64 */
      }
      break;
    case SEEK_END:
      {
        ACE_OFF_T const size = ACE_OS::filesize (lock->handle_);
        if (size == -1)
          return;

        start += size;
      }
      break;
    }
  lock->overlapped_.Offset = ACE_LOW_PART (start);
  lock->overlapped_.OffsetHigh = ACE_HIGH_PART (start);
  if (len == 0)
    {
      ACE_OFF_T const tlen = ACE_OS::filesize (lock->handle_);
      if (tlen != -1)
        len = tlen - start;
    }
}
#endif /* ACE_WIN32 */

ACE_INLINE int
ACE_OS::flock_init (ACE_OS::ace_flock_t *lock,
                    int flags,
                    const ACE_TCHAR *name,
                    mode_t perms)
{
  ACE_OS_TRACE ("ACE_OS::flock_init");
#if defined (ACE_WIN32)
  // Once initialized, these values are never changed.
  lock->overlapped_.Internal = 0;
  lock->overlapped_.InternalHigh = 0;
  lock->overlapped_.OffsetHigh = 0;
  lock->overlapped_.hEvent = 0;
#endif /* ACE_WIN32 */
  lock->handle_ = ACE_INVALID_HANDLE;
  lock->lockname_ = 0;

  if (name != 0)
    {
      ACE_OSCALL (ACE_OS::open (name, flags, perms),
                  ACE_HANDLE,
                  ACE_INVALID_HANDLE,
                  lock->handle_);
      if (lock->handle_ != ACE_INVALID_HANDLE)
        lock->lockname_ = ACE_OS::strdup (name);
      return lock->handle_ == ACE_INVALID_HANDLE ? -1 : 0;
    }
  else
    return 0;
}

ACE_INLINE int
ACE_OS::flock_unlock (ACE_OS::ace_flock_t *lock,
                      short whence,
                      ACE_OFF_T start,
                      ACE_OFF_T len)
{
  ACE_OS_TRACE ("ACE_OS::flock_unlock");
#if defined (ACE_LACKS_FILELOCKS)
  ACE_UNUSED_ARG (lock);
  ACE_UNUSED_ARG (whence);
  ACE_UNUSED_ARG (start);
  ACE_UNUSED_ARG (len);
  ACE_NOTSUP_RETURN (-1);
#elif defined (ACE_WIN32)
  ACE_OS::flock_adjust_params (lock, whence, start, len);
  DWORD low_len = ACE_LOW_PART (len);
  DWORD high_len = ACE_HIGH_PART (len);
  ACE_WIN32CALL_RETURN (
    ACE_ADAPT_RETVAL (::UnlockFile (lock->handle_,
                                    lock->overlapped_.Offset,
                                    lock->overlapped_.OffsetHigh,
                                    low_len,
                                    high_len),
                      ace_result_), int, -1);
#else
  lock->lock_.l_whence = whence;
  lock->lock_.l_start = start;
  lock->lock_.l_len = len;
  lock->lock_.l_type = F_UNLCK;   // Unlock file.

  // release lock
  ACE_OSCALL_RETURN (ACE_OS::fcntl (lock->handle_, F_SETLK,
                                    reinterpret_cast<long> (&lock->lock_)),
                     int, -1);
#endif /* ACE_WIN32 */
}

ACE_INLINE int
ACE_OS::flock_destroy (ACE_OS::ace_flock_t *lock,
                       int unlink_file)
{
  ACE_OS_TRACE ("ACE_OS::flock_destroy");
  if (lock->handle_ != ACE_INVALID_HANDLE)
    {
      ACE_OS::flock_unlock (lock);
      // Close the handle.
      ACE_OS::close (lock->handle_);
      lock->handle_ = ACE_INVALID_HANDLE;
      if (lock->lockname_ != 0)
        {
          if (unlink_file)
            ACE_OS::unlink (lock->lockname_);
          ACE_OS::free (
            static_cast<void *> (const_cast<ACE_TCHAR *> (lock->lockname_)));
        }
      lock->lockname_ = 0;
    }
  return 0;
}

ACE_INLINE int
ACE_OS::flock_rdlock (ACE_OS::ace_flock_t *lock,
                      short whence,
                      ACE_OFF_T start,
                      ACE_OFF_T len)
{
  ACE_OS_TRACE ("ACE_OS::flock_rdlock");
#if defined (ACE_LACKS_FILELOCKS)
  ACE_UNUSED_ARG (lock);
  ACE_UNUSED_ARG (whence);
  ACE_UNUSED_ARG (start);
  ACE_UNUSED_ARG (len);
  ACE_NOTSUP_RETURN (-1);
#elif defined (ACE_WIN32)
  ACE_OS::flock_adjust_params (lock, whence, start, len);
  DWORD low_len = ACE_LOW_PART (len);
  DWORD high_len = ACE_HIGH_PART (len);
  ACE_WIN32CALL_RETURN (ACE_ADAPT_RETVAL (::LockFileEx (lock->handle_,
                                                        0,
                                                        0,
                                                        low_len,
                                                        high_len,
                                                        &lock->overlapped_),
                                          ace_result_), int, -1);
#else
  lock->lock_.l_whence = whence;
  lock->lock_.l_start = start;
  lock->lock_.l_len = len;
  lock->lock_.l_type = F_RDLCK;         // set read lock
  // block, if no access
  ACE_OSCALL_RETURN (ACE_OS::fcntl (lock->handle_, F_SETLKW,
                                    reinterpret_cast<long> (&lock->lock_)),
                     int, -1);
#endif /* ACE_WIN32 */
}

ACE_INLINE int
ACE_OS::flock_tryrdlock (ACE_OS::ace_flock_t *lock,
                         short whence,
                         ACE_OFF_T start,
                         ACE_OFF_T len)
{
  ACE_OS_TRACE ("ACE_OS::ace_flock_tryrdlock");
#if defined (ACE_LACKS_FILELOCKS)
  ACE_UNUSED_ARG (lock);
  ACE_UNUSED_ARG (whence);
  ACE_UNUSED_ARG (start);
  ACE_UNUSED_ARG (len);
  ACE_NOTSUP_RETURN (-1);
#elif defined (ACE_WIN32)
  ACE_OS::flock_adjust_params (lock, whence, start, len);
  DWORD low_len = ACE_LOW_PART (len);
  DWORD high_len = ACE_HIGH_PART (len);
  ACE_WIN32CALL_RETURN (
    ACE_ADAPT_RETVAL (::LockFileEx (lock->handle_,
                                    LOCKFILE_FAIL_IMMEDIATELY,
                                    0,
                                    low_len,
                                    high_len,
                                    &lock->overlapped_),
                      ace_result_), int, -1);
#else
  lock->lock_.l_whence = whence;
  lock->lock_.l_start = start;
  lock->lock_.l_len = len;
  lock->lock_.l_type = F_RDLCK;         // set read lock

  int result = 0;
  // Does not block, if no access, returns -1 and set errno = EBUSY;
  ACE_OSCALL (ACE_OS::fcntl (lock->handle_, F_SETLK,
                             reinterpret_cast<long> (&lock->lock_)),
              int, -1, result);

  if (result == -1 && (errno == EACCES || errno == EAGAIN))
    errno = EBUSY;

  return result;
#endif /* ACE_WIN32 */
}

ACE_INLINE int
ACE_OS::flock_trywrlock (ACE_OS::ace_flock_t *lock,
                         short whence,
                         ACE_OFF_T start,
                         ACE_OFF_T len)
{
  ACE_OS_TRACE ("ACE_OS::ace_flock_trywrlock");
#if defined (ACE_LACKS_FILELOCKS)
  ACE_UNUSED_ARG (lock);
  ACE_UNUSED_ARG (whence);
  ACE_UNUSED_ARG (start);
  ACE_UNUSED_ARG (len);
  ACE_NOTSUP_RETURN (-1);
#elif defined (ACE_WIN32)
  ACE_OS::flock_adjust_params (lock, whence, start, len);
  DWORD low_len = ACE_LOW_PART (len);
  DWORD high_len = ACE_HIGH_PART (len);
  ACE_WIN32CALL_RETURN (
    ACE_ADAPT_RETVAL (::LockFileEx (lock->handle_,
                                    LOCKFILE_FAIL_IMMEDIATELY | LOCKFILE_EXCLUSIVE_LOCK,
                                    0,
                                    low_len,
                                    high_len,
                                    &lock->overlapped_),
                      ace_result_), int, -1);
#else
  lock->lock_.l_whence = whence;
  lock->lock_.l_start = start;
  lock->lock_.l_len = len;
  lock->lock_.l_type = F_WRLCK;         // set write lock

  int result = 0;
  // Does not block, if no access, returns -1 and set errno = EBUSY;
  ACE_OSCALL (ACE_OS::fcntl (lock->handle_,
                             F_SETLK,
                             reinterpret_cast<long> (&lock->lock_)),
              int, -1, result);

  if (result == -1 && (errno == EACCES || errno == EAGAIN))
    errno = EBUSY;

  return result;
#endif /* ACE_WIN32 */
}

ACE_INLINE int
ACE_OS::flock_wrlock (ACE_OS::ace_flock_t *lock,
                      short whence,
                      ACE_OFF_T start,
                      ACE_OFF_T len)
{
  ACE_OS_TRACE ("ACE_OS::flock_wrlock");
#if defined (ACE_LACKS_FILELOCKS)
  ACE_UNUSED_ARG (lock);
  ACE_UNUSED_ARG (whence);
  ACE_UNUSED_ARG (start);
  ACE_UNUSED_ARG (len);
  ACE_NOTSUP_RETURN (-1);
#elif defined (ACE_WIN32)
  ACE_OS::flock_adjust_params (lock, whence, start, len);
  DWORD low_len = ACE_LOW_PART (len);
  DWORD high_len = ACE_HIGH_PART (len);
  ACE_WIN32CALL_RETURN (
    ACE_ADAPT_RETVAL (::LockFileEx (lock->handle_,
                                    LOCKFILE_EXCLUSIVE_LOCK,
                                    0,
                                    low_len,
                                    high_len,
                                    &lock->overlapped_),
                      ace_result_), int, -1);
#else
  lock->lock_.l_whence = whence;
  lock->lock_.l_start = start;
  lock->lock_.l_len = len;
  lock->lock_.l_type = F_WRLCK;         // set write lock
  // block, if no access
  ACE_OSCALL_RETURN (ACE_OS::fcntl (lock->handle_, F_SETLKW,
                                    reinterpret_cast<long> (&lock->lock_)),
                     int, -1);
#endif /* ACE_WIN32 */
}

#if !defined (ACE_LACKS_CLEARERR)
ACE_INLINE void
ACE_OS::clearerr (FILE* fp)
{
  ace_clearerr_helper (fp);
}
#endif /* !ACE_LACKS_CLEARERR */

#if !defined (ACE_LACKS_CUSERID)
ACE_INLINE char *
ACE_OS::cuserid (char *user, size_t maxlen)
{
  ACE_OS_TRACE ("ACE_OS::cuserid");
#if defined (ACE_VXWORKS)
  ACE_UNUSED_ARG (maxlen);
  if (user == 0)
    {
      // Require that the user field be non-null, i.e., don't
      // allocate or use static storage.
      ACE_NOTSUP_RETURN (0);
    }
  else
    {
      ::remCurIdGet (user, 0);
      return user;
    }
#elif defined (__QNXNTO__) || defined (ACE_HAS_PHARLAP) || defined (ACE_HAS_WINCE)
  ACE_UNUSED_ARG (user);
  ACE_UNUSED_ARG (maxlen);
  ACE_NOTSUP_RETURN (0);
#elif defined (ACE_WIN32)
  BOOL result = GetUserNameA (user, (u_long *) &maxlen);
  if (result == FALSE)
    ACE_FAIL_RETURN (0);
  else
    return user;
#elif defined (ACE_HAS_ALT_CUSERID)
#  if defined (ACE_LACKS_PWD_FUNCTIONS)
#    error Cannot use alternate cuserid() without POSIX password functions!
#  endif  /* ACE_LACKS_PWD_FUNCTIONS */

  // POSIX.1 dropped the cuserid() function.
  // GNU GLIBC and other platforms correctly deprecate the cuserid()
  // function.

  if (maxlen == 0)
    {
      // It doesn't make sense to have a zero length user ID.
      errno = EINVAL;
      return 0;
    }

  struct passwd *pw = 0;

  // Make sure the file pointer is at the beginning of the password file
  ACE_OS::setpwent ();
  // Should use ACE_OS::setpwent() but I didn't want to move this
  // method after it.

  // Use the effective user ID to determine the user name.
  pw = ::getpwuid (ACE_OS::geteuid ());

  // Make sure the password file is closed.
  ACE_OS::endpwent ();

  if (pw == 0)
    {
      errno = ENOENT;
      return 0;
    }

  size_t max_length = 0;
  char *userid = 0;

  if (user == 0)
    {
      // Not reentrant/thread-safe, but nothing else can be done if a
      // zero pointer was passed in as the destination.

#if defined (_POSIX_SOURCE) && defined (L_cuserid)
      const size_t ACE_L_cuserid = L_cuserid;
#else
      const size_t ACE_L_cuserid = 9;  // 8 character user ID + NULL
#endif  /* _POSIX_SOURCE */

      static char tmp[ACE_L_cuserid] = { '\0' };
      max_length = ACE_L_cuserid - 1; // Do not include NULL in length

      userid = tmp;
    }
  else
    {
      max_length = maxlen;
      userid = user;
    }

  // Extract the user name from the passwd structure.
  if (ACE_OS::strlen (pw->pw_name) <= max_length)
    {
      return ACE_OS::strcpy (userid, pw->pw_name);
    }
  else
    {
      errno = ENOSPC;  // Buffer is not large enough.
      return 0;
    }
#else
  // Hackish because of missing buffer size!
  ACE_UNUSED_ARG (maxlen);
  ACE_OSCALL_RETURN (::ace_cuserid(user), char*, 0);
#endif /* ACE_VXWORKS */
}

#if defined (ACE_HAS_WCHAR)
ACE_INLINE wchar_t *
ACE_OS::cuserid (wchar_t *user, size_t maxlen)
{
# if defined (ACE_HAS_WINCE)
  ACE_UNUSED_ARG (user);
  ACE_UNUSED_ARG (maxlen);
  ACE_NOTSUP_RETURN (0);
# elif defined (ACE_WIN32)
  BOOL result = GetUserNameW (user, (u_long *) &maxlen);
  if (result == FALSE)
    ACE_FAIL_RETURN (0);
  else
    return user;
# else /* ACE_WIN32 */
  char *char_user;
  wchar_t *result = 0;

  ACE_NEW_RETURN (char_user, char[maxlen + 1], 0);

  if (ACE_OS::cuserid (char_user, maxlen))
    {
      ACE_OS::strcpy (user, ACE_Ascii_To_Wide (char_user).wchar_rep ());
      result = user;
    }

  delete [] char_user;

  return result;
# endif /* ACE_WIN32 */
}
#endif /* ACE_HAS_WCHAR  */
#endif /* ACE_LACKS_CUSERID */

ACE_INLINE int
ACE_OS::fclose (FILE *fp)
{
  ACE_OS_TRACE ("ACE_OS::fclose");
  ACE_OSCALL_RETURN (ACE_STD_NAMESPACE::fclose (fp), int, -1);
}

ACE_INLINE FILE *
ACE_OS::fdopen (ACE_HANDLE handle, const ACE_TCHAR *mode)
{
  ACE_OS_TRACE ("ACE_OS::fdopen");
#if defined (ACE_HAS_WINCE)
  ACE_OSCALL_RETURN (::_wfdopen (handle, ACE_TEXT_ALWAYS_WCHAR (mode)),
                     FILE*,
                     0);
#elif defined (ACE_WIN32)
  // kernel file handle -> FILE* conversion...
  // Options: _O_APPEND, _O_RDONLY and _O_TEXT are lost

  FILE * file = 0;

  int const crt_handle = ::_open_osfhandle (intptr_t (handle), 0);

  if (crt_handle != -1)
    {
#   if defined(ACE_HAS_NONCONST_FDOPEN) && !defined (ACE_USES_WCHAR)
      file = ::_fdopen (crt_handle, const_cast<ACE_TCHAR *> (mode));
#   elif defined (ACE_HAS_NONCONST_FDOPEN) && defined (ACE_USES_WCHAR)
      file = ::_wfdopen (crt_handle, const_cast<ACE_TCHAR *> (mode));
#   elif defined (ACE_USES_WCHAR)
      file = ::_wfdopen (crt_handle, mode);
#   else
      file = ::_fdopen (crt_handle, mode);
#   endif /* ACE_HAS_NONCONST_FDOPEN */

      if (!file)
        {
          ::_close (crt_handle);
        }
    }

  return file;
#elif defined (ACE_LACKS_FDOPEN)
  ACE_UNUSED_ARG (handle);
  ACE_UNUSED_ARG (mode);
  ACE_NOTSUP_RETURN (0);
#else
  ACE_OSCALL_RETURN
    (::fdopen (handle, ACE_TEXT_ALWAYS_CHAR (mode)), FILE *, 0);
#endif /* ACE_HAS_WINCE */
}

ACE_INLINE int
ACE_OS::fflush (FILE *fp)
{
  ACE_OS_TRACE ("ACE_OS::fflush");
#if defined (ACE_VXWORKS)
  if (fp == 0)
    {
      // Do not allow fflush(0) on VxWorks
      return 0;
    }
#endif /* ACE_VXWORKS */

  ACE_OSCALL_RETURN (ACE_STD_NAMESPACE::fflush (fp), int, -1);
}

ACE_INLINE int
ACE_OS::fgetc (FILE* fp)
{
  return ace_fgetc_helper (fp);
}

ACE_INLINE int
ACE_OS::getc (FILE* fp)
{
  return ace_getc_helper (fp);
}

ACE_INLINE int
ACE_OS::fgetpos (FILE* fp, fpos_t* pos)
{
  ACE_OSCALL_RETURN (ACE_STD_NAMESPACE::fgetpos (fp, pos), int, -1);
}

ACE_INLINE char *
ACE_OS::fgets (char *buf, int size, FILE *fp)
{
  ACE_OS_TRACE ("ACE_OS::fgets");
  ACE_OSCALL_RETURN (ACE_STD_NAMESPACE::fgets (buf, size, fp), char *, 0);
}

#if defined (ACE_HAS_WCHAR) && !defined(ACE_LACKS_FGETWS)
ACE_INLINE wchar_t *
ACE_OS::fgets (wchar_t *buf, int size, FILE *fp)
{
  ACE_OS_TRACE ("ACE_OS::fgets");
  ACE_OSCALL_RETURN (ACE_STD_NAMESPACE::fgetws (buf, size, fp), wchar_t *, 0);
}
#endif /* ACE_HAS_WCHAR && !ACE_LACKS_FGETWS */

#if !(defined (ACE_WIN32) && !defined (ACE_HAS_WINCE))
// Win32 PC implementation of fopen () is in OS_NS_stdio.cpp.
ACE_INLINE FILE *
ACE_OS::fopen (const char *filename, const char *mode)
{
  ACE_OS_TRACE ("ACE_OS::fopen");
  ACE_OSCALL_RETURN
    (::fopen (filename, mode), FILE *, 0);
}

#if defined (ACE_HAS_WCHAR)
// Win32 PC implementation of fopen () is in OS_NS_stdio.cpp.
ACE_INLINE FILE *
ACE_OS::fopen (const char *filename, const wchar_t *mode)
{
  ACE_OS_TRACE ("ACE_OS::fopen");
  ACE_Wide_To_Ascii n_mode (mode);
  ACE_OSCALL_RETURN
    (::fopen (filename, n_mode.char_rep ()), FILE *, 0);
}
// Win32 PC implementation of fopen () is in OS_NS_stdio.cpp.
ACE_INLINE FILE *
ACE_OS::fopen (const wchar_t *filename, const wchar_t *mode)
{
  ACE_OS_TRACE ("ACE_OS::fopen");
#if defined (ACE_HAS_WINCE)
  ACE_OSCALL_RETURN
    (::_wfopen (filename, mode), FILE *, 0);
#else
  // Non-Windows doesn't use wchar_t file systems.
  ACE_Wide_To_Ascii n_filename (filename);
  ACE_Wide_To_Ascii n_mode (mode);
  ACE_OSCALL_RETURN
    (::fopen (n_filename.char_rep (), n_mode.char_rep ()), FILE*, 0);
#endif /* ACE_HAS_WINCE */
}
// Win32 PC implementation of fopen () is in OS_NS_stdio.cpp.
ACE_INLINE FILE *
ACE_OS::fopen (const wchar_t *filename, const char *mode)
{
  ACE_OS_TRACE ("ACE_OS::fopen");
#if defined (ACE_HAS_WINCE)
  ACE_Ascii_To_Wide n_mode (mode);
  ACE_OSCALL_RETURN
    (::_wfopen (filename, n_mode.wchar_rep ()), FILE *, 0);
#else
  // Non-Windows doesn't use wchar_t file systems.
  ACE_Wide_To_Ascii n_filename (filename);
  ACE_OSCALL_RETURN
    (::fopen (n_filename.char_rep (), mode), FILE*, 0);
#endif /* ACE_HAS_WINCE */
}
#endif /* ACE_HAS_WCHAR */

#endif /* ACE_WIN32 */

ACE_INLINE int
ACE_OS::ungetc (int c, FILE *fp)
{
  return ace_ungetc_helper (c, fp);
}

ACE_INLINE int
ACE_OS::fputc (int c, FILE *fp)
{
  return ace_fputc_helper (c, fp);
}

ACE_INLINE int
ACE_OS::putc (int c, FILE *fp)
{
  return ace_putc_helper (c, fp);
}

ACE_INLINE int
ACE_OS::fputs (const char *s, FILE *stream)
{
  ACE_OS_TRACE ("ACE_OS::fputs");
  ACE_OSCALL_RETURN (ACE_STD_NAMESPACE::fputs (s, stream), int, -1);
}

#if defined (ACE_HAS_WCHAR) && !defined(ACE_LACKS_FPUTWS)
ACE_INLINE int
ACE_OS::fputs (const wchar_t *s, FILE *stream)
{
  ACE_OS_TRACE ("ACE_OS::fputs");
  ACE_OSCALL_RETURN (ACE_STD_NAMESPACE::fputws (s, stream), int, -1);
}
#endif /* ACE_HAS_WCHAR && !ACE_LACKS_FPUTWS */

ACE_INLINE size_t
ACE_OS::fread (void *ptr, size_t size, size_t nelems, FILE *fp)
{
  ACE_OS_TRACE ("ACE_OS::fread");
  ACE_OSCALL_RETURN (ACE_STD_NAMESPACE::fread (ptr, size, nelems, fp),
                     size_t,
                     0);
}

ACE_INLINE FILE *
ACE_OS::freopen (const ACE_TCHAR *filename, const ACE_TCHAR *mode, FILE* stream)
{
  ACE_OS_TRACE ("ACE_OS::freopen");
#if defined (ACE_WIN32) && (defined(ACE_USES_WCHAR) || defined(ACE_HAS_WINCE))
  ACE_OSCALL_RETURN (::_wfreopen (ACE_TEXT_ALWAYS_WCHAR (filename),
                                  ACE_TEXT_ALWAYS_WCHAR (mode),
                                  stream),
                     FILE *, 0);
#else
  ACE_OSCALL_RETURN
    (ACE_STD_NAMESPACE::freopen (ACE_TEXT_ALWAYS_CHAR (filename),
                                 ACE_TEXT_ALWAYS_CHAR (mode),
                                 stream),
     FILE *, 0);
#endif /* ACE_WIN32 && ACE_USES_WCHAR */
}

ACE_INLINE int
ACE_OS::fseek (FILE *fp, long offset, int whence)
{
# if defined (ACE_WIN32)
#   if SEEK_SET != FILE_BEGIN || SEEK_CUR != FILE_CURRENT || SEEK_END != FILE_END
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
      return -1; // rather safe than sorry
    }
#   endif  /* SEEK_SET != FILE_BEGIN || SEEK_CUR != FILE_CURRENT || SEEK_END != FILE_END */
# endif   /* ACE_WIN32 */
  ACE_OSCALL_RETURN (ACE_STD_NAMESPACE::fseek (fp, offset, whence), int, -1);
}

ACE_INLINE int
ACE_OS::fsetpos (FILE* fp, fpos_t* pos)
{
  ACE_OSCALL_RETURN (::fsetpos (fp, pos), int, -1);
}

ACE_INLINE long
ACE_OS::ftell (FILE* fp)
{
  ACE_OSCALL_RETURN (ACE_STD_NAMESPACE::ftell (fp), long, -1);
}

ACE_INLINE size_t
ACE_OS::fwrite (const void *ptr, size_t size, size_t nitems, FILE *fp)
{
  ACE_OS_TRACE ("ACE_OS::fwrite");
  ACE_OSCALL_RETURN (ACE_STD_NAMESPACE::fwrite (ptr, size, nitems, fp),
                     size_t,
                     0);
}

ACE_INLINE void
ACE_OS::perror (const char *s)
{
  ACE_OS_TRACE ("ACE_OS::perror");
#if defined (ACE_LACKS_PERROR)
  ACE_UNUSED_ARG (s);
#else
  ::perror (s);
#endif /* ACE_HAS_WINCE */
}

#if defined (ACE_HAS_WCHAR)
ACE_INLINE void
ACE_OS::perror (const wchar_t *s)
{
  ACE_OS_TRACE ("ACE_OS::perror");
#if defined (ACE_LACKS_PERROR)
  ACE_UNUSED_ARG (s);
#elif defined (ACE_WIN32)
  ::_wperror (s);
#else
  ACE_Wide_To_Ascii n_s (s);
  ::perror (n_s.char_rep ());
#endif /* ACE_HAS_WINCE */
}
#endif /* ACE_HAS_WCHAR */

ACE_INLINE int
ACE_OS::puts (const char *s)
{
  ACE_OS_TRACE ("ACE_OS::puts");
  ACE_OSCALL_RETURN (::puts (s), int, -1);
}

#if defined (ACE_HAS_WCHAR)
ACE_INLINE int
ACE_OS::puts (const wchar_t *s)
{
  ACE_OS_TRACE ("ACE_OS::puts");
#if defined (ACE_WIN32)
  ACE_OSCALL_RETURN (::_putws (s), int, -1);
#else /* ACE_WIN32 */
  // There's no putws()...
  ACE_Wide_To_Ascii n_s (s);
  ACE_OSCALL_RETURN (::puts (n_s.char_rep ()), int, -1);
#endif /* ACE_WIN32 */
}
#endif /* ACE_HAS_WCHAR */

ACE_INLINE int
ACE_OS::rename (const char *old_name,
                const char *new_name,
                int flags)
{
# if defined (ACE_LACKS_RENAME)
  ACE_UNUSED_ARG (old_name);
  ACE_UNUSED_ARG (new_name);
  ACE_UNUSED_ARG (flags);
  ACE_NOTSUP_RETURN (-1);
# elif defined (ACE_HAS_WINCE)
  // Win CE is always wide-char.
  ACE_UNUSED_ARG (flags);
  if (0 != MoveFile (ACE_TEXT_CHAR_TO_TCHAR (old_name),
                     ACE_TEXT_CHAR_TO_TCHAR (new_name)))
    ACE_FAIL_RETURN (-1);
  return 0;
# elif defined (ACE_WIN32) && !defined (ACE_LACKS_WIN32_MOVEFILEEX)
  // NT4 (and up) provides a way to rename/move a file with similar semantics
  // to what's usually done on UNIX - if there's an existing file with
  // <new_name> it is removed before the file is renamed/moved. The
  // MOVEFILE_COPY_ALLOWED is specified to allow such a rename across drives.
  if (flags == -1)
    flags = MOVEFILE_COPY_ALLOWED | MOVEFILE_REPLACE_EXISTING;
  if (::MoveFileExA (old_name, new_name, flags) == 0)
    ACE_FAIL_RETURN (-1);
  return 0;
# else /* ACE_LACKS_RENAME */
  ACE_UNUSED_ARG (flags);
  ACE_OSCALL_RETURN (::rename (old_name, new_name), int, -1);
# endif /* ACE_LACKS_RENAME */
}

#if defined (ACE_HAS_WCHAR)
ACE_INLINE int
ACE_OS::rename (const wchar_t *old_name,
                const wchar_t *new_name,
                int flags)
{
# if defined (ACE_LACKS_RENAME)
  ACE_UNUSED_ARG (old_name);
  ACE_UNUSED_ARG (new_name);
  ACE_UNUSED_ARG (flags);
  ACE_NOTSUP_RETURN (-1);
# elif defined (ACE_HAS_WINCE)
  ACE_UNUSED_ARG (flags);
  if (MoveFileW (old_name, new_name) != 0)
    ACE_FAIL_RETURN (-1);
  return 0;
# elif defined (ACE_WIN32) && !defined (ACE_LACKS_WIN32_MOVEFILEEX)
  // NT4 (and up) provides a way to rename/move a file with similar semantics
  // to what's usually done on UNIX - if there's an existing file with
  // <new_name> it is removed before the file is renamed/moved. The
  // MOVEFILE_COPY_ALLOWED is specified to allow such a rename across drives.
  if (flags == -1)
    flags = MOVEFILE_COPY_ALLOWED | MOVEFILE_REPLACE_EXISTING;
  if (::MoveFileExW (old_name, new_name, flags) == 0)
    ACE_FAIL_RETURN (-1);
  return 0;
# elif defined (ACE_WIN32)
  ACE_UNUSED_ARG (flags);
  ACE_OSCALL_RETURN (::_wrename (old_name, new_name), int, -1);
# else /* ACE_LACKS_RENAME */
  ACE_Wide_To_Ascii nold_name (old_name);
  ACE_Wide_To_Ascii nnew_name (new_name);
  return ACE_OS::rename (nold_name.char_rep (), nnew_name.char_rep (), flags);
# endif /* ACE_LACKS_RENAME */
}
#endif /* ACE_HAS_WCHAR */

ACE_INLINE void
ACE_OS::rewind (FILE *fp)
{
#if !defined (ACE_HAS_WINCE)
  ACE_OS_TRACE ("ACE_OS::rewind");
  ::rewind (fp);
#else
  // This isn't perfect since it doesn't reset EOF, but it's probably
  // the closest we can get on WINCE.
  (void) fseek (fp, 0L, SEEK_SET);
#endif /* ACE_HAS_WINCE */
}

ACE_INLINE char *
ACE_OS::tempnam (const char *dir, const char *pfx)
{
  ACE_OS_TRACE ("ACE_OS::tempnam");
#if defined (ACE_LACKS_TEMPNAM)
  ACE_UNUSED_ARG (dir);
  ACE_UNUSED_ARG (pfx);
  ACE_NOTSUP_RETURN (0);
#elif defined (ACE_HAS_NONCONST_TEMPNAM)
  ACE_OSCALL_RETURN (ACE_STD_NAMESPACE::tempnam (const_cast <char *> (dir), const_cast<char *> (pfx)), char *, 0);
#else /* ACE_LACKS_TEMPNAM */
  ACE_OSCALL_RETURN (ACE_STD_NAMESPACE::tempnam (dir, pfx), char *, 0);
#endif /* ACE_LACKS_TEMPNAM */
}

#if defined (ACE_HAS_WCHAR)
ACE_INLINE wchar_t *
ACE_OS::tempnam (const wchar_t *dir, const wchar_t *pfx)
{
  ACE_OS_TRACE ("ACE_OS::tempnam");
#if defined (ACE_LACKS_TEMPNAM)
  ACE_UNUSED_ARG (dir);
  ACE_UNUSED_ARG (pfx);
  ACE_NOTSUP_RETURN (0);
#elif defined(ACE_WIN32)
#  if defined (ACE_HAS_NONCONST_TEMPNAM)
  ACE_OSCALL_RETURN (::_wtempnam (const_cast <wchar_t*> (dir), const_cast <wchar_t*> (pfx)), wchar_t *, 0);
#  else
  ACE_OSCALL_RETURN (::_wtempnam (dir, pfx), wchar_t *, 0);
#  endif /* __BORLANDC__ */
#else /* ACE_LACKS_TEMPNAM */
  // No native wide-char support; convert to narrow and call the char* variant.
  char *ndir = ACE_Wide_To_Ascii (dir).char_rep ();
  char *npfx = ACE_Wide_To_Ascii (pfx).char_rep ();
  char *name = ACE_OS::tempnam (ndir, npfx);
  // ACE_OS::tempnam returns a pointer to a malloc()-allocated space.
  // Convert that string to wide-char and free() the original.
  wchar_t *wname = 0;
  if (name != 0)
    {
      size_t namelen = ACE_OS::strlen (name) + 1;
      wname = reinterpret_cast<wchar_t *>
        (ACE_OS::malloc (namelen * sizeof (wchar_t)));
      if (wname != 0)
        ACE_OS::strcpy (wname, ACE_Ascii_To_Wide (name).wchar_rep ());
      ACE_OS::free (name);
    }
  return wname;
#endif /* ACE_LACKS_TEMPNAM */
}
#endif /* ACE_HAS_WCHAR */

ACE_INLINE int
ACE_OS::vasprintf (char **bufp, const char* format, va_list argptr)
{
#if defined (ACE_HAS_VASPRINTF)
  return ::vasprintf (bufp, format, argptr);
#else
  return ACE_OS::vasprintf_emulation (bufp, format, argptr);
#endif /* ACE_HAS_VASPRINTF */
}

#if defined (ACE_HAS_WCHAR)
ACE_INLINE int
ACE_OS::vasprintf (wchar_t **bufp, const wchar_t* format, va_list argptr)
{
#if defined (ACE_HAS_VASWPRINTF)
  return ::vaswprintf (bufp, format, argptr);
#else
  return ACE_OS::vaswprintf_emulation (bufp, format, argptr);
#endif /* ACE_HAS_VASWPRINTF */
}
#endif /* ACE_HAS_WCHAR */

ACE_INLINE int
ACE_OS::vprintf (const char *format, va_list argptr)
{
  return ::vprintf (format, argptr);
}

#if defined (ACE_HAS_WCHAR)
ACE_INLINE int
ACE_OS::vprintf (const wchar_t *format, va_list argptr)
{
#if defined (ACE_HAS_VWPRINTF)
  return ::vwprintf (format, argptr);
#else
  ACE_UNUSED_ARG (format);
  ACE_UNUSED_ARG (argptr);
  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_HAS_VWPRINTF */
}
#endif /* ACE_HAS_WCHAR */

ACE_INLINE int
ACE_OS::vfprintf (FILE *fp, const char *format, va_list argptr)
{
  return ACE_STD_NAMESPACE::vfprintf (fp, format, argptr);
}

#if defined (ACE_HAS_WCHAR)
ACE_INLINE int
ACE_OS::vfprintf (FILE *fp, const wchar_t *format, va_list argptr)
{
#if defined (ACE_HAS_VFWPRINTF)
  return ::vfwprintf (fp, format, argptr);
#else
  ACE_UNUSED_ARG (fp);
  ACE_UNUSED_ARG (format);
  ACE_UNUSED_ARG (argptr);
  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_HAS_VFWPRINTF */
}
#endif /* ACE_HAS_WCHAR */

ACE_INLINE int
ACE_OS::vsprintf (char *buffer, const char *format, va_list argptr)
{
  return ::vsprintf (buffer, format, argptr);
}

#if defined (ACE_HAS_WCHAR)
ACE_INLINE int
ACE_OS::vsprintf (wchar_t *buffer, const wchar_t *format, va_list argptr)
{
# if (defined _XOPEN_SOURCE && (_XOPEN_SOURCE - 0) >= 500) || \
     (defined (sun) && !(defined(_XOPEN_SOURCE) && (_XOPEN_VERSION-0==4))) || \
      defined (ACE_HAS_DINKUM_STL) || defined (__DMC__) || \
      defined (ACE_HAS_VSWPRINTF) || defined (ACE_WIN32_VC9) || \
     (defined (ACE_WIN32_VC8) && !defined (ACE_HAS_WINCE) && \
      _MSC_FULL_VER > 140050000)

  // The XPG4/UNIX98/C99 signature of the wide-char sprintf has a
  // maxlen argument. Since this method doesn't supply one, pass in
  // a length that works (ULONG_MAX doesn't on all platform since some check
  // to see if the operation will remain in bounds). If this isn't ok, use
  // ACE_OS::snprintf().
  return vswprintf (buffer, 4096, format, argptr);

# elif defined (ACE_WIN32)
  // Windows has vswprintf, but the pre-VC8 signature is from the older
  // ISO C standard. Also see ACE_OS::snprintf() for more info on this.

  return vswprintf (buffer, format, argptr);

# else
  ACE_UNUSED_ARG (buffer);
  ACE_UNUSED_ARG (format);
  ACE_UNUSED_ARG (argptr);
  ACE_NOTSUP_RETURN (-1);

# endif /* XPG5 || ACE_HAS_DINKUM_STL */
}
#endif /* ACE_HAS_WCHAR */

ACE_INLINE int
ACE_OS::vsnprintf (char *buffer, size_t maxlen, const char *format, va_list ap)
{
#if !defined (ACE_LACKS_VSNPRINTF)
  int result;
#  if 0 /* defined (ACE_HAS_TR24731_2005_CRT) */
  // _vsnprintf_s() doesn't report the length needed when it truncates. This
  // info is needed and relied on by others things in ACE+TAO, so don't use
  // this. There's adequate protection via the maxlen.
  result = _vsnprintf_s (buffer, maxlen, _TRUNCATE, format, ap);
#  elif !defined (ACE_WIN32)
  result = ::vsnprintf (buffer, maxlen, format, ap);
#  else
  result = ::_vsnprintf (buffer, maxlen, format, ap);

  // Win32 doesn't regard a full buffer with no 0-terminate as an overrun.
  if (result == static_cast<int> (maxlen))
    buffer[maxlen-1] = '\0';

  // Win32 doesn't 0-terminate the string if it overruns maxlen.
  if (result == -1)
    buffer[maxlen-1] = '\0';
# endif
  // In out-of-range conditions, C99 defines vsnprintf() to return the number
  // of characters that would have been written if enough space was available.
  // Earlier variants of the vsnprintf() (e.g. UNIX98) defined it to return
  // -1. This method follows the C99 standard, but needs to guess at the
  // value; uses maxlen + 1.
  if (result == -1)
    {
      result = static_cast <int> (maxlen + 1);
    }

  return result;
#elif defined (ACE_HAS_TRIO)
  return trio_vsnprintf (buffer, maxlen, format, ap);
#else
  ACE_UNUSED_ARG (buffer);
  ACE_UNUSED_ARG (maxlen);
  ACE_UNUSED_ARG (format);
  ACE_UNUSED_ARG (ap);
  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_LACKS_VSNPRINTF */
}

#if defined (ACE_HAS_WCHAR)
ACE_INLINE int
ACE_OS::vsnprintf (wchar_t *buffer, size_t maxlen, const wchar_t *format, va_list ap)
{
# if (defined _XOPEN_SOURCE && (_XOPEN_SOURCE - 0) >= 500) || \
     (defined (sun) && !(defined(_XOPEN_SOURCE) && (_XOPEN_VERSION-0==4))) || \
     (defined (ACE_HAS_DINKUM_STL) || defined (__DMC__)) || \
      defined (ACE_HAS_VSWPRINTF) || \
      defined (ACE_WIN32)

  int result;

# if defined (ACE_WIN32)
  // Microsoft's vswprintf() doesn't have the maxlen argument that
  // XPG4/UNIX98 define. They do, however, recommend use of _vsnwprintf()
  // as a substitute, which does have the same signature as the UNIX98 one.
  result = ::_vsnwprintf (buffer, maxlen, format, ap);

  // Win32 doesn't regard a full buffer with no 0-terminate as an overrun.
  if (result == static_cast<int> (maxlen))
    buffer[maxlen-1] = '\0';

  // Win32 doesn't 0-terminate the string if it overruns maxlen.
  if (result == -1)
    buffer[maxlen-1] = '\0';
# else
  result = vswprintf (buffer, maxlen, format, ap);
#endif

  // In out-of-range conditions, C99 defines vsnprintf() to return the number
  // of characters that would have been written if enough space was available.
  // Earlier variants of the vsnprintf() (e.g. UNIX98) defined it to return
  // -1. This method follows the C99 standard, but needs to guess at the
  // value; uses maxlen + 1.
  if (result == -1)
    {
      result = static_cast <int> (maxlen + 1);
    }

  return result;

# else

  ACE_UNUSED_ARG (buffer);
  ACE_UNUSED_ARG (maxlen);
  ACE_UNUSED_ARG (format);
  ACE_UNUSED_ARG (ap);
  ACE_NOTSUP_RETURN (-1);

# endif /* platforms with a variant of vswprintf */
}
#endif /* ACE_HAS_WCHAR */

#if defined (ACE_MT_SAFE) && (ACE_MT_SAFE != 0)
#if defined (ACE_WIN32)
ACE_INLINE const ACE_TEXT_OSVERSIONINFO &
ACE_OS::get_win32_versioninfo ()
{
  return ACE_OS::win32_versioninfo_;
}

ACE_INLINE HINSTANCE
ACE_OS::get_win32_resource_module ()
{
  return ACE_OS::win32_resource_module_;
}

ACE_INLINE void
ACE_OS::set_win32_resource_module (HINSTANCE instance)
{
  ACE_OS::win32_resource_module_ = instance;
}

ACE_INLINE LPSECURITY_ATTRIBUTES
ACE_OS::default_win32_security_attributes (LPSECURITY_ATTRIBUTES sa)
{
#if defined (ACE_DEFINES_DEFAULT_WIN32_SECURITY_ATTRIBUTES)
  if (sa == 0)
    {
      // @@ This is a good place to use pthread_once.
      static SECURITY_ATTRIBUTES default_sa;
      static SECURITY_DESCRIPTOR sd;
      InitializeSecurityDescriptor(&sd, SECURITY_DESCRIPTOR_REVISION);
      SetSecurityDescriptorDacl(&sd, TRUE, 0, FALSE);
      default_sa.nLength = sizeof(SECURITY_ATTRIBUTES);
      default_sa.lpSecurityDescriptor = &sd;
      default_sa.bInheritHandle       = TRUE;
      sa = &default_sa;
    }
  return sa;
#else /* !ACE_DEFINES_DEFAULT_WIN32_SECURITY_ATTRIBUTES */
  return sa;
#endif /* ACE_DEFINES_DEFAULT_WIN32_SECURITY_ATTRIBUTES */
}

ACE_INLINE LPSECURITY_ATTRIBUTES
ACE_OS::default_win32_security_attributes_r (LPSECURITY_ATTRIBUTES sa,
                                             LPSECURITY_ATTRIBUTES sa_buffer,
                                             SECURITY_DESCRIPTOR* sd_buffer)
{
#if defined (ACE_DEFINES_DEFAULT_WIN32_SECURITY_ATTRIBUTES)
  if (sa == 0)
    {
      if (sa_buffer != 0 && sd_buffer != 0)
        {
          InitializeSecurityDescriptor
            (sd_buffer, SECURITY_DESCRIPTOR_REVISION);
          SetSecurityDescriptorDacl (sd_buffer, TRUE, 0, FALSE);
          sa_buffer->nLength = sizeof(SECURITY_ATTRIBUTES);
          sa_buffer->lpSecurityDescriptor = sd_buffer;
          sa_buffer->bInheritHandle       = TRUE;
          sa = sa_buffer;
        }
    }
  return sa;
#else /* !ACE_DEFINES_DEFAULT_WIN32_SECURITY_ATTRIBUTES */
  ACE_UNUSED_ARG(sa_buffer);
  ACE_UNUSED_ARG(sd_buffer);
  return sa;
#endif /* ACE_DEFINES_DEFAULT_WIN32_SECURITY_ATTRIBUTES */
}

#endif /* ACE_WIN32 */
#endif

ACE_END_VERSIONED_NAMESPACE_DECL
