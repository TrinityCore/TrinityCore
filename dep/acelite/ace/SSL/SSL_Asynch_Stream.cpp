// $Id: SSL_Asynch_Stream.cpp 91813 2010-09-17 07:52:52Z johnnyw $
#include "SSL_Asynch_Stream.h"

// This only works on platforms with Asynchronous IO support.
#if OPENSSL_VERSION_NUMBER > 0x0090581fL && ((defined (ACE_WIN32) && !defined (ACE_HAS_WINCE)) || (defined (ACE_HAS_AIO_CALLS)))

#if defined (ACE_WIN32)
# include "ace/WIN32_Proactor.h"
#else
# include "ace/POSIX_Proactor.h"
#endif  /* ACE_WIN32 */

#include "ace/OS_NS_string.h"
#include "ace/Proactor.h"
#include "ace/Truncate.h"

#if !defined(__ACE_INLINE__)
#include "SSL_Asynch_Stream.inl"
#endif /* __ACE_INLINE__ */

#include <openssl/err.h>

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_SSL_Asynch_Write_Stream_Result::ACE_SSL_Asynch_Write_Stream_Result
  (ACE_Handler &       handler,
   ACE_HANDLE          handle,
   ACE_Message_Block & message_block,
   size_t              bytes_to_write,
   const void *        act,
   ACE_HANDLE          event,
   int                 priority,
   int                 signal_number
 )
  : AWS_RESULT (handler.proxy (),
                handle,
                message_block,
                bytes_to_write,
                act,
                event,
                priority,
                signal_number
                )
{
}

ACE_SSL_Asynch_Read_Stream_Result::ACE_SSL_Asynch_Read_Stream_Result
  (ACE_Handler &        handler,
   ACE_HANDLE           handle,
   ACE_Message_Block &  message_block,
   size_t               bytes_to_read,
   const void *         act,
   ACE_HANDLE           event,
   int                  priority,
   int                  signal_number
 )
  : ARS_RESULT (handler.proxy (),
                handle,
                message_block,
                bytes_to_read,
                act,
                event,
                priority,
                signal_number
                )
{
}

ACE_SSL_Asynch_Result::ACE_SSL_Asynch_Result (ACE_Handler & handler)
  : A_RESULT (handler.proxy (),
              0,          // act,
              ACE_INVALID_HANDLE,
              0,           // Offset
              0,           // OffsetHigh
              0,           // Priority
              ACE_SIGRTMIN //signal_number
              )
{
}

void
ACE_SSL_Asynch_Result::complete (size_t /* bytes_transferred */,
                                 int    /* success */,
                                 const  void * /* completion_key */,
                                 u_long /* error */)
{
  this->handler_proxy_->handler ()->handle_wakeup ();
}

// ************************************************************
//  ACE_SSL_Asynch_Stream Constructor / Destructor
// ************************************************************
ACE_SSL_Asynch_Stream::ACE_SSL_Asynch_Stream (
  ACE_SSL_Asynch_Stream::Stream_Type s_type,
  ACE_SSL_Context * context)
  : type_         (s_type),
    proactor_     (0),
    ext_handler_  (0),
    ext_read_result_ (0),
    ext_write_result_(0),
    flags_        (0),
    ssl_          (0),
    handshake_complete_(false),
    bio_          (0),
    bio_istream_  (),
    bio_inp_msg_  (),
    bio_inp_errno_(0),
    bio_inp_flag_ (0),
    bio_ostream_  (),
    bio_out_msg_  (),
    bio_out_errno_(0),
    bio_out_flag_ (0),
    mutex_ ()
{
  ACE_TRACE ("ACE_SSL_Asynch_Stream::ACE_SSL_Asynch_Stream");
  // was honestly copied from ACE_SSL_SOCK_Stream :)

  ACE_SSL_Context * ctx =
    (context == 0 ? ACE_SSL_Context::instance () : context);

  this->ssl_ = ::SSL_new (ctx->context ());

  if (this->ssl_ == 0)
    ACE_ERROR
      ((LM_ERROR,
        ACE_TEXT ("(%P|%t) ACE_SSL_Asynch_Stream %p\n"),
        ACE_TEXT ("- cannot allocate new SSL structure")
     ));

}

