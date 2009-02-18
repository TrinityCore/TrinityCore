// -*- C++ -*-

//==========================================================================
/**
 *  @file   config-lite.h
 *
 *  $Id: config-lite.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author (Originally in OS.h)Doug Schmidt <schmidt@cs.wustl.edu>
 *  @author Jesper S. M|ller<stophph@diku.dk>
 *  @author and a cast of thousands...
 *
 *  This file contains the contents of the old config-all.h in order to
 *  avoid a circular dependency problem caused by some of the new
 *  includes added to config-all.h, e.g., OS_main.h.
 */
//==========================================================================

#ifndef ACE_CONFIG_LITE_H
#define ACE_CONFIG_LITE_H

#include /**/ "ace/pre.h"

#include "ace/config-macros.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

// Empty ACE_OS namespace to help identify compiler errors more
// easily.      -- @@ Do we really need this?
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
namespace ACE_OS {}
ACE_END_VERSIONED_NAMESPACE_DECL

// ============================================================================
// UNICODE macros (to be added later)
// ============================================================================

// Get the unicode (i.e. ACE_TCHAR) defines
# include "ace/ace_wchar.h"

// ============================================================================
// at_exit declarations
// ============================================================================

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

// Marker for cleanup, used by ACE_Exit_Info.
extern int ace_exit_hook_marker;

ACE_END_VERSIONED_NAMESPACE_DECL

// For use by <ACE_OS::exit>.
extern "C"
{
  typedef void (*ACE_EXIT_HOOK) (void);
}

// Signature for registering a cleanup function that is used by the
// ACE_Object_Manager and the ACE_Thread_Manager.
# if defined (ACE_HAS_SIG_C_FUNC)
extern "C" {
# endif /* ACE_HAS_SIG_C_FUNC */
typedef void (*ACE_CLEANUP_FUNC)(void *object, void *param) /* throw () */;
# if defined (ACE_HAS_SIG_C_FUNC)
}
# endif /* ACE_HAS_SIG_C_FUNC */

// ============================================================================
// log_msg declarations
// ============================================================================

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

# if defined (ACE_HAS_WIN32_STRUCTURAL_EXCEPTIONS)
typedef int (*ACE_SEH_EXCEPT_HANDLER)(void *);
// Prototype of win32 structured exception handler functions.
// They are used to get the exception handling expression or
// as exception handlers.
# endif /* ACE_HAS_WIN32_STRUCTURAL_EXCEPTIONS */

class ACE_OS_Thread_Descriptor;
class ACE_OS_Log_Msg_Attributes;
typedef void (*ACE_INIT_LOG_MSG_HOOK) (ACE_OS_Log_Msg_Attributes &attr
# if defined (ACE_HAS_WIN32_STRUCTURAL_EXCEPTIONS)
                                       , ACE_SEH_EXCEPT_HANDLER selector
                                       , ACE_SEH_EXCEPT_HANDLER handler
# endif /* ACE_HAS_WIN32_STRUCTURAL_EXCEPTIONS */
                                       );
typedef void (*ACE_INHERIT_LOG_MSG_HOOK) (ACE_OS_Thread_Descriptor*,
                                          ACE_OS_Log_Msg_Attributes &);

typedef void (*ACE_CLOSE_LOG_MSG_HOOK) (void);

typedef void (*ACE_SYNC_LOG_MSG_HOOK) (const ACE_TCHAR *prog_name);

typedef ACE_OS_Thread_Descriptor *(*ACE_THR_DESC_LOG_MSG_HOOK) (void);

ACE_END_VERSIONED_NAMESPACE_DECL

/**
 * @deprecated ACE_DECLARE_STL_REVERSE_ITERATORS is a crutch to be
 *             used until all C++ compiler supported by ACE support
 *             the standard reverse_iterator adapters.
 * @internal   ACE_DECLARE_STL_REVERSE_ITERATORS is not meant for use
 *             outside of ACE.
 */
// STL reverse_iterator declaration generator
// Make sure you include <iterator> in the file you're using this
// generator, and that the following traits are available:
//
//   iterator
//   const_iterator
//   value_type
//   reference
//   pointer
//   const_reference
//   const_pointer
//   difference_type
//
// Once all C++ compilers support the standard reverse_iterator
// adapters, we can drop this generator macro or at least drop the
// MSVC++ or Sun Studio preprocessor conditional blocks.
#if defined (__SUNPRO_CC) && __SUNPRO_CC <= 0x590 \
      && !defined (_STLPORT_VERSION)
  // If we're not using the stlport4 C++ library (which has standard
  // iterators), we need to ensure this is included in order to test
  // the _RWSTD_NO_CLASS_PARTIAL_SPEC feature test macro below.
# include <Cstd/stdcomp.h>
#endif /* __SUNPRO_CC <= 0x580 */
#if (defined (_MSC_VER) && (_MSC_VER <= 1310) && defined (_WIN64)) \
    || defined (ACE_HAS_BROKEN_STD_REVERSE_ITERATOR)
  // VC 7.1 and the latest 64-bit platform SDK still don't define a standard
  // compliant reverse_iterator adapter.
# define ACE_DECLARE_STL_REVERSE_ITERATORS \
  typedef std::reverse_iterator<iterator, value_type> reverse_iterator; \
  typedef std::reverse_iterator<const_iterator, \
                                value_type const> const_reverse_iterator;
#elif defined (__SUNPRO_CC) && __SUNPRO_CC <= 0x590 \
      && defined (_RWSTD_NO_CLASS_PARTIAL_SPEC)
# define ACE_DECLARE_STL_REVERSE_ITERATORS \
  typedef std::reverse_iterator<iterator, \
                                std::input_iterator_tag, \
                                value_type, \
                                reference, \
                                pointer, \
                                difference_type> reverse_iterator; \
  typedef std::reverse_iterator<const_iterator, \
                                std::input_iterator_tag, \
                                value_type const, \
                                const_reference, \
                                const_pointer, \
                                difference_type> const_reverse_iterator;
#else
# define ACE_DECLARE_STL_REVERSE_ITERATORS \
  typedef std::reverse_iterator<iterator>       reverse_iterator; \
  typedef std::reverse_iterator<const_iterator> const_reverse_iterator;
#endif  /* _MSC_VER && _WIN64 */


#include /**/ "ace/post.h"

#endif /* ACE_CONFIG_LITE_H */

