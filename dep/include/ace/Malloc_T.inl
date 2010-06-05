// -*- C++ -*-
//
// $Id: Malloc_T.inl 80826 2008-03-04 14:51:23Z wotte $

#include "ace/OS_NS_string.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

template <class T> ACE_INLINE T *
ACE_Cached_Mem_Pool_Node<T>::addr (void)
{
  // This should be done using a single reinterpret_cast, but Sun/CC
  // (4.2) gets awfully confused when T is a char[20] (and maybe other
  // types).
  return static_cast<T *> (static_cast <void *> (this));
}

template <class T> ACE_INLINE ACE_Cached_Mem_Pool_Node<T> *
ACE_Cached_Mem_Pool_Node<T>::get_next (void)
{
  return this->next_;
}

template <class T> ACE_INLINE void
ACE_Cached_Mem_Pool_Node<T>::set_next (ACE_Cached_Mem_Pool_Node<T> *ptr)
{
  this->next_ = ptr;
}

template <class T, class ACE_LOCK> ACE_INLINE size_t
ACE_Cached_Allocator<T, ACE_LOCK>::pool_depth (void)
{
  return this->free_list_.size ();
}

template <class ACE_LOCK> ACE_INLINE size_t
ACE_Dynamic_Cached_Allocator<ACE_LOCK>::pool_depth (void)
{
  return this->free_list_.size ();
}

template <ACE_MEM_POOL_1, class ACE_LOCK, class ACE_CB> ACE_INLINE int
ACE_Malloc_T<ACE_MEM_POOL_2, ACE_LOCK, ACE_CB>::ref_counter (void)
{
  ACE_GUARD_RETURN (ACE_LOCK, ace_mon, *this->lock_, -1);
  if (this->cb_ptr_ != 0)
    return this->cb_ptr_->ref_counter_;

  return -1;
}

template <ACE_MEM_POOL_1, class ACE_LOCK, class ACE_CB> ACE_INLINE int
ACE_Malloc_T<ACE_MEM_POOL_2, ACE_LOCK, ACE_CB>::bad (void)
{
  return this->bad_flag_;
}

template <ACE_MEM_POOL_1, class ACE_LOCK, class ACE_CB> ACE_INLINE int
ACE_Malloc_T<ACE_MEM_POOL_2, ACE_LOCK, ACE_CB>::release (int close)
{
  ACE_GUARD_RETURN (ACE_LOCK, ace_mon, *this->lock_, -1);
  if (this->cb_ptr_ != 0)
    {
      int const retv = --this->cb_ptr_->ref_counter_;

#if 0
      ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("(%P) ACE_Malloc_T::release ->%d\n"),
                 this->cb_ptr_->ref_counter_ - 1));
#endif /* 0 */
      if (close)
        this->memory_pool_.release (0);

      if (retv == 0)
        this->remove ();
      return retv;
    }
  return -1;
}

template <ACE_MEM_POOL_1, class ACE_LOCK, class ACE_CB> ACE_INLINE ACE_MEM_POOL &
ACE_Malloc_T<ACE_MEM_POOL_2, ACE_LOCK, ACE_CB>::memory_pool (void)
{
  ACE_TRACE ("ACE_Malloc_T<MEMORY_POOL, ACE_LOCK, ACE_CB>::memory_pool");
  return this->memory_pool_;
}

template <ACE_MEM_POOL_1, class ACE_LOCK, class ACE_CB> ACE_INLINE int
ACE_Malloc_T<ACE_MEM_POOL_2, ACE_LOCK, ACE_CB>::sync (ssize_t len,
                                                    int flags)
{
  ACE_TRACE ("ACE_Malloc_T<MEMORY_POOL, ACE_LOCK, ACE_CB>::sync");
  return this->memory_pool_.sync (len, flags);
}

template <ACE_MEM_POOL_1, class ACE_LOCK, class ACE_CB> ACE_INLINE int
ACE_Malloc_T<ACE_MEM_POOL_2, ACE_LOCK, ACE_CB>::sync (void *addr,
                                                    size_t len,
                                                    int flags)
{
  ACE_TRACE ("ACE_Malloc_T<MEMORY_POOL, ACE_LOCK, ACE_CB>::sync");
  return this->memory_pool_.sync (addr, len, flags);
}

template <ACE_MEM_POOL_1, class ACE_LOCK, class ACE_CB> ACE_INLINE int
ACE_Malloc_T<ACE_MEM_POOL_2, ACE_LOCK, ACE_CB>::protect (ssize_t len,
                                                       int flags)
{
  ACE_TRACE ("ACE_Malloc_T<MEMORY_POOL, ACE_LOCK, ACE_CB>::protect");
  return this->memory_pool_.protect (len, flags);
}

