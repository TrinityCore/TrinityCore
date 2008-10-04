// $Id: Timeprobe_T.cpp 80826 2008-03-04 14:51:23Z wotte $

#ifndef ACE_TIMEPROBE_T_CPP
#define ACE_TIMEPROBE_T_CPP

#include "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if defined (ACE_COMPILE_TIMEPROBES)

#include "ace/Timeprobe.h"
#include "ace/High_Res_Timer.h"
#include "ace/OS_NS_string.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

template <class ACE_LOCK, class ALLOCATOR>
ACE_Timeprobe_Ex<ACE_LOCK, ALLOCATOR>::ACE_Timeprobe_Ex (u_long size)
  : timeprobes_ (0),
    lock_ (),
    max_size_ (size),
    current_size_ (0),
    report_buffer_full_ (0),
    allocator_ (0)
{
  ACE_timeprobe_t *temp;
  //FUZZ: disable check_for_lack_ACE_OS
  ACE_NEW_MALLOC_ARRAY (temp,
                        (ACE_timeprobe_t *) this->allocator ()->
                        malloc (this->max_size_*sizeof(ACE_timeprobe_t)),
                        ACE_timeprobe_t,
                        this->max_size_);
  //FUZZ: enable check_for_lack_ACE_OS
  this->timeprobes_ = temp;

}

template <class ACE_LOCK, class ALLOCATOR>
ACE_Timeprobe_Ex<ACE_LOCK, ALLOCATOR>::
ACE_Timeprobe_Ex (ALLOCATOR *allocator,
               u_long size)
  : timeprobes_ (0),
    lock_ (),
    max_size_ (size),
    current_size_ (0),
    report_buffer_full_ (0),
    allocator_ (allocator)
{
  ACE_timeprobe_t *temp = 0;
  //FUZZ: disable check_for_lack_ACE_OS
  ACE_NEW_MALLOC_ARRAY (temp,
                        (ACE_timeprobe_t *) this->allocator ()->
                        malloc (this->max_size_*sizeof(ACE_timeprobe_t)),
                        ACE_timeprobe_t,
                        this->max_size_);
  //FUZZ: enable check_for_lack_ACE_OS
  this->timeprobes_ = temp;

}

template <class ACE_LOCK, class ALLOCATOR>
ACE_Timeprobe_Ex<ACE_LOCK, ALLOCATOR>::ACE_Timeprobe_Ex (const ACE_Timeprobe_Ex<ACE_LOCK, ALLOCATOR> &)
{
  //
  // Stupid MSVC is forcing me to define this; please don't use it.
  //

  ACE_ERROR ((LM_ERROR,
              ACE_TEXT ("ACE_NOTSUP: %N, line %l\n")));
  errno = ENOTSUP;
}

template <class ACE_LOCK, class ALLOCATOR>
ACE_Timeprobe_Ex<ACE_LOCK, ALLOCATOR>::~ACE_Timeprobe_Ex (void)
{
  ACE_DES_ARRAY_FREE ((ACE_timeprobe_t *) (this->timeprobes_),
                      this->max_size_,
                      this->allocator ()->free,
                      ACE_timeprobe_t);
}

template <class ACE_LOCK, class ALLOCATOR> void
ACE_Timeprobe_Ex<ACE_LOCK, ALLOCATOR>::timeprobe (u_long event)
{
  ACE_GUARD (ACE_LOCK, ace_mon, this->lock_);

  this->timeprobes_[this->current_size_].event_.event_number_ = event;
  this->timeprobes_[this->current_size_].event_type_ = ACE_timeprobe_t::NUMBER;
  this->timeprobes_[this->current_size_].time_ = ACE_OS::gethrtime ();
  this->timeprobes_[this->current_size_].thread_ = ACE_OS::thr_self ();

  ++this->current_size_;

#if !defined (ACE_TIMEPROBE_ASSERTS_FIXED_SIZE)
  // wrap around to the beginning on overflow
  if (this->current_size_ >= this->max_size_)
    {
      this->current_size_ = 0;
      this->report_buffer_full_ = 1;
    }
#endif /* ACE_TIMEPROBE_ASSERTS_FIXED_SIZE */

  ACE_ASSERT (this->current_size_ < this->max_size_);
}

