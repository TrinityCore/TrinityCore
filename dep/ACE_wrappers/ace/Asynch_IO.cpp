// $Id: Asynch_IO.cpp 82559 2008-08-07 20:23:07Z parsons $

#include "ace/Asynch_IO.h"

ACE_RCSID(ace, Asynch_IO, "$Id: Asynch_IO.cpp 82559 2008-08-07 20:23:07Z parsons $")

#if defined (ACE_HAS_WIN32_OVERLAPPED_IO) || defined (ACE_HAS_AIO_CALLS)
// This only works on platforms with Asynchronous IO

#include "ace/Proactor.h"
#include "ace/Message_Block.h"
#include "ace/INET_Addr.h"
#include "ace/Asynch_IO_Impl.h"
#include "ace/os_include/os_errno.h"
#include "ace/Truncate.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

size_t
ACE_Asynch_Result::bytes_transferred (void) const
{
  return this->implementation ()->bytes_transferred ();
}

const void *
ACE_Asynch_Result::act (void) const
{
  return this->implementation ()->act ();
}

int
ACE_Asynch_Result::success (void) const
{
  return this->implementation ()->success ();
}

const void *
ACE_Asynch_Result::completion_key (void) const
{
  return this->implementation ()->completion_key ();
}

unsigned long
ACE_Asynch_Result::error (void) const
{
  return this->implementation ()->error ();
}

ACE_HANDLE
ACE_Asynch_Result::event (void) const
{
  return this->implementation ()->event ();
}

unsigned long
ACE_Asynch_Result::offset (void) const
{
  return this->implementation ()->offset ();
}

unsigned long
ACE_Asynch_Result::offset_high (void) const
{
  return this->implementation ()->offset_high ();
}

int
ACE_Asynch_Result::priority (void) const
{
  return this->implementation ()->priority ();
}

int
ACE_Asynch_Result::signal_number (void) const
{
  return this->implementation ()->signal_number ();
}

ACE_Asynch_Result::ACE_Asynch_Result (ACE_Asynch_Result_Impl *implementation)
  : implementation_ (implementation)
{
}

ACE_Asynch_Result::~ACE_Asynch_Result (void)
{
  // Proactor deletes the implementation when the <complete> finishes.
}

ACE_Asynch_Result_Impl *
ACE_Asynch_Result::implementation (void) const
{
  return this->implementation_;
}

// *********************************************************************

int
ACE_Asynch_Operation::open (ACE_Handler &handler,
                            ACE_HANDLE handle,
                            const void *completion_key,
                            ACE_Proactor *proactor)
{
  return this->implementation ()->open (handler.proxy (),
                                        handle,
                                        completion_key,
                                        proactor);
}

int
ACE_Asynch_Operation::cancel (void)
{
  if (0 == this->implementation ())
    {
      errno = EFAULT;
      return -1;
    }
  return this->implementation ()->cancel ();
}

ACE_Proactor *
ACE_Asynch_Operation::proactor (void) const
{
  if (0 == this->implementation ())
    {
      errno = EFAULT;
      return 0;
    }
  return this->implementation ()->proactor ();
}

ACE_Asynch_Operation::ACE_Asynch_Operation (void)
{
}

ACE_Asynch_Operation::~ACE_Asynch_Operation (void)
{
}

ACE_Proactor *
ACE_Asynch_Operation::get_proactor (ACE_Proactor *user_proactor,
                                    ACE_Handler &handler) const
{
  if (user_proactor == 0)
    {
      // Grab the singleton proactor if <handler->proactor> is zero
      user_proactor = handler.proactor ();
      if (user_proactor == 0)
        user_proactor = ACE_Proactor::instance ();
    }

  return user_proactor;
}

// ************************************************************

ACE_Asynch_Read_Stream::ACE_Asynch_Read_Stream (void)
  : implementation_ (0)
{
}

ACE_Asynch_Read_Stream::~ACE_Asynch_Read_Stream (void)
{
  // Delete the implementation.
  delete this->implementation_;
  this->implementation_ = 0;
}

int
ACE_Asynch_Read_Stream::open (ACE_Handler &handler,
                              ACE_HANDLE handle,
                              const void *completion_key,
                              ACE_Proactor *proactor)
{
  // Get a proactor for/from the user.
  proactor = this->get_proactor (proactor, handler);

  // Now let us get the implementation initialized.
  if ((this->implementation_ = proactor->create_asynch_read_stream ()) == 0)
    return -1;

  // Call the <open> method of the base class.
  return ACE_Asynch_Operation::open (handler,
                                     handle,
                                     completion_key,
                                     proactor);
}

