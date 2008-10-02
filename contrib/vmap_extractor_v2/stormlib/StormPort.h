/*****************************************************************************/
/* StormPort.h                           Copyright (c) Marko Friedemann 2001 */
/*---------------------------------------------------------------------------*/
/* Portability module for the StormLib library. Contains a wrapper symbols   */
/* to make the compilation under Linux work                                  */
/*                                                                           */
/* Author: Marko Friedemann <marko.friedemann@bmx-chemnitz.de>               */
/* Created at: Mon Jan 29 18:26:01 CEST 2001                                 */
/* Computer: whiplash.flachland-chemnitz.de                                  */
/* System: Linux 2.4.0 on i686                                               */
/*                                                                           */
/* Author: Sam Wilkins                                                       */
/* System: Mac OS X and port to big endian processor                         */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/*   Date    Ver   Who  Comment                                              */
/* --------  ----  ---  -------                                              */
/* 29.01.01  1.00  Mar  Created                                              */
/* 24.03.03  1.01  Lad  Some cosmetic changes                                */
/* 12.11.03  1.02  Dan  Macintosh compatibility                              */
/* 24.07.04  1.03  Sam  Mac OS X compatibility                               */
/* 22.11.06  1.04  Sam  Mac OS X compatibility (for StormLib 6.0)            */
/* 31.12.06  1.05  XPinguin  Full GNU/Linux compatibility		     */
/*****************************************************************************/

#ifndef __STORMPORT_H__
#define __STORMPORT_H__

// Defines for Windows
#if !defined(PLATFORM_DEFINED) && (defined(WIN32) || defined(WIN64))

  // In MSVC 8.0, there are some functions declared as deprecated.
  #if _MSC_VER >= 1400
  #define _CRT_SECURE_NO_DEPRECATE
  #define _CRT_NON_CONFORMING_SWPRINTFS
  #endif

  #include <assert.h>      
  #include <stdio.h>      
  #include <windows.h>      
  #define PLATFORM_LITTLE_ENDIAN  1

  #ifdef WIN64
    #define PLATFORM_64BIT
  #else
    #define PLATFORM_32BIT
  #endif

  #define PLATFORM_DEFINED                  // The platform is known now

#endif

// Defines for Mac Carbon 
#if !defined(PLATFORM_DEFINED) && defined(__APPLE__)  // Mac Carbon API

  // Macintosh using Carbon
  #include <Carbon/Carbon.h> // Mac OS X
  #define _stricmp strcasecmp  // Case insensitive strcmp has a different name on this platform.
  #define _strnicmp strncasecmp
  
  typedef void          * LPCSTR;
  typedef unsigned long * LPDWORD;
  typedef long          * PLONG;
  typedef void          * LPVOID;
  typedef unsigned int  UINT;
  
  #define    PKEXPORT
  #define    __SYS_ZLIB
  #define    __SYS_BZLIB
  #define    LANG_NEUTRAL   0

  #if defined(__BIG_ENDIAN__)
    #define PLATFORM_LITTLE_ENDIAN  0
  #else
    #define PLATFORM_LITTLE_ENDIAN  1       // Apple is now making Macs with Intel CPUs
  #endif
  #define PLATFORM_DEFINED                  // The platform is known now

#endif

// Assumption: we are not on Windows nor Macintosh, so this must be linux *grin*
// Ladik : Why the hell Linux does not use some OS-dependent #define ?
#if !defined(PLATFORM_DEFINED)

  #include <sys/types.h>
  #include <sys/stat.h>
  #include <fcntl.h>
  #include <unistd.h>
  #include <stdint.h>
  #include <stdlib.h>
  #include <stdio.h>
  #include <stdarg.h>
  #include <string.h>
  #include <ctype.h>
  #include <assert.h>

  #define PLATFORM_LITTLE_ENDIAN  1
  #define PLATFORM_DEFINED
  #define LANG_NEUTRAL   0

#endif  /* not __powerc */


#if !defined(WIN32) && !defined(WIN64)

  // Typedefs for ANSI C
  typedef unsigned char  BYTE;
  typedef short          SHORT;
  typedef unsigned short WORD;
  typedef unsigned short USHORT;
  typedef long           LONG;
  typedef unsigned long  DWORD;
  typedef unsigned long  DWORD_PTR;
  typedef long           LONG_PTR;
  typedef long long      LONGLONG;
#ifndef __OBJC__
  #define BOOL           bool
