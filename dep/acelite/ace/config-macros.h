// -*- C++ -*-

//==========================================================================
/**
 *  @file   config-macros.h
 *
 *  $Id: config-macros.h 94386 2011-08-10 12:42:53Z johnnyw $
 *
 *  @author (Originally in OS.h)Doug Schmidt <schmidt@cs.wustl.edu>
 *  @author Jesper S. M|ller<stophph@diku.dk>
 *  @author and a cast of thousands...
 *
 *  This file contains the contents of the old config-lite.h header
 *  without C++ code (except for C++ code in macros).  Specifically,
 *  only macros or C language constructs are found in this header.
 *  Allows configuration values and macros to be used by some C
 *  language sources.
 */
//==========================================================================

#ifndef ACE_CONFIG_MACROS_H
#define ACE_CONFIG_MACROS_H

#ifdef _WIN32
  #include "ace/config-win32.h"
#else
  #include "ace/config.h"
#endif

#include "ace/Version.h"
#include "ace/Versioned_Namespace.h"

#if !defined (ACE_HAS_EXCEPTIONS)
#define ACE_HAS_EXCEPTIONS
#endif /* !ACE_HAS_EXCEPTIONS */

// ACE_HAS_TLI is used to decide whether to try any XTI/TLI functionality
// so if it isn't set, set it. Capabilities and differences between
// XTI and TLI favor XTI, but when deciding to do anything, as opposed to
// ACE_NOTSUP_RETURN for example, ACE_HAS_TLI is the deciding factor.
#if !defined (ACE_HAS_TLI)
#  if defined (ACE_HAS_XTI)
#    define ACE_HAS_TLI
#  endif /* ACE_HAS_XTI */
#endif /* ACE_HAS_TLI */

#define ACE_BITS_PER_ULONG (8 * sizeof (u_long))

#if !defined (ACE_OSTREAM_TYPE)
# if defined (ACE_LACKS_IOSTREAM_TOTALLY)
#   define ACE_OSTREAM_TYPE FILE
# else  /* ! ACE_LACKS_IOSTREAM_TOTALLY */
#   define ACE_OSTREAM_TYPE ostream
# endif /* ! ACE_LACKS_IOSTREAM_TOTALLY */
#endif /* ! ACE_OSTREAM_TYPE */

#if !defined (ACE_DEFAULT_LOG_STREAM)
# if defined (ACE_LACKS_IOSTREAM_TOTALLY)
#   define ACE_DEFAULT_LOG_STREAM 0
# else  /* ! ACE_LACKS_IOSTREAM_TOTALLY */
#   define ACE_DEFAULT_LOG_STREAM (&cerr)
# endif /* ! ACE_LACKS_IOSTREAM_TOTALLY */
#endif /* ! ACE_DEFAULT_LOG_STREAM */

// For Win32 compatibility...
# if !defined (ACE_WSOCK_VERSION)
#   define ACE_WSOCK_VERSION 0, 0
# endif /* ACE_WSOCK_VERSION */

# if defined (ACE_MT_SAFE) && (ACE_MT_SAFE != 0)
#   define ACE_MT(X) X
# else
#   define ACE_MT(X)
# endif /* ACE_MT_SAFE */

# if defined (ACE_HAS_PURIFY)
#   define ACE_INITIALIZE_MEMORY_BEFORE_USE
# endif /* ACE_HAS_PURIFY */

# if defined (ACE_HAS_VALGRIND)
#   define ACE_INITIALIZE_MEMORY_BEFORE_USE
#   define ACE_LACKS_DLCLOSE
# endif /* ACE_HAS_VALGRIND */

// =========================================================================
// Perfect Multicast filting refers to RFC 3376, where a socket is only
// delivered dgrams for groups joined even if it didn't bind the group
// address.  We turn this option off by default, although most OS's
// except for Windows and Solaris probably lack perfect filtering.
// =========================================================================

