// -*- C++ -*-

//=============================================================================
/**
 *  @file    Functor.inl
 *
 *  $Id: Functor.inl 80826 2008-03-04 14:51:23Z wotte $
 *
 *  Inlinable method definitions for non-templatized classes
 *  and template specializations implementing the GOF Command Pattern,
 *  and STL-style functors.
 *
 *
 *  @author Chris Gill           <cdgill@cs.wustl.edu>
 *
 * Based on Command Pattern implementations originally done by
 *
 * Carlos O'Ryan        <coryan@cs.wustl.edu>
 * Douglas C. Schmidt   <schmidt@cs.wustl.edu>
 * Sergio Flores-Gaitan <sergio@cs.wustl.edu>
 *
 * and on STL-style functor implementations originally done by
 * Irfan Pyarali  <irfan@cs.wustl.edu>
 */
//=============================================================================

#include "ace/ACE.h"
#include "ace/OS_NS_string.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

//////////////////////////////////////////////////////////////
// GOF Command Pattern Classes and Template Specializations //
//////////////////////////////////////////////////////////////

// Default constructor.

ACE_INLINE
ACE_Command_Base::ACE_Command_Base (void)
{
}

////////////////////////////////////////////////////////////
// STL-style Functor Classes and Template Specializations //
////////////////////////////////////////////////////////////

ACE_INLINE unsigned long
ACE_Hash<char>::operator () (char t) const
{
  return t;
}

#if defined (ACE_HAS_WCHAR) && ! defined (ACE_LACKS_NATIVE_WCHAR_T)
ACE_INLINE unsigned long
ACE_Hash<wchar_t>::operator () (wchar_t t) const
{
  return t;
}
#endif /* ACE_HAS_WCHAR && ! ACE_LACKS_NATIVE_WCHAR_T */

ACE_INLINE unsigned long
ACE_Hash<signed char>::operator () (signed char t) const
{
  return t;
}

ACE_INLINE unsigned long
ACE_Hash<unsigned char>::operator () (unsigned char t) const
{
  return t;
}

#if 0
ACE_INLINE unsigned long
ACE_Hash<ACE_INT16>::operator () (ACE_INT16 t) const
{
  return t;
}

ACE_INLINE unsigned long
ACE_Hash<ACE_UINT16>::operator () (ACE_UINT16 t) const
{
  return t;
}

ACE_INLINE unsigned long
ACE_Hash<ACE_INT32>::operator () (ACE_INT32 t) const
{
  return static_cast<unsigned long> (t);
}

ACE_INLINE unsigned long
ACE_Hash<ACE_UINT32>::operator () (ACE_UINT32 t) const
{
  return t;
}

ACE_INLINE unsigned long
ACE_Hash<ACE_UINT64>::operator () (ACE_UINT64 t) const
{
#if (ACE_SIZEOF_LONG == 4)
  return ACE_U64_TO_U32 (t);
#else
  return static_cast<unsigned long> (t);
#endif /* ACE_SIZEOF_LONG */
}
#endif

ACE_INLINE unsigned long
ACE_Hash<short>::operator () (short t) const
{
  return static_cast<unsigned long> (t);
}

ACE_INLINE unsigned long
ACE_Hash<unsigned short>::operator () (unsigned short t) const
{
  return static_cast<unsigned long> (t);
}

ACE_INLINE unsigned long
ACE_Hash<int>::operator () (int t) const
{
  return static_cast<unsigned long> (t);
}

ACE_INLINE unsigned long
ACE_Hash<unsigned int>::operator () (unsigned int t) const
{
  return static_cast<unsigned long> (t);
}

ACE_INLINE unsigned long
ACE_Hash<long>::operator () (long t) const
{
  return static_cast<unsigned long> (t);
}

ACE_INLINE unsigned long
ACE_Hash<unsigned long>::operator () (unsigned long t) const
{
  return t;
}

// This #if needs to match the one in Functor.h
#if !defined (ACE_LACKS_LONGLONG_T) && (ACE_SIZEOF_LONG < 8)
ACE_INLINE unsigned long
ACE_Hash<ACE_INT64>::operator () (ACE_INT64 t) const
{
  return static_cast<unsigned long> (t);
}
#endif /* !ACE_LACKS_LONGLONG_T && ACE_SIZEOF_LONG < 8 */

