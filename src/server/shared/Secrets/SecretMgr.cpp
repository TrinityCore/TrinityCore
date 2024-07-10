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

#include "SecretMgr.h"
#include "AES.h"
#include "Argon2Hash.h"
#include "Config.h"
#include "CryptoGenerics.h"
#include "DatabaseEnv.h"
#include "Errors.h"
#include "Log.h"

#define SECRET_FLAG_FOR(key, val, server) server ## _ ## key = (val ## ull << (16*SECRET_OWNER_ ## server))
#define SECRET_FLAG(key, val) SECRET_FLAG_ ## key = val, SECRET_FLAG_FOR(key, val, BNETSERVER), SECRET_FLAG_FOR(key, val, WORLDSERVER)
enum SecretFlags : uint64
{
    SECRET_FLAG(DEFER_LOAD, 0x1)
};
#undef SECRET_FLAG_FOR
#undef SECRET_FLAG

struct SecretInfo
{
    char const* configKey;
    char const* oldKey;
    int bits;
    SecretOwner owner;
    uint64 _flags;
    uint16 flags() const { return static_cast<uint16>(_flags >> (16*SecretMgr::OWNER)); }
};

static constexpr SecretInfo secret_info[NUM_SECRETS] =
{
    { "TOTPMasterSecret", "TOTPOldMasterSecret", 128, SECRET_OWNER_BNETSERVER, WORLDSERVER_DEFER_LOAD }
};

SecretOwner SecretMgr::OWNER;

/*static*/ SecretMgr* SecretMgr::instance()
{
    static SecretMgr instance;
    return &instance;
}

static Optional<BigNumber> GetHexFromConfig(char const* configKey, int bits)
{
    ASSERT(bits > 0);
    std::string str = sConfigMgr->GetStringDefault(configKey, "");
    if (str.empty())
        return {};

    BigNumber secret;
    if (!secret.SetHexStr(str.c_str()))
    {
        TC_LOG_FATAL("server.loading", "Invalid value for '{}' - specify a hexadecimal integer of up to {} bits with no prefix.", configKey, bits);
        ABORT();
    }

    BigNumber threshold(2);
    threshold <<= bits;
    if (!((BigNumber(0) <= secret) && (secret < threshold)))
    {
        TC_LOG_ERROR("server.loading", "Value for '{}' is out of bounds (should be an integer of up to {} bits with no prefix). Truncated to {} bits.", configKey, bits, bits);
        secret %= threshold;
    }
    ASSERT(((BigNumber(0) <= secret) && (secret < threshold)));

    return secret;
}

void SecretMgr::Initialize(SecretOwner owner)
{
    OWNER = owner;

    for (uint32 i = 0; i < NUM_SECRETS; ++i)
    {
        if (secret_info[i].flags() & SECRET_FLAG_DEFER_LOAD)
            continue;
        std::unique_lock<std::mutex> lock(_secrets[i].lock);
        AttemptLoad(Secrets(i), LOG_LEVEL_FATAL, lock);
        if (!_secrets[i].IsAvailable())
            ABORT(); // load failed
    }
}

SecretMgr::Secret const& SecretMgr::GetSecret(Secrets i)
{
    std::unique_lock<std::mutex> lock(_secrets[i].lock);

    if (_secrets[i].state == Secret::NOT_LOADED_YET)
        AttemptLoad(i, LOG_LEVEL_ERROR, lock);
    return _secrets[i];
}

