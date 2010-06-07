// $Id: Malloc_T.cpp 84282 2009-01-30 15:04:29Z msmit $

#ifndef ACE_MALLOC_T_CPP
#define ACE_MALLOC_T_CPP

#include "ace/Malloc_T.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if !defined (__ACE_INLINE__)
#include "ace/Malloc_T.inl"
#endif /* __ACE_INLINE__ */

#include "ace/ACE.h"
#include "ace/OS_NS_string.h"


ACE_BEGIN_VERSIONED_NAMESPACE_DECL

template <class T, class ACE_LOCK>
ACE_Cached_Allocator<T, ACE_LOCK>::ACE_Cached_Allocator (size_t n_chunks)
  : pool_ (0),
    free_list_ (ACE_PURE_FREE_LIST)
{
  // To maintain alignment requirements, make sure that each element
  // inserted into the free list is aligned properly for the platform.
  // Since the memory is allocated as a char[], the compiler won't help.
  // To make sure enough room is allocated, round up the size so that
  // each element starts aligned.
  //
  // NOTE - this would probably be easier by defining pool_ as a pointer
  // to T and allocating an array of them (the compiler would probably
  // take care of the alignment for us), but then the ACE_NEW below would
  // require a default constructor on T - a requirement that is not in
  // previous versions of ACE
  size_t chunk_size = sizeof (T);
  chunk_size = ACE_MALLOC_ROUNDUP (chunk_size, ACE_MALLOC_ALIGN);
  ACE_NEW (this->pool_,
           char[n_chunks * chunk_size]);

  for (size_t c = 0;
       c < n_chunks;
       c++)
    {
      void* placement = this->pool_ + c * chunk_size;
      this->free_list_.add (new (placement) ACE_Cached_Mem_Pool_Node<T>);
    }
  // Put into free list using placement contructor, no real memory
  // allocation in the above <new>.
}

template <class T, class ACE_LOCK>
ACE_Cached_Allocator<T, ACE_LOCK>::~ACE_Cached_Allocator (void)
{
  delete [] this->pool_;
}

template <class T, class ACE_LOCK> void *
ACE_Cached_Allocator<T, ACE_LOCK>::malloc (size_t nbytes)
{
  // Check if size requested fits within pre-determined size.
  if (nbytes > sizeof (T))
    return 0;

  // addr() call is really not absolutely necessary because of the way
  // ACE_Cached_Mem_Pool_Node's internal structure arranged.
  return this->free_list_.remove ()->addr ();
}

template <class T, class ACE_LOCK> void *
ACE_Cached_Allocator<T, ACE_LOCK>::calloc (size_t nbytes,
                                           char initial_value)
{
  // Check if size requested fits within pre-determined size.
  if (nbytes > sizeof (T))
    return 0;

  // addr() call is really not absolutely necessary because of the way
  // ACE_Cached_Mem_Pool_Node's internal structure arranged.
  void *ptr = this->free_list_.remove ()->addr ();
  if (ptr != 0)
    ACE_OS::memset (ptr, initial_value, sizeof (T));
  return ptr;
}

template <class T, class ACE_LOCK> void *
ACE_Cached_Allocator<T, ACE_LOCK>::calloc (size_t,
                                           size_t,
                                           char)
{
  ACE_NOTSUP_RETURN (0);
}

template <class T, class ACE_LOCK> void
ACE_Cached_Allocator<T, ACE_LOCK>::free (void * ptr)
{
  if (ptr != 0)
    this->free_list_.add ((ACE_Cached_Mem_Pool_Node<T> *) ptr) ;
}

template <class ACE_LOCK>
ACE_Dynamic_Cached_Allocator<ACE_LOCK>::ACE_Dynamic_Cached_Allocator
  (size_t n_chunks, size_t chunk_size)
    : pool_ (0),
      free_list_ (ACE_PURE_FREE_LIST),
      chunk_size_(chunk_size)
{
  chunk_size = ACE_MALLOC_ROUNDUP (chunk_size, ACE_MALLOC_ALIGN);
  ACE_NEW (this->pool_, char[n_chunks * chunk_size_]);

  for (size_t c = 0;
       c < n_chunks;
       c++)
    {
      void* placement = this->pool_ + c * chunk_size_;

      this->free_list_.add (new (placement) ACE_Cached_Mem_Pool_Node<char>);
    }
  // Put into free list using placement contructor, no real memory
  // allocation in the above <new>.
}

template <class ACE_LOCK>
ACE_Dynamic_Cached_Allocator<ACE_LOCK>::~ACE_Dynamic_Cached_Allocator (void)
{
  delete [] this->pool_;
  this->pool_ = 0;
  chunk_size_ = 0;
}

template <class ACE_LOCK> void *
ACE_Dynamic_Cached_Allocator<ACE_LOCK>::malloc (size_t nbytes)
{
  // Check if size requested fits within pre-determined size.
  if (nbytes > chunk_size_)
    return 0;

  // addr() call is really not absolutely necessary because of the way
  // ACE_Cached_Mem_Pool_Node's internal structure arranged.
  return this->free_list_.remove ()->addr ();
}

template <class ACE_LOCK> void *
ACE_Dynamic_Cached_Allocator<ACE_LOCK>::calloc (size_t nbytes,
                                                char initial_value)
{
  // Check if size requested fits within pre-determined size.
  if (nbytes > chunk_size_)
    return 0;

  // addr() call is really not absolutely necessary because of the way
  // ACE_Cached_Mem_Pool_Node's internal structure arranged.
  void *ptr = this->free_list_.remove ()->addr ();
  if (ptr != 0)
    ACE_OS::memset (ptr, initial_value, chunk_size_);
  return ptr;
}

template <class ACE_LOCK> void *
ACE_Dynamic_Cached_Allocator<ACE_LOCK>::calloc (size_t, size_t, char)
{
  ACE_NOTSUP_RETURN (0);
}

template <class ACE_LOCK> void
ACE_Dynamic_Cached_Allocator<ACE_LOCK>::free (void * ptr)
{
  if (ptr != 0)
    this->free_list_.add ((ACE_Cached_Mem_Pool_Node<char> *) ptr);
}

ACE_ALLOC_HOOK_DEFINE (ACE_Malloc_T)

template <class MALLOC> void *
ACE_Allocator_Adapter<MALLOC>::malloc (size_t nbytes)
{
  ACE_TRACE ("ACE_Allocator_Adapter<MALLOC>::malloc");
  return this->allocator_.malloc (nbytes);
}

