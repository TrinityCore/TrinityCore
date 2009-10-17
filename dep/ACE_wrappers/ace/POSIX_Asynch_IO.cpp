// $Id: POSIX_Asynch_IO.cpp 81535 2008-04-29 20:08:52Z shuston $
#include "ace/POSIX_Asynch_IO.h"
#if defined (ACE_HAS_AIO_CALLS)
#include "ace/Flag_Manip.h"
#include "ace/Proactor.h"
#include "ace/Message_Block.h"
#include "ace/INET_Addr.h"
#include "ace/Asynch_Pseudo_Task.h"
#include "ace/POSIX_Proactor.h"
#include "ace/OS_NS_errno.h"
#include "ace/OS_NS_sys_socket.h"
#include "ace/OS_NS_sys_stat.h"
ACE_RCSID (ace,
           POSIX_Asynch_IO,
           "$Id: POSIX_Asynch_IO.cpp 81535 2008-04-29 20:08:52Z shuston $")

ACE_BEGIN_VERSIONED_NAMESPACE_DECL
size_t
ACE_POSIX_Asynch_Result::bytes_transferred (void) const
{
  return this->bytes_transferred_;
}
void
ACE_POSIX_Asynch_Result::set_bytes_transferred (size_t nbytes)
{
  this->bytes_transferred_= nbytes;
}
const void *
ACE_POSIX_Asynch_Result::act (void) const
{
  return this->act_;
}
int
ACE_POSIX_Asynch_Result::success (void) const
{
  return this->success_;
}
const void *
ACE_POSIX_Asynch_Result::completion_key (void) const
{
  return this->completion_key_;
}
u_long
ACE_POSIX_Asynch_Result::error (void) const
{
  return this->error_;
}
void
ACE_POSIX_Asynch_Result::set_error (u_long errcode)
{
  this->error_=errcode;
}
ACE_HANDLE
ACE_POSIX_Asynch_Result::event (void) const
{
  return ACE_INVALID_HANDLE;
}
u_long
ACE_POSIX_Asynch_Result::offset (void) const
{
  return this->aio_offset;
}
u_long
ACE_POSIX_Asynch_Result::offset_high (void) const
{
  //
  // @@ Support aiocb64??
  //
  ACE_NOTSUP_RETURN (0);
}
int
ACE_POSIX_Asynch_Result::priority (void) const
{
  return this->aio_reqprio;
}
int
ACE_POSIX_Asynch_Result::signal_number (void) const
{
  return this->aio_sigevent.sigev_signo;
}
int
ACE_POSIX_Asynch_Result::post_completion (ACE_Proactor_Impl *proactor_impl)
{
  // Get to the platform specific implementation.
  ACE_POSIX_Proactor *posix_proactor = dynamic_cast<ACE_POSIX_Proactor *> (proactor_impl);
  if (posix_proactor == 0)
    ACE_ERROR_RETURN ((LM_ERROR, "Dynamic cast to POSIX Proactor failed\n"), -1);
  // Post myself.
  return posix_proactor->post_completion (this);
}
ACE_POSIX_Asynch_Result::~ACE_POSIX_Asynch_Result (void)
{
}
ACE_POSIX_Asynch_Result::ACE_POSIX_Asynch_Result
  (const ACE_Handler::Proxy_Ptr &handler_proxy,
   const void* act,
   ACE_HANDLE /* event */,      // Event is not used on POSIX.
   u_long offset,
   u_long offset_high,
   int priority,
   int signal_number)
  : handler_proxy_ (handler_proxy),
    act_ (act),
    bytes_transferred_ (0),
    success_ (0),
    completion_key_ (0),
    error_ (0)
{
  aio_offset = offset;
  aio_reqprio = priority;
  aio_sigevent.sigev_signo = signal_number;
  //
  // @@ Support offset_high with aiocb64.
  //
  ACE_UNUSED_ARG (offset_high);
  // Other fields in the <aiocb> will be initialized by the
  // subclasses.
}
// ****************************************************************
int
ACE_POSIX_Asynch_Operation::open (const ACE_Handler::Proxy_Ptr &handler_proxy,
                                  ACE_HANDLE handle,
                                  const void * /* completion_key */,
                                  ACE_Proactor *proactor)
{
  this->proactor_ = proactor;
  this->handler_proxy_ = handler_proxy;
  this->handle_ = handle;
  // Grab the handle from the <handler> if <handle> is invalid
  if (this->handle_ == ACE_INVALID_HANDLE)
    {
      ACE_Handler *handler = handler_proxy.get ()->handler ();
      if (handler != 0)
        this->handle_ = handler->handle ();
    }
  if (this->handle_ == ACE_INVALID_HANDLE)
    return -1;
#if 0
  // @@ If <proactor> is 0, let us not bother about getting this
  // Proactor, we have already got the specific implementation
  // Proactor.
  // If no proactor was passed
  if (this->proactor_ == 0)
    {
      // Grab the proactor from the <Service_Config> if
      // <handler->proactor> is zero
      this->proactor_ = this->handler_->proactor ();
      if (this->proactor_ == 0)
        this->proactor_ = ACE_Proactor::instance();
    }
#endif /* 0 */
  return 0;
}
int
ACE_POSIX_Asynch_Operation::cancel (void)
{
  if (!posix_proactor_)
    return -1;
  return posix_proactor_->cancel_aio (this->handle_);
}
ACE_Proactor *
ACE_POSIX_Asynch_Operation::proactor (void) const
{
  return this->proactor_;
}
ACE_POSIX_Proactor *
ACE_POSIX_Asynch_Operation::posix_proactor (void) const
{
  return this->posix_proactor_;
}
ACE_POSIX_Asynch_Operation::~ACE_POSIX_Asynch_Operation (void)
{
}
ACE_POSIX_Asynch_Operation::ACE_POSIX_Asynch_Operation (ACE_POSIX_Proactor *posix_proactor)
  : posix_proactor_ (posix_proactor),
    handle_  (ACE_INVALID_HANDLE)
{
}
// *********************************************************************
size_t
ACE_POSIX_Asynch_Read_Stream_Result::bytes_to_read (void) const
{
  return this->aio_nbytes;
}
ACE_Message_Block &
ACE_POSIX_Asynch_Read_Stream_Result::message_block (void) const
{
  return this->message_block_;
}
ACE_HANDLE
ACE_POSIX_Asynch_Read_Stream_Result::handle (void) const
{
  return this->aio_fildes;
}
ACE_POSIX_Asynch_Read_Stream_Result::ACE_POSIX_Asynch_Read_Stream_Result
  (const ACE_Handler::Proxy_Ptr &handler_proxy,
   ACE_HANDLE handle,
   ACE_Message_Block &message_block,
   size_t bytes_to_read,
   const void* act,
   ACE_HANDLE event,
   int priority,
   int signal_number)
  : ACE_POSIX_Asynch_Result
      (handler_proxy, act, event, 0, 0, priority, signal_number),
    message_block_ (message_block)
{
  this->aio_fildes = handle;
  this->aio_buf = message_block.wr_ptr ();
  this->aio_nbytes = bytes_to_read;
}
void
ACE_POSIX_Asynch_Read_Stream_Result::complete (size_t bytes_transferred,
                                               int success,
                                               const void *completion_key,
                                               u_long error)
{
  this->bytes_transferred_ = bytes_transferred;
  this->success_ = success;
  this->completion_key_ = completion_key;
  this->error_ = error;
  // <errno> is available in the aiocb.
  ACE_UNUSED_ARG (error);
  // Appropriately move the pointers in the message block.
  this->message_block_.wr_ptr (bytes_transferred);
  // Create the interface result class.
  ACE_Asynch_Read_Stream::Result result (this);
  // Call the application handler.
  ACE_Handler *handler = this->handler_proxy_.get ()->handler ();
  if (handler != 0)
    handler->handle_read_stream (result);
}
ACE_POSIX_Asynch_Read_Stream_Result::~ACE_POSIX_Asynch_Read_Stream_Result (void)
{
}
// ************************************************************
ACE_POSIX_Asynch_Read_Stream::ACE_POSIX_Asynch_Read_Stream (ACE_POSIX_Proactor  *posix_proactor)
  : ACE_POSIX_Asynch_Operation (posix_proactor)
{
}
int
ACE_POSIX_Asynch_Read_Stream::read (ACE_Message_Block &message_block,
                                    size_t bytes_to_read,
                                    const void *act,
                                    int priority,
                                    int signal_number)
{
  size_t space = message_block.space ();
  if (bytes_to_read > space)
     bytes_to_read=space;
  if (bytes_to_read == 0)
    {
      errno = ENOSPC;
      return -1;
    }
  // Create the Asynch_Result.
  ACE_POSIX_Asynch_Read_Stream_Result *result = 0;
  ACE_POSIX_Proactor *proactor = this->posix_proactor ();
  ACE_NEW_RETURN (result,
                  ACE_POSIX_Asynch_Read_Stream_Result (this->handler_proxy_,
                                                       this->handle_,
                                                       message_block,
                                                       bytes_to_read,
                                                       act,
                                                       proactor->get_handle (),
                                                       priority,
                                                       signal_number),
                  -1);
  int return_val = proactor->start_aio (result, ACE_POSIX_Proactor::ACE_OPCODE_READ);
  if (return_val == -1)
    delete result;
  return return_val;
}
ACE_POSIX_Asynch_Read_Stream::~ACE_POSIX_Asynch_Read_Stream (void)
{
}
// *********************************************************************
size_t
ACE_POSIX_Asynch_Write_Stream_Result::bytes_to_write (void) const
{
  return this->aio_nbytes;
}
ACE_Message_Block &
ACE_POSIX_Asynch_Write_Stream_Result::message_block (void) const
{
  return this->message_block_;
}
ACE_HANDLE
ACE_POSIX_Asynch_Write_Stream_Result::handle (void) const
{
  return this->aio_fildes;
}
ACE_POSIX_Asynch_Write_Stream_Result::ACE_POSIX_Asynch_Write_Stream_Result
  (const ACE_Handler::Proxy_Ptr &handler_proxy,
   ACE_HANDLE handle,
   ACE_Message_Block &message_block,
   size_t bytes_to_write,
   const void* act,
   ACE_HANDLE event,
   int priority,
   int signal_number)
  : ACE_POSIX_Asynch_Result
      (handler_proxy, act, event, 0, 0, priority, signal_number),
    message_block_ (message_block)
{
  this->aio_fildes = handle;
  this->aio_buf = message_block.rd_ptr ();
  this->aio_nbytes = bytes_to_write;
}
void
ACE_POSIX_Asynch_Write_Stream_Result::complete (size_t bytes_transferred,
                                                int success,
                                                const void *completion_key,
                                                u_long error)
{
  // Get all the data copied.
  this->bytes_transferred_ = bytes_transferred;
  this->success_ = success;
  this->completion_key_ = completion_key;
  this->error_ = error;
  // <errno> is available in the aiocb.
  ACE_UNUSED_ARG (error);
  // Appropriately move the pointers in the message block.
  this->message_block_.rd_ptr (bytes_transferred);
  // Create the interface result class.
  ACE_Asynch_Write_Stream::Result result (this);
  // Call the application handler.
  ACE_Handler *handler = this->handler_proxy_.get ()->handler ();
  if (handler != 0)
    handler->handle_write_stream (result);
}
ACE_POSIX_Asynch_Write_Stream_Result::~ACE_POSIX_Asynch_Write_Stream_Result (void)
{
}
// *********************************************************************
ACE_POSIX_Asynch_Write_Stream::ACE_POSIX_Asynch_Write_Stream (ACE_POSIX_Proactor *posix_proactor)
  : ACE_POSIX_Asynch_Operation (posix_proactor)
{
}
int
ACE_POSIX_Asynch_Write_Stream::write (ACE_Message_Block &message_block,
                                      size_t bytes_to_write,
                                      const void *act,
                                      int priority,
                                      int signal_number)
{
  size_t len = message_block.length ();
  if (bytes_to_write > len)
     bytes_to_write = len;
  if (bytes_to_write == 0)
    ACE_ERROR_RETURN
      ((LM_ERROR,
        ACE_TEXT ("ACE_POSIX_Asynch_Write_Stream::write:")
        ACE_TEXT ("Attempt to write 0 bytes\n")),
      -1);
  ACE_POSIX_Asynch_Write_Stream_Result *result = 0;
  ACE_POSIX_Proactor *proactor = this->posix_proactor ();
  ACE_NEW_RETURN (result,
                  ACE_POSIX_Asynch_Write_Stream_Result (this->handler_proxy_,
                                                        this->handle_,
                                                        message_block,
                                                        bytes_to_write,
                                                        act,
                                                        proactor->get_handle (),
                                                        priority,
                                                        signal_number),
                  -1);
  int return_val = proactor->start_aio (result, ACE_POSIX_Proactor::ACE_OPCODE_WRITE);
  if (return_val == -1)
    delete result;
  return return_val;
}
ACE_POSIX_Asynch_Write_Stream::~ACE_POSIX_Asynch_Write_Stream (void)
{
}
// *********************************************************************
ACE_POSIX_Asynch_Read_File_Result::ACE_POSIX_Asynch_Read_File_Result
  (const ACE_Handler::Proxy_Ptr &handler_proxy,
   ACE_HANDLE handle,
   ACE_Message_Block &message_block,
   size_t bytes_to_read,
   const void* act,
   u_long offset,
   u_long offset_high,
   ACE_HANDLE event,
   int priority,
   int signal_number)
  : ACE_POSIX_Asynch_Read_Stream_Result (handler_proxy,
                                         handle,
                                         message_block,
                                         bytes_to_read,
                                         act,
                                         event,
                                         priority,
                                         signal_number)
{
  this->aio_offset = offset;
  //
  // @@ Use aiocb64??
  //
  ACE_UNUSED_ARG (offset_high);
}
void
ACE_POSIX_Asynch_Read_File_Result::complete (size_t bytes_transferred,
                                             int success,
                                             const void *completion_key,
                                             u_long error)
{
  // Copy all the data.
  this->bytes_transferred_ = bytes_transferred;
  this->success_ = success;
  this->completion_key_ = completion_key;
  this->error_ = error;
  // <errno> is available in the aiocb.
  ACE_UNUSED_ARG (error);
  // Appropriately move the pointers in the message block.
  this->message_block_.wr_ptr (bytes_transferred);
  // Create the interface result class.
  ACE_Asynch_Read_File::Result result (this);
  // Call the application handler.
  ACE_Handler *handler = this->handler_proxy_.get ()->handler ();
  if (handler != 0)
    handler->handle_read_file (result);
}
ACE_POSIX_Asynch_Read_File_Result::~ACE_POSIX_Asynch_Read_File_Result (void)
{
}
// *********************************************************************
ACE_POSIX_Asynch_Read_File::ACE_POSIX_Asynch_Read_File (ACE_POSIX_Proactor *posix_proactor)
  : ACE_POSIX_Asynch_Read_Stream (posix_proactor)
{
}
int
ACE_POSIX_Asynch_Read_File::read (ACE_Message_Block &message_block,
                                  size_t bytes_to_read,
                                  u_long offset,
                                  u_long offset_high,
                                  const void *act,
                                  int priority,
                                  int signal_number)
{
  size_t space = message_block.space ();
  if ( bytes_to_read > space )
     bytes_to_read=space;
  if ( bytes_to_read == 0 )
    ACE_ERROR_RETURN
      ((LM_ERROR,
        ACE_TEXT ("ACE_POSIX_Asynch_Read_File::read:")
        ACE_TEXT ("Attempt to read 0 bytes or no space in the message block\n")),
       -1);
  ACE_POSIX_Asynch_Read_File_Result *result = 0;
  ACE_POSIX_Proactor *proactor = this->posix_proactor ();
  ACE_NEW_RETURN (result,
                  ACE_POSIX_Asynch_Read_File_Result (this->handler_proxy_,
                                                     this->handle_,
                                                     message_block,
                                                     bytes_to_read,
                                                     act,
                                                     offset,
                                                     offset_high,
                                                     posix_proactor ()->get_handle (),
                                                     priority,
                                                     signal_number),
                  -1);
  int return_val = proactor->start_aio (result, ACE_POSIX_Proactor::ACE_OPCODE_READ);
  if (return_val == -1)
    delete result;
  return return_val;
}
ACE_POSIX_Asynch_Read_File::~ACE_POSIX_Asynch_Read_File (void)
{
}
int
ACE_POSIX_Asynch_Read_File::read (ACE_Message_Block &message_block,
                                  size_t bytes_to_read,
                                  const void *act,
                                  int priority,
                                  int signal_number)
{
  return ACE_POSIX_Asynch_Read_Stream::read (message_block,
                                             bytes_to_read,
                                             act,
                                             priority,
                                             signal_number);
}
// ************************************************************
ACE_POSIX_Asynch_Write_File_Result::ACE_POSIX_Asynch_Write_File_Result
  (const ACE_Handler::Proxy_Ptr &handler_proxy,
   ACE_HANDLE handle,
   ACE_Message_Block &message_block,
   size_t bytes_to_write,
   const void* act,
   u_long offset,
   u_long offset_high,
   ACE_HANDLE event,
   int priority,
   int signal_number)
  : ACE_POSIX_Asynch_Write_Stream_Result (handler_proxy,
                                          handle,
                                          message_block,
                                          bytes_to_write,
                                          act,
                                          event,
                                          priority,
                                          signal_number)
{
  this->aio_offset = offset;
  //
  // @@ Support offset_high with aiocb64.
  //
  ACE_UNUSED_ARG (offset_high);
}
void
ACE_POSIX_Asynch_Write_File_Result::complete (size_t bytes_transferred,
                                              int success,
                                              const void *completion_key,
                                              u_long error)
{
  // Copy the data.
  this->bytes_transferred_ = bytes_transferred;
  this->success_ = success;
  this->completion_key_ = completion_key;
  this->error_ = error;
  // <error> is available in <aio_resultp.aio_error>
  ACE_UNUSED_ARG (error);
  // Appropriately move the pointers in the message block.
  this->message_block_.rd_ptr (bytes_transferred);
  // Create the interface result class.
  ACE_Asynch_Write_File::Result result (this);
  // Call the application handler.
  ACE_Handler *handler = this->handler_proxy_.get ()->handler ();
  if (handler != 0)
    handler->handle_write_file (result);
}
ACE_POSIX_Asynch_Write_File_Result::~ACE_POSIX_Asynch_Write_File_Result  (void)
{
}
// *********************************************************************
ACE_POSIX_Asynch_Write_File::ACE_POSIX_Asynch_Write_File (ACE_POSIX_Proactor *posix_proactor)
  : ACE_POSIX_Asynch_Write_Stream (posix_proactor)
{
}
int
ACE_POSIX_Asynch_Write_File::write (ACE_Message_Block &message_block,
                                    size_t bytes_to_write,
                                    u_long offset,
                                    u_long offset_high,
                                    const void *act,
                                    int priority,
                                    int signal_number)
{
  size_t len = message_block.length ();
  if (bytes_to_write > len)
     bytes_to_write = len;
  if (bytes_to_write == 0)
    ACE_ERROR_RETURN
      ((LM_ERROR,
        ACE_TEXT ("ACE_POSIX_Asynch_Write_File::write:")
        ACE_TEXT ("Attempt to write 0 bytes\n")),
      -1);
  ACE_POSIX_Asynch_Write_File_Result *result = 0;
  ACE_POSIX_Proactor *proactor = this->posix_proactor ();
  ACE_NEW_RETURN (result,
                  ACE_POSIX_Asynch_Write_File_Result (this->handler_proxy_,
                                                      this->handle_,
                                                      message_block,
                                                      bytes_to_write,
                                                      act,
                                                      offset,
                                                      offset_high,
                                                      proactor->get_handle (),
                                                      priority,
                                                      signal_number),
                  -1);
  int return_val = proactor->start_aio (result, ACE_POSIX_Proactor::ACE_OPCODE_WRITE);
  if (return_val == -1)
    delete result;
  return return_val;
}
ACE_POSIX_Asynch_Write_File::~ACE_POSIX_Asynch_Write_File (void)
{
}
int
ACE_POSIX_Asynch_Write_File::write (ACE_Message_Block &message_block,
                                    size_t bytes_to_write,
                                    const void *act,
                                    int priority,
                                    int signal_number)
{
  return ACE_POSIX_Asynch_Write_Stream::write (message_block,
                                                     bytes_to_write,
                                                     act,
                                                     priority,
                                                     signal_number);
}
// *********************************************************************

