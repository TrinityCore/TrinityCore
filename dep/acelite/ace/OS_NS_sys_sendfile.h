// -*- C++ -*-

//=============================================================================
/**
 *  @file    OS_NS_sys_sendfile.h
 *
 *  $Id: OS_NS_sys_sendfile.h 84216 2009-01-22 18:34:40Z johnnyw $
 *
 *  @author Ossama Othman <ossama@dre.vanderbilt.edu>
 */
//=============================================================================

#ifndef ACE_OS_NS_SYS_SENDFILE_H
#define ACE_OS_NS_SYS_SENDFILE_H

#include /**/ "ace/pre.h"

#include /**/ "ace/ACE_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/Basic_Types.h"  /* For ssize_t and off_t. */
#include "ace/config-all.h"

#if defined (ACE_EXPORT_MACRO)
#  undef ACE_EXPORT_MACRO
#endif
#define ACE_EXPORT_MACRO ACE_Export


ACE_BEGIN_VERSIONED_NAMESPACE_DECL

namespace ACE_OS
{
  /// Finds the length of a string (char version).
  ACE_NAMESPACE_INLINE_FUNCTION
  ssize_t sendfile (ACE_HANDLE out_fd,
                    ACE_HANDLE in_fd,
                    off_t * offset,
                    size_t count);

#if defined ACE_HAS_SENDFILE && ACE_HAS_SENDFILE == 0
  extern ACE_Export
  ssize_t sendfile_emulation (ACE_HANDLE out_fd,
                              ACE_HANDLE in_fd,
                              off_t * offset,
                              size_t count);
#endif  /* ACE_HAS_SENDFILE==0 */

}

ACE_END_VERSIONED_NAMESPACE_DECL

# if defined (ACE_HAS_INLINED_OSCALLS)
#   if defined (ACE_INLINE)
#     undef ACE_INLINE
#   endif /* ACE_INLINE */
#   define ACE_INLINE inline
#   include "ace/OS_NS_sys_sendfile.inl"
# endif /* ACE_HAS_INLINED_OSCALLS */

#include /**/ "ace/post.h"

#endif  /* ACE_OS_NS_SYS_SENDFILE_H */
