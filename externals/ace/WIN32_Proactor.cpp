// $Id: WIN32_Proactor.cpp 80826 2008-03-04 14:51:23Z wotte $

// ACE_RCSID(ace, Proactor, "$Id: WIN32_Proactor.cpp 80826 2008-03-04 14:51:23Z wotte $")

#include "ace/WIN32_Proactor.h"

#if defined (ACE_WIN32) && defined (ACE_HAS_WIN32_OVERLAPPED_IO)
// WIN implemenatation of the Proactor.

#include "ace/Log_Msg.h"
#include "ace/Object_Manager.h"
#include "ace/OS_NS_errno.h"
#include "ace/OS_NS_unistd.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class ACE_WIN32_Wakeup_Completion
 *
 * This is result object is used by the <end_event_loop> of the
 * ACE_Proactor interface to wake up all the threads blocking
 * for completions.
 */
class ACE_WIN32_Wakeup_Completion : public ACE_WIN32_Asynch_Result
{

public:
  /// Constructor.
  ACE_WIN32_Wakeup_Completion (ACE_Handler::Proxy_Ptr &handler_proxy,
                               const void *act = 0,
                               ACE_HANDLE event = ACE_INVALID_HANDLE,
                               int priority = 0,
                               int signal_number = ACE_SIGRTMIN);

  /// Destructor.
  virtual ~ACE_WIN32_Wakeup_Completion (void);

  /// This method calls the <handler>'s <handle_wakeup> method.
  virtual void complete (size_t bytes_transferred = 0,
                         int success = 1,
                         const void *completion_key = 0,
                         u_long error = 0);
};

ACE_WIN32_Proactor::ACE_WIN32_Proactor (size_t number_of_threads,
                                        bool used_with_reactor_event_loop)
  : completion_port_ (0),
    // This *MUST* be 0, *NOT* ACE_INVALID_HANDLE !!!
    number_of_threads_ (static_cast<DWORD> (number_of_threads)),
    used_with_reactor_event_loop_ (used_with_reactor_event_loop)
{
  // Create the completion port.
  this->completion_port_ = ::CreateIoCompletionPort (INVALID_HANDLE_VALUE,
                                                     0,
                                                     0,
                                                     this->number_of_threads_);
  if (this->completion_port_ == 0)
    ACE_ERROR ((LM_ERROR,
                ACE_TEXT ("%p\n"),
                ACE_TEXT ("CreateIoCompletionPort")));

  this->get_asynch_pseudo_task ().start ();
}

ACE_WIN32_Proactor::~ACE_WIN32_Proactor (void)
{
  this->get_asynch_pseudo_task ().stop ();

  this->close ();
}

ACE_Asynch_Pseudo_Task &
ACE_WIN32_Proactor::get_asynch_pseudo_task ()
{
  return this->pseudo_task_;
}

int
ACE_WIN32_Proactor::close (void)
{
  // Close the completion port
  if (this->completion_port_ != 0)
    {
      // To avoid memory leaks we should delete all results from queue.

      for (;;)
        {
          ACE_OVERLAPPED *overlapped = 0;
          u_long bytes_transferred = 0;
          ULONG_PTR completion_key = 0;

          // Get the next asynchronous operation that completes
          BOOL res = ::GetQueuedCompletionStatus
            (this->completion_port_,
             &bytes_transferred,
             &completion_key,
             &overlapped,
             0);  // poll

          if (overlapped == 0 || res == FALSE)
            break;

          ACE_WIN32_Asynch_Result *asynch_result =
            (ACE_WIN32_Asynch_Result *) overlapped;

          delete asynch_result;
        }

      int result = ACE_OS::close (this->completion_port_);
      this->completion_port_ = 0;
      return result;
    }

  return 0;
}

int
ACE_WIN32_Proactor::register_handle (ACE_HANDLE handle,
                                     const void *completion_key)
{
  ULONG_PTR comp_key (reinterpret_cast<ULONG_PTR> (completion_key));

  // No locking is needed here as no state changes.
  ACE_HANDLE cp = ::CreateIoCompletionPort (handle,
                                            this->completion_port_,
                                            comp_key,
                                            this->number_of_threads_);
  if (cp == 0)
    {
      ACE_OS::set_errno_to_last_error ();
      // If errno == ERROR_INVALID_PARAMETER, then this handle was
      // already registered.
      if (errno != ERROR_INVALID_PARAMETER)
        {
          if (ACE::debug ())
            {
              ACE_DEBUG ((LM_ERROR,
                          ACE_TEXT ("%p\n"),
                          ACE_TEXT ("CreateIoCompletionPort")));
            }
          return -1;
        }
    }
  return 0;
}

