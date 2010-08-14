// $Id: ACE.cpp 91066 2010-07-12 11:05:04Z johnnyw $

#include "ace/ACE.h"

#include "ace/Basic_Types.h"
#include "ace/Handle_Set.h"
#include "ace/Auto_Ptr.h"
#include "ace/SString.h"
#include "ace/Version.h"
#include "ace/Message_Block.h"
#include "ace/Log_Msg.h"
#include "ace/OS_NS_sys_select.h"
#include "ace/OS_NS_string.h"
#include "ace/OS_NS_strings.h"
#include "ace/OS_NS_signal.h"
#include "ace/OS_NS_stdio.h"
#include "ace/OS_NS_sys_resource.h"
#include "ace/OS_NS_sys_wait.h"
#include "ace/OS_NS_sys_time.h"
#include "ace/OS_NS_time.h"
#include "ace/OS_NS_sys_uio.h"
#include "ace/OS_NS_sys_stat.h"
#include "ace/OS_NS_ctype.h"
#include "ace/OS_NS_fcntl.h"
#include "ace/OS_TLI.h"
#include "ace/Truncate.h"

#if defined (ACE_VXWORKS) && (ACE_VXWORKS < 0x620)
extern "C" int maxFiles;
#endif /* ACE_VXWORKS */

#if !defined (__ACE_INLINE__)
#include "ace/ACE.inl"
#endif /* __ACE_INLINE__ */

#if defined (ACE_HAS_POLL) && defined (ACE_HAS_LIMITED_SELECT)
#  include "ace/OS_NS_poll.h"
#endif /* ACE_HAS_POLL  && ACE_HAS_LIMITED_SELECT */


ACE_RCSID (ace,
           ACE,
           "$Id: ACE.cpp 91066 2010-07-12 11:05:04Z johnnyw $")


// Open versioned namespace, if enabled by the user.
  ACE_BEGIN_VERSIONED_NAMESPACE_DECL

namespace ACE
{
  // private:
  //  Used internally so not exported.

  // Size of allocation granularity.
  size_t allocation_granularity_ = 0;

  // Size of a VM page.
  size_t pagesize_ = 0;

  // Are we debugging ACE?
  // Keeps track of whether we're in some global debug mode.
  char debug_;
}


int
ACE::out_of_handles (int error)
{
  // EMFILE is common to all platforms.
  if (error == EMFILE ||
#if defined (ACE_WIN32)
      // On Win32, we need to check for ENOBUFS also.
      error == ENOBUFS ||
#elif defined (HPUX)
      // On HPUX, we need to check for EADDRNOTAVAIL also.
      error == EADDRNOTAVAIL ||
#elif defined (linux)
      // On linux, we need to check for ENOENT also.
      error == ENOENT ||
      // For RedHat5.2, need to check for EINVAL too.
      error == EINVAL ||
      // Without threads check for EOPNOTSUPP
      error == EOPNOTSUPP ||
#elif defined (sun)
      // On sun, we need to check for ENOSR also.
      error == ENOSR ||
      // Without threads check for ENOTSUP
      error == ENOTSUP ||
#elif defined (__FreeBSD__)
      // On FreeBSD we need to check for EOPNOTSUPP (LinuxThreads) or
      // ENOSYS (libc_r threads) also.
      error == EOPNOTSUPP ||
      error == ENOSYS ||
#elif defined (__OpenBSD__)
      // OpenBSD appears to return EBADF.
      error == EBADF ||
#elif defined (__sgi) // irix
      error == ENOTSUP ||
#elif defined (DIGITAL_UNIX) // osf1
      error == ENOTSUP ||
#endif /* ACE_WIN32 */
      error == ENFILE)
    return 1;
  else
    return 0;
}

u_int
ACE::major_version (void)
{
  return ACE_MAJOR_VERSION;
}

u_int
ACE::minor_version (void)
{
  return ACE_MINOR_VERSION;
}

u_int
ACE::beta_version (void)
{
  return ACE_BETA_VERSION;
}

const ACE_TCHAR *
ACE::compiler_name (void)
{
#ifdef ACE_CC_NAME
  return ACE_CC_NAME;
#else
  return ACE_TEXT ("");
#endif
}

u_int
ACE::compiler_major_version (void)
{
#ifdef ACE_CC_MAJOR_VERSION
  return ACE_CC_MAJOR_VERSION;
#else
  return 0;
#endif
}

u_int
ACE::compiler_minor_version (void)
{
#ifdef ACE_CC_MINOR_VERSION
  return ACE_CC_MINOR_VERSION;
#else
  return 0;
#endif
}

u_int
ACE::compiler_beta_version (void)
{
#ifdef ACE_CC_BETA_VERSION
  return ACE_CC_BETA_VERSION;
#else
  return 0;
#endif
}

ACE_TCHAR
ACE::nibble2hex (u_int n)
{
  // Yes, this works for UNICODE
  return ACE_TEXT ("0123456789abcdef")[n & 0x0f];
}

bool
ACE::debug (void)
{
  static const char* debug = ACE_OS::getenv ("ACE_DEBUG");
  return (ACE::debug_ != 0) ? ACE::debug_ : (debug != 0 ? (*debug != '0') : false);
}

void
ACE::debug (bool onoff)
{
  ACE::debug_ = onoff;
}

int
ACE::select (int width,
             ACE_Handle_Set *readfds,
             ACE_Handle_Set *writefds,
             ACE_Handle_Set *exceptfds,
             const ACE_Time_Value *timeout)
{
  int result = ACE_OS::select (width,
                               readfds ? readfds->fdset () : 0,
                               writefds ? writefds->fdset () : 0,
                               exceptfds ? exceptfds->fdset () : 0,
                               timeout);
  if (result > 0)
    {
# if !defined (ACE_WIN32)
      // This isn't needed for Windows... it's a no-op anyway.
      if (readfds)
        readfds->sync ((ACE_HANDLE) width);
      if (writefds)
        writefds->sync ((ACE_HANDLE) width);
      if (exceptfds)
        exceptfds->sync ((ACE_HANDLE) width);
#endif /* ACE_WIN32 */
    }
  return result;
}

int
ACE::select (int width,
             ACE_Handle_Set &readfds,
             const ACE_Time_Value *timeout)
{
  int result = ACE_OS::select (width,
                               readfds.fdset (),
                               0,
                               0,
                               timeout);

#if !defined (ACE_WIN32)
  if (result > 0)
    readfds.sync ((ACE_HANDLE) width);
#endif /* ACE_WIN32 */
  return result;
}

int
ACE::terminate_process (pid_t pid)
{
#if defined (ACE_HAS_PHARLAP)
  ACE_UNUSED_ARG (pid);
  ACE_NOTSUP_RETURN (-1);
#elif defined (ACE_WIN32)
  // Create a handle for the given process id.
  ACE_HANDLE process_handle =
    ::OpenProcess (PROCESS_TERMINATE,
                   FALSE, // New handle is not inheritable.
                   pid);

  if (process_handle == ACE_INVALID_HANDLE
      || process_handle == 0)
    return -1;
  else
    {
      // Kill the process associated with process_handle.
      BOOL terminate_result =
        ::TerminateProcess (process_handle, 0);
      // Free up the kernel resources.
      ACE_OS::close (process_handle);
      return terminate_result ? 0 : -1;
    }
#else
  return ACE_OS::kill (pid, 9);
#endif /* ACE_HAS_PHARLAP */
}

int
ACE::process_active (pid_t pid)
{
#if !defined(ACE_WIN32)
  if (ACE_OS::kill (pid, 0) == 0)
    return 1;
  else if (errno == ESRCH)
    return 0;
  else
    return -1;
#else
  // Create a handle for the given process id.
  ACE_HANDLE process_handle =
    ::OpenProcess (PROCESS_QUERY_INFORMATION, FALSE, pid);
  if (process_handle == ACE_INVALID_HANDLE || process_handle == 0)
    return 0;
  else
    {
      DWORD status;
      int result = 1;
      if (::GetExitCodeProcess (process_handle,
                                &status) == 0
          || status != STILL_ACTIVE)
        result = 0;

      ::CloseHandle (process_handle);
      return result;
    }
#endif /* !ACE_WIN32 */
}

const ACE_TCHAR *
ACE::execname (const ACE_TCHAR *old_name)
{
#if defined (ACE_WIN32)
  const ACE_TCHAR *suffix = ACE_OS::strrchr (old_name, ACE_TEXT ('.'));
  if (suffix == 0 || ACE_OS::strcasecmp (suffix, ACE_TEXT (".exe")) != 0)
    {
      ACE_TCHAR *new_name = 0;

      size_t size =
        ACE_OS::strlen (old_name)
        + ACE_OS::strlen (ACE_TEXT (".exe"))
        + 1;

      ACE_NEW_RETURN (new_name,
                      ACE_TCHAR[size],
                      0);
      ACE_TCHAR *end = new_name;

      end = ACE_OS::strecpy (new_name, old_name);

      // Concatenate the .exe suffix onto the end of the executable.
      // end points _after_ the terminating nul.
      ACE_OS::strcpy (end - 1, ACE_TEXT (".exe"));

      return new_name;
    }
#endif /* ACE_WIN32 */
  return old_name;
}

u_long
ACE::hash_pjw (const char *str, size_t len)
{
  u_long hash = 0;

  for (size_t i = 0; i < len; i++)
    {
      const char temp = str[i];
      hash = (hash << 4) + (temp * 13);

      u_long g = hash & 0xf0000000;

      if (g)
        {
          hash ^= (g >> 24);
          hash ^= g;
        }
    }

  return hash;
}

u_long
ACE::hash_pjw (const char *str)
{
  return ACE::hash_pjw (str, ACE_OS::strlen (str));
}

#if defined (ACE_HAS_WCHAR)
u_long
ACE::hash_pjw (const wchar_t *str, size_t len)
{
  u_long hash = 0;

  for (size_t i = 0; i < len; i++)
    {
      // @@ UNICODE: Does this function do the correct thing with wchar's?

      const wchar_t temp = str[i];
      hash = (hash << 4) + (temp * 13);

      u_long g = hash & 0xf0000000;

      if (g)
        {
          hash ^= (g >> 24);
          hash ^= g;
        }
    }

  return hash;
}

u_long
ACE::hash_pjw (const wchar_t *str)
{
  return ACE::hash_pjw (str, ACE_OS::strlen (str));
}
#endif /* ACE_HAS_WCHAR */

ACE_TCHAR *
ACE::strenvdup (const ACE_TCHAR *str)
{
  ACE_TRACE ("ACE::strenvdup");

  return ACE_OS::strenvdup (str);
}

/*

Examples:

Source               NT                    UNIX
==================================================================
netsvc               netsvc.dll            libnetsvc.so
(PATH will be         (LD_LIBRARY_PATH
evaluated)            evaluated)

libnetsvc.dll        libnetsvc.dll         libnetsvc.dll + warning
netsvc.so            netsvc.so + warning   libnetsvc.so

..\../libs/netsvc    ..\..\libs\netsvc.dll ../../libs/netsvc.so
(absolute path used)  (absolute path used)

*/

const ACE_TCHAR *
ACE::basename (const ACE_TCHAR *pathname, ACE_TCHAR delim)
{
  ACE_TRACE ("ACE::basename");
  const ACE_TCHAR *temp = ACE_OS::strrchr (pathname, delim);

  if (temp == 0)
    return pathname;
  else
    return temp + 1;
}

const ACE_TCHAR *
ACE::dirname (const ACE_TCHAR *pathname, ACE_TCHAR delim)
{
  ACE_TRACE ("ACE::dirname");
  static ACE_TCHAR return_dirname[MAXPATHLEN + 1];

  const ACE_TCHAR *temp = ACE_OS::strrchr (pathname, delim);

  if (temp == 0)
    {
      return_dirname[0] = '.';
      return_dirname[1] = '\0';

      return return_dirname;
    }
  else
    {
      // When the len is truncated, there are problems!  This should
      // not happen in normal circomstances
      size_t len = temp - pathname + 1;
      if (len > (sizeof return_dirname / sizeof (ACE_TCHAR)))
        len = sizeof return_dirname / sizeof (ACE_TCHAR);

      ACE_OS::strsncpy (return_dirname,
                        pathname,
                        len);
      return return_dirname;
    }
}

