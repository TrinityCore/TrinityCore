// $Id: Select_Reactor_Base.cpp 90989 2010-07-05 11:22:50Z johnnyw $

#include "ace/Select_Reactor_Base.h"
#include "ace/Reactor.h"
#include "ace/Thread.h"
#include "ace/SOCK_Acceptor.h"
#include "ace/SOCK_Connector.h"
#include "ace/Timer_Queue.h"
#include "ace/Log_Msg.h"
#include "ace/Signal.h"
#include "ace/OS_NS_fcntl.h"

#if !defined (__ACE_INLINE__)
#include "ace/Select_Reactor_Base.inl"
#endif /* __ACE_INLINE__ */

#ifndef ACE_WIN32
# include <algorithm>
#endif  /* !ACE_WIN32 */

ACE_RCSID (ace,
           Select_Reactor_Base,
           "$Id: Select_Reactor_Base.cpp 90989 2010-07-05 11:22:50Z johnnyw $")


ACE_BEGIN_VERSIONED_NAMESPACE_DECL

template<typename iterator>
inline ACE_Event_Handler *
ACE_SELECT_REACTOR_EVENT_HANDLER (iterator i)
{
#ifdef ACE_WIN32
  return (*i).item ();
#else
  return (*i);
#endif  /* ACE_WIN32 */
}

// Performs sanity checking on the ACE_HANDLE.

bool
ACE_Select_Reactor_Handler_Repository::invalid_handle (ACE_HANDLE handle)
{
  ACE_TRACE ("ACE_Select_Reactor_Handler_Repository::invalid_handle");
#if defined (ACE_WIN32)
  // It's too expensive to perform more exhaustive validity checks on
  // Win32 due to the way that they implement SOCKET HANDLEs.
  if (handle == ACE_INVALID_HANDLE)
#else /* !ACE_WIN32 */
  if (handle < 0
      || static_cast<size_type> (handle) >= this->event_handlers_.size ())
#endif /* ACE_WIN32 */
    {
      errno = EINVAL;
      return true;
    }

  return false;
}

// Performs sanity checking on the ACE_HANDLE.

bool
ACE_Select_Reactor_Handler_Repository::handle_in_range (ACE_HANDLE handle)
{
  ACE_TRACE ("ACE_Select_Reactor_Handler_Repository::handle_in_range");
#if defined (ACE_WIN32)
  // It's too expensive to perform more exhaustive validity checks on
  // Win32 due to the way that they implement SOCKET HANDLEs.
  if (handle != ACE_INVALID_HANDLE)
#else /* !ACE_WIN32 */
  if (handle >= 0 && handle < this->max_handlep1_)
#endif /* ACE_WIN32 */
    {
      return true;
    }

  // Don't bother setting errno.  It isn't used in the select()-based
  // reactors and incurs a TSS access.
  // errno = EINVAL;

  return false;
}

int
ACE_Select_Reactor_Handler_Repository::open (size_type size)
{
  ACE_TRACE ("ACE_Select_Reactor_Handler_Repository::open");

#if defined (ACE_WIN32)
  if (this->event_handlers_.open (size) == -1)
    return -1;
#else
  if (this->event_handlers_.size (size) == -1)
    return -1;

  // Initialize the ACE_Event_Handler pointers to 0.
  std::fill (this->event_handlers_.begin (),
             this->event_handlers_.end (),
             static_cast<ACE_Event_Handler *> (0));

  this->max_handlep1_ = 0;
#endif /* ACE_WIN32 */

  // Try to increase the number of handles if <size> is greater than
  // the current limit.
  return ACE::set_handle_limit (static_cast<int> (size), 1);
}

// Initialize a repository of the appropriate <size>.

ACE_Select_Reactor_Handler_Repository::ACE_Select_Reactor_Handler_Repository (ACE_Select_Reactor_Impl &select_reactor)
  : select_reactor_ (select_reactor),
#ifndef ACE_WIN32
    max_handlep1_ (0),
#endif  /* !ACE_WIN32 */
    event_handlers_ ()
{
  ACE_TRACE ("ACE_Select_Reactor_Handler_Repository::ACE_Select_Reactor_Handler_Repository");
}

int
ACE_Select_Reactor_Handler_Repository::unbind_all (void)
{
  // Unbind all of the <handle, ACE_Event_Handler>s.
#ifdef ACE_WIN32
  map_type::iterator const end = this->event_handlers_.end ();
  for (map_type::iterator pos = this->event_handlers_.begin ();
       pos != end;
       )
    {
      // Post-increment (*not* pre-increment) before unbind()ing since
      // the current iterator will be invalidated during the unbind()
      // operation.
      map_type::iterator const the_pos (pos++);

      ACE_HANDLE const handle = (*the_pos).key ();
      (void) this->unbind (handle,
                           the_pos,
                           ACE_Event_Handler::ALL_EVENTS_MASK);
    }
#else
  // We could use the "end()" iterator but leveraging max_handlep1_
  // allows us to optimize away unnecessary accesses of nil event
  // handler pointers.
  map_type::iterator pos =
    this->event_handlers_.begin ();  // iterator == ACE_Event_Handler*

  for (ACE_HANDLE handle = 0;
       handle < this->max_handlep1_;
       ++handle)
    {
      (void) this->unbind (handle,
                           pos,
                           ACE_Event_Handler::ALL_EVENTS_MASK);
      ++pos;
    }
#endif  /* ACE_WIN32 */

  return 0;
}

