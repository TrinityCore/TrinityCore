// $Id: OS_NS_sys_sendfile.cpp 80826 2008-03-04 14:51:23Z wotte $

#include "ace/OS_NS_sys_sendfile.h"
#include "ace/OS_NS_sys_mman.h"

#if defined (ACE_WIN32) || defined (HPUX)
# include "ace/OS_NS_sys_socket.h"
#else
# include "ace/OS_NS_unistd.h"
#endif  /* ACE_WIN32 || HPUX */

#ifndef ACE_HAS_INLINED_OSCALLS
# include "ace/OS_NS_sys_sendfile.inl"
#endif  /* ACE_HAS_INLINED_OSCALLS */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

#ifndef ACE_HAS_SENDFILE
ssize_t
ACE_OS::sendfile_emulation (ACE_HANDLE out_fd,
                            ACE_HANDLE in_fd,
                            off_t * offset,
                            size_t count)
{
  // @@ Is it possible to inline a call to ::TransmitFile() on
  //    MS Windows instead of emulating here?

  // @@ We may want set up a signal lease (or oplock) if supported by
  //    the platform so that we don't get a bus error if the mmap()ed
  //    file is truncated.
  void * const buf =
    ACE_OS::mmap (0, count, PROT_READ, MAP_SHARED, in_fd, *offset);

  if (buf == MAP_FAILED)
    return -1;

#if defined (ACE_WIN32) || defined (HPUX)
  ssize_t const r =
    ACE_OS::send (out_fd, static_cast<const char *> (buf), count);
#else
  ssize_t const r = ACE_OS::write (out_fd, buf, count);
#endif /* ACE_WIN32 */

  (void) ACE_OS::munmap (buf, count);

  if (r > 0)
    *offset += static_cast<off_t> (r);

  return r;
}
#endif  /* !ACE_HAS_SENDFILE */

ACE_END_VERSIONED_NAMESPACE_DECL

