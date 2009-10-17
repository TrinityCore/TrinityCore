// -*- C++ -*-

//=============================================================================
/**
 *  @file   OS_NS_pwd.h
 *
 *  $Id: OS_NS_pwd.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Douglas C. Schmidt <schmidt@cs.wustl.edu>
 *  @author Jesper S. M|ller<stophph@diku.dk>
 *  @author and a cast of thousands...
 *
 *  Originally in OS.h.
 */
//=============================================================================

#ifndef ACE_OS_NS_PWD_H
#define ACE_OS_NS_PWD_H

# include /**/ "ace/pre.h"

# include "ace/config-all.h"

# if !defined (ACE_LACKS_PRAGMA_ONCE)
#  pragma once
# endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/os_include/os_pwd.h"
#include /**/ "ace/ACE_export.h"

#if defined (ACE_EXPORT_MACRO)
#  undef ACE_EXPORT_MACRO
#endif
#define ACE_EXPORT_MACRO ACE_Export

# if defined (ACE_HAS_BROKEN_R_ROUTINES)
#   undef getpwnam_r
# endif /* ACE_HAS_BROKEN_R_ROUTINES */

struct passwd;

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

namespace ACE_OS
{


  //@{ @name A set of wrappers for password routines.

  ACE_NAMESPACE_INLINE_FUNCTION
  void endpwent (void);

  ACE_NAMESPACE_INLINE_FUNCTION
  struct passwd *getpwent (void);

  ACE_NAMESPACE_INLINE_FUNCTION
  struct passwd *getpwnam (const char *user);

  ACE_NAMESPACE_INLINE_FUNCTION
  struct passwd *getpwnam_r (const char *name,
                             struct passwd *pwent,
                             char *buffer,
                             int buflen);
  ACE_NAMESPACE_INLINE_FUNCTION
  void setpwent (void);
  //@}

} /* namespace ACE_OS */

ACE_END_VERSIONED_NAMESPACE_DECL

# if defined (ACE_HAS_INLINED_OSCALLS)
#   if defined (ACE_INLINE)
#     undef ACE_INLINE
#   endif /* ACE_INLINE */
#   define ACE_INLINE inline
#   include "ace/OS_NS_pwd.inl"
# endif /* ACE_HAS_INLINED_OSCALLS */

# include /**/ "ace/post.h"
#endif /* ACE_OS_NS_PWD_H */

