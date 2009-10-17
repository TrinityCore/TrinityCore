// -*- C++ -*-

//==========================================================================
/**
 *  @file    Functor_String.h
 *
 *  $Id: Functor_String.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *   Class template specializations for ACE_*String types implementing
 *   function objects that are used in  various places in ATC. They
 *   could be placed in Functor.h. But we don't want to couple string
 *   types to the rest of ACE+TAO. Hence they are placed in a seperate
 *   file.
 */
//==========================================================================
#ifndef ACE_FUNCTOR_STRING_H
#define ACE_FUNCTOR_STRING_H
#include /**/ "ace/pre.h"

#include /**/ "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include /**/ "ace/ACE_export.h"
#include "ace/SStringfwd.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

////////////////////////////////////////////////////////////
// STL-style Functor Classes and Template Specializations //
////////////////////////////////////////////////////////////

// Forward declaration since we are going to specialize that template
// here. The template itself requires this file so every user of the
// template should also see the specialization.
template <class TYPE> class ACE_Hash;
template <class TYPE> class ACE_Equal_To;
template <class TYPE> class ACE_Less_Than;

/**
 * @class ACE_Equal_To<ACE_CString>
 *
 * @brief Function object for determining whether two ACE_CStrings are
 * equal.
 */
template<>
class ACE_Export ACE_Equal_To<ACE_CString>
{
public:
  int operator () (const ACE_CString &lhs,
                   const ACE_CString &rhs) const;
};

/**
 * @class ACE_Hash<ACE_CString>
 *
 * @brief Function object for hashing a ACE_CString
 */
template<>
class ACE_Export ACE_Hash<ACE_CString>
{
public:
  /// Calls ACE::hash_pjw
  unsigned long operator () (const ACE_CString &lhs) const;
};

/**
 * @class ACE_Less_Than<ACE_CString>
 *
 * @brief Function object for determining whether the first const string
 * is less than the second const string.
 */
template<>
class ACE_Export ACE_Less_Than<ACE_CString>
{
public:
  /// Simply calls ACE_OS::strcmp
  int operator () (const ACE_CString &lhs,
                   const ACE_CString &rhs) const;
};

#if defined (ACE_USES_WCHAR)

/**
 * @class ACE_Equal_To<ACE_WString>
 *
 * @brief Function object for determining whether two ACE_CStrings are
 * equal.
 */
template<>
class ACE_Export ACE_Equal_To<ACE_WString>
{
public:
  int operator () (const ACE_WString &lhs,
                   const ACE_WString &rhs) const;
};

/**
 * @class ACE_Hash<ACE_WString>
 *
 * @brief Function object for hashing a ACE_WString
 */
template<>
class ACE_Export ACE_Hash<ACE_WString>
{
public:
  /// Calls ACE::hash_pjw
  unsigned long operator () (const ACE_WString &lhs) const;
};

/**
 * @class ACE_Less_Than<ACE_WString>
 *
 * @brief Function object for determining whether the first const string
 * is less than the second const string.
 */
template<>
class ACE_Export ACE_Less_Than<ACE_WString>
{
public:
  /// Simply calls ACE_OS::strcmp
  int operator () (const ACE_WString &lhs,
                   const ACE_WString &rhs) const;
};

#endif /*ACE_USES_WCHAR*/

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ace/Functor_String.inl"
#endif /* __ACE_INLINE__ */

#include /**/ "ace/post.h"
#endif /*ACE_FUNCTOR_STRING_H*/

