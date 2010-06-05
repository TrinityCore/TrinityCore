// -*- C++ -*-

//=============================================================================
/**
 *  @file    Timeprobe.h
 *
 *  $Id: Timeprobe.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Irfan Pyarali
 *
 * If users want to use time probes, the ACE_COMPILE_TIMEPROBES
 * flag must be defined when compiling ACE.  This can be achieved
 * by doing one of the following:
 *
 * . Use make probe = 1, if you are using the make utility.
 *
 * . Define ACE_COMPILE_TIMEPROBES in config.h
 *
 * . Define ACE_COMPILE_TIMEPROBES in the VC project file.
 *
 * . Other regular methods will also work.
 *
 * It is not necessary to define ACE_COMPILE_TIMEPROBES when using
 * time probes, you simply need ACE_ENABLE_TIMEPROBES.  You can use
 * the ACE_TIMEPROBE_* macros to program the time probes, and use
 * the ACE_ENABLE_TIMEPROBE to enable the time probes.  If you
 * define ACE_ENABLE_TIMEPROBE in your code, but forget to compile
 * ACE with ACE_COMPILE_TIMEPROBES, you will end up with linker
 * errors.
 *
 * Remember that ACE_COMPILE_TIMEPROBES means that the ACE library
 * will contain code for time probes.  This is only useful when
 * compiling ACE. ACE_ENABLE_TIMEPROBES means that the
 * ACE_TIMEPROBE_* macros should spring to life.
 */
//=============================================================================

#ifndef ACE_TIMEPROBE_H
#define ACE_TIMEPROBE_H
#include /**/ "ace/pre.h"

#include "ace/config-lite.h"
#include /**/ "ace/ACE_export.h"
#include "ace/Malloc_Allocator.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

/* Enable ACE Timeprobes */
#if defined (ACE_ENABLE_TIMEPROBES)
  #if !defined (ACE_COMPILE_TIMEPROBES)
    #define ACE_COMPILE_TIMEPROBES
  #endif /* ACE_COMPILE_TIMEPROBES */
#endif /* ACE_ENABLE_TIMEPROBES */

#if defined (ACE_COMPILE_TIMEPROBES)

#include "ace/OS_NS_time.h"
#include "ace/OS_NS_Thread.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class ACE_Event_Descriptions
 *
 * @brief Event Descriptions.
 */
class ACE_Export ACE_Event_Descriptions
{
public:
  /// Event descriptions
  const char **descriptions_;

  /// Minimum id of this description set
  u_long minimum_id_;

  /// Comparison
  bool operator== (const ACE_Event_Descriptions &rhs) const;
};

/**
 * @class ACE_timeprobe_t
 *
 * @brief Time probe record.
 */
class ACE_Export ACE_timeprobe_t
{
public:
  /// Events are record as strings or numbers.
  union event
  {
    u_long event_number_;
    const char *event_description_;
  };

  /// Type of event.
  enum event_type
  {
    NUMBER,
    STRING
  };

  /// Event.
  event event_;

  /// Type of event.
  event_type event_type_;

  /// Timestamp.
  ACE_hrtime_t time_;

  /// Id of thread posting the time probe.
  ACE_thread_t thread_;
};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ace/Timeprobe.inl"
#endif /* __ACE_INLINE__ */

#include "ace/Synch_Traits.h"
#include "ace/Null_Mutex.h"
#include "ace/Singleton.h"
#include "ace/Timeprobe_T.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

// If ACE_MT_TIMEPROBES is defined, use a Thread_Mutex to lock the
// internal state of ACE_Timerprobe.  This allows multiple threads to
// use the same ACE_Timerprobe.
#  if defined (ACE_MT_TIMEPROBES)
typedef ACE_SYNCH_MUTEX ACE_TIMEPROBE_MUTEX;
#  else /* ACE_MT_TIMEPROBES */
typedef ACE_SYNCH_NULL_MUTEX ACE_TIMEPROBE_MUTEX;
#  endif /* ACE_MT_TIMEPROBES */

