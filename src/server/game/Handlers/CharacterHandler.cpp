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

#include "WorldSession.h"
#include "AccountMgr.h"
#include "ArenaTeam.h"
#include "ArenaTeamMgr.h"
#include "ArtifactPackets.h"
#include "AuctionHousePackets.h"
#include "AuthenticationPackets.h"
#include "Battleground.h"
#include "BattlegroundPackets.h"
#include "BattlePetMgr.h"
#include "CalendarMgr.h"
#include "CharacterCache.h"
#include "CharacterPackets.h"
#include "Chat.h"
#include "Common.h"
#include "Containers.h"
#include "DatabaseEnv.h"
#include "DB2Stores.h"
#include "EquipmentSetPackets.h"
#include "GameObject.h"
#include "GameTime.h"
#include "GitRevision.h"
#include "Group.h"
#include "GroupMgr.h"
#include "Guild.h"
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
#include "SocialMgr.h"
#include "StringConvert.h"
#include "SystemPackets.h"
#include "Util.h"
#include "World.h"
#include <sstream>

class LoginQueryHolder : public CharacterDatabaseQueryHolder
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

    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHARACTER);
    stmt->setUInt64(0, lowGuid);
    res &= SetPreparedQuery(PLAYER_LOGIN_QUERY_LOAD_FROM, stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHARACTER_CUSTOMIZATIONS);
    stmt->setUInt64(0, lowGuid);
    res &= SetPreparedQuery(PLAYER_LOGIN_QUERY_LOAD_CUSTOMIZATIONS, stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_GROUP_MEMBER);
    stmt->setUInt64(0, lowGuid);
    res &= SetPreparedQuery(PLAYER_LOGIN_QUERY_LOAD_GROUP, stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHARACTER_AURAS);
    stmt->setUInt64(0, lowGuid);
    res &= SetPreparedQuery(PLAYER_LOGIN_QUERY_LOAD_AURAS, stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHARACTER_AURA_EFFECTS);
    stmt->setUInt64(0, lowGuid);
    res &= SetPreparedQuery(PLAYER_LOGIN_QUERY_LOAD_AURA_EFFECTS, stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHARACTER_AURA_STORED_LOCATIONS);
    stmt->setUInt64(0, lowGuid);
    res &= SetPreparedQuery(PLAYER_LOGIN_QUERY_LOAD_AURA_STORED_LOCATIONS, stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHARACTER_SPELL);
    stmt->setUInt64(0, lowGuid);
    res &= SetPreparedQuery(PLAYER_LOGIN_QUERY_LOAD_SPELLS, stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHARACTER_SPELL_FAVORITES);
    stmt->setUInt64(0, lowGuid);
    res &= SetPreparedQuery(PLAYER_LOGIN_QUERY_LOAD_SPELL_FAVORITES, stmt);

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

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_ITEM_INSTANCE_AZERITE);
    stmt->setUInt64(0, lowGuid);
    res &= SetPreparedQuery(PLAYER_LOGIN_QUERY_LOAD_AZERITE, stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_ITEM_INSTANCE_AZERITE_MILESTONE_POWER);
    stmt->setUInt64(0, lowGuid);
    res &= SetPreparedQuery(PLAYER_LOGIN_QUERY_LOAD_AZERITE_MILESTONE_POWERS, stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_ITEM_INSTANCE_AZERITE_UNLOCKED_ESSENCE);
    stmt->setUInt64(0, lowGuid);
    res &= SetPreparedQuery(PLAYER_LOGIN_QUERY_LOAD_AZERITE_UNLOCKED_ESSENCES, stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_ITEM_INSTANCE_AZERITE_EMPOWERED);
    stmt->setUInt64(0, lowGuid);
    res &= SetPreparedQuery(PLAYER_LOGIN_QUERY_LOAD_AZERITE_EMPOWERED, stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHAR_VOID_STORAGE);
    stmt->setUInt64(0, lowGuid);
    res &= SetPreparedQuery(PLAYER_LOGIN_QUERY_LOAD_VOID_STORAGE, stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_MAIL);
    stmt->setUInt64(0, lowGuid);
    res &= SetPreparedQuery(PLAYER_LOGIN_QUERY_LOAD_MAILS, stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_MAILITEMS);
    stmt->setUInt64(0, lowGuid);
    res &= SetPreparedQuery(PLAYER_LOGIN_QUERY_LOAD_MAIL_ITEMS, stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_MAILITEMS_ARTIFACT);
    stmt->setUInt64(0, lowGuid);
    res &= SetPreparedQuery(PLAYER_LOGIN_QUERY_LOAD_MAIL_ITEMS_ARTIFACT, stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_MAILITEMS_AZERITE);
    stmt->setUInt64(0, lowGuid);
    res &= SetPreparedQuery(PLAYER_LOGIN_QUERY_LOAD_MAIL_ITEMS_AZERITE, stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_MAILITEMS_AZERITE_MILESTONE_POWER);
    stmt->setUInt64(0, lowGuid);
    res &= SetPreparedQuery(PLAYER_LOGIN_QUERY_LOAD_MAIL_ITEMS_AZERITE_MILESTONE_POWER, stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_MAILITEMS_AZERITE_UNLOCKED_ESSENCE);
    stmt->setUInt64(0, lowGuid);
    res &= SetPreparedQuery(PLAYER_LOGIN_QUERY_LOAD_MAIL_ITEMS_AZERITE_UNLOCKED_ESSENCE, stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_MAILITEMS_AZERITE_EMPOWERED);
    stmt->setUInt64(0, lowGuid);
    res &= SetPreparedQuery(PLAYER_LOGIN_QUERY_LOAD_MAIL_ITEMS_AZERITE_EMPOWERED, stmt);

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

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHAR_PETS);
    stmt->setUInt64(0, lowGuid);
    res &= SetPreparedQuery(PLAYER_LOGIN_QUERY_LOAD_PET_SLOTS, stmt);

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

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHAR_TRAIT_ENTRIES);
    stmt->setUInt64(0, lowGuid);
    res &= SetPreparedQuery(PLAYER_LOGIN_QUERY_LOAD_TRAIT_ENTRIES, stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHAR_TRAIT_CONFIGS);
    stmt->setUInt64(0, lowGuid);
    res &= SetPreparedQuery(PLAYER_LOGIN_QUERY_LOAD_TRAIT_CONFIGS, stmt);

    return res;
}

class EnumCharactersQueryHolder : public CharacterDatabaseQueryHolder
{
public:
    enum
    {
        CHARACTERS,
        CUSTOMIZATIONS,

        MAX
    };

    EnumCharactersQueryHolder()
    {
        SetSize(MAX);
    }

    bool Initialize(uint32 accountId, bool withDeclinedNames, bool isDeletedCharacters)
    {
        _isDeletedCharacters = isDeletedCharacters;

        constexpr CharacterDatabaseStatements statements[2][3] =
        {
            { CHAR_SEL_ENUM, CHAR_SEL_ENUM_DECLINED_NAME, CHAR_SEL_ENUM_CUSTOMIZATIONS },
            { CHAR_SEL_UNDELETE_ENUM, CHAR_SEL_UNDELETE_ENUM_DECLINED_NAME, CHAR_SEL_UNDELETE_ENUM_CUSTOMIZATIONS }
        };

        bool result = true;
        CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(statements[isDeletedCharacters ? 1 : 0][withDeclinedNames ? 1 : 0]);
        stmt->setUInt32(0, accountId);
        result &= SetPreparedQuery(CHARACTERS, stmt);

        stmt = CharacterDatabase.GetPreparedStatement(statements[isDeletedCharacters ? 1 : 0][2]);
        stmt->setUInt32(0, accountId);
        result &= SetPreparedQuery(CUSTOMIZATIONS, stmt);

        return result;
    }

    bool IsDeletedCharacters() const { return _isDeletedCharacters; }

private:
    bool _isDeletedCharacters = false;
};

void WorldSession::HandleCharEnum(CharacterDatabaseQueryHolder const& holder)
{
    WorldPackets::Character::EnumCharactersResult charEnum;
    charEnum.Success = true;
    charEnum.IsDeletedCharacters = static_cast<EnumCharactersQueryHolder const&>(holder).IsDeletedCharacters();
    charEnum.DisabledClassesMask = sWorld->getIntConfig(CONFIG_CHARACTER_CREATING_DISABLED_CLASSMASK);

    if (!charEnum.IsDeletedCharacters)
        _legitCharacters.clear();

    std::unordered_map<ObjectGuid::LowType, std::vector<UF::ChrCustomizationChoice>> customizations;
    if (PreparedQueryResult customizationsResult = holder.GetPreparedResult(EnumCharactersQueryHolder::CUSTOMIZATIONS))
    {
        do
        {
            Field* fields = customizationsResult->Fetch();
            UF::ChrCustomizationChoice& choice = customizations[fields[0].GetUInt64()].emplace_back();
            choice.ChrCustomizationOptionID = fields[1].GetUInt32();
            choice.ChrCustomizationChoiceID = fields[2].GetUInt32();

        } while (customizationsResult->NextRow());
    }

    if (PreparedQueryResult result = holder.GetPreparedResult(EnumCharactersQueryHolder::CHARACTERS))
    {
        do
        {
            charEnum.Characters.emplace_back(result->Fetch());

            WorldPackets::Character::EnumCharactersResult::CharacterInfo& charInfo = charEnum.Characters.back();

            if (std::vector<UF::ChrCustomizationChoice>* customizationsForChar = Trinity::Containers::MapGetValuePtr(customizations, charInfo.Guid.GetCounter()))
                charInfo.Customizations = std::move(*customizationsForChar);

            TC_LOG_INFO("network", "Loading char guid {} from account {}.", charInfo.Guid.ToString(), GetAccountId());

            if (!charEnum.IsDeletedCharacters)
            {
                if (!ValidateAppearance(Races(charInfo.RaceID), Classes(charInfo.ClassID), Gender(charInfo.SexID), MakeChrCustomizationChoiceRange(charInfo.Customizations)))
                {
                    TC_LOG_ERROR("entities.player.loading", "Player {} has wrong Appearance values (Hair/Skin/Color), forcing recustomize", charInfo.Guid.ToString());

                    charInfo.Customizations.clear();

                    if (!(charInfo.Flags2 & (CHAR_CUSTOMIZE_FLAG_CUSTOMIZE | CHAR_CUSTOMIZE_FLAG_FACTION | CHAR_CUSTOMIZE_FLAG_RACE)))
                    {
                        CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_ADD_AT_LOGIN_FLAG);
                        stmt->setUInt16(0, uint16(AT_LOGIN_CUSTOMIZE));
                        stmt->setUInt64(1, charInfo.Guid.GetCounter());
                        CharacterDatabase.Execute(stmt);
                        charInfo.Flags2 = CHAR_CUSTOMIZE_FLAG_CUSTOMIZE;
                    }
                }

                // Do not allow locked characters to login
                if (!(charInfo.Flags & (CHARACTER_FLAG_LOCKED_FOR_TRANSFER | CHARACTER_FLAG_LOCKED_BY_BILLING)))
                    _legitCharacters.insert(charInfo.Guid);
            }

            if (!sCharacterCache->HasCharacterCacheEntry(charInfo.Guid)) // This can happen if characters are inserted into the database manually. Core hasn't loaded name data yet.
                sCharacterCache->AddCharacterCacheEntry(charInfo.Guid, GetAccountId(), charInfo.Name, charInfo.SexID, charInfo.RaceID, charInfo.ClassID, charInfo.ExperienceLevel, false);

            charEnum.MaxCharacterLevel = std::max<int32>(charEnum.MaxCharacterLevel, charInfo.ExperienceLevel);
        }
        while (result->NextRow() && charEnum.Characters.size() < MAX_CHARACTERS_PER_REALM);
    }

    for (std::pair<uint8 const, RaceUnlockRequirement> const& requirement : sObjectMgr->GetRaceUnlockRequirements())
    {
        WorldPackets::Character::EnumCharactersResult::RaceUnlock raceUnlock;
        raceUnlock.RaceID = requirement.first;
        raceUnlock.HasExpansion = GetAccountExpansion() >= requirement.second.Expansion;
        raceUnlock.HasAchievement = requirement.second.AchievementId != 0
            && (sWorld->getBoolConfig(CONFIG_CHARACTER_CREATING_DISABLE_ALLIED_RACE_ACHIEVEMENT_REQUIREMENT)
                /* || HasAccountAchievement(requirement.second.AchievementId)*/);
        charEnum.RaceUnlockData.push_back(raceUnlock);
    }

    SendPacket(charEnum.Write());
}