ACE_SSL_Asynch_Stream::~ACE_SSL_Asynch_Stream (void)
{
  ACE_TRACE ("ACE_SSL_Asynch_Stream::~ACE_SSL_Asynch_Stream");


  // It is safe to delete stream if all notifications are received,
  // i.e., state is SF_DELETE_ENABLE or if proactor event loop is
  // done.
  if (this->flags_ & SF_STREAM_OPEN)             // open
    if ((this->flags_ & SF_DELETE_ENABLE) == 0)  // but ..
      ACE_DEBUG ((LM_DEBUG,
                  ACE_TEXT("ACE_SSL_Asynch_Stream::DTOR-")
                  ACE_TEXT("possible access violation ")
                  ACE_TEXT("if proactor still handles events\n")));

  ::SSL_free (this->ssl_);

  // Was honestly copied from ACE_SSL_SOCK_Stream :)

  // @@ Question: should we reference count the Context object or
  // leave that to the application developer? We do not reference
  // count reactors (for example) and following some simple rules
  // seems to work fine!
}

// ************************************************************
//  close ()
//  returns :
//  0  - Stream is in the state SF_DELETE_ENABLE,
//       so  it is safe to delete stream
//  -1 - Stream has pending AIO requests,
//       close should be repeated later one more
// ************************************************************

int
ACE_SSL_Asynch_Stream::close (void)
{
  ACE_MT (ACE_GUARD_RETURN (ACE_SYNCH_MUTEX, ace_mon, this->mutex_, -1));

  if ((flags_ & SF_STREAM_OPEN) == 0) // not open
    flags_ |= SF_DELETE_ENABLE;

  if (flags_ & SF_DELETE_ENABLE)
    return 0;

  flags_ |= SF_REQ_SHUTDOWN;

  this->do_SSL_state_machine ();

  return -1;
}

// ************************************************************
//  Asynch_Operation interface
//    cancel
// ************************************************************
int
ACE_SSL_Asynch_Stream::cancel (void)
{
  ACE_MT (ACE_GUARD_RETURN (ACE_SYNCH_MUTEX, ace_mon, this->mutex_, -1));

  if ((flags_ & SF_STREAM_OPEN) == 0) // not open
    {
      return 1;   //   AIO_ALLDONE
    }

  // attempt to cancel internal, i.e. user's read/write
  int rc_r_int = bio_istream_.cancel();
  int rc_w_int = bio_ostream_.cancel();

  // attempt to cancel external, i.e. bio_ssl read/write
  int rc_r_ext = notify_read (0, ERR_CANCELED);
  int rc_w_ext = notify_write (0, ERR_CANCELED);

  if ((rc_r_int < 0 || rc_w_int < 0)
      && (rc_r_ext < 0 || rc_w_ext < 0))
    {
      return -1;  // at least one error
    }

  if (rc_r_int == 1 && rc_w_int == 1
      && rc_r_ext == 1 && rc_w_ext == 1)
    {
      return 1;  // AIO_ALLDONE
    }

  if ((rc_r_int == 2 || rc_w_int == 2)
      && (rc_r_ext == 2 || rc_w_ext == 2))
    {
      return 2;  // AIO_NOT_CANCELED , at least one not canceled
    }

  return 0;    // AIO_CANCELED, at least will be one notification
}

