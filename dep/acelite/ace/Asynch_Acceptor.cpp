/* -*- C++ -*- */
// $Id: Asynch_Acceptor.cpp 95630 2012-03-22 13:04:47Z johnnyw $

#ifndef ACE_ASYNCH_ACCEPTOR_C
#define ACE_ASYNCH_ACCEPTOR_C

#include "ace/Asynch_Acceptor.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if defined (ACE_HAS_WIN32_OVERLAPPED_IO) || defined (ACE_HAS_AIO_CALLS)
// This only works on platforms that support async i/o.

#include "ace/OS_Errno.h"
#include "ace/OS_Memory.h"
#include "ace/OS_NS_sys_socket.h"
#include "ace/Log_Msg.h"
#include "ace/Message_Block.h"
#include "ace/INET_Addr.h"
#include "ace/SOCK_Stream.h"
#include "ace/Sock_Connect.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

template <class HANDLER>
ACE_Asynch_Acceptor<HANDLER>::ACE_Asynch_Acceptor (void)
  : listen_handle_ (ACE_INVALID_HANDLE),
    pass_addresses_ (false),
    validate_new_connection_ (false),
    reissue_accept_ (1),
    bytes_to_read_ (0),
    addr_family_ (0)
{
}

template <class HANDLER>
ACE_Asynch_Acceptor<HANDLER>::~ACE_Asynch_Acceptor (void)
{
  // Close down the listen socket
  if (this->listen_handle_ != ACE_INVALID_HANDLE)
    {
      ACE_OS::closesocket (this->listen_handle_);
      this->listen_handle_ = ACE_INVALID_HANDLE;
    }
}

template <class HANDLER> int
ACE_Asynch_Acceptor<HANDLER>::open (const ACE_INET_Addr &address,
                                    size_t bytes_to_read,
                                    bool pass_addresses,
                                    int backlog,
                                    int reuse_addr,
                                    ACE_Proactor *proactor,
                                    bool validate_new_connection,
                                    int reissue_accept,
                                    int number_of_initial_accepts)
{
  ACE_TRACE ("ACE_Asynch_Acceptor<>::open");

  this->proactor (proactor);
  this->pass_addresses_ = pass_addresses;
  this->bytes_to_read_ = bytes_to_read;
  this->validate_new_connection_ = validate_new_connection;
  this->reissue_accept_ = reissue_accept;
  this->addr_family_ = address.get_type ();

  // Create the listener socket
  this->listen_handle_ = ACE_OS::socket (address.get_type (), SOCK_STREAM, 0);
  if (this->listen_handle_ == ACE_INVALID_HANDLE)
    ACE_ERROR_RETURN ((LM_ERROR,
                       ACE_TEXT ("%p\n"),
                       ACE_TEXT ("ACE_OS::socket")),
                      -1);
  // Initialize the ACE_Asynch_Accept
  if (this->asynch_accept_.open (*this,
                                 this->listen_handle_,
                                 0,
                                 this->proactor ()) == -1)
    {
      ACE_Errno_Guard g (errno);
      ACE_ERROR ((LM_ERROR,
                  ACE_TEXT ("%p\n"),
                  ACE_TEXT ("ACE_Asynch_Accept::open")));
      ACE_OS::closesocket (this->listen_handle_);
      this->listen_handle_ = ACE_INVALID_HANDLE;
      return -1;
    }

  if (reuse_addr)
    {
      // Reuse the address
      int one = 1;
      if (ACE_OS::setsockopt (this->listen_handle_,
                              SOL_SOCKET,
                              SO_REUSEADDR,
                              (const char*) &one,
                              sizeof one) == -1)
        {
          ACE_Errno_Guard g (errno);
          ACE_ERROR ((LM_ERROR,
                      ACE_TEXT ("%p\n"),
                      ACE_TEXT ("ACE_OS::setsockopt")));
          ACE_OS::closesocket (this->listen_handle_);
          this->listen_handle_ = ACE_INVALID_HANDLE;
          return -1;
        }
    }

  // If port is not specified, bind to any port.
  static ACE_INET_Addr sa (ACE_sap_any_cast (const ACE_INET_Addr &));

  if (address == sa &&
      ACE::bind_port (this->listen_handle_,
                      INADDR_ANY,
                      address.get_type()) == -1)
    {
      ACE_Errno_Guard g (errno);
      ACE_ERROR ((LM_ERROR,
                  ACE_TEXT ("%p\n"),
                  ACE_TEXT ("ACE::bind_port")));
      ACE_OS::closesocket (this->listen_handle_);
      this->listen_handle_ = ACE_INVALID_HANDLE;
      return -1;
    }

  // Bind to the specified port.
  if (ACE_OS::bind (this->listen_handle_,
                    reinterpret_cast<sockaddr *> (address.get_addr ()),
                    address.get_size ()) == -1)
    {
      ACE_Errno_Guard g (errno);
      ACE_ERROR ((LM_ERROR,
                  ACE_TEXT ("%p\n"),
                  ACE_TEXT ("ACE_OS::bind")));
      ACE_OS::closesocket (this->listen_handle_);
      this->listen_handle_ = ACE_INVALID_HANDLE;
      return -1;
    }

  // Start listening.
  if (ACE_OS::listen (this->listen_handle_, backlog) == -1)
    {
      ACE_Errno_Guard g (errno);
      ACE_ERROR ((LM_ERROR,
                  ACE_TEXT ("%p\n"),
                  ACE_TEXT ("ACE_OS::listen")));
      ACE_OS::closesocket (this->listen_handle_);
      this->listen_handle_ = ACE_INVALID_HANDLE;
      return -1;
    }

  // For the number of <intial_accepts>.
  if (number_of_initial_accepts == -1)
    number_of_initial_accepts = backlog;

  for (int i = 0; i < number_of_initial_accepts; i++)
    {
      // Initiate accepts.
      if (this->accept (bytes_to_read) == -1)
        {
          ACE_Errno_Guard g (errno);
          ACE_ERROR ((LM_ERROR,
                      ACE_TEXT ("%p\n"),
                      ACE_TEXT ("ACE_Asynch_Acceptor::accept")));
          ACE_OS::closesocket (this->listen_handle_);
          this->listen_handle_ = ACE_INVALID_HANDLE;
          return -1;
        }
    }

  return 0;
}