# if !defined (ACE_LACKS_PERFECT_MULTICAST_FILTERING)
#   define ACE_LACKS_PERFECT_MULTICAST_FILTERING 0
# endif /* ACE_LACKS_PERFECT_MULTICAST_FILTERING */

// =========================================================================
// Enable/Disable Features By Default
// =========================================================================

# if !defined (ACE_HAS_POSITION_INDEPENDENT_POINTERS)
#   define ACE_HAS_POSITION_INDEPENDENT_POINTERS 1
# endif /* ACE_HAS_POSITION_INDEPENDENT_POINTERS */

# if !defined (ACE_HAS_PROCESS_SPAWN)
#   if !defined (ACE_LACKS_FORK) || \
       (defined (ACE_WIN32) && !defined (ACE_HAS_PHARLAP)) || \
       defined (ACE_WINCE) || defined (ACE_OPENVMS)
#     define ACE_HAS_PROCESS_SPAWN 1
#   endif
# endif /* ACE_HAS_PROCESS_SPAWN */

# if !defined (ACE_HAS_DYNAMIC_LINKING)
#   if defined (ACE_HAS_SVR4_DYNAMIC_LINKING) || defined (ACE_WIN32) || defined (ACE_VXWORKS) || defined (__hpux)
#     define ACE_HAS_DYNAMIC_LINKING 1
#   endif
# endif /* ACE_HAS_DYNAMIC_LINKING */

# if defined (ACE_USES_FIFO_SEM)
#   if defined (ACE_HAS_POSIX_SEM) || defined (ACE_LACKS_MKFIFO) || defined (ACE_LACKS_FCNTL)
#     undef ACE_USES_FIFO_SEM
#   endif
# endif /* ACE_USES_FIFO_SEM */

// =========================================================================
// INLINE macros
//
// These macros handle all the inlining of code via the .i or .inl files
// =========================================================================

#if defined (ACE_LACKS_INLINE_FUNCTIONS) && !defined (ACE_NO_INLINE)
#  define ACE_NO_INLINE
#endif /* defined (ACE_LACKS_INLINE_FUNCTIONS) && !defined (ACE_NO_INLINE) */

// ACE inlining has been explicitly disabled.  Implement
// internally within ACE by undefining __ACE_INLINE__.
#if defined (ACE_NO_INLINE)
#  undef __ACE_INLINE__
#endif /* ! ACE_NO_INLINE */

#if defined (__ACE_INLINE__)
#  define ACE_INLINE inline
#  if !defined (ACE_HAS_INLINED_OSCALLS)
#    define ACE_HAS_INLINED_OSCALLS
#  endif /* !ACE_HAS_INLINED_OSCALLS */
#else
#  define ACE_INLINE
#endif /* __ACE_INLINE__ */

// ============================================================================
// EXPORT macros
//
// Since Win32 DLL's do not export all symbols by default, they must be
// explicitly exported (which is done by *_Export macros).
// ============================================================================

// Win32 should have already defined the macros in config-win32-common.h
#if !defined (ACE_HAS_CUSTOM_EXPORT_MACROS)
#  define ACE_Proper_Export_Flag
#  define ACE_Proper_Import_Flag
#  define ACE_EXPORT_SINGLETON_DECLARATION(T)
#  define ACE_IMPORT_SINGLETON_DECLARATION(T)
#  define ACE_EXPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  define ACE_IMPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#else
// An export macro should at the very least have been defined.

#  ifndef ACE_Proper_Import_Flag
#    define ACE_Proper_Import_Flag
#  endif  /* !ACE_Proper_Import_Flag */

#  ifndef ACE_EXPORT_SINGLETON_DECLARATION
#    define ACE_EXPORT_SINGLETON_DECLARATION(T)
#  endif  /* !ACE_EXPORT_SINGLETON_DECLARATION */

