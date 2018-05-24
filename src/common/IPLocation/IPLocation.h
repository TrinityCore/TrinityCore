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

#include "Define.h"
#include <string>

#define MAX_IPV4_RANGE 4294967295U
#define IPLOCATION_DATABASE_TYPE_FILE 1

typedef struct Ipv
{
    uint32 ipversion;
    uint32 ipv4;
} Ipv;

static void*  cache_shm_ptr;

class TC_COMMON_API IPLocationRecord
{
    public:
        IPLocationRecord();
        ~IPLocationRecord();

        std::string country_short;
        std::string country_long;
};

class TC_COMMON_API IPLocation
{
    public:
        IPLocation();
        ~IPLocation();
        static IPLocation* instance();

        void Load();
        IPLocationRecord* GetData(std::string const& ipAddress);

    private:
        uint8 Read8(FILE* handle, uint32 position);
        uint32 Read32(FILE* handle, uint32 position);
        static uint32 IP2No(std::string const& ipAddress);
        char* ReadStr(FILE* handle, uint32 position);
        IPLocationRecord* ReadRecord(uint32 rowaddr);
        IPLocationRecord* GetIPv4Record(Ipv parsed_ipv);
        IPLocationRecord* BadRecord(char const* message);

        FILE*  _fileHandle;
        uint8  _databaseType;
        uint8  _databaseColumn;
        uint8  _databaseDay;
        uint8  _databaseMonth;
        uint8  _databaseYear;
        uint32 _databaseCount;
        uint32 _databaseAddr;
        uint32 _ipVersion;
        uint32 _ipv4DatabaseCount;
        uint32 _ipv4DatabaseAddr;
        uint32 _ipv4IndexbaseAddr;

        std::vector<IPLocation*> _ipLocation;
};

#define sIPLocation IPLocation::instance()