int
ACE_Select_Reactor_Handler_Repository::close (void)
{
  ACE_TRACE ("ACE_Select_Reactor_Handler_Repository::close");

  return this->unbind_all ();
}

ACE_Select_Reactor_Handler_Repository::map_type::iterator
ACE_Select_Reactor_Handler_Repository::find_eh (ACE_HANDLE handle)
{
  ACE_TRACE ("ACE_Select_Reactor_Handler_Repository::find_eh");

  map_type::iterator pos (this->event_handlers_.end ());

  // this code assumes the handle is in range.
#if defined (ACE_WIN32)
  this->event_handlers_.find (handle, pos);
#else
  map_type::iterator const tmp = &this->event_handlers_[handle];

  if (*tmp != 0)
    pos = tmp;
#endif /* ACE_WIN32 */

  return pos;
}

// Bind the <ACE_Event_Handler *> to the <ACE_HANDLE>.
int
ACE_Select_Reactor_Handler_Repository::bind (ACE_HANDLE handle,
                                             ACE_Event_Handler *event_handler,
                                             ACE_Reactor_Mask mask)
{
  ACE_TRACE ("ACE_Select_Reactor_Handler_Repository::bind");

  if (event_handler == 0)
    return -1;

  if (handle == ACE_INVALID_HANDLE)
    handle = event_handler->get_handle ();

  if (this->invalid_handle (handle))
    return -1;

  // Is this handle already in the Reactor?
  bool existing_handle = false;

#if defined (ACE_WIN32)

  map_type::ENTRY * entry = 0;

  int const result =
    this->event_handlers_.bind (handle, event_handler, entry);

  if (result == -1)
    {
      return -1;
    }
  else if (result == 1)  // Entry already exists.
    {
      // Cannot use a different handler for an existing handle.
      if (event_handler != entry->item ())
        {
          return -1;
        }
      else
        {
          // Remember that this handle is already registered in the
          // Reactor.
          existing_handle = true;
        }
    }

#else

  // Check if this handle is already registered.
  ACE_Event_Handler * const current_handler =
    this->event_handlers_[handle];

  if (current_handler)
    {
      // Cannot use a different handler for an existing handle.
      if (current_handler != event_handler)
        return -1;

      // Remember that this handle is already registered in the
      // Reactor.
      existing_handle = true;
    }

  this->event_handlers_[handle] = event_handler;

  if (this->max_handlep1_ < handle + 1)
    this->max_handlep1_ = handle + 1;

#endif /* ACE_WIN32 */

  if (this->select_reactor_.is_suspended_i (handle))
    {
      this->select_reactor_.bit_ops (handle,
                                     mask,
                                     this->select_reactor_.suspend_set_,
                                     ACE_Reactor::ADD_MASK);
    }
  else
    {
      this->select_reactor_.bit_ops (handle,
                                     mask,
                                     this->select_reactor_.wait_set_,
                                     ACE_Reactor::ADD_MASK);

      // Note the fact that we've changed the state of the <wait_set_>,
      // which is used by the dispatching loop to determine whether it can
      // keep going or if it needs to reconsult select().
      // this->select_reactor_.state_changed_ = 1;
    }

  // If new entry, call add_reference() if needed.
  if (!existing_handle)
    event_handler->add_reference ();

  return 0;
}

// Remove the binding of <ACE_HANDLE>.

