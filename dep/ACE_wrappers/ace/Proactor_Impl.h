// -*- C++ -*-

//=============================================================================
/**
 *  @file    Proactor_Impl.h
 *
 *  $Id: Proactor_Impl.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Alexander Babu Arulanthu <alex@cs.wustl.edu>
 *  @author Alexander Libman <alibman@ihug.com.au>
 */
//=============================================================================


#ifndef ACE_PROACTOR_IMPL_H
#define ACE_PROACTOR_IMPL_H
#include /**/ "ace/pre.h"

#include /**/ "ace/config-all.h"

#if defined (ACE_HAS_WIN32_OVERLAPPED_IO) || defined (ACE_HAS_AIO_CALLS)
// This only works on standard Win32 platforms and on Unix platforms supporting
// aio calls.

#include "ace/Asynch_IO.h"
#include "ace/Reactor.h"
#include "ace/Countdown_Time.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class ACE_Proactor_Impl
 *
 * @brief A manager for asynchronous event demultiplexing. This class
 * is the base class for all the concrete implementation
 * classes.
 *
 * See the Proactor pattern description at
 * http://www.cs.wustl.edu/~schmidt/proactor.ps.gz for more
 * details.
 */
class ACE_Export ACE_Proactor_Impl : public ACE_Event_Handler
{

public:
  /// Virtual destruction.
  virtual ~ACE_Proactor_Impl (void);

  /// Close the IO completion port.
  virtual int close (void) = 0;

  /// This method adds the @a handle to the I/O completion port. This
  /// function is a no-op function for Unix systems.
  virtual int register_handle (ACE_HANDLE handle,
                               const void *completion_key) = 0;

  /**
   * Dispatch a single set of events.  If @a wait_time elapses before
   * any events occur, return 0.  Return 1 on success i.e., when a
   * completion is dispatched, non-zero (-1) on errors and errno is
   * set accordingly.
   */
  virtual int handle_events (ACE_Time_Value &wait_time) = 0;

  /**
   * Block indefinitely until at least one event is dispatched.
   * Dispatch a single set of events.  If <wait_time> elapses before
   * any events occur, return 0.  Return 1 on success i.e., when a
   * completion is dispatched, non-zero (-1) on errors and errno is
   * set accordingly.
   */
  virtual int handle_events (void) = 0;

  /// Add wakeup dispatch threads (reinit).
  virtual int wake_up_dispatch_threads (void) = 0;

  /// Close all dispatch threads.
  virtual int close_dispatch_threads (int wait) = 0;

  /// Get number of thread used as a parameter to CreatIoCompletionPort.
  virtual size_t number_of_threads (void) const = 0;

  /// Set number of thread used as a parameter to CreatIoCompletionPort.
  virtual void number_of_threads (size_t threads) = 0;

  /// Get the event handle.
  virtual ACE_HANDLE get_handle (void) const = 0;

  //
  // = Factory methods for the operations
  //
  // Note that the user does not have to use or know about these
  // methods.

  /// Create the correct implementation class for doing Asynch_Read_Stream.
  virtual ACE_Asynch_Read_Stream_Impl *create_asynch_read_stream (void) = 0;

  /// Create the correct implementation class for doing Asynch_Write_Stream.
  virtual ACE_Asynch_Write_Stream_Impl *create_asynch_write_stream (void) = 0;

  /// Create the correct implementation class for doing Asynch_Read_File.
  virtual ACE_Asynch_Read_File_Impl *create_asynch_read_file (void) = 0;

    /// Create the correct implementation class for doing Asynch_Write_File.
  virtual ACE_Asynch_Write_File_Impl *create_asynch_write_file (void) = 0;

  /// Create the correct implementation class for doing Asynch_Accept.
  virtual ACE_Asynch_Accept_Impl *create_asynch_accept (void) = 0;

  /// Create the correct implementation class for doing Asynch_Connect.
  virtual ACE_Asynch_Connect_Impl *create_asynch_connect (void) = 0;

  /// Create the correct implementation class for doing Asynch_Transmit_File.
  virtual ACE_Asynch_Transmit_File_Impl *create_asynch_transmit_file (void) = 0;

  /// Create the correct implementation class for doing
  /// Asynch_Read_Dgram.
  virtual ACE_Asynch_Read_Dgram_Impl *create_asynch_read_dgram (void) = 0;

  /// Create the correct implementation class for doing
  /// Asynch_Write_Dgram.
  virtual ACE_Asynch_Write_Dgram_Impl *create_asynch_write_dgram (void) = 0;

  //
  // = Factory methods for the results
  //
  // Note that the user does not have to use or know about these
  // methods unless they want to "fake" results.

  /// Create the correct implementation class for ACE_Asynch_Read_Stream::Result class.
  virtual ACE_Asynch_Read_Stream_Result_Impl *
    create_asynch_read_stream_result (const ACE_Handler::Proxy_Ptr &handler_proxy,
                                      ACE_HANDLE handle,
                                      ACE_Message_Block &message_block,
                                      size_t bytes_to_read,
                                      const void* act,
                                      ACE_HANDLE event = ACE_INVALID_HANDLE,
                                      int priority = 0,
                                      int signal_number = ACE_SIGRTMIN) = 0;

  /// Create the correct implementation class for ACE_Asynch_Write_Stream::Result.
  virtual ACE_Asynch_Write_Stream_Result_Impl *
    create_asynch_write_stream_result (const ACE_Handler::Proxy_Ptr &handler_proxy,
                                       ACE_HANDLE handle,
                                       ACE_Message_Block &message_block,
                                       size_t bytes_to_write,
                                       const void* act,
                                       ACE_HANDLE event = ACE_INVALID_HANDLE,
                                       int priority = 0,
                                       int signal_number = ACE_SIGRTMIN) = 0;

