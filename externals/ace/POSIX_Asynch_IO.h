// -*- C++ -*-

//=============================================================================
/**
 *  @file    POSIX_Asynch_IO.h
 *
 *  $Id: POSIX_Asynch_IO.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  The implementation classes for POSIX implementation of Asynch
 *  Operations are defined here in this file.
 *
 *  @author Irfan Pyarali <irfan@cs.wustl.edu>
 *  @author Tim Harrison <harrison@cs.wustl.edu>
 *  @author Alexander Babu Arulanthu <alex@cs.wustl.edu>
 *  @author Roger Tragin <r.tragin@computer.org>
 *  @author Alexander Libman <alibman@baltimore.com>
 */
//=============================================================================

#ifndef ACE_POSIX_ASYNCH_IO_H
#define ACE_POSIX_ASYNCH_IO_H

#include /**/ "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if defined (ACE_HAS_AIO_CALLS)

#include "ace/os_include/os_aio.h"

#include "ace/Asynch_IO_Impl.h"
#include "ace/Unbounded_Queue.h"
#include "ace/Map_Manager.h"
#include "ace/Event_Handler.h"
#if defined(INTEGRITY)
#include "ace/ACE.h"
#endif

#include "ace/Null_Mutex.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

// Forward declarations
class ACE_POSIX_Proactor;
class ACE_Proactor_Impl;
class ACE_Handle_Set;

/**
 * @class ACE_POSIX_Asynch_Result
 *
 * This class provides concrete implementation for ACE_Asynch_Result
 * for POSIX4 platforms. This class extends @c aiocb and makes it more
 * useful.
 */
class ACE_Export ACE_POSIX_Asynch_Result : public virtual ACE_Asynch_Result_Impl,
                                           public aiocb
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
   * @note This is not implemented for POSIX4 platforms.
   */
  const void *completion_key (void) const;

  /// Error value if the operation fails.
  u_long error (void) const;

  /// This returns ACE_INVALID_HANDLE on POSIX4 platforms.
  ACE_HANDLE event (void) const;

  /**
   * This really make sense only when doing file I/O.
   *
   * @@ On POSIX4-Unix, offset_high should be supported using
   *     aiocb64.
   *
   */
  u_long offset (void) const;
  u_long offset_high (void) const;

  /// Priority of the operation.
  int priority (void) const;

  /**
   * POSIX4 realtime signal number to be used for the
   * operation. <signal_number> ranges from SIGRTMIN to SIGRTMAX. By
   * default, SIGRTMIN is used to issue <aio_> calls.
   */
  int signal_number (void) const;

  /// Post @c this to the Proactor.
  int post_completion (ACE_Proactor_Impl *proactor);

  /// Destructor.
  virtual ~ACE_POSIX_Asynch_Result (void);

  /// Simulate error value to use in the post_completion ()
  void set_error (u_long errcode);

  /// Simulate value to use in the post_completion ()
  void set_bytes_transferred (size_t nbytes);

protected:
  /// Constructor. <Event> is not used on POSIX.
  ACE_POSIX_Asynch_Result (const ACE_Handler::Proxy_Ptr &handler_proxy,
                           const void* act,
                           ACE_HANDLE event,
                           u_long offset,
                           u_long offset_high,
                           int priority,
                           int signal_number);

  /// Handler that will be called back.
  ACE_Handler::Proxy_Ptr handler_proxy_;

  /**
   * ACT for this operation.
   * We could use <aiocb::aio_sigevent.sigev_value.sival_ptr> for
   * this. But it doesnot provide the constness, so this may be
   * better.
   */
  const void *act_;

  /// Bytes transferred by this operation.
  size_t bytes_transferred_;

  /// Success indicator.
  int success_;

  /// ACT associated with handle.
  const void *completion_key_;

  /// Error if operation failed.
  u_long error_;
};

/**
 * @class ACE_POSIX_Asynch_Operation
 *
 * @brief This class implements ACE_Asynch_Operation for all
 * implementations of Proactor (AIOCB, SIG, SUN)
 * Specific future implementations can derive from this class.
 */
class ACE_Export ACE_POSIX_Asynch_Operation : public virtual ACE_Asynch_Operation_Impl
{
public:
  /**
   * Initializes the factory with information which will be used with
   * each asynchronous call.  If (@a handle == ACE_INVALID_HANDLE),
   * @c ACE_Handler::handle will be called on the handler to get the
   * correct handle. No need for the Proactor since the sub classes
   * will know the correct implementation Proactor class, since this
   * Operation class itself was created by the correct implementation
   * Proactor class.
   */
  int open (const ACE_Handler::Proxy_Ptr &handler_proxy,
            ACE_HANDLE handle,
            const void *completion_key,
            ACE_Proactor *proactor = 0);

  /// Check the documentation for ACE_Asynch_Operation::cancel.
  int cancel (void);

  // = Access methods.

  /// Return the underlying proactor.
  ACE_Proactor* proactor (void) const;

  /// Return the underlying Proactor implementation.
  ACE_POSIX_Proactor * posix_proactor (void) const;

protected:
  /// Contructor.
  ACE_POSIX_Asynch_Operation (ACE_POSIX_Proactor *posix_proactor);