int
ACE_Asynch_Read_Stream::read (ACE_Message_Block &message_block,
                              size_t bytes_to_read,
                              const void *act,
                              int priority,
                              int signal_number)
{
  if (0 == this->implementation_)
    {
      errno = EFAULT;
      return -1;
    }
  return this->implementation_->read (message_block,
                                      bytes_to_read,
                                      act,
                                      priority,
                                      signal_number);
}

#if defined (ACE_HAS_WIN32_OVERLAPPED_IO)
int
ACE_Asynch_Read_Stream::readv (ACE_Message_Block &message_block,
                               size_t bytes_to_read,
                               const void *act,
                               int priority,
                               int signal_number)
{
  if (0 == this->implementation_)
    {
      errno = EFAULT;
      return -1;
    }
  return this->implementation_->readv (message_block,
                                       bytes_to_read,
                                       act,
                                       priority,
                                       signal_number);
}
#endif /* ACE_HAS_WIN32_OVERLAPPED_IO */

ACE_Asynch_Operation_Impl *
ACE_Asynch_Read_Stream::implementation (void) const
{
  return this->implementation_;
}

// ************************************************************

size_t
ACE_Asynch_Read_Stream::Result::bytes_to_read (void) const
{
  return this->implementation ()->bytes_to_read ();
}

ACE_Message_Block &
ACE_Asynch_Read_Stream::Result::message_block (void) const
{
  return this->implementation ()->message_block ();
}

ACE_HANDLE
ACE_Asynch_Read_Stream::Result::handle (void) const
{
  return this->implementation ()->handle ();
}

ACE_Asynch_Read_Stream::Result::Result (ACE_Asynch_Read_Stream_Result_Impl *implementation)
  : ACE_Asynch_Result (implementation),
    implementation_ (implementation)
{
}

ACE_Asynch_Read_Stream::Result::~Result (void)
{
  // Proactor will delete the implementation after <complete> is
  // finished.
}

ACE_Asynch_Read_Stream_Result_Impl *
ACE_Asynch_Read_Stream::Result::implementation (void) const
{
  return this->implementation_;
}

// ***************************************************

ACE_Asynch_Write_Stream::ACE_Asynch_Write_Stream (void)
  : implementation_ (0)
{
}

ACE_Asynch_Write_Stream::~ACE_Asynch_Write_Stream (void)
{
  // Delete the implementation.
  delete this->implementation_;
  this->implementation_ = 0;
}

int
ACE_Asynch_Write_Stream::open (ACE_Handler &handler,
                               ACE_HANDLE handle,
                               const void *completion_key,
                               ACE_Proactor *proactor)
{
  // Get a proactor for/from the user.
  proactor = this->get_proactor (proactor, handler);

  // Now let us get the implementation initialized.
  if ((this->implementation_ = proactor->create_asynch_write_stream ()) == 0)
    return -1;

  // Call the <open> method of the base class.
  return ACE_Asynch_Operation::open (handler,
                                     handle,
                                     completion_key,
                                     proactor);
}

int
ACE_Asynch_Write_Stream::write (ACE_Message_Block &message_block,
                                size_t bytes_to_write,
                                const void *act,
                                int priority,
                                int signal_number)
{
  if (0 == this->implementation_)
    {
      errno = EFAULT;
      return -1;
    }
  return this->implementation_->write (message_block,
                                       bytes_to_write,
                                       act,
                                       priority,
                                       signal_number);
}

#if defined (ACE_HAS_WIN32_OVERLAPPED_IO)
int
ACE_Asynch_Write_Stream::writev (ACE_Message_Block &message_block,
                                 size_t bytes_to_write,
                                 const void *act,
                                 int priority,
                                 int signal_number)
{
  if (0 == this->implementation_)
    {
      errno = EFAULT;
      return -1;
    }
  return this->implementation_->writev (message_block,
                                        bytes_to_write,
                                        act,
                                        priority,
                                        signal_number);
}
#endif /* ACE_HAS_WIN32_OVERLAPPED_IO */

ACE_Asynch_Operation_Impl *
ACE_Asynch_Write_Stream::implementation (void) const
{
  return this->implementation_;
}

// ************************************************************

size_t
ACE_Asynch_Write_Stream::Result::bytes_to_write (void) const
{
  return this->implementation ()->bytes_to_write ();
}

