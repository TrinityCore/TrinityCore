/*****************************************************************************/
/* CascPort.h                             Copyright (c) Ladislav Zezula 2014 */
/*---------------------------------------------------------------------------*/
/* Portability module for the CascLib library. Contains a wrapper symbols    */
/* to make the compilation under Linux work                                  */
/*---------------------------------------------------------------------------*/
/*   Date    Ver   Who  Comment                                              */
/* --------  ----  ---  -------                                              */
/* 29.04.14  1.00  Lad  Created                                              */
/*****************************************************************************/

#ifndef __CASCPORT_H__
#define __CASCPORT_H__

#ifndef __cplusplus
  #define bool char
  #define true 1
  #define false 0
#endif

//-----------------------------------------------------------------------------
// Defines for Windows

#if !defined(PLATFORM_DEFINED) && (defined(_WIN32) || defined(_WIN64))

  // In MSVC 8.0, there are some functions declared as deprecated.
  #if _MSC_VER >= 1400
    #ifndef _CRT_SECURE_NO_DEPRECATE
      #define _CRT_SECURE_NO_DEPRECATE
    #endif
    #ifndef _CRT_NON_CONFORMING_SWPRINTFS
      #define _CRT_NON_CONFORMING_SWPRINTFS
    #endif
  #endif

  #ifndef WIN32_LEAN_AND_MEAN
    #define WIN32_LEAN_AND_MEAN
  #endif

  // Suppress definitions of `min` and `max` macros by <windows.h>:
  #define NOMINMAX 1

  #include <tchar.h>
  #include <assert.h>
  #include <ctype.h>
  #include <io.h>
  #include <stdio.h>
  #include <stdlib.h>
  #include <direct.h>
  #include <malloc.h>
  #include <windows.h>
  #include <wininet.h>
  #include <strsafe.h>
  #include <sys/types.h>
  #define PLATFORM_LITTLE_ENDIAN

  #ifdef _WIN64
    #define PLATFORM_64BIT
  #else
    #define PLATFORM_32BIT
  #endif

  #define URL_SEP_CHAR              '/'
  #define PATH_SEP_CHAR             '\\'
  #define PATH_SEP_STRING           "\\"

  #define PLATFORM_WINDOWS
  #define PLATFORM_DEFINED                  // The platform is known now

#endif

#if _MSC_VER >= 1500
  #include <intrin.h>       // Support for intrinsic functions
  #pragma intrinsic(memcmp, memcpy)
#endif

#ifndef FIELD_OFFSET
#define FIELD_OFFSET(type, field)    ((LONG)(size_t)&(((type *)0)->field))
#endif

//-----------------------------------------------------------------------------
// Defines for Mac

#if !defined(PLATFORM_DEFINED) && defined(__APPLE__)  // Mac BSD API

  // Macintosh
  #include <sys/types.h>
  #include <sys/stat.h>
  #include <sys/mman.h>
  #include <fcntl.h>
  #include <dirent.h>
  #include <unistd.h>
  #include <stddef.h>
  #include <stdint.h>
  #include <stdlib.h>
  #include <stdio.h>
  #include <stdarg.h>
  #include <string.h>
  #include <ctype.h>
  #include <wchar.h>
  #include <cassert>
  #include <errno.h>
  #include <pthread.h>

  // Support for PowerPC on Max OS X
  #if (__ppc__ == 1) || (__POWERPC__ == 1) || (_ARCH_PPC == 1)
    #include <stdint.h>
    #include <CoreFoundation/CFByteOrder.h>
  #endif

  #define    PKEXPORT
  #define    __SYS_ZLIB
  #define    __SYS_BZLIB

  #ifndef __BIG_ENDIAN__
    #define PLATFORM_LITTLE_ENDIAN
  #endif

  #define URL_SEP_CHAR              '/'
  #define PATH_SEP_CHAR             '/'
  #define PATH_SEP_STRING           "/"

  #define PLATFORM_MAC
  #define PLATFORM_DEFINED                  // The platform is known now

#endif

//-----------------------------------------------------------------------------
// Assumption: we are not on Windows nor Macintosh, so this must be linux *grin*

#if !defined(PLATFORM_DEFINED)
  #include <sys/types.h>
  #include <sys/stat.h>
  #include <sys/mman.h>
  #include <fcntl.h>
  #include <dirent.h>
  #include <unistd.h>
  #include <stddef.h>
  #include <stdint.h>
  #include <stdlib.h>
  #include <stdio.h>
  #include <stdarg.h>
  #include <string.h>
  #include <ctype.h>
  #include <wchar.h>
  #include <assert.h>
  #include <errno.h>
  #include <pthread.h>

  #define URL_SEP_CHAR              '/'
  #define PATH_SEP_CHAR             '/'
  #define PATH_SEP_STRING           "/"

  #define PLATFORM_LITTLE_ENDIAN
  #define PLATFORM_LINUX
  #define PLATFORM_DEFINED

