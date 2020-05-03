/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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

#include "Define.h"
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

    char const* HumanReadableCASCError(uint32 error);

    StorageHandle OpenStorage(boost::filesystem::path const& path, uint32 localeMask, char const* product);
    uint32 GetBuildNumber(StorageHandle const& storage);
    uint32 GetInstalledLocalesMask(StorageHandle const& storage);
    bool HasTactKey(StorageHandle const& storage, uint64 keyLookup);

    FileHandle OpenFile(StorageHandle const& storage, char const* fileName, uint32 localeMask, bool printErrors = false, bool zerofillEncryptedParts = false);
    FileHandle OpenFile(StorageHandle const& storage, uint32 fileDataId, uint32 localeMask, bool printErrors = false, bool zerofillEncryptedParts = false);
    int64 GetFileSize(FileHandle const& file);
    int64 GetFilePointer(FileHandle const& file);
    bool SetFilePointer(FileHandle const& file, int64 position);
    bool ReadFile(FileHandle const& file, void* buffer, uint32 bytes, uint32* bytesRead);
}

#endif // CascHandles_h__
