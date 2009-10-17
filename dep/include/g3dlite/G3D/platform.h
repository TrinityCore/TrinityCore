/**
 @file platform.h

 #defines for platform specific issues.

 @maintainer Morgan McGuire, matrix@graphics3d.com

 @created 2003-06-09
 @edited  2006-01-16
 */

#ifndef G3D_PLATFORM_H
#define G3D_PLATFORM_H

/**
 The version number of G3D in the form: MmmBB ->
 version M.mm [beta BB]
 */
#define G3D_VER 61000

#if defined(G3D_RELEASEDEBUG)
#   define G3D_DEBUGRELEASE
#endif

#if defined(G3D_DEBUGRELEASE) && defined(_DEBUG)
#   undef _DEBUG
#endif

#if !defined(G3D_DEBUG) && (defined(_DEBUG) || defined(G3D_DEBUGRELEASE))
#   define G3D_DEBUG
#endif

#ifdef _MSC_VER
    #define G3D_WIN32
#elif defined(__MINGW32__)
    #define G3D_WIN32
    #define G3D_MINGW32
#elif defined(__linux__)
    #define G3D_LINUX
#elif defined(__OpenBSD__)
    #define G3D_LINUX
#elif defined(__FreeBSD__)
    #define G3D_LINUX
#elif defined(__NetBSD__)
    #define G3D_LINUX
#elif defined(__APPLE__)
    #define G3D_OSX
#else
    #error Unknown platform
#endif


// Default to compiling with SSE, but if you want to compile
// without installing SP5.0 and the Processor Pack on Windows, compile with NO_SSE
// defined (can be passed to the compiler command line with /D "NO_SSE")
#if !defined(NO_SSE)
   #define SSE
#endif

#ifdef G3D_WIN32
// Turn off warnings about deprecated C routines (TODO: revisit)
#   pragma warning (disable : 4996)
#endif

// On g++, recognize cases where the -msse2 flag was not specified
#if defined(SSE) && defined(__GNUC__) && ! defined (__SSE__)
#   undef SSE
#endif

#if defined(__GNUC__)
#    if __STDC_VERSION__ < 199901
#        define restrict __restrict__
#    endif
#endif


// Verify that the supported compilers are being used and that this is a known
// processor.

#ifdef G3D_LINUX
#   ifndef __GNUC__
#       error G3D only supports the gcc compiler on Linux.
#   endif

//#   ifndef __i386__
//#       error G3D only supports x86 machines on Linux.
//#   endif

#   define G3D_DEPRECATED __attribute__((__deprecated__))

#   ifndef __cdecl
#       define __cdecl __attribute__((cdecl))
#   endif

#   ifndef __stdcall
#       define __stdcall __attribute__((stdcall))
#   endif

#   define G3D_CHECK_PRINTF_METHOD_ARGS   __attribute__((__format__(__printf__, 2, 3)))
#   define G3D_CHECK_VPRINTF_METHOD_ARGS  __attribute__((__format__(__printf__, 2, 0)))
#   define G3D_CHECK_PRINTF_ARGS          __attribute__((__format__(__printf__, 1, 2)))
#   define G3D_CHECK_VPRINTF_ARGS         __attribute__((__format__(__printf__, 1, 0)))
#endif


#ifdef G3D_OSX
    #ifndef __GNUC__
        #error G3D only supports the gcc compiler on OS X.
    #endif

    #if defined(__i386__)
        #define G3D_OSX_INTEL
    #elif defined(__PPC__)
        #define G3D_OSX_PPC
    #else
        #define G3D_OSX_UNKNOWN
    #endif

#   ifndef __cdecl
#       define __cdecl __attribute__((cdecl))
#   endif

#   ifndef __stdcall
#       define __stdcall __attribute__((stdcall))
#   endif

#   define G3D_DEPRECATED __attribute__((__deprecated__))

#   define G3D_CHECK_PRINTF_METHOD_ARGS   __attribute__((__format__(__printf__, 2, 3)))
#   define G3D_CHECK_VPRINTF_METHOD_ARGS  __attribute__((__format__(__printf__, 2, 0)))
#   define G3D_CHECK_PRINTF_ARGS          __attribute__((__format__(__printf__, 1, 2)))
#   define G3D_CHECK_VPRINTF_ARGS         __attribute__((__format__(__printf__, 1, 0)))
#endif


#ifdef G3D_WIN32
// Microsoft Visual C++ 7.1 _MSC_VER = 1310
// Microsoft Visual C++ 7.0 _MSC_VER = 1300
// Microsoft Visual C++ 6.0 _MSC_VER = 1200
// Microsoft Visual C++ 5.0 _MSC_VER = 1100

    // Old versions of MSVC (6.0 and previous) don't
    // support C99 for loop scoping rules.  This fixes them.
