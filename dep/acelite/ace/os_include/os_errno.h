// -*- C++ -*-

//=============================================================================
/**
 *  @file    os_errno.h
 *
 *  system error numbers
 *
 *  $Id: os_errno.h 91076 2010-07-13 14:20:35Z johnnyw $
 *
 *  @author Don Hinton <dhinton@dresystems.com>
 *  @author This code was originally in various places including ace/OS.h.
 */
//=============================================================================

#ifndef ACE_OS_INCLUDE_OS_ERRNO_H
#define ACE_OS_INCLUDE_OS_ERRNO_H

#include /**/ "ace/pre.h"

#include "ace/config-lite.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if !defined (ACE_LACKS_ERRNO_H)
# include /**/ <errno.h>
#endif /* !ACE_LACKS_ERRNO_H */

#if defined (ACE_VXWORKS)
// Needed for VxWorks to pickup errnoSet()
#include /**/ <errnoLib.h>
#endif /* ACE_VXWORKS */

// Place all additions (especially function declarations) within extern "C" {}
#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

#if defined (ACE_WIN32)
   // error code mapping for windows

   // VC++ 10 has these error codes defined in errno.h,
   // this will cause different errors in ACE.
   // So we undef these error codes if they are wrongly defined
#   if defined (EWOULDBLOCK) && (EWOULDBLOCK != WSAEWOULDBLOCK)
#     undef EWOULDBLOCK
#   endif /* EWOULDBLOCK */
#   if defined (EINPROGRESS) && (EINPROGRESS != WSAEINPROGRESS)
#     undef EINPROGRESS
#   endif /* EINPROGRESS */
#   if defined (EALREADY) && (EALREADY != WSAEALREADY)
#     undef EALREADY
#   endif /* EALREADY */
#   if defined (ENOTSOCK) && (ENOTSOCK != WSAENOTSOCK)
#     undef ENOTSOCK
#   endif /* ENOTSOCK */
#   if defined (EDESTADDRREQ) && (EDESTADDRREQ != WSAEDESTADDRREQ)
#     undef EDESTADDRREQ
#   endif /* EDESTADDRREQ */
#   if defined (EMSGSIZE) && (EMSGSIZE != WSAEMSGSIZE)
#     undef EMSGSIZE
#   endif /* EMSGSIZE */
#   if defined (EPROTOTYPE) && (EPROTOTYPE != WSAEPROTOTYPE)
#     undef EPROTOTYPE
#   endif /* EPROTOTYPE */
#   if defined (ENOPROTOOPT) && (ENOPROTOOPT != WSAENOPROTOOPT)
#     undef ENOPROTOOPT
#   endif /* ENOPROTOOPT */
#   if defined (EPROTONOSUPPORT) && (EPROTONOSUPPORT != WSAEPROTONOSUPPORT)
#     undef EPROTONOSUPPORT
#   endif /* EPROTONOSUPPORT */
#   if defined (ESOCKTNOSUPPORT) && (ESOCKTNOSUPPORT != WSAESOCKTNOSUPPORT)
#     undef ESOCKTNOSUPPORT
#   endif /* ESOCKTNOSUPPORT */
#   if defined (EOPNOTSUPP) && (EOPNOTSUPP != WSAEOPNOTSUPP)
#     undef EOPNOTSUPP
#   endif /* EOPNOTSUPP */
#   if defined (EPFNOSUPPORT) && (EPFNOSUPPORT != WSAEPFNOSUPPORT)
#     undef EPFNOSUPPORT
#   endif /* EPFNOSUPPORT */
#   if defined (EAFNOSUPPORT) && (EAFNOSUPPORT != WSAEAFNOSUPPORT)
#     undef EAFNOSUPPORT
#   endif /* EAFNOSUPPORT */
#   if defined (EADDRINUSE) && (EADDRINUSE != WSAEADDRINUSE)
#     undef EADDRINUSE
#   endif /* EADDRINUSE */
#   if defined (EADDRNOTAVAIL) && (EADDRNOTAVAIL != WSAEADDRNOTAVAIL)
#     undef EADDRNOTAVAIL
#   endif /* EADDRNOTAVAIL */
#   if defined (ENETDOWN) && (ENETDOWN != WSAENETDOWN)
#     undef ENETDOWN
#   endif /* ENETDOWN */
#   if defined (ENETUNREACH) && (ENETUNREACH != WSAENETUNREACH)
#     undef ENETUNREACH
#   endif /* ENETUNREACH */
#   if defined (ENETRESET) && (ENETRESET != WSAENETRESET)
#     undef ENETRESET
#   endif /* ENETRESET */
#   if defined (ECONNABORTED) && (ECONNABORTED != WSAECONNABORTED)
#     undef ECONNABORTED
#   endif /* ECONNABORTED */
#   if defined (ECONNRESET) && (ECONNRESET != WSAECONNRESET)
#     undef ECONNRESET
#   endif /* ECONNRESET */
#   if defined (ENOBUFS) && (ENOBUFS != WSAENOBUFS)
#     undef ENOBUFS
#   endif /* ENOBUFS */
#   if defined (EISCONN) && (EISCONN != WSAEISCONN)
#     undef EISCONN
#   endif /* EISCONN */
#   if defined (ENOTCONN) && (ENOTCONN != WSAENOTCONN)
#     undef ENOTCONN
#   endif /* ENOTCONN */
#   if defined (ESHUTDOWN) && (ESHUTDOWN != WSAESHUTDOWN)
#     undef ESHUTDOWN
#   endif /* ESHUTDOWN */
#   if defined (ETOOMANYREFS) && (ETOOMANYREFS != WSAETOOMANYREFS)
#     undef ETOOMANYREFS
#   endif /* ETOOMANYREFS */
#   if defined (ETIMEDOUT) && (ETIMEDOUT != WSAETIMEDOUT)
#     undef ETIMEDOUT
#   endif /* ETIMEDOUT */
#   if defined (ECONNREFUSED) && (ECONNREFUSED != WSAECONNREFUSED)
#     undef ECONNREFUSED
#   endif /* ECONNREFUSED */
#   if defined (ELOOP) && (ELOOP != WSAELOOP)
#     undef ELOOP
#   endif /* ELOOP */
//#   if defined (ENAMETOOLONG) && (ENAMETOOLONG != WSAENAMETOOLONG)
//#      undef ENAMETOOLONG
//#   endif /* ENAMETOOLONG */
#   if defined (EHOSTDOWN) && (EHOSTDOWN != WSAEHOSTDOWN)
#     undef EHOSTDOWN
#   endif /* EHOSTDOWN */
#   if defined (EHOSTUNREACH) && (EHOSTUNREACH != WSAEHOSTUNREACH)
#     undef EHOSTUNREACH
#   endif /* EHOSTUNREACH */
//#   if defined (ENOTEMPTY) && (ENOTEMPTY != WSAENOTEMPTY)
//#      undef ENOTEMPTY
//#   endif /* ENOTEMPTY */
#   if defined (EPROCLIM) && (EPROCLIM != WSAEPROCLIM)
#     undef EPROCLIM
#   endif /* EPROCLIM */
#   if defined (EUSERS) && (EUSERS != WSAEUSERS)
#     undef EUSERS
#   endif /* EUSERS */
#   if defined (EDQUOT) && (EDQUOT != WSAEDQUOT)
#     undef EDQUOT
#   endif /* EDQUOT */
#   if defined (ESTALE) && (ESTALE != WSAESTALE)
#     undef ESTALE
#   endif /* ESTALE */
#   if defined (EREMOTE) && (EREMOTE != WSAEREMOTE)
#     undef EREMOTE
#   endif /* EREMOTE */

