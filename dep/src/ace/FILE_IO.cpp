// $Id: FILE_IO.cpp 82559 2008-08-07 20:23:07Z parsons $

#include "ace/FILE_IO.h"

#include "ace/Log_Msg.h"
#include "ace/OS_NS_sys_stat.h"
#include "ace/OS_Memory.h"
#include "ace/Truncate.h"

#if !defined (__ACE_INLINE__)
#include "ace/FILE_IO.inl"
#endif /* __ACE_INLINE__ */

ACE_RCSID(ace, FILE_IO, "$Id: FILE_IO.cpp 82559 2008-08-07 20:23:07Z parsons $")

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_ALLOC_HOOK_DEFINE(ACE_FILE_IO)

void
ACE_FILE_IO::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_FILE_IO::dump");

  ACE_DEBUG ((LM_DEBUG, ACE_BEGIN_DUMP, this));
  this->addr_.dump ();
  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
#endif /* ACE_HAS_DUMP */
}

// Simple-minded do nothing constructor.

ACE_FILE_IO::ACE_FILE_IO (void)
{
  ACE_TRACE ("ACE_FILE_IO::ACE_FILE_IO");
}

// Send N char *ptrs and int lengths.  Note that the char *'s precede
// the ints (basically, an varargs version of writev).  The count N is
// the *total* number of trailing arguments, *not* a couple of the
// number of tuple pairs!

ssize_t
ACE_FILE_IO::send (size_t n, ...) const
{
  ACE_TRACE ("ACE_FILE_IO::send");
  va_list argp;
  int total_tuples = ACE_Utils::truncate_cast<int> (n / 2);
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
      iovp[i].iov_len  = va_arg (argp, int);
    }

  ssize_t result = ACE_OS::writev (this->get_handle (),
                                   iovp,
                                   total_tuples);
#if !defined (ACE_HAS_ALLOCA)
  delete [] iovp;
#endif /* !defined (ACE_HAS_ALLOCA) */
  va_end (argp);
  return result;
}

// This is basically an interface to ACE_OS::readv, that doesn't use
// the struct iovec explicitly.  The ... can be passed as an arbitrary
// number of (char *ptr, int len) tuples.  However, the count N is the
// *total* number of trailing arguments, *not* a couple of the number
// of tuple pairs!

ssize_t
ACE_FILE_IO::recv (size_t n, ...) const
{
  ACE_TRACE ("ACE_FILE_IO::recv");
  va_list argp;
  int total_tuples = ACE_Utils::truncate_cast<int> (n / 2);
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
      iovp[i].iov_len  = va_arg (argp, int);
    }

  ssize_t const result = ACE_OS::readv (this->get_handle (),
                                        iovp,
                                        total_tuples);
#if !defined (ACE_HAS_ALLOCA)
  delete [] iovp;
#endif /* !defined (ACE_HAS_ALLOCA) */
  va_end (argp);
  return result;
}

// Allows a client to read from a file without having to provide a
// buffer to read.  This method determines how much data is in the
// file, allocates a buffer of this size, reads in the data, and
// returns the number of bytes read.

ssize_t
ACE_FILE_IO::recvv (iovec *io_vec)
{
  ACE_TRACE ("ACE_FILE_IO::recvv");

  io_vec->iov_base = 0;
  size_t const length =
    static_cast <size_t> (ACE_OS::filesize (this->get_handle ()));

  if (length > 0)
    {
      ACE_NEW_RETURN (io_vec->iov_base,
                      char[length],
                      -1);
      io_vec->iov_len = this->recv_n (io_vec->iov_base,
                                      length);
      return io_vec->iov_len;
    }
  else
    {
      return ACE_Utils::truncate_cast<ssize_t> (length);
    }
}

ACE_END_VERSIONED_NAMESPACE_DECL

