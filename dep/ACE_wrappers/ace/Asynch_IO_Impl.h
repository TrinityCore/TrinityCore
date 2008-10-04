/* -*- C++ -*- */

//=============================================================================
/**
 *  @file    Asynch_IO_Impl.h
 *
 *  $Id: Asynch_IO_Impl.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *
 *  This class contains asbtract base classes for all the concrete
 *  implementation classes for the various asynchronous operations
 *  that are used with the Praoctor.
 *
 *
 *  @author Irfan Pyarali (irfan@cs.wustl.edu)
 *  @author Tim Harrison (harrison@cs.wustl.edu)
 *  @author Alexander Babu Arulanthu <alex@cs.wustl.edu>
 *  @author Roger Tragin <r.tragin@computer.org>
 *  @author Alexander Libman <alibman@ihug.com.au>
 */
//=============================================================================

#ifndef ACE_ASYNCH_IO_IMPL_H
#define ACE_ASYNCH_IO_IMPL_H
#include /**/ "ace/pre.h"

#include /**/ "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if defined (ACE_HAS_WIN32_OVERLAPPED_IO) || defined (ACE_HAS_AIO_CALLS)
// This only works on Win32 platforms and on Unix platforms supporting
// aio calls.

#include "ace/Asynch_IO.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

// Forward declaration.
class ACE_Proactor_Impl;

/**
 * @class ACE_Asynch_Result_Impl
 *
 * @brief Abstract base class for the all the classes that provide
 * concrete implementations for ACE_Asynch_Result.
 *
 */
class ACE_Export ACE_Asynch_Result_Impl
{
public:
  virtual ~ACE_Asynch_Result_Impl (void);

  /// Number of bytes transferred by the operation.
  virtual size_t bytes_transferred (void) const = 0;

  /// ACT associated with the operation.
  virtual const void *act (void) const = 0;

  /// Did the operation succeed?
  virtual int success (void) const = 0;

  /// This ACT is not the same as the ACT associated with the
  /// asynchronous operation.
  virtual const void *completion_key (void) const = 0;

  /// Error value if the operation fail.
  virtual u_long error (void) const = 0;

  /// Event associated with the OVERLAPPED structure.
  virtual ACE_HANDLE event (void) const = 0;

  /// This really make sense only when doing file I/O.
  virtual u_long offset (void) const = 0;
  virtual u_long offset_high (void) const = 0;

  /// Priority of the operation.
  virtual int priority (void) const = 0;

  /**
   * POSIX4 real-time signal number to be used for the
   * operation. <signal_number> ranges from SIGRTMIN to SIGRTMAX. By
   * default, SIGRTMIN is used to issue <aio_> calls. This is a no-op
   * on non-POSIX4 systems and returns 0.
   */
  virtual int signal_number (void) const = 0;

  // protected:
  //
  // These two should really be protected.  But sometimes it
  // simplifies code to be able to "fake" a result.  Use carefully.
  /// This is called when the asynchronous operation completes.
  virtual void complete (size_t bytes_transferred,
                         int success,
                         const void *completion_key,
                         u_long error = 0) = 0;

  /// Post @c this to the Proactor's completion port.
  virtual int post_completion (ACE_Proactor_Impl *proactor) = 0;

protected:
  /// Do-nothing constructor.
  ACE_Asynch_Result_Impl (void);
};

/**
 * @class ACE_Asynch_Operation_Impl
 *
 * @brief Abstract base class for all the concrete implementation
 * classes that provide different implementations for the
 * ACE_Asynch_Operation.
 */
class ACE_Export ACE_Asynch_Operation_Impl
{
public:
  virtual ~ACE_Asynch_Operation_Impl (void);

  /**
   * Initializes the factory with information which will be used with
   * each asynchronous call.  If @a handle == ACE_INVALID_HANDLE,
   * ACE_Handler::handle() will be called on the proxied handler to get the
   * correct handle.
   */
  virtual int open (const ACE_Handler::Proxy_Ptr &handler_proxy,
                    ACE_HANDLE handle,
                    const void *completion_key,
                    ACE_Proactor *proactor) = 0;

