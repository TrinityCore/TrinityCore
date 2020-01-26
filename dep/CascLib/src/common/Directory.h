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

bool DirectoryExists(LPCTSTR szDirectory);

bool MakeDirectory(LPCTSTR szDirectory);

int ScanIndexDirectory(
    LPCTSTR szIndexPath,
    INDEX_FILE_FOUND pfnOnFileFound,
    void * pvContext
    );

#endif // __DIRECTORY_H__
