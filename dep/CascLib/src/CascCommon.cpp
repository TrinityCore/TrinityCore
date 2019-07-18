/*****************************************************************************/
/* CascCommon.cpp                         Copyright (c) Ladislav Zezula 2014 */
/*---------------------------------------------------------------------------*/
/* Common functions for CascLib                                              */
/*---------------------------------------------------------------------------*/
/*   Date    Ver   Who  Comment                                              */
/* --------  ----  ---  -------                                              */
/* 29.04.14  1.00  Lad  The first version of CascCommon.cpp                  */
/*****************************************************************************/

#define __CASCLIB_SELF__
#include "CascLib.h"
#include "CascCommon.h"

//-----------------------------------------------------------------------------
// Functions

LPBYTE LoadInternalFileToMemory(TCascStorage * hs, PCASC_CKEY_ENTRY pCKeyEntry, DWORD * pcbFileData)
{
    LPBYTE pbFileData = NULL;
    HANDLE hFile = NULL;
    DWORD cbFileData = pcbFileData[0];
    DWORD dwBytesRead = 0;
    int nError = ERROR_SUCCESS;

    // Open the file either by CKey or by EKey
    if(OpenFileByCKeyEntry(hs, pCKeyEntry, CASC_STRICT_DATA_CHECK, &hFile))
    {
        // Retrieve the size of the file. Note that the caller might specify
        // the real size of the file, in case the file size is not retrievable
        // or if the size is wrong. Example: ENCODING file has size specified in BUILD
        if(cbFileData == 0 || cbFileData == CASC_INVALID_SIZE)
        {
            cbFileData = CascGetFileSize(hFile, NULL);
            if(cbFileData == 0 || cbFileData == CASC_INVALID_SIZE)
                nError = ERROR_FILE_CORRUPT;
        }

        // Retrieve the size of the ENCODING file
        if(nError == ERROR_SUCCESS)
        {
            // Allocate space for the ENCODING file
            pbFileData = CASC_ALLOC(BYTE, cbFileData);
            if(pbFileData != NULL)
            {
                // Read the entire file to memory
                CascReadFile(hFile, pbFileData, cbFileData, &dwBytesRead);
                if(dwBytesRead != cbFileData)
                {
                    nError = ERROR_FILE_CORRUPT;
                }
            }
            else
            {
                nError = ERROR_NOT_ENOUGH_MEMORY;
            }
        }

        // Close the file
        CascCloseFile(hFile);
    }
    else
    {
        nError = GetLastError();
    }

    // Handle errors
    if(nError != ERROR_SUCCESS)
    {
        // Free the file data
        CASC_FREE(pbFileData);
        cbFileData = 0;

        // Set the last error
        SetLastError(nError);
    }

    // Give the loaded file length
    if(pcbFileData != NULL)
        *pcbFileData = cbFileData;
    return pbFileData;
}

LPBYTE LoadFileToMemory(const TCHAR * szFileName, DWORD * pcbFileData)
{
    TFileStream * pStream;
    ULONGLONG FileSize = 0;
    LPBYTE pbFileData = NULL;
    DWORD cbFileData = 0;

    // Open the stream for read-only access and read the file
    // Note that this fails when the game is running (sharing violation).
    pStream = FileStream_OpenFile(szFileName, STREAM_FLAG_READ_ONLY | STREAM_PROVIDER_FLAT | BASE_PROVIDER_FILE);
    if(pStream != NULL)
    {
        // Retrieve the file size
        FileStream_GetSize(pStream, &FileSize);
        cbFileData = (DWORD)FileSize;

        // Do not load zero files or too larget files
        if(0 < FileSize && FileSize <= 0x2000000)
        {
            // Allocate file data buffer. Make it 1 byte longer
            // so string functions can put '\0' there
            pbFileData = CASC_ALLOC(BYTE, cbFileData + 1);
            if(pbFileData != NULL)
            {
                if(!FileStream_Read(pStream, NULL, pbFileData, cbFileData))
                {
                    CASC_FREE(pbFileData);
                    cbFileData = 0;
                }
            }
            else
            {
                SetLastError(ERROR_NOT_ENOUGH_MEMORY);
                cbFileData = 0;
            }
        }
        else
        {
            SetLastError(ERROR_BAD_FORMAT);
            cbFileData = 0;
            assert(false);
        }

        // Close the file stream
        FileStream_Close(pStream);
    }

    // Give out values
    if(pcbFileData != NULL)
        pcbFileData[0] = cbFileData;
    return pbFileData;
}

void FreeCascBlob(PQUERY_KEY pBlob)
{
    if(pBlob != NULL)
    {
        CASC_FREE(pBlob->pbData);
        pBlob->cbData = 0;
    }
}
