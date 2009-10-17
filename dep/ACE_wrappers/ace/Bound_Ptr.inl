/* -*- C++ -*- */
// $Id: Bound_Ptr.inl 80826 2008-03-04 14:51:23Z wotte $

// Bound_Ptr.i

#include "ace/Guard_T.h"
#if !defined (ACE_NEW_THROWS_EXCEPTIONS)
#  include "ace/Log_Msg.h"
#endif /* ACE_NEW_THROWS_EXCEPTIONS */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

template <class ACE_LOCK> inline ACE_Bound_Ptr_Counter<ACE_LOCK> *
ACE_Bound_Ptr_Counter<ACE_LOCK>::internal_create (long init_obj_ref_count)
{
  ACE_Bound_Ptr_Counter<ACE_LOCK> *temp = 0;
  ACE_NEW_RETURN (temp,
                  ACE_Bound_Ptr_Counter<ACE_LOCK> (init_obj_ref_count),
                  0);
  return temp;
}

template <class ACE_LOCK> inline ACE_Bound_Ptr_Counter<ACE_LOCK> *
ACE_Bound_Ptr_Counter<ACE_LOCK>::create_strong (void)
{
  // Set initial object reference count to 1.
  ACE_Bound_Ptr_Counter<ACE_LOCK> *temp = internal_create (1);
#if defined (ACE_NEW_THROWS_EXCEPTIONS)
  if (temp == 0)
    ACE_throw_bad_alloc;
#else
  ACE_ASSERT (temp != 0);
#endif /* ACE_NEW_THROWS_EXCEPTIONS */
  return temp;
}

template <class ACE_LOCK> inline long
ACE_Bound_Ptr_Counter<ACE_LOCK>::attach_strong (ACE_Bound_Ptr_Counter<ACE_LOCK>* counter)
{
  ACE_GUARD_RETURN (ACE_LOCK, guard, counter->lock_, -1);

  // Can't attach a strong pointer to an object that has already been deleted.
  if (counter->obj_ref_count_ == -1)
    return -1;

  long new_obj_ref_count = ++counter->obj_ref_count_;
  ++counter->self_ref_count_;

  return new_obj_ref_count;
}

template <class ACE_LOCK> inline long
ACE_Bound_Ptr_Counter<ACE_LOCK>::detach_strong (ACE_Bound_Ptr_Counter<ACE_LOCK>* counter)
{
  ACE_Bound_Ptr_Counter<ACE_LOCK> *counter_del = 0;
  long new_obj_ref_count;

  {
    ACE_GUARD_RETURN (ACE_LOCK, guard, counter->lock_, -1);

    if ((new_obj_ref_count = --counter->obj_ref_count_) == 0)
      // Change the object reference count to -1 to indicate that the
      // object has been deleted, as opposed to a weak pointer that
      // simply hasn't had any strong pointers created from it yet.
      counter->obj_ref_count_ = -1;

    if (--counter->self_ref_count_ == 0)
      // Since counter contains the lock held by the ACE_Guard, the
      // guard needs to be released before freeing the memory holding
      // the lock. So save the pointer to free, then release, then
      // free.
      counter_del = counter;

  }  // Release the lock

  delete counter_del;

  return new_obj_ref_count;
}

template <class ACE_LOCK> inline ACE_Bound_Ptr_Counter<ACE_LOCK> *
ACE_Bound_Ptr_Counter<ACE_LOCK>::create_weak (void)
{
  // Set initial object reference count to 0.

  ACE_Bound_Ptr_Counter<ACE_LOCK> *temp = internal_create (0);
#if defined (ACE_NEW_THROWS_EXCEPTIONS)
  if (temp == 0)
    ACE_throw_bad_alloc;
#else
  ACE_ASSERT (temp != 0);
#endif /* ACE_NEW_THROWS_EXCEPTIONS */
  return temp;
}

