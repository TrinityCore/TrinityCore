// -*- C++ -*-
// $Id: Atomic_Op_GCC_T.inl 95225 2011-12-05 20:25:15Z shuston $

#if defined (ACE_HAS_GCC_ATOMIC_BUILTINS) && (ACE_HAS_GCC_ATOMIC_BUILTINS == 1)

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

template <typename T>
ACE_INLINE
ACE_Atomic_Op_GCC<T>::ACE_Atomic_Op_GCC (void)
  : value_ (0)
{
}

template <typename T>
ACE_INLINE
ACE_Atomic_Op_GCC<T>::ACE_Atomic_Op_GCC (T c)
  : value_ (c)
{
}

template <typename T>
ACE_INLINE
ACE_Atomic_Op_GCC<T>::ACE_Atomic_Op_GCC (
  const ACE_Atomic_Op_GCC<T> &rhs)
  : value_ (rhs.value_)
{
}

template <typename T>
ACE_INLINE T
ACE_Atomic_Op_GCC<T>::operator++ (void)
{
  return __sync_add_and_fetch (&this->value_, 1);
}

template <typename T>
ACE_INLINE T
ACE_Atomic_Op_GCC<T>::operator++ (int)
{
  return __sync_fetch_and_add (&this->value_, 1);
}

template <typename T>
ACE_INLINE T
ACE_Atomic_Op_GCC<T>::operator-- (void)
{
  return __sync_sub_and_fetch (&this->value_, 1);
}

template <typename T>
ACE_INLINE T
ACE_Atomic_Op_GCC<T>::operator-- (int)
{
  return __sync_fetch_and_sub (&this->value_, 1);
}

template <typename T>
ACE_INLINE T
ACE_Atomic_Op_GCC<T>::operator+= (T rhs)
{
  return __sync_add_and_fetch (&this->value_, rhs);
}

template <typename T>
ACE_INLINE T
ACE_Atomic_Op_GCC<T>::operator-= (T rhs)
{
  return __sync_sub_and_fetch (&this->value_, rhs);
}

template <typename T>
ACE_INLINE bool
ACE_Atomic_Op_GCC<T>::operator== (T rhs) const
{
  return (this->value_ == rhs);
}

template <typename T>
ACE_INLINE bool
ACE_Atomic_Op_GCC<T>::operator!= (T rhs) const
{
  return (this->value_ != rhs);
}

template <typename T>
ACE_INLINE bool
ACE_Atomic_Op_GCC<T>::operator>= (T rhs) const
{
  return (this->value_ >= rhs);
}

template <typename T>
ACE_INLINE bool
ACE_Atomic_Op_GCC<T>::operator> (T rhs) const
{
  return (this->value_ > rhs);
}

template <typename T>
ACE_INLINE bool
ACE_Atomic_Op_GCC<T>::operator<= (T rhs) const
{
  return (this->value_ <= rhs);
}

template <typename T>
ACE_INLINE bool
ACE_Atomic_Op_GCC<T>::operator< (T rhs) const
{
  return (this->value_ < rhs);
}

template <typename T>
ACE_INLINE ACE_Atomic_Op_GCC<T> &
ACE_Atomic_Op_GCC<T>::operator= (T rhs)
{
  (void) __sync_lock_test_and_set (&this->value_, rhs);
  return *this;
}

template <typename T>
ACE_INLINE ACE_Atomic_Op_GCC<T> &
ACE_Atomic_Op_GCC<T>::operator= (
   const ACE_Atomic_Op_GCC<T> &rhs)
{
  (void) __sync_lock_test_and_set (&this->value_, rhs.value_);
  return *this;
}

template <typename T>
ACE_INLINE T
ACE_Atomic_Op_GCC<T>::exchange (T newval)
{
  return __sync_val_compare_and_swap (&this->value_, this->value_, newval);
}

template <typename T>
ACE_INLINE T
ACE_Atomic_Op_GCC<T>::value (void) const
{
  return this->value_;
}

template <typename T>
ACE_INLINE volatile T &
ACE_Atomic_Op_GCC<T>::value_i (void)
{
  return this->value_;
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_HAS_GCC_ATOMIC_BUILTINS */