ACE_Message_Block &
ACE_Asynch_Write_Stream::Result::message_block (void) const
{
  return this->implementation ()->message_block ();
}

ACE_HANDLE
ACE_Asynch_Write_Stream::Result::handle (void) const
{
  return this->implementation ()->handle ();
}

ACE_Asynch_Write_Stream::Result::Result (ACE_Asynch_Write_Stream_Result_Impl *implementation)
  : ACE_Asynch_Result (implementation),
    implementation_ (implementation)
{
}

ACE_Asynch_Write_Stream::Result::~Result (void)
{
  // Proactor will delte the implementation when the <complete> call
  // finishes.
}

ACE_Asynch_Write_Stream_Result_Impl *
ACE_Asynch_Write_Stream::Result::implementation (void) const
{
  return this->implementation_;
}

// ************************************************************

ACE_Asynch_Read_File::ACE_Asynch_Read_File (void)
  : implementation_ (0)
{
}

ACE_Asynch_Read_File::~ACE_Asynch_Read_File (void)
{
  // Delete the implementation.
  delete this->implementation_;
  this->implementation_ = 0;
}

int
ACE_Asynch_Read_File::open (ACE_Handler &handler,
                            ACE_HANDLE handle,
                            const void *completion_key,
                            ACE_Proactor *proactor)
{
  // Get a proactor for/from the user.
  proactor = this->get_proactor (proactor, handler);

  // Now let us get the implementation initialized.
  if ((this->implementation_ = proactor->create_asynch_read_file ()) == 0)
    return -1;

  // Call the <open> method of the base class.
  return ACE_Asynch_Operation::open (handler,
                                     handle,
                                     completion_key,
                                     proactor);
}

int
ACE_Asynch_Read_File::read (ACE_Message_Block &message_block,
                            size_t bytes_to_read,
                            unsigned long offset,
                            unsigned long offset_high,
                            const void *act,
                            int priority,
                            int signal_number)
{
  if (0 == this->implementation_)
    {
      errno = EFAULT;
      return -1;
    }
  return this->implementation_->read (message_block,
                                      bytes_to_read,
                                      offset,
                                      offset_high,
                                      act,
                                      priority,
                                      signal_number);
}

#if (defined (ACE_WIN32) && !defined (ACE_HAS_WINCE))
int
ACE_Asynch_Read_File::readv (ACE_Message_Block &message_block,
                             size_t bytes_to_read,
                             unsigned long offset,
                             unsigned long offset_high,
                             const void *act,
                             int priority,
                             int signal_number)
{
  if (0 == this->implementation_)
    {
      errno = EFAULT;
      return -1;
    }
  return this->implementation_->readv (message_block,
                                       bytes_to_read,
                                       offset,
                                       offset_high,
                                       act,
                                       priority,
                                       signal_number);
}
#endif /* (defined (ACE_WIN32) && !defined (ACE_HAS_WINCE)) */

ACE_Asynch_Operation_Impl *
ACE_Asynch_Read_File::implementation (void) const
{
  return this->implementation_;
}

// ************************************************************

ACE_Asynch_Read_File::Result::Result (ACE_Asynch_Read_File_Result_Impl *implementation)
  : ACE_Asynch_Read_Stream::Result (implementation),
    implementation_ (implementation)
{
}

ACE_Asynch_Read_File::Result::~Result (void)
{
  // Proactor will delete the implementation when <complete> call
  // completes.
}

ACE_Asynch_Read_File_Result_Impl *
ACE_Asynch_Read_File::Result::implementation (void) const
{
  return this->implementation_;
}

// ************************************************************

ACE_Asynch_Write_File::ACE_Asynch_Write_File (void)
  : implementation_ (0)
{
}

ACE_Asynch_Write_File::~ACE_Asynch_Write_File (void)
{
  // Delete the implementation.
  delete this->implementation_;
  this->implementation_ = 0;
}

int
ACE_Asynch_Write_File::open (ACE_Handler &handler,
                             ACE_HANDLE handle,
                             const void *completion_key,
                             ACE_Proactor *proactor)
{
  // Get a proactor for/from the user.
  proactor = this->get_proactor (proactor, handler);

  // Now let us get the implementation initialized.
  if ((this->implementation_ = proactor->create_asynch_write_file ()) == 0)
    return -1;

  // Call the <open> method of the base class.
  return ACE_Asynch_Operation::open (handler,
                                     handle,
                                     completion_key,
                                     proactor);
}

