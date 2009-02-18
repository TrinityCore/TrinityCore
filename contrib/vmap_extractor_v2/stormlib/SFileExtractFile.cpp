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
#include "SCommon.h"

// TODO: Test for archives > 4GB
BOOL WINAPI SFileExtractFile(HANDLE hMpq, const char * szToExtract, const char * szExtracted)
{
    HANDLE hLocalFile = INVALID_HANDLE_VALUE;
    HANDLE hMpqFile = NULL;
    int nError = ERROR_SUCCESS;

    // Create the local file
    if(nError == ERROR_SUCCESS)
    {
        hLocalFile = CreateFile(szExtracted, GENERIC_WRITE, FILE_SHARE_READ, NULL, CREATE_ALWAYS, 0, NULL);
        if(hLocalFile == INVALID_HANDLE_VALUE)
            nError = GetLastError();
    }

    // Open the MPQ file
    if(nError == ERROR_SUCCESS)
    {
        if(!SFileOpenFileEx(hMpq, szToExtract, 0, &hMpqFile))
            nError = GetLastError();
    }

    // Copy the file's content
    if(nError == ERROR_SUCCESS)
    {
        char  szBuffer[0x1000];
        DWORD dwTransferred = 1;

        while(dwTransferred > 0)
        {
            SFileReadFile(hMpqFile, szBuffer, sizeof(szBuffer), &dwTransferred, NULL);
            if(dwTransferred == 0)
                break;

            WriteFile(hLocalFile, szBuffer, dwTransferred, &dwTransferred, NULL);
            if(dwTransferred == 0)
                break;
        }
    }

    // Close the files
    if(hMpqFile != NULL)
        SFileCloseFile(hMpqFile);
    if(hLocalFile != INVALID_HANDLE_VALUE)
        CloseHandle(hLocalFile);
    if(nError != ERROR_SUCCESS)
        SetLastError(nError);
    return (BOOL)(nError == ERROR_SUCCESS);
}

