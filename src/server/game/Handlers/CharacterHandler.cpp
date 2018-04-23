/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
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

#include "WorldSession.h"
#include "AccountMgr.h"
#include "ArenaTeam.h"
#include "ArenaTeamMgr.h"
#include "AuthenticationPackets.h"
#include "Battleground.h"
#include "BattlegroundPackets.h"
#include "BattlePetPackets.h"
#include "CalendarMgr.h"
#include "CharacterPackets.h"
#include "Chat.h"
#include "ClientConfigPackets.h"
#include "Common.h"
#include "DatabaseEnv.h"
#include "DB2Stores.h"
#include "EquipmentSetPackets.h"
#include "GameObject.h"
#include "GitRevision.h"
#include "Group.h"
#include "Guild.h"
#include "GuildFinderMgr.h"
#include "GuildMgr.h"
#include "Item.h"
#include "Language.h"
#include "Log.h"
#include "Map.h"
#include "Metric.h"
#include "MiscPackets.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "Pet.h"
#include "Player.h"
#include "PlayerDump.h"
#include "QueryHolder.h"
#include "QueryPackets.h"
#include "Realm.h"
#include "ReputationMgr.h"
#include "ScriptMgr.h"
#include "SharedDefines.h"
#include "SocialMgr.h"
#include "SystemPackets.h"
#include "Util.h"
#include "World.h"

class LoginQueryHolder : public SQLQueryHolder
{
    private:
        uint32 m_accountId;
        ObjectGuid m_guid;
    public:
        LoginQueryHolder(uint32 accountId, ObjectGuid guid)
            : m_accountId(accountId), m_guid(guid) { }
        ObjectGuid GetGuid() const { return m_guid; }
        uint32 GetAccountId() const { return m_accountId; }
        bool Initialize();
};

bool LoginQueryHolder::Initialize()
{
    SetSize(MAX_PLAYER_LOGIN_QUERY);

    bool res = true;
    ObjectGuid::LowType lowGuid = m_guid.GetCounter();

    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHARACTER);
    stmt->setUInt64(0, lowGuid);
    res &= SetPreparedQuery(PLAYER_LOGIN_QUERY_LOAD_FROM, stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_GROUP_MEMBER);
    stmt->setUInt64(0, lowGuid);
    res &= SetPreparedQuery(PLAYER_LOGIN_QUERY_LOAD_GROUP, stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHARACTER_INSTANCE);
    stmt->setUInt64(0, lowGuid);
    res &= SetPreparedQuery(PLAYER_LOGIN_QUERY_LOAD_BOUND_INSTANCES, stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHARACTER_AURAS);
    stmt->setUInt64(0, lowGuid);
    res &= SetPreparedQuery(PLAYER_LOGIN_QUERY_LOAD_AURAS, stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHARACTER_AURA_EFFECTS);
    stmt->setUInt64(0, lowGuid);
    res &= SetPreparedQuery(PLAYER_LOGIN_QUERY_LOAD_AURA_EFFECTS, stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHARACTER_SPELL);
    stmt->setUInt64(0, lowGuid);
    res &= SetPreparedQuery(PLAYER_LOGIN_QUERY_LOAD_SPELLS, stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHARACTER_QUESTSTATUS);
    stmt->setUInt64(0, lowGuid);
    res &= SetPreparedQuery(PLAYER_LOGIN_QUERY_LOAD_QUEST_STATUS, stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHARACTER_QUESTSTATUS_OBJECTIVES);
    stmt->setUInt64(0, lowGuid);
    res &= SetPreparedQuery(PLAYER_LOGIN_QUERY_LOAD_QUEST_STATUS_OBJECTIVES, stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHARACTER_QUESTSTATUS_OBJECTIVES_CRITERIA);
    stmt->setUInt64(0, lowGuid);
    res &= SetPreparedQuery(PLAYER_LOGIN_QUERY_LOAD_QUEST_STATUS_OBJECTIVES_CRITERIA, stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHARACTER_QUESTSTATUS_OBJECTIVES_CRITERIA_PROGRESS);
    stmt->setUInt64(0, lowGuid);
    res &= SetPreparedQuery(PLAYER_LOGIN_QUERY_LOAD_QUEST_STATUS_OBJECTIVES_CRITERIA_PROGRESS, stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHARACTER_QUESTSTATUS_DAILY);
    stmt->setUInt64(0, lowGuid);
    res &= SetPreparedQuery(PLAYER_LOGIN_QUERY_LOAD_DAILY_QUEST_STATUS, stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHARACTER_QUESTSTATUS_WEEKLY);
    stmt->setUInt64(0, lowGuid);
    res &= SetPreparedQuery(PLAYER_LOGIN_QUERY_LOAD_WEEKLY_QUEST_STATUS, stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHARACTER_QUESTSTATUS_MONTHLY);
    stmt->setUInt64(0, lowGuid);
    res &= SetPreparedQuery(PLAYER_LOGIN_QUERY_LOAD_MONTHLY_QUEST_STATUS, stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHARACTER_QUESTSTATUS_SEASONAL);
    stmt->setUInt64(0, lowGuid);
    res &= SetPreparedQuery(PLAYER_LOGIN_QUERY_LOAD_SEASONAL_QUEST_STATUS, stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHARACTER_REPUTATION);
    stmt->setUInt64(0, lowGuid);
    res &= SetPreparedQuery(PLAYER_LOGIN_QUERY_LOAD_REPUTATION, stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHARACTER_INVENTORY);
    stmt->setUInt64(0, lowGuid);
    res &= SetPreparedQuery(PLAYER_LOGIN_QUERY_LOAD_INVENTORY, stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_ITEM_INSTANCE_ARTIFACT);
    stmt->setUInt64(0, lowGuid);
    res &= SetPreparedQuery(PLAYER_LOGIN_QUERY_LOAD_ARTIFACTS, stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHAR_VOID_STORAGE);
    stmt->setUInt64(0, lowGuid);
    res &= SetPreparedQuery(PLAYER_LOGIN_QUERY_LOAD_VOID_STORAGE, stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHARACTER_ACTIONS);
    stmt->setUInt64(0, lowGuid);
    res &= SetPreparedQuery(PLAYER_LOGIN_QUERY_LOAD_ACTIONS, stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHARACTER_MAILCOUNT);
    stmt->setUInt64(0, lowGuid);
    stmt->setUInt64(1, uint64(time(NULL)));
    res &= SetPreparedQuery(PLAYER_LOGIN_QUERY_LOAD_MAIL_COUNT, stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHARACTER_MAILDATE);
    stmt->setUInt64(0, lowGuid);
    res &= SetPreparedQuery(PLAYER_LOGIN_QUERY_LOAD_MAIL_DATE, stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHARACTER_SOCIALLIST);
    stmt->setUInt64(0, lowGuid);
    res &= SetPreparedQuery(PLAYER_LOGIN_QUERY_LOAD_SOCIAL_LIST, stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHARACTER_HOMEBIND);
    stmt->setUInt64(0, lowGuid);
    res &= SetPreparedQuery(PLAYER_LOGIN_QUERY_LOAD_HOME_BIND, stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHARACTER_SPELLCOOLDOWNS);
    stmt->setUInt64(0, lowGuid);
    res &= SetPreparedQuery(PLAYER_LOGIN_QUERY_LOAD_SPELL_COOLDOWNS, stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHARACTER_SPELL_CHARGES);
    stmt->setUInt64(0, lowGuid);
    res &= SetPreparedQuery(PLAYER_LOGIN_QUERY_LOAD_SPELL_CHARGES, stmt);

    if (sWorld->getBoolConfig(CONFIG_DECLINED_NAMES_USED))
    {
        stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHARACTER_DECLINEDNAMES);
        stmt->setUInt64(0, lowGuid);
        res &= SetPreparedQuery(PLAYER_LOGIN_QUERY_LOAD_DECLINED_NAMES, stmt);
    }

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_GUILD_MEMBER);
    stmt->setUInt64(0, lowGuid);
    res &= SetPreparedQuery(PLAYER_LOGIN_QUERY_LOAD_GUILD, stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHARACTER_ARENAINFO);
    stmt->setUInt64(0, lowGuid);
    res &= SetPreparedQuery(PLAYER_LOGIN_QUERY_LOAD_ARENA_INFO, stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHARACTER_ACHIEVEMENTS);
    stmt->setUInt64(0, lowGuid);
    res &= SetPreparedQuery(PLAYER_LOGIN_QUERY_LOAD_ACHIEVEMENTS, stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHARACTER_CRITERIAPROGRESS);
    stmt->setUInt64(0, lowGuid);
    res &= SetPreparedQuery(PLAYER_LOGIN_QUERY_LOAD_CRITERIA_PROGRESS, stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHARACTER_EQUIPMENTSETS);
    stmt->setUInt64(0, lowGuid);
    res &= SetPreparedQuery(PLAYER_LOGIN_QUERY_LOAD_EQUIPMENT_SETS, stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHARACTER_TRANSMOG_OUTFITS);
    stmt->setUInt64(0, lowGuid);
    res &= SetPreparedQuery(PLAYER_LOGIN_QUERY_LOAD_TRANSMOG_OUTFITS, stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHAR_CUF_PROFILES);
    stmt->setUInt64(0, lowGuid);
    res &= SetPreparedQuery(PLAYER_LOGIN_QUERY_LOAD_CUF_PROFILES, stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHARACTER_BGDATA);
    stmt->setUInt64(0, lowGuid);
    res &= SetPreparedQuery(PLAYER_LOGIN_QUERY_LOAD_BG_DATA, stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHARACTER_GLYPHS);
    stmt->setUInt64(0, lowGuid);
    res &= SetPreparedQuery(PLAYER_LOGIN_QUERY_LOAD_GLYPHS, stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHARACTER_TALENTS);
    stmt->setUInt64(0, lowGuid);
    res &= SetPreparedQuery(PLAYER_LOGIN_QUERY_LOAD_TALENTS, stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHARACTER_PVP_TALENTS);
    stmt->setUInt64(0, lowGuid);
    res &= SetPreparedQuery(PLAYER_LOGIN_QUERY_LOAD_PVP_TALENTS, stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_PLAYER_ACCOUNT_DATA);
    stmt->setUInt64(0, lowGuid);
    res &= SetPreparedQuery(PLAYER_LOGIN_QUERY_LOAD_ACCOUNT_DATA, stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHARACTER_SKILLS);
    stmt->setUInt64(0, lowGuid);
    res &= SetPreparedQuery(PLAYER_LOGIN_QUERY_LOAD_SKILLS, stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHARACTER_RANDOMBG);
    stmt->setUInt64(0, lowGuid);
    res &= SetPreparedQuery(PLAYER_LOGIN_QUERY_LOAD_RANDOM_BG, stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHARACTER_BANNED);
    stmt->setUInt64(0, lowGuid);
    res &= SetPreparedQuery(PLAYER_LOGIN_QUERY_LOAD_BANNED, stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHARACTER_QUESTSTATUSREW);
    stmt->setUInt64(0, lowGuid);
    res &= SetPreparedQuery(PLAYER_LOGIN_QUERY_LOAD_QUEST_STATUS_REW, stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_ACCOUNT_INSTANCELOCKTIMES);
    stmt->setUInt32(0, m_accountId);
    res &= SetPreparedQuery(PLAYER_LOGIN_QUERY_LOAD_INSTANCE_LOCK_TIMES, stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_PLAYER_CURRENCY);
    stmt->setUInt64(0, lowGuid);
    res &= SetPreparedQuery(PLAYER_LOGIN_QUERY_LOAD_CURRENCY, stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CORPSE_LOCATION);
    stmt->setUInt64(0, lowGuid);
    res &= SetPreparedQuery(PLAYER_LOGIN_QUERY_LOAD_CORPSE_LOCATION, stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHARACTER_GARRISON);
    stmt->setUInt64(0, lowGuid);
    res &= SetPreparedQuery(PLAYER_LOGIN_QUERY_LOAD_GARRISON, stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHARACTER_GARRISON_BLUEPRINTS);
    stmt->setUInt64(0, lowGuid);
    res &= SetPreparedQuery(PLAYER_LOGIN_QUERY_LOAD_GARRISON_BLUEPRINTS, stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHARACTER_GARRISON_BUILDINGS);
    stmt->setUInt64(0, lowGuid);
    res &= SetPreparedQuery(PLAYER_LOGIN_QUERY_LOAD_GARRISON_BUILDINGS, stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHARACTER_GARRISON_FOLLOWERS);
    stmt->setUInt64(0, lowGuid);
    res &= SetPreparedQuery(PLAYER_LOGIN_QUERY_LOAD_GARRISON_FOLLOWERS, stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHARACTER_GARRISON_FOLLOWER_ABILITIES);
    stmt->setUInt64(0, lowGuid);
    res &= SetPreparedQuery(PLAYER_LOGIN_QUERY_LOAD_GARRISON_FOLLOWER_ABILITIES, stmt);

    return res;
}

