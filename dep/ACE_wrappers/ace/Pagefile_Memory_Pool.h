// -*- C++ -*-
//=============================================================================
/**
 *  @file     Pagefile_Memory_Pool.h
 *
 *  $Id: Pagefile_Memory_Pool.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Dougls C. Schmidt <schmidt@cs.wustl.edu>
 *  @author Prashant Jain <pjain@cs.wustl.edu>
 */
//=============================================================================
#ifndef ACE_PAGEFILE_MEMORY_POOL_H
#define ACE_PAGEFILE_MEMORY_POOL_H
#include /**/ "ace/pre.h"
#include /**/ "ace/ACE_export.h"
#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */
#if defined (ACE_WIN32) && !defined (ACE_HAS_PHARLAP)
#include "ace/ACE.h"
#include "ace/os_include/sys/os_mman.h"
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
/**
 * @class ACE_Pagefile_Memory_Pool_Options
 *
 * @brief Helper class for Pagefile Memory Pool constructor options.
 *
 * This should be a nested class, but that breaks too many
 * compilers.
 */
class ACE_Export ACE_Pagefile_Memory_Pool_Options
{
public:
  /// Initialization method.
  ACE_Pagefile_Memory_Pool_Options (
    void *base_addr = ACE_DEFAULT_PAGEFILE_POOL_BASE,
    size_t max_size = ACE_DEFAULT_PAGEFILE_POOL_SIZE);
  /// Base address of the memory-mapped backing store.
  void *base_addr_;
  /// Maximum size the pool may grow.
  size_t max_size_;
};
/**
 * @class ACE_Pagefile_Memory_Pool
 *
 * @brief Make a memory pool that is based on "anonymous" memory
 * regions allocated from the Win32 page file.
 */
class ACE_Export ACE_Pagefile_Memory_Pool
{
public:
  typedef ACE_Pagefile_Memory_Pool_Options OPTIONS;
  /// Initialize the pool.
  ACE_Pagefile_Memory_Pool (const ACE_TCHAR *backing_store_name = 0,
                            const OPTIONS *options = 0);
  /// Ask system for initial chunk of shared memory.
  void *init_acquire (size_t nbytes,
                      size_t &rounded_bytes,
                      int &first_time);
  /// Acquire at least @a nbytes from the memory pool.  <rounded_bytes>
  /// is the actual number of bytes allocated.
  void *acquire (size_t nbytes,
                 size_t &rounded_bytes);
  /// Instruct the memory pool to release all of its resources.
  int release (int destroy = 1);
  /**
   * Win32 Structural exception selector.  The return value decides
   * how to handle memory pool related structural exceptions.  Returns
   * 1, 0, or , -1.
   */
  virtual int seh_selector (void *);
  /**
   * Try to extend the virtual address space so that @a addr is now
   * covered by the address mapping.  The method succeeds and returns
   * 0 if the backing store has adequate memory to cover this address.
   * Otherwise, it returns -1.  This method is typically called by an
   * exception handler for a Win32 structured exception when another
   * process has grown the backing store (and its mapping) and our
   * process now incurs a fault because our mapping isn't in range
   * (yet).
   */
  int remap (void *addr);
  /// Round up to system page size.
  size_t round_to_page_size (size_t nbytes);
  /// Round up to the chunk size required by the operation system
  size_t round_to_chunk_size (size_t nbytes);
  // = Don't need this methods here ...
  int sync (ssize_t = -1, int = MS_SYNC);
  int sync (void *, size_t, int = MS_SYNC);
  int protect (ssize_t = -1, int = PROT_RDWR);
  int protect (void *, size_t, int = PROT_RDWR);
  /// Return the base address of this memory pool, 0 if base_addr
  /// never changes.
  virtual void *base_addr (void) const;
  void dump (void) const {}
protected:
  /**
   * Map portions or the entire pool into the local virtual address
   * space.  To do this, we compute the new @c file_offset of the
   * backing store and commit the memory.
   */
  int map (int &firstTime, size_t appendBytes = 0);
  /// Release the mapping.
  int unmap (void);
private:
  /**
   * @class Control_Block
   *
   * @brief Attributes that are meaningful in local storage only.
   */
  class Control_Block
  {
  public:
    /// Required base address
    void *req_base_;
    /// Base address returned from system call
    void *mapped_base_;
    /**
     * @class Shared_Control_Block
     *
     * @brief Pool statistics
     */
    class Shared_Control_Block
    {
    public:
      /// Maximum size the pool may grow
      size_t max_size_;
      /// Size of mapped shared memory segment
      size_t mapped_size_;
      /// Offset to mapped but not yet acquired address space
      ptrdiff_t free_offset_;
      /// Size of mapped but not yet acquired address space
      size_t free_size_;
    };
    Shared_Control_Block sh_;
  };
  // Base of mapped region.  If this has the value of 0 then the OS is
  // free to select any address to map the file, otherwise this value
  // is what the OS must try to use to mmap the file.
  /// Description of what our process mapped.
  Control_Block local_cb_;
  /// Shared memory pool statistics.
  Control_Block *shared_cb_;
  /// File mapping handle.
  ACE_HANDLE object_handle_;
  /// System page size.
  size_t page_size_;
  /// Name of the backing store where the shared memory pool is kept.
  ACE_TCHAR backing_store_name_[MAXPATHLEN];
};
ACE_END_VERSIONED_NAMESPACE_DECL
#endif /* ACE_WIN32 && !ACE_HAS_PHARLAP */
#if defined (__ACE_INLINE__)
#include "ace/Pagefile_Memory_Pool.inl"
#endif /* __ACE_INLINE__ */
#include /**/ "ace/post.h"
#endif /* ACE_MEMORY_POOL_H */

