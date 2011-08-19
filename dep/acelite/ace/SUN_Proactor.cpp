// $Id: SUN_Proactor.cpp 91286 2010-08-05 09:04:31Z johnnyw $

#include "ace/SUN_Proactor.h"

#if defined (ACE_HAS_AIO_CALLS) && defined (sun)

#include "ace/Task_T.h"
#include "ace/Log_Msg.h"
#include "ace/Object_Manager.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_SUN_Proactor::ACE_SUN_Proactor (size_t max_aio_operations)
  : ACE_POSIX_AIOCB_Proactor (max_aio_operations,
                              ACE_POSIX_Proactor::PROACTOR_SUN),
    condition_ (mutex_)
{
  // To provide correct virtual calls.
  create_notify_manager ();

  // we should start pseudo-asynchronous accept task
  // one per all future acceptors

  this->get_asynch_pseudo_task ().start ();
}

// Destructor.
ACE_SUN_Proactor::~ACE_SUN_Proactor (void)
{
  this->close ();
}

int
ACE_SUN_Proactor::handle_events (ACE_Time_Value &wait_time)
{
  // Decrement <wait_time> with the amount of time spent in the method
  ACE_Countdown_Time countdown (&wait_time);
  return this->handle_events_i (&wait_time);
}

int
ACE_SUN_Proactor::handle_events (void)
{
  return this->handle_events_i (0);
}

int ACE_SUN_Proactor::wait_for_start (ACE_Time_Value * abstime)
{
#if defined (ACE_MT_SAFE) && (ACE_MT_SAFE != 0)

  ACE_MT (ACE_GUARD_RETURN (ACE_Thread_Mutex, ace_mon, mutex_, -1));

  if (this->num_started_aio_ != 0)  // double check
    return 0;

  return this->condition_.wait (abstime);

#else

  return 0;  // or -1 ???

#endif /* ACE_MT_SAFE */
}

int
ACE_SUN_Proactor::handle_events_i (ACE_Time_Value *delta)
{
  int retval = 0;
  aio_result_t *result = 0;

  if (0 == delta)
    {
      if (this->num_started_aio_ == 0)
        this->wait_for_start (0);

      result = aiowait (0);
    }
  else
    {
      if (this->num_started_aio_ == 0)
        {
          // Decrement delta with the amount of time spent waiting
          ACE_Countdown_Time countdown (delta);
          ACE_Time_Value tv (*delta);
          tv += ACE_OS::gettimeofday ();
          if (this->wait_for_start (&tv) == -1)
            return -1;
        }
      struct timeval delta_tv = *delta;
      result = aiowait (&delta_tv);
    }

  if (result == 0)
    {
      // timeout, do nothing,
      // we should process "post_completed" queue
    }
  else if (reinterpret_cast<long> (result) == -1)
    {
      // Check errno  for  EINVAL,EAGAIN,EINTR ??
      switch (errno)
       {
       case EINTR :     // aiowait() was interrupted by a signal.
       case EINVAL:     // there are no outstanding asynchronous I/O requests.
         break;         // we should process "post_completed" queue

       default:         // EFAULT
         ACE_ERROR_RETURN ((LM_ERROR,
                       ACE_TEXT("%N:%l:(%P | %t)::%p \nNumAIO=%d\n"),
                       ACE_TEXT("ACE_SUN_Proactor::handle_events: aiowait failed"),
                        num_started_aio_),
                      -1);
       }
    }
  else
    {
      int error_status = 0;
      size_t transfer_count = 0;

      ACE_POSIX_Asynch_Result *asynch_result =
        find_completed_aio (result,
                            error_status,
                            transfer_count);

      if (asynch_result != 0)
        {
          // Call the application code.
          this->application_specific_code (asynch_result,
                                           transfer_count,
                                           0,             // No completion key.
                                           error_status); // Error
          retval++;
        }
    }

  // process post_completed results
  retval += this->process_result_queue ();

  return retval > 0 ? 1 : 0 ;

}

int
ACE_SUN_Proactor::get_result_status (ACE_POSIX_Asynch_Result* asynch_result,
                                     int &error_status,
                                     size_t &transfer_count)
{

   // Get the error status of the aio_ operation.
   error_status  = asynch_result->aio_resultp.aio_errno;
   ssize_t op_return = asynch_result->aio_resultp.aio_return;

   // ****** from Sun man pages *********************
   // Upon completion of the operation both aio_return and aio_errno
   // are set to reflect the result of the operation.
   // AIO_INPROGRESS is not a value used by the system
   // so the client may detect a change in state
   // by initializing aio_return to this value.

   if (error_status == EINPROGRESS || op_return == AIO_INPROGRESS)
     return 0;  // not completed

   if (op_return < 0)
     transfer_count = 0; // zero bytes transferred
   else
     transfer_count = static_cast<size_t> (op_return);

   return 1; // completed
}