size_t
ACE_POSIX_Asynch_Accept_Result::bytes_to_read (void) const
{
  return this->aio_nbytes;
}
ACE_Message_Block &
ACE_POSIX_Asynch_Accept_Result::message_block (void) const
{
  return this->message_block_;
}
ACE_HANDLE
ACE_POSIX_Asynch_Accept_Result::listen_handle (void) const
{
  return this->listen_handle_;
}
ACE_HANDLE
ACE_POSIX_Asynch_Accept_Result::accept_handle (void) const
{
  return this->aio_fildes;
}
ACE_POSIX_Asynch_Accept_Result::ACE_POSIX_Asynch_Accept_Result
  (const ACE_Handler::Proxy_Ptr &handler_proxy,
   ACE_HANDLE listen_handle,
   ACE_HANDLE accept_handle,
   ACE_Message_Block &message_block,
   size_t bytes_to_read,
   const void* act,
   ACE_HANDLE event,
   int priority,
   int signal_number)
  : ACE_POSIX_Asynch_Result
      (handler_proxy, act, event, 0, 0, priority, signal_number),
    message_block_ (message_block),
    listen_handle_ (listen_handle)
{
  this->aio_fildes = accept_handle;
  this->aio_nbytes = bytes_to_read;
}
void
ACE_POSIX_Asynch_Accept_Result::complete (size_t bytes_transferred,
                                          int success,
                                          const void *completion_key,
                                          u_long error)
{
  // Copy the data.
  this->bytes_transferred_ = bytes_transferred;
  this->success_ = success;
  this->completion_key_ = completion_key;
  this->error_ = error;
  // Appropriately move the pointers in the message block.
  this->message_block_.wr_ptr (bytes_transferred);
  // Create the interface result class.
  ACE_Asynch_Accept::Result result (this);
  // Call the application handler.
  ACE_Handler *handler = this->handler_proxy_.get ()->handler ();
  if (handler != 0)
    handler->handle_accept (result);
}
ACE_POSIX_Asynch_Accept_Result::~ACE_POSIX_Asynch_Accept_Result (void)
{
}
// *********************************************************************
ACE_POSIX_Asynch_Accept::ACE_POSIX_Asynch_Accept (ACE_POSIX_Proactor * posix_proactor)
  : ACE_POSIX_Asynch_Operation (posix_proactor),
    flg_open_ (false)
{
}
ACE_POSIX_Asynch_Accept::~ACE_POSIX_Asynch_Accept (void)
{
  this->close ();
  this->reactor (0); // to avoid purge_pending_notifications
}
ACE_HANDLE
ACE_POSIX_Asynch_Accept::get_handle (void) const
{
  return this->handle_;
}
void
ACE_POSIX_Asynch_Accept::set_handle (ACE_HANDLE handle)
{
  ACE_ASSERT (handle_ == ACE_INVALID_HANDLE);
  this->handle_ = handle;
}
int
ACE_POSIX_Asynch_Accept::open (const ACE_Handler::Proxy_Ptr &handler_proxy,
                               ACE_HANDLE handle,
                               const void *completion_key,
                               ACE_Proactor *proactor)
{
  ACE_TRACE ("ACE_POSIX_Asynch_Accept::open");
  // if we are already opened,
  // we could not create a new handler without closing the previous
  if (this->flg_open_)
    ACE_ERROR_RETURN ((LM_ERROR,
                       ACE_TEXT("%N:%l:ACE_POSIX_Asynch_Accept::open:")
                       ACE_TEXT("acceptor already open \n")),
                      -1);
  if (-1 == ACE_POSIX_Asynch_Operation::open (handler_proxy,
                                              handle,
                                              completion_key,
                                              proactor))
    return -1;
  flg_open_ = true;
  ACE_Asynch_Pseudo_Task & task =
    this->posix_proactor ()->get_asynch_pseudo_task ();
  if (-1 == task.register_io_handler (this->get_handle(),
                                      this,
                                      ACE_Event_Handler::ACCEPT_MASK,
                                      1))  // suspend after register
    {
      this->flg_open_= false;
      this->handle_ = ACE_INVALID_HANDLE;
      return -1 ;
    }
  return 0;
}
int
ACE_POSIX_Asynch_Accept::accept (ACE_Message_Block &message_block,
                                 size_t bytes_to_read,
                                 ACE_HANDLE accept_handle,
                                 const void *act,
                                 int priority,
                                 int signal_number,
                                 int addr_family)
{
  ACE_TRACE ("ACE_POSIX_Asynch_Accept::accept");
  if (!this->flg_open_)
    ACE_ERROR_RETURN ((LM_ERROR,
                       ACE_TEXT("%N:%l:ACE_POSIX_Asynch_Accept::accept")
                       ACE_TEXT("acceptor was not opened before\n")),
                      -1);
  // Sanity check: make sure that enough space has been allocated by
  // the caller.
  size_t address_size = sizeof (sockaddr_in);
#if defined (ACE_HAS_IPV6)
  if (addr_family == AF_INET6)
    address_size = sizeof (sockaddr_in6);
#else
  ACE_UNUSED_ARG (addr_family);
#endif
  size_t available_space = message_block.space ();
  size_t space_needed = bytes_to_read + 2 * address_size;
  if (available_space < space_needed)
    {
      ACE_OS::last_error (ENOBUFS);
      return -1;
    }
  // Common code for both WIN and POSIX.
  // Create future Asynch_Accept_Result
  ACE_POSIX_Asynch_Accept_Result *result = 0;
  ACE_NEW_RETURN (result,
                  ACE_POSIX_Asynch_Accept_Result (this->handler_proxy_,
                                                  this->handle_,
                                                  accept_handle,
                                                  message_block,
                                                  bytes_to_read,
                                                  act,
                                                  this->posix_proactor()->get_handle (),
                                                  priority,
                                                  signal_number),
                  -1);
  // Enqueue result
  {
    ACE_MT (ACE_GUARD_RETURN (ACE_SYNCH_MUTEX, ace_mon, this->lock_, -1));
    if (this->result_queue_.enqueue_tail (result) == -1)
      {
        ACE_ERROR ((LM_ERROR,
                    ACE_TEXT ("ACE_POSIX_Asynch_Accept::accept: %p\n")
                    ACE_TEXT ("enqueue_tail")));
        delete result;  // to avoid memory  leak
        return -1;
      }
    if (this->result_queue_.size () > 1)
      return 0;
  }
  // If this is the only item, then it means there the set was empty
  // before. So enable the accept handle in the reactor.
  ACE_Asynch_Pseudo_Task & task =
    this->posix_proactor ()->get_asynch_pseudo_task ();
  return task.resume_io_handler (this->get_handle ());
}
//@@ New method cancel_uncompleted
// It performs cancellation of all pending requests
//
// Parameter flg_notify can be
//     0  - don't send notifications about canceled accepts
//    !0  - notify user about canceled accepts
//          according POSIX standards we should receive notifications
//          on canceled AIO requests
//
//  Return value : number of cancelled requests
//
int
ACE_POSIX_Asynch_Accept::cancel_uncompleted (int flg_notify)
{
  ACE_TRACE ("ACE_POSIX_Asynch_Accept::cancel_uncompleted");
  int retval = 0;
  for (; ; retval++)
    {
      ACE_POSIX_Asynch_Accept_Result* result = 0;
      this->result_queue_.dequeue_head (result);
      if (result == 0)
        break;
      if (this->flg_open_ == 0 || flg_notify == 0) //if we should not notify
        delete result ;                            // we have to delete result
      else                                 //else notify as any cancelled AIO
        {
          // Store the new handle.
          result->aio_fildes = ACE_INVALID_HANDLE ;
          result->set_bytes_transferred (0);
          result->set_error (ECANCELED);
          if (this->posix_proactor ()->post_completion (result) == -1)
            ACE_ERROR ((LM_ERROR,
                        ACE_TEXT("(%P | %t):%p\n"),
                        ACE_TEXT("ACE_POSIX_Asynch_Accept::")
                        ACE_TEXT("cancel_uncompleted")
                        ));
        }
    }
  return retval;
}
int
ACE_POSIX_Asynch_Accept::cancel (void)
{
  ACE_TRACE ("ACE_POSIX_Asynch_Accept::cancel");
  // Since this is not a real POSIX asynch I/O operation, we can't
  // call ::aiocancel () or ACE_POSIX_Asynch_Operation::cancel ().
  // We delegate real cancelation to cancel_uncompleted (1)
  int rc = -1 ;  // ERRORS
  {
    ACE_MT (ACE_GUARD_RETURN (ACE_SYNCH_MUTEX, ace_mon, this->lock_, -1));
    int num_cancelled = cancel_uncompleted (flg_open_);
    if (num_cancelled == 0)
      rc = 1 ;        // AIO_ALLDONE
    else if (num_cancelled > 0)
      rc = 0 ;        // AIO_CANCELED
    if (!this->flg_open_)
      return rc ;
  }
  ACE_Asynch_Pseudo_Task & task =
    this->posix_proactor ()->get_asynch_pseudo_task ();
  task.suspend_io_handler (this->get_handle());
  return 0;
}
int
ACE_POSIX_Asynch_Accept::close ()
{
  ACE_TRACE ("ACE_POSIX_Asynch_Accept::close");
  // 1. It performs cancellation of all pending requests
  // 2. Removes itself from Reactor ( ACE_Asynch_Pseudo_Task)
  // 3. close the socket
  //
  //  Parameter flg_notify can be
  //     0  - don't send notifications about canceled accepts
  //    !0  - notify user about canceled accepts
  //          according POSIX standards we should receive notifications
  //          on canceled AIO requests
  //
  //  Return codes : 0 - OK ,
  //                -1 - Errors
  {
    ACE_MT (ACE_GUARD_RETURN (ACE_SYNCH_MUTEX, ace_mon, this->lock_, -1));
    this->cancel_uncompleted (flg_open_);
  }
  if (!this->flg_open_)
    {
      if (this->handle_ != ACE_INVALID_HANDLE)
        {
          ACE_OS::closesocket (this->handle_);
          this->handle_ = ACE_INVALID_HANDLE;
        }
      return 0;
    }
  if (this->handle_ == ACE_INVALID_HANDLE)
    return 0;
  ACE_Asynch_Pseudo_Task & task =
    this->posix_proactor ()->get_asynch_pseudo_task ();
  task.remove_io_handler (this->get_handle ());
  if (this->handle_ != ACE_INVALID_HANDLE)
    {
      ACE_OS::closesocket (this->handle_);
      this->handle_ = ACE_INVALID_HANDLE;
    }
  this->flg_open_ = false;
  return 0;
}
int
ACE_POSIX_Asynch_Accept::handle_close (ACE_HANDLE, ACE_Reactor_Mask)
{
  ACE_TRACE ("ACE_POSIX_Asynch_Accept::handle_close");
  ACE_MT (ACE_GUARD_RETURN (ACE_SYNCH_MUTEX, ace_mon, this->lock_, 0));
  // handle_close is called in two cases:
  //  1. Pseudo task is closing (i.e. proactor destructor)
  //  2. The listen handle is closed (we don't have exclusive access to this)
  this->cancel_uncompleted (0);
  this->flg_open_ = false;
  this->handle_ = ACE_INVALID_HANDLE;
  return 0;
}
int
ACE_POSIX_Asynch_Accept::handle_input (ACE_HANDLE /* fd */)
{
  ACE_TRACE ("ACE_POSIX_Asynch_Accept::handle_input");
  // An <accept> has been sensed on the <listen_handle>. We should be
  // able to just go ahead and do the <accept> now on this <fd>. This
  // should be the same as the <listen_handle>.
  ACE_POSIX_Asynch_Accept_Result* result = 0;
  {
    ACE_MT (ACE_GUARD_RETURN (ACE_SYNCH_MUTEX, ace_mon, this->lock_, 0));
    // Deregister this info pertaining to this accept call.
    if (this->result_queue_.dequeue_head (result) != 0)
      ACE_ERROR ((LM_ERROR,
                  ACE_TEXT("%N:%l:(%P | %t):%p\n"),
                  ACE_TEXT("ACE_POSIX_Asynch_Accept::handle_input:")
                  ACE_TEXT( " dequeueing failed")));
    // Disable the handle in the reactor if no more accepts are pending.
    if (this->result_queue_.size () == 0)
      {
        ACE_Asynch_Pseudo_Task & task =
          this->posix_proactor ()->get_asynch_pseudo_task ();
        task.suspend_io_handler (this->get_handle());
      }
  }
  // Issue <accept> now.
  // @@ We shouldnt block here since we have already done poll/select
  // thru reactor. But are we sure?
  ACE_HANDLE new_handle = ACE_OS::accept (this->handle_, 0, 0);
  if (result == 0) // there is nobody to notify
    {
      ACE_OS::closesocket (new_handle);
      return 0;
    }
  if (new_handle == ACE_INVALID_HANDLE)
    {
      result->set_error (errno);
      ACE_ERROR ((LM_ERROR,
                  ACE_TEXT("%N:%l:(%P | %t):%p\n"),
                  ACE_TEXT("ACE_POSIX_Asynch_Accept::handle_input: ")
                  ACE_TEXT("accept")));
      // Notify client as usual, "AIO" finished with errors
    }
  // Store the new handle.
  result->aio_fildes = new_handle;
  // Notify the main process about this completion
  // Send the Result through the notification pipe.
  if (this->posix_proactor ()->post_completion (result) == -1)
    ACE_ERROR ((LM_ERROR,
                ACE_TEXT("Error:(%P | %t):%p\n"),
                ACE_TEXT("ACE_POSIX_Asynch_Accept::handle_input: ")
                ACE_TEXT(" <post_completion> failed")));
  return 0;
}
// *********************************************************************
ACE_HANDLE
ACE_POSIX_Asynch_Connect_Result::connect_handle (void) const
{
  return this->aio_fildes;
}
void ACE_POSIX_Asynch_Connect_Result::connect_handle (ACE_HANDLE handle)
{
  this->aio_fildes = handle;
}

