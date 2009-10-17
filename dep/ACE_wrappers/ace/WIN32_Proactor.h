// -*- C++ -*-

//=============================================================================
/**
 *  @file    WIN32_Proactor.h
 *
 *  $Id: WIN32_Proactor.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Irfan Pyarali (irfan@cs.wustl.edu)
 *  @author Tim Harrison (harrison@cs.wustl.edu)
 *  @author Alexander Babu Arulanthu <alex@cs.wustl.edu>
 *  @author Roger Tragin <r.tragin@computer.org>
 *  @author Alexander Libman <alibman@ihug.com.au>
 */
//=============================================================================

#ifndef ACE_WIN32_PROACTOR_H
#define ACE_WIN32_PROACTOR_H
#include /**/ "ace/pre.h"

#include /**/ "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if defined (ACE_WIN32) && defined (ACE_HAS_WIN32_OVERLAPPED_IO)
// WIN32 implementation of the Proactor.

#include "ace/WIN32_Asynch_IO.h"
#include "ace/Event_Handler.h"

#include "ace/Proactor_Impl.h"
#include "ace/Asynch_Pseudo_Task.h"
#include "ace/Auto_Event.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

// Forward declarations.
class ACE_WIN32_Asynch_Result;
class ACE_WIN32_Proactor_Timer_Handler;

/**
 * @class ACE_WIN32_Proactor
 *
 * @brief A manager for asynchronous event demultiplexing on Win32.
 *
 * See the Proactor pattern description at
 * http://www.cs.wustl.edu/~schmidt/PDF/proactor.pdf for more
 * details.
 */
class ACE_Export ACE_WIN32_Proactor : public ACE_Proactor_Impl
{
  friend class ACE_WIN32_Asynch_Connect;

public:
  /// A do nothing constructor.
  ACE_WIN32_Proactor (size_t number_of_threads = 0,
                      bool used_with_reactor_event_loop = false);

  /// Virtual destruction.
  virtual ~ACE_WIN32_Proactor (void);

  /// Close the IO completion port.
  virtual int close (void);

  /// This method adds the @a handle to the I/O completion port. This
  /// function is a no-op function for Unix systems.
  virtual int register_handle (ACE_HANDLE handle,
                               const void *completion_key);

  /**
   * Dispatch a single set of events.  If @a wait_time elapses before
   * any events occur, return 0.  Return 1 on success i.e., when a
   * completion is dispatched, non-zero (-1) on errors and errno is
   * set accordingly.
   */
  virtual int handle_events (ACE_Time_Value &wait_time);

  /**
   * Block indefinitely until at least one event is dispatched.
   * Dispatch a single set of events. Return 1 on success i.e., when a
   * completion is dispatched, non-zero (-1) on errors and errno is
   * set accordingly.
   */
  virtual int handle_events (void);

  /**
   * Post a result to the completion port of the Proactor.  If errors
   * occur, the result will be deleted by this method.  If successful,
   * the result will be deleted by the Proactor when the result is
   * removed from the completion port.  Therefore, the result should
   * have been dynamically allocated and should be orphaned by the
   * user once this method is called.
   */
  virtual int post_completion (ACE_WIN32_Asynch_Result *result);

  /// Add wakeup dispatch threads (reinit).
  int wake_up_dispatch_threads (void);

  /// Close all dispatch threads.
  int close_dispatch_threads (int wait);

  /// Get number of thread used as a parameter to @c CreateIoCompletionPort.
  size_t number_of_threads (void) const;

  /// Set number of thread used as a parameter to @c CreateIoCompletionPort.
  void number_of_threads (size_t threads);

  /// Get the event handle.
  virtual ACE_HANDLE get_handle (void) const;

