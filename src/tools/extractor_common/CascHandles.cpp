/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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

#include "CascHandles.h"
#include <CascLib.h>
#include <boost/filesystem/operations.hpp>

char const* CASC::HumanReadableCASCError(DWORD error)
{
    switch (error)
    {
        case ERROR_SUCCESS: return "SUCCESS";
        case ERROR_FILE_CORRUPT: return "FILE_CORRUPT";
        case ERROR_CAN_NOT_COMPLETE: return "CAN_NOT_COMPLETE";
        case ERROR_HANDLE_EOF: return "HANDLE_EOF";
        case ERROR_NO_MORE_FILES: return "NO_MORE_FILES";
        case ERROR_BAD_FORMAT: return "BAD_FORMAT";
        case ERROR_INSUFFICIENT_BUFFER: return "INSUFFICIENT_BUFFER";
        case ERROR_ALREADY_EXISTS: return "ALREADY_EXISTS";
        case ERROR_DISK_FULL: return "DISK_FULL";
        case ERROR_INVALID_PARAMETER: return "INVALID_PARAMETER";
        case ERROR_NOT_SUPPORTED: return "NOT_SUPPORTED";
        case ERROR_NOT_ENOUGH_MEMORY: return "NOT_ENOUGH_MEMORY";
        case ERROR_INVALID_HANDLE: return "INVALID_HANDLE";
        case ERROR_ACCESS_DENIED: return "ACCESS_DENIED";
        case ERROR_FILE_NOT_FOUND: return "FILE_NOT_FOUND";
        default: return "UNKNOWN";
    }
}

void CASC::StorageDeleter::operator()(HANDLE handle)
{
    if (handle != nullptr && handle != INVALID_HANDLE_VALUE)
        ::CascCloseStorage(handle);
}

void CASC::FileDeleter::operator()(HANDLE handle)
{
    if (handle != nullptr && handle != INVALID_HANDLE_VALUE)
        ::CascCloseFile(handle);
}

CASC::StorageHandle CASC::OpenStorage(boost::filesystem::path const& path, DWORD localeMask)
{
    HANDLE handle = nullptr;
    if (!::CascOpenStorage(path.string().c_str(), localeMask, &handle))
    {
        DWORD lastError = GetLastError(); // support checking error set by *Open* call, not the next *Close*
        printf("Error opening casc storage '%s': %s\n", path.string().c_str(), HumanReadableCASCError(lastError));
        CascCloseStorage(handle);
        SetLastError(lastError);
        return StorageHandle();
    }

    printf("Opened casc storage '%s'\n", path.string().c_str());
    return StorageHandle(handle);
}

namespace CASC
{
    static DWORD GetStorageInfo(StorageHandle const& storage, CASC_STORAGE_INFO_CLASS storageInfoClass)
    {
        DWORD value = 0;
        size_t infoDataSizeNeeded = 0;
        if (!::CascGetStorageInfo(storage.get(), storageInfoClass, &value, sizeof(value), &infoDataSizeNeeded))
        {
            if (GetLastError() == ERROR_INSUFFICIENT_BUFFER)
            {
                std::unique_ptr<char> buf(new char[infoDataSizeNeeded]);
                ::CascGetStorageInfo(storage.get(), storageInfoClass, buf.get(), infoDataSizeNeeded, &infoDataSizeNeeded);
                return *reinterpret_cast<DWORD*>(buf.get());
            }
        }

        return value;
    }
}

DWORD CASC::GetBuildNumber(StorageHandle const& storage)
{
    return GetStorageInfo(storage, CascStorageGameBuild);
}

DWORD CASC::GetInstalledLocalesMask(StorageHandle const& storage)
{
    return GetStorageInfo(storage, CascStorageInstalledLocales);
}

CASC::FileHandle CASC::OpenFile(StorageHandle const& storage, char const* fileName, DWORD localeMask, bool printErrors /*= false*/)
{
    HANDLE handle = nullptr;
    if (!::CascOpenFile(storage.get(), fileName, localeMask, 0, &handle))
    {
        DWORD lastError = GetLastError(); // support checking error set by *Open* call, not the next *Close*
        if (printErrors)
            fprintf(stderr, "Failed to open '%s' in CASC storage: %s\n", fileName, HumanReadableCASCError(lastError));

        CascCloseFile(handle);
        SetLastError(lastError);
        return FileHandle();
    }

    return FileHandle(handle);
}

DWORD CASC::GetFileSize(FileHandle const& file, PDWORD fileSizeHigh)
{
    return ::CascGetFileSize(file.get(), fileSizeHigh);
}

DWORD CASC::GetFilePointer(FileHandle const& file)
{
    return ::CascSetFilePointer(file.get(), 0, nullptr, FILE_CURRENT);
}

bool CASC::SetFilePointer(FileHandle const& file, LONGLONG position)
{
    LONG parts[2];
    memcpy(parts, &position, sizeof(parts));
    return ::CascSetFilePointer(file.get(), parts[0], &parts[1], FILE_BEGIN) != CASC_INVALID_POS;
}

bool CASC::ReadFile(FileHandle const& file, void* buffer, DWORD bytes, PDWORD bytesRead)
{
    return ::CascReadFile(file.get(), buffer, bytes, bytesRead);
}
