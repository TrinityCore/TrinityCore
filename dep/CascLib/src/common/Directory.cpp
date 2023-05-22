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

bool DirectoryExists(LPCTSTR szDirectory)
{
#ifdef CASCLIB_PLATFORM_WINDOWS

    DWORD dwAttributes = GetFileAttributes(szDirectory);
    if((dwAttributes != INVALID_FILE_ATTRIBUTES) && (dwAttributes & FILE_ATTRIBUTE_DIRECTORY))
        return true;

#else // CASCLIB_PLATFORM_WINDOWS

    DIR * dir = opendir(szDirectory);

    if(dir != NULL)
    {
        closedir(dir);
        return true;
    }

#endif

    return false;
}

bool MakeDirectory(LPCTSTR szDirectory)
{
#ifdef CASCLIB_PLATFORM_WINDOWS

    BOOL bResult = CreateDirectory(szDirectory, NULL);
    return (bResult) ? true : false;

#else

    return (mkdir(szDirectory, 0755) == 0);

#endif
}

DWORD ScanDirectory(
    LPCTSTR szDirectory,
    DIRECTORY_CALLBACK PfnFolderCallback,
    DIRECTORY_CALLBACK PfnFileCallback,
    void * pvContext)
{
#ifdef CASCLIB_PLATFORM_WINDOWS

    CASC_PATH<TCHAR> SearchMask(szDirectory, _T("*"), NULL);
    WIN32_FIND_DATA wf;
    HANDLE hFind;

    // Prepare directory search
    hFind = FindFirstFile(SearchMask, &wf);
    if(hFind != INVALID_HANDLE_VALUE)
    {
        // Skip the first file as it's always just "." or ".."
        while(FindNextFile(hFind, &wf))
        {
            // If we found a folder, we call the directory callback
            if(wf.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
            {
                if(PfnFolderCallback != NULL)
                {
                    if(!PfnFolderCallback(wf.cFileName, pvContext))
                        break;
                }
            }
            else
            {
                if(PfnFileCallback != NULL)
                {
                    if(!PfnFileCallback(wf.cFileName, pvContext))
                        break;
                }
            }
        }

        // Close the search handle
        FindClose(hFind);
        return ERROR_SUCCESS;
    }

#else // CASCLIB_PLATFORM_WINDOWS

    struct dirent * dir_entry;
    DIR * dir;

    // Prepare directory search
    if((dir = opendir(szDirectory)) != NULL)
    {
        // Read (the next) directory entry
        while((dir_entry = readdir(dir)) != NULL)
        {
            if(dir_entry->d_type == DT_DIR)
            {
                if(PfnFolderCallback != NULL)
                {
                    if(!PfnFolderCallback(dir_entry->d_name, pvContext))
                    {
                        break;
                    }
                }
            }
            else
            {
                if(PfnFileCallback != NULL)
                {
                    if(!PfnFileCallback(dir_entry->d_name, pvContext))
                    {
                        break;
                    }
                }
            }
        }

        closedir(dir);
        return ERROR_SUCCESS;
    }

#endif

    return ERROR_PATH_NOT_FOUND;
}