void WorldSession::HandleCharEnum(PreparedQueryResult result)
{
    uint8 demonHunterCount = 0; // We use this counter to allow multiple demon hunter creations when allowed in config
    bool canAlwaysCreateDemonHunter = HasPermission(rbac::RBAC_PERM_SKIP_CHECK_CHARACTER_CREATION_DEMON_HUNTER);
    if (sWorld->getIntConfig(CONFIG_CHARACTER_CREATING_MIN_LEVEL_FOR_DEMON_HUNTER) == 0) // char level = 0 means this check is disabled, so always true
        canAlwaysCreateDemonHunter = true;
    WorldPackets::Character::EnumCharactersResult charEnum;
    charEnum.Success = true;
    charEnum.IsDeletedCharacters = false;
    charEnum.DisabledClassesMask = sWorld->getIntConfig(CONFIG_CHARACTER_CREATING_DISABLED_CLASSMASK);

    _legitCharacters.clear();

    if (result)
    {
        do
        {
            charEnum.Characters.emplace_back(result->Fetch());

            WorldPackets::Character::EnumCharactersResult::CharacterInfo& charInfo = charEnum.Characters.back();

            TC_LOG_INFO("network", "Loading char guid %s from account %u.", charInfo.Guid.ToString().c_str(), GetAccountId());

            if (!Player::ValidateAppearance(charInfo.Race, charInfo.Class, charInfo.Sex, charInfo.HairStyle, charInfo.HairColor, charInfo.Face, charInfo.FacialHair, charInfo.Skin, charInfo.CustomDisplay))
            {
                TC_LOG_ERROR("entities.player.loading", "Player %s has wrong Appearance values (Hair/Skin/Color), forcing recustomize", charInfo.Guid.ToString().c_str());

                // Make sure customization always works properly - send all zeroes instead
                charInfo.Skin = 0, charInfo.Face = 0, charInfo.HairStyle = 0, charInfo.HairColor = 0, charInfo.FacialHair = 0;

                if (!(charInfo.CustomizationFlag == CHAR_CUSTOMIZE_FLAG_CUSTOMIZE))
                {
                    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_ADD_AT_LOGIN_FLAG);
                    stmt->setUInt16(0, uint16(AT_LOGIN_CUSTOMIZE));
                    stmt->setUInt64(1, charInfo.Guid.GetCounter());
                    CharacterDatabase.Execute(stmt);
                    charInfo.CustomizationFlag = CHAR_CUSTOMIZE_FLAG_CUSTOMIZE;
                }
            }

            // Do not allow locked characters to login
            if (!(charInfo.Flags & (CHARACTER_FLAG_LOCKED_FOR_TRANSFER | CHARACTER_FLAG_LOCKED_BY_BILLING)))
                _legitCharacters.insert(charInfo.Guid);

            if (!sWorld->HasCharacterInfo(charInfo.Guid)) // This can happen if characters are inserted into the database manually. Core hasn't loaded name data yet.
                sWorld->AddCharacterInfo(charInfo.Guid, GetAccountId(), charInfo.Name, charInfo.Sex, charInfo.Race, charInfo.Class, charInfo.Level, false);

            if (charInfo.Class == CLASS_DEMON_HUNTER)
                demonHunterCount++;

            if (demonHunterCount >= sWorld->getIntConfig(CONFIG_DEMON_HUNTERS_PER_REALM) && !canAlwaysCreateDemonHunter)
                charEnum.HasDemonHunterOnRealm = true;
            else
                charEnum.HasDemonHunterOnRealm = false;

            charEnum.MaxCharacterLevel = std::max<int32>(charEnum.MaxCharacterLevel, charInfo.Level);
        }
        while (result->NextRow());
    }

    charEnum.IsDemonHunterCreationAllowed = GetAccountExpansion() >= EXPANSION_LEGION || canAlwaysCreateDemonHunter;
    charEnum.IsAlliedRacesCreationAllowed = GetAccountExpansion() >= EXPANSION_BATTLE_FOR_AZEROTH;

    for (std::pair<uint8 const, RaceUnlockRequirement> const& requirement : sObjectMgr->GetRaceUnlockRequirements())
    {
        WorldPackets::Character::EnumCharactersResult::RaceUnlock raceUnlock;
        raceUnlock.RaceID = requirement.first;
        raceUnlock.HasExpansion = GetAccountExpansion() >= requirement.second.Expansion;
        charEnum.RaceUnlockData.push_back(raceUnlock);
    }

    SendPacket(charEnum.Write());
}

void WorldSession::HandleCharEnumOpcode(WorldPackets::Character::EnumCharacters& /*enumCharacters*/)
{
    // remove expired bans
    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_EXPIRED_BANS);
    CharacterDatabase.Execute(stmt);

    /// get all the data necessary for loading all characters (along with their pets) on the account

    if (sWorld->getBoolConfig(CONFIG_DECLINED_NAMES_USED))
        stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_ENUM_DECLINED_NAME);
    else
        stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_ENUM);

    stmt->setUInt8(0, PET_SAVE_AS_CURRENT);
    stmt->setUInt32(1, GetAccountId());

    _queryProcessor.AddQuery(CharacterDatabase.AsyncQuery(stmt).WithPreparedCallback(std::bind(&WorldSession::HandleCharEnum, this, std::placeholders::_1)));
}

void WorldSession::HandleCharUndeleteEnum(PreparedQueryResult result)
{
    WorldPackets::Character::EnumCharactersResult charEnum;
    charEnum.Success = true;
    charEnum.IsDeletedCharacters = true;
    charEnum.DisabledClassesMask = sWorld->getIntConfig(CONFIG_CHARACTER_CREATING_DISABLED_CLASSMASK);

    if (result)
    {
        do
        {
            Field* fields = result->Fetch();
            WorldPackets::Character::EnumCharactersResult::CharacterInfo charInfo(fields);

            TC_LOG_INFO("network", "Loading undeleted char guid %s from account %u.", charInfo.Guid.ToString().c_str(), GetAccountId());

            if (!sWorld->HasCharacterInfo(charInfo.Guid)) // This can happen if characters are inserted into the database manually. Core hasn't loaded name data yet.
                sWorld->AddCharacterInfo(charInfo.Guid, GetAccountId(), charInfo.Name, charInfo.Sex, charInfo.Race, charInfo.Class, charInfo.Level, true);

            charEnum.Characters.emplace_back(charInfo);
        }
        while (result->NextRow());
    }

    SendPacket(charEnum.Write());
}

void WorldSession::HandleCharUndeleteEnumOpcode(WorldPackets::Character::EnumCharacters& /*enumCharacters*/)
{
    /// get all the data necessary for loading all undeleted characters (along with their pets) on the account
    PreparedStatement* stmt = nullptr;
    if (sWorld->getBoolConfig(CONFIG_DECLINED_NAMES_USED))
        stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_UNDELETE_ENUM_DECLINED_NAME);
    else
        stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_UNDELETE_ENUM);

    stmt->setUInt8(0, PET_SAVE_AS_CURRENT);
    stmt->setUInt32(1, GetAccountId());

    _queryProcessor.AddQuery(CharacterDatabase.AsyncQuery(stmt).WithPreparedCallback(std::bind(&WorldSession::HandleCharUndeleteEnum, this, std::placeholders::_1)));
}

void WorldSession::HandleCharCreateOpcode(WorldPackets::Character::CreateCharacter& charCreate)
{
    if (!HasPermission(rbac::RBAC_PERM_SKIP_CHECK_CHARACTER_CREATION_TEAMMASK))
    {
        if (uint32 mask = sWorld->getIntConfig(CONFIG_CHARACTER_CREATING_DISABLED))
        {
            bool disabled = false;

            switch (Player::TeamIdForRace(charCreate.CreateInfo->Race))
            {
                case TEAM_ALLIANCE:
                    disabled = (mask & (1 << 0)) != 0;
                    break;
                case TEAM_HORDE:
                    disabled = (mask & (1 << 1)) != 0;
                    break;
                case TEAM_NEUTRAL:
                    disabled = (mask & (1 << 2)) != 0;
                    break;
            }

            if (disabled)
            {
                SendCharCreate(CHAR_CREATE_DISABLED);
                return;
            }
        }
    }

    ChrClassesEntry const* classEntry = sChrClassesStore.LookupEntry(charCreate.CreateInfo->Class);
    if (!classEntry)
    {
        TC_LOG_ERROR("network", "Class (%u) not found in DBC while creating new char for account (ID: %u): wrong DBC files or cheater?", charCreate.CreateInfo->Class, GetAccountId());
        SendCharCreate(CHAR_CREATE_FAILED);
        return;
    }

    ChrRacesEntry const* raceEntry = sChrRacesStore.LookupEntry(charCreate.CreateInfo->Race);
    if (!raceEntry)
    {
        TC_LOG_ERROR("network", "Race (%u) not found in DBC while creating new char for account (ID: %u): wrong DBC files or cheater?", charCreate.CreateInfo->Race, GetAccountId());
        SendCharCreate(CHAR_CREATE_FAILED);
        return;
    }

    // prevent character creating Expansion race without Expansion account
    RaceUnlockRequirement const* raceExpansionRequirement = sObjectMgr->GetRaceUnlockRequirement(charCreate.CreateInfo->Race);
    if (!raceExpansionRequirement)
    {
        TC_LOG_ERROR("entities.player.cheat", "Account %u tried to create character with unavailable race %u", GetAccountId(), charCreate.CreateInfo->Race);
        SendCharCreate(CHAR_CREATE_FAILED);
        return;
    }

    if (raceExpansionRequirement->Expansion > GetAccountExpansion())
    {
        TC_LOG_ERROR("entities.player.cheat", "Expansion %u account:[%d] tried to Create character with expansion %u race (%u)",
            GetAccountExpansion(), GetAccountId(), raceExpansionRequirement->Expansion, charCreate.CreateInfo->Race);
        SendCharCreate(CHAR_CREATE_EXPANSION);
        return;
    }

    //if (raceExpansionRequirement->AchievementId && !)
    //{
    //    TC_LOG_ERROR("entities.player.cheat", "Expansion %u account:[%d] tried to Create character without achievement %u race (%u)",
    //        GetAccountExpansion(), GetAccountId(), raceExpansionRequirement->AchievementId, charCreate.CreateInfo->Race);
    //    SendCharCreate(CHAR_CREATE_ALLIED_RACE_ACHIEVEMENT);
    //    return;
    //}

    // prevent character creating Expansion class without Expansion account
    uint8 classExpansionRequirement = sObjectMgr->GetClassExpansionRequirement(charCreate.CreateInfo->Class);
    if (classExpansionRequirement > GetAccountExpansion())
    {
        TC_LOG_ERROR("entities.player.cheat", "Expansion %u account:[%d] tried to Create character with expansion %u class (%u)",
            GetAccountExpansion(), GetAccountId(), classExpansionRequirement, charCreate.CreateInfo->Class);
        SendCharCreate(CHAR_CREATE_EXPANSION_CLASS);
        return;
    }

    if (!HasPermission(rbac::RBAC_PERM_SKIP_CHECK_CHARACTER_CREATION_RACEMASK))
    {
        uint32 raceMaskDisabled = sWorld->getIntConfig(CONFIG_CHARACTER_CREATING_DISABLED_RACEMASK);
        if ((1 << (charCreate.CreateInfo->Race - 1)) & raceMaskDisabled)
        {
            SendCharCreate(CHAR_CREATE_DISABLED);
            return;
        }
    }

    if (!HasPermission(rbac::RBAC_PERM_SKIP_CHECK_CHARACTER_CREATION_CLASSMASK))
    {
        uint32 classMaskDisabled = sWorld->getIntConfig(CONFIG_CHARACTER_CREATING_DISABLED_CLASSMASK);
        if ((1 << (charCreate.CreateInfo->Class - 1)) & classMaskDisabled)
        {
            SendCharCreate(CHAR_CREATE_DISABLED);
            return;
        }
    }

    // prevent character creating with invalid name
    if (!normalizePlayerName(charCreate.CreateInfo->Name))
    {
        TC_LOG_ERROR("entities.player.cheat", "Account:[%d] but tried to Create character with empty [name] ", GetAccountId());
        SendCharCreate(CHAR_NAME_NO_NAME);
        return;
    }

    // check name limitations
    ResponseCodes res = ObjectMgr::CheckPlayerName(charCreate.CreateInfo->Name, GetSessionDbcLocale(), true);
    if (res != CHAR_NAME_SUCCESS)
    {
        SendCharCreate(res);
        return;
    }

    if (!HasPermission(rbac::RBAC_PERM_SKIP_CHECK_CHARACTER_CREATION_RESERVEDNAME) && sObjectMgr->IsReservedName(charCreate.CreateInfo->Name))
    {
        SendCharCreate(CHAR_NAME_RESERVED);
        return;
    }

    std::shared_ptr<WorldPackets::Character::CharacterCreateInfo> createInfo = charCreate.CreateInfo;
    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHECK_NAME);
    stmt->setString(0, charCreate.CreateInfo->Name);

    _queryProcessor.AddQuery(CharacterDatabase.AsyncQuery(stmt)
        .WithChainingPreparedCallback([this](QueryCallback& queryCallback, PreparedQueryResult result)
    {
        if (result)
        {
            SendCharCreate(CHAR_CREATE_NAME_IN_USE);
            return;
        }

        PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_SEL_SUM_REALM_CHARACTERS);
        stmt->setUInt32(0, GetAccountId());
        queryCallback.SetNextQuery(LoginDatabase.AsyncQuery(stmt));
    })
        .WithChainingPreparedCallback([this](QueryCallback& queryCallback, PreparedQueryResult result)
    {
        uint64 acctCharCount = 0;
        if (result)
        {
            Field* fields = result->Fetch();
            acctCharCount = uint64(fields[0].GetDouble());
        }

        if (acctCharCount >= sWorld->getIntConfig(CONFIG_CHARACTERS_PER_ACCOUNT))
        {
            SendCharCreate(CHAR_CREATE_ACCOUNT_LIMIT);
            return;
        }

        PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_SUM_CHARS);
        stmt->setUInt32(0, GetAccountId());
        queryCallback.SetNextQuery(CharacterDatabase.AsyncQuery(stmt));
    })
        .WithChainingPreparedCallback([this, createInfo](QueryCallback& queryCallback, PreparedQueryResult result)
    {
        if (result)
        {
            Field* fields = result->Fetch();
            createInfo->CharCount = uint8(fields[0].GetUInt64()); // SQL's COUNT() returns uint64 but it will always be less than uint8.Max

            if (createInfo->CharCount >= sWorld->getIntConfig(CONFIG_CHARACTERS_PER_REALM))
            {
                SendCharCreate(CHAR_CREATE_SERVER_LIMIT);
                return;
            }
        }

        bool allowTwoSideAccounts = !sWorld->IsPvPRealm() || HasPermission(rbac::RBAC_PERM_TWO_SIDE_CHARACTER_CREATION);
        uint32 skipCinematics = sWorld->getIntConfig(CONFIG_SKIP_CINEMATICS);

        std::function<void(PreparedQueryResult)> finalizeCharacterCreation = [this, createInfo](PreparedQueryResult result)
        {
            bool haveSameRace = false;
            uint32 demonHunterReqLevel = sWorld->getIntConfig(CONFIG_CHARACTER_CREATING_MIN_LEVEL_FOR_DEMON_HUNTER);
            bool hasDemonHunterReqLevel = (demonHunterReqLevel == 0);
            bool allowTwoSideAccounts = !sWorld->IsPvPRealm() || HasPermission(rbac::RBAC_PERM_TWO_SIDE_CHARACTER_CREATION);
            uint32 skipCinematics = sWorld->getIntConfig(CONFIG_SKIP_CINEMATICS);
            bool checkDemonHunterReqs = createInfo->Class == CLASS_DEMON_HUNTER && !HasPermission(rbac::RBAC_PERM_SKIP_CHECK_CHARACTER_CREATION_DEMON_HUNTER);

            if (result)
            {
                uint32 team = Player::TeamForRace(createInfo->Race);
                uint32 freeDemonHunterSlots = sWorld->getIntConfig(CONFIG_DEMON_HUNTERS_PER_REALM);

                Field* field = result->Fetch();
                uint8 accRace = field[1].GetUInt8();

                if (checkDemonHunterReqs)
                {
                    uint8 accClass = field[2].GetUInt8();
                    if (accClass == CLASS_DEMON_HUNTER)
                    {
                        if (freeDemonHunterSlots > 0)
                            --freeDemonHunterSlots;

                        if (freeDemonHunterSlots == 0)
                        {
                            SendCharCreate(CHAR_CREATE_FAILED);
                            return;
                        }
                    }

                    if (!hasDemonHunterReqLevel)
                    {
                        uint8 accLevel = field[0].GetUInt8();
                        if (accLevel >= demonHunterReqLevel)
                            hasDemonHunterReqLevel = true;
                    }
                }

                // need to check team only for first character
                /// @todo what to if account already has characters of both races?
                if (!allowTwoSideAccounts)
                {
                    uint32 accTeam = 0;
                    if (accRace > 0)
                        accTeam = Player::TeamForRace(accRace);

                    if (accTeam != team)
                    {
                        SendCharCreate(CHAR_CREATE_PVP_TEAMS_VIOLATION);
                        return;
                    }
                }

                // search same race for cinematic or same class if need
                /// @todo check if cinematic already shown? (already logged in?; cinematic field)
                while ((skipCinematics == 1 && !haveSameRace) || createInfo->Class == CLASS_DEMON_HUNTER)
                {
                    if (!result->NextRow())
                        break;

                    field = result->Fetch();
                    accRace = field[1].GetUInt8();

                    if (!haveSameRace)
                        haveSameRace = createInfo->Race == accRace;

                    if (checkDemonHunterReqs)
                    {
                        uint8 accClass = field[2].GetUInt8();
                        if (accClass == CLASS_DEMON_HUNTER)
                        {
                            if (freeDemonHunterSlots > 0)
                                --freeDemonHunterSlots;

                            if (freeDemonHunterSlots == 0)
                            {
                                SendCharCreate(CHAR_CREATE_FAILED);
                                return;
                            }
                        }

                        if (!hasDemonHunterReqLevel)
                        {
                            uint8 accLevel = field[0].GetUInt8();
                            if (accLevel >= demonHunterReqLevel)
                                hasDemonHunterReqLevel = true;
                        }
                    }
                }
            }

            if (checkDemonHunterReqs && !hasDemonHunterReqLevel)
            {
                SendCharCreate(CHAR_CREATE_LEVEL_REQUIREMENT_DEMON_HUNTER);
                return;
            }

            Player newChar(this);
            newChar.GetMotionMaster()->Initialize();
            if (!newChar.Create(sObjectMgr->GetGenerator<HighGuid::Player>().Generate(), createInfo.get()))
            {
                // Player not create (race/class/etc problem?)
                newChar.CleanupsBeforeDelete();

                SendCharCreate(CHAR_CREATE_ERROR);
                return;
            }

            if ((haveSameRace && skipCinematics == 1) || skipCinematics == 2)
                newChar.setCinematic(1);                          // not show intro

            newChar.SetAtLoginFlag(AT_LOGIN_FIRST);               // First login

                                                                  // Player created, save it now
            newChar.SaveToDB(true);
            createInfo->CharCount += 1;

            SQLTransaction trans = LoginDatabase.BeginTransaction();

            PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_DEL_REALM_CHARACTERS_BY_REALM);
            stmt->setUInt32(0, GetAccountId());
            stmt->setUInt32(1, realm.Id.Realm);
            trans->Append(stmt);

            stmt = LoginDatabase.GetPreparedStatement(LOGIN_INS_REALM_CHARACTERS);
            stmt->setUInt32(0, createInfo->CharCount);
            stmt->setUInt32(1, GetAccountId());
            stmt->setUInt32(2, realm.Id.Realm);
            trans->Append(stmt);

            LoginDatabase.CommitTransaction(trans);

            SendCharCreate(CHAR_CREATE_SUCCESS);

            TC_LOG_INFO("entities.player.character", "Account: %u (IP: %s) Create Character: %s %s", GetAccountId(), GetRemoteAddress().c_str(), createInfo->Name.c_str(), newChar.GetGUID().ToString().c_str());
            sScriptMgr->OnPlayerCreate(&newChar);
            sWorld->AddCharacterInfo(newChar.GetGUID(), GetAccountId(), newChar.GetName(), newChar.GetByteValue(PLAYER_BYTES_3, PLAYER_BYTES_3_OFFSET_GENDER), newChar.getRace(), newChar.getClass(), newChar.getLevel(), false);

            newChar.CleanupsBeforeDelete();
        };

        if (allowTwoSideAccounts && !skipCinematics && createInfo->Class != CLASS_DEMON_HUNTER)
        {
            finalizeCharacterCreation(PreparedQueryResult(nullptr));
            return;
        }

        PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHAR_CREATE_INFO);
        stmt->setUInt32(0, GetAccountId());
        stmt->setUInt32(1, (skipCinematics == 1 || createInfo->Class == CLASS_DEMON_HUNTER) ? 12 : 1);
        queryCallback.WithPreparedCallback(std::move(finalizeCharacterCreation)).SetNextQuery(CharacterDatabase.AsyncQuery(stmt));
    }));
}

