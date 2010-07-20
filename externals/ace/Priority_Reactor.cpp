// $Id: Priority_Reactor.cpp 82723 2008-09-16 09:35:44Z johnnyw $

#include "ace/Priority_Reactor.h"
#include "ace/Malloc_T.h"

ACE_RCSID(ace, Priority_Reactor, "$Id: Priority_Reactor.cpp 82723 2008-09-16 09:35:44Z johnnyw $")

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

typedef ACE_Unbounded_Queue_Iterator<ACE_Event_Tuple> QUEUE_ITERATOR;
// Its iterator.

typedef ACE_Cached_Allocator<ACE_Node<ACE_Event_Tuple>, ACE_SYNCH_NULL_MUTEX> TUPLE_ALLOCATOR;
// Defines the memory allocator used, no need for locking because it
// is only used in one thread of control.

ACE_ALLOC_HOOK_DEFINE(ACE_Priority_Reactor)

// Initialize ACE_Select_Reactor.

#define npriorities \
        ACE_Event_Handler::HI_PRIORITY-ACE_Event_Handler::LO_PRIORITY+1

void
ACE_Priority_Reactor::init_bucket (void)
{
  // Allocate enough space for all the handles.
  // TODO: This can be wrong, maybe we should use other kind of
  // allocator here?
  ACE_NEW (this->tuple_allocator_,
           TUPLE_ALLOCATOR (ACE_Select_Reactor::DEFAULT_SIZE));

  // The event handlers are assigned to a new As the Event
  ACE_NEW (this->bucket_,
           QUEUE *[npriorities]);

  // This loops "ensures" exception safety.
  for (int i = 0; i < npriorities; ++i)
    ACE_NEW (this->bucket_[i],
             QUEUE (this->tuple_allocator_));
}

ACE_Priority_Reactor::ACE_Priority_Reactor (ACE_Sig_Handler *sh,
                                            ACE_Timer_Queue *tq)
  : ACE_Select_Reactor(sh, tq),
    bucket_ (0),
    tuple_allocator_ (0)
{
  ACE_TRACE ("ACE_Priority_Reactor::ACE_Priority_Reactor");
  this->init_bucket ();
}

ACE_Priority_Reactor::ACE_Priority_Reactor (size_t size,
                                            bool restart,
                                            ACE_Sig_Handler *sh,
                                            ACE_Timer_Queue *tq)
  : ACE_Select_Reactor (size, restart, sh, tq),
    bucket_ (0),
    tuple_allocator_ (0)
{
  ACE_TRACE ("ACE_Priority_Reactor::ACE_Priority_Reactor");
  this->init_bucket ();
}

ACE_Priority_Reactor::~ACE_Priority_Reactor (void)
{
  ACE_TRACE ("ACE_Priority_Reactor::~ACE_Priority_Reactor");

  for (int i = 0; i < npriorities; ++i)
    delete this->bucket_[i];

  delete[] this->bucket_;
  delete tuple_allocator_;
}

int
ACE_Priority_Reactor::build_bucket (ACE_Handle_Set &dispatch_mask,
                                    int &min_priority,
                                    int &max_priority)
{
  ACE_Handle_Set_Iterator handle_iter (dispatch_mask);

  for (ACE_HANDLE handle;
       (handle = handle_iter ()) != ACE_INVALID_HANDLE;
       )
    {
      ACE_Event_Handler *event_handler =
        this->handler_rep_.find (handle);
      if (event_handler == 0)
        return -1;

      ACE_Event_Tuple et (event_handler,
                          handle);
      int prio = et.event_handler_->priority ();

      // If the priority is out of range assign the minimum priority.
      if (prio < ACE_Event_Handler::LO_PRIORITY
          || prio > ACE_Event_Handler::HI_PRIORITY)
        prio = ACE_Event_Handler::LO_PRIORITY;

      if (bucket_[prio]->enqueue_tail (et) == -1)
        return -1;

      // Update the priority ranges....
      if (min_priority > prio)
        min_priority = prio;
      if (max_priority < prio)
        max_priority = prio;
    }

  return 0;
}

int
ACE_Priority_Reactor::dispatch_io_set (int number_of_active_handles,
                                       int& number_dispatched,
                                       int mask,
                                       ACE_Handle_Set& dispatch_mask,
                                       ACE_Handle_Set& ready_mask,
                                       ACE_EH_PTMF callback)
{
  ACE_TRACE ("ACE_Priority_Reactor::dispatch_io_set");

  if (number_of_active_handles == 0)
    return 0;

  // The range for which there exists any Event_Tuple is computed on
  // the ordering loop, minimizing iterations on the dispatching loop.
  int min_priority =
    ACE_Event_Handler::HI_PRIORITY;
  int max_priority =
    ACE_Event_Handler::LO_PRIORITY;

  if (this->build_bucket (dispatch_mask,
                          min_priority,
                          max_priority) == -1)
    return -1;

  for (int i = max_priority; i >= min_priority; --i)
    {
      while (!bucket_[i]->is_empty ()
             && number_dispatched < number_of_active_handles)
        {

          ACE_Event_Tuple et;

          bucket_[i]->dequeue_head (et);

          this->notify_handle (et.handle_,
                               mask,
                               ready_mask,
                               et.event_handler_,
                               callback);
          number_dispatched++;

          // clear the bit from that dispatch mask,
          // so when we need to restart the iteration (rebuilding the iterator...)
          // we will not dispatch the already dipatched handlers
          this->clear_dispatch_mask (et.handle_,
                                     mask);

          if (this->state_changed_)
            this->state_changed_ = false; // so it will not rebuild it ...
        }

      // Even if we are aborting the loop due to this->state_changed
      // or another error we still want to cleanup the buckets.
      bucket_[i]->reset ();
    }

  return 0;
}

void
ACE_Priority_Reactor::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_Priority_Reactor::dump");

  ACE_DEBUG ((LM_DEBUG, ACE_BEGIN_DUMP, this));

  ACE_Select_Reactor::dump ();

  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
#endif /* ACE_HAS_DUMP */
}

ACE_END_VERSIONED_NAMESPACE_DECL