#if (ACE_SIZEOF_LONG < 8)
ACE_INLINE unsigned long
ACE_Hash<ACE_UINT64>::operator () (const ACE_UINT64 &t) const
{
#if (ACE_SIZEOF_LONG == 4)
  return ACE_U64_TO_U32 (t);
#else
  return static_cast<unsigned long> (t);
#endif /* ACE_SIZEOF_LONG */
}
#endif /* !ACE_LACKS_UNSIGNEDLONGLONG_T */

ACE_INLINE unsigned long
ACE_Hash<const char *>::operator () (const char *t) const
{
  return ACE::hash_pjw (t);
}

ACE_INLINE unsigned long
ACE_Hash<char *>::operator () (const char *t) const
{
  return ACE::hash_pjw (t);
}

ACE_INLINE unsigned long
ACE_Hash<void *>::operator () (const void *t) const
{
  return static_cast<unsigned long> (reinterpret_cast<uintptr_t> (t));
}

/***********************************************************************/
ACE_INLINE int
ACE_Equal_To<const char *>::operator () (const char *lhs, const char *rhs) const
{
  return !ACE_OS::strcmp (lhs, rhs);
}

ACE_INLINE int
ACE_Equal_To<char *>::operator () (const char *lhs, const char *rhs) const
{
  return !ACE_OS::strcmp (lhs, rhs);
}

ACE_INLINE int
ACE_Equal_To<ACE_UINT16>::operator () (const ACE_UINT16 lhs, const ACE_UINT16 rhs) const
{
  return (lhs == rhs);
}

ACE_INLINE int
ACE_Equal_To<ACE_INT16>::operator () (const ACE_INT16 lhs, const ACE_INT16 rhs) const
{
  return (lhs == rhs);
}

ACE_INLINE int
ACE_Equal_To<ACE_UINT32>::operator () (const ACE_UINT32 lhs, const ACE_UINT32 rhs) const
{
  return (lhs == rhs);
}

ACE_INLINE int
ACE_Equal_To<ACE_INT32>::operator () (const ACE_INT32 lhs, const ACE_INT32 rhs) const
{
  return (lhs == rhs);
}

ACE_INLINE int
ACE_Equal_To<ACE_UINT64>::operator () (const ACE_UINT64 lhs, const ACE_UINT64 rhs) const
{
  return (lhs == rhs);
}

/****************************************************************************/
ACE_INLINE int
ACE_Less_Than<const char *>::operator () (const char *lhs, const char *rhs) const
{
  return (ACE_OS::strcmp (lhs, rhs) < 0) ? 1 : 0;
}

ACE_INLINE int
ACE_Less_Than<char *>::operator () (const char *lhs, const char *rhs) const
{
  return (ACE_OS::strcmp (lhs, rhs) < 0) ? 1 : 0;
}

#if defined (ACE_HAS_WCHAR)

ACE_INLINE unsigned long
ACE_Hash<const wchar_t *>::operator () (const wchar_t *t) const
{
  return ACE::hash_pjw (t);
}

ACE_INLINE unsigned long
ACE_Hash<wchar_t *>::operator () (const wchar_t *t) const
{
  return ACE::hash_pjw (t);
}

ACE_INLINE int
ACE_Equal_To<const wchar_t *>::operator () (const wchar_t *lhs,
                                            const wchar_t *rhs) const
{
  return !ACE_OS::strcmp (lhs, rhs);
}

ACE_INLINE int
ACE_Equal_To<wchar_t *>::operator () (const wchar_t *lhs,
                                      const wchar_t *rhs) const
{
  return !ACE_OS::strcmp (lhs, rhs);
}

ACE_INLINE int
ACE_Less_Than<const wchar_t *>::operator () (const wchar_t *lhs, const wchar_t *rhs) const
{
  return (ACE_OS::strcmp (lhs, rhs) < 0) ? 1 : 0;
}

ACE_INLINE int
ACE_Less_Than<wchar_t *>::operator () (const wchar_t *lhs, const wchar_t *rhs) const
{
  return (ACE_OS::strcmp (lhs, rhs) < 0) ? 1 : 0;
}

#endif  // ACE_HAS_WCHAR

ACE_END_VERSIONED_NAMESPACE_DECL
