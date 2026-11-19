/*****************************************************************************/
/* cmf.cpp                                Copyright (c) Ladislav Zezula 2023 */
/*---------------------------------------------------------------------------*/
/* Support for Content Manifest Files (.cmf)                                 */
/* Know-how from https://github.com/overtools/TACTLib                        */
/*---------------------------------------------------------------------------*/
/*   Date    Ver   Who  Comment                                              */
/* --------  ----  ---  -------                                              */
/* 29.07.23  1.00  Lad  Created                                              */
/*****************************************************************************/

#define __CASCLIB_SELF__
#include "../CascLib.h"
#include "../CascCommon.h"

#include "aes.h"
#include "overwatch.h"

//-----------------------------------------------------------------------------
// Encryption key providers for CMF files. These are taken from TACTLib
// with the kind permission of the TACTLib authors
// (https://github.com/overtools/TACTLib)

// Key and IV provider functions
typedef LPBYTE(*GET_KEY)(const CASC_CMF_HEADER & Header, LPBYTE pbKey, int nLength);
typedef LPBYTE(*GET_IV)(const CASC_CMF_HEADER & Header, LPBYTE nameSha1, LPBYTE pbKey, int nLength);

// Structure for the single provider
typedef struct _CASC_CMF_KEY_PROVIDER
{
    DWORD   dwBuildNumber;
    GET_KEY PfnGetKey;
    GET_IV  PfnGetIV;
} CASC_CMF_KEY_PROVIDER;
typedef const CASC_CMF_KEY_PROVIDER *PCASC_CMF_KEY_PROVIDER;

// Needed by various providers in the cmf-key.cpp file
struct TMath
{
    template <typename TYPE>
    TYPE Max(TYPE value1, TYPE value2)
    {
        return (value1 > value2) ? value1 : value2;
    }
    DWORD dwDummy;
} Math;

// Needed by various providers in the cmf-key.cpp file
static uint Constrain(LONGLONG value)
{
    return (uint)(value % 0xFFFFFFFFULL);
}

// Needed by various providers in the cmf-key.cpp file
static int SignedMod(LONGLONG p1, LONGLONG p2)
{
    int a = (int)p1;
    int b = (int)p2;
    return (a % b) < 0 ? (a % b + b) : (a % b);
}

// Include the CMF key provider functions and the table of providers
// This file is created by the "cmf-update.py" script, DO NOT EDIT.
#include "cmf-key.cpp"

//-----------------------------------------------------------------------------
// Local functions

static PCASC_CMF_KEY_PROVIDER FindCmfKeyProvider(DWORD dwBuildNumber)
{
    PCASC_CMF_KEY_PROVIDER pStartEntry = CmfKeyProviders;
    PCASC_CMF_KEY_PROVIDER pMidleEntry = NULL;
    PCASC_CMF_KEY_PROVIDER pFinalEntry = &CmfKeyProviders[_countof(CmfKeyProviders)];

    // Perform binary search on the table
    while(pStartEntry < pFinalEntry)
    {
        // Calculate the middle of the interval
        pMidleEntry = pStartEntry + ((pFinalEntry - pStartEntry) / 2);

        // Did we find it?
        if(dwBuildNumber == pMidleEntry->dwBuildNumber)
            return pMidleEntry;

        // Move the interval to the left or right
        if(dwBuildNumber > pMidleEntry->dwBuildNumber)
            pStartEntry = pMidleEntry + 1;
        else
            pFinalEntry = pMidleEntry;
    }
/*
    for(size_t i = 0; i < _countof(CmfKeyProviders); i++)
    {
        if(CmfKeyProviders[i].dwBuildNumber == dwBuildNumber)
        {
            return &CmfKeyProviders[i];
        }
    }
*/
    return NULL;
}

static DWORD DecryptCmfStream(const CASC_CMF_HEADER & Header, const char * szPlainName, LPBYTE pbDataPtr, LPBYTE pbDataEnd)
{
    PCASC_CMF_KEY_PROVIDER pKeyProvider;
    AES_KEY AesKey;
    BYTE RawKey[CASC_AES_KEY_LENGTH];
    BYTE RawIV[CASC_AES_IV_LENGTH];
    BYTE nameDigest[SHA1_HASH_SIZE];

    // Find the provider for that Overwatch build
    if((pKeyProvider = FindCmfKeyProvider(Header.m_buildVersion)) == NULL)
        return ERROR_FILE_ENCRYPTED;

    // Create SHA1 from the file name
    CascHash_SHA1(szPlainName, strlen(szPlainName), nameDigest);

    // Retrieve key and IV
    pKeyProvider->PfnGetKey(Header, RawKey, sizeof(RawKey));
    pKeyProvider->PfnGetIV(Header, nameDigest, RawIV, sizeof(RawIV));

    // Decrypt the stream using AES
    AES_set_decrypt_key(RawKey, 256, &AesKey);
    AES_cbc_decrypt(pbDataPtr, pbDataPtr, (pbDataEnd - pbDataPtr), &AesKey, RawIV);
    return ERROR_SUCCESS;
}

