/* -*- C++ -*- */

//=============================================================================
/**
 *  @file    Metrics_Cache.h
 *
 *  $Id: Metrics_Cache.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Chris Gill
 */
//=============================================================================


#ifndef ACE_METRICS_CACHE_H
#define ACE_METRICS_CACHE_H

#include "ace/Timeprobe.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if defined (ACE_METRICS_COLLECTION)

#if defined (ACE_ENABLE_TIMEPROBES) && defined (ACE_COMPILE_TIMEPROBES)

/**
 * Call the appropriate 'report_ + NAME + _start' function. The start function makes a time probe measurement.
 *
 * ACE: The cache is a double-sided space of ACE_Timeprobe objects. For example if there is 10 probes there
 * will be a two lists of 10 probes all initialized. When a record is made, the appropriate probe is found,
 * add the measurement is made.
 *
 * TAO: The cache is still double sided but this time the X argument is a handle_t. The appropriate monitor
 *      map is located in the Metrics_Cache, find the data, and if there is nothing wrong with the data
 *      make a time measurement. The data is actually a ACE_Metrics_Timeprobe (Why not TAO_Metrics_Timeprobe?)
 *
 * USAGE_LEVEL: ACE+TAO
 *
 * @param METRICS_PTR - Pointer to a initialized metrics cache
 * @param NAME - Name of defining function (e.g. ACE: enqueue/dequeue)
 * @param X - Argument (ACE: u_int, TAO: RtecScheduler::handle_t)
 */
#  define START_DISPATCH_METRIC(METRICS_PTR,NAME,X) \
do { if((METRICS_PTR->metrics_enabled())) { \
METRICS_PTR->report_##NAME##_start(X); \
} } while (0)

/**
 * Call the appropriate 'report_ + NAME + _stop' function. The stop function makes a time probe measurement.
 *
 * ACE & TAO: Same as START_DISPATCH_METRIC
 *
 * USAGE_LEVEL: ACE+TAO
 *
 * @param METRICS_PTR - Pointer to a initialized metrics cache
 * @param NAME - Name of defining function (e.g. ACE: enqueue/dequeue)
 * @param X - Argument (ACE: u_int, TAO: RtecScheduler::handle_t)
 */
#  define STOP_DISPATCH_METRIC(METRICS_PTR,NAME,X) \
do { if((METRICS_PTR->metrics_enabled())) { \
METRICS_PTR->report_##NAME##_stop(X); \
} } while (0)

/**
 * Call the appropriate 'report_ + NAME + _suspend' function. The suspend function makes a time probe measurement.
 * This marks when the object under observation has been suspended.
 *
 * USAGE_LEVEL: ACE+TAO
 *
 * @param METRICS_PTR - Pointer to a initialized metrics cache
 * @param NAME - Name of defining function (e.g. ACE: enqueue/dequeue)
 * @param X - Argument (ACE: u_int, TAO: RtecScheduler::handle_t)
 */
#  define PAUSE_DISPATCH_METRIC(METRICS_PTR,NAME,X) \
do { if((METRICS_PTR->metrics_enabled())) { \
METRICS_PTR->report_##NAME##_suspend(X); \
} } while (0)

/**
 * Call the appropriate 'report_ + NAME + _resume' function. The suspend function makes a time probe measurement.
 * This marks when the object under observation that was suspended is not resuming normal execution.
 *
 * USAGE_LEVEL: ACE+TAO
 *
 * @param METRICS_PTR - Pointer to a initialized metrics cache
 * @param NAME - Name of defining function (e.g. ACE: enqueue/dequeue)
 * @param X - Argument (ACE: u_int, TAO: RtecScheduler::handle_t)
 */
#  define RESUME_DISPATCH_METRIC(METRICS_PTR,NAME,X) \
do { if((METRICS_PTR->metrics_enabled())) { \
METRICS_PTR->report_##NAME##_resume(X); \
} } while (0)


/**
 * Mystery macros. I could not find where there were functions like 'report_base_metrics_start ()'. All the
 * start and stop functions had an argument to find the probe in the cache
 */
#  define START_METRIC(METRICS_PTR,NAME) \
do { if((METRICS_PTR->metrics_enabled())) { \
METRICS_PTR->report_##NAME##_start(); \
} } while (0)

#  define STOP_METRIC(METRICS_PTR,NAME) \
do { if((METRICS_PTR->metrics_enabled())) { \
METRICS_PTR->report_##NAME##_stop(); \
} } while (0)

#include "ace/Metrics_Cache_T.h"
#include "ace/Singleton.h"

#if defined (_MSC_VER)
// Disable warning of using Microsoft Extension.
#pragma warning(disable:4231)
#endif /* _MSC_VER */

#if defined (_MSC_VER)
// Default back the warning of using Microsoft Extension.
#pragma warning(default:4231)
#endif /* _MSC_VER */

#else
#error ACE_Compile_Timeprobes must be defined in order to collect metrics
#endif /* ACE_ENABLE_TIMEPROBES & ACE_COMPILE_TIMEPROBES */

#else

#  define REGISTER_METRICS_PROBE_RETURN(METRICS_PTR,METRICS_REGION,PROBE_NAME,PROBE_TYPE,METRICS_HANDLE)
#  define REGISTER_METRICS_REPORTING_PROBE_RETURN(METRICS_PTR,METRICS_REGION,PROBE_NAME,PROBE_TYPE,METRICS_LOGGER_REF,METRICS_HANDLE)
#  define START_DISPATCH_METRIC(METRICS_PTR,NAME,X)
#  define STOP_DISPATCH_METRIC(METRICS_PTR,NAME,X)
#  define PAUSE_DISPATCH_METRIC(METRICS_PTR,NAME,X)
#  define RESUME_DISPATCH_METRIC(METRICS_PTR,NAME,X)
#  define START_METRIC(METRICS_PTR,NAME)
#  define STOP_METRIC(METRICS_PTR,NAME)

#endif /* ACE_ENABLE_TIMEPROBES && ACE_COMPILE_TIMEPROBES */

#endif /* ACE_METRICS_CACHE_H */
