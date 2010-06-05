// -*- C++ -*-
//
// $Id: Intrusive_Auto_Ptr.inl 81219 2008-04-02 20:23:32Z iliyan $

#include "ace/Guard_T.h"
#include "ace/Log_Msg.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

template <class X> ACE_INLINE
ACE_Intrusive_Auto_Ptr<X>::ACE_Intrusive_Auto_Ptr (X *p, bool addref)
  : rep_ (p)
{
  if (rep_ != 0  && addref)
    X::intrusive_add_ref (rep_);
}

template <class X> ACE_INLINE
ACE_Intrusive_Auto_Ptr<X>::ACE_Intrusive_Auto_Ptr (const ACE_Intrusive_Auto_Ptr<X> &r)
  : rep_ (r.rep_)
{
  if (rep_ != 0)
    X::intrusive_add_ref (rep_);
}

template <class X> ACE_INLINE X *
ACE_Intrusive_Auto_Ptr<X>::operator-> (void) const
{
    return this->rep_;
}

template<class X> ACE_INLINE X &
ACE_Intrusive_Auto_Ptr<X>::operator *() const
{
  return *this->rep_;
}

template <class X> ACE_INLINE X*
ACE_Intrusive_Auto_Ptr<X>::get (void) const
{
  // We return the ACE_Future_rep.
  return this->rep_;
}

template<class X> ACE_INLINE X *
ACE_Intrusive_Auto_Ptr<X>::release (void)
{
  X *p = this->rep_;
  if (this->rep_ != 0)
    X::intrusive_remove_ref (this->rep_);

  this->rep_ = 0;
  return p;
}

template<class X> ACE_INLINE void
ACE_Intrusive_Auto_Ptr<X>::reset (X *p)
{
  // Avoid deleting the underlying auto_ptr if assigning the same actual
  // pointer value.
  if (this->rep_ == p)
    return;

  X *old_rep = this->rep_;
  this->rep_ = p;

  if (this->rep_ != 0)
    X::intrusive_add_ref (this->rep_);

  if (old_rep != 0)
    X::intrusive_remove_ref (old_rep);

  return;
}

template <class X> ACE_INLINE void
ACE_Intrusive_Auto_Ptr<X>::operator = (const ACE_Intrusive_Auto_Ptr<X> &rhs)
{
  // do nothing when aliasing
  if (this->rep_ == rhs.rep_)
    return;

  // assign a zero
  if (rhs.rep_  == 0)
    {
      X::intrusive_remove_ref (rhs.rep_);
      this->rep_ = 0;
      return;
    }

  //  bind <this> to the same <ACE_Intrusive_Auto_Ptr_Rep> as <rhs>.
  X *old_rep = this->rep_;
  this->rep_ = rhs.rep_;
  X::intrusive_add_ref (this->rep_);
  X::intrusive_remove_ref (old_rep);
}

// Copy derived class constructor
template<class X> template <class U> ACE_INLINE
ACE_Intrusive_Auto_Ptr<X>::ACE_Intrusive_Auto_Ptr (const ACE_Intrusive_Auto_Ptr<U> & rhs)
{
  // note implicit cast from U* to T* so illegal copy will generate a
  // compiler warning here
  this->rep_ = rhs.operator-> ();
  X::intrusive_add_ref(this->rep_);
}

  /// Equality operator that returns @c true if both
  /// ACE_Intrusive_Auto_Ptr objects point to the same underlying
  /// representation. It does not compare the actual pointers.
  /**
   * @note It also returns @c true if both objects have just been
   *       instantiated and not used yet.
   */
template<class T, class U> ACE_INLINE bool operator==(ACE_Intrusive_Auto_Ptr<T> const & a, ACE_Intrusive_Auto_Ptr<U> const & b)
{
    return a.get() == b.get();
}

  /// Inequality operator, which is the opposite of equality.
  template<class T, class U> ACE_INLINE bool operator!=(ACE_Intrusive_Auto_Ptr<T> const & a, ACE_Intrusive_Auto_Ptr<U> const & b)
{
    return a.get() != b.get();
}

    template<class T, class U> ACE_INLINE bool operator==(ACE_Intrusive_Auto_Ptr<T> const & a, U * b)
{
    return a.get() == b;
}

      template<class T, class U> ACE_INLINE bool operator!=(ACE_Intrusive_Auto_Ptr<T> & a, U * b)
{
    return a.get() != b;
}

        template<class T, class U> ACE_INLINE bool operator==(T * a, ACE_Intrusive_Auto_Ptr<U> const & b)
{
    return a == b.get();
}

          template<class T, class U> ACE_INLINE bool operator!=(T * a, ACE_Intrusive_Auto_Ptr<U> const & b)
{
    return a != b.get();
}

ACE_END_VERSIONED_NAMESPACE_DECL
