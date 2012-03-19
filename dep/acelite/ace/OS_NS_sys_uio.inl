// -*- C++ -*-
//
// $Id: OS_NS_sys_uio.inl 80826 2008-03-04 14:51:23Z wotte $

#include "ace/os_include/os_errno.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_INLINE ssize_t
ACE_OS::readv (ACE_HANDLE handle,
               const iovec *iov,
               int iovlen)
{
  ACE_OS_TRACE ("ACE_OS::readv");
#if defined (ACE_LACKS_READV)
  ACE_OSCALL_RETURN (ACE_OS::readv_emulation (handle, iov, iovlen),
                     ssize_t,
                     -1);
#else /* ACE_LACKS_READV */
#if defined (ACE_HAS_NONCONST_READV)
  ACE_OSCALL_RETURN (::readv (handle,
                              const_cast<iovec *>(iov),
                              iovlen), ssize_t, -1);
#else
  ACE_OSCALL_RETURN (::readv (handle,
                              iov,
                              iovlen), ssize_t, -1);
#endif /* ACE_HAS_NONCONST_READV */
#endif /* ACE_LACKS_READV */
}

ACE_INLINE ssize_t
ACE_OS::writev (ACE_HANDLE handle,
                const iovec *iov,
                int iovcnt)
{
  ACE_OS_TRACE ("ACE_OS::writev");
#if defined (ACE_LACKS_WRITEV)
  ACE_OSCALL_RETURN (ACE_OS::writev_emulation (handle,
                                               iov,
                                               iovcnt), ssize_t, -1);
#else /* ACE_LACKS_WRITEV */
#if defined (ACE_HAS_NONCONST_WRITEV)
  ACE_OSCALL_RETURN (::writev (handle,
                               const_cast<iovec *>(iov),
                               iovcnt), ssize_t, -1);
#else
  ACE_OSCALL_RETURN (::writev (handle,
                               iov,
                               iovcnt), ssize_t, -1);
#endif /* ACE_HAS_NONCONST_WRITEV */
#endif /* ACE_LACKS_WRITEV */
}

ACE_END_VERSIONED_NAMESPACE_DECL