template <class ACE_LOCK, class ALLOCATOR> void
ACE_Timeprobe_Ex<ACE_LOCK, ALLOCATOR>::timeprobe (const char *event)
{
  ACE_GUARD (ACE_LOCK, ace_mon, this->lock_);

  this->timeprobes_[this->current_size_].event_.event_description_ = event;
  this->timeprobes_[this->current_size_].event_type_ = ACE_timeprobe_t::STRING;
  this->timeprobes_[this->current_size_].time_ = ACE_OS::gethrtime ();
  this->timeprobes_[this->current_size_].thread_ = ACE_OS::thr_self ();

  ++this->current_size_;

#if !defined (ACE_TIMEPROBE_ASSERTS_FIXED_SIZE)
  // wrap around to the beginning on overflow
  if (this->current_size_ >= this->max_size_)
    {
      this->current_size_ = 0;
      this->report_buffer_full_ = 1;
    }
#endif /* ACE_TIMEPROBE_ASSERTS_FIXED_SIZE */

  ACE_ASSERT (this->current_size_ < this->max_size_);
}

template <class ACE_LOCK, class ALLOCATOR> void
ACE_Timeprobe_Ex<ACE_LOCK, ALLOCATOR>::reset (void)
{
  ACE_GUARD (ACE_LOCK, ace_mon, this->lock_);

  this->current_size_ = 0;
  this->report_buffer_full_ = 0;
}

template <class ACE_LOCK, class ALLOCATOR> void
ACE_Timeprobe_Ex<ACE_LOCK, ALLOCATOR>::increase_size (u_long size)
{
  ACE_GUARD (ACE_LOCK, ace_mon, this->lock_);

  if (size > this->max_size_)
    {
      ACE_timeprobe_t *temp = 0;
      //FUZZ: disable check_for_lack_ACE_OS
      ACE_NEW_MALLOC_ARRAY (temp,
                            (ACE_timeprobe_t *) this->allocator ()->
                            malloc (this->max_size_
                                    * sizeof (ACE_timeprobe_t)),
                            ACE_timeprobe_t,
                            size);
      //FUZZ: enable check_for_lack_ACE_OS

      if (this->max_size_ > 0)
        {
          ACE_OS::memcpy (temp,
                          this->timeprobes_,
                          this->max_size_ * sizeof (ACE_timeprobe_t));

          // Iterates over the array explicitly calling the destructor for
          // each probe instance, then deallocates the memory

          ACE_DES_ARRAY_FREE ((ACE_timeprobe_t *)(this->timeprobes_),
                              this->max_size_,
                              this->allocator ()->free,
                              ACE_timeprobe_t);
        }
      this->timeprobes_ = temp;
      this->max_size_ = size;
    }
}

template <class ACE_LOCK, class ALLOCATOR> ACE_Unbounded_Set<ACE_Event_Descriptions> &
ACE_Timeprobe_Ex<ACE_LOCK, ALLOCATOR>::event_descriptions (void)
{
  return this->event_descriptions_;
}

template <class ACE_LOCK, class ALLOCATOR> ACE_Unbounded_Set<ACE_Event_Descriptions> &
ACE_Timeprobe_Ex<ACE_LOCK, ALLOCATOR>::sorted_event_descriptions (void)
{
  return this->sorted_event_descriptions_;
}

template <class ACE_LOCK, class ALLOCATOR> ACE_timeprobe_t *
ACE_Timeprobe_Ex<ACE_LOCK, ALLOCATOR>::timeprobes (void)
{
  return this->timeprobes_;
}

