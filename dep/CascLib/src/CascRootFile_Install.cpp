/*****************************************************************************/
/* CascRootFile_Install.cpp               Copyright (c) Ladislav Zezula 2018 */
/*---------------------------------------------------------------------------*/
/* Support for ROOT handler based on INSTALL manifest                        */
/*---------------------------------------------------------------------------*/
/*   Date    Ver   Who  Comment                                              */
/* --------  ----  ---  -------                                              */
/* 21.05.19  1.00  Lad  The first version of CascRootFile_Install.cpp        */
/*****************************************************************************/

#define __CASCLIB_SELF__
#include "CascLib.h"
#include "CascCommon.h"

//-----------------------------------------------------------------------------
// Handler definitions for Starcraft I root file

struct TRootHandler_Install : public TFileTreeRoot
{
    public:

    TRootHandler_Install() : TFileTreeRoot(0)
    {
        // We have file names and return CKey as result of search
        dwFeatures |= (CASC_FEATURE_FILE_NAMES | CASC_FEATURE_ROOT_CKEY);
    }

    static int CaptureInstallHeader(CASC_INSTALL_HEADER & InHeader, LPBYTE pbFileData, size_t cbFileData)
    {
        PFILE_INSTALL_HEADER pFileHeader = (PFILE_INSTALL_HEADER)pbFileData;

        // Check the signature ('DL') and version
        if (cbFileData < sizeof(FILE_INSTALL_HEADER) || pFileHeader->Magic != FILE_MAGIC_INSTALL || pFileHeader->Version != 1)
            return ERROR_BAD_FORMAT;

        // Note that we don't support CKey sizes greater than 0x10 in the INSTALL file
        if (pFileHeader->EKeyLength > MD5_HASH_SIZE)
            return ERROR_BAD_FORMAT;

        // Capture the header version 1
        memset(&InHeader, 0, sizeof(CASC_INSTALL_HEADER));
        InHeader.Magic = pFileHeader->Magic;
        InHeader.Version = pFileHeader->Version;
        InHeader.EKeyLength = pFileHeader->EKeyLength;
        InHeader.TagCount = ConvertBytesToInteger_2(pFileHeader->TagCount);
        InHeader.EntryCount = ConvertBytesToInteger_4(pFileHeader->EntryCount);
        InHeader.HeaderLength = sizeof(FILE_INSTALL_HEADER);
        return ERROR_SUCCESS;
    }

    int Load(TCascStorage * hs, CASC_INSTALL_HEADER InHeader, LPBYTE pbInstallFile, LPBYTE pbInstallEnd)
    {
        PCASC_CKEY_ENTRY pCKeyEntry;
        const char * szString;
        size_t nBitmapLength;
        size_t nFileCount = InHeader.EntryCount;

        // Skip the header
        pbInstallFile += InHeader.HeaderLength;

        // Skip the tags
        for (DWORD i = 0; i < InHeader.TagCount; i++)
        {
            szString = (const char *)pbInstallFile;
            nBitmapLength = GetTagBitmapLength(pbInstallFile, pbInstallEnd, InHeader.EntryCount);
            pbInstallFile = pbInstallFile + strlen(szString) + 1 + sizeof(USHORT) + nBitmapLength;
        }

        // Load the names and insert them to the root handler
        while(nFileCount > 0 && pbInstallFile < pbInstallEnd)
        {
            // File Name and CKey
            szString = (const char *)pbInstallFile;
            pbInstallFile += strlen(szString) + 1;

            // Verify whether it is a known entry
            pCKeyEntry = FindCKeyEntry_CKey(hs, pbInstallFile);
            pbInstallFile += MD5_HASH_SIZE + sizeof(DWORD);

            // Insert the FileName+CKey to the file tree
            if (pCKeyEntry != NULL)
                FileTree.InsertByName(pCKeyEntry, szString);
            nFileCount--;
        }

        return ERROR_SUCCESS;
    }
};

//-----------------------------------------------------------------------------
// Public functions

//
// Starcraft ROOT file is a text file with the following format:
// HD2/portraits/NBluCrit/NLCFID01.webm|c2795b120592355d45eba9cdc37f691e
// locales/enUS/Assets/campaign/EXPZerg/Zerg08/staredit/wav/zovtra01.ogg|316b0274bf2dabaa8db60c3ff1270c85
// locales/zhCN/Assets/sound/terran/ghost/tghdth01.wav|6637ed776bd22089e083b8b0b2c0374c
//

int RootHandler_CreateInstall(TCascStorage * hs, LPBYTE pbInstallFile, DWORD cbInstallFile)
{
    CASC_INSTALL_HEADER InHeader;
    TRootHandler_Install * pRootHandler = NULL;
    int nError = ERROR_BAD_FORMAT;

    // Capture the header of the DOWNLOAD file
    nError = TRootHandler_Install::CaptureInstallHeader(InHeader, pbInstallFile, cbInstallFile);
    if (nError == ERROR_SUCCESS)
    {
        // Allocate the root handler object
        pRootHandler = new TRootHandler_Install();
        if (pRootHandler != NULL)
        {
            // Parse the entire install manifest
            nError = pRootHandler->Load(hs, InHeader, pbInstallFile, pbInstallFile + cbInstallFile);
            hs->pRootHandler = pRootHandler;
        }
    }

    return nError;
}