int
ACE_Asynch_Write_File::write (ACE_Message_Block &message_block,
                              size_t bytes_to_write,
                              unsigned long offset,
                              unsigned long offset_high,
                              const void *act,
                              int priority,
                              int signal_number)
{
  if (0 == this->implementation_)
    {
      errno = EFAULT;
      return -1;
    }
  return this->implementation_->write (message_block,
                                       bytes_to_write,
                                       offset,
                                       offset_high,
                                       act,
                                       priority,
                                       signal_number);
}

#if (defined (ACE_WIN32) && !defined (ACE_HAS_WINCE))
int
ACE_Asynch_Write_File::writev (ACE_Message_Block &message_block,
                               size_t bytes_to_write,
                               unsigned long offset,
                               unsigned long offset_high,
                               const void *act,
                               int priority,
                               int signal_number)
{
  if (0 == this->implementation_)
    {
      errno = EFAULT;
      return -1;
    }
  return this->implementation_->writev (message_block,
                                        bytes_to_write,
                                        offset,
                                        offset_high,
                                        act,
                                        priority,
                                        signal_number);
}
#endif /* (defined (ACE_WIN32) && !defined (ACE_HAS_WINCE)) */

ACE_Asynch_Operation_Impl *
ACE_Asynch_Write_File::implementation (void) const
{
  return this->implementation_;
}

// ************************************************************

ACE_Asynch_Write_File::Result::Result (ACE_Asynch_Write_File_Result_Impl *implementation)
  : ACE_Asynch_Write_Stream::Result (implementation),
    implementation_ (implementation)
{
}

ACE_Asynch_Write_File::Result::~Result (void)
{
  // Proactor will delete the implementation when the <complete> call
  // completes.
}

ACE_Asynch_Write_File_Result_Impl *
ACE_Asynch_Write_File::Result::implementation (void) const
{
  return this->implementation_;
}

// *********************************************************************

ACE_Asynch_Accept::ACE_Asynch_Accept (void)
  : implementation_ (0)
{
}

ACE_Asynch_Accept::~ACE_Asynch_Accept (void)
{
  // Delete the implementation.
  delete this->implementation_;
  this->implementation_ = 0;
}

int
ACE_Asynch_Accept::open (ACE_Handler &handler,
                         ACE_HANDLE handle,
                         const void *completion_key,
                         ACE_Proactor *proactor)
{
  // Get a proactor for/from the user.
  proactor = this->get_proactor (proactor, handler);

  // Now let us get the implementation initialized.
  if ((this->implementation_ = proactor->create_asynch_accept ()) == 0)
    return -1;

  // Call the <open> method of the base class.
  return ACE_Asynch_Operation::open (handler,
                                     handle,
                                     completion_key,
                                     proactor);
}

int
ACE_Asynch_Accept::accept (ACE_Message_Block &message_block,
                           size_t bytes_to_read,
                           ACE_HANDLE accept_handle,
                           const void *act,
                           int priority,
                           int signal_number,
                           int addr_family)
{
  if (0 == this->implementation_)
    {
      errno = EFAULT;
      return -1;
    }
  return this->implementation_->accept (message_block,
                                        bytes_to_read,
                                        accept_handle,
                                        act,
                                        priority,
                                        signal_number,
                                        addr_family);
}

ACE_Asynch_Operation_Impl *
ACE_Asynch_Accept::implementation (void)  const
{
  return this->implementation_;
}

// ************************************************************

size_t
ACE_Asynch_Accept::Result::bytes_to_read (void) const
{
  return this->implementation ()->bytes_to_read ();
}

ACE_Message_Block &
ACE_Asynch_Accept::Result::message_block (void) const
{
  return this->implementation ()->message_block ();
}

ACE_HANDLE
ACE_Asynch_Accept::Result::listen_handle (void) const
{
  return this->implementation ()->listen_handle ();
}

ACE_HANDLE
ACE_Asynch_Accept::Result::accept_handle (void) const
{
  return this->implementation ()->accept_handle ();
}

ACE_Asynch_Accept::Result::Result (ACE_Asynch_Accept_Result_Impl *implementation)
  : ACE_Asynch_Result (implementation),
    implementation_ (implementation)
{
}

ACE_Asynch_Accept::Result::~Result (void)
{
  // Proactor will delete the implementation when the <complete> call
  // completes.
}

ACE_Asynch_Accept_Result_Impl *
ACE_Asynch_Accept::Result::implementation (void) const
{
  return this->implementation_;
}



// *********************************************************************

