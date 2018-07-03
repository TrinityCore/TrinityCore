/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef CascHandles_h__
#define CascHandles_h__

#include <CascPort.h>
#include <memory>

namespace boost
{
    namespace filesystem
    {
        class path;
    }
}

namespace CASC
{
    struct StorageDeleter
    {
        typedef HANDLE pointer;
        void operator()(HANDLE handle);
    };

    struct FileDeleter
    {
        typedef HANDLE pointer;
        void operator()(HANDLE handle);
    };

    typedef std::unique_ptr<HANDLE, StorageDeleter> StorageHandle;
    typedef std::unique_ptr<HANDLE, FileDeleter> FileHandle;

    char const* HumanReadableCASCError(DWORD error);

    StorageHandle OpenStorage(boost::filesystem::path const& path, DWORD localeMask);
    DWORD GetBuildNumber(StorageHandle const& storage);
    DWORD GetInstalledLocalesMask(StorageHandle const& storage);

    FileHandle OpenFile(StorageHandle const& storage, char const* fileName, DWORD localeMask, bool printErrors = false);
    DWORD GetFileSize(FileHandle const& file, PDWORD fileSizeHigh);
    DWORD GetFilePointer(FileHandle const& file);
    bool ReadFile(FileHandle const& file, void* buffer, DWORD bytes, PDWORD bytesRead);
}

#endif // CascHandles_h__
