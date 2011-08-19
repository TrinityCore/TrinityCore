// $Id: Vector_T.cpp 92069 2010-09-28 11:38:59Z johnnyw $

#ifndef ACE_VECTOR_T_CPP
#define ACE_VECTOR_T_CPP

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/Vector_T.h"

#if !defined (__ACE_INLINE__)
#include "ace/Vector_T.inl"
#endif /* __ACE_INLINE__ */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_ALLOC_HOOK_DEFINE(ACE_Vector)

template <class T, size_t DEFAULT_SIZE>
void ACE_Vector<T, DEFAULT_SIZE>::resize (const size_t new_size,
                                          const T& t)
{
  ACE_Array<T>::size (new_size);
  if (new_size > length_)
    for (size_t i = length_; i < new_size; ++i)
      (*this)[i]=t;

  curr_max_size_ = this->max_size ();
  length_ = new_size;
}

template <class T, size_t DEFAULT_SIZE>
void ACE_Vector<T, DEFAULT_SIZE>::push_back (const T& elem)
{
  if (length_ == curr_max_size_)
    {
      ACE_Array<T>::size (curr_max_size_ * 2);
      curr_max_size_ = this->max_size ();
    }
  else
    ACE_Array<T>::size (length_ + 1);

  ++length_;
  (*this)[length_-1] = elem;
}

template <class T, size_t DEFAULT_SIZE>
void ACE_Vector<T, DEFAULT_SIZE>::dump (void) const
{
}

// Compare this vector with <s> for equality.
template <class T, size_t DEFAULT_SIZE> bool
ACE_Vector<T, DEFAULT_SIZE>::operator== (const ACE_Vector<T, DEFAULT_SIZE> &s) const
{
  if (this == &s)
    return true;
  else if (this->size () != s.size ())
    return false;

  const size_t len = s.size ();
  for (size_t slot = 0; slot < len; ++slot)
    if ((*this)[slot] != s[slot])
      return false;

  return true;
}

// ****************************************************************

template <class T, size_t DEFAULT_SIZE> int
ACE_Vector_Iterator<T, DEFAULT_SIZE>::next (T *&item)
{
  // ACE_TRACE ("ACE_Vector_Iterator<T>::next");

  if (this->done ())
    {
      item = 0;
      return 0;
    }
  else
    {
      item = &vector_[current_];
      return 1;
    }
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_VECTOR_T_CPP */