void WorldSession::HandleCharDeleteOpcode(WorldPackets::Character::CharDelete& charDelete)
{
    // Initiating
    uint32 initAccountId = GetAccountId();

    // can't delete loaded character
    if (ObjectAccessor::FindPlayer(charDelete.Guid))
    {
        sScriptMgr->OnPlayerFailedDelete(charDelete.Guid, initAccountId);
        return;
    }

    // is guild leader
    if (sGuildMgr->GetGuildByLeader(charDelete.Guid))
    {
        sScriptMgr->OnPlayerFailedDelete(charDelete.Guid, initAccountId);
        SendCharDelete(CHAR_DELETE_FAILED_GUILD_LEADER);
        return;
    }

    // is arena team captain
    if (sArenaTeamMgr->GetArenaTeamByCaptain(charDelete.Guid))
    {
        sScriptMgr->OnPlayerFailedDelete(charDelete.Guid, initAccountId);
        SendCharDelete(CHAR_DELETE_FAILED_ARENA_CAPTAIN);
        return;
    }

    CharacterInfo const* characterInfo = sWorld->GetCharacterInfo(charDelete.Guid);
    if (!characterInfo)
    {
        sScriptMgr->OnPlayerFailedDelete(charDelete.Guid, initAccountId);
        return;
    }

    uint32 accountId = characterInfo->AccountId;
    std::string name = characterInfo->Name;
    uint8 level = characterInfo->Level;

    // prevent deleting other players' characters using cheating tools
    if (accountId != initAccountId)
    {
        sScriptMgr->OnPlayerFailedDelete(charDelete.Guid, initAccountId);
        return;
    }

    TC_LOG_INFO("entities.player.character", "Account: %u, IP: %s deleted character: %s, %s, Level: %u", accountId, GetRemoteAddress().c_str(), name.c_str(), charDelete.Guid.ToString().c_str(), level);

    // To prevent hook failure, place hook before removing reference from DB
    sScriptMgr->OnPlayerDelete(charDelete.Guid, initAccountId); // To prevent race conditioning, but as it also makes sense, we hand the accountId over for successful delete.
    // Shouldn't interfere with character deletion though

    if (sLog->ShouldLog("entities.player.dump", LOG_LEVEL_INFO)) // optimize GetPlayerDump call
    {
        std::string dump;
        if (PlayerDumpWriter().GetDump(charDelete.Guid.GetCounter(), dump))
            sLog->outCharDump(dump.c_str(), accountId, charDelete.Guid.GetCounter(), name.c_str());
    }

    sGuildFinderMgr->RemoveAllMembershipRequestsFromPlayer(charDelete.Guid);
    sCalendarMgr->RemoveAllPlayerEventsAndInvites(charDelete.Guid);
    Player::DeleteFromDB(charDelete.Guid, accountId);

    SendCharDelete(CHAR_DELETE_SUCCESS);
}

void WorldSession::HandlePlayerLoginOpcode(WorldPackets::Character::PlayerLogin& playerLogin)
{
    if (PlayerLoading() || GetPlayer() != NULL)
    {
        TC_LOG_ERROR("network", "Player tries to login again, AccountId = %d", GetAccountId());
        KickPlayer();
        return;
    }

    m_playerLoading = playerLogin.Guid;

    TC_LOG_DEBUG("network", "Character %s logging in", playerLogin.Guid.ToString().c_str());

    if (!IsLegitCharacterForAccount(playerLogin.Guid))
    {
        TC_LOG_ERROR("network", "Account (%u) can't login with that character (%s).", GetAccountId(), playerLogin.Guid.ToString().c_str());
        KickPlayer();
        return;
    }

    SendConnectToInstance(WorldPackets::Auth::ConnectToSerial::WorldAttempt1);
}

void WorldSession::HandleContinuePlayerLogin()
{
    if (!PlayerLoading() || GetPlayer())
    {
        KickPlayer();
        return;
    }

    LoginQueryHolder* holder = new LoginQueryHolder(GetAccountId(), m_playerLoading);
    if (!holder->Initialize())
    {
        delete holder;                                      // delete all unprocessed queries
        m_playerLoading.Clear();
        return;
    }

    SendPacket(WorldPackets::Auth::ResumeComms(CONNECTION_TYPE_INSTANCE).Write());

    _charLoginCallback = CharacterDatabase.DelayQueryHolder(holder);
}

void WorldSession::AbortLogin(WorldPackets::Character::LoginFailureReason reason)
{
    if (!PlayerLoading() || GetPlayer())
    {
        KickPlayer();
        return;
    }

    m_playerLoading.Clear();
    SendPacket(WorldPackets::Character::CharacterLoginFailed(reason).Write());
}

void WorldSession::HandleLoadScreenOpcode(WorldPackets::Character::LoadingScreenNotify& /*loadingScreenNotify*/)
{
    // TODO: Do something with this packet
}

