// -*- C++ -*-

//=============================================================================
/**
 *  @file   OS_NS_errno.h
 *
 *  $Id: OS_NS_errno.h 94454 2011-09-08 17:36:56Z johnnyw $
 *
 *  @author Douglas C. Schmidt <schmidt@cs.wustl.edu>
 *  @author Jesper S. M|ller<stophph@diku.dk>
 *  @author and a cast of thousands...
 *
 *  Originally in OS.h.
 */
//=============================================================================

#ifndef ACE_OS_NS_ERRNO_H
# define ACE_OS_NS_ERRNO_H

# include /**/ "ace/pre.h"

# include "ace/config-lite.h"

# if !defined (ACE_LACKS_PRAGMA_ONCE)
#  pragma once
# endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/os_include/os_errno.h"
#include /**/ "ace/ACE_export.h"

#if defined (ACE_EXPORT_MACRO)
#  undef ACE_EXPORT_MACRO
#endif
#define ACE_EXPORT_MACRO ACE_Export

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

namespace ACE_OS {

  ACE_NAMESPACE_INLINE_FUNCTION
  int last_error (void);

  ACE_NAMESPACE_INLINE_FUNCTION
  void last_error (int error);

  ACE_NAMESPACE_INLINE_FUNCTION
  int set_errno_to_last_error (void);

  ACE_NAMESPACE_INLINE_FUNCTION
  int set_errno_to_wsa_last_error (void);

} /* namespace ACE_OS */

#if defined (ACE_HAS_WINCE_BROKEN_ERRNO)
/**
 * @class ACE_CE_Errno
 *
 * Some versions of CE don't support @c errno and some versions'
 * implementations are busted.  So we implement our own.
 * Our implementation takes up one Tls key, however, it does not
 * allocate memory from the heap so there's no problem with cleaning
 * up the errno when a thread exit.
 */
class ACE_Export ACE_CE_Errno
{
public:
  ACE_CE_Errno () {}
  static void init ();
  static void fini ();
  static ACE_CE_Errno *instance ();

  operator int (void) const;
  int operator= (int);

private:
  static ACE_CE_Errno *instance_;
  static DWORD errno_key_;
};

# define errno (* (ACE_CE_Errno::instance ()))
#endif /* ACE_HAS_WINCE_BROKEN_ERRNO */

#if defined (ACE_HAS_WINCE_BROKEN_ERRNO)
#  define ACE_ERRNO_TYPE ACE_CE_Errno
#  define ACE_ERRNO_GET ACE_CE_Errno::instance ()->operator int()
#else
#  if !defined (ACE_ERRNO_TYPE)
#   define ACE_ERRNO_TYPE int
#  endif  /* !ACE_ERRNO_TYPE */
#  define ACE_ERRNO_GET errno
#endif /* ACE_HAS_WINCE_BROKEN_ERRNO */

ACE_END_VERSIONED_NAMESPACE_DECL

# if defined (ACE_HAS_INLINED_OSCALLS)
#   if defined (ACE_INLINE)
#     undef ACE_INLINE
#   endif /* ACE_INLINE */
#   define ACE_INLINE inline
#   include "ace/OS_NS_errno.inl"
# endif /* ACE_HAS_INLINED_OSCALLS */

# include /**/ "ace/post.h"
#endif /* ACE_OS_NS_ERRNO_H */
