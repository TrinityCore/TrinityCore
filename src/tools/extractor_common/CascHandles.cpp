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
#include "IoContext.h"
#include "Resolver.h"
#include <CascLib.h>
#include <boost/asio/streambuf.hpp>
#include <boost/asio/read.hpp>
#include <boost/asio/read_until.hpp>
#include <boost/asio/write.hpp>
#include <boost/asio/ssl/stream.hpp>
#include <boost/filesystem/operations.hpp>
#include <string>

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
        case ERROR_FILE_OFFLINE: return "FILE_OFFLINE";
        default: return "UNKNOWN";
    }
}

namespace
{
    Optional<std::string> DownloadFile(std::string const& serverName, int16 port, std::string const& getCommand)
    {
        boost::system::error_code error;
        Trinity::Asio::IoContext ioContext;
        boost::asio::ssl::context sslContext(boost::asio::ssl::context::sslv23);
        sslContext.set_options(boost::asio::ssl::context::no_sslv2, error);
        sslContext.set_options(boost::asio::ssl::context::no_sslv3, error);
        sslContext.set_options(boost::asio::ssl::context::no_tlsv1, error);
        sslContext.set_options(boost::asio::ssl::context::no_tlsv1_1, error);
        sslContext.set_default_verify_paths(error);

        Trinity::Asio::Resolver resolver(ioContext);

        Optional<boost::asio::ip::tcp::endpoint> endpoint = resolver.Resolve(boost::asio::ip::tcp::v4(), serverName, std::to_string(port));
        if (!endpoint)
            return {};

        boost::asio::ssl::stream<boost::asio::ip::tcp::socket> socket(ioContext, sslContext);
        socket.set_verify_mode(boost::asio::ssl::verify_none, error);
        if (error)
            return {};

        socket.lowest_layer().connect(*endpoint, error);
        if (error)
            return {};

        if (!SSL_set_tlsext_host_name(socket.native_handle(), serverName.c_str()))
            return {};

        socket.handshake(boost::asio::ssl::stream_base::client, error);
        if (error)
            return {};

        boost::asio::streambuf request;
        std::ostream request_stream(&request);

        request_stream << "GET " << getCommand << " HTTP/1.0\r\n";
        request_stream << "Host: " << serverName << "\r\n";
        request_stream << "Connection: close\r\n\r\n";

        // Send the request.
        boost::asio::write(socket, request);

        // Read the response status line.
        boost::asio::streambuf response;
        boost::asio::read_until(socket, response, "\r\n", error);
        if (error)
        {
            printf("Downloading tact key list failed to read HTTP response status %s", error.message().c_str());
            return {};
        }

        // Check that response is OK.
        std::string http_version;
        uint32 status_code;
        std::string status_message;
        std::istream response_stream(&response);

        response_stream >> http_version;
        response_stream >> status_code;
        std::getline(response_stream, status_message);

        if (status_code != 200)
        {
            printf("Downloading tact key list failed with server response %u %s", status_code, status_message.c_str());
            return {};
        }

        // Read the response headers, which are terminated by a blank line.
        boost::asio::read_until(socket, response, "\r\n\r\n");
        if (error)
        {
            printf("Downloading tact key list failed to read HTTP response headers %s", error.message().c_str());
            return {};
        }

        // Process the response headers.
        std::string header;
        while (std::getline(response_stream, header) && header != "\r")
        {
        }

        std::stringstream rawBody;

        // Write whatever content we already have to output.
        if (response.size() > 0)
            rawBody << &response;

        // Read until EOF, writing data to output as we go.
        while (boost::asio::read(socket, response, boost::asio::transfer_at_least(1), error))
            rawBody << &response;

        return rawBody.str();
    }

    template<typename T>
    bool GetStorageInfo(HANDLE storage, CASC_STORAGE_INFO_CLASS storageInfoClass, T* value)
    {
        size_t infoDataSizeNeeded = 0;
        return ::CascGetStorageInfo(storage, storageInfoClass, value, sizeof(T), &infoDataSizeNeeded);
    }
}