void WorldSession::HandlePlayerLogin(LoginQueryHolder* holder)
{
    ObjectGuid playerGuid = holder->GetGuid();

    Player* pCurrChar = new Player(this);
     // for send server info and strings (config)
    ChatHandler chH = ChatHandler(pCurrChar->GetSession());

    // "GetAccountId() == db stored account id" checked in LoadFromDB (prevent login not own character using cheating tools)
    if (!pCurrChar->LoadFromDB(playerGuid, holder))
    {
        SetPlayer(NULL);
        KickPlayer();                                       // disconnect client, player no set to session and it will not deleted or saved at kick
        delete pCurrChar;                                   // delete it manually
        delete holder;                                      // delete all unprocessed queries
        m_playerLoading.Clear();
        return;
    }

    pCurrChar->SetUInt32Value(PLAYER_FIELD_VIRTUAL_PLAYER_REALM, GetVirtualRealmAddress());

    SendTutorialsData();

    pCurrChar->GetMotionMaster()->Initialize();
    pCurrChar->SendDungeonDifficulty();

    WorldPackets::Character::LoginVerifyWorld loginVerifyWorld;
    loginVerifyWorld.MapID = pCurrChar->GetMapId();
    loginVerifyWorld.Pos = pCurrChar->GetPosition();
    SendPacket(loginVerifyWorld.Write());

    // load player specific part before send times
    LoadAccountData(holder->GetPreparedResult(PLAYER_LOGIN_QUERY_LOAD_ACCOUNT_DATA), PER_CHARACTER_CACHE_MASK);

    WorldPackets::ClientConfig::AccountDataTimes accountDataTimes;
    accountDataTimes.PlayerGuid = playerGuid;
    accountDataTimes.ServerTime = uint32(sWorld->GetGameTime());
    for (uint32 i = 0; i < NUM_ACCOUNT_DATA_TYPES; ++i)
        accountDataTimes.AccountTimes[i] = uint32(GetAccountData(AccountDataType(i))->Time);

    SendPacket(accountDataTimes.Write());

    SendFeatureSystemStatus();

    // Send MOTD
    {
        WorldPackets::System::MOTD motd;
        motd.Text = &sWorld->GetMotd();
        SendPacket(motd.Write());
    }

    SendSetTimeZoneInformation();

    // Send PVPSeason
    {
        WorldPackets::Battleground::PVPSeason season;
        season.PreviousSeason = sWorld->getIntConfig(CONFIG_ARENA_SEASON_ID) - sWorld->getBoolConfig(CONFIG_ARENA_SEASON_IN_PROGRESS);

        if (sWorld->getBoolConfig(CONFIG_ARENA_SEASON_IN_PROGRESS))
            season.CurrentSeason = sWorld->getIntConfig(CONFIG_ARENA_SEASON_ID);

        SendPacket(season.Write());
    }

    // send server info
    {
        if (sWorld->getIntConfig(CONFIG_ENABLE_SINFO_LOGIN) == 1)
            chH.PSendSysMessage(GitRevision::GetFullVersion());
    }

    //QueryResult* result = CharacterDatabase.PQuery("SELECT guildid, rank FROM guild_member WHERE guid = '%u'", pCurrChar->GetGUIDLow());
    if (PreparedQueryResult resultGuild = holder->GetPreparedResult(PLAYER_LOGIN_QUERY_LOAD_GUILD))
    {
        Field* fields = resultGuild->Fetch();
        pCurrChar->SetInGuild(fields[0].GetUInt64());
        pCurrChar->SetGuildRank(fields[1].GetUInt8());
        if (Guild* guild = sGuildMgr->GetGuildById(pCurrChar->GetGuildId()))
            pCurrChar->SetGuildLevel(guild->GetLevel());
    }
    else if (pCurrChar->GetGuildId())                        // clear guild related fields in case wrong data about non existed membership
    {
        pCurrChar->SetInGuild(UI64LIT(0));
        pCurrChar->SetGuildRank(0);
        pCurrChar->SetGuildLevel(0);
    }

    // TODO: Move this to BattlePetMgr::SendJournalLock() just to have all packets in one file
    WorldPackets::BattlePet::BattlePetJournalLockAcquired lock;
    SendPacket(lock.Write());

    pCurrChar->SendInitialPacketsBeforeAddToMap();

    //Show cinematic at the first time that player login
    if (!pCurrChar->getCinematic())
    {
        pCurrChar->setCinematic(1);

        if (ChrClassesEntry const* cEntry = sChrClassesStore.LookupEntry(pCurrChar->getClass()))
        {
            if (pCurrChar->getClass() == CLASS_DEMON_HUNTER) /// @todo: find a more generic solution
                pCurrChar->SendMovieStart(469);
            else if (cEntry->CinematicSequenceID)
                pCurrChar->SendCinematicStart(cEntry->CinematicSequenceID);
            else if (ChrRacesEntry const* rEntry = sChrRacesStore.LookupEntry(pCurrChar->getRace()))
                pCurrChar->SendCinematicStart(rEntry->CinematicSequenceID);

            // send new char string if not empty
            if (!sWorld->GetNewCharString().empty())
                chH.PSendSysMessage("%s", sWorld->GetNewCharString().c_str());
        }
    }

    if (!pCurrChar->GetMap()->AddPlayerToMap(pCurrChar))
    {
        AreaTriggerStruct const* at = sObjectMgr->GetGoBackTrigger(pCurrChar->GetMapId());
        if (at)
            pCurrChar->TeleportTo(at->target_mapId, at->target_X, at->target_Y, at->target_Z, pCurrChar->GetOrientation());
        else
            pCurrChar->TeleportTo(pCurrChar->m_homebindMapId, pCurrChar->m_homebindX, pCurrChar->m_homebindY, pCurrChar->m_homebindZ, pCurrChar->GetOrientation());
    }

    ObjectAccessor::AddObject(pCurrChar);
    //TC_LOG_DEBUG("Player %s added to Map.", pCurrChar->GetName().c_str());

    if (pCurrChar->GetGuildId())
    {
        if (Guild* guild = sGuildMgr->GetGuildById(pCurrChar->GetGuildId()))
            guild->SendLoginInfo(this);
        else
        {
            // remove wrong guild data
            TC_LOG_ERROR("misc", "Player %s (%s) marked as member of not existing guild (id: " UI64FMTD "), removing guild membership for player.", pCurrChar->GetName().c_str(), pCurrChar->GetGUID().ToString().c_str(), pCurrChar->GetGuildId());
            pCurrChar->SetInGuild(UI64LIT(0));
        }
    }

    pCurrChar->SendInitialPacketsAfterAddToMap();

    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_CHAR_ONLINE);
    stmt->setUInt64(0, pCurrChar->GetGUID().GetCounter());
    CharacterDatabase.Execute(stmt);

    stmt = LoginDatabase.GetPreparedStatement(LOGIN_UPD_ACCOUNT_ONLINE);
    stmt->setUInt32(0, GetAccountId());
    LoginDatabase.Execute(stmt);

    pCurrChar->SetInGameTime(getMSTime());

    // announce group about member online (must be after add to player list to receive announce to self)
    if (Group* group = pCurrChar->GetGroup())
    {
        //pCurrChar->groupInfo.group->SendInit(this); // useless
        group->SendUpdate();
        group->ResetMaxEnchantingLevel();
    }

    // friend status
    sSocialMgr->SendFriendStatus(pCurrChar, FRIEND_ONLINE, pCurrChar->GetGUID(), true);

    // Place character in world (and load zone) before some object loading
    pCurrChar->LoadCorpse(holder->GetPreparedResult(PLAYER_LOGIN_QUERY_LOAD_CORPSE_LOCATION));

    // setting Ghost+speed if dead
    if (pCurrChar->m_deathState != ALIVE)
    {
        // not blizz like, we must correctly save and load player instead...
        if (pCurrChar->getRace() == RACE_NIGHTELF && !pCurrChar->HasAura(20584))
            pCurrChar->CastSpell(pCurrChar, 20584, true, 0);// auras SPELL_AURA_INCREASE_SPEED(+speed in wisp form), SPELL_AURA_INCREASE_SWIM_SPEED(+swim speed in wisp form), SPELL_AURA_TRANSFORM (to wisp form)

        if (!pCurrChar->HasAura(8326))
            pCurrChar->CastSpell(pCurrChar, 8326, true, 0);     // auras SPELL_AURA_GHOST, SPELL_AURA_INCREASE_SPEED(why?), SPELL_AURA_INCREASE_SWIM_SPEED(why?)

        pCurrChar->SetWaterWalking(true);
    }

    pCurrChar->ContinueTaxiFlight();

    // reset for all pets before pet loading
    if (pCurrChar->HasAtLoginFlag(AT_LOGIN_RESET_PET_TALENTS))
    {
        // Delete all of the player's pet spells
        PreparedStatement* stmtSpells = CharacterDatabase.GetPreparedStatement(CHAR_DEL_ALL_PET_SPELLS_BY_OWNER);
        stmtSpells->setUInt64(0, pCurrChar->GetGUID().GetCounter());
        CharacterDatabase.Execute(stmtSpells);

        // Then reset all of the player's pet specualizations
        PreparedStatement* stmtSpec = CharacterDatabase.GetPreparedStatement(CHAR_UPD_PET_SPECS_BY_OWNER);
        stmtSpec->setUInt64(0, pCurrChar->GetGUID().GetCounter());
        CharacterDatabase.Execute(stmtSpec);
    }

    // Load pet if any (if player not alive and in taxi flight or another then pet will remember as temporary unsummoned)
    pCurrChar->LoadPet();

    // Set FFA PvP for non GM in non-rest mode
    if (sWorld->IsFFAPvPRealm() && !pCurrChar->IsGameMaster() && !pCurrChar->HasFlag(PLAYER_FLAGS, PLAYER_FLAGS_RESTING))
        pCurrChar->SetByteFlag(UNIT_FIELD_BYTES_2, UNIT_BYTES_2_OFFSET_PVP_FLAG, UNIT_BYTE2_FLAG_FFA_PVP);

    if (pCurrChar->HasFlag(PLAYER_FLAGS, PLAYER_FLAGS_CONTESTED_PVP))
        pCurrChar->SetContestedPvP();

    // Apply at_login requests
    if (pCurrChar->HasAtLoginFlag(AT_LOGIN_RESET_SPELLS))
    {
        pCurrChar->ResetSpells();
        SendNotification(LANG_RESET_SPELLS);
    }

    if (pCurrChar->HasAtLoginFlag(AT_LOGIN_RESET_TALENTS))
    {
        pCurrChar->ResetTalents(true);
        pCurrChar->ResetTalentSpecialization();
        pCurrChar->SendTalentsInfoData(); // original talents send already in to SendInitialPacketsBeforeAddToMap, resend reset state
        SendNotification(LANG_RESET_TALENTS);
    }

    bool firstLogin = pCurrChar->HasAtLoginFlag(AT_LOGIN_FIRST);
    if (firstLogin)
    {
        pCurrChar->RemoveAtLoginFlag(AT_LOGIN_FIRST);

        PlayerInfo const* info = sObjectMgr->GetPlayerInfo(pCurrChar->getRace(), pCurrChar->getClass());
        for (uint32 spellId : info->castSpells)
            pCurrChar->CastSpell(pCurrChar, spellId, true);
    }

    // show time before shutdown if shutdown planned.
    if (sWorld->IsShuttingDown())
        sWorld->ShutdownMsg(true, pCurrChar);

    if (sWorld->getBoolConfig(CONFIG_ALL_TAXI_PATHS))
        pCurrChar->SetTaxiCheater(true);

    if (pCurrChar->IsGameMaster())
        SendNotification(LANG_GM_ON);

    TC_LOG_INFO("entities.player.character", "Account: %u (IP: %s) Login Character: [%s] (%s) Level: %d",
        GetAccountId(), GetRemoteAddress().c_str(), pCurrChar->GetName().c_str(), pCurrChar->GetGUID().ToString().c_str(), pCurrChar->getLevel());

    if (!pCurrChar->IsStandState() && !pCurrChar->HasUnitState(UNIT_STATE_STUNNED))
        pCurrChar->SetStandState(UNIT_STAND_STATE_STAND);

    m_playerLoading.Clear();

    // Handle Login-Achievements (should be handled after loading)
    _player->UpdateCriteria(CRITERIA_TYPE_ON_LOGIN, 1);

    sScriptMgr->OnPlayerLogin(pCurrChar, firstLogin);

    TC_METRIC_EVENT("player_events", "Login", pCurrChar->GetName());

    delete holder;
}

void WorldSession::SendFeatureSystemStatus()
{
    WorldPackets::System::FeatureSystemStatus features;

    /// START OF DUMMY VALUES
    features.ComplaintStatus = 2;
    features.ScrollOfResurrectionRequestsRemaining = 1;
    features.ScrollOfResurrectionMaxRequestsPerDay = 1;
    features.TwitterPostThrottleLimit = 60;
    features.TwitterPostThrottleCooldown = 20;
    features.CfgRealmID = 2;
    features.CfgRealmRecID = 0;
    features.TokenPollTimeSeconds = 300;
    features.TokenRedeemIndex = 0;
    features.VoiceEnabled = false;
    features.BrowserEnabled = false; // Has to be false, otherwise client will crash if "Customer Support" is opened

    features.EuropaTicketSystemStatus = boost::in_place();
    features.EuropaTicketSystemStatus->ThrottleState.MaxTries = 10;
    features.EuropaTicketSystemStatus->ThrottleState.PerMilliseconds = 60000;
    features.EuropaTicketSystemStatus->ThrottleState.TryCount = 1;
    features.EuropaTicketSystemStatus->ThrottleState.LastResetTimeBeforeNow = 111111;
    features.ComplaintStatus = 0;
    features.TutorialsEnabled = true;
    features.NPETutorialsEnabled = true;
    /// END OF DUMMY VALUES

    features.EuropaTicketSystemStatus->TicketsEnabled = sWorld->getBoolConfig(CONFIG_SUPPORT_TICKETS_ENABLED);
    features.EuropaTicketSystemStatus->BugsEnabled = sWorld->getBoolConfig(CONFIG_SUPPORT_BUGS_ENABLED);
    features.EuropaTicketSystemStatus->ComplaintsEnabled = sWorld->getBoolConfig(CONFIG_SUPPORT_COMPLAINTS_ENABLED);
    features.EuropaTicketSystemStatus->SuggestionsEnabled = sWorld->getBoolConfig(CONFIG_SUPPORT_SUGGESTIONS_ENABLED);

    features.CharUndeleteEnabled = sWorld->getBoolConfig(CONFIG_FEATURE_SYSTEM_CHARACTER_UNDELETE_ENABLED);
    features.BpayStoreEnabled = sWorld->getBoolConfig(CONFIG_FEATURE_SYSTEM_BPAY_STORE_ENABLED);

    SendPacket(features.Write());
}

void WorldSession::HandleSetFactionAtWar(WorldPackets::Character::SetFactionAtWar& packet)
{
    GetPlayer()->GetReputationMgr().SetAtWar(packet.FactionIndex, true);
}

void WorldSession::HandleSetFactionNotAtWar(WorldPackets::Character::SetFactionNotAtWar& packet)
{
    GetPlayer()->GetReputationMgr().SetAtWar(packet.FactionIndex, false);
}

//I think this function is never used :/ I dunno, but i guess this opcode not exists
void WorldSession::HandleSetFactionCheat(WorldPacket& /*recvData*/)
{
    TC_LOG_ERROR("network", "WORLD SESSION: HandleSetFactionCheat, not expected call, please report.");
    GetPlayer()->GetReputationMgr().SendStates();
}

void WorldSession::HandleTutorialFlag(WorldPackets::Misc::TutorialSetFlag& packet)
{
    switch (packet.Action)
    {
        case TUTORIAL_ACTION_UPDATE:
        {
            uint8 index = uint8(packet.TutorialBit >> 5);
            if (index >= MAX_ACCOUNT_TUTORIAL_VALUES)
            {
                TC_LOG_ERROR("network", "CMSG_TUTORIAL_FLAG received bad TutorialBit %u.", packet.TutorialBit);
                return;
            }
            uint32 flag = GetTutorialInt(index);
            flag |= (1 << (packet.TutorialBit & 0x1F));
            SetTutorialInt(index, flag);
            break;
        }
        case TUTORIAL_ACTION_CLEAR:
            for (uint8 i = 0; i < MAX_ACCOUNT_TUTORIAL_VALUES; ++i)
                SetTutorialInt(i, 0xFFFFFFFF);
            break;
        case TUTORIAL_ACTION_RESET:
            for (uint8 i = 0; i < MAX_ACCOUNT_TUTORIAL_VALUES; ++i)
                SetTutorialInt(i, 0x00000000);
            break;
        default:
            TC_LOG_ERROR("network", "CMSG_TUTORIAL_FLAG received unknown TutorialAction %u.", packet.Action);
            return;
    }
}

void WorldSession::HandleSetWatchedFactionOpcode(WorldPackets::Character::SetWatchedFaction& packet)
{
    GetPlayer()->SetUInt32Value(PLAYER_FIELD_WATCHED_FACTION_INDEX, packet.FactionIndex);
}

void WorldSession::HandleSetFactionInactiveOpcode(WorldPackets::Character::SetFactionInactive& packet)
{
    _player->GetReputationMgr().SetInactive(packet.Index, packet.State);
}

void WorldSession::HandleRequestForcedReactionsOpcode(WorldPackets::Reputation::RequestForcedReactions& /*requestForcedReactions*/)
{
    _player->GetReputationMgr().SendForceReactions();
}