void WorldSession::HandleCharEnumOpcode(WorldPackets::Character::EnumCharacters& /*enumCharacters*/)
{
    // remove expired bans
    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_EXPIRED_BANS);
    CharacterDatabase.Execute(stmt);

    /// get all the data necessary for loading all characters (along with their pets) on the account
    std::shared_ptr<EnumCharactersQueryHolder> holder = std::make_shared<EnumCharactersQueryHolder>();
    if (!holder->Initialize(GetAccountId(), sWorld->getBoolConfig(CONFIG_DECLINED_NAMES_USED), false))
    {
        HandleCharEnum(*holder);
        return;
    }

    AddQueryHolderCallback(CharacterDatabase.DelayQueryHolder(holder)).AfterComplete([this](SQLQueryHolderBase const& result)
    {
        HandleCharEnum(static_cast<EnumCharactersQueryHolder const&>(result));
    });
}

void WorldSession::HandleCharUndeleteEnumOpcode(WorldPackets::Character::EnumCharacters& /*enumCharacters*/)
{
    /// get all the data necessary for loading all undeleted characters (along with their pets) on the account
    std::shared_ptr<EnumCharactersQueryHolder> holder = std::make_shared<EnumCharactersQueryHolder>();
    if (!holder->Initialize(GetAccountId(), sWorld->getBoolConfig(CONFIG_DECLINED_NAMES_USED), true))
    {
        HandleCharEnum(*holder);
        return;
    }

    AddQueryHolderCallback(CharacterDatabase.DelayQueryHolder(holder)).AfterComplete([this](SQLQueryHolderBase const& result)
    {
        HandleCharEnum(static_cast<EnumCharactersQueryHolder const&>(result));
    });
}

bool WorldSession::MeetsChrCustomizationReq(ChrCustomizationReqEntry const* req, Races race, Classes playerClass,
    bool checkRequiredDependentChoices, Trinity::IteratorPair<UF::ChrCustomizationChoice const*> selectedChoices) const
{
    if (!req->GetFlags().HasFlag(ChrCustomizationReqFlag::HasRequirements))
        return true;

    if (req->ClassMask && !(req->ClassMask & (1 << (playerClass - 1))))
        return false;

    if (race != RACE_NONE && !req->RaceMask.IsEmpty() && req->RaceMask.RawValue != -1 && !req->RaceMask.HasRace(race))
        return false;

    if (req->AchievementID /*&& !HasAchieved(req->AchievementID)*/)
        return false;

    if (req->ItemModifiedAppearanceID && !GetCollectionMgr()->HasItemAppearance(req->ItemModifiedAppearanceID).first)
        return false;

    if (req->QuestID)
    {
        if (!_player)
            return false;

        if (!_player->IsQuestRewarded(req->QuestID))
            return false;
    }

    if (checkRequiredDependentChoices)
    {
        if (std::vector<std::pair<uint32, std::vector<uint32>>> const* requiredChoices = sDB2Manager.GetRequiredCustomizationChoices(req->ID))
        {
            for (auto const& [chrCustomizationOptionId, requiredChoicesForOption] : *requiredChoices)
            {
                bool hasRequiredChoiceForOption = false;
                for (uint32 requiredChoice : requiredChoicesForOption)
                {
                    auto choiceItr = std::find_if(selectedChoices.begin(), selectedChoices.end(), [requiredChoice](UF::ChrCustomizationChoice const& choice)
                    {
                        return choice.ChrCustomizationChoiceID == requiredChoice;
                    });

                    if (choiceItr != selectedChoices.end())
                    {
                        hasRequiredChoiceForOption = true;
                        break;
                    }
                }

                if (!hasRequiredChoiceForOption)
                    return false;
            }
        }
    }

    return true;
}

