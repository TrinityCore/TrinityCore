/*****************************************************************************/
/* Directory.cpp                          Copyright (c) Ladislav Zezula 2014 */
/*---------------------------------------------------------------------------*/
/* System-dependent directory functions for CascLib                          */
/*---------------------------------------------------------------------------*/
/*   Date    Ver   Who  Comment                                              */
/* --------  ----  ---  -------                                              */
/* 29.04.14  1.00  Lad  The first version of Directory.cpp                   */
/*****************************************************************************/

#define __CASCLIB_SELF__
#include "../CascLib.h"
#include "../CascCommon.h"

//-----------------------------------------------------------------------------
// Public functions

bool DirectoryExists(const TCHAR * szDirectory)
{
#ifdef PLATFORM_WINDOWS

    DWORD dwAttributes = GetFileAttributes(szDirectory);
    if((dwAttributes != INVALID_FILE_ATTRIBUTES) && (dwAttributes & FILE_ATTRIBUTE_DIRECTORY))
        return true;

#else // PLATFORM_WINDOWS

    DIR * dir = opendir(szDirectory);

    if(dir != NULL)
    {
        closedir(dir);
        return true;
    }

#endif

    return false;
}

bool MakeDirectory(const TCHAR * szDirectory)
{
#ifdef PLATFORM_WINDOWS

    BOOL bResult = CreateDirectory(szDirectory, NULL);
    return (bResult) ? true : false;

#else

    return (mkdir(szDirectory, 0755) == 0);

#endif
}

int ScanIndexDirectory(
    LPCTSTR szIndexPath,
    INDEX_FILE_FOUND pfnOnFileFound,
    void * pvContext)
{
#ifdef PLATFORM_WINDOWS

    WIN32_FIND_DATA wf;
    TCHAR * szSearchMask;
    HANDLE hFind;

    // Prepare the search mask
    szSearchMask = CombinePath(szIndexPath, _T("*"));
    if(szSearchMask == NULL)
        return ERROR_NOT_ENOUGH_MEMORY;

    // Prepare directory search
    hFind = FindFirstFile(szSearchMask, &wf);
    if(hFind != INVALID_HANDLE_VALUE)
    {
        // Skip the first file as it's always just "." or ".."
        while(FindNextFile(hFind, &wf))
        {
            // If the found object is a file, pass it to the handler
            if(!(wf.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
            {
                // Let the callback scan the file name
                pfnOnFileFound(wf.cFileName, pvContext);
            }
        }

        // Close the search handle
        FindClose(hFind);
    }

    CASC_FREE(szSearchMask);

#else // PLATFORM_WINDOWS

    struct dirent * dir_entry;
    DIR * dir;

    dir = opendir(szIndexPath);
    if(dir != NULL)
    {
        while((dir_entry = readdir(dir)) != NULL)
        {
            if(dir_entry->d_type != DT_DIR)
            {
                pfnOnFileFound(dir_entry->d_name, pvContext);
            }
        }

        closedir(dir);
    }

#endif

    return ERROR_SUCCESS;
}
