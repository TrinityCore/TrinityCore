/* -*- C++ -*- */

//=============================================================================
/**
 *  @file    Asynch_IO.h
 *
 *  $Id: Asynch_IO.h 84837 2009-03-16 13:01:15Z johnnyw $
 *
 *  This works on Win32 (defined (ACE_WIN32) && !defined
 *  (ACE_HAS_WINCE)) platforms and on POSIX4 platforms with {aio_*}
 *  routines (defined (ACE_HAS_AIO_CALLS))
 *
 *  On Win32 platforms, the implementation of
 *  {ACE_Asynch_Transmit_File} and {ACE_Asynch_Accept} are only
 *  supported if ACE_HAS_WINSOCK2 is defined or you are on WinNT 4.0
 *  or higher.
 *
 *  @author Irfan Pyarali <irfan@cs.wustl.edu>
 *  @author Tim Harrison <harrison@cs.wustl.edu>
 *  @author Alexander Babu Arulanthu <alex@cs.wustl.edu>
 *  @author Roger Tragin <r.tragin@computer.org>
 *  @author Alexander Libman <alibman@ihug.com.au>
 */
//=============================================================================

#ifndef ACE_ASYNCH_IO_H
#define ACE_ASYNCH_IO_H
#include /**/ "ace/pre.h"

#include /**/ "ace/ACE_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if defined (ACE_HAS_WIN32_OVERLAPPED_IO) || defined (ACE_HAS_AIO_CALLS)

#include "ace/Synch_Traits.h"
#if defined (ACE_HAS_THREADS)
#  include "ace/Thread_Mutex.h"
#else
#  include "ace/Null_Mutex.h"
#endif /* ACE_HAS_THREADS */
#include "ace/Refcounted_Auto_Ptr.h"

#include "ace/os_include/os_signal.h"
#include "ace/os_include/sys/os_socket.h"
#include "ace/os_include/sys/os_types.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

# if defined (ACE_HAS_WIN32_OVERLAPPED_IO)
typedef TRANSMIT_FILE_BUFFERS ACE_TRANSMIT_FILE_BUFFERS;
typedef LPTRANSMIT_FILE_BUFFERS ACE_LPTRANSMIT_FILE_BUFFERS;
typedef PTRANSMIT_FILE_BUFFERS ACE_PTRANSMIT_FILE_BUFFERS;

#   define ACE_INFINITE INFINITE
#   define ACE_STATUS_TIMEOUT STATUS_TIMEOUT
#   define ACE_WAIT_FAILED WAIT_FAILED
#   define ACE_WAIT_TIMEOUT WAIT_TIMEOUT
# else /* ACE_HAS_WIN32_OVERLAPPED_IO */
struct ACE_TRANSMIT_FILE_BUFFERS
{
  void *Head;
  size_t HeadLength;
  void *Tail;
  size_t TailLength;
};
typedef ACE_TRANSMIT_FILE_BUFFERS* ACE_PTRANSMIT_FILE_BUFFERS;
typedef ACE_TRANSMIT_FILE_BUFFERS* ACE_LPTRANSMIT_FILE_BUFFERS;

#   if !defined (ACE_INFINITE)
#     define ACE_INFINITE LONG_MAX
#   endif /* ACE_INFINITE */
#   define ACE_STATUS_TIMEOUT LONG_MAX
#   define ACE_WAIT_FAILED LONG_MAX
#   define ACE_WAIT_TIMEOUT LONG_MAX
# endif /* ACE_HAS_WIN32_OVERLAPPED_IO */

// Forward declarations
class ACE_Proactor;
class ACE_Handler;
class ACE_Message_Block;
class ACE_INET_Addr;
class ACE_Addr;

// Forward declarations
class ACE_Asynch_Result_Impl;
class ACE_Time_Value;

/**
 * @class ACE_Asynch_Result
 *
 * @brief An interface base class which allows users access to common
 * information related to an asynchronous operation.
 *
 * An interface base class from which you can obtain some basic
 * information like the number of bytes transferred, the ACT
 * associated with the asynchronous operation, indication of
 * success or failure, etc. Subclasses may want to store more
 * information that is particular to the asynchronous operation
 * it represents.
 */
class ACE_Export ACE_Asynch_Result
{

public:
  /// Number of bytes transferred by the operation.
  size_t bytes_transferred (void) const;

  /// ACT associated with the operation.
  const void *act (void) const;

  /// Did the operation succeed?
  int success (void) const;

  /**
   * This is the ACT associated with the handle on which the
   * Asynch_Operation takes place.
   *
   * On WIN32, this returns the ACT associated with the handle when it
   * was registered with the I/O completion port.
   *
   * @@ This is not implemented for POSIX4 platforms. Returns 0.
   */
  const void *completion_key (void) const;

  /// Error value if the operation fails.
  unsigned long error (void) const;

  /**
   * On WIN32, this returns the event associated with the OVERLAPPED
   * structure.
   *
   * This returns ACE_INVALID_HANDLE on POSIX4-Unix platforms.
   */
  ACE_HANDLE event (void) const;

  /**
   * This really makes sense only when doing file I/O.
   *
   * On WIN32, these are represented in the OVERLAPPED datastructure.
   *
   * @@ On POSIX4-Unix, offset_high should be supported using
   *    aiocb64.
   */
  unsigned long offset (void) const;
  unsigned long offset_high (void) const;

  /**
   * Priority of the operation.
   *
   * On POSIX4-Unix, this is supported. Priority works like {nice} in
   * Unix. Negative values are not allowed. 0 means priority of the
   * operation same as the process priority. 1 means priority of the
   * operation is one less than process. And so forth.
   *
   * On Win32, this is a no-op.
   */
  int priority (void) const;

  /**
   * POSIX4 real-time signal number to be used for the
   * operation. {signal_number} ranges from ACE_SIGRTMIN to ACE_SIGRTMAX. By
   * default, ACE_SIGRTMIN is used to issue {aio_} calls. This is a no-op
   * on non-POSIX4 systems and returns 0.
   */
  int signal_number (void) const;


  /// Destructor.
  virtual ~ACE_Asynch_Result (void);

protected:
  /// Constructor. This implementation will not be deleted.  The
  /// implementation will be deleted by the Proactor.
  ACE_Asynch_Result (ACE_Asynch_Result_Impl *implementation);

  /// Get the implementation class.
  ACE_Asynch_Result_Impl *implementation (void) const;

  /// Implementation class.
  ACE_Asynch_Result_Impl *implementation_;
};

// Forward declarations
class ACE_Asynch_Operation_Impl;

/**
 * @class ACE_Asynch_Operation
 *
 * @brief This is an interface base class for all asynch
 * operations. The resposiblility of this class is to forward
 * all methods to its delegation/implementation class, e.g.,
 * ACE_WIN32_Asynch_Operation or ACE_POSIX_Asynch_Operation.
 *
 * There are some attributes and functionality which is common
 * to all asychronous operations. The delegation classes of this
 * class will factor out this code.
 */
class ACE_Export ACE_Asynch_Operation
{

public:
  /**
   * Initializes the factory with information which will be used with
   * each asynchronous call.  If ({handle} == ACE_INVALID_HANDLE),
   * {ACE_Handler::handle} will be called on the {handler} to get the
   * correct handle.
   */
  int open (ACE_Handler &handler,
            ACE_HANDLE handle,
            const void *completion_key,
            ACE_Proactor *proactor);

