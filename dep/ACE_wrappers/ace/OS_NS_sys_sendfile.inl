// -*- C++ -*-
//
// $Id: OS_NS_sys_sendfile.inl 80826 2008-03-04 14:51:23Z wotte $

#ifdef ACE_HAS_SENDFILE
# include <sys/sendfile.h>
#endif  /* ACE_HAS_SENDFILE */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_INLINE ssize_t
ACE_OS::sendfile (ACE_HANDLE out_fd,
                  ACE_HANDLE in_fd,
                  off_t * offset,
                  size_t count)
{
#ifdef ACE_HAS_SENDFILE
  return ::sendfile (out_fd, in_fd, offset, count);
#else
  return ACE_OS::sendfile_emulation (out_fd, in_fd, offset, count);
#endif  /* ACE_HAS_SENDFILE */
}

ACE_END_VERSIONED_NAMESPACE_DECL
