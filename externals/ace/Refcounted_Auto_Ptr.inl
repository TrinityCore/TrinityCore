// -*- C++ -*-
//
// $Id: Refcounted_Auto_Ptr.inl 81179 2008-03-31 19:00:29Z iliyan $

#include "ace/Guard_T.h"
#include "ace/Log_Msg.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

template <class X, class ACE_LOCK> inline long
ACE_Refcounted_Auto_Ptr_Rep<X, ACE_LOCK>::count (void) const
{
  return this->ref_count_.value();
}

template <class X, class ACE_LOCK> inline long
ACE_Refcounted_Auto_Ptr<X, ACE_LOCK>::count (void) const
{
  return this->rep_->count ();
}

template <class X, class ACE_LOCK> inline bool
ACE_Refcounted_Auto_Ptr<X, ACE_LOCK>::null (void) const
{
  return (this->rep_ == 0 || this->rep_->get () == 0);
}

template <class X, class ACE_LOCK> inline ACE_Refcounted_Auto_Ptr_Rep<X, ACE_LOCK> *
ACE_Refcounted_Auto_Ptr_Rep<X, ACE_LOCK>::internal_create (X *p)
{
  ACE_Refcounted_Auto_Ptr_Rep<X, ACE_LOCK> *temp = 0;
  ACE_NEW_RETURN (temp,
                  (ACE_Refcounted_Auto_Ptr_Rep<X, ACE_LOCK>) (p),
                  0);
  return temp;
}

template <class X, class ACE_LOCK> inline ACE_Refcounted_Auto_Ptr_Rep<X, ACE_LOCK> *
ACE_Refcounted_Auto_Ptr_Rep<X, ACE_LOCK>::create (X *p)
{
  // Yes set ref count to zero.
  ACE_Refcounted_Auto_Ptr_Rep<X, ACE_LOCK> *temp = internal_create (p);
#if defined (ACE_NEW_THROWS_EXCEPTIONS)
  if (temp == 0)
    ACE_throw_bad_alloc;
#else
  ACE_ASSERT (temp != 0);
#endif /* ACE_NEW_THROWS_EXCEPTIONS */
   return temp;
}

template <class X, class ACE_LOCK> inline ACE_Refcounted_Auto_Ptr_Rep<X, ACE_LOCK> *
ACE_Refcounted_Auto_Ptr_Rep<X, ACE_LOCK>::attach (ACE_Refcounted_Auto_Ptr_Rep<X, ACE_LOCK>*& rep)
{
  if (rep == 0)
    return 0;

  ++rep->ref_count_;

  return rep;
}

template <class X, class ACE_LOCK> inline void
ACE_Refcounted_Auto_Ptr_Rep<X, ACE_LOCK>::detach (ACE_Refcounted_Auto_Ptr_Rep<X, ACE_LOCK>*& rep)
{
  if (rep == 0)
    return;

  if (rep->ref_count_-- == 0)
    delete rep;
}

template <class X, class ACE_LOCK> inline
ACE_Refcounted_Auto_Ptr_Rep<X, ACE_LOCK>::ACE_Refcounted_Auto_Ptr_Rep (X *p)
  : ptr_ (p),
    ref_count_ (0)
{
}

template <class X, class ACE_LOCK> inline
ACE_Refcounted_Auto_Ptr_Rep<X, ACE_LOCK>::~ACE_Refcounted_Auto_Ptr_Rep (void)
{
}

template <class X, class ACE_LOCK> inline X *
ACE_Refcounted_Auto_Ptr_Rep<X, ACE_LOCK>::get (void) const
{
  return this->ptr_.get ();
}

template <class X, class ACE_LOCK> inline
ACE_Refcounted_Auto_Ptr<X, ACE_LOCK>::ACE_Refcounted_Auto_Ptr (X *p)
  : rep_ (AUTO_REFCOUNTED_PTR_REP::create (p))
{
}