int
ACE_Select_Reactor_Handler_Repository::unbind (
  ACE_HANDLE handle,
  map_type::iterator pos,
  ACE_Reactor_Mask mask)
{
  ACE_TRACE ("ACE_Select_Reactor_Handler_Repository::unbind");

  // Retrieve event handler before unbinding it from the map.  The
  // iterator pointing to it will no longer be valid once the handler
  // is unbound.
  ACE_Event_Handler * const event_handler =
    (pos == this->event_handlers_.end ()
     ? 0
     : ACE_SELECT_REACTOR_EVENT_HANDLER (pos));

  // Clear out the <mask> bits in the Select_Reactor's wait_set.
  this->select_reactor_.bit_ops (handle,
                                 mask,
                                 this->select_reactor_.wait_set_,
                                 ACE_Reactor::CLR_MASK);

  // And suspend_set.
  this->select_reactor_.bit_ops (handle,
                                 mask,
                                 this->select_reactor_.suspend_set_,
                                 ACE_Reactor::CLR_MASK);

  // Note the fact that we've changed the state of the <wait_set_>,
  // which is used by the dispatching loop to determine whether it can
  // keep going or if it needs to reconsult select().
  // this->select_reactor_.state_changed_ = 1;

  // If there are no longer any outstanding events on this <handle>
  // then we can totally shut down the Event_Handler.

  bool const has_any_wait_mask =
    (this->select_reactor_.wait_set_.rd_mask_.is_set (handle)
     || this->select_reactor_.wait_set_.wr_mask_.is_set (handle)
     || this->select_reactor_.wait_set_.ex_mask_.is_set (handle));
  bool const has_any_suspend_mask =
    (this->select_reactor_.suspend_set_.rd_mask_.is_set (handle)
     || this->select_reactor_.suspend_set_.wr_mask_.is_set (handle)
     || this->select_reactor_.suspend_set_.ex_mask_.is_set (handle));

  bool complete_removal = false;

  if (!has_any_wait_mask && !has_any_suspend_mask)
    {
#if defined (ACE_WIN32)
      if (event_handler != 0 && this->event_handlers_.unbind (pos) == -1)
        return -1;  // Should not happen!
#else
      this->event_handlers_[handle] = 0;

      if (this->max_handlep1_ == handle + 1)
        {
          // We've deleted the last entry, so we need to figure out
          // the last valid place in the array that is worth looking
          // at.
          ACE_HANDLE const wait_rd_max =
            this->select_reactor_.wait_set_.rd_mask_.max_set ();
          ACE_HANDLE const wait_wr_max =
            this->select_reactor_.wait_set_.wr_mask_.max_set ();
          ACE_HANDLE const wait_ex_max =
            this->select_reactor_.wait_set_.ex_mask_.max_set ();

          ACE_HANDLE const suspend_rd_max =
            this->select_reactor_.suspend_set_.rd_mask_.max_set ();
          ACE_HANDLE const suspend_wr_max =
            this->select_reactor_.suspend_set_.wr_mask_.max_set ();
          ACE_HANDLE const suspend_ex_max =
            this->select_reactor_.suspend_set_.ex_mask_.max_set ();

          // Compute the maximum of six values.
          this->max_handlep1_ = wait_rd_max;
          if (this->max_handlep1_ < wait_wr_max)
            this->max_handlep1_ = wait_wr_max;
          if (this->max_handlep1_ < wait_ex_max)
            this->max_handlep1_ = wait_ex_max;

          if (this->max_handlep1_ < suspend_rd_max)
            this->max_handlep1_ = suspend_rd_max;
          if (this->max_handlep1_ < suspend_wr_max)
            this->max_handlep1_ = suspend_wr_max;
          if (this->max_handlep1_ < suspend_ex_max)
            this->max_handlep1_ = suspend_ex_max;

          ++this->max_handlep1_;
        }

#endif /* ACE_WIN32 */

      // The handle has been completely removed.
      complete_removal = true;
    }

  if (event_handler == 0)
    return -1;

  bool const requires_reference_counting =
    event_handler->reference_counting_policy ().value () ==
    ACE_Event_Handler::Reference_Counting_Policy::ENABLED;

  // Close down the <Event_Handler> unless we've been instructed not
  // to.
  if (ACE_BIT_ENABLED (mask, ACE_Event_Handler::DONT_CALL) == 0)
    (void) event_handler->handle_close (handle, mask);

  // Call remove_reference() if the removal is complete and reference
  // counting is needed.
  if (complete_removal && requires_reference_counting)
    {
      (void) event_handler->remove_reference ();
    }

  return 0;
}

ACE_Select_Reactor_Handler_Repository_Iterator::ACE_Select_Reactor_Handler_Repository_Iterator
  (ACE_Select_Reactor_Handler_Repository const * s)
    : rep_ (s),
      current_ (s->event_handlers_.begin ())
{
#ifndef ACE_WIN32
  // Don't use ACE_Array_Base::end() since it may be larger than
  // event_handlers[max_handlep1_].
  const_base_iterator const end =
    &this->rep_->event_handlers_[this->rep_->max_handlep1 ()];

  // Advance to the next element containing a non-zero event handler.
  // There's no need to do this for the Windows case since the hash
  // map will only contain non-zero event handlers.
  while (this->current_ != end && (*(this->current_) == 0))
    ++this->current_;
#endif
}

// Pass back the <next_item> that hasn't been seen in the Set.
// Returns 0 when all items have been seen, else 1.

bool
ACE_Select_Reactor_Handler_Repository_Iterator::next (
  ACE_Event_Handler *&next_item)
{
  bool result = true;

  if (this->done ())
    result = false;
  else
    next_item = ACE_SELECT_REACTOR_EVENT_HANDLER (this->current_);

  return result;
}