#endif
  typedef void         * HANDLE;
  typedef void         * LPOVERLAPPED; // Unsupported on Linux
  typedef char           TCHAR;
  typedef unsigned long  LCID;
  
  typedef void          * LPCSTR;
  typedef unsigned long * LPDWORD;
  typedef long          * PLONG;
  typedef void          * LPVOID;
  typedef unsigned int  UINT;
  
  typedef struct _FILETIME
  { 
      DWORD dwLowDateTime; 
      DWORD dwHighDateTime; 
  }
  FILETIME, *PFILETIME;

  typedef union _LARGE_INTEGER
  {
  #if PLATFORM_LITTLE_ENDIAN
    struct
    {
        DWORD LowPart;
        LONG HighPart;
    };
  #else
    struct
    {
        LONG HighPart;
        DWORD LowPart;
    };
  #endif
    LONGLONG QuadPart;
  }
  LARGE_INTEGER, *PLARGE_INTEGER;
  
  // Some Windows-specific defines
  #ifndef MAX_PATH
    #define MAX_PATH 1024
  #endif

  #ifndef TRUE
    #define TRUE true
  #endif

  #ifndef FALSE
    #define FALSE false
  #endif

  #define VOID     void
  #define WINAPI 

  #define FILE_BEGIN    SEEK_SET
  #define FILE_CURRENT  SEEK_CUR
  #define FILE_END      SEEK_END
  
  #define CREATE_NEW    1
  #define CREATE_ALWAYS 2
  #define OPEN_EXISTING 3
  #define OPEN_ALWAYS   4
  
  #define FILE_SHARE_READ 0x00000001L
  #define GENERIC_WRITE   0x40000000
  #define GENERIC_READ    0x80000000
  
  #define FILE_FLAG_DELETE_ON_CLOSE         1   // Sam: Added these two defines so it would compile.
  #define FILE_FLAG_SEQUENTIAL_SCAN         2
  
  #define ERROR_SUCCESS                     0
  #define ERROR_INVALID_FUNCTION            1
  #define ERROR_FILE_NOT_FOUND              2
  #define ERROR_ACCESS_DENIED               5
  #define ERROR_NOT_ENOUGH_MEMORY           8
  #define ERROR_BAD_FORMAT                 11
  #define ERROR_NO_MORE_FILES              18
  #define ERROR_GEN_FAILURE                31
  #define ERROR_HANDLE_EOF                 38
  #define ERROR_HANDLE_DISK_FULL           39
  #define ERROR_NOT_SUPPORTED              50
  #define ERROR_INVALID_PARAMETER          87
  #define ERROR_DISK_FULL                 112
  #define ERROR_CALL_NOT_IMPLEMENTED      120
  #define ERROR_ALREADY_EXISTS            183
  #define ERROR_CAN_NOT_COMPLETE         1003
  #define ERROR_PARAMETER_QUOTA_EXCEEDED 1283
  #define ERROR_FILE_CORRUPT             1392
  #define ERROR_INSUFFICIENT_BUFFER      4999
  
  #define INVALID_HANDLE_VALUE ((HANDLE) -1)
  
  #ifndef min
  #define min(a, b) ((a < b) ? a : b)
  #endif
  
  #ifndef max
  #define max(a, b) ((a > b) ? a : b)
  #endif
  
  #define _stricmp strcasecmp
  #define _strnicmp strncasecmp
  
  extern int globalerr;
  
  void  SetLastError(int err);
  int   GetLastError();
  char *ErrString(int err);

  // Emulation of functions for file I/O available in Win32
  HANDLE CreateFile(const char * lpFileName, DWORD dwDesiredAccess, DWORD dwShareMode, void * lpSecurityAttributes, DWORD dwCreationDisposition, DWORD dwFlagsAndAttributes, HANDLE hTemplateFile);
  BOOL   CloseHandle(HANDLE hObject);

  DWORD  GetFileSize(HANDLE hFile, DWORD * lpFileSizeHigh);
  DWORD  SetFilePointer(HANDLE, LONG lDistanceToMove, LONG * lpDistanceToMoveHigh, DWORD dwMoveMethod);
  BOOL   SetEndOfFile(HANDLE hFile);

  BOOL   ReadFile(HANDLE hFile, void * lpBuffer, DWORD nNumberOfBytesToRead, DWORD * lpNumberOfBytesRead, void * lpOverLapped);
  BOOL   WriteFile(HANDLE hFile, const void * lpBuffer, DWORD nNumberOfBytesToWrite, DWORD * lpNumberOfBytesWritten, void * lpOverLapped);

  BOOL   IsBadReadPtr(const void * ptr, int size);
  DWORD  GetFileAttributes(const char * szileName);

  BOOL   DeleteFile(const char * lpFileName);
  BOOL   MoveFile(const char * lpFromFileName, const char * lpToFileName);
  void   GetTempPath(DWORD szTempLength, char * szTemp);
  void   GetTempFileName(const char * lpTempFolderPath, const char * lpFileName, DWORD something, char * szLFName);

  #define strnicmp strncasecmp

#endif // !WIN32

#if PLATFORM_LITTLE_ENDIAN
    #define    BSWAP_INT16_UNSIGNED(a)          (a)
    #define    BSWAP_INT16_SIGNED(a)            (a)
    #define    BSWAP_INT32_UNSIGNED(a)          (a)
    #define    BSWAP_INT32_SIGNED(a)            (a)
    #define    BSWAP_ARRAY16_UNSIGNED(a,b)      {}
    #define    BSWAP_ARRAY32_UNSIGNED(a,b)      {}
    #define    BSWAP_TMPQSHUNT(a)               {}
    #define    BSWAP_TMPQHEADER(a)              {}
#else
    extern unsigned short SwapUShort(unsigned short);
    extern unsigned long SwapULong(unsigned long);
    extern short SwapShort(unsigned short);
    extern long SwapLong(unsigned long);
    extern void ConvertUnsignedLongBuffer(unsigned long *buffer, unsigned long nbLongs);
    extern void ConvertUnsignedShortBuffer(unsigned short *buffer, unsigned long nbShorts);
    extern void ConvertTMPQShunt(void *shunt);
    extern void ConvertTMPQHeader(void *header);
    #define    BSWAP_INT16_UNSIGNED(a)          SwapUShort((a))
    #define    BSWAP_INT32_UNSIGNED(a)          SwapULong((a))
    #define    BSWAP_INT16_SIGNED(a)            SwapShort((a))
    #define    BSWAP_INT32_SIGNED(a)            SwapLong((a))
    #define    BSWAP_ARRAY16_UNSIGNED(a,b)      ConvertUnsignedShortBuffer((a),(b))
    #define    BSWAP_ARRAY32_UNSIGNED(a,b)      ConvertUnsignedLongBuffer((a),(b))
    #define    BSWAP_TMPQSHUNT(a)               ConvertTMPQShunt((a))
    #define    BSWAP_TMPQHEADER(a)              ConvertTMPQHeader((a))
#endif

#endif // __STORMPORT_H__