ACE_POSIX_Asynch_Connect_Result::ACE_POSIX_Asynch_Connect_Result
  (const ACE_Handler::Proxy_Ptr &handler_proxy,
   ACE_HANDLE connect_handle,
   const void* act,
   ACE_HANDLE event,
   int priority,
   int signal_number)
  : ACE_POSIX_Asynch_Result
      (handler_proxy, act, event, 0, 0, priority, signal_number)
{
  this->aio_fildes = connect_handle;
  this->aio_nbytes = 0;
}
void
ACE_POSIX_Asynch_Connect_Result::complete (size_t bytes_transferred,
                                           int success,
                                           const void *completion_key,
                                           u_long error)
{
  // Copy the data.
  this->bytes_transferred_ = bytes_transferred;
  this->success_ = success;
  this->completion_key_ = completion_key;
  this->error_ = error;
  // Create the interface result class.
  ACE_Asynch_Connect::Result result (this);
  // Call the application handler.
  ACE_Handler *handler = this->handler_proxy_.get ()->handler ();
  if (handler != 0)
    handler->handle_connect (result);
}
ACE_POSIX_Asynch_Connect_Result::~ACE_POSIX_Asynch_Connect_Result (void)
{
}
// *********************************************************************
ACE_POSIX_Asynch_Connect::ACE_POSIX_Asynch_Connect (ACE_POSIX_Proactor * posix_proactor)
  : ACE_POSIX_Asynch_Operation (posix_proactor),
    flg_open_ (false)
{
}
ACE_POSIX_Asynch_Connect::~ACE_POSIX_Asynch_Connect (void)
{
  this->close ();
  this->reactor(0); // to avoid purge_pending_notifications
}
ACE_HANDLE
ACE_POSIX_Asynch_Connect::get_handle (void) const
{
  ACE_ASSERT (0);
  return  ACE_INVALID_HANDLE;
}
void
ACE_POSIX_Asynch_Connect::set_handle (ACE_HANDLE)
{
  ACE_ASSERT (0) ;
}
int
ACE_POSIX_Asynch_Connect::open (const ACE_Handler::Proxy_Ptr &handler_proxy,
                                ACE_HANDLE handle,
                                const void *completion_key,
                                ACE_Proactor *proactor)
{
  ACE_TRACE ("ACE_POSIX_Asynch_Connect::open");
  if (this->flg_open_)
    return -1;
  //int result =
  ACE_POSIX_Asynch_Operation::open (handler_proxy,
                                    handle,
                                    completion_key,
                                    proactor);
  // Ignore result as we pass ACE_INVALID_HANDLE
  //if (result == -1)
  //  return result;
  this->flg_open_ = true;
  return 0;
}
int
ACE_POSIX_Asynch_Connect::connect (ACE_HANDLE connect_handle,
                                   const ACE_Addr & remote_sap,
                                   const ACE_Addr & local_sap,
                                   int reuse_addr,
                                   const void *act,
                                   int priority,
                                   int signal_number)
{
  ACE_TRACE ("ACE_POSIX_Asynch_Connect::connect");
  if (this->flg_open_ == 0)
    ACE_ERROR_RETURN ((LM_ERROR,
                       ACE_TEXT("%N:%l:ACE_POSIX_Asynch_Connect::connect")
                       ACE_TEXT("connector was not opened before\n")),
                      -1);
  // Common code for both WIN and POSIX.
  // Create future Asynch_Connect_Result
  ACE_POSIX_Asynch_Connect_Result *result = 0;
  ACE_NEW_RETURN (result,
                  ACE_POSIX_Asynch_Connect_Result (this->handler_proxy_,
                                                   connect_handle,
                                                   act,
                                                   this->posix_proactor ()->get_handle (),
                                                   priority,
                                                   signal_number),
                  -1);
  int rc = connect_i (result,
                      remote_sap,
                      local_sap,
                      reuse_addr);
  // update handle
  connect_handle = result->connect_handle ();
  if (rc != 0)
    return post_result (result, true);
  //  Enqueue result we will wait for completion
  {
    ACE_MT (ACE_GUARD_RETURN (ACE_SYNCH_MUTEX, ace_mon, this->lock_, -1));
    if (this->result_map_.bind (connect_handle, result) == -1)
      {
        ACE_ERROR  ((LM_ERROR,
                     ACE_TEXT ("%N:%l:%p\n"),
                     ACE_TEXT ("ACE_POSIX_Asynch_Connect::connect:")
                     ACE_TEXT ("bind")));
        result->set_error (EFAULT);
        return post_result (result, true);
      }
  }
  ACE_Asynch_Pseudo_Task & task =
    this->posix_proactor ()->get_asynch_pseudo_task ();
  rc = task.register_io_handler (connect_handle,
                                 this,
                                 ACE_Event_Handler::CONNECT_MASK,
                                 0);  // don't suspend after register
  if (rc < 0)
    {
      {
        ACE_MT (ACE_GUARD_RETURN (ACE_SYNCH_MUTEX, ace_mon, this->lock_, -1));
        this->result_map_.unbind (connect_handle, result);
      }
      if (result != 0)
        {
          result->set_error (EFAULT);
          this->post_result (result, true);
        }
      return -1;
    }
  else
    result = 0;

  return 0;
}
int ACE_POSIX_Asynch_Connect::post_result (ACE_POSIX_Asynch_Connect_Result * result,
                                           bool post_enable)
{
  if (this->flg_open_ && post_enable != 0)
    {
      if (this->posix_proactor ()->post_completion (result) == 0)
        return 0;
      ACE_ERROR ((LM_ERROR,
                  ACE_TEXT("Error:(%P | %t):%p\n"),
                  ACE_TEXT("ACE_POSIX_Asynch_Connect::post_result: ")
                  ACE_TEXT(" <post_completion> failed")));
    }
  ACE_HANDLE handle = result->connect_handle ();
  if (handle != ACE_INVALID_HANDLE)
    ACE_OS::closesocket (handle);
   delete result;
   return -1;
}
//connect_i
//  return code :
//   -1   errors  before  attempt to connect
//    0   connect started
//    1   connect finished ( may be unsuccessfully)
int
ACE_POSIX_Asynch_Connect::connect_i (ACE_POSIX_Asynch_Connect_Result *result,
                                     const ACE_Addr & remote_sap,
                                     const ACE_Addr & local_sap,
                                     int  reuse_addr)
{
  result->set_bytes_transferred (0);
  ACE_HANDLE handle = result->connect_handle ();
  if (handle == ACE_INVALID_HANDLE)
    {
      int protocol_family = remote_sap.get_type ();
      handle = ACE_OS::socket (protocol_family,
                               SOCK_STREAM,
                               0);
      // save it
      result->connect_handle (handle);
      if (handle == ACE_INVALID_HANDLE)
        {
          result->set_error (errno);
          ACE_ERROR_RETURN
            ((LM_ERROR,
              ACE_TEXT("ACE_POSIX_Asynch_Connect::connect_i: %p\n"),
              ACE_TEXT("socket")),
             -1);
        }
      // Reuse the address
      int one = 1;
      if (protocol_family != PF_UNIX &&
          reuse_addr != 0 &&
          ACE_OS::setsockopt (handle,
                              SOL_SOCKET,
                              SO_REUSEADDR,
                              (const char*) &one,
                              sizeof one) == -1 )
        {
          result->set_error (errno);
          ACE_ERROR_RETURN
            ((LM_ERROR,
              ACE_TEXT("ACE_POSIX_Asynch_Connect::connect_i: %p\n"),
              ACE_TEXT("setsockopt")),
             -1);
        }
    }
  if (local_sap != ACE_Addr::sap_any)
    {
      sockaddr * laddr = reinterpret_cast<sockaddr *> (local_sap.get_addr ());
      size_t size = local_sap.get_size ();
      if (ACE_OS::bind (handle, laddr, size) == -1)
        {
           result->set_error (errno);
           ACE_ERROR_RETURN
             ((LM_ERROR,
               ACE_TEXT("ACE_POSIX_Asynch_Connect::connect_i: %p\n"),
               ACE_TEXT("bind")),
              -1);
        }
    }
  // set non blocking mode
  if (ACE::set_flags (handle, ACE_NONBLOCK) != 0)
    {
      result->set_error (errno);
      ACE_ERROR_RETURN
        ((LM_ERROR,
          ACE_TEXT("ACE_POSIX_Asynch_Connect::connect_i: %p\n")
          ACE_TEXT("set_flags")),
         -1);
    }
  for (;;)
    {
      int rc = ACE_OS::connect
        (handle,
         reinterpret_cast<sockaddr *> (remote_sap.get_addr ()),
         remote_sap.get_size ());
      if (rc < 0)  // failure
        {
          if (errno == EWOULDBLOCK || errno == EINPROGRESS)
            return 0; // connect started
          if (errno == EINTR)
             continue;
          result->set_error (errno);
        }
      return 1 ;  // connect finished
    }
  ACE_NOTREACHED (return 0);
}