#   if !defined (ETIME)
#     define ETIME                  ERROR_SEM_TIMEOUT
#   endif /* !ETIME */
#   if !defined (EWOULDBLOCK)
#     define EWOULDBLOCK             WSAEWOULDBLOCK
#   endif /* !EWOULDBLOCK */
#   if !defined (EINPROGRESS)
#     define EINPROGRESS             WSAEINPROGRESS
#   endif /* !EINPROGRESS */
#   if !defined (EALREADY)
#     define EALREADY                WSAEALREADY
#   endif /* !EALREADY */
#   if !defined (ENOTSOCK)
#     define ENOTSOCK                WSAENOTSOCK
#   endif /* !ENOTSOCK */
#   if !defined (EDESTADDRREQ)
#     define EDESTADDRREQ            WSAEDESTADDRREQ
#   endif /* !EDESTADDRREQ */
#   if !defined (EMSGSIZE)
#     define EMSGSIZE                WSAEMSGSIZE
#   endif /* !EMSGSIZE */
#   if !defined (EPROTOTYPE)
#     define EPROTOTYPE              WSAEPROTOTYPE
#   endif /* !EPROTOTYPE */
#   if !defined (ENOPROTOOPT)
#     define ENOPROTOOPT             WSAENOPROTOOPT
#   endif /* !ENOPROTOOPT */
#   if !defined (EPROTONOSUPPORT)
#     define EPROTONOSUPPORT         WSAEPROTONOSUPPORT
#   endif /* !EPROTONOSUPPORT */
#   if !defined (ESOCKTNOSUPPORT)
#     define ESOCKTNOSUPPORT         WSAESOCKTNOSUPPORT
#   endif /* !ESOCKTNOSUPPORT */
#   if !defined (EOPNOTSUPP)
#     define EOPNOTSUPP              WSAEOPNOTSUPP
#   endif /* !EOPNOTSUPP */
#   if !defined (EPFNOSUPPORT)
#     define EPFNOSUPPORT            WSAEPFNOSUPPORT
#   endif /* !EPFNOSUPPORT */
#   if !defined (EAFNOSUPPORT)
#     define EAFNOSUPPORT            WSAEAFNOSUPPORT
#   endif /* !EAFNOSUPPORT */
#   if !defined (EADDRINUSE)
#     define EADDRINUSE              WSAEADDRINUSE
#   endif /* !EADDRINUSE */
#   if !defined (EADDRNOTAVAIL)
#     define EADDRNOTAVAIL           WSAEADDRNOTAVAIL
#   endif /* !EADDRNOTAVAIL */
#   if !defined (ENETDOWN)
#     define ENETDOWN                WSAENETDOWN
#   endif /* !ENETDOWN */
#   if !defined (ENETUNREACH)
#     define ENETUNREACH             WSAENETUNREACH
#   endif /* !ENETUNREACH */
#   if !defined (ENETRESET)
#     define ENETRESET               WSAENETRESET
#   endif /* !ENETRESET */
#   if !defined (ECONNABORTED)
#     define ECONNABORTED            WSAECONNABORTED
#   endif /* !ECONNABORTED */
#   if !defined (ECONNRESET)
#     define ECONNRESET              WSAECONNRESET
#   endif /* !ECONNRESET */
#   if !defined (ENOBUFS)
#     define ENOBUFS                 WSAENOBUFS
#   endif /* !ENOBUFS */
#   if !defined (EISCONN)
#     define EISCONN                 WSAEISCONN
#   endif /* !EISCONN */
#   if !defined (ENOTCONN)
#     define ENOTCONN                WSAENOTCONN
#   endif /* !ENOTCONN */
#   if !defined (ESHUTDOWN)
#     define ESHUTDOWN               WSAESHUTDOWN
#   endif /* !ESHUTDOWN */
#   if !defined (ETOOMANYREFS)
#     define ETOOMANYREFS            WSAETOOMANYREFS
#   endif /* !ETOOMANYREFS */
#   if !defined (ETIMEDOUT)
#     define ETIMEDOUT               WSAETIMEDOUT
#   endif /* !ETIMEDOUT */
#   if !defined (ECONNREFUSED)
#     define ECONNREFUSED            WSAECONNREFUSED
#   endif /* !ECONNREFUSED */
#   if !defined (ELOOP)
#     define ELOOP                   WSAELOOP
#   endif /* !ELOOP */
#   if !defined (EHOSTDOWN)
#     define EHOSTDOWN               WSAEHOSTDOWN
#   endif /* !EHOSTDOWN */
#   if !defined (EHOSTUNREACH)
#     define EHOSTUNREACH            WSAEHOSTUNREACH
#   endif /* !EHOSTUNREACH */
#   if !defined (EPROCLIM)
#     define EPROCLIM                WSAEPROCLIM
#   endif /* !EPROCLIM */
#   if !defined (EUSERS)
#     define EUSERS                  WSAEUSERS
#   endif /* !EUSERS */
#   if !defined (EDQUOT)
#     define EDQUOT                  WSAEDQUOT
#   endif /* !EDQUOT */
#   if !defined (ESTALE)
#     define ESTALE                  WSAESTALE
#   endif /* !ESTALE */
#   if !defined (EREMOTE)
#     define EREMOTE                 WSAEREMOTE
#   endif /* !EREMOTE */

    // Grrr! ENAMETOOLONG and ENOTEMPTY are already defined by the horrible
    // 'standard' library.
    // #define ENAMETOOLONG            WSAENAMETOOLONG
