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

#include "IpBanCheckConnectionInitializer.h"
#include "DatabaseEnv.h"
#include "IpAddress.h"
#include "Log.h"

QueryCallback Trinity::Net::IpBanCheckHelpers::AsyncQuery(boost::asio::ip::address const& ipAddress)
{
    LoginDatabasePreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_SEL_IP_INFO);
    stmt->setString(0, ipAddress.to_string());
    return LoginDatabase.AsyncQuery(stmt);
}

bool Trinity::Net::IpBanCheckHelpers::IsBanned(PreparedQueryResult const& result)
{
    if (result)
    {
        do
        {
            Field* fields = result->Fetch();
            if (fields[0].GetUInt64() != 0)
                return true;

        } while (result->NextRow());
    }

    return false;
}

void Trinity::Net::IpBanCheckHelpers::LogFailure(boost::asio::ip::address const& ipAddress)
{
    TC_LOG_ERROR("network", "IpBanCheckConnectionInitializer: IP {} is banned.", ipAddress);
}