// Move forward by one element in the set.

bool
ACE_Select_Reactor_Handler_Repository_Iterator::advance (void)
{
#ifdef ACE_WIN32
  // No need to explicitly limit search to "current" to
  // max_handlep1_ range.
  const_base_iterator const end = this->rep_->event_handlers_.end ();
#else
  // Don't use ACE_Array_Base::end() since it may be larger than
  // event_handlers[max_handlep1_].
  const_base_iterator const end =
    &this->rep_->event_handlers_[this->rep_->max_handlep1 ()];
#endif  /* ACE_WIN32 */

  if (this->current_ != end)
    ++this->current_;

#ifndef ACE_WIN32
  // Advance to the next element containing a non-zero event handler.
  // There's no need to do this for the Windows case since the hash
  // map will only contain non-zero event handlers.
  while (this->current_ != end && (*(this->current_) == 0))
    ++this->current_;
#endif  /* !ACE_WIN32 */

  return this->current_ != end;
}

// Dump the state of an object.

void
ACE_Select_Reactor_Handler_Repository_Iterator::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_Select_Reactor_Handler_Repository_Iterator::dump");

  ACE_DEBUG ((LM_DEBUG, ACE_BEGIN_DUMP, this));
  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("rep_ = %u"), this->rep_));
# ifdef ACE_WIN32
  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("current_ = ")));
  this->current_.dump ();
# else
  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("current_ = %@"), this->current_));
# endif  /* ACE_WIN32 */
  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
#endif /* ACE_HAS_DUMP */
}

void
ACE_Select_Reactor_Handler_Repository::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_Select_Reactor_Handler_Repository::dump");

# ifdef ACE_WIN32
#  define ACE_HANDLE_FORMAT_SPECIFIER ACE_TEXT("%@")
#  define ACE_MAX_HANDLEP1_FORMAT_SPECIFIER ACE_TEXT("%u")
# else
#  define ACE_HANDLE_FORMAT_SPECIFIER ACE_TEXT("%d")
#  define ACE_MAX_HANDLEP1_FORMAT_SPECIFIER ACE_TEXT("%d")
# endif  /* ACE_WIN32 */

  ACE_DEBUG ((LM_DEBUG, ACE_BEGIN_DUMP, this));
  ACE_DEBUG ((LM_DEBUG,
              ACE_TEXT ("max_handlep1_ = ")
              ACE_MAX_HANDLEP1_FORMAT_SPECIFIER
              ACE_TEXT ("\n"),
              this->max_handlep1 ()));
  ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("[")));

  ACE_Event_Handler *event_handler = 0;

  for (ACE_Select_Reactor_Handler_Repository_Iterator iter (this);
       iter.next (event_handler) != 0;
       iter.advance ())
    ACE_DEBUG ((LM_DEBUG,
                ACE_TEXT (" (event_handler = %@,")
                ACE_TEXT (" event_handler->handle_ = ")
                ACE_HANDLE_FORMAT_SPECIFIER
                ACE_TEXT ("\n"),
                event_handler,
                event_handler->get_handle ()));

  ACE_DEBUG ((LM_DEBUG, ACE_TEXT (" ]\n")));
  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
#endif /* ACE_HAS_DUMP */
}

ACE_ALLOC_HOOK_DEFINE(ACE_Select_Reactor_Handler_Repository_Iterator)

ACE_Select_Reactor_Notify::ACE_Select_Reactor_Notify (void)
  : max_notify_iterations_ (-1)
{
}

ACE_Select_Reactor_Notify::~ACE_Select_Reactor_Notify (void)
{
}

void
ACE_Select_Reactor_Notify::max_notify_iterations (int iterations)
{
  // Must always be > 0 or < 0 to optimize the loop exit condition.
  if (iterations == 0)
    iterations = 1;

  this->max_notify_iterations_ = iterations;
}

int
ACE_Select_Reactor_Notify::max_notify_iterations (void)
{
  return this->max_notify_iterations_;
}

// purge_pending_notifications
// Removes all entries from the notify_queue_ and each one that
// matches <eh> is put on the free_queue_. The rest are saved on a
// local queue and copied back to the notify_queue_ at the end.
// Returns the number of entries removed. Returns -1 on error.
// ACE_NOTSUP_RETURN if ACE_HAS_REACTOR_NOTIFICATION_QUEUE is not defined.
int
ACE_Select_Reactor_Notify::purge_pending_notifications (ACE_Event_Handler *eh,
                                                        ACE_Reactor_Mask  mask )
{
  ACE_TRACE ("ACE_Select_Reactor_Notify::purge_pending_notifications");

#if defined (ACE_HAS_REACTOR_NOTIFICATION_QUEUE)

  return notification_queue_.purge_pending_notifications(eh, mask);

#else /* defined (ACE_HAS_REACTOR_NOTIFICATION_QUEUE) */
  ACE_UNUSED_ARG (eh);
  ACE_UNUSED_ARG (mask);
  ACE_NOTSUP_RETURN (-1);
#endif  /* defined (ACE_HAS_REACTOR_NOTIFICATION_QUEUE) */
}

