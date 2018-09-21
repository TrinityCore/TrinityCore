/*****************************************************************************/
/* CascRootFile_SC1.cpp                   Copyright (c) Ladislav Zezula 2017 */
/*---------------------------------------------------------------------------*/
/* Support for loading Starcraft 1 ROOT file                                 */
/*---------------------------------------------------------------------------*/
/*   Date    Ver   Who  Comment                                              */
/* --------  ----  ---  -------                                              */
/* 28.10.15  1.00  Lad  The first version of CascRootFile_SC1.cpp            */
/*****************************************************************************/

#define __CASCLIB_SELF__
#include "CascLib.h"
#include "CascCommon.h"

//-----------------------------------------------------------------------------
// Structure definitions for Overwatch root file

typedef struct _CASC_FILE_ENTRY
{
    ENCODING_KEY EncodingKey;                       // Encoding key
    ULONGLONG FileNameHash;                         // File name hash
    DWORD dwFileName;                               // Offset of the file name in the name cache
} CASC_FILE_ENTRY, *PCASC_FILE_ENTRY;

struct TRootHandler_SC1 : public TRootHandler
{
    // Linear global list of file entries
    DYNAMIC_ARRAY FileTable;

    // Linear global list of names
    DYNAMIC_ARRAY FileNames;

    // Global map of FileName -> FileEntry
    PCASC_MAP pRootMap;
};

//-----------------------------------------------------------------------------
// Local functions

static int InsertFileEntry(
    TRootHandler_SC1 * pRootHandler,
    const char * szFileName,
    LPBYTE pbEncodingKey)
{
    PCASC_FILE_ENTRY pFileEntry;
    size_t nLength = strlen(szFileName);

    // Attempt to insert the file name to the global buffer
    szFileName = (char *)Array_Insert(&pRootHandler->FileNames, szFileName, nLength + 1);
    if(szFileName == NULL)
        return ERROR_NOT_ENOUGH_MEMORY;

    // Attempt to insert the entry to the array of file entries
    pFileEntry = (PCASC_FILE_ENTRY)Array_Insert(&pRootHandler->FileTable, NULL, 1);
    if(pFileEntry == NULL)
        return ERROR_NOT_ENOUGH_MEMORY;

    // Fill the file entry
    pFileEntry->EncodingKey  = *(PENCODING_KEY)pbEncodingKey;
    pFileEntry->FileNameHash = CalcFileNameHash(szFileName);
    pFileEntry->dwFileName   = (DWORD)Array_IndexOf(&pRootHandler->FileNames, szFileName);

    // Insert the file entry to the map
    assert(Map_FindObject(pRootHandler->pRootMap, &pFileEntry->FileNameHash, NULL) == NULL);
    Map_InsertObject(pRootHandler->pRootMap, pFileEntry, &pFileEntry->FileNameHash);
    return ERROR_SUCCESS;
}

//-----------------------------------------------------------------------------
// Implementation of Overwatch root file

static int SC1Handler_Insert(
    TRootHandler_SC1 * pRootHandler,
    const char * szFileName,
    LPBYTE pbEncodingKey)
{
    return InsertFileEntry(pRootHandler, szFileName, pbEncodingKey);
}

static LPBYTE SC1Handler_Search(TRootHandler_SC1 * pRootHandler, TCascSearch * pSearch, PDWORD /* PtrFileSize */, PDWORD /* PtrLocaleFlags */, PDWORD /* PtrFileDataId */)
{
    PCASC_FILE_ENTRY pFileEntry;

    // Are we still inside the root directory range?
    while(pSearch->IndexLevel1 < pRootHandler->FileTable.ItemCount)
    {
        // Retrieve the file item
        pFileEntry = (PCASC_FILE_ENTRY)Array_ItemAt(&pRootHandler->FileTable, pSearch->IndexLevel1);
        
        // Prepare the pointer to the next search
        pSearch->IndexLevel1++;
		
        char *filename = (char *)Array_ItemAt(&pRootHandler->FileNames, pFileEntry->dwFileName);
        if (CheckWildCard(filename, pSearch->szMask)) {
            strcpy(pSearch->szFileName, filename);
            return pFileEntry->EncodingKey.Value;
        }
    }

    // No more entries
    return NULL;
}

static void SC1Handler_EndSearch(TRootHandler_SC1 * /* pRootHandler */, TCascSearch * /* pSearch */)
{
    // Do nothing
}