// ************************************************************
//  Asynch_Operation interface
//    open
// ************************************************************
int
ACE_SSL_Asynch_Stream::open (ACE_Handler & handler,
                             ACE_HANDLE handle,
                             const void * completion_key,
                             ACE_Proactor * proactor)
{
  ACE_MT (ACE_GUARD_RETURN (ACE_SYNCH_MUTEX, ace_mon, this->mutex_, -1));

  if (this->flags_ & SF_STREAM_OPEN)
    ACE_ERROR_RETURN
      ((LM_ERROR,
        ACE_TEXT ("(%P|%t) ACE_SSL_Asynch_Stream::open() %p\n"),
        ACE_TEXT ("- already opened")),
       -1);

  if (this->ssl_ == 0)
    ACE_ERROR_RETURN
      ((LM_ERROR,
        ACE_TEXT ("(%P|%t) ACE_SSL_Asynch_Stream::open() %p\n"),
        ACE_TEXT ("- SSL structure is absent")),
       -1);

  if (handle == ACE_INVALID_HANDLE)
    ACE_ERROR_RETURN
      ((LM_ERROR,
        ACE_TEXT ("(%P|%t) ACE_SSL_Asynch_Stream::open() %p\n"),
        ACE_TEXT ("- invalid handle")),
       -1);


  // Get a proactor for/from the user.
  this->proactor_    = this->get_proactor (proactor, handler);
  this->ext_handler_ = & handler;
  this->handle (handle);

  // Open internal input stream
  if (this->bio_istream_.open (*this,   // real callbacks to this
                               handle,
                               completion_key,
                               this->proactor_) != 0)
    return -1;

  // Open internal output stream
  if (this->bio_ostream_.open (*this,  // real callbacks to this
                               handle,
                               completion_key,
                               this->proactor_) != 0)
    return -1;

  this->bio_ = ACE_SSL_make_BIO (this);

  if (this->bio_ == 0)
    ACE_ERROR_RETURN
      ((LM_ERROR,
        ACE_TEXT ("(%P|%t) ACE_SSL_Asynch_Stream::open() %p\n"),
        ACE_TEXT ("- cannot allocate new BIO structure")),
       -1);

  ::SSL_set_bio (this->ssl_ , this->bio_ , this->bio_);

  switch (this->type_)
    {
    case ST_CLIENT:
      ::SSL_set_connect_state (this->ssl_);
      break;

    case ST_SERVER:
      ::SSL_set_accept_state (this->ssl_);
      break;

    default:
      ACE_ERROR_RETURN
        ((LM_ERROR,
          ACE_TEXT ("(%P|%t) ACE_SSL_Asynch_Stream::open() %p\n"),
          ACE_TEXT ("- invalid stream type")),
         -1);
    }

  this->flags_ |= SF_STREAM_OPEN;

  this->do_SSL_state_machine ();

  return 0;
}


// ************************************************************
//  Asynch_Operation interface
//    read
// ************************************************************
int
ACE_SSL_Asynch_Stream::read (ACE_Message_Block & message_block,
                             size_t bytes_to_read,
                             const void * act,
                             int priority,
                             int signal_number)
{
  ACE_MT (ACE_GUARD_RETURN (ACE_SYNCH_MUTEX, ace_mon, this->mutex_, -1));

  if ((this->flags_ & SF_STREAM_OPEN) == 0)  // not open
    return -1;

  if (this->flags_ & SF_REQ_SHUTDOWN)
    return -1;

  // only one read operation is allowed now
  // later it will be possible to make a queue

  if (this->ext_read_result_ != 0)
    return -1;

  // create result for future notification
  ACE_NEW_RETURN (this->ext_read_result_,
                  ACE_SSL_Asynch_Read_Stream_Result (
                    *this->ext_handler_,
                    this->handle (),
                    message_block,
                    bytes_to_read,
                    act,
                    this->proactor_->get_handle(),
                    priority,
                    signal_number),
                  -1);

  this->do_SSL_state_machine (); // ignore return code

  return 0;
}