void
ACE_Select_Reactor_Notify::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_Select_Reactor_Notify::dump");

  ACE_DEBUG ((LM_DEBUG, ACE_BEGIN_DUMP, this));
  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("select_reactor_ = %x"), this->select_reactor_));
  this->notification_pipe_.dump ();
  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
#endif /* ACE_HAS_DUMP */
}

int
ACE_Select_Reactor_Notify::open (ACE_Reactor_Impl *r,
                                 ACE_Timer_Queue *,
                                 int disable_notify_pipe)
{
  ACE_TRACE ("ACE_Select_Reactor_Notify::open");

  if (disable_notify_pipe == 0)
    {
      this->select_reactor_ =
        dynamic_cast<ACE_Select_Reactor_Impl *> (r);

      if (select_reactor_ == 0)
        {
          errno = EINVAL;
          return -1;
        }

      if (this->notification_pipe_.open () == -1)
        return -1;
#if defined (F_SETFD)
      ACE_OS::fcntl (this->notification_pipe_.read_handle (), F_SETFD, 1);
      ACE_OS::fcntl (this->notification_pipe_.write_handle (), F_SETFD, 1);
#endif /* F_SETFD */

#if defined (ACE_HAS_REACTOR_NOTIFICATION_QUEUE)
      if (notification_queue_.open() == -1)
        {
          return -1;
        }
#endif /* ACE_HAS_REACTOR_NOTIFICATION_QUEUE */

      // There seems to be a Win32 bug with this...  Set this into
      // non-blocking mode.
      if (ACE::set_flags (this->notification_pipe_.read_handle (),
                          ACE_NONBLOCK) == -1)
        return -1;
      else
        return this->select_reactor_->register_handler
          (this->notification_pipe_.read_handle (),
           this,
           ACE_Event_Handler::READ_MASK);
    }
  else
    {
      this->select_reactor_ = 0;
      return 0;
    }
}

int
ACE_Select_Reactor_Notify::close (void)
{
  ACE_TRACE ("ACE_Select_Reactor_Notify::close");

#if defined (ACE_HAS_REACTOR_NOTIFICATION_QUEUE)
  notification_queue_.reset();
#else
  if (this->notification_pipe_.read_handle() != ACE_INVALID_HANDLE)
    {
      // Please see Bug 2820, if we just close the pipe then we break
      // the reference counting rules.  Basically, all the event
      // handlers "stored" in the pipe had their reference counts
      // increased.  We need to decrease them before closing the
      // pipe....
      ACE_Notification_Buffer b;
      for (int r = read_notify_pipe(notification_pipe_.read_handle(), b);
           r > 0;
           r = read_notify_pipe(notification_pipe_.read_handle(), b))
        {
          if (b.eh_ != 0)
            {
              b.eh_->remove_reference();
            }
        }
    }
#endif /* ACE_HAS_REACTOR_NOTIFICATION_QUEUE */

  return this->notification_pipe_.close ();
}

int
ACE_Select_Reactor_Notify::notify (ACE_Event_Handler *event_handler,
                                   ACE_Reactor_Mask mask,
                                   ACE_Time_Value *timeout)
{
  ACE_TRACE ("ACE_Select_Reactor_Notify::notify");

  // Just consider this method a "no-op" if there's no
  // <ACE_Select_Reactor> configured.
  if (this->select_reactor_ == 0)
    return 0;

  ACE_Event_Handler_var safe_handler (event_handler);

  if (event_handler)
    {
      event_handler->add_reference ();
    }

  ACE_Notification_Buffer buffer (event_handler, mask);

#if defined (ACE_HAS_REACTOR_NOTIFICATION_QUEUE)
  int const notification_required =
    notification_queue_.push_new_notification(buffer);

  if (notification_required == -1)
    {
      return -1;
    }

  if (notification_required == 0)
    {
      // No failures, the handler is now owned by the notification queue
      safe_handler.release ();

      return 0;
    }
#endif /* ACE_HAS_REACTOR_NOTIFICATION_QUEUE */

  ssize_t const n = ACE::send (this->notification_pipe_.write_handle (),
                               (char *) &buffer,
                               sizeof buffer,
                               timeout);
  if (n == -1)
    {
      return -1;
    }

  // No failures.
  safe_handler.release ();

  return 0;
}

// Handles pending threads (if any) that are waiting to unblock the
// Select_Reactor.

