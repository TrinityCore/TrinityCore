// $Id: SSL_SOCK_Stream.cpp 91368 2010-08-16 13:03:34Z mhengstmengel $

#include "ace/Handle_Set.h"
#include "ace/Log_Msg.h"
#include "ace/Countdown_Time.h"
#include "ace/OS_NS_string.h"
#include "ace/OS_NS_sys_select.h"
#include "ace/OS_Memory.h"

#include <openssl/err.h>

#include "SSL_SOCK_Stream.h"

#if !defined (__ACE_INLINE__)
#include "SSL_SOCK_Stream.inl"
#endif /* __ACE_INLINE__ */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_ALLOC_HOOK_DEFINE(ACE_SSL_SOCK_Stream)

ACE_SSL_SOCK_Stream::ACE_SSL_SOCK_Stream (ACE_SSL_Context *context)
  : ssl_ (0),
    stream_ ()
{
  ACE_TRACE ("ACE_SSL_SOCK_Stream::ACE_SSL_SOCK_Stream");

  ACE_SSL_Context * ctx =
    (context == 0 ? ACE_SSL_Context::instance () : context);

  this->ssl_ = ::SSL_new (ctx->context ());

  if (this->ssl_ == 0)
    {
      ACE_ERROR ((LM_ERROR,
                  "(%P|%t) ACE_SSL_SOCK_Stream "
                  "- cannot allocate new SSL structure %p\n",
                  ACE_TEXT ("")));
    }
}

ACE_SSL_SOCK_Stream::~ACE_SSL_SOCK_Stream (void)
{
  ACE_TRACE ("ACE_SSL_SOCK_Stream::~ACE_SSL_SOCK_Stream");

  ::SSL_free (this->ssl_);

  // @@ Question: should we reference count the Context object or
  // leave that to the application developer? We do not reference
  // count reactors (for example) and following some simple rules
  // seems to work fine!
}

ssize_t
ACE_SSL_SOCK_Stream::sendv (const iovec iov[],
                            size_t n,
                            const ACE_Time_Value *max_wait_time) const
{
  ACE_TRACE ("ACE_SSL_SOCK_Stream::sendv");

  // There is subtle problem in this method that occurs when using
  // non-blocking IO.  The semantics of a non-blocking scatter write
  // (sendv()) are not possible to retain with the emulation in this
  // method.

  ssize_t bytes_sent = 0;

  ACE_Time_Value t;
  ACE_Time_Value *timeout = const_cast<ACE_Time_Value *> (max_wait_time);

  if (max_wait_time != 0)
    {
      // Make a copy since ACE_Countdown_Time modifies the
      // ACE_Time_Value.
      t = *max_wait_time;
      timeout = &t;
    }

  // Take into account the time between each send.
  ACE_Countdown_Time countdown (timeout);

  for (size_t i = 0; i < n; ++i)
    {
      ssize_t const result = this->send (iov[i].iov_base,
                                         iov[i].iov_len,
                                         timeout);

      if (result == -1)
        {
          // There is a subtle difference in behaviour depending on
          // whether or not any data was sent.  If no data was sent,
          // then always return -1.  Otherwise return bytes_sent.
          // This gives the caller an opportunity to keep track of
          if (bytes_sent > 0)
            break;
          else
            return -1;
        }
      else
        {
          bytes_sent += result;

          // Do not continue on to the next loop iteration if the
          // amount of data sent was less than the amount data given.
          // This avoids a subtle problem where "holes" in the data
          // stream would occur if partial sends of a given buffer in
          // the iovec array occured.
          if (static_cast<size_t> (result) < static_cast<size_t> (iov[i].iov_len))
            break;
        }

      (void) countdown.update ();
    }

  return bytes_sent;
}