template <class ACE_LOCK> inline void
ACE_Bound_Ptr_Counter<ACE_LOCK>::attach_weak (ACE_Bound_Ptr_Counter<ACE_LOCK>* counter)
{
  ACE_GUARD (ACE_LOCK, guard, counter->lock_);

  ++counter->self_ref_count_;
}

template <class ACE_LOCK> inline void
ACE_Bound_Ptr_Counter<ACE_LOCK>::detach_weak (ACE_Bound_Ptr_Counter<ACE_LOCK>* counter)
{
  ACE_Bound_Ptr_Counter<ACE_LOCK> *counter_del = 0;

  {
    ACE_GUARD (ACE_LOCK, guard, counter->lock_);

    if (--counter->self_ref_count_ == 0)
      // Since counter contains the lock held by the ACE_Guard, the
      // guard needs to be released before freeing the memory holding
      // the lock. So save the pointer to free, then release, then
      // free.
      counter_del = counter;

  }  // Release the lock

  delete counter_del;
}

template <class ACE_LOCK> inline bool
ACE_Bound_Ptr_Counter<ACE_LOCK>::object_was_deleted (ACE_Bound_Ptr_Counter<ACE_LOCK> *counter)
{
  ACE_GUARD_RETURN (ACE_LOCK, guard, counter->lock_, 0);

  return counter->obj_ref_count_ == -1;
}

template <class ACE_LOCK> inline
ACE_Bound_Ptr_Counter<ACE_LOCK>::ACE_Bound_Ptr_Counter (long init_obj_ref_count)
  : obj_ref_count_ (init_obj_ref_count),
    self_ref_count_ (1)
{
}

template <class ACE_LOCK> inline
ACE_Bound_Ptr_Counter<ACE_LOCK>::~ACE_Bound_Ptr_Counter (void)
{
}

template <class X, class ACE_LOCK> inline
ACE_Strong_Bound_Ptr<X, ACE_LOCK>::ACE_Strong_Bound_Ptr (X *p)
  : counter_ (COUNTER::create_strong ()),
    ptr_ (p)
{
}

template <class X, class ACE_LOCK> inline
ACE_Strong_Bound_Ptr<X, ACE_LOCK>::ACE_Strong_Bound_Ptr (auto_ptr<X> p)
  : counter_ (COUNTER::create_strong ()),
    ptr_ (p.release())
{
}

template <class X, class ACE_LOCK> inline
ACE_Strong_Bound_Ptr<X, ACE_LOCK>::ACE_Strong_Bound_Ptr (const ACE_Strong_Bound_Ptr<X, ACE_LOCK> &r)
  : counter_ (r.counter_),
    ptr_ (r.ptr_)
{
  COUNTER::attach_strong (this->counter_);
}

template <class X, class ACE_LOCK> inline
ACE_Strong_Bound_Ptr<X, ACE_LOCK>::ACE_Strong_Bound_Ptr (const ACE_Weak_Bound_Ptr<X, ACE_LOCK> &r)
  : counter_ (r.counter_),
    ptr_ (r.ptr_)
{
  // When creating a strong pointer from a weak one we can't assume that the
  // underlying object still exists. Therefore we must check for a return value
  // of -1, which indicates that the object has been destroyed.
  if (COUNTER::attach_strong (this->counter_) == -1)
    {
      // Underlying object has already been deleted, so set this pointer to null.
      this->counter_ = COUNTER::create_strong ();
      this->ptr_ = 0;
    }
}

template <class X, class ACE_LOCK> inline
ACE_Strong_Bound_Ptr<X, ACE_LOCK>::~ACE_Strong_Bound_Ptr (void)
{
  if (COUNTER::detach_strong (this->counter_) == 0)
    delete this->ptr_;
}

