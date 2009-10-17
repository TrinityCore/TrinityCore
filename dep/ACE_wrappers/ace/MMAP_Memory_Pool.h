// -*- C++ -*-
//=============================================================================
/**
 *  @file     MMAP_Memory_Pool.h
 *
 *  $Id: MMAP_Memory_Pool.h 81589 2008-05-02 13:07:33Z johnnyw $
 *
 *  @author Dougls C. Schmidt <schmidt@cs.wustl.edu>
 *  @author Prashant Jain <pjain@cs.wustl.edu>
 */
//=============================================================================
#ifndef ACE_MMAP_MEMORY_POOL_H
#define ACE_MMAP_MEMORY_POOL_H
#include /**/ "ace/pre.h"
#include /**/ "ace/ACE_export.h"
#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */
#include "ace/ACE.h"
#include "ace/Event_Handler.h"
#include "ace/Sig_Handler.h"
#include "ace/Mem_Map.h"
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
/**
 * @class ACE_MMAP_Memory_Pool_Options
 *
 * @brief Helper class for MMAP Memory Pool constructor options.
 *
 * This should be a nested class, but that breaks too many
 * compilers.
 */
class ACE_Export ACE_MMAP_Memory_Pool_Options
{
public:
  enum
  {
    /**
     * The base address from the first call to mmap will be used for subsequent
     * calls to mmap.
     */
    FIRSTCALL_FIXED = 0,
    /**
     * The base address specified in base_addr will be used in all calls to
     * mmap.
     */
    ALWAYS_FIXED = 1,
    /**
     * The base address will be selected by the OS for each call to mmap.
     * Caution should be used with this mode since a call that requires the
     * backing store to grow may change pointers that are cached by the
     * application.
     */
    NEVER_FIXED = 2
  };
  /// Constructor
  ACE_MMAP_Memory_Pool_Options (const void *base_addr = ACE_DEFAULT_BASE_ADDR,
                                int use_fixed_addr = ALWAYS_FIXED,
                                bool write_each_page = true,
                                size_t minimum_bytes = 0,
                                u_int flags = 0,
                                bool guess_on_fault = true,
                                LPSECURITY_ATTRIBUTES sa = 0,
                                mode_t file_mode = ACE_DEFAULT_FILE_PERMS,
                                bool unique_ = false,
                                bool install_signal_handler = true);
  /// Base address of the memory-mapped backing store.
  const void *base_addr_;
  /**
   * Determines whether we set @c base_addr_ or if mmap(2) selects it
   * FIRSTCALL_FIXED The base address from the first call to mmap
   *                 will be used for subsequent calls to mmap
   * ALWAYS_FIXED    The base address specified in base_addr will be
   *                 used in all calls to mmap.
   * NEVER_FIXED     The base address will be selected by the OS for
   *                 each call to mmap. Caution should be used with
   *                 this mode since a call that requires the backing
   *                 store to grow may change pointers that are
   *                 cached by the application.
   */
  int use_fixed_addr_;
  /// Should each page be written eagerly to avoid surprises later
  /// on?
  bool write_each_page_;
  /// What the minimim bytes of the initial segment should be.
  size_t minimum_bytes_;
  /// Any special flags that need to be used for @c mmap.
  u_int flags_;
  /**
   * Try to remap without knowing the faulting address.  This
   * parameter is ignored on platforms that know the faulting address
   * (UNIX with SI_ADDR and Win32).
   */
  bool guess_on_fault_;
  /// Pointer to a security attributes object.  Only used on NT.
  LPSECURITY_ATTRIBUTES sa_;
  /// File mode for mmaped file, if it is created.
  mode_t file_mode_;
  /// Do we want an unique backing store name?
  bool unique_;
  /// Should we install a signal handler
  bool install_signal_handler_;
private:
  // Prevent copying
  ACE_MMAP_Memory_Pool_Options (const ACE_MMAP_Memory_Pool_Options &);
  ACE_MMAP_Memory_Pool_Options &operator= (const ACE_MMAP_Memory_Pool_Options &);
};
/**
 * @class ACE_MMAP_Memory_Pool
 *
 * @brief Make a memory pool that is based on @c mmap(2).  This
 * implementation allows memory to be shared between processes.
 */
