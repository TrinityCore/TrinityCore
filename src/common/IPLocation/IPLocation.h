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

#ifndef IPLOCATION_H
#define IPLOCATION_H

#include "Define.h"
#include <array>
#include <string>
#include <vector>

struct IpLocationRecord
{
    IpLocationRecord() : IpFrom(), IpTo() { }
    IpLocationRecord(std::array<uint8, 16> ipFrom, std::array<uint8, 16> ipTo, std::string&& countryCode, std::string&& countryName)
        : IpFrom(ipFrom), IpTo(ipTo), CountryCode(std::move(countryCode)), CountryName(std::move(countryName)) { }

    std::array<uint8, 16> IpFrom;
    std::array<uint8, 16> IpTo;
    std::string CountryCode;
    std::string CountryName;
};

class TC_COMMON_API IpLocationStore
{
    public:
        IpLocationStore();
        IpLocationStore(IpLocationStore const&) = delete;
        IpLocationStore(IpLocationStore&&) = delete;
        IpLocationStore& operator=(IpLocationStore const&) = delete;
        IpLocationStore& operator=(IpLocationStore&&) = delete;
        ~IpLocationStore();
        static IpLocationStore* Instance();

        void Load();
        IpLocationRecord const* GetLocationRecord(std::string const& ipAddress) const;

    private:
        std::vector<IpLocationRecord> _ipLocationStore;
};

#define sIPLocation IpLocationStore::Instance()

#endif