// ************************************************************
//  Asynch_Operation interface
//    write
// ************************************************************
int
ACE_SSL_Asynch_Stream::write (ACE_Message_Block & message_block,
                              size_t bytes_to_write,
                              const void * act,
                              int priority,
                              int signal_number)
{
  ACE_MT (ACE_GUARD_RETURN (ACE_SYNCH_MUTEX, ace_mon, this->mutex_, -1));

  if ((this->flags_ & SF_STREAM_OPEN) == 0)  // not open
    return -1;

  if (this->flags_ & SF_REQ_SHUTDOWN)
    return -1;

  // only one read operation is allowed now
  // later it will be possible to make a queue

  if (this->ext_write_result_ != 0)
    return -1;

  // create result for future notification
  ACE_NEW_RETURN (this->ext_write_result_,
                  ACE_SSL_Asynch_Write_Stream_Result (
                    *this->ext_handler_,
                    this->handle (),
                    message_block,
                    bytes_to_write,
                    act,
                    this->proactor_->get_handle(),
                    priority,
                    signal_number),
                  -1);

  this->do_SSL_state_machine ();

  return 0;
}

// ************************************************************
//  Main SSL engine
// ************************************************************
int
ACE_SSL_Asynch_Stream::do_SSL_state_machine (void)
{
  // this protected member should be called
  // with locked mutex_

  int retval = this->do_SSL_handshake ();

  if (retval == 0)          // handshake in progress ?
    return 0;

  if (retval < 0)
    this->flags_ |= SF_REQ_SHUTDOWN;

  this->do_SSL_read ();  // execute user read request
  this->do_SSL_write (); // execute user write request

  if ((this->flags_ & SF_REQ_SHUTDOWN) == 0)     // Do we have any errors
    return 0;

  this->do_SSL_shutdown ();

  this->notify_close ();

  return 0;
}

// ************************************************************
// do_SSL_shutdown
// return code:
// 1   SSL shutdown is finished already, success
// 0   SSL shutdown in progress
// -1  failure
// ************************************************************
int
ACE_SSL_Asynch_Stream::do_SSL_shutdown (void)
{
  if (this->flags_ & SF_SHUTDOWN_DONE) // already done
    return 1;

  this->flags_ |= SF_REQ_SHUTDOWN;

  // if we have any uncompleted user requests
  // than cancel its
  this->notify_read  (0, ERR_CANCELED);
  this->notify_write (0, ERR_CANCELED);

  int retval = ::SSL_shutdown (this->ssl_);

  int status = ::SSL_get_error (this->ssl_, retval);

  switch (status)
    {
    case SSL_ERROR_NONE:
    case SSL_ERROR_ZERO_RETURN:
    case SSL_ERROR_SYSCALL:
      retval = 1;
      break;

    case SSL_ERROR_WANT_READ:
    case SSL_ERROR_WANT_WRITE:
    case SSL_ERROR_WANT_CONNECT:
    //   case SSL_ERROR_WANT_ACCEPT:
    case SSL_ERROR_WANT_X509_LOOKUP:
      return 0;

    default:
      this->print_error (status,
                         ACE_TEXT ("Shutdown error"));
      retval = -1;
      break;
    }

  this->flags_ |= SF_SHUTDOWN_DONE;

  return retval;
}

