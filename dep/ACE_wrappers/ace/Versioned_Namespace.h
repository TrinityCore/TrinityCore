// -*- C++ -*-

//=============================================================================
/**
 * @file    Versioned_Namespace.h
 *
 * $Id$
 *
 * Versioned namespace support.
 *
 * Useful for preventing conflicts when using a third party library.
 *
 * @author Ossama Othman <ossama@dre.vanderbilt.edu>
 */
//=============================================================================

#ifndef ACE_VERSIONED_NAMESPACE_H
#define ACE_VERSIONED_NAMESPACE_H

#ifndef ACE_CONFIG_MACROS_H
# error This header is only meant to be included by or after "ace/config-lite.h".
#endif  /* !ACE_CONFIG_LITE_H */


#if defined (ACE_HAS_VERSIONED_NAMESPACE) && ACE_HAS_VERSIONED_NAMESPACE == 1

# ifndef ACE_VERSIONED_NAMESPACE_NAME
//#  include "ace/Version.h"

// Preprocessor symbols will not be expanded if they are
// concatenated.  Force the preprocessor to expand them during the
// argument prescan by calling a macro that itself calls another that
// performs the actual concatenation.
#  define ACE_MAKE_VERSIONED_NAMESPACE_NAME_IMPL(MAJOR,MINOR,BETA) ACE_ ## MAJOR ## _ ## MINOR ## _ ## BETA
#  define ACE_MAKE_VERSIONED_NAMESPACE_NAME(MAJOR,MINOR,BETA) ACE_MAKE_VERSIONED_NAMESPACE_NAME_IMPL(MAJOR,MINOR,BETA)
#  define ACE_VERSIONED_NAMESPACE_NAME ACE_MAKE_VERSIONED_NAMESPACE_NAME(ACE_MAJOR_VERSION,ACE_MINOR_VERSION,ACE_BETA_VERSION)
# endif  /* !ACE_VERSIONED_NAMESPACE_NAME */

# define ACE_BEGIN_VERSIONED_NAMESPACE_DECL namespace ACE_VERSIONED_NAMESPACE_NAME {
# define ACE_END_VERSIONED_NAMESPACE_DECL } \
  using namespace ACE_VERSIONED_NAMESPACE_NAME;

#else

# define ACE_VERSIONED_NAMESPACE_NAME
# define ACE_BEGIN_VERSIONED_NAMESPACE_DECL
# define ACE_END_VERSIONED_NAMESPACE_DECL

#endif  /* ACE_HAS_VERSIONED_NAMESPACE */

#endif  /* !ACE_VERSIONED_NAMESPACE_H */
