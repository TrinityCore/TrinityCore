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

#if !defined(PLATFORM_DEFINED) && (defined(WIN32) || defined(WIN64))

  // In MSVC 8.0, there are some functions declared as deprecated.
  #if _MSC_VER >= 1400
  #define _CRT_SECURE_NO_DEPRECATE
  #define _CRT_NON_CONFORMING_SWPRINTFS
  #endif

  #include <tchar.h>
  #include <assert.h>
  #include <ctype.h>
  #include <stdio.h>
  #include <windows.h>
  #include <wininet.h>
  #include <sys/types.h>
  #define PLATFORM_LITTLE_ENDIAN

  #ifdef WIN64
    #define PLATFORM_64BIT
  #else
    #define PLATFORM_32BIT
  #endif

  #define PATH_SEPARATOR     '\\'
  #define CREATE_DIRECTORY(name)    CreateDirectory(name, NULL);

  #define PLATFORM_WINDOWS
  #define PLATFORM_DEFINED                  // The platform is known now

#endif

//-----------------------------------------------------------------------------
// Defines for Mac

#if !defined(PLATFORM_DEFINED) && defined(__APPLE__)  // Mac BSD API

  // Macintosh
  #include <sys/types.h>
  #include <sys/stat.h>
  #include <sys/mman.h>
  #include <unistd.h>
  #include <fcntl.h>
  #include <stdlib.h>
  #include <dirent.h>
  #include <errno.h>
  #include <stddef.h>

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

  #define PATH_SEPARATOR     '/'
  #define CREATE_DIRECTORY(name)    mkdir(name, 0755)

  #define PLATFORM_MAC
  #define PLATFORM_DEFINED                  // The platform is known now

  #define FIELD_OFFSET(t,f) offsetof(t,f)
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
  #include <assert.h>
  #include <errno.h>

  #define PATH_SEPARATOR     '/'
  #define CREATE_DIRECTORY(name)    mkdir(name, 0755)

  #define PLATFORM_LITTLE_ENDIAN
  #define PLATFORM_LINUX
  #define PLATFORM_DEFINED

  #define FIELD_OFFSET(t,f) offsetof(t,f)
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
  typedef unsigned long  DWORD_PTR;
  typedef long           LONG_PTR;
  typedef long           INT_PTR;
  typedef long long      LONGLONG;
  typedef unsigned long long ULONGLONG;
  typedef unsigned long long *PULONGLONG;
  typedef void         * HANDLE;
  typedef void         * LPOVERLAPPED; // Unsupported on Linux and Mac
  typedef char           TCHAR;
  typedef unsigned int   LCID;
  typedef LONG         * PLONG;
  typedef DWORD        * PDWORD;
  typedef BYTE         * LPBYTE;

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
  #define _tcscpy   strcpy
  #define _tcscat   strcat
  #define _tcschr   strchr
  #define _tcsrchr  strrchr
  #define _tcsstr   strstr
  #define _tcsspn   strspn
  #define _tcsncmp  strncmp
  #define _tprintf  printf
  #define _stprintf sprintf
  #define _tremove  remove
  #define _tmkdir   mkdir

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
  #define ERROR_ACCESS_DENIED            EPERM
  #define ERROR_INVALID_HANDLE           EBADF
  #define ERROR_NOT_ENOUGH_MEMORY        ENOMEM
  #define ERROR_NOT_SUPPORTED            ENOTSUP
  #define ERROR_INVALID_PARAMETER        EINVAL
  #define ERROR_DISK_FULL                ENOSPC
  #define ERROR_ALREADY_EXISTS           EEXIST
  #define ERROR_INSUFFICIENT_BUFFER      ENOBUFS
  #define ERROR_BAD_FORMAT               1000        // No such error code under Linux
  #define ERROR_NO_MORE_FILES            1001        // No such error code under Linux
  #define ERROR_HANDLE_EOF               1002        // No such error code under Linux
  #define ERROR_CAN_NOT_COMPLETE         1003        // No such error code under Linux
  #define ERROR_FILE_CORRUPT             1004        // No such error code under Linux
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

#endif // __CASCPORT_H__
