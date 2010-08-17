// $Id: OS_NS_sys_uio.cpp 81756 2008-05-22 09:47:33Z johnnyw $

#include "ace/OS_NS_sys_uio.h"

ACE_RCSID(ace, OS_NS_sys_uio, "$Id: OS_NS_sys_uio.cpp 81756 2008-05-22 09:47:33Z johnnyw $")

#if !defined (ACE_HAS_INLINED_OSCALLS)
# include "ace/OS_NS_sys_uio.inl"
#endif /* ACE_HAS_INLINED_OSCALLS */

#include "ace/OS_Memory.h"
#include "ace/OS_NS_string.h"
#include "ace/OS_NS_unistd.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

# if defined (ACE_LACKS_READV)

// "Fake" readv for operating systems without it.  Note that this is
// thread-safe.

ssize_t
ACE_OS::readv_emulation (ACE_HANDLE handle,
                         const iovec *iov,
                         int n)
{
  ACE_OS_TRACE ("ACE_OS::readv_emulation");

  // In case there's a single element, skip the memcpy.
  if (1 == n)
    return ACE_OS::read (handle, iov[0].iov_base, iov[0].iov_len);

  ssize_t length = 0;
  int i;

  for (i = 0; i < n; ++i)
    if (static_cast<int> (iov[i].iov_len) < 0)
      return -1;
    else
      length += iov[i].iov_len;

  char *buf;
#   if defined (ACE_HAS_ALLOCA)
  buf = (char *) alloca (length);
#   else
  ACE_NEW_RETURN (buf,
                  char[length],
                  -1);
#   endif /* !defined (ACE_HAS_ALLOCA) */

  length = ACE_OS::read (handle, buf, length);

  if (length != -1)
    {
      char *ptr = buf;
      ssize_t copyn = length;

      for (i = 0;
           i < n && copyn > 0;
           ++i)
        {
          ACE_OS::memcpy (iov[i].iov_base, ptr,
                          // iov_len is int on some platforms, size_t on others
                          copyn > (int) iov[i].iov_len
                            ? (size_t) iov[i].iov_len
                            : (size_t) copyn);
          ptr += iov[i].iov_len;
          copyn -= iov[i].iov_len;
        }
    }

#   if !defined (ACE_HAS_ALLOCA)
  delete [] buf;
#   endif /* !defined (ACE_HAS_ALLOCA) */
  return length;
}
# endif /* ACE_LACKS_READV */

# if defined (ACE_LACKS_WRITEV)

// "Fake" writev for operating systems without it.  Note that this is
// thread-safe.

ssize_t
ACE_OS::writev_emulation (ACE_HANDLE handle, const iovec *iov, int n)
{
  ACE_OS_TRACE ("ACE_OS::writev_emulation");

  // To avoid having to allocate a temporary buffer to which all of
  // the data will be copied and then written, this implementation
  // performs incremental writes.

  ssize_t bytes_sent = 0;

  for (int i = 0; i < n; ++i)
    {
      ssize_t const result =
        ACE_OS::write (handle, iov[i].iov_base, iov[i].iov_len);

      if (result == -1)
        {
          // There is a subtle difference in behaviour depending on
          // whether or not any data was sent.  If no data was sent,
          // then always return -1.  Otherwise return bytes_sent.
          // This gives the caller an opportunity to keep track of
          // bytes that have already been sent.
          if (bytes_sent > 0)
            break;
          else
            return -1;
        }
      else
        {
          bytes_sent += result;

          // Do not continue on to the next loop iteration if the
          // amount of data sent was less than the amount data given.
          // This avoids a subtle problem where "holes" in the data
          // stream would occur if partial sends of a given buffer in
          // the iovec array occured.
          if (static_cast<size_t> (result) < iov[i].iov_len)
            break;
        }
    }

  return bytes_sent;
}
# endif /* ACE_LACKS_WRITEV */

ACE_END_VERSIONED_NAMESPACE_DECL
