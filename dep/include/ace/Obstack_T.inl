// -*- C++ -*-
//
// $Id: Obstack_T.inl 80826 2008-03-04 14:51:23Z wotte $

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

template <class CHAR> ACE_INLINE size_t
ACE_Obstack_T<CHAR>::length () const
{
  return this->size_ / sizeof (CHAR);
}

template <class CHAR> ACE_INLINE size_t
ACE_Obstack_T<CHAR>::size () const
{
  return this->size_;
}

ACE_END_VERSIONED_NAMESPACE_DECL
