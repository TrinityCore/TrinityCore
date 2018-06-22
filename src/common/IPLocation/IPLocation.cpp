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
#include "IpAddress.h"
#include "Log.h"
#include <fstream>
#include <iostream>

IpLocationStore::IpLocationStore()
{
}

IpLocationStore::~IpLocationStore()
{
}

void IpLocationStore::Load()
{
    std::string value = sConfigMgr->GetStringDefault("IPLocationFile", ".");
    if (value.empty())
        return;

    _ipLocationStore.clear();
    TC_LOG_INFO("server.loading", "Loading IP Location Database...");

    // Default folder
    if (!value.compare("."))
        value.append("/IP2LOCATION-LITE-DB1.CSV");

    // Check file name
    if (value.find("IP2LOCATION-LITE-DB1.CSV") == std::string::npos)
    {
        TC_LOG_ERROR("server.loading", "IPLocation:: File name is not valid, must be IP2LOCATION-LITE-DB1.CSV");
        return;
    }

    // Check if file exists
    std::ifstream ipfile(value);
    if (!ipfile)
    {
        TC_LOG_ERROR("server.loading", "IPLocation:: No database file exists.");
        return;
    }

    if (!ipfile.is_open())
    {
        TC_LOG_ERROR("server.loading", "IPLocation:: The file can not be opened.");
        return;
    }

    std::string ip_from;
    std::string ip_to;
    std::string country_code;
    std::string country_name;

    while (ipfile.good())
    {
        // Read lines
        std::getline(ipfile, ip_from, ',');
        std::getline(ipfile, ip_to, ',');
        std::getline(ipfile, country_code, ',');
        std::getline(ipfile, country_name, '\n');

        // Remove new lines and return
        country_name.erase(std::remove(country_name.begin(), country_name.end(), '\r'), country_name.end());
        country_name.erase(std::remove(country_name.begin(), country_name.end(), '\n'), country_name.end());

        // Remove quotation marks
        ip_from.erase(std::remove(ip_from.begin(), ip_from.end(), '"'), ip_from.end());
        ip_to.erase(std::remove(ip_to.begin(), ip_to.end(), '"'), ip_to.end());
        country_code.erase(std::remove(country_code.begin(), country_code.end(), '"'), country_code.end());
        country_name.erase(std::remove(country_name.begin(), country_name.end(), '"'), country_name.end());

        // Convert country code to lowercase
        std::transform(country_code.begin(), country_code.end(), country_code.begin(), ::tolower);

        IpLocationRecord data;
        data.ip_from        = (uint32)atoull(ip_from.c_str());
        data.ip_to          = (uint32)atoull(ip_to.c_str());
        data.country_code   = country_code;
        data.country_name   = country_name;

        _ipLocationStore.push_back(data);
    }

    std::sort(_ipLocationStore.begin(), _ipLocationStore.end(), [](IpLocationRecord const& a, IpLocationRecord const& b) { return a.ip_from < b.ip_from; });

    ipfile.close();

    TC_LOG_INFO("server.loading", ">> Loaded %u entries.", uint32(_ipLocationStore.size()));
}

IpLocationRecord* IpLocationStore::GetData(std::string const& ipAddress)
{
    if (_ipLocationStore.empty())
        return nullptr;

    uint32 ip = Trinity::Net::address_to_uint(Trinity::Net::make_address_v4(ipAddress));
    auto itr = std::upper_bound(_ipLocationStore.begin(), _ipLocationStore.end(), ip, [](uint32 ip, IpLocationRecord const& loc) { return loc.ip_to >= ip; });
    ASSERT(&(*itr));

    return &(*itr);
}

IpLocationStore* IpLocationStore::instance()
{
    static IpLocationStore instance;
    return &instance;
}