#  ifndef ACE_IMPORT_SINGLETON_DECLARATION
#    define ACE_IMPORT_SINGLETON_DECLARATION(T)
#  endif  /* !ACE_IMPORT_SINGLETON_DECLARATION */

#  ifndef ACE_EXPORT_SINGLETON_DECLARE
#    define ACE_EXPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  endif  /* !ACE_EXPORT_SINGLETON_DECLARE */

#  ifndef ACE_IMPORT_SINGLETON_DECLARE
#    define ACE_IMPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  endif  /* !ACE_IMPORT_SINGLETON_DECLARE */

#endif /* !ACE_HAS_CUSTOM_EXPORT_MACROS */

// This is a whim of mine -- that instead of annotating a class with
// ACE_Export in its declaration, we make the declaration near the TOP
// of the file with ACE_DECLARE_EXPORT.
// TS = type specifier (e.g., class, struct, int, etc.)
// ID = identifier
// So, how do you use it?  Most of the time, just use ...
// ACE_DECLARE_EXPORT(class, someobject);
// If there are global functions to be exported, then use ...
// ACE_DECLARE_EXPORT(void, globalfunction) (int, ...);
// Someday, when template libraries are supported, we made need ...
// ACE_DECLARE_EXPORT(template class, sometemplate) <class TYPE, class LOCK>;
# define ACE_DECLARE_EXPORT(TS,ID) TS ACE_Export ID

// ============================================================================
// Cast macros
//
// These macros are used to choose between the old cast style and the new
// *_cast<> operators
// ============================================================================

#   define ACE_sap_any_cast(TYPE)                                      reinterpret_cast<TYPE> (const_cast<ACE_Addr &> (ACE_Addr::sap_any))

# if !defined (ACE_CAST_CONST)
    // Sun CC 4.2, for example, requires const in reinterpret casts of
    // data members in const member functions.  But, other compilers
    // complain about the useless const.  This keeps everyone happy.
#   if defined (__SUNPRO_CC)
#     define ACE_CAST_CONST const
#   else  /* ! __SUNPRO_CC */
#     define ACE_CAST_CONST
#   endif /* ! __SUNPRO_CC */
# endif /* ! ACE_CAST_CONST */

// ============================================================================
// Compiler Silencing macros
//
// Some compilers complain about parameters that are not used.  This macro
// should keep them quiet.
// ============================================================================

#if !defined (ACE_UNUSED_ARG)
# if defined (__GNUC__) && ((__GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 2)))
#   define ACE_UNUSED_ARG(a) (void) (a)
# elif defined (__GNUC__) || defined (ghs) || defined (__hpux) || defined (__DECCXX) || defined (__rational__) || defined (__USLC__) || defined (ACE_RM544) || defined (__DCC__) || defined (__PGI) || defined (__TANDEM)
// Some compilers complain about "statement with no effect" with (a).
// This eliminates the warnings, and no code is generated for the null
// conditional statement.  @note that may only be true if -O is enabled,
// such as with GreenHills (ghs) 1.8.8.
#  define ACE_UNUSED_ARG(a) do {/* null */} while (&a == 0)
# elif defined (__DMC__)
   #define ACE_UNUSED_ID(identifier)
   template <class T>
   inline void ACE_UNUSED_ARG(const T& ACE_UNUSED_ID(t)) { }
# else /* ghs || __GNUC__ || ..... */
#  define ACE_UNUSED_ARG(a) (a)
# endif /* ghs || __GNUC__ || ..... */
#endif /* !ACE_UNUSED_ARG */

#if defined (_MSC_VER) || defined (ghs) || defined (__DECCXX) || defined(__BORLANDC__) || defined (ACE_RM544) || defined (__USLC__) || defined (__DCC__) || defined (__PGI) || defined (__TANDEM) || (defined (__HP_aCC) && (__HP_aCC < 40000 || __HP_aCC >= 60500))
# define ACE_NOTREACHED(a)
#else  /* ghs || ..... */
# define ACE_NOTREACHED(a) a
#endif /* ghs || ..... */

