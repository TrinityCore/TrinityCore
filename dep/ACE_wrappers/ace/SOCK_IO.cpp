// $Id: SOCK_IO.cpp 82294 2008-07-12 13:03:37Z johnnyw $
#include "ace/SOCK_IO.h"
#include "ace/Handle_Set.h"
#include "ace/OS_NS_sys_select.h"
#include "ace/OS_NS_sys_socket.h"
#include "ace/OS_Memory.h"
#include "ace/Truncate.h"
#if !defined (__ACE_INLINE__)
#include "ace/SOCK_IO.inl"
#endif /* __ACE_INLINE__ */
ACE_RCSID(ace, SOCK_IO, "$Id: SOCK_IO.cpp 82294 2008-07-12 13:03:37Z johnnyw $")
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
ACE_ALLOC_HOOK_DEFINE(ACE_SOCK_IO)
void
ACE_SOCK_IO::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_SOCK_IO::dump");
#endif /* ACE_HAS_DUMP */
}
// Allows a client to read from a socket without having to provide
// a buffer to read.  This method determines how much data is in the
// socket, allocates a buffer of this size, reads in the data, and
// returns the number of bytes read.
ssize_t
ACE_SOCK_IO::recvv (iovec *io_vec,
                    const ACE_Time_Value *timeout) const
{
  ACE_TRACE ("ACE_SOCK_IO::recvv");
#if defined (FIONREAD)
  ACE_Handle_Set handle_set;
  handle_set.reset ();
  handle_set.set_bit (this->get_handle ());
  io_vec->iov_base = 0;
  // Check the status of the current socket.
  int select_width;
#  if defined (ACE_WIN32)
  // This arg is ignored on Windows and causes pointer truncation
  // warnings on 64-bit compiles.
  select_width = 0;
#  else
  select_width = int (this->get_handle ()) + 1;
#  endif /* ACE_WIN32 */
  switch (ACE_OS::select (select_width,
                          handle_set,
                          0, 0,
                          timeout))
    {
    case -1:
      return -1;
      /* NOTREACHED */
    case 0:
      errno = ETIME;
      return -1;
      /* NOTREACHED */
    default:
      // Goes fine, fallthrough to get data
      break;
    }
  int inlen = 0;
  if (ACE_OS::ioctl (this->get_handle (),
                     FIONREAD,
                     &inlen) == -1)
    return -1;
  else if (inlen > 0)
    {
      ACE_NEW_RETURN (io_vec->iov_base,
                      char[inlen],
                      -1);
      // It's ok to blindly cast this value since 'inlen' is an int and, thus,
      // we can't get more than that back. Besides, if the recv() fails, we
      // don't want that value cast to unsigned and returned.
      ssize_t recv_len = this->recv (io_vec->iov_base, inlen);
      if (recv_len > 0)
        // u_long is the Windows type; size_t is everyone else's. A u_long
        // should go into a size_t anywhere without an issue.
        io_vec->iov_len = static_cast<u_long> (recv_len);
      return recv_len;
    }
  else
    return 0;
#else
  ACE_UNUSED_ARG (io_vec);
  ACE_UNUSED_ARG (timeout);
  ACE_NOTSUP_RETURN (-1);
#endif /* FIONREAD */
}
// Send N char *ptrs and int lengths.  Note that the char *'s precede
// the ints (basically, an varargs version of writev).  The count N is
// the *total* number of trailing arguments, *not* a couple of the
// number of tuple pairs!
ssize_t
ACE_SOCK_IO::send (size_t n, ...) const
{
  ACE_TRACE ("ACE_SOCK_IO::send");
  va_list argp;
  int const total_tuples = ACE_Utils::truncate_cast<int> (n / 2);
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
  ssize_t const result = ACE_OS::sendv (this->get_handle (),
                                        iovp,
                                        total_tuples);
#if !defined (ACE_HAS_ALLOCA)
  delete [] iovp;
#endif /* !defined (ACE_HAS_ALLOCA) */
  va_end (argp);
  return result;
}
// This is basically an interface to ACE_OS::readv, that doesn't use
// the struct iovec_Base explicitly.  The ... can be passed as an arbitrary
// number of (char *ptr, int len) tuples.  However, the count N is the
// *total* number of trailing arguments, *not* a couple of the number
// of tuple pairs!
ssize_t
ACE_SOCK_IO::recv (size_t n, ...) const
{
  ACE_TRACE ("ACE_SOCK_IO::recv");
  va_list argp;
  int const total_tuples = ACE_Utils::truncate_cast<int> (n / 2);
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
  ssize_t const result = ACE_OS::recvv (this->get_handle (),
                                        iovp,
                                        total_tuples);
#if !defined (ACE_HAS_ALLOCA)
  delete [] iovp;
#endif /* !defined (ACE_HAS_ALLOCA) */
  va_end (argp);
  return result;
}
ACE_END_VERSIONED_NAMESPACE_DECL