int
ACE_Select_Reactor_Notify::dispatch_notifications (int &number_of_active_handles,
                                                   ACE_Handle_Set &rd_mask)
{
  ACE_TRACE ("ACE_Select_Reactor_Notify::dispatch_notifications");

  ACE_HANDLE const read_handle =
    this->notification_pipe_.read_handle ();

  if (read_handle != ACE_INVALID_HANDLE
      && rd_mask.is_set (read_handle))
    {
      --number_of_active_handles;
      rd_mask.clr_bit (read_handle);
      return this->handle_input (read_handle);
    }
  else
    return 0;
}


ACE_HANDLE
ACE_Select_Reactor_Notify::notify_handle (void)
{
  ACE_TRACE ("ACE_Select_Reactor_Notify::notify_handle");

  return this->notification_pipe_.read_handle ();
}


int
ACE_Select_Reactor_Notify::is_dispatchable (ACE_Notification_Buffer &buffer)
{
#if defined (ACE_HAS_REACTOR_NOTIFICATION_QUEUE)
  ACE_UNUSED_ARG(buffer);
  return 1;
#else
  // If eh == 0 then another thread is unblocking the
  // <ACE_Select_Reactor> to update the <ACE_Select_Reactor>'s
  // internal structures.  Otherwise, we need to dispatch the
  // appropriate handle_* method on the <ACE_Event_Handler>
  // pointer we've been passed.
  if (buffer.eh_ != 0)
    {
      return 1;
    }
  else
    {
      // has no dispatchable buffer
      return 0;
    }
#endif /*ACE_HAS_REACTOR_NOTIFICATION_QUEUE */
}

int
ACE_Select_Reactor_Notify::dispatch_notify (ACE_Notification_Buffer &buffer)
{
  int result = 0;

#if defined (ACE_HAS_REACTOR_NOTIFICATION_QUEUE)
  // Dispatch one message from the notify queue, and put another in
  // the pipe if one is available.  Remember, the idea is to keep
  // exactly one message in the pipe at a time.

  bool more_messages_queued = false;
  ACE_Notification_Buffer next;

  result = notification_queue_.pop_next_notification(buffer,
                                                     more_messages_queued,
                                                     next);

  if (result == 0 || result == -1)
    {
      return result;
    }

  if(more_messages_queued)
    {
      (void) ACE::send(this->notification_pipe_.write_handle(),
            (char *)&next, sizeof(ACE_Notification_Buffer));
    }
#endif /* ACE_HAS_REACTOR_NOTIFICATION_QUEUE */

  // If eh == 0 then another thread is unblocking the
  // <ACE_Select_Reactor> to update the <ACE_Select_Reactor>'s
  // internal structures.  Otherwise, we need to dispatch the
  // appropriate handle_* method on the <ACE_Event_Handler> pointer
  // we've been passed.
  if (buffer.eh_ != 0)
    {
      ACE_Event_Handler *event_handler = buffer.eh_;

      bool const requires_reference_counting =
        event_handler->reference_counting_policy ().value () ==
        ACE_Event_Handler::Reference_Counting_Policy::ENABLED;

      switch (buffer.mask_)
        {
        case ACE_Event_Handler::READ_MASK:
        case ACE_Event_Handler::ACCEPT_MASK:
          result = event_handler->handle_input (ACE_INVALID_HANDLE);
          break;
        case ACE_Event_Handler::WRITE_MASK:
          result = event_handler->handle_output (ACE_INVALID_HANDLE);
          break;
        case ACE_Event_Handler::EXCEPT_MASK:
          result = event_handler->handle_exception (ACE_INVALID_HANDLE);
          break;
        case ACE_Event_Handler::QOS_MASK:
          result = event_handler->handle_qos (ACE_INVALID_HANDLE);
          break;
        case ACE_Event_Handler::GROUP_QOS_MASK:
          result = event_handler->handle_group_qos (ACE_INVALID_HANDLE);
          break;
        default:
          // Should we bail out if we get an invalid mask?
          ACE_ERROR ((LM_ERROR,
                      ACE_TEXT ("invalid mask = %d\n"),
                      buffer.mask_));
        }

      if (result == -1)
        event_handler->handle_close (ACE_INVALID_HANDLE,
                                     ACE_Event_Handler::EXCEPT_MASK);

      if (requires_reference_counting)
        {
          event_handler->remove_reference ();
        }
    }

  return 1;
}