  /**
   * (Attempts to) cancel the asynchronous operation pending against
   * the {handle} registered with this Operation.
   *
   * All completion notifications for the I/O operations will occur
   * normally.
   *
   * = Return Values:
   *
   * -1 : Operation failed. (can get only in POSIX).
   *  0 : All the operations were cancelled.
   *  1 : All the operations were already finished in this
   *      handle. Unable to cancel them.
   *  2 : Atleast one of the requested operations cannot be
   *      cancelled.
   *
   * There is slight difference in the semantics between NT and POSIX
   * platforms which is given below.
   *
   * = Win32 :
   *
   *   cancels all pending accepts operations that were issued by the
   *   calling thread.  The function does not cancel asynchronous
   *   operations issued by other threads.
   *   All I/O operations that are canceled will complete with the
   *   error ERROR_OPERATION_ABORTED.
   *
   * = POSIX:
   *
   *   Attempts to cancel one or more asynchronous I/O requests
   *   currently outstanding against the {handle} registered in this
   *   operation.
   *   For requested operations that are successfully canceled, the
   *   associated  error  status is set to ECANCELED.
   */
  int cancel (void);


  // = Access methods.

  /// Return the underlying proactor.
  ACE_Proactor* proactor (void) const;

  /// Destructor.
  virtual ~ACE_Asynch_Operation (void);

protected:
  /// Constructor.
  ACE_Asynch_Operation (void);

  /// Return the underlying implementation class.
  virtual ACE_Asynch_Operation_Impl *implementation (void) const = 0;

  /// Get a proactor for/from the user
  ACE_Proactor *get_proactor (ACE_Proactor *user_proactor,
                              ACE_Handler &handler) const;
};

// Forward declarations
class ACE_Asynch_Read_Stream_Result_Impl;
class ACE_Asynch_Read_Stream_Impl;

/**
 * @class ACE_Asynch_Read_Stream
 *
 * @brief This class is a factory for starting off asynchronous reads
 * on a stream. This class forwards all methods to its
 * implementation class.
 *
 * Once {open} is called, multiple asynchronous {read}s can
 * started using this class.  An ACE_Asynch_Read_Stream::Result
 * will be passed back to the {handler} when the asynchronous
 * reads completes through the {ACE_Handler::handle_read_stream}
 * callback.
 */
class ACE_Export ACE_Asynch_Read_Stream : public ACE_Asynch_Operation
{

public:
  /// A do nothing constructor.
  ACE_Asynch_Read_Stream (void);

  /// Destructor
  virtual ~ACE_Asynch_Read_Stream (void);

  /**
   * Initializes the factory with information which will be used with
   * each asynchronous call.
   *
   * @param handler The ACE_Handler that will be called to handle completions
   *                for operations initiated using this factory.
   * @param handle  The handle that future read operations will use.
   *                If handle == @c ACE_INVALID_HANDLE,
   *                ACE_Handler::handle() will be called on @ handler
   *                to get the correct handle.
   *
   * @retval 0    for success.
   * @retval -1   for failure; consult @c errno for further information.
   */
  int open (ACE_Handler &handler,
            ACE_HANDLE handle = ACE_INVALID_HANDLE,
            const void *completion_key = 0,
            ACE_Proactor *proactor = 0);

  /**
   * Initiate an asynchronous read operation.
   *
   * @param message_block      The ACE_Message_Block to receive the data.
   *                           Received bytes will be placed in the block
   *                           beginning at its current write pointer.
   *                           If data is read, the message block's write
   *                           pointer will be advanced by the number of
   *                           bytes read.
   * @param num_bytes_to_read  The maximum number of bytes to read.
   * @param act                Asynchronous Completion Token; passed through to
   *                           the completion handler in the Result object.
   * @param priority           Priority of the operation. On POSIX4-Unix,
   *                           this is supported. Works like @c nice in Unix.
   *                           Negative values are not allowed. 0 means
   *                           priority of the operation same as the process
   *                           priority. 1 means priority of the operation is
   *                           one less than process priority, etc.
   *                           Ignored on Windows.
   * @param signal_number      The POSIX4 real-time signal number to be used
   *                           to signal completion of the operation. Values
   *                           range from ACE_SIGRTMIN to ACE_SIGRTMAX.
   *                           This argument is ignored on non-POSIX4 systems.
   */
  int read (ACE_Message_Block &message_block,
            size_t num_bytes_to_read,
            const void *act = 0,
            int priority = 0,
            int signal_number = ACE_SIGRTMIN);

#if defined (ACE_HAS_WIN32_OVERLAPPED_IO)
  /**
  * Same as above but with scatter support, through chaining of composite
  * message blocks using the continuation field.
  */
  int readv (ACE_Message_Block &message_block,
             size_t num_bytes_to_read,
             const void *act = 0,
             int priority = 0,
             int signal_number = ACE_SIGRTMIN);
#endif /* defined (ACE_HAS_WIN32_OVERLAPPED_IO) */

  /// Return the underlying implementation class.
  //  (this should be protected...)
  virtual ACE_Asynch_Operation_Impl *implementation (void) const;

protected:
  /// Implementation class that all methods will be forwarded to.
  ACE_Asynch_Read_Stream_Impl *implementation_;

public:
/**
 * @class Result
 *
 * @brief This is the class which will be passed back to the
 * ACE_Handler::handle_read_stream when the asynchronous read completes.
 * This class forwards all the methods to the implementation classes.
 *
 * This class has all the information necessary for the
 * handler to uniquiely identify the completion of the
 * asynchronous read.
 */
  class ACE_Export Result : public ACE_Asynch_Result
  {

    /// The concrete implementation result classes only construct this
    /// class.
    friend class ACE_POSIX_Asynch_Read_Stream_Result;
    friend class ACE_WIN32_Asynch_Read_Stream_Result;

  public:
    /// The number of bytes which were requested at the start of the
    /// asynchronous read.
    size_t bytes_to_read (void) const;

    /// Message block which contains the read data.
    ACE_Message_Block &message_block (void) const;

    /// I/O handle used for reading.
    ACE_HANDLE handle (void) const;

    /// Get the implementation class.
    ACE_Asynch_Read_Stream_Result_Impl *implementation (void) const;

  protected:
    /// Constructor.
    Result (ACE_Asynch_Read_Stream_Result_Impl *implementation);

    /// Destructor.
    virtual ~Result (void);

    /// The implementation class.
    ACE_Asynch_Read_Stream_Result_Impl *implementation_;
  };
private:
  ACE_UNIMPLEMENTED_FUNC (void operator= (const ACE_Asynch_Read_Stream &))
  ACE_UNIMPLEMENTED_FUNC (ACE_Asynch_Read_Stream (const ACE_Asynch_Read_Stream &))
};

// Forward declarations
class ACE_Asynch_Write_Stream_Impl;
class ACE_Asynch_Write_Stream_Result_Impl;

/**
 * @class ACE_Asynch_Write_Stream
 *
 * @brief This class is a factory for initiating asynchronous writes
 * on a connected TCP/IP stream. This class forwards all methods to its
 * implementation class.
 *
 * Once open() is called, multiple asynchronous writes can be
 * started using this class.  An ACE_Asynch_Write_Stream::Result
 * will be passed to the ACE_Handler::handle_write_stream() method on the
 * opened ACE_Handler object when the asynchronous write completes.
 */
class ACE_Export ACE_Asynch_Write_Stream : public ACE_Asynch_Operation
{

public:
  /// A do nothing constructor.
  ACE_Asynch_Write_Stream (void);

  /// Destructor.
  virtual ~ACE_Asynch_Write_Stream (void);