// ============================================================================
// ACE_ALLOC_HOOK* macros
//
// Macros to declare and define class-specific allocation operators.
// ============================================================================

# if defined (ACE_HAS_ALLOC_HOOKS)
#   define ACE_ALLOC_HOOK_DECLARE \
  void *operator new (size_t bytes); \
  void operator delete (void *ptr);

  // Note that these are just place holders for now.  Some day they
  // may be be replaced by <ACE_Malloc>.
#   define ACE_ALLOC_HOOK_DEFINE(CLASS) \
  void *CLASS::operator new (size_t bytes) { return ::new char[bytes]; } \
  void CLASS::operator delete (void *ptr) { delete [] ((char *) ptr); }
# else
#   define ACE_ALLOC_HOOK_DECLARE struct __Ace {} /* Just need a dummy... */
#   define ACE_ALLOC_HOOK_DEFINE(CLASS)
# endif /* ACE_HAS_ALLOC_HOOKS */

// ============================================================================
/**
 * ACE_OSCALL* macros
 *
 * @deprecated ACE_OSCALL_RETURN and ACE_OSCALL should not be used.
 *             Please restart system calls in your application code.
 *             See the @c sigaction(2) man page for documentation
 *             regarding enabling restartable system calls across
 *             signals via the @c SA_RESTART flag.
 *
 * The following two macros used ensure that system calls are properly
 * restarted (if necessary) when interrupts occur.  However, that
 * capability was never enabled by any of our supported platforms.
 * In fact, some parts of ACE would not function properly when that
 * ability was enabled.  Furthermore, they assumed that ability to
 * restart system calls was determined statically.  That assumption
 * does not hold for modern platforms, where that ability is
 * determined dynamically at run-time.
 */
// ============================================================================

#define ACE_OSCALL_RETURN(X,TYPE,FAILVALUE) \
  do \
    return (TYPE) (X); \
  while (0)
#define ACE_OSCALL(X,TYPE,FAILVALUE,RESULT) \
  do \
    RESULT = (TYPE) (X); \
  while (0)

#if defined (ACE_WIN32)
# define ACE_WIN32CALL_RETURN(X,TYPE,FAILVALUE) \
  do { \
    TYPE ace_result_; \
    ace_result_ = (TYPE) X; \
    if (ace_result_ == FAILVALUE) \
      ACE_OS::set_errno_to_last_error (); \
    return ace_result_; \
  } while (0)
# define ACE_WIN32CALL(X,TYPE,FAILVALUE,RESULT) \
  do { \
    RESULT = (TYPE) X; \
    if (RESULT == FAILVALUE) \
      ACE_OS::set_errno_to_last_error (); \
  } while (0)
#endif  /* ACE_WIN32 */

// The C99 security-improved run-time returns an error value on failure;
// 0 on success.
#if defined (ACE_HAS_TR24731_2005_CRT)
#  define ACE_SECURECRTCALL(X,TYPE,FAILVALUE,RESULT) \
  do { \
    errno_t ___ = X; \
    if (___ != 0) { errno = ___; RESULT = FAILVALUE; } \
  } while (0)
#endif /* ACE_HAS_TR24731_2005_CRT */

// ============================================================================
// Fundamental types
// ============================================================================

#if defined (ACE_WIN32)

typedef HANDLE ACE_HANDLE;
typedef SOCKET ACE_SOCKET;
# define ACE_INVALID_HANDLE INVALID_HANDLE_VALUE

#else /* ! ACE_WIN32 */

typedef int ACE_HANDLE;
typedef ACE_HANDLE ACE_SOCKET;
# define ACE_INVALID_HANDLE -1

#endif /* ACE_WIN32 */