// ************************************************************
// Do SSL handshake if necessary
// return code:
// 1   SSL handshake is finished already, success
// 0   SSL handshake in progress
// -1  failure
// ************************************************************
int
ACE_SSL_Asynch_Stream::do_SSL_handshake (void)
{
  if (SSL_is_init_finished (this->ssl_))
    {
      if (!handshake_complete_)
        {
          handshake_complete_ = true;

          if (!post_handshake_check ())
            {
              return -1;
            }
        }
      return 1;
    }

  if (this->flags_ & SF_REQ_SHUTDOWN)
    return -1;

  int retval = -1;

  switch (this->type_)
    {
    case ST_CLIENT:
      retval = ::SSL_connect (this->ssl_);
      break;

    case ST_SERVER:
      retval = ::SSL_accept (this->ssl_);
      break;

    default:
      ACE_ERROR_RETURN
        ((LM_ERROR,
          ACE_TEXT ("(%P|%t) ACE_SSL_Asynch_Stream %p\n"),
          ACE_TEXT ("- invalid stream type")),
         -1);
    }

  int status = ::SSL_get_error (this->ssl_, retval);

  switch (status)
    {
    case SSL_ERROR_NONE:
      break;

    case SSL_ERROR_WANT_READ:
    case SSL_ERROR_WANT_WRITE:
    case SSL_ERROR_WANT_CONNECT:
    //case SSL_ERROR_WANT_ACCEPT:
    case SSL_ERROR_WANT_X509_LOOKUP:
      return 0;

    case SSL_ERROR_ZERO_RETURN:
    case SSL_ERROR_SYSCALL:
    default:
      this->print_error (status,
                         ACE_TEXT ("Handshake error"));
      return -1;
    }

  return 1;
}


bool
ACE_SSL_Asynch_Stream::post_handshake_check (void)
{
  return true;
}

// ************************************************************
// Perform SSL_read call if necessary and notify user
// ************************************************************
int
ACE_SSL_Asynch_Stream::do_SSL_read (void)
{
  if (this->ext_read_result_ == 0)  // nothing to do
    {
      return 0;
    }

  if (this->flags_ & SF_REQ_SHUTDOWN)
    {
      this->notify_read (0, ERR_CANCELED);
      return -1;
    }

  ACE_Message_Block & mb = this->ext_read_result_->message_block ();
  size_t bytes_req = this->ext_read_result_->bytes_to_read ();

  ERR_clear_error ();

  const int bytes_trn =
    ::SSL_read (this->ssl_,
                mb.wr_ptr (),
                ACE_Utils::truncate_cast<int> (bytes_req));

  int const status = ::SSL_get_error (this->ssl_, bytes_trn);

  switch (status)
    {
    case SSL_ERROR_NONE:
      this->notify_read (bytes_trn, 0);
      return 1;

    case SSL_ERROR_WANT_READ:
    case SSL_ERROR_WANT_WRITE:
      return 0;

    case SSL_ERROR_ZERO_RETURN:
      this->notify_read (0, 0);
      return 1;

    case SSL_ERROR_SYSCALL:
      if (bytes_trn == 0)
        {
          this->notify_read (0, 0);
          return 1;
        }
      // If not an EOF, then fall through to "default" case.

    default:
      break;
    }

 this->notify_read (0, EFAULT);
 this->print_error (status,
                    ACE_TEXT ("SSL_read error"));

 return -1;
}

// ************************************************************
// Perform SSL_write call if necessary  and notify user
// ************************************************************
int
ACE_SSL_Asynch_Stream::do_SSL_write (void)
{
  if (this->ext_write_result_ == 0)  // nothing to do
    {
      return 0;
    }

  if (this->flags_ & SF_REQ_SHUTDOWN)
    {
      this->notify_write (0, ERR_CANCELED);
      return -1;
    }

  ACE_Message_Block & mb = this->ext_write_result_->message_block ();
  size_t       bytes_req = this->ext_write_result_->bytes_to_write ();

  ERR_clear_error ();

  const int bytes_trn =
    ::SSL_write (this->ssl_,
                 mb.rd_ptr (),
                 ACE_Utils::truncate_cast<int> (bytes_req));

  int const status = ::SSL_get_error (this->ssl_, bytes_trn);

  switch (status)
    {
    case SSL_ERROR_NONE:
      this->notify_write (bytes_trn, 0);
      return 1;

    case SSL_ERROR_WANT_READ:
    case SSL_ERROR_WANT_WRITE:
      return 0;

    case SSL_ERROR_ZERO_RETURN:
      this->notify_write (bytes_trn, 0);
      return 1;

    case SSL_ERROR_SYSCALL:
    default:
      break;
    }

 this->notify_write(0, EFAULT);
 this->print_error (status,
                    ACE_TEXT ("SSL_write error"));

 return -1;
}

