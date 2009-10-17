// -*- C++ -*-
//=============================================================================
/**
 *  @file     Sbrk_Memory_Pool.h
 *
 *  $Id: Sbrk_Memory_Pool.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Dougls C. Schmidt <schmidt@cs.wustl.edu>
 *  @author Prashant Jain <pjain@cs.wustl.edu>
 */
//=============================================================================
#ifndef ACE_SBRK_MEMORY_POOL_H
#define ACE_SBRK_MEMORY_POOL_H
#include /**/ "ace/pre.h"
#include /**/ "ace/ACE_export.h"
#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */
#if !defined (ACE_LACKS_SBRK)
#include "ace/ACE.h"
#include "ace/os_include/sys/os_mman.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL
/**
 * @class ACE_Sbrk_Memory_Pool_Options
 *
 * @brief Helper class for Sbrk Memory Pool constructor options.
 *
 * This should be a nested class, but that breaks too many
 * compilers.
 */
class ACE_Export ACE_Sbrk_Memory_Pool_Options
{
};
/**
 * @class ACE_Sbrk_Memory_Pool
 *
 * @brief Make a memory pool that is based on <sbrk(2)>.
 */
class ACE_Export ACE_Sbrk_Memory_Pool
{
public:
  typedef ACE_Sbrk_Memory_Pool_Options OPTIONS;
  /// Initialize the pool.
  ACE_Sbrk_Memory_Pool (const ACE_TCHAR *backing_store_name = 0,
                        const OPTIONS *options = 0);
  virtual ~ACE_Sbrk_Memory_Pool (void);
  // = Implementor operations.
  /// Ask system for initial chunk of local memory.
  virtual void *init_acquire (size_t nbytes,
                              size_t &rounded_bytes,
                              int &first_time);
  /// Acquire at least @a nbytes from the memory pool. @a rounded_bytes is
  /// the actual number of bytes allocated.
  virtual void *acquire (size_t nbytes,
                         size_t &rounded_bytes);
  /// Instruct the memory pool to release all of its resources.
  virtual int release (int destroy = 1);
  /**
   * Sync @a len bytes of the memory region to the backing store
   * starting at @c this->base_addr_.  If @a len == -1 then sync the
   * whole region.
   */
  virtual int sync (ssize_t len = -1, int flags = MS_SYNC);
  /// Sync @a len bytes of the memory region to the backing store
  /// starting at @a addr.
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
  /// Dump the state of an object.
  virtual void dump (void) const;
  /// Return the base address of this memory pool, 0 if base_addr
  /// never changes.
  virtual void *base_addr (void) const;
  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;
protected:
  /// Implement the algorithm for rounding up the request to an
  /// appropriate chunksize.
  virtual size_t round_up (size_t nbytes);
};
ACE_END_VERSIONED_NAMESPACE_DECL
#endif /* !ACE_LACKS_SBRK */
#include /**/ "ace/post.h"
#endif /* ACE_SBRK_MEMORY_POOL_H */