template <class X, class ACE_LOCK> inline void
ACE_Strong_Bound_Ptr<X, ACE_LOCK>::operator = (const ACE_Strong_Bound_Ptr<X, ACE_LOCK> &rhs)
{
  // This will work if &r == this, by first increasing the ref count, but
  // why go through all that?
  if (&rhs == this)
    return;

  COUNTER *new_counter = rhs.counter_;
  X_t *new_ptr = rhs.ptr_;
  COUNTER::attach_strong (new_counter);
  if (COUNTER::detach_strong (this->counter_) == 0)
    delete this->ptr_;
  this->counter_ = new_counter;
  this->ptr_ = new_ptr;
}

template <class X, class ACE_LOCK> inline void
ACE_Strong_Bound_Ptr<X, ACE_LOCK>::operator = (const ACE_Weak_Bound_Ptr<X, ACE_LOCK> &rhs)
{
  // This will work if &r == this, by first increasing the ref count, but
  // why go through all that?
  if (&rhs == this)
    return;

  COUNTER *new_counter = rhs.counter_;
  X_t *new_ptr = rhs.ptr_;

  // When creating a strong pointer from a weak one we can't assume that the
  // underlying object still exists. Therefore we must check for a return value
  // of -1, which indicates that the object has been destroyed.
  if (COUNTER::attach_strong (new_counter) == -1)
    {
      // Underlying object has already been deleted, so set this pointer to null.
      new_counter = COUNTER::create_strong ();
      new_ptr = 0;
    }

  if (COUNTER::detach_strong (this->counter_) == 0)
    delete this->ptr_;
  this->counter_ = new_counter;
  this->ptr_ = new_ptr;
}

template <class X, class ACE_LOCK> inline bool
ACE_Strong_Bound_Ptr<X, ACE_LOCK>::operator== (const ACE_Strong_Bound_Ptr<X, ACE_LOCK> &r) const
{
  return this->ptr_ == r.ptr_;
}

template <class X, class ACE_LOCK> inline bool
ACE_Strong_Bound_Ptr<X, ACE_LOCK>::operator== (const ACE_Weak_Bound_Ptr<X, ACE_LOCK> &r) const
{
  // Use the weak pointer's operator== since it will check for null.
  return r == *this;
}

template <class X, class ACE_LOCK> inline bool
ACE_Strong_Bound_Ptr<X, ACE_LOCK>::operator== (X *p) const
{
  return this->ptr_ == p;
}

template <class X, class ACE_LOCK> inline bool
ACE_Strong_Bound_Ptr<X, ACE_LOCK>::operator!= (const ACE_Strong_Bound_Ptr<X, ACE_LOCK> &r) const
{
  return this->ptr_ != r.ptr_;
}

template <class X, class ACE_LOCK> inline bool
ACE_Strong_Bound_Ptr<X, ACE_LOCK>::operator!= (const ACE_Weak_Bound_Ptr<X, ACE_LOCK> &r) const
{
  // Use the weak pointer's operator!= since it will check for null.
  return r != *this;
}

template <class X, class ACE_LOCK> inline bool
ACE_Strong_Bound_Ptr<X, ACE_LOCK>::operator!= (X *p) const
{
  return this->ptr_ != p;
}

template <class X, class ACE_LOCK> inline X *
ACE_Strong_Bound_Ptr<X, ACE_LOCK>::operator-> (void) const
{
  return this->ptr_;
}

template<class X, class ACE_LOCK> inline X &
ACE_Strong_Bound_Ptr<X, ACE_LOCK>::operator *() const
{
  return *this->ptr_;
}

template <class X, class ACE_LOCK> inline X*
ACE_Strong_Bound_Ptr<X, ACE_LOCK>::get (void) const
{
  return this->ptr_;
}

template <class X, class ACE_LOCK> inline int
ACE_Strong_Bound_Ptr<X, ACE_LOCK>::null (void) const
{
  return this->ptr_ == 0;
}

