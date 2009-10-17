// -*- C++ -*-
//
// $Id: Metrics_Cache_T.inl 80826 2008-03-04 14:51:23Z wotte $

#ifndef ACE_METRICS_CACHE_T_INL
#define ACE_METRICS_CACHE_T_INL

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/////////////////////////////
// Class ACE_Metrics_Cache //
/////////////////////////////


template <class ACE_LOCK, class ALLOCATOR>
ACE_INLINE void
ACE_Metrics_Cache<ACE_LOCK, ALLOCATOR>::report_enqueue_start (u_long i)
{
  if (i < this->probe_set_size_)
    {
      u_long & count =
        this->enqueue_count_ [this->supplier_index_] [i];
      ++count;

      if (! this->interval_initialized_)
        {
          this->interval_initialized_ = 1;
          ACE_hrtime_t hrtime_now = ACE_OS::gethrtime ();
          ACE_High_Res_Timer::hrtime_to_tv (this->interval_start_,
                                                    hrtime_now);
          this->interval_end_.set (this->interval_start_.sec(),
                                   this->interval_start_.usec());
        }

      // Take the metrics timeprobe last, to avoid measuring the above
      // metrics processing.
      ACE_Metrics_Timeprobe<ACE_LOCK, ALLOCATOR> * probe =
        this->enqueue_probes_ [this->supplier_index_][i];
      probe->
        timeprobe (ACE_Metrics_Timeprobe<ACE_LOCK, ALLOCATOR>::WORK_START);
    }
}


template <class ACE_LOCK, class ALLOCATOR>
ACE_INLINE void
ACE_Metrics_Cache<ACE_LOCK, ALLOCATOR>::report_enqueue_stop (u_long i)
{
  if (i < this->probe_set_size_)
    {
      // Take the metrics timeprobe first, to avoid measuring the below
      // metrics processing.
      ACE_Metrics_Timeprobe<ACE_LOCK, ALLOCATOR> * probe =
        this->enqueue_probes_ [this->supplier_index_][i];
      probe->
        timeprobe (ACE_Metrics_Timeprobe<ACE_LOCK, ALLOCATOR>::WORK_STOP);

      ACE_hrtime_t hrtime_now = ACE_OS::gethrtime ();
      ACE_High_Res_Timer::hrtime_to_tv (this->interval_end_,
                                            hrtime_now);

      u_long & count = enqueue_count_ [this->supplier_index_][i];
      ++count;
    }

}


template <class ACE_LOCK, class ALLOCATOR>
ACE_INLINE void
ACE_Metrics_Cache<ACE_LOCK, ALLOCATOR>::report_enqueue_suspend (u_long i)
{
  if (i < this->probe_set_size_)
    {
      ACE_Metrics_Timeprobe<ACE_LOCK, ALLOCATOR> * probe =
        this->enqueue_probes_ [this->supplier_index_][i];
      probe->
        timeprobe (ACE_Metrics_Timeprobe<ACE_LOCK, ALLOCATOR>::WORK_SUSPEND);
      u_long & count =
        this->enqueue_count_ [this->supplier_index_] [i];
      ++count;
    }
}


template <class ACE_LOCK, class ALLOCATOR>
ACE_INLINE void
ACE_Metrics_Cache<ACE_LOCK, ALLOCATOR>::report_enqueue_resume (u_long i)
{
  if (i < this->probe_set_size_)
    {
      u_long & count =
        this->enqueue_count_ [this->supplier_index_] [i];
      ++count;
      ACE_Metrics_Timeprobe<ACE_LOCK, ALLOCATOR> * probe =
        this->enqueue_probes_ [this->supplier_index_][i];
      probe->
        timeprobe (ACE_Metrics_Timeprobe<ACE_LOCK, ALLOCATOR>::WORK_RESUME);
    }
}


template <class ACE_LOCK, class ALLOCATOR>
ACE_INLINE void
ACE_Metrics_Cache<ACE_LOCK, ALLOCATOR>::report_dequeue_start (u_long i)
{
  if (i < this->probe_set_size_)
    {
      u_long & count =
        this->dequeue_count_ [this->supplier_index_] [i];
      ++count;

      if (! this->interval_initialized_)
        {
          this->interval_initialized_ = 1;
          ACE_hrtime_t hrtime_now = ACE_OS::gethrtime ();
          ACE_High_Res_Timer::hrtime_to_tv (this->interval_start_,
                                                    hrtime_now);
          this->interval_end_.set (this->interval_start_.sec(),
                                   this->interval_start_.usec());
        }

      // Take the metrics timeprobe last, to avoid measuring the above
      // metrics processing.
      ACE_Metrics_Timeprobe<ACE_LOCK, ALLOCATOR> * probe =
        this->dequeue_probes_ [this->supplier_index_][i];
      probe->
        timeprobe (ACE_Metrics_Timeprobe<ACE_LOCK, ALLOCATOR>::WORK_START);
    }
}