#   if !defined (EADDRINUSE)
#     define EADDRINUSE              WSAEADDRINUSE
#   endif /* EADDRINUSE*/

  // CE needs this...
#  if !defined (EPERM)
#    define EPERM                 ERROR_ACCESS_DENIED
#  endif
#endif /* ACE_WIN32 */

#if defined (ACE_HAS_H_ERRNO)
void herror (const char *str);
#endif /* ACE_HAS_H_ERRNO */

#if defined (ACE_LACKS_ERRNO_H)
# if !defined (EPERM)
#   define EPERM           1
# endif /* EPERM */
# if !defined (ENOENT)
#   define ENOENT          2
# endif /* ENOENT */
# if !defined (ESRCH)
#   define ESRCH           3
# endif /* ESRCH */
# if !defined (EINTR)
#   define EINTR           4
# endif /* EINTR */
# if !defined (EIO)
#   define EIO             5
# endif /* EIO */
# if !defined (ENXIO)
#   define ENXIO           6
# endif /* ENXIO */
# if !defined (E2BIG)
#   define E2BIG           7
# endif /* E2BIG */
# if !defined (ENOEXEC)
#   define ENOEXEC         8
# endif /* ENOEXEC */
# if !defined (EBADF)
#   define EBADF           9
# endif /* EBADF */
# if !defined (ECHILD)
#   define ECHILD          10
# endif /* ECHILD */
# if !defined (EAGAIN)
#   define EAGAIN          11
# endif /* EAGAIN */
# if !defined (ENOMEM)
#   define ENOMEM          12
# endif /* ENOMEM */
# if !defined (EACCES)
#   define EACCES          13
# endif /* EACCES */
# if !defined (EFAULT)
#   define EFAULT          14
# endif /* EFAULT */
# if !defined (EBUSY)
#   define EBUSY           16
# endif /* EBUSY */
# if !defined (EEXIST)
#   define EEXIST          17
# endif /* EEXIST */
# if !defined (EXDEV)
#   define EXDEV           18
# endif /* EXDEV */
# if !defined (ENODEV)
#   define ENODEV          19
# endif /* ENODEV */
# if !defined (ENOTDIR)
#   define ENOTDIR         20
# endif /* ENOTDIR */
# if !defined (EISDIR)
#   define EISDIR          21
# endif /* EISDIR */
# if !defined (EINVAL)
#   define EINVAL          22
# endif /* EINVAL */
# if !defined (ENFILE)
#   define ENFILE          23
# endif /* ENFILE */
# if !defined (EMFILE)
#   define EMFILE          24
# endif /* EMFILE */
# if !defined (ENOTTY)
#   define ENOTTY          25
# endif /* ENOTTY */
# if !defined (EFBIG)
#   define EFBIG           27
# endif /* EFBIG */
# if !defined (ENOSPC)
#   define ENOSPC          28
# endif /* ENOSPC */
# if !defined (ESPIPE)
#   define ESPIPE          29
# endif /* ESPIPE */
# if !defined (EROFS)
#   define EROFS           30
# endif /* EROFS */
# if !defined (EMLINK)
#   define EMLINK          31
# endif /* EMLINK */
# if !defined (EPIPE)
#   define EPIPE           32
# endif /* EPIPE */
# if !defined (EDOM)
#   define EDOM            33
# endif /* EDOM */
# if !defined (ERANGE)
#   define ERANGE          34
# endif /* ERANGE */
# if !defined (EDEADLK)
#   define EDEADLK         36
# endif /* EDEADLK */
# if !defined (ENAMETOOLONG)
#   define ENAMETOOLONG    38
# endif /* ENAMETOOLONG */
# if !defined (ENOLCK)
#   define ENOLCK          39
# endif /* ENOLCK */
# if !defined (ENOSYS)
#   define ENOSYS          40
# endif /* ENOSYS */
# if !defined (ENOTEMPTY)
#   define ENOTEMPTY       41
# endif /* ENOTEMPTY */
#endif /* ACE_LACKS_ERRNO_H */