//@@ New method cancel_uncompleted
// It performs cancellation of all pending requests
//
// Parameter flg_notify can be
//     0  - don't send notifications about canceled accepts
//    !0  - notify user about canceled accepts
//          according POSIX standards we should receive notifications
//          on canceled AIO requests
//
//  Return value : number of cancelled requests
//
int
ACE_POSIX_Asynch_Connect::cancel_uncompleted (bool flg_notify,
                                              ACE_Handle_Set & set)
{
  ACE_TRACE ("ACE_POSIX_Asynch_Connect::cancel_uncompleted");
  int retval = 0;
  MAP_MANAGER::ITERATOR  iter (result_map_);
  MAP_MANAGER::ENTRY *   me = 0;
  set.reset ();
  for (; iter.next (me) != 0;  retval++ , iter.advance ())
    {
       ACE_HANDLE handle = me->ext_id_;
       ACE_POSIX_Asynch_Connect_Result* result = me->int_id_ ;
       set.set_bit (handle);
       result->set_bytes_transferred (0);
       result->set_error (ECANCELED);
       this->post_result (result, flg_notify);
    }
  result_map_.unbind_all ();
  return retval;
}
int
ACE_POSIX_Asynch_Connect::cancel (void)
{
  ACE_TRACE ("ACE_POSIX_Asynch_Connect::cancel");
  // Since this is not a real asynch I/O operation, we can't just call
  // ::aiocancel () or ACE_POSIX_Asynch_Operation::cancel ().
  // Delegate real cancelation to cancel_uncompleted (1)
  int rc = -1 ;  // ERRORS
  ACE_Handle_Set set;
  int num_cancelled = 0;
  {
    ACE_MT (ACE_GUARD_RETURN (ACE_SYNCH_MUTEX, ace_mon, this->lock_, -1));
    num_cancelled = cancel_uncompleted (flg_open_, set);
  }
  if (num_cancelled == 0)
    rc = 1 ;        // AIO_ALLDONE
  else if (num_cancelled > 0)
    rc = 0 ;        // AIO_CANCELED
  if (!this->flg_open_)
    return rc ;
  ACE_Asynch_Pseudo_Task & task =
    this->posix_proactor ()->get_asynch_pseudo_task ();
  task.remove_io_handler (set);
  return rc;
}
int
ACE_POSIX_Asynch_Connect::close (void)
{
  ACE_TRACE ("ACE_POSIX_Asynch_Connect::close");
  ACE_Handle_Set set ;
  int num_cancelled = 0;
  {
    ACE_MT (ACE_GUARD_RETURN (ACE_SYNCH_MUTEX, ace_mon, this->lock_, -1));
    num_cancelled = cancel_uncompleted (flg_open_, set);
  }
  if (num_cancelled == 0 || !this->flg_open_)
    {
      this->flg_open_ = false;
      return 0;
    }
  ACE_Asynch_Pseudo_Task & task =
    this->posix_proactor ()->get_asynch_pseudo_task ();
  task.remove_io_handler (set);
  this->flg_open_ = false;
  return 0;
}
int
ACE_POSIX_Asynch_Connect::handle_output (ACE_HANDLE fd)
{
  ACE_TRACE ("ACE_POSIX_Asynch_Connect::handle_output");
  ACE_POSIX_Asynch_Connect_Result* result = 0;
  {
    ACE_MT (ACE_GUARD_RETURN (ACE_SYNCH_MUTEX, ace_mon, this->lock_, 0));
    if (this->result_map_.unbind (fd, result) != 0) // not found
      return -1;
  }
  int sockerror  = 0 ;
  int lsockerror = sizeof sockerror;
  ACE_OS::getsockopt (fd,
                      SOL_SOCKET,
                      SO_ERROR,
                      (char*) &sockerror,
                      &lsockerror);
  result->set_bytes_transferred (0);
  result->set_error (sockerror);
  // This previously just did a "return -1" and let handle_close() clean
  // things up. However, this entire object may be gone as a result of
  // the application's completion handler, so don't count on 'this' being
  // legitimate on return from post_result().
  // remove_io_handler() contains flag DONT_CALL
  this->posix_proactor ()->get_asynch_pseudo_task ().remove_io_handler (fd);
  this->post_result (result, this->flg_open_);
  return 0;
}

