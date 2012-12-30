// -*- C++ -*-
//
// $Id: config-g++-common.h 96157 2012-09-27 06:33:47Z johnnyw $

// This configuration file is designed to be included by another,
// specific configuration file.  It provides config information common
// to all g++ platforms, including egcs.

#ifndef ACE_GNUG_COMMON_H
#define ACE_GNUG_COMMON_H
#include /**/ "ace/pre.h"

#if !defined (ACE_CC_NAME)
# define ACE_CC_NAME ACE_TEXT ("g++")
#endif
#define ACE_CC_MAJOR_VERSION __GNUC__
#define ACE_CC_MINOR_VERSION __GNUC_MINOR__
#define ACE_CC_BETA_VERSION (0)

#define ACE_HAS_CPLUSPLUS_HEADERS
#define ACE_HAS_STDCPP_STL_INCLUDES
#define ACE_HAS_STANDARD_CPP_LIBRARY 1
#define ACE_HAS_WORKING_EXPLICIT_TEMPLATE_DESTRUCTOR
#define ACE_USES_STD_NAMESPACE_FOR_STDCPP_LIB 1
#define ACE_TEMPLATES_REQUIRE_SOURCE

#if (__GNUC__ > 3 || (__GNUC__ == 3 && __GNUC_MINOR__ >= 4))
# define ACE_EXPLICIT_TEMPLATE_DESTRUCTOR_TAKES_ARGS
#endif /* __GNUC__ >= 3.4 */

#define ACE_NEW_THROWS_EXCEPTIONS
#if (__GNUC__ >= 4 || (__GNUC__ == 3 && __GNUC_MINOR__ >= 3))
// Versions of g++ prior to 3.3 had a buggy operator // new(nothrow)[]().
#  define ACE_HAS_NEW_NOTHROW
#endif /* __GNUC__ >= 3.3 */

#if (__GNUC__ >= 5 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 7))
# if __cplusplus > 199711L
#  define ACE_HAS_CPP11
# endif
#endif

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

#if !defined (ACE_HAS_GCC_CONSTRUCTOR_ATTRIBUTE)
#define ACE_HAS_GCC_CONSTRUCTOR_ATTRIBUTE 1
#endif

#if !defined (ACE_HAS_GCC_DESTRUCTOR_ATTRIBUTE)
#define ACE_HAS_GCC_DESTRUCTOR_ATTRIBUTE 1
#endif

#if !defined (ACE_HAS_GCC_DEPRECATED_ATTRIBUTE)
#define ACE_HAS_GCC_DEPRECATED_ATTRIBUTE 1
#endif

#if !defined (ACE_HAS_GCC_FORMAT_ATTRIBUTE)
#define ACE_HAS_GCC_FORMAT_ATTRIBUTE 1
#endif

#if (ACE_HAS_GCC_CONSTRUCTOR_ATTRIBUTE == 1)
# define ACE_GCC_CONSTRUCTOR_ATTRIBUTE __attribute__ ((constructor))
#endif

#if (ACE_HAS_GCC_DESTRUCTOR_ATTRIBUTE == 1)
# define ACE_GCC_DESTRUCTOR_ATTRIBUTE __attribute__ ((destructor))
#endif

#if (ACE_HAS_GCC_DEPRECATED_ATTRIBUTE == 1)
#define ACE_DEPRECATED __attribute__ ((deprecated))
#endif

#if (ACE_HAS_GCC_FORMAT_ATTRIBUTE == 1)
# define ACE_GCC_FORMAT_ATTRIBUTE(TYPE, STR_INDEX, FIRST_INDEX) \
   __attribute__ ((format (TYPE, STR_INDEX, FIRST_INDEX)))
#endif

// GNU g++ >= 4.x implements "#pragma once".
#if (__GNUC__ < 4) && !defined (ACE_LACKS_PRAGMA_ONCE)
// We define it with a -D with make depend.
# define ACE_LACKS_PRAGMA_ONCE
#endif /* ! ACE_LACKS_PRAGMA_ONCE */

// Take advantage of G++ (>= 4.x) visibility attributes to generate
// improved shared library binaries.
#if (__GNUC__ >= 4) && !defined (__MINGW32__) && !defined (ACE_HAS_CEGCC)

# if defined (ACE_HAS_CUSTOM_EXPORT_MACROS) && ACE_HAS_CUSTOM_EXPORT_MACROS == 0
#  undef ACE_HAS_CUSTOM_EXPORT_MACROS
#  if defined (ACE_GCC_HAS_TEMPLATE_INSTANTIATION_VISIBILITY_ATTRS)
#    undef ACE_GCC_HAS_TEMPLATE_INSTANTIATION_VISIBILITY_ATTRS
#  endif /* ACE_GCC_HAS_TEMPLATE_INSTANTIATION_VISIBILITY_ATTRS */
#  define ACE_GCC_HAS_TEMPLATE_INSTANTIATION_VISIBILITY_ATTRS 0
# else
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

# endif  /* ACE_HAS_CUSTOM_EXPORT_MACROS == 0 */
#endif  /* __GNU__ >= 4 */

// GCC >= 4.1 provides __sync_XXXX builtins for use in atomic operations
// although the builtins are provided globally they are not supported on all platforms
#if defined (ACE_HAS_THREADS)
#if (__GNUC__ > 4) || ((__GNUC__ == 4) && (__GNUC_MINOR__ >= 1))
# if defined (__powerpc__)
// The builtins seem to be provided for all powerpc platforms
#   define ACE_HAS_GCC_ATOMIC_BUILTINS 1
# if ((__GNUC__ == 4) && (__GNUC_MINOR__ == 1) && (__GNUC_PATCHLEVEL__ == 1))
// PPU GCC 4.1.1 doesn't have builtin atomic ops for size 1/2
#  define ACE_LACKS_GCC_ATOMIC_BUILTINS_2
#  define ACE_LACKS_GCC_ATOMIC_BUILTINS_1
# endif
# endif
# if defined (__ia64)
// The builtins seem to be provided for the IA64 platforms
#   define ACE_HAS_GCC_ATOMIC_BUILTINS 1
# endif
# if defined (__amd64__) || defined (__x86_64__)
// The builtin's are provided also for 64bit linux
#   define ACE_HAS_GCC_ATOMIC_BUILTINS 1
# endif
#endif
#endif /* ACE_HAS_THREADS */

#include /**/ "ace/post.h"
#endif /* ACE_GNUG_COMMON_H */
