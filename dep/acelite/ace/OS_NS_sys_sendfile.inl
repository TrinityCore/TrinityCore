// -*- C++ -*-
//
// $Id: OS_NS_sys_sendfile.inl 84216 2009-01-22 18:34:40Z johnnyw $

#if defined ACE_HAS_SENDFILE && ACE_HAS_SENDFILE == 1
# include <sys/sendfile.h>
#endif  /* ACE_HAS_SENDFILE==1 */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_INLINE ssize_t
ACE_OS::sendfile (ACE_HANDLE out_fd,
                  ACE_HANDLE in_fd,
                  off_t * offset,
                  size_t count)
{
#if defined ACE_HAS_SENDFILE && ACE_HAS_SENDFILE == 1
  return ::sendfile (out_fd, in_fd, offset, count);
#else
  return ACE_OS::sendfile_emulation (out_fd, in_fd, offset, count);
#endif  /* ACE_HAS_SENDFILE==1 */
}

ACE_END_VERSIONED_NAMESPACE_DECL
