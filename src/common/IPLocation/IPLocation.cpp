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
#include <fstream>
#include <iostream>

IPLocation::IPLocation()
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

    _ipLocationStore.clear();
    TC_LOG_INFO("server.loading", "Loading IP Location Database...");

    // Check file extension
    std::string extension = value.substr(value.find_last_of('.') + 1);
    std::transform(extension.begin(), extension.end(), extension.begin(), ::tolower);
    if (extension != "csv")
    {
        TC_LOG_INFO("server.loading", "IPLocation:: File extension is not valid, must be .CSV extension");
        return;
    }

    std::ifstream ipfile(value);
    if (!ipfile.is_open())
    {
        TC_LOG_INFO("server.loading", "IPLocation:: No database file exists.");
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

        // Remove quotation marks
        ip_from.erase(std::remove(ip_from.begin(), ip_from.end(), '"'), ip_from.end());
        ip_to.erase(std::remove(ip_to.begin(), ip_to.end(), '"'), ip_to.end());
        country_code.erase(std::remove(country_code.begin(), country_code.end(), '"'), country_code.end());
        country_name.erase(std::remove(country_name.begin(), country_name.end(), '"'), country_name.end());

        // Convert country code to lowercase
        std::transform(country_code.begin(), country_code.end(), country_code.begin(), ::tolower);

        Iplocation data;
        data.ip_from        = (uint64)_atoi64(ip_from.c_str());;
        data.ip_to          = (uint64)_atoi64(ip_to.c_str());;
        data.country_code   = country_code;
        data.country_name   = country_name;

        _ipLocationStore.push_back(data);
    }

    ipfile.close();

    TC_LOG_INFO("server.loading", ">> Loaded %u entries.", _ipLocationStore.size());
}

Iplocation* IPLocation::GetData(std::string const& ipAddress)
{
    if (_ipLocationStore.empty())
        return nullptr;

    uint64 ip = Trinity::Net::address_to_uint(Trinity::Net::make_address_v4(ipAddress));
    for (auto itr = _ipLocationStore.begin(); itr != _ipLocationStore.end(); ++itr)
    {
        if (itr->ip_from <= ip && itr->ip_to >= ip)
            return &(*itr);
    }

    return nullptr;
}

IPLocation* IPLocation::instance()
{
    static IPLocation instance;
    return &instance;
}