  /// Create the correct implementation class for ACE_Asynch_Read_File::Result.
  virtual ACE_Asynch_Read_File_Result_Impl *
    create_asynch_read_file_result (const ACE_Handler::Proxy_Ptr &handler_proxy,
                                    ACE_HANDLE handle,
                                    ACE_Message_Block &message_block,
                                    size_t bytes_to_read,
                                    const void* act,
                                    u_long offset,
                                    u_long offset_high,
                                    ACE_HANDLE event = ACE_INVALID_HANDLE,
                                    int priority = 0,
                                    int signal_number = ACE_SIGRTMIN) = 0;

    /// Create the correct implementation class for ACE_Asynch_Write_File::Result.
  virtual ACE_Asynch_Write_File_Result_Impl *
    create_asynch_write_file_result (const ACE_Handler::Proxy_Ptr &handler,
                                     ACE_HANDLE handle,
                                     ACE_Message_Block &message_block,
                                     size_t bytes_to_write,
                                     const void* act,
                                     u_long offset,
                                     u_long offset_high,
                                     ACE_HANDLE event = ACE_INVALID_HANDLE,
                                     int priority = 0,
                                     int signal_number = ACE_SIGRTMIN) = 0;

  /// Create the correct implementation class for ACE_Asynch_Read_Dgram::Result.
  virtual ACE_Asynch_Read_Dgram_Result_Impl *
    create_asynch_read_dgram_result (const ACE_Handler::Proxy_Ptr &handler_proxy,
                                     ACE_HANDLE handle,
                                     ACE_Message_Block *message_block,
                                     size_t bytes_to_read,
                                     int flags,
                                     int protocol_family,
                                     const void* act,
                                     ACE_HANDLE event = ACE_INVALID_HANDLE,
                                     int priority = 0,
                                     int signal_number = ACE_SIGRTMIN) = 0;

  /// Create the correct implementation class for ACE_Asynch_Write_Dgram::Result.
  virtual ACE_Asynch_Write_Dgram_Result_Impl *
    create_asynch_write_dgram_result (const ACE_Handler::Proxy_Ptr &handler_proxy,
                                      ACE_HANDLE handle,
                                      ACE_Message_Block *message_block,
                                      size_t bytes_to_write,
                                      int flags,
                                      const void* act,
                                      ACE_HANDLE event = ACE_INVALID_HANDLE,
                                      int priority = 0,
                                      int signal_number = ACE_SIGRTMIN) = 0;

  /// Create the correct implementation class for ACE_Asynch_Accept::Result.
  virtual ACE_Asynch_Accept_Result_Impl *
    create_asynch_accept_result (const ACE_Handler::Proxy_Ptr &handler_proxy,
                                 ACE_HANDLE listen_handle,
                                 ACE_HANDLE accept_handle,
                                 ACE_Message_Block &message_block,
                                 size_t bytes_to_read,
                                 const void* act,
                                 ACE_HANDLE event = ACE_INVALID_HANDLE,
                                 int priority = 0,
                                 int signal_number = ACE_SIGRTMIN) = 0;

  /// Create the correct implementation class for ACE_Asynch_Connect::Result.
  virtual ACE_Asynch_Connect_Result_Impl *
    create_asynch_connect_result (const ACE_Handler::Proxy_Ptr &handler_proxy,
                                  ACE_HANDLE connect_handle,
                                  const void* act,
                                  ACE_HANDLE event = ACE_INVALID_HANDLE,
                                  int priority = 0,
                                  int signal_number = ACE_SIGRTMIN) = 0;

  /// Create the correct implementation class for ACE_Asynch_Transmit_File::Result.
  virtual ACE_Asynch_Transmit_File_Result_Impl *
    create_asynch_transmit_file_result (const ACE_Handler::Proxy_Ptr &handler_proxy,
                                        ACE_HANDLE socket,
                                        ACE_HANDLE file,
                                        ACE_Asynch_Transmit_File::Header_And_Trailer *header_and_trailer,
                                        size_t bytes_to_write,
                                        u_long offset,
                                        u_long offset_high,
                                        size_t bytes_per_send,
                                        u_long flags,
                                        const void *act,
                                        ACE_HANDLE event = ACE_INVALID_HANDLE,
                                        int priority = 0,
                                        int signal_number = ACE_SIGRTMIN) = 0;

  /**
   * Create the correct implementation object for the Timer
   * result. POSIX_SIG_Proactor will create a Timer object with a
   * meaningful signal number, if you leave the signal number as 0.
   */
  virtual ACE_Asynch_Result_Impl *
    create_asynch_timer (const ACE_Handler::Proxy_Ptr &handler_proxy,
                         const void *act,
                         const ACE_Time_Value &tv,
                         ACE_HANDLE event = ACE_INVALID_HANDLE,
                         int priority = 0,
                         int signal_number = 0) = 0;

  /**
   * Post @a how_many completions to the completion port so that all
   * threads can wake up. This is used in conjunction with the
   * <run_event_loop>.
   */
  virtual int post_wakeup_completions (int how_many) = 0;
};

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_HAS_WIN32_OVERLAPPED_IO || ACE_HAS_AIO_CALLS */
#include /**/ "ace/post.h"
#endif /* ACE_PROACTOR_IMPL_H */

