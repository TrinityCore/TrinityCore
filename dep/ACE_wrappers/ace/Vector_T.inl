// -*- C++ -*-
//
// $Id: Vector_T.inl 81478 2008-04-28 13:22:26Z schmidt $

#include <algorithm>

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

template <class T, size_t DEFAULT_SIZE> ACE_INLINE
ACE_Vector<T, DEFAULT_SIZE>::ACE_Vector (const size_t init_size,
                                         ACE_Allocator* alloc)
  : ACE_Array<T> (init_size == 0 ? DEFAULT_SIZE : init_size, alloc),
    length_ (0)
{
  this->curr_max_size_ = this->max_size ();
}

template <class T, size_t DEFAULT_SIZE> ACE_INLINE
ACE_Vector<T, DEFAULT_SIZE>::~ACE_Vector ()
{
}

template <class T, size_t DEFAULT_SIZE> ACE_INLINE
size_t ACE_Vector<T, DEFAULT_SIZE>::capacity (void) const
{
  return curr_max_size_;
}

template <class T, size_t DEFAULT_SIZE> ACE_INLINE
size_t ACE_Vector<T, DEFAULT_SIZE>::size (void) const
{
  return length_;
}

template <class T, size_t DEFAULT_SIZE> ACE_INLINE
void ACE_Vector<T, DEFAULT_SIZE>::clear (void)
{
  length_ = 0;
}

template <class T, size_t DEFAULT_SIZE> ACE_INLINE
void ACE_Vector<T, DEFAULT_SIZE>::pop_back (void)
{
  if (length_ > 0)
    {
      --length_;
      ACE_Array<T>::size (length_);
    }
}

// Compare this vector with <s> for inequality.

template <class T, size_t DEFAULT_SIZE> ACE_INLINE bool
ACE_Vector<T, DEFAULT_SIZE>::operator!= (const ACE_Vector<T, DEFAULT_SIZE> &s) const
{
  return !(*this == s);
}

template <class T, size_t DEFAULT_SIZE> ACE_INLINE void
ACE_Vector<T, DEFAULT_SIZE>::swap (ACE_Vector &rhs)
{
  ACE_Array<T>::swap (rhs);
  std::swap (this->length_, rhs.length_);
  std::swap (this->curr_max_size_, rhs.curr_max_size_);
}

// ****************************************************************

template <class T, size_t DEFAULT_SIZE> ACE_INLINE void
ACE_Vector_Iterator<T, DEFAULT_SIZE>::dump (void) const
{
  // ACE_TRACE ("ACE_Vector_Iterator<T>::dump");
}

template <class T, size_t DEFAULT_SIZE> ACE_INLINE
ACE_Vector_Iterator<T, DEFAULT_SIZE>::ACE_Vector_Iterator (ACE_Vector<T, DEFAULT_SIZE> &v)
    : current_ (0),
      vector_ (v)
{
  // ACE_TRACE ("ACE_Vector_Iterator<T>::ACE_Vector_Iterator");
}

template <class T, size_t DEFAULT_SIZE> ACE_INLINE int
ACE_Vector_Iterator<T, DEFAULT_SIZE>::advance (void)
{
  // ACE_TRACE ("ACE_Vector_Iterator<T>::advance");

  if (this->current_ < vector_.size ())
    {
      ++this->current_;
      return 1;
    }
  else
    // Already finished iterating.
    return 0;
}

template <class T, size_t DEFAULT_SIZE> ACE_INLINE int
ACE_Vector_Iterator<T, DEFAULT_SIZE>::done (void) const
{
  ACE_TRACE ("ACE_Vector_Iterator<T>::done");

  return this->current_ >= vector_.size ();
}

ACE_END_VERSIONED_NAMESPACE_DECL

