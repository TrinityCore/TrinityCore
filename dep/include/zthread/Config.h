/*
 * Copyright (c) 2005, Eric Crahen
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is furnished
 * to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 */

#ifndef __ZTCONFIG_H__
#define __ZTCONFIG_H__

// =====================================================================================
// The following section describes the symbols the configure program will define.
// If you are not using configure (autoconf), then you make want to set these by 
// uncommenting them here, or whatever other means you'd like.
// =====================================================================================

// (configure)
// Uncomment to disable actually changing the operating systems real thread priority
// #define ZTHREAD_DISABLE_PRIORITY 1

// (configure)
// Uncomment to disable compiling the interrupt() hook mechanisms.
// #define ZTHREAD_DISABLE_INTERRUPT 1

// (configure)
// Uncomment to select a Win32 ThreadOps implementation that uses _beginthreadex()
// otherwise, CreateThread() will be used for a Windows compilation
// #define HAVE_BEGINTHREADEX 1

// (configure)
// Uncomment to select a pthreads based implementation
// #define ZT_POSIX 1

// (configure)
// Uncomment to select a Windows based implementation that uses features not
// supported by windows 98 and 95
// #define ZT_WIN32 1

// (configure)
// Uncomment to select a Windows based implementation that does not use features not
// supported by windows 98 and 95, but may not be compatible with 64 bit or alpha systems
// #define ZT_WIN9X 1

// (configure)
// Uncomment to select a MacOS based implementation
// #define ZT_MACOS 1

// (configure)
// Uncomment to prefer vanilla implementations of primatives when possible
// #define ZT_VANILLA 1

// =====================================================================================
// The following section can be customized to select the implementation that is compiled
// Eventually, the configure program will be updated to define these symbols as well.
// =====================================================================================

// Uncomment to select very simple spinlock based implementations
// #define ZTHREAD_USE_SPIN_LOCKS 1

// Uncomment to select the vannila dual mutex implementation of FastRecursiveLock
// #define ZTHREAD_DUAL_LOCKS 1

// Uncomment to select a POSIX implementation of FastRecursiveLock that does not 
// spin, but instead sleeps on a condition variable.
// #define ZTHREAD_CONDITION_LOCKS 1

// Uncomment if you want to eliminate inlined code used as a part of some template classes
// #define ZTHREAD_NOINLINE

// Uncomment if you want to compile a DLL version of the library. (Win32)
// #define ZTHREAD_EXPORTS 1

// Uncomment if you want to compile a client using the DLL version of the library. (Win32)
// #define ZTHREAD_IMPORTS 1

// ===================================================================================
// The following section will attempt to guess the best configuration for your system
// ===================================================================================

// Select an implementation by checking out the environment, first looking for 
// compilers, then by looking for other definitions that could be present

#if !defined(ZT_POSIX) && !defined(ZT_WIN9X) && !defined(ZT_WIN32) && !defined(ZT_MACOS)

// Check for well known compilers
#if defined(_MSC_VER) || defined(__BORLANDC__) || defined(__BCPLUSPLUS__) || defined(__MINGW32__)

#  define ZT_WIN32

#elif defined(__CYGWIN__)

#  define ZT_POSIX

// Check for well known platforms
#elif defined(__linux__) || \
      defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || \
      defined(__hpux) || \
      defined(__sgi) || \
      defined(__sun)

#  define ZT_POSIX

// Check for definitions from well known headers
#elif defined(_POSIX_SOURCE) || defined(_XOPEN_SOURCE) 

#  define ZT_POSIX

#elif defined(WIN32_LEAN_AND_MEAN)

#  define ZT_WIN32

#elif defined(macintosh) || defined(__APPLE__) || defined(__APPLE_CC__)

#  define ZT_MACOS

#else
#  error "Could not select implementation, define ZT_WIN9X, ZT_WIN32, ZT_POSIX or ZT_MACOS"
#endif

#endif

// Once an implementation has been selected, configure the API decorator
// for shared libraries if its needed.

#if defined(ZTHREAD_SHARED)  // Compatibility w/ past releases

#  define ZTHREAD_IMPORTS

#elif defined(ZTHREAD_STATIC)

#  undef ZTHREAD_EXPORTS
#  undef ZTHREAD_IMPORTS

#endif

// Windows users will get a static build by default, unless they 
// define either ZTHREAD_IMPORTS or ZTHREAD_EXPORTS. Client code 
// of a dll version of this library should define the first flag;
// To build the dll version of this library, define the second.

#if defined(ZTHREAD_IMPORTS) && defined(ZTHREAD_EXPORTS)
#  error "Import and export declarations are not valid"
#else

#  if defined(ZTHREAD_IMPORTS) 
#    define ZTHREAD_API __declspec(dllimport)
#  elif defined(ZTHREAD_EXPORTS) 
#    define ZTHREAD_API __declspec(dllexport)
#  else
#    define ZTHREAD_API 
#  endif

#endif

// Once the API decorator is configured, create a macro for 
// explicit template instantiation (whose need can hopefully 
// be removed from the library)

#if defined(ZTHREAD_EXPORTS)
#  define EXPLICIT_TEMPLATE(X) template class __declspec( dllexport ) X; 
#elif defined(ZTHREAD_IMPORTS)
#  define EXPLICIT_TEMPLATE(X) template class __declspec( dllimport ) X; 
#else
#  define EXPLICIT_TEMPLATE(X)
#endif

// Give libc a hint, should be defined by the user - but people tend 
// to forget.

#if !defined(REENTRANT)
#  define REENTRANT
#endif

#if !defined(_REENTRANT)
#  define _REENTRANT
#endif

#if defined(_MSC_VER)
#  pragma warning(disable:4275)
#  pragma warning(disable:4290) 
#  pragma warning(disable:4786)
#  pragma warning(disable:4251)
#  pragma warning(disable:4355)
#endif

// Ensure that only one implementation is selected
#if \
(defined(ZT_POSIX) && defined(ZT_WIN32)) \
 || (defined(ZT_POSIX) && defined(ZT_WIN9X)) \
    || (defined(ZT_WIN32) && defined(ZT_WIN9X)) 

#  error "Only one implementation should be selected!"

#endif

#if defined(ZTHREAD_NOINLINE)
#  define ZTHREAD_INLINE 
#else
#  define ZTHREAD_INLINE inline 
#endif

#endif // __ZTCONFIG_H__