template <class HANDLER> int
ACE_Asynch_Acceptor<HANDLER>::set_handle (ACE_HANDLE listen_handle)
{
  ACE_TRACE ("ACE_Asynch_Acceptor<>::set_handle");

  // Take ownership of the <listen_handle>
  this->listen_handle_ = listen_handle;

  // Reinitialize the ACE_Asynch_Accept
  if (this->asynch_accept_.open (*this,
                                 this->listen_handle_,
                                 0,
                                 this->proactor ()) == -1)
    ACE_ERROR_RETURN ((LM_ERROR,
                       ACE_TEXT ("%p\n"),
                       ACE_TEXT ("ACE_Asynch_Accept::open")),
                      -1);
  return 0;
}

template <class HANDLER> ACE_HANDLE
ACE_Asynch_Acceptor<HANDLER>::get_handle (void) const
{
  return this->listen_handle_;
}

template <class HANDLER> int
ACE_Asynch_Acceptor<HANDLER>::accept (size_t bytes_to_read, const void *act)
{
  ACE_TRACE ("ACE_Asynch_Acceptor<>::accept");

  ACE_Message_Block *message_block = 0;
  // The space_needed calculation is drive by needs of Windows. POSIX doesn't
  // need to extra 16 bytes, but it doesn't hurt.
  size_t space_needed = sizeof (sockaddr_in) + 16;
#if defined (ACE_HAS_IPV6)
  if (PF_INET6 == this->addr_family_)
    space_needed = sizeof (sockaddr_in6) + 16;
#endif /* ACE_HAS_IPV6 */
  space_needed = (2 * space_needed) + bytes_to_read;

  // Create a new message block big enough for the addresses and data
  ACE_NEW_RETURN (message_block,
                  ACE_Message_Block (space_needed),
                  -1);

  // Initiate asynchronous accepts
  if (this->asynch_accept_.accept (*message_block,
                                   bytes_to_read,
                                   ACE_INVALID_HANDLE,
                                   act,
                                   0,
                                   ACE_SIGRTMIN,
                                   this->addr_family_) == -1)
    {
      // Cleanup on error
      message_block->release ();
      return -1;
    }
  return 0;
}