  /// Destructor.
  virtual ~ACE_POSIX_Asynch_Operation (void);

  // This call is for the POSIX implementation. This method is used by
  // ACE_Asynch_Operation to store some information with the
  // Proactor after an <aio_> call is issued, so that the Proactor can
  // retreve this information to do <aio_return> and <aio_error>.
  // Passing a '0' ptr returns the status, indicating whether there
  // are slots available or no. Passing a valid ptr stores the ptr
  // with the Proactor.

  /**
   * It is easy to get this specific implementation proactor here,
   * since it is the one that creates the correct POSIX_Asynch_*
   * objects. We can use this to get to the implementation proactor
   * directly.
   */
  ACE_POSIX_Proactor *posix_proactor_;

  /// Proactor that this Asynch IO will be registered with.
  ACE_Proactor *proactor_;

  /// Handler that will receive the callback.
  ACE_Handler::Proxy_Ptr handler_proxy_;

  /// I/O handle used for reading.
  ACE_HANDLE handle_;
};

/**
 * @class ACE_POSIX_Asynch_Read_Stream_Result
 *
 * @brief This class provides concrete implementation for
 *    <ACE_Asynch_Read_Stream::Result> class for POSIX platforms.
 */
class ACE_Export ACE_POSIX_Asynch_Read_Stream_Result : public virtual ACE_Asynch_Read_Stream_Result_Impl,
                                                       public ACE_POSIX_Asynch_Result
{

  /// Factory classes will have special permissions.
  friend class ACE_POSIX_Asynch_Read_Stream;

  /// The Proactor constructs the Result class for faking results.
  friend class ACE_POSIX_Proactor;

public:
  /// The number of bytes which were requested at the start of the
  /// asynchronous read.
  size_t bytes_to_read (void) const;

  /// Message block which contains the read data.
  ACE_Message_Block &message_block (void) const;

  /// I/O handle used for reading.
  ACE_HANDLE handle (void) const;

protected:
  ACE_POSIX_Asynch_Read_Stream_Result (const ACE_Handler::Proxy_Ptr &handler_proxy,
                                       ACE_HANDLE handle,
                                       ACE_Message_Block &message_block,
                                       size_t bytes_to_read,
                                       const void* act,
                                       ACE_HANDLE event,
                                       int priority,
                                       int signal_number);
  // Constructor is protected since creation is limited to
  // ACE_Asynch_Read_Stream factory.

  /// Get the data copied to this class, before calling application
  /// handler.
  virtual void complete (size_t bytes_transferred,
                         int success,
                         const void *completion_key,
                         u_long error);

  /// Destructor.
  virtual ~ACE_POSIX_Asynch_Read_Stream_Result (void);

  // aiocb::aio_nbytes
  // Bytes requested when the asynchronous read was initiated.

  /// Message block for reading the data into.
  ACE_Message_Block &message_block_;

  // aiocb::aio_filedes
  // I/O handle used for reading.
};

/**
 * @class ACE_POSIX_Asynch_Read_Stream
 *
 * This class implements <ACE_Asynch_Read_Stream> for all POSIX
 * based implementation of Proactor.
 *
 */
class ACE_Export ACE_POSIX_Asynch_Read_Stream : public virtual ACE_Asynch_Read_Stream_Impl,
                                                public ACE_POSIX_Asynch_Operation
{
public:
  /// Constructor.
  ACE_POSIX_Asynch_Read_Stream (ACE_POSIX_Proactor *posix_proactor);

  /// This starts off an asynchronous read.  Upto @a bytes_to_read will
  /// be read and stored in the @a message_block.
  int read (ACE_Message_Block &message_block,
            size_t bytes_to_read,
            const void *act,
            int priority,
            int signal_number = 0);

  /// Destructor.
  virtual ~ACE_POSIX_Asynch_Read_Stream (void);
};


/**
 * @class ACE_POSIX_Asynch_Write_Stream_Result
 *
 * @brief This class provides concrete implementation for
 *     <ACE_Asynch_Write_Stream::Result> on POSIX platforms.
 *
 *
 *     This class has all the information necessary for the
 *     @c handler to uniquiely identify the completion of the
 *     asynchronous write.
 */
class ACE_Export ACE_POSIX_Asynch_Write_Stream_Result : public virtual ACE_Asynch_Write_Stream_Result_Impl,
                                                        public ACE_POSIX_Asynch_Result
{
  /// Factory classes will have special privilages.
  friend class ACE_POSIX_Asynch_Write_Stream;

  /// The Proactor constructs the Result class for faking results.
  friend class ACE_POSIX_Proactor;

public:
  /// The number of bytes which were requested at the start of the
  /// asynchronous write.
  size_t bytes_to_write (void) const;

  /// Message block that contains the data to be written.
  ACE_Message_Block &message_block (void) const;

  /// I/O handle used for writing.
  ACE_HANDLE handle (void) const;

protected:
  /// Constructor is protected since creation is limited to
  /// ACE_Asynch_Write_Stream factory.
  ACE_POSIX_Asynch_Write_Stream_Result (const ACE_Handler::Proxy_Ptr &handler_proxy,
                                        ACE_HANDLE handle,
                                        ACE_Message_Block &message_block,
                                        size_t bytes_to_write,
                                        const void* act,
                                        ACE_HANDLE event,
                                        int priority,
                                        int signal_number);

  /// ACE_Proactor will call this method when the write completes.
  virtual void complete (size_t bytes_transferred,
                         int success,
                         const void *completion_key,
                         u_long error);

  /// Destructor.
  virtual ~ACE_POSIX_Asynch_Write_Stream_Result (void);

protected:
  // aiocb::aio_nbytes
  // The number of bytes which were requested at the start of the
  // asynchronous write.

  /// Message block that contains the data to be written.
  ACE_Message_Block &message_block_;

  // aiocb::aio_filedes
  // I/O handle used for writing.
};