template <class MALLOC> void *
ACE_Allocator_Adapter<MALLOC>::calloc (size_t nbytes,
                                       char initial_value)
{
  ACE_TRACE ("ACE_Allocator_Adapter<MALLOC>::calloc");
  return this->allocator_.calloc (nbytes, initial_value);
}

template <class MALLOC> void *
ACE_Allocator_Adapter<MALLOC>::calloc (size_t n_elem,
                                       size_t elem_size,
                                       char initial_value)
{
  ACE_TRACE ("ACE_Allocator_Adapter<MALLOC>::calloc");
  return this->allocator_.calloc (n_elem, elem_size, initial_value);
}

template <class MALLOC> MALLOC &
ACE_Allocator_Adapter<MALLOC>::alloc (void)
{
  ACE_TRACE ("ACE_Allocator_Adapter<MALLOC>::allocator");
  return this->allocator_;
}

template <class MALLOC> void
ACE_Allocator_Adapter<MALLOC>::free (void *ptr)
{
  ACE_TRACE ("ACE_Allocator_Adapter<MALLOC>::free");
  this->allocator_.free (ptr);
}

template <class MALLOC> int
ACE_Allocator_Adapter<MALLOC>::remove (void)
{
  ACE_TRACE ("ACE_Allocator_Adapter<MALLOC>::remove");
  return this->allocator_.remove ();
}

template <class MALLOC> int
ACE_Allocator_Adapter<MALLOC>::trybind (const char *name,
                                        void *&pointer)
{
  ACE_TRACE ("ACE_Allocator_Adapter<MALLOC>::trybind");
  return this->allocator_.trybind (name, pointer);
}

template <class MALLOC> int
ACE_Allocator_Adapter<MALLOC>::bind (const char *name,
                                     void *pointer,
                                     int duplicates)
{
  ACE_TRACE ("ACE_Allocator_Adapter<MALLOC>::bind");
  return this->allocator_.bind (name, pointer, duplicates);
}

template <class MALLOC> int
ACE_Allocator_Adapter<MALLOC>::find (const char *name,
                                     void *&pointer)
{
  ACE_TRACE ("ACE_Allocator_Adapter<MALLOC>::find");
  return this->allocator_.find (name, pointer);
}

template <class MALLOC> int
ACE_Allocator_Adapter<MALLOC>::find (const char *name)
{
  ACE_TRACE ("ACE_Allocator_Adapter<MALLOC>::find");
  return this->allocator_.find (name);
}

template <class MALLOC> int
ACE_Allocator_Adapter<MALLOC>::unbind (const char *name, void *&pointer)
{
  ACE_TRACE ("ACE_Allocator_Adapter<MALLOC>::unbind");
  return this->allocator_.unbind (name, pointer);
}

template <class MALLOC> int
ACE_Allocator_Adapter<MALLOC>::unbind (const char *name)
{
  ACE_TRACE ("ACE_Allocator_Adapter<MALLOC>::unbind");
  return this->allocator_.unbind (name);
}

template <class MALLOC> int
ACE_Allocator_Adapter<MALLOC>::sync (ssize_t len, int flags)
{
  ACE_TRACE ("ACE_Allocator_Adapter<MALLOC>::sync");
  return this->allocator_.sync (len, flags);
}

template <class MALLOC> int
ACE_Allocator_Adapter<MALLOC>::sync (void *addr, size_t len, int flags)
{
  ACE_TRACE ("ACE_Allocator_Adapter<MALLOC>::sync");
  return this->allocator_.sync (addr, len, flags);
}

template <class MALLOC> int
ACE_Allocator_Adapter<MALLOC>::protect (ssize_t len, int flags)
{
  ACE_TRACE ("ACE_Allocator_Adapter<MALLOC>::protect");
  return this->allocator_.protect (len, flags);
}

template <class MALLOC> int
ACE_Allocator_Adapter<MALLOC>::protect (void *addr, size_t len, int flags)
{
  ACE_TRACE ("ACE_Allocator_Adapter<MALLOC>::protect");
  return this->allocator_.protect (addr, len, flags);
}

template <class MALLOC>
ACE_Allocator_Adapter<MALLOC>::ACE_Allocator_Adapter (const char *pool_name)
  : allocator_ (ACE_TEXT_CHAR_TO_TCHAR (pool_name))
{
  ACE_TRACE ("ACE_Allocator_Adapter<MALLOC>::ACE_Allocator_Adapter");
}

#if defined (ACE_HAS_WCHAR)
template <class MALLOC>
ACE_Allocator_Adapter<MALLOC>::ACE_Allocator_Adapter (const wchar_t *pool_name)
  : allocator_ (ACE_TEXT_WCHAR_TO_TCHAR (pool_name))
{
  ACE_TRACE ("ACE_Allocator_Adapter<MALLOC>::ACE_Allocator_Adapter");
}
#endif /* ACE_HAS_WCHAR */

template <class MALLOC>
ACE_Allocator_Adapter<MALLOC>::~ACE_Allocator_Adapter (void)
{
  ACE_TRACE ("ACE_Allocator_Adapter<MALLOC>::~ACE_Allocator_Adapter");
}

#if defined (ACE_HAS_MALLOC_STATS)
template <class MALLOC> void
ACE_Allocator_Adapter<MALLOC>::print_stats (void) const
{
  ACE_TRACE ("ACE_Allocator_Adapter<MALLOC>::print_stats");
  this->allocator_.print_stats ();
}
#endif /* ACE_HAS_MALLOC_STATS */

template <class MALLOC> void
ACE_Allocator_Adapter<MALLOC>::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_Allocator_Adapter<MALLOC>::dump");
  this->allocator_.dump ();
#endif /* ACE_HAS_DUMP */
}

template <ACE_MEM_POOL_1, class ACE_LOCK, class ACE_CB> void
ACE_Malloc_T<ACE_MEM_POOL_2, ACE_LOCK, ACE_CB>::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_Malloc_T<ACE_MEM_POOL_2, ACE_LOCK, ACE_CB>::dump");

  ACE_DEBUG ((LM_DEBUG, ACE_BEGIN_DUMP, this));
  this->memory_pool_.dump ();
  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("cb_ptr_ = %@\n"), this->cb_ptr_));
  this->cb_ptr_->dump ();
#if defined (ACE_HAS_MALLOC_STATS)
  if (this->cb_ptr_ != 0)
    this->cb_ptr_->malloc_stats_.dump ();
#endif /* ACE_HAS_MALLOC_STATS */
  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
#endif /* ACE_HAS_DUMP */
}