int
ACE_POSIX_Asynch_Connect::handle_close (ACE_HANDLE fd, ACE_Reactor_Mask)
{
  ACE_TRACE ("ACE_POSIX_Asynch_Connect::handle_close");
  ACE_Asynch_Pseudo_Task &task =
         this->posix_proactor ()->get_asynch_pseudo_task ();
  task.remove_io_handler (fd);
  ACE_POSIX_Asynch_Connect_Result* result = 0;
  {
    ACE_MT (ACE_GUARD_RETURN (ACE_SYNCH_MUTEX, ace_mon, this->lock_, 0));
    if (this->result_map_.unbind (fd, result) != 0) // not found
      return -1;
  }
  result->set_bytes_transferred (0);
  result->set_error (ECANCELED);
  this->post_result (result, this->flg_open_);
  return 0;
}
// *********************************************************************
ACE_HANDLE
ACE_POSIX_Asynch_Transmit_File_Result::socket (void) const
{
  return this->socket_;
}
ACE_HANDLE
ACE_POSIX_Asynch_Transmit_File_Result::file (void) const
{
  return this->aio_fildes;
}
ACE_Asynch_Transmit_File::Header_And_Trailer *
ACE_POSIX_Asynch_Transmit_File_Result::header_and_trailer (void) const
{
  return this->header_and_trailer_;
}
size_t
ACE_POSIX_Asynch_Transmit_File_Result::bytes_to_write (void) const
{
  return this->aio_nbytes;
}
size_t
ACE_POSIX_Asynch_Transmit_File_Result::bytes_per_send (void) const
{
  return this->bytes_per_send_;
}
u_long
ACE_POSIX_Asynch_Transmit_File_Result::flags (void) const
{
  return this->flags_;
}
ACE_POSIX_Asynch_Transmit_File_Result::ACE_POSIX_Asynch_Transmit_File_Result
  (const ACE_Handler::Proxy_Ptr &handler_proxy,
   ACE_HANDLE socket,
   ACE_HANDLE file,
   ACE_Asynch_Transmit_File::Header_And_Trailer *header_and_trailer,
   size_t bytes_to_write,
   u_long offset,
   u_long offset_high,
   size_t bytes_per_send,
   u_long flags,
   const void *act,
   ACE_HANDLE event,
   int priority,
   int signal_number)
  : ACE_POSIX_Asynch_Result
     (handler_proxy, act, event, offset, offset_high, priority, signal_number),
    socket_ (socket),
    header_and_trailer_ (header_and_trailer),
    bytes_per_send_ (bytes_per_send),
    flags_ (flags)
{
  this->aio_fildes = file;
  this->aio_nbytes = bytes_to_write;
}
void
ACE_POSIX_Asynch_Transmit_File_Result::complete (size_t bytes_transferred,
                                                 int success,
                                                 const void *completion_key,
                                                 u_long error)
{
  // Copy the data.
  this->bytes_transferred_ = bytes_transferred;
  this->success_ = success;
  this->completion_key_ = completion_key;
  this->error_ = error;
  // We will not do this because (a) the header and trailer blocks may
  // be the same message_blocks and (b) in cases of failures we have
  // no idea how much of what (header, data, trailer) was sent.
  /*
    if (this->success_ && this->header_and_trailer_ != 0)
    {
    ACE_Message_Block *header = this->header_and_trailer_->header ();
    if (header != 0)
    header->rd_ptr (this->header_and_trailer_->header_bytes ());
    ACE_Message_Block *trailer = this->header_and_trailer_->trailer ();
    if (trailer != 0)
    trailer->rd_ptr (this->header_and_trailer_->trailer_bytes ());
    }
  */
  // Create the interface result class.
  ACE_Asynch_Transmit_File::Result result (this);
  // Call the application handler.
  ACE_Handler *handler = this->handler_proxy_.get ()->handler ();
  if (handler != 0)
    handler->handle_transmit_file (result);
}
ACE_POSIX_Asynch_Transmit_File_Result::~ACE_POSIX_Asynch_Transmit_File_Result (void)
{
}