/**
 * @class ACE_POSIX_Asynch_Write_Stream
 *
 * @brief This class implements <ACE_Asynch_Write_Stream> for
 *  all POSIX implementations of ACE_Proactor.
 */
class ACE_Export ACE_POSIX_Asynch_Write_Stream : public virtual ACE_Asynch_Write_Stream_Impl,
                                                 public ACE_POSIX_Asynch_Operation
{
public:
  /// Constructor.
  ACE_POSIX_Asynch_Write_Stream (ACE_POSIX_Proactor *posix_proactor);

  /// This starts off an asynchronous write.  Upto @a bytes_to_write
  /// will be written from the @a message_block.
  int write (ACE_Message_Block &message_block,
             size_t bytes_to_write,
             const void *act,
             int priority,
             int signal_number = 0);

  /// Destructor.
  virtual ~ACE_POSIX_Asynch_Write_Stream (void);
};

/**
 * @class ACE_POSIX_Asynch_Read_File_Result
 *
 * @brief This class provides concrete implementation for
 *     <ACE_Asynch_Read_File::Result> class for POSIX platforms.
 */
class ACE_Export ACE_POSIX_Asynch_Read_File_Result : public virtual ACE_Asynch_Read_File_Result_Impl,
                                                     public ACE_POSIX_Asynch_Read_Stream_Result
{
  /// Factory classes will have special permissions.
  friend class ACE_POSIX_Asynch_Read_File;

  /// The Proactor constructs the Result class for faking results.
  friend class ACE_POSIX_Proactor;

public:

protected:
  /// Constructor is protected since creation is limited to
  /// ACE_Asynch_Read_File factory.
  ACE_POSIX_Asynch_Read_File_Result (const ACE_Handler::Proxy_Ptr &handler_proxy,
                                     ACE_HANDLE handle,
                                     ACE_Message_Block &message_block,
                                     size_t bytes_to_read,
                                     const void* act,
                                     u_long offset,
                                     u_long offset_high,
                                     ACE_HANDLE event,
                                     int priority,
                                     int signal_number);

  /// ACE_Proactor will call this method when the read completes.
  virtual void complete (size_t bytes_transferred,
                         int success,
                         const void *completion_key,
                         u_long error);

  /// Destructor.
  virtual ~ACE_POSIX_Asynch_Read_File_Result (void);
};

/**
 * @class ACE_POSIX_Asynch_Read_File
 *
 * @brief This class is a factory for starting off asynchronous reads
 *     on a file. This class implements <ACE_Asynch_Read_File> for
 *     all POSIX implementations of Proactor.
 *
 *     Once <open> is called, multiple asynchronous <read>s can
 *     started using this class.  A <ACE_Asynch_Read_File::Result>
 *     will be passed back to the @c handler when the asynchronous
 *     reads completes through the <ACE_Handler::handle_read_file>
 *     callback.
 *
 *     This class differs slightly from <ACE_Asynch_Read_Stream> as it
 *     allows the user to specify an offset for the read.
 */
class ACE_Export ACE_POSIX_Asynch_Read_File : public virtual ACE_Asynch_Read_File_Impl,
                                              public ACE_POSIX_Asynch_Read_Stream
{

public:
  /// Constructor.
  ACE_POSIX_Asynch_Read_File (ACE_POSIX_Proactor *posix_proactor);

  /**
   * This starts off an asynchronous read.  Upto @a bytes_to_read will
   * be read and stored in the @a message_block.  The read will start
   * at @a offset from the beginning of the file.
   */
  int read (ACE_Message_Block &message_block,
            size_t bytes_to_read,
            u_long offset,
            u_long offset_high,
            const void *act,
            int priority,
            int signal_number = 0);

  /// Destructor.
  virtual ~ACE_POSIX_Asynch_Read_File (void);

private:
  /**
   * This belongs to ACE_POSIX_Asynch_Read_Stream. We have
   * defined this here to avoid compiler warnings and forward the
   * method to <ACE_POSIX_Asynch_Read_Stream::read>.
   */
  int read (ACE_Message_Block &message_block,
            size_t bytes_to_read,
            const void *act,
            int priority,
            int signal_number = 0);
};


/**
 * @class ACE_POSIX_Asynch_Write_File_Result
 *
 * @brief This class provides implementation for
 *     <ACE_Asynch_Write_File_Result> for POSIX platforms.
 *
 *     This class has all the information necessary for the
 *     @c handler to uniquiely identify the completion of the
 *     asynchronous write.
 *
 *     This class differs slightly from
 *     <ACE_Asynch_Write_Stream::Result> as it calls back
 *     <ACE_Handler::handle_write_file> on the @c handler instead of
 *     <ACE_Handler::handle_write_stream>.  No additional state is
 *     required by this class as <ACE_Asynch_Result> can store the
 *     @a offset.
 */