template<class X, class ACE_LOCK> inline void
ACE_Strong_Bound_Ptr<X, ACE_LOCK>::reset (X *p)
{
  COUNTER *old_counter = this->counter_;
  X_t *old_ptr = this->ptr_;
  this->counter_ = COUNTER::create_strong ();
  this->ptr_ = p;
  if (COUNTER::detach_strong (old_counter) == 0)
    delete old_ptr;
}

template<class X, class ACE_LOCK> inline void
ACE_Strong_Bound_Ptr<X, ACE_LOCK>::reset (auto_ptr<X> p)
{
  COUNTER *old_counter = this->counter_;
  X_t *old_ptr = this->ptr_;
  this->counter_ = COUNTER::create_strong ();
  this->ptr_ = p.release ();
  if (COUNTER::detach_strong (old_counter) == 0)
    delete old_ptr;
}

template <class X, class ACE_LOCK> inline
ACE_Weak_Bound_Ptr<X, ACE_LOCK>::ACE_Weak_Bound_Ptr (X *p)
  : counter_ (COUNTER::create_weak ()),
    ptr_ (p)
{
}

template <class X, class ACE_LOCK> inline
ACE_Weak_Bound_Ptr<X, ACE_LOCK>::ACE_Weak_Bound_Ptr (const ACE_Weak_Bound_Ptr<X, ACE_LOCK> &r)
  : counter_ (r.counter_),
    ptr_ (r.ptr_)
{
  COUNTER::attach_weak (this->counter_);
}

template <class X, class ACE_LOCK> inline
ACE_Weak_Bound_Ptr<X, ACE_LOCK>::ACE_Weak_Bound_Ptr (const ACE_Strong_Bound_Ptr<X, ACE_LOCK> &r)
  : counter_ (r.counter_),
    ptr_ (r.ptr_)
{
  COUNTER::attach_weak (this->counter_);
}

template <class X, class ACE_LOCK> inline
ACE_Weak_Bound_Ptr<X, ACE_LOCK>::~ACE_Weak_Bound_Ptr (void)
{
  COUNTER::detach_weak (this->counter_);
}

template <class X, class ACE_LOCK> inline void
ACE_Weak_Bound_Ptr<X, ACE_LOCK>::operator = (const ACE_Weak_Bound_Ptr<X, ACE_LOCK> &rhs)
{
  // This will work if &rhs == this, by first increasing the ref count
  COUNTER *new_counter = rhs.counter_;
  COUNTER::attach_weak (new_counter);
  COUNTER::detach_weak (this->counter_);
  this->counter_ = new_counter;
  this->ptr_ = rhs.ptr_;
}

template <class X, class ACE_LOCK> inline void
ACE_Weak_Bound_Ptr<X, ACE_LOCK>::operator = (const ACE_Strong_Bound_Ptr<X, ACE_LOCK> &rhs)
{
  // This will work if &rhs == this, by first increasing the ref count
  COUNTER *new_counter = rhs.counter_;
  COUNTER::attach_weak (new_counter);
  COUNTER::detach_weak (this->counter_);
  this->counter_ = new_counter;
  this->ptr_ = rhs.ptr_;
}

template <class X, class ACE_LOCK> inline bool
ACE_Weak_Bound_Ptr<X, ACE_LOCK>::operator== (const ACE_Weak_Bound_Ptr<X, ACE_LOCK> &r) const
{
  // A weak pointer must behave as though it is automatically set to null
  // if the underlying object has been deleted.
  if (COUNTER::object_was_deleted (this->counter_))
    return r.ptr_ == 0;

  return this->ptr_ == r.ptr_;
}

template <class X, class ACE_LOCK> inline bool
ACE_Weak_Bound_Ptr<X, ACE_LOCK>::operator== (const ACE_Strong_Bound_Ptr<X, ACE_LOCK> &r) const
{
  // A weak pointer must behave as though it is automatically set to null
  // if the underlying object has been deleted.
  if (COUNTER::object_was_deleted (this->counter_))
    return r.ptr_ == 0;

  return this->ptr_ == r.ptr_;
}