void WorldSession::HandleCharRenameOpcode(WorldPackets::Character::CharacterRenameRequest& request)
{
    if (!IsLegitCharacterForAccount(request.RenameInfo->Guid))
    {
        TC_LOG_ERROR("network", "Account %u, IP: %s tried to rename character %s, but it does not belong to their account!",
            GetAccountId(), GetRemoteAddress().c_str(), request.RenameInfo->Guid.ToString().c_str());
        KickPlayer();
        return;
    }

    // prevent character rename to invalid name
    if (!normalizePlayerName(request.RenameInfo->NewName))
    {
        SendCharRename(CHAR_NAME_NO_NAME, request.RenameInfo.get());
        return;
    }

    ResponseCodes res = ObjectMgr::CheckPlayerName(request.RenameInfo->NewName, GetSessionDbcLocale(), true);
    if (res != CHAR_NAME_SUCCESS)
    {
        SendCharRename(res, request.RenameInfo.get());
        return;
    }

    // check name limitations
    if (!HasPermission(rbac::RBAC_PERM_SKIP_CHECK_CHARACTER_CREATION_RESERVEDNAME) && sObjectMgr->IsReservedName(request.RenameInfo->NewName))
    {
        SendCharRename(CHAR_NAME_RESERVED, request.RenameInfo.get());
        return;
    }

    // Ensure that there is no character with the desired new name
    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_FREE_NAME);
    stmt->setUInt64(0, request.RenameInfo->Guid.GetCounter());
    stmt->setString(1, request.RenameInfo->NewName);

    _queryProcessor.AddQuery(CharacterDatabase.AsyncQuery(stmt)
        .WithPreparedCallback(std::bind(&WorldSession::HandleCharRenameCallBack, this, request.RenameInfo, std::placeholders::_1)));
}

void WorldSession::HandleCharRenameCallBack(std::shared_ptr<WorldPackets::Character::CharacterRenameInfo> renameInfo, PreparedQueryResult result)
{
    if (!result)
    {
        SendCharRename(CHAR_CREATE_ERROR, renameInfo.get());
        return;
    }

    Field* fields = result->Fetch();

    std::string oldName = fields[0].GetString();
    uint16 atLoginFlags = fields[1].GetUInt16();

    if (!(atLoginFlags & AT_LOGIN_RENAME))
    {
        SendCharRename(CHAR_CREATE_ERROR, renameInfo.get());
        return;
    }

    atLoginFlags &= ~AT_LOGIN_RENAME;

    SQLTransaction trans = CharacterDatabase.BeginTransaction();
    ObjectGuid::LowType lowGuid = renameInfo->Guid.GetCounter();

    // Update name and at_login flag in the db
    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_CHAR_NAME_AT_LOGIN);
    stmt->setString(0, renameInfo->NewName);
    stmt->setUInt16(1, atLoginFlags);
    stmt->setUInt64(2, lowGuid);

    trans->Append(stmt);

    // Removed declined name from db
    stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHAR_DECLINED_NAME);
    stmt->setUInt64(0, lowGuid);

    trans->Append(stmt);

    CharacterDatabase.CommitTransaction(trans);

    TC_LOG_INFO("entities.player.character", "Account: %u (IP: %s) Character:[%s] (%s) Changed name to: %s",
        GetAccountId(), GetRemoteAddress().c_str(), oldName.c_str(), renameInfo->Guid.ToString().c_str(), renameInfo->NewName.c_str());

    SendCharRename(RESPONSE_SUCCESS, renameInfo.get());

    sWorld->UpdateCharacterInfo(renameInfo->Guid, renameInfo->NewName);
}

void WorldSession::HandleSetPlayerDeclinedNames(WorldPackets::Character::SetPlayerDeclinedNames& packet)
{
    // not accept declined names for unsupported languages
    std::string name;
    if (!ObjectMgr::GetPlayerNameByGUID(packet.Player, name))
    {
        SendSetPlayerDeclinedNamesResult(DECLINED_NAMES_RESULT_ERROR, packet.Player);
        return;
    }

    std::wstring wname;
    if (!Utf8toWStr(name, wname))
    {
        SendSetPlayerDeclinedNamesResult(DECLINED_NAMES_RESULT_ERROR, packet.Player);
        return;
    }

    if (!isCyrillicCharacter(wname[0]))                      // name already stored as only single alphabet using
    {
        SendSetPlayerDeclinedNamesResult(DECLINED_NAMES_RESULT_ERROR, packet.Player);
        return;
    }

    for (int i = 0; i < MAX_DECLINED_NAME_CASES; ++i)
    {
        if (!normalizePlayerName(packet.DeclinedNames.name[i]))
        {
            SendSetPlayerDeclinedNamesResult(DECLINED_NAMES_RESULT_ERROR, packet.Player);
            return;
        }
    }

    if (!ObjectMgr::CheckDeclinedNames(wname, packet.DeclinedNames))
    {
        SendSetPlayerDeclinedNamesResult(DECLINED_NAMES_RESULT_ERROR, packet.Player);
        return;
    }

    for (int i = 0; i < MAX_DECLINED_NAME_CASES; ++i)
        CharacterDatabase.EscapeString(packet.DeclinedNames.name[i]);

    SQLTransaction trans = CharacterDatabase.BeginTransaction();

    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHAR_DECLINED_NAME);
    stmt->setUInt64(0, packet.Player.GetCounter());
    trans->Append(stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_CHAR_DECLINED_NAME);
    stmt->setUInt64(0, packet.Player.GetCounter());

    for (uint8 i = 0; i < MAX_DECLINED_NAME_CASES; i++)
        stmt->setString(i + 1, packet.DeclinedNames.name[i]);

    trans->Append(stmt);

    CharacterDatabase.CommitTransaction(trans);

    SendSetPlayerDeclinedNamesResult(DECLINED_NAMES_RESULT_SUCCESS, packet.Player);
}

void WorldSession::HandleAlterAppearance(WorldPackets::Character::AlterApperance& packet)
{
    BarberShopStyleEntry const* bs_hair = sBarberShopStyleStore.LookupEntry(packet.NewHairStyle);
    if (!bs_hair || bs_hair->Type != 0 || bs_hair->Race != _player->getRace() || bs_hair->Sex != _player->GetByteValue(PLAYER_BYTES_3, PLAYER_BYTES_3_OFFSET_GENDER))
        return;

    BarberShopStyleEntry const* bs_facialHair = sBarberShopStyleStore.LookupEntry(packet.NewFacialHair);
    if (!bs_facialHair || bs_facialHair->Type != 2 || bs_facialHair->Race != _player->getRace() || bs_facialHair->Sex != _player->GetByteValue(PLAYER_BYTES_3, PLAYER_BYTES_3_OFFSET_GENDER))
        return;

    BarberShopStyleEntry const* bs_skinColor = sBarberShopStyleStore.LookupEntry(packet.NewSkinColor);
    if (bs_skinColor && (bs_skinColor->Type != 3 || bs_skinColor->Race != _player->getRace() || bs_skinColor->Sex != _player->GetByteValue(PLAYER_BYTES_3, PLAYER_BYTES_3_OFFSET_GENDER)))
        return;

    BarberShopStyleEntry const* bs_face = sBarberShopStyleStore.LookupEntry(packet.NewFace);
    if (bs_face && (bs_face->Type != 4 || bs_face->Race != _player->getRace() || bs_face->Sex != _player->GetByteValue(PLAYER_BYTES_3, PLAYER_BYTES_3_OFFSET_GENDER)))
        return;

    std::array<BarberShopStyleEntry const*, PLAYER_CUSTOM_DISPLAY_SIZE> customDisplayEntries;
    std::array<uint8, PLAYER_CUSTOM_DISPLAY_SIZE> customDisplay;
    for (std::size_t i = 0; i < PLAYER_CUSTOM_DISPLAY_SIZE; ++i)
    {
        BarberShopStyleEntry const* bs_customDisplay = sBarberShopStyleStore.LookupEntry(packet.NewCustomDisplay[i]);
        if (bs_customDisplay && (bs_customDisplay->Type != 5 + i || bs_customDisplay->Race != _player->getRace() || bs_customDisplay->Sex != _player->GetByteValue(PLAYER_BYTES_3, PLAYER_BYTES_3_OFFSET_GENDER)))
            return;

        customDisplayEntries[i] = bs_customDisplay;
        customDisplay[i] = bs_customDisplay ? bs_customDisplay->Data : 0;
    }

    if (!Player::ValidateAppearance(_player->getRace(), _player->getClass(), _player->GetByteValue(PLAYER_BYTES_3, PLAYER_BYTES_3_OFFSET_GENDER),
        bs_hair->Data,
        packet.NewHairColor,
        bs_face ? bs_face->Data : _player->GetByteValue(PLAYER_BYTES, PLAYER_BYTES_OFFSET_FACE_ID),
        bs_facialHair->Data,
        bs_skinColor ? bs_skinColor->Data : _player->GetByteValue(PLAYER_BYTES, PLAYER_BYTES_OFFSET_SKIN_ID),
        customDisplay))
        return;

    GameObject* go = _player->FindNearestGameObjectOfType(GAMEOBJECT_TYPE_BARBER_CHAIR, 5.0f);
    if (!go)
    {
        SendPacket(WorldPackets::Character::BarberShopResult(WorldPackets::Character::BarberShopResult::ResultEnum::NotOnChair).Write());
        return;
    }

    if (_player->GetStandState() != UnitStandStateType(UNIT_STAND_STATE_SIT_LOW_CHAIR + go->GetGOInfo()->barberChair.chairheight))
    {
        SendPacket(WorldPackets::Character::BarberShopResult(WorldPackets::Character::BarberShopResult::ResultEnum::NotOnChair).Write());
        return;
    }

    uint32 cost = _player->GetBarberShopCost(bs_hair, packet.NewHairColor, bs_facialHair, bs_skinColor, bs_face, customDisplayEntries);

    // 0 - ok
    // 1, 3 - not enough money
    // 2 - you have to sit on barber chair
    if (!_player->HasEnoughMoney((uint64)cost))
    {
        SendPacket(WorldPackets::Character::BarberShopResult(WorldPackets::Character::BarberShopResult::ResultEnum::NoMoney).Write());
        return;
    }

    SendPacket(WorldPackets::Character::BarberShopResult(WorldPackets::Character::BarberShopResult::ResultEnum::Success).Write());

    _player->ModifyMoney(-int64(cost));                     // it isn't free
    _player->UpdateCriteria(CRITERIA_TYPE_GOLD_SPENT_AT_BARBER, cost);

    _player->SetByteValue(PLAYER_BYTES, PLAYER_BYTES_OFFSET_HAIR_STYLE_ID, uint8(bs_hair->Data));
    _player->SetByteValue(PLAYER_BYTES, PLAYER_BYTES_OFFSET_HAIR_COLOR_ID, uint8(packet.NewHairColor));
    _player->SetByteValue(PLAYER_BYTES_2, PLAYER_BYTES_2_OFFSET_FACIAL_STYLE, uint8(bs_facialHair->Data));
    if (bs_skinColor)
        _player->SetByteValue(PLAYER_BYTES, PLAYER_BYTES_OFFSET_SKIN_ID, uint8(bs_skinColor->Data));
    if (bs_face)
        _player->SetByteValue(PLAYER_BYTES, PLAYER_BYTES_OFFSET_FACE_ID, uint8(bs_face->Data));

    for (uint32 i = 0; i < PLAYER_CUSTOM_DISPLAY_SIZE; ++i)
        _player->SetByteValue(PLAYER_BYTES_2, PLAYER_BYTES_2_OFFSET_CUSTOM_DISPLAY_OPTION + i, customDisplay[i]);

    _player->UpdateCriteria(CRITERIA_TYPE_VISIT_BARBER_SHOP, 1);

    _player->SetStandState(UNIT_STAND_STATE_STAND);
}

void WorldSession::HandleCharCustomizeOpcode(WorldPackets::Character::CharCustomize& packet)
{
    if (!IsLegitCharacterForAccount(packet.CustomizeInfo->CharGUID))
    {
        TC_LOG_ERROR("entities.player.cheat", "Account %u, IP: %s tried to customise %s, but it does not belong to their account!",
            GetAccountId(), GetRemoteAddress().c_str(), packet.CustomizeInfo->CharGUID.ToString().c_str());
        KickPlayer();
        return;
    }

    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHAR_CUSTOMIZE_INFO);
    stmt->setUInt64(0, packet.CustomizeInfo->CharGUID.GetCounter());

    _queryProcessor.AddQuery(CharacterDatabase.AsyncQuery(stmt)
        .WithPreparedCallback(std::bind(&WorldSession::HandleCharCustomizeCallback, this, packet.CustomizeInfo, std::placeholders::_1)));
}