ssize_t
ACE::recv (ACE_HANDLE handle,
           void *buf,
           size_t len,
           int flags,
           const ACE_Time_Value *timeout)
{
  if (timeout == 0)
    return ACE_OS::recv (handle, (char *) buf, len, flags);
  else
    {
      int val = 0;
      if (ACE::enter_recv_timedwait (handle, timeout, val) ==-1)
        return -1;
      else
        {
          ssize_t bytes_transferred =
            ACE_OS::recv (handle, (char *) buf, len, flags);
          ACE::restore_non_blocking_mode (handle, val);
          return bytes_transferred;
        }
    }
}

#if defined (ACE_HAS_TLI)

ssize_t
ACE::t_rcv (ACE_HANDLE handle,
            void *buf,
            size_t len,
            int *flags,
            const ACE_Time_Value *timeout)
{
  if (timeout == 0)
    return ACE_OS::t_rcv (handle, (char *) buf, len, flags);
  else
    {
      int val = 0;
      if (ACE::enter_recv_timedwait (handle, timeout, val) ==-1)
        return -1;
      else
        {
          ssize_t bytes_transferred =
            ACE_OS::t_rcv (handle, (char *) buf, len, flags);
          ACE::restore_non_blocking_mode (handle, val);
          return bytes_transferred;
        }
    }
}

#endif /* ACE_HAS_TLI */

ssize_t
ACE::recv (ACE_HANDLE handle,
           void *buf,
           size_t n,
           const ACE_Time_Value *timeout)
{
  if (timeout == 0)
    return ACE::recv_i (handle, buf, n);
  else
    {
      int val = 0;
      if (ACE::enter_recv_timedwait (handle, timeout, val) == -1)
        return -1;
      else
        {
          ssize_t bytes_transferred = ACE::recv_i (handle, buf, n);
          ACE::restore_non_blocking_mode (handle, val);
          return bytes_transferred;
        }
    }
}

ssize_t
ACE::recvmsg (ACE_HANDLE handle,
              struct msghdr *msg,
              int flags,
              const ACE_Time_Value *timeout)
{
  if (timeout == 0)
    return ACE_OS::recvmsg (handle, msg, flags);
  else
    {
      int val = 0;
      if (ACE::enter_recv_timedwait (handle, timeout, val) == -1)
        return -1;
      else
        {
          ssize_t bytes_transferred = ACE_OS::recvmsg (handle, msg, flags);
          ACE::restore_non_blocking_mode (handle, val);
          return bytes_transferred;
        }
    }
}

ssize_t
ACE::recvfrom (ACE_HANDLE handle,
               char *buf,
               int len,
               int flags,
               struct sockaddr *addr,
               int *addrlen,
               const ACE_Time_Value *timeout)
{
  if (timeout == 0)
    return ACE_OS::recvfrom (handle, buf, len, flags, addr, addrlen);
  else
    {
      int val = 0;
      if (ACE::enter_recv_timedwait (handle, timeout, val) == -1)
        return -1;
      else
        {
          ssize_t bytes_transferred =
            ACE_OS::recvfrom (handle, buf, len, flags, addr, addrlen);
          ACE::restore_non_blocking_mode (handle, val);
          return bytes_transferred;
        }
    }
}

ssize_t
ACE::recv_n_i (ACE_HANDLE handle,
               void *buf,
               size_t len,
               int flags,
               size_t *bt)
{
  size_t temp;
  size_t &bytes_transferred = bt == 0 ? temp : *bt;
  ssize_t n;

  for (bytes_transferred = 0;
       bytes_transferred < len;
       bytes_transferred += n)
    {
      // Try to transfer as much of the remaining data as possible.
      n = ACE_OS::recv (handle,
                        static_cast <char *> (buf) + bytes_transferred,
                        len - bytes_transferred,
                        flags);
      // Check EOF.
      if (n == 0)
        return 0;

      // Check for other errors.
      if (n == -1)
        {
          // Check for possible blocking.
          if (errno == EWOULDBLOCK)
            {
              // Wait for the blocking to subside.
              int const result = ACE::handle_read_ready (handle, 0);

              // Did select() succeed?
              if (result != -1)
                {
                  // Blocking subsided.  Continue data transfer.
                  n = 0;
                  continue;
                }
            }

          // Other data transfer or select() failures.
          return -1;
        }
    }

  return static_cast<ssize_t> (bytes_transferred);
}

ssize_t
ACE::recv_n_i (ACE_HANDLE handle,
               void *buf,
               size_t len,
               int flags,
               const ACE_Time_Value *timeout,
               size_t *bt)
{
  size_t temp;
  size_t &bytes_transferred = bt == 0 ? temp : *bt;
  ssize_t n;
  ssize_t result = 0;
  int error = 0;

  int val = 0;
  ACE::record_and_set_non_blocking_mode (handle, val);

  for (bytes_transferred = 0;
       bytes_transferred < len;
       bytes_transferred += n)
    {
      // Try to transfer as much of the remaining data as possible.
      // Since the socket is in non-blocking mode, this call will not
      // block.
      n = ACE_OS::recv (handle,
                        static_cast <char *> (buf) + bytes_transferred,
                        len - bytes_transferred,
                        flags);

      // Check for errors.
      if (n == 0 ||
          n == -1)
        {
          // Check for possible blocking.
          if (n == -1 &&
              errno == EWOULDBLOCK)
            {
              // Wait upto <timeout> for the blocking to subside.
              int const rtn = ACE::handle_read_ready (handle, timeout);

              // Did select() succeed?
              if (rtn != -1)
                {
                  // Blocking subsided in <timeout> period.  Continue
                  // data transfer.
                  n = 0;
                  continue;
                }
            }

          // Wait in select() timed out or other data transfer or
          // select() failures.
          error = 1;
          result = n;
          break;
        }
    }

  ACE::restore_non_blocking_mode (handle, val);

  if (error)
    return result;
  else
    return static_cast<ssize_t> (bytes_transferred);
}

#if defined (ACE_HAS_TLI)

ssize_t
ACE::t_rcv_n_i (ACE_HANDLE handle,
                void *buf,
                size_t len,
                int *flags,
                size_t *bt)
{
  size_t temp;
  size_t &bytes_transferred = bt == 0 ? temp : *bt;
  ssize_t n;

  for (bytes_transferred = 0;
       bytes_transferred < len;
       bytes_transferred += n)
    {
      // Try to transfer as much of the remaining data as possible.
      n = ACE_OS::t_rcv (handle,
                         (char *) buf + bytes_transferred,
                         len - bytes_transferred,
                         flags);
      // Check EOF.
      if (n == 0)
        return 0;

      // Check for other errors.
      if (n == -1)
        {
          // Check for possible blocking.
          if (errno == EWOULDBLOCK)
            {
              // Wait for the blocking to subside.
              int const result = ACE::handle_read_ready (handle, 0);

              // Did select() succeed?
              if (result != -1)
                {
                  // Blocking subsided.  Continue data transfer.
                  n = 0;
                  continue;
                }
            }

          // Other data transfer or select() failures.
          return -1;
        }
    }

  return bytes_transferred;
}

ssize_t
ACE::t_rcv_n_i (ACE_HANDLE handle,
                void *buf,
                size_t len,
                int *flags,
                const ACE_Time_Value *timeout,
                size_t *bt)
{
  size_t temp;
  size_t &bytes_transferred = bt == 0 ? temp : *bt;
  ssize_t n;
  ssize_t result = 0;
  int error = 0;

  int val = 0;
  ACE::record_and_set_non_blocking_mode (handle, val);

  for (bytes_transferred = 0;
       bytes_transferred < len;
       bytes_transferred += n)
    {
      // Try to transfer as much of the remaining data as possible.
      // Since the socket is in non-blocking mode, this call will not
      // block.
      n = ACE_OS::t_rcv (handle,
                         (char *) buf + bytes_transferred,
                         len - bytes_transferred,
                         flags);

      // Check for errors.
      if (n == 0 ||
          n == -1)
        {
          // Check for possible blocking.
          if (n == -1 &&
              errno == EWOULDBLOCK)
            {
              // Wait upto <timeout> for the blocking to subside.
              int const rtn = ACE::handle_read_ready (handle, timeout);

              // Did select() succeed?
              if (rtn != -1)
                {
                  // Blocking subsided in <timeout> period.  Continue
                  // data transfer.
                  n = 0;
                  continue;
                }
            }

          // Wait in select() timed out or other data transfer or
          // select() failures.
          error = 1;
          result = n;
          break;
        }
    }

  ACE::restore_non_blocking_mode (handle, val);

  if (error)
    return result;
  else
    return bytes_transferred;
}

#endif /* ACE_HAS_TLI */

ssize_t
ACE::recv_n_i (ACE_HANDLE handle,
               void *buf,
               size_t len,
               size_t *bt)
{
  size_t temp;
  size_t &bytes_transferred = bt == 0 ? temp : *bt;
  ssize_t n;

  for (bytes_transferred = 0;
       bytes_transferred < len;
       bytes_transferred += n)
    {
      // Try to transfer as much of the remaining data as possible.
      n = ACE::recv_i (handle,
                       static_cast <char *> (buf) + bytes_transferred,
                       len - bytes_transferred);
      // Check EOF.
      if (n == 0)
        {
          return 0;
        }
      // Check for other errors.
      if (n == -1)
        {
          // Check for possible blocking.
          if (errno == EWOULDBLOCK)
            {
              // Wait for the blocking to subside.
              int const result = ACE::handle_read_ready (handle, 0);

              // Did select() succeed?
              if (result != -1)
                {
                  // Blocking subsided.  Continue data transfer.
                  n = 0;
                  continue;
                }
            }

          // Other data transfer or select() failures.
          return -1;
        }
    }

  return static_cast<ssize_t> (bytes_transferred);
}

ssize_t
ACE::recv_n_i (ACE_HANDLE handle,
               void *buf,
               size_t len,
               const ACE_Time_Value *timeout,
               size_t *bt)
{
  size_t temp;
  size_t &bytes_transferred = bt == 0 ? temp : *bt;
  ssize_t n;
  ssize_t result = 0;
  int error = 0;

  int val = 0;
  ACE::record_and_set_non_blocking_mode (handle, val);

  for (bytes_transferred = 0;
       bytes_transferred < len;
       bytes_transferred += n)
    {
      // Try to transfer as much of the remaining data as possible.
      // Since the socket is in non-blocking mode, this call will not
      // block.
      n = ACE::recv_i (handle,
                       static_cast <char *> (buf) + bytes_transferred,
                       len - bytes_transferred);

      // Check for errors.
      if (n == 0 ||
          n == -1)
        {
          // Check for possible blocking.
          if (n == -1 &&
              errno == EWOULDBLOCK)
            {
              // Wait upto <timeout> for the blocking to subside.
              int const rtn = ACE::handle_read_ready (handle, timeout);

              // Did select() succeed?
              if (rtn != -1)
                {
                  // Blocking subsided in <timeout> period.  Continue
                  // data transfer.
                  n = 0;
                  continue;
                }
            }

          // Wait in select() timed out or other data transfer or
          // select() failures.
          error = 1;
          result = n;
          break;
        }
    }

  ACE::restore_non_blocking_mode (handle, val);

  if (error)
    return result;
  else
    return static_cast<ssize_t> (bytes_transferred);
}

// This is basically an interface to ACE_OS::readv, that doesn't use
// the struct iovec explicitly.  The ... can be passed as an arbitrary
// number of (char *ptr, int len) tuples.  However, the count N is the
// *total* number of trailing arguments, *not* a couple of the number
// of tuple pairs!