  /**
   * This cancels all pending accepts operations that were issued by
   * the calling thread.  The function does not cancel asynchronous
   * operations issued by other threads.
   */
  virtual int cancel (void) = 0;

  // = Access methods.

  /// Return the underlying proactor.
  virtual ACE_Proactor* proactor (void) const = 0;

protected:
  /// Do-nothing constructor.
  ACE_Asynch_Operation_Impl (void);
};

/**
 * @class ACE_Asynch_Read_Stream_Impl
 *
 * @brief Abstract base class for all the concrete implementation
 * classes that provide different implementations for the
 * ACE_Asynch_Read_Stream
 *
 */
class ACE_Export ACE_Asynch_Read_Stream_Impl : public virtual ACE_Asynch_Operation_Impl
{
public:
  virtual ~ACE_Asynch_Read_Stream_Impl (void);

  /// This starts off an asynchronous read. Upto @a bytes_to_read will
  /// be read and stored in the @a message_block.
  virtual int read (ACE_Message_Block &message_block,
                    size_t bytes_to_read,
                    const void *act,
                    int priority,
                    int signal_number) = 0;

#if (defined (ACE_WIN32) && !defined (ACE_HAS_WINCE))
  /**
  * Same as above but with scatter support, through chaining of composite
  * message blocks using the continuation field.
  */
  virtual int readv (ACE_Message_Block &message_block,
                     size_t bytes_to_read,
                     const void *act,
                     int priority,
                     int signal_number) = 0;
#endif /* (defined (ACE_WIN32) && !defined (ACE_HAS_WINCE)) */

protected:
  /// Do-nothing constructor.
  ACE_Asynch_Read_Stream_Impl (void);
};

/**
 * @class ACE_Asynch_Read_Stream_Result_Impl
 *
 * @brief Abstract base class for all the concrete implementation
 * classes that provide different implementations for the
 * ACE_Asynch_Read_Stream::Result class.
 *
 */
class ACE_Export ACE_Asynch_Read_Stream_Result_Impl : public virtual ACE_Asynch_Result_Impl
{
public:
  virtual ~ACE_Asynch_Read_Stream_Result_Impl (void);

  /// The number of bytes which were requested at the start of the
  /// asynchronous read.
  virtual size_t bytes_to_read (void) const = 0;

  /// Message block which contains the read data.
  virtual ACE_Message_Block &message_block (void) const = 0;

  /// I/O handle used for reading.
  virtual ACE_HANDLE handle (void) const = 0;

protected:
  /// Do-nothing constructor.
  ACE_Asynch_Read_Stream_Result_Impl (void);
};

/**
 * @class ACE_Asynch_Write_Stream_Impl
 *
 * @brief Abstract base class for all the concrete implementation
 * classes that provide different implementations for the
 * ACE_Asynch_Write_Stream class.
 *
 */
class ACE_Export ACE_Asynch_Write_Stream_Impl : public virtual ACE_Asynch_Operation_Impl
{
public:
  virtual ~ACE_Asynch_Write_Stream_Impl (void);

  /// This starts off an asynchronous write.  Upto @a bytes_to_write
  /// will be written from the @a message_block.
  virtual int write (ACE_Message_Block &message_block,
                     size_t bytes_to_write,
                     const void *act,
                     int priority,
                     int signal_number) = 0;

#if (defined (ACE_WIN32) && !defined (ACE_HAS_WINCE))
  /**
  * Same as above but with gather support, through chaining of composite
  * message blocks using the continuation field.
  */
  virtual int writev (ACE_Message_Block &message_block,
                      size_t bytes_to_write,
                      const void *act,
                      int priority,
                      int signal_number) = 0;
#endif /* (defined (ACE_WIN32) && !defined (ACE_HAS_WINCE)) */

protected:
  /// Do-nothing constructor.
  ACE_Asynch_Write_Stream_Impl (void);
};

