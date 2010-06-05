// -*- C++ -*-
//
// $Id: Functor_String.inl 80826 2008-03-04 14:51:23Z wotte $

#include "ace/ACE.h"
#include "ace/String_Base.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_INLINE unsigned long
ACE_Hash<ACE_CString>::operator () (const ACE_CString &t) const
{
  return t.hash ();
}

ACE_INLINE int
ACE_Equal_To<ACE_CString>::operator () (const ACE_CString &lhs,
                                        const ACE_CString &rhs) const
{
  return lhs == rhs;
}

ACE_INLINE int
ACE_Less_Than<ACE_CString>::operator () (const ACE_CString &lhs,
                                         const ACE_CString &rhs) const
{
  return (lhs < rhs);
}

#if defined (ACE_USES_WCHAR)
ACE_INLINE unsigned long
ACE_Hash<ACE_WString>::operator () (const ACE_WString &t) const
{
  return t.hash ();
}

ACE_INLINE int
ACE_Equal_To<ACE_WString>::operator () (const ACE_WString &lhs,
                                        const ACE_WString &rhs) const
{
  return lhs == rhs;
}

ACE_INLINE int
ACE_Less_Than<ACE_WString>::operator () (const ACE_WString &lhs,
                                         const ACE_WString &rhs) const
{
  return (lhs < rhs);
}

#endif /*ACE_USES_WCHAR*/

ACE_END_VERSIONED_NAMESPACE_DECL