// *********************************************************************
/**
 * @class ACE_POSIX_Asynch_Transmit_Handler
 *
 * @brief Auxillary handler for doing <Asynch_Transmit_File> in
 * Unix. <ACE_POSIX_Asynch_Transmit_File> internally uses this.
 *
 * This is a helper class for implementing
 * <ACE_POSIX_Asynch_Transmit_File> in Unix systems.
 */
class ACE_Export ACE_POSIX_Asynch_Transmit_Handler : public ACE_Handler
{
public:
  /// Constructor. Result pointer will have all the information to do
  /// the file transmission (socket, file, application handler, bytes
  /// to write).
  ACE_POSIX_Asynch_Transmit_Handler (ACE_POSIX_Proactor *posix_proactor,
                                     ACE_POSIX_Asynch_Transmit_File_Result *result);
  /// Destructor.
  virtual ~ACE_POSIX_Asynch_Transmit_Handler (void);
  /// Do the transmission. All the info to do the transmission is in
  /// the <result> member.
  int transmit (void);
protected:
  /// The asynch result pointer made from the initial transmit file
  /// request.
  ACE_POSIX_Asynch_Transmit_File_Result *result_;
  /// Message bloack used to do the transmission.
  ACE_Message_Block *mb_;
  enum ACT
  {
    HEADER_ACT  = 1,
    DATA_ACT    = 2,
    TRAILER_ACT = 3
  };
  /// ACT to transmit header.
  ACT header_act_;
  /// ACT to transmit data.
  ACT data_act_;
  /// ACT to transmit trailer.
  ACT trailer_act_;
  /// Current offset of the file being transmitted.
  size_t file_offset_;
  /// Total size of the file.
  size_t file_size_;
  /// Number of bytes transferred on the stream.
  size_t bytes_transferred_;
  /// This is called when asynchronous writes from the socket complete.
  virtual void handle_write_stream (const ACE_Asynch_Write_Stream::Result &result);
  /// This is called when asynchronous reads from the file complete.
  virtual void handle_read_file (const ACE_Asynch_Read_File::Result &result);
  /// Issue asynch read from  the file.
  int initiate_read_file (void);
  /// To read from the file to be transmitted.
  ACE_POSIX_Asynch_Read_File rf_;
  /// Write stream to write the header, trailer and the data.
  ACE_POSIX_Asynch_Write_Stream ws_;
};
// ************************************************************
// Constructor.
ACE_POSIX_Asynch_Transmit_Handler::ACE_POSIX_Asynch_Transmit_Handler
      (ACE_POSIX_Proactor *posix_proactor,
       ACE_POSIX_Asynch_Transmit_File_Result *result)
  : result_ (result),
    mb_ (0),
    header_act_ (this->HEADER_ACT),
    data_act_ (this->DATA_ACT),
    trailer_act_ (this->TRAILER_ACT),
    file_offset_ (result->offset ()),
    file_size_ (0),
    bytes_transferred_ (0),
    rf_ (posix_proactor),
    ws_ (posix_proactor)
{
  // Allocate memory for the message block.
  ACE_NEW (this->mb_,
           ACE_Message_Block (this->result_->bytes_per_send ()
                              + 1));
  // Init the file size.
  file_size_ = ACE_OS::filesize (this->result_->file ());
}
// Destructor.
ACE_POSIX_Asynch_Transmit_Handler::~ACE_POSIX_Asynch_Transmit_Handler (void)
{
  delete result_;
  mb_->release ();
}