  /**
   * Initializes the factory with information which will be used with
   * each asynchronous operation.
   *
   * @param handler        ACE_Handler to be notified when operations initiated
   *                       via this factory complete. The handle_write_stream()
   *                       method will be called on this object.
   * @param handle         The socket handle to initiate write operations on.
   *                       If handle is @c ACE_INVALID_HANDLE,
   *                       ACE_Handler::handle() will be called on handler to
   *                       get the handle value.
   * @param completion_key A token that is passed to the completion handler.
   * @param proactor       The ACE_Proactor object which will control operation
   *                       completion and dispatching the results to handler.
   *                       If this is 0, the process's singleton ACE_Proactor
   *                       will be used.
   *
   * @retval 0    for success.
   * @retval -1   for failure; consult @c errno for further information.
   */
  int open (ACE_Handler &handler,
            ACE_HANDLE handle = ACE_INVALID_HANDLE,
            const void *completion_key = 0,
            ACE_Proactor *proactor = 0);

  /**
   * Initiates an asynchronous write on a socket. If the operation completes
   * the ACE_Handler object registered in open() will receive a completion
   * callback via its handle_write_stream() method.
   *
   * @param bytes_to_write   The number of bytes to write.
   * @param message_block    The ACE_Message_Block containing data to write.
   *                         Data is written to the socket beginning at the
   *                         block's rd_ptr. Upon successful completion
   *                         of the write operation, the message_block rd_ptr
   *                         is updated to reflect the data that was written.
   * @param act              Token that is passed through to the completion
   *                         handler.
   * @param priority         Priority of the operation. This argument only has
   *                         an affect on POSIX4-Unix. Works like @c nice in
   *                         Unix; negative values are not allowed. 0 means
   *                         priority of the operation same as the process
   *                         priority. 1 means priority of the operation is one
   *                         less than the process, and so forth.
   * @param signal_number    The POSIX4 real-time signal number to be used
   *                         for the operation. signal_number ranges from
   *                         ACE_SIGRTMIN to ACE_SIGRTMAX. This argument is
   *                         not used on other platforms.
   *
   * @retval 0    for success, and the handle_write_stream associated
   *              with the opened ACE_Handler will be called. An
   *              instance of ACE_Asynch_Write_Stream::Result will be
   *              passed to the completion handler.
   * @retval -1   for failure; consult @c errno for further information.
   */
  int write (ACE_Message_Block &message_block,
             size_t bytes_to_write,
             const void *act = 0,
             int priority = 0,
             int signal_number = ACE_SIGRTMIN);

#if defined (ACE_HAS_WIN32_OVERLAPPED_IO)
  /**
  * Same as above but with gather support, through chaining of composite
  * message blocks using the continuation field.
  */
  int writev (ACE_Message_Block &message_block,
              size_t bytes_to_write,
              const void *act = 0,
              int priority = 0,
              int signal_number = ACE_SIGRTMIN);
#endif /* defined (ACE_HAS_WIN32_OVERLAPPED_IO) */

  /// Return the underlying implementation class.
  /// @todo (this should be protected...)
  virtual ACE_Asynch_Operation_Impl *implementation (void) const;

protected:
  /// Implementation class that all methods will be forwarded to.
  ACE_Asynch_Write_Stream_Impl *implementation_;

public:
/**
 * @class Result
 *
 * @brief This is that class which will be passed back to the
 * ACE_Handler when the asynchronous write completes. This class
 * forwards all the methods to the implementation class.
 *
 * This class has all the information necessary for the
 * handler to uniquiely identify the completion of the
 * asynchronous write.
 */
  class ACE_Export Result : public ACE_Asynch_Result
  {

    /// The concrete implementation result classes only construct this
    /// class.
    friend class ACE_POSIX_Asynch_Write_Stream_Result;
    friend class ACE_WIN32_Asynch_Write_Stream_Result;

  public:
    /// The number of bytes which were requested at the start of the
    /// asynchronous write.
    size_t bytes_to_write (void) const;

    /// Message block that contains the data to be written.
    ACE_Message_Block &message_block (void) const;

    /// I/O handle used for writing.
    ACE_HANDLE handle (void) const;

    /// Get the implementation class.
    ACE_Asynch_Write_Stream_Result_Impl *implementation (void) const;

  protected:
    /// Constructor.
    Result (ACE_Asynch_Write_Stream_Result_Impl *implementation);

    /// Destructor.
    virtual ~Result (void);

    /// Implementation class.
    ACE_Asynch_Write_Stream_Result_Impl *implementation_;
  };
private:
  ACE_UNIMPLEMENTED_FUNC (void operator= (const ACE_Asynch_Write_Stream &))
  ACE_UNIMPLEMENTED_FUNC (ACE_Asynch_Write_Stream (const ACE_Asynch_Write_Stream &))
};

// Forward declarations
class ACE_Asynch_Read_File_Impl;
class ACE_Asynch_Read_File_Result_Impl;

/**
 * @class ACE_Asynch_Read_File
 *
 * @brief This class is a factory for starting off asynchronous reads
 * on a file. This class forwards all methods to its
 * implementation class.
 *
 * Once open() is called, multiple asynchronous reads can
 * started using this class. An ACE_Asynch_Read_File::Result
 * will be passed back to the completion handler's
 * ACE_Handler::handle_read_file() method when each asynchronous
 * read completes.
 * This class differs slightly from ACE_Asynch_Read_Stream as it
 * allows the user to specify an offset for the read.
 */
class ACE_Export ACE_Asynch_Read_File : public ACE_Asynch_Read_Stream
{

public:
  /// A do nothing constructor.
  ACE_Asynch_Read_File (void);

  /// Destructor.
  virtual ~ACE_Asynch_Read_File (void);

  /**
   * Initializes the factory with information which will be used with
   * each asynchronous operation.
   *
   * @param handler        ACE_Handler to be notified when operations initiated
   *                       via this factory complete. The
   *                       ACE_Handler::handle_read_file() method will be
   *                       called on this object.
   * @param handle         The file handle to initiate read operations on.
   *                       If handle is @c ACE_INVALID_HANDLE,
   *                       ACE_Handler::handle() will be called on handler to
   *                       get the handle value.
   * @param completion_key A token that is passed to the completion handler.
   * @param proactor       The ACE_Proactor object which will control operation
   *                       completion and dispatching the results to handler.
   *                       If this is 0, the process's singleton ACE_Proactor
   *                       will be used.
   *
   * @retval 0    for success.
   * @retval -1   for failure; consult @c errno for further information.
   */
  int open (ACE_Handler &handler,
            ACE_HANDLE handle = ACE_INVALID_HANDLE,
            const void *completion_key = 0,
            ACE_Proactor *proactor = 0);

  /**
   * This starts off an asynchronous read.  Upto {bytes_to_read} will
   * be read and stored in the {message_block}.  The read will start
   * at {offset} from the beginning of the file. Priority of the
   * operation is specified by {priority}. On POSIX4-Unix, this is
   * supported. Works like {nice} in Unix. Negative values are not
   * allowed. 0 means priority of the operation same as the process
   * priority. 1 means priority of the operation is one less than
   * process. And so forth. On Win32, this argument is a no-op.
   * {signal_number} is the POSIX4 real-time signal number to be used
   * for the operation. {signal_number} ranges from ACE_SIGRTMIN to
   * ACE_SIGRTMAX. This argument is a no-op on non-POSIX4 systems.
   */
  int read (ACE_Message_Block &message_block,
            size_t bytes_to_read,
            unsigned long offset = 0,
            unsigned long offset_high = 0,
            const void *act = 0,
            int priority = 0,
            int signal_number = ACE_SIGRTMIN);

#if (defined (ACE_WIN32) && !defined (ACE_HAS_WINCE))
  /**
  * Same as above but with scatter support, through chaining of composite
  * message blocks using the continuation field.
  * @note In win32 Each data block payload must be at least the size of a system
  * memory page and must be aligned on a system memory page size boundary
  */
  int readv (ACE_Message_Block &message_block,
             size_t bytes_to_read,
             unsigned long offset = 0,
             unsigned long offset_high = 0,
             const void *act = 0,
             int priority = 0,
             int signal_number = ACE_SIGRTMIN);
#endif /* (defined (ACE_WIN32) && !defined (ACE_HAS_WINCE)) */