ssize_t
ACE_SSL_SOCK_Stream::recvv (iovec *io_vec,
                            const ACE_Time_Value *timeout) const
{
  ACE_TRACE ("ACE_SSL_SOCK_Stream::recvv");

  // From ACE_SOCK_IO::recvv().
#if defined (FIONREAD)
  ACE_Handle_Set handle_set;
  handle_set.reset ();
  handle_set.set_bit (this->get_handle ());

  io_vec->iov_base = 0;

  // Check the status of the current socket.
  switch (
    ACE_OS::select (int (this->get_handle ()) + 1,
                    handle_set,
                    0,
                    0,
                    timeout))
    {
    case -1:
      return -1;
      /* NOTREACHED */
    case 0:
      errno = ETIME;
      return -1;
      /* NOTREACHED */
    default:
      // Goes fine, fallthrough to get data
      break;
    }

  int inlen;

  if (ACE_OS::ioctl (this->get_handle (),
                     FIONREAD,
                     &inlen) == -1)
    return -1;
  else if (inlen > 0)
    {
      ACE_NEW_RETURN (io_vec->iov_base,
                      char[inlen],
                      -1);
      io_vec->iov_len = this->recv (io_vec->iov_base,
                                    inlen);
      return io_vec->iov_len;
    }
  else
    return 0;
#else
  ACE_UNUSED_ARG (io_vec);
  ACE_UNUSED_ARG (timeout);
  ACE_NOTSUP_RETURN (-1);
#endif /* FIONREAD */
}

ssize_t
ACE_SSL_SOCK_Stream::send (const void *buf,
                           size_t len,
                           int flags,
                           const ACE_Time_Value *timeout) const
{
  ACE_TRACE ("ACE_SSL_SOCK_Stream::send");

  // If SSL has data in the buffer, i.e. SSL_pending() returns a
  // non-zero value, then don't block on select().
  if (timeout == 0 || ::SSL_pending (this->ssl_))
    return this->send (buf, len, flags);

  int val = 0;
  if (ACE::enter_send_timedwait (this->get_handle (),
                                 timeout,
                                 val) == -1)
    return -1;

  ssize_t const bytes_transferred = this->send (buf, len, flags);

  ACE::restore_non_blocking_mode (this->get_handle (), val);

  return bytes_transferred;
}

ssize_t
ACE_SSL_SOCK_Stream::recv (void *buf,
                           size_t n,
                           int flags,
                           const ACE_Time_Value *timeout) const
{
  ACE_TRACE ("ACE_SSL_SOCK_Stream::recv");

  return this->recv_i (buf, n, flags, timeout);
}


ssize_t
ACE_SSL_SOCK_Stream::send (size_t n, ...) const
{
  ACE_TRACE ("ACE_SSL_SOCK_Stream::send");

  size_t const total_tuples = n / 2;

  va_list argp;
  va_start (argp, n);

  ssize_t bytes_sent = 0;

  // NOTE: This method used to fill an IO vector (e.g. iovec) and then
  //       send it using a scatter write (sendv()).  However, it is
  //       not possible to emulate a non-blocking scatter write over
  //       SSL.  As such, there is no point in attempting to use
  //       scatter writes over SSL.
  for (size_t i = 0; i < total_tuples; ++i)
    {
      ssize_t const data_len = va_arg (argp, ssize_t);
      ssize_t const result = this->send (va_arg (argp, char *), data_len);

      if (result == -1)
        {
          // There is a subtle difference in behaviour depending on
          // whether or not any data was sent.  If no data was sent,
          // then always return -1.  Otherwise return bytes_sent.
          // This gives the caller an opportunity to keep track of
          // which data was actually sent.
          if (bytes_sent > 0)
            break;
          else
            {
              va_end (argp);
              return -1;
            }
        }
      else
        {
          bytes_sent += result;

          // Do not continue on to the next loop iteration if the
          // amount of data sent was less than the amount of data
          // given.  This avoids a subtle problem where "holes" in the
          // data stream would occur if partial sends of a given
          // buffer in the varargs occured.
          if (result < data_len)
            break;

        }
    }

  va_end (argp);

  return bytes_sent;
}