// Define the type that's returned from the platform's native thread
// functions. ACE_THR_FUNC_RETURN is the type defined as the thread
// function's return type, except when the thread function doesn't return
// anything (pSoS). The ACE_THR_FUNC_NO_RETURN_VAL macro is used to
// indicate that the actual thread function doesn't return anything. The
// rest of ACE uses a real type so there's no a ton of conditional code
// everywhere to deal with the possibility of no return type.
# if defined (ACE_VXWORKS) && !defined (ACE_HAS_PTHREADS)
# include /**/ <taskLib.h>
typedef int ACE_THR_FUNC_RETURN;
#define ACE_HAS_INTEGRAL_TYPE_THR_FUNC_RETURN
# elif defined (ACE_WIN32)
typedef DWORD ACE_THR_FUNC_RETURN;
#define ACE_HAS_INTEGRAL_TYPE_THR_FUNC_RETURN
# else
typedef void* ACE_THR_FUNC_RETURN;
# endif /* ACE_VXWORKS */
typedef ACE_THR_FUNC_RETURN (*ACE_THR_FUNC)(void *);

#ifdef __cplusplus
extern "C" {
#endif  /* __cplusplus */
typedef void (*ACE_THR_C_DEST)(void *);
#ifdef __cplusplus
}
#endif  /* __cplusplus */
typedef void (*ACE_THR_DEST)(void *);

// Now some platforms have special requirements...
# if defined (ACE_VXWORKS) && !defined (ACE_HAS_PTHREADS)
typedef FUNCPTR ACE_THR_FUNC_INTERNAL;  // where typedef int (*FUNCPTR) (...)
# else
typedef ACE_THR_FUNC ACE_THR_FUNC_INTERNAL;
# endif /* ACE_VXWORKS */

# ifdef __cplusplus
extern "C"
{
# endif  /* __cplusplus */
# if defined (ACE_VXWORKS) && !defined (ACE_HAS_PTHREADS)
typedef FUNCPTR ACE_THR_C_FUNC;  // where typedef int (*FUNCPTR) (...)
# else
typedef ACE_THR_FUNC_RETURN (*ACE_THR_C_FUNC)(void *);
# endif /* ACE_VXWORKS */
# ifdef __cplusplus
}
# endif  /* __cplusplus */

// ============================================================================
// Macros for controlling the lifetimes of dlls loaded by ACE_DLL--including
// all dlls loaded via the ACE Service Config framework.
//
// Please don't change these values or add new ones wantonly, since we use
// the ACE_BIT_ENABLED, etc..., macros to test them.
// ============================================================================

// Per-process policy that unloads dlls eagerly.
#define ACE_DLL_UNLOAD_POLICY_PER_PROCESS 0
// Apply policy on a per-dll basis.  If the dll doesn't use one of the macros
// below, the current per-process policy will be used.
#define ACE_DLL_UNLOAD_POLICY_PER_DLL 1
// Don't unload dll when refcount reaches zero, i.e., wait for either an
// explicit unload request or program exit.
#define ACE_DLL_UNLOAD_POLICY_LAZY 2
// Default policy allows dlls to control their own destinies, but will
// unload those that don't make a choice eagerly.
#define ACE_DLL_UNLOAD_POLICY_DEFAULT ACE_DLL_UNLOAD_POLICY_PER_DLL

// Add this macro you one of your cpp file in your dll.  X should
// be either ACE_DLL_UNLOAD_POLICY_DEFAULT or ACE_DLL_UNLOAD_POLICY_LAZY.
#define ACE_DLL_UNLOAD_POLICY(CLS,X) \
extern "C" u_long CLS##_Export _get_dll_unload_policy (void) \
  { return X;}

// ============================================================================
// ACE_USES_CLASSIC_SVC_CONF macro
// ============================================================================

