// -*- C++ -*-

//==========================================================================
/**
 *  @file    Malloc_T.h
 *
 *  $Id: Malloc_T.h 92085 2010-09-29 12:23:13Z johnnyw $
 *
 *  @author Douglas C. Schmidt <schmidt@cs.wustl.edu> and
 *          Irfan Pyarali <irfan@cs.wustl.edu>
 */
//==========================================================================

#ifndef ACE_MALLOC_T_H
#define ACE_MALLOC_T_H
#include /**/ "ace/pre.h"

#include "ace/Malloc.h"               /* Need ACE_Control_Block */
#include "ace/Malloc_Base.h"          /* Need ACE_Allocator */

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/Malloc_Allocator.h"
#include "ace/Free_List.h"
#include "ace/Guard_T.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class ACE_Cached_Mem_Pool_Node
 *
 * @brief ACE_Cached_Mem_Pool_Node keeps unused memory within a free
 * list.
 *
 * The length of a piece of unused memory must be greater than
 * sizeof (void*).  This makes sense because we'll waste even
 * more memory if we keep them in a separate data structure.
 * This class should really be placed within the ACE_Cached_Allocator
 * class but this can't be done due to C++ compiler portability problems.
 */
template <class T>
class ACE_Cached_Mem_Pool_Node
{
public:
  /// Return the address of free memory.
  T *addr (void);

  /// Get the next ACE_Cached_Mem_Pool_Node in a list.
  ACE_Cached_Mem_Pool_Node<T> *get_next (void);

  /// Set the next ACE_Cached_Mem_Pool_Node.
  void set_next (ACE_Cached_Mem_Pool_Node<T> *ptr);

private:
  /**
   * Since memory is not used when placed in a free list,
   * we can use it to maintain the structure of free list.
   * I was using union to hide the fact of overlapping memory
   * usage.  However, that cause problem on MSVC.  So, I now turn
   * back to hack this with casting.
   */
  ACE_Cached_Mem_Pool_Node<T> *next_;
};

/**
 * @class ACE_Cached_Allocator
 *
 * @brief A fixed-size allocator that caches items for quicker access.
 *
 * This class enables caching of dynamically allocated,
 * fixed-sized classes.  Notice that the <code>sizeof (TYPE)</code>
 * must be greater than or equal to <code> sizeof (void*) </code> for
 * this to work properly.
 *
 * This class can be configured flexibly with different types of
 * ACE_LOCK strategies that support the @a ACE_Thread_Mutex,
 * @a ACE_Thread_Semaphore, @a ACE_Process_Mutex, and @a
 * ACE_Process_Semaphore constructor API.
 *
 * @sa ACE_Dynamic_Cached_Allocator
 */
template <class T, class ACE_LOCK>
class ACE_Cached_Allocator : public ACE_New_Allocator
{
public:
  /// Create a cached memory pool with @a n_chunks chunks
  /// each with sizeof (TYPE) size.
  ACE_Cached_Allocator (size_t n_chunks);

  /// Clear things up.
  ~ACE_Cached_Allocator (void);

  /**
   * Get a chunk of memory from free list cache.  Note that @a nbytes is
   * only checked to make sure that it's less or equal to sizeof T, and is
   * otherwise ignored since @c malloc() always returns a pointer to an
   * item of sizeof (T).
   */
  void *malloc (size_t nbytes = sizeof (T));

  /**
   * Get a chunk of memory from free list cache, giving them
   * @a initial_value.  Note that @a nbytes is only checked to make sure
   * that it's less or equal to sizeof T, and is otherwise ignored since
   * calloc() always returns a pointer to an item of sizeof (T).
   */
  virtual void *calloc (size_t nbytes,
                        char initial_value = '\0');

  /// This method is a no-op and just returns 0 since the free list
  /// only works with fixed sized entities.
  virtual void *calloc (size_t n_elem,
                        size_t elem_size,
                        char initial_value = '\0');

  /// Return a chunk of memory back to free list cache.
  void free (void *);

