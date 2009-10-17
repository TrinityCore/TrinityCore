// -*- C++ -*-
//=============================================================================
/**
 *  @file    WIN32_Asynch_IO.h
 *
 *  $Id: WIN32_Asynch_IO.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *
 *  These classes only works on Win32 platforms.
 *
 *  The implementation of ACE_Asynch_Transmit_File,
 *  ACE_Asynch_Accept, and ACE_Asynch_Connect are only supported if
 *  ACE_HAS_WINSOCK2 is defined or you are on WinNT 4.0 or higher.
 *
 *
 *  @author Irfan Pyarali <irfan@cs.wustl.edu>
 *  @author Tim Harrison <harrison@cs.wustl.edu>
 *  @author Alexander Babu Arulanthu <alex@cs.wustl.edu>
 *  @author Roger Tragin <r.tragin@computer.org>
 *  @author Alexander Libman <alibman@ihug.com.au>
 */
//=============================================================================
#ifndef ACE_WIN32_ASYNCH_IO_H
#define ACE_WIN32_ASYNCH_IO_H
#include /**/ "ace/pre.h"
#include /**/ "ace/config-all.h"
#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */
#if defined (ACE_HAS_WIN32_OVERLAPPED_IO) && \
    (defined (ACE_HAS_WINSOCK2) && (ACE_HAS_WINSOCK2 == 1))
#include "ace/Asynch_IO_Impl.h"
#include "ace/Addr.h"
#include "ace/Event_Handler.h"
#include "ace/Handle_Set.h"
#include "ace/Map_Manager.h"
#include "ace/Null_Mutex.h"
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
// Forward declaration
class ACE_WIN32_Proactor;
/**
 * @class ACE_WIN32_Asynch_Result
 *
 * @brief An abstract class which adds information to the OVERLAPPED
 *     structure to make it more useful.
 *
 *     An abstract base class from which you can obtain some basic
 *     information like the number of bytes transferred, the ACT
 *     associated with the asynchronous operation, indication of
 *     success or failure, etc.  Subclasses may want to store more
 *     information that is particular to the asynchronous operation
 *     it represents.
 */
