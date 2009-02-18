// $Id: SPIPE_Acceptor.cpp 80826 2008-03-04 14:51:23Z wotte $

#include "ace/SPIPE_Acceptor.h"
#include "ace/Log_Msg.h"
#include "ace/OS_NS_sys_stat.h"
#include "ace/OS_NS_sys_time.h"

#if defined (ACE_HAS_STREAM_PIPES)
#  include "ace/OS_NS_unistd.h"
#endif  // ACE_HAS_STREAM_PIPES

ACE_RCSID(ace, SPIPE_Acceptor, "$Id: SPIPE_Acceptor.cpp 80826 2008-03-04 14:51:23Z wotte $")

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_SPIPE_Acceptor::ACE_SPIPE_Acceptor (void)
#if defined (ACE_HAS_WIN32_NAMED_PIPES)
  : sa_ (0), pipe_handle_ (ACE_INVALID_HANDLE)
#endif /* ACE_HAS_WIN32_NAMED_PIPES */
{
  ACE_TRACE ("ACE_SPIPE_Acceptor::ACE_SPIPE_Acceptor");
}

int
ACE_SPIPE_Acceptor::remove (void)
{
  ACE_TRACE ("ACE_SPIPE_Acceptor::remove");
#if defined (ACE_HAS_STREAM_PIPES)
  int result = this->close ();

  // Remove the underlying file.
  return ACE_OS::unlink (this->local_addr_.get_path_name ()) == -1
    || result == -1 ? -1 : 0;
#else
  this->close ();
  return 0;
#endif
}

ACE_ALLOC_HOOK_DEFINE (ACE_SPIPE_Acceptor)

void
ACE_SPIPE_Acceptor::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_SPIPE_Acceptor::dump");
#endif /* ACE_HAS_DUMP */
}

// General purpose routine for performing server ACE_SPIPE creation.

int
ACE_SPIPE_Acceptor::open (const ACE_SPIPE_Addr &local_sap,
                          int reuse_addr,
                          int perms,
                          LPSECURITY_ATTRIBUTES sa,
                          int pipe_mode)
{
  ACE_TRACE ("ACE_SPIPE_Acceptor::open");
  ACE_UNUSED_ARG (reuse_addr);

  this->local_addr_ = local_sap;
  this->set_handle (ACE_INVALID_HANDLE);
#if defined (ACE_HAS_WIN32_NAMED_PIPES)
  this->sa_ = sa;
  this->pipe_mode_ = pipe_mode;
#else
  ACE_UNUSED_ARG (sa);
  ACE_UNUSED_ARG (pipe_mode);
#endif /* ACE_HAS_WIN32_NAMED_PIPES */

  return this->create_new_instance (perms);
}

