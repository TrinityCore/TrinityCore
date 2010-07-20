// -*- C++ -*-
//
// $Id: SSL_SOCK.inl 80826 2008-03-04 14:51:23Z wotte $

#include "ace/OS_NS_sys_socket.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_INLINE void
ACE_SSL_SOCK::set_handle (ACE_HANDLE fd)
{
  this->ACE_SOCK::set_handle (fd);
}

ACE_INLINE ACE_HANDLE
ACE_SSL_SOCK::get_handle (void) const
{
  // return this->ssl_ ? (ACE_HANDLE) ::SSL_get_fd (this->ssl_) : ACE_INVALID_HANDLE;
  return this->ACE_SOCK::get_handle ();
}


ACE_INLINE int
ACE_SSL_SOCK::control (int cmd, void *arg) const
{
  return ACE_OS::ioctl (this->get_handle (), cmd, arg);
}

ACE_INLINE int
ACE_SSL_SOCK::set_option (int level,
                     int option,
                     void *optval,
                     int optlen) const
{
//   switch (option)
//     {
//     case SO_SNDBUF:
//       return ::BIO_set_write_buffer_size (this->io_bio_, *((int *) optval));
//     case SO_RCVCBUF:
//       return ::BIO_set_read_buffer_size (this->io_bio_, *((int *) optval));
//     default:
      return ACE_OS::setsockopt (this->get_handle (),
                                 level,
                                 option, (char *) optval,
                                 optlen);
//    }
}

// Provides access to the ACE_OS::getsockopt system call.

ACE_INLINE int
ACE_SSL_SOCK::get_option (int level,
                     int option,
                     void *optval,
                     int *optlen) const
{
//  switch (option)
//    {
//     case SO_SNDBUF:
//       return ::BIO_get_write_buffer_size (this->io_bio_, *((int *) optval));
//     case SO_RCVCBUF:
//       return ::BIO_get_read_buffer_size (this->io_bio_, *((int *) optval));
//    default:
      return ACE_OS::getsockopt (this->get_handle (),
                                 level,
                                 option, (char *) optval,
                                 optlen);
//    }
}

ACE_END_VERSIONED_NAMESPACE_DECL