  /// Return the underlying implementation class.
  //  (this should be protected...)
  virtual ACE_Asynch_Operation_Impl *implementation (void) const;

protected:
  /// Delegation/implementation class that all methods will be
  /// forwarded to.
  ACE_Asynch_Read_File_Impl *implementation_;

public:
/**
 * @class Result
 *
 * @brief This is that class which will be passed back to the
 * {handler} when the asynchronous read completes. This class
 * forwards all the methods to the implementation class.
 *
 * This class has all the information necessary for the
 * {handler} to uniquiely identify the completion of the
 * asynchronous read.
 * This class differs slightly from
 * ACE_Asynch_Read_Stream::Result as it calls back
 * {ACE_Handler::handle_read_file} on the {handler} instead of
 * {ACE_Handler::handle_read_stream}.  No additional state is
 * required by this class as ACE_Asynch_Result can store the
 * {offset}.
 */
  class ACE_Export Result : public ACE_Asynch_Read_Stream::Result
  {

    /// The concrete implementation result classes only construct this
    /// class.
    friend class ACE_POSIX_Asynch_Read_File_Result;
    friend class ACE_WIN32_Asynch_Read_File_Result;

  public:
    /// Get the implementation class.
    ACE_Asynch_Read_File_Result_Impl *implementation (void) const;

  protected:
    /// Constructor. This implementation will not be deleted.
    Result (ACE_Asynch_Read_File_Result_Impl *implementation);

    /// Destructor.
    virtual ~Result (void);

    /// The implementation class.
    ACE_Asynch_Read_File_Result_Impl *implementation_;

  private:
    /// Here just to provide an dummpy implementation, since the
    /// one auto generated by MSVC is flagged as infinitely recursive
    void operator= (Result &) {}
  };
private:
  ACE_UNIMPLEMENTED_FUNC (void operator= (const ACE_Asynch_Read_File &))
  ACE_UNIMPLEMENTED_FUNC (ACE_Asynch_Read_File (const ACE_Asynch_Read_File &))
};

// Forward declarations
class ACE_Asynch_Write_File_Impl;
class ACE_Asynch_Write_File_Result_Impl;

/**
 * @class ACE_Asynch_Write_File
 *
 * @brief This class is a factory for starting off asynchronous writes
 * on a file. This class forwards all methods to its
 * implementation class.
 *
 * Once {open} is called, multiple asynchronous {write}s can be
 * started using this class.  A ACE_Asynch_Write_File::Result
 * will be passed back to the {handler} when the asynchronous
 * writes completes through the {ACE_Handler::handle_write_file}
 * callback.
 * This class differs slightly from ACE_Asynch_Write_Stream as
 * it allows the user to specify an offset for the write.
 */
class ACE_Export ACE_Asynch_Write_File : public ACE_Asynch_Write_Stream
{

public:
  /// A do nothing constructor.
  ACE_Asynch_Write_File (void);

  /// Destructor.
  virtual ~ACE_Asynch_Write_File (void);

  /**
   * Initializes the factory with information which will be used with
   * each asynchronous call. If ({handle} == ACE_INVALID_HANDLE),
   * {ACE_Handler::handle} will be called on the {handler} to get the
   * correct handle.
   */
  int open (ACE_Handler &handler,
            ACE_HANDLE handle = ACE_INVALID_HANDLE,
            const void *completion_key = 0,
            ACE_Proactor *proactor = 0);

  /**
   * This starts off an asynchronous write.  Upto {bytes_to_write}
   * will be written from the {message_block}, starting at the
   * block's {rd_ptr}.  The write will go to the file, starting
   * {offset} bytes from the beginning of the file. Priority of the
   * operation is specified by {priority}. On POSIX4-Unix, this is
   * supported. Works like {nice} in Unix. Negative values are not
   * allowed. 0 means priority of the operation same as the process
   * priority. 1 means priority of the operation is one less than
   * process. And so forth. On Win32, this is a no-op.
   * {signal_number} is the POSIX4 real-time signal number to be used
   * for the operation. {signal_number} ranges from ACE_SIGRTMIN to
   * ACE_SIGRTMAX. This argument is a no-op on non-POSIX4 systems.
   */
  int write (ACE_Message_Block &message_block,
             size_t bytes_to_write,
             unsigned long offset = 0,
             unsigned long offset_high = 0,
             const void *act = 0,
             int priority = 0,
             int signal_number = ACE_SIGRTMIN);

#if (defined (ACE_WIN32) && !defined (ACE_HAS_WINCE))
  /**
  * Same as above but with gather support, through chaining of composite
  * message blocks using the continuation field.
  * @note In win32 Each data block payload must be at least the size of a system
  * memory page and must be aligned on a system memory page size boundary
  */
  int writev (ACE_Message_Block &message_block,
              size_t bytes_to_write,
              unsigned long offset = 0,
              unsigned long offset_high = 0,
              const void *act = 0,
              int priority = 0,
              int signal_number = ACE_SIGRTMIN);
#endif /* (defined (ACE_WIN32) && !defined (ACE_HAS_WINCE)) */

  /// Return the underlying implementation class.
  //  (this should be protected...)
  virtual ACE_Asynch_Operation_Impl *implementation (void) const;

protected:
  /// Implementation object.
  ACE_Asynch_Write_File_Impl *implementation_;

public:
/**
 * @class Result
 *
 * @brief This is that class which will be passed back to the
 * {handler} when the asynchronous write completes. This class
 * forwards all the methods to the implementation class.
 *
 * This class has all the information necessary for the
 * {handler} to uniquiely identify the completion of the
 * asynchronous write.
 * This class differs slightly from
 * ACE_Asynch_Write_Stream::Result as it calls back
 * {ACE_Handler::handle_write_file} on the {handler} instead
 * of {ACE_Handler::handle_write_stream}.  No additional state
 * is required by this class as ACE_Asynch_Result can store
 * the {offset}.
 */
  class ACE_Export Result : public ACE_Asynch_Write_Stream::Result
  {

    /// The concrete implementation result classes only construct this
    /// class.
    friend class ACE_POSIX_Asynch_Write_File_Result;
    friend class ACE_WIN32_Asynch_Write_File_Result;

  public:
    ///  Get the implementation class.
    ACE_Asynch_Write_File_Result_Impl *implementation (void) const;

  protected:
    /// Constructor. This implementation will not be deleted.
    Result (ACE_Asynch_Write_File_Result_Impl *implementation);

    /// Destructor.
    virtual ~Result (void);

    /// The implementation class.
    ACE_Asynch_Write_File_Result_Impl *implementation_;

  private:
    /// Here just to provide an dummpy implementation, since the
    /// one auto generated by MSVC is flagged as infinitely recursive
    void operator= (Result &) {};
  };
private:
  ACE_UNIMPLEMENTED_FUNC (void operator= (const ACE_Asynch_Write_File &))
  ACE_UNIMPLEMENTED_FUNC (ACE_Asynch_Write_File (const ACE_Asynch_Write_File &))
};

// Forward declarations
class ACE_Asynch_Accept_Result_Impl;
class ACE_Asynch_Accept_Impl;

