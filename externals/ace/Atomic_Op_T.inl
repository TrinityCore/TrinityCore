// -*- C++ -*-
//
// $Id: Atomic_Op_T.inl 80826 2008-03-04 14:51:23Z wotte $

#include "ace/Guard_T.h"

#include <algorithm>

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

//
// ACE_Atomic_Op_Ex inline functions
//

template <class ACE_LOCK, class TYPE>
ACE_INLINE TYPE
ACE_Atomic_Op_Ex<ACE_LOCK, TYPE>::operator++ (void)
{
  // ACE_TRACE ("ACE_Atomic_Op_Ex<ACE_LOCK, TYPE>::operator++");
  ACE_GUARD_RETURN (ACE_LOCK, ace_mon, this->mutex_, this->value_);
  return ++this->value_;
}

template <class ACE_LOCK, class TYPE>
ACE_INLINE TYPE
ACE_Atomic_Op_Ex<ACE_LOCK, TYPE>::operator+= (
  typename ACE_Atomic_Op_Ex<ACE_LOCK, TYPE>::arg_type rhs)
{
  // ACE_TRACE ("ACE_Atomic_Op_Ex<ACE_LOCK, TYPE>::operator+=");
  ACE_GUARD_RETURN (ACE_LOCK, ace_mon, this->mutex_, this->value_);
  return this->value_ += rhs;
}

template <class ACE_LOCK, class TYPE>
ACE_INLINE TYPE
ACE_Atomic_Op_Ex<ACE_LOCK, TYPE>::operator-- (void)
{
  // ACE_TRACE ("ACE_Atomic_Op_Ex<ACE_LOCK, TYPE>::operator--");
  ACE_GUARD_RETURN (ACE_LOCK, ace_mon, this->mutex_, this->value_);
  return --this->value_;
}

template <class ACE_LOCK, class TYPE>
ACE_INLINE TYPE
ACE_Atomic_Op_Ex<ACE_LOCK, TYPE>::operator-= (
  typename ACE_Atomic_Op_Ex<ACE_LOCK, TYPE>::arg_type rhs)
{
  // ACE_TRACE ("ACE_Atomic_Op_Ex<ACE_LOCK, TYPE>::operator-=");
  ACE_GUARD_RETURN (ACE_LOCK, ace_mon, this->mutex_, this->value_);
  return this->value_ -= rhs;
}

template <class ACE_LOCK, class TYPE>
ACE_INLINE
ACE_Atomic_Op_Ex<ACE_LOCK, TYPE>::ACE_Atomic_Op_Ex (
  ACE_Atomic_Op_Ex<ACE_LOCK, TYPE> const & rhs)
  : mutex_ (rhs.mutex_)
  , value_ (rhs.value ())  // rhs.value() returns atomically
{
  // ACE_TRACE ("ACE_Atomic_Op_Ex<ACE_LOCK, TYPE>::ACE_Atomic_Op_Ex");
}

template <class ACE_LOCK, class TYPE>
ACE_INLINE TYPE
ACE_Atomic_Op_Ex<ACE_LOCK, TYPE>::operator++ (int)
{
  // ACE_TRACE ("ACE_Atomic_Op_Ex<ACE_LOCK, TYPE>::operator++");
  ACE_GUARD_RETURN (ACE_LOCK, ace_mon, this->mutex_, this->value_);
  return this->value_++;
}

template <class ACE_LOCK, class TYPE>
ACE_INLINE TYPE
ACE_Atomic_Op_Ex<ACE_LOCK, TYPE>::operator-- (int)
{
  // ACE_TRACE ("ACE_Atomic_Op_Ex<ACE_LOCK, TYPE>::operator--");
  ACE_GUARD_RETURN (ACE_LOCK, ace_mon, this->mutex_, this->value_);
  return this->value_--;
}

template <class ACE_LOCK, class TYPE>
ACE_INLINE bool
ACE_Atomic_Op_Ex<ACE_LOCK, TYPE>::operator== (
  typename ACE_Atomic_Op_Ex<ACE_LOCK, TYPE>::arg_type rhs) const
{
  // ACE_TRACE ("ACE_Atomic_Op_Ex<ACE_LOCK, TYPE>::operator==");
  ACE_GUARD_RETURN (ACE_LOCK, ace_mon, this->mutex_, false);
  return this->value_ == rhs;
}

template <class ACE_LOCK, class TYPE>
ACE_INLINE bool
ACE_Atomic_Op_Ex<ACE_LOCK, TYPE>::operator!= (
  typename ACE_Atomic_Op_Ex<ACE_LOCK, TYPE>::arg_type rhs) const
{
  // ACE_TRACE ("ACE_Atomic_Op_Ex<ACE_LOCK, TYPE>::operator!=");
  return !(*this == rhs);
}