static LPBYTE SC1Handler_GetKey(TRootHandler_SC1 * pRootHandler, const char * szFileName)
{
    ULONGLONG FileNameHash = CalcFileNameHash(szFileName);

    return (LPBYTE)Map_FindObject(pRootHandler->pRootMap, &FileNameHash, NULL);
}

static DWORD SC1Handler_GetFileId(TRootHandler_SC1 * /* pRootHandler */, const char * /* szFileName */)
{
  // Not implemented for Overwatch
  return 0;
}

static void SC1Handler_Close(TRootHandler_SC1 * pRootHandler)
{
    if(pRootHandler != NULL)
    {
        // Free the file map
        if(pRootHandler->pRootMap)
            Map_Free(pRootHandler->pRootMap);
        pRootHandler->pRootMap = NULL;

        // Free the array of the file names and file items
        Array_Free(&pRootHandler->FileTable);
        Array_Free(&pRootHandler->FileNames);

        // Free the root file itself
        CASC_FREE(pRootHandler);
    }
}

//-----------------------------------------------------------------------------
// Public functions

int RootHandler_CreateSC1(TCascStorage * hs, LPBYTE pbRootFile, DWORD cbRootFile)
{
    TRootHandler_SC1 * pRootHandler;
    ENCODING_KEY KeyBuffer;
    QUERY_KEY EncodingKey = {KeyBuffer.Value, MD5_HASH_SIZE};
    void * pTextFile;
    size_t nLength;
    char szOneLine[0x200];
    DWORD dwFileCountMax = (DWORD)hs->pEncodingMap->TableSize;
    int nError = ERROR_SUCCESS;

    // Allocate the root handler object
    hs->pRootHandler = pRootHandler = CASC_ALLOC(TRootHandler_SC1, 1);
    if(pRootHandler == NULL)
        return ERROR_NOT_ENOUGH_MEMORY;

    // Fill-in the handler functions
    memset(pRootHandler, 0, sizeof(TRootHandler_SC1));
    pRootHandler->Insert      = (ROOT_INSERT)SC1Handler_Insert;
    pRootHandler->Search      = (ROOT_SEARCH)SC1Handler_Search;
    pRootHandler->EndSearch   = (ROOT_ENDSEARCH)SC1Handler_EndSearch;
    pRootHandler->GetKey      = (ROOT_GETKEY)SC1Handler_GetKey;
    pRootHandler->Close       = (ROOT_CLOSE)SC1Handler_Close;
    pRootHandler->GetFileId   = (ROOT_GETFILEID)SC1Handler_GetFileId;

    // Fill-in the flags
    pRootHandler->dwRootFlags |= ROOT_FLAG_HAS_NAMES;

    // Allocate the linear array of file entries
    nError = Array_Create(&pRootHandler->FileTable, CASC_FILE_ENTRY, 0x10000);
    if(nError != ERROR_SUCCESS)
        return nError;

    // Allocate the buffer for the file names
    nError = Array_Create(&pRootHandler->FileNames, char, 0x10000);
    if(nError != ERROR_SUCCESS)
        return nError;

    // Create map of ROOT_ENTRY -> FileEntry
    pRootHandler->pRootMap = Map_Create(dwFileCountMax, sizeof(ULONGLONG), FIELD_OFFSET(CASC_FILE_ENTRY, FileNameHash));
    if(pRootHandler->pRootMap == NULL)
        return ERROR_NOT_ENOUGH_MEMORY;

    // Parse the ROOT file
    pTextFile = ListFile_FromBuffer(pbRootFile, cbRootFile);
    if(pTextFile != NULL)
    {
        // Parse the next lines
        while((nLength = ListFile_GetNextLine(pTextFile, szOneLine, _maxchars(szOneLine))) > 0)
        {
            LPSTR szEncodingKey;
            BYTE EncodingKey[MD5_HASH_SIZE];

            szEncodingKey = strchr(szOneLine, _T('|'));
            if(szEncodingKey != NULL)
            {
                // Split the name and encoding key
                *szEncodingKey++ = 0;

                // Insert the entry to the map
                ConvertStringToBinary(szEncodingKey, MD5_STRING_SIZE, EncodingKey);
                InsertFileEntry(pRootHandler, szOneLine, EncodingKey);
            }
        }

        // Free the listfile
        ListFile_Free(pTextFile);
    }

    // Succeeded
    return nError;
}