/**
 * @class ACE_Asynch_Accept
 *
 * @brief This class is a factory for starting off asynchronous accepts
 * on a listen handle. This class forwards all methods to its
 * implementation class.
 *
 * Once {open} is called, multiple asynchronous {accept}s can
 * started using this class.  A ACE_Asynch_Accept::Result will
 * be passed back to the {handler} when the asynchronous accept
 * completes through the {ACE_Handler::handle_accept}
 * callback.
 */
class ACE_Export ACE_Asynch_Accept : public ACE_Asynch_Operation
{

public:
  /// A do nothing constructor.
  ACE_Asynch_Accept (void);

  /// Destructor.
  virtual ~ACE_Asynch_Accept (void);

  /**
   * Initializes the factory with information which will be used with
   * each asynchronous call. If ({handle} == ACE_INVALID_HANDLE),
   * {ACE_Handler::handle} will be called on the {handler} to get the
   * correct handle.
   */
  int open (ACE_Handler &handler,
            ACE_HANDLE handle = ACE_INVALID_HANDLE,
            const void *completion_key = 0,
            ACE_Proactor *proactor = 0);

  /**
   * This starts off an asynchronous accept.  The asynchronous accept
   * call also allows any initial data to be returned to the
   * handler specified to @c open().
   *   @param message_block   A message block to receive initial data, as well
   *                          as the local and remote addresses when the
   *                          connection is made. Since the block receives
   *                          the addresses regardless of whether or not
   *                          initial data is available or requested, the
   *                          message block size must be at least
   *                          @a bytes_to_read plus two times the size of
   *                          the addresses used (IPv4 or IPv6).
   *   @param bytes_to_read   The maximum number of bytes of initial data
   *                          to read into @a message_block.
   *   @param accept_handle   The handle that the new connection will be
   *                          accepted on. If @c INVALID_HANDLE, a new
   *                          handle will be created using @a addr_family.
   *   @param act             Value to be passed in result when operation
   *                          completes.
   *   @param priority        Priority of the operation. On POSIX4-Unix, this
   *                          is supported. Works like @c nice in Unix.
   *                          Negative values are not allowed. 0 means
   *                          priority of the operation same as the process
   *                          priority. 1 means priority of the operation is
   *                          one less than process. And so forth.
   *                          On Win32, this argument is ignored.
   *   @param signal_number   The POSIX4 real-time signal number to be used
   *                          for the operation. Value range is from
   *                          @c ACE_SIGRTMIN to @c ACE_SIGRTMAX.
   *                          This argument is ignored on non-POSIX4 systems.
   *   @param addr_family     The address family to use if @a accept_handle
   *                          is @c ACE_INVALID_HANDLE and a new handle must
   *                          be opened. Values are @c AF_INET and @c PF_INET6.
   */
  int accept (ACE_Message_Block &message_block,
              size_t bytes_to_read,
              ACE_HANDLE accept_handle = ACE_INVALID_HANDLE,
              const void *act = 0,
              int priority = 0,
              int signal_number = ACE_SIGRTMIN,
              int addr_family = AF_INET);

  /// Return the underlying implementation class.
  //  (this should be protected...)
  virtual ACE_Asynch_Operation_Impl *implementation (void) const;

protected:
  /// Delegation/implementation class that all methods will be
  /// forwarded to.
  ACE_Asynch_Accept_Impl *implementation_;

public:
/**
 * @class Result
 *
 * @brief This is that class which will be passed back to the
 * {handler} when the asynchronous accept completes.
 *
 * This class has all the information necessary for the
 * {handler} to uniquiely identify the completion of the
 * asynchronous accept.
 */
  class ACE_Export Result : public ACE_Asynch_Result
  {

    /// The concrete implementation result classes only construct this
    /// class.
    friend class ACE_POSIX_Asynch_Accept_Result;
    friend class ACE_WIN32_Asynch_Accept_Result;

  public:
    /// The number of bytes which were requested at the start of the
    /// asynchronous accept.
    size_t bytes_to_read (void) const;

    /// Message block which contains the read data.
    ACE_Message_Block &message_block (void) const;

    /// I/O handle used for accepting new connections.
    ACE_HANDLE listen_handle (void) const;

    /// I/O handle for the new connection.
    ACE_HANDLE accept_handle (void) const;

    /// Get the implementation.
    ACE_Asynch_Accept_Result_Impl *implementation (void) const;

  protected:
    /// Contructor. Implementation will not be deleted.
    Result (ACE_Asynch_Accept_Result_Impl *implementation);

    /// Destructor.
    virtual ~Result (void);

    /// Impelmentation class.
    ACE_Asynch_Accept_Result_Impl *implementation_;
  };
private:
  ACE_UNIMPLEMENTED_FUNC (void operator= (const ACE_Asynch_Accept &))
  ACE_UNIMPLEMENTED_FUNC (ACE_Asynch_Accept (const ACE_Asynch_Accept &))
};
// Forward declarations
class ACE_Asynch_Connect_Result_Impl;
class ACE_Asynch_Connect_Impl;

/**
 * @class ACE_Asynch_Connect
 *
 * @brief This class is a factory for starting off asynchronous connects
 * This class forwards all methods to its implementation class.
 *
 * Once @c open is called, multiple asynchronous connect operationss can
 * started using this class.  A ACE_Asynch_Connect::Result will
 * be passed back to the associated ACE_Handler when the asynchronous connect
 * completes through the ACE_Handler::handle_connect() callback.
 */
class ACE_Export ACE_Asynch_Connect : public ACE_Asynch_Operation
{

public:
  /// A do nothing constructor.
  ACE_Asynch_Connect (void);

  /// Destructor.
  virtual ~ACE_Asynch_Connect (void);

  /**
   * Initializes the factory with information which will be used with
   * each asynchronous call.
   *
   * @note @arg handle is ignored and should be @c ACE_INVALID_HANDLE.
   */
  int open (ACE_Handler &handler,
            ACE_HANDLE handle = ACE_INVALID_HANDLE,
            const void *completion_key = 0,
            ACE_Proactor *proactor = 0);

  /**
   * This starts off an asynchronous Connect.
   */
  int connect (ACE_HANDLE connect_handle,
               const ACE_Addr & remote_sap,
               const ACE_Addr & local_sap,
               int  reuse_addr,
               const void *act=0,
               int priority = 0,
               int signal_number = ACE_SIGRTMIN);

  /// Return the underlying implementation class.
  //  (this should be protected...)
  virtual ACE_Asynch_Operation_Impl *implementation (void) const;

protected:
  /// Delegation/implementation class that all methods will be
  /// forwarded to.
  ACE_Asynch_Connect_Impl *implementation_;

public:
/**
 * @class Result
 *
 * @brief This is that class which will be passed back to the
 * handler when the asynchronous connect completes.
 *
 * This class has all the information necessary for the
 * handler to uniquely identify the completion of the
 * asynchronous connect.
 */
  class ACE_Export Result : public ACE_Asynch_Result
  {

    /// The concrete implementation result classes only construct this
    /// class.
    friend class ACE_POSIX_Asynch_Connect_Result;
    friend class ACE_WIN32_Asynch_Connect_Result;

  public:

    /// I/O handle for the  connection.
    ACE_HANDLE connect_handle (void) const;

    /// Get the implementation.
    ACE_Asynch_Connect_Result_Impl *implementation (void) const;

  protected:
    /// Contructor. Implementation will not be deleted.
    Result (ACE_Asynch_Connect_Result_Impl *implementation);

    /// Destructor.
    virtual ~Result (void);

    /// Impelmentation class.
    ACE_Asynch_Connect_Result_Impl *implementation_;
  };
private:
  ACE_UNIMPLEMENTED_FUNC (void operator= (const ACE_Asynch_Connect &))
  ACE_UNIMPLEMENTED_FUNC (ACE_Asynch_Connect (const ACE_Asynch_Connect &))
};

