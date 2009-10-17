/* -*- C++ -*- */
//=============================================================================
/**
 *  @file    Free_List.h
 *
 *  $Id: Free_List.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Darrell Brunsch (brunsch@cs.wustl.edu)
 */
//=============================================================================
#ifndef ACE_FREE_LIST_H
#define ACE_FREE_LIST_H
#include /**/ "ace/pre.h"
#include /**/ "ace/config-all.h"
#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */
#include "ace/Global_Macros.h"
#include "ace/Default_Constants.h"
#include "ace/os_include/os_stddef.h"
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
/**
 * @class ACE_Free_List
 *
 * @brief Implements a free list.
 *
 * This class maintains a free list of nodes of type T.
 */
template <class T>
class ACE_Free_List
{
public:
  /// Destructor - removes all the elements from the free_list.
  virtual ~ACE_Free_List (void);
  /// Inserts an element onto the free list (if it isn't past the high
  /// water mark).
  virtual void add (T *element) = 0;
  /// Takes a element off the freelist and returns it.  It creates
  /// <inc> new elements if the size is at or below the low water mark.
  virtual T *remove (void) = 0;
  /// Returns the current size of the free list.
  virtual size_t size (void) = 0;
  /// Resizes the free list to @a newsize.
  virtual void resize (size_t newsize) = 0;
};
/**
 * @class ACE_Locked_Free_List
 *
 * @brief Implements a free list.
 *
 * This class maintains a free list of nodes of type T.  It
 * depends on the type T having a <get_next> and <set_next>
 * method.  It maintains a mutex so the freelist can be used in
 * a multithreaded program .
 */
template <class T, class ACE_LOCK>
class ACE_Locked_Free_List : public ACE_Free_List<T>
{
public:
  // = Initialization and termination.
  /**
   * Constructor takes a @a mode (i.e., ACE_FREE_LIST_WITH_POOL or
   * ACE_PURE_FREE_LIST), a count of the number of nodes to
   * <prealloc>, a low and high water mark (<lwm> and <hwm>) that
   * indicate when to allocate more nodes, an increment value (<inc>)
   * that indicates how many nodes to allocate when the list must
   * grow.
   */
  ACE_Locked_Free_List (int mode = ACE_FREE_LIST_WITH_POOL,
                        size_t prealloc = ACE_DEFAULT_FREE_LIST_PREALLOC,
                        size_t lwm = ACE_DEFAULT_FREE_LIST_LWM,
                        size_t hwm = ACE_DEFAULT_FREE_LIST_HWM,
                        size_t inc = ACE_DEFAULT_FREE_LIST_INC);
  /// Destructor - removes all the elements from the free_list.
  virtual ~ACE_Locked_Free_List (void);
  /// Inserts an element onto the free list (if it isn't past the high
  /// water mark).
  virtual void add (T *element);
  /// Takes a element off the freelist and returns it.  It creates
  /// <inc> new elements if the size is at or below the low water mark.
  virtual T *remove (void);
  /// Returns the current size of the free list.
  virtual size_t size (void);
  /// Resizes the free list to @a newsize.
  virtual void resize (size_t newsize);
protected:
  /// Allocates @a n extra nodes for the freelist.
  virtual void alloc (size_t n);
  /// Removes and frees @a n nodes from the freelist.
  virtual void dealloc (size_t n);
  /// Free list operation mode, either ACE_FREE_LIST_WITH_POOL or
  /// ACE_PURE_FREE_LIST.
  int mode_;
  /// Pointer to the first node in the freelist.
  T *free_list_;
  /// Low water mark.
  size_t lwm_;
  /// High water mark.
  size_t hwm_;
  /// Increment value.
  size_t inc_;
  /// Keeps track of the size of the list.
  size_t size_;
  /// Synchronization variable for ACE_Timer_Queue.
  ACE_LOCK mutex_;
private:
  // = Don't allow these operations for now.
  ACE_UNIMPLEMENTED_FUNC (ACE_Locked_Free_List (const ACE_Locked_Free_List<T, ACE_LOCK> &))
  ACE_UNIMPLEMENTED_FUNC (void operator= (const ACE_Locked_Free_List<T, ACE_LOCK> &))
};
ACE_END_VERSIONED_NAMESPACE_DECL
#if defined (ACE_TEMPLATES_REQUIRE_SOURCE)
#include "ace/Free_List.cpp"
#endif /* ACE_TEMPLATES_REQUIRE_SOURCE */
#if defined (ACE_TEMPLATES_REQUIRE_PRAGMA)
#pragma implementation ("Free_List.cpp")
#endif /* ACE_TEMPLATES_REQUIRE_PRAGMA */
#include /**/ "ace/post.h"
#endif /* ACE_FREE_LIST_H */

