// -*- C++ -*-
//
// $Id: config-icc-common.h 81935 2008-06-12 22:01:53Z jtc $

#ifndef ACE_LINUX_ICC_COMMON_H
#define ACE_LINUX_ICC_COMMON_H
#include /**/ "ace/pre.h"

# define ACE_HAS_CPLUSPLUS_HEADERS
# define ACE_HAS_STDCPP_STL_INCLUDES
# define ACE_HAS_TEMPLATE_TYPEDEFS
# define ACE_HAS_STANDARD_CPP_LIBRARY 1
# define ACE_HAS_WORKING_EXPLICIT_TEMPLATE_DESTRUCTOR
# define ACE_USES_STD_NAMESPACE_FOR_STDCPP_LIB 1
# define ACE_HAS_STRING_CLASS

#if defined (ACE_HAS_CUSTOM_EXPORT_MACROS) && ACE_HAS_CUSTOM_EXPORT_MACROS == 0
#  undef ACE_HAS_CUSTOM_EXPORT_MACROS
#  if defined (ACE_GCC_HAS_TEMPLATE_INSTANTIATION_VISIBILITY_ATTRS)
#    undef ACE_GCC_HAS_TEMPLATE_INSTANTIATION_VISIBILITY_ATTRS
#  endif /* ACE_GCC_HAS_TEMPLATE_INSTANTIATION_VISIBILITY_ATTRS */
#  define ACE_GCC_HAS_TEMPLATE_INSTANTIATION_VISIBILITY_ATTRS 0
#else
#  ifndef ACE_HAS_CUSTOM_EXPORT_MACROS
#    define ACE_HAS_CUSTOM_EXPORT_MACROS
#  endif  /* !ACE_HAS_CUSTOM_EXPORT_MACROS */
#  define ACE_Proper_Export_Flag __attribute__ ((visibility("default")))
#  define ACE_Proper_Import_Flag __attribute__ ((visibility("default")))

#  if (__GNUC__ > 4) || ((__GNUC__ == 4) && (__GNUC_MINOR__ >= 2))
// Sadly, G++ 4.x silently ignores visibility attributes on
// template instantiations, which breaks singletons.
// As a workaround, we use the GCC visibility pragmas.
// And to make them fit in a macro, we use C99's _Pragma()
// http://gcc.gnu.org/bugzilla/show_bug.cgi?id=17470
// This has been fixed in GCC 4.1.1 with FC6 but not with SuSE 10.2
// that gets shipped with GCC 4.1.2 so we assume that with GCC 4.2
// this will be fixed on the head. With FC6 just set this define yourself
#   ifndef ACE_GCC_HAS_TEMPLATE_INSTANTIATION_VISIBILITY_ATTRS
#     define ACE_GCC_HAS_TEMPLATE_INSTANTIATION_VISIBILITY_ATTRS 1
#   endif
#  endif

#  if defined (ACE_GCC_HAS_TEMPLATE_INSTANTIATION_VISIBILITY_ATTRS) && ACE_GCC_HAS_TEMPLATE_INSTANTIATION_VISIBILITY_ATTRS == 1
#   define ACE_EXPORT_SINGLETON_DECLARATION(T) template class ACE_Proper_Export_Flag T
#   define ACE_EXPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) template class ACE_Proper_Export_Flag SINGLETON_TYPE <CLASS, LOCK>;
#  else  /* ACE_GCC_HAS_TEMPLATE_INSTANTIATION_VISIBILITY_ATTRS */
#   define ACE_EXPORT_SINGLETON_DECLARATION(T)     \
        _Pragma ("GCC visibility push(default)")  \
        template class T                          \
        _Pragma ("GCC visibility pop")
#   define ACE_EXPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) \
        _Pragma ("GCC visibility push(default)")                    \
        template class SINGLETON_TYPE<CLASS, LOCK>;                 \
        _Pragma ("GCC visibility pop")
#  endif /* ACE_GCC_HAS_TEMPLATE_INSTANTIATION_VISIBILITY_ATTRS */

// Note that the "__extension__" is needed to prevent g++ from issuing
// an error when using its "-pedantic" command line flag.
# define ACE_IMPORT_SINGLETON_DECLARATION(T) __extension__ extern template class T
# define ACE_IMPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) __extension__ extern template class SINGLETON_TYPE<CLASS, LOCK>;
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

#if !defined (__MINGW32__) && (defined (i386) || defined (__i386__))
  // If running an Intel, assume that it's a Pentium so that
  // ACE_OS::gethrtime () can use the RDTSC instruction.  If running a
  // 486 or lower, be sure to comment this out.  (If not running an
  // Intel CPU, this #define will not be seen because of the i386
  // protection, so it can be ignored.)
# define ACE_HAS_PENTIUM
#endif /* i386 */

#if (defined (ACE_HAS_PENTIUM) || defined (__amd64__) || defined (__x86_64__))
# define ACE_HAS_INTEL_ASSEMBLY
#endif

#if !defined (ACE_LACKS_PRAGMA_ONCE)
  // We define it with a -D with make depend.
# define ACE_LACKS_PRAGMA_ONCE
#endif /* ! ACE_LACKS_PRAGMA_ONCE */

#define ACE_TEMPLATES_REQUIRE_SOURCE

#if (__INTEL_COMPILER >= 910)
# define ACE_EXPLICIT_TEMPLATE_DESTRUCTOR_TAKES_ARGS
#endif

#if defined (__ia64)
# define ACE_HAS_IA64INTRIN_H
# define ACE_HAS_INTRINSIC_INTERLOCKED
#else
# define ACE_HAS_IA32INTRIN_H
#endif

#include /**/ "ace/post.h"
#endif /* ACE_LINUX_ICC_COMMON_H */

