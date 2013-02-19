// $Id: POSIX_CB_Proactor.cpp 91683 2010-09-09 09:07:49Z johnnyw $

#include "ace/POSIX_CB_Proactor.h"

#if defined (ACE_HAS_AIO_CALLS) && !defined (ACE_HAS_BROKEN_SIGEVENT_STRUCT)

#include "ace/Task_T.h"
#include "ace/Log_Msg.h"
#include "ace/Object_Manager.h"
#include "ace/OS_NS_sys_time.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_POSIX_CB_Proactor::ACE_POSIX_CB_Proactor (size_t max_aio_operations)
  : ACE_POSIX_AIOCB_Proactor (max_aio_operations,
                              ACE_POSIX_Proactor::PROACTOR_CB),
    sema_ ((unsigned int) 0)
{
  // we should start pseudo-asynchronous accept task
  // one per all future acceptors

  this->get_asynch_pseudo_task ().start ();
}

// Destructor.
ACE_POSIX_CB_Proactor::~ACE_POSIX_CB_Proactor (void)
{
  this->close ();
}

ACE_POSIX_Proactor::Proactor_Type
ACE_POSIX_CB_Proactor::get_impl_type (void)
{
  return PROACTOR_CB;
}

void ACE_POSIX_CB_Proactor::aio_completion_func (sigval cb_data)
{
  ACE_POSIX_CB_Proactor * impl = static_cast<ACE_POSIX_CB_Proactor *> (cb_data.sival_ptr);
  if ( impl != 0 )
    impl->notify_completion (0);
}

#if defined (ACE_HAS_SIG_C_FUNC)
extern "C" void
ACE_POSIX_CB_Proactor_aio_completion (sigval cb_data)
{
  ACE_POSIX_CB_Proactor::aio_completion_func (cb_data);
}
#endif /* ACE_HAS_SIG_C_FUNC */

int
ACE_POSIX_CB_Proactor::handle_events (ACE_Time_Value &wait_time)
{
  // Decrement <wait_time> with the amount of time spent in the method
  ACE_Countdown_Time countdown (&wait_time);
  return this->handle_events_i (wait_time.msec ());
}

int
ACE_POSIX_CB_Proactor::handle_events (void)
{
  return this->handle_events_i (ACE_INFINITE);
}

int
ACE_POSIX_CB_Proactor::notify_completion (int sig_num)
{
  ACE_UNUSED_ARG (sig_num);

  return this->sema_.release();
}


ssize_t
ACE_POSIX_CB_Proactor::allocate_aio_slot (ACE_POSIX_Asynch_Result *result)
{
  ssize_t slot = ACE_POSIX_AIOCB_Proactor::allocate_aio_slot (result);
  if (slot == -1)
    return -1;

  // setup OS notification methods for this aio
  // @@ TODO: This gets the completion method back to this proactor to
  // find the completed aiocb. It would be so much better to not only get
  // the proactor, but the aiocb as well.
  result->aio_sigevent.sigev_notify = SIGEV_THREAD;
#  if defined (ACE_HAS_SIG_C_FUNC)
  result->aio_sigevent.sigev_notify_function =
    ACE_POSIX_CB_Proactor_aio_completion;
#  else
  result->aio_sigevent.sigev_notify_function = aio_completion_func;
#  endif /* ACE_HAS_SIG_C_FUNC */
  result->aio_sigevent.sigev_notify_attributes = 0;

  result->aio_sigevent.sigev_value.sival_ptr = this ;

  return slot;
}

int
ACE_POSIX_CB_Proactor::handle_events_i (u_long milli_seconds)
{

  int result_wait=0;

  // Wait for the signals.
  if (milli_seconds == ACE_INFINITE)
    {
      result_wait = this->sema_.acquire();
    }
  else
    {
      // Wait for <milli_seconds> amount of time.
      ACE_Time_Value abs_time = ACE_OS::gettimeofday ()
                              + ACE_Time_Value (0, milli_seconds * 1000);

      result_wait = this->sema_.acquire(abs_time);
    }

  // Check for errors
  // but let continue work in case of errors
  // we should check "post_completed" queue
  if (result_wait == -1)
    {
      int const lerror = errno;
      if (lerror != ETIME &&   // timeout
          lerror != EINTR )    // interrupted system call
        ACE_ERROR ((LM_ERROR,
                    ACE_TEXT("%N:%l:(%P | %t)::%p\n"),
                    ACE_TEXT("ACE_POSIX_CB_Proactor::handle_events:")
                    ACE_TEXT("semaphore acquire failed")
                  ));
    }

  size_t index = 0;          // start index to scan aiocb list
  size_t count = this->aiocb_list_max_size_;  // max number to iterate

  int error_status = 0;
  size_t return_status = 0;

  int ret_aio = 0;
  int ret_que = 0;

  for (;; ret_aio++)
    {
      ACE_POSIX_Asynch_Result * asynch_result =
          this->find_completed_aio (error_status,
                                    return_status,
                                    index,
                                    count);

      if (asynch_result == 0)
          break;

      // Call the application code.
      this->application_specific_code (asynch_result,
                                       return_status, // Bytes transferred.
                                       0,             // No completion key.
                                       error_status); // Error
     }

  // process post_completed results
  ret_que = this->process_result_queue ();

  // Uncomment this  if you want to test
  // and research the behavior of you system
  // ACE_DEBUG ((LM_DEBUG,
  //            "(%t) NumAIO=%d NumQueue=%d\n",
  //             ret_aio, ret_que));

  return ret_aio + ret_que > 0 ? 1 : 0;
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_HAS_AIO_CALLS && !ACE_HAS_BROKEN_SIGEVENT_STRUCT */