#if defined (ACE_HAS_MALLOC_STATS)

template <ACE_MEM_POOL_1, class ACE_LOCK, class ACE_CB> void
ACE_Malloc_T<ACE_MEM_POOL_2, ACE_LOCK, ACE_CB>::print_stats (void) const
{
  ACE_TRACE ("ACE_Malloc_T<ACE_MEM_POOL_2, ACE_LOCK, ACE_CB>::print_stats");
  ACE_GUARD (ACE_LOCK, ace_mon, *this->lock_);

  if (this->cb_ptr_ == 0)
    return;
  this->cb_ptr_->malloc_stats_.dump ();
  ACE_DEBUG ((LM_DEBUG,
              ACE_TEXT ("(%P|%t) contents of freelist:\n")));

  for (MALLOC_HEADER *currp = this->cb_ptr_->freep_->next_block_;
       ;
       currp = currp->next_block_)
    {
      ACE_DEBUG ((LM_DEBUG,
                  ACE_TEXT ("(%P|%t) ptr = %@, MALLOC_HEADER units = %d, byte units = %d\n"),
                  currp,
                  currp->size_,
                  currp->size_ * sizeof (MALLOC_HEADER)));
      if (currp == this->cb_ptr_->freep_)
        break;
    }
}
#endif /* ACE_HAS_MALLOC_STATS */

// Put <ptr> in the free list (locked version).

template<ACE_MEM_POOL_1, class ACE_LOCK, class ACE_CB> void
ACE_Malloc_T<ACE_MEM_POOL_2, ACE_LOCK, ACE_CB>::free (void *ptr)
{
  ACE_TRACE ("ACE_Malloc_T<ACE_MEM_POOL_2, ACE_LOCK, ACE_CB>::free");
  ACE_GUARD (ACE_LOCK, ace_mon, *this->lock_);

  this->shared_free (ptr);
}

// This function is called by the ACE_Malloc_T constructor to initialize
// the memory pool.  The first time in it allocates room for the
// control block (as well as a chunk of memory, depending on
// rounding...).  Depending on the type of <MEM_POOL> (i.e., shared
// vs. local) subsequent calls from other processes will only
// initialize the control block pointer.

template <ACE_MEM_POOL_1, class ACE_LOCK, class ACE_CB> int
ACE_Malloc_T<ACE_MEM_POOL_2, ACE_LOCK, ACE_CB>::open (void)
{
  ACE_TRACE ("ACE_Malloc_T<ACE_MEM_POOL_2, ACE_LOCK, ACE_CB>::open");
  ACE_GUARD_RETURN (ACE_LOCK, ace_mon, *this->lock_, -1);

  size_t rounded_bytes = 0;
  int first_time = 0;

  this->cb_ptr_ = (ACE_CB *)
    this->memory_pool_.init_acquire (sizeof *this->cb_ptr_,
                                     rounded_bytes,
                                     first_time);
  if (this->cb_ptr_ == 0)
    ACE_ERROR_RETURN ((LM_ERROR,
                       ACE_TEXT ("(%P|%t) %p\n"),
                       ACE_TEXT ("init_acquire failed")),
                      -1);
  else if (first_time)
    {
      // ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("(%P|%t) first time in, control block = %@\n"), this->cb_ptr_));

      MALLOC_HEADER::init_ptr (&this->cb_ptr_->freep_,
                               &this->cb_ptr_->base_,
                               this->cb_ptr_);

      MALLOC_HEADER::init_ptr (&this->cb_ptr_->freep_->next_block_,
                               this->cb_ptr_->freep_,
                               this->cb_ptr_);

      NAME_NODE::init_ptr (&this->cb_ptr_->name_head_,
                           0,
                           this->cb_ptr_);

      this->cb_ptr_->freep_->size_ = 0;
      this->cb_ptr_->ref_counter_ = 1;

      if (rounded_bytes > (sizeof *this->cb_ptr_ + sizeof (MALLOC_HEADER)))
        {
          // If we've got any extra space at the end of the control
          // block, then skip past the dummy <MALLOC_HEADER> to
          // point at the first free block.
          MALLOC_HEADER *p = ((MALLOC_HEADER *) (this->cb_ptr_->freep_)) + 1;

          MALLOC_HEADER::init_ptr (&p->next_block_,
                                   0,
                                   this->cb_ptr_);

          // Why aC++ in 64-bit mode can't grok this, I have no
          // idea... but it ends up with an extra bit set which makes
          // size_ really big without this hack.
#if defined (__hpux) && defined (__LP64__)
          size_t hpux11_hack = (rounded_bytes - sizeof *this->cb_ptr_)
                               / sizeof (MALLOC_HEADER);
          p->size_ = hpux11_hack;
#else
          p->size_ = (rounded_bytes - sizeof *this->cb_ptr_)
            / sizeof (MALLOC_HEADER);
#endif /* (__hpux) && defined (__LP64__) */

          ACE_MALLOC_STATS (++this->cb_ptr_->malloc_stats_.nchunks_);
          ACE_MALLOC_STATS (++this->cb_ptr_->malloc_stats_.nblocks_);
          ACE_MALLOC_STATS (++this->cb_ptr_->malloc_stats_.ninuse_);

          // Insert the newly allocated chunk of memory into the free
          // list.  Add "1" to skip over the <MALLOC_HEADER> when
          // freeing the pointer.
          this->shared_free (p + 1);
        }
    }
  else
    ++this->cb_ptr_->ref_counter_;
  return 0;
}

template <ACE_MEM_POOL_1, class ACE_LOCK, class ACE_CB>
ACE_Malloc_T<ACE_MEM_POOL_2, ACE_LOCK, ACE_CB>::ACE_Malloc_T (const ACE_TCHAR *pool_name)
  : cb_ptr_ (0),
    memory_pool_ (pool_name),
    bad_flag_ (0)
{
  ACE_TRACE ("ACE_Malloc_T<ACE_MEM_POOL_2, ACE_LOCK, ACE_CB>::ACE_Malloc_T");
  this->lock_ = ACE_Malloc_Lock_Adapter_T<ACE_LOCK> ()(pool_name);
  if (this->lock_ == 0)
    return;

  this->delete_lock_ = true;

  this->bad_flag_ = this->open ();

  if (this->bad_flag_ == -1)
    ACE_ERROR ((LM_ERROR,
                ACE_TEXT ("%p\n"),
                ACE_TEXT ("ACE_Malloc_T<ACE_MEM_POOL_2, ACE_LOCK, ACE_CB>::ACE_Malloc_T")));
}