  virtual ACE_Asynch_Read_Stream_Impl *create_asynch_read_stream (void);
  virtual ACE_Asynch_Write_Stream_Impl *create_asynch_write_stream (void);
  virtual ACE_Asynch_Read_File_Impl *create_asynch_read_file (void);
  virtual ACE_Asynch_Write_File_Impl *create_asynch_write_file (void);
  virtual ACE_Asynch_Read_Dgram_Impl *create_asynch_read_dgram (void);
  virtual ACE_Asynch_Write_Dgram_Impl *create_asynch_write_dgram (void);
  virtual ACE_Asynch_Accept_Impl *create_asynch_accept (void);
  virtual ACE_Asynch_Connect_Impl *create_asynch_connect (void);
  virtual ACE_Asynch_Transmit_File_Impl *create_asynch_transmit_file (void);

  // Methods used to create Asynch_IO_Result objects. We create the right
  // objects here in these methods.

  virtual ACE_Asynch_Read_Stream_Result_Impl *create_asynch_read_stream_result (const ACE_Handler::Proxy_Ptr &handler_proxy,
                                                                                ACE_HANDLE handle,
                                                                                ACE_Message_Block &message_block,
                                                                                size_t bytes_to_read,
                                                                                const void* act,
                                                                                ACE_HANDLE event,
                                                                                int priority,
                                                                                int signal_number = 0);

  virtual ACE_Asynch_Write_Stream_Result_Impl *create_asynch_write_stream_result (const ACE_Handler::Proxy_Ptr &handler_proxy,
                                                                                  ACE_HANDLE handle,
                                                                                  ACE_Message_Block &message_block,
                                                                                  size_t bytes_to_write,
                                                                                  const void* act,
                                                                                  ACE_HANDLE event,
                                                                                  int priority,
                                                                                  int signal_number = 0);

  virtual ACE_Asynch_Read_File_Result_Impl *create_asynch_read_file_result (const ACE_Handler::Proxy_Ptr &handler_proxy,
                                                                            ACE_HANDLE handle,
                                                                            ACE_Message_Block &message_block,
                                                                            size_t bytes_to_read,
                                                                            const void* act,
                                                                            u_long offset,
                                                                            u_long offset_high,
                                                                            ACE_HANDLE event,
                                                                            int priority,
                                                                            int signal_number = 0);

  virtual ACE_Asynch_Write_File_Result_Impl *create_asynch_write_file_result (const ACE_Handler::Proxy_Ptr &handler_proxy,
                                                                              ACE_HANDLE handle,
                                                                              ACE_Message_Block &message_block,
                                                                              size_t bytes_to_write,
                                                                              const void* act,
                                                                              u_long offset,
                                                                              u_long offset_high,
                                                                              ACE_HANDLE event,
                                                                              int priority,
                                                                              int signal_number = 0);

  /// Create the correct implementation class for ACE_Asynch_Read_Dgram::Result.
  virtual ACE_Asynch_Read_Dgram_Result_Impl *create_asynch_read_dgram_result (const ACE_Handler::Proxy_Ptr &handler_proxy,
                                                                              ACE_HANDLE handle,
                                                                              ACE_Message_Block *message_block,
                                                                              size_t bytes_to_read,
                                                                              int flags,
                                                                              int protocol_family,
                                                                              const void* act,
                                                                              ACE_HANDLE event,
                                                                              int priority,
                                                                              int signal_number = 0);

  /// Create the correct implementation class for ACE_Asynch_Write_Dgram::Result.
  virtual ACE_Asynch_Write_Dgram_Result_Impl *create_asynch_write_dgram_result (const ACE_Handler::Proxy_Ptr &handler_proxy,
                                                                                ACE_HANDLE handle,
                                                                                ACE_Message_Block *message_block,
                                                                                size_t bytes_to_write,
                                                                                int flags,
                                                                                const void* act,
                                                                                ACE_HANDLE event,
                                                                                int priority,
                                                                                int signal_number = 0);

  virtual ACE_Asynch_Accept_Result_Impl *create_asynch_accept_result (const ACE_Handler::Proxy_Ptr &handler_proxy,
                                                                      ACE_HANDLE listen_handle,
                                                                      ACE_HANDLE accept_handle,
                                                                      ACE_Message_Block &message_block,
                                                                      size_t bytes_to_read,
                                                                      const void* act,
                                                                      ACE_HANDLE event,
                                                                      int priority,
                                                                      int signal_number = 0);