bool WorldSession::ValidateAppearance(Races race, Classes playerClass, Gender gender, Trinity::IteratorPair<UF::ChrCustomizationChoice const*> customizations)
{
    std::vector<ChrCustomizationOptionEntry const*> const* options = sDB2Manager.GetCustomiztionOptions(race, gender);
    if (!options)
        return false;

    uint32 previousOption = 0;

    for (UF::ChrCustomizationChoice playerChoice : customizations)
    {
        // check uniqueness of options
        if (playerChoice.ChrCustomizationOptionID == previousOption)
            return false;

        previousOption = playerChoice.ChrCustomizationOptionID;

        // check if we can use this option
        auto customizationOptionDataItr = std::find_if(options->begin(), options->end(), [&](ChrCustomizationOptionEntry const* option)
        {
            return option->ID == playerChoice.ChrCustomizationOptionID;
        });

        // option not found for race/gender combination
        if (customizationOptionDataItr == options->end())
            return false;

        if (ChrCustomizationReqEntry const* req = sChrCustomizationReqStore.LookupEntry((*customizationOptionDataItr)->ChrCustomizationReqID))
            if (!MeetsChrCustomizationReq(req, race, playerClass, false, customizations))
                return false;

        std::vector<ChrCustomizationChoiceEntry const*> const* choicesForOption = sDB2Manager.GetCustomiztionChoices(playerChoice.ChrCustomizationOptionID);
        if (!choicesForOption)
            return false;

        auto customizationChoiceDataItr = std::find_if(choicesForOption->begin(), choicesForOption->end(), [&](ChrCustomizationChoiceEntry const* choice)
        {
            return choice->ID == playerChoice.ChrCustomizationChoiceID;
        });

        // choice not found for option
        if (customizationChoiceDataItr == choicesForOption->end())
            return false;

        if (ChrCustomizationReqEntry const* req = sChrCustomizationReqStore.LookupEntry((*customizationChoiceDataItr)->ChrCustomizationReqID))
            if (!MeetsChrCustomizationReq(req, race, playerClass, true, customizations))
                return false;
    }

    return true;
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
        TC_LOG_ERROR("network", "Class ({}) not found in DBC while creating new char for account (ID: {}): wrong DBC files or cheater?", charCreate.CreateInfo->Class, GetAccountId());
        SendCharCreate(CHAR_CREATE_FAILED);
        return;
    }

    ChrRacesEntry const* raceEntry = sChrRacesStore.LookupEntry(charCreate.CreateInfo->Race);
    if (!raceEntry)
    {
        TC_LOG_ERROR("network", "Race ({}) not found in DBC while creating new char for account (ID: {}): wrong DBC files or cheater?", charCreate.CreateInfo->Race, GetAccountId());
        SendCharCreate(CHAR_CREATE_FAILED);
        return;
    }

    // prevent character creating Expansion race without Expansion account
    RaceUnlockRequirement const* raceExpansionRequirement = sObjectMgr->GetRaceUnlockRequirement(charCreate.CreateInfo->Race);
    if (!raceExpansionRequirement)
    {
        TC_LOG_ERROR("entities.player.cheat", "Account {} tried to create character with unavailable race {}", GetAccountId(), charCreate.CreateInfo->Race);
        SendCharCreate(CHAR_CREATE_FAILED);
        return;
    }

    if (raceExpansionRequirement->Expansion > GetAccountExpansion())
    {
        TC_LOG_ERROR("entities.player.cheat", "Expansion {} account:[{}] tried to Create character with expansion {} race ({})",
            GetAccountExpansion(), GetAccountId(), raceExpansionRequirement->Expansion, charCreate.CreateInfo->Race);
        SendCharCreate(CHAR_CREATE_EXPANSION);
        return;
    }

    //if (raceExpansionRequirement->AchievementId && !)
    //{
    //    TC_LOG_ERROR("entities.player.cheat", "Expansion {} account:[{}] tried to Create character without achievement {} race ({})",
    //        GetAccountExpansion(), GetAccountId(), raceExpansionRequirement->AchievementId, charCreate.CreateInfo->Race);
    //    SendCharCreate(CHAR_CREATE_ALLIED_RACE_ACHIEVEMENT);
    //    return;
    //}

    // prevent character creating Expansion class without Expansion account
    if (ClassAvailability const* raceClassExpansionRequirement = sObjectMgr->GetClassExpansionRequirement(charCreate.CreateInfo->Race, charCreate.CreateInfo->Class))
    {
        if (raceClassExpansionRequirement->ActiveExpansionLevel > GetExpansion() || raceClassExpansionRequirement->AccountExpansionLevel > GetAccountExpansion())
        {
            TC_LOG_ERROR("entities.player.cheat", "Account:[{}] tried to create character with race/class {}/{} without required expansion (had {}/{}, required {}/{})",
                GetAccountId(), uint32(charCreate.CreateInfo->Race), uint32(charCreate.CreateInfo->Class), GetExpansion(), GetAccountExpansion(),
                raceClassExpansionRequirement->ActiveExpansionLevel, raceClassExpansionRequirement->AccountExpansionLevel);
            SendCharCreate(CHAR_CREATE_EXPANSION_CLASS);
            return;
        }
    }
    else if (ClassAvailability const* classExpansionRequirement = sObjectMgr->GetClassExpansionRequirementFallback(charCreate.CreateInfo->Class))
    {
        if (classExpansionRequirement->MinActiveExpansionLevel > GetExpansion() || classExpansionRequirement->AccountExpansionLevel > GetAccountExpansion())
        {
            TC_LOG_ERROR("entities.player.cheat", "Account:[{}] tried to create character with race/class {}/{} without required expansion (had {}/{}, required {}/{})",
                GetAccountId(), uint32(charCreate.CreateInfo->Race), uint32(charCreate.CreateInfo->Class), GetExpansion(), GetAccountExpansion(),
                classExpansionRequirement->ActiveExpansionLevel, classExpansionRequirement->AccountExpansionLevel);
            SendCharCreate(CHAR_CREATE_EXPANSION_CLASS);
            return;
        }
    }
    else
    {
        TC_LOG_ERROR("entities.player.cheat", "Expansion {} account:[{}] tried to Create character for race/class combination that is missing requirements in db ({}/{})",
            GetAccountExpansion(), GetAccountId(), uint32(charCreate.CreateInfo->Race), uint32(charCreate.CreateInfo->Class));
        SendCharCreate(CHAR_CREATE_EXPANSION_CLASS);
        return;
    }

    if (!HasPermission(rbac::RBAC_PERM_SKIP_CHECK_CHARACTER_CREATION_RACEMASK))
    {
        if (raceEntry->GetFlags().HasFlag(ChrRacesFlag::NPCOnly))
        {
            TC_LOG_ERROR("network", "Race ({}) was not playable but requested while creating new char for account (ID: {}): wrong DBC files or cheater?", charCreate.CreateInfo->Race, GetAccountId());
            SendCharCreate(CHAR_CREATE_DISABLED);
            return;
        }

        Trinity::RaceMask<uint64> raceMaskDisabled{ sWorld->GetUInt64Config(CONFIG_CHARACTER_CREATING_DISABLED_RACEMASK) };
        if (raceMaskDisabled.HasRace(charCreate.CreateInfo->Race))
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
        TC_LOG_ERROR("entities.player.cheat", "Account:[{}] but tried to Create character with empty [name] ", GetAccountId());
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

    if (charCreate.CreateInfo->TimerunningSeasonID)
    {
        SendCharCreate(CHAR_CREATE_TIMERUNNING);
        return;
    }

    std::shared_ptr<WorldPackets::Character::CharacterCreateInfo> createInfo = charCreate.CreateInfo;
    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHECK_NAME);
    stmt->setString(0, charCreate.CreateInfo->Name);

    _queryProcessor.AddCallback(CharacterDatabase.AsyncQuery(stmt)
        .WithChainingPreparedCallback([this](QueryCallback& queryCallback, PreparedQueryResult result)
    {
        if (result)
        {
            SendCharCreate(CHAR_CREATE_NAME_IN_USE);
            return;
        }

        LoginDatabasePreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_SEL_SUM_REALM_CHARACTERS);
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

        CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_SUM_CHARS);
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
            uint32 evokerReqLevel = sWorld->getIntConfig(CONFIG_CHARACTER_CREATING_MIN_LEVEL_FOR_EVOKER);
            bool hasEvokerReqLevel = (evokerReqLevel == 0);
            bool allowTwoSideAccounts = !sWorld->IsPvPRealm() || HasPermission(rbac::RBAC_PERM_TWO_SIDE_CHARACTER_CREATION);
            uint32 skipCinematics = sWorld->getIntConfig(CONFIG_SKIP_CINEMATICS);
            bool checkClassLevelReqs = (createInfo->Class == CLASS_DEMON_HUNTER || createInfo->Class == CLASS_EVOKER)
                                        && !HasPermission(rbac::RBAC_PERM_SKIP_CHECK_CHARACTER_CREATION_DEMON_HUNTER);
            int32 evokerLimit = sWorld->getIntConfig(CONFIG_CHARACTER_CREATING_EVOKERS_PER_REALM);
            bool hasEvokerLimit = evokerLimit != 0;

            if (result)
            {
                uint32 team = Player::TeamForRace(createInfo->Race);

                Field* field = result->Fetch();
                uint8 accRace = field[1].GetUInt8();
                uint8 accClass = field[2].GetUInt8();

                if (checkClassLevelReqs)
                {
                    if (!hasDemonHunterReqLevel)
                    {
                        uint8 accLevel = field[0].GetUInt8();
                        if (accLevel >= demonHunterReqLevel)
                            hasDemonHunterReqLevel = true;
                    }
                    if (!hasEvokerReqLevel)
                    {
                        uint8 accLevel = field[0].GetUInt8();
                        if (accLevel >= evokerReqLevel)
                            hasEvokerReqLevel = true;
                    }
                }

                if (accClass == CLASS_EVOKER)
                    --evokerLimit;

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
                while ((skipCinematics == 1 && !haveSameRace) || createInfo->Class == CLASS_DEMON_HUNTER || createInfo->Class == CLASS_EVOKER)
                {
                    if (!result->NextRow())
                        break;

                    field = result->Fetch();
                    accRace = field[1].GetUInt8();
                    accClass = field[2].GetUInt8();

                    if (!haveSameRace)
                        haveSameRace = createInfo->Race == accRace;

                    if (checkClassLevelReqs)
                    {
                        if (!hasDemonHunterReqLevel)
                        {
                            uint8 accLevel = field[0].GetUInt8();
                            if (accLevel >= demonHunterReqLevel)
                                hasDemonHunterReqLevel = true;
                        }
                        if (!hasEvokerReqLevel)
                        {
                            uint8 accLevel = field[0].GetUInt8();
                            if (accLevel >= evokerReqLevel)
                                hasEvokerReqLevel = true;
                        }
                    }

                    if (accClass == CLASS_EVOKER)
                        --evokerLimit;
                }
            }

            if (checkClassLevelReqs)
            {
                if (!hasDemonHunterReqLevel)
                {
                    SendCharCreate(CHAR_CREATE_NEW_PLAYER);
                    return;
                }
                if (!hasEvokerReqLevel)
                {
                    SendCharCreate(CHAR_CREATE_DRACTHYR_LEVEL_REQUIREMENT);
                    return;
                }
            }

            if (createInfo->Class == CLASS_EVOKER && hasEvokerLimit && evokerLimit < 1)
            {
                SendCharCreate(CHAR_CREATE_DRACTHYR_DUPLICATE);
                return;
            }

            // Check name uniqueness in the same step as saving to database
            if (sCharacterCache->GetCharacterCacheByName(createInfo->Name))
            {
                SendCharCreate(CHAR_CREATE_NAME_IN_USE);
                return;
            }

            std::shared_ptr<Player> newChar(new Player(this), [](Player* ptr)
            {
                ptr->CleanupsBeforeDelete();
                delete ptr;
            });
            newChar->GetMotionMaster()->Initialize();
            if (!newChar->Create(sObjectMgr->GetGenerator<HighGuid::Player>().Generate(), createInfo.get()))
            {
                // Player not create (race/class/etc problem?)
                SendCharCreate(CHAR_CREATE_ERROR);
                return;
            }

            if ((haveSameRace && skipCinematics == 1) || skipCinematics == 2)
                newChar->setCinematic(1);                         // not show intro

            newChar->SetAtLoginFlag(AT_LOGIN_FIRST);              // First login

            CharacterDatabaseTransaction characterTransaction = CharacterDatabase.BeginTransaction();
            LoginDatabaseTransaction trans = LoginDatabase.BeginTransaction();

                                                                  // Player created, save it now
            newChar->SaveToDB(trans, characterTransaction, true);
            createInfo->CharCount += 1;

            LoginDatabasePreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_REP_REALM_CHARACTERS);
            stmt->setUInt32(0, createInfo->CharCount);
            stmt->setUInt32(1, GetAccountId());
            stmt->setUInt32(2, realm.Id.Realm);
            trans->Append(stmt);

            LoginDatabase.CommitTransaction(trans);

            AddTransactionCallback(CharacterDatabase.AsyncCommitTransaction(characterTransaction)).AfterComplete([this, newChar = std::move(newChar)](bool success)
            {
                if (success)
                {
                    TC_LOG_INFO("entities.player.character", "Account: {} (IP: {}) Create Character: {} {}", GetAccountId(), GetRemoteAddress(), newChar->GetName(), newChar->GetGUID().ToString());
                    sScriptMgr->OnPlayerCreate(newChar.get());
                    sCharacterCache->AddCharacterCacheEntry(newChar->GetGUID(), GetAccountId(), newChar->GetName(), newChar->GetNativeGender(), newChar->GetRace(), newChar->GetClass(), newChar->GetLevel(), false);

                    SendCharCreate(CHAR_CREATE_SUCCESS, newChar->GetGUID());
                }
                else
                    SendCharCreate(CHAR_CREATE_ERROR);
            });
        };

        if (allowTwoSideAccounts && !skipCinematics && createInfo->Class != CLASS_DEMON_HUNTER)
        {
            finalizeCharacterCreation(PreparedQueryResult(nullptr));
            return;
        }

        CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHAR_CREATE_INFO);
        stmt->setUInt32(0, GetAccountId());
        stmt->setUInt32(1, (skipCinematics == 1 || createInfo->Class == CLASS_DEMON_HUNTER || createInfo->Class == CLASS_EVOKER) ? 1200 : 1); // 200 (max chars per realm) + 1000 (max deleted chars per realm)
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

    CharacterCacheEntry const* characterInfo = sCharacterCache->GetCharacterCacheByGuid(charDelete.Guid);
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

    TC_LOG_INFO("entities.player.character", "Account: {}, IP: {} deleted character: {}, {}, Level: {}", accountId, GetRemoteAddress(), name, charDelete.Guid.ToString(), level);

    // To prevent hook failure, place hook before removing reference from DB
    sScriptMgr->OnPlayerDelete(charDelete.Guid, initAccountId); // To prevent race conditioning, but as it also makes sense, we hand the accountId over for successful delete.
    // Shouldn't interfere with character deletion though

    if (sLog->ShouldLog("entities.player.dump", LOG_LEVEL_INFO)) // optimize GetPlayerDump call
    {
        std::string dump;
        if (PlayerDumpWriter().GetDump(charDelete.Guid.GetCounter(), dump))
            sLog->OutCharDump(dump.c_str(), accountId, charDelete.Guid.GetCounter(), name.c_str());
    }

    sCalendarMgr->RemoveAllPlayerEventsAndInvites(charDelete.Guid);
    Player::DeleteFromDB(charDelete.Guid, accountId);

    SendCharDelete(CHAR_DELETE_SUCCESS);
}

