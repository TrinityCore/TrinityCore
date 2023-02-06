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

// If the callback returns false, the directory enumeration stops
typedef bool (*DIRECTORY_CALLBACK)(LPCTSTR szPathName, void * pvContext);

bool DirectoryExists(
    LPCTSTR szDirectory
    );

bool MakeDirectory(
    LPCTSTR szDirectory
    );

DWORD ScanDirectory(
    LPCTSTR szDirectory,
    DIRECTORY_CALLBACK PfnFolderCallback,       // Can be NULL if the caller doesn't care about folders
    DIRECTORY_CALLBACK PfnFileCallback,         // Can be NULL if the caller doesn't care about files
    void * pvContext
    );

#endif // __DIRECTORY_H__