template <ACE_MEM_POOL_1, class ACE_LOCK, class ACE_CB>
ACE_Malloc_T<ACE_MEM_POOL_2, ACE_LOCK, ACE_CB>::ACE_Malloc_T (const ACE_TCHAR *pool_name,
                                                              const ACE_TCHAR *lock_name,
                                                              const ACE_MEM_POOL_OPTIONS *options)
  : cb_ptr_ (0),
    memory_pool_ (pool_name, options),
    bad_flag_ (0)
{
  ACE_TRACE ("ACE_Malloc_T<ACE_MEM_POOL_2, ACE_LOCK, ACE_CB>::ACE_Malloc_T");
  // Use pool_name for lock_name if lock_name not passed.
  const ACE_TCHAR *name = lock_name ? lock_name : pool_name;
  this->lock_ = ACE_Malloc_Lock_Adapter_T<ACE_LOCK> ()(name);
  if (this->lock_ == 0)
    return;

  this->delete_lock_ = true;

  this->bad_flag_ = this->open ();
  if (this->bad_flag_ == -1)
    ACE_ERROR ((LM_ERROR,
                ACE_TEXT ("%p\n"),
                ACE_TEXT ("ACE_Malloc_T<ACE_MEM_POOL_2, ACE_LOCK, ACE_CB>::ACE_Malloc_T")));
}


template <ACE_MEM_POOL_1, class ACE_LOCK, class ACE_CB>
ACE_Malloc_T<ACE_MEM_POOL_2, ACE_LOCK, ACE_CB>::ACE_Malloc_T (const ACE_TCHAR *pool_name,
                                                              const ACE_MEM_POOL_OPTIONS *options,
                                                              ACE_LOCK *lock)
  : cb_ptr_ (0),
    memory_pool_ (pool_name, options),
    lock_ (lock),
    delete_lock_ (false),
    bad_flag_ (0)
{
  ACE_TRACE ("ACE_Malloc_T<ACE_MEM_POOL_2, ACE_LOCK, ACE_CB>::ACE_Malloc_T");

  if (lock == 0)
    {
      this->bad_flag_ = -1;
      errno = EINVAL;
      return;
    }

  this->bad_flag_ = this->open ();
  if (this->bad_flag_ == -1)
    ACE_ERROR ((LM_ERROR,
                ACE_TEXT ("%p\n"),
                ACE_TEXT ("ACE_Malloc_T<ACE_MEM_POOL_2, ACE_LOCK, ACE_CB>::ACE_Malloc_T")));
}

#if !defined (ACE_HAS_TEMPLATE_TYPEDEFS)
template <ACE_MEM_POOL_1, class ACE_LOCK, class ACE_CB>
ACE_Malloc_T<ACE_MEM_POOL_2, ACE_LOCK, ACE_CB>::ACE_Malloc_T (const ACE_TCHAR *pool_name,
                                                          const ACE_TCHAR *lock_name,
                                                          const void *options)
  : cb_ptr_ (0),
    memory_pool_ (pool_name,
                  (const ACE_MEM_POOL_OPTIONS *) options),
    bad_flag_ (0)
{
  ACE_TRACE ("ACE_Malloc_T<ACE_MEM_POOL_2, ACE_LOCK, ACE_CB>::ACE_Malloc_T");

  this->lock_ = ACE_Malloc_Lock_Adapter_T<ACE_LOCK> ()(lock_name);
  if (this->lock_ == 0)
    return;

  this->delete_lock_ = true;
  this->bad_flag_ = this->open ();
  if (this->bad_flag_ == -1)
    ACE_ERROR ((LM_ERROR,
                ACE_TEXT ("%p\n"),
                ACE_TEXT ("ACE_Malloc_T<ACE_MEM_POOL_2, ACE_LOCK, ACE_CB>::ACE_Malloc_T")));
}
#endif /* ACE_HAS_TEMPLATE_TYPEDEFS */


template <ACE_MEM_POOL_1, class ACE_LOCK, class ACE_CB>
ACE_Malloc_T<ACE_MEM_POOL_2, ACE_LOCK, ACE_CB>::~ACE_Malloc_T (void)
{
  ACE_TRACE ("ACE_Malloc_T<MEM_POOL>::~ACE_Malloc_T<MEM_POOL>");
  if (this->delete_lock_)
    {
      delete this->lock_;
      this->lock_ = 0;
    }
}

// Clean up the resources allocated by ACE_Malloc_T.

template <ACE_MEM_POOL_1, class ACE_LOCK, class ACE_CB> int
ACE_Malloc_T<ACE_MEM_POOL_2, ACE_LOCK, ACE_CB>::remove (void)
{
  ACE_TRACE ("ACE_Malloc_T<ACE_MEM_POOL_2, ACE_LOCK, ACE_CB>::remove");
  // ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("(%P|%t) destroying ACE_Malloc_T\n")));

#if defined (ACE_HAS_MALLOC_STATS)
  this->print_stats ();
#endif /* ACE_HAS_MALLOC_STATS */

  // Remove the ACE_LOCK.
  if (this->delete_lock_)
    this->lock_->remove ();

  // Give the memory pool a chance to release its resources.
  int const result = this->memory_pool_.release ();

  // Reset this->cb_ptr_ as it is no longer valid.
  // There's also no need to keep the reference counter as the
  // underlying memory pool has been destroyed.
  // Also notice that we are leaving the decision of removing
  // the pool to users so they can map to the same mmap file
  // again.
  this->cb_ptr_ = 0;

  return result;
}

// General-purpose memory allocator.  Assumes caller holds the locks.