void WorldSession::HandlePlayerLoginOpcode(WorldPackets::Character::PlayerLogin& playerLogin)
{
    if (PlayerLoading() || GetPlayer() != nullptr)
    {
        TC_LOG_ERROR("network", "Player tries to login again, AccountId = {}", GetAccountId());
        KickPlayer("WorldSession::HandlePlayerLoginOpcode Another client logging in");
        return;
    }

    m_playerLoading = playerLogin.Guid;

    TC_LOG_DEBUG("network", "Character {} logging in", playerLogin.Guid.ToString());

    if (!IsLegitCharacterForAccount(playerLogin.Guid))
    {
        TC_LOG_ERROR("network", "Account ({}) can't login with that character ({}).", GetAccountId(), playerLogin.Guid.ToString());
        KickPlayer("WorldSession::HandlePlayerLoginOpcode Trying to login with a character of another account");
        return;
    }

    SendConnectToInstance(WorldPackets::Auth::ConnectToSerial::WorldAttempt1);
}

void WorldSession::HandleContinuePlayerLogin()
{
    if (!PlayerLoading() || GetPlayer())
    {
        KickPlayer("WorldSession::HandleContinuePlayerLogin incorrect player state when logging in");
        return;
    }

    std::shared_ptr<LoginQueryHolder> holder = std::make_shared<LoginQueryHolder>(GetAccountId(), m_playerLoading);
    if (!holder->Initialize())
    {
        m_playerLoading.Clear();
        return;
    }

    SendPacket(WorldPackets::Auth::ResumeComms(CONNECTION_TYPE_INSTANCE).Write());

    AddQueryHolderCallback(CharacterDatabase.DelayQueryHolder(holder)).AfterComplete([this](SQLQueryHolderBase const& holder)
    {
        HandlePlayerLogin(static_cast<LoginQueryHolder const&>(holder));
    });
}

void WorldSession::AbortLogin(WorldPackets::Character::LoginFailureReason reason)
{
    if (!PlayerLoading() || GetPlayer())
    {
        KickPlayer("WorldSession::AbortLogin incorrect player state when logging in");
        return;
    }

    m_playerLoading.Clear();
    SendPacket(WorldPackets::Character::CharacterLoginFailed(reason).Write());
}

void WorldSession::HandleLoadScreenOpcode(WorldPackets::Character::LoadingScreenNotify& /*loadingScreenNotify*/)
{
    // TODO: Do something with this packet
}

