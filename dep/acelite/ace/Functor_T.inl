// -*- C++ -*-
//
// $Id: Functor_T.inl 95332 2011-12-15 11:09:41Z mcorino $

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

template<class RECEIVER> ACE_INLINE
ACE_Member_Function_Command<RECEIVER>::
ACE_Member_Function_Command (RECEIVER &recvr, PTMF ptmf)
  : receiver_(recvr)
  , ptmf_(ptmf)
{
}

template<class RECEIVER> ACE_INLINE
ACE_Member_Function_Command<RECEIVER>::
~ACE_Member_Function_Command (void)
{
}

template<class RECEIVER> ACE_INLINE int
ACE_Member_Function_Command<RECEIVER>::execute (void *)
{
  (this->receiver_.*ptmf_)();
  return 0;
}

template <class TYPE> ACE_INLINE unsigned long
ACE_Hash<TYPE>::operator () (const TYPE &t) const
{
  return t.hash ();
}

template <class TYPE> ACE_INLINE unsigned long
ACE_Pointer_Hash<TYPE>::operator () (TYPE t) const
{
#if defined (ACE_WIN64)
  // The cast below is legit... we only want a hash, and need not convert
  // the hash back to a pointer.
#  pragma warning(push)
#  pragma warning(disable : 4311)   /* Truncate pointer to unsigned long */
#endif /* ACE_WIN64 */
  return reinterpret_cast<unsigned long> (t);
#if defined (ACE_WIN64)
#  pragma warning(pop)
#endif /* ACE_WIN64 */
}

template <class TYPE> ACE_INLINE bool
ACE_Equal_To<TYPE>::operator () (const TYPE &lhs,
                                 const TYPE &rhs) const
{
  return lhs == rhs;
}

template <class TYPE> ACE_INLINE bool
ACE_Less_Than<TYPE>::operator () (const TYPE &lhs,
                                  const TYPE &rhs) const
{
  return lhs < rhs;
}

ACE_END_VERSIONED_NAMESPACE_DECL
