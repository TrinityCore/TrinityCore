// $Id: UPIPE_Acceptor.cpp 80826 2008-03-04 14:51:23Z wotte $

#include "ace/UPIPE_Acceptor.h"

ACE_RCSID(ace, UPIPE_Acceptor, "$Id: UPIPE_Acceptor.cpp 80826 2008-03-04 14:51:23Z wotte $")

#if defined (ACE_HAS_THREADS)

#include "ace/OS_NS_unistd.h"

#if !defined (__ACE_INLINE__)
#include "ace/UPIPE_Acceptor.inl"
#endif /* __ACE_INLINE__ */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_ALLOC_HOOK_DEFINE(ACE_UPIPE_Acceptor)

void
ACE_UPIPE_Acceptor::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_UPIPE_Acceptor::dump");
#endif /* ACE_HAS_DUMP */
}

/* Do nothing routine for constructor. */

ACE_UPIPE_Acceptor::ACE_UPIPE_Acceptor (void)
  : mb_ (sizeof (ACE_UPIPE_Stream *))
{
  ACE_TRACE ("ACE_UPIPE_Acceptor::ACE_UPIPE_Acceptor");
}

ACE_UPIPE_Acceptor::~ACE_UPIPE_Acceptor (void)
{
  ACE_TRACE ("ACE_UPIPE_Acceptor::~ACE_UPIPE_Acceptor");
}

// General purpose routine for performing server ACE_UPIPE.

int
ACE_UPIPE_Acceptor::open (const ACE_UPIPE_Addr &local_addr,
                          int reuse_addr)
{
  ACE_TRACE ("ACE_UPIPE_Acceptor::open");
  return this->ACE_SPIPE_Acceptor::open (local_addr, reuse_addr);
}

int
ACE_UPIPE_Acceptor::close (void)
{
  ACE_TRACE ("ACE_UPIPE_Acceptor::close");
  return this->ACE_SPIPE_Acceptor::close ();
}

// General purpose routine for accepting new connections.

ACE_UPIPE_Acceptor::ACE_UPIPE_Acceptor (const ACE_UPIPE_Addr &local_addr,
                                        int reuse_addr)
  : mb_ (sizeof (ACE_UPIPE_Stream *))
{
  ACE_TRACE ("ACE_UPIPE_Acceptor::ACE_UPIPE_Acceptor");

  if (this->open (local_addr, reuse_addr) == -1)
    ACE_ERROR ((LM_ERROR,
                ACE_TEXT ("%p\n"),
                ACE_TEXT ("ACE_UPIPE_Acceptor")));
}

int
ACE_UPIPE_Acceptor::accept (ACE_UPIPE_Stream &new_stream,
                            ACE_UPIPE_Addr *remote_addr,
                            ACE_Time_Value *timeout,
                            int restart,
                            int reset_new_handle)
{
  ACE_TRACE ("ACE_UPIPE_Acceptor::accept");
  ACE_UNUSED_ARG (reset_new_handle);

  ACE_SPIPE_Stream new_io;

  if (this->ACE_SPIPE_Acceptor::accept (new_io, remote_addr,
                                        timeout, restart) == -1)
    return -1;
  else
    {
      ACE_UPIPE_Stream *remote_stream = 0;

      ACE_MT (ACE_GUARD_RETURN (ACE_Thread_Mutex, ace_mon, new_stream.lock_, -1));

      new_stream.set_handle (new_io.get_handle ());
      new_stream.reference_count_++;

      // Transfer address ownership.
      new_io.get_local_addr (new_stream.local_addr_);
      new_io.get_remote_addr (new_stream.remote_addr_);

      // Now that we got the handle, we'll read the address of the
      // connector-side ACE_UPIPE_Stream out of the pipe and link that
      // ACE_UPIPE_Stream to our ACE_UPIPE_Stream.

      if (ACE_OS::read (new_stream.get_handle (),
                        (char *) &remote_stream,
                        sizeof remote_stream) == -1)
        ACE_ERROR ((LM_ERROR,
                    ACE_TEXT ("ACE_UPIPE_Acceptor: %p\n"),
                    ACE_TEXT ("read stream address failed")));
      else if (new_stream.stream_.link (remote_stream->stream_) == -1)
        ACE_ERROR ((LM_ERROR,
                    ACE_TEXT ("ACE_UPIPE_Acceptor: %p\n"),
                    ACE_TEXT ("link streams failed")));
      // Send a message over the new streampipe to confirm acceptance.
      else if (new_stream.send (&mb_, 0) == -1)
        ACE_ERROR ((LM_ERROR,
                    ACE_TEXT ("ACE_UPIPE_Acceptor: %p\n"),
                    ACE_TEXT ("linked stream.put failed")));

      // Close down the new_stream at this point in order to conserve
      // handles.  Note that we don't need the SPIPE connection
      // anymore since we're now linked via the <Message_Queue>.
      new_stream.ACE_SPIPE::close ();
      return 0;
    }
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_HAS_THREADS */