ssize_t
ACE::recv (ACE_HANDLE handle, size_t n, ...)
{
  va_list argp;
  int const total_tuples = static_cast<int> (n / 2);
  iovec *iovp = 0;
#if defined (ACE_HAS_ALLOCA)
  iovp = (iovec *) alloca (total_tuples * sizeof (iovec));
#else
  ACE_NEW_RETURN (iovp,
                  iovec[total_tuples],
                  -1);
#endif /* !defined (ACE_HAS_ALLOCA) */

  va_start (argp, n);

  for (int i = 0; i < total_tuples; i++)
    {
      iovp[i].iov_base = va_arg (argp, char *);
      iovp[i].iov_len = va_arg (argp, int);
    }

  ssize_t const result = ACE_OS::recvv (handle, iovp, total_tuples);
#if !defined (ACE_HAS_ALLOCA)
  delete [] iovp;
#endif /* !defined (ACE_HAS_ALLOCA) */
  va_end (argp);
  return result;
}

ssize_t
ACE::recvv (ACE_HANDLE handle,
            iovec *iov,
            int iovcnt,
            const ACE_Time_Value *timeout)
{
  if (timeout == 0)
    return ACE_OS::recvv (handle, iov, iovcnt);
  else
    {
      int val = 0;
      if (ACE::enter_recv_timedwait (handle, timeout, val) == -1)
        return -1;
      else
        {
          ssize_t bytes_transferred = ACE_OS::recvv (handle, iov, iovcnt);
          ACE::restore_non_blocking_mode (handle, val);
          return bytes_transferred;
        }
    }
}

ssize_t
ACE::recvv_n_i (ACE_HANDLE handle,
                iovec *iov,
                int iovcnt,
                size_t *bt)
{
  size_t temp;
  size_t &bytes_transferred = bt == 0 ? temp : *bt;
  bytes_transferred = 0;

  for (int s = 0; s < iovcnt; )
    {
      // Try to transfer as much of the remaining data as possible.
      ssize_t n = ACE_OS::recvv (handle, iov + s, iovcnt - s);
      // Check EOF.
      if (n == 0)
        return 0;

      // Check for other errors.
      if (n == -1)
        {
          // Check for possible blocking.
          if (errno == EWOULDBLOCK)
            {
              // Wait for the blocking to subside.
              int const result = ACE::handle_read_ready (handle, 0);

              // Did select() succeed?
              if (result != -1)
                {
                  // Blocking subsided.  Continue data transfer.
                  n = 0;
                  continue;
                }
            }

          // Other data transfer or select() failures.
          return -1;
        }

      for (bytes_transferred += n;
           s < iovcnt
             && n >= static_cast<ssize_t> (iov[s].iov_len);
           s++)
        n -= iov[s].iov_len;

      if (n != 0)
        {
          char *base = static_cast<char *> (iov[s].iov_base);
          iov[s].iov_base = base + n;
          iov[s].iov_len = iov[s].iov_len - n;
        }
    }

  return ACE_Utils::truncate_cast<ssize_t> (bytes_transferred);
}

ssize_t
ACE::recvv_n_i (ACE_HANDLE handle,
                iovec *iov,
                int iovcnt,
                const ACE_Time_Value *timeout,
                size_t *bt)
{
  size_t temp;
  size_t &bytes_transferred = bt == 0 ? temp : *bt;
  bytes_transferred = 0;
  ssize_t result = 0;
  int error = 0;

  int val = 0;
  ACE::record_and_set_non_blocking_mode (handle, val);

  for (int s = 0; s < iovcnt; )
    {
      // Try to transfer as much of the remaining data as possible.
      // Since the socket is in non-blocking mode, this call will not
      // block.
      ssize_t n = ACE_OS::recvv (handle, iov + s, iovcnt - s);

      // Check for errors.
      if (n == 0 || n == -1)
        {
          // Check for possible blocking.
          if (n == -1 && errno == EWOULDBLOCK)
            {
              // Wait upto <timeout> for the blocking to subside.
              int const rtn = ACE::handle_read_ready (handle, timeout);

              // Did select() succeed?
              if (rtn != -1)
                {
                  // Blocking subsided in <timeout> period.  Continue
                  // data transfer.
                  n = 0;
                  continue;
                }
            }

          // Wait in select() timed out or other data transfer or
          // select() failures.
          error = 1;
          result = n;
          break;
        }

      for (bytes_transferred += n;
           s < iovcnt
             && n >= static_cast<ssize_t> (iov[s].iov_len);
           s++)
        n -= iov[s].iov_len;

      if (n != 0)
        {
          char *base = reinterpret_cast<char *> (iov[s].iov_base);
          iov[s].iov_base = base + n;
          iov[s].iov_len = iov[s].iov_len - n;
        }
    }

  ACE::restore_non_blocking_mode (handle, val);

  if (error)
    {
      return result;
    }
  else
    {
      return ACE_Utils::truncate_cast<ssize_t> (bytes_transferred);
    }
}

ssize_t
ACE::recv_n (ACE_HANDLE handle,
             ACE_Message_Block *message_block,
             const ACE_Time_Value *timeout,
             size_t *bt)
{
  size_t temp;
  size_t &bytes_transferred = bt == 0 ? temp : *bt;
  bytes_transferred = 0;

  iovec iov[ACE_IOV_MAX];
  int iovcnt = 0;

  while (message_block != 0)
    {
      // Our current message block chain.
      const ACE_Message_Block *current_message_block = message_block;

      while (current_message_block != 0)
        {
          size_t current_message_block_length =
            current_message_block->length ();
          char *this_rd_ptr = current_message_block->rd_ptr ();

          // Check if this block has any space for incoming data.
          while (current_message_block_length > 0)
            {
              u_long const this_chunk_length =
                ACE_Utils::truncate_cast<u_long> (
                  current_message_block_length);

              // Collect the data in the iovec.
              iov[iovcnt].iov_base = this_rd_ptr;
              iov[iovcnt].iov_len  = this_chunk_length;
              current_message_block_length -= this_chunk_length;
              this_rd_ptr += this_chunk_length;

              // Increment iovec counter.
              ++iovcnt;

              // The buffer is full make a OS call.  @@ TODO find a way to
              // find ACE_IOV_MAX for platforms that do not define it rather
              // than simply setting ACE_IOV_MAX to some arbitrary value such
              // as 16.
              if (iovcnt == ACE_IOV_MAX)
                {
                  size_t current_transfer = 0;

                  ssize_t const result = ACE::recvv_n (handle,
                                                       iov,
                                                       iovcnt,
                                                       timeout,
                                                       &current_transfer);

                  // Add to total bytes transferred.
                  bytes_transferred += current_transfer;

                  // Errors.
                  if (result == -1 || result == 0)
                    return result;

                  // Reset iovec counter.
                  iovcnt = 0;
                }
            }

          // Select the next message block in the chain.
          current_message_block = current_message_block->cont ();
        }

      // Selection of the next message block chain.
      message_block = message_block->next ();
    }

  // Check for remaining buffers to be sent.  This will happen when
  // ACE_IOV_MAX is not a multiple of the number of message blocks.
  if (iovcnt != 0)
    {
      size_t current_transfer = 0;

      ssize_t const result = ACE::recvv_n (handle,
                                           iov,
                                           iovcnt,
                                           timeout,
                                           &current_transfer);

      // Add to total bytes transferred.
      bytes_transferred += current_transfer;

      // Errors.
      if (result == -1 || result == 0)
        {
          return result;
        }
    }

  // Return total bytes transferred.
  return ACE_Utils::truncate_cast<ssize_t> (bytes_transferred);
}

ssize_t
ACE::send (ACE_HANDLE handle,
           const void *buf,
           size_t n,
           int flags,
           const ACE_Time_Value *timeout)
{
  if (timeout == 0)
    return ACE_OS::send (handle, (const char *) buf, n, flags);
  else
    {
      int val = 0;
      if (ACE::enter_send_timedwait (handle, timeout, val) == -1)
        return -1;
      else
        {
          ssize_t const bytes_transferred =
            ACE_OS::send (handle, (const char *) buf, n, flags);
          ACE::restore_non_blocking_mode (handle, val);
          return bytes_transferred;
        }
    }
}

#if defined (ACE_HAS_TLI)

ssize_t
ACE::t_snd (ACE_HANDLE handle,
            const void *buf,
            size_t n,
            int flags,
            const ACE_Time_Value *timeout)
{
  if (timeout == 0)
    return ACE_OS::t_snd (handle, (const char *) buf, n, flags);
  else
    {
      int val = 0;
      if (ACE::enter_send_timedwait (handle, timeout, val) == -1)
        return -1;
      else
        {
          ssize_t const bytes_transferred =
            ACE_OS::t_snd (handle, (const char *) buf, n, flags);
          ACE::restore_non_blocking_mode (handle, val);
          return bytes_transferred;
        }
    }
}

#endif /* ACE_HAS_TLI */

ssize_t
ACE::send (ACE_HANDLE handle,
           const void *buf,
           size_t n,
           const ACE_Time_Value *timeout)
{
  if (timeout == 0)
    return ACE::send_i (handle, buf, n);
  else
    {
      int val = 0;
      if (ACE::enter_send_timedwait (handle, timeout, val) == -1)
        return -1;
      else
        {
          ssize_t const bytes_transferred = ACE::send_i (handle, buf, n);
          ACE::restore_non_blocking_mode (handle, val);
          return bytes_transferred;
        }
    }
}

ssize_t
ACE::sendmsg (ACE_HANDLE handle,
              const struct msghdr *msg,
              int flags,
              const ACE_Time_Value *timeout)
{
  if (timeout == 0)
    return ACE_OS::sendmsg (handle, msg, flags);
  else
    {
      int val = 0;
      if (ACE::enter_send_timedwait (handle, timeout, val) == -1)
        return -1;
      else
        {
          ssize_t const bytes_transferred =
            ACE_OS::sendmsg (handle, msg, flags);
          ACE::restore_non_blocking_mode (handle, val);
          return bytes_transferred;
        }
    }
}

ssize_t
ACE::sendto (ACE_HANDLE handle,
             const char *buf,
             int len,
             int flags,
             const struct sockaddr *addr,
             int addrlen,
             const ACE_Time_Value *timeout)
{
  if (timeout == 0)
    return ACE_OS::sendto (handle, buf, len, flags, addr, addrlen);
  else
    {
      int val = 0;
      if (ACE::enter_send_timedwait (handle, timeout, val) == -1)
        return -1;
      else
        {
          ssize_t const bytes_transferred =
            ACE_OS::sendto (handle, buf, len, flags, addr, addrlen);
          ACE::restore_non_blocking_mode (handle, val);
          return bytes_transferred;
        }
    }
}

ssize_t
ACE::send_n_i (ACE_HANDLE handle,
               const void *buf,
               size_t len,
               int flags,
               size_t *bt)
{
  size_t temp;
  size_t &bytes_transferred = bt == 0 ? temp : *bt;
  ssize_t n;

  for (bytes_transferred = 0;
       bytes_transferred < len;
       bytes_transferred += n)
    {
      // Try to transfer as much of the remaining data as possible.
      n = ACE_OS::send (handle,
                        (char *) buf + bytes_transferred,
                        len - bytes_transferred,
                        flags);
      // Check EOF.
      if (n == 0)
        return 0;

      // Check for other errors.
      if (n == -1)
        {
          // Check for possible blocking.
#if defined (ACE_WIN32)
          if (errno == EWOULDBLOCK) // If enobufs no need to loop
#else
          if (errno == EWOULDBLOCK || errno == ENOBUFS)
#endif /* ACE_WIN32 */
            {
              // Wait for the blocking to subside.
              int const result = ACE::handle_write_ready (handle, 0);

              // Did select() succeed?
              if (result != -1)
                {
                  // Blocking subsided.  Continue data transfer.
                  n = 0;
                  continue;
                }
            }

          // Other data transfer or select() failures.
          return -1;
        }
    }

  return ACE_Utils::truncate_cast<ssize_t> (bytes_transferred);
}