ACE_Asynch_Connect::ACE_Asynch_Connect (void)
  : implementation_ (0)
{
}

ACE_Asynch_Connect::~ACE_Asynch_Connect (void)
{
  // Delete the implementation.
  delete this->implementation_;
  this->implementation_ = 0;
}

int
ACE_Asynch_Connect::open (ACE_Handler &handler,
                          ACE_HANDLE handle,
                          const void *completion_key,
                          ACE_Proactor *proactor)
{
  // Get a proactor for/from the user.
  proactor = this->get_proactor (proactor, handler);

  // Now let us get the implementation initialized.
  if ((this->implementation_ = proactor->create_asynch_connect ()) == 0)
    return -1;

  // Call the <open> method of the base class.
  return ACE_Asynch_Operation::open (handler,
                                     handle,
                                     completion_key,
                                     proactor);
}

int
ACE_Asynch_Connect::connect (ACE_HANDLE connect_handle,
                             const ACE_Addr & remote_sap,
                             const ACE_Addr & local_sap,
                             int  reuse_addr,
                             const void *act,
                             int priority,
                             int signal_number)
{
  if (0 == this->implementation_)
    {
      errno = EFAULT;
      return -1;
    }
  return this->implementation_->connect (connect_handle,
                                         remote_sap,
                                         local_sap,
                                         reuse_addr,
                                         act,
                                         priority,
                                         signal_number);
}

ACE_Asynch_Operation_Impl *
ACE_Asynch_Connect::implementation (void)  const
{
  return this->implementation_;
}

// ************************************************************

ACE_Asynch_Connect::Result::Result (ACE_Asynch_Connect_Result_Impl *implementation)
  : ACE_Asynch_Result (implementation),
    implementation_ (implementation)
{
}

ACE_Asynch_Connect::Result::~Result (void)
{
  // Proactor will delete the implementation when the <complete> call
  // completes.
}

ACE_HANDLE
ACE_Asynch_Connect::Result::connect_handle (void) const
{
  return this->implementation ()->connect_handle ();
}


ACE_Asynch_Connect_Result_Impl *
ACE_Asynch_Connect::Result::implementation (void) const
{
  return this->implementation_;
}

// ************************************************************

ACE_Asynch_Transmit_File::ACE_Asynch_Transmit_File (void)
  : implementation_ (0)
{
}

ACE_Asynch_Transmit_File::~ACE_Asynch_Transmit_File (void)
{
  // Delete the implementation.
  delete this->implementation_;
  this->implementation_ = 0;
}

int
ACE_Asynch_Transmit_File::open (ACE_Handler &handler,
                                ACE_HANDLE handle,
                                const void *completion_key,
                                ACE_Proactor *proactor)
{
  // Get a proactor for/from the user.
  proactor = this->get_proactor (proactor, handler);

  // Now let us get the implementation initialized.
  if ((this->implementation_ = proactor->create_asynch_transmit_file ()) == 0)
    return -1;

  // Call the <open> method of the base class.
  return ACE_Asynch_Operation::open (handler,
                                     handle,
                                     completion_key,
                                     proactor);
}

int
ACE_Asynch_Transmit_File::transmit_file (ACE_HANDLE file,
                                         Header_And_Trailer *header_and_trailer,
                                         size_t bytes_to_write,
                                         unsigned long offset,
                                         unsigned long offset_high,
                                         size_t bytes_per_send,
                                         unsigned long flags,
                                         const void *act,
                                         int priority,
                                         int signal_number)
{
  if (0 == this->implementation_)
    {
      errno = EFAULT;
      return -1;
    }
  return this->implementation_->transmit_file (file,
                                               header_and_trailer,
                                               bytes_to_write,
                                               offset,
                                               offset_high,
                                               bytes_per_send,
                                               flags,
                                               act,
                                               priority,
                                               signal_number);
}

ACE_Asynch_Operation_Impl *
ACE_Asynch_Transmit_File::implementation (void) const
{
  return this->implementation_;
}

// ****************************************************************************

ACE_HANDLE
ACE_Asynch_Transmit_File::Result::socket (void) const
{
  return this->implementation ()->socket ();
}

ACE_HANDLE
ACE_Asynch_Transmit_File::Result::file (void) const
{
  return this->implementation ()->file ();
}

ACE_Asynch_Transmit_File::Header_And_Trailer *
ACE_Asynch_Transmit_File::Result::header_and_trailer (void) const
{
  return this->implementation ()->header_and_trailer ();
}