void WorldSession::HandleCharCustomizeCallback(std::shared_ptr<WorldPackets::Character::CharCustomizeInfo> customizeInfo, PreparedQueryResult result)
{
    if (!result)
    {
        SendCharCustomize(CHAR_CREATE_ERROR, customizeInfo.get());
        return;
    }

    Field* fields = result->Fetch();

    std::string oldName = fields[0].GetString();
    uint8 plrRace = fields[1].GetUInt8();
    uint8 plrClass = fields[2].GetUInt8();
    uint8 plrGender = fields[3].GetUInt8();
    uint16 atLoginFlags = fields[4].GetUInt16();

    if (!Player::ValidateAppearance(plrRace, plrClass, plrGender, customizeInfo->HairStyleID, customizeInfo->HairColorID, customizeInfo->FaceID,
        customizeInfo->FacialHairStyleID, customizeInfo->SkinID, customizeInfo->CustomDisplay))
    {
        SendCharCustomize(CHAR_CREATE_ERROR, customizeInfo.get());
        return;
    }

    if (!(atLoginFlags & AT_LOGIN_CUSTOMIZE))
    {
        SendCharCustomize(CHAR_CREATE_ERROR, customizeInfo.get());
        return;
    }

    // prevent character rename
    if (sWorld->getBoolConfig(CONFIG_PREVENT_RENAME_CUSTOMIZATION) && (customizeInfo->CharName != oldName))
    {
        SendCharCustomize(CHAR_NAME_FAILURE, customizeInfo.get());
        return;
    }

    atLoginFlags &= ~AT_LOGIN_CUSTOMIZE;

    // prevent character rename to invalid name
    if (!normalizePlayerName(customizeInfo->CharName))
    {
        SendCharCustomize(CHAR_NAME_NO_NAME, customizeInfo.get());
        return;
    }

    ResponseCodes res = ObjectMgr::CheckPlayerName(customizeInfo->CharName, GetSessionDbcLocale(), true);
    if (res != CHAR_NAME_SUCCESS)
    {
        SendCharCustomize(res, customizeInfo.get());
        return;
    }

    // check name limitations
    if (!HasPermission(rbac::RBAC_PERM_SKIP_CHECK_CHARACTER_CREATION_RESERVEDNAME) && sObjectMgr->IsReservedName(customizeInfo->CharName))
    {
        SendCharCustomize(CHAR_NAME_RESERVED, customizeInfo.get());
        return;
    }

    // character with this name already exist
    /// @todo: make async
    ObjectGuid newGuid = ObjectMgr::GetPlayerGUIDByName(customizeInfo->CharName);
    if (!newGuid.IsEmpty())
    {
        if (newGuid != customizeInfo->CharGUID)
        {
            SendCharCustomize(CHAR_CREATE_NAME_IN_USE, customizeInfo.get());
            return;
        }
    }

    PreparedStatement* stmt = nullptr;
    SQLTransaction trans = CharacterDatabase.BeginTransaction();

    ObjectGuid::LowType lowGuid = customizeInfo->CharGUID.GetCounter();

    /// Customize
    {
        stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_GENDER_AND_APPEARANCE);

        stmt->setUInt8(0, customizeInfo->SexID);
        stmt->setUInt8(1, customizeInfo->SkinID);
        stmt->setUInt8(2, customizeInfo->FaceID);
        stmt->setUInt8(3, customizeInfo->HairStyleID);
        stmt->setUInt8(4, customizeInfo->HairColorID);
        stmt->setUInt8(5, customizeInfo->FacialHairStyleID);
        stmt->setUInt8(6, customizeInfo->CustomDisplay[0]);
        stmt->setUInt8(7, customizeInfo->CustomDisplay[1]);
        stmt->setUInt8(8, customizeInfo->CustomDisplay[2]);
        stmt->setUInt64(9, lowGuid);

        trans->Append(stmt);
    }

    /// Name Change and update atLogin flags
    {
        stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_CHAR_NAME_AT_LOGIN);
        stmt->setString(0, customizeInfo->CharName);
        stmt->setUInt16(1, atLoginFlags);
        stmt->setUInt64(2, lowGuid);

        trans->Append(stmt);

        stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHAR_DECLINED_NAME);
        stmt->setUInt64(0, lowGuid);

        trans->Append(stmt);
    }

    CharacterDatabase.CommitTransaction(trans);

    sWorld->UpdateCharacterInfo(customizeInfo->CharGUID, customizeInfo->CharName, customizeInfo->SexID);

    SendCharCustomize(RESPONSE_SUCCESS, customizeInfo.get());

    TC_LOG_INFO("entities.player.character", "Account: %u (IP: %s), Character[%s] (%s) Customized to: %s",
        GetAccountId(), GetRemoteAddress().c_str(), oldName.c_str(), customizeInfo->CharGUID.ToString().c_str(), customizeInfo->CharName.c_str());
}

void WorldSession::HandleEquipmentSetSave(WorldPackets::EquipmentSet::SaveEquipmentSet& saveEquipmentSet)
{
    if (saveEquipmentSet.Set.SetID >= MAX_EQUIPMENT_SET_INDEX) // client set slots amount
        return;

    if (saveEquipmentSet.Set.Type > EquipmentSetInfo::TRANSMOG)
        return;

    for (uint8 i = 0; i < EQUIPMENT_SLOT_END; ++i)
    {
        if (!(saveEquipmentSet.Set.IgnoreMask & (1 << i)))
        {
            if (saveEquipmentSet.Set.Type == EquipmentSetInfo::EQUIPMENT)
            {
                saveEquipmentSet.Set.Appearances[i] = 0;

                ObjectGuid const& itemGuid = saveEquipmentSet.Set.Pieces[i];
                if (!itemGuid.IsEmpty())
                {
                    Item* item = _player->GetItemByPos(INVENTORY_SLOT_BAG_0, i);

                    /// cheating check 1 (item equipped but sent empty guid)
                    if (!item)
                        return;

                    /// cheating check 2 (sent guid does not match equipped item)
                    if (item->GetGUID() != itemGuid)
                        return;
                }
                else
                    saveEquipmentSet.Set.IgnoreMask |= 1 << i;
            }
            else
            {
                saveEquipmentSet.Set.Pieces[i].Clear();
                if (saveEquipmentSet.Set.Appearances[i])
                {
                    if (!sItemModifiedAppearanceStore.LookupEntry(saveEquipmentSet.Set.Appearances[i]))
                        return;

                    bool hasAppearance, isTemporary;
                    std::tie(hasAppearance, isTemporary) = GetCollectionMgr()->HasItemAppearance(saveEquipmentSet.Set.Appearances[i]);
                    if (!hasAppearance)
                        return;
                }
                else
                    saveEquipmentSet.Set.IgnoreMask |= 1 << i;
            }
        }
        else
        {
            saveEquipmentSet.Set.Pieces[i].Clear();
            saveEquipmentSet.Set.Appearances[i] = 0;
        }
    }

    saveEquipmentSet.Set.IgnoreMask &= 0x7FFFF; /// clear invalid bits (i > EQUIPMENT_SLOT_END)
    if (saveEquipmentSet.Set.Type == EquipmentSetInfo::EQUIPMENT)
    {
        saveEquipmentSet.Set.Enchants[0] = 0;
        saveEquipmentSet.Set.Enchants[1] = 0;
    }
    else
    {
        auto validateIllusion = [this](uint32 enchantId) -> bool
        {
            SpellItemEnchantmentEntry const* illusion = sSpellItemEnchantmentStore.LookupEntry(enchantId);
            if (!illusion)
                return false;

            if (!illusion->ItemVisual || !(illusion->Flags & ENCHANTMENT_COLLECTABLE))
                return false;

            if (PlayerConditionEntry const* condition = sPlayerConditionStore.LookupEntry(illusion->TransmogPlayerConditionID))
                if (!sConditionMgr->IsPlayerMeetingCondition(_player, condition))
                    return false;

            if (illusion->ScalingClassRestricted > 0 && uint8(illusion->ScalingClassRestricted) != _player->getClass())
                return false;

            return true;
        };

        if (saveEquipmentSet.Set.Enchants[0] && !validateIllusion(saveEquipmentSet.Set.Enchants[0]))
            return;

        if (saveEquipmentSet.Set.Enchants[1] && !validateIllusion(saveEquipmentSet.Set.Enchants[1]))
            return;
    }

    _player->SetEquipmentSet(saveEquipmentSet.Set);
}

void WorldSession::HandleDeleteEquipmentSet(WorldPackets::EquipmentSet::DeleteEquipmentSet& deleteEquipmentSet)
{
    _player->DeleteEquipmentSet(deleteEquipmentSet.ID);
}

void WorldSession::HandleUseEquipmentSet(WorldPackets::EquipmentSet::UseEquipmentSet& useEquipmentSet)
{
    ObjectGuid ignoredItemGuid;
    ignoredItemGuid.SetRawValue(0x0C00040000000000, 0xFFFFFFFFFFFFFFFF);

    for (uint8 i = 0; i < EQUIPMENT_SLOT_END; ++i)
    {
        TC_LOG_DEBUG("entities.player.items", "%s: ContainerSlot: %u, Slot: %u", useEquipmentSet.Items[i].Item.ToString().c_str(), useEquipmentSet.Items[i].ContainerSlot, useEquipmentSet.Items[i].Slot);

        // check if item slot is set to "ignored" (raw value == 1), must not be unequipped then
        if (useEquipmentSet.Items[i].Item == ignoredItemGuid)
            continue;

        // Only equip weapons in combat
        if (_player->IsInCombat() && i != EQUIPMENT_SLOT_MAINHAND && i != EQUIPMENT_SLOT_OFFHAND)
            continue;

        Item* item = _player->GetItemByGuid(useEquipmentSet.Items[i].Item);

        uint16 dstPos = i | (INVENTORY_SLOT_BAG_0 << 8);

        if (!item)
        {
            Item* uItem = _player->GetItemByPos(INVENTORY_SLOT_BAG_0, i);
            if (!uItem)
                continue;

            ItemPosCountVec itemPosCountVec;
            InventoryResult inventoryResult = _player->CanStoreItem(NULL_BAG, NULL_SLOT, itemPosCountVec, uItem, false);
            if (inventoryResult == EQUIP_ERR_OK)
            {
                _player->RemoveItem(INVENTORY_SLOT_BAG_0, i, true);
                _player->StoreItem(itemPosCountVec, uItem, true);
            }
            else
                _player->SendEquipError(inventoryResult, uItem,  NULL);
            continue;
        }

        if (item->GetPos() == dstPos)
            continue;

        _player->SwapItem(item->GetPos(), dstPos);
    }

    WorldPackets::EquipmentSet::UseEquipmentSetResult result;
    result.GUID = useEquipmentSet.GUID;
    result.Reason = 0; // 4 - equipment swap failed - inventory is full
    SendPacket(result.Write());
}

void WorldSession::HandleCharRaceOrFactionChangeOpcode(WorldPackets::Character::CharRaceOrFactionChange& packet)
{
    if (!IsLegitCharacterForAccount(packet.RaceOrFactionChangeInfo->Guid))
    {
        TC_LOG_ERROR("entities.player.cheat", "Account %u, IP: %s tried to factionchange character %s, but it does not belong to their account!",
            GetAccountId(), GetRemoteAddress().c_str(), packet.RaceOrFactionChangeInfo->Guid.ToString().c_str());
        KickPlayer();
        return;
    }

    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHAR_RACE_OR_FACTION_CHANGE_INFOS);
    stmt->setUInt64(0, packet.RaceOrFactionChangeInfo->Guid.GetCounter());

    _queryProcessor.AddQuery(CharacterDatabase.AsyncQuery(stmt)
        .WithPreparedCallback(std::bind(&WorldSession::HandleCharRaceOrFactionChangeCallback, this, packet.RaceOrFactionChangeInfo, std::placeholders::_1)));
}