class ACE_Export ACE_POSIX_Asynch_Write_File_Result : public virtual ACE_Asynch_Write_File_Result_Impl,
                                                      public ACE_POSIX_Asynch_Write_Stream_Result
{
  /// Factory classes will have special permissions.
  friend class ACE_POSIX_Asynch_Write_File;

  /// The Proactor constructs the Result class for faking results.
  friend class ACE_POSIX_Proactor;

protected:
  /// Constructor is protected since creation is limited to
  /// ACE_Asynch_Write_File factory.
  ACE_POSIX_Asynch_Write_File_Result (const ACE_Handler::Proxy_Ptr &handler_proxy,
                                      ACE_HANDLE handle,
                                      ACE_Message_Block &message_block,
                                      size_t bytes_to_write,
                                      const void* act,
                                      u_long offset,
                                      u_long offset_high,
                                      ACE_HANDLE event,
                                      int priority,
                                      int signal_number);

  /// ACE_Proactor will call this method when the write completes.
  virtual void complete (size_t bytes_transferred,
                         int success,
                         const void *completion_key,
                         u_long error);

  /// Destructor.
  virtual ~ACE_POSIX_Asynch_Write_File_Result (void);
};

/**
 * @class ACE_POSIX_Asynch_Write_File
 *
 *     This class provides concrete implementation for
 *     <ACE_Asynch_Write_File> for POSIX platforms where the
 *     completion strategy for Proactor is based on AIOCB (AIO
 *     Control Blocks).
 *
 */
class ACE_Export ACE_POSIX_Asynch_Write_File : public virtual ACE_Asynch_Write_File_Impl,
                                               public ACE_POSIX_Asynch_Write_Stream
{
public:
  /// Constructor.
  ACE_POSIX_Asynch_Write_File (ACE_POSIX_Proactor *posix_proactor);

  /**
   * This starts off an asynchronous write.  Upto @a bytes_to_write
   * will be written and stored in the @a message_block.  The write will
   * start at @a offset from the beginning of the file.
   */
  int write (ACE_Message_Block &message_block,
             size_t bytes_to_write,
             u_long offset,
             u_long offset_high,
             const void *act,
             int priority,
             int signal_number = 0);

  /// Destructor.
  virtual ~ACE_POSIX_Asynch_Write_File (void);

private:
  /**
   * This <write> belongs to ACE_POSIX_Asynch_Write_Stream. We
   * have put this here to avoid compiler warnings. We forward this
   * method call to the <ACE_POSIX_Asynch_Write_Stream::write>
   * one.
   */
  int write (ACE_Message_Block &message_block,
             size_t bytes_to_write,
             const void *act,
             int priority,
             int signal_number = 0);
};

/**
 * @class ACE_POSIX_Asynch_Accept_Result
 *
 * @brief This is that class which will be passed back to the
 *     handler when the asynchronous accept completes.
 *
 *
 *     This class has all the information necessary for the
 *     handler to uniquiely identify the completion of the
 *     asynchronous accept.
 */
class ACE_Export ACE_POSIX_Asynch_Accept_Result : public virtual ACE_Asynch_Accept_Result_Impl,
                                                  public ACE_POSIX_Asynch_Result
{
  /// Factory classes will have special permissions.
  friend class ACE_POSIX_Asynch_Accept;

  /// The Proactor constructs the Result class for faking results.
  friend class ACE_POSIX_Proactor;

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

protected:
  /// Constructor is protected since creation is limited to
  /// ACE_Asynch_Accept factory.
  ACE_POSIX_Asynch_Accept_Result (const ACE_Handler::Proxy_Ptr &handler_proxy,
                                  ACE_HANDLE listen_handle,
                                  ACE_HANDLE accept_handle,
                                  ACE_Message_Block &message_block,
                                  size_t bytes_to_read,
                                  const void* act,
                                  ACE_HANDLE event,
                                  int priority,
                                  int signal_number);

  /// ACE_Proactor will call this method when the accept completes.
  virtual void complete (size_t bytes_transferred,
                         int success,
                         const void *completion_key,
                         u_long error);

  /// Destructor.
  virtual ~ACE_POSIX_Asynch_Accept_Result (void);

  // aiocb::aio_nbytes
  // Bytes requested when the asynchronous read was initiated.
  // Actually, on POSIX implementation, we dont read any intial data.

  /// Message block for reading the data into.
  ACE_Message_Block &message_block_;

  /// I/O handle used for accepting new connections.
  ACE_HANDLE listen_handle_;

  // aiocb::aio_filedes
  // I/O handle for the new connection.
};


/**
 * @class ACE_POSIX_Asynch_Accept
 *
 * @brief For the POSIX implementation this class is common for all Proactors
 * (AIOCB/SIG/SUN)
 */
