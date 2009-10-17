// -*- C++ -*-

//=============================================================================
/**
 * @file Metrics_Cache_T.h
 *
 * $Id: Metrics_Cache_T.h 80826 2008-03-04 14:51:23Z wotte $
 *
 * @author Chris Gill <cdgill@cse.wustl.edu>
 */
//=============================================================================


#ifndef ACE_METRICS_CACHE_T_H
#define ACE_METRICS_CACHE_T_H

#include /**/ "ace/config-all.h"

// helpful macro definitions
#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if defined (ACE_COMPILE_TIMEPROBES)

#include "ace/Timeprobe.h"
#include "ace/Timeprobe_T.h"

// Defaults for initializing timeprobes and timeprobe arays.
#define METRICS_MIN_TIMEPROBE_TABLE_SIZE 256 * 4
#define METRICS_MAX_TIMEPROBE_TABLE_SIZE 256 * 256
#define METRICS_DEFAULT_TIMEPROBE_TABLE_SIZE METRICS_MIN_TIMEPROBE_TABLE_SIZE
#define METRICS_DEFAULT_TIMEPROBE_COUNT 6

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class ACE_Metrics_Timeprobe
 *
 * @brief This class implements a timeprobe for use in a Metrics framework.
 *
 * This class provides a probe for specific thread and method call
 * metrics timing points.
 */
template <class ACE_LOCK, class ALLOCATOR>
class ACE_Metrics_Timeprobe :
  public ACE_Timeprobe_Ex<ACE_LOCK, ALLOCATOR>
  {
public:

  typedef ACE_Metrics_Timeprobe<ACE_LOCK, ALLOCATOR>
          ACE_METRICS_TIMEPROBE_TYPE;

  typedef ACE_timeprobe_t ACE_METRICS_TIMEPROBE_DATA_TYPE;
  typedef ACE_METRICS_TIMEPROBE_TYPE* ACE_METRICS_TIMEPROBE_BASED_PTR_TYPE;
  typedef char* ACE_METRICS_NAME_BASED_PTR_TYPE;

  // Enumerated timeprobe event types.
  enum event_id
  {
    WORK_START = 0,
    WORK_STOP = 1,
    WORK_SUSPEND = 2,
    WORK_RESUME = 3
  };

  // Default constructor: plugs in the above event descriptions.
  ACE_Metrics_Timeprobe (u_int id = 0,
                         const char *name = 0,
                         u_long size = METRICS_DEFAULT_TIMEPROBE_TABLE_SIZE);

  // Constructor with allocator: plugs in the above event descriptions.
  ACE_Metrics_Timeprobe (ALLOCATOR *allocatorPtr,
                         u_int id = 0,
                         const char *name = 0,
                         u_long size = METRICS_DEFAULT_TIMEPROBE_TABLE_SIZE);

  // Destructor.
  virtual ~ACE_Metrics_Timeprobe ();

  // Returns true if a timeprobe event matches the passed id.
  int is_event (const ACE_METRICS_TIMEPROBE_DATA_TYPE &t,
                ACE_Metrics_Timeprobe<ACE_LOCK, ALLOCATOR>::event_id id);

  // Accessor and mutator for probe name.
  const char * probe_name (void);
  void probe_name (char * name);

  // Accessor for probe id.
  u_int probe_id (void);

  // Mutator for probe id.
  void probe_id (u_int id);

  // Flush the ACE metrics timeprobe into shared memory.
  void flush_ACE_Metrics_Timeprobe ();

protected:

  // Identifier for the timeprobe.
  u_int id_;

  // Name of the timeprobe.
  char* name_;

private:

  // Declare but do not define.
  ACE_Metrics_Timeprobe (const ACE_Metrics_Timeprobe<ACE_LOCK, ALLOCATOR> &);
  void operator =(const ACE_Metrics_Timeprobe<ACE_LOCK, ALLOCATOR> &);
};

/**
 * @class ACE_Metrics_Cache
 *
 * @brief This class implements a cache for metrics timeprobe data.
 *
 *   This class allows probes to be recorded into a single cache that
 *   monitors and other higher level metrics classes can query.
 */