class ACE_Export ACE_WIN32_Asynch_Result : public virtual ACE_Asynch_Result_Impl,
                                           public OVERLAPPED
{
  /// Factory class has special permissions.
  friend class ACE_WIN32_Asynch_Accept;
  /// Proactor class has special permission.
  friend class ACE_WIN32_Proactor;
public:
  /// Number of bytes transferred by the operation.
  size_t bytes_transferred (void) const;
  /// ACT associated with the operation.
  const void *act (void) const;
  /// Did the operation succeed?
  int success (void) const;
  /**
   * This returns the ACT associated with the handle when it was
   * registered with the I/O completion port.  This ACT is not the
   * same as the ACT associated with the asynchronous operation.
   */
  const void *completion_key (void) const;
  /// Error value if the operation fail.
  u_long error (void) const;
  /// Event associated with the OVERLAPPED structure.
  ACE_HANDLE event (void) const;
  /// This really make sense only when doing file I/O.
  u_long offset (void) const;
  /// Offset_high associated with the OVERLAPPED structure.
  u_long offset_high (void) const;
  /// The priority of the asynchronous operation. Currently, this is
  /// not supported on Win32.
  int priority (void) const;
  /// Returns 0.
  int signal_number (void) const;
  /// Post @c this to the Proactor's completion port.
  int post_completion (ACE_Proactor_Impl *proactor);
  /// Destructor.
  virtual ~ACE_WIN32_Asynch_Result (void);
  /// Simulate error value to use in the post_completion ()
  void set_error (u_long errcode);
  /// Simulate value to use in the post_completion ()
  void set_bytes_transferred (size_t nbytes);
protected:
  /// Constructor.
  ACE_WIN32_Asynch_Result (const ACE_Handler::Proxy_Ptr &handler_proxy,
                           const void* act,
                           ACE_HANDLE event,
                           u_long offset,
                           u_long offset_high,
                           int priority,
                           int signal_number = 0);
  /// Proxy for the ACE_Handler that will be called back.
  ACE_Handler::Proxy_Ptr handler_proxy_;
  /// ACT for this operation.
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
 * @class ACE_WIN32_Asynch_Operation
 *
 * @brief This class abstracts out the common things needed for
 * implementing Asynch_Operation for WIN32 platform.
 *
 */
class ACE_Export ACE_WIN32_Asynch_Operation : public virtual ACE_Asynch_Operation_Impl
{
public:
  /**
   * Initializes the factory with information which will be used with
   * each asynchronous call.  If (<handle> == ACE_INVALID_HANDLE),
   * <ACE_Handler::handle> will be called on the @a handler to get the
   * correct handle.
   */
  int open (const ACE_Handler::Proxy_Ptr &handler_proxy,
            ACE_HANDLE handle,
            const void *completion_key,
            ACE_Proactor *proactor);
  /**
   * This cancels all pending accepts operations that were issued by
   * the calling thread.  The function does not cancel asynchronous
   * operations issued by other threads.
   */
  int cancel (void);
  // = Access methods.
  /// Return the underlying proactor.
  ACE_Proactor* proactor (void) const;
protected:
  /// Constructor.
  ACE_WIN32_Asynch_Operation (ACE_WIN32_Proactor *win32_proactor);
  /// Destructor.
  virtual ~ACE_WIN32_Asynch_Operation (void);
  /// Win32 Proactor.
  ACE_WIN32_Proactor *win32_proactor_;
  /// Proactor that this asynch IO is registered with.
  ACE_Proactor *proactor_;
  /// Handler that will receive the callback.
  ACE_Handler::Proxy_Ptr handler_proxy_;
  /// I/O handle used for reading.
  ACE_HANDLE handle_;
};
/**
 * @class ACE_WIN32_Asynch_Read_Stream_Result
 *
 * @brief This class provides concrete implementation for
 * ACE_Asynch_Read_Stream::Result class.
 */
class ACE_Export ACE_WIN32_Asynch_Read_Stream_Result : public virtual ACE_Asynch_Read_Stream_Result_Impl,
                                                       public ACE_WIN32_Asynch_Result
{
  /// Factory class will have special permissions.
  friend class ACE_WIN32_Asynch_Read_Stream;
  /// Proactor class has special permission.
  friend class ACE_WIN32_Proactor;
public:
  /// The number of bytes which were requested at the start of the
  /// asynchronous read.
  size_t bytes_to_read (void) const;
  /// Message block which contains the read data.
  ACE_Message_Block &message_block (void) const;
  /// I/O handle used for reading.
  ACE_HANDLE handle (void) const;
  // Base class operations. These operations are here to kill
  // dominance warnings. These methods call the base class methods.
  /// Number of bytes transferred by the operation.
  size_t bytes_transferred (void) const;
  /// ACT associated with the operation.
  const void *act (void) const;
  /// Did the operation succeed?
  int success (void) const;
  /**
   * This returns the ACT associated with the handle when it was
   * registered with the I/O completion port.  This ACT is not the
   * same as the ACT associated with the asynchronous operation.
   */
  const void *completion_key (void) const;
  /// Error value if the operation fail.
  u_long error (void) const;
  /// Event associated with the OVERLAPPED structure.
  ACE_HANDLE event (void) const;
  /// This really make sense only when doing file I/O.
  u_long offset (void) const;
  /// Offset_high associated with the OVERLAPPED structure.
  u_long offset_high (void) const;
  /// The priority of the asynchronous operation. Currently, this is
  /// not supported on Win32.
  int priority (void) const;
  /// No-op. Returns 0.
  int signal_number (void) const;
  /// Post @c this to the Proactor's completion port.
  int post_completion (ACE_Proactor_Impl *proactor);
  /// Accessor for the scatter read flag
  int scatter_enabled (void) const;
protected:
  /// Constructor is protected since creation is limited to
  /// ACE_Asynch_Read_Stream factory.
  ACE_WIN32_Asynch_Read_Stream_Result (const ACE_Handler::Proxy_Ptr &handler_proxy,
                                       ACE_HANDLE handle,
                                       ACE_Message_Block &message_block,
                                       size_t bytes_to_read,
                                       const void* act,
                                       ACE_HANDLE event,
                                       int priority,
                                       int signal_number = 0,
                                       int scatter_enabled = 0);
  /// Proactor will call this method when the read completes.
  virtual void complete (size_t bytes_transferred,
                         int success,
                         const void *completion_key,
                         u_long error);
  /// Destructor.
  virtual ~ACE_WIN32_Asynch_Read_Stream_Result (void);
  /// Bytes requested when the asynchronous read was initiated.
  size_t bytes_to_read_;
  /// Message block for reading the data into.
  ACE_Message_Block &message_block_;
  /// I/O handle used for reading.
  ACE_HANDLE handle_;
  /// Flag for scatter read
  int scatter_enabled_;
};
/**
 * @class ACE_WIN32_Asynch_Read_Stream
 *
 * @brief This class is a factory for starting off asynchronous reads
 *     on a stream.
 *
 *     Once <open> is called, multiple asynchronous <read>s can
 *     started using this class.  An ACE_Asynch_Read_Stream::Result
 *     will be passed back to the @a handler when the asynchronous
 *     reads completes through the <ACE_Handler::handle_read_stream>
 *     callback.
 */
class ACE_Export ACE_WIN32_Asynch_Read_Stream : public virtual ACE_Asynch_Read_Stream_Impl,
                                                public ACE_WIN32_Asynch_Operation
{
public:
  /// Constructor.
  ACE_WIN32_Asynch_Read_Stream (ACE_WIN32_Proactor *win32_proactor);
  /// This starts off an asynchronous read.  Upto @a bytes_to_read will
  /// be read and stored in the @a message_block.
  int read (ACE_Message_Block &message_block,
            size_t bytes_to_read,
            const void *act,
            int priority,
            int signal_number = 0);
  /**
  * Same as above but with scatter support, through chaining of composite
  * message blocks using the continuation field.
  */
  int readv (ACE_Message_Block &message_block,
             size_t bytes_to_read,
             const void *act,
             int priority,
             int signal_number = 0);
  /// Destructor.
  virtual ~ACE_WIN32_Asynch_Read_Stream (void);
  // Methods belong to ACE_WIN32_Asynch_Operation base class. These
  // methods are defined here to avoid VC++ warnings. They route the
  // call to the ACE_WIN32_Asynch_Operation base class.
  /**
   * Initializes the factory with information which will be used with
   * each asynchronous call.  If (<handle> == ACE_INVALID_HANDLE),
   * <ACE_Handler::handle> will be called on the @a handler to get the
   * correct handle.
   */
  int open (const ACE_Handler::Proxy_Ptr &handler_proxy,
            ACE_HANDLE handle,
            const void *completion_key,
            ACE_Proactor *proactor);
  /**
   * This cancels all pending accepts operations that were issued by
   * the calling thread.  The function does not cancel asynchronous
   * operations issued by other threads.
   */
  int cancel (void);
  /// Return the underlying proactor.
  ACE_Proactor* proactor (void) const;
protected:
  /// This is the method which does the real work and is there so that
  /// the ACE_Asynch_Read_File class can use it too.
  int shared_read (ACE_WIN32_Asynch_Read_Stream_Result *result);
};
/**
 * @class ACE_WIN32_Asynch_Write_Stream_Result
 *
 * @brief This class provides concrete implementation for
 *    ACE_Asynch_Write_Stream::Result class.
 */
class ACE_Export ACE_WIN32_Asynch_Write_Stream_Result : public virtual ACE_Asynch_Write_Stream_Result_Impl,
                                                        public ACE_WIN32_Asynch_Result
{
  /// Factory class willl have special permissions.
  friend class ACE_WIN32_Asynch_Write_Stream;
  /// Proactor class has special permission.
  friend class ACE_WIN32_Proactor;
public:
  /// The number of bytes which were requested at the start of the
  /// asynchronous write.
  size_t bytes_to_write (void) const;
  /// Message block that contains the data to be written.
  ACE_Message_Block &message_block (void) const;
  /// I/O handle used for writing.
  ACE_HANDLE handle (void) const;
  // = Base class operations. These operations are here to kill some
  //   warnings. These methods call the base class methods.
  /// Number of bytes transferred by the operation.
  size_t bytes_transferred (void) const;
  /// ACT associated with the operation.
  const void *act (void) const;
  /// Did the operation succeed?
  int success (void) const;
  /**
   * This returns the ACT associated with the handle when it was
   * registered with the I/O completion port.  This ACT is not the
   * same as the ACT associated with the asynchronous operation.
   */
  const void *completion_key (void) const;
  /// Error value if the operation fail.
  u_long error (void) const;
  /// Event associated with the OVERLAPPED structure.
  ACE_HANDLE event (void) const;
  /// This really make sense only when doing file I/O.
  u_long offset (void) const;
  /// Offset_high associated with the OVERLAPPED structure.
  u_long offset_high (void) const;
  /// The priority of the asynchronous operation. Currently, this is
  /// not supported on Win32.
  int priority (void) const;
  /// No-op. Returns 0.
  int signal_number (void) const;
  /// Post @c this to the Proactor's completion port.
  int post_completion (ACE_Proactor_Impl *proactor);
  /// Accessor for the gather write flag
  int gather_enabled (void) const;
protected:
  /// Constructor is protected since creation is limited to
  /// ACE_Asynch_Write_Stream factory.
  ACE_WIN32_Asynch_Write_Stream_Result (const ACE_Handler::Proxy_Ptr &handler_proxy,
                                        ACE_HANDLE handle,
                                        ACE_Message_Block &message_block,
                                        size_t bytes_to_write,
                                        const void* act,
                                        ACE_HANDLE event,
                                        int priority,
                                        int signal_number = 0,
                                        int gather_enabled = 0);
  /// ACE_Proactor will call this method when the write completes.
  virtual void complete (size_t bytes_transferred,
                         int success,
                         const void *completion_key,
                         u_long error);
  /// Destructor.
  virtual ~ACE_WIN32_Asynch_Write_Stream_Result (void);
  /// The number of bytes which were requested at the start of the
  /// asynchronous write.
  size_t bytes_to_write_;
  /// Message block that contains the data to be written.
  ACE_Message_Block &message_block_;
  /// I/O handle used for writing.
  ACE_HANDLE handle_;
  /// Flag for gather write
  int gather_enabled_;
};
/**
 * @class ACE_WIN32_Asynch_Write_Stream
 *
 * @brief This class is a factory for starting off asynchronous writes
 *    on a stream.
 *
 *
 *     Once <open> is called, multiple asynchronous <writes>s can
 *     started using this class.  A ACE_Asynch_Write_Stream::Result
 *     will be passed back to the @a handler when the asynchronous
 *     write completes through the
 *     <ACE_Handler::handle_write_stream> callback.
 */
class ACE_Export ACE_WIN32_Asynch_Write_Stream : public virtual ACE_Asynch_Write_Stream_Impl,
                                                 public ACE_WIN32_Asynch_Operation
{
public:
  /// Constructor.
  ACE_WIN32_Asynch_Write_Stream (ACE_WIN32_Proactor *win32_proactor);
  /// This starts off an asynchronous write.  Upto @a bytes_to_write
  /// will be written from the @a message_block.
  int write (ACE_Message_Block &message_block,
             size_t bytes_to_write,
             const void *act,
             int priority,
             int signal_number = 0);
  /**
  * Same as above but with gather support, through chaining of composite
  * message blocks using the continuation field.
  */
  int writev (ACE_Message_Block &message_block,
              size_t bytes_to_write,
              const void *act,
              int priority,
              int signal_number = 0);
  /// Destructor.
  virtual ~ACE_WIN32_Asynch_Write_Stream (void);
  // = Methods belonging to <ACE_WIN32_Asynch_Operation> base class.
  // These methods are defined here to avoid VC++ warnings. They route
  // the call to the <ACE_WIN32_Asynch_Operation> base class.
  /**
   * Initializes the factory with information which will be used with
   * each asynchronous call.  If (<handle> == ACE_INVALID_HANDLE),
   * <ACE_Handler::handle> will be called on the @a handler to get the
   * correct handle.
   */
  int open (const ACE_Handler::Proxy_Ptr &handler_proxy,
            ACE_HANDLE handle,
            const void *completion_key,
            ACE_Proactor *proactor);
  /**
   * This cancels all pending accepts operations that were issued by
   * the calling thread.  The function does not cancel asynchronous
   * operations issued by other threads.
   */
  int cancel (void);
  /// Return the underlying proactor.
  ACE_Proactor* proactor (void) const;
protected:
  /// This is the method which does the real work and is there so that
  /// the ACE_Asynch_Write_File class can use it too.
  int shared_write (ACE_WIN32_Asynch_Write_Stream_Result *result);
};
/**
 * @class ACE_WIN32_Asynch_Read_File_Result
 *
 * @brief This class provides concrete implementation for
 *     ACE_Asynch_Read_File::Result class.
 */
class ACE_Export ACE_WIN32_Asynch_Read_File_Result : public virtual ACE_Asynch_Read_File_Result_Impl,
                                                     public ACE_WIN32_Asynch_Read_Stream_Result
{
  /// Factory class will have special permissions.
  friend class ACE_WIN32_Asynch_Read_File;
  /// Proactor class has special permission.
  friend class ACE_WIN32_Proactor;
public:
  // = These methods belong to ACE_WIN32_Asynch_Result class base
  //   class. These operations are here to kill some warnings. These
  //   methods call the base class methods.
  /// Number of bytes transferred by the operation.
  size_t bytes_transferred (void) const;
  /// ACT associated with the operation.
  const void *act (void) const;
  /// Did the operation succeed?
  int success (void) const;
  /**
   * This returns the ACT associated with the handle when it was
   * registered with the I/O completion port.  This ACT is not the
   * same as the ACT associated with the asynchronous operation.
   */
  const void *completion_key (void) const;
  /// Error value if the operation fail.
  u_long error (void) const;
  /// Event associated with the OVERLAPPED structure.
  ACE_HANDLE event (void) const;
  /// This really make sense only when doing file I/O.
  u_long offset (void) const;
  /// Offset_high associated with the OVERLAPPED structure.
  u_long offset_high (void) const;
  /// The priority of the asynchronous operation. Currently, this is
  /// not supported on Win32.
  int priority (void) const;
  /// No-op. Returns 0.
  int signal_number (void) const;
  // The following methods belong to
  // ACE_WIN32_Asynch_Read_Stream_Result. They are here to avoid VC++
  // dominance warnings. These methods route their call to the
  // ACE_WIN32_Asynch_Read_Stream_Result base class.
  /// The number of bytes which were requested at the start of the
  /// asynchronous read.
  size_t bytes_to_read (void) const;
  /// Message block which contains the read data.
  ACE_Message_Block &message_block (void) const;
  /// I/O handle used for reading.
  ACE_HANDLE handle (void) const;
  /// Post @c this to the Proactor's completion port.
  int post_completion (ACE_Proactor_Impl *proactor);
protected:
  /// Constructor is protected since creation is limited to
  /// ACE_Asynch_Read_File factory.
  ACE_WIN32_Asynch_Read_File_Result (const ACE_Handler::Proxy_Ptr &handler_proxy,
                                     ACE_HANDLE handle,
                                     ACE_Message_Block &message_block,
                                     size_t bytes_to_read,
                                     const void* act,
                                     u_long offset,
                                     u_long offset_high,
                                     ACE_HANDLE event,
                                     int priority,
                                     int signal_number = 0,
                                     int scatter_enabled = 0);
  /// ACE_Proactor will call this method when the read completes.
  virtual void complete (size_t bytes_transferred,
                         int success,
                         const void *completion_key,
                         u_long error);
  /// Destructor.
  virtual ~ACE_WIN32_Asynch_Read_File_Result (void);
};
/**
 * @class ACE_WIN32_Asynch_Read_File
 *
 * @brief This class is a factory for starting off asynchronous reads
 *     on a file.
 *
 *     Once <open> is called, multiple asynchronous <read>s can
 *     started using this class.  A ACE_Asynch_Read_File::Result
 *     will be passed back to the @a handler when the asynchronous
 *     reads completes through the <ACE_Handler::handle_read_file>
 *     callback.
 *
 *     This class differs slightly from ACE_Asynch_Read_Stream as it
 *     allows the user to specify an offset for the read.
 */
class ACE_Export ACE_WIN32_Asynch_Read_File : public virtual ACE_Asynch_Read_File_Impl,
                                              public ACE_WIN32_Asynch_Read_Stream
{
public:
  /// Constructor.
  ACE_WIN32_Asynch_Read_File (ACE_WIN32_Proactor *win32_proactor);
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
  /**
  * Same as above but with scatter support, through chaining of
  * composite message blocks using the continuation field.
  * @note Each data block payload must be at least the size of a
  * system memory page and must be aligned on a system memory page
  * size boundary
  */
  int readv (ACE_Message_Block &message_block,
             size_t bytes_to_read,
             u_long offset,
             u_long offset_high,
             const void *act,
             int priority,
             int signal_number = 0);

  /// Destructor.
  virtual ~ACE_WIN32_Asynch_Read_File (void);
  // = Methods belong to ACE_WIN32_Asynch_Operation base class. These
  //   methods are defined here to avoid VC++ warnings. They route the
  //   call to the ACE_WIN32_Asynch_Operation base class.
  /**
   * Initializes the factory with information which will be used with
   * each asynchronous call.  If (<handle> == ACE_INVALID_HANDLE),
   * <ACE_Handler::handle> will be called on the @a handler to get the
   * correct handle.
   */
  int open (const ACE_Handler::Proxy_Ptr &handler_proxy,
            ACE_HANDLE handle,
            const void *completion_key,
            ACE_Proactor *proactor);
  /**
   * This cancels all pending accepts operations that were issued by
   * the calling thread.  The function does not cancel asynchronous
   * operations issued by other threads.
   */
  int cancel (void);
  /// Return the underlying proactor.
  ACE_Proactor* proactor (void) const;
private:
  /**
   * This method belongs to ACE_WIN32_Asynch_Read_Stream. It is here
   * to avoid the compiler warnings. We forward this call to the
   * ACE_WIN32_Asynch_Read_Stream class.
   */
  int read (ACE_Message_Block &message_block,
            size_t bytes_to_read,
            const void *act,
            int priority,
            int signal_number = 0);
  /**
  * Same as above but with scatter support, through chaining of composite
  * message blocks using the continuation field.
  */
  int readv (ACE_Message_Block &message_block,
             size_t bytes_to_read,
             const void *act,
             int priority,
             int signal_number = 0);
};
/**
 * @class ACE_WIN32_Asynch_Write_File_Result
 *
 * @brief  This class provides implementation for
 *      ACE_Asynch_Write_File_Result for WIN32 platforms.
 *
 *     This class has all the information necessary for the
 *     @a handler to uniquiely identify the completion of the
 *     asynchronous write.
 *
 *     This class differs slightly from
 *     ACE_Asynch_Write_Stream::Result as it calls back
 *     <ACE_Handler::handle_write_file> on the @a handler instead
 *     of <ACE_Handler::handle_write_stream>.  No additional state
 *     is required by this class as ACE_Asynch_Result can store
 *     the @a offset.
 */
class ACE_Export ACE_WIN32_Asynch_Write_File_Result : public virtual ACE_Asynch_Write_File_Result_Impl,
                                                      public ACE_WIN32_Asynch_Write_Stream_Result
{
  /// Factory class will have special permission.
  friend class ACE_WIN32_Asynch_Write_File;
  /// Proactor class has special permission.
  friend class ACE_WIN32_Proactor;
public:
  // = Base class operations. These operations are here to kill some
  //   warnings. These methods call the base class methods.
  /// Number of bytes transferred by the operation.
  size_t bytes_transferred (void) const;
  /// ACT associated with the operation.
  const void *act (void) const;
  /// Did the operation succeed?
  int success (void) const;
  /**
   * This returns the ACT associated with the handle when it was
   * registered with the I/O completion port.  This ACT is not the
   * same as the ACT associated with the asynchronous operation.
   */
  const void *completion_key (void) const;
  /// Error value if the operation fail.
  u_long error (void) const;
  /// Event associated with the OVERLAPPED structure.
  ACE_HANDLE event (void) const;
  /// This really make sense only when doing file I/O.
  u_long offset (void) const;
  /// Offset_high associated with the OVERLAPPED structure.
  u_long offset_high (void) const;
  /// The priority of the asynchronous operation. Currently, this is
  /// not supported on Win32.
  int priority (void) const;
  /// No-op. Returns 0.
  int signal_number (void) const;
  // The following methods belong to
  // ACE_WIN32_Asynch_Read_Stream_Result. They are here to avoid VC++
  // warnings. These methods route their call to the
  // ACE_WIN32_Asynch_Read_Stream_Result base class.
  /// The number of bytes which were requested at the start of the
  /// asynchronous write.
  size_t bytes_to_write (void) const;
  /// Message block that contains the data to be written.
  ACE_Message_Block &message_block (void) const;
  /// I/O handle used for writing.
  ACE_HANDLE handle (void) const;
  /// Post @c this to the Proactor's completion port.
  int post_completion (ACE_Proactor_Impl *proactor);
protected:
  /// Constructor is protected since creation is limited to
  /// ACE_Asynch_Write_File factory.
  ACE_WIN32_Asynch_Write_File_Result (const ACE_Handler::Proxy_Ptr &handler_proxy,
                                      ACE_HANDLE handle,
                                      ACE_Message_Block &message_block,
                                      size_t bytes_to_write,
                                      const void* act,
                                      u_long offset,
                                      u_long offset_high,
                                      ACE_HANDLE event,
                                      int priority,
                                      int signal_number = 0,
                                      int gather_enabled = 0);
  /// ACE_Proactor will call this method when the write completes.
  virtual void complete (size_t bytes_transferred,
                         int success,
                         const void *completion_key,
                         u_long error);
  /// Destructor.
  virtual ~ACE_WIN32_Asynch_Write_File_Result (void);
};
/**
 * @class ACE_WIN32_Asynch_Write_File
 *
 * @brief This class is a factory for starting off asynchronous writes
 *     on a file.
 *
 *     Once <open> is called, multiple asynchronous <write>s can be
 *     started using this class.  A ACE_Asynch_Write_File::Result
 *     will be passed back to the @a handler when the asynchronous
 *     writes completes through the <ACE_Handler::handle_write_file>
 *     callback.
 */
class ACE_Export ACE_WIN32_Asynch_Write_File : public virtual ACE_Asynch_Write_File_Impl,
                                               public ACE_WIN32_Asynch_Write_Stream
{
public:
  /// Constructor.
  ACE_WIN32_Asynch_Write_File (ACE_WIN32_Proactor *win32_proactor);
  /**
   * This starts off an asynchronous write.  Upto @a bytes_to_write
   * will be write and stored in the @a message_block.  The write will
   * start at @a offset from the beginning of the file.
   */
  int write (ACE_Message_Block &message_block,
             size_t bytes_to_write,
             u_long offset,
             u_long offset_high,
             const void *act,
             int priority,
             int signal_number = 0);
  /**
  * Same as above but with gather support, through chaining of
  * composite message blocks using the continuation field.
  * @note Each data block payload must be at least the size of a
  * system memory page and must be aligned on a system memory page
  * size boundary
  */
  int writev (ACE_Message_Block &message_block,
              size_t bytes_to_write,
              u_long offset,
              u_long offset_high,
              const void *act,
              int priority,
              int signal_number = 0);
  /// Destrcutor.
  virtual ~ACE_WIN32_Asynch_Write_File (void);
  // = Methods belong to ACE_WIN32_Asynch_Operation base class. These
  //   methods are defined here to avoid VC++ warnings. They route the
  //   call to the ACE_WIN32_Asynch_Operation base class.
  /**
   * Initializes the factory with information which will be used with
   * each asynchronous call.  If (<handle> == ACE_INVALID_HANDLE),
   * <ACE_Handler::handle> will be called on the @a handler to get the
   * correct handle.
   */
  int open (const ACE_Handler::Proxy_Ptr &handler_proxy,
            ACE_HANDLE handle,
            const void *completion_key,
            ACE_Proactor *proactor);
  /**
   * This cancels all pending accepts operations that were issued by
   * the calling thread.  The function does not cancel asynchronous
   * operations issued by other threads.
   */
  int cancel (void);
  /// Return the underlying proactor.
  ACE_Proactor* proactor (void) const;
private:
  /**
   * This method belongs to ACE_WIN32_Asynch_Write_Stream. It is here
   * to avoid compiler warnings. This method is forwarded to the
   * ACE_WIN32_Asynch_Write_Stream class.
   */
  int write (ACE_Message_Block &message_block,
             size_t bytes_to_write,
             const void *act,
             int priority,
             int signal_number = 0);
  /**
  * Same as above but with gather support, through chaining of composite
  * message blocks using the continuation field.
  */
  int writev (ACE_Message_Block &message_block,
              size_t bytes_to_write,
              const void *act,
              int priority,
              int signal_number = 0);
};
/**
 * @class ACE_WIN32_Asynch_Accept_Result
 *
 * @brief This class implements ACE_Asynch_Accept::Result for WIN32
 *     platform.
 *
 *     This class has all the information necessary for the
 *     @a handler to uniquiely identify the completion of the
 *     asynchronous accept.
 */
class ACE_Export ACE_WIN32_Asynch_Accept_Result : public virtual ACE_Asynch_Accept_Result_Impl,
                                                  public ACE_WIN32_Asynch_Result
{
  /// Factory will have special permission.
  friend class ACE_WIN32_Asynch_Accept;
  /// Proactor class has special permission.
  friend class ACE_WIN32_Proactor;
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
  // = Base class operations. These operations are here to kill some
  //   warnings. These methods call the base class methods.
  /// Number of bytes transferred by the operation.
  size_t bytes_transferred (void) const;
  /// ACT associated with the operation.
  const void *act (void) const;
  /// Did the operation succeed?
  int success (void) const;
  /**
   * This returns the ACT associated with the handle when it was
   * registered with the I/O completion port.  This ACT is not the
   * same as the ACT associated with the asynchronous operation.
   */
  const void *completion_key (void) const;
  /// Error value if the operation fail.
  u_long error (void) const;
  /// Event associated with the OVERLAPPED structure.
  ACE_HANDLE event (void) const;
  /// This really make sense only when doing file I/O.
  u_long offset (void) const;
  /// Offset_high associated with the OVERLAPPED structure.
  u_long offset_high (void) const;
  /// The priority of the asynchronous operation. Currently, this is
  /// not supported on Win32.
  int priority (void) const;
  /// No-op. Returns 0.
  int signal_number (void) const;
  /// Post @c this to the Proactor's completion port.
  int post_completion (ACE_Proactor_Impl *proactor);
protected:
  /// Constructor is protected since creation is limited to
  /// ACE_Asynch_Accept factory.
  ACE_WIN32_Asynch_Accept_Result (const ACE_Handler::Proxy_Ptr &handler_proxy,
                                  ACE_HANDLE listen_handle,
                                  ACE_HANDLE accept_handle,
                                  ACE_Message_Block &message_block,
                                  size_t bytes_to_read,
                                  const void* act,
                                  ACE_HANDLE event,
                                  int priority,
                                  int signal_number = 0);
  /// ACE_Proactor will call this method when the accept completes.
  virtual void complete (size_t bytes_transferred,
                         int success,
                         const void *completion_key,
                         u_long error);
  /// Destructor.
  virtual ~ACE_WIN32_Asynch_Accept_Result (void);
  /// Bytes requested when the asynchronous read was initiated.
  size_t bytes_to_read_;
  /// Message block for reading the data into.
  ACE_Message_Block &message_block_;
  /// I/O handle used for accepting new connections.
  ACE_HANDLE listen_handle_;
  /// I/O handle for the new connection.
  ACE_HANDLE accept_handle_;
};
/**
 * @class ACE_WIN32_Asynch_Accept
 *
 * @brief This class is a factory for starting off asynchronous accepts
 *     on a listen handle.
 *
 *     Once <open> is called, multiple asynchronous <accept>s can
 *     started using this class.  A ACE_Asynch_Accept::Result will
 *     be passed back to the @a handler when the asynchronous accept
 *     completes through the <ACE_Handler::handle_accept>
 *     callback.
 */
class ACE_Export ACE_WIN32_Asynch_Accept : public virtual ACE_Asynch_Accept_Impl,
                                           public ACE_WIN32_Asynch_Operation
{
public:
  /// Constructor.
  ACE_WIN32_Asynch_Accept (ACE_WIN32_Proactor *win32_proactor);
  /**
   * This starts off an asynchronous accept.  The asynchronous accept
   * call also allows any initial data to be returned to the
   * @a handler.  Upto @a bytes_to_read will be read and stored in the
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
  /// Destructor.
  ~ACE_WIN32_Asynch_Accept (void);
  // Methods belong to ACE_WIN32_Asynch_Operation base class. These
  // methods are defined here to avoid VC++ warnings. They route the
  // call to the ACE_WIN32_Asynch_Operation base class.
  /**
   * Initializes the factory with information which will be used with
   * each asynchronous call.  If (<handle> == ACE_INVALID_HANDLE),
   * <ACE_Handler::handle> will be called on the @a handler to get the
   * correct handle.
   */
  int open (const ACE_Handler::Proxy_Ptr &handler_proxy,
            ACE_HANDLE handle,
            const void *completion_key,
            ACE_Proactor *proactor);
  /**
   * This cancels all pending accepts operations that were issued by
   * the calling thread.  The function does not cancel asynchronous
   * operations issued by other threads.
   */
  int cancel (void);
  /// Return the underlying proactor.
  ACE_Proactor* proactor (void) const;
};
/**
 * @class ACE_WIN32_Asynch_Connect_Result
 *
 * @brief This is that class which will be passed back to the
 *        completion handler when the asynchronous connect completes.
 *
 *     This class has all the information necessary for the
 *     completion handler to uniquiely identify the completion of the
 *     asynchronous connect.
 */
class ACE_Export ACE_WIN32_Asynch_Connect_Result : public virtual ACE_Asynch_Connect_Result_Impl,
                                                   public ACE_WIN32_Asynch_Result
{
  /// Factory classes will have special permissions.
  friend class ACE_WIN32_Asynch_Connect;
  /// The Proactor constructs the Result class for faking results.
  friend class ACE_WIN32_Proactor;
public:
  /// I/O handle for the  connection.
  ACE_HANDLE connect_handle (void) const;
  // = Base class operations. These operations are here to kill some
  //   warnings. These methods call the base class methods.
  /// Number of bytes transferred by the operation.
  size_t bytes_transferred (void) const;
  /// ACT associated with the operation.
  const void *act (void) const;
  /// Did the operation succeed?
  int success (void) const;
  /**
   * Returns the ACT associated with the handle when it was
   * registered with the I/O completion port.  This ACT is not the
   * same as the ACT associated with the asynchronous operation.
   */
  const void *completion_key (void) const;
  /// Error value if the operation fail.
  u_long error (void) const;
  /// Event associated with the OVERLAPPED structure.
  ACE_HANDLE event (void) const;
  /// This really make sense only when doing file I/O.
  u_long offset (void) const;
  /// Offset_high associated with the OVERLAPPED structure.
  u_long offset_high (void) const;
  /// The priority of the asynchronous operation. Currently, this is
  /// not supported on Win32.
  int priority (void) const;
  /// No-op. Returns 0.
  int signal_number (void) const;
  /// Post this object to the Proactor's completion port.
  int post_completion (ACE_Proactor_Impl *proactor);
protected:
  /// Constructor is protected since creation is limited to
  /// ACE_Asynch_Connect factory.
  ACE_WIN32_Asynch_Connect_Result (const ACE_Handler::Proxy_Ptr &handler_proxy,
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
  virtual ~ACE_WIN32_Asynch_Connect_Result (void);
  /// Set the I/O handle for the new connection.
  void  connect_handle (ACE_HANDLE handle);
  ACE_HANDLE  connect_handle_;
};

/**
 * @class ACE_WIN32_Asynch_Connect
 */
class ACE_Export ACE_WIN32_Asynch_Connect :
  public virtual ACE_Asynch_Connect_Impl,
  public ACE_WIN32_Asynch_Operation,
  public ACE_Event_Handler
{
public:
  /// Constructor.
  ACE_WIN32_Asynch_Connect (ACE_WIN32_Proactor * win32_proactor);
  /// Destructor.
  virtual ~ACE_WIN32_Asynch_Connect (void);
 /**
   * This open belongs to ACE_WIN32_Asynch_Operation. We forward
   * this call to that method. We have put this here to avoid the
   * compiler warnings.
   */
  int open (const ACE_Handler::Proxy_Ptr &handler_proxy,
            ACE_HANDLE handle,
            const void *completion_key,
            ACE_Proactor *proactor = 0);
  /**
   * Start an asynchronous connect.
   *
   * @param connect_handle Handle to use for the connect. If the value
   *                       ACE_INVALID_HANDLE, a new handle will be created.
   *
   * @retval 0  Success
   * @retval -1 Error
   */
  int connect (ACE_HANDLE connect_handle,
               const ACE_Addr &remote_sap,
               const ACE_Addr &local_sap,
               int  reuse_addr,
               const void *act,
               int priority,
               int signal_number = 0);
  /**
   *  Cancel all pending pseudo-asynchronus requests
   *  Behavior as usual AIO request
   */
  int cancel (void);
  /**
   *  Close performs cancellation of all pending requests
   *  and close the connect handle
   */
  int close (void);
  /// Virtual from ACE_Event_Handler
  ACE_HANDLE get_handle (void) const;
  /// Virtual from ACE_Event_Handler
  void set_handle (ACE_HANDLE handle);
  /// Virtual from ACE_Event_Handler
  int handle_input  ( ACE_HANDLE handle);
  int handle_output ( ACE_HANDLE handle);
  int handle_exception ( ACE_HANDLE handle);
  /// Virtual from ACE_Event_Handler
  int handle_close (ACE_HANDLE handle, ACE_Reactor_Mask close_mask) ;
  // = Methods belong to ACE_WIN32_Asynch_Operation base class. These
  //   methods are defined here to avoid dominace warnings. They route
  //   the call to the ACE_WIN32_Asynch_Operation base class.
  /// Return the underlying proactor.
  ACE_Proactor* proactor (void) const;
private:
  int connect_i (ACE_WIN32_Asynch_Connect_Result *result,
                 const ACE_Addr &remote_sap,
                 const ACE_Addr &local_sap,
                 int reuse_addr);
  int post_result (ACE_WIN32_Asynch_Connect_Result *result, bool flg_post);
  /// Cancel uncompleted connect operations.
  /**
   * @param flg_notify Indicates whether or not to send notification about
   *                   canceled connect operations.  If false, don't send
   *                   notifications. If true, notify user about canceled
   *                   connects.
   *                   According WIN32 standards we should receive
   *                   notifications on canceled AIO requests.
   *
   * @param set        Receives the set of I/O handles on which asynchronous
   *                   connect requests were canceled as a result of this
   *                   method. The contents of @a set are completely
   *                   replaced.
   */
  int cancel_uncompleted (bool flg_notify, ACE_Handle_Set &set);
  /// true  - Connect is registered in ACE_Asynch_Pseudo_Task
  /// false - Accept is deregisted in ACE_Asynch_Pseudo_Task
  bool flg_open_ ;
  typedef ACE_Map_Manager<ACE_HANDLE, ACE_WIN32_Asynch_Connect_Result *, ACE_SYNCH_NULL_MUTEX>
          MAP_MANAGER;
  /// Map of Result pointers that correspond to all the <accept>'s
  /// pending.
  MAP_MANAGER result_map_;
  /// The lock to protect the result map which is shared. The queue
  /// is updated by main thread in the register function call and
  /// through the auxillary thread in the asynch pseudo task.
  ACE_SYNCH_MUTEX lock_;
};
/**
 * @class ACE_WIN32_Asynch_Transmit_File_Result
 *
 *
 * @brief This class implements ACE_Asynch_Transmit_File::Result for
 *     WIN32 platforms.
 *
 *     This class has all the information necessary for the
 *     @a handler to uniquiely identify the completion of the
 *     asynchronous transmit file.
 */
class ACE_Export ACE_WIN32_Asynch_Transmit_File_Result : public virtual ACE_Asynch_Transmit_File_Result_Impl,
                                                         public ACE_WIN32_Asynch_Result
{
  /// Factory class will have special permission.
  friend class ACE_WIN32_Asynch_Transmit_File;
  /// Proactor class has special permission.
  friend class ACE_WIN32_Proactor;
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
  // Base class operations. These operations are here to kill some
  // warnings. These methods call the base class methods.
  /// Number of bytes transferred by the operation.
  size_t bytes_transferred (void) const;
  /// ACT associated with the operation.
  const void *act (void) const;
  /// Did the operation succeed?
  int success (void) const;
  /**
   * This returns the ACT associated with the handle when it was
   * registered with the I/O completion port.  This ACT is not the
   * same as the ACT associated with the asynchronous operation.
   */
  const void *completion_key (void) const;
  /// Error value if the operation fail.
  u_long error (void) const;
  /// Event associated with the OVERLAPPED structure.
  ACE_HANDLE event (void) const;
  /// This really make sense only when doing file I/O.
  u_long offset (void) const;
  /// Offset_high associated with the OVERLAPPED structure.
  u_long offset_high (void) const;
  /// The priority of the asynchronous operation. Currently, this is
  /// not supported on Win32.
  int priority (void) const;
  /// No-op. Returns 0.
  int signal_number (void) const;
  /// Post @c this to the Proactor's completion port.
  int post_completion (ACE_Proactor_Impl *proactor);
protected:
  /// Constructor is protected since creation is limited to
  /// ACE_Asynch_Transmit_File factory.
  ACE_WIN32_Asynch_Transmit_File_Result (const ACE_Handler::Proxy_Ptr &handler_proxy,
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
                int signal_number = 0);
  /// Proactor will call this method when the write completes.
  virtual void complete (size_t bytes_transferred,
                         int success,
                         const void *completion_key,
                         u_long error);
  /// Destructor.
  virtual ~ACE_WIN32_Asynch_Transmit_File_Result (void);
  /// Network I/O handle.
  ACE_HANDLE socket_;
  /// File I/O handle.
  ACE_HANDLE file_;
  /// Header and trailer data associated with this transmit file.
  ACE_Asynch_Transmit_File::Header_And_Trailer *header_and_trailer_;
  /// The number of bytes which were requested at the start of the
  /// asynchronous transmit file.
  size_t bytes_to_write_;
  /// Number of bytes per send requested at the start of the transmit
  /// file.
  size_t bytes_per_send_;
  /// Flags which were passed into transmit file.
  u_long flags_;
};
/**
 * @class ACE_WIN32_Asynch_Transmit_File
 *
 * @brief This class is a factory for starting off asynchronous
 *     transmit files on a stream.
 *
 *     Once <open> is called, multiple asynchronous <transmit_file>s
 *     can started using this class.  A
 *     ACE_Asynch_Transmit_File::Result will be passed back to the
 *     @a handler when the asynchronous transmit file completes
 *     through the <ACE_Handler::handle_transmit_file> callback.
 *
 *     The transmit_file function transmits file data over a
 *     connected network connection. The function uses the operating
 *     system's cache manager to retrieve the file data. This
 *     function provides high-performance file data transfer over
 *     network connections.  This function would be of great use in
 *     a Web Server, Image Server, etc.
 */
class ACE_Export ACE_WIN32_Asynch_Transmit_File : public virtual ACE_Asynch_Transmit_File_Impl,
                                                  public ACE_WIN32_Asynch_Operation
{
public:
  /// Constructor.
  ACE_WIN32_Asynch_Transmit_File (ACE_WIN32_Proactor *win32_proactor);
  /**
   * This starts off an asynchronous transmit file. The <file> is a
   * handle to an open file.  <header_and_trailer> is a pointer to a
   * data structure that contains pointers to data to send before and
   * after the file data is sent.  Set this parameter to 0 if you only
   * want to transmit the file data.  Upto @a bytes_to_write will be
   * written to the <socket>.  If you want to send the entire file,
   * let @a bytes_to_write = 0.  @a bytes_per_send is the size of each
   * block of data sent per send operation.  Please read the Win32
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
  ~ACE_WIN32_Asynch_Transmit_File (void);
  // Methods belong to ACE_WIN32_Asynch_Operation base class. These
  // methods are defined here to avoid VC++ warnings. They route the
  // call to the ACE_WIN32_Asynch_Operation base class.
  /**
   * Initializes the factory with information which will be used with
   * each asynchronous call.  If (<handle> == ACE_INVALID_HANDLE),
   * <ACE_Handler::handle> will be called on the @a handler to get the
   * correct handle.
   */
  int open (const ACE_Handler::Proxy_Ptr &handler_proxy,
            ACE_HANDLE handle,
            const void *completion_key,
            ACE_Proactor *proactor);
  /**
   * This cancels all pending accepts operations that were issued by
   * the calling thread.  The function does not cancel asynchronous
   * operations issued by other threads.
   */
  int cancel (void);
  /// Return the underlying proactor.
  ACE_Proactor* proactor (void) const;
};
/**
 * @class ACE_WIN32_Asynch_Read_Dgram_Result
 *
 * @brief This class provides concrete implementation for
 * ACE_Asynch_Read_Dgram::Result class.
 */
class ACE_Export ACE_WIN32_Asynch_Read_Dgram_Result : public virtual ACE_Asynch_Read_Dgram_Result_Impl,
                                                      public ACE_WIN32_Asynch_Result
{
  /// Factory class will have special permissions.
  friend class ACE_WIN32_Asynch_Read_Dgram;
  /// Proactor class has special permission.
  friend class ACE_WIN32_Proactor;
public:
  /// The number of bytes which were requested at the start of the
  /// asynchronous read.
  size_t bytes_to_read (void) const;
  /// Message block which contains the read data
  ACE_Message_Block *message_block (void) const;
  /// The address of where the packet came from
  int remote_address (ACE_Addr& addr) const;
  sockaddr *saddr () const;
  /// The flags used in the read
  int flags (void) const;
  /// I/O handle used for reading.
  ACE_HANDLE handle (void) const;
  // Base class operations. These operations are here to kill
  // dominance warnings. These methods call the base class methods.
  /// Number of bytes transferred by the operation.
  size_t bytes_transferred (void) const;
  /// ACT associated with the operation.
  const void *act (void) const;
  /// Did the operation succeed?
  int success (void) const;
  /**
   * This returns the ACT associated with the handle when it was
   * registered with the I/O completion port.  This ACT is not the
   * same as the ACT associated with the asynchronous operation.
   */
  const void *completion_key (void) const;
  /// Error value if the operation fail.
  u_long error (void) const;
  /// Event associated with the OVERLAPPED structure.
  ACE_HANDLE event (void) const;
  /// This really make sense only when doing file I/O.
  u_long offset (void) const;
  /// Offset_high associated with the OVERLAPPED structure.
  u_long offset_high (void) const;
  /// The priority of the asynchronous operation. Currently, this is
  /// not supported on Win32.
  int priority (void) const;
  /// No-op. Returns 0.
  int signal_number (void) const;
  /// Post @c this to the Proactor's completion port.
  int post_completion (ACE_Proactor_Impl *proactor);
protected:
  /// Constructor is protected since creation is limited to
  /// ACE_Asynch_Read_Dgram factory.
  ACE_WIN32_Asynch_Read_Dgram_Result (const ACE_Handler::Proxy_Ptr &handler_proxy,
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
  virtual ~ACE_WIN32_Asynch_Read_Dgram_Result (void);
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
/**
 * @class ACE_WIN32_Asynch_Read_Dgram
 *
 * @brief This class is a factory for starting off asynchronous reads
 *     on a UDP socket.
 *
 *     Once <open> is called, multiple asynchronous <read>s can be
 *     started using this class.  An ACE_Asynch_Read_Dgram::Result
 *     will be passed back to the @a handler when the asynchronous
 *     reads completes through the <ACE_Handler::handle_read_stream>
 *     callback.
 *
 */
class ACE_Export ACE_WIN32_Asynch_Read_Dgram : public virtual ACE_Asynch_Read_Dgram_Impl,
                                               public ACE_WIN32_Asynch_Operation
{
public:
  /// Constructor.
  ACE_WIN32_Asynch_Read_Dgram (ACE_WIN32_Proactor *win32_proactor);
  /// Destructor.
  virtual ~ACE_WIN32_Asynch_Read_Dgram (void);
   /** This starts off an asynchronous read.  Upto
   * <message_block->total_size()> will be read and stored in the
   * @a message_block.  @a message_block's <wr_ptr> will be updated to reflect
   * the added bytes if the read operation is successfully completed.
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
   */
  virtual ssize_t recv (ACE_Message_Block *message_block,
                        size_t &number_of_bytes_recvd,
                        int flags,
                        int protocol_family,
                        const void *act,
                        int priority,
                        int signal_number);
  // Methods belong to ACE_WIN32_Asynch_Operation base class. These
  // methods are defined here to avoid VC++ warnings. They route the
  // call to the ACE_WIN32_Asynch_Operation base class.
  /**
   * Initializes the factory with information which will be used with
   * each asynchronous call.  If (<handle> == ACE_INVALID_HANDLE),
   * <ACE_Handler::handle> will be called on the @a handler to get the
   * correct handle.
   */
  int open (const ACE_Handler::Proxy_Ptr &handler_proxy,
            ACE_HANDLE handle,
            const void *completion_key,
            ACE_Proactor *proactor);
  /**
   * This cancels all pending accepts operations that were issued by
   * the calling thread.  The function does not cancel asynchronous
   * operations issued by other threads.
   */
  int cancel (void);
  /// Return the underlying proactor.
  ACE_Proactor* proactor (void) const;
protected:
  /// Do-nothing constructor.
  ACE_WIN32_Asynch_Read_Dgram (void);
};
/**
 * @class ACE_WIN32_Asynch_Write_Dgram_Result
 *
 * @brief This class provides concrete implementation for
 *    ACE_Asynch_Write_Dgram::Result class.
 */
class ACE_Export ACE_WIN32_Asynch_Write_Dgram_Result : public virtual ACE_Asynch_Write_Dgram_Result_Impl,
                                                       public ACE_WIN32_Asynch_Result
{
  /// Factory class willl have special permissions.
  friend class ACE_WIN32_Asynch_Write_Dgram;
  /// Proactor class has special permission.
  friend class ACE_WIN32_Proactor;
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
  // = Base class operations. These operations are here to kill some
  //   warnings. These methods call the base class methods.
  /// Number of bytes transferred by the operation.
  size_t bytes_transferred (void) const;
  /// ACT associated with the operation.
  const void *act (void) const;
  /// Did the operation succeed?
  int success (void) const;
  /**
   * This returns the ACT associated with the handle when it was
   * registered with the I/O completion port.  This ACT is not the
   * same as the ACT associated with the asynchronous operation.
   */
  const void *completion_key (void) const;
  /// Error value if the operation fail.
  u_long error (void) const;
  /// Event associated with the OVERLAPPED structure.
  ACE_HANDLE event (void) const;
  /// This really make sense only when doing file I/O.
  u_long offset (void) const;
  /// Offset_high associated with the OVERLAPPED structure.
  u_long offset_high (void) const;
  /// The priority of the asynchronous operation. Currently, this is
  /// not supported on Win32.
  int priority (void) const;
  /// No-op. Returns 0.
  int signal_number (void) const;
  /// Post @c this to the Proactor's completion port.
  int post_completion (ACE_Proactor_Impl *proactor);
protected:
  /// Constructor is protected since creation is limited to
  /// ACE_Asynch_Write_Stream factory.
  ACE_WIN32_Asynch_Write_Dgram_Result (const ACE_Handler::Proxy_Ptr &handler_proxy,
                                       ACE_HANDLE handle,
                                       ACE_Message_Block *message_block,
                                       size_t bytes_to_write,
                                       int flags,
                                       const void* act,
                                       ACE_HANDLE event,
                                       int priority,
                                       int signal_number = 0);
  /// ACE_Proactor will call this method when the write completes.
  virtual void complete (size_t bytes_transferred,
                         int success,
                         const void *completion_key,
                         u_long error);
  /// Destructor.
  virtual ~ACE_WIN32_Asynch_Write_Dgram_Result (void);
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
 * @class ACE_WIN32_Asynch_Write_Dgram
 *
 * @brief This class is a factory for starting off asynchronous writes
 *    on a UDP socket.
 *
 *
 *     Once <open> is called, multiple asynchronous <writes>s can
 *     started using this class.  A ACE_Asynch_Write_Stream::Result
 *     will be passed back to the @a handler when the asynchronous
 *     write completes through the
 *     <ACE_Handler::handle_write_stream> callback.
 */
class ACE_Export ACE_WIN32_Asynch_Write_Dgram : public virtual ACE_Asynch_Write_Dgram_Impl,
                                                public ACE_WIN32_Asynch_Operation
{
public:
  /// Constructor.
  ACE_WIN32_Asynch_Write_Dgram (ACE_WIN32_Proactor *win32_proactor);
  /// Destructor.
  virtual ~ACE_WIN32_Asynch_Write_Dgram (void);
  /** This starts off an asynchronous send.  Upto
   * <message_block->total_length()> will be sent.  @a message_block's
   * <rd_ptr> will be updated to reflect the sent bytes if the send operation
   * is successfully completed.
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
   */
  virtual ssize_t send (ACE_Message_Block *message_block,
                        size_t &number_of_bytes_sent,
                        int flags,
                        const ACE_Addr &addr,
                        const void *act,
                        int priority,
                        int signal_number);
  // = Methods belonging to <ACE_WIN32_Asynch_Operation> base class.
  // These methods are defined here to avoid VC++ warnings. They route
  // the call to the <ACE_WIN32_Asynch_Operation> base class.
  /**
   * Initializes the factory with information which will be used with
   * each asynchronous call.  If (<handle> == ACE_INVALID_HANDLE),
   * <ACE_Handler::handle> will be called on the @a handler to get the
   * correct handle.
   */
  int open (const ACE_Handler::Proxy_Ptr &handler_proxy,
            ACE_HANDLE handle,
            const void *completion_key,
            ACE_Proactor *proactor);
  /**
   * This cancels all pending accepts operations that were issued by
   * the calling thread.  The function does not cancel asynchronous
   * operations issued by other threads.
   */
  int cancel (void);
  /// Return the underlying proactor.
  ACE_Proactor* proactor (void) const;
protected:
  /// Do-nothing constructor.
  ACE_WIN32_Asynch_Write_Dgram (void);
};
ACE_END_VERSIONED_NAMESPACE_DECL
#endif /* ACE_HAS_WIN32_OVERLAPPED_IO && ACE_HAS_WINSOCK2 */
#include /**/ "ace/post.h"
#endif /* ACE_WIN32_ASYNCH_IO_H */