class ACE_Export ACE_POSIX_Asynch_Accept :
  public virtual ACE_Asynch_Accept_Impl,
  public ACE_POSIX_Asynch_Operation,
  public ACE_Event_Handler
{
public:

  /// Constructor.
  ACE_POSIX_Asynch_Accept (ACE_POSIX_Proactor * posix_proactor);

  /// Destructor.
  virtual ~ACE_POSIX_Asynch_Accept (void);

 /**
   * This <open> belongs to ACE_POSIX_Asynch_Operation. We forward
   * this call to that method. We have put this here to avoid the
   * compiler warnings.
   */
  int open (const ACE_Handler::Proxy_Ptr &handler_proxy,
            ACE_HANDLE handle,
            const void *completion_key,
            ACE_Proactor *proactor = 0);

  /**
   * This starts off an asynchronous accept.  The asynchronous accept
   * call also allows any initial data to be returned to the
   * @c handler.  Upto @a bytes_to_read will be read and stored in the
   * @a message_block.  The <accept_handle> will be used for the
   * <accept> call.  If (<accept_handle> == INVALID_HANDLE), a new
   * handle will be created.
   *
   * @a message_block must be specified. This is because the address of
   * the new connection is placed at the end of this buffer.
   */
  int accept (ACE_Message_Block &message_block,
              size_t bytes_to_read,
              ACE_HANDLE accept_handle,
              const void *act,
              int priority,
              int signal_number = 0,
              int addr_family = AF_INET);

  /**
   *  Cancel all pending pseudo-asynchronus requests
   *  Behavior as usual AIO request
   */
  int cancel (void);

  /**
   *  Close performs cancellation of all pending requests
   *  and closure the listen handle
   */
  int close ();

  /// virtual from ACE_Event_Handler
  ACE_HANDLE get_handle (void) const;

  /// virtual from ACE_Event_Handler
  void set_handle (ACE_HANDLE handle);

  /// virtual from ACE_Event_Handler
  /// Called when accept event comes up on <listen_handle>
  int handle_input (ACE_HANDLE handle);

  /// virtual from ACE_Event_Handler
  int handle_close (ACE_HANDLE handle, ACE_Reactor_Mask close_mask);

private:
  /// flg_notify points whether or not we should send notification about
  /// canceled accepts
  ///  Parameter flg_notify can be
  ///    0  - don't send notifications about canceled accepts
  ///    1  - notify user about canceled accepts
  ///         according POSIX standards we should receive notifications
  ///         on canceled AIO requests
  int cancel_uncompleted (int flg_notify);

  /// true  - Accept is registered in ACE_Asynch_Pseudo_Task
  /// false - Accept is deregisted in ACE_Asynch_Pseudo_Task
  bool flg_open_ ;

  /// Queue of Result pointers that correspond to all the pending
  /// accept operations.
  ACE_Unbounded_Queue<ACE_POSIX_Asynch_Accept_Result*> result_queue_;

  /// The lock to protect the result queue which is shared. The queue
  /// is updated by main thread in the register function call and
  /// through the auxillary thread in the deregister fun. So let us
  /// mutex it.
  ACE_SYNCH_MUTEX lock_;
};

/**
 * @class ACE_POSIX_Asynch_Connect_Result
 *
 * @brief This is that class which will be passed back to the
 *     completion handler when the asynchronous connect completes.
 *
 *     This class has all the information necessary for a
 *     completion handler to uniquely identify the completion of the
 *     asynchronous connect.
 */
class ACE_Export ACE_POSIX_Asynch_Connect_Result : public virtual ACE_Asynch_Connect_Result_Impl,
                                                  public ACE_POSIX_Asynch_Result
{
  /// Factory classes will have special permissions.
  friend class ACE_POSIX_Asynch_Connect;

  /// The Proactor constructs the Result class for faking results.
  friend class ACE_POSIX_Proactor;

public:

  /// I/O handle for the  connection.
  ACE_HANDLE connect_handle (void) const;

protected:
  /// Constructor is protected since creation is limited to
  /// ACE_Asynch_Connect factory.
  ACE_POSIX_Asynch_Connect_Result (const ACE_Handler::Proxy_Ptr &handler_proxy,
                                   ACE_HANDLE  connect_handle,
                                   const void* act,
                                   ACE_HANDLE  event,
                                   int priority,
                                   int signal_number);

  /// ACE_Proactor will call this method when the accept completes.
  virtual void complete (size_t bytes_transferred,
                         int success,
                         const void *completion_key,
                         u_long error);

  /// Destructor.
  virtual ~ACE_POSIX_Asynch_Connect_Result (void);

  // aiocb::aio_filedes
  // I/O handle for the new connection.
  void connect_handle (ACE_HANDLE handle);
};


/**
 * @class ACE_POSIX_Asynch_Connect
 *
 */
