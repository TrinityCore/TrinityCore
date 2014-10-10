/*****************************************************************************/
/* ListFile.cpp                           Copyright (c) Ladislav Zezula 2004 */
/*---------------------------------------------------------------------------*/
/* Description:                                                              */
/*---------------------------------------------------------------------------*/
/*   Date    Ver   Who  Comment                                              */
/* --------  ----  ---  -------                                              */
/* 12.06.04  1.00  Lad  The first version of ListFile.cpp                    */
/*****************************************************************************/

#define __CASCLIB_SELF__
#include "../CascLib.h"
#include "../CascCommon.h"

//-----------------------------------------------------------------------------
// Listfile entry structure

#define CACHE_BUFFER_SIZE  0x1000       // Size of the cache buffer

typedef bool (*RELOAD_CACHE)(void * pvCacheContext, LPBYTE pbBuffer, DWORD dwBytesToRead);
typedef void (*CLOSE_STREAM)(void * pvCacheContext);

struct TListFileCache
{
    RELOAD_CACHE pfnReloadCache;        // Function for reloading the cache
    CLOSE_STREAM pfnCloseStream;        // Function for closing the stream
    void  * pvCacheContext;             // Reload context passed to reload function
    char  * szMask;                     // Self-relative pointer to file mask
    DWORD   dwFileSize;                 // Total size of the cached file
    DWORD   dwFilePos;                  // Position of the cache in the file
    BYTE  * pBegin;                     // The begin of the listfile cache
    BYTE  * pPos;
    BYTE  * pEnd;                       // The last character in the file cache

    BYTE Buffer[CACHE_BUFFER_SIZE];
//  char MaskBuff[1]                    // Followed by the name mask (if any)
};

//-----------------------------------------------------------------------------
// Local functions

static bool ReloadCache_ExternalFile(void * pvCacheContext, LPBYTE pbBuffer, DWORD dwBytesToRead)
{
    TFileStream * pStream = (TFileStream *)pvCacheContext;

    return FileStream_Read(pStream, NULL, pbBuffer, dwBytesToRead);
}

static void CloseStream_ExternalFile(void * pvCacheContext)
{
    TFileStream * pStream = (TFileStream *)pvCacheContext;

    return FileStream_Close(pStream);
}


// Reloads the cache. Returns number of characters
// that has been loaded into the cache.
static DWORD ReloadListFileCache(TListFileCache * pCache)
{
    DWORD dwBytesToRead = 0;

    // Only do something if the cache is empty
    if(pCache->pPos >= pCache->pEnd)
    {
        // Move the file position forward
        pCache->dwFilePos += CACHE_BUFFER_SIZE;
        if(pCache->dwFilePos >= pCache->dwFileSize)
            return 0;

        // Get the number of bytes remaining
        dwBytesToRead = pCache->dwFileSize - pCache->dwFilePos;
        if(dwBytesToRead > CACHE_BUFFER_SIZE)
            dwBytesToRead = CACHE_BUFFER_SIZE;

        // Load the next data chunk to the cache
        // If we didn't read anything, it might mean that the block
        // of the file is not available
        // We stop reading the file at this point, because the rest
        // of the listfile is unreliable
        if(!pCache->pfnReloadCache(pCache->pvCacheContext, pCache->Buffer, dwBytesToRead))
            return 0;

        // Set the buffer pointers
        pCache->pBegin =
        pCache->pPos = &pCache->Buffer[0];
        pCache->pEnd = pCache->pBegin + dwBytesToRead;
    }

    return dwBytesToRead;
}