template <class HANDLER> void
ACE_Asynch_Acceptor<HANDLER>::handle_accept (const ACE_Asynch_Accept::Result &result)
{
  ACE_TRACE ("ACE_Asynch_Acceptor<>::handle_accept");

  // Variable for error tracking
  int error = 0;

  // If the asynchronous accept fails.
  if (!result.success () || result.accept_handle () == ACE_INVALID_HANDLE)
    {
      error = 1;
    }

#if defined (ACE_WIN32)
  // In order to use accept handle with other Window Sockets 1.1
  // functions, we call the setsockopt function with the
  // SO_UPDATE_ACCEPT_CONTEXT option. This option initializes the
  // socket so that other Windows Sockets routines to access the
  // socket correctly.
  if (!error &&
      ACE_OS::setsockopt (result.accept_handle (),
                          SOL_SOCKET,
                          SO_UPDATE_ACCEPT_CONTEXT,
                          (char *) &this->listen_handle_,
                          sizeof (this->listen_handle_)) == -1)
    {
      error = 1;
    }
#endif /* ACE_WIN32 */

  // Parse address.
  ACE_INET_Addr local_address;
  ACE_INET_Addr remote_address;
  if (!error &&
      (this->validate_new_connection_ || this->pass_addresses_))
    // Parse the addresses.
    this->parse_address (result,
                         remote_address,
                         local_address);

  // Validate remote address
  if (!error &&
      this->validate_new_connection_ &&
      (this->validate_connection (result, remote_address, local_address) == -1))
    {
      error = 1;
    }

  HANDLER *new_handler = 0;
  if (!error)
    {
      // The Template method
      new_handler = this->make_handler ();
      if (new_handler == 0)
        {
          error = 1;
        }
    }

  // If no errors
  if (!error)
    {
      // Update the Proactor unless make_handler() or constructed handler
      // set up its own.
      if (new_handler->proactor () == 0)
        new_handler->proactor (this->proactor ());

      // Pass the addresses
      if (this->pass_addresses_)
        new_handler->addresses (remote_address,
                                local_address);

      // Pass the ACT
      if (result.act () != 0)
        new_handler->act (result.act ());

      // Set up the handler's new handle value
      new_handler->handle (result.accept_handle ());

      // Initiate the handler
      new_handler->open (result.accept_handle (),
                         result.message_block ());
    }

  // On failure, no choice but to close the socket
  if (error &&
      result.accept_handle() != ACE_INVALID_HANDLE )
    ACE_OS::closesocket (result.accept_handle ());

  // Delete the dynamically allocated message_block
  result.message_block ().release ();

  // Start off another asynchronous accept to keep the backlog going,
  // unless we closed the listen socket already (from the destructor),
  // or this callback is the result of a canceled/aborted accept.
  if (this->should_reissue_accept () &&
      this->listen_handle_ != ACE_INVALID_HANDLE
#if defined (ACE_WIN32)
      && result.error () != ERROR_OPERATION_ABORTED
#else
      && result.error () != ECANCELED
#endif
      )
    this->accept (this->bytes_to_read_, result.act ());
}

template <class HANDLER> int
ACE_Asynch_Acceptor<HANDLER>::validate_connection
  (const ACE_Asynch_Accept::Result& /* result */,
   const ACE_INET_Addr& /* remote */,
   const ACE_INET_Addr& /* local */)
{
  // Default implementation always validates the remote address.
  return 0;
}

template <class HANDLER> int
ACE_Asynch_Acceptor<HANDLER>::cancel (void)
{
  ACE_TRACE ("ACE_Asynch_Acceptor<>::cancel");

  // All I/O operations that are canceled will complete with the error
  // ERROR_OPERATION_ABORTED. All completion notifications for the I/O
  // operations will occur normally.
#if defined (ACE_HAS_WIN32_OVERLAPPED_IO)
  return (int) ::CancelIo (this->listen_handle_);
#else
  // Supported now
  return this->asynch_accept_.cancel();
#endif /* defined (ACE_HAS_WIN32_OVERLAPPED_IO) */
}

