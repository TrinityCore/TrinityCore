// $Id: Message_Queue_NT.cpp 92900 2010-12-17 14:45:11Z mcorino $

#include "ace/Message_Queue.h"
#include "ace/Message_Queue_NT.h"
#include "ace/Log_Msg.h"

#if !defined (__ACE_INLINE__)
#include "ace/Message_Queue_NT.inl"
#endif /* __ACE_INLINE__ */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

#if defined (ACE_HAS_WIN32_OVERLAPPED_IO)

ACE_Message_Queue_NT::ACE_Message_Queue_NT (DWORD max_threads)
  : max_cthrs_ (max_threads),
    cur_thrs_ (0),
    cur_bytes_ (0),
    cur_length_ (0),
    cur_count_ (0),
    completion_port_ (ACE_INVALID_HANDLE)
{
  ACE_TRACE ("ACE_Message_Queue_NT::ACE_Message_Queue_NT");
  this->open (max_threads);
}

int
ACE_Message_Queue_NT::open (DWORD max_threads)
{
  ACE_TRACE ("ACE_Message_Queue_NT::open");
  this->max_cthrs_ = max_threads;
  this->state_ = ACE_Message_Queue_Base::ACTIVATED;
  this->completion_port_ = ::CreateIoCompletionPort (ACE_INVALID_HANDLE,
                                                     0,
                                                     ACE_Message_Queue_Base::ACTIVATED,
                                                     max_threads);
  if (this->completion_port_ == 0)
    this->state_ = ACE_Message_Queue_Base::DEACTIVATED;
  return (this->completion_port_ == 0 ? -1 : 0);
}

int
ACE_Message_Queue_NT::close (void)
{
  ACE_TRACE ("ACE_Message_Queue_NT::close");
  ACE_GUARD_RETURN (ACE_SYNCH_MUTEX, ace_mon, this->lock_, -1);
  this->deactivate ();
  return (::CloseHandle (this->completion_port_) ? 0 : -1 );
}

ACE_Message_Queue_NT::~ACE_Message_Queue_NT (void)
{
  ACE_TRACE ("ACE_Message_Queue_NT::~ACE_Message_Queue_NT");
  this->close ();
}

int
ACE_Message_Queue_NT::enqueue (ACE_Message_Block *new_item,
                               ACE_Time_Value *)
{
  ACE_TRACE ("ACE_Message_Queue_NT::enqueue");
  ACE_GUARD_RETURN (ACE_SYNCH_MUTEX, ace_mon, this->lock_, -1);
  if (this->state_ != ACE_Message_Queue_Base::DEACTIVATED)
    {
      size_t const msize = new_item->total_size ();
      size_t const mlength = new_item->total_length ();
      // Note - we send ACTIVATED in the 3rd arg to tell the completion
      // routine it's _NOT_ being woken up because of deactivate().
      ULONG_PTR state_to_post;
      state_to_post = ACE_Message_Queue_Base::ACTIVATED;
      if (::PostQueuedCompletionStatus (this->completion_port_,
                                        static_cast<DWORD> (msize),
                                        state_to_post,
                                        reinterpret_cast<LPOVERLAPPED> (new_item)))
        {
          // Update the states once I succeed.
          this->cur_bytes_ += msize;
          this->cur_length_ += mlength;
          return ACE_Utils::truncate_cast<int> (++this->cur_count_);
        }
    }
  else
    errno = ESHUTDOWN;

  // Fail to enqueue the message.
  return -1;
}

int
ACE_Message_Queue_NT::dequeue (ACE_Message_Block *&first_item,
                               ACE_Time_Value *timeout)
{
  ACE_TRACE ("ACE_Message_Queue_NT::dequeue_head");

  {
    ACE_GUARD_RETURN (ACE_SYNCH_MUTEX, ace_mon, this->lock_, -1);

    // Make sure the MQ is not deactivated before proceeding.
    if (this->state_ == ACE_Message_Queue_Base::DEACTIVATED)
      {
        errno = ESHUTDOWN;      // Operation on deactivated MQ not allowed.
        return -1;
      }
    else
      ++this->cur_thrs_;        // Increase the waiting thread count.
  }

  ULONG_PTR queue_state;
  DWORD msize;
  // Get a message from the completion port.
  int retv = ::GetQueuedCompletionStatus (this->completion_port_,
                                          &msize,
                                          &queue_state,
                                          reinterpret_cast<LPOVERLAPPED *> (&first_item),
                                          (timeout == 0 ? INFINITE : timeout->msec ()));
  {
    ACE_GUARD_RETURN (ACE_SYNCH_MUTEX, ace_mon, this->lock_, -1);
    --this->cur_thrs_;          // Decrease waiting thread count.
    if (retv)
      {
        if (queue_state == ACE_Message_Queue_Base::ACTIVATED)
          {                     // Really get a valid MB from the queue.
            --this->cur_count_;
            this->cur_bytes_ -= msize;
            this->cur_length_ -= first_item->total_length ();
            return ACE_Utils::truncate_cast<int> (this->cur_count_);
          }
        else                    // Woken up by deactivate () or pulse ().
            errno = ESHUTDOWN;
      }
  }
  return -1;
}