ACE_Asynch_Read_Stream_Impl *
ACE_WIN32_Proactor::create_asynch_read_stream (void)
{
  ACE_Asynch_Read_Stream_Impl *implementation = 0;
  ACE_NEW_RETURN (implementation,
                  ACE_WIN32_Asynch_Read_Stream (this),
                  0);
  return implementation;
}

ACE_Asynch_Write_Stream_Impl *
ACE_WIN32_Proactor::create_asynch_write_stream (void)
{
  ACE_Asynch_Write_Stream_Impl *implementation = 0;
  ACE_NEW_RETURN (implementation,
                  ACE_WIN32_Asynch_Write_Stream (this),
                  0);
  return implementation;
}

ACE_Asynch_Read_Dgram_Impl *
ACE_WIN32_Proactor::create_asynch_read_dgram (void)
{
  ACE_Asynch_Read_Dgram_Impl *implementation = 0;
  ACE_NEW_RETURN (implementation,
                  ACE_WIN32_Asynch_Read_Dgram (this),
                  0);
  return implementation;
}

ACE_Asynch_Write_Dgram_Impl *
ACE_WIN32_Proactor::create_asynch_write_dgram (void)
{
  ACE_Asynch_Write_Dgram_Impl *implementation = 0;
  ACE_NEW_RETURN (implementation,
                  ACE_WIN32_Asynch_Write_Dgram (this),
                  0);
  return implementation;
}

ACE_Asynch_Read_File_Impl *
ACE_WIN32_Proactor::create_asynch_read_file (void)
{
  ACE_Asynch_Read_File_Impl *implementation = 0;
  ACE_NEW_RETURN (implementation,
                  ACE_WIN32_Asynch_Read_File (this),
                  0);
  return  implementation;
}

ACE_Asynch_Write_File_Impl *
ACE_WIN32_Proactor::create_asynch_write_file (void)
{
  ACE_Asynch_Write_File_Impl *implementation = 0;
  ACE_NEW_RETURN (implementation,
                  ACE_WIN32_Asynch_Write_File (this),
                  0);
  return  implementation;
}

ACE_Asynch_Accept_Impl *
ACE_WIN32_Proactor::create_asynch_accept (void)
{
  ACE_Asynch_Accept_Impl *implementation = 0;
  ACE_NEW_RETURN (implementation,
                  ACE_WIN32_Asynch_Accept (this),
                  0);
  return implementation;
}

ACE_Asynch_Connect_Impl *
ACE_WIN32_Proactor::create_asynch_connect (void)
{
  ACE_Asynch_Connect_Impl *implementation = 0;
  ACE_NEW_RETURN (implementation,
                  ACE_WIN32_Asynch_Connect (this),
                  0);
  return implementation;
}

ACE_Asynch_Transmit_File_Impl *
ACE_WIN32_Proactor::create_asynch_transmit_file (void)
{
  ACE_Asynch_Transmit_File_Impl *implementation = 0;
  ACE_NEW_RETURN (implementation,
                  ACE_WIN32_Asynch_Transmit_File (this),
                  0);
  return  implementation;
}

ACE_Asynch_Read_Stream_Result_Impl *
ACE_WIN32_Proactor::create_asynch_read_stream_result
  (const ACE_Handler::Proxy_Ptr &handler_proxy,
   ACE_HANDLE handle,
   ACE_Message_Block &message_block,
   size_t bytes_to_read,
   const void* act,
   ACE_HANDLE event,
   int priority,
   int signal_number)
{
  ACE_Asynch_Read_Stream_Result_Impl *implementation = 0;
  ACE_NEW_RETURN (implementation,
                  ACE_WIN32_Asynch_Read_Stream_Result (handler_proxy,
                                                       handle,
                                                       message_block,
                                                       bytes_to_read,
                                                       act,
                                                       event,
                                                       priority,
                                                       signal_number),
                  0);
  return implementation;
}

ACE_Asynch_Write_Stream_Result_Impl *
ACE_WIN32_Proactor::create_asynch_write_stream_result
  (const ACE_Handler::Proxy_Ptr &handler_proxy,
   ACE_HANDLE handle,
   ACE_Message_Block &message_block,
   size_t bytes_to_write,
   const void* act,
   ACE_HANDLE event,
   int priority,
   int signal_number)
{
  ACE_Asynch_Write_Stream_Result_Impl *implementation = 0;
  ACE_NEW_RETURN (implementation,
                  ACE_WIN32_Asynch_Write_Stream_Result (handler_proxy,
                                                        handle,
                                                        message_block,
                                                        bytes_to_write,
                                                        act,
                                                        event,
                                                        priority,
                                                        signal_number),
                  0);
  return implementation;
}