#endif

//-----------------------------------------------------------------------------
// Definition of Windows-specific types for non-Windows platforms

#ifndef PLATFORM_WINDOWS
  #if __LP64__
    #define PLATFORM_64BIT
  #else
    #define PLATFORM_32BIT
  #endif

  // Typedefs for ANSI C
  typedef unsigned char  BYTE;
  typedef unsigned short USHORT;
  typedef int            LONG;
  typedef unsigned int   DWORD;
  typedef long long      LONGLONG;
  typedef signed long long LONGLONG;
  typedef signed long long *PLONGLONG;
  typedef unsigned long long ULONGLONG;
  typedef unsigned long long *PULONGLONG;
  typedef void         * HANDLE;
  typedef char           TCHAR;
  typedef unsigned int   LCID;
  typedef LONG         * PLONG;
  typedef DWORD        * PDWORD;
  typedef BYTE         * LPBYTE;
  typedef char         * LPSTR;
  typedef const char   * LPCSTR;
  typedef TCHAR        * LPTSTR;
  typedef const TCHAR  * LPCTSTR;

  #ifdef PLATFORM_32BIT
    #define _LZMA_UINT32_IS_ULONG
  #endif

  // Some Windows-specific defines
  #ifndef MAX_PATH
    #define MAX_PATH 1024
  #endif

  #define WINAPI

  #define FILE_BEGIN    SEEK_SET
  #define FILE_CURRENT  SEEK_CUR
  #define FILE_END      SEEK_END

  #define INVALID_HANDLE_VALUE ((HANDLE)-1)

  #define _T(x)     x
  #define _tcslen   strlen
  #define _tcscat   strcat
  #define _tcschr   strchr
  #define _tcsrchr  strrchr
  #define _tcsstr   strstr
  #define _tcsspn   strspn
  #define _tcsncmp  strncmp
  #define _tprintf  printf
  #define _tremove  remove
  #define _taccess  access
  #define _access   access

  #define _stricmp  strcasecmp
  #define _strnicmp strncasecmp
  #define _tcsicmp  strcasecmp
  #define _tcsnicmp strncasecmp

#endif // !PLATFORM_WINDOWS

// 64-bit calls are supplied by "normal" calls on Mac
#if defined(PLATFORM_MAC)
  #define stat64  stat
  #define fstat64 fstat
  #define lseek64 lseek
  #define ftruncate64 ftruncate
  #define off64_t off_t
  #define O_LARGEFILE 0
#endif

// Platform-specific error codes for UNIX-based platforms
#if defined(PLATFORM_MAC) || defined(PLATFORM_LINUX)
  #define ERROR_SUCCESS                  0
  #define ERROR_FILE_NOT_FOUND           ENOENT
  #define ERROR_PATH_NOT_FOUND           ENOENT
  #define ERROR_ACCESS_DENIED            EPERM
  #define ERROR_INVALID_HANDLE           EBADF
  #define ERROR_NOT_ENOUGH_MEMORY        ENOMEM
  #define ERROR_NOT_SUPPORTED            ENOTSUP
  #define ERROR_INVALID_PARAMETER        EINVAL
  #define ERROR_DISK_FULL                ENOSPC
  #define ERROR_ALREADY_EXISTS           EEXIST
  #define ERROR_INSUFFICIENT_BUFFER      ENOBUFS
  #define ERROR_BAD_FORMAT               1000       // No such error code under Linux
  #define ERROR_NO_MORE_FILES            1001       // No such error code under Linux
  #define ERROR_HANDLE_EOF               1002       // No such error code under Linux
  #define ERROR_CAN_NOT_COMPLETE         1003       // No such error code under Linux
  #define ERROR_FILE_CORRUPT             1004       // No such error code under Linux
  #define ERROR_FILE_ENCRYPTED           1005       // Returned by encrypted stream when can't find file key
#endif

#ifndef ERROR_FILE_INCOMPLETE
#define ERROR_FILE_INCOMPLETE            1006       // The required file part is missing
#endif

#ifndef ERROR_FILE_OFFLINE
#define ERROR_FILE_OFFLINE               1007       // The file is not available in the local storage
#endif

#ifndef ERROR_BUFFER_OVERFLOW
#define ERROR_BUFFER_OVERFLOW            1008
#endif

#ifndef ERROR_CANCELLED
#define ERROR_CANCELLED                  1009
#endif

