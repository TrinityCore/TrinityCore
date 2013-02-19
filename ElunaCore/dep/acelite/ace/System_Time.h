// -*- C++ -*-

//=============================================================================
/**
 *  @file    System_Time.h
 *
 *  $Id: System_Time.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Prashant Jain
 *  @author Tim H. Harrison
 *  @author Douglas C. Schmidt
 */
//=============================================================================

#ifndef ACE_SYSTEM_TIME_H
#define ACE_SYSTEM_TIME_H
#include /**/ "ace/pre.h"

#include /**/ "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/Global_Macros.h"
#include "ace/os_include/os_time.h"  /* For time_t. */
#include "ace/os_include/os_limits.h"  /* For MAXPATHLEN. */
#include "ace/MMAP_Memory_Pool.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

template<ACE_MEM_POOL_1, class ACE_LOCK> class ACE_Malloc;
template<class MALLOC> class ACE_Allocator_Adapter;

class ACE_Null_Mutex;
class ACE_Time_Value;
class ACE_MMAP_Memory_Pool;

/**
 * @class ACE_System_Time
 *
 * @brief Defines the timer services of the OS interface to access the
 * system time either on the local host or on the central time
 * server in the network.
 */
class ACE_Export ACE_System_Time
{
public:
  /**
   * Enumeration types to specify mode of synchronization with master
   * clock.  Jump will set local system time directly (thus possibly
   * producing time gaps or ambiguous local system times.  Adjust will
   * smoothly slow down or speed up the local system clock to reach
   * the system time of the master clock.
   */
  enum Sync_Mode { Jump, Adjust };

  /// Default constructor.
  ACE_System_Time (const ACE_TCHAR *poolname = 0);

  /// Default destructor.
  ~ACE_System_Time (void);

  /// Get the local system time, i.e., the value returned by
  /// ACE_OS::time().
  static int get_local_system_time (time_t & time_out);

  /// Get the local system time, i.e., the value returned by
  /// ACE_OS::time().
  static int get_local_system_time (ACE_Time_Value &time_out);

  /// Get the system time of the central time server.
  int get_master_system_time (time_t & time_out);

  /// Get the system time of the central time server.
  int get_master_system_time (ACE_Time_Value &time_out);

  /// Synchronize local system time with the central time server using
  /// specified mode.
  int sync_local_system_time (ACE_System_Time::Sync_Mode mode);

private:
  typedef ACE_Malloc<ACE_MMAP_MEMORY_POOL, ACE_Null_Mutex> MALLOC;
  typedef ACE_Allocator_Adapter<MALLOC> ALLOCATOR;

  /// Our allocator (used for obtaining system time from shared memory).
  ALLOCATOR * shmem_;

  /// The name of the pool used by the allocator.
  ACE_TCHAR poolname_[MAXPATHLEN + 1];

  /// Pointer to delta time kept in shared memory.
  long * delta_time_;
};

ACE_END_VERSIONED_NAMESPACE_DECL

#include /**/ "ace/post.h"
#endif /* ACE_SYSTEM_TIME_H */