ssize_t
ACE::send_n_i (ACE_HANDLE handle,
               const void *buf,
               size_t len,
               int flags,
               const ACE_Time_Value *timeout,
               size_t *bt)
{
  size_t temp;
  size_t &bytes_transferred = bt == 0 ? temp : *bt;
  ssize_t n;
  ssize_t result = 0;
  int error = 0;

  int val = 0;
  ACE::record_and_set_non_blocking_mode (handle, val);

  for (bytes_transferred = 0;
       bytes_transferred < len;
       bytes_transferred += n)
    {
      // Try to transfer as much of the remaining data as possible.
      // Since the socket is in non-blocking mode, this call will not
      // block.
      n = ACE_OS::send (handle,
                        (char *) buf + bytes_transferred,
                        len - bytes_transferred,
                        flags);

      // Check for errors.
      if (n == 0 ||
          n == -1)
        {
          // Check for possible blocking.
          if (n == -1 && (errno == EWOULDBLOCK || errno == ENOBUFS))
            {
              // Wait upto <timeout> for the blocking to subside.
              int const rtn = ACE::handle_write_ready (handle, timeout);

              // Did select() succeed?
              if (rtn != -1)
                {
                  // Blocking subsided in <timeout> period.  Continue
                  // data transfer.
                  n = 0;
                  continue;
                }
            }

          // Wait in select() timed out or other data transfer or
          // select() failures.
          error = 1;
          result = n;
          break;
        }
    }

  ACE::restore_non_blocking_mode (handle, val);

  if (error)
    {
      return result;
    }
  else
    {
      return ACE_Utils::truncate_cast<ssize_t> (bytes_transferred);
    }
}

#if defined (ACE_HAS_TLI)

ssize_t
ACE::t_snd_n_i (ACE_HANDLE handle,
                const void *buf,
                size_t len,
                int flags,
                size_t *bt)
{
  size_t temp;
  size_t &bytes_transferred = bt == 0 ? temp : *bt;
  ssize_t n;

  for (bytes_transferred = 0;
       bytes_transferred < len;
       bytes_transferred += n)
    {
      // Try to transfer as much of the remaining data as possible.
      n = ACE_OS::t_snd (handle,
                         (char *) buf + bytes_transferred,
                         len - bytes_transferred,
                         flags);
      // Check EOF.
      if (n == 0)
        return 0;

      // Check for other errors.
      if (n == -1)
        {
          // Check for possible blocking.
          if (errno == EWOULDBLOCK || errno == ENOBUFS)
            {
              // Wait for the blocking to subside.
              int const result = ACE::handle_write_ready (handle, 0);

              // Did select() succeed?
              if (result != -1)
                {
                  // Blocking subsided.  Continue data transfer.
                  n = 0;
                  continue;
                }
            }

          // Other data transfer or select() failures.
          return -1;
        }
    }

  return bytes_transferred;
}

ssize_t
ACE::t_snd_n_i (ACE_HANDLE handle,
                const void *buf,
                size_t len,
                int flags,
                const ACE_Time_Value *timeout,
                size_t *bt)
{
  size_t temp;
  size_t &bytes_transferred = bt == 0 ? temp : *bt;
  ssize_t n;
  ssize_t result = 0;
  int error = 0;

  int val = 0;
  ACE::record_and_set_non_blocking_mode (handle, val);

  for (bytes_transferred = 0;
       bytes_transferred < len;
       bytes_transferred += n)
    {
      // Try to transfer as much of the remaining data as possible.
      // Since the socket is in non-blocking mode, this call will not
      // block.
      n = ACE_OS::t_snd (handle,
                         (char *) buf + bytes_transferred,
                         len - bytes_transferred,
                         flags);

      // Check for errors.
      if (n == 0 ||
          n == -1)
        {
          // Check for possible blocking.
          if (n == -1 &&
              errno == EWOULDBLOCK || errno == ENOBUFS)
            {
              // Wait upto <timeout> for the blocking to subside.
              int const rtn = ACE::handle_write_ready (handle, timeout);

              // Did select() succeed?
              if (rtn != -1)
                {
                  // Blocking subsided in <timeout> period.  Continue
                  // data transfer.
                  n = 0;
                  continue;
                }
            }

          // Wait in select() timed out or other data transfer or
          // select() failures.
          error = 1;
          result = n;
          break;
        }
    }

  ACE::restore_non_blocking_mode (handle, val);

  if (error)
    return result;
  else
    return bytes_transferred;
}

#endif /* ACE_HAS_TLI */

ssize_t
ACE::send_n_i (ACE_HANDLE handle,
               const void *buf,
               size_t len,
               size_t *bt)
{
  size_t temp;
  size_t &bytes_transferred = bt == 0 ? temp : *bt;
  ssize_t n;

  for (bytes_transferred = 0;
       bytes_transferred < len;
       bytes_transferred += n)
    {
      // Try to transfer as much of the remaining data as possible.
      n = ACE::send_i (handle,
                       (char *) buf + bytes_transferred,
                       len - bytes_transferred);
      // Check EOF.
      if (n == 0)
        {
          return 0;
        }

      // Check for other errors.
      if (n == -1)
        {
          // Check for possible blocking.
          if (errno == EWOULDBLOCK || errno == ENOBUFS)
            {
              // Wait for the blocking to subside.
              int const result = ACE::handle_write_ready (handle, 0);

              // Did select() succeed?
              if (result != -1)
                {
                  // Blocking subsided.  Continue data transfer.
                  n = 0;
                  continue;
                }
            }

          // Other data transfer or select() failures.
          return -1;
        }
    }

  return ACE_Utils::truncate_cast<ssize_t> (bytes_transferred);
}

ssize_t
ACE::send_n_i (ACE_HANDLE handle,
               const void *buf,
               size_t len,
               const ACE_Time_Value *timeout,
               size_t *bt)
{
  size_t temp;
  size_t &bytes_transferred = bt == 0 ? temp : *bt;
  ssize_t n;
  ssize_t result = 0;
  int error = 0;

  int val = 0;
  ACE::record_and_set_non_blocking_mode (handle, val);

  for (bytes_transferred = 0;
       bytes_transferred < len;
       bytes_transferred += n)
    {
      // Try to transfer as much of the remaining data as possible.
      // Since the socket is in non-blocking mode, this call will not
      // block.
      n = ACE::send_i (handle,
                       (char *) buf + bytes_transferred,
                       len - bytes_transferred);

      // Check for errors.
      if (n == 0 ||
          n == -1)
        {
          // Check for possible blocking.
          if (n == -1 &&
              (errno == EWOULDBLOCK || errno == ENOBUFS))
            {
              // Wait upto <timeout> for the blocking to subside.
              int const rtn = ACE::handle_write_ready (handle, timeout);

              // Did select() succeed?
              if (rtn != -1)
                {
                  // Blocking subsided in <timeout> period.  Continue
                  // data transfer.
                  n = 0;
                  continue;
                }
            }

          // Wait in select() timed out or other data transfer or
          // select() failures.
          error = 1;
          result = n;
          break;
        }
    }

  ACE::restore_non_blocking_mode (handle, val);

  if (error)
    {
      return result;
    }
  else
    {
      return ACE_Utils::truncate_cast<ssize_t> (bytes_transferred);
    }
}

// Send N char *ptrs and int lengths.  Note that the char *'s precede
// the ints (basically, an varargs version of writev).  The count N is
// the *total* number of trailing arguments, *not* a couple of the
// number of tuple pairs!

ssize_t
ACE::send (ACE_HANDLE handle, size_t n, ...)
{
  va_list argp;
  int total_tuples = static_cast<int> (n / 2);
  iovec *iovp;
#if defined (ACE_HAS_ALLOCA)
  iovp = (iovec *) alloca (total_tuples * sizeof (iovec));
#else
  ACE_NEW_RETURN (iovp,
                  iovec[total_tuples],
                  -1);
#endif /* !defined (ACE_HAS_ALLOCA) */

  va_start (argp, n);

  for (int i = 0; i < total_tuples; i++)
    {
      iovp[i].iov_base = va_arg (argp, char *);
      iovp[i].iov_len = va_arg (argp, int);
    }

  ssize_t result = ACE_OS::sendv (handle, iovp, total_tuples);
#if !defined (ACE_HAS_ALLOCA)
  delete [] iovp;
#endif /* !defined (ACE_HAS_ALLOCA) */
  va_end (argp);
  return result;
}

ssize_t
ACE::sendv (ACE_HANDLE handle,
            const iovec *iov,
            int iovcnt,
            const ACE_Time_Value *timeout)
{
  if (timeout == 0)
    return ACE_OS::sendv (handle, iov, iovcnt);
  else
    {
      int val = 0;
      if (ACE::enter_send_timedwait (handle, timeout, val) == -1)
        return -1;
      else
        {
          ssize_t bytes_transferred = ACE_OS::sendv (handle, iov, iovcnt);
          ACE::restore_non_blocking_mode (handle, val);
          return bytes_transferred;
        }
    }
}

ssize_t
ACE::sendv_n_i (ACE_HANDLE handle,
                const iovec *i,
                int iovcnt,
                size_t *bt)
{
  size_t temp;
  size_t &bytes_transferred = bt == 0 ? temp : *bt;
  bytes_transferred = 0;

  iovec *iov = const_cast<iovec *> (i);

  for (int s = 0;
       s < iovcnt;
       )
    {
      // Try to transfer as much of the remaining data as possible.
      ssize_t n = ACE_OS::sendv (handle, iov + s, iovcnt - s);
      
      // Check EOF.
      if (n == 0)
        return 0;

      // Check for other errors.
      if (n == -1)
        {
          // Check for possible blocking.
          if (errno == EWOULDBLOCK || errno == ENOBUFS)
            {
              // Wait for the blocking to subside.
              int const result = ACE::handle_write_ready (handle, 0);

              // Did select() succeed?
              if (result != -1)
                {
                  // Blocking subsided.  Continue data transfer.
                  n = 0;
                  continue;
                }
            }

          // Other data transfer or select() failures.
          return -1;
        }

      for (bytes_transferred += n;
           s < iovcnt
             && n >= static_cast<ssize_t> (iov[s].iov_len);
           s++)
        n -= iov[s].iov_len;

      if (n != 0)
        {
          char *base = reinterpret_cast<char *> (iov[s].iov_base);
          iov[s].iov_base = base + n;
          iov[s].iov_len = iov[s].iov_len - n;
        }
    }

  return ACE_Utils::truncate_cast<ssize_t> (bytes_transferred);
}

ssize_t
ACE::sendv_n_i (ACE_HANDLE handle,
                const iovec *i,
                int iovcnt,
                const ACE_Time_Value *timeout,
                size_t *bt)
{
  size_t temp;
  size_t &bytes_transferred = bt == 0 ? temp : *bt;
  bytes_transferred = 0;
  ssize_t result = 0;
  int error = 0;

  int val = 0;
  ACE::record_and_set_non_blocking_mode (handle, val);

  iovec *iov = const_cast<iovec *> (i);

  for (int s = 0;
       s < iovcnt;
       )
    {
      // Try to transfer as much of the remaining data as possible.
      // Since the socket is in non-blocking mode, this call will not
      // block.
      ssize_t n = ACE_OS::sendv (handle, iov + s, iovcnt - s);

      // Check for errors.
      if (n == 0 ||
          n == -1)
        {
          // Check for possible blocking.
          if (n == -1 &&
              (errno == EWOULDBLOCK || errno == ENOBUFS))
            {
              // Wait upto <timeout> for the blocking to subside.
              int const rtn = ACE::handle_write_ready (handle, timeout);

              // Did select() succeed?
              if (rtn != -1)
                {
                  // Blocking subsided in <timeout> period.  Continue
                  // data transfer.
                  n = 0;
                  continue;
                }
            }

          // Wait in select() timed out or other data transfer or
          // select() failures.
          error = 1;
          result = n;
          break;
        }

      for (bytes_transferred += n;
           s < iovcnt
             && n >= static_cast<ssize_t> (iov[s].iov_len);
           s++)
        n -= iov[s].iov_len;

      if (n != 0)
        {
          char *base = reinterpret_cast<char *> (iov[s].iov_base);
          iov[s].iov_base = base + n;
          iov[s].iov_len = iov[s].iov_len - n;
        }
    }

  ACE::restore_non_blocking_mode (handle, val);

  if (error)
    {
      return result;
    }
  else
    {
      return ACE_Utils::truncate_cast<ssize_t> (bytes_transferred);
    }
}