  /// Return the number of chunks available in the cache.
  size_t pool_depth (void);

private:
  /// Remember how we allocate the memory in the first place so
  /// we can clear things up later.
  char *pool_;

  /// Maintain a cached memory free list.
  ACE_Locked_Free_List<ACE_Cached_Mem_Pool_Node<T>, ACE_LOCK> free_list_;
};

/**
 * @class ACE_Dynamic_Cached_Allocator
 *
 * @brief A size-based allocator that caches blocks for quicker access.
 *
 * This class enables caching of dynamically allocated,
 * fixed-size chunks.  Notice that the <code>chunk_size</code>
 * must be greater than or equal to <code> sizeof (void*) </code> for
 * this to work properly.
 *
 * This class can be configured flexibly with different types of
 * ACE_LOCK strategies that support the @a ACE_Thread_Mutex and @a
 * ACE_Process_Mutex constructor API.
 *
 * @sa ACE_Cached_Allocator
 */
template <class ACE_LOCK>
class ACE_Dynamic_Cached_Allocator : public ACE_New_Allocator
{
public:
  /// Create a cached memory pool with @a n_chunks chunks
  /// each with @a chunk_size size.
  ACE_Dynamic_Cached_Allocator (size_t n_chunks, size_t chunk_size);

  /// Clear things up.
  ~ACE_Dynamic_Cached_Allocator (void);

  /**
   * Get a chunk of memory from free list cache.  Note that @a nbytes is
   * only checked to make sure that it's less or equal to @a chunk_size,
   * and is otherwise ignored since malloc() always returns a pointer to an
   * item of @a chunk_size size.
   */
  void *malloc (size_t nbytes = 0);

  /**
   * Get a chunk of memory from free list cache, giving them
   * @a initial_value.  Note that @a nbytes is only checked to make sure
   * that it's less or equal to @a chunk_size, and is otherwise ignored
   * since calloc() always returns a pointer to an item of @a chunk_size.
   */
  virtual void *calloc (size_t nbytes,
                        char initial_value = '\0');

  /// This method is a no-op and just returns 0 since the free list
  /// only works with fixed sized entities.
  virtual void *calloc (size_t n_elem,
                        size_t elem_size,
                        char initial_value = '\0');

  /// Return a chunk of memory back to free list cache.
  void free (void *);

  /// Return the number of chunks available in the cache.
  size_t pool_depth (void);

private:
  /// Remember how we allocate the memory in the first place so
  /// we can clear things up later.
  char *pool_;

  /// Maintain a cached memory free list. We use @c char as template
  /// parameter, although sizeof(char) is usually less than
  /// sizeof(void*). Really important is that @a chunk_size
  /// must be greater or equal to sizeof(void*).
  ACE_Locked_Free_List<ACE_Cached_Mem_Pool_Node<char>, ACE_LOCK> free_list_;

  /// Remember the size of our chunks.
  size_t chunk_size_;
};

/**
 * @class ACE_Allocator_Adapter
 *
 * @brief This class is an adapter that allows the ACE_Allocator to
 * use the ACE_Malloc class below.
 */
template <class MALLOC>
class ACE_Allocator_Adapter : public ACE_Allocator
{
public:
  // Trait.
  typedef MALLOC ALLOCATOR;
  typedef const typename MALLOC::MEMORY_POOL_OPTIONS *MEMORY_POOL_OPTIONS;

  // = Initialization.
  /**
   * Note that @a pool_name should be located in
   * a directory with the appropriate visibility and protection so
   * that all processes that need to access it can do so. */
  ACE_Allocator_Adapter (const char *pool_name = 0);

  /**
   * Note that @a pool_name should be located in
   * a directory with the appropriate visibility and protection so
   * that all processes that need to access it can do so.
   */
  ACE_Allocator_Adapter (const char *pool_name,
                         const char *lock_name,
                         MEMORY_POOL_OPTIONS options = 0);

#if defined (ACE_HAS_WCHAR)
  /**
   * Note that @a pool_name should be located in
   * a directory with the appropriate visibility and protection so
   * that all processes that need to access it can do so. */
  ACE_Allocator_Adapter (const wchar_t *pool_name);