template <class ACE_LOCK, class ALLOCATOR>
class ACE_Metrics_Cache
{
public:

  typedef ACE_Metrics_Cache <ACE_LOCK, ALLOCATOR> ACE_METRICS_CACHE_TYPE;

  // Default constructor.
  ACE_Metrics_Cache (u_long table_size
                       = METRICS_DEFAULT_TIMEPROBE_TABLE_SIZE,
                     u_long number_of_probes
                       = METRICS_DEFAULT_TIMEPROBE_COUNT,
                     ALLOCATOR * allocatorPtr = (ALLOCATOR*)ALLOCATOR::instance());

  // Destructor.
  ~ACE_Metrics_Cache ();

  // = Dispatching metrics.

  // Report start, stop, suspend, and resume times of a dispatch
  // enqueue: stores data metrics on the supplier side.
  void report_enqueue_start (u_long i);
  void report_enqueue_stop (u_long i);
  void report_enqueue_suspend (u_long i);
  void report_enqueue_resume (u_long i);

  // Report start, stop, suspend, and resume times of a dispatch
  // dequeue: stores data metrics on the supplier side..
  void report_dequeue_start (u_long i);
  void report_dequeue_stop (u_long i);
  void report_dequeue_suspend (u_long i);
  void report_dequeue_resume (u_long i);

  // Reset the metrics data on the consumer side.
  void reset_base_statistics ();

  // Flips the supplier and consumer sides.
  void flip_supplier_and_consumer ();

  // Flush the ACE metrics cache into shared memory.
  void flush_ACE_Metrics_Cache ();

  // Set the enable state for metrics collection.
  void metrics_enabled(int enabled);

  // Return the enable state for metrics collection.
  int metrics_enabled(void) const;

protected:

  // Obtain an allocator pointer correctly thunked for the current
  // address space.  If there is no allocator stored in the instance,
  // the singleton allocator in the current process is used.
  ALLOCATOR * allocator (void);

  // = Implementation members.

  // Number of probes in each supplier/consumer set.
  u_long probe_set_size_;

  // Probe data counts for each supplier/consumer set.
  u_long * enqueue_count_ [2];
  u_long * dequeue_count_ [2];

  // Probes for each supplier/consumer set.
  ACE_Metrics_Timeprobe<ACE_LOCK, ALLOCATOR> ** enqueue_probes_ [2];
  ACE_Metrics_Timeprobe<ACE_LOCK, ALLOCATOR> ** dequeue_probes_ [2];

  // Names for the probes.
  char ** enqueue_names_;
  char ** dequeue_names_;

  // Index from which probe events are being consumed.
  // for WSOA, it's the data being sent to the logger
  int consumer_index_;

  // Index to which probe events are being supplied.
  // for WSOA, it's the data being recorded from the probes
  int supplier_index_;

  // Size of the timestamp table in each probe.
  u_long table_size_;

  // Interval start and stop timestamps.
  ACE_Time_Value interval_start_;

  // Interval start and stop timestamps.
  ACE_Time_Value interval_end_;

  // Flag to indicate whether or not start time of interval has been
  // initialized since the last reset.
  int interval_initialized_;

  // Indicator of whether metrics is enabled.
  int metrics_enabled_;

private:

  // Allocation strategy object.
  ALLOCATOR* allocator_;

  // Declare but do not define.
  ACE_Metrics_Cache (const ACE_Metrics_Cache<ACE_LOCK, ALLOCATOR> &);
  void operator = (const ACE_Metrics_Cache<ACE_LOCK, ALLOCATOR> &);
};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ace/Metrics_Cache_T.inl"
#endif /* __ACE_INLINE__ */

#if defined (ACE_TEMPLATES_REQUIRE_SOURCE)
#include "ace/Metrics_Cache_T.cpp"
#endif /* ACE_TEMPLATES_REQUIRE_SOURCE */

#if defined (ACE_TEMPLATES_REQUIRE_PRAGMA)
#pragma implementation ("Metrics_Cache_T.cpp")
#endif /* ACE_TEMPLATES_REQUIRE_PRAGMA */

#endif /* defined (ACE_COMPILE_TIMEPROBES) */

#endif /* ACE_METRICS_CACHE_T_H */