int
ACE_SPIPE_Acceptor::create_new_instance (int perms)
{
#if defined (ACE_HAS_STREAM_PIPES)
  ACE_HANDLE spipe[2];
  char module[] = "connld";

  ACE_HANDLE handle = ACE_OS::creat (this->local_addr_.get_path_name (),
                                     perms);
  if (handle == ACE_INVALID_HANDLE)
    return -1;
  else if (ACE_OS::close (handle) == -1)
    return -1;
  else if (ACE_OS::pipe (spipe) == -1)
    return -1;
  else if (ACE_OS::ioctl (spipe[0],
                          I_PUSH,
                          module) == -1)
    return -1;
  else if (-1 == ACE_OS::fattach(spipe[0],
                                 ACE_TEXT_ALWAYS_CHAR (
                                   this->local_addr_.get_path_name ())))
    return -1;

  this->set_duplex_handle (spipe[0]);
  this->set_handle (spipe[1]);
  return 0;

#elif defined (ACE_HAS_WIN32_NAMED_PIPES)
  // Create a new instance of the Named Pipe (WIN32).  A new instance
  // of the named pipe must be created for every client process.  If
  // an instance of the named pipe that is already connected to a
  // client process is reused with a new client process,
  // ::ConnectNamedPipe () would fail.

  ACE_UNUSED_ARG (perms);
  ACE_TRACE ("ACE_SPIPE_Acceptor::create_new_instance");
  int status;

  // Create a new instance of the named pipe
  this->pipe_handle_ =
#if defined (ACE_USES_WCHAR)
    ::CreateNamedPipeW (
#else /* ACE_USES_WCHAR */
    ::CreateNamedPipeA (
#endif /* ACE_USES_WCHAR */
                        this->local_addr_.get_path_name (),
                        PIPE_ACCESS_DUPLEX
                        | FILE_FLAG_OVERLAPPED,
                        pipe_mode_,
                        PIPE_UNLIMITED_INSTANCES,
                        1024 * 10,
                        1024 * 10,
                        ACE_DEFAULT_TIMEOUT,
                        this->sa_);

  if (this->pipe_handle_ == ACE_INVALID_HANDLE)
    return -1;
  else
    {
      // Start the Connect (analogous to listen () for a socket).
      // Completion is noted by the event being signalled.  If a
      // client connects before this call, the error status will be
      // ERROR_PIPE_CONNECTED.  If the client also disconnects before
      // this call, the error status will be ERROR_NO_DATA.  In both
      // cases, that fact is remembered via already_connected_ and
      // noted when the user calls accept().  Else the error status
      // should be ERROR_IO_PENDING and the OS will signal the event
      // when it's done.
      this->already_connected_ = 0;
      this->set_handle (this->event_.handle ());
      this->overlapped_.hEvent = this->event_.handle ();
      this->event_.reset ();

      BOOL result = ::ConnectNamedPipe (this->pipe_handle_,
                                        &this->overlapped_);
      ACE_UNUSED_ARG (result);
      // ConnectNamePipe is suppose to always
      // "fail" when passed in overlapped i/o
      ACE_ASSERT (!result);

      status = ::GetLastError ();
      switch (status)
        {
        case ERROR_IO_PENDING:
          break;
        case ERROR_PIPE_CONNECTED:
        case ERROR_NO_DATA:
          this->already_connected_ = 1;
          // Set the associated event as signaled so any reactors or
          // proactors waiting for this will respond.
          this->event_.signal ();
          break;
        default:
          ACE_ASSERT (FALSE);    // An undocumented error was returned.
          this->close ();        // Sets handle to ACE_INVALID_HANDLE.
          break;
        }
    }
  return this->get_handle () == ACE_INVALID_HANDLE ? -1 : 0;
#else
  ACE_UNUSED_ARG (perms);
  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_HAS_STREAM_PIPES */
}

int
ACE_SPIPE_Acceptor::close (void)
{
  ACE_TRACE ("ACE_SPIPE_Acceptor::close");

#if defined (ACE_HAS_WIN32_NAMED_PIPES)

  // Check to see if we have a valid pipe; if not, nothing to do.
  if (this->pipe_handle_ == ACE_INVALID_HANDLE)
    return -1;

  // Substitute the pipe handle back in so it's closed properly in the
  // ACE_OS wrapper. But leave the pipe_handle_ value so we can clean up the
  // hanging overlapped operation afterwards.
  this->set_handle (this->pipe_handle_);

#endif /* ACE_HAS_WIN32_NAMED_PIPES */

  // This behavior is shared by UNIX and Win32...
  int result = this->ACE_SPIPE::close ();
  this->set_handle (ACE_INVALID_HANDLE);

#if defined (ACE_HAS_STREAM_PIPES)
  ACE_OS::fdetach (ACE_TEXT_ALWAYS_CHAR (this->local_addr_.get_path_name ()));
#elif defined (ACE_HAS_WIN32_NAMED_PIPES)

  // open () started the Connect in asynchronous mode, and accept() restarts
  // the ConnectNamedPipe in overlapped mode.  To avoid leaving a hanging
  // overlapped operation that'll write into members of this object,
  // wait for the event in the OVERLAPPED structure to be signalled.
  if (this->already_connected_ == 0)
    {
      if (this->event_.wait () != -1)
        {
          // Should be here with the ConnectNamedPipe operation complete.
          // Steal the already_connected_ flag to record the results.
          DWORD unused;
          ::GetOverlappedResult (this->pipe_handle_,
                                 &this->overlapped_,
                                 &unused,
                                 FALSE);
        }
      this->pipe_handle_ = ACE_INVALID_HANDLE;
      this->already_connected_ = 0;
    }
#endif /* ACE_HAS_STREAM_PIPES */

  return result;
}

ACE_SPIPE_Acceptor::ACE_SPIPE_Acceptor (const ACE_SPIPE_Addr &local_sap,
                                        int reuse_addr,
                                        int perms,
                                        LPSECURITY_ATTRIBUTES sa,
                                        int pipe_mode)
{
  ACE_TRACE ("ACE_SPIPE_Acceptor::ACE_SPIPE_Acceptor");

  if (this->open (local_sap, reuse_addr, perms, sa, pipe_mode) == -1)
    ACE_ERROR ((LM_ERROR,
                ACE_TEXT ("%p\n"),
                ACE_TEXT ("ACE_SPIPE_Acceptor")));
}

// General purpose routine for accepting new connections.

int
ACE_SPIPE_Acceptor::accept (ACE_SPIPE_Stream &new_io,
                            ACE_SPIPE_Addr *remote_addr,
                            ACE_Time_Value *timeout,
                            int restart,
                            int reset_new_handle)
{
  ACE_TRACE ("ACE_SPIPE_Acceptor::accept");
  ACE_UNUSED_ARG (reset_new_handle);

#if defined (ACE_HAS_STREAM_PIPES)
  strrecvfd r_handle;

  // Note that if THIS->MILLI_SECOND_DELAY == -1 we block on
  // ACE_OS::ioctl (). Otherwise, we will wait for the desired number
  // of milli seconds using ACE_OS::poll.

  if (timeout != 0 &&
      ACE::handle_timed_accept (this->get_handle (),
                                timeout,
                                restart) == -1)
    return -1;
  else if (ACE_OS::ioctl (this->get_handle (),
                          I_RECVFD,
                          &r_handle) == -1)
    return -1;

  new_io.set_handle (r_handle.fd);
  new_io.local_addr_ = this->local_addr_;
  new_io.remote_addr_.set_size (sizeof r_handle.gid + sizeof r_handle.uid);
  new_io.remote_addr_.group_id (r_handle.gid);
  new_io.remote_addr_.user_id (r_handle.uid);

  // This is for compatibility with ACE_SOCK_Acceptor and
  // ACE_TLI_Acceptor.
  if (remote_addr != 0)
    *remote_addr = new_io.remote_addr_;

  return 0;
#elif defined (ACE_HAS_WIN32_NAMED_PIPES)
  ACE_UNUSED_ARG (restart);
  ACE_UNUSED_ARG (remote_addr);

  // Check to see if we have a valid pipe
  if (this->pipe_handle_ == ACE_INVALID_HANDLE)
    return -1;

  // open () started the Connect in asynchronous mode.  Wait for the event
  // in the OVERLAPPED structure to be signalled, then grab the status.
  if (this->already_connected_ == 0)
    {
      if (timeout != 0)
        {
          ACE_Time_Value abstime (ACE_OS::gettimeofday () + *timeout);
          if (this->event_.wait (&abstime) == -1)
            return -1;
        }
      else
        if (this->event_.wait () == -1)
          return -1;

      // Should be here with the ConnectNamedPipe operation complete.
      // Steal the already_connected_ flag to record the results.
      DWORD unused;
      this->already_connected_ = ::GetOverlappedResult (this->pipe_handle_,
                                                        &this->overlapped_,
                                                        &unused,
                                                        FALSE);
    }

  if (this->already_connected_)
    {
      new_io.set_handle (this->pipe_handle_);
      this->pipe_handle_ = ACE_INVALID_HANDLE;
      new_io.local_addr_ = this->local_addr_;

      // Create a new instance of the pipe for the next connection.
      this->create_new_instance ();
      return 0;
    }
  return -1;
#else
  ACE_UNUSED_ARG (restart);
  ACE_UNUSED_ARG (timeout);
  ACE_UNUSED_ARG (remote_addr);
  ACE_UNUSED_ARG (new_io);
  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_HAS_STREAM_PIPES */
}

ACE_END_VERSIONED_NAMESPACE_DECL