/**
 * @class ACE_Asynch_Write_Stream_Result_Impl
 *
 * @brief Abstract base class for all the concrete implementation
 * classes that provide different implementations for the
 * ACE_Asynch_Write_Stream::Result.
 *
 */
class ACE_Export ACE_Asynch_Write_Stream_Result_Impl : public virtual ACE_Asynch_Result_Impl
{
public:
  virtual ~ACE_Asynch_Write_Stream_Result_Impl (void);

  /// The number of bytes which were requested at the start of the
  /// asynchronous write.
  virtual size_t bytes_to_write (void) const = 0;

  /// Message block that contains the data to be written.
  virtual ACE_Message_Block &message_block (void) const = 0;

  /// I/O handle used for writing.
  virtual ACE_HANDLE handle (void) const = 0;

protected:
  /// Do-nothing constructor.
  ACE_Asynch_Write_Stream_Result_Impl (void);
};

/**
 * @class ACE_Asynch_Read_File_Impl
 *
 * @brief Abstract base class for all the concrete implementation
 * classes that provide different implementations for the
 * ACE_Asynch_Read_File::Result.
 *
 */
class ACE_Export ACE_Asynch_Read_File_Impl : public virtual ACE_Asynch_Read_Stream_Impl
{
public:
  virtual ~ACE_Asynch_Read_File_Impl (void);

  /**
   * This starts off an asynchronous read.  Upto @a bytes_to_read will
   * be read and stored in the @a message_block.  The read will start
   * at @a offset from the beginning of the file.
   */
  virtual int read (ACE_Message_Block &message_block,
                    size_t bytes_to_read,
                    u_long offset,
                    u_long offset_high,
                    const void *act,
                    int priority,
                    int signal_number) = 0;

#if (defined (ACE_WIN32) && !defined (ACE_HAS_WINCE))
  /**
  * Same as above but with scatter support, through chaining of composite
  * message blocks using the continuation field.
  * @note In win32 Each data block payload must be at least the size of a system
  * memory page and must be aligned on a system memory page size boundary
  */
  virtual int readv (ACE_Message_Block &message_block,
                     size_t bytes_to_read,
                     u_long offset,
                     u_long offset_high,
                     const void *act,
                     int priority,
                     int signal_number) = 0;
#endif /* (defined (ACE_WIN32) && !defined (ACE_HAS_WINCE)) */

  /// This starts off an asynchronous read. Upto @a bytes_to_read will
  /// be read and stored in the @a message_block.
  virtual int read (ACE_Message_Block &message_block,
                    size_t bytes_to_read,
                    const void *act,
                    int priority,
                    int signal_number) = 0;

#if (defined (ACE_WIN32) && !defined (ACE_HAS_WINCE))
  /**
  * Same as above but with scatter support, through chaining of composite
  * message blocks using the continuation field.
  */
  virtual int readv (ACE_Message_Block &message_block,
                     size_t bytes_to_read,
                     const void *act,
                     int priority,
                     int signal_number) = 0;
#endif /* (defined (ACE_WIN32) && !defined (ACE_HAS_WINCE)) */

protected:
  /// Do-nothing constructor.
  ACE_Asynch_Read_File_Impl (void);
};

/**
 * @class ACE_Asynch_Read_File_Result_Impl
 *
 * @brief This is the abstract base class for all the concrete
 * implementation classes for ACE_Asynch_Read_File::Result.
 *
 */
class ACE_Export ACE_Asynch_Read_File_Result_Impl : public virtual ACE_Asynch_Read_Stream_Result_Impl
{
public:
  /// Destructor.
  virtual ~ACE_Asynch_Read_File_Result_Impl (void);

protected:
  /// Do-nothing constructor.
  ACE_Asynch_Read_File_Result_Impl (void);
};

