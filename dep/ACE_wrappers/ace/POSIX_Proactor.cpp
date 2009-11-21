// $Id: POSIX_Proactor.cpp 81697 2008-05-14 18:33:11Z johnnyw $

#include "ace/POSIX_Proactor.h"

#if defined (ACE_HAS_AIO_CALLS)

#if !defined (__ACE_INLINE__)
#include "ace/POSIX_Proactor.inl"
#endif /* __ACE_INLINE__ */

# if defined (ACE_HAS_SYS_SYSTEMINFO_H)
#   include /**/ <sys/systeminfo.h>
# endif /* ACE_HAS_SYS_SYSTEMINFO_H */

#include "ace/ACE.h"
#include "ace/Flag_Manip.h"
#include "ace/Task_T.h"
#include "ace/Log_Msg.h"
#include "ace/Object_Manager.h"
#include "ace/OS_NS_sys_socket.h"
#include "ace/OS_NS_signal.h"
#include "ace/OS_NS_unistd.h"

#if defined (sun)
#  include "ace/OS_NS_strings.h"
#endif /* sun */

// *********************************************************************

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class ACE_POSIX_Wakeup_Completion
 *
 * This result object is used by the <end_event_loop> of the
 * ACE_Proactor interface to wake up all the threads blocking
 * for completions.
 */
class ACE_POSIX_Wakeup_Completion : public ACE_POSIX_Asynch_Result
{
public:
  /// Constructor.
  ACE_POSIX_Wakeup_Completion (const ACE_Handler::Proxy_Ptr &handler_proxy,
                               const void *act = 0,
                               ACE_HANDLE event = ACE_INVALID_HANDLE,
                               int priority = 0,
                               int signal_number = ACE_SIGRTMIN);

  /// Destructor.
  virtual ~ACE_POSIX_Wakeup_Completion (void);

  /// This method calls the <handler>'s <handle_wakeup> method.
  virtual void complete (size_t bytes_transferred = 0,
                         int success = 1,
                         const void *completion_key = 0,
                         u_long error = 0);
};

// *********************************************************************
ACE_POSIX_Proactor::ACE_POSIX_Proactor (void)
  :  os_id_ (ACE_OS_UNDEFINED)
{
#if defined(sun)

  os_id_ = ACE_OS_SUN; // set family

  char Buf [32];

  ::memset(Buf,0,sizeof(Buf));

  ACE_OS::sysinfo (SI_RELEASE , Buf, sizeof(Buf)-1);

  if (ACE_OS::strcasecmp (Buf , "5.6") == 0)
    os_id_ = ACE_OS_SUN_56;
  else if (ACE_OS::strcasecmp (Buf , "5.7") == 0)
    os_id_ = ACE_OS_SUN_57;
  else if (ACE_OS::strcasecmp (Buf , "5.8") == 0)
    os_id_ = ACE_OS_SUN_58;

#elif defined(HPUX)

  os_id_ = ACE_OS_HPUX;   // set family

#elif defined(__sgi)

  os_id_ = ACE_OS_IRIX;   // set family

#elif defined(__OpenBSD)

  os_id_ = ACE_OS_OPENBSD; // set family

  // do the same

//#else defined (LINUX, __FreeBSD__ ...)
//setup here os_id_
#endif
}

ACE_POSIX_Proactor::~ACE_POSIX_Proactor (void)
{
  this->close ();
}

int
ACE_POSIX_Proactor::close (void)
{
  return 0;
}

int
ACE_POSIX_Proactor::register_handle (ACE_HANDLE handle,
                                     const void *completion_key)
{
  ACE_UNUSED_ARG (handle);
  ACE_UNUSED_ARG (completion_key);
  return 0;
}

int
ACE_POSIX_Proactor::wake_up_dispatch_threads (void)
{
  return 0;
}

int
ACE_POSIX_Proactor::close_dispatch_threads (int)
{
  return 0;
}

size_t
ACE_POSIX_Proactor::number_of_threads (void) const
{
  // @@ Implement it.
  ACE_NOTSUP_RETURN (0);
}

void
ACE_POSIX_Proactor::number_of_threads (size_t threads)
{
  // @@ Implement it.
  ACE_UNUSED_ARG (threads);
}

ACE_HANDLE
ACE_POSIX_Proactor::get_handle (void) const
{
  return ACE_INVALID_HANDLE;
}

ACE_Asynch_Read_Stream_Impl *
ACE_POSIX_Proactor::create_asynch_read_stream (void)
{
  ACE_Asynch_Read_Stream_Impl *implementation = 0;
  ACE_NEW_RETURN (implementation,
                  ACE_POSIX_Asynch_Read_Stream (this),
                  0);
  return implementation;
}