ssize_t
ACE::write_n (ACE_HANDLE handle,
              const ACE_Message_Block *message_block,
              size_t *bt)
{
  size_t temp;
  size_t &bytes_transferred = bt == 0 ? temp : *bt;
  bytes_transferred = 0;

  iovec iov[ACE_IOV_MAX];
  int iovcnt = 0;

  while (message_block != 0)
    {
      // Our current message block chain.
      const ACE_Message_Block *current_message_block = message_block;

      while (current_message_block != 0)
        {
          size_t current_message_block_length =
            current_message_block->length ();
          char *this_block_ptr = current_message_block->rd_ptr ();

          // Check if this block has any data to be sent.
          while (current_message_block_length > 0)
            {
              u_long const this_chunk_length =
                ACE_Utils::truncate_cast<u_long> (
                  current_message_block_length);

              // Collect the data in the iovec.
              iov[iovcnt].iov_base = this_block_ptr;
              iov[iovcnt].iov_len  = this_chunk_length;
              current_message_block_length -= this_chunk_length;
              this_block_ptr += this_chunk_length;

              // Increment iovec counter.
              ++iovcnt;

              // The buffer is full make a OS call.  @@ TODO find a way to
              // find ACE_IOV_MAX for platforms that do not define it rather
              // than simply setting ACE_IOV_MAX to some arbitrary value such
              // as 16.
              if (iovcnt == ACE_IOV_MAX)
                {
                  size_t current_transfer = 0;

                  ssize_t const result = ACE::writev_n (handle,
                                                        iov,
                                                        iovcnt,
                                                        &current_transfer);

                  // Add to total bytes transferred.
                  bytes_transferred += current_transfer;

                  // Errors.
                  if (result == -1 || result == 0)
                    return result;

                  // Reset iovec counter.
                  iovcnt = 0;
                }
            }

          // Select the next message block in the chain.
          current_message_block = current_message_block->cont ();
        }

      // Selection of the next message block chain.
      message_block = message_block->next ();
    }

  // Check for remaining buffers to be sent.  This will happen when
  // ACE_IOV_MAX is not a multiple of the number of message blocks.
  if (iovcnt != 0)
    {
      size_t current_transfer = 0;

      ssize_t const result = ACE::writev_n (handle,
                                            iov,
                                            iovcnt,
                                            &current_transfer);

      // Add to total bytes transferred.
      bytes_transferred += current_transfer;

      // Errors.
      if (result == -1 || result == 0)
        return result;
    }

  // Return total bytes transferred.
  return ACE_Utils::truncate_cast<ssize_t> (bytes_transferred);
}

ssize_t
ACE::send_n (ACE_HANDLE handle,
             const ACE_Message_Block *message_block,
             const ACE_Time_Value *timeout,
             size_t *bt)
{
  size_t temp;
  size_t &bytes_transferred = bt == 0 ? temp : *bt;
  bytes_transferred = 0;

  iovec iov[ACE_IOV_MAX];
  int iovcnt = 0;

  while (message_block != 0)
    {
      // Our current message block chain.
      const ACE_Message_Block *current_message_block = message_block;

      while (current_message_block != 0)
        {
          char *this_block_ptr = current_message_block->rd_ptr ();
          size_t current_message_block_length =
            current_message_block->length ();

          // Check if this block has any data to be sent.
          while (current_message_block_length > 0)
            {
              u_long const this_chunk_length =
                ACE_Utils::truncate_cast<u_long> (
                  current_message_block_length);

              // Collect the data in the iovec.
              iov[iovcnt].iov_base = this_block_ptr;
              iov[iovcnt].iov_len  = this_chunk_length;
              current_message_block_length -= this_chunk_length;
              this_block_ptr += this_chunk_length;

              // Increment iovec counter.
              ++iovcnt;

              // The buffer is full make a OS call.  @@ TODO find a way to
              // find ACE_IOV_MAX for platforms that do not define it rather
              // than simply setting ACE_IOV_MAX to some arbitrary value such
              // as 16.
              if (iovcnt == ACE_IOV_MAX)
                {
                  size_t current_transfer = 0;

                  ssize_t const result = ACE::sendv_n (handle,
                                                       iov,
                                                       iovcnt,
                                                       timeout,
                                                       &current_transfer);

                  // Add to total bytes transferred.
                  bytes_transferred += current_transfer;

                  // Errors.
                  if (result == -1 || result == 0)
                    return result;

                  // Reset iovec counter.
                  iovcnt = 0;
                }
            }

          // Select the next message block in the chain.
          current_message_block = current_message_block->cont ();
        }

      // Selection of the next message block chain.
      message_block = message_block->next ();
    }

  // Check for remaining buffers to be sent.  This will happen when
  // ACE_IOV_MAX is not a multiple of the number of message blocks.
  if (iovcnt != 0)
    {
      size_t current_transfer = 0;

      ssize_t const result = ACE::sendv_n (handle,
                                           iov,
                                           iovcnt,
                                           timeout,
                                           &current_transfer);

      // Add to total bytes transferred.
      bytes_transferred += current_transfer;

      // Errors.
      if (result == -1 || result == 0)
        {
          return result;
        }
    }

  // Return total bytes transferred.
  return ACE_Utils::truncate_cast<ssize_t> (bytes_transferred);
}

ssize_t
ACE::readv_n (ACE_HANDLE handle,
              iovec *iov,
              int iovcnt,
              size_t *bt)
{
  size_t temp;
  size_t &bytes_transferred = bt == 0 ? temp : *bt;
  bytes_transferred = 0;

  for (int s = 0;
       s < iovcnt;
       )
    {
      ssize_t n = ACE_OS::readv (handle,
                                 iov + s,
                                 iovcnt - s);

      if (n == -1 || n == 0)
        return n;

      for (bytes_transferred += n;
           s < iovcnt
             && n >= static_cast<ssize_t> (iov[s].iov_len);
           s++)
        n -= iov[s].iov_len;

      if (n != 0)
        {
          char *base = reinterpret_cast<char *> (iov[s].iov_base);
          iov[s].iov_base = base + n;
          iov[s].iov_len = iov[s].iov_len - n;
        }
    }

  return ACE_Utils::truncate_cast<ssize_t> (bytes_transferred);
}

ssize_t
ACE::writev_n (ACE_HANDLE handle,
               const iovec *i,
               int iovcnt,
               size_t *bt)
{
  size_t temp;
  size_t &bytes_transferred = bt == 0 ? temp : *bt;
  bytes_transferred = 0;

  iovec *iov = const_cast<iovec *> (i);

  for (int s = 0;
       s < iovcnt;
       )
    {
      ssize_t n = ACE_OS::writev (handle,
                                  iov + s,
                                  iovcnt - s);

      if (n == -1 || n == 0)
        {
          return n;
        }

      for (bytes_transferred += n;
           s < iovcnt
             && n >= static_cast<ssize_t> (iov[s].iov_len);
           s++)
        n -= iov[s].iov_len;

      if (n != 0)
        {
          char *base = reinterpret_cast<char *> (iov[s].iov_base);
          iov[s].iov_base = base + n;
          iov[s].iov_len = iov[s].iov_len - n;
        }
    }

  return ACE_Utils::truncate_cast<ssize_t> (bytes_transferred);
}

int
ACE::handle_ready (ACE_HANDLE handle,
                   const ACE_Time_Value *timeout,
                   int read_ready,
                   int write_ready,
                   int exception_ready)
{
#if defined (ACE_HAS_POLL) && defined (ACE_HAS_LIMITED_SELECT)
  ACE_UNUSED_ARG (write_ready);
  ACE_UNUSED_ARG (exception_ready);

  struct pollfd fds;

  fds.fd = handle;
  fds.events = read_ready ? POLLIN : POLLOUT;
  fds.revents = 0;

  int result = ACE_OS::poll (&fds, 1, timeout);
#else
  ACE_Handle_Set handle_set;
  handle_set.set_bit (handle);

  // Wait for data or for the timeout to elapse.
  int select_width;
#  if defined (ACE_WIN32)
  // This arg is ignored on Windows and causes pointer truncation
  // warnings on 64-bit compiles.
  select_width = 0;
#  else
  select_width = int (handle) + 1;
#  endif /* ACE_WIN64 */
  int result = ACE_OS::select (select_width,
                               read_ready ? handle_set.fdset () : 0, // read_fds.
                               write_ready ? handle_set.fdset () : 0, // write_fds.
                               exception_ready ? handle_set.fdset () : 0, // exception_fds.
                               timeout);

#endif /* ACE_HAS_POLL && ACE_HAS_LIMITED_SELECT */

  switch (result)
    {
    case 0:  // Timer expired.
      errno = ETIME;
      /* FALLTHRU */
    case -1: // we got here directly - select() returned -1.
      return -1;
    case 1: // Handle has data.
      /* FALLTHRU */
    default: // default is case result > 0; return a
      // ACE_ASSERT (result == 1);
      return result;
    }
}

int
ACE::enter_recv_timedwait (ACE_HANDLE handle,
                           const ACE_Time_Value *timeout,
                           int &val)
{
  int result = ACE::handle_read_ready (handle,
                                       timeout);

  if (result == -1)
    return -1;

  ACE::record_and_set_non_blocking_mode (handle,
                                         val);

  return result;
}

int
ACE::enter_send_timedwait (ACE_HANDLE handle,
                           const ACE_Time_Value *timeout,
                           int &val)
{
  int result = ACE::handle_write_ready (handle,
                                        timeout);

  if (result == -1)
    return -1;

  ACE::record_and_set_non_blocking_mode (handle,
                                         val);

  return result;
}

void
ACE::record_and_set_non_blocking_mode (ACE_HANDLE handle,
                                       int &val)
{
  // We need to record whether we are already *in* nonblocking mode,
  // so that we can correctly reset the state when we're done.
  val = ACE::get_flags (handle);

  if (ACE_BIT_DISABLED (val, ACE_NONBLOCK))
    // Set the handle into non-blocking mode if it's not already in
    // it.
    ACE::set_flags (handle, ACE_NONBLOCK);
}

void
ACE::restore_non_blocking_mode (ACE_HANDLE handle,
                                int val)
{
  if (ACE_BIT_DISABLED (val,
                        ACE_NONBLOCK))
    {
      // Save/restore errno.
      ACE_Errno_Guard error (errno);
      // Only disable ACE_NONBLOCK if we weren't in non-blocking mode
      // originally.
      ACE::clr_flags (handle, ACE_NONBLOCK);
    }
}


// Format buffer into printable format.  This is useful for debugging.
// Portions taken from mdump by J.P. Knight (J.P.Knight@lut.ac.uk)
// Modifications by Todd Montgomery.

