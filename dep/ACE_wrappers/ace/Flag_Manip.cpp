// $Id: Flag_Manip.cpp 80826 2008-03-04 14:51:23Z wotte $

#include "ace/Flag_Manip.h"

#if defined (ACE_LACKS_FCNTL)
#  include "ace/OS_NS_stropts.h"
#  include "ace/OS_NS_errno.h"
#endif /* ACE_LACKS_FCNTL */

#if !defined (__ACE_INLINE__)
#include "ace/Flag_Manip.inl"
#endif /* __ACE_INLINE__ */

#if defined (CYGWIN32)
#  include "ace/os_include/os_termios.h"
#endif /* CYGWIN32 */

ACE_RCSID (ace,
           Flag_Manip,
           "$Id: Flag_Manip.cpp 80826 2008-03-04 14:51:23Z wotte $")

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

// Flags are file status flags to turn on.

int
ACE::set_flags (ACE_HANDLE handle, int flags)
{
  ACE_TRACE ("ACE::set_flags");
#if defined (ACE_LACKS_FCNTL)
  switch (flags)
    {
    case ACE_NONBLOCK:
      // nonblocking argument (1)
      // blocking:            (0)
      {
        int nonblock = 1;
        return ACE_OS::ioctl (handle, FIONBIO, &nonblock);
      }
    default:
      ACE_NOTSUP_RETURN (-1);
    }
#else
  int val = ACE_OS::fcntl (handle, F_GETFL, 0);

  if (val == -1)
    return -1;

  // Turn on flags.
  ACE_SET_BITS (val, flags);

  if (ACE_OS::fcntl (handle, F_SETFL, val) == -1)
    return -1;
  else
    return 0;
#endif /* ACE_LACKS_FCNTL */
}

// Flags are the file status flags to turn off.

int
ACE::clr_flags (ACE_HANDLE handle, int flags)
{
  ACE_TRACE ("ACE::clr_flags");

#if defined (ACE_LACKS_FCNTL)
  switch (flags)
    {
    case ACE_NONBLOCK:
      // nonblocking argument (1)
      // blocking:            (0)
      {
        int nonblock = 0;
        return ACE_OS::ioctl (handle, FIONBIO, &nonblock);
      }
    default:
      ACE_NOTSUP_RETURN (-1);
    }
#else
  int val = ACE_OS::fcntl (handle, F_GETFL, 0);

  if (val == -1)
    return -1;

  // Turn flags off.
  ACE_CLR_BITS (val, flags);

  if (ACE_OS::fcntl (handle, F_SETFL, val) == -1)
    return -1;
  else
    return 0;
#endif /* ACE_LACKS_FCNTL */
}

ACE_END_VERSIONED_NAMESPACE_DECL