// For now, default is to use the classic svc.conf format.
#if !defined (ACE_USES_CLASSIC_SVC_CONF)
# if defined (ACE_HAS_CLASSIC_SVC_CONF) && defined (ACE_HAS_XML_SVC_CONF)
#   error You can only use either CLASSIC or XML svc.conf, not both.
# endif
// Change the ACE_HAS_XML_SVC_CONF to ACE_HAS_CLASSIC_SVC_CONF when
// we switch ACE to use XML svc.conf as default format.
# if defined (ACE_HAS_XML_SVC_CONF)
#   define ACE_USES_CLASSIC_SVC_CONF 0
# else
#   define ACE_USES_CLASSIC_SVC_CONF 1
# endif /* ACE_HAS_XML_SVC_CONF */
#endif /* ACE_USES_CLASSIC_SVC_CONF */

// ============================================================================
// Default svc.conf file extension.
// ============================================================================
#if defined (ACE_USES_CLASSIC_SVC_CONF) && (ACE_USES_CLASSIC_SVC_CONF == 1)
# define ACE_DEFAULT_SVC_CONF_EXT   ".conf"
#else
# define ACE_DEFAULT_SVC_CONF_EXT   ".conf.xml"
#endif /* ACE_USES_CLASSIC_SVC_CONF && ACE_USES_CLASSIC_SVC_CONF == 1 */

// ============================================================================
// Miscellaneous macros
// ============================================================================

#if defined (ACE_USES_EXPLICIT_STD_NAMESPACE)
#  define ACE_STD_NAMESPACE std
#else
#  define ACE_STD_NAMESPACE
#endif

#if !defined (ACE_OS_String)
#  define ACE_OS_String ACE_OS
#endif /* ACE_OS_String */
#if !defined (ACE_OS_Memory)
#  define ACE_OS_Memory ACE_OS
#endif /* ACE_OS_Memory */
#if !defined (ACE_OS_Dirent)
#  define ACE_OS_Dirent ACE_OS
#endif /* ACE_OS_Dirent */
#if !defined (ACE_OS_TLI)
#  define ACE_OS_TLI ACE_OS
#endif /* ACE_OS_TLI */

// -------------------------------------------------------------------
// Preprocessor symbols will not be expanded if they are
// concatenated.  Force the preprocessor to expand them during the
// argument prescan by calling a macro that itself calls another that
// performs the actual concatenation.
#define ACE_PREPROC_CONCATENATE_IMPL(A,B) A ## B
#define ACE_PREPROC_CONCATENATE(A,B) ACE_PREPROC_CONCATENATE_IMPL(A,B)
// -------------------------------------------------------------------

/// If MPC is using a lib modifier this define will be set and this then
/// is used by the service configurator framework
#if defined MPC_LIB_MODIFIER && !defined (ACE_LD_DECORATOR_STR)
#define ACE_LD_DECORATOR_STR ACE_TEXT( MPC_LIB_MODIFIER )
#endif /* MPC_LIB_MODIFIER */

#ifndef ACE_GCC_CONSTRUCTOR_ATTRIBUTE
# define ACE_GCC_CONSTRUCTOR_ATTRIBUTE
#endif

#ifndef ACE_GCC_DESTRUCTOR_ATTRIBUTE
# define ACE_GCC_DESTRUCTOR_ATTRIBUTE
#endif

#ifndef ACE_HAS_TEMPLATE_TYPEDEFS
#define ACE_HAS_TEMPLATE_TYPEDEFS
#endif

#ifndef ACE_GCC_FORMAT_ATTRIBUTE
# define ACE_GCC_FORMAT_ATTRIBUTE(TYPE, STR_INDEX, FIRST_INDEX)
#endif

#ifndef ACE_DEPRECATED
# define ACE_DEPRECATED
#endif

#ifndef ACE_HAS_REACTOR_NOTIFICATION_QUEUE
# define ACE_HAS_REACTOR_NOTIFICATION_QUEUE
#endif

#endif /* ACE_CONFIG_MACROS_H */