  /**
   * Note that @a pool_name should be located in
   * a directory with the appropriate visibility and protection so
   * that all processes that need to access it can do so.
   */
  ACE_Allocator_Adapter (const wchar_t *pool_name,
                         const wchar_t *lock_name,
                         MEMORY_POOL_OPTIONS options = 0);
#endif /* ACE_HAS_WCHAR */

  /// Destructor.
  virtual ~ACE_Allocator_Adapter (void);

  // = Memory Management

  /// Allocate @a nbytes, but don't give them any initial value.
  virtual void *malloc (size_t nbytes);

  /// Allocate @a nbytes, giving them all an @a initial_value.
  virtual void *calloc (size_t nbytes, char initial_value = '\0');

  /// Allocate @a n_elem each of size @a elem_size, giving them
  /// @a initial_value.
  virtual void *calloc (size_t n_elem,
                        size_t elem_size,
                        char initial_value = '\0');

  /// Free @a ptr (must have been allocated by ACE_Allocator::malloc()).
  virtual void free (void *ptr);

  /// Remove any resources associated with this memory manager.
  virtual int remove (void);

  // = Map manager like functions

  /**
   * Associate @a name with @a pointer.  If @a duplicates == 0 then do
   * not allow duplicate @a name/pointer associations, else if
   * @a duplicates != 0 then allow duplicate @a name/pointer
   * associations.  Returns 0 if successfully binds (1) a previously
   * unbound @a name or (2) @a duplicates != 0, returns 1 if trying to
   * bind a previously bound @a name and @a duplicates == 0, else
   * returns -1 if a resource failure occurs.
   */
  virtual int bind (const char *name, void *pointer, int duplicates = 0);

  /**
   * Associate @a name with @a pointer.  Does not allow duplicate
   * name/pointer associations.  Returns 0 if successfully binds
   * (1) a previously unbound @a name, 1 if trying to bind a previously
   * bound @a name, or returns -1 if a resource failure occurs.  When
   * this call returns, @a pointer's value will always reference the
   * void * that @a name is associated with.  Thus, if the caller needs
   * to use @a pointer (e.g., to free it) a copy must be maintained by
   * the caller.
   */
  virtual int trybind (const char *name, void *&pointer);

  /// Locate @a name and pass out parameter via pointer.  If found,
  /// return 0, returns -1 if @a name isn't found.
  virtual int find (const char *name, void *&pointer);

  /// Returns 0 if the name is in the mapping and -1 if not.
  virtual int find (const char *name);

  /// Unbind (remove) the name from the map.  Don't return the pointer
  /// to the caller
  virtual int unbind (const char *name);

  /// Break any association of name.  Returns the value of pointer in
  /// case the caller needs to deallocate memory.
  virtual int unbind (const char *name, void *&pointer);

  // = Protection and "sync" (i.e., flushing data to backing store).

  /**
   * Sync @a len bytes of the memory region to the backing store
   * starting at @c this->base_addr_.  If @a len == -1 then sync the
   * whole region.
   */
  virtual int sync (ssize_t len = -1, int flags = MS_SYNC);

  /// Sync @a len bytes of the memory region to the backing store
  /// starting at @c addr_.
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

  /// Returns the underlying allocator.
  ALLOCATOR &alloc (void);

#if defined (ACE_HAS_MALLOC_STATS)
  /// Dump statistics of how malloc is behaving.
  virtual void print_stats (void) const;
#endif /* ACE_HAS_MALLOC_STATS */

  /// Dump the state of the object.
  virtual void dump (void) const;

private:
  /// ALLOCATOR instance, which is owned by the adapter.
  ALLOCATOR allocator_;
};

