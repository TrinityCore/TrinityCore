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

struct in6_addr_local
{
    union
    {
        uint8 addr8[16];
        uint8 addr16[8];
    } u;
};

typedef struct Ipv
{
    uint32 ipversion;
    uint32 ipv4;
    struct in6_addr_local ipv6;
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

        FILE*  filehandle;
        uint8  databasetype;
        uint8  databasecolumn;
        uint8  databaseday;
        uint8  databasemonth;
        uint8  databaseyear;
        uint32 databasecount;
        uint32 databaseaddr;
        uint32 ipversion;
        uint32 ipv4databasecount;
        uint32 ipv4databaseaddr;
        uint32 ipv6databasecount;
        uint32 ipv6databaseaddr;
        uint32 ipv4indexbaseaddr;
        uint32 ipv6indexbaseaddr;

        struct in6_addr_local ReadIPv6Address(FILE *handle, uint32_t position)
        {
            int i, j;
            struct in6_addr_local addr6;
            for (i = 0, j = 15; i < 16; i++, j--)
            {
                addr6.u.addr8[i] = Read8(handle, position + j);
            }
            return addr6;
        }

        std::vector<IPLocation*> _ipLocation;
};

#define sIPLocation IPLocation::instance()

