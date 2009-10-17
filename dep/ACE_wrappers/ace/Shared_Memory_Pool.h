// -*- C++ -*-
//=============================================================================
/**
 *  @file     Shared_Memory_Pool.h
 *
 *  $Id: Shared_Memory_Pool.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Dougls C. Schmidt <schmidt@cs.wustl.edu>
 *  @author Prashant Jain <pjain@cs.wustl.edu>
 */
//=============================================================================
#ifndef ACE_SHARED_MEMORY_POOL_H
#define ACE_SHARED_MEMORY_POOL_H
#include /**/ "ace/pre.h"
#include /**/ "ace/ACE_export.h"
#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */
#if !defined (ACE_LACKS_SYSV_SHMEM)
#include "ace/ACE.h"
#include "ace/Event_Handler.h"
#include "ace/Sig_Handler.h"
#include "ace/os_include/sys/os_mman.h"
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
/**
 * @class ACE_Shared_Memory_Pool_Options
 *
 * @brief Helper class for Shared Memory Pool constructor options.
 *
 * This should be a nested class, but that breaks too many
 * compilers.
 */
class ACE_Export ACE_Shared_Memory_Pool_Options
{
public:
  /// Initialization method.
  ACE_Shared_Memory_Pool_Options (
    const char *base_addr = ACE_DEFAULT_BASE_ADDR,
    size_t max_segments = ACE_DEFAULT_MAX_SEGMENTS,
    size_t file_perms = ACE_DEFAULT_FILE_PERMS,
    ACE_OFF_T minimum_bytes = 0,
    size_t segment_size = ACE_DEFAULT_SEGMENT_SIZE);
  /// Base address of the memory-mapped backing store.
  const char *base_addr_;
  /// Number of shared memory segments to allocate.
  size_t max_segments_;
  /// What the minimum bytes of the initial segment should be.
  ACE_OFF_T minimum_bytes_;
  /// File permissions to use when creating/opening a segment.
  size_t file_perms_;
  /// Shared memory segment size.
  size_t segment_size_;
};
/**
 * @class ACE_Shared_Memory_Pool
 *
 * @brief Make a memory pool that is based on System V shared memory
 * (shmget(2) etc.).  This implementation allows memory to be
 * shared between processes.  If your platform doesn't support
 * System V shared memory (e.g., Win32 and many RTOS platforms
 * do not) then you should use ACE_MMAP_Memory_Pool instead of this
 * class.  In fact, you should probably use ACE_MMAP_Memory_Pool on
 * platforms that *do* support System V shared memory since it
 * provides more powerful features, such as persistent backing store
 * and greatly scalability.
 */
class ACE_Export ACE_Shared_Memory_Pool : public ACE_Event_Handler
{
public:
  typedef ACE_Shared_Memory_Pool_Options OPTIONS;
  /// Initialize the pool.
  ACE_Shared_Memory_Pool (const ACE_TCHAR *backing_store_name = 0,
                          const OPTIONS *options = 0);
  virtual ~ACE_Shared_Memory_Pool (void);
  /// Ask system for initial chunk of local memory.
  virtual void *init_acquire (size_t nbytes,
                              size_t &rounded_bytes,
                              int &first_time);
  /**
   * Acquire at least @a nbytes from the memory pool. @a rounded_byes is
   * the actual number of bytes allocated.  Also acquires an internal
   * semaphore that ensures proper serialization of Memory_Pool
   * initialization across processes.
   */
  virtual void *acquire (size_t nbytes,
                         size_t &rounded_bytes);
  /// Instruct the memory pool to release all of its resources.
  virtual int release (int destroy = 1);
  /// Sync the memory region to the backing store starting at
  /// @c this->base_addr_.
  virtual int sync (ssize_t len = -1, int flags = MS_SYNC);
  /// Sync the memory region to the backing store starting at @a addr.
  virtual int sync (void *addr, size_t len, int flags = MS_SYNC);
  /**
   * Change the protection of the pages of the mapped region to @a prot
   * starting at @c this->base_addr_ up to @a len bytes.  If @a len == -1
   * then change protection of all pages in the mapped region.
   */
  virtual int protect (ssize_t len = -1, int prot = PROT_RDWR);
  /// Change the protection of the pages of the mapped region to @a prot
  /// starting at @a addr up to @a len bytes.
  virtual int protect (void *addr, size_t len, int prot = PROT_RDWR);
  /// Return the base address of this memory pool, 0 if base_addr
  /// never changes.
  virtual void *base_addr (void) const;
  /// Dump the state of an object.
  virtual void dump (void) const;
  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;
protected:
  /// Implement the algorithm for rounding up the request to an
  /// appropriate chunksize.
  virtual size_t round_up (size_t nbytes);
  /**
   * Commits a new shared memory segment if necessary after an
   * <acquire> or a signal.  @a offset is set to the new offset into
   * the backing store.
   */
  virtual int commit_backing_store_name (size_t rounded_bytes,
                                         ACE_OFF_T &offset);
  /// Keeps track of all the segments being used.
  struct SHM_TABLE
  {
    /// Shared memory segment key.
    key_t key_;
    /// Shared memory segment internal id.
    int shmid_;
    /// Is the segment currently used.;
    int used_;
  };
  /**
   * Base address of the shared memory segment.  If this has the value
   * of 0 then the OS is free to select any address, otherwise this
   * value is what the OS must try to use to map the shared memory
   * segment.
   */
  void *base_addr_;
  /// File permissions to use when creating/opening a segment.
  size_t file_perms_;
  /// Number of shared memory segments in the <SHM_TABLE> table.
  size_t max_segments_;
  /// What the minimim bytes of the initial segment should be.
  ACE_OFF_T minimum_bytes_;
  /// Shared memory segment size.
  size_t segment_size_;
  /// Base shared memory key for the segment.
  key_t base_shm_key_;
  /// Find the segment that contains the @a searchPtr
  virtual int find_seg (const void *const searchPtr,
                        ACE_OFF_T &offset,
                        size_t &counter);
  /// Determine how much memory is currently in use.
  virtual int in_use (ACE_OFF_T &offset,
                      size_t &counter);
  /// Handles SIGSEGV.
  ACE_Sig_Handler signal_handler_;
  /// Handle SIGSEGV and SIGBUS signals to remap shared memory
  /// properly.
  virtual int handle_signal (int signum, siginfo_t *, ucontext_t *);
};
ACE_END_VERSIONED_NAMESPACE_DECL
#endif /* !ACE_LACKS_SYSV_SHMEM */
#include /**/ "ace/post.h"
#endif /* ACE_SHARED_MEMORY_POOL_H */

