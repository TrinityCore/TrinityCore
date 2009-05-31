/*****************************************************************************/
/* Storm.h                           Copyright Justin Olbrantz(Quantam) 2000 */
/*---------------------------------------------------------------------------*/
/* Storm Interface Library v1.0 for Windows                                  */
/*                                                                           */
/* Author : Justin Olbrantz(Quantam)                                         */
/* E-mail : omega@dragonfire.net                                             */
/* WWW    : www.campaigncreations.com/starcraft/mpq2k/inside_mopaq/          */
/*---------------------------------------------------------------------------*/
/*   Date    Ver   Who  Comment                                              */
/* --------  ----  ---  -------                                              */
/* xx.xx.00  1.00  Qua  The first version of Storm.h                         */
/* 11.04.03  1.00  Lad  Added some functions                                 */
/*****************************************************************************/

// We need the Windows data types for the Storm prototypes
#include <windows.h>

#ifndef __STORM_H__
#define __STORM_H__

// Somethimes is necessary to change the function names so they
// will not conflict with other MPQ tools.
#ifdef STORM_ALTERNATE_NAMES
  #define SFILE(Name) Storm##Name
  #define SCOMP(Name) Storm##Name
#else
  #define SFILE(Name) SFile##Name
  #define SCOMP(Name) SComp##Name
#endif


// Just in case anyone is still using C out there
#ifdef __cplusplus
extern "C" {
#endif

// Storm file function prototypes
BOOL  WINAPI SFILE(OpenArchive)(LPCSTR lpFileName, DWORD dwPriority, DWORD dwFlags, HANDLE *hMPQ);
BOOL  WINAPI SFILE(CloseArchive)(HANDLE hMPQ);
BOOL  WINAPI SFILE(GetArchiveName)(HANDLE hMPQ, LPCSTR lpBuffer, DWORD dwBufferLength);
BOOL  WINAPI SFILE(OpenFile)(LPCSTR lpFileName, HANDLE *hFile);
BOOL  WINAPI SFILE(OpenFileEx)(HANDLE hMPQ, LPCSTR lpFileName, DWORD dwSearchScope, HANDLE *hFile);
BOOL  WINAPI SFILE(CloseFile)(HANDLE hFile);
DWORD WINAPI SFILE(GetFileSize)(HANDLE hFile, LPDWORD lpFileSizeHigh);
BOOL  WINAPI SFILE(GetFileArchive)(HANDLE hFile, HANDLE *hMPQ);
BOOL  WINAPI SFILE(GetFileName)(HANDLE hFile, LPCSTR lpBuffer, DWORD dwBufferLength);
DWORD WINAPI SFILE(SetFilePointer)(HANDLE hFile, long lDistanceToMove, PLONG lplDistanceToMoveHigh, DWORD dwMoveMethod);
BOOL  WINAPI SFILE(ReadFile)(HANDLE hFile,LPVOID lpBuffer,DWORD nNumberOfBytesToRead,LPDWORD lpNumberOfBytesRead,LPOVERLAPPED lpOverlapped);
LCID  WINAPI SFILE(SetLocale)(LCID nNewLocale);
BOOL  WINAPI SFILE(GetBasePath)(LPCSTR lpBuffer, DWORD dwBufferLength);
BOOL  WINAPI SFILE(SetBasePath)(LPCSTR lpNewBasePath);

// Storm (de)compression functions
BOOL  WINAPI SCOMP(Compress)  (char * pbOutBuffer, int * pdwOutLength, char * pbInBuffer, int dwInLength, int uCmp, int uCmpType, int nCmpLevel);
BOOL  WINAPI SCOMP(Decompress)(char * pbOutBuffer, int * pdwOutLength, char * pbInBuffer, int dwInLength);


#if defined(_MSC_VER) && !defined(BUILDING_STORM_CPP)
#pragma comment(lib, "Storm.lib")    // Force linking Storm.lib and thus Storm.dll
#endif

#ifdef __cplusplus
}
#endif

#endif // __STORM_H__