// Forward declarations
class ACE_Asynch_Transmit_File_Result_Impl;
class ACE_Asynch_Transmit_File_Impl;

/**
 * @class ACE_Asynch_Transmit_File
 *
 * @brief This class is a factory for starting off asynchronous
 * transmit files on a stream.
 *
 * Once {open} is called, multiple asynchronous {transmit_file}s
 * can started using this class.  A
 * ACE_Asynch_Transmit_File::Result will be passed back to the
 * {handler} when the asynchronous transmit file completes
 * through the {ACE_Handler::handle_transmit_file} callback.
 * The transmit_file function transmits file data over a
 * connected network connection. The function uses the operating
 * system's cache manager to retrieve the file data. This
 * function provides high-performance file data transfer over
 * network connections.  This function would be of great use in
 * a Web Server, Image Server, etc.
 */
class ACE_Export ACE_Asynch_Transmit_File : public ACE_Asynch_Operation
{

public:
  // Forward declarations
  class Header_And_Trailer;

  /// A do nothing constructor.
  ACE_Asynch_Transmit_File (void);

  /// Destructor.
  virtual ~ACE_Asynch_Transmit_File (void);

  /**
   * Initializes the factory with information which will be used with
   * each asynchronous call. If ({handle} == ACE_INVALID_HANDLE),
   * {ACE_Handler::handle} will be called on the {handler} to get the
   * correct handle.
   */
  int open (ACE_Handler &handler,
            ACE_HANDLE handle = ACE_INVALID_HANDLE,
            const void *completion_key = 0,
            ACE_Proactor *proactor = 0);

  /**
   * This starts off an asynchronous transmit file.  The {file} is a
   * handle to an open file.  {header_and_trailer} is a pointer to a
   * data structure that contains pointers to data to send before and
   * after the file data is sent.  Set this parameter to 0 if you only
   * want to transmit the file data.  Upto {bytes_to_write} will be
   * written to the {socket}.  If you want to send the entire file,
   * let {bytes_to_write} = 0.  {bytes_per_send} is the size of each
   * block of data sent per send operation.  Please read the Win32
   * documentation on what the flags should be. Priority of the
   * operation is specified by {priority}. On POSIX4-Unix, this is
   * supported. Works like {nice} in Unix. Negative values are not
   * allowed. 0 means priority of the operation same as the process
   * priority. 1 means priority of the operation is one less than
   * process. And so forth. On Win32, this is a no-op.
   * {signal_number} is the POSIX4 real-time signal number to be used
   * for the operation. {signal_number} ranges from ACE_SIGRTMIN to
   * ACE_SIGRTMAX. This argument is a no-op on non-POSIX4 systems.
   */
  int transmit_file (ACE_HANDLE file,
                     Header_And_Trailer *header_and_trailer = 0,
                     size_t bytes_to_write = 0,
                     unsigned long offset = 0,
                     unsigned long offset_high = 0,
                     size_t bytes_per_send = 0,
                     unsigned long flags = 0,
                     const void *act = 0,
                     int priority = 0,
                     int signal_number = ACE_SIGRTMIN);

  /// Return the underlying implementation class.
  //  (this should be protected...)
  virtual ACE_Asynch_Operation_Impl *implementation (void) const;

protected:
  /// The implementation class.
  ACE_Asynch_Transmit_File_Impl *implementation_;

public:
/**
 * @class Result
 *
 * @brief This is that class which will be passed back to the
 * {handler} when the asynchronous transmit file completes.
 *
 * This class has all the information necessary for the
 * {handler} to uniquiely identify the completion of the
 * asynchronous transmit file.
 */
  class ACE_Export Result : public ACE_Asynch_Result
  {

    /// The concrete implementation result classes only construct this
    /// class.
    friend class ACE_POSIX_Asynch_Transmit_File_Result;
    friend class ACE_WIN32_Asynch_Transmit_File_Result;

  public:
    /// Socket used for transmitting the file.
    ACE_HANDLE socket (void) const;

    /// File from which the data is read.
    ACE_HANDLE file (void) const;

    /// Header and trailer data associated with this transmit file.
    Header_And_Trailer *header_and_trailer (void) const;

    /// The number of bytes which were requested at the start of the
    /// asynchronous transmit file.
    size_t bytes_to_write (void) const;

    /// Number of bytes per send requested at the start of the transmit
    /// file.
    size_t bytes_per_send (void) const;

    /// Flags which were passed into transmit file.
    unsigned long flags (void) const;

    /// Get the implementation class.
    ACE_Asynch_Transmit_File_Result_Impl *implementation (void) const;

  protected:
    /// Constructor.
    Result (ACE_Asynch_Transmit_File_Result_Impl *implementation);

    /// Destructor.
    virtual ~Result (void);

    /// The implementation class.
    ACE_Asynch_Transmit_File_Result_Impl *implementation_;
  };

/**
 * @class Header_And_Trailer
 *
 * @brief The class defines a data structure that contains pointers
 * to data to send before and after the file data is sent.
 *
 * This class provides a wrapper over TRANSMIT_FILE_BUFFERS
 * and provided a consistent use of ACE_Message_Blocks.
 */
  class ACE_Export Header_And_Trailer
  {

  public:
    /// Constructor.
    Header_And_Trailer (ACE_Message_Block *header = 0,
                        size_t header_bytes = 0,
                        ACE_Message_Block *trailer = 0,
                        size_t trailer_bytes = 0);

    /// Destructor
    virtual ~Header_And_Trailer (void);

    /// This method allows all the member to be set in one fell swoop.
    void header_and_trailer (ACE_Message_Block *header = 0,
                             size_t header_bytes = 0,
                             ACE_Message_Block *trailer = 0,
                             size_t trailer_bytes = 0);

    /// Get header which goes before the file data.
    ACE_Message_Block *header (void) const;

    /// Set header which goes before the file data.
    void header (ACE_Message_Block *message_block);

    /// Get size of the header data.
    size_t header_bytes (void) const;

    /// Set size of the header data.
    void header_bytes (size_t bytes);

    /// Get trailer which goes after the file data.
    ACE_Message_Block *trailer (void) const;

    /// Set trailer which goes after the file data.
    void trailer (ACE_Message_Block *message_block);

    /// Get size of the trailer data.
    size_t trailer_bytes (void) const;

    /// Set size of the trailer data.
    void trailer_bytes (size_t bytes);

    /// Conversion routine.
    ACE_LPTRANSMIT_FILE_BUFFERS transmit_buffers (void);

  protected:
    /// Header data.
    ACE_Message_Block *header_;

    /// Size of header data.
    size_t header_bytes_;

    /// Trailer data.
    ACE_Message_Block *trailer_;

    /// Size of trailer data.
    size_t trailer_bytes_;

    /// Target data structure.
    ACE_TRANSMIT_FILE_BUFFERS transmit_buffers_;
  };
private:
  ACE_UNIMPLEMENTED_FUNC (void operator= (const ACE_Asynch_Transmit_File &))
  ACE_UNIMPLEMENTED_FUNC (ACE_Asynch_Transmit_File (const ACE_Asynch_Transmit_File &))
};


// Forward declarations
class ACE_Asynch_Read_Dgram_Result_Impl;
class ACE_Asynch_Read_Dgram_Impl;
class ACE_Addr;

/**
 * @class ACE_Asynch_Read_Dgram
 *
 * @brief This class is a factory for starting off asynchronous reads
 * on a UDP socket. This class forwards all methods to its
 * implementation class.
 *
 * Once {open} is called, multiple asynchronous {read}s can be
 * started using this class.  An ACE_Asynch_Read_Dgram::Result
 * will be passed back to the {handler} when the asynchronous
 * reads completes through the {ACE_Handler::handle_read_dgram}
 * callback.
 */
