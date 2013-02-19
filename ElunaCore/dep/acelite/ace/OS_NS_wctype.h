// -*- C++ -*-

//=============================================================================
/**
 *  @file   OS_NS_wctype.h
 *
 *  $Id: OS_NS_wctype.h 83891 2008-11-28 11:01:50Z johnnyw $
 *
 *  @author Johnny Willemsen  <jwillemsen@remedy.nl>
 */
//=============================================================================

#ifndef ACE_OS_NS_WCTYPE_H
# define ACE_OS_NS_WCTYPE_H

# include /**/ "ace/pre.h"

# include "ace/config-all.h"

# if !defined (ACE_LACKS_PRAGMA_ONCE)
#  pragma once
# endif /* ACE_LACKS_PRAGMA_ONCE */

#include /**/ "ace/ACE_export.h"

#if defined (ACE_EXPORT_MACRO)
#  undef ACE_EXPORT_MACRO
#endif
#define ACE_EXPORT_MACRO ACE_Export

#include "ace/os_include/os_ctype.h"
#if defined ACE_HAS_WCHAR
# include "ace/os_include/os_wctype.h"
#endif /* ACE_HAS_WCHAR */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

namespace ACE_OS {

  // these are non-standard names...

  /** @name Functions from <cctype>
   *
   *  Included are the functions defined in <cctype> and their <cwctype>
   *  equivalents.
   *
   *  Since they are often implemented as macros, we don't use the same name
   *  here.  Instead, we change by prepending "ace_".
   */
  //@{
#if defined (ACE_HAS_WCHAR)
  /// Tests @a c for the property specified by the @a desc argument
  ACE_NAMESPACE_INLINE_FUNCTION
  int ace_iswctype(wint_t c, wctype_t desc);
#endif /* ACE_HAS_WCHAR */
  //@}

} /* namespace ACE_OS */

ACE_END_VERSIONED_NAMESPACE_DECL

# if defined (ACE_HAS_INLINED_OSCALLS)
#   if defined (ACE_INLINE)
#     undef ACE_INLINE
#   endif /* ACE_INLINE */
#   define ACE_INLINE inline
#   include "ace/OS_NS_wctype.inl"
# endif /* ACE_HAS_INLINED_OSCALLS */

# include /**/ "ace/post.h"
#endif /* ACE_OS_NS_WCTYPE_H */