/**
 * @class ACE_Asynch_Write_File_Impl
 *
 * @brief Abstract base class for all the concrete implementation
 * classes that provide different implementations for the
 * ACE_Asynch_Write_File.
 *
 */
class ACE_Export ACE_Asynch_Write_File_Impl : public virtual ACE_Asynch_Write_Stream_Impl
{
public:
  virtual ~ACE_Asynch_Write_File_Impl (void);

  /**
   * This starts off an asynchronous write.  Upto @a bytes_to_write
   * will be write and stored in the @a message_block.  The write will
   * start at @a offset from the beginning of the file.
   */
  virtual int write (ACE_Message_Block &message_block,
                     size_t bytes_to_write,
                     u_long offset,
                     u_long offset_high,
                     const void *act,
                     int priority,
                     int signal_number) = 0;

#if (defined (ACE_WIN32) && !defined (ACE_HAS_WINCE))
  /**
  * Same as above but with gather support, through chaining of composite
  * message blocks using the continuation field.
  * @note In win32 Each data block payload must be at least the size of a system
  * memory page and must be aligned on a system memory page size boundary
  */
  virtual int writev (ACE_Message_Block &message_block,
                      size_t bytes_to_write,
                      u_long offset,
                      u_long offset_high,
                      const void *act,
                      int priority,
                      int signal_number) = 0;
#endif /* (defined (ACE_WIN32) && !defined (ACE_HAS_WINCE)) */

  /// This starts off an asynchronous write.  Upto @a bytes_to_write
  /// will be written from the @a message_block.
  virtual int write (ACE_Message_Block &message_block,
                     size_t bytes_to_write,
                     const void *act,
                     int priority,
                     int signal_number) = 0;

#if (defined (ACE_WIN32) && !defined (ACE_HAS_WINCE))
  /**
  * Same as above but with gather support, through chaining of composite
  * message blocks using the continuation field.
  */
  virtual int writev (ACE_Message_Block &message_block,
                      size_t bytes_to_write,
                      const void *act,
                      int priority,
                      int signal_number) = 0;
#endif /* (defined (ACE_WIN32) && !defined (ACE_HAS_WINCE)) */

protected:
  /// Do-nothing constructor.
  ACE_Asynch_Write_File_Impl (void);
};

/**
 * @class ACE_Asynch_Write_File_Result_Impl
 *
 * @brief This is the abstract base class for all the concrete
 * implementation classes that provide different implementations
 * for the ACE_Asynch_Write_File::Result.
 *
 */
class ACE_Export ACE_Asynch_Write_File_Result_Impl : public virtual ACE_Asynch_Write_Stream_Result_Impl
{
public:
  virtual ~ACE_Asynch_Write_File_Result_Impl (void);

protected:
  /// Do-nothing constructor.
  ACE_Asynch_Write_File_Result_Impl (void);
};

/**
 * @class ACE_Asynch_Accept_Impl
 *
 * @brief Abstract base class for all the concrete implementation
 * classes that provide different implementations for the
 * ACE_Asynch_Accept.
 *
 */
class ACE_Export ACE_Asynch_Accept_Impl : public virtual ACE_Asynch_Operation_Impl
{
public:
  virtual ~ACE_Asynch_Accept_Impl (void);

  /**
   * This starts off an asynchronous accept.  The asynchronous accept
   * call also allows any initial data to be returned to the
   * <handler>.  Upto @a bytes_to_read will be read and stored in the
   * @a message_block.  The @a accept_handle will be used for the
   * <accept> call.  If (@a accept_handle == INVALID_HANDLE), a new
   * handle will be created.
   *
   * @a message_block must be specified. This is because the address of
   * the new connection is placed at the end of this buffer.
   */
  virtual int accept (ACE_Message_Block &message_block,
                      size_t bytes_to_read,
                      ACE_HANDLE accept_handle,
                      const void *act,
                      int priority,
                      int signal_number,
                      int addr_family) = 0;

protected:
  /// Do-nothing constructor.
  ACE_Asynch_Accept_Impl (void);
};