// Do the transmission.
// Initiate transmitting the header. When that completes
// handle_write_stream will be called, there start transmitting the file.
int
ACE_POSIX_Asynch_Transmit_Handler::transmit (void)
{
  // No proactor is given for the <open>'s. Because we are using the
  // concrete implementations of the  Asynch_Operations, and we have
  // already given them the specific proactor, so they wont need the
  // general <proactor> interface pointer.
  // Open Asynch_Read_File.
  if (this->rf_.open (this->proxy (),
                      this->result_->file (),
                      0,
                      0) == -1)
    ACE_ERROR_RETURN ((LM_ERROR,
                       "ACE_Asynch_Transmit_Handler:read_file open failed\n"),
                      -1);
  // Open Asynch_Write_Stream.
  if (this->ws_.open (this->proxy (),
                      this->result_->socket (),
                      0,
                      0) == -1)
    ACE_ERROR_RETURN ((LM_ERROR,
                       "ACE_Asynch_Transmit_Handler:write_stream open failed\n"),
                      -1);
  // Transmit the header.
  if (this->ws_.write (*this->result_->header_and_trailer ()->header (),
                       this->result_->header_and_trailer ()->header_bytes (),
                       reinterpret_cast<void *> (&this->header_act_),
                       0) == -1)
    ACE_ERROR_RETURN ((LM_ERROR,
                       "Asynch_Transmit_Handler:transmitting header:write_stream failed\n"),
                      -1);
  return 0;
}
void
ACE_POSIX_Asynch_Transmit_Handler::handle_write_stream (const ACE_Asynch_Write_Stream::Result &result)
{
  // Update bytes transferred so far.
  this->bytes_transferred_ += result.bytes_transferred ();
  // Check the success parameter.
  if (result.success () == 0)
    {
      // Failure.
      ACE_ERROR ((LM_ERROR,
                  "Asynch_Transmit_File failed.\n"));
      ACE_SEH_TRY
        {
          this->result_->complete (this->bytes_transferred_,
                                   0,      // Failure.
                                   0,      // @@ Completion key.
                                   0);     // @@ Error no.
        }
      ACE_SEH_FINALLY
        {
          // This is crucial to prevent memory leaks. This deletes
          // the result pointer also.
          delete this;
        }
    }
  // Write stream successful.
  // Partial write to socket.
  size_t unsent_data = result.bytes_to_write () - result.bytes_transferred ();
  if (unsent_data != 0)
    {
      ACE_DEBUG ((LM_DEBUG,
                  "%N:%l:Partial write to socket: Asynch_write called again\n"));
      // Duplicate the message block and retry remaining data
      if (this->ws_.write (*result.message_block ().duplicate (),
                           unsent_data,
                           result.act (),
                           this->result_->priority (),
                           this->result_->signal_number ()) == -1)
        {
          // @@ Handle this error.
          ACE_ERROR ((LM_ERROR,
                      "Asynch_Transmit_Handler:write_stream failed\n"));
          return;
        }
      // @@ Handling *partial write* to a socket.  Let us not continue
      // further before this write finishes. Because proceeding with
      // another read and then write might change the order of the
      // file transmission, because partial write to the stream is
      // always possible.
      return;
    }
  // Not a partial write. A full write.
  // Check ACT to see what was sent.
  ACT act = * (ACT *) result.act ();
  switch (act)
    {
    case TRAILER_ACT:
      // If it is the "trailer" that is just sent, then transmit file
      // is complete.
      // Call the application handler.
      ACE_SEH_TRY
        {
          this->result_->complete (this->bytes_transferred_,
                                   1,      // @@ Success.
                                   0,      // @@ Completion key.
                                   0);     // @@ Errno.
        }
      ACE_SEH_FINALLY
        {
          delete this;
        }
      break;
    case HEADER_ACT:
    case DATA_ACT:
      // If header/data was sent, initiate the file data transmission.
      if (this->initiate_read_file () == -1)
        // @@ Handle this error.
        ACE_ERROR ((LM_ERROR,
                    "Error:Asynch_Transmit_Handler:read_file couldnt be initiated\n"));
      break;
    default:
      // @@ Handle this error.
      ACE_ERROR ((LM_ERROR,
                  "Error:ACE_Asynch_Transmit_Handler::handle_write_stream::Unexpected act\n"));
    }
}
void
ACE_POSIX_Asynch_Transmit_Handler::handle_read_file (const ACE_Asynch_Read_File::Result &result)
{
  // Failure.
  if (result.success () == 0)
    {
      //
      ACE_SEH_TRY
        {
          this->result_->complete (this->bytes_transferred_,
                                   0,      // Failure.
                                   0,      // @@ Completion key.
                                   errno); // Error no.
        }
      ACE_SEH_FINALLY
        {
          delete this;
        }
      return;
    }
  // Read successful.
  if (result.bytes_transferred () == 0)
    return;
  // Increment offset.
  this->file_offset_ += result.bytes_transferred ();
  // Write data to network.
  if (this->ws_.write (result.message_block (),
                       result.bytes_transferred (),
                       (void *)&this->data_act_,
                       this->result_->priority (),
                       this->result_->signal_number ()) == -1)
    {
      // @@ Handle this error.
      ACE_ERROR ((LM_ERROR,
                  "Error:ACE_Asynch_Transmit_File : write to the stream failed\n"));
      return;
    }
}
int
ACE_POSIX_Asynch_Transmit_Handler::initiate_read_file (void)
{
  // Is there something to read.
  if (this->file_offset_ >= this->file_size_)
    {
      // File is sent. Send the trailer.
      if (this->ws_.write (*this->result_->header_and_trailer ()->trailer (),
                           this->result_->header_and_trailer ()->trailer_bytes (),
                           (void *)&this->trailer_act_,
                           this->result_->priority (),
                           this->result_->signal_number ()) == -1)
        ACE_ERROR_RETURN ((LM_ERROR,
                           "Error:Asynch_Transmit_Handler:write_stream writing trailer failed\n"),
                          -1);
      return 0;
    }
  else
    {
      // @@ Is this right??
      // Previous reads and writes are over. For the new read, adjust
      // the wr_ptr and the rd_ptr to the beginning.
      this->mb_->rd_ptr (this->mb_->base ());
      this->mb_->wr_ptr (this->mb_->base ());
      // Inititiate an asynchronous read from the file.
      if (this->rf_.read (*this->mb_,
                          this->mb_->size () - 1,
                          this->file_offset_,
                          0, // @@ offset_high !!! if aiocb64 is used.
                          0, // Act
                          this->result_->priority (),
                          this->result_->signal_number ()) == -1)
        ACE_ERROR_RETURN ((LM_ERROR,
                           "Error:Asynch_Transmit_Handler::read from file failed\n"),
                          -1);
      return 0;
    }
}
// *********************************************************************
ACE_POSIX_Asynch_Transmit_File::ACE_POSIX_Asynch_Transmit_File (ACE_POSIX_Proactor *posix_proactor)
  : ACE_POSIX_Asynch_Operation (posix_proactor)
{
}
int
ACE_POSIX_Asynch_Transmit_File::transmit_file (ACE_HANDLE file,
                                               ACE_Asynch_Transmit_File::Header_And_Trailer *header_and_trailer,
                                               size_t bytes_to_write,
                                               u_long offset,
                                               u_long offset_high,
                                               size_t bytes_per_send,
                                               u_long flags,
                                               const void *act,
                                               int priority,
                                               int signal_number)
{
  // Adjust these parameters if there are default values specified.
  ssize_t file_size = ACE_OS::filesize (file);
  if (file_size == -1)
    ACE_ERROR_RETURN ((LM_ERROR,
                       "Error:%N:%l:%p\n",
                       "POSIX_Asynch_Transmit_File:filesize failed"),
                      -1);
  if (bytes_to_write == 0)
    bytes_to_write = file_size;
  if (offset > (size_t) file_size)
    ACE_ERROR_RETURN ((LM_ERROR,
                       "Error:%p\n",
                       "Asynch_Transmit_File:File size is less than offset"),
                      -1);
  if (offset != 0)
    bytes_to_write = file_size - offset + 1;
  if (bytes_per_send == 0)
    bytes_per_send = bytes_to_write;
  // Configure the result parameter.
  ACE_POSIX_Asynch_Transmit_File_Result *result = 0;
  ACE_NEW_RETURN (result,
                  ACE_POSIX_Asynch_Transmit_File_Result (this->handler_proxy_,
                                                         this->handle_,
                                                         file,
                                                         header_and_trailer,
                                                         bytes_to_write,
                                                         offset,
                                                         offset_high,
                                                         bytes_per_send,
                                                         flags,
                                                         act,
                                                         this->posix_proactor ()->get_handle (),
                                                         priority,
                                                         signal_number),
                  -1);
  // Make the auxillary handler and initiate transmit.
  ACE_POSIX_Asynch_Transmit_Handler *transmit_handler = 0;
  ACE_NEW_RETURN (transmit_handler,
                  ACE_POSIX_Asynch_Transmit_Handler (this->posix_proactor (),
                                                     result),
                  -1);
  ssize_t return_val = transmit_handler->transmit ();
  if (return_val == -1)
    // This deletes the <result> in it too.
    delete transmit_handler;
  return 0;
}
ACE_POSIX_Asynch_Transmit_File::~ACE_POSIX_Asynch_Transmit_File (void)
{
}
// *********************************************************************
size_t
ACE_POSIX_Asynch_Read_Dgram_Result::bytes_to_read (void) const
{
  return this->bytes_to_read_;
}
int
ACE_POSIX_Asynch_Read_Dgram_Result::remote_address (ACE_Addr& addr) const
{
  int retVal = -1;  // failure
  // make sure the addresses are of the same type
  if (addr.get_type () == this->remote_address_->get_type ())
  { // copy the remote_address_ into addr
    addr.set_addr (this->remote_address_->get_addr (),
                   this->remote_address_->get_size ());
    retVal = 0; // success
  }
  return retVal;
}
sockaddr *
ACE_POSIX_Asynch_Read_Dgram_Result::saddr () const
{
  return (sockaddr *) this->remote_address_->get_addr ();
}