//-----------------------------------------------------------------------------
// Public functions

DWORD LoadContentManifestFile(TCascStorage * hs, CASC_FILE_TREE & FileTree, PCASC_CKEY_ENTRY pCKeyEntry, const char * szCmfFileName)
{
    CASC_BLOB CmfFile;
    const char * szCmfPlainName = GetPlainFileName(szCmfFileName);
    DWORD dwErrCode;

    // Load the entire internal file to memory
    if((dwErrCode = LoadInternalFileToMemory(hs, pCKeyEntry, CmfFile)) == ERROR_SUCCESS)
    {
        PCASC_APM_ENTRY_V2 pApmEntries = NULL;
        CASC_CMF_HEADER CmfHeader = {0};
        LPBYTE pbDataEnd = CmfFile.pbData + CmfFile.cbData;
        LPBYTE pbDataPtr = CmfFile.pbData;
        size_t nPlainName;
        DWORD dwBuildVersion;
        char szFileName[MAX_PATH];

        // Get the build version
        if((pbDataPtr = CaptureInteger32(pbDataPtr, pbDataEnd, &dwBuildVersion)) == NULL)
            return ERROR_BAD_FORMAT;
        pbDataPtr = CmfFile.pbData;

        // Parse headers of various versions
        if(dwBuildVersion > CASC_OVERWATCH_VERSION_148_PTR)
        {
            CASC_CMF_HEADER_148 * pHeader148;

            if((pbDataPtr = CaptureStructure(pbDataPtr, pbDataEnd, &pHeader148)) == NULL)
                return ERROR_BAD_FORMAT;
            CmfHeader = *pHeader148;
        }
        else if(dwBuildVersion > CASC_OVERWATCH_VERSION_122_PTR)
        {
            CASC_CMF_HEADER_122 * pHeader122;

            if((pbDataPtr = CaptureStructure(pbDataPtr, pbDataEnd, &pHeader122)) == NULL)
                return ERROR_BAD_FORMAT;
            CmfHeader = *pHeader122;
        }
        else
        {
            CASC_CMF_HEADER_100 * pHeader100;

            if((pbDataPtr = CaptureStructure(pbDataPtr, pbDataEnd, &pHeader100)) == NULL)
                return ERROR_BAD_FORMAT;
            CmfHeader = *pHeader100;
        }

        // Decrypt the stream, if needed
        if(CmfHeader.IsEncrypted())
        {
            if((dwErrCode = DecryptCmfStream(CmfHeader, szCmfPlainName, pbDataPtr, pbDataEnd)) != ERROR_SUCCESS)
            {
                return dwErrCode;
            }
        }

        // Skip APM entries. We don't need them for anything, really
        if((pbDataPtr = CaptureArray(pbDataPtr, pbDataEnd, &pApmEntries, CmfHeader.m_entryCount)) == NULL)
        {
            return ERROR_BAD_FORMAT;
        }

        // Create the name template of the assets
        nPlainName = BuildAssetFileNameTemplate(szFileName,
                                                _countof(szFileName),
                                                "ContentManifestFiles",
                                                szCmfPlainName);

        // Load the hash list This is the list of Asset ID -> CKey
        if(CmfHeader.m_buildVersion >= 57230)
        {
            PCASC_CMF_HASH_ENTRY_135 pHashList;

            if((pbDataPtr = CaptureArray(pbDataPtr, pbDataEnd, &pHashList, CmfHeader.m_dataCount)) == NULL)
                return ERROR_BAD_FORMAT;

            dwErrCode = InsertAssetFiles(hs, FileTree, szFileName, nPlainName, pHashList, CmfHeader.m_dataCount);
        }
        else
        {
            PCASC_CMF_HASH_ENTRY_100 pHashList;

            if((pbDataPtr = CaptureArray(pbDataPtr, pbDataEnd, &pHashList, CmfHeader.m_dataCount)) == NULL)
                return ERROR_BAD_FORMAT;

            dwErrCode = InsertAssetFiles(hs, FileTree, szFileName, nPlainName, pHashList, CmfHeader.m_dataCount);
        }
    }
    return dwErrCode;
}