/**
 * @class ACE_Static_Allocator
 *
 * @brief Defines a class that provided a highly optimized memory
 * management scheme for allocating memory statically.
 *
 * This class allocates a fixed-size @c POOL_SIZE of memory and
 * uses the ACE_Static_Allocator_Base class implementations of
 * malloc() and calloc() to optimize memory allocation from this
 * pool.
 */
template <size_t POOL_SIZE>
class ACE_Static_Allocator : public ACE_Static_Allocator_Base
{
public:
  ACE_Static_Allocator (void)
    : ACE_Static_Allocator_Base (pool_, POOL_SIZE)
  {
    // This function <{must}> be inlined!!!
  }

private:
  /// Pool contents.
  char pool_[POOL_SIZE];
};

// Forward declaration.
template <ACE_MEM_POOL_1, class ACE_LOCK, class ACE_CB>
class ACE_Malloc_LIFO_Iterator_T;

// Ensure backwards compatibility...
#define ACE_Malloc_Iterator ACE_Malloc_LIFO_Iterator

// Forward declaration.
template <ACE_MEM_POOL_1, class ACE_LOCK, class ACE_CB>
class ACE_Malloc_FIFO_Iterator_T;

/**
 * @class ACE_Malloc_T
 *
 * @brief A class template that uses parameterized types to provide
 * an extensible mechanism for encapsulating various dynamic
 * memory management strategies.
 *
 * This class can be configured flexibly with different
 * MEMORY_POOL strategies and different types of ACE_LOCK
 * strategies that support the ACE_Thread_Mutex and ACE_Process_Mutex
 * constructor API.
 *
 * Common MEMORY_POOL strategies to use with this class are:
 *   - ACE_Local_Memory_Pool
 *   - ACE_MMAP_Memory_Pool
 *   - ACE_Pagefile_Memory_Pool
 *   - ACE_Shared_Memory_Pool
 *   - ACE_Sbrk_Memory_Pool
 *
 * The MEMORY_POOL class must provide the following methods:
 *   - constructor (const ACE_TCHAR *pool_name)
 *   - constructor (const ACE_TCHAR *pool_name, const MEMORY_POOL_OPTIONS *options)
 *   - void dump (void) const (needed if ACE is built with ACE_HAS_DUMP defined)
 *   - void *init_acquire (size_t nbytes, size_t &rounded_bytes, int &first_time);
 *   - int release (void)
 *   - void *acquire (size_t nbytes, size_t &rounded_bytes)
 *   - void *base_addr (void)
 *   - seh_selector() (only needed on Windows)
 *
 * Note that the ACE_Allocator_Adapter class can be used to integrate allocator
 * classes which do not meet the interface requirements of ACE_Malloc_T.
 *
 * @Note The bind() and find() methods use linear search, so
 * it's not a good idea to use them for managing a large number of
 * entities.  If you need to manage a large number of entities, it's
 * recommended that you bind() an ACE_Hash_Map_Manager that
 * resides in shared memory, use find() to locate it, and then
 * store/retrieve the entities in the hash map.
 */
template <ACE_MEM_POOL_1, class ACE_LOCK, class ACE_CB>
class ACE_Malloc_T
{
public:
  friend class ACE_Malloc_LIFO_Iterator_T<ACE_MEM_POOL_2, ACE_LOCK, ACE_CB>;
  friend class ACE_Malloc_FIFO_Iterator_T<ACE_MEM_POOL_2, ACE_LOCK, ACE_CB>;
  typedef ACE_MEM_POOL MEMORY_POOL;
  typedef ACE_MEM_POOL_OPTIONS MEMORY_POOL_OPTIONS;
  typedef typename ACE_CB::ACE_Name_Node NAME_NODE;
  typedef typename ACE_CB::ACE_Malloc_Header MALLOC_HEADER;

  // = Initialization and termination methods.
  /**
   * Initialize ACE_Malloc.  This constructor passes @a pool_name to
   * initialize the memory pool, and uses ACE::basename() to
   * automatically extract out the name used for the underlying lock
   * name (if necessary).
   *
   * Note that @a pool_name should be located in
   * a directory with the appropriate visibility and protection so
   * that all processes that need to access it can do so.
   */
  ACE_Malloc_T (const ACE_TCHAR *pool_name = 0);