template <class X, class ACE_LOCK> inline bool
ACE_Weak_Bound_Ptr<X, ACE_LOCK>::operator== (X *p) const
{
  // A weak pointer must behave as though it is automatically set to null
  // if the underlying object has been deleted.
  if (COUNTER::object_was_deleted (this->counter_))
    return p == 0;

  return this->ptr_ == p;
}

template <class X, class ACE_LOCK> inline bool
ACE_Weak_Bound_Ptr<X, ACE_LOCK>::operator!= (const ACE_Weak_Bound_Ptr<X, ACE_LOCK> &r) const
{
  // A weak pointer must behave as though it is automatically set to null
  // if the underlying object has been deleted.
  if (COUNTER::object_was_deleted (this->counter_))
    return r.ptr_ != 0;

  return this->ptr_ != r.ptr_;
}

template <class X, class ACE_LOCK> inline bool
ACE_Weak_Bound_Ptr<X, ACE_LOCK>::operator!= (const ACE_Strong_Bound_Ptr<X, ACE_LOCK> &r) const
{
  // A weak pointer must behave as though it is automatically set to null
  // if the underlying object has been deleted.
  if (COUNTER::object_was_deleted (this->counter_))
    return r.ptr_ != 0;

  return this->ptr_ != r.ptr_;
}

template <class X, class ACE_LOCK> inline bool
ACE_Weak_Bound_Ptr<X, ACE_LOCK>::operator!= (X *p) const
{
  // A weak pointer must behave as though it is automatically set to null
  // if the underlying object has been deleted.
  if (COUNTER::object_was_deleted (this->counter_))
    return p != 0;

  return this->ptr_ != p;
}

template <class X, class ACE_LOCK> inline ACE_Strong_Bound_Ptr<X, ACE_LOCK>
ACE_Weak_Bound_Ptr<X, ACE_LOCK>::operator-> (void) const
{
  return ACE_Strong_Bound_Ptr<X, ACE_LOCK> (*this);
}

template <class X, class ACE_LOCK> inline ACE_Strong_Bound_Ptr<X, ACE_LOCK>
ACE_Weak_Bound_Ptr<X, ACE_LOCK>::strong (void) const
{
  return ACE_Strong_Bound_Ptr<X, ACE_LOCK> (*this);
}

template <class X, class ACE_LOCK> inline X*
ACE_Weak_Bound_Ptr<X, ACE_LOCK>::unsafe_get (void) const
{
  // We do not check if the object has been deleted, since this operation
  // is defined to be unsafe!
  return this->ptr_;
}

template <class X, class ACE_LOCK> inline int
ACE_Weak_Bound_Ptr<X, ACE_LOCK>::null (void) const
{
  // A weak pointer must behave as though it is automatically set to null
  // if the underlying object has been deleted.
  if (COUNTER::object_was_deleted (this->counter_))
    return 1;

  return this->ptr_ == 0;
}

template<class X, class ACE_LOCK> inline void
ACE_Weak_Bound_Ptr<X, ACE_LOCK>::reset (X *p)
{
  COUNTER *old_counter = this->counter_;
  this->counter_ = COUNTER::create_weak ();
  this->ptr_ = p;
  COUNTER::detach_weak (old_counter);
}

template<class X, class ACE_LOCK> inline long
ACE_Weak_Bound_Ptr<X, ACE_LOCK>::add_ref ()
{
  return COUNTER::attach_strong (counter_);
}

template<class X, class ACE_LOCK> inline long
ACE_Weak_Bound_Ptr<X, ACE_LOCK>::remove_ref ()
{
  long new_obj_ref_count = COUNTER::detach_strong (counter_);
  if (new_obj_ref_count == 0)
    {
      delete this->ptr_;
      this->ptr_ = 0;
    }
  return new_obj_ref_count;
}

ACE_END_VERSIONED_NAMESPACE_DECL