int
ACE_POSIX_Asynch_Read_Dgram_Result::flags (void) const
{
  return this->flags_;
}
ACE_HANDLE
ACE_POSIX_Asynch_Read_Dgram_Result::handle (void) const
{
  return this->handle_;
}
ACE_Message_Block*
ACE_POSIX_Asynch_Read_Dgram_Result::message_block () const
{
  return this->message_block_;
}
ACE_POSIX_Asynch_Read_Dgram_Result::ACE_POSIX_Asynch_Read_Dgram_Result
  (const ACE_Handler::Proxy_Ptr &handler_proxy,
   ACE_HANDLE handle,
   ACE_Message_Block *message_block,
   size_t bytes_to_read,
   int flags,
   int protocol_family,
   const void* act,
   ACE_HANDLE event,
   int priority,
   int signal_number)
  : ACE_POSIX_Asynch_Result
      (handler_proxy, act, event, 0, 0, priority, signal_number),
    bytes_to_read_ (bytes_to_read),
    message_block_ (message_block),
    remote_address_ (0),
    addr_len_ (0),
    flags_ (flags),
    handle_ (handle)
{
  ACE_UNUSED_ARG (protocol_family);
  this->aio_fildes = handle;
  this->aio_buf = message_block->wr_ptr ();
  this->aio_nbytes = bytes_to_read;
  ACE_NEW (this->remote_address_, ACE_INET_Addr);
}
void
ACE_POSIX_Asynch_Read_Dgram_Result::complete (size_t bytes_transferred,
                                              int success,
                                              const void *completion_key,
                                              u_long error)
{
  // Copy the data which was returned by GetQueuedCompletionStatus
  this->bytes_transferred_ = bytes_transferred;
  this->success_ = success;
  this->completion_key_ = completion_key;
  this->error_ = error;
  // Appropriately move the pointers in the message block.
  this->message_block_->wr_ptr (bytes_transferred);
  // <errno> is available in the aiocb.
  ACE_UNUSED_ARG (error);
 this->remote_address_->set_size(this->addr_len_);
  // Create the interface result class.
  ACE_Asynch_Read_Dgram::Result result (this);
  // Call the application handler.
  ACE_Handler *handler = this->handler_proxy_.get ()->handler ();
  if (handler != 0)
    handler->handle_read_dgram (result);
}
ACE_POSIX_Asynch_Read_Dgram_Result::~ACE_POSIX_Asynch_Read_Dgram_Result (void)
{
  delete this->remote_address_;
}
//***************************************************************************
size_t
ACE_POSIX_Asynch_Write_Dgram_Result::bytes_to_write (void) const
{
  return this->bytes_to_write_;
}
int
ACE_POSIX_Asynch_Write_Dgram_Result::flags (void) const
{
  return this->flags_;
}
ACE_HANDLE
ACE_POSIX_Asynch_Write_Dgram_Result::handle (void) const
{
  return this->handle_;
}

ACE_Message_Block*
ACE_POSIX_Asynch_Write_Dgram_Result::message_block () const
{
  return this->message_block_;
}
ACE_POSIX_Asynch_Write_Dgram_Result::ACE_POSIX_Asynch_Write_Dgram_Result
  (const ACE_Handler::Proxy_Ptr &handler_proxy,
   ACE_HANDLE handle,
   ACE_Message_Block *message_block,
   size_t bytes_to_write,
   int flags,
   const void* act,
   ACE_HANDLE event,
   int priority,
   int signal_number)
  : ACE_POSIX_Asynch_Result
     (handler_proxy, act, event, 0, 0, priority, signal_number),
    bytes_to_write_ (bytes_to_write),
    message_block_ (message_block),
    flags_ (flags),
    handle_ (handle)
{
  this->aio_fildes = handle;
  this->aio_buf = message_block->rd_ptr ();
  this->aio_nbytes = bytes_to_write;
}
void
ACE_POSIX_Asynch_Write_Dgram_Result::complete (size_t bytes_transferred,
                                               int success,
                                               const void *completion_key,
                                               u_long error)
{
  // Copy the data which was returned by GetQueuedCompletionStatus
  this->bytes_transferred_ = bytes_transferred;
  this->success_ = success;
  this->completion_key_ = completion_key;
  this->error_ = error;
  // <errno> is available in the aiocb.
  ACE_UNUSED_ARG (error);
  // Appropriately move the pointers in the message block.
  this->message_block_->rd_ptr (bytes_transferred);
  // Create the interface result class.
  ACE_Asynch_Write_Dgram::Result result (this);
  // Call the application handler.
  ACE_Handler *handler = this->handler_proxy_.get ()->handler ();
  if (handler != 0)
    handler->handle_write_dgram (result);
}
ACE_POSIX_Asynch_Write_Dgram_Result::~ACE_POSIX_Asynch_Write_Dgram_Result (void)
{
}
/***************************************************************************/
ACE_POSIX_Asynch_Read_Dgram::~ACE_POSIX_Asynch_Read_Dgram (void)
{
}
ssize_t
ACE_POSIX_Asynch_Read_Dgram::recv (ACE_Message_Block *message_block,
                                   size_t & /*number_of_bytes_recvd*/,
                                   int flags,
                                   int protocol_family,
                                   const void *act,
                                   int priority,
                                   int signal_number)
{
  size_t space = message_block->space ();
  // Create the Asynch_Result.
  ACE_POSIX_Asynch_Read_Dgram_Result *result = 0;
  ACE_POSIX_Proactor *proactor = this->posix_proactor ();
  ACE_NEW_RETURN (result,
                  ACE_POSIX_Asynch_Read_Dgram_Result (this->handler_proxy_,
                                                      this->handle_,
                                                      message_block,
                                                      space,
                                                      flags,
                                                      protocol_family,
                                                      act,
                                                      proactor->get_handle (),
                                                      priority,
                                                      signal_number),
                  -1);
  int return_val = proactor->start_aio (result, ACE_POSIX_Proactor::ACE_OPCODE_READ);
  if (return_val == -1)
    delete result;
  return return_val;
}
ACE_POSIX_Asynch_Read_Dgram::ACE_POSIX_Asynch_Read_Dgram (ACE_POSIX_Proactor *posix_proactor)
  : ACE_POSIX_Asynch_Operation (posix_proactor)
{
}
//***************************************************************************
ACE_POSIX_Asynch_Write_Dgram::~ACE_POSIX_Asynch_Write_Dgram (void)
{
}
ssize_t
ACE_POSIX_Asynch_Write_Dgram::send (ACE_Message_Block *message_block,
                                    size_t &/*number_of_bytes_sent*/,
                                    int flags,
                                    const ACE_Addr &/*addr*/,
                                    const void *act,
                                    int priority,
                                    int signal_number)
{
  size_t len = message_block->length ();
  if (len == 0)
    ACE_ERROR_RETURN
      ((LM_ERROR,
        ACE_TEXT ("ACE_POSIX_Asynch_Write_Stream::write:")
        ACE_TEXT ("Attempt to write 0 bytes\n")),
      -1);
  ACE_POSIX_Asynch_Write_Dgram_Result *result = 0;
  ACE_POSIX_Proactor *proactor = this->posix_proactor ();
  ACE_NEW_RETURN (result,
                  ACE_POSIX_Asynch_Write_Dgram_Result (this->handler_proxy_,
                                                       this->handle_,
                                                       message_block,
                                                       len,
                                                       flags,
                                                       act,
                                                       proactor->get_handle (),
                                                       priority,
                                                       signal_number),
                  -1);
  int return_val = proactor->start_aio (result, ACE_POSIX_Proactor::ACE_OPCODE_WRITE);
  if (return_val == -1)
    delete result;
  return return_val;
}
ACE_POSIX_Asynch_Write_Dgram::ACE_POSIX_Asynch_Write_Dgram
  (ACE_POSIX_Proactor *posix_proactor)
  : ACE_POSIX_Asynch_Operation (posix_proactor)
{
}
ACE_END_VERSIONED_NAMESPACE_DECL
#endif /* ACE_HAS_AIO_CALLS */