int
ACE_Select_Reactor_Notify::read_notify_pipe (ACE_HANDLE handle,
                                             ACE_Notification_Buffer &buffer)
{
  ACE_TRACE ("ACE_Select_Reactor_Notify::read_notify_pipe");

  // This is kind of a weird, fragile beast.  We first read with a
  // regular read.  The read side of this socket is non-blocking, so
  // the read may end up being short.
  //
  // If the read is short, then we do a recv_n to insure that we block
  // and read the rest of the buffer.
  //
  // Now, you might be tempted to say, "why don't we just replace the
  // first recv with a recv_n?"  I was, too.  But that doesn't work
  // because of how the calling code in handle_input() works.  In
  // handle_input, the event will only be dispatched if the return
  // value from read_notify_pipe() is > 0.  That means that we can't
  // return zero from this func unless it's an EOF condition.
  //
  // Thus, the return value semantics for this are:
  // -1: nothing read, fatal, unrecoverable error
  // 0: nothing read at all
  // 1: complete buffer read

  ssize_t const n = ACE::recv (handle, (char *) &buffer, sizeof buffer);

  if (n > 0)
    {
      // Check to see if we've got a short read.
      if (n != sizeof buffer)
        {
          ssize_t const remainder = sizeof buffer - n;

          // If so, try to recover by reading the remainder.  If this
          // doesn't work we're in big trouble since the input stream
          // won't be aligned correctly.  I'm not sure quite what to
          // do at this point.  It's probably best just to return -1.
          if (ACE::recv_n (handle,
                           ((char *) &buffer) + n,
                           remainder) != remainder)
            return -1;
        }


      return 1;
    }

  // Return -1 if things have gone seriously  wrong.
  if (n <= 0 && (errno != EWOULDBLOCK && errno != EAGAIN))
    return -1;

  return 0;
}


int
ACE_Select_Reactor_Notify::handle_input (ACE_HANDLE handle)
{
  ACE_TRACE ("ACE_Select_Reactor_Notify::handle_input");
  // Precondition: this->select_reactor_.token_.current_owner () ==
  // ACE_Thread::self ();

  int number_dispatched = 0;
  int result = 0;
  ACE_Notification_Buffer buffer;

  // If there is only one buffer in the pipe, this will loop and call
  // read_notify_pipe() twice.  The first time will read the buffer, and
  // the second will read the fact that the pipe is empty.
  while ((result = this->read_notify_pipe (handle, buffer)) > 0)
    {
      // Dispatch the buffer
      // NOTE: We count only if we made any dispatches ie. upcalls.
      if (this->dispatch_notify (buffer) > 0)
        ++number_dispatched;

      // Bail out if we've reached the <notify_threshold_>.  Note that
      // by default <notify_threshold_> is -1, so we'll loop until all
      // the notifications in the pipe have been dispatched.
      if (number_dispatched == this->max_notify_iterations_)
        break;
    }

  // Reassign number_dispatched to -1 if things have gone seriously
  // wrong.
  if (result < 0)
    number_dispatched = -1;

  // Enqueue ourselves into the list of waiting threads.  When we
  // reacquire the token we'll be off and running again with ownership
  // of the token.  The postcondition of this call is that
  // <select_reactor_.token_.current_owner> == <ACE_Thread::self>.
  this->select_reactor_->renew ();
  return number_dispatched;
}

// -------------------------------------------

int
ACE_Select_Reactor_Impl::purge_pending_notifications (ACE_Event_Handler *eh,
                                                      ACE_Reactor_Mask mask)
{
  if (this->notify_handler_ == 0)
    return 0;
  else
    return this->notify_handler_->purge_pending_notifications (eh, mask);
}