/**
 * @class ACE_Asynch_Accept_Result_Impl
 *
 * @brief Abstract base class for all the concrete implementation
 * classes that provide different implementations for the
 * ACE_Asynch_Accept.
 *
 */
class ACE_Export ACE_Asynch_Accept_Result_Impl : public virtual ACE_Asynch_Result_Impl
{
public:
  virtual ~ACE_Asynch_Accept_Result_Impl (void);

  /// The number of bytes which were requested at the start of the
  /// asynchronous accept.
  virtual size_t bytes_to_read (void) const = 0;

  /// Message block which contains the read data.
  virtual ACE_Message_Block &message_block (void) const = 0;

  /// I/O handle used for accepting new connections.
  virtual ACE_HANDLE listen_handle (void) const = 0;

  /// I/O handle for the new connection.
  virtual ACE_HANDLE accept_handle (void) const = 0;

protected:
  /// Do-nothing constructor.
  ACE_Asynch_Accept_Result_Impl (void);
};


/**
 * @class ACE_Asynch_Connect_Impl
 *
 * @brief Abstract base class for all the concrete implementation
 * classes that provide different implementations for the
 * ACE_Asynch_Connect.
 *
 */
class ACE_Export ACE_Asynch_Connect_Impl : public virtual ACE_Asynch_Operation_Impl
{
public:
  virtual ~ACE_Asynch_Connect_Impl (void);

  /**
   * This starts off an asynchronous connect
   */
  virtual int connect (ACE_HANDLE connect_handle,
                       const ACE_Addr & remote_sap,
                       const ACE_Addr & local_sap,
                       int   reuse_addr,
                       const void *act,
                       int   priority,
                       int   signal_number) = 0;

protected:
  /// Do-nothing constructor.
  ACE_Asynch_Connect_Impl (void);
};

/**
 * @class ACE_Asynch_Connect_Result_Impl
 *
 * @brief Abstract base class for all the concrete implementation
 * classes that provide different implementations for the
 * ACE_Asynch_Connect.
 *
 */
class ACE_Export ACE_Asynch_Connect_Result_Impl : public virtual ACE_Asynch_Result_Impl
{
public:
  virtual ~ACE_Asynch_Connect_Result_Impl (void);

  /// I/O handle for the connection.
  virtual ACE_HANDLE connect_handle (void) const = 0;

protected:
  /// Do-nothing constructor.
  ACE_Asynch_Connect_Result_Impl (void);
};


/**
 * @class ACE_Asynch_Transmit_File_Impl
 *
 * @brief Abstract base class for all the concrete implementation
 * classes that provide different implementations for the
 * ACE_Asynch_Transmit_File.
 *
 */
class ACE_Asynch_Transmit_File_Impl : public virtual ACE_Asynch_Operation_Impl
{
public:
  virtual ~ACE_Asynch_Transmit_File_Impl (void);

  /// This starts off an asynchronous transmit file.
  virtual int transmit_file (ACE_HANDLE file,
                             ACE_Asynch_Transmit_File::Header_And_Trailer *header_and_trailer,
                             size_t bytes_to_write,
                             u_long offset,
                             u_long offset_high,
                             size_t bytes_per_send,
                             u_long flags,
                             const void *act,
                             int priority,
                             int signal_number) = 0;

protected:
  /// Do-nothing constructor.
  ACE_Asynch_Transmit_File_Impl (void);
};

/**
 * @class ACE_Asynch_Transmit_File_Result_Impl
 *
 * @brief Abstract base class for all the concrete implementation
 * classes that provide different implementations for the
 * ACE_Asynch_Transmit_File::Result.
 *
 */
class ACE_Export ACE_Asynch_Transmit_File_Result_Impl : public virtual ACE_Asynch_Result_Impl
{
public:
  virtual ~ACE_Asynch_Transmit_File_Result_Impl (void);

