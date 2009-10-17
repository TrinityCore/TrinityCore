// -*- C++ -*-
//=============================================================================
/**
 *  @file   OS_Memory.h
 *
 *  $Id: OS_Memory.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Doug Schmidt <schmidt@cs.wustl.edu>
 *  @author Jesper S. M|ller<stophph@diku.dk>
 *  @author and a cast of thousands...
 */
//=============================================================================
#ifndef ACE_OS_MEMORY_H
#define ACE_OS_MEMORY_H
#include /**/ "ace/pre.h"
#include /**/ "ace/ACE_export.h"
#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */
#include "ace/OS_Errno.h"
#include "ace/Basic_Types.h"
#include "ace/os_include/os_stddef.h"
// Allow an installation to replace the lowest-level allocation
// functions without changing the source of ACE.
//
// To do this, simple #define ACE_*_FUNC macros in config.h to
// the names of the site-specific functions, e.g.,
//
//   #define ACE_MALLOC_FUNC  dlmalloc
//   #define ACE_CALLOC_FUNC  dlcalloc
//   #define ACE_FREE_FUNC    dlfree
//   #define ACE_REALLOC_FUNC dlrealloc
//
// For completeness' sake, you should probably put
//   #define ACE_HAS_STRDUP_EMULATION
//   #define ACE_HAS_WCSDUP_EMULATION
// too, so that you guarantee that strdup() and wcsdup() call your
// desired mallocator and not the system mallocator.
//
#if !defined (ACE_MALLOC_FUNC)
#  define ACE_MALLOC_FUNC ::malloc
#endif
#if !defined (ACE_CALLOC_FUNC)
#  define ACE_CALLOC_FUNC ::calloc
#endif
#if !defined (ACE_FREE_FUNC)
#  define ACE_FREE_FUNC ::free
#endif
#if !defined (ACE_REALLOC_FUNC)
#  define ACE_REALLOC_FUNC ::realloc
#endif
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
#if defined (ACE_HAS_OLD_MALLOC)
typedef char * ACE_MALLOC_T;
#else
typedef void * ACE_MALLOC_T;
#endif /* ACE_HAS_OLD_MALLOC */
ACE_END_VERSIONED_NAMESPACE_DECL
// ============================================================================
// ACE_NEW macros
//
// A useful abstraction for expressions involving operator new since
// we can change memory allocation error handling policies (e.g.,
// depending on whether ANSI/ISO exception handling semantics are
// being used).
// ============================================================================
// If new(std::nothrow) is defined then, by definition, new throws exceptions.
#if defined (ACE_HAS_NEW_NOTHROW)
#  if !defined (ACE_NEW_THROWS_EXCEPTIONS)
#    define ACE_NEW_THROWS_EXCEPTIONS
#  endif
#endif
// The Windows MFC exception mechanism requires that a caught CException
// (including the CMemoryException in use here) be freed using its Delete()
// method. Thus, when MFC is in use and we're catching exceptions as a result
// of new(), the exception's Delete() method has to be called. No other
// platform imposes this sort of restriction/requirement. The Windows
// config stuff (at least for MSVC/MFC) defines a ACE_del_bad_alloc macro
// that works with its ACE_bad_alloc macro to implement this cleanup
// requirement. Since no other platform requires this, define it as
// empty here.
#if !defined (ACE_del_bad_alloc)
#  define ACE_del_bad_alloc
#endif
#if defined (ACE_NEW_THROWS_EXCEPTIONS)
// Since new() throws exceptions, we need a way to avoid passing
// exceptions past the call to new because ACE counts on having a 0
// return value for a failed allocation. Some compilers offer the
// new (nothrow) version, which does exactly what we want. Others
// do not. For those that do not, this sets up what exception is thrown,
// and then below we'll do a try/catch around the new to catch it and
// return a 0 pointer instead.
#  if defined (__HP_aCC)
      // I know this works for HP aC++... if <stdexcept> is used, it
      // introduces other stuff that breaks things, like <memory>, which
      // screws up auto_ptr.
#    include /**/ <new>
    // _HP_aCC was first defined at aC++ 03.13 on HP-UX 11. Prior to that
    // (03.10 and before) a failed new threw bad_alloc. After that (03.13
    // and above) the exception thrown is dependent on the below settings.
#    if (HPUX_VERS >= 1100)
#      if ((__HP_aCC < 32500 && !defined (RWSTD_NO_NAMESPACE)) || \
           defined (ACE_USES_STD_NAMESPACE_FOR_STDCPP_LIB))
