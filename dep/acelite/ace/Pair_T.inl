// -*- C++ -*-
//
// $Id: Pair_T.inl 92097 2010-09-30 05:41:49Z msmit $

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

template <class T1, class T2> ACE_INLINE
ACE_Reference_Pair<T1, T2>::ACE_Reference_Pair (T1 &t1,
                                                T2 &t2)
  : first_ (t1),
    second_ (t2)
{
}

template <class T1, class T2> ACE_INLINE T1 &
ACE_Reference_Pair<T1, T2>::first (void) const
{
  return this->first_;
}

template <class T1, class T2> ACE_INLINE T2 &
ACE_Reference_Pair<T1, T2>::second (void) const
{
  return this->second_;
}

template <class T1, class T2> ACE_INLINE bool
ACE_Reference_Pair<T1, T2>::operator== (const ACE_Reference_Pair<T1, T2> &rhs) const
{
  return (this->first_ == rhs.first_ &&
          this->second_ == rhs.second_);
}

ACE_END_VERSIONED_NAMESPACE_DECL