class ACE_Export ACE_POSIX_Asynch_Connect :
  public virtual ACE_Asynch_Connect_Impl,
  public ACE_POSIX_Asynch_Operation,
  public ACE_Event_Handler
{
public:

  /// Constructor.
  ACE_POSIX_Asynch_Connect (ACE_POSIX_Proactor * posix_proactor);

  /// Destructor.
  virtual ~ACE_POSIX_Asynch_Connect (void);

 /**
   * This belongs to ACE_POSIX_Asynch_Operation. We forward
   * this call to that method. We have put this here to avoid the
   * compiler warnings.
   */
  int open (const ACE_Handler::Proxy_Ptr &handler_proxy,
            ACE_HANDLE handle,
            const void *completion_key,
            ACE_Proactor *proactor = 0);

  /**
   * This starts off an asynchronous connect.
   *
   * @arg connect_handle   will be used for the connect call.  If
   *                       ACE_INVALID_HANDLE is specified, a new
   *                       handle will be created.
   */
  int connect (ACE_HANDLE connect_handle,
               const ACE_Addr &remote_sap,
               const ACE_Addr &local_sap,
               int reuse_addr,
               const void *act,
               int priority,
               int signal_number = 0);

  /**
   *  Cancel all pending pseudo-asynchronus requests
   *  Behavior as usual AIO request
   */
  int cancel (void);

  /**
   *  Close performs cancellation of all pending requests.
   */
  int close (void);

  /// virtual from ACE_Event_Handler
  ACE_HANDLE get_handle (void) const;

  /// virtual from ACE_Event_Handler
  void set_handle (ACE_HANDLE handle);

  /// virtual from ACE_Event_Handler
  /// The default action on handle_input() and handle_exception is to
  /// return -1. Since that's what we want to do, just reuse them.
  /// handle_output(), however, is where successful connects are reported.
  int handle_output (ACE_HANDLE handle);

  /// virtual from ACE_Event_Handler
  int handle_close (ACE_HANDLE handle, ACE_Reactor_Mask close_mask) ;

private:
  int connect_i (ACE_POSIX_Asynch_Connect_Result *result,
                 const ACE_Addr & remote_sap,
                 const ACE_Addr & local_sap,
                 int reuse_addr);

  int post_result (ACE_POSIX_Asynch_Connect_Result *result, bool flg_post);

  /// Cancel uncompleted connect operations.
  /**
   *  @arg flg_notify  Indicates whether or not we should send notification
   *                   about canceled accepts.  If this is false, don't send
   *                   notifications about canceled connects.  If true, notify
   *                   user about canceled connects according POSIX
   *                   standards we should receive notifications on canceled
   *                   AIO requests.
   */
  int cancel_uncompleted (bool flg_notify, ACE_Handle_Set &set);

  bool flg_open_ ;
  /// true  - Connect is registered in ACE_Asynch_Pseudo_Task
  /// false - Aceept is deregisted in ACE_Asynch_Pseudo_Task

  typedef ACE_Map_Manager<ACE_HANDLE, ACE_POSIX_Asynch_Connect_Result *, ACE_SYNCH_NULL_MUTEX>
          MAP_MANAGER;

  /// @deprecated (Two) Deprecated typedefs.  Use the map traits instead.
  typedef MAP_MANAGER::ITERATOR MAP_ITERATOR;
  typedef MAP_MANAGER::ENTRY MAP_ENTRY;

  /// Map of Result pointers that correspond to all the pending connects.
  MAP_MANAGER result_map_;

  /// The lock to protect the result map which is shared. The queue
  /// is updated by main thread in the register function call and
  /// through the auxillary thread  in the asynch pseudo task.
  ACE_SYNCH_MUTEX lock_;
};


/**
 * @class ACE_POSIX_Asynch_Transmit_File_Result
 *
 * @brief This is that class which will be passed back to the
 *     <handler> when the asynchronous transmit file completes.
 *
 *     This class has all the information necessary for the
 *     <handler> to uniquiely identify the completion of the
 *     asynchronous transmit file.
 */
class ACE_Export ACE_POSIX_Asynch_Transmit_File_Result : public virtual ACE_Asynch_Transmit_File_Result_Impl,
                                                         public ACE_POSIX_Asynch_Result
{
  /// Factory classes will have special permissions.
  friend class ACE_POSIX_Asynch_Transmit_File;

  /// Handlers do all the job.
  friend class ACE_POSIX_Asynch_Transmit_Handler;

  /// The Proactor constructs the Result class for faking results.
  friend class ACE_POSIX_Proactor;

public:
  /// Socket used for transmitting the file.
  ACE_HANDLE socket (void) const;

  /// File from which the data is read.
  ACE_HANDLE file (void) const;

  /// Header and trailer data associated with this transmit file.
  ACE_Asynch_Transmit_File::Header_And_Trailer *header_and_trailer (void) const;

  /// The number of bytes which were requested at the start of the
  /// asynchronous transmit file.
  size_t bytes_to_write (void) const;

  /// Number of bytes per send requested at the start of the transmit
  /// file.
  size_t bytes_per_send (void) const;

  /// Flags which were passed into transmit file.
  u_long flags (void) const;

protected:
  ACE_POSIX_Asynch_Transmit_File_Result (const ACE_Handler::Proxy_Ptr &handler_proxy,
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
                                         int signal_number);
  // Constructor is protected since creation is limited to
  // ACE_Asynch_Transmit_File factory.

  /// ACE_Proactor will call this method when the write completes.
  virtual void complete (size_t bytes_transferred,
                         int success,
                         const void *completion_key,
                         u_long error);

  /// Destructor.
  virtual ~ACE_POSIX_Asynch_Transmit_File_Result (void);

  /// Network I/O handle.
  ACE_HANDLE socket_;

  // aiocb::aio_filedes
  // File I/O handle.

  /// Header and trailer data associated with this transmit file.
  ACE_Asynch_Transmit_File::Header_And_Trailer *header_and_trailer_;

  // aiocb::aio_nbytes
  // The number of bytes which were requested at the start of the
  // asynchronous transmit file.

  /// Number of bytes per send requested at the start of the transmit
  /// file.
  size_t bytes_per_send_;

  /// Flags which were passed into transmit file.
  u_long flags_;
};