size_t
ACE::format_hexdump (const char *buffer,
                     size_t size,
                     ACE_TCHAR *obuf,
                     size_t obuf_sz)
{
  ACE_TRACE ("ACE::format_hexdump");

  u_char c;
  ACE_TCHAR textver[16 + 1];

  // We can fit 16 bytes output in text mode per line, 4 chars per byte.
  size_t maxlen = (obuf_sz / 68) * 16;

  if (size > maxlen)
    size = maxlen;

  size_t i;

  size_t const lines = size / 16;
  for (i = 0; i < lines; i++)
    {
      size_t j;

      for (j = 0 ; j < 16; j++)
        {
          c = (u_char) buffer[(i << 4) + j];    // or, buffer[i*16+j]
          ACE_OS::sprintf (obuf,
                           ACE_TEXT ("%02x "),
                           c);
          obuf += 3;
          if (j == 7)
            {
              ACE_OS::sprintf (obuf,
                               ACE_TEXT (" "));
              ++obuf;
            }
          textver[j] = ACE_OS::ace_isprint (c) ? c : '.';
        }

      textver[j] = 0;

      ACE_OS::sprintf (obuf,
#if !defined (ACE_WIN32) && defined (ACE_USES_WCHAR)
                       ACE_TEXT ("  %ls\n"),
#else
                       ACE_TEXT ("  %s\n"),
#endif
                       textver);

      while (*obuf != '\0')
        ++obuf;
    }

  if (size % 16)
    {
      for (i = 0 ; i < size % 16; i++)
        {
          c = (u_char) buffer[size - size % 16 + i];
          ACE_OS::sprintf (obuf,
                           ACE_TEXT ("%02x "),
                           c);
          obuf += 3;
          if (i == 7)
            {
              ACE_OS::sprintf (obuf,
                               ACE_TEXT (" "));
              ++obuf;
            }
          textver[i] = ACE_OS::ace_isprint (c) ? c : '.';
        }

      for (i = size % 16; i < 16; i++)
        {
          ACE_OS::sprintf (obuf,
                           ACE_TEXT ("   "));
          obuf += 3;
          if (i == 7)
            {
              ACE_OS::sprintf (obuf,
                               ACE_TEXT (" "));
              ++obuf;
            }
          textver[i] = ' ';
        }

      textver[i] = 0;
      ACE_OS::sprintf (obuf,
#if !defined (ACE_WIN32) && defined (ACE_USES_WCHAR)
                       ACE_TEXT ("  %ls\n"),
#else
                       ACE_TEXT ("  %s\n"),
#endif
                       textver);
    }
  return size;
}

// Returns the current timestamp in the form
// "hour:minute:second:microsecond."  The month, day, and year are
// also stored in the beginning of the date_and_time array.

ACE_TCHAR *
ACE::timestamp (ACE_TCHAR date_and_time[],
                size_t date_and_timelen,
                bool return_pointer_to_first_digit)
{
  return ACE::timestamp (ACE_Time_Value::zero,
                         date_and_time,
                         date_and_timelen,
                         return_pointer_to_first_digit);
}

// Returns the given timestamp in the form
// "hour:minute:second:microsecond."  The month, day, and year are
// also stored in the beginning of the date_and_time array.

ACE_TCHAR *
ACE::timestamp (const ACE_Time_Value& time_value,
                ACE_TCHAR date_and_time[],
                size_t date_and_timelen,
                bool return_pointer_to_first_digit)
{
  //ACE_TRACE ("ACE::timestamp");

  if (date_and_timelen < 35)
    {
      errno = EINVAL;
      return 0;
    }

#if defined (WIN32)
  if (time_value == ACE_Time_Value::zero)
  {
    // Emulate Unix.  Win32 does NOT support all the UNIX versions
    // below, so DO we need this ifdef.
    static const ACE_TCHAR *day_of_week_name[] =
      {
        ACE_TEXT ("Sun"),
        ACE_TEXT ("Mon"),
        ACE_TEXT ("Tue"),
        ACE_TEXT ("Wed"),
        ACE_TEXT ("Thu"),
        ACE_TEXT ("Fri"),
        ACE_TEXT ("Sat")
      };
  
    static const ACE_TCHAR *month_name[] =
      {
        ACE_TEXT ("Jan"),
        ACE_TEXT ("Feb"),
        ACE_TEXT ("Mar"),
        ACE_TEXT ("Apr"),
        ACE_TEXT ("May"),
        ACE_TEXT ("Jun"),
        ACE_TEXT ("Jul"),
        ACE_TEXT ("Aug"),
        ACE_TEXT ("Sep"),
        ACE_TEXT ("Oct"),
        ACE_TEXT ("Nov"),
        ACE_TEXT ("Dec")
      };
  
    SYSTEMTIME local;
    ::GetLocalTime (&local);
  
    ACE_OS::sprintf (date_and_time,
                    ACE_TEXT ("%3s %3s %2d %04d %02d:%02d:%02d.%06d"),
                    day_of_week_name[local.wDayOfWeek],
                    month_name[local.wMonth - 1],
                    (int) local.wDay,
                    (int) local.wYear,
                    (int) local.wHour,
                    (int) local.wMinute,
                    (int) local.wSecond,
                    (int) (local.wMilliseconds * 1000));
    return &date_and_time[15 + (return_pointer_to_first_digit != 0)];
  }
#endif  /* WIN32 */
  ACE_TCHAR timebuf[26]; // This magic number is based on the ctime(3c) man page.
  ACE_Time_Value cur_time = 
    (time_value == ACE_Time_Value::zero) ? 
        ACE_Time_Value (ACE_OS::gettimeofday ()) : time_value;
  time_t secs = cur_time.sec ();

  ACE_OS::ctime_r (&secs,
                   timebuf,
                   sizeof timebuf / sizeof (ACE_TCHAR));
  // date_and_timelen > sizeof timebuf!
  ACE_OS::strsncpy (date_and_time,
                    timebuf,
                    date_and_timelen);
  ACE_TCHAR yeartmp[5];
  ACE_OS::strsncpy (yeartmp,
                    &date_and_time[20],
                    5);
  ACE_TCHAR timetmp[9];
  ACE_OS::strsncpy (timetmp,
                    &date_and_time[11],
                    9);
  ACE_OS::sprintf (&date_and_time[11],
#  if defined (ACE_USES_WCHAR)
                   ACE_TEXT ("%ls %ls.%06ld"),
#  else
                   ACE_TEXT ("%s %s.%06ld"),
#  endif /* ACE_USES_WCHAR */
                   yeartmp,
                   timetmp,
                   cur_time.usec ());
  date_and_time[33] = '\0';
  return &date_and_time[15 + (return_pointer_to_first_digit != 0)];
}

// This function rounds the request to a multiple of the page size.

size_t
ACE::round_to_pagesize (size_t len)
{
  ACE_TRACE ("ACE::round_to_pagesize");

  if (ACE::pagesize_ == 0)
    ACE::pagesize_ = ACE_OS::getpagesize ();

  return (len + (ACE::pagesize_ - 1)) & ~(ACE::pagesize_ - 1);
}

size_t
ACE::round_to_allocation_granularity (size_t len)
{
  ACE_TRACE ("ACE::round_to_allocation_granularity");

  if (ACE::allocation_granularity_ == 0)
    ACE::allocation_granularity_ = ACE_OS::allocation_granularity ();

  return (len + (ACE::allocation_granularity_ - 1)) & ~(ACE::allocation_granularity_ - 1);
}

ACE_HANDLE
ACE::handle_timed_complete (ACE_HANDLE h,
                            const ACE_Time_Value *timeout,
                            int is_tli)
{
  ACE_TRACE ("ACE::handle_timed_complete");

#if !defined (ACE_WIN32) && defined (ACE_HAS_POLL) && defined (ACE_HAS_LIMITED_SELECT)

  struct pollfd fds;

  fds.fd = h;
  fds.events = POLLIN | POLLOUT;
  fds.revents = 0;

#else
  ACE_Handle_Set rd_handles;
  ACE_Handle_Set wr_handles;
  rd_handles.set_bit (h);
  wr_handles.set_bit (h);
#endif /* !ACE_WIN32 && ACE_HAS_POLL && ACE_HAS_LIMITED_SELECT */

#if defined (ACE_WIN32)
  // Winsock is different - it sets the exception bit for failed connect,
  // unlike other platforms, where the write bit is set for both success
  // and fail.
  ACE_Handle_Set ex_handles;
  ex_handles.set_bit (h);
#endif /* ACE_WIN32 */

  bool need_to_check = false;
  bool known_failure = false;

#if defined (ACE_WIN32)
  int n = ACE_OS::select (0,    // Ignored on Windows: int (h) + 1,
                          0,
                          wr_handles,
                          ex_handles,
                          timeout);
#else
# if defined (ACE_HAS_POLL) && defined (ACE_HAS_LIMITED_SELECT)

  int n = ACE_OS::poll (&fds, 1, timeout);

# else
  int n = 0;
  if (is_tli)
    n = ACE_OS::select (int (h) + 1,
                        rd_handles,
                        wr_handles,
                        0,
                        timeout);
  else
    n = ACE_OS::select (int (h) + 1,
                        0,
                        wr_handles,
                        0,
                        timeout);
# endif /* ACE_HAS_POLL && ACE_HAS_LIMITED_SELECT */
#endif /* ACE_WIN32 */

  // If we failed to connect within the time period allocated by the
  // caller, then we fail (e.g., the remote host might have been too
  // busy to accept our call).
  if (n <= 0)
    {
      if (n == 0 && timeout != 0)
        errno = ETIME;
      return ACE_INVALID_HANDLE;
    }

  // On Windows, a ready-for-write handle is successfully connected, and
  // ready-for-exception is a failure. On fails, we need to grab the error
  // code via getsockopt.
  // On BSD sockets using select(), the handle becomes writable on
  // completion either success or fail, so if the select() does not time
  // out, we need to check for success/fail.
  // It is believed that TLI sockets use the readable=fail, writeable=success
  // but that hasn't been as well tested.
#if defined (ACE_WIN32)
  ACE_UNUSED_ARG (is_tli);

  // On Win32, ex_handle set indicates a failure. We'll do the check
  // to try and get an errno value, but the connect failed regardless of
  // what getsockopt says about the error.
  if (ex_handles.is_set (h))
    {
      need_to_check = true;
      known_failure = true;
    }
#else
  if (is_tli)
# if defined (ACE_HAS_POLL) && defined (ACE_HAS_LIMITED_SELECT)
    need_to_check = (fds.revents & POLLIN) && !(fds.revents & POLLOUT);
# else
    need_to_check = rd_handles.is_set (h) && !wr_handles.is_set (h);
# endif /* ACE_HAS_POLL && ACE_HAS_LIMITED_SELECT */

  else
# if defined (ACE_HAS_POLL) && defined (ACE_HAS_LIMITED_SELECT)
    need_to_check = (fds.revents & POLLIN);
# else
    need_to_check = true;
# endif /* ACE_HAS_POLL && ACE_HAS_LIMITED_SELECT */
#endif /* ACE_WIN32 */

  if (need_to_check)
    {
#if defined (SOL_SOCKET) && defined (SO_ERROR)
      int sock_err = 0;
      int sock_err_len = sizeof (sock_err);
      int sockopt_ret = ACE_OS::getsockopt (h, SOL_SOCKET, SO_ERROR,
                                            (char *)&sock_err, &sock_err_len);
      if (sockopt_ret < 0)
        {
          h = ACE_INVALID_HANDLE;
        }

      if (sock_err != 0 || known_failure)
        {
          h = ACE_INVALID_HANDLE;
          errno = sock_err;
        }
#else
      char dummy;

      // The following recv() won't block provided that the
      // ACE_NONBLOCK flag has not been turned off .
      n = ACE::recv (h, &dummy, 1, MSG_PEEK);

      // If no data was read/peeked at, check to see if it's because
      // of a non-connected socket (and therefore an error) or there's
      // just no data yet.
      if (n <= 0)
        {
          if (n == 0)
            {
              errno = ECONNREFUSED;
              h = ACE_INVALID_HANDLE;
            }
          else if (errno != EWOULDBLOCK && errno != EAGAIN)
            h = ACE_INVALID_HANDLE;
        }
#endif
    }

  // 1. The HANDLE is ready for writing and doesn't need to be checked or
  // 2. recv() returned an indication of the state of the socket - if there is
  // either data present, or a recv is legit but there's no data yet,
  // the connection was successfully established.
  return h;
}