static size_t ReadListFileLine(TListFileCache * pCache, char * szLine, size_t nMaxChars)
{
    char * szLineBegin = szLine;
    char * szLineEnd = szLine + nMaxChars - 1;
    char * szExtraString = NULL;
    
    // Skip newlines, spaces, tabs and another non-printable stuff
    for(;;)
    {
        // If we need to reload the cache, do it
        if(pCache->pPos == pCache->pEnd)
        {
            if(ReloadListFileCache(pCache) == 0)
                break;
        }

        // If we found a non-whitespace character, stop
        if(pCache->pPos[0] > 0x20)
            break;

        // Skip the character
        pCache->pPos++;
    }

    // Copy the remaining characters
    while(szLine < szLineEnd)
    {
        // If we need to reload the cache, do it now and resume copying
        if(pCache->pPos == pCache->pEnd)
        {
            if(ReloadListFileCache(pCache) == 0)
                break;
        }

        // If we have found a newline, stop loading
        if(*pCache->pPos == 0x0D || *pCache->pPos == 0x0A)
            break;

        // Blizzard listfiles can also contain information about patch:
        // Pass1\Files\MacOS\unconditional\user\Background Downloader.app\Contents\Info.plist~Patch(Data#frFR#base-frFR,1326)
        if(*pCache->pPos == '~')
            szExtraString = szLine;

        // Copy the character
        *szLine++ = *pCache->pPos++;
    }

    // Terminate line with zero
    *szLine = 0;

    // If there was extra string after the file name, clear it
    if(szExtraString != NULL)
    {
        if(szExtraString[0] == '~' && szExtraString[1] == 'P')
        {
            szLine = szExtraString;
            *szExtraString = 0;
        }
    }

    // Return the length of the line
    return (szLine - szLineBegin);
}

static TListFileCache * CreateListFileCache(RELOAD_CACHE pfnReloadCache, CLOSE_STREAM pfnCloseStream, void * pvCacheContext, DWORD dwFileSize)
{
    TListFileCache * pCache = NULL;
    DWORD dwBytesToRead;

    // Allocate cache for one file block
    pCache = (TListFileCache *)CASC_ALLOC(BYTE, sizeof(TListFileCache));
    if(pCache != NULL)
    {
        // Clear the entire structure
        memset(pCache, 0, sizeof(TListFileCache));
        pCache->pfnReloadCache = pfnReloadCache;
        pCache->pfnCloseStream = pfnCloseStream;
        pCache->pvCacheContext = pvCacheContext;
        pCache->dwFileSize = dwFileSize;

        // Load the file cache from the file
        dwBytesToRead = CASCLIB_MIN(CACHE_BUFFER_SIZE, dwFileSize);
        if(pfnReloadCache(pvCacheContext, pCache->Buffer, dwBytesToRead))
        {
            // Allocate pointers
            pCache->pBegin = pCache->pPos = &pCache->Buffer[0];
            pCache->pEnd   = pCache->pBegin + dwBytesToRead;
        }
        else
        {
            ListFile_Free(pCache);
            pCache = NULL;
        }
    }

    // Return the cache
    return pCache;
}

//-----------------------------------------------------------------------------
// Listfile functions

void * ListFile_OpenExternal(const TCHAR * szListFile)
{
    TListFileCache * pCache;
    TFileStream * pStream;
    ULONGLONG FileSize = 0;

    // Open the external listfile
    pStream = FileStream_OpenFile(szListFile, STREAM_FLAG_READ_ONLY);
    if(pStream != NULL)
    {
        // Retrieve the size of the external listfile
        FileStream_GetSize(pStream, &FileSize);
        if(0 < FileSize && FileSize <= 0xFFFFFFFF)
        {                                                               
            // Create the cache for the listfile
            pCache = CreateListFileCache(ReloadCache_ExternalFile, CloseStream_ExternalFile, pStream, (DWORD)FileSize);
            if(pCache != NULL)
                return pCache;
        }

        // Close the file stream
        FileStream_Close(pStream);
    }

    return NULL;
}

size_t ListFile_GetNext(void * pvListFile, const char * szMask, char * szBuffer, size_t nMaxChars)
{
    TListFileCache * pCache = (TListFileCache *)pvListFile;
    size_t nLength = 0;
    int nError = ERROR_INVALID_PARAMETER;

    // Check for parameters
    if(pCache != NULL)
    {
        for(;;)
        {
            // Read the (next) line
            nLength = ReadListFileLine(pCache, szBuffer, nMaxChars);
            if(nLength == 0)
            {
                nError = ERROR_NO_MORE_FILES;
                break;
            }

            // If some mask entered, check it
            if(CheckWildCard(szBuffer, szMask))
            {
                nError = ERROR_SUCCESS;
                break;
            }
        }
    }

    if(nError != ERROR_SUCCESS)
        SetLastError(nError);
    return nLength;
}

void ListFile_Free(void * pvListFile)
{
    TListFileCache * pCache = (TListFileCache *)pvListFile;

    // Valid parameter check
    if(pCache != NULL)
    {
        if(pCache->pfnCloseStream != NULL)
            pCache->pfnCloseStream(pCache->pvCacheContext);
        CASC_FREE(pCache);
    }
}