ACE_Asynch_Read_Stream_Result_Impl *
ACE_POSIX_Proactor::create_asynch_read_stream_result
  (const ACE_Handler::Proxy_Ptr &handler_proxy,
   ACE_HANDLE handle,
   ACE_Message_Block &message_block,
   size_t bytes_to_read,
   const void* act,
   ACE_HANDLE event,
   int priority,
   int signal_number)
{
  ACE_Asynch_Read_Stream_Result_Impl *implementation;
  ACE_NEW_RETURN (implementation,
                  ACE_POSIX_Asynch_Read_Stream_Result (handler_proxy,
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

ACE_Asynch_Write_Stream_Impl *
ACE_POSIX_Proactor::create_asynch_write_stream (void)
{
  ACE_Asynch_Write_Stream_Impl *implementation = 0;
  ACE_NEW_RETURN (implementation,
                  ACE_POSIX_Asynch_Write_Stream (this),
                  0);
  return implementation;
}

ACE_Asynch_Write_Stream_Result_Impl *
ACE_POSIX_Proactor::create_asynch_write_stream_result
  (const ACE_Handler::Proxy_Ptr &handler_proxy,
   ACE_HANDLE handle,
   ACE_Message_Block &message_block,
   size_t bytes_to_write,
   const void* act,
   ACE_HANDLE event,
   int priority,
   int signal_number)
{
  ACE_Asynch_Write_Stream_Result_Impl *implementation;
  ACE_NEW_RETURN (implementation,
                  ACE_POSIX_Asynch_Write_Stream_Result (handler_proxy,
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

ACE_Asynch_Read_File_Impl *
ACE_POSIX_Proactor::create_asynch_read_file (void)
{
  ACE_Asynch_Read_File_Impl *implementation = 0;
  ACE_NEW_RETURN (implementation,
                  ACE_POSIX_Asynch_Read_File (this),
                  0);
  return  implementation;
}

ACE_Asynch_Read_File_Result_Impl *
ACE_POSIX_Proactor::create_asynch_read_file_result
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
  ACE_Asynch_Read_File_Result_Impl *implementation;
  ACE_NEW_RETURN (implementation,
                  ACE_POSIX_Asynch_Read_File_Result (handler_proxy,
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

ACE_Asynch_Write_File_Impl *
ACE_POSIX_Proactor::create_asynch_write_file (void)
{
  ACE_Asynch_Write_File_Impl *implementation = 0;
  ACE_NEW_RETURN (implementation,
                  ACE_POSIX_Asynch_Write_File (this),
                  0);
  return  implementation;
}

ACE_Asynch_Write_File_Result_Impl *
ACE_POSIX_Proactor::create_asynch_write_file_result
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
  ACE_Asynch_Write_File_Result_Impl *implementation;
  ACE_NEW_RETURN (implementation,
                  ACE_POSIX_Asynch_Write_File_Result (handler_proxy,
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

ACE_Asynch_Read_Dgram_Impl *
ACE_POSIX_Proactor::create_asynch_read_dgram (void)
{
    ACE_Asynch_Read_Dgram_Impl *implementation = 0;
    ACE_NEW_RETURN (implementation,
                    ACE_POSIX_Asynch_Read_Dgram (this),
                    0);
    return implementation;
}

ACE_Asynch_Read_Dgram_Result_Impl *
ACE_POSIX_Proactor::create_asynch_read_dgram_result
  (const ACE_Handler::Proxy_Ptr &handler_proxy,
   ACE_HANDLE handle,
   ACE_Message_Block *message_block,
   size_t bytes_to_read,
   int flags,
   int protocol_family,
   const void* act,
   ACE_HANDLE event ,
   int priority ,
   int signal_number)
{
  ACE_Asynch_Read_Dgram_Result_Impl *implementation=0;
  ACE_NEW_RETURN (implementation,
                  ACE_POSIX_Asynch_Read_Dgram_Result(handler_proxy,
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

ACE_Asynch_Write_Dgram_Impl *
ACE_POSIX_Proactor::create_asynch_write_dgram (void)
{
        ACE_Asynch_Write_Dgram_Impl *implementation = 0;
        ACE_NEW_RETURN (implementation,
                        ACE_POSIX_Asynch_Write_Dgram (this),
                        0);

    return implementation;
}

ACE_Asynch_Write_Dgram_Result_Impl *
ACE_POSIX_Proactor::create_asynch_write_dgram_result
  (const ACE_Handler::Proxy_Ptr &handler_proxy,
   ACE_HANDLE handle,
   ACE_Message_Block *message_block,
   size_t bytes_to_write,
   int flags,
   const void* act,
   ACE_HANDLE event,
   int priority ,
   int signal_number)
{
  ACE_Asynch_Write_Dgram_Result_Impl *implementation=0;
  ACE_NEW_RETURN (implementation,
                  ACE_POSIX_Asynch_Write_Dgram_Result(handler_proxy,
                                                      handle,
                                                      message_block,
                                                      bytes_to_write,
                                                      flags,
                                                      act,
                                                      event,
                                                      priority,
                                                      signal_number),
                  0);

  return implementation;
}

ACE_Asynch_Accept_Impl *
ACE_POSIX_Proactor::create_asynch_accept (void)
{
  ACE_Asynch_Accept_Impl *implementation = 0;
  ACE_NEW_RETURN (implementation,
                  ACE_POSIX_Asynch_Accept (this),
                  0);

  return implementation;
}

ACE_Asynch_Accept_Result_Impl *
ACE_POSIX_Proactor::create_asynch_accept_result
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
  ACE_Asynch_Accept_Result_Impl *implementation;
  ACE_NEW_RETURN (implementation,
                  ACE_POSIX_Asynch_Accept_Result (handler_proxy,
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

ACE_Asynch_Connect_Impl *
ACE_POSIX_Proactor::create_asynch_connect (void)
{
  ACE_Asynch_Connect_Impl *implementation = 0;
  ACE_NEW_RETURN (implementation,
                  ACE_POSIX_Asynch_Connect (this),
                  0);

  return implementation;
}

ACE_Asynch_Connect_Result_Impl *
ACE_POSIX_Proactor::create_asynch_connect_result
  (const ACE_Handler::Proxy_Ptr &handler_proxy,
   ACE_HANDLE connect_handle,
   const void* act,
   ACE_HANDLE event,
   int priority,
   int signal_number)
{
  ACE_Asynch_Connect_Result_Impl *implementation;
  ACE_NEW_RETURN (implementation,
                  ACE_POSIX_Asynch_Connect_Result (handler_proxy,
                                                   connect_handle,
                                                   act,
                                                   event,
                                                   priority,
                                                   signal_number),
                  0);
  return implementation;
}

ACE_Asynch_Transmit_File_Impl *
ACE_POSIX_Proactor::create_asynch_transmit_file (void)
{
  ACE_Asynch_Transmit_File_Impl *implementation = 0;
  ACE_NEW_RETURN (implementation,
                  ACE_POSIX_Asynch_Transmit_File (this),
                  0);
  return implementation;
}

ACE_Asynch_Transmit_File_Result_Impl *
ACE_POSIX_Proactor::create_asynch_transmit_file_result
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
  ACE_Asynch_Transmit_File_Result_Impl *implementation;
  ACE_NEW_RETURN (implementation,
                  ACE_POSIX_Asynch_Transmit_File_Result (handler_proxy,
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
ACE_POSIX_Proactor::create_asynch_timer
  (const ACE_Handler::Proxy_Ptr &handler_proxy,
   const void *act,
   const ACE_Time_Value &tv,
   ACE_HANDLE event,
   int priority,
   int signal_number)
{
  ACE_POSIX_Asynch_Timer *implementation;
  ACE_NEW_RETURN (implementation,
                  ACE_POSIX_Asynch_Timer (handler_proxy,
                                          act,
                                          tv,
                                          event,
                                          priority,
                                          signal_number),
                  0);
  return implementation;
}

#if 0
int
ACE_POSIX_Proactor::handle_signal (int, siginfo_t *, ucontext_t *)
{
  // Perform a non-blocking "poll" for all the I/O events that have
  // completed in the I/O completion queue.

  ACE_Time_Value timeout (0, 0);
  int result = 0;

  for (;;)
    {
      result = this->handle_events (timeout);
      if (result != 0 || errno == ETIME)
        break;
    }

  // If our handle_events failed, we'll report a failure to the
  // Reactor.
  return result == -1 ? -1 : 0;
}

int
ACE_POSIX_Proactor::handle_close (ACE_HANDLE handle,
                                  ACE_Reactor_Mask close_mask)
{
  ACE_UNUSED_ARG (close_mask);
  ACE_UNUSED_ARG (handle);

  return this->close ();
}
#endif /* 0 */

void
ACE_POSIX_Proactor::application_specific_code (ACE_POSIX_Asynch_Result *asynch_result,
                                               size_t bytes_transferred,
                                               const void */* completion_key*/,
                                               u_long error)
{
  ACE_SEH_TRY
    {
      // Call completion hook
      asynch_result->complete (bytes_transferred,
                               error ? 0 : 1,
                               0, // No completion key.
                               error);
    }
  ACE_SEH_FINALLY
    {
      // This is crucial to prevent memory leaks
      delete asynch_result;
    }
}

int
ACE_POSIX_Proactor::post_wakeup_completions (int how_many)
{
  ACE_POSIX_Wakeup_Completion *wakeup_completion = 0;

  for (int ci = 0; ci < how_many; ci++)
    {
      ACE_NEW_RETURN
        (wakeup_completion,
         ACE_POSIX_Wakeup_Completion (this->wakeup_handler_.proxy ()),
         -1);
      if (this->post_completion (wakeup_completion) == -1)
        return -1;
    }

  return 0;
}

ACE_POSIX_Proactor::Proactor_Type
ACE_POSIX_Proactor::get_impl_type (void)
{
  return PROACTOR_POSIX;
}

/**
 * @class ACE_AIOCB_Notify_Pipe_Manager
 *
 * @brief This class manages the notify pipe of the AIOCB Proactor.
 *
 * This class acts as the Handler for the
 * <Asynch_Read> operations issued on the notify pipe. This
 * class is very useful in implementing <Asynch_Accept> operation
 * class for the <AIOCB_Proactor>. This is also useful for
 * implementing <post_completion> for <AIOCB_Proactor>.

 * <AIOCB_Proactor> class issues a <Asynch_Read> on
 * the pipe, using this class as the
 * Handler. <POSIX_Asynch_Result *>'s are sent through the
 * notify pipe. When <POSIX_Asynch_Result *>'s show up on the
 * notify pipe, the <POSIX_AIOCB_Proactor> dispatches the
 * completion of the <Asynch_Read_Stream> and calls the
 * <handle_read_stream> of this class. This class calls
 * <complete> on the <POSIX_Asynch_Result *> and thus calls the
 * application handler.
 * Handling the MessageBlock:
 * We give this message block to read the result pointer through
 * the notify pipe. We expect that to read 4 bytes from the
 * notify pipe, for each <accept> call. Before giving this
 * message block to another <accept>, we update <wr_ptr> and put
 * it in its initial position.
 */
class ACE_AIOCB_Notify_Pipe_Manager : public ACE_Handler
{
public:
  /// Constructor. You need the posix proactor because you need to call
  /// <application_specific_code>
  ACE_AIOCB_Notify_Pipe_Manager (ACE_POSIX_AIOCB_Proactor *posix_aiocb_proactor);

  /// Destructor.
  virtual ~ACE_AIOCB_Notify_Pipe_Manager (void);

  /// Send the result pointer through the notification pipe.
  int notify ();

  /// This is the call back method when <Asynch_Read> from the pipe is
  /// complete.
  virtual void handle_read_stream (const ACE_Asynch_Read_Stream::Result &result);

private:
  /// The implementation proactor class.
  ACE_POSIX_AIOCB_Proactor  *posix_aiocb_proactor_;

  /// Message block to get ACE_POSIX_Asynch_Result pointer from the pipe.
  ACE_Message_Block message_block_;

  /// Pipe for the communication between Proactor and the
  /// Asynch_Accept/Asynch_Connect and other post_completions
  ACE_Pipe pipe_;

  /// To do asynch_read on the pipe.
  ACE_POSIX_Asynch_Read_Stream read_stream_;

  /// Default constructor. Shouldnt be called.
  ACE_AIOCB_Notify_Pipe_Manager (void);
};

ACE_AIOCB_Notify_Pipe_Manager::ACE_AIOCB_Notify_Pipe_Manager (ACE_POSIX_AIOCB_Proactor *posix_aiocb_proactor)
  : posix_aiocb_proactor_ (posix_aiocb_proactor),
    message_block_ (sizeof (2)),
    read_stream_ (posix_aiocb_proactor)
{
  // Open the pipe.
  this->pipe_.open ();

  // Set write side in NONBLOCK mode
  ACE::set_flags (this->pipe_.write_handle (), ACE_NONBLOCK);

  // Set read side in BLOCK mode
  ACE::clr_flags (this->pipe_.read_handle (), ACE_NONBLOCK);

  // Let AIOCB_Proactor know about our handle
  posix_aiocb_proactor_->set_notify_handle (this->pipe_.read_handle ());

  // Open the read stream.
  if (this->read_stream_.open (this->proxy (),
                               this->pipe_.read_handle (),
                               0, // Completion Key
                               0) // Proactor
      == -1)
    ACE_ERROR ((LM_ERROR,
                "%N:%l:%p\n",
                "ACE_AIOCB_Notify_Pipe_Manager::ACE_AIOCB_Notify_Pipe_Manager:"
                "Open on Read Stream failed"));

  // Issue an asynch_read on the read_stream of the notify pipe.
  if (this->read_stream_.read (this->message_block_,
                               1, // enough to read 1 byte
                               0, // ACT
                               0) // Priority
      == -1)
    ACE_ERROR ((LM_ERROR,
                "%N:%l:%p\n",
                "ACE_AIOCB_Notify_Pipe_Manager::ACE_AIOCB_Notify_Pipe_Manager:"
                "Read from pipe failed"));
}

ACE_AIOCB_Notify_Pipe_Manager::~ACE_AIOCB_Notify_Pipe_Manager (void)
{
  // 1. try to cancel pending aio
  this->read_stream_.cancel ();

  // 2. close both handles
  // Destuctor of ACE_Pipe does not close handles.
  // We can not use ACE_Pipe::close() as it
  // closes  read_handle and than write_handle.
  // In some systems close() may wait for
  // completion for all asynch. pending requests.
  // So we should close write_handle firstly
  // to force read completion ( if 1. does not help )
  // and then read_handle and not vice versa

  ACE_HANDLE h = this->pipe_.write_handle ();
  if (h != ACE_INVALID_HANDLE)
     ACE_OS::closesocket (h);

  h = this->pipe_.read_handle ();
  if ( h != ACE_INVALID_HANDLE)
     ACE_OS::closesocket (h);

}

int
ACE_AIOCB_Notify_Pipe_Manager::notify ()
{
  // Send the result pointer through the pipe.
  char char_send = 0;
  ssize_t ret_val = ACE::send (this->pipe_.write_handle (),
                               &char_send,
                               sizeof (char_send));

  if (ret_val < 0)
    {
      if (errno != EWOULDBLOCK)
#if 0
        ACE_ERROR ((LM_ERROR,
                    ACE_TEXT ("(%P %t):%p\n"),
                    ACE_TEXT ("ACE_AIOCB_Notify_Pipe_Manager::notify")
                    ACE_TEXT ("Error:Writing on to notify pipe failed")));
#endif /* 0 */
      return -1;
    }

  return 0;
}

void
ACE_AIOCB_Notify_Pipe_Manager::handle_read_stream
  (const ACE_Asynch_Read_Stream::Result & /*result*/)
{
  // 1. Start new read to avoid pipe overflow

  // Set the message block properly. Put the <wr_ptr> back in the
  // initial position.
  if (this->message_block_.length () > 0)
      this->message_block_.wr_ptr (this->message_block_.rd_ptr ());

  // One accept has completed. Issue a read to handle any
  // <post_completion>s in the future.
  if (-1 == this->read_stream_.read (this->message_block_,
                                     1,   // enough to read 1 byte
                                     0,   // ACT
                                     0))  // Priority
    ACE_ERROR ((LM_ERROR,
                ACE_TEXT ("%N:%l:(%P | %t):%p\n"),
                ACE_TEXT ("ACE_AIOCB_Notify_Pipe_Manager::handle_read_stream:")
                ACE_TEXT ("Read from pipe failed")));

  // 2. Do the upcalls
  // this->posix_aiocb_proactor_->process_result_queue ();
}

// Public constructor for common use.
ACE_POSIX_AIOCB_Proactor::ACE_POSIX_AIOCB_Proactor (size_t max_aio_operations)
  : aiocb_notify_pipe_manager_ (0),
    aiocb_list_ (0),
    result_list_ (0),
    aiocb_list_max_size_ (max_aio_operations),
    aiocb_list_cur_size_ (0),
    notify_pipe_read_handle_ (ACE_INVALID_HANDLE),
    num_deferred_aiocb_ (0),
    num_started_aio_ (0)
{
  // Check for correct value for max_aio_operations
  check_max_aio_num ();

  this->create_result_aiocb_list ();

  this->create_notify_manager ();

  // start pseudo-asynchronous accept task
  // one per all future acceptors
  this->get_asynch_pseudo_task().start ();

}

// Special protected constructor for ACE_SUN_Proactor
ACE_POSIX_AIOCB_Proactor::ACE_POSIX_AIOCB_Proactor (size_t max_aio_operations,
                                                    ACE_POSIX_Proactor::Proactor_Type)
  : aiocb_notify_pipe_manager_ (0),
    aiocb_list_ (0),
    result_list_ (0),
    aiocb_list_max_size_ (max_aio_operations),
    aiocb_list_cur_size_ (0),
    notify_pipe_read_handle_ (ACE_INVALID_HANDLE),
    num_deferred_aiocb_ (0),
    num_started_aio_ (0)
{
  //check for correct value for max_aio_operations
  this->check_max_aio_num ();

  this->create_result_aiocb_list ();

  // @@ We should create Notify_Pipe_Manager in the derived class to
  // provide correct calls for virtual functions !!!
}

// Destructor.
ACE_POSIX_AIOCB_Proactor::~ACE_POSIX_AIOCB_Proactor (void)
{
  this->close();
}

ACE_POSIX_Proactor::Proactor_Type
ACE_POSIX_AIOCB_Proactor::get_impl_type (void)
{
  return PROACTOR_AIOCB;
}

int
ACE_POSIX_AIOCB_Proactor::close (void)
{
  // stop asynch accept task
  this->get_asynch_pseudo_task().stop ();

  this->delete_notify_manager ();

  this->clear_result_queue ();

  return this->delete_result_aiocb_list ();
}

void ACE_POSIX_AIOCB_Proactor::set_notify_handle (ACE_HANDLE h)
{
  notify_pipe_read_handle_ = h;
}

int ACE_POSIX_AIOCB_Proactor::create_result_aiocb_list (void)
{
  if (aiocb_list_ != 0)
    return 0;

  ACE_NEW_RETURN (aiocb_list_, aiocb *[aiocb_list_max_size_], -1);

  ACE_NEW_RETURN (result_list_,
                  ACE_POSIX_Asynch_Result *[aiocb_list_max_size_],
                  -1);

  // Initialize the array.
  for (size_t ai = 0; ai < this->aiocb_list_max_size_; ai++)
    {
      aiocb_list_[ai] = 0;
      result_list_[ai] = 0;
    }

  return 0;
}

int ACE_POSIX_AIOCB_Proactor::delete_result_aiocb_list (void)
{
  if (aiocb_list_ == 0)  // already deleted
    return 0;

  size_t ai;

  // Try to cancel all uncompleted operations; POSIX systems may have
  // hidden system threads that still can work with our aiocbs!
  for (ai = 0; ai < aiocb_list_max_size_; ai++)
    if (this->aiocb_list_[ai] != 0)  // active operation
      this->cancel_aiocb (result_list_[ai]);

  int num_pending = 0;

  for (ai = 0; ai < aiocb_list_max_size_; ai++)
    {
      if (this->aiocb_list_[ai] == 0 ) //  not active operation
        continue;

      // Get the error and return status of the aio_ operation.
      int error_status  = 0;
      size_t transfer_count = 0;
      int flg_completed = this->get_result_status (result_list_[ai],
                                                   error_status,
                                                   transfer_count);

      //don't delete uncompleted AIOCB's
      if (flg_completed == 0)  // not completed !!!
        {
          num_pending++;
#if 0
          char * errtxt = ACE_OS::strerror (error_status);
          if (errtxt == 0)
              errtxt ="?????????";

          char * op = (aiocb_list_[ai]->aio_lio_opcode == LIO_WRITE )?
            "WRITE":"READ" ;

          ACE_ERROR ((LM_ERROR,
                      ACE_TEXT("slot=%d op=%s status=%d xfercnt=%d %s\n"),
                      ai,
                      op,
                      error_status,
                      transfer_count,
                      errtxt));
#endif /* 0 */
        }
      else // completed , OK
        {
          delete this->result_list_[ai];
          this->result_list_[ai] = 0;
          this->aiocb_list_[ai] = 0;
        }
    }

  // If it is not possible cancel some operation (num_pending > 0 ),
  // we can do only one thing -report about this
  // and complain about POSIX implementation.
  // We know that we have memory leaks, but it is better than
  // segmentation fault!
  ACE_DEBUG
    ((LM_DEBUG,
      ACE_TEXT("ACE_POSIX_AIOCB_Proactor::delete_result_aiocb_list\n")
      ACE_TEXT(" number pending AIO=%d\n"),
      num_pending));

  delete [] this->aiocb_list_;
  this->aiocb_list_ = 0;

  delete [] this->result_list_;
  this->result_list_ = 0;

  return (num_pending == 0 ? 0 : -1);
  // ?? or just always return 0;
}

void ACE_POSIX_AIOCB_Proactor::check_max_aio_num ()
{
  long max_os_aio_num = ACE_OS::sysconf (_SC_AIO_MAX);

  // Define max limit AIO's for concrete OS
  // -1 means that there is no limit, but it is not true
  // (example, SunOS 5.6)

  if (max_os_aio_num > 0 &&
      aiocb_list_max_size_ > (unsigned long) max_os_aio_num)
     aiocb_list_max_size_ = max_os_aio_num;

#if defined (HPUX) || defined (__FreeBSD__)
  // Although HPUX 11.00 allows to start 2048 AIO's for all process in
  // system it has a limit 256 max elements for aio_suspend () It is a
  // pity, but ...

  long max_os_listio_num = ACE_OS::sysconf (_SC_AIO_LISTIO_MAX);
  if (max_os_listio_num > 0
      && aiocb_list_max_size_ > (unsigned long) max_os_listio_num)
    aiocb_list_max_size_ = max_os_listio_num;
#endif /* HPUX || __FreeBSD__ */

  // check for user-defined value
  // ACE_AIO_MAX_SIZE if defined in POSIX_Proactor.h

  if (aiocb_list_max_size_ <= 0
     || aiocb_list_max_size_ > ACE_AIO_MAX_SIZE)
     aiocb_list_max_size_ = ACE_AIO_MAX_SIZE;

  // check for max number files to open

  int max_num_files = ACE::max_handles ();

  if (max_num_files > 0
      && aiocb_list_max_size_ > (unsigned long) max_num_files)
    {
      ACE::set_handle_limit (aiocb_list_max_size_);

      max_num_files = ACE::max_handles ();
    }

  if (max_num_files > 0
      && aiocb_list_max_size_ > (unsigned long) max_num_files)
    aiocb_list_max_size_ = (unsigned long) max_num_files;

  ACE_DEBUG ((LM_DEBUG,
             "(%P | %t) ACE_POSIX_AIOCB_Proactor::Max Number of AIOs=%d\n",
              aiocb_list_max_size_));

#if defined(__sgi)

   ACE_DEBUG((LM_DEBUG,
              ACE_TEXT( "SGI IRIX specific: aio_init!\n")));

//typedef struct aioinit {
//    int aio_threads;  /* The number of aio threads to start (5) */
//    int aio_locks;    /* Initial number of preallocated locks (3) */
//    int aio_num;      /* estimated total simultanious aiobc structs (1000) */
//    int aio_usedba;   /* Try to use DBA for raw I/O in lio_listio (0) */
//    int aio_debug;    /* turn on debugging (0) */
//    int aio_numusers; /* max number of user sprocs making aio_* calls (5) */
//    int aio_reserved[3];
//} aioinit_t;

    aioinit_t  aioinit;

    aioinit.aio_threads = 10; /* The number of aio threads to start (5) */
    aioinit.aio_locks = 20;   /* Initial number of preallocated locks (3) */
                       /* estimated total simultaneous aiobc structs (1000) */
    aioinit.aio_num = aiocb_list_max_size_;
    aioinit.aio_usedba = 0;   /* Try to use DBA for raw IO in lio_listio (0) */
    aioinit.aio_debug = 0;    /* turn on debugging (0) */
    aioinit.aio_numusers = 100; /* max number of user sprocs making aio_* calls (5) */
    aioinit.aio_reserved[0] = 0;
    aioinit.aio_reserved[1] = 0;
    aioinit.aio_reserved[2] = 0;

    aio_sgi_init (&aioinit);

#endif

    return;
}

void
ACE_POSIX_AIOCB_Proactor::create_notify_manager (void)
{
  // Remember! this issues a Asynch_Read
  // on the notify pipe for doing the Asynch_Accept/Connect.

  if (aiocb_notify_pipe_manager_ == 0)
    ACE_NEW (aiocb_notify_pipe_manager_,
             ACE_AIOCB_Notify_Pipe_Manager (this));
}

void
ACE_POSIX_AIOCB_Proactor::delete_notify_manager (void)
{
  // We are responsible for delete as all pointers set to 0 after
  // delete, it is save to delete twice

  delete aiocb_notify_pipe_manager_;
  aiocb_notify_pipe_manager_ = 0;
}

int
ACE_POSIX_AIOCB_Proactor::handle_events (ACE_Time_Value &wait_time)
{
  // Decrement <wait_time> with the amount of time spent in the method
  ACE_Countdown_Time countdown (&wait_time);
  return this->handle_events_i (wait_time.msec ());
}

int
ACE_POSIX_AIOCB_Proactor::handle_events (void)
{
  return this->handle_events_i (ACE_INFINITE);
}

int
ACE_POSIX_AIOCB_Proactor::notify_completion(int  sig_num)
{
  ACE_UNUSED_ARG (sig_num);

  return this->aiocb_notify_pipe_manager_->notify ();
}

int
ACE_POSIX_AIOCB_Proactor::post_completion (ACE_POSIX_Asynch_Result *result)
{
  ACE_MT (ACE_GUARD_RETURN (ACE_SYNCH_MUTEX, ace_mon, this->mutex_, -1));

  int ret_val = this->putq_result (result);

  return ret_val;
}

int
ACE_POSIX_AIOCB_Proactor::putq_result (ACE_POSIX_Asynch_Result *result)
{
  // this protected method should be called with locked mutex_
  // we can't use GUARD as Proactor uses non-recursive mutex

  if (!result)
    return -1;

  int sig_num = result->signal_number ();
  int ret_val = this->result_queue_.enqueue_tail (result);

  if (ret_val == -1)
    ACE_ERROR_RETURN ((LM_ERROR,
                       "%N:%l:ACE_POSIX_AIOCB_Proactor::putq_result failed\n"),
                      -1);

  this->notify_completion (sig_num);

  return 0;
}

ACE_POSIX_Asynch_Result * ACE_POSIX_AIOCB_Proactor::getq_result (void)
{
  ACE_MT (ACE_GUARD_RETURN (ACE_SYNCH_MUTEX, ace_mon, this->mutex_, 0));

  ACE_POSIX_Asynch_Result* result = 0;

  if (this->result_queue_.dequeue_head (result) != 0)
    return 0;

//  don't waste time if queue is empty - it is normal
//  or check queue size before dequeue_head
//    ACE_ERROR_RETURN ((LM_ERROR,
//                       "%N:%l:(%P | %t):%p\n",
//                       "ACE_POSIX_AIOCB_Proactor::getq_result failed"),
//                      0);

  return result;
}

int ACE_POSIX_AIOCB_Proactor::clear_result_queue (void)
{
  int ret_val = 0;
  ACE_POSIX_Asynch_Result* result = 0;

  while ((result = this->getq_result ()) != 0)
    {
      delete result;
      ret_val++;
    }

  return ret_val;
}

int ACE_POSIX_AIOCB_Proactor::process_result_queue (void)
{
  int ret_val = 0;
  ACE_POSIX_Asynch_Result* result = 0;

  while ((result = this->getq_result ()) != 0)
    {
      this->application_specific_code
            (result,
             result->bytes_transferred(), // 0, No bytes transferred.
             0,  // No completion key.
             result->error());   //0, No error.

      ret_val++;
    }

  return ret_val;
}

int
ACE_POSIX_AIOCB_Proactor::handle_events_i (u_long milli_seconds)
{
  int result_suspend = 0;
  int retval= 0;

  if (milli_seconds == ACE_INFINITE)
    // Indefinite blocking.
    result_suspend = aio_suspend (aiocb_list_,
                                  aiocb_list_max_size_,
                                  0);
  else
    {
      // Block on <aio_suspend> for <milli_seconds>
      timespec timeout;
      timeout.tv_sec = milli_seconds / 1000;
      timeout.tv_nsec = (milli_seconds - (timeout.tv_sec * 1000)) * 1000000;
      result_suspend = aio_suspend (aiocb_list_,
                                    aiocb_list_max_size_,
                                    &timeout);
    }

  // Check for errors
  if (result_suspend == -1)
    {
      if (errno != EAGAIN &&   // Timeout
          errno != EINTR )    // Interrupted call
          ACE_ERROR ((LM_ERROR,
                      ACE_TEXT ("%N:%l:(%P|%t)::%p\n"),
                      ACE_TEXT ("handle_events: aio_suspend failed")));
      // let continue work
      // we should check "post_completed" queue
    }
  else
    {
      size_t index = 0;
      size_t count = aiocb_list_max_size_;  // max number to iterate
      int error_status = 0;
      size_t transfer_count = 0;

      for (; ; retval++)
        {
          ACE_POSIX_Asynch_Result *asynch_result =
            find_completed_aio (error_status,
                                transfer_count,
                                index,
                                count);

          if (asynch_result == 0)
            break;

          // Call the application code.
          this->application_specific_code (asynch_result,
                                           transfer_count,
                                           0,             // No completion key.
                                           error_status);
        }
    }

  // process post_completed results
  retval += this->process_result_queue ();

  return retval > 0 ? 1 : 0;
}

int
ACE_POSIX_AIOCB_Proactor::get_result_status (ACE_POSIX_Asynch_Result *asynch_result,
                                             int &error_status,
                                             size_t &transfer_count)
{
  transfer_count = 0;

  // Get the error status of the aio_ operation.
  error_status  = aio_error (asynch_result);
  if (error_status == EINPROGRESS)
    return 0;  // not completed

  ssize_t op_return = aio_return (asynch_result);
  if (op_return > 0)
    transfer_count = static_cast<size_t> (op_return);
  // else transfer_count is already 0, error_status reports the error.
  return 1; // completed
}

ACE_POSIX_Asynch_Result *
ACE_POSIX_AIOCB_Proactor::find_completed_aio (int &error_status,
                                              size_t &transfer_count,
                                              size_t &index,
                                              size_t &count)
{
  // parameter index defines initial slot to scan
  // parameter count tells us how many slots should we scan

  ACE_MT (ACE_GUARD_RETURN (ACE_Thread_Mutex, ace_mon, this->mutex_, 0));

  ACE_POSIX_Asynch_Result *asynch_result = 0;

  if (num_started_aio_ == 0)  // save time
    return 0;

  for (; count > 0; index++ , count--)
    {
      if (index >= aiocb_list_max_size_) // like a wheel
        index = 0;

      if (aiocb_list_[index] == 0) // Dont process null blocks.
        continue;

      if (0 != this->get_result_status (result_list_[index],
                                        error_status,
                                        transfer_count))  // completed
        break;

    } // end for

  if (count == 0) // all processed , nothing found
    return 0;
  asynch_result = result_list_[index];

  aiocb_list_[index] = 0;
  result_list_[index] = 0;
  aiocb_list_cur_size_--;

  num_started_aio_--;  // decrement count active aios
  index++;             // for next iteration
  count--;             // for next iteration

  this->start_deferred_aio ();
  //make attempt to start deferred AIO
  //It is safe as we are protected by mutex_

  return asynch_result;
}

int
ACE_POSIX_AIOCB_Proactor::start_aio (ACE_POSIX_Asynch_Result *result,
                                     ACE_POSIX_Proactor::Opcode op)
{
  ACE_TRACE ("ACE_POSIX_AIOCB_Proactor::start_aio");

  ACE_MT (ACE_GUARD_RETURN (ACE_Thread_Mutex, ace_mon, this->mutex_, -1));

  int ret_val = (aiocb_list_cur_size_ >= aiocb_list_max_size_) ? -1 : 0;

  if (result == 0) // Just check the status of the list
    return ret_val;

  // Save operation code in the aiocb
  switch (op)
    {
    case ACE_POSIX_Proactor::ACE_OPCODE_READ:
      result->aio_lio_opcode = LIO_READ;
      break;

    case ACE_POSIX_Proactor::ACE_OPCODE_WRITE:
      result->aio_lio_opcode = LIO_WRITE;
      break;

    default:
      ACE_ERROR_RETURN ((LM_ERROR,
                         ACE_TEXT ("%N:%l:(%P|%t)::")
                         ACE_TEXT ("start_aio: Invalid op code %d\n"),
                         op),
                        -1);
    }

  if (ret_val != 0)   // No free slot
    {
      errno = EAGAIN;
      return -1;
    }

  // Find a free slot and store.

  ssize_t slot = allocate_aio_slot (result);

  if (slot < 0)
    return -1;

  size_t index = static_cast<size_t> (slot);

  result_list_[index] = result;   //Store result ptr anyway
  aiocb_list_cur_size_++;

  ret_val = start_aio_i (result);
  switch (ret_val)
    {
    case 0:     // started OK
      aiocb_list_[index] = result;
      return 0;

    case 1:     // OS AIO queue overflow
      num_deferred_aiocb_ ++;
      return 0;

    default:    // Invalid request, there is no point
      break;    // to start it later
    }

  result_list_[index] = 0;
  aiocb_list_cur_size_--;
  return -1;
}

ssize_t
ACE_POSIX_AIOCB_Proactor::allocate_aio_slot (ACE_POSIX_Asynch_Result *result)
{
  size_t i = 0;

  // we reserve zero slot for ACE_AIOCB_Notify_Pipe_Manager
  // so make check for ACE_AIOCB_Notify_Pipe_Manager request

  if (notify_pipe_read_handle_ == result->aio_fildes) // Notify_Pipe ?
    {                                       // should be free,
      if (result_list_[i] != 0)           // only 1 request
        {                                   // is allowed
          errno   = EAGAIN;
          ACE_ERROR_RETURN ((LM_ERROR,
                     "%N:%l:(%P | %t)::\n"
                     "ACE_POSIX_AIOCB_Proactor::allocate_aio_slot:"
                     "internal Proactor error 0\n"),
                     -1);
        }
    }
  else  //try to find free slot as usual, but starting from 1
    {
      for (i= 1; i < this->aiocb_list_max_size_; i++)
        if (result_list_[i] == 0)
          break;
    }

  if (i >= this->aiocb_list_max_size_)
    ACE_ERROR_RETURN ((LM_ERROR,
              "%N:%l:(%P | %t)::\n"
              "ACE_POSIX_AIOCB_Proactor::allocate_aio_slot:"
              "internal Proactor error 1\n"),
              -1);

  //setup OS notification methods for this aio
  result->aio_sigevent.sigev_notify = SIGEV_NONE;

  return static_cast<ssize_t> (i);
}

// start_aio_i  has new return codes
//     0    AIO was started successfully
//     1    AIO was not started, OS AIO queue overflow
//     -1   AIO was not started, other errors

int
ACE_POSIX_AIOCB_Proactor::start_aio_i (ACE_POSIX_Asynch_Result *result)
{
  ACE_TRACE ("ACE_POSIX_AIOCB_Proactor::start_aio_i");

  int ret_val;
  const ACE_TCHAR *ptype = 0;

  // Start IO

  switch (result->aio_lio_opcode )
    {
    case LIO_READ :
      ptype = ACE_TEXT ("read ");
      ret_val = aio_read (result);
      break;
    case LIO_WRITE :
      ptype = ACE_TEXT ("write");
      ret_val = aio_write (result);
      break;
    default:
      ptype = ACE_TEXT ("?????");
      ret_val = -1;
      break;
    }

  if (ret_val == 0)
    {
      ++this->num_started_aio_;
    }
  else // if (ret_val == -1)
    {
      if (errno == EAGAIN || errno == ENOMEM)  //Ok, it will be deferred AIO
        ret_val = 1;
      else
        ACE_ERROR ((LM_ERROR,
                    ACE_TEXT ("%N:%l:(%P | %t)::start_aio_i: aio_%s %p\n"),
                    ptype,
                    ACE_TEXT ("queueing failed")));
    }

  return ret_val;
}

int
ACE_POSIX_AIOCB_Proactor::start_deferred_aio ()
{
  ACE_TRACE ("ACE_POSIX_AIOCB_Proactor::start_deferred_aio");

  // This protected method is called from
  // find_completed_aio after any AIO completion
  // We should call this method always with locked
  // ACE_POSIX_AIOCB_Proactor::mutex_
  //
  // It tries to start the first deferred AIO
  // if such exists

  if (num_deferred_aiocb_ == 0)
    return 0;  //  nothing to do

  size_t i = 0;

  for (i= 0; i < this->aiocb_list_max_size_; i++)
    if (result_list_[i] !=0       // check for
       && aiocb_list_[i]  ==0)     // deferred AIO
      break;

  if (i >= this->aiocb_list_max_size_)
    ACE_ERROR_RETURN ((LM_ERROR,
                 "%N:%l:(%P | %t)::\n"
                 "start_deferred_aio:"
                 "internal Proactor error 3\n"),
                 -1);

  ACE_POSIX_Asynch_Result *result = result_list_[i];

  int ret_val = start_aio_i (result);

  switch (ret_val)
    {
    case 0 :    //started OK , decrement count of deferred AIOs
      aiocb_list_[i] = result;
      num_deferred_aiocb_ --;
      return 0;

    case 1 :
      return 0;  //try again later

    default :     // Invalid Parameters , should never be
      break;
    }

  //AL notify  user

  result_list_[i] = 0;
  --aiocb_list_cur_size_;

  --num_deferred_aiocb_;

  result->set_error (errno);
  result->set_bytes_transferred (0);
  this->putq_result (result);  // we are with locked mutex_ here !

  return -1;
}

int
ACE_POSIX_AIOCB_Proactor::cancel_aio (ACE_HANDLE handle)
{
  // This new method should be called from
  // ACE_POSIX_Asynch_Operation instead of usual ::aio_cancel
  // It scans the result_list_ and defines all AIO requests
  // that were issued for handle "handle"
  //
  // For all deferred AIO requests with handle "handle"
  // it removes its from the lists and notifies user
  //
  // For all running AIO requests with handle "handle"
  // it calls ::aio_cancel. According to the POSIX standards
  // we will receive ECANCELED  for all ::aio_canceled AIO requests
  // later on return from ::aio_suspend

  ACE_TRACE ("ACE_POSIX_AIOCB_Proactor::cancel_aio");

  int    num_total     = 0;
  int    num_cancelled = 0;

  {
    ACE_MT (ACE_GUARD_RETURN (ACE_Thread_Mutex, ace_mon, this->mutex_, -1));

    size_t ai = 0;

    for (ai = 0; ai < this->aiocb_list_max_size_; ai++)
      {
        if (this->result_list_[ai] == 0)    // Skip empty slot
          continue;

        if (this->result_list_[ai]->aio_fildes != handle)  // Not ours
          continue;

        ++num_total;

        ACE_POSIX_Asynch_Result *asynch_result = this->result_list_[ai];

        if (this->aiocb_list_[ai] == 0)  // Canceling a deferred operation
          {
            num_cancelled++;
            this->num_deferred_aiocb_--;

            this->aiocb_list_[ai] = 0;
            this->result_list_[ai] = 0;
            this->aiocb_list_cur_size_--;

            asynch_result->set_error (ECANCELED);
            asynch_result->set_bytes_transferred (0);
            this->putq_result (asynch_result);
            // we are with locked mutex_ here !
          }
        else      // Cancel started aio
          {
            int rc_cancel = this->cancel_aiocb (asynch_result);

            if (rc_cancel == 0)    //notification in the future
              num_cancelled++;     //it is OS responsiblity
          }
      }

  } // release mutex_

  if (num_total == 0)
    return 1;  // ALLDONE

  if (num_cancelled == num_total)
    return 0;  // CANCELLED

  return 2; // NOT CANCELLED
}

int
ACE_POSIX_AIOCB_Proactor::cancel_aiocb (ACE_POSIX_Asynch_Result * result)
{
  // This method is called from cancel_aio
  // to cancel a previously submitted AIO request
  int rc = ::aio_cancel (0, result);

  // Check the return value and return 0/1/2 appropriately.
  if (rc == AIO_CANCELED)
    return 0;
  else if (rc == AIO_ALLDONE)
    return 1;
  else // (rc == AIO_NOTCANCELED)
    return 2;
}

// *********************************************************************

#if defined(ACE_HAS_POSIX_REALTIME_SIGNALS)

ACE_POSIX_SIG_Proactor::ACE_POSIX_SIG_Proactor (size_t max_aio_operations)
  :  ACE_POSIX_AIOCB_Proactor (max_aio_operations,
                               ACE_POSIX_Proactor::PROACTOR_SIG)
{
  // = Set up the mask we'll use to block waiting for SIGRTMIN. Use that
  // to add it to the signal mask for this thread, and also set the process
  // signal action to pass signal information when we want it.

  // Clear the signal set.
  ACE_OS::sigemptyset (&this->RT_completion_signals_);

  // Add the signal number to the signal set.
  if (ACE_OS::sigaddset (&this->RT_completion_signals_, ACE_SIGRTMIN) == -1)
    ACE_ERROR ((LM_ERROR, ACE_TEXT ("ACE_POSIX_SIG_Proactor: %p\n"),
                ACE_TEXT ("sigaddset")));
  this->block_signals ();
  // Set up the signal action for SIGRTMIN.
  this->setup_signal_handler (ACE_SIGRTMIN);

  // we do not have to create notify manager
  // but we should start pseudo-asynchronous accept task
  // one per all future acceptors

  this->get_asynch_pseudo_task().start ();
  return;
}

ACE_POSIX_SIG_Proactor::ACE_POSIX_SIG_Proactor (const sigset_t signal_set,
                                                size_t max_aio_operations)
  :  ACE_POSIX_AIOCB_Proactor (max_aio_operations,
                               ACE_POSIX_Proactor::PROACTOR_SIG)
{
  // = Keep <Signal_set> with the Proactor, mask all the signals and
  //   setup signal actions for the signals in the <signal_set>.

  // = Keep <signal_set> with the Proactor.

  // Empty the signal set first.
  if (sigemptyset (&this->RT_completion_signals_) == -1)
    ACE_ERROR ((LM_ERROR,
                "Error:(%P | %t):%p\n",
                "sigemptyset failed"));

  // For each signal number present in the <signal_set>, add it to
  // the signal set we use, and also set up its process signal action
  // to allow signal info to be passed into sigwait/sigtimedwait.
  int member = 0;
  for (int si = ACE_SIGRTMIN; si <= ACE_SIGRTMAX; si++)
    {
      member = sigismember (&signal_set,
                            si);
      if (member == -1)
        ACE_ERROR ((LM_ERROR,
                    "%N:%l:(%P | %t)::%p\n",
                    "ACE_POSIX_SIG_Proactor::ACE_POSIX_SIG_Proactor:"
                    "sigismember failed"));
      else if (member == 1)
        {
          sigaddset (&this->RT_completion_signals_, si);
          this->setup_signal_handler (si);
        }
    }

  // Mask all the signals.
  this->block_signals ();

  // we do not have to create notify manager
  // but we should start pseudo-asynchronous accept task
  // one per all future acceptors

  this->get_asynch_pseudo_task().start ();
  return;
}

ACE_POSIX_SIG_Proactor::~ACE_POSIX_SIG_Proactor (void)
{
  this->close ();

  // @@ Enable the masked signals again.
}

ACE_POSIX_Proactor::Proactor_Type
ACE_POSIX_SIG_Proactor::get_impl_type (void)
{
  return PROACTOR_SIG;
}

int
ACE_POSIX_SIG_Proactor::handle_events (ACE_Time_Value &wait_time)
{
  // Decrement <wait_time> with the amount of time spent in the method
  ACE_Countdown_Time countdown (&wait_time);
  return this->handle_events_i (&wait_time);
}

int
ACE_POSIX_SIG_Proactor::handle_events (void)
{
  return this->handle_events_i (0);
}

int
ACE_POSIX_SIG_Proactor::notify_completion (int sig_num)
{
  // Get this process id.
  pid_t const pid = ACE_OS::getpid ();
  if (pid == (pid_t) -1)
    ACE_ERROR_RETURN ((LM_ERROR,
                       "Error:%N:%l(%P | %t):%p",
                       "<getpid> failed"),
                      -1);

  // Set the signal information.
  sigval value;
#if defined (ACE_HAS_SIGVAL_SIGVAL_INT)
  value.sigval_int = -1;
#else
  value.sival_int = -1;
#endif /* ACE_HAS_SIGVAL_SIGVAL_INT */

  // Queue the signal.
  if (sigqueue (pid, sig_num, value) == 0)
    return 0;

  if (errno != EAGAIN)
    ACE_ERROR_RETURN ((LM_ERROR,
                       "Error:%N:%l:(%P | %t):%p\n",
                       "<sigqueue> failed"),
                      -1);
  return -1;
}

ACE_Asynch_Result_Impl *
ACE_POSIX_SIG_Proactor::create_asynch_timer
  (const ACE_Handler::Proxy_Ptr &handler_proxy,
   const void *act,
   const ACE_Time_Value &tv,
   ACE_HANDLE event,
   int priority,
   int signal_number)
{
  int is_member = 0;

  // Fix the signal number.
  if (signal_number == -1)
    {
      int si;
      for (si = ACE_SIGRTMAX;
           (is_member == 0) && (si >= ACE_SIGRTMIN);
           si--)
        {
          is_member = sigismember (&this->RT_completion_signals_,
                                   si);
          if (is_member == -1)
            ACE_ERROR_RETURN ((LM_ERROR,
                               "%N:%l:(%P | %t)::%s\n",
                               "ACE_POSIX_SIG_Proactor::create_asynch_timer:"
                               "sigismember failed"),
                              0);
        }

      if (is_member == 0)
        ACE_ERROR_RETURN ((LM_ERROR,
                           "Error:%N:%l:(%P | %t)::%s\n",
                           "ACE_POSIX_SIG_Proactor::ACE_POSIX_SIG_Proactor:"
                           "Signal mask set empty"),
                          0);
      else
        // + 1 to nullify loop increment.
        signal_number = si + 1;
    }

  ACE_Asynch_Result_Impl *implementation;
  ACE_NEW_RETURN (implementation,
                  ACE_POSIX_Asynch_Timer (handler_proxy,
                                          act,
                                          tv,
                                          event,
                                          priority,
                                          signal_number),
                  0);
  return implementation;
}

#if 0
static void
sig_handler (int sig_num, siginfo_t *, ucontext_t *)
{
  // Should never be called
  ACE_DEBUG ((LM_DEBUG,
              "%N:%l:(%P | %t)::sig_handler received signal: %d\n",
               sig_num));
}
#endif /*if 0*/

int
ACE_POSIX_SIG_Proactor::setup_signal_handler (int signal_number) const
{
  // Set up the specified signal so that signal information will be
  // passed to sigwaitinfo/sigtimedwait. Don't change the default
  // signal handler - having a handler and waiting for the signal can
  // produce undefined behavior.

  // But can not use SIG_DFL
  // With SIG_DFL after delivering the first signal
  // SIG_DFL handler resets  SA_SIGINFO flags
  // and we will lose all information sig_info
  // At least all SunOS have such behavior
#if 0
  struct sigaction reaction;
  sigemptyset (&reaction.sa_mask);   // Nothing else to mask.
  reaction.sa_flags = SA_SIGINFO;    // Realtime flag.
  reaction.sa_sigaction = ACE_SIGNAL_C_FUNC (sig_handler); // (SIG_DFL);
  int sigaction_return = ACE_OS::sigaction (signal_number,
                                            &reaction,
                                            0);
  if (sigaction_return == -1)
    ACE_ERROR_RETURN ((LM_ERROR,
                       "Error:%p\n",
                       "Proactor couldnt do sigaction for the RT SIGNAL"),
                      -1);
#else
  ACE_UNUSED_ARG(signal_number);
#endif
  return 0;
}

int
ACE_POSIX_SIG_Proactor::block_signals (void) const
{
  return ACE_OS::pthread_sigmask (SIG_BLOCK, &this->RT_completion_signals_, 0);
}

ssize_t
ACE_POSIX_SIG_Proactor::allocate_aio_slot (ACE_POSIX_Asynch_Result *result)
{
  size_t i = 0;

  //try to find free slot as usual, starting from 0
  for (i = 0; i < this->aiocb_list_max_size_; i++)
    if (result_list_[i] == 0)
      break;

  if (i >= this->aiocb_list_max_size_)
    ACE_ERROR_RETURN ((LM_ERROR,
              "%N:%l:(%P | %t)::\n"
              "ACE_POSIX_SIG_Proactor::allocate_aio_slot "
              "internal Proactor error 1\n"),
              -1);

  // setup OS notification methods for this aio
  // store index!!, not pointer in signal info
  result->aio_sigevent.sigev_notify = SIGEV_SIGNAL;
  result->aio_sigevent.sigev_signo = result->signal_number ();
#if defined (ACE_HAS_SIGVAL_SIGVAL_INT)
  result->aio_sigevent.sigev_value.sigval_int = static_cast<int> (i);
#else
  result->aio_sigevent.sigev_value.sival_int = static_cast<int> (i);
#endif /* ACE_HAS_SIGVAL_SIGVAL_INT */

  return static_cast<ssize_t> (i);
}

int
ACE_POSIX_SIG_Proactor::handle_events_i (const ACE_Time_Value *timeout)
{
  int result_sigwait = 0;
  siginfo_t sig_info;

  do
    {
      // Wait for the signals.
      if (timeout == 0)
        {
          result_sigwait = ACE_OS::sigwaitinfo (&this->RT_completion_signals_,
                                                &sig_info);
        }
      else
        {
          result_sigwait = ACE_OS::sigtimedwait (&this->RT_completion_signals_,
                                                 &sig_info,
                                                 timeout);
          if (result_sigwait == -1 && errno == EAGAIN)
            return 0;
        }
    }
  while (result_sigwait == -1 && errno == EINTR);

  if (result_sigwait == -1)  // Not a timeout, not EINTR: tell caller of error
    return -1;

  // Decide what to do. We always check the completion queue since it's an
  // easy, quick check. What is decided here is whether to check for
  // I/O completions and, if so, how completely to scan.
  int flg_aio = 0;           // 1 if AIO Completion possible

  size_t index = 0;          // start index to scan aiocb list
  size_t count = 1;          // max number of aiocbs to scan
  int error_status = 0;
  size_t transfer_count = 0;

  if (sig_info.si_code == SI_ASYNCIO || this->os_id_ == ACE_OS_SUN_56)
    {
      flg_aio = 1;  // AIO signal received
      // define index to start
      // nothing will happen if it contains garbage
#if defined (ACE_HAS_SIGVAL_SIGVAL_INT)
      index = static_cast<size_t> (sig_info.si_value.sigval_int);
#else
      index = static_cast<size_t> (sig_info.si_value.sival_int);
#endif /* ACE_HAS_SIGVAL_SIGVAL_INT */
      // Assume we have a correctly-functioning implementation, and that
      // there is one I/O to process, and it's correctly specified in the
      // siginfo received. There are, however, some special situations
      // where this isn't true...
      if (os_id_ == ACE_OS_SUN_56) // Solaris 6
        {
          // 1. Solaris 6 always loses any RT signal,
          //    if it has more SIGQUEMAX=32 pending signals
          //    so we should scan the whole aiocb list
          // 2. Moreover,it has one more bad habit
          //    to notify aio completion
          //    with SI_QUEUE code instead of SI_ASYNCIO, hence the
          //    OS_SUN_56 addition to the si_code check, above.
          count = aiocb_list_max_size_;
        }
    }
  else if (sig_info.si_code != SI_QUEUE)
    {
      // Unknown signal code.
      // may some other third-party libraries could send it
      // or message queue could also generate it !
      // So print the message and check our completions
      ACE_ERROR ((LM_DEBUG,
                  ACE_TEXT ("%N:%l:(%P | %t): ")
                  ACE_TEXT ("ACE_POSIX_SIG_Proactor::handle_events: ")
                  ACE_TEXT ("Unexpected signal code (%d) returned ")
                  ACE_TEXT ("from sigwait; expecting %d\n"),
                  result_sigwait, sig_info.si_code));
      flg_aio = 1;
    }

  int ret_aio = 0;
  int ret_que = 0;

  if (flg_aio)
    for (; ; ret_aio++)
      {
        ACE_POSIX_Asynch_Result *asynch_result =
          find_completed_aio (error_status,
                              transfer_count,
                              index,
                              count);

        if (asynch_result == 0)
          break;

        // Call the application code.
        this->application_specific_code (asynch_result,
                                         transfer_count,
                                         0,             // No completion key.
                                         error_status); // Error
      }

  // process post_completed results
  ret_que = this->process_result_queue ();

  // Uncomment this  if you want to test
  // and research the behavior of you system
#if 0
  ACE_DEBUG ((LM_DEBUG,
              "(%t) NumAIO=%d NumQueue=%d\n",
              ret_aio, ret_que));
#endif

  return ret_aio + ret_que > 0 ? 1 : 0;
}

#endif /* ACE_HAS_POSIX_REALTIME_SIGNALS */

// *********************************************************************

ACE_POSIX_Asynch_Timer::ACE_POSIX_Asynch_Timer
  (const ACE_Handler::Proxy_Ptr &handler_proxy,
   const void *act,
   const ACE_Time_Value &tv,
   ACE_HANDLE event,
   int priority,
   int signal_number)
  : ACE_POSIX_Asynch_Result
     (handler_proxy, act, event, 0, 0, priority, signal_number),
    time_ (tv)
{
}

void
ACE_POSIX_Asynch_Timer::complete (size_t       /* bytes_transferred */,
                                  int          /* success */,
                                  const void * /* completion_key */,
                                  u_long       /* error */)
{
  ACE_Handler *handler = this->handler_proxy_.get ()->handler ();
  if (handler != 0)
    handler->handle_time_out (this->time_, this->act ());
}

// *********************************************************************

ACE_POSIX_Wakeup_Completion::ACE_POSIX_Wakeup_Completion
  (const ACE_Handler::Proxy_Ptr &handler_proxy,
   const void *act,
   ACE_HANDLE event,
   int priority,
   int signal_number)
  : ACE_Asynch_Result_Impl (),
    ACE_POSIX_Asynch_Result (handler_proxy,
                             act,
                             event,
                             0,
                             0,
                             priority,
                             signal_number)
{
}

ACE_POSIX_Wakeup_Completion::~ACE_POSIX_Wakeup_Completion (void)
{
}

void
ACE_POSIX_Wakeup_Completion::complete (size_t       /* bytes_transferred */,
                                       int          /* success */,
                                       const void * /* completion_key */,
                                       u_long       /*  error */)
{

  ACE_Handler *handler = this->handler_proxy_.get ()->handler ();
  if (handler != 0)
    handler->handle_wakeup ();
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_HAS_AIO_CALLS */

