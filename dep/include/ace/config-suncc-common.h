// -*- C++ -*-
//
// $Id: config-suncc-common.h 81935 2008-06-12 22:01:53Z jtc $

#ifndef ACE_SUNCC_COMMON_H
#define ACE_SUNCC_COMMON_H
#include /**/ "ace/pre.h"

# define ACE_HAS_CPLUSPLUS_HEADERS
# define ACE_HAS_STDCPP_STL_INCLUDES
# define ACE_HAS_TEMPLATE_TYPEDEFS
# define ACE_HAS_STANDARD_CPP_LIBRARY 1
# define ACE_HAS_WORKING_EXPLICIT_TEMPLATE_DESTRUCTOR
# define ACE_USES_STD_NAMESPACE_FOR_STDCPP_LIB 1
# define ACE_HAS_STRING_CLASS
# define ACE_EXPLICIT_TEMPLATE_DESTRUCTOR_TAKES_ARGS
# define ACE_HAS_THR_C_DEST 1
# define ACE_LACKS_SWAB
#if defined (ACE_HAS_CUSTOM_EXPORT_MACROS) && ACE_HAS_CUSTOM_EXPORT_MACROS == 0
#  undef ACE_HAS_CUSTOM_EXPORT_MACROS
#else
#  ifndef ACE_HAS_CUSTOM_EXPORT_MACROS
#    define ACE_HAS_CUSTOM_EXPORT_MACROS
#  endif  /* !ACE_HAS_CUSTOM_EXPORT_MACROS */
#  define ACE_Proper_Export_Flag __attribute__ ((visibility("default")))
#  define ACE_Proper_Import_Flag
#  define ACE_EXPORT_SINGLETON_DECLARATION(T) template class ACE_Proper_Export_Flag T
#  define ACE_EXPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) template class ACE_Proper_Export_Flag SINGLETON_TYPE <CLASS, LOCK>;
#  define ACE_IMPORT_SINGLETON_DECLARATION(T) __extension__ extern template class T
#  define ACE_IMPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) __extension__ extern template class SINGLETON_TYPE<CLASS, LOCK>;
#endif  /* ACE_HAS_CUSTOM_EXPORT_MACROS == 0 */

// __EXCEPTIONS is defined with -fexceptions, the egcs default.  It
// is not defined with -fno-exceptions, the ACE default for g++.
// ACE_HAS_EXCEPTIONS is defined in
// include/makeinclude/wrapper_macros.GNU, so this really isn't
// necessary.  Just in case . . .
# if defined (__EXCEPTIONS) && !defined (ACE_HAS_EXCEPTIONS)
#   define ACE_HAS_EXCEPTIONS
# endif /* __EXCEPTIONS && ! ACE_HAS_EXCEPTIONS */

# if defined (ACE_HAS_EXCEPTIONS)
#   define ACE_NEW_THROWS_EXCEPTIONS
# endif /* ACE_HAS_EXCEPTIONS */

#if (defined (i386) || defined (__i386__)) && !defined (ACE_SIZEOF_LONG_DOUBLE)
# define ACE_SIZEOF_LONG_DOUBLE 12
#endif /* i386 */

#if defined (i386) || defined (__i386__)
  // If running an Intel, assume that it's a Pentium so that
  // ACE_OS::gethrtime () can use the RDTSC instruction.  If running a
  // 486 or lower, be sure to comment this out.  (If not running an
  // Intel CPU, this #define will not be seen because of the i386
  // protection, so it can be ignored.)
# define ACE_HAS_PENTIUM
#endif /* i386 */

#if !defined (ACE_LACKS_PRAGMA_ONCE)
  // We define it with a -D with make depend.
# define ACE_LACKS_PRAGMA_ONCE
#endif /* ! ACE_LACKS_PRAGMA_ONCE */

#define ACE_TEMPLATES_REQUIRE_SOURCE

#include /**/ "ace/post.h"
#endif /* ACE_SUNCC_COMMON_H */

