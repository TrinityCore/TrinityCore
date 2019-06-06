/*****************************************************************************/
/* RootHandler.h                          Copyright (c) Ladislav Zezula 2015 */
/*---------------------------------------------------------------------------*/
/* Interface for root handlers                                               */
/*---------------------------------------------------------------------------*/
/*   Date    Ver   Who  Comment                                              */
/* --------  ----  ---  -------                                              */
/* 09.03.15  1.00  Lad  Created                                              */
/*****************************************************************************/

#ifndef __ROOT_HANDLER_H__
#define __ROOT_HANDLER_H__

//-----------------------------------------------------------------------------
// Defines

#define CASC_MNDX_ROOT_SIGNATURE        0x58444E4D  // 'MNDX'
#define CASC_TVFS_ROOT_SIGNATURE        0x53465654  // 'TVFS'
#define CASC_DIABLO3_ROOT_SIGNATURE     0x8007D0C4
#define CASC_WOW82_ROOT_SIGNATURE       0x4D465354  // 'TSFM', WoW since 8.2

#define DUMP_LEVEL_ROOT_FILE                     1  // Dump root file
#define DUMP_LEVEL_ENCODING_FILE                 2  // Dump root file + encoding file
#define DUMP_LEVEL_INDEX_ENTRIES                 3  // Dump root file + encoding file + index entries

//-----------------------------------------------------------------------------
// Class for generic root handler

struct TRootHandler
{
    public:

    TRootHandler()
    {
        dwFeatures = 0;
    }

    virtual ~TRootHandler()
    {}

    // Inserts new file name to the root handler
    // szFileName - Pointer to the file name
    // pCKeyEntry - Pointer to the CASC_CKEY_ENTRY for the file
    virtual int Insert(const char * /* szFileName */, PCASC_CKEY_ENTRY /* pCKeyEntry */)
    {
        return ERROR_NOT_SUPPORTED;
    }

    // Searches the file by file name
    // hs         - Pointer to the storage structure
    // szFileName - Pointer to the file name
    virtual PCASC_CKEY_ENTRY GetFile(struct TCascStorage * /* hs */, const char * /* szFileName */)
    {
        return NULL;
    }

    // Searches the file by file data id
    // hs         - Pointer to the storage structure
    // FileDataId - File data id
    virtual PCASC_CKEY_ENTRY GetFile(struct TCascStorage * /* hs */, DWORD /* FileDataId */)
    {
        return NULL;
    }

    // Performs find-next-file operation
    // pSearch   - Pointer to the initialized search structure
    // pFindData - Pointer to output structure that will contain the information
    virtual PCASC_CKEY_ENTRY Search(struct TCascSearch * /* pSearch */, struct _CASC_FIND_DATA * /* pFindData */)
    {
        return NULL;
    }

    // Returns advanced info from the root file entry.
    // pCKeyEntry - CKey/EKey, depending on which type the root handler provides
    // pFileInfo - Pointer to CASC_FILE_FULL_INFO structure
    virtual bool GetInfo(PCASC_CKEY_ENTRY /* pCKeyEntry */, struct _CASC_FILE_FULL_INFO * /* pFileInfo */)
    {
        return false;
    }

    DWORD GetFeatures()
    {
        return dwFeatures;
    }

    protected:

    DWORD dwFeatures;                               // CASC features. See CASC_FEATURE_XXX
};

//-----------------------------------------------------------------------------
// Class for root handler that has basic mapping of FileName -> CASC_FILE_NODE

struct TFileTreeRoot : public TRootHandler
{
    TFileTreeRoot(DWORD FileTreeFlags);
    virtual ~TFileTreeRoot();

    int Insert(const char * szFileName, PCASC_CKEY_ENTRY pCKeyEntry);

    PCASC_CKEY_ENTRY GetFile(struct TCascStorage * hs, const char * szFileName);
    PCASC_CKEY_ENTRY GetFile(struct TCascStorage * hs, DWORD FileDataId);
    PCASC_CKEY_ENTRY Search(struct TCascSearch * pSearch, struct _CASC_FIND_DATA * pFindData);
    bool GetInfo(PCASC_CKEY_ENTRY pCKeyEntry, struct _CASC_FILE_FULL_INFO * pFileInfo);

    protected:

    CASC_FILE_TREE FileTree;
};

#endif  // __ROOT_HANDLER_H__