  virtual ACE_Asynch_Connect_Result_Impl *create_asynch_connect_result (const ACE_Handler::Proxy_Ptr &handler_proxy,
                                                                        ACE_HANDLE connect_handle,
                                                                        const void *act,
                                                                        ACE_HANDLE event,
                                                                        int priority,
                                                                        int signal_number = 0);


  virtual ACE_Asynch_Transmit_File_Result_Impl *create_asynch_transmit_file_result (const ACE_Handler::Proxy_Ptr &handler_proxy,
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

  /// Create a timer result object which can be used with the Timer
  /// mechanism of the Proactor.
  virtual ACE_Asynch_Result_Impl *create_asynch_timer (const ACE_Handler::Proxy_Ptr &handler_proxy,
                                                       const void *act,
                                                       const ACE_Time_Value &tv,
                                                       ACE_HANDLE event,
                                                       int priority,
                                                       int signal_number = 0);

protected:
  /// Task to process pseudo-asynchronous operations
  ACE_Asynch_Pseudo_Task & get_asynch_pseudo_task (void);

  /// Called when object is signaled by OS (either via UNIX signals or
  /// when a Win32 object becomes signaled).
  virtual int handle_signal (int signum, siginfo_t * = 0, ucontext_t * = 0);

  /// Called when object is removed from the ACE_Reactor.
  virtual int handle_close (ACE_HANDLE handle,
                            ACE_Reactor_Mask close_mask);

  /**
   * Dispatch a single set of events.  If @a milli_seconds elapses
   * before any events occur, return 0. Return 1 if a completion is
   * dispatched. Return -1 on errors.
   */
  virtual int handle_events (unsigned long milli_seconds);

  /// Protect against structured exceptions caused by user code when
  /// dispatching handles.
  void application_specific_code (ACE_WIN32_Asynch_Result *asynch_result,
                                  size_t bytes_transferred,
                                  const void *completion_key,
                                  u_long error);

  /**
   * Post @a how_many completions to the completion port so that all
   * threads can wake up. This is used in conjunction with the
   * run_event_loop().
   */
  virtual int post_wakeup_completions (int how_many);

  /// Handle for the completion port. Unix doesnt have completion
  /// ports.
  ACE_HANDLE completion_port_;

  /// This number is passed to the @c CreateIOCompletionPort system
  /// call.
  DWORD number_of_threads_;

  /// This event is used in conjunction with Reactor when we try to
 /// integrate the event loops of Reactor and the Proactor.
  ACE_Auto_Event event_;

  /// Flag that indicates whether we are used in conjunction with
  /// Reactor.
  bool const used_with_reactor_event_loop_;

  /// Handler to handle the wakeups. This works in conjunction with the
  /// ACE_Proactor::run_event_loop().
  ACE_Handler wakeup_handler_;

  /// Pseudo-task for asynch connect ( NT/2000)
  /// In future should removed in XP with ConnectEx support
  ACE_Asynch_Pseudo_Task pseudo_task_;
};

/**
 * @class ACE_WIN32_Asynch_Timer
 *
 * @brief This class is posted to the completion port when a timer
 * expires. When the complete method of this object is
 * called, the @a handler's handle_timeout method will be
 * called.
 */
class ACE_WIN32_Asynch_Timer : public ACE_WIN32_Asynch_Result
{
  /// The factory method for this class is with the POSIX_Proactor
  /// class.
  friend class ACE_WIN32_Proactor;

protected:
  /// Constructor.
  ACE_WIN32_Asynch_Timer (const ACE_Handler::Proxy_Ptr &handler_proxy,
                          const void *act,
                          const ACE_Time_Value &tv,
                          ACE_HANDLE event = ACE_INVALID_HANDLE,
                          int priority = 0,
                          int signal_number = 0);

  /// This method calls the @a handler's handle_timeout method.
  virtual void complete (size_t bytes_transferred,
                         int success,
                         const void *completion_key,
                         u_long error = 0);

  /// Time value requested by caller
  ACE_Time_Value time_;
};

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_WIN32 */
#include /**/ "ace/post.h"
#endif /* ACE_PROACTOR_H */