// Wait up to <timeout> amount of time to accept a connection.

int
ACE::handle_timed_accept (ACE_HANDLE listener,
                          ACE_Time_Value *timeout,
                          bool restart)
{
  ACE_TRACE ("ACE::handle_timed_accept");
  // Make sure we don't bomb out on erroneous values.
  if (listener == ACE_INVALID_HANDLE)
    return -1;

#if defined (ACE_HAS_POLL) && defined (ACE_HAS_LIMITED_SELECT)

  struct pollfd fds;

  fds.fd = listener;
  fds.events = POLLIN;
  fds.revents = 0;

#else
  // Use the select() implementation rather than poll().
  ACE_Handle_Set rd_handle;
  rd_handle.set_bit (listener);
#endif /* ACE_HAS_POLL && ACE_HAS_LIMITED_SELECT */

  // We need a loop here if <restart> is enabled.

  for (;;)
    {
#if defined (ACE_HAS_POLL) && defined (ACE_HAS_LIMITED_SELECT)

      int n = ACE_OS::poll (&fds, 1, timeout);

#else
      int select_width;
#  if defined (ACE_WIN32)
      // This arg is ignored on Windows and causes pointer truncation
      // warnings on 64-bit compiles.
      select_width = 0;
#  else
      select_width = int (listener) + 1;
#  endif /* ACE_WIN32 */
      int n = ACE_OS::select (select_width,
                              rd_handle, 0, 0,
                              timeout);
#endif /* ACE_HAS_POLL && ACE_HAS_LIMITED_SELECT */

      switch (n)
        {
        case -1:
          if (errno == EINTR && restart)
            continue;
          else
            return -1;
          /* NOTREACHED */
        case 0:
          if (timeout != 0 && *timeout == ACE_Time_Value::zero)
            errno = EWOULDBLOCK;
          else
            errno = ETIMEDOUT;
          return -1;
          /* NOTREACHED */
        case 1:
          return 0;
          /* NOTREACHED */
        default:
          errno = EINVAL;
          return -1;
          /* NOTREACHED */
        }
    }
}

// Make the current process a UNIX daemon.  This is based on Stevens
// code from APUE.

int
ACE::daemonize (const ACE_TCHAR pathname[],
                bool close_all_handles,
                const ACE_TCHAR program_name[])
{
  ACE_TRACE ("ACE::daemonize");
#if !defined (ACE_LACKS_FORK)
  pid_t pid = ACE_OS::fork ();

  if (pid == -1)
    return -1;
  else if (pid != 0)
    ACE_OS::exit (0); // Parent exits.

  // 1st child continues.
  ACE_OS::setsid (); // Become session leader.

  ACE_OS::signal (SIGHUP, SIG_IGN);

  pid = ACE_OS::fork (program_name);

  if (pid != 0)
    ACE_OS::exit (0); // First child terminates.

  // Second child continues.

  if (pathname != 0)
    // change working directory.
    ACE_OS::chdir (pathname);

  ACE_OS::umask (0); // clear our file mode creation mask.

  // Close down the I/O handles.
  if (close_all_handles)
    {
      for (int i = ACE::max_handles () - 1; i >= 0; i--)
        ACE_OS::close (i);

      int fd = ACE_OS::open ("/dev/null", O_RDWR, 0);
      if (fd != -1)
        {
          ACE_OS::dup2 (fd, ACE_STDIN);
          ACE_OS::dup2 (fd, ACE_STDOUT);
          ACE_OS::dup2 (fd, ACE_STDERR);

          if (fd > ACE_STDERR)
            ACE_OS::close (fd);
        }
    }

  return 0;
#else
  ACE_UNUSED_ARG (pathname);
  ACE_UNUSED_ARG (close_all_handles);
  ACE_UNUSED_ARG (program_name);

  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_LACKS_FORK */
}

pid_t
ACE::fork (const ACE_TCHAR *program_name,
           int avoid_zombies)
{
  if (avoid_zombies == 0)
    return ACE_OS::fork (program_name);
  else
    {
      // This algorithm is adapted from an example in the Stevens book
      // "Advanced Programming in the Unix Environment" and an item in
      // Andrew Gierth's Unix Programming FAQ.  It creates an orphan
      // process that's inherited by the init process; init cleans up
      // when the orphan process terminates.
      //
      // Another way to avoid zombies is to ignore or catch the
      // SIGCHLD signal; we don't use that approach here.

      pid_t pid = ACE_OS::fork ();
      if (pid == 0)
        {
          // The child process forks again to create a grandchild.
          switch (ACE_OS::fork (program_name))
            {
            case 0: // grandchild returns 0.
              return 0;
            case -1: // assumes all errnos are < 256
              ACE_OS::_exit (errno);
            default:  // child terminates, orphaning grandchild
              ACE_OS::_exit (0);
            }
        }

      // Parent process waits for child to terminate.
      ACE_exitcode status;
      if (pid < 0 || ACE_OS::waitpid (pid, &status, 0) < 0)
        return -1;

      // child terminated by calling exit()?
      if (WIFEXITED ((status)))
        {
          // child terminated normally?
          if (WEXITSTATUS ((status)) == 0)
            return 1;
          else
            errno = WEXITSTATUS ((status));
        }
      else
        // child didn't call exit(); perhaps it received a signal?
        errno = EINTR;

      return -1;
    }
}

int
ACE::max_handles (void)
{
  ACE_TRACE ("ACE::max_handles");
#if defined (RLIMIT_NOFILE) && !defined (ACE_LACKS_RLIMIT)
  rlimit rl;
  int const r = ACE_OS::getrlimit (RLIMIT_NOFILE, &rl);
# if !defined (RLIM_INFINITY)
  if (r == 0)
    return rl.rlim_cur;
# else
  if (r == 0 && rl.rlim_cur != RLIM_INFINITY)
    return rl.rlim_cur;
  // If == RLIM_INFINITY, fall through to the ACE_LACKS_RLIMIT sections
# endif /* RLIM_INFINITY */
#endif /* RLIMIT_NOFILE && !ACE_LACKS_RLIMIT */

#if defined (_SC_OPEN_MAX)
  return ACE_OS::sysconf (_SC_OPEN_MAX);
#elif defined (ACE_VXWORKS) && (ACE_VXWORKS < 0x620)
  return maxFiles;
#elif defined (FD_SETSIZE)
  return FD_SETSIZE;
#else
  ACE_NOTSUP_RETURN (-1);
#endif /* _SC_OPEN_MAX */
}

// Set the number of currently open handles in the process.
//
// If NEW_LIMIT == -1 set the limit to the maximum allowable.
// Otherwise, set it to be the value of NEW_LIMIT.

int
ACE::set_handle_limit (int new_limit,
                       int increase_limit_only)
{
  ACE_TRACE ("ACE::set_handle_limit");
  int cur_limit = ACE::max_handles ();
  int max_limit = cur_limit;

  if (cur_limit == -1)
    return -1;

#if !defined (ACE_LACKS_RLIMIT) && defined (RLIMIT_NOFILE)
  struct rlimit rl;

  ACE_OS::memset ((void *) &rl, 0, sizeof rl);
  int r = ACE_OS::getrlimit (RLIMIT_NOFILE, &rl);
  if (r == 0)
    max_limit = rl.rlim_max;
#endif /* ACE_LACKS_RLIMIT */

  if (new_limit == -1)
    new_limit = max_limit;

  if (new_limit < 0)
    {
      errno = EINVAL;
      return -1;
    }
  else if (new_limit > cur_limit)
    {
      // Increase the limit.
#if !defined (ACE_LACKS_RLIMIT) && defined (RLIMIT_NOFILE)
      rl.rlim_cur = new_limit;
      return ACE_OS::setrlimit (RLIMIT_NOFILE, &rl);
#elif defined (ACE_LACKS_RLIMIT_NOFILE)
      return 0;
#else
      // Must return EINVAL errno.
      ACE_NOTSUP_RETURN (-1);
#endif /* ACE_LACKS_RLIMIT */
    }
  else if (increase_limit_only == 0)
    {
      // Decrease the limit.
#if !defined (ACE_LACKS_RLIMIT) && defined (RLIMIT_NOFILE)
      rl.rlim_cur = new_limit;
      return ACE_OS::setrlimit (RLIMIT_NOFILE, &rl);
#else
      // We give a chance to platforms without RLIMIT to work.
      // Instead of ACE_NOTSUP_RETURN (0), just return 0 because
      // new_limit is <= cur_limit, so it's a no-op.
      return 0;
#endif /* ACE_LACKS_RLIMIT */
    }

  return 0;
}

// Euclid's greatest common divisor algorithm.
u_long
ACE::gcd (u_long x, u_long y)
{
  while (y != 0)
    {
      u_long r = x % y;
      x = y;
      y = r;
    }

  return x;
}


// Calculates the minimum enclosing frame size for the given values.
u_long
ACE::minimum_frame_size (u_long period1, u_long period2)
{
  // if one of the periods is zero, treat it as though it as
  // uninitialized and return the other period as the frame size
  if (0 == period1)
    {
      return period2;
    }
  if (0 == period2)
    {
      return period1;
    }

  // if neither is zero, find the greatest common divisor of the two periods
  u_long greatest_common_divisor = ACE::gcd (period1, period2);

  // explicitly consider cases to reduce risk of possible overflow errors
  if (greatest_common_divisor == 1)
    {
      // periods are relative primes: just multiply them together
      return period1 * period2;
    }
  else if (greatest_common_divisor == period1)
    {
      // the first period divides the second: return the second
      return period2;
    }
  else if (greatest_common_divisor == period2)
    {
      // the second period divides the first: return the first
      return period1;
    }
  else
    {
      // the current frame size and the entry's effective period
      // have a non-trivial greatest common divisor: return the
      // product of factors divided by those in their gcd.
      return (period1 * period2) / greatest_common_divisor;
    }
}


u_long
ACE::is_prime (const u_long n,
               const u_long min_factor,
               const u_long max_factor)
{
  if (n > 3)
    for (u_long factor = min_factor;
         factor <= max_factor;
         ++factor)
      if (n / factor * factor == n)
        return factor;

  return 0;
}