template <ACE_MEM_POOL_1, class ACE_LOCK, class ACE_CB> void *
ACE_Malloc_T<ACE_MEM_POOL_2, ACE_LOCK, ACE_CB>::shared_malloc (size_t nbytes)
{
#if !defined (ACE_HAS_WIN32_STRUCTURAL_EXCEPTIONS)
  ACE_TRACE ("ACE_Malloc_T<ACE_MEM_POOL_2, ACE_LOCK, ACE_CB>::shared_malloc");
#endif /* !ACE_HAS_WIN32_STRUCTURAL_EXCEPTIONS */

  if (this->cb_ptr_ == 0)
    return 0;

  // Round up request to a multiple of the MALLOC_HEADER size.
  size_t const nunits =
    (nbytes + sizeof (MALLOC_HEADER) - 1) / sizeof (MALLOC_HEADER)
    + 1; // Add one for the <MALLOC_HEADER> itself.

  MALLOC_HEADER *prevp = 0;
  MALLOC_HEADER *currp = 0;

  ACE_SEH_TRY
    {
      // Begin the search starting at the place in the freelist where the
      // last block was found.
      prevp = this->cb_ptr_->freep_;
      currp = prevp->next_block_;
    }
#if defined (ACE_HAS_WIN32_STRUCTURAL_EXCEPTIONS)
  ACE_SEH_EXCEPT (this->memory_pool_.seh_selector (GetExceptionInformation ()))
    {
      currp = prevp->next_block_;
    }
#endif /* ACE_HAS_WIN32_STRUCTURAL_EXCEPTIONS */

  // Search the freelist to locate a block of the appropriate size.

  while (1)

    // *Warning* Do not use "continue" within this while-loop.

    {
      ACE_SEH_TRY
        {
          if (currp->size_ >= nunits) // Big enough
            {
              ACE_MALLOC_STATS (++this->cb_ptr_->malloc_stats_.ninuse_);
              if (currp->size_ == nunits)
                // Exact size, just update the pointers.
                prevp->next_block_ = currp->next_block_;
              else
                {
                  // Remaining chunk is larger than requested block, so
                  // allocate at tail end.
                  ACE_MALLOC_STATS (++this->cb_ptr_->malloc_stats_.nblocks_);
                  currp->size_ -= nunits;
                  currp += currp->size_;
                  MALLOC_HEADER::init_ptr (&currp->next_block_,
                                           0,
                                           this->cb_ptr_);
                  currp->size_ = nunits;
                }
              this->cb_ptr_->freep_ = prevp;

              // Skip over the MALLOC_HEADER when returning pointer.
              return currp + 1;
            }
          else if (currp == this->cb_ptr_->freep_)
            {
              // We've wrapped around freelist without finding a
              // block.  Therefore, we need to ask the memory pool for
              // a new chunk of bytes.

              size_t chunk_bytes = 0;

              currp = (MALLOC_HEADER *)
                this->memory_pool_.acquire (nunits * sizeof (MALLOC_HEADER),
                                            chunk_bytes);
              void *remap_addr = this->memory_pool_.base_addr ();
              if (remap_addr != 0)
                this->cb_ptr_ = (ACE_CB *) remap_addr;

              if (currp != 0)
                {
                  ACE_MALLOC_STATS (++this->cb_ptr_->malloc_stats_.nblocks_);
                  ACE_MALLOC_STATS (++this->cb_ptr_->malloc_stats_.nchunks_);
                  ACE_MALLOC_STATS (++this->cb_ptr_->malloc_stats_.ninuse_);

                  MALLOC_HEADER::init_ptr (&currp->next_block_,
                                           0,
                                           this->cb_ptr_);
                  // Compute the chunk size in MALLOC_HEADER units.
                  currp->size_ = chunk_bytes / sizeof (MALLOC_HEADER);

                  // Insert the newly allocated chunk of memory into the
                  // free list.  Add "1" to skip over the
                  // <MALLOC_HEADER> when freeing the pointer since
                  // the first thing <free> does is decrement by this
                  // amount.
                  this->shared_free (currp + 1);
                  currp = this->cb_ptr_->freep_;
                }
              else
                return 0;
                // Shouldn't do this here because of errors with the wchar ver
                // This is because ACE_ERROR_RETURN converts the __FILE__ to
                // wchar before printing out.  The compiler will complain
                // about this since a destructor would present in a SEH block
                //ACE_ERROR_RETURN ((LM_ERROR,
                //                   ACE_TEXT ("(%P|%t) %p\n"),
                //                   ACE_TEXT ("malloc")),
                //                  0);
            }
          prevp = currp;
          currp = currp->next_block_;
        }
      ACE_SEH_EXCEPT (this->memory_pool_.seh_selector (GetExceptionInformation ()))
        {
        }
    }
  ACE_NOTREACHED (return 0;)
}

// General-purpose memory allocator.

template <ACE_MEM_POOL_1, class ACE_LOCK, class ACE_CB> void *
ACE_Malloc_T<ACE_MEM_POOL_2, ACE_LOCK, ACE_CB>::malloc (size_t nbytes)
{
  ACE_TRACE ("ACE_Malloc_T<ACE_MEM_POOL_2, ACE_LOCK, ACE_CB>::malloc");
  ACE_GUARD_RETURN (ACE_LOCK, ace_mon, *this->lock_, 0);

  return this->shared_malloc (nbytes);
}

// General-purpose memory allocator.

template <ACE_MEM_POOL_1, class ACE_LOCK, class ACE_CB> void *
ACE_Malloc_T<ACE_MEM_POOL_2, ACE_LOCK, ACE_CB>::calloc (size_t nbytes,
                                                        char initial_value)
{
  ACE_TRACE ("ACE_Malloc_T<ACE_MEM_POOL_2, ACE_LOCK, ACE_CB>::calloc");
  void *ptr = this->malloc (nbytes);

  if (ptr != 0)
    ACE_OS::memset (ptr, initial_value, nbytes);

  return ptr;
}

template <ACE_MEM_POOL_1, class ACE_LOCK, class ACE_CB> void *
ACE_Malloc_T<ACE_MEM_POOL_2, ACE_LOCK, ACE_CB>::calloc (size_t n_elem,
                                                        size_t elem_size,
                                                        char initial_value)
{
  ACE_TRACE ("ACE_Malloc_T<ACE_MEM_POOL_2, ACE_LOCK, ACE_CB>::calloc");

  return this->calloc (n_elem * elem_size, initial_value);
}

// Put block AP in the free list (must be called with locks held!)