#ifndef ERROR_INDEX_PARSING_DONE
#define ERROR_INDEX_PARSING_DONE         1010
#endif

#ifndef _countof
#define _countof(x)   (sizeof(x) / sizeof(x[0]))
#endif

//-----------------------------------------------------------------------------
// Swapping functions

#ifdef PLATFORM_LITTLE_ENDIAN
    #define    BSWAP_INT16_UNSIGNED(a)          (a)
    #define    BSWAP_INT16_SIGNED(a)            (a)
    #define    BSWAP_INT32_UNSIGNED(a)          (a)
    #define    BSWAP_INT32_SIGNED(a)            (a)
    #define    BSWAP_INT64_SIGNED(a)            (a)
    #define    BSWAP_INT64_UNSIGNED(a)          (a)
    #define    BSWAP_ARRAY16_UNSIGNED(a,b)      {}
    #define    BSWAP_ARRAY32_UNSIGNED(a,b)      {}
    #define    BSWAP_ARRAY64_UNSIGNED(a,b)      {}
#else

#ifdef __cplusplus
  extern "C" {
#endif
    int16_t  SwapInt16(uint16_t);
    uint16_t SwapUInt16(uint16_t);
    int32_t  SwapInt32(uint32_t);
    uint32_t SwapUInt32(uint32_t);
    int64_t  SwapInt64(uint64_t);
    uint64_t SwapUInt64(uint64_t);
    void ConvertUInt16Buffer(void * ptr, size_t length);
    void ConvertUInt32Buffer(void * ptr, size_t length);
    void ConvertUInt64Buffer(void * ptr, size_t length);
#ifdef __cplusplus
  }
#endif
    #define    BSWAP_INT16_SIGNED(a)            SwapInt16((a))
    #define    BSWAP_INT16_UNSIGNED(a)          SwapUInt16((a))
    #define    BSWAP_INT32_SIGNED(a)            SwapInt32((a))
    #define    BSWAP_INT32_UNSIGNED(a)          SwapUInt32((a))
    #define    BSWAP_INT64_SIGNED(a)            SwapInt64((a))
    #define    BSWAP_INT64_UNSIGNED(a)          SwapUInt64((a))
    #define    BSWAP_ARRAY16_UNSIGNED(a,b)      ConvertUInt16Buffer((a),(b))
    #define    BSWAP_ARRAY32_UNSIGNED(a,b)      ConvertUInt32Buffer((a),(b))
    #define    BSWAP_ARRAY64_UNSIGNED(a,b)      ConvertUInt64Buffer((a),(b))
#endif

//-----------------------------------------------------------------------------
// Interlocked operations

inline DWORD CascInterlockedIncrement(DWORD * PtrValue)
{
#ifdef PLATFORM_WINDOWS
    return (DWORD)InterlockedIncrement((LONG *)(PtrValue));
#elif defined(__GNUC__)
    return __sync_add_and_fetch(PtrValue, 1);
#else
    #define INTERLOCKED_NOT_SUPPORTED
    return ++(*PtrValue);
#endif
}

inline DWORD CascInterlockedDecrement(DWORD * PtrValue)
{
#ifdef PLATFORM_WINDOWS
    return (DWORD)InterlockedDecrement((LONG *)(PtrValue));
#elif defined(__GNUC__)
    return __sync_sub_and_fetch(PtrValue, 1);
#else
    return --(*PtrValue);
#endif
}

//-----------------------------------------------------------------------------
// Lock functions

#ifdef PLATFORM_WINDOWS

typedef RTL_CRITICAL_SECTION CASC_LOCK;
#define CascInitLock(Lock)      InitializeCriticalSection(&Lock);
#define CascFreeLock(Lock)      DeleteCriticalSection(&Lock);
#define CascLock(Lock)          EnterCriticalSection(&Lock);
#define CascUnlock(Lock)        LeaveCriticalSection(&Lock);

#else

typedef pthread_mutex_t CASC_LOCK;
#define CascInitLock(Lock)      pthread_mutex_init(&Lock, NULL);
#define CascFreeLock(Lock)      pthread_mutex_destroy(&Lock);
#define CascLock(Lock)          pthread_mutex_lock(&Lock);
#define CascUnlock(Lock)        pthread_mutex_unlock(&Lock);

#endif

//-----------------------------------------------------------------------------
// Forbidden functions, do not use

#ifdef __CASCLIB_SELF__
#define strcpy  UNSAFE_DO_NOT_USE_STRCPY
#define strcat  UNSAFE_DO_NOT_USE_STRCAT
#define sprintf UNSAFE_DO_NOT_USE_SPRINTF
#endif

#endif // __CASCPORT_H__
