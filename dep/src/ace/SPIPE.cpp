// $Id: SPIPE.cpp 80826 2008-03-04 14:51:23Z wotte $

#include "ace/SPIPE.h"

#include "ace/OS_NS_unistd.h"

#if !defined (__ACE_INLINE__)
#include "ace/SPIPE.inl"
#endif /* __ACE_INLINE__ */

ACE_RCSID(ace, SPIPE, "$Id: SPIPE.cpp 80826 2008-03-04 14:51:23Z wotte $")

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_ALLOC_HOOK_DEFINE(ACE_SPIPE)

// This is the do-nothing constructor.

ACE_SPIPE::ACE_SPIPE (void)
{
  // ACE_TRACE ("ACE_SPIPE::ACE_SPIPE");
}

void
ACE_SPIPE::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_SPIPE::dump");
#endif /* ACE_HAS_DUMP */
}

// Close down a ACE_SPIPE.

int
ACE_SPIPE::get_local_addr (ACE_SPIPE_Addr &local_sap) const
{
  ACE_TRACE ("ACE_SPIPE::get_local_addr");
  local_sap = this->local_addr_;
  return 0;
}

// Close down the STREAM pipe without removing the rendezvous point.

int
ACE_SPIPE::close (void)
{
  ACE_TRACE ("ACE_SPIPE::close");
  int result = 0;

  if (this->get_handle () != ACE_INVALID_HANDLE)
    {
      result = ACE_OS::close (this->get_handle ());
#if defined (ACE_HAS_STREAM_PIPES)
      result = (ACE_OS::close (duplex_pipe_handle_) || result);
#endif /* ACE_HAS_STREAM_PIPES */
      this->set_handle (ACE_INVALID_HANDLE);
    }
  return result;
}

// Close down the STREAM pipe and remove the rendezvous point from the
// file system.

int
ACE_SPIPE::remove (void)
{
  ACE_TRACE ("ACE_SPIPE::remove");
  int result = this->close ();
  return ACE_OS::unlink (this->local_addr_.get_path_name ()) == -1 || result == -1 ? -1 : 0;
}

#if defined (ACE_HAS_STREAM_PIPES)
/// Temporary store of duplex pipe handle.
void
ACE_SPIPE::set_duplex_handle (ACE_HANDLE handle)
{
  ACE_TRACE ("ACE_SPIPE::set_duplex_handle");
  this->duplex_pipe_handle_ = handle;
}
#endif /* ACE_HAS_STREAM_PIPES */

ACE_END_VERSIONED_NAMESPACE_DECL