size_t
ACE_Asynch_Transmit_File::Result::bytes_to_write (void) const
{
  return this->implementation ()->bytes_to_write ();
}

size_t
ACE_Asynch_Transmit_File::Result::bytes_per_send (void) const
{
  return this->implementation ()->bytes_per_send ();
}

unsigned long
ACE_Asynch_Transmit_File::Result::flags (void) const
{
  return this->implementation ()->flags ();
}

ACE_Asynch_Transmit_File::Result::Result (ACE_Asynch_Transmit_File_Result_Impl *implementation)
  : ACE_Asynch_Result (implementation),
    implementation_ (implementation)
{
}

ACE_Asynch_Transmit_File::Result::~Result (void)
{
}

ACE_Asynch_Transmit_File_Result_Impl *
ACE_Asynch_Transmit_File::Result::implementation (void) const
{
  return this->implementation_;
}

// ************************************************************

ACE_Asynch_Transmit_File::Header_And_Trailer::Header_And_Trailer (ACE_Message_Block *header,
                                                                  size_t header_bytes,
                                                                  ACE_Message_Block *trailer,
                                                                  size_t trailer_bytes)
  : header_ (header),
    header_bytes_ (header_bytes),
    trailer_ (trailer),
    trailer_bytes_ (trailer_bytes)
{
}

ACE_Asynch_Transmit_File::Header_And_Trailer::~Header_And_Trailer (void)
{
}

void
ACE_Asynch_Transmit_File::Header_And_Trailer::header_and_trailer (ACE_Message_Block *header,
                                                                  size_t header_bytes,
                                                                  ACE_Message_Block *trailer,
                                                                  size_t trailer_bytes)
{
  this->header (header);
  this->header_bytes (header_bytes);
  this->trailer (trailer);
  this->trailer_bytes (trailer_bytes);
}

ACE_Message_Block *
ACE_Asynch_Transmit_File::Header_And_Trailer::header (void) const
{
  return this->header_;
}

void
ACE_Asynch_Transmit_File::Header_And_Trailer::header (ACE_Message_Block *message_block)
{
  this->header_ = message_block;
}

size_t
ACE_Asynch_Transmit_File::Header_And_Trailer::header_bytes (void) const
{
  return this->header_bytes_;
}

void
ACE_Asynch_Transmit_File::Header_And_Trailer::header_bytes (size_t bytes)
{
  this->header_bytes_ = bytes;
}

ACE_Message_Block *
ACE_Asynch_Transmit_File::Header_And_Trailer::trailer (void) const
{
  return this->trailer_;
}

void
ACE_Asynch_Transmit_File::Header_And_Trailer::trailer (ACE_Message_Block *message_block)
{
  this->trailer_ = message_block;
}

size_t
ACE_Asynch_Transmit_File::Header_And_Trailer::trailer_bytes (void) const
{
  return this->trailer_bytes_;
}

void
ACE_Asynch_Transmit_File::Header_And_Trailer::trailer_bytes (size_t bytes)
{
  this->trailer_bytes_ = bytes;
}

ACE_LPTRANSMIT_FILE_BUFFERS
ACE_Asynch_Transmit_File::Header_And_Trailer::transmit_buffers (void)
{
  // If both are zero, return zero
  if (this->header_ == 0 && this->trailer_ == 0)
    {
      return 0;
    }
  else
    {
      // Something is valid

      // If header is valid, set the fields
      if (this->header_ != 0)
        {
          this->transmit_buffers_.Head = this->header_->rd_ptr ();
#if defined (ACE_WIN64) || defined (ACE_WIN32)
          this->transmit_buffers_.HeadLength =
            ACE_Utils::truncate_cast<DWORD> (this->header_bytes_);
#else
          this->transmit_buffers_.HeadLength = this->header_bytes_;
#endif /* ACE_WIN64 || ACE_WIN32 */
        }
      else
        {
          this->transmit_buffers_.Head = 0;
          this->transmit_buffers_.HeadLength = 0;
        }

      // If trailer is valid, set the fields
      if (this->trailer_ != 0)
        {
          this->transmit_buffers_.Tail = this->trailer_->rd_ptr ();
#if defined(ACE_WIN64) || defined (ACE_WIN32)
          this->transmit_buffers_.TailLength =
            ACE_Utils::truncate_cast<DWORD> (this->trailer_bytes_);
#else
          this->transmit_buffers_.TailLength = this->trailer_bytes_;
#endif /* ACE_WIN64 || ACE_WIN32 */
        }
      else
        {
          this->transmit_buffers_.Tail = 0;
          this->transmit_buffers_.TailLength = 0;
        }

      // Return the transmit buffers
      return &this->transmit_buffers_;
    }
}