#   if (_MSC_VER <= 1200)
        // This trick will generate a warning; disable the warning
#       pragma warning (disable : 4127)
#       define for if (false) {} else for
#    endif

#   if (_MSC_VER <= 1200)
//      Nothing we can do on VC6 for deprecated functions
#      define G3D_DEPRECATED
#   else
#      define G3D_DEPRECATED __declspec(deprecated)
#   endif

// Prevent Winsock conflicts by hiding the winsock API
#ifndef _WINSOCKAPI_
#   define _G3D_INTERNAL_HIDE_WINSOCK_
#   define _WINSOCKAPI_
#   endif

// Disable 'name too long for browse information' warning
#   pragma warning (disable : 4786)
// TODO: remove
#   pragma warning (disable : 4244)

#   if defined(_MSC_VER) && (_MSC_VER <= 1200)
        //  VC6 std:: has signed problems in it
#       pragma warning (disable : 4018)
#   endif

#   define ZLIB_WINAPI

// Mingw32 defines restrict
#   ifndef G3D_MINGW32
#          define restrict
#   endif

#   define G3D_CHECK_PRINTF_ARGS
#   define G3D_CHECK_VPRINTF_ARGS
#   define G3D_CHECK_PRINTF_METHOD_ARGS
#   define G3D_CHECK_VPRINTF_METHOD_ARGS

    // On MSVC, we need to link against the multithreaded DLL version of
    // the C++ runtime because that is what SDL and ZLIB are compiled
    // against.  This is not the default for MSVC, so we set the following
    // defines to force correct linking.
    //
    // For documentation on compiler options, see:
    //  http://msdn.microsoft.com/library/default.asp?url=/library/en-us/vccore/html/_core_.2f.md.2c_2f.ml.2c_2f.mt.2c_2f.ld.asp
    //  http://msdn.microsoft.com/library/default.asp?url=/library/en-us/vccore98/HTML/_core_Compiler_Reference.asp
    //

#if 0 //ignore that for Trinity
    // DLL runtime
    #ifndef _DLL
        #define _DLL
    #endif

    // Multithreaded runtime
    #ifndef _MT
        #define _MT 1
    #endif
    // Ensure that we aren't forced into the static lib
    #ifdef _STATIC_CPPLIB
        #undef _STATIC_CPPLIB
    #endif
#endif

    #ifdef _DEBUG
        #pragma comment (linker, "/NODEFAULTLIB:libc.lib")
        #pragma comment (linker, "/NODEFAULTLIB:libcmt.lib")
        #pragma comment (linker, "/NODEFAULTLIB:msvcrt.lib")
        #pragma comment (linker, "/NODEFAULTLIB:libcd.lib")
        #pragma comment (linker, "/NODEFAULTLIB:msvcrtd.lib")
    #else
        #pragma comment(linker, "/NODEFAULTLIB:LIBC.LIB")
        #pragma comment(linker, "/NODEFAULTLIB:msvcrt.lib")
        #pragma comment(linker, "/NODEFAULTLIB:libcd.lib")
        #pragma comment(linker, "/NODEFAULTLIB:libcmtd.lib")
        #pragma comment(linker, "/NODEFAULTLIB:msvcrtd.lib")
    #endif

    // Now set up external linking

    #ifdef _DEBUG
        // zlib and SDL were linked against the release MSVCRT; force
        // the debug version.
        #pragma comment(linker, "/NODEFAULTLIB:MSVCRT.LIB")
#   endif

#   ifndef WIN32_LEAN_AND_MEAN
#       define WIN32_LEAN_AND_MEAN 1
#   endif


#   define NOMINMAX 1
#   include <windows.h>
#   undef WIN32_LEAN_AND_MEAN
#   undef NOMINMAX

#ifdef _G3D_INTERNAL_HIDE_WINSOCK_
#   undef _G3D_INTERNAL_HIDE_WINSOCK_
#   undef _WINSOCKAPI_
#endif

#endif

#   if defined(_MSC_VER) && (_MSC_VER <= 1200)
        // VC6 std:: has signed/unsigned problems
#       pragma warning (disable : 4018)
#   endif

/**
  @def STR(expression)

  Creates a string from the expression.  Frequently used with G3D::Shader
  to express shading programs inline.

  <CODE>STR(this becomes a string)<PRE> evaluates the same as <CODE>"this becomes a string"</CODE>
 */
#define STR(x) #x

#undef G3D_DEPRECATED
#define G3D_DEPRECATED

// Header guard
#endif

