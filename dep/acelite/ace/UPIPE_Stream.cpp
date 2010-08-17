// $Id: UPIPE_Stream.cpp 82559 2008-08-07 20:23:07Z parsons $

#include "ace/UPIPE_Stream.h"

ACE_RCSID(ace, UPIPE_Stream, "$Id: UPIPE_Stream.cpp 82559 2008-08-07 20:23:07Z parsons $")

#if defined (ACE_HAS_THREADS)

#include "ace/OS_NS_string.h"

#if !defined (__ACE_INLINE__)
#include "ace/UPIPE_Stream.inl"
#endif /* __ACE_INLINE__ */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_ALLOC_HOOK_DEFINE(ACE_UPIPE_Stream)

ACE_UPIPE_Stream::ACE_UPIPE_Stream (void)
  : mb_last_ (0),
    reference_count_ (0)
{
  ACE_TRACE ("ACE_UPIPE_Stream::ACE_UPIPE_STREAM");
}

ACE_UPIPE_Stream::~ACE_UPIPE_Stream (void)
{
  if (this->mb_last_ != 0)
    {
      this->mb_last_->release ();
      this->mb_last_ = 0;
    }
}

int
ACE_UPIPE_Stream::control (int cmd,
                           void * val) const
{
  ACE_TRACE ("ACE_UPIPE_Stream::control");

  return ((ACE_UPIPE_Stream *) this)->stream_.control
    ((ACE_IO_Cntl_Msg::ACE_IO_Cntl_Cmds) cmd, val);
}

void
ACE_UPIPE_Stream::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_UPIPE_Stream::dump");
#endif /* ACE_HAS_DUMP */
}

int
ACE_UPIPE_Stream::close (void)
{
  ACE_TRACE ("ACE_UPIPE_Stream::close");
  ACE_MT (ACE_GUARD_RETURN (ACE_Thread_Mutex, ace_mon, this->lock_, -1));

  this->reference_count_--;

  if (this->reference_count_ == 0)
    {
      // Since the UPIPE should have been closed earlier we won't bother
      // checking to see if closing it now fails.

      if (this->ACE_SPIPE::get_handle () != ACE_INVALID_HANDLE)
        this->ACE_SPIPE::close ();

      // Close down the ACE_stream.
      return this->stream_.close ();
    }
  return 0;
}

int
ACE_UPIPE_Stream::get_remote_addr (ACE_UPIPE_Addr &remote_sap) const
{
  ACE_TRACE ("ACE_UPIPE_Stream::get_remote_addr");
  remote_sap = this->remote_addr_;
  return 0;
}

int
ACE_UPIPE_Stream::send (ACE_Message_Block *mb_p,
                        ACE_Time_Value *timeout)
{
  ACE_TRACE ("ACE_UPIPE_Stream::send_msg");
  return this->stream_.put (mb_p, timeout) == -1 ? -1 : 0;
}

int ACE_UPIPE_Stream::recv (ACE_Message_Block *& mb_p,
                            ACE_Time_Value *timeout)
{
  return this->stream_.get (mb_p, timeout) == -1 ? -1 : 0;
}

// Send a buffer.

ssize_t
ACE_UPIPE_Stream::send (const char *buffer,
                        size_t n,
                        ACE_Time_Value *timeout)
{
  ACE_TRACE ("ACE_UPIPE_Stream::send");

  ACE_Message_Block *mb_p;
  ACE_NEW_RETURN (mb_p,
                  ACE_Message_Block (n),
                  -1);
  mb_p->copy (buffer, n);
  return
    this->stream_.put (mb_p, timeout) == -1
    ? -1
    : static_cast<ssize_t> (n);
}

// Receive a buffer.

ssize_t
ACE_UPIPE_Stream::recv (char *buffer,
                        size_t n,
                        ACE_Time_Value *timeout)
{
  ACE_TRACE ("ACE_UPIPE_Stream::recv");
  // Index in buffer.
  size_t bytes_read = 0;

  while (bytes_read < n)
    if (this->mb_last_ != 0)
      {
        // We have remaining data in our last read Message_Buffer.
        size_t this_len = this->mb_last_->length ();
        if (this_len < n)
          {
            // The remaining data is not enough.

            ACE_OS::memcpy ((void *) &buffer[bytes_read],
                            this->mb_last_->rd_ptr (),
                            this_len);
            bytes_read += this_len;
            this->mb_last_ = this->mb_last_->release ();   // mb_last_ now 0
            return static_cast<ssize_t> (bytes_read);
          }
        else
          {
            // The remaining data is at least enough.  If there's
            // more, we'll get it the next time through.
            ACE_OS::memcpy (&buffer[bytes_read],
                            this->mb_last_->rd_ptr (),
                            n);
            bytes_read += n;

            // Advance rd_ptr.
            this->mb_last_->rd_ptr (n);

            if (this->mb_last_->length () == 0)
              // Now the Message_Buffer is empty.
              this->mb_last_ = this->mb_last_->release ();
          }
      }
    else
      {
        // We have to get a new Message_Buffer from our stream.
        int result = this->stream_.get (this->mb_last_, timeout);

        if (result == -1)
          {
            if (errno == EWOULDBLOCK && bytes_read > 0)
              // Return the number of bytes read before we timed out.
              return static_cast<ssize_t> (bytes_read);
            else
              return -1;
          }
      }

  return static_cast<ssize_t> (bytes_read);
}

ssize_t
ACE_UPIPE_Stream::send_n (const char *buf,
                          size_t n,
                          ACE_Time_Value *timeout)
{
  ACE_TRACE ("ACE_UPIPE_Stream::send_n");

  size_t bytes_written;
  ssize_t len = 0;

  for (bytes_written = 0; bytes_written < n; bytes_written += len)
    {
      len = this->send (buf + bytes_written,
                        n - bytes_written,
                        timeout);

      if (len == -1)
        {
          return -1;
        }
    }

  return static_cast<ssize_t> (bytes_written);
}

ssize_t
ACE_UPIPE_Stream::recv_n (char *buf,
                          size_t n,
                          ACE_Time_Value *timeout)
{
  ACE_TRACE ("ACE_UPIPE_Stream::recv_n");
  size_t bytes_read;
  ssize_t len = 0;

  for (bytes_read = 0; bytes_read < n; bytes_read += len)
    {
      len = this->recv (buf + bytes_read,
                        n - bytes_read,
                        timeout);
                        
      if (len == -1)
        {
          return -1;
        }
      else if (len == 0)
        {
          break;
        }
    }

  return static_cast< ssize_t> (bytes_read);
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_HAS_THREADS */