ACE_POSIX_Asynch_Result *
ACE_SUN_Proactor::find_completed_aio (aio_result_t *result,
                                      int &error_status,
                                      size_t &transfer_count)
{
  ACE_MT (ACE_GUARD_RETURN (ACE_Thread_Mutex, ace_mon, mutex_, 0));

  size_t ai;
  error_status = -1;
  transfer_count = 0;

  // we call find_completed_aio always with result != 0

  for (ai = 0; ai < aiocb_list_max_size_; ai++)
    if (aiocb_list_[ai] != 0 &&                 //check for non zero
        result == &aiocb_list_[ai]->aio_resultp)
      break;

  if (ai >= aiocb_list_max_size_)   // not found
    return 0;                       // means somebody else uses aio directly!!!

  ACE_POSIX_Asynch_Result *asynch_result = result_list_[ai];

  if (this->get_result_status (asynch_result,
                               error_status,
                               transfer_count) == 0)
    { // should never be
      ACE_ERROR ((LM_ERROR,
                  ACE_TEXT("%N:%l:(%P | %t)::%p\n"),
                  ACE_TEXT("ACE_SUN_Proactor::find_completed_aio:")
                  ACE_TEXT("should never be !!!\n")));
      return 0;
    }

  aiocb_list_[ai] = 0;
  result_list_[ai] = 0;
  aiocb_list_cur_size_--;

  num_started_aio_--;

  start_deferred_aio ();
  //make attempt to start deferred AIO
  //It is safe as we are protected by mutex_

  return asynch_result;
}

// start_aio_i has new return codes
// 0  successful start
// 1  try later, OS queue overflow
// -1 invalid request and other errors

int
ACE_SUN_Proactor::start_aio_i (ACE_POSIX_Asynch_Result *result)
{
  ACE_TRACE ("ACE_SUN_Proactor::start_aio_i");

  int ret_val;
  const ACE_TCHAR *ptype;

  // ****** from Sun man pages *********************
  // Upon completion of the operation both aio_return and aio_errno
  // are set to reflect the result of the operation.
  // AIO_INPROGRESS is not a value used by the system
  // so the client may detect a change in state
  // by initializing aio_return to this value.
  result->aio_resultp.aio_return = AIO_INPROGRESS;
  result->aio_resultp.aio_errno  = EINPROGRESS;

  // Start IO
  switch (result->aio_lio_opcode)
    {
    case LIO_READ :
      ptype = ACE_TEXT ("read");
      ret_val = aioread (result->aio_fildes,
                         (char *) result->aio_buf,
                         result->aio_nbytes,
                         result->aio_offset,
                         SEEK_SET,
                         &result->aio_resultp);
      break;

    case LIO_WRITE :
      ptype = ACE_TEXT ("write");
      ret_val = aiowrite (result->aio_fildes,
                          (char *) result->aio_buf,
                          result->aio_nbytes,
                          result->aio_offset,
                          SEEK_SET,
                          &result->aio_resultp);
      break;

    default:
      ptype = ACE_TEXT ("?????");
      ret_val = -1;
      break;
    }

  if (ret_val == 0)
    {
      this->num_started_aio_++;
      if (this->num_started_aio_ == 1)  // wake up condition
        this->condition_.broadcast ();
    }
  else // if (ret_val == -1)
    {
      if (errno == EAGAIN || errno == ENOMEM) // Defer - retry this later.
        ret_val = 1;
      else
        ACE_ERROR ((LM_ERROR,
                    ACE_TEXT ("%N:%l:(%P | %t)::start_aio: aio%s %p\n"),
                    ptype,
                    ACE_TEXT ("queueing failed\n")));
    }

  return ret_val;
}

int
ACE_SUN_Proactor::cancel_aiocb (ACE_POSIX_Asynch_Result *result)
{
  ACE_TRACE ("ACE_SUN_Proactor::cancel_aiocb");
  int rc = ::aiocancel (&result->aio_resultp);
  if (rc == 0)    //  AIO_CANCELED
    {
      // after aiocancel Sun does not notify us
      // so we should send notification
      // to save POSIX behavoir.
      // Also we should do this for deffered aio's

      result->set_error (ECANCELED);
      result->set_bytes_transferred (0);
      this->putq_result (result);
      return 0;
    }

  return 2;
}

ACE_POSIX_Proactor::Proactor_Type
ACE_SUN_Proactor::get_impl_type (void)
{
  return PROACTOR_SUN;
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_HAS_AIO_CALLS && sun */