ssize_t
ACE_SSL_SOCK_Stream::recv (size_t n, ...) const
{
  ACE_TRACE ("ACE_SSL_SOCK_Stream::recv");

  size_t const total_tuples = n / 2;

  va_list argp;
  va_start (argp, n);

  ssize_t bytes_recv = 0;

  for (size_t i = 0; i < total_tuples; ++i)
    {
      ssize_t const data_len = va_arg (argp, ssize_t);
      ssize_t const result = this->recv (va_arg (argp, char *), data_len);

      if (result == -1)
        {
          // There is a subtle difference in behaviour depending on
          // whether or not any data was received.  If no data was
          // received, then always return -1.  Otherwise return
          // bytes_received.  This gives the caller an opportunity to
          // keep track of which data was actually received.
          if (bytes_recv > 0)
            {
              break;
            }
          else
            {
              va_end (argp);
              return -1;
            }
        }
      else
        {
          bytes_recv += result;

          // Do not continue on to the next loop iteration if the
          // amount of data received was less than the amount of data
          // desired.  This avoids a subtle problem where "holes" in
          // the data stream would occur if partial receives of a
          // given buffer in the varargs occured.
          if (result < data_len)
            {
              break;
            }
        }
    }

  va_end (argp);

  return bytes_recv;
}

ssize_t
ACE_SSL_SOCK_Stream::send_n (const void *buf,
                             size_t len,
                             int flags,
                             const ACE_Time_Value *timeout,
                             size_t *bt) const
{
  ACE_TRACE ("ACE_SSL_SOCK_Stream::send_n");

  // No support for send flags in SSL.
  if (flags != 0)
    {
      ACE_NOTSUP_RETURN (-1);
    }

  /* This code mimics ACE::send_n */
  // Total number of bytes written.
  size_t temp = 0;
  size_t &bytes_transferred = ((bt == 0) ? temp : *bt);

  // Actual number of bytes written in each <send> attempt
  ssize_t n = 0;

  for (bytes_transferred = 0;
       bytes_transferred < len;
       bytes_transferred += n)
    {
      n = this->send ((const char*) buf + bytes_transferred,
                      len - bytes_transferred,
                      flags,
                      timeout);

      if (n < 0)
        {
          if (errno == EWOULDBLOCK)
            {
              // If blocked, try again.
              n = 0;
              continue;
            }
          else
            {
              return -1;
            }
        }
      else if (n == 0)
        {
          break;
        }
    }

  return ACE_Utils::truncate_cast<ssize_t> (bytes_transferred);
}

ssize_t
ACE_SSL_SOCK_Stream::recv_n (void *buf,
                             size_t len,
                             int flags,
                             const ACE_Time_Value *timeout,
                             size_t *bt) const
{
  ACE_TRACE ("ACE_SSL_SOCK_Stream::recv_n");

  if (flags != 0)
    {
      if ((flags | MSG_PEEK) != MSG_PEEK)
        {
          ACE_NOTSUP_RETURN (-1);
        }
    }

  size_t temp = 0;
  size_t &bytes_transferred = ((bt == 0) ? temp : *bt);

  ssize_t n = 0;

  for (bytes_transferred = 0;
       bytes_transferred < len;
       bytes_transferred += n)
    {
      n = this->recv ((char*) buf + bytes_transferred,
                      len - bytes_transferred,
                      flags,
                      timeout);

      if (n < 0)
        {
          if (errno == EWOULDBLOCK)
            {
              // If blocked, try again.
              n = 0;
              continue;
            }
          else
            {
              return -1;
            }
        }
      else if (n == 0)
        {
          break;
        }
    }

  return ACE_Utils::truncate_cast<ssize_t> (bytes_transferred);
}

ssize_t
ACE_SSL_SOCK_Stream::recv_n (void *buf, int len, int flags) const
{
  ACE_TRACE ("ACE_SSL_SOCK_Stream::recv_n");

  if (flags != 0)
    {
      if ((flags | MSG_PEEK) != MSG_PEEK)
        {
          ACE_NOTSUP_RETURN (-1);
        }
    }

  ssize_t bytes_transferred = 0;
  ssize_t n = 0;

  for (bytes_transferred = 0;
       bytes_transferred < len;
       bytes_transferred += n)
    {
      n = this->recv ((char*) buf + bytes_transferred,
                      len - bytes_transferred,
                      flags);

      if (n < 0)
        {
          if (errno == EWOULDBLOCK)
            {
              // If blocked, try again.
              n = 0;
              continue;
            }
          else
            {
              return -1;
            }
        }
      else if (n == 0)
        {
          break;
        }
    }

  return ACE_Utils::truncate_cast<ssize_t> (bytes_transferred);
}