ACE_Asynch_Read_File_Result_Impl *
ACE_WIN32_Proactor::create_asynch_read_file_result
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
{
  ACE_Asynch_Read_File_Result_Impl *implementation = 0;
  ACE_NEW_RETURN (implementation,
                  ACE_WIN32_Asynch_Read_File_Result (handler_proxy,
                                                     handle,
                                                     message_block,
                                                     bytes_to_read,
                                                     act,
                                                     offset,
                                                     offset_high,
                                                     event,
                                                     priority,
                                                     signal_number),
                  0);
  return implementation;
}

ACE_Asynch_Write_File_Result_Impl *
ACE_WIN32_Proactor::create_asynch_write_file_result
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
{
  ACE_Asynch_Write_File_Result_Impl *implementation = 0;
  ACE_NEW_RETURN (implementation,
                  ACE_WIN32_Asynch_Write_File_Result (handler_proxy,
                                                      handle,
                                                      message_block,
                                                      bytes_to_write,
                                                      act,
                                                      offset,
                                                      offset_high,
                                                      event,
                                                      priority,
                                                      signal_number),
                  0);
  return implementation;
}

ACE_Asynch_Read_Dgram_Result_Impl *
ACE_WIN32_Proactor::create_asynch_read_dgram_result
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
{
  ACE_Asynch_Read_Dgram_Result_Impl *implementation = 0;
  ACE_NEW_RETURN (implementation,
                  ACE_WIN32_Asynch_Read_Dgram_Result (handler_proxy,
                                                      handle,
                                                      message_block,
                                                      bytes_to_read,
                                                      flags,
                                                      protocol_family,
                                                      act,
                                                      event,
                                                      priority,
                                                      signal_number),
                  0);
  return implementation;
}

ACE_Asynch_Write_Dgram_Result_Impl *
ACE_WIN32_Proactor::create_asynch_write_dgram_result
  (const ACE_Handler::Proxy_Ptr &handler_proxy,
   ACE_HANDLE handle,
   ACE_Message_Block *message_block,
   size_t bytes_to_read,
   int flags,
   const void* act,
   ACE_HANDLE event,
   int priority,
   int signal_number)
{
  ACE_Asynch_Write_Dgram_Result_Impl *implementation = 0;
  ACE_NEW_RETURN (implementation,
                  ACE_WIN32_Asynch_Write_Dgram_Result(handler_proxy,
                                                      handle,
                                                      message_block,
                                                      bytes_to_read,
                                                      flags,
                                                      act,
                                                      event,
                                                      priority,
                                                      signal_number),
                 0);
  return implementation;
}

ACE_Asynch_Accept_Result_Impl *
ACE_WIN32_Proactor::create_asynch_accept_result
  (const ACE_Handler::Proxy_Ptr &handler_proxy,
   ACE_HANDLE listen_handle,
   ACE_HANDLE accept_handle,
   ACE_Message_Block &message_block,
   size_t bytes_to_read,
   const void* act,
   ACE_HANDLE event,
   int priority,
   int signal_number)
{
  ACE_Asynch_Accept_Result_Impl *implementation = 0;
  ACE_NEW_RETURN (implementation,
                  ACE_WIN32_Asynch_Accept_Result (handler_proxy,
                                                  listen_handle,
                                                  accept_handle,
                                                  message_block,
                                                  bytes_to_read,
                                                  act,
                                                  event,
                                                  priority,
                                                  signal_number),
                  0);
  return implementation;
}

ACE_Asynch_Connect_Result_Impl *
ACE_WIN32_Proactor::create_asynch_connect_result
  (const ACE_Handler::Proxy_Ptr &handler_proxy,
   ACE_HANDLE connect_handle,
   const void *act,
   ACE_HANDLE event,
   int priority,
   int signal_number)
{
  ACE_Asynch_Connect_Result_Impl *implementation = 0;
  ACE_NEW_RETURN (implementation,
                  ACE_WIN32_Asynch_Connect_Result (handler_proxy,
                                                   connect_handle,
                                                   act,
                                                   event,
                                                   priority,
                                                   signal_number),
                  0);
  return implementation;
}

ACE_Asynch_Transmit_File_Result_Impl *
ACE_WIN32_Proactor::create_asynch_transmit_file_result
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
{
  ACE_Asynch_Transmit_File_Result_Impl *implementation = 0;
  ACE_NEW_RETURN (implementation,
                  ACE_WIN32_Asynch_Transmit_File_Result (handler_proxy,
                                                         socket,
                                                         file,
                                                         header_and_trailer,
                                                         bytes_to_write,
                                                         offset,
                                                         offset_high,
                                                         bytes_per_send,
                                                         flags,
                                                         act,
                                                         event,
                                                         priority,
                                                         signal_number),
                  0);
  return implementation;
}