template <ACE_MEM_POOL_1, class ACE_LOCK, class ACE_CB> void
ACE_Malloc_T<ACE_MEM_POOL_2, ACE_LOCK, ACE_CB>::shared_free (void *ap)
{
#if !defined (ACE_HAS_WIN32_STRUCTURAL_EXCEPTIONS)
  ACE_TRACE ("ACE_Malloc_T<ACE_MEM_POOL_2, ACE_LOCK, ACE_CB>::shared_free");
#endif /* ACE_HAS_WIN32_STRUCTURAL_EXCEPTIONS */

  if (ap == 0 || this->cb_ptr_ == 0)
    return;

  // Adjust AP to point to the block MALLOC_HEADER
  MALLOC_HEADER *blockp = ((MALLOC_HEADER *) ap) - 1;
  MALLOC_HEADER *currp = this->cb_ptr_->freep_;

  // Search until we find the location where the blocks belongs.  Note
  // that addresses are kept in sorted order.

  ACE_SEH_TRY
    {
      for (;
           blockp <= currp
             || blockp >= (MALLOC_HEADER *) currp->next_block_;
           currp = currp->next_block_)
        {
          if (currp >= (MALLOC_HEADER *) currp->next_block_
              && (blockp > currp
                  || blockp < (MALLOC_HEADER *) currp->next_block_))
            // Freed block at the start or the end of the memory pool.
            break;
        }

      // Join to upper neighbor.
      if ((blockp + blockp->size_) == currp->next_block_)
        {
          ACE_MALLOC_STATS (--this->cb_ptr_->malloc_stats_.nblocks_);
          blockp->size_ += currp->next_block_->size_;
          blockp->next_block_ = currp->next_block_->next_block_;
        }
      else
        blockp->next_block_ = currp->next_block_;

      // Join to lower neighbor.
      if ((currp + currp->size_) == blockp)
        {
          ACE_MALLOC_STATS (--this->cb_ptr_->malloc_stats_.nblocks_);
          currp->size_ += blockp->size_;
          currp->next_block_ = blockp->next_block_;
        }
      else
        currp->next_block_ = blockp;

      ACE_MALLOC_STATS (--this->cb_ptr_->malloc_stats_.ninuse_);
      this->cb_ptr_->freep_ = currp;
    }
  ACE_SEH_EXCEPT (this->memory_pool_.seh_selector (GetExceptionInformation ()))
    {
    }
}

// No locks held here, caller must acquire/release lock.

template <ACE_MEM_POOL_1, class ACE_LOCK, class ACE_CB> void*
ACE_Malloc_T<ACE_MEM_POOL_2, ACE_LOCK, ACE_CB>::shared_find (const char *name)
{
#if !defined (ACE_HAS_WIN32_STRUCTURAL_EXCEPTIONS)
  ACE_TRACE ("ACE_Malloc_T<ACE_MEM_POOL_2, ACE_LOCK, ACE_CB>::shared_find");
#endif /* !ACE_HAS_WIN32_STRUCTURAL_EXCEPTIONS */

  if (this->cb_ptr_ == 0)
    return 0;

  ACE_SEH_TRY
    {
      for (NAME_NODE *node = this->cb_ptr_->name_head_;
           node != 0;
           node = node->next_)
        if (ACE_OS::strcmp (node->name (),
                            name) == 0)
          return node;
    }
  ACE_SEH_EXCEPT (this->memory_pool_.seh_selector (GetExceptionInformation ()))
    {
    }
  return 0;
}

template <ACE_MEM_POOL_1, class ACE_LOCK, class ACE_CB> int
ACE_Malloc_T<ACE_MEM_POOL_2, ACE_LOCK, ACE_CB>::shared_bind (const char *name,
                                                             void *pointer)
{
  if (this->cb_ptr_ == 0)
    return -1;

  // Combine the two allocations into one to avoid overhead...
  NAME_NODE *new_node = 0;

  ACE_ALLOCATOR_RETURN (new_node,
                        (NAME_NODE *)
                        this->shared_malloc (sizeof (NAME_NODE) +
                                             ACE_OS::strlen (name) + 1),
                        -1);
  char *name_ptr = (char *) (new_node + 1);

  // Use operator placement new to insert <new_node> at the head of
  // the linked list of <NAME_NODE>s.
  NAME_NODE *result =
    new (new_node) NAME_NODE (name,
                              name_ptr,
                              reinterpret_cast<char *> (pointer),
                              this->cb_ptr_->name_head_);
  this->cb_ptr_->name_head_ = result;
  return 0;
}

template <ACE_MEM_POOL_1, class ACE_LOCK, class ACE_CB> int
ACE_Malloc_T<ACE_MEM_POOL_2, ACE_LOCK, ACE_CB>::trybind (const char *name,
                                                         void *&pointer)
{
  ACE_TRACE ("ACE_Malloc_T<ACE_MEM_POOL_2, ACE_LOCK, ACE_CB>::trybind");
  ACE_WRITE_GUARD_RETURN (ACE_LOCK, ace_mon, *this->lock_, -1);

  NAME_NODE *node = (NAME_NODE *) this->shared_find (name);

  if (node == 0)
    // Didn't find it, so insert it.
    return this->shared_bind (name, pointer);

  // Found it, so return a copy of the current entry.
  pointer = (char *) node->pointer_;
  return 1;
}

template <ACE_MEM_POOL_1, class ACE_LOCK, class ACE_CB> int
ACE_Malloc_T<ACE_MEM_POOL_2, ACE_LOCK, ACE_CB>::bind (const char *name,
                                                      void *pointer,
                                                      int duplicates)
{
  ACE_TRACE ("ACE_Malloc_T<ACE_MEM_POOL_2, ACE_LOCK, ACE_CB>::bind");
  ACE_WRITE_GUARD_RETURN (ACE_LOCK, ace_mon, *this->lock_, -1);

  if (duplicates == 0 && this->shared_find (name) != 0)
    // If we're not allowing duplicates, then if the name is already
    // present, return 1.
    return 1;

  // If we get this far, either we're allowing duplicates or we didn't
  // find the name yet.
  return this->shared_bind (name, pointer);
}

template <ACE_MEM_POOL_1, class ACE_LOCK, class ACE_CB> int
ACE_Malloc_T<ACE_MEM_POOL_2, ACE_LOCK, ACE_CB>::find (const char *name,
                                                    void *&pointer)
{
  ACE_TRACE ("ACE_Malloc_T<ACE_MEM_POOL_2, ACE_LOCK, ACE_CB>::find");

  ACE_READ_GUARD_RETURN (ACE_LOCK, ace_mon, *this->lock_, -1);

  NAME_NODE *node = (NAME_NODE *) this->shared_find (name);

  if (node == 0)
    return -1;

  pointer = (char *) node->pointer_;
  return 0;
}

// Returns a count of the number of available chunks that can hold
// <size> byte allocations.  Function can be used to determine if you
// have reached a water mark. This implies a fixed amount of allocated
// memory.
//
// @param size - the chunk size of that you would like a count of
// @return function returns the number of chunks of the given size
//          that would fit in the currently allocated memory