typedef ACE_New_Allocator ACE_TIMEPROBE_ALLOCATOR;

typedef ACE_Timeprobe_Ex<ACE_TIMEPROBE_MUTEX, ACE_TIMEPROBE_ALLOCATOR>
        ACE_TIMEPROBE_WITH_LOCKING;

// If ACE_TSS_TIMEPROBES is defined, store the ACE_Timeprobe singleton
// in thread specific storage.  This allows multiple threads to use
// their own instance of ACE_Timerprobe, without interfering with each
// other.

#  if defined (ACE_TSS_TIMEPROBES)
#    define ACE_TIMEPROBE_SINGLETON_TYPE ACE_TSS_Singleton
#    define ACE_TIMEPROBE_SINGLETON_LOCK_TYPE ACE_SYNCH_NULL_MUTEX
#  else /* ACE_TSS_TIMEPROBES */
#    define ACE_TIMEPROBE_SINGLETON_TYPE ACE_Singleton
#    define ACE_TIMEPROBE_SINGLETON_LOCK_TYPE ACE_SYNCH_MUTEX
#  endif /* ACE_TSS_TIMEPROBES */

ACE_SINGLETON_DECLARE (ACE_TIMEPROBE_SINGLETON_TYPE, \
                       ACE_TIMEPROBE_WITH_LOCKING,   \
                       ACE_TIMEPROBE_SINGLETON_LOCK_TYPE)

typedef ACE_TIMEPROBE_SINGLETON_TYPE<ACE_TIMEPROBE_WITH_LOCKING, ACE_TIMEPROBE_SINGLETON_LOCK_TYPE>
        ACE_TIMEPROBE_SINGLETON;

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_COMPILE_TIMEPROBES */

// If ACE_ENABLE_TIMEPROBES is defined, the macros below will
// work. Otherwise, they just vanish.  Using this macro, you can
// control which files/libraries are probed.
#if defined (ACE_ENABLE_TIMEPROBES) && defined (ACE_COMPILE_TIMEPROBES)

#  define ACE_TIMEPROBE_RESET ACE_TIMEPROBE_SINGLETON::instance ()->reset ()

#  define ACE_TIMEPROBE(id) ACE_TIMEPROBE_SINGLETON::instance ()->timeprobe (id)

#  define ACE_TIMEPROBE_PRINT ACE_TIMEPROBE_SINGLETON::instance ()->print_times ()

#  define ACE_TIMEPROBE_PRINT_ABSOLUTE ACE_TIMEPROBE_SINGLETON::instance ()->print_absolute_times ()

#  define ACE_TIMEPROBE_EVENT_DESCRIPTIONS(descriptions, minimum_id) \
static int ace_timeprobe_##descriptions##_return = \
  ACE_TIMEPROBE_SINGLETON::instance ()->event_descriptions \
    (descriptions, minimum_id)

#  define ACE_FUNCTION_TIMEPROBE(X) \
  ACE_Function_Timeprobe<ACE_TIMEPROBE_WITH_LOCKING> function_timeprobe \
    (*ACE_TIMEPROBE_SINGLETON::instance (), X)

#else /* ACE_ENABLE_TIMEPROBES && ACE_COMPILE_TIMEPROBES */

#  define ACE_TIMEPROBE_RESET
#  define ACE_TIMEPROBE(id)
#  define ACE_TIMEPROBE_PRINT
#  define ACE_TIMEPROBE_PRINT_ABSOLUTE
#  define ACE_TIMEPROBE_EVENT_DESCRIPTIONS(descriptions, minimum_id)
#  define ACE_FUNCTION_TIMEPROBE(X)

#endif /* ACE_ENABLE_TIMEPROBES && ACE_COMPILE_TIMEPROBES */
#include /**/ "ace/post.h"
#endif /* ACE_TIMEPROBE_H */