ACE_Asynch_Result_Impl *
ACE_WIN32_Proactor::create_asynch_timer (const ACE_Handler::Proxy_Ptr &handler_proxy,
                                         const void *act,
                                         const ACE_Time_Value &tv,
                                         ACE_HANDLE event,
                                         int priority,
                                         int signal_number)
{
  ACE_Asynch_Result_Impl *implementation = 0;
  ACE_NEW_RETURN (implementation,
                  ACE_WIN32_Asynch_Timer (handler_proxy,
                                          act,
                                          tv,
                                          event,
                                          priority,
                                          signal_number),
                  0);
  return implementation;
}

int
ACE_WIN32_Proactor::handle_signal (int, siginfo_t *, ucontext_t *)
{
  // Perform a non-blocking "poll" for all the I/O events that have
  // completed in the I/O completion queue.

  int result = 0;

  for (ACE_Time_Value timeout (0, 0);
       ;
      )
    {
      result = this->handle_events (timeout);

      if (result != 1)
        break;
    }

  // If our handle_events failed, we'll report a failure to the
  // Reactor.
  return result == -1 ? -1 : 0;
}

int
ACE_WIN32_Proactor::handle_close (ACE_HANDLE handle,
                                  ACE_Reactor_Mask close_mask)
{
  ACE_UNUSED_ARG (close_mask);
  ACE_UNUSED_ARG (handle);

  return this->close ();
}

ACE_HANDLE
ACE_WIN32_Proactor::get_handle (void) const
{
  if (this->used_with_reactor_event_loop_)
    return this->event_.handle ();
  else
    return 0;
}

int
ACE_WIN32_Proactor::handle_events (ACE_Time_Value &wait_time)
{
  // Decrement <wait_time> with the amount of time spent in the method
  ACE_Countdown_Time countdown (&wait_time);
  return this->handle_events (wait_time.msec ());
}

int
ACE_WIN32_Proactor::handle_events (void)
{
  return this->handle_events (ACE_INFINITE);
}

int
ACE_WIN32_Proactor::handle_events (unsigned long milli_seconds)
{
  ACE_OVERLAPPED *overlapped = 0;
  u_long bytes_transferred = 0;
  ULONG_PTR completion_key = 0;

  // Get the next asynchronous operation that completes
  BOOL result = ::GetQueuedCompletionStatus (this->completion_port_,
                                             &bytes_transferred,
                                             &completion_key,
                                             &overlapped,
                                             milli_seconds);
  if (result == FALSE && overlapped == 0)
    {
      ACE_OS::set_errno_to_last_error ();

      switch (errno)
        {
        case WAIT_TIMEOUT:
          errno = ETIME;
          return 0;

        case ERROR_SUCCESS:
          // Calling GetQueuedCompletionStatus with timeout value 0
          // returns FALSE with extended errno "ERROR_SUCCESS" errno =
          // ETIME; ?? I don't know if this has to be done !!
          return 0;

        default:
          if (ACE::debug ())
            ACE_DEBUG ((LM_ERROR,
                        ACE_TEXT ("%p\n"),
                        ACE_TEXT ("GetQueuedCompletionStatus")));
          return -1;
        }
    }
  else if (overlapped != 0)
    {
      // Narrow the result.
      ACE_WIN32_Asynch_Result *asynch_result = (ACE_WIN32_Asynch_Result *) overlapped;

      // If errors happen, grab the error.
      if (result == FALSE)
        ACE_OS::set_errno_to_last_error ();
      else
        errno = 0;

      u_long result_err = asynch_result->error ();

      // if "result_err" is 0 than
      //     It is normal OS/WIN32 AIO completion.
      //     We have cleared asynch_result->error_
      //     during shared_read/shared_write.
      //     The real error code is already stored in "errno",
      //     so copy "errno" value to the "result_err"
      //     and pass this "result_err" code
      //     to the application_specific_code ()
      // else
      //    "result_err" non zero
      //     it means we have "post_completed" result
      //     so pass this "result_err" code
      //     to the application_specific_code ()

      if (result_err == 0)
        result_err = errno ;

      this->application_specific_code (asynch_result,
                                       static_cast<size_t> (bytes_transferred),
                                       (void *) completion_key,
                                       result_err);
    }
  return 1;
}