  /// Socket used for transmitting the file.
  virtual ACE_HANDLE socket (void) const = 0;

  /// File from which the data is read.
  virtual ACE_HANDLE file (void) const = 0;

  /// Header and trailer data associated with this transmit file.
  virtual ACE_Asynch_Transmit_File::Header_And_Trailer *header_and_trailer (void) const = 0;

  /// The number of bytes which were requested at the start of the
  /// asynchronous transmit file.
  virtual size_t bytes_to_write (void) const = 0;

  /// Number of bytes per send requested at the start of the transmit
  /// file.
  virtual size_t bytes_per_send (void) const = 0;

  /// Flags which were passed into transmit file.
  virtual u_long flags (void) const = 0;

protected:
  /// Do-nothing constructor.
  ACE_Asynch_Transmit_File_Result_Impl (void);
};


/**
 * @class ACE_Asynch_Read_Dgram_Impl
 *
 * @brief Abstract base class for all the concrete implementation
 * classes that provide different implementations for the
 * ACE_Asynch_Read_Dgram
 *
 */
class ACE_Export ACE_Asynch_Read_Dgram_Impl : public virtual ACE_Asynch_Operation_Impl
{
public:
  virtual ~ACE_Asynch_Read_Dgram_Impl (void);

  /** This starts off an asynchronous read.  Upto
   * <message_block->total_size()> will be read and stored in the
   * @a message_block.  @a message_block's <wr_ptr> will be updated to reflect
   * the added bytes if the read operation is successful completed.
   * Return code of 1 means immediate success and <number_of_bytes_recvd>
   * will contain number of bytes read.  The <ACE_Handler::handle_read_dgram>
   * method will still be called.  Return code of 0 means the IO will
   * complete proactively.  Return code of -1 means there was an error, use
   * errno to get the error code.
   *
   * Scatter/gather is supported on WIN32 by using the <message_block->cont()>
   * method.  Up to ACE_IOV_MAX @a message_block's are supported.  Upto
   * <message_block->size()> bytes will be read into each <message block> for
   * a total of <message_block->total_size()> bytes.  All @a message_block's
   * <wr_ptr>'s will be updated to reflect the added bytes for each
   * @a message_block
   *
   * Priority of the operation is specified by @a priority. On POSIX4-Unix,
   * this is supported. Works like <nice> in Unix. Negative values are not
   * allowed. 0 means priority of the operation same as the process
   * priority. 1 means priority of the operation is one less than
   * process. And so forth. On Win32, @a priority is a no-op.
   * @a signal_number is the POSIX4 real-time signal number to be used
   * for the operation. @a signal_number ranges from ACE_SIGRTMIN to
   * ACE_SIGRTMAX. This argument is a no-op on non-POSIX4 systems.
   */
  virtual ssize_t recv (ACE_Message_Block *message_block,
                        size_t &number_of_bytes_recvd,
                        int flags,
                        int protocol_family,
                        const void *act,
                        int priority,
                        int signal_number) = 0;

protected:
  /// Do-nothing constructor.
  ACE_Asynch_Read_Dgram_Impl (void);
};

/**
 * @class ACE_Asynch_Read_Dgram_Result_Impl
 *
 * @brief Abstract base class for all the concrete implementation
 * classes that provide different implementations for the
 * ACE_Asynch_Read_Dgram::Result class.
 *
 */
class ACE_Export ACE_Asynch_Read_Dgram_Result_Impl : public virtual ACE_Asynch_Result_Impl
{
public:
  virtual ~ACE_Asynch_Read_Dgram_Result_Impl (void);

  /// Message block which contains the read data
  virtual ACE_Message_Block *message_block (void) const = 0;

  /// The number of bytes which were requested at the start of the
  /// asynchronous read.
  virtual size_t bytes_to_read (void) const = 0;

