// $Id: MEM_Stream.cpp 80826 2008-03-04 14:51:23Z wotte $

#include "ace/MEM_Stream.h"

#if (ACE_HAS_POSITION_INDEPENDENT_POINTERS == 1)

#if !defined (__ACE_INLINE__)
#include "ace/MEM_Stream.inl"
#endif /* __ACE_INLINE__ */

ACE_RCSID(ace, MEM_Stream, "$Id: MEM_Stream.cpp 80826 2008-03-04 14:51:23Z wotte $")

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_ALLOC_HOOK_DEFINE(ACE_MEM_Stream)

void
ACE_MEM_Stream::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_MEM_Stream::dump");
#endif /* ACE_HAS_DUMP */
}

int
ACE_MEM_Stream::close (void)
{
  this->send ((char *)0, 0);

  this->fini ();

#if defined (ACE_WIN32)
  // We need the following call to make things work correctly on
  // Win32, which requires use to do a <close_writer> before doing the
  // close in order to avoid losing data.  Note that we don't need to
  // do this on UNIX since it doesn't have this "feature".  Moreover,
  // this will cause subtle problems on UNIX due to the way that
  // fork() works.
  this->close_writer ();
#endif /* ACE_WIN32 */
  // Close down the socket.
  return ACE_SOCK::close ();
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_HAS_POSITION_INDEPENDENT_POINTERS == 1 */
