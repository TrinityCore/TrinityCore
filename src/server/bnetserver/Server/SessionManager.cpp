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

#include "SessionManager.h"
#include "DatabaseEnv.h"
#include "SRP6.h"
#include "Util.h"

bool Battlenet::SessionManager::StartNetwork(Trinity::Asio::IoContext& ioContext, std::string const& bindIp, uint16 port, int threadCount)
{
    if (!BaseSocketMgr::StartNetwork(ioContext, bindIp, port, threadCount))
        return false;

    _acceptor->SetSocketFactory(std::bind(&BaseSocketMgr::GetSocketForAccept, this));
    _acceptor->AsyncAcceptWithCallback<&OnSocketAccept>();
    return true;
}

void Battlenet::SessionManager::FixLegacyAuthHashes()
{
    TC_LOG_INFO("server.bnetserver", "Updating password hashes...");
    uint32 const start = getMSTime();
    // the auth update query nulls salt/verifier if they cannot be converted
    // if they are non-null but s/v have been cleared, that means a legacy tool touched our auth DB (otherwise, the core might've done it itself, it used to use those hacks too)
    QueryResult result = LoginDatabase.Query("SELECT id, sha_pass_hash, IF((salt IS null) AND (verifier IS null), 0, 1) AS shouldWarn FROM account WHERE s != DEFAULT(s) OR v != DEFAULT(v) OR salt IS NULL OR verifier IS NULL");
    if (!result)
    {
        TC_LOG_INFO("server.bnetserver", ">> No password hashes to update - this took us %u ms to realize", GetMSTimeDiffToNow(start));
        return;
    }

    bool hadWarning = false;
    uint32 c = 0;
    LoginDatabaseTransaction tx = LoginDatabase.BeginTransaction();
    do
    {
        uint32 const id = (*result)[0].GetUInt32();
        std::pair<Trinity::Crypto::SRP6::Salt, Trinity::Crypto::SRP6::Verifier> registrationData = Trinity::Crypto::SRP6::MakeRegistrationDataFromHash_DEPRECATED_DONOTUSE(
            HexStrToByteArray<Trinity::Crypto::SHA1::DIGEST_LENGTH>((*result)[1].GetString())
        );

        if ((*result)[2].GetInt64() && !hadWarning)
        {
            hadWarning = true;
            TC_LOG_WARN("server.bnetserver", "(!) You appear to be using an outdated external account management tool.\n(!!) This is INSECURE, has been deprecated, and will cease to function entirely in the near future.\n(!) Update your external tool.\n(!!) If no update is available, refer your tool's developer to https://github.com/TrinityCore/TrinityCore/issues/25157.");
        }

        LoginDatabasePreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_UPD_LOGON);
        stmt->setBinary(0, registrationData.first);
        stmt->setBinary(1, registrationData.second);
        stmt->setUInt32(2, id);
        tx->Append(stmt);

        ++c;
    } while (result->NextRow());
    LoginDatabase.CommitTransaction(tx);

    TC_LOG_INFO("server.bnetserver", ">> %u password hashes updated in %u ms", c, GetMSTimeDiffToNow(start));
}

NetworkThread<Battlenet::Session>* Battlenet::SessionManager::CreateThreads() const
{
    return new NetworkThread<Session>[GetNetworkThreadCount()];
}

void Battlenet::SessionManager::OnSocketAccept(tcp::socket&& sock, uint32 threadIndex)
{
    sSessionMgr.OnSocketOpen(std::forward<tcp::socket>(sock), threadIndex);
}

Battlenet::SessionManager& Battlenet::SessionManager::Instance()
{
    static SessionManager instance;
    return instance;
}