#        define ACE_bad_alloc ::std::bad_alloc
#        define ACE_nothrow   ::std::nothrow
#        define ACE_nothrow_t ::std::nothrow_t
#      else
#        define ACE_bad_alloc bad_alloc
#        define ACE_nothrow   nothrow
#        define ACE_nothrow_t nothrow_t
#      endif /* __HP_aCC */
#    elif ((__HP_aCC <  12500 && !defined (RWSTD_NO_NAMESPACE)) || \
           defined (ACE_USES_STD_NAMESPACE_FOR_STDCPP_LIB))
#      define ACE_bad_alloc ::std::bad_alloc
#      define ACE_nothrow   ::std::nothrow
#      define ACE_nothrow_t ::std::nothrow_t
#    else
#      define ACE_bad_alloc bad_alloc
#      define ACE_nothrow   nothrow
#      define ACE_nothrow_t nothrow_t
#    endif /* HPUX_VERS < 1100 */
#    define ACE_throw_bad_alloc throw ACE_bad_alloc ()
#  elif defined (__SUNPRO_CC)
#      if (__SUNPRO_CC < 0x500) || (__SUNPRO_CC_COMPAT == 4)
#        include /**/ <exception.h>
         // Note: we catch ::xalloc rather than just xalloc because of
         // a name clash with unsafe_ios::xalloc()
#        define ACE_bad_alloc ::xalloc
#        define ACE_throw_bad_alloc throw ACE_bad_alloc ("no more memory")
#      else
#        include /**/ <new>
#        define ACE_bad_alloc ::std::bad_alloc
#        if defined (ACE_HAS_NEW_NOTHROW)
#          if defined (ACE_USES_STD_NAMESPACE_FOR_STDCPP_LIB)
#            define ACE_nothrow   ::std::nothrow
#            define ACE_nothrow_t ::std::nothrow_t
#          else
#            define ACE_nothrow   nothrow
#            define ACE_nothrow_t nothrow_t
#          endif /* ACE_USES_STD_NAMESPACE_FOR_STDCPP_LIB */
#        endif /* ACE_HAS_NEW_NOTHROW */
#        define ACE_throw_bad_alloc throw ACE_bad_alloc ()
#      endif /* __SUNPRO_CC < 0x500 */
#  elif defined (ACE_USES_STD_NAMESPACE_FOR_STDCPP_LIB)
#    include /**/ <new>
#    if !defined (ACE_bad_alloc)
#      define ACE_bad_alloc ::std::bad_alloc
#    endif
#    define ACE_nothrow   ::std::nothrow
#    define ACE_nothrow_t ::std::nothrow_t
     // MFC changes the behavior of operator new at all MSVC versions from 6 up.
#    if defined (ACE_HAS_MFC) && (ACE_HAS_MFC == 1)
#      define ACE_throw_bad_alloc AfxThrowMemoryException ()
#    else
#      define ACE_throw_bad_alloc throw ACE_bad_alloc ()
#    endif
#  else
#    include /**/ <new>
#    if !defined (ACE_bad_alloc)
#      define ACE_bad_alloc bad_alloc
#    endif
#    define ACE_nothrow   nothrow
#    define ACE_nothrow_t nothrow_t
     // MFC changes the behavior of operator new at all MSVC versions from 6 up.
#    if defined (ACE_HAS_MFC) && (ACE_HAS_MFC == 1)
#      define ACE_throw_bad_alloc AfxThrowMemoryException ()
#    else
#      define ACE_throw_bad_alloc throw ACE_bad_alloc ()
#    endif
#  endif /* __HP_aCC */
#  if defined (ACE_HAS_NEW_NOTHROW)
#    define ACE_NEW_RETURN(POINTER,CONSTRUCTOR,RET_VAL) \
   do { POINTER = new (ACE_nothrow) CONSTRUCTOR; \
     if (POINTER == 0) { errno = ENOMEM; return RET_VAL; } \
   } while (0)
#    define ACE_NEW(POINTER,CONSTRUCTOR) \
   do { POINTER = new(ACE_nothrow) CONSTRUCTOR; \
     if (POINTER == 0) { errno = ENOMEM; return; } \
   } while (0)
#    define ACE_NEW_NORETURN(POINTER,CONSTRUCTOR) \
   do { POINTER = new(ACE_nothrow) CONSTRUCTOR; \
     if (POINTER == 0) { errno = ENOMEM; } \
   } while (0)
#  else
#    define ACE_NEW_RETURN(POINTER,CONSTRUCTOR,RET_VAL) \
   do { try { POINTER = new CONSTRUCTOR; } \
     catch (ACE_bad_alloc) { ACE_del_bad_alloc errno = ENOMEM; POINTER = 0; return RET_VAL; } \
   } while (0)