namespace CASC
{
using CASCCharType = std::remove_const_t<std::remove_pointer_t<decltype(CASC_OPEN_STORAGE_ARGS::szLocalPath)>>;
using CASCStringType = std::basic_string<CASCCharType>;

Storage::Storage(HANDLE handle) : _handle(handle)
{
}

bool Storage::LoadOnlineTactKeys()
{
    // attempt to download only once, not every storage opening
    static Optional<std::string> const tactKeys = DownloadFile("raw.githubusercontent.com", 443, "/wowdev/TACTKeys/master/WoW.txt");

    return tactKeys && CascImportKeysFromString(_handle, tactKeys->c_str());
}

Storage::~Storage()
{
    ::CascCloseStorage(_handle);
}

Storage* Storage::Open(boost::filesystem::path const& path, uint32 localeMask, char const* product)
{
    CASCStringType strPath = path.template string<CASCStringType>();
    CASCStringType strProduct(product, product + strlen(product)); // dumb conversion from char to wchar, always ascii
    CASC_OPEN_STORAGE_ARGS args = {};
    args.Size = sizeof(CASC_OPEN_STORAGE_ARGS);
    args.szLocalPath = strPath.c_str();
    args.szCodeName = strProduct.c_str();
    args.dwLocaleMask = localeMask;
    HANDLE handle = nullptr;
    if (!CascOpenStorageEx(nullptr, &args, false, &handle))
    {
        DWORD lastError = GetCascError(); // support checking error set by *Open* call, not the next *Close*
        printf("Error opening casc storage '%s': %s\n", path.string().c_str(), HumanReadableCASCError(lastError));
        CascCloseStorage(handle);
        SetCascError(lastError);
        return nullptr;
    }

    printf("Opened casc storage '%s'\n", path.string().c_str());
    Storage* storage = new Storage(handle);

    if (!storage->LoadOnlineTactKeys())
        printf("Failed to load additional online encryption keys, some files might not be extracted.\n");

    return storage;
}

Storage* Storage::OpenRemote(boost::filesystem::path const& path, uint32 localeMask, char const* product, char const* region)
{
    CASCStringType strPath = path.template string<CASCStringType>();
    CASCStringType strProduct(product, product + strlen(product)); // dumb conversion from char to wchar, always ascii
    CASCStringType strRegion(region, region + strlen(region)); // dumb conversion from char to wchar, always ascii
    CASC_OPEN_STORAGE_ARGS args = {};
    args.Size = sizeof(CASC_OPEN_STORAGE_ARGS);
    args.szLocalPath = strPath.c_str();
    args.szCodeName = strProduct.c_str();
    args.szRegion = strRegion.c_str();
    args.dwLocaleMask = localeMask;

    HANDLE handle = nullptr;
    if (!::CascOpenStorageEx(nullptr, &args, true, &handle))
    {
        DWORD lastError = GetCascError(); // support checking error set by *Open* call, not the next *Close*
        printf("Error opening remote casc storage: %s\n", HumanReadableCASCError(lastError));
        CascCloseStorage(handle);
        SetCascError(lastError);
        return nullptr;
    }

    DWORD features = 0;
    if (!GetStorageInfo(handle, CascStorageFeatures, &features) || !(features & CASC_FEATURE_ONLINE))
    {
        printf("Local casc storage detected in cache path \"%s\" (or its parent directory). Remote storage not opened!\n", path.string().c_str());
        CascCloseStorage(handle);
        SetCascError(ERROR_FILE_OFFLINE);
        return nullptr;
    }

    printf("Opened remote casc storage '%s'\n", path.string().c_str());
    Storage* storage = new Storage(handle);

    if (!storage->LoadOnlineTactKeys())
        printf("Failed to load additional online encryption keys, some files might not be extracted.\n");

    return storage;
}

uint32 Storage::GetBuildNumber() const
{
    CASC_STORAGE_PRODUCT product;
    if (GetStorageInfo(_handle, CascStorageProduct, &product))
        return product.BuildNumber;

    return 0;
}

uint32 Storage::GetInstalledLocalesMask() const
{
    DWORD locales;
    if (GetStorageInfo(_handle, CascStorageInstalledLocales, &locales))
        return locales;

    return 0;
}

bool Storage::HasTactKey(uint64 keyLookup) const
{
    return CascFindEncryptionKey(_handle, keyLookup) != nullptr;
}

File* Storage::OpenFile(char const* fileName, uint32 localeMask, bool printErrors /*= false*/, bool zerofillEncryptedParts /*= false*/) const
{
    DWORD openFlags = CASC_OPEN_BY_NAME;
    if (zerofillEncryptedParts)
        openFlags |= CASC_OVERCOME_ENCRYPTED;

    HANDLE handle = nullptr;
    if (!::CascOpenFile(_handle, fileName, localeMask, openFlags, &handle))
    {
        DWORD lastError = GetCascError(); // support checking error set by *Open* call, not the next *Close*
        if (printErrors)
            fprintf(stderr, "Failed to open '%s' in CASC storage: %s\n", fileName, HumanReadableCASCError(lastError));

        CascCloseFile(handle);
        SetCascError(lastError);
        return nullptr;
    }

    return new File(handle);
}

File* Storage::OpenFile(uint32 fileDataId, uint32 localeMask, bool printErrors /*= false*/, bool zerofillEncryptedParts /*= false*/) const
{
    DWORD openFlags = CASC_OPEN_BY_FILEID;
    if (zerofillEncryptedParts)
        openFlags |= CASC_OVERCOME_ENCRYPTED;

    HANDLE handle = nullptr;
    if (!::CascOpenFile(_handle, CASC_FILE_DATA_ID(fileDataId), localeMask, openFlags, &handle))
    {
        DWORD lastError = GetCascError(); // support checking error set by *Open* call, not the next *Close*
        if (printErrors)
            fprintf(stderr, "Failed to open 'FileDataId %u' in CASC storage: %s\n", fileDataId, HumanReadableCASCError(lastError));

        CascCloseFile(handle);
        SetCascError(lastError);
        return nullptr;
    }

    return new File(handle);
}

File::File(HANDLE handle) : _handle(handle)
{
}

File::~File()
{
    ::CascCloseFile(_handle);
}

uint32 File::GetId() const
{
    CASC_FILE_FULL_INFO info;
    if (!::CascGetFileInfo(_handle, CascFileFullInfo, &info, sizeof(info), nullptr))
        return CASC_INVALID_ID;

    return info.FileDataId;
}

int64 File::GetSize() const
{
    ULONGLONG size;
    if (!::CascGetFileSize64(_handle, &size))
        return -1;

    return int64(size);
}

int64 File::GetPointer() const
{
    ULONGLONG position;
    if (!::CascSetFilePointer64(_handle, 0, &position, FILE_CURRENT))
        return -1;

    return int64(position);
}

bool File::SetPointer(int64 position)
{
    LONG parts[2];
    memcpy(parts, &position, sizeof(parts));
    return ::CascSetFilePointer64(_handle, position, nullptr, FILE_BEGIN);
}

bool File::ReadFile(void* buffer, uint32 bytes, uint32* bytesRead)
{
    DWORD bytesReadDWORD;
    if (!::CascReadFile(_handle, buffer, bytes, &bytesReadDWORD))
        return false;

    if (bytesRead)
        *bytesRead = bytesReadDWORD;

    return true;
}
}