  /**
   * Initialize ACE_Malloc.  This constructor passes @a pool_name to
   * initialize the memory pool, and uses @a lock_name to automatically
   * extract out the name used for the underlying lock name (if
   * necessary).  In addition, @a options is passed through to
   * initialize the underlying memory pool.
   *
   * Note that @a pool_name should be located in
   * a directory with the appropriate visibility and protection so
   * that all processes that need to access it can do so.
   */
  ACE_Malloc_T (const ACE_TCHAR *pool_name,
                const ACE_TCHAR *lock_name,
                const ACE_MEM_POOL_OPTIONS *options = 0);

  /**
   * Initialize an ACE_Malloc with an external ACE_LOCK.
   * This constructor passes @a pool_name and @a options to initialize
   * the memory pool. @a lock is used as the pool lock, and must be
   * properly set up and ready for use before being passed to this method.
   */
  ACE_Malloc_T (const ACE_TCHAR *pool_name,
                const ACE_MEM_POOL_OPTIONS *options,
                ACE_LOCK *lock);

  /// Destructor
  ~ACE_Malloc_T (void);

  /// Get Reference counter.
  int ref_counter (void);

  /// Release ref counter.
  int release (int close = 0);

  /// Releases resources allocated by this object.
  int remove (void);

  // = Memory management

  /// Allocate @a nbytes, but don't give them any initial value.
  void *malloc (size_t nbytes);

  /// Allocate @a nbytes, giving them @a initial_value.
  void *calloc (size_t nbytes, char initial_value = '\0');

  /// Allocate @a n_elem each of size @a elem_size, giving them
  /// @a initial_value.
  void *calloc (size_t n_elem,
                size_t elem_size,
                char initial_value = '\0');

  /// Deallocate memory pointed to by @a ptr, which must have been
  /// allocated previously by malloc().
  void free (void *ptr);

  /// Returns a reference to the underlying memory pool.
  MEMORY_POOL &memory_pool (void);

  // = Map manager like functions

  /**
   * Associate @a name with @a pointer.  If @a duplicates == 0 then do
   * not allow duplicate name/pointer associations, else if
   * @a duplicates != 0 then allow duplicate name/pointer
   * associations.  Returns 0 if successfully binds (1) a previously
   * unbound @a name or (2) @a duplicates != 0, returns 1 if trying to
   * bind a previously bound @a name and @a duplicates == 0, else
   * returns -1 if a resource failure occurs.
   */
  int bind (const char *name, void *pointer, int duplicates = 0);

  /**
   * Associate @a name with @a pointer.  Does not allow duplicate
   * name/pointer associations.  Returns 0 if successfully binds
   * (1) a previously unbound @a name, 1 if trying to bind a previously
   * bound @a name, or returns -1 if a resource failure occurs.  When
   * this call returns @a pointer's value will always reference the
   * void * that @a name is associated with.  Thus, if the caller needs
   * to use @a pointer (e.g., to free it) a copy must be maintained by
   * the caller.
   */
  int trybind (const char *name, void *&pointer);

  /// Locate @a name and pass out parameter via @a pointer.  If found,
  /// return 0, returns -1 if failure occurs.
  int find (const char *name, void *&pointer);

  /// Returns 0 if @a name is in the mapping. -1, otherwise.
  int find (const char *name);

  /**
   * Unbind (remove) the name from the map.  Don't return the pointer
   * to the caller.  If you want to remove all occurrences of @a name
   * you'll need to call this method multiple times until it fails...
   */
  int unbind (const char *name);

  /**
   * Unbind (remove) one association of @a name to @a pointer.  Returns
   * the value of pointer in case the caller needs to deallocate
   * memory.  If you want to remove all occurrences of @a name you'll
   * need to call this method multiple times until it fails...
   */
  int unbind (const char *name, void *&pointer);