const ACE_TCHAR *
ACE::sock_error (int error)
{
#if defined (ACE_WIN32)
  static ACE_TCHAR unknown_msg[64];

  switch (error)
    {
    case WSAVERNOTSUPPORTED:
      return ACE_TEXT ("version of WinSock not supported");
      /* NOTREACHED */
    case WSASYSNOTREADY:
      return ACE_TEXT ("WinSock not present or not responding");
      /* NOTREACHED */
    case WSAEINVAL:
      return ACE_TEXT ("app version not supported by DLL");
      /* NOTREACHED */
    case WSAHOST_NOT_FOUND:
      return ACE_TEXT ("Authoritive: Host not found");
      /* NOTREACHED */
    case WSATRY_AGAIN:
      return ACE_TEXT ("Non-authoritive: host not found or server failure");
      /* NOTREACHED */
    case WSANO_RECOVERY:
      return ACE_TEXT ("Non-recoverable: refused or not implemented");
      /* NOTREACHED */
    case WSANO_DATA:
      return ACE_TEXT ("Valid name, no data record for type");
      /* NOTREACHED */
      /*
        case WSANO_ADDRESS:
        return "Valid name, no MX record";
      */
    case WSANOTINITIALISED:
      return ACE_TEXT ("WSA Startup not initialized");
      /* NOTREACHED */
    case WSAENETDOWN:
      return ACE_TEXT ("Network subsystem failed");
      /* NOTREACHED */
    case WSAEINPROGRESS:
      return ACE_TEXT ("Blocking operation in progress");
      /* NOTREACHED */
    case WSAEINTR:
      return ACE_TEXT ("Blocking call cancelled");
      /* NOTREACHED */
    case WSAEAFNOSUPPORT:
      return ACE_TEXT ("address family not supported");
      /* NOTREACHED */
    case WSAEMFILE:
      return ACE_TEXT ("no file handles available");
      /* NOTREACHED */
    case WSAENOBUFS:
      return ACE_TEXT ("no buffer space available");
      /* NOTREACHED */
    case WSAEPROTONOSUPPORT:
      return ACE_TEXT ("specified protocol not supported");
      /* NOTREACHED */
    case WSAEPROTOTYPE:
      return ACE_TEXT ("protocol wrong type for this socket");
      /* NOTREACHED */
    case WSAESOCKTNOSUPPORT:
      return ACE_TEXT ("socket type not supported for address family");
      /* NOTREACHED */
    case WSAENOTSOCK:
      return ACE_TEXT ("handle is not a socket");
      /* NOTREACHED */
    case WSAEWOULDBLOCK:
      return ACE_TEXT ("resource temporarily unavailable");
      /* NOTREACHED */
    case WSAEADDRINUSE:
      return ACE_TEXT ("address already in use");
      /* NOTREACHED */
    case WSAECONNABORTED:
      return ACE_TEXT ("connection aborted");
      /* NOTREACHED */
    case WSAECONNRESET:
      return ACE_TEXT ("connection reset");
      /* NOTREACHED */
    case WSAENOTCONN:
      return ACE_TEXT ("not connected");
      /* NOTREACHED */
    case WSAETIMEDOUT:
      return ACE_TEXT ("connection timed out");
      /* NOTREACHED */
    case WSAECONNREFUSED:
      return ACE_TEXT ("connection refused");
      /* NOTREACHED */
    case WSAEHOSTDOWN:
      return ACE_TEXT ("host down");
      /* NOTREACHED */
    case WSAEHOSTUNREACH:
      return ACE_TEXT ("host unreachable");
      /* NOTREACHED */
    case WSAEADDRNOTAVAIL:
      return ACE_TEXT ("address not available");
      /* NOTREACHED */
    case WSAEISCONN:
      return ACE_TEXT ("socket is already connected");
      /* NOTREACHED */
    case WSAENETRESET:
      return ACE_TEXT ("network dropped connection on reset");
      /* NOTREACHED */
    case WSAEMSGSIZE:
      return ACE_TEXT ("message too long");
      /* NOTREACHED */
    case WSAENETUNREACH:
      return ACE_TEXT ("network is unreachable");
      /* NOTREACHED */
    case WSAEFAULT:
      return ACE_TEXT ("bad address");
      /* NOTREACHED */
    case WSAEDISCON:
      return ACE_TEXT ("graceful shutdown in progress");
      /* NOTREACHED */
    case WSAEACCES:
      return ACE_TEXT ("permission denied");
      /* NOTREACHED */
    case WSAESHUTDOWN:
      return ACE_TEXT ("cannot send after socket shutdown");
      /* NOTREACHED */
    case WSAEPROCLIM:
      return ACE_TEXT ("too many processes");
      /* NOTREACHED */
    case WSAEALREADY:
      return ACE_TEXT ("operation already in progress");
      /* NOTREACHED */
    case WSAEPFNOSUPPORT:
      return ACE_TEXT ("protocol family not supported");
      /* NOTREACHED */
    case WSAENOPROTOOPT:
      return ACE_TEXT ("bad protocol option");
      /* NOTREACHED */
    case WSATYPE_NOT_FOUND:
      return ACE_TEXT ("class type not found");
      /* NOTREACHED */
    case WSAEOPNOTSUPP:
      return ACE_TEXT ("operation not supported");
      /* NOTREACHED */
    case WSAEDESTADDRREQ:
      return ACE_TEXT ("destination address required");
      /* NOTREACHED */
    default:
      ACE_OS::sprintf (unknown_msg, ACE_TEXT ("unknown error: %d"), error);
      return unknown_msg;
      /* NOTREACHED */
    }
#else
  ACE_UNUSED_ARG (error);
  ACE_NOTSUP_RETURN (0);
#endif /* ACE_WIN32 */
}

bool
ACE::is_sock_error (int error)
{
#if defined (ACE_WIN32)
  switch (error)
    {
    case WSAVERNOTSUPPORTED:
    case WSASYSNOTREADY:
    case WSAEINVAL:
    case WSAHOST_NOT_FOUND:
    case WSATRY_AGAIN:
    case WSANO_RECOVERY:
    case WSANO_DATA:
      /*
        case WSANO_ADDRESS:
      */
    case WSANOTINITIALISED:
    case WSAENETDOWN:
    case WSAEINPROGRESS:
    case WSAEINTR:
    case WSAEAFNOSUPPORT:
    case WSAEMFILE:
    case WSAENOBUFS:
    case WSAEPROTONOSUPPORT:
    case WSAEPROTOTYPE:
    case WSAESOCKTNOSUPPORT:
    case WSAENOTSOCK:
    case WSAEWOULDBLOCK:
    case WSAEADDRINUSE:
    case WSAECONNABORTED:
    case WSAECONNRESET:
    case WSAENOTCONN:
    case WSAETIMEDOUT:
    case WSAECONNREFUSED:
    case WSAEHOSTDOWN:
    case WSAEHOSTUNREACH:
    case WSAEADDRNOTAVAIL:
    case WSAEISCONN:
    case WSAENETRESET:
    case WSAEMSGSIZE:
    case WSAENETUNREACH:
    case WSAEFAULT:
    case WSAEDISCON:
    case WSAEACCES:
    case WSAESHUTDOWN:
    case WSAEPROCLIM:
    case WSAEALREADY:
    case WSAEPFNOSUPPORT:
    case WSAENOPROTOOPT:
    case WSATYPE_NOT_FOUND:
    case WSAEOPNOTSUPP:
      return true;
    }
#else
  ACE_UNUSED_ARG (error);
#endif /* ACE_WIN32 */
  return false;
}

char *
ACE::strndup (const char *str, size_t n)
{
  const char *t = str;
  size_t len;

  // Figure out how long this string is (remember, it might not be
  // NUL-terminated).

  for (len = 0;
       len < n && *t++ != '\0';
       len++)
    continue;

  char *s;
  ACE_ALLOCATOR_RETURN (s,
                        (char *) ACE_OS::malloc (len + 1),
                        0);
  return ACE_OS::strsncpy (s, str, len + 1);
}

#if defined (ACE_HAS_WCHAR)
wchar_t *
ACE::strndup (const wchar_t *str, size_t n)
{
  const wchar_t *t = str;
  size_t len;

  // Figure out how long this string is (remember, it might not be
  // NUL-terminated).

  for (len = 0;
       len < n && *t++ != '\0';
       len++)
    continue;

  wchar_t *s;
  ACE_ALLOCATOR_RETURN (s,
                        static_cast<wchar_t *> (
            ACE_OS::malloc ((len + 1) * sizeof (wchar_t))),
                        0);
  return ACE_OS::strsncpy (s, str, len + 1);
}
#endif /* ACE_HAS_WCHAR */

char *
ACE::strnnew (const char *str, size_t n)
{
  const char *t = str;
  size_t len;

  // Figure out how long this string is (remember, it might not be
  // NUL-terminated).

  for (len = 0;
       len < n && *t++ != L'\0';
       len++)
    continue;

  char *s;
  ACE_NEW_RETURN (s,
                  char[len + 1],
                  0);
  return ACE_OS::strsncpy (s, str, len + 1);
}

#if defined (ACE_HAS_WCHAR)
wchar_t *
ACE::strnnew (const wchar_t *str, size_t n)
{
  const wchar_t *t = str;
  size_t len;

  // Figure out how long this string is (remember, it might not be
  // NUL-terminated).

  for (len = 0;
       len < n && *t++ != ACE_TEXT_WIDE ('\0');
       len++)
    continue;

  wchar_t *s;
  ACE_NEW_RETURN (s,
                  wchar_t[len + 1],
                  0);
  return ACE_OS::strsncpy (s, str, len + 1);
}
#endif /* ACE_HAS_WCHAR */

const char *
ACE::strend (const char *s)
{
  while (*s++ != '\0')
    continue;

  return s;
}

#if defined ACE_HAS_WCHAR
const wchar_t *
ACE::strend (const wchar_t *s)
{
  while (*s++ != ACE_TEXT_WIDE ('\0'))
    continue;

  return s;
}
#endif

char *
ACE::strnew (const char *s)
{
  if (s == 0)
    return 0;
  char *t = 0;
  ACE_NEW_RETURN (t,
                  char [ACE_OS::strlen (s) + 1],
                  0);
  if (t == 0)
    return 0;
  else
    return ACE_OS::strcpy (t, s);
}

#if defined (ACE_HAS_WCHAR)
wchar_t *
ACE::strnew (const wchar_t *s)
{
  if (s == 0)
    return 0;
  wchar_t *t = 0;
  ACE_NEW_RETURN (t,
                  wchar_t[ACE_OS::strlen (s) + 1],
                  0);
  if (t == 0)
    return 0;
  else
    return ACE_OS::strcpy (t, s);
}
#endif /* ACE_HAS_WCHAR */

// helper functions for ACE::wild_match()
namespace
{

  inline bool equal_char (char a, char b, bool case_sensitive)
  {
    if (case_sensitive)
      return a == b;
    return ACE_OS::ace_tolower (a) == ACE_OS::ace_tolower (b);
  }

  // precond:  *p == '[' start of char class
  // postcond: *p == ']' end of the char class
  inline bool equal_class (char s, const char *&p, bool case_sensitive)
  {
    ++p;
    bool negate = false;
    if (*p == '!')
      {
        negate = true;
        ++p;
      }
    // ] and - are regular in 1st position
    for (bool first = true; *p && (first || *p != ']'); ++p)
      {
        if (!first && *p == '-' && p[1] != ']')
          {
            if (!p[1] || p[1] <= p[-1]) // invalid range
              {
                continue;
              }
            // Since we are in the POSIX locale, only the basic ASCII
            // characters are allowed as the range endpoints.  These characters
            // are the same values in both signed and unsigned chars so we
            // don't have to account for any "pathological cases."
            for (char range = p[-1] + 1; range <= p[1]; ++range)
              {
                if (equal_char (s, range, case_sensitive))
                  {
                    while (*++p != ']') {}
                    return !negate;
                  }
              }
            ++p; // consume the character 1 past the -
          }
        else if (equal_char (s, *p, case_sensitive))
          {
            while (*++p != ']') {}
            return !negate;
          }
        first = false;
      }
    return negate;
  }
}

bool
ACE::wild_match(const char *str, const char *pat, bool case_sensitive,
                bool character_classes)
{
  if (str == pat)
    return true;
  if (pat == 0 || str == 0)
    return false;

  bool star = false, escape = false;
  const char *s = str;
  const char *p = pat;
  while (*s != '\0')
    {
      if (!escape && *p == '\\')
        {
          ++p;
          escape = true;
        }
      else if (!escape && *p == '*')
        {
          star = true;
          pat = p;
          while (*++pat == '*') {}

          if (*pat == '\0')
            return true;
          p = pat;
        }
      else if (!escape && *p == '?')
        {
          ++s;
          ++p;
        }
      else if (!escape && character_classes && *p == '[')
        {
          if (equal_class (*s, p, case_sensitive))
            {
              ++p;
            }
           else
            {
              if (!star)
                return false;
              p = pat;
            }
          ++s;
        }
      else if (!equal_char (*s, *p, case_sensitive))
        {
          if (!star)
            return false;
          ++s;
          p = pat;
          escape = false;
        }
      else
        {
          ++s;
          ++p;
          escape = false;
        }
    }
  if (*p == '*')
    while (*++p == '*') {}

  return *p == '\0';
}

// Close versioned namespace, if enabled by the user.
ACE_END_VERSIONED_NAMESPACE_DECL