int
ACE_Message_Queue_NT::deactivate (void)
{
  ACE_TRACE ("ACE_Message_Queue_NT::deactivate");
  ACE_GUARD_RETURN (ACE_SYNCH_MUTEX, ace_mon, this->lock_, -1);

  int const previous_state = this->state_;
  if (previous_state != ACE_Message_Queue_Base::DEACTIVATED)
    {
      this->state_ = ACE_Message_Queue_Base::DEACTIVATED;

      // Get the number of shutdown messages necessary to wake up all
      // waiting threads.
      DWORD cntr =
        this->cur_thrs_ - static_cast<DWORD> (this->cur_count_);
      while (cntr-- > 0)
        ::PostQueuedCompletionStatus (this->completion_port_,
                                      0,
                                      this->state_,
                                      0);
    }
  return previous_state;
}

int
ACE_Message_Queue_NT::activate (void)
{
  ACE_TRACE ("ACE_Message_Queue_NT::activate");
  ACE_GUARD_RETURN (ACE_SYNCH_MUTEX, ace_mon, this->lock_, -1);
  int const previous_status = this->state_;
  this->state_ = ACE_Message_Queue_Base::ACTIVATED;
  return previous_status;
}

int
ACE_Message_Queue_NT::pulse (void)
{
  ACE_TRACE ("ACE_Message_Queue_NT::pulse");
  ACE_GUARD_RETURN (ACE_SYNCH_MUTEX, ace_mon, this->lock_, -1);

  int const previous_state = this->state_;
  if (previous_state != ACE_Message_Queue_Base::DEACTIVATED)
    {
      this->state_ = ACE_Message_Queue_Base::PULSED;

      // Get the number of shutdown messages necessary to wake up all
      // waiting threads.

      DWORD cntr =
        this->cur_thrs_ - static_cast<DWORD> (this->cur_count_);
      while (cntr-- > 0)
        ::PostQueuedCompletionStatus (this->completion_port_,
                                      0,
                                      this->state_,
                                      0);
    }
  return previous_state;
}

void
ACE_Message_Queue_NT::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_Message_Queue_NT::dump");

  ACE_DEBUG ((LM_DEBUG, ACE_BEGIN_DUMP, this));
  switch (this->state_)
    {
    case ACE_Message_Queue_Base::ACTIVATED:
      ACE_DEBUG ((LM_DEBUG,
                  ACE_TEXT ("state = ACTIVATED\n")));
      break;
    case ACE_Message_Queue_Base::DEACTIVATED:
      ACE_DEBUG ((LM_DEBUG,
                  ACE_TEXT ("state = DEACTIVATED\n")));
      break;
    case ACE_Message_Queue_Base::PULSED:
      ACE_DEBUG ((LM_DEBUG,
                  ACE_TEXT ("state = PULSED\n")));
      break;
    }

  ACE_DEBUG ((LM_DEBUG,
              ACE_TEXT ("max_cthrs_ = %d\n")
              ACE_TEXT ("cur_thrs_ = %d\n")
              ACE_TEXT ("cur_bytes = %d\n")
              ACE_TEXT ("cur_length = %d\n")
              ACE_TEXT ("cur_count = %d\n")
              ACE_TEXT ("completion_port_ = %x\n"),
              this->max_cthrs_,
              this->cur_thrs_,
              this->cur_bytes_,
              this->cur_length_,
              this->cur_count_,
              this->completion_port_));
  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
#endif /* ACE_HAS_DUMP */
}

#endif /* ACE_HAS_WIN32_OVERLAPPED_IO */

ACE_END_VERSIONED_NAMESPACE_DECL