template <class ACE_LOCK, class ALLOCATOR> ACE_LOCK &
ACE_Timeprobe_Ex<ACE_LOCK, ALLOCATOR>::lock (void)
{
  return this->lock_;
}

template <class ACE_LOCK, class ALLOCATOR> u_long
ACE_Timeprobe_Ex<ACE_LOCK, ALLOCATOR>::max_size (void)
{
  return this->max_size_;
}

template <class ACE_LOCK, class ALLOCATOR> u_long
ACE_Timeprobe_Ex<ACE_LOCK, ALLOCATOR>::current_size (void)
{
  return this->current_size_;
}

template <class ACE_LOCK, class ALLOCATOR> int
ACE_Timeprobe_Ex<ACE_LOCK, ALLOCATOR>::event_descriptions (const char **descriptions,
                                             u_long minimum_id)
{
  ACE_GUARD_RETURN (ACE_LOCK, ace_mon, this->lock_, -1);

  ACE_Event_Descriptions events;
  events.descriptions_ = descriptions;
  events.minimum_id_ = minimum_id;

  this->event_descriptions_.insert (events);

  return 0;
}

template <class ACE_LOCK, class ALLOCATOR> void
ACE_Timeprobe_Ex<ACE_LOCK, ALLOCATOR>::print_times (void)
{
  ACE_GUARD (ACE_LOCK, ace_mon, this->lock_);

  // Sort the event descriptions
  this->sort_event_descriptions_i ();

  u_long size = this->report_buffer_full_ ? this->max_size_
                                          : this->current_size_;

  ACE_DEBUG ((LM_DEBUG,
              "\nACE_Timeprobe_Ex; %u timestamps were recorded:\n",
              size));

  if (size == 0)
    return;

  ACE_DEBUG ((LM_DEBUG,
              "\n%-50.50s %8.8s %13.13s\n\n",
              "Event",
              "thread",
              "usec"));

  double gsf = ACE_High_Res_Timer::global_scale_factor ();
  u_long i, j;

  // First element
  i = this->report_buffer_full_ ? this->current_size_ : 0;

  ACE_DEBUG ((LM_DEBUG,
              "%-50.50s %8.8x %13.13s\n",
              this->find_description_i (i),
              this->timeprobes_[i].thread_,
              "START"));

  if (size == 1)
    return;

  bool has_timestamp_inversion = false;

  j = i;
  i = (i + 1) % this->max_size_;

  do
    {
      // When reusing the same ACE_Timeprobe from multiple threads
      // with Linux on Intel SMP, it sometimes happens that the
      // recorded times go backward in time if they are recorded from
      // different threads (see bugzilla #2342).  To obtain the
      // correct signed difference between consecutive recorded times,
      // one has to cast the time difference to an intermediate signed
      // integral type of the same size as ACE_hrtime_t.

      double time_difference =
        (ACE_INT64) (this->timeprobes_[i].time_ - this->timeprobes_[j].time_);

      if (time_difference < 0)
        has_timestamp_inversion = true;

      // Convert to microseconds.
      time_difference /= gsf;

      ACE_DEBUG ((LM_DEBUG,
                  "%-50.50s %8.8x %14.3f\n",
                  this->find_description_i (i),
                  this->timeprobes_[i].thread_,
                  time_difference));

      j = i;
      i = (i + 1) % this->max_size_;
    }
  while (i != this->current_size_);

  static bool inversion_warning_printed = false;
  if (!inversion_warning_printed && has_timestamp_inversion)
    {
      inversion_warning_printed = true;
      ACE_DEBUG ((LM_DEBUG,
                  "\nWARNING: The timestamps recorded by gethrtime() on"
                  " this platform are\n"
                  "not monotonic across different threads.\n"));
    }
}

