/*****************************************************************************/
/* ListFile.h                             Copyright (c) Ladislav Zezula 2014 */
/*---------------------------------------------------------------------------*/
/* Common functions for CascLib                                              */
/*---------------------------------------------------------------------------*/
/*   Date    Ver   Who  Comment                                              */
/* --------  ----  ---  -------                                              */
/* 10.05.14  1.00  Lad  The first version of ListFile.h                      */
/*****************************************************************************/

#ifndef __LISTFILE_H__
#define __LISTFILE_H__

//-----------------------------------------------------------------------------
// Functions for parsing an external listfile

void * ListFile_OpenExternal(const TCHAR * szListFile);
void * ListFile_FromBuffer(LPBYTE pbBuffer, DWORD cbBuffer);
bool   ListFile_VerifyMD5(void * pvListFile, LPBYTE pbHashMD5);
size_t ListFile_GetNextLine(void * pvListFile, const char ** pszLineBegin, const char ** pszLineEnd);
size_t ListFile_GetNextLine(void * pvListFile, char * szBuffer, size_t nMaxChars);
size_t ListFile_GetNext(void * pvListFile, char * szBuffer, size_t nMaxChars, PDWORD PtrFileDataId);
LPBYTE ListFile_GetData(void * pvListFile, PDWORD PtrDataSize);

#endif // __LISTFILE_H__