// *********************************************************************

ACE_Handler::ACE_Handler (void)
  : proactor_ (0), handle_ (ACE_INVALID_HANDLE)
{
  ACE_Handler::Proxy *p;
  ACE_NEW (p, ACE_Handler::Proxy (this));
  this->proxy_.reset (p);
}

ACE_Handler::ACE_Handler (ACE_Proactor *d)
  : proactor_ (d), handle_ (ACE_INVALID_HANDLE)
{
  ACE_Handler::Proxy *p;
  ACE_NEW (p, ACE_Handler::Proxy (this));
  this->proxy_.reset (p);
}

ACE_Handler::~ACE_Handler (void)
{
  ACE_Handler::Proxy *p = this->proxy_.get ();
  if (p)
    p->reset ();
}

void
ACE_Handler::handle_read_stream (const ACE_Asynch_Read_Stream::Result & /* result */)
{
}

void
ACE_Handler::handle_write_stream (const ACE_Asynch_Write_Stream::Result & /* result */)
{
}

void
ACE_Handler::handle_write_dgram (const ACE_Asynch_Write_Dgram::Result & /* result */)
{
}

void
ACE_Handler::handle_read_dgram (const ACE_Asynch_Read_Dgram::Result & /* result */)
{
}

void
ACE_Handler::handle_accept (const ACE_Asynch_Accept::Result & /* result */)
{
}

void
ACE_Handler::handle_connect (const ACE_Asynch_Connect::Result & /* result */)
{
}

void
ACE_Handler::handle_transmit_file (const ACE_Asynch_Transmit_File::Result & /* result */)
{
}

void
ACE_Handler::handle_read_file (const ACE_Asynch_Read_File::Result & /* result */)
{
}

void
ACE_Handler::handle_write_file (const ACE_Asynch_Write_File::Result & /* result */)
{
}

void
ACE_Handler::handle_time_out (const ACE_Time_Value & /* tv */,
                              const void *           /* act */)
{
}

void
ACE_Handler::handle_wakeup (void)
{
}

ACE_Proactor *
ACE_Handler::proactor (void)
{
  return this->proactor_;
}

void
ACE_Handler::proactor (ACE_Proactor *p)
{
  this->proactor_ = p;
}

ACE_HANDLE
ACE_Handler::handle (void) const
{
  return this->handle_;
}

void
ACE_Handler::handle (ACE_HANDLE h)
{
  this->handle_ = h;
}

ACE_Refcounted_Auto_Ptr<ACE_Handler::Proxy, ACE_SYNCH_MUTEX> &
ACE_Handler::proxy (void)
{
  return this->proxy_;
}

// ************************************************************

ACE_Service_Handler::ACE_Service_Handler (void)
{
}

ACE_Service_Handler::~ACE_Service_Handler (void)
{
}

void
ACE_Service_Handler::addresses (const ACE_INET_Addr & /* remote_address */,
                                const ACE_INET_Addr & /* local_address */ )
{
}

void
ACE_Service_Handler::act (const void *)
{
}

void
ACE_Service_Handler::open (ACE_HANDLE,
                           ACE_Message_Block &)
{
}


// ************************************************************

ACE_Asynch_Read_Dgram::ACE_Asynch_Read_Dgram (void)
  : implementation_ (0)
{
}

ACE_Asynch_Read_Dgram::~ACE_Asynch_Read_Dgram (void)
{
  // Delete the implementation.
  delete this->implementation_;
  this->implementation_ = 0;
}

int
ACE_Asynch_Read_Dgram::open (ACE_Handler &handler,
                             ACE_HANDLE handle,
                             const void *completion_key,
                             ACE_Proactor *proactor)
{
  // Get a proactor for/from the user.
  proactor = this->get_proactor (proactor, handler);

  // Now let us get the implementation initialized.
  if ((this->implementation_ = proactor->create_asynch_read_dgram ()) == 0)
    return -1;

  // Call the <open> method of the base class.
  return ACE_Asynch_Operation::open (handler,
                                     handle,
                                     completion_key,
                                     proactor);
}

