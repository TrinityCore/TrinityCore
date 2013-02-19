// $Id: SOCK_Stream.cpp 91286 2010-08-05 09:04:31Z johnnyw $

#include "ace/SOCK_Stream.h"

#if !defined (__ACE_INLINE__)
#include "ace/SOCK_Stream.inl"
#endif /* __ACE_INLINE__ */



ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_ALLOC_HOOK_DEFINE(ACE_SOCK_Stream)

void
ACE_SOCK_Stream::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_SOCK_Stream::dump");
#endif /* ACE_HAS_DUMP */
}

int
ACE_SOCK_Stream::close (void)
{
#if defined (ACE_WIN32)
  // We need the following call to make things work correctly on
  // Win32, which requires us to do a close_writer() before doing the
  // close() in order to avoid losing data.  Note that we don't need
  // to do this on UNIX since it doesn't have this "feature".
  // Moreover, this will cause subtle problems on UNIX due to the way
  // that fork() works.
  (void) this->close_writer ();
 #endif /* ACE_WIN32 */

  // Close down the socket.
  return ACE_SOCK::close ();
}

ACE_END_VERSIONED_NAMESPACE_DECL