class ACE_Export ACE_MMAP_Memory_Pool : public ACE_Event_Handler
{
public:
  typedef ACE_MMAP_Memory_Pool_Options OPTIONS;
  // = Initialization and termination methods.
  /// Initialize the pool.
  ACE_MMAP_Memory_Pool (const ACE_TCHAR *backing_store_name = 0,
                        const OPTIONS *options = 0);
  /// Destructor.
  virtual ~ACE_MMAP_Memory_Pool (void);
  /// Ask system for initial chunk of shared memory.
  virtual void *init_acquire (size_t nbytes,
                              size_t &rounded_bytes,
                              int &first_time);
  /**
   * Acquire at least @a nbytes from the memory pool. @a rounded_bytes
   * is the actual number of bytes allocated.  Also acquires an
   * internal semaphore that ensures proper serialization of
   * ACE_MMAP_Memory_Pool initialization across processes.
   */
  virtual void *acquire (size_t nbytes,
                         size_t &rounded_bytes);
  /// Instruct the memory pool to release all of its resources.
  virtual int release (int destroy = 1);
  /// Sync the memory region to the backing store starting at
  /// @c this->base_addr_.
  virtual int sync (size_t len, int flags = MS_SYNC);
  /// Sync the memory region to the backing store starting at
  /// @c this->base_addr_.  Will sync as much as the backing file
  /// allows.
  virtual int sync (int flags = MS_SYNC);
  /// Sync the memory region to the backing store starting at @a addr.
  virtual int sync (void *addr, size_t len, int flags = MS_SYNC);
  /**
   * Change the protection of the pages of the mapped region to @a prot
   * starting at @c this->base_addr_ up to @a len bytes.  If @a len == -1
   * then change protection of all pages in the mapped region.
   */
  virtual int protect (size_t len, int prot = PROT_RDWR);
  /**
   * Change the protection of all the pages of the mapped region to @a prot
   * starting at @c this->base_addr_.
   */
  virtual int protect (int prot = PROT_RDWR);
  /// Change the protection of the pages of the mapped region to @a prot
  /// starting at @a addr up to @a len bytes.
  virtual int protect (void *addr, size_t len, int prot = PROT_RDWR);
#if defined (ACE_WIN32)
  /**
   * Win32 Structural exception selector.  The return value decides
   * how to handle memory pool related structural exceptions.  Returns
   * 1, 0, or , -1.
   */
  virtual int seh_selector (void *);
#endif /* ACE_WIN32 */
  /**
   * Try to extend the virtual address space so that @a addr is now
   * covered by the address mapping.  The method succeeds and returns
   * 0 if the backing store has adequate memory to cover this address.
   * Otherwise, it returns -1.  This method is typically called by a
   * UNIX signal handler for SIGSEGV or a Win32 structured exception
   * when another process has grown the backing store (and its
   * mapping) and our process now incurs a fault because our mapping
   * isn't in range (yet).
   */
  virtual int remap (void *addr);
  /// Return the base address of this memory pool.
  virtual void *base_addr (void) const;
  /// Dump the state of an object.
  virtual void dump (void) const;
  /// Get reference to underlying ACE_Mem_Map object.
  ACE_Mem_Map const & mmap (void) const;
  /// Get reference to underlying ACE_Mem_Map object.
  ACE_Mem_Map & mmap (void);
  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;
protected:
  /// Implement the algorithm for rounding up the request to an
  /// appropriate chunksize.
  virtual size_t round_up (size_t nbytes);
  /// Compute the new @a map_size of the backing store and commit the
  /// memory.
  virtual int commit_backing_store_name (size_t rounded_bytes,
                                         size_t & map_size);
  /// Memory map the file up to @a map_size bytes.
  virtual int map_file (size_t map_size);
#if !defined (ACE_WIN32)
  /**
   * Handle SIGSEGV and SIGBUS signals to remap memory properly.  When a
   * process reads or writes to non-mapped memory a signal (SIGBUS or
   * SIGSEGV) will be triggered.  At that point, the ACE_Sig_Handler
   * (which is part of the ACE_Reactor) will catch the signal and
   * dispatch the handle_signal() method defined here.  If the SIGSEGV
   * signal occurred due to the fact that the mapping wasn't uptodate
   * with respect to the backing store, the handler method below will
   * update the mapping accordingly.  When the signal handler returns,
   * the instruction should be restarted and the operation should work.
   */
  virtual int handle_signal (int signum, siginfo_t *, ucontext_t *);
#endif
#if !defined (ACE_WIN32)
  /// Handles SIGSEGV.
  ACE_Sig_Handler signal_handler_;
#endif
  /// Memory-mapping object.
  ACE_Mem_Map mmap_;
  /**
   * Base of mapped region.  If this has the value of 0 then the OS is
   * free to select any address to map the file, otherwise this value
   * is what the OS must try to use to mmap the file.
   */
  void *base_addr_;
  /// Must we use the @c base_addr_ or can we let mmap(2) select it?
  int use_fixed_addr_;
  /// Flags passed into ACE_OS::mmap().
  int flags_;
  /// Should we write a byte to each page to forceably allocate memory
  /// for this backing store?
  bool write_each_page_;
  /// What the minimum bytes of the initial segment should be.
  size_t minimum_bytes_;
  /// Name of the backing store where the shared memory pool is kept.
  ACE_TCHAR backing_store_name_[MAXPATHLEN + 1];
  /**
   * Try to remap without knowing the faulting address.  This
   * parameter is ignored on platforms that know the faulting address
   * (UNIX with SI_ADDR and Win32).
   */
  bool guess_on_fault_;
  /// Security attributes object, only used on NT.
  LPSECURITY_ATTRIBUTES sa_;
  /// Protection mode for mmaped file.
  mode_t file_mode_;
  /// Should we install a signal handler
  bool install_signal_handler_;
};
/**
 * @class ACE_Lite_MMAP_Memory_Pool
 *
 * @brief Make a ``lighter-weight'' memory pool based ACE_Mem_Map.
 *
 * This implementation allows memory to be shared between
 * processes.  However, unlike the ACE_MMAP_Memory_Pool
 * the @c sync methods are no-ops, which means that we don't pay
 * for the price of flushing the memory to the backing store on
 * every update.  Naturally, this trades off increased
 * performance for less reliability if the machine crashes.
 */
class ACE_Export ACE_Lite_MMAP_Memory_Pool : public ACE_MMAP_Memory_Pool
{
public:
  /// Initialize the pool.
  ACE_Lite_MMAP_Memory_Pool (const ACE_TCHAR *backing_store_name = 0,
                             const OPTIONS *options = 0);
  /// Destructor.
  virtual ~ACE_Lite_MMAP_Memory_Pool (void);
  /// Overwrite the default sync behavior with no-op
  virtual int sync (size_t len, int flags = MS_SYNC);
  /// Overwrite the default sync behavior with no-op
  virtual int sync (int flags = MS_SYNC);
  /// Overwrite the default sync behavior with no-op
  virtual int sync (void *addr, size_t len, int flags = MS_SYNC);
};
ACE_END_VERSIONED_NAMESPACE_DECL
#if defined (__ACE_INLINE__)
#include "ace/MMAP_Memory_Pool.inl"
#endif /* __ACE_INLINE__ */
#include /**/ "ace/post.h"
#endif /* ACE_MMAP_MEMORY_POOL_H */