template <class ACE_LOCK, class ALLOCATOR> void
ACE_Timeprobe_Ex<ACE_LOCK, ALLOCATOR>::print_absolute_times (void)
{
  ACE_GUARD (ACE_LOCK, ace_mon, this->lock_);

  // Sort the event descriptions
  this->sort_event_descriptions_i ();

  u_long size = this->report_buffer_full_ ? this->max_size_
                                          : this->current_size_;

  ACE_DEBUG ((LM_DEBUG,
              "\nACE_Timeprobe_Ex; %u timestamps were recorded:\n",
              size));

  if (size == 0)
    return;

  ACE_DEBUG ((LM_DEBUG,
              "\n%-50.50s %8.8s %13.13s\n\n",
              "Event",
              "thread",
              "stamp"));

  u_long i = this->report_buffer_full_ ? this->current_size_ : 0;

  ACE_Time_Value tv; // to convert ACE_hrtime_t
  do
    {
      ACE_High_Res_Timer::hrtime_to_tv (tv, this->timeprobes_ [i].time_);

      ACE_DEBUG ((LM_DEBUG,
                  "%-50.50s %8.8x %12.12u\n",
                  this->find_description_i (i),
                  this->timeprobes_ [i].thread_,
                  tv.sec () * 1000000
                   + tv.usec ()));

      // Modulus increment: loops around at the end.
      i = (i + 1) % this->max_size_;
    }
  while (i != this->current_size_);
}

template <class ACE_LOCK, class ALLOCATOR> const char *
ACE_Timeprobe_Ex<ACE_LOCK, ALLOCATOR>::find_description_i (u_long i)
{
  if (this->timeprobes_[i].event_type_ == ACE_timeprobe_t::STRING)
    return this->timeprobes_[i].event_.event_description_;
  else
    {
      EVENT_DESCRIPTIONS::iterator iterator = this->sorted_event_descriptions_.begin ();
      for (u_long j = 0;
           j < this->sorted_event_descriptions_.size () - 1;
           iterator++, j++)
        {
          EVENT_DESCRIPTIONS::iterator next_event_descriptions = iterator;
          ++next_event_descriptions;

          if (this->timeprobes_[i].event_.event_number_ < (*next_event_descriptions).minimum_id_)
            break;
        }
      return (*iterator).descriptions_[this->timeprobes_[i].event_.event_number_ - (*iterator).minimum_id_];
    }
}

template <class ACE_LOCK, class ALLOCATOR> void
ACE_Timeprobe_Ex<ACE_LOCK, ALLOCATOR>::sort_event_descriptions_i (void)
{
  size_t total_elements = this->event_descriptions_.size ();

  for (size_t i = 0;
       i < total_elements;
       i++)
    {
      EVENT_DESCRIPTIONS::iterator iterator = this->event_descriptions_.begin ();
      ACE_Event_Descriptions min_entry = *iterator;

      for (;
           iterator != this->event_descriptions_.end ();
           iterator++)
        if ((*iterator).minimum_id_ < min_entry.minimum_id_)
          min_entry = *iterator;

      this->sorted_event_descriptions_.insert (min_entry);
      this->event_descriptions_.remove (min_entry);
    }
}

template <class ACE_LOCK, class ALLOCATOR> ALLOCATOR *
ACE_Timeprobe_Ex<ACE_LOCK, ALLOCATOR>::allocator (void)
{
  return allocator_ ? allocator_ : ACE_Singleton<ALLOCATOR, ACE_LOCK>::instance ();
}

template <class Timeprobe>
ACE_Function_Timeprobe<Timeprobe>::ACE_Function_Timeprobe (Timeprobe &timeprobe,
                                                           u_long event)
  : timeprobe_ (timeprobe),
    event_ (event)
{
  this->timeprobe_.timeprobe (this->event_);
}

template <class Timeprobe>
ACE_Function_Timeprobe<Timeprobe>::~ACE_Function_Timeprobe (void)
{
  this->timeprobe_.timeprobe (this->event_ + 1);
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_COMPILE_TIMEPROBES */
#endif /* ACE_TIMEPROBE_T_CPP */
