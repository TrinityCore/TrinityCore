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

CASC::Storage::Storage(HANDLE handle) : _handle(handle)
{
}

CASC::Storage::~Storage()
{
    ::CascCloseStorage(_handle);
}

CASC::Storage* CASC::Storage::Open(boost::filesystem::path const& path, uint32 localeMask, char const* product)
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
        return nullptr;
    }

    printf("Opened casc storage '%s'\n", path.string().c_str());
    return new Storage(handle);
}

namespace CASC
{
    template<typename T>
    static bool GetStorageInfo(HANDLE storage, CASC_STORAGE_INFO_CLASS storageInfoClass, T* value)
    {
        size_t infoDataSizeNeeded = 0;
        return ::CascGetStorageInfo(storage, storageInfoClass, value, sizeof(T), &infoDataSizeNeeded);
    }
}

uint32 CASC::Storage::GetBuildNumber() const
{
    CASC_STORAGE_PRODUCT product;
    if (GetStorageInfo(_handle, CascStorageProduct, &product))
        return product.BuildNumber;

    return 0;
}

uint32 CASC::Storage::GetInstalledLocalesMask() const
{
    DWORD locales;
    if (GetStorageInfo(_handle, CascStorageInstalledLocales, &locales))
        return locales;

    return 0;
}

bool CASC::Storage::HasTactKey(uint64 keyLookup) const
{
    return CascFindEncryptionKey(_handle, keyLookup) != nullptr;
}

CASC::File* CASC::Storage::OpenFile(char const* fileName, uint32 localeMask, bool printErrors /*= false*/, bool zerofillEncryptedParts /*= false*/) const
{
    DWORD openFlags = CASC_OPEN_BY_NAME;
    if (zerofillEncryptedParts)
        openFlags |= CASC_OVERCOME_ENCRYPTED;

    HANDLE handle = nullptr;
    if (!::CascOpenFile(_handle, fileName, localeMask, openFlags, &handle))
    {
        DWORD lastError = GetLastError(); // support checking error set by *Open* call, not the next *Close*
        if (printErrors)
            fprintf(stderr, "Failed to open '%s' in CASC storage: %s\n", fileName, HumanReadableCASCError(lastError));

        CascCloseFile(handle);
        SetLastError(lastError);
        return nullptr;
    }

    return new File(handle);
}

CASC::File* CASC::Storage::OpenFile(uint32 fileDataId, uint32 localeMask, bool printErrors /*= false*/, bool zerofillEncryptedParts /*= false*/) const
{
    DWORD openFlags = CASC_OPEN_BY_FILEID;
    if (zerofillEncryptedParts)
        openFlags |= CASC_OVERCOME_ENCRYPTED;

    HANDLE handle = nullptr;
    if (!::CascOpenFile(_handle, CASC_FILE_DATA_ID(fileDataId), localeMask, openFlags, &handle))
    {
        DWORD lastError = GetLastError(); // support checking error set by *Open* call, not the next *Close*
        if (printErrors)
            fprintf(stderr, "Failed to open 'FileDataId %u' in CASC storage: %s\n", fileDataId, HumanReadableCASCError(lastError));

        CascCloseFile(handle);
        SetLastError(lastError);
        return nullptr;
    }

    return new File(handle);
}

CASC::File::File(HANDLE handle) : _handle(handle)
{
}

CASC::File::~File()
{
    ::CascCloseFile(_handle);
}

uint32 CASC::File::GetId() const
{
    CASC_FILE_FULL_INFO info;
    if (!::CascGetFileInfo(_handle, CascFileFullInfo, &info, sizeof(info), nullptr))
        return CASC_INVALID_ID;

    return info.FileDataId;
}

int64 CASC::File::GetSize() const
{
    ULONGLONG size;
    if (!::CascGetFileSize64(_handle, &size))
        return -1;

    return int64(size);
}

int64 CASC::File::GetPointer() const
{
    ULONGLONG position;
    if (!::CascSetFilePointer64(_handle, 0, &position, FILE_CURRENT))
        return -1;

    return int64(position);
}

bool CASC::File::SetPointer(int64 position)
{
    LONG parts[2];
    memcpy(parts, &position, sizeof(parts));
    return ::CascSetFilePointer64(_handle, position, nullptr, FILE_BEGIN);
}

bool CASC::File::ReadFile(void* buffer, uint32 bytes, uint32* bytesRead)
{
    DWORD bytesReadDWORD;
    if (!::CascReadFile(_handle, buffer, bytes, &bytesReadDWORD))
        return false;

    if (bytesRead)
        *bytesRead = bytesReadDWORD;

    return true;
}
