/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
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

#include "Player.h"
#include "AccountMgr.h"
#include "AchievementMgr.h"
#include "ArenaTeam.h"
#include "ArenaTeamMgr.h"
#include "Battlefield.h"
#include "BattlefieldMgr.h"
#include "BattlefieldWG.h"
#include "Battleground.h"
#include "BattlegroundMgr.h"
#include "BattlegroundScore.h"
#include "BattlePetMgr.h"
#include "CellImpl.h"
#include "ChannelMgr.h"
#include "CharacterDatabaseCleaner.h"
#include "CharacterPackets.h"
#include "Chat.h"
#include "ChatPackets.h"
#include "CombatLogPackets.h"
#include "CombatPackets.h"
#include "Common.h"
#include "ConditionMgr.h"
#include "CreatureAI.h"
#include "DB2Stores.h"
#include "DatabaseEnv.h"
#include "DisableMgr.h"
#include "DuelPackets.h"
#include "EquipmentSetPackets.h"
#include "Formulas.h"
#include "GameEventMgr.h"
#include "GameObjectAI.h"
#include "Garrison.h"
#include "GossipDef.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"
#include "Group.h"
#include "GroupMgr.h"
#include "Guild.h"
#include "GuildMgr.h"
#include "InstancePackets.h"
#include "InstanceSaveMgr.h"
#include "InstanceScript.h"
#include "ItemPackets.h"
#include "KillRewarder.h"
#include "LFGMgr.h"
#include "Language.h"
#include "Log.h"
#include "LootPackets.h"
#include "MailPackets.h"
#include "MapManager.h"
#include "MiscPackets.h"
#include "MovementPackets.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "Opcodes.h"
#include "OutdoorPvP.h"
#include "OutdoorPvPMgr.h"
#include "Pet.h"
#include "PetPackets.h"
#include "QuestDef.h"
#include "QuestPackets.h"
#include "ReputationMgr.h"
#include "GitRevision.h"
#include "SkillDiscovery.h"
#include "SocialMgr.h"
#include "Spell.h"
#include "SpellAuraEffects.h"
#include "SpellAuras.h"
#include "SpellHistory.h"
#include "SpellMgr.h"
#include "SpellPackets.h"
#include "TalentPackets.h"
#include "ToyPackets.h"
#include "Transport.h"
#include "UpdateData.h"
#include "UpdateFieldFlags.h"
#include "UpdateMask.h"
#include "Util.h"
#include "VehiclePackets.h"
#include "Weather.h"
#include "WeatherMgr.h"
#include "World.h"
#include "WorldPacket.h"
#include "WorldSession.h"
#include "WorldStatePackets.h"
#include "DBCStructure.h"

#define ZONE_UPDATE_INTERVAL (1*IN_MILLISECONDS)

// corpse reclaim times
#define DEATH_EXPIRE_STEP (5*MINUTE)
#define MAX_DEATH_COUNT 3

static uint32 copseReclaimDelay[MAX_DEATH_COUNT] = { 30, 60, 120 };

uint32 const MasterySpells[MAX_CLASSES] =
{
        0,
    87500,  // Warrior
    87494,  // Paladin
    87493,  // Hunter
    87496,  // Rogue
    87495,  // Priest
    87492,  // Death Knight
    87497,  // Shaman
    86467,  // Mage
    87498,  // Warlock
        0,
    87491,  // Druid
};

uint64 const MAX_MONEY_AMOUNT = 9999999999ULL;

Player::Player(WorldSession* session) : Unit(true)
{
    m_speakTime = 0;
    m_speakCount = 0;

    m_objectType |= TYPEMASK_PLAYER;
    m_objectTypeId = TYPEID_PLAYER;

    m_valuesCount = PLAYER_END;
    _dynamicValuesCount = PLAYER_DYNAMIC_END;

    m_session = session;

    m_ingametime = 0;

    m_ExtraFlags = 0;

    m_spellModTakingSpell = nullptr;
    //m_pad = 0;

    // players always accept
    if (!GetSession()->HasPermission(rbac::RBAC_PERM_CAN_FILTER_WHISPERS))
        SetAcceptWhispers(true);

    m_regenTimer = 0;
    m_regenTimerCount = 0;
    m_holyPowerRegenTimerCount = 0;
    m_focusRegenTimerCount = 0;
    m_weaponChangeTimer = 0;

    m_zoneUpdateId = uint32(-1);
    m_zoneUpdateTimer = 0;

    m_areaUpdateId = 0;
    m_team = 0;

    m_nextSave = sWorld->getIntConfig(CONFIG_INTERVAL_SAVE);

    memset(m_items, 0, sizeof(Item*)*PLAYER_SLOTS_COUNT);

    m_social = nullptr;

    // group is initialized in the reference constructor
    SetGroupInvite(nullptr);
    m_groupUpdateMask = 0;
    m_bPassOnGroupLoot = false;

    duel = nullptr;

    m_GuildIdInvited = UI64LIT(0);
    m_ArenaTeamIdInvited = 0;

    m_atLoginFlags = AT_LOGIN_NONE;

    mSemaphoreTeleport_Near = false;
    mSemaphoreTeleport_Far = false;

    m_DelayedOperations = 0;
    m_bCanDelayTeleport = false;
    m_bHasDelayedTeleport = false;
    m_teleport_options = 0;

    m_trade = nullptr;

    m_cinematic = 0;

    PlayerTalkClass = new PlayerMenu(GetSession());
    m_currentBuybackSlot = BUYBACK_SLOT_START;

    m_DailyQuestChanged = false;
    m_lastDailyQuestTime = 0;

    // Init rune flags
    for (uint8 i = 0; i < MAX_RUNES; ++i)
    {
        SetRuneTimer(i, 0xFFFFFFFF);
        SetLastRuneGraceTimer(i, 0);
    }

    for (uint8 i=0; i < MAX_TIMERS; i++)
        m_MirrorTimer[i] = DISABLED_MIRROR_TIMER;

    m_MirrorTimerFlags = UNDERWATER_NONE;
    m_MirrorTimerFlagsLast = UNDERWATER_NONE;
    m_isInWater = false;
    m_drunkTimer = 0;
    m_deathTimer = 0;
    m_deathExpireTime = 0;

    m_swingErrorMsg = 0;

    for (uint8 j = 0; j < PLAYER_MAX_BATTLEGROUND_QUEUES; ++j)
    {
        m_bgBattlegroundQueueID[j].bgQueueTypeId = BATTLEGROUND_QUEUE_NONE;
        m_bgBattlegroundQueueID[j].invitedToInstance = 0;
        m_bgBattlegroundQueueID[j].joinTime = 0;
    }

    m_logintime = time(nullptr);
    m_Last_tick = m_logintime;
    m_Played_time[PLAYED_TIME_TOTAL] = 0;
    m_Played_time[PLAYED_TIME_LEVEL] = 0;
    m_WeaponProficiency = 0;
    m_ArmorProficiency = 0;
    m_canParry = false;
    m_canBlock = false;
    m_canTitanGrip = false;

    m_temporaryUnsummonedPetNumber = 0;
    //cache for UNIT_CREATED_BY_SPELL to allow
    //returning reagents for temporarily removed pets
    //when dying/logging out
    m_oldpetspell = 0;
    m_lastpetnumber = 0;

    ////////////////////Rest System/////////////////////
    _restTime = 0;
    inn_triggerId = 0;
    m_rest_bonus = 0;
    _restFlagMask = 0;
    ////////////////////Rest System/////////////////////

    m_mailsLoaded = false;
    m_mailsUpdated = false;
    unReadMails = 0;
    m_nextMailDelivereTime = 0;

    m_itemUpdateQueueBlocked = false;

    for (uint8 i = 0; i < MAX_MOVE_TYPE; ++i)
        m_forced_speed_changes[i] = 0;

    m_stableSlots = 0;

    /////////////////// Instance System /////////////////////

    m_HomebindTimer = 0;
    m_InstanceValid = true;
    m_dungeonDifficulty = DIFFICULTY_NORMAL;
    m_raidDifficulty = DIFFICULTY_NORMAL_RAID;
    m_legacyRaidDifficulty = DIFFICULTY_10_N;
    m_prevMapDifficulty = DIFFICULTY_NORMAL_RAID;

    m_lastPotionId = 0;
    _talentMgr = new PlayerTalentInfo();

    for (uint8 i = 0; i < BASEMOD_END; ++i)
    {
        m_auraBaseMod[i][FLAT_MOD] = 0.0f;
        m_auraBaseMod[i][PCT_MOD] = 1.0f;
    }

    for (uint8 i = 0; i < MAX_COMBAT_RATING; i++)
        m_baseRatingValue[i] = 0;

    m_baseSpellPower = 0;
    m_baseManaRegen = 0;
    m_baseHealthRegen = 0;
    m_spellPenetrationItemMod = 0;

    // Honor System
    m_lastHonorUpdateTime = time(nullptr);

    m_IsBGRandomWinner = false;

    // Player summoning
    m_summon_expire = 0;
    m_summon_mapid = 0;
    m_summon_x = 0.0f;
    m_summon_y = 0.0f;
    m_summon_z = 0.0f;

    m_mover = this;
    m_movedPlayer = this;
    m_seer = this;

    m_recallMap = 0;
    m_recallX = 0;
    m_recallY = 0;
    m_recallZ = 0;
    m_recallO = 0;

    m_homebindMapId = 0;
    m_homebindAreaId = 0;
    m_homebindX = 0;
    m_homebindY = 0;
    m_homebindZ = 0;

    m_contestedPvPTimer = 0;

    m_declinedname = nullptr;

    m_isActive = true;

    m_runes = nullptr;

    m_lastFallTime = 0;
    m_lastFallZ = 0;

    m_grantableLevels = 0;

    m_ControlledByPlayer = true;

    sWorld->IncreasePlayerCount();

    m_ChampioningFaction = 0;

    m_timeSyncTimer = 0;
    m_timeSyncClient = 0;
    m_timeSyncServer = 0;

    for (uint8 i = 0; i < MAX_POWERS_PER_CLASS; ++i)
        m_powerFraction[i] = 0;

    isDebugAreaTriggers = false;

    m_WeeklyQuestChanged = false;
    m_MonthlyQuestChanged = false;
    m_SeasonalQuestChanged = false;

    SetPendingBind(0, 0);

    _activeCheats = CHEAT_NONE;
    healthBeforeDuel = 0;
    manaBeforeDuel = 0;
    _maxPersonalArenaRate = 0;

    memset(_voidStorageItems, 0, VOID_STORAGE_MAX_SLOT * sizeof(VoidStorageItem*));

    m_achievementMgr = new AchievementMgr<Player>(this);
    m_reputationMgr = new ReputationMgr(this);

    for (uint8 i = 0; i < MAX_CUF_PROFILES; ++i)
        _CUFProfiles[i] = nullptr;

    _advancedCombatLoggingEnabled = false;
}

Player::~Player()
{
    // it must be unloaded already in PlayerLogout and accessed only for logged in player
    //m_social = NULL;

    // Note: buy back item already deleted from DB when player was saved
    for (uint8 i = 0; i < PLAYER_SLOTS_COUNT; ++i)
        delete m_items[i];

    for (PlayerSpellMap::const_iterator itr = m_spells.begin(); itr != m_spells.end(); ++itr)
        delete itr->second;

    delete _talentMgr;

    //all mailed items should be deleted, also all mail should be deallocated
    for (PlayerMails::iterator itr = m_mail.begin(); itr != m_mail.end(); ++itr)
        delete *itr;

    for (ItemMap::iterator iter = mMitems.begin(); iter != mMitems.end(); ++iter)
        delete iter->second;                                //if item is duplicated... then server may crash ... but that item should be deallocated

    delete PlayerTalkClass;

    for (size_t x = 0; x < ItemSetEff.size(); x++)
        delete ItemSetEff[x];

    delete m_declinedname;
    delete m_runes;
    delete m_achievementMgr;
    delete m_reputationMgr;

    for (uint8 i = 0; i < VOID_STORAGE_MAX_SLOT; ++i)
        delete _voidStorageItems[i];

    sWorld->DecreasePlayerCount();
}

void Player::CleanupsBeforeDelete(bool finalCleanup)
{
    TradeCancel(false);
    DuelComplete(DUEL_INTERRUPTED);

    Unit::CleanupsBeforeDelete(finalCleanup);

    // clean up player-instance binds, may unload some instance saves
    for (uint8 i = 0; i < MAX_DIFFICULTY; ++i)
        for (BoundInstancesMap::iterator itr = m_boundInstances[i].begin(); itr != m_boundInstances[i].end(); ++itr)
            itr->second.save->RemovePlayer(this);
}

bool Player::Create(ObjectGuid::LowType guidlow, WorldPackets::Character::CharacterCreateInfo const* createInfo)
{
    //FIXME: outfitId not used in player creating
    /// @todo need more checks against packet modifications

    Object::_Create(ObjectGuid::Create<HighGuid::Player>(guidlow));

    m_name = createInfo->Name;

    PlayerInfo const* info = sObjectMgr->GetPlayerInfo(createInfo->Race, createInfo->Class);
    if (!info)
    {
        TC_LOG_ERROR("entities.player", "Player::Create: Possible hacking-attempt: Account %u tried creating a character named '%s' with an invalid race/class pair (%u/%u) - refusing to do so.",
                GetSession()->GetAccountId(), m_name.c_str(), createInfo->Race, createInfo->Class);
        return false;
    }

    for (uint8 i = 0; i < PLAYER_SLOTS_COUNT; i++)
        m_items[i] = nullptr;

    Relocate(info->positionX, info->positionY, info->positionZ, info->orientation);

    ChrClassesEntry const* cEntry = sChrClassesStore.LookupEntry(createInfo->Class);
    if (!cEntry)
    {
        TC_LOG_ERROR("entities.player", "Player::Create: Possible hacking-attempt: Account %u tried creating a character named '%s' with an invalid character class (%u) - refusing to do so (wrong DBC-files?)",
                GetSession()->GetAccountId(), m_name.c_str(), createInfo->Class);
        return false;
    }

    if (!ValidateAppearance(createInfo->Race, createInfo->Class, createInfo->Sex, createInfo->HairStyle, createInfo->HairColor, createInfo->Face, createInfo->FacialHairStyle, createInfo->Skin, true))
    {
        TC_LOG_ERROR("entities.player", "Player::Create: Possible hacking-attempt: Account %u tried creating a character named '%s' with invalid appearance attributes - refusing to do so",
            GetSession()->GetAccountId(), m_name.c_str());
        return false;
    }

    SetMap(sMapMgr->CreateMap(info->mapId, this));

    uint8 powertype = cEntry->PowerType;

    SetObjectScale(1.0f);

    setFactionForRace(createInfo->Race);

    if (!IsValidGender(createInfo->Sex))
    {
        TC_LOG_ERROR("entities.player", "Player::Create: Possible hacking-attempt: Account %u tried creating a character named '%s' with an invalid gender (%u) - refusing to do so",
                GetSession()->GetAccountId(), m_name.c_str(), createInfo->Sex);
        return false;
    }

    SetByteValue(UNIT_FIELD_BYTES_0, UNIT_BYTES_0_OFFSET_RACE, createInfo->Race);
    SetByteValue(UNIT_FIELD_BYTES_0, UNIT_BYTES_0_OFFSET_CLASS, createInfo->Class);
    SetByteValue(UNIT_FIELD_BYTES_0, UNIT_BYTES_0_OFFSET_GENDER, createInfo->Sex);
    SetUInt32Value(UNIT_FIELD_DISPLAY_POWER, powertype);
    InitDisplayIds();
    if (sWorld->getIntConfig(CONFIG_GAME_TYPE) == REALM_TYPE_PVP || sWorld->getIntConfig(CONFIG_GAME_TYPE) == REALM_TYPE_RPPVP)
    {
        SetByteFlag(UNIT_FIELD_BYTES_2, 1, UNIT_BYTE2_FLAG_PVP);
        SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_PVP_ATTACKABLE);
    }

    SetFlag(UNIT_FIELD_FLAGS_2, UNIT_FLAG2_REGENERATE_POWER);
    SetFloatValue(UNIT_FIELD_HOVERHEIGHT, 1.0f);            // default for players in 3.0.3

    SetInt32Value(PLAYER_FIELD_WATCHED_FACTION_INDEX, uint32(-1));  // -1 is default value

    SetByteValue(PLAYER_BYTES, PLAYER_BYTES_OFFSET_SKIN_ID, createInfo->Skin);
    SetByteValue(PLAYER_BYTES, PLAYER_BYTES_OFFSET_FACE_ID, createInfo->Face);
    SetByteValue(PLAYER_BYTES, PLAYER_BYTES_OFFSET_HAIR_STYLE_ID, createInfo->HairStyle);
    SetByteValue(PLAYER_BYTES, PLAYER_BYTES_OFFSET_HAIR_COLOR_ID, createInfo->HairColor);
    SetByteValue(PLAYER_BYTES_2, PLAYER_BYTES_2_OFFSET_FACIAL_STYLE, createInfo->FacialHairStyle);
    SetByteValue(PLAYER_BYTES_2, PLAYER_BYTES_2_OFFSET_REST_STATE, (GetSession()->IsARecruiter() || GetSession()->GetRecruiterId() != 0) ? REST_STATE_RAF_LINKED : REST_STATE_NOT_RAF_LINKED);
    SetByteValue(PLAYER_BYTES_3, PLAYER_BYTES_3_OFFSET_GENDER, createInfo->Sex);
    SetByteValue(PLAYER_BYTES_3, PLAYER_BYTES_3_OFFSET_ARENA_FACTION, 0);

    SetGuidValue(OBJECT_FIELD_DATA, ObjectGuid::Empty);
    SetUInt32Value(PLAYER_GUILDRANK, 0);
    SetGuildLevel(0);
    SetUInt32Value(PLAYER_GUILD_TIMESTAMP, 0);

    for (int i = 0; i < KNOWN_TITLES_SIZE; ++i)
        SetUInt64Value(PLAYER__FIELD_KNOWN_TITLES + i, 0);  // 0=disabled
    SetUInt32Value(PLAYER_CHOSEN_TITLE, 0);

    SetUInt32Value(PLAYER_FIELD_KILLS, 0);
    SetUInt32Value(PLAYER_FIELD_LIFETIME_HONORABLE_KILLS, 0);

    // set starting level
    uint32 start_level = getClass() != CLASS_DEATH_KNIGHT
        ? sWorld->getIntConfig(CONFIG_START_PLAYER_LEVEL)
        : sWorld->getIntConfig(CONFIG_START_HEROIC_PLAYER_LEVEL);

    if (m_session->HasPermission(rbac::RBAC_PERM_USE_START_GM_LEVEL))
    {
        uint32 gm_level = sWorld->getIntConfig(CONFIG_START_GM_LEVEL);
        if (gm_level > start_level)
            start_level = gm_level;
    }

    SetUInt32Value(UNIT_FIELD_LEVEL, start_level);

    InitRunes();

    SetUInt32Value(PLAYER_FIELD_COINAGE, sWorld->getIntConfig(CONFIG_START_PLAYER_MONEY));
    SetCurrency(CURRENCY_TYPE_HONOR_POINTS, sWorld->getIntConfig(CONFIG_CURRENCY_START_HONOR_POINTS));
    SetCurrency(CURRENCY_TYPE_APEXIS_CRYSTALS, sWorld->getIntConfig(CONFIG_CURRENCY_START_APEXIS_CRYSTALS));
    SetCurrency(CURRENCY_TYPE_JUSTICE_POINTS, sWorld->getIntConfig(CONFIG_CURRENCY_START_JUSTICE_POINTS));
    SetCurrency(CURRENCY_TYPE_CONQUEST_POINTS, sWorld->getIntConfig(CONFIG_CURRENCY_START_CONQUEST_POINTS));

    // start with every map explored
    if (sWorld->getBoolConfig(CONFIG_START_ALL_EXPLORED))
    {
        for (uint8 i=0; i<PLAYER_EXPLORED_ZONES_SIZE; i++)
            SetFlag(PLAYER_EXPLORED_ZONES_1+i, 0xFFFFFFFF);
    }

    //Reputations if "StartAllReputation" is enabled, -- @todo Fix this in a better way
    if (sWorld->getBoolConfig(CONFIG_START_ALL_REP))
    {
        GetReputationMgr().SetReputation(sFactionStore.LookupEntry(942), 42999);
        GetReputationMgr().SetReputation(sFactionStore.LookupEntry(935), 42999);
        GetReputationMgr().SetReputation(sFactionStore.LookupEntry(936), 42999);
        GetReputationMgr().SetReputation(sFactionStore.LookupEntry(1011), 42999);
        GetReputationMgr().SetReputation(sFactionStore.LookupEntry(970), 42999);
        GetReputationMgr().SetReputation(sFactionStore.LookupEntry(967), 42999);
        GetReputationMgr().SetReputation(sFactionStore.LookupEntry(989), 42999);
        GetReputationMgr().SetReputation(sFactionStore.LookupEntry(932), 42999);
        GetReputationMgr().SetReputation(sFactionStore.LookupEntry(934), 42999);
        GetReputationMgr().SetReputation(sFactionStore.LookupEntry(1038), 42999);
        GetReputationMgr().SetReputation(sFactionStore.LookupEntry(1077), 42999);

        // Factions depending on team, like cities and some more stuff
        switch (GetTeam())
        {
        case ALLIANCE:
            GetReputationMgr().SetReputation(sFactionStore.LookupEntry(72), 42999);
            GetReputationMgr().SetReputation(sFactionStore.LookupEntry(47), 42999);
            GetReputationMgr().SetReputation(sFactionStore.LookupEntry(69), 42999);
            GetReputationMgr().SetReputation(sFactionStore.LookupEntry(930), 42999);
            GetReputationMgr().SetReputation(sFactionStore.LookupEntry(730), 42999);
            GetReputationMgr().SetReputation(sFactionStore.LookupEntry(978), 42999);
            GetReputationMgr().SetReputation(sFactionStore.LookupEntry(54), 42999);
            GetReputationMgr().SetReputation(sFactionStore.LookupEntry(946), 42999);
            break;
        case HORDE:
            GetReputationMgr().SetReputation(sFactionStore.LookupEntry(76), 42999);
            GetReputationMgr().SetReputation(sFactionStore.LookupEntry(68), 42999);
            GetReputationMgr().SetReputation(sFactionStore.LookupEntry(81), 42999);
            GetReputationMgr().SetReputation(sFactionStore.LookupEntry(911), 42999);
            GetReputationMgr().SetReputation(sFactionStore.LookupEntry(729), 42999);
            GetReputationMgr().SetReputation(sFactionStore.LookupEntry(941), 42999);
            GetReputationMgr().SetReputation(sFactionStore.LookupEntry(530), 42999);
            GetReputationMgr().SetReputation(sFactionStore.LookupEntry(947), 42999);
            break;
        default:
            break;
        }
    }

    // Played time
    m_Last_tick = time(nullptr);
    m_Played_time[PLAYED_TIME_TOTAL] = 0;
    m_Played_time[PLAYED_TIME_LEVEL] = 0;

    // base stats and related field values
    InitStatsForLevel();
    InitTaxiNodesForLevel();
    InitGlyphsForLevel();
    InitTalentForLevel();
    InitPrimaryProfessions();                               // to max set before any spell added

    // apply original stats mods before spell loading or item equipment that call before equip _RemoveStatsMods()
    UpdateMaxHealth();                                      // Update max Health (for add bonus from stamina)
    SetFullHealth();
    if (getPowerType() == POWER_MANA)
        SetPower(POWER_MANA, GetMaxPower(POWER_MANA));

    if (getPowerType() == POWER_RUNIC_POWER)
    {
        SetPower(POWER_RUNES, 8);
        SetMaxPower(POWER_RUNES, 8);
        SetPower(POWER_RUNIC_POWER, 0);
        SetMaxPower(POWER_RUNIC_POWER, 1000);
    }

    // original spells
    LearnDefaultSkills();
    LearnCustomSpells();

    // Original action bar. Do not use Player::AddActionButton because we do not have skill spells loaded at this time
    // but checks will still be performed later when loading character from db in Player::_LoadActions
    for (PlayerCreateInfoActions::const_iterator action_itr = info->action.begin(); action_itr != info->action.end(); ++action_itr)
    {
        // create new button
        ActionButton& ab = m_actionButtons[action_itr->button];

        // set data
        ab.SetActionAndType(action_itr->action, ActionButtonType(action_itr->type));
    }

    // original items
    if (CharStartOutfitEntry const* oEntry = sDB2Manager.GetCharStartOutfitEntry(createInfo->Race, createInfo->Class, createInfo->Sex))
    {
        for (int j = 0; j < MAX_OUTFIT_ITEMS; ++j)
        {
            if (oEntry->ItemID[j] <= 0)
                continue;

            uint32 itemId = oEntry->ItemID[j];

            // just skip, reported in ObjectMgr::LoadItemTemplates
            ItemTemplate const* iProto = sObjectMgr->GetItemTemplate(itemId);
            if (!iProto)
                continue;

            // BuyCount by default
            uint32 count = iProto->GetBuyCount();

            // special amount for food/drink
            if (iProto->GetClass() == ITEM_CLASS_CONSUMABLE && iProto->GetSubClass() == ITEM_SUBCLASS_FOOD_DRINK)
            {
                if (iProto->Effects.size() >= 1)
                {
                    switch (iProto->Effects[0]->Category)
                    {
                        case SPELL_CATEGORY_FOOD:                                // food
                            count = getClass() == CLASS_DEATH_KNIGHT ? 10 : 4;
                            break;
                        case SPELL_CATEGORY_DRINK:                                // drink
                            count = 2;
                            break;
                    }
                }
                if (iProto->GetMaxStackSize() < count)
                    count = iProto->GetMaxStackSize();
            }
            StoreNewItemInBestSlots(itemId, count);
        }
    }

    for (PlayerCreateInfoItems::const_iterator item_id_itr = info->item.begin(); item_id_itr != info->item.end(); ++item_id_itr)
        StoreNewItemInBestSlots(item_id_itr->item_id, item_id_itr->item_amount);

    // bags and main-hand weapon must equipped at this moment
    // now second pass for not equipped (offhand weapon/shield if it attempt equipped before main-hand weapon)
    // or ammo not equipped in special bag
    for (uint8 i = INVENTORY_SLOT_ITEM_START; i < INVENTORY_SLOT_ITEM_END; i++)
    {
        if (Item* pItem = GetItemByPos(INVENTORY_SLOT_BAG_0, i))
        {
            uint16 eDest;
            // equip offhand weapon/shield if it attempt equipped before main-hand weapon
            InventoryResult msg = CanEquipItem(NULL_SLOT, eDest, pItem, false);
            if (msg == EQUIP_ERR_OK)
            {
                RemoveItem(INVENTORY_SLOT_BAG_0, i, true);
                EquipItem(eDest, pItem, true);
            }
            // move other items to more appropriate slots
            else
            {
                ItemPosCountVec sDest;
                msg = CanStoreItem(NULL_BAG, NULL_SLOT, sDest, pItem, false);
                if (msg == EQUIP_ERR_OK)
                {
                    RemoveItem(INVENTORY_SLOT_BAG_0, i, true);
                    StoreItem(sDest, pItem, true);
                }
            }
        }
    }
    // all item positions resolved

    return true;
}

bool Player::StoreNewItemInBestSlots(uint32 titem_id, uint32 titem_amount)
{
    TC_LOG_DEBUG("entities.player.items", "Player::StoreNewItemInBestSlots: Player '%s' (%s) creates initial item (ItemID: %u, Count: %u)",
        GetName().c_str(), GetGUID().ToString().c_str(), titem_id, titem_amount);

    // attempt equip by one
    while (titem_amount > 0)
    {
        uint16 eDest;
        InventoryResult msg = CanEquipNewItem(NULL_SLOT, eDest, titem_id, false);
        if (msg != EQUIP_ERR_OK)
            break;

        EquipNewItem(eDest, titem_id, true);
        AutoUnequipOffhandIfNeed();
        --titem_amount;
    }

    if (titem_amount == 0)
        return true;                                        // equipped

    // attempt store
    ItemPosCountVec sDest;
    // store in main bag to simplify second pass (special bags can be not equipped yet at this moment)
    InventoryResult msg = CanStoreNewItem(INVENTORY_SLOT_BAG_0, NULL_SLOT, sDest, titem_id, titem_amount);
    if (msg == EQUIP_ERR_OK)
    {
        StoreNewItem(sDest, titem_id, true, Item::GenerateItemRandomPropertyId(titem_id));
        return true;                                        // stored
    }

    // item can't be added
    TC_LOG_ERROR("entities.player.items", "Player::StoreNewItemInBestSlots: Player '%s' (%s) can't equip or store initial item (ItemID: %u, Race: %u, Class: %u, InventoryResult: %u)",
        GetName().c_str(), GetGUID().ToString().c_str(), titem_id, getRace(), getClass(), msg);
    return false;
}

void Player::SendMirrorTimer(MirrorTimerType Type, uint32 MaxValue, uint32 CurrentValue, int32 Regen)
{
    if (int(MaxValue) == DISABLED_MIRROR_TIMER)
    {
        if (int(CurrentValue) != DISABLED_MIRROR_TIMER)
            StopMirrorTimer(Type);
        return;
    }

    GetSession()->SendPacket(WorldPackets::Misc::StartMirrorTimer(Type, CurrentValue, MaxValue, Regen, 0, 0).Write());
}

void Player::StopMirrorTimer(MirrorTimerType Type)
{
    m_MirrorTimer[Type] = DISABLED_MIRROR_TIMER;
    GetSession()->SendPacket(WorldPackets::Misc::StopMirrorTimer(Type).Write());
}

bool Player::IsImmuneToEnvironmentalDamage() const
{
    // check for GM and death state included in isAttackableByAOE
    return !isTargetableForAttack(false);
}

uint32 Player::EnvironmentalDamage(EnviromentalDamage type, uint32 damage)
{
    if (IsImmuneToEnvironmentalDamage())
        return 0;

    // Absorb, resist some environmental damage type
    uint32 absorb = 0;
    uint32 resist = 0;
    if (type == DAMAGE_LAVA)
        CalcAbsorbResist(this, SPELL_SCHOOL_MASK_FIRE, DIRECT_DAMAGE, damage, &absorb, &resist);
    else if (type == DAMAGE_SLIME)
        CalcAbsorbResist(this, SPELL_SCHOOL_MASK_NATURE, DIRECT_DAMAGE, damage, &absorb, &resist);

    damage -= absorb + resist;

    DealDamageMods(this, damage, &absorb);

    WorldPackets::CombatLog::EnvironmentalDamageLog packet;
    packet.Victim = GetGUID();
    packet.Type = type != DAMAGE_FALL_TO_VOID ? type : DAMAGE_FALL;
    packet.Amount = damage;
    packet.Absorbed = absorb;
    packet.Resisted = resist;

    uint32 final_damage = DealDamage(this, damage, nullptr, SELF_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, nullptr, false);

    packet.LogData.Initialize(this);
    SendCombatLogMessage(&packet);

    if (!IsAlive())
    {
        if (type == DAMAGE_FALL)                               // DealDamage not apply item durability loss at self damage
        {
            TC_LOG_DEBUG("entities.player", "Player::EnvironmentalDamage: Player '%s' (%s) fall to death, loosing 10%% durability",
                GetName().c_str(), GetGUID().ToString().c_str());
            DurabilityLossAll(0.10f, false);
            // durability lost message
            SendDurabilityLoss(this, 10);
        }

        UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_DEATHS_FROM, 1, type);
    }

    return final_damage;
}

int32 Player::getMaxTimer(MirrorTimerType timer) const
{
    switch (timer)
    {
        case FATIGUE_TIMER:
            return MINUTE * IN_MILLISECONDS;
        case BREATH_TIMER:
        {
            if (!IsAlive() || HasAuraType(SPELL_AURA_WATER_BREATHING) || GetSession()->GetSecurity() >= AccountTypes(sWorld->getIntConfig(CONFIG_DISABLE_BREATHING)))
                return DISABLED_MIRROR_TIMER;
            int32 UnderWaterTime = 3 * MINUTE * IN_MILLISECONDS;
            AuraEffectList const& mModWaterBreathing = GetAuraEffectsByType(SPELL_AURA_MOD_WATER_BREATHING);
            for (AuraEffectList::const_iterator i = mModWaterBreathing.begin(); i != mModWaterBreathing.end(); ++i)
                AddPct(UnderWaterTime, (*i)->GetAmount());
            return UnderWaterTime;
        }
        case FIRE_TIMER:
        {
            if (!IsAlive())
                return DISABLED_MIRROR_TIMER;
            return 1 * IN_MILLISECONDS;
        }
        default:
            return 0;
    }
}

void Player::UpdateMirrorTimers()
{
    // Desync flags for update on next HandleDrowning
    if (m_MirrorTimerFlags)
        m_MirrorTimerFlagsLast = ~m_MirrorTimerFlags;
}

void Player::StopMirrorTimers()
{
    StopMirrorTimer(FATIGUE_TIMER);
    StopMirrorTimer(BREATH_TIMER);
    StopMirrorTimer(FIRE_TIMER);
}

bool Player::IsMirrorTimerActive(MirrorTimerType type) const
{
    return m_MirrorTimer[type] == getMaxTimer(type);
}

void Player::HandleDrowning(uint32 time_diff)
{
    if (!m_MirrorTimerFlags)
        return;

    // In water
    if (m_MirrorTimerFlags & UNDERWATER_INWATER)
    {
        // Breath timer not activated - activate it
        if (m_MirrorTimer[BREATH_TIMER] == DISABLED_MIRROR_TIMER)
        {
            m_MirrorTimer[BREATH_TIMER] = getMaxTimer(BREATH_TIMER);
            SendMirrorTimer(BREATH_TIMER, m_MirrorTimer[BREATH_TIMER], m_MirrorTimer[BREATH_TIMER], -1);
        }
        else                                                              // If activated - do tick
        {
            m_MirrorTimer[BREATH_TIMER]-=time_diff;
            // Timer limit - need deal damage
            if (m_MirrorTimer[BREATH_TIMER] < 0)
            {
                m_MirrorTimer[BREATH_TIMER]+= 1*IN_MILLISECONDS;
                // Calculate and deal damage
                /// @todo Check this formula
                uint32 damage = GetMaxHealth() / 5 + urand(0, getLevel()-1);
                EnvironmentalDamage(DAMAGE_DROWNING, damage);
            }
            else if (!(m_MirrorTimerFlagsLast & UNDERWATER_INWATER))      // Update time in client if need
                SendMirrorTimer(BREATH_TIMER, getMaxTimer(BREATH_TIMER), m_MirrorTimer[BREATH_TIMER], -1);
        }
    }
    else if (m_MirrorTimer[BREATH_TIMER] != DISABLED_MIRROR_TIMER)        // Regen timer
    {
        int32 UnderWaterTime = getMaxTimer(BREATH_TIMER);
        // Need breath regen
        m_MirrorTimer[BREATH_TIMER]+=10*time_diff;
        if (m_MirrorTimer[BREATH_TIMER] >= UnderWaterTime || !IsAlive())
            StopMirrorTimer(BREATH_TIMER);
        else if (m_MirrorTimerFlagsLast & UNDERWATER_INWATER)
            SendMirrorTimer(BREATH_TIMER, UnderWaterTime, m_MirrorTimer[BREATH_TIMER], 10);
    }

    // In dark water
    if (m_MirrorTimerFlags & UNDERWARER_INDARKWATER)
    {
        // Fatigue timer not activated - activate it
        if (m_MirrorTimer[FATIGUE_TIMER] == DISABLED_MIRROR_TIMER)
        {
            m_MirrorTimer[FATIGUE_TIMER] = getMaxTimer(FATIGUE_TIMER);
            SendMirrorTimer(FATIGUE_TIMER, m_MirrorTimer[FATIGUE_TIMER], m_MirrorTimer[FATIGUE_TIMER], -1);
        }
        else
        {
            m_MirrorTimer[FATIGUE_TIMER]-=time_diff;
            // Timer limit - need deal damage or teleport ghost to graveyard
            if (m_MirrorTimer[FATIGUE_TIMER] < 0)
            {
                m_MirrorTimer[FATIGUE_TIMER]+= 1*IN_MILLISECONDS;
                if (IsAlive())                                            // Calculate and deal damage
                {
                    uint32 damage = GetMaxHealth() / 5 + urand(0, getLevel()-1);
                    EnvironmentalDamage(DAMAGE_EXHAUSTED, damage);
                }
                else if (HasFlag(PLAYER_FLAGS, PLAYER_FLAGS_GHOST))       // Teleport ghost to graveyard
                    RepopAtGraveyard();
            }
            else if (!(m_MirrorTimerFlagsLast & UNDERWARER_INDARKWATER))
                SendMirrorTimer(FATIGUE_TIMER, getMaxTimer(FATIGUE_TIMER), m_MirrorTimer[FATIGUE_TIMER], -1);
        }
    }
    else if (m_MirrorTimer[FATIGUE_TIMER] != DISABLED_MIRROR_TIMER)       // Regen timer
    {
        int32 DarkWaterTime = getMaxTimer(FATIGUE_TIMER);
        m_MirrorTimer[FATIGUE_TIMER]+=10*time_diff;
        if (m_MirrorTimer[FATIGUE_TIMER] >= DarkWaterTime || !IsAlive())
            StopMirrorTimer(FATIGUE_TIMER);
        else if (m_MirrorTimerFlagsLast & UNDERWARER_INDARKWATER)
            SendMirrorTimer(FATIGUE_TIMER, DarkWaterTime, m_MirrorTimer[FATIGUE_TIMER], 10);
    }

    if (m_MirrorTimerFlags & (UNDERWATER_INLAVA /*| UNDERWATER_INSLIME*/) && !(_lastLiquid && _lastLiquid->SpellID))
    {
        // Breath timer not activated - activate it
        if (m_MirrorTimer[FIRE_TIMER] == DISABLED_MIRROR_TIMER)
            m_MirrorTimer[FIRE_TIMER] = getMaxTimer(FIRE_TIMER);
        else
        {
            m_MirrorTimer[FIRE_TIMER] -= time_diff;
            if (m_MirrorTimer[FIRE_TIMER] < 0)
            {
                m_MirrorTimer[FIRE_TIMER]+= 1*IN_MILLISECONDS;
                // Calculate and deal damage
                /// @todo Check this formula
                uint32 damage = urand(600, 700);
                if (m_MirrorTimerFlags & UNDERWATER_INLAVA)
                    EnvironmentalDamage(DAMAGE_LAVA, damage);
                // need to skip Slime damage in Undercity,
                // maybe someone can find better way to handle environmental damage
                //else if (m_zoneUpdateId != 1497)
                //    EnvironmentalDamage(DAMAGE_SLIME, damage);
            }
        }
    }
    else
        m_MirrorTimer[FIRE_TIMER] = DISABLED_MIRROR_TIMER;

    // Recheck timers flag
    m_MirrorTimerFlags&=~UNDERWATER_EXIST_TIMERS;
    for (uint8 i = 0; i< MAX_TIMERS; ++i)
        if (m_MirrorTimer[i] != DISABLED_MIRROR_TIMER)
        {
            m_MirrorTimerFlags|=UNDERWATER_EXIST_TIMERS;
            break;
        }
    m_MirrorTimerFlagsLast = m_MirrorTimerFlags;
}

///The player sobers by 1% every 9 seconds
void Player::HandleSobering()
{
    m_drunkTimer = 0;

    uint8 currentDrunkValue = GetDrunkValue();
    uint8 drunk = currentDrunkValue ? --currentDrunkValue : 0;
    SetDrunkValue(drunk);
}

DrunkenState Player::GetDrunkenstateByValue(uint8 value)
{
    if (value >= 90)
        return DRUNKEN_SMASHED;
    if (value >= 50)
        return DRUNKEN_DRUNK;
    if (value)
        return DRUNKEN_TIPSY;
    return DRUNKEN_SOBER;
}

void Player::SetDrunkValue(uint8 newDrunkValue, uint32 itemId /*= 0*/)
{
    bool isSobering = newDrunkValue < GetDrunkValue();
    uint32 oldDrunkenState = Player::GetDrunkenstateByValue(GetDrunkValue());
    if (newDrunkValue > 100)
        newDrunkValue = 100;

    // select drunk percent or total SPELL_AURA_MOD_FAKE_INEBRIATE amount, whichever is higher for visibility updates
    int32 drunkPercent = std::max<int32>(newDrunkValue, GetTotalAuraModifier(SPELL_AURA_MOD_FAKE_INEBRIATE));
    if (drunkPercent)
    {
        m_invisibilityDetect.AddFlag(INVISIBILITY_DRUNK);
        m_invisibilityDetect.SetValue(INVISIBILITY_DRUNK, drunkPercent);
    }
    else if (!HasAuraType(SPELL_AURA_MOD_FAKE_INEBRIATE) && !newDrunkValue)
        m_invisibilityDetect.DelFlag(INVISIBILITY_DRUNK);

    uint32 newDrunkenState = Player::GetDrunkenstateByValue(newDrunkValue);
    SetByteValue(PLAYER_BYTES_3, PLAYER_BYTES_3_OFFSET_INEBRIATION, newDrunkValue);
    UpdateObjectVisibility();

    if (!isSobering)
        m_drunkTimer = 0;   // reset sobering timer

    if (newDrunkenState == oldDrunkenState)
        return;

    WorldPackets::Misc::CrossedInebriationThreshold data;
    data.Guid = GetGUID();
    data.Threshold = newDrunkenState;
    data.ItemID = itemId;

    SendMessageToSet(data.Write(), true);
}

void Player::Update(uint32 p_time)
{
    if (!IsInWorld())
        return;

    // undelivered mail
    if (m_nextMailDelivereTime && m_nextMailDelivereTime <= time(nullptr))
    {
        SendNewMail();
        ++unReadMails;

        // It will be recalculate at mailbox open (for unReadMails important non-0 until mailbox open, it also will be recalculated)
        m_nextMailDelivereTime = 0;
    }

    // If this is set during update SetSpellModTakingSpell call is missing somewhere in the code
    // Having this would prevent more aura charges to be dropped, so let's crash
    //ASSERT (!m_spellModTakingSpell);
    if (m_spellModTakingSpell)
    {
        //TC_LOG_FATAL("entities.player", "Player has m_pad %u during update!", m_pad);
        //if (m_spellModTakingSpell)
        TC_LOG_FATAL("spells", "Player::Update: Player '%s' (%s) has m_spellModTakingSpell (SpellID: %u) during update!",
            GetName().c_str(), GetGUID().ToString().c_str(), m_spellModTakingSpell->m_spellInfo->Id);
        m_spellModTakingSpell = nullptr;
    }

    //used to implement delayed far teleport
    SetCanDelayTeleport(true);
    Unit::Update(p_time);
    SetCanDelayTeleport(false);

    time_t now = time(nullptr);

    UpdatePvPFlag(now);

    UpdateContestedPvP(p_time);

    UpdateDuelFlag(now);

    CheckDuelDistance(now);

    UpdateAfkReport(now);

    if (IsCharmed())
        if (Unit* charmer = GetCharmer())
            if (charmer->GetTypeId() == TYPEID_UNIT && charmer->IsAlive())
                UpdateCharmedAI();

    // Update items that have just a limited lifetime
    if (now > m_Last_tick)
        UpdateItemDuration(uint32(now - m_Last_tick));

    // check every second
    if (now > m_Last_tick + 1)
        UpdateSoulboundTradeItems();

    // If mute expired, remove it from the DB
    if (GetSession()->m_muteTime && GetSession()->m_muteTime < now)
    {
        GetSession()->m_muteTime = 0;
        PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_UPD_MUTE_TIME);
        stmt->setInt64(0, 0); // Set the mute time to 0
        stmt->setString(1, "");
        stmt->setString(2, "");
        stmt->setUInt32(3, GetSession()->GetAccountId());
        LoginDatabase.Execute(stmt);
    }

    if (!m_timedquests.empty())
    {
        QuestSet::iterator iter = m_timedquests.begin();
        while (iter != m_timedquests.end())
        {
            QuestStatusData& q_status = m_QuestStatus[*iter];
            if (q_status.Timer <= p_time)
            {
                uint32 quest_id  = *iter;
                ++iter;                                     // current iter will be removed in FailQuest
                FailQuest(quest_id);
            }
            else
            {
                q_status.Timer -= p_time;
                m_QuestStatusSave[*iter] = QUEST_DEFAULT_SAVE_TYPE;
                ++iter;
            }
        }
    }

    m_achievementMgr->UpdateTimedAchievements(p_time);

    if (HasUnitState(UNIT_STATE_MELEE_ATTACKING) && !HasUnitState(UNIT_STATE_CASTING))
    {
        if (Unit* victim = GetVictim())
        {
            // default combat reach 10
            /// @todo add weapon, skill check

            if (isAttackReady(BASE_ATTACK))
            {
                if (!IsWithinMeleeRange(victim))
                {
                    setAttackTimer(BASE_ATTACK, 100);
                    if (m_swingErrorMsg != 1)               // send single time (client auto repeat)
                    {
                        SendAttackSwingNotInRange();
                        m_swingErrorMsg = 1;
                    }
                }
                //120 degrees of radiant range
                else if (!HasInArc(2 * float(M_PI) / 3, victim))
                {
                    setAttackTimer(BASE_ATTACK, 100);
                    if (m_swingErrorMsg != 2)               // send single time (client auto repeat)
                    {
                        SendAttackSwingBadFacingAttack();
                        m_swingErrorMsg = 2;
                    }
                }
                else
                {
                    m_swingErrorMsg = 0;                    // reset swing error state

                    // prevent base and off attack in same time, delay attack at 0.2 sec
                    if (haveOffhandWeapon())
                        if (getAttackTimer(OFF_ATTACK) < ATTACK_DISPLAY_DELAY)
                            setAttackTimer(OFF_ATTACK, ATTACK_DISPLAY_DELAY);

                    // do attack
                    AttackerStateUpdate(victim, BASE_ATTACK);
                    resetAttackTimer(BASE_ATTACK);
                }
            }

            if (haveOffhandWeapon() && isAttackReady(OFF_ATTACK))
            {
                if (!IsWithinMeleeRange(victim))
                    setAttackTimer(OFF_ATTACK, 100);
                else if (!HasInArc(2 * float(M_PI) / 3, victim))
                    setAttackTimer(OFF_ATTACK, 100);
                else
                {
                    // prevent base and off attack in same time, delay attack at 0.2 sec
                    if (getAttackTimer(BASE_ATTACK) < ATTACK_DISPLAY_DELAY)
                        setAttackTimer(BASE_ATTACK, ATTACK_DISPLAY_DELAY);

                    // do attack
                    AttackerStateUpdate(victim, OFF_ATTACK);
                    resetAttackTimer(OFF_ATTACK);
                }
            }

            /*Unit* owner = victim->GetOwner();
            Unit* u = owner ? owner : victim;
            if (u->IsPvP() && (!duel || duel->opponent != u))
            {
                UpdatePvP(true);
                RemoveAurasWithInterruptFlags(AURA_INTERRUPT_FLAG_ENTER_PVP_COMBAT);
            }*/
        }
    }

    if (HasFlag(PLAYER_FLAGS, PLAYER_FLAGS_RESTING))
    {
        if (roll_chance_i(3) && _restTime > 0)      // freeze update
        {
            time_t currTime = time(nullptr);
            time_t timeDiff = currTime - _restTime;
            if (timeDiff >= 10)                               // freeze update
            {
                _restTime = currTime;

                float bubble = 0.125f * sWorld->getRate(RATE_REST_INGAME);
                float extraPerSec = ((float)GetUInt32Value(PLAYER_NEXT_LEVEL_XP) / 72000.0f) * bubble;

                // speed collect rest bonus (section/in hour)
                float currRestBonus = GetRestBonus();
                SetRestBonus(currRestBonus + timeDiff * extraPerSec);
            }
        }
    }

    if (m_weaponChangeTimer > 0)
    {
        if (p_time >= m_weaponChangeTimer)
            m_weaponChangeTimer = 0;
        else
            m_weaponChangeTimer -= p_time;
    }

    if (m_zoneUpdateTimer > 0)
    {
        if (p_time >= m_zoneUpdateTimer)
        {
            // On zone update tick check if we are still in an inn if we are supposed to be in one
            if (HasRestFlag(REST_FLAG_IN_TAVERN))
            {
                AreaTriggerEntry const* atEntry = sAreaTriggerStore.LookupEntry(GetInnTriggerId());
                if (!atEntry || !IsInAreaTriggerRadius(atEntry))
                    RemoveRestFlag(REST_FLAG_IN_TAVERN);
            }

            uint32 newzone, newarea;
            GetZoneAndAreaId(newzone, newarea);

            if (m_zoneUpdateId != newzone)
                UpdateZone(newzone, newarea);                // also update area
            else
            {
                // use area updates as well
                // needed for free far all arenas for example
                if (m_areaUpdateId != newarea)
                    UpdateArea(newarea);

                m_zoneUpdateTimer = ZONE_UPDATE_INTERVAL;
            }
        }
        else
            m_zoneUpdateTimer -= p_time;
    }

    if (m_timeSyncTimer > 0)
    {
        if (p_time >= m_timeSyncTimer)
            SendTimeSync();
        else
            m_timeSyncTimer -= p_time;
    }

    if (IsAlive())
    {
        m_regenTimer += p_time;
        RegenerateAll();
    }

    if (m_deathState == JUST_DIED)
        KillPlayer();

    if (m_nextSave > 0)
    {
        if (p_time >= m_nextSave)
        {
            // m_nextSave reset in SaveToDB call
            SaveToDB();
            TC_LOG_DEBUG("entities.player", "Player::Update: Player '%s' (%s) saved", GetName().c_str(), GetGUID().ToString().c_str());
        }
        else
            m_nextSave -= p_time;
    }

    //Handle Water/drowning
    HandleDrowning(p_time);

    // Played time
    if (now > m_Last_tick)
    {
        uint32 elapsed = uint32(now - m_Last_tick);
        m_Played_time[PLAYED_TIME_TOTAL] += elapsed;        // Total played time
        m_Played_time[PLAYED_TIME_LEVEL] += elapsed;        // Level played time
        m_Last_tick = now;
    }

    if (GetDrunkValue())
    {
        m_drunkTimer += p_time;
        if (m_drunkTimer > 9 * IN_MILLISECONDS)
            HandleSobering();
    }

    if (HasPendingBind())
    {
        if (_pendingBindTimer <= p_time)
        {
            // Player left the instance
            if (_pendingBindId == GetInstanceId())
                BindToInstance();
            SetPendingBind(0, 0);
        }
        else
            _pendingBindTimer -= p_time;
    }

    // not auto-free ghost from body in instances
    if (m_deathTimer > 0 && !GetBaseMap()->Instanceable() && !HasAuraType(SPELL_AURA_PREVENT_RESURRECTION))
    {
        if (p_time >= m_deathTimer)
        {
            m_deathTimer = 0;
            BuildPlayerRepop();
            RepopAtGraveyard();
        }
        else
            m_deathTimer -= p_time;
    }

    UpdateEnchantTime(p_time);
    UpdateHomebindTime(p_time);

    if (!_instanceResetTimes.empty())
    {
        for (InstanceTimeMap::iterator itr = _instanceResetTimes.begin(); itr != _instanceResetTimes.end();)
        {
            if (itr->second < now)
                _instanceResetTimes.erase(itr++);
            else
                ++itr;
        }
    }

    if (getClass() == CLASS_DEATH_KNIGHT)
    {
        // Update rune timers
        for (uint8 i = 0; i < MAX_RUNES; ++i)
        {
            uint32 timer = GetRuneTimer(i);

            // Don't update timer if rune is disabled
            if (GetRuneCooldown(i))
                continue;

            // Timer has began
            if (timer < 0xFFFFFFFF)
            {
                timer += p_time;
                SetRuneTimer(i, std::min(uint32(2500), timer));
            }
        }
    }

    // group update
    SendUpdateToOutOfRangeGroupMembers();

    Pet* pet = GetPet();
    if (pet && !pet->IsWithinDistInMap(this, GetMap()->GetVisibilityRange()) && !pet->isPossessed())
    //if (pet && !pet->IsWithinDistInMap(this, GetMap()->GetVisibilityDistance()) && (GetCharmGUID() && (pet->GetGUID() != GetCharmGUID())))
        RemovePet(pet, PET_SAVE_NOT_IN_SLOT, true);

    //we should execute delayed teleports only for alive(!) players
    //because we don't want player's ghost teleported from graveyard
    if (IsHasDelayedTeleport() && IsAlive())
        TeleportTo(m_teleport_dest, m_teleport_options);

}

void Player::setDeathState(DeathState s)
{
    uint32 ressSpellId = 0;

    bool cur = IsAlive();

    if (s == JUST_DIED)
    {
        if (!cur)
        {
            TC_LOG_ERROR("entities.player", "Player::setDeathState: Attempt to kill a dead player '%s' (%s)", GetName().c_str(), GetGUID().ToString().c_str());
            return;
        }

        // drunken state is cleared on death
        SetDrunkValue(0);
        // lost combo points at any target (targeted combo points clear in Unit::setDeathState)
        ClearComboPoints();

        ClearResurrectRequestData();

        //FIXME: is pet dismissed at dying or releasing spirit? if second, add setDeathState(DEAD) to HandleRepopRequestOpcode and define pet unsummon here with (s == DEAD)
        RemovePet(nullptr, PET_SAVE_NOT_IN_SLOT, true);

        // save value before aura remove in Unit::setDeathState
        ressSpellId = GetUInt32Value(PLAYER_SELF_RES_SPELL);

        // passive spell
        if (!ressSpellId)
            ressSpellId = GetResurrectionSpellId();
        UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_DEATH_AT_MAP, 1);
        UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_DEATH, 1);
        UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_DEATH_IN_DUNGEON, 1);
        ResetAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_BG_OBJECTIVE_CAPTURE, ACHIEVEMENT_CRITERIA_CONDITION_NO_DEATH);
        ResetAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_HONORABLE_KILL, ACHIEVEMENT_CRITERIA_CONDITION_NO_DEATH);
        ResetAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_GET_KILLING_BLOWS, ACHIEVEMENT_CRITERIA_CONDITION_NO_DEATH);
    }

    Unit::setDeathState(s);

    // restore resurrection spell id for player after aura remove
    if (s == JUST_DIED && cur && ressSpellId)
        SetUInt32Value(PLAYER_SELF_RES_SPELL, ressSpellId);

    if (IsAlive() && !cur)
        //clear aura case after resurrection by another way (spells will be applied before next death)
        SetUInt32Value(PLAYER_SELF_RES_SPELL, 0);
}

void Player::ToggleAFK()
{
    ToggleFlag(PLAYER_FLAGS, PLAYER_FLAGS_AFK);

    // afk player not allowed in battleground
    if (isAFK() && InBattleground() && !InArena())
        LeaveBattleground();
}

void Player::ToggleDND()
{
    ToggleFlag(PLAYER_FLAGS, PLAYER_FLAGS_DND);
}

uint8 Player::GetChatFlags() const
{
    uint8 tag = CHAT_FLAG_NONE;

    if (isGMChat())
        tag |= CHAT_FLAG_GM;
    if (isDND())
        tag |= CHAT_FLAG_DND;
    if (isAFK())
        tag |= CHAT_FLAG_AFK;
    if (HasFlag(PLAYER_FLAGS, PLAYER_FLAGS_DEVELOPER))
        tag |= CHAT_FLAG_DEV;

    return tag;
}

bool Player::TeleportTo(uint32 mapid, float x, float y, float z, float orientation, uint32 options)
{
    if (!MapManager::IsValidMapCoord(mapid, x, y, z, orientation))
    {
        TC_LOG_ERROR("maps", "Player::TeleportTo: Invalid map (%d) or invalid coordinates (X: %f, Y: %f, Z: %f, O: %f) given when teleporting player '%s' (%s, MapID: %d, X: %f, Y: %f, Z: %f, O: %f).",
            mapid, x, y, z, orientation, GetGUID().ToString().c_str(), GetName().c_str(), GetMapId(), GetPositionX(), GetPositionY(), GetPositionZ(), GetOrientation());
        return false;
    }

    if (!GetSession()->HasPermission(rbac::RBAC_PERM_SKIP_CHECK_DISABLE_MAP) && DisableMgr::IsDisabledFor(DISABLE_TYPE_MAP, mapid, this))
    {
        TC_LOG_ERROR("maps", "Player::TeleportTo: Player '%s' (%s) tried to enter a forbidden map (MapID: %u)", GetGUID().ToString().c_str(), GetName().c_str(), mapid);
        SendTransferAborted(mapid, TRANSFER_ABORT_MAP_NOT_ALLOWED);
        return false;
    }

    // preparing unsummon pet if lost (we must get pet before teleportation or will not find it later)
    Pet* pet = GetPet();

    MapEntry const* mEntry = sMapStore.LookupEntry(mapid);

    // don't let enter battlegrounds without assigned battleground id (for example through areatrigger)...
    // don't let gm level > 1 either
    if (!InBattleground() && mEntry->IsBattlegroundOrArena())
        return false;

    // client without expansion support
    if (GetSession()->GetExpansion() < mEntry->Expansion())
    {
        TC_LOG_DEBUG("maps", "Player '%s' (%s) using client without required expansion tried teleport to non accessible map (MapID: %u)",
            GetName().c_str(), GetGUID().ToString().c_str(), mapid);

        if (Transport* transport = GetTransport())
        {
            transport->RemovePassenger(this);
            RepopAtGraveyard();                             // teleport to near graveyard if on transport, looks blizz like :)
        }

        SendTransferAborted(mapid, TRANSFER_ABORT_INSUF_EXPAN_LVL, mEntry->Expansion());

        return false;                                       // normal client can't teleport to this map...
    }
    else
        TC_LOG_DEBUG("maps", "Player %s (%s) is being teleported to map (MapID: %u)", GetName().c_str(), GetGUID().ToString().c_str(), mapid);

    if (m_vehicle)
        ExitVehicle();

    // reset movement flags at teleport, because player will continue move with these flags after teleport
    SetUnitMovementFlags(GetUnitMovementFlags() & MOVEMENTFLAG_MASK_HAS_PLAYER_STATUS_OPCODE);
    m_movementInfo.ResetJump();
    DisableSpline();

    if (Transport* transport = GetTransport())
    {
        if (!(options & TELE_TO_NOT_LEAVE_TRANSPORT))
            transport->RemovePassenger(this);
    }

    // The player was ported to another map and loses the duel immediately.
    // We have to perform this check before the teleport, otherwise the
    // ObjectAccessor won't find the flag.
    if (duel && GetMapId() != mapid && GetMap()->GetGameObject(GetGuidValue(PLAYER_DUEL_ARBITER)))
        DuelComplete(DUEL_FLED);

    if (GetMapId() == mapid)
    {
        //lets reset far teleport flag if it wasn't reset during chained teleport
        SetSemaphoreTeleportFar(false);
        //setup delayed teleport flag
        SetDelayedTeleportFlag(IsCanDelayTeleport());
        //if teleport spell is cast in Unit::Update() func
        //then we need to delay it until update process will be finished
        if (IsHasDelayedTeleport())
        {
            SetSemaphoreTeleportNear(true);
            //lets save teleport destination for player
            m_teleport_dest = WorldLocation(mapid, x, y, z, orientation);
            m_teleport_options = options;
            return true;
        }

        if (!(options & TELE_TO_NOT_UNSUMMON_PET))
        {
            //same map, only remove pet if out of range for new position
            if (pet && !pet->IsWithinDist3d(x, y, z, GetMap()->GetVisibilityRange()))
                UnsummonPetTemporaryIfAny();
        }

        if (!(options & TELE_TO_NOT_LEAVE_COMBAT))
            CombatStop();

        // this will be used instead of the current location in SaveToDB
        m_teleport_dest = WorldLocation(mapid, x, y, z, orientation);
        m_teleport_options = options;
        SetFallInformation(0, z);

        // code for finish transfer called in WorldSession::HandleMovementOpcodes()
        // at client packet CMSG_MOVE_TELEPORT_ACK
        SetSemaphoreTeleportNear(true);
        // near teleport, triggering send CMSG_MOVE_TELEPORT_ACK from client at landing
        if (!GetSession()->PlayerLogout())
            SendTeleportPacket(m_teleport_dest);
    }
    else
    {
        if (getClass() == CLASS_DEATH_KNIGHT && GetMapId() == 609 && !IsGameMaster() && !HasSpell(50977))
            return false;

        // far teleport to another map
        Map* oldmap = IsInWorld() ? GetMap() : NULL;
        // check if we can enter before stopping combat / removing pet / totems / interrupting spells

        // Check enter rights before map getting to avoid creating instance copy for player
        // this check not dependent from map instance copy and same for all instance copies of selected map
        if (sMapMgr->PlayerCannotEnter(mapid, this, false))
            return false;

        // Seamless teleport can happen only if cosmetic maps match
        if (!oldmap ||
            (oldmap->GetEntry()->CosmeticParentMapID != int32(mapid) && int32(GetMapId()) != mEntry->CosmeticParentMapID &&
            !((oldmap->GetEntry()->CosmeticParentMapID != -1) ^ (oldmap->GetEntry()->CosmeticParentMapID != mEntry->CosmeticParentMapID))))
            options &= ~TELE_TO_SEAMLESS;

        //I think this always returns true. Correct me if I am wrong.
        // If the map is not created, assume it is possible to enter it.
        // It will be created in the WorldPortAck.
        //Map* map = sMapMgr->FindBaseNonInstanceMap(mapid);
        //if (!map || map->CanEnter(this))
        {
            //lets reset near teleport flag if it wasn't reset during chained teleports
            SetSemaphoreTeleportNear(false);
            //setup delayed teleport flag
            SetDelayedTeleportFlag(IsCanDelayTeleport());
            //if teleport spell is cast in Unit::Update() func
            //then we need to delay it until update process will be finished
            if (IsHasDelayedTeleport())
            {
                SetSemaphoreTeleportFar(true);
                //lets save teleport destination for player
                m_teleport_dest = WorldLocation(mapid, x, y, z, orientation);
                m_teleport_options = options;
                return true;
            }

            SetSelection(ObjectGuid::Empty);

            CombatStop();

            ResetContestedPvP();

            // remove player from battleground on far teleport (when changing maps)
            if (Battleground const* bg = GetBattleground())
            {
                // Note: at battleground join battleground id set before teleport
                // and we already will found "current" battleground
                // just need check that this is targeted map or leave
                if (bg->GetMapId() != mapid)
                    LeaveBattleground(false);                   // don't teleport to entry point
            }

            // remove arena spell coldowns/buffs now to also remove pet's cooldowns before it's temporarily unsummoned
            if (mEntry->IsBattleArena())
            {
                RemoveArenaSpellCooldowns(true);
                RemoveArenaAuras();
                if (pet)
                    pet->RemoveArenaAuras();
            }

            // remove pet on map change
            if (pet)
                UnsummonPetTemporaryIfAny();

            // remove all dyn objects
            RemoveAllDynObjects();

            // stop spellcasting
            // not attempt interrupt teleportation spell at caster teleport
            if (!(options & TELE_TO_SPELL))
                if (IsNonMeleeSpellCast(true))
                    InterruptNonMeleeSpells(true);

            //remove auras before removing from map...
            RemoveAurasWithInterruptFlags(AURA_INTERRUPT_FLAG_CHANGE_MAP | AURA_INTERRUPT_FLAG_MOVE | AURA_INTERRUPT_FLAG_TURNING);

            if (!GetSession()->PlayerLogout() && !(options & TELE_TO_SEAMLESS))
            {
                // send transfer packets
                WorldPackets::Movement::TransferPending transferPending;
                transferPending.MapID = mapid;
                if (Transport* transport = GetTransport())
                {
                    transferPending.Ship = boost::in_place();
                    transferPending.Ship->ID = transport->GetEntry();
                    transferPending.Ship->OriginMapID = GetMapId();
                }

                GetSession()->SendPacket(transferPending.Write());
            }

            // remove from old map now
            if (oldmap)
                oldmap->RemovePlayerFromMap(this, false);

            m_teleport_dest = WorldLocation(mapid, x, y, z, orientation);
            m_teleport_options = options;
            SetFallInformation(0, z);
            // if the player is saved before worldportack (at logout for example)
            // this will be used instead of the current location in SaveToDB

            if (!GetSession()->PlayerLogout())
            {
                if (mEntry->IsDungeon())
                {
                    WorldPackets::Instance::UpdateLastInstance updateLastInstance;
                    updateLastInstance.MapID = mapid;
                    SendDirectMessage(updateLastInstance.Write());
                }

                WorldPackets::Movement::NewWorld packet;
                packet.MapID = mapid;
                packet.Pos = static_cast<Position>(m_teleport_dest);
                packet.Reason = !(options & TELE_TO_SEAMLESS) ? NEW_WORLD_NORMAL : NEW_WORLD_SEAMLESS;
                SendDirectMessage(packet.Write());
            }

            // move packet sent by client always after far teleport
            // code for finish transfer to new map called in WorldSession::HandleMoveWorldportAckOpcode at client packet
            SetSemaphoreTeleportFar(true);
        }
        //else
        //    return false;
    }
    return true;
}

bool Player::TeleportTo(WorldLocation const &loc, uint32 options /*= 0*/)
{
    return TeleportTo(loc.GetMapId(), loc.GetPositionX(), loc.GetPositionY(), loc.GetPositionZ(), loc.GetOrientation(), options);
}

bool Player::TeleportToBGEntryPoint()
{
    if (m_bgData.joinPos.m_mapId == MAPID_INVALID)
        return false;

    ScheduleDelayedOperation(DELAYED_BG_MOUNT_RESTORE);
    ScheduleDelayedOperation(DELAYED_BG_TAXI_RESTORE);
    ScheduleDelayedOperation(DELAYED_BG_GROUP_RESTORE);
    return TeleportTo(m_bgData.joinPos);
}

void Player::ProcessDelayedOperations()
{
    if (m_DelayedOperations == 0)
        return;

    if (m_DelayedOperations & DELAYED_RESURRECT_PLAYER)
        ResurrectUsingRequestDataImpl();

    if (m_DelayedOperations & DELAYED_SAVE_PLAYER)
        SaveToDB();

    if (m_DelayedOperations & DELAYED_SPELL_CAST_DESERTER)
        CastSpell(this, 26013, true);               // Deserter

    if (m_DelayedOperations & DELAYED_BG_MOUNT_RESTORE)
    {
        if (m_bgData.mountSpell)
        {
            CastSpell(this, m_bgData.mountSpell, true);
            m_bgData.mountSpell = 0;
        }
    }

    if (m_DelayedOperations & DELAYED_BG_TAXI_RESTORE)
    {
        if (m_bgData.HasTaxiPath())
        {
            m_taxi.AddTaxiDestination(m_bgData.taxiPath[0]);
            m_taxi.AddTaxiDestination(m_bgData.taxiPath[1]);
            m_bgData.ClearTaxiPath();

            ContinueTaxiFlight();
        }
    }

    if (m_DelayedOperations & DELAYED_BG_GROUP_RESTORE)
    {
        if (Group* g = GetGroup())
            g->SendUpdateToPlayer(GetGUID());
    }

    //we have executed ALL delayed ops, so clear the flag
    m_DelayedOperations = 0;
}

void Player::AddToWorld()
{
    ///- Do not add/remove the player from the object storage
    ///- It will crash when updating the ObjectAccessor
    ///- The player should only be added when logging in
    Unit::AddToWorld();

    for (uint8 i = PLAYER_SLOT_START; i < PLAYER_SLOT_END; ++i)
        if (m_items[i])
            m_items[i]->AddToWorld();
}

void Player::RemoveFromWorld()
{
    // cleanup
    if (IsInWorld())
    {
        ///- Release charmed creatures, unsummon totems and remove pets/guardians
        StopCastingCharm();
        StopCastingBindSight();
        UnsummonPetTemporaryIfAny();
        sOutdoorPvPMgr->HandlePlayerLeaveZone(this, m_zoneUpdateId);
        sBattlefieldMgr->HandlePlayerLeaveZone(this, m_zoneUpdateId);
    }

    // Remove items from world before self - player must be found in Item::RemoveFromObjectUpdate
    for (uint8 i = PLAYER_SLOT_START; i < PLAYER_SLOT_END; ++i)
        if (m_items[i])
            m_items[i]->RemoveFromWorld();

    ///- Do not add/remove the player from the object storage
    ///- It will crash when updating the ObjectAccessor
    ///- The player should only be removed when logging out
    Unit::RemoveFromWorld();

    for (ItemMap::iterator iter = mMitems.begin(); iter != mMitems.end(); ++iter)
        iter->second->RemoveFromWorld();

    if (m_uint32Values)
    {
        if (WorldObject* viewpoint = GetViewpoint())
        {
            TC_LOG_ERROR("entities.player", "Player::RemoveFromWorld: Player '%s' (%s) has viewpoint (Entry:%u, Type: %u) when removed from world",
                GetName().c_str(), GetGUID().ToString().c_str(), viewpoint->GetEntry(), viewpoint->GetTypeId());
            SetViewpoint(viewpoint, false);
        }
    }
}

bool Player::IsImmunedToSpellEffect(SpellInfo const* spellInfo, uint32 index) const
{
    SpellEffectInfo const* effect = spellInfo->GetEffect(GetMap()->GetDifficultyID(), index);
    if (!effect || !effect->IsEffect())
        return false;

    // players are immune to taunt (the aura and the spell effect).
    if (spellInfo->GetEffect(index)->IsAura(SPELL_AURA_MOD_TAUNT))
        return true;
    if (spellInfo->GetEffect(index)->IsEffect(SPELL_EFFECT_ATTACK_ME))
        return true;

    return Unit::IsImmunedToSpellEffect(spellInfo, index);
}

void Player::RegenerateAll()
{
    //if (m_regenTimer <= 500)
    //    return;

    m_regenTimerCount += m_regenTimer;

    if (getClass() == CLASS_PALADIN)
        m_holyPowerRegenTimerCount += m_regenTimer;

    if (getClass() == CLASS_HUNTER)
        m_focusRegenTimerCount += m_regenTimer;

    Regenerate(POWER_ENERGY);
    Regenerate(POWER_MANA);

    // Runes act as cooldowns, and they don't need to send any data
    if (getClass() == CLASS_DEATH_KNIGHT)
    {
        for (uint8 i = 0; i < MAX_RUNES; i += 2)
        {
            uint8 runeToRegen = i;
            uint32 cd = GetRuneCooldown(i);
            uint32 secondRuneCd = GetRuneCooldown(i + 1);
            // Regenerate second rune of the same type only after first rune is off the cooldown
            if (secondRuneCd && (cd > secondRuneCd || !cd))
            {
                runeToRegen = i + 1;
                cd = secondRuneCd;
            }

            if (cd)
                SetRuneCooldown(runeToRegen, (cd > m_regenTimer) ? cd - m_regenTimer : 0);
        }
    }

    if (m_focusRegenTimerCount >= 1000 && getClass() == CLASS_HUNTER)
    {
        Regenerate(POWER_FOCUS);
        m_focusRegenTimerCount -= 1000;
    }

    if (m_regenTimerCount >= 2000)
    {
        // Not in combat or they have regeneration
        if (!IsInCombat() || IsPolymorphed() || m_baseHealthRegen ||
            HasAuraType(SPELL_AURA_MOD_REGEN_DURING_COMBAT) ||
            HasAuraType(SPELL_AURA_MOD_HEALTH_REGEN_IN_COMBAT))
        {
            RegenerateHealth();
        }

        Regenerate(POWER_RAGE);
        if (getClass() == CLASS_DEATH_KNIGHT)
            Regenerate(POWER_RUNIC_POWER);

        m_regenTimerCount -= 2000;
    }

    if (m_holyPowerRegenTimerCount >= 10000 && getClass() == CLASS_PALADIN)
    {
        Regenerate(POWER_HOLY_POWER);
        m_holyPowerRegenTimerCount -= 10000;
    }

    m_regenTimer = 0;
}

void Player::Regenerate(Powers power)
{
    uint32 maxValue = GetMaxPower(power);
    if (!maxValue)
        return;

    uint32 curValue = GetPower(power);

    /// @todo possible use of miscvalueb instead of amount
    if (HasAuraTypeWithValue(SPELL_AURA_PREVENT_REGENERATE_POWER, power))
        return;

    // Skip regeneration for power type we cannot have
    uint32 powerIndex = GetPowerIndex(power);
    if (powerIndex == MAX_POWERS || powerIndex >= MAX_POWERS_PER_CLASS)
        return;

    float addvalue = 0.0f;

    // Powers now benefit from haste.
    float rangedHaste = GetFloatValue(UNIT_FIELD_MOD_RANGED_HASTE);
    float meleeHaste = GetFloatValue(UNIT_FIELD_MOD_HASTE);
    float spellHaste = GetFloatValue(UNIT_MOD_CAST_SPEED);

    switch (power)
    {
        case POWER_MANA:
        {
            float ManaIncreaseRate = sWorld->getRate(RATE_POWER_MANA);

            if (IsInCombat()) // Trinity Updates Mana in intervals of 2s, which is correct
                addvalue += GetFloatValue(UNIT_FIELD_POWER_REGEN_INTERRUPTED_FLAT_MODIFIER) *  ManaIncreaseRate * ((0.001f * m_regenTimer) + CalculatePct(0.001f, spellHaste));
            else
                addvalue += GetFloatValue(UNIT_FIELD_POWER_REGEN_FLAT_MODIFIER) *  ManaIncreaseRate * ((0.001f * m_regenTimer) + CalculatePct(0.001f, spellHaste));
        }
        break;
        case POWER_RAGE:                                                // Regenerate rage
        {
            if (!IsInCombat() && !HasAuraType(SPELL_AURA_INTERRUPT_REGEN))
            {
                float RageDecreaseRate = sWorld->getRate(RATE_POWER_RAGE_LOSS);
                addvalue += -25 * RageDecreaseRate / meleeHaste;                // 2.5 rage by tick (= 2 seconds => 1.25 rage/sec)
            }
        }
        break;
        case POWER_FOCUS:
            addvalue += (6.0f + CalculatePct(6.0f, rangedHaste)) * sWorld->getRate(RATE_POWER_FOCUS);
            break;
        case POWER_ENERGY:                                              // Regenerate energy (rogue)
            addvalue += ((0.01f * m_regenTimer) + CalculatePct(0.01f, meleeHaste)) * sWorld->getRate(RATE_POWER_ENERGY);
            break;
        case POWER_RUNIC_POWER:
        {
            if (!IsInCombat() && !HasAuraType(SPELL_AURA_INTERRUPT_REGEN))
            {
                float RunicPowerDecreaseRate = sWorld->getRate(RATE_POWER_RUNICPOWER_LOSS);
                addvalue += -30 * RunicPowerDecreaseRate;         // 3 RunicPower by tick
            }
        }
        break;
        case POWER_HOLY_POWER:                                          // Regenerate holy power
        {
            if (!IsInCombat())
                addvalue += -1.0f;      // remove 1 every 10 sec, first one removed 20s after leaving combat
        }
        break;
        case POWER_RUNES:
            break;
        case POWER_HEALTH:
            return;
        default:
            break;
    }

    // Mana regen calculated in Player::UpdateManaRegen()
    if (power != POWER_MANA)
    {
        AuraEffectList const& ModPowerRegenPCTAuras = GetAuraEffectsByType(SPELL_AURA_MOD_POWER_REGEN_PERCENT);
        for (AuraEffectList::const_iterator i = ModPowerRegenPCTAuras.begin(); i != ModPowerRegenPCTAuras.end(); ++i)
            if (Powers((*i)->GetMiscValue()) == power)
                AddPct(addvalue, (*i)->GetAmount());

        // Butchery requires combat for this effect
        if (power != POWER_RUNIC_POWER || IsInCombat())
            addvalue += GetTotalAuraModifierByMiscValue(SPELL_AURA_MOD_POWER_REGEN, power) * ((power != POWER_ENERGY) ? m_regenTimerCount : m_regenTimer) / (5 * IN_MILLISECONDS);
    }

    if (addvalue < 0.0f)
    {
        if (curValue == 0)
            return;
    }
    else if (addvalue > 0.0f)
    {
        if (curValue == maxValue)
            return;
    }
    else
        return;

    addvalue += m_powerFraction[powerIndex];
    uint32 integerValue = uint32(std::fabs(addvalue));

    if (addvalue < 0.0f)
    {
        if (curValue > integerValue)
        {
            curValue -= integerValue;
            m_powerFraction[powerIndex] = addvalue + integerValue;
        }
        else
        {
            curValue = 0;
            m_powerFraction[powerIndex] = 0;
        }
    }
    else
    {
        curValue += integerValue;

        if (curValue > maxValue)
        {
            curValue = maxValue;
            m_powerFraction[powerIndex] = 0;
        }
        else
            m_powerFraction[powerIndex] = addvalue - integerValue;
    }

    if (m_regenTimerCount >= 2000)
        SetPower(power, curValue);
    else
        UpdateUInt32Value(UNIT_FIELD_POWER + powerIndex, curValue);
}

void Player::RegenerateHealth()
{
    uint32 curValue = GetHealth();
    uint32 maxValue = GetMaxHealth();

    if (curValue >= maxValue)
        return;

    float HealthIncreaseRate = sWorld->getRate(RATE_HEALTH);
    float addValue = 0.0f;

    // polymorphed case
    if (IsPolymorphed())
        addValue = float(GetMaxHealth()) / 3.0f;
    // normal regen case (maybe partly in combat case)
    else if (!IsInCombat() || HasAuraType(SPELL_AURA_MOD_REGEN_DURING_COMBAT))
    {
        addValue = HealthIncreaseRate;

        if (!IsInCombat())
        {
            if (getLevel() < 15)
                addValue = (0.20f * ((float)GetMaxHealth()) / getLevel() * HealthIncreaseRate);
            else
                addValue = 0.015f * ((float)GetMaxHealth()) * HealthIncreaseRate;

            AuraEffectList const& mModHealthRegenPct = GetAuraEffectsByType(SPELL_AURA_MOD_HEALTH_REGEN_PERCENT);
            for (AuraEffectList::const_iterator i = mModHealthRegenPct.begin(); i != mModHealthRegenPct.end(); ++i)
                AddPct(addValue, (*i)->GetAmount());

            addValue += GetTotalAuraModifier(SPELL_AURA_MOD_REGEN) * 0.4f;
        }
        else if (HasAuraType(SPELL_AURA_MOD_REGEN_DURING_COMBAT))
            ApplyPct(addValue, GetTotalAuraModifier(SPELL_AURA_MOD_REGEN_DURING_COMBAT));

        if (!IsStandState())
            addValue *= 1.5f;
    }

    // always regeneration bonus (including combat)
    addValue += GetTotalAuraModifier(SPELL_AURA_MOD_HEALTH_REGEN_IN_COMBAT);
    addValue += m_baseHealthRegen / 2.5f;

    if (addValue < 0.0f)
        addValue = 0.0f;

    ModifyHealth(int32(addValue));
}

void Player::ResetAllPowers()
{
    SetHealth(GetMaxHealth());
    switch (getPowerType())
    {
        case POWER_MANA:
            SetPower(POWER_MANA, GetMaxPower(POWER_MANA));
            break;
        case POWER_RAGE:
            SetPower(POWER_RAGE, 0);
            break;
        case POWER_ENERGY:
            SetPower(POWER_ENERGY, GetMaxPower(POWER_ENERGY));
            break;
        case POWER_RUNIC_POWER:
            SetPower(POWER_RUNIC_POWER, 0);
            break;
        case POWER_ECLIPSE:
            SetPower(POWER_ECLIPSE, 0);
            break;
        default:
            break;
    }
}

bool Player::CanInteractWithQuestGiver(Object* questGiver) const
{
    switch (questGiver->GetTypeId())
    {
        case TYPEID_UNIT:
            return GetNPCIfCanInteractWith(questGiver->GetGUID(), UNIT_NPC_FLAG_QUESTGIVER) != nullptr;
        case TYPEID_GAMEOBJECT:
            return GetGameObjectIfCanInteractWith(questGiver->GetGUID(), GAMEOBJECT_TYPE_QUESTGIVER) != nullptr;
        case TYPEID_PLAYER:
            return IsAlive() && questGiver->ToPlayer()->IsAlive();
        case TYPEID_ITEM:
            return IsAlive();
        default:
            break;
    }
    return false;
}

Creature* Player::GetNPCIfCanInteractWith(ObjectGuid const& guid, uint64 npcflagmask) const
{
    // unit checks
    if (!guid)
        return nullptr;

    if (!IsInWorld())
        return nullptr;

    if (IsInFlight())
        return nullptr;

    // exist (we need look pets also for some interaction (quest/etc)
    Creature* creature = ObjectAccessor::GetCreatureOrPetOrVehicle(*this, guid);
    if (!creature)
        return nullptr;

    // Deathstate checks
    if (!IsAlive() && !(creature->GetCreatureTemplate()->type_flags & CREATURE_TYPEFLAGS_GHOST))
        return nullptr;

    // alive or spirit healer
    if (!creature->IsAlive() && !(creature->GetCreatureTemplate()->type_flags & CREATURE_TYPEFLAGS_DEAD_INTERACT))
        return nullptr;

    // appropriate npc type
    if (npcflagmask && !creature->HasFlag64(UNIT_NPC_FLAGS, npcflagmask))
        return nullptr;

    // not allow interaction under control, but allow with own pets
    if (!creature->GetCharmerGUID().IsEmpty())
        return nullptr;

    // not unfriendly/hostile
    if (creature->GetReactionTo(this) <= REP_UNFRIENDLY)
        return nullptr;

    // not too far
    if (!creature->IsWithinDistInMap(this, INTERACTION_DISTANCE))
        return nullptr;

    return creature;
}

GameObject* Player::GetGameObjectIfCanInteractWith(ObjectGuid const& guid) const
{
    if (GameObject* go = GetMap()->GetGameObject(guid))
    {
        if (go->IsWithinDistInMap(this, go->GetInteractionDistance()))
            return go;

        TC_LOG_DEBUG("maps", "Player::GetGameObjectIfCanInteractWith: GameObject '%s' (%s) is too far away from player '%s' (%s) to be used by him (Distance: %f, maximal %f is allowed)",
            go->GetGOInfo()->name.c_str(), go->GetGUID().ToString().c_str(), GetName().c_str(), GetGUID().ToString().c_str(), go->GetDistance(this), go->GetInteractionDistance());
    }

    return nullptr;
}

GameObject* Player::GetGameObjectIfCanInteractWith(ObjectGuid const& guid, GameobjectTypes type) const
{
    if (GameObject* go = GetMap()->GetGameObject(guid))
    {
        if (go->GetGoType() == type)
        {
            if (go->IsWithinDistInMap(this, go->GetInteractionDistance()))
                return go;

            TC_LOG_DEBUG("maps", "Player::GetGameObjectIfCanInteractWith: GameObject '%s' (%s) is too far away from player '%s' (%s) to be used by him (Distance: %f, maximal %f is allowed)",
                go->GetGOInfo()->name.c_str(), go->GetGUID().ToString().c_str(), GetName().c_str(), GetGUID().ToString().c_str(), go->GetDistance(this), go->GetInteractionDistance());
        }
    }

    return nullptr;
}

bool Player::IsUnderWater() const
{
    return IsInWater() &&
        GetPositionZ() < (GetBaseMap()->GetWaterLevel(GetPositionX(), GetPositionY())-2);
}

void Player::SetInWater(bool apply)
{
    if (m_isInWater == apply)
        return;

    //define player in water by opcodes
    //move player's guid into HateOfflineList of those mobs
    //which can't swim and move guid back into ThreatList when
    //on surface.
    /// @todo exist also swimming mobs, and function must be symmetric to enter/leave water
    m_isInWater = apply;

    // remove auras that need water/land
    RemoveAurasWithInterruptFlags(apply ? AURA_INTERRUPT_FLAG_NOT_ABOVEWATER : AURA_INTERRUPT_FLAG_NOT_UNDERWATER);

    getHostileRefManager().updateThreatTables();
}

bool Player::IsInAreaTriggerRadius(const AreaTriggerEntry* trigger) const
{
    if (!trigger || GetMapId() != trigger->MapID)
        return false;

    if (trigger->Radius > 0.f)
    {
        // if we have radius check it
        float dist = GetDistance(trigger->Pos.X, trigger->Pos.Y, trigger->Pos.Z);
        if (dist > trigger->Radius)
            return false;
    }
    else
    {
        Position center(trigger->Pos.X, trigger->Pos.Y, trigger->Pos.Z, trigger->BoxYaw);
        if (!IsWithinBox(center, trigger->BoxLength / 2.f, trigger->BoxWidth / 2.f, trigger->BoxHeight / 2.f))
            return false;
    }

    return true;
}

void Player::SetGameMaster(bool on)
{
    if (on)
    {
        m_ExtraFlags |= PLAYER_EXTRA_GM_ON;
        setFaction(35);
        SetFlag(PLAYER_FLAGS, PLAYER_FLAGS_GM);
        SetFlag(UNIT_FIELD_FLAGS_2, UNIT_FLAG2_ALLOW_CHEAT_SPELLS);

        if (Pet* pet = GetPet())
        {
            pet->setFaction(35);
            pet->getHostileRefManager().setOnlineOfflineState(false);
        }

        RemoveByteFlag(UNIT_FIELD_BYTES_2, 1, UNIT_BYTE2_FLAG_FFA_PVP);
        ResetContestedPvP();

        getHostileRefManager().setOnlineOfflineState(false);
        CombatStopWithPets();

        m_serverSideVisibilityDetect.SetValue(SERVERSIDE_VISIBILITY_GM, GetSession()->GetSecurity());
    }
    else
    {
        m_ExtraFlags &= ~ PLAYER_EXTRA_GM_ON;
        setFactionForRace(getRace());
        RemoveFlag(PLAYER_FLAGS, PLAYER_FLAGS_GM);
        RemoveFlag(UNIT_FIELD_FLAGS_2, UNIT_FLAG2_ALLOW_CHEAT_SPELLS);

        if (Pet* pet = GetPet())
        {
            pet->setFaction(getFaction());
            pet->getHostileRefManager().setOnlineOfflineState(true);
        }

        // restore FFA PvP Server state
        if (sWorld->IsFFAPvPRealm())
            SetByteFlag(UNIT_FIELD_BYTES_2, 1, UNIT_BYTE2_FLAG_FFA_PVP);

        // restore FFA PvP area state, remove not allowed for GM mounts
        UpdateArea(m_areaUpdateId);

        getHostileRefManager().setOnlineOfflineState(true);
        m_serverSideVisibilityDetect.SetValue(SERVERSIDE_VISIBILITY_GM, SEC_PLAYER);
    }

    UpdateObjectVisibility();
}

bool Player::CanBeGameMaster() const
{
    return GetSession()->HasPermission(rbac::RBAC_PERM_COMMAND_GM);
}

void Player::SetGMVisible(bool on)
{
    if (on)
    {
        m_ExtraFlags &= ~PLAYER_EXTRA_GM_INVISIBLE;         //remove flag
        m_serverSideVisibility.SetValue(SERVERSIDE_VISIBILITY_GM, SEC_PLAYER);
    }
    else
    {
        m_ExtraFlags |= PLAYER_EXTRA_GM_INVISIBLE;          //add flag

        SetAcceptWhispers(false);
        SetGameMaster(true);

        m_serverSideVisibility.SetValue(SERVERSIDE_VISIBILITY_GM, GetSession()->GetSecurity());
    }
}

bool Player::IsGroupVisibleFor(Player const* p) const
{
    switch (sWorld->getIntConfig(CONFIG_GROUP_VISIBILITY))
    {
        default: return IsInSameGroupWith(p);
        case 1:  return IsInSameRaidWith(p);
        case 2:  return GetTeam() == p->GetTeam();
    }
}

bool Player::IsInSameGroupWith(Player const* p) const
{
    return p == this || (GetGroup() != nullptr &&
        GetGroup() == p->GetGroup() &&
        GetGroup()->SameSubGroup(this, p));
}

bool Player::IsInSameRaidWith(Player const* p) const
{
    return p == this || (GetGroup() != nullptr && GetGroup() == p->GetGroup());
}

///- If the player is invited, remove him. If the group if then only 1 person, disband the group.
/// @todo Shouldn't we also check if there is no other invitees before disbanding the group?
void Player::UninviteFromGroup()
{
    Group* group = GetGroupInvite();
    if (!group)
        return;

    group->RemoveInvite(this);

    if (group->GetMembersCount() <= 1)                       // group has just 1 member => disband
    {
        if (group->IsCreated())
        {
            group->Disband(true);
        }
        else
        {
            group->RemoveAllInvites();
            delete group;
        }
    }
}

void Player::RemoveFromGroup(Group* group, ObjectGuid guid, RemoveMethod method /* = GROUP_REMOVEMETHOD_DEFAULT*/, ObjectGuid kicker /* = ObjectGuid::Empty */, const char* reason /* = NULL */)
{
    if (!group)
        return;

    group->RemoveMember(guid, method, kicker, reason);
}

void Player::GiveXP(uint32 xp, Unit* victim, float group_rate)
{
    if (xp < 1)
        return;

    if (!IsAlive() && !GetBattlegroundId())
        return;

    if (HasFlag(PLAYER_FLAGS, PLAYER_FLAGS_NO_XP_GAIN))
        return;

    if (victim && victim->GetTypeId() == TYPEID_UNIT && !victim->ToCreature()->hasLootRecipient())
        return;

    uint8 level = getLevel();

    sScriptMgr->OnGivePlayerXP(this, xp, victim);

    // XP to money conversion processed in Player::RewardQuest
    if (level >= sWorld->getIntConfig(CONFIG_MAX_PLAYER_LEVEL))
        return;

    uint32 bonus_xp;
    bool recruitAFriend = GetsRecruitAFriendBonus(true);

    // RaF does NOT stack with rested experience
    if (recruitAFriend)
        bonus_xp = 2 * xp; // xp + bonus_xp must add up to 3 * xp for RaF; calculation for quests done client-side
    else
        bonus_xp = victim ? GetXPRestBonus(xp) : 0; // XP resting bonus

    WorldPackets::Character::LogXPGain packet;
    packet.Victim = victim ? victim->GetGUID() : ObjectGuid::Empty;
    packet.Original = xp + bonus_xp;
    packet.Reason = victim ? LOG_XP_REASON_KILL : LOG_XP_REASON_NO_KILL;
    packet.Amount = xp;
    packet.GroupBonus = group_rate;
    packet.ReferAFriend = recruitAFriend;
    GetSession()->SendPacket(packet.Write());

    uint32 curXP = GetUInt32Value(PLAYER_XP);
    uint32 nextLvlXP = GetUInt32Value(PLAYER_NEXT_LEVEL_XP);
    uint32 newXP = curXP + xp + bonus_xp;

    while (newXP >= nextLvlXP && level < sWorld->getIntConfig(CONFIG_MAX_PLAYER_LEVEL))
    {
        newXP -= nextLvlXP;

        if (level < sWorld->getIntConfig(CONFIG_MAX_PLAYER_LEVEL))
            GiveLevel(level + 1);

        level = getLevel();
        nextLvlXP = GetUInt32Value(PLAYER_NEXT_LEVEL_XP);
    }

    SetUInt32Value(PLAYER_XP, newXP);
}

// Update player to next level
// Current player experience not update (must be update by caller)
void Player::GiveLevel(uint8 level)
{
    uint8 oldLevel = getLevel();
    if (level == oldLevel)
        return;

    if (Guild* guild = GetGuild())
        guild->UpdateMemberData(this, GUILD_MEMBER_DATA_LEVEL, level);

    PlayerLevelInfo info;
    sObjectMgr->GetPlayerLevelInfo(getRace(), getClass(), level, &info);

    uint32 basehp = 0, basemana = 0;
    sObjectMgr->GetPlayerClassLevelInfo(getClass(), level, basehp, basemana);

    WorldPackets::Misc::LevelUpInfo packet;
    packet.Level = level;
    packet.HealthDelta = int32(basehp) - int32(GetCreateHealth());

    /// @todo find some better solution
    // for (int i = 0; i < MAX_STORED_POWERS; ++i)
    packet.PowerDelta[0] = int32(basemana) - int32(GetCreateMana());
    packet.PowerDelta[1] = 0;
    packet.PowerDelta[2] = 0;
    packet.PowerDelta[3] = 0;
    packet.PowerDelta[4] = 0;
    packet.PowerDelta[5] = 0;

    for (uint8 i = STAT_STRENGTH; i < MAX_STATS; ++i)
        packet.StatDelta[i] = int32(info.stats[i]) - GetCreateStat(Stats(i));

    uint32 const* rowLevels = (getClass() != CLASS_DEATH_KNIGHT) ? DefaultTalentRowLevels : DKTalentRowLevels;

    packet.Cp = std::find(rowLevels, rowLevels + MAX_TALENT_TIERS, level) != (rowLevels + MAX_TALENT_TIERS);

    GetSession()->SendPacket(packet.Write());

    SetUInt32Value(PLAYER_NEXT_LEVEL_XP, sObjectMgr->GetXPForLevel(level));

    //update level, max level of skills
    m_Played_time[PLAYED_TIME_LEVEL] = 0;                   // Level Played Time reset

    _ApplyAllLevelScaleItemMods(false);

    SetLevel(level);

    UpdateSkillsForLevel();
    LearnDefaultSkills();
    LearnSpecializationSpells();

    // save base values (bonuses already included in stored stats
    for (uint8 i = STAT_STRENGTH; i < MAX_STATS; ++i)
        SetCreateStat(Stats(i), info.stats[i]);

    SetCreateHealth(basehp);
    SetCreateMana(basemana);

    InitTalentForLevel();
    InitTaxiNodesForLevel();
    InitGlyphsForLevel();

    UpdateAllStats();

    if (sWorld->getBoolConfig(CONFIG_ALWAYS_MAXSKILL)) // Max weapon skill when leveling up
        UpdateSkillsToMaxSkillsForLevel();

    _ApplyAllLevelScaleItemMods(true); // Moved to above SetFullHealth so player will have full health from Heirlooms

    // set current level health and mana/energy to maximum after applying all mods.
    SetFullHealth();
    SetPower(POWER_MANA, GetMaxPower(POWER_MANA));
    SetPower(POWER_ENERGY, GetMaxPower(POWER_ENERGY));
    if (GetPower(POWER_RAGE) > GetMaxPower(POWER_RAGE))
        SetPower(POWER_RAGE, GetMaxPower(POWER_RAGE));
    SetPower(POWER_FOCUS, 0);

    // update level to hunter/summon pet
    if (Pet* pet = GetPet())
        pet->SynchronizeLevelWithOwner();

    if (MailLevelReward const* mailReward = sObjectMgr->GetMailLevelReward(level, getRaceMask()))
    {
        /// @todo Poor design of mail system
        SQLTransaction trans = CharacterDatabase.BeginTransaction();
        MailDraft(mailReward->mailTemplateId).SendMailTo(trans, this, MailSender(MAIL_CREATURE, uint64(mailReward->senderEntry)));
        CharacterDatabase.CommitTransaction(trans);
    }

    UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_REACH_LEVEL);

    // Refer-A-Friend
    if (GetSession()->GetRecruiterId())
    {
        if (level < sWorld->getIntConfig(CONFIG_MAX_RECRUIT_A_FRIEND_BONUS_PLAYER_LEVEL))
        {
            if (level % 2 == 0)
            {
                ++m_grantableLevels;

                if (!HasByteFlag(PLAYER_FIELD_BYTES, PLAYER_FIELD_BYTES_OFFSET_RAF_GRANTABLE_LEVEL, 0x01))
                    SetByteFlag(PLAYER_FIELD_BYTES, PLAYER_FIELD_BYTES_OFFSET_RAF_GRANTABLE_LEVEL, 0x01);
            }
        }
    }

    sScriptMgr->OnPlayerLevelChanged(this, oldLevel);
}

void Player::InitTalentForLevel()
{
    uint8 level = getLevel();
    // talents base at level diff (talents = level - 9 but some can be used already)
    if (level < MIN_SPECIALIZATION_LEVEL)
        ResetTalentSpecialization();

    uint32 talentTiers = CalculateTalentsTiers();
    if (level < 15)
    {
        // Remove all talent points
        ResetTalents(true);
    }
    else
    {
        if (level < sWorld->getIntConfig(CONFIG_MIN_DUALSPEC_LEVEL) || GetTalentGroupsCount() == 0)
        {
            SetTalentGroupsCount(1);
            SetActiveTalentGroup(0);
        }

        if (!GetSession()->HasPermission(rbac::RBAC_PERM_SKIP_CHECK_MORE_TALENTS_THAN_ALLOWED))
            for (uint32 t = talentTiers; t < MAX_TALENT_TIERS; ++t)
                for (uint32 c = 0; c < MAX_TALENT_COLUMNS; ++c)
                    for (TalentEntry const* talent : sTalentByPos[getClass()][t][c])
                        RemoveTalent(talent);
    }

    SetUInt32Value(PLAYER_FIELD_MAX_TALENT_TIERS, talentTiers);

    if (!GetSession()->PlayerLoading())
        SendTalentsInfoData(); // update at client
}

void Player::InitStatsForLevel(bool reapplyMods)
{
    if (reapplyMods)                                        //reapply stats values only on .reset stats (level) command
        _RemoveAllStatBonuses();

    uint32 basehp = 0, basemana = 0;
    sObjectMgr->GetPlayerClassLevelInfo(getClass(), getLevel(), basehp, basemana);

    PlayerLevelInfo info;
    sObjectMgr->GetPlayerLevelInfo(getRace(), getClass(), getLevel(), &info);

    SetUInt32Value(PLAYER_FIELD_MAX_LEVEL, sWorld->getIntConfig(CONFIG_MAX_PLAYER_LEVEL));
    SetUInt32Value(PLAYER_NEXT_LEVEL_XP, sObjectMgr->GetXPForLevel(getLevel()));

    // reset before any aura state sources (health set/aura apply)
    SetUInt32Value(UNIT_FIELD_AURASTATE, 0);

    UpdateSkillsForLevel();

    // set default cast time multiplier
    SetFloatValue(UNIT_MOD_CAST_SPEED, 1.0f);
    SetFloatValue(UNIT_MOD_CAST_HASTE, 1.0f);
    SetFloatValue(UNIT_FIELD_MOD_HASTE, 1.0f);
    SetFloatValue(UNIT_FIELD_MOD_RANGED_HASTE, 1.0f);

    // reset size before reapply auras
    SetObjectScale(1.0f);

    // save base values (bonuses already included in stored stats
    for (uint8 i = STAT_STRENGTH; i < MAX_STATS; ++i)
        SetCreateStat(Stats(i), info.stats[i]);

    for (uint8 i = STAT_STRENGTH; i < MAX_STATS; ++i)
        SetStat(Stats(i), info.stats[i]);

    SetCreateHealth(basehp);

    //set create powers
    SetCreateMana(basemana);

    SetArmor(int32(m_createStats[STAT_AGILITY]*2));

    InitStatBuffMods();

    //reset rating fields values
    for (uint16 index = PLAYER_FIELD_COMBAT_RATING_1; index < PLAYER_FIELD_COMBAT_RATING_1 + MAX_COMBAT_RATING; ++index)
        SetUInt32Value(index, 0);

    SetUInt32Value(PLAYER_FIELD_MOD_HEALING_DONE_POS, 0);
    SetFloatValue(PLAYER_FIELD_MOD_HEALING_PCT, 1.0f);
    SetFloatValue(PLAYER_FIELD_MOD_HEALING_DONE_PCT, 1.0f);
    SetFloatValue(PLAYER_FIELD_MOD_PERIODIC_HEALING_DONE_PERCENT, 1.0f);
    for (uint8 i = 0; i < 7; ++i)
    {
        SetUInt32Value(PLAYER_FIELD_MOD_DAMAGE_DONE_NEG+i, 0);
        SetUInt32Value(PLAYER_FIELD_MOD_DAMAGE_DONE_POS+i, 0);
        SetFloatValue(PLAYER_FIELD_MOD_DAMAGE_DONE_PCT+i, 1.0f);
    }

    SetFloatValue(PLAYER_FIELD_MOD_SPELL_POWER_PCT, 1.0f);

    //reset attack power, damage and attack speed fields
    SetFloatValue(UNIT_FIELD_BASEATTACKTIME, 2000.0f);
    SetFloatValue(UNIT_FIELD_BASEATTACKTIME + 1, 2000.0f); // offhand attack time
    SetFloatValue(UNIT_FIELD_RANGEDATTACKTIME, 2000.0f);

    SetFloatValue(UNIT_FIELD_MINDAMAGE, 0.0f);
    SetFloatValue(UNIT_FIELD_MAXDAMAGE, 0.0f);
    SetFloatValue(UNIT_FIELD_MINOFFHANDDAMAGE, 0.0f);
    SetFloatValue(UNIT_FIELD_MAXOFFHANDDAMAGE, 0.0f);
    SetFloatValue(UNIT_FIELD_MINRANGEDDAMAGE, 0.0f);
    SetFloatValue(UNIT_FIELD_MAXRANGEDDAMAGE, 0.0f);
    for (uint16 i = 0; i < 3; ++i)
    {
        SetFloatValue(PLAYER_FIELD_WEAPON_DMG_MULTIPLIERS + i, 1.0f);
        SetFloatValue(PLAYER_FIELD_WEAPON_ATK_SPEED_MULTIPLIERS + i, 1.0f);
    }

    SetInt32Value(UNIT_FIELD_ATTACK_POWER,            0);
    SetFloatValue(UNIT_FIELD_ATTACK_POWER_MULTIPLIER, 0.0f);
    SetInt32Value(UNIT_FIELD_RANGED_ATTACK_POWER,     0);
    SetFloatValue(UNIT_FIELD_RANGED_ATTACK_POWER_MULTIPLIER, 0.0f);

    // Base crit values (will be recalculated in UpdateAllStats() at loading and in _ApplyAllStatBonuses() at reset
    SetFloatValue(PLAYER_CRIT_PERCENTAGE, 0.0f);
    SetFloatValue(PLAYER_OFFHAND_CRIT_PERCENTAGE, 0.0f);
    SetFloatValue(PLAYER_RANGED_CRIT_PERCENTAGE, 0.0f);

    // Init spell schools (will be recalculated in UpdateAllStats() at loading and in _ApplyAllStatBonuses() at reset
    for (uint8 i = 0; i < 7; ++i)
        SetFloatValue(PLAYER_SPELL_CRIT_PERCENTAGE1+i, 0.0f);

    SetFloatValue(PLAYER_PARRY_PERCENTAGE, 0.0f);
    SetFloatValue(PLAYER_BLOCK_PERCENTAGE, 0.0f);

    // Static 30% damage blocked
    SetUInt32Value(PLAYER_SHIELD_BLOCK, 30);

    // Dodge percentage
    SetFloatValue(PLAYER_DODGE_PERCENTAGE, 0.0f);

    // set armor (resistance 0) to original value (create_agility*2)
    SetArmor(int32(m_createStats[STAT_AGILITY]*2));
    SetResistanceBuffMods(SpellSchools(0), true, 0.0f);
    SetResistanceBuffMods(SpellSchools(0), false, 0.0f);
    // set other resistance to original value (0)
    for (uint8 i = 1; i < MAX_SPELL_SCHOOL; ++i)
    {
        SetResistance(SpellSchools(i), 0);
        SetResistanceBuffMods(SpellSchools(i), true, 0.0f);
        SetResistanceBuffMods(SpellSchools(i), false, 0.0f);
    }

    SetUInt32Value(PLAYER_FIELD_MOD_TARGET_RESISTANCE, 0);
    SetUInt32Value(PLAYER_FIELD_MOD_TARGET_PHYSICAL_RESISTANCE, 0);
    for (uint8 i = 0; i < MAX_SPELL_SCHOOL; ++i)
    {
        SetUInt32Value(UNIT_FIELD_POWER_COST_MODIFIER+i, 0);
        SetFloatValue(UNIT_FIELD_POWER_COST_MULTIPLIER+i, 0.0f);
    }
    // Reset no reagent cost field
    for (uint8 i = 0; i < 3; ++i)
        SetUInt32Value(PLAYER_NO_REAGENT_COST_1 + i, 0);
    // Init data for form but skip reapply item mods for form
    InitDataForForm(reapplyMods);

    // save new stats
    for (uint8 i = POWER_MANA; i < MAX_POWERS; ++i)
        SetMaxPower(Powers(i), GetCreatePowers(Powers(i)));

    SetMaxHealth(basehp);                     // stamina bonus will applied later

    // cleanup mounted state (it will set correctly at aura loading if player saved at mount.
    SetUInt32Value(UNIT_FIELD_MOUNTDISPLAYID, 0);

    // cleanup unit flags (will be re-applied if need at aura load).
    RemoveFlag(UNIT_FIELD_FLAGS,
        UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_DISABLE_MOVE | UNIT_FLAG_NOT_ATTACKABLE_1 |
        UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC  | UNIT_FLAG_LOOTING          |
        UNIT_FLAG_PET_IN_COMBAT  | UNIT_FLAG_SILENCED     | UNIT_FLAG_PACIFIED         |
        UNIT_FLAG_STUNNED        | UNIT_FLAG_IN_COMBAT    | UNIT_FLAG_DISARMED         |
        UNIT_FLAG_CONFUSED       | UNIT_FLAG_FLEEING      | UNIT_FLAG_NOT_SELECTABLE   |
        UNIT_FLAG_SKINNABLE      | UNIT_FLAG_MOUNT        | UNIT_FLAG_TAXI_FLIGHT      );
    SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_PVP_ATTACKABLE);   // must be set

    SetFlag(UNIT_FIELD_FLAGS_2, UNIT_FLAG2_REGENERATE_POWER);// must be set

    // cleanup player flags (will be re-applied if need at aura load), to avoid have ghost flag without ghost aura, for example.
    RemoveFlag(PLAYER_FLAGS, PLAYER_FLAGS_AFK | PLAYER_FLAGS_DND | PLAYER_FLAGS_GM | PLAYER_FLAGS_GHOST | PLAYER_ALLOW_ONLY_ABILITY);

    RemoveStandFlags(UNIT_STAND_FLAGS_ALL);                 // one form stealth modified bytes
    RemoveByteFlag(UNIT_FIELD_BYTES_2, 1, UNIT_BYTE2_FLAG_FFA_PVP | UNIT_BYTE2_FLAG_SANCTUARY);

    // restore if need some important flags
    SetUInt32Value(PLAYER_FIELD_BYTES2, 0);                 // flags empty by default

    if (reapplyMods)                                        // reapply stats values only on .reset stats (level) command
        _ApplyAllStatBonuses();

    // set current level health and mana/energy to maximum after applying all mods.
    SetFullHealth();
    SetPower(POWER_MANA, GetMaxPower(POWER_MANA));
    SetPower(POWER_ENERGY, GetMaxPower(POWER_ENERGY));
    if (GetPower(POWER_RAGE) > GetMaxPower(POWER_RAGE))
        SetPower(POWER_RAGE, GetMaxPower(POWER_RAGE));
    SetPower(POWER_FOCUS, GetMaxPower(POWER_FOCUS));
    SetPower(POWER_RUNIC_POWER, 0);

    // update level to hunter/summon pet
    if (Pet* pet = GetPet())
        pet->SynchronizeLevelWithOwner();
}

void Player::SendKnownSpells()
{
    WorldPackets::Spells::SendKnownSpells knownSpells;
    knownSpells.InitialLogin = false; /// @todo

    knownSpells.KnownSpells.reserve(m_spells.size());
    for (PlayerSpellMap::value_type const& spell : m_spells)
    {
        if (spell.second->state == PLAYERSPELL_REMOVED)
            continue;

        if (!spell.second->active || spell.second->disabled)
            continue;

        knownSpells.KnownSpells.push_back(spell.first);
    }

    SendDirectMessage(knownSpells.Write());
}

void Player::RemoveMail(uint32 id)
{
    for (PlayerMails::iterator itr = m_mail.begin(); itr != m_mail.end(); ++itr)
    {
        if ((*itr)->messageID == id)
        {
            //do not delete item, because Player::removeMail() is called when returning mail to sender.
            m_mail.erase(itr);
            return;
        }
    }
}

void Player::SendMailResult(uint32 mailId, MailResponseType mailAction, MailResponseResult mailError, uint32 equipError, ObjectGuid::LowType item_guid, uint32 item_count) const
{
    WorldPackets::Mail::MailCommandResult result;

    result.MailID = mailId;
    result.Command = mailAction;
    result.ErrorCode = mailError;

    if (mailError == MAIL_ERR_EQUIP_ERROR)
        result.BagResult = equipError;
    else if (mailAction == MAIL_ITEM_TAKEN)
    {
        result.AttachID = item_guid;
        result.QtyInInventory = item_count;
    }
    GetSession()->SendPacket(result.Write());
}

void Player::SendNewMail() const
{
    // deliver undelivered mail
    WorldPackets::Mail::NotifyRecievedMail notify;
    notify.Delay = 0.0f;

    GetSession()->SendPacket(notify.Write());
}

void Player::UpdateNextMailTimeAndUnreads()
{
    // calculate next delivery time (min. from non-delivered mails
    // and recalculate unReadMail
    time_t cTime = time(nullptr);
    m_nextMailDelivereTime = 0;
    unReadMails = 0;
    for (PlayerMails::iterator itr = m_mail.begin(); itr != m_mail.end(); ++itr)
    {
        if ((*itr)->deliver_time > cTime)
        {
            if (!m_nextMailDelivereTime || m_nextMailDelivereTime > (*itr)->deliver_time)
                m_nextMailDelivereTime = (*itr)->deliver_time;
        }
        else if (((*itr)->checked & MAIL_CHECK_MASK_READ) == 0)
            ++unReadMails;
    }
}

void Player::AddNewMailDeliverTime(time_t deliver_time)
{
    if (deliver_time <= time(nullptr))                          // ready now
    {
        ++unReadMails;
        SendNewMail();
    }
    else                                                    // not ready and no have ready mails
    {
        if (!m_nextMailDelivereTime || m_nextMailDelivereTime > deliver_time)
            m_nextMailDelivereTime = deliver_time;
    }
}

void DeleteSpellFromAllPlayers(uint32 spellId)
{
    CharacterDatabaseStatements stmts[2] = {CHAR_DEL_INVALID_SPELL_SPELLS, CHAR_DEL_INVALID_SPELL_TALENTS};
    for (uint8 i = 0; i < 2; i++)
    {
        PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(stmts[i]);

        stmt->setUInt32(0, spellId);

        CharacterDatabase.Execute(stmt);
    }
}

bool Player::AddTalent(TalentEntry const* talent, uint8 spec, bool learning)
{
    SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(talent->SpellID);
    if (!spellInfo)
    {
        // do character spell book cleanup (all characters)
        if (!IsInWorld() && !learning)                       // spell load case
        {
            TC_LOG_ERROR("spells", "Player::AddTalent: Spell (ID: %u) does not exist. Deleting for all characters in `character_spell` and `character_talent`.", talent->SpellID);

            DeleteSpellFromAllPlayers(talent->SpellID);
        }
        else
            TC_LOG_ERROR("spells", "Player::AddTalent: Spell (ID: %u) does not exist", talent->SpellID);

        return false;
    }

    if (!SpellMgr::IsSpellValid(spellInfo, this, false))
    {
        // do character spell book cleanup (all characters)
        if (!IsInWorld() && !learning)                       // spell load case
        {
            TC_LOG_ERROR("spells", "Player::AddTalent: Spell (ID: %u) is invalid. Deleting for all characters in `character_spell` and `character_talent`.", talent->SpellID);

            DeleteSpellFromAllPlayers(talent->SpellID);
        }
        else
            TC_LOG_ERROR("spells", "Player::AddTalent: Spell (ID: %u) is invalid", talent->SpellID);

        return false;
    }

    if (talent->OverridesSpellID)
        AddOverrideSpell(talent->OverridesSpellID, talent->SpellID);

    PlayerTalentMap::iterator itr = GetTalentMap(spec)->find(talent->ID);
    if (itr != GetTalentMap(spec)->end())
        itr->second = PLAYERSPELL_UNCHANGED;
    else
        (*GetTalentMap(spec))[talent->ID] = learning ? PLAYERSPELL_NEW : PLAYERSPELL_UNCHANGED;

    return true;
}

void Player::RemoveTalent(TalentEntry const* talent)
{
    SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(talent->SpellID);
    if (!spellInfo)
        return;

    RemoveSpell(talent->SpellID, true);

    // search for spells that the talent teaches and unlearn them
    for (SpellEffectInfo const* effect : spellInfo->GetEffectsForDifficulty(DIFFICULTY_NONE))
        if (effect && effect->TriggerSpell > 0 && effect->Effect == SPELL_EFFECT_LEARN_SPELL)
            RemoveSpell(effect->TriggerSpell, true);

    if (talent->OverridesSpellID)
        RemoveOverrideSpell(talent->OverridesSpellID, talent->SpellID);

    // if this talent rank can be found in the PlayerTalentMap, mark the talent as removed so it gets deleted
    PlayerTalentMap::iterator plrTalent = GetTalentMap(GetActiveTalentGroup())->find(talent->ID);
    if (plrTalent != GetTalentMap(GetActiveTalentGroup())->end())
        plrTalent->second = PLAYERSPELL_REMOVED;
}

bool Player::AddSpell(uint32 spellId, bool active, bool learning, bool dependent, bool disabled, bool loading /*= false*/, uint32 fromSkill /*= 0*/)
{
    SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(spellId);
    if (!spellInfo)
    {
        // do character spell book cleanup (all characters)
        if (!IsInWorld() && !learning)                       // spell load case
        {
            TC_LOG_ERROR("spells", "Player::AddSpell: Spell (ID: %u) does not exist. deleting for all characters in `character_spell` and `character_talent`.", spellId);

            DeleteSpellFromAllPlayers(spellId);
        }
        else
            TC_LOG_ERROR("spells", "Player::AddSpell: Spell (ID: %u) does not exist", spellId);

        return false;
    }

    if (!SpellMgr::IsSpellValid(spellInfo, this, false))
    {
        // do character spell book cleanup (all characters)
        if (!IsInWorld() && !learning)                       // spell load case
        {
            TC_LOG_ERROR("spells", "Player::AddSpell: Spell (ID: %u) is invalid. deleting for all characters in `character_spell` and `character_talent`.", spellId);

            DeleteSpellFromAllPlayers(spellId);
        }
        else
            TC_LOG_ERROR("spells", "Player::AddSpell: Spell (ID: %u) is invalid", spellId);

        return false;
    }

    PlayerSpellState state = learning ? PLAYERSPELL_NEW : PLAYERSPELL_UNCHANGED;

    bool dependent_set = false;
    bool disabled_case = false;
    bool superceded_old = false;

    PlayerSpellMap::iterator itr = m_spells.find(spellId);

    // Remove temporary spell if found to prevent conflicts
    if (itr != m_spells.end() && itr->second->state == PLAYERSPELL_TEMPORARY)
        RemoveTemporarySpell(spellId);
    else if (itr != m_spells.end())
    {
        uint32 next_active_spell_id = 0;
        // fix activate state for non-stackable low rank (and find next spell for !active case)
        if (!spellInfo->IsStackableWithRanks() && spellInfo->IsRanked())
        {
            if (uint32 next = sSpellMgr->GetNextSpellInChain(spellId))
            {
                if (HasSpell(next))
                {
                    // high rank already known so this must !active
                    active = false;
                    next_active_spell_id = next;
                }
            }
        }

        // not do anything if already known in expected state
        if (itr->second->state != PLAYERSPELL_REMOVED && itr->second->active == active &&
            itr->second->dependent == dependent && itr->second->disabled == disabled)
        {
            if (!IsInWorld() && !learning)                   // explicitly load from DB and then exist in it already and set correctly
                itr->second->state = PLAYERSPELL_UNCHANGED;

            return false;
        }

        // dependent spell known as not dependent, overwrite state
        if (itr->second->state != PLAYERSPELL_REMOVED && !itr->second->dependent && dependent)
        {
            itr->second->dependent = dependent;
            if (itr->second->state != PLAYERSPELL_NEW)
                itr->second->state = PLAYERSPELL_CHANGED;
            dependent_set = true;
        }

        // update active state for known spell
        if (itr->second->active != active && itr->second->state != PLAYERSPELL_REMOVED && !itr->second->disabled)
        {
            itr->second->active = active;

            if (!IsInWorld() && !learning && !dependent_set) // explicitly load from DB and then exist in it already and set correctly
                itr->second->state = PLAYERSPELL_UNCHANGED;
            else if (itr->second->state != PLAYERSPELL_NEW)
                itr->second->state = PLAYERSPELL_CHANGED;

            if (active)
            {
                if (spellInfo->IsPassive() && IsNeedCastPassiveSpellAtLearn(spellInfo))
                    CastSpell(this, spellId, true);
            }
            else if (IsInWorld())
            {
                if (next_active_spell_id)
                    SendSupercededSpell(spellId, next_active_spell_id);
                else
                {
                    WorldPackets::Spells::UnlearnedSpells unlearnedSpells;
                    unlearnedSpells.SpellID.push_back(spellId);
                    SendDirectMessage(unlearnedSpells.Write());
                }
            }

            return active;                                  // learn (show in spell book if active now)
        }

        if (itr->second->disabled != disabled && itr->second->state != PLAYERSPELL_REMOVED)
        {
            if (itr->second->state != PLAYERSPELL_NEW)
                itr->second->state = PLAYERSPELL_CHANGED;
            itr->second->disabled = disabled;

            if (disabled)
                return false;

            disabled_case = true;
        }
        else switch (itr->second->state)
        {
            case PLAYERSPELL_UNCHANGED:                     // known saved spell
                return false;
            case PLAYERSPELL_REMOVED:                       // re-learning removed not saved spell
            {
                delete itr->second;
                m_spells.erase(itr);
                state = PLAYERSPELL_CHANGED;
                break;                                      // need re-add
            }
            default:                                        // known not saved yet spell (new or modified)
            {
                // can be in case spell loading but learned at some previous spell loading
                if (!IsInWorld() && !learning && !dependent_set)
                    itr->second->state = PLAYERSPELL_UNCHANGED;

                return false;
            }
        }
    }

    if (!disabled_case) // skip new spell adding if spell already known (disabled spells case)
    {
        // non talent spell: learn low ranks (recursive call)
        if (uint32 prev_spell = sSpellMgr->GetPrevSpellInChain(spellId))
        {
            if (!IsInWorld() || disabled)                    // at spells loading, no output, but allow save
                AddSpell(prev_spell, active, true, true, disabled, false, fromSkill);
            else                                            // at normal learning
                LearnSpell(prev_spell, true, fromSkill);
        }

        PlayerSpell* newspell = new PlayerSpell;
        newspell->state     = state;
        newspell->active    = active;
        newspell->dependent = dependent;
        newspell->disabled  = disabled;

        // replace spells in action bars and spellbook to bigger rank if only one spell rank must be accessible
        if (newspell->active && !newspell->disabled && !spellInfo->IsStackableWithRanks() && spellInfo->IsRanked() != 0)
        {
            for (PlayerSpellMap::iterator itr2 = m_spells.begin(); itr2 != m_spells.end(); ++itr2)
            {
                if (itr2->second->state == PLAYERSPELL_REMOVED)
                    continue;

                SpellInfo const* i_spellInfo = sSpellMgr->GetSpellInfo(itr2->first);
                if (!i_spellInfo)
                    continue;

                if (spellInfo->IsDifferentRankOf(i_spellInfo))
                {
                    if (itr2->second->active)
                    {
                        if (spellInfo->IsHighRankOf(i_spellInfo))
                        {
                            if (IsInWorld())                 // not send spell (re-/over-)learn packets at loading
                                SendSupercededSpell(itr2->first, spellId);

                            // mark old spell as disable (SMSG_SUPERCEDED_SPELL replace it in client by new)
                            itr2->second->active = false;
                            if (itr2->second->state != PLAYERSPELL_NEW)
                                itr2->second->state = PLAYERSPELL_CHANGED;
                            superceded_old = true;          // new spell replace old in action bars and spell book.
                        }
                        else
                        {
                            if (IsInWorld())                 // not send spell (re-/over-)learn packets at loading
                                SendSupercededSpell(spellId, itr2->first);

                            // mark new spell as disable (not learned yet for client and will not learned)
                            newspell->active = false;
                            if (newspell->state != PLAYERSPELL_NEW)
                                newspell->state = PLAYERSPELL_CHANGED;
                        }
                    }
                }
            }
        }

        m_spells[spellId] = newspell;

        // return false if spell disabled
        if (newspell->disabled)
            return false;
    }

    // cast talents with SPELL_EFFECT_LEARN_SPELL (other dependent spells will learned later as not auto-learned)
    // note: all spells with SPELL_EFFECT_LEARN_SPELL isn't passive
    if (!loading && spellInfo->HasAttribute(SPELL_ATTR0_CU_IS_TALENT) && spellInfo->HasEffect(SPELL_EFFECT_LEARN_SPELL))
    {
        // ignore stance requirement for talent learn spell (stance set for spell only for client spell description show)
        CastSpell(this, spellId, true);
    }
    // also cast passive spells (including all talents without SPELL_EFFECT_LEARN_SPELL) with additional checks
    else if (spellInfo->IsPassive())
    {
        if (IsNeedCastPassiveSpellAtLearn(spellInfo))
            CastSpell(this, spellId, true);
    }
    else if (spellInfo->HasEffect(SPELL_EFFECT_SKILL_STEP))
    {
        CastSpell(this, spellId, true);
        return false;
    }

    // update free primary prof.points (if any, can be none in case GM .learn prof. learning)
    if (uint32 freeProfs = GetFreePrimaryProfessionPoints())
    {
        if (spellInfo->IsPrimaryProfessionFirstRank())
            SetFreePrimaryProfessions(freeProfs - 1);
    }

    SkillLineAbilityMapBounds skill_bounds = sSpellMgr->GetSkillLineAbilityMapBounds(spellId);

    if (SpellLearnSkillNode const* spellLearnSkill = sSpellMgr->GetSpellLearnSkill(spellId))
    {
        // add dependent skills if this spell is not learned from adding skill already
        if (spellLearnSkill->skill != fromSkill)
        {
            uint32 skill_value = GetPureSkillValue(spellLearnSkill->skill);
            uint32 skill_max_value = GetPureMaxSkillValue(spellLearnSkill->skill);

            if (skill_value < spellLearnSkill->value)
                skill_value = spellLearnSkill->value;

            uint32 new_skill_max_value = spellLearnSkill->maxvalue == 0 ? GetMaxSkillValueForLevel() : spellLearnSkill->maxvalue;

            if (skill_max_value < new_skill_max_value)
                skill_max_value = new_skill_max_value;

            SetSkill(spellLearnSkill->skill, spellLearnSkill->step, skill_value, skill_max_value);
        }
    }
    else
    {
        // not ranked skills
        for (SkillLineAbilityMap::const_iterator _spell_idx = skill_bounds.first; _spell_idx != skill_bounds.second; ++_spell_idx)
        {
            SkillLineEntry const* pSkill = sSkillLineStore.LookupEntry(_spell_idx->second->SkillLine);
            if (!pSkill)
                continue;

            if (pSkill->ID == fromSkill)
                continue;

            // Runeforging special case
            if ((_spell_idx->second->AquireMethod == SKILL_LINE_ABILITY_LEARNED_ON_SKILL_LEARN && !HasSkill(pSkill->ID)) || ((pSkill->ID == SKILL_RUNEFORGING_2) && _spell_idx->second->TrivialSkillLineRankHigh == 0))
                if (SkillRaceClassInfoEntry const* rcInfo = GetSkillRaceClassInfo(pSkill->ID, getRace(), getClass()))
                    LearnDefaultSkill(rcInfo);
        }
    }

    // learn dependent spells
    SpellLearnSpellMapBounds spell_bounds = sSpellMgr->GetSpellLearnSpellMapBounds(spellId);

    for (SpellLearnSpellMap::const_iterator itr2 = spell_bounds.first; itr2 != spell_bounds.second; ++itr2)
    {
        if (!itr2->second.AutoLearned)
        {
            if (!IsInWorld() || !itr2->second.Active)       // at spells loading, no output, but allow save
                AddSpell(itr2->second.Spell, itr2->second.Active, true, true, false);
            else                                            // at normal learning
                LearnSpell(itr2->second.Spell, true);
        }

        if (itr2->second.OverridesSpell && itr2->second.Active)
            AddOverrideSpell(itr2->second.OverridesSpell, itr2->second.Spell);
    }

    if (!GetSession()->PlayerLoading())
    {
        // not ranked skills
        for (SkillLineAbilityMap::const_iterator _spell_idx = skill_bounds.first; _spell_idx != skill_bounds.second; ++_spell_idx)
        {
            UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_LEARN_SKILL_LINE, _spell_idx->second->SkillLine);
            UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_LEARN_SKILLLINE_SPELLS, _spell_idx->second->SkillLine);
        }

        UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_LEARN_SPELL, spellId);
    }

    // return true (for send learn packet) only if spell active (in case ranked spells) and not replace old spell
    return active && !disabled && !superceded_old;
}

void Player::AddTemporarySpell(uint32 spellId)
{
    PlayerSpellMap::iterator itr = m_spells.find(spellId);
    // spell already added - do not do anything
    if (itr != m_spells.end())
        return;
    PlayerSpell* newspell = new PlayerSpell;
    newspell->state     = PLAYERSPELL_TEMPORARY;
    newspell->active    = true;
    newspell->dependent = false;
    newspell->disabled  = false;
    m_spells[spellId]   = newspell;
}

void Player::RemoveTemporarySpell(uint32 spellId)
{
    PlayerSpellMap::iterator itr = m_spells.find(spellId);
    // spell already not in list - do not do anything
    if (itr == m_spells.end())
        return;
    // spell has other state than temporary - do not change it
    if (itr->second->state != PLAYERSPELL_TEMPORARY)
        return;
    delete itr->second;
    m_spells.erase(itr);
}

bool Player::IsNeedCastPassiveSpellAtLearn(SpellInfo const* spellInfo) const
{
    // note: form passives activated with shapeshift spells be implemented by HandleShapeshiftBoosts instead of spell_learn_spell
    // talent dependent passives activated at form apply have proper stance data
    ShapeshiftForm form = GetShapeshiftForm();
    bool need_cast = (!spellInfo->Stances || (form && (spellInfo->Stances & (UI64LIT(1) << (form - 1)))) ||
        (!form && (spellInfo->HasAttribute(SPELL_ATTR2_NOT_NEED_SHAPESHIFT))));

    if (spellInfo->HasAttribute(SPELL_ATTR8_MASTERY_SPECIALIZATION))
        need_cast &= IsCurrentSpecMasterySpell(spellInfo);

    //Check CasterAuraStates
    return need_cast && (!spellInfo->CasterAuraState || HasAuraState(AuraStateType(spellInfo->CasterAuraState)));
}

bool Player::IsCurrentSpecMasterySpell(SpellInfo const* spellInfo) const
{
    if (ChrSpecializationEntry const* chrSpec = sChrSpecializationStore.LookupEntry(GetSpecId(GetActiveTalentGroup())))
        return spellInfo->Id == chrSpec->MasterySpellID[0] || spellInfo->Id == chrSpec->MasterySpellID[1];

    return false;
}

void Player::LearnSpell(uint32 spell_id, bool dependent, uint32 fromSkill /*= 0*/)
{
    PlayerSpellMap::iterator itr = m_spells.find(spell_id);

    bool disabled = (itr != m_spells.end()) ? itr->second->disabled : false;
    bool active = disabled ? itr->second->active : true;

    bool learning = AddSpell(spell_id, active, true, dependent, false, false, fromSkill);

    // prevent duplicated entires in spell book, also not send if not in world (loading)
    if (learning && IsInWorld())
    {
        WorldPackets::Spells::LearnedSpells packet;
        packet.SpellID.push_back(spell_id);
        GetSession()->SendPacket(packet.Write());
    }

    // learn all disabled higher ranks and required spells (recursive)
    if (disabled)
    {
        if (uint32 nextSpell = sSpellMgr->GetNextSpellInChain(spell_id))
        {
            PlayerSpellMap::iterator iter = m_spells.find(nextSpell);
            if (iter != m_spells.end() && iter->second->disabled)
                LearnSpell(nextSpell, false, fromSkill);
        }

        SpellsRequiringSpellMapBounds spellsRequiringSpell = sSpellMgr->GetSpellsRequiringSpellBounds(spell_id);
        for (SpellsRequiringSpellMap::const_iterator itr2 = spellsRequiringSpell.first; itr2 != spellsRequiringSpell.second; ++itr2)
        {
            PlayerSpellMap::iterator iter2 = m_spells.find(itr2->second);
            if (iter2 != m_spells.end() && iter2->second->disabled)
                LearnSpell(itr2->second, false, fromSkill);
        }
    }
}

void Player::RemoveSpell(uint32 spell_id, bool disabled, bool learn_low_rank)
{
    PlayerSpellMap::iterator itr = m_spells.find(spell_id);
    if (itr == m_spells.end())
        return;

    if (itr->second->state == PLAYERSPELL_REMOVED || (disabled && itr->second->disabled) || itr->second->state == PLAYERSPELL_TEMPORARY)
        return;

    // unlearn non talent higher ranks (recursive)
    if (uint32 nextSpell = sSpellMgr->GetNextSpellInChain(spell_id))
    {
        SpellInfo const* spellInfo = sSpellMgr->AssertSpellInfo(nextSpell);
        if (HasSpell(nextSpell) && !spellInfo->HasAttribute(SPELL_ATTR0_CU_IS_TALENT))
            RemoveSpell(nextSpell, disabled, false);
    }
    //unlearn spells dependent from recently removed spells
    SpellsRequiringSpellMapBounds spellsRequiringSpell = sSpellMgr->GetSpellsRequiringSpellBounds(spell_id);
    for (SpellsRequiringSpellMap::const_iterator itr2 = spellsRequiringSpell.first; itr2 != spellsRequiringSpell.second; ++itr2)
        RemoveSpell(itr2->second, disabled);

    // re-search, it can be corrupted in prev loop
    itr = m_spells.find(spell_id);
    if (itr == m_spells.end())
        return;                                             // already unleared

    bool cur_active    = itr->second->active;
    bool cur_dependent = itr->second->dependent;

    if (disabled)
    {
        itr->second->disabled = disabled;
        if (itr->second->state != PLAYERSPELL_NEW)
            itr->second->state = PLAYERSPELL_CHANGED;
    }
    else
    {
        if (itr->second->state == PLAYERSPELL_NEW)
        {
            delete itr->second;
            m_spells.erase(itr);
        }
        else
            itr->second->state = PLAYERSPELL_REMOVED;
    }

    RemoveOwnedAura(spell_id, GetGUID());

    // remove pet auras
    for (uint8 i = 0; i < MAX_SPELL_EFFECTS; ++i)
        if (PetAura const* petSpell = sSpellMgr->GetPetAura(spell_id, i))
            RemovePetAura(petSpell);

    // update free primary prof.points (if not overflow setting, can be in case GM use before .learn prof. learning)
    SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(spell_id);
    if (spellInfo && spellInfo->IsPrimaryProfessionFirstRank())
    {
        uint32 freeProfs = GetFreePrimaryProfessionPoints()+1;
        if (freeProfs <= sWorld->getIntConfig(CONFIG_MAX_PRIMARY_TRADE_SKILL))
            SetFreePrimaryProfessions(freeProfs);
    }

    // remove dependent skill
    SpellLearnSkillNode const* spellLearnSkill = sSpellMgr->GetSpellLearnSkill(spell_id);
    if (spellLearnSkill)
    {
        uint32 prev_spell = sSpellMgr->GetPrevSpellInChain(spell_id);
        if (!prev_spell)                                    // first rank, remove skill
            SetSkill(spellLearnSkill->skill, 0, 0, 0);
        else
        {
            // search prev. skill setting by spell ranks chain
            SpellLearnSkillNode const* prevSkill = sSpellMgr->GetSpellLearnSkill(prev_spell);
            while (!prevSkill && prev_spell)
            {
                prev_spell = sSpellMgr->GetPrevSpellInChain(prev_spell);
                prevSkill = sSpellMgr->GetSpellLearnSkill(sSpellMgr->GetFirstSpellInChain(prev_spell));
            }

            if (!prevSkill)                                 // not found prev skill setting, remove skill
                SetSkill(spellLearnSkill->skill, 0, 0, 0);
            else                                            // set to prev. skill setting values
            {
                uint32 skill_value = GetPureSkillValue(prevSkill->skill);
                uint32 skill_max_value = GetPureMaxSkillValue(prevSkill->skill);

                if (skill_value > prevSkill->value)
                    skill_value = prevSkill->value;

                uint32 new_skill_max_value = prevSkill->maxvalue == 0 ? GetMaxSkillValueForLevel() : prevSkill->maxvalue;

                if (skill_max_value > new_skill_max_value)
                    skill_max_value = new_skill_max_value;

                SetSkill(prevSkill->skill, prevSkill->step, skill_value, skill_max_value);
            }
        }
    }

    // remove dependent spells
    SpellLearnSpellMapBounds spell_bounds = sSpellMgr->GetSpellLearnSpellMapBounds(spell_id);

    for (SpellLearnSpellMap::const_iterator itr2 = spell_bounds.first; itr2 != spell_bounds.second; ++itr2)
    {
        RemoveSpell(itr2->second.Spell, disabled);
        if (itr2->second.OverridesSpell)
            RemoveOverrideSpell(itr2->second.OverridesSpell, itr2->second.Spell);
    }

    // activate lesser rank in spellbook/action bar, and cast it if need
    bool prev_activate = false;

    if (uint32 prev_id = sSpellMgr->GetPrevSpellInChain(spell_id))
    {
        // if ranked non-stackable spell: need activate lesser rank and update dendence state
        /// No need to check for spellInfo != NULL here because if cur_active is true, then that means that the spell was already in m_spells, and only valid spells can be pushed there.
        if (cur_active && !spellInfo->IsStackableWithRanks() && spellInfo->IsRanked())
        {
            // need manually update dependence state (learn spell ignore like attempts)
            PlayerSpellMap::iterator prev_itr = m_spells.find(prev_id);
            if (prev_itr != m_spells.end())
            {
                if (prev_itr->second->dependent != cur_dependent)
                {
                    prev_itr->second->dependent = cur_dependent;
                    if (prev_itr->second->state != PLAYERSPELL_NEW)
                        prev_itr->second->state = PLAYERSPELL_CHANGED;
                }

                // now re-learn if need re-activate
                if (cur_active && !prev_itr->second->active && learn_low_rank)
                {
                    if (AddSpell(prev_id, true, false, prev_itr->second->dependent, prev_itr->second->disabled))
                    {
                        // downgrade spell ranks in spellbook and action bar
                        SendSupercededSpell(spell_id, prev_id);
                        prev_activate = true;
                    }
                }
            }
        }
    }

    m_overrideSpells.erase(spell_id);

    if (spell_id == 46917 && m_canTitanGrip)
        SetCanTitanGrip(false);

    if (m_canDualWield)
    {
        if (spellInfo && spellInfo->IsPassive() && spellInfo->HasEffect(SPELL_EFFECT_DUAL_WIELD))
            SetCanDualWield(false);
    }

    if (sWorld->getBoolConfig(CONFIG_OFFHAND_CHECK_AT_SPELL_UNLEARN))
        AutoUnequipOffhandIfNeed();

    // remove from spell book if not replaced by lesser rank
    if (!prev_activate)
    {
        WorldPackets::Spells::UnlearnedSpells unlearnedSpells;
        unlearnedSpells.SpellID.push_back(spell_id);
        SendDirectMessage(unlearnedSpells.Write());
    }
}

void Player::RemoveArenaSpellCooldowns(bool removeActivePetCooldowns)
{
    // remove cooldowns on spells that have < 10 min CD
    GetSpellHistory()->ResetCooldowns([](SpellHistory::CooldownStorageType::iterator itr)
    {
        SpellInfo const* spellInfo = sSpellMgr->AssertSpellInfo(itr->first);
        return spellInfo->RecoveryTime < 10 * MINUTE * IN_MILLISECONDS && spellInfo->CategoryRecoveryTime < 10 * MINUTE * IN_MILLISECONDS;
    }, true);

    // pet cooldowns
    if (removeActivePetCooldowns)
        if (Pet* pet = GetPet())
            pet->GetSpellHistory()->ResetAllCooldowns();
}

uint32 Player::GetNextResetTalentsCost() const
{
    // The first time reset costs 1 gold
    if (GetTalentResetCost() < 1*GOLD)
        return 1*GOLD;
    // then 5 gold
    else if (GetTalentResetCost() < 5*GOLD)
        return 5*GOLD;
    // After that it increases in increments of 5 gold
    else if (GetTalentResetCost() < 10*GOLD)
        return 10*GOLD;
    else
    {
        uint64 months = (sWorld->GetGameTime() - GetTalentResetTime())/MONTH;
        if (months > 0)
        {
            // This cost will be reduced by a rate of 5 gold per month
            int32 new_cost = int32(GetTalentResetCost() - 5*GOLD*months);
            // to a minimum of 10 gold.
            return (new_cost < 10*GOLD ? 10*GOLD : new_cost);
        }
        else
        {
            // After that it increases in increments of 5 gold
            int32 new_cost = GetTalentResetCost() + 5*GOLD;
            // until it hits a cap of 50 gold.
            if (new_cost > 50*GOLD)
                new_cost = 50*GOLD;
            return new_cost;
        }
    }
}

bool Player::ResetTalents(bool noCost)
{
    sScriptMgr->OnPlayerTalentsReset(this, noCost);

    // not need after this call
    if (HasAtLoginFlag(AT_LOGIN_RESET_TALENTS))
        RemoveAtLoginFlag(AT_LOGIN_RESET_TALENTS, true);

    uint32 cost = 0;

    if (!noCost && !sWorld->getBoolConfig(CONFIG_NO_RESET_TALENT_COST))
    {
        cost = GetNextResetTalentsCost();

        if (!HasEnoughMoney(uint64(cost)))
        {
            SendBuyError(BUY_ERR_NOT_ENOUGHT_MONEY, nullptr, 0, 0);
            return false;
        }
    }

    RemovePet(nullptr, PET_SAVE_NOT_IN_SLOT, true);

    for (uint32 talentId = 0; talentId < sTalentStore.GetNumRows(); ++talentId)
    {
        TalentEntry const* talentInfo = sTalentStore.LookupEntry(talentId);
        if (!talentInfo)
            continue;

        // unlearn only talents for character class
        // some spell learned by one class as normal spells or know at creation but another class learn it as talent,
        // to prevent unexpected lost normal learned spell skip another class talents
        if (talentInfo->ClassID != getClass())
            continue;

        // skip non-existent talent ranks
        if (talentInfo->SpellID == 0)
            continue;

        RemoveTalent(talentInfo);
    }

    SQLTransaction trans = CharacterDatabase.BeginTransaction();
    _SaveTalents(trans);
    _SaveSpells(trans);
    CharacterDatabase.CommitTransaction(trans);

    if (!noCost)
    {
        ModifyMoney(-(int64)cost);
        UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_GOLD_SPENT_FOR_TALENTS, cost);
        UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_NUMBER_OF_TALENT_RESETS, 1);

        SetTalentResetCost(cost);
        SetTalentResetTime(time(nullptr));
    }

    /* when prev line will dropped use next line
    if (Pet* pet = GetPet())
    {
        if (pet->getPetType() == HUNTER_PET && !pet->GetCreatureTemplate()->IsTameable(CanTameExoticPets()))
            RemovePet(NULL, PET_SAVE_NOT_IN_SLOT, true);
    }
    */

    return true;
}

Mail* Player::GetMail(uint32 id)
{
    for (PlayerMails::iterator itr = m_mail.begin(); itr != m_mail.end(); ++itr)
        if ((*itr)->messageID == id)
            return (*itr);

    return nullptr;
}

void Player::BuildCreateUpdateBlockForPlayer(UpdateData* data, Player* target) const
{
    if (target == this)
    {
        for (uint8 i = 0; i < EQUIPMENT_SLOT_END; ++i)
        {
            if (m_items[i] == nullptr)
                continue;

            m_items[i]->BuildCreateUpdateBlockForPlayer(data, target);
        }

        for (uint8 i = INVENTORY_SLOT_BAG_START; i < BANK_SLOT_BAG_END; ++i)
        {
            if (m_items[i] == nullptr)
                continue;

            m_items[i]->BuildCreateUpdateBlockForPlayer(data, target);
        }
    }

    Unit::BuildCreateUpdateBlockForPlayer(data, target);
}

void Player::DestroyForPlayer(Player* target) const
{
    Unit::DestroyForPlayer(target);

    for (uint8 i = 0; i < INVENTORY_SLOT_BAG_END; ++i)
    {
        if (m_items[i] == nullptr)
            continue;

        m_items[i]->DestroyForPlayer(target);
    }

    if (target == this)
    {
        for (uint8 i = INVENTORY_SLOT_BAG_START; i < BANK_SLOT_BAG_END; ++i)
        {
            if (m_items[i] == nullptr)
                continue;

            m_items[i]->DestroyForPlayer(target);
        }
    }
}

bool Player::HasSpell(uint32 spell) const
{
    PlayerSpellMap::const_iterator itr = m_spells.find(spell);
    return (itr != m_spells.end() && itr->second->state != PLAYERSPELL_REMOVED &&
        !itr->second->disabled);
}

bool Player::HasTalent(uint32 talentId, uint8 group) const
{
    PlayerTalentMap::const_iterator itr = GetTalentMap(group)->find(talentId);
    return (itr != GetTalentMap(group)->end() && itr->second != PLAYERSPELL_REMOVED);
}

bool Player::HasActiveSpell(uint32 spell) const
{
    PlayerSpellMap::const_iterator itr = m_spells.find(spell);
    return (itr != m_spells.end() && itr->second->state != PLAYERSPELL_REMOVED &&
        itr->second->active && !itr->second->disabled);
}

TrainerSpellState Player::GetTrainerSpellState(TrainerSpell const* trainer_spell) const
{
    if (!trainer_spell)
        return TRAINER_SPELL_RED;

    bool hasSpell = true;
    for (uint8 i = 0; i < MAX_TRAINERSPELL_ABILITY_REQS; ++i)
    {
        if (!trainer_spell->ReqAbility[i])
            continue;

        if (!HasSpell(trainer_spell->ReqAbility[i]))
        {
            hasSpell = false;
            break;
        }
    }
    // known spell
    if (hasSpell)
        return TRAINER_SPELL_GRAY;

    // check skill requirement
    if (trainer_spell->ReqSkillLine && GetBaseSkillValue(trainer_spell->ReqSkillLine) < trainer_spell->ReqSkillRank)
        return TRAINER_SPELL_RED;

    // check level requirement
    if (getLevel() < trainer_spell->ReqLevel)
        return TRAINER_SPELL_RED;

    for (uint8 i = 0; i < MAX_TRAINERSPELL_ABILITY_REQS; ++i)
    {
        if (!trainer_spell->ReqAbility[i])
            continue;

        // check race/class requirement
        if (!IsSpellFitByClassAndRace(trainer_spell->ReqAbility[i]))
            return TRAINER_SPELL_RED;

        if (uint32 prevSpell = sSpellMgr->GetPrevSpellInChain(trainer_spell->ReqAbility[i]))
        {
            // check prev.rank requirement
            if (prevSpell && !HasSpell(prevSpell))
                return TRAINER_SPELL_RED;
        }

        SpellsRequiringSpellMapBounds spellsRequired = sSpellMgr->GetSpellsRequiredForSpellBounds(trainer_spell->ReqAbility[i]);
        for (SpellsRequiringSpellMap::const_iterator itr = spellsRequired.first; itr != spellsRequired.second; ++itr)
        {
            // check additional spell requirement
            if (!HasSpell(itr->second))
                return TRAINER_SPELL_RED;
        }
    }

    // check primary prof. limit
    // first rank of primary profession spell when there are no professions available is disabled
    for (uint8 i = 0; i < MAX_TRAINERSPELL_ABILITY_REQS; ++i)
    {
        if (!trainer_spell->ReqAbility[i])
            continue;
        SpellInfo const* learnedSpellInfo = sSpellMgr->GetSpellInfo(trainer_spell->ReqAbility[i]);
        if (learnedSpellInfo && learnedSpellInfo->IsPrimaryProfessionFirstRank() && (GetFreePrimaryProfessionPoints() == 0))
            return TRAINER_SPELL_GREEN_DISABLED;
    }

    return TRAINER_SPELL_GREEN;
}

/**
 * Deletes a character from the database
 *
 * The way characters will be deleted is decided based on the config option.
 *
 * @see Player::DeleteOldCharacters
 *
 * @param playerguid       the low-GUID from the player which should be deleted
 * @param accountId        the account id from the player
 * @param updateRealmChars when this flag is set, the amount of characters on that realm will be updated in the realmlist
 * @param deleteFinally    if this flag is set, the config option will be ignored and the character will be permanently removed from the database
 */
void Player::DeleteFromDB(ObjectGuid playerguid, uint32 accountId, bool updateRealmChars, bool deleteFinally)
{
    // Avoid realm-update for non-existing account
    if (accountId == 0)
        updateRealmChars = false;

    // Convert guid to low GUID for CharacterNameData, but also other methods on success
    ObjectGuid::LowType guid = playerguid.GetCounter();
    uint32 charDeleteMethod = sWorld->getIntConfig(CONFIG_CHARDELETE_METHOD);

    if (deleteFinally)
        charDeleteMethod = CHAR_DELETE_REMOVE;
    else if (CharacterInfo const* characterInfo = sWorld->GetCharacterInfo(playerguid)) // To avoid a query, we select loaded data. If it doesn't exist, return.
    {
        // Define the required variables
        uint32 charDeleteMinLvl = sWorld->getIntConfig(characterInfo->Class != CLASS_DEATH_KNIGHT ? CONFIG_CHARDELETE_MIN_LEVEL : CONFIG_CHARDELETE_HEROIC_MIN_LEVEL);

        // if we want to finalize the character removal or the character does not meet the level requirement of either heroic or non-heroic settings,
        // we set it to mode CHAR_DELETE_REMOVE
        if (characterInfo->Level < charDeleteMinLvl)
            charDeleteMethod = CHAR_DELETE_REMOVE;
    }

    if (ObjectGuid::LowType guildId = GetGuildIdFromDB(playerguid))
        if (Guild* guild = sGuildMgr->GetGuildById(guildId))
            guild->DeleteMember(playerguid, false, false, true);

    // remove from arena teams
    LeaveAllArenaTeams(playerguid);

    // the player was uninvited already on logout so just remove from group
    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_GROUP_MEMBER);
    stmt->setUInt64(0, guid);
    PreparedQueryResult resultGroup = CharacterDatabase.Query(stmt);

    if (resultGroup)
        if (Group* group = sGroupMgr->GetGroupByDbStoreId((*resultGroup)[0].GetUInt32()))
            RemoveFromGroup(group, playerguid);

    // Remove signs from petitions (also remove petitions if owner);
    RemovePetitionsAndSigns(playerguid);

    switch (charDeleteMethod)
    {
        // Completely remove from the database
        case CHAR_DELETE_REMOVE:
        {
            SQLTransaction trans = CharacterDatabase.BeginTransaction();

            stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHAR_COD_ITEM_MAIL);
            stmt->setUInt64(0, guid);
            PreparedQueryResult resultMail = CharacterDatabase.Query(stmt);

            if (resultMail)
            {
                do
                {
                    Field* mailFields = resultMail->Fetch();

                    uint32 mail_id       = mailFields[0].GetUInt32();
                    uint8 mailType       = mailFields[1].GetUInt8();
                    uint16 mailTemplateId= mailFields[2].GetUInt16();
                    ObjectGuid::LowType sender = mailFields[3].GetUInt64();
                    std::string subject  = mailFields[4].GetString();
                    std::string body     = mailFields[5].GetString();
                    uint64 money         = mailFields[6].GetUInt64();
                    bool has_items       = mailFields[7].GetBool();

                    // We can return mail now
                    // So firstly delete the old one
                    stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_MAIL_BY_ID);
                    stmt->setUInt32(0, mail_id);
                    trans->Append(stmt);

                    // Mail is not from player
                    if (mailType != MAIL_NORMAL)
                    {
                        if (has_items)
                        {
                            stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_MAIL_ITEM_BY_ID);
                            stmt->setUInt32(0, mail_id);
                            trans->Append(stmt);
                        }
                        continue;
                    }

                    MailDraft draft(subject, body);
                    if (mailTemplateId)
                        draft = MailDraft(mailTemplateId, false);    // items are already included

                    if (has_items)
                    {
                        // Data needs to be at first place for Item::LoadFromDB
                        stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_MAILITEMS);
                        stmt->setUInt32(0, mail_id);
                        PreparedQueryResult resultItems = CharacterDatabase.Query(stmt);
                        if (resultItems)
                        {
                            do
                            {
                                Field* itemFields = resultItems->Fetch();
                                ObjectGuid::LowType itemGuidLow = itemFields[0].GetUInt64();
                                uint32 itemEntry = itemFields[1].GetUInt32();

                                ItemTemplate const* itemProto = sObjectMgr->GetItemTemplate(itemEntry);
                                if (!itemProto)
                                {
                                    stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_ITEM_INSTANCE);
                                    stmt->setUInt64(0, itemGuidLow);
                                    trans->Append(stmt);
                                    continue;
                                }

                                Item* item = NewItemOrBag(itemProto);
                                if (!item->LoadFromDB(itemGuidLow, playerguid, itemFields, itemEntry))
                                {
                                    item->FSetState(ITEM_REMOVED);
                                    item->SaveToDB(trans);              // it also deletes item object!
                                    continue;
                                }

                                draft.AddItem(item);
                            }
                            while (resultItems->NextRow());
                        }
                    }

                    stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_MAIL_ITEM_BY_ID);
                    stmt->setUInt32(0, mail_id);
                    trans->Append(stmt);

                    uint32 pl_account = ObjectMgr::GetPlayerAccountIdByGUID(playerguid);

                    draft.AddMoney(money).SendReturnToSender(pl_account, guid, sender, trans);
                }
                while (resultMail->NextRow());
            }

            // Unsummon and delete for pets in world is not required: player deleted from CLI or character list with not loaded pet.
            // NOW we can finally clear other DB data related to character
            stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHAR_PETS);
            stmt->setUInt64(0, guid);
            PreparedQueryResult resultPets = CharacterDatabase.Query(stmt);

            if (resultPets)
            {
                do
                {
                    uint32 petguidlow = (*resultPets)[0].GetUInt32();
                    Pet::DeleteFromDB(petguidlow);
                } while (resultPets->NextRow());
            }

            // Delete char from social list of online chars
            stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHAR_SOCIAL);
            stmt->setUInt64(0, guid);

            if (PreparedQueryResult resultFriends = CharacterDatabase.Query(stmt))
            {
                do
                {
                    if (Player* playerFriend = ObjectAccessor::FindPlayer(ObjectGuid::Create<HighGuid::Player>((*resultFriends)[0].GetUInt64())))
                    {
                        playerFriend->GetSocial()->RemoveFromSocialList(playerguid, SOCIAL_FLAG_ALL);
                        sSocialMgr->SendFriendStatus(playerFriend, FRIEND_REMOVED, playerguid);
                    }
                } while (resultFriends->NextRow());
            }

            stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHARACTER);
            stmt->setUInt64(0, guid);
            trans->Append(stmt);

            stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_PLAYER_ACCOUNT_DATA);
            stmt->setUInt64(0, guid);
            trans->Append(stmt);

            stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHAR_DECLINED_NAME);
            stmt->setUInt64(0, guid);
            trans->Append(stmt);

            stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHAR_ACTION);
            stmt->setUInt64(0, guid);
            trans->Append(stmt);

            stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHARACTER_ARENA_STATS);
            stmt->setUInt64(0, guid);
            trans->Append(stmt);

            stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHAR_AURA_EFFECT);
            stmt->setUInt64(0, guid);
            trans->Append(stmt);

            stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHAR_AURA);
            stmt->setUInt64(0, guid);
            trans->Append(stmt);

            stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_PLAYER_BGDATA);
            stmt->setUInt64(0, guid);
            trans->Append(stmt);

            stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_BATTLEGROUND_RANDOM);
            stmt->setUInt64(0, guid);
            trans->Append(stmt);

            stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHAR_CUF_PROFILES);
            stmt->setUInt64(0, guid);
            trans->Append(stmt);

            stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_PLAYER_CURRENCY);
            stmt->setUInt64(0, guid);
            trans->Append(stmt);

            stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHAR_GIFT);
            stmt->setUInt64(0, guid);
            trans->Append(stmt);

            stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_PLAYER_HOMEBIND);
            stmt->setUInt64(0, guid);
            trans->Append(stmt);

            stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHAR_INSTANCE);
            stmt->setUInt64(0, guid);
            trans->Append(stmt);

            stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHAR_INVENTORY);
            stmt->setUInt64(0, guid);
            trans->Append(stmt);

            stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHAR_QUESTSTATUS);
            stmt->setUInt64(0, guid);
            trans->Append(stmt);

            stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHAR_QUESTSTATUS_OBJECTIVES);
            stmt->setUInt64(0, guid);
            trans->Append(stmt);

            stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHAR_QUESTSTATUS_REWARDED);
            stmt->setUInt64(0, guid);
            trans->Append(stmt);

            stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHAR_REPUTATION);
            stmt->setUInt64(0, guid);
            trans->Append(stmt);

            stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHAR_SPELL);
            stmt->setUInt64(0, guid);
            trans->Append(stmt);

            stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHAR_SPELL_COOLDOWNS);
            stmt->setUInt64(0, guid);
            trans->Append(stmt);

            stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHAR_SPELL_CHARGES);
            stmt->setUInt64(0, guid);
            trans->Append(stmt);

            stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_ITEM_INSTANCE_BY_OWNER);
            stmt->setUInt64(0, guid);
            trans->Append(stmt);

            stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHAR_SOCIAL_BY_FRIEND);
            stmt->setUInt64(0, guid);
            trans->Append(stmt);

            stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHAR_SOCIAL_BY_GUID);
            stmt->setUInt64(0, guid);
            trans->Append(stmt);

            stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_MAIL);
            stmt->setUInt64(0, guid);
            trans->Append(stmt);

            stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_MAIL_ITEMS);
            stmt->setUInt64(0, guid);
            trans->Append(stmt);

            stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHAR_PET_BY_OWNER);
            stmt->setUInt64(0, guid);
            trans->Append(stmt);

            stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHAR_PET_DECLINEDNAME_BY_OWNER);
            stmt->setUInt64(0, guid);
            trans->Append(stmt);

            stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHAR_ACHIEVEMENTS);
            stmt->setUInt64(0, guid);
            trans->Append(stmt);

            stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHAR_ACHIEVEMENT_PROGRESS);
            stmt->setUInt64(0, guid);
            trans->Append(stmt);

            stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHAR_EQUIPMENTSETS);
            stmt->setUInt64(0, guid);
            trans->Append(stmt);

            stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_GUILD_EVENTLOG_BY_PLAYER);
            stmt->setUInt64(0, guid);
            stmt->setUInt64(1, guid);
            trans->Append(stmt);

            stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_GUILD_BANK_EVENTLOG_BY_PLAYER);
            stmt->setUInt64(0, guid);
            trans->Append(stmt);

            stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHAR_GLYPHS);
            stmt->setUInt64(0, guid);
            trans->Append(stmt);

            stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHARACTER_QUESTSTATUS_DAILY);
            stmt->setUInt64(0, guid);
            trans->Append(stmt);

            stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHARACTER_QUESTSTATUS_WEEKLY);
            stmt->setUInt64(0, guid);
            trans->Append(stmt);

            stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHARACTER_QUESTSTATUS_MONTHLY);
            stmt->setUInt64(0, guid);
            trans->Append(stmt);

            stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHARACTER_QUESTSTATUS_SEASONAL);
            stmt->setUInt64(0, guid);
            trans->Append(stmt);

            stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHAR_TALENT);
            stmt->setUInt64(0, guid);
            trans->Append(stmt);

            stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHAR_SKILLS);
            stmt->setUInt64(0, guid);
            trans->Append(stmt);

            stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHAR_STATS);
            stmt->setUInt64(0, guid);
            trans->Append(stmt);

            stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHAR_VOID_STORAGE_ITEM_BY_CHAR_GUID);
            stmt->setUInt64(0, guid);
            trans->Append(stmt);

            Corpse::DeleteFromDB(playerguid, trans);

            Garrison::DeleteFromDB(guid, trans);

            CharacterDatabase.CommitTransaction(trans);

            sWorld->DeleteCharacterInfo(playerguid);
            break;
        }
        // The character gets unlinked from the account, the name gets freed up and appears as deleted ingame
        case CHAR_DELETE_UNLINK:
        {
            stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_DELETE_INFO);
            stmt->setUInt64(0, guid);

            CharacterDatabase.Execute(stmt);

            sWorld->UpdateCharacterInfoDeleted(playerguid, true);
            break;
        }
        default:
            TC_LOG_ERROR("entities.player", "Player::DeleteFromDB: Tried to delete player (%s) with unsupported delete method (%u).",
                playerguid.ToString().c_str(), charDeleteMethod);
            return;
    }

    if (updateRealmChars)
        sWorld->UpdateRealmCharCount(accountId);
}

/**
 * Characters which were kept back in the database after being deleted and are now too old (see config option "CharDelete.KeepDays"), will be completely deleted.
 *
 * @see Player::DeleteFromDB
 */
void Player::DeleteOldCharacters()
{
    uint32 keepDays = sWorld->getIntConfig(CONFIG_CHARDELETE_KEEP_DAYS);
    if (!keepDays)
        return;

    Player::DeleteOldCharacters(keepDays);
}

/**
 * Characters which were kept back in the database after being deleted and are older than the specified amount of days, will be completely deleted.
 *
 * @see Player::DeleteFromDB
 *
 * @param keepDays overwrite the config option by another amount of days
 */
void Player::DeleteOldCharacters(uint32 keepDays)
{
    TC_LOG_INFO("entities.player", "Player::DeleteOldCharacters: Deleting all characters which have been deleted %u days before...", keepDays);

    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHAR_OLD_CHARS);
    stmt->setUInt32(0, uint32(time(nullptr) - time_t(keepDays * DAY)));
    PreparedQueryResult result = CharacterDatabase.Query(stmt);

    if (result)
    {
         TC_LOG_DEBUG("entities.player", "Player::DeleteOldCharacters: Found " UI64FMTD " character(s) to delete", result->GetRowCount());
         do
         {
            Field* fields = result->Fetch();
            Player::DeleteFromDB(ObjectGuid::Create<HighGuid::Player>(fields[0].GetUInt64()), fields[1].GetUInt32(), true, true);
         }
         while (result->NextRow());
    }
}

/* Preconditions:
  - a resurrectable corpse must not be loaded for the player (only bones)
  - the player must be in world
*/
void Player::BuildPlayerRepop()
{
    WorldPackets::Misc::PreRessurect packet;
    packet.PlayerGUID = GetGUID();
    GetSession()->SendPacket(packet.Write());

    if (getRace() == RACE_NIGHTELF)
        CastSpell(this, 20584, true);
    CastSpell(this, 8326, true);

    // there must be SMSG.FORCE_RUN_SPEED_CHANGE, SMSG.FORCE_SWIM_SPEED_CHANGE, SMSG.MOVE_SET_WATER_WALK
    // there must be SMSG.STOP_MIRROR_TIMER

    // the player cannot have a corpse already on current map, only bones which are not returned by GetCorpse
    WorldLocation corpseLocation = GetCorpseLocation();
    if (corpseLocation.GetMapId() == GetMapId())
    {
        TC_LOG_ERROR("entities.player", "Player::BuildPlayerRepop: Player '%s' (%s) already has a corpse", GetName().c_str(), GetGUID().ToString().c_str());
        return;
    }

    // create a corpse and place it at the player's location
    Corpse* corpse = CreateCorpse();
    if (!corpse)
    {
        TC_LOG_ERROR("entities.player", "Player::BuildPlayerRepop: Error creating corpse for player '%s' (%s)", GetName().c_str(), GetGUID().ToString().c_str());
        return;
    }
    GetMap()->AddToMap(corpse);

    // convert player body to ghost
    SetHealth(1);

    SetWaterWalking(true);
    if (!GetSession()->isLogingOut() && !HasUnitState(UNIT_STATE_STUNNED))
        SetRooted(false);

    // BG - remove insignia related
    RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_SKINNABLE);

    int32 corpseReclaimDelay = CalculateCorpseReclaimDelay();

    if (corpseReclaimDelay >= 0)
        SendCorpseReclaimDelay(corpseReclaimDelay);

    // to prevent cheating
    corpse->ResetGhostTime();

    StopMirrorTimers();                                     //disable timers(bars)

    // set and clear other
    SetByteValue(UNIT_FIELD_BYTES_1, 3, UNIT_BYTE1_FLAG_ALWAYS_STAND);
}

void Player::ResurrectPlayer(float restore_percent, bool applySickness)
{
    WorldPackets::Misc::DeathReleaseLoc packet;
    packet.MapID = -1;
    GetSession()->SendPacket(packet.Write());

    // speed change, land walk

    // remove death flag + set aura
    SetByteValue(UNIT_FIELD_BYTES_1, 3, 0x00);
    RemoveFlag(PLAYER_FLAGS, PLAYER_FLAGS_IS_OUT_OF_BOUNDS);

    // This must be called always even on Players with race != RACE_NIGHTELF in case of faction change
    RemoveAurasDueToSpell(20584);                           // RACE_NIGHTELF speed bonuses
    RemoveAurasDueToSpell(8326);                            // SPELL_AURA_GHOST

    if (GetSession()->IsARecruiter() || (GetSession()->GetRecruiterId() != 0))
        SetFlag(OBJECT_DYNAMIC_FLAGS, UNIT_DYNFLAG_REFER_A_FRIEND);

    setDeathState(ALIVE);

    SetWaterWalking(false, true);
    if (!HasUnitState(UNIT_STATE_STUNNED))
        SetRooted(false);

    m_deathTimer = 0;

    // set health/powers (0- will be set in caller)
    if (restore_percent > 0.0f)
    {
        SetHealth(uint32(GetMaxHealth()*restore_percent));
        SetPower(POWER_MANA, uint32(GetMaxPower(POWER_MANA)*restore_percent));
        SetPower(POWER_RAGE, 0);
        SetPower(POWER_ENERGY, uint32(GetMaxPower(POWER_ENERGY)*restore_percent));
        SetPower(POWER_FOCUS, uint32(GetMaxPower(POWER_FOCUS)*restore_percent));
        SetPower(POWER_ECLIPSE, 0);
    }

    // trigger update zone for alive state zone updates
    uint32 newzone, newarea;
    GetZoneAndAreaId(newzone, newarea);
    UpdateZone(newzone, newarea);
    sOutdoorPvPMgr->HandlePlayerResurrects(this, newzone);

    if (InBattleground())
    {
        if (Battleground* bg = GetBattleground())
            bg->HandlePlayerResurrect(this);
    }

    // update visibility
    UpdateObjectVisibility();

    if (!applySickness)
        return;

    //Characters from level 1-10 are not affected by resurrection sickness.
    //Characters from level 11-19 will suffer from one minute of sickness
    //for each level they are above 10.
    //Characters level 20 and up suffer from ten minutes of sickness.
    int32 startLevel = sWorld->getIntConfig(CONFIG_DEATH_SICKNESS_LEVEL);

    if (int32(getLevel()) >= startLevel)
    {
        // set resurrection sickness
        CastSpell(this, 15007, true);

        // not full duration
        if (int32(getLevel()) < startLevel+9)
        {
            int32 delta = (int32(getLevel()) - startLevel + 1)*MINUTE;

            if (Aura* aur = GetAura(15007, GetGUID()))
            {
                aur->SetDuration(delta*IN_MILLISECONDS);
            }
        }
    }
}

void Player::KillPlayer()
{
    if (IsFlying() && !GetTransport())
        GetMotionMaster()->MoveFall();

    SetRooted(true);

    StopMirrorTimers();                                     //disable timers(bars)

    setDeathState(CORPSE);
    //SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_IN_PVP);

    SetUInt32Value(OBJECT_DYNAMIC_FLAGS, UNIT_DYNFLAG_NONE);
    ApplyModFlag(PLAYER_FIELD_LOCAL_FLAGS, PLAYER_LOCAL_FLAG_RELEASE_TIMER, !sMapStore.LookupEntry(GetMapId())->Instanceable() && !HasAuraType(SPELL_AURA_PREVENT_RESURRECTION));

    // 6 minutes until repop at graveyard
    m_deathTimer = 6 * MINUTE * IN_MILLISECONDS;

    UpdateCorpseReclaimDelay();                             // dependent at use SetDeathPvP() call before kill

    int32 corpseReclaimDelay = CalculateCorpseReclaimDelay();

    if (corpseReclaimDelay >= 0)
        SendCorpseReclaimDelay(corpseReclaimDelay);

    // don't create corpse at this moment, player might be falling

    // update visibility
    UpdateObjectVisibility();
}

void Player::OfflineResurrect(ObjectGuid const& guid, SQLTransaction& trans)
{
    Corpse::DeleteFromDB(guid, trans);
    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_ADD_AT_LOGIN_FLAG);
    stmt->setUInt16(0, uint16(AT_LOGIN_RESURRECT));
    stmt->setUInt64(1, guid.GetCounter());
    CharacterDatabase.ExecuteOrAppend(trans, stmt);
}

Corpse* Player::CreateCorpse()
{
    // prevent existence 2 corpse for player
    SpawnCorpseBones();

    uint32 _cfb1, _cfb2;

    Corpse* corpse = new Corpse((m_ExtraFlags & PLAYER_EXTRA_PVP_DEATH) ? CORPSE_RESURRECTABLE_PVP : CORPSE_RESURRECTABLE_PVE);
    SetPvPDeath(false);

    if (!corpse->Create(GetMap()->GenerateLowGuid<HighGuid::Corpse>(), this))
    {
        delete corpse;
        return nullptr;
    }

    _corpseLocation.WorldRelocate(*this);

    uint8 skin = GetByteValue(PLAYER_BYTES, PLAYER_BYTES_OFFSET_SKIN_ID);
    uint8 face = GetByteValue(PLAYER_BYTES, PLAYER_BYTES_OFFSET_FACE_ID);
    uint8 hairstyle = GetByteValue(PLAYER_BYTES, PLAYER_BYTES_OFFSET_HAIR_STYLE_ID);
    uint8 haircolor = GetByteValue(PLAYER_BYTES, PLAYER_BYTES_OFFSET_HAIR_COLOR_ID);
    uint8 facialhair = GetByteValue(PLAYER_BYTES_2, PLAYER_BYTES_2_OFFSET_FACIAL_STYLE);

    _cfb1 = ((0x00) | (getRace() << 8) | (GetByteValue(PLAYER_BYTES_3, PLAYER_BYTES_3_OFFSET_GENDER) << 16) | (skin << 24));
    _cfb2 = ((face) | (hairstyle << 8) | (haircolor << 16) | (facialhair << 24));

    corpse->SetUInt32Value(CORPSE_FIELD_BYTES_1, _cfb1);
    corpse->SetUInt32Value(CORPSE_FIELD_BYTES_2, _cfb2);

    uint32 flags = CORPSE_FLAG_UNK2;
    if (HasFlag(PLAYER_FLAGS, PLAYER_FLAGS_HIDE_HELM))
        flags |= CORPSE_FLAG_HIDE_HELM;
    if (HasFlag(PLAYER_FLAGS, PLAYER_FLAGS_HIDE_CLOAK))
        flags |= CORPSE_FLAG_HIDE_CLOAK;
    if (InBattleground() && !InArena())
        flags |= CORPSE_FLAG_LOOTABLE;                      // to be able to remove insignia

    corpse->SetUInt32Value(CORPSE_FIELD_FLAGS, flags);
    corpse->SetUInt32Value(CORPSE_FIELD_DISPLAY_ID, GetNativeDisplayId());

    uint32 iDisplayID;
    uint32 iIventoryType;
    uint32 _cfi;
    for (uint8 i = 0; i < EQUIPMENT_SLOT_END; i++)
    {
        if (m_items[i])
        {
            iDisplayID = m_items[i]->GetDisplayId();
            iIventoryType = m_items[i]->GetTemplate()->GetInventoryType();

            _cfi = iDisplayID | (iIventoryType << 24);
            corpse->SetUInt32Value(CORPSE_FIELD_ITEM + i, _cfi);
        }
    }

    // register for player, but not show
    GetMap()->AddCorpse(corpse);

    // we do not need to save corpses for BG/arenas
    if (!GetMap()->IsBattlegroundOrArena())
        corpse->SaveToDB();

    return corpse;
}

void Player::SpawnCorpseBones(bool triggerSave /*= true*/)
{
    _corpseLocation.WorldRelocate();
    if (GetMap()->ConvertCorpseToBones(GetGUID()))
        if (triggerSave && !GetSession()->PlayerLogoutWithSave())   // at logout we will already store the player
            SaveToDB();                                             // prevent loading as ghost without corpse
}

Corpse* Player::GetCorpse() const
{
    return GetMap()->GetCorpseByPlayer(GetGUID());
}

void Player::DurabilityLossAll(double percent, bool inventory)
{
    for (uint8 i = EQUIPMENT_SLOT_START; i < EQUIPMENT_SLOT_END; i++)
        if (Item* pItem = GetItemByPos(INVENTORY_SLOT_BAG_0, i))
            DurabilityLoss(pItem, percent);

    if (inventory)
    {
        // bags not have durability
        // for (int i = INVENTORY_SLOT_BAG_START; i < INVENTORY_SLOT_BAG_END; i++)

        for (uint8 i = INVENTORY_SLOT_ITEM_START; i < INVENTORY_SLOT_ITEM_END; i++)
            if (Item* pItem = GetItemByPos(INVENTORY_SLOT_BAG_0, i))
                DurabilityLoss(pItem, percent);

        for (uint8 i = INVENTORY_SLOT_BAG_START; i < INVENTORY_SLOT_BAG_END; i++)
            if (Bag* pBag = GetBagByPos(i))
                for (uint32 j = 0; j < pBag->GetBagSize(); j++)
                    if (Item* pItem = GetItemByPos(i, j))
                        DurabilityLoss(pItem, percent);
    }
}

void Player::DurabilityLoss(Item* item, double percent)
{
    if (!item)
        return;

    uint32 pMaxDurability = item ->GetUInt32Value(ITEM_FIELD_MAXDURABILITY);

    if (!pMaxDurability)
        return;

    percent /= GetTotalAuraMultiplier(SPELL_AURA_MOD_DURABILITY_LOSS);

    uint32 pDurabilityLoss = uint32(pMaxDurability*percent);

    if (pDurabilityLoss < 1)
        pDurabilityLoss = 1;

    DurabilityPointsLoss(item, pDurabilityLoss);
}

void Player::DurabilityPointsLossAll(int32 points, bool inventory)
{
    for (uint8 i = EQUIPMENT_SLOT_START; i < EQUIPMENT_SLOT_END; i++)
        if (Item* pItem = GetItemByPos(INVENTORY_SLOT_BAG_0, i))
            DurabilityPointsLoss(pItem, points);

    if (inventory)
    {
        // bags not have durability
        // for (int i = INVENTORY_SLOT_BAG_START; i < INVENTORY_SLOT_BAG_END; i++)

        for (uint8 i = INVENTORY_SLOT_ITEM_START; i < INVENTORY_SLOT_ITEM_END; i++)
            if (Item* pItem = GetItemByPos(INVENTORY_SLOT_BAG_0, i))
                DurabilityPointsLoss(pItem, points);

        for (uint8 i = INVENTORY_SLOT_BAG_START; i < INVENTORY_SLOT_BAG_END; i++)
            if (Bag* pBag = static_cast<Bag*>(GetItemByPos(INVENTORY_SLOT_BAG_0, i)))
                for (uint32 j = 0; j < pBag->GetBagSize(); j++)
                    if (Item* pItem = GetItemByPos(i, j))
                        DurabilityPointsLoss(pItem, points);
    }
}

void Player::DurabilityPointsLoss(Item* item, int32 points)
{
    int32 pMaxDurability = item->GetUInt32Value(ITEM_FIELD_MAXDURABILITY);
    int32 pOldDurability = item->GetUInt32Value(ITEM_FIELD_DURABILITY);
    int32 pNewDurability = pOldDurability - points;

    if (pNewDurability < 0)
        pNewDurability = 0;
    else if (pNewDurability > pMaxDurability)
        pNewDurability = pMaxDurability;

    if (pOldDurability != pNewDurability)
    {
        // modify item stats _before_ Durability set to 0 to pass _ApplyItemMods internal check
        if (pNewDurability == 0 && pOldDurability > 0 && item->IsEquipped())
            _ApplyItemMods(item, item->GetSlot(), false);

        item->SetUInt32Value(ITEM_FIELD_DURABILITY, pNewDurability);

        // modify item stats _after_ restore durability to pass _ApplyItemMods internal check
        if (pNewDurability > 0 && pOldDurability == 0 && item->IsEquipped())
            _ApplyItemMods(item, item->GetSlot(), true);

        item->SetState(ITEM_CHANGED, this);
    }
}

void Player::DurabilityPointLossForEquipSlot(EquipmentSlots slot)
{
    if (Item* pItem = GetItemByPos(INVENTORY_SLOT_BAG_0, slot))
        DurabilityPointsLoss(pItem, 1);
}

uint32 Player::DurabilityRepairAll(bool cost, float discountMod, bool guildBank)
{
    uint32 TotalCost = 0;
    // equipped, backpack, bags itself
    for (uint8 i = EQUIPMENT_SLOT_START; i < INVENTORY_SLOT_ITEM_END; i++)
        TotalCost += DurabilityRepair(((INVENTORY_SLOT_BAG_0 << 8) | i), cost, discountMod, guildBank);

    // bank, buyback and keys not repaired

    // items in inventory bags
    for (uint8 j = INVENTORY_SLOT_BAG_START; j < INVENTORY_SLOT_BAG_END; j++)
        for (uint8 i = 0; i < MAX_BAG_SIZE; i++)
            TotalCost += DurabilityRepair(((j << 8) | i), cost, discountMod, guildBank);
    return TotalCost;
}

uint32 Player::DurabilityRepair(uint16 pos, bool cost, float discountMod, bool guildBank)
{
    Item* item = GetItemByPos(pos);

    uint32 TotalCost = 0;
    if (!item)
        return TotalCost;

    uint32 maxDurability = item->GetUInt32Value(ITEM_FIELD_MAXDURABILITY);
    if (!maxDurability)
        return TotalCost;

    uint32 curDurability = item->GetUInt32Value(ITEM_FIELD_DURABILITY);

    if (cost)
    {
        uint32 LostDurability = maxDurability - curDurability;
        if (LostDurability>0)
        {
            ItemTemplate const* ditemProto = item->GetTemplate();

            DurabilityCostsEntry const* dcost = sDurabilityCostsStore.LookupEntry(ditemProto->GetBaseItemLevel());
            if (!dcost)
            {
                TC_LOG_ERROR("entities.player.items", "Player::DurabilityRepair: Player '%s' (%s) tried to repair an item (ItemID: %u) with invalid item level %u",
                    GetName().c_str(), GetGUID().ToString().c_str(), ditemProto->GetId(), ditemProto->GetBaseItemLevel());
                return TotalCost;
            }

            uint32 dQualitymodEntryId = (ditemProto->GetQuality() + 1) * 2;
            DurabilityQualityEntry const* dQualitymodEntry = sDurabilityQualityStore.LookupEntry(dQualitymodEntryId);
            if (!dQualitymodEntry)
            {
                TC_LOG_ERROR("entities.player.items", "Player::DurabilityRepair: Player '%s' (%s) tried to repair an item (ItemID: %u) with invalid QualitymodEntry %u",
                    GetName().c_str(), GetGUID().ToString().c_str(), ditemProto->GetId(), dQualitymodEntryId);
                return TotalCost;
            }

            uint32 dmultiplier = 0;
            if (ditemProto->GetClass() == ITEM_CLASS_WEAPON)
                dmultiplier = dcost->WeaponSubClassCost[ditemProto->GetSubClass()];
            else if (ditemProto->GetClass() == ITEM_CLASS_ARMOR)
                dmultiplier = dcost->ArmorSubClassCost[ditemProto->GetSubClass()];

            uint32 costs = uint32(LostDurability * dmultiplier * double(dQualitymodEntry->QualityMod) * item->GetRepairCostMultiplier());

            costs = uint32(costs * discountMod * sWorld->getRate(RATE_REPAIRCOST));

            if (costs == 0)                                   //fix for ITEM_QUALITY_ARTIFACT
                costs = 1;

            if (guildBank)
            {
                if (!GetGuildId())
                {
                    TC_LOG_DEBUG("entities.player.items", "Player::DurabilityRepair: Player '%s' (%s) tried to repair item in a guild bank but is not member of a guild",
                        GetName().c_str(), GetGUID().ToString().c_str());
                    return TotalCost;
                }

                Guild* guild = sGuildMgr->GetGuildById(GetGuildId());
                if (!guild)
                    return TotalCost;

                if (!guild->HandleMemberWithdrawMoney(GetSession(), costs, true))
                    return TotalCost;

                TotalCost = costs;
            }
            else if (!HasEnoughMoney(uint64(costs)))
            {
                TC_LOG_DEBUG("entities.player.items", "Player::DurabilityRepair: Player '%s' (%s) has not enough money to repair item",
                    GetName().c_str(), GetGUID().ToString().c_str());
                return TotalCost;
            }
            else
                ModifyMoney(-int64(costs));
        }
    }

    item->SetUInt32Value(ITEM_FIELD_DURABILITY, maxDurability);
    item->SetState(ITEM_CHANGED, this);

    // reapply mods for total broken and repaired item if equipped
    if (IsEquipmentPos(pos) && !curDurability)
        _ApplyItemMods(item, pos & 255, true);
    return TotalCost;
}

void Player::RepopAtGraveyard()
{
    // note: this can be called also when the player is alive
    // for example from WorldSession::HandleMovementOpcodes

    AreaTableEntry const* zone = sAreaTableStore.LookupEntry(GetAreaId());

    // Such zones are considered unreachable as a ghost and the player must be automatically revived
    if ((!IsAlive() && zone && zone->Flags[0] & AREA_FLAG_NEED_FLY) || GetTransport() || GetPositionZ() < GetMap()->GetMinHeight(GetPositionX(), GetPositionY()))
    {
        ResurrectPlayer(0.5f);
        SpawnCorpseBones();
    }

    WorldSafeLocsEntry const* ClosestGrave;

    // Special handle for battleground maps
    if (Battleground* bg = GetBattleground())
        ClosestGrave = bg->GetClosestGraveYard(this);
    else
    {
        if (Battlefield* bf = sBattlefieldMgr->GetBattlefieldToZoneId(GetZoneId()))
            ClosestGrave = bf->GetClosestGraveYard(this);
        else
            ClosestGrave = sObjectMgr->GetClosestGraveYard(GetPositionX(), GetPositionY(), GetPositionZ(), GetMapId(), GetTeam());
    }

    // stop countdown until repop
    m_deathTimer = 0;

    // if no grave found, stay at the current location
    // and don't show spirit healer location
    if (ClosestGrave)
    {
        TeleportTo(ClosestGrave->MapID, ClosestGrave->Loc.X, ClosestGrave->Loc.Y, ClosestGrave->Loc.Z, (ClosestGrave->Facing * M_PI) / 180); // Orientation is initially in degrees
        if (isDead())                                        // not send if alive, because it used in TeleportTo()
        {
            WorldPackets::Misc::DeathReleaseLoc packet;
            packet.MapID = ClosestGrave->MapID;
            packet.Loc = G3D::Vector3(ClosestGrave->Loc.X, ClosestGrave->Loc.Y, ClosestGrave->Loc.Z);
            GetSession()->SendPacket(packet.Write());
        }
    }
    else if (GetPositionZ() < GetMap()->GetMinHeight(GetPositionX(), GetPositionY()))
        TeleportTo(m_homebindMapId, m_homebindX, m_homebindY, m_homebindZ, GetOrientation());

    RemoveFlag(PLAYER_FLAGS, PLAYER_FLAGS_IS_OUT_OF_BOUNDS);
}

bool Player::CanJoinConstantChannelInZone(ChatChannelsEntry const* channel, AreaTableEntry const* zone) const
{
    if (channel->Flags & CHANNEL_DBC_FLAG_ZONE_DEP && zone->Flags[0] & AREA_FLAG_ARENA_INSTANCE)
        return false;

    if ((channel->Flags & CHANNEL_DBC_FLAG_CITY_ONLY) && (!(zone->Flags[0] & AREA_FLAG_SLAVE_CAPITAL)))
        return false;

    if ((channel->Flags & CHANNEL_DBC_FLAG_GUILD_REQ) && GetGuildId())
        return false;

    return true;
}

void Player::JoinedChannel(Channel* c)
{
    m_channels.push_back(c);
}

void Player::LeftChannel(Channel* c)
{
    m_channels.remove(c);
}

void Player::CleanupChannels()
{
    while (!m_channels.empty())
    {
        Channel* ch = *m_channels.begin();
        m_channels.erase(m_channels.begin());               // remove from player's channel list
        ch->LeaveChannel(this, false);                      // not send to client, not remove from player's channel list
        if (ChannelMgr* cMgr = ChannelMgr::ForTeam(GetTeam()))
            cMgr->LeftChannel(ch->GetName());               // deleted channel if empty
    }
    TC_LOG_DEBUG("chat.system", "Player::CleanupChannels: Channels of player '%s' (%s) cleaned up.", GetName().c_str(), GetGUID().ToString().c_str());
}

void Player::UpdateLocalChannels(uint32 newZone)
{
    if (GetSession()->PlayerLoading() && !IsBeingTeleportedFar())
        return;                                              // The client handles it automatically after loading, but not after teleporting

    AreaTableEntry const* current_zone = sAreaTableStore.LookupEntry(newZone);
    if (!current_zone)
        return;

    ChannelMgr* cMgr = ChannelMgr::ForTeam(GetTeam());
    if (!cMgr)
        return;

    for (uint32 i = 0; i < sChatChannelsStore.GetNumRows(); ++i)
    {
        if (ChatChannelsEntry const* channel = sChatChannelsStore.LookupEntry(i))
        {
            Channel* usedChannel = nullptr;

            for (JoinedChannelsList::iterator itr = m_channels.begin(); itr != m_channels.end(); ++itr)
            {
                if ((*itr)->GetChannelId() == i)
                {
                    usedChannel = *itr;
                    break;
                }
            }

            Channel* removeChannel = nullptr;
            Channel* joinChannel = nullptr;
            bool sendRemove = true;

            if (CanJoinConstantChannelInZone(channel, current_zone))
            {
                if (!(channel->Flags & CHANNEL_DBC_FLAG_GLOBAL))
                {
                    if (channel->Flags & CHANNEL_DBC_FLAG_CITY_ONLY && usedChannel)
                        continue;                            // Already on the channel, as city channel names are not changing

                    char new_channel_name_buf[100];
                    char const* currentNameExt;

                    if (channel->Flags & CHANNEL_DBC_FLAG_CITY_ONLY)
                        currentNameExt = sObjectMgr->GetTrinityStringForDBCLocale(LANG_CHANNEL_CITY);
                    else
                        currentNameExt = current_zone->AreaName_lang;

                    snprintf(new_channel_name_buf, 100, channel->Name_lang, currentNameExt);

                    joinChannel = cMgr->GetJoinChannel(new_channel_name_buf, channel->ID);
                    if (usedChannel)
                    {
                        if (joinChannel != usedChannel)
                        {
                            removeChannel = usedChannel;
                            sendRemove = false;              // Do not send leave channel, it already replaced at client
                        }
                        else
                            joinChannel = nullptr;
                    }
                }
                else
                    joinChannel = cMgr->GetJoinChannel(channel->Name_lang, channel->ID);
            }
            else
                removeChannel = usedChannel;

            if (joinChannel)
                joinChannel->JoinChannel(this, "");          // Changed Channel: ... or Joined Channel: ...

            if (removeChannel)
            {
                removeChannel->LeaveChannel(this, sendRemove); // Leave old channel
                std::string name = removeChannel->GetName(); // Store name, (*i)erase in LeftChannel
                LeftChannel(removeChannel);                  // Remove from player's channel list
                cMgr->LeftChannel(name);                     // Delete if empty
            }
        }
    }
}

void Player::LeaveLFGChannel()
{
    for (JoinedChannelsList::iterator i = m_channels.begin(); i != m_channels.end(); ++i)
    {
        if ((*i)->IsLFG())
        {
            (*i)->LeaveChannel(this);
            break;
        }
    }
}

void Player::HandleBaseModValue(BaseModGroup modGroup, BaseModType modType, float amount, bool apply)
{
    if (modGroup >= BASEMOD_END || modType >= MOD_END)
    {
        TC_LOG_ERROR("spells", "Player::HandleBaseModValue: Invalid BaseModGroup/BaseModType (%u/%u) for player '%s' (%s)",
            modGroup, modType, GetName().c_str(), GetGUID().ToString().c_str());
        return;
    }

    if (modType == FLAT_MOD)
        m_auraBaseMod[modGroup][modType] += apply ? amount : -amount;
    else // PCT_MOD
        ApplyPercentModFloatVar(m_auraBaseMod[modGroup][modType], amount, apply);

    if (!CanModifyStats())
        return;

    switch (modGroup)
    {
        case CRIT_PERCENTAGE:              UpdateCritPercentage(BASE_ATTACK);                          break;
        case RANGED_CRIT_PERCENTAGE:       UpdateCritPercentage(RANGED_ATTACK);                        break;
        case OFFHAND_CRIT_PERCENTAGE:      UpdateCritPercentage(OFF_ATTACK);                           break;
        default: break;
    }
}

float Player::GetBaseModValue(BaseModGroup modGroup, BaseModType modType) const
{
    if (modGroup >= BASEMOD_END || modType >= MOD_END)
    {
        TC_LOG_ERROR("spells", "Player::GetBaseModValue: Invalid BaseModGroup/BaseModType (%u/%u) for player '%s' (%s)",
            modGroup, modType, GetName().c_str(), GetGUID().ToString().c_str());
        return 0.0f;
    }

    if (modType == PCT_MOD && m_auraBaseMod[modGroup][PCT_MOD] <= 0.0f)
        return 0.0f;

    return m_auraBaseMod[modGroup][modType];
}

float Player::GetTotalBaseModValue(BaseModGroup modGroup) const
{
    if (modGroup >= BASEMOD_END)
    {
        TC_LOG_ERROR("spells", "Player::GetTotalBaseModValue: Invalid BaseModGroup (%u) for player '%s' (%s)",
            modGroup, GetName().c_str(), GetGUID().ToString().c_str());
        return 0.0f;
    }

    if (m_auraBaseMod[modGroup][PCT_MOD] <= 0.0f)
        return 0.0f;

    return m_auraBaseMod[modGroup][FLAT_MOD] * m_auraBaseMod[modGroup][PCT_MOD];
}

float Player::GetMeleeCritFromAgility() const
{
    uint8 level = getLevel();
    uint32 pclass = getClass();

    if (level >= sGtChanceToMeleeCritStore.GetTableRowCount())
        level = sGtChanceToMeleeCritStore.GetTableRowCount() - 1;

    GtChanceToMeleeCritBaseEntry const* critBase = sGtChanceToMeleeCritBaseStore.EvaluateTable(pclass - 1, 0);
    GtChanceToMeleeCritEntry     const* critRatio = sGtChanceToMeleeCritStore.EvaluateTable(level - 1, pclass - 1);
    if (critBase == nullptr || critRatio == nullptr)
        return 0.0f;

    float crit = critBase->base + GetStat(STAT_AGILITY)*critRatio->ratio;
    return crit*100.0f;
}

void Player::GetDodgeFromAgility(float &diminishing, float &nondiminishing) const
{
    // Table for base dodge values
    const float dodge_base[MAX_CLASSES] =
    {
         0.037580f, // Warrior
         0.036520f, // Paladin
        -0.054500f, // Hunter
        -0.005900f, // Rogue
         0.031830f, // Priest
         0.036640f, // DK
         0.016750f, // Shaman
         0.034575f, // Mage
         0.020350f, // Warlock
         0.0f,      // ??
         0.049510f  // Druid
    };
    // Crit/agility to dodge/agility coefficient multipliers; 3.2.0 increased required agility by 15%
    const float crit_to_dodge[MAX_CLASSES] =
    {
         0.85f/1.15f,    // Warrior
         1.00f/1.15f,    // Paladin
         1.11f/1.15f,    // Hunter
         2.00f/1.15f,    // Rogue
         1.00f/1.15f,    // Priest
         0.85f/1.15f,    // DK
         1.60f/1.15f,    // Shaman
         1.00f/1.15f,    // Mage
         0.97f/1.15f,    // Warlock (?)
         0.0f,           // ??
         2.00f/1.15f     // Druid
    };

    uint8 level = getLevel();
    uint32 pclass = getClass();

    if (level >= sGtChanceToMeleeCritStore.GetTableRowCount())
        level = sGtChanceToMeleeCritStore.GetTableRowCount() - 1;

    // Dodge per agility is proportional to crit per agility, which is available from DBC files
    GtChanceToMeleeCritEntry  const* dodgeRatio = sGtChanceToMeleeCritStore.EvaluateTable(level - 1, pclass - 1);
    if (dodgeRatio == nullptr || pclass > MAX_CLASSES)
        return;

    /// @todo research if talents/effects that increase total agility by x% should increase non-diminishing part
    float base_agility = GetCreateStat(STAT_AGILITY) * m_auraModifiersGroup[UNIT_MOD_STAT_START + STAT_AGILITY][BASE_PCT];
    float bonus_agility = GetStat(STAT_AGILITY) - base_agility;

    // calculate diminishing (green in char screen) and non-diminishing (white) contribution
    diminishing = 100.0f * bonus_agility * dodgeRatio->ratio * crit_to_dodge[pclass-1];
    nondiminishing = 100.0f * (dodge_base[pclass-1] + base_agility * dodgeRatio->ratio * crit_to_dodge[pclass-1]);
}

float Player::GetSpellCritFromIntellect() const
{
    uint8 level = getLevel();
    uint32 pclass = getClass();

    if (level >= sGtChanceToSpellCritStore.GetTableRowCount())
        level = sGtChanceToSpellCritStore.GetTableRowCount() - 1;

    GtChanceToSpellCritBaseEntry const* critBase = sGtChanceToSpellCritBaseStore.EvaluateTable(pclass - 1, 0);
    GtChanceToSpellCritEntry const* critRatio = sGtChanceToSpellCritStore.EvaluateTable(level - 1, pclass - 1);
    if (critBase == nullptr || critRatio == nullptr)
        return 0.0f;

    float crit = critBase->base + GetStat(STAT_INTELLECT) * critRatio->ratio;
    return crit * 100.0f;
}

float Player::GetRatingMultiplier(CombatRating cr) const
{
    uint8 level = getLevel();

    if (level >= sGtCombatRatingsStore.GetTableRowCount())
        level = sGtCombatRatingsStore.GetTableRowCount() - 1;

    GtCombatRatingsEntry const* Rating = sGtCombatRatingsStore.EvaluateTable(level - 1, cr);
    if (!Rating || !Rating->ratio)
        return 1.0f;                                        // By default use minimum coefficient (not must be called)

    return 1.0f / Rating->ratio;
}

float Player::GetRatingBonusValue(CombatRating cr) const
{
    float baseResult = float(GetUInt32Value(PLAYER_FIELD_COMBAT_RATING_1 + cr)) * GetRatingMultiplier(cr);
    if (cr != CR_RESILIENCE_PLAYER_DAMAGE_TAKEN)
        return baseResult;
    return float(1.0f - pow(0.99f, baseResult)) * 100.0f;
}

float Player::GetExpertiseDodgeOrParryReduction(WeaponAttackType attType) const
{
    float baseExpertise = 7.5f;
    switch (attType)
    {
        case BASE_ATTACK:
            return baseExpertise + GetUInt32Value(PLAYER_EXPERTISE) / 4.0f;
        case OFF_ATTACK:
            return baseExpertise + GetUInt32Value(PLAYER_OFFHAND_EXPERTISE) / 4.0f;
        default:
            break;
    }
    return 0.0f;
}

float Player::OCTRegenMPPerSpirit() const
{
    uint8 level = getLevel();
    uint32 pclass = getClass();

    if (level >= sGtRegenMPPerSptStore.GetTableRowCount())
        level = sGtRegenMPPerSptStore.GetTableRowCount() - 1;

    GtRegenMPPerSptEntry  const* moreRatio = sGtRegenMPPerSptStore.EvaluateTable(level - 1, pclass - 1);
    if (moreRatio == nullptr)
        return 0.0f;

    // Formula get from PaperDollFrame script
    float spirit    = GetStat(STAT_SPIRIT);
    float regen     = spirit * moreRatio->ratio;
    return regen;
}

void Player::ApplyRatingMod(CombatRating combatRating, int32 value, bool apply)
{
    float oldRating = m_baseRatingValue[combatRating];
    m_baseRatingValue[combatRating] += (apply ? value : -value);

    // explicit affected values
    float const multiplier = GetRatingMultiplier(combatRating);
    float const oldVal = oldRating * multiplier;
    float const newVal = m_baseRatingValue[combatRating] * multiplier;
    switch (combatRating)
    {
        case CR_HASTE_MELEE:
            ApplyAttackTimePercentMod(BASE_ATTACK, oldVal, false);
            ApplyAttackTimePercentMod(OFF_ATTACK, oldVal, false);
            ApplyAttackTimePercentMod(BASE_ATTACK, newVal, true);
            ApplyAttackTimePercentMod(OFF_ATTACK, newVal, true);
                if (getClass() == CLASS_DEATH_KNIGHT)
                    UpdateAllRunesRegen();
            break;
        case CR_HASTE_RANGED:
            ApplyAttackTimePercentMod(RANGED_ATTACK, oldVal, false);
            ApplyAttackTimePercentMod(RANGED_ATTACK, newVal, true);
            break;
        case CR_HASTE_SPELL:
            ApplyCastTimePercentMod(oldVal, false);
            ApplyCastTimePercentMod(newVal, true);
            break;
        default:
            break;
    }

    UpdateRating(combatRating);
}

void Player::UpdateRating(CombatRating cr)
{
    int32 amount = m_baseRatingValue[cr];
    // Apply bonus from SPELL_AURA_MOD_RATING_FROM_STAT
    // stat used stored in miscValueB for this aura
    AuraEffectList const& modRatingFromStat = GetAuraEffectsByType(SPELL_AURA_MOD_RATING_FROM_STAT);
    for (AuraEffectList::const_iterator i = modRatingFromStat.begin(); i != modRatingFromStat.end(); ++i)
        if ((*i)->GetMiscValue() & (1<<cr))
            amount += int32(CalculatePct(GetStat(Stats((*i)->GetMiscValueB())), (*i)->GetAmount()));
    if (amount < 0)
        amount = 0;
    SetUInt32Value(PLAYER_FIELD_COMBAT_RATING_1 + cr, uint32(amount));

    bool affectStats = CanModifyStats();

    switch (cr)
    {
        case CR_UNUSED_1:
        case CR_DEFENSE_SKILL:
            break;
        case CR_DODGE:
            UpdateDodgePercentage();
            break;
        case CR_PARRY:
            UpdateParryPercentage();
            break;
        case CR_BLOCK:
            UpdateBlockPercentage();
            break;
        case CR_HIT_MELEE:
            UpdateMeleeHitChances();
            break;
        case CR_HIT_RANGED:
            UpdateRangedHitChances();
            break;
        case CR_HIT_SPELL:
            UpdateSpellHitChances();
            break;
        case CR_CRIT_MELEE:
            if (affectStats)
            {
                UpdateCritPercentage(BASE_ATTACK);
                UpdateCritPercentage(OFF_ATTACK);
            }
            break;
        case CR_CRIT_RANGED:
            if (affectStats)
                UpdateCritPercentage(RANGED_ATTACK);
            break;
        case CR_CRIT_SPELL:
            if (affectStats)
                UpdateAllSpellCritChances();
            break;
        case CR_MULTISTRIKE:
        case CR_READINESS:
        case CR_SPEED:
        case CR_RESILIENCE_PLAYER_DAMAGE_TAKEN:
        case CR_RESILIENCE_CRIT_TAKEN:
        case CR_LIFESTEAL:
            break;
        case CR_HASTE_MELEE:                                // Implemented in Player::ApplyRatingMod
        case CR_HASTE_RANGED:
        case CR_HASTE_SPELL:
            break;
        case CR_AVOIDANCE:
        case CR_UNUSED_2:
        case CR_WEAPON_SKILL_RANGED:
            break;
        case CR_EXPERTISE:
            if (affectStats)
            {
                UpdateExpertise(BASE_ATTACK);
                UpdateExpertise(OFF_ATTACK);
            }
            break;
        case CR_ARMOR_PENETRATION:
            if (affectStats)
                UpdateArmorPenetration(amount);
            break;
        case CR_MASTERY:
            UpdateMastery();
            break;
        case CR_UNUSED_3:
        case CR_UNUSED_4:
        case CR_VERSATILITY_DAMAGE_DONE:
        case CR_VERSATILITY_DAMAGE_TAKEN:
            break;
    }
}

void Player::UpdateAllRatings()
{
    for (int cr = 0; cr < MAX_COMBAT_RATING; ++cr)
        UpdateRating(CombatRating(cr));
}

void Player::SetRegularAttackTime()
{
    for (uint8 i = 0; i < MAX_ATTACK; ++i)
    {
        Item* tmpitem = GetWeaponForAttack(WeaponAttackType(i), true);
        if (tmpitem && !tmpitem->IsBroken())
        {
            ItemTemplate const* proto = tmpitem->GetTemplate();
            if (proto->GetDelay())
                SetAttackTime(WeaponAttackType(i), proto->GetDelay());
        }
        else
            SetAttackTime(WeaponAttackType(i), BASE_ATTACK_TIME);  // If there is no weapon reset attack time to base (might have been changed from forms)
    }
}

//skill+step, checking for max value
bool Player::UpdateSkill(uint32 skill_id, uint32 step)
{
    if (!skill_id)
        return false;

    SkillStatusMap::iterator itr = mSkillStatus.find(skill_id);
    if (itr == mSkillStatus.end() || itr->second.uState == SKILL_DELETED)
        return false;

    uint16 field = itr->second.pos / 2;
    uint8 offset = itr->second.pos & 1; // itr->second.pos % 2

    uint16 value = GetUInt16Value(PLAYER_SKILL_LINEID + SKILL_RANK_OFFSET + field, offset);
    uint16 max = GetUInt16Value(PLAYER_SKILL_LINEID + SKILL_MAX_RANK_OFFSET + field, offset);

    if (!max || !value || value >= max)
        return false;

    if (value < max)
    {
        uint32 new_value = value + step;
        if (new_value > max)
            new_value = max;

        SetUInt16Value(PLAYER_SKILL_LINEID + SKILL_RANK_OFFSET + field, offset, new_value);
        if (itr->second.uState != SKILL_NEW)
            itr->second.uState = SKILL_CHANGED;

        UpdateSkillEnchantments(skill_id, value, new_value);
        UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_REACH_SKILL_LEVEL, skill_id);
        return true;
    }

    return false;
}

inline int SkillGainChance(uint32 SkillValue, uint32 GrayLevel, uint32 GreenLevel, uint32 YellowLevel)
{
    if (SkillValue >= GrayLevel)
        return sWorld->getIntConfig(CONFIG_SKILL_CHANCE_GREY)*10;
    if (SkillValue >= GreenLevel)
        return sWorld->getIntConfig(CONFIG_SKILL_CHANCE_GREEN)*10;
    if (SkillValue >= YellowLevel)
        return sWorld->getIntConfig(CONFIG_SKILL_CHANCE_YELLOW)*10;
    return sWorld->getIntConfig(CONFIG_SKILL_CHANCE_ORANGE)*10;
}

bool Player::UpdateCraftSkill(uint32 spellid)
{
    TC_LOG_DEBUG("entities.player.skills", "Player::UpdateCraftSkill: Player '%s' (%s), SpellID: %d",
        GetName().c_str(), GetGUID().ToString().c_str(), spellid);

    SkillLineAbilityMapBounds bounds = sSpellMgr->GetSkillLineAbilityMapBounds(spellid);

    for (SkillLineAbilityMap::const_iterator _spell_idx = bounds.first; _spell_idx != bounds.second; ++_spell_idx)
    {
        if (_spell_idx->second->SkillLine)
        {
            uint32 SkillValue = GetPureSkillValue(_spell_idx->second->SkillLine);

            // Alchemy Discoveries here
            SpellInfo const* spellEntry = sSpellMgr->GetSpellInfo(spellid);
            if (spellEntry && spellEntry->Mechanic == MECHANIC_DISCOVERY)
            {
                if (uint32 discoveredSpell = GetSkillDiscoverySpell(_spell_idx->second->SkillLine, spellid, this))
                    LearnSpell(discoveredSpell, false);
            }

            uint32 craft_skill_gain = sWorld->getIntConfig(CONFIG_SKILL_GAIN_CRAFTING);

            return UpdateSkillPro(_spell_idx->second->SkillLine, SkillGainChance(SkillValue,
                _spell_idx->second->TrivialSkillLineRankHigh,
                (_spell_idx->second->TrivialSkillLineRankHigh + _spell_idx->second->TrivialSkillLineRankLow)/2,
                _spell_idx->second->TrivialSkillLineRankLow),
                craft_skill_gain);
        }
    }
    return false;
}

bool Player::UpdateGatherSkill(uint32 SkillId, uint32 SkillValue, uint32 RedLevel, uint32 Multiplicator)
{
    TC_LOG_DEBUG("entities.player.skills", "Player::UpdateGatherSkill: Player '%s' (%s), SkillID: %u, SkillLevel: %u,  RedLevel: %u)",
        GetName().c_str(), GetGUID().ToString().c_str(), SkillId, SkillValue, RedLevel);

    uint32 gathering_skill_gain = sWorld->getIntConfig(CONFIG_SKILL_GAIN_GATHERING);

    // For skinning and Mining chance decrease with level. 1-74 - no decrease, 75-149 - 2 times, 225-299 - 8 times
    switch (SkillId)
    {
        case SKILL_HERBALISM:
        case SKILL_LOCKPICKING:
        case SKILL_JEWELCRAFTING:
        case SKILL_INSCRIPTION:
            return UpdateSkillPro(SkillId, SkillGainChance(SkillValue, RedLevel+100, RedLevel+50, RedLevel+25)*Multiplicator, gathering_skill_gain);
        case SKILL_SKINNING:
            if (sWorld->getIntConfig(CONFIG_SKILL_CHANCE_SKINNING_STEPS) == 0)
                return UpdateSkillPro(SkillId, SkillGainChance(SkillValue, RedLevel+100, RedLevel+50, RedLevel+25)*Multiplicator, gathering_skill_gain);
            else
                return UpdateSkillPro(SkillId, (SkillGainChance(SkillValue, RedLevel+100, RedLevel+50, RedLevel+25)*Multiplicator) >> (SkillValue/sWorld->getIntConfig(CONFIG_SKILL_CHANCE_SKINNING_STEPS)), gathering_skill_gain);
        case SKILL_MINING:
            if (sWorld->getIntConfig(CONFIG_SKILL_CHANCE_MINING_STEPS) == 0)
                return UpdateSkillPro(SkillId, SkillGainChance(SkillValue, RedLevel+100, RedLevel+50, RedLevel+25)*Multiplicator, gathering_skill_gain);
            else
                return UpdateSkillPro(SkillId, (SkillGainChance(SkillValue, RedLevel+100, RedLevel+50, RedLevel+25)*Multiplicator) >> (SkillValue/sWorld->getIntConfig(CONFIG_SKILL_CHANCE_MINING_STEPS)), gathering_skill_gain);
    }
    return false;
}

bool Player::UpdateFishingSkill()
{
    TC_LOG_DEBUG("entities.player.skills", "Player::UpdateFishingSkill: Player '%s' (%s)", GetName().c_str(), GetGUID().ToString().c_str());

    uint32 SkillValue = GetPureSkillValue(SKILL_FISHING);

    int32 chance = SkillValue < 75 ? 100 : 2500/(SkillValue-50);

    uint32 gathering_skill_gain = sWorld->getIntConfig(CONFIG_SKILL_GAIN_GATHERING);

    return UpdateSkillPro(SKILL_FISHING, chance*10, gathering_skill_gain);
}

bool Player::UpdateSkillPro(uint16 skillId, int32 chance, uint32 step)
{
    // levels sync. with spell requirement for skill levels to learn
    // bonus abilities in sSkillLineAbilityStore
    // Used only to avoid scan DBC at each skill grow
    static uint32 bonusSkillLevels[] = { 75, 150, 225, 300, 375, 450, 525 };
    static const size_t bonusSkillLevelsSize = sizeof(bonusSkillLevels) / sizeof(uint32);

    TC_LOG_DEBUG("entities.player.skills", "Player::UpdateSkillPro: Player '%s' (%s), SkillID: %u, Chance: %3.1f%%)",
        GetName().c_str(), GetGUID().ToString().c_str(), skillId, chance / 10.0f);
    if (!skillId)
        return false;

    if (chance <= 0)                                         // speedup in 0 chance case
    {
        TC_LOG_DEBUG("entities.player.skills", "Player::UpdateSkillPro: Player '%s' (%s), SkillID: %u, Chance: %3.1f%% missed",
            GetName().c_str(), GetGUID().ToString().c_str(), skillId, chance / 10.0f);
        return false;
    }

    SkillStatusMap::iterator itr = mSkillStatus.find(skillId);
    if (itr == mSkillStatus.end() || itr->second.uState == SKILL_DELETED)
        return false;

    uint16 field = itr->second.pos / 2;
    uint8 offset = itr->second.pos & 1; // itr->second.pos % 2

    uint16 value = GetUInt16Value(PLAYER_SKILL_LINEID + SKILL_RANK_OFFSET + field, offset);
    uint16 max = GetUInt16Value(PLAYER_SKILL_LINEID + SKILL_MAX_RANK_OFFSET + field, offset);

    if (!max || !value || value >= max)
        return false;

    if (irand(1, 1000) > chance)
    {
        TC_LOG_DEBUG("entities.player.skills", "Player::UpdateSkillPro: Player '%s' (%s), SkillID: %u, Chance: %3.1f%% missed",
            GetName().c_str(), GetGUID().ToString().c_str(), skillId, chance / 10.0f);
        return false;
    }

    uint16 new_value = value + step;
    if (new_value > max)
        new_value = max;

    SetUInt16Value(PLAYER_SKILL_LINEID + SKILL_RANK_OFFSET + field, offset, new_value);
    if (itr->second.uState != SKILL_NEW)
        itr->second.uState = SKILL_CHANGED;

    for (size_t i = 0; i < bonusSkillLevelsSize; ++i)
    {
        uint32 bsl = bonusSkillLevels[i];
        if (value < bsl && new_value >= bsl)
        {
            LearnSkillRewardedSpells(skillId, new_value);
            break;
        }
    }

    UpdateSkillEnchantments(skillId, value, new_value);
    UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_REACH_SKILL_LEVEL, skillId);
    TC_LOG_DEBUG("entities.player.skills", "Player::UpdateSkillPro: Player '%s' (%s), SkillID: %u, Chance: %3.1f%% taken",
        GetName().c_str(), GetGUID().ToString().c_str(), skillId, chance / 10.0f);
    return true;
}

void Player::ModifySkillBonus(uint32 skillid, int32 val, bool talent)
{
    SkillStatusMap::const_iterator itr = mSkillStatus.find(skillid);
    if (itr == mSkillStatus.end() || itr->second.uState == SKILL_DELETED)
        return;

    uint16 field = itr->second.pos / 2 + (talent ? PLAYER_SKILL_LINEID + SKILL_PERM_BONUS_OFFSET : PLAYER_SKILL_LINEID + SKILL_TEMP_BONUS_OFFSET);
    uint8 offset = itr->second.pos & 1; // itr->second.pos % 2

    uint16 bonus = GetUInt16Value(field, offset);

    SetUInt16Value(field, offset, bonus + val);
}

void Player::UpdateSkillsForLevel()
{
    uint32 maxSkill = GetMaxSkillValueForLevel();

    for (SkillStatusMap::iterator itr = mSkillStatus.begin(); itr != mSkillStatus.end(); ++itr)
    {
        if (itr->second.uState == SKILL_DELETED)
            continue;

        uint32 pskill = itr->first;
        SkillRaceClassInfoEntry const* rcEntry = GetSkillRaceClassInfo(pskill, getRace(), getClass());
        if (!rcEntry)
            continue;

        uint16 field = itr->second.pos / 2;
        uint8 offset = itr->second.pos & 1; // itr->second.pos % 2

        if (GetSkillRangeType(rcEntry) == SKILL_RANGE_LEVEL)
        {
            if (!IsWeaponSkill(rcEntry->SkillID))
            {
                uint16 max = GetUInt16Value(PLAYER_SKILL_LINEID + SKILL_MAX_RANK_OFFSET + field, offset);

                /// update only level dependent max skill values
                if (max != 1)
                {
                    SetUInt16Value(PLAYER_SKILL_LINEID + SKILL_RANK_OFFSET + field, offset, maxSkill);
                    SetUInt16Value(PLAYER_SKILL_LINEID + SKILL_MAX_RANK_OFFSET + field, offset, maxSkill);
                    if (itr->second.uState != SKILL_NEW)
                        itr->second.uState = SKILL_CHANGED;
                }
            }
        }

        // Update level dependent skillline spells
        LearnSkillRewardedSpells(rcEntry->SkillID, GetUInt16Value(PLAYER_SKILL_LINEID + SKILL_RANK_OFFSET + field, offset));
    }
}

void Player::UpdateSkillsToMaxSkillsForLevel()
{
    for (SkillStatusMap::iterator itr = mSkillStatus.begin(); itr != mSkillStatus.end(); ++itr)
    {
        if (itr->second.uState == SKILL_DELETED)
            continue;

        uint32 pskill = itr->first;
        SkillRaceClassInfoEntry const* rcEntry = GetSkillRaceClassInfo(pskill, getRace(), getClass());
        if (!rcEntry)
            continue;

        if (IsProfessionOrRidingSkill(rcEntry->SkillID))
            continue;

        if (IsWeaponSkill(rcEntry->SkillID))
            continue;

        uint16 field = itr->second.pos / 2;
        uint8 offset = itr->second.pos & 1; // itr->second.pos % 2

        uint16 max = GetUInt16Value(PLAYER_SKILL_LINEID + SKILL_MAX_RANK_OFFSET + field, offset);

        if (max > 1)
        {
            SetUInt16Value(PLAYER_SKILL_LINEID + SKILL_RANK_OFFSET + field, offset, max);

            if (itr->second.uState != SKILL_NEW)
                itr->second.uState = SKILL_CHANGED;
        }
    }
}

// This functions sets a skill line value (and adds if doesn't exist yet)
// To "remove" a skill line, set it's values to zero
void Player::SetSkill(uint16 id, uint16 step, uint16 newVal, uint16 maxVal)
{
    if (!id)
        return;

    uint16 currVal;
    SkillStatusMap::iterator itr = mSkillStatus.find(id);

    //has skill
    if (itr != mSkillStatus.end() && itr->second.uState != SKILL_DELETED)
    {
        uint16 field = itr->second.pos / 2;
        uint8 offset = itr->second.pos & 1; // itr->second.pos % 2
        currVal = GetUInt16Value(PLAYER_SKILL_LINEID + SKILL_RANK_OFFSET + field, offset);
        if (newVal)
        {
            // if skill value is going down, update enchantments before setting the new value
            if (newVal < currVal)
                UpdateSkillEnchantments(id, currVal, newVal);

            // update step
            SetUInt16Value(PLAYER_SKILL_LINEID + SKILL_STEP_OFFSET + field, offset, step);
            // update value
            SetUInt16Value(PLAYER_SKILL_LINEID + SKILL_RANK_OFFSET + field, offset, newVal);
            SetUInt16Value(PLAYER_SKILL_LINEID + SKILL_MAX_RANK_OFFSET + field, offset, maxVal);

            if (itr->second.uState != SKILL_NEW)
                itr->second.uState = SKILL_CHANGED;

            LearnSkillRewardedSpells(id, newVal);
            // if skill value is going up, update enchantments after setting the new value
            if (newVal > currVal)
                UpdateSkillEnchantments(id, currVal, newVal);

            UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_REACH_SKILL_LEVEL, id);
            UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_LEARN_SKILL_LEVEL, id);
        }
        else                                                //remove
        {
            //remove enchantments needing this skill
            UpdateSkillEnchantments(id, currVal, 0);
            // clear skill fields
            SetUInt16Value(PLAYER_SKILL_LINEID + SKILL_ID_OFFSET + field, offset, 0);
            SetUInt16Value(PLAYER_SKILL_LINEID + SKILL_STEP_OFFSET + field, offset, 0);
            SetUInt16Value(PLAYER_SKILL_LINEID + SKILL_RANK_OFFSET + field, offset, 0);
            SetUInt16Value(PLAYER_SKILL_LINEID + SKILL_MAX_RANK_OFFSET + field, offset, 0);
            SetUInt16Value(PLAYER_SKILL_LINEID + SKILL_TEMP_BONUS_OFFSET + field, offset, 0);
            SetUInt16Value(PLAYER_SKILL_LINEID + SKILL_PERM_BONUS_OFFSET + field, offset, 0);

            // mark as deleted or simply remove from map if not saved yet
            if (itr->second.uState != SKILL_NEW)
                itr->second.uState = SKILL_DELETED;
            else
                mSkillStatus.erase(itr);

            // remove all spells that related to this skill
            for (uint32 j = 0; j < sSkillLineAbilityStore.GetNumRows(); ++j)
                if (SkillLineAbilityEntry const* pAbility = sSkillLineAbilityStore.LookupEntry(j))
                    if (pAbility->SkillLine == id)
                        RemoveSpell(sSpellMgr->GetFirstSpellInChain(pAbility->SpellID));

            // Clear profession lines
            if (GetUInt32Value(PLAYER_PROFESSION_SKILL_LINE_1) == id)
                SetUInt32Value(PLAYER_PROFESSION_SKILL_LINE_1, 0);
            else if (GetUInt32Value(PLAYER_PROFESSION_SKILL_LINE_1 + 1) == id)
                SetUInt32Value(PLAYER_PROFESSION_SKILL_LINE_1 + 1, 0);
        }
    }
    else if (newVal)                                        //add
    {
        currVal = 0;
        for (uint32 i = 0; i < PLAYER_MAX_SKILLS; ++i)
        {
            uint16 field = i / 2;
            uint8 offset = i & 1; // i % 2

            if (!GetUInt16Value(PLAYER_SKILL_LINEID + SKILL_ID_OFFSET + field, offset))
            {
                SkillLineEntry const* skillEntry = sSkillLineStore.LookupEntry(id);
                if (!skillEntry)
                {
                    TC_LOG_ERROR("misc", "Player::SetSkill: Skill (SkillID: %u) not found in SkillLineStore for player '%s' (%s)",
                        id, GetName().c_str(), GetGUID().ToString().c_str());
                    return;
                }

                SetUInt16Value(PLAYER_SKILL_LINEID + SKILL_ID_OFFSET + field, offset, id);
                if (skillEntry->CategoryID == SKILL_CATEGORY_PROFESSION)
                {
                    if (!GetUInt32Value(PLAYER_PROFESSION_SKILL_LINE_1))
                        SetUInt32Value(PLAYER_PROFESSION_SKILL_LINE_1, id);
                    else if (!GetUInt32Value(PLAYER_PROFESSION_SKILL_LINE_1 + 1))
                        SetUInt32Value(PLAYER_PROFESSION_SKILL_LINE_1 + 1, id);
                }

                SetUInt16Value(PLAYER_SKILL_LINEID + SKILL_STEP_OFFSET + field, offset, step);
                SetUInt16Value(PLAYER_SKILL_LINEID + SKILL_RANK_OFFSET + field, offset, newVal);
                SetUInt16Value(PLAYER_SKILL_LINEID + SKILL_MAX_RANK_OFFSET + field, offset, maxVal);

                UpdateSkillEnchantments(id, currVal, newVal);
                UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_REACH_SKILL_LEVEL, id);
                UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_LEARN_SKILL_LEVEL, id);

                // insert new entry or update if not deleted old entry yet
                if (itr != mSkillStatus.end())
                {
                    itr->second.pos = i;
                    itr->second.uState = SKILL_CHANGED;
                }
                else
                    mSkillStatus.insert(SkillStatusMap::value_type(id, SkillStatusData(i, SKILL_NEW)));

                // apply skill bonuses
                SetUInt16Value(PLAYER_SKILL_LINEID + SKILL_TEMP_BONUS_OFFSET + field, offset, 0);
                SetUInt16Value(PLAYER_SKILL_LINEID + SKILL_PERM_BONUS_OFFSET + field, offset, 0);
                // temporary bonuses
                AuraEffectList const& mModSkill = GetAuraEffectsByType(SPELL_AURA_MOD_SKILL);
                for (AuraEffectList::const_iterator j = mModSkill.begin(); j != mModSkill.end(); ++j)
                    if ((*j)->GetMiscValue() == int32(id))
                        (*j)->HandleEffect(this, AURA_EFFECT_HANDLE_SKILL, true);
                AuraEffectList const& mModSkill2 = GetAuraEffectsByType(SPELL_AURA_MOD_SKILL_2);
                for (AuraEffectList::const_iterator j = mModSkill2.begin(); j != mModSkill2.end(); ++j)
                    if ((*j)->GetMiscValue() == int32(id))
                        (*j)->HandleEffect(this, AURA_EFFECT_HANDLE_SKILL, true);

                // permanent bonuses
                AuraEffectList const& mModSkillTalent = GetAuraEffectsByType(SPELL_AURA_MOD_SKILL_TALENT);
                for (AuraEffectList::const_iterator j = mModSkillTalent.begin(); j != mModSkillTalent.end(); ++j)
                    if ((*j)->GetMiscValue() == int32(id))
                        (*j)->HandleEffect(this, AURA_EFFECT_HANDLE_SKILL, true);

                // Learn all spells for skill
                LearnSkillRewardedSpells(id, newVal);
                return;
            }
        }
    }
}

bool Player::HasSkill(uint32 skill) const
{
    if (!skill)
        return false;

    SkillStatusMap::const_iterator itr = mSkillStatus.find(skill);
    return (itr != mSkillStatus.end() && itr->second.uState != SKILL_DELETED);
}

uint16 Player::GetSkillStep(uint16 skill) const
{
    if (!skill)
        return 0;

    SkillStatusMap::const_iterator itr = mSkillStatus.find(skill);
    if (itr == mSkillStatus.end() || itr->second.uState == SKILL_DELETED)
        return 0;

    return GetUInt16Value(PLAYER_SKILL_LINEID + SKILL_STEP_OFFSET + itr->second.pos / 2, itr->second.pos & 1);
}

uint16 Player::GetSkillValue(uint32 skill) const
{
    if (!skill)
        return 0;

    SkillStatusMap::const_iterator itr = mSkillStatus.find(skill);
    if (itr == mSkillStatus.end() || itr->second.uState == SKILL_DELETED)
        return 0;

    uint16 field = itr->second.pos / 2;
    uint8 offset = itr->second.pos & 1;

    int32 result = int32(GetUInt16Value(PLAYER_SKILL_LINEID + SKILL_RANK_OFFSET + field, offset));
    result += int32(GetUInt16Value(PLAYER_SKILL_LINEID + SKILL_TEMP_BONUS_OFFSET + field, offset));
    result += int32(GetUInt16Value(PLAYER_SKILL_LINEID + SKILL_PERM_BONUS_OFFSET + field, offset));
    return result < 0 ? 0 : result;
}

uint16 Player::GetMaxSkillValue(uint32 skill) const
{
    if (!skill)
        return 0;

    SkillStatusMap::const_iterator itr = mSkillStatus.find(skill);
    if (itr == mSkillStatus.end() || itr->second.uState == SKILL_DELETED)
        return 0;

    uint16 field = itr->second.pos / 2;
    uint8 offset = itr->second.pos & 1;

    int32 result = int32(GetUInt16Value(PLAYER_SKILL_LINEID + SKILL_MAX_RANK_OFFSET + field, offset));
    result += int32(GetUInt16Value(PLAYER_SKILL_LINEID + SKILL_TEMP_BONUS_OFFSET + field, offset));
    result += int32(GetUInt16Value(PLAYER_SKILL_LINEID + SKILL_PERM_BONUS_OFFSET + field, offset));
    return result < 0 ? 0 : result;
}

uint16 Player::GetPureMaxSkillValue(uint32 skill) const
{
    if (!skill)
        return 0;

    SkillStatusMap::const_iterator itr = mSkillStatus.find(skill);
    if (itr == mSkillStatus.end() || itr->second.uState == SKILL_DELETED)
        return 0;

    uint16 field = itr->second.pos / 2;
    uint8 offset = itr->second.pos & 1;

    return GetUInt16Value(PLAYER_SKILL_LINEID + SKILL_MAX_RANK_OFFSET + field, offset);
}

uint16 Player::GetBaseSkillValue(uint32 skill) const
{
    if (!skill)
        return 0;

    SkillStatusMap::const_iterator itr = mSkillStatus.find(skill);
    if (itr == mSkillStatus.end() || itr->second.uState == SKILL_DELETED)
        return 0;

    uint16 field = itr->second.pos / 2;
    uint8 offset = itr->second.pos & 1;

    int32 result = int32(GetUInt16Value(PLAYER_SKILL_LINEID + SKILL_RANK_OFFSET + field, offset));
    result += int32(GetUInt16Value(PLAYER_SKILL_LINEID + SKILL_PERM_BONUS_OFFSET + field, offset));
    return result < 0 ? 0 : result;
}

uint16 Player::GetPureSkillValue(uint32 skill) const
{
    if (!skill)
        return 0;

    SkillStatusMap::const_iterator itr = mSkillStatus.find(skill);
    if (itr == mSkillStatus.end() || itr->second.uState == SKILL_DELETED)
        return 0;

    uint16 field = itr->second.pos / 2;
    uint8 offset = itr->second.pos & 1;

    return GetUInt16Value(PLAYER_SKILL_LINEID + SKILL_RANK_OFFSET + field, offset);
}

int16 Player::GetSkillPermBonusValue(uint32 skill) const
{
    if (!skill)
        return 0;

    SkillStatusMap::const_iterator itr = mSkillStatus.find(skill);
    if (itr == mSkillStatus.end() || itr->second.uState == SKILL_DELETED)
        return 0;

    uint16 field = itr->second.pos / 2;
    uint8 offset = itr->second.pos & 1;

    return GetUInt16Value(PLAYER_SKILL_LINEID + SKILL_PERM_BONUS_OFFSET + field, offset);
}

int16 Player::GetSkillTempBonusValue(uint32 skill) const
{
    if (!skill)
        return 0;

    SkillStatusMap::const_iterator itr = mSkillStatus.find(skill);
    if (itr == mSkillStatus.end() || itr->second.uState == SKILL_DELETED)
        return 0;

    uint16 field = itr->second.pos / 2;
    uint8 offset = itr->second.pos & 1;

    return GetUInt16Value(PLAYER_SKILL_LINEID + SKILL_TEMP_BONUS_OFFSET + field, offset);
}

void Player::SendActionButtons(uint32 state) const
{
    WorldPackets::Spells::UpdateActionButtons packet;

    for (uint8 button = 0; button < MAX_ACTION_BUTTONS; ++button)
    {
        ActionButtonList::const_iterator itr = m_actionButtons.find(button);
        if (itr != m_actionButtons.end() && itr->second.uState != ACTIONBUTTON_DELETED)
            packet.ActionButtons[button] = uint64(itr->second.packedData);
        else
            packet.ActionButtons[button] = 0;
    }

    packet.Reason = state;

    SendDirectMessage(packet.Write());
}

bool Player::IsActionButtonDataValid(uint8 button, uint32 action, uint8 type) const
{
    if (button >= MAX_ACTION_BUTTONS)
    {
        TC_LOG_ERROR("entities.player", "Player::IsActionButtonDataValid: Action %u not added into button %u for player %s (%s): button must be < %u",
            action, button, GetName().c_str(), GetGUID().ToString().c_str(), MAX_ACTION_BUTTONS);
        return false;
    }

    if (action >= MAX_ACTION_BUTTON_ACTION_VALUE)
    {
        TC_LOG_ERROR("entities.player", "Player::IsActionButtonDataValid: Action %u not added into button %u for player %s (%s): action must be < %u",
            action, button, GetName().c_str(), GetGUID().ToString().c_str(), MAX_ACTION_BUTTON_ACTION_VALUE);
        return false;
    }

    switch (type)
    {
        case ACTION_BUTTON_SPELL:
            if (!sSpellMgr->GetSpellInfo(action))
            {
                TC_LOG_ERROR("entities.player", "Player::IsActionButtonDataValid: Spell action %u not added into button %u for player %s (%s): spell not exist",
                    action, button, GetName().c_str(), GetGUID().ToString().c_str());
                return false;
            }

            if (!HasSpell(action))
            {
                TC_LOG_ERROR("entities.player", "Player::IsActionButtonDataValid: Spell action %u not added into button %u for player %s (%s): player don't known this spell",
                    action, button, GetName().c_str(), GetGUID().ToString().c_str());
                return false;
            }
            break;
        case ACTION_BUTTON_ITEM:
            if (!sObjectMgr->GetItemTemplate(action))
            {
                TC_LOG_ERROR("entities.player", "Player::IsActionButtonDataValid: Item action %u not added into button %u for player %s (%s): item not exist",
                    action, button, GetName().c_str(), GetGUID().ToString().c_str());
                return false;
            }
            break;
        case ACTION_BUTTON_MOUNT:
        {
            auto mount = sDB2Manager.GetMountById(action);
            if (!mount)
            {
                TC_LOG_ERROR("entities.player", "Player::IsActionButtonDataValid: Mount action %u not added into button %u for player %s (%s): mount does not exist",
                    action, button, GetName().c_str(), GetGUID().ToString().c_str());
                return false;
            }

            if (!HasSpell(mount->SpellId))
            {
                TC_LOG_ERROR("entities.player", "Player::IsActionButtonDataValid: Mount action %u not added into button %u for player %s (%s): Player does not know this mount",
                    action, button, GetName().c_str(), GetGUID().ToString().c_str());
                return false;
            }
            break;
        }
        case ACTION_BUTTON_C:
        case ACTION_BUTTON_CMACRO:
        case ACTION_BUTTON_MACRO:
        case ACTION_BUTTON_EQSET:
        case ACTION_BUTTON_DROPDOWN:
            break;
        default:
            TC_LOG_ERROR("entities.player", "Player::IsActionButtonDataValid: Unknown action type %u", type);
            return false;                                          // other cases not checked at this moment
    }

    return true;
}

ActionButton* Player::AddActionButton(uint8 button, uint32 action, uint8 type)
{
    if (!IsActionButtonDataValid(button, action, type))
        return nullptr;

    // it create new button (NEW state) if need or return existed
    ActionButton& ab = m_actionButtons[button];

    // set data and update to CHANGED if not NEW
    ab.SetActionAndType(action, ActionButtonType(type));

    TC_LOG_DEBUG("entities.player", "Player::AddActionButton: Player '%s' (%s) added action '%u' (type %u) to button '%u'",
        GetName().c_str(), GetGUID().ToString().c_str(), action, type, button);
    return &ab;
}

void Player::RemoveActionButton(uint8 button)
{
    ActionButtonList::iterator buttonItr = m_actionButtons.find(button);
    if (buttonItr == m_actionButtons.end() || buttonItr->second.uState == ACTIONBUTTON_DELETED)
        return;

    if (buttonItr->second.uState == ACTIONBUTTON_NEW)
        m_actionButtons.erase(buttonItr);                   // new and not saved
    else
        buttonItr->second.uState = ACTIONBUTTON_DELETED;    // saved, will deleted at next save

    TC_LOG_DEBUG("entities.player", "Player::RemoveActionButton: Player '%s' (%s) removed action button '%u'",
        GetName().c_str(), GetGUID().ToString().c_str(), button);
}

ActionButton const* Player::GetActionButton(uint8 button)
{
    ActionButtonList::iterator buttonItr = m_actionButtons.find(button);
    if (buttonItr == m_actionButtons.end() || buttonItr->second.uState == ACTIONBUTTON_DELETED)
        return nullptr;

    return &buttonItr->second;
}

bool Player::UpdatePosition(float x, float y, float z, float orientation, bool teleport)
{
    if (!Unit::UpdatePosition(x, y, z, orientation, teleport))
        return false;

    //if (movementInfo.flags & MOVEMENTFLAG_MOVING)
    //    mover->RemoveAurasWithInterruptFlags(AURA_INTERRUPT_FLAG_MOVE);
    //if (movementInfo.flags & MOVEMENTFLAG_TURNING)
    //    mover->RemoveAurasWithInterruptFlags(AURA_INTERRUPT_FLAG_TURNING);
    //AURA_INTERRUPT_FLAG_JUMP not sure

    // group update
    if (GetGroup())
        SetGroupUpdateFlag(GROUP_UPDATE_FLAG_POSITION);

    CheckAreaExploreAndOutdoor();

    return true;
}

void Player::SaveRecallPosition()
{
    m_recallMap = GetMapId();
    m_recallX = GetPositionX();
    m_recallY = GetPositionY();
    m_recallZ = GetPositionZ();
    m_recallO = GetOrientation();
}

void Player::SendMessageToSetInRange(WorldPacket const* data, float dist, bool self)
{
    if (self)
        GetSession()->SendPacket(data);

    Trinity::MessageDistDeliverer notifier(this, data, dist);
    VisitNearbyWorldObject(dist, notifier);
}

void Player::SendMessageToSetInRange(WorldPacket const* data, float dist, bool self, bool own_team_only)
{
    if (self)
        GetSession()->SendPacket(data);

    Trinity::MessageDistDeliverer notifier(this, data, dist, own_team_only);
    VisitNearbyWorldObject(dist, notifier);
}

void Player::SendMessageToSet(WorldPacket const* data, Player const* skipped_rcvr)
{
    if (skipped_rcvr != this)
        GetSession()->SendPacket(data);

    // we use World::GetMaxVisibleDistance() because i cannot see why not use a distance
    // update: replaced by GetMap()->GetVisibilityDistance()
    Trinity::MessageDistDeliverer notifier(this, data, GetVisibilityRange(), false, skipped_rcvr);
    VisitNearbyWorldObject(GetVisibilityRange(), notifier);
}

void Player::SendDirectMessage(WorldPacket const* data) const
{
    m_session->SendPacket(data);
}

void Player::SendCinematicStart(uint32 CinematicSequenceId) const
{
    WorldPackets::Misc::TriggerCinematic packet;
    packet.CinematicID = CinematicSequenceId;
    SendDirectMessage(packet.Write());
}

void Player::SendMovieStart(uint32 MovieId) const
{
    WorldPackets::Misc::TriggerMovie packet;
    packet.MovieID = MovieId;
    SendDirectMessage(packet.Write());
}

void Player::CheckAreaExploreAndOutdoor()
{
    if (!IsAlive())
        return;

    if (IsInFlight())
        return;

    bool isOutdoor;
    uint32 areaId = GetBaseMap()->GetAreaId(GetPositionX(), GetPositionY(), GetPositionZ(), &isOutdoor);
    AreaTableEntry const* areaEntry = sAreaTableStore.LookupEntry(areaId);

    if (sWorld->getBoolConfig(CONFIG_VMAP_INDOOR_CHECK) && !isOutdoor)
        RemoveAurasWithAttribute(SPELL_ATTR0_OUTDOORS_ONLY);

    if (!areaId)
        return;

    if (!areaEntry)
    {
        TC_LOG_ERROR("entities.player", "Player '%s' (%s) discovered unknown area (x: %f y: %f z: %f map: %u)",
            GetName().c_str(), GetGUID().ToString().c_str(), GetPositionX(), GetPositionY(), GetPositionZ(), GetMapId());
        return;
    }

    uint32 offset = areaEntry->AreaBit / 32;

    if (offset >= PLAYER_EXPLORED_ZONES_SIZE)
    {
        TC_LOG_ERROR("entities.player", "Player::CheckAreaExploreAndOutdoor: Wrong area flag %u in map data for (X: %f Y: %f) point to field PLAYER_EXPLORED_ZONES_1 + %u ( %u must be < %u ).",
            areaId, GetPositionX(), GetPositionY(), offset, offset, PLAYER_EXPLORED_ZONES_SIZE);
        return;
    }

    uint32 val = (uint32)(1 << (areaEntry->AreaBit % 32));
    uint32 currFields = GetUInt32Value(PLAYER_EXPLORED_ZONES_1 + offset);

    if (!(currFields & val))
    {
        SetUInt32Value(PLAYER_EXPLORED_ZONES_1 + offset, (uint32)(currFields | val));

        UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_EXPLORE_AREA);

        if (areaEntry->ExplorationLevel > 0)
        {
            if (getLevel() >= sWorld->getIntConfig(CONFIG_MAX_PLAYER_LEVEL))
            {
                SendExplorationExperience(areaId, 0);
            }
            else
            {
                int32 diff = int32(getLevel()) - areaEntry->ExplorationLevel;
                uint32 XP;
                if (diff < -5)
                {
                    XP = uint32(sObjectMgr->GetBaseXP(getLevel()+5)*sWorld->getRate(RATE_XP_EXPLORE));
                }
                else if (diff > 5)
                {
                    int32 exploration_percent = 100 - ((diff - 5) * 5);
                    if (exploration_percent < 0)
                        exploration_percent = 0;

                    XP = uint32(sObjectMgr->GetBaseXP(areaEntry->ExplorationLevel)*exploration_percent/100*sWorld->getRate(RATE_XP_EXPLORE));
                }
                else
                {
                    XP = uint32(sObjectMgr->GetBaseXP(areaEntry->ExplorationLevel)*sWorld->getRate(RATE_XP_EXPLORE));
                }

                GiveXP(XP, nullptr);
                SendExplorationExperience(areaId, XP);
            }
            TC_LOG_DEBUG("entities.player", "Player '%s' (%s) discovered a new area: %u", GetName().c_str(),GetGUID().ToString().c_str(), areaId);
        }
    }
}

uint32 Player::TeamForRace(uint8 race)
{
    if (ChrRacesEntry const* rEntry = sChrRacesStore.LookupEntry(race))
    {
        switch (rEntry->TeamID)
        {
            case 0: return ALLIANCE;
            case 1: return HORDE;
        }
        TC_LOG_ERROR("entities.player", "Race (%u) has wrong teamid (%u) in DBC: wrong DBC files?", uint32(race), rEntry->TeamID);
    }
    else
        TC_LOG_ERROR("entities.player", "Race (%u) not found in DBC: wrong DBC files?", uint32(race));

    return ALLIANCE;
}

TeamId Player::TeamIdForRace(uint8 race)
{
    if (ChrRacesEntry const* rEntry = sChrRacesStore.LookupEntry(race))
        return TeamId(rEntry->TeamID);

    TC_LOG_ERROR("entities.player", "Race (%u) not found in DBC: wrong DBC files?", race);
    return TEAM_NEUTRAL;
}

void Player::setFactionForRace(uint8 race)
{
    m_team = TeamForRace(race);

    ChrRacesEntry const* rEntry = sChrRacesStore.LookupEntry(race);
    setFaction(rEntry ? rEntry->FactionID : 0);
}

ReputationRank Player::GetReputationRank(uint32 faction) const
{
    FactionEntry const* factionEntry = sFactionStore.LookupEntry(faction);
    return GetReputationMgr().GetRank(factionEntry);
}

// Calculate total reputation percent player gain with quest/creature level
int32 Player::CalculateReputationGain(ReputationSource source, uint32 creatureOrQuestLevel, int32 rep, int32 faction, bool noQuestBonus)
{
    float percent = 100.0f;

    float repMod = noQuestBonus ? 0.0f : float(GetTotalAuraModifier(SPELL_AURA_MOD_REPUTATION_GAIN));

    // faction specific auras only seem to apply to kills
    if (source == REPUTATION_SOURCE_KILL)
        repMod += GetTotalAuraModifierByMiscValue(SPELL_AURA_MOD_FACTION_REPUTATION_GAIN, faction);

    percent += rep > 0 ? repMod : -repMod;

    float rate;
    switch (source)
    {
        case REPUTATION_SOURCE_KILL:
            rate = sWorld->getRate(RATE_REPUTATION_LOWLEVEL_KILL);
            break;
        case REPUTATION_SOURCE_QUEST:
        case REPUTATION_SOURCE_DAILY_QUEST:
        case REPUTATION_SOURCE_WEEKLY_QUEST:
        case REPUTATION_SOURCE_MONTHLY_QUEST:
        case REPUTATION_SOURCE_REPEATABLE_QUEST:
            rate = sWorld->getRate(RATE_REPUTATION_LOWLEVEL_QUEST);
            break;
        case REPUTATION_SOURCE_SPELL:
        default:
            rate = 1.0f;
            break;
    }

    if (rate != 1.0f && creatureOrQuestLevel < Trinity::XP::GetGrayLevel(getLevel()))
        percent *= rate;

    if (percent <= 0.0f)
        return 0;

    // Multiply result with the faction specific rate
    if (RepRewardRate const* repData = sObjectMgr->GetRepRewardRate(faction))
    {
        float repRate = 0.0f;
        switch (source)
        {
            case REPUTATION_SOURCE_KILL:
                repRate = repData->creatureRate;
                break;
            case REPUTATION_SOURCE_QUEST:
                repRate = repData->questRate;
                break;
            case REPUTATION_SOURCE_DAILY_QUEST:
                repRate = repData->questDailyRate;
                break;
            case REPUTATION_SOURCE_WEEKLY_QUEST:
                repRate = repData->questWeeklyRate;
                break;
            case REPUTATION_SOURCE_MONTHLY_QUEST:
                repRate = repData->questMonthlyRate;
                break;
            case REPUTATION_SOURCE_REPEATABLE_QUEST:
                repRate = repData->questRepeatableRate;
                break;
            case REPUTATION_SOURCE_SPELL:
                repRate = repData->spellRate;
                break;
        }

        // for custom, a rate of 0.0 will totally disable reputation gain for this faction/type
        if (repRate <= 0.0f)
            return 0;

        percent *= repRate;
    }

    if (source != REPUTATION_SOURCE_SPELL && GetsRecruitAFriendBonus(false))
        percent *= 1.0f + sWorld->getRate(RATE_REPUTATION_RECRUIT_A_FRIEND_BONUS);

    return CalculatePct(rep, percent);
}

// Calculates how many reputation points player gains in victim's enemy factions
void Player::RewardReputation(Unit* victim, float rate)
{
    if (!victim || victim->GetTypeId() == TYPEID_PLAYER)
        return;

    if (victim->ToCreature()->IsReputationGainDisabled())
        return;

    ReputationOnKillEntry const* Rep = sObjectMgr->GetReputationOnKilEntry(victim->ToCreature()->GetCreatureTemplate()->Entry);
    if (!Rep)
        return;

    uint32 ChampioningFaction = 0;

    if (GetChampioningFaction())
    {
        // support for: Championing - http://www.wowwiki.com/Championing
        Map const* map = GetMap();
        if (map->IsNonRaidDungeon())
            if (LFGDungeonEntry const* dungeon = GetLFGDungeon(map->GetId(), map->GetDifficultyID()))
                if (dungeon->TargetLevel == 80)
                    ChampioningFaction = GetChampioningFaction();
    }

    uint32 team = GetTeam();

    if (Rep->RepFaction1 && (!Rep->TeamDependent || team == ALLIANCE))
    {
        int32 donerep1 = CalculateReputationGain(REPUTATION_SOURCE_KILL, victim->getLevel(), Rep->RepValue1, ChampioningFaction ? ChampioningFaction : Rep->RepFaction1);
        donerep1 = int32(donerep1 * rate);

        FactionEntry const* factionEntry1 = sFactionStore.LookupEntry(ChampioningFaction ? ChampioningFaction : Rep->RepFaction1);
        uint32 current_reputation_rank1 = GetReputationMgr().GetRank(factionEntry1);
        if (factionEntry1 && current_reputation_rank1 <= Rep->ReputationMaxCap1)
            GetReputationMgr().ModifyReputation(factionEntry1, donerep1);
    }

    if (Rep->RepFaction2 && (!Rep->TeamDependent || team == HORDE))
    {
        int32 donerep2 = CalculateReputationGain(REPUTATION_SOURCE_KILL, victim->getLevel(), Rep->RepValue2, ChampioningFaction ? ChampioningFaction : Rep->RepFaction2);
        donerep2 = int32(donerep2 * rate);

        FactionEntry const* factionEntry2 = sFactionStore.LookupEntry(ChampioningFaction ? ChampioningFaction : Rep->RepFaction2);
        uint32 current_reputation_rank2 = GetReputationMgr().GetRank(factionEntry2);
        if (factionEntry2 && current_reputation_rank2 <= Rep->ReputationMaxCap2)
            GetReputationMgr().ModifyReputation(factionEntry2, donerep2);
    }
}

// Calculate how many reputation points player gain with the quest
void Player::RewardReputation(Quest const* quest)
{
    for (uint8 i = 0; i < QUEST_REWARD_REPUTATIONS_COUNT; ++i)
    {
        if (!quest->RewardFactionId[i])
            continue;

        int32 rep = 0;
        bool noQuestBonus = false;

        if (quest->RewardFactionOverride[i])
        {
            rep = quest->RewardFactionOverride[i] / 100;
            noQuestBonus = true;
        }
        else
        {
            uint32 row = ((quest->RewardFactionValue[i] < 0) ? 1 : 0) + 1;
            if (QuestFactionRewEntry const* questFactionRewEntry = sQuestFactionRewardStore.LookupEntry(row))
            {
                uint32 field = abs(quest->RewardFactionValue[i]);
                rep = questFactionRewEntry->QuestRewFactionValue[field];
            }
        }

        if (!rep)
            continue;

        if (quest->IsDaily())
            rep = CalculateReputationGain(REPUTATION_SOURCE_DAILY_QUEST, GetQuestLevel(quest), rep, quest->RewardFactionId[i], noQuestBonus);
        else if (quest->IsWeekly())
            rep = CalculateReputationGain(REPUTATION_SOURCE_WEEKLY_QUEST, GetQuestLevel(quest), rep, quest->RewardFactionId[i], noQuestBonus);
        else if (quest->IsMonthly())
            rep = CalculateReputationGain(REPUTATION_SOURCE_MONTHLY_QUEST, GetQuestLevel(quest), rep, quest->RewardFactionId[i], noQuestBonus);
        else if (quest->IsRepeatable())
            rep = CalculateReputationGain(REPUTATION_SOURCE_REPEATABLE_QUEST, GetQuestLevel(quest), rep, quest->RewardFactionId[i], noQuestBonus);
        else
            rep = CalculateReputationGain(REPUTATION_SOURCE_QUEST, GetQuestLevel(quest), rep, quest->RewardFactionId[i], noQuestBonus);

        if (FactionEntry const* factionEntry = sFactionStore.LookupEntry(quest->RewardFactionId[i]))
            GetReputationMgr().ModifyReputation(factionEntry, rep);
    }
}

void Player::UpdateHonorFields()
{
    /// called when rewarding honor and at each save
    time_t now = time_t(time(nullptr));
    time_t today = time_t(time(nullptr) / DAY) * DAY;

    if (m_lastHonorUpdateTime < today)
    {
        time_t yesterday = today - DAY;

        // update yesterday's contribution
        if (m_lastHonorUpdateTime >= yesterday)
        {
            // this is the first update today, reset today's contribution
            uint16 killsToday = GetUInt16Value(PLAYER_FIELD_KILLS, PLAYER_FIELD_KILLS_OFFSET_TODAY_KILLS);
            SetUInt16Value(PLAYER_FIELD_KILLS, PLAYER_FIELD_KILLS_OFFSET_TODAY_KILLS, 0);
            SetUInt16Value(PLAYER_FIELD_KILLS, PLAYER_FIELD_KILLS_OFFSET_YESTERDAY_KILLS, killsToday);
        }
        else
        {
            // no honor/kills yesterday or today, reset
            SetUInt32Value(PLAYER_FIELD_KILLS, 0);
        }
    }

    m_lastHonorUpdateTime = now;
}

///Calculate the amount of honor gained based on the victim
///and the size of the group for which the honor is divided
///An exact honor value can also be given (overriding the calcs)
bool Player::RewardHonor(Unit* victim, uint32 groupsize, int32 honor, bool pvptoken)
{
    // do not reward honor in arenas, but enable onkill spellproc
    if (InArena())
    {
        if (!victim || victim == this || victim->GetTypeId() != TYPEID_PLAYER)
            return false;

        if (GetBGTeam() == victim->ToPlayer()->GetBGTeam())
            return false;

        return true;
    }

    // 'Inactive' this aura prevents the player from gaining honor points and battleground Tokenizer
    if (HasAura(SPELL_AURA_PLAYER_INACTIVE))
        return false;

    ObjectGuid victim_guid;
    uint32 victim_rank = 0;

    // need call before fields update to have chance move yesterday data to appropriate fields before today data change.
    UpdateHonorFields();

    // do not reward honor in arenas, but return true to enable onkill spellproc
    if (InBattleground() && GetBattleground() && GetBattleground()->isArena())
        return true;

    // Promote to float for calculations
    float honor_f = (float)honor;

    if (honor_f <= 0)
    {
        if (!victim || victim == this || victim->HasAuraType(SPELL_AURA_NO_PVP_CREDIT))
            return false;

        victim_guid = victim->GetGUID();

        if (Player* plrVictim = victim->ToPlayer())
        {
            if (GetTeam() == plrVictim->GetTeam() && !sWorld->IsFFAPvPRealm())
                return false;

            uint8 k_level = getLevel();
            uint8 k_grey = Trinity::XP::GetGrayLevel(k_level);
            uint8 v_level = victim->getLevel();

            if (v_level <= k_grey)
                return false;

            // PLAYER_CHOSEN_TITLE VALUES DESCRIPTION
            //  [0]      Just name
            //  [1..14]  Alliance honor titles and player name
            //  [15..28] Horde honor titles and player name
            //  [29..38] Other title and player name
            //  [39+]    Nothing
            uint32 victim_title = victim->GetUInt32Value(PLAYER_CHOSEN_TITLE);
                                                        // Get Killer titles, CharTitlesEntry::bit_index
            // Ranks:
            //  title[1..14]  -> rank[5..18]
            //  title[15..28] -> rank[5..18]
            //  title[other]  -> 0
            if (victim_title == 0)
                victim_guid.Clear();                     // Don't show HK: <rank> message, only log.
            else if (victim_title < 15)
                victim_rank = victim_title + 4;
            else if (victim_title < 29)
                victim_rank = victim_title - 14 + 4;
            else
                victim_guid.Clear();                     // Don't show HK: <rank> message, only log.

            honor_f = std::ceil(Trinity::Honor::hk_honor_at_level_f(k_level) * (v_level - k_grey) / (k_level - k_grey));

            // count the number of playerkills in one day
            ApplyModUInt16Value(PLAYER_FIELD_KILLS, PLAYER_FIELD_KILLS_OFFSET_TODAY_KILLS, 1, true);
            // and those in a lifetime
            ApplyModUInt32Value(PLAYER_FIELD_LIFETIME_HONORABLE_KILLS, 1, true);
            UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_EARN_HONORABLE_KILL);
            UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_HK_CLASS, victim->getClass());
            UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_HK_RACE, victim->getRace());
            UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_HONORABLE_KILL_AT_AREA, GetAreaId());
            UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_HONORABLE_KILL, 1, 0, 0, victim);
        }
        else
        {
            if (!victim->ToCreature()->IsRacialLeader())
                return false;

            honor_f = 100.0f;                               // ??? need more info
            victim_rank = 19;                               // HK: Leader
        }
    }

    if (victim != nullptr)
    {
        if (groupsize > 1)
            honor_f /= groupsize;

        // apply honor multiplier from aura (not stacking-get highest)
        AddPct(honor_f, GetMaxPositiveAuraModifier(SPELL_AURA_MOD_HONOR_GAIN_PCT));
    }

    honor_f *= sWorld->getRate(RATE_HONOR);
    // Back to int now
    honor = int32(honor_f);
    // honor - for show honor points in log
    // victim_guid - for show victim name in log
    // victim_rank [1..4]  HK: <dishonored rank>
    // victim_rank [5..19] HK: <alliance\horde rank>
    // victim_rank [0, 20+] HK: <>
    WorldPackets::Combat::PvPCredit data;
    data.Honor = honor;
    data.Target = victim_guid;
    data.Rank = victim_rank;

    GetSession()->SendPacket(data.Write());

    // add honor points
    ModifyCurrency(CURRENCY_TYPE_HONOR_POINTS, int32(honor));

    if (InBattleground() && honor > 0)
    {
        if (Battleground* bg = GetBattleground())
        {
            bg->UpdatePlayerScore(this, SCORE_BONUS_HONOR, honor, false); //false: prevent looping
        }
    }

    if (sWorld->getBoolConfig(CONFIG_PVP_TOKEN_ENABLE) && pvptoken)
    {
        if (!victim || victim == this || victim->HasAuraType(SPELL_AURA_NO_PVP_CREDIT))
            return true;

        if (victim->GetTypeId() == TYPEID_PLAYER)
        {
            // Check if allowed to receive it in current map
            uint8 MapType = sWorld->getIntConfig(CONFIG_PVP_TOKEN_MAP_TYPE);
            if ((MapType == 1 && !InBattleground() && !IsFFAPvP())
                || (MapType == 2 && !IsFFAPvP())
                || (MapType == 3 && !InBattleground()))
                return true;

            uint32 itemId = sWorld->getIntConfig(CONFIG_PVP_TOKEN_ID);
            int32 count = sWorld->getIntConfig(CONFIG_PVP_TOKEN_COUNT);

            if (AddItem(itemId, count))
                ChatHandler(GetSession()).PSendSysMessage("You have been awarded a token for slaying another player.");
        }
    }

    return true;
}


void Player::_LoadCurrency(PreparedQueryResult result)
{
    if (!result)
        return;

    do
    {
        Field* fields = result->Fetch();

        uint16 currencyID = fields[0].GetUInt16();

        CurrencyTypesEntry const* currency = sCurrencyTypesStore.LookupEntry(currencyID);
        if (!currency)
            continue;

        PlayerCurrency cur;
        cur.state = PLAYERCURRENCY_UNCHANGED;
        cur.Quantity = fields[1].GetUInt32();
        cur.WeeklyQuantity = fields[2].GetUInt32();
        cur.TrackedQuantity = fields[3].GetUInt32();
        cur.Flags = fields[4].GetUInt8();

        _currencyStorage.insert(PlayerCurrenciesMap::value_type(currencyID, cur));

    } while (result->NextRow());
}

void Player::_SaveCurrency(SQLTransaction& trans)
{
    PreparedStatement* stmt;
    for (PlayerCurrenciesMap::iterator itr = _currencyStorage.begin(); itr != _currencyStorage.end(); ++itr)
    {
        CurrencyTypesEntry const* entry = sCurrencyTypesStore.LookupEntry(itr->first);
        if (!entry) // should never happen
            continue;

        switch (itr->second.state)
        {
            case PLAYERCURRENCY_NEW:
                stmt = CharacterDatabase.GetPreparedStatement(CHAR_REP_PLAYER_CURRENCY);
                stmt->setUInt64(0, GetGUID().GetCounter());
                stmt->setUInt16(1, itr->first);
                stmt->setUInt32(2, itr->second.Quantity);
                stmt->setUInt32(3, itr->second.WeeklyQuantity);
                stmt->setUInt32(4, itr->second.TrackedQuantity);
                stmt->setUInt8(5, itr->second.Flags);
                trans->Append(stmt);
                break;
            case PLAYERCURRENCY_CHANGED:
                stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_PLAYER_CURRENCY);
                stmt->setUInt32(0, itr->second.Quantity);
                stmt->setUInt32(1, itr->second.WeeklyQuantity);
                stmt->setUInt32(2, itr->second.TrackedQuantity);
                stmt->setUInt8(3, itr->second.Flags);
                stmt->setUInt64(4, GetGUID().GetCounter());
                stmt->setUInt16(5, itr->first);
                trans->Append(stmt);
                break;
            default:
                break;
        }

        itr->second.state = PLAYERCURRENCY_UNCHANGED;
    }
}

void Player::SendNewCurrency(uint32 id) const
{
    PlayerCurrenciesMap::const_iterator itr = _currencyStorage.find(id);
    if (itr == _currencyStorage.end())
        return;

    CurrencyTypesEntry const* entry = sCurrencyTypesStore.LookupEntry(id);
    if (!entry) // should never happen
        return;

    WorldPackets::Misc::SetupCurrency packet;
    WorldPackets::Misc::SetupCurrency::Record record;
    record.Type = entry->ID;
    record.Quantity = itr->second.Quantity;
    record.WeeklyQuantity = itr->second.WeeklyQuantity;
    record.MaxWeeklyQuantity = GetCurrencyWeekCap(entry);
    record.TrackedQuantity = itr->second.TrackedQuantity;
    record.Flags = itr->second.Flags;

    packet.Data.push_back(record);

    GetSession()->SendPacket(packet.Write());
}

void Player::SendCurrencies() const
{
    WorldPackets::Misc::SetupCurrency packet;
    packet.Data.reserve(_currencyStorage.size());

    for (PlayerCurrenciesMap::const_iterator itr = _currencyStorage.begin(); itr != _currencyStorage.end(); ++itr)
    {
        CurrencyTypesEntry const* entry = sCurrencyTypesStore.LookupEntry(itr->first);

        // not send init meta currencies.
        if (!entry || entry->CategoryID == CURRENCY_CATEGORY_META_CONQUEST)
            continue;

        WorldPackets::Misc::SetupCurrency::Record record;
        record.Type = entry->ID;
        record.Quantity = itr->second.Quantity;
        record.WeeklyQuantity = itr->second.WeeklyQuantity;
        record.MaxWeeklyQuantity = GetCurrencyWeekCap(entry);
        record.TrackedQuantity = itr->second.TrackedQuantity;
        record.Flags = itr->second.Flags;

        packet.Data.push_back(record);
    }

    GetSession()->SendPacket(packet.Write());
}

void Player::SendPvpRewards() const
{
    WorldPacket packet(SMSG_REQUEST_PVP_REWARDS_RESPONSE, 24);
    packet << GetCurrencyWeekCap(CURRENCY_TYPE_CONQUEST_POINTS);
    packet << GetCurrencyOnWeek(CURRENCY_TYPE_CONQUEST_POINTS);
    packet << GetCurrencyWeekCap(CURRENCY_TYPE_CONQUEST_META_ARENA);
    packet << GetCurrencyOnWeek(CURRENCY_TYPE_CONQUEST_META_RBG);
    packet << GetCurrencyOnWeek(CURRENCY_TYPE_CONQUEST_META_ARENA);
    packet << GetCurrencyWeekCap(CURRENCY_TYPE_CONQUEST_POINTS);

    GetSession()->SendPacket(&packet);
}

uint32 Player::GetCurrency(uint32 id) const
{
    PlayerCurrenciesMap::const_iterator itr = _currencyStorage.find(id);
    if (itr == _currencyStorage.end())
        return 0;

    return itr->second.Quantity;
}

uint32 Player::GetCurrencyOnWeek(uint32 id) const
{
    PlayerCurrenciesMap::const_iterator itr = _currencyStorage.find(id);
    if (itr == _currencyStorage.end())
        return 0;

    return itr->second.WeeklyQuantity;
}

bool Player::HasCurrency(uint32 id, uint32 count) const
{
    PlayerCurrenciesMap::const_iterator itr = _currencyStorage.find(id);
    return itr != _currencyStorage.end() && itr->second.Quantity >= count;
}

void Player::ModifyCurrency(uint32 id, int32 count, bool printLog/* = true*/, bool ignoreMultipliers/* = false*/)
{
    if (!count)
        return;

    CurrencyTypesEntry const* currency = sCurrencyTypesStore.LookupEntry(id);
    ASSERT(currency);

    if (!ignoreMultipliers)
        count *= GetTotalAuraMultiplierByMiscValue(SPELL_AURA_MOD_CURRENCY_GAIN, id);

    uint32 oldTotalCount = 0;
    uint32 oldWeekCount = 0;
    uint32 oldTrackedCount = 0;

    PlayerCurrenciesMap::iterator itr = _currencyStorage.find(id);
    if (itr == _currencyStorage.end())
    {
        PlayerCurrency cur;
        cur.state = PLAYERCURRENCY_NEW;
        cur.Quantity = 0;
        cur.WeeklyQuantity = 0;
        cur.TrackedQuantity = 0;
        cur.Flags = 0;
        _currencyStorage[id] = cur;
        itr = _currencyStorage.find(id);
    }
    else
    {
        oldTotalCount = itr->second.Quantity;
        oldWeekCount = itr->second.WeeklyQuantity;
        oldTrackedCount = itr->second.TrackedQuantity;
    }

    // count can't be more then weekCap if used (weekCap > 0)
    uint32 weekCap = GetCurrencyWeekCap(currency);
    if (weekCap && count > int32(weekCap))
        count = weekCap;

    // count can't be more then totalCap if used (totalCap > 0)
    uint32 totalCap = GetCurrencyTotalCap(currency);
    if (totalCap && count > int32(totalCap))
        count = totalCap;

    int32 newTrackedCount = int32(oldTrackedCount) + (count > 0 ? count : 0);
    if (newTrackedCount < 0)
        newTrackedCount = 0;

    int32 newTotalCount = int32(oldTotalCount) + count;
    if (newTotalCount < 0)
        newTotalCount = 0;

    int32 newWeekCount = int32(oldWeekCount) + (count > 0 ? count : 0);
    if (newWeekCount < 0)
        newWeekCount = 0;

    // if we get more then weekCap just set to limit
    if (weekCap && int32(weekCap) < newWeekCount)
    {
        newWeekCount = int32(weekCap);
        // weekCap - oldWeekCount always >= 0 as we set limit before!
        newTotalCount = oldTotalCount + (weekCap - oldWeekCount);
    }

    // if we get more then totalCap set to maximum;
    if (totalCap && int32(totalCap) < newTotalCount)
    {
        newTotalCount = int32(totalCap);
        newWeekCount = weekCap;
    }

    if (uint32(newTotalCount) != oldTotalCount)
    {
        if (itr->second.state != PLAYERCURRENCY_NEW)
            itr->second.state = PLAYERCURRENCY_CHANGED;

        itr->second.Quantity = newTotalCount;
        itr->second.WeeklyQuantity = newWeekCount;
        itr->second.TrackedQuantity = newTrackedCount;

        if (count > 0)
            UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_CURRENCY, id, count);

        CurrencyChanged(id, count);

        if (currency->CategoryID == CURRENCY_CATEGORY_META_CONQUEST)
        {
            // count was changed to week limit, now we can modify original points.
            ModifyCurrency(CURRENCY_TYPE_CONQUEST_POINTS, count, printLog);
            return;
        }

        WorldPackets::Misc::SetCurrency packet;
        packet.Type = id;
        packet.Quantity = newTotalCount;
        packet.SuppressChatLog = !printLog;
        packet.WeeklyQuantity = newWeekCount;
        packet.TrackedQuantity = newTrackedCount;
        packet.Flags = itr->second.Flags;

        GetSession()->SendPacket(packet.Write());
    }
}

void Player::SetCurrency(uint32 id, uint32 count, bool /*printLog*/ /*= true*/)
{
    PlayerCurrenciesMap::iterator itr = _currencyStorage.find(id);
    if (itr == _currencyStorage.end())
    {
        PlayerCurrency cur;
        cur.state = PLAYERCURRENCY_NEW;
        cur.Quantity = count;
        cur.WeeklyQuantity = 0;
        cur.TrackedQuantity = 0;
        cur.Flags = 0;
        _currencyStorage[id] = cur;
    }
}

uint32 Player::GetCurrencyWeekCap(uint32 id) const
{
    CurrencyTypesEntry const* entry = sCurrencyTypesStore.LookupEntry(id);
    if (!entry)
        return 0;

    return GetCurrencyWeekCap(entry);
}

void Player::ResetCurrencyWeekCap()
{
    for (uint32 arenaSlot = 0; arenaSlot < MAX_ARENA_SLOT; arenaSlot++)
    {
        if (uint32 arenaTeamId = GetArenaTeamId(arenaSlot))
        {
            ArenaTeam* arenaTeam = sArenaTeamMgr->GetArenaTeamById(arenaTeamId);
            ASSERT(arenaTeam);
            arenaTeam->FinishWeek();                              // set played this week etc values to 0 in memory, too
            arenaTeam->SaveToDB();                                // save changes
            arenaTeam->NotifyStatsChanged();                      // notify the players of the changes
        }
    }

    for (PlayerCurrenciesMap::iterator itr = _currencyStorage.begin(); itr != _currencyStorage.end(); ++itr)
    {
        itr->second.WeeklyQuantity = 0;
        itr->second.state = PLAYERCURRENCY_CHANGED;
    }

    WorldPacket data(SMSG_RESET_WEEKLY_CURRENCY, 0);
    SendDirectMessage(&data);
}

uint32 Player::GetCurrencyWeekCap(CurrencyTypesEntry const* currency) const
{
    switch (currency->ID)
    {
            //original conquest not have week cap
        case CURRENCY_TYPE_CONQUEST_POINTS:
            return std::max(GetCurrencyWeekCap(CURRENCY_TYPE_CONQUEST_META_ARENA), GetCurrencyWeekCap(CURRENCY_TYPE_CONQUEST_META_RBG));
        case CURRENCY_TYPE_CONQUEST_META_ARENA:
            // should add precision mod = 100
            return Trinity::Currency::ConquestRatingCalculator(_maxPersonalArenaRate) * CURRENCY_PRECISION;
        case CURRENCY_TYPE_CONQUEST_META_RBG:
            // should add precision mod = 100
            return Trinity::Currency::BgConquestRatingCalculator(GetRBGPersonalRating()) * CURRENCY_PRECISION;
    }

    return currency->MaxEarnablePerWeek;
}

uint32 Player::GetCurrencyTotalCap(CurrencyTypesEntry const* currency) const
{
    // @TODO: Possibly use caps from CurrencyTypes.dbc
    uint32 cap = currency->MaxQty;

    switch (currency->ID)
    {
        case CURRENCY_TYPE_HONOR_POINTS:
        {
            uint32 honorcap = sWorld->getIntConfig(CONFIG_CURRENCY_MAX_HONOR_POINTS);
            if (honorcap > 0)
                cap = honorcap;
            break;
        }
        case CURRENCY_TYPE_APEXIS_CRYSTALS:
        {
            uint32 apexiscap = sWorld->getIntConfig(CONFIG_CURRENCY_MAX_APEXIS_CRYSTALS);
            if (apexiscap > 0)
                cap = apexiscap;
            break;
        }
        case CURRENCY_TYPE_JUSTICE_POINTS:
        {
            uint32 justicecap = sWorld->getIntConfig(CONFIG_CURRENCY_MAX_JUSTICE_POINTS);
            if (justicecap > 0)
                cap = justicecap;
            break;
        }
    }

    return cap;
}

void Player::UpdateConquestCurrencyCap(uint32 currency) const
{
    uint32 currenciesToUpdate[2] = { currency, CURRENCY_TYPE_CONQUEST_POINTS };

    for (uint32 i = 0; i < 2; ++i)
    {
        CurrencyTypesEntry const* currencyEntry = sCurrencyTypesStore.LookupEntry(currenciesToUpdate[i]);
        if (!currencyEntry)
            continue;

        WorldPacket packet(SMSG_SET_MAX_WEEKLY_QUANTITY, 8);
        packet << uint32(GetCurrencyWeekCap(currencyEntry));
        packet << uint32(currenciesToUpdate[i]);
        GetSession()->SendPacket(&packet);
    }
}

void Player::SetInGuild(ObjectGuid::LowType guildId)
{
    if (guildId)
        SetGuidValue(OBJECT_FIELD_DATA, ObjectGuid::Create<HighGuid::Guild>(guildId));
    else
        SetGuidValue(OBJECT_FIELD_DATA, ObjectGuid::Empty);

    ApplyModFlag(PLAYER_FLAGS, PLAYER_FLAGS_GUILD_LEVEL_ENABLED, guildId != 0);
    SetUInt16Value(OBJECT_FIELD_TYPE, 1, guildId != 0);
}

ObjectGuid::LowType Player::GetGuildIdFromDB(ObjectGuid guid)
{
    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_GUILD_MEMBER);
    stmt->setUInt64(0, guid.GetCounter());
    if (PreparedQueryResult result = CharacterDatabase.Query(stmt))
        return result->Fetch()[0].GetUInt64();

    return UI64LIT(0);
}

uint8 Player::GetRankFromDB(ObjectGuid guid)
{
    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_GUILD_MEMBER);
    stmt->setUInt64(0, guid.GetCounter());
    if (PreparedQueryResult result = CharacterDatabase.Query(stmt))
        return result->Fetch()[1].GetUInt8();

    return 0;
}

void Player::SetArenaTeamInfoField(uint8 slot, ArenaTeamInfoType type, uint32 value)
{
    SetUInt32Value(PLAYER_FIELD_ARENA_TEAM_INFO_1_1 + (slot * ARENA_TEAM_END) + type, value);
    if (type == ARENA_TEAM_PERSONAL_RATING && value > _maxPersonalArenaRate)
    {
        _maxPersonalArenaRate = value;
        UpdateConquestCurrencyCap(CURRENCY_TYPE_CONQUEST_META_ARENA);
    }
}

void Player::SetInArenaTeam(uint32 ArenaTeamId, uint8 slot, uint8 type)
{
    SetArenaTeamInfoField(slot, ARENA_TEAM_ID, ArenaTeamId);
    SetArenaTeamInfoField(slot, ARENA_TEAM_TYPE, type);
}

uint32 Player::GetArenaTeamIdFromDB(ObjectGuid guid, uint8 type)
{
    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_ARENA_TEAM_ID_BY_PLAYER_GUID);
    stmt->setUInt64(0, guid.GetCounter());
    stmt->setUInt8(1, type);
    PreparedQueryResult result = CharacterDatabase.Query(stmt);

    if (!result)
        return 0;

    uint32 id = (*result)[0].GetUInt32();
    return id;
}

uint32 Player::GetZoneIdFromDB(ObjectGuid guid)
{
    ObjectGuid::LowType guidLow = guid.GetCounter();
    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHAR_ZONE);
    stmt->setUInt64(0, guidLow);
    PreparedQueryResult result = CharacterDatabase.Query(stmt);

    if (!result)
        return 0;
    Field* fields = result->Fetch();
    uint32 zone = fields[0].GetUInt16();

    if (!zone)
    {
        // stored zone is zero, use generic and slow zone detection
        stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHAR_POSITION_XYZ);
        stmt->setUInt64(0, guidLow);
        result = CharacterDatabase.Query(stmt);

        if (!result)
            return 0;
        fields = result->Fetch();
        uint32 map = fields[0].GetUInt16();
        float posx = fields[1].GetFloat();
        float posy = fields[2].GetFloat();
        float posz = fields[3].GetFloat();

        if (!sMapStore.LookupEntry(map))
            return 0;

        zone = sMapMgr->GetZoneId(map, posx, posy, posz);

        if (zone > 0)
        {
            stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_ZONE);

            stmt->setUInt16(0, uint16(zone));
            stmt->setUInt64(1, guidLow);

            CharacterDatabase.Execute(stmt);
        }
    }

    return zone;
}

uint32 Player::GetLevelFromDB(ObjectGuid guid)
{
    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHAR_LEVEL);
    stmt->setUInt64(0, guid.GetCounter());
    PreparedQueryResult result = CharacterDatabase.Query(stmt);

    if (!result)
        return 0;

    Field* fields = result->Fetch();
    uint8 level = fields[0].GetUInt8();

    return level;
}

void Player::UpdateArea(uint32 newArea)
{
    // FFA_PVP flags are area and not zone id dependent
    // so apply them accordingly
    m_areaUpdateId = newArea;

    AreaTableEntry const* area = sAreaTableStore.LookupEntry(newArea);
    pvpInfo.IsInFFAPvPArea = area && (area->Flags[0] & AREA_FLAG_ARENA);
    UpdatePvPState(true);

    UpdateAreaDependentAuras(newArea);
    UpdateAreaPhase();

    // previously this was in UpdateZone (but after UpdateArea) so nothing will break
    pvpInfo.IsInNoPvPArea = false;
    if (area && area->IsSanctuary())    // in sanctuary
    {
        SetByteFlag(UNIT_FIELD_BYTES_2, 1, UNIT_BYTE2_FLAG_SANCTUARY);
        pvpInfo.IsInNoPvPArea = true;
        if (!duel)
            CombatStopWithPets();
    }
    else
        RemoveByteFlag(UNIT_FIELD_BYTES_2, 1, UNIT_BYTE2_FLAG_SANCTUARY);

    uint32 const areaRestFlag = (GetTeam() == ALLIANCE) ? AREA_FLAG_REST_ZONE_ALLIANCE : AREA_FLAG_REST_ZONE_HORDE;
    if (area && area->Flags[0] & areaRestFlag)
        SetRestFlag(REST_FLAG_IN_FACTION_AREA);
    else
        RemoveRestFlag(REST_FLAG_IN_FACTION_AREA);
}

void Player::UpdateZone(uint32 newZone, uint32 newArea)
{
    if (m_zoneUpdateId != newZone)
    {
        sOutdoorPvPMgr->HandlePlayerLeaveZone(this, m_zoneUpdateId);
        sOutdoorPvPMgr->HandlePlayerEnterZone(this, newZone);
        sBattlefieldMgr->HandlePlayerLeaveZone(this, m_zoneUpdateId);
        sBattlefieldMgr->HandlePlayerEnterZone(this, newZone);
        SendInitWorldStates(newZone, newArea);              // only if really enters to new zone, not just area change, works strange...
        if (Guild* guild = GetGuild())
            guild->UpdateMemberData(this, GUILD_MEMBER_DATA_ZONEID, newZone);
    }

    // group update
    if (GetGroup())
    {
        SetGroupUpdateFlag(GROUP_UPDATE_FULL);
        if (Pet* pet = GetPet())
            pet->SetGroupUpdateFlag(GROUP_UPDATE_PET_FULL);
    }

    m_zoneUpdateId    = newZone;
    m_zoneUpdateTimer = ZONE_UPDATE_INTERVAL;

    // zone changed, so area changed as well, update it
    UpdateArea(newArea);

    AreaTableEntry const* zone = sAreaTableStore.LookupEntry(newZone);
    if (!zone)
        return;

    if (sWorld->getBoolConfig(CONFIG_WEATHER) && !HasAuraType(SPELL_AURA_FORCE_WEATHER))
    {
        if (Weather* weather = WeatherMgr::FindWeather(zone->ID))
            weather->SendWeatherUpdateToPlayer(this);
        else if (!WeatherMgr::AddWeather(zone->ID))
            // send fine weather packet to remove old zone's weather
            WeatherMgr::SendFineWeatherUpdateToPlayer(this);
    }

    sScriptMgr->OnPlayerUpdateZone(this, newZone, newArea);

    // in PvP, any not controlled zone (except zone->team == 6, default case)
    // in PvE, only opposition team capital
    switch (zone->FactionGroupMask)
    {
        case AREATEAM_ALLY:
            pvpInfo.IsInHostileArea = GetTeam() != ALLIANCE && (sWorld->IsPvPRealm() || zone->Flags[0] & AREA_FLAG_CAPITAL);
            break;
        case AREATEAM_HORDE:
            pvpInfo.IsInHostileArea = GetTeam() != HORDE && (sWorld->IsPvPRealm() || zone->Flags[0] & AREA_FLAG_CAPITAL);
            break;
        case AREATEAM_NONE:
            // overwrite for battlegrounds, maybe batter some zone flags but current known not 100% fit to this
            pvpInfo.IsInHostileArea = sWorld->IsPvPRealm() || InBattleground() || zone->Flags[0] & AREA_FLAG_WINTERGRASP;
            break;
        default:                                            // 6 in fact
            pvpInfo.IsInHostileArea = false;
            break;
    }

    // Treat players having a quest flagging for PvP as always in hostile area
    pvpInfo.IsHostile = pvpInfo.IsInHostileArea || HasPvPForcingQuest();

    if (zone->Flags[0] & AREA_FLAG_CAPITAL) // Is in a capital city
    {
        if (!pvpInfo.IsHostile || zone->IsSanctuary())
            SetRestFlag(REST_FLAG_IN_CITY);
        pvpInfo.IsInNoPvPArea = true;
    }
    else
        RemoveRestFlag(REST_FLAG_IN_CITY);

    UpdatePvPState();

    // remove items with area/map limitations (delete only for alive player to allow back in ghost mode)
    // if player resurrected at teleport this will be applied in resurrect code
    if (IsAlive())
        DestroyZoneLimitedItem(true, newZone);

    // check some item equip limitations (in result lost CanTitanGrip at talent reset, for example)
    AutoUnequipOffhandIfNeed();

    // recent client version not send leave/join channel packets for built-in local channels
    UpdateLocalChannels(newZone);

    UpdateZoneDependentAuras(newZone);

    UpdateAreaPhase();
}

//If players are too far away from the duel flag... they lose the duel
void Player::CheckDuelDistance(time_t currTime)
{
    if (!duel)
        return;

    ObjectGuid duelFlagGUID = GetGuidValue(PLAYER_DUEL_ARBITER);
    GameObject* obj = GetMap()->GetGameObject(duelFlagGUID);
    if (!obj)
        return;

    if (duel->outOfBound == 0)
    {
        if (!IsWithinDistInMap(obj, 50))
        {
            duel->outOfBound = currTime;

            GetSession()->SendPacket(WorldPackets::Duel::DuelOutOfBounds().Write());
        }
    }
    else
    {
        if (IsWithinDistInMap(obj, 40))
        {
            duel->outOfBound = 0;

            GetSession()->SendPacket(WorldPackets::Duel::DuelInBounds().Write());
        }
        else if (currTime >= (duel->outOfBound+10))
            DuelComplete(DUEL_FLED);
    }
}

bool Player::IsOutdoorPvPActive() const
{
    return IsAlive() && !HasInvisibilityAura() && !HasStealthAura() && IsPvP() && !HasUnitMovementFlag(MOVEMENTFLAG_FLYING) && !IsInFlight();
}

void Player::DuelComplete(DuelCompleteType type)
{
    // duel not requested
    if (!duel)
        return;

    TC_LOG_DEBUG("entities.unit", "Player::DuelComplete: Player '%s' (%s), Opponent: '%s' (%s)",
        GetName().c_str(), GetGUID().ToString().c_str(), duel->opponent->GetName().c_str(), duel->opponent->GetGUID().ToString().c_str());

    WorldPackets::Duel::DuelComplete duelCompleted;
    duelCompleted.Started = type != DUEL_INTERRUPTED;
    WorldPacket const* duelCompletedPacket = duelCompleted.Write();
    GetSession()->SendPacket(duelCompletedPacket);

    if (duel->opponent->GetSession())
        duel->opponent->GetSession()->SendPacket(duelCompletedPacket);

    if (type != DUEL_INTERRUPTED)
    {
        WorldPackets::Duel::DuelWinner duelWinner;
        duelWinner.BeatenName = (type == DUEL_WON ? duel->opponent->GetName() : GetName());
        duelWinner.WinnerName = (type == DUEL_WON ? GetName() : duel->opponent->GetName());
        duelWinner.BeatenVirtualRealmAddress = GetVirtualRealmAddress();
        duelWinner.WinnerVirtualRealmAddress = GetVirtualRealmAddress();
        duelWinner.Fled = type != DUEL_WON;

        SendMessageToSet(duelWinner.Write(), true);
    }

    sScriptMgr->OnPlayerDuelEnd(duel->opponent, this, type);

    switch (type)
    {
        case DUEL_FLED:
            // if initiator and opponent are on the same team
            // or initiator and opponent are not PvP enabled, forcibly stop attacking
            if (duel->initiator->GetTeam() == duel->opponent->GetTeam())
            {
                duel->initiator->AttackStop();
                duel->opponent->AttackStop();
            }
            else
            {
                if (!duel->initiator->IsPvP())
                    duel->initiator->AttackStop();
                if (!duel->opponent->IsPvP())
                    duel->opponent->AttackStop();
            }
            break;
        case DUEL_WON:
            UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_LOSE_DUEL, 1);
            duel->opponent->UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_WIN_DUEL, 1);

            // Credit for quest Death's Challenge
            if (getClass() == CLASS_DEATH_KNIGHT && duel->opponent->GetQuestStatus(12733) == QUEST_STATUS_INCOMPLETE)
                duel->opponent->CastSpell(duel->opponent, 52994, true);

            // Honor points after duel (the winner) - ImpConfig
            if (uint32 amount = sWorld->getIntConfig(CONFIG_HONOR_AFTER_DUEL))
                duel->opponent->RewardHonor(nullptr, 1, amount);

            break;
        default:
            break;
    }

    // Victory emote spell
    if (type != DUEL_INTERRUPTED)
        duel->opponent->CastSpell(duel->opponent, 52852, true);

    //Remove Duel Flag object
    GameObject* obj = GetMap()->GetGameObject(GetGuidValue(PLAYER_DUEL_ARBITER));
    if (obj)
        duel->initiator->RemoveGameObject(obj, true);

    /* remove auras */
    AuraApplicationMap &itsAuras = duel->opponent->GetAppliedAuras();
    for (AuraApplicationMap::iterator i = itsAuras.begin(); i != itsAuras.end();)
    {
        Aura const* aura = i->second->GetBase();
        if (!i->second->IsPositive() && aura->GetCasterGUID() == GetGUID() && aura->GetApplyTime() >= duel->startTime)
            duel->opponent->RemoveAura(i);
        else
            ++i;
    }

    AuraApplicationMap &myAuras = GetAppliedAuras();
    for (AuraApplicationMap::iterator i = myAuras.begin(); i != myAuras.end();)
    {
        Aura const* aura = i->second->GetBase();
        if (!i->second->IsPositive() && aura->GetCasterGUID() == duel->opponent->GetGUID() && aura->GetApplyTime() >= duel->startTime)
            RemoveAura(i);
        else
            ++i;
    }

    // cleanup combo points
    ClearComboPoints();
    duel->opponent->ClearComboPoints();

    //cleanups
    SetGuidValue(PLAYER_DUEL_ARBITER, ObjectGuid::Empty);
    SetUInt32Value(PLAYER_DUEL_TEAM, 0);
    duel->opponent->SetGuidValue(PLAYER_DUEL_ARBITER, ObjectGuid::Empty);
    duel->opponent->SetUInt32Value(PLAYER_DUEL_TEAM, 0);

    delete duel->opponent->duel;
    duel->opponent->duel = nullptr;
    delete duel;
    duel = nullptr;
}

//---------------------------------------------------------//

void Player::_ApplyItemMods(Item* item, uint8 slot, bool apply)
{
    if (slot >= INVENTORY_SLOT_BAG_END || !item)
        return;

    ItemTemplate const* proto = item->GetTemplate();

    if (!proto)
        return;

    // not apply/remove mods for broken item
    if (item->IsBroken())
        return;

    TC_LOG_DEBUG("entities.player.items", "Player::_ApplyItemMods: Applying mods for item %s", item->GetGUID().ToString().c_str());

    uint8 attacktype = Player::GetAttackBySlot(slot, item->GetTemplate()->GetInventoryType());

    if (item->GetSocketColor(0))                              //only (un)equipping of items with sockets can influence metagems, so no need to waste time with normal items
        CorrectMetaGemEnchants(slot, apply);

    if (attacktype < MAX_ATTACK)
        _ApplyWeaponDependentAuraMods(item, WeaponAttackType(attacktype), apply);

    _ApplyItemBonuses(item, slot, apply);
    ApplyItemEquipSpell(item, apply);
    ApplyEnchantment(item, apply);

    TC_LOG_DEBUG("entities.player.items", "Player::_ApplyItemMods: completed");
}

void Player::_ApplyItemBonuses(Item* item, uint8 slot, bool apply)
{
    ItemTemplate const* proto = item->GetTemplate();
    if (slot >= INVENTORY_SLOT_BAG_END || !proto)
        return;

    // req. check at equip, but allow use for extended range if range limit max level, set proper level
    for (uint8 i = 0; i < MAX_ITEM_PROTO_STATS; ++i)
    {
        int32 statType = item->GetItemStatType(i);
        if (statType == -1)
            continue;

        int32 val = item->GetItemStatValue(i, this);
        if (val == 0)
            continue;

        switch (statType)
        {
            case ITEM_MOD_MANA:
                HandleStatModifier(UNIT_MOD_MANA, BASE_VALUE, float(val), apply);
                break;
            case ITEM_MOD_HEALTH:                           // modify HP
                HandleStatModifier(UNIT_MOD_HEALTH, BASE_VALUE, float(val), apply);
                break;
            case ITEM_MOD_AGILITY:                          // modify agility
                HandleStatModifier(UNIT_MOD_STAT_AGILITY, BASE_VALUE, float(val), apply);
                ApplyStatBuffMod(STAT_AGILITY, CalculatePct(val, GetModifierValue(UNIT_MOD_STAT_AGILITY, BASE_PCT_EXCLUDE_CREATE)), apply);
                break;
            case ITEM_MOD_STRENGTH:                         //modify strength
                HandleStatModifier(UNIT_MOD_STAT_STRENGTH, BASE_VALUE, float(val), apply);
                ApplyStatBuffMod(STAT_STRENGTH, CalculatePct(val, GetModifierValue(UNIT_MOD_STAT_STRENGTH, BASE_PCT_EXCLUDE_CREATE)), apply);
                break;
            case ITEM_MOD_INTELLECT:                        //modify intellect
                HandleStatModifier(UNIT_MOD_STAT_INTELLECT, BASE_VALUE, float(val), apply);
                ApplyStatBuffMod(STAT_INTELLECT, CalculatePct(val, GetModifierValue(UNIT_MOD_STAT_INTELLECT, BASE_PCT_EXCLUDE_CREATE)), apply);
                break;
            case ITEM_MOD_SPIRIT:                           //modify spirit
                HandleStatModifier(UNIT_MOD_STAT_SPIRIT, BASE_VALUE, float(val), apply);
                ApplyStatBuffMod(STAT_SPIRIT, CalculatePct(val, GetModifierValue(UNIT_MOD_STAT_SPIRIT, BASE_PCT_EXCLUDE_CREATE)), apply);
                break;
            case ITEM_MOD_STAMINA:                          //modify stamina
                HandleStatModifier(UNIT_MOD_STAT_STAMINA, BASE_VALUE, float(val), apply);
                ApplyStatBuffMod(STAT_STAMINA, CalculatePct(val, GetModifierValue(UNIT_MOD_STAT_STAMINA, BASE_PCT_EXCLUDE_CREATE)), apply);
                break;
            case ITEM_MOD_DEFENSE_SKILL_RATING:
                ApplyRatingMod(CR_DEFENSE_SKILL, int32(val), apply);
                break;
            case ITEM_MOD_DODGE_RATING:
                ApplyRatingMod(CR_DODGE, int32(val), apply);
                break;
            case ITEM_MOD_PARRY_RATING:
                ApplyRatingMod(CR_PARRY, int32(val), apply);
                break;
            case ITEM_MOD_BLOCK_RATING:
                ApplyRatingMod(CR_BLOCK, int32(val), apply);
                break;
            case ITEM_MOD_HIT_MELEE_RATING:
                ApplyRatingMod(CR_HIT_MELEE, int32(val), apply);
                break;
            case ITEM_MOD_HIT_RANGED_RATING:
                ApplyRatingMod(CR_HIT_RANGED, int32(val), apply);
                break;
            case ITEM_MOD_HIT_SPELL_RATING:
                ApplyRatingMod(CR_HIT_SPELL, int32(val), apply);
                break;
            case ITEM_MOD_CRIT_MELEE_RATING:
                ApplyRatingMod(CR_CRIT_MELEE, int32(val), apply);
                break;
            case ITEM_MOD_CRIT_RANGED_RATING:
                ApplyRatingMod(CR_CRIT_RANGED, int32(val), apply);
                break;
            case ITEM_MOD_CRIT_SPELL_RATING:
                ApplyRatingMod(CR_CRIT_SPELL, int32(val), apply);
                break;
            // case ITEM_MOD_HIT_TAKEN_MELEE_RATING:
            //     ApplyRatingMod(CR_HIT_TAKEN_MELEE, int32(val), apply);
            //     break;
            // case ITEM_MOD_HIT_TAKEN_RANGED_RATING:
            //     ApplyRatingMod(CR_HIT_TAKEN_RANGED, int32(val), apply);
            //     break;
            // case ITEM_MOD_HIT_TAKEN_SPELL_RATING:
            //     ApplyRatingMod(CR_HIT_TAKEN_SPELL, int32(val), apply);
            //     break;
            // case ITEM_MOD_CRIT_TAKEN_MELEE_RATING:
            //     ApplyRatingMod(CR_CRIT_TAKEN_MELEE, int32(val), apply);
            //     break;
            case ITEM_MOD_CRIT_TAKEN_RANGED_RATING:
                ApplyRatingMod(CR_RESILIENCE_PLAYER_DAMAGE_TAKEN, int32(val), apply);
                break;
            // case ITEM_MOD_CRIT_TAKEN_SPELL_RATING:
            //     ApplyRatingMod(CR_CRIT_TAKEN_SPELL, int32(val), apply);
            //     break;
            case ITEM_MOD_HASTE_MELEE_RATING:
                ApplyRatingMod(CR_HASTE_MELEE, int32(val), apply);
                break;
            case ITEM_MOD_HASTE_RANGED_RATING:
                ApplyRatingMod(CR_HASTE_RANGED, int32(val), apply);
                break;
            case ITEM_MOD_HASTE_SPELL_RATING:
                ApplyRatingMod(CR_HASTE_SPELL, int32(val), apply);
                break;
            case ITEM_MOD_HIT_RATING:
                ApplyRatingMod(CR_HIT_MELEE, int32(val), apply);
                ApplyRatingMod(CR_HIT_RANGED, int32(val), apply);
                ApplyRatingMod(CR_HIT_SPELL, int32(val), apply);
                break;
            case ITEM_MOD_CRIT_RATING:
                ApplyRatingMod(CR_CRIT_MELEE, int32(val), apply);
                ApplyRatingMod(CR_CRIT_RANGED, int32(val), apply);
                ApplyRatingMod(CR_CRIT_SPELL, int32(val), apply);
                break;
            // case ITEM_MOD_HIT_TAKEN_RATING: // Unused since 3.3.5
            //     ApplyRatingMod(CR_HIT_TAKEN_MELEE, int32(val), apply);
            //     ApplyRatingMod(CR_HIT_TAKEN_RANGED, int32(val), apply);
            //     ApplyRatingMod(CR_HIT_TAKEN_SPELL, int32(val), apply);
            //     break;
            // case ITEM_MOD_CRIT_TAKEN_RATING: // Unused since 3.3.5
            //     ApplyRatingMod(CR_CRIT_TAKEN_MELEE, int32(val), apply);
            //     ApplyRatingMod(CR_CRIT_TAKEN_RANGED, int32(val), apply);
            //     ApplyRatingMod(CR_CRIT_TAKEN_SPELL, int32(val), apply);
            //     break;
            case ITEM_MOD_RESILIENCE_RATING:
                ApplyRatingMod(CR_RESILIENCE_PLAYER_DAMAGE_TAKEN, int32(val), apply);
                break;
            case ITEM_MOD_HASTE_RATING:
                ApplyRatingMod(CR_HASTE_MELEE, int32(val), apply);
                ApplyRatingMod(CR_HASTE_RANGED, int32(val), apply);
                ApplyRatingMod(CR_HASTE_SPELL, int32(val), apply);
                break;
            case ITEM_MOD_EXPERTISE_RATING:
                ApplyRatingMod(CR_EXPERTISE, int32(val), apply);
                break;
            case ITEM_MOD_ATTACK_POWER:
                HandleStatModifier(UNIT_MOD_ATTACK_POWER, TOTAL_VALUE, float(val), apply);
                HandleStatModifier(UNIT_MOD_ATTACK_POWER_RANGED, TOTAL_VALUE, float(val), apply);
                break;
            case ITEM_MOD_RANGED_ATTACK_POWER:
                HandleStatModifier(UNIT_MOD_ATTACK_POWER_RANGED, TOTAL_VALUE, float(val), apply);
                break;
            case ITEM_MOD_MANA_REGENERATION:
                ApplyManaRegenBonus(int32(val), apply);
                break;
            case ITEM_MOD_ARMOR_PENETRATION_RATING:
                ApplyRatingMod(CR_ARMOR_PENETRATION, int32(val), apply);
                break;
            case ITEM_MOD_SPELL_POWER:
                ApplySpellPowerBonus(int32(val), apply);
                break;
            case ITEM_MOD_HEALTH_REGEN:
                ApplyHealthRegenBonus(int32(val), apply);
                break;
            case ITEM_MOD_SPELL_PENETRATION:
                ApplySpellPenetrationBonus(val, apply);
                break;
            case ITEM_MOD_MASTERY_RATING:
                ApplyRatingMod(CR_MASTERY, int32(val), apply);
                break;
            case ITEM_MOD_FIRE_RESISTANCE:
                HandleStatModifier(UNIT_MOD_RESISTANCE_FIRE, BASE_VALUE, float(val), apply);
                break;
            case ITEM_MOD_FROST_RESISTANCE:
                HandleStatModifier(UNIT_MOD_RESISTANCE_FROST, BASE_VALUE, float(val), apply);
                break;
            case ITEM_MOD_HOLY_RESISTANCE:
                HandleStatModifier(UNIT_MOD_RESISTANCE_HOLY, BASE_VALUE, float(val), apply);
                break;
            case ITEM_MOD_SHADOW_RESISTANCE:
                HandleStatModifier(UNIT_MOD_RESISTANCE_SHADOW, BASE_VALUE, float(val), apply);
                break;
            case ITEM_MOD_NATURE_RESISTANCE:
                HandleStatModifier(UNIT_MOD_RESISTANCE_NATURE, BASE_VALUE, float(val), apply);
                break;
            case ITEM_MOD_ARCANE_RESISTANCE:
                HandleStatModifier(UNIT_MOD_RESISTANCE_ARCANE, BASE_VALUE, float(val), apply);
                break;
            case ITEM_MOD_AGI_STR_INT:
                HandleStatModifier(UNIT_MOD_STAT_AGILITY, BASE_VALUE, float(val), apply);
                HandleStatModifier(UNIT_MOD_STAT_STRENGTH, BASE_VALUE, float(val), apply);
                HandleStatModifier(UNIT_MOD_STAT_INTELLECT, BASE_VALUE, float(val), apply);
                ApplyStatBuffMod(STAT_AGILITY, CalculatePct(val, GetModifierValue(UNIT_MOD_STAT_AGILITY, BASE_PCT_EXCLUDE_CREATE)), apply);
                ApplyStatBuffMod(STAT_STRENGTH, CalculatePct(val, GetModifierValue(UNIT_MOD_STAT_STRENGTH, BASE_PCT_EXCLUDE_CREATE)), apply);
                ApplyStatBuffMod(STAT_INTELLECT, CalculatePct(val, GetModifierValue(UNIT_MOD_STAT_INTELLECT, BASE_PCT_EXCLUDE_CREATE)), apply);
                break;
            case ITEM_MOD_AGI_STR:
                HandleStatModifier(UNIT_MOD_STAT_AGILITY, BASE_VALUE, float(val), apply);
                HandleStatModifier(UNIT_MOD_STAT_STRENGTH, BASE_VALUE, float(val), apply);
                ApplyStatBuffMod(STAT_AGILITY, CalculatePct(val, GetModifierValue(UNIT_MOD_STAT_AGILITY, BASE_PCT_EXCLUDE_CREATE)), apply);
                ApplyStatBuffMod(STAT_STRENGTH, CalculatePct(val, GetModifierValue(UNIT_MOD_STAT_STRENGTH, BASE_PCT_EXCLUDE_CREATE)), apply);
                break;
            case ITEM_MOD_AGI_INT:
                HandleStatModifier(UNIT_MOD_STAT_AGILITY, BASE_VALUE, float(val), apply);
                HandleStatModifier(UNIT_MOD_STAT_INTELLECT, BASE_VALUE, float(val), apply);
                ApplyStatBuffMod(STAT_AGILITY, CalculatePct(val, GetModifierValue(UNIT_MOD_STAT_AGILITY, BASE_PCT_EXCLUDE_CREATE)), apply);
                ApplyStatBuffMod(STAT_INTELLECT, CalculatePct(val, GetModifierValue(UNIT_MOD_STAT_INTELLECT, BASE_PCT_EXCLUDE_CREATE)), apply);
                break;
            case ITEM_MOD_STR_INT:
                HandleStatModifier(UNIT_MOD_STAT_STRENGTH, BASE_VALUE, float(val), apply);
                HandleStatModifier(UNIT_MOD_STAT_INTELLECT, BASE_VALUE, float(val), apply);
                ApplyStatBuffMod(STAT_STRENGTH, CalculatePct(val, GetModifierValue(UNIT_MOD_STAT_STRENGTH, BASE_PCT_EXCLUDE_CREATE)), apply);
                ApplyStatBuffMod(STAT_INTELLECT, CalculatePct(val, GetModifierValue(UNIT_MOD_STAT_INTELLECT, BASE_PCT_EXCLUDE_CREATE)), apply);
                break;
        }
    }

    if (uint32 armor = item->GetArmor(this))
    {
        UnitModifierType modType = TOTAL_VALUE;
        if (proto->GetClass() == ITEM_CLASS_ARMOR)
        {
            switch (proto->GetSubClass())
            {
                case ITEM_SUBCLASS_ARMOR_CLOTH:
                case ITEM_SUBCLASS_ARMOR_LEATHER:
                case ITEM_SUBCLASS_ARMOR_MAIL:
                case ITEM_SUBCLASS_ARMOR_PLATE:
                case ITEM_SUBCLASS_ARMOR_SHIELD:
                    modType = BASE_VALUE;
                break;
            }
        }

        HandleStatModifier(UNIT_MOD_ARMOR, modType, float(armor), apply);
    }

    /*
    if (proto->GetArmorDamageModifier() > 0)
        HandleStatModifier(UNIT_MOD_ARMOR, TOTAL_VALUE, float(proto->GetArmorDamageModifier()), apply);
    */

    WeaponAttackType attType = BASE_ATTACK;

    if (slot == EQUIPMENT_SLOT_MAINHAND && (proto->GetInventoryType() == INVTYPE_RANGED || proto->GetInventoryType() == INVTYPE_RANGEDRIGHT))
    {
        attType = RANGED_ATTACK;
    }
    else if (slot == EQUIPMENT_SLOT_OFFHAND)
    {
        attType = OFF_ATTACK;
    }

    if (CanUseAttackType(attType))
        _ApplyWeaponDamage(slot, item, apply);
}

void Player::_ApplyWeaponDamage(uint8 slot, Item* item, bool apply)
{
    ItemTemplate const* proto = item->GetTemplate();
    WeaponAttackType attType = BASE_ATTACK;
    float damage = 0.0f;

    if (slot == EQUIPMENT_SLOT_MAINHAND && (proto->GetInventoryType() == INVTYPE_RANGED || proto->GetInventoryType() == INVTYPE_RANGEDRIGHT))
        attType = RANGED_ATTACK;
    else if (slot == EQUIPMENT_SLOT_OFFHAND)
        attType = OFF_ATTACK;

    float minDamage, maxDamage;
    item->GetDamage(this, minDamage, maxDamage);

    if (minDamage > 0)
    {
        damage = apply ? minDamage : BASE_MINDAMAGE;
        SetBaseWeaponDamage(attType, MINDAMAGE, damage);
    }

    if (maxDamage  > 0)
    {
        damage = apply ? maxDamage : BASE_MAXDAMAGE;
        SetBaseWeaponDamage(attType, MAXDAMAGE, damage);
    }

    if (proto->GetDelay() && !IsInFeralForm())
        SetAttackTime(attType, apply ? proto->GetDelay() : BASE_ATTACK_TIME);

    if (CanModifyStats() && (damage || proto->GetDelay()))
        UpdateDamagePhysical(attType);
}

void Player::_ApplyWeaponDependentAuraMods(Item* item, WeaponAttackType attackType, bool apply)
{
    AuraEffectList const& auraCritList = GetAuraEffectsByType(SPELL_AURA_MOD_WEAPON_CRIT_PERCENT);
    for (AuraEffectList::const_iterator itr = auraCritList.begin(); itr != auraCritList.end(); ++itr)
        _ApplyWeaponDependentAuraCritMod(item, attackType, *itr, apply);

    AuraEffectList const& auraDamageFlatList = GetAuraEffectsByType(SPELL_AURA_MOD_DAMAGE_DONE);
    for (AuraEffectList::const_iterator itr = auraDamageFlatList.begin(); itr != auraDamageFlatList.end(); ++itr)
        _ApplyWeaponDependentAuraDamageMod(item, attackType, *itr, apply);

    AuraEffectList const& auraDamagePctList = GetAuraEffectsByType(SPELL_AURA_MOD_DAMAGE_PERCENT_DONE);
    for (AuraEffectList::const_iterator itr = auraDamagePctList.begin(); itr != auraDamagePctList.end(); ++itr)
        _ApplyWeaponDependentAuraDamageMod(item, attackType, *itr, apply);
}

void Player::_ApplyWeaponDependentAuraCritMod(Item* item, WeaponAttackType attackType, AuraEffect const* aura, bool apply)
{
    // don't apply mod if item is broken or cannot be used
    if (item->IsBroken() || !CanUseAttackType(attackType))
        return;

    // generic not weapon specific case processes in aura code
    if (aura->GetSpellInfo()->EquippedItemClass == -1)
        return;

    BaseModGroup mod;
    switch (attackType)
    {
        case BASE_ATTACK:   mod = CRIT_PERCENTAGE;        break;
        case OFF_ATTACK:    mod = OFFHAND_CRIT_PERCENTAGE;break;
        case RANGED_ATTACK: mod = RANGED_CRIT_PERCENTAGE; break;
        default: return;
    }

    if (item->IsFitToSpellRequirements(aura->GetSpellInfo()))
        HandleBaseModValue(mod, FLAT_MOD, float (aura->GetAmount()), apply);
}

void Player::_ApplyWeaponDependentAuraDamageMod(Item* item, WeaponAttackType attackType, AuraEffect const* aura, bool apply)
{
    // don't apply mod if item is broken or cannot be used
    if (item->IsBroken() || !CanUseAttackType(attackType))
        return;

    // ignore spell mods for not wands
    if ((aura->GetMiscValue() & SPELL_SCHOOL_MASK_NORMAL) == 0 && (getClassMask() & CLASSMASK_WAND_USERS) == 0)
        return;

    // generic not weapon specific case processes in aura code
    if (aura->GetSpellInfo()->EquippedItemClass == -1)
        return;

    UnitMods unitMod;
    switch (attackType)
    {
        case BASE_ATTACK:   unitMod = UNIT_MOD_DAMAGE_MAINHAND; break;
        case OFF_ATTACK:    unitMod = UNIT_MOD_DAMAGE_OFFHAND;  break;
        case RANGED_ATTACK: unitMod = UNIT_MOD_DAMAGE_RANGED;   break;
        default: return;
    }

    UnitModifierType unitModType;
    switch (aura->GetAuraType())
    {
        case SPELL_AURA_MOD_DAMAGE_DONE:         unitModType = TOTAL_VALUE; break;
        case SPELL_AURA_MOD_DAMAGE_PERCENT_DONE: unitModType = TOTAL_PCT;   break;
        default: return;
    }

    if (item->IsFitToSpellRequirements(aura->GetSpellInfo()))
    {
        HandleStatModifier(unitMod, unitModType, float(aura->GetAmount()), apply);
        if (unitModType == TOTAL_VALUE)
        {
            if (aura->GetAmount() > 0)
                ApplyModUInt32Value(PLAYER_FIELD_MOD_DAMAGE_DONE_POS, aura->GetAmount(), apply);
            else
                ApplyModUInt32Value(PLAYER_FIELD_MOD_DAMAGE_DONE_NEG, aura->GetAmount(), apply);
        }
    }
}

void Player::ApplyItemEquipSpell(Item* item, bool apply, bool formChange /*= false*/)
{
    if (!item)
        return;

    ItemTemplate const* proto = item->GetTemplate();
    if (!proto)
        return;

    for (uint8 i = 0; i < proto->Effects.size(); ++i)
    {
        ItemEffectEntry const* effectData = proto->Effects[i];

        // wrong triggering type
        if (apply && effectData->Trigger != ITEM_SPELLTRIGGER_ON_EQUIP)
            continue;

        // check if it is valid spell
        SpellInfo const* spellproto = sSpellMgr->GetSpellInfo(effectData->SpellID);
        if (!spellproto)
            continue;

        if (spellproto->HasAura(GetMap()->GetDifficultyID(), SPELL_AURA_MOD_XP_PCT)
            && !GetSession()->GetCollectionMgr()->CanApplyHeirloomXpBonus(item->GetEntry(), getLevel())
            && sDB2Manager.GetHeirloomByItemId(item->GetEntry()))
            continue;

        ApplyEquipSpell(spellproto, item, apply, formChange);
    }
}

void Player::ApplyEquipSpell(SpellInfo const* spellInfo, Item* item, bool apply, bool formChange /*= false*/)
{
    if (apply)
    {
        // Cannot be used in this stance/form
        if (spellInfo->CheckShapeshift(GetShapeshiftForm()) != SPELL_CAST_OK)
            return;

        if (formChange)                                    // check aura active state from other form
        {
            AuraApplicationMapBounds range = GetAppliedAuras().equal_range(spellInfo->Id);
            for (AuraApplicationMap::const_iterator itr = range.first; itr != range.second; ++itr)
                if (!item || itr->second->GetBase()->GetCastItemGUID() == item->GetGUID())
                    return;
        }

        TC_LOG_DEBUG("entities.player", "Player::ApplyEquipSpell: Player '%s' (%s) cast %s equip spell (ID: %i)",
            GetName().c_str(), GetGUID().ToString().c_str(), (item ? "item" : "itemset"), spellInfo->Id);

        CastSpell(this, spellInfo, true, item);
    }
    else
    {
        if (formChange)                                     // check aura compatibility
        {
            // Cannot be used in this stance/form
            if (spellInfo->CheckShapeshift(GetShapeshiftForm()) == SPELL_CAST_OK)
                return;                                     // and remove only not compatible at form change
        }

        if (item)
            RemoveAurasDueToItemSpell(spellInfo->Id, item->GetGUID());  // un-apply all spells, not only at-equipped
        else
            RemoveAurasDueToSpell(spellInfo->Id);           // un-apply spell (item set case)
    }
}

void Player::UpdateEquipSpellsAtFormChange()
{
    for (uint8 i = 0; i < INVENTORY_SLOT_BAG_END; ++i)
    {
        if (m_items[i] && !m_items[i]->IsBroken() && CanUseAttackType(Player::GetAttackBySlot(i, m_items[i]->GetTemplate()->GetInventoryType())))
        {
            ApplyItemEquipSpell(m_items[i], false, true);     // remove spells that not fit to form
            ApplyItemEquipSpell(m_items[i], true, true);      // add spells that fit form but not active
        }
    }

    UpdateItemSetAuras(true);
}

void Player::UpdateItemSetAuras(bool formChange /*= false*/)
{
    // item set bonuses not dependent from item broken state
    for (size_t setindex = 0; setindex < ItemSetEff.size(); ++setindex)
    {
        ItemSetEffect* eff = ItemSetEff[setindex];
        if (!eff)
            continue;

        for (ItemSetSpellEntry const* itemSetSpell : eff->SetBonuses)
        {
            SpellInfo const* spellInfo = sSpellMgr->AssertSpellInfo(itemSetSpell->SpellID);

            if (itemSetSpell->ChrSpecID && itemSetSpell->ChrSpecID != GetUInt32Value(PLAYER_FIELD_CURRENT_SPEC_ID))
                ApplyEquipSpell(spellInfo, nullptr, false, false);  // item set aura is not for current spec
            else
            {
                ApplyEquipSpell(spellInfo, nullptr, false, formChange); // remove spells that not fit to form - removal is skipped if shapeshift condition is satisfied
                ApplyEquipSpell(spellInfo, nullptr, true, formChange);  // add spells that fit form but not active
            }
        }
    }
}

void Player::CastItemCombatSpell(Unit* target, WeaponAttackType attType, uint32 procVictim, uint32 procEx)
{
    if (!target || !target->IsAlive() || target == this)
        return;

    for (uint8 i = EQUIPMENT_SLOT_START; i < EQUIPMENT_SLOT_END; ++i)
    {
        // If usable, try to cast item spell
        if (Item* item = GetItemByPos(INVENTORY_SLOT_BAG_0, i))
            if (!item->IsBroken() && CanUseAttackType(attType))
                if (ItemTemplate const* proto = item->GetTemplate())
                {
                    // Additional check for weapons
                    if (proto->GetClass() == ITEM_CLASS_WEAPON)
                    {
                        // offhand item cannot proc from main hand hit etc
                        EquipmentSlots slot;
                        switch (attType)
                        {
                            case BASE_ATTACK:   slot = EQUIPMENT_SLOT_MAINHAND; break;
                            case OFF_ATTACK:    slot = EQUIPMENT_SLOT_OFFHAND;  break;
                            case RANGED_ATTACK: slot = EQUIPMENT_SLOT_MAINHAND; break;
                            default: slot = EQUIPMENT_SLOT_END; break;
                        }
                        if (slot != i)
                            continue;
                        // Check if item is useable (forms or disarm)
                        if (attType == BASE_ATTACK)
                            if (!IsUseEquipedWeapon(true) && !IsInFeralForm())
                                continue;
                    }
                    CastItemCombatSpell(target, attType, procVictim, procEx, item, proto);
                }
    }
}

void Player::CastItemCombatSpell(Unit* target, WeaponAttackType attType, uint32 procVictim, uint32 procEx, Item* item, ItemTemplate const* proto)
{
    // Can do effect if any damage done to target
    if (procVictim & PROC_FLAG_TAKEN_DAMAGE)
    //if (damageInfo->procVictim & PROC_FLAG_TAKEN_ANY_DAMAGE)
    {
        for (uint8 i = 0; i < proto->Effects.size(); ++i)
        {
            ItemEffectEntry const* effectData = proto->Effects[i];

            // wrong triggering type
            if (effectData->Trigger != ITEM_SPELLTRIGGER_CHANCE_ON_HIT)
                continue;

            SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(effectData->SpellID);
            if (!spellInfo)
            {
                TC_LOG_ERROR("entities.player.items", "Player::CastItemCombatSpell: Player '%s' (%s) cast unknown item spell (ID: %i)",
                    GetName().c_str(), GetGUID().ToString().c_str(), effectData->SpellID);
                continue;
            }

            // not allow proc extra attack spell at extra attack
            if (m_extraAttacks && spellInfo->HasEffect(DIFFICULTY_NONE, SPELL_EFFECT_ADD_EXTRA_ATTACKS))
                return;

            float chance = (float)spellInfo->ProcChance;

            if (proto->SpellPPMRate)
            {
                uint32 WeaponSpeed = GetAttackTime(attType);
                chance = GetPPMProcChance(WeaponSpeed, proto->SpellPPMRate, spellInfo);
            }
            else if (chance > 100.0f)
                chance = GetWeaponProcChance();

            if (roll_chance_f(chance))
                CastSpell(target, spellInfo->Id, true, item);
        }
    }

    // item combat enchantments
    for (uint8 e_slot = 0; e_slot < MAX_ENCHANTMENT_SLOT; ++e_slot)
    {
        uint32 enchant_id = item->GetEnchantmentId(EnchantmentSlot(e_slot));
        SpellItemEnchantmentEntry const* pEnchant = sSpellItemEnchantmentStore.LookupEntry(enchant_id);
        if (!pEnchant)
            continue;

        for (uint8 s = 0; s < MAX_ITEM_ENCHANTMENT_EFFECTS; ++s)
        {
            if (pEnchant->Effect[s] != ITEM_ENCHANTMENT_TYPE_COMBAT_SPELL)
                continue;

            SpellEnchantProcEntry const* entry = sSpellMgr->GetSpellEnchantProcEvent(enchant_id);

            if (entry && entry->procEx)
            {
                // Check hit/crit/dodge/parry requirement
                if ((entry->procEx & procEx) == 0)
                    continue;
            }
            else
            {
                // Can do effect if any damage done to target
                if (!(procVictim & PROC_FLAG_TAKEN_DAMAGE))
                //if (!(damageInfo->procVictim & PROC_FLAG_TAKEN_ANY_DAMAGE))
                    continue;
            }

            SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(pEnchant->EffectSpellID[s]);
            if (!spellInfo)
            {
                TC_LOG_ERROR("entities.player.items", "Player::CastItemCombatSpell: Player '%s' (%s) cast unknown spell (EnchantID: %u, SpellID: %i), ignoring",
                    GetName().c_str(), GetGUID().ToString().c_str(), pEnchant->ID, pEnchant->EffectSpellID[s]);
                continue;
            }

            float chance = pEnchant->EffectPointsMin[s] != 0 ? float(pEnchant->EffectPointsMin[s]) : GetWeaponProcChance();

            if (entry)
            {
                if (entry->PPMChance)
                    chance = GetPPMProcChance(proto->GetDelay(), entry->PPMChance, spellInfo);
                else if (entry->customChance)
                    chance = (float)entry->customChance;
            }

            // Apply spell mods
            ApplySpellMod(pEnchant->EffectSpellID[s], SPELLMOD_CHANCE_OF_SUCCESS, chance);

            // Shiv has 100% chance to apply the poison
            if (FindCurrentSpellBySpellId(5938) && e_slot == TEMP_ENCHANTMENT_SLOT)
                chance = 100.0f;

            if (roll_chance_f(chance))
            {
                if (spellInfo->IsPositive())
                    CastSpell(this, spellInfo, true, item);
                else
                    CastSpell(target, spellInfo, true, item);
            }
        }
    }
}

void Player::CastItemUseSpell(Item* item, SpellCastTargets const& targets, uint8 castCount, int32* misc)
{
    ItemTemplate const* proto = item->GetTemplate();
    // special learning case
    if (proto->Effects.size() >= 2)
    {
        if (proto->Effects[0]->SpellID == 483 || proto->Effects[0]->SpellID == 55884)
        {
            uint32 learn_spell_id = proto->Effects[0]->SpellID;
            uint32 learning_spell_id = proto->Effects[1]->SpellID;

            SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(learn_spell_id);
            if (!spellInfo)
            {
                TC_LOG_ERROR("entities.player", "Player::CastItemUseSpell: Item (Entry: %u) has wrong spell id %u, ignoring", proto->GetId(), learn_spell_id);
                SendEquipError(EQUIP_ERR_INTERNAL_BAG_ERROR, item, nullptr);
                return;
            }

            Spell* spell = new Spell(this, spellInfo, TRIGGERED_NONE);
            spell->m_CastItem = item;
            spell->m_cast_count = castCount; //set count of casts
            spell->SetSpellValue(SPELLVALUE_BASE_POINT0, learning_spell_id);
            spell->prepare(&targets);
            return;
        }
    }

    // item spells cast at use
    for (uint8 i = 0; i < proto->Effects.size(); ++i)
    {
        ItemEffectEntry const* effectData = proto->Effects[i];

        // wrong triggering type
        if (effectData->Trigger != ITEM_SPELLTRIGGER_ON_USE)
            continue;

        SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(effectData->SpellID);
        if (!spellInfo)
        {
            TC_LOG_ERROR("entities.player", "Player::CastItemUseSpell: Item (Entry: %u) has wrong spell id %u, ignoring", proto->GetId(), effectData->SpellID);
            continue;
        }

        Spell* spell = new Spell(this, spellInfo, TRIGGERED_NONE);
        spell->m_CastItem = item;
        spell->m_cast_count = castCount;                   // set count of casts
        spell->m_misc.Raw.Data[0] = misc[0];
        spell->m_misc.Raw.Data[1] = misc[1];
        spell->prepare(&targets);
        return;
    }

    // Item enchantments spells cast at use
    for (uint8 e_slot = 0; e_slot < MAX_ENCHANTMENT_SLOT; ++e_slot)
    {
        uint32 enchant_id = item->GetEnchantmentId(EnchantmentSlot(e_slot));
        SpellItemEnchantmentEntry const* pEnchant = sSpellItemEnchantmentStore.LookupEntry(enchant_id);
        if (!pEnchant)
            continue;
        for (uint8 s = 0; s < MAX_ITEM_ENCHANTMENT_EFFECTS; ++s)
        {
            if (pEnchant->Effect[s] != ITEM_ENCHANTMENT_TYPE_USE_SPELL)
                continue;

            SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(pEnchant->EffectSpellID[s]);
            if (!spellInfo)
            {
                TC_LOG_ERROR("entities.player", "Player::CastItemUseSpell: Enchant %i, cast unknown spell %i", pEnchant->ID, pEnchant->EffectSpellID[s]);
                continue;
            }

            Spell* spell = new Spell(this, spellInfo, TRIGGERED_NONE);
            spell->m_CastItem = item;
            spell->m_cast_count = castCount;                // set count of casts
            spell->m_misc.Raw.Data[0] = misc[0];
            spell->m_misc.Raw.Data[1] = misc[1];
            spell->prepare(&targets);
            return;
        }
    }
}

void Player::_RemoveAllItemMods()
{
    TC_LOG_DEBUG("entities.player.items", "_RemoveAllItemMods start.");

    for (uint8 i = 0; i < INVENTORY_SLOT_BAG_END; ++i)
    {
        if (m_items[i])
        {
            ItemTemplate const* proto = m_items[i]->GetTemplate();
            if (!proto)
                continue;

            // item set bonuses not dependent from item broken state
            if (proto->GetItemSet())
                RemoveItemsSetItem(this, proto);

            if (m_items[i]->IsBroken() || !CanUseAttackType(Player::GetAttackBySlot(i, m_items[i]->GetTemplate()->GetInventoryType())))
                continue;

            ApplyItemEquipSpell(m_items[i], false);
            ApplyEnchantment(m_items[i], false);
        }
    }

    for (uint8 i = 0; i < INVENTORY_SLOT_BAG_END; ++i)
    {
        if (m_items[i])
        {
            if (m_items[i]->IsBroken() || !CanUseAttackType(Player::GetAttackBySlot(i, m_items[i]->GetTemplate()->GetInventoryType())))
                continue;

            uint32 attacktype = Player::GetAttackBySlot(i, m_items[i]->GetTemplate()->GetInventoryType());
            if (attacktype < MAX_ATTACK)
                _ApplyWeaponDependentAuraMods(m_items[i], WeaponAttackType(attacktype), false);

            _ApplyItemBonuses(m_items[i], i, false);
        }
    }

    TC_LOG_DEBUG("entities.player.items", "_RemoveAllItemMods complete.");
}

void Player::_ApplyAllItemMods()
{
    TC_LOG_DEBUG("entities.player.items", "_ApplyAllItemMods start.");

    for (uint8 i = 0; i < INVENTORY_SLOT_BAG_END; ++i)
    {
        if (m_items[i])
        {
            if (m_items[i]->IsBroken() || !CanUseAttackType(Player::GetAttackBySlot(i, m_items[i]->GetTemplate()->GetInventoryType())))
                continue;

            uint32 attacktype = Player::GetAttackBySlot(i, m_items[i]->GetTemplate()->GetInventoryType());
            if (attacktype < MAX_ATTACK)
                _ApplyWeaponDependentAuraMods(m_items[i], WeaponAttackType(attacktype), true);

            _ApplyItemBonuses(m_items[i], i, true);
        }
    }

    for (uint8 i = 0; i < INVENTORY_SLOT_BAG_END; ++i)
    {
        if (m_items[i])
        {
            ItemTemplate const* proto = m_items[i]->GetTemplate();
            if (!proto)
                continue;

            // item set bonuses not dependent from item broken state
            if (proto->GetItemSet())
                AddItemsSetItem(this, m_items[i]);

            if (m_items[i]->IsBroken() || !CanUseAttackType(Player::GetAttackBySlot(i, m_items[i]->GetTemplate()->GetInventoryType())))
                continue;

            ApplyItemEquipSpell(m_items[i], true);
            ApplyEnchantment(m_items[i], true);
        }
    }

    TC_LOG_DEBUG("entities.player.items", "_ApplyAllItemMods complete.");
}

void Player::_ApplyAllLevelScaleItemMods(bool apply)
{
    for (uint8 i = 0; i < INVENTORY_SLOT_BAG_END; ++i)
    {
        if (m_items[i])
        {
            if (m_items[i]->IsBroken() || !CanUseAttackType(Player::GetAttackBySlot(i, m_items[i]->GetTemplate()->GetInventoryType())))
                continue;

            _ApplyItemBonuses(m_items[i], i, apply);
            ApplyItemEquipSpell(m_items[i], apply);
        }
    }
}

/*  If in a battleground a player dies, and an enemy removes the insignia, the player's bones is lootable
    Called by remove insignia spell effect    */
void Player::RemovedInsignia(Player* looterPlr)
{
    if (!GetBattlegroundId())
        return;

    // If not released spirit, do it !
    if (m_deathTimer > 0)
    {
        m_deathTimer = 0;
        BuildPlayerRepop();
        RepopAtGraveyard();
    }

    _corpseLocation.WorldRelocate();

    // We have to convert player corpse to bones, not to be able to resurrect there
    // SpawnCorpseBones isn't handy, 'cos it saves player while he in BG
    Corpse* bones = GetMap()->ConvertCorpseToBones(GetGUID(), true);
    if (!bones)
        return;

    // Now we must make bones lootable, and send player loot
    bones->SetFlag(CORPSE_FIELD_DYNAMIC_FLAGS, CORPSE_DYNFLAG_LOOTABLE);

    // We store the level of our player in the gold field
    // We retrieve this information at Player::SendLoot()
    bones->loot.gold = getLevel();
    bones->lootRecipient = looterPlr;
    looterPlr->SendLoot(bones->GetGUID(), LOOT_INSIGNIA);
}

void Player::SendLootRelease(ObjectGuid guid) const
{
    WorldPackets::Loot::LootReleaseResponse packet;
    packet.LootObj = guid;
    packet.Owner = GetGUID();
    SendDirectMessage(packet.Write());
}

void Player::SendLoot(ObjectGuid guid, LootType loot_type)
{
    ObjectGuid currentLootGuid = GetLootGUID();
    if (!currentLootGuid.IsEmpty())
        m_session->DoLootRelease(currentLootGuid);

    Loot* loot;
    PermissionTypes permission = ALL_PERMISSION;

    TC_LOG_DEBUG("loot", "Player::SendLoot: Player: '%s' (%s), Loot: %s",
        GetName().c_str(), GetGUID().ToString().c_str(), guid.ToString().c_str());
    if (guid.IsGameObject())
    {
        GameObject* go = GetMap()->GetGameObject(guid);

        // not check distance for GO in case owned GO (fishing bobber case, for example)
        // And permit out of range GO with no owner in case fishing hole
        if (!go || (loot_type != LOOT_FISHINGHOLE && ((loot_type != LOOT_FISHING && loot_type != LOOT_FISHING_JUNK) || go->GetOwnerGUID() != GetGUID()) && !go->IsWithinDistInMap(this, INTERACTION_DISTANCE)) || (loot_type == LOOT_CORPSE && go->GetRespawnTime() && go->isSpawnedByDefault()))
        {
            SendLootRelease(guid);
            return;
        }

        loot = &go->loot;

        if (go->getLootState() == GO_READY)
        {
            uint32 lootid = go->GetGOInfo()->GetLootId();
            if (Battleground* bg = GetBattleground())
                if (!bg->CanActivateGO(go->GetEntry(), GetTeam()))
                {
                    SendLootRelease(guid);
                    return;
                }

            if (lootid)
            {
                loot->clear();

                Group* group = GetGroup();
                bool groupRules = (group && go->GetGOInfo()->type == GAMEOBJECT_TYPE_CHEST && go->GetGOInfo()->chest.usegrouplootrules);

                // check current RR player and get next if necessary
                if (groupRules)
                    group->UpdateLooterGuid(go, true);

                loot->FillLoot(lootid, LootTemplates_Gameobject, this, !groupRules, false, go->GetLootMode());

                // get next RR player (for next loot)
                if (groupRules && !go->loot.empty())
                    group->UpdateLooterGuid(go);
            }

            if (loot_type == LOOT_FISHING)
                go->getFishLoot(loot, this);
            else if (loot_type == LOOT_FISHING_JUNK)
                go->getFishLootJunk(loot, this);

            if (go->GetGOInfo()->type == GAMEOBJECT_TYPE_CHEST && go->GetGOInfo()->chest.usegrouplootrules)
            {
                if (Group* group = GetGroup())
                {
                    switch (group->GetLootMethod())
                    {
                        case GROUP_LOOT:
                            // GroupLoot: rolls items over threshold. Items with quality < threshold, round robin
                            group->GroupLoot(loot, go);
                            break;
                        case NEED_BEFORE_GREED:
                            group->NeedBeforeGreed(loot, go);
                            break;
                        case MASTER_LOOT:
                            group->MasterLoot(loot, go);
                            break;
                        default:
                            break;
                    }
                }
            }

            go->SetLootState(GO_ACTIVATED, this);
        }

        if (go->getLootState() == GO_ACTIVATED)
        {
            if (Group* group = GetGroup())
            {
                switch (group->GetLootMethod())
                {
                    case MASTER_LOOT:
                        permission = group->GetMasterLooterGuid() == GetGUID() ? MASTER_PERMISSION : RESTRICTED_PERMISSION;
                        break;
                    case FREE_FOR_ALL:
                        permission = ALL_PERMISSION;
                        break;
                    case ROUND_ROBIN:
                        permission = ROUND_ROBIN_PERMISSION;
                        break;
                    default:
                        permission = GROUP_PERMISSION;
                        break;
                }
            }
            else
                permission = ALL_PERMISSION;
        }
    }
    else if (guid.IsItem())
    {
        Item* item = GetItemByGuid(guid);

        if (!item)
        {
            SendLootRelease(guid);
            return;
        }

        permission = OWNER_PERMISSION;

        loot = &item->loot;

        // If item doesn't already have loot, attempt to load it. If that
        //  fails then this is first time opening, generate loot
        if (!item->m_lootGenerated && !item->ItemContainerLoadLootFromDB())
        {
            item->m_lootGenerated = true;
            loot->clear();

            switch (loot_type)
            {
                case LOOT_DISENCHANTING:
                    loot->FillLoot(item->GetTemplate()->DisenchantID, LootTemplates_Disenchant, this, true);
                    break;
                case LOOT_PROSPECTING:
                    loot->FillLoot(item->GetEntry(), LootTemplates_Prospecting, this, true);
                    break;
                case LOOT_MILLING:
                    loot->FillLoot(item->GetEntry(), LootTemplates_Milling, this, true);
                    break;
                default:
                    loot->generateMoneyLoot(item->GetTemplate()->MinMoneyLoot, item->GetTemplate()->MaxMoneyLoot);
                    loot->FillLoot(item->GetEntry(), LootTemplates_Item, this, true, loot->gold != 0);

                    // Force save the loot and money items that were just rolled
                    //  Also saves the container item ID in Loot struct (not to DB)
                    if (loot->gold > 0 || loot->unlootedCount > 0)
                        item->ItemContainerSaveLootToDB();

                    break;
            }
        }
    }
    else if (guid.IsCorpse())                          // remove insignia
    {
        Corpse* bones = ObjectAccessor::GetCorpse(*this, guid);

        if (!bones || !(loot_type == LOOT_CORPSE || loot_type == LOOT_INSIGNIA) || bones->GetType() != CORPSE_BONES)
        {
            SendLootRelease(guid);
            return;
        }

        loot = &bones->loot;

        if (!bones->lootForBody)
        {
            bones->lootForBody = true;
            uint32 pLevel = bones->loot.gold;
            bones->loot.clear();
            if (Battleground* bg = GetBattleground())
                if (bg->GetTypeID(true) == BATTLEGROUND_AV)
                    loot->FillLoot(1, LootTemplates_Creature, this, true);
            // It may need a better formula
            // Now it works like this: lvl10: ~6copper, lvl70: ~9silver
            bones->loot.gold = uint32(urand(50, 150) * 0.016f * std::pow(float(pLevel) / 5.76f, 2.5f) * sWorld->getRate(RATE_DROP_MONEY));
        }

        if (bones->lootRecipient != this)
            permission = NONE_PERMISSION;
        else
            permission = OWNER_PERMISSION;
    }
    else
    {
        Creature* creature = GetMap()->GetCreature(guid);

        // must be in range and creature must be alive for pickpocket and must be dead for another loot
        if (!creature || creature->IsAlive() != (loot_type == LOOT_PICKPOCKETING) || !creature->IsWithinDistInMap(this, INTERACTION_DISTANCE))
        {
            SendLootRelease(guid);
            return;
        }

        if (loot_type == LOOT_PICKPOCKETING && IsFriendlyTo(creature))
        {
            SendLootRelease(guid);
            return;
        }

        loot = &creature->loot;

        if (loot_type == LOOT_PICKPOCKETING)
        {
            if (loot->loot_type != LOOT_PICKPOCKETING)
            {
                if (creature->CanGeneratePickPocketLoot())
                {
                    creature->StartPickPocketRefillTimer();
                    loot->clear();

                    if (uint32 lootid = creature->GetCreatureTemplate()->pickpocketLootId)
                        loot->FillLoot(lootid, LootTemplates_Pickpocketing, this, true);

                    // Generate extra money for pick pocket loot
                    const uint32 a = urand(0, creature->getLevel() / 2);
                    const uint32 b = urand(0, getLevel() / 2);
                    loot->gold = uint32(10 * (a + b) * sWorld->getRate(RATE_DROP_MONEY));
                    permission = OWNER_PERMISSION;
                }
                else
                {
                    SendLootError(guid, LOOT_ERROR_ALREADY_PICKPOCKETED);
                    return;
                }
            } // else - still has pickpocket loot generated & not fully taken
        }
        else
        {
            // the player whose group may loot the corpse
            Player* recipient = creature->GetLootRecipient();
            if (!recipient)
                return;

            if (loot->loot_type == LOOT_NONE)
            {
                // for creature, loot is filled when creature is killed.
                if (Group* group = recipient->GetGroup())
                {
                    switch (group->GetLootMethod())
                    {
                        case GROUP_LOOT:
                            // GroupLoot: rolls items over threshold. Items with quality < threshold, round robin
                            group->GroupLoot(loot, creature);
                            break;
                        case NEED_BEFORE_GREED:
                            group->NeedBeforeGreed(loot, creature);
                            break;
                        case MASTER_LOOT:
                            group->MasterLoot(loot, creature);
                            break;
                        default:
                            break;
                    }
                }
            }

            // if loot is already skinning loot then don't do anything else
            if (loot->loot_type == LOOT_SKINNING)
            {
                loot_type = LOOT_SKINNING;
                permission = creature->GetSkinner() == GetGUID() ? OWNER_PERMISSION : NONE_PERMISSION;
            }
            else if (loot_type == LOOT_SKINNING)
            {
                loot->clear();
                loot->FillLoot(creature->GetCreatureTemplate()->SkinLootId, LootTemplates_Skinning, this, true);
                creature->SetSkinner(GetGUID());
                permission = OWNER_PERMISSION;
            }
            // set group rights only for loot_type != LOOT_SKINNING
            else
            {
                if (Group* group = GetGroup())
                {
                    if (group == recipient->GetGroup())
                    {
                        switch (group->GetLootMethod())
                        {
                            case MASTER_LOOT:
                                permission = group->GetMasterLooterGuid() == GetGUID() ? MASTER_PERMISSION : RESTRICTED_PERMISSION;
                                break;
                            case FREE_FOR_ALL:
                                permission = ALL_PERMISSION;
                                break;
                            case ROUND_ROBIN:
                                permission = ROUND_ROBIN_PERMISSION;
                                break;
                            default:
                                permission = GROUP_PERMISSION;
                                break;
                        }
                    }
                    else
                        permission = NONE_PERMISSION;
                }
                else if (recipient == this)
                    permission = OWNER_PERMISSION;
                else
                    permission = NONE_PERMISSION;
            }
        }
    }

    // LOOT_INSIGNIA and LOOT_FISHINGHOLE unsupported by client
    switch (loot_type)
    {
        case LOOT_INSIGNIA:    loot_type = LOOT_SKINNING; break;
        case LOOT_FISHINGHOLE: loot_type = LOOT_FISHING; break;
        case LOOT_FISHING_JUNK: loot_type = LOOT_FISHING; break;
        default: break;
    }

    // need know merged fishing/corpse loot type for achievements
    loot->loot_type = loot_type;

    if (permission != NONE_PERMISSION)
    {
        LootMethod _lootMethod = FREE_FOR_ALL;
        if (Group* group = GetGroup())
        {
            if (Creature* creature = GetMap()->GetCreature(guid))
            {
                if (Player* recipient = creature->GetLootRecipient())
                {
                    if (group == recipient->GetGroup())
                        _lootMethod = group->GetLootMethod();
                }
            }
        }

        SetLootGUID(guid);

        WorldPackets::Loot::LootResponse packet;
        packet.LootObj = guid;
        packet.Owner = loot->GetGUID();
        packet.LootMethod = _lootMethod;
        packet.AcquireReason = loot_type;
        packet.Acquired = true; // false == No Loot (this too^^)
        loot->BuildLootResponse(packet, this, permission);
        SendDirectMessage(packet.Write());

        // add 'this' player as one of the players that are looting 'loot'
        loot->AddLooter(GetGUID());
    }
    else
        SendLootError(GetLootGUID(), LOOT_ERROR_DIDNT_KILL);

    if (loot_type == LOOT_CORPSE && !guid.IsItem())
        SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_LOOTING);
}

void Player::SendLootError(ObjectGuid guid, LootError error) const
{
    WorldPacket data(SMSG_LOOT_RESPONSE, 10);
    data << guid;
    data << uint8(LOOT_NONE);
    data << uint8(error);
    SendDirectMessage(&data);
}

void Player::SendNotifyLootMoneyRemoved(ObjectGuid lootObj) const
{
    WorldPackets::Loot::CoinRemoved packet;
    packet.LootObj = lootObj;
    SendDirectMessage(packet.Write());
}

void Player::SendNotifyLootItemRemoved(ObjectGuid owner, ObjectGuid lootObj, uint8 lootSlot) const
{
    WorldPackets::Loot::LootRemoved packet;
    packet.Owner = owner;
    packet.LootObj = lootObj;
    // Since 6.x client expects loot to be starting from 1 hence the +1
    packet.LootListID = lootSlot+1;
    GetSession()->SendPacket(packet.Write());
}

void Player::SendUpdateWorldState(uint32 variable, uint32 value, bool hidden /*= false*/) const
{
    WorldPackets::WorldState::UpdateWorldState worldstate;
    worldstate.VariableID = variable;
    worldstate.Value = value;
    worldstate.Hidden = hidden;
    SendDirectMessage(worldstate.Write());
}

void Player::SendInitWorldStates(uint32 zoneid, uint32 areaid)
{
    // data depends on zoneid/mapid...
    Battleground* bg = GetBattleground();
    uint32 mapid = GetMapId();
    OutdoorPvP* pvp = sOutdoorPvPMgr->GetOutdoorPvPToZoneId(zoneid);
    InstanceScript* instance = GetInstanceScript();
    Battlefield* bf = sBattlefieldMgr->GetBattlefieldToZoneId(zoneid);

    WorldPackets::WorldState::InitWorldStates packet;
    packet.MapID = mapid;
    packet.AreaID = zoneid;
    packet.SubareaID = areaid;
    packet.Worldstates.emplace_back(2264, 0);              // 1
    packet.Worldstates.emplace_back(2263, 0);              // 2
    packet.Worldstates.emplace_back(2262, 0);              // 3
    packet.Worldstates.emplace_back(2261, 0);              // 4
    packet.Worldstates.emplace_back(2260, 0);              // 5
    packet.Worldstates.emplace_back(2259, 0);              // 6

    packet.Worldstates.emplace_back(3191, int32(sWorld->getBoolConfig(CONFIG_ARENA_SEASON_IN_PROGRESS) ? sWorld->getIntConfig(CONFIG_ARENA_SEASON_ID) : 0)); // 7 Current Season - Arena season in progress
                                                                                                                                                              // 0 - End of season
    packet.Worldstates.emplace_back(3901, int32(sWorld->getIntConfig(CONFIG_ARENA_SEASON_ID) - sWorld->getBoolConfig(CONFIG_ARENA_SEASON_IN_PROGRESS)));     // 8 PreviousSeason

    if (mapid == 530)                                       // Outland
    {
        packet.Worldstates.emplace_back(2495, 0);          // 7
        packet.Worldstates.emplace_back(2493, 0xF);        // 8
        packet.Worldstates.emplace_back(2491, 0xF);        // 9
    }

    // insert <field> <value>
    switch (zoneid)
    {
        case 1:                                             // Dun Morogh
        case 11:                                            // Wetlands
        case 12:                                            // Elwynn Forest
        case 38:                                            // Loch Modan
        case 40:                                            // Westfall
        case 51:                                            // Searing Gorge
        case 1519:                                          // Stormwind City
        case 1537:                                          // Ironforge
        case 2257:                                          // Deeprun Tram
        case 3703:                                          // Shattrath City});
            break;
        case 1377:                                          // Silithus
            if (pvp && pvp->GetTypeId() == OUTDOOR_PVP_SI)
                pvp->FillInitialWorldStates(packet);
            else
            {
                // states are always shown
                packet.Worldstates.emplace_back(2313, 0x0); // 7 ally silityst gathered
                packet.Worldstates.emplace_back(2314, 0x0); // 8 horde silityst gathered
                packet.Worldstates.emplace_back(2317, 0x0); // 9 max silithyst
            }
            // dunno about these... aq opening event maybe?
            packet.Worldstates.emplace_back(2322, 0x0); // 10 sandworm N
            packet.Worldstates.emplace_back(2323, 0x0); // 11 sandworm S
            packet.Worldstates.emplace_back(2324, 0x0); // 12 sandworm SW
            packet.Worldstates.emplace_back(2325, 0x0); // 13 sandworm E
            break;
        case 2597:                                          // Alterac Valley
            if (bg && bg->GetTypeID(true) == BATTLEGROUND_AV)
                bg->FillInitialWorldStates(packet);
            else
            {
                packet.Worldstates.emplace_back(0x7ae, 0x1);           // 7 snowfall n
                packet.Worldstates.emplace_back(0x532, 0x1);           // 8 frostwolfhut hc
                packet.Worldstates.emplace_back(0x531, 0x0);           // 9 frostwolfhut ac
                packet.Worldstates.emplace_back(0x52e, 0x0);           // 10 stormpike firstaid a_a
                packet.Worldstates.emplace_back(0x571, 0x0);           // 11 east frostwolf tower horde assaulted -unused
                packet.Worldstates.emplace_back(0x570, 0x0);           // 12 west frostwolf tower horde assaulted - unused
                packet.Worldstates.emplace_back(0x567, 0x1);           // 13 frostwolfe c
                packet.Worldstates.emplace_back(0x566, 0x1);           // 14 frostwolfw c
                packet.Worldstates.emplace_back(0x550, 0x1);           // 15 irondeep (N) ally
                packet.Worldstates.emplace_back(0x544, 0x0);           // 16 ice grave a_a
                packet.Worldstates.emplace_back(0x536, 0x0);           // 17 stormpike grave h_c
                packet.Worldstates.emplace_back(0x535, 0x1);           // 18 stormpike grave a_c
                packet.Worldstates.emplace_back(0x518, 0x0);           // 19 stoneheart grave a_a
                packet.Worldstates.emplace_back(0x517, 0x0);           // 20 stoneheart grave h_a
                packet.Worldstates.emplace_back(0x574, 0x0);           // 21 1396 unk
                packet.Worldstates.emplace_back(0x573, 0x0);           // 22 iceblood tower horde assaulted -unused
                packet.Worldstates.emplace_back(0x572, 0x0);           // 23 towerpoint horde assaulted - unused
                packet.Worldstates.emplace_back(0x56f, 0x0);           // 24 1391 unk
                packet.Worldstates.emplace_back(0x56e, 0x0);           // 25 iceblood a
                packet.Worldstates.emplace_back(0x56d, 0x0);           // 26 towerp a
                packet.Worldstates.emplace_back(0x56c, 0x0);           // 27 frostwolfe a
                packet.Worldstates.emplace_back(0x56b, 0x0);           // 28 froswolfw a
                packet.Worldstates.emplace_back(0x56a, 0x1);           // 29 1386 unk
                packet.Worldstates.emplace_back(0x569, 0x1);           // 30 iceblood c
                packet.Worldstates.emplace_back(0x568, 0x1);           // 31 towerp c
                packet.Worldstates.emplace_back(0x565, 0x0);           // 32 stoneh tower a
                packet.Worldstates.emplace_back(0x564, 0x0);           // 33 icewing tower a
                packet.Worldstates.emplace_back(0x563, 0x0);           // 34 dunn a
                packet.Worldstates.emplace_back(0x562, 0x0);           // 35 duns a
                packet.Worldstates.emplace_back(0x561, 0x0);           // 36 stoneheart bunker alliance assaulted - unused
                packet.Worldstates.emplace_back(0x560, 0x0);           // 37 icewing bunker alliance assaulted - unused
                packet.Worldstates.emplace_back(0x55f, 0x0);           // 38 dunbaldar south alliance assaulted - unused
                packet.Worldstates.emplace_back(0x55e, 0x0);           // 39 dunbaldar north alliance assaulted - unused
                packet.Worldstates.emplace_back(0x55d, 0x0);           // 40 stone tower d
                packet.Worldstates.emplace_back(0x3c6, 0x0);           // 41 966 unk
                packet.Worldstates.emplace_back(0x3c4, 0x0);           // 42 964 unk
                packet.Worldstates.emplace_back(0x3c2, 0x0);           // 43 962 unk
                packet.Worldstates.emplace_back(0x516, 0x1);           // 44 stoneheart grave a_c
                packet.Worldstates.emplace_back(0x515, 0x0);           // 45 stonheart grave h_c
                packet.Worldstates.emplace_back(0x3b6, 0x0);           // 46 950 unk
                packet.Worldstates.emplace_back(0x55c, 0x0);           // 47 icewing tower d
                packet.Worldstates.emplace_back(0x55b, 0x0);           // 48 dunn d
                packet.Worldstates.emplace_back(0x55a, 0x0);           // 49 duns d
                packet.Worldstates.emplace_back(0x559, 0x0);           // 50 1369 unk
                packet.Worldstates.emplace_back(0x558, 0x0);           // 51 iceblood d
                packet.Worldstates.emplace_back(0x557, 0x0);           // 52 towerp d
                packet.Worldstates.emplace_back(0x556, 0x0);           // 53 frostwolfe d
                packet.Worldstates.emplace_back(0x555, 0x0);           // 54 frostwolfw d
                packet.Worldstates.emplace_back(0x554, 0x1);           // 55 stoneh tower c
                packet.Worldstates.emplace_back(0x553, 0x1);           // 56 icewing tower c
                packet.Worldstates.emplace_back(0x552, 0x1);           // 57 dunn c
                packet.Worldstates.emplace_back(0x551, 0x1);           // 58 duns c
                packet.Worldstates.emplace_back(0x54f, 0x0);           // 59 irondeep (N) horde
                packet.Worldstates.emplace_back(0x54e, 0x0);           // 60 irondeep (N) ally
                packet.Worldstates.emplace_back(0x54d, 0x1);           // 61 mine (S) neutral
                packet.Worldstates.emplace_back(0x54c, 0x0);           // 62 mine (S) horde
                packet.Worldstates.emplace_back(0x54b, 0x0);           // 63 mine (S) ally
                packet.Worldstates.emplace_back(0x545, 0x0);           // 64 iceblood h_a
                packet.Worldstates.emplace_back(0x543, 0x1);           // 65 iceblod h_c
                packet.Worldstates.emplace_back(0x542, 0x0);           // 66 iceblood a_c
                packet.Worldstates.emplace_back(0x540, 0x0);           // 67 snowfall h_a
                packet.Worldstates.emplace_back(0x53f, 0x0);           // 68 snowfall a_a
                packet.Worldstates.emplace_back(0x53e, 0x0);           // 69 snowfall h_c
                packet.Worldstates.emplace_back(0x53d, 0x0);           // 70 snowfall a_c
                packet.Worldstates.emplace_back(0x53c, 0x0);           // 71 frostwolf g h_a
                packet.Worldstates.emplace_back(0x53b, 0x0);           // 72 frostwolf g a_a
                packet.Worldstates.emplace_back(0x53a, 0x1);           // 73 frostwolf g h_c
                packet.Worldstates.emplace_back(0x539, 0x0);           // 74 frostwolf g a_c
                packet.Worldstates.emplace_back(0x538, 0x0);           // 75 stormpike grave h_a
                packet.Worldstates.emplace_back(0x537, 0x0);           // 76 stormpike grave a_a
                packet.Worldstates.emplace_back(0x534, 0x0);           // 77 frostwolf hut h_a
                packet.Worldstates.emplace_back(0x533, 0x0);           // 78 frostwolf hut a_a
                packet.Worldstates.emplace_back(0x530, 0x0);           // 79 stormpike first aid h_a
                packet.Worldstates.emplace_back(0x52f, 0x0);           // 80 stormpike first aid h_c
                packet.Worldstates.emplace_back(0x52d, 0x1);           // 81 stormpike first aid a_c
            }
            break;
        case 3277:                                          // Warsong Gulch
            if (bg && bg->GetTypeID(true) == BATTLEGROUND_WS)
                bg->FillInitialWorldStates(packet);
            else
            {
                packet.Worldstates.emplace_back(0x62d, 0x0);       // 7 1581 alliance flag captures
                packet.Worldstates.emplace_back(0x62e, 0x0);       // 8 1582 horde flag captures
                packet.Worldstates.emplace_back(0x609, 0x0);       // 9 1545 unk, set to 1 on alliance flag pickup...
                packet.Worldstates.emplace_back(0x60a, 0x0);       // 10 1546 unk, set to 1 on horde flag pickup, after drop it's -1
                packet.Worldstates.emplace_back(0x60b, 0x2);       // 11 1547 unk
                packet.Worldstates.emplace_back(0x641, 0x3);       // 12 1601 unk (max flag captures?)
                packet.Worldstates.emplace_back(0x922, 0x1);       // 13 2338 horde (0 - hide, 1 - flag ok, 2 - flag picked up (flashing), 3 - flag picked up (not flashing)
                packet.Worldstates.emplace_back(0x923, 0x1);       // 14 2339 alliance (0 - hide, 1 - flag ok, 2 - flag picked up (flashing), 3 - flag picked up (not flashing)
            }
            break;
        case 3358:                                          // Arathi Basin
            if (bg && bg->GetTypeID(true) == BATTLEGROUND_AB)
                bg->FillInitialWorldStates(packet);
            else
            {
                packet.Worldstates.emplace_back(0x6e7, 0x0);       // 7 1767 stables alliance
                packet.Worldstates.emplace_back(0x6e8, 0x0);       // 8 1768 stables horde
                packet.Worldstates.emplace_back(0x6e9, 0x0);       // 9 1769 unk, ST?
                packet.Worldstates.emplace_back(0x6ea, 0x0);       // 10 1770 stables (show/hide)
                packet.Worldstates.emplace_back(0x6ec, 0x0);       // 11 1772 farm (0 - horde controlled, 1 - alliance controlled)
                packet.Worldstates.emplace_back(0x6ed, 0x0);       // 12 1773 farm (show/hide)
                packet.Worldstates.emplace_back(0x6ee, 0x0);       // 13 1774 farm color
                packet.Worldstates.emplace_back(0x6ef, 0x0);       // 14 1775 gold mine color, may be FM?
                packet.Worldstates.emplace_back(0x6f0, 0x0);       // 15 1776 alliance resources
                packet.Worldstates.emplace_back(0x6f1, 0x0);       // 16 1777 horde resources
                packet.Worldstates.emplace_back(0x6f2, 0x0);       // 17 1778 horde bases
                packet.Worldstates.emplace_back(0x6f3, 0x0);       // 18 1779 alliance bases
                packet.Worldstates.emplace_back(0x6f4, 0x7d0);     // 19 1780 max resources (2000)
                packet.Worldstates.emplace_back(0x6f6, 0x0);       // 20 1782 blacksmith color
                packet.Worldstates.emplace_back(0x6f7, 0x0);       // 21 1783 blacksmith (show/hide)
                packet.Worldstates.emplace_back(0x6f8, 0x0);       // 22 1784 unk, bs?
                packet.Worldstates.emplace_back(0x6f9, 0x0);       // 23 1785 unk, bs?
                packet.Worldstates.emplace_back(0x6fb, 0x0);       // 24 1787 gold mine (0 - horde contr, 1 - alliance contr)
                packet.Worldstates.emplace_back(0x6fc, 0x0);       // 25 1788 gold mine (0 - conflict, 1 - horde)
                packet.Worldstates.emplace_back(0x6fd, 0x0);       // 26 1789 gold mine (1 - show/0 - hide)
                packet.Worldstates.emplace_back(0x6fe, 0x0);       // 27 1790 gold mine color
                packet.Worldstates.emplace_back(0x700, 0x0);       // 28 1792 gold mine color, wtf?, may be LM?
                packet.Worldstates.emplace_back(0x701, 0x0);       // 29 1793 lumber mill color (0 - conflict, 1 - horde contr)
                packet.Worldstates.emplace_back(0x702, 0x0);       // 30 1794 lumber mill (show/hide)
                packet.Worldstates.emplace_back(0x703, 0x0);       // 31 1795 lumber mill color color
                packet.Worldstates.emplace_back(0x732, 0x1);       // 32 1842 stables (1 - uncontrolled)
                packet.Worldstates.emplace_back(0x733, 0x1);       // 33 1843 gold mine (1 - uncontrolled)
                packet.Worldstates.emplace_back(0x734, 0x1);       // 34 1844 lumber mill (1 - uncontrolled)
                packet.Worldstates.emplace_back(0x735, 0x1);       // 35 1845 farm (1 - uncontrolled)
                packet.Worldstates.emplace_back(0x736, 0x1);       // 36 1846 blacksmith (1 - uncontrolled)
                packet.Worldstates.emplace_back(0x745, 0x2);       // 37 1861 unk
                packet.Worldstates.emplace_back(0x7a3, 0x708);     // 38 1955 warning limit (1800)
            }
            break;
        case 3820:                                          // Eye of the Storm
            if (bg && bg->GetTypeID(true) == BATTLEGROUND_EY)
                bg->FillInitialWorldStates(packet);
            else
            {
                packet.Worldstates.emplace_back(0xac1, 0x0);       // 7  2753 Horde Bases
                packet.Worldstates.emplace_back(0xac0, 0x0);       // 8  2752 Alliance Bases
                packet.Worldstates.emplace_back(0xab6, 0x0);       // 9  2742 Mage Tower - Horde conflict
                packet.Worldstates.emplace_back(0xab5, 0x0);       // 10 2741 Mage Tower - Alliance conflict
                packet.Worldstates.emplace_back(0xab4, 0x0);       // 11 2740 Fel Reaver - Horde conflict
                packet.Worldstates.emplace_back(0xab3, 0x0);       // 12 2739 Fel Reaver - Alliance conflict
                packet.Worldstates.emplace_back(0xab2, 0x0);       // 13 2738 Draenei - Alliance conflict
                packet.Worldstates.emplace_back(0xab1, 0x0);       // 14 2737 Draenei - Horde conflict
                packet.Worldstates.emplace_back(0xab0, 0x0);       // 15 2736 unk // 0 at start
                packet.Worldstates.emplace_back(0xaaf, 0x0);       // 16 2735 unk // 0 at start
                packet.Worldstates.emplace_back(0xaad, 0x0);       // 17 2733 Draenei - Horde control
                packet.Worldstates.emplace_back(0xaac, 0x0);       // 18 2732 Draenei - Alliance control
                packet.Worldstates.emplace_back(0xaab, 0x1);       // 19 2731 Draenei uncontrolled (1 - yes, 0 - no)
                packet.Worldstates.emplace_back(0xaaa, 0x0);       // 20 2730 Mage Tower - Alliance control
                packet.Worldstates.emplace_back(0xaa9, 0x0);       // 21 2729 Mage Tower - Horde control
                packet.Worldstates.emplace_back(0xaa8, 0x1);       // 22 2728 Mage Tower uncontrolled (1 - yes, 0 - no)
                packet.Worldstates.emplace_back(0xaa7, 0x0);       // 23 2727 Fel Reaver - Horde control
                packet.Worldstates.emplace_back(0xaa6, 0x0);       // 24 2726 Fel Reaver - Alliance control
                packet.Worldstates.emplace_back(0xaa5, 0x1);       // 25 2725 Fel Reaver uncontrolled (1 - yes, 0 - no)
                packet.Worldstates.emplace_back(0xaa4, 0x0);       // 26 2724 Boold Elf - Horde control
                packet.Worldstates.emplace_back(0xaa3, 0x0);       // 27 2723 Boold Elf - Alliance control
                packet.Worldstates.emplace_back(0xaa2, 0x1);       // 28 2722 Boold Elf uncontrolled (1 - yes, 0 - no)
                packet.Worldstates.emplace_back(0xac5, 0x1);       // 29 2757 Flag (1 - show, 0 - hide) - doesn't work exactly this way!
                packet.Worldstates.emplace_back(0xad2, 0x1);       // 30 2770 Horde top-stats (1 - show, 0 - hide) // 02 -> horde picked up the flag
                packet.Worldstates.emplace_back(0xad1, 0x1);       // 31 2769 Alliance top-stats (1 - show, 0 - hide) // 02 -> alliance picked up the flag
                packet.Worldstates.emplace_back(0xabe, 0x0);       // 32 2750 Horde resources
                packet.Worldstates.emplace_back(0xabd, 0x0);       // 33 2749 Alliance resources
                packet.Worldstates.emplace_back(0xa05, 0x8e);      // 34 2565 unk, constant?
                packet.Worldstates.emplace_back(0xaa0, 0x0);       // 35 2720 Capturing progress-bar (100 -> empty (only grey), 0 -> blue|red (no grey), default 0)
                packet.Worldstates.emplace_back(0xa9f, 0x0);       // 36 2719 Capturing progress-bar (0 - left, 100 - right)
                packet.Worldstates.emplace_back(0xa9e, 0x0);       // 37 2718 Capturing progress-bar (1 - show, 0 - hide)
                packet.Worldstates.emplace_back(0xc0d, 0x17b);     // 38 3085 unk
                // and some more ... unknown
            }
            break;
        // any of these needs change! the client remembers the prev setting!
        // ON EVERY ZONE LEAVE, RESET THE OLD ZONE'S WORLD STATE, BUT AT LEAST THE UI STUFF!
        case 3483:                                          // Hellfire Peninsula
            if (pvp && pvp->GetTypeId() == OUTDOOR_PVP_HP)
                pvp->FillInitialWorldStates(packet);
            else
            {
                packet.Worldstates.emplace_back(0x9ba, 0x1);           // 10 // add ally tower main gui icon       // maybe should be sent only on login?
                packet.Worldstates.emplace_back(0x9b9, 0x1);           // 11 // add horde tower main gui icon      // maybe should be sent only on login?
                packet.Worldstates.emplace_back(0x9b5, 0x0);           // 12 // show neutral broken hill icon      // 2485
                packet.Worldstates.emplace_back(0x9b4, 0x1);           // 13 // show icon above broken hill        // 2484
                packet.Worldstates.emplace_back(0x9b3, 0x0);           // 14 // show ally broken hill icon         // 2483
                packet.Worldstates.emplace_back(0x9b2, 0x0);           // 15 // show neutral overlook icon         // 2482
                packet.Worldstates.emplace_back(0x9b1, 0x1);           // 16 // show the overlook arrow            // 2481
                packet.Worldstates.emplace_back(0x9b0, 0x0);           // 17 // show ally overlook icon            // 2480
                packet.Worldstates.emplace_back(0x9ae, 0x0);           // 18 // horde pvp objectives captured      // 2478
                packet.Worldstates.emplace_back(0x9ac, 0x0);           // 19 // ally pvp objectives captured       // 2476
                packet.Worldstates.emplace_back(2475, 100);            //: ally / horde slider grey area                              // show only in direct vicinity!
                packet.Worldstates.emplace_back(2474, 50);             //: ally / horde slider percentage, 100 for ally, 0 for horde  // show only in direct vicinity!
                packet.Worldstates.emplace_back(2473, 0);              //: ally / horde slider display                                // show only in direct vicinity!
                packet.Worldstates.emplace_back(0x9a8, 0x0);           // 20 // show the neutral stadium icon      // 2472
                packet.Worldstates.emplace_back(0x9a7, 0x0);           // 21 // show the ally stadium icon         // 2471
                packet.Worldstates.emplace_back(0x9a6, 0x1);           // 22 // show the horde stadium icon        // 2470
            }
            break;
        case 3518:                                          // Nagrand
            if (pvp && pvp->GetTypeId() == OUTDOOR_PVP_NA)
                pvp->FillInitialWorldStates(packet);
            else
            {
                packet.Worldstates.emplace_back(2503, 0x0);    // 10
                packet.Worldstates.emplace_back(2502, 0x0);    // 11
                packet.Worldstates.emplace_back(2493, 0x0);    // 12
                packet.Worldstates.emplace_back(2491, 0x0);    // 13

                packet.Worldstates.emplace_back(2495, 0x0);    // 14
                packet.Worldstates.emplace_back(2494, 0x0);    // 15
                packet.Worldstates.emplace_back(2497, 0x0);    // 16

                packet.Worldstates.emplace_back(2762, 0x0);    // 17
                packet.Worldstates.emplace_back(2662, 0x0);    // 18
                packet.Worldstates.emplace_back(2663, 0x0);    // 19
                packet.Worldstates.emplace_back(2664, 0x0);    // 20

                packet.Worldstates.emplace_back(2760, 0x0);    // 21
                packet.Worldstates.emplace_back(2670, 0x0);    // 22
                packet.Worldstates.emplace_back(2668, 0x0);    // 23
                packet.Worldstates.emplace_back(2669, 0x0);    // 24

                packet.Worldstates.emplace_back(2761, 0x0);    // 25
                packet.Worldstates.emplace_back(2667, 0x0);    // 26
                packet.Worldstates.emplace_back(2665, 0x0);    // 27
                packet.Worldstates.emplace_back(2666, 0x0);    // 28

                packet.Worldstates.emplace_back(2763, 0x0);    // 29
                packet.Worldstates.emplace_back(2659, 0x0);    // 30
                packet.Worldstates.emplace_back(2660, 0x0);    // 31
                packet.Worldstates.emplace_back(2661, 0x0);    // 32

                packet.Worldstates.emplace_back(2671, 0x0);    // 33
                packet.Worldstates.emplace_back(2676, 0x0);    // 34
                packet.Worldstates.emplace_back(2677, 0x0);    // 35
                packet.Worldstates.emplace_back(2672, 0x0);    // 36
                packet.Worldstates.emplace_back(2673, 0x0);    // 37
            }
            break;
        case 3519:                                          // Terokkar Forest
            if (pvp && pvp->GetTypeId() == OUTDOOR_PVP_TF)
                pvp->FillInitialWorldStates(packet);
            else
            {
                packet.Worldstates.emplace_back(0xa41, 0x0);           // 10 // 2625 capture bar pos
                packet.Worldstates.emplace_back(0xa40, 0x14);          // 11 // 2624 capture bar neutral
                packet.Worldstates.emplace_back(0xa3f, 0x0);           // 12 // 2623 show capture bar
                packet.Worldstates.emplace_back(0xa3e, 0x0);           // 13 // 2622 horde towers controlled
                packet.Worldstates.emplace_back(0xa3d, 0x5);           // 14 // 2621 ally towers controlled
                packet.Worldstates.emplace_back(0xa3c, 0x0);           // 15 // 2620 show towers controlled
                packet.Worldstates.emplace_back(0xa88, 0x0);           // 16 // 2696 SE Neu
                packet.Worldstates.emplace_back(0xa87, 0x0);           // 17 // SE Horde
                packet.Worldstates.emplace_back(0xa86, 0x0);           // 18 // SE Ally
                packet.Worldstates.emplace_back(0xa85, 0x0);           // 19 //S Neu
                packet.Worldstates.emplace_back(0xa84, 0x0);           // 20 S Horde
                packet.Worldstates.emplace_back(0xa83, 0x0);           // 21 S Ally
                packet.Worldstates.emplace_back(0xa82, 0x0);           // 22 NE Neu
                packet.Worldstates.emplace_back(0xa81, 0x0);           // 23 NE Horde
                packet.Worldstates.emplace_back(0xa80, 0x0);           // 24 NE Ally
                packet.Worldstates.emplace_back(0xa7e, 0x0);           // 25 // 2686 N Neu
                packet.Worldstates.emplace_back(0xa7d, 0x0);           // 26 N Horde
                packet.Worldstates.emplace_back(0xa7c, 0x0);           // 27 N Ally
                packet.Worldstates.emplace_back(0xa7b, 0x0);           // 28 NW Ally
                packet.Worldstates.emplace_back(0xa7a, 0x0);           // 29 NW Horde
                packet.Worldstates.emplace_back(0xa79, 0x0);           // 30 NW Neutral
                packet.Worldstates.emplace_back(0x9d0, 0x5);           // 31 // 2512 locked time remaining seconds first digit
                packet.Worldstates.emplace_back(0x9ce, 0x0);           // 32 // 2510 locked time remaining seconds second digit
                packet.Worldstates.emplace_back(0x9cd, 0x0);           // 33 // 2509 locked time remaining minutes
                packet.Worldstates.emplace_back(0x9cc, 0x0);           // 34 // 2508 neutral locked time show
                packet.Worldstates.emplace_back(0xad0, 0x0);           // 35 // 2768 horde locked time show
                packet.Worldstates.emplace_back(0xacf, 0x1);           // 36 // 2767 ally locked time show
            }
            break;
        case 3521:                                          // Zangarmarsh
            if (pvp && pvp->GetTypeId() == OUTDOOR_PVP_ZM)
                pvp->FillInitialWorldStates(packet);
            else
            {
                packet.Worldstates.emplace_back(0x9e1, 0x0);           // 10 //2529
                packet.Worldstates.emplace_back(0x9e0, 0x0);           // 11
                packet.Worldstates.emplace_back(0x9df, 0x0);           // 12
                packet.Worldstates.emplace_back(0xa5d, 0x1);           // 13 //2653
                packet.Worldstates.emplace_back(0xa5c, 0x0);           // 14 //2652 east beacon neutral
                packet.Worldstates.emplace_back(0xa5b, 0x1);           // 15 horde
                packet.Worldstates.emplace_back(0xa5a, 0x0);           // 16 ally
                packet.Worldstates.emplace_back(0xa59, 0x1);           // 17 // 2649 Twin spire graveyard horde  12???
                packet.Worldstates.emplace_back(0xa58, 0x0);           // 18 ally     14 ???
                packet.Worldstates.emplace_back(0xa57, 0x0);           // 19 neutral  7???
                packet.Worldstates.emplace_back(0xa56, 0x0);           // 20 // 2646 west beacon neutral
                packet.Worldstates.emplace_back(0xa55, 0x1);           // 21 horde
                packet.Worldstates.emplace_back(0xa54, 0x0);           // 22 ally
                packet.Worldstates.emplace_back(0x9e7, 0x0);           // 23 // 2535
                packet.Worldstates.emplace_back(0x9e6, 0x0);           // 24
                packet.Worldstates.emplace_back(0x9e5, 0x0);           // 25
                packet.Worldstates.emplace_back(0xa00, 0x0);           // 26 // 2560
                packet.Worldstates.emplace_back(0x9ff, 0x1);           // 27
                packet.Worldstates.emplace_back(0x9fe, 0x0);           // 28
                packet.Worldstates.emplace_back(0x9fd, 0x0);           // 29
                packet.Worldstates.emplace_back(0x9fc, 0x1);           // 30
                packet.Worldstates.emplace_back(0x9fb, 0x0);           // 31
                packet.Worldstates.emplace_back(0xa62, 0x0);           // 32 // 2658
                packet.Worldstates.emplace_back(0xa61, 0x1);           // 33
                packet.Worldstates.emplace_back(0xa60, 0x1);           // 34
                packet.Worldstates.emplace_back(0xa5f, 0x0);           // 35
            }
            break;
        case 3698:                                          // Nagrand Arena
            if (bg && bg->GetTypeID(true) == BATTLEGROUND_NA)
                bg->FillInitialWorldStates(packet);
            else
            {
                packet.Worldstates.emplace_back(0xa0f, 0x0);           // 7
                packet.Worldstates.emplace_back(0xa10, 0x0);           // 8
                packet.Worldstates.emplace_back(0xa11, 0x0);           // 9 show
            }
            break;
        case 3702:                                          // Blade's Edge Arena
            if (bg && bg->GetTypeID(true) == BATTLEGROUND_BE)
                bg->FillInitialWorldStates(packet);
            else
            {
                packet.Worldstates.emplace_back(0x9f0, 0x0);           // 7 gold
                packet.Worldstates.emplace_back(0x9f1, 0x0);           // 8 green
                packet.Worldstates.emplace_back(0x9f3, 0x0);           // 9 show
            }
            break;
        case 3968:                                          // Ruins of Lordaeron
            if (bg && bg->GetTypeID(true) == BATTLEGROUND_RL)
                bg->FillInitialWorldStates(packet);
            else
            {
                packet.Worldstates.emplace_back(0xbb8, 0x0);           // 7 gold
                packet.Worldstates.emplace_back(0xbb9, 0x0);           // 8 green
                packet.Worldstates.emplace_back(0xbba, 0x0);           // 9 show
            }
            break;
        case 4378:                                          // Dalaran Sewers
            if (bg && bg->GetTypeID(true) == BATTLEGROUND_DS)
                bg->FillInitialWorldStates(packet);
            else
            {
                packet.Worldstates.emplace_back(3601, 0x0);           // 7 gold
                packet.Worldstates.emplace_back(3600, 0x0);           // 8 green
                packet.Worldstates.emplace_back(3610, 0x0);           // 9 show
            }
            break;
        case 4384:                                          // Strand of the Ancients
            if (bg && bg->GetTypeID(true) == BATTLEGROUND_SA)
                bg->FillInitialWorldStates(packet);
            else
            {
                // 1-3 A defend, 4-6 H defend, 7-9 unk defend, 1 - ok, 2 - half destroyed, 3 - destroyed
                packet.Worldstates.emplace_back(0xf09, 0x0);       // 7  3849 Gate of Temple
                packet.Worldstates.emplace_back(0xe36, 0x0);       // 8  3638 Gate of Yellow Moon
                packet.Worldstates.emplace_back(0xe27, 0x0);       // 9  3623 Gate of Green Emerald
                packet.Worldstates.emplace_back(0xe24, 0x0);       // 10 3620 Gate of Blue Sapphire
                packet.Worldstates.emplace_back(0xe21, 0x0);       // 11 3617 Gate of Red Sun
                packet.Worldstates.emplace_back(0xe1e, 0x0);       // 12 3614 Gate of Purple Ametyst

                packet.Worldstates.emplace_back(0xdf3, 0x0);       // 13 3571 bonus timer (1 - on, 0 - off)
                packet.Worldstates.emplace_back(0xded, 0x0);       // 14 3565 Horde Attacker
                packet.Worldstates.emplace_back(0xdec, 0x0);       // 15 3564 Alliance Attacker
                // End Round (timer), better explain this by example, eg. ends in 19:59 -> A:BC
                packet.Worldstates.emplace_back(0xde9, 0x0);       // 16 3561 C
                packet.Worldstates.emplace_back(0xde8, 0x0);       // 17 3560 B
                packet.Worldstates.emplace_back(0xde7, 0x0);       // 18 3559 A
                packet.Worldstates.emplace_back(0xe35, 0x0);       // 19 3637 East g - Horde control
                packet.Worldstates.emplace_back(0xe34, 0x0);       // 20 3636 West g - Horde control
                packet.Worldstates.emplace_back(0xe33, 0x0);       // 21 3635 South g - Horde control
                packet.Worldstates.emplace_back(0xe32, 0x0);       // 22 3634 East g - Alliance control
                packet.Worldstates.emplace_back(0xe31, 0x0);       // 23 3633 West g - Alliance control
                packet.Worldstates.emplace_back(0xe30, 0x0);       // 24 3632 South g - Alliance control
                packet.Worldstates.emplace_back(0xe2f, 0x0);       // 25 3631 Chamber of Ancients - Horde control
                packet.Worldstates.emplace_back(0xe2e, 0x0);       // 26 3630 Chamber of Ancients - Alliance control
                packet.Worldstates.emplace_back(0xe2d, 0x0);       // 27 3629 Beach1 - Horde control
                packet.Worldstates.emplace_back(0xe2c, 0x0);       // 28 3628 Beach2 - Horde control
                packet.Worldstates.emplace_back(0xe2b, 0x0);       // 29 3627 Beach1 - Alliance control
                packet.Worldstates.emplace_back(0xe2a, 0x0);       // 30 3626 Beach2 - Alliance control
                // and many unks...
            }
            break;
        case 4406:                                          // Ring of Valor
            if (bg && bg->GetTypeID(true) == BATTLEGROUND_RV)
                bg->FillInitialWorldStates(packet);
            else
            {
                packet.Worldstates.emplace_back(0xe10, 0x0);           // 7 gold
                packet.Worldstates.emplace_back(0xe11, 0x0);           // 8 green
                packet.Worldstates.emplace_back(0xe1a, 0x0);           // 9 show
            }
            break;
        case 4710:
            if (bg && bg->GetTypeID(true) == BATTLEGROUND_IC)
                bg->FillInitialWorldStates(packet);
            else
            {
                packet.Worldstates.emplace_back(4221, 1); // 7 BG_IC_ALLIANCE_RENFORT_SET
                packet.Worldstates.emplace_back(4222, 1); // 8 BG_IC_HORDE_RENFORT_SET
                packet.Worldstates.emplace_back(4226, 300); // 9 BG_IC_ALLIANCE_RENFORT
                packet.Worldstates.emplace_back(4227, 300); // 10 BG_IC_HORDE_RENFORT
                packet.Worldstates.emplace_back(4322, 1); // 11 BG_IC_GATE_FRONT_H_WS_OPEN
                packet.Worldstates.emplace_back(4321, 1); // 12 BG_IC_GATE_WEST_H_WS_OPEN
                packet.Worldstates.emplace_back(4320, 1); // 13 BG_IC_GATE_EAST_H_WS_OPEN
                packet.Worldstates.emplace_back(4323, 1); // 14 BG_IC_GATE_FRONT_A_WS_OPEN
                packet.Worldstates.emplace_back(4324, 1); // 15 BG_IC_GATE_WEST_A_WS_OPEN
                packet.Worldstates.emplace_back(4325, 1); // 16 BG_IC_GATE_EAST_A_WS_OPEN
                packet.Worldstates.emplace_back(4317, 1); // 17 unknown

                packet.Worldstates.emplace_back(4301, 1); // 18 BG_IC_DOCKS_UNCONTROLLED
                packet.Worldstates.emplace_back(4296, 1); // 19 BG_IC_HANGAR_UNCONTROLLED
                packet.Worldstates.emplace_back(4306, 1); // 20 BG_IC_QUARRY_UNCONTROLLED
                packet.Worldstates.emplace_back(4311, 1); // 21 BG_IC_REFINERY_UNCONTROLLED
                packet.Worldstates.emplace_back(4294, 1); // 22 BG_IC_WORKSHOP_UNCONTROLLED
                packet.Worldstates.emplace_back(4243, 1); // 23 unknown
                packet.Worldstates.emplace_back(4345, 1); // 24 unknown
            }
            break;
        // The Ruby Sanctum
        case 4987:
            if (instance && mapid == 724)
                instance->FillInitialWorldStates(packet);
            else
            {
                packet.Worldstates.emplace_back(5049, 50);             // 9  WORLDSTATE_CORPOREALITY_MATERIAL
                packet.Worldstates.emplace_back(5050, 50);             // 10 WORLDSTATE_CORPOREALITY_TWILIGHT
                packet.Worldstates.emplace_back(5051, 0);              // 11 WORLDSTATE_CORPOREALITY_TOGGLE
            }
            break;
        // Icecrown Citadel
        case 4812:
            if (instance && mapid == 631)
                instance->FillInitialWorldStates(packet);
            else
            {
                packet.Worldstates.emplace_back(4903, 0);              // 9  WORLDSTATE_SHOW_TIMER (Blood Quickening weekly)
                packet.Worldstates.emplace_back(4904, 30);             // 10 WORLDSTATE_EXECUTION_TIME
                packet.Worldstates.emplace_back(4940, 0);              // 11 WORLDSTATE_SHOW_ATTEMPTS
                packet.Worldstates.emplace_back(4941, 50);             // 12 WORLDSTATE_ATTEMPTS_REMAINING
                packet.Worldstates.emplace_back(4942, 50);             // 13 WORLDSTATE_ATTEMPTS_MAX
            }
            break;
        // The Culling of Stratholme
        case 4100:
            if (instance && mapid == 595)
                instance->FillInitialWorldStates(packet);
            else
            {
                packet.Worldstates.emplace_back(3479, 0);              // 9  WORLDSTATE_SHOW_CRATES
                packet.Worldstates.emplace_back(3480, 0);              // 10 WORLDSTATE_CRATES_REVEALED
                packet.Worldstates.emplace_back(3504, 0);              // 11 WORLDSTATE_WAVE_COUNT
                packet.Worldstates.emplace_back(3931, 25);             // 12 WORLDSTATE_TIME_GUARDIAN
                packet.Worldstates.emplace_back(3932, 0);              // 13 WORLDSTATE_TIME_GUARDIAN_SHOW
            }
            break;
        // The Oculus
        case 4228:
            if (instance && mapid == 578)
                instance->FillInitialWorldStates(packet);
            else
            {
                packet.Worldstates.emplace_back(3524, 0);              // 9  WORLD_STATE_CENTRIFUGE_CONSTRUCT_SHOW
                packet.Worldstates.emplace_back(3486, 0);              // 10 WORLD_STATE_CENTRIFUGE_CONSTRUCT_AMOUNT
            }
            break;
        // Ulduar
        case 4273:
            if (instance && mapid == 603)
                instance->FillInitialWorldStates(packet);
            else
            {
                packet.Worldstates.emplace_back(4132, 0);              // 9  WORLDSTATE_ALGALON_TIMER_ENABLED
                packet.Worldstates.emplace_back(4131, 0);              // 10 WORLDSTATE_ALGALON_DESPAWN_TIMER
            }
            break;
        // Violet Hold
        case 4415:
            if (instance && mapid == 608)
                instance->FillInitialWorldStates(packet);
            else
            {
                packet.Worldstates.emplace_back(3816, 0);              // 9  WORLD_STATE_VH_SHOW
                packet.Worldstates.emplace_back(3815, 100);            // 10 WORLD_STATE_VH_PRISON_STATE
                packet.Worldstates.emplace_back(3810, 0);              // 11 WORLD_STATE_VH_WAVE_COUNT
            }
            break;
        // Halls of Refection
        case 4820:
            if (instance && mapid == 668)
                instance->FillInitialWorldStates(packet);
            else
            {
                packet.Worldstates.emplace_back(4884, 0);              // 9  WORLD_STATE_HOR_WAVES_ENABLED
                packet.Worldstates.emplace_back(4882, 0);              // 10 WORLD_STATE_HOR_WAVE_COUNT
            }
            break;
        // Zul Aman
        case 3805:
            if (instance && mapid == 568)
                instance->FillInitialWorldStates(packet);
            else
            {
                packet.Worldstates.emplace_back(3104, 0);              // 9  WORLD_STATE_ZULAMAN_TIMER_ENABLED
                packet.Worldstates.emplace_back(3106, 0);              // 10 WORLD_STATE_ZULAMAN_TIMER
            }
            break;
        // Twin Peaks
        case 5031:
            if (bg && bg->GetTypeID(true) == BATTLEGROUND_TP)
                bg->FillInitialWorldStates(packet);
            else
            {
                packet.Worldstates.emplace_back(0x62d, 0x0);       //  7 1581 alliance flag captures
                packet.Worldstates.emplace_back(0x62e, 0x0);       //  8 1582 horde flag captures
                packet.Worldstates.emplace_back(0x609, 0x0);       //  9 1545 unk
                packet.Worldstates.emplace_back(0x60a, 0x0);       // 10 1546 unk
                packet.Worldstates.emplace_back(0x60b, 0x2);       // 11 1547 unk
                packet.Worldstates.emplace_back(0x641, 0x3);       // 12 1601 unk
                packet.Worldstates.emplace_back(0x922, 0x1);       // 13 2338 horde (0 - hide, 1 - flag ok, 2 - flag picked up (flashing), 3 - flag picked up (not flashing)
                packet.Worldstates.emplace_back(0x923, 0x1);       // 14 2339 alliance (0 - hide, 1 - flag ok, 2 - flag picked up (flashing), 3 - flag picked up (not flashing)
            }
            break;
        // Battle for Gilneas
        case 5449:
            if (bg && bg->GetTypeID(true) == BATTLEGROUND_BFG)
                bg->FillInitialWorldStates(packet);
            break;
        // Wintergrasp
        case 4197:
            if (bf && bf->GetTypeId() == BATTLEFIELD_WG)
                bf->FillInitialWorldStates(packet);
            // No break here, intended.
        default:
            packet.Worldstates.emplace_back(0x914, 0x0);           // 7
            packet.Worldstates.emplace_back(0x913, 0x0);           // 8
            packet.Worldstates.emplace_back(0x912, 0x0);           // 9
            packet.Worldstates.emplace_back(0x915, 0x0);           // 10
            break;
    }

    GetSession()->SendPacket(packet.Write());
    SendBGWeekendWorldStates();
    SendBattlefieldWorldStates();
}

void Player::SendBGWeekendWorldStates() const
{
    for (uint32 i = 1; i < sBattlemasterListStore.GetNumRows(); ++i)
    {
        BattlemasterListEntry const* bl = sBattlemasterListStore.LookupEntry(i);
        if (bl && bl->HolidayWorldState)
        {
            if (BattlegroundMgr::IsBGWeekend((BattlegroundTypeId)bl->ID))
                SendUpdateWorldState(bl->HolidayWorldState, 1);
            else
                SendUpdateWorldState(bl->HolidayWorldState, 0);
        }
    }
}

void Player::SendBattlefieldWorldStates() const
{
    /// Send misc stuff that needs to be sent on every login, like the battle timers.
    if (sWorld->getBoolConfig(CONFIG_WINTERGRASP_ENABLE))
    {
        if (Battlefield* wg = sBattlefieldMgr->GetBattlefieldByBattleId(BATTLEFIELD_BATTLEID_WG))
        {
            SendUpdateWorldState(BATTLEFIELD_WG_WORLD_STATE_ACTIVE, wg->IsWarTime() ? 0 : 1);
            uint32 timer = wg->IsWarTime() ? 0 : (wg->GetTimer() / 1000); // 0 - Time to next battle
            SendUpdateWorldState(ClockWorldState[1], uint32(time(nullptr) + timer));
        }
    }
}

uint32 Player::GetXPRestBonus(uint32 xp)
{
    uint32 rested_bonus = (uint32)GetRestBonus();           // xp for each rested bonus

    if (rested_bonus > xp)                                   // max rested_bonus == xp or (r+x) = 200% xp
        rested_bonus = xp;

    SetRestBonus(GetRestBonus() - rested_bonus);

    TC_LOG_DEBUG("entities.player", "Player::GetXPRestBonus: Player '%s' (%s) gain %u xp (+%u Rested Bonus). Rested points=%f", GetGUID().ToString().c_str(), GetName().c_str(), xp + rested_bonus, rested_bonus, GetRestBonus());
    return rested_bonus;
}

void Player::SetBindPoint(ObjectGuid guid) const
{
    WorldPackets::Misc::BinderConfirm packet(guid);
    GetSession()->SendPacket(packet.Write());
}

void Player::SendRespecWipeConfirm(ObjectGuid const& guid, uint32 cost) const
{
    WorldPackets::Talent::RespecWipeConfirm respecWipeConfirm;
    respecWipeConfirm.RespecMaster = guid;
    respecWipeConfirm.Cost = cost;
    respecWipeConfirm.RespecType = SPEC_RESET_TALENTS;
    GetSession()->SendPacket(respecWipeConfirm.Write());
}

void Player::ResetPetTalents()
{
    /* TODO: 6.x remove/update pet talents
    // This needs another gossip option + NPC text as a confirmation.
    // The confirmation gossip listid has the text: "Yes, please do."
    Pet* pet = GetPet();

    if (!pet || pet->getPetType() != HUNTER_PET || pet->m_usedTalentCount == 0)
        return;

    CharmInfo* charmInfo = pet->GetCharmInfo();
    if (!charmInfo)
    {
        TC_LOG_ERROR("entities.player", "Object (%s) is considered pet-like but doesn't have a charminfo!", pet->GetGUID().ToString().c_str());
        return;
    }
    pet->resetTalents();
    SendTalentsInfoData(true);
    */
}

/*********************************************************/
/***                    STORAGE SYSTEM                 ***/
/*********************************************************/

void Player::SetVirtualItemSlot(uint8 i, Item* item)
{
    ASSERT(i < 3);
    if (i < 2 && item)
    {
        if (!item->GetEnchantmentId(TEMP_ENCHANTMENT_SLOT))
            return;
        uint32 charges = item->GetEnchantmentCharges(TEMP_ENCHANTMENT_SLOT);
        if (charges == 0)
            return;
        if (charges > 1)
            item->SetEnchantmentCharges(TEMP_ENCHANTMENT_SLOT, charges-1);
        else if (charges <= 1)
        {
            ApplyEnchantment(item, TEMP_ENCHANTMENT_SLOT, false);
            item->ClearEnchantment(TEMP_ENCHANTMENT_SLOT);
        }
    }
}

void Player::SetSheath(SheathState sheathed)
{
    switch (sheathed)
    {
        case SHEATH_STATE_UNARMED:                          // no prepared weapon
            SetVirtualItemSlot(0, nullptr);
            SetVirtualItemSlot(1, nullptr);
            SetVirtualItemSlot(2, nullptr);
            break;
        case SHEATH_STATE_MELEE:                            // prepared melee weapon
            SetVirtualItemSlot(0, GetWeaponForAttack(BASE_ATTACK, true));
            SetVirtualItemSlot(1, GetWeaponForAttack(OFF_ATTACK, true));
            SetVirtualItemSlot(2, nullptr);
            break;
        case SHEATH_STATE_RANGED:                           // prepared ranged weapon
            SetVirtualItemSlot(0, nullptr);
            SetVirtualItemSlot(1, nullptr);
            SetVirtualItemSlot(2, GetWeaponForAttack(RANGED_ATTACK, true));
            break;
        default:
            SetVirtualItemSlot(0, nullptr);
            SetVirtualItemSlot(1, nullptr);
            SetVirtualItemSlot(2, nullptr);
            break;
    }
    Unit::SetSheath(sheathed);                              // this must visualize Sheath changing for other players...
}

uint8 Player::FindEquipSlot(ItemTemplate const* proto, uint32 slot, bool swap) const
{
    uint8 slots[4];
    slots[0] = NULL_SLOT;
    slots[1] = NULL_SLOT;
    slots[2] = NULL_SLOT;
    slots[3] = NULL_SLOT;
    switch (proto->GetInventoryType())
    {
        case INVTYPE_HEAD:
            slots[0] = EQUIPMENT_SLOT_HEAD;
            break;
        case INVTYPE_NECK:
            slots[0] = EQUIPMENT_SLOT_NECK;
            break;
        case INVTYPE_SHOULDERS:
            slots[0] = EQUIPMENT_SLOT_SHOULDERS;
            break;
        case INVTYPE_BODY:
            slots[0] = EQUIPMENT_SLOT_BODY;
            break;
        case INVTYPE_CHEST:
            slots[0] = EQUIPMENT_SLOT_CHEST;
            break;
        case INVTYPE_ROBE:
            slots[0] = EQUIPMENT_SLOT_CHEST;
            break;
        case INVTYPE_WAIST:
            slots[0] = EQUIPMENT_SLOT_WAIST;
            break;
        case INVTYPE_LEGS:
            slots[0] = EQUIPMENT_SLOT_LEGS;
            break;
        case INVTYPE_FEET:
            slots[0] = EQUIPMENT_SLOT_FEET;
            break;
        case INVTYPE_WRISTS:
            slots[0] = EQUIPMENT_SLOT_WRISTS;
            break;
        case INVTYPE_HANDS:
            slots[0] = EQUIPMENT_SLOT_HANDS;
            break;
        case INVTYPE_FINGER:
            slots[0] = EQUIPMENT_SLOT_FINGER1;
            slots[1] = EQUIPMENT_SLOT_FINGER2;
            break;
        case INVTYPE_TRINKET:
            slots[0] = EQUIPMENT_SLOT_TRINKET1;
            slots[1] = EQUIPMENT_SLOT_TRINKET2;
            break;
        case INVTYPE_CLOAK:
            slots[0] = EQUIPMENT_SLOT_BACK;
            break;
        case INVTYPE_WEAPON:
        {
            slots[0] = EQUIPMENT_SLOT_MAINHAND;

            // suggest offhand slot only if know dual wielding
            // (this will be replace mainhand weapon at auto equip instead unwonted "you don't known dual wielding" ...
            if (CanDualWield())
                slots[1] = EQUIPMENT_SLOT_OFFHAND;
            break;
        }
        case INVTYPE_SHIELD:
            slots[0] = EQUIPMENT_SLOT_OFFHAND;
            break;
        case INVTYPE_RANGED:
            slots[0] = EQUIPMENT_SLOT_MAINHAND;
            break;
        case INVTYPE_2HWEAPON:
            slots[0] = EQUIPMENT_SLOT_MAINHAND;
            if (CanDualWield() && CanTitanGrip())
                slots[1] = EQUIPMENT_SLOT_OFFHAND;
            break;
        case INVTYPE_TABARD:
            slots[0] = EQUIPMENT_SLOT_TABARD;
            break;
        case INVTYPE_WEAPONMAINHAND:
            slots[0] = EQUIPMENT_SLOT_MAINHAND;
            break;
        case INVTYPE_WEAPONOFFHAND:
            slots[0] = EQUIPMENT_SLOT_OFFHAND;
            break;
        case INVTYPE_HOLDABLE:
            slots[0] = EQUIPMENT_SLOT_OFFHAND;
            break;
        case INVTYPE_RANGEDRIGHT:
            slots[0] = EQUIPMENT_SLOT_MAINHAND;
            break;
        case INVTYPE_BAG:
            slots[0] = INVENTORY_SLOT_BAG_START + 0;
            slots[1] = INVENTORY_SLOT_BAG_START + 1;
            slots[2] = INVENTORY_SLOT_BAG_START + 2;
            slots[3] = INVENTORY_SLOT_BAG_START + 3;
            break;
        default:
            return NULL_SLOT;
    }

    if (slot != NULL_SLOT)
    {
        if (swap || !GetItemByPos(INVENTORY_SLOT_BAG_0, slot))
            for (uint8 i = 0; i < 4; ++i)
                if (slots[i] == slot)
                    return slot;
    }
    else
    {
        // search free slot at first
        for (uint8 i = 0; i < 4; ++i)
            if (slots[i] != NULL_SLOT && !GetItemByPos(INVENTORY_SLOT_BAG_0, slots[i]))
                // in case 2hand equipped weapon (without titan grip) offhand slot empty but not free
                if (slots[i] != EQUIPMENT_SLOT_OFFHAND || !IsTwoHandUsed())
                    return slots[i];

        // if not found free and can swap return first appropriate from used
        for (uint8 i = 0; i < 4; ++i)
            if (slots[i] != NULL_SLOT && swap)
                return slots[i];
    }

    // no free position
    return NULL_SLOT;
}

InventoryResult Player::CanUnequipItems(uint32 item, uint32 count) const
{
    uint32 tempcount = 0;

    InventoryResult res = EQUIP_ERR_OK;

    for (uint8 i = EQUIPMENT_SLOT_START; i < INVENTORY_SLOT_BAG_END; ++i)
        if (Item* pItem = GetItemByPos(INVENTORY_SLOT_BAG_0, i))
            if (pItem->GetEntry() == item)
            {
                InventoryResult ires = CanUnequipItem(INVENTORY_SLOT_BAG_0 << 8 | i, false);
                if (ires == EQUIP_ERR_OK)
                {
                    tempcount += pItem->GetCount();
                    if (tempcount >= count)
                        return EQUIP_ERR_OK;
                }
                else
                    res = ires;
            }

    for (uint8 i = INVENTORY_SLOT_ITEM_START; i < INVENTORY_SLOT_ITEM_END; ++i)
        if (Item* pItem = GetItemByPos(INVENTORY_SLOT_BAG_0, i))
            if (pItem->GetEntry() == item)
            {
                tempcount += pItem->GetCount();
                if (tempcount >= count)
                    return EQUIP_ERR_OK;
            }


    for (uint8 i = INVENTORY_SLOT_BAG_START; i < INVENTORY_SLOT_BAG_END; ++i)
        if (Bag* pBag = GetBagByPos(i))
            for (uint32 j = 0; j < pBag->GetBagSize(); ++j)
                if (Item* pItem = GetItemByPos(i, j))
                    if (pItem->GetEntry() == item)
                    {
                        tempcount += pItem->GetCount();
                        if (tempcount >= count)
                            return EQUIP_ERR_OK;
                    }

    // not found req. item count and have unequippable items
    return res;
}

uint32 Player::GetItemCount(uint32 item, bool inBankAlso, Item* skipItem) const
{
    uint32 count = 0;
    for (uint8 i = EQUIPMENT_SLOT_START; i < INVENTORY_SLOT_ITEM_END; i++)
        if (Item* pItem = GetItemByPos(INVENTORY_SLOT_BAG_0, i))
            if (pItem != skipItem &&  pItem->GetEntry() == item)
                count += pItem->GetCount();

    for (uint8 i = INVENTORY_SLOT_BAG_START; i < INVENTORY_SLOT_BAG_END; ++i)
        if (Bag* pBag = GetBagByPos(i))
            count += pBag->GetItemCount(item, skipItem);

    if (skipItem && skipItem->GetTemplate()->GetGemProperties())
        for (uint8 i = EQUIPMENT_SLOT_START; i < INVENTORY_SLOT_ITEM_END; ++i)
            if (Item* pItem = GetItemByPos(INVENTORY_SLOT_BAG_0, i))
                if (pItem != skipItem && pItem->GetSocketColor(0))
                    count += pItem->GetGemCountWithID(item);

    if (inBankAlso)
    {
        // checking every item from 39 to 74 (including bank bags)
        for (uint8 i = BANK_SLOT_ITEM_START; i < BANK_SLOT_BAG_END; ++i)
            if (Item* pItem = GetItemByPos(INVENTORY_SLOT_BAG_0, i))
                if (pItem != skipItem && pItem->GetEntry() == item)
                    count += pItem->GetCount();

        for (uint8 i = BANK_SLOT_BAG_START; i < BANK_SLOT_BAG_END; ++i)
            if (Bag* pBag = GetBagByPos(i))
                count += pBag->GetItemCount(item, skipItem);

        if (skipItem && skipItem->GetTemplate()->GetGemProperties())
            for (uint8 i = BANK_SLOT_ITEM_START; i < BANK_SLOT_ITEM_END; ++i)
                if (Item* pItem = GetItemByPos(INVENTORY_SLOT_BAG_0, i))
                    if (pItem != skipItem && pItem->GetSocketColor(0))
                        count += pItem->GetGemCountWithID(item);
    }

    return count;
}

uint32 Player::GetItemCountWithLimitCategory(uint32 limitCategory, Item* skipItem) const
{
    uint32 count = 0;
    for (int i = EQUIPMENT_SLOT_START; i < INVENTORY_SLOT_ITEM_END; ++i)
        if (Item* pItem = GetItemByPos(INVENTORY_SLOT_BAG_0, i))
            if (pItem != skipItem)
                if (ItemTemplate const* pProto = pItem->GetTemplate())
                    if (pProto->GetItemLimitCategory() == limitCategory)
                        count += pItem->GetCount();

    for (int i = INVENTORY_SLOT_BAG_START; i < INVENTORY_SLOT_BAG_END; ++i)
        if (Bag* pBag = GetBagByPos(i))
            count += pBag->GetItemCountWithLimitCategory(limitCategory, skipItem);

    for (int i = BANK_SLOT_ITEM_START; i < BANK_SLOT_BAG_END; ++i)
        if (Item* pItem = GetItemByPos(INVENTORY_SLOT_BAG_0, i))
            if (pItem != skipItem)
                if (ItemTemplate const* pProto = pItem->GetTemplate())
                    if (pProto->GetItemLimitCategory() == limitCategory)
                        count += pItem->GetCount();

    for (int i = BANK_SLOT_BAG_START; i < BANK_SLOT_BAG_END; ++i)
        if (Bag* pBag = GetBagByPos(i))
            count += pBag->GetItemCountWithLimitCategory(limitCategory, skipItem);

    return count;
}

Item* Player::GetItemByGuid(ObjectGuid guid) const
{
    for (uint8 i = EQUIPMENT_SLOT_START; i < INVENTORY_SLOT_ITEM_END; ++i)
        if (Item* pItem = GetItemByPos(INVENTORY_SLOT_BAG_0, i))
            if (pItem->GetGUID() == guid)
                return pItem;

    for (int i = BANK_SLOT_ITEM_START; i < BANK_SLOT_BAG_END; ++i)
        if (Item* pItem = GetItemByPos(INVENTORY_SLOT_BAG_0, i))
            if (pItem->GetGUID() == guid)
                return pItem;

    for (uint8 i = INVENTORY_SLOT_BAG_START; i < INVENTORY_SLOT_BAG_END; ++i)
        if (Bag* pBag = GetBagByPos(i))
            for (uint32 j = 0; j < pBag->GetBagSize(); ++j)
                if (Item* pItem = pBag->GetItemByPos(j))
                    if (pItem->GetGUID() == guid)
                        return pItem;

    for (uint8 i = BANK_SLOT_BAG_START; i < BANK_SLOT_BAG_END; ++i)
        if (Bag* pBag = GetBagByPos(i))
            for (uint32 j = 0; j < pBag->GetBagSize(); ++j)
                if (Item* pItem = pBag->GetItemByPos(j))
                    if (pItem->GetGUID() == guid)
                        return pItem;

    return nullptr;
}

Item* Player::GetItemByPos(uint16 pos) const
{
    uint8 bag = pos >> 8;
    uint8 slot = pos & 255;
    return GetItemByPos(bag, slot);
}

Item* Player::GetItemByPos(uint8 bag, uint8 slot) const
{
    if (bag == INVENTORY_SLOT_BAG_0 && slot < BANK_SLOT_BAG_END)
        return m_items[slot];
    if (Bag* pBag = GetBagByPos(bag))
        return pBag->GetItemByPos(slot);
    return nullptr;
}

//Does additional check for disarmed weapons
Item* Player::GetUseableItemByPos(uint8 bag, uint8 slot) const
{
    Item* item = GetItemByPos(bag, slot);
    if (!item)
        return nullptr;

    if (!CanUseAttackType(GetAttackBySlot(slot, item->GetTemplate()->GetInventoryType())))
        return nullptr;

    return item;
}

Bag* Player::GetBagByPos(uint8 bag) const
{
    if ((bag >= INVENTORY_SLOT_BAG_START && bag < INVENTORY_SLOT_BAG_END)
        || (bag >= BANK_SLOT_BAG_START && bag < BANK_SLOT_BAG_END))
        if (Item* item = GetItemByPos(INVENTORY_SLOT_BAG_0, bag))
            return item->ToBag();
    return nullptr;
}

Item* Player::GetWeaponForAttack(WeaponAttackType attackType, bool useable /*= false*/) const
{
    uint8 slot;
    switch (attackType)
    {
        case BASE_ATTACK:   slot = EQUIPMENT_SLOT_MAINHAND; break;
        case OFF_ATTACK:    slot = EQUIPMENT_SLOT_OFFHAND;  break;
        case RANGED_ATTACK: slot = EQUIPMENT_SLOT_MAINHAND;   break;
        default: return nullptr;
    }

    Item* item;
    if (useable)
        item = GetUseableItemByPos(INVENTORY_SLOT_BAG_0, slot);
    else
        item = GetItemByPos(INVENTORY_SLOT_BAG_0, slot);
    if (!item || item->GetTemplate()->GetClass() != ITEM_CLASS_WEAPON)
        return nullptr;

    if (!useable)
        return item;

    if (item->IsBroken() || IsInFeralForm())
        return nullptr;

    return item;
}

Item* Player::GetShield(bool useable) const
{
    Item* item;
    if (useable)
        item = GetUseableItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND);
    else
        item = GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND);

    if (!item || item->GetTemplate()->GetClass() != ITEM_CLASS_ARMOR)
        return nullptr;

    if (!useable)
        return item;

    if (item->IsBroken())
        return nullptr;

    return item;
}

uint8 Player::GetAttackBySlot(uint8 slot, InventoryType inventoryType)
{
    switch (slot)
    {
        case EQUIPMENT_SLOT_MAINHAND: return inventoryType != INVTYPE_RANGED && inventoryType != INVTYPE_RANGEDRIGHT ? BASE_ATTACK : RANGED_ATTACK;
        case EQUIPMENT_SLOT_OFFHAND:  return OFF_ATTACK;
        default:                      return MAX_ATTACK;
    }
}

bool Player::IsInventoryPos(uint8 bag, uint8 slot)
{
    if (bag == INVENTORY_SLOT_BAG_0 && slot == NULL_SLOT)
        return true;
    if (bag == INVENTORY_SLOT_BAG_0 && (slot >= INVENTORY_SLOT_ITEM_START && slot < INVENTORY_SLOT_ITEM_END))
        return true;
    if (bag >= INVENTORY_SLOT_BAG_START && bag < INVENTORY_SLOT_BAG_END)
        return true;
    return false;
}

bool Player::IsEquipmentPos(uint8 bag, uint8 slot)
{
    if (bag == INVENTORY_SLOT_BAG_0 && (slot < EQUIPMENT_SLOT_END))
        return true;
    if (bag == INVENTORY_SLOT_BAG_0 && (slot >= INVENTORY_SLOT_BAG_START && slot < INVENTORY_SLOT_BAG_END))
        return true;
    return false;
}

bool Player::IsBankPos(uint8 bag, uint8 slot)
{
    if (bag == INVENTORY_SLOT_BAG_0 && (slot >= BANK_SLOT_ITEM_START && slot < BANK_SLOT_ITEM_END))
        return true;
    if (bag == INVENTORY_SLOT_BAG_0 && (slot >= BANK_SLOT_BAG_START && slot < BANK_SLOT_BAG_END))
        return true;
    if (bag >= BANK_SLOT_BAG_START && bag < BANK_SLOT_BAG_END)
        return true;
    return false;
}

bool Player::IsBagPos(uint16 pos)
{
    uint8 bag = pos >> 8;
    uint8 slot = pos & 255;
    if (bag == INVENTORY_SLOT_BAG_0 && (slot >= INVENTORY_SLOT_BAG_START && slot < INVENTORY_SLOT_BAG_END))
        return true;
    if (bag == INVENTORY_SLOT_BAG_0 && (slot >= BANK_SLOT_BAG_START && slot < BANK_SLOT_BAG_END))
        return true;
    return false;
}

bool Player::IsValidPos(uint8 bag, uint8 slot, bool explicit_pos) const
{
    // post selected
    if (bag == NULL_BAG && !explicit_pos)
        return true;

    if (bag == INVENTORY_SLOT_BAG_0)
    {
        // any post selected
        if (slot == NULL_SLOT && !explicit_pos)
            return true;

        // equipment
        if (slot < EQUIPMENT_SLOT_END)
            return true;

        // bag equip slots
        if (slot >= INVENTORY_SLOT_BAG_START && slot < INVENTORY_SLOT_BAG_END)
            return true;

        // backpack slots
        if (slot >= INVENTORY_SLOT_ITEM_START && slot < INVENTORY_SLOT_ITEM_END)
            return true;

        // bank main slots
        if (slot >= BANK_SLOT_ITEM_START && slot < BANK_SLOT_ITEM_END)
            return true;

        // bank bag slots
        if (slot >= BANK_SLOT_BAG_START && slot < BANK_SLOT_BAG_END)
            return true;

        return false;
    }

    // bag content slots
    // bank bag content slots
    if (Bag* pBag = GetBagByPos(bag))
    {
        // any post selected
        if (slot == NULL_SLOT && !explicit_pos)
            return true;

        return slot < pBag->GetBagSize();
    }

    // where this?
    return false;
}

bool Player::HasItemCount(uint32 item, uint32 count, bool inBankAlso) const
{
    uint32 tempcount = 0;
    for (uint8 i = EQUIPMENT_SLOT_START; i < INVENTORY_SLOT_ITEM_END; i++)
    {
        Item* pItem = GetItemByPos(INVENTORY_SLOT_BAG_0, i);
        if (pItem && pItem->GetEntry() == item && !pItem->IsInTrade())
        {
            tempcount += pItem->GetCount();
            if (tempcount >= count)
                return true;
        }
    }

    for (uint8 i = INVENTORY_SLOT_BAG_START; i < INVENTORY_SLOT_BAG_END; i++)
    {
        if (Bag* pBag = GetBagByPos(i))
        {
            for (uint32 j = 0; j < pBag->GetBagSize(); j++)
            {
                Item* pItem = GetItemByPos(i, j);
                if (pItem && pItem->GetEntry() == item && !pItem->IsInTrade())
                {
                    tempcount += pItem->GetCount();
                    if (tempcount >= count)
                        return true;
                }
            }
        }
    }

    if (inBankAlso)
    {
        for (uint8 i = BANK_SLOT_ITEM_START; i < BANK_SLOT_ITEM_END; i++)
        {
            Item* pItem = GetItemByPos(INVENTORY_SLOT_BAG_0, i);
            if (pItem && pItem->GetEntry() == item && !pItem->IsInTrade())
            {
                tempcount += pItem->GetCount();
                if (tempcount >= count)
                    return true;
            }
        }
        for (uint8 i = BANK_SLOT_BAG_START; i < BANK_SLOT_BAG_END; i++)
        {
            if (Bag* pBag = GetBagByPos(i))
            {
                for (uint32 j = 0; j < pBag->GetBagSize(); j++)
                {
                    Item* pItem = GetItemByPos(i, j);
                    if (pItem && pItem->GetEntry() == item && !pItem->IsInTrade())
                    {
                        tempcount += pItem->GetCount();
                        if (tempcount >= count)
                            return true;
                    }
                }
            }
        }
    }

    return false;
}

bool Player::HasItemOrGemWithIdEquipped(uint32 item, uint32 count, uint8 except_slot) const
{
    uint32 tempcount = 0;
    for (uint8 i = EQUIPMENT_SLOT_START; i < EQUIPMENT_SLOT_END; ++i)
    {
        if (i == except_slot)
            continue;

        Item* pItem = GetItemByPos(INVENTORY_SLOT_BAG_0, i);
        if (pItem && pItem->GetEntry() == item)
        {
            tempcount += pItem->GetCount();
            if (tempcount >= count)
                return true;
        }
    }

    ItemTemplate const* pProto = sObjectMgr->GetItemTemplate(item);
    if (pProto && pProto->GetGemProperties())
    {
        for (uint8 i = EQUIPMENT_SLOT_START; i < EQUIPMENT_SLOT_END; ++i)
        {
            if (i == except_slot)
                continue;

            Item* pItem = GetItemByPos(INVENTORY_SLOT_BAG_0, i);
            if (pItem && pItem->GetSocketColor(0))
            {
                tempcount += pItem->GetGemCountWithID(item);
                if (tempcount >= count)
                    return true;
            }
        }
    }

    return false;
}

bool Player::HasItemOrGemWithLimitCategoryEquipped(uint32 limitCategory, uint32 count, uint8 except_slot) const
{
    uint32 tempcount = 0;
    for (uint8 i = EQUIPMENT_SLOT_START; i < EQUIPMENT_SLOT_END; ++i)
    {
        if (i == except_slot)
            continue;

        Item* pItem = GetItemByPos(INVENTORY_SLOT_BAG_0, i);
        if (!pItem)
            continue;

        ItemTemplate const* pProto = pItem->GetTemplate();
        if (!pProto)
            continue;

        if (pProto->GetItemLimitCategory() == limitCategory)
        {
            tempcount += pItem->GetCount();
            if (tempcount >= count)
                return true;
        }

        if (pItem->GetSocketColor(0) || pItem->GetEnchantmentId(PRISMATIC_ENCHANTMENT_SLOT))
        {
            tempcount += pItem->GetGemCountWithLimitCategory(limitCategory);
            if (tempcount >= count)
                return true;
        }
    }

    return false;
}

InventoryResult Player::CanTakeMoreSimilarItems(uint32 entry, uint32 count, Item* pItem, uint32* no_space_count /*= nullptr*/, uint32* offendingItemId /*= nullptr*/) const
{
    ItemTemplate const* pProto = sObjectMgr->GetItemTemplate(entry);
    if (!pProto)
    {
        if (no_space_count)
            *no_space_count = count;
        return EQUIP_ERR_ITEM_MAX_COUNT;
    }

    if (pItem && pItem->m_lootGenerated)
        return EQUIP_ERR_LOOT_GONE;

    // no maximum
    if ((pProto->GetMaxCount() <= 0 && pProto->GetItemLimitCategory() == 0) || pProto->GetMaxCount() == 2147483647)
        return EQUIP_ERR_OK;

    if (pProto->GetMaxCount() > 0)
    {
        uint32 curcount = GetItemCount(pProto->GetId(), true, pItem);
        if (curcount + count > uint32(pProto->GetMaxCount()))
        {
            if (no_space_count)
                *no_space_count = count + curcount - pProto->GetMaxCount();
            return EQUIP_ERR_ITEM_MAX_COUNT;
        }
    }

    // check unique-equipped limit
    if (pProto->GetItemLimitCategory())
    {
        ItemLimitCategoryEntry const* limitEntry = sItemLimitCategoryStore.LookupEntry(pProto->GetItemLimitCategory());
        if (!limitEntry)
        {
            if (no_space_count)
                *no_space_count = count;
            return EQUIP_ERR_NOT_EQUIPPABLE;
        }

        if (limitEntry->Flags == ITEM_LIMIT_CATEGORY_MODE_HAVE)
        {
            uint32 curcount = GetItemCountWithLimitCategory(pProto->GetItemLimitCategory(), pItem);
            if (curcount + count > uint32(limitEntry->Quantity))
            {
                if (no_space_count)
                    *no_space_count = count + curcount - limitEntry->Quantity;
                if (offendingItemId)
                    *offendingItemId = pProto->GetId();
                return EQUIP_ERR_ITEM_MAX_LIMIT_CATEGORY_COUNT_EXCEEDED_IS;
            }
        }
    }

    return EQUIP_ERR_OK;
}

InventoryResult Player::CanStoreNewItem(uint8 bag, uint8 slot, ItemPosCountVec& dest, uint32 item, uint32 count, uint32* no_space_count /*= NULL*/) const
{
    return CanStoreItem(bag, slot, dest, item, count, nullptr, false, no_space_count);
}

InventoryResult Player::CanStoreItem(uint8 bag, uint8 slot, ItemPosCountVec& dest, Item* pItem, bool swap /*= false*/) const
{
    if (!pItem)
        return EQUIP_ERR_ITEM_NOT_FOUND;
    uint32 count = pItem->GetCount();
    return CanStoreItem(bag, slot, dest, pItem->GetEntry(), count, pItem, swap, nullptr);
}

bool Player::HasItemTotemCategory(uint32 TotemCategory) const
{
    Item* item;
    for (uint8 i = EQUIPMENT_SLOT_START; i < INVENTORY_SLOT_ITEM_END; ++i)
    {
        item = GetUseableItemByPos(INVENTORY_SLOT_BAG_0, i);
        if (item && IsTotemCategoryCompatibleWith(item->GetTemplate()->GetTotemCategory(), TotemCategory))
            return true;
    }

    Bag* bag;
    for (uint8 i = INVENTORY_SLOT_BAG_START; i < INVENTORY_SLOT_BAG_END; ++i)
    {
        bag = GetBagByPos(i);
        if (bag)
        {
            for (uint32 j = 0; j < bag->GetBagSize(); ++j)
            {
                item = GetUseableItemByPos(i, j);
                if (item && IsTotemCategoryCompatibleWith(item->GetTemplate()->GetTotemCategory(), TotemCategory))
                    return true;
            }
        }
    }

    return false;
}

InventoryResult Player::CanStoreItem_InSpecificSlot(uint8 bag, uint8 slot, ItemPosCountVec &dest, ItemTemplate const* pProto, uint32& count, bool swap, Item* pSrcItem) const
{
    Item* pItem2 = GetItemByPos(bag, slot);

    // ignore move item (this slot will be empty at move)
    if (pItem2 == pSrcItem)
        pItem2 = nullptr;

    uint32 need_space;

    if (pSrcItem && pSrcItem->IsNotEmptyBag() && !IsBagPos(uint16(bag) << 8 | slot))
        return EQUIP_ERR_DESTROY_NONEMPTY_BAG;

    // empty specific slot - check item fit to slot
    if (!pItem2 || swap)
    {
        if (bag == INVENTORY_SLOT_BAG_0)
        {
            // prevent cheating
            if ((slot >= BUYBACK_SLOT_START && slot < BUYBACK_SLOT_END) || slot >= PLAYER_SLOT_END)
                return EQUIP_ERR_WRONG_BAG_TYPE;
        }
        else
        {
            Bag* pBag = GetBagByPos(bag);
            if (!pBag)
                return EQUIP_ERR_WRONG_BAG_TYPE;

            ItemTemplate const* pBagProto = pBag->GetTemplate();
            if (!pBagProto)
                return EQUIP_ERR_WRONG_BAG_TYPE;

            if (slot >= pBagProto->GetContainerSlots())
                return EQUIP_ERR_WRONG_BAG_TYPE;

            if (!ItemCanGoIntoBag(pProto, pBagProto))
                return EQUIP_ERR_WRONG_BAG_TYPE;
        }

        // non empty stack with space
        need_space = pProto->GetMaxStackSize();
    }
    // non empty slot, check item type
    else
    {
        // can be merged at least partly
        InventoryResult res  = pItem2->CanBeMergedPartlyWith(pProto);
        if (res != EQUIP_ERR_OK)
            return res;

        // free stack space or infinity
        need_space = pProto->GetMaxStackSize() - pItem2->GetCount();
    }

    if (need_space > count)
        need_space = count;

    ItemPosCount newPosition = ItemPosCount((bag << 8) | slot, need_space);
    if (!newPosition.isContainedIn(dest))
    {
        dest.push_back(newPosition);
        count -= need_space;
    }
    return EQUIP_ERR_OK;
}

InventoryResult Player::CanStoreItem_InBag(uint8 bag, ItemPosCountVec &dest, ItemTemplate const* pProto, uint32& count, bool merge, bool non_specialized, Item* pSrcItem, uint8 skip_bag, uint8 skip_slot) const
{
    // skip specific bag already processed in first called CanStoreItem_InBag
    if (bag == skip_bag)
        return EQUIP_ERR_WRONG_BAG_TYPE;

    // skip not existed bag or self targeted bag
    Bag* pBag = GetBagByPos(bag);
    if (!pBag || pBag == pSrcItem)
        return EQUIP_ERR_WRONG_BAG_TYPE;

    if (pSrcItem && pSrcItem->IsNotEmptyBag())
        return EQUIP_ERR_DESTROY_NONEMPTY_BAG;

    ItemTemplate const* pBagProto = pBag->GetTemplate();
    if (!pBagProto)
        return EQUIP_ERR_WRONG_BAG_TYPE;

    // specialized bag mode or non-specialized
    if (non_specialized != (pBagProto->GetClass() == ITEM_CLASS_CONTAINER && pBagProto->GetSubClass() == ITEM_SUBCLASS_CONTAINER))
        return EQUIP_ERR_WRONG_BAG_TYPE;

    if (!ItemCanGoIntoBag(pProto, pBagProto))
        return EQUIP_ERR_WRONG_BAG_TYPE;

    for (uint32 j = 0; j < pBag->GetBagSize(); j++)
    {
        // skip specific slot already processed in first called CanStoreItem_InSpecificSlot
        if (j == skip_slot)
            continue;

        Item* pItem2 = GetItemByPos(bag, j);

        // ignore move item (this slot will be empty at move)
        if (pItem2 == pSrcItem)
            pItem2 = nullptr;

        // if merge skip empty, if !merge skip non-empty
        if ((pItem2 != nullptr) != merge)
            continue;

        uint32 need_space = pProto->GetMaxStackSize();

        if (pItem2)
        {
            // can be merged at least partly
            uint8 res  = pItem2->CanBeMergedPartlyWith(pProto);
            if (res != EQUIP_ERR_OK)
                continue;

            // descrease at current stacksize
            need_space -= pItem2->GetCount();
        }

        if (need_space > count)
            need_space = count;

        ItemPosCount newPosition = ItemPosCount((bag << 8) | j, need_space);
        if (!newPosition.isContainedIn(dest))
        {
            dest.push_back(newPosition);
            count -= need_space;

            if (count==0)
                return EQUIP_ERR_OK;
        }
    }
    return EQUIP_ERR_OK;
}

InventoryResult Player::CanStoreItem_InInventorySlots(uint8 slot_begin, uint8 slot_end, ItemPosCountVec &dest, ItemTemplate const* pProto, uint32& count, bool merge, Item* pSrcItem, uint8 skip_bag, uint8 skip_slot) const
{
    //this is never called for non-bag slots so we can do this
    if (pSrcItem && pSrcItem->IsNotEmptyBag())
        return EQUIP_ERR_DESTROY_NONEMPTY_BAG;

    for (uint32 j = slot_begin; j < slot_end; j++)
    {
        // skip specific slot already processed in first called CanStoreItem_InSpecificSlot
        if (INVENTORY_SLOT_BAG_0 == skip_bag && j == skip_slot)
            continue;

        Item* pItem2 = GetItemByPos(INVENTORY_SLOT_BAG_0, j);

        // ignore move item (this slot will be empty at move)
        if (pItem2 == pSrcItem)
            pItem2 = nullptr;

        // if merge skip empty, if !merge skip non-empty
        if ((pItem2 != nullptr) != merge)
            continue;

        uint32 need_space = pProto->GetMaxStackSize();

        if (pItem2)
        {
            // can be merged at least partly
            uint8 res  = pItem2->CanBeMergedPartlyWith(pProto);
            if (res != EQUIP_ERR_OK)
                continue;

            // descrease at current stacksize
            need_space -= pItem2->GetCount();
        }

        if (need_space > count)
            need_space = count;

        ItemPosCount newPosition = ItemPosCount((INVENTORY_SLOT_BAG_0 << 8) | j, need_space);
        if (!newPosition.isContainedIn(dest))
        {
            dest.push_back(newPosition);
            count -= need_space;

            if (count==0)
                return EQUIP_ERR_OK;
        }
    }
    return EQUIP_ERR_OK;
}

InventoryResult Player::CanStoreItem(uint8 bag, uint8 slot, ItemPosCountVec &dest, uint32 entry, uint32 count, Item* pItem, bool swap, uint32* no_space_count) const
{
    TC_LOG_DEBUG("entities.player.items", "Player::CanStoreItem: Bag: %u, Slot: %u, Item: %u, Count: %u", bag, slot, entry, count);

    ItemTemplate const* pProto = sObjectMgr->GetItemTemplate(entry);
    if (!pProto)
    {
        if (no_space_count)
            *no_space_count = count;
        return swap ? EQUIP_ERR_CANT_SWAP : EQUIP_ERR_ITEM_NOT_FOUND;
    }

    if (pItem)
    {
        // item used
        if (pItem->m_lootGenerated)
        {
            if (no_space_count)
                *no_space_count = count;
            return EQUIP_ERR_LOOT_GONE;
        }

        if (pItem->IsBindedNotWith(this))
        {
            if (no_space_count)
                *no_space_count = count;
            return EQUIP_ERR_NOT_OWNER;
        }
    }

    // check count of items (skip for auto move for same player from bank)
    uint32 no_similar_count = 0;                            // can't store this amount similar items
    InventoryResult res = CanTakeMoreSimilarItems(entry, count, pItem, &no_similar_count);
    if (res != EQUIP_ERR_OK)
    {
        if (count == no_similar_count)
        {
            if (no_space_count)
                *no_space_count = no_similar_count;
            return res;
        }
        count -= no_similar_count;
    }

    // in specific slot
    if (bag != NULL_BAG && slot != NULL_SLOT)
    {
        res = CanStoreItem_InSpecificSlot(bag, slot, dest, pProto, count, swap, pItem);
        if (res != EQUIP_ERR_OK)
        {
            if (no_space_count)
                *no_space_count = count + no_similar_count;
            return res;
        }

        if (count == 0)
        {
            if (no_similar_count == 0)
                return EQUIP_ERR_OK;

            if (no_space_count)
                *no_space_count = count + no_similar_count;
            return EQUIP_ERR_ITEM_MAX_COUNT;
        }
    }

    // not specific slot or have space for partly store only in specific slot

    // in specific bag
    if (bag != NULL_BAG)
    {
        // search stack in bag for merge to
        if (pProto->GetMaxStackSize() != 1)
        {
            if (bag == INVENTORY_SLOT_BAG_0)               // inventory
            {
                res = CanStoreItem_InInventorySlots(INVENTORY_SLOT_ITEM_START, INVENTORY_SLOT_ITEM_END, dest, pProto, count, true, pItem, bag, slot);
                if (res != EQUIP_ERR_OK)
                {
                    if (no_space_count)
                        *no_space_count = count + no_similar_count;
                    return res;
                }

                if (count == 0)
                {
                    if (no_similar_count == 0)
                        return EQUIP_ERR_OK;

                    if (no_space_count)
                        *no_space_count = count + no_similar_count;
                    return EQUIP_ERR_ITEM_MAX_COUNT;
                }
            }
            else                                            // equipped bag
            {
                // we need check 2 time (specialized/non_specialized), use NULL_BAG to prevent skipping bag
                res = CanStoreItem_InBag(bag, dest, pProto, count, true, false, pItem, NULL_BAG, slot);
                if (res != EQUIP_ERR_OK)
                    res = CanStoreItem_InBag(bag, dest, pProto, count, true, true, pItem, NULL_BAG, slot);

                if (res != EQUIP_ERR_OK)
                {
                    if (no_space_count)
                        *no_space_count = count + no_similar_count;
                    return res;
                }

                if (count == 0)
                {
                    if (no_similar_count == 0)
                        return EQUIP_ERR_OK;

                    if (no_space_count)
                        *no_space_count = count + no_similar_count;
                    return EQUIP_ERR_ITEM_MAX_COUNT;
                }
            }
        }

        // search free slot in bag for place to
        if (bag == INVENTORY_SLOT_BAG_0)                     // inventory
        {
            res = CanStoreItem_InInventorySlots(INVENTORY_SLOT_ITEM_START, INVENTORY_SLOT_ITEM_END, dest, pProto, count, false, pItem, bag, slot);
            if (res != EQUIP_ERR_OK)
            {
                if (no_space_count)
                    *no_space_count = count + no_similar_count;
                return res;
            }

            if (count == 0)
            {
                if (no_similar_count == 0)
                    return EQUIP_ERR_OK;

                if (no_space_count)
                    *no_space_count = count + no_similar_count;
                return EQUIP_ERR_ITEM_MAX_COUNT;
            }
        }
        else                                                // equipped bag
        {
            res = CanStoreItem_InBag(bag, dest, pProto, count, false, false, pItem, NULL_BAG, slot);
            if (res != EQUIP_ERR_OK)
                res = CanStoreItem_InBag(bag, dest, pProto, count, false, true, pItem, NULL_BAG, slot);

            if (res != EQUIP_ERR_OK)
            {
                if (no_space_count)
                    *no_space_count = count + no_similar_count;
                return res;
            }

            if (count == 0)
            {
                if (no_similar_count == 0)
                    return EQUIP_ERR_OK;

                if (no_space_count)
                    *no_space_count = count + no_similar_count;
                return EQUIP_ERR_ITEM_MAX_COUNT;
            }
        }
    }

    // not specific bag or have space for partly store only in specific bag

    // search stack for merge to
    if (pProto->GetMaxStackSize() != 1)
    {
        res = CanStoreItem_InInventorySlots(INVENTORY_SLOT_ITEM_START, INVENTORY_SLOT_ITEM_END, dest, pProto, count, true, pItem, bag, slot);
        if (res != EQUIP_ERR_OK)
        {
            if (no_space_count)
                *no_space_count = count + no_similar_count;
            return res;
        }

        if (count == 0)
        {
            if (no_similar_count == 0)
                return EQUIP_ERR_OK;

            if (no_space_count)
                *no_space_count = count + no_similar_count;
            return EQUIP_ERR_ITEM_MAX_COUNT;
        }

        if (pProto->GetBagFamily())
        {
            for (uint32 i = INVENTORY_SLOT_BAG_START; i < INVENTORY_SLOT_BAG_END; i++)
            {
                res = CanStoreItem_InBag(i, dest, pProto, count, true, false, pItem, bag, slot);
                if (res != EQUIP_ERR_OK)
                    continue;

                if (count == 0)
                {
                    if (no_similar_count == 0)
                        return EQUIP_ERR_OK;

                    if (no_space_count)
                        *no_space_count = count + no_similar_count;
                    return EQUIP_ERR_ITEM_MAX_COUNT;
                }
            }
        }

        for (uint32 i = INVENTORY_SLOT_BAG_START; i < INVENTORY_SLOT_BAG_END; i++)
        {
            res = CanStoreItem_InBag(i, dest, pProto, count, true, true, pItem, bag, slot);
            if (res != EQUIP_ERR_OK)
                continue;

            if (count == 0)
            {
                if (no_similar_count == 0)
                    return EQUIP_ERR_OK;

                if (no_space_count)
                    *no_space_count = count + no_similar_count;
                return EQUIP_ERR_ITEM_MAX_COUNT;
            }
        }
    }

    // search free slot - special bag case
    if (pProto->GetBagFamily())
    {
        for (uint32 i = INVENTORY_SLOT_BAG_START; i < INVENTORY_SLOT_BAG_END; i++)
        {
            res = CanStoreItem_InBag(i, dest, pProto, count, false, false, pItem, bag, slot);
            if (res != EQUIP_ERR_OK)
                continue;

            if (count == 0)
            {
                if (no_similar_count == 0)
                    return EQUIP_ERR_OK;

                if (no_space_count)
                    *no_space_count = count + no_similar_count;
                return EQUIP_ERR_ITEM_MAX_COUNT;
            }
        }
    }

    if (pItem && pItem->IsNotEmptyBag())
        return EQUIP_ERR_BAG_IN_BAG;

    // search free slot
    res = CanStoreItem_InInventorySlots(INVENTORY_SLOT_ITEM_START, INVENTORY_SLOT_ITEM_END, dest, pProto, count, false, pItem, bag, slot);
    if (res != EQUIP_ERR_OK)
    {
        if (no_space_count)
            *no_space_count = count + no_similar_count;
        return res;
    }

    if (count == 0)
    {
        if (no_similar_count == 0)
            return EQUIP_ERR_OK;

        if (no_space_count)
            *no_space_count = count + no_similar_count;
        return EQUIP_ERR_ITEM_MAX_COUNT;
    }

    for (uint8 i = INVENTORY_SLOT_BAG_START; i < INVENTORY_SLOT_BAG_END; i++)
    {
        res = CanStoreItem_InBag(i, dest, pProto, count, false, true, pItem, bag, slot);
        if (res != EQUIP_ERR_OK)
            continue;

        if (count == 0)
        {
            if (no_similar_count == 0)
                return EQUIP_ERR_OK;

            if (no_space_count)
                *no_space_count = count + no_similar_count;
            return EQUIP_ERR_ITEM_MAX_COUNT;
        }
    }

    if (no_space_count)
        *no_space_count = count + no_similar_count;

    return EQUIP_ERR_INV_FULL;
}

//////////////////////////////////////////////////////////////////////////
InventoryResult Player::CanStoreItems(Item** items, int count, uint32* offendingItemId) const
{
    Item* item2;

    // fill space table
    uint32 inventoryCounts[INVENTORY_SLOT_ITEM_END - INVENTORY_SLOT_ITEM_START];
    uint32 bagCounts[INVENTORY_SLOT_BAG_END - INVENTORY_SLOT_BAG_START][MAX_BAG_SIZE];

    memset(inventoryCounts, 0, sizeof(uint32) * (INVENTORY_SLOT_ITEM_END - INVENTORY_SLOT_ITEM_START));
    memset(bagCounts, 0, sizeof(uint32) * (INVENTORY_SLOT_BAG_END - INVENTORY_SLOT_BAG_START) * MAX_BAG_SIZE);

    for (uint8 i = INVENTORY_SLOT_ITEM_START; i < INVENTORY_SLOT_ITEM_END; i++)
    {
        item2 = GetItemByPos(INVENTORY_SLOT_BAG_0, i);
        if (item2 && !item2->IsInTrade())
            inventoryCounts[i - INVENTORY_SLOT_ITEM_START] = item2->GetCount();
    }

    for (uint8 i = INVENTORY_SLOT_BAG_START; i < INVENTORY_SLOT_BAG_END; i++)
        if (Bag* pBag = GetBagByPos(i))
            for (uint32 j = 0; j < pBag->GetBagSize(); j++)
            {
                item2 = GetItemByPos(i, j);
                if (item2 && !item2->IsInTrade())
                    bagCounts[i - INVENTORY_SLOT_BAG_START][j] = item2->GetCount();
            }

    // check free space for all items
    for (int k = 0; k < count; ++k)
    {
        Item* item = items[k];

        // no item
        if (!item)
            continue;

        TC_LOG_DEBUG("entities.player.items", "Player::CanStoreItems: Player '%s' (%s), Index: %i ItemID: %u, Count: %u",
            GetName().c_str(), GetGUID().ToString().c_str(), k + 1, item->GetEntry(), item->GetCount());
        ItemTemplate const* pProto = item->GetTemplate();

        // strange item
        if (!pProto)
            return EQUIP_ERR_ITEM_NOT_FOUND;

        // item used
        if (item->m_lootGenerated)
            return EQUIP_ERR_LOOT_GONE;

        // item it 'bind'
        if (item->IsBindedNotWith(this))
            return EQUIP_ERR_NOT_OWNER;

        ItemTemplate const* pBagProto;

        // item is 'one item only'
        InventoryResult res = CanTakeMoreSimilarItems(item, offendingItemId);
        if (res != EQUIP_ERR_OK)
            return res;

        // search stack for merge to
        if (pProto->GetMaxStackSize() != 1)
        {
            bool b_found = false;

            for (int t = INVENTORY_SLOT_ITEM_START; t < INVENTORY_SLOT_ITEM_END; ++t)
            {
                item2 = GetItemByPos(INVENTORY_SLOT_BAG_0, t);
                if (item2 && item2->CanBeMergedPartlyWith(pProto) == EQUIP_ERR_OK && inventoryCounts[t-INVENTORY_SLOT_ITEM_START] + item->GetCount() <= pProto->GetMaxStackSize())
                {
                    inventoryCounts[t-INVENTORY_SLOT_ITEM_START] += item->GetCount();
                    b_found = true;
                    break;
                }
            }
            if (b_found)
                continue;

            for (int t = INVENTORY_SLOT_BAG_START; !b_found && t < INVENTORY_SLOT_BAG_END; ++t)
            {
                if (Bag* bag = GetBagByPos(t))
                {
                    if (ItemCanGoIntoBag(item->GetTemplate(), bag->GetTemplate()))
                    {
                        for (uint32 j = 0; j < bag->GetBagSize(); j++)
                        {
                            item2 = GetItemByPos(t, j);
                            if (item2 && item2->CanBeMergedPartlyWith(pProto) == EQUIP_ERR_OK && bagCounts[t-INVENTORY_SLOT_BAG_START][j] + item->GetCount() <= pProto->GetMaxStackSize())
                            {
                                bagCounts[t-INVENTORY_SLOT_BAG_START][j] += item->GetCount();
                                b_found = true;
                                break;
                            }
                        }
                    }
                }
            }
            if (b_found)
                continue;
        }

        // special bag case
        if (pProto->GetBagFamily())
        {
            bool b_found = false;

            for (int t = INVENTORY_SLOT_BAG_START; !b_found && t < INVENTORY_SLOT_BAG_END; ++t)
            {
                if (Bag* bag = GetBagByPos(t))
                {
                    pBagProto = bag->GetTemplate();

                    // not plain container check
                    if (pBagProto && (pBagProto->GetClass() != ITEM_CLASS_CONTAINER || pBagProto->GetSubClass() != ITEM_SUBCLASS_CONTAINER) &&
                        ItemCanGoIntoBag(pProto, pBagProto))
                    {
                        for (uint32 j = 0; j < bag->GetBagSize(); j++)
                        {
                            if (bagCounts[t-INVENTORY_SLOT_BAG_START][j] == 0)
                            {
                                bagCounts[t-INVENTORY_SLOT_BAG_START][j] = 1;
                                b_found = true;
                                break;
                            }
                        }
                    }
                }
            }
            if (b_found)
                continue;
        }

        // search free slot
        bool b_found = false;
        for (int t = INVENTORY_SLOT_ITEM_START; t < INVENTORY_SLOT_ITEM_END; ++t)
        {
            if (inventoryCounts[t-INVENTORY_SLOT_ITEM_START] == 0)
            {
                inventoryCounts[t-INVENTORY_SLOT_ITEM_START] = 1;
                b_found = true;
                break;
            }
        }
        if (b_found)
            continue;

        // search free slot in bags
        for (int t = INVENTORY_SLOT_BAG_START; !b_found && t < INVENTORY_SLOT_BAG_END; ++t)
        {
            if (Bag* bag = GetBagByPos(t))
            {
                pBagProto = bag->GetTemplate();

                // special bag already checked
                if (pBagProto && (pBagProto->GetClass() != ITEM_CLASS_CONTAINER || pBagProto->GetSubClass() != ITEM_SUBCLASS_CONTAINER))
                    continue;

                for (uint32 j = 0; j < bag->GetBagSize(); j++)
                {
                    if (bagCounts[t - INVENTORY_SLOT_BAG_START][j] == 0)
                    {
                        bagCounts[t - INVENTORY_SLOT_BAG_START][j] = 1;
                        b_found = true;
                        break;
                    }
                }
            }
        }

        // no free slot found?
        if (!b_found)
            return EQUIP_ERR_BAG_FULL;
    }

    return EQUIP_ERR_OK;
}

//////////////////////////////////////////////////////////////////////////
InventoryResult Player::CanEquipNewItem(uint8 slot, uint16 &dest, uint32 item, bool swap) const
{
    dest = 0;
    Item* pItem = Item::CreateItem(item, 1, this);
    if (pItem)
    {
        InventoryResult result = CanEquipItem(slot, dest, pItem, swap);
        delete pItem;
        return result;
    }

    return EQUIP_ERR_ITEM_NOT_FOUND;
}

InventoryResult Player::CanEquipItem(uint8 slot, uint16 &dest, Item* pItem, bool swap, bool not_loading) const
{
    dest = 0;
    if (pItem)
    {
        TC_LOG_DEBUG("entities.player.items", "Player::CanEquipItem: Player '%s' (%s), Slot: %u, Item: %u, Count: %u",
            GetName().c_str(), GetGUID().ToString().c_str(), slot, pItem->GetEntry(), pItem->GetCount());
        ItemTemplate const* pProto = pItem->GetTemplate();
        if (pProto)
        {
            // item used
            if (pItem->m_lootGenerated)
                return EQUIP_ERR_LOOT_GONE;

            if (pItem->IsBindedNotWith(this))
                return EQUIP_ERR_NOT_OWNER;

            // check count of items (skip for auto move for same player from bank)
            InventoryResult res = CanTakeMoreSimilarItems(pItem);
            if (res != EQUIP_ERR_OK)
                return res;

            // check this only in game
            if (not_loading)
            {
                // May be here should be more stronger checks; STUNNED checked
                // ROOT, CONFUSED, DISTRACTED, FLEEING this needs to be checked.
                if (HasUnitState(UNIT_STATE_STUNNED))
                    return EQUIP_ERR_GENERIC_STUNNED;

                // do not allow equipping gear except weapons, offhands, projectiles, relics in
                // - combat
                // - in-progress arenas
                if (!pProto->CanChangeEquipStateInCombat())
                {
                    if (IsInCombat())
                        return EQUIP_ERR_NOT_IN_COMBAT;

                    if (Battleground* bg = GetBattleground())
                        if (bg->isArena() && bg->GetStatus() == STATUS_IN_PROGRESS)
                            return EQUIP_ERR_NOT_DURING_ARENA_MATCH;
                }

                if (IsInCombat() && (pProto->GetClass() == ITEM_CLASS_WEAPON || pProto->GetInventoryType() == INVTYPE_RELIC) && m_weaponChangeTimer != 0)
                    return EQUIP_ERR_CLIENT_LOCKED_OUT;         // maybe exist better err

                if (IsNonMeleeSpellCast(false))
                    return EQUIP_ERR_CLIENT_LOCKED_OUT;
            }

            ScalingStatDistributionEntry const* ssd = pItem->GetScalingStatDistribution() ? sScalingStatDistributionStore.LookupEntry(pItem->GetScalingStatDistribution()) : 0;
            // check allowed level (extend range to upper values if MaxLevel more or equal max player level, this let GM set high level with 1...max range items)
            if (ssd && ssd->MaxLevel < DEFAULT_MAX_LEVEL && ssd->MaxLevel < getLevel() && !sDB2Manager.GetHeirloomByItemId(pProto->GetId()))
                return EQUIP_ERR_NOT_EQUIPPABLE;

            uint8 eslot = FindEquipSlot(pProto, slot, swap);
            if (eslot == NULL_SLOT)
                return EQUIP_ERR_NOT_EQUIPPABLE;

            res = CanUseItem(pItem, not_loading);
            if (res != EQUIP_ERR_OK)
                return res;

            if (!swap && GetItemByPos(INVENTORY_SLOT_BAG_0, eslot))
                return EQUIP_ERR_NO_SLOT_AVAILABLE;

            // if we are swapping 2 equiped items, CanEquipUniqueItem check
            // should ignore the item we are trying to swap, and not the
            // destination item. CanEquipUniqueItem should ignore destination
            // item only when we are swapping weapon from bag
            uint8 ignore = uint8(NULL_SLOT);
            switch (eslot)
            {
                case EQUIPMENT_SLOT_MAINHAND:
                    ignore = EQUIPMENT_SLOT_OFFHAND;
                    break;
                case EQUIPMENT_SLOT_OFFHAND:
                    ignore = EQUIPMENT_SLOT_MAINHAND;
                    break;
                case EQUIPMENT_SLOT_FINGER1:
                    ignore = EQUIPMENT_SLOT_FINGER2;
                    break;
                case EQUIPMENT_SLOT_FINGER2:
                    ignore = EQUIPMENT_SLOT_FINGER1;
                    break;
                case EQUIPMENT_SLOT_TRINKET1:
                    ignore = EQUIPMENT_SLOT_TRINKET2;
                    break;
                case EQUIPMENT_SLOT_TRINKET2:
                    ignore = EQUIPMENT_SLOT_TRINKET1;
                    break;
            }

            if (ignore == uint8(NULL_SLOT) || pItem != GetItemByPos(INVENTORY_SLOT_BAG_0, ignore))
                ignore = eslot;

            InventoryResult res2 = CanEquipUniqueItem(pItem, swap ? ignore : uint8(NULL_SLOT));
            if (res2 != EQUIP_ERR_OK)
                return res2;

            // check unique-equipped special item classes
            if (pProto->GetClass() == ITEM_CLASS_QUIVER)
                for (uint8 i = INVENTORY_SLOT_BAG_START; i < INVENTORY_SLOT_BAG_END; ++i)
                    if (Item* pBag = GetItemByPos(INVENTORY_SLOT_BAG_0, i))
                        if (pBag != pItem)
                            if (ItemTemplate const* pBagProto = pBag->GetTemplate())
                                if (pBagProto->GetClass() == pProto->GetClass() && (!swap || pBag->GetSlot() != eslot))
                                    return (pBagProto->GetSubClass() == ITEM_SUBCLASS_AMMO_POUCH)
                                        ? EQUIP_ERR_ONLY_ONE_AMMO
                                        : EQUIP_ERR_ONLY_ONE_QUIVER;

            uint32 type = pProto->GetInventoryType();

            if (eslot == EQUIPMENT_SLOT_OFFHAND)
            {
                // Do not allow polearm to be equipped in the offhand (rare case for the only 1h polearm 41750)
                if (type == INVTYPE_WEAPON && pProto->GetSubClass() == ITEM_SUBCLASS_WEAPON_POLEARM)
                    return EQUIP_ERR_2HSKILLNOTFOUND;
                else if (type == INVTYPE_WEAPON || type == INVTYPE_WEAPONOFFHAND)
                {
                    if (!CanDualWield())
                        return EQUIP_ERR_2HSKILLNOTFOUND;
                }
                else if (type == INVTYPE_2HWEAPON)
                {
                    if (!CanDualWield() || !CanTitanGrip())
                        return EQUIP_ERR_2HSKILLNOTFOUND;
                }

                if (IsTwoHandUsed())
                    return EQUIP_ERR_2HANDED_EQUIPPED;
            }

            // equip two-hand weapon case (with possible unequip 2 items)
            if (type == INVTYPE_2HWEAPON)
            {
                if (eslot == EQUIPMENT_SLOT_OFFHAND)
                {
                    if (!CanTitanGrip())
                        return EQUIP_ERR_NOT_EQUIPPABLE;
                }
                else if (eslot != EQUIPMENT_SLOT_MAINHAND)
                    return EQUIP_ERR_NOT_EQUIPPABLE;

                if (!CanTitanGrip())
                {
                    // offhand item must can be stored in inventory for offhand item and it also must be unequipped
                    Item* offItem = GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND);
                    ItemPosCountVec off_dest;
                    if (offItem && (!not_loading ||
                        CanUnequipItem(uint16(INVENTORY_SLOT_BAG_0) << 8 | EQUIPMENT_SLOT_OFFHAND, false) != EQUIP_ERR_OK ||
                        CanStoreItem(NULL_BAG, NULL_SLOT, off_dest, offItem, false) != EQUIP_ERR_OK))
                        return swap ? EQUIP_ERR_CANT_SWAP : EQUIP_ERR_INV_FULL;
                }
            }
            dest = ((INVENTORY_SLOT_BAG_0 << 8) | eslot);
            return EQUIP_ERR_OK;
        }
    }

    return !swap ? EQUIP_ERR_ITEM_NOT_FOUND : EQUIP_ERR_CANT_SWAP;
}

InventoryResult Player::CanUnequipItem(uint16 pos, bool swap) const
{
    // Applied only to equipped items and bank bags
    if (!IsEquipmentPos(pos) && !IsBagPos(pos))
        return EQUIP_ERR_OK;

    Item* pItem = GetItemByPos(pos);

    // Applied only to existed equipped item
    if (!pItem)
        return EQUIP_ERR_OK;

    TC_LOG_DEBUG("entities.player.items", "Player::CanUnequipItem: Player '%s' (%s), Slot: %u, Item: %u, Count: %u",
        GetName().c_str(), GetGUID().ToString().c_str(), pos, pItem->GetEntry(), pItem->GetCount());

    ItemTemplate const* pProto = pItem->GetTemplate();
    if (!pProto)
        return EQUIP_ERR_ITEM_NOT_FOUND;

    // item used
    if (pItem->m_lootGenerated)
        return EQUIP_ERR_LOOT_GONE;

    // do not allow unequipping gear except weapons, offhands, projectiles, relics in
    // - combat
    // - in-progress arenas
    if (!pProto->CanChangeEquipStateInCombat())
    {
        if (IsInCombat())
            return EQUIP_ERR_NOT_IN_COMBAT;

        if (Battleground* bg = GetBattleground())
            if (bg->isArena() && bg->GetStatus() == STATUS_IN_PROGRESS)
                return EQUIP_ERR_NOT_DURING_ARENA_MATCH;
    }

    if (!swap && pItem->IsNotEmptyBag())
        return EQUIP_ERR_DESTROY_NONEMPTY_BAG;

    return EQUIP_ERR_OK;
}

InventoryResult Player::CanBankItem(uint8 bag, uint8 slot, ItemPosCountVec &dest, Item* pItem, bool swap, bool not_loading) const
{
    if (!pItem)
        return swap ? EQUIP_ERR_CANT_SWAP : EQUIP_ERR_ITEM_NOT_FOUND;

    uint32 count = pItem->GetCount();

    TC_LOG_DEBUG("entities.player.items", "Player::CanBankItem: Player '%s' (%s), Bag: %u, Slot: %u, Item: %u, Count: %u",
        GetName().c_str(), GetGUID().ToString().c_str(), bag, slot, pItem->GetEntry(), pItem->GetCount());
    ItemTemplate const* pProto = pItem->GetTemplate();
    if (!pProto)
        return swap ? EQUIP_ERR_CANT_SWAP : EQUIP_ERR_ITEM_NOT_FOUND;

    // item used
    if (pItem->m_lootGenerated)
        return EQUIP_ERR_LOOT_GONE;

    if (pItem->IsBindedNotWith(this))
        return EQUIP_ERR_NOT_OWNER;

    // Currency Tokenizer are not supposed to be swapped out of their hidden bag
    if (pItem->IsCurrencyToken())
    {
        TC_LOG_ERROR("entities.player", "Possible hacking attempt: Player %s (%s) tried to move token [%s entry: %u] out of the currency bag!",
            GetName().c_str(), GetGUID().ToString().c_str(), pItem->GetGUID().ToString().c_str(), pProto->GetId());
        return EQUIP_ERR_CANT_SWAP;
    }

    // check count of items (skip for auto move for same player from bank)
    InventoryResult res = CanTakeMoreSimilarItems(pItem);
    if (res != EQUIP_ERR_OK)
        return res;

    // in specific slot
    if (bag != NULL_BAG && slot != NULL_SLOT)
    {
        if (slot >= BANK_SLOT_BAG_START && slot < BANK_SLOT_BAG_END)
        {
            if (!pItem->IsBag())
                return EQUIP_ERR_WRONG_SLOT;

            if (slot - BANK_SLOT_BAG_START >= GetBankBagSlotCount())
                return EQUIP_ERR_NO_BANK_SLOT;

            res = CanUseItem(pItem, not_loading);
            if (res != EQUIP_ERR_OK)
                return res;
        }

        res = CanStoreItem_InSpecificSlot(bag, slot, dest, pProto, count, swap, pItem);
        if (res != EQUIP_ERR_OK)
            return res;

        if (count == 0)
            return EQUIP_ERR_OK;
    }

    // not specific slot or have space for partly store only in specific slot

    // in specific bag
    if (bag != NULL_BAG)
    {
        if (pItem->IsNotEmptyBag())
            return EQUIP_ERR_BAG_IN_BAG;

        // search stack in bag for merge to
        if (pProto->GetMaxStackSize() != 1)
        {
            if (bag == INVENTORY_SLOT_BAG_0)
            {
                res = CanStoreItem_InInventorySlots(BANK_SLOT_ITEM_START, BANK_SLOT_ITEM_END, dest, pProto, count, true, pItem, bag, slot);
                if (res != EQUIP_ERR_OK)
                    return res;

                if (count == 0)
                    return EQUIP_ERR_OK;
            }
            else
            {
                res = CanStoreItem_InBag(bag, dest, pProto, count, true, false, pItem, NULL_BAG, slot);
                if (res != EQUIP_ERR_OK)
                    res = CanStoreItem_InBag(bag, dest, pProto, count, true, true, pItem, NULL_BAG, slot);

                if (res != EQUIP_ERR_OK)
                    return res;

                if (count == 0)
                    return EQUIP_ERR_OK;
            }
        }

        // search free slot in bag
        if (bag == INVENTORY_SLOT_BAG_0)
        {
            res = CanStoreItem_InInventorySlots(BANK_SLOT_ITEM_START, BANK_SLOT_ITEM_END, dest, pProto, count, false, pItem, bag, slot);
            if (res != EQUIP_ERR_OK)
                return res;

            if (count == 0)
                return EQUIP_ERR_OK;
        }
        else
        {
            res = CanStoreItem_InBag(bag, dest, pProto, count, false, false, pItem, NULL_BAG, slot);
            if (res != EQUIP_ERR_OK)
                res = CanStoreItem_InBag(bag, dest, pProto, count, false, true, pItem, NULL_BAG, slot);

            if (res != EQUIP_ERR_OK)
                return res;

            if (count == 0)
                return EQUIP_ERR_OK;
        }
    }

    // not specific bag or have space for partly store only in specific bag

    // search stack for merge to
    if (pProto->GetMaxStackSize() != 1)
    {
        // in slots
        res = CanStoreItem_InInventorySlots(BANK_SLOT_ITEM_START, BANK_SLOT_ITEM_END, dest, pProto, count, true, pItem, bag, slot);
        if (res != EQUIP_ERR_OK)
            return res;

        if (count == 0)
            return EQUIP_ERR_OK;

        // in special bags
        if (pProto->GetBagFamily())
        {
            for (uint8 i = BANK_SLOT_BAG_START; i < BANK_SLOT_BAG_END; i++)
            {
                res = CanStoreItem_InBag(i, dest, pProto, count, true, false, pItem, bag, slot);
                if (res != EQUIP_ERR_OK)
                    continue;

                if (count == 0)
                    return EQUIP_ERR_OK;
            }
        }

        for (uint8 i = BANK_SLOT_BAG_START; i < BANK_SLOT_BAG_END; i++)
        {
            res = CanStoreItem_InBag(i, dest, pProto, count, true, true, pItem, bag, slot);
            if (res != EQUIP_ERR_OK)
                continue;

            if (count == 0)
                return EQUIP_ERR_OK;
        }
    }

    // search free place in special bag
    if (pProto->GetBagFamily())
    {
        for (uint8 i = BANK_SLOT_BAG_START; i < BANK_SLOT_BAG_END; i++)
        {
            res = CanStoreItem_InBag(i, dest, pProto, count, false, false, pItem, bag, slot);
            if (res != EQUIP_ERR_OK)
                continue;

            if (count == 0)
                return EQUIP_ERR_OK;
        }
    }

    // search free space
    res = CanStoreItem_InInventorySlots(BANK_SLOT_ITEM_START, BANK_SLOT_ITEM_END, dest, pProto, count, false, pItem, bag, slot);
    if (res != EQUIP_ERR_OK)
        return res;

    if (count == 0)
        return EQUIP_ERR_OK;

    for (uint8 i = BANK_SLOT_BAG_START; i < BANK_SLOT_BAG_END; i++)
    {
        res = CanStoreItem_InBag(i, dest, pProto, count, false, true, pItem, bag, slot);
        if (res != EQUIP_ERR_OK)
            continue;

        if (count == 0)
            return EQUIP_ERR_OK;
    }
    return EQUIP_ERR_BANK_FULL;
}

InventoryResult Player::CanUseItem(Item* pItem, bool not_loading) const
{
    if (pItem)
    {
        TC_LOG_DEBUG("entities.player.items", "Player::CanUseItem: Player '%s' (%s),  Item: %u",
            GetName().c_str(), GetGUID().ToString().c_str(), pItem->GetEntry());

        if (!IsAlive() && not_loading)
            return EQUIP_ERR_PLAYER_DEAD;

        //if (isStunned())
        //    return EQUIP_ERR_GENERIC_STUNNED;

        ItemTemplate const* pProto = pItem->GetTemplate();
        if (pProto)
        {
            if (pItem->IsBindedNotWith(this))
                return EQUIP_ERR_NOT_OWNER;

            InventoryResult res = CanUseItem(pProto);
            if (res != EQUIP_ERR_OK)
                return res;

            if (pItem->GetSkill() != 0)
            {
                bool allowEquip = false;
                uint32 itemSkill = pItem->GetSkill();
                // Armor that is binded to account can "morph" from plate to mail, etc. if skill is not learned yet.
                if (pProto->GetQuality() == ITEM_QUALITY_HEIRLOOM && pProto->GetClass() == ITEM_CLASS_ARMOR && !HasSkill(itemSkill))
                {
                    /// @todo when you right-click already equipped item it throws EQUIP_ERR_PROFICIENCY_NEEDED.
                    // In fact it's a visual bug, everything works properly... I need sniffs of operations with
                    // binded to account items from off server.

                    switch (getClass())
                    {
                        case CLASS_HUNTER:
                        case CLASS_SHAMAN:
                            allowEquip = (itemSkill == SKILL_MAIL);
                            break;
                        case CLASS_PALADIN:
                        case CLASS_WARRIOR:
                            allowEquip = (itemSkill == SKILL_PLATE_MAIL);
                            break;
                    }
                }
                if (!allowEquip && GetSkillValue(itemSkill) == 0)
                    return EQUIP_ERR_PROFICIENCY_NEEDED;
            }

            if (pProto->GetRequiredReputationFaction() && uint32(GetReputationRank(pProto->GetRequiredReputationFaction())) < pProto->GetRequiredReputationRank())
                return EQUIP_ERR_CANT_EQUIP_REPUTATION;

            return EQUIP_ERR_OK;
        }
    }
    return EQUIP_ERR_ITEM_NOT_FOUND;
}

InventoryResult Player::CanUseItem(ItemTemplate const* proto) const
{
    // Used by group, function NeedBeforeGreed, to know if a prototype can be used by a player

    if (!proto)
        return EQUIP_ERR_ITEM_NOT_FOUND;

    if ((proto->GetFlags2() & ITEM_FLAG2_HORDE_ONLY) && GetTeam() != HORDE)
        return EQUIP_ERR_CANT_EQUIP_EVER;

    if ((proto->GetFlags2() & ITEM_FLAG2_ALLIANCE_ONLY) && GetTeam() != ALLIANCE)
        return EQUIP_ERR_CANT_EQUIP_EVER;

    if ((proto->GetAllowableClass() & getClassMask()) == 0 || (proto->GetAllowableRace() & getRaceMask()) == 0)
        return EQUIP_ERR_CANT_EQUIP_EVER;

    if (proto->GetRequiredSkill() != 0)
    {
        if (GetSkillValue(proto->GetRequiredSkill()) == 0)
            return EQUIP_ERR_PROFICIENCY_NEEDED;
        else if (GetSkillValue(proto->GetRequiredSkill()) < proto->GetRequiredSkillRank())
            return EQUIP_ERR_CANT_EQUIP_SKILL;
    }

    if (proto->GetRequiredSpell() != 0 && !HasSpell(proto->GetRequiredSpell()))
        return EQUIP_ERR_PROFICIENCY_NEEDED;

    if (getLevel() < proto->GetBaseRequiredLevel())
        return EQUIP_ERR_CANT_EQUIP_LEVEL_I;

    // If World Event is not active, prevent using event dependant items
    if (proto->GetHolidayID() && !IsHolidayActive(proto->GetHolidayID()))
        return EQUIP_ERR_CLIENT_LOCKED_OUT;

    // learning (recipes, mounts, pets, etc.)
    if (proto->Effects.size() >= 2)
        if (proto->Effects[0]->SpellID == 483 || proto->Effects[0]->SpellID == 55884)
            if (HasSpell(proto->Effects[1]->SpellID))
                return EQUIP_ERR_INTERNAL_BAG_ERROR;

    return EQUIP_ERR_OK;
}

InventoryResult Player::CanRollForItemInLFG(ItemTemplate const* proto, WorldObject const* lootedObject) const
{
    if (!GetGroup() || !GetGroup()->isLFGGroup())
        return EQUIP_ERR_OK;    // not in LFG group

    // check if looted object is inside the lfg dungeon
    Map const* map = lootedObject->GetMap();
    if (!sLFGMgr->inLfgDungeonMap(GetGroup()->GetGUID(), map->GetId(), map->GetDifficultyID()))
        return EQUIP_ERR_OK;

    if (!proto)
        return EQUIP_ERR_ITEM_NOT_FOUND;
   // Used by group, function NeedBeforeGreed, to know if a prototype can be used by a player

    const static uint32 item_weapon_skills[MAX_ITEM_SUBCLASS_WEAPON] =
    {
        SKILL_AXES,     SKILL_2H_AXES,  SKILL_BOWS,          SKILL_GUNS,      SKILL_MACES,
        SKILL_2H_MACES, SKILL_POLEARMS, SKILL_SWORDS,        SKILL_2H_SWORDS, 0,
        SKILL_STAVES,   0,              0,                   SKILL_FIST_WEAPONS,   0,
        SKILL_DAGGERS,  SKILL_THROWN,   SKILL_ASSASSINATION, SKILL_CROSSBOWS, SKILL_WANDS,
        SKILL_FISHING
    }; //Copy from function Item::GetSkill()

    if ((proto->GetAllowableClass() & getClassMask()) == 0 || (proto->GetAllowableRace() & getRaceMask()) == 0)
        return EQUIP_ERR_CANT_EQUIP_EVER;

    if (proto->GetRequiredSpell() != 0 && !HasSpell(proto->GetRequiredSpell()))
        return EQUIP_ERR_PROFICIENCY_NEEDED;

    if (proto->GetRequiredSkill() != 0)
    {
        if (!GetSkillValue(proto->GetRequiredSkill()))
            return EQUIP_ERR_PROFICIENCY_NEEDED;
        else if (GetSkillValue(proto->GetRequiredSkill()) < proto->GetRequiredSkillRank())
            return EQUIP_ERR_CANT_EQUIP_SKILL;
    }

    uint8 _class = getClass();

    if (proto->GetClass() == ITEM_CLASS_WEAPON && GetSkillValue(item_weapon_skills[proto->GetSubClass()]) == 0)
        return EQUIP_ERR_PROFICIENCY_NEEDED;

    if (proto->GetClass() == ITEM_CLASS_ARMOR && proto->GetSubClass() > ITEM_SUBCLASS_ARMOR_MISCELLANEOUS && proto->GetSubClass() < ITEM_SUBCLASS_ARMOR_BUCKLER && proto->GetInventoryType() != INVTYPE_CLOAK)
    {
        if (_class == CLASS_WARRIOR || _class == CLASS_PALADIN || _class == CLASS_DEATH_KNIGHT)
        {
            if (getLevel() < 40)
            {
                if (proto->GetSubClass() != ITEM_SUBCLASS_ARMOR_MAIL)
                    return EQUIP_ERR_CLIENT_LOCKED_OUT;
            }
            else if (proto->GetSubClass() != ITEM_SUBCLASS_ARMOR_PLATE)
                return EQUIP_ERR_CLIENT_LOCKED_OUT;
        }
        else if (_class == CLASS_HUNTER || _class == CLASS_SHAMAN)
        {
            if (getLevel() < 40)
            {
                if (proto->GetSubClass() != ITEM_SUBCLASS_ARMOR_LEATHER)
                    return EQUIP_ERR_CLIENT_LOCKED_OUT;
            }
            else if (proto->GetSubClass() != ITEM_SUBCLASS_ARMOR_MAIL)
                return EQUIP_ERR_CLIENT_LOCKED_OUT;
        }

        if (_class == CLASS_ROGUE || _class == CLASS_DRUID)
            if (proto->GetSubClass() != ITEM_SUBCLASS_ARMOR_LEATHER)
                return EQUIP_ERR_CLIENT_LOCKED_OUT;

        if (_class == CLASS_MAGE || _class == CLASS_PRIEST || _class == CLASS_WARLOCK)
            if (proto->GetSubClass() != ITEM_SUBCLASS_ARMOR_CLOTH)
                return EQUIP_ERR_CLIENT_LOCKED_OUT;
    }

    return EQUIP_ERR_OK;
}

// Return stored item (if stored to stack, it can diff. from pItem). And pItem ca be deleted in this case.
Item* Player::StoreNewItem(ItemPosCountVec const& pos, uint32 itemId, bool update, int32 randomPropertyId /*= 0*/, GuidSet const& allowedLooters /*= GuidSet()*/, std::vector<int32> const& bonusListIDs /*= std::vector<int32>()*/)
{
    uint32 count = 0;
    for (ItemPosCountVec::const_iterator itr = pos.begin(); itr != pos.end(); ++itr)
        count += itr->count;

    Item* item = Item::CreateItem(itemId, count, this);
    if (item)
    {
        ItemAddedQuestCheck(itemId, count);
        UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_RECEIVE_EPIC_ITEM, itemId, count);
        UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_OWN_ITEM, itemId, 1);

        if (sDB2Manager.GetHeirloomByItemId(itemId))
            GetSession()->GetCollectionMgr()->AddHeirloom(itemId, 0);

        if (randomPropertyId)
            item->SetItemRandomProperties(randomPropertyId);

        for (int32 bonusListID : bonusListIDs)
            item->AddBonuses(bonusListID);

        item = StoreItem(pos, item, update);

        if (allowedLooters.size() > 1 && item->GetTemplate()->GetMaxStackSize() == 1 && item->IsSoulBound())
        {
            item->SetSoulboundTradeable(allowedLooters);
            item->SetUInt32Value(ITEM_FIELD_CREATE_PLAYED_TIME, GetTotalPlayedTime());
            AddTradeableItem(item);

            // save data
            std::ostringstream ss;
            GuidSet::const_iterator itr = allowedLooters.begin();
            ss << *itr;
            for (++itr; itr != allowedLooters.end(); ++itr)
                ss << ' ' << *itr;

            PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_ITEM_BOP_TRADE);
            stmt->setUInt64(0, item->GetGUID().GetCounter());
            stmt->setString(1, ss.str());
            CharacterDatabase.Execute(stmt);
        }
    }
    return item;
}

Item* Player::StoreItem(ItemPosCountVec const& dest, Item* pItem, bool update)
{
    if (!pItem)
        return nullptr;

    Item* lastItem = pItem;
    for (ItemPosCountVec::const_iterator itr = dest.begin(); itr != dest.end();)
    {
        uint16 pos = itr->pos;
        uint32 count = itr->count;

        ++itr;

        if (itr == dest.end())
        {
            lastItem = _StoreItem(pos, pItem, count, false, update);
            break;
        }

        lastItem = _StoreItem(pos, pItem, count, true, update);
    }
    return lastItem;
}

// Return stored item (if stored to stack, it can diff. from pItem). And pItem ca be deleted in this case.
Item* Player::_StoreItem(uint16 pos, Item* pItem, uint32 count, bool clone, bool update)
{
    if (!pItem)
        return nullptr;

    uint8 bag = pos >> 8;
    uint8 slot = pos & 255;

    TC_LOG_DEBUG("entities.player.items", "Player::_StoreItem: Player '%s' (%s), Bag: %u, Slot: %u, Item: %u (%s), Count: %u",
        GetName().c_str(), GetGUID().ToString().c_str(), bag, slot, pItem->GetEntry(), pItem->GetGUID().ToString().c_str(), count);

    Item* pItem2 = GetItemByPos(bag, slot);

    if (!pItem2)
    {
        if (clone)
            pItem = pItem->CloneItem(count, this);
        else
            pItem->SetCount(count);

        if (!pItem)
            return nullptr;

        if (pItem->GetTemplate()->GetBonding() == BIND_WHEN_PICKED_UP ||
            pItem->GetTemplate()->GetBonding() == BIND_QUEST_ITEM ||
            (pItem->GetTemplate()->GetBonding() == BIND_WHEN_EQUIPED && IsBagPos(pos)))
            pItem->SetBinding(true);

        Bag* pBag = (bag == INVENTORY_SLOT_BAG_0) ? NULL : GetBagByPos(bag);
        if (!pBag)
        {
            m_items[slot] = pItem;
            SetGuidValue(PLAYER_FIELD_INV_SLOT_HEAD + (slot * 4), pItem->GetGUID());
            pItem->SetGuidValue(ITEM_FIELD_CONTAINED, GetGUID());
            pItem->SetOwnerGUID(GetGUID());

            pItem->SetSlot(slot);
            pItem->SetContainer(nullptr);
        }
        else
            pBag->StoreItem(slot, pItem, update);

        if (IsInWorld() && update)
        {
            pItem->AddToWorld();
            pItem->SendUpdateToPlayer(this);
        }

        pItem->SetState(ITEM_CHANGED, this);
        if (pBag)
            pBag->SetState(ITEM_CHANGED, this);

        AddEnchantmentDurations(pItem);
        AddItemDurations(pItem);

        const ItemTemplate* proto = pItem->GetTemplate();
        for (uint8 i = 0; i < proto->Effects.size(); ++i)
            if (proto->Effects[i]->Trigger == ITEM_SPELLTRIGGER_ON_NO_DELAY_USE) // On obtain trigger
                if (bag == INVENTORY_SLOT_BAG_0 || (bag >= INVENTORY_SLOT_BAG_START && bag < INVENTORY_SLOT_BAG_END))
                    if (!HasAura(proto->Effects[i]->SpellID))
                        CastSpell(this, proto->Effects[i]->SpellID, true, pItem);

        return pItem;
    }
    else
    {
        if (pItem2->GetTemplate()->GetBonding() == BIND_WHEN_PICKED_UP ||
            pItem2->GetTemplate()->GetBonding() == BIND_QUEST_ITEM ||
            (pItem2->GetTemplate()->GetBonding() == BIND_WHEN_EQUIPED && IsBagPos(pos)))
            pItem2->SetBinding(true);

        pItem2->SetCount(pItem2->GetCount() + count);
        if (IsInWorld() && update)
            pItem2->SendUpdateToPlayer(this);

        if (!clone)
        {
            // delete item (it not in any slot currently)
            if (IsInWorld() && update)
            {
                pItem->RemoveFromWorld();
                pItem->DestroyForPlayer(this);
            }

            RemoveEnchantmentDurations(pItem);
            RemoveItemDurations(pItem);

            pItem->SetOwnerGUID(GetGUID());                 // prevent error at next SetState in case trade/mail/buy from vendor
            pItem->SetNotRefundable(this);
            pItem->ClearSoulboundTradeable(this);
            RemoveTradeableItem(pItem);
            pItem->SetState(ITEM_REMOVED, this);
        }

        AddEnchantmentDurations(pItem2);

        pItem2->SetState(ITEM_CHANGED, this);

        const ItemTemplate* proto = pItem2->GetTemplate();
        for (uint8 i = 0; i < proto->Effects.size(); ++i)
            if (proto->Effects[i]->Trigger == ITEM_SPELLTRIGGER_ON_NO_DELAY_USE) // On obtain trigger
                if (bag == INVENTORY_SLOT_BAG_0 || (bag >= INVENTORY_SLOT_BAG_START && bag < INVENTORY_SLOT_BAG_END))
                    if (!HasAura(proto->Effects[i]->SpellID))
                        CastSpell(this, proto->Effects[i]->SpellID, true, pItem2);

        return pItem2;
    }
}

Item* Player::EquipNewItem(uint16 pos, uint32 item, bool update)
{
    if (Item* pItem = Item::CreateItem(item, 1, this))
    {
        ItemAddedQuestCheck(item, 1);
        UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_RECEIVE_EPIC_ITEM, item, 1);
        return EquipItem(pos, pItem, update);
    }

    return nullptr;
}

Item* Player::EquipItem(uint16 pos, Item* pItem, bool update)
{
    AddEnchantmentDurations(pItem);
    AddItemDurations(pItem);

    uint8 bag = pos >> 8;
    uint8 slot = pos & 255;

    Item* pItem2 = GetItemByPos(bag, slot);

    if (!pItem2)
    {
        VisualizeItem(slot, pItem);

        if (IsAlive())
        {
            ItemTemplate const* pProto = pItem->GetTemplate();

            // item set bonuses applied only at equip and removed at unequip, and still active for broken items
            if (pProto && pProto->GetItemSet())
                AddItemsSetItem(this, pItem);

            _ApplyItemMods(pItem, slot, true);

            if (pProto && IsInCombat() && (pProto->GetClass() == ITEM_CLASS_WEAPON || pProto->GetInventoryType() == INVTYPE_RELIC) && m_weaponChangeTimer == 0)
            {
                uint32 cooldownSpell = getClass() == CLASS_ROGUE ? 6123 : 6119;
                SpellInfo const* spellProto = sSpellMgr->GetSpellInfo(cooldownSpell);

                if (!spellProto)
                    TC_LOG_ERROR("entities.player", "Player::EquipItem: Weapon switch cooldown spell %u for player '%s' (%s) couldn't be found in Spell.dbc",
                        cooldownSpell, GetName().c_str(), GetGUID().ToString().c_str());
                else
                {
                    m_weaponChangeTimer = spellProto->StartRecoveryTime;

                    GetSpellHistory()->AddGlobalCooldown(spellProto, m_weaponChangeTimer);

                    WorldPackets::Spells::SpellCooldown spellCooldown;
                    spellCooldown.Caster = GetGUID();
                    spellCooldown.Flags = SPELL_COOLDOWN_FLAG_INCLUDE_GCD;
                    spellCooldown.SpellCooldowns.emplace_back(cooldownSpell, 0);
                    GetSession()->SendPacket(spellCooldown.Write());
                }
            }
        }

        if (IsInWorld() && update)
        {
            pItem->AddToWorld();
            pItem->SendUpdateToPlayer(this);
        }

        ApplyEquipCooldown(pItem);

         // update expertise and armor penetration - passive auras may need it

        if (slot == EQUIPMENT_SLOT_MAINHAND)
            UpdateExpertise(BASE_ATTACK);

        else if (slot == EQUIPMENT_SLOT_OFFHAND)
            UpdateExpertise(OFF_ATTACK);

        switch (slot)
        {
            case EQUIPMENT_SLOT_MAINHAND:
            case EQUIPMENT_SLOT_OFFHAND:
                RecalculateRating(CR_ARMOR_PENETRATION);
            default:
                break;
        }
    }
    else
    {
        pItem2->SetCount(pItem2->GetCount() + pItem->GetCount());
        if (IsInWorld() && update)
            pItem2->SendUpdateToPlayer(this);

        // delete item (it not in any slot currently)
        //pItem->DeleteFromDB();
        if (IsInWorld() && update)
        {
            pItem->RemoveFromWorld();
            pItem->DestroyForPlayer(this);
        }

        RemoveEnchantmentDurations(pItem);
        RemoveItemDurations(pItem);

        pItem->SetOwnerGUID(GetGUID());                     // prevent error at next SetState in case trade/mail/buy from vendor
        pItem->SetNotRefundable(this);
        pItem->ClearSoulboundTradeable(this);
        RemoveTradeableItem(pItem);
        pItem->SetState(ITEM_REMOVED, this);
        pItem2->SetState(ITEM_CHANGED, this);

        ApplyEquipCooldown(pItem2);

        return pItem2;
    }

    // only for full equip instead adding to stack
    UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_EQUIP_ITEM, pItem->GetEntry());
    UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_EQUIP_EPIC_ITEM, pItem->GetEntry(), slot);

    return pItem;
}

void Player::QuickEquipItem(uint16 pos, Item* pItem)
{
    if (pItem)
    {
        AddEnchantmentDurations(pItem);
        AddItemDurations(pItem);

        uint8 slot = pos & 255;
        VisualizeItem(slot, pItem);

        if (IsInWorld())
        {
            pItem->AddToWorld();
            pItem->SendUpdateToPlayer(this);
        }

        UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_EQUIP_ITEM, pItem->GetEntry());
        UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_EQUIP_EPIC_ITEM, pItem->GetEntry(), slot);
    }
}

void Player::SetVisibleItemSlot(uint8 slot, Item* pItem)
{
    if (pItem)
    {
        SetUInt32Value(PLAYER_VISIBLE_ITEM + VISIBLE_ITEM_ENTRY_OFFSET + (slot * 2), pItem->GetVisibleEntry());
        SetUInt16Value(PLAYER_VISIBLE_ITEM + VISIBLE_ITEM_ENCHANTMENT_OFFSET + (slot * 2), 0, pItem->GetVisibleAppearanceModId());
        SetUInt16Value(PLAYER_VISIBLE_ITEM + VISIBLE_ITEM_ENCHANTMENT_OFFSET + (slot * 2), 1, pItem->GetEnchantmentId(PERM_ENCHANTMENT_SLOT));
    }
    else
    {
        SetUInt32Value(PLAYER_VISIBLE_ITEM + VISIBLE_ITEM_ENTRY_OFFSET + (slot * 2), 0);
        SetUInt32Value(PLAYER_VISIBLE_ITEM + VISIBLE_ITEM_ENCHANTMENT_OFFSET + (slot * 2), 0);
    }
}

void Player::VisualizeItem(uint8 slot, Item* pItem)
{
    if (!pItem)
        return;

    // check also  BIND_WHEN_PICKED_UP and BIND_QUEST_ITEM for .additem or .additemset case by GM (not binded at adding to inventory)
    if (pItem->GetTemplate()->GetBonding() == BIND_WHEN_EQUIPED || pItem->GetTemplate()->GetBonding() == BIND_WHEN_PICKED_UP || pItem->GetTemplate()->GetBonding() == BIND_QUEST_ITEM)
        pItem->SetBinding(true);

    TC_LOG_DEBUG("entities.player.items", "Player::SetVisibleItemSlot: Player '%s' (%s), Slot: %u, Item: %u",
        GetName().c_str(), GetGUID().ToString().c_str(), slot, pItem->GetEntry());

    m_items[slot] = pItem;
    SetGuidValue(PLAYER_FIELD_INV_SLOT_HEAD + (slot * 4), pItem->GetGUID());
    pItem->SetGuidValue(ITEM_FIELD_CONTAINED, GetGUID());
    pItem->SetOwnerGUID(GetGUID());
    pItem->SetSlot(slot);
    pItem->SetContainer(nullptr);

    if (slot < EQUIPMENT_SLOT_END)
        SetVisibleItemSlot(slot, pItem);

    pItem->SetState(ITEM_CHANGED, this);
}

Item* Player::BankItem(ItemPosCountVec const& dest, Item* pItem, bool update)
{
    return StoreItem(dest, pItem, update);
}

void Player::RemoveItem(uint8 bag, uint8 slot, bool update)
{
    // note: removeitem does not actually change the item
    // it only takes the item out of storage temporarily
    // note2: if removeitem is to be used for delinking
    // the item must be removed from the player's updatequeue

    Item* pItem = GetItemByPos(bag, slot);
    if (pItem)
    {
        TC_LOG_DEBUG("entities.player.items", "Player::RemoveItem: Player '%s' (%s), Bag: %u, Slot: %u, Item: %u",
            GetName().c_str(), GetGUID().ToString().c_str(), bag, slot, pItem->GetEntry());

        RemoveEnchantmentDurations(pItem);
        RemoveItemDurations(pItem);
        RemoveTradeableItem(pItem);

        if (bag == INVENTORY_SLOT_BAG_0)
        {
            if (slot < INVENTORY_SLOT_BAG_END)
            {
                ItemTemplate const* pProto = pItem->GetTemplate();
                // item set bonuses applied only at equip and removed at unequip, and still active for broken items

                if (pProto && pProto->GetItemSet())
                    RemoveItemsSetItem(this, pProto);

                _ApplyItemMods(pItem, slot, false);

                // remove item dependent auras and casts (only weapon and armor slots)
                if (slot < EQUIPMENT_SLOT_END)
                {
                    RemoveItemDependentAurasAndCasts(pItem);

                    // remove held enchantments, update expertise
                    if (slot == EQUIPMENT_SLOT_MAINHAND)
                    {
                        if (pItem->GetItemSuffixFactor())
                        {
                            pItem->ClearEnchantment(PROP_ENCHANTMENT_SLOT_3);
                            pItem->ClearEnchantment(PROP_ENCHANTMENT_SLOT_4);
                        }
                        else
                        {
                            pItem->ClearEnchantment(PROP_ENCHANTMENT_SLOT_0);
                            pItem->ClearEnchantment(PROP_ENCHANTMENT_SLOT_1);
                        }

                        UpdateExpertise(BASE_ATTACK);
                    }
                    else if (slot == EQUIPMENT_SLOT_OFFHAND)
                        UpdateExpertise(OFF_ATTACK);
                    // update armor penetration - passive auras may need it
                    switch (slot)
                    {
                        case EQUIPMENT_SLOT_MAINHAND:
                        case EQUIPMENT_SLOT_OFFHAND:
                            RecalculateRating(CR_ARMOR_PENETRATION);
                        default:
                            break;
                    }
                }
            }

            m_items[slot] = nullptr;
            SetGuidValue(PLAYER_FIELD_INV_SLOT_HEAD + (slot * 4), ObjectGuid::Empty);

            if (slot < EQUIPMENT_SLOT_END)
                SetVisibleItemSlot(slot, nullptr);
        }
        else if (Bag* pBag = GetBagByPos(bag))
            pBag->RemoveItem(slot, update);

        pItem->SetGuidValue(ITEM_FIELD_CONTAINED, ObjectGuid::Empty);
        // pItem->SetUInt64Value(ITEM_FIELD_OWNER, 0); not clear owner at remove (it will be set at store). This used in mail and auction code
        pItem->SetSlot(NULL_SLOT);
        if (IsInWorld() && update)
            pItem->SendUpdateToPlayer(this);
    }
}

// Common operation need to remove item from inventory without delete in trade, auction, guild bank, mail....
void Player::MoveItemFromInventory(uint8 bag, uint8 slot, bool update)
{
    if (Item* it = GetItemByPos(bag, slot))
    {
        ItemRemovedQuestCheck(it->GetEntry(), it->GetCount());
        RemoveItem(bag, slot, update);
        it->SetNotRefundable(this, false);
        it->RemoveFromUpdateQueueOf(this);
        if (it->IsInWorld())
        {
            it->RemoveFromWorld();
            it->DestroyForPlayer(this);
        }
    }
}

// Common operation need to add item from inventory without delete in trade, guild bank, mail....
void Player::MoveItemToInventory(ItemPosCountVec const& dest, Item* pItem, bool update, bool in_characterInventoryDB)
{
    // update quest counters
    ItemAddedQuestCheck(pItem->GetEntry(), pItem->GetCount());
    UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_RECEIVE_EPIC_ITEM, pItem->GetEntry(), pItem->GetCount());

    // store item
    Item* pLastItem = StoreItem(dest, pItem, update);

    // only set if not merged to existed stack (pItem can be deleted already but we can compare pointers any way)
    if (pLastItem == pItem)
    {
        // update owner for last item (this can be original item with wrong owner
        if (pLastItem->GetOwnerGUID() != GetGUID())
            pLastItem->SetOwnerGUID(GetGUID());

        // if this original item then it need create record in inventory
        // in case trade we already have item in other player inventory
        pLastItem->SetState(in_characterInventoryDB ? ITEM_CHANGED : ITEM_NEW, this);

        if (pLastItem->HasFlag(ITEM_FIELD_FLAGS, ITEM_FIELD_FLAG_BOP_TRADEABLE))
            AddTradeableItem(pLastItem);
    }
}

void Player::DestroyItem(uint8 bag, uint8 slot, bool update)
{
    Item* pItem = GetItemByPos(bag, slot);
    if (pItem)
    {
        TC_LOG_DEBUG("entities.player.items", "Player::DestroyItem: Player '%s' (%s), Bag: %u, Slot: %u, Item: %u",
            GetName().c_str(), GetGUID().ToString().c_str(), bag, slot, pItem->GetEntry());
        // Also remove all contained items if the item is a bag.
        // This if () prevents item saving crashes if the condition for a bag to be empty before being destroyed was bypassed somehow.
        if (pItem->IsNotEmptyBag())
            for (uint8 i = 0; i < MAX_BAG_SIZE; ++i)
                DestroyItem(slot, i, update);

        if (pItem->HasFlag(ITEM_FIELD_FLAGS, ITEM_FIELD_FLAG_WRAPPED))
        {
            PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_GIFT);

            stmt->setUInt64(0, pItem->GetGUID().GetCounter());

            CharacterDatabase.Execute(stmt);
        }

        RemoveEnchantmentDurations(pItem);
        RemoveItemDurations(pItem);

        pItem->SetNotRefundable(this);
        pItem->ClearSoulboundTradeable(this);
        RemoveTradeableItem(pItem);

        const ItemTemplate* proto = pItem->GetTemplate();
        for (uint8 i = 0; i < proto->Effects.size(); ++i)
            if (proto->Effects[i]->Trigger == ITEM_SPELLTRIGGER_ON_NO_DELAY_USE) // On obtain trigger
                RemoveAurasDueToSpell(proto->Effects[i]->SpellID);

        ItemRemovedQuestCheck(pItem->GetEntry(), pItem->GetCount());
        sScriptMgr->OnItemRemove(this, pItem);

        if (bag == INVENTORY_SLOT_BAG_0)
        {
            SetGuidValue(PLAYER_FIELD_INV_SLOT_HEAD + (slot * 4), ObjectGuid::Empty);

            // equipment and equipped bags can have applied bonuses
            if (slot < INVENTORY_SLOT_BAG_END)
            {
                ItemTemplate const* pProto = pItem->GetTemplate();

                // item set bonuses applied only at equip and removed at unequip, and still active for broken items
                if (pProto && pProto->GetItemSet())
                    RemoveItemsSetItem(this, pProto);

                _ApplyItemMods(pItem, slot, false);
            }

            if (slot < EQUIPMENT_SLOT_END)
            {
                // remove item dependent auras and casts (only weapon and armor slots)
                RemoveItemDependentAurasAndCasts(pItem);

                // update expertise and armor penetration - passive auras may need it
                switch (slot)
                {
                    case EQUIPMENT_SLOT_MAINHAND:
                    case EQUIPMENT_SLOT_OFFHAND:
                        RecalculateRating(CR_ARMOR_PENETRATION);
                    default:
                        break;
                }

                if (slot == EQUIPMENT_SLOT_MAINHAND)
                    UpdateExpertise(BASE_ATTACK);
                else if (slot == EQUIPMENT_SLOT_OFFHAND)
                    UpdateExpertise(OFF_ATTACK);

                // equipment visual show
                SetVisibleItemSlot(slot, nullptr);
            }

            m_items[slot] = nullptr;
        }
        else if (Bag* pBag = GetBagByPos(bag))
            pBag->RemoveItem(slot, update);

        // Delete rolled money / loot from db.
        // MUST be done before RemoveFromWorld() or GetTemplate() fails
        if (ItemTemplate const* pTmp = pItem->GetTemplate())
            if (pTmp->GetFlags() & ITEM_FLAG_OPENABLE)
                pItem->ItemContainerDeleteLootMoneyAndLootItemsFromDB();

        if (IsInWorld() && update)
        {
            pItem->RemoveFromWorld();
            pItem->DestroyForPlayer(this);
        }

        //pItem->SetOwnerGUID(0);
        pItem->SetGuidValue(ITEM_FIELD_CONTAINED, ObjectGuid::Empty);
        pItem->SetSlot(NULL_SLOT);
        pItem->SetState(ITEM_REMOVED, this);
    }
}

void Player::DestroyItemCount(uint32 itemEntry, uint32 count, bool update, bool unequip_check)
{
    TC_LOG_DEBUG("entities.player.items", "Player::DestroyItemCount: Player '%s' (%s), Item: %u, Count: %u",
        GetName().c_str(), GetGUID().ToString().c_str(), itemEntry, count);
    uint32 remcount = 0;

    // in inventory
    for (uint8 i = INVENTORY_SLOT_ITEM_START; i < INVENTORY_SLOT_ITEM_END; ++i)
    {
        if (Item* item = GetItemByPos(INVENTORY_SLOT_BAG_0, i))
        {
            if (item->GetEntry() == itemEntry && !item->IsInTrade())
            {
                if (item->GetCount() + remcount <= count)
                {
                    // all items in inventory can unequipped
                    remcount += item->GetCount();
                    DestroyItem(INVENTORY_SLOT_BAG_0, i, update);

                    if (remcount >= count)
                        return;
                }
                else
                {
                    ItemRemovedQuestCheck(item->GetEntry(), count - remcount);
                    item->SetCount(item->GetCount() - count + remcount);
                    if (IsInWorld() && update)
                        item->SendUpdateToPlayer(this);
                    item->SetState(ITEM_CHANGED, this);
                    return;
                }
            }
        }
    }

    // in inventory bags
    for (uint8 i = INVENTORY_SLOT_BAG_START; i < INVENTORY_SLOT_BAG_END; i++)
    {
        if (Bag* bag = GetBagByPos(i))
        {
            for (uint32 j = 0; j < bag->GetBagSize(); j++)
            {
                if (Item* item = bag->GetItemByPos(j))
                {
                    if (item->GetEntry() == itemEntry && !item->IsInTrade())
                    {
                        // all items in bags can be unequipped
                        if (item->GetCount() + remcount <= count)
                        {
                            remcount += item->GetCount();
                            DestroyItem(i, j, update);

                            if (remcount >= count)
                                return;
                        }
                        else
                        {
                            ItemRemovedQuestCheck(item->GetEntry(), count - remcount);
                            item->SetCount(item->GetCount() - count + remcount);
                            if (IsInWorld() && update)
                                item->SendUpdateToPlayer(this);
                            item->SetState(ITEM_CHANGED, this);
                            return;
                        }
                    }
                }
            }
        }
    }

    // in equipment and bag list
    for (uint8 i = EQUIPMENT_SLOT_START; i < INVENTORY_SLOT_BAG_END; i++)
    {
        if (Item* item = GetItemByPos(INVENTORY_SLOT_BAG_0, i))
        {
            if (item && item->GetEntry() == itemEntry && !item->IsInTrade())
            {
                if (item->GetCount() + remcount <= count)
                {
                    if (!unequip_check || CanUnequipItem(INVENTORY_SLOT_BAG_0 << 8 | i, false) == EQUIP_ERR_OK)
                    {
                        remcount += item->GetCount();
                        DestroyItem(INVENTORY_SLOT_BAG_0, i, update);

                        if (remcount >= count)
                            return;
                    }
                }
                else
                {
                    ItemRemovedQuestCheck(item->GetEntry(), count - remcount);
                    item->SetCount(item->GetCount() - count + remcount);
                    if (IsInWorld() && update)
                        item->SendUpdateToPlayer(this);
                    item->SetState(ITEM_CHANGED, this);
                    return;
                }
            }
        }
    }

    // in bank
    for (uint8 i = BANK_SLOT_ITEM_START; i < BANK_SLOT_ITEM_END; i++)
    {
        if (Item* item = GetItemByPos(INVENTORY_SLOT_BAG_0, i))
        {
            if (item->GetEntry() == itemEntry && !item->IsInTrade())
            {
                if (item->GetCount() + remcount <= count)
                {
                    remcount += item->GetCount();
                    DestroyItem(INVENTORY_SLOT_BAG_0, i, update);
                    if (remcount >= count)
                        return;
                }
                else
                {
                    ItemRemovedQuestCheck(item->GetEntry(), count - remcount);
                    item->SetCount(item->GetCount() - count + remcount);
                    if (IsInWorld() && update)
                        item->SendUpdateToPlayer(this);
                    item->SetState(ITEM_CHANGED, this);
                    return;
                }
            }
        }
    }

    // in bank bags
    for (uint8 i = BANK_SLOT_BAG_START; i < BANK_SLOT_BAG_END; i++)
    {
        if (Bag* bag = GetBagByPos(i))
        {
            for (uint32 j = 0; j < bag->GetBagSize(); j++)
            {
                if (Item* item = bag->GetItemByPos(j))
                {
                    if (item->GetEntry() == itemEntry && !item->IsInTrade())
                    {
                        // all items in bags can be unequipped
                        if (item->GetCount() + remcount <= count)
                        {
                            remcount += item->GetCount();
                            DestroyItem(i, j, update);

                            if (remcount >= count)
                                return;
                        }
                        else
                        {
                            ItemRemovedQuestCheck(item->GetEntry(), count - remcount);
                            item->SetCount(item->GetCount() - count + remcount);
                            if (IsInWorld() && update)
                                item->SendUpdateToPlayer(this);
                            item->SetState(ITEM_CHANGED, this);
                            return;
                        }
                    }
                }
            }
        }
    }
}

void Player::DestroyZoneLimitedItem(bool update, uint32 new_zone)
{
    TC_LOG_DEBUG("entities.player.items", "Player::DestroyZoneLimitedItem: In map %u and area %u for player '%s' (%s)",
        GetMapId(), new_zone, GetName().c_str(), GetGUID().ToString().c_str());

    // in inventory
    for (uint8 i = INVENTORY_SLOT_ITEM_START; i < INVENTORY_SLOT_ITEM_END; i++)
        if (Item* pItem = GetItemByPos(INVENTORY_SLOT_BAG_0, i))
            if (pItem->IsLimitedToAnotherMapOrZone(GetMapId(), new_zone))
                DestroyItem(INVENTORY_SLOT_BAG_0, i, update);

    // in inventory bags
    for (uint8 i = INVENTORY_SLOT_BAG_START; i < INVENTORY_SLOT_BAG_END; i++)
        if (Bag* pBag = GetBagByPos(i))
            for (uint32 j = 0; j < pBag->GetBagSize(); j++)
                if (Item* pItem = pBag->GetItemByPos(j))
                    if (pItem->IsLimitedToAnotherMapOrZone(GetMapId(), new_zone))
                        DestroyItem(i, j, update);

    // in equipment and bag list
    for (uint8 i = EQUIPMENT_SLOT_START; i < INVENTORY_SLOT_BAG_END; i++)
        if (Item* pItem = GetItemByPos(INVENTORY_SLOT_BAG_0, i))
            if (pItem->IsLimitedToAnotherMapOrZone(GetMapId(), new_zone))
                DestroyItem(INVENTORY_SLOT_BAG_0, i, update);
}

void Player::DestroyConjuredItems(bool update)
{
    // used when entering arena
    // destroys all conjured items
    TC_LOG_DEBUG("entities.player.items", "Player::DestroyConjuredItems: Player '%s' (%s)",
        GetName().c_str(), GetGUID().ToString().c_str());

    // in inventory
    for (uint8 i = INVENTORY_SLOT_ITEM_START; i < INVENTORY_SLOT_ITEM_END; i++)
        if (Item* pItem = GetItemByPos(INVENTORY_SLOT_BAG_0, i))
            if (pItem->IsConjuredConsumable())
                DestroyItem(INVENTORY_SLOT_BAG_0, i, update);

    // in inventory bags
    for (uint8 i = INVENTORY_SLOT_BAG_START; i < INVENTORY_SLOT_BAG_END; i++)
        if (Bag* pBag = GetBagByPos(i))
            for (uint32 j = 0; j < pBag->GetBagSize(); j++)
                if (Item* pItem = pBag->GetItemByPos(j))
                    if (pItem->IsConjuredConsumable())
                        DestroyItem(i, j, update);

    // in equipment and bag list
    for (uint8 i = EQUIPMENT_SLOT_START; i < INVENTORY_SLOT_BAG_END; i++)
        if (Item* pItem = GetItemByPos(INVENTORY_SLOT_BAG_0, i))
            if (pItem->IsConjuredConsumable())
                DestroyItem(INVENTORY_SLOT_BAG_0, i, update);
}

Item* Player::GetItemByEntry(uint32 entry) const
{
    // in inventory
    for (int i = INVENTORY_SLOT_ITEM_START; i < INVENTORY_SLOT_ITEM_END; ++i)
        if (Item* pItem = GetItemByPos(INVENTORY_SLOT_BAG_0, i))
            if (pItem->GetEntry() == entry)
                return pItem;

    for (int i = INVENTORY_SLOT_BAG_START; i < INVENTORY_SLOT_BAG_END; ++i)
        if (Bag* pBag = GetBagByPos(i))
            for (uint32 j = 0; j < pBag->GetBagSize(); ++j)
                if (Item* pItem = pBag->GetItemByPos(j))
                    if (pItem->GetEntry() == entry)
                        return pItem;

    for (int i = EQUIPMENT_SLOT_START; i < INVENTORY_SLOT_BAG_END; ++i)
        if (Item* pItem = GetItemByPos(INVENTORY_SLOT_BAG_0, i))
            if (pItem->GetEntry() == entry)
                return pItem;

    return nullptr;
}

std::vector<Item*> Player::GetItemListByEntry(uint32 entry, bool inBankAlso) const
{
    std::vector<Item*> itemList = std::vector<Item*>();

    for (uint8 i = INVENTORY_SLOT_ITEM_START; i < INVENTORY_SLOT_ITEM_END; ++i)
        if (Item* item = GetItemByPos(INVENTORY_SLOT_BAG_0, i))
            if (item->GetEntry() == entry)
                itemList.push_back(item);

    for (uint8 i = INVENTORY_SLOT_BAG_START; i < INVENTORY_SLOT_BAG_END; ++i)
        if (Bag* bag = GetBagByPos(i))
            for (uint32 j = 0; j < bag->GetBagSize(); ++j)
                if (Item* item = bag->GetItemByPos(j))
                    if (item->GetEntry() == entry)
                        itemList.push_back(item);

    for (uint8 i = EQUIPMENT_SLOT_START; i < INVENTORY_SLOT_BAG_END; ++i)
        if (Item* item = GetItemByPos(INVENTORY_SLOT_BAG_0, i))
            if (item->GetEntry() == entry)
                itemList.push_back(item);

    if (inBankAlso)
    {
        for (uint8 i = BANK_SLOT_ITEM_START; i < BANK_SLOT_BAG_END; ++i)
            if (Item* item = GetItemByPos(INVENTORY_SLOT_BAG_0, i))
                if (item->GetEntry() == entry)
                    itemList.push_back(item);
    }

    return itemList;
}

void Player::DestroyItemCount(Item* pItem, uint32 &count, bool update)
{
    if (!pItem)
        return;

    TC_LOG_DEBUG("entities.player.items", "Player::DestroyItemCount: Player '%s' (%s), Item (%s, Entry: %u), Count: %u",
        GetName().c_str(), GetGUID().ToString().c_str(), pItem->GetGUID().ToString().c_str(), pItem->GetEntry(), count);

    if (pItem->GetCount() <= count)
    {
        count -= pItem->GetCount();

        DestroyItem(pItem->GetBagSlot(), pItem->GetSlot(), update);
    }
    else
    {
        ItemRemovedQuestCheck(pItem->GetEntry(), count);
        pItem->SetCount(pItem->GetCount() - count);
        count = 0;
        if (IsInWorld() && update)
            pItem->SendUpdateToPlayer(this);
        pItem->SetState(ITEM_CHANGED, this);
    }
}

void Player::SplitItem(uint16 src, uint16 dst, uint32 count)
{
    uint8 srcbag = src >> 8;
    uint8 srcslot = src & 255;

    uint8 dstbag = dst >> 8;
    uint8 dstslot = dst & 255;

    Item* pSrcItem = GetItemByPos(srcbag, srcslot);
    if (!pSrcItem)
    {
        SendEquipError(EQUIP_ERR_ITEM_NOT_FOUND, pSrcItem, nullptr);
        return;
    }

    if (pSrcItem->m_lootGenerated)                           // prevent split looting item (item
    {
        //best error message found for attempting to split while looting
        SendEquipError(EQUIP_ERR_SPLIT_FAILED, pSrcItem, nullptr);
        return;
    }

    // not let split all items (can be only at cheating)
    if (pSrcItem->GetCount() == count)
    {
        SendEquipError(EQUIP_ERR_SPLIT_FAILED, pSrcItem, nullptr);
        return;
    }

    // not let split more existed items (can be only at cheating)
    if (pSrcItem->GetCount() < count)
    {
        SendEquipError(EQUIP_ERR_TOO_FEW_TO_SPLIT, pSrcItem, nullptr);
        return;
    }

    //! If trading
    if (TradeData* tradeData = GetTradeData())
    {
        //! If current item is in trade window (only possible with packet spoofing - silent return)
        if (tradeData->GetTradeSlotForItem(pSrcItem->GetGUID()) != TRADE_SLOT_INVALID)
            return;
    }

    TC_LOG_DEBUG("entities.player.items", "Player::SplitItem: Player '%s' (%s), Bag: %u, Slot: %u, Item: %u, Count: %u",
        GetName().c_str(), GetGUID().ToString().c_str(), dstbag, dstslot, pSrcItem->GetEntry(), count);
    Item* pNewItem = pSrcItem->CloneItem(count, this);
    if (!pNewItem)
    {
        SendEquipError(EQUIP_ERR_ITEM_NOT_FOUND, pSrcItem, nullptr);
        return;
    }

    if (IsInventoryPos(dst))
    {
        // change item amount before check (for unique max count check)
        pSrcItem->SetCount(pSrcItem->GetCount() - count);

        ItemPosCountVec dest;
        InventoryResult msg = CanStoreItem(dstbag, dstslot, dest, pNewItem, false);
        if (msg != EQUIP_ERR_OK)
        {
            delete pNewItem;
            pSrcItem->SetCount(pSrcItem->GetCount() + count);
            SendEquipError(msg, pSrcItem, nullptr);
            return;
        }

        if (IsInWorld())
            pSrcItem->SendUpdateToPlayer(this);
        pSrcItem->SetState(ITEM_CHANGED, this);
        StoreItem(dest, pNewItem, true);
    }
    else if (IsBankPos(dst))
    {
        // change item amount before check (for unique max count check)
        pSrcItem->SetCount(pSrcItem->GetCount() - count);

        ItemPosCountVec dest;
        InventoryResult msg = CanBankItem(dstbag, dstslot, dest, pNewItem, false);
        if (msg != EQUIP_ERR_OK)
        {
            delete pNewItem;
            pSrcItem->SetCount(pSrcItem->GetCount() + count);
            SendEquipError(msg, pSrcItem, nullptr);
            return;
        }

        if (IsInWorld())
            pSrcItem->SendUpdateToPlayer(this);
        pSrcItem->SetState(ITEM_CHANGED, this);
        BankItem(dest, pNewItem, true);
    }
    else if (IsEquipmentPos(dst))
    {
        // change item amount before check (for unique max count check), provide space for splitted items
        pSrcItem->SetCount(pSrcItem->GetCount() - count);

        uint16 dest;
        InventoryResult msg = CanEquipItem(dstslot, dest, pNewItem, false);
        if (msg != EQUIP_ERR_OK)
        {
            delete pNewItem;
            pSrcItem->SetCount(pSrcItem->GetCount() + count);
            SendEquipError(msg, pSrcItem, nullptr);
            return;
        }

        if (IsInWorld())
            pSrcItem->SendUpdateToPlayer(this);
        pSrcItem->SetState(ITEM_CHANGED, this);
        EquipItem(dest, pNewItem, true);
        AutoUnequipOffhandIfNeed();
    }
}

void Player::SwapItem(uint16 src, uint16 dst)
{
    uint8 srcbag = src >> 8;
    uint8 srcslot = src & 255;

    uint8 dstbag = dst >> 8;
    uint8 dstslot = dst & 255;

    Item* pSrcItem = GetItemByPos(srcbag, srcslot);
    Item* pDstItem = GetItemByPos(dstbag, dstslot);

    if (!pSrcItem)
        return;

    TC_LOG_DEBUG("entities.player.items", "Player::SwapItem: Player '%s' (%s), Bag: %u, Slot: %u, Item: %u",
        GetName().c_str(), GetGUID().ToString().c_str(), dstbag, dstslot, pSrcItem->GetEntry());

    if (!IsAlive())
    {
        SendEquipError(EQUIP_ERR_PLAYER_DEAD, pSrcItem, pDstItem);
        return;
    }

    // SRC checks

    // check unequip potability for equipped items and bank bags
    if (IsEquipmentPos(src) || IsBagPos(src))
    {
        // bags can be swapped with empty bag slots, or with empty bag (items move possibility checked later)
        InventoryResult msg = CanUnequipItem(src, !IsBagPos(src) || IsBagPos(dst) || (pDstItem && pDstItem->ToBag() && pDstItem->ToBag()->IsEmpty()));
        if (msg != EQUIP_ERR_OK)
        {
            SendEquipError(msg, pSrcItem, pDstItem);
            return;
        }
    }

    // prevent put equipped/bank bag in self
    if (IsBagPos(src) && srcslot == dstbag)
    {
        SendEquipError(EQUIP_ERR_BAG_IN_BAG, pSrcItem, pDstItem);
        return;
    }

    // prevent equipping bag in the same slot from its inside
    if (IsBagPos(dst) && srcbag == dstslot)
    {
        SendEquipError(EQUIP_ERR_CANT_SWAP, pSrcItem, pDstItem);
        return;
    }

    // DST checks

    if (pDstItem)
    {
        // check unequip potability for equipped items and bank bags
        if (IsEquipmentPos(dst) || IsBagPos(dst))
        {
            // bags can be swapped with empty bag slots, or with empty bag (items move possibility checked later)
            InventoryResult msg = CanUnequipItem(dst, !IsBagPos(dst) || IsBagPos(src) || (pSrcItem->ToBag() && pSrcItem->ToBag()->IsEmpty()));
            if (msg != EQUIP_ERR_OK)
            {
                SendEquipError(msg, pSrcItem, pDstItem);
                return;
            }
        }
    }

    // NOW this is or item move (swap with empty), or swap with another item (including bags in bag possitions)
    // or swap empty bag with another empty or not empty bag (with items exchange)

    // Move case
    if (!pDstItem)
    {
        if (IsInventoryPos(dst))
        {
            ItemPosCountVec dest;
            InventoryResult msg = CanStoreItem(dstbag, dstslot, dest, pSrcItem, false);
            if (msg != EQUIP_ERR_OK)
            {
                SendEquipError(msg, pSrcItem, nullptr);
                return;
            }

            RemoveItem(srcbag, srcslot, true);
            StoreItem(dest, pSrcItem, true);
            if (IsBankPos(src))
                ItemAddedQuestCheck(pSrcItem->GetEntry(), pSrcItem->GetCount());
        }
        else if (IsBankPos(dst))
        {
            ItemPosCountVec dest;
            InventoryResult msg = CanBankItem(dstbag, dstslot, dest, pSrcItem, false);
            if (msg != EQUIP_ERR_OK)
            {
                SendEquipError(msg, pSrcItem, nullptr);
                return;
            }

            RemoveItem(srcbag, srcslot, true);
            BankItem(dest, pSrcItem, true);
            ItemRemovedQuestCheck(pSrcItem->GetEntry(), pSrcItem->GetCount());
        }
        else if (IsEquipmentPos(dst))
        {
            uint16 dest;
            InventoryResult msg = CanEquipItem(dstslot, dest, pSrcItem, false);
            if (msg != EQUIP_ERR_OK)
            {
                SendEquipError(msg, pSrcItem, nullptr);
                return;
            }

            RemoveItem(srcbag, srcslot, true);
            EquipItem(dest, pSrcItem, true);
            AutoUnequipOffhandIfNeed();
        }

        return;
    }

    // attempt merge to / fill target item
    if (!pSrcItem->IsBag() && !pDstItem->IsBag())
    {
        InventoryResult msg;
        ItemPosCountVec sDest;
        uint16 eDest = 0;
        if (IsInventoryPos(dst))
            msg = CanStoreItem(dstbag, dstslot, sDest, pSrcItem, false);
        else if (IsBankPos(dst))
            msg = CanBankItem(dstbag, dstslot, sDest, pSrcItem, false);
        else if (IsEquipmentPos(dst))
            msg = CanEquipItem(dstslot, eDest, pSrcItem, false);
        else
            return;

        // can be merge/fill
        if (msg == EQUIP_ERR_OK)
        {
            if (pSrcItem->GetCount() + pDstItem->GetCount() <= pSrcItem->GetTemplate()->GetMaxStackSize())
            {
                RemoveItem(srcbag, srcslot, true);

                if (IsInventoryPos(dst))
                    StoreItem(sDest, pSrcItem, true);
                else if (IsBankPos(dst))
                    BankItem(sDest, pSrcItem, true);
                else if (IsEquipmentPos(dst))
                {
                    EquipItem(eDest, pSrcItem, true);
                    AutoUnequipOffhandIfNeed();
                }
            }
            else
            {
                pSrcItem->SetCount(pSrcItem->GetCount() + pDstItem->GetCount() - pSrcItem->GetTemplate()->GetMaxStackSize());
                pDstItem->SetCount(pSrcItem->GetTemplate()->GetMaxStackSize());
                pSrcItem->SetState(ITEM_CHANGED, this);
                pDstItem->SetState(ITEM_CHANGED, this);
                if (IsInWorld())
                {
                    pSrcItem->SendUpdateToPlayer(this);
                    pDstItem->SendUpdateToPlayer(this);
                }
            }
            SendRefundInfo(pDstItem);
            return;
        }
    }

    // impossible merge/fill, do real swap
    InventoryResult msg = EQUIP_ERR_OK;

    // check src->dest move possibility
    ItemPosCountVec sDest;
    uint16 eDest = 0;
    if (IsInventoryPos(dst))
        msg = CanStoreItem(dstbag, dstslot, sDest, pSrcItem, true);
    else if (IsBankPos(dst))
        msg = CanBankItem(dstbag, dstslot, sDest, pSrcItem, true);
    else if (IsEquipmentPos(dst))
    {
        msg = CanEquipItem(dstslot, eDest, pSrcItem, true);
        if (msg == EQUIP_ERR_OK)
            msg = CanUnequipItem(eDest, true);
    }

    if (msg != EQUIP_ERR_OK)
    {
        SendEquipError(msg, pSrcItem, pDstItem);
        return;
    }

    // check dest->src move possibility
    ItemPosCountVec sDest2;
    uint16 eDest2 = 0;
    if (IsInventoryPos(src))
        msg = CanStoreItem(srcbag, srcslot, sDest2, pDstItem, true);
    else if (IsBankPos(src))
        msg = CanBankItem(srcbag, srcslot, sDest2, pDstItem, true);
    else if (IsEquipmentPos(src))
    {
        msg = CanEquipItem(srcslot, eDest2, pDstItem, true);
        if (msg == EQUIP_ERR_OK)
            msg = CanUnequipItem(eDest2, true);
    }

    if (msg != EQUIP_ERR_OK)
    {
        SendEquipError(msg, pDstItem, pSrcItem);
        return;
    }

    // Check bag swap with item exchange (one from empty in not bag possition (equipped (not possible in fact) or store)
    if (Bag* srcBag = pSrcItem->ToBag())
    {
        if (Bag* dstBag = pDstItem->ToBag())
        {
            Bag* emptyBag = nullptr;
            Bag* fullBag = nullptr;
            if (srcBag->IsEmpty() && !IsBagPos(src))
            {
                emptyBag = srcBag;
                fullBag  = dstBag;
            }
            else if (dstBag->IsEmpty() && !IsBagPos(dst))
            {
                emptyBag = dstBag;
                fullBag  = srcBag;
            }

            // bag swap (with items exchange) case
            if (emptyBag && fullBag)
            {
                ItemTemplate const* emptyProto = emptyBag->GetTemplate();

                uint32 count = 0;

                for (uint32 i=0; i < fullBag->GetBagSize(); ++i)
                {
                    Item* bagItem = fullBag->GetItemByPos(i);
                    if (!bagItem)
                        continue;

                    ItemTemplate const* bagItemProto = bagItem->GetTemplate();
                    if (!bagItemProto || !ItemCanGoIntoBag(bagItemProto, emptyProto))
                    {
                        // one from items not go to empty target bag
                        SendEquipError(EQUIP_ERR_BAG_IN_BAG, pSrcItem, pDstItem);
                        return;
                    }

                    ++count;
                }

                if (count > emptyBag->GetBagSize())
                {
                    // too small targeted bag
                    SendEquipError(EQUIP_ERR_CANT_SWAP, pSrcItem, pDstItem);
                    return;
                }

                // Items swap
                count = 0;                                      // will pos in new bag
                for (uint32 i = 0; i< fullBag->GetBagSize(); ++i)
                {
                    Item* bagItem = fullBag->GetItemByPos(i);
                    if (!bagItem)
                        continue;

                    fullBag->RemoveItem(i, true);
                    emptyBag->StoreItem(count, bagItem, true);
                    bagItem->SetState(ITEM_CHANGED, this);

                    ++count;
                }
            }
        }
    }

    // now do moves, remove...
    RemoveItem(dstbag, dstslot, false);
    RemoveItem(srcbag, srcslot, false);

    // add to dest
    if (IsInventoryPos(dst))
        StoreItem(sDest, pSrcItem, true);
    else if (IsBankPos(dst))
        BankItem(sDest, pSrcItem, true);
    else if (IsEquipmentPos(dst))
        EquipItem(eDest, pSrcItem, true);

    // add to src
    if (IsInventoryPos(src))
        StoreItem(sDest2, pDstItem, true);
    else if (IsBankPos(src))
        BankItem(sDest2, pDstItem, true);
    else if (IsEquipmentPos(src))
        EquipItem(eDest2, pDstItem, true);

    // if player is moving bags and is looting an item inside this bag
    // release the loot
    if (!GetLootGUID().IsEmpty())
    {
        bool released = false;
        if (IsBagPos(src))
        {
            Bag* bag = pSrcItem->ToBag();
            for (uint32 i = 0; i < bag->GetBagSize(); ++i)
            {
                if (Item* bagItem = bag->GetItemByPos(i))
                {
                    if (bagItem->m_lootGenerated)
                    {
                        m_session->DoLootRelease(GetLootGUID());
                        released = true;                    // so we don't need to look at dstBag
                        break;
                    }
                }
            }
        }

        if (!released && IsBagPos(dst) && pDstItem)
        {
            Bag* bag = pDstItem->ToBag();
            for (uint32 i = 0; i < bag->GetBagSize(); ++i)
            {
                if (Item* bagItem = bag->GetItemByPos(i))
                {
                    if (bagItem->m_lootGenerated)
                    {
                        m_session->DoLootRelease(GetLootGUID());
                        break;
                    }
                }
            }
        }
    }

    AutoUnequipOffhandIfNeed();
}

void Player::AddItemToBuyBackSlot(Item* pItem)
{
    if (pItem)
    {
        uint32 slot = m_currentBuybackSlot;
        // if current back slot non-empty search oldest or free
        if (m_items[slot])
        {
            uint32 oldest_time = GetUInt32Value(PLAYER_FIELD_BUYBACK_TIMESTAMP_1);
            uint32 oldest_slot = BUYBACK_SLOT_START;

            for (uint32 i = BUYBACK_SLOT_START+1; i < BUYBACK_SLOT_END; ++i)
            {
                // found empty
                if (!m_items[i])
                {
                    oldest_slot = i;
                    break;
                }

                uint32 i_time = GetUInt32Value(PLAYER_FIELD_BUYBACK_TIMESTAMP_1 + i - BUYBACK_SLOT_START);

                if (oldest_time > i_time)
                {
                    oldest_time = i_time;
                    oldest_slot = i;
                }
            }

            // find oldest
            slot = oldest_slot;
        }

        RemoveItemFromBuyBackSlot(slot, true);
        TC_LOG_DEBUG("entities.player.items", "Player::AddItemToBuyBackSlot: Player '%s' (%s), Item: %u, Slot: %u",
            GetName().c_str(), GetGUID().ToString().c_str(), pItem->GetEntry(), slot);

        m_items[slot] = pItem;
        time_t base = time(nullptr);
        uint32 etime = uint32(base - m_logintime + (30 * 3600));
        uint32 eslot = slot - BUYBACK_SLOT_START;

        SetGuidValue(PLAYER_FIELD_INV_SLOT_HEAD + (slot * 4), pItem->GetGUID());
        if (ItemTemplate const* proto = pItem->GetTemplate())
            SetUInt32Value(PLAYER_FIELD_BUYBACK_PRICE_1 + eslot, proto->GetSellPrice() * pItem->GetCount());
        else
            SetUInt32Value(PLAYER_FIELD_BUYBACK_PRICE_1 + eslot, 0);

        SetUInt32Value(PLAYER_FIELD_BUYBACK_TIMESTAMP_1 + eslot, (uint32)etime);

        // move to next (for non filled list is move most optimized choice)
        if (m_currentBuybackSlot < BUYBACK_SLOT_END - 1)
            ++m_currentBuybackSlot;
    }
}

Item* Player::GetItemFromBuyBackSlot(uint32 slot)
{
    TC_LOG_DEBUG("entities.player.items", "Player::GetItemFromBuyBackSlot: Player '%s' (%s), Slot: %u",
        GetName().c_str(), GetGUID().ToString().c_str(), slot);
    if (slot >= BUYBACK_SLOT_START && slot < BUYBACK_SLOT_END)
        return m_items[slot];
    return nullptr;
}

void Player::RemoveItemFromBuyBackSlot(uint32 slot, bool del)
{
    TC_LOG_DEBUG("entities.player.items", "Player::RemoveItemFromBuyBackSlot: Player '%s' (%s), Slot: %u",
        GetName().c_str(), GetGUID().ToString().c_str(), slot);
    if (slot >= BUYBACK_SLOT_START && slot < BUYBACK_SLOT_END)
    {
        Item* pItem = m_items[slot];
        if (pItem)
        {
            pItem->RemoveFromWorld();
            if (del)
                pItem->SetState(ITEM_REMOVED, this);
        }

        m_items[slot] = nullptr;

        uint32 eslot = slot - BUYBACK_SLOT_START;
        SetGuidValue(PLAYER_FIELD_INV_SLOT_HEAD + (slot * 4), ObjectGuid::Empty);
        SetUInt32Value(PLAYER_FIELD_BUYBACK_PRICE_1 + eslot, 0);
        SetUInt32Value(PLAYER_FIELD_BUYBACK_TIMESTAMP_1 + eslot, 0);

        // if current backslot is filled set to now free slot
        if (m_items[m_currentBuybackSlot])
            m_currentBuybackSlot = slot;
    }
}

void Player::SendEquipError(InventoryResult msg, Item* item1 /*= nullptr*/, Item* item2 /*= nullptr*/, uint32 itemId /*= 0*/) const
{
    WorldPackets::Item::InventoryChangeFailure failure;
    failure.BagResult = msg;

    if (msg != EQUIP_ERR_OK)
    {
        if (item1)
            failure.Item[0] = item1->GetGUID();

        if (item2)
            failure.Item[1] = item2->GetGUID();

        failure.ContainerBSlot = 0; // bag equip slot, used with EQUIP_ERR_EVENT_AUTOEQUIP_BIND_CONFIRM and EQUIP_ERR_ITEM_DOESNT_GO_INTO_BAG2

        switch (msg)
        {
            case EQUIP_ERR_CANT_EQUIP_LEVEL_I:
            case EQUIP_ERR_PURCHASE_LEVEL_TOO_LOW:
            {
                failure.Level = uint32(item1 ? item1->GetRequiredLevel() : 0);
                break;
            }
            case EQUIP_ERR_EVENT_AUTOEQUIP_BIND_CONFIRM:    // no idea about this one...
            {
                //failure.SrcContainer
                //failure.SrcSlot
                //failure.DstContainer
                break;
            }
            case EQUIP_ERR_ITEM_MAX_LIMIT_CATEGORY_COUNT_EXCEEDED_IS:
            case EQUIP_ERR_ITEM_MAX_LIMIT_CATEGORY_SOCKETED_EXCEEDED_IS:
            case EQUIP_ERR_ITEM_MAX_LIMIT_CATEGORY_EQUIPPED_EXCEEDED_IS:
            {
                ItemTemplate const* proto = item1 ? item1->GetTemplate() : sObjectMgr->GetItemTemplate(itemId);
                failure.LimitCategory = proto ? proto->GetItemLimitCategory() : 0;
                break;
            }
            default:
                break;
        }
    }

    SendDirectMessage(failure.Write());
}

void Player::SendBuyError(BuyResult msg, Creature* creature, uint32 item, uint32 /*param*/) const
{
    WorldPackets::Item::BuyFailed packet;
    packet.VendorGUID = creature ? creature->GetGUID() : ObjectGuid::Empty;
    packet.Muid = item;
    packet.Reason = msg;
    GetSession()->SendPacket(packet.Write());
}

void Player::SendSellError(SellResult msg, Creature* creature, ObjectGuid guid) const
{
    WorldPackets::Item::SellResponse sellResponse;
    sellResponse.VendorGUID = (creature ? creature->GetGUID() : ObjectGuid::Empty);
    sellResponse.ItemGUID = guid;
    sellResponse.Reason = msg;
    GetSession()->SendPacket(sellResponse.Write());
}

bool Player::IsUseEquipedWeapon(bool mainhand) const
{
    // disarm applied only to mainhand weapon
    return !IsInFeralForm() && (!mainhand || !HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISARMED));
}

bool Player::IsTwoHandUsed() const
{
    Item* mainItem = GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND);
    if (!mainItem)
        return false;

    ItemTemplate const* itemTemplate = mainItem->GetTemplate();
    return (itemTemplate->GetInventoryType() == INVTYPE_2HWEAPON && !CanTitanGrip()) ||
        itemTemplate->GetInventoryType() == INVTYPE_RANGED ||
        (itemTemplate->GetInventoryType() == INVTYPE_RANGEDRIGHT && itemTemplate->GetClass() == ITEM_CLASS_WEAPON && itemTemplate->GetSubClass() != ITEM_SUBCLASS_WEAPON_WAND);
}

void Player::TradeCancel(bool sendback)
{
    if (m_trade)
    {
        Player* trader = m_trade->GetTrader();

        // send yellow "Trade canceled" message to both traders
        if (sendback)
            GetSession()->SendCancelTrade();

        trader->GetSession()->SendCancelTrade();

        // cleanup
        delete m_trade;
        m_trade = nullptr;
        delete trader->m_trade;
        trader->m_trade = nullptr;
    }
}

void Player::UpdateSoulboundTradeItems()
{
    // also checks for garbage data
    for (GuidUnorderedSet::iterator itr = m_itemSoulboundTradeable.begin(); itr != m_itemSoulboundTradeable.end();)
    {
        Item* item = GetItemByGuid(*itr);
        if (!item || item->GetOwnerGUID() != GetGUID() || item->CheckSoulboundTradeExpire())
            itr = m_itemSoulboundTradeable.erase(itr);
        else
            ++itr;
    }
}

void Player::AddTradeableItem(Item* item)
{
    m_itemSoulboundTradeable.insert(item->GetGUID());
}

void Player::RemoveTradeableItem(Item* item)
{
    m_itemSoulboundTradeable.erase(item->GetGUID());
}

void Player::UpdateItemDuration(uint32 time, bool realtimeonly)
{
    if (m_itemDuration.empty())
        return;

    TC_LOG_DEBUG("entities.player.items", "Player::UpdateItemDuration: Player '%s' (%s), Time: %u, RealTimeOnly: %u",
        GetName().c_str(), GetGUID().ToString().c_str(), time, realtimeonly);

    for (ItemDurationList::const_iterator itr = m_itemDuration.begin(); itr != m_itemDuration.end();)
    {
        Item* item = *itr;
        ++itr;                                              // current element can be erased in UpdateDuration

        if (!realtimeonly || item->GetTemplate()->FlagsCu & ITEM_FLAGS_CU_DURATION_REAL_TIME)
            item->UpdateDuration(this, time);
    }
}

void Player::UpdateEnchantTime(uint32 time)
{
    for (EnchantDurationList::iterator itr = m_enchantDuration.begin(), next; itr != m_enchantDuration.end(); itr=next)
    {
        ASSERT(itr->item);
        next = itr;
        if (!itr->item->GetEnchantmentId(itr->slot))
        {
            next = m_enchantDuration.erase(itr);
        }
        else if (itr->leftduration <= time)
        {
            ApplyEnchantment(itr->item, itr->slot, false, false);
            itr->item->ClearEnchantment(itr->slot);
            next = m_enchantDuration.erase(itr);
        }
        else if (itr->leftduration > time)
        {
            itr->leftduration -= time;
            ++next;
        }
    }
}

void Player::AddEnchantmentDurations(Item* item)
{
    for (int x = 0; x < MAX_ENCHANTMENT_SLOT; ++x)
    {
        if (!item->GetEnchantmentId(EnchantmentSlot(x)))
            continue;

        uint32 duration = item->GetEnchantmentDuration(EnchantmentSlot(x));
        if (duration > 0)
            AddEnchantmentDuration(item, EnchantmentSlot(x), duration);
    }
}

void Player::RemoveEnchantmentDurations(Item* item)
{
    for (EnchantDurationList::iterator itr = m_enchantDuration.begin(); itr != m_enchantDuration.end();)
    {
        if (itr->item == item)
        {
            // save duration in item
            item->SetEnchantmentDuration(EnchantmentSlot(itr->slot), itr->leftduration, this);
            itr = m_enchantDuration.erase(itr);
        }
        else
            ++itr;
    }
}

void Player::RemoveArenaEnchantments(EnchantmentSlot slot)
{
    // remove enchantments from equipped items first to clean up the m_enchantDuration list
    for (EnchantDurationList::iterator itr = m_enchantDuration.begin(), next; itr != m_enchantDuration.end(); itr = next)
    {
        next = itr;
        if (itr->slot == slot)
        {
            if (itr->item && itr->item->GetEnchantmentId(slot))
            {
                // Poisons and DK runes are enchants which are allowed on arenas
                if (sSpellMgr->IsArenaAllowedEnchancment(itr->item->GetEnchantmentId(slot)))
                {
                    ++next;
                    continue;
                }
                // remove from stats
                ApplyEnchantment(itr->item, slot, false, false);
                // remove visual
                itr->item->ClearEnchantment(slot);
            }
            // remove from update list
            next = m_enchantDuration.erase(itr);
        }
        else
            ++next;
    }

    // remove enchants from inventory items
    // NOTE: no need to remove these from stats, since these aren't equipped
    // in inventory
    for (uint8 i = INVENTORY_SLOT_ITEM_START; i < INVENTORY_SLOT_ITEM_END; ++i)
        if (Item* pItem = GetItemByPos(INVENTORY_SLOT_BAG_0, i))
            if (pItem->GetEnchantmentId(slot))
                pItem->ClearEnchantment(slot);

    // in inventory bags
    for (uint8 i = INVENTORY_SLOT_BAG_START; i < INVENTORY_SLOT_BAG_END; ++i)
        if (Bag* pBag = GetBagByPos(i))
            for (uint32 j = 0; j < pBag->GetBagSize(); j++)
                if (Item* pItem = pBag->GetItemByPos(j))
                    if (pItem->GetEnchantmentId(slot))
                        pItem->ClearEnchantment(slot);
}

// duration == 0 will remove item enchant
void Player::AddEnchantmentDuration(Item* item, EnchantmentSlot slot, uint32 duration)
{
    if (!item)
        return;

    if (slot >= MAX_ENCHANTMENT_SLOT)
        return;

    for (EnchantDurationList::iterator itr = m_enchantDuration.begin(); itr != m_enchantDuration.end(); ++itr)
    {
        if (itr->item == item && itr->slot == slot)
        {
            itr->item->SetEnchantmentDuration(itr->slot, itr->leftduration, this);
            m_enchantDuration.erase(itr);
            break;
        }
    }
    if (item && duration > 0)
    {
        GetSession()->SendItemEnchantTimeUpdate(GetGUID(), item->GetGUID(), slot, uint32(duration/1000));
        m_enchantDuration.push_back(EnchantDuration(item, slot, duration));
    }
}

void Player::ApplyEnchantment(Item* item, bool apply)
{
    for (uint32 slot = 0; slot < MAX_ENCHANTMENT_SLOT; ++slot)
        ApplyEnchantment(item, EnchantmentSlot(slot), apply);
}

void Player::ApplyEnchantment(Item* item, EnchantmentSlot slot, bool apply, bool apply_dur, bool ignore_condition)
{
    if (!item || !item->IsEquipped())
        return;

    if (slot >= MAX_ENCHANTMENT_SLOT)
        return;

    uint32 enchant_id = item->GetEnchantmentId(slot);
    if (!enchant_id)
        return;

    SpellItemEnchantmentEntry const* pEnchant = sSpellItemEnchantmentStore.LookupEntry(enchant_id);
    if (!pEnchant)
        return;

    if (!ignore_condition && pEnchant->ConditionID && !EnchantmentFitsRequirements(pEnchant->ConditionID, -1))
        return;

    if (pEnchant->MinLevel > getLevel())
        return;

    if (pEnchant->RequiredSkillID > 0 && pEnchant->RequiredSkillRank > GetSkillValue(pEnchant->RequiredSkillID))
        return;

    // Cogwheel gems dont have requirement data set in SpellItemEnchantment.dbc, but they do have it in Item-sparse.db2
    if (ItemTemplate const* gem = sObjectMgr->GetItemTemplate(pEnchant->SRCItemID))
        if (gem->GetRequiredSkill() && GetSkillValue(gem->GetRequiredSkill()) < gem->GetRequiredSkillRank())
            return;

    // If we're dealing with a gem inside a prismatic socket we need to check the prismatic socket requirements
    // rather than the gem requirements itself. If the socket has no color it is a prismatic socket.
    if ((slot == SOCK_ENCHANTMENT_SLOT || slot == SOCK_ENCHANTMENT_SLOT_2 || slot == SOCK_ENCHANTMENT_SLOT_3)
        && !item->GetSocketColor(slot - SOCK_ENCHANTMENT_SLOT))
    {
        // Check if the requirements for the prismatic socket are met before applying the gem stats
        SpellItemEnchantmentEntry const* pPrismaticEnchant = sSpellItemEnchantmentStore.LookupEntry(item->GetEnchantmentId(PRISMATIC_ENCHANTMENT_SLOT));
        if (!pPrismaticEnchant || (pPrismaticEnchant->RequiredSkillID > 0 && pPrismaticEnchant->RequiredSkillRank > GetSkillValue(pPrismaticEnchant->RequiredSkillID)))
            return;
    }

    if (!item->IsBroken())
    {
        for (int s = 0; s < MAX_ITEM_ENCHANTMENT_EFFECTS; ++s)
        {
            uint32 enchant_display_type = pEnchant->Effect[s];
            uint32 enchant_amount = pEnchant->EffectPointsMin[s];
            uint32 enchant_spell_id = pEnchant->EffectSpellID[s];

            switch (enchant_display_type)
            {
                case ITEM_ENCHANTMENT_TYPE_NONE:
                    break;
                case ITEM_ENCHANTMENT_TYPE_COMBAT_SPELL:
                    // processed in Player::CastItemCombatSpell
                    break;
                case ITEM_ENCHANTMENT_TYPE_DAMAGE:
                    if (item->GetSlot() == EQUIPMENT_SLOT_MAINHAND)
                    {
                        if (item->GetTemplate()->GetInventoryType() != INVTYPE_RANGED && item->GetTemplate()->GetInventoryType() != INVTYPE_RANGEDRIGHT)
                            HandleStatModifier(UNIT_MOD_DAMAGE_MAINHAND, TOTAL_VALUE, float(enchant_amount), apply);
                        else
                            HandleStatModifier(UNIT_MOD_DAMAGE_RANGED, TOTAL_VALUE, float(enchant_amount), apply);
                    }
                    else if (item->GetSlot() == EQUIPMENT_SLOT_OFFHAND)
                        HandleStatModifier(UNIT_MOD_DAMAGE_OFFHAND, TOTAL_VALUE, float(enchant_amount), apply);
                    break;
                case ITEM_ENCHANTMENT_TYPE_EQUIP_SPELL:
                    if (enchant_spell_id)
                    {
                        if (apply)
                        {
                            int32 basepoints = 0;
                            // Random Property Exist - try found basepoints for spell (basepoints depends from item suffix factor)
                            if (item->GetItemRandomPropertyId() < 0)
                            {
                                ItemRandomSuffixEntry const* item_rand = sItemRandomSuffixStore.LookupEntry(abs(item->GetItemRandomPropertyId()));
                                if (item_rand)
                                {
                                    // Search enchant_amount
                                    for (int k = 0; k < MAX_ITEM_RANDOM_PROPERTIES; ++k)
                                    {
                                        if (item_rand->Enchantment[k] == enchant_id)
                                        {
                                            basepoints = int32((item_rand->AllocationPct[k] * item->GetItemSuffixFactor()) / 10000);
                                            break;
                                        }
                                    }
                                }
                            }
                            // Cast custom spell vs all equal basepoints got from enchant_amount
                            if (basepoints)
                                CastCustomSpell(this, enchant_spell_id, &basepoints, &basepoints, &basepoints, true, item);
                            else
                                CastSpell(this, enchant_spell_id, true, item);
                        }
                        else
                            RemoveAurasDueToItemSpell(enchant_spell_id, item->GetGUID());
                    }
                    break;
                case ITEM_ENCHANTMENT_TYPE_RESISTANCE:
                    if (!enchant_amount)
                    {
                        ItemRandomSuffixEntry const* item_rand = sItemRandomSuffixStore.LookupEntry(abs(item->GetItemRandomPropertyId()));
                        if (item_rand)
                        {
                            for (int k = 0; k < MAX_ITEM_RANDOM_PROPERTIES; ++k)
                            {
                                if (item_rand->Enchantment[k] == enchant_id)
                                {
                                    enchant_amount = uint32((item_rand->AllocationPct[k] * item->GetItemSuffixFactor()) / 10000);
                                    break;
                                }
                            }
                        }
                    }

                    HandleStatModifier(UnitMods(UNIT_MOD_RESISTANCE_START + enchant_spell_id), TOTAL_VALUE, float(enchant_amount), apply);
                    break;
                case ITEM_ENCHANTMENT_TYPE_STAT:
                {
                    if (!enchant_amount)
                    {
                        ItemRandomSuffixEntry const* item_rand_suffix = sItemRandomSuffixStore.LookupEntry(abs(item->GetItemRandomPropertyId()));
                        if (item_rand_suffix)
                        {
                            for (int k = 0; k < MAX_ITEM_RANDOM_PROPERTIES; ++k)
                            {
                                if (item_rand_suffix->Enchantment[k] == enchant_id)
                                {
                                    enchant_amount = uint32((item_rand_suffix->AllocationPct[k] * item->GetItemSuffixFactor()) / 10000);
                                    break;
                                }
                            }
                        }
                    }

                    TC_LOG_DEBUG("entities.player.items", "Adding %u to stat nb %u", enchant_amount, enchant_spell_id);
                    switch (enchant_spell_id)
                    {
                        case ITEM_MOD_MANA:
                            TC_LOG_DEBUG("entities.player.items", "+ %u MANA", enchant_amount);
                            HandleStatModifier(UNIT_MOD_MANA, BASE_VALUE, float(enchant_amount), apply);
                            break;
                        case ITEM_MOD_HEALTH:
                            TC_LOG_DEBUG("entities.player.items", "+ %u HEALTH", enchant_amount);
                            HandleStatModifier(UNIT_MOD_HEALTH, BASE_VALUE, float(enchant_amount), apply);
                            break;
                        case ITEM_MOD_AGILITY:
                            TC_LOG_DEBUG("entities.player.items", "+ %u AGILITY", enchant_amount);
                            HandleStatModifier(UNIT_MOD_STAT_AGILITY, TOTAL_VALUE, float(enchant_amount), apply);
                            ApplyStatBuffMod(STAT_AGILITY, (float)enchant_amount, apply);
                            break;
                        case ITEM_MOD_STRENGTH:
                            TC_LOG_DEBUG("entities.player.items", "+ %u STRENGTH", enchant_amount);
                            HandleStatModifier(UNIT_MOD_STAT_STRENGTH, TOTAL_VALUE, float(enchant_amount), apply);
                            ApplyStatBuffMod(STAT_STRENGTH, (float)enchant_amount, apply);
                            break;
                        case ITEM_MOD_INTELLECT:
                            TC_LOG_DEBUG("entities.player.items", "+ %u INTELLECT", enchant_amount);
                            HandleStatModifier(UNIT_MOD_STAT_INTELLECT, TOTAL_VALUE, float(enchant_amount), apply);
                            ApplyStatBuffMod(STAT_INTELLECT, (float)enchant_amount, apply);
                            break;
                        case ITEM_MOD_SPIRIT:
                            TC_LOG_DEBUG("entities.player.items", "+ %u SPIRIT", enchant_amount);
                            HandleStatModifier(UNIT_MOD_STAT_SPIRIT, TOTAL_VALUE, float(enchant_amount), apply);
                            ApplyStatBuffMod(STAT_SPIRIT, (float)enchant_amount, apply);
                            break;
                        case ITEM_MOD_STAMINA:
                            TC_LOG_DEBUG("entities.player.items", "+ %u STAMINA", enchant_amount);
                            HandleStatModifier(UNIT_MOD_STAT_STAMINA, TOTAL_VALUE, float(enchant_amount), apply);
                            ApplyStatBuffMod(STAT_STAMINA, (float)enchant_amount, apply);
                            break;
                        case ITEM_MOD_DEFENSE_SKILL_RATING:
                            ApplyRatingMod(CR_DEFENSE_SKILL, enchant_amount, apply);
                            TC_LOG_DEBUG("entities.player.items", "+ %u DEFENCE", enchant_amount);
                            break;
                        case  ITEM_MOD_DODGE_RATING:
                            ApplyRatingMod(CR_DODGE, enchant_amount, apply);
                            TC_LOG_DEBUG("entities.player.items", "+ %u DODGE", enchant_amount);
                            break;
                        case ITEM_MOD_PARRY_RATING:
                            ApplyRatingMod(CR_PARRY, enchant_amount, apply);
                            TC_LOG_DEBUG("entities.player.items", "+ %u PARRY", enchant_amount);
                            break;
                        case ITEM_MOD_BLOCK_RATING:
                            ApplyRatingMod(CR_BLOCK, enchant_amount, apply);
                            TC_LOG_DEBUG("entities.player.items", "+ %u SHIELD_BLOCK", enchant_amount);
                            break;
                        case ITEM_MOD_HIT_MELEE_RATING:
                            ApplyRatingMod(CR_HIT_MELEE, enchant_amount, apply);
                            TC_LOG_DEBUG("entities.player.items", "+ %u MELEE_HIT", enchant_amount);
                            break;
                        case ITEM_MOD_HIT_RANGED_RATING:
                            ApplyRatingMod(CR_HIT_RANGED, enchant_amount, apply);
                            TC_LOG_DEBUG("entities.player.items", "+ %u RANGED_HIT", enchant_amount);
                            break;
                        case ITEM_MOD_HIT_SPELL_RATING:
                            ApplyRatingMod(CR_HIT_SPELL, enchant_amount, apply);
                            TC_LOG_DEBUG("entities.player.items", "+ %u SPELL_HIT", enchant_amount);
                            break;
                        case ITEM_MOD_CRIT_MELEE_RATING:
                            ApplyRatingMod(CR_CRIT_MELEE, enchant_amount, apply);
                            TC_LOG_DEBUG("entities.player.items", "+ %u MELEE_CRIT", enchant_amount);
                            break;
                        case ITEM_MOD_CRIT_RANGED_RATING:
                            ApplyRatingMod(CR_CRIT_RANGED, enchant_amount, apply);
                            TC_LOG_DEBUG("entities.player.items", "+ %u RANGED_CRIT", enchant_amount);
                            break;
                        case ITEM_MOD_CRIT_SPELL_RATING:
                            ApplyRatingMod(CR_CRIT_SPELL, enchant_amount, apply);
                            TC_LOG_DEBUG("entities.player.items", "+ %u SPELL_CRIT", enchant_amount);
                            break;
                        // Values from ITEM_STAT_MELEE_HA_RATING to ITEM_MOD_HASTE_RANGED_RATING are never used
                        // in Enchantments
                        // case ITEM_MOD_HIT_TAKEN_MELEE_RATING:
                        //     ApplyRatingMod(CR_HIT_TAKEN_MELEE, enchant_amount, apply);
                        //     break;
                        // case ITEM_MOD_HIT_TAKEN_RANGED_RATING:
                        //     ApplyRatingMod(CR_HIT_TAKEN_RANGED, enchant_amount, apply);
                        //     break;
                        // case ITEM_MOD_HIT_TAKEN_SPELL_RATING:
                        //     ApplyRatingMod(CR_HIT_TAKEN_SPELL, enchant_amount, apply);
                        //     break;
                        // case ITEM_MOD_CRIT_TAKEN_MELEE_RATING:
                        //     ApplyRatingMod(CR_CRIT_TAKEN_MELEE, enchant_amount, apply);
                        //     break;
                        // case ITEM_MOD_CRIT_TAKEN_RANGED_RATING:
                        //     ApplyRatingMod(CR_CRIT_TAKEN_RANGED, enchant_amount, apply);
                        //     break;
                        // case ITEM_MOD_CRIT_TAKEN_SPELL_RATING:
                        //     ApplyRatingMod(CR_CRIT_TAKEN_SPELL, enchant_amount, apply);
                        //     break;
                        // case ITEM_MOD_HASTE_MELEE_RATING:
                        //     ApplyRatingMod(CR_HASTE_MELEE, enchant_amount, apply);
                        //     break;
                        // case ITEM_MOD_HASTE_RANGED_RATING:
                        //     ApplyRatingMod(CR_HASTE_RANGED, enchant_amount, apply);
                        //     break;
                        case ITEM_MOD_HASTE_SPELL_RATING:
                            ApplyRatingMod(CR_HASTE_SPELL, enchant_amount, apply);
                            break;
                        case ITEM_MOD_HIT_RATING:
                            ApplyRatingMod(CR_HIT_MELEE, enchant_amount, apply);
                            ApplyRatingMod(CR_HIT_RANGED, enchant_amount, apply);
                            ApplyRatingMod(CR_HIT_SPELL, enchant_amount, apply);
                            TC_LOG_DEBUG("entities.player.items", "+ %u HIT", enchant_amount);
                            break;
                        case ITEM_MOD_CRIT_RATING:
                            ApplyRatingMod(CR_CRIT_MELEE, enchant_amount, apply);
                            ApplyRatingMod(CR_CRIT_RANGED, enchant_amount, apply);
                            ApplyRatingMod(CR_CRIT_SPELL, enchant_amount, apply);
                            TC_LOG_DEBUG("entities.player.items", "+ %u CRITICAL", enchant_amount);
                            break;
                        // case ITEM_MOD_HIT_TAKEN_RATING: // Unused since 3.3.5
                        //     ApplyRatingMod(CR_HIT_TAKEN_MELEE, enchant_amount, apply);
                        //     ApplyRatingMod(CR_HIT_TAKEN_RANGED, enchant_amount, apply);
                        //     ApplyRatingMod(CR_HIT_TAKEN_SPELL, enchant_amount, apply);
                        //     break;
                        // case ITEM_MOD_CRIT_TAKEN_RATING: // Unused since 3.3.5
                        //     ApplyRatingMod(CR_CRIT_TAKEN_MELEE, enchant_amount, apply);
                        //     ApplyRatingMod(CR_CRIT_TAKEN_RANGED, enchant_amount, apply);
                        //     ApplyRatingMod(CR_CRIT_TAKEN_SPELL, enchant_amount, apply);
                        //     break;
                        case ITEM_MOD_RESILIENCE_RATING:
                            ApplyRatingMod(CR_RESILIENCE_PLAYER_DAMAGE_TAKEN, enchant_amount, apply);
                            TC_LOG_DEBUG("entities.player.items", "+ %u RESILIENCE", enchant_amount);
                            break;
                        case ITEM_MOD_HASTE_RATING:
                            ApplyRatingMod(CR_HASTE_MELEE, enchant_amount, apply);
                            ApplyRatingMod(CR_HASTE_RANGED, enchant_amount, apply);
                            ApplyRatingMod(CR_HASTE_SPELL, enchant_amount, apply);
                            TC_LOG_DEBUG("entities.player.items", "+ %u HASTE", enchant_amount);
                            break;
                        case ITEM_MOD_EXPERTISE_RATING:
                            ApplyRatingMod(CR_EXPERTISE, enchant_amount, apply);
                            TC_LOG_DEBUG("entities.player.items", "+ %u EXPERTISE", enchant_amount);
                            break;
                        case ITEM_MOD_ATTACK_POWER:
                            HandleStatModifier(UNIT_MOD_ATTACK_POWER, TOTAL_VALUE, float(enchant_amount), apply);
                            HandleStatModifier(UNIT_MOD_ATTACK_POWER_RANGED, TOTAL_VALUE, float(enchant_amount), apply);
                            TC_LOG_DEBUG("entities.player.items", "+ %u ATTACK_POWER", enchant_amount);
                            break;
                        case ITEM_MOD_RANGED_ATTACK_POWER:
                            HandleStatModifier(UNIT_MOD_ATTACK_POWER_RANGED, TOTAL_VALUE, float(enchant_amount), apply);
                            TC_LOG_DEBUG("entities.player.items", "+ %u RANGED_ATTACK_POWER", enchant_amount);
                            break;
                        case ITEM_MOD_MANA_REGENERATION:
                            ApplyManaRegenBonus(enchant_amount, apply);
                            TC_LOG_DEBUG("entities.player.items", "+ %u MANA_REGENERATION", enchant_amount);
                            break;
                        case ITEM_MOD_ARMOR_PENETRATION_RATING:
                            ApplyRatingMod(CR_ARMOR_PENETRATION, enchant_amount, apply);
                            TC_LOG_DEBUG("entities.player.items", "+ %u ARMOR PENETRATION", enchant_amount);
                            break;
                        case ITEM_MOD_SPELL_POWER:
                            ApplySpellPowerBonus(enchant_amount, apply);
                            TC_LOG_DEBUG("entities.player.items", "+ %u SPELL_POWER", enchant_amount);
                            break;
                        case ITEM_MOD_HEALTH_REGEN:
                            ApplyHealthRegenBonus(enchant_amount, apply);
                            TC_LOG_DEBUG("entities.player.items", "+ %u HEALTH_REGENERATION", enchant_amount);
                            break;
                        case ITEM_MOD_SPELL_PENETRATION:
                            ApplySpellPenetrationBonus(enchant_amount, apply);
                            TC_LOG_DEBUG("entities.player.items", "+ %u SPELL_PENETRATION", enchant_amount);
                            break;
                        case ITEM_MOD_BLOCK_VALUE:
                            HandleBaseModValue(SHIELD_BLOCK_VALUE, FLAT_MOD, float(enchant_amount), apply);
                            TC_LOG_DEBUG("entities.player.items", "+ %u BLOCK_VALUE", enchant_amount);
                            break;
                        case ITEM_MOD_MASTERY_RATING:
                            ApplyRatingMod(CR_MASTERY, enchant_amount, apply);
                            TC_LOG_DEBUG("entities.player.items", "+ %u MASTERY", enchant_amount);
                            break;
                        default:
                            break;
                    }
                    break;
                }
                case ITEM_ENCHANTMENT_TYPE_TOTEM:           // Shaman Rockbiter Weapon
                {
                    if (getClass() == CLASS_SHAMAN)
                    {
                        float addValue;
                        if (item->GetSlot() == EQUIPMENT_SLOT_MAINHAND)
                        {
                            addValue = float(enchant_amount * item->GetTemplate()->GetDelay() / 1000.0f);
                            HandleStatModifier(UNIT_MOD_DAMAGE_MAINHAND, TOTAL_VALUE, addValue, apply);
                        }
                        else if (item->GetSlot() == EQUIPMENT_SLOT_OFFHAND)
                        {
                            addValue = float(enchant_amount * item->GetTemplate()->GetDelay() / 1000.0f);
                            HandleStatModifier(UNIT_MOD_DAMAGE_OFFHAND, TOTAL_VALUE, addValue, apply);
                        }
                    }
                    break;
                }
                case ITEM_ENCHANTMENT_TYPE_USE_SPELL:
                    // processed in Player::CastItemUseSpell
                    break;
                case ITEM_ENCHANTMENT_TYPE_PRISMATIC_SOCKET:
                    // nothing do..
                    break;
                default:
                    TC_LOG_ERROR("entities.player", "Player::ApplyEnchantment: Unknown item enchantment (ID: %u, DisplayType: %u) for player '%s' (%s)",
                        enchant_id, enchant_display_type, GetName().c_str(), GetGUID().ToString().c_str());
                    break;
            }                                               /*switch (enchant_display_type)*/
        }                                                   /*for*/
    }

    // visualize enchantment at player and equipped items
    if (slot == PERM_ENCHANTMENT_SLOT)
        SetUInt16Value(PLAYER_VISIBLE_ITEM + VISIBLE_ITEM_ENCHANTMENT_OFFSET + (item->GetSlot() * 2), 0, apply ? item->GetEnchantmentId(slot) : 0);

    if (slot == TEMP_ENCHANTMENT_SLOT)
        SetUInt16Value(PLAYER_VISIBLE_ITEM + VISIBLE_ITEM_ENCHANTMENT_OFFSET + (item->GetSlot() * 2), 1, apply ? item->GetEnchantmentId(slot) : 0);

    if (apply_dur)
    {
        if (apply)
        {
            // set duration
            uint32 duration = item->GetEnchantmentDuration(slot);
            if (duration > 0)
                AddEnchantmentDuration(item, slot, duration);
        }
        else
        {
            // duration == 0 will remove EnchantDuration
            AddEnchantmentDuration(item, slot, 0);
        }
    }
}

void Player::UpdateSkillEnchantments(uint16 skill_id, uint16 curr_value, uint16 new_value)
{
    for (uint8 i = 0; i < INVENTORY_SLOT_BAG_END; ++i)
    {
        if (m_items[i])
        {
            for (uint8 slot = 0; slot < MAX_ENCHANTMENT_SLOT; ++slot)
            {
                uint32 ench_id = m_items[i]->GetEnchantmentId(EnchantmentSlot(slot));
                if (!ench_id)
                    continue;

                SpellItemEnchantmentEntry const* Enchant = sSpellItemEnchantmentStore.LookupEntry(ench_id);
                if (!Enchant)
                    return;

                if (Enchant->RequiredSkillID == skill_id)
                {
                    // Checks if the enchantment needs to be applied or removed
                    if (curr_value < Enchant->RequiredSkillRank && new_value >= Enchant->RequiredSkillRank)
                        ApplyEnchantment(m_items[i], EnchantmentSlot(slot), true);
                    else if (new_value < Enchant->RequiredSkillRank && curr_value >= Enchant->RequiredSkillRank)
                        ApplyEnchantment(m_items[i], EnchantmentSlot(slot), false);
                }

                // If we're dealing with a gem inside a prismatic socket we need to check the prismatic socket requirements
                // rather than the gem requirements itself. If the socket has no color it is a prismatic socket.
                if ((slot == SOCK_ENCHANTMENT_SLOT || slot == SOCK_ENCHANTMENT_SLOT_2 || slot == SOCK_ENCHANTMENT_SLOT_3)
                    && !m_items[i]->GetSocketColor(slot - SOCK_ENCHANTMENT_SLOT))
                {
                    SpellItemEnchantmentEntry const* pPrismaticEnchant = sSpellItemEnchantmentStore.LookupEntry(m_items[i]->GetEnchantmentId(PRISMATIC_ENCHANTMENT_SLOT));

                    if (pPrismaticEnchant && pPrismaticEnchant->RequiredSkillID == skill_id)
                    {
                        if (curr_value < pPrismaticEnchant->RequiredSkillRank && new_value >= pPrismaticEnchant->RequiredSkillRank)
                            ApplyEnchantment(m_items[i], EnchantmentSlot(slot), true);
                        else if (new_value < pPrismaticEnchant->RequiredSkillRank && curr_value >= pPrismaticEnchant->RequiredSkillRank)
                            ApplyEnchantment(m_items[i], EnchantmentSlot(slot), false);
                    }
                }
            }
        }
    }
}

void Player::SendEnchantmentDurations()
{
    for (EnchantDurationList::const_iterator itr = m_enchantDuration.begin(); itr != m_enchantDuration.end(); ++itr)
        GetSession()->SendItemEnchantTimeUpdate(GetGUID(), itr->item->GetGUID(), itr->slot, uint32(itr->leftduration) / 1000);
}

void Player::SendItemDurations()
{
    for (ItemDurationList::const_iterator itr = m_itemDuration.begin(); itr != m_itemDuration.end(); ++itr)
        (*itr)->SendTimeUpdate(this);
}

void Player::SendNewItem(Item* item, uint32 quantity, bool pushed, bool created, bool broadcast)
{
    if (!item)  // prevent crash
        return;

    WorldPackets::Item::ItemPushResult packet;

    packet.PlayerGUID = GetGUID();

    packet.Slot = item->GetBagSlot();
    packet.SlotInBag = item->GetCount() == quantity ? item->GetSlot() : -1;

    packet.Item.Initialize(item);

    //packet.QuestLogItemID;
    packet.Quantity = quantity;
    packet.QuantityInInventory = GetItemCount(item->GetEntry());
    //packet.DungeonEncounterID;
    packet.BattlePetBreedID = item->GetModifier(ITEM_MODIFIER_BATTLE_PET_BREED_DATA) & 0xFFFFFF;
    packet.BattlePetBreedQuality = (item->GetModifier(ITEM_MODIFIER_BATTLE_PET_BREED_DATA) >> 24) & 0xFF;
    packet.BattlePetSpeciesID = item->GetModifier(ITEM_MODIFIER_BATTLE_PET_SPECIES_ID);
    packet.BattlePetLevel = item->GetModifier(ITEM_MODIFIER_BATTLE_PET_LEVEL);

    packet.ItemGUID = item->GetGUID();

    packet.Pushed = pushed;
    packet.DisplayText = WorldPackets::Item::ItemPushResult::DISPLAY_TYPE_NORMAL;
    packet.Created = created;
    //packet.IsBonusRoll;
    //packet.IsEncounterLoot;

    if (broadcast && GetGroup())
        GetGroup()->BroadcastPacket(packet.Write(), true);
    else
        GetSession()->SendPacket(packet.Write());
}

/*********************************************************/
/***                    GOSSIP SYSTEM                  ***/
/*********************************************************/

void Player::PrepareGossipMenu(WorldObject* source, uint32 menuId /*= 0*/, bool showQuests /*= false*/)
{
    PlayerMenu* menu = PlayerTalkClass;
    menu->ClearMenus();

    menu->GetGossipMenu().SetMenuId(menuId);

    GossipMenuItemsMapBounds menuItemBounds = sObjectMgr->GetGossipMenuItemsMapBounds(menuId);

    // if default menuId and no menu options exist for this, use options from default options
    if (menuItemBounds.first == menuItemBounds.second && menuId == GetDefaultGossipMenuForSource(source))
        menuItemBounds = sObjectMgr->GetGossipMenuItemsMapBounds(0);

    uint64 npcflags = 0;

    if (source->GetTypeId() == TYPEID_UNIT)
    {
        npcflags = source->GetUInt64Value(UNIT_NPC_FLAGS);
        if (showQuests && npcflags & UNIT_NPC_FLAG_QUESTGIVER)
            PrepareQuestMenu(source->GetGUID());
    }
    else if (source->GetTypeId() == TYPEID_GAMEOBJECT)
        if (showQuests && source->ToGameObject()->GetGoType() == GAMEOBJECT_TYPE_QUESTGIVER)
            PrepareQuestMenu(source->GetGUID());

    for (GossipMenuItemsContainer::const_iterator itr = menuItemBounds.first; itr != menuItemBounds.second; ++itr)
    {
        bool canTalk = true;
        if (!sConditionMgr->IsObjectMeetToConditions(this, source, itr->second.Conditions))
            continue;

        if (Creature* creature = source->ToCreature())
        {
            if (!(itr->second.OptionNpcflag & npcflags))
                continue;

            switch (itr->second.OptionType)
            {
                case GOSSIP_OPTION_ARMORER:
                    canTalk = false;                       // added in special mode
                    break;
                case GOSSIP_OPTION_SPIRITHEALER:
                    if (!isDead())
                        canTalk = false;
                    break;
                case GOSSIP_OPTION_VENDOR:
                {
                    VendorItemData const* vendorItems = creature->GetVendorItems();
                    if (!vendorItems || vendorItems->Empty())
                    {
                        TC_LOG_ERROR("sql.sql", "Creature %s (%s DB GUID: " UI64FMTD ") has UNIT_NPC_FLAG_VENDOR set but has an empty trading item list.", creature->GetName().c_str(), creature->GetGUID().ToString().c_str(), creature->GetSpawnId());
                        canTalk = false;
                    }
                    break;
                }
                case GOSSIP_OPTION_LEARNDUALSPEC:
                    if (!(GetTalentGroupsCount() == 1 && creature->isCanTrainingAndResetTalentsOf(this) && !(getLevel() < sWorld->getIntConfig(CONFIG_MIN_DUALSPEC_LEVEL))))
                        canTalk = false;
                    break;
                case GOSSIP_OPTION_UNLEARNTALENTS:
                    if (!creature->isCanTrainingAndResetTalentsOf(this))
                        canTalk = false;
                    break;
                case GOSSIP_OPTION_UNLEARNPETTALENTS:
                    if (!GetPet() || GetPet()->getPetType() != HUNTER_PET || GetPet()->m_spells.size() <= 1 || creature->GetCreatureTemplate()->trainer_type != TRAINER_TYPE_PETS || creature->GetCreatureTemplate()->trainer_class != CLASS_HUNTER)
                        canTalk = false;
                    break;
                case GOSSIP_OPTION_TAXIVENDOR:
                    if (GetSession()->SendLearnNewTaxiNode(creature))
                        return;
                    break;
                case GOSSIP_OPTION_BATTLEFIELD:
                    if (!creature->isCanInteractWithBattleMaster(this, false))
                        canTalk = false;
                    break;
                case GOSSIP_OPTION_STABLEPET:
                    if (getClass() != CLASS_HUNTER)
                        canTalk = false;
                    break;
                case GOSSIP_OPTION_QUESTGIVER:
                    canTalk = false;
                    break;
                case GOSSIP_OPTION_TRAINER:
                    if (getClass() != creature->GetCreatureTemplate()->trainer_class && creature->GetCreatureTemplate()->trainer_type == TRAINER_TYPE_CLASS)
                    {
                        TC_LOG_ERROR("sql.sql", "GOSSIP_OPTION_TRAINER:: Player %s (%s) request wrong gossip menu: %u with wrong class: %u at Creature: %s (Entry: %u, Trainer Class: %u)",
                            GetName().c_str(), GetGUID().ToString().c_str(), menu->GetGossipMenu().GetMenuId(), getClass(),
                            creature->GetName().c_str(), creature->GetEntry(), creature->GetCreatureTemplate()->trainer_class);
                    }
                    // no break;
                case GOSSIP_OPTION_GOSSIP:
                case GOSSIP_OPTION_SPIRITGUIDE:
                case GOSSIP_OPTION_INNKEEPER:
                case GOSSIP_OPTION_BANKER:
                case GOSSIP_OPTION_PETITIONER:
                case GOSSIP_OPTION_TABARDDESIGNER:
                case GOSSIP_OPTION_AUCTIONEER:
                    break;                                  // no checks
                case GOSSIP_OPTION_OUTDOORPVP:
                    if (!sOutdoorPvPMgr->CanTalkTo(this, creature, itr->second))
                        canTalk = false;
                    break;
                default:
                    TC_LOG_ERROR("sql.sql", "Creature entry %u has unknown gossip option %u for menu %u", creature->GetEntry(), itr->second.OptionType, itr->second.MenuId);
                    canTalk = false;
                    break;
            }
        }
        else if (GameObject* go = source->ToGameObject())
        {
            switch (itr->second.OptionType)
            {
                case GOSSIP_OPTION_GOSSIP:
                    if (go->GetGoType() != GAMEOBJECT_TYPE_QUESTGIVER && go->GetGoType() != GAMEOBJECT_TYPE_GOOBER)
                        canTalk = false;
                    break;
                default:
                    canTalk = false;
                    break;
            }
        }

        if (canTalk)
        {
            std::string strOptionText, strBoxText;
            BroadcastTextEntry const* optionBroadcastText = sBroadcastTextStore.LookupEntry(itr->second.OptionBroadcastTextId);
            BroadcastTextEntry const* boxBroadcastText = sBroadcastTextStore.LookupEntry(itr->second.BoxBroadcastTextId);
            LocaleConstant locale = GetSession()->GetSessionDbLocaleIndex();

            if (optionBroadcastText)
                strOptionText = DB2Manager::GetBroadcastTextValue(optionBroadcastText, locale, getGender());
            else
                strOptionText = itr->second.OptionText;

            if (boxBroadcastText)
                strBoxText = DB2Manager::GetBroadcastTextValue(boxBroadcastText, locale, getGender());
            else
                strBoxText = itr->second.BoxText;

            if (locale != DEFAULT_LOCALE)
            {
                if (!optionBroadcastText)
                {
                    /// Find localizations from database.
                    if (GossipMenuItemsLocale const* gossipMenuLocale = sObjectMgr->GetGossipMenuItemsLocale(MAKE_PAIR32(menuId, itr->second.OptionIndex)))
                        ObjectMgr::GetLocaleString(gossipMenuLocale->OptionText, locale, strOptionText);
                }

                if (!boxBroadcastText)
                {
                    /// Find localizations from database.
                    if (GossipMenuItemsLocale const* gossipMenuLocale = sObjectMgr->GetGossipMenuItemsLocale(MAKE_PAIR32(menuId, itr->second.OptionIndex)))
                        ObjectMgr::GetLocaleString(gossipMenuLocale->BoxText, locale, strBoxText);
                }
            }

            menu->GetGossipMenu().AddMenuItem(itr->second.OptionIndex, itr->second.OptionIcon, strOptionText, 0, itr->second.OptionType, strBoxText, itr->second.BoxMoney, itr->second.BoxCoded);
            menu->GetGossipMenu().AddGossipMenuItemData(itr->second.OptionIndex, itr->second.ActionMenuId, itr->second.ActionPoiId);
        }
    }
}

void Player::SendPreparedGossip(WorldObject* source)
{
    if (!source)
        return;

    if (source->GetTypeId() == TYPEID_UNIT || source->GetTypeId() == TYPEID_GAMEOBJECT)
    {
        if (PlayerTalkClass->GetGossipMenu().Empty() && !PlayerTalkClass->GetQuestMenu().Empty())
        {
            SendPreparedQuest(source->GetGUID());
            return;
        }
    }

    // in case non empty gossip menu (that not included quests list size) show it
    // (quest entries from quest menu will be included in list)

    uint32 textId = GetGossipTextId(source);

    if (uint32 menuId = PlayerTalkClass->GetGossipMenu().GetMenuId())
        textId = GetGossipTextId(menuId, source);

    PlayerTalkClass->SendGossipMenu(textId, source->GetGUID());
}

void Player::OnGossipSelect(WorldObject* source, uint32 gossipListId, uint32 menuId)
{
    GossipMenu& gossipMenu = PlayerTalkClass->GetGossipMenu();

    // if not same, then something funky is going on
    if (menuId != gossipMenu.GetMenuId())
        return;

    GossipMenuItem const* item = gossipMenu.GetItem(gossipListId);
    if (!item)
        return;

    uint32 gossipOptionId = item->OptionType;
    ObjectGuid guid = source->GetGUID();

    if (source->GetTypeId() == TYPEID_GAMEOBJECT)
    {
        if (gossipOptionId > GOSSIP_OPTION_QUESTGIVER)
        {
            TC_LOG_ERROR("entities.player", "Player '%s' (%s) requests invalid gossip option for GameObject (Entry: %u)",
                GetName().c_str(), GetGUID().ToString().c_str(), source->GetEntry());
            return;
        }
    }

    GossipMenuItemData const* menuItemData = gossipMenu.GetItemData(gossipListId);
    if (!menuItemData)
        return;

    int32 cost = int32(item->BoxMoney);
    if (!HasEnoughMoney(int64(cost)))
    {
        SendBuyError(BUY_ERR_NOT_ENOUGHT_MONEY, nullptr, 0, 0);
        PlayerTalkClass->SendCloseGossip();
        return;
    }

    switch (gossipOptionId)
    {
        case GOSSIP_OPTION_GOSSIP:
        {
            if (menuItemData->GossipActionPoi)
                PlayerTalkClass->SendPointOfInterest(menuItemData->GossipActionPoi);

            if (menuItemData->GossipActionMenuId)
            {
                PrepareGossipMenu(source, menuItemData->GossipActionMenuId);
                SendPreparedGossip(source);
            }

            break;
        }
        case GOSSIP_OPTION_OUTDOORPVP:
            sOutdoorPvPMgr->HandleGossipOption(this, source->ToCreature(), gossipListId);
            break;
        case GOSSIP_OPTION_SPIRITHEALER:
            if (isDead())
                source->ToCreature()->CastSpell(source->ToCreature(), 17251, true, nullptr, nullptr, GetGUID());
            break;
        case GOSSIP_OPTION_QUESTGIVER:
            PrepareQuestMenu(guid);
            SendPreparedQuest(guid);
            break;
        case GOSSIP_OPTION_VENDOR:
        case GOSSIP_OPTION_ARMORER:
            GetSession()->SendListInventory(guid);
            break;
        case GOSSIP_OPTION_STABLEPET:
            GetSession()->SendStablePet(guid);
            break;
        case GOSSIP_OPTION_TRAINER:
            GetSession()->SendTrainerList(guid);
            break;
        case GOSSIP_OPTION_LEARNDUALSPEC:
            if (GetTalentGroupsCount() == 1 && getLevel() >= sWorld->getIntConfig(CONFIG_MIN_DUALSPEC_LEVEL))
            {
                // Cast spells that teach dual spec
                // Both are also ImplicitTarget self and must be cast by player
                CastSpell(this, 63680, true, nullptr, nullptr, GetGUID());
                CastSpell(this, 63624, true, nullptr, nullptr, GetGUID());

                // Should show another Gossip text with "Congratulations..."
                PlayerTalkClass->SendCloseGossip();
            }
            break;
        case GOSSIP_OPTION_UNLEARNTALENTS:
            PlayerTalkClass->SendCloseGossip();
            SendRespecWipeConfirm(guid, sWorld->getBoolConfig(CONFIG_NO_RESET_TALENT_COST) ? 0 : GetNextResetTalentsCost());
            break;
        case GOSSIP_OPTION_UNLEARNPETTALENTS:
            PlayerTalkClass->SendCloseGossip();
            ResetPetTalents();
            break;
        case GOSSIP_OPTION_TAXIVENDOR:
            GetSession()->SendTaxiMenu(source->ToCreature());
            break;
        case GOSSIP_OPTION_INNKEEPER:
            PlayerTalkClass->SendCloseGossip();
            SetBindPoint(guid);
            break;
        case GOSSIP_OPTION_BANKER:
            GetSession()->SendShowBank(guid);
            break;
        case GOSSIP_OPTION_PETITIONER:
            PlayerTalkClass->SendCloseGossip();
            GetSession()->SendPetitionShowList(guid);
            break;
        case GOSSIP_OPTION_TABARDDESIGNER:
            PlayerTalkClass->SendCloseGossip();
            GetSession()->SendTabardVendorActivate(guid);
            break;
        case GOSSIP_OPTION_AUCTIONEER:
            GetSession()->SendAuctionHello(guid, source->ToCreature());
            break;
        case GOSSIP_OPTION_SPIRITGUIDE:
            PrepareGossipMenu(source);
            SendPreparedGossip(source);
            break;
        case GOSSIP_OPTION_BATTLEFIELD:
        {
            BattlegroundTypeId bgTypeId = sBattlegroundMgr->GetBattleMasterBG(source->GetEntry());

            if (bgTypeId == BATTLEGROUND_TYPE_NONE)
            {
                TC_LOG_ERROR("entities.player", "Player '%s' (%s) requested battlegroundlist from an invalid creature (%s)",
                    GetName().c_str(), GetGUID().ToString().c_str(), source->GetGUID().ToString().c_str());
                return;
            }

            sBattlegroundMgr->SendBattlegroundList(this, guid, bgTypeId);
            break;
        }
    }

    ModifyMoney(-cost);
}

uint32 Player::GetGossipTextId(WorldObject* source)
{
    if (!source)
        return DEFAULT_GOSSIP_MESSAGE;

    return GetGossipTextId(GetDefaultGossipMenuForSource(source), source);
}

uint32 Player::GetGossipTextId(uint32 menuId, WorldObject* source)
{
    uint32 textId = DEFAULT_GOSSIP_MESSAGE;

    if (!menuId)
        return textId;

    GossipMenusMapBounds menuBounds = sObjectMgr->GetGossipMenusMapBounds(menuId);

    for (GossipMenusContainer::const_iterator itr = menuBounds.first; itr != menuBounds.second; ++itr)
    {
        if (sConditionMgr->IsObjectMeetToConditions(this, source, itr->second.conditions))
            textId = itr->second.text_id;
    }

    return textId;
}

uint32 Player::GetDefaultGossipMenuForSource(WorldObject* source)
{
    switch (source->GetTypeId())
    {
        case TYPEID_UNIT:
            return source->ToCreature()->GetCreatureTemplate()->GossipMenuId;
        case TYPEID_GAMEOBJECT:
            return source->ToGameObject()->GetGOInfo()->GetGossipMenuId();
        default:
            break;
    }

    return 0;
}

/*********************************************************/
/***                    QUEST SYSTEM                   ***/
/*********************************************************/

void Player::PrepareQuestMenu(ObjectGuid guid)
{
    QuestRelationBounds objectQR;
    QuestRelationBounds objectQIR;

    // pets also can have quests
    Creature* creature = ObjectAccessor::GetCreatureOrPetOrVehicle(*this, guid);
    if (creature)
    {
        objectQR  = sObjectMgr->GetCreatureQuestRelationBounds(creature->GetEntry());
        objectQIR = sObjectMgr->GetCreatureQuestInvolvedRelationBounds(creature->GetEntry());
    }
    else
    {
        //we should obtain map pointer from GetMap() in 99% of cases. Special case
        //only for quests which cast teleport spells on player
        Map* _map = IsInWorld() ? GetMap() : sMapMgr->FindMap(GetMapId(), GetInstanceId());
        ASSERT(_map);
        GameObject* gameObject = _map->GetGameObject(guid);
        if (gameObject)
        {
            objectQR  = sObjectMgr->GetGOQuestRelationBounds(gameObject->GetEntry());
            objectQIR = sObjectMgr->GetGOQuestInvolvedRelationBounds(gameObject->GetEntry());
        }
        else
            return;
    }

    QuestMenu &qm = PlayerTalkClass->GetQuestMenu();
    qm.ClearMenu();

    for (QuestRelations::const_iterator i = objectQIR.first; i != objectQIR.second; ++i)
    {
        uint32 quest_id = i->second;
        QuestStatus status = GetQuestStatus(quest_id);
        if (status == QUEST_STATUS_COMPLETE)
            qm.AddMenuItem(quest_id, 4);
        else if (status == QUEST_STATUS_INCOMPLETE)
            qm.AddMenuItem(quest_id, 4);
        //else if (status == QUEST_STATUS_AVAILABLE)
        //    qm.AddMenuItem(quest_id, 2);
    }

    for (QuestRelations::const_iterator i = objectQR.first; i != objectQR.second; ++i)
    {
        uint32 quest_id = i->second;
        Quest const* quest = sObjectMgr->GetQuestTemplate(quest_id);
        if (!quest)
            continue;

        if (!CanTakeQuest(quest, false))
            continue;

        if (quest->IsAutoComplete())
            qm.AddMenuItem(quest_id, 4);
        else if (GetQuestStatus(quest_id) == QUEST_STATUS_NONE)
            qm.AddMenuItem(quest_id, 2);
    }
}

void Player::SendPreparedQuest(ObjectGuid guid)
{
    QuestMenu& questMenu = PlayerTalkClass->GetQuestMenu();
    if (questMenu.Empty())
        return;

    // single element case
    if (questMenu.GetMenuItemCount() == 1)
    {
        QuestMenuItem const& qmi0 = questMenu.GetItem(0);
        uint32 questId = qmi0.QuestId;

        // Auto open
        if (Quest const* quest = sObjectMgr->GetQuestTemplate(questId))
        {
            if (qmi0.QuestIcon == 4)
            {
                PlayerTalkClass->SendQuestGiverRequestItems(quest, guid, CanRewardQuest(quest, false), true);
                return;
            }
            // Send completable on repeatable and autoCompletable quest if player don't have quest
            /// @todo verify if check for !quest->IsDaily() is really correct (possibly not)
            else
            {
                Object* object = ObjectAccessor::GetObjectByTypeMask(*this, guid, TYPEMASK_UNIT | TYPEMASK_GAMEOBJECT | TYPEMASK_ITEM);
                if (!object || (!object->hasQuest(questId) && !object->hasInvolvedQuest(questId)))
                {
                    PlayerTalkClass->SendCloseGossip();
                    return;
                }

                if (object->GetTypeId() != TYPEID_UNIT || object->GetUInt64Value(UNIT_NPC_FLAGS) & UNIT_NPC_FLAG_GOSSIP)
                {
                    if (quest->IsAutoAccept() && CanAddQuest(quest, true) && CanTakeQuest(quest, true))
                        AddQuestAndCheckCompletion(quest, object);

                    if (quest->IsAutoComplete() && quest->IsRepeatable() && !quest->IsDailyOrWeekly())
                        PlayerTalkClass->SendQuestGiverRequestItems(quest, guid, CanCompleteRepeatableQuest(quest), true);
                    else
                        PlayerTalkClass->SendQuestGiverQuestDetails(quest, guid, true);
                    return;
                }
            }
        }
    }

    PlayerTalkClass->SendQuestGiverQuestList(guid);
}

bool Player::IsActiveQuest(uint32 quest_id) const
{
    return m_QuestStatus.find(quest_id) != m_QuestStatus.end();
}

Quest const* Player::GetNextQuest(ObjectGuid guid, Quest const* quest) const
{
    QuestRelationBounds objectQR;
    uint32 nextQuestID = quest->GetNextQuestInChain();

    switch (guid.GetHigh())
    {
        case HighGuid::Player:
            ASSERT(quest->HasFlag(QUEST_FLAGS_AUTOCOMPLETE));
            return sObjectMgr->GetQuestTemplate(nextQuestID);
        case HighGuid::Creature:
        case HighGuid::Pet:
        case HighGuid::Vehicle:
        {
            if (Creature* creature = ObjectAccessor::GetCreatureOrPetOrVehicle(*this, guid))
                objectQR  = sObjectMgr->GetCreatureQuestRelationBounds(creature->GetEntry());
            else
                return nullptr;
            break;
        }
        case HighGuid::GameObject:
        {
            //we should obtain map pointer from GetMap() in 99% of cases. Special case
            //only for quests which cast teleport spells on player
            Map* _map = IsInWorld() ? GetMap() : sMapMgr->FindMap(GetMapId(), GetInstanceId());
            ASSERT(_map);
            if (GameObject* gameObject = _map->GetGameObject(guid))
                objectQR = sObjectMgr->GetGOQuestRelationBounds(gameObject->GetEntry());
            else
                return nullptr;
            break;
        }
        default:
            return nullptr;
    }

    // for unit and go state
    for (QuestRelations::const_iterator itr = objectQR.first; itr != objectQR.second; ++itr)
    {
        if (itr->second == nextQuestID)
            return sObjectMgr->GetQuestTemplate(nextQuestID);
    }

    return nullptr;
}

bool Player::CanSeeStartQuest(Quest const* quest)
{
    if (!DisableMgr::IsDisabledFor(DISABLE_TYPE_QUEST, quest->GetQuestId(), this) && SatisfyQuestClass(quest, false) && SatisfyQuestRace(quest, false) &&
        SatisfyQuestSkill(quest, false) && SatisfyQuestExclusiveGroup(quest, false) && SatisfyQuestReputation(quest, false) &&
        SatisfyQuestPreviousQuest(quest, false) && SatisfyQuestNextChain(quest, false) &&
        SatisfyQuestPrevChain(quest, false) && SatisfyQuestDay(quest, false) && SatisfyQuestWeek(quest, false) &&
        SatisfyQuestMonth(quest, false) && SatisfyQuestSeasonal(quest, false))
    {
        return int32(getLevel() + sWorld->getIntConfig(CONFIG_QUEST_HIGH_LEVEL_HIDE_DIFF)) >= quest->GetMinLevel();
    }

    return false;
}

bool Player::CanTakeQuest(Quest const* quest, bool msg)
{
    return !DisableMgr::IsDisabledFor(DISABLE_TYPE_QUEST, quest->GetQuestId(), this)
        && SatisfyQuestStatus(quest, msg) && SatisfyQuestExclusiveGroup(quest, msg)
        && SatisfyQuestClass(quest, msg) && SatisfyQuestRace(quest, msg) && SatisfyQuestLevel(quest, msg)
        && SatisfyQuestSkill(quest, msg) && SatisfyQuestReputation(quest, msg)
        && SatisfyQuestPreviousQuest(quest, msg) && SatisfyQuestTimed(quest, msg)
        && SatisfyQuestNextChain(quest, msg) && SatisfyQuestPrevChain(quest, msg)
        && SatisfyQuestDay(quest, msg) && SatisfyQuestWeek(quest, msg)
        && SatisfyQuestMonth(quest, msg) && SatisfyQuestSeasonal(quest, msg)
        && SatisfyQuestConditions(quest, msg);
}

bool Player::CanAddQuest(Quest const* quest, bool msg) const
{
    if (!SatisfyQuestLog(msg))
        return false;

    uint32 srcitem = quest->GetSrcItemId();
    if (srcitem > 0)
    {
        uint32 count = quest->GetSrcItemCount();
        ItemPosCountVec dest;
        InventoryResult msg2 = CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, srcitem, count);

        // player already have max number (in most case 1) source item, no additional item needed and quest can be added.
        if (msg2 == EQUIP_ERR_ITEM_MAX_COUNT)
            return true;
        if (msg2 != EQUIP_ERR_OK)
        {
            SendEquipError(msg2, nullptr, nullptr, srcitem);
            return false;
        }
    }
    return true;
}

bool Player::CanCompleteQuest(uint32 quest_id)
{
    if (quest_id)
    {
        Quest const* qInfo = sObjectMgr->GetQuestTemplate(quest_id);
        if (!qInfo)
            return false;

        if (!qInfo->IsRepeatable() && m_RewardedQuests.find(quest_id) != m_RewardedQuests.end())
            return false;                                   // not allow re-complete quest

        // auto complete quest
        if (qInfo->IsAutoComplete() && CanTakeQuest(qInfo, false))
            return true;

        QuestStatusMap::iterator itr = m_QuestStatus.find(quest_id);
        if (itr == m_QuestStatus.end())
            return false;

        QuestStatusData &q_status = itr->second;

        if (q_status.Status == QUEST_STATUS_INCOMPLETE)
        {
            for (QuestObjective const& obj : qInfo->GetObjectives())
            {
                switch (obj.Type)
                {
                    case QUEST_OBJECTIVE_MONSTER:
                    case QUEST_OBJECTIVE_ITEM:
                    case QUEST_OBJECTIVE_GAMEOBJECT:
                    case QUEST_OBJECTIVE_PLAYERKILLS:
                    case QUEST_OBJECTIVE_TALKTO:
                    case QUEST_OBJECTIVE_WINPVPPETBATTLES:
                    case QUEST_OBJECTIVE_HAVE_CURRENCY:
                    case QUEST_OBJECTIVE_OBTAIN_CURRENCY:
                        if (GetQuestObjectiveData(qInfo, obj.StorageIndex) < obj.Amount)
                            return false;
                        break;
                    case QUEST_OBJECTIVE_MIN_REPUTATION:
                        if (GetReputationMgr().GetReputation(obj.ObjectID) < obj.Amount)
                            return false;
                        break;
                    case QUEST_OBJECTIVE_MAX_REPUTATION:
                        if (GetReputationMgr().GetReputation(obj.ObjectID) > obj.Amount)
                            return false;
                        break;
                    case QUEST_OBJECTIVE_MONEY:
                        if (!HasEnoughMoney(uint64(obj.Amount)))
                            return false;
                        break;
                    case QUEST_OBJECTIVE_AREATRIGGER:
                        if (!GetQuestObjectiveData(qInfo, obj.StorageIndex))
                            return false;
                        break;
                    case QUEST_OBJECTIVE_LEARNSPELL:
                        if (!HasSpell(obj.ObjectID))
                            return false;
                        break;
                    case QUEST_OBJECTIVE_CURRENCY:
                        if (!HasCurrency(obj.ObjectID, obj.Amount))
                            return false;
                        break;
                    default:
                        TC_LOG_ERROR("entities.player.quest", "Player::CanCompleteQuest: Player '%s' (%s) tried to complete a quest (ID: %u) with an unknown objective type %u",
                            GetName().c_str(), GetGUID().ToString().c_str(), quest_id, obj.Type);
                        return false;
                }
            }

            if (qInfo->HasSpecialFlag(QUEST_SPECIAL_FLAGS_TIMED) && q_status.Timer == 0)
                return false;

            return true;
        }
    }
    return false;
}

bool Player::CanCompleteRepeatableQuest(Quest const* quest)
{
    // Solve problem that player don't have the quest and try complete it.
    // if repeatable she must be able to complete event if player don't have it.
    // Seem that all repeatable quest are DELIVER Flag so, no need to add more.
    if (!CanTakeQuest(quest, false))
        return false;

    if (quest->HasSpecialFlag(QUEST_SPECIAL_FLAGS_DELIVER))
        for (QuestObjective const& obj : quest->GetObjectives())
            if (obj.Type == QUEST_OBJECTIVE_ITEM && !HasItemCount(obj.ObjectID, obj.Amount))
                return false;

    if (!CanRewardQuest(quest, false))
        return false;

    return true;
}

bool Player::CanRewardQuest(Quest const* quest, bool msg)
{
    // not auto complete quest and not completed quest (only cheating case, then ignore without message)
    if (!quest->IsDFQuest() && !quest->IsAutoComplete() && GetQuestStatus(quest->GetQuestId()) != QUEST_STATUS_COMPLETE)
        return false;

    // daily quest can't be rewarded (25 daily quest already completed)
    if (!SatisfyQuestDay(quest, true) || !SatisfyQuestWeek(quest, true) || !SatisfyQuestMonth(quest, true) || !SatisfyQuestSeasonal(quest, true))
        return false;

    // rewarded and not repeatable quest (only cheating case, then ignore without message)
    if (GetQuestRewardStatus(quest->GetQuestId()))
        return false;

    // prevent receive reward with quest items in bank
    if (quest->HasSpecialFlag(QUEST_SPECIAL_FLAGS_DELIVER))
    {
        for (QuestObjective const& obj : quest->GetObjectives())
        {
            if (obj.Type != QUEST_OBJECTIVE_ITEM)
                continue;

            if (GetItemCount(obj.ObjectID) < uint32(obj.Amount))
            {
                if (msg)
                    SendEquipError(EQUIP_ERR_ITEM_NOT_FOUND, nullptr, nullptr, obj.ObjectID);
                return false;
            }
        }
    }

    for (QuestObjective const& obj : quest->GetObjectives())
    {
        switch (obj.Type)
        {
            case QUEST_OBJECTIVE_CURRENCY:
                if (!HasCurrency(obj.ObjectID, obj.Amount))
                    return false;
                break;
            case QUEST_OBJECTIVE_MONEY:
                if (!HasEnoughMoney(uint64(obj.Amount)))
                    return false;
                break;
        }
    }

    return true;
}

void Player::AddQuestAndCheckCompletion(Quest const* quest, Object* questGiver)
{
    AddQuest(quest, questGiver);

    if (CanCompleteQuest(quest->GetQuestId()))
        CompleteQuest(quest->GetQuestId());

    if (!questGiver)
        return;

    switch (questGiver->GetTypeId())
    {
        case TYPEID_UNIT:
            sScriptMgr->OnQuestAccept(this, questGiver->ToCreature(), quest);
            questGiver->ToCreature()->AI()->sQuestAccept(this, quest);
            break;
        case TYPEID_ITEM:
        case TYPEID_CONTAINER:
        {
            Item* item = static_cast<Item*>(questGiver);
            sScriptMgr->OnQuestAccept(this, item, quest);

            // destroy not required for quest finish quest starting item
            bool destroyItem = true;
            for (QuestObjective const& obj : quest->GetObjectives())
            {
                if (obj.Type == QUEST_OBJECTIVE_ITEM && uint32(obj.ObjectID) == item->GetEntry() && item->GetTemplate()->GetMaxCount() > 0)
                {
                    destroyItem = false;
                    break;
                }
            }

            if (destroyItem)
                DestroyItem(item->GetBagSlot(), item->GetSlot(), true);

            break;
        }
        case TYPEID_GAMEOBJECT:
            sScriptMgr->OnQuestAccept(this, questGiver->ToGameObject(), quest);
            questGiver->ToGameObject()->AI()->QuestAccept(this, quest);
            break;
        default:
            break;
    }
}

bool Player::CanRewardQuest(Quest const* quest, uint32 reward, bool msg)
{
    // prevent receive reward with quest items in bank or for not completed quest
    if (!CanRewardQuest(quest, msg))
        return false;

    ItemPosCountVec dest;
    if (quest->GetRewChoiceItemsCount() > 0)
    {
        for (uint32 i = 0; i < quest->GetRewChoiceItemsCount(); ++i)
        {
            if (quest->RewardChoiceItemId[i] && quest->RewardChoiceItemId[i] == reward)
            {
                InventoryResult res = CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, quest->RewardChoiceItemId[i], quest->RewardChoiceItemCount[i]);
                if (res != EQUIP_ERR_OK)
                {
                    SendEquipError(res, nullptr, nullptr, quest->RewardChoiceItemId[i]);
                    return false;
                }
            }
        }
    }

    if (quest->GetRewItemsCount() > 0)
    {
        for (uint32 i = 0; i < quest->GetRewItemsCount(); ++i)
        {
            if (quest->RewardItemId[i])
            {
                InventoryResult res = CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, quest->RewardItemId[i], quest->RewardItemCount[i]);
                if (res != EQUIP_ERR_OK)
                {
                    SendEquipError(res, nullptr, nullptr, quest->RewardItemId[i]);
                    return false;
                }
            }
        }
    }

    // QuestPackageItem.db2
    if (quest->GetQuestPackageID())
    {
        if (std::vector<QuestPackageItemEntry const*> const* questPackageItems = sDB2Manager.GetQuestPackageItems(quest->GetQuestPackageID()))
        {
            for (QuestPackageItemEntry const* questPackageItem : *questPackageItems)
            {
                if (questPackageItem->ItemID != reward)
                    continue;

                if (ItemTemplate const* rewardProto = sObjectMgr->GetItemTemplate(questPackageItem->ItemID))
                {
                    if (rewardProto->CanWinForPlayer(this))
                    {
                        InventoryResult res = CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, questPackageItem->ItemID, questPackageItem->ItemCount);
                        if (res != EQUIP_ERR_OK)
                        {
                            SendEquipError(res, nullptr, nullptr, questPackageItem->ItemID);
                            return false;
                        }
                    }
                }
            }
        }
    }

    return true;
}

void Player::AddQuest(Quest const* quest, Object* questGiver)
{
    uint16 log_slot = FindQuestSlot(0);

    if (log_slot >= MAX_QUEST_LOG_SIZE) // Player does not have any free slot in the quest log
        return;

    uint32 quest_id = quest->GetQuestId();

    // if not exist then created with set uState == NEW and rewarded=false
    QuestStatusData& questStatusData = m_QuestStatus[quest_id];

    // check for repeatable quests status reset
    questStatusData.Status = QUEST_STATUS_INCOMPLETE;

    int32 maxStorageIndex = 0;
    for (QuestObjective const& obj : quest->GetObjectives())
        if (obj.StorageIndex > maxStorageIndex)
            maxStorageIndex = obj.StorageIndex;

    questStatusData.ObjectiveData.resize(maxStorageIndex+1, 0);

    GiveQuestSourceItem(quest);
    AdjustQuestReqItemCount(quest);

    for (QuestObjective const& obj : quest->GetObjectives())
        if (obj.Type == QUEST_OBJECTIVE_MIN_REPUTATION || obj.Type == QUEST_OBJECTIVE_MAX_REPUTATION)
            if (FactionEntry const* factionEntry = sFactionStore.LookupEntry(obj.ObjectID))
                GetReputationMgr().SetVisible(factionEntry);

    uint32 qtime = 0;
    if (quest->HasSpecialFlag(QUEST_SPECIAL_FLAGS_TIMED))
    {
        uint32 limittime = quest->GetLimitTime();

        // shared timed quest
        if (questGiver && questGiver->GetTypeId() == TYPEID_PLAYER)
            limittime = questGiver->ToPlayer()->getQuestStatusMap()[quest_id].Timer / IN_MILLISECONDS;

        AddTimedQuest(quest_id);
        questStatusData.Timer = limittime * IN_MILLISECONDS;
        qtime = static_cast<uint32>(time(nullptr)) + limittime;
    }
    else
        questStatusData.Timer = 0;

    if (quest->HasFlag(QUEST_FLAGS_FLAGS_PVP))
    {
        pvpInfo.IsHostile = true;
        UpdatePvPState();
    }

    SetQuestSlot(log_slot, quest_id, qtime);

    m_QuestStatusSave[quest_id] = QUEST_DEFAULT_SAVE_TYPE;

    StartTimedAchievement(ACHIEVEMENT_TIMED_TYPE_QUEST, quest_id);

    SendQuestUpdate(quest_id);

    if (sWorld->getBoolConfig(CONFIG_QUEST_ENABLE_QUEST_TRACKER)) // check if Quest Tracker is enabled
    {
        // prepare Quest Tracker datas
        PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_QUEST_TRACK);
        stmt->setUInt32(0, quest_id);
        stmt->setUInt64(1, GetGUID().GetCounter());
        stmt->setString(2, GitRevision::GetHash());
        stmt->setString(3, GitRevision::GetDate());

        // add to Quest Tracker
        CharacterDatabase.Execute(stmt);
    }
}

void Player::CompleteQuest(uint32 quest_id)
{
    if (quest_id)
    {
        SetQuestStatus(quest_id, QUEST_STATUS_COMPLETE);

        uint16 log_slot = FindQuestSlot(quest_id);
        if (log_slot < MAX_QUEST_LOG_SIZE)
            SetQuestSlotState(log_slot, QUEST_STATE_COMPLETE);

        if (Quest const* qInfo = sObjectMgr->GetQuestTemplate(quest_id))
        {
            if (qInfo->HasFlag(QUEST_FLAGS_TRACKING))
                RewardQuest(qInfo, 0, this, false);
            else
                SendQuestComplete(qInfo);
        }
    }

    if (sWorld->getBoolConfig(CONFIG_QUEST_ENABLE_QUEST_TRACKER)) // check if Quest Tracker is enabled
    {
        // prepare Quest Tracker data
        PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_QUEST_TRACK_COMPLETE_TIME);
        stmt->setUInt32(0, quest_id);
        stmt->setUInt64(1, GetGUID().GetCounter());

        // add to Quest Tracker
        CharacterDatabase.Execute(stmt);
    }
}

void Player::IncompleteQuest(uint32 quest_id)
{
    if (quest_id)
    {
        SetQuestStatus(quest_id, QUEST_STATUS_INCOMPLETE);

        uint16 log_slot = FindQuestSlot(quest_id);
        if (log_slot < MAX_QUEST_LOG_SIZE)
            RemoveQuestSlotState(log_slot, QUEST_STATE_COMPLETE);
    }
}

uint32 Player::GetQuestMoneyReward(Quest const* quest) const
{
    return quest->MoneyValue(getLevel()) * sWorld->getRate(RATE_MONEY_QUEST);
}

uint32 Player::GetQuestXPReward(Quest const* quest)
{
    bool rewarded = (m_RewardedQuests.find(quest->GetQuestId()) != m_RewardedQuests.end());

    // Not give XP in case already completed once repeatable quest
    if (rewarded && !quest->IsDFQuest())
        return 0;

    uint32 XP = quest->XPValue(getLevel()) * sWorld->getRate(RATE_XP_QUEST);

    // handle SPELL_AURA_MOD_XP_QUEST_PCT auras
    Unit::AuraEffectList const& ModXPPctAuras = GetAuraEffectsByType(SPELL_AURA_MOD_XP_QUEST_PCT);
    for (Unit::AuraEffectList::const_iterator i = ModXPPctAuras.begin(); i != ModXPPctAuras.end(); ++i)
        AddPct(XP, (*i)->GetAmount());

    return XP;
}

void Player::RewardQuest(Quest const* quest, uint32 reward, Object* questGiver, bool announce)
{
    //this THING should be here to protect code from quest, which cast on player far teleport as a reward
    //should work fine, cause far teleport will be executed in Player::Update()
    SetCanDelayTeleport(true);

    uint32 quest_id = quest->GetQuestId();

    for (QuestObjective const& obj : quest->GetObjectives())
    {
        switch (obj.Type)
        {
            case QUEST_OBJECTIVE_ITEM:
                if (!(quest->GetFlagsEx() & QUEST_FLAGS_EX_KEEP_ADDITIONAL_ITEMS))
                    DestroyItemCount(obj.ObjectID, obj.Amount, true);
                break;
            case QUEST_OBJECTIVE_CURRENCY:
                ModifyCurrency(obj.ObjectID, -int32(obj.Amount), false, true);
                break;
        }
    }

    if (!(quest->GetFlagsEx() & QUEST_FLAGS_EX_KEEP_ADDITIONAL_ITEMS))
    {
        for (uint8 i = 0; i < QUEST_ITEM_DROP_COUNT; ++i)
        {
            if (quest->ItemDrop[i])
            {
                uint32 count = quest->ItemDropQuantity[i];
                DestroyItemCount(quest->ItemDrop[i], count ? count : 9999, true);
            }
        }
    }

    RemoveTimedQuest(quest_id);

    if (quest->GetRewChoiceItemsCount() > 0)
    {
        for (uint32 i = 0; i < quest->GetRewChoiceItemsCount(); ++i)
        {
            if (quest->RewardChoiceItemId[i] && quest->RewardChoiceItemId[i] == reward)
            {
                ItemPosCountVec dest;
                if (CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, reward, quest->RewardChoiceItemCount[i]) == EQUIP_ERR_OK)
                {
                    Item* item = StoreNewItem(dest, reward, true, Item::GenerateItemRandomPropertyId(reward));
                    SendNewItem(item, quest->RewardChoiceItemCount[i], true, false);
                }
            }
        }
    }

    // QuestPackageItem.db2
    if (quest->GetQuestPackageID())
    {
        if (std::vector<QuestPackageItemEntry const*> const* questPackageItems = sDB2Manager.GetQuestPackageItems(quest->GetQuestPackageID()))
        {
            for (QuestPackageItemEntry const* questPackageItem : *questPackageItems)
            {
                if (questPackageItem->ItemID != reward)
                    continue;

                if (ItemTemplate const* rewardProto = sObjectMgr->GetItemTemplate(questPackageItem->ItemID))
                {
                    if (rewardProto->CanWinForPlayer(this))
                    {
                        ItemPosCountVec dest;
                        if (CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, questPackageItem->ItemID, questPackageItem->ItemCount) == EQUIP_ERR_OK)
                        {
                            Item* item = StoreNewItem(dest, questPackageItem->ItemID, true, Item::GenerateItemRandomPropertyId(questPackageItem->ItemID));
                            SendNewItem(item, questPackageItem->ItemCount, true, false);
                        }
                    }
                }
            }
        }
    }

    if (quest->GetRewItemsCount() > 0)
    {
        for (uint32 i = 0; i < quest->GetRewItemsCount(); ++i)
        {
            if (uint32 itemId = quest->RewardItemId[i])
            {
                ItemPosCountVec dest;
                if (CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, itemId, quest->RewardItemCount[i]) == EQUIP_ERR_OK)
                {
                    Item* item = StoreNewItem(dest, itemId, true, Item::GenerateItemRandomPropertyId(itemId));
                    SendNewItem(item, quest->RewardItemCount[i], true, false);
                }
                else if (quest->IsDFQuest())
                    SendItemRetrievalMail(quest->RewardItemId[i], quest->RewardItemCount[i]);
            }
        }
    }

    for (uint8 i = 0; i < QUEST_REWARD_CURRENCY_COUNT; ++i)
        if (quest->RewardCurrencyId[i])
            ModifyCurrency(quest->RewardCurrencyId[i], quest->RewardCurrencyCount[i]);

    if (uint32 skill = quest->GetRewardSkillId())
        UpdateSkillPro(skill, 1000, quest->GetRewardSkillPoints());

    RewardReputation(quest);

    uint16 log_slot = FindQuestSlot(quest_id);
    if (log_slot < MAX_QUEST_LOG_SIZE)
        SetQuestSlot(log_slot, 0);

    uint32 XP = GetQuestXPReward(quest);

    int32 moneyRew = 0;
    if (getLevel() < sWorld->getIntConfig(CONFIG_MAX_PLAYER_LEVEL))
        GiveXP(XP, nullptr);
    else
        moneyRew = int32(quest->GetRewMoneyMaxLevel() * sWorld->getRate(RATE_DROP_MONEY));

    moneyRew += GetQuestMoneyReward(quest);

    if (moneyRew)
    {
        ModifyMoney(moneyRew);

        if (moneyRew > 0)
            UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_MONEY_FROM_QUEST_REWARD, uint32(moneyRew));
    }

    // honor reward
    if (uint32 honor = quest->CalculateHonorGain(getLevel()))
        RewardHonor(nullptr, 0, honor);

    // title reward
    if (quest->GetRewTitle())
    {
        if (CharTitlesEntry const* titleEntry = sCharTitlesStore.LookupEntry(quest->GetRewTitle()))
            SetTitle(titleEntry);
    }

    // Send reward mail
    if (uint32 mail_template_id = quest->GetRewMailTemplateId())
    {
        /// @todo Poor design of mail system
        SQLTransaction trans = CharacterDatabase.BeginTransaction();
        MailDraft(mail_template_id).SendMailTo(trans, this, questGiver, MAIL_CHECK_MASK_HAS_BODY, quest->GetRewMailDelaySecs());
        CharacterDatabase.CommitTransaction(trans);
    }

    if (quest->IsDaily() || quest->IsDFQuest())
    {
        SetDailyQuestStatus(quest_id);
        if (quest->IsDaily())
        {
            UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_DAILY_QUEST, quest_id);
            UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_DAILY_QUEST_DAILY, quest_id);
        }
    }
    else if (quest->IsWeekly())
        SetWeeklyQuestStatus(quest_id);
    else if (quest->IsMonthly())
        SetMonthlyQuestStatus(quest_id);
    else if (quest->IsSeasonal())
        SetSeasonalQuestStatus(quest_id);

    RemoveActiveQuest(quest_id, false);
    m_RewardedQuests.insert(quest_id);
    m_RewardedQuestsSave[quest_id] = QUEST_DEFAULT_SAVE_TYPE;
    // StoreNewItem, mail reward, etc. save data directly to the database
    // to prevent exploitable data desynchronisation we save the quest status to the database too
    // (to prevent rewarding this quest another time while rewards were already given out)
    SQLTransaction trans = SQLTransaction(nullptr);
    _SaveQuestStatus(trans);

    if (announce)
        SendQuestReward(quest, XP);

    // cast spells after mark quest complete (some spells have quest completed state requirements in spell_area data)
    if (quest->GetRewSpell() > 0)
    {
        SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(quest->GetRewSpell());
        if (questGiver->isType(TYPEMASK_UNIT) && !spellInfo->HasEffect(DIFFICULTY_NONE, SPELL_EFFECT_LEARN_SPELL) && !spellInfo->HasEffect(DIFFICULTY_NONE, SPELL_EFFECT_CREATE_ITEM) && !spellInfo->HasEffect(DIFFICULTY_NONE, SPELL_EFFECT_APPLY_AURA))
        {
            if (Creature* creature = GetMap()->GetCreature(questGiver->GetGUID()))
                creature->CastSpell(this, quest->GetRewSpell(), true);
        }
        else
            CastSpell(this, quest->GetRewSpell(), true);
    }
    else if (quest->GetRewDisplaySpell() > 0)
    {
        SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(quest->GetRewDisplaySpell());
        if (questGiver->isType(TYPEMASK_UNIT) && !spellInfo->HasEffect(DIFFICULTY_NONE, SPELL_EFFECT_LEARN_SPELL) && !spellInfo->HasEffect(DIFFICULTY_NONE, SPELL_EFFECT_CREATE_ITEM))
        {
            if (Creature* creature = GetMap()->GetCreature(questGiver->GetGUID()))
                creature->CastSpell(this, quest->GetRewDisplaySpell(), true);
        }
        else
            CastSpell(this, quest->GetRewDisplaySpell(), true);
    }

    if (quest->GetZoneOrSort() > 0)
        UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_QUESTS_IN_ZONE, quest->GetZoneOrSort());
    UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_QUEST_COUNT);
    UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_QUEST, quest->GetQuestId());

    if (uint32 questBit = sDB2Manager.GetQuestUniqueBitFlag(quest_id))
        SetQuestCompletedBit(questBit, true);

    if (quest->HasFlag(QUEST_FLAGS_FLAGS_PVP))
    {
        pvpInfo.IsHostile = pvpInfo.IsInHostileArea || HasPvPForcingQuest();
        UpdatePvPState();
    }

    SendQuestUpdate(quest_id);

    //lets remove flag for delayed teleports
    SetCanDelayTeleport(false);
}

void Player::FailQuest(uint32 questId)
{

    if (Quest const* quest = sObjectMgr->GetQuestTemplate(questId))
    {
        // Already complete quests shouldn't turn failed.
        if (GetQuestStatus(questId) == QUEST_STATUS_COMPLETE && !quest->HasSpecialFlag(QUEST_SPECIAL_FLAGS_TIMED))
            return;

        SetQuestStatus(questId, QUEST_STATUS_FAILED);

        uint16 log_slot = FindQuestSlot(questId);

        if (log_slot < MAX_QUEST_LOG_SIZE)
        {
            SetQuestSlotTimer(log_slot, 1);
            SetQuestSlotState(log_slot, QUEST_STATE_FAIL);
        }

        if (quest->HasSpecialFlag(QUEST_SPECIAL_FLAGS_TIMED))
        {
            QuestStatusData& q_status = m_QuestStatus[questId];

            RemoveTimedQuest(questId);
            q_status.Timer = 0;

            SendQuestTimerFailed(questId);
        }
        else
            SendQuestFailed(questId);

        // Destroy quest items on quest failure.
        for (QuestObjective const& obj : quest->GetObjectives())
            if (obj.Type == QUEST_OBJECTIVE_ITEM)
                DestroyItemCount(obj.ObjectID, obj.Amount, true, true);
        // Destroy items received during the quest.
        for (uint8 i = 0; i < QUEST_ITEM_DROP_COUNT; ++i)
            if (quest->ItemDrop[i] && quest->ItemDropQuantity[i])
                DestroyItemCount(quest->ItemDrop[i], quest->ItemDropQuantity[i], true, true);
    }
}

bool Player::SatisfyQuestSkill(Quest const* qInfo, bool msg) const
{
    uint32 skill = qInfo->GetRequiredSkill();

    // skip 0 case RequiredSkill
    if (skill == 0)
        return true;

    // check skill value
    if (GetSkillValue(skill) < qInfo->GetRequiredSkillValue())
    {
        if (msg)
        {
            SendCanTakeQuestResponse(QUEST_ERR_NONE);
            TC_LOG_DEBUG("misc", "Player::SatisfyQuestSkill: Sent QUEST_ERR_NONE (QuestID: %u) because player '%s' (%s) doesn't have the required skill value.",
                qInfo->GetQuestId(), GetName().c_str(), GetGUID().ToString().c_str());
        }

        return false;
    }

    return true;
}

bool Player::SatisfyQuestLevel(Quest const* qInfo, bool msg) const
{
    if (getLevel() < qInfo->GetMinLevel())
    {
        if (msg)
        {
            SendCanTakeQuestResponse(QUEST_ERR_FAILED_LOW_LEVEL);
            TC_LOG_DEBUG("misc", "Player::SatisfyQuestLevel: Sent QUEST_ERR_FAILED_LOW_LEVEL (QuestID: %u) because player '%s' (%s) doesn't have the required (min) level.",
                qInfo->GetQuestId(), GetName().c_str(), GetGUID().ToString().c_str());
        }
        return false;
    }

    if (qInfo->GetMaxLevel() > 0 && getLevel() > qInfo->GetMaxLevel())
    {
        if (msg)
        {
            SendCanTakeQuestResponse(QUEST_ERR_NONE); // There doesn't seem to be a specific response for too high player level
            TC_LOG_DEBUG("misc", "Player::SatisfyQuestLevel: Sent QUEST_ERR_FAILED_LOW_LEVEL (QuestID: %u) because player '%s' (%s) doesn't have the required (max) level.",
                qInfo->GetQuestId(), GetName().c_str(), GetGUID().ToString().c_str());
        }
        return false;
    }
    return true;
}

bool Player::SatisfyQuestLog(bool msg) const
{
    // exist free slot
    if (FindQuestSlot(0) < MAX_QUEST_LOG_SIZE)
        return true;

    if (msg)
    {
        WorldPackets::Quest::QuestLogFull data;
        GetSession()->SendPacket(data.Write());
    }
    return false;
}

bool Player::SatisfyQuestPreviousQuest(Quest const* qInfo, bool msg)
{
    // No previous quest (might be first quest in a series)
    if (qInfo->prevQuests.empty())
        return true;

    for (Quest::PrevQuests::const_iterator iter = qInfo->prevQuests.begin(); iter != qInfo->prevQuests.end(); ++iter)
    {
        uint32 prevId = abs(*iter);

        Quest const* qPrevInfo = sObjectMgr->GetQuestTemplate(prevId);

        if (qPrevInfo)
        {
            // If any of the positive previous quests completed, return true
            if (*iter > 0 && m_RewardedQuests.find(prevId) != m_RewardedQuests.end())
            {
                // skip one-from-all exclusive group
                if (qPrevInfo->GetExclusiveGroup() >= 0)
                    return true;

                // each-from-all exclusive group (< 0)
                // can be start if only all quests in prev quest exclusive group completed and rewarded
                ObjectMgr::ExclusiveQuestGroupsBounds range(sObjectMgr->mExclusiveQuestGroups.equal_range(qPrevInfo->GetExclusiveGroup()));

                for (; range.first != range.second; ++range.first)
                {
                    uint32 exclude_Id = range.first->second;

                    // skip checked quest id, only state of other quests in group is interesting
                    if (exclude_Id == prevId)
                        continue;

                    // alternative quest from group also must be completed and rewarded (reported)
                    if (m_RewardedQuests.find(exclude_Id) == m_RewardedQuests.end())
                    {
                        if (msg)
                        {
                            SendCanTakeQuestResponse(QUEST_ERR_NONE);
                            TC_LOG_DEBUG("misc", "Player::SatisfyQuestPreviousQuest: Sent QUEST_ERR_NONE (QuestID: %u) because player '%s' (%s) doesn't have the required quest (1).",
                                qInfo->GetQuestId(), GetName().c_str(), GetGUID().ToString().c_str());
                        }
                        return false;
                    }
                }
                return true;
            }

            // If any of the negative previous quests active, return true
            if (*iter < 0 && GetQuestStatus(prevId) != QUEST_STATUS_NONE)
            {
                // skip one-from-all exclusive group
                if (qPrevInfo->GetExclusiveGroup() >= 0)
                    return true;

                // each-from-all exclusive group (< 0)
                // can be start if only all quests in prev quest exclusive group active
                ObjectMgr::ExclusiveQuestGroupsBounds range(sObjectMgr->mExclusiveQuestGroups.equal_range(qPrevInfo->GetExclusiveGroup()));

                for (; range.first != range.second; ++range.first)
                {
                    uint32 exclude_Id = range.first->second;

                    // skip checked quest id, only state of other quests in group is interesting
                    if (exclude_Id == prevId)
                        continue;

                    // alternative quest from group also must be active
                    if (GetQuestStatus(exclude_Id) != QUEST_STATUS_NONE)
                    {
                        if (msg)
                        {
                            SendCanTakeQuestResponse(QUEST_ERR_NONE);
                            TC_LOG_DEBUG("misc", "Player::SatisfyQuestPreviousQuest: Sent QUEST_ERR_NONE (QuestID: %u) because player '%s' (%s) doesn't have the required quest (2).",
                                qInfo->GetQuestId(), GetName().c_str(), GetGUID().ToString().c_str());

                        }
                        return false;
                    }
                }
                return true;
            }
        }
    }

    // Has only positive prev. quests in non-rewarded state
    // and negative prev. quests in non-active state
    if (msg)
    {
        SendCanTakeQuestResponse(QUEST_ERR_NONE);
        TC_LOG_DEBUG("misc", "Player::SatisfyQuestPreviousQuest: Sent QUEST_ERR_NONE (QuestID: %u) because player '%s' (%s) doesn't have required quest (3).",
            qInfo->GetQuestId(), GetName().c_str(), GetGUID().ToString().c_str());
    }

    return false;
}

bool Player::SatisfyQuestClass(Quest const* qInfo, bool msg) const
{
    uint32 reqClass = qInfo->GetAllowableClasses();

    if (reqClass == 0)
        return true;

    if ((reqClass & getClassMask()) == 0)
    {
        if (msg)
        {
            SendCanTakeQuestResponse(QUEST_ERR_NONE);
            TC_LOG_DEBUG("misc", "Player::SatisfyQuestClass: Sent QUEST_ERR_NONE (QuestID: %u) because player '%s' (%s) doesn't have required class.",
                qInfo->GetQuestId(), GetName().c_str(), GetGUID().ToString().c_str());
        }

        return false;
    }

    return true;
}

bool Player::SatisfyQuestRace(Quest const* qInfo, bool msg) const
{
    int32 reqraces = qInfo->GetAllowableRaces();
    if (reqraces == -1)
        return true;
    if ((reqraces & getRaceMask()) == 0)
    {
        if (msg)
        {
            SendCanTakeQuestResponse(QUEST_ERR_FAILED_WRONG_RACE);
            TC_LOG_DEBUG("misc", "Player::SatisfyQuestRace: Sent QUEST_ERR_FAILED_WRONG_RACE (QuestID: %u) because player '%s' (%s) doesn't have required race.",
                qInfo->GetQuestId(), GetName().c_str(), GetGUID().ToString().c_str());

        }
        return false;
    }
    return true;
}

bool Player::SatisfyQuestReputation(Quest const* qInfo, bool msg)
{
    uint32 fIdMin = qInfo->GetRequiredMinRepFaction();      //Min required rep
    if (fIdMin && GetReputationMgr().GetReputation(fIdMin) < qInfo->GetRequiredMinRepValue())
    {
        if (msg)
        {
            SendCanTakeQuestResponse(QUEST_ERR_NONE);
            TC_LOG_DEBUG("misc", "Player::SatisfyQuestReputation: Sent QUEST_ERR_NONE (QuestID: %u) because player '%s' (%s) doesn't required reputation (min).",
                qInfo->GetQuestId(), GetName().c_str(), GetGUID().ToString().c_str());
        }
        return false;
    }

    uint32 fIdMax = qInfo->GetRequiredMaxRepFaction();      //Max required rep
    if (fIdMax && GetReputationMgr().GetReputation(fIdMax) >= qInfo->GetRequiredMaxRepValue())
    {
        if (msg)
        {
            SendCanTakeQuestResponse(QUEST_ERR_NONE);
            TC_LOG_DEBUG("misc", "SatisfyQuestReputation: Sent QUEST_ERR_NONE (QuestID: %u) because player '%s' (%s) doesn't required reputation (max).",
                qInfo->GetQuestId(), GetName().c_str(), GetGUID().ToString().c_str());
        }
        return false;
    }

    /** @todo 6.x investigate if it's still needed
    // ReputationObjective2 does not seem to be an objective requirement but a requirement
    // to be able to accept the quest
    uint32 fIdObj = qInfo->GetRepObjectiveFaction2();
    if (fIdObj && GetReputationMgr().GetReputation(fIdObj) >= qInfo->GetRepObjectiveValue2())
    {
        if (msg)
        {
            SendCanTakeQuestResponse(QUEST_ERR_NONE);
            TC_LOG_DEBUG("misc", "SatisfyQuestReputation: Sent QUEST_ERR_NONE (questId: %u) because player does not have required reputation (ReputationObjective2).", qInfo->GetQuestId());
        }
        return false;
    }**/

    return true;
}

bool Player::SatisfyQuestStatus(Quest const* qInfo, bool msg) const
{
    if (GetQuestStatus(qInfo->GetQuestId()) != QUEST_STATUS_NONE)
    {
        if (msg)
        {
            SendCanTakeQuestResponse(QUEST_ERR_ALREADY_ON1);
            TC_LOG_DEBUG("misc", "Player::SatisfyQuestStatus: Sent QUEST_ERR_ALREADY_ON1 (QuestID: %u) because player '%s' (%s) quest status is not NONE.",
                qInfo->GetQuestId(), GetName().c_str(), GetGUID().ToString().c_str());
        }
        return false;
    }
    return true;
}

bool Player::SatisfyQuestConditions(Quest const* qInfo, bool msg)
{
    if (!sConditionMgr->IsObjectMeetingNotGroupedConditions(CONDITION_SOURCE_TYPE_QUEST_ACCEPT, qInfo->GetQuestId(), this))
    {
        if (msg)
        {
            SendCanTakeQuestResponse(QUEST_ERR_NONE);
            TC_LOG_DEBUG("misc", "Player::SatisfyQuestConditions: Sent QUEST_ERR_NONE (QuestID: %u) because player '%s' (%s) doesn't meet conditions.",
                qInfo->GetQuestId(), GetName().c_str(), GetGUID().ToString().c_str());
        }
        TC_LOG_DEBUG("condition", "Player::SatisfyQuestConditions: conditions not met for quest %u", qInfo->GetQuestId());
        return false;
    }
    return true;
}

bool Player::SatisfyQuestTimed(Quest const* qInfo, bool msg) const
{
    if (!m_timedquests.empty() && qInfo->HasSpecialFlag(QUEST_SPECIAL_FLAGS_TIMED))
    {
        if (msg)
        {
            SendCanTakeQuestResponse(QUEST_ERR_ONLY_ONE_TIMED);
            TC_LOG_DEBUG("misc", "Player::SatisfyQuestTimed: Sent QUEST_ERR_ONLY_ONE_TIMED (QuestID: %u) because player '%s' (%s) is already on a timed quest.",
                qInfo->GetQuestId(), GetName().c_str(), GetGUID().ToString().c_str());
        }
        return false;
    }
    return true;
}

bool Player::SatisfyQuestExclusiveGroup(Quest const* qInfo, bool msg)
{
    // non positive exclusive group, if > 0 then can be start if any other quest in exclusive group already started/completed
    if (qInfo->GetExclusiveGroup() <= 0)
        return true;

    ObjectMgr::ExclusiveQuestGroupsBounds range(sObjectMgr->mExclusiveQuestGroups.equal_range(qInfo->GetExclusiveGroup()));

    for (; range.first != range.second; ++range.first)
    {
        uint32 exclude_Id = range.first->second;

        // skip checked quest id, only state of other quests in group is interesting
        if (exclude_Id == qInfo->GetQuestId())
            continue;

        // not allow have daily quest if daily quest from exclusive group already recently completed
        Quest const* Nquest = sObjectMgr->GetQuestTemplate(exclude_Id);
        ASSERT(Nquest);
        if (!SatisfyQuestDay(Nquest, false) || !SatisfyQuestWeek(Nquest, false) || !SatisfyQuestSeasonal(Nquest, false))
        {
            if (msg)
            {
                SendCanTakeQuestResponse(QUEST_ERR_NONE);
                TC_LOG_DEBUG("misc", "Player::SatisfyQuestExclusiveGroup: Sent QUEST_ERR_NONE (QuestID: %u) because player '%s' (%s) already did daily quests in exclusive group.",
                    qInfo->GetQuestId(), GetName().c_str(), GetGUID().ToString().c_str());
            }

            return false;
        }

        // alternative quest already started or completed - but don't check rewarded states if both are repeatable
        if (GetQuestStatus(exclude_Id) != QUEST_STATUS_NONE || (!(qInfo->IsRepeatable() && Nquest->IsRepeatable()) && (m_RewardedQuests.find(exclude_Id) != m_RewardedQuests.end())))
        {
            if (msg)
            {
                SendCanTakeQuestResponse(QUEST_ERR_NONE);
                TC_LOG_DEBUG("misc", "Player::SatisfyQuestExclusiveGroup: Sent QUEST_ERR_NONE (QuestID: %u) because player '%s' (%s) already did quest in exclusive group.",
                    qInfo->GetQuestId(), GetName().c_str(), GetGUID().ToString().c_str());
            }
            return false;
        }
    }
    return true;
}

bool Player::SatisfyQuestNextChain(Quest const* qInfo, bool msg) const
{
    uint32 nextQuest = qInfo->GetNextQuestInChain();
    if (!nextQuest)
        return true;

    // next quest in chain already started or completed
    if (GetQuestStatus(nextQuest) != QUEST_STATUS_NONE) // GetQuestStatus returns QUEST_STATUS_COMPLETED for rewarded quests
    {
        if (msg)
        {
            SendCanTakeQuestResponse(QUEST_ERR_NONE);
            TC_LOG_DEBUG("misc", "Player::SatisfyQuestNextChain: Sent QUEST_ERR_NONE (QuestID: %u) because player '%s' (%s) already did or started next quest in chain.",
                qInfo->GetQuestId(), GetName().c_str(), GetGUID().ToString().c_str());
        }
        return false;
    }

    // check for all quests further up the chain
    // only necessary if there are quest chains with more than one quest that can be skipped
    //return SatisfyQuestNextChain(qInfo->GetNextQuestInChain(), msg);
    return true;
}

bool Player::SatisfyQuestPrevChain(Quest const* qInfo, bool msg)
{
    // No previous quest in chain
    if (qInfo->prevChainQuests.empty())
        return true;

    for (Quest::PrevChainQuests::const_iterator iter = qInfo->prevChainQuests.begin(); iter != qInfo->prevChainQuests.end(); ++iter)
    {
        QuestStatusMap::const_iterator itr = m_QuestStatus.find(*iter);

        // If any of the previous quests in chain active, return false
        if (itr != m_QuestStatus.end() && itr->second.Status != QUEST_STATUS_NONE)
        {
            if (msg)
            {
                SendCanTakeQuestResponse(QUEST_ERR_NONE);
                TC_LOG_DEBUG("misc", "Player::SatisfyQuestNextChain: Sent QUEST_ERR_NONE (QuestID: %u) because player '%s' (%s) already did or started next quest in chain.",
                    qInfo->GetQuestId(), GetName().c_str(), GetGUID().ToString().c_str());
            }
            return false;
        }

        // check for all quests further down the chain
        // only necessary if there are quest chains with more than one quest that can be skipped
        //if (!SatisfyQuestPrevChain(prevId, msg))
        //    return false;
    }

    // No previous quest in chain active
    return true;
}

bool Player::SatisfyQuestDay(Quest const* qInfo, bool /*msg*/) const
{
    if (!qInfo->IsDaily() && !qInfo->IsDFQuest())
        return true;

    if (qInfo->IsDFQuest())
    {
        if (!m_DFQuests.empty())
            return false;

        return true;
    }

    std::vector<uint32> const& dailies = GetDynamicValues(PLAYER_DYNAMIC_FIELD_DAILY_QUESTS);
    for (uint32 dailyQuestId : dailies)
        if (dailyQuestId == qInfo->GetQuestId())
            return false;

    return true;
}

bool Player::SatisfyQuestWeek(Quest const* qInfo, bool /*msg*/)
{
    if (!qInfo->IsWeekly() || m_weeklyquests.empty())
        return true;

    // if not found in cooldown list
    return m_weeklyquests.find(qInfo->GetQuestId()) == m_weeklyquests.end();
}

bool Player::SatisfyQuestSeasonal(Quest const* qInfo, bool /*msg*/)
{
    if (!qInfo->IsSeasonal() || m_seasonalquests.empty())
        return true;

    uint16 eventId = sGameEventMgr->GetEventIdForQuest(qInfo);
    if (m_seasonalquests.find(eventId) == m_seasonalquests.end() || m_seasonalquests[eventId].empty())
        return true;

    // if not found in cooldown list
    return m_seasonalquests[eventId].find(qInfo->GetQuestId()) == m_seasonalquests[eventId].end();
}

bool Player::SatisfyQuestMonth(Quest const* qInfo, bool /*msg*/)
{
    if (!qInfo->IsMonthly() || m_monthlyquests.empty())
        return true;

    // if not found in cooldown list
    return m_monthlyquests.find(qInfo->GetQuestId()) == m_monthlyquests.end();
}

bool Player::GiveQuestSourceItem(Quest const* quest)
{
    uint32 srcitem = quest->GetSrcItemId();
    if (srcitem > 0)
    {
        uint32 count = quest->GetSrcItemCount();
        if (count <= 0)
            count = 1;

        ItemPosCountVec dest;
        InventoryResult msg = CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, srcitem, count);
        if (msg == EQUIP_ERR_OK)
        {
            Item* item = StoreNewItem(dest, srcitem, true);
            SendNewItem(item, count, true, false);
            return true;
        }
        // player already have max amount required item, just report success
        if (msg == EQUIP_ERR_ITEM_MAX_COUNT)
            return true;

        SendEquipError(msg, nullptr, nullptr, srcitem);
        return false;
    }

    return true;
}

bool Player::TakeQuestSourceItem(uint32 questId, bool msg)
{
    Quest const* quest = sObjectMgr->GetQuestTemplate(questId);
    if (quest)
    {
        uint32 srcItemId = quest->GetSrcItemId();
        ItemTemplate const* item = sObjectMgr->GetItemTemplate(srcItemId);

        if (srcItemId > 0)
        {
            uint32 count = quest->GetSrcItemCount();
            if (count <= 0)
                count = 1;

            // exist two cases when destroy source quest item not possible:
            // a) non un-equippable item (equipped non-empty bag, for example)
            // b) when quest is started from an item and item also is needed in
            // the end as RequiredItemId
            InventoryResult res = CanUnequipItems(srcItemId, count);
            if (res != EQUIP_ERR_OK)
            {
                if (msg)
                    SendEquipError(res, nullptr, nullptr, srcItemId);
                return false;
            }

            ASSERT(item);
            bool destroyItem = true;
            if (item->GetStartQuest() == questId)
                for (QuestObjective const& obj : quest->GetObjectives())
                    if (obj.Type == QUEST_OBJECTIVE_ITEM && srcItemId == uint32(obj.ObjectID))
                        destroyItem = false;

            if (destroyItem)
                DestroyItemCount(srcItemId, count, true, true);
        }
    }

    return true;
}

bool Player::GetQuestRewardStatus(uint32 quest_id) const
{
    Quest const* qInfo = sObjectMgr->GetQuestTemplate(quest_id);
    if (qInfo)
    {
        if (qInfo->IsSeasonal() && !qInfo->IsRepeatable())
        {
            uint16 eventId = sGameEventMgr->GetEventIdForQuest(qInfo);
            auto seasonalQuestItr = m_seasonalquests.find(eventId);
            if (seasonalQuestItr != m_seasonalquests.end())
                return seasonalQuestItr->second.find(quest_id) != seasonalQuestItr->second.end();

            return false;
        }


        // for repeatable quests: rewarded field is set after first reward only to prevent getting XP more than once
        if (!qInfo->IsRepeatable())
            return m_RewardedQuests.find(quest_id) != m_RewardedQuests.end();

        return false;
    }
    return false;
}

QuestStatus Player::GetQuestStatus(uint32 quest_id) const
{
    if (quest_id)
    {
        QuestStatusMap::const_iterator itr = m_QuestStatus.find(quest_id);
        if (itr != m_QuestStatus.end())
            return itr->second.Status;

        if (Quest const* qInfo = sObjectMgr->GetQuestTemplate(quest_id))
        {
            if (qInfo->IsSeasonal() && !qInfo->IsRepeatable())
            {
                uint16 eventId = sGameEventMgr->GetEventIdForQuest(qInfo);
                auto seasonalQuestItr = m_seasonalquests.find(eventId);
                if (seasonalQuestItr == m_seasonalquests.end() || seasonalQuestItr->second.find(quest_id) == seasonalQuestItr->second.end())
                    return QUEST_STATUS_NONE;
            }

            if (!qInfo->IsRepeatable() && m_RewardedQuests.find(quest_id) != m_RewardedQuests.end())
                return QUEST_STATUS_REWARDED;
        }
    }
    return QUEST_STATUS_NONE;
}

bool Player::CanShareQuest(uint32 quest_id) const
{
    Quest const* qInfo = sObjectMgr->GetQuestTemplate(quest_id);
    return qInfo && qInfo->HasFlag(QUEST_FLAGS_SHARABLE) && IsActiveQuest(quest_id);
}

void Player::SetQuestStatus(uint32 questId, QuestStatus status, bool update /*= true*/)
{
    if (sObjectMgr->GetQuestTemplate(questId))
    {
        m_QuestStatus[questId].Status = status;
        m_QuestStatusSave[questId] = QUEST_DEFAULT_SAVE_TYPE;
    }

    if (update)
        SendQuestUpdate(questId);

    sScriptMgr->OnQuestStatusChange(this, questId, status);
}

void Player::RemoveActiveQuest(uint32 questId, bool update /*= true*/)
{
    QuestStatusMap::iterator itr = m_QuestStatus.find(questId);
    if (itr != m_QuestStatus.end())
    {
        m_QuestStatus.erase(itr);
        m_QuestStatusSave[questId] = QUEST_DELETE_SAVE_TYPE;
    }

    if (update)
        SendQuestUpdate(questId);
}

void Player::RemoveRewardedQuest(uint32 questId, bool update /*= true*/)
{
    RewardedQuestSet::iterator rewItr = m_RewardedQuests.find(questId);
    if (rewItr != m_RewardedQuests.end())
    {
        m_RewardedQuests.erase(rewItr);
        m_RewardedQuestsSave[questId] = QUEST_FORCE_DELETE_SAVE_TYPE;
    }

    if (uint32 questBit = sDB2Manager.GetQuestUniqueBitFlag(questId))
        SetQuestCompletedBit(questBit, false);

    if (update)
        SendQuestUpdate(questId);
}

void Player::SendQuestUpdate(uint32 questId)
{
    uint32 zone = 0, area = 0;

    SpellAreaForQuestMapBounds saBounds = sSpellMgr->GetSpellAreaForQuestMapBounds(questId);
    if (saBounds.first != saBounds.second)
    {
        GetZoneAndAreaId(zone, area);

        for (SpellAreaForAreaMap::const_iterator itr = saBounds.first; itr != saBounds.second; ++itr)
            if (itr->second->autocast && itr->second->IsFitToRequirements(this, zone, area))
                if (!HasAura(itr->second->spellId))
                    CastSpell(this, itr->second->spellId, true);
    }

    saBounds = sSpellMgr->GetSpellAreaForQuestEndMapBounds(questId);
    if (saBounds.first != saBounds.second)
    {
        if (!zone || !area)
            GetZoneAndAreaId(zone, area);

        for (SpellAreaForAreaMap::const_iterator itr = saBounds.first; itr != saBounds.second; ++itr)
            if (!itr->second->IsFitToRequirements(this, zone, area))
                RemoveAurasDueToSpell(itr->second->spellId);
    }

    UpdateForQuestWorldObjects();
    SendUpdatePhasing();
}

QuestGiverStatus Player::GetQuestDialogStatus(Object* questgiver)
{
    QuestRelationBounds qr;
    QuestRelationBounds qir;

    switch (questgiver->GetTypeId())
    {
    case TYPEID_GAMEOBJECT:
    {
        QuestGiverStatus questStatus = QuestGiverStatus(sScriptMgr->GetDialogStatus(this, questgiver->ToGameObject()));
        if (questStatus != DIALOG_STATUS_SCRIPTED_NO_STATUS)
            return questStatus;
        qr = sObjectMgr->GetGOQuestRelationBounds(questgiver->GetEntry());
        qir = sObjectMgr->GetGOQuestInvolvedRelationBounds(questgiver->GetEntry());
        break;
    }
    case TYPEID_UNIT:
    {
        QuestGiverStatus questStatus = QuestGiverStatus(sScriptMgr->GetDialogStatus(this, questgiver->ToCreature()));
        if (questStatus != DIALOG_STATUS_SCRIPTED_NO_STATUS)
            return questStatus;
        qr = sObjectMgr->GetCreatureQuestRelationBounds(questgiver->GetEntry());
        qir = sObjectMgr->GetCreatureQuestInvolvedRelationBounds(questgiver->GetEntry());
        break;
    }
    default:
        // it's impossible, but check
        TC_LOG_ERROR("entities.player.quest", "Player::GetQuestDialogStatus: Called with unexpected type (Entry: %u, Type: %u) by player '%s' (%s)",
            questgiver->GetEntry(), questgiver->GetTypeId(), GetName().c_str(), GetGUID().ToString().c_str());
        return DIALOG_STATUS_NONE;
    }

    QuestGiverStatus result = DIALOG_STATUS_NONE;

    for (QuestRelations::const_iterator i = qir.first; i != qir.second; ++i)
    {
        QuestGiverStatus result2 = DIALOG_STATUS_NONE;
        uint32 questId = i->second;
        Quest const* quest = sObjectMgr->GetQuestTemplate(questId);
        if (!quest)
            continue;

        if (!sConditionMgr->IsObjectMeetingNotGroupedConditions(CONDITION_SOURCE_TYPE_QUEST_SHOW_MARK, quest->GetQuestId(), this))
            continue;

        QuestStatus status = GetQuestStatus(questId);
        if ((status == QUEST_STATUS_COMPLETE && !GetQuestRewardStatus(questId)) ||
            (quest->IsAutoComplete() && CanTakeQuest(quest, false)))
        {
            if (quest->IsAutoComplete() && quest->IsRepeatable() && !quest->IsDailyOrWeekly())
                result2 = DIALOG_STATUS_REWARD_REP;
            else
                result2 = DIALOG_STATUS_REWARD;
        }
        else if (status == QUEST_STATUS_INCOMPLETE)
            result2 = DIALOG_STATUS_INCOMPLETE;

        if (result2 > result)
            result = result2;
    }

    for (QuestRelations::const_iterator i = qr.first; i != qr.second; ++i)
    {
        QuestGiverStatus result2 = DIALOG_STATUS_NONE;
        uint32 questId = i->second;
        Quest const* quest = sObjectMgr->GetQuestTemplate(questId);
        if (!quest)
            continue;

        if (!sConditionMgr->IsObjectMeetingNotGroupedConditions(CONDITION_SOURCE_TYPE_QUEST_SHOW_MARK, quest->GetQuestId(), this))
            continue;

        QuestStatus status = GetQuestStatus(questId);
        if (status == QUEST_STATUS_NONE)
        {
            if (CanSeeStartQuest(quest))
            {
                if (SatisfyQuestLevel(quest, false))
                {
                    if (quest->IsAutoComplete())
                        result2 = DIALOG_STATUS_REWARD_REP;
                    else if (getLevel() <= (GetQuestLevel(quest) + sWorld->getIntConfig(CONFIG_QUEST_LOW_LEVEL_HIDE_DIFF)))
                    {
                        if (quest->IsDaily())
                            result2 = DIALOG_STATUS_AVAILABLE_REP;
                        else
                            result2 = DIALOG_STATUS_AVAILABLE;
                    }
                    else
                        result2 = DIALOG_STATUS_LOW_LEVEL_AVAILABLE;
                }
                else
                    result2 = DIALOG_STATUS_UNAVAILABLE;
            }
        }

        if (result2 > result)
            result = result2;
    }

    return result;
}

// not used in Trinity, but used in scripting code
uint16 Player::GetReqKillOrCastCurrentCount(uint32 quest_id, int32 entry) const
{
    Quest const* qInfo = sObjectMgr->GetQuestTemplate(quest_id);
    if (!qInfo)
        return 0;

    for (QuestObjective const& obj : qInfo->GetObjectives())
        if (obj.ObjectID == entry)
            return GetQuestObjectiveData(qInfo, obj.StorageIndex);

    return 0;
}

void Player::AdjustQuestReqItemCount(Quest const* quest)
{
    if (quest->HasSpecialFlag(QUEST_SPECIAL_FLAGS_DELIVER))
    {
        for (QuestObjective const& obj : quest->GetObjectives())
        {
            if (obj.Type != QUEST_OBJECTIVE_ITEM)
                continue;

            uint32 reqItemCount = obj.Amount;
            uint32 curItemCount = GetItemCount(obj.ObjectID, true);
            SetQuestObjectiveData(quest, obj.StorageIndex, std::min(curItemCount, reqItemCount));
        }
    }
}

uint16 Player::FindQuestSlot(uint32 quest_id) const
{
    for (uint16 i = 0; i < MAX_QUEST_LOG_SIZE; ++i)
        if (GetQuestSlotQuestId(i) == quest_id)
            return i;

    return MAX_QUEST_LOG_SIZE;
}

uint32 Player::GetQuestSlotQuestId(uint16 slot) const
{
    return GetUInt32Value(PLAYER_QUEST_LOG + slot * MAX_QUEST_OFFSET + QUEST_ID_OFFSET);
}

uint32 Player::GetQuestSlotState(uint16 slot)   const
{
    return GetUInt32Value(PLAYER_QUEST_LOG + slot * MAX_QUEST_OFFSET + QUEST_STATE_OFFSET);
}

uint16 Player::GetQuestSlotCounter(uint16 slot, uint8 counter) const
{
    return (uint16)(GetUInt64Value(PLAYER_QUEST_LOG + slot * MAX_QUEST_OFFSET + QUEST_COUNTS_OFFSET) >> (counter * 16));
}

uint32 Player::GetQuestSlotTime(uint16 slot) const
{
    return GetUInt32Value(PLAYER_QUEST_LOG + slot * MAX_QUEST_OFFSET + QUEST_TIME_OFFSET);
}

void Player::SetQuestSlot(uint16 slot, uint32 quest_id, uint32 timer /*= 0*/)
{
    SetUInt32Value(PLAYER_QUEST_LOG + slot * MAX_QUEST_OFFSET + QUEST_ID_OFFSET, quest_id);
    SetUInt32Value(PLAYER_QUEST_LOG + slot * MAX_QUEST_OFFSET + QUEST_STATE_OFFSET, 0);
    SetUInt32Value(PLAYER_QUEST_LOG + slot * MAX_QUEST_OFFSET + QUEST_COUNTS_OFFSET, 0);
    SetUInt32Value(PLAYER_QUEST_LOG + slot * MAX_QUEST_OFFSET + QUEST_COUNTS_OFFSET + 1, 0);
    SetUInt32Value(PLAYER_QUEST_LOG + slot * MAX_QUEST_OFFSET + QUEST_TIME_OFFSET, timer);
}

void Player::SetQuestSlotCounter(uint16 slot, uint8 counter, uint16 count)
{
    uint64 val = GetUInt64Value(PLAYER_QUEST_LOG + slot * MAX_QUEST_OFFSET + QUEST_COUNTS_OFFSET);
    val &= ~((uint64)0xFFFF << (counter * 16));
    val |= ((uint64)count << (counter * 16));
    SetUInt64Value(PLAYER_QUEST_LOG + slot * MAX_QUEST_OFFSET + QUEST_COUNTS_OFFSET, val);
}

void Player::SetQuestSlotState(uint16 slot, uint32 state)
{
    SetFlag(PLAYER_QUEST_LOG + slot * MAX_QUEST_OFFSET + QUEST_STATE_OFFSET, state);
}

void Player::RemoveQuestSlotState(uint16 slot, uint32 state)
{
    RemoveFlag(PLAYER_QUEST_LOG + slot * MAX_QUEST_OFFSET + QUEST_STATE_OFFSET, state);
}

void Player::SetQuestSlotTimer(uint16 slot, uint32 timer)
{
    SetUInt32Value(PLAYER_QUEST_LOG + slot * MAX_QUEST_OFFSET + QUEST_TIME_OFFSET, timer);
}

void Player::SetQuestCompletedBit(uint32 questBit, bool completed)
{
    if (!questBit)
        return;

    uint32 fieldOffset = (questBit - 1) >> 5;
    if (fieldOffset >= QUESTS_COMPLETED_BITS_SIZE)
        return;

    ApplyModFlag(PLAYER_FIELD_QUEST_COMPLETED + ((questBit - 1) >> 5), 1 << ((questBit - 1) & 31), completed);
}

void Player::AreaExploredOrEventHappens(uint32 questId)
{
    if (questId)
    {
        uint16 log_slot = FindQuestSlot(questId);
        if (log_slot < MAX_QUEST_LOG_SIZE)
        {
            TC_LOG_ERROR("entities.player.quest", "Player::AreaExploredOrEventHappens:Deprecated function called for quest %u", questId);
            /** @todo
            This function was previously used for area triggers but now those are a part of quest objective system
            Currently this function is used to complete quests with no objectives (needs verifying) so probably rename it?

            QuestStatusData& q_status = m_QuestStatus[questId];

            if (!q_status.Explored)
            {
                q_status.Explored = true;
                m_QuestStatusSave[questId] = QUEST_DEFAULT_SAVE_TYPE;
                SetQuestSlotState(log_slot, QUEST_STATE_COMPLETE);
                SendQuestComplete(questId);
            }**/
        }
        if (CanCompleteQuest(questId))
            CompleteQuest(questId);
    }
}

//not used in Trinityd, function for external script library
void Player::GroupEventHappens(uint32 questId, WorldObject const* pEventObject)
{
    if (Group* group = GetGroup())
    {
        for (GroupReference* itr = group->GetFirstMember(); itr != nullptr; itr = itr->next())
        {
            Player* player = itr->GetSource();

            // for any leave or dead (with not released body) group member at appropriate distance
            if (player && player->IsAtGroupRewardDistance(pEventObject) && !player->GetCorpse())
                player->AreaExploredOrEventHappens(questId);
        }
    }
    else
        AreaExploredOrEventHappens(questId);
}

void Player::ItemAddedQuestCheck(uint32 entry, uint32 count)
{
    for (uint8 i = 0; i < MAX_QUEST_LOG_SIZE; ++i)
    {
        uint32 questid = GetQuestSlotQuestId(i);
        if (questid == 0)
            continue;

        QuestStatusData& q_status = m_QuestStatus[questid];

        if (q_status.Status != QUEST_STATUS_INCOMPLETE)
            continue;

        Quest const* qInfo = sObjectMgr->GetQuestTemplate(questid);
        if (!qInfo || !qInfo->HasSpecialFlag(QUEST_SPECIAL_FLAGS_DELIVER))
            continue;

        for (QuestObjective const& obj : qInfo->GetObjectives())
        {
            if (obj.Type != QUEST_OBJECTIVE_ITEM)
                continue;

            uint32 reqItem = obj.ObjectID;
            if (reqItem == entry)
            {
                uint32 reqItemCount = obj.Amount;
                uint32 curItemCount = GetQuestObjectiveData(qInfo, obj.StorageIndex);
                if (curItemCount < reqItemCount)
                {
                    uint32 newItemCount = std::min<uint32>(curItemCount + count, reqItemCount);
                    SetQuestObjectiveData(qInfo, obj.StorageIndex, newItemCount);

                    //SendQuestUpdateAddItem(qInfo, j, additemcount);
                    // FIXME: verify if there's any packet sent updating item
                }

                if (CanCompleteQuest(questid))
                    CompleteQuest(questid);

                return;
            }
        }
    }
    UpdateForQuestWorldObjects();
}

void Player::ItemRemovedQuestCheck(uint32 entry, uint32 count)
{
    for (uint8 i = 0; i < MAX_QUEST_LOG_SIZE; ++i)
    {
        uint32 questid = GetQuestSlotQuestId(i);
        if (!questid)
            continue;

        Quest const* qInfo = sObjectMgr->GetQuestTemplate(questid);
        if (!qInfo)
            continue;

        if (!qInfo->HasSpecialFlag(QUEST_SPECIAL_FLAGS_DELIVER))
            continue;

        for (QuestObjective const& obj : qInfo->GetObjectives())
        {
            if (obj.Type != QUEST_OBJECTIVE_ITEM)
                continue;

            uint32 reqItem = obj.ObjectID;
            if (reqItem == entry)
            {
                uint32 reqItemCount = obj.Amount;
                uint16 curItemCount = GetQuestObjectiveData(qInfo, obj.StorageIndex);

                if (curItemCount >= reqItemCount) // we may have more than what the status shows
                    curItemCount = GetItemCount(entry, false);

                uint16 newItemCount = (count > curItemCount) ? 0 : curItemCount - count;

                if (newItemCount < reqItemCount)
                {
                    SetQuestObjectiveData(qInfo, obj.StorageIndex, newItemCount);
                    IncompleteQuest(questid);
                }
                return;
            }
        }
    }
    UpdateForQuestWorldObjects();
}

void Player::KilledMonster(CreatureTemplate const* cInfo, ObjectGuid guid)
{
    ASSERT(cInfo);

    if (cInfo->Entry)
        KilledMonsterCredit(cInfo->Entry, guid);

    for (uint8 i = 0; i < MAX_KILL_CREDIT; ++i)
        if (cInfo->KillCredit[i])
            KilledMonsterCredit(cInfo->KillCredit[i], ObjectGuid::Empty);
}

void Player::KilledMonsterCredit(uint32 entry, ObjectGuid guid /*= ObjectGuid::Empty*/)
{
    uint16 addKillCount = 1;
    uint32 real_entry = entry;
    Creature* killed = nullptr;
    if (!guid.IsEmpty())
    {
        killed = GetMap()->GetCreature(guid);
        if (killed && killed->GetEntry())
            real_entry = killed->GetEntry();
    }

    StartTimedAchievement(ACHIEVEMENT_TIMED_TYPE_CREATURE, real_entry);   // MUST BE CALLED FIRST
    UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_KILL_CREATURE, real_entry, addKillCount, 0, killed);

    for (uint8 i = 0; i < MAX_QUEST_LOG_SIZE; ++i)
    {
        uint32 questid = GetQuestSlotQuestId(i);
        if (!questid)
            continue;

        Quest const* qInfo = sObjectMgr->GetQuestTemplate(questid);
        if (!qInfo)
            continue;

        // just if !ingroup || !noraidgroup || raidgroup
        QuestStatusData& q_status = m_QuestStatus[questid];
        if (q_status.Status == QUEST_STATUS_INCOMPLETE && (!GetGroup() || !GetGroup()->isRaidGroup() || qInfo->IsAllowedInRaid(GetMap()->GetDifficultyID())))
        {
            if (qInfo->HasSpecialFlag(QUEST_SPECIAL_FLAGS_KILL) /*&& !qInfo->HasSpecialFlag(QUEST_SPECIAL_FLAGS_CAST)*/)
            {
                for (QuestObjective const& obj : qInfo->GetObjectives())
                {
                    if (obj.Type != QUEST_OBJECTIVE_MONSTER)
                        continue;

                    uint32 reqkill = obj.ObjectID;

                    if (reqkill == real_entry)
                    {
                        uint32 reqKillCount = obj.Amount;
                        uint16 curKillCount = GetQuestObjectiveData(qInfo, obj.StorageIndex);
                        if (curKillCount < reqKillCount)
                        {
                            SetQuestObjectiveData(qInfo, obj.StorageIndex, curKillCount + addKillCount);
                            SendQuestUpdateAddCredit(qInfo, guid, obj, curKillCount + addKillCount);
                        }

                        if (CanCompleteQuest(questid))
                            CompleteQuest(questid);

                        // same objective target can be in many active quests, but not in 2 objectives for single quest (code optimization).
                        break;
                    }
                }
            }
        }
    }
}

void Player::KilledPlayerCredit()
{
    uint16 addKillCount = 1;

    for (uint8 i = 0; i < MAX_QUEST_LOG_SIZE; ++i)
    {
        uint32 questid = GetQuestSlotQuestId(i);
        if (!questid)
            continue;

        Quest const* qInfo = sObjectMgr->GetQuestTemplate(questid);
        if (!qInfo)
            continue;

        // This flag is only used for performance optimisation to prevent iterating over all quests
        if (!qInfo->HasSpecialFlag(QUEST_SPECIAL_FLAGS_PLAYER_KILL))
            continue;

        // just if !ingroup || !noraidgroup || raidgroup
        QuestStatusData& q_status = m_QuestStatus[questid];
        if (q_status.Status == QUEST_STATUS_INCOMPLETE && (!GetGroup() || !GetGroup()->isRaidGroup() || qInfo->IsAllowedInRaid(GetMap()->GetDifficultyID())))
        {
            for (QuestObjective const& obj : qInfo->GetObjectives())
            {
                if (obj.Type != QUEST_OBJECTIVE_PLAYERKILLS)
                    continue;

                uint32 curKillCount = GetQuestObjectiveData(qInfo, obj.StorageIndex);
                if (curKillCount < uint32(obj.Amount))
                {
                    SetQuestObjectiveData(qInfo, obj.StorageIndex, curKillCount + addKillCount);
                    SendQuestUpdateAddPlayer(qInfo, curKillCount + addKillCount, obj.Amount);
                }

                if (CanCompleteQuest(questid))
                    CompleteQuest(questid);

                // Quest can't have more than one player kill objective (code optimisation)
                break;
            }
        }
    }
}

void Player::KillCreditGO(uint32 entry, ObjectGuid guid)
{
    uint16 addCastCount = 1;
    for (uint8 i = 0; i < MAX_QUEST_LOG_SIZE; ++i)
    {
        uint32 questid = GetQuestSlotQuestId(i);
        if (!questid)
            continue;

        Quest const* qInfo = sObjectMgr->GetQuestTemplate(questid);
        if (!qInfo)
            continue;

        QuestStatusData& q_status = m_QuestStatus[questid];

        if (q_status.Status == QUEST_STATUS_INCOMPLETE)
        {
            if (qInfo->HasSpecialFlag(QUEST_SPECIAL_FLAGS_CAST) /*&& !qInfo->HasSpecialFlag(QUEST_SPECIAL_FLAGS_KILL)*/)
            {
                for (QuestObjective const& obj : qInfo->GetObjectives())
                {
                    if (obj.Type != QUEST_OBJECTIVE_GAMEOBJECT)
                        continue;

                    uint32 reqTarget = obj.ObjectID;

                    // other not this creature/GO related objectives
                    if (reqTarget != entry)
                        continue;

                    uint32 reqCastCount = obj.Amount;
                    uint32 curCastCount = GetQuestObjectiveData(qInfo, obj.StorageIndex);
                    if (curCastCount < reqCastCount)
                    {
                        SetQuestObjectiveData(qInfo, obj.StorageIndex, curCastCount + addCastCount);
                        SendQuestUpdateAddCredit(qInfo, guid, obj, curCastCount + addCastCount);
                    }

                    if (CanCompleteQuest(questid))
                        CompleteQuest(questid);

                    // same objective target can be in many active quests, but not in 2 objectives for single quest (code optimization).
                    break;
                }
            }
        }
    }
}

void Player::TalkedToCreature(uint32 entry, ObjectGuid guid)
{
    uint16 addTalkCount = 1;
    for (uint8 i = 0; i < MAX_QUEST_LOG_SIZE; ++i)
    {
        uint32 questid = GetQuestSlotQuestId(i);
        if (!questid)
            continue;

        Quest const* qInfo = sObjectMgr->GetQuestTemplate(questid);
        if (!qInfo)
            continue;

        QuestStatusData& q_status = m_QuestStatus[questid];

        if (q_status.Status == QUEST_STATUS_INCOMPLETE)
        {
            if (qInfo->HasSpecialFlag(QUEST_SPECIAL_FLAGS_KILL | QUEST_SPECIAL_FLAGS_CAST | QUEST_SPECIAL_FLAGS_SPEAKTO))
            {
                for (QuestObjective const& obj : qInfo->GetObjectives())
                {
                    if (obj.Type != QUEST_OBJECTIVE_TALKTO)
                        continue;

                    uint32 reqTarget = obj.ObjectID;

                    if (reqTarget == entry)
                    {
                        uint32 reqTalkCount = obj.Amount;
                        uint32 curTalkCount = GetQuestObjectiveData(qInfo, obj.StorageIndex);
                        if (curTalkCount < reqTalkCount)
                        {
                            SetQuestObjectiveData(qInfo, obj.StorageIndex, curTalkCount + addTalkCount);
                            SendQuestUpdateAddCredit(qInfo, guid, obj, curTalkCount + addTalkCount);
                        }

                        if (CanCompleteQuest(questid))
                            CompleteQuest(questid);

                        // Quest can't have more than one objective for the same creature (code optimisation)
                        break;
                    }
                }
            }
        }
    }
}

void Player::MoneyChanged(uint64 value)
{
    for (uint8 i = 0; i < MAX_QUEST_LOG_SIZE; ++i)
    {
        uint32 questid = GetQuestSlotQuestId(i);
        if (!questid)
            continue;

        Quest const* qInfo = sObjectMgr->GetQuestTemplate(questid);
        if (!qInfo)
            continue;

        for (QuestObjective const& obj : qInfo->GetObjectives())
        {
            if (obj.Type != QUEST_OBJECTIVE_MONEY)
                continue;

            QuestStatusData& q_status = m_QuestStatus[questid];

            if (q_status.Status == QUEST_STATUS_INCOMPLETE)
            {
                if (int64(value) >= obj.Amount)
                {
                    if (CanCompleteQuest(questid))
                        CompleteQuest(questid);
                }
            }
            else if (q_status.Status == QUEST_STATUS_COMPLETE)
            {
                if (int64(value) < obj.Amount)
                    IncompleteQuest(questid);
            }
        }
    }
}

void Player::ReputationChanged(FactionEntry const* factionEntry)
{
    for (uint8 i = 0; i < MAX_QUEST_LOG_SIZE; ++i)
    {
        if (uint32 questid = GetQuestSlotQuestId(i))
        {
            if (Quest const* qInfo = sObjectMgr->GetQuestTemplate(questid))
            {
                QuestStatusData& q_status = m_QuestStatus[questid];

                for (QuestObjective const& obj : qInfo->GetObjectives())
                {
                    if (uint32(obj.ObjectID) != factionEntry->ID)
                        continue;

                    if (obj.Type == QUEST_OBJECTIVE_MIN_REPUTATION)
                    {
                        if (q_status.Status == QUEST_STATUS_INCOMPLETE)
                        {
                            if (GetReputationMgr().GetReputation(factionEntry) >= obj.Amount)
                                if (CanCompleteQuest(questid))
                                    CompleteQuest(questid);
                        }
                        else if (q_status.Status == QUEST_STATUS_COMPLETE)
                        {
                            if (GetReputationMgr().GetReputation(factionEntry) < obj.Amount)
                                IncompleteQuest(questid);
                        }
                    }
                    else if (obj.Type == QUEST_OBJECTIVE_MAX_REPUTATION)
                    {
                        if (q_status.Status == QUEST_STATUS_INCOMPLETE)
                        {
                            if (GetReputationMgr().GetReputation(factionEntry) <= obj.Amount)
                                if (CanCompleteQuest(questid))
                                    CompleteQuest(questid);
                        }
                        else if (q_status.Status == QUEST_STATUS_COMPLETE)
                        {
                            if (GetReputationMgr().GetReputation(factionEntry) > obj.Amount)
                                IncompleteQuest(questid);
                        }
                    }
                }
            }
        }
    }
}

void Player::CurrencyChanged(uint32 currencyId, int32 change)
{
    for (uint8 i = 0; i < MAX_QUEST_LOG_SIZE; ++i)
    {
        uint32 questid = GetQuestSlotQuestId(i);
        if (!questid)
            continue;

        Quest const* qInfo = sObjectMgr->GetQuestTemplate(questid);
        if (!qInfo)
            continue;

        for (QuestObjective const& obj : qInfo->GetObjectives())
        {
            if (uint32(obj.ObjectID) != currencyId)
                continue;

            if (obj.Type != QUEST_OBJECTIVE_HAVE_CURRENCY)
                continue;

            QuestStatusData& q_status = m_QuestStatus[questid];
            if (obj.Type == QUEST_OBJECTIVE_CURRENCY || obj.Type == QUEST_OBJECTIVE_HAVE_CURRENCY)
            {
                int64 value = GetCurrency(currencyId);
                if (obj.Type == QUEST_OBJECTIVE_HAVE_CURRENCY)
                    SetQuestObjectiveData(qInfo, obj.StorageIndex, int32(std::min<int64>(value, obj.Amount)));

                if (q_status.Status == QUEST_STATUS_INCOMPLETE)
                {
                    if (value >= obj.Amount)
                    {
                        if (CanCompleteQuest(questid))
                            CompleteQuest(questid);
                    }
                }
                else if (q_status.Status == QUEST_STATUS_COMPLETE)
                {
                    if (value < obj.Amount)
                        IncompleteQuest(questid);
                }
            }
            else if (obj.Type == QUEST_OBJECTIVE_OBTAIN_CURRENCY && change > 0) // currency losses are not accounted for in this objective type
            {
                int64 currentProgress = GetQuestObjectiveData(qInfo, obj.StorageIndex);
                SetQuestObjectiveData(qInfo, obj.StorageIndex, int32(std::max(std::min<int64>(currentProgress + change, obj.Amount), SI64LIT(0))));
                if (CanCompleteQuest(questid))
                    CompleteQuest(questid);
            }
        }
    }
}

bool Player::HasQuestForItem(uint32 itemid) const
{
    for (uint8 i = 0; i < MAX_QUEST_LOG_SIZE; ++i)
    {
        uint32 questid = GetQuestSlotQuestId(i);
        if (questid == 0)
            continue;

        QuestStatusMap::const_iterator qs_itr = m_QuestStatus.find(questid);
        if (qs_itr == m_QuestStatus.end())
            continue;

        QuestStatusData const& q_status = qs_itr->second;

        if (q_status.Status == QUEST_STATUS_INCOMPLETE)
        {
            Quest const* qInfo = sObjectMgr->GetQuestTemplate(questid);
            if (!qInfo)
                continue;

            // hide quest if player is in raid-group and quest is no raid quest
            if (GetGroup() && GetGroup()->isRaidGroup() && !qInfo->IsAllowedInRaid(GetMap()->GetDifficultyID()))
                if (!InBattleground()) //there are two ways.. we can make every bg-quest a raidquest, or add this code here.. i don't know if this can be exploited by other quests, but i think all other quests depend on a specific area.. but keep this in mind, if something strange happens later
                    continue;

            // There should be no mixed ReqItem/ReqSource drop
            // This part for ReqItem drop
            for (QuestObjective const& obj : qInfo->GetObjectives())
            {
                if (obj.Type == QUEST_OBJECTIVE_ITEM && itemid == uint32(obj.ObjectID) && GetQuestObjectiveData(qInfo, obj.StorageIndex) < obj.Amount)
                    return true;
            }
            // This part - for ReqSource
            for (uint8 j = 0; j < QUEST_ITEM_DROP_COUNT; ++j)
            {
                // examined item is a source item
                if (qInfo->ItemDrop[j] == itemid)
                {
                    ItemTemplate const* pProto = sObjectMgr->GetItemTemplate(itemid);

                    // 'unique' item
                    if (pProto->GetMaxCount() && GetItemCount(itemid, true) < pProto->GetMaxCount())
                        return true;

                    // allows custom amount drop when not 0
                    if (qInfo->ItemDropQuantity[j])
                    {
                        if (GetItemCount(itemid, true) < qInfo->ItemDropQuantity[j])
                            return true;
                    } else if (GetItemCount(itemid, true) < pProto->GetMaxStackSize())
                        return true;
                }
            }
        }
    }
    return false;
}

int32 Player::GetQuestObjectiveData(Quest const* quest, int8 storageIndex) const
{
    if (storageIndex < 0)
        TC_LOG_ERROR("entities.player.quest", "Player::GetQuestObjectiveData: Called for quest %u with invalid StorageIndex %d (objective data is not tracked)",
            quest->GetQuestId(), storageIndex);

    auto itr = m_QuestStatus.find(quest->GetQuestId());

    if (itr == m_QuestStatus.end())
    {
        TC_LOG_ERROR("entities.player.quest", "Player::GetQuestObjectiveData: Player '%s' (%s) doesn't have quest status data (QuestID: %u)",
            GetName().c_str(), GetGUID().ToString().c_str(), quest->GetQuestId());
        return 0;
    }

    QuestStatusData const& status = itr->second;

    if (uint8(storageIndex) >= status.ObjectiveData.size())
    {
        TC_LOG_ERROR("entities.player.quest", "Player::GetQuestObjectiveData: Player '%s' (%s) quest %u out of range StorageIndex %u",
            GetName().c_str(), GetGUID().ToString().c_str(), quest->GetQuestId(), storageIndex);
        return 0;
    }

    return status.ObjectiveData[storageIndex];
}

void Player::SetQuestObjectiveData(Quest const* quest, int8 storageIndex, int32 data)
{
    if (storageIndex < 0)
        TC_LOG_ERROR("entities.player.quest", "Player::SetQuestObjectiveData: called for quest %u with invalid StorageIndex %d (objective data is not tracked)",
            quest->GetQuestId(), storageIndex);

    auto itr = m_QuestStatus.find(quest->GetQuestId());

    if (itr == m_QuestStatus.end())
    {
        TC_LOG_ERROR("entities.player.quest", "Player::SetQuestObjectiveData: player '%s' (%s) doesn't have quest status data (QuestID: %u)",
            GetName().c_str(), GetGUID().ToString().c_str(), quest->GetQuestId());
        return;
    }

    QuestStatusData& status = itr->second;

    if (uint8(storageIndex) >= status.ObjectiveData.size())
    {
        TC_LOG_ERROR("entities.player.quest", "Player::SetQuestObjectiveData: player '%s' (%s) quest %u out of range StorageIndex %u",
            GetName().c_str(), GetGUID().ToString().c_str(), quest->GetQuestId(), storageIndex);
        return;
    }

    // No change
    if (status.ObjectiveData[storageIndex] == data)
        return;

    // Set data
    status.ObjectiveData[storageIndex] = data;

    // Add to save
    m_QuestStatusSave[quest->GetQuestId()] = QUEST_DEFAULT_SAVE_TYPE;

    // Update quest fields
    uint16 log_slot = FindQuestSlot(quest->GetQuestId());
    if (log_slot < MAX_QUEST_LOG_SIZE)
        SetQuestSlotCounter(log_slot, storageIndex, status.ObjectiveData[storageIndex]);
}

void Player::SendQuestComplete(Quest const* quest) const
{
    if (quest)
    {
        WorldPackets::Quest::QuestUpdateComplete data;
        data.QuestID = quest->GetQuestId();
        GetSession()->SendPacket(data.Write());
    }
}

void Player::SendQuestReward(Quest const* quest, uint32 XP) const
{
    uint32 questId = quest->GetQuestId();
    sGameEventMgr->HandleQuestComplete(questId);

    uint32 xp;
    uint32 moneyReward;

    if (getLevel() < sWorld->getIntConfig(CONFIG_MAX_PLAYER_LEVEL))
    {
        xp = XP;
        moneyReward = GetQuestMoneyReward(quest);
    }
    else // At max level, increase gold reward
    {
        xp = 0;
        moneyReward = uint32(GetQuestMoneyReward(quest) + int32(quest->GetRewMoneyMaxLevel() * sWorld->getRate(RATE_DROP_MONEY)));
    }

    WorldPackets::Quest::QuestGiverQuestComplete packet;

    packet.QuestID = questId;
    packet.MoneyReward = moneyReward;
    packet.XPReward = xp;
    packet.SkillLineIDReward = quest->GetRewardSkillId();
    packet.NumSkillUpsReward = quest->GetRewardSkillPoints();
    packet.TalentReward = quest->GetBonusTalents();

    // @todo fix these 3
    packet.UseQuestReward = true;
    packet.LaunchGossip = true;
    //packet.ItemReward

    GetSession()->SendPacket(packet.Write());
}

void Player::SendQuestFailed(uint32 questID, InventoryResult reason) const
{
    if (questID)
    {
        WorldPackets::Quest::QuestGiverQuestFailed questGiverQuestFailed;
        questGiverQuestFailed.QuestID = questID;
        questGiverQuestFailed.Reason = reason; // failed reason (valid reasons: 4, 16, 50, 17, other values show default message)
        GetSession()->SendPacket(questGiverQuestFailed.Write());
    }
}

void Player::SendQuestTimerFailed(uint32 questID) const
{
    if (questID)
    {
        WorldPackets::Quest::QuestUpdateFailedTimer questUpdateFailedTimer;
        questUpdateFailedTimer.QuestID = questID;
        GetSession()->SendPacket(questUpdateFailedTimer.Write());
    }
}

void Player::SendCanTakeQuestResponse(QuestFailedReason reason, bool sendErrorMessage /*= true*/, std::string reasonText /*= ""*/) const
{
    WorldPackets::Quest::QuestGiverInvalidQuest questGiverInvalidQuest;

    questGiverInvalidQuest.Reason = reason;
    questGiverInvalidQuest.SendErrorMessage = sendErrorMessage;
    questGiverInvalidQuest.ReasonText = reasonText;

    GetSession()->SendPacket(questGiverInvalidQuest.Write());
}

void Player::SendQuestConfirmAccept(Quest const* quest, Player* receiver) const
{
    if (!receiver)
        return;

    std::string questTitle = quest->GetLogTitle();
    uint32 questID = quest->GetQuestId();

    LocaleConstant localeConstant = receiver->GetSession()->GetSessionDbLocaleIndex();
    if (localeConstant >= LOCALE_enUS)
        if (QuestTemplateLocale const* questTemplateLocale = sObjectMgr->GetQuestLocale(questID))
            ObjectMgr::GetLocaleString(questTemplateLocale->LogTitle, localeConstant, questTitle);

    WorldPackets::Quest::QuestConfirmAcceptResponse packet;
    packet.QuestID = questID;
    packet.InitiatedBy = GetGUID();
    packet.QuestTitle = questTitle;

    receiver->GetSession()->SendPacket(packet.Write());
}

void Player::SendPushToPartyResponse(Player* player, QuestPushReason reason) const
{
    if (player)
    {
        WorldPackets::Quest::QuestPushResultResponse data;
        data.SenderGUID = player->GetGUID();
        data.Result = reason; // valid values: 0-13
        SendDirectMessage(data.Write());
    }
}

void Player::SendQuestUpdateAddCredit(Quest const* quest, ObjectGuid guid, QuestObjective const& obj, uint16 count) const
{
    WorldPackets::Quest::QuestUpdateAddCredit packet;
    packet.VictimGUID = guid;
    packet.QuestID = quest->GetQuestId();
    packet.ObjectID = obj.ObjectID;
    packet.Count = count;
    packet.Required = obj.Amount;
    packet.ObjectiveType = obj.Type;
    GetSession()->SendPacket(packet.Write());
}

void Player::SendQuestUpdateAddPlayer(Quest const* quest, uint16 newCount, uint32 required) const
{
    WorldPacket data(SMSG_QUEST_UPDATE_ADD_PVP_CREDIT, (3*4));
    data << uint32(quest->GetQuestId());
    data << uint32(newCount);
    data << uint32(required);
    GetSession()->SendPacket(&data);
}

bool Player::HasPvPForcingQuest() const
{
    for (uint8 i = 0; i < MAX_QUEST_LOG_SIZE; ++i)
    {
        uint32 questId = GetQuestSlotQuestId(i);
        if (questId == 0)
            continue;

        Quest const* quest = sObjectMgr->GetQuestTemplate(questId);
        if (!quest)
            continue;

        if (quest->HasFlag(QUEST_FLAGS_FLAGS_PVP))
            return true;
    }

    return false;
}

/*********************************************************/
/***                   LOAD SYSTEM                     ***/
/*********************************************************/

void Player::_LoadDeclinedNames(PreparedQueryResult result)
{
    if (!result)
        return;

    delete m_declinedname;
    m_declinedname = new DeclinedName;
    for (uint8 i = 0; i < MAX_DECLINED_NAME_CASES; ++i)
        m_declinedname->name[i] = (*result)[i].GetString();
}

void Player::_LoadArenaTeamInfo(PreparedQueryResult result)
{
    // arenateamid, played_week, played_season, personal_rating
    memset((void*)&m_uint32Values[PLAYER_FIELD_ARENA_TEAM_INFO_1_1], 0, sizeof(uint32) * MAX_ARENA_SLOT * ARENA_TEAM_END);

    uint16 personalRatingCache[] = {0, 0, 0};

    if (result)
    {
        do
        {
            Field* fields = result->Fetch();

            uint32 arenaTeamId = fields[0].GetUInt32();

            ArenaTeam* arenaTeam = sArenaTeamMgr->GetArenaTeamById(arenaTeamId);
            if (!arenaTeam)
            {
                TC_LOG_ERROR("entities.player", "Player::_LoadArenaTeamInfo: couldn't load arenateam %u", arenaTeamId);
                continue;
            }

            uint8 arenaSlot = arenaTeam->GetSlot();

            personalRatingCache[arenaSlot] = fields[4].GetUInt16();

            SetArenaTeamInfoField(arenaSlot, ARENA_TEAM_ID, arenaTeamId);
            SetArenaTeamInfoField(arenaSlot, ARENA_TEAM_TYPE, arenaTeam->GetType());
            SetArenaTeamInfoField(arenaSlot, ARENA_TEAM_MEMBER, (arenaTeam->GetCaptain() == GetGUID()) ? 0 : 1);
            SetArenaTeamInfoField(arenaSlot, ARENA_TEAM_GAMES_WEEK, uint32(fields[1].GetUInt16()));
            SetArenaTeamInfoField(arenaSlot, ARENA_TEAM_GAMES_SEASON, uint32(fields[2].GetUInt16()));
            SetArenaTeamInfoField(arenaSlot, ARENA_TEAM_WINS_SEASON, uint32(fields[3].GetUInt16()));
        }
        while (result->NextRow());
    }

    for (uint8 slot = 0; slot <= 2; ++slot)
    {
        SetArenaTeamInfoField(slot, ARENA_TEAM_PERSONAL_RATING, uint32(personalRatingCache[slot]));
    }
}

void Player::_LoadEquipmentSets(PreparedQueryResult result)
{
    // SetPQuery(PLAYER_LOGIN_QUERY_LOADEQUIPMENTSETS,   "SELECT setguid, setindex, name, iconname, item0, item1, item2, item3, item4, item5, item6, item7, item8, item9, item10, item11, item12, item13, item14, item15, item16, item17, item18 FROM character_equipmentsets WHERE guid = '%u' ORDER BY setindex", GUID_LOPART(m_guid));
    if (!result)
        return;

    do
    {
        Field* fields = result->Fetch();
        EquipmentSetInfo eqSet;

        eqSet.Data.Guid       = fields[0].GetUInt64();
        eqSet.Data.SetID      = fields[1].GetUInt8();
        eqSet.Data.SetName    = fields[2].GetString();
        eqSet.Data.SetIcon    = fields[3].GetString();
        eqSet.Data.IgnoreMask = fields[4].GetUInt32();
        eqSet.State           = EQUIPMENT_SET_UNCHANGED;

        for (uint32 i = 0; i < EQUIPMENT_SLOT_END; ++i)
            if (ObjectGuid::LowType guid = fields[5 + i].GetUInt64())
                eqSet.Data.Pieces[i] = ObjectGuid::Create<HighGuid::Item>(guid);

        if (eqSet.Data.SetID >= MAX_EQUIPMENT_SET_INDEX)   // client limit
            continue;

        _equipmentSets[eqSet.Data.SetID] = eqSet;
    }
    while (result->NextRow());
}

void Player::_LoadBGData(PreparedQueryResult result)
{
    if (!result)
        return;

    Field* fields = result->Fetch();
    // Expecting only one row
    //        0           1     2      3      4      5      6          7          8        9
    // SELECT instanceId, team, joinX, joinY, joinZ, joinO, joinMapId, taxiStart, taxiEnd, mountSpell FROM character_battleground_data WHERE guid = ?

    m_bgData.bgInstanceID = fields[0].GetUInt32();
    m_bgData.bgTeam       = fields[1].GetUInt16();
    m_bgData.joinPos      = WorldLocation(fields[6].GetUInt16(),    // Map
                                          fields[2].GetFloat(),     // X
                                          fields[3].GetFloat(),     // Y
                                          fields[4].GetFloat(),     // Z
                                          fields[5].GetFloat());    // Orientation
    m_bgData.taxiPath[0]  = fields[7].GetUInt32();
    m_bgData.taxiPath[1]  = fields[8].GetUInt32();
    m_bgData.mountSpell   = fields[9].GetUInt32();
}

bool Player::LoadPositionFromDB(uint32& mapid, float& x, float& y, float& z, float& o, bool& in_flight, ObjectGuid guid)
{
    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHAR_POSITION);
    stmt->setUInt64(0, guid.GetCounter());
    PreparedQueryResult result = CharacterDatabase.Query(stmt);

    if (!result)
        return false;

    Field* fields = result->Fetch();

    x = fields[0].GetFloat();
    y = fields[1].GetFloat();
    z = fields[2].GetFloat();
    o = fields[3].GetFloat();
    mapid = fields[4].GetUInt16();
    in_flight = !fields[5].GetString().empty();

    return true;
}

void Player::SetHomebind(WorldLocation const& loc, uint32 areaId)
{
    loc.GetPosition(m_homebindX, m_homebindY, m_homebindZ);
    m_homebindMapId = loc.GetMapId();
    m_homebindAreaId = areaId;

    // update sql homebind
    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_PLAYER_HOMEBIND);
    stmt->setUInt16(0, m_homebindMapId);
    stmt->setUInt16(1, m_homebindAreaId);
    stmt->setFloat (2, m_homebindX);
    stmt->setFloat (3, m_homebindY);
    stmt->setFloat (4, m_homebindZ);
    stmt->setUInt64(5, GetGUID().GetCounter());
    CharacterDatabase.Execute(stmt);
}

void Player::SendBindPointUpdate() const
{
    WorldPackets::Misc::BindPointUpdate packet;
    packet.BindPosition.x = m_homebindX;
    packet.BindPosition.y = m_homebindY;
    packet.BindPosition.z = m_homebindZ;
    packet.BindMapID = m_homebindMapId;
    packet.BindAreaID = m_homebindAreaId;
    SendDirectMessage(packet.Write());
}

uint32 Player::GetUInt32ValueFromArray(Tokenizer const& data, uint16 index)
{
    if (index >= data.size())
        return 0;

    return (uint32)atoi(data[index]);
}

float Player::GetFloatValueFromArray(Tokenizer const& data, uint16 index)
{
    float result;
    uint32 temp = Player::GetUInt32ValueFromArray(data, index);
    memcpy(&result, &temp, sizeof(result));

    return result;
}

bool Player::IsLoading() const
{
    return GetSession()->PlayerLoading();
}

bool Player::LoadFromDB(ObjectGuid guid, SQLQueryHolder *holder)
{
    //        0     1        2     3     4      5       6      7   8      9     10    11         12         13           14         15         16
    //"SELECT guid, account, name, race, class, gender, level, xp, money, skin, face, hairStyle, hairColor, facialStyle, bankSlots, restState, playerFlags, "
    // 17          18          19          20   21           22        23         24         25         26          27           28                 29
    //"position_x, position_y, position_z, map, orientation, taximask, cinematic, totaltime, leveltime, rest_bonus, logout_time, is_logout_resting, resettalents_cost, "
    // 30                 31          32       33       34       35       36         37           38            39        40    41      42                 43         44
    //"resettalents_time, talentTree, trans_x, trans_y, trans_z, trans_o, transguid, extra_flags, stable_slots, at_login, zone, online, death_expire_time, taxi_path, dungeonDifficulty, "
    // 45          46          47              48           49              50
    //"totalKills, todayKills, yesterdayKills, chosenTitle, watchedFaction, drunk, "
    // 51      52      53      54      55      56      57      58           59         60          61          62             63
    //"health, power1, power2, power3, power4, power5, power6, instance_id, speccount, activespec, lootSpecId, exploredZones, equipmentCache, "
    // 64           65          66               67              68
    //"knownTitles, actionBars, grantableLevels, raidDifficulty, legacyRaidDifficulty FROM characters WHERE guid = '%u'", guid);
    PreparedQueryResult result = holder->GetPreparedResult(PLAYER_LOGIN_QUERY_LOAD_FROM);
    if (!result)
    {
        std::string name = "<unknown>";
        ObjectMgr::GetPlayerNameByGUID(guid, name);
        TC_LOG_ERROR("entities.player", "Player::LoadFromDB: Player '%s' (%s) not found in table `characters`, can't load. ", name.c_str(), guid.ToString().c_str());
        return false;
    }

    Field* fields = result->Fetch();

    uint32 dbAccountId = fields[1].GetUInt32();

    // check if the character's account in the db and the logged in account match.
    // player should be able to load/delete character only with correct account!
    if (dbAccountId != GetSession()->GetAccountId())
    {
        TC_LOG_ERROR("entities.player", "Player::LoadFromDB: Player (%s) loading from wrong account (is: %u, should be: %u)", guid.ToString().c_str(), GetSession()->GetAccountId(), dbAccountId);
        return false;
    }

    if (holder->GetPreparedResult(PLAYER_LOGIN_QUERY_LOAD_BANNED))
    {
        TC_LOG_ERROR("entities.player", "Player::LoadFromDB: Player (%s) is banned, can't load.", guid.ToString().c_str());
        return false;
    }

    Object::_Create(guid);

    m_name = fields[2].GetString();

    // check name limitations
    if (ObjectMgr::CheckPlayerName(m_name, GetSession()->GetSessionDbcLocale()) != CHAR_NAME_SUCCESS ||
        (!GetSession()->HasPermission(rbac::RBAC_PERM_SKIP_CHECK_CHARACTER_CREATION_RESERVEDNAME) && sObjectMgr->IsReservedName(m_name)))
    {
        PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_ADD_AT_LOGIN_FLAG);
        stmt->setUInt16(0, uint16(AT_LOGIN_RENAME));
        stmt->setUInt64(1, guid.GetCounter());
        CharacterDatabase.Execute(stmt);
        return false;
    }

    // overwrite possible wrong/corrupted guid
    SetGuidValue(OBJECT_FIELD_GUID, guid);

    uint8 gender = fields[5].GetUInt8();
    if (!IsValidGender(gender))
    {
        TC_LOG_ERROR("entities.player", "Player::LoadFromDB: Player (%s) has wrong gender (%u), can't load.", guid.ToString().c_str(), gender);
        return false;
    }

    SetByteValue(UNIT_FIELD_BYTES_0, UNIT_BYTES_0_OFFSET_RACE, fields[3].GetUInt8());
    SetByteValue(UNIT_FIELD_BYTES_0, UNIT_BYTES_0_OFFSET_CLASS, fields[4].GetUInt8());
    SetByteValue(UNIT_FIELD_BYTES_0, UNIT_BYTES_0_OFFSET_GENDER, gender);

    // check if race/class combination is valid
    PlayerInfo const* info = sObjectMgr->GetPlayerInfo(getRace(), getClass());
    if (!info)
    {
        TC_LOG_ERROR("entities.player", "Player::LoadFromDB: Player (%s) has wrong race/class (%u/%u), can't load.", guid.ToString().c_str(), getRace(), getClass());
        return false;
    }

    SetUInt32Value(UNIT_FIELD_LEVEL, fields[6].GetUInt8());
    SetUInt32Value(PLAYER_XP, fields[7].GetUInt32());

    _LoadIntoDataField(fields[62].GetCString(), PLAYER_EXPLORED_ZONES_1, PLAYER_EXPLORED_ZONES_SIZE);
    _LoadIntoDataField(fields[64].GetCString(), PLAYER__FIELD_KNOWN_TITLES, KNOWN_TITLES_SIZE * 2);

    SetObjectScale(1.0f);
    SetFloatValue(UNIT_FIELD_HOVERHEIGHT, 1.0f);

    // load achievements before anything else to prevent multiple gains for the same achievement/criteria on every loading (as loading does call UpdateAchievementCriteria)
    m_achievementMgr->LoadFromDB(holder->GetPreparedResult(PLAYER_LOGIN_QUERY_LOAD_ACHIEVEMENTS), holder->GetPreparedResult(PLAYER_LOGIN_QUERY_LOAD_CRITERIA_PROGRESS));

    uint64 money = fields[8].GetUInt64();
    if (money > MAX_MONEY_AMOUNT)
        money = MAX_MONEY_AMOUNT;
    SetMoney(money);

    SetByteValue(PLAYER_BYTES, PLAYER_BYTES_OFFSET_SKIN_ID, fields[9].GetUInt8());
    SetByteValue(PLAYER_BYTES, PLAYER_BYTES_OFFSET_FACE_ID, fields[10].GetUInt8());
    SetByteValue(PLAYER_BYTES, PLAYER_BYTES_OFFSET_HAIR_STYLE_ID, fields[11].GetUInt8());
    SetByteValue(PLAYER_BYTES, PLAYER_BYTES_OFFSET_HAIR_COLOR_ID, fields[12].GetUInt8());
    SetByteValue(PLAYER_BYTES_2, PLAYER_BYTES_2_OFFSET_FACIAL_STYLE, fields[13].GetUInt8());
    SetByteValue(PLAYER_BYTES_2, PLAYER_BYTES_2_OFFSET_BANK_BAG_SLOTS, fields[14].GetUInt8());
    SetByteValue(PLAYER_BYTES_2, PLAYER_BYTES_2_OFFSET_REST_STATE, fields[15].GetUInt8());
    SetByteValue(PLAYER_BYTES_3, PLAYER_BYTES_3_OFFSET_GENDER, gender);
    SetByteValue(PLAYER_BYTES_3, PLAYER_BYTES_3_OFFSET_INEBRIATION, fields[50].GetUInt8());
    SetUInt32Value(PLAYER_FLAGS, fields[16].GetUInt32());
    SetInt32Value(PLAYER_FIELD_WATCHED_FACTION_INDEX, fields[49].GetUInt32());

    if (!ValidateAppearance(
        fields[3].GetUInt8(), // race
        fields[4].GetUInt8(), // class
        gender,
        GetByteValue(PLAYER_BYTES, PLAYER_BYTES_OFFSET_HAIR_STYLE_ID),
        GetByteValue(PLAYER_BYTES, PLAYER_BYTES_OFFSET_HAIR_COLOR_ID),
        GetByteValue(PLAYER_BYTES, PLAYER_BYTES_OFFSET_FACE_ID),
        GetByteValue(PLAYER_BYTES_2, PLAYER_BYTES_2_OFFSET_FACIAL_STYLE),
        GetByteValue(PLAYER_BYTES, PLAYER_BYTES_OFFSET_SKIN_ID)))
    {
        TC_LOG_ERROR("entities.player", "Player::LoadFromDB: Player (%s) has wrong Appearance values (Hair/Skin/Color), can't load.", guid.ToString().c_str());
        return false;
    }

    // set which actionbars the client has active - DO NOT REMOVE EVER AGAIN (can be changed though, if it does change fieldwise)
    SetByteValue(PLAYER_FIELD_BYTES, PLAYER_FIELD_BYTES_OFFSET_ACTION_BAR_TOGGLES, fields[65].GetUInt8());

    InitDisplayIds();

    // cleanup inventory related item value fields (its will be filled correctly in _LoadInventory)
    for (uint8 slot = EQUIPMENT_SLOT_START; slot < EQUIPMENT_SLOT_END; ++slot)
    {
        SetGuidValue(PLAYER_FIELD_INV_SLOT_HEAD + (slot * 4), ObjectGuid::Empty);
        SetVisibleItemSlot(slot, nullptr);

        delete m_items[slot];
        m_items[slot] = nullptr;
    }

    TC_LOG_DEBUG("entities.player.loading", "Player::LoadFromDB: Load Basic value of player '%s' is: ", m_name.c_str());
    outDebugValues();

    //Need to call it to initialize m_team (m_team can be calculated from race)
    //Other way is to saves m_team into characters table.
    setFactionForRace(getRace());

    // load home bind and check in same time class/race pair, it used later for restore broken positions
    if (!_LoadHomeBind(holder->GetPreparedResult(PLAYER_LOGIN_QUERY_LOAD_HOME_BIND)))
        return false;

    InitPrimaryProfessions();                               // to max set before any spell loaded

    // init saved position, and fix it later if problematic
    ObjectGuid::LowType transLowGUID = fields[36].GetUInt64();

    Relocate(fields[17].GetFloat(), fields[18].GetFloat(), fields[19].GetFloat(), fields[21].GetFloat());

    uint32 mapId = fields[20].GetUInt16();
    uint32 instanceId = fields[58].GetUInt32();

    SetDungeonDifficultyID(CheckLoadedDungeonDifficultyID(Difficulty(fields[44].GetUInt8())));
    SetRaidDifficultyID(CheckLoadedRaidDifficultyID(Difficulty(fields[67].GetUInt8())));
    SetLegacyRaidDifficultyID(CheckLoadedLegacyRaidDifficultyID(Difficulty(fields[68].GetUInt8())));

    std::string taxi_nodes = fields[43].GetString();

#define RelocateToHomebind(){ mapId = m_homebindMapId; instanceId = 0; Relocate(m_homebindX, m_homebindY, m_homebindZ); }

    _LoadGroup(holder->GetPreparedResult(PLAYER_LOGIN_QUERY_LOAD_GROUP));

    _LoadArenaTeamInfo(holder->GetPreparedResult(PLAYER_LOGIN_QUERY_LOAD_ARENA_INFO));

    // check arena teams integrity
    for (uint32 arena_slot = 0; arena_slot < MAX_ARENA_SLOT; ++arena_slot)
    {
        uint32 arena_team_id = GetArenaTeamId(arena_slot);
        if (!arena_team_id)
            continue;

        if (ArenaTeam* at = sArenaTeamMgr->GetArenaTeamById(arena_team_id))
            if (at->IsMember(GetGUID()))
                continue;

        // arena team not exist or not member, cleanup fields
        for (int j = 0; j < 6; ++j)
            SetArenaTeamInfoField(arena_slot, ArenaTeamInfoType(j), 0);
    }

    _LoadCurrency(holder->GetPreparedResult(PLAYER_LOGIN_QUERY_LOAD_CURRENCY));
    SetUInt32Value(PLAYER_FIELD_LIFETIME_HONORABLE_KILLS, fields[45].GetUInt32());
    SetUInt16Value(PLAYER_FIELD_KILLS, PLAYER_FIELD_KILLS_OFFSET_TODAY_KILLS, fields[46].GetUInt16());
    SetUInt16Value(PLAYER_FIELD_KILLS, PLAYER_FIELD_KILLS_OFFSET_YESTERDAY_KILLS, fields[47].GetUInt16());

    _LoadBoundInstances(holder->GetPreparedResult(PLAYER_LOGIN_QUERY_LOAD_BOUND_INSTANCES));
    _LoadInstanceTimeRestrictions(holder->GetPreparedResult(PLAYER_LOGIN_QUERY_LOAD_INSTANCE_LOCK_TIMES));
    _LoadBGData(holder->GetPreparedResult(PLAYER_LOGIN_QUERY_LOAD_BG_DATA));

    GetSession()->SetPlayer(this);
    MapEntry const* mapEntry = sMapStore.LookupEntry(mapId);
    if (!mapEntry || !IsPositionValid())
    {
        TC_LOG_ERROR("entities.player", "Player::LoadFromDB: Player (%s) has invalid coordinates (MapId: %u X: %f Y: %f Z: %f O: %f). Teleport to default race/class locations.",
            guid.ToString().c_str(), mapId, GetPositionX(), GetPositionY(), GetPositionZ(), GetOrientation());
        RelocateToHomebind();
    }
    // Player was saved in Arena or Bg
    else if (mapEntry && mapEntry->IsBattlegroundOrArena())
    {
        Battleground* currentBg = nullptr;
        if (m_bgData.bgInstanceID)                                                //saved in Battleground
            currentBg = sBattlegroundMgr->GetBattleground(m_bgData.bgInstanceID, BATTLEGROUND_TYPE_NONE);

        bool player_at_bg = currentBg && currentBg->IsPlayerInBattleground(GetGUID());

        if (player_at_bg && currentBg->GetStatus() != STATUS_WAIT_LEAVE)
        {
            BattlegroundQueueTypeId bgQueueTypeId = sBattlegroundMgr->BGQueueTypeId(currentBg->GetTypeID(), currentBg->GetArenaType());
            AddBattlegroundQueueId(bgQueueTypeId);

            m_bgData.bgTypeID = currentBg->GetTypeID();

            //join player to battleground group
            currentBg->EventPlayerLoggedIn(this);
            currentBg->AddOrSetPlayerToCorrectBgGroup(this, m_bgData.bgTeam);

            SetInviteForBattlegroundQueueType(bgQueueTypeId, currentBg->GetInstanceID());
        }
        // Bg was not found - go to Entry Point
        else
        {
            // leave bg
            if (player_at_bg)
                currentBg->RemovePlayerAtLeave(GetGUID(), false, true);

            // Do not look for instance if bg not found
            const WorldLocation& _loc = GetBattlegroundEntryPoint();
            mapId = _loc.GetMapId(); instanceId = 0;

            // Db field type is type int16, so it can never be MAPID_INVALID
            //if (mapId == MAPID_INVALID) -- code kept for reference
            if (int16(mapId) == int16(-1)) // Battleground Entry Point not found (???)
            {
                TC_LOG_ERROR("entities.player", "Player::LoadFromDB: Player (%s) was in BG in database, but BG was not found and entry point was invalid! Teleport to default race/class locations.",
                    guid.ToString().c_str());
                RelocateToHomebind();
            }
            else
                Relocate(&_loc);

            // We are not in BG anymore
            m_bgData.bgInstanceID = 0;
        }
    }
    // currently we do not support transport in bg
    else if (transLowGUID)
    {
        ObjectGuid transGUID = ObjectGuid::Create<HighGuid::Transport>(transLowGUID);

        Transport* transport = nullptr;
        if (Transport* go = HashMapHolder<Transport>::Find(transGUID))
            transport = go;

        if (transport)
        {
            float x = fields[32].GetFloat(), y = fields[33].GetFloat(), z = fields[34].GetFloat(), o = fields[35].GetFloat();
            m_movementInfo.transport.pos.Relocate(x, y, z, o);
            transport->CalculatePassengerPosition(x, y, z, &o);

            if (!Trinity::IsValidMapCoord(x, y, z, o) ||
                // transport size limited
                std::fabs(m_movementInfo.transport.pos.GetPositionX()) > 250.0f ||
                std::fabs(m_movementInfo.transport.pos.GetPositionY()) > 250.0f ||
                std::fabs(m_movementInfo.transport.pos.GetPositionZ()) > 250.0f)
            {
                TC_LOG_ERROR("entities.player", "Player::LoadFromDB: Player (%s) has invalid transport coordinates (X: %f Y: %f Z: %f O: %f). Teleport to bind location.",
                    guid.ToString().c_str(), x, y, z, o);

                m_movementInfo.transport.Reset();

                RelocateToHomebind();
            }
            else
            {
                Relocate(x, y, z, o);
                mapId = transport->GetMapId();

                transport->AddPassenger(this);
            }
        }
        else
        {
            TC_LOG_ERROR("entities.player", "Player::LoadFromDB: Player (%s) has problems with transport guid (" UI64FMTD "). Teleport to bind location.",
                guid.ToString().c_str(), transLowGUID);

            RelocateToHomebind();
        }
    }
    // currently we do not support taxi in instance
    else if (!taxi_nodes.empty())
    {
        instanceId = 0;

        // Not finish taxi flight path
        if (m_bgData.HasTaxiPath())
        {
            for (int i = 0; i < 2; ++i)
                m_taxi.AddTaxiDestination(m_bgData.taxiPath[i]);
        }
        else if (!m_taxi.LoadTaxiDestinationsFromString(taxi_nodes, GetTeam()))
        {
            // problems with taxi path loading
            TaxiNodesEntry const* nodeEntry = nullptr;
            if (uint32 node_id = m_taxi.GetTaxiSource())
                nodeEntry = sTaxiNodesStore.LookupEntry(node_id);

            if (!nodeEntry)                                      // don't know taxi start node, to homebind
            {
                TC_LOG_ERROR("entities.player", "Player::LoadFromDB: Player (%s) has wrong data in taxi destination list, teleport to homebind.", GetGUID().ToString().c_str());
                RelocateToHomebind();
            }
            else                                                // have start node, to it
            {
                TC_LOG_ERROR("entities.player", "Player::LoadFromDB: Player (%s) has too short taxi destination list, teleport to original node.", GetGUID().ToString().c_str());
                mapId = nodeEntry->MapID;
                Relocate(nodeEntry->Pos.X, nodeEntry->Pos.Y, nodeEntry->Pos.Z, 0.0f);
            }
            m_taxi.ClearTaxiDestinations();
        }

        if (uint32 node_id = m_taxi.GetTaxiSource())
        {
            // save source node as recall coord to prevent recall and fall from sky
            TaxiNodesEntry const* nodeEntry = sTaxiNodesStore.LookupEntry(node_id);
            if (nodeEntry && nodeEntry->MapID == GetMapId())
            {
                ASSERT(nodeEntry);                                  // checked in m_taxi.LoadTaxiDestinationsFromString
                mapId = nodeEntry->MapID;
                Relocate(nodeEntry->Pos.X, nodeEntry->Pos.Y, nodeEntry->Pos.Z, 0.0f);
            }

            // flight will started later
        }
    }

    // Map could be changed before
    mapEntry = sMapStore.LookupEntry(mapId);
    // client without expansion support
    if (mapEntry)
    {
        if (GetSession()->GetExpansion() < mapEntry->Expansion())
        {
            TC_LOG_DEBUG("entities.player.loading", "Player::LoadFromDB: Player '%s' (%s) using client without required expansion tried login at non accessible map %u",
                GetName().c_str(), GetGUID().ToString().c_str(), mapId);
            RelocateToHomebind();
        }

        // fix crash (because of if (Map* map = _FindMap(instanceId)) in MapInstanced::CreateInstance)
        if (instanceId)
            if (InstanceSave* save = GetInstanceSave(mapId))
                if (save->GetInstanceId() != instanceId)
                    instanceId = 0;
    }

    // NOW player must have valid map
    // load the player's map here if it's not already loaded
    Map* map = sMapMgr->CreateMap(mapId, this, instanceId);
    AreaTriggerStruct const* areaTrigger = nullptr;
    bool check = false;

    if (!map)
    {
        areaTrigger = sObjectMgr->GetGoBackTrigger(mapId);
        check = true;
    }
    else if (map->IsDungeon()) // if map is dungeon...
    {
        if (Map::EnterState denyReason = ((InstanceMap*)map)->CannotEnter(this)) // ... and can't enter map, then look for entry point.
        {
            switch (denyReason)
            {
                case Map::CANNOT_ENTER_DIFFICULTY_UNAVAILABLE:
                    SendTransferAborted(map->GetId(), TRANSFER_ABORT_DIFFICULTY, map->GetDifficultyID());
                    break;
                case Map::CANNOT_ENTER_INSTANCE_BIND_MISMATCH:
                    ChatHandler(GetSession()).PSendSysMessage(GetSession()->GetTrinityString(LANG_INSTANCE_BIND_MISMATCH), map->GetMapName());
                    break;
                case Map::CANNOT_ENTER_TOO_MANY_INSTANCES:
                    SendTransferAborted(map->GetId(), TRANSFER_ABORT_TOO_MANY_INSTANCES);
                    break;
                case Map::CANNOT_ENTER_MAX_PLAYERS:
                    SendTransferAborted(map->GetId(), TRANSFER_ABORT_MAX_PLAYERS);
                    break;
                case Map::CANNOT_ENTER_ZONE_IN_COMBAT:
                    SendTransferAborted(map->GetId(), TRANSFER_ABORT_ZONE_IN_COMBAT);
                    break;
                default:
                    break;
            }
            areaTrigger = sObjectMgr->GetGoBackTrigger(mapId);
            check = true;
        }
        else if (instanceId && !sInstanceSaveMgr->GetInstanceSave(instanceId)) // ... and instance is reseted then look for entrance.
        {
            areaTrigger = sObjectMgr->GetMapEntranceTrigger(mapId);
            check = true;
        }
    }

    if (check) // in case of special event when creating map...
    {
        if (areaTrigger) // ... if we have an areatrigger, then relocate to new map/coordinates.
        {
            Relocate(areaTrigger->target_X, areaTrigger->target_Y, areaTrigger->target_Z, GetOrientation());
            if (mapId != areaTrigger->target_mapId)
            {
                mapId = areaTrigger->target_mapId;
                map = sMapMgr->CreateMap(mapId, this);
            }
        }
        else
        {
            TC_LOG_ERROR("entities.player", "Player::LoadFromDB: Player '%s' (%s) Map: %u, X: %f, Y: %f, Z: %f, O: %f. Areatrigger not found.",
                m_name.c_str(), guid.ToString().c_str(), mapId, GetPositionX(), GetPositionY(), GetPositionZ(), GetOrientation());
            RelocateToHomebind();
            map = nullptr;
        }
    }

    if (!map)
    {
        mapId = info->mapId;
        Relocate(info->positionX, info->positionY, info->positionZ, 0.0f);
        map = sMapMgr->CreateMap(mapId, this);
        if (!map)
        {
            TC_LOG_ERROR("entities.player", "Player::LoadFromDB: Player '%s' (%s) Map: %u, X: %f, Y: %f, Z: %f, O: %f. Invalid default map coordinates or instance couldn't be created.",
                m_name.c_str(), guid.ToString().c_str(), mapId, GetPositionX(), GetPositionY(), GetPositionZ(), GetOrientation());
            return false;
        }
    }

    SetMap(map);

    // now that map position is determined, check instance validity
    if (!CheckInstanceValidity(true) && !IsInstanceLoginGameMasterException())
        m_InstanceValid = false;

    // randomize first save time in range [CONFIG_INTERVAL_SAVE] around [CONFIG_INTERVAL_SAVE]
    // this must help in case next save after mass player load after server startup
    m_nextSave = urand(m_nextSave / 2, m_nextSave * 3 / 2);

    SaveRecallPosition();

    time_t now = time(nullptr);
    time_t logoutTime = time_t(fields[27].GetUInt32());

    // since last logout (in seconds)
    uint32 time_diff = uint32(now - logoutTime); //uint64 is excessive for a time_diff in seconds.. uint32 allows for 136~ year difference.

    // set value, including drunk invisibility detection
    // calculate sobering. after 15 minutes logged out, the player will be sober again
    uint8 newDrunkValue = 0;
    if (time_diff < uint32(GetDrunkValue()) * 9)
        newDrunkValue = GetDrunkValue() - time_diff / 9;

    SetDrunkValue(newDrunkValue);

    m_cinematic = fields[23].GetUInt8();
    m_Played_time[PLAYED_TIME_TOTAL] = fields[24].GetUInt32();
    m_Played_time[PLAYED_TIME_LEVEL] = fields[25].GetUInt32();

    SetTalentResetCost(fields[29].GetUInt32());
    SetTalentResetTime(time_t(fields[30].GetUInt32()));

    m_taxi.LoadTaxiMask(fields[22].GetString());                // must be before InitTaxiNodesForLevel

    uint32 extraflags = fields[37].GetUInt16();

    m_stableSlots = fields[38].GetUInt8();
    if (m_stableSlots > MAX_PET_STABLES)
    {
        TC_LOG_ERROR("entities.player", "Player::LoadFromDB: Player (%s) can't have more stable slots than %u, but has %u in DB",
            GetGUID().ToString().c_str(), MAX_PET_STABLES, uint32(m_stableSlots));
        m_stableSlots = MAX_PET_STABLES;
    }

    m_atLoginFlags = fields[39].GetUInt16();

    if (HasAtLoginFlag(AT_LOGIN_RENAME))
    {
        TC_LOG_ERROR("entities.player", "Player::LoadFromDB: Player (%s) tried to login while forced to rename, can't load.'", GetGUID().ToString().c_str());
        return false;
    }

    // Honor system
    // Update Honor kills data
    m_lastHonorUpdateTime = logoutTime;
    UpdateHonorFields();

    m_deathExpireTime = time_t(fields[42].GetUInt32());

    if (m_deathExpireTime > now + MAX_DEATH_COUNT * DEATH_EXPIRE_STEP)
        m_deathExpireTime = now + MAX_DEATH_COUNT * DEATH_EXPIRE_STEP - 1;

    // clear channel spell data (if saved at channel spell casting)
    SetChannelObjectGuid(ObjectGuid::Empty);
    SetUInt32Value(UNIT_CHANNEL_SPELL, 0);

    // clear charm/summon related fields
    SetOwnerGUID(ObjectGuid::Empty);
    SetGuidValue(UNIT_FIELD_CHARMEDBY, ObjectGuid::Empty);
    SetGuidValue(UNIT_FIELD_CHARM, ObjectGuid::Empty);
    SetGuidValue(UNIT_FIELD_SUMMON, ObjectGuid::Empty);
    SetGuidValue(PLAYER_FARSIGHT, ObjectGuid::Empty);
    SetCreatorGUID(ObjectGuid::Empty);

    RemoveFlag(UNIT_FIELD_FLAGS_2, UNIT_FLAG2_FORCE_MOVEMENT);

    // reset some aura modifiers before aura apply
    SetUInt32Value(PLAYER_TRACK_CREATURES, 0);
    SetUInt32Value(PLAYER_TRACK_RESOURCES, 0);

    // make sure the unit is considered out of combat for proper loading
    ClearInCombat();

    // make sure the unit is considered not in duel for proper loading
    SetGuidValue(PLAYER_DUEL_ARBITER, ObjectGuid::Empty);
    SetUInt32Value(PLAYER_DUEL_TEAM, 0);

    // reset stats before loading any modifiers
    InitStatsForLevel();
    InitGlyphsForLevel();
    InitTaxiNodesForLevel();
    InitRunes();

    // rest bonus can only be calculated after InitStatsForLevel()
    m_rest_bonus = fields[26].GetFloat();

    if (time_diff > 0)
    {
        //speed collect rest bonus in offline, in logout, far from tavern, city (section/in hour)
        float bubble0 = 0.031f;
        //speed collect rest bonus in offline, in logout, in tavern, city (section/in hour)
        float bubble1 = 0.125f;
        float bubble = fields[28].GetUInt8() > 0
            ? bubble1*sWorld->getRate(RATE_REST_OFFLINE_IN_TAVERN_OR_CITY)
            : bubble0*sWorld->getRate(RATE_REST_OFFLINE_IN_WILDERNESS);

        SetRestBonus(GetRestBonus() + time_diff*((float)GetUInt32Value(PLAYER_NEXT_LEVEL_XP) / 72000)*bubble);
    }

    // load skills after InitStatsForLevel because it triggering aura apply also
    _LoadSkills(holder->GetPreparedResult(PLAYER_LOGIN_QUERY_LOAD_SKILLS));
    UpdateSkillsForLevel(); //update skills after load, to make sure they are correctly update at player load

    SetTalentGroupsCount(fields[59].GetUInt8());
    SetActiveTalentGroup(fields[60].GetUInt8());

    uint32 lootSpecId = fields[61].GetUInt32();
    if (ChrSpecializationEntry const* chrSpec = sChrSpecializationStore.LookupEntry(lootSpecId))
    {
        if (chrSpec->ClassID == getClass())
            SetLootSpecId(lootSpecId);
    }

    // sanity check
    if (GetTalentGroupsCount() > MAX_TALENT_GROUPS || GetActiveTalentGroup() > MAX_TALENT_GROUP || GetTalentGroupsCount() < MIN_TALENT_GROUPS)
    {
        TC_LOG_ERROR("entities.player", "Player::LoadFromDB: Player %s (%s) has invalid SpecCount = %u and/or invalid ActiveSpec = %u.",
            GetName().c_str(), GetGUID().ToString().c_str(), GetTalentGroupsCount(), GetActiveTalentGroup());
        SetActiveTalentGroup(0);
    }

    // Only load selected specializations, learning mastery spells requires this
    Tokenizer talentSpecs(fields[31].GetString(), ' ', MAX_TALENT_GROUPS);
    for (uint8 i = 0; i < MAX_TALENT_GROUPS; ++i)
    {
        if (i >= talentSpecs.size())
            break;

        uint32 talentSpec = atoul(talentSpecs[i]);
        if (talentSpec)
        {
            if (sChrSpecializationStore.LookupEntry(talentSpec))
                SetSpecId(i, talentSpec);
            else
                SetAtLoginFlag(AT_LOGIN_RESET_TALENTS);
        }
    }

    SetUInt32Value(PLAYER_FIELD_CURRENT_SPEC_ID, GetSpecId(GetActiveTalentGroup()));

    _LoadTalents(holder->GetPreparedResult(PLAYER_LOGIN_QUERY_LOAD_TALENTS));
    _LoadSpells(holder->GetPreparedResult(PLAYER_LOGIN_QUERY_LOAD_SPELLS));
    GetSession()->GetCollectionMgr()->LoadToys();
    GetSession()->GetCollectionMgr()->LoadHeirlooms();

    LearnSpecializationSpells();

    _LoadGlyphs(holder->GetPreparedResult(PLAYER_LOGIN_QUERY_LOAD_GLYPHS));
    _LoadAuras(holder->GetPreparedResult(PLAYER_LOGIN_QUERY_LOAD_AURAS), holder->GetPreparedResult(PLAYER_LOGIN_QUERY_LOAD_AURA_EFFECTS), time_diff);
    _LoadGlyphAuras();
    // add ghost flag (must be after aura load: PLAYER_FLAGS_GHOST set in aura)
    if (HasFlag(PLAYER_FLAGS, PLAYER_FLAGS_GHOST))
        m_deathState = DEAD;

    // after spell load, learn rewarded spell if need also
    _LoadQuestStatus(holder->GetPreparedResult(PLAYER_LOGIN_QUERY_LOAD_QUEST_STATUS));
    _LoadQuestStatusObjectives(holder->GetPreparedResult(PLAYER_LOGIN_QUERY_LOAD_QUEST_STATUS_OBJECTIVES));
    _LoadQuestStatusRewarded(holder->GetPreparedResult(PLAYER_LOGIN_QUERY_LOAD_QUEST_STATUS_REW));
    _LoadDailyQuestStatus(holder->GetPreparedResult(PLAYER_LOGIN_QUERY_LOAD_DAILY_QUEST_STATUS));
    _LoadWeeklyQuestStatus(holder->GetPreparedResult(PLAYER_LOGIN_QUERY_LOAD_WEEKLY_QUEST_STATUS));
    _LoadSeasonalQuestStatus(holder->GetPreparedResult(PLAYER_LOGIN_QUERY_LOAD_SEASONAL_QUEST_STATUS));
    _LoadMonthlyQuestStatus(holder->GetPreparedResult(PLAYER_LOGIN_QUERY_LOAD_MONTHLY_QUEST_STATUS));
    _LoadRandomBGStatus(holder->GetPreparedResult(PLAYER_LOGIN_QUERY_LOAD_RANDOM_BG));

    // after spell and quest load
    InitTalentForLevel();
    LearnDefaultSkills();
    LearnCustomSpells();

    // must be before inventory (some items required reputation check)
    m_reputationMgr->LoadFromDB(holder->GetPreparedResult(PLAYER_LOGIN_QUERY_LOAD_REPUTATION));

    _LoadInventory(holder->GetPreparedResult(PLAYER_LOGIN_QUERY_LOAD_INVENTORY), time_diff);

    if (IsVoidStorageUnlocked())
        _LoadVoidStorage(holder->GetPreparedResult(PLAYER_LOGIN_QUERY_LOAD_VOID_STORAGE));

    // update items with duration and realtime
    UpdateItemDuration(time_diff, true);

    _LoadActions(holder->GetPreparedResult(PLAYER_LOGIN_QUERY_LOAD_ACTIONS));

    // unread mails and next delivery time, actual mails not loaded
    _LoadMailInit(holder->GetPreparedResult(PLAYER_LOGIN_QUERY_LOAD_MAIL_COUNT), holder->GetPreparedResult(PLAYER_LOGIN_QUERY_LOAD_MAIL_DATE));

    m_social = sSocialMgr->LoadFromDB(holder->GetPreparedResult(PLAYER_LOGIN_QUERY_LOAD_SOCIAL_LIST), GetGUID());

    // check PLAYER_CHOSEN_TITLE compatibility with PLAYER__FIELD_KNOWN_TITLES
    // note: PLAYER__FIELD_KNOWN_TITLES updated at quest status loaded
    uint32 curTitle = fields[48].GetUInt32();
    if (curTitle && !HasTitle(curTitle))
        curTitle = 0;

    SetUInt32Value(PLAYER_CHOSEN_TITLE, curTitle);

    // has to be called after last Relocate() in Player::LoadFromDB
    SetFallInformation(0, GetPositionZ());

    GetSpellHistory()->LoadFromDB<Player>(holder->GetPreparedResult(PLAYER_LOGIN_QUERY_LOAD_SPELL_COOLDOWNS), holder->GetPreparedResult(PLAYER_LOGIN_QUERY_LOAD_SPELL_CHARGES));

    // Spell code allow apply any auras to dead character in load time in aura/spell/item loading
    // Do now before stats re-calculation cleanup for ghost state unexpected auras
    if (!IsAlive())
        RemoveAllAurasOnDeath();
    else
        RemoveAllAurasRequiringDeadTarget();

    //apply all stat bonuses from items and auras
    SetCanModifyStats(true);
    UpdateAllStats();

    // restore remembered power/health values (but not more max values)
    uint32 savedHealth = fields[51].GetUInt32();
    SetHealth(savedHealth > GetMaxHealth() ? GetMaxHealth() : savedHealth);
    uint32 loadedPowers = 0;
    for (uint32 i = 0; i < MAX_POWERS; ++i)
    {
        if (GetPowerIndex(i) != MAX_POWERS)
        {
            uint32 savedPower = fields[52 + loadedPowers].GetUInt32();
            uint32 maxPower = GetUInt32Value(UNIT_FIELD_MAXPOWER + loadedPowers);
            SetPower(Powers(i), (savedPower > maxPower) ? maxPower : savedPower);
            if (++loadedPowers >= MAX_POWERS_PER_CLASS)
                break;
        }
    }

    for (; loadedPowers < MAX_POWERS_PER_CLASS; ++loadedPowers)
        SetUInt32Value(UNIT_FIELD_POWER + loadedPowers, 0);

    SetPower(POWER_ECLIPSE, 0);

    TC_LOG_DEBUG("entities.player.loading", "Player::LoadFromDB: The value of player '%s' after load item and aura is: ", m_name.c_str());
    outDebugValues();

    // GM state
    if (GetSession()->HasPermission(rbac::RBAC_PERM_RESTORE_SAVED_GM_STATE))
    {
        switch (sWorld->getIntConfig(CONFIG_GM_LOGIN_STATE))
        {
            default:
            case 0:                      break;             // disable
            case 1: SetGameMaster(true); break;             // enable
            case 2:                                         // save state
                if (extraflags & PLAYER_EXTRA_GM_ON)
                    SetGameMaster(true);
                break;
        }

        switch (sWorld->getIntConfig(CONFIG_GM_VISIBLE_STATE))
        {
            default:
            case 0: SetGMVisible(false); break;             // invisible
            case 1:                      break;             // visible
            case 2:                                         // save state
                if (extraflags & PLAYER_EXTRA_GM_INVISIBLE)
                    SetGMVisible(false);
                break;
        }

        switch (sWorld->getIntConfig(CONFIG_GM_CHAT))
        {
            default:
            case 0:                  break;                 // disable
            case 1: SetGMChat(true); break;                 // enable
            case 2:                                         // save state
                if (extraflags & PLAYER_EXTRA_GM_CHAT)
                    SetGMChat(true);
                break;
        }

        switch (sWorld->getIntConfig(CONFIG_GM_WHISPERING_TO))
        {
            default:
            case 0:                          break;         // disable
            case 1: SetAcceptWhispers(true); break;         // enable
            case 2:                                         // save state
                if (extraflags & PLAYER_EXTRA_ACCEPT_WHISPERS)
                    SetAcceptWhispers(true);
                break;
        }
    }

    // RaF stuff.
    m_grantableLevels = fields[66].GetUInt8();
    if (GetSession()->IsARecruiter() || (GetSession()->GetRecruiterId() != 0))
        SetFlag(OBJECT_DYNAMIC_FLAGS, UNIT_DYNFLAG_REFER_A_FRIEND);

    if (m_grantableLevels > 0)
        SetByteValue(PLAYER_FIELD_BYTES, PLAYER_FIELD_BYTES_OFFSET_RAF_GRANTABLE_LEVEL, 0x01);

    _LoadDeclinedNames(holder->GetPreparedResult(PLAYER_LOGIN_QUERY_LOAD_DECLINED_NAMES));

    _LoadEquipmentSets(holder->GetPreparedResult(PLAYER_LOGIN_QUERY_LOAD_EQUIPMENT_SETS));

    _LoadCUFProfiles(holder->GetPreparedResult(PLAYER_LOGIN_QUERY_LOAD_CUF_PROFILES));

    std::unique_ptr<Garrison> garrison = Trinity::make_unique<Garrison>(this);
    if (garrison->LoadFromDB(holder->GetPreparedResult(PLAYER_LOGIN_QUERY_LOAD_GARRISON),
        holder->GetPreparedResult(PLAYER_LOGIN_QUERY_LOAD_GARRISON_BLUEPRINTS),
        holder->GetPreparedResult(PLAYER_LOGIN_QUERY_LOAD_GARRISON_BUILDINGS),
        holder->GetPreparedResult(PLAYER_LOGIN_QUERY_LOAD_GARRISON_FOLLOWERS),
        holder->GetPreparedResult(PLAYER_LOGIN_QUERY_LOAD_GARRISON_FOLLOWER_ABILITIES)))
        _garrison = std::move(garrison);

    m_achievementMgr->CheckAllAchievementCriteria(this);
    return true;
}

void Player::_LoadCUFProfiles(PreparedQueryResult result)
{
    if (!result)
        return;

    do
    {
        // SELECT id, name, frameHeight, frameWidth, sortBy, healthText, boolOptions, unk146, unk147, unk148, unk150, unk152, unk154 FROM character_cuf_profiles WHERE guid = ?
        Field* fields = result->Fetch();

        uint8 id            = fields[0].GetUInt8();
        std::string name    = fields[1].GetString();
        uint16 frameHeight  = fields[2].GetUInt16();
        uint16 frameWidth   = fields[3].GetUInt16();
        uint8 sortBy        = fields[4].GetUInt8();
        uint8 healthText    = fields[5].GetUInt8();
        uint32 boolOptions  = fields[6].GetUInt32();
        uint8 topPoint      = fields[7].GetUInt8();
        uint8 bottomPoint   = fields[8].GetUInt8();
        uint8 leftPoint     = fields[9].GetUInt8();
        uint16 topOffset    = fields[10].GetUInt16();
        uint16 bottomOffset = fields[11].GetUInt16();
        uint16 leftOffset   = fields[12].GetUInt16();

        if (id > MAX_CUF_PROFILES)
        {
            TC_LOG_ERROR("entities.player", "Player::_LoadCUFProfiles: Player '%s' (%s) has an CUF profile with invalid id (ID: %u), max is %i.", GetName().c_str(), GetGUID().ToString().c_str(), id, MAX_CUF_PROFILES);
            continue;
        }

        _CUFProfiles[id] = Trinity::make_unique<CUFProfile>(name, frameHeight, frameWidth, sortBy, healthText, boolOptions, topPoint, bottomPoint, leftPoint, topOffset, bottomOffset, leftOffset);
    }
    while (result->NextRow());
}

bool Player::isAllowedToLoot(const Creature* creature)
{
    if (!creature->isDead() || !creature->IsDamageEnoughForLootingAndReward())
        return false;

    if (HasPendingBind())
        return false;

    const Loot* loot = &creature->loot;
    if (loot->isLooted()) // nothing to loot or everything looted.
        return false;

    if (loot->loot_type == LOOT_SKINNING)
        return creature->GetSkinner() == GetGUID();

    Group* thisGroup = GetGroup();
    if (!thisGroup)
        return this == creature->GetLootRecipient();
    else if (thisGroup != creature->GetLootRecipientGroup())
        return false;

    switch (thisGroup->GetLootMethod())
    {
        case PERSONAL_LOOT: /// @todo implement personal loot (http://wow.gamepedia.com/Loot#Personal_Loot)
            return false;
        case MASTER_LOOT:
        case FREE_FOR_ALL:
            return true;
        case ROUND_ROBIN:
            // may only loot if the player is the loot roundrobin player
            // or if there are free/quest/conditional item for the player
            if (loot->roundRobinPlayer.IsEmpty() || loot->roundRobinPlayer == GetGUID())
                return true;

            return loot->hasItemFor(this);
        case GROUP_LOOT:
        case NEED_BEFORE_GREED:
            // may only loot if the player is the loot roundrobin player
            // or item over threshold (so roll(s) can be launched)
            // or if there are free/quest/conditional item for the player
            if (loot->roundRobinPlayer.IsEmpty() || loot->roundRobinPlayer == GetGUID())
                return true;

            if (loot->hasOverThresholdItem())
                return true;

            return loot->hasItemFor(this);
    }

    return false;
}

void Player::_LoadActions(PreparedQueryResult result)
{
    m_actionButtons.clear();

    if (result)
    {
        do
        {
            Field* fields = result->Fetch();
            uint8 button = fields[0].GetUInt8();
            uint32 action = fields[1].GetUInt32();
            uint8 type = fields[2].GetUInt8();

            if (ActionButton* ab = AddActionButton(button, action, type))
                ab->uState = ACTIONBUTTON_UNCHANGED;
            else
            {
                TC_LOG_ERROR("entities.player", "Player::_LoadActions: Player '%s' (%s) has an invalid action button (Button: %u, Action: %u, Type: %u). It will be delted at next save.",
                    GetName().c_str(), GetGUID().ToString().c_str(), button, action, type);

                // Will deleted in DB at next save (it can create data until save but marked as deleted)
                m_actionButtons[button].uState = ACTIONBUTTON_DELETED;
            }
        } while (result->NextRow());
    }
}

void Player::_LoadAuras(PreparedQueryResult auraResult, PreparedQueryResult effectResult, uint32 timediff)
{
    TC_LOG_DEBUG("entities.player.loading", "Player::_LoadAuras: Loading auras for %s", GetGUID().ToString().c_str());

    /*
                    0         1      2           3            4       5           6
    SELECT casterGuid, itemGuid, spell, effectMask, effectIndex, amount, baseAmount FROM character_aura_effect WHERE guid = ?
    */

    ObjectGuid casterGuid, itemGuid;
    std::map<AuraKey, AuraLoadEffectInfo> effectInfo;
    if (effectResult)
    {
        do
        {
            Field* fields = effectResult->Fetch();
            uint32 effectIndex = fields[4].GetUInt8();
            if (effectIndex < MAX_SPELL_EFFECTS)
            {
                casterGuid.SetRawValue(fields[0].GetBinary());
                itemGuid.SetRawValue(fields[1].GetBinary());
                AuraKey key{ casterGuid, itemGuid, fields[2].GetUInt32(), fields[3].GetUInt32() };
                AuraLoadEffectInfo& info = effectInfo[key];
                info.Amounts[effectIndex] = fields[5].GetInt32();
                info.BaseAmounts[effectIndex] = fields[6].GetInt32();
            }
        }
        while (effectResult->NextRow());
    }

    /*
                    0         1      2           3                4           5            6           7              8              9
    SELECT casterGuid, itemGuid, spell, effectMask, recalculateMask, stackCount, maxDuration, remainTime, remainCharges, castItemLevel FROM character_aura WHERE guid = ?
    */
    if (auraResult)
    {
        do
        {
            Field* fields = auraResult->Fetch();
            casterGuid.SetRawValue(fields[0].GetBinary());
            itemGuid.SetRawValue(fields[1].GetBinary());
            AuraKey key{ casterGuid, itemGuid, fields[2].GetUInt32(), fields[3].GetUInt32() };
            uint32 recalculateMask = fields[4].GetUInt32();
            uint8 stackCount = fields[5].GetUInt8();
            int32 maxDuration = fields[6].GetInt32();
            int32 remainTime = fields[7].GetInt32();
            uint8 remainCharges = fields[8].GetUInt8();
            int32 castItemLevel = fields[9].GetInt32();

            SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(key.SpellId);
            if (!spellInfo)
            {
                TC_LOG_ERROR("entities.player", "Player::_LoadAuras: Player '%s' (%s) has an invalid aura (SpellID: %u), ignoring.",
                    GetName().c_str(), GetGUID().ToString().c_str(), key.SpellId);
                continue;
            }

            // negative effects should continue counting down after logout
            if (remainTime != -1 && !spellInfo->IsPositive())
            {
                if (remainTime/IN_MILLISECONDS <= int32(timediff))
                    continue;

                remainTime -= timediff*IN_MILLISECONDS;
            }

            // prevent wrong values of remainCharges
            if (spellInfo->ProcCharges)
            {
                // we have no control over the order of applying auras and modifiers allow auras
                // to have more charges than value in SpellInfo
                if (remainCharges <= 0/* || remainCharges > spellproto->procCharges*/)
                    remainCharges = spellInfo->ProcCharges;
            }
            else
                remainCharges = 0;

            AuraLoadEffectInfo& info = effectInfo[key];
            if (Aura* aura = Aura::TryCreate(spellInfo, key.EffectMask, this, nullptr, info.BaseAmounts.data(), nullptr, casterGuid, castItemLevel))
            {
                if (!aura->CanBeSaved())
                {
                    aura->Remove();
                    continue;
                }

                aura->SetLoadedState(maxDuration, remainTime, remainCharges, stackCount, recalculateMask, info.Amounts.data());
                aura->ApplyForTargets();
                TC_LOG_DEBUG("entities.player", "Player::_LoadAuras: Added aura (SpellID: %u, EffectMask: %u) to player '%s (%s)",
                    spellInfo->Id, key.EffectMask, GetName().c_str(), GetGUID().ToString().c_str());
            }
        }
        while (auraResult->NextRow());
    }
}

void Player::_LoadGlyphAuras()
{
    for (uint8 i = 0; i < MAX_GLYPH_SLOT_INDEX; ++i)
    {
        if (uint32 glyph = GetGlyph(GetActiveTalentGroup(), i))
        {
            if (GlyphPropertiesEntry const* gp = sGlyphPropertiesStore.LookupEntry(glyph))
            {
                if (GlyphSlotEntry const* gs = sGlyphSlotStore.LookupEntry(GetGlyphSlot(i)))
                {
                    if (gp->Type == gs->Type)
                    {
                        CastSpell(this, gp->SpellID, true);
                        continue;
                    }
                    else
                        TC_LOG_ERROR("entities.player", "Player::_LoadGlyphAuras: Player '%s' (%s) has glyph with typeflags %u in slot with typeflags %u, removing.", GetName().c_str(), GetGUID().ToString().c_str(), gp->Type, gs->Type);
                }
                else
                    TC_LOG_ERROR("entities.player", "Player::_LoadGlyphAuras: Player '%s' (%s) has not existing glyph slot entry %u on index %u", GetName().c_str(), GetGUID().ToString().c_str(), GetGlyphSlot(i), i);
            }
            else
                TC_LOG_ERROR("entities.player", "Player::_LoadGlyphAuras: Player '%s' (%s) has not existing glyph entry %u on index %u", GetName().c_str(), GetGUID().ToString().c_str(), glyph, i);

            // On any error remove glyph
            SetGlyph(i, 0);
        }
    }
}

void Player::LoadCorpse(PreparedQueryResult result)
{
    if (IsAlive() || HasAtLoginFlag(AT_LOGIN_RESURRECT))
        SpawnCorpseBones(false);

    if (!IsAlive())
    {
        if (result && !HasAtLoginFlag(AT_LOGIN_RESURRECT))
        {
            Field* fields = result->Fetch();
            _corpseLocation.WorldRelocate(fields[0].GetUInt16(), fields[1].GetFloat(), fields[2].GetFloat(), fields[3].GetFloat(), fields[4].GetFloat());
            ApplyModFlag(PLAYER_FIELD_LOCAL_FLAGS, PLAYER_LOCAL_FLAG_RELEASE_TIMER, !sMapStore.LookupEntry(_corpseLocation.GetMapId())->Instanceable());
        }
        else
            ResurrectPlayer(0.5f);
    }

    RemoveAtLoginFlag(AT_LOGIN_RESURRECT);
}

void Player::_LoadInventory(PreparedQueryResult result, uint32 timeDiff)
{
    //              0             1               2                   3         4            5           6         7                8                    9             10             11       12                     13            14
    // SELECT ii.guid, ii.itemEntry, ii.creatorGuid, ii.giftCreatorGuid, ii.count, ii.duration, ii.charges, ii.flags, ii.enchantments, ii.randomPropertyId, ii.durability, ii.playedTime, ii.text, ii.transmogrification, ii.upgradeId
    //                        15                  16                  17              18                  19               20   21    22
    //        ii.enchantIllusion, battlePetSpeciesId, battlePetBreedData, battlePetLevel, battlePetDisplayId, ii.bonusListIDs, bag, slot FROM character_inventory ci JOIN item_instance ii ON ci.item = ii.guid WHERE ci.guid = ? ORDER BY bag, slot
    //NOTE: the "order by `bag`" is important because it makes sure
    //the bagMap is filled before items in the bags are loaded
    //NOTE2: the "order by `slot`" is needed because mainhand weapons are (wrongly?)
    //expected to be equipped before offhand items (@todo fixme)

    if (result)
    {
        uint32 zoneId = GetZoneId();

        std::map<ObjectGuid, Bag*> bagMap;                               // fast guid lookup for bags
        std::map<ObjectGuid, Item*> invalidBagMap;                       // fast guid lookup for bags
        std::list<Item*> problematicItems;
        SQLTransaction trans = CharacterDatabase.BeginTransaction();

        // Prevent items from being added to the queue while loading
        m_itemUpdateQueueBlocked = true;
        do
        {
            Field* fields = result->Fetch();
            if (Item* item = _LoadItem(trans, zoneId, timeDiff, fields))
            {
                ObjectGuid bagGuid = fields[21].GetUInt64() ? ObjectGuid::Create<HighGuid::Item>(fields[21].GetUInt64()) : ObjectGuid::Empty;
                uint8 slot = fields[22].GetUInt8();

                GetSession()->GetCollectionMgr()->CheckHeirloomUpgrades(item);

                uint8 err = EQUIP_ERR_OK;
                // Item is not in bag
                if (!bagGuid)
                {
                    item->SetContainer(nullptr);
                    item->SetSlot(slot);

                    if (IsInventoryPos(INVENTORY_SLOT_BAG_0, slot))
                    {
                        ItemPosCountVec dest;
                        err = CanStoreItem(INVENTORY_SLOT_BAG_0, slot, dest, item, false);
                        if (err == EQUIP_ERR_OK)
                            item = StoreItem(dest, item, true);
                    }
                    else if (IsEquipmentPos(INVENTORY_SLOT_BAG_0, slot))
                    {
                        uint16 dest;
                        err = CanEquipItem(slot, dest, item, false, false);
                        if (err == EQUIP_ERR_OK)
                            QuickEquipItem(dest, item);
                    }
                    else if (IsBankPos(INVENTORY_SLOT_BAG_0, slot))
                    {
                        ItemPosCountVec dest;
                        err = CanBankItem(INVENTORY_SLOT_BAG_0, slot, dest, item, false, false);
                        if (err == EQUIP_ERR_OK)
                            item = BankItem(dest, item, true);
                    }

                    // Remember bags that may contain items in them
                    if (err == EQUIP_ERR_OK)
                    {
                        if (IsBagPos(item->GetPos()))
                            if (Bag* pBag = item->ToBag())
                                bagMap[item->GetGUID()] = pBag;
                    }
                    else
                        if (IsBagPos(item->GetPos()))
                            if (item->IsBag())
                                invalidBagMap[item->GetGUID()] = item;
                }
                else
                {
                    item->SetSlot(NULL_SLOT);
                    // Item is in the bag, find the bag
                    std::map<ObjectGuid, Bag*>::iterator itr = bagMap.find(bagGuid);
                    if (itr != bagMap.end())
                    {
                        ItemPosCountVec dest;
                        err = CanStoreItem(itr->second->GetSlot(), slot, dest, item);
                        if (err == EQUIP_ERR_OK)
                            item = StoreItem(dest, item, true);
                    }
                    else if (invalidBagMap.find(bagGuid) != invalidBagMap.end())
                    {
                        std::map<ObjectGuid, Item*>::iterator invalidBagItr = invalidBagMap.find(bagGuid);
                        if (std::find(problematicItems.begin(), problematicItems.end(), invalidBagItr->second) != problematicItems.end())
                            err = EQUIP_ERR_INTERNAL_BAG_ERROR;
                    }
                    else
                    {
                        TC_LOG_ERROR("entities.player", "Player::_LoadInventory: Player '%s' (%s) has item (%s, entry: %u) which doesnt have a valid bag (Bag %s, slot: %u). Possible cheat?",
                            GetName().c_str(), GetGUID().ToString().c_str(), item->GetGUID().ToString().c_str(), item->GetEntry(), bagGuid.ToString().c_str(), slot);
                        item->DeleteFromInventoryDB(trans);
                        delete item;
                        continue;
                    }

                }

                // Item's state may have changed after storing
                if (err == EQUIP_ERR_OK)
                    item->SetState(ITEM_UNCHANGED, this);
                else
                {
                    TC_LOG_ERROR("entities.player", "Player::_LoadInventory: Player '%s' (%s) has item (%s, entry: %u) which can't be loaded into inventory (Bag %s, slot: %u) by reason %u. Item will be sent by mail.",
                        GetName().c_str(), GetGUID().ToString().c_str(), item->GetGUID().ToString().c_str(), item->GetEntry(), bagGuid.ToString().c_str(), slot, err);
                    item->DeleteFromInventoryDB(trans);
                    problematicItems.push_back(item);
                }
            }
        } while (result->NextRow());

        m_itemUpdateQueueBlocked = false;

        // Send problematic items by mail
        while (!problematicItems.empty())
        {
            std::string subject = GetSession()->GetTrinityString(LANG_NOT_EQUIPPED_ITEM);

            MailDraft draft(subject, "There were problems with equipping item(s).");
            for (uint8 i = 0; !problematicItems.empty() && i < MAX_MAIL_ITEMS; ++i)
            {
                draft.AddItem(problematicItems.front());
                problematicItems.pop_front();
            }
            draft.SendMailTo(trans, this, MailSender(this, MAIL_STATIONERY_GM), MAIL_CHECK_MASK_COPIED);
        }
        CharacterDatabase.CommitTransaction(trans);
    }
    //if (IsAlive())
    _ApplyAllItemMods();
}

void Player::_LoadVoidStorage(PreparedQueryResult result)
{
    if (!result)
        return;

    do
    {
        // SELECT itemId, itemEntry, slot, creatorGuid, randomProperty, suffixFactor, upgradeId, bonusListIDs FROM character_void_storage WHERE playerGuid = ?
        Field* fields = result->Fetch();

        uint64 itemId = fields[0].GetUInt64();
        uint32 itemEntry = fields[1].GetUInt32();
        uint8 slot = fields[2].GetUInt8();
        ObjectGuid creatorGuid = fields[3].GetUInt64() ? ObjectGuid::Create<HighGuid::Player>(fields[3].GetUInt64()) : ObjectGuid::Empty;
        uint32 randomProperty = fields[4].GetUInt32();
        uint32 suffixFactor = fields[5].GetUInt32();
        uint32 upgradeId = fields[6].GetUInt32();
        std::vector<uint32> bonusListIDs;
        Tokenizer bonusListIdTokens(fields[7].GetString(), ' ');
        for (char const* token : bonusListIdTokens)
            bonusListIDs.push_back(atoul(token));

        if (!itemId)
        {
            TC_LOG_ERROR("entities.player", "Player::_LoadVoidStorage: Player '%s' (%s) has an item with an invalid id (item id: " UI64FMTD ", entry: %u).",
                GetName().c_str(), GetGUID().ToString().c_str(), itemId, itemEntry);
            continue;
        }

        if (!sObjectMgr->GetItemTemplate(itemEntry))
        {
            TC_LOG_ERROR("entities.player", "Player::_LoadVoidStorage: Player '%s' (%s) has an item with an invalid entry (item id: " UI64FMTD ", entry: %u).",
                GetName().c_str(), GetGUID().ToString().c_str(), itemId, itemEntry);
            continue;
        }

        if (slot >= VOID_STORAGE_MAX_SLOT)
        {
            TC_LOG_ERROR("entities.player", "Player::_LoadVoidStorage: Player '%s' (%s) has an item with an invalid slot (item id: " UI64FMTD ", entry: %u, slot: %u).",
                GetName().c_str(), GetGUID().ToString().c_str(), itemId, itemEntry, slot);
            continue;
        }

        std::string name;
        if (!creatorGuid.IsEmpty() && !ObjectMgr::GetPlayerNameByGUID(creatorGuid, name))
        {
            TC_LOG_ERROR("entities.player", "Player::_LoadVoidStorage: Player '%s' (%s) has an item with an invalid creator guid, set to 0 (item id: " UI64FMTD ", entry: %u, creator: %s).",
                GetName().c_str(), GetGUID().ToString().c_str(), itemId, itemEntry, creatorGuid.ToString().c_str());
            creatorGuid.Clear();
        }

        _voidStorageItems[slot] = new VoidStorageItem(itemId, itemEntry, creatorGuid, randomProperty, suffixFactor, upgradeId, bonusListIDs);
    }
    while (result->NextRow());
}

Item* Player::_LoadItem(SQLTransaction& trans, uint32 zoneId, uint32 timeDiff, Field* fields)
{
    Item* item = nullptr;
    ObjectGuid::LowType itemGuid = fields[0].GetUInt64();
    uint32 itemEntry = fields[1].GetUInt32();
    if (ItemTemplate const* proto = sObjectMgr->GetItemTemplate(itemEntry))
    {
        bool remove = false;
        item = NewItemOrBag(proto);
        if (item->LoadFromDB(itemGuid, GetGUID(), fields, itemEntry))
        {
            PreparedStatement* stmt;

            // Do not allow to have item limited to another map/zone in alive state
            if (IsAlive() && item->IsLimitedToAnotherMapOrZone(GetMapId(), zoneId))
            {
                TC_LOG_DEBUG("entities.player.loading", "Player::_LoadInventory: player (%s, name: '%s', map: %u) has item (%s, entry: %u) limited to another map (%u). Deleting item.",
                    GetGUID().ToString().c_str(), GetName().c_str(), GetMapId(), item->GetGUID().ToString().c_str(), item->GetEntry(), zoneId);
                remove = true;
            }
            // "Conjured items disappear if you are logged out for more than 15 minutes"
            else if (timeDiff > 15 * MINUTE && proto->GetFlags() & ITEM_FLAG_CONJURED)
            {
                TC_LOG_DEBUG("entities.player.loading", "Player::_LoadInventory: player (%s, name: '%s', diff: %u) has conjured item (%s, entry: %u) with expired lifetime (15 minutes). Deleting item.",
                    GetGUID().ToString().c_str(), GetName().c_str(), timeDiff, item->GetGUID().ToString().c_str(), item->GetEntry());
                remove = true;
            }
            else if (item->HasFlag(ITEM_FIELD_FLAGS, ITEM_FIELD_FLAG_REFUNDABLE))
            {
                if (item->GetPlayedTime() > (2 * HOUR))
                {
                    TC_LOG_DEBUG("entities.player.loading", "Player::_LoadInventory: player (%s, name: '%s') has item (%s, entry: %u) with expired refund time (%u). Deleting refund data and removing refundable flag.",
                        GetGUID().ToString().c_str(), GetName().c_str(), item->GetGUID().ToString().c_str(), item->GetEntry(), item->GetPlayedTime());

                    stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_ITEM_REFUND_INSTANCE);
                    stmt->setUInt64(0, item->GetGUID().GetCounter());
                    trans->Append(stmt);

                    item->RemoveFlag(ITEM_FIELD_FLAGS, ITEM_FIELD_FLAG_REFUNDABLE);
                }
                else
                {
                    stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_ITEM_REFUNDS);
                    stmt->setUInt64(0, item->GetGUID().GetCounter());
                    stmt->setUInt64(1, GetGUID().GetCounter());
                    if (PreparedQueryResult result = CharacterDatabase.Query(stmt))
                    {
                        item->SetRefundRecipient(GetGUID());
                        item->SetPaidMoney((*result)[0].GetUInt32());
                        item->SetPaidExtendedCost((*result)[1].GetUInt16());
                        AddRefundReference(item->GetGUID());
                    }
                    else
                    {
                        TC_LOG_DEBUG("entities.player.loading", "Player::_LoadInventory: player (%s, name: '%s') has item (%s, entry: %u) with refundable flags, but without data in item_refund_instance. Removing flag.",
                            GetGUID().ToString().c_str(), GetName().c_str(), item->GetGUID().ToString().c_str(), item->GetEntry());
                        item->RemoveFlag(ITEM_FIELD_FLAGS, ITEM_FIELD_FLAG_REFUNDABLE);
                    }
                }
            }
            else if (item->HasFlag(ITEM_FIELD_FLAGS, ITEM_FIELD_FLAG_BOP_TRADEABLE))
            {
                stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_ITEM_BOP_TRADE);
                stmt->setUInt64(0, item->GetGUID().GetCounter());
                if (PreparedQueryResult result = CharacterDatabase.Query(stmt))
                {
                    std::string strGUID = (*result)[0].GetString();
                    Tokenizer GUIDlist(strGUID, ' ');
                    GuidSet looters;
                    for (Tokenizer::const_iterator itr = GUIDlist.begin(); itr != GUIDlist.end(); ++itr)
                        looters.insert(ObjectGuid::Create<HighGuid::Player>(uint64(strtoull(*itr, nullptr, 10))));

                    if (looters.size() > 1 && item->GetTemplate()->GetMaxStackSize() == 1 && item->IsSoulBound())
                    {
                        item->SetSoulboundTradeable(looters);
                        AddTradeableItem(item);
                    }
                    else
                        item->ClearSoulboundTradeable(this);
                }
                else
                {
                    TC_LOG_DEBUG("entities.player.loading", "Player::_LoadInventory: player (%s, name: '%s') has item (%s, entry: %u) with ITEM_FIELD_FLAG_BOP_TRADEABLE flag, but without data in item_soulbound_trade_data. Removing flag.",
                        GetGUID().ToString().c_str(), GetName().c_str(), item->GetGUID().ToString().c_str(), item->GetEntry());
                    item->RemoveFlag(ITEM_FIELD_FLAGS, ITEM_FIELD_FLAG_BOP_TRADEABLE);
                }
            }
            else if (proto->GetHolidayID())
            {
                remove = true;
                GameEventMgr::GameEventDataMap const& events = sGameEventMgr->GetEventMap();
                GameEventMgr::ActiveEvents const& activeEventsList = sGameEventMgr->GetActiveEventList();
                for (GameEventMgr::ActiveEvents::const_iterator itr = activeEventsList.begin(); itr != activeEventsList.end(); ++itr)
                {
                    if (events[*itr].holiday_id == proto->GetHolidayID())
                    {
                        remove = false;
                        break;
                    }
                }
            }
        }
        else
        {
            TC_LOG_ERROR("entities.player", "Player::_LoadInventory: player (%s, name: '%s') has broken item (GUID: " UI64FMTD ", entry: %u) in inventory. Deleting item.",
                GetGUID().ToString().c_str(), GetName().c_str(), itemGuid, itemEntry);
            remove = true;
        }
        // Remove item from inventory if necessary
        if (remove)
        {
            Item::DeleteFromInventoryDB(trans, itemGuid);
            item->FSetState(ITEM_REMOVED);
            item->SaveToDB(trans);                           // it also deletes item object!
            item = nullptr;
        }
    }
    else
    {
        TC_LOG_ERROR("entities.player", "Player::_LoadInventory: player (%s, name: '%s') has unknown item (entry: %u) in inventory. Deleting item.",
            GetGUID().ToString().c_str(), GetName().c_str(), itemEntry);
        Item::DeleteFromInventoryDB(trans, itemGuid);
        Item::DeleteFromDB(trans, itemGuid);
    }
    return item;
}

// load mailed item which should receive current player
void Player::_LoadMailedItems(Mail* mail)
{
    // data needs to be at first place for Item::LoadFromDB
    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_MAILITEMS);
    stmt->setUInt32(0, mail->messageID);
    PreparedQueryResult result = CharacterDatabase.Query(stmt);
    if (!result)
        return;

    do
    {
        Field* fields = result->Fetch();

        ObjectGuid::LowType itemGuid = fields[0].GetUInt64();
        uint32 itemEntry = fields[1].GetUInt32();

        mail->AddItem(itemGuid, itemEntry);

        ItemTemplate const* proto = sObjectMgr->GetItemTemplate(itemEntry);
        if (!proto)
        {
            TC_LOG_ERROR("entities.player", "Player '%s' (%s) has unknown item_template in mailed items (GUID: " UI64FMTD ", Entry: %u) in mail (%u), deleted.",
                GetName().c_str(), GetGUID().ToString().c_str(), itemGuid, itemEntry, mail->messageID);

            stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_INVALID_MAIL_ITEM);
            stmt->setUInt64(0, itemGuid);
            CharacterDatabase.Execute(stmt);

            stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_ITEM_INSTANCE);
            stmt->setUInt64(0, itemGuid);
            CharacterDatabase.Execute(stmt);
            continue;
        }

        Item* item = NewItemOrBag(proto);

        ObjectGuid ownerGuid = fields[21].GetUInt64() ? ObjectGuid::Create<HighGuid::Player>(fields[21].GetUInt64()) : ObjectGuid::Empty;
        if (!item->LoadFromDB(itemGuid, ownerGuid, fields, itemEntry))
        {
            TC_LOG_ERROR("entities.player", "Player::_LoadMailedItems: Item (GUID: " UI64FMTD ") in mail (%u) doesn't exist, deleted from mail.", itemGuid, mail->messageID);

            stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_MAIL_ITEM);
            stmt->setUInt64(0, itemGuid);
            CharacterDatabase.Execute(stmt);

            item->FSetState(ITEM_REMOVED);

            SQLTransaction temp = SQLTransaction(nullptr);
            item->SaveToDB(temp);                               // it also deletes item object !
            continue;
        }

        AddMItem(item);
    }
    while (result->NextRow());
}

void Player::_LoadMailInit(PreparedQueryResult resultUnread, PreparedQueryResult resultDelivery)
{
    //set a count of unread mails
    //QueryResult* resultMails = CharacterDatabase.PQuery("SELECT COUNT(id) FROM mail WHERE receiver = '%u' AND (checked & 1)=0 AND deliver_time <= '" UI64FMTD "'", GUID_LOPART(playerGuid), (uint64)cTime);
    if (resultUnread)
        unReadMails = uint8((*resultUnread)[0].GetUInt64());

    // store nearest delivery time (it > 0 and if it < current then at next player update SendNewMaill will be called)
    //resultMails = CharacterDatabase.PQuery("SELECT MIN(deliver_time) FROM mail WHERE receiver = '%u' AND (checked & 1)=0", GUID_LOPART(playerGuid));
    if (resultDelivery)
        m_nextMailDelivereTime = time_t((*resultDelivery)[0].GetUInt32());
}

void Player::_LoadMail()
{
    m_mail.clear();

    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_MAIL);
    stmt->setUInt64(0, GetGUID().GetCounter());
    PreparedQueryResult result = CharacterDatabase.Query(stmt);

    if (result)
    {
        do
        {
            Field* fields = result->Fetch();
            Mail* m = new Mail;

            m->messageID      = fields[0].GetUInt32();
            m->messageType    = fields[1].GetUInt8();
            m->sender         = fields[2].GetUInt64();
            m->receiver       = fields[3].GetUInt64();
            m->subject        = fields[4].GetString();
            m->body           = fields[5].GetString();
            bool has_items    = fields[6].GetBool();
            m->expire_time    = time_t(fields[7].GetUInt32());
            m->deliver_time   = time_t(fields[8].GetUInt32());
            m->money          = fields[9].GetUInt64();
            m->COD            = fields[10].GetUInt64();
            m->checked        = fields[11].GetUInt8();
            m->stationery     = fields[12].GetUInt8();
            m->mailTemplateId = fields[13].GetInt16();

            if (m->mailTemplateId && !sMailTemplateStore.LookupEntry(m->mailTemplateId))
            {
                TC_LOG_ERROR("entities.player", "Player::_LoadMail: Mail (%u) has nonexistent MailTemplateId (%u), remove at load", m->messageID, m->mailTemplateId);
                m->mailTemplateId = 0;
            }

            m->state = MAIL_STATE_UNCHANGED;

            if (has_items)
                _LoadMailedItems(m);

            m_mail.push_back(m);
        }
        while (result->NextRow());
    }
    m_mailsLoaded = true;
}

void Player::LoadPet()
{
    //fixme: the pet should still be loaded if the player is not in world
    // just not added to the map
    if (IsInWorld())
    {
        Pet* pet = new Pet(this);
        if (!pet->LoadPetFromDB(this, 0, 0, true))
            delete pet;
    }
}

void Player::_LoadQuestStatus(PreparedQueryResult result)
{
    uint16 slot = 0;

    ////                                                       0      1       2
    //QueryResult* result = CharacterDatabase.PQuery("SELECT quest, status, timer WHERE guid = '%u'", GetGUIDLow());

    if (result)
    {
        do
        {
            Field* fields = result->Fetch();

            uint32 quest_id = fields[0].GetUInt32();
                                                            // used to be new, no delete?
            Quest const* quest = sObjectMgr->GetQuestTemplate(quest_id);
            if (quest)
            {
                // find or create
                QuestStatusData& questStatusData = m_QuestStatus[quest_id];

                uint8 qstatus = fields[1].GetUInt8();
                if (qstatus < MAX_QUEST_STATUS)
                    questStatusData.Status = QuestStatus(qstatus);
                else
                {
                    questStatusData.Status = QUEST_STATUS_INCOMPLETE;
                    TC_LOG_ERROR("entities.player", "Player::_LoadQuestStatus: Player '%s' (%s) has invalid quest %d status (%u), replaced by QUEST_STATUS_INCOMPLETE(3).",
                        GetName().c_str(), GetGUID().ToString().c_str(), quest_id, qstatus);
                }

                time_t quest_time = time_t(fields[2].GetUInt32());

                if (quest->HasSpecialFlag(QUEST_SPECIAL_FLAGS_TIMED) && !GetQuestRewardStatus(quest_id))
                {
                    AddTimedQuest(quest_id);

                    if (quest_time <= sWorld->GetGameTime())
                        questStatusData.Timer = 1;
                    else
                        questStatusData.Timer = uint32((quest_time - sWorld->GetGameTime()) * IN_MILLISECONDS);
                }
                else
                    quest_time = 0;

                // add to quest log
                if (slot < MAX_QUEST_LOG_SIZE && questStatusData.Status != QUEST_STATUS_NONE)
                {
                    SetQuestSlot(slot, quest_id, uint32(quest_time)); // cast can't be helped

                    if (questStatusData.Status == QUEST_STATUS_COMPLETE)
                        SetQuestSlotState(slot, QUEST_STATE_COMPLETE);
                    else if (questStatusData.Status == QUEST_STATUS_FAILED)
                        SetQuestSlotState(slot, QUEST_STATE_FAIL);

                    ++slot;
                }

                // Resize quest objective data to proper size
                int32 maxStorageIndex = 0;
                for (QuestObjective const& obj : quest->GetObjectives())
                    if (obj.StorageIndex > maxStorageIndex)
                        maxStorageIndex = obj.StorageIndex;

                questStatusData.ObjectiveData.resize(maxStorageIndex+1);

                TC_LOG_DEBUG("entities.player.loading", "Player::_LoadQuestStatus: Quest status is {%u} for quest {%u} for player (%s)", questStatusData.Status, quest_id, GetGUID().ToString().c_str());
            }
        }
        while (result->NextRow());
    }

    // clear quest log tail
    for (uint16 i = slot; i < MAX_QUEST_LOG_SIZE; ++i)
        SetQuestSlot(i, 0);
}

void Player::_LoadQuestStatusObjectives(PreparedQueryResult result)
{
    uint16 slot = 0;

    ////                                                       0        1       2
    //QueryResult* result = CharacterDatabase.PQuery("SELECT quest, objective, data WHERE guid = '%u'", GetGUIDLow());

    if (result)
    {
        do
        {
            Field* fields = result->Fetch();

            uint32 questID = fields[0].GetUInt32();

            auto itr = m_QuestStatus.find(questID);
            if (itr != m_QuestStatus.end())
            {
                QuestStatusData& questStatusData = itr->second;
                uint8 objectiveIndex = fields[1].GetUInt8();

                if (objectiveIndex < questStatusData.ObjectiveData.size())
                {
                    int32 data = fields[2].GetInt32();
                    questStatusData.ObjectiveData[objectiveIndex] = data;
                    SetQuestSlotCounter(slot, objectiveIndex, data);
                }
                else
                    TC_LOG_ERROR("entities.player", "Player::_LoadQuestStatusObjectives: Player '%s' (%s) has quest %d out of range objective index %u.", GetName().c_str(), GetGUID().ToString().c_str(), questID, objectiveIndex);
            }
            else
                TC_LOG_ERROR("entities.player", "Player::_LoadQuestStatusObjectives: Player %s (%s) does not have quest %d but has objective data for it.", GetName().c_str(), GetGUID().ToString().c_str(), questID);
        }
        while (result->NextRow());
    }
}

void Player::_LoadQuestStatusRewarded(PreparedQueryResult result)
{
    // SELECT quest FROM character_queststatus_rewarded WHERE guid = ?

    if (result)
    {
        do
        {
            Field* fields = result->Fetch();

            uint32 quest_id = fields[0].GetUInt32();
                                                            // used to be new, no delete?
            Quest const* quest = sObjectMgr->GetQuestTemplate(quest_id);
            if (quest)
            {
                // learn rewarded spell if unknown
                LearnQuestRewardedSpells(quest);

                // set rewarded title if any
                if (quest->GetRewTitle())
                    if (CharTitlesEntry const* titleEntry = sCharTitlesStore.LookupEntry(quest->GetRewTitle()))
                        SetTitle(titleEntry);

                // Skip loading special quests - they are also added to rewarded quests but only once and remain there forever
                // instead add them separately from load daily/weekly/monthly/seasonal
                if (!quest->IsDailyOrWeekly() && !quest->IsMonthly() && !quest->IsSeasonal())
                    if (uint32 questBit = sDB2Manager.GetQuestUniqueBitFlag(quest_id))
                        SetQuestCompletedBit(questBit, true);
            }

            m_RewardedQuests.insert(quest_id);
        }
        while (result->NextRow());
    }
}

void Player::_LoadDailyQuestStatus(PreparedQueryResult result)
{
    m_DFQuests.clear();

    //QueryResult* result = CharacterDatabase.PQuery("SELECT quest, time FROM character_queststatus_daily WHERE guid = '%u'", GetGUIDLow());

    if (result)
    {
        do
        {
            Field* fields = result->Fetch();
            uint32 quest_id = fields[0].GetUInt32();
            if (Quest const* qQuest = sObjectMgr->GetQuestTemplate(quest_id))
            {
                if (qQuest->IsDFQuest())
                {
                    m_DFQuests.insert(qQuest->GetQuestId());
                    m_lastDailyQuestTime = time_t(fields[1].GetUInt32());
                    continue;
                }
            }

            // save _any_ from daily quest times (it must be after last reset anyway)
            m_lastDailyQuestTime = time_t(fields[1].GetUInt32());

            Quest const* quest = sObjectMgr->GetQuestTemplate(quest_id);
            if (!quest)
                continue;

            AddDynamicValue(PLAYER_DYNAMIC_FIELD_DAILY_QUESTS, quest_id);
            if (uint32 questBit = sDB2Manager.GetQuestUniqueBitFlag(quest_id))
                SetQuestCompletedBit(questBit, true);

            TC_LOG_DEBUG("entities.player.loading", "Player::_LoadDailyQuestStatus: Loaded daily quest cooldown (QuestID: %u) for player '%s' (%s)",
                quest_id, GetName().c_str(), GetGUID().ToString().c_str());
        }
        while (result->NextRow());
    }

    m_DailyQuestChanged = false;
}

void Player::_LoadWeeklyQuestStatus(PreparedQueryResult result)
{
    m_weeklyquests.clear();

    if (result)
    {
        do
        {
            Field* fields = result->Fetch();
            uint32 quest_id = fields[0].GetUInt32();
            Quest const* quest = sObjectMgr->GetQuestTemplate(quest_id);
            if (!quest)
                continue;

            m_weeklyquests.insert(quest_id);
            if (uint32 questBit = sDB2Manager.GetQuestUniqueBitFlag(quest_id))
                SetQuestCompletedBit(questBit, true);

            TC_LOG_DEBUG("entities.player.loading", "Player::_LoadWeeklyQuestStatus: Loaded weekly quest cooldown (QuestID: %u) for player '%s' (%s)",
                quest_id, GetName().c_str(), GetGUID().ToString().c_str());
        }
        while (result->NextRow());
    }

    m_WeeklyQuestChanged = false;
}

void Player::_LoadSeasonalQuestStatus(PreparedQueryResult result)
{
    m_seasonalquests.clear();

    if (result)
    {
        do
        {
            Field* fields = result->Fetch();
            uint32 quest_id = fields[0].GetUInt32();
            uint32 event_id = fields[1].GetUInt32();
            Quest const* quest = sObjectMgr->GetQuestTemplate(quest_id);
            if (!quest)
                continue;

            m_seasonalquests[event_id].insert(quest_id);
            if (uint32 questBit = sDB2Manager.GetQuestUniqueBitFlag(quest_id))
                SetQuestCompletedBit(questBit, true);

            TC_LOG_DEBUG("entities.player.loading", "Player::_LoadSeasonalQuestStatus: Loaded seasonal quest cooldown (QuestID: %u) for player '%s' (%s)",
                quest_id, GetName().c_str(), GetGUID().ToString().c_str());
        }
        while (result->NextRow());
    }

    m_SeasonalQuestChanged = false;
}

void Player::_LoadMonthlyQuestStatus(PreparedQueryResult result)
{
    m_monthlyquests.clear();

    if (result)
    {
        do
        {
            Field* fields = result->Fetch();
            uint32 quest_id = fields[0].GetUInt32();
            Quest const* quest = sObjectMgr->GetQuestTemplate(quest_id);
            if (!quest)
                continue;

            m_monthlyquests.insert(quest_id);
            if (uint32 questBit = sDB2Manager.GetQuestUniqueBitFlag(quest_id))
                SetQuestCompletedBit(questBit, true);

            TC_LOG_DEBUG("entities.player.loading", "Player::_LoadMonthlyQuestStatus: Loaded monthly quest cooldown (QuestID: %u) for player '%s' (%s)",
                quest_id, GetName().c_str(), GetGUID().ToString().c_str());
        }
        while (result->NextRow());
    }

    m_MonthlyQuestChanged = false;
}

void Player::_LoadSpells(PreparedQueryResult result)
{
    //QueryResult* result = CharacterDatabase.PQuery("SELECT spell, active, disabled FROM character_spell WHERE guid = '%u'", GetGUIDLow());

    if (result)
    {
        do
            AddSpell((*result)[0].GetUInt32(), (*result)[1].GetBool(), false, false, (*result)[2].GetBool(), true);
        while (result->NextRow());
    }
}

void Player::_LoadGroup(PreparedQueryResult result)
{
    //QueryResult* result = CharacterDatabase.PQuery("SELECT guid FROM group_member WHERE memberGuid=%u", GetGUIDLow());
    if (result)
    {
        if (Group* group = sGroupMgr->GetGroupByDbStoreId((*result)[0].GetUInt32()))
        {
            if (group->IsLeader(GetGUID()))
                SetFlag(PLAYER_FLAGS, PLAYER_FLAGS_GROUP_LEADER);

            uint8 subgroup = group->GetMemberGroup(GetGUID());
            SetGroup(group, subgroup);
            if (getLevel() >= LEVELREQUIREMENT_HEROIC)
            {
                // the group leader may change the instance difficulty while the player is offline
                SetDungeonDifficultyID(group->GetDungeonDifficultyID());
                SetRaidDifficultyID(group->GetRaidDifficultyID());
                SetLegacyRaidDifficultyID(group->GetLegacyRaidDifficultyID());
            }
        }
    }

    if (!GetGroup() || !GetGroup()->IsLeader(GetGUID()))
        RemoveFlag(PLAYER_FLAGS, PLAYER_FLAGS_GROUP_LEADER);
}

void Player::_LoadBoundInstances(PreparedQueryResult result)
{
    for (uint8 i = 0; i < MAX_DIFFICULTY; ++i)
        m_boundInstances[i].clear();

    Group* group = GetGroup();

    //QueryResult* result = CharacterDatabase.PQuery("SELECT id, permanent, map, difficulty, resettime FROM character_instance LEFT JOIN instance ON instance = id WHERE guid = '%u'", GUID_LOPART(m_guid));
    if (result)
    {
        do
        {
            Field* fields = result->Fetch();

            bool perm = fields[1].GetBool();
            uint32 mapId = fields[2].GetUInt16();
            uint32 instanceId = fields[0].GetUInt32();
            uint8 difficulty = fields[3].GetUInt8();

            time_t resetTime = time_t(fields[4].GetUInt32());
            // the resettime for normal instances is only saved when the InstanceSave is unloaded
            // so the value read from the DB may be wrong here but only if the InstanceSave is loaded
            // and in that case it is not used

            bool deleteInstance = false;

            MapEntry const* mapEntry = sMapStore.LookupEntry(mapId);
            std::string mapname = mapEntry ? mapEntry->MapName_lang : "Unknown";

            if (!mapEntry || !mapEntry->IsDungeon())
            {
                TC_LOG_ERROR("entities.player", "Player::_LoadBoundInstances: Player '%s' (%s) has bind to not existed or not dungeon map %d (%s)",
                    GetName().c_str(), GetGUID().ToString().c_str(), mapId, mapname.c_str());
                deleteInstance = true;
            }
            else if (difficulty >= MAX_DIFFICULTY)
            {
                TC_LOG_ERROR("entities.player", "Player::_LoadBoundInstances: player '%s' (%s) has bind to not existed difficulty %d instance for map %u (%s)",
                    GetName().c_str(), GetGUID().ToString().c_str(), difficulty, mapId, mapname.c_str());
                deleteInstance = true;
            }
            else
            {
                MapDifficultyEntry const* mapDiff = GetMapDifficultyData(mapId, Difficulty(difficulty));
                if (!mapDiff)
                {
                    TC_LOG_ERROR("entities.player", "Player::_LoadBoundInstances: player '%s' (%s) has bind to not existed difficulty %d instance for map %u (%s)",
                        GetName().c_str(), GetGUID().ToString().c_str(), difficulty, mapId, mapname.c_str());
                    deleteInstance = true;
                }
                else if (!perm && group)
                {
                    TC_LOG_ERROR("entities.player", "Player::_LoadBoundInstances: player '%s' (%s) is in group %s but has a non-permanent character bind to map %d (%s), %d, %d",
                        GetName().c_str(), GetGUID().ToString().c_str(), group->GetGUID().ToString().c_str(), mapId, mapname.c_str(), instanceId, difficulty);
                    deleteInstance = true;
                }
            }

            if (deleteInstance)
            {
                PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHAR_INSTANCE_BY_INSTANCE_GUID);

                stmt->setUInt64(0, GetGUID().GetCounter());
                stmt->setUInt32(1, instanceId);

                CharacterDatabase.Execute(stmt);

                continue;
            }

            // since non permanent binds are always solo bind, they can always be reset
            if (InstanceSave* save = sInstanceSaveMgr->AddInstanceSave(mapId, instanceId, Difficulty(difficulty), resetTime, !perm, true))
               BindToInstance(save, perm, true);
        }
        while (result->NextRow());
    }
}

InstancePlayerBind* Player::GetBoundInstance(uint32 mapid, Difficulty difficulty)
{
    // some instances only have one difficulty
    MapDifficultyEntry const* mapDiff = GetDownscaledMapDifficultyData(mapid, difficulty);
    if (!mapDiff)
        return nullptr;

    BoundInstancesMap::iterator itr = m_boundInstances[difficulty].find(mapid);
    if (itr != m_boundInstances[difficulty].end())
        return &itr->second;

    return nullptr;
}

InstancePlayerBind const* Player::GetBoundInstance(uint32 mapid, Difficulty difficulty) const
{
    // some instances only have one difficulty
    MapDifficultyEntry const* mapDiff = GetDownscaledMapDifficultyData(mapid, difficulty);
    if (!mapDiff)
        return nullptr;

    auto itr = m_boundInstances[difficulty].find(mapid);
    if (itr != m_boundInstances[difficulty].end())
        return &itr->second;

    return nullptr;
}

InstanceSave* Player::GetInstanceSave(uint32 mapid)
{
    MapEntry const* mapEntry = sMapStore.LookupEntry(mapid);
    InstancePlayerBind* pBind = GetBoundInstance(mapid, GetDifficultyID(mapEntry));
    InstanceSave* pSave = pBind ? pBind->save : NULL;
    if (!pBind || !pBind->perm)
        if (Group* group = GetGroup())
            if (InstanceGroupBind* groupBind = group->GetBoundInstance(this))
                pSave = groupBind->save;

    return pSave;
}

void Player::UnbindInstance(uint32 mapid, Difficulty difficulty, bool unload)
{
    BoundInstancesMap::iterator itr = m_boundInstances[difficulty].find(mapid);
    UnbindInstance(itr, difficulty, unload);
}

void Player::UnbindInstance(BoundInstancesMap::iterator &itr, Difficulty difficulty, bool unload)
{
    if (itr != m_boundInstances[difficulty].end())
    {
        if (!unload)
        {
            PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHAR_INSTANCE_BY_INSTANCE_GUID);

            stmt->setUInt64(0, GetGUID().GetCounter());
            stmt->setUInt32(1, itr->second.save->GetInstanceId());

            CharacterDatabase.Execute(stmt);
        }

        if (itr->second.perm)
            GetSession()->SendCalendarRaidLockout(itr->second.save, false);

        itr->second.save->RemovePlayer(this);               // save can become invalid
        m_boundInstances[difficulty].erase(itr++);
    }
}

InstancePlayerBind* Player::BindToInstance(InstanceSave* save, bool permanent, bool load)
{
    if (save)
    {
        InstancePlayerBind& bind = m_boundInstances[save->GetDifficultyID()][save->GetMapId()];
        if (!load)
        {
            if (bind.save)
            {
                // update the save when the group kills a boss
                if (permanent != bind.perm || save != bind.save)
                {
                    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_CHAR_INSTANCE);

                    stmt->setUInt32(0, save->GetInstanceId());
                    stmt->setBool(1, permanent);
                    stmt->setUInt64(2, GetGUID().GetCounter());
                    stmt->setUInt32(3, bind.save->GetInstanceId());

                    CharacterDatabase.Execute(stmt);
                }
            }
            else
            {
                PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_CHAR_INSTANCE);

                stmt->setUInt64(0, GetGUID().GetCounter());
                stmt->setUInt32(1, save->GetInstanceId());
                stmt->setBool(2, permanent);

                CharacterDatabase.Execute(stmt);
            }
        }

        if (bind.save != save)
        {
            if (bind.save)
                bind.save->RemovePlayer(this);
            save->AddPlayer(this);
        }

        if (permanent)
            save->SetCanReset(false);

        bind.save = save;
        bind.perm = permanent;
        if (!load)
            TC_LOG_DEBUG("maps", "Player::BindToInstance: Player '%s' (%s) is now bound to map (ID: %d, Instance: %d, Difficulty: %d)",
                GetName().c_str(), GetGUID().ToString().c_str(), save->GetMapId(), save->GetInstanceId(), save->GetDifficultyID());
        sScriptMgr->OnPlayerBindToInstance(this, save->GetDifficultyID(), save->GetMapId(), permanent);
        return &bind;
    }

    return nullptr;
}

void Player::BindToInstance()
{
    InstanceSave* mapSave = sInstanceSaveMgr->GetInstanceSave(_pendingBindId);
    if (!mapSave) //it seems sometimes mapSave is NULL, but I did not check why
        return;

    WorldPackets::Instance::InstanceSaveCreated data;
    data.Gm = IsGameMaster();
    GetSession()->SendPacket(data.Write());
    if (!IsGameMaster())
    {
        BindToInstance(mapSave, true);
        GetSession()->SendCalendarRaidLockout(mapSave, true);
    }
}

void Player::SetPendingBind(uint32 instanceId, uint32 bindTimer)
{
    _pendingBindId = instanceId;
    _pendingBindTimer = bindTimer;
}

void Player::SendRaidInfo()
{
    WorldPackets::Instance::InstanceInfo instanceInfo;

    time_t now = time(nullptr);

    for (uint8 i = 0; i < MAX_DIFFICULTY; ++i)
    {
        for (BoundInstancesMap::iterator itr = m_boundInstances[i].begin(); itr != m_boundInstances[i].end(); ++itr)
        {
            if (itr->second.perm)
            {
                InstanceSave* save = itr->second.save;

                WorldPackets::Instance::InstanceLockInfos lockInfos;

                lockInfos.InstanceID = save->GetInstanceId();
                lockInfos.MapID = save->GetMapId();
                lockInfos.DifficultyID = save->GetDifficultyID();
                lockInfos.TimeRemaining = save->GetResetTime() - now;

                lockInfos.CompletedMask = 0;
                if (Map* map = sMapMgr->FindMap(save->GetMapId(), save->GetInstanceId()))
                    if (InstanceScript* instanceScript = ((InstanceMap*)map)->GetInstanceScript())
                        lockInfos.CompletedMask = instanceScript->GetCompletedEncounterMask();

                lockInfos.Locked = lockInfos.TimeRemaining <= 0;
                lockInfos.Extended = false;

                instanceInfo.LockList.push_back(lockInfos);
            }
        }
    }

    GetSession()->SendPacket(instanceInfo.Write());
}

bool Player::Satisfy(AccessRequirement const* ar, uint32 target_map, bool report)
{
    if (!IsGameMaster() && ar)
    {
        uint8 LevelMin = 0;
        uint8 LevelMax = 0;

        MapEntry const* mapEntry = sMapStore.LookupEntry(target_map);
        if (!mapEntry)
            return false;

        if (!sWorld->getBoolConfig(CONFIG_INSTANCE_IGNORE_LEVEL))
        {
            if (ar->levelMin && getLevel() < ar->levelMin)
                LevelMin = ar->levelMin;
            if (ar->levelMax && getLevel() > ar->levelMax)
                LevelMax = ar->levelMax;
        }

        uint32 missingItem = 0;
        if (ar->item)
        {
            if (!HasItemCount(ar->item) &&
                (!ar->item2 || !HasItemCount(ar->item2)))
                missingItem = ar->item;
        }
        else if (ar->item2 && !HasItemCount(ar->item2))
            missingItem = ar->item2;

        if (DisableMgr::IsDisabledFor(DISABLE_TYPE_MAP, target_map, this))
        {
            GetSession()->SendNotification("%s", GetSession()->GetTrinityString(LANG_INSTANCE_CLOSED));
            return false;
        }

        uint32 missingQuest = 0;
        if (GetTeam() == ALLIANCE && ar->quest_A && !GetQuestRewardStatus(ar->quest_A))
            missingQuest = ar->quest_A;
        else if (GetTeam() == HORDE && ar->quest_H && !GetQuestRewardStatus(ar->quest_H))
            missingQuest = ar->quest_H;

        uint32 missingAchievement = 0;
        Player* leader = this;
        ObjectGuid leaderGuid = GetGroup() ? GetGroup()->GetLeaderGUID() : GetGUID();
        if (leaderGuid != GetGUID())
            leader = ObjectAccessor::FindPlayer(leaderGuid);

        if (ar->achievement)
            if (!leader || !leader->HasAchieved(ar->achievement))
                missingAchievement = ar->achievement;

        Difficulty target_difficulty = GetDifficultyID(mapEntry);
        MapDifficultyEntry const* mapDiff = GetDownscaledMapDifficultyData(target_map, target_difficulty);
        if (LevelMin || LevelMax || missingItem || missingQuest || missingAchievement)
        {
            if (report)
            {
                if (missingQuest && !ar->questFailedText.empty())
                    ChatHandler(GetSession()).PSendSysMessage("%s", ar->questFailedText.c_str());
                else if (mapDiff->HasMessage()) // if (missingAchievement) covered by this case
                    SendTransferAborted(target_map, TRANSFER_ABORT_DIFFICULTY, target_difficulty);
                else if (missingItem)
                    GetSession()->SendNotification(GetSession()->GetTrinityString(LANG_LEVEL_MINREQUIRED_AND_ITEM), LevelMin, ASSERT_NOTNULL(sObjectMgr->GetItemTemplate(missingItem))->GetName(GetSession()->GetSessionDbcLocale()));
                else if (LevelMin)
                    GetSession()->SendNotification(GetSession()->GetTrinityString(LANG_LEVEL_MINREQUIRED), LevelMin);
            }
            return false;
        }
    }
    return true;
}

bool Player::IsInstanceLoginGameMasterException() const
{
    if (CanBeGameMaster())
    {
        ChatHandler(GetSession()).SendSysMessage(LANG_INSTANCE_LOGIN_GAMEMASTER_EXCEPTION);
        return true;
    }
    else
        return false;
}

bool Player::CheckInstanceValidity(bool /*isLogin*/)
{
    // game masters' instances are always valid
    if (IsGameMaster())
        return true;

    // non-instances are always valid
    Map* map = GetMap();
    if (!map || !map->IsDungeon())
        return true;

    // raid instances require the player to be in a raid group to be valid
    if (map->IsRaid() && !sWorld->getBoolConfig(CONFIG_INSTANCE_IGNORE_RAID))
        if (!GetGroup() || !GetGroup()->isRaidGroup())
            return false;

    if (Group* group = GetGroup())
    {
        // check if player's group is bound to this instance
        InstanceGroupBind* bind = group->GetBoundInstance(map->GetDifficultyID(), map->GetId());
        if (!bind || !bind->save || bind->save->GetInstanceId() != map->GetInstanceId())
            return false;

        Map::PlayerList const& players = map->GetPlayers();
        if (!players.isEmpty())
            for (Map::PlayerList::const_iterator it = players.begin(); it != players.end(); ++it)
            {
                if (Player* otherPlayer = it->GetSource())
                {
                    if (otherPlayer->IsGameMaster())
                        continue;
                    if (!otherPlayer->m_InstanceValid) // ignore players that currently have a homebind timer active
                        continue;
                    if (group != otherPlayer->GetGroup())
                        return false;
                }
            }
    }
    else
    {
        // instance is invalid if we are not grouped and there are other players
        if (map->GetPlayersCountExceptGMs() > 1)
            return false;

        // check if the player is bound to this instance
        InstancePlayerBind* bind = GetBoundInstance(map->GetId(), map->GetDifficultyID());
        if (!bind || !bind->save || bind->save->GetInstanceId() != map->GetInstanceId())
            return false;
    }

    return true;
}

bool Player::CheckInstanceCount(uint32 instanceId) const
{
    if (_instanceResetTimes.size() < sWorld->getIntConfig(CONFIG_MAX_INSTANCES_PER_HOUR))
        return true;
    return _instanceResetTimes.find(instanceId) != _instanceResetTimes.end();
}

void Player::AddInstanceEnterTime(uint32 instanceId, time_t enterTime)
{
    if (_instanceResetTimes.find(instanceId) == _instanceResetTimes.end())
        _instanceResetTimes.insert(InstanceTimeMap::value_type(instanceId, enterTime + HOUR));
}

bool Player::_LoadHomeBind(PreparedQueryResult result)
{
    PlayerInfo const* info = sObjectMgr->GetPlayerInfo(getRace(), getClass());
    if (!info)
    {
        TC_LOG_ERROR("entities.player", "Player::_LoadHomeBind: Player '%s' (%s) has incorrect race/class (%u/%u) pair. Can't load.",
            GetGUID().ToString().c_str(), GetName().c_str(), uint32(getRace()), uint32(getClass()));
        return false;
    }

    bool ok = false;
    // SELECT mapId, zoneId, posX, posY, posZ FROM character_homebind WHERE guid = ?
    if (result)
    {
        Field* fields = result->Fetch();

        m_homebindMapId = fields[0].GetUInt16();
        m_homebindAreaId = fields[1].GetUInt16();
        m_homebindX = fields[2].GetFloat();
        m_homebindY = fields[3].GetFloat();
        m_homebindZ = fields[4].GetFloat();

        MapEntry const* bindMapEntry = sMapStore.LookupEntry(m_homebindMapId);

        // accept saved data only for valid position (and non instanceable), and accessable
        if (MapManager::IsValidMapCoord(m_homebindMapId, m_homebindX, m_homebindY, m_homebindZ) &&
            !bindMapEntry->Instanceable() && GetSession()->GetExpansion() >= bindMapEntry->Expansion())
            ok = true;
        else
        {
            PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_PLAYER_HOMEBIND);
            stmt->setUInt64(0, GetGUID().GetCounter());
            CharacterDatabase.Execute(stmt);
        }
    }

    if (!ok)
    {
        m_homebindMapId = info->mapId;
        m_homebindAreaId = info->areaId;
        m_homebindX = info->positionX;
        m_homebindY = info->positionY;
        m_homebindZ = info->positionZ;

        PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_PLAYER_HOMEBIND);
        stmt->setUInt64(0, GetGUID().GetCounter());
        stmt->setUInt16(1, m_homebindMapId);
        stmt->setUInt16(2, m_homebindAreaId);
        stmt->setFloat (3, m_homebindX);
        stmt->setFloat (4, m_homebindY);
        stmt->setFloat (5, m_homebindZ);
        CharacterDatabase.Execute(stmt);
    }

    TC_LOG_DEBUG("entities.player", "Player::_LoadHomeBind: Setting home position (MapID: %u, AreaID: %u, X: %f, Y: %f, Z: %f) of player '%s' (%s)",
        m_homebindMapId, m_homebindAreaId, m_homebindX, m_homebindY, m_homebindZ, GetName().c_str(), GetGUID().ToString().c_str());

    return true;
}

/*********************************************************/
/***                   SAVE SYSTEM                     ***/
/*********************************************************/

void Player::SaveToDB(bool create /*=false*/)
{
    // delay auto save at any saves (manual, in code, or autosave)
    m_nextSave = sWorld->getIntConfig(CONFIG_INTERVAL_SAVE);

    //lets allow only players in world to be saved
    if (IsBeingTeleportedFar())
    {
        ScheduleDelayedOperation(DELAYED_SAVE_PLAYER);
        return;
    }

    // first save/honor gain after midnight will also update the player's honor fields
    UpdateHonorFields();

    TC_LOG_DEBUG("entities.unit", "Player::SaveToDB: The value of player %s at save: ", m_name.c_str());
    outDebugValues();

    if (!create)
        sScriptMgr->OnPlayerSave(this);

    PreparedStatement* stmt;
    uint8 index = 0;

    if (create)
    {
        //! Insert query
        /// @todo: Filter out more redundant fields that can take their default value at player create
        stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_CHARACTER);
        stmt->setUInt64(index++, GetGUID().GetCounter());
        stmt->setUInt32(index++, GetSession()->GetAccountId());
        stmt->setString(index++, GetName());
        stmt->setUInt8(index++, getRace());
        stmt->setUInt8(index++, getClass());
        stmt->setUInt8(index++, GetByteValue(PLAYER_BYTES_3, PLAYER_BYTES_3_OFFSET_GENDER));   // save gender from PLAYER_BYTES_3, UNIT_BYTES_0 changes with every transform effect
        stmt->setUInt8(index++, getLevel());
        stmt->setUInt32(index++, GetUInt32Value(PLAYER_XP));
        stmt->setUInt64(index++, GetMoney());
        stmt->setUInt8(index++, GetByteValue(PLAYER_BYTES, PLAYER_BYTES_OFFSET_SKIN_ID));
        stmt->setUInt8(index++, GetByteValue(PLAYER_BYTES, PLAYER_BYTES_OFFSET_FACE_ID));
        stmt->setUInt8(index++, GetByteValue(PLAYER_BYTES, PLAYER_BYTES_OFFSET_HAIR_STYLE_ID));
        stmt->setUInt8(index++, GetByteValue(PLAYER_BYTES, PLAYER_BYTES_OFFSET_HAIR_COLOR_ID));
        stmt->setUInt8(index++, GetByteValue(PLAYER_BYTES_2, PLAYER_BYTES_2_OFFSET_FACIAL_STYLE));
        stmt->setUInt8(index++, GetByteValue(PLAYER_BYTES_2, PLAYER_BYTES_2_OFFSET_BANK_BAG_SLOTS));
        stmt->setUInt8(index++, GetByteValue(PLAYER_BYTES_2, PLAYER_BYTES_2_OFFSET_REST_STATE));
        stmt->setUInt32(index++, GetUInt32Value(PLAYER_FLAGS));
        stmt->setUInt16(index++, (uint16)GetMapId());
        stmt->setUInt32(index++, (uint32)GetInstanceId());
        stmt->setUInt8(index++, uint8(GetDungeonDifficultyID()));
        stmt->setUInt8(index++, uint8(GetRaidDifficultyID()));
        stmt->setUInt8(index++, uint8(GetLegacyRaidDifficultyID()));
        stmt->setFloat(index++, finiteAlways(GetPositionX()));
        stmt->setFloat(index++, finiteAlways(GetPositionY()));
        stmt->setFloat(index++, finiteAlways(GetPositionZ()));
        stmt->setFloat(index++, finiteAlways(GetOrientation()));
        stmt->setFloat(index++, finiteAlways(GetTransOffsetX()));
        stmt->setFloat(index++, finiteAlways(GetTransOffsetY()));
        stmt->setFloat(index++, finiteAlways(GetTransOffsetZ()));
        stmt->setFloat(index++, finiteAlways(GetTransOffsetO()));
        ObjectGuid::LowType transLowGUID = UI64LIT(0);
        if (GetTransport())
            transLowGUID = GetTransport()->GetGUID().GetCounter();
        stmt->setUInt64(index++, transLowGUID);

        std::ostringstream ss;
        ss << m_taxi;
        stmt->setString(index++, ss.str());
        stmt->setUInt8(index++, m_cinematic);
        stmt->setUInt32(index++, m_Played_time[PLAYED_TIME_TOTAL]);
        stmt->setUInt32(index++, m_Played_time[PLAYED_TIME_LEVEL]);
        stmt->setFloat(index++, finiteAlways(m_rest_bonus));
        stmt->setUInt32(index++, uint32(time(nullptr)));
        stmt->setUInt8(index++,  (HasFlag(PLAYER_FLAGS, PLAYER_FLAGS_RESTING) ? 1 : 0));
        //save, far from tavern/city
        //save, but in tavern/city
        stmt->setUInt32(index++, GetTalentResetCost());
        stmt->setUInt32(index++, GetTalentResetTime());

        ss.str("");
        for (uint8 i = 0; i < MAX_TALENT_GROUPS; ++i)
            ss << GetSpecId(i) << " ";
        stmt->setString(index++, ss.str());
        stmt->setUInt16(index++, (uint16)m_ExtraFlags);
        stmt->setUInt8(index++,  m_stableSlots);
        stmt->setUInt16(index++, (uint16)m_atLoginFlags);
        stmt->setUInt16(index++, GetZoneId());
        stmt->setUInt32(index++, uint32(m_deathExpireTime));

        ss.str("");
        ss << m_taxi.SaveTaxiDestinationsToString();

        stmt->setString(index++, ss.str());
        stmt->setUInt32(index++, GetUInt32Value(PLAYER_FIELD_LIFETIME_HONORABLE_KILLS));
        stmt->setUInt16(index++, GetUInt16Value(PLAYER_FIELD_KILLS, PLAYER_FIELD_KILLS_OFFSET_TODAY_KILLS));
        stmt->setUInt16(index++, GetUInt16Value(PLAYER_FIELD_KILLS, PLAYER_FIELD_KILLS_OFFSET_YESTERDAY_KILLS));
        stmt->setUInt32(index++, GetUInt32Value(PLAYER_CHOSEN_TITLE));
        stmt->setUInt32(index++, GetUInt32Value(PLAYER_FIELD_WATCHED_FACTION_INDEX));
        stmt->setUInt8(index++, GetDrunkValue());
        stmt->setUInt32(index++, GetHealth());

        uint32 storedPowers = 0;
        for (uint32 i = 0; i < MAX_POWERS; ++i)
        {
            if (GetPowerIndex(i) != MAX_POWERS)
            {
                stmt->setUInt32(index++, GetUInt32Value(UNIT_FIELD_POWER + storedPowers));
                if (++storedPowers >= MAX_POWERS_PER_CLASS)
                    break;
            }
        }

        for (; storedPowers < MAX_POWERS_PER_CLASS; ++storedPowers)
            stmt->setUInt32(index++, 0);

        stmt->setUInt32(index++, GetSession()->GetLatency());

        stmt->setUInt8(index++, GetTalentGroupsCount());
        stmt->setUInt8(index++, GetActiveTalentGroup());

        stmt->setUInt32(index++, GetLootSpecId());

        ss.str("");
        for (uint32 i = 0; i < PLAYER_EXPLORED_ZONES_SIZE; ++i)
            ss << GetUInt32Value(PLAYER_EXPLORED_ZONES_1 + i) << ' ';
        stmt->setString(index++, ss.str());

        ss.str("");
        // cache equipment...
        for (uint32 i = 0; i < INVENTORY_SLOT_BAG_END; ++i)
        {
            if (Item* item = GetItemByPos(INVENTORY_SLOT_BAG_0, i))
            {
                ss << item->GetTemplate()->GetInventoryType() << ' ' << item->GetDisplayId() << ' ';
                if (SpellItemEnchantmentEntry const* enchant = sSpellItemEnchantmentStore.LookupEntry(item->GetEnchantmentId(PERM_ENCHANTMENT_SLOT)))
                    ss << enchant->ItemVisual;
                else
                    ss << '0';

                ss << ' ';
            }
            else
                ss << "0 0 0 ";
        }

        stmt->setString(index++, ss.str());

        ss.str("");
        for (uint32 i = 0; i < KNOWN_TITLES_SIZE * 2; ++i)
            ss << GetUInt32Value(PLAYER__FIELD_KNOWN_TITLES + i) << ' ';
        stmt->setString(index++, ss.str());

        stmt->setUInt8(index++, GetByteValue(PLAYER_FIELD_BYTES, PLAYER_FIELD_BYTES_OFFSET_ACTION_BAR_TOGGLES));
        stmt->setUInt32(index, m_grantableLevels);
    }
    else
    {
        // Update query
        stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_CHARACTER);
        stmt->setString(index++, GetName());
        stmt->setUInt8(index++, getRace());
        stmt->setUInt8(index++, getClass());
        stmt->setUInt8(index++, GetByteValue(PLAYER_BYTES_3, PLAYER_BYTES_3_OFFSET_GENDER));   // save gender from PLAYER_BYTES_3, UNIT_BYTES_0 changes with every transform effect
        stmt->setUInt8(index++, getLevel());
        stmt->setUInt32(index++, GetUInt32Value(PLAYER_XP));
        stmt->setUInt64(index++, GetMoney());
        stmt->setUInt8(index++, GetByteValue(PLAYER_BYTES, PLAYER_BYTES_OFFSET_SKIN_ID));
        stmt->setUInt8(index++, GetByteValue(PLAYER_BYTES, PLAYER_BYTES_OFFSET_FACE_ID));
        stmt->setUInt8(index++, GetByteValue(PLAYER_BYTES, PLAYER_BYTES_OFFSET_HAIR_STYLE_ID));
        stmt->setUInt8(index++, GetByteValue(PLAYER_BYTES, PLAYER_BYTES_OFFSET_HAIR_COLOR_ID));
        stmt->setUInt8(index++, GetByteValue(PLAYER_BYTES_2, PLAYER_BYTES_2_OFFSET_FACIAL_STYLE));
        stmt->setUInt8(index++, GetByteValue(PLAYER_BYTES_2, PLAYER_BYTES_2_OFFSET_BANK_BAG_SLOTS));
        stmt->setUInt8(index++, GetByteValue(PLAYER_BYTES_2, PLAYER_BYTES_2_OFFSET_REST_STATE));
        stmt->setUInt32(index++, GetUInt32Value(PLAYER_FLAGS));

        if (!IsBeingTeleported())
        {
            stmt->setUInt16(index++, (uint16)GetMapId());
            stmt->setUInt32(index++, (uint32)GetInstanceId());
            stmt->setUInt8(index++, uint8(GetDungeonDifficultyID()));
            stmt->setUInt8(index++, uint8(GetRaidDifficultyID()));
            stmt->setUInt8(index++, uint8(GetLegacyRaidDifficultyID()));
            stmt->setFloat(index++, finiteAlways(GetPositionX()));
            stmt->setFloat(index++, finiteAlways(GetPositionY()));
            stmt->setFloat(index++, finiteAlways(GetPositionZ()));
            stmt->setFloat(index++, finiteAlways(GetOrientation()));
        }
        else
        {
            stmt->setUInt16(index++, (uint16)GetTeleportDest().GetMapId());
            stmt->setUInt32(index++, (uint32)0);
            stmt->setUInt8(index++, uint8(GetDungeonDifficultyID()));
            stmt->setUInt8(index++, uint8(GetRaidDifficultyID()));
            stmt->setUInt8(index++, uint8(GetLegacyRaidDifficultyID()));
            stmt->setFloat(index++, finiteAlways(GetTeleportDest().GetPositionX()));
            stmt->setFloat(index++, finiteAlways(GetTeleportDest().GetPositionY()));
            stmt->setFloat(index++, finiteAlways(GetTeleportDest().GetPositionZ()));
            stmt->setFloat(index++, finiteAlways(GetTeleportDest().GetOrientation()));
        }

        stmt->setFloat(index++, finiteAlways(GetTransOffsetX()));
        stmt->setFloat(index++, finiteAlways(GetTransOffsetY()));
        stmt->setFloat(index++, finiteAlways(GetTransOffsetZ()));
        stmt->setFloat(index++, finiteAlways(GetTransOffsetO()));
        ObjectGuid::LowType transLowGUID = UI64LIT(0);
        if (GetTransport())
            transLowGUID = GetTransport()->GetGUID().GetCounter();
        stmt->setUInt64(index++, transLowGUID);

        std::ostringstream ss;
        ss << m_taxi;
        stmt->setString(index++, ss.str());
        stmt->setUInt8(index++, m_cinematic);
        stmt->setUInt32(index++, m_Played_time[PLAYED_TIME_TOTAL]);
        stmt->setUInt32(index++, m_Played_time[PLAYED_TIME_LEVEL]);
        stmt->setFloat(index++, finiteAlways(m_rest_bonus));
        stmt->setUInt32(index++, uint32(time(nullptr)));
        stmt->setUInt8(index++,  (HasFlag(PLAYER_FLAGS, PLAYER_FLAGS_RESTING) ? 1 : 0));
        //save, far from tavern/city
        //save, but in tavern/city
        stmt->setUInt32(index++, GetTalentResetCost());
        stmt->setUInt32(index++, GetTalentResetTime());

        ss.str("");
        for (uint8 i = 0; i < MAX_TALENT_GROUPS; ++i)
            ss << GetSpecId(i) << " ";
        stmt->setString(index++, ss.str());
        stmt->setUInt16(index++, (uint16)m_ExtraFlags);
        stmt->setUInt8(index++,  m_stableSlots);
        stmt->setUInt16(index++, (uint16)m_atLoginFlags);
        stmt->setUInt16(index++, GetZoneId());
        stmt->setUInt32(index++, uint32(m_deathExpireTime));

        ss.str("");
        ss << m_taxi.SaveTaxiDestinationsToString();

        stmt->setString(index++, ss.str());
        stmt->setUInt32(index++, GetUInt32Value(PLAYER_FIELD_LIFETIME_HONORABLE_KILLS));
        stmt->setUInt16(index++, GetUInt16Value(PLAYER_FIELD_KILLS, PLAYER_FIELD_KILLS_OFFSET_TODAY_KILLS));
        stmt->setUInt16(index++, GetUInt16Value(PLAYER_FIELD_KILLS, PLAYER_FIELD_KILLS_OFFSET_YESTERDAY_KILLS));
        stmt->setUInt32(index++, GetUInt32Value(PLAYER_CHOSEN_TITLE));
        stmt->setUInt32(index++, GetUInt32Value(PLAYER_FIELD_WATCHED_FACTION_INDEX));
        stmt->setUInt8(index++, GetDrunkValue());
        stmt->setUInt32(index++, GetHealth());

        uint32 storedPowers = 0;
        for (uint32 i = 0; i < MAX_POWERS; ++i)
        {
            if (GetPowerIndex(i) != MAX_POWERS)
            {
                stmt->setUInt32(index++, GetUInt32Value(UNIT_FIELD_POWER + storedPowers));
                if (++storedPowers >= MAX_POWERS_PER_CLASS)
                    break;
            }
        }

        for (; storedPowers < MAX_POWERS_PER_CLASS; ++storedPowers)
            stmt->setUInt32(index++, 0);

        stmt->setUInt32(index++, GetSession()->GetLatency());

        stmt->setUInt8(index++, GetTalentGroupsCount());
        stmt->setUInt8(index++, GetActiveTalentGroup());

        stmt->setUInt32(index++, GetLootSpecId());

        ss.str("");
        for (uint32 i = 0; i < PLAYER_EXPLORED_ZONES_SIZE; ++i)
            ss << GetUInt32Value(PLAYER_EXPLORED_ZONES_1 + i) << ' ';
        stmt->setString(index++, ss.str());

        ss.str("");
        // cache equipment...
        for (uint32 i = 0; i < INVENTORY_SLOT_BAG_END; ++i)
        {
            if (Item* item = GetItemByPos(INVENTORY_SLOT_BAG_0, i))
            {
                ss << item->GetTemplate()->GetInventoryType() << ' ' << item->GetDisplayId() << ' ';
                if (SpellItemEnchantmentEntry const* enchant = sSpellItemEnchantmentStore.LookupEntry(item->GetEnchantmentId(PERM_ENCHANTMENT_SLOT)))
                    ss << enchant->ItemVisual;
                else
                    ss << '0';

                ss << ' ';
            }
            else
                ss << "0 0 0 ";
        }

        stmt->setString(index++, ss.str());

        ss.str("");
        for (uint32 i = 0; i < KNOWN_TITLES_SIZE*2; ++i)
            ss << GetUInt32Value(PLAYER__FIELD_KNOWN_TITLES + i) << ' ';

        stmt->setString(index++, ss.str());
        stmt->setUInt8(index++, GetByteValue(PLAYER_FIELD_BYTES, PLAYER_FIELD_BYTES_OFFSET_ACTION_BAR_TOGGLES));
        stmt->setUInt32(index++, m_grantableLevels);

        stmt->setUInt8(index++, IsInWorld() && !GetSession()->PlayerLogout() ? 1 : 0);
        // Index
        stmt->setUInt64(index, GetGUID().GetCounter());
    }

    SQLTransaction trans = CharacterDatabase.BeginTransaction();

    trans->Append(stmt);

    if (m_mailsUpdated)                                     //save mails only when needed
        _SaveMail(trans);

    _SaveBGData(trans);
    _SaveInventory(trans);
    _SaveVoidStorage(trans);
    _SaveQuestStatus(trans);
    _SaveDailyQuestStatus(trans);
    _SaveWeeklyQuestStatus(trans);
    _SaveSeasonalQuestStatus(trans);
    _SaveMonthlyQuestStatus(trans);
    _SaveTalents(trans);
    _SaveSpells(trans);
    GetSpellHistory()->SaveToDB<Player>(trans);
    _SaveActions(trans);
    _SaveAuras(trans);
    _SaveSkills(trans);
    m_achievementMgr->SaveToDB(trans);
    m_reputationMgr->SaveToDB(trans);
    _SaveEquipmentSets(trans);
    GetSession()->SaveTutorialsData(trans);                 // changed only while character in game
    _SaveGlyphs(trans);
    _SaveInstanceTimeRestrictions(trans);
    _SaveCurrency(trans);
    _SaveCUFProfiles(trans);
    if (_garrison)
        _garrison->SaveToDB(trans);

    // check if stats should only be saved on logout
    // save stats can be out of transaction
    if (m_session->isLogingOut() || !sWorld->getBoolConfig(CONFIG_STATS_SAVE_ONLY_ON_LOGOUT))
        _SaveStats(trans);

    CharacterDatabase.CommitTransaction(trans);

    // TODO: Move this out
    trans = LoginDatabase.BeginTransaction();
    GetSession()->GetCollectionMgr()->SaveAccountToys(trans);
    GetSession()->GetBattlePetMgr()->SaveToDB(trans);
    GetSession()->GetCollectionMgr()->SaveAccountHeirlooms(trans);
    LoginDatabase.CommitTransaction(trans);

    // save pet (hunter pet level and experience and all type pets health/mana).
    if (Pet* pet = GetPet())
        pet->SavePetToDB(PET_SAVE_AS_CURRENT);
}

// fast save function for item/money cheating preventing - save only inventory and money state
void Player::SaveInventoryAndGoldToDB(SQLTransaction& trans)
{
    _SaveInventory(trans);
    _SaveCurrency(trans);
    SaveGoldToDB(trans);
}

void Player::SaveGoldToDB(SQLTransaction& trans) const
{
    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_CHAR_MONEY);
    stmt->setUInt64(0, GetMoney());
    stmt->setUInt64(1, GetGUID().GetCounter());
    trans->Append(stmt);
}

void Player::_SaveActions(SQLTransaction& trans)
{
    PreparedStatement* stmt;

    for (ActionButtonList::iterator itr = m_actionButtons.begin(); itr != m_actionButtons.end();)
    {
        switch (itr->second.uState)
        {
            case ACTIONBUTTON_NEW:
                stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_CHAR_ACTION);
                stmt->setUInt64(0, GetGUID().GetCounter());
                stmt->setUInt8(1, GetActiveTalentGroup());
                stmt->setUInt8(2, itr->first);
                stmt->setUInt32(3, itr->second.GetAction());
                stmt->setUInt8(4, uint8(itr->second.GetType()));
                trans->Append(stmt);

                itr->second.uState = ACTIONBUTTON_UNCHANGED;
                ++itr;
                break;
            case ACTIONBUTTON_CHANGED:
                stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_CHAR_ACTION);
                stmt->setUInt32(0, itr->second.GetAction());
                stmt->setUInt8(1, uint8(itr->second.GetType()));
                stmt->setUInt64(2, GetGUID().GetCounter());
                stmt->setUInt8(3, itr->first);
                stmt->setUInt8(4, GetActiveTalentGroup());
                trans->Append(stmt);

                itr->second.uState = ACTIONBUTTON_UNCHANGED;
                ++itr;
                break;
            case ACTIONBUTTON_DELETED:
                stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHAR_ACTION_BY_BUTTON_SPEC);
                stmt->setUInt64(0, GetGUID().GetCounter());
                stmt->setUInt8(1, itr->first);
                stmt->setUInt8(2, GetActiveTalentGroup());
                trans->Append(stmt);

                m_actionButtons.erase(itr++);
                break;
            default:
                ++itr;
                break;
        }
    }
}

void Player::_SaveAuras(SQLTransaction& trans)
{
    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHAR_AURA_EFFECT);
    stmt->setUInt64(0, GetGUID().GetCounter());
    trans->Append(stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHAR_AURA);
    stmt->setUInt64(0, GetGUID().GetCounter());
    trans->Append(stmt);

    uint8 index;
    for (AuraMap::const_iterator itr = m_ownedAuras.begin(); itr != m_ownedAuras.end(); ++itr)
    {
        if (!itr->second->CanBeSaved())
            continue;

        Aura* aura = itr->second;
        uint32 recalculateMask = 0;
        AuraKey key = aura->GenerateKey(recalculateMask);

        index = 0;
        stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_AURA);
        stmt->setUInt64(index++, GetGUID().GetCounter());
        stmt->setBinary(index++, key.Caster.GetRawValue());
        stmt->setBinary(index++, key.Item.GetRawValue());
        stmt->setUInt32(index++, key.SpellId);
        stmt->setUInt32(index++, key.EffectMask);
        stmt->setUInt8(index++, recalculateMask);
        stmt->setUInt8(index++, aura->GetStackAmount());
        stmt->setInt32(index++, aura->GetMaxDuration());
        stmt->setInt32(index++, aura->GetDuration());
        stmt->setUInt8(index++, aura->GetCharges());
        stmt->setInt32(index++, aura->GetCastItemLevel());
        trans->Append(stmt);

        for (AuraEffect const* effect : aura->GetAuraEffects())
        {
            if (effect)
            {
                index = 0;
                stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_AURA_EFFECT);
                stmt->setUInt64(index++, GetGUID().GetCounter());
                stmt->setBinary(index++, key.Caster.GetRawValue());
                stmt->setBinary(index++, key.Item.GetRawValue());
                stmt->setUInt32(index++, key.SpellId);
                stmt->setUInt32(index++, key.EffectMask);
                stmt->setUInt8(index++, effect->GetEffIndex());
                stmt->setInt32(index++, effect->GetAmount());
                stmt->setInt32(index++, effect->GetBaseAmount());
                trans->Append(stmt);
            }
        }
    }
}

void Player::_SaveInventory(SQLTransaction& trans)
{
    PreparedStatement* stmt;
    // force items in buyback slots to new state
    // and remove those that aren't already
    for (uint8 i = BUYBACK_SLOT_START; i < BUYBACK_SLOT_END; ++i)
    {
        Item* item = m_items[i];
        if (!item || item->GetState() == ITEM_NEW)
            continue;

        stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHAR_INVENTORY_BY_ITEM);
        stmt->setUInt64(0, item->GetGUID().GetCounter());
        trans->Append(stmt);

        stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_ITEM_INSTANCE);
        stmt->setUInt64(0, item->GetGUID().GetCounter());
        trans->Append(stmt);
        m_items[i]->FSetState(ITEM_NEW);
    }

    // Updated played time for refundable items. We don't do this in Player::Update because there's simply no need for it,
    // the client auto counts down in real time after having received the initial played time on the first
    // SMSG_ITEM_REFUND_INFO_RESPONSE packet.
    // Item::UpdatePlayedTime is only called when needed, which is in DB saves, and item refund info requests.
    GuidSet::iterator i_next;
    for (GuidSet::iterator itr = m_refundableItems.begin(); itr!= m_refundableItems.end(); itr = i_next)
    {
        // use copy iterator because itr may be invalid after operations in this loop
        i_next = itr;
        ++i_next;

        Item* iPtr = GetItemByGuid(*itr);
        if (iPtr)
        {
            iPtr->UpdatePlayedTime(this);
            continue;
        }
        else
        {
            TC_LOG_ERROR("entities.player", "Player::_SaveInventory: Can't find item (%s) in refundable storage for player '%s' (%s), removing.",
                itr->ToString().c_str(), GetName().c_str(), GetGUID().ToString().c_str());
            m_refundableItems.erase(itr);
        }
    }

    // update enchantment durations
    for (EnchantDurationList::iterator itr = m_enchantDuration.begin(); itr != m_enchantDuration.end(); ++itr)
        itr->item->SetEnchantmentDuration(itr->slot, itr->leftduration, this);

    // if no changes
    if (m_itemUpdateQueue.empty())
        return;

    for (size_t i = 0; i < m_itemUpdateQueue.size(); ++i)
    {
        Item* item = m_itemUpdateQueue[i];
        if (!item)
            continue;

        Bag* container = item->GetContainer();
        if (item->GetState() != ITEM_REMOVED)
        {
            Item* test = GetItemByPos(item->GetBagSlot(), item->GetSlot());
            if (test == nullptr)
            {
                ObjectGuid::LowType bagTestGUID = UI64LIT(0);
                if (Item* test2 = GetItemByPos(INVENTORY_SLOT_BAG_0, item->GetBagSlot()))
                    bagTestGUID = test2->GetGUID().GetCounter();

                TC_LOG_ERROR("entities.player", "Player::_SaveInventory: Player '%s' (%s) has incorrect values (Bag: %u, Slot: %u) for the item (%s, State: %d). The player doesn't have an item at that position.",
                    GetName().c_str(), GetGUID().ToString().c_str(), item->GetBagSlot(), item->GetSlot(), item->GetGUID().ToString().c_str(), (int32)item->GetState());
                // according to the test that was just performed nothing should be in this slot, delete
                stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHAR_INVENTORY_BY_BAG_SLOT);
                stmt->setUInt64(0, bagTestGUID);
                stmt->setUInt8(1, item->GetSlot());
                stmt->setUInt64(2, GetGUID().GetCounter());
                trans->Append(stmt);

                // also THIS item should be somewhere else, cheat attempt
                item->FSetState(ITEM_REMOVED); // we are IN updateQueue right now, can't use SetState which modifies the queue
                DeleteRefundReference(item->GetGUID());
                // don't skip, let the switch delete it
                //continue;
            }
            else if (test != item)
            {
                TC_LOG_ERROR("entities.player", "Player::_SaveInventory: Player '%s' (%s) has incorrect values (Bag: %u, Slot: %u) for the item (%s). %s is there instead!",
                    GetName().c_str(), GetGUID().ToString().c_str(), item->GetBagSlot(), item->GetSlot(), item->GetGUID().ToString().c_str(), test->GetGUID().ToString().c_str());
                // save all changes to the item...
                if (item->GetState() != ITEM_NEW) // only for existing items, no dupes
                    item->SaveToDB(trans);
                // ...but do not save position in inventory
                continue;
            }
        }

        switch (item->GetState())
        {
            case ITEM_NEW:
            case ITEM_CHANGED:
                stmt = CharacterDatabase.GetPreparedStatement(CHAR_REP_INVENTORY_ITEM);
                stmt->setUInt64(0, GetGUID().GetCounter());
                stmt->setUInt64(1, container ? container->GetGUID().GetCounter() : UI64LIT(0));
                stmt->setUInt8 (2, item->GetSlot());
                stmt->setUInt64(3, item->GetGUID().GetCounter());
                trans->Append(stmt);
                break;
            case ITEM_REMOVED:
                stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHAR_INVENTORY_BY_ITEM);
                stmt->setUInt64(0, item->GetGUID().GetCounter());
                trans->Append(stmt);
            case ITEM_UNCHANGED:
                break;
        }

        item->SaveToDB(trans);                                   // item have unchanged inventory record and can be save standalone
    }
    m_itemUpdateQueue.clear();
}

void Player::_SaveVoidStorage(SQLTransaction& trans)
{
    PreparedStatement* stmt = nullptr;

    for (uint8 i = 0; i < VOID_STORAGE_MAX_SLOT; ++i)
    {
        if (!_voidStorageItems[i]) // unused item
        {
            // DELETE FROM void_storage WHERE slot = ? AND playerGuid = ?
            stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHAR_VOID_STORAGE_ITEM_BY_SLOT);
            stmt->setUInt8(0, i);
            stmt->setUInt64(1, GetGUID().GetCounter());
        }
        else
        {
            // REPLACE INTO character_inventory (itemId, playerGuid, itemEntry, slot, creatorGuid, randomProperty, suffixFactor, upgradeId, bonusListIDs) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?)
            stmt = CharacterDatabase.GetPreparedStatement(CHAR_REP_CHAR_VOID_STORAGE_ITEM);
            stmt->setUInt64(0, _voidStorageItems[i]->ItemId);
            stmt->setUInt64(1, GetGUID().GetCounter());
            stmt->setUInt32(2, _voidStorageItems[i]->ItemEntry);
            stmt->setUInt8(3, i);
            stmt->setUInt64(4, _voidStorageItems[i]->CreatorGuid.GetCounter());
            stmt->setUInt32(5, _voidStorageItems[i]->ItemRandomPropertyId);
            stmt->setUInt32(6, _voidStorageItems[i]->ItemSuffixFactor);
            stmt->setUInt32(7, _voidStorageItems[i]->ItemUpgradeId);
            std::ostringstream bonusListIDs;
            for (int32 bonusListID : _voidStorageItems[i]->BonusListIDs)
                bonusListIDs << bonusListID << ' ';
            stmt->setString(8, bonusListIDs.str());
        }

        trans->Append(stmt);
    }
}


void Player::_SaveCUFProfiles(SQLTransaction& trans)
{
    PreparedStatement* stmt;
    for (uint8 i = 0; i < MAX_CUF_PROFILES; ++i)
    {
        if (!_CUFProfiles[i]) // unused profile
        {
            // DELETE FROM character_cuf_profiles WHERE guid = ? and id = ?
            stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHAR_CUF_PROFILES_BY_ID);
            stmt->setUInt64(0, GetGUID().GetCounter());
            stmt->setUInt8(1, i);
        }
        else
        {
            // REPLACE INTO character_cuf_profiles (guid, id, name, frameHeight, frameWidth, sortBy, healthText, boolOptions, unk146, unk147, unk148, unk150, unk152, unk154) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)
            stmt = CharacterDatabase.GetPreparedStatement(CHAR_REP_CHAR_CUF_PROFILES);
            stmt->setUInt64(0, GetGUID().GetCounter());
            stmt->setUInt8(1, i);
            stmt->setString(2, _CUFProfiles[i]->ProfileName);
            stmt->setUInt16(3, _CUFProfiles[i]->FrameHeight);
            stmt->setUInt16(4, _CUFProfiles[i]->FrameWidth);
            stmt->setUInt8(5, _CUFProfiles[i]->SortBy);
            stmt->setUInt8(6, _CUFProfiles[i]->HealthText);
            stmt->setUInt32(7, _CUFProfiles[i]->BoolOptions.to_ulong()); // 25 of 32 fields used, fits in an int
            stmt->setUInt8(8, _CUFProfiles[i]->TopPoint);
            stmt->setUInt8(9, _CUFProfiles[i]->BottomPoint);
            stmt->setUInt8(10, _CUFProfiles[i]->LeftPoint);
            stmt->setUInt16(11, _CUFProfiles[i]->TopOffset);
            stmt->setUInt16(12, _CUFProfiles[i]->BottomOffset);
            stmt->setUInt16(13, _CUFProfiles[i]->LeftOffset);
        }

        trans->Append(stmt);
    }
}

void Player::_SaveMail(SQLTransaction& trans)
{
    if (!m_mailsLoaded)
        return;

    PreparedStatement* stmt;

    for (PlayerMails::iterator itr = m_mail.begin(); itr != m_mail.end(); ++itr)
    {
        Mail* m = (*itr);
        if (m->state == MAIL_STATE_CHANGED)
        {
            stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_MAIL);
            stmt->setUInt8(0, uint8(m->HasItems() ? 1 : 0));
            stmt->setUInt32(1, uint32(m->expire_time));
            stmt->setUInt32(2, uint32(m->deliver_time));
            stmt->setUInt32(3, m->money);
            stmt->setUInt32(4, m->COD);
            stmt->setUInt8(5, uint8(m->checked));
            stmt->setUInt32(6, m->messageID);

            trans->Append(stmt);

            if (!m->removedItems.empty())
            {
                for (std::vector<ObjectGuid::LowType>::iterator itr2 = m->removedItems.begin(); itr2 != m->removedItems.end(); ++itr2)
                {
                    stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_MAIL_ITEM);
                    stmt->setUInt64(0, *itr2);
                    trans->Append(stmt);
                }
                m->removedItems.clear();
            }
            m->state = MAIL_STATE_UNCHANGED;
        }
        else if (m->state == MAIL_STATE_DELETED)
        {
            if (m->HasItems())
            {
                for (MailItemInfoVec::iterator itr2 = m->items.begin(); itr2 != m->items.end(); ++itr2)
                {
                    stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_ITEM_INSTANCE);
                    stmt->setUInt64(0, itr2->item_guid);
                    trans->Append(stmt);
                }
            }
            stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_MAIL_BY_ID);
            stmt->setUInt32(0, m->messageID);
            trans->Append(stmt);

            stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_MAIL_ITEM_BY_ID);
            stmt->setUInt32(0, m->messageID);
            trans->Append(stmt);
        }
    }

    //deallocate deleted mails...
    for (PlayerMails::iterator itr = m_mail.begin(); itr != m_mail.end();)
    {
        if ((*itr)->state == MAIL_STATE_DELETED)
        {
            Mail* m = *itr;
            m_mail.erase(itr);
            delete m;
            itr = m_mail.begin();
        }
        else
            ++itr;
    }

    m_mailsUpdated = false;
}

void Player::_SaveQuestStatus(SQLTransaction& trans)
{
    bool isTransaction = bool(trans);
    if (!isTransaction)
        trans = CharacterDatabase.BeginTransaction();

    QuestStatusSaveMap::iterator saveItr;
    QuestStatusMap::iterator statusItr;
    PreparedStatement* stmt;

    bool keepAbandoned = !(sWorld->GetCleaningFlags() & CharacterDatabaseCleaner::CLEANING_FLAG_QUESTSTATUS);

    for (saveItr = m_QuestStatusSave.begin(); saveItr != m_QuestStatusSave.end(); ++saveItr)
    {
        if (saveItr->second == QUEST_DEFAULT_SAVE_TYPE)
        {
            statusItr = m_QuestStatus.find(saveItr->first);
            if (statusItr != m_QuestStatus.end() && (keepAbandoned || statusItr->second.Status != QUEST_STATUS_NONE))
            {
                QuestStatusData const& qData = statusItr->second;

                // Save main quest status and timer
                stmt = CharacterDatabase.GetPreparedStatement(CHAR_REP_CHAR_QUESTSTATUS);
                stmt->setUInt64(0, GetGUID().GetCounter());
                stmt->setUInt32(1, statusItr->first);
                stmt->setUInt8(2, uint8(qData.Status));
                stmt->setUInt32(3, uint32(qData.Timer / IN_MILLISECONDS+ sWorld->GetGameTime()));
                trans->Append(stmt);

                // Save objectives
                for (uint32 i = 0; i < qData.ObjectiveData.size(); ++i)
                {
                    stmt = CharacterDatabase.GetPreparedStatement(CHAR_REP_CHAR_QUESTSTATUS_OBJECTIVES);
                    stmt->setUInt64(0, GetGUID().GetCounter());
                    stmt->setUInt32(1, statusItr->first);
                    stmt->setUInt8(2, i);
                    stmt->setInt32(3, qData.ObjectiveData[i]);
                    trans->Append(stmt);
                }
            }
        }
        else
        {
            // Delete
            stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHAR_QUESTSTATUS_BY_QUEST);
            stmt->setUInt64(0, GetGUID().GetCounter());
            stmt->setUInt32(1, saveItr->first);
            trans->Append(stmt);

            stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHAR_QUESTSTATUS_OBJECTIVES_BY_QUEST);
            stmt->setUInt64(0, GetGUID().GetCounter());
            stmt->setUInt32(1, saveItr->first);
            trans->Append(stmt);
        }
    }

    m_QuestStatusSave.clear();

    for (saveItr = m_RewardedQuestsSave.begin(); saveItr != m_RewardedQuestsSave.end(); ++saveItr)
    {
        if (saveItr->second == QUEST_DEFAULT_SAVE_TYPE)
        {
            stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_CHAR_QUESTSTATUS_REWARDED);
            stmt->setUInt64(0, GetGUID().GetCounter());
            stmt->setUInt32(1, saveItr->first);
            trans->Append(stmt);

        }
        else if (saveItr->second == QUEST_FORCE_DELETE_SAVE_TYPE || !keepAbandoned)
        {
            stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHAR_QUESTSTATUS_REWARDED_BY_QUEST);
            stmt->setUInt64(0, GetGUID().GetCounter());
            stmt->setUInt32(1, saveItr->first);
            trans->Append(stmt);
        }
    }

    m_RewardedQuestsSave.clear();

    if (!isTransaction)
        CharacterDatabase.CommitTransaction(trans);
}

void Player::_SaveDailyQuestStatus(SQLTransaction& trans)
{
    if (!m_DailyQuestChanged)
        return;

    m_DailyQuestChanged = false;

    // save last daily quest time for all quests: we need only mostly reset time for reset check anyway

    // we don't need transactions here.
    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHARACTER_QUESTSTATUS_DAILY);
    stmt->setUInt64(0, GetGUID().GetCounter());
    trans->Append(stmt);

    std::vector<uint32> const& dailies = GetDynamicValues(PLAYER_DYNAMIC_FIELD_DAILY_QUESTS);
    for (uint32 questId : dailies)
    {
        stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_CHARACTER_QUESTSTATUS_DAILY);
        stmt->setUInt64(0, GetGUID().GetCounter());
        stmt->setUInt32(1, questId);
        stmt->setUInt64(2, uint64(m_lastDailyQuestTime));
        trans->Append(stmt);
    }

    if (!m_DFQuests.empty())
    {
        for (DFQuestsDoneList::iterator itr = m_DFQuests.begin(); itr != m_DFQuests.end(); ++itr)
        {
            stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_CHARACTER_QUESTSTATUS_DAILY);
            stmt->setUInt64(0, GetGUID().GetCounter());
            stmt->setUInt32(1, (*itr));
            stmt->setUInt64(2, uint64(m_lastDailyQuestTime));
            trans->Append(stmt);
        }
    }
}

void Player::_SaveWeeklyQuestStatus(SQLTransaction& trans)
{
    if (!m_WeeklyQuestChanged || m_weeklyquests.empty())
        return;

    // we don't need transactions here.
    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHARACTER_QUESTSTATUS_WEEKLY);
    stmt->setUInt64(0, GetGUID().GetCounter());
    trans->Append(stmt);

    for (QuestSet::const_iterator iter = m_weeklyquests.begin(); iter != m_weeklyquests.end(); ++iter)
    {
        uint32 questId  = *iter;

        stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_CHARACTER_QUESTSTATUS_WEEKLY);
        stmt->setUInt64(0, GetGUID().GetCounter());
        stmt->setUInt32(1, questId);
        trans->Append(stmt);
    }

    m_WeeklyQuestChanged = false;
}

void Player::_SaveSeasonalQuestStatus(SQLTransaction& trans)
{
    if (!m_SeasonalQuestChanged || m_seasonalquests.empty())
        return;

    // we don't need transactions here.
    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHARACTER_QUESTSTATUS_SEASONAL);
    stmt->setUInt64(0, GetGUID().GetCounter());
    trans->Append(stmt);

    for (SeasonalEventQuestMap::const_iterator iter = m_seasonalquests.begin(); iter != m_seasonalquests.end(); ++iter)
    {
        uint16 eventId = iter->first;

        for (SeasonalQuestSet::const_iterator itr = iter->second.begin(); itr != iter->second.end(); ++itr)
        {
            uint32 questId = *itr;

            stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_CHARACTER_QUESTSTATUS_SEASONAL);
            stmt->setUInt64(0, GetGUID().GetCounter());
            stmt->setUInt32(1, questId);
            stmt->setUInt32(2, eventId);
            trans->Append(stmt);
        }
    }

    m_SeasonalQuestChanged = false;
}

void Player::_SaveMonthlyQuestStatus(SQLTransaction& trans)
{
    if (!m_MonthlyQuestChanged || m_monthlyquests.empty())
        return;

    // we don't need transactions here.
    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHARACTER_QUESTSTATUS_MONTHLY);
    stmt->setUInt64(0, GetGUID().GetCounter());
    trans->Append(stmt);

    for (QuestSet::const_iterator iter = m_monthlyquests.begin(); iter != m_monthlyquests.end(); ++iter)
    {
        uint32 questId = *iter;

        stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_CHARACTER_QUESTSTATUS_MONTHLY);
        stmt->setUInt64(0, GetGUID().GetCounter());
        stmt->setUInt32(1, questId);
        trans->Append(stmt);
    }

    m_MonthlyQuestChanged = false;
}

void Player::_SaveSkills(SQLTransaction& trans)
{
    PreparedStatement* stmt;
    // we don't need transactions here.
    for (SkillStatusMap::iterator itr = mSkillStatus.begin(); itr != mSkillStatus.end();)
    {
        if (itr->second.uState == SKILL_UNCHANGED)
        {
            ++itr;
            continue;
        }

        if (itr->second.uState == SKILL_DELETED)
        {
            stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHAR_SKILL_BY_SKILL);
            stmt->setUInt64(0, GetGUID().GetCounter());
            stmt->setUInt32(1, itr->first);
            trans->Append(stmt);

            mSkillStatus.erase(itr++);
            continue;
        }

        uint16 field = itr->second.pos / 2;
        uint8 offset = itr->second.pos & 1;

        uint16 value = GetUInt16Value(PLAYER_SKILL_LINEID + SKILL_RANK_OFFSET + field, offset);
        uint16 max = GetUInt16Value(PLAYER_SKILL_LINEID + SKILL_MAX_RANK_OFFSET + field, offset);

        switch (itr->second.uState)
        {
            case SKILL_NEW:
                stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_CHAR_SKILLS);
                stmt->setUInt64(0, GetGUID().GetCounter());
                stmt->setUInt16(1, uint16(itr->first));
                stmt->setUInt16(2, value);
                stmt->setUInt16(3, max);
                trans->Append(stmt);
                break;
            case SKILL_CHANGED:
                stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_CHAR_SKILLS);
                stmt->setUInt16(0, value);
                stmt->setUInt16(1, max);
                stmt->setUInt64(2, GetGUID().GetCounter());
                stmt->setUInt16(3, uint16(itr->first));
                trans->Append(stmt);
                break;
            default:
                break;
        }

        itr->second.uState = SKILL_UNCHANGED;
        ++itr;
    }
}

void Player::_SaveSpells(SQLTransaction& trans)
{
    PreparedStatement* stmt;

    for (PlayerSpellMap::iterator itr = m_spells.begin(); itr != m_spells.end();)
    {
        if (itr->second->state == PLAYERSPELL_REMOVED || itr->second->state == PLAYERSPELL_CHANGED)
        {
            stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHAR_SPELL_BY_SPELL);
            stmt->setUInt32(0, itr->first);
            stmt->setUInt64(1, GetGUID().GetCounter());
            trans->Append(stmt);
        }

        // add only changed/new not dependent spells
        if (!itr->second->dependent && (itr->second->state == PLAYERSPELL_NEW || itr->second->state == PLAYERSPELL_CHANGED))
        {
            stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_CHAR_SPELL);
            stmt->setUInt64(0, GetGUID().GetCounter());
            stmt->setUInt32(1, itr->first);
            stmt->setBool(2, itr->second->active);
            stmt->setBool(3, itr->second->disabled);
            trans->Append(stmt);
        }

        if (itr->second->state == PLAYERSPELL_REMOVED)
        {
            delete itr->second;
            m_spells.erase(itr++);
        }
        else
        {
            itr->second->state = PLAYERSPELL_UNCHANGED;
            ++itr;
        }
    }
}

// save player stats -- only for external usage
// real stats will be recalculated on player login
void Player::_SaveStats(SQLTransaction& trans) const
{
    // check if stat saving is enabled and if char level is high enough
    if (!sWorld->getIntConfig(CONFIG_MIN_LEVEL_STAT_SAVE) || getLevel() < sWorld->getIntConfig(CONFIG_MIN_LEVEL_STAT_SAVE))
        return;

    PreparedStatement* stmt;

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHAR_STATS);
    stmt->setUInt64(0, GetGUID().GetCounter());
    trans->Append(stmt);

    uint8 index = 0;

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_CHAR_STATS);
    stmt->setUInt64(index++, GetGUID().GetCounter());
    stmt->setUInt32(index++, GetMaxHealth());

    for (uint8 i = 0; i < MAX_POWERS_PER_CLASS; ++i)
        stmt->setUInt32(index++, GetMaxPower(Powers(i)));

    for (uint8 i = 0; i < MAX_STATS; ++i)
        stmt->setUInt32(index++, GetStat(Stats(i)));

    for (int i = 0; i < MAX_SPELL_SCHOOL; ++i)
        stmt->setUInt32(index++, GetResistance(SpellSchools(i)));

    stmt->setFloat(index++, GetFloatValue(PLAYER_BLOCK_PERCENTAGE));
    stmt->setFloat(index++, GetFloatValue(PLAYER_DODGE_PERCENTAGE));
    stmt->setFloat(index++, GetFloatValue(PLAYER_PARRY_PERCENTAGE));
    stmt->setFloat(index++, GetFloatValue(PLAYER_CRIT_PERCENTAGE));
    stmt->setFloat(index++, GetFloatValue(PLAYER_RANGED_CRIT_PERCENTAGE));
    stmt->setFloat(index++, GetFloatValue(PLAYER_SPELL_CRIT_PERCENTAGE1));
    stmt->setUInt32(index++, GetUInt32Value(UNIT_FIELD_ATTACK_POWER));
    stmt->setUInt32(index++, GetUInt32Value(UNIT_FIELD_RANGED_ATTACK_POWER));
    stmt->setUInt32(index++, GetBaseSpellPowerBonus());
    stmt->setUInt32(index, GetUInt32Value(PLAYER_FIELD_COMBAT_RATING_1 + CR_RESILIENCE_PLAYER_DAMAGE_TAKEN));

    trans->Append(stmt);
}

void Player::outDebugValues() const
{
    if (!sLog->ShouldLog("entities.unit", LOG_LEVEL_DEBUG))
        return;

    TC_LOG_DEBUG("entities.unit", "HP is: \t\t\t%u\t\tMP is: \t\t\t%u", GetMaxHealth(), GetMaxPower(POWER_MANA));
    TC_LOG_DEBUG("entities.unit", "AGILITY is: \t\t%f\t\tSTRENGTH is: \t\t%f", GetStat(STAT_AGILITY), GetStat(STAT_STRENGTH));
    TC_LOG_DEBUG("entities.unit", "INTELLECT is: \t\t%f\t\tSPIRIT is: \t\t%f", GetStat(STAT_INTELLECT), GetStat(STAT_SPIRIT));
    TC_LOG_DEBUG("entities.unit", "STAMINA is: \t\t%f", GetStat(STAT_STAMINA));
    TC_LOG_DEBUG("entities.unit", "Armor is: \t\t%u\t\tBlock is: \t\t%f", GetArmor(), GetFloatValue(PLAYER_BLOCK_PERCENTAGE));
    TC_LOG_DEBUG("entities.unit", "HolyRes is: \t\t%u\t\tFireRes is: \t\t%u", GetResistance(SPELL_SCHOOL_HOLY), GetResistance(SPELL_SCHOOL_FIRE));
    TC_LOG_DEBUG("entities.unit", "NatureRes is: \t\t%u\t\tFrostRes is: \t\t%u", GetResistance(SPELL_SCHOOL_NATURE), GetResistance(SPELL_SCHOOL_FROST));
    TC_LOG_DEBUG("entities.unit", "ShadowRes is: \t\t%u\t\tArcaneRes is: \t\t%u", GetResistance(SPELL_SCHOOL_SHADOW), GetResistance(SPELL_SCHOOL_ARCANE));
    TC_LOG_DEBUG("entities.unit", "MIN_DAMAGE is: \t\t%f\tMAX_DAMAGE is: \t\t%f", GetFloatValue(UNIT_FIELD_MINDAMAGE), GetFloatValue(UNIT_FIELD_MAXDAMAGE));
    TC_LOG_DEBUG("entities.unit", "MIN_OFFHAND_DAMAGE is: \t%f\tMAX_OFFHAND_DAMAGE is: \t%f", GetFloatValue(UNIT_FIELD_MINOFFHANDDAMAGE), GetFloatValue(UNIT_FIELD_MAXOFFHANDDAMAGE));
    TC_LOG_DEBUG("entities.unit", "MIN_RANGED_DAMAGE is: \t%f\tMAX_RANGED_DAMAGE is: \t%f", GetFloatValue(UNIT_FIELD_MINRANGEDDAMAGE), GetFloatValue(UNIT_FIELD_MAXRANGEDDAMAGE));
    TC_LOG_DEBUG("entities.unit", "ATTACK_TIME is: \t%u\t\tRANGE_ATTACK_TIME is: \t%u", GetAttackTime(BASE_ATTACK), GetAttackTime(RANGED_ATTACK));
}

/*********************************************************/
/***               FLOOD FILTER SYSTEM                 ***/
/*********************************************************/

void Player::UpdateSpeakTime()
{
    // ignore chat spam protection for GMs in any mode
    if (GetSession()->HasPermission(rbac::RBAC_PERM_SKIP_CHECK_CHAT_SPAM))
        return;

    time_t current = time(nullptr);
    if (m_speakTime > current)
    {
        uint32 max_count = sWorld->getIntConfig(CONFIG_CHATFLOOD_MESSAGE_COUNT);
        if (!max_count)
            return;

        ++m_speakCount;
        if (m_speakCount >= max_count)
        {
            // prevent overwrite mute time, if message send just before mutes set, for example.
            time_t new_mute = current + sWorld->getIntConfig(CONFIG_CHATFLOOD_MUTE_TIME);
            if (GetSession()->m_muteTime < new_mute)
                GetSession()->m_muteTime = new_mute;

            m_speakCount = 0;
        }
    }
    else
        m_speakCount = 1;

    m_speakTime = current + sWorld->getIntConfig(CONFIG_CHATFLOOD_MESSAGE_DELAY);
}

bool Player::CanSpeak() const
{
    return  GetSession()->m_muteTime <= time (nullptr);
}

/*********************************************************/
/***              LOW LEVEL FUNCTIONS:Notifiers        ***/
/*********************************************************/

void Player::SavePositionInDB(WorldLocation const& loc, uint16 zoneId, ObjectGuid guid, SQLTransaction& trans)
{
    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_CHARACTER_POSITION);

    stmt->setFloat(0, loc.GetPositionX());
    stmt->setFloat(1, loc.GetPositionY());
    stmt->setFloat(2, loc.GetPositionZ());
    stmt->setFloat(3, loc.GetOrientation());
    stmt->setUInt16(4, uint16(loc.GetMapId()));
    stmt->setUInt16(5, zoneId);
    stmt->setUInt64(6, guid.GetCounter());

    CharacterDatabase.ExecuteOrAppend(trans, stmt);
}

void Player::SetUInt32ValueInArray(Tokenizer& Tokenizer, uint16 index, uint32 value)
{
    char buf[11];
    snprintf(buf, 11, "%u", value);

    if (index >= Tokenizer.size())
        return;

    Tokenizer[index] = buf;
}

void Player::SendAttackSwingDeadTarget() const
{
    WorldPackets::Combat::AttackSwingError packet(ATTACKSWINGERR_DEADTARGET);
    GetSession()->SendPacket(packet.Write());
}

void Player::SendAttackSwingCantAttack() const
{
    WorldPackets::Combat::AttackSwingError packet(ATTACKSWINGERR_CANT_ATTACK);
    GetSession()->SendPacket(packet.Write());
}

void Player::SendAttackSwingNotInRange() const
{
    WorldPackets::Combat::AttackSwingError packet(ATTACKSWINGERR_NOTINRANGE);
    GetSession()->SendPacket(packet.Write());
}

void Player::SendAttackSwingBadFacingAttack() const
{
    WorldPackets::Combat::AttackSwingError packet(ATTACKSWINGERR_BADFACING);
    GetSession()->SendPacket(packet.Write());
}

void Player::SendAttackSwingCancelAttack() const
{
    WorldPackets::Combat::CancelCombat packet;
    GetSession()->SendPacket(packet.Write());
}

void Player::SendAutoRepeatCancel(Unit* target)
{
    WorldPackets::Combat::CancelAutoRepeat cancelAutoRepeat;
    cancelAutoRepeat.Guid = target->GetGUID();                     // may be it's target guid
    SendMessageToSet(cancelAutoRepeat.Write(), false);
}

void Player::SendExplorationExperience(uint32 Area, uint32 Experience) const
{
    GetSession()->SendPacket(WorldPackets::Misc::ExplorationExperience(Experience, Area).Write());
}

void Player::SendDungeonDifficulty(int32 forcedDifficulty /*= -1*/) const
{
    WorldPackets::Misc::DungeonDifficultySet dungeonDifficultySet;
    dungeonDifficultySet.DifficultyID = forcedDifficulty == -1 ? GetDungeonDifficultyID() : forcedDifficulty;
    GetSession()->SendPacket(dungeonDifficultySet.Write());
}

void Player::SendRaidDifficulty(bool legacy, int32 forcedDifficulty /*= -1*/) const
{
    WorldPackets::Misc::RaidDifficultySet raidDifficultySet;
    raidDifficultySet.DifficultyID = forcedDifficulty == -1 ? (legacy ? GetLegacyRaidDifficultyID() : GetRaidDifficultyID()) : forcedDifficulty;
    raidDifficultySet.Legacy = legacy;
    GetSession()->SendPacket(raidDifficultySet.Write());
}

void Player::SendResetFailedNotify(uint32 /*mapid*/) const
{
    WorldPackets::Instance::ResetFailedNotify data;
    GetSession()->SendPacket(data.Write());
}

/// Reset all solo instances and optionally send a message on success for each
void Player::ResetInstances(uint8 method, bool isRaid, bool isLegacy)
{
    // method can be INSTANCE_RESET_ALL, INSTANCE_RESET_CHANGE_DIFFICULTY, INSTANCE_RESET_GROUP_JOIN

    // we assume that when the difficulty changes, all instances that can be reset will be
    Difficulty diff = GetDungeonDifficultyID();
    if (isRaid)
    {
        if (!isLegacy)
            diff = GetRaidDifficultyID();
        else
            diff = GetLegacyRaidDifficultyID();
    }

    for (BoundInstancesMap::iterator itr = m_boundInstances[diff].begin(); itr != m_boundInstances[diff].end();)
    {
        InstanceSave* p = itr->second.save;
        const MapEntry* entry = sMapStore.LookupEntry(itr->first);
        if (!entry || entry->IsRaid() != isRaid || !p->CanReset())
        {
            ++itr;
            continue;
        }

        if (method == INSTANCE_RESET_ALL)
        {
            // the "reset all instances" method can only reset normal maps
            if (entry->IsRaid() || diff == DIFFICULTY_HEROIC)
            {
                ++itr;
                continue;
            }
        }

        // if the map is loaded, reset it
        Map* map = sMapMgr->FindMap(p->GetMapId(), p->GetInstanceId());
        if (map && map->IsDungeon())
            if (!map->ToInstanceMap()->Reset(method))
            {
                ++itr;
                continue;
            }

        // since this is a solo instance there should not be any players inside
        if (method == INSTANCE_RESET_ALL || method == INSTANCE_RESET_CHANGE_DIFFICULTY)
            SendResetInstanceSuccess(p->GetMapId());

        p->DeleteFromDB();
        m_boundInstances[diff].erase(itr++);

        // the following should remove the instance save from the manager and delete it as well
        p->RemovePlayer(this);
    }
}

void Player::SendResetInstanceSuccess(uint32 MapId) const
{
    WorldPackets::Instance::InstanceReset data;
    data.MapID = MapId;
    GetSession()->SendPacket(data.Write());
}

void Player::SendResetInstanceFailed(ResetFailedReason reason, uint32 mapID) const
{
    /*reasons for instance reset failure:
    // 0: There are players inside the instance.
    // 1: There are players offline in your party.
    // 2>: There are players in your party attempting to zone into an instance.
    */

    WorldPackets::Instance::InstanceResetFailed data;
    data.MapID = mapID;
    data.ResetFailedReason = reason;
    GetSession()->SendPacket(data.Write());
}

/*********************************************************/
/***              Update timers                        ***/
/*********************************************************/

///checks the 15 afk reports per 5 minutes limit
void Player::UpdateAfkReport(time_t currTime)
{
    if (m_bgData.bgAfkReportedTimer <= currTime)
    {
        m_bgData.bgAfkReportedCount = 0;
        m_bgData.bgAfkReportedTimer = currTime+5*MINUTE;
    }
}

void Player::UpdateContestedPvP(uint32 diff)
{
    if (!m_contestedPvPTimer||IsInCombat())
        return;
    if (m_contestedPvPTimer <= diff)
    {
        ResetContestedPvP();
    }
    else
        m_contestedPvPTimer -= diff;
}

void Player::ResetContestedPvP()
{
    ClearUnitState(UNIT_STATE_ATTACK_PLAYER);
    RemoveFlag(PLAYER_FLAGS, PLAYER_FLAGS_CONTESTED_PVP);
    m_contestedPvPTimer = 0;
}

void Player::UpdatePvPFlag(time_t currTime)
{
    if (!IsPvP())
        return;

    if (!pvpInfo.EndTimer || currTime < (pvpInfo.EndTimer + 300) || pvpInfo.IsHostile)
        return;

    UpdatePvP(false);
}

void Player::UpdateDuelFlag(time_t currTime)
{
    if (!duel || duel->startTimer == 0 ||currTime < duel->startTimer + 3)
        return;

    sScriptMgr->OnPlayerDuelStart(this, duel->opponent);

    SetUInt32Value(PLAYER_DUEL_TEAM, 1);
    duel->opponent->SetUInt32Value(PLAYER_DUEL_TEAM, 2);

    duel->startTimer = 0;
    duel->startTime  = currTime;
    duel->opponent->duel->startTimer = 0;
    duel->opponent->duel->startTime  = currTime;
}

Pet* Player::GetPet() const
{
    ObjectGuid pet_guid = GetPetGUID();
    if (!pet_guid.IsEmpty())
    {
        if (!pet_guid.IsPet())
            return nullptr;

        Pet* pet = ObjectAccessor::GetPet(*this, pet_guid);

        if (!pet)
            return nullptr;

        if (IsInWorld() && pet)
            return pet;

        //there may be a guardian in slot
        //TC_LOG_ERROR("entities.player", "Player::GetPet: Pet %u not exist.", GUID_LOPART(pet_guid));
        //const_cast<Player*>(this)->SetPetGUID(0);
    }

    return nullptr;
}

void Player::RemovePet(Pet* pet, PetSaveMode mode, bool returnreagent)
{
    if (!pet)
        pet = GetPet();

    if (pet)
    {
        TC_LOG_DEBUG("entities.pet", "Player::RemovePet: Player '%s' (%s), Pet (Entry: %u, Mode: %u, ReturnReagent: %u)",
            GetName().c_str(), GetGUID().ToString().c_str(), pet->GetEntry(), mode, returnreagent);

        if (pet->m_removed)
            return;
    }

    if (returnreagent && (pet || m_temporaryUnsummonedPetNumber) && !InBattleground())
    {
        //returning of reagents only for players, so best done here
        uint32 spellId = pet ? pet->GetUInt32Value(UNIT_CREATED_BY_SPELL) : m_oldpetspell;
        SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(spellId);

        if (spellInfo)
        {
            for (uint32 i = 0; i < MAX_SPELL_REAGENTS; ++i)
            {
                if (spellInfo->Reagent[i] > 0)
                {
                    ItemPosCountVec dest;                   //for succubus, voidwalker, felhunter and felguard credit soulshard when despawn reason other than death (out of range, logout)
                    InventoryResult msg = CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, spellInfo->Reagent[i], spellInfo->ReagentCount[i]);
                    if (msg == EQUIP_ERR_OK)
                    {
                        Item* item = StoreNewItem(dest, spellInfo->Reagent[i], true);
                        if (IsInWorld())
                            SendNewItem(item, spellInfo->ReagentCount[i], true, false);
                    }
                }
            }
        }
        m_temporaryUnsummonedPetNumber = 0;
    }

    if (!pet || pet->GetOwnerGUID() != GetGUID())
        return;

    pet->CombatStop();

    if (returnreagent)
    {
        switch (pet->GetEntry())
        {
            //warlock pets except imp are removed(?) when logging out
            case 1860:
            case 1863:
            case 417:
            case 17252:
                mode = PET_SAVE_NOT_IN_SLOT;
                break;
        }
    }

    // only if current pet in slot
    pet->SavePetToDB(mode);

    SetMinion(pet, false);

    pet->AddObjectToRemoveList();
    pet->m_removed = true;

    if (pet->isControlled())
    {
        WorldPackets::Pet::PetSpells petSpellsPacket;
        GetSession()->SendPacket(petSpellsPacket.Write());

        if (GetGroup())
            SetGroupUpdateFlag(GROUP_UPDATE_FLAG_PET);
    }
}

void Player::StopCastingCharm()
{
    Unit* charm = GetCharm();
    if (!charm)
        return;

    if (charm->GetTypeId() == TYPEID_UNIT)
    {
        if (charm->ToCreature()->HasUnitTypeMask(UNIT_MASK_PUPPET))
            static_cast<Puppet*>(charm)->UnSummon();
        else if (charm->IsVehicle())
            ExitVehicle();
    }
    if (!GetCharmGUID().IsEmpty())
        charm->RemoveCharmAuras();

    if (!GetCharmGUID().IsEmpty())
    {
        TC_LOG_FATAL("entities.player", "Player::StopCastingCharm: Player '%s' (%s) is not able to uncharm unit (%s)", GetName().c_str(), GetGUID().ToString().c_str(), GetCharmGUID().ToString().c_str());
        if (!charm->GetCharmerGUID().IsEmpty())
        {
            TC_LOG_FATAL("entities.player", "Player::StopCastingCharm: Charmed unit has charmer %s", charm->GetCharmerGUID().ToString().c_str());
            ABORT();
        }

        SetCharm(charm, false);
    }
}

void Player::Say(std::string const& text, Language language, WorldObject const* /*= nullptr*/)
{
    std::string _text(text);
    sScriptMgr->OnPlayerChat(this, CHAT_MSG_SAY, language, _text);

    WorldPackets::Chat::Chat packet;
    packet.Initialize(CHAT_MSG_SAY, language, this, this, _text);
    SendMessageToSetInRange(packet.Write(), sWorld->getFloatConfig(CONFIG_LISTEN_RANGE_SAY), true);
}

void Player::Yell(std::string const& text, Language language, WorldObject const* /*= nullptr*/)
{
    std::string _text(text);
    sScriptMgr->OnPlayerChat(this, CHAT_MSG_YELL, language, _text);

    WorldPackets::Chat::Chat packet;
    packet.Initialize(CHAT_MSG_YELL, language, this, this, _text);
    SendMessageToSetInRange(packet.Write(), sWorld->getFloatConfig(CONFIG_LISTEN_RANGE_YELL), true);
}

void Player::TextEmote(std::string const& text, WorldObject const* /*= nullptr*/, bool /*= false*/)
{
    std::string _text(text);
    sScriptMgr->OnPlayerChat(this, CHAT_MSG_EMOTE, LANG_UNIVERSAL, _text);

    WorldPackets::Chat::Chat packet;
    packet.Initialize(CHAT_MSG_EMOTE, LANG_UNIVERSAL, this, this, _text);
    SendMessageToSetInRange(packet.Write(), sWorld->getFloatConfig(CONFIG_LISTEN_RANGE_TEXTEMOTE), true, !GetSession()->HasPermission(rbac::RBAC_PERM_TWO_SIDE_INTERACTION_CHAT));
}

void Player::WhisperAddon(std::string const& text, const std::string& prefix, Player* receiver)
{
    std::string _text(text);
    sScriptMgr->OnPlayerChat(this, CHAT_MSG_WHISPER, uint32(LANG_ADDON), _text, receiver);

    if (!receiver->GetSession()->IsAddonRegistered(prefix))
        return;

    WorldPackets::Chat::Chat packet;
    packet.Initialize(CHAT_MSG_WHISPER, LANG_ADDON, this, this, text, 0, "", DEFAULT_LOCALE, prefix);
    receiver->SendDirectMessage(packet.Write());
}

void Player::Whisper(std::string const& text, Language language, Player* target, bool /*= false*/)
{
    ASSERT(target);

    bool isAddonMessage = language == LANG_ADDON;

    if (!isAddonMessage) // if not addon data
        language = LANG_UNIVERSAL; // whispers should always be readable

    std::string _text(text);
    sScriptMgr->OnPlayerChat(this, CHAT_MSG_WHISPER, language, _text, target);

    WorldPackets::Chat::Chat packet;
    packet.Initialize(CHAT_MSG_WHISPER, Language(language), this, this, _text);
    target->SendDirectMessage(packet.Write());

    // rest stuff shouldn't happen in case of addon message
    if (isAddonMessage)
        return;

    packet.Initialize(CHAT_MSG_WHISPER_INFORM, Language(language), target, target, _text);
    SendDirectMessage(packet.Write());

    if (!isAcceptWhispers() && !IsGameMaster() && !target->IsGameMaster())
    {
        SetAcceptWhispers(true);
        ChatHandler(GetSession()).SendSysMessage(LANG_COMMAND_WHISPERON);
    }

    // announce afk or dnd message
    if (target->isAFK())
        ChatHandler(GetSession()).PSendSysMessage(LANG_PLAYER_AFK, target->GetName().c_str(), target->autoReplyMsg.c_str());
    else if (target->isDND())
        ChatHandler(GetSession()).PSendSysMessage(LANG_PLAYER_DND, target->GetName().c_str(), target->autoReplyMsg.c_str());
}

Item* Player::GetMItem(ObjectGuid::LowType id)
{
    ItemMap::const_iterator itr = mMitems.find(id);
    return itr != mMitems.end() ? itr->second : NULL;
}

void Player::AddMItem(Item* it)
{
    ASSERT(it);
    //ASSERT deleted, because items can be added before loading
    mMitems[it->GetGUID().GetCounter()] = it;
}

bool Player::RemoveMItem(ObjectGuid::LowType id)
{
    return mMitems.erase(id) ? true : false;
}

void Player::SendOnCancelExpectedVehicleRideAura() const
{
    GetSession()->SendPacket(WorldPackets::Vehicle::OnCancelExpectedRideVehicleAura().Write());
}

void Player::PetSpellInitialize()
{
    Pet* pet = GetPet();

    if (!pet)
        return;

    CharmInfo* charmInfo = pet->GetCharmInfo();

    WorldPackets::Pet::PetSpells petSpellsPacket;
    petSpellsPacket.PetGUID = pet->GetGUID();
    petSpellsPacket.CreatureFamily = pet->GetCreatureTemplate()->family;         // creature family (required for pet talents)
    //petSpellsPacket.Specialization = pet->GetSpecialization(); NYI
    petSpellsPacket.TimeLimit = pet->GetDuration();
    petSpellsPacket.ReactState = pet->GetReactState();
    petSpellsPacket.CommandState = charmInfo->GetCommandState();

    // action bar loop
    for (uint32 i = 0; i < MAX_UNIT_ACTION_BAR_INDEX; ++i)
        petSpellsPacket.ActionButtons[i] = charmInfo->GetActionBarEntry(i)->packedData;

    if (pet->IsPermanentPetFor(this))
    {
        // spells loop
        for (PetSpellMap::iterator itr = pet->m_spells.begin(); itr != pet->m_spells.end(); ++itr)
        {
            if (itr->second.state == PETSPELL_REMOVED)
                continue;

            petSpellsPacket.Actions.push_back(MAKE_UNIT_ACTION_BUTTON(itr->first, itr->second.active));
        }
    }

    // Cooldowns
    pet->GetSpellHistory()->WritePacket(&petSpellsPacket);

    GetSession()->SendPacket(petSpellsPacket.Write());
}

void Player::PossessSpellInitialize()
{
    Unit* charm = GetCharm();
    if (!charm)
        return;

    CharmInfo* charmInfo = charm->GetCharmInfo();

    if (!charmInfo)
    {
        TC_LOG_ERROR("entities.player", "Player::PossessSpellInitialize: charm (%s) has no charminfo!", charm->GetGUID().ToString().c_str());
        return;
    }

    WorldPackets::Pet::PetSpells petSpellsPacket;
    petSpellsPacket.PetGUID = charm->GetGUID();

    for (uint32 i = 0; i < MAX_UNIT_ACTION_BAR_INDEX; ++i)
        petSpellsPacket.ActionButtons[i] = charmInfo->GetActionBarEntry(i)->packedData;

    // Cooldowns
    charm->GetSpellHistory()->WritePacket(&petSpellsPacket);

    GetSession()->SendPacket(petSpellsPacket.Write());
}

void Player::VehicleSpellInitialize()
{
    Creature* vehicle = GetVehicleCreatureBase();
    if (!vehicle)
        return;

    uint8 cooldownCount = 0;

    WorldPacket data(SMSG_PET_SPELLS_MESSAGE, 8 + 2 + 4 + 4 + 4 * 10 + 1 + 1 + cooldownCount * (4 + 2 + 4 + 4));
    data << vehicle->GetGUID();                             // Guid
    data << uint16(0);                                      // Pet Family (0 for all vehicles)
    data << uint32(vehicle->IsSummon() ? vehicle->ToTempSummon()->GetTimer() : 0); // Duration
    // The following three segments are read by the client as one uint32
    data << uint8(vehicle->GetReactState());                // React State
    data << uint8(0);                                       // Command State
    data << uint16(0x800);                                  // DisableActions (set for all vehicles)

    for (uint32 i = 0; i < CREATURE_MAX_SPELLS; ++i)
    {
        uint32 spellId = vehicle->m_spells[i];
        SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(spellId);
        if (!spellInfo)
        {
            data << uint16(0) << uint8(0) << uint8(i+8);
            continue;
        }

        if (!sConditionMgr->IsObjectMeetingVehicleSpellConditions(vehicle->GetEntry(), spellId, this, vehicle))
        {
            TC_LOG_DEBUG("condition", "Player::VehicleSpellInitialize: Player '%s' (%s) doesn't meet conditions for vehicle (Entry: %u, Spell: %u)",
                GetName().c_str(), GetGUID().ToString().c_str(), vehicle->ToCreature()->GetEntry(), spellId);
            data << uint16(0) << uint8(0) << uint8(i+8);
            continue;
        }

        if (spellInfo->IsPassive())
            vehicle->CastSpell(vehicle, spellId, true);

        data << uint32(MAKE_UNIT_ACTION_BUTTON(spellId, i+8));
    }

    for (uint32 i = CREATURE_MAX_SPELLS; i < MAX_SPELL_CONTROL_BAR; ++i)
        data << uint32(0);

    data << uint8(0); // Auras?

    // Cooldowns
    //vehicle->GetSpellHistory()->WritePacket(&petSpells);
    GetSession()->SendPacket(&data);
}

void Player::CharmSpellInitialize()
{
    Unit* charm = GetFirstControlled();
    if (!charm)
        return;

    CharmInfo* charmInfo = charm->GetCharmInfo();
    if (!charmInfo)
    {
        TC_LOG_ERROR("entities.player", "Player::CharmSpellInitialize(): Player '%s' (%s) has a charm (%s) but no no charminfo!",
            GetName().c_str(), GetGUID().ToString().c_str(), charm->GetGUID().ToString().c_str());
        return;
    }

    uint8 addlist = 0;
    if (charm->GetTypeId() != TYPEID_PLAYER)
    {
        //CreatureInfo const* cinfo = charm->ToCreature()->GetCreatureTemplate();
        //if (cinfo && cinfo->type == CREATURE_TYPE_DEMON && getClass() == CLASS_WARLOCK)
        {
            for (uint32 i = 0; i < MAX_SPELL_CHARM; ++i)
                if (charmInfo->GetCharmSpell(i)->GetAction())
                    ++addlist;
        }
    }

    WorldPacket data(SMSG_PET_SPELLS_MESSAGE, 8 + 2 + 4 + 4 + 4 * MAX_UNIT_ACTION_BAR_INDEX + 1 + 4 * addlist + 1);
    data << charm->GetGUID();
    data << uint16(0);
    data << uint32(0);

    if (charm->GetTypeId() != TYPEID_PLAYER)
        data << uint8(charm->ToCreature()->GetReactState()) << uint8(charmInfo->GetCommandState()) << uint16(0);
    else
        data << uint32(0);

    charmInfo->BuildActionBar(&data);

    data << uint8(addlist);

    if (addlist)
    {
        for (uint32 i = 0; i < MAX_SPELL_CHARM; ++i)
        {
            CharmSpellInfo* cspell = charmInfo->GetCharmSpell(i);
            if (cspell->GetAction())
                data << uint32(cspell->packedData);
        }
    }

    // Cooldowns
    //charm->GetSpellHistory()->WritePacket(&petSpells);

    GetSession()->SendPacket(&data);
}

void Player::SendRemoveControlBar() const
{
    WorldPackets::Pet::PetSpells packet;
    GetSession()->SendPacket(packet.Write());
}

bool Player::IsAffectedBySpellmod(SpellInfo const* spellInfo, SpellModifier* mod, Spell* spell) const
{
    if (!mod || !spellInfo)
        return false;

    // Mod out of charges
    if (spell && mod->charges == -1 && spell->m_appliedMods.find(mod->ownerAura) == spell->m_appliedMods.end())
        return false;

    // +duration to infinite duration spells making them limited
    if (mod->op == SPELLMOD_DURATION && spellInfo->GetDuration() == -1)
        return false;

    return spellInfo->IsAffectedBySpellMod(mod);
}

void Player::AddSpellMod(SpellModifier* mod, bool apply)
{
    TC_LOG_DEBUG("spells", "Player::AddSpellMod: Player '%s' (%s), SpellID: %d", GetName().c_str(), GetGUID().ToString().c_str(), mod->spellId);
    OpcodeServer opcode = (mod->type == SPELLMOD_FLAT) ? SMSG_SET_FLAT_SPELL_MODIFIER : SMSG_SET_PCT_SPELL_MODIFIER;

    WorldPackets::Spells::SetSpellModifier packet(opcode);

    int i = 0;
    flag128 _mask;

    /// @todo Implement sending of bulk modifiers instead of single
    packet.Modifiers.resize(1);
    WorldPackets::Spells::SpellModifier& spellMod = packet.Modifiers[0];

    spellMod.ModIndex = mod->op;

    for (int eff = 0; eff < 128; ++eff)
    {
        if (eff != 0 && (eff % 32) == 0)
            _mask[i++] = 0;

        _mask[i] = uint32(1) << (eff - (32 * i));
        if (mod->mask & _mask)
        {
            WorldPackets::Spells::SpellModifierData modData;

            for (SpellModList::iterator itr = m_spellMods[mod->op].begin(); itr != m_spellMods[mod->op].end(); ++itr)
                if ((*itr)->type == mod->type && (*itr)->mask & _mask)
                    modData.ModifierValue += (*itr)->value;

            modData.ModifierValue += apply ? mod->value : -(mod->value);
            if (mod->type == SPELLMOD_PCT)
                modData.ModifierValue = 1.0f + (modData.ModifierValue * 0.01f);

            modData.ClassIndex = eff;

            spellMod.ModifierData.push_back(modData);
        }
    }

    SendDirectMessage(packet.Write());

    if (apply)
        m_spellMods[mod->op].push_back(mod);
    else
    {
        m_spellMods[mod->op].remove(mod);
        // mods bound to aura will be removed in AuraEffect::~AuraEffect
        if (!mod->ownerAura)
            delete mod;
    }
}

// Restore spellmods in case of failed cast
void Player::RestoreSpellMods(Spell* spell, uint32 ownerAuraId, Aura* aura)
{
    if (!spell || spell->m_appliedMods.empty())
        return;

    std::list<Aura*> aurasQueue;

    for (uint8 i=0; i<MAX_SPELLMOD; ++i)
    {
        for (SpellModList::iterator itr = m_spellMods[i].begin(); itr != m_spellMods[i].end(); ++itr)
        {
            SpellModifier* mod = *itr;

            // Spellmods without aura set cannot be charged
            if (!mod->ownerAura || !mod->ownerAura->IsUsingCharges())
                continue;

            // Restore only specific owner aura mods
            if (ownerAuraId && (ownerAuraId != mod->ownerAura->GetSpellInfo()->Id))
                continue;

            if (aura && mod->ownerAura != aura)
                continue;

            // Check if mod affected this spell
            // First, check if the mod aura applied at least one spellmod to this spell
            Spell::UsedSpellMods::iterator iterMod = spell->m_appliedMods.find(mod->ownerAura);
            if (iterMod == spell->m_appliedMods.end())
                continue;
            // Second, check if the current mod is one of those applied by the mod aura
            if (!(mod->mask & spell->m_spellInfo->SpellFamilyFlags))
                continue;

            // remove from list - This will be done after all mods have been gone through
            // to ensure we iterate over all mods of an aura before removing said aura
            // from applied mods (Else, an aura with two mods on the current spell would
            // only see the first of its modifier restored)
            aurasQueue.push_back(mod->ownerAura);

            // add mod charges back to mod
            if (mod->charges == -1)
                mod->charges = 1;
            else
                mod->charges++;

            // Do not set more spellmods than available
            if (mod->ownerAura->GetCharges() < mod->charges)
                mod->charges = mod->ownerAura->GetCharges();

            // Skip this check for now - aura charges may change due to various reason
            /// @todo track these changes correctly
            //ASSERT (mod->ownerAura->GetCharges() <= mod->charges);
        }
    }

    for (std::list<Aura*>::iterator itr = aurasQueue.begin(); itr != aurasQueue.end(); ++itr)
    {
        Spell::UsedSpellMods::iterator iterMod = spell->m_appliedMods.find(*itr);
        if (iterMod != spell->m_appliedMods.end())
            spell->m_appliedMods.erase(iterMod);
    }
}

void Player::RestoreAllSpellMods(uint32 ownerAuraId, Aura* aura)
{
    for (uint32 i = 0; i < CURRENT_MAX_SPELL; ++i)
        if (m_currentSpells[i])
            RestoreSpellMods(m_currentSpells[i], ownerAuraId, aura);
}

void Player::RemoveSpellMods(Spell* spell)
{
    if (!spell)
        return;

    if (spell->m_appliedMods.empty())
        return;

    for (uint8 i=0; i<MAX_SPELLMOD; ++i)
    {
        for (SpellModList::const_iterator itr = m_spellMods[i].begin(); itr != m_spellMods[i].end();)
        {
            SpellModifier* mod = *itr;
            ++itr;

            // spellmods without aura set cannot be charged
            if (!mod->ownerAura || !mod->ownerAura->IsUsingCharges())
                continue;

            // check if mod affected this spell
            Spell::UsedSpellMods::iterator iterMod = spell->m_appliedMods.find(mod->ownerAura);
            if (iterMod == spell->m_appliedMods.end())
                continue;

            // remove from list
            spell->m_appliedMods.erase(iterMod);

            if (mod->ownerAura->DropCharge(AURA_REMOVE_BY_EXPIRE))
                itr = m_spellMods[i].begin();
        }
    }
}

void Player::DropModCharge(SpellModifier* mod, Spell* spell)
{
    // don't handle spells with proc_event entry defined
    // this is a temporary workaround, because all spellmods should be handled like that
    if (sSpellMgr->GetSpellProcEvent(mod->spellId))
        return;

    if (spell && mod->ownerAura && mod->charges > 0)
    {
        if (--mod->charges == 0)
            mod->charges = -1;

        spell->m_appliedMods.insert(mod->ownerAura);
    }
}

void Player::SetSpellModTakingSpell(Spell* spell, bool apply)
{
    if (!spell || (m_spellModTakingSpell && m_spellModTakingSpell != spell))
        return;

    if (apply && spell->getState() == SPELL_STATE_FINISHED)
        return;

    m_spellModTakingSpell = apply ? spell : NULL;
}

// send Proficiency
void Player::SendProficiency(ItemClass itemClass, uint32 itemSubclassMask) const
{
    WorldPackets::Item::SetProficiency packet;
    packet.ProficiencyMask = itemSubclassMask;
    packet.ProficiencyClass = itemClass;
    SendDirectMessage(packet.Write());
}

void Player::RemovePetitionsAndSigns(ObjectGuid guid)
{
    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_PETITION_SIG_BY_GUID);
    stmt->setUInt64(0, guid.GetCounter());
    PreparedQueryResult result = CharacterDatabase.Query(stmt);

    if (result)
    {
        do                                                  // this part effectively does nothing, since the deletion / modification only takes place _after_ the PetitionQuery. Though I don't know if the result remains intact if I execute the delete query beforehand.
        {                                                   // and SendPetitionQueryOpcode reads data from the DB
            Field* fields = result->Fetch();
            ObjectGuid ownerguid = ObjectGuid::Create<HighGuid::Player>(fields[0].GetUInt64());
            ObjectGuid petitionguid = ObjectGuid::Create<HighGuid::Item>(fields[1].GetUInt64());

            // send update if charter owner in game
            Player* owner = ObjectAccessor::FindConnectedPlayer(ownerguid);
            if (owner)
                owner->GetSession()->SendPetitionQueryOpcode(petitionguid);
        } while (result->NextRow());

        stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_ALL_PETITION_SIGNATURES);

        stmt->setUInt64(0, guid.GetCounter());

        CharacterDatabase.Execute(stmt);
    }

    SQLTransaction trans = CharacterDatabase.BeginTransaction();

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_PETITION_BY_OWNER);
    stmt->setUInt64(0, guid.GetCounter());
    trans->Append(stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_PETITION_SIGNATURE_BY_OWNER);
    stmt->setUInt64(0, guid.GetCounter());
    trans->Append(stmt);

    CharacterDatabase.CommitTransaction(trans);
}

void Player::LeaveAllArenaTeams(ObjectGuid guid)
{
    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_PLAYER_ARENA_TEAMS);
    stmt->setUInt64(0, guid.GetCounter());
    PreparedQueryResult result = CharacterDatabase.Query(stmt);

    if (!result)
        return;

    do
    {
        Field* fields = result->Fetch();
        uint32 arenaTeamId = fields[0].GetUInt32();
        if (arenaTeamId != 0)
        {
            ArenaTeam* arenaTeam = sArenaTeamMgr->GetArenaTeamById(arenaTeamId);
            if (arenaTeam)
                arenaTeam->DelMember(guid, true);
        }
    }
    while (result->NextRow());
}

void Player::SetRestBonus(float rest_bonus_new)
{
    // Prevent resting on max level
    if (getLevel() >= sWorld->getIntConfig(CONFIG_MAX_PLAYER_LEVEL))
        rest_bonus_new = 0;

    if (rest_bonus_new < 0)
        rest_bonus_new = 0;

    float rest_bonus_max = (float)GetUInt32Value(PLAYER_NEXT_LEVEL_XP)*1.5f/2;

    if (rest_bonus_new > rest_bonus_max)
        m_rest_bonus = rest_bonus_max;
    else
        m_rest_bonus = rest_bonus_new;

    // update data for client
    if ((GetsRecruitAFriendBonus(true) && (GetSession()->IsARecruiter() || GetSession()->GetRecruiterId() != 0)))
        SetByteValue(PLAYER_BYTES_2, PLAYER_BYTES_2_OFFSET_REST_STATE, REST_STATE_RAF_LINKED);
    else
    {
        if (m_rest_bonus > 10)
            SetByteValue(PLAYER_BYTES_2, PLAYER_BYTES_2_OFFSET_REST_STATE, REST_STATE_RESTED);
        else if (m_rest_bonus <= 1)
            SetByteValue(PLAYER_BYTES_2, PLAYER_BYTES_2_OFFSET_REST_STATE, REST_STATE_NOT_RAF_LINKED);
    }

    //RestTickUpdate
    SetUInt32Value(PLAYER_REST_STATE_EXPERIENCE, uint32(m_rest_bonus));
}

bool Player::ActivateTaxiPathTo(std::vector<uint32> const& nodes, Creature* npc /*= NULL*/, uint32 spellid /*= 0*/)
{
    if (nodes.size() < 2)
    {
        GetSession()->SendActivateTaxiReply(ERR_TAXINOSUCHPATH);
        return false;
    }

    // not let cheating with start flight in time of logout process || while in combat || has type state: stunned || has type state: root
    if (GetSession()->isLogingOut() || IsInCombat() || HasUnitState(UNIT_STATE_STUNNED) || HasUnitState(UNIT_STATE_ROOT))
    {
        GetSession()->SendActivateTaxiReply(ERR_TAXIPLAYERBUSY);
        return false;
    }

    if (HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE))
        return false;

    // taximaster case
    if (npc)
    {
        // not let cheating with start flight mounted
        if (IsMounted())
        {
            GetSession()->SendActivateTaxiReply(ERR_TAXIPLAYERALREADYMOUNTED);
            return false;
        }

        if (IsInDisallowedMountForm())
        {
            GetSession()->SendActivateTaxiReply(ERR_TAXIPLAYERSHAPESHIFTED);
            return false;
        }

        // not let cheating with start flight in time of logout process || if casting not finished || while in combat || if not use Spell's with EffectSendTaxi
        if (IsNonMeleeSpellCast(false))
        {
            GetSession()->SendActivateTaxiReply(ERR_TAXIPLAYERBUSY);
            return false;
        }
    }
    // cast case or scripted call case
    else
    {
        RemoveAurasByType(SPELL_AURA_MOUNTED);

        if (IsInDisallowedMountForm())
            RemoveAurasByType(SPELL_AURA_MOD_SHAPESHIFT);

        if (Spell* spell = GetCurrentSpell(CURRENT_GENERIC_SPELL))
            if (spell->m_spellInfo->Id != spellid)
                InterruptSpell(CURRENT_GENERIC_SPELL, false);

        InterruptSpell(CURRENT_AUTOREPEAT_SPELL, false);

        if (Spell* spell = GetCurrentSpell(CURRENT_CHANNELED_SPELL))
            if (spell->m_spellInfo->Id != spellid)
                InterruptSpell(CURRENT_CHANNELED_SPELL, true);
    }

    uint32 sourcenode = nodes[0];

    // starting node too far away (cheat?)
    TaxiNodesEntry const* node = sTaxiNodesStore.LookupEntry(sourcenode);
    if (!node)
    {
        GetSession()->SendActivateTaxiReply(ERR_TAXINOSUCHPATH);
        return false;
    }

    // check node starting pos data set case if provided
    if (node->Pos.X != 0.0f || node->Pos.Y != 0.0f || node->Pos.Z != 0.0f)
    {
        if (node->MapID != GetMapId() ||
            (node->Pos.X - GetPositionX())*(node->Pos.X - GetPositionX())+
            (node->Pos.Y - GetPositionY())*(node->Pos.Y - GetPositionY())+
            (node->Pos.Z - GetPositionZ())*(node->Pos.Z - GetPositionZ()) >
            (2*INTERACTION_DISTANCE)*(2*INTERACTION_DISTANCE)*(2*INTERACTION_DISTANCE))
        {
            GetSession()->SendActivateTaxiReply(ERR_TAXITOOFARAWAY);
            return false;
        }
    }
    // node must have pos if taxi master case (npc != NULL)
    else if (npc)
    {
        GetSession()->SendActivateTaxiReply(ERR_TAXIUNSPECIFIEDSERVERERROR);
        return false;
    }
    // Prepare to flight start now

    // stop combat at start taxi flight if any
    CombatStop();

    StopCastingCharm();
    StopCastingBindSight();
    ExitVehicle();

    // stop trade (client cancel trade at taxi map open but cheating tools can be used for reopen it)
    TradeCancel(true);

    // clean not finished taxi path if any
    m_taxi.ClearTaxiDestinations();

    // 0 element current node
    m_taxi.AddTaxiDestination(sourcenode);

    // fill destinations path tail
    uint32 sourcepath = 0;
    uint32 totalcost = 0;
    uint32 firstcost = 0;

    uint32 prevnode = sourcenode;
    uint32 lastnode;

    for (uint32 i = 1; i < nodes.size(); ++i)
    {
        uint32 path, cost;

        lastnode = nodes[i];
        sObjectMgr->GetTaxiPath(prevnode, lastnode, path, cost);

        if (!path)
        {
            m_taxi.ClearTaxiDestinations();
            return false;
        }

        totalcost += cost;
        if (i == 1)
            firstcost = cost;

        if (prevnode == sourcenode)
            sourcepath = path;

        m_taxi.AddTaxiDestination(lastnode);

        prevnode = lastnode;
    }

    // get mount model (in case non taximaster (npc == NULL) allow more wide lookup)
    //
    // Hack-Fix for Alliance not being able to use Acherus taxi. There is
    // only one mount ID for both sides. Probably not good to use 315 in case DBC nodes
    // change but I couldn't find a suitable alternative. OK to use class because only DK
    // can use this taxi.
    uint32 mount_display_id = sObjectMgr->GetTaxiMountDisplayId(sourcenode, GetTeam(), npc == nullptr || (sourcenode == 315 && getClass() == CLASS_DEATH_KNIGHT));

    // in spell case allow 0 model
    if ((mount_display_id == 0 && spellid == 0) || sourcepath == 0)
    {
        GetSession()->SendActivateTaxiReply(ERR_TAXIUNSPECIFIEDSERVERERROR);
        m_taxi.ClearTaxiDestinations();
        return false;
    }

    uint64 money = GetMoney();

    if (npc)
        totalcost = (uint32)ceil(totalcost*GetReputationPriceDiscount(npc));

    if (money < totalcost)
    {
        GetSession()->SendActivateTaxiReply(ERR_TAXINOTENOUGHMONEY);
        m_taxi.ClearTaxiDestinations();
        return false;
    }

    //Checks and preparations done, DO FLIGHT
    UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_FLIGHT_PATHS_TAKEN, 1);

    // prevent stealth flight
    //RemoveAurasWithInterruptFlags(AURA_INTERRUPT_FLAG_TALK);

    if (sWorld->getBoolConfig(CONFIG_INSTANT_TAXI))
    {
        TaxiNodesEntry const* lastPathNode = sTaxiNodesStore.LookupEntry(nodes[nodes.size()-1]);
        ASSERT(lastPathNode);
        m_taxi.ClearTaxiDestinations();
        ModifyMoney(-int64(totalcost));
        UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_GOLD_SPENT_FOR_TRAVELLING, totalcost);
        TeleportTo(lastPathNode->MapID, lastPathNode->Pos.X, lastPathNode->Pos.Y, lastPathNode->Pos.Z, GetOrientation());
        return false;
    }
    else
    {
        ModifyMoney(-int64(firstcost));
        UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_GOLD_SPENT_FOR_TRAVELLING, firstcost);
        GetSession()->SendActivateTaxiReply(ERR_TAXIOK);
        GetSession()->SendDoFlight(mount_display_id, sourcepath);
    }
    return true;
}

bool Player::ActivateTaxiPathTo(uint32 taxi_path_id, uint32 spellid /*= 0*/)
{
    TaxiPathEntry const* entry = sTaxiPathStore.LookupEntry(taxi_path_id);
    if (!entry)
        return false;

    std::vector<uint32> nodes;

    nodes.resize(2);
    nodes[0] = entry->From;
    nodes[1] = entry->To;

    return ActivateTaxiPathTo(nodes, nullptr, spellid);
}

void Player::CleanupAfterTaxiFlight()
{
    m_taxi.ClearTaxiDestinations();        // not destinations, clear source node
    Dismount();
    RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE | UNIT_FLAG_TAXI_FLIGHT);
    getHostileRefManager().setOnlineOfflineState(true);
}

void Player::ContinueTaxiFlight() const
{
    uint32 sourceNode = m_taxi.GetTaxiSource();
    if (!sourceNode)
        return;

    TC_LOG_DEBUG("entities.unit", "Player::ContinueTaxiFlight: Restart %s taxi flight", GetGUID().ToString().c_str());

    uint32 mountDisplayId = sObjectMgr->GetTaxiMountDisplayId(sourceNode, GetTeam(), true);
    if (!mountDisplayId)
        return;

    uint32 path = m_taxi.GetCurrentTaxiPath();

    // search appropriate start path node
    uint32 startNode = 0;

    TaxiPathNodeList const& nodeList = sTaxiPathNodesByPath[path];

    float distPrev;
    float distNext =
        (nodeList[0]->Loc.X - GetPositionX())*(nodeList[0]->Loc.X - GetPositionX()) +
        (nodeList[0]->Loc.Y - GetPositionY())*(nodeList[0]->Loc.Y - GetPositionY()) +
        (nodeList[0]->Loc.Z - GetPositionZ())*(nodeList[0]->Loc.Z - GetPositionZ());

    for (uint32 i = 1; i < nodeList.size(); ++i)
    {
        TaxiPathNodeEntry const* node = nodeList[i];
        TaxiPathNodeEntry const* prevNode = nodeList[i-1];

        // skip nodes at another map
        if (node->MapID != GetMapId())
            continue;

        distPrev = distNext;

        distNext =
            (node->Loc.X - GetPositionX()) * (node->Loc.X - GetPositionX()) +
            (node->Loc.Y - GetPositionY()) * (node->Loc.Y - GetPositionY()) +
            (node->Loc.Z - GetPositionZ()) * (node->Loc.Z - GetPositionZ());

        float distNodes =
            (node->Loc.X - prevNode->Loc.X) * (node->Loc.X - prevNode->Loc.X) +
            (node->Loc.Y - prevNode->Loc.Y) * (node->Loc.Y - prevNode->Loc.Y) +
            (node->Loc.Z - prevNode->Loc.Z) * (node->Loc.Z - prevNode->Loc.Z);

        if (distNext + distPrev < distNodes)
        {
            startNode = i;
            break;
        }
    }

    GetSession()->SendDoFlight(mountDisplayId, path, startNode);
}

void Player::InitDataForForm(bool reapplyMods)
{
    ShapeshiftForm form = GetShapeshiftForm();

    SpellShapeshiftFormEntry const* ssEntry = sSpellShapeshiftFormStore.LookupEntry(form);
    if (ssEntry && ssEntry->CombatRoundTime)
    {
        SetAttackTime(BASE_ATTACK, ssEntry->CombatRoundTime);
        SetAttackTime(OFF_ATTACK, ssEntry->CombatRoundTime);
        SetAttackTime(RANGED_ATTACK, BASE_ATTACK_TIME);
    }
    else
        SetRegularAttackTime();

    switch (form)
    {
        case FORM_GHOUL:
        case FORM_CAT:
        {
            if (getPowerType() != POWER_ENERGY)
                setPowerType(POWER_ENERGY);
            break;
        }
        case FORM_BEAR:
        {
            if (getPowerType() != POWER_RAGE)
                setPowerType(POWER_RAGE);
            break;
        }
        default:                                            // 0, for example
        {
            ChrClassesEntry const* cEntry = sChrClassesStore.LookupEntry(getClass());
            if (cEntry && cEntry->PowerType < MAX_POWERS && uint32(getPowerType()) != cEntry->PowerType)
                setPowerType(Powers(cEntry->PowerType));
            break;
        }
    }

    // update auras at form change, ignore this at mods reapply (.reset stats/etc) when form not change.
    if (!reapplyMods)
        UpdateEquipSpellsAtFormChange();

    UpdateAttackPowerAndDamage();
    UpdateAttackPowerAndDamage(true);
}

void Player::InitDisplayIds()
{
    PlayerInfo const* info = sObjectMgr->GetPlayerInfo(getRace(), getClass());
    if (!info)
    {
        TC_LOG_ERROR("entities.player", "Player::InitDisplayIds: Player '%s' (%s) has incorrect race/class pair. Can't init display ids.", GetName().c_str(), GetGUID().ToString().c_str());
        return;
    }

    uint8 gender = GetByteValue(PLAYER_BYTES_3, PLAYER_BYTES_3_OFFSET_GENDER);
    switch (gender)
    {
        case GENDER_FEMALE:
            SetDisplayId(info->displayId_f);
            SetNativeDisplayId(info->displayId_f);
            break;
        case GENDER_MALE:
            SetDisplayId(info->displayId_m);
            SetNativeDisplayId(info->displayId_m);
            break;
        default:
            TC_LOG_ERROR("entities.player", "Player::InitDisplayIds: Player '%s' (%s) has invalid gender %u", GetName().c_str(), GetGUID().ToString().c_str(), gender);
    }
}

inline bool Player::_StoreOrEquipNewItem(uint32 vendorslot, uint32 item, uint8 count, uint8 bag, uint8 slot, int32 price, ItemTemplate const* pProto, Creature* pVendor, VendorItem const* crItem, bool bStore)
{
    uint32 stacks = count / pProto->GetBuyCount();
    ItemPosCountVec vDest;
    uint16 uiDest = 0;
    InventoryResult msg = bStore ?
        CanStoreNewItem(bag, slot, vDest, item, count) :
        CanEquipNewItem(slot, uiDest, item, false);
    if (msg != EQUIP_ERR_OK)
    {
        SendEquipError(msg, nullptr, nullptr, item);
        return false;
    }

    ModifyMoney(-price);

    if (crItem->ExtendedCost) // case for new honor system
    {
        ItemExtendedCostEntry const* iece = sItemExtendedCostStore.LookupEntry(crItem->ExtendedCost);
        ASSERT(iece);
        for (int i = 0; i < MAX_ITEM_EXT_COST_CURRENCIES; ++i)
        {
            if (iece->RequiredItem[i])
                DestroyItemCount(iece->RequiredItem[i], iece->RequiredItemCount[i] * stacks, true);
        }

        for (int i = 0; i < MAX_ITEM_EXT_COST_CURRENCIES; ++i)
        {
            if (iece->RequirementFlags & (ITEM_EXT_COST_CURRENCY_REQ_IS_SEASON_EARNED_1 << i))
                continue;

            if (iece->RequiredCurrency[i])
                ModifyCurrency(iece->RequiredCurrency[i], -int32(iece->RequiredCurrencyCount[i] * stacks), true, true);
        }
    }

    Item* it = bStore ?
        StoreNewItem(vDest, item, true) :
        EquipNewItem(uiDest, item, true);
    if (it)
    {
        uint32 new_count = pVendor->UpdateVendorItemCurrentCount(crItem, count);

        WorldPackets::Item::BuySucceeded packet;
        packet.VendorGUID = pVendor->GetGUID();
        packet.Muid = vendorslot + 1;
        packet.NewQuantity = crItem->maxcount > 0 ? new_count : 0xFFFFFFFF;
        packet.QuantityBought = count;
        GetSession()->SendPacket(packet.Write());

        SendNewItem(it, count, true, false, false);

        if (!bStore)
            AutoUnequipOffhandIfNeed();

        if (pProto->GetFlags() & ITEM_FLAG_REFUNDABLE && crItem->ExtendedCost && pProto->GetMaxStackSize() == 1)
        {
            it->SetFlag(ITEM_FIELD_FLAGS, ITEM_FIELD_FLAG_REFUNDABLE);
            it->SetRefundRecipient(GetGUID());
            it->SetPaidMoney(price);
            it->SetPaidExtendedCost(crItem->ExtendedCost);
            it->SaveRefundDataToDB();
            AddRefundReference(it->GetGUID());
        }
    }
    return true;
}

bool Player::BuyCurrencyFromVendorSlot(ObjectGuid vendorGuid, uint32 vendorSlot, uint32 currency, uint32 count)
{
    // cheating attempt
    if (count < 1) count = 1;

    if (!IsAlive())
        return false;

    CurrencyTypesEntry const* proto = sCurrencyTypesStore.LookupEntry(currency);
    if (!proto)
    {
        SendBuyError(BUY_ERR_CANT_FIND_ITEM, nullptr, currency, 0);
        return false;
    }

    Creature* creature = GetNPCIfCanInteractWith(vendorGuid, UNIT_NPC_FLAG_VENDOR);
    if (!creature)
    {
        TC_LOG_DEBUG("network", "Player::BuyCurrencyFromVendorSlot: Vendor (%s) not found or player '%s' (%s) can't interact with him.",
            vendorGuid.ToString().c_str(), GetName().c_str(), GetGUID().ToString().c_str());
        SendBuyError(BUY_ERR_DISTANCE_TOO_FAR, nullptr, currency, 0);
        return false;
    }

    VendorItemData const* vItems = creature->GetVendorItems();
    if (!vItems || vItems->Empty())
    {
        SendBuyError(BUY_ERR_CANT_FIND_ITEM, creature, currency, 0);
        return false;
    }

    if (vendorSlot >= vItems->GetItemCount())
    {
        SendBuyError(BUY_ERR_CANT_FIND_ITEM, creature, currency, 0);
        return false;
    }

    VendorItem const* crItem = vItems->GetItem(vendorSlot);
    // store diff item (cheating)
    if (!crItem || crItem->item != currency || crItem->Type != ITEM_VENDOR_TYPE_CURRENCY)
    {
        SendBuyError(BUY_ERR_CANT_FIND_ITEM, creature, currency, 0);
        return false;
    }

    if (count % crItem->maxcount)
    {
        SendEquipError(EQUIP_ERR_CANT_BUY_QUANTITY, nullptr, nullptr);
        return false;
    }

    uint32 stacks = count / crItem->maxcount;
    ItemExtendedCostEntry const* iece;
    if (crItem->ExtendedCost)
    {
        iece = sItemExtendedCostStore.LookupEntry(crItem->ExtendedCost);
        if (!iece)
        {
            TC_LOG_ERROR("entities.player", "Player::BuyCurrencyFromVendorSlot: Currency %u has wrong ExtendedCost field value %u", currency, crItem->ExtendedCost);
            return false;
        }

        for (uint8 i = 0; i < MAX_ITEM_EXT_COST_ITEMS; ++i)
        {
            if (iece->RequiredItem[i] && !HasItemCount(iece->RequiredItem[i], (iece->RequiredItemCount[i] * stacks)))
            {
                SendEquipError(EQUIP_ERR_VENDOR_MISSING_TURNINS, nullptr, nullptr);
                return false;
            }
        }

        for (uint8 i = 0; i < MAX_ITEM_EXT_COST_CURRENCIES; ++i)
        {
            if (!iece->RequiredCurrency[i])
                continue;

            CurrencyTypesEntry const* entry = sCurrencyTypesStore.LookupEntry(iece->RequiredCurrency[i]);
            if (!entry)
            {
                SendBuyError(BUY_ERR_CANT_FIND_ITEM, creature, currency, 0); // Find correct error
                return false;
            }

            if (iece->RequirementFlags & (ITEM_EXT_COST_CURRENCY_REQ_IS_SEASON_EARNED_1 << i))
            {
                // Not implemented
                SendEquipError(EQUIP_ERR_VENDOR_MISSING_TURNINS, nullptr, nullptr); // Find correct error
                return false;
            }
            else if (!HasCurrency(iece->RequiredCurrency[i], (iece->RequiredCurrencyCount[i] * stacks)))
            {
                SendEquipError(EQUIP_ERR_VENDOR_MISSING_TURNINS, nullptr, nullptr); // Find correct error
                return false;
            }
        }

        // check for personal arena rating requirement
        if (GetMaxPersonalArenaRatingRequirement(iece->RequiredArenaSlot) < iece->RequiredPersonalArenaRating)
        {
            // probably not the proper equip err
            SendEquipError(EQUIP_ERR_CANT_EQUIP_RANK, nullptr, nullptr);
            return false;
        }

        if (iece->RequiredFactionId && uint32(GetReputationRank(iece->RequiredFactionId)) < iece->RequiredFactionStanding)
        {
            SendBuyError(BUY_ERR_REPUTATION_REQUIRE, creature, currency, 0);
            return false;
        }

        if (iece->RequirementFlags & ITEM_EXT_COST_FLAG_REQUIRE_GUILD && !GetGuildId())
        {
            SendEquipError(EQUIP_ERR_VENDOR_MISSING_TURNINS, nullptr, nullptr); // Find correct error
            return false;
        }

        if (iece->RequiredAchievement && !HasAchieved(iece->RequiredAchievement))
        {
            SendEquipError(EQUIP_ERR_VENDOR_MISSING_TURNINS, nullptr, nullptr); // Find correct error
            return false;
        }
    }
    else // currencies have no price defined, can only be bought with ExtendedCost
    {
        SendBuyError(BUY_ERR_CANT_FIND_ITEM, nullptr, currency, 0);
        return false;
    }

    ModifyCurrency(currency, count, true, true);
    if (iece)
    {
        for (uint8 i = 0; i < MAX_ITEM_EXT_COST_ITEMS; ++i)
        {
            if (!iece->RequiredItem[i])
                continue;

            DestroyItemCount(iece->RequiredItem[i], iece->RequiredItemCount[i] * stacks, true);
        }

        for (uint8 i = 0; i < MAX_ITEM_EXT_COST_CURRENCIES; ++i)
        {
            if (!iece->RequiredCurrency[i])
                continue;

            if (iece->RequirementFlags & (ITEM_EXT_COST_CURRENCY_REQ_IS_SEASON_EARNED_1 << i))
                continue;

            ModifyCurrency(iece->RequiredCurrency[i], -int32(iece->RequiredCurrencyCount[i]) * stacks, false, true);
        }
    }

    return true;
}

// Return true is the bought item has a max count to force refresh of window by caller
bool Player::BuyItemFromVendorSlot(ObjectGuid vendorguid, uint32 vendorslot, uint32 item, uint8 count, uint8 bag, uint8 slot)
{
    // cheating attempt
    if (count < 1) count = 1;

    // cheating attempt
    if (slot > MAX_BAG_SIZE && slot != NULL_SLOT)
        return false;

    if (!IsAlive())
        return false;

    ItemTemplate const* pProto = sObjectMgr->GetItemTemplate(item);
    if (!pProto)
    {
        SendBuyError(BUY_ERR_CANT_FIND_ITEM, nullptr, item, 0);
        return false;
    }

    if (!(pProto->GetAllowableClass() & getClassMask()) && pProto->GetBonding() == BIND_WHEN_PICKED_UP && !IsGameMaster())
    {
        SendBuyError(BUY_ERR_CANT_FIND_ITEM, nullptr, item, 0);
        return false;
    }

    if (!IsGameMaster() && ((pProto->GetFlags2() & ITEM_FLAG2_HORDE_ONLY && GetTeam() == ALLIANCE) || (pProto->GetFlags2() == ITEM_FLAG2_ALLIANCE_ONLY && GetTeam() == HORDE)))
        return false;

    Creature* creature = GetNPCIfCanInteractWith(vendorguid, UNIT_NPC_FLAG_VENDOR);
    if (!creature)
    {
        TC_LOG_DEBUG("network", "Player::BuyItemFromVendorSlot: Vendor (%s) not found or player '%s' (%s) can't interact with him.",
            vendorguid.ToString().c_str(), GetName().c_str(), GetGUID().ToString().c_str());
        SendBuyError(BUY_ERR_DISTANCE_TOO_FAR, nullptr, item, 0);
        return false;
    }

    if (!sConditionMgr->IsObjectMeetingVendorItemConditions(creature->GetEntry(), item, this, creature))
    {
        TC_LOG_DEBUG("condition", "Player::BuyItemFromVendorSlot: Player '%s' (%s) doesn't meed conditions for creature (Entry: %u, Item: %u)",
            GetName().c_str(), GetGUID().ToString().c_str(), creature->GetEntry(), item);
        SendBuyError(BUY_ERR_CANT_FIND_ITEM, creature, item, 0);
        return false;
    }

    VendorItemData const* vItems = creature->GetVendorItems();
    if (!vItems || vItems->Empty())
    {
        SendBuyError(BUY_ERR_CANT_FIND_ITEM, creature, item, 0);
        return false;
    }

    if (vendorslot >= vItems->GetItemCount())
    {
        SendBuyError(BUY_ERR_CANT_FIND_ITEM, creature, item, 0);
        return false;
    }

    VendorItem const* crItem = vItems->GetItem(vendorslot);
    // store diff item (cheating)
    if (!crItem || crItem->item != item)
    {
        SendBuyError(BUY_ERR_CANT_FIND_ITEM, creature, item, 0);
        return false;
    }

    // check current item amount if it limited
    if (crItem->maxcount != 0)
    {
        if (creature->GetVendorItemCurrentCount(crItem) < pProto->GetBuyCount() * count)
        {
            SendBuyError(BUY_ERR_ITEM_ALREADY_SOLD, creature, item, 0);
            return false;
        }
    }

    if (pProto->GetRequiredReputationFaction() && (uint32(GetReputationRank(pProto->GetRequiredReputationFaction())) < pProto->GetRequiredReputationRank()))
    {
        SendBuyError(BUY_ERR_REPUTATION_REQUIRE, creature, item, 0);
        return false;
    }

    if (crItem->ExtendedCost)
    {
        // Can only buy full stacks for extended cost
        if (count % pProto->GetBuyCount())
        {
            SendEquipError(EQUIP_ERR_CANT_BUY_QUANTITY, nullptr, nullptr);
            return false;
        }

        uint32 stacks = count / pProto->GetBuyCount();
        ItemExtendedCostEntry const* iece = sItemExtendedCostStore.LookupEntry(crItem->ExtendedCost);
        if (!iece)
        {
            TC_LOG_ERROR("entities.player", "Player::BuyItemFromVendorSlot: Item %u has wrong ExtendedCost field value %u", pProto->GetId(), crItem->ExtendedCost);
            return false;
        }

        for (uint8 i = 0; i < MAX_ITEM_EXT_COST_ITEMS; ++i)
        {
            if (iece->RequiredItem[i] && !HasItemCount(iece->RequiredItem[i], iece->RequiredItemCount[i] * stacks))
            {
                SendEquipError(EQUIP_ERR_VENDOR_MISSING_TURNINS, nullptr, nullptr);
                return false;
            }
        }

        for (uint8 i = 0; i < MAX_ITEM_EXT_COST_CURRENCIES; ++i)
        {
            if (!iece->RequiredCurrency[i])
                continue;

            CurrencyTypesEntry const* entry = sCurrencyTypesStore.LookupEntry(iece->RequiredCurrency[i]);
            if (!entry)
            {
                SendBuyError(BUY_ERR_CANT_FIND_ITEM, creature, item, 0);
                return false;
            }

            if (iece->RequirementFlags & (ITEM_EXT_COST_CURRENCY_REQ_IS_SEASON_EARNED_1 << i))
            {
                SendEquipError(EQUIP_ERR_VENDOR_MISSING_TURNINS, nullptr, nullptr); // Find correct error
                return false;
            }
            else if (!HasCurrency(iece->RequiredCurrency[i], iece->RequiredCurrencyCount[i] * stacks))
            {
                SendEquipError(EQUIP_ERR_VENDOR_MISSING_TURNINS, nullptr, nullptr);
                return false;
            }
        }

        // check for personal arena rating requirement
        if (GetMaxPersonalArenaRatingRequirement(iece->RequiredArenaSlot) < iece->RequiredPersonalArenaRating)
        {
            // probably not the proper equip err
            SendEquipError(EQUIP_ERR_CANT_EQUIP_RANK, nullptr, nullptr);
            return false;
        }

        if (iece->RequiredFactionId && uint32(GetReputationRank(iece->RequiredFactionId)) < iece->RequiredFactionStanding)
        {
            SendBuyError(BUY_ERR_REPUTATION_REQUIRE, creature, item, 0);
            return false;
        }

        if (iece->RequirementFlags & ITEM_EXT_COST_FLAG_REQUIRE_GUILD && !GetGuildId())
        {
            SendEquipError(EQUIP_ERR_VENDOR_MISSING_TURNINS, nullptr, nullptr); // Find correct error
            return false;
        }

        if (iece->RequiredAchievement && !HasAchieved(iece->RequiredAchievement))
        {
            SendEquipError(EQUIP_ERR_VENDOR_MISSING_TURNINS, nullptr, nullptr); // Find correct error
            return false;
        }
    }

    uint32 price = 0;
    if (crItem->IsGoldRequired(pProto) && pProto->GetBuyPrice() > 0) //Assume price cannot be negative (do not know why it is int32)
    {
        uint32 maxCount = MAX_MONEY_AMOUNT / pProto->GetBuyPrice();
        if ((uint32)count > maxCount)
        {
            TC_LOG_ERROR("entities.player", "Player::BuyItemFromVendorSlot: Player '%s' (%s) tried to buy item (ItemID: %u, Count: %u), causing overflow",
                GetName().c_str(), GetGUID().ToString().c_str(), pProto->GetId(), (uint32)count);
            count = (uint8)maxCount;
        }
        price = pProto->GetBuyPrice() * count; //it should not exceed MAX_MONEY_AMOUNT

        // reputation discount
        price = uint32(floor(price * GetReputationPriceDiscount(creature)));

        if (int32 priceMod = GetTotalAuraModifier(SPELL_AURA_MOD_VENDOR_ITEMS_PRICES))
            price -= CalculatePct(price, priceMod);

        if (!HasEnoughMoney(uint64(price)))
        {
            SendBuyError(BUY_ERR_NOT_ENOUGHT_MONEY, creature, item, 0);
            return false;
        }
    }

    if ((bag == NULL_BAG && slot == NULL_SLOT) || IsInventoryPos(bag, slot))
    {
        if (!_StoreOrEquipNewItem(vendorslot, item, count, bag, slot, price, pProto, creature, crItem, true))
            return false;
    }
    else if (IsEquipmentPos(bag, slot))
    {
        if (count != 1)
        {
            SendEquipError(EQUIP_ERR_NOT_EQUIPPABLE, nullptr, nullptr);
            return false;
        }
        if (!_StoreOrEquipNewItem(vendorslot, item, count, bag, slot, price, pProto, creature, crItem, false))
            return false;
    }
    else
    {
        SendEquipError(EQUIP_ERR_WRONG_SLOT, nullptr, nullptr);
        return false;
    }

    if (crItem->maxcount != 0) // bought
    {
        if (pProto->GetQuality() > ITEM_QUALITY_EPIC || (pProto->GetQuality() == ITEM_QUALITY_EPIC && pProto->GetBaseItemLevel() >= MinNewsItemLevel))
            if (Guild* guild = GetGuild())
                guild->AddGuildNews(GUILD_NEWS_ITEM_PURCHASED, GetGUID(), 0, item);
        return true;
    }

    return false;
}

uint32 Player::GetMaxPersonalArenaRatingRequirement(uint32 minarenaslot) const
{
    // returns the maximal personal arena rating that can be used to purchase items requiring this condition
    // the personal rating of the arena team must match the required limit as well
    // so return max[in arenateams](min(personalrating[teamtype], teamrating[teamtype]))
    uint32 max_personal_rating = 0;
    for (uint8 i = minarenaslot; i < MAX_ARENA_SLOT; ++i)
    {
        if (ArenaTeam* at = sArenaTeamMgr->GetArenaTeamById(GetArenaTeamId(i)))
        {
            uint32 p_rating = GetArenaPersonalRating(i);
            uint32 t_rating = at->GetRating();
            p_rating = p_rating < t_rating ? p_rating : t_rating;
            if (max_personal_rating < p_rating)
                max_personal_rating = p_rating;
        }
    }
    return max_personal_rating;
}

void Player::UpdateHomebindTime(uint32 time)
{
    // GMs never get homebind timer online
    if (m_InstanceValid || IsGameMaster())
    {
        if (m_HomebindTimer) // instance valid, but timer not reset
            SendRaidGroupOnlyMessage(RAID_GROUP_ERR_NONE, 0);

        // instance is valid, reset homebind timer
        m_HomebindTimer = 0;
    }
    else if (m_HomebindTimer > 0)
    {
        if (time >= m_HomebindTimer)
        {
            // teleport to nearest graveyard
            RepopAtGraveyard();
        }
        else
            m_HomebindTimer -= time;
    }
    else
    {
        // instance is invalid, start homebind timer
        m_HomebindTimer = 60000;
        // send message to player
        SendRaidGroupOnlyMessage(RAID_GROUP_ERR_REQUIREMENTS_UNMATCH, m_HomebindTimer);
        TC_LOG_DEBUG("maps", "Player::UpdateHomebindTime: Player '%s' (%s) will be teleported to homebind in 60 seconds",
            GetName().c_str(), GetGUID().ToString().c_str());
    }
}

void Player::UpdatePvPState(bool onlyFFA)
{
    /// @todo should we always synchronize UNIT_FIELD_BYTES_2, 1 of controller and controlled?
    // no, we shouldn't, those are checked for affecting player by client
    if (!pvpInfo.IsInNoPvPArea && !IsGameMaster()
        && (pvpInfo.IsInFFAPvPArea || sWorld->IsFFAPvPRealm()))
    {
        if (!IsFFAPvP())
        {
            SetByteFlag(UNIT_FIELD_BYTES_2, 1, UNIT_BYTE2_FLAG_FFA_PVP);
            for (ControlList::iterator itr = m_Controlled.begin(); itr != m_Controlled.end(); ++itr)
                (*itr)->SetByteValue(UNIT_FIELD_BYTES_2, 1, UNIT_BYTE2_FLAG_FFA_PVP);
        }
    }
    else if (IsFFAPvP())
    {
        RemoveByteFlag(UNIT_FIELD_BYTES_2, 1, UNIT_BYTE2_FLAG_FFA_PVP);
        for (ControlList::iterator itr = m_Controlled.begin(); itr != m_Controlled.end(); ++itr)
            (*itr)->RemoveByteFlag(UNIT_FIELD_BYTES_2, 1, UNIT_BYTE2_FLAG_FFA_PVP);
    }

    if (onlyFFA)
        return;

    if (pvpInfo.IsHostile)                               // in hostile area
    {
        if (!IsPvP() || pvpInfo.EndTimer)
            UpdatePvP(true, true);
    }
    else                                                    // in friendly area
    {
        if (IsPvP() && !HasFlag(PLAYER_FLAGS, PLAYER_FLAGS_IN_PVP) && !pvpInfo.EndTimer)
            pvpInfo.EndTimer = time(nullptr);                  // start toggle-off
    }
}

void Player::SetPvP(bool state)
{
    Unit::SetPvP(state);
    for (ControlList::iterator itr = m_Controlled.begin(); itr != m_Controlled.end(); ++itr)
        (*itr)->SetPvP(state);
}

void Player::UpdatePvP(bool state, bool _override)
{
    if (!state || _override)
    {
        SetPvP(state);
        pvpInfo.EndTimer = 0;
    }
    else
    {
        pvpInfo.EndTimer = time(nullptr);
        SetPvP(state);
    }
}

void Player::UpdatePotionCooldown(Spell* spell)
{
    // no potion used i combat or still in combat
    if (!m_lastPotionId || IsInCombat())
        return;

    // Call not from spell cast, send cooldown event for item spells if no in combat
    if (!spell)
    {
        // spell/item pair let set proper cooldown (except not existed charged spell cooldown spellmods for potions)
        if (ItemTemplate const* proto = sObjectMgr->GetItemTemplate(m_lastPotionId))
            for (uint8 idx = 0; idx < proto->Effects.size(); ++idx)
                if (proto->Effects[idx]->Trigger == ITEM_SPELLTRIGGER_ON_USE)
                    if (SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(proto->Effects[idx]->SpellID))
                        GetSpellHistory()->SendCooldownEvent(spellInfo, m_lastPotionId);
    }
    // from spell cases (m_lastPotionId set in Spell::SendSpellCooldown)
    else
        GetSpellHistory()->SendCooldownEvent(spell->m_spellInfo, m_lastPotionId, spell);

    m_lastPotionId = 0;
}

void Player::SetResurrectRequestData(Unit* caster, uint32 health, uint32 mana, uint32 appliedAura)
{
    ASSERT(!IsResurrectRequested());
    _resurrectionData.reset(new ResurrectionData());
    _resurrectionData->GUID = caster->GetGUID();
    _resurrectionData->Location.WorldRelocate(*caster);
    _resurrectionData->Health = health;
    _resurrectionData->Mana = mana;
    _resurrectionData->Aura = appliedAura;
}

                                                           //slot to be excluded while counting
bool Player::EnchantmentFitsRequirements(uint32 enchantmentcondition, int8 slot) const
{
    if (!enchantmentcondition)
        return true;

    SpellItemEnchantmentConditionEntry const* Condition = sSpellItemEnchantmentConditionStore.LookupEntry(enchantmentcondition);

    if (!Condition)
        return true;

    uint8 curcount[4] = {0, 0, 0, 0};

    //counting current equipped gem colors
    for (uint8 i = EQUIPMENT_SLOT_START; i < EQUIPMENT_SLOT_END; ++i)
    {
        if (i == slot)
            continue;
        Item* pItem2 = GetItemByPos(INVENTORY_SLOT_BAG_0, i);
        if (pItem2 && !pItem2->IsBroken() && pItem2->GetTemplate()->GetSocketColor(0))
        {
            for (uint32 enchant_slot = SOCK_ENCHANTMENT_SLOT; enchant_slot < SOCK_ENCHANTMENT_SLOT+3; ++enchant_slot)
            {
                uint32 enchant_id = pItem2->GetEnchantmentId(EnchantmentSlot(enchant_slot));
                if (!enchant_id)
                    continue;

                SpellItemEnchantmentEntry const* enchantEntry = sSpellItemEnchantmentStore.LookupEntry(enchant_id);
                if (!enchantEntry)
                    continue;

                uint32 gemid = enchantEntry->SRCItemID;
                if (!gemid)
                    continue;

                ItemTemplate const* gemProto = sObjectMgr->GetItemTemplate(gemid);
                if (!gemProto)
                    continue;

                GemPropertiesEntry const* gemProperty = sGemPropertiesStore.LookupEntry(gemProto->GetGemProperties());
                if (!gemProperty)
                    continue;

                uint8 GemColor = gemProperty->Type;

                for (uint8 b = 0, tmpcolormask = 1; b < 4; b++, tmpcolormask <<= 1)
                {
                    if (tmpcolormask & GemColor)
                        ++curcount[b];
                }
            }
        }
    }

    bool activate = true;

    for (uint8 i = 0; i < 5; i++)
    {
        if (!Condition->LTOperandType[i])
            continue;

        uint32 _cur_gem = curcount[Condition->LTOperandType[i] - 1];

        // if have <CompareColor> use them as count, else use <value> from Condition
        uint32 _cmp_gem = Condition->RTOperandType[i] ? curcount[Condition->RTOperandType[i] - 1]: Condition->RTOperand[i];

        switch (Condition->Operator[i])
        {
            case 2:                                         // requires less <color> than (<value> || <comparecolor>) gems
                activate &= (_cur_gem < _cmp_gem) ? true : false;
                break;
            case 3:                                         // requires more <color> than (<value> || <comparecolor>) gems
                activate &= (_cur_gem > _cmp_gem) ? true : false;
                break;
            case 5:                                         // requires at least <color> than (<value> || <comparecolor>) gems
                activate &= (_cur_gem >= _cmp_gem) ? true : false;
                break;
        }
    }

    TC_LOG_DEBUG("entities.player.items", "Player::EnchantmentFitsRequirements: Checking Condition %u, there are %u Meta Gems, %u Red Gems, %u Yellow Gems and %u Blue Gems, Activate:%s",
        enchantmentcondition, curcount[0], curcount[1], curcount[2], curcount[3], activate ? "yes" : "no");

    return activate;
}

void Player::CorrectMetaGemEnchants(uint8 exceptslot, bool apply)
{
                                                            //cycle all equipped items
    for (uint32 slot = EQUIPMENT_SLOT_START; slot < EQUIPMENT_SLOT_END; ++slot)
    {
        //enchants for the slot being socketed are handled by Player::ApplyItemMods
        if (slot == exceptslot)
            continue;

        Item* pItem = GetItemByPos(INVENTORY_SLOT_BAG_0, slot);

        if (!pItem || !pItem->GetSocketColor(0))
            continue;

        for (uint32 enchant_slot = SOCK_ENCHANTMENT_SLOT; enchant_slot < SOCK_ENCHANTMENT_SLOT+3; ++enchant_slot)
        {
            uint32 enchant_id = pItem->GetEnchantmentId(EnchantmentSlot(enchant_slot));
            if (!enchant_id)
                continue;

            SpellItemEnchantmentEntry const* enchantEntry = sSpellItemEnchantmentStore.LookupEntry(enchant_id);
            if (!enchantEntry)
                continue;

            uint32 condition = enchantEntry->ConditionID;
            if (condition)
            {
                                                            //was enchant active with/without item?
                bool wasactive = EnchantmentFitsRequirements(condition, apply ? exceptslot : -1);
                                                            //should it now be?
                if (wasactive ^ EnchantmentFitsRequirements(condition, apply ? -1 : exceptslot))
                {
                    // ignore item gem conditions
                                                            //if state changed, (dis)apply enchant
                    ApplyEnchantment(pItem, EnchantmentSlot(enchant_slot), !wasactive, true, true);
                }
            }
        }
    }
}

                                                            //if false -> then toggled off if was on| if true -> toggled on if was off AND meets requirements
void Player::ToggleMetaGemsActive(uint8 exceptslot, bool apply)
{
    //cycle all equipped items
    for (int slot = EQUIPMENT_SLOT_START; slot < EQUIPMENT_SLOT_END; ++slot)
    {
        //enchants for the slot being socketed are handled by WorldSession::HandleSocketOpcode(WorldPacket& recvData)
        if (slot == exceptslot)
            continue;

        Item* pItem = GetItemByPos(INVENTORY_SLOT_BAG_0, slot);

        if (!pItem || !pItem->GetSocketColor(0))   //if item has no sockets or no item is equipped go to next item
            continue;

        //cycle all (gem)enchants
        for (uint32 enchant_slot = SOCK_ENCHANTMENT_SLOT; enchant_slot < SOCK_ENCHANTMENT_SLOT+3; ++enchant_slot)
        {
            uint32 enchant_id = pItem->GetEnchantmentId(EnchantmentSlot(enchant_slot));
            if (!enchant_id)                                 //if no enchant go to next enchant(slot)
                continue;

            SpellItemEnchantmentEntry const* enchantEntry = sSpellItemEnchantmentStore.LookupEntry(enchant_id);
            if (!enchantEntry)
                continue;

            //only metagems to be (de)activated, so only enchants with condition
            uint32 condition = enchantEntry->ConditionID;
            if (condition)
                ApplyEnchantment(pItem, EnchantmentSlot(enchant_slot), apply);
        }
    }
}

void Player::SetBattlegroundEntryPoint()
{
    // Taxi path store
    if (!m_taxi.empty())
    {
        m_bgData.mountSpell  = 0;
        m_bgData.taxiPath[0] = m_taxi.GetTaxiSource();
        m_bgData.taxiPath[1] = m_taxi.GetTaxiDestination();

        // On taxi we don't need check for dungeon
        m_bgData.joinPos = WorldLocation(GetMapId(), GetPositionX(), GetPositionY(), GetPositionZ(), GetOrientation());
    }
    else
    {
        m_bgData.ClearTaxiPath();

        // Mount spell id storing
        if (IsMounted())
        {
            AuraEffectList const& auras = GetAuraEffectsByType(SPELL_AURA_MOUNTED);
            if (!auras.empty())
                m_bgData.mountSpell = (*auras.begin())->GetId();
        }
        else
            m_bgData.mountSpell = 0;

        // If map is dungeon find linked graveyard
        if (GetMap()->IsDungeon())
        {
            if (const WorldSafeLocsEntry* entry = sObjectMgr->GetClosestGraveYard(GetPositionX(), GetPositionY(), GetPositionZ(), GetMapId(), GetTeam()))
                m_bgData.joinPos = WorldLocation(entry->MapID, entry->Loc.X, entry->Loc.Y, entry->Loc.Z, 0.0f);
            else
                TC_LOG_ERROR("entities.player", "Player::SetBattlegroundEntryPoint: Dungeon (MapID: %u) has no linked graveyard, setting home location as entry point.", GetMapId());
        }
        // If new entry point is not BG or arena set it
        else if (!GetMap()->IsBattlegroundOrArena())
            m_bgData.joinPos = WorldLocation(GetMapId(), GetPositionX(), GetPositionY(), GetPositionZ(), GetOrientation());
    }

    if (m_bgData.joinPos.m_mapId == MAPID_INVALID) // In error cases use homebind position
        m_bgData.joinPos = WorldLocation(m_homebindMapId, m_homebindX, m_homebindY, m_homebindZ, 0.0f);
}

void Player::SetBGTeam(uint32 team)
{
    m_bgData.bgTeam = team;
    SetByteValue(PLAYER_BYTES_3, PLAYER_BYTES_3_OFFSET_ARENA_FACTION, uint8(team == ALLIANCE ? 1 : 0));
}

uint32 Player::GetBGTeam() const
{
    return m_bgData.bgTeam ? m_bgData.bgTeam : GetTeam();
}

void Player::LeaveBattleground(bool teleportToEntryPoint)
{
    if (Battleground* bg = GetBattleground())
    {
        bg->RemovePlayerAtLeave(GetGUID(), teleportToEntryPoint, true);

        // call after remove to be sure that player resurrected for correct cast
        if (bg->isBattleground() && !IsGameMaster() && sWorld->getBoolConfig(CONFIG_BATTLEGROUND_CAST_DESERTER))
        {
            if (bg->GetStatus() == STATUS_IN_PROGRESS || bg->GetStatus() == STATUS_WAIT_JOIN)
            {
                //lets check if player was teleported from BG and schedule delayed Deserter spell cast
                if (IsBeingTeleportedFar())
                {
                    ScheduleDelayedOperation(DELAYED_SPELL_CAST_DESERTER);
                    return;
                }

                CastSpell(this, 26013, true);               // Deserter
            }
        }
    }
}

bool Player::CanJoinToBattleground(Battleground const* bg) const
{
    // check Deserter debuff
    if (HasAura(26013))
        return false;

    if (bg->isArena() && !GetSession()->HasPermission(rbac::RBAC_PERM_JOIN_ARENAS))
        return false;

    if (bg->IsRandom() && !GetSession()->HasPermission(rbac::RBAC_PERM_JOIN_RANDOM_BG))
        return false;

    if (!GetSession()->HasPermission(rbac::RBAC_PERM_JOIN_NORMAL_BG))
        return false;

    return true;
}

bool Player::CanReportAfkDueToLimit()
{
    // a player can complain about 15 people per 5 minutes
    if (m_bgData.bgAfkReportedCount++ >= 15)
        return false;

    return true;
}

///This player has been blamed to be inactive in a battleground
void Player::ReportedAfkBy(Player* reporter)
{
    WorldPackets::Battleground::ReportPvPPlayerAFKResult reportAfkResult;
    reportAfkResult.Offender = GetGUID();
    Battleground* bg = GetBattleground();
    // Battleground also must be in progress!
    if (!bg || bg != reporter->GetBattleground() || GetTeam() != reporter->GetTeam() || bg->GetStatus() != STATUS_IN_PROGRESS)
    {
        reporter->SendDirectMessage(reportAfkResult.Write());
        return;
    }

    // check if player has 'Idle' or 'Inactive' debuff
    if (m_bgData.bgAfkReporter.find(reporter->GetGUID()) == m_bgData.bgAfkReporter.end() && !HasAura(43680) && !HasAura(43681) && reporter->CanReportAfkDueToLimit())
    {
        m_bgData.bgAfkReporter.insert(reporter->GetGUID());
        // 3 players have to complain to apply debuff
        if (m_bgData.bgAfkReporter.size() >= 3)
        {
            // cast 'Idle' spell
            CastSpell(this, 43680, true);
            m_bgData.bgAfkReporter.clear();
            reportAfkResult.NumBlackMarksOnOffender = m_bgData.bgAfkReporter.size();
            reportAfkResult.NumPlayersIHaveReported = reporter->m_bgData.bgAfkReportedCount;
            reportAfkResult.Result = WorldPackets::Battleground::ReportPvPPlayerAFKResult::PVP_REPORT_AFK_SUCCESS;
        }
    }

    reporter->SendDirectMessage(reportAfkResult.Write());
}

WorldLocation Player::GetStartPosition() const
{
    PlayerInfo const* info = sObjectMgr->GetPlayerInfo(getRace(), getClass());
    uint32 mapId = info->mapId;
    if (getClass() == CLASS_DEATH_KNIGHT && HasSpell(50977))
        mapId = 0;
    return WorldLocation(mapId, info->positionX, info->positionY, info->positionZ, 0);
}

bool Player::HaveAtClient(WorldObject const* u) const
{
    return u == this || m_clientGUIDs.find(u->GetGUID()) != m_clientGUIDs.end();
}

bool Player::IsNeverVisible() const
{
    if (Unit::IsNeverVisible())
        return true;

    if (GetSession()->PlayerLogout() || GetSession()->PlayerLoading())
        return true;

    return false;
}

bool Player::CanAlwaysSee(WorldObject const* obj) const
{
    // Always can see self
    if (m_mover == obj)
        return true;

    ObjectGuid guid = GetGuidValue(PLAYER_FARSIGHT);
    if (!guid.IsEmpty())
        if (obj->GetGUID() == guid)
            return true;

    return false;
}

bool Player::IsAlwaysDetectableFor(WorldObject const* seer) const
{
    if (Unit::IsAlwaysDetectableFor(seer))
        return true;

    if (const Player* seerPlayer = seer->ToPlayer())
        if (IsGroupVisibleFor(seerPlayer))
            return !(seerPlayer->duel && seerPlayer->duel->startTime != 0 && seerPlayer->duel->opponent == this);

    return false;
}

bool Player::IsVisibleGloballyFor(Player const* u) const
{
    if (!u)
        return false;

    // Always can see self
    if (u == this)
        return true;

    // Visible units, always are visible for all players
    if (IsVisible())
        return true;

    // GMs are visible for higher gms (or players are visible for gms)
    if (!AccountMgr::IsPlayerAccount(u->GetSession()->GetSecurity()))
        return GetSession()->GetSecurity() <= u->GetSession()->GetSecurity();

    // non faction visibility non-breakable for non-GMs
    return false;
}

template<class T>
inline void UpdateVisibilityOf_helper(GuidUnorderedSet& s64, T* target, std::set<Unit*>& /*v*/)
{
    s64.insert(target->GetGUID());
}

template<>
inline void UpdateVisibilityOf_helper(GuidUnorderedSet& s64, GameObject* target, std::set<Unit*>& /*v*/)
{
    // @HACK: This is to prevent objects like deeprun tram from disappearing when player moves far from its spawn point while riding it
    // But exclude stoppable elevators from this hack - they would be teleporting from one end to another
    // if affected transports move so far horizontally that it causes them to run out of visibility range then you are out of luck
    // fix visibility instead of adding hacks here
    if (!target->IsDynTransport())
        s64.insert(target->GetGUID());
}

template<>
inline void UpdateVisibilityOf_helper(GuidUnorderedSet& s64, Creature* target, std::set<Unit*>& v)
{
    s64.insert(target->GetGUID());
    v.insert(target);
}

template<>
inline void UpdateVisibilityOf_helper(GuidUnorderedSet& s64, Player* target, std::set<Unit*>& v)
{
    s64.insert(target->GetGUID());
    v.insert(target);
}

template<class T>
inline void BeforeVisibilityDestroy(T* /*t*/, Player* /*p*/) { }

template<>
inline void BeforeVisibilityDestroy<Creature>(Creature* t, Player* p)
{
    if (p->GetPetGUID() == t->GetGUID() && t->IsPet())
        t->ToPet()->Remove(PET_SAVE_NOT_IN_SLOT, true);
}

void Player::UpdateVisibilityOf(WorldObject* target)
{
    if (HaveAtClient(target))
    {
        if (!CanSeeOrDetect(target, false, true))
        {
            if (target->GetTypeId() == TYPEID_UNIT)
                BeforeVisibilityDestroy<Creature>(target->ToCreature(), this);

            target->DestroyForPlayer(this);
            m_clientGUIDs.erase(target->GetGUID());

            #ifdef TRINITY_DEBUG
            TC_LOG_DEBUG("maps", "%s out of range for %s. Distance = %f", target->GetGUID().ToString().c_str(), GetGUID().ToString().c_str(), GetDistance(target));
            #endif
        }
    }
    else
    {
        if (CanSeeOrDetect(target, false, true))
        {
            target->SendUpdateToPlayer(this);
            m_clientGUIDs.insert(target->GetGUID());

            #ifdef TRINITY_DEBUG
            TC_LOG_DEBUG("maps", "%s is visible now for %s. Distance = %f", target->GetGUID().ToString().c_str(), GetGUID().ToString().c_str(), GetDistance(target));
            #endif

            // target aura duration for caster show only if target exist at caster client
            // send data at target visibility change (adding to client)
            if (target->isType(TYPEMASK_UNIT))
                SendInitialVisiblePackets(static_cast<Unit*>(target));
        }
    }
}

void Player::UpdateTriggerVisibility()
{
    if (m_clientGUIDs.empty())
        return;

    if (!IsInWorld())
        return;

    UpdateData udata(GetMapId());
    WorldPacket packet;
    for (auto itr = m_clientGUIDs.begin(); itr != m_clientGUIDs.end(); ++itr)
    {
        if (itr->IsCreatureOrVehicle())
        {
            Creature* creature = GetMap()->GetCreature(*itr);
            // Update fields of triggers, transformed units or unselectable units (values dependent on GM state)
            if (!creature || (!creature->IsTrigger() && !creature->HasAuraType(SPELL_AURA_TRANSFORM) && !creature->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE)))
                continue;

            creature->SetFieldNotifyFlag(UF_FLAG_PUBLIC);
            creature->BuildValuesUpdateBlockForPlayer(&udata, this);
            creature->RemoveFieldNotifyFlag(UF_FLAG_PUBLIC);
        }
        else if (itr->IsGameObject())
        {
            GameObject* go = GetMap()->GetGameObject(*itr);
            if (!go)
                continue;

            go->SetFieldNotifyFlag(UF_FLAG_PUBLIC);
            go->BuildValuesUpdateBlockForPlayer(&udata, this);
            go->RemoveFieldNotifyFlag(UF_FLAG_PUBLIC);
        }
    }

    if (!udata.HasData())
        return;

    udata.BuildPacket(&packet);
    GetSession()->SendPacket(&packet);
}

void Player::SendInitialVisiblePackets(Unit* target) const
{
    SendAurasForTarget(target);
    if (target->IsAlive())
    {
        if (target->HasUnitState(UNIT_STATE_MELEE_ATTACKING) && target->GetVictim())
            target->SendMeleeAttackStart(target->GetVictim());
    }
}

template<class T>
void Player::UpdateVisibilityOf(T* target, UpdateData& data, std::set<Unit*>& visibleNow)
{
    if (HaveAtClient(target))
    {
        if (!CanSeeOrDetect(target, false, true))
        {
            BeforeVisibilityDestroy<T>(target, this);

            target->BuildOutOfRangeUpdateBlock(&data);
            m_clientGUIDs.erase(target->GetGUID());

            #ifdef TRINITY_DEBUG
            TC_LOG_DEBUG("maps", "Object %s (%u) is out of range for %s. Distance = %f", target->GetGUID().ToString().c_str(), target->GetEntry(), GetGUID().ToString().c_str(), GetDistance(target));
            #endif
        }
    }
    else //if (visibleNow.size() < 30 || target->GetTypeId() == TYPEID_UNIT && target->ToCreature()->IsVehicle())
    {
        if (CanSeeOrDetect(target, false, true))
        {
            target->BuildCreateUpdateBlockForPlayer(&data, this);
            UpdateVisibilityOf_helper(m_clientGUIDs, target, visibleNow);

            #ifdef TRINITY_DEBUG
            TC_LOG_DEBUG("maps", "Object %s (%u) is visible now for %s. Distance = %f", target->GetGUID().ToString().c_str(), target->GetEntry(), GetGUID().ToString().c_str(), GetDistance(target));
            #endif
        }
    }
}

template void Player::UpdateVisibilityOf(Player*        target, UpdateData& data, std::set<Unit*>& visibleNow);
template void Player::UpdateVisibilityOf(Creature*      target, UpdateData& data, std::set<Unit*>& visibleNow);
template void Player::UpdateVisibilityOf(Corpse*        target, UpdateData& data, std::set<Unit*>& visibleNow);
template void Player::UpdateVisibilityOf(GameObject*    target, UpdateData& data, std::set<Unit*>& visibleNow);
template void Player::UpdateVisibilityOf(DynamicObject* target, UpdateData& data, std::set<Unit*>& visibleNow);
template void Player::UpdateVisibilityOf(AreaTrigger*   target, UpdateData& data, std::set<Unit*>& visibleNow);

void Player::UpdateObjectVisibility(bool forced)
{
    // Prevent updating visibility if player is not in world (example: LoadFromDB sets drunkstate which updates invisibility while player is not in map)
    if (!IsInWorld())
        return;

    if (!forced)
        AddToNotify(NOTIFY_VISIBILITY_CHANGED);
    else
    {
        Unit::UpdateObjectVisibility(true);
        UpdateVisibilityForPlayer();
    }
}

void Player::UpdateVisibilityForPlayer()
{
    // updates visibility of all objects around point of view for current player
    Trinity::VisibleNotifier notifier(*this);
    m_seer->VisitNearbyObject(GetSightRange(), notifier);
    notifier.SendToSelf();   // send gathered data
}

void Player::InitPrimaryProfessions()
{
    SetFreePrimaryProfessions(sWorld->getIntConfig(CONFIG_MAX_PRIMARY_TRADE_SKILL));
}

bool Player::ModifyMoney(int64 amount, bool sendError /*= true*/)
{
    if (!amount)
        return true;

    sScriptMgr->OnPlayerMoneyChanged(this, amount);

    if (amount < 0)
        SetMoney(GetMoney() > uint64(-amount) ? GetMoney() + amount : 0);
    else
    {
        if (GetMoney() < MAX_MONEY_AMOUNT - static_cast<uint64>(amount))
            SetMoney(GetMoney() + amount);
        else
        {
            sScriptMgr->OnPlayerMoneyLimit(this, amount);

            if (sendError)
                SendEquipError(EQUIP_ERR_TOO_MUCH_GOLD, nullptr, nullptr);
            return false;
        }
    }

    return true;
}

bool Player::HasEnoughMoney(int64 amount) const
{
    if (amount > 0)
        return (GetMoney() >= (uint64) amount);
    return true;
}

void Player::SetMoney(uint64 value)
{
    SetUInt64Value(PLAYER_FIELD_COINAGE, value);
    MoneyChanged(value);
    UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_GOLD_VALUE_OWNED);
}

bool Player::IsQuestRewarded(uint32 quest_id) const
{
    return m_RewardedQuests.find(quest_id) != m_RewardedQuests.end();
}

Unit* Player::GetSelectedUnit() const
{
    ObjectGuid selectionGUID = GetTarget();
    if (!selectionGUID.IsEmpty())
        return ObjectAccessor::GetUnit(*this, selectionGUID);
    return nullptr;
}

Player* Player::GetSelectedPlayer() const
{
    ObjectGuid selectionGUID = GetTarget();
    if (!selectionGUID.IsEmpty())
        return ObjectAccessor::GetPlayer(*this, selectionGUID);
    return nullptr;
}

void Player::AddComboPoints(int8 count, Spell* spell)
{
    if (!count)
        return;

    int8 comboPoints = spell ? spell->m_comboPointGain : GetPower(POWER_COMBO_POINTS);

    // without combo points lost (duration checked in aura)
    RemoveAurasByType(SPELL_AURA_RETAIN_COMBO_POINTS);

    comboPoints += count;

    if (comboPoints > 5)
        comboPoints = 5;
    else if (comboPoints < 0)
        comboPoints = 0;

    if (!spell)
        SetPower(POWER_COMBO_POINTS, comboPoints);
    else
        spell->m_comboPointGain = comboPoints;
}

void Player::GainSpellComboPoints(int8 count)
{
    if (!count)
        return;

    int8 cp = GetPower(POWER_COMBO_POINTS);

    cp += count;
    if (cp > 5) cp = 5;
    else if (cp < 0) cp = 0;

    SetPower(POWER_COMBO_POINTS, cp);
}

void Player::ClearComboPoints()
{
    // without combopoints lost (duration checked in aura)
    RemoveAurasByType(SPELL_AURA_RETAIN_COMBO_POINTS);

    SetPower(POWER_COMBO_POINTS, 0);
}

void Player::SetGroup(Group* group, int8 subgroup)
{
    if (group == nullptr)
        m_group.unlink();
    else
    {
        // never use SetGroup without a subgroup unless you specify NULL for group
        ASSERT(subgroup >= 0);
        m_group.link(group, this);
        m_group.setSubGroup((uint8)subgroup);
    }

    UpdateObjectVisibility(false);
}

void Player::SendInitialPacketsBeforeAddToMap()
{
    /// Pass 'this' as argument because we're not stored in ObjectAccessor yet
    GetSocial()->SendSocialList(this, SOCIAL_FLAG_ALL);

    /// SMSG_BINDPOINTUPDATE
    SendBindPointUpdate();

    // SMSG_SET_PROFICIENCY
    // SMSG_SET_PCT_SPELL_MODIFIER
    // SMSG_SET_FLAT_SPELL_MODIFIER

    /// SMSG_TALENTS_INFO
    SendTalentsInfoData();
    /// SMSG_INITIAL_SPELLS
    SendKnownSpells();

    /// SMSG_SEND_UNLEARN_SPELLS
    SendDirectMessage(WorldPackets::Spells::SendUnlearnSpells().Write());

    /// SMSG_SEND_SPELL_HISTORY
    WorldPackets::Spells::SendSpellHistory sendSpellHistory;
    GetSpellHistory()->WritePacket(&sendSpellHistory);
    SendDirectMessage(sendSpellHistory.Write());

    /// SMSG_SEND_SPELL_CHARGES
    WorldPackets::Spells::SendSpellCharges sendSpellCharges;
    GetSpellHistory()->WritePacket(&sendSpellCharges);
    SendDirectMessage(sendSpellCharges.Write());

    /// SMSG_ACTION_BUTTONS
    SendInitialActionButtons();

    /// SMSG_INITIALIZE_FACTIONS
    m_reputationMgr->SendInitialReputations();
    /// SMSG_SETUP_CURRENCY
    SendCurrencies();
    /// SMSG_EQUIPMENT_SET_LIST
    SendEquipmentSetList();

    m_achievementMgr->SendAllAchievementData(this);

    /// SMSG_LOGIN_SETTIMESPEED
    static float const TimeSpeed = 0.01666667f;
    WorldPackets::Misc::LoginSetTimeSpeed loginSetTimeSpeed;
    loginSetTimeSpeed.NewSpeed = TimeSpeed;
    loginSetTimeSpeed.GameTime = sWorld->GetGameTime();
    loginSetTimeSpeed.ServerTime = sWorld->GetGameTime();
    loginSetTimeSpeed.GameTimeHolidayOffset = 0; /// @todo
    loginSetTimeSpeed.ServerTimeHolidayOffset = 0; /// @todo
    SendDirectMessage(loginSetTimeSpeed.Write());

    /// SMSG_WORLD_SERVER_INFO
    WorldPackets::Misc::WorldServerInfo worldServerInfo;
    // worldServerInfo.IneligibleForLootMask; /// @todo
    worldServerInfo.WeeklyReset = sWorld->GetNextWeeklyQuestsResetTime() - WEEK;
    worldServerInfo.InstanceGroupSize = GetMap()->GetMapDifficulty()->MaxPlayers;
    worldServerInfo.IsTournamentRealm = 0; /// @todo
    // worldServerInfo.RestrictedAccountMaxLevel; /// @todo
    // worldServerInfo.RestrictedAccountMaxMoney; /// @todo
    worldServerInfo.DifficultyID = GetMap()->GetDifficultyID();
    // worldServerInfo.XRealmPvpAlert;  /// @todo
    SendDirectMessage(worldServerInfo.Write());

    // SMSG_ACCOUNT_MOUNT_UPDATE
    // SMSG_ACCOUNT_TOYS_UPDATE
    WorldPackets::Toy::AccountToysUpdate toysUpdate;
    toysUpdate.IsFullUpdate = true;
    toysUpdate.Toys = &GetSession()->GetCollectionMgr()->GetAccountToys();
    SendDirectMessage(toysUpdate.Write());

    // SMSG_ACCOUNT_HEIRLOOM_UPDATE
    WorldPackets::Misc::AccountHeirloomUpdate heirloomUpdate;
    heirloomUpdate.IsFullUpdate = true;
    heirloomUpdate.Heirlooms = &GetSession()->GetCollectionMgr()->GetAccountHeirlooms();
    SendDirectMessage(heirloomUpdate.Write());

    WorldPackets::Character::InitialSetup initialSetup;
    initialSetup.ServerExpansionLevel = sWorld->getIntConfig(CONFIG_EXPANSION);
    SendDirectMessage(initialSetup.Write());

    SetMover(this);
}

void Player::SendInitialPacketsAfterAddToMap()
{
    UpdateVisibilityForPlayer();

    // update zone
    uint32 newzone, newarea;
    GetZoneAndAreaId(newzone, newarea);
    UpdateZone(newzone, newarea);                            // also call SendInitWorldStates();

    ResetTimeSync();
    SendTimeSync();

    GetSession()->SendLoadCUFProfiles();

    CastSpell(this, 836, true);                             // LOGINEFFECT

    // set some aura effects that send packet to player client after add player to map
    // SendMessageToSet not send it to player not it map, only for aura that not changed anything at re-apply
    // same auras state lost at far teleport, send it one more time in this case also
    static const AuraType auratypes[] =
    {
        SPELL_AURA_MOD_FEAR,     SPELL_AURA_TRANSFORM,                 SPELL_AURA_WATER_WALK,
        SPELL_AURA_FEATHER_FALL, SPELL_AURA_HOVER,                     SPELL_AURA_SAFE_FALL,
        SPELL_AURA_FLY,          SPELL_AURA_MOD_INCREASE_MOUNTED_FLIGHT_SPEED, SPELL_AURA_NONE
    };
    for (AuraType const* itr = &auratypes[0]; itr && itr[0] != SPELL_AURA_NONE; ++itr)
    {
        Unit::AuraEffectList const& auraList = GetAuraEffectsByType(*itr);
        if (!auraList.empty())
            auraList.front()->HandleEffect(this, AURA_EFFECT_HANDLE_SEND_FOR_CLIENT, true);
    }

    if (HasAuraType(SPELL_AURA_MOD_STUN))
        SetRooted(true);

    // manual send package (have code in HandleEffect(this, AURA_EFFECT_HANDLE_SEND_FOR_CLIENT, true); that must not be re-applied.
    if (HasAuraType(SPELL_AURA_MOD_ROOT))
        SetRooted(true, true);

    SendAurasForTarget(this);
    SendEnchantmentDurations();                             // must be after add to map
    SendItemDurations();                                    // must be after add to map

    if (GetMap()->IsRaid())
    {
        m_prevMapDifficulty = GetMap()->GetDifficultyID();
        DifficultyEntry const* difficulty = sDifficultyStore.AssertEntry(m_prevMapDifficulty);
        SendRaidDifficulty((difficulty->Flags & DIFFICULTY_FLAG_LEGACY) != 0, m_prevMapDifficulty);
    }
    else if (GetMap()->IsNonRaidDungeon())
    {
        m_prevMapDifficulty = GetMap()->GetDifficultyID();
        SendDungeonDifficulty(m_prevMapDifficulty);
    }
    else if (!GetMap()->Instanceable())
    {
        DifficultyEntry const* difficulty = sDifficultyStore.AssertEntry(m_prevMapDifficulty);
        SendRaidDifficulty((difficulty->Flags & DIFFICULTY_FLAG_LEGACY) != 0);
    }

    if (_garrison)
        _garrison->SendRemoteInfo();
}

void Player::SendUpdateToOutOfRangeGroupMembers()
{
    if (m_groupUpdateMask == GROUP_UPDATE_FLAG_NONE)
        return;
    if (Group* group = GetGroup())
        group->UpdatePlayerOutOfRange(this);

    m_groupUpdateMask = GROUP_UPDATE_FLAG_NONE;
    if (Pet* pet = GetPet())
        pet->ResetGroupUpdateFlag();
}

void Player::SendTransferAborted(uint32 mapid, TransferAbortReason reason, uint8 arg) const
{
    WorldPackets::Movement::TransferAborted transferAborted;
    transferAborted.MapID = mapid;
    transferAborted.Arg = arg;
    transferAborted.TransfertAbort = reason;
    GetSession()->SendPacket(transferAborted.Write());
}

void Player::SendInstanceResetWarning(uint32 mapid, Difficulty difficulty, uint32 time, bool welcome) const
{
    // type of warning, based on the time remaining until reset
    uint32 type;
    if (welcome)
        type = RAID_INSTANCE_WELCOME;
    else if (time > 21600)
        type = RAID_INSTANCE_WELCOME;
    else if (time > 3600)
        type = RAID_INSTANCE_WARNING_HOURS;
    else if (time > 300)
        type = RAID_INSTANCE_WARNING_MIN;
    else
        type = RAID_INSTANCE_WARNING_MIN_SOON;

    WorldPackets::Instance::RaidInstanceMessage raidInstanceMessage;
    raidInstanceMessage.Type = type;
    raidInstanceMessage.MapID = mapid;
    raidInstanceMessage.DifficultyID = difficulty;
    raidInstanceMessage.TimeLeft = int32(time);
    if (InstancePlayerBind const* bind = GetBoundInstance(mapid, difficulty))
        raidInstanceMessage.Locked = bind->perm;
    else
        raidInstanceMessage.Locked = false;
    raidInstanceMessage.Extended = false;
    GetSession()->SendPacket(raidInstanceMessage.Write());
}

void Player::ApplyEquipCooldown(Item* pItem)
{
    if (pItem->HasFlag(ITEM_FIELD_FLAGS, ITEM_FLAG_NO_EQUIP_COOLDOWN))
        return;

    ItemTemplate const* proto = pItem->GetTemplate();

    for (uint8 i = 0; i < proto->Effects.size(); ++i)
    {
        ItemEffectEntry const* effectData = proto->Effects[i];

        // wrong triggering type (note: ITEM_SPELLTRIGGER_ON_NO_DELAY_USE not have cooldown)
        if (effectData->Trigger != ITEM_SPELLTRIGGER_ON_USE)
            continue;

        // Don't replace longer cooldowns by equip cooldown if we have any.
        if (GetSpellHistory()->GetRemainingCooldown(sSpellMgr->AssertSpellInfo(effectData->SpellID)) > 30 * IN_MILLISECONDS)
            continue;

        GetSpellHistory()->AddCooldown(effectData->SpellID, pItem->GetEntry(), std::chrono::seconds(30));

        WorldPackets::Item::ItemCooldown data;
        data.ItemGuid = pItem->GetGUID();
        data.SpellID = effectData->SpellID;
        data.Cooldown = 30 * IN_MILLISECONDS; // Always 30secs?
        GetSession()->SendPacket(data.Write());
    }
}

void Player::ResetSpells(bool myClassOnly)
{
    // not need after this call
    if (HasAtLoginFlag(AT_LOGIN_RESET_SPELLS))
        RemoveAtLoginFlag(AT_LOGIN_RESET_SPELLS, true);

    // make full copy of map (spells removed and marked as deleted at another spell remove
    // and we can't use original map for safe iterative with visit each spell at loop end
    PlayerSpellMap smap = GetSpellMap();

    uint32 family;

    if (myClassOnly)
    {
        ChrClassesEntry const* clsEntry = sChrClassesStore.LookupEntry(getClass());
        if (!clsEntry)
            return;
        family = clsEntry->SpellClassSet;

        for (PlayerSpellMap::const_iterator iter = smap.begin(); iter != smap.end(); ++iter)
        {
            SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(iter->first);
            if (!spellInfo)
                continue;

            // skip server-side/triggered spells
            if (spellInfo->SpellLevel == 0)
                continue;

            // skip wrong class/race skills
            if (!IsSpellFitByClassAndRace(spellInfo->Id))
                continue;

            // skip other spell families
            if (spellInfo->SpellFamilyName != family)
                continue;

            // skip broken spells
            if (!SpellMgr::IsSpellValid(spellInfo, this, false))
                continue;
        }
    }
    else
        for (PlayerSpellMap::const_iterator iter = smap.begin(); iter != smap.end(); ++iter)
            RemoveSpell(iter->first, false, false);           // only iter->first can be accessed, object by iter->second can be deleted already

    LearnDefaultSkills();
    LearnCustomSpells();
    LearnQuestRewardedSpells();
}

void Player::LearnCustomSpells()
{
    if (!sWorld->getBoolConfig(CONFIG_START_ALL_SPELLS))
        return;

    // learn default race/class spells
    PlayerInfo const* info = sObjectMgr->GetPlayerInfo(getRace(), getClass());
    for (PlayerCreateInfoSpells::const_iterator itr = info->customSpells.begin(); itr != info->customSpells.end(); ++itr)
    {
        uint32 tspell = *itr;
        TC_LOG_DEBUG("entities.player.loading", "Player::LearnCustomSpells: Player '%s' (%s, Class: %u Race: %u): Adding initial spell (SpellID: %u)",
            GetName().c_str(), GetGUID().ToString().c_str(), uint32(getClass()), uint32(getRace()), tspell);
        if (!IsInWorld())                                    // will send in INITIAL_SPELLS in list anyway at map add
            AddSpell(tspell, true, true, true, false);
        else                                                // but send in normal spell in game learn case
            LearnSpell(tspell, true);
    }
}

void Player::LearnDefaultSkills()
{
    // learn default race/class skills
    PlayerInfo const* info = sObjectMgr->GetPlayerInfo(getRace(), getClass());
    for (PlayerCreateInfoSkills::const_iterator itr = info->skills.begin(); itr != info->skills.end(); ++itr)
    {
        SkillRaceClassInfoEntry const* rcInfo = *itr;
        if (HasSkill(rcInfo->SkillID))
            continue;

        if (rcInfo->MinLevel > getLevel())
            continue;

        LearnDefaultSkill(rcInfo);
    }
}

void Player::LearnDefaultSkill(SkillRaceClassInfoEntry const* rcInfo)
{
    uint16 skillId = rcInfo->SkillID;
    switch (GetSkillRangeType(rcInfo))
    {
        case SKILL_RANGE_LANGUAGE:
            SetSkill(skillId, 0, 300, 300);
            break;
        case SKILL_RANGE_LEVEL:
        {
            uint16 skillValue = 1;
            uint16 maxValue = GetMaxSkillValueForLevel();
            if (rcInfo->Flags & SKILL_FLAG_ALWAYS_MAX_VALUE)
                skillValue = maxValue;
            else if (getClass() == CLASS_DEATH_KNIGHT)
                skillValue = std::min(std::max<uint16>({ 1, uint16((getLevel() - 1) * 5) }), maxValue);
            else if (skillId == SKILL_FIST_WEAPONS)
                skillValue = std::max<uint16>(1, GetSkillValue(SKILL_UNARMED));
            else if (skillId == SKILL_LOCKPICKING)
                skillValue = std::max<uint16>(1, GetSkillValue(SKILL_LOCKPICKING));

            SetSkill(skillId, 0, skillValue, maxValue);
            break;
        }
        case SKILL_RANGE_MONO:
            SetSkill(skillId, 0, 1, 1);
            break;
        case SKILL_RANGE_RANK:
        {
            uint16 rank = 1;
            if (getClass() == CLASS_DEATH_KNIGHT && skillId == SKILL_FIRST_AID)
                rank = 4;

            SkillTiersEntry const* tier = sObjectMgr->GetSkillTier(rcInfo->SkillTierID);
            uint16 maxValue = tier->Value[std::max<int32>(rank - 1, 0)];
            uint16 skillValue = 1;
            if (rcInfo->Flags & SKILL_FLAG_ALWAYS_MAX_VALUE)
                skillValue = maxValue;
            else if (getClass() == CLASS_DEATH_KNIGHT)
                skillValue = std::min(std::max(uint16(1), uint16((getLevel() - 1) * 5)), maxValue);

            SetSkill(skillId, rank, skillValue, maxValue);
            break;
        }
        default:
            break;
    }
}

void Player::LearnQuestRewardedSpells(Quest const* quest)
{
    int32 spell_id = quest->GetRewSpell();
    uint32 src_spell_id = quest->GetSrcSpell();

    // skip quests without rewarded spell
    if (!spell_id)
        return;

    // if RewSpellCast = -1 we remove aura do to SrcSpell from player.
    if (spell_id == -1 && src_spell_id)
    {
        RemoveAurasDueToSpell(src_spell_id);
        return;
    }

    SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(spell_id);
    if (!spellInfo)
        return;

    // check learned spells state
    bool found = false;
    for (SpellEffectInfo const* effect : spellInfo->GetEffectsForDifficulty(DIFFICULTY_NONE))
    {
        if (effect && effect->Effect == SPELL_EFFECT_LEARN_SPELL && !HasSpell(effect->TriggerSpell))
        {
            found = true;
            break;
        }
    }

    // skip quests with not teaching spell or already known spell
    if (!found)
        return;

    SpellEffectInfo const* effect = spellInfo->GetEffect(DIFFICULTY_NONE, EFFECT_0);
    if (!effect)
        return;

    uint32 learned_0 = effect->TriggerSpell;
    if (!HasSpell(learned_0))
    {
        SpellInfo const* learnedInfo = sSpellMgr->GetSpellInfo(learned_0);
        if (!learnedInfo)
            return;

        // profession specialization can be re-learned from npc
        if (learnedInfo->GetEffect(EFFECT_0)->Effect == SPELL_EFFECT_TRADE_SKILL && learnedInfo->GetEffect(EFFECT_1)->Effect == 0 && !learnedInfo->SpellLevel)
            return;
    }

    CastSpell(this, spell_id, true);
}

void Player::LearnQuestRewardedSpells()
{
    // learn spells received from quest completing
    for (RewardedQuestSet::const_iterator itr = m_RewardedQuests.begin(); itr != m_RewardedQuests.end(); ++itr)
    {
        Quest const* quest = sObjectMgr->GetQuestTemplate(*itr);
        if (!quest)
            continue;

        LearnQuestRewardedSpells(quest);
    }
}

void Player::LearnSkillRewardedSpells(uint32 skillId, uint32 skillValue)
{
    uint32 raceMask  = getRaceMask();
    uint32 classMask = getClassMask();
    for (uint32 j = 0; j < sSkillLineAbilityStore.GetNumRows(); ++j)
    {
        SkillLineAbilityEntry const* ability = sSkillLineAbilityStore.LookupEntry(j);
        if (!ability || ability->SkillLine != skillId)
            continue;

        SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(ability->SpellID);
        if (!spellInfo)
            continue;

        if (ability->AquireMethod != SKILL_LINE_ABILITY_LEARNED_ON_SKILL_VALUE && ability->AquireMethod != SKILL_LINE_ABILITY_LEARNED_ON_SKILL_LEARN)
            continue;

        // Check race if set
        if (ability->RaceMask && !(ability->RaceMask & raceMask))
            continue;

        // Check class if set
        if (ability->ClassMask && !(ability->ClassMask & classMask))
            continue;

        // check level, skip class spells if not high enough
        if (getLevel() < spellInfo->SpellLevel)
            continue;

        // need unlearn spell
        if (skillValue < ability->MinSkillLineRank && ability->AquireMethod == SKILL_LINE_ABILITY_LEARNED_ON_SKILL_VALUE)
            RemoveSpell(ability->SpellID);
        // need learn
        else if (!IsInWorld())
            AddSpell(ability->SpellID, true, true, true, false, false, ability->SkillLine);
        else
            LearnSpell(ability->SpellID, true, ability->SkillLine);
    }
}

void Player::SendAurasForTarget(Unit* target) const
{
    if (!target || target->GetVisibleAuras()->empty())                  // speedup things
        return;

    /*! Blizz sends certain movement packets sometimes even before CreateObject
        These movement packets are usually found in SMSG_COMPRESSED_MOVES
    */
    if (target->HasAuraType(SPELL_AURA_FEATHER_FALL))
        target->SetFeatherFall(true, true);

    if (target->HasAuraType(SPELL_AURA_WATER_WALK))
        target->SetWaterWalking(true, true);

    if (target->HasAuraType(SPELL_AURA_HOVER))
        target->SetHover(true, true);

    Unit::VisibleAuraMap const* visibleAuras = target->GetVisibleAuras();

    WorldPackets::Spells::AuraUpdate update;
    update.UpdateAll = true;
    update.UnitGUID = target->GetGUID();
    update.Auras.reserve(visibleAuras->size());

    for (Unit::VisibleAuraMap::const_iterator itr = visibleAuras->begin(); itr != visibleAuras->end(); ++itr)
    {
        AuraApplication* auraApp = itr->second;
        WorldPackets::Spells::AuraInfo auraInfo;
        auraApp->BuildUpdatePacket(auraInfo, false);
        update.Auras.push_back(auraInfo);
    }

    GetSession()->SendPacket(update.Write());
}

void Player::SetDailyQuestStatus(uint32 quest_id)
{
    if (Quest const* qQuest = sObjectMgr->GetQuestTemplate(quest_id))
    {
        if (!qQuest->IsDFQuest())
        {
            AddDynamicValue(PLAYER_DYNAMIC_FIELD_DAILY_QUESTS, quest_id);
            m_lastDailyQuestTime = time(nullptr);              // last daily quest time
            m_DailyQuestChanged = true;
        }
        else
        {
            m_DFQuests.insert(quest_id);
            m_lastDailyQuestTime = time(nullptr);
            m_DailyQuestChanged = true;
        }
    }
}

void Player::SetWeeklyQuestStatus(uint32 quest_id)
{
    m_weeklyquests.insert(quest_id);
    m_WeeklyQuestChanged = true;
}

void Player::SetSeasonalQuestStatus(uint32 quest_id)
{
    Quest const* quest = sObjectMgr->GetQuestTemplate(quest_id);
    if (!quest)
        return;

    m_seasonalquests[sGameEventMgr->GetEventIdForQuest(quest)].insert(quest_id);
    m_SeasonalQuestChanged = true;
}

void Player::SetMonthlyQuestStatus(uint32 quest_id)
{
    m_monthlyquests.insert(quest_id);
    m_MonthlyQuestChanged = true;
}

void Player::DailyReset()
{
    for (uint32 questId : GetDynamicValues(PLAYER_DYNAMIC_FIELD_DAILY_QUESTS))
        if (uint32 questBit = sDB2Manager.GetQuestUniqueBitFlag(questId))
            SetQuestCompletedBit(questBit, false);

    WorldPackets::Quest::DailyQuestsReset dailyQuestsReset;
    dailyQuestsReset.Count = int32(GetDynamicValues(PLAYER_DYNAMIC_FIELD_DAILY_QUESTS).size());
    SendDirectMessage(dailyQuestsReset.Write());

    ClearDynamicValue(PLAYER_DYNAMIC_FIELD_DAILY_QUESTS);

    m_DFQuests.clear(); // Dungeon Finder Quests.

    // DB data deleted in caller
    m_DailyQuestChanged = false;
    m_lastDailyQuestTime = 0;

    if (_garrison)
        _garrison->ResetFollowerActivationLimit();
}

void Player::ResetWeeklyQuestStatus()
{
    if (m_weeklyquests.empty())
        return;

    for (uint32 questId : m_weeklyquests)
        if (uint32 questBit = sDB2Manager.GetQuestUniqueBitFlag(questId))
            SetQuestCompletedBit(questBit, false);

    m_weeklyquests.clear();
    // DB data deleted in caller
    m_WeeklyQuestChanged = false;
}

void Player::ResetSeasonalQuestStatus(uint16 event_id)
{
    auto eventItr = m_seasonalquests.find(event_id);
    if (eventItr == m_seasonalquests.end())
        return;

    if (eventItr->second.empty())
        return;

    for (uint32 questId : eventItr->second)
        if (uint32 questBit = sDB2Manager.GetQuestUniqueBitFlag(questId))
            SetQuestCompletedBit(questBit, false);

    m_seasonalquests.erase(eventItr);
    // DB data deleted in caller
    m_SeasonalQuestChanged = false;
}

void Player::ResetMonthlyQuestStatus()
{
    if (m_monthlyquests.empty())
        return;

    for (uint32 questId : m_monthlyquests)
        if (uint32 questBit = sDB2Manager.GetQuestUniqueBitFlag(questId))
            SetQuestCompletedBit(questBit, false);

    m_monthlyquests.clear();
    // DB data deleted in caller
    m_MonthlyQuestChanged = false;
}

Battleground* Player::GetBattleground() const
{
    if (GetBattlegroundId() == 0)
        return nullptr;

    return sBattlegroundMgr->GetBattleground(GetBattlegroundId(), m_bgData.bgTypeID);
}

uint32 Player::GetBattlegroundQueueJoinTime(BattlegroundQueueTypeId bgQueueTypeId) const
{
    for (uint8 i = 0; i < PLAYER_MAX_BATTLEGROUND_QUEUES; ++i)
        if (m_bgBattlegroundQueueID[i].bgQueueTypeId == bgQueueTypeId)
            return m_bgBattlegroundQueueID[i].joinTime;
    return 0;
}

bool Player::InBattlegroundQueue() const
{
    for (uint8 i = 0; i < PLAYER_MAX_BATTLEGROUND_QUEUES; ++i)
        if (m_bgBattlegroundQueueID[i].bgQueueTypeId != BATTLEGROUND_QUEUE_NONE)
            return true;
    return false;
}

BattlegroundQueueTypeId Player::GetBattlegroundQueueTypeId(uint32 index) const
{
    if (index < PLAYER_MAX_BATTLEGROUND_QUEUES)
        return m_bgBattlegroundQueueID[index].bgQueueTypeId;

    return BATTLEGROUND_QUEUE_NONE;
}

uint32 Player::GetBattlegroundQueueIndex(BattlegroundQueueTypeId bgQueueTypeId) const
{
    for (uint8 i = 0; i < PLAYER_MAX_BATTLEGROUND_QUEUES; ++i)
        if (m_bgBattlegroundQueueID[i].bgQueueTypeId == bgQueueTypeId)
            return i;
    return PLAYER_MAX_BATTLEGROUND_QUEUES;
}

bool Player::IsInvitedForBattlegroundQueueType(BattlegroundQueueTypeId bgQueueTypeId) const
{
    for (uint8 i = 0; i < PLAYER_MAX_BATTLEGROUND_QUEUES; ++i)
        if (m_bgBattlegroundQueueID[i].bgQueueTypeId == bgQueueTypeId)
            return m_bgBattlegroundQueueID[i].invitedToInstance != 0;
    return false;
}

bool Player::InBattlegroundQueueForBattlegroundQueueType(BattlegroundQueueTypeId bgQueueTypeId) const
{
    return GetBattlegroundQueueIndex(bgQueueTypeId) < PLAYER_MAX_BATTLEGROUND_QUEUES;
}

void Player::SetBattlegroundId(uint32 val, BattlegroundTypeId bgTypeId)
{
    m_bgData.bgInstanceID = val;
    m_bgData.bgTypeID = bgTypeId;
}

uint32 Player::AddBattlegroundQueueId(BattlegroundQueueTypeId val)
{
    for (uint8 i=0; i < PLAYER_MAX_BATTLEGROUND_QUEUES; ++i)
    {
        if (m_bgBattlegroundQueueID[i].bgQueueTypeId == BATTLEGROUND_QUEUE_NONE || m_bgBattlegroundQueueID[i].bgQueueTypeId == val)
        {
            m_bgBattlegroundQueueID[i].bgQueueTypeId = val;
            m_bgBattlegroundQueueID[i].invitedToInstance = 0;
            m_bgBattlegroundQueueID[i].joinTime = getMSTime();
            return i;
        }
    }
    return PLAYER_MAX_BATTLEGROUND_QUEUES;
}

bool Player::HasFreeBattlegroundQueueId() const
{
    for (uint8 i=0; i < PLAYER_MAX_BATTLEGROUND_QUEUES; ++i)
        if (m_bgBattlegroundQueueID[i].bgQueueTypeId == BATTLEGROUND_QUEUE_NONE)
            return true;
    return false;
}

void Player::RemoveBattlegroundQueueId(BattlegroundQueueTypeId val)
{
    for (uint8 i=0; i < PLAYER_MAX_BATTLEGROUND_QUEUES; ++i)
    {
        if (m_bgBattlegroundQueueID[i].bgQueueTypeId == val)
        {
            m_bgBattlegroundQueueID[i].bgQueueTypeId = BATTLEGROUND_QUEUE_NONE;
            m_bgBattlegroundQueueID[i].invitedToInstance = 0;
            m_bgBattlegroundQueueID[i].joinTime = 0;
            return;
        }
    }
}

void Player::SetInviteForBattlegroundQueueType(BattlegroundQueueTypeId bgQueueTypeId, uint32 instanceId)
{
    for (uint8 i=0; i < PLAYER_MAX_BATTLEGROUND_QUEUES; ++i)
        if (m_bgBattlegroundQueueID[i].bgQueueTypeId == bgQueueTypeId)
            m_bgBattlegroundQueueID[i].invitedToInstance = instanceId;
}

bool Player::IsInvitedForBattlegroundInstance(uint32 instanceId) const
{
    for (uint8 i=0; i < PLAYER_MAX_BATTLEGROUND_QUEUES; ++i)
        if (m_bgBattlegroundQueueID[i].invitedToInstance == instanceId)
            return true;
    return false;
}

bool Player::InArena() const
{
    Battleground* bg = GetBattleground();
    if (!bg || !bg->isArena())
        return false;

    return true;
}

bool Player::GetBGAccessByLevel(BattlegroundTypeId bgTypeId) const
{
    // get a template bg instead of running one
    Battleground* bg = sBattlegroundMgr->GetBattlegroundTemplate(bgTypeId);
    if (!bg)
        return false;

    // limit check leel to dbc compatible level range
    uint32 level = getLevel();
    if (level > DEFAULT_MAX_LEVEL)
        level = DEFAULT_MAX_LEVEL;

    if (level < bg->GetMinLevel() || level > bg->GetMaxLevel())
        return false;

    return true;
}

float Player::GetReputationPriceDiscount(Creature const* creature) const
{
    FactionTemplateEntry const* vendor_faction = creature->GetFactionTemplateEntry();
    if (!vendor_faction || !vendor_faction->Faction)
        return 1.0f;

    ReputationRank rank = GetReputationRank(vendor_faction->Faction);
    if (rank <= REP_NEUTRAL)
        return 1.0f;

    return 1.0f - 0.05f* (rank - REP_NEUTRAL);
}

bool Player::IsSpellFitByClassAndRace(uint32 spell_id) const
{
    uint32 racemask  = getRaceMask();
    uint32 classmask = getClassMask();

    SkillLineAbilityMapBounds bounds = sSpellMgr->GetSkillLineAbilityMapBounds(spell_id);
    if (bounds.first == bounds.second)
        return true;

    for (SkillLineAbilityMap::const_iterator _spell_idx = bounds.first; _spell_idx != bounds.second; ++_spell_idx)
    {
        // skip wrong race skills
        if (_spell_idx->second->RaceMask && (_spell_idx->second->RaceMask & racemask) == 0)
            continue;

        // skip wrong class skills
        if (_spell_idx->second->ClassMask && (_spell_idx->second->ClassMask & classmask) == 0)
            continue;

        return true;
    }

    return false;
}

bool Player::HasQuestForGO(int32 GOId) const
{
    for (uint8 i = 0; i < MAX_QUEST_LOG_SIZE; ++i)
    {
        uint32 questid = GetQuestSlotQuestId(i);
        if (questid == 0)
            continue;

        QuestStatusMap::const_iterator qs_itr = m_QuestStatus.find(questid);
        if (qs_itr == m_QuestStatus.end())
            continue;

        QuestStatusData const& qs = qs_itr->second;

        if (qs.Status == QUEST_STATUS_INCOMPLETE)
        {
            Quest const* qInfo = sObjectMgr->GetQuestTemplate(questid);
            if (!qInfo)
                continue;

            if (GetGroup() && GetGroup()->isRaidGroup() && !qInfo->IsAllowedInRaid(GetMap()->GetDifficultyID()))
                continue;

            for (QuestObjective const& obj : qInfo->GetObjectives())
            {
                if (obj.Type != QUEST_OBJECTIVE_GAMEOBJECT) //skip non GO case
                    continue;

                if (GOId == obj.ObjectID && GetQuestObjectiveData(qInfo, obj.StorageIndex) < obj.Amount)
                    return true;
            }
        }
    }
    return false;
}

void Player::UpdateForQuestWorldObjects()
{
    if (m_clientGUIDs.empty())
        return;

    UpdateData udata(GetMapId());
    WorldPacket packet;
    for (auto itr = m_clientGUIDs.begin(); itr != m_clientGUIDs.end(); ++itr)
    {
        if (itr->IsGameObject())
        {
            if (GameObject* obj = ObjectAccessor::GetGameObject(*this, *itr))
                obj->BuildValuesUpdateBlockForPlayer(&udata, this);
        }
        else if (itr->IsCreatureOrVehicle())
        {
            Creature* obj = ObjectAccessor::GetCreatureOrPetOrVehicle(*this, *itr);
            if (!obj)
                continue;

            // check if this unit requires quest specific flags
            if (!obj->HasFlag64(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_SPELLCLICK))
                continue;

            SpellClickInfoMapBounds clickPair = sObjectMgr->GetSpellClickInfoMapBounds(obj->GetEntry());
            for (SpellClickInfoContainer::const_iterator _itr = clickPair.first; _itr != clickPair.second; ++_itr)
            {
                //! This code doesn't look right, but it was logically converted to condition system to do the exact
                //! same thing it did before. It definitely needs to be overlooked for intended functionality.
                if (ConditionContainer const* conds = sConditionMgr->GetConditionsForSpellClickEvent(obj->GetEntry(), _itr->second.spellId))
                {
                    bool buildUpdateBlock = false;
                    for (ConditionContainer::const_iterator jtr = conds->begin(); jtr != conds->end() && !buildUpdateBlock; ++jtr)
                        if ((*jtr)->ConditionType == CONDITION_QUESTREWARDED || (*jtr)->ConditionType == CONDITION_QUESTTAKEN)
                            buildUpdateBlock = true;

                    if (buildUpdateBlock)
                    {
                        obj->BuildValuesUpdateBlockForPlayer(&udata, this);
                        break;
                    }
                }
            }
        }
    }
    udata.BuildPacket(&packet);
    GetSession()->SendPacket(&packet);
}

void Player::SetSummonPoint(uint32 mapid, float x, float y, float z)
{
    m_summon_expire = time(nullptr) + MAX_PLAYER_SUMMON_DELAY;
    m_summon_mapid = mapid;
    m_summon_x = x;
    m_summon_y = y;
    m_summon_z = z;
}

void Player::SummonIfPossible(bool agree)
{
    if (!agree)
    {
        m_summon_expire = 0;
        return;
    }

    // expire and auto declined
    if (m_summon_expire < time(nullptr))
        return;

    // stop taxi flight at summon
    if (IsInFlight())
    {
        GetMotionMaster()->MovementExpired();
        CleanupAfterTaxiFlight();
    }

    // drop flag at summon
    // this code can be reached only when GM is summoning player who carries flag, because player should be immune to summoning spells when he carries flag
    if (Battleground* bg = GetBattleground())
        bg->EventPlayerDroppedFlag(this);

    m_summon_expire = 0;

    UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_ACCEPTED_SUMMONINGS, 1);

    TeleportTo(m_summon_mapid, m_summon_x, m_summon_y, m_summon_z, GetOrientation());
}

void Player::RemoveItemDurations(Item* item)
{
    for (ItemDurationList::iterator itr = m_itemDuration.begin(); itr != m_itemDuration.end(); ++itr)
    {
        if (*itr == item)
        {
            m_itemDuration.erase(itr);
            break;
        }
    }
}

void Player::AddItemDurations(Item* item)
{
    if (item->GetUInt32Value(ITEM_FIELD_DURATION))
    {
        m_itemDuration.push_back(item);
        item->SendTimeUpdate(this);
    }
}

void Player::AutoUnequipOffhandIfNeed(bool force /*= false*/)
{
    Item* offItem = GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND);
    if (!offItem)
        return;

     // unequip offhand weapon if player doesn't have dual wield anymore
    if (!CanDualWield() && (offItem->GetTemplate()->GetInventoryType() == INVTYPE_WEAPONOFFHAND || offItem->GetTemplate()->GetInventoryType() == INVTYPE_WEAPON))
          force = true;

    // need unequip offhand for 2h-weapon without TitanGrip (in any from hands)
    if (!force && (CanTitanGrip() || (offItem->GetTemplate()->GetInventoryType() != INVTYPE_2HWEAPON && !IsTwoHandUsed())))
        return;

    ItemPosCountVec off_dest;
    uint8 off_msg = CanStoreItem(NULL_BAG, NULL_SLOT, off_dest, offItem, false);
    if (off_msg == EQUIP_ERR_OK)
    {
        RemoveItem(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND, true);
        StoreItem(off_dest, offItem, true);
    }
    else
    {
        MoveItemFromInventory(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND, true);
        SQLTransaction trans = CharacterDatabase.BeginTransaction();
        offItem->DeleteFromInventoryDB(trans);                   // deletes item from character's inventory
        offItem->SaveToDB(trans);                                // recursive and not have transaction guard into self, item not in inventory and can be save standalone

        std::string subject = GetSession()->GetTrinityString(LANG_NOT_EQUIPPED_ITEM);
        MailDraft(subject, "There were problems with equipping one or several items").AddItem(offItem).SendMailTo(trans, this, MailSender(this, MAIL_STATIONERY_GM), MAIL_CHECK_MASK_COPIED);

        CharacterDatabase.CommitTransaction(trans);
    }
}

OutdoorPvP* Player::GetOutdoorPvP() const
{
    return sOutdoorPvPMgr->GetOutdoorPvPToZoneId(GetZoneId());
}

bool Player::HasItemFitToSpellRequirements(SpellInfo const* spellInfo, Item const* ignoreItem) const
{
    if (spellInfo->EquippedItemClass < 0)
        return true;

    // scan other equipped items for same requirements (mostly 2 daggers/etc)
    // for optimize check 2 used cases only
    switch (spellInfo->EquippedItemClass)
    {
        case ITEM_CLASS_WEAPON:
        {
            if (Item* item = GetUseableItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND))
                if (item != ignoreItem && item->IsFitToSpellRequirements(spellInfo))
                    return true;
            if (Item* item = GetUseableItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND))
                if (item != ignoreItem && item->IsFitToSpellRequirements(spellInfo))
                    return true;
            break;
        }
        case ITEM_CLASS_ARMOR:
        {
            // tabard not have dependent spells
            for (uint8 i = EQUIPMENT_SLOT_START; i < EQUIPMENT_SLOT_MAINHAND; ++i)
                if (Item* item = GetUseableItemByPos(INVENTORY_SLOT_BAG_0, i))
                    if (item != ignoreItem && item->IsFitToSpellRequirements(spellInfo))
                        return true;

            // shields can be equipped to offhand slot
            if (Item* item = GetUseableItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND))
                if (item != ignoreItem && item->IsFitToSpellRequirements(spellInfo))
                    return true;

            break;
        }
        default:
            TC_LOG_ERROR("entities.player", "Player::HasItemFitToSpellRequirements: Not handled spell requirement for item class %u", spellInfo->EquippedItemClass);
            break;
    }

    return false;
}

bool Player::CanNoReagentCast(SpellInfo const* spellInfo) const
{
    // don't take reagents for spells with SPELL_ATTR5_NO_REAGENT_WHILE_PREP
    if (spellInfo->HasAttribute(SPELL_ATTR5_NO_REAGENT_WHILE_PREP) &&
        HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_PREPARATION))
        return true;

    // Check no reagent use mask
    flag128 noReagentMask;
    noReagentMask[0] = GetUInt32Value(PLAYER_NO_REAGENT_COST_1);
    noReagentMask[1] = GetUInt32Value(PLAYER_NO_REAGENT_COST_1 + 1);
    noReagentMask[2] = GetUInt32Value(PLAYER_NO_REAGENT_COST_1 + 2);
    noReagentMask[3] = GetUInt32Value(PLAYER_NO_REAGENT_COST_1 + 3);
    if (spellInfo->SpellFamilyFlags  & noReagentMask)
        return true;

    return false;
}

void Player::RemoveItemDependentAurasAndCasts(Item* pItem)
{
    for (AuraMap::iterator itr = m_ownedAuras.begin(); itr != m_ownedAuras.end();)
    {
        Aura* aura = itr->second;

        // skip passive (passive item dependent spells work in another way) and not self applied auras
        SpellInfo const* spellInfo = aura->GetSpellInfo();
        if (aura->IsPassive() ||  aura->GetCasterGUID() != GetGUID())
        {
            ++itr;
            continue;
        }

        // skip if not item dependent or have alternative item
        if (HasItemFitToSpellRequirements(spellInfo, pItem))
        {
            ++itr;
            continue;
        }

        // no alt item, remove aura, restart check
        RemoveOwnedAura(itr);
    }

    // currently cast spells can be dependent from item
    for (uint32 i = 0; i < CURRENT_MAX_SPELL; ++i)
        if (Spell* spell = GetCurrentSpell(CurrentSpellTypes(i)))
            if (spell->getState() != SPELL_STATE_DELAYED && !HasItemFitToSpellRequirements(spell->m_spellInfo, pItem))
                InterruptSpell(CurrentSpellTypes(i));
}

uint32 Player::GetResurrectionSpellId() const
{
    // search priceless resurrection possibilities
    uint32 prio = 0;
    uint32 spell_id = 0;
    AuraEffectList const& dummyAuras = GetAuraEffectsByType(SPELL_AURA_DUMMY);
    for (AuraEffectList::const_iterator itr = dummyAuras.begin(); itr != dummyAuras.end(); ++itr)
    {
        // Soulstone Resurrection                           // prio: 3 (max, non death persistent)
        if (prio < 2 && (*itr)->GetSpellInfo()->SpellFamilyName == SPELLFAMILY_WARLOCK && (*itr)->GetSpellInfo()->SpellFamilyFlags[1] & 0x1000000)
        {
            spell_id =  3026;
            prio = 3;
        }
        // Twisting Nether                                  // prio: 2 (max)
        else if ((*itr)->GetId() == 23701 && roll_chance_i(10))
        {
            prio = 2;
            spell_id = 23700;
        }
    }

    // Reincarnation (passive spell)  // prio: 1
    if (prio < 1 && HasSpell(20608) && !GetSpellHistory()->HasCooldown(21169))
        spell_id = 21169;

    return spell_id;
}

// Used in triggers for check "Only to targets that grant experience or honor" req
bool Player::isHonorOrXPTarget(Unit const* victim) const
{
    uint8 v_level = victim->getLevel();
    uint8 k_grey  = Trinity::XP::GetGrayLevel(getLevel());

    // Victim level less gray level
    if (v_level < k_grey)
        return false;

    if (Creature const* const creature = victim->ToCreature())
    {
        if (creature->IsTotem() ||
            creature->IsPet() ||
            creature->GetCreatureTemplate()->flags_extra & CREATURE_FLAG_EXTRA_NO_XP_AT_KILL)
                return false;
    }
    return true;
}

bool Player::GetsRecruitAFriendBonus(bool forXP)
{
    bool recruitAFriend = false;
    if (getLevel() <= sWorld->getIntConfig(CONFIG_MAX_RECRUIT_A_FRIEND_BONUS_PLAYER_LEVEL) || !forXP)
    {
        if (Group* group = this->GetGroup())
        {
            for (GroupReference* itr = group->GetFirstMember(); itr != nullptr; itr = itr->next())
            {
                Player* player = itr->GetSource();
                if (!player)
                    continue;

                if (!player->IsAtRecruitAFriendDistance(this))
                    continue;                               // member (alive or dead) or his corpse at req. distance

                if (forXP)
                {
                    // level must be allowed to get RaF bonus
                    if (player->getLevel() > sWorld->getIntConfig(CONFIG_MAX_RECRUIT_A_FRIEND_BONUS_PLAYER_LEVEL))
                        continue;

                    // level difference must be small enough to get RaF bonus, UNLESS we are lower level
                    if (player->getLevel() < getLevel())
                        if (uint8(getLevel() - player->getLevel()) > sWorld->getIntConfig(CONFIG_MAX_RECRUIT_A_FRIEND_BONUS_PLAYER_LEVEL_DIFFERENCE))
                            continue;
                }

                bool ARecruitedB = (player->GetSession()->GetRecruiterId() == GetSession()->GetAccountId());
                bool BRecruitedA = (GetSession()->GetRecruiterId() == player->GetSession()->GetAccountId());
                if (ARecruitedB || BRecruitedA)
                {
                    recruitAFriend = true;
                    break;
                }
            }
        }
    }
    return recruitAFriend;
}

void Player::RewardPlayerAndGroupAtKill(Unit* victim, bool isBattleGround)
{
    KillRewarder(this, victim, isBattleGround).Reward();
}

void Player::RewardPlayerAndGroupAtEvent(uint32 creature_id, WorldObject* pRewardSource)
{
    if (!pRewardSource)
        return;

    ObjectGuid creature_guid = (pRewardSource->GetTypeId() == TYPEID_UNIT) ? pRewardSource->GetGUID() : ObjectGuid::Empty;

    // prepare data for near group iteration
    if (Group* group = GetGroup())
    {
        for (GroupReference* itr = group->GetFirstMember(); itr != nullptr; itr = itr->next())
        {
            Player* player = itr->GetSource();
            if (!player)
                continue;

            if (!player->IsAtGroupRewardDistance(pRewardSource))
                continue;                               // member (alive or dead) or his corpse at req. distance

            // quest objectives updated only for alive group member or dead but with not released body
            if (player->IsAlive()|| !player->GetCorpse())
                player->KilledMonsterCredit(creature_id, creature_guid);
        }
    }
    else                                                    // if (!group)
        KilledMonsterCredit(creature_id, creature_guid);
}

bool Player::IsAtGroupRewardDistance(WorldObject const* pRewardSource) const
{
    if (!pRewardSource)
        return false;
    const WorldObject* player = GetCorpse();
    if (!player || IsAlive())
        player = this;

    if (player->GetMapId() != pRewardSource->GetMapId() || player->GetInstanceId() != pRewardSource->GetInstanceId())
        return false;

    if (player->GetMap()->IsDungeon())
        return true;

    return pRewardSource->GetDistance(player) <= sWorld->getFloatConfig(CONFIG_GROUP_XP_DISTANCE);
}

bool Player::IsAtRecruitAFriendDistance(WorldObject const* pOther) const
{
    if (!pOther)
        return false;
    const WorldObject* player = GetCorpse();
    if (!player || IsAlive())
        player = this;

    if (player->GetMapId() != pOther->GetMapId() || player->GetInstanceId() != pOther->GetInstanceId())
        return false;

    return pOther->GetDistance(player) <= sWorld->getFloatConfig(CONFIG_MAX_RECRUIT_A_FRIEND_DISTANCE);
}

void Player::ResurrectUsingRequestData()
{
    /// Teleport before resurrecting by player, otherwise the player might get attacked from creatures near his corpse
    TeleportTo(_resurrectionData->Location);

    if (IsBeingTeleported())
    {
        ScheduleDelayedOperation(DELAYED_RESURRECT_PLAYER);
        return;
    }

    ResurrectUsingRequestDataImpl();
}

void Player::ResurrectUsingRequestDataImpl()
{
    ResurrectPlayer(0.0f, false);

    if (GetMaxHealth() > _resurrectionData->Health)
        SetHealth(_resurrectionData->Health);
    else
        SetFullHealth();

    if (uint32(GetMaxPower(POWER_MANA)) > _resurrectionData->Mana)
        SetPower(POWER_MANA, _resurrectionData->Mana);
    else
        SetPower(POWER_MANA, GetMaxPower(POWER_MANA));

    SetPower(POWER_RAGE, 0);
    SetPower(POWER_ENERGY, GetMaxPower(POWER_ENERGY));
    SetPower(POWER_FOCUS, GetMaxPower(POWER_FOCUS));
    SetPower(POWER_ECLIPSE, 0);

    if (uint32 aura = _resurrectionData->Aura)
        CastSpell(this, aura, true, nullptr, nullptr, _resurrectionData->GUID);

    SpawnCorpseBones();
}

void Player::SetClientControl(Unit* target, bool allowMove)
{
    WorldPackets::Movement::ControlUpdate data;
    data.Guid = target->GetGUID();
    data.On = allowMove;
    GetSession()->SendPacket(data.Write());

    if (this != target)
        SetViewpoint(target, allowMove);

    if (allowMove)
        SetMover(target);
}

void Player::SetMover(Unit* target)
{
    m_mover->m_movedPlayer = nullptr;
    m_mover = target;
    m_mover->m_movedPlayer = this;

    WorldPackets::Movement::MoveSetActiveMover packet;
    packet.MoverGUID = target->GetGUID();
    SendDirectMessage(packet.Write());
}

void Player::UpdateZoneDependentAuras(uint32 newZone)
{
    // Some spells applied at enter into zone (with subzones), aura removed in UpdateAreaDependentAuras that called always at zone->area update
    SpellAreaForAreaMapBounds saBounds = sSpellMgr->GetSpellAreaForAreaMapBounds(newZone);
    for (SpellAreaForAreaMap::const_iterator itr = saBounds.first; itr != saBounds.second; ++itr)
        if (itr->second->autocast && itr->second->IsFitToRequirements(this, newZone, 0))
            if (!HasAura(itr->second->spellId))
                CastSpell(this, itr->second->spellId, true);
}

void Player::UpdateAreaDependentAuras(uint32 newArea)
{
    // remove auras from spells with area limitations
    for (AuraMap::iterator iter = m_ownedAuras.begin(); iter != m_ownedAuras.end();)
    {
        // use m_zoneUpdateId for speed: UpdateArea called from UpdateZone or instead UpdateZone in both cases m_zoneUpdateId up-to-date
        if (iter->second->GetSpellInfo()->CheckLocation(GetMapId(), m_zoneUpdateId, newArea, this) != SPELL_CAST_OK)
            RemoveOwnedAura(iter);
        else
            ++iter;
    }

    // some auras applied at subzone enter
    SpellAreaForAreaMapBounds saBounds = sSpellMgr->GetSpellAreaForAreaMapBounds(newArea);
    for (SpellAreaForAreaMap::const_iterator itr = saBounds.first; itr != saBounds.second; ++itr)
        if (itr->second->autocast && itr->second->IsFitToRequirements(this, m_zoneUpdateId, newArea))
            if (!HasAura(itr->second->spellId))
                CastSpell(this, itr->second->spellId, true);
}

uint32 Player::GetCorpseReclaimDelay(bool pvp) const
{
    if (pvp)
    {
        if (!sWorld->getBoolConfig(CONFIG_DEATH_CORPSE_RECLAIM_DELAY_PVP))
            return copseReclaimDelay[0];
    }
    else if (!sWorld->getBoolConfig(CONFIG_DEATH_CORPSE_RECLAIM_DELAY_PVE))
        return 0;

    time_t now = time(nullptr);
    // 0..2 full period
    // should be ceil(x)-1 but not floor(x)
    uint64 count = (now < m_deathExpireTime - 1) ? (m_deathExpireTime - 1 - now) / DEATH_EXPIRE_STEP : 0;
    return copseReclaimDelay[count];
}

void Player::UpdateCorpseReclaimDelay()
{
    bool pvp = (m_ExtraFlags & PLAYER_EXTRA_PVP_DEATH) != 0;

    if ((pvp && !sWorld->getBoolConfig(CONFIG_DEATH_CORPSE_RECLAIM_DELAY_PVP)) ||
        (!pvp && !sWorld->getBoolConfig(CONFIG_DEATH_CORPSE_RECLAIM_DELAY_PVE)))
        return;

    time_t now = time(nullptr);

    if (now < m_deathExpireTime)
    {
        // full and partly periods 1..3
        uint64 count = (m_deathExpireTime - now) / DEATH_EXPIRE_STEP + 1;

        if (count < MAX_DEATH_COUNT)
            m_deathExpireTime = now+(count + 1) * DEATH_EXPIRE_STEP;
        else
            m_deathExpireTime = now + MAX_DEATH_COUNT*DEATH_EXPIRE_STEP;
    }
    else
        m_deathExpireTime = now + DEATH_EXPIRE_STEP;
}

int32 Player::CalculateCorpseReclaimDelay(bool load) const
{
    Corpse* corpse = GetCorpse();

    if (load && !corpse)
        return -1;

    bool pvp = corpse ? corpse->GetType() == CORPSE_RESURRECTABLE_PVP : (m_ExtraFlags & PLAYER_EXTRA_PVP_DEATH) != 0;

    uint32 delay;

    if (load)
    {
        if (corpse->GetGhostTime() > m_deathExpireTime)
            return -1;

        uint64 count = 0;

        if ((pvp && sWorld->getBoolConfig(CONFIG_DEATH_CORPSE_RECLAIM_DELAY_PVP)) ||
           (!pvp && sWorld->getBoolConfig(CONFIG_DEATH_CORPSE_RECLAIM_DELAY_PVE)))
        {
            count = (m_deathExpireTime - corpse->GetGhostTime()) / DEATH_EXPIRE_STEP;

            if (count >= MAX_DEATH_COUNT)
                count = MAX_DEATH_COUNT - 1;
        }

        time_t expected_time = corpse->GetGhostTime() + copseReclaimDelay[count];
        time_t now = time(nullptr);

        if (now >= expected_time)
            return -1;

        delay = expected_time - now;
    }
    else
        delay = GetCorpseReclaimDelay(pvp);

    return delay * IN_MILLISECONDS;
}

void Player::SendCorpseReclaimDelay(uint32 delay) const
{
    WorldPackets::Misc::CorpseReclaimDelay packet;
    packet.Remaining = delay;
    GetSession()->SendPacket(packet.Write());
}

Player* Player::GetNextRandomRaidMember(float radius)
{
    Group* group = GetGroup();
    if (!group)
        return nullptr;

    std::vector<Player*> nearMembers;
    nearMembers.reserve(group->GetMembersCount());

    for (GroupReference* itr = group->GetFirstMember(); itr != nullptr; itr = itr->next())
    {
        Player* Target = itr->GetSource();

        // IsHostileTo check duel and controlled by enemy
        if (Target && Target != this && IsWithinDistInMap(Target, radius) &&
            !Target->HasInvisibilityAura() && !IsHostileTo(Target))
            nearMembers.push_back(Target);
    }

    if (nearMembers.empty())
        return nullptr;

    uint32 randTarget = urand(0, nearMembers.size()-1);
    return nearMembers[randTarget];
}

PartyResult Player::CanUninviteFromGroup(ObjectGuid guidMember) const
{
    Group const* grp = GetGroup();
    if (!grp)
        return ERR_NOT_IN_GROUP;

    if (grp->isLFGGroup())
    {
        ObjectGuid gguid = grp->GetGUID();
        if (!sLFGMgr->GetKicksLeft(gguid))
            return ERR_PARTY_LFG_BOOT_LIMIT;

        lfg::LfgState state = sLFGMgr->GetState(gguid);
        if (sLFGMgr->IsVoteKickActive(gguid))
            return ERR_PARTY_LFG_BOOT_IN_PROGRESS;

        if (grp->GetMembersCount() <= lfg::LFG_GROUP_KICK_VOTES_NEEDED)
            return ERR_PARTY_LFG_BOOT_TOO_FEW_PLAYERS;

        if (state == lfg::LFG_STATE_FINISHED_DUNGEON)
            return ERR_PARTY_LFG_BOOT_DUNGEON_COMPLETE;

        if (grp->isRollLootActive())
            return ERR_PARTY_LFG_BOOT_LOOT_ROLLS;

        /// @todo Should also be sent when anyone has recently left combat, with an aprox ~5 seconds timer.
        for (GroupReference const* itr = grp->GetFirstMember(); itr != nullptr; itr = itr->next())
            if (itr->GetSource() && itr->GetSource()->IsInCombat())
                return ERR_PARTY_LFG_BOOT_IN_COMBAT;

        /* Missing support for these types
            return ERR_PARTY_LFG_BOOT_COOLDOWN_S;
            return ERR_PARTY_LFG_BOOT_NOT_ELIGIBLE_S;
        */
    }
    else
    {
        if (!grp->IsLeader(GetGUID()) && !grp->IsAssistant(GetGUID()))
            return ERR_NOT_LEADER;

        if (InBattleground())
            return ERR_INVITE_RESTRICTED;

        if (grp->IsLeader(guidMember))
            return ERR_NOT_LEADER;
    }

    return ERR_PARTY_RESULT_OK;
}

bool Player::isUsingLfg() const
{
    return sLFGMgr->GetState(GetGUID()) != lfg::LFG_STATE_NONE;
}

bool Player::inRandomLfgDungeon() const
{
    if (sLFGMgr->selectedRandomLfgDungeon(GetGUID()))
    {
        Map const* map = GetMap();
        return sLFGMgr->inLfgDungeonMap(GetGUID(), map->GetId(), map->GetDifficultyID());
    }

    return false;
}

void Player::SetBattlegroundOrBattlefieldRaid(Group* group, int8 subgroup)
{
    //we must move references from m_group to m_originalGroup
    SetOriginalGroup(GetGroup(), GetSubGroup());

    m_group.unlink();
    m_group.link(group, this);
    m_group.setSubGroup((uint8)subgroup);
}

void Player::RemoveFromBattlegroundOrBattlefieldRaid()
{
    //remove existing reference
    m_group.unlink();
    if (Group* group = GetOriginalGroup())
    {
        m_group.link(group, this);
        m_group.setSubGroup(GetOriginalSubGroup());
    }
    SetOriginalGroup(nullptr);
}

void Player::SetOriginalGroup(Group* group, int8 subgroup)
{
    if (group == nullptr)
        m_originalGroup.unlink();
    else
    {
        // never use SetOriginalGroup without a subgroup unless you specify NULL for group
        ASSERT(subgroup >= 0);
        m_originalGroup.link(group, this);
        m_originalGroup.setSubGroup((uint8)subgroup);
    }
}

void Player::UpdateUnderwaterState(Map* m, float x, float y, float z)
{
    LiquidData liquid_status;
    ZLiquidStatus res = m->getLiquidStatus(x, y, z, MAP_ALL_LIQUIDS, &liquid_status);
    if (!res)
    {
        m_MirrorTimerFlags &= ~(UNDERWATER_INWATER | UNDERWATER_INLAVA | UNDERWATER_INSLIME | UNDERWARER_INDARKWATER);
        if (_lastLiquid && _lastLiquid->SpellID)
            RemoveAurasDueToSpell(_lastLiquid->SpellID);

        _lastLiquid = nullptr;
        return;
    }

    if (uint32 liqEntry = liquid_status.entry)
    {
        LiquidTypeEntry const* liquid = sLiquidTypeStore.LookupEntry(liqEntry);
        if (_lastLiquid && _lastLiquid->SpellID && _lastLiquid->ID != liqEntry)
            RemoveAurasDueToSpell(_lastLiquid->SpellID);

        if (liquid && liquid->SpellID)
        {
            if (res & (LIQUID_MAP_UNDER_WATER | LIQUID_MAP_IN_WATER))
            {
                if (!HasAura(liquid->SpellID))
                    CastSpell(this, liquid->SpellID, true);
            }
            else
                RemoveAurasDueToSpell(liquid->SpellID);
        }

        _lastLiquid = liquid;
    }
    else if (_lastLiquid && _lastLiquid->SpellID)
    {
        RemoveAurasDueToSpell(_lastLiquid->SpellID);
        _lastLiquid = nullptr;
    }


    // All liquids type - check under water position
    if (liquid_status.type_flags & (MAP_LIQUID_TYPE_WATER | MAP_LIQUID_TYPE_OCEAN | MAP_LIQUID_TYPE_MAGMA | MAP_LIQUID_TYPE_SLIME))
    {
        if (res & LIQUID_MAP_UNDER_WATER)
            m_MirrorTimerFlags |= UNDERWATER_INWATER;
        else
            m_MirrorTimerFlags &= ~UNDERWATER_INWATER;
    }

    // Allow travel in dark water on taxi or transport
    if ((liquid_status.type_flags & MAP_LIQUID_TYPE_DARK_WATER) && !IsInFlight() && !GetTransport())
        m_MirrorTimerFlags |= UNDERWARER_INDARKWATER;
    else
        m_MirrorTimerFlags &= ~UNDERWARER_INDARKWATER;

    // in lava check, anywhere in lava level
    if (liquid_status.type_flags & MAP_LIQUID_TYPE_MAGMA)
    {
        if (res & (LIQUID_MAP_UNDER_WATER | LIQUID_MAP_IN_WATER | LIQUID_MAP_WATER_WALK))
            m_MirrorTimerFlags |= UNDERWATER_INLAVA;
        else
            m_MirrorTimerFlags &= ~UNDERWATER_INLAVA;
    }
    // in slime check, anywhere in slime level
    if (liquid_status.type_flags & MAP_LIQUID_TYPE_SLIME)
    {
        if (res & (LIQUID_MAP_UNDER_WATER | LIQUID_MAP_IN_WATER | LIQUID_MAP_WATER_WALK))
            m_MirrorTimerFlags |= UNDERWATER_INSLIME;
        else
            m_MirrorTimerFlags &= ~UNDERWATER_INSLIME;
    }
}

void Player::SetCanParry(bool value)
{
    if (m_canParry == value)
        return;

    m_canParry = value;
    UpdateParryPercentage();
}

void Player::SetCanBlock(bool value)
{
    if (m_canBlock == value)
        return;

    m_canBlock = value;
    UpdateBlockPercentage();
}

bool ItemPosCount::isContainedIn(std::vector<ItemPosCount> const& vec) const
{
    for (ItemPosCountVec::const_iterator itr = vec.begin(); itr != vec.end(); ++itr)
        if (itr->pos == pos)
            return true;
    return false;
}

void Player::StopCastingBindSight() const
{
    if (WorldObject* target = GetViewpoint())
    {
        if (target->isType(TYPEMASK_UNIT))
        {
            static_cast<Unit*>(target)->RemoveAurasByType(SPELL_AURA_BIND_SIGHT, GetGUID());
            static_cast<Unit*>(target)->RemoveAurasByType(SPELL_AURA_MOD_POSSESS, GetGUID());
            static_cast<Unit*>(target)->RemoveAurasByType(SPELL_AURA_MOD_POSSESS_PET, GetGUID());
        }
    }
}

void Player::SetViewpoint(WorldObject* target, bool apply)
{
    if (apply)
    {
        TC_LOG_DEBUG("maps", "Player::CreateViewpoint: Player '%s' (%s) creates seer (Entry: %u, TypeId: %u).",
            GetName().c_str(), GetGUID().ToString().c_str(), target->GetEntry(), target->GetTypeId());

        if (!AddGuidValue(PLAYER_FARSIGHT, target->GetGUID()))
        {
            TC_LOG_FATAL("entities.player", "Player::CreateViewpoint: Player '%s' (%s) cannot add new viewpoint!", GetName().c_str(), GetGUID().ToString().c_str());
            return;
        }

        // farsight dynobj or puppet may be very far away
        UpdateVisibilityOf(target);

        if (target->isType(TYPEMASK_UNIT) && target != GetVehicleBase())
            static_cast<Unit*>(target)->AddPlayerToVision(this);
    }
    else
    {
        TC_LOG_DEBUG("maps", "Player::CreateViewpoint: Player %s remove seer", GetName().c_str());

        if (!RemoveGuidValue(PLAYER_FARSIGHT, target->GetGUID()))
        {
            TC_LOG_FATAL("entities.player", "Player::CreateViewpoint: Player '%s' (%s) cannot remove current viewpoint!", GetName().c_str(), GetGUID().ToString().c_str());
            return;
        }

        if (target->isType(TYPEMASK_UNIT) && target != GetVehicleBase())
            static_cast<Unit*>(target)->RemovePlayerFromVision(this);

        //must immediately set seer back otherwise may crash
        m_seer = this;

        //WorldPacket data(SMSG_CLEAR_FAR_SIGHT_IMMEDIATE, 0);
        //GetSession()->SendPacket(&data);
    }
}

WorldObject* Player::GetViewpoint() const
{
    ObjectGuid guid = GetGuidValue(PLAYER_FARSIGHT);
    if (!guid.IsEmpty())
        return static_cast<WorldObject*>(ObjectAccessor::GetObjectByTypeMask(*this, guid, TYPEMASK_SEER));
    return nullptr;
}

bool Player::CanUseBattlegroundObject(GameObject* gameobject) const
{
    // It is possible to call this method with a null pointer, only skipping faction check.
    if (gameobject)
    {
        FactionTemplateEntry const* playerFaction = GetFactionTemplateEntry();
        FactionTemplateEntry const* faction = sFactionTemplateStore.LookupEntry(gameobject->GetUInt32Value(GAMEOBJECT_FACTION));

        if (playerFaction && faction && !playerFaction->IsFriendlyTo(*faction))
            return false;
    }

    // BUG: sometimes when player clicks on flag in AB - client won't send gameobject_use, only gameobject_report_use packet
    // Note: Mount, stealth and invisibility will be removed when used
    return (!isTotalImmune() &&                            // Damage immune
            !HasAura(SPELL_RECENTLY_DROPPED_FLAG) &&       // Still has recently held flag debuff
            IsAlive());                                    // Alive
}

bool Player::CanCaptureTowerPoint() const
{
    return (!HasStealthAura() &&                            // not stealthed
            !HasInvisibilityAura() &&                       // not invisible
            IsAlive());                                     // live player
}

uint32 Player::GetBarberShopCost(BarberShopStyleEntry const* newHairStyle, uint8 newHairColor, BarberShopStyleEntry const* newFacialHair, BarberShopStyleEntry const* newSkin /*= nullptr*/, BarberShopStyleEntry const* newFace /*= nullptr*/) const
{
    uint8 level = getLevel();

    if (level >= sGtBarberShopCostBaseStore.GetTableRowCount())
        level = sGtBarberShopCostBaseStore.GetTableRowCount() - 1;

    uint8 hairstyle = GetByteValue(PLAYER_BYTES, PLAYER_BYTES_OFFSET_HAIR_STYLE_ID);
    uint8 haircolor = GetByteValue(PLAYER_BYTES, PLAYER_BYTES_OFFSET_HAIR_COLOR_ID);
    uint8 facialhair = GetByteValue(PLAYER_BYTES_2, PLAYER_BYTES_2_OFFSET_FACIAL_STYLE);
    uint8 skincolor = GetByteValue(PLAYER_BYTES, PLAYER_BYTES_OFFSET_SKIN_ID);
    uint8 face = GetByteValue(PLAYER_BYTES, PLAYER_BYTES_OFFSET_FACE_ID);

    if ((hairstyle == newHairStyle->Data) && (haircolor == newHairColor) && (facialhair == newFacialHair->Data) && (!newSkin || (newSkin->Data == skincolor)) && (!newFace || (newFace->Data == face)))
        return 0;

    GtBarberShopCostBaseEntry const* bsc = sGtBarberShopCostBaseStore.EvaluateTable(level - 1, 0);
    if (!bsc)                                                // shouldn't happen
        return 0xFFFFFFFF;

    uint32 cost = 0;

    if (hairstyle != newHairStyle->Data)
        cost += uint32(bsc->cost * newHairStyle->CostModifier);

    if ((haircolor != newHairColor) && (hairstyle == newHairStyle->Data))
        cost += uint32(bsc->cost * 0.5f);                    // +1/2 of price

    if (facialhair != newFacialHair->Data)
        cost += uint32(bsc->cost * newFacialHair->CostModifier);

    if (newSkin && skincolor != newSkin->Data)
        cost += uint32(bsc->cost * newSkin->CostModifier);

    if (newFace && face != newFace->Data)
        cost += uint32(bsc->cost * newFace->CostModifier);

    return cost;
}

void Player::InitGlyphsForLevel()
{
    uint32 slotMask = 0;
    uint8 slot = 0;
    uint8 level = getLevel();
    for (GlyphSlotEntry const* gs : sDB2Manager.GetGlyphSlots())
    {
        if (level >= ((gs->Tooltip + 1) * 25))
            slotMask |= 1 << slot;

        SetGlyphSlot(slot++, gs->ID);
    }

    SetUInt32Value(PLAYER_GLYPHS_ENABLED, slotMask);
}

void Player::SetGlyph(uint8 slot, uint32 glyph)
{
    _talentMgr->GroupInfo[GetActiveTalentGroup()].Glyphs[slot] = glyph;
    SetUInt32Value(PLAYER_FIELD_GLYPHS_1 + slot, glyph);
}

bool Player::isTotalImmune() const
{
    AuraEffectList const& immune = GetAuraEffectsByType(SPELL_AURA_SCHOOL_IMMUNITY);

    uint32 immuneMask = 0;
    for (AuraEffectList::const_iterator itr = immune.begin(); itr != immune.end(); ++itr)
    {
        immuneMask |= (*itr)->GetMiscValue();
        if (immuneMask & SPELL_SCHOOL_MASK_ALL)            // total immunity
            return true;
    }
    return false;
}

bool Player::HasTitle(uint32 bitIndex) const
{
    if (bitIndex > MAX_TITLE_INDEX)
        return false;

    uint32 fieldIndexOffset = bitIndex / 32;
    uint32 flag = 1 << (bitIndex % 32);
    return HasFlag(PLAYER__FIELD_KNOWN_TITLES + fieldIndexOffset, flag);
}

void Player::SetTitle(CharTitlesEntry const* title, bool lost)
{
    uint32 fieldIndexOffset = title->MaskID / 32;
    uint32 flag = 1 << (title->MaskID % 32);

    if (lost)
    {
        if (!HasFlag(PLAYER__FIELD_KNOWN_TITLES + fieldIndexOffset, flag))
            return;

        RemoveFlag(PLAYER__FIELD_KNOWN_TITLES + fieldIndexOffset, flag);
    }
    else
    {
        if (HasFlag(PLAYER__FIELD_KNOWN_TITLES + fieldIndexOffset, flag))
            return;

        SetFlag(PLAYER__FIELD_KNOWN_TITLES + fieldIndexOffset, flag);
    }

    WorldPackets::Character::TitleEarned packet(lost ? SMSG_TITLE_LOST : SMSG_TITLE_EARNED);
    packet.Index = title->MaskID;
    GetSession()->SendPacket(packet.Write());
}

bool Player::isTotalImmunity() const
{
    AuraEffectList const& immune = GetAuraEffectsByType(SPELL_AURA_SCHOOL_IMMUNITY);

    for (AuraEffectList::const_iterator itr = immune.begin(); itr != immune.end(); ++itr)
    {
        if (((*itr)->GetMiscValue() & SPELL_SCHOOL_MASK_ALL) !=0)   // total immunity
        {
            return true;
        }
        if (((*itr)->GetMiscValue() & SPELL_SCHOOL_MASK_NORMAL) !=0)   // physical damage immunity
        {
            for (AuraEffectList::const_iterator i = immune.begin(); i != immune.end(); ++i)
            {
                if (((*i)->GetMiscValue() & SPELL_SCHOOL_MASK_MAGIC) !=0)   // magic immunity
                {
                    return true;
                }
            }
        }
    }
    return false;
}

void Player::UpdateCharmedAI()
{
    //This should only called in Player::Update
  Creature* charmer = GetCharmer()->ToCreature();

    //kill self if charm aura has infinite duration
    if (charmer->IsInEvadeMode())
    {
        AuraEffectList const& auras = GetAuraEffectsByType(SPELL_AURA_MOD_CHARM);
        for (AuraEffectList::const_iterator iter = auras.begin(); iter != auras.end(); ++iter)
            if ((*iter)->GetCasterGUID() == charmer->GetGUID() && (*iter)->GetBase()->IsPermanent())
            {
                charmer->DealDamage(this, GetHealth(), nullptr, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, nullptr, false);
                return;
            }
    }

    if (!charmer->IsInCombat())
        GetMotionMaster()->MoveFollow(charmer, PET_FOLLOW_DIST, PET_FOLLOW_ANGLE);

    Unit* target = GetVictim();
    if (!target || !charmer->IsValidAttackTarget(target))
    {
        target = charmer->SelectNearestTarget();
        if (!target)
            return;

        GetMotionMaster()->MoveChase(target);
        Attack(target, true);
    }
}

uint32 Player::GetRuneTypeBaseCooldown(RuneType runeType) const
{
    float cooldown = RUNE_BASE_COOLDOWN;
    float hastePct;

    AuraEffectList const& regenAura = GetAuraEffectsByType(SPELL_AURA_MOD_POWER_REGEN_PERCENT);
    for (AuraEffectList::const_iterator i = regenAura.begin();i != regenAura.end(); ++i)
        if ((*i)->GetMiscValue() == POWER_RUNES && (*i)->GetMiscValueB() == runeType)
            cooldown *= 1.0f - (*i)->GetAmount() / 100.0f;

    // Runes cooldown are now affected by player's haste from equipment ...
    hastePct = GetRatingBonusValue(CR_HASTE_MELEE);

    // ... and some auras.
    hastePct += GetTotalAuraModifier(SPELL_AURA_MOD_MELEE_HASTE);
    hastePct += GetTotalAuraModifier(SPELL_AURA_MOD_MELEE_HASTE_2);
    hastePct += GetTotalAuraModifier(SPELL_AURA_MOD_MELEE_HASTE_3);

    cooldown *=  1.0f - (hastePct / 100.0f);

    return cooldown;
}

void Player::SetRuneCooldown(uint8 index, uint32 cooldown, bool casted /*= false*/)
{
    uint32 gracePeriod = GetRuneTimer(index);

    if (casted && IsInCombat())
    {
        if (gracePeriod < 0xFFFFFFFF && cooldown > 0)
        {
            uint32 lessCd = std::min(uint32(2500), gracePeriod);
            cooldown = (cooldown > lessCd) ? (cooldown - lessCd) : 0;
            SetLastRuneGraceTimer(index, lessCd);
        }

        SetRuneTimer(index, 0);
    }

    m_runes->runes[index].Cooldown = cooldown;
    m_runes->SetRuneState(index, (cooldown == 0) ? true : false);
}

void Player::SetRuneConvertAura(uint8 index, AuraEffect const* aura)
{
    m_runes->runes[index].ConvertAura = aura;
}

void Player::AddRuneByAuraEffect(uint8 index, RuneType newType, AuraEffect const* aura)
{
    SetRuneConvertAura(index, aura); ConvertRune(index, newType);
}

void Player::RemoveRunesByAuraEffect(AuraEffect const* aura)
{
    for (uint8 i = 0; i < MAX_RUNES; ++i)
    {
        if (m_runes->runes[i].ConvertAura == aura)
        {
            ConvertRune(i, GetBaseRune(i));
            SetRuneConvertAura(i, nullptr);
        }
    }
}

void Player::RestoreBaseRune(uint8 index)
{
    AuraEffect const* aura = m_runes->runes[index].ConvertAura;
    // If rune was converted by a non-passive aura that still active we should keep it converted
    if (aura && !(aura->GetSpellInfo()->Attributes & SPELL_ATTR0_PASSIVE))
        return;
    ConvertRune(index, GetBaseRune(index));
    SetRuneConvertAura(index, nullptr);
    // Don't drop passive talents providing rune convertion
    if (!aura || aura->GetAuraType() != SPELL_AURA_CONVERT_RUNE)
        return;
    for (uint8 i = 0; i < MAX_RUNES; ++i)
    {
        if (aura == m_runes->runes[i].ConvertAura)
            return;
    }
    aura->GetBase()->Remove();
}

void Player::ConvertRune(uint8 index, RuneType newType)
{
    SetCurrentRune(index, newType);

    WorldPackets::Spells::ConvertRune data;
    data.Index = index;
    data.Rune = newType;
    GetSession()->SendPacket(data.Write());
}

void Player::ResyncRunes(uint8 count) const
{
    WorldPackets::Spells::ResyncRunes data(count);

    for (uint32 i = 0; i < count; ++i)
    {
        WorldPackets::Spells::ResyncRunes::ResyncRune rune;
        rune.RuneType = GetCurrentRune(i);                         // rune type
        rune.Cooldown = uint8(255 - (GetRuneCooldown(i) * 51));    // passed cooldown time (0-255)
        data.Runes.push_back(rune);
    }
    GetSession()->SendPacket(data.Write());
}

void Player::AddRunePower(uint8 index) const
{
    WorldPacket data(SMSG_ADD_RUNE_POWER, 4);
    data << uint32(1 << index);                             // mask (0x00-0x3F probably)
    GetSession()->SendPacket(&data);
}

static RuneType runeSlotTypes[MAX_RUNES] =
{
    /*0*/ RUNE_BLOOD,
    /*1*/ RUNE_BLOOD,
    /*2*/ RUNE_UNHOLY,
    /*3*/ RUNE_UNHOLY,
    /*4*/ RUNE_FROST,
    /*5*/ RUNE_FROST
};

void Player::InitRunes()
{
    if (getClass() != CLASS_DEATH_KNIGHT)
        return;

    m_runes = new Runes;

    m_runes->runeState = 0;
    m_runes->lastUsedRune = RUNE_BLOOD;

    for (uint8 i = 0; i < MAX_RUNES; ++i)
    {
        SetBaseRune(i, runeSlotTypes[i]);                               // init base types
        SetCurrentRune(i, runeSlotTypes[i]);                            // init current types
        SetRuneCooldown(i, 0);                                          // reset cooldowns
        SetRuneTimer(i, 0xFFFFFFFF);                                    // Reset rune flags
        SetLastRuneGraceTimer(i, 0);
        SetRuneConvertAura(i, nullptr);
        m_runes->SetRuneState(i);
    }

    for (uint8 i = 0; i < NUM_RUNE_TYPES; ++i)
        SetFloatValue(PLAYER_RUNE_REGEN_1 + i, 0.1f);                  // set a base regen timer equal to 10 sec
}

bool Player::IsBaseRuneSlotsOnCooldown(RuneType runeType) const
{
    for (uint8 i = 0; i < MAX_RUNES; ++i)
        if (GetBaseRune(i) == runeType && GetRuneCooldown(i) == 0)
            return false;

    return true;
}

void Player::AutoStoreLoot(uint8 bag, uint8 slot, uint32 loot_id, LootStore const& store, bool broadcast)
{
    Loot loot;
    loot.FillLoot (loot_id, store, this, true);

    uint32 max_slot = loot.GetMaxSlotInLootFor(this);
    for (uint32 i = 0; i < max_slot; ++i)
    {
        LootItem* lootItem = loot.LootItemInSlot(i, this);

        ItemPosCountVec dest;
        InventoryResult msg = CanStoreNewItem(bag, slot, dest, lootItem->itemid, lootItem->count);
        if (msg != EQUIP_ERR_OK && slot != NULL_SLOT)
            msg = CanStoreNewItem(bag, NULL_SLOT, dest, lootItem->itemid, lootItem->count);
        if (msg != EQUIP_ERR_OK && bag != NULL_BAG)
            msg = CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, lootItem->itemid, lootItem->count);
        if (msg != EQUIP_ERR_OK)
        {
            SendEquipError(msg, nullptr, nullptr, lootItem->itemid);
            continue;
        }

        Item* pItem = StoreNewItem(dest, lootItem->itemid, true, lootItem->randomPropertyId, GuidSet(), lootItem->BonusListIDs);
        SendNewItem(pItem, lootItem->count, false, false, broadcast);
    }
}

void Player::StoreLootItem(uint8 lootSlot, Loot* loot)
{
    QuestItem* qitem = nullptr;
    QuestItem* ffaitem = nullptr;
    QuestItem* conditem = nullptr;

    LootItem* item = loot->LootItemInSlot(lootSlot, this, &qitem, &ffaitem, &conditem);

    if (!item)
    {
        SendEquipError(EQUIP_ERR_LOOT_GONE, nullptr, nullptr);
        return;
    }

    if (!item->AllowedForPlayer(this))
    {
        SendLootRelease(GetLootGUID());
        return;
    }

    // questitems use the blocked field for other purposes
    if (!qitem && item->is_blocked)
    {
        SendLootRelease(GetLootGUID());
        return;
    }

    ItemPosCountVec dest;
    InventoryResult msg = CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, item->itemid, item->count);
    if (msg == EQUIP_ERR_OK)
    {
        Item* newitem = StoreNewItem(dest, item->itemid, true, item->randomPropertyId, item->GetAllowedLooters(), item->BonusListIDs);

        if (qitem)
        {
            qitem->is_looted = true;
            //freeforall is 1 if everyone's supposed to get the quest item.
            if (item->freeforall || loot->GetPlayerQuestItems().size() == 1)
                SendNotifyLootItemRemoved(GetLootGUID(), loot->GetGUID(), lootSlot);
            else
                loot->NotifyQuestItemRemoved(qitem->index);
        }
        else
        {
            if (ffaitem)
            {
                //freeforall case, notify only one player of the removal
                ffaitem->is_looted = true;
                SendNotifyLootItemRemoved(GetLootGUID(), loot->GetGUID(), lootSlot);
            }
            else
            {
                //not freeforall, notify everyone
                if (conditem)
                    conditem->is_looted = true;
                loot->NotifyItemRemoved(lootSlot);
            }
        }

        //if only one person is supposed to loot the item, then set it to looted
        if (!item->freeforall)
            item->is_looted = true;

        --loot->unlootedCount;

        if (sObjectMgr->GetItemTemplate(item->itemid))
            if (newitem->GetQuality() > ITEM_QUALITY_EPIC || (newitem->GetQuality() == ITEM_QUALITY_EPIC && newitem->GetItemLevel(this) >= MinNewsItemLevel))
                if (Guild* guild = GetGuild())
                    guild->AddGuildNews(GUILD_NEWS_ITEM_LOOTED, GetGUID(), 0, item->itemid);

        SendNewItem(newitem, uint32(item->count), false, false, true);
        UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_LOOT_ITEM, item->itemid, item->count);
        UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_LOOT_TYPE, item->itemid, item->count, loot->loot_type);
        UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_LOOT_EPIC_ITEM, item->itemid, item->count);

        // LootItem is being removed (looted) from the container, delete it from the DB.
        if (!loot->containerID.IsEmpty())
            loot->DeleteLootItemFromContainerItemDB(item->itemid);
    }
    else
        SendEquipError(msg, nullptr, nullptr, item->itemid);
}

bool Player::CanFlyInZone(uint32 mapid, uint32 zone) const
{
    // continent checked in SpellInfo::CheckLocation at cast and area update
    uint32 v_map = GetVirtualMapForMapAndZone(mapid, zone);
    return v_map != 571 || HasSpell(54197); // 54197 = Cold Weather Flying
}

void Player::LearnSpellHighestRank(uint32 spellid)
{
    LearnSpell(spellid, false);

    if (uint32 next = sSpellMgr->GetNextSpellInChain(spellid))
        LearnSpellHighestRank(next);
}

void Player::_LoadSkills(PreparedQueryResult result)
{
    //                                                           0      1      2
    // SetPQuery(PLAYER_LOGIN_QUERY_LOADSKILLS,          "SELECT skill, value, max FROM character_skills WHERE guid = '%u'", GUID_LOPART(m_guid));

    uint32 count = 0;
    uint8 professionCount = 0;
    std::unordered_map<uint32, uint32> loadedSkillValues;
    if (result)
    {
        do
        {
            Field* fields = result->Fetch();
            uint16 skill    = fields[0].GetUInt16();
            uint16 value    = fields[1].GetUInt16();
            uint16 max      = fields[2].GetUInt16();

            SkillRaceClassInfoEntry const* rcEntry = GetSkillRaceClassInfo(skill, getRace(), getClass());
            if (!rcEntry)
            {
                TC_LOG_ERROR("entities.player", "Player::_LoadSkills: Player '%s' (%s, Race: %u, Class: %u) has forbidden skill %u for his race/class combination",
                    GetName().c_str(), GetGUID().ToString().c_str(), uint32(getRace()), uint32(getClass()), skill);

                mSkillStatus.insert(SkillStatusMap::value_type(skill, SkillStatusData(0, SKILL_DELETED)));
                continue;
            }

            // set fixed skill ranges
            switch (GetSkillRangeType(rcEntry))
            {
                case SKILL_RANGE_LANGUAGE:                      // 300..300
                    value = max = 300;
                    break;
                case SKILL_RANGE_MONO:                          // 1..1, grey monolite bar
                    value = max = 1;
                    break;
                case SKILL_RANGE_LEVEL:
                    max = GetMaxSkillValueForLevel();
                default:
                    break;
            }

            if (value == 0)
            {
                TC_LOG_ERROR("entities.player", "Player::_LoadSkills: Player '%s' (%s) has skill %u with value 0, deleted.",
                    GetName().c_str(), GetGUID().ToString().c_str(), skill);

                PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHARACTER_SKILL);

                stmt->setUInt64(0, GetGUID().GetCounter());
                stmt->setUInt16(1, skill);

                CharacterDatabase.Execute(stmt);

                continue;
            }

            uint16 field = count / 2;
            uint8 offset = count & 1;

            SetUInt16Value(PLAYER_SKILL_LINEID + SKILL_ID_OFFSET + field, offset, skill);
            uint16 step = 0;

            SkillLineEntry const* skillLine = sSkillLineStore.LookupEntry(rcEntry->SkillID);
            if (skillLine)
            {
                if (skillLine->CategoryID == SKILL_CATEGORY_SECONDARY)
                    step = max / 75;

                if (skillLine->CategoryID == SKILL_CATEGORY_PROFESSION)
                {
                    step = max / 75;

                    if (professionCount < 2)
                        SetUInt32Value(PLAYER_PROFESSION_SKILL_LINE_1 + professionCount++, skill);
                }
            }

            SetUInt16Value(PLAYER_SKILL_LINEID + SKILL_STEP_OFFSET + field, offset, step);
            SetUInt16Value(PLAYER_SKILL_LINEID + SKILL_RANK_OFFSET + field, offset, value);
            SetUInt16Value(PLAYER_SKILL_LINEID + SKILL_MAX_RANK_OFFSET + field, offset, max);
            SetUInt16Value(PLAYER_SKILL_LINEID + SKILL_TEMP_BONUS_OFFSET + field, offset, 0);
            SetUInt16Value(PLAYER_SKILL_LINEID + SKILL_PERM_BONUS_OFFSET + field, offset, 0);

            mSkillStatus.insert(SkillStatusMap::value_type(skill, SkillStatusData(count, SKILL_UNCHANGED)));
            loadedSkillValues[skill] = value;

            ++count;

            if (count >= PLAYER_MAX_SKILLS)                      // client limit
            {
                TC_LOG_ERROR("entities.player", "Player::_LoadSkills: Player '%s' (%s) has more than %u skills.",
                    GetName().c_str(), GetGUID().ToString().c_str(), PLAYER_MAX_SKILLS);
                break;
            }
        }
        while (result->NextRow());
    }

    // Learn skill rewarded spells after all skills have been loaded to prevent learning a skill from them before its loaded with proper value from DB
    for (auto& skill : loadedSkillValues)
        LearnSkillRewardedSpells(skill.first, skill.second);

    if (HasSkill(SKILL_FIST_WEAPONS))
        SetSkill(SKILL_FIST_WEAPONS, 0, GetSkillValue(SKILL_UNARMED), GetMaxSkillValueForLevel());

    for (; count < PLAYER_MAX_SKILLS; ++count)
    {
        uint16 field = count / 2;
        uint8 offset = count & 1;

        SetUInt16Value(PLAYER_SKILL_LINEID + SKILL_ID_OFFSET + field, offset, 0);
        SetUInt16Value(PLAYER_SKILL_LINEID + SKILL_STEP_OFFSET + field, offset, 0);
        SetUInt16Value(PLAYER_SKILL_LINEID + SKILL_RANK_OFFSET + field, offset, 0);
        SetUInt16Value(PLAYER_SKILL_LINEID + SKILL_MAX_RANK_OFFSET + field, offset, 0);
        SetUInt16Value(PLAYER_SKILL_LINEID + SKILL_TEMP_BONUS_OFFSET + field, offset, 0);
        SetUInt16Value(PLAYER_SKILL_LINEID + SKILL_PERM_BONUS_OFFSET + field, offset, 0);
    }
}

InventoryResult Player::CanEquipUniqueItem(Item* pItem, uint8 eslot, uint32 limit_count) const
{
    ItemTemplate const* pProto = pItem->GetTemplate();

    // proto based limitations
    if (InventoryResult res = CanEquipUniqueItem(pProto, eslot, limit_count))
        return res;

    // check unique-equipped on gems
    for (uint32 enchant_slot = SOCK_ENCHANTMENT_SLOT; enchant_slot < SOCK_ENCHANTMENT_SLOT+3; ++enchant_slot)
    {
        uint32 enchant_id = pItem->GetEnchantmentId(EnchantmentSlot(enchant_slot));
        if (!enchant_id)
            continue;
        SpellItemEnchantmentEntry const* enchantEntry = sSpellItemEnchantmentStore.LookupEntry(enchant_id);
        if (!enchantEntry)
            continue;

        ItemTemplate const* pGem = sObjectMgr->GetItemTemplate(enchantEntry->SRCItemID);
        if (!pGem)
            continue;

        // include for check equip another gems with same limit category for not equipped item (and then not counted)
        uint32 gem_limit_count = !pItem->IsEquipped() && pGem->GetItemLimitCategory()
            ? pItem->GetGemCountWithLimitCategory(pGem->GetItemLimitCategory()) : 1;

        if (InventoryResult res = CanEquipUniqueItem(pGem, eslot, gem_limit_count))
            return res;
    }

    return EQUIP_ERR_OK;
}

InventoryResult Player::CanEquipUniqueItem(ItemTemplate const* itemProto, uint8 except_slot, uint32 limit_count) const
{
    // check unique-equipped on item
    if (itemProto->GetFlags() & ITEM_FLAG_UNIQUE_EQUIPPED)
    {
        // there is an equip limit on this item
        if (HasItemOrGemWithIdEquipped(itemProto->GetId(), 1, except_slot))
            return EQUIP_ERR_ITEM_UNIQUE_EQUIPPABLE;
    }

    // check unique-equipped limit
    if (itemProto->GetItemLimitCategory())
    {
        ItemLimitCategoryEntry const* limitEntry = sItemLimitCategoryStore.LookupEntry(itemProto->GetItemLimitCategory());
        if (!limitEntry)
            return EQUIP_ERR_NOT_EQUIPPABLE;

        // NOTE: limitEntry->mode not checked because if item have have-limit then it applied and to equip case

        if (limit_count > limitEntry->Quantity)
            return EQUIP_ERR_ITEM_MAX_LIMIT_CATEGORY_EQUIPPED_EXCEEDED_IS;

        // there is an equip limit on this item
        if (HasItemOrGemWithLimitCategoryEquipped(itemProto->GetItemLimitCategory(), limitEntry->Quantity - limit_count + 1, except_slot))
            return EQUIP_ERR_ITEM_MAX_COUNT_EQUIPPED_SOCKETED;
    }

    return EQUIP_ERR_OK;
}

void Player::SetFallInformation(uint32 time, float z)
{
    m_lastFallTime = time;
    m_lastFallZ = z;
}

void Player::HandleFall(MovementInfo const& movementInfo)
{
    // calculate total z distance of the fall
    float z_diff = m_lastFallZ - movementInfo.pos.GetPositionZ();
    //TC_LOG_DEBUG("misc", "zDiff = %f", z_diff);

    //Players with low fall distance, Feather Fall or physical immunity (charges used) are ignored
    // 14.57 can be calculated by resolving damageperc formula below to 0
    if (z_diff >= 14.57f && !isDead() && !IsGameMaster() &&
        !HasAuraType(SPELL_AURA_HOVER) && !HasAuraType(SPELL_AURA_FEATHER_FALL) &&
        !HasAuraType(SPELL_AURA_FLY) && !IsImmunedToDamage(SPELL_SCHOOL_MASK_NORMAL))
    {
        //Safe fall, fall height reduction
        int32 safe_fall = GetTotalAuraModifier(SPELL_AURA_SAFE_FALL);

        float damageperc = 0.018f*(z_diff-safe_fall)-0.2426f;

        if (damageperc > 0)
        {
            uint32 damage = (uint32)(damageperc * GetMaxHealth()*sWorld->getRate(RATE_DAMAGE_FALL));

            if (GetCommandStatus(CHEAT_GOD))
                damage = 0;

            float height = movementInfo.pos.m_positionZ;
            UpdateGroundPositionZ(movementInfo.pos.m_positionX, movementInfo.pos.m_positionY, height);

            if (damage > 0)
            {
                //Prevent fall damage from being more than the player maximum health
                if (damage > GetMaxHealth())
                    damage = GetMaxHealth();

                // Gust of Wind
                if (HasAura(43621))
                    damage = GetMaxHealth()/2;

                uint32 original_health = GetHealth();
                uint32 final_damage = EnvironmentalDamage(DAMAGE_FALL, damage);

                // recheck alive, might have died of EnvironmentalDamage, avoid cases when player die in fact like Spirit of Redemption case
                if (IsAlive() && final_damage < original_health)
                    UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_FALL_WITHOUT_DYING, uint32(z_diff*100));
            }

            //Z given by moveinfo, LastZ, FallTime, WaterZ, MapZ, Damage, Safefall reduction
            TC_LOG_DEBUG("entities.player", "FALLDAMAGE z=%f sz=%f pZ=%f FallTime=%d mZ=%f damage=%d SF=%d", movementInfo.pos.GetPositionZ(), height, GetPositionZ(), movementInfo.jump.fallTime, height, damage, safe_fall);
        }
    }
    RemoveAurasWithInterruptFlags(AURA_INTERRUPT_FLAG_LANDING); // No fly zone - Parachute
}

void Player::ResetAchievements()
{
    m_achievementMgr->Reset();
}

void Player::SendRespondInspectAchievements(Player* player) const
{
    m_achievementMgr->SendAchievementInfo(player);
}

uint32 Player::GetAchievementPoints() const
{
    return m_achievementMgr->GetAchievementPoints();
}

bool Player::HasAchieved(uint32 achievementId) const
{
    return m_achievementMgr->HasAchieved(achievementId);
}

void Player::StartTimedAchievement(AchievementCriteriaTimedTypes type, uint32 entry, uint32 timeLost/* = 0*/)
{
    m_achievementMgr->StartTimedAchievement(type, entry, timeLost);
}

void Player::RemoveTimedAchievement(AchievementCriteriaTimedTypes type, uint32 entry)
{
    m_achievementMgr->RemoveTimedAchievement(type, entry);
}

void Player::ResetAchievementCriteria(AchievementCriteriaTypes type, uint64 miscValue1 /*= 0*/, uint64 miscValue2 /*= 0*/, bool evenIfCriteriaComplete /* = false*/)
{
    m_achievementMgr->ResetAchievementCriteria(type, miscValue1, miscValue2, evenIfCriteriaComplete);
}

void Player::UpdateAchievementCriteria(AchievementCriteriaTypes type, uint64 miscValue1 /*= 0*/, uint64 miscValue2 /*= 0*/, uint64 miscValue3 /*= 0*/, Unit* unit /*= NULL*/)
{
    m_achievementMgr->UpdateAchievementCriteria(type, miscValue1, miscValue2, miscValue3, unit, this);
    Guild* guild = sGuildMgr->GetGuildById(GetGuildId());
    if (!guild)
        return;

    // Update only individual achievement criteria here, otherwise we may get multiple updates
    // from a single boss kill
    if (sAchievementMgr->IsGroupCriteriaType(type))
        return;

    guild->UpdateAchievementCriteria(type, miscValue1, miscValue2, miscValue3, unit, this);
}

void Player::CompletedAchievement(AchievementEntry const* entry)
{
    m_achievementMgr->CompletedAchievement(entry, this);
}

bool Player::LearnTalent(uint32 talentId)
{
    TalentEntry const* talentInfo = sTalentStore.LookupEntry(talentId);
    if (!talentInfo)
        return false;

    if (talentInfo->SpecID && talentInfo->SpecID != GetSpecId(GetActiveTalentGroup()))
        return false;

    // prevent learn talent for different class (cheating)
    if (talentInfo->ClassID != getClass())
        return false;

    // check if we have enough talent points
    if (talentInfo->TierID >= GetUInt32Value(PLAYER_FIELD_MAX_TALENT_TIERS))
        return false;

    // Check if there is a different talent for us to learn in selected slot
    // Example situation:
    // Warrior talent row 2 slot 0
    // Talent.dbc has an entry for each specialization
    // but only 2 out of 3 have SpecID != 0
    // We need to make sure that if player is in one of these defined specs he will not learn the other choice
    TalentEntry const* bestSlotMatch = nullptr;
    for (TalentEntry const* talent : sTalentByPos[getClass()][talentInfo->TierID][talentInfo->ColumnIndex])
    {
        if (!talent->SpecID)
            bestSlotMatch = talent;
        else if (talent->SpecID == GetSpecId(GetActiveTalentGroup()))
        {
            bestSlotMatch = talent;
            break;
        }
    }

    if (talentInfo != bestSlotMatch)
        return false;

    // Check if player doesn't have any talent in current tier
    for (uint32 c = 0; c < MAX_TALENT_COLUMNS; ++c)
        for (TalentEntry const* talent : sTalentByPos[getClass()][talentInfo->TierID][c])
            if (HasTalent(talent->ID, GetActiveTalentGroup()))
                return false;

    // spell not set in talent.dbc
    uint32 spellid = talentInfo->SpellID;
    if (!spellid)
    {
        TC_LOG_ERROR("entities.player", "Player::LearnTalent: Talent.dbc has no spellInfo for talent: %u (spell id = 0)", talentId);
        return false;
    }

    // already known
    if (HasTalent(talentId, GetActiveTalentGroup()) || HasSpell(spellid))
        return false;

    if (!AddTalent(talentInfo, GetActiveTalentGroup(), true))
        return false;

    LearnSpell(spellid, false);

    TC_LOG_DEBUG("misc", "Player::LearnTalent: TalentID: %u Spell: %u Group: %u\n", talentId, spellid, GetActiveTalentGroup());

    return true;
}

void Player::LearnTalentSpecialization(uint32 talentSpec)
{
    if (GetSpecId(GetActiveTalentGroup()))
        return;

    SetSpecId(GetActiveTalentGroup(), talentSpec);
    SetUInt32Value(PLAYER_FIELD_CURRENT_SPEC_ID, talentSpec);

    // Reset only talents that have different spells for each spec
    uint32 class_ = getClass();
    for (uint32 t = 0; t < MAX_TALENT_TIERS; ++t)
        for (uint32 c = 0; c < MAX_TALENT_COLUMNS; ++c)
            if (sTalentByPos[class_][t][c].size() > 1)
                for (TalentEntry const* talent : sTalentByPos[class_][t][c])
                    RemoveTalent(talent);

    LearnSpecializationSpells();
    SendTalentsInfoData();
    UpdateItemSetAuras(false);
}

void Player::ResetTalentSpecialization()
{
    if (!GetSpecId(GetActiveTalentGroup()))
        return;

    SetSpecId(GetActiveTalentGroup(), 0);
    SetUInt32Value(PLAYER_FIELD_CURRENT_SPEC_ID, 0);

    // Reset only talents that have different spells for each spec
    uint32 class_ = getClass();
    for (uint32 t = 0; t < MAX_TALENT_TIERS; ++t)
        for (uint32 c = 0; c < MAX_TALENT_COLUMNS; ++c)
            if (sTalentByPos[class_][t][c].size() > 1)
                for (TalentEntry const* talent : sTalentByPos[class_][t][c])
                    RemoveTalent(talent);

    RemoveSpecializationSpells();
    SendTalentsInfoData();
    UpdateItemSetAuras(false);
}

void Player::UpdateFallInformationIfNeed(MovementInfo const& minfo, uint16 opcode)
{
    if (m_lastFallTime >= minfo.jump.fallTime || m_lastFallZ <= minfo.pos.GetPositionZ() || opcode == CMSG_MOVE_FALL_LAND)
        SetFallInformation(minfo.jump.fallTime, minfo.pos.GetPositionZ());
}

void Player::UnsummonPetTemporaryIfAny()
{
    Pet* pet = GetPet();
    if (!pet)
        return;

    if (!m_temporaryUnsummonedPetNumber && pet->isControlled() && !pet->isTemporarySummoned())
    {
        m_temporaryUnsummonedPetNumber = pet->GetCharmInfo()->GetPetNumber();
        m_oldpetspell = pet->GetUInt32Value(UNIT_CREATED_BY_SPELL);
    }

    RemovePet(pet, PET_SAVE_AS_CURRENT);
}

void Player::ResummonPetTemporaryUnSummonedIfAny()
{
    if (!m_temporaryUnsummonedPetNumber)
        return;

    // not resummon in not appropriate state
    if (IsPetNeedBeTemporaryUnsummoned())
        return;

    if (!GetPetGUID().IsEmpty())
        return;

    Pet* NewPet = new Pet(this);
    if (!NewPet->LoadPetFromDB(this, 0, m_temporaryUnsummonedPetNumber, true))
        delete NewPet;

    m_temporaryUnsummonedPetNumber = 0;
}

bool Player::IsPetNeedBeTemporaryUnsummoned() const
{
    return !IsInWorld() || !IsAlive() || IsMounted() /*+in flight*/;
}

bool Player::CanSeeSpellClickOn(Creature const* c) const
{
    if (!c->HasFlag64(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_SPELLCLICK))
        return false;

    SpellClickInfoMapBounds clickPair = sObjectMgr->GetSpellClickInfoMapBounds(c->GetEntry());
    if (clickPair.first == clickPair.second)
        return true;

    for (SpellClickInfoContainer::const_iterator itr = clickPair.first; itr != clickPair.second; ++itr)
    {
        if (!itr->second.IsFitToRequirements(this, c))
            return false;

        if (sConditionMgr->IsObjectMeetingSpellClickConditions(c->GetEntry(), itr->second.spellId, const_cast<Player*>(this), const_cast<Creature*>(c)))
            return true;
    }

    return false;
}

void Player::SendTalentsInfoData()
{
    WorldPackets::Talent::UpdateTalentData packet;

    packet.Info.ActiveGroup = GetActiveTalentGroup();

    uint8 groupsCount = GetTalentGroupsCount();

    for (uint8 i = 0; i < groupsCount; ++i)
    {
        WorldPackets::Talent::TalentGroupInfo groupInfoPkt;

        groupInfoPkt.SpecID = GetSpecId(i);
        groupInfoPkt.TalentIDs.reserve(GetTalentMap(i)->size());

        for (PlayerTalentMap::const_iterator itr = GetTalentMap(i)->begin(); itr != GetTalentMap(i)->end(); ++itr)
        {
            if (itr->second == PLAYERSPELL_REMOVED)
                continue;

            TalentEntry const* talentInfo = sTalentStore.LookupEntry(itr->first);
            if (!talentInfo)
            {
                TC_LOG_ERROR("entities.player", "Player::SendTalentsInfoData: Player '%s' (%s) has unknown talent id: %u",
                    GetName().c_str(), GetGUID().ToString().c_str(), itr->first);
                continue;
            }

            if (talentInfo->ClassID != getClass())
                continue;

            SpellInfo const* spellEntry = sSpellMgr->GetSpellInfo(talentInfo->SpellID);
            if (!spellEntry)
            {
                TC_LOG_ERROR("entities.player", "Player::SendTalentsInfoData: Player '%s' (%s) has unknown talent spell: %u",
                    GetName().c_str(), GetGUID().ToString().c_str(), talentInfo->SpellID);
                continue;
            }

            groupInfoPkt.TalentIDs.push_back(uint16(itr->first));
        }

        for (uint32 x = 0; x < MAX_GLYPH_SLOT_INDEX; ++x)
            groupInfoPkt.GlyphIDs[x] = uint16(GetGlyph(i, x));

        packet.Info.TalentGroups.push_back(groupInfoPkt);
    }

    SendDirectMessage(packet.Write());
}

void Player::SendEquipmentSetList()
{
    WorldPackets::EquipmentSet::LoadEquipmentSet data;

    for (EquipmentSetContainer::value_type const& eqSet : _equipmentSets)
    {
        if (eqSet.second.State == EQUIPMENT_SET_DELETED)
            continue;

        data.SetData.push_back(&eqSet.second.Data);
    }

    SendDirectMessage(data.Write());
}

void Player::SetEquipmentSet(EquipmentSetInfo::EquipmentSetData&& newEqSet)
{
    if (newEqSet.Guid != 0)
    {
        // something wrong...
        EquipmentSetContainer::const_iterator itr = _equipmentSets.find(newEqSet.SetID);
        if (itr == _equipmentSets.end() || itr->second.Data.Guid != newEqSet.Guid)
        {
            TC_LOG_ERROR("entities.player", "Player::SetEquipmentSet: Player '%s' (%s) tried to save nonexistent equipment set " UI64FMTD " (index: %u)",
                GetName().c_str(), GetGUID().ToString().c_str(), newEqSet.Guid, newEqSet.SetID);
            return;
        }
    }

    EquipmentSetInfo& eqSlot = _equipmentSets[newEqSet.SetID];

    EquipmentSetUpdateState oldState = eqSlot.State;

    eqSlot.Data = newEqSet;

    if (eqSlot.Data.Guid == 0)
    {
        eqSlot.Data.Guid = sObjectMgr->GenerateEquipmentSetGuid();

        WorldPackets::EquipmentSet::EquipmentSetID data;
        data.GUID = eqSlot.Data.Guid;
        data.SetID = eqSlot.Data.SetID;
        SendDirectMessage(data.Write());
    }

    eqSlot.State = oldState == EQUIPMENT_SET_NEW ? EQUIPMENT_SET_NEW : EQUIPMENT_SET_CHANGED;
}

void Player::_SaveEquipmentSets(SQLTransaction& trans)
{
    for (EquipmentSetContainer::iterator itr = _equipmentSets.begin(); itr != _equipmentSets.end();)
    {
        EquipmentSetInfo& eqSet = itr->second;
        PreparedStatement* stmt;
        uint8 j = 0;
        switch (eqSet.State)
        {
            case EQUIPMENT_SET_UNCHANGED:
                ++itr;
                break;                                      // nothing do
            case EQUIPMENT_SET_CHANGED:
                stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_EQUIP_SET);
                stmt->setString(j++, eqSet.Data.SetName);
                stmt->setString(j++, eqSet.Data.SetIcon);
                stmt->setUInt32(j++, eqSet.Data.IgnoreMask);

                for (uint8 i = 0; i < EQUIPMENT_SLOT_END; ++i)
                    stmt->setUInt64(j++, eqSet.Data.Pieces[i].GetCounter());

                stmt->setUInt64(j++, GetGUID().GetCounter());
                stmt->setUInt64(j++, eqSet.Data.Guid);
                stmt->setUInt32(j, eqSet.Data.SetID);
                trans->Append(stmt);
                eqSet.State = EQUIPMENT_SET_UNCHANGED;
                ++itr;
                break;
            case EQUIPMENT_SET_NEW:
                stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_EQUIP_SET);
                stmt->setUInt64(j++, GetGUID().GetCounter());
                stmt->setUInt64(j++, eqSet.Data.Guid);
                stmt->setUInt32(j++, eqSet.Data.SetID);
                stmt->setString(j++, eqSet.Data.SetName);
                stmt->setString(j++, eqSet.Data.SetIcon);
                stmt->setUInt32(j++, eqSet.Data.IgnoreMask);

                for (uint8 i = 0; i < EQUIPMENT_SLOT_END; ++i)
                    stmt->setUInt64(j++, eqSet.Data.Pieces[i].GetCounter());

                trans->Append(stmt);
                eqSet.State = EQUIPMENT_SET_UNCHANGED;
                ++itr;
                break;
            case EQUIPMENT_SET_DELETED:
                stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_EQUIP_SET);
                stmt->setUInt64(0, eqSet.Data.Guid);
                trans->Append(stmt);
                itr = _equipmentSets.erase(itr);
                break;
        }
    }
}

void Player::_SaveBGData(SQLTransaction& trans)
{
    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_PLAYER_BGDATA);
    stmt->setUInt64(0, GetGUID().GetCounter());
    trans->Append(stmt);
    /* guid, bgInstanceID, bgTeam, x, y, z, o, map, taxi[0], taxi[1], mountSpell */
    stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_PLAYER_BGDATA);
    stmt->setUInt64(0, GetGUID().GetCounter());
    stmt->setUInt32(1, m_bgData.bgInstanceID);
    stmt->setUInt16(2, m_bgData.bgTeam);
    stmt->setFloat (3, m_bgData.joinPos.GetPositionX());
    stmt->setFloat (4, m_bgData.joinPos.GetPositionY());
    stmt->setFloat (5, m_bgData.joinPos.GetPositionZ());
    stmt->setFloat (6, m_bgData.joinPos.GetOrientation());
    stmt->setUInt16(7, m_bgData.joinPos.GetMapId());
    stmt->setUInt16(8, m_bgData.taxiPath[0]);
    stmt->setUInt16(9, m_bgData.taxiPath[1]);
    stmt->setUInt16(10, m_bgData.mountSpell);
    trans->Append(stmt);
}

void Player::DeleteEquipmentSet(uint64 id)
{
    for (EquipmentSetContainer::iterator itr = _equipmentSets.begin(); itr != _equipmentSets.end();)
    {
        if (itr->second.Data.Guid == id)
        {
            if (itr->second.State == EQUIPMENT_SET_NEW)
                itr = _equipmentSets.erase(itr);
            else
                itr->second.State = EQUIPMENT_SET_DELETED;
            break;
        }
        ++itr;
    }
}

void Player::RemoveAtLoginFlag(AtLoginFlags flags, bool persist /*= false*/)
{
    m_atLoginFlags &= ~flags;

    if (persist)
    {
        PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_REM_AT_LOGIN_FLAG);

        stmt->setUInt16(0, uint16(flags));
        stmt->setUInt64(1, GetGUID().GetCounter());

        CharacterDatabase.Execute(stmt);
    }
}

void Player::ResetMap()
{
    // this may be called during Map::Update
    // after decrement+unlink, ++m_mapRefIter will continue correctly
    // when the first element of the list is being removed
    // nocheck_prev will return the padding element of the RefManager
    // instead of NULL in the case of prev
    GetMap()->UpdateIteratorBack(this);
    Unit::ResetMap();
    GetMapRef().unlink();
}

void Player::SetMap(Map* map)
{
    Unit::SetMap(map);
    m_mapRef.link(map, this);
}

void Player::_LoadGlyphs(PreparedQueryResult result)
{
    // SELECT group, glyph1, glyph2, glyph3, glyph4, glyph5, glyph6, glyph7, glyph8, glyph9 FROM character_glyphs WHERE guid = '%u'
    if (!result)
        return;

    do
    {
        Field* fields = result->Fetch();

        uint8 group = fields[0].GetUInt8();
        if (group >= GetTalentGroupsCount())
            continue;

        for (uint8 i = 0; i < MAX_GLYPH_SLOT_INDEX; ++i)
            _talentMgr->GroupInfo[group].Glyphs[i] = fields[i + 1].GetUInt16();
    }
    while (result->NextRow());
}

void Player::_SaveGlyphs(SQLTransaction& trans) const
{
    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHAR_GLYPHS);
    stmt->setUInt64(0, GetGUID().GetCounter());
    trans->Append(stmt);

    for (uint8 group = 0; group < GetTalentGroupsCount(); ++group)
    {
        uint8 index = 0;

        stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_CHAR_GLYPHS);
        stmt->setUInt64(index++, GetGUID().GetCounter());

        stmt->setUInt8(index++, group);

        for (uint8 i = 0; i < MAX_GLYPH_SLOT_INDEX; ++i)
            stmt->setUInt16(index++, uint16(GetGlyph(group, i)));

        trans->Append(stmt);
    }
}

void Player::_LoadTalents(PreparedQueryResult result)
{
    // SetPQuery(PLAYER_LOGIN_QUERY_LOADTALENTS, "SELECT spell, spec FROM character_talent WHERE guid = '%u'", GUID_LOPART(m_guid));
    if (result)
    {
        do
            if (TalentEntry const* talent = sTalentStore.LookupEntry((*result)[0].GetUInt32()))
                AddTalent(talent, (*result)[1].GetUInt8(), false);
        while (result->NextRow());
    }
}

void Player::_SaveTalents(SQLTransaction& trans)
{
    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHAR_TALENT);
    stmt->setUInt64(0, GetGUID().GetCounter());
    trans->Append(stmt);

    PlayerTalentMap* talents;
    for (uint8 group = 0; group < MAX_TALENT_GROUPS; ++group)
    {
        talents = GetTalentMap(group);
        for (PlayerTalentMap::iterator itr = talents->begin(); itr != talents->end();)
        {
            if (itr->second == PLAYERSPELL_REMOVED)
            {
                itr = talents->erase(itr);
                continue;
            }

            stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_CHAR_TALENT);
            stmt->setUInt64(0, GetGUID().GetCounter());
            stmt->setUInt32(1, itr->first);
            stmt->setUInt8(2, group);
            trans->Append(stmt);
            ++itr;
        }
    }
}

void Player::UpdateTalentGroupCount(uint8 count)
{
    uint32 curCount = GetTalentGroupsCount();
    if (curCount == count)
        return;

    if (GetActiveTalentGroup() >= count)
        ActivateTalentGroup(0);

    SQLTransaction trans = CharacterDatabase.BeginTransaction();
    PreparedStatement* stmt;

    // Copy spec data
    if (count > curCount)
    {
        _SaveActions(trans); // make sure the button list is cleaned up
        for (ActionButtonList::iterator itr = m_actionButtons.begin(); itr != m_actionButtons.end(); ++itr)
        {
            stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_CHAR_ACTION);
            stmt->setUInt64(0, GetGUID().GetCounter());
            stmt->setUInt8(1, 1);
            stmt->setUInt8(2, itr->first);
            stmt->setUInt32(3, itr->second.GetAction());
            stmt->setUInt8(4, uint8(itr->second.GetType()));
            trans->Append(stmt);
        }
    }
    // Delete spec data for removed spec.
    else if (count < curCount)
    {
        _SaveActions(trans);

        stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHAR_ACTION_EXCEPT_SPEC);
        stmt->setUInt8(0, GetActiveTalentGroup());
        stmt->setUInt64(1, GetGUID().GetCounter());
        trans->Append(stmt);

    }

    CharacterDatabase.CommitTransaction(trans);

    SetTalentGroupsCount(count);

    SendTalentsInfoData();
}

void Player::ActivateTalentGroup(uint8 spec)
{
    if (GetActiveTalentGroup() == spec)
        return;

    if (spec > GetTalentGroupsCount())
        return;

    if (IsNonMeleeSpellCast(false))
        InterruptNonMeleeSpells(false);

    SQLTransaction trans = CharacterDatabase.BeginTransaction();
    _SaveActions(trans);
    CharacterDatabase.CommitTransaction(trans);

    // TO-DO: We need more research to know what happens with warlock's reagent
    if (Pet* pet = GetPet())
        RemovePet(pet, PET_SAVE_NOT_IN_SLOT);

    ClearAllReactives();
    UnsummonAllTotems();
    ExitVehicle();
    RemoveAllControlled();
    /*RemoveAllAurasOnDeath();
    if (GetPet())
        GetPet()->RemoveAllAurasOnDeath();*/

    //RemoveAllAuras(GetGUID(), NULL, false, true); // removes too many auras
    //ExitVehicle(); // should be impossible to switch specs from inside a vehicle..

    // Let client clear his current Actions
    SendActionButtons(2);
    // m_actionButtons.clear() is called in the next _LoadActionButtons
    for (uint32 talentId = 0; talentId < sTalentStore.GetNumRows(); ++talentId)
    {
        TalentEntry const* talentInfo = sTalentStore.LookupEntry(talentId);
        if (!talentInfo)
            continue;

        // unlearn only talents for character class
        // some spell learned by one class as normal spells or know at creation but another class learn it as talent,
        // to prevent unexpected lost normal learned spell skip another class talents
        if (talentInfo->ClassID != getClass())
            continue;

        if (talentInfo->SpellID == 0)
            continue;

        SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(talentInfo->SpellID);
        if (!spellInfo)
            continue;

        RemoveSpell(talentInfo->SpellID, true);

        // search for spells that the talent teaches and unlearn them
        for (SpellEffectInfo const* effect : spellInfo->GetEffectsForDifficulty(DIFFICULTY_NONE))
            if (effect && effect->TriggerSpell > 0 && effect->Effect == SPELL_EFFECT_LEARN_SPELL)
                RemoveSpell(effect->TriggerSpell, true);

        if (talentInfo->OverridesSpellID)
            RemoveOverrideSpell(talentInfo->OverridesSpellID, talentInfo->SpellID);
    }

    // Remove spec specific spells
    RemoveSpecializationSpells();

    // set glyphs
    for (uint8 slot = 0; slot < MAX_GLYPH_SLOT_INDEX; ++slot)
        // remove secondary glyph
        if (uint32 oldglyph = GetGlyph(GetActiveTalentGroup(), slot))
            if (GlyphPropertiesEntry const* old_gp = sGlyphPropertiesStore.LookupEntry(oldglyph))
                RemoveAurasDueToSpell(old_gp->SpellID);

    SetActiveTalentGroup(spec);
    SetUInt32Value(PLAYER_FIELD_CURRENT_SPEC_ID, GetSpecId(spec));

    for (uint32 talentId = 0; talentId < sTalentStore.GetNumRows(); ++talentId)
    {
        TalentEntry const* talentInfo = sTalentStore.LookupEntry(talentId);
        if (!talentInfo)
            continue;

        // learn only talents for character class
        if (talentInfo->ClassID != getClass())
            continue;

        if (!talentInfo->SpellID)
            continue;

        // if the talent can be found in the newly activated PlayerTalentMap
        if (HasTalent(talentInfo->ID, GetActiveTalentGroup()))
        {
            LearnSpell(talentInfo->SpellID, false);      // add the talent to the PlayerSpellMap
            if (talentInfo->OverridesSpellID)
                AddOverrideSpell(talentInfo->OverridesSpellID, talentInfo->SpellID);
        }
    }

    LearnSpecializationSpells();

    if (CanUseMastery())
        if (ChrSpecializationEntry const* specialization = sChrSpecializationStore.LookupEntry(GetSpecId(GetActiveTalentGroup())))
            for (uint32 i = 0; i < MAX_MASTERY_SPELLS; ++i)
                if (uint32 mastery = specialization->MasterySpellID[i])
                    LearnSpell(mastery, false);

    // set glyphs
    for (uint8 slot = 0; slot < MAX_GLYPH_SLOT_INDEX; ++slot)
    {
        uint32 glyph = GetGlyph(GetActiveTalentGroup(), slot);

        // apply primary glyph
        if (glyph)
            if (GlyphPropertiesEntry const* gp = sGlyphPropertiesStore.LookupEntry(glyph))
                CastSpell(this, gp->SpellID, true);

        SetGlyph(slot, glyph);
    }

    InitTalentForLevel();

    {
        PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHARACTER_ACTIONS_SPEC);
        stmt->setUInt64(0, GetGUID().GetCounter());
        stmt->setUInt8(1, GetActiveTalentGroup());
        if (PreparedQueryResult result = CharacterDatabase.Query(stmt))
            _LoadActions(result);
    }

    SendActionButtons(1);

    Powers pw = getPowerType();
    if (pw != POWER_MANA)
        SetPower(POWER_MANA, 0); // Mana must be 0 even if it isn't the active power type.

    SetPower(pw, 0);
    UpdateItemSetAuras(false);

    if (!sChrSpecializationStore.LookupEntry(GetSpecId(GetActiveTalentGroup())))
        ResetTalents(true);
}

void Player::ResetTimeSync()
{
    m_timeSyncTimer = 0;
    m_timeSyncClient = 0;
    m_timeSyncServer = getMSTime();
}

void Player::SendTimeSync()
{
    m_timeSyncQueue.push(m_movementCounter++);

    WorldPackets::Misc::TimeSyncRequest packet;
    packet.SequenceIndex = m_timeSyncQueue.back();
    SendDirectMessage(packet.Write());

    // Schedule next sync in 10 sec
    m_timeSyncTimer = 10000;
    m_timeSyncServer = getMSTime();

    if (m_timeSyncQueue.size() > 3)
        TC_LOG_ERROR("network", "Player::SendTimeSync: Did not receive CMSG_TIME_SYNC_RESP for over 30 seconds from '%s' (%s), possible cheater",
            GetName().c_str(), GetGUID().ToString().c_str());
}

void Player::SetReputation(uint32 factionentry, uint32 value)
{
    GetReputationMgr().SetReputation(sFactionStore.LookupEntry(factionentry), value);
}
uint32 Player::GetReputation(uint32 factionentry) const
{
    return GetReputationMgr().GetReputation(sFactionStore.LookupEntry(factionentry));
}

std::string Player::GetGuildName() const
{
    return GetGuildId() ? sGuildMgr->GetGuildById(GetGuildId())->GetName() : "";
}

void Player::AddRefundReference(ObjectGuid it)
{
    m_refundableItems.insert(it);
}

void Player::DeleteRefundReference(ObjectGuid it)
{
    GuidSet::iterator itr = m_refundableItems.find(it);
    if (itr != m_refundableItems.end())
        m_refundableItems.erase(itr);
}

void Player::SendRefundInfo(Item* item)
{
    // This function call unsets ITEM_FIELD_FLAG_REFUNDABLE if played time is over 2 hours.
    item->UpdatePlayedTime(this);

    if (!item->HasFlag(ITEM_FIELD_FLAGS, ITEM_FIELD_FLAG_REFUNDABLE))
    {
        TC_LOG_DEBUG("entities.player.items", "Item refund: item not refundable!");
        return;
    }

    if (GetGUID() != item->GetRefundRecipient()) // Formerly refundable item got traded
    {
        TC_LOG_DEBUG("entities.player.items", "Item refund: item was traded!");
        item->SetNotRefundable(this);
        return;
    }

    ItemExtendedCostEntry const* iece = sItemExtendedCostStore.LookupEntry(item->GetPaidExtendedCost());
    if (!iece)
    {
        TC_LOG_DEBUG("entities.player.items", "Item refund: cannot find extendedcost data.");
        return;
    }

    WorldPackets::Item::SetItemPurchaseData setItemPurchaseData;
    setItemPurchaseData.ItemGUID = item->GetGUID();
    setItemPurchaseData.PurchaseTime = GetTotalPlayedTime() - item->GetPlayedTime();
    setItemPurchaseData.Contents.Money = item->GetPaidMoney();

    for (uint8 i = 0; i < MAX_ITEM_EXT_COST_ITEMS; ++i)                             // item cost data
    {
        setItemPurchaseData.Contents.Items[i].ItemCount = iece->RequiredItemCount[i];
        setItemPurchaseData.Contents.Items[i].ItemID = iece->RequiredItem[i];
    }

    for (uint8 i = 0; i < MAX_ITEM_EXT_COST_CURRENCIES; ++i)                        // currency cost data
    {
        if (iece->RequirementFlags & (ITEM_EXT_COST_CURRENCY_REQ_IS_SEASON_EARNED_1 << i))
            continue;

        setItemPurchaseData.Contents.Currencies[i].CurrencyCount = iece->RequiredCurrencyCount[i];
        setItemPurchaseData.Contents.Currencies[i].CurrencyID = iece->RequiredCurrency[i];
    }

    GetSession()->SendPacket(setItemPurchaseData.Write());
}

bool Player::AddItem(uint32 itemId, uint32 count)
{
    uint32 noSpaceForCount = 0;
    ItemPosCountVec dest;
    InventoryResult msg = CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, itemId, count, &noSpaceForCount);
    if (msg != EQUIP_ERR_OK)
        count -= noSpaceForCount;

    if (count == 0 || dest.empty())
    {
        /// @todo Send to mailbox if no space
        ChatHandler(GetSession()).PSendSysMessage("You don't have any space in your bags.");
        return false;
    }

    Item* item = StoreNewItem(dest, itemId, true, Item::GenerateItemRandomPropertyId(itemId));
    if (item)
        SendNewItem(item, count, true, false);
    else
        return false;
    return true;
}

void Player::SendItemRefundResult(Item* item, ItemExtendedCostEntry const* iece, uint8 error) const
{
    WorldPackets::Item::ItemPurchaseRefundResult itemPurchaseRefundResult;
    itemPurchaseRefundResult.ItemGUID = item->GetGUID();
    itemPurchaseRefundResult.Result = error;
    if (!error)
    {
        itemPurchaseRefundResult.Contents = boost::in_place();
        itemPurchaseRefundResult.Contents->Money = item->GetPaidMoney();
        for (uint8 i = 0; i < MAX_ITEM_EXT_COST_ITEMS; ++i)                             // item cost data
        {
            itemPurchaseRefundResult.Contents->Items[i].ItemCount = iece->RequiredItemCount[i];
            itemPurchaseRefundResult.Contents->Items[i].ItemID = iece->RequiredItem[i];
        }

        for (uint8 i = 0; i < MAX_ITEM_EXT_COST_CURRENCIES; ++i)                        // currency cost data
        {
            if (iece->RequirementFlags & (ITEM_EXT_COST_CURRENCY_REQ_IS_SEASON_EARNED_1 << i))
                continue;

            itemPurchaseRefundResult.Contents->Currencies[i].CurrencyCount = iece->RequiredCurrencyCount[i];
            itemPurchaseRefundResult.Contents->Currencies[i].CurrencyID = iece->RequiredCurrency[i];
        }
    }

    GetSession()->SendPacket(itemPurchaseRefundResult.Write());
}

void Player::RefundItem(Item* item)
{
    if (!item->HasFlag(ITEM_FIELD_FLAGS, ITEM_FIELD_FLAG_REFUNDABLE))
    {
        TC_LOG_DEBUG("entities.player.items", "Item refund: item not refundable!");
        return;
    }

    if (item->IsRefundExpired())    // item refund has expired
    {
        item->SetNotRefundable(this);
        SendItemRefundResult(item, nullptr, 10);
        return;
    }

    if (GetGUID() != item->GetRefundRecipient()) // Formerly refundable item got traded
    {
        TC_LOG_DEBUG("entities.player.items", "Item refund: item was traded!");
        item->SetNotRefundable(this);
        return;
    }

    ItemExtendedCostEntry const* iece = sItemExtendedCostStore.LookupEntry(item->GetPaidExtendedCost());
    if (!iece)
    {
        TC_LOG_DEBUG("entities.player.items", "Item refund: cannot find extendedcost data.");
        return;
    }

    bool store_error = false;
    for (uint8 i = 0; i < MAX_ITEM_EXT_COST_ITEMS; ++i)
    {
        uint32 count = iece->RequiredItemCount[i];
        uint32 itemid = iece->RequiredItem[i];

        if (count && itemid)
        {
            ItemPosCountVec dest;
            InventoryResult msg = CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, itemid, count);
            if (msg != EQUIP_ERR_OK)
            {
                store_error = true;
                break;
            }
         }
    }

    if (store_error)
    {
        SendItemRefundResult(item, iece, 10);
        return;
    }

    SendItemRefundResult(item, iece, 0);

    uint32 moneyRefund = item->GetPaidMoney();  // item-> will be invalidated in DestroyItem

    // Save all relevant data to DB to prevent desynchronisation exploits
    SQLTransaction trans = CharacterDatabase.BeginTransaction();

    // Delete any references to the refund data
    item->SetNotRefundable(this, true, &trans);

    // Destroy item
    DestroyItem(item->GetBagSlot(), item->GetSlot(), true);

    // Grant back extendedcost items
    for (uint8 i = 0; i < MAX_ITEM_EXT_COST_ITEMS; ++i)
    {
        uint32 count = iece->RequiredItemCount[i];
        uint32 itemid = iece->RequiredItem[i];
        if (count && itemid)
        {
            ItemPosCountVec dest;
            InventoryResult msg = CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, itemid, count);
            ASSERT(msg == EQUIP_ERR_OK); /// Already checked before
            Item* it = StoreNewItem(dest, itemid, true);
            SendNewItem(it, count, true, false, true);
        }
    }

    // Grant back currencies
    for (uint8 i = 0; i < MAX_ITEM_EXT_COST_CURRENCIES; ++i)
    {
        if (iece->RequirementFlags & (ITEM_EXT_COST_CURRENCY_REQ_IS_SEASON_EARNED_1 << i))
            continue;

        uint32 count = iece->RequiredCurrencyCount[i];
        uint32 currencyid = iece->RequiredCurrency[i];
        if (count && currencyid)
            ModifyCurrency(currencyid, count, true, true);
    }

    // Grant back money
    if (moneyRefund)
        ModifyMoney(moneyRefund); // Saved in SaveInventoryAndGoldToDB

    SaveInventoryAndGoldToDB(trans);

    CharacterDatabase.CommitTransaction(trans);
}

void Player::SendItemRetrievalMail(uint32 itemEntry, uint32 count)
{
    MailSender sender(MAIL_CREATURE, UI64LIT(34337) /* The Postmaster */);
    MailDraft draft("Recovered Item", "We recovered a lost item in the twisting nether and noted that it was yours.$B$BPlease find said object enclosed."); // This is the text used in Cataclysm, it probably wasn't changed.
    SQLTransaction trans = CharacterDatabase.BeginTransaction();

    if (Item* item = Item::CreateItem(itemEntry, count, nullptr))
    {
        item->SaveToDB(trans);
        draft.AddItem(item);
    }

    draft.SendMailTo(trans, MailReceiver(this, GetGUID().GetCounter()), sender);
    CharacterDatabase.CommitTransaction(trans);
}

void Player::SetRandomWinner(bool isWinner)
{
    m_IsBGRandomWinner = isWinner;
    if (m_IsBGRandomWinner)
    {
        PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_BATTLEGROUND_RANDOM);

        stmt->setUInt64(0, GetGUID().GetCounter());

        CharacterDatabase.Execute(stmt);
    }
}

void Player::_LoadRandomBGStatus(PreparedQueryResult result)
{
    //QueryResult result = CharacterDatabase.PQuery("SELECT guid FROM character_battleground_random WHERE guid = '%u'", GetGUIDLow());

    if (result)
        m_IsBGRandomWinner = true;
}

float Player::GetAverageItemLevel() const
{
    float sum = 0;
    uint32 count = 0;

    for (int i = EQUIPMENT_SLOT_START; i < EQUIPMENT_SLOT_END; ++i)
    {
        // don't check tabard, ranged, offhand or shirt
        if (i == EQUIPMENT_SLOT_TABARD || i == EQUIPMENT_SLOT_RANGED || i == EQUIPMENT_SLOT_OFFHAND || i == EQUIPMENT_SLOT_BODY)
            continue;

        if (m_items[i] && m_items[i]->GetTemplate())
            sum += m_items[i]->GetItemLevel(this);

        ++count;
    }

    return ((float)sum) / count;
}

void Player::_LoadInstanceTimeRestrictions(PreparedQueryResult result)
{
    if (!result)
        return;

    do
    {
        Field* fields = result->Fetch();
        _instanceResetTimes.insert(InstanceTimeMap::value_type(fields[0].GetUInt32(), fields[1].GetUInt64()));
    } while (result->NextRow());
}

void Player::_SaveInstanceTimeRestrictions(SQLTransaction& trans)
{
    if (_instanceResetTimes.empty())
        return;

    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_ACCOUNT_INSTANCE_LOCK_TIMES);
    stmt->setUInt32(0, GetSession()->GetAccountId());
    trans->Append(stmt);

    for (InstanceTimeMap::const_iterator itr = _instanceResetTimes.begin(); itr != _instanceResetTimes.end(); ++itr)
    {
        stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_ACCOUNT_INSTANCE_LOCK_TIMES);
        stmt->setUInt32(0, GetSession()->GetAccountId());
        stmt->setUInt32(1, itr->first);
        stmt->setUInt64(2, itr->second);
        trans->Append(stmt);
    }
}

bool Player::IsInWhisperWhiteList(ObjectGuid guid)
{
    for (GuidList::const_iterator itr = WhisperList.begin(); itr != WhisperList.end(); ++itr)
        if (*itr == guid)
            return true;

    return false;
}

uint8 Player::GetNextVoidStorageFreeSlot() const
{
    for (uint8 i = 0; i < VOID_STORAGE_MAX_SLOT; ++i)
        if (!_voidStorageItems[i]) // unused item
            return i;

    return VOID_STORAGE_MAX_SLOT;
}

uint8 Player::GetNumOfVoidStorageFreeSlots() const
{
    uint8 count = 0;

    for (uint8 i = 0; i < VOID_STORAGE_MAX_SLOT; ++i)
        if (!_voidStorageItems[i])
            count++;

    return count;
}

uint8 Player::AddVoidStorageItem(VoidStorageItem&& item)
{
    uint8 slot = GetNextVoidStorageFreeSlot();

    if (slot >= VOID_STORAGE_MAX_SLOT)
    {
        GetSession()->SendVoidStorageTransferResult(VOID_TRANSFER_ERROR_FULL);
        return 255;
    }

    _voidStorageItems[slot] = new VoidStorageItem(std::move(item));
    return slot;
}

void Player::DeleteVoidStorageItem(uint8 slot)
{
    if (slot >= VOID_STORAGE_MAX_SLOT)
    {
        GetSession()->SendVoidStorageTransferResult(VOID_TRANSFER_ERROR_INTERNAL_ERROR_1);
        return;
    }

    delete _voidStorageItems[slot];
    _voidStorageItems[slot] = nullptr;
}

bool Player::SwapVoidStorageItem(uint8 oldSlot, uint8 newSlot)
{
    if (oldSlot >= VOID_STORAGE_MAX_SLOT || newSlot >= VOID_STORAGE_MAX_SLOT || oldSlot == newSlot)
        return false;

    std::swap(_voidStorageItems[newSlot], _voidStorageItems[oldSlot]);
    return true;
}

VoidStorageItem* Player::GetVoidStorageItem(uint8 slot) const
{
    if (slot >= VOID_STORAGE_MAX_SLOT)
    {
        GetSession()->SendVoidStorageTransferResult(VOID_TRANSFER_ERROR_INTERNAL_ERROR_1);
        return nullptr;
    }

    return _voidStorageItems[slot];
}

VoidStorageItem* Player::GetVoidStorageItem(uint64 id, uint8& slot) const
{
    for (uint8 i = 0; i < VOID_STORAGE_MAX_SLOT; ++i)
    {
        if (_voidStorageItems[i] && _voidStorageItems[i]->ItemId == id)
        {
            slot = i;
            return _voidStorageItems[i];
        }
    }

    return nullptr;
}

void Player::OnCombatExit()
{
    UpdatePotionCooldown();
    if (getClass() == CLASS_PALADIN)
        m_holyPowerRegenTimerCount = 20000; // first charge of holy power decays 20 seconds after leaving combat
}

void Player::CreateGarrison(uint32 garrSiteId)
{
    std::unique_ptr<Garrison> garrison(new Garrison(this));
    if (garrison->Create(garrSiteId))
        _garrison = std::move(garrison);
}

void Player::DeleteGarrison()
{
    if (_garrison)
    {
        _garrison->Delete();
        _garrison.reset();
    }
}

void Player::SendMovementSetCanTransitionBetweenSwimAndFly(bool apply)
{
    WorldPackets::Movement::MoveSetFlag packet(apply ? SMSG_MOVE_ENABLE_TRANSITION_BETWEEN_SWIM_AND_FLY : SMSG_MOVE_DISABLE_TRANSITION_BETWEEN_SWIM_AND_FLY);
    packet.MoverGUID = GetGUID();
    packet.SequenceIndex = m_movementCounter++;
    SendMessageToSet(packet.Write(), true);
}

void Player::SendMovementSetCollisionHeight(float height)
{
    WorldPackets::Movement::MoveSetCollisionHeight setCollisionHeight;
    setCollisionHeight.MoverGUID = GetGUID();
    setCollisionHeight.SequenceIndex = m_movementCounter++;
    setCollisionHeight.Height = height;
    setCollisionHeight.Scale = GetObjectScale();
    setCollisionHeight.MountDisplayID = GetUInt32Value(UNIT_FIELD_MOUNTDISPLAYID);
    setCollisionHeight.Reason = WorldPackets::Movement::UPDATE_COLLISION_HEIGHT_MOUNT;
    SendDirectMessage(setCollisionHeight.Write());

    WorldPackets::Movement::MoveUpdateCollisionHeight updateCollisionHeight;
    updateCollisionHeight.movementInfo = &m_movementInfo;
    updateCollisionHeight.Height = height;
    updateCollisionHeight.Scale = GetObjectScale();
    SendMessageToSet(updateCollisionHeight.Write(), false);
}

float Player::GetCollisionHeight(bool mounted) const
{
    if (mounted)
    {
        CreatureDisplayInfoEntry const* mountDisplayInfo = sCreatureDisplayInfoStore.LookupEntry(GetUInt32Value(UNIT_FIELD_MOUNTDISPLAYID));
        if (!mountDisplayInfo)
            return GetCollisionHeight(false);

        CreatureModelDataEntry const* mountModelData = sCreatureModelDataStore.LookupEntry(mountDisplayInfo->ModelID);
        if (!mountModelData)
            return GetCollisionHeight(false);

        CreatureDisplayInfoEntry const* displayInfo = sCreatureDisplayInfoStore.LookupEntry(GetNativeDisplayId());
        ASSERT(displayInfo);
        CreatureModelDataEntry const* modelData = sCreatureModelDataStore.LookupEntry(displayInfo->ModelID);
        ASSERT(modelData);

        float scaleMod = GetObjectScale(); // 99% sure about this

        return scaleMod * mountModelData->MountHeight + modelData->CollisionHeight * 0.5f;
    }
    else
    {
        //! Dismounting case - use basic default model data
        CreatureDisplayInfoEntry const* displayInfo = sCreatureDisplayInfoStore.LookupEntry(GetNativeDisplayId());
        ASSERT(displayInfo);
        CreatureModelDataEntry const* modelData = sCreatureModelDataStore.LookupEntry(displayInfo->ModelID);
        ASSERT(modelData);

        return modelData->CollisionHeight;
    }
}

std::string Player::GetMapAreaAndZoneString() const
{
    uint32 areaId = GetAreaId();
    std::string areaName = "Unknown";
    std::string zoneName = "Unknown";
    if (AreaTableEntry const* area = sAreaTableStore.LookupEntry(areaId))
    {
        areaName = area->AreaName_lang;
        if (AreaTableEntry const* zone = sAreaTableStore.LookupEntry(area->ParentAreaID))
            zoneName = zone->AreaName_lang;
    }

    std::ostringstream str;
    str << "Map: " << GetMapId() << " (" << (FindMap() ? FindMap()->GetMapName() : "Unknown") << ") Area: " << areaId << " (" << areaName.c_str() << ") Zone: " << zoneName.c_str();
    return str.str();
}

std::string Player::GetCoordsMapAreaAndZoneString() const
{
    std::ostringstream str;
    str << Position::ToString() << " " << GetMapAreaAndZoneString();
    return str.str();
}

Guild* Player::GetGuild()
{
    ObjectGuid::LowType guildId = GetGuildId();
    return guildId ? sGuildMgr->GetGuildById(guildId) : nullptr;
}

Guild const* Player::GetGuild() const
{
    ObjectGuid::LowType guildId = GetGuildId();
    return guildId ? sGuildMgr->GetGuildById(guildId) : nullptr;
}

Pet* Player::SummonPet(uint32 entry, float x, float y, float z, float ang, PetType petType, uint32 duration)
{
    Pet* pet = new Pet(this, petType);

    if (petType == SUMMON_PET && pet->LoadPetFromDB(this, entry))
    {
        // Remove Demonic Sacrifice auras (known pet)
        Unit::AuraEffectList const& auraClassScripts = GetAuraEffectsByType(SPELL_AURA_OVERRIDE_CLASS_SCRIPTS);
        for (Unit::AuraEffectList::const_iterator itr = auraClassScripts.begin(); itr != auraClassScripts.end();)
        {
            if ((*itr)->GetMiscValue() == 2228)
            {
                RemoveAurasDueToSpell((*itr)->GetId());
                itr = auraClassScripts.begin();
            }
            else
                ++itr;
        }

        if (duration > 0)
            pet->SetDuration(duration);

        return nullptr;
    }

    // petentry == 0 for hunter "call pet" (current pet summoned if any)
    if (!entry)
    {
        delete pet;
        return nullptr;
    }

    pet->Relocate(x, y, z, ang);
    if (!pet->IsPositionValid())
    {
        TC_LOG_ERROR("misc", "Player::SummonPet: Pet (%s, Entry: %d) not summoned. Suggested coordinates aren't valid (X: %f Y: %f)", pet->GetGUID().ToString().c_str(), pet->GetEntry(), pet->GetPositionX(), pet->GetPositionY());
        delete pet;
        return nullptr;
    }

    Map* map = GetMap();
    uint32 pet_number = sObjectMgr->GeneratePetNumber();
    if (!pet->Create(map->GenerateLowGuid<HighGuid::Pet>(), map, entry))
    {
        TC_LOG_ERROR("misc", "Player::SummonPet: No such creature entry %u", entry);
        delete pet;
        return nullptr;
    }

    pet->CopyPhaseFrom(this);

    pet->SetCreatorGUID(GetGUID());
    pet->SetUInt32Value(UNIT_FIELD_FACTIONTEMPLATE, getFaction());

    pet->setPowerType(POWER_MANA);
    pet->SetUInt64Value(UNIT_NPC_FLAGS, 0);
    pet->SetUInt32Value(UNIT_FIELD_BYTES_1, 0);
    pet->InitStatsForLevel(getLevel());

    SetMinion(pet, true);

    switch (petType)
    {
        case SUMMON_PET:
            // this enables pet details window (Shift+P)
            pet->GetCharmInfo()->SetPetNumber(pet_number, true);
            pet->SetByteValue(UNIT_FIELD_BYTES_0, UNIT_BYTES_0_OFFSET_CLASS, CLASS_MAGE);
            pet->SetUInt32Value(UNIT_FIELD_PETEXPERIENCE, 0);
            pet->SetUInt32Value(UNIT_FIELD_PETNEXTLEVELEXP, 1000);
            pet->SetFullHealth();
            pet->SetPower(POWER_MANA, pet->GetMaxPower(POWER_MANA));
            pet->SetUInt32Value(UNIT_FIELD_PET_NAME_TIMESTAMP, uint32(time(nullptr))); // cast can't be helped in this case
            break;
        default:
            break;
    }

    map->AddToMap(pet->ToCreature());

    switch (petType)
    {
        case SUMMON_PET:
            pet->InitPetCreateSpells();
            pet->InitTalentForLevel();
            pet->SavePetToDB(PET_SAVE_AS_CURRENT);
            PetSpellInitialize();
            break;
        default:
            break;
    }

    if (petType == SUMMON_PET)
    {
        // Remove Demonic Sacrifice auras (known pet)
        Unit::AuraEffectList const& auraClassScripts = GetAuraEffectsByType(SPELL_AURA_OVERRIDE_CLASS_SCRIPTS);
        for (Unit::AuraEffectList::const_iterator itr = auraClassScripts.begin(); itr != auraClassScripts.end();)
        {
            if ((*itr)->GetMiscValue() == 2228)
            {
                RemoveAurasDueToSpell((*itr)->GetId());
                itr = auraClassScripts.begin();
            }
            else
                ++itr;
        }
    }

    if (duration > 0)
        pet->SetDuration(duration);

    //ObjectAccessor::UpdateObjectVisibility(pet);

    return pet;
}

bool Player::CanUseMastery() const
{
    return HasSpell(MasterySpells[getClass()]);
}

void Player::ValidateMovementInfo(MovementInfo* mi)
{
    //! Anti-cheat checks. Please keep them in seperate if () blocks to maintain a clear overview.
    //! Might be subject to latency, so just remove improper flags.
    #ifdef TRINITY_DEBUG
    #define REMOVE_VIOLATING_FLAGS(check, maskToRemove) \
    { \
        if (check) \
        { \
            TC_LOG_DEBUG("entities.unit", "Player::ValidateMovementInfo: Violation of MovementFlags found (%s). " \
                "MovementFlags: %u, MovementFlags2: %u for player %s. Mask %u will be removed.", \
                STRINGIZE(check), mi->GetMovementFlags(), mi->GetExtraMovementFlags(), GetGUID().ToString().c_str(), maskToRemove); \
            mi->RemoveMovementFlag((maskToRemove)); \
        } \
    }
    #else
    #define REMOVE_VIOLATING_FLAGS(check, maskToRemove) \
        if (check) \
            mi->RemoveMovementFlag((maskToRemove));
    #endif

    /*! This must be a packet spoofing attempt. MOVEMENTFLAG_ROOT sent from the client is not valid
        in conjunction with any of the moving movement flags such as MOVEMENTFLAG_FORWARD.
        It will freeze clients that receive this player's movement info.
    */
    REMOVE_VIOLATING_FLAGS(mi->HasMovementFlag(MOVEMENTFLAG_ROOT),
        MOVEMENTFLAG_ROOT);

    //! Cannot hover without SPELL_AURA_HOVER
    REMOVE_VIOLATING_FLAGS(mi->HasMovementFlag(MOVEMENTFLAG_HOVER) && !HasAuraType(SPELL_AURA_HOVER),
        MOVEMENTFLAG_HOVER);

    //! Cannot ascend and descend at the same time
    REMOVE_VIOLATING_FLAGS(mi->HasMovementFlag(MOVEMENTFLAG_ASCENDING) && mi->HasMovementFlag(MOVEMENTFLAG_DESCENDING),
        MOVEMENTFLAG_ASCENDING | MOVEMENTFLAG_DESCENDING);

    //! Cannot move left and right at the same time
    REMOVE_VIOLATING_FLAGS(mi->HasMovementFlag(MOVEMENTFLAG_LEFT) && mi->HasMovementFlag(MOVEMENTFLAG_RIGHT),
        MOVEMENTFLAG_LEFT | MOVEMENTFLAG_RIGHT);

    //! Cannot strafe left and right at the same time
    REMOVE_VIOLATING_FLAGS(mi->HasMovementFlag(MOVEMENTFLAG_STRAFE_LEFT) && mi->HasMovementFlag(MOVEMENTFLAG_STRAFE_RIGHT),
        MOVEMENTFLAG_STRAFE_LEFT | MOVEMENTFLAG_STRAFE_RIGHT);

    //! Cannot pitch up and down at the same time
    REMOVE_VIOLATING_FLAGS(mi->HasMovementFlag(MOVEMENTFLAG_PITCH_UP) && mi->HasMovementFlag(MOVEMENTFLAG_PITCH_DOWN),
        MOVEMENTFLAG_PITCH_UP | MOVEMENTFLAG_PITCH_DOWN);

    //! Cannot move forwards and backwards at the same time
    REMOVE_VIOLATING_FLAGS(mi->HasMovementFlag(MOVEMENTFLAG_FORWARD) && mi->HasMovementFlag(MOVEMENTFLAG_BACKWARD),
        MOVEMENTFLAG_FORWARD | MOVEMENTFLAG_BACKWARD);

    //! Cannot walk on water without SPELL_AURA_WATER_WALK
    REMOVE_VIOLATING_FLAGS(mi->HasMovementFlag(MOVEMENTFLAG_WATERWALKING) && !HasAuraType(SPELL_AURA_WATER_WALK),
        MOVEMENTFLAG_WATERWALKING);

    //! Cannot feather fall without SPELL_AURA_FEATHER_FALL
    REMOVE_VIOLATING_FLAGS(mi->HasMovementFlag(MOVEMENTFLAG_FALLING_SLOW) && !HasAuraType(SPELL_AURA_FEATHER_FALL),
        MOVEMENTFLAG_FALLING_SLOW);

    /*! Cannot fly if no fly auras present. Exception is being a GM.
        Note that we check for account level instead of Player::IsGameMaster() because in some
        situations it may be feasable to use .gm fly on as a GM without having .gm on,
        e.g. aerial combat.
    */

    REMOVE_VIOLATING_FLAGS(mi->HasMovementFlag(MOVEMENTFLAG_FLYING | MOVEMENTFLAG_CAN_FLY) && GetSession()->GetSecurity() == SEC_PLAYER &&
        !m_mover->HasAuraType(SPELL_AURA_FLY) &&
        !m_mover->HasAuraType(SPELL_AURA_MOD_INCREASE_MOUNTED_FLIGHT_SPEED),
        MOVEMENTFLAG_FLYING | MOVEMENTFLAG_CAN_FLY);

    REMOVE_VIOLATING_FLAGS(mi->HasMovementFlag(MOVEMENTFLAG_DISABLE_GRAVITY | MOVEMENTFLAG_CAN_FLY) && mi->HasMovementFlag(MOVEMENTFLAG_FALLING),
        MOVEMENTFLAG_FALLING);

    REMOVE_VIOLATING_FLAGS(mi->HasMovementFlag(MOVEMENTFLAG_SPLINE_ELEVATION) && G3D::fuzzyEq(mi->splineElevation, 0.0f), MOVEMENTFLAG_SPLINE_ELEVATION);

    // Client first checks if spline elevation != 0, then verifies flag presence
    if (G3D::fuzzyNe(mi->splineElevation, 0.0f))
        mi->AddMovementFlag(MOVEMENTFLAG_SPLINE_ELEVATION);

    #undef REMOVE_VIOLATING_FLAGS
}

void Player::SendUpdatePhasing()
{
    if (!IsInWorld())
        return;

    RebuildTerrainSwaps(); // to set default map swaps

    GetSession()->SendSetPhaseShift(GetPhases(), GetTerrainSwaps(), GetWorldMapAreaSwaps());
}

void Player::SendSupercededSpell(uint32 oldSpell, uint32 newSpell) const
{
    WorldPacket data(SMSG_SUPERCEDED_SPELLS, 8);
    data << uint32(newSpell) << uint32(oldSpell);
    GetSession()->SendPacket(&data);
}

uint32 Player::CalculateTalentsTiers() const
{
    uint32 const* rowLevels = (getClass() != CLASS_DEATH_KNIGHT) ? DefaultTalentRowLevels : DKTalentRowLevels;
    for (uint32 i = MAX_TALENT_TIERS; i; --i)
        if (getLevel() >= rowLevels[i - 1])
            return i;

    return 0;
}

Difficulty Player::GetDifficultyID(MapEntry const* mapEntry) const
{
    if (!mapEntry->IsRaid())
        return m_dungeonDifficulty;

    MapDifficultyEntry const* defaultDifficulty = GetDefaultMapDifficulty(mapEntry->ID);
    if (!defaultDifficulty)
        return m_legacyRaidDifficulty;

    DifficultyEntry const* difficulty = sDifficultyStore.LookupEntry(defaultDifficulty->DifficultyID);
    if (!difficulty || difficulty->Flags & DIFFICULTY_FLAG_LEGACY)
        return m_legacyRaidDifficulty;

    return m_raidDifficulty;
}

Difficulty Player::CheckLoadedDungeonDifficultyID(Difficulty difficulty)
{
    DifficultyEntry const* difficultyEntry = sDifficultyStore.LookupEntry(difficulty);
    if (!difficultyEntry)
        return DIFFICULTY_NORMAL;

    if (difficultyEntry->InstanceType != MAP_INSTANCE)
        return DIFFICULTY_NORMAL;

    if (!(difficultyEntry->Flags & DIFFICULTY_FLAG_CAN_SELECT))
        return DIFFICULTY_NORMAL;

    return difficulty;
}

Difficulty Player::CheckLoadedRaidDifficultyID(Difficulty difficulty)
{
    DifficultyEntry const* difficultyEntry = sDifficultyStore.LookupEntry(difficulty);
    if (!difficultyEntry)
        return DIFFICULTY_NORMAL_RAID;

    if (difficultyEntry->InstanceType != MAP_RAID)
        return DIFFICULTY_NORMAL_RAID;

    if (!(difficultyEntry->Flags & DIFFICULTY_FLAG_CAN_SELECT) || (difficultyEntry->Flags & DIFFICULTY_FLAG_LEGACY))
        return DIFFICULTY_NORMAL_RAID;

    return difficulty;
}

Difficulty Player::CheckLoadedLegacyRaidDifficultyID(Difficulty difficulty)
{
    DifficultyEntry const* difficultyEntry = sDifficultyStore.LookupEntry(difficulty);
    if (!difficultyEntry)
        return DIFFICULTY_10_N;

    if (difficultyEntry->InstanceType != MAP_RAID)
        return DIFFICULTY_10_N;

    if (!(difficultyEntry->Flags & DIFFICULTY_FLAG_CAN_SELECT) || !(difficultyEntry->Flags & DIFFICULTY_FLAG_LEGACY))
        return DIFFICULTY_10_N;

    return difficulty;
}

SpellInfo const* Player::GetCastSpellInfo(SpellInfo const* spellInfo) const
{
    auto overrides = m_overrideSpells.find(spellInfo->Id);
    if (overrides != m_overrideSpells.end())
        for (uint32 spellId : overrides->second)
            if (SpellInfo const* newInfo = sSpellMgr->GetSpellInfo(spellId))
                return Unit::GetCastSpellInfo(newInfo);

    return Unit::GetCastSpellInfo(spellInfo);
}

void Player::AddOverrideSpell(uint32 overridenSpellId, uint32 newSpellId)
{
    m_overrideSpells[overridenSpellId].insert(newSpellId);
}

void Player::RemoveOverrideSpell(uint32 overridenSpellId, uint32 newSpellId)
{
    auto overrides = m_overrideSpells.find(overridenSpellId);
    if (overrides == m_overrideSpells.end())
        return;

    overrides->second.erase(newSpellId);
    if (overrides->second.empty())
        m_overrideSpells.erase(overrides);
}

void Player::LearnSpecializationSpells()
{
    if (std::vector<SpecializationSpellsEntry const*> const* specSpells = sDB2Manager.GetSpecializationSpells(GetSpecId(GetActiveTalentGroup())))
    {
        for (size_t j = 0; j < specSpells->size(); ++j)
        {
            SpecializationSpellsEntry const* specSpell = specSpells->at(j);
            SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(specSpell->SpellID);
            if (!spellInfo || spellInfo->SpellLevel > getLevel())
                continue;

            LearnSpell(specSpell->SpellID, false);
            if (specSpell->OverridesSpellID)
                AddOverrideSpell(specSpell->OverridesSpellID, specSpell->SpellID);
        }
    }
}

void Player::RemoveSpecializationSpells()
{
    for (uint32 i = 0; i < MAX_SPECIALIZATIONS; ++i)
    {
        if (ChrSpecializationEntry const* specialization = sChrSpecializationByIndexStore[getClass()][i])
        {
            if (std::vector<SpecializationSpellsEntry const*> const* specSpells = sDB2Manager.GetSpecializationSpells(specialization->ID))
            {
                for (size_t j = 0; j < specSpells->size(); ++j)
                {
                    SpecializationSpellsEntry const* specSpell = specSpells->at(j);
                    RemoveSpell(specSpell->SpellID, true);
                    if (specSpell->OverridesSpellID)
                        RemoveOverrideSpell(specSpell->OverridesSpellID, specSpell->SpellID);
                }
            }

            for (uint32 j = 0; j < MAX_MASTERY_SPELLS; ++j)
                if (uint32 mastery = specialization->MasterySpellID[j])
                    RemoveAurasDueToSpell(mastery);
        }
    }
}

void Player::RemoveSocial()
{
    sSocialMgr->RemovePlayerSocial(GetGUID());
    m_social = nullptr;
}

bool Player::ValidateAppearance(uint8 race, uint8 class_, uint8 gender, uint8 hairID, uint8 hairColor, uint8 faceID, uint8 facialHair, uint8 skinColor, bool create /*=false*/)
{
    // Check skin color
    // For Skin type is always 0
    if (CharSectionsEntry const* entry = GetCharSectionEntry(race, SECTION_TYPE_SKIN, gender, 0, skinColor))
    {   // Skin Color defined as Face color, too, we check skin & face in one pass
        if (CharSectionsEntry const* entry2 = GetCharSectionEntry(race, SECTION_TYPE_FACE, gender, faceID, skinColor))
        {
            // Check DeathKnight exclusive
            if (((entry->Flags & SECTION_FLAG_DEATH_KNIGHT) || (entry2->Flags & SECTION_FLAG_DEATH_KNIGHT)) && class_ != CLASS_DEATH_KNIGHT)
                return false;
            if (create && !((entry->Flags & SECTION_FLAG_PLAYER) && (entry2->Flags & SECTION_FLAG_PLAYER)))
                return false;
        }
        else
            return false;
    }
    else
        return false;

    // These combinations don't have an entry of Type SECTION_TYPE_FACIAL_HAIR, exclude them from that check
    bool excludeCheck = (race == RACE_TAUREN) || (race == RACE_DRAENEI) || (gender == GENDER_FEMALE && race != RACE_NIGHTELF && race != RACE_UNDEAD_PLAYER);

    // Check Hair
    if (CharSectionsEntry const* entry = GetCharSectionEntry(race, SECTION_TYPE_HAIR, gender, hairID, hairColor))
    {
        if ((entry->Flags & SECTION_FLAG_DEATH_KNIGHT) && class_ != CLASS_DEATH_KNIGHT)
            return false;
        if (create && !(entry->Flags & SECTION_FLAG_PLAYER))
            return false;

        if (!excludeCheck)
        {
            if (CharSectionsEntry const* entry2 = GetCharSectionEntry(race, SECTION_TYPE_FACIAL_HAIR, gender, facialHair, hairColor))
            {
                if ((entry2->Flags & SECTION_FLAG_DEATH_KNIGHT) && class_ != CLASS_DEATH_KNIGHT)
                    return false;
                if (create && !(entry2->Flags & SECTION_FLAG_PLAYER))
                    return false;
            }
            else
                return false;
        }
        else
        {
            // @TODO: Bound checking for facialHair ID (used clientside for markings, tauren beard, etc.)
            // Not present in DBC
        }
    }
    else
        return false;

    return true;
}

uint32 Player::GetDefaultSpecId() const
{
    ChrClassesEntry const* entry = sChrClassesStore.LookupEntry(getClass());
    if (entry)
        return entry->DefaultSpec;
    return 0;
}

void Player::SendSpellCategoryCooldowns() const
{
    WorldPackets::Spells::CategoryCooldown cooldowns;

    Unit::AuraEffectList const& categoryCooldownAuras = GetAuraEffectsByType(SPELL_AURA_MOD_SPELL_CATEGORY_COOLDOWN);
    for (AuraEffect* aurEff : categoryCooldownAuras)
    {
        uint32 categoryId = aurEff->GetMiscValue();
        auto cItr = std::find_if(cooldowns.CategoryCooldowns.begin(), cooldowns.CategoryCooldowns.end(),
            [categoryId](WorldPackets::Spells::CategoryCooldown::CategoryCooldownInfo const& cooldown)
        {
            return cooldown.Category == categoryId;
        });

        if (cItr == cooldowns.CategoryCooldowns.end())
            cooldowns.CategoryCooldowns.emplace_back(categoryId, -aurEff->GetAmount());
        else
            cItr->ModCooldown -= aurEff->GetAmount();
    }

    SendDirectMessage(cooldowns.Write());
}

void Player::SendRaidGroupOnlyMessage(RaidGroupReason reason, int32 delay) const
{
    WorldPackets::Instance::RaidGroupOnly raidGroupOnly;
    raidGroupOnly.Delay = delay;
    raidGroupOnly.Reason = reason;

    GetSession()->SendPacket(raidGroupOnly.Write());
}

void Player::SetRestFlag(RestFlag restFlag, uint32 triggerId /*= 0*/)
{
    uint32 oldRestMask = _restFlagMask;
    _restFlagMask |= restFlag;

    if (!oldRestMask && _restFlagMask) // only set flag/time on the first rest state
    {
        _restTime = time(nullptr);
        SetFlag(PLAYER_FLAGS, PLAYER_FLAGS_RESTING);
    }

    if (triggerId)
        inn_triggerId = triggerId;
}

void Player::RemoveRestFlag(RestFlag restFlag)
{
    uint32 oldRestMask = _restFlagMask;
    _restFlagMask &= ~restFlag;

    if (oldRestMask && !_restFlagMask) // only remove flag/time on the last rest state remove
    {
        _restTime = 0;
        RemoveFlag(PLAYER_FLAGS, PLAYER_FLAGS_RESTING);
    }
}