template <class X, class ACE_LOCK> inline
ACE_Refcounted_Auto_Ptr<X, ACE_LOCK>::ACE_Refcounted_Auto_Ptr (const ACE_Refcounted_Auto_Ptr<X, ACE_LOCK> &r)
  : rep_ (AUTO_REFCOUNTED_PTR_REP::attach (((ACE_Refcounted_Auto_Ptr<X, ACE_LOCK> &) r).rep_))
{
}

template <class X, class ACE_LOCK> inline bool
ACE_Refcounted_Auto_Ptr<X, ACE_LOCK>::operator== (const ACE_Refcounted_Auto_Ptr<X, ACE_LOCK> &r) const
{
  return r.rep_ == this->rep_;
}

template <class X, class ACE_LOCK> inline bool
ACE_Refcounted_Auto_Ptr<X, ACE_LOCK>::operator!= (const ACE_Refcounted_Auto_Ptr<X, ACE_LOCK> &r) const
{
  return r.rep_ != this->rep_;
}

template <class X, class ACE_LOCK> inline X *
ACE_Refcounted_Auto_Ptr<X, ACE_LOCK>::operator-> (void) const
{
    return this->rep_->get();
}

template<class X, class ACE_LOCK> inline X &
ACE_Refcounted_Auto_Ptr<X, ACE_LOCK>::operator *() const
{
  return *this->rep_->get ();
}

template<class X, class ACE_LOCK> inline bool
ACE_Refcounted_Auto_Ptr<X, ACE_LOCK>::operator !() const
{
  return this->rep_->get () == 0;
}

template<class X, class ACE_LOCK> inline
ACE_Refcounted_Auto_Ptr<X, ACE_LOCK>::operator bool () const
{
  return this->rep_->get () != 0;
}

template <class X, class ACE_LOCK> inline X*
ACE_Refcounted_Auto_Ptr<X, ACE_LOCK>::get (void) const
{
  // We return the ACE_Future_rep.
  return this->rep_->get ();
}

template<class X, class ACE_LOCK> inline X *
ACE_Refcounted_Auto_Ptr<X, ACE_LOCK>::release (void)
{
  X *p = this->get ();
  AUTO_REFCOUNTED_PTR_REP::detach (this->rep_);
  this->rep_ = 0;
  return p;
}

template<class X, class ACE_LOCK> inline void
ACE_Refcounted_Auto_Ptr<X, ACE_LOCK>::reset (X *p)
{
  // Avoid deleting the underlying auto_ptr if assigning the same actual
  // pointer value.
  if (this->get () == p)
    return;

  AUTO_REFCOUNTED_PTR_REP *old_rep = this->rep_;
  if ((this->rep_ = AUTO_REFCOUNTED_PTR_REP::create (p)) != 0)
    AUTO_REFCOUNTED_PTR_REP::detach (old_rep);
  else
    this->rep_ = old_rep;
  return;
}

template <class X, class ACE_LOCK> inline void
ACE_Refcounted_Auto_Ptr<X, ACE_LOCK>::operator = (const ACE_Refcounted_Auto_Ptr<X, ACE_LOCK> &rhs)
{
  //  bind <this> to the same <ACE_Refcounted_Auto_Ptr_Rep> as <r>.
  AUTO_REFCOUNTED_PTR_REP *old_rep = this->rep_;
  if (rhs.rep_ != 0)
    {
      this->rep_ = AUTO_REFCOUNTED_PTR_REP::attach
        (const_cast<ACE_Refcounted_Auto_Ptr<X, ACE_LOCK>& > (rhs).rep_);
      if (this->rep_ != 0)
        AUTO_REFCOUNTED_PTR_REP::detach (old_rep);
    }
  else    // Assign a 0 rep to this
    {
      AUTO_REFCOUNTED_PTR_REP::detach (old_rep);
      this->rep_ = 0;
    }
}

ACE_END_VERSIONED_NAMESPACE_DECL