void SecretMgr::AttemptLoad(Secrets i, LogLevel errorLevel, std::unique_lock<std::mutex> const&)
{
    auto const& info = secret_info[i];
    Optional<std::string> oldDigest;
    {
        LoginDatabasePreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_SEL_SECRET_DIGEST);
        stmt->setUInt32(0, i);
        PreparedQueryResult result = LoginDatabase.Query(stmt);
        if (result)
            oldDigest = result->Fetch()->GetString();
    }
    Optional<BigNumber> currentValue = GetHexFromConfig(info.configKey, info.bits);

    // verify digest
    if (
        ((!oldDigest) != (!currentValue)) || // there is an old digest, but no current secret (or vice versa)
        (oldDigest && !Trinity::Crypto::Argon2::Verify(currentValue->AsHexStr(), *oldDigest)) // there is an old digest, and the current secret does not match it
        )
    {
        if (info.owner != OWNER)
        {
            if (currentValue)
                TC_LOG_MESSAGE_BODY("server.loading", errorLevel, "Invalid value for '{}' specified - this is not actually the secret being used in your auth DB.", info.configKey);
            else
                TC_LOG_MESSAGE_BODY("server.loading", errorLevel, "No value for '{}' specified - please specify the secret currently being used in your auth DB.", info.configKey);
            _secrets[i].state = Secret::LOAD_FAILED;
            return;
        }

        Optional<BigNumber> oldSecret;
        if (oldDigest && info.oldKey) // there is an old digest, so there might be an old secret (if possible)
        {
            oldSecret = GetHexFromConfig(info.oldKey, info.bits);
            if (oldSecret && !Trinity::Crypto::Argon2::Verify(oldSecret->AsHexStr(), *oldDigest))
            {
                TC_LOG_MESSAGE_BODY("server.loading", errorLevel, "Invalid value for '{}' specified - this is not actually the secret previously used in your auth DB.", info.oldKey);
                _secrets[i].state = Secret::LOAD_FAILED;
                return;
            }
        }

        // attempt to transition us to the new key, if possible
        Optional<std::string> error = AttemptTransition(Secrets(i), currentValue, oldSecret, !!oldDigest);
        if (error)
        {
            TC_LOG_MESSAGE_BODY("server.loading", errorLevel, "Your value of '{}' changed, but we cannot transition your database to the new value:\n{}", info.configKey, error->c_str());
            _secrets[i].state = Secret::LOAD_FAILED;
            return;
        }

        TC_LOG_INFO("server.loading", "Successfully transitioned database to new '{}' value.", info.configKey);
    }

    if (currentValue)
    {
        _secrets[i].state = Secret::PRESENT;
        _secrets[i].value = *currentValue;
    }
    else
        _secrets[i].state = Secret::NOT_PRESENT;
}

Optional<std::string> SecretMgr::AttemptTransition(Secrets i, Optional<BigNumber> const& newSecret, Optional<BigNumber> const& oldSecret, bool hadOldSecret) const
{
    LoginDatabaseTransaction trans = LoginDatabase.BeginTransaction();

    switch (i)
    {
        case SECRET_TOTP_MASTER_KEY:
        {
            QueryResult result = LoginDatabase.Query("SELECT id, totp_secret FROM account");
            if (result) do
            {
                Field* fields = result->Fetch();
                if (fields[1].IsNull())
                    continue;

                uint32 id = fields[0].GetUInt32();
                std::vector<uint8> totpSecret = fields[1].GetBinary();

                if (hadOldSecret)
                {
                    if (!oldSecret)
                        return Trinity::StringFormat("Cannot decrypt old TOTP tokens - add config key '{}' to authserver.conf!", secret_info[i].oldKey);

                    bool success = Trinity::Crypto::AEDecrypt<Trinity::Crypto::AES>(totpSecret, oldSecret->ToByteArray<Trinity::Crypto::AES::KEY_SIZE_BYTES>());
                    if (!success)
                        return Trinity::StringFormat("Cannot decrypt old TOTP tokens - value of '{}' is incorrect for some users!", secret_info[i].oldKey);
                }

                if (newSecret)
                    Trinity::Crypto::AEEncryptWithRandomIV<Trinity::Crypto::AES>(totpSecret, newSecret->ToByteArray<Trinity::Crypto::AES::KEY_SIZE_BYTES>());

                LoginDatabasePreparedStatement* updateStmt = LoginDatabase.GetPreparedStatement(LOGIN_UPD_ACCOUNT_TOTP_SECRET);
                updateStmt->setBinary(0, totpSecret);
                updateStmt->setUInt32(1, id);
                trans->Append(updateStmt);
            } while (result->NextRow());

            break;
        }
        default:
            return std::string("Unknown secret index - huh?");
    }

    if (hadOldSecret)
    {
        LoginDatabasePreparedStatement* deleteStmt = LoginDatabase.GetPreparedStatement(LOGIN_DEL_SECRET_DIGEST);
        deleteStmt->setUInt32(0, i);
        trans->Append(deleteStmt);
    }

    if (newSecret)
    {
        BigNumber salt;
        salt.SetRand(128);
        Optional<std::string> hash = Trinity::Crypto::Argon2::Hash(newSecret->AsHexStr(), salt);
        if (!hash)
            return std::string("Failed to hash new secret");

        LoginDatabasePreparedStatement* insertStmt = LoginDatabase.GetPreparedStatement(LOGIN_INS_SECRET_DIGEST);
        insertStmt->setUInt32(0, i);
        insertStmt->setString(1, *hash);
        trans->Append(insertStmt);
    }

    LoginDatabase.CommitTransaction(trans);
    return {};
}
