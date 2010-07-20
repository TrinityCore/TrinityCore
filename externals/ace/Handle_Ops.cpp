// $Id: Handle_Ops.cpp 80826 2008-03-04 14:51:23Z wotte $

#include "ace/Handle_Ops.h"

#include "ace/OS_NS_errno.h"
#include "ace/OS_NS_fcntl.h"
#include "ace/Time_Value.h"

ACE_RCSID (ace,
           Handle_Ops,
           "$Id: Handle_Ops.cpp 80826 2008-03-04 14:51:23Z wotte $")


ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_HANDLE
ACE::handle_timed_open (ACE_Time_Value *timeout,
                        const ACE_TCHAR *name,
                        int flags,
                        int perms,
                        LPSECURITY_ATTRIBUTES sa)
{
  ACE_TRACE ("ACE::handle_timed_open");

  if (timeout != 0)
    {
#if !defined (ACE_WIN32)
      // On Win32, ACE_NONBLOCK gets recognized as O_WRONLY so we
      // don't use it there
      flags |= ACE_NONBLOCK;
#endif /* ACE_WIN32 */

      // Open the named pipe or file using non-blocking mode...
      ACE_HANDLE const handle = ACE_OS::open (name, flags, perms, sa);

      if (handle == ACE_INVALID_HANDLE
          && (errno == EWOULDBLOCK
              && (timeout->sec () > 0 || timeout->usec () > 0)))
        // This expression checks if we were polling.
        errno = ETIMEDOUT;

      return handle;
    }
  else
    return ACE_OS::open (name, flags, perms, sa);
}

ACE_END_VERSIONED_NAMESPACE_DECL