void WorldSession::HandlePlayerLogin(LoginQueryHolder const& holder)
{
    ObjectGuid playerGuid = holder.GetGuid();

    Player* pCurrChar = new Player(this);
     // for send server info and strings (config)
    ChatHandler chH = ChatHandler(pCurrChar->GetSession());

    // "GetAccountId() == db stored account id" checked in LoadFromDB (prevent login not own character using cheating tools)
    if (!pCurrChar->LoadFromDB(playerGuid, holder))
    {
        SetPlayer(nullptr);
        KickPlayer("WorldSession::HandlePlayerLogin Player::LoadFromDB failed"); // disconnect client, player no set to session and it will not deleted or saved at kick
        delete pCurrChar;                                   // delete it manually
        m_playerLoading.Clear();
        return;
    }

    pCurrChar->SetVirtualPlayerRealm(GetVirtualRealmAddress());

    SendAccountDataTimes(ObjectGuid::Empty, GLOBAL_CACHE_MASK);
    SendTutorialsData();

    pCurrChar->GetMotionMaster()->Initialize();
    pCurrChar->SendDungeonDifficulty();

    WorldPackets::Character::LoginVerifyWorld loginVerifyWorld;
    loginVerifyWorld.MapID = pCurrChar->GetMapId();
    loginVerifyWorld.Pos = pCurrChar->GetPosition();
    SendPacket(loginVerifyWorld.Write());

    // load player specific part before send times
    LoadAccountData(holder.GetPreparedResult(PLAYER_LOGIN_QUERY_LOAD_ACCOUNT_DATA), PER_CHARACTER_CACHE_MASK);
    SendAccountDataTimes(playerGuid, ALL_ACCOUNT_DATA_CACHE_MASK);

    SendFeatureSystemStatus();

    // Send MOTD
    {
        for (std::string const& motdLine : sWorld->GetMotd())
            sWorld->SendServerMessage(SERVER_MSG_STRING, motdLine, pCurrChar);
    }

    SendSetTimeZoneInformation();

    // Send PVPSeason
    {
        WorldPackets::Battleground::SeasonInfo seasonInfo;
        seasonInfo.PreviousArenaSeason = sWorld->getIntConfig(CONFIG_ARENA_SEASON_ID) - sWorld->getBoolConfig(CONFIG_ARENA_SEASON_IN_PROGRESS);

        if (sWorld->getBoolConfig(CONFIG_ARENA_SEASON_IN_PROGRESS))
            seasonInfo.CurrentArenaSeason = sWorld->getIntConfig(CONFIG_ARENA_SEASON_ID);

        SendPacket(seasonInfo.Write());
    }

    // send server info
    {
        if (sWorld->getIntConfig(CONFIG_ENABLE_SINFO_LOGIN) == 1)
            chH.PSendSysMessage(GitRevision::GetFullVersion());
    }

    //QueryResult* result = CharacterDatabase.PQuery("SELECT guildid, `rank` FROM guild_member WHERE guid = '{}'", pCurrChar->GetGUIDLow());
    if (PreparedQueryResult resultGuild = holder.GetPreparedResult(PLAYER_LOGIN_QUERY_LOAD_GUILD))
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

    pCurrChar->GetSession()->GetBattlePetMgr()->SendJournalLockStatus();

    pCurrChar->SendInitialPacketsBeforeAddToMap();

    //Show cinematic at the first time that player login
    if (!pCurrChar->getCinematic())
    {
        pCurrChar->setCinematic(1);

        if (PlayerInfo const* playerInfo = sObjectMgr->GetPlayerInfo(pCurrChar->GetRace(), pCurrChar->GetClass()))
        {
            switch (pCurrChar->GetCreateMode())
            {
                case PlayerCreateMode::Normal:
                    if (playerInfo->introMovieId)
                        pCurrChar->SendMovieStart(*playerInfo->introMovieId);
                    else if (playerInfo->introSceneId)
                        pCurrChar->GetSceneMgr().PlayScene(*playerInfo->introSceneId);
                    else if (sChrClassesStore.AssertEntry(pCurrChar->GetClass())->CinematicSequenceID)
                        pCurrChar->SendCinematicStart(sChrClassesStore.AssertEntry(pCurrChar->GetClass())->CinematicSequenceID);
                    else if (sChrRacesStore.AssertEntry(pCurrChar->GetRace())->CinematicSequenceID)
                        pCurrChar->SendCinematicStart(sChrRacesStore.AssertEntry(pCurrChar->GetRace())->CinematicSequenceID);
                    break;
                case PlayerCreateMode::NPE:
                    if (playerInfo->introSceneIdNPE)
                        pCurrChar->GetSceneMgr().PlayScene(*playerInfo->introSceneIdNPE);
                    break;
                default:
                    break;
            }
        }

        // send new char string if not empty
        if (!sWorld->GetNewCharString().empty())
            chH.PSendSysMessage("%s", sWorld->GetNewCharString().c_str());
    }

    if (!pCurrChar->GetMap()->AddPlayerToMap(pCurrChar))
    {
        AreaTriggerStruct const* at = sObjectMgr->GetGoBackTrigger(pCurrChar->GetMapId());
        if (at)
            pCurrChar->TeleportTo(at->target_mapId, at->target_X, at->target_Y, at->target_Z, pCurrChar->GetOrientation());
        else
            pCurrChar->TeleportTo(pCurrChar->m_homebind);
    }

    ObjectAccessor::AddObject(pCurrChar);
    //TC_LOG_DEBUG("Player {} added to Map.", pCurrChar->GetName());

    if (pCurrChar->GetGuildId())
    {
        if (Guild* guild = sGuildMgr->GetGuildById(pCurrChar->GetGuildId()))
            guild->SendLoginInfo(this);
        else
        {
            // remove wrong guild data
            TC_LOG_ERROR("misc", "Player {} ({}) marked as member of not existing guild (id: {}), removing guild membership for player.", pCurrChar->GetName(), pCurrChar->GetGUID().ToString(), pCurrChar->GetGuildId());
            pCurrChar->SetInGuild(UI64LIT(0));
        }
    }

    pCurrChar->RemoveAurasWithInterruptFlags(SpellAuraInterruptFlags::Login);

    pCurrChar->SendInitialPacketsAfterAddToMap();

    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_CHAR_ONLINE);
    stmt->setUInt64(0, pCurrChar->GetGUID().GetCounter());
    CharacterDatabase.Execute(stmt);

    LoginDatabasePreparedStatement* loginStmt = LoginDatabase.GetPreparedStatement(LOGIN_UPD_ACCOUNT_ONLINE);
    loginStmt->setUInt32(0, GetAccountId());
    LoginDatabase.Execute(loginStmt);

    pCurrChar->SetInGameTime(GameTime::GetGameTimeMS());

    // announce group about member online (must be after add to player list to receive announce to self)
    if (Group* group = pCurrChar->GetGroup())
    {
        //pCurrChar->groupInfo.group->SendInit(this); // useless
        group->SendUpdate();
        if (group->GetLeaderGUID() == pCurrChar->GetGUID())
            group->StopLeaderOfflineTimer();
    }

    // friend status
    sSocialMgr->SendFriendStatus(pCurrChar, FRIEND_ONLINE, pCurrChar->GetGUID(), true);

    // Place character in world (and load zone) before some object loading
    pCurrChar->LoadCorpse(holder.GetPreparedResult(PLAYER_LOGIN_QUERY_LOAD_CORPSE_LOCATION));

    // setting Ghost+speed if dead
    if (pCurrChar->m_deathState == DEAD)
    {
        // not blizz like, we must correctly save and load player instead...
        if (pCurrChar->GetRace() == RACE_NIGHTELF && !pCurrChar->HasAura(20584))
            pCurrChar->CastSpell(pCurrChar, 20584, true);// auras SPELL_AURA_INCREASE_SPEED(+speed in wisp form), SPELL_AURA_INCREASE_SWIM_SPEED(+swim speed in wisp form), SPELL_AURA_TRANSFORM (to wisp form)

        if (!pCurrChar->HasAura(8326))
            pCurrChar->CastSpell(pCurrChar, 8326, true); // auras SPELL_AURA_GHOST, SPELL_AURA_INCREASE_SPEED(why?), SPELL_AURA_INCREASE_SWIM_SPEED(why?)

        pCurrChar->SetWaterWalking(true);
    }

    pCurrChar->ContinueTaxiFlight();

    // reset for all pets before pet loading
    if (pCurrChar->HasAtLoginFlag(AT_LOGIN_RESET_PET_TALENTS))
    {
        // Delete all of the player's pet spells
        CharacterDatabasePreparedStatement* stmtSpells = CharacterDatabase.GetPreparedStatement(CHAR_DEL_ALL_PET_SPELLS_BY_OWNER);
        stmtSpells->setUInt64(0, pCurrChar->GetGUID().GetCounter());
        CharacterDatabase.Execute(stmtSpells);

        // Then reset all of the player's pet specualizations
        CharacterDatabasePreparedStatement* stmtSpec = CharacterDatabase.GetPreparedStatement(CHAR_UPD_PET_SPECS_BY_OWNER);
        stmtSpec->setUInt64(0, pCurrChar->GetGUID().GetCounter());
        CharacterDatabase.Execute(stmtSpec);
    }

    // Load pet if any (if player not alive and in taxi flight or another then pet will remember as temporary unsummoned)
    pCurrChar->ResummonPetTemporaryUnSummonedIfAny();

    // Set FFA PvP for non GM in non-rest mode
    if (sWorld->IsFFAPvPRealm() && !pCurrChar->IsGameMaster() && !pCurrChar->HasPlayerFlag(PLAYER_FLAGS_RESTING))
        pCurrChar->SetPvpFlag(UNIT_BYTE2_FLAG_FFA_PVP);

    if (pCurrChar->HasPlayerFlag(PLAYER_FLAGS_CONTESTED_PVP))
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

        PlayerInfo const* info = sObjectMgr->GetPlayerInfo(pCurrChar->GetRace(), pCurrChar->GetClass());
        for (uint32 spellId : info->castSpells[AsUnderlyingType(pCurrChar->GetCreateMode())])
            pCurrChar->CastSpell(pCurrChar, spellId, true);

        // start with every map explored
        if (sWorld->getBoolConfig(CONFIG_START_ALL_EXPLORED))
        {
            for (uint32 i = 0; i < PLAYER_EXPLORED_ZONES_SIZE; ++i)
                pCurrChar->AddExploredZones(i, UI64LIT(0xFFFFFFFFFFFFFFFF));
        }

        // Max relevant reputations if "StartAllReputation" is enabled
        if (sWorld->getBoolConfig(CONFIG_START_ALL_REP))
        {
            ReputationMgr& repMgr = pCurrChar->GetReputationMgr();
            repMgr.SetOneFactionReputation(sFactionStore.LookupEntry( 942), 42999, false); // Cenarion Expedition
            repMgr.SetOneFactionReputation(sFactionStore.LookupEntry( 935), 42999, false); // The Sha'tar
            repMgr.SetOneFactionReputation(sFactionStore.LookupEntry( 936), 42999, false); // Shattrath City
            repMgr.SetOneFactionReputation(sFactionStore.LookupEntry(1011), 42999, false); // Lower City
            repMgr.SetOneFactionReputation(sFactionStore.LookupEntry( 970), 42999, false); // Sporeggar
            repMgr.SetOneFactionReputation(sFactionStore.LookupEntry( 967), 42999, false); // The Violet Eye
            repMgr.SetOneFactionReputation(sFactionStore.LookupEntry( 989), 42999, false); // Keepers of Time
            repMgr.SetOneFactionReputation(sFactionStore.LookupEntry( 932), 42999, false); // The Aldor
            repMgr.SetOneFactionReputation(sFactionStore.LookupEntry( 934), 42999, false); // The Scryers
            repMgr.SetOneFactionReputation(sFactionStore.LookupEntry(1038), 42999, false); // Ogri'la
            repMgr.SetOneFactionReputation(sFactionStore.LookupEntry(1077), 42999, false); // Shattered Sun Offensive
            repMgr.SetOneFactionReputation(sFactionStore.LookupEntry(1106), 42999, false); // Argent Crusade
            repMgr.SetOneFactionReputation(sFactionStore.LookupEntry(1104), 42999, false); // Frenzyheart Tribe
            repMgr.SetOneFactionReputation(sFactionStore.LookupEntry(1090), 42999, false); // Kirin Tor
            repMgr.SetOneFactionReputation(sFactionStore.LookupEntry(1098), 42999, false); // Knights of the Ebon Blade
            repMgr.SetOneFactionReputation(sFactionStore.LookupEntry(1156), 42999, false); // The Ashen Verdict
            repMgr.SetOneFactionReputation(sFactionStore.LookupEntry(1073), 42999, false); // The Kalu'ak
            repMgr.SetOneFactionReputation(sFactionStore.LookupEntry(1105), 42999, false); // The Oracles
            repMgr.SetOneFactionReputation(sFactionStore.LookupEntry(1119), 42999, false); // The Sons of Hodir
            repMgr.SetOneFactionReputation(sFactionStore.LookupEntry(1091), 42999, false); // The Wyrmrest Accord

            // Factions depending on team, like cities and some more stuff
            switch (pCurrChar->GetTeam())
            {
                case ALLIANCE:
                    repMgr.SetOneFactionReputation(sFactionStore.LookupEntry(  72), 42999, false); // Stormwind
                    repMgr.SetOneFactionReputation(sFactionStore.LookupEntry(  47), 42999, false); // Ironforge
                    repMgr.SetOneFactionReputation(sFactionStore.LookupEntry(  69), 42999, false); // Darnassus
                    repMgr.SetOneFactionReputation(sFactionStore.LookupEntry( 930), 42999, false); // Exodar
                    repMgr.SetOneFactionReputation(sFactionStore.LookupEntry( 730), 42999, false); // Stormpike Guard
                    repMgr.SetOneFactionReputation(sFactionStore.LookupEntry( 978), 42999, false); // Kurenai
                    repMgr.SetOneFactionReputation(sFactionStore.LookupEntry(  54), 42999, false); // Gnomeregan Exiles
                    repMgr.SetOneFactionReputation(sFactionStore.LookupEntry( 946), 42999, false); // Honor Hold
                    repMgr.SetOneFactionReputation(sFactionStore.LookupEntry(1037), 42999, false); // Alliance Vanguard
                    repMgr.SetOneFactionReputation(sFactionStore.LookupEntry(1068), 42999, false); // Explorers' League
                    repMgr.SetOneFactionReputation(sFactionStore.LookupEntry(1126), 42999, false); // The Frostborn
                    repMgr.SetOneFactionReputation(sFactionStore.LookupEntry(1094), 42999, false); // The Silver Covenant
                    repMgr.SetOneFactionReputation(sFactionStore.LookupEntry(1050), 42999, false); // Valiance Expedition
                    break;
                case HORDE:
                    repMgr.SetOneFactionReputation(sFactionStore.LookupEntry(  76), 42999, false); // Orgrimmar
                    repMgr.SetOneFactionReputation(sFactionStore.LookupEntry(  68), 42999, false); // Undercity
                    repMgr.SetOneFactionReputation(sFactionStore.LookupEntry(  81), 42999, false); // Thunder Bluff
                    repMgr.SetOneFactionReputation(sFactionStore.LookupEntry( 911), 42999, false); // Silvermoon City
                    repMgr.SetOneFactionReputation(sFactionStore.LookupEntry( 729), 42999, false); // Frostwolf Clan
                    repMgr.SetOneFactionReputation(sFactionStore.LookupEntry( 941), 42999, false); // The Mag'har
                    repMgr.SetOneFactionReputation(sFactionStore.LookupEntry( 530), 42999, false); // Darkspear Trolls
                    repMgr.SetOneFactionReputation(sFactionStore.LookupEntry( 947), 42999, false); // Thrallmar
                    repMgr.SetOneFactionReputation(sFactionStore.LookupEntry(1052), 42999, false); // Horde Expedition
                    repMgr.SetOneFactionReputation(sFactionStore.LookupEntry(1067), 42999, false); // The Hand of Vengeance
                    repMgr.SetOneFactionReputation(sFactionStore.LookupEntry(1124), 42999, false); // The Sunreavers
                    repMgr.SetOneFactionReputation(sFactionStore.LookupEntry(1064), 42999, false); // The Taunka
                    repMgr.SetOneFactionReputation(sFactionStore.LookupEntry(1085), 42999, false); // Warsong Offensive
                    break;
                default:
                    break;
            }
            repMgr.SendState(nullptr);
        }
    }

    // show time before shutdown if shutdown planned.
    if (sWorld->IsShuttingDown())
        sWorld->ShutdownMsg(true, pCurrChar);

    if (sWorld->getBoolConfig(CONFIG_ALL_TAXI_PATHS))
        pCurrChar->SetTaxiCheater(true);

    if (pCurrChar->IsGameMaster())
        SendNotification(LANG_GM_ON);

    TC_LOG_INFO("entities.player.character", "Account: {} (IP: {}) Login Character: [{}] {} Level: {}, XP: {}/{} ({} left)",
        GetAccountId(), GetRemoteAddress(), pCurrChar->GetName(), pCurrChar->GetGUID().ToString(), pCurrChar->GetLevel(),
        _player->GetXP(), _player->GetXPForNextLevel(), std::max(0, (int32)_player->GetXPForNextLevel() - (int32)_player->GetXP()));

    if (!pCurrChar->IsStandState() && !pCurrChar->HasUnitState(UNIT_STATE_STUNNED))
        pCurrChar->SetStandState(UNIT_STAND_STATE_STAND);

    pCurrChar->UpdateAverageItemLevelTotal();
    pCurrChar->UpdateAverageItemLevelEquipped();

    m_playerLoading.Clear();

    _player->UpdateMountCapability();

    // Handle Login-Achievements (should be handled after loading)
    _player->UpdateCriteria(CriteriaType::Login, 1);

    sScriptMgr->OnPlayerLogin(pCurrChar, firstLogin);

    TC_METRIC_EVENT("player_events", "Login", pCurrChar->GetName());
}