// ************************************************************
//  notify external user handler that
//  it is now to safe destroy stream
//  Return code  looks like cancel() return code
//  0  - notified               NOTIFIED
//  1  - nothing to notify      ALLDONE
//  2  - unable to notify       NOT NOTIFIED
// ************************************************************
int
ACE_SSL_Asynch_Stream::notify_close (void)
{
  if (this->flags_ & SF_CLOSE_NTF_SENT)  // already sent
    return 1;

  if ((this->flags_ & SF_SHUTDOWN_DONE) == 0)  // only after shutdown
    return 2;    // too early , we will do later

  if (this->pending_BIO_count () != 0)   // wait for all internal IO
    return 2;   // too early , we will do later

  // create result for future notification
  ACE_SSL_Asynch_Result * close_result = 0;

  ACE_NEW_RETURN (close_result,
                  ACE_SSL_Asynch_Result (*this),
                  2);
  //@@ Not exception safe!

 int retval =
   close_result->post_completion (this->proactor_->implementation ());

 if (retval == 0)
   {
     this->flags_ |= SF_CLOSE_NTF_SENT;
     return 0;
   }

 delete close_result;
 return 2;
}

// ************************************************************
//  notify external user handler about user write completion
//  Return code  looks like cancel() return code
//  0  - notified               NOTIFIED/CANCELED
//  1  - nothing to notify      ALLDONE
//  2  - unable to notify       NOT NOTIFIED/CANCELED
// ************************************************************

int
ACE_SSL_Asynch_Stream::notify_read (int bytes_transferred,
                                    int error)
{
  if (ext_read_result_ == 0) //nothing to notify
    return 1;

  this->ext_read_result_->set_bytes_transferred (bytes_transferred);
  this->ext_read_result_->set_error (error);

  int retval =
    this->ext_read_result_->post_completion (proactor_->implementation ());

  if (retval == 0)
    {
      this->ext_read_result_ = 0;
      return 0;  // success
    }

  return 2; // unable to notify
}

// ************************************************************
//  notify external user handler about user write completion
//  Return code  looks like cancel() return code
//  0  - notified               NOTIFIED/CANCELED
//  1  - nothing to notify      ALLDONE
//  2  - unable to notify       NOT NOTIFIED/CANCELED
// ************************************************************

int
ACE_SSL_Asynch_Stream::notify_write (int bytes_transferred,
                                     int error)
{
  if (this->ext_write_result_ == 0) //nothing to notify
    return 1;

  this->ext_write_result_->set_bytes_transferred (bytes_transferred);
  this->ext_write_result_->set_error (error);

  int retval =
    this->ext_write_result_->post_completion (
      this->proactor_->implementation ());

  if (retval == 0)
    {
      this->ext_write_result_ = 0;
      return 0;  // success
    }

  return 2; // unable to notify
}

// ************************************************************
// Print SSL errors
// ************************************************************
void
ACE_SSL_Asynch_Stream::print_error (int err_ssl,
                                    const ACE_TCHAR * pText)
{
  ACE_DEBUG ((LM_DEBUG,
              ACE_TEXT("SSL-error:%d %s\n"),
              err_ssl,
              pText));

#if OPENSSL_VERSION_NUMBER >= 0x0090601fL
  // OpenSSL < 0.9.6a doesn't have ERR_error_string_n() function.
  unsigned long lerr = 0;
  char buf[1024];

  while ((lerr = ERR_get_error()) != 0)
    {
      ERR_error_string_n (lerr, buf, sizeof buf);

      ACE_DEBUG ((LM_DEBUG, "%C\n", buf));
    }
#endif  /* OPENSSL_VERSION_NUMBER */
}

