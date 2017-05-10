/*****************************************************************************/
/* DumpContext.cpp                        Copyright (c) Ladislav Zezula 2015 */
/*---------------------------------------------------------------------------*/
/* Implementation of dump context                                            */
/*---------------------------------------------------------------------------*/
/*   Date    Ver   Who  Comment                                              */
/* --------  ----  ---  -------                                              */
/* 16.03.15  1.00  Lad  Created                                              */
/*****************************************************************************/

#define __CASCLIB_SELF__
#include "../CascLib.h"
#include "../CascCommon.h"

//-----------------------------------------------------------------------------
// Local functions

static TCHAR * FormatFileName(TCascStorage * hs, const TCHAR * szNameFormat)
{
    TCHAR * szFileName;
    TCHAR * szSrc;
    TCHAR * szTrg;

    // Create copy of the file name
    szFileName = szSrc = szTrg = CascNewStr(szNameFormat, 0);
    if(szFileName != NULL)
    {
        // Format the file name
        while(szSrc[0] != 0)
        {
            if(szSrc[0] == _T('%'))
            {
                // Replace "%build%" with a build number
                if(!_tcsncmp(szSrc, _T("%build%"), 7))
                {
                    szTrg += _stprintf(szTrg, _T("%u"), hs->dwBuildNumber);
                    szSrc += 7;
                    continue;
                }
            }

            // Just copy the character
            *szTrg++ = *szSrc++;
        }

        // Terminate the target file name
        szTrg[0] = 0;
    }

    return szFileName;
}

//-----------------------------------------------------------------------------
// Public functions

TDumpContext * CreateDumpContext(TCascStorage * hs, const TCHAR * szNameFormat)
{
    TDumpContext * dc;
    TCHAR * szFileName;

    // Validate the storage handle
    if(hs != NULL)
    {
        // Calculate the number of bytes needed for dump context
        dc = CASC_ALLOC(TDumpContext, 1);
        if(dc != NULL)
        {
            // Initialize the dump context
            memset(dc, 0, sizeof(TDumpContext));

            // Format the real file name
            szFileName = FormatFileName(hs, szNameFormat);
            if(szFileName != NULL)
            {
                // Create the file
                dc->pStream = FileStream_CreateFile(szFileName, 0);
                if(dc->pStream != NULL)
                {
                    // Initialize buffers
                    dc->pbBufferBegin =
                    dc->pbBufferPtr = dc->DumpBuffer;
                    dc->pbBufferEnd = dc->DumpBuffer + CASC_DUMP_BUFFER_SIZE;

                    // Success
                    CASC_FREE(szFileName);
                    return dc;
                }

                // File create failed --> delete the file name
                CASC_FREE(szFileName);
            }

            // Free the dump context
            CASC_FREE(dc);
        }
    }

    return NULL;
}

int dump_print(TDumpContext * dc, const char * szFormat, ...)
{
    va_list argList;
    char szBuffer[0x200];
    int nLength = 0;

    // Only if the dump context is valid
    if(dc != NULL)
    {
        // Print the buffer using sprintf
        va_start(argList, szFormat);
        nLength = vsprintf(szBuffer, szFormat, argList);
        assert(nLength < 0x200);
        va_end(argList);

        // Copy the string. Replace "\n" with "\n\r"
        for(int i = 0; i < nLength; i++)
        {
            // Flush the buffer, if needed
            if((dc->pbBufferPtr + 2) >= dc->pbBufferEnd)
            {
                FileStream_Write(dc->pStream, NULL, dc->pbBufferBegin, (DWORD)(dc->pbBufferPtr - dc->pbBufferBegin));
                dc->pbBufferPtr = dc->pbBufferBegin;
            }

            // Copy the char
            if(szBuffer[i] == 0x0A)
                *dc->pbBufferPtr++ = 0x0D;
            *dc->pbBufferPtr++ = szBuffer[i];
        }
    }

    return nLength;
}

int dump_close(TDumpContext * dc)
{
    // Only if the dump context is valid
    if(dc != NULL)
    {
        // Flush the dump context if there are some data
        if(dc->pbBufferPtr > dc->pbBufferBegin)
            FileStream_Write(dc->pStream, NULL, dc->pbBufferBegin, (DWORD)(dc->pbBufferPtr - dc->pbBufferBegin));
        dc->pbBufferPtr = dc->pbBufferBegin;

        // Free the file stream and the entire context
        if(dc->pStream != NULL)
            FileStream_Close(dc->pStream);
        CASC_FREE(dc);
    }

    return 0;
}