  // = Protection and "sync" (i.e., flushing data to backing store).

  /**
   * Sync @a len bytes of the memory region to the backing store
   * starting at @c this->base_addr_.  If @a len == -1 then sync the
   * whole region.
   */
  int sync (ssize_t len = -1, int flags = MS_SYNC);

  /// Sync @a len bytes of the memory region to the backing store
  /// starting at @c addr_.
  int sync (void *addr, size_t len, int flags = MS_SYNC);

  /**
   * Change the protection of the pages of the mapped region to @a prot
   * starting at @c this->base_addr_ up to @a len bytes.  If @a len == -1
   * then change protection of all pages in the mapped region.
   */
  int protect (ssize_t len = -1, int prot = PROT_RDWR);

  /// Change the protection of the pages of the mapped region to @a prot
  /// starting at @a addr up to @a len bytes.
  int protect (void *addr, size_t len, int prot = PROT_RDWR);

  /**
   * Returns a count of the number of available chunks that can hold
   * @a size byte allocations.  Function can be used to determine if you
   * have reached a water mark. This implies a fixed amount of allocated
   * memory.
   *
   * @param size  The chunk size of that you would like a count of
   * @return Function returns the number of chunks of the given size
   *          that would fit in the currently allocated memory.
   */
  ssize_t avail_chunks (size_t size) const;

#if defined (ACE_HAS_MALLOC_STATS)
  /// Dump statistics of how malloc is behaving.
  void print_stats (void) const;
#endif /* ACE_HAS_MALLOC_STATS */

  /// Returns a pointer to the lock used to provide mutual exclusion to
  /// an ACE_Malloc allocator.
  ACE_LOCK &mutex (void);

  /// Dump the state of an object.
  void dump (void) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

  /// Return cb_ptr value.
  void *base_addr (void);

  /**
   * Bad flag.  This operation should be called immediately after the
   * construction of the Malloc object to query whether the object was
   * constructed successfully.  If not, the user should invoke @c
   * remove and release the object (it is not usable.)
   * @retval 0 if all is fine.  non-zero if this malloc object is
   *         unuable.
   */
  int bad (void);

private:
  /// Initialize the Malloc pool.
  int open (void);

  /// Associate @a name with @a pointer.  Assumes that locks are held by
  /// callers.
  int shared_bind (const char *name,
                   void *pointer);

  /**
   * Try to locate @a name.  If found, return the associated
   * ACE_Name_Node, else returns 0 if can't find the @a name.
   * Assumes that locks are held by callers.  Remember to cast the
   * return value to ACE_CB::ACE_Name_Node*.
   */
  void *shared_find (const char *name);

  /// Allocate memory.  Assumes that locks are held by callers.
  void *shared_malloc (size_t nbytes);

  /// Deallocate memory.  Assumes that locks are held by callers.
  void shared_free (void *ptr);

  /// Pointer to the control block that is stored in memory controlled
  /// by <MEMORY_POOL>.
  ACE_CB *cb_ptr_;

  /// Pool of memory used by ACE_Malloc to manage its freestore.
  MEMORY_POOL memory_pool_;

  /// Lock that ensures mutual exclusion for the memory pool.
  ACE_LOCK *lock_;

  /// True if destructor should delete the lock
  bool delete_lock_;

  /// Keep track of failure in constructor.
  int bad_flag_;
};

/*****************************************************************************/

/**
 * @class ACE_Malloc_Lock_Adapter_T
 *
 * @brief Template functor adapter for lock strategies used with ACE_Malloc_T.
 *
 * This class acts as a factory for lock strategies that have various ctor
 * signatures.  If the lock strategy's ctor takes an ACE_TCHAR* as the first
 * and only required parameter, it will just work.  Otherwise use template
 * specialization to create a version that matches the lock strategy's ctor
 * signature.  See ACE_Process_Semaphore and ACE_Thread_Semaphore for
 * examples.
 *
 */
