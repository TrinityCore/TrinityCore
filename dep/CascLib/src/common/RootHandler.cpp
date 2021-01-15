/*****************************************************************************/
/* RootHandler.cpp                        Copyright (c) Ladislav Zezula 2015 */
/*---------------------------------------------------------------------------*/
/* Implementation of root handler                                            */
/*---------------------------------------------------------------------------*/
/*   Date    Ver   Who  Comment                                              */
/* --------  ----  ---  -------                                              */
/* 09.03.15  1.00  Lad  Created                                              */
/*****************************************************************************/

#define __CASCLIB_SELF__
#include "../CascLib.h"
#include "../CascCommon.h"

//-----------------------------------------------------------------------------
// Constructor and destructor - TFileTreeRoot

TFileTreeRoot::TFileTreeRoot(DWORD FileTreeFlags) : TRootHandler()
{
    // Initialize the file tree
    FileTree.Create(FileTreeFlags);
}

TFileTreeRoot::~TFileTreeRoot()
{
    // Free the file tree
    FileTree.Free();
    dwFeatures = 0;
}

//-----------------------------------------------------------------------------
// Virtual functions - TFileTreeRoot

int TFileTreeRoot::Insert(
    const char * szFileName,
    PCASC_CKEY_ENTRY pCKeyEntry)
{
    PCASC_FILE_NODE pFileNode;

    pFileNode = FileTree.InsertByName(pCKeyEntry, szFileName, FileTree.GetNextFileDataId());
    return (pFileNode != NULL) ? ERROR_SUCCESS : ERROR_CAN_NOT_COMPLETE;
}

PCASC_CKEY_ENTRY TFileTreeRoot::GetFile(TCascStorage * /* hs */, const char * szFileName)
{
    PCASC_FILE_NODE pFileNode;
    ULONGLONG FileNameHash = CalcFileNameHash(szFileName);
    
    pFileNode = FileTree.Find(FileNameHash);
    return (pFileNode != NULL) ? pFileNode->pCKeyEntry : NULL;
}

PCASC_CKEY_ENTRY TFileTreeRoot::GetFile(TCascStorage * /* hs */, DWORD FileDataId)
{
    PCASC_FILE_NODE pFileNode;

    pFileNode = FileTree.FindById(FileDataId);
    return (pFileNode != NULL) ? pFileNode->pCKeyEntry : NULL;
}

PCASC_CKEY_ENTRY TFileTreeRoot::Search(TCascSearch * pSearch, PCASC_FIND_DATA pFindData)
{
    PCASC_FILE_NODE pFileNode;
    size_t nMaxFileIndex = FileTree.GetMaxFileIndex();

    // Are we still inside the root directory range?
    while(pSearch->nFileIndex < nMaxFileIndex)
    {
        //BREAKIF(pSearch->nFileIndex >= 2823765);

        // Retrieve the file item
        pFileNode = FileTree.PathAt(pFindData->szFileName, MAX_PATH, pSearch->nFileIndex++);
        if(pFileNode != NULL)
        {
            // Ignore folders and mount points
            if(!(pFileNode->Flags & CFN_FLAG_FOLDER))
            {
                // Check the wildcard
                if (CascCheckWildCard(pFindData->szFileName, pSearch->szMask))
                {
                    // Retrieve the extra values (FileDataId, file size and locale flags)
                    FileTree.GetExtras(pFileNode, &pFindData->dwFileDataId, &pFindData->dwLocaleFlags, &pFindData->dwContentFlags);

                    // Return the found CKey entry
                    return pFileNode->pCKeyEntry;
                }
            }
        }
    }

    // No more entries
    return NULL;
}

bool TFileTreeRoot::GetInfo(PCASC_CKEY_ENTRY pCKeyEntry, PCASC_FILE_FULL_INFO pFileInfo)
{
    PCASC_FILE_NODE pFileNode;

    // Can't do much if the root key is NULL
    if(pCKeyEntry != NULL)
    {
        pFileNode = FileTree.Find(pCKeyEntry);
        if(pFileNode != NULL)
        {
            FileTree.GetExtras(pFileNode, &pFileInfo->FileDataId, &pFileInfo->LocaleFlags, &pFileInfo->ContentFlags);
            pFileInfo->FileNameHash = pFileNode->FileNameHash;
            return true;
        }
    }

    return false;
}