/**
 * @class ACE_POSIX_Asynch_Transmit_File
 *
 * @brief Implementation for transmit_file will make use of
 *     POSIX_Asynch_Transmit_Handler.
 */
class ACE_Export ACE_POSIX_Asynch_Transmit_File : public virtual ACE_Asynch_Transmit_File_Impl,
                                                  public ACE_POSIX_Asynch_Operation
{
public:
  /// Constructor.
  ACE_POSIX_Asynch_Transmit_File (ACE_POSIX_Proactor *posix_proactor);

  /**
   * This starts off an asynchronous transmit file. The <file> is a
   * handle to an open file.  <header_and_trailer> is a pointer to a
   * data structure that contains pointers to data to send before and
   * after the file data is sent.  Set this parameter to 0 if you only
   * want to transmit the file data.  Upto @a bytes_to_write will be
   * written to the <socket>.  If you want to send the entire file,
   * let @a bytes_to_write = 0.  @a bytes_per_send is the size of each
   * block of data sent per send operation. Please read the POSIX
   * documentation on what the flags should be.
   */
  int transmit_file (ACE_HANDLE file,
                     ACE_Asynch_Transmit_File::Header_And_Trailer *header_and_trailer,
                     size_t bytes_to_write,
                     u_long offset,
                     u_long offset_high,
                     size_t bytes_per_send,
                     u_long flags,
                     const void *act,
                     int priority,
                     int signal_number = 0);

  /// Destructor.
  virtual ~ACE_POSIX_Asynch_Transmit_File (void);
};


/**
 * @class ACE_POSIX_Asynch_Read_Dgram
 *
 * @brief This class is a factory for starting off asynchronous reads
 *     on a UDP socket.
 *
 *     Once <open> is called, multiple asynchronous <read>s can be
 *     started using this class.  An ACE_Asynch_Read_Dgram::Result
 *     will be passed back to the <handler> when the asynchronous
 *     reads completes through the <ACE_Handler::handle_read_stream>
 *     callback.
 *
 */
class ACE_Export ACE_POSIX_Asynch_Read_Dgram : public virtual ACE_Asynch_Read_Dgram_Impl,
                                               public ACE_POSIX_Asynch_Operation
{
public:
  /// Constructor.
  ACE_POSIX_Asynch_Read_Dgram (ACE_POSIX_Proactor *posix_proactor);
  virtual ~ACE_POSIX_Asynch_Read_Dgram (void);

  /** This method queues an asynchronous read.  Up to
   * @a message_block->total_size() bytes will be read and stored in the
   * @a message_block beginning at its write pointer. The @a message_block
   * write pointer will be updated to reflect any added bytes if the read
   * operation is successful completed.
   * Priority of the operation is specified by @a priority. On POSIX4-Unix,
   * this is supported. Works like <nice> in Unix. Negative values are not
   * allowed. 0 means priority of the operation same as the process
   * priority. 1 means priority of the operation is one less than
   * process.  @a signal_number argument is a no-op on non-POSIX4 systems.
   *
   * @note Unlike the Windows version of this facility, no indication of
   * immediate success can be returned, and @a number_of_bytes_read is
   * never used.
   *
   * @arg flags Not used.
   * @arg protocol_family Not used.
   * @retval 0  The IO will complete asynchronously.
   * @retval -1 There was an error; see @c errno to get the error code.
   *
   */
  virtual ssize_t recv (ACE_Message_Block *message_block,
                        size_t &number_of_bytes_recvd,
                        int flags,
                        int protocol_family,
                        const void *act,
                        int priority,
                        int signal_number);

protected:
  /// Do-nothing constructor.
  ACE_POSIX_Asynch_Read_Dgram (void);
};

/**
 * @class ACE_POSIX__Asynch_Write_Dgram_Result
 *
 * @brief This is class provides concrete implementation for
 *        ACE_Asynch_Write_Dgram::Result class.
 */
class ACE_Export ACE_POSIX_Asynch_Write_Dgram_Result : public virtual ACE_Asynch_Write_Dgram_Result_Impl,
                                                       public ACE_POSIX_Asynch_Result
{
  /// Factory classes will have special permissions.
  friend class ACE_POSIX_Asynch_Write_Dgram;

  /// Proactor class has special permission.
  friend class ACE_POSIX_Proactor;

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

protected:
  /// Constructor is protected since creation is limited to
  /// ACE_Asynch_Write_Stream factory.
  ACE_POSIX_Asynch_Write_Dgram_Result (const ACE_Handler::Proxy_Ptr &handler_proxy,
                                       ACE_HANDLE handle,
                                       ACE_Message_Block *message_block,
                                       size_t bytes_to_write,
                                       int flags,
                                       const void* act,
                                       ACE_HANDLE event,
                                       int priority,
                                       int signal_number);

  /// ACE_Proactor will call this method when the write completes.
  virtual void complete (size_t bytes_transferred,
                         int success,
                         const void *completion_key,
                         u_long error);

  /// Destructor.
  virtual ~ACE_POSIX_Asynch_Write_Dgram_Result (void);

  /// The number of bytes which were requested at the start of the
  /// asynchronous write.
  size_t bytes_to_write_;

  /// Message block used for the send.
  ACE_Message_Block *message_block_;

  /// The flags using in the write
  int flags_;

  /// I/O handle used for writing.
  ACE_HANDLE handle_;

  };