class ACE_Export ACE_Asynch_Read_Dgram : public ACE_Asynch_Operation
{

public:
  /// A do nothing constructor.
  ACE_Asynch_Read_Dgram (void);

  /// Destructor
  virtual ~ACE_Asynch_Read_Dgram (void);

  /**
   * Initializes the factory with information which will be used with
   * each asynchronous call. If ({handle} == ACE_INVALID_HANDLE),
   * {ACE_Handler::handle} will be called on the {handler} to get the
   * correct handle.
   */
  int open (ACE_Handler &handler,
            ACE_HANDLE handle = ACE_INVALID_HANDLE,
            const void *completion_key = 0,
            ACE_Proactor *proactor = 0);

  /** This starts off an asynchronous read.  Upto
   * {message_block->total_size()} will be read and stored in the
   * {message_block}.  {message_block}'s {wr_ptr} will be updated to reflect
   * the added bytes if the read operation is successfully completed.
   * Return code of 1 means immediate success and {number_of_bytes_recvd}
   * will contain number of bytes read.  The {ACE_Handler::handle_read_dgram}
   * method will still be called.  Return code of 0 means the IO will
   * complete proactively.  Return code of -1 means there was an error, use
   * errno to get the error code.
   *
   * Scatter/gather is supported on WIN32 by using the {message_block->cont()}
   * method.  Up to ACE_IOV_MAX {message_block}'s are supported.  Upto
   * {message_block->size()} bytes will be read into each {message block} for
   * a total of {message_block->total_size()} bytes.  All {message_block}'s
   * {wr_ptr}'s will be updated to reflect the added bytes for each
   * {message_block}
   *
   * Priority of the operation is specified by {priority}. On POSIX4-Unix,
   * this is supported. Works like {nice} in Unix. Negative values are not
   * allowed. 0 means priority of the operation same as the process
   * priority. 1 means priority of the operation is one less than
   * process. And so forth. On Win32, {priority} is a no-op.
   * {signal_number} is the POSIX4 real-time signal number to be used
   * for the operation. {signal_number} ranges from ACE_SIGRTMIN to
   * ACE_SIGRTMAX. This argument is a no-op on non-POSIX4 systems.
   */
  ssize_t recv (ACE_Message_Block *message_block,
                size_t &number_of_bytes_recvd,
                int flags,
                int protocol_family = PF_INET,
                const void *act = 0,
                int priority = 0,
                int signal_number = ACE_SIGRTMIN);

  /// Return the underlying implementation class.
  //  (this should be protected...)
  virtual ACE_Asynch_Operation_Impl *implementation (void) const;

protected:
  /// Implementation class that all methods will be forwarded to.
  ACE_Asynch_Read_Dgram_Impl *implementation_;

public:
/**
 * @class Result
 *
 * @brief This is the class which will be passed back to the
 * {handler} when the asynchronous read completes. This class
 * forwards all the methods to the implementation classes.
 *
 * This class has all the information necessary for the
 * {handler} to uniquiely identify the completion of the
 * asynchronous read.
 */
  class ACE_Export Result : public ACE_Asynch_Result
  {

    /// The concrete implementation result classes only construct this
    /// class.
    friend class ACE_POSIX_Asynch_Read_Dgram_Result;
    friend class ACE_WIN32_Asynch_Read_Dgram_Result;

  public:

    /// The number of bytes which were requested at the start of the
    /// asynchronous read.
    size_t bytes_to_read (void) const;

    /// Message block which contains the read data
    ACE_Message_Block *message_block (void) const;

    /// The flags used in the read
    int flags (void) const;

    /// The address of where the packet came from
    int remote_address (ACE_Addr& addr) const;

    /// I/O handle used for reading.
    ACE_HANDLE handle (void) const;

    /// Get the implementation class.
    ACE_Asynch_Read_Dgram_Result_Impl *implementation (void) const;

  protected:
    /// Constructor.
    Result (ACE_Asynch_Read_Dgram_Result_Impl *implementation);

    /// Destructor.
    virtual ~Result (void);

    /// The implementation class.
    ACE_Asynch_Read_Dgram_Result_Impl *implementation_;
  };
private:
  ACE_UNIMPLEMENTED_FUNC (void operator= (const ACE_Asynch_Read_Dgram &))
  ACE_UNIMPLEMENTED_FUNC (ACE_Asynch_Read_Dgram (const ACE_Asynch_Read_Dgram &))
};

// Forward declarations
class ACE_Asynch_Write_Dgram_Impl;
class ACE_Asynch_Write_Dgram_Result_Impl;

/**
 * @class ACE_Asynch_Write_Dgram
 *
 * @brief This class is a factory for starting off asynchronous writes
 * on a UDP socket. This class forwards all methods to its
 * implementation class.
 *
 * Once {open} is called, multiple asynchronous {writes}s can
 * started using this class.  An ACE_Asynch_Write_Dgram::Result
 * will be passed back to the {handler} when the asynchronous
 * write completes through the
 * {ACE_Handler::handle_write_dgram} callback.
 */
class ACE_Export ACE_Asynch_Write_Dgram : public ACE_Asynch_Operation
{

public:
  /// A do nothing constructor.
  ACE_Asynch_Write_Dgram (void);

  /// Destructor.
  virtual ~ACE_Asynch_Write_Dgram (void);

  /**
   * Initializes the factory with information which will be used with
   * each asynchronous call. If ({handle} == ACE_INVALID_HANDLE),
   * {ACE_Handler::handle} will be called on the {handler} to get the
   * correct handle.
   */
  int open (ACE_Handler &handler,
            ACE_HANDLE handle = ACE_INVALID_HANDLE,
            const void *completion_key = 0,
            ACE_Proactor *proactor = 0);

  /** This starts off an asynchronous send.  Upto
   * {message_block->total_length()} will be sent.  {message_block}'s
   * {rd_ptr} will be updated to reflect the sent bytes if the send operation
   * is successfully completed.
   * Return code of 1 means immediate success and {number_of_bytes_sent}
   * is updated to number of bytes sent.  The {ACE_Handler::handle_write_dgram}
   * method will still be called.  Return code of 0 means the IO will
   * complete proactively.  Return code of -1 means there was an error, use
   * errno to get the error code.
   *
   * Scatter/gather is supported on WIN32 by using the {message_block->cont()}
   * method.  Up to ACE_IOV_MAX {message_block}'s are supported.  Upto
   * {message_block->length()} bytes will be sent from each {message block}
   * for a total of {message_block->total_length()} bytes.  All
   * {message_block}'s {rd_ptr}'s will be updated to reflect the bytes sent
   * from each {message_block}.
   *
   * Priority of the operation is specified by {priority}. On POSIX4-Unix,
   * this is supported. Works like {nice} in Unix. Negative values are not
   * allowed. 0 means priority of the operation same as the process
   * priority. 1 means priority of the operation is one less than
   * process. And so forth. On Win32, this argument is a no-op.
   * {signal_number} is the POSIX4 real-time signal number to be used
   * for the operation. {signal_number} ranges from ACE_SIGRTMIN to
   * ACE_SIGRTMAX. This argument is a no-op on non-POSIX4 systems.
   */
  ssize_t send (ACE_Message_Block *message_block,
                size_t &number_of_bytes_sent,
                int flags,
                const ACE_Addr& remote_addr,
                const void *act = 0,
                int priority = 0,
                int signal_number = ACE_SIGRTMIN);

