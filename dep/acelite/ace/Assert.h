// -*- C++ -*-

//=============================================================================
/**
 *  @file    Assert.h
 *
 *  $Id: Assert.h 82808 2008-09-23 11:27:27Z smcqueen $
 *
 *  @author Douglas C. Schmidt <schmidt@cs.wustl.edu>
 */
//=============================================================================

#ifndef ACE_ASSERT_H
#define ACE_ASSERT_H

#include /**/ "ace/pre.h"

#include /**/ "ace/ACE_export.h"

#include /**/ "ace/config-all.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL
ACE_Export void __ace_assert(const char *file, int line, const ACE_TCHAR *expression);
ACE_END_VERSIONED_NAMESPACE_DECL

#define ACE_TEST_ASSERT(X) \
  ((X)                      \
   ? static_cast<void>(0)   \
   : ACE_VERSIONED_NAMESPACE_NAME::__ace_assert(__FILE__, __LINE__, ACE_TEXT_CHAR_TO_TCHAR (#X)))

#if defined (ACE_NDEBUG)
#define ACE_ASSERT(x) \
  (static_cast<void>(0))
#else
#define ACE_ASSERT(X) ACE_TEST_ASSERT(X)
#endif /* ACE_NDEBUG */

#include /**/ "ace/post.h"

#endif /* ACE_ASSERT */