#if defined (ACE_LACKS_T_ERRNO)
extern int t_errno;
#endif /* ACE_LACKS_T_ERRNO */

#if !defined (ENOSYS)
# define ENOSYS EFAULT /* Operation not supported or unknown error. */
#endif /* !ENOSYS */

#if !defined (ENOTSUP)
# define ENOTSUP ENOSYS  /* Operation not supported. */
#endif /* !ENOTSUP */

#if !defined (ESUCCESS)
#  define ESUCCESS 0
#endif /* !ESUCCESS */

#if !defined (EIDRM)
#  define EIDRM 0
#endif /* !EIDRM */

#if !defined (ENFILE)
#  define ENFILE EMFILE /* No more socket descriptors are available. */
#endif /* !ENFILE */

#if !defined (ECOMM)
   // Not the same, but ECONNABORTED is provided on NT.
#  define ECOMM ECONNABORTED
#endif /* ECOMM */

#if !defined (EDEADLK)
#  define EDEADLK 1000 /* Some large number.... */
#endif /* !EDEADLK */

#if !defined (ENXIO)     /* Needed in SOCK_Dgram_Mcast */
#   define ENXIO  6
#endif /* ENXIO */

#if !defined (ETIMEDOUT) && defined (ETIME)
#  define ETIMEDOUT ETIME
#endif /* ETIMEDOUT */

#if !defined (ETIME) && defined (ETIMEDOUT)
#  define ETIME ETIMEDOUT
#endif /* ETIMED */

#if !defined (EBUSY)
#  define EBUSY ETIME
#endif /* EBUSY */

#if !defined (ECANCELED)
#  define ECANCELED 125
#endif /* ECANCELED */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#include /**/ "ace/post.h"
#endif /* ACE_OS_INCLUDE_OS_ERRNO_H */
