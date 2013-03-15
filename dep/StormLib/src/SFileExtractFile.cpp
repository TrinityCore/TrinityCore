/*****************************************************************************/
/* SFileExtractFile.cpp                   Copyright (c) Ladislav Zezula 2003 */
/*---------------------------------------------------------------------------*/
/* Simple extracting utility                                                 */
/*---------------------------------------------------------------------------*/
/*   Date    Ver   Who  Comment                                              */
/* --------  ----  ---  -------                                              */
/* 20.06.03  1.00  Lad  The first version of SFileExtractFile.cpp            */
/*****************************************************************************/

#define __STORMLIB_SELF__
#include "StormLib.h"
#include "StormCommon.h"

bool WINAPI SFileExtractFile(HANDLE hMpq, const char * szToExtract, const TCHAR * szExtracted, DWORD dwSearchScope)
{
    TFileStream * pLocalFile = NULL;
    HANDLE hMpqFile = NULL;
    int nError = ERROR_SUCCESS;

    // Open the MPQ file
    if(nError == ERROR_SUCCESS)
    {
        if(!SFileOpenFileEx(hMpq, szToExtract, dwSearchScope, &hMpqFile))
            nError = GetLastError();
    }

    // Create the local file
    if(nError == ERROR_SUCCESS)
    {
        pLocalFile = FileStream_CreateFile(szExtracted, STREAM_PROVIDER_LINEAR | BASE_PROVIDER_FILE);
        if(pLocalFile == NULL)
            nError = GetLastError();
    }

    // Copy the file's content
    if(nError == ERROR_SUCCESS)
    {
        char  szBuffer[0x1000];
        DWORD dwTransferred;

        for(;;)
        {
            // dwTransferred is only set to nonzero if something has been read.
            // nError can be ERROR_SUCCESS or ERROR_HANDLE_EOF
            if(!SFileReadFile(hMpqFile, szBuffer, sizeof(szBuffer), &dwTransferred, NULL))
                nError = GetLastError();
            if(nError == ERROR_HANDLE_EOF)
                nError = ERROR_SUCCESS;
            if(dwTransferred == 0)
                break;

            // If something has been actually read, write it
            if(!FileStream_Write(pLocalFile, NULL, szBuffer, dwTransferred))
                nError = GetLastError();
        }
    }

    // Close the files
    if(hMpqFile != NULL)
        SFileCloseFile(hMpqFile);
    if(pLocalFile != NULL)
        FileStream_Close(pLocalFile);
    if(nError != ERROR_SUCCESS)
        SetLastError(nError);
    return (nError == ERROR_SUCCESS);
}