template <ACE_MEM_POOL_1, class ACE_LOCK, class ACE_CB> ssize_t
ACE_Malloc_T<ACE_MEM_POOL_2, ACE_LOCK, ACE_CB>::avail_chunks (size_t size) const
{
  ACE_TRACE ("ACE_Malloc_T<ACE_MEM_POOL_2, ACE_LOCK, ACE_CB>::avail_chunks");
  ACE_READ_GUARD_RETURN (ACE_LOCK, ace_mon, *this->lock_, -1);

  if (this->cb_ptr_ == 0)
    return -1;

  size_t count = 0;
  // Avoid dividing by 0...
  size = size == 0 ? 1 : size;
  MALLOC_HEADER *currp = this->cb_ptr_->freep_;

  // Calculate how many will fit in this block.
  do {
    size_t avail_size = currp->size_ == 0 ? 0 : currp->size_ - 1;
    if (avail_size * sizeof (MALLOC_HEADER) >= size)
      count += avail_size * sizeof (MALLOC_HEADER) / size;
    currp = currp->next_block_;
  }
  while (currp != this->cb_ptr_->freep_);

  return count;
}

template <ACE_MEM_POOL_1, class ACE_LOCK, class ACE_CB> int
ACE_Malloc_T<ACE_MEM_POOL_2, ACE_LOCK, ACE_CB>::find (const char *name)
{
  ACE_TRACE ("ACE_Malloc_T<ACE_MEM_POOL_2, ACE_LOCK, ACE_CB>::find");
  ACE_READ_GUARD_RETURN (ACE_LOCK, ace_mon, *this->lock_, -1);

  return this->shared_find (name) == 0 ? -1 : 0;
}

template <ACE_MEM_POOL_1, class ACE_LOCK, class ACE_CB> int
ACE_Malloc_T<ACE_MEM_POOL_2, ACE_LOCK, ACE_CB>::unbind (const char *name, void *&pointer)
{
  ACE_TRACE ("ACE_Malloc_T<ACE_MEM_POOL_2, ACE_LOCK, ACE_CB>::unbind");
  ACE_WRITE_GUARD_RETURN (ACE_LOCK, ace_mon, *this->lock_, -1);

  if (this->cb_ptr_ == 0)
    return -1;

  NAME_NODE *prev = 0;

  for (NAME_NODE *curr = this->cb_ptr_->name_head_;
       curr != 0;
       curr = curr->next_)
    {
      if (ACE_OS::strcmp (curr->name (), name) == 0)
        {
          pointer = (char *) curr->pointer_;

          if (prev == 0)
            this->cb_ptr_->name_head_ = curr->next_;
          else
            prev->next_ = curr->next_;

          if (curr->next_)
            curr->next_->prev_ = prev;

          // This will free up both the node and the name due to our
          // clever trick in <bind>!
          this->shared_free (curr);
          return 0;
        }
      prev = curr;
    }

  // Didn't find it, so fail.
  return -1;
}

template <ACE_MEM_POOL_1, class ACE_LOCK, class ACE_CB> int
ACE_Malloc_T<ACE_MEM_POOL_2, ACE_LOCK, ACE_CB>::unbind (const char *name)
{
  ACE_TRACE ("ACE_Malloc_T<ACE_MEM_POOL_2, ACE_LOCK, ACE_CB>::unbind");
  void *temp = 0;
  return this->unbind (name, temp);
}

/*****************************************************************************/

template <class ACE_LOCK> ACE_LOCK *
ACE_Malloc_Lock_Adapter_T<ACE_LOCK>::operator () (const ACE_TCHAR *name)
{
  ACE_LOCK *p = 0;
  if (name == 0)
    ACE_NEW_RETURN (p, ACE_LOCK (name), 0);
  else
    ACE_NEW_RETURN (p, ACE_LOCK (ACE::basename (name,
                                                ACE_DIRECTORY_SEPARATOR_CHAR)),
                    0);
  return p;
}

/*****************************************************************************/

template <ACE_MEM_POOL_1, class ACE_LOCK, class ACE_CB> void
ACE_Malloc_LIFO_Iterator_T<ACE_MEM_POOL_2, ACE_LOCK, ACE_CB>::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_Malloc_LIFO_Iterator_T<ACE_MEM_POOL_2, ACE_LOCK, ACE_CB>::dump");

  ACE_DEBUG ((LM_DEBUG, ACE_BEGIN_DUMP, this));
  this->curr_->dump ();
  this->guard_.dump ();
  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("name_ = %C\n"), this->name_));
  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
#endif /* ACE_HAS_DUMP */
}

template <ACE_MEM_POOL_1, class ACE_LOCK, class ACE_CB>
ACE_Malloc_LIFO_Iterator_T<ACE_MEM_POOL_2, ACE_LOCK, ACE_CB>::ACE_Malloc_LIFO_Iterator_T (ACE_Malloc_T<ACE_MEM_POOL_2, ACE_LOCK, ACE_CB> &malloc,
                                                                                      const char *name)
  : malloc_ (malloc),
    curr_ (0),
    guard_ (*malloc_.lock_),
    name_ (name != 0 ? ACE_OS::strdup (name) : 0)
{
  ACE_TRACE ("ACE_Malloc_LIFO_Iterator_T<ACE_MEM_POOL_2, ACE_LOCK, ACE_CB>::ACE_Malloc_LIFO_Iterator_T");
  // Cheap trick to make code simple.
  // @@ Doug, this looks like trouble...
  NAME_NODE temp;
  this->curr_ = &temp;
  this->curr_->next_ = malloc_.cb_ptr_->name_head_;

  this->advance ();
}

template <ACE_MEM_POOL_1, class ACE_LOCK, class ACE_CB>
ACE_Malloc_LIFO_Iterator_T<ACE_MEM_POOL_2, ACE_LOCK, ACE_CB>::~ACE_Malloc_LIFO_Iterator_T (void)
{
  ACE_OS::free ((void *) this->name_);
}

template <ACE_MEM_POOL_1, class ACE_LOCK, class ACE_CB> int
ACE_Malloc_LIFO_Iterator_T<ACE_MEM_POOL_2, ACE_LOCK, ACE_CB>::next (void *&next_entry,
                                                                    const char *&name)
{
  ACE_TRACE ("ACE_Malloc_LIFO_Iterator_T<ACE_MEM_POOL_2, ACE_LOCK, ACE_CB>::next");

  if (this->curr_ != 0)
    {
      next_entry = (char *) this->curr_->pointer_;
      name = this->curr_->name ();
      return 1;
    }
  else
    return 0;
}

template <ACE_MEM_POOL_1, class ACE_LOCK, class ACE_CB> int
ACE_Malloc_LIFO_Iterator_T<ACE_MEM_POOL_2, ACE_LOCK, ACE_CB>::next (void *&next_entry)
{
  ACE_TRACE ("ACE_Malloc_LIFO_Iterator_T<ACE_MEM_POOL_2, ACE_LOCK, ACE_CB>::next");

  if (this->curr_ != 0)
    {
      next_entry = this->curr_->pointer_;
      return 1;
    }
  else
    return 0;
}