template <class ACE_LOCK, class TYPE>
ACE_INLINE bool
ACE_Atomic_Op_Ex<ACE_LOCK, TYPE>::operator>= (
  typename ACE_Atomic_Op_Ex<ACE_LOCK, TYPE>::arg_type rhs) const
{
  // ACE_TRACE ("ACE_Atomic_Op_Ex<ACE_LOCK, TYPE>::operator>=");
  ACE_GUARD_RETURN (ACE_LOCK, ace_mon, this->mutex_, false);
  return this->value_ >= rhs;
}

template <class ACE_LOCK, class TYPE>
ACE_INLINE bool
ACE_Atomic_Op_Ex<ACE_LOCK, TYPE>::operator> (
  typename ACE_Atomic_Op_Ex<ACE_LOCK, TYPE>::arg_type rhs) const
{
  // ACE_TRACE ("ACE_Atomic_Op_Ex<ACE_LOCK, TYPE>::operator>");
  ACE_GUARD_RETURN (ACE_LOCK, ace_mon, this->mutex_, false);
  return this->value_ > rhs;
}

template <class ACE_LOCK, class TYPE>
ACE_INLINE bool
ACE_Atomic_Op_Ex<ACE_LOCK, TYPE>::operator<= (
  typename ACE_Atomic_Op_Ex<ACE_LOCK, TYPE>::arg_type rhs) const
{
  // ACE_TRACE ("ACE_Atomic_Op_Ex<ACE_LOCK, TYPE>::operator<=");
  ACE_GUARD_RETURN (ACE_LOCK, ace_mon, this->mutex_, false);
  return this->value_ <= rhs;
}

template <class ACE_LOCK, class TYPE>
ACE_INLINE bool
ACE_Atomic_Op_Ex<ACE_LOCK, TYPE>::operator< (
  typename ACE_Atomic_Op_Ex<ACE_LOCK, TYPE>::arg_type rhs) const
{
  // ACE_TRACE ("ACE_Atomic_Op_Ex<ACE_LOCK, TYPE>::operator<");
  ACE_GUARD_RETURN (ACE_LOCK, ace_mon, this->mutex_, false);
  return this->value_ < rhs;
}

template <class ACE_LOCK, class TYPE>
ACE_INLINE ACE_Atomic_Op_Ex<ACE_LOCK, TYPE> &
ACE_Atomic_Op_Ex<ACE_LOCK, TYPE>::operator= (
  ACE_Atomic_Op_Ex<ACE_LOCK, TYPE> const & rhs)
{
  // ACE_TRACE ("ACE_Atomic_Op_Ex<ACE_LOCK, TYPE>::operator=");

  ACE_Atomic_Op_Ex<ACE_LOCK, TYPE> tmp (rhs);

  ACE_GUARD_RETURN (ACE_LOCK, ace_mon, this->mutex_, *this);
  std::swap (this->value_, tmp.value_);

  return *this;
}

template <class ACE_LOCK, class TYPE>
ACE_INLINE TYPE
ACE_Atomic_Op_Ex<ACE_LOCK, TYPE>::value (void) const
{
  // ACE_TRACE ("ACE_Atomic_Op_Ex<ACE_LOCK, TYPE>::value");
  ACE_GUARD_RETURN (ACE_LOCK, ace_mon, this->mutex_, this->value_);
  return this->value_;
}

template <class ACE_LOCK, class TYPE>
ACE_INLINE TYPE &
ACE_Atomic_Op_Ex<ACE_LOCK, TYPE>::value_i (void)
{
  // Explicitly return <value_> (by reference).  This gives the user
  // full, unrestricted access to the underlying value.  This method
  // will usually be used in conjunction with explicit access to the
  // lock.  Use with care ;-)
  return this->value_;
}

template <class ACE_LOCK, class TYPE>
ACE_INLINE ACE_Atomic_Op_Ex<ACE_LOCK, TYPE> &
ACE_Atomic_Op_Ex<ACE_LOCK, TYPE>::operator= (
  typename ACE_Atomic_Op_Ex<ACE_LOCK, TYPE>::arg_type rhs)
{
  // ACE_TRACE ("ACE_Atomic_Op_Ex<ACE_LOCK, TYPE>::operator=");
  ACE_GUARD_RETURN (ACE_LOCK, ace_mon, this->mutex_, *this);
  this->value_ = rhs;
  return *this;
}

//
// ACE_Atomic_Op inline functions
//

template <class ACE_LOCK, class TYPE> ACE_INLINE
ACE_Atomic_Op<ACE_LOCK, TYPE>::ACE_Atomic_Op (
  ACE_Atomic_Op<ACE_LOCK, TYPE> const & rhs)
  : impl_ (own_mutex_, rhs.value ())
{
  // ACE_TRACE ("ACE_Atomic_Op<ACE_LOCK, TYPE>::ACE_Atomic_Op");
}


