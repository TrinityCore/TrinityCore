// -*- C++ -*-

//=============================================================================
/**
 *  @file   OS_Errno.h
 *
 *  $Id: OS_Errno.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author (Originally in OS.h)Doug Schmidt <schmidt@cs.wustl.edu>
 */
//=============================================================================

#ifndef ACE_OS_ERRNO_H
#define ACE_OS_ERRNO_H
#include /**/ "ace/pre.h"

#include /**/ "ace/ACE_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/OS_NS_errno.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class ACE_Errno_Guard
 *
 * @brief Provides a wrapper to improve performance when thread-specific
 * errno must be saved and restored in a block of code.
 *
 * The typical use-case for this is the following:
 * int error = errno;
 * call_some_function_that_might_change_errno ();
 * errno = error;
 * This can be replaced with
 * {
 * ACE_Errno_Guard guard (errno);
 * call_some_function_that_might_change_errno ();
 * }
 * This implementation is more elegant and more efficient since it
 * avoids an unnecessary second access to thread-specific storage
 * by caching a pointer to the value of errno in TSS.
 */
class ACE_Export ACE_Errno_Guard
{
public:
  ///  Stash the value of <error> into <error_> and initialize the
  ///  <errno_ptr_> to the address of <errno_ref>.
  ACE_Errno_Guard (ACE_ERRNO_TYPE &errno_ref,
                   int error);

  ///  Stash the value of @c errno into <error_> and initialize the
  ///  <errno_ptr_> to the address of <errno_ref>.
  ACE_Errno_Guard (ACE_ERRNO_TYPE &errno_ref);

  /// Reset the value of @c errno to <error>.
  ~ACE_Errno_Guard (void);

#if defined (ACE_HAS_WINCE_BROKEN_ERRNO)
  /// Assign <errno_ref> to <error_>.
  int operator= (const ACE_ERRNO_TYPE &errno_ref);
#endif /* ACE_HAS_WINCE_BROKEN_ERRNO */

  /// Assign <error> to <error_>.
  int operator= (int error);

  /// Compare <error> with <error_> for equality.
  bool operator== (int error);

  /// Compare <error> with <error_> for inequality.
  bool operator!= (int error);

private:
  // Prevent copying
  ACE_Errno_Guard (const ACE_Errno_Guard &);
  ACE_Errno_Guard &operator= (const ACE_Errno_Guard &);

#if defined (ACE_MT_SAFE)
  ACE_ERRNO_TYPE *errno_ptr_;
#endif /* ACE_MT_SAFE */
  int error_;
};

ACE_END_VERSIONED_NAMESPACE_DECL

// Inlining this class on debug builds with gcc on Solaris can cause
// deadlocks during static initialization. On non debug builds it
// causes compilation errors.
#if defined (ACE_HAS_INLINED_OSCALLS) && \
    (!defined (__GNUG__) || !defined (__sun__))
# if defined (ACE_INLINE)
#  undef ACE_INLINE
# endif /* ACE_INLINE */
# define ACE_INLINE inline
# include "ace/OS_Errno.inl"
#endif /* ACE_HAS_INLINED_OSCALLS */

#include /**/ "ace/post.h"
#endif /* ACE_OS_ERRNO_H */

