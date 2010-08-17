// $Id: MEM_Acceptor.cpp 84455 2009-02-13 13:31:02Z johnnyw $

#include "ace/MEM_Acceptor.h"

#if (ACE_HAS_POSITION_INDEPENDENT_POINTERS == 1)

#include "ace/OS_NS_stdio.h"
#include "ace/OS_NS_string.h"
#include "ace/OS_NS_sys_socket.h"
#include "ace/OS_NS_unistd.h"

#if !defined (__ACE_INLINE__)
#include "ace/MEM_Acceptor.inl"
#endif /* __ACE_INLINE__ */

ACE_RCSID(ace, MEM_Acceptor, "$Id: MEM_Acceptor.cpp 84455 2009-02-13 13:31:02Z johnnyw $")

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_ALLOC_HOOK_DEFINE(ACE_MEM_Acceptor)

void
ACE_MEM_Acceptor::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_MEM_Acceptor::dump");
#endif /* ACE_HAS_DUMP */
}

// Do nothing routine for constructor.

ACE_MEM_Acceptor::ACE_MEM_Acceptor (void)
  : mmap_prefix_ (0),
    malloc_options_ (ACE_DEFAULT_BASE_ADDR, 0),
    preferred_strategy_ (ACE_MEM_IO::Reactive)
{
  ACE_TRACE ("ACE_MEM_Acceptor::ACE_MEM_Acceptor");
}

ACE_MEM_Acceptor::~ACE_MEM_Acceptor (void)
{
  ACE_TRACE ("ACE_MEM_Acceptor::~ACE_MEM_Acceptor");
  delete[] this->mmap_prefix_;
}

// General purpose routine for performing server ACE_SOCK creation.

ACE_MEM_Acceptor::ACE_MEM_Acceptor (const ACE_MEM_Addr &remote_sap,
                                    int reuse_addr,
                                    int backlog,
                                    int protocol)
  : mmap_prefix_ (0),
    malloc_options_ (ACE_DEFAULT_BASE_ADDR, 0),
    preferred_strategy_ (ACE_MEM_IO::Reactive)
{
  ACE_TRACE ("ACE_MEM_Acceptor::ACE_MEM_Acceptor");
  if (this->open (remote_sap,
                  reuse_addr,
                  backlog,
                  protocol) == -1)
    ACE_ERROR ((LM_ERROR,
                ACE_TEXT ("ACE_MEM_Acceptor::ACE_MEM_Acceptor")));
}

int
ACE_MEM_Acceptor::open (const ACE_MEM_Addr &remote_sap,
                        int reuse_addr,
                        int back_log,
                        int protocol)
{
  ACE_TRACE ("ACE_MEM_Acceptor::open");
  return this->ACE_SOCK_Acceptor::open (remote_sap.get_local_addr (),
                                        reuse_addr,
                                        PF_INET,
                                        back_log,
                                        protocol);
}

// General purpose routine for accepting new connections.

