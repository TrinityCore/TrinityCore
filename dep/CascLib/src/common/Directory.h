/*****************************************************************************/
/* Directory.h                            Copyright (c) Ladislav Zezula 2015 */
/*---------------------------------------------------------------------------*/
/* Directory functions for CascLib                                           */
/*---------------------------------------------------------------------------*/
/*   Date    Ver   Who  Comment                                              */
/* --------  ----  ---  -------                                              */
/* 30.10.15  1.00  Lad  The first version of Directory.h                     */
/*****************************************************************************/

#ifndef __DIRECTORY_H__
#define __DIRECTORY_H__

//-----------------------------------------------------------------------------
// Scanning a directory

typedef bool (*INDEX_FILE_FOUND)(const TCHAR * szFileName, PDWORD IndexArray, PDWORD OldIndexArray, void * pvContext);

bool DirectoryExists(const TCHAR * szDirectory);

bool MakeDirectory(const TCHAR * szDirectory);

int ScanIndexDirectory(
    const TCHAR * szIndexPath,
    INDEX_FILE_FOUND pfnOnFileFound,
    PDWORD IndexArray,
    PDWORD OldIndexArray,
    void * pvContext
    );

#endif // __DIRECTORY_H__
