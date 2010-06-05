// -*- C++ -*-

//=============================================================================
/**
 *  @file   OS_NS_sys_time.h
 *
 *  $Id: OS_NS_sys_time.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Douglas C. Schmidt <schmidt@cs.wustl.edu>
 *  @author Jesper S. M|ller<stophph@diku.dk>
 *  @author and a cast of thousands...
 *
 *  Originally in OS.h.
 */
//=============================================================================

#ifndef ACE_OS_NS_SYS_TIME_H
# define ACE_OS_NS_SYS_TIME_H

# include /**/ "ace/pre.h"

# include "ace/config-all.h"

# if !defined (ACE_LACKS_PRAGMA_ONCE)
#  pragma once
# endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/Time_Value.h"
#include /**/ "ace/ACE_export.h"

#if defined (ACE_EXPORT_MACRO)
#  undef ACE_EXPORT_MACRO
#endif
#define ACE_EXPORT_MACRO ACE_Export

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

namespace ACE_OS
{
#if defined (ACE_WIN32) && defined (_WIN32_WCE)
// Something is a bit brain-damaged here and I'm not sure what... this code
// compiled before the OS reorg for ACE 5.4. Since then it hasn't - eVC
// complains that the operators that return ACE_Time_Value are C-linkage
// functions that can't return a C++ class. The only way I've found to
// defeat this is to wrap the whole class in extern "C++".
//    - Steve Huston, 23-Aug-2004
extern "C++" {
#endif

  ACE_NAMESPACE_INLINE_FUNCTION
  ACE_Time_Value gettimeofday (void);

#if defined (ACE_WIN32) && defined (_WIN32_WCE)
}
#endif
} /* namespace ACE_OS */

ACE_END_VERSIONED_NAMESPACE_DECL

# if defined (ACE_HAS_INLINED_OSCALLS)
#   if defined (ACE_INLINE)
#     undef ACE_INLINE
#   endif /* ACE_INLINE */
#   define ACE_INLINE inline
#   include "ace/OS_NS_sys_time.inl"
# endif /* ACE_HAS_INLINED_OSCALLS */

# include /**/ "ace/post.h"
#endif /* ACE_OS_NS_SYS_TIME_H */

