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
// Structures

typedef struct _LISTFILE_ENTRY
{
    ULONGLONG FileNameHash;             // Hash of the file name
    DWORD cbEntrySize;                  // Length of this entry, in bytes
    char szFileName[1];                 // File name, aligned to 8-byte boundary

} LISTFILE_ENTRY, *PLISTFILE_ENTRY;

typedef struct _LISTFILE_MAP
{
    PCASC_MAP pNameMap;                 // Map of hash-to-name
    size_t cbBufferMax;                 // Total size of the buffer, in bytes
    size_t cbBuffer;                    // Current size of the buffer, in bytes
    size_t nEntries;                    // Number of entries

    // First LISTFILE_ENTRY starts here

} LISTFILE_MAP, *PLISTFILE_MAP;

//-----------------------------------------------------------------------------
// Functions for parsing an external listfile

void * ListFile_OpenExternal(const TCHAR * szListFile);
size_t ListFile_GetNext(void * pvListFile, const char * szMask, char * szBuffer, size_t nMaxChars);
void ListFile_Free(void * pvListFile);

//-----------------------------------------------------------------------------
// Functions for creating a listfile map

PLISTFILE_MAP ListFile_CreateMap(const TCHAR * szListFile);
const char * ListFile_FindName(PLISTFILE_MAP pListMap, ULONGLONG FileNameHash);
void ListFile_FreeMap(PLISTFILE_MAP pListMap);

#endif // __LISTFILE_H__