ssize_t
ACE_Asynch_Read_Dgram::recv (ACE_Message_Block *message_block,
                             size_t &number_of_bytes_recvd,
                             int flags,
                             int protocol_family,
                             const void *act,
                             int priority,
                             int signal_number)
{
  if (0 == this->implementation_)
    {
      errno = EFAULT;
      return -1;
    }
  return this->implementation_->recv (message_block,
                                      number_of_bytes_recvd,
                                      flags,
                                      protocol_family,
                                      act,
                                      priority,
                                      signal_number);
}

ACE_Asynch_Operation_Impl *
ACE_Asynch_Read_Dgram::implementation (void) const
{
  return this->implementation_;
}

// ************************************************************

int
ACE_Asynch_Read_Dgram::Result::remote_address (ACE_Addr& addr) const
{
  return this->implementation ()->remote_address (addr);
}

ACE_Message_Block*
ACE_Asynch_Read_Dgram::Result::message_block (void) const
{
  return this->implementation ()->message_block ();
}

int
ACE_Asynch_Read_Dgram::Result::flags (void) const
{
  return this->implementation ()->flags ();
}

size_t
ACE_Asynch_Read_Dgram::Result::bytes_to_read (void) const
{
  return this->implementation ()->bytes_to_read ();
}

ACE_HANDLE
ACE_Asynch_Read_Dgram::Result::handle (void) const
{
  return this->implementation ()->handle();
}

ACE_Asynch_Read_Dgram::Result::Result (ACE_Asynch_Read_Dgram_Result_Impl *implementation)
: ACE_Asynch_Result (implementation),
  implementation_ (implementation)
{
}

ACE_Asynch_Read_Dgram::Result::~Result (void)
{
}

ACE_Asynch_Read_Dgram_Result_Impl *
ACE_Asynch_Read_Dgram::Result::implementation (void) const
{
  return this->implementation_;
}

// ************************************************************


ACE_Asynch_Write_Dgram::ACE_Asynch_Write_Dgram (void)
  : implementation_ (0)
{
}

ACE_Asynch_Write_Dgram::~ACE_Asynch_Write_Dgram (void)
{
  // Delete the implementation.
  delete this->implementation_;
  this->implementation_ = 0;
}

int
ACE_Asynch_Write_Dgram::open (ACE_Handler &handler,
                              ACE_HANDLE handle,
                              const void *completion_key,
                              ACE_Proactor *proactor)
{
  // Get a proactor for/from the user.
  proactor = this->get_proactor (proactor, handler);

  // Now let us get the implementation initialized.
  if ((this->implementation_ = proactor->create_asynch_write_dgram ()) == 0)
    return -1;

  // Call the <open> method of the base class.
  return ACE_Asynch_Operation::open (handler,
                                     handle,
                                     completion_key,
                                     proactor);
}

ssize_t
ACE_Asynch_Write_Dgram::send (ACE_Message_Block *message_block,
                              size_t &number_of_bytes_sent,
                              int flags,
                              const ACE_Addr& remote_addr,
                              const void *act,
                              int priority,
                              int signal_number)
{
  if (0 == this->implementation_)
    {
      errno = EFAULT;
      return -1;
    }
  return this->implementation_->send (message_block,
                                      number_of_bytes_sent,
                                      flags,
                                      remote_addr,
                                      act,
                                      priority,
                                      signal_number);
}

ACE_Asynch_Operation_Impl *
ACE_Asynch_Write_Dgram::implementation (void) const
{
  return this->implementation_;
}

// ************************************************************

size_t
ACE_Asynch_Write_Dgram::Result::bytes_to_write (void) const
{
  return this->implementation ()->bytes_to_write ();
}

ACE_Message_Block*
ACE_Asynch_Write_Dgram::Result::message_block () const
{
  return this->implementation ()->message_block ();
}

int
ACE_Asynch_Write_Dgram::Result::flags (void) const
{
  return this->implementation ()->flags ();
}

ACE_HANDLE
ACE_Asynch_Write_Dgram::Result::handle (void) const
{
  return this->implementation ()->handle ();
}

ACE_Asynch_Write_Dgram_Result_Impl *
ACE_Asynch_Write_Dgram::Result::implementation (void) const
{
  return this->implementation_;
}

ACE_Asynch_Write_Dgram::Result::Result (ACE_Asynch_Write_Dgram_Result_Impl *implementation)
: ACE_Asynch_Result (implementation),
  implementation_ (implementation)
{
}

ACE_Asynch_Write_Dgram::Result::~Result (void)
{
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_HAS_WIN32_OVERLAPPED_IO || ACE_HAS_AIO_CALLS */