template <class HANDLER> void
ACE_Asynch_Acceptor<HANDLER>::parse_address (const
                                             ACE_Asynch_Accept::Result &result,
                                             ACE_INET_Addr &remote_address,
                                             ACE_INET_Addr &local_address)
{
  ACE_TRACE ("ACE_Asynch_Acceptor<>::parse_address");

#if defined (ACE_HAS_AIO_CALLS)

  // Use an ACE_SOCK to get the addresses - it knows how to deal with
  // ACE_INET_Addr objects and get IPv4/v6 addresses.
  ACE_SOCK_Stream str (result.accept_handle ());
  str.get_local_addr (local_address);
  str.get_remote_addr (remote_address);

#elif defined (ACE_HAS_WINSOCK2) && (ACE_HAS_WINSOCK2 != 0)

  ACE_Message_Block &message_block = result.message_block ();

  sockaddr *local_addr = 0;
  sockaddr *remote_addr = 0;
  int local_size = 0;
  int remote_size = 0;
  // This matches setup in accept().
  size_t addr_size = sizeof (sockaddr_in) + 16;
#if defined (ACE_HAS_IPV6)
  if (this->addr_family_ == PF_INET6)
    addr_size = sizeof (sockaddr_in6) + 16;
#endif /* ACE_HAS_IPV6 */

  ::GetAcceptExSockaddrs (message_block.rd_ptr (),
                          static_cast<DWORD> (this->bytes_to_read_),
                          static_cast<DWORD> (addr_size),
                          static_cast<DWORD> (addr_size),
                          &local_addr,
                          &local_size,
                          &remote_addr,
                          &remote_size);

  local_address.set (reinterpret_cast<sockaddr_in *> (local_addr),
                     local_size);
  remote_address.set (reinterpret_cast<sockaddr_in *> (remote_addr),
                      remote_size);
#else
  // just in case
  errno = ENOTSUP;
#endif /* defined (ACE_HAS_WINSOCK2) && (ACE_HAS_WINSOCK2 != 0) */
  return;
}

template <class HANDLER> ACE_HANDLE
ACE_Asynch_Acceptor<HANDLER>::handle (void) const
{
  return this->listen_handle_;
}

template <class HANDLER> void
ACE_Asynch_Acceptor<HANDLER>::handle (ACE_HANDLE h)
{
  ACE_Handler::handle (h);
}

template <class HANDLER> ACE_Asynch_Accept &
ACE_Asynch_Acceptor<HANDLER>::asynch_accept (void)
{
  return this->asynch_accept_;
}

template <class HANDLER> HANDLER *
ACE_Asynch_Acceptor<HANDLER>::make_handler (void)
{
  // Default behavior
  HANDLER *handler = 0;
  ACE_NEW_RETURN (handler,
                  HANDLER,
                  0);
  return handler;
}

template <class HANDLER> bool
ACE_Asynch_Acceptor<HANDLER>::pass_addresses (void) const
{
  return this->pass_addresses_;
}

template <class HANDLER> void
ACE_Asynch_Acceptor<HANDLER>::pass_addresses (bool new_value)
{
  this->pass_addresses_ = new_value;
}

template <class HANDLER> bool
ACE_Asynch_Acceptor<HANDLER>::validate_new_connection (void) const
{
  return this->validate_new_connection_;
}

template <class HANDLER> void
ACE_Asynch_Acceptor<HANDLER>::validate_new_connection (bool new_value)
{
  this->validate_new_connection_ = new_value;
}

template <class HANDLER> int
ACE_Asynch_Acceptor<HANDLER>::reissue_accept (void) const
{
  return this->reissue_accept_;
}

template <class HANDLER> void
ACE_Asynch_Acceptor<HANDLER>::reissue_accept (int new_value)
{
  this->reissue_accept_ = new_value;
}

template <class HANDLER> size_t
ACE_Asynch_Acceptor<HANDLER>::bytes_to_read (void) const
{
  return this->bytes_to_read_;
}

template <class HANDLER> void
ACE_Asynch_Acceptor<HANDLER>::bytes_to_read (size_t new_value)
{
  this->bytes_to_read_ = new_value;
}

template <class HANDLER> int
ACE_Asynch_Acceptor<HANDLER>::should_reissue_accept (void)
{
  return this->reissue_accept_;
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_WIN32 || ACE_HAS_AIO_CALLS */
#endif /* ACE_ASYNCH_ACCEPTOR_C */