/**
 * @class ACE_POSIX_Asynch_Write_Dgram
 *
 * @brief This class is a factory for starting off asynchronous writes
 *    on a UDP socket. The UDP socket must be "connected", as there is
 *    no facility for specifying the destination address on each send
 *    operation.
 *
 *     Once @c open() is called, multiple asynchronous writes can
 *     started using this class.  A ACE_Asynch_Write_Stream::Result
 *     will be passed back to the associated completion handler when the
 *     asynchronous write completes through the
 *     ACE_Handler::handle_write_stream() callback.
 */
class ACE_Export ACE_POSIX_Asynch_Write_Dgram : public virtual ACE_Asynch_Write_Dgram_Impl,
                                                public ACE_POSIX_Asynch_Operation
{
public:
  /// Constructor.
  ACE_POSIX_Asynch_Write_Dgram (ACE_POSIX_Proactor *posix_proactor);

  /// Destructor
  virtual ~ACE_POSIX_Asynch_Write_Dgram (void);

  /** This method queues an asynchronous send.  Up to
   * @a message_block->total_length bytes will be sent, beginning at the
   * read pointer. The @a message_block read pointer will be updated to
   * reflect the sent bytes if the send operation is successful completed.
   *
   * Priority of the operation is specified by @a priority. On POSIX,
   * this is supported. Works like @c nice in Unix. Negative values are not
   * allowed. 0 means priority of the operation same as the process
   * priority. 1 means priority of the operation is one less than
   * process, etc.
   * @a signal_number is a no-op on non-POSIX4 systems.
   *
   * @note Unlike the Windows version of this facility, no indication of
   * immediate success can be returned, and @a number_of_bytes_sent is
   * never used.
   *
   * @arg flags Not used.
   * @arg addr Not used.
   * @retval 0  The IO will complete asynchronously.
   * @retval -1 There was an error; see @c errno to get the error code.
   */
  virtual ssize_t send (ACE_Message_Block *message_block,
                        size_t &number_of_bytes_sent,
                        int flags,
                        const ACE_Addr &addr,
                        const void *act,
                        int priority,
                        int signal_number);

protected:
  /// Do-nothing constructor.
  ACE_POSIX_Asynch_Write_Dgram (void);
};


/*****************************************************/

/**
 * @class ACE_POSIX_Asynch_Read_Dgram_Result
 *
 * @brief This is class provides concrete implementation for
 *        ACE_Asynch_Read_Dgram::Result class.
 */
class ACE_Export ACE_POSIX_Asynch_Read_Dgram_Result : public virtual ACE_Asynch_Read_Dgram_Result_Impl,
                                                      public virtual ACE_POSIX_Asynch_Result
{

  /// Factory classes will have special permissions.
  friend class ACE_POSIX_Asynch_Read_Dgram;

  /// Proactor class has special permission.
  friend class ACE_POSIX_Proactor;

public:
  /// The number of bytes which were requested at the start of the
  /// asynchronous read.
  size_t bytes_to_read (void) const;

  /// Message block which contains the read data
  ACE_Message_Block *message_block (void) const;

  /// The address of where the packet came from
  int remote_address (ACE_Addr& addr) const;

  sockaddr *saddr (void) const;

  /// The flags used in the read
  int flags (void) const;

  /// I/O handle used for reading.
  ACE_HANDLE handle (void) const;

protected:
  /// Constructor is protected since creation is limited to
  /// ACE_Asynch_Read_Dgram factory.
  ACE_POSIX_Asynch_Read_Dgram_Result (const ACE_Handler::Proxy_Ptr &handler_proxy,
                                      ACE_HANDLE handle,
                                      ACE_Message_Block *message_block,
                                      size_t bytes_to_read,
                                      int flags,
                                      int protocol_family,
                                      const void* act,
                                      ACE_HANDLE event,
                                      int priority,
                                      int signal_number = 0);

  /// Proactor will call this method when the read completes.
  virtual void complete (size_t bytes_transferred,
                         int success,
                         const void *completion_key,
                         u_long error);

  /// Destructor.
  virtual ~ACE_POSIX_Asynch_Read_Dgram_Result (void);

  /// Bytes requested when the asynchronous read was initiated.
  size_t bytes_to_read_;

  /// Message block for reading the data into.
  ACE_Message_Block *message_block_;

  /// The address of where the packet came from
  ACE_Addr *remote_address_;

  int addr_len_;

  /// The flags used in the read
  int flags_;

  /// I/O handle used for reading.
  ACE_HANDLE handle_;

};

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_HAS_AIO_CALLS */
#endif /* ACE_POSIX_ASYNCH_IO_H */
