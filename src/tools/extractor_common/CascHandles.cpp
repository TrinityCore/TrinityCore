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

#include "CascHandles.h"
#include <CascLib.h>
#include <boost/filesystem/operations.hpp>

char const* CASC::HumanReadableCASCError(uint32 error)
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
        case ERROR_FILE_ENCRYPTED: return "FILE_ENCRYPTED";
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

CASC::StorageHandle CASC::OpenStorage(boost::filesystem::path const& path, uint32 localeMask, char const* product)
{
    std::string strPath = path.string();
    CASC_OPEN_STORAGE_ARGS args = {};
    args.Size = sizeof(CASC_OPEN_STORAGE_ARGS);
    args.szLocalPath = strPath.c_str();
    args.szCodeName = product;
    args.dwLocaleMask = localeMask;
    HANDLE handle = nullptr;
    if (!::CascOpenStorageEx(nullptr, &args, false, &handle))
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
    template<typename T>
    static bool GetStorageInfo(StorageHandle const& storage, CASC_STORAGE_INFO_CLASS storageInfoClass, T* value)
    {
        size_t infoDataSizeNeeded = 0;
        return ::CascGetStorageInfo(storage.get(), storageInfoClass, value, sizeof(T), &infoDataSizeNeeded);
    }
}

uint32 CASC::GetBuildNumber(StorageHandle const& storage)
{
    CASC_STORAGE_PRODUCT product;
    if (GetStorageInfo(storage, CascStorageProduct, &product))
        return product.BuildNumber;

    return 0;
}

uint32 CASC::GetInstalledLocalesMask(StorageHandle const& storage)
{
    DWORD locales;
    if (GetStorageInfo(storage, CascStorageInstalledLocales, &locales))
        return locales;

    return 0;
}

bool CASC::HasTactKey(StorageHandle const& storage, uint64 keyLookup)
{
    return CascFindEncryptionKey(storage.get(), keyLookup) != nullptr;
}

CASC::FileHandle CASC::OpenFile(StorageHandle const& storage, char const* fileName, uint32 localeMask, bool printErrors /*= false*/, bool zerofillEncryptedParts /*= false*/)
{
    DWORD openFlags = CASC_OPEN_BY_NAME;
    if (zerofillEncryptedParts)
        openFlags |= CASC_OVERCOME_ENCRYPTED;

    HANDLE handle = nullptr;
    if (!::CascOpenFile(storage.get(), fileName, localeMask, openFlags, &handle))
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

CASC::FileHandle CASC::OpenFile(StorageHandle const& storage, uint32 fileDataId, uint32 localeMask, bool printErrors /*= false*/, bool zerofillEncryptedParts /*= false*/)
{
    DWORD openFlags = CASC_OPEN_BY_FILEID;
    if (zerofillEncryptedParts)
        openFlags |= CASC_OVERCOME_ENCRYPTED;

    HANDLE handle = nullptr;
    if (!::CascOpenFile(storage.get(), CASC_FILE_DATA_ID(fileDataId), localeMask, openFlags, &handle))
    {
        DWORD lastError = GetLastError(); // support checking error set by *Open* call, not the next *Close*
        if (printErrors)
            fprintf(stderr, "Failed to open 'FileDataId %u' in CASC storage: %s\n", fileDataId, HumanReadableCASCError(lastError));

        CascCloseFile(handle);
        SetLastError(lastError);
        return FileHandle();
    }

    return FileHandle(handle);
}

int64 CASC::GetFileSize(FileHandle const& file)
{
    ULONGLONG size;
    if (!::CascGetFileSize64(file.get(), &size))
        return -1;

    return int64(size);
}

int64 CASC::GetFilePointer(FileHandle const& file)
{
    ULONGLONG position;
    if (!::CascSetFilePointer64(file.get(), 0, &position, FILE_CURRENT))
        return -1;

    return int64(position);
}

bool CASC::SetFilePointer(FileHandle const& file, int64 position)
{
    LONG parts[2];
    memcpy(parts, &position, sizeof(parts));
    return ::CascSetFilePointer64(file.get(), position, nullptr, FILE_BEGIN);
}

bool CASC::ReadFile(FileHandle const& file, void* buffer, uint32 bytes, uint32* bytesRead)
{
    DWORD bytesReadDWORD;
    if (!::CascReadFile(file.get(), buffer, bytes, &bytesReadDWORD))
        return false;

    if (bytesRead)
        *bytesRead = bytesReadDWORD;

    return true;
}
