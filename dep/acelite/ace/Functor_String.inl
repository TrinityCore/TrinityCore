// -*- C++ -*-
//
// $Id: Functor_String.inl 93411 2011-02-18 22:21:16Z hillj $

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

ACE_INLINE unsigned long
ACE_Hash<std::string>::operator () (const std::string &t) const
{
  return ACE::hash_pjw (t.c_str (), t.length ());
}


ACE_INLINE int
ACE_Equal_To<std::string>::operator () (const std::string &lhs,
                                        const std::string &rhs) const
{
  return lhs == rhs;
}

ACE_INLINE int
ACE_Less_Than<std::string>::operator () (const std::string &lhs,
                                         const std::string &rhs) const
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