/*****************************************************************************/

/**
 * @class ACE_Malloc_LIFO_Iterator_T
 *
 * @brief LIFO iterator for names stored in Malloc'd memory.
 *
 * This class can be configured flexibly with different types of
 * ACE_LOCK strategies that support the @a ACE_Thread_Mutex and @a
 * ACE_Process_Mutex constructor API.
 *
 * Does not support deletions while iteration is occurring.
 */
template <ACE_MEM_POOL_1, class ACE_LOCK, class ACE_CB>
class ACE_Malloc_LIFO_Iterator_T
{
public:
  typedef typename ACE_CB::ACE_Name_Node NAME_NODE;
  typedef typename ACE_CB::ACE_Malloc_Header MALLOC_HEADER;

  // = Initialization method.
  /// If @a name = 0 it will iterate through everything else only
  /// through those entries whose @a name match.
  ACE_Malloc_LIFO_Iterator_T (ACE_Malloc_T<ACE_MEM_POOL_2, ACE_LOCK, ACE_CB> &malloc,
                              const char *name = 0);

  /// Destructor.
  ~ACE_Malloc_LIFO_Iterator_T (void);

  // = Iteration methods.

  /// Returns 1 when all items have been seen, else 0.
  int done (void) const;

  /// Pass back the next entry in the set that hasn't yet been
  /// visited.  Returns 0 when all items have been seen, else 1.
  int next (void *&next_entry);

  /**
   * Pass back the next entry (and the name associated with it) in
   * the set that hasn't yet been visited.  Returns 0 when all items
   * have been seen, else 1.
   */
  int next (void *&next_entry, const char *&name);

  /// Move forward by one element in the set.  Returns 0 when all the
  /// items in the set have been seen, else 1.
  int advance (void);

  /// Dump the state of an object.
  void dump (void) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

private:
  /// Malloc we are iterating over.
  ACE_Malloc_T<ACE_MEM_POOL_2, ACE_LOCK, ACE_CB> &malloc_;

  /// Keeps track of how far we've advanced...
  NAME_NODE *curr_;

// FUZZ: disable check_for_ACE_Guard
  /// Lock Malloc for the lifetime of the iterator.
  ACE_Read_Guard<ACE_LOCK> guard_;
// FUZZ: enable check_for_ACE_Guard

  /// Name that we are searching for.
  const char *name_;
};

/**
 * @class ACE_Malloc_FIFO_Iterator_T
 *
 * @brief FIFO iterator for names stored in Malloc'd memory.
 *
 * This class can be configured flexibly with different types of
 * ACE_LOCK strategies that support the @a ACE_Thread_Mutex and @a
 * ACE_Process_Mutex constructor API.
 *
 * Does not support deletions while iteration is occurring.
 */
template <ACE_MEM_POOL_1, class ACE_LOCK, class ACE_CB>
class ACE_Malloc_FIFO_Iterator_T
{
public:
  typedef typename ACE_CB::ACE_Name_Node NAME_NODE;
  typedef typename ACE_CB::ACE_Malloc_Header MALLOC_HEADER;

  /// If @a name = 0 it will iterate through everything else only
  /// through those entries whose @a name match.
  ACE_Malloc_FIFO_Iterator_T (ACE_Malloc_T<ACE_MEM_POOL_2, ACE_LOCK, ACE_CB> &malloc,
                              const char *name = 0);

  /// Destructor.
  ~ACE_Malloc_FIFO_Iterator_T (void);

  // = Iteration methods.

  /// Returns 1 when all items have been seen, else 0.
  int done (void) const;

  /// Pass back the next entry in the set that hasn't yet been
  /// visited.  Returns 0 when all items have been seen, else 1.
  int next (void *&next_entry);

  /**
   * Pass back the next entry (and the name associated with it) in
   * the set that hasn't yet been visited.  Returns 0 when all items
   * have been seen, else 1.
   */
  int next (void *&next_entry, const char *&name);