void WorldSession::SendFeatureSystemStatus()
{
    WorldPackets::System::FeatureSystemStatus features;

    /// START OF DUMMY VALUES
    features.ComplaintStatus = COMPLAINT_ENABLED_WITH_AUTO_IGNORE;
    features.CfgRealmID = 2;
    features.CfgRealmRecID = 0;
    features.TokenPollTimeSeconds = 300;
    features.VoiceEnabled = false;
    features.BrowserEnabled = false; // Has to be false, otherwise client will crash if "Customer Support" is opened

    // Enable guilds only.
    // This is required to restore old guild channel behavior for GMs.
    // The new club streams do not support sending messages through the guild channel when you are not in a guild.
    features.ClubsEnabled = true;
    features.ClubsBattleNetClubTypeAllowed = false;
    features.ClubsCharacterClubTypeAllowed = false;
    features.ClubsPresenceUpdateEnabled = true;
    features.HiddenUIClubsPresenceUpdateTimer = 60000;

    features.EuropaTicketSystemStatus.emplace();
    features.EuropaTicketSystemStatus->ThrottleState.MaxTries = 10;
    features.EuropaTicketSystemStatus->ThrottleState.PerMilliseconds = 60000;
    features.EuropaTicketSystemStatus->ThrottleState.TryCount = 1;
    features.EuropaTicketSystemStatus->ThrottleState.LastResetTimeBeforeNow = 111111;
    features.TutorialsEnabled = true;
    features.NPETutorialsEnabled = true;
    /// END OF DUMMY VALUES

    features.EuropaTicketSystemStatus->TicketsEnabled = sWorld->getBoolConfig(CONFIG_SUPPORT_TICKETS_ENABLED);
    features.EuropaTicketSystemStatus->BugsEnabled = sWorld->getBoolConfig(CONFIG_SUPPORT_BUGS_ENABLED);
    features.EuropaTicketSystemStatus->ComplaintsEnabled = sWorld->getBoolConfig(CONFIG_SUPPORT_COMPLAINTS_ENABLED);
    features.EuropaTicketSystemStatus->SuggestionsEnabled = sWorld->getBoolConfig(CONFIG_SUPPORT_SUGGESTIONS_ENABLED);

    features.CharUndeleteEnabled = sWorld->getBoolConfig(CONFIG_FEATURE_SYSTEM_CHARACTER_UNDELETE_ENABLED);
    features.BpayStoreEnabled = sWorld->getBoolConfig(CONFIG_FEATURE_SYSTEM_BPAY_STORE_ENABLED);
    features.IsMuted = !CanSpeak();

    features.TextToSpeechFeatureEnabled = false;

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

void WorldSession::HandleTutorialFlag(WorldPackets::Misc::TutorialSetFlag& packet)
{
    switch (packet.Action)
    {
        case TUTORIAL_ACTION_UPDATE:
        {
            uint8 index = uint8(packet.TutorialBit >> 5);
            if (index >= MAX_ACCOUNT_TUTORIAL_VALUES)
            {
                TC_LOG_ERROR("network", "CMSG_TUTORIAL_FLAG received bad TutorialBit {}.", packet.TutorialBit);
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
            TC_LOG_ERROR("network", "CMSG_TUTORIAL_FLAG received unknown TutorialAction {}.", packet.Action);
            return;
    }
}

void WorldSession::HandleSetWatchedFactionOpcode(WorldPackets::Character::SetWatchedFaction& packet)
{
    GetPlayer()->SetWatchedFactionIndex(packet.FactionIndex);
}

void WorldSession::HandleSetFactionInactiveOpcode(WorldPackets::Character::SetFactionInactive& packet)
{
    _player->GetReputationMgr().SetInactive(packet.Index, packet.State);
}

void WorldSession::HandleRequestForcedReactionsOpcode(WorldPackets::Reputation::RequestForcedReactions& /*requestForcedReactions*/)
{
    _player->GetReputationMgr().SendForceReactions();
}

void WorldSession::HandleCheckCharacterNameAvailability(WorldPackets::Character::CheckCharacterNameAvailability& checkCharacterNameAvailability)
{
    // prevent character rename to invalid name
    if (!normalizePlayerName(checkCharacterNameAvailability.Name))
    {
        SendPacket(WorldPackets::Character::CheckCharacterNameAvailabilityResult(checkCharacterNameAvailability.SequenceIndex, CHAR_NAME_NO_NAME).Write());
        return;
    }

    ResponseCodes res = ObjectMgr::CheckPlayerName(checkCharacterNameAvailability.Name, GetSessionDbcLocale(), true);
    if (res != CHAR_NAME_SUCCESS)
    {
        SendPacket(WorldPackets::Character::CheckCharacterNameAvailabilityResult(checkCharacterNameAvailability.SequenceIndex, res).Write());
        return;
    }

    // check name limitations
    if (!HasPermission(rbac::RBAC_PERM_SKIP_CHECK_CHARACTER_CREATION_RESERVEDNAME) && sObjectMgr->IsReservedName(checkCharacterNameAvailability.Name))
    {
        SendPacket(WorldPackets::Character::CheckCharacterNameAvailabilityResult(checkCharacterNameAvailability.SequenceIndex, CHAR_NAME_RESERVED).Write());
        return;
    }

    // Ensure that there is no character with the desired new name
    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHECK_NAME);
    stmt->setString(0, checkCharacterNameAvailability.Name);

    _queryProcessor.AddCallback(CharacterDatabase.AsyncQuery(stmt)
        .WithPreparedCallback([this, sequenceIndex = checkCharacterNameAvailability.SequenceIndex](PreparedQueryResult result)
    {
        SendPacket(WorldPackets::Character::CheckCharacterNameAvailabilityResult(sequenceIndex, result ? CHAR_CREATE_NAME_IN_USE : RESPONSE_SUCCESS).Write());
    }));
}

void WorldSession::HandleCharRenameOpcode(WorldPackets::Character::CharacterRenameRequest& request)
{
    if (!IsLegitCharacterForAccount(request.RenameInfo->Guid))
    {
        TC_LOG_ERROR("network", "Account {}, IP: {} tried to rename character {}, but it does not belong to their account!",
            GetAccountId(), GetRemoteAddress(), request.RenameInfo->Guid.ToString());
        KickPlayer("WorldSession::HandleCharRenameOpcode rename character from a different account");
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
    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_FREE_NAME);
    stmt->setUInt64(0, request.RenameInfo->Guid.GetCounter());
    stmt->setString(1, request.RenameInfo->NewName);

    _queryProcessor.AddCallback(CharacterDatabase.AsyncQuery(stmt)
        .WithPreparedCallback([this, renameInfo = std::move(request.RenameInfo)](PreparedQueryResult result) mutable
        {
            HandleCharRenameCallBack(std::move(renameInfo), std::move(result));
        }));
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

    CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();
    ObjectGuid::LowType lowGuid = renameInfo->Guid.GetCounter();

    // Update name and at_login flag in the db
    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_CHAR_NAME_AT_LOGIN);
    stmt->setString(0, renameInfo->NewName);
    stmt->setUInt16(1, atLoginFlags);
    stmt->setUInt64(2, lowGuid);

    trans->Append(stmt);

    // Removed declined name from db
    stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHAR_DECLINED_NAME);
    stmt->setUInt64(0, lowGuid);

    trans->Append(stmt);

    CharacterDatabase.CommitTransaction(trans);

    TC_LOG_INFO("entities.player.character", "Account: {} (IP: {}) Character:[{}] ({}) Changed name to: {}",
        GetAccountId(), GetRemoteAddress(), oldName, renameInfo->Guid.ToString(), renameInfo->NewName);

    SendCharRename(RESPONSE_SUCCESS, renameInfo.get());

    sCharacterCache->UpdateCharacterData(renameInfo->Guid, renameInfo->NewName);
}

void WorldSession::HandleSetPlayerDeclinedNames(WorldPackets::Character::SetPlayerDeclinedNames& packet)
{
    // not accept declined names for unsupported languages
    std::string name;
    if (!sCharacterCache->GetCharacterNameByGuid(packet.Player, name))
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

    CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();

    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHAR_DECLINED_NAME);
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
    Trinity::IteratorPair<UF::ChrCustomizationChoice const*> customizations = MakeChrCustomizationChoiceRange(packet.Customizations);
    if (packet.CustomizedChrModelID)
    {
        ConditionalChrModelEntry const* conditionalChrModel = DB2Manager::GetConditionalChrModel(packet.CustomizedChrModelID);
        if (!conditionalChrModel)
            return;

        if (ChrCustomizationReqEntry const* req = sChrCustomizationReqStore.LookupEntry(conditionalChrModel->ChrCustomizationReqID))
            if (!MeetsChrCustomizationReq(req, Races(packet.CustomizedRace), Classes(_player->GetClass()), false, customizations))
                return;

        if (!ConditionMgr::IsPlayerMeetingCondition(_player, conditionalChrModel->PlayerConditionID))
            return;
    }

    if (!ValidateAppearance(Races(_player->GetRace()), Classes(_player->GetClass()), Gender(packet.NewSex), customizations))
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

    int64 cost = _player->GetBarberShopCost(customizations);

    // 0 - ok
    // 1, 3 - not enough money
    // 2 - you have to sit on barber chair
    if (!_player->HasEnoughMoney(cost))
    {
        SendPacket(WorldPackets::Character::BarberShopResult(WorldPackets::Character::BarberShopResult::ResultEnum::NoMoney).Write());
        return;
    }

    SendPacket(WorldPackets::Character::BarberShopResult(WorldPackets::Character::BarberShopResult::ResultEnum::Success).Write());

    _player->ModifyMoney(-cost);                     // it isn't free
    _player->UpdateCriteria(CriteriaType::MoneySpentAtBarberShop, cost);

    if (_player->GetNativeGender() != packet.NewSex)
    {
        _player->SetNativeGender(Gender(packet.NewSex));
        _player->InitDisplayIds();
        _player->RestoreDisplayId(false);
    }

    _player->SetCustomizations(Trinity::Containers::MakeIteratorPair(packet.Customizations.begin(), packet.Customizations.end()));

    _player->UpdateCriteria(CriteriaType::GotHaircut, 1);

    _player->SetStandState(UNIT_STAND_STATE_STAND);

    sCharacterCache->UpdateCharacterGender(_player->GetGUID(), packet.NewSex);
}