// ************************************************************
//  BIO helper functions
//  SSL library will ask BIO to do raw I/O
//  BIO will call us to do this
// ************************************************************
int
ACE_SSL_Asynch_Stream::ssl_bio_read (char * buf,
                                     size_t len,
                                     int & errval)
{
  // We do not have to acquire mutex
  // as we called already with locked mutex
  // from do_SSL_state_machine()

  errval = 0;

  size_t cur_len = this->bio_inp_msg_.length ();

  if (cur_len > 0) // there are more data buffered
    {
      const char * rd_ptr = this->bio_inp_msg_.rd_ptr ();

      if (cur_len > len)
        {
          cur_len = len;
        }

      ACE_OS::memcpy (buf, rd_ptr, cur_len);

      this->bio_inp_msg_.rd_ptr (cur_len); // go ahead

      return ACE_Utils::truncate_cast<int> (cur_len);
    }

  if (this->bio_inp_errno_ != 0)     // if was error - it is permanent !
    {
      errval = this->bio_inp_errno_;
      return -1;
    }

  if (this->bio_inp_flag_ & BF_EOS)  // End of stream
    {
      return 0;
    }

  errval = EINPROGRESS;          // SSL will try later

  if (this->bio_inp_flag_ & BF_AIO)  // we are busy
    {
      return -1;
    }

  if (this->bio_inp_msg_.size (len) != 0)
    {
      ACE_ERROR
        ((LM_ERROR,
          ACE_TEXT ("%N:%l ((%P|%t) ACE_SSL_Asynch_Stream %p\n"),
          ACE_TEXT ("error in ACE_Message_Block::size() ")
          ));

      errval = EINVAL;
      return -1;
    }

  char * base = this->bio_inp_msg_.base ();

  this->bio_inp_msg_.rd_ptr (base);
  this->bio_inp_msg_.wr_ptr (base);

  if (this->bio_istream_.read (
        bio_inp_msg_,  // message block
        len,           // priority
        0,             // act
        0,             // priority
        ACE_SIGRTMIN   // default signal
        ) == -1)
    {
      ACE_ERROR
        ((LM_ERROR,
          ACE_TEXT ("%N:%l (%P|%t) ACE_SSL_Asynch_Stream %p\n"),
          ACE_TEXT ("attempt read failed")
          ));

      errval = EINVAL;  // may be leave EINPROGRESS ??
      return -1;        // to try later
    }

  this->bio_inp_flag_ |= BF_AIO;  // AIO is active

  return -1;
}


int
ACE_SSL_Asynch_Stream::ssl_bio_write (const char * buf,
                                      size_t len,
                                      int & errval)
{
  // We do not have to acquire mutex
  // as we called already with locked mutex
  // from do_SSL_state_machine

  errval = 0;

  if (this->bio_out_flag_ & BF_AIO)  // sorry, we are busy
    {
      errval = EINPROGRESS;   // try later
      return -1;
    }

  if (this->bio_out_errno_ != 0)      // no recovery
    {
      errval = this->bio_out_errno_;
      return -1;
    }

  if (this->bio_out_msg_.size (len) != 0)
    {
      ACE_ERROR
        ((LM_ERROR,
          ACE_TEXT ("%N:%l ((%P|%t) ACE_SSL_Asynch_Stream %p\n"),
          ACE_TEXT ("error in ACE_Message_Block::size() ")
          ));

      errval = EINVAL;
      return -1;
    }

  char * base = this->bio_out_msg_.base ();

  this->bio_out_msg_.rd_ptr (base);
  this->bio_out_msg_.wr_ptr (base);

  if (this->bio_out_msg_.copy (buf, len) == -1)
    {
      ACE_ERROR
        ((LM_ERROR,
          ACE_TEXT ("%N:%l ((%P|%t) ACE_SSL_Asynch_Stream %p\n"),
          ACE_TEXT ("error in ACE_Message_Block::copy() ")
          ));

      errval = EINVAL;
      return -1;
    }


  if (this->bio_ostream_.write (
        this->bio_out_msg_, // message block
        len,          // priority
        0,            // act
        0,            // priority
        ACE_SIGRTMIN  // default signal
        ) == -1)
    {
      ACE_ERROR
        ((LM_ERROR,
          ACE_TEXT ("%N:%l ((%P|%t) ACE_SSL_Asynch_Stream %p\n"),
          ACE_TEXT ("attempt write failed")
          ));

      errval = EINVAL;  // may be leave EINPROGRESS ??
      return -1;        // to try later
    }

  this->bio_out_flag_ |= BF_AIO;  // AIO is active
  errval = 0;               // Ok, go ahead

  return ACE_Utils::truncate_cast<int> (len);
}