  /// Move forward by one element in the set.  Returns 0 when all the
  /// items in the set have been seen, else 1.
  int advance (void);

  /// Go to the starting element that was inserted first. Returns 0
  /// when there is no item in the set, else 1.
  int start (void);

  /// Dump the state of an object.
  void dump (void) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

private:
  /// Malloc we are iterating over.
  ACE_Malloc_T<ACE_MEM_POOL_2, ACE_LOCK, ACE_CB> &malloc_;

  /// Keeps track of how far we've advanced...
  NAME_NODE *curr_;

// FUZZ: disable check_for_ACE_Guard
  /// Lock Malloc for the lifetime of the iterator.
  ACE_Read_Guard<ACE_LOCK> guard_;
// FUZZ: enable check_for_ACE_Guard

  /// Name that we are searching for.
  const char *name_;
};

template <ACE_MEM_POOL_1, class ACE_LOCK>
class ACE_Malloc : public ACE_Malloc_T<ACE_MEM_POOL_2, ACE_LOCK, ACE_Control_Block>
{
public:
  // = Initialization and termination methods.
  /**
   * Initialize ACE_Malloc.  This constructor passes @a pool_name to
   * initialize the memory pool, and uses ACE::basename() to
   * automatically extract out the name used for the underlying lock
   * name (if necessary).  Note that @a pool_name should be located in
   * a directory with the appropriate visibility and protection so
   * that all processes that need to access it can do so.
   */
  ACE_Malloc (const ACE_TCHAR *pool_name = 0);

  /**
   * Initialize ACE_Malloc.  This constructor passes @a pool_name to
   * initialize the memory pool, and uses @a lock_name to automatically
   * extract out the name used for the underlying lock name (if
   * necessary).  In addition, @a options is passed through to
   * initialize the underlying memory pool.  Note that @a pool_name
   * should be located in a directory with the appropriate visibility
   * and protection so that all processes that need to access it can
   * do so.
   */
  ACE_Malloc (const ACE_TCHAR *pool_name,
              const ACE_TCHAR *lock_name,
              const ACE_MEM_POOL_OPTIONS *options = 0);
};

template <ACE_MEM_POOL_1, class ACE_LOCK>
class ACE_Malloc_LIFO_Iterator : public ACE_Malloc_LIFO_Iterator_T<ACE_MEM_POOL_2, ACE_LOCK, ACE_Control_Block>
{
public:
  /// If @a name = 0 it will iterate through everything else only
  /// through those entries whose @a name match.
  ACE_Malloc_LIFO_Iterator (ACE_Malloc<ACE_MEM_POOL_2, ACE_LOCK> &malloc,
                            const char *name = 0);
};

template <ACE_MEM_POOL_1, class ACE_LOCK>
class ACE_Malloc_FIFO_Iterator : public ACE_Malloc_FIFO_Iterator_T<ACE_MEM_POOL_2, ACE_LOCK, ACE_Control_Block>
{
public:
  /// If @a name = 0 it will iterate through everything else only
  /// through those entries whose @a name match.
  ACE_Malloc_FIFO_Iterator (ACE_Malloc<ACE_MEM_POOL_2, ACE_LOCK> &malloc,
                            const char *name = 0);
};

template <class ACE_LOCK>
class ACE_Malloc_Lock_Adapter_T
{
public:
  ACE_LOCK * operator () (const ACE_TCHAR *myname);
};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ace/Malloc_T.inl"
#endif /* __ACE_INLINE__ */

#if defined (ACE_TEMPLATES_REQUIRE_SOURCE)
#include "ace/Malloc_T.cpp"
#endif /* ACE_TEMPLATES_REQUIRE_SOURCE */

#if defined (ACE_TEMPLATES_REQUIRE_PRAGMA)
#pragma implementation ("Malloc_T.cpp")
#endif /* ACE_TEMPLATES_REQUIRE_PRAGMA */

#include /**/ "ace/post.h"
#endif /* ACE_MALLOC_H */