void WorldSession::HandleCharCustomizeOpcode(WorldPackets::Character::CharCustomize& packet)
{
    if (!IsLegitCharacterForAccount(packet.CustomizeInfo->CharGUID))
    {
        TC_LOG_ERROR("entities.player.cheat", "Account {}, IP: {} tried to customise {}, but it does not belong to their account!",
            GetAccountId(), GetRemoteAddress(), packet.CustomizeInfo->CharGUID.ToString());
        KickPlayer("WorldSession::HandleCharCustomize Trying to customise character of another account");
        return;
    }

    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHAR_CUSTOMIZE_INFO);
    stmt->setUInt64(0, packet.CustomizeInfo->CharGUID.GetCounter());

    _queryProcessor.AddCallback(CharacterDatabase.AsyncQuery(stmt)
        .WithPreparedCallback([this, customizeInfo = std::move(packet.CustomizeInfo)](PreparedQueryResult result) mutable
        {
            HandleCharCustomizeCallback(std::move(customizeInfo), std::move(result));
        }));
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
    Races plrRace = Races(fields[1].GetUInt8());
    Classes plrClass = Classes(fields[2].GetUInt8());
    Gender plrGender = Gender(fields[3].GetUInt8());
    uint16 atLoginFlags = fields[4].GetUInt16();

    if (!ValidateAppearance(plrRace, plrClass, plrGender, MakeChrCustomizationChoiceRange(customizeInfo->Customizations)))
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
    ObjectGuid newGuid = sCharacterCache->GetCharacterGuidByName(customizeInfo->CharName);
    if (!newGuid.IsEmpty())
    {
        if (newGuid != customizeInfo->CharGUID)
        {
            SendCharCustomize(CHAR_CREATE_NAME_IN_USE, customizeInfo.get());
            return;
        }
    }

    CharacterDatabasePreparedStatement* stmt = nullptr;
    CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();

    ObjectGuid::LowType lowGuid = customizeInfo->CharGUID.GetCounter();

    /// Customize
    Player::SaveCustomizations(trans, lowGuid, MakeChrCustomizationChoiceRange(customizeInfo->Customizations));

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

    sCharacterCache->UpdateCharacterData(customizeInfo->CharGUID, customizeInfo->CharName, customizeInfo->SexID);

    SendCharCustomize(RESPONSE_SUCCESS, customizeInfo.get());

    TC_LOG_INFO("entities.player.character", "Account: {} (IP: {}), Character[{}] ({}) Customized to: {}",
        GetAccountId(), GetRemoteAddress(), oldName, customizeInfo->CharGUID.ToString(), customizeInfo->CharName);
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

                    auto [hasAppearance, isTemporary] = GetCollectionMgr()->HasItemAppearance(saveEquipmentSet.Set.Appearances[i]);
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

            if (!illusion->ItemVisual || !illusion->GetFlags().HasFlag(SpellItemEnchantmentFlags::AllowTransmog))
                return false;

            if (!ConditionMgr::IsPlayerMeetingCondition(_player, illusion->TransmogUseConditionID))
                return false;

            if (illusion->ScalingClassRestricted > 0 && uint8(illusion->ScalingClassRestricted) != _player->GetClass())
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
        TC_LOG_DEBUG("entities.player.items", "{}: ContainerSlot: {}, Slot: {}", useEquipmentSet.Items[i].Item.ToString(), useEquipmentSet.Items[i].ContainerSlot, useEquipmentSet.Items[i].Slot);

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
                if (_player->CanUnequipItem(dstPos, true) != EQUIP_ERR_OK)
                    continue;

                _player->RemoveItem(INVENTORY_SLOT_BAG_0, i, true);
                _player->StoreItem(itemPosCountVec, uItem, true);
            }
            else
                _player->SendEquipError(inventoryResult, uItem,  nullptr);
            continue;
        }

        if (item->GetPos() == dstPos)
            continue;

        if (_player->CanEquipItem(i, dstPos, item, true) != EQUIP_ERR_OK)
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
        TC_LOG_ERROR("entities.player.cheat", "Account {}, IP: {} tried to factionchange character {}, but it does not belong to their account!",
            GetAccountId(), GetRemoteAddress(), packet.RaceOrFactionChangeInfo->Guid.ToString());
        KickPlayer("WorldSession::HandleCharFactionOrRaceChange Trying to change faction of character of another account");
        return;
    }

    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHAR_RACE_OR_FACTION_CHANGE_INFOS);
    stmt->setUInt64(0, packet.RaceOrFactionChangeInfo->Guid.GetCounter());

    _queryProcessor.AddCallback(CharacterDatabase.AsyncQuery(stmt)
        .WithPreparedCallback([this, factionChangeInfo = std::move(packet.RaceOrFactionChangeInfo)](PreparedQueryResult result) mutable
        {
            HandleCharRaceOrFactionChangeCallback(std::move(factionChangeInfo), std::move(result));
        }));
}