// ************************************************************
//  Internal IO handlers
//  virtual from ACE_Service_Handler
// ************************************************************
void
ACE_SSL_Asynch_Stream::handle_write_stream (
  const ACE_Asynch_Write_Stream::Result &result)
{
  ACE_MT (ACE_GUARD (ACE_SYNCH_MUTEX, ace_mon, this->mutex_));

  this->bio_out_flag_ &= ~BF_AIO;

  ACE_Message_Block & mb = result.message_block ();

  size_t bytes_req = result.bytes_to_write ();
  size_t bytes_trn = result.bytes_transferred ();
  u_long errval    = result.error ();
  size_t len       = bytes_req - bytes_trn;

  if (errval != 0)                    // error ?
    this->bio_out_errno_ = errval;    // save err code
  else if (len > 0)                   // TCP/IP overloaded ?
    {                                 // continue, rd_ptr at right place
      if (this->bio_ostream_.write (
            mb,          // message block
            len,         // priority
            0,           // act
            0,           // priority
            ACE_SIGRTMIN // default signal
            ) == 0)
        {
          this->bio_out_flag_ |= BF_AIO;
          return;
        }

      ACE_ERROR
        ((LM_ERROR,
          ACE_TEXT ("(%P|%t) ACE_SSL_Asynch_Stream %p\n"),
          ACE_TEXT ("attempt write failed")
          ));

      this->bio_out_errno_ = EINVAL;
    }

  this->do_SSL_state_machine ();

  return;
}

void
ACE_SSL_Asynch_Stream::handle_read_stream (
  const ACE_Asynch_Read_Stream::Result &result)
{
  ACE_MT (ACE_GUARD (ACE_SYNCH_MUTEX, ace_mon, this->mutex_));

  this->bio_inp_flag_ &= ~BF_AIO;

  size_t bytes_trn = result.bytes_transferred ();
  u_long errval    = result.error ();

  if (errval != 0)                     // error ?
     this->bio_inp_errno_ = errval;    // save err code
  else if (bytes_trn == 0)             // end of stream ?
     this->bio_inp_flag_ |= BF_EOS;    // set flag EOS

  this->do_SSL_state_machine ();

  return;
}

void
ACE_SSL_Asynch_Stream::handle_wakeup (void)
{
  ACE_Handler * user_handler = 0;

  {
    ACE_MT (ACE_GUARD (ACE_SYNCH_MUTEX, ace_mon, this->mutex_));

    this->flags_ |= SF_DELETE_ENABLE;

    user_handler = this->ext_handler_;
  }

  if (user_handler != 0)
    user_handler->handle_wakeup();
}

int
ACE_SSL_Asynch_Stream::pending_BIO_count (void)
{
  int ret = 0;

  if (this->bio_inp_flag_ & BF_AIO)
    ++ret;

  if (this->bio_out_flag_ & BF_AIO)
    ++ret;

  return ret;
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif  /* OPENSSL_VERSION_NUMBER > 0x0090581fL && (ACE_WIN32 ||
           ACE_HAS_AIO_CALLS) */
