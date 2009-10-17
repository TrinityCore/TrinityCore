// -*- C++ -*-
// ============================================================================
/**
 * @file Exception_Macros.h
 *
 * $Id: Exception_Macros.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *   Writing code that is portable between platforms with or without
 *   native C++ exceptions is hard.  The following macros offer some
 *   help on this task.
 *
 *  @author Nanbor Wang <nanbor@cs.wustl.edu>
 *  @author Aniruddha Gokhale  <gokhale@sahyadri.research.bell-labs.com>
 *  @author Carlos O'Ryan  <coryan@uci.edu>
 *  @author Krishnakumar B <kitty@cs.wustl.edu>, et al.
 */
// ============================================================================
// Macros for handling exceptions.
#ifndef ACE_EXCEPTION_MACROS_H
#define ACE_EXCEPTION_MACROS_H
#include /**/ "ace/pre.h"
#include /**/ "ace/config-all.h"
# if !defined (ACE_LACKS_PRAGMA_ONCE)
#   pragma once
# endif /* ACE_LACKS_PRAGMA_ONCE */
// By default, if the compiler supports native exception handling, assume
// CORBA also support native exception handling. But it can be disabled by
// defining ACE_CORBA_HAS_EXCEPTIONS=0. If the compiler does not support
// exceptions handling, make sure native exception handling is disabled.
#if defined (ACE_HAS_EXCEPTIONS)
#  if defined (ACE_CORBA_HAS_EXCEPTIONS)
#    if (ACE_CORBA_HAS_EXCEPTIONS == 0)
#      undef ACE_USES_NATIVE_EXCEPTIONS
#    else /* ACE_CORBA_HAS_EXCEPTIONS != 0 */
#      define ACE_USES_NATIVE_EXCEPTIONS
#    endif /* ACE_CORBA_HAS_EXCEPTIONS == 0 */
#  else
#    define ACE_USES_NATIVE_EXCEPTIONS
#    define ACE_CORBA_HAS_EXCEPTIONS
#  endif /* ACE_CORBA_HAS_EXCEPTIONS */
#else /* ! ACE_HAS_EXCEPTIONS */
#  undef ACE_CORBA_HAS_EXCEPTIONS
#  undef ACE_USES_NATIVE_EXCEPTIONS
#endif /* ACE_HAS_EXCEPTIONS */
#include /**/ "ace/post.h"
#endif /* ACE_EXCEPTION_MACROS_H */

