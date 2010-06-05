// $Id: SPIPE_Connector.cpp 80826 2008-03-04 14:51:23Z wotte $

#include "ace/SPIPE_Connector.h"
#include "ace/Log_Msg.h"
#include "ace/OS_NS_sys_time.h"
#include "ace/OS_NS_fcntl.h"
#include "ace/OS_NS_unistd.h"

#if !defined (__ACE_INLINE__)
#include "ace/SPIPE_Connector.inl"
#endif /* __ACE_INLINE__ */

ACE_RCSID(ace, SPIPE_Connector, "$Id: SPIPE_Connector.cpp 80826 2008-03-04 14:51:23Z wotte $")

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_ALLOC_HOOK_DEFINE(ACE_SPIPE_Connector)

// Creates a Local ACE_SPIPE.

ACE_SPIPE_Connector::ACE_SPIPE_Connector (ACE_SPIPE_Stream &new_io,
                                          const ACE_SPIPE_Addr &remote_sap,
                                          ACE_Time_Value *timeout,
                                          const ACE_Addr & local_sap,
                                          int reuse_addr,
                                          int flags,
                                          int perms,
            LPSECURITY_ATTRIBUTES sa,
            int pipe_mode)
{
  ACE_TRACE ("ACE_SPIPE_Connector::ACE_SPIPE_Connector");
  if (this->connect (new_io, remote_sap, timeout, local_sap,
                     reuse_addr, flags, perms, sa, pipe_mode) == -1
      && timeout != 0 && !(errno == EWOULDBLOCK || errno == ETIME))
    ACE_ERROR ((LM_ERROR, ACE_TEXT ("address %s, %p\n"),
               remote_sap.get_path_name (), ACE_TEXT ("ACE_SPIPE_Connector")));
}

void
ACE_SPIPE_Connector::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_SPIPE_Connector::dump");
#endif /* ACE_HAS_DUMP */
}

ACE_SPIPE_Connector::ACE_SPIPE_Connector (void)
{
  ACE_TRACE ("ACE_SPIPE_Connector::ACE_SPIPE_Connector");
}

int
ACE_SPIPE_Connector::connect (ACE_SPIPE_Stream &new_io,
                              const ACE_SPIPE_Addr &remote_sap,
                              ACE_Time_Value *timeout,
                              const ACE_Addr & /* local_sap */,
                              int /* reuse_addr */,
                              int flags,
                              int perms,
                              LPSECURITY_ATTRIBUTES sa,
                              int pipe_mode)
{
  ACE_TRACE ("ACE_SPIPE_Connector::connect");
  // Make darn sure that the O_CREAT flag is not set!
  ACE_CLR_BITS (flags, O_CREAT);

  ACE_HANDLE handle;

  ACE_UNUSED_ARG (pipe_mode);
#if defined (ACE_WIN32) && \
   !defined (ACE_HAS_PHARLAP) && !defined (ACE_HAS_WINCE)
  // We need to allow for more than one attempt to connect,
  // calculate the absolute time at which we give up.
  ACE_Time_Value absolute_time;
  if (timeout != 0)
    absolute_time = ACE_OS::gettimeofday () + *timeout;

  // Loop until success or failure.
  for (;;)
    {
      handle = ACE_OS::open (remote_sap.get_path_name(), flags, perms, sa);
      if (handle != ACE_INVALID_HANDLE)
        // Success!
        break;

      // Check if we have a busy pipe condition.
      if (::GetLastError() != ERROR_PIPE_BUSY)
        // Nope, this is a failure condition.
        break;

      // This will hold the time out value used in the ::WaitNamedPipe
      // call.
      DWORD time_out_value;

      // Check if we are to block until we connect.
      if (timeout == 0)
        // Wait for as long as it takes.
        time_out_value = NMPWAIT_WAIT_FOREVER;
      else
        {
          // Calculate the amount of time left to wait.
          ACE_Time_Value relative_time (absolute_time - ACE_OS::gettimeofday ());
          // Check if we have run out of time.
          if (relative_time <= ACE_Time_Value::zero)
            {
              // Mimick the errno value returned by
              // ACE::handle_timed_open.
              if (*timeout == ACE_Time_Value::zero)
                errno = EWOULDBLOCK;
              else
                errno = ETIMEDOUT;
              // Exit the connect loop with the failure.
              break;
            }
          // Get the amount of time remaining for ::WaitNamedPipe.
          time_out_value = relative_time.msec ();

        }

      // Wait for the named pipe to become available.
      ACE_TEXT_WaitNamedPipe (remote_sap.get_path_name (),
                              time_out_value);

      // Regardless of the return value, we'll do one more attempt to
      // connect to see if it is now available and to return
      // consistent error values.
    }

  // Set named pipe mode if we have a valid handle.
  if (handle != ACE_INVALID_HANDLE)
    {
      // Check if we are changing the pipe mode from the default.
      if (pipe_mode != (PIPE_READMODE_BYTE | PIPE_WAIT))
        {
          DWORD dword_pipe_mode = pipe_mode;
          if (!::SetNamedPipeHandleState (handle,
                                          &dword_pipe_mode,
                                          0,
                                          0))
            {
              // We were not able to put the pipe into the requested
              // mode.
              ACE_OS::close (handle);
              handle = ACE_INVALID_HANDLE;
            }
        }
    }
#else /* ACE_WIN32 && !ACE_HAS_PHARLAP */
  handle = ACE::handle_timed_open (timeout,
                                              remote_sap.get_path_name (),
                                              flags, perms, sa);
#endif /* !ACE_WIN32 || ACE_HAS_PHARLAP || ACE_HAS_WINCE */

  new_io.set_handle (handle);
  new_io.remote_addr_ = remote_sap; // class copy.

  return handle == ACE_INVALID_HANDLE ? -1 : 0;
}

ACE_END_VERSIONED_NAMESPACE_DECL