ssize_t
ACE_SSL_SOCK_Stream::send_n (const void *buf, int len, int flags) const
{
  ACE_TRACE ("ACE_SSL_SOCK_Stream::send_n");

  // Send flags are unsupported in SSL
  if (flags != 0)
    {
      ACE_NOTSUP_RETURN (-1);
    }

  /*  The following code mimics <ACE::send_n> */
  size_t bytes_transferred = 0;
  ssize_t n = 0;

  for (bytes_transferred = 0;
       bytes_transferred < (size_t) len;
       bytes_transferred += n)
    {
      n = this->send ((const char*) buf + bytes_transferred,
                      len - bytes_transferred,
                      flags);

      if (n < 0)
        {
          if (errno == EWOULDBLOCK)
            {
              // If blocked, try again.
              n = 0;
              continue;
            }
          else
            {
              return -1;
            }
        }
      else if (n == 0)
        {
          break;
        }
    }

  return ACE_Utils::truncate_cast<ssize_t> (bytes_transferred);
}

ssize_t
ACE_SSL_SOCK_Stream::sendv_n (const iovec iov[], size_t iovcnt) const
{
  ACE_TRACE ("ACE_SSL_SOCK_Stream::sendv_n");

  ssize_t bytes_sent = 0;

  for (size_t i = 0; i < iovcnt; ++i)
    {
      ssize_t result = this->send_n (iov[i].iov_base,
                                     iov[i].iov_len);


      if (result == -1)
        {
          // There is a subtle difference in behaviour depending on
          // whether or not any data was sent.  If no data was sent,
          // then always return -1.  Otherwise return bytes_sent.
          // This gives the caller an opportunity to keep track of
          // which data was actually sent.
          if (bytes_sent > 0)
            {
              break;
            }
          else
            {
              return -1;
            }
        }
      else
        {
          bytes_sent += result;
        }
    }

  return bytes_sent;
}

ssize_t
ACE_SSL_SOCK_Stream::recvv_n (iovec iov[], size_t iovcnt) const
{
  ACE_TRACE ("ACE_SSL_SOCK_Stream::recvv_n");

  ssize_t bytes_read = 0;

  for (size_t i = 0; i < iovcnt; ++i)
    {
      ssize_t const result = this->recv_n (iov[i].iov_base,
                                           iov[i].iov_len);

      if (result == -1)
        {
          // There is a subtle difference in behaviour depending on
          // whether or not any data was read.  If no data was read,
          // then always return -1.  Otherwise return bytes_read.
          // This gives the caller an opportunity to keep track of
          // which data was actually read.
          if (bytes_read > 0)
            {
              break;
            }
          else
            {
              return -1;
            }
        }
      else
        {
          bytes_read += result;
        }
    }

  return bytes_read;
}

int
ACE_SSL_SOCK_Stream::get_remote_addr (ACE_Addr &addr) const
{
  // Some applications use get_remote_addr() as a way of determining
  // whether or not a connection has been established.  In SSL's case,
  // the remote addr will be available once the TCP handshake has been
  // complete.  Despite that fact, the SSL connection may not have
  // been completed.  In such a case, a successful return from
  // get_remote_addr() would be misleading.

  if (SSL_is_init_finished (this->ssl_))
    {
      return this->ACE_SSL_SOCK::get_remote_addr (addr);
    }

  if (this->get_handle () == ACE_INVALID_HANDLE)
    {
      errno = EBADF;
    }
  else
    {
      errno = ENOTCONN;
    }

  return -1;
}

ACE_END_VERSIONED_NAMESPACE_DECL