// Perform GET, CLR, SET, and ADD operations on the Handle_Sets.
//
// GET = 1, Retrieve current value
// SET = 2, Set value of bits to new mask (changes the entire mask)
// ADD = 3, Bitwise "or" the value into the mask (only changes
//          enabled bits)
// CLR = 4  Bitwise "and" the negation of the value out of the mask
//          (only changes enabled bits)
//
// Returns the original mask.  Must be called with locks held.
int
ACE_Select_Reactor_Impl::bit_ops (ACE_HANDLE handle,
                                  ACE_Reactor_Mask mask,
                                  ACE_Select_Reactor_Handle_Set &handle_set,
                                  int ops)
{
  ACE_TRACE ("ACE_Select_Reactor_Impl::bit_ops");
  if (this->handler_rep_.handle_in_range (handle) == 0)
    return -1;

#if !defined (ACE_WIN32)
  ACE_Sig_Guard sb (0,
                    this->mask_signals_); // Block out all signals until method returns.
#endif /* ACE_WIN32 */

  ACE_FDS_PTMF ptmf  = &ACE_Handle_Set::set_bit;
  u_long omask = ACE_Event_Handler::NULL_MASK;

  // Find the old reactor masks.  This automatically does the work of
  // the GET_MASK operation.
  if (handle_set.rd_mask_.is_set (handle))
    ACE_SET_BITS (omask, ACE_Event_Handler::READ_MASK);
  if (handle_set.wr_mask_.is_set (handle))
    ACE_SET_BITS (omask, ACE_Event_Handler::WRITE_MASK);
  if (handle_set.ex_mask_.is_set (handle))
    ACE_SET_BITS (omask, ACE_Event_Handler::EXCEPT_MASK);

  switch (ops)
    {
    case ACE_Reactor::GET_MASK:
      // The work for this operation is done in all cases at the
      // begining of the function.
      break;
    case ACE_Reactor::CLR_MASK:
      ptmf = &ACE_Handle_Set::clr_bit;
      // State was changed. we need to reflect that change in the
      // dispatch_mask I assume that only ACE_Reactor::CLR_MASK should
      // be treated here  which means we need to clear the handle|mask
      // from the current dispatch handler
      this->clear_dispatch_mask (handle, mask);
      /* FALLTHRU */
    case ACE_Reactor::SET_MASK:
      /* FALLTHRU */
    case ACE_Reactor::ADD_MASK:

      // The following code is rather subtle...  Note that if we are
      // doing a ACE_Reactor::SET_MASK then if the bit is not enabled
      // in the mask we need to clear the bit from the ACE_Handle_Set.
      // On the other hand, if we are doing a ACE_Reactor::CLR_MASK or
      // a ACE_Reactor::ADD_MASK we just carry out the operations
      // specified by the mask.

      // READ, ACCEPT, and CONNECT flag will place the handle in the
      // read set.
      if (ACE_BIT_ENABLED (mask, ACE_Event_Handler::READ_MASK)
          || ACE_BIT_ENABLED (mask, ACE_Event_Handler::ACCEPT_MASK)
          || ACE_BIT_ENABLED (mask, ACE_Event_Handler::CONNECT_MASK))
        {
          (handle_set.rd_mask_.*ptmf) (handle);
        }
      else if (ops == ACE_Reactor::SET_MASK)
        handle_set.rd_mask_.clr_bit (handle);

      // WRITE and CONNECT flag will place the handle in the write set
      if (ACE_BIT_ENABLED (mask,
                           ACE_Event_Handler::WRITE_MASK)
          || ACE_BIT_ENABLED (mask,
                              ACE_Event_Handler::CONNECT_MASK))
        {
          (handle_set.wr_mask_.*ptmf) (handle);
        }
      else if (ops == ACE_Reactor::SET_MASK)
        handle_set.wr_mask_.clr_bit (handle);

      // EXCEPT (and CONNECT on Win32) flag will place the handle in
      // the except set.
      if (ACE_BIT_ENABLED (mask, ACE_Event_Handler::EXCEPT_MASK)
#if defined (ACE_WIN32)
          || ACE_BIT_ENABLED (mask, ACE_Event_Handler::CONNECT_MASK)
#endif /* ACE_WIN32 */
          )
        {
          (handle_set.ex_mask_.*ptmf) (handle);
        }
      else if (ops == ACE_Reactor::SET_MASK)
        handle_set.ex_mask_.clr_bit (handle);
      break;
    default:
      return -1;
    }
  return omask;
}

void
ACE_Select_Reactor_Impl::clear_dispatch_mask (ACE_HANDLE handle,
                                              ACE_Reactor_Mask mask)
{
  ACE_TRACE ("ACE_Select_Reactor_Impl::clear_dispatch_mask");

  //  Use handle and mask in order to modify the sets
  // (wait/suspend/ready/dispatch), that way, the dispatch_io_set loop
  // will not be interrupt, and there will no reason to rescan the
  // wait_set and re-calling select function, which is *very*
  // expensive. It seems that wait/suspend/ready sets are getting
  // updated in register/remove bind/unbind etc functions.  The only
  // thing need to be updated is the dispatch_set (also can  be found
  // in that file code as dispatch_mask).  Because of that, we need
  // that dispatch_set to be member of the ACE_Select_Reactor_impl in
  // Select_Reactor_Base.h file  That way we will have access to that
  // member in that function.

  // We kind of invalidate the iterator in dispatch_io_set because its
  // an array and index built from the original dispatch-set. Take a
  // look at dispatch_io_set for more details.

  // We only need to clr_bit, because we are interested in clearing the
  // handles that was removed, so no dispatching to these handles will
  // occur.
  if (ACE_BIT_ENABLED (mask, ACE_Event_Handler::READ_MASK) ||
      ACE_BIT_ENABLED (mask, ACE_Event_Handler::ACCEPT_MASK))
    {
      this->dispatch_set_.rd_mask_.clr_bit (handle);
    }
  if (ACE_BIT_ENABLED (mask, ACE_Event_Handler::WRITE_MASK))
    {
      this->dispatch_set_.wr_mask_.clr_bit (handle);
    }
  if (ACE_BIT_ENABLED (mask, ACE_Event_Handler::EXCEPT_MASK))
    {
      this->dispatch_set_.ex_mask_.clr_bit (handle);
    }

  // That will make the dispatch_io_set iterator re-start and rescan
  // the dispatch set.
  this->state_changed_ = true;
}


int
ACE_Select_Reactor_Impl::resumable_handler (void)
{
  // The select reactor has no handlers that can be resumed by the
  // application. So return 0;

  return 0;
}

ACE_END_VERSIONED_NAMESPACE_DECL