template <class ACE_LOCK, class TYPE>
ACE_INLINE ACE_Atomic_Op<ACE_LOCK, TYPE> &
ACE_Atomic_Op<ACE_LOCK, TYPE>::operator= (
  typename ACE_Atomic_Op<ACE_LOCK, TYPE>::arg_type i)
{
  this->impl_ = i;
  return *this;
}

template <class ACE_LOCK, class TYPE>
ACE_INLINE ACE_Atomic_Op<ACE_LOCK, TYPE> &
ACE_Atomic_Op<ACE_LOCK, TYPE>::operator= (
  ACE_Atomic_Op<ACE_LOCK, TYPE> const & rhs)
{
  this->impl_ = rhs.impl_;
  return *this;
}

template <class ACE_LOCK, class TYPE>
ACE_INLINE TYPE
ACE_Atomic_Op<ACE_LOCK, TYPE>::operator++ (void)
{
  return ++this->impl_;
}

template <class ACE_LOCK, class TYPE>
ACE_INLINE TYPE
ACE_Atomic_Op<ACE_LOCK, TYPE>::operator++ (int)
{
  return this->impl_++;
}

template <class ACE_LOCK, class TYPE>
ACE_INLINE TYPE
ACE_Atomic_Op<ACE_LOCK, TYPE>::operator+= (
  typename ACE_Atomic_Op<ACE_LOCK, TYPE>::arg_type rhs)
{
  return this->impl_ += rhs;
}

template <class ACE_LOCK, class TYPE>
ACE_INLINE TYPE
ACE_Atomic_Op<ACE_LOCK, TYPE>::operator-- (void)
{
  return --this->impl_;
}

template <class ACE_LOCK, class TYPE>
ACE_INLINE TYPE
ACE_Atomic_Op<ACE_LOCK, TYPE>::operator-- (int)
{
  return this->impl_--;
}

template <class ACE_LOCK, class TYPE>
ACE_INLINE TYPE
ACE_Atomic_Op<ACE_LOCK, TYPE>::operator-= (
  typename ACE_Atomic_Op<ACE_LOCK, TYPE>::arg_type rhs)
{
  return this->impl_ -= rhs;
}

template <class ACE_LOCK, class TYPE>
ACE_INLINE bool
ACE_Atomic_Op<ACE_LOCK, TYPE>::operator== (
  typename ACE_Atomic_Op<ACE_LOCK, TYPE>::arg_type rhs) const
{
  return this->impl_ == rhs;
}

template <class ACE_LOCK, class TYPE>
ACE_INLINE bool
ACE_Atomic_Op<ACE_LOCK, TYPE>::operator!= (
  typename ACE_Atomic_Op<ACE_LOCK, TYPE>::arg_type rhs) const
{
  return this->impl_ != rhs;
}

template <class ACE_LOCK, class TYPE>
ACE_INLINE bool
ACE_Atomic_Op<ACE_LOCK, TYPE>::operator>= (
  typename ACE_Atomic_Op<ACE_LOCK, TYPE>::arg_type rhs) const
{
  return this->impl_ >= rhs;
}

template <class ACE_LOCK, class TYPE>
ACE_INLINE bool
ACE_Atomic_Op<ACE_LOCK, TYPE>::operator> (
  typename ACE_Atomic_Op<ACE_LOCK, TYPE>::arg_type rhs) const
{
  return this->impl_ > rhs;
}

template <class ACE_LOCK, class TYPE>
ACE_INLINE bool
ACE_Atomic_Op<ACE_LOCK, TYPE>::operator<= (
  typename ACE_Atomic_Op<ACE_LOCK, TYPE>::arg_type rhs) const
{
  return this->impl_ <= rhs;
}

template <class ACE_LOCK, class TYPE>
ACE_INLINE bool
ACE_Atomic_Op<ACE_LOCK, TYPE>::operator< (
  typename ACE_Atomic_Op<ACE_LOCK, TYPE>::arg_type rhs) const
{
  return this->impl_ < rhs;
}

template <class ACE_LOCK, class TYPE>
ACE_INLINE TYPE
ACE_Atomic_Op<ACE_LOCK, TYPE>::value (void) const
{
  return this->impl_.value ();
}

template <class ACE_LOCK, class TYPE>
ACE_INLINE void
ACE_Atomic_Op<ACE_LOCK, TYPE>::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  this->impl_.dump ();
#endif /* ACE_HAS_DUMP */
  return;
}

template <class ACE_LOCK, class TYPE>
ACE_INLINE ACE_LOCK &
ACE_Atomic_Op<ACE_LOCK, TYPE>::mutex (void)
{
  return this->own_mutex_;
}

template <class ACE_LOCK, class TYPE>
ACE_INLINE TYPE &
ACE_Atomic_Op<ACE_LOCK, TYPE>::value_i (void)
{
  return this->impl_.value_i ();
}

ACE_END_VERSIONED_NAMESPACE_DECL