void WorldSession::HandleCharRaceOrFactionChangeCallback(std::shared_ptr<WorldPackets::Character::CharRaceOrFactionChangeInfo> factionChangeInfo, PreparedQueryResult result)
{
    if (!result)
    {
        SendCharFactionChange(CHAR_CREATE_ERROR, factionChangeInfo.get());
        return;
    }

    // get the players old (at this moment current) race
    CharacterInfo const* characterInfo = sWorld->GetCharacterInfo(factionChangeInfo->Guid);
    if (!characterInfo)
    {
        SendCharFactionChange(CHAR_CREATE_ERROR, factionChangeInfo.get());
        return;
    }

    std::string oldName = characterInfo->Name;
    uint8 oldRace     = characterInfo->Race;
    uint8 playerClass = characterInfo->Class;
    uint8 level       = characterInfo->Level;

    if (!sObjectMgr->GetPlayerInfo(factionChangeInfo->RaceID, playerClass))
    {
        SendCharFactionChange(CHAR_CREATE_ERROR, factionChangeInfo.get());
        return;
    }

    Field* fields              = result->Fetch();
    uint16 atLoginFlags        = fields[0].GetUInt16();
    std::string knownTitlesStr = fields[1].GetString();

    uint16 usedLoginFlag = (factionChangeInfo->FactionChange ? AT_LOGIN_CHANGE_FACTION : AT_LOGIN_CHANGE_RACE);
    if (!(atLoginFlags & usedLoginFlag))
    {
        SendCharFactionChange(CHAR_CREATE_ERROR, factionChangeInfo.get());
        return;
    }

    TeamId newTeamId = Player::TeamIdForRace(factionChangeInfo->RaceID);
    if (newTeamId == TEAM_NEUTRAL)
    {
        SendCharFactionChange(CHAR_CREATE_RESTRICTED_RACECLASS, factionChangeInfo.get());
        return;
    }

    if (factionChangeInfo->FactionChange == (Player::TeamIdForRace(oldRace) == newTeamId))
    {
        SendCharFactionChange(factionChangeInfo->FactionChange ? CHAR_CREATE_CHARACTER_SWAP_FACTION : CHAR_CREATE_CHARACTER_RACE_ONLY, factionChangeInfo.get());
        return;
    }

    if (!HasPermission(rbac::RBAC_PERM_SKIP_CHECK_CHARACTER_CREATION_RACEMASK))
    {
        uint32 raceMaskDisabled = sWorld->getIntConfig(CONFIG_CHARACTER_CREATING_DISABLED_RACEMASK);
        if ((1 << (factionChangeInfo->RaceID - 1)) & raceMaskDisabled)
        {
            SendCharFactionChange(CHAR_CREATE_ERROR, factionChangeInfo.get());
            return;
        }
    }

    // prevent character rename
    if (sWorld->getBoolConfig(CONFIG_PREVENT_RENAME_CUSTOMIZATION) && (factionChangeInfo->Name != oldName))
    {
        SendCharFactionChange(CHAR_NAME_FAILURE, factionChangeInfo.get());
        return;
    }

    // prevent character rename to invalid name
    if (!normalizePlayerName(factionChangeInfo->Name))
    {
        SendCharFactionChange(CHAR_NAME_NO_NAME, factionChangeInfo.get());
        return;
    }

    ResponseCodes res = ObjectMgr::CheckPlayerName(factionChangeInfo->Name, GetSessionDbcLocale(), true);
    if (res != CHAR_NAME_SUCCESS)
    {
        SendCharFactionChange(res, factionChangeInfo.get());
        return;
    }

    // check name limitations
    if (!HasPermission(rbac::RBAC_PERM_SKIP_CHECK_CHARACTER_CREATION_RESERVEDNAME) && sObjectMgr->IsReservedName(factionChangeInfo->Name))
    {
        SendCharFactionChange(CHAR_NAME_RESERVED, factionChangeInfo.get());
        return;
    }

    // character with this name already exist
    ObjectGuid newGuid = ObjectMgr::GetPlayerGUIDByName(factionChangeInfo->Name);
    if (!newGuid.IsEmpty())
    {
        if (newGuid != factionChangeInfo->Guid)
        {
            SendCharFactionChange(CHAR_CREATE_NAME_IN_USE, factionChangeInfo.get());
            return;
        }
    }

    if (sArenaTeamMgr->GetArenaTeamByCaptain(factionChangeInfo->Guid))
    {
        SendCharFactionChange(CHAR_CREATE_CHARACTER_ARENA_LEADER, factionChangeInfo.get());
        return;
    }

    // All checks are fine, deal with race change now
    ObjectGuid::LowType lowGuid = factionChangeInfo->Guid.GetCounter();

    PreparedStatement* stmt = nullptr;
    SQLTransaction trans = CharacterDatabase.BeginTransaction();

    // resurrect the character in case he's dead
    Player::OfflineResurrect(factionChangeInfo->Guid, trans);

    // Name Change and update atLogin flags
    {
        CharacterDatabase.EscapeString(factionChangeInfo->Name);

        stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_CHAR_NAME_AT_LOGIN);
        stmt->setString(0, factionChangeInfo->Name);
        stmt->setUInt16(1, uint16((atLoginFlags | AT_LOGIN_RESURRECT) & ~usedLoginFlag));
        stmt->setUInt64(2, lowGuid);

        trans->Append(stmt);

        stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHAR_DECLINED_NAME);
        stmt->setUInt64(0, lowGuid);

        trans->Append(stmt);
    }

    // Customize
    {
        stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_GENDER_AND_APPEARANCE);
        stmt->setUInt8(0, factionChangeInfo->SexID);
        stmt->setUInt8(1, factionChangeInfo->SkinID);
        stmt->setUInt8(2, factionChangeInfo->FaceID);
        stmt->setUInt8(3, factionChangeInfo->HairStyleID);
        stmt->setUInt8(4, factionChangeInfo->HairColorID);
        stmt->setUInt8(5, factionChangeInfo->FacialHairStyleID);
        stmt->setUInt8(6, factionChangeInfo->CustomDisplay[0]);
        stmt->setUInt8(7, factionChangeInfo->CustomDisplay[1]);
        stmt->setUInt8(8, factionChangeInfo->CustomDisplay[2]);
        stmt->setUInt64(9, lowGuid);

        trans->Append(stmt);
    }

    // Race Change
    {
        stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_CHAR_RACE);
        stmt->setUInt8(0, factionChangeInfo->RaceID);
        stmt->setUInt64(1, lowGuid);

        trans->Append(stmt);
    }

    sWorld->UpdateCharacterInfo(factionChangeInfo->Guid, factionChangeInfo->Name, factionChangeInfo->SexID, factionChangeInfo->RaceID);

    if (oldRace != factionChangeInfo->RaceID)
    {
        // Switch Languages
        // delete all languages first
        stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHAR_SKILL_LANGUAGES);
        stmt->setUInt64(0, lowGuid);
        trans->Append(stmt);

        // Now add them back
        stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_CHAR_SKILL_LANGUAGE);
        stmt->setUInt64(0, lowGuid);

        // Faction specific languages
        if (newTeamId == TEAM_HORDE)
            stmt->setUInt16(1, 109);
        else
            stmt->setUInt16(1, 98);

        trans->Append(stmt);

        // Race specific languages
        if (factionChangeInfo->RaceID != RACE_ORC && factionChangeInfo->RaceID != RACE_HUMAN)
        {
            stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_CHAR_SKILL_LANGUAGE);
            stmt->setUInt64(0, lowGuid);

            switch (factionChangeInfo->RaceID)
            {
                case RACE_DWARF:
                    stmt->setUInt16(1, 111);
                    break;
                case RACE_DRAENEI:
                    stmt->setUInt16(1, 759);
                    break;
                case RACE_GNOME:
                    stmt->setUInt16(1, 313);
                    break;
                case RACE_NIGHTELF:
                    stmt->setUInt16(1, 113);
                    break;
                case RACE_WORGEN:
                    stmt->setUInt16(1, 791);
                    break;
                case RACE_UNDEAD_PLAYER:
                    stmt->setUInt16(1, 673);
                    break;
                case RACE_TAUREN:
                    stmt->setUInt16(1, 115);
                    break;
                case RACE_TROLL:
                    stmt->setUInt16(1, 315);
                    break;
                case RACE_BLOODELF:
                    stmt->setUInt16(1, 137);
                    break;
                case RACE_GOBLIN:
                    stmt->setUInt16(1, 792);
                    break;
            }

            trans->Append(stmt);
        }

        // Team Conversion
        if (factionChangeInfo->FactionChange)
        {
            // Delete all Flypaths
            stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_CHAR_TAXI_PATH);
            stmt->setUInt64(0, lowGuid);
            trans->Append(stmt);

            if (level > 7)
            {
                // Update Taxi path
                // this doesn't seem to be 100% blizzlike... but it can't really be helped.
                std::ostringstream taximaskstream;
                TaxiMask const& factionMask = newTeamId == TEAM_HORDE ? sHordeTaxiNodesMask : sAllianceTaxiNodesMask;
                for (std::size_t i = 0; i < TaxiMaskSize; ++i)
                {
                    // i = (315 - 1) / 8 = 39
                    // m = 1 << ((315 - 1) % 8) = 4
                    uint8 deathKnightExtraNode = playerClass != CLASS_DEATH_KNIGHT || i != 39 ? 0 : 4;
                    taximaskstream << uint32(factionMask[i] | deathKnightExtraNode) << ' ';
                }

                stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_CHAR_TAXIMASK);
                stmt->setString(0, taximaskstream.str());
                stmt->setUInt64(1, lowGuid);
                trans->Append(stmt);
            }

            /// @todo: make this part async
            if (!sWorld->getBoolConfig(CONFIG_ALLOW_TWO_SIDE_INTERACTION_GUILD))
            {
                // Reset guild
                stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_GUILD_MEMBER);
                stmt->setUInt64(0, lowGuid);

                if (PreparedQueryResult memberResult = CharacterDatabase.Query(stmt))
                    if (Guild* guild = sGuildMgr->GetGuildById(memberResult->Fetch()[0].GetUInt64()))
                        guild->DeleteMember(trans, factionChangeInfo->Guid, false, false, true);

                Player::LeaveAllArenaTeams(factionChangeInfo->Guid);
            }

            if (!HasPermission(rbac::RBAC_PERM_TWO_SIDE_ADD_FRIEND))
            {
                // Delete Friend List
                stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHAR_SOCIAL_BY_GUID);
                stmt->setUInt64(0, lowGuid);
                trans->Append(stmt);

                stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHAR_SOCIAL_BY_FRIEND);
                stmt->setUInt64(0, lowGuid);
                trans->Append(stmt);
            }

            // Reset homebind and position
            stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_PLAYER_HOMEBIND);
            stmt->setUInt64(0, lowGuid);
            trans->Append(stmt);

            stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_PLAYER_HOMEBIND);
            stmt->setUInt64(0, lowGuid);

            WorldLocation loc;
            uint16 zoneId = 0;
            if (newTeamId == TEAM_ALLIANCE)
            {
                loc.WorldRelocate(0, -8867.68f, 673.373f, 97.9034f, 0.0f);
                zoneId = 1519;
            }
            else
            {
                loc.WorldRelocate(1, 1633.33f, -4439.11f, 15.7588f, 0.0f);
                zoneId = 1637;
            }

            stmt->setUInt16(1, loc.GetMapId());
            stmt->setUInt16(2, zoneId);
            stmt->setFloat(3, loc.GetPositionX());
            stmt->setFloat(4, loc.GetPositionY());
            stmt->setFloat(5, loc.GetPositionZ());
            trans->Append(stmt);

            Player::SavePositionInDB(loc, zoneId, factionChangeInfo->Guid, trans);

            // Achievement conversion
            for (std::map<uint32, uint32>::const_iterator it = sObjectMgr->FactionChangeAchievements.begin(); it != sObjectMgr->FactionChangeAchievements.end(); ++it)
            {
                uint32 achiev_alliance = it->first;
                uint32 achiev_horde = it->second;

                stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHAR_ACHIEVEMENT_BY_ACHIEVEMENT);
                stmt->setUInt16(0, uint16(newTeamId == TEAM_ALLIANCE ? achiev_alliance : achiev_horde));
                stmt->setUInt64(1, lowGuid);
                trans->Append(stmt);

                stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_CHAR_ACHIEVEMENT);
                stmt->setUInt32(0, uint16(newTeamId == TEAM_ALLIANCE ? achiev_alliance : achiev_horde));
                stmt->setUInt32(1, uint16(newTeamId == TEAM_ALLIANCE ? achiev_horde : achiev_alliance));
                stmt->setUInt64(2, lowGuid);
                trans->Append(stmt);
            }

            // Item conversion
            for (std::map<uint32, uint32>::const_iterator it = sObjectMgr->FactionChangeItems.begin(); it != sObjectMgr->FactionChangeItems.end(); ++it)
            {
                uint32 item_alliance = it->first;
                uint32 item_horde = it->second;

                stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_CHAR_INVENTORY_FACTION_CHANGE);
                stmt->setUInt32(0, (newTeamId == TEAM_ALLIANCE ? item_alliance : item_horde));
                stmt->setUInt32(1, (newTeamId == TEAM_ALLIANCE ? item_horde : item_alliance));
                stmt->setUInt64(2, lowGuid);
                trans->Append(stmt);
            }

            // Delete all current quests
            stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHAR_QUESTSTATUS);
            stmt->setUInt64(0, lowGuid);
            trans->Append(stmt);

            // Quest conversion
            for (std::map<uint32, uint32>::const_iterator it = sObjectMgr->FactionChangeQuests.begin(); it != sObjectMgr->FactionChangeQuests.end(); ++it)
            {
                uint32 quest_alliance = it->first;
                uint32 quest_horde = it->second;

                stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHAR_QUESTSTATUS_REWARDED_BY_QUEST);
                stmt->setUInt64(0, lowGuid);
                stmt->setUInt32(1, (newTeamId == TEAM_ALLIANCE ? quest_alliance : quest_horde));
                trans->Append(stmt);

                stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_CHAR_QUESTSTATUS_REWARDED_FACTION_CHANGE);
                stmt->setUInt32(0, (newTeamId == TEAM_ALLIANCE ? quest_alliance : quest_horde));
                stmt->setUInt32(1, (newTeamId == TEAM_ALLIANCE ? quest_horde : quest_alliance));
                stmt->setUInt64(2, lowGuid);
                trans->Append(stmt);
            }

            // Mark all rewarded quests as "active" (will count for completed quests achievements)
            stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_CHAR_QUESTSTATUS_REWARDED_ACTIVE);
            stmt->setUInt64(0, lowGuid);
            trans->Append(stmt);

            // Disable all old-faction specific quests
            {
                ObjectMgr::QuestMap const& questTemplates = sObjectMgr->GetQuestTemplates();
                for (ObjectMgr::QuestMap::const_iterator iter = questTemplates.begin(); iter != questTemplates.end(); ++iter)
                {
                    Quest const* quest = iter->second;
                    uint64 newRaceMask = (newTeamId == TEAM_ALLIANCE) ? RACEMASK_ALLIANCE : RACEMASK_HORDE;
                    if (quest->GetAllowableRaces() != uint64(-1) && !(quest->GetAllowableRaces() & newRaceMask))
                    {
                        stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_CHAR_QUESTSTATUS_REWARDED_ACTIVE_BY_QUEST);
                        stmt->setUInt64(0, lowGuid);
                        stmt->setUInt32(1, quest->GetQuestId());
                        trans->Append(stmt);
                    }
                }
            }

            // Spell conversion
            for (std::map<uint32, uint32>::const_iterator it = sObjectMgr->FactionChangeSpells.begin(); it != sObjectMgr->FactionChangeSpells.end(); ++it)
            {
                uint32 spell_alliance = it->first;
                uint32 spell_horde = it->second;

                stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHAR_SPELL_BY_SPELL);
                stmt->setUInt32(0, (newTeamId == TEAM_ALLIANCE ? spell_alliance : spell_horde));
                stmt->setUInt64(1, lowGuid);
                trans->Append(stmt);

                stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_CHAR_SPELL_FACTION_CHANGE);
                stmt->setUInt32(0, (newTeamId == TEAM_ALLIANCE ? spell_alliance : spell_horde));
                stmt->setUInt32(1, (newTeamId == TEAM_ALLIANCE ? spell_horde : spell_alliance));
                stmt->setUInt64(2, lowGuid);
                trans->Append(stmt);
            }

            // Reputation conversion
            for (std::map<uint32, uint32>::const_iterator it = sObjectMgr->FactionChangeReputation.begin(); it != sObjectMgr->FactionChangeReputation.end(); ++it)
            {
                uint32 reputation_alliance = it->first;
                uint32 reputation_horde = it->second;
                uint32 newReputation = (newTeamId == TEAM_ALLIANCE) ? reputation_alliance : reputation_horde;
                uint32 oldReputation = (newTeamId == TEAM_ALLIANCE) ? reputation_horde : reputation_alliance;

                // select old standing set in db
                stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHAR_REP_BY_FACTION);
                stmt->setUInt32(0, oldReputation);
                stmt->setUInt64(1, lowGuid);

                if (PreparedQueryResult reputationResult = CharacterDatabase.Query(stmt))
                {
                    fields = reputationResult->Fetch();
                    int32 oldDBRep = fields[0].GetInt32();
                    FactionEntry const* factionEntry = sFactionStore.LookupEntry(oldReputation);

                    // old base reputation
                    int32 oldBaseRep = sObjectMgr->GetBaseReputationOf(factionEntry, oldRace, playerClass);

                    // new base reputation
                    int32 newBaseRep = sObjectMgr->GetBaseReputationOf(sFactionStore.LookupEntry(newReputation), factionChangeInfo->RaceID, playerClass);

                    // final reputation shouldnt change
                    int32 FinalRep = oldDBRep + oldBaseRep;
                    int32 newDBRep = FinalRep - newBaseRep;

                    stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHAR_REP_BY_FACTION);
                    stmt->setUInt32(0, newReputation);
                    stmt->setUInt64(1, lowGuid);
                    trans->Append(stmt);

                    stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_CHAR_REP_FACTION_CHANGE);
                    stmt->setUInt16(0, uint16(newReputation));
                    stmt->setInt32(1, newDBRep);
                    stmt->setUInt16(2, uint16(oldReputation));
                    stmt->setUInt64(3, lowGuid);
                    trans->Append(stmt);
                }
            }

            // Title conversion
            if (!knownTitlesStr.empty())
            {
                uint32 const ktcount = KNOWN_TITLES_SIZE * 2;
                uint32 knownTitles[ktcount];
                Tokenizer tokens(knownTitlesStr, ' ', ktcount);

                if (tokens.size() != ktcount)
                {
                    SendCharFactionChange(CHAR_CREATE_ERROR, factionChangeInfo.get());
                    return;
                }

                for (uint32 index = 0; index < ktcount; ++index)
                    knownTitles[index] = atoul(tokens[index]);

                for (std::map<uint32, uint32>::const_iterator it = sObjectMgr->FactionChangeTitles.begin(); it != sObjectMgr->FactionChangeTitles.end(); ++it)
                {
                    uint32 title_alliance = it->first;
                    uint32 title_horde = it->second;

                    CharTitlesEntry const* atitleInfo = sCharTitlesStore.AssertEntry(title_alliance);
                    CharTitlesEntry const* htitleInfo = sCharTitlesStore.AssertEntry(title_horde);
                    // new team
                    if (newTeamId == TEAM_ALLIANCE)
                    {
                        uint32 maskID = htitleInfo->MaskID;
                        uint32 index = maskID / 32;
                        uint32 old_flag = 1 << (maskID % 32);
                        uint32 new_flag = 1 << (atitleInfo->MaskID % 32);
                        if (knownTitles[index] & old_flag)
                        {
                            knownTitles[index] &= ~old_flag;
                            // use index of the new title
                            knownTitles[atitleInfo->MaskID / 32] |= new_flag;
                        }
                    }
                    else
                    {
                        uint32 maskID = atitleInfo->MaskID;
                        uint32 index = maskID / 32;
                        uint32 old_flag = 1 << (maskID % 32);
                        uint32 new_flag = 1 << (htitleInfo->MaskID % 32);
                        if (knownTitles[index] & old_flag)
                        {
                            knownTitles[index] &= ~old_flag;
                            // use index of the new title
                            knownTitles[htitleInfo->MaskID / 32] |= new_flag;
                        }
                    }

                    std::ostringstream ss;
                    for (uint32 index = 0; index < ktcount; ++index)
                        ss << knownTitles[index] << ' ';

                    stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_CHAR_TITLES_FACTION_CHANGE);
                    stmt->setString(0, ss.str());
                    stmt->setUInt64(1, lowGuid);
                    trans->Append(stmt);

                    // unset any currently chosen title
                    stmt = CharacterDatabase.GetPreparedStatement(CHAR_RES_CHAR_TITLES_FACTION_CHANGE);
                    stmt->setUInt64(0, lowGuid);
                    trans->Append(stmt);
                }
            }
        }
    }

    CharacterDatabase.CommitTransaction(trans);

    TC_LOG_DEBUG("entities.player", "%s (IP: %s) changed race from %u to %u", GetPlayerInfo().c_str(), GetRemoteAddress().c_str(), oldRace, factionChangeInfo->RaceID);

    SendCharFactionChange(RESPONSE_SUCCESS, factionChangeInfo.get());
}

