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

#include "IPLocation.h"
#include "Config.h"
#include "ByteConverter.h"
#include "IpAddress.h"
#include "Log.h"

IPLocation::IPLocation() : _fileHandle(nullptr), _databaseType(0), _databaseColumn(0), _databaseDay(0),
    _databaseMonth(0), _databaseYear(0), _databaseCount(0), _databaseAddr(0), _ipVersion(0),
    _ipv4DatabaseCount(0), _ipv4DatabaseAddr(0), _ipv4IndexbaseAddr(0)
{
}

IPLocation::~IPLocation()
{
}

void IPLocation::Load()
{
    std::string const value = sConfigMgr->GetStringDefault("IPLocationFile", "");
    if (value.empty())
        return;

    _ipLocation.clear();
    TC_LOG_INFO("server.loading", "Loading IP Location Database...");

    FILE* file = fopen(value.c_str(), "rb");
    if (!file)
    {
        TC_LOG_INFO("server.loading", "IPLocation:: No database file exists.");
        return;
    }

    IPLocation* location = new IPLocation();

    location->_fileHandle = file;

    location->_databaseType       = Read8(location->_fileHandle,  1);
    location->_databaseColumn     = Read8(location->_fileHandle,  2);
    location->_databaseYear       = Read8(location->_fileHandle,  3);
    location->_databaseMonth      = Read8(location->_fileHandle,  4);
    location->_databaseDay        = Read8(location->_fileHandle,  5);

    location->_databaseCount      = Read32(location->_fileHandle, 6);
    location->_databaseAddr       = Read32(location->_fileHandle, 10);
    location->_ipVersion          = Read32(location->_fileHandle, 14);

    location->_ipv4DatabaseCount  = Read32(location->_fileHandle, 6);
    location->_ipv4DatabaseAddr   = Read32(location->_fileHandle, 10);
    location->_ipv4IndexbaseAddr  = Read32(location->_fileHandle, 22);

    _ipLocation.push_back(location);

    TC_LOG_INFO("server.loading", ">> Loaded IP Location Database.");
}

uint8 IPLocation::Read8(FILE* handle, uint32 position)
{
    uint8 ret = 0;

    if (handle != nullptr)
    {
        fseek(handle, position - 1, 0);
        fread(&ret, 1, 1, handle);
    }

    return ret;
}

uint32 IPLocation::Read32(FILE* handle, uint32 position)
{
    uint8 byte1 = 0;
    uint8 byte2 = 0;
    uint8 byte3 = 0;
    uint8 byte4 = 0;

    // Read from file
    if (handle != nullptr)
    {
        fseek(handle, position - 1, 0);
        fread(&byte1, 1, 1, handle);
        fread(&byte2, 1, 1, handle);
        fread(&byte3, 1, 1, handle);
        fread(&byte4, 1, 1, handle);
    }
    else
        return 0;

    return ((byte4 << 24) | (byte3 << 16) | (byte2 << 8) | (byte1));
}

IPLocationRecord* IPLocation::GetData(std::string const& ipAddress)
{
    Ipv parsed_ipv;
    parsed_ipv.ipversion = 4;
    parsed_ipv.ipv4 = IP2No(ipAddress);

    return GetIPv4Record(parsed_ipv);
}

IPLocationRecord* IPLocation::GetIPv4Record(Ipv parsed_ipv)
{
    if (_ipLocation.empty())
        return nullptr;

    IPLocation* location = *_ipLocation.begin();
    if (!location)
        return nullptr;

    FILE* handle    = location->_fileHandle;
    uint32 baseaddr = location->_ipv4DatabaseAddr;
    uint32 dbcolumn = location->_databaseColumn;
    uint32 ipv4indexbaseaddr = location->_ipv4IndexbaseAddr;

    uint32 low  = 0;
    uint32 high = location->_ipv4DatabaseCount;
    uint32 mid  = 0;

    uint32 ipfrom = 0;
    uint32 ipto   = 0;

    uint32 ipno = parsed_ipv.ipv4;
    if (ipno == (uint32)MAX_IPV4_RANGE)
        ipno = ipno - 1;

    if (ipv4indexbaseaddr > 0)
    {
        // use the index table 
        uint32 ipnum1n2 = (uint32)ipno >> 16;
        uint32 indexpos = ipv4indexbaseaddr + (ipnum1n2 << 3);

        low  = Read32(handle, indexpos);
        high = Read32(handle, indexpos + 4);
    }

    while (low <= high)
    {
        mid     = (uint32)((low + high) >> 1);
        ipfrom  = Read32(handle, baseaddr + mid * dbcolumn * 4);
        ipto    = Read32(handle, baseaddr + (mid + 1) * dbcolumn * 4);

        if ((ipno >= ipfrom) && (ipno < ipto))
            return ReadRecord(baseaddr + (mid * dbcolumn * 4));
        else
        {
            if (ipno < ipfrom)
                high = mid - 1;
            else
                low = mid + 1;
        }
    }

    return nullptr;
}

uint32 IPLocation::IP2No(std::string const& ipAddress)
{
    uint32 ip = Trinity::Net::address_to_uint(Trinity::Net::make_address_v4(ipAddress));
    EndianConvertReverse(ip);

    uint8* ptr = (uint8*)&ip;
    uint32 a   = 0;

    if (ipAddress.c_str() != nullptr)
    {
        a  = (uint8)(ptr[3]);
        a += (uint8)(ptr[2]) * 256;
        a += (uint8)(ptr[1]) * 256 * 256;
        a += (uint8)(ptr[0]) * 256 * 256 * 256;
    }

    return a;
}

char* IPLocation::ReadStr(FILE* handle, uint32 position)
{
    uint8 size = 0;
    char* str = nullptr;
    if (handle != nullptr)
    {
        fseek(handle, position, 0);
        fread(&size, 1, 1, handle);
        str = (char *)malloc(size + 1);
        memset(str, 0, size + 1);
        fread(str, size, 1, handle);
    }

    return str;
}

IPLocationRecord* IPLocation::ReadRecord(uint32 rowaddr)
{
    if (_ipLocation.empty())
        return nullptr;

    IPLocation* location = *_ipLocation.begin();
    if (!location)
        return nullptr;

    uint8 dbtype = location->_databaseType;
    FILE* handle = location->_fileHandle;
    IPLocationRecord* record = new IPLocationRecord();
    if (!record)
        return nullptr;

    if (dbtype == IPLOCATION_DATABASE_TYPE_FILE)
    {
        std::string countryShort = ReadStr(handle, Read32(handle, rowaddr + 4 * (2 - 1)));
        std::transform(countryShort.begin(), countryShort.end(), countryShort.begin(), ::tolower);

        record->country_short = countryShort;
        record->country_long  = ReadStr(handle, Read32(handle, rowaddr + 4 * (2 - 1)) + 3);
    }
    else
    {
        record->country_short = "N/A";
        record->country_long  = "N/A";
    }

    return record;
}

IPLocationRecord* IPLocation::BadRecord(char const* message)
{
    IPLocationRecord* record = new IPLocationRecord();
    if (!record)
        return nullptr;

    record->country_short = message;
    record->country_long = message;

    return record;
}

IPLocation* IPLocation::instance()
{
    static IPLocation instance;
    return &instance;
}

IPLocationRecord::IPLocationRecord()
{
}

IPLocationRecord::~IPLocationRecord()
{
}