  /// Return the underlying implementation class.
  //  (this should be protected...)
  virtual ACE_Asynch_Operation_Impl *implementation (void) const;

protected:
  /// Implementation class that all methods will be forwarded to.
  ACE_Asynch_Write_Dgram_Impl *implementation_;

public:
/**
 * @class Result
 *
 * @brief This is that class which will be passed back to the
 * {handler} when the asynchronous write completes. This class
 * forwards all the methods to the implementation class.
 *
 * This class has all the information necessary for the
 * {handler} to uniquiely identify the completion of the
 * asynchronous write.
 */
  class ACE_Export Result : public ACE_Asynch_Result
  {

    /// The concrete implementation result classes only construct this
    /// class.
    friend class ACE_POSIX_Asynch_Write_Dgram_Result;
    friend class ACE_WIN32_Asynch_Write_Dgram_Result;

  public:

    /// The number of bytes which were requested at the start of the
    /// asynchronous write.
    size_t bytes_to_write (void) const;

    /// Message block which contains the sent data
    ACE_Message_Block *message_block (void) const;

    /// The flags using in the write
    int flags (void) const;

    /// I/O handle used for writing.
    ACE_HANDLE handle (void) const;

    /// Get the implementation class.
    ACE_Asynch_Write_Dgram_Result_Impl *implementation (void) const;

  protected:
    /// Constructor.
    Result (ACE_Asynch_Write_Dgram_Result_Impl *implementation);

    /// Destructor.
    virtual ~Result (void);

    /// Implementation class.
    ACE_Asynch_Write_Dgram_Result_Impl *implementation_;
  };
private:
  ACE_UNIMPLEMENTED_FUNC (void operator= (const ACE_Asynch_Write_Dgram &))
  ACE_UNIMPLEMENTED_FUNC (ACE_Asynch_Write_Dgram (const ACE_Asynch_Write_Dgram &))
};


/**
 * @class ACE_Handler
 *
 * @brief This base class defines the interface for receiving the
 * results of asynchronous operations.
 *
 * Subclasses of this class will fill in appropriate methods.
 */
class ACE_Export ACE_Handler
{
public:
  /// A do nothing constructor.
  ACE_Handler (void);

  /// A do nothing constructor which allows proactor to be set to \<p\>.
  ACE_Handler (ACE_Proactor *p);

  /// Virtual destruction.
  virtual ~ACE_Handler (void);

  /// This method will be called when an asynchronous read completes on
  /// a stream.
  virtual void handle_read_stream (const ACE_Asynch_Read_Stream::Result &result);

  /// This method will be called when an asynchronous write completes
  /// on a UDP socket.
  virtual void handle_write_dgram (const ACE_Asynch_Write_Dgram::Result &result);

  /// This method will be called when an asynchronous read completes on
  /// a UDP socket.
  virtual void handle_read_dgram (const ACE_Asynch_Read_Dgram::Result &result);

  /// This method will be called when an asynchronous write completes
  /// on a stream.
  virtual void handle_write_stream (const ACE_Asynch_Write_Stream::Result &result);

  /// This method will be called when an asynchronous read completes on
  /// a file.
  virtual void handle_read_file (const ACE_Asynch_Read_File::Result &result);

  /// This method will be called when an asynchronous write completes
  /// on a file.
  virtual void handle_write_file (const ACE_Asynch_Write_File::Result &result);

  /// This method will be called when an asynchronous accept completes.
  virtual void handle_accept (const ACE_Asynch_Accept::Result &result);

  /// This method will be called when an asynchronous connect completes.
  virtual void handle_connect (const ACE_Asynch_Connect::Result &result);

  /// This method will be called when an asynchronous transmit file
  /// completes.
  virtual void handle_transmit_file (const ACE_Asynch_Transmit_File::Result &result);

  /// Called when timer expires.  {tv} was the requested time value and
  /// {act} is the ACT passed when scheduling the timer.
  virtual void handle_time_out (const ACE_Time_Value &tv,
                                const void *act = 0);

  /**
   * This is method works with the {run_event_loop} of the
   * ACE_Proactor. A special {Wake_Up_Completion} is used to wake up
   * all the threads that are blocking for completions.
   */
  virtual void handle_wakeup (void);

  /// Get the proactor associated with this handler.
  ACE_Proactor *proactor (void);

  /// Set the proactor.
  void proactor (ACE_Proactor *p);

  /**
   * Get the I/O handle used by this {handler}. This method will be
   * called by the ACE_Asynch_* classes when an ACE_INVALID_HANDLE is
   * passed to {open}.
   */
  virtual ACE_HANDLE handle (void) const;

  /// Set the ACE_HANDLE value for this Handler.
  virtual void handle (ACE_HANDLE);

  /**
   * @class Proxy
   *
   * @brief The Proxy class acts as a proxy for dispatch of completions
   * to operations issued for the associated handler. It allows the handler
   * to be deleted while operations are outstanding. The proxy must be used
   * to get the ACE_Handler pointer for dispatching, and if it's 0, the
   * handler is no longer valid and the result should not be dispatched.
   */
  class ACE_Export Proxy
  {
  public:
    Proxy (ACE_Handler *handler) : handler_ (handler) {};
    void reset (void) { this->handler_ = 0; };
    ACE_Handler *handler (void) { return this->handler_; };
  private:
    ACE_Handler *handler_;
  };
  typedef ACE_Refcounted_Auto_Ptr<Proxy, ACE_SYNCH_MUTEX>
    Proxy_Ptr;

  Proxy_Ptr &proxy (void);

protected:
  /// The proactor associated with this handler.
  ACE_Proactor *proactor_;

  /// The ACE_HANDLE in use with this handler.
  ACE_HANDLE    handle_;

  /// Refers to proxy for this handler.
  ACE_Refcounted_Auto_Ptr<Proxy, ACE_SYNCH_MUTEX> proxy_;

  ACE_UNIMPLEMENTED_FUNC (ACE_Handler (const ACE_Handler &))
  ACE_UNIMPLEMENTED_FUNC (ACE_Handler operator= (const ACE_Handler &))
};

// Forward declarations
class ACE_INET_Addr;

// Forward declarations
template <class HANDLER>
class ACE_Asynch_Acceptor;

/**
 * @class ACE_Service_Handler
 *
 * @brief This base class defines the interface for the
 * ACE_Asynch_Acceptor to call into when new connection are
 * accepted.
 *
 * Subclasses of this class will fill in appropriate methods to
 * define application specific behavior.
 */
class ACE_Export ACE_Service_Handler : public ACE_Handler
{

  /// The Acceptor is the factory and therefore should have special
  /// privileges.
  friend class ACE_Asynch_Acceptor<ACE_Service_Handler>;

public:
  /// A do nothing constructor.
  ACE_Service_Handler (void);

  /// Virtual destruction.
  virtual ~ACE_Service_Handler (void);

  /**
   * {open} is called by ACE_Asynch_Acceptor to initialize a new
   * instance of ACE_Service_Handler that has been created after the
   * new connection is accepted. The handle for the new connection is
   * passed along with the initial data that may have shown up.
   */
  virtual void open (ACE_HANDLE new_handle,
                     ACE_Message_Block &message_block);

  // protected:
  // This should be corrected after the correct semantics of the
  // friend has been figured out.

  /// Called by ACE_Asynch_Acceptor to pass the addresses of the new
  /// connections.
  virtual void addresses (const ACE_INET_Addr &remote_address,
                          const ACE_INET_Addr &local_address);

  /// Called by ACE_Asynch_Acceptor to pass the act.
  virtual void act (const void *);
};

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_WIN32 || ACE_HAS_AIO_CALLS*/
#include /**/ "ace/post.h"
#endif /* ACE_ASYNCH_IO_H */