void WorldSession::HandleCharRaceOrFactionChangeCallback(std::shared_ptr<WorldPackets::Character::CharRaceOrFactionChangeInfo> factionChangeInfo, PreparedQueryResult result)
{
    if (!result)
    {
        SendCharFactionChange(CHAR_CREATE_ERROR, factionChangeInfo.get());
        return;
    }

    // get the players old (at this moment current) race
    CharacterCacheEntry const* characterInfo = sCharacterCache->GetCharacterCacheByGuid(factionChangeInfo->Guid);
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
    uint32 groupId             = !fields[2].IsNull() ? fields[2].GetUInt32() : 0;

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
        Trinity::RaceMask<uint64> raceMaskDisabled{ sWorld->GetUInt64Config(CONFIG_CHARACTER_CREATING_DISABLED_RACEMASK) };
        if (raceMaskDisabled.HasRace(factionChangeInfo->RaceID))
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
    ObjectGuid newGuid = sCharacterCache->GetCharacterGuidByName(factionChangeInfo->Name);
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

    CharacterDatabasePreparedStatement* stmt = nullptr;
    CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();

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
    Player::SaveCustomizations(trans, lowGuid, MakeChrCustomizationChoiceRange(factionChangeInfo->Customizations));

    // Race Change
    {
        stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_CHAR_RACE);
        stmt->setUInt8(0, factionChangeInfo->RaceID);
        stmt->setUInt16(1, PLAYER_EXTRA_HAS_RACE_CHANGED);
        stmt->setUInt64(2, lowGuid);

        trans->Append(stmt);
    }

    sCharacterCache->UpdateCharacterData(factionChangeInfo->Guid, factionChangeInfo->Name, factionChangeInfo->SexID, factionChangeInfo->RaceID);

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
        std::array<uint8, 4> const racesWithoutSpecificLanguages = { RACE_ORC, RACE_HUMAN, RACE_MAGHAR_ORC, RACE_KUL_TIRAN };
        if (std::find(racesWithoutSpecificLanguages.begin(), racesWithoutSpecificLanguages.end(), factionChangeInfo->RaceID) == racesWithoutSpecificLanguages.end())
        {
            stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_CHAR_SKILL_LANGUAGE);
            stmt->setUInt64(0, lowGuid);

            switch (factionChangeInfo->RaceID)
            {
                case RACE_DWARF:
                case RACE_DARK_IRON_DWARF:
                    stmt->setUInt16(1, 111);
                    break;
                case RACE_DRAENEI:
                case RACE_LIGHTFORGED_DRAENEI:
                    stmt->setUInt16(1, 759);
                    break;
                case RACE_GNOME:
                case RACE_MECHAGNOME:
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
                case RACE_HIGHMOUNTAIN_TAUREN:
                    stmt->setUInt16(1, 115);
                    break;
                case RACE_TROLL:
                case RACE_ZANDALARI_TROLL:
                    stmt->setUInt16(1, 315);
                    break;
                case RACE_BLOODELF:
                case RACE_VOID_ELF:
                    stmt->setUInt16(1, 137);
                    break;
                case RACE_GOBLIN:
                    stmt->setUInt16(1, 792);
                    break;
                case RACE_NIGHTBORNE:
                    stmt->setUInt16(1, 2464);
                    break;
                case RACE_VULPERA:
                    stmt->setUInt16(1, 2776);
                    break;
                case LANG_PANDAREN_ALLIANCE:
                case LANG_PANDAREN_HORDE:
                    stmt->setUInt16(1, 905);
                    break;
                case RACE_DRACTHYR_ALLIANCE:
                case RACE_DRACTHYR_HORDE:
                    stmt->setUInt16(1, 138);
                    break;
                default:
                    TC_LOG_ERROR("entities.player", "Could not find language data for race ({}).", factionChangeInfo->RaceID);
                    SendCharFactionChange(CHAR_CREATE_ERROR, factionChangeInfo.get());
                    return;
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
                for (std::size_t i = 0; i < factionMask.size(); ++i)
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

            if (!sWorld->getBoolConfig(CONFIG_ALLOW_TWO_SIDE_INTERACTION_GUILD))
            {
                // Reset guild
                if (Guild* guild = sGuildMgr->GetGuildById(characterInfo->GuildId))
                    guild->DeleteMember(trans, factionChangeInfo->Guid, false, false);

                Player::LeaveAllArenaTeams(factionChangeInfo->Guid);
            }

            if (groupId && !sWorld->getBoolConfig(CONFIG_ALLOW_TWO_SIDE_INTERACTION_GROUP))
            {
                if (Group* group = sGroupMgr->GetGroupByDbStoreId(groupId))
                    group->RemoveMember(factionChangeInfo->Guid);
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
            ObjectMgr::CharacterConversionMap const& itemConversionMap = newTeamId == TEAM_ALLIANCE
                ? sObjectMgr->FactionChangeItemsHordeToAlliance
                : sObjectMgr->FactionChangeItemsAllianceToHorde;
            for (std::map<uint32, uint32>::const_iterator it = itemConversionMap.begin(); it != itemConversionMap.end(); ++it)
            {
                uint32 oldItemId = it->first;
                uint32 newItemId = it->second;

                stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_CHAR_INVENTORY_FACTION_CHANGE);
                stmt->setUInt32(0, newItemId);
                stmt->setUInt32(1, oldItemId);
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
                ObjectMgr::QuestContainer const& questTemplates = sObjectMgr->GetQuestTemplates();
                for (auto const& [questId, quest] : questTemplates)
                {
                    Trinity::RaceMask<uint64> newRaceMask = (newTeamId == TEAM_ALLIANCE) ? RACEMASK_ALLIANCE : RACEMASK_HORDE;
                    if (quest->GetAllowableRaces().RawValue != uint64(-1) && (quest->GetAllowableRaces() & newRaceMask).IsEmpty())
                    {
                        stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_CHAR_QUESTSTATUS_REWARDED_ACTIVE_BY_QUEST);
                        stmt->setUInt64(0, lowGuid);
                        stmt->setUInt32(1, questId);
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
                std::vector<std::string_view> tokens = Trinity::Tokenize(knownTitlesStr, ' ', false);
                std::vector<uint32> knownTitles;

                for (std::string_view token : tokens)
                {
                    if (Optional<uint32> thisMask = Trinity::StringTo<uint32>(token))
                        knownTitles.push_back(*thisMask);
                    else
                    {
                        TC_LOG_WARN("entities.player", "{} has invalid title data '{}' - skipped, this may result in titles being lost",
                           GetPlayerInfo(), token);
                        knownTitles.push_back(0);
                    }
                }

                for (std::map<uint32, uint32>::const_iterator it = sObjectMgr->FactionChangeTitles.begin(); it != sObjectMgr->FactionChangeTitles.end(); ++it)
                {
                    uint32 title_alliance = it->first;
                    uint32 title_horde = it->second;

                    CharTitlesEntry const* atitleInfo = sCharTitlesStore.AssertEntry(title_alliance);
                    CharTitlesEntry const* htitleInfo = sCharTitlesStore.AssertEntry(title_horde);
                    // new team
                    if (newTeamId == TEAM_ALLIANCE)
                    {
                        uint32 bitIndex = htitleInfo->MaskID;
                        uint32 index = bitIndex / 32;
                        if (index >= knownTitles.size())
                            continue;

                        uint32 old_flag = 1 << (bitIndex % 32);
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
                        uint32 bitIndex = htitleInfo->MaskID;
                        uint32 index = bitIndex / 32;
                        if (index >= knownTitles.size())
                            continue;

                        uint32 old_flag = 1 << (bitIndex % 32);
                        uint32 new_flag = 1 << (htitleInfo->MaskID % 32);
                        if (knownTitles[index] & old_flag)
                        {
                            knownTitles[index] &= ~old_flag;
                            // use index of the new title
                            knownTitles[htitleInfo->MaskID / 32] |= new_flag;
                        }
                    }

                    std::ostringstream ss;
                    for (uint32 mask : knownTitles)
                        ss << mask << ' ';

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

    TC_LOG_DEBUG("entities.player", "{} (IP: {}) changed race from {} to {}", GetPlayerInfo(), GetRemoteAddress(), oldRace, factionChangeInfo->RaceID);

    SendCharFactionChange(RESPONSE_SUCCESS, factionChangeInfo.get());
}

void WorldSession::HandleRandomizeCharNameOpcode(WorldPackets::Character::GenerateRandomCharacterName& packet)
{
    if (!Player::IsValidRace(packet.Race))
    {
        TC_LOG_ERROR("misc", "Invalid race ({}) sent by accountId: {}", packet.Race, GetAccountId());
        return;
    }

    if (!Player::IsValidGender(packet.Sex))
    {
        TC_LOG_ERROR("misc", "Invalid gender ({}) sent by accountId: {}", packet.Sex, GetAccountId());
        return;
    }

    WorldPackets::Character::GenerateRandomCharacterNameResult result;
    result.Success = true;
    result.Name = sDB2Manager.GetNameGenEntry(packet.Race, packet.Sex);

    SendPacket(result.Write());
}

void WorldSession::HandleReorderCharacters(WorldPackets::Character::ReorderCharacters& reorderChars)
{
    CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();

    for (WorldPackets::Character::ReorderCharacters::ReorderInfo const& reorderInfo : reorderChars.Entries)
    {
        CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_CHAR_LIST_SLOT);
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
    if (*_player->m_activePlayerData->XP)
        return;

    if (ChrClassesEntry const* classEntry = sChrClassesStore.LookupEntry(_player->GetClass()))
    {
        if (classEntry->CinematicSequenceID)
            _player->SendCinematicStart(classEntry->CinematicSequenceID);
        else if (ChrRacesEntry const* raceEntry = sChrRacesStore.LookupEntry(_player->GetRace()))
            _player->SendCinematicStart(raceEntry->CinematicSequenceID);
    }
}

void WorldSession::HandleGetUndeleteCooldownStatus(WorldPackets::Character::GetUndeleteCharacterCooldownStatus& /*getCooldown*/)
{
    LoginDatabasePreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_SEL_LAST_CHAR_UNDELETE);
    stmt->setUInt32(0, GetBattlenetAccountId());

    _queryProcessor.AddCallback(LoginDatabase.AsyncQuery(stmt).WithPreparedCallback([this](PreparedQueryResult result)
    {
        HandleUndeleteCooldownStatusCallback(std::move(result));
    }));
}

void WorldSession::HandleUndeleteCooldownStatusCallback(PreparedQueryResult result)
{
    uint32 cooldown = 0;
    uint32 maxCooldown = sWorld->getIntConfig(CONFIG_FEATURE_SYSTEM_CHARACTER_UNDELETE_COOLDOWN);
    if (result)
    {
        uint32 lastUndelete = result->Fetch()[0].GetUInt32();
        uint32 now = uint32(GameTime::GetGameTime());
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

    LoginDatabasePreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_SEL_LAST_CHAR_UNDELETE);
    stmt->setUInt32(0, GetBattlenetAccountId());

    std::shared_ptr<WorldPackets::Character::CharacterUndeleteInfo> undeleteInfo = undeleteCharacter.UndeleteInfo;
    _queryProcessor.AddCallback(LoginDatabase.AsyncQuery(stmt)
        .WithChainingPreparedCallback([this, undeleteInfo](QueryCallback& queryCallback, PreparedQueryResult result)
    {
        if (result)
        {
            uint32 lastUndelete = result->Fetch()[0].GetUInt32();
            uint32 maxCooldown = sWorld->getIntConfig(CONFIG_FEATURE_SYSTEM_CHARACTER_UNDELETE_COOLDOWN);
            if (lastUndelete && (lastUndelete + maxCooldown > GameTime::GetGameTime()))
            {
                SendUndeleteCharacterResponse(CHARACTER_UNDELETE_RESULT_ERROR_COOLDOWN, undeleteInfo.get());
                return;
            }
        }

        CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHAR_DEL_INFO_BY_GUID);
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

        CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHECK_NAME);
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

        CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_SUM_CHARS);
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

        CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_RESTORE_DELETE_INFO);
        stmt->setString(0, undeleteInfo->Name);
        stmt->setUInt32(1, GetAccountId());
        stmt->setUInt64(2, undeleteInfo->CharacterGuid.GetCounter());
        CharacterDatabase.Execute(stmt);

        LoginDatabasePreparedStatement* loginStmt = LoginDatabase.GetPreparedStatement(LOGIN_UPD_LAST_CHAR_UNDELETE);
        loginStmt->setUInt32(0, GetBattlenetAccountId());
        LoginDatabase.Execute(loginStmt);

        sCharacterCache->UpdateCharacterInfoDeleted(undeleteInfo->CharacterGuid, false, undeleteInfo->Name);

        SendUndeleteCharacterResponse(CHARACTER_UNDELETE_RESULT_OK, undeleteInfo.get());
    }));
}

void WorldSession::HandleSavePersonalEmblem(WorldPackets::Character::SavePersonalEmblem const& savePersonalEmblem)
{
    if (!_player->GetNPCIfCanInteractWith(savePersonalEmblem.Vendor, UNIT_NPC_FLAG_NONE, UNIT_NPC_FLAG_2_PERSONAL_TABARD_DESIGNER))
    {
        SendPacket(WorldPackets::Character::PlayerSavePersonalEmblem(ERR_GUILDEMBLEM_INVALIDVENDOR).Write());
        return;
    }

    if (!EmblemInfo::ValidateEmblemColors(savePersonalEmblem.PersonalTabard.EmblemStyle, savePersonalEmblem.PersonalTabard.EmblemColor,
        savePersonalEmblem.PersonalTabard.BorderStyle, savePersonalEmblem.PersonalTabard.BorderColor,
        savePersonalEmblem.PersonalTabard.BackgroundColor))
    {
        SendPacket(WorldPackets::Character::PlayerSavePersonalEmblem(ERR_GUILDEMBLEM_INVALID_TABARD_COLORS).Write());
        return;
    }

    _player->SetPersonalTabard(savePersonalEmblem.PersonalTabard.EmblemStyle, savePersonalEmblem.PersonalTabard.EmblemColor,
        savePersonalEmblem.PersonalTabard.BorderStyle, savePersonalEmblem.PersonalTabard.BorderColor,
        savePersonalEmblem.PersonalTabard.BackgroundColor);

    SendPacket(WorldPackets::Character::PlayerSavePersonalEmblem(ERR_GUILDEMBLEM_SUCCESS).Write());
}

void WorldSession::SendCharCreate(ResponseCodes result, ObjectGuid const& guid /*= ObjectGuid::Empty*/)
{
    WorldPackets::Character::CreateChar response;
    response.Code = result;
    response.Guid = guid;

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
        WorldPackets::Character::CharCustomizeSuccess response(customizeInfo);
        SendPacket(response.Write());
    }
    else
    {
        WorldPackets::Character::CharCustomizeFailure failed;
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
        packet.Display.emplace();
        packet.Display->Name = factionChangeInfo->Name;
        packet.Display->SexID = factionChangeInfo->SexID;
        packet.Display->Customizations = &factionChangeInfo->Customizations;
        packet.Display->RaceID = factionChangeInfo->RaceID;
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