void WorldSession::HandleRandomizeCharNameOpcode(WorldPackets::Character::GenerateRandomCharacterName& packet)
{
    if (!Player::IsValidRace(packet.Race))
    {
        TC_LOG_ERROR("misc", "Invalid race (%u) sent by accountId: %u", packet.Race, GetAccountId());
        return;
    }

    if (!Player::IsValidGender(packet.Sex))
    {
        TC_LOG_ERROR("misc", "Invalid gender (%u) sent by accountId: %u", packet.Sex, GetAccountId());
        return;
    }

    WorldPackets::Character::GenerateRandomCharacterNameResult result;
    result.Success = true;
    result.Name = sDB2Manager.GetNameGenEntry(packet.Race, packet.Sex);

    SendPacket(result.Write());
}

void WorldSession::HandleReorderCharacters(WorldPackets::Character::ReorderCharacters& reorderChars)
{
    SQLTransaction trans = CharacterDatabase.BeginTransaction();

    for (WorldPackets::Character::ReorderCharacters::ReorderInfo const& reorderInfo : reorderChars.Entries)
    {
        PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_CHAR_LIST_SLOT);
        stmt->setUInt8(0, reorderInfo.NewPosition);
        stmt->setUInt64(1, reorderInfo.PlayerGUID.GetCounter());
        stmt->setUInt32(2, GetAccountId());
        trans->Append(stmt);
    }

    CharacterDatabase.CommitTransaction(trans);
}

void WorldSession::HandleOpeningCinematic(WorldPackets::Misc::OpeningCinematic& /*packet*/)
{
    // Only players that has not yet gained any experience can use this
    if (_player->GetUInt32Value(PLAYER_XP))
        return;

    if (ChrClassesEntry const* classEntry = sChrClassesStore.LookupEntry(_player->getClass()))
    {
        if (classEntry->CinematicSequenceID)
            _player->SendCinematicStart(classEntry->CinematicSequenceID);
        else if (ChrRacesEntry const* raceEntry = sChrRacesStore.LookupEntry(_player->getRace()))
            _player->SendCinematicStart(raceEntry->CinematicSequenceID);
    }
}

void WorldSession::HandleGetUndeleteCooldownStatus(WorldPackets::Character::GetUndeleteCharacterCooldownStatus& /*getCooldown*/)
{
    PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_SEL_LAST_CHAR_UNDELETE);
    stmt->setUInt32(0, GetBattlenetAccountId());

    _queryProcessor.AddQuery(LoginDatabase.AsyncQuery(stmt).WithPreparedCallback(std::bind(&WorldSession::HandleUndeleteCooldownStatusCallback, this, std::placeholders::_1)));
}

void WorldSession::HandleUndeleteCooldownStatusCallback(PreparedQueryResult result)
{
    uint32 cooldown = 0;
    uint32 maxCooldown = sWorld->getIntConfig(CONFIG_FEATURE_SYSTEM_CHARACTER_UNDELETE_COOLDOWN);
    if (result)
    {
        uint32 lastUndelete = result->Fetch()[0].GetUInt32();
        uint32 now = uint32(time(nullptr));
        if (lastUndelete + maxCooldown > now)
            cooldown = std::max<uint32>(0, lastUndelete + maxCooldown - now);
    }

    SendUndeleteCooldownStatusResponse(cooldown, maxCooldown);
}

void WorldSession::HandleCharUndeleteOpcode(WorldPackets::Character::UndeleteCharacter& undeleteCharacter)
{
    if (!sWorld->getBoolConfig(CONFIG_FEATURE_SYSTEM_CHARACTER_UNDELETE_ENABLED))
    {
        SendUndeleteCharacterResponse(CHARACTER_UNDELETE_RESULT_ERROR_DISABLED, undeleteCharacter.UndeleteInfo.get());
        return;
    }

    PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_SEL_LAST_CHAR_UNDELETE);
    stmt->setUInt32(0, GetBattlenetAccountId());

    std::shared_ptr<WorldPackets::Character::CharacterUndeleteInfo> undeleteInfo = undeleteCharacter.UndeleteInfo;
    _queryProcessor.AddQuery(LoginDatabase.AsyncQuery(stmt)
        .WithChainingPreparedCallback([this, undeleteInfo](QueryCallback& queryCallback, PreparedQueryResult result)
    {
        if (result)
        {
            uint32 lastUndelete = result->Fetch()[0].GetUInt32();
            uint32 maxCooldown = sWorld->getIntConfig(CONFIG_FEATURE_SYSTEM_CHARACTER_UNDELETE_COOLDOWN);
            if (lastUndelete && (lastUndelete + maxCooldown > time(nullptr)))
            {
                SendUndeleteCharacterResponse(CHARACTER_UNDELETE_RESULT_ERROR_COOLDOWN, undeleteInfo.get());
                return;
            }
        }

        PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHAR_DEL_INFO_BY_GUID);
        stmt->setUInt64(0, undeleteInfo->CharacterGuid.GetCounter());
        queryCallback.SetNextQuery(CharacterDatabase.AsyncQuery(stmt));
    })
        .WithChainingPreparedCallback([this, undeleteInfo](QueryCallback& queryCallback, PreparedQueryResult result)
    {
        if (!result)
        {
            SendUndeleteCharacterResponse(CHARACTER_UNDELETE_RESULT_ERROR_CHAR_CREATE, undeleteInfo.get());
            return;
        }

        Field* fields = result->Fetch();
        undeleteInfo->Name = fields[1].GetString();
        uint32 account = fields[2].GetUInt32();

        if (account != GetAccountId())
        {
            SendUndeleteCharacterResponse(CHARACTER_UNDELETE_RESULT_ERROR_UNKNOWN, undeleteInfo.get());
            return;
        }

        PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHECK_NAME);
        stmt->setString(0, undeleteInfo->Name);
        queryCallback.SetNextQuery(CharacterDatabase.AsyncQuery(stmt));
    })
        .WithChainingPreparedCallback([this, undeleteInfo](QueryCallback& queryCallback, PreparedQueryResult result)
    {
        if (result)
        {
            SendUndeleteCharacterResponse(CHARACTER_UNDELETE_RESULT_ERROR_NAME_TAKEN_BY_THIS_ACCOUNT, undeleteInfo.get());
            return;
        }

        /// @todo: add more safety checks
        /// * max char count per account
        /// * max death knight count
        /// * max demon hunter count
        /// * team violation

        PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_SUM_CHARS);
        stmt->setUInt32(0, GetAccountId());
        queryCallback.SetNextQuery(CharacterDatabase.AsyncQuery(stmt));
    })
        .WithPreparedCallback([this, undeleteInfo](PreparedQueryResult result)
    {
        if (result)
        {
            Field* fields = result->Fetch();

            if (fields[0].GetUInt64() >= sWorld->getIntConfig(CONFIG_CHARACTERS_PER_REALM)) // SQL's COUNT() returns uint64 but it will always be less than uint8.Max
            {
                SendUndeleteCharacterResponse(CHARACTER_UNDELETE_RESULT_ERROR_CHAR_CREATE, undeleteInfo.get());
                return;
            }
        }

        PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_RESTORE_DELETE_INFO);
        stmt->setString(0, undeleteInfo->Name);
        stmt->setUInt32(1, GetAccountId());
        stmt->setUInt64(2, undeleteInfo->CharacterGuid.GetCounter());
        CharacterDatabase.Execute(stmt);

        stmt = LoginDatabase.GetPreparedStatement(LOGIN_UPD_LAST_CHAR_UNDELETE);
        stmt->setUInt32(0, GetBattlenetAccountId());
        LoginDatabase.Execute(stmt);

        sWorld->UpdateCharacterInfoDeleted(undeleteInfo->CharacterGuid, false, &undeleteInfo->Name);

        SendUndeleteCharacterResponse(CHARACTER_UNDELETE_RESULT_OK, undeleteInfo.get());
    }));
}

void WorldSession::SendCharCreate(ResponseCodes result)
{
    WorldPackets::Character::CreateChar response;
    response.Code = result;

    SendPacket(response.Write());
}

void WorldSession::SendCharDelete(ResponseCodes result)
{
    WorldPackets::Character::DeleteChar response;
    response.Code = result;

    SendPacket(response.Write());
}

void WorldSession::SendCharRename(ResponseCodes result, WorldPackets::Character::CharacterRenameInfo const* renameInfo)
{
    WorldPackets::Character::CharacterRenameResult packet;
    packet.Result = result;
    packet.Name = renameInfo->NewName;
    if (result == RESPONSE_SUCCESS)
        packet.Guid = renameInfo->Guid;

    SendPacket(packet.Write());
}

void WorldSession::SendCharCustomize(ResponseCodes result, WorldPackets::Character::CharCustomizeInfo const* customizeInfo)
{
    if (result == RESPONSE_SUCCESS)
    {
        WorldPackets::Character::CharCustomizeResponse response(customizeInfo);
        SendPacket(response.Write());
    }
    else
    {
        WorldPackets::Character::CharCustomizeFailed failed;
        failed.Result = uint8(result);
        failed.CharGUID = customizeInfo->CharGUID;
        SendPacket(failed.Write());
    }
}

void WorldSession::SendCharFactionChange(ResponseCodes result, WorldPackets::Character::CharRaceOrFactionChangeInfo const* factionChangeInfo)
{
    WorldPackets::Character::CharFactionChangeResult packet;
    packet.Result = result;
    packet.Guid = factionChangeInfo->Guid;

    if (result == RESPONSE_SUCCESS)
    {
        packet.Display = boost::in_place();
        packet.Display->Name = factionChangeInfo->Name;
        packet.Display->SexID = factionChangeInfo->SexID;
        packet.Display->SkinID = factionChangeInfo->SkinID;
        packet.Display->HairColorID = factionChangeInfo->HairColorID;
        packet.Display->HairStyleID = factionChangeInfo->HairStyleID;
        packet.Display->FacialHairStyleID = factionChangeInfo->FacialHairStyleID;
        packet.Display->FaceID = factionChangeInfo->FaceID;
        packet.Display->RaceID = factionChangeInfo->RaceID;
        packet.Display->CustomDisplay = factionChangeInfo->CustomDisplay;
    }

    SendPacket(packet.Write());
}

void WorldSession::SendSetPlayerDeclinedNamesResult(DeclinedNameResult result, ObjectGuid guid)
{
    WorldPackets::Character::SetPlayerDeclinedNamesResult packet;
    packet.ResultCode = result;
    packet.Player = guid;

    SendPacket(packet.Write());
}

void WorldSession::SendUndeleteCooldownStatusResponse(uint32 currentCooldown, uint32 maxCooldown)
{
    WorldPackets::Character::UndeleteCooldownStatusResponse response;
    response.OnCooldown = (currentCooldown > 0);
    response.MaxCooldown = maxCooldown;
    response.CurrentCooldown = currentCooldown;

    SendPacket(response.Write());
}

void WorldSession::SendUndeleteCharacterResponse(CharacterUndeleteResult result, WorldPackets::Character::CharacterUndeleteInfo const* undeleteInfo)
{
    WorldPackets::Character::UndeleteCharacterResponse response;
    response.UndeleteInfo = undeleteInfo;
    response.Result = result;

    SendPacket(response.Write());
}