template <ACE_MEM_POOL_1, class ACE_LOCK, class ACE_CB> ACE_INLINE int
ACE_Malloc_T<ACE_MEM_POOL_2, ACE_LOCK, ACE_CB>::protect (void *addr,
                                                             size_t len,
                                                             int flags)
{
  ACE_TRACE ("ACE_Malloc_T<MEMORY_POOL, ACE_LOCK, ACE_CB>::protect");
  return this->memory_pool_.protect (addr, len, flags);
}

template <ACE_MEM_POOL_1, class ACE_LOCK, class ACE_CB> ACE_INLINE ACE_LOCK &
ACE_Malloc_T<ACE_MEM_POOL_2, ACE_LOCK, ACE_CB>::mutex (void)
{
  return *this->lock_;
}

template <ACE_MEM_POOL_1, class ACE_LOCK, class ACE_CB> ACE_INLINE void *
ACE_Malloc_T<ACE_MEM_POOL_2, ACE_LOCK, ACE_CB>::base_addr (void)
{
  return this->cb_ptr_;
}

template <ACE_MEM_POOL_1, class ACE_LOCK> ACE_INLINE
ACE_Malloc<ACE_MEM_POOL_2, ACE_LOCK>::ACE_Malloc (const ACE_TCHAR *pool_name)
  : ACE_Malloc_T<ACE_MEM_POOL_2, ACE_LOCK, ACE_Control_Block> (pool_name)
{
}

template <ACE_MEM_POOL_1, class ACE_LOCK> ACE_INLINE
ACE_Malloc<ACE_MEM_POOL_2, ACE_LOCK>::ACE_Malloc (const ACE_TCHAR *pool_name,
                                                  const ACE_TCHAR *lock_name,
                                                  const ACE_MEM_POOL_OPTIONS *options)
  : ACE_Malloc_T<ACE_MEM_POOL_2, ACE_LOCK, ACE_Control_Block> (pool_name, lock_name, options)
{
}

#if !defined (ACE_HAS_TEMPLATE_TYPEDEFS)
template <ACE_MEM_POOL_1, class ACE_LOCK> ACE_INLINE
ACE_Malloc<ACE_MEM_POOL_2, ACE_LOCK>::ACE_Malloc (const ACE_TCHAR *pool_name,
                                                  const ACE_TCHAR *lock_name,
                                                  const void *options)
  : ACE_Malloc_T<ACE_MEM_POOL_2, ACE_LOCK, ACE_Control_Block> (pool_name, lock_name, options)
{
}
#endif /* !ACE_HAS_TEMPLATE_TYPEDEFS */

template <ACE_MEM_POOL_1, class ACE_LOCK> ACE_INLINE
ACE_Malloc_LIFO_Iterator<ACE_MEM_POOL_2, ACE_LOCK>::ACE_Malloc_LIFO_Iterator (ACE_Malloc<ACE_MEM_POOL_2, ACE_LOCK> &malloc,
                                                                              const char *name)
  : ACE_Malloc_LIFO_Iterator_T<ACE_MEM_POOL_2, ACE_LOCK, ACE_Control_Block> (malloc, name)
{
}

template <ACE_MEM_POOL_1, class ACE_LOCK> ACE_INLINE
ACE_Malloc_FIFO_Iterator<ACE_MEM_POOL_2, ACE_LOCK>::ACE_Malloc_FIFO_Iterator (ACE_Malloc<ACE_MEM_POOL_2, ACE_LOCK> &malloc,
                                                                              const char *name)
  : ACE_Malloc_FIFO_Iterator_T<ACE_MEM_POOL_2, ACE_LOCK, ACE_Control_Block> (malloc, name)
{
}

#if 0
template <ACE_MEM_POOL_1, class ACE_LOCK, class ACE_CB> ACE_INLINE void
ACE_Malloc_T<ACE_MEM_POOL_2, ACE_LOCK, ACE_CB>::init_malloc_header_ptr (void* ptr)
{
#if (ACE_HAS_POSITION_INDEPENDENT_POINTERS == 1)
  new (ptr) ACE_MALLOC_HEADER_PTR (this->cb_ptr_, 0);
#else
  ACE_UNUSED_ARG (ptr);
#endif /* ACE_HAS_POSITION_INDEPENDENT_POINTERS == 1 */
}
#endif  /* 0 */

ACE_END_VERSIONED_NAMESPACE_DECL