  /// The address of where the packet came from
  virtual int remote_address (ACE_Addr& addr) const = 0;

  /// The flags used in the read
  virtual int flags (void) const = 0;

  /// I/O handle used for reading.
  virtual ACE_HANDLE handle (void) const = 0;

protected:
  /// Do-nothing constructor.
  ACE_Asynch_Read_Dgram_Result_Impl (void);
};

/**
 * @class ACE_Asynch_Write_Dgram_Impl
 *
 * @brief Abstract base class for all the concrete implementation
 * classes that provide different implementations for the
 * ACE_Asynch_Write_Dgram class.
 *
 */
class ACE_Export ACE_Asynch_Write_Dgram_Impl : public virtual ACE_Asynch_Operation_Impl
{
public:
  virtual ~ACE_Asynch_Write_Dgram_Impl (void);

  /** This starts off an asynchronous send.  Upto
   * <message_block->total_length()> will be sent.  @a message_block's
   * <rd_ptr> will be updated to reflect the sent bytes if the send operation
   * is successful completed.
   * Return code of 1 means immediate success and <number_of_bytes_sent>
   * is updated to number of bytes sent.  The <ACE_Handler::handle_write_dgram>
   * method will still be called.  Return code of 0 means the IO will
   * complete proactively.  Return code of -1 means there was an error, use
   * errno to get the error code.
   *
   * Scatter/gather is supported on WIN32 by using the <message_block->cont()>
   * method.  Up to ACE_IOV_MAX @a message_block's are supported.  Upto
   * <message_block->length()> bytes will be sent from each <message block>
   * for a total of <message_block->total_length()> bytes.  All
   * @a message_block's <rd_ptr>'s will be updated to reflect the bytes sent
   * from each @a message_block.
   *
   * Priority of the operation is specified by @a priority. On POSIX4-Unix,
   * this is supported. Works like <nice> in Unix. Negative values are not
   * allowed. 0 means priority of the operation same as the process
   * priority. 1 means priority of the operation is one less than
   * process. And so forth. On Win32, this argument is a no-op.
   * @a signal_number is the POSIX4 real-time signal number to be used
   * for the operation. @a signal_number ranges from ACE_SIGRTMIN to
   * ACE_SIGRTMAX. This argument is a no-op on non-POSIX4 systems.
   */
  virtual ssize_t send (ACE_Message_Block *message_block,
                        size_t &number_of_bytes_sent,
                        int flags,
                        const ACE_Addr &addr,
                        const void *act,
                        int priority,
                        int signal_number) = 0;

protected:
  /// Do-nothing constructor.
  ACE_Asynch_Write_Dgram_Impl (void);
};

/**
 * @class ACE_Asynch_Write_Dgram_Result_Impl
 *
 * @brief Abstract base class for all the concrete implementation
 * classes that provide different implementations for the
 * ACE_Asynch_Write_Dgram::Result class.
 *
 */
class ACE_Export ACE_Asynch_Write_Dgram_Result_Impl : public virtual ACE_Asynch_Result_Impl
{
public:
  virtual ~ACE_Asynch_Write_Dgram_Result_Impl (void);

  /// The number of bytes which were requested at the start of the
  /// asynchronous write.
  virtual size_t bytes_to_write (void) const = 0;

  /// Message block which contains the sent data
  virtual ACE_Message_Block *message_block (void) const = 0;

  /// The flags using in the write
  virtual int flags (void) const = 0;

  /// I/O handle used for writing.
  virtual ACE_HANDLE handle (void) const = 0;

protected:
  /// Do-nothing constructor.
  ACE_Asynch_Write_Dgram_Result_Impl (void);
};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ace/Asynch_IO_Impl.inl"
#endif /* __ACE_INLINE__ */

#endif /* ACE_HAS_WIN32_OVERLAPPED_IO || ACE_HAS_AIO_CALLS */
#include /**/ "ace/post.h"
#endif /* ACE_ASYNCH_IO_IMPL_H */
