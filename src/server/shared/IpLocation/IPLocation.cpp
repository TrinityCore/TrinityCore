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

#include "IPLocation.h"
#include "BigNumber.h"
#include "Config.h"
#include "Errors.h"
#include "IpAddress.h"
#include "Log.h"
#include "Util.h"
#include <algorithm>
#include <fstream>

IpLocationStore::IpLocationStore() = default;
IpLocationStore::~IpLocationStore() = default;

void IpLocationStore::Load()
{
    _ipLocationStore.clear();
    TC_LOG_INFO("server.loading", "Loading IP Location Database...");

    std::string databaseFilePath = sConfigMgr->GetStringDefault("IPLocationFile", "");
    if (databaseFilePath.empty())
        return;

    // Check if file exists
    std::ifstream databaseFile(databaseFilePath);
    if (!databaseFile)
    {
        TC_LOG_ERROR("server.loading", "IPLocation: No ip database file exists ({}).", databaseFilePath);
        return;
    }

    if (!databaseFile.is_open())
    {
        TC_LOG_ERROR("server.loading", "IPLocation: Ip database file ({}) can not be opened.", databaseFilePath);
        return;
    }

    std::string ipFrom;
    std::string ipTo;
    std::string countryCode;
    std::string countryName;
    BigNumber bnParser;
    BigNumber ipv4Max(0xFFFFFFFF);
    BigNumber ipv6MappedMask(0xFFFF);
    ipv6MappedMask <<= 32;

    auto parseStringToIPv6 = [&](std::string const& str) -> Optional<std::array<uint8, 16>>
    {
        bnParser.SetDecStr(str);
        if (!bnParser.SetDecStr(str))
            return {};
        // convert ipv4 to ipv6 v4 mapped value
        if (bnParser <= ipv4Max)
            bnParser += ipv6MappedMask;
        return bnParser.ToByteArray<16>(false);
    };

    while (databaseFile.good())
    {
        // Read lines
        if (!std::getline(databaseFile, ipFrom, ','))
            break;
        if (!std::getline(databaseFile, ipTo, ','))
            break;
        if (!std::getline(databaseFile, countryCode, ','))
            break;
        if (!std::getline(databaseFile, countryName, '\n'))
            break;

        // Remove new lines and return
        std::erase_if(countryName, [](char c) { return c == '\r' || c == '\n'; });

        // Remove quotation marks
        std::erase(ipFrom, '"');
        std::erase(ipTo, '"');
        std::erase(countryCode, '"');
        std::erase(countryName, '"');

        if (countryCode == "-")
            continue;

        // Convert country code to lowercase
        strToLower(countryCode);

        Optional<std::array<uint8, 16>> from = parseStringToIPv6(ipFrom);
        if (!from)
            continue;

        Optional<std::array<uint8, 16>> to = parseStringToIPv6(ipTo);
        if (!to)
            continue;

        _ipLocationStore.emplace_back(*from, *to, std::move(countryCode), std::move(countryName));
    }

    std::ranges::sort(_ipLocationStore, {}, &IpLocationRecord::IpFrom);
    ASSERT(std::ranges::is_sorted(_ipLocationStore, [](IpLocationRecord const& a, IpLocationRecord const& b) { return a.IpFrom < b.IpTo; }),
        "Overlapping IP ranges detected in database file");

    databaseFile.close();

    TC_LOG_INFO("server.loading", ">> Loaded {} ip location entries.", _ipLocationStore.size());
}

IpLocationRecord const* IpLocationStore::GetLocationRecord(std::string const& ipAddress) const
{
    boost::system::error_code error;
    boost::asio::ip::address address = Trinity::Net::make_address(ipAddress, error);
    if (error)
        return nullptr;

    std::array<uint8, 16> bytes = [&]() -> std::array<uint8, 16>
    {
        if (address.is_v6())
            return address.to_v6().to_bytes();
        if (address.is_v4())
            return Trinity::Net::make_address_v6(Trinity::Net::v4_mapped, address.to_v4()).to_bytes();
        return {};
    }();
    auto itr = std::ranges::upper_bound(_ipLocationStore, bytes, {}, &IpLocationRecord::IpTo);
    if (itr == _ipLocationStore.end())
        return nullptr;

    if (bytes < itr->IpFrom)
        return nullptr;

    return &(*itr);
}

IpLocationStore* IpLocationStore::Instance()
{
    static IpLocationStore instance;
    return &instance;
}
