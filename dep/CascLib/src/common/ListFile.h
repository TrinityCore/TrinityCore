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

void * ListFile_OpenExternal(const TCHAR * szListFile);
size_t ListFile_GetNext(void * pvListFile, const char * szMask, char * szBuffer, size_t nMaxChars);
void ListFile_Free(void * pvListFile);

#endif // __LISTFILE_H__