void
ACE_WIN32_Proactor::application_specific_code (ACE_WIN32_Asynch_Result *asynch_result,
                                               size_t bytes_transferred,
                                               const void *completion_key,
                                               u_long error)
{
  ACE_SEH_TRY
    {
      // Call completion hook
      asynch_result->complete (bytes_transferred,
                               error ? 0 : 1,
                               (void *) completion_key,
                               error);
    }
  ACE_SEH_FINALLY
    {
      // This is crucial to prevent memory leaks
      delete asynch_result;
    }
}

int
ACE_WIN32_Proactor::post_completion (ACE_WIN32_Asynch_Result *result)
{
  // Grab the event associated with the Proactor
  HANDLE handle = this->get_handle ();

  // pass
  //   bytes_transferred
  //   completion_key
  // to the ::PostQueuedCompletionStatus()
  //   error will be extracted later in handle_events()

  DWORD bytes_transferred = 0;
  const void * completion_key = 0 ;

  if (result != 0)
    {
      // This cast is ok since the original API calls restricted the transfer
      // counts to DWORD range.
      bytes_transferred = static_cast<DWORD> (result->bytes_transferred ());
      completion_key = result->completion_key();
    }

  ULONG_PTR comp_key (reinterpret_cast<ULONG_PTR> (completion_key));

  // Post a completion
  if (::PostQueuedCompletionStatus (this->completion_port_, // completion port
                                    bytes_transferred,      // xfer count
                                    comp_key,               // completion key
                                    result                  // overlapped
                                   ) == FALSE)
    {
      delete result;

      if (ACE::debug ())
        {
          ACE_DEBUG ((LM_ERROR,
                      ACE_TEXT ("%p\n"),
                      ACE_TEXT ("PostQueuedCompletionStatus failed")));
        }
      return -1;
    }

  // If Proactor event is valid, signal it
  if (handle != ACE_INVALID_HANDLE
      && handle != 0)
    ACE_OS::event_signal (&handle);

  return 0;
}

int
ACE_WIN32_Proactor::post_wakeup_completions (int how_many)
{
  ACE_WIN32_Wakeup_Completion *wakeup_completion = 0;

  for (ssize_t ci = 0; ci < how_many; ci++)
    {
      ACE_NEW_RETURN
        (wakeup_completion,
         ACE_WIN32_Wakeup_Completion (this->wakeup_handler_.proxy ()),
         -1);

      if (wakeup_completion->post_completion (this) == -1)
        return -1;
    }

  return 0;
}

int
ACE_WIN32_Proactor::wake_up_dispatch_threads (void)
{
  return 0;
}

int
ACE_WIN32_Proactor::close_dispatch_threads (int)
{
  return 0;
}

size_t
ACE_WIN32_Proactor::number_of_threads (void) const
{
  return static_cast<size_t> (this->number_of_threads_);
}

void
ACE_WIN32_Proactor::number_of_threads (size_t threads)
{
  this->number_of_threads_ = static_cast<DWORD> (threads);
}

ACE_WIN32_Asynch_Timer::ACE_WIN32_Asynch_Timer
  (const ACE_Handler::Proxy_Ptr &handler_proxy,
   const void *act,
   const ACE_Time_Value &tv,
   ACE_HANDLE event,
   int priority,
   int signal_number)
  : ACE_Asynch_Result_Impl (),
    ACE_WIN32_Asynch_Result (handler_proxy, act, event, 0, 0, priority,
                             signal_number),
    time_ (tv)
{
}

void
ACE_WIN32_Asynch_Timer::complete (size_t,
                                  int,
                                  const void *,
                                  u_long)
{
  ACE_Handler *handler = this->handler_proxy_.get ()->handler ();
  if (handler != 0)
    handler->handle_time_out (this->time_, this->act ());
}

ACE_WIN32_Wakeup_Completion::ACE_WIN32_Wakeup_Completion
  (ACE_Handler::Proxy_Ptr &handler_proxy,
   const void *act,
   ACE_HANDLE event,
   int priority,
   int signal_number)
  : ACE_Asynch_Result_Impl (),
    ACE_WIN32_Asynch_Result
     (handler_proxy, act, event, 0, 0, priority, signal_number)
{
}

ACE_WIN32_Wakeup_Completion::~ACE_WIN32_Wakeup_Completion (void)
{
}

void
ACE_WIN32_Wakeup_Completion::complete (size_t       /* bytes_transferred */,
                                       int          /* success */,
                                       const void * /* completion_key */,
                                       u_long       /*  error */)
{
  ACE_Handler *handler = this->handler_proxy_.get ()->handler ();
  if (handler != 0)
    handler->handle_wakeup ();
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_WIN32 */
