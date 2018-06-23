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
#include <vector>

struct IpLocationRecord
{
    uint32 ip_from;
    uint32 ip_to;
    std::string country_code;
    std::string country_name;
};

class TC_COMMON_API IpLocationStore
{
    public:
        IpLocationStore();
        ~IpLocationStore();
        static IpLocationStore* instance();

        void Load();
        IpLocationRecord* GetData(std::string const& ipAddress);

    private:
        std::vector<IpLocationRecord> _ipLocationStore;
};

#define sIPLocation IpLocationStore::instance()
