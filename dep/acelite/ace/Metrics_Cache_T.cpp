// $Id: Metrics_Cache_T.cpp 92090 2010-09-29 14:10:45Z johnnyw $

#ifndef ACE_METRICS_CACHE_CPP
#define ACE_METRICS_CACHE_CPP

//#define ACE_BUILD_DLL

#include "ace/Metrics_Cache_T.h"

#if defined (ACE_COMPILE_TIMEPROBES)

#include "ace/Metrics_Cache.h"

#if !defined (__ACE_INLINE__)
#include "ace/Metrics_Cache_T.inl"
#endif /* __ACE_INLINE__ */

/// Const strings for timeprobe event type descriptions.
static const char * event_description_strings [] =
{
  "start",
  "stop",
  "suspend",
  "resume"
};

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/////////////////////////////////
// class ACE_Metrics_Timeprobe //
/////////////////////////////////

template <class ACE_LOCK, class ALLOCATOR>
ACE_Metrics_Timeprobe<ACE_LOCK, ALLOCATOR>::ACE_Metrics_Timeprobe (u_int id,
                                                                   const char *name,
                                                                   u_long size)
  :
    ACE_Timeprobe<ACE_LOCK> (size),
    id_ (id),
    name_ (0)
{
  if (name == 0)
    {
      name = "";
    }

  char * name_tmp = 0;
  ACE_NEW_MALLOC_ARRAY (name_tmp,
                        (char *) this->allocator ()->malloc (ACE_OS::strlen(name)+1),
                        char,
                        ACE_OS::strlen(name)+1);
  ACE_OS::memcpy (name_tmp, name, ACE_OS::strlen (name)+1);
  name_ = name_tmp;

  this->event_descriptions (event_description_strings,
                            sizeof(event_description_strings)/sizeof(const char *));
}

template <class ACE_LOCK, class ALLOCATOR>
ACE_Metrics_Timeprobe<ACE_LOCK, ALLOCATOR>::
ACE_Metrics_Timeprobe (ALLOCATOR *alloc,
                       u_int id,
                       const char *name,
                       u_long size)
  : ACE_Timeprobe_Ex<ACE_LOCK, ALLOCATOR> (size),
    id_ (id),
    name_ (0)
{
  if (name == 0)
    {
      name = "";
    }

  char * name_tmp = 0;
  ACE_NEW_MALLOC_ARRAY (name_tmp,
                        (char *) alloc->malloc(ACE_OS::strlen(name)+1),
                        char,
                        ACE_OS::strlen(name)+1);
  ACE_OS::memcpy (name_tmp, name, ACE_OS::strlen (name)+1);
  name_ = name_tmp;

  this->event_descriptions (event_description_strings,
                            sizeof(event_description_strings)/sizeof(const char *));
}

template <class ACE_LOCK, class ALLOCATOR>
ACE_Metrics_Timeprobe<ACE_LOCK, ALLOCATOR>::~ACE_Metrics_Timeprobe ()
{
   if (name_)
    {
         this->allocator ()->free ((void*) name_);
    }
}


// Returns true if a timeprobe matches the passed id.

template <class ACE_LOCK, class ALLOCATOR>
int
ACE_Metrics_Timeprobe<ACE_LOCK, ALLOCATOR>::is_event (const ACE_Metrics_Timeprobe<ACE_LOCK,
                                                      ALLOCATOR>::
                                                      ACE_METRICS_TIMEPROBE_DATA_TYPE &t,
                                                      ACE_Metrics_Timeprobe<ACE_LOCK,
                                                      ALLOCATOR>::
                                                      event_id id)
{
  return (t.event_.event_number_ ==  (u_long) id) ? 1 : 0;
}

template <class ACE_LOCK, class ALLOCATOR>
const char *
ACE_Metrics_Timeprobe<ACE_LOCK, ALLOCATOR>::probe_name (void)
{
   return name_;
}

template <class ACE_LOCK, class ALLOCATOR>
void
ACE_Metrics_Timeprobe<ACE_LOCK, ALLOCATOR>::probe_name (char * name)
{
  char * name_tmp = 0;
  ACE_NEW_MALLOC_ARRAY (name_tmp,
                        (char *) this->allocator ()->malloc (ACE_OS::strlen(name)+1),
                        char,
                        ACE_OS::strlen(name)+1);
  ACE_OS::memcpy (name_tmp, name, ACE_OS::strlen (name)+1);

  if (name_)
  {
     this->allocator ()->free (name_);
  }

  name_ = name_tmp;
}

template <class ACE_LOCK, class ALLOCATOR>
u_int
ACE_Metrics_Timeprobe<ACE_LOCK, ALLOCATOR>::probe_id (void)
{
  return id_;
}


template <class ACE_LOCK, class ALLOCATOR>
void
ACE_Metrics_Timeprobe<ACE_LOCK, ALLOCATOR>::probe_id (u_int id)
{
  id_ = id;
}


// Flush the ACE metrics timeprobe into shared memory.

template <class ACE_LOCK, class ALLOCATOR> void
ACE_Metrics_Timeprobe<ACE_LOCK, ALLOCATOR>::
flush_ACE_Metrics_Timeprobe ()
{
}


/////////////////////////////
// Class ACE_Metrics_Cache //
/////////////////////////////


// Constructor.

template <class ACE_LOCK, class ALLOCATOR>
ACE_Metrics_Cache<ACE_LOCK, ALLOCATOR>::
ACE_Metrics_Cache (u_long table_size,
                   u_long,
                   ALLOCATOR *alloc)
  : probe_set_size_ (0),
    enqueue_names_ (0),
    dequeue_names_ (0),
    consumer_index_ (0),
    supplier_index_ (1),
    table_size_ (table_size),
    interval_start_ (ACE_Time_Value::zero),
    interval_end_ (ACE_Time_Value::zero),
    interval_initialized_ (0),
    metrics_enabled_(1),
    allocator_ (alloc)
{
  // Initialize probe and count arrays.

  // Ensure that the high res timer global scale factor
  // is set before any of its static methods are used
  ACE_High_Res_Timer::global_scale_factor ();

  enqueue_count_ [0] = 0;
  enqueue_count_ [1] = 0;
  dequeue_count_ [0] = 0;
  dequeue_count_ [1] = 0;
  enqueue_probes_ [0] = 0;
  enqueue_probes_ [1] = 0;
  dequeue_probes_ [0] = 0;
  dequeue_probes_ [1] = 0;
}

// Destructor.

template <class ACE_LOCK, class ALLOCATOR>
ACE_Metrics_Cache<ACE_LOCK, ALLOCATOR>::~ACE_Metrics_Cache ()
{
}

// Obtain an allocator pointer correctly thunked for the current
// address space.  If there is no allocator stored in the instance,
// the singleton allocator in the current process is used.

template <class ACE_LOCK, class ALLOCATOR> ALLOCATOR *
ACE_Metrics_Cache<ACE_LOCK, ALLOCATOR>::allocator (void)
{
  ALLOCATOR * alloc = allocator_;
  return alloc
         ? alloc
         : ACE_Singleton<ALLOCATOR, ACE_LOCK>::instance ();
}


// Flush the ACE metrics cache into shared memory.

template <class ACE_LOCK, class ALLOCATOR> void
ACE_Metrics_Cache<ACE_LOCK, ALLOCATOR>::
flush_ACE_Metrics_Cache ()
{
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* defined (ACE_COMPILE_TIMEPROBES) */

#endif /* ACE_METRICS_CACHE_CPP */