#    define ACE_NEW(POINTER,CONSTRUCTOR) \
   do { try { POINTER = new CONSTRUCTOR; } \
     catch (ACE_bad_alloc) { ACE_del_bad_alloc errno = ENOMEM; POINTER = 0; return; } \
   } while (0)
#    define ACE_NEW_NORETURN(POINTER,CONSTRUCTOR) \
   do { try { POINTER = new CONSTRUCTOR; } \
     catch (ACE_bad_alloc) { ACE_del_bad_alloc errno = ENOMEM; POINTER = 0; } \
   } while (0)
#  endif /* ACE_HAS_NEW_NOTHROW */
#else /* ACE_NEW_THROWS_EXCEPTIONS */
# define ACE_NEW_RETURN(POINTER,CONSTRUCTOR,RET_VAL) \
   do { POINTER = new CONSTRUCTOR; \
     if (POINTER == 0) { errno = ENOMEM; return RET_VAL; } \
   } while (0)
# define ACE_NEW(POINTER,CONSTRUCTOR) \
   do { POINTER = new CONSTRUCTOR; \
     if (POINTER == 0) { errno = ENOMEM; return; } \
   } while (0)
# define ACE_NEW_NORETURN(POINTER,CONSTRUCTOR) \
   do { POINTER = new CONSTRUCTOR; \
     if (POINTER == 0) { errno = ENOMEM; } \
   } while (0)
# define ACE_throw_bad_alloc \
  void* gcc_will_complain_if_literal_0_is_returned = 0; \
  return gcc_will_complain_if_literal_0_is_returned
#endif /* ACE_NEW_THROWS_EXCEPTIONS */
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
//@{
/**
 * @name Efficiently compute aligned pointers to powers of 2 boundaries.
 */
/**
 * Efficiently align "value" up to "alignment", knowing that all such
 * boundaries are binary powers and that we're using two's complement
 * arithmetic.
 *
 * Since the alignment is a power of two its binary representation is:
 *
 * alignment      = 0...010...0
 *
 * hence
 *
 * alignment - 1  = 0...001...1 = T1
 *
 * so the complement is:
 *
 * ~(alignment - 1) = 1...110...0 = T2
 *
 * Notice that there is a multiple of <alignment> in the range
 * [<value>,<value> + T1], also notice that if
 *
 * X = ( <value> + T1 ) & T2
 *
 * then
 *
 * <value> <= X <= <value> + T1
 *
 * because the & operator only changes the last bits, and since X is a
 * multiple of <alignment> (its last bits are zero) we have found the
 * multiple we wanted.
 */
/// Return the next integer aligned to a required boundary
/**
 * @param ptr the base pointer
 * @param alignment the required alignment
 */
#if defined (ACE_OPENVMS) && (!defined (__INITIAL_POINTER_SIZE) || (__INITIAL_POINTER_SIZE < 64))
inline unsigned int
ACE_align_binary (unsigned int ptr, unsigned int alignment)
{
  unsigned int const tmp = alignment - 1;
  return (ptr + tmp) & (~tmp);
}
#else
inline uintptr_t
ACE_align_binary (uintptr_t ptr, uintptr_t alignment)
{
  uintptr_t const tmp = alignment - 1;
  return (ptr + tmp) & (~tmp);
}
#endif
#if defined (ACE_OPENVMS) && (!defined (__INITIAL_POINTER_SIZE) || (__INITIAL_POINTER_SIZE < 64))
/// Return the next address aligned to a required boundary
inline char *
ACE_ptr_align_binary (char const * ptr, unsigned int alignment)
{
  return
    reinterpret_cast<char *> (
      ACE_align_binary (reinterpret_cast<unsigned int> (ptr), alignment));
}
/// Return the next address aligned to a required boundary
inline char *
ACE_ptr_align_binary (unsigned char const * ptr, unsigned int alignment)
{
  return
    ACE_ptr_align_binary (reinterpret_cast<char const *> (ptr), alignment);
}
#else
/// Return the next address aligned to a required boundary
inline char *
ACE_ptr_align_binary (char const * ptr, uintptr_t alignment)
{
  return
    reinterpret_cast<char *> (
      ACE_align_binary (reinterpret_cast<uintptr_t> (ptr), alignment));
}
/// Return the next address aligned to a required boundary
inline char *
ACE_ptr_align_binary (unsigned char const * ptr, uintptr_t alignment)
{
  return
    ACE_ptr_align_binary (reinterpret_cast<char const *> (ptr), alignment);
}
#endif  /* ACE_OPENVMS && __INITIAL_POINTER_SIZE < 64 */
//@}
ACE_END_VERSIONED_NAMESPACE_DECL
#include "ace/OS_NS_stdlib.h"
#include /**/ "ace/post.h"
#endif /* ACE_OS_MEMORY_H */