template <ACE_MEM_POOL_1, class ACE_LOCK, class ACE_CB> int
ACE_Malloc_LIFO_Iterator_T<ACE_MEM_POOL_2, ACE_LOCK, ACE_CB>::done (void) const
{
  ACE_TRACE ("ACE_Malloc_LIFO_Iterator_T<ACE_MEM_POOL_2, ACE_LOCK, ACE_CB>::done");

  return this->curr_ == 0;
}

template <ACE_MEM_POOL_1, class ACE_LOCK, class ACE_CB> int
ACE_Malloc_LIFO_Iterator_T<ACE_MEM_POOL_2, ACE_LOCK, ACE_CB>::advance (void)
{
  ACE_TRACE ("ACE_Malloc_LIFO_Iterator_T<ACE_MEM_POOL_2, ACE_LOCK, ACE_CB>::advance");

  this->curr_ = this->curr_->next_;

  if (this->name_ == 0)
    return this->curr_ != 0;

  while (this->curr_ != 0
         && ACE_OS::strcmp (this->name_,
                            this->curr_->name ()) != 0)
    this->curr_ = this->curr_->next_;

  return this->curr_ != 0;
}

template <ACE_MEM_POOL_1, class ACE_LOCK, class ACE_CB> void
ACE_Malloc_FIFO_Iterator_T<ACE_MEM_POOL_2, ACE_LOCK, ACE_CB>::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_Malloc_FIFO_Iterator_T<ACE_MEM_POOL_2, ACE_LOCK, ACE_CB>::dump");

  ACE_DEBUG ((LM_DEBUG, ACE_BEGIN_DUMP, this));
  this->curr_->dump ();
  this->guard_.dump ();
  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("name_ = %s\n"), this->name_));
  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
#endif /* ACE_HAS_DUMP */
}

template <ACE_MEM_POOL_1, class ACE_LOCK, class ACE_CB>
ACE_Malloc_FIFO_Iterator_T<ACE_MEM_POOL_2, ACE_LOCK, ACE_CB>::ACE_Malloc_FIFO_Iterator_T (ACE_Malloc_T<ACE_MEM_POOL_2, ACE_LOCK, ACE_CB> &malloc,
                                                                                      const char *name)
  : malloc_ (malloc),
    curr_ (0),
    guard_ (*malloc_.lock_),
    name_ (name != 0 ? ACE_OS::strdup (name) : 0)
{
  ACE_TRACE ("ACE_Malloc_FIFO_Iterator_T<ACE_MEM_POOL_2, ACE_LOCK, ACE_CB>::ACE_Malloc_FIFO_Iterator");
  // Cheap trick to make code simple.
  // @@ Doug, this looks like trouble...
  NAME_NODE temp;
  this->curr_ = &temp;
  this->curr_->next_ = malloc_.cb_ptr_->name_head_;
  this->curr_->prev_ = 0;

  // Go to the first element that was inserted.
  this->start ();
}

template <ACE_MEM_POOL_1, class ACE_LOCK, class ACE_CB>
ACE_Malloc_FIFO_Iterator_T<ACE_MEM_POOL_2, ACE_LOCK, ACE_CB>::~ACE_Malloc_FIFO_Iterator_T (void)
{
  ACE_OS::free ((void *) this->name_);
}

template <ACE_MEM_POOL_1, class ACE_LOCK, class ACE_CB> int
ACE_Malloc_FIFO_Iterator_T<ACE_MEM_POOL_2, ACE_LOCK, ACE_CB>::next (void *&next_entry,
                                                                    const char *&name)
{
  ACE_TRACE ("ACE_Malloc_FIFO_Iterator_T<ACE_MEM_POOL_2, ACE_LOCK, ACE_CB>::next");

  if (this->curr_ != 0)
    {
      next_entry = (char *) this->curr_->pointer_;
      name = this->curr_->name ();
      return 1;
    }
  else
    return 0;
}

template <ACE_MEM_POOL_1, class ACE_LOCK, class ACE_CB> int
ACE_Malloc_FIFO_Iterator_T<ACE_MEM_POOL_2, ACE_LOCK, ACE_CB>::next (void *&next_entry)
{
  ACE_TRACE ("ACE_Malloc_FIFO_Iterator_T<ACE_MEM_POOL_2, ACE_LOCK, ACE_CB>::next");

  if (this->curr_ != 0)
    {
      next_entry = this->curr_->pointer_;
      return 1;
    }
  else
    return 0;
}

template <ACE_MEM_POOL_1, class ACE_LOCK, class ACE_CB> int
ACE_Malloc_FIFO_Iterator_T<ACE_MEM_POOL_2, ACE_LOCK, ACE_CB>::done (void) const
{
  ACE_TRACE ("ACE_Malloc_FIFO_Iterator_T<ACE_MEM_POOL_2, ACE_LOCK, ACE_CB>::done");

  return this->curr_ == 0;
}

template <ACE_MEM_POOL_1, class ACE_LOCK, class ACE_CB> int
ACE_Malloc_FIFO_Iterator_T<ACE_MEM_POOL_2, ACE_LOCK, ACE_CB>::advance (void)
{
  ACE_TRACE ("ACE_Malloc_FIFO_Iterator_T<ACE_MEM_POOL_2, ACE_LOCK, ACE_CB>::advance");

  this->curr_ = this->curr_->prev_;

  if (this->name_ == 0)
    return this->curr_ != 0;

  while (this->curr_ != 0
         && ACE_OS::strcmp (this->name_,
                            this->curr_->name ()) != 0)
    this->curr_ = this->curr_->prev_;

  return this->curr_ != 0;
}

template <ACE_MEM_POOL_1, class ACE_LOCK, class ACE_CB> int
ACE_Malloc_FIFO_Iterator_T<ACE_MEM_POOL_2, ACE_LOCK, ACE_CB>::start (void)
{
  this->curr_ = this->curr_->next_;
  NAME_NODE *prev = 0;

  // Locate the element that was inserted first.
  // @@ We could optimize this by making the list a circular list or
  // storing an extra pointer.
  while (this->curr_ != 0)
    {
      prev = this->curr_;
      this->curr_ = this->curr_->next_;
    }

  this->curr_ = prev;
  return this->curr_ != 0;
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_MALLOC_T_CPP */
