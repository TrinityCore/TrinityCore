/*****************************************************************************/
/* apm.cpp                                Copyright (c) Ladislav Zezula 2023 */
/*---------------------------------------------------------------------------*/
/* Support for Application Package Manifest (.apm)                           */
/* Know-how from https://github.com/overtools/TACTLib                        */
/*---------------------------------------------------------------------------*/
/*   Date    Ver   Who  Comment                                              */
/* --------  ----  ---  -------                                              */
/* 02.08.23  1.00  Lad  Created                                              */
/*****************************************************************************/

#define __CASCLIB_SELF__
#include "../CascLib.h"
#include "../CascCommon.h"

#include "overwatch.h"

//-----------------------------------------------------------------------------
// Local functions

template <typename APM_ENTRY>
static bool IsContinuousArray(APM_ENTRY * pEntry, size_t nCount)
{
    // Must be at last 5 entries
    if(nCount-- >= 5)
    {
        for(size_t i = 0; i < nCount; i++, pEntry++)
        {
            // n+1-th index must be greater than n-th index
            if(pEntry[1].Index > pEntry[0].Index + 10)
            {
                return false;
            }
        }
        return true;
    }
    return false;
}

static LPBYTE CaptureApmHeader(TCascStorage * hs, LPBYTE pbDataPtr, LPBYTE pbDataEnd, CASC_APM_HEADER & ApmHeader)
{
    // Build 47161+
    PCASC_APM_HEADER_V2 pHeader_V3 = NULL;
    if(CaptureStructure<CASC_APM_HEADER_V2>(pbDataPtr, pbDataEnd, &pHeader_V3) != NULL)
    {
        if(pHeader_V3->BuildNumber == hs->dwBuildNumber &&
           pHeader_V3->ZeroValue1 == 0 &&
           pHeader_V3->ZeroValue2 == 0 &&
           pHeader_V3->ZeroValue3 == 0)
        {
            ApmHeader.BuildNumber  = pHeader_V3->BuildNumber;
            ApmHeader.PackageCount = pHeader_V3->PackageCount;
            ApmHeader.PackageCount = pHeader_V3->PackageCount;
            ApmHeader.EntryCount   = pHeader_V3->EntryCount;
            ApmHeader.HeaderMagic  = pHeader_V3->HeaderMagic;
            return pbDataPtr + sizeof(CASC_APM_HEADER_V2);
        }
    }

    // Build 24919
    PCASC_APM_HEADER_V1 pHeader_V1 = NULL;
    if(CaptureStructure<CASC_APM_HEADER_V1>(pbDataPtr, pbDataEnd, &pHeader_V1) != NULL)
    {
        if((pHeader_V1->HeaderMagic & 0x00FFFFFF) == CASC_APM_HEADER_MAGIC)
        {
            ApmHeader.BuildNumber  = pHeader_V1->BuildNumber;
            ApmHeader.PackageCount = pHeader_V1->PackageCount;
            ApmHeader.PackageCount = pHeader_V1->PackageCount;
            ApmHeader.EntryCount   = pHeader_V1->EntryCount;
            ApmHeader.HeaderMagic  = pHeader_V1->HeaderMagic;
            return pbDataPtr + sizeof(CASC_APM_HEADER_V1);
        }
    }
    return NULL;
}

static LPBYTE SkipApmEntries(TCascStorage * hs, LPBYTE pbDataPtr, LPBYTE pbDataEnd, size_t nCount)
{
    PCASC_APM_ENTRY_V2 pApmEntries_V2 = NULL;
    PCASC_APM_ENTRY_V1 pApmEntries_V1 = NULL;
    LPBYTE pbSavePtr = pbDataPtr;

    // Keep compiler happy
    CASCLIB_UNUSED(hs);

    // Try APM entries v2 (example: Overwatch build 47161)
    if((pbDataPtr = CaptureArray(pbSavePtr, pbDataEnd, &pApmEntries_V2, nCount)) != NULL)
    {
        if(IsContinuousArray(pApmEntries_V2, nCount))
        {
            return pbDataPtr;
        }
    }

    // Try APM entries v1 (example: Overwatch build 24919)
    if((pbDataPtr = CaptureArray(pbSavePtr, pbDataEnd, &pApmEntries_V1, nCount)) != NULL)
    {
        if(IsContinuousArray(pApmEntries_V1, nCount))
        {
            return pbDataPtr;
        }
    }
    return NULL;
}

//-----------------------------------------------------------------------------
// Public functions

DWORD LoadApplicationPackageManifestFile(TCascStorage * hs, CASC_FILE_TREE & FileTree, PCASC_CKEY_ENTRY pCKeyEntry, const char * szApmFileName)
{
    CASC_BLOB ApmFile;
    const char * szApmPlainName = GetPlainFileName(szApmFileName);
    DWORD dwErrCode;

    // Load the entire internal file to memory
    if((dwErrCode = LoadInternalFileToMemory(hs, pCKeyEntry, ApmFile)) == ERROR_SUCCESS)
    {
        PCASC_APM_PACKAGE_ENTRY_V1 pEntries;
        CASC_APM_HEADER ApmHeader = {0};
        LPBYTE pbDataEnd = ApmFile.pbData + ApmFile.cbData;
        LPBYTE pbDataPtr = ApmFile.pbData;
        size_t nPlainName;
        char szFileName[MAX_PATH];

        // Capture the header
        if((pbDataPtr = CaptureApmHeader(hs, pbDataPtr, pbDataEnd, ApmHeader)) == NULL)
            return ERROR_BAD_FORMAT;

        // Skip the array of APM_ENTRYs. We use heuristics to determine which APM entry is there
        if((pbDataPtr = SkipApmEntries(hs, pbDataPtr, pbDataEnd, ApmHeader.EntryCount)) == NULL)
            return ERROR_BAD_FORMAT;

        // Get the array of APM package entries. Only take those with CKey
        if((pbDataPtr = CaptureArray(pbDataPtr, pbDataEnd, &pEntries, ApmHeader.PackageCount)) != NULL)
        {
            // The array must fill the whole file without any leftover
            if(pbDataPtr == pbDataEnd && ApmHeader.PackageCount > 1)
            {
                // Check the first two entries - if their CKey is OK, then we consider them valid
                if(FindCKeyEntry_CKey(hs, pEntries[0].CKey) != NULL && FindCKeyEntry_CKey(hs, pEntries[1].CKey) != NULL)
                {
                    // Create the name template of the assets
                    nPlainName = BuildAssetFileNameTemplate(szFileName,
                                                            _countof(szFileName),
                                                            "AppPackageManifests",
                                                            szApmPlainName);

                    dwErrCode = InsertAssetFiles(hs, FileTree, szFileName, nPlainName, pEntries, ApmHeader.PackageCount);
                }
            }
        }
    }
    return dwErrCode;
}
