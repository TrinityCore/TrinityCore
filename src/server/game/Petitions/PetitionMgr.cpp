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

#include "PetitionMgr.h"
#include "DatabaseEnv.h"
#include "Log.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "Timer.h"
#include "WorldSession.h"
#include <unordered_map>

namespace
{
    std::unordered_map<ObjectGuid, Petition> _petitionStore;
}

PetitionMgr* PetitionMgr::instance()
{
    static PetitionMgr instance;
    return &instance;
}

void PetitionMgr::LoadPetitions()
{
    uint32 oldMSTime = getMSTime();
    _petitionStore.clear();

    QueryResult result = CharacterDatabase.Query("SELECT petitionguid, ownerguid, name FROM petition");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 petitions.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();
        AddPetition(ObjectGuid::Create<HighGuid::Item>(fields[0].GetUInt64()), ObjectGuid::Create<HighGuid::Player>(fields[1].GetUInt64()), fields[2].GetString(), true);
        ++count;
    } while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded %u petitions in: %u ms.", count, GetMSTimeDiffToNow(oldMSTime));
}

void PetitionMgr::LoadSignatures()
{
    uint32 oldMSTime = getMSTime();

    QueryResult result = CharacterDatabase.Query("SELECT petitionguid, player_account, playerguid FROM petition_sign");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 Petition signs!");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        Petition* petition = GetPetition(ObjectGuid::Create<HighGuid::Item>(fields[0].GetUInt64()));
        if (!petition)
            continue;

        petition->AddSignature(fields[1].GetUInt32(), ObjectGuid::Create<HighGuid::Player>(fields[2].GetUInt64()), true);
        ++count;
    } while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded %u Petition signs in %u ms.", count, GetMSTimeDiffToNow(oldMSTime));
}

void PetitionMgr::AddPetition(ObjectGuid petitionGuid, ObjectGuid ownerGuid, std::string const& name, bool isLoading)
{
    Petition& p = _petitionStore[petitionGuid];
    p.PetitionGuid = petitionGuid;
    p.OwnerGuid = ownerGuid;
    p.PetitionName = name;
    p.Signatures.clear();

    if (isLoading)
        return;

    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_PETITION);
    stmt->setUInt64(0, ownerGuid.GetCounter());
    stmt->setUInt64(1, petitionGuid.GetCounter());
    stmt->setString(2, name);
    CharacterDatabase.Execute(stmt);
}

void PetitionMgr::RemovePetition(ObjectGuid petitionGuid)
{
    _petitionStore.erase(petitionGuid);

    // Delete From DB
    CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();

    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_PETITION_BY_GUID);
    stmt->setUInt64(0, petitionGuid.GetCounter());
    trans->Append(stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_PETITION_SIGNATURE_BY_GUID);
    stmt->setUInt64(0, petitionGuid.GetCounter());
    trans->Append(stmt);

    CharacterDatabase.CommitTransaction(trans);
}

Petition* PetitionMgr::GetPetition(ObjectGuid petitionGuid)
{
    auto itr = _petitionStore.find(petitionGuid);
    if (itr != _petitionStore.end())
        return &itr->second;

    return nullptr;
}

Petition* PetitionMgr::GetPetitionByOwner(ObjectGuid ownerGuid)
{
    for (auto& petitionPair : _petitionStore)
        if (petitionPair.second.OwnerGuid == ownerGuid)
            return &petitionPair.second;

    return nullptr;
}

void PetitionMgr::RemovePetitionsByOwner(ObjectGuid ownerGuid)
{
    for (auto itr = _petitionStore.begin(); itr != _petitionStore.end();)
    {
        if (itr->second.OwnerGuid == ownerGuid)
        {
            _petitionStore.erase(itr);
            break;
        }
        else
            ++itr;
    }

    CharacterDatabasePreparedStatement* stmt;
    CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();
    stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_PETITION_BY_OWNER);
    stmt->setUInt32(0, ownerGuid.GetCounter());
    trans->Append(stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_PETITION_SIGNATURE_BY_OWNER);
    stmt->setUInt32(0, ownerGuid.GetCounter());
    trans->Append(stmt);
    CharacterDatabase.CommitTransaction(trans);
}

void PetitionMgr::RemoveSignaturesBySigner(ObjectGuid signerGuid)
{
    for (auto& petitionPair : _petitionStore)
        petitionPair.second.RemoveSignatureBySigner(signerGuid);

    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_ALL_PETITION_SIGNATURES);
    stmt->setUInt32(0, signerGuid.GetCounter());
    CharacterDatabase.Execute(stmt);
}

bool Petition::IsPetitionSignedByAccount(uint32 accountId) const
{
    for (Signature const& signature : Signatures)
        if (signature.first == accountId)
            return true;

    return false;
}

void Petition::AddSignature(uint32 accountId, ObjectGuid playerGuid, bool isLoading)
{
    Signatures.emplace_back(accountId, playerGuid);

    if (isLoading)
        return;

    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_PETITION_SIGNATURE);

    stmt->setUInt64(0, OwnerGuid.GetCounter());
    stmt->setUInt64(1, PetitionGuid.GetCounter());
    stmt->setUInt64(2, playerGuid.GetCounter());
    stmt->setUInt32(3, accountId);

    CharacterDatabase.Execute(stmt);
}

void Petition::UpdateName(std::string const& newName)
{
    PetitionName = newName;

    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_PETITION_NAME);
    stmt->setString(0, newName);
    stmt->setUInt64(1, PetitionGuid.GetCounter());
    CharacterDatabase.Execute(stmt);
}

void Petition::RemoveSignatureBySigner(ObjectGuid playerGuid)
{
    for (auto itr = Signatures.begin(); itr != Signatures.end(); ++itr)
    {
        if (itr->second == playerGuid)
        {
            Signatures.erase(itr);

            // notify owner
            if (Player* owner = ObjectAccessor::FindConnectedPlayer(OwnerGuid))
                owner->GetSession()->SendPetitionQueryOpcode(PetitionGuid);

            break;
        }
    }
}