template <class ACE_LOCK, class ALLOCATOR>
ACE_INLINE void
ACE_Metrics_Cache<ACE_LOCK, ALLOCATOR>::report_dequeue_stop (u_long i)
{
  if (i < this->probe_set_size_)
    {
      // Take the metrics timeprobe first, to avoid measuring the
      // metrics processing below.
      ACE_Metrics_Timeprobe<ACE_LOCK, ALLOCATOR> * probe =
        this->dequeue_probes_ [this->supplier_index_][i];

      probe->timeprobe (ACE_Metrics_Timeprobe<ACE_LOCK, ALLOCATOR>::WORK_STOP);

      ACE_hrtime_t hrtime_now = ACE_OS::gethrtime ();
      ACE_High_Res_Timer::hrtime_to_tv (this->interval_end_,
                                                    hrtime_now);

      u_long & count = dequeue_count_ [this->supplier_index_] [i];
      ++count;
    }
}


template <class ACE_LOCK, class ALLOCATOR>
ACE_INLINE void
ACE_Metrics_Cache<ACE_LOCK, ALLOCATOR>::report_dequeue_suspend (u_long i)
{
  if (i < this->probe_set_size_)
    {
      u_long & count =
        this->dequeue_count_ [this->supplier_index_] [i];
      ++count;
      ACE_Metrics_Timeprobe<ACE_LOCK, ALLOCATOR> * probe =
        this->dequeue_probes_ [this->supplier_index_][i];
      probe->
        timeprobe (ACE_Metrics_Timeprobe<ACE_LOCK, ALLOCATOR>::WORK_SUSPEND);
    }
}


template <class ACE_LOCK, class ALLOCATOR>
ACE_INLINE void
ACE_Metrics_Cache<ACE_LOCK, ALLOCATOR>::report_dequeue_resume (u_long i)
{
  if (i < this->probe_set_size_)
    {
      u_long & count =
        this->dequeue_count_ [this->supplier_index_] [i];
      ++count;
      ACE_Metrics_Timeprobe<ACE_LOCK, ALLOCATOR> * probe =
        this->dequeue_probes_ [this->supplier_index_][i];
      probe->
        timeprobe (ACE_Metrics_Timeprobe<ACE_LOCK, ALLOCATOR>::WORK_RESUME);
    }
}


template <class ACE_LOCK, class ALLOCATOR>
ACE_INLINE void
ACE_Metrics_Cache<ACE_LOCK, ALLOCATOR>::reset_base_statistics ()
{
  this->interval_initialized_ = 0;
  this->interval_start_.set (0, 0);
  this->interval_end_.set (0, 0);

  for (u_int i = 0; i < this->probe_set_size_; ++i)
    {
      this->enqueue_count_ [this->consumer_index_] [i] = 0;
      this->dequeue_count_ [this->consumer_index_] [i] = 0;

      ACE_Metrics_Timeprobe<ACE_LOCK, ALLOCATOR> * probe =
        this->enqueue_probes_ [this->consumer_index_][i];
      probe->reset ();
      probe =
        this->dequeue_probes_ [this->consumer_index_][i];
      probe->reset ();
    }
}


// Flips the supplier and consumer positions.

template <class ACE_LOCK, class ALLOCATOR>
ACE_INLINE void
ACE_Metrics_Cache<ACE_LOCK, ALLOCATOR>::flip_supplier_and_consumer ()
{
  int temp = consumer_index_;
  consumer_index_ = supplier_index_;
  supplier_index_ = temp;
}

template <class ACE_LOCK, class ALLOCATOR>
ACE_INLINE void
ACE_Metrics_Cache<ACE_LOCK, ALLOCATOR>::metrics_enabled(int enabled)
{
   metrics_enabled_ = enabled;
}

template <class ACE_LOCK, class ALLOCATOR>
ACE_INLINE int
ACE_Metrics_Cache<ACE_LOCK, ALLOCATOR>::metrics_enabled(void) const
{
   return metrics_enabled_;
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_METRICS_CACHE_T_INL */