int
ACE_MEM_Acceptor::accept (ACE_MEM_Stream &new_stream,
                          ACE_MEM_Addr *remote_sap,
                          ACE_Time_Value *timeout,
                          bool restart,
                          bool reset_new_handle)
{
  ACE_TRACE ("ACE_MEM_Acceptor::accept");

  int in_blocking_mode = 1;
  if (this->shared_accept_start (timeout,
                                 restart,
                                 in_blocking_mode) == -1)
    return -1;
  else
    {
      sockaddr *addr = 0;
      struct sockaddr_in inet_addr;
      int *len_ptr = 0;
      int len = 0;

      if (remote_sap != 0)
        {
          addr = reinterpret_cast<sockaddr *> (&inet_addr);
          len = sizeof (inet_addr);
          len_ptr = &len;
        }

      do
        // On Win32 the third parameter to <accept> must be a NULL
        // pointer if to ignore the client's address.
        new_stream.set_handle (ACE_OS::accept (this->get_handle (),
                                               addr,
                                               len_ptr));
      while (new_stream.get_handle () == ACE_INVALID_HANDLE
             && restart != 0
             && errno == EINTR
             && timeout == 0);

      if (remote_sap != 0)
        {
          ACE_INET_Addr temp (&inet_addr, len);
          remote_sap->set_port_number (temp.get_port_number ());
        }
    }

  if (this->shared_accept_finish (new_stream,
                                  in_blocking_mode,
                                  reset_new_handle) == -1)
    return -1;

  // Allocate 2 * MAXPATHLEN so we can accomodate the unique
  // name that gets appended later
  ACE_TCHAR buf [2 * MAXPATHLEN + 1];

  ACE_INET_Addr local_addr;
  if (new_stream.get_local_addr (local_addr) == -1)
    return -1;

  if (this->mmap_prefix_ != 0)
    {
      ACE_OS::sprintf (buf,
                       ACE_TEXT ("%s_%d_"),
                       this->mmap_prefix_,
                       local_addr.get_port_number ());
    }
  else
    {
      ACE_TCHAR name[25];
      // - 24 is so we can append name to the end.
      if (ACE::get_temp_dir (buf, MAXPATHLEN - 24) == -1)
        {
          ACE_ERROR ((LM_ERROR,
                      ACE_TEXT ("Temporary path too long, ")
                      ACE_TEXT ("defaulting to current directory\n")));
          buf[0] = 0;
        }

      ACE_OS::sprintf (name,
                       ACE_TEXT ("MEM_Acceptor_%d_"),
                       local_addr.get_port_number ());
      ACE_OS::strcat (buf, name);
    }
  ACE_TCHAR unique [MAXPATHLEN];
  ACE_OS::unique_name (&new_stream, unique, MAXPATHLEN);

  ACE_OS::strcat (buf, unique);

  // Make sure we have a fresh start.
  ACE_OS::unlink (buf);

  new_stream.disable (ACE_NONBLOCK);
  ACE_HANDLE new_handle = new_stream.get_handle ();

  // Protocol negociation:
  //   Tell the client side what level of signaling strategy
  //   we support.
  ACE_MEM_IO::Signal_Strategy client_signaling =
#if defined (ACE_WIN32) || !defined (_ACE_USE_SV_SEM)
    this->preferred_strategy_;
#else
    // We don't support MT.
    ACE_MEM_IO::Reactive;
#endif /* ACE_WIN32 || !_ACE_USE_SV_SEM */
  if (ACE::send (new_handle, &client_signaling,
                 sizeof (ACE_INT16)) == -1)
    ACE_ERROR_RETURN ((LM_DEBUG,
                       ACE_TEXT ("ACE_MEM_Acceptor::accept error sending strategy\n")),
                      -1);

  //   Now we get the signaling strategy the client support.
  if (ACE::recv (new_handle, &client_signaling,
                 sizeof (ACE_INT16)) == -1)
    ACE_ERROR_RETURN ((LM_DEBUG,
                       ACE_TEXT ("ACE_MEM_Acceptor::%p error receiving strategy\n"),
                       ACE_TEXT ("accept")),
                      -1);

  // Ensure minimum buffer size
  if (this->malloc_options_.minimum_bytes_ < ACE_MEM_STREAM_MIN_BUFFER)
    this->malloc_options_.minimum_bytes_ = ACE_MEM_STREAM_MIN_BUFFER;

  // Client will decide what signaling strategy to use.

  // Now set up the shared memory malloc pool.
  if (new_stream.init (buf,
                       static_cast<ACE_MEM_IO::Signal_Strategy> (client_signaling),
                       &this->malloc_options_) == -1)
    return -1;

  // @@ Need to handle timeout here.
  ACE_UINT16 buf_len = static_cast<ACE_UINT16> ((ACE_OS::strlen (buf) + 1) *
                                                sizeof (ACE_TCHAR));

  // No need to worry about byte-order because both parties should always
  // be on the same machine.
  if (ACE::send (new_handle, &buf_len, sizeof (ACE_UINT16)) == -1)
    return -1;

  // Now send the pathname of the mmap file.
  if (ACE::send (new_handle, buf, buf_len) == -1)
    return -1;
  return 0;
}

int
ACE_MEM_Acceptor::shared_accept_finish (ACE_MEM_Stream new_stream,
                                        int in_blocking_mode,
                                        bool reset_new_handle) const
{
  ACE_TRACE ("ACE_MEM_Acceptor::shared_accept_finish ()");

  ACE_HANDLE new_handle = new_stream.get_handle ();

  // Check to see if we were originally in blocking mode, and if so,
  // set the <new_stream>'s handle and <this> handle to be in blocking
  // mode.
  if (in_blocking_mode)
    {
      // Save/restore errno.
      ACE_Errno_Guard error (errno);

      // Only disable ACE_NONBLOCK if we weren't in non-blocking mode
      // originally.
      ACE::clr_flags (this->get_handle (),
                                 ACE_NONBLOCK);
      ACE::clr_flags (new_handle,
                                 ACE_NONBLOCK);
    }

#if defined (ACE_HAS_WINSOCK2) && (ACE_HAS_WINSOCK2 != 0)
  if (reset_new_handle)
    // Reset the event association inherited by the new handle.
    ::WSAEventSelect ((SOCKET) new_handle, 0, 0);
#else
  ACE_UNUSED_ARG (reset_new_handle);
#endif /* ACE_WIN32 */
  if (new_handle == ACE_INVALID_HANDLE)
    return -1;

  return 0;
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_HAS_POSITION_INDEPENDENT_POINTERS == 1 */
