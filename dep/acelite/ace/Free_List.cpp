// $Id: Free_List.cpp 81107 2008-03-27 11:12:42Z johnnyw $

#ifndef ACE_FREE_LIST_CPP
#define ACE_FREE_LIST_CPP

#include "ace/Free_List.h"
#include "ace/Guard_T.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

template <class T>
ACE_Free_List<T>::~ACE_Free_List (void)
{
}

// Default constructor that takes in a preallocation number
// (<prealloc>), a low and high water mark (<lwm> and <hwm>) and an
// increment value (<inc>)

template <class T, class ACE_LOCK>
ACE_Locked_Free_List<T, ACE_LOCK>::ACE_Locked_Free_List (int mode,
                                                     size_t prealloc,
                                                     size_t lwm,
                                                     size_t hwm,
                                                     size_t inc)
  : mode_ (mode),
    free_list_ (0),
    lwm_ (lwm),
    hwm_ (hwm),
    inc_ (inc),
    size_ (0)
{
  this->alloc (prealloc);
}

// Destructor - removes all the elements from the free_list

template <class T, class ACE_LOCK>
ACE_Locked_Free_List<T, ACE_LOCK>::~ACE_Locked_Free_List (void)
{
  if (this->mode_ != ACE_PURE_FREE_LIST)
    while (this->free_list_ != 0)
      {
        T *temp = this->free_list_;
        this->free_list_ = this->free_list_->get_next ();
        delete temp;
      }
}

// Inserts an element onto the free list (if we are allowed to manage
// elements withing and it pasts the high water mark, delete the
// element)

template <class T, class ACE_LOCK> void
ACE_Locked_Free_List<T, ACE_LOCK>::add (T *element)
{
  ACE_MT (ACE_GUARD (ACE_LOCK, ace_mon, this->mutex_));

  // Check to see that we not at the high water mark.
  if (this->mode_ == ACE_PURE_FREE_LIST
      || this->size_ < this->hwm_)
    {
      element->set_next (this->free_list_);
      this->free_list_ = element;
      this->size_++;
    }
  else
    delete element;
}

// Takes a element off the freelist and returns it.  It creates <inc>
// new elements if we are allowed to do it and the size is at the low
// water mark.

template <class T, class ACE_LOCK> T *
ACE_Locked_Free_List<T, ACE_LOCK>::remove (void)
{
  ACE_MT (ACE_GUARD_RETURN (ACE_LOCK, ace_mon, this->mutex_, 0));

  // If we are at the low water mark, add some nodes
  if (this->mode_ != ACE_PURE_FREE_LIST && this->size_ <= this->lwm_)
    this->alloc (this->inc_);

  // Remove a node
  T *temp = this->free_list_;

  if (temp != 0)
    {
      this->free_list_ = this->free_list_->get_next ();
      this->size_--;
    }

  return temp;
}


// Returns the current size of the free list

template <class T, class ACE_LOCK> size_t
ACE_Locked_Free_List<T, ACE_LOCK>::size (void)
{
  return this->size_;
}

// Resizes the free list to <newsize>

template <class T, class ACE_LOCK> void
ACE_Locked_Free_List<T, ACE_LOCK>::resize (size_t newsize)
{
  ACE_MT (ACE_GUARD (ACE_LOCK, ace_mon, this->mutex_));

  // Check if we are allowed to resize
  if (this->mode_ != ACE_PURE_FREE_LIST)
    {
      // Check to see if we grow or shrink
      if (newsize < this->size_)
        {
          this->dealloc (this->size_ - newsize);
        }
      else
        {
          this->alloc (newsize - this->size_);
        }
    }
}

// Allocates <n> extra nodes for the freelist

template <class T, class ACE_LOCK> void
ACE_Locked_Free_List<T, ACE_LOCK>::alloc (size_t n)
{
  for (; n > 0; n--)
    {
      T *temp = 0;
      ACE_NEW (temp, T);
      temp->set_next (this->free_list_);
      this->free_list_ = temp;
      this->size_++;
    }
}

// Removes and frees <n> nodes from the freelist.

template <class T, class ACE_LOCK> void
ACE_Locked_Free_List<T, ACE_LOCK>::dealloc (size_t n)
{
  for (; this->free_list_ != 0 && n > 0;
       n--)
    {
      T *temp = this->free_list_;
      this->free_list_ = this->free_list_->get_next ();
      delete temp;
      this->size_--;
    }
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_FREE_LIST_CPP */
