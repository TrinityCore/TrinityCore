/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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
#include "Bag.h"
#include "Battlefield.h"
#include "BattlefieldMgr.h"
#include "BattlefieldWG.h"
#include "Battleground.h"
#include "BattlegroundMgr.h"
#include "BattlegroundScore.h"
#include "CellImpl.h"
#include "Channel.h"
#include "ChannelMgr.h"
#include "CharacterCache.h"
#include "CharacterDatabaseCleaner.h"
#include "Chat.h"
#include "CinematicMgr.h"
#include "Common.h"
#include "ConditionMgr.h"
#include "CreatureAI.h"
#include "DatabaseEnv.h"
#include "DisableMgr.h"
#include "Formulas.h"
#include "GameEventMgr.h"
#include "GameObjectAI.h"
#include "GameTime.h"
#include "GitRevision.h"
#include "GossipDef.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"
#include "Group.h"
#include "GroupMgr.h"
#include "Guild.h"
#include "GuildMgr.h"
#include "InstanceSaveMgr.h"
#include "InstanceScript.h"
#include "Item.h"
#include "KillRewarder.h"
#include "Language.h"
#include "LFGMgr.h"
#include "Log.h"
#include "LootItemStorage.h"
#include "LootMgr.h"
#include "Mail.h"
#include "MapManager.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "Opcodes.h"
#include "OutdoorPvP.h"
#include "OutdoorPvPMgr.h"
#include "Pet.h"
#include "PetitionMgr.h"
#include "PoolMgr.h"
#include "QueryHolder.h"
#include "QuestDef.h"
#include "QuestPools.h"
#include "Realm.h"
#include "ReputationMgr.h"
#include "SkillDiscovery.h"
#include "SocialMgr.h"
#include "Spell.h"
#include "SpellAuraEffects.h"
#include "SpellAuras.h"
#include "SpellHistory.h"
#include "SpellMgr.h"
#include "SpellPackets.h"
#include "TicketMgr.h"
#include "TradeData.h"
#include "Trainer.h"
#include "Transport.h"
#include "UpdateData.h"
#include "UpdateFieldFlags.h"
#include "UpdateMask.h"
#include "Util.h"
#include "Weather.h"
#include "WeatherMgr.h"
#include "World.h"
#include "WorldPacket.h"
#include "WorldSession.h"
#include "WorldStatePackets.h"

#define ZONE_UPDATE_INTERVAL (1*IN_MILLISECONDS)

#define PLAYER_SKILL_INDEX(x)       (PLAYER_SKILL_INFO_1_1 + ((x)*3))
#define PLAYER_SKILL_VALUE_INDEX(x) (PLAYER_SKILL_INDEX(x)+1)
#define PLAYER_SKILL_BONUS_INDEX(x) (PLAYER_SKILL_INDEX(x)+2)

#define SKILL_VALUE(x)         PAIR32_LOPART(x)
#define SKILL_MAX(x)           PAIR32_HIPART(x)
#define MAKE_SKILL_VALUE(v, m) MAKE_PAIR32(v, m)

#define SKILL_TEMP_BONUS(x)    int16(PAIR32_LOPART(x))
#define SKILL_PERM_BONUS(x)    int16(PAIR32_HIPART(x))
#define MAKE_SKILL_BONUS(t, p) MAKE_PAIR32(t, p)

enum CharacterFlags
{
    CHARACTER_FLAG_NONE                 = 0x00000000,
    CHARACTER_FLAG_UNK1                 = 0x00000001,
    CHARACTER_FLAG_UNK2                 = 0x00000002,
    CHARACTER_LOCKED_FOR_TRANSFER       = 0x00000004,
    CHARACTER_FLAG_UNK4                 = 0x00000008,
    CHARACTER_FLAG_UNK5                 = 0x00000010,
    CHARACTER_FLAG_UNK6                 = 0x00000020,
    CHARACTER_FLAG_UNK7                 = 0x00000040,
    CHARACTER_FLAG_UNK8                 = 0x00000080,
    CHARACTER_FLAG_UNK9                 = 0x00000100,
    CHARACTER_FLAG_UNK10                = 0x00000200,
    CHARACTER_FLAG_HIDE_HELM            = 0x00000400,
    CHARACTER_FLAG_HIDE_CLOAK           = 0x00000800,
    CHARACTER_FLAG_UNK13                = 0x00001000,
    CHARACTER_FLAG_GHOST                = 0x00002000,
    CHARACTER_FLAG_RENAME               = 0x00004000,
    CHARACTER_FLAG_UNK16                = 0x00008000,
    CHARACTER_FLAG_UNK17                = 0x00010000,
    CHARACTER_FLAG_UNK18                = 0x00020000,
    CHARACTER_FLAG_UNK19                = 0x00040000,
    CHARACTER_FLAG_UNK20                = 0x00080000,
    CHARACTER_FLAG_UNK21                = 0x00100000,
    CHARACTER_FLAG_UNK22                = 0x00200000,
    CHARACTER_FLAG_UNK23                = 0x00400000,
    CHARACTER_FLAG_UNK24                = 0x00800000,
    CHARACTER_FLAG_LOCKED_BY_BILLING    = 0x01000000,
    CHARACTER_FLAG_DECLINED             = 0x02000000,
    CHARACTER_FLAG_UNK27                = 0x04000000,
    CHARACTER_FLAG_UNK28                = 0x08000000,
    CHARACTER_FLAG_UNK29                = 0x10000000,
    CHARACTER_FLAG_UNK30                = 0x20000000,
    CHARACTER_FLAG_UNK31                = 0x40000000,
    CHARACTER_FLAG_UNK32                = 0x80000000
};

enum CharacterCustomizeFlags
{
    CHAR_CUSTOMIZE_FLAG_NONE            = 0x00000000,
    CHAR_CUSTOMIZE_FLAG_CUSTOMIZE       = 0x00000001,       // name, gender, etc...
    CHAR_CUSTOMIZE_FLAG_FACTION         = 0x00010000,       // name, gender, faction, etc...
    CHAR_CUSTOMIZE_FLAG_RACE            = 0x00100000        // name, gender, race, etc...
};

// corpse reclaim times
#define DEATH_EXPIRE_STEP (5*MINUTE)
#define MAX_DEATH_COUNT 3

static uint32 copseReclaimDelay[MAX_DEATH_COUNT] = { 30, 60, 120 };

uint32 const MAX_MONEY_AMOUNT = static_cast<uint32>(std::numeric_limits<int32>::max());

Player::Player(WorldSession* session): Unit(true)
{
    m_speakTime = 0;
    m_speakCount = 0;

    m_objectType |= TYPEMASK_PLAYER;
    m_objectTypeId = TYPEID_PLAYER;

    m_valuesCount = PLAYER_END;

    m_session = session;

    m_ingametime = 0;
    m_sharedQuestId = 0;

    m_ExtraFlags = 0;

    m_spellModTakingSpell = nullptr;
    //m_pad = 0;

    // players always accept
    if (!GetSession()->HasPermission(rbac::RBAC_PERM_CAN_FILTER_WHISPERS))
        SetAcceptWhispers(true);

    m_usedTalentCount = 0;
    m_questRewardTalentCount = 0;

    m_regenTimer = 0;
    m_regenTimerCount = 0;
    m_foodEmoteTimerCount = 0;
    m_weaponChangeTimer = 0;

    m_zoneUpdateId = uint32(-1);
    m_zoneUpdateTimer = 0;

    m_areaUpdateId = 0;
    m_team = 0;

    m_needsZoneUpdate = false;

    m_nextSave = sWorld->getIntConfig(CONFIG_INTERVAL_SAVE);

    memset(m_items, 0, sizeof(Item*)*PLAYER_SLOTS_COUNT);

    m_social = nullptr;

    // group is initialized in the reference constructor
    SetGroupInvite(nullptr);
    m_groupUpdateMask = 0;
    m_auraRaidUpdateMask = 0;
    m_bPassOnGroupLoot = false;

    m_GuildIdInvited = 0;
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
    m_hostileReferenceCheckTimer = 0;
    m_drunkTimer = 0;
    m_deathTimer = 0;
    m_deathExpireTime = 0;

    m_swingErrorMsg = 0;

    for (uint8 j = 0; j < PLAYER_MAX_BATTLEGROUND_QUEUES; ++j)
    {
        m_bgBattlegroundQueueID[j].bgQueueTypeId = BATTLEGROUND_QUEUE_NONE;
        m_bgBattlegroundQueueID[j].invitedToInstance = 0;
    }

    m_logintime = GameTime::GetGameTime();
    m_Last_tick = m_logintime;
    m_Played_time[PLAYED_TIME_TOTAL] = 0;
    m_Played_time[PLAYED_TIME_LEVEL] = 0;
    m_WeaponProficiency = 0;
    m_ArmorProficiency = 0;
    m_canParry = false;
    m_canBlock = false;
    m_canTitanGrip = false;
    m_titanGripPenaltySpellId = 0;
    m_ammoDPS = 0.0f;

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

    m_resetTalentsCost = 0;
    m_resetTalentsTime = 0;
    m_itemUpdateQueueBlocked = false;

    for (uint8 i = 0; i < MAX_MOVE_TYPE; ++i)
        m_forced_speed_changes[i] = 0;

    m_stableSlots = 0;

    /////////////////// Instance System /////////////////////

    m_HomebindTimer = 0;
    m_InstanceValid = true;
    m_dungeonDifficulty = DUNGEON_DIFFICULTY_NORMAL;
    m_raidDifficulty = RAID_DIFFICULTY_10MAN_NORMAL;
    m_raidMapDifficulty = RAID_DIFFICULTY_10MAN_NORMAL;

    m_lastPotionId = 0;

    m_activeSpec = 0;
    m_specsCount = 1;

    for (uint8 i = 0; i < MAX_TALENT_SPECS; ++i)
    {
        for (uint8 g = 0; g < MAX_GLYPH_SLOT_INDEX; ++g)
            m_Glyphs[i][g] = 0;

        m_talents[i] = new PlayerTalentMap();
    }

    for (uint8 i = 0; i < BASEMOD_END; ++i)
    {
        m_auraBaseFlatMod[i] = 0.0f;
        m_auraBasePctMod[i] = 1.0f;
    }

    for (uint8 i = 0; i < MAX_COMBAT_RATING; i++)
        m_baseRatingValue[i] = 0;

    m_baseSpellPower = 0;
    m_baseFeralAP = 0;
    m_baseManaRegen = 0;
    m_baseHealthRegen = 0;
    m_spellPenetrationItemMod = 0;

    // Honor System
    m_lastHonorUpdateTime = GameTime::GetGameTime();

    m_IsBGRandomWinner = false;

    // Player summoning
    m_summon_expire = 0;

    m_unitMovedByMe = this;
    m_playerMovingMe = this;
    m_seer = this;

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
    m_fishingSteps = 0;

    m_ControlledByPlayer = true;

    sWorld->IncreasePlayerCount();

    m_ChampioningFaction = 0;

    for (uint8 i = 0; i < MAX_POWERS; ++i)
        m_powerFraction[i] = 0;

    isDebugAreaTriggers = false;

    m_WeeklyQuestChanged = false;

    m_MonthlyQuestChanged = false;

    m_SeasonalQuestChanged = false;

    SetPendingBind(0, 0);

    _activeCheats = CHEAT_NONE;
    healthBeforeDuel = 0;
    manaBeforeDuel = 0;

    _cinematicMgr = new CinematicMgr(this);

    m_achievementMgr = new AchievementMgr(this);
    m_reputationMgr = new ReputationMgr(this);

    m_groupUpdateTimer.Reset(5000);
}

Player::~Player()
{
    // it must be unloaded already in PlayerLogout and accessed only for logged in player
    //m_social = nullptr;

    // Note: buy back item already deleted from DB when player was saved
    for (uint8 i = 0; i < PLAYER_SLOTS_COUNT; ++i)
        delete m_items[i];

    for (PlayerSpellMap::const_iterator itr = m_spells.begin(); itr != m_spells.end(); ++itr)
        delete itr->second;

    for (uint8 i = 0; i < MAX_TALENT_SPECS; ++i)
    {
        for (PlayerTalentMap::const_iterator itr = m_talents[i]->begin(); itr != m_talents[i]->end(); ++itr)
            delete itr->second;
        delete m_talents[i];
    }

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
    delete _cinematicMgr;

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

bool Player::Create(ObjectGuid::LowType guidlow, CharacterCreateInfo* createInfo)
{
    //FIXME: outfitId not used in player creating
    /// @todo need more checks against packet modifications

    Object::_Create(guidlow, 0, HighGuid::Player);

    m_name = createInfo->Name;

    PlayerInfo const* info = sObjectMgr->GetPlayerInfo(createInfo->Race, createInfo->Class);
    if (!info)
    {
        TC_LOG_ERROR("entities.player.cheat", "Player::Create: Possible hacking attempt: Account %u tried to create a character named '%s' with an invalid race/class pair (%u/%u) - refusing to do so.",
                GetSession()->GetAccountId(), m_name.c_str(), createInfo->Race, createInfo->Class);
        return false;
    }

    for (uint8 i = 0; i < PLAYER_SLOTS_COUNT; i++)
        m_items[i] = nullptr;

    Relocate(info->positionX, info->positionY, info->positionZ, info->orientation);

    ChrClassesEntry const* cEntry = sChrClassesStore.LookupEntry(createInfo->Class);
    if (!cEntry)
    {
        TC_LOG_ERROR("entities.player.cheat", "Player::Create: Possible hacking attempt: Account %u tried to create a character named '%s' with an invalid character class (%u) - refusing to do so (wrong DBC-files?)",
                GetSession()->GetAccountId(), m_name.c_str(), createInfo->Class);
        return false;
    }

    SetMap(sMapMgr->CreateMap(info->mapId, this));

    uint8 powertype = cEntry->powerType;

    SetObjectScale(1.0f);

    SetFactionForRace(createInfo->Race);

    if (!IsValidGender(createInfo->Gender))
    {
        TC_LOG_ERROR("entities.player.cheat", "Player::Create: Possible hacking attempt: Account %u tried to create a character named '%s' with an invalid gender (%u) - refusing to do so",
                GetSession()->GetAccountId(), m_name.c_str(), createInfo->Gender);
        return false;
    }

    if (!ValidateAppearance(createInfo->Race, createInfo->Class, createInfo->Gender, createInfo->HairStyle, createInfo->HairColor, createInfo->Face, createInfo->FacialHair, createInfo->Skin, true))
    {
        TC_LOG_ERROR("entities.player.cheat", "Player::Create: Possible hacking attempt: Account %u tried to create a character named '%s' with invalid appearance attributes - refusing to do so",
            GetSession()->GetAccountId(), m_name.c_str());
        return false;
    }

    SetRace(createInfo->Race);
    SetClass(createInfo->Class);
    SetGender(createInfo->Gender);
    SetPowerType(Powers(powertype), false);
    InitDisplayIds();
    UpdatePositionData();
    if (sWorld->getIntConfig(CONFIG_GAME_TYPE) == REALM_TYPE_PVP || sWorld->getIntConfig(CONFIG_GAME_TYPE) == REALM_TYPE_RPPVP)
    {
        SetByteFlag(UNIT_FIELD_BYTES_2, UNIT_BYTES_2_OFFSET_PVP_FLAG, UNIT_BYTE2_FLAG_PVP);
        SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_PLAYER_CONTROLLED);
    }
    SetFlag(UNIT_FIELD_FLAGS_2, UNIT_FLAG2_REGENERATE_POWER);
    SetFloatValue(UNIT_MOD_CAST_SPEED, 1.0f);               // fix cast time showed in spell tooltip on client
    SetFloatValue(UNIT_FIELD_HOVERHEIGHT, 1.0f);            // default for players in 3.0.3

    SetInt32Value(PLAYER_FIELD_WATCHED_FACTION_INDEX, uint32(-1));  // -1 is default value

    SetSkinId(createInfo->Skin);
    SetFaceId(createInfo->Face);
    SetHairStyleId(createInfo->HairStyle);
    SetHairColorId(createInfo->HairColor);
    SetFacialStyle(createInfo->FacialHair);
    SetRestState((GetSession()->IsARecruiter() || GetSession()->GetRecruiterId() != 0) ? REST_STATE_RAF_LINKED : REST_STATE_NOT_RAF_LINKED);
    SetNativeGender(createInfo->Gender);
    SetArenaFaction(0);

    SetUInt32Value(PLAYER_GUILDID, 0);
    SetRank(0);
    SetUInt32Value(PLAYER_GUILD_TIMESTAMP, 0);

    for (int i = 0; i < KNOWN_TITLES_SIZE; ++i)
        SetUInt64Value(PLAYER__FIELD_KNOWN_TITLES + i, 0);  // 0=disabled
    SetUInt32Value(PLAYER_CHOSEN_TITLE, 0);

    SetUInt32Value(PLAYER_FIELD_KILLS, 0);
    SetUInt32Value(PLAYER_FIELD_LIFETIME_HONORABLE_KILLS, 0);
    SetUInt32Value(PLAYER_FIELD_TODAY_CONTRIBUTION, 0);
    SetUInt32Value(PLAYER_FIELD_YESTERDAY_CONTRIBUTION, 0);

    // set starting level
    uint32 start_level = GetClass() != CLASS_DEATH_KNIGHT
        ? sWorld->getIntConfig(CONFIG_START_PLAYER_LEVEL)
        : sWorld->getIntConfig(CONFIG_START_DEATH_KNIGHT_PLAYER_LEVEL);

    if (m_session->HasPermission(rbac::RBAC_PERM_USE_START_GM_LEVEL))
    {
        uint32 gm_level = sWorld->getIntConfig(CONFIG_START_GM_LEVEL);
        if (gm_level > start_level)
            start_level = gm_level;
    }

    SetLevel(start_level, false);

    InitRunes();

    SetMoney(sWorld->getIntConfig(CONFIG_START_PLAYER_MONEY));
    SetHonorPoints(sWorld->getIntConfig(CONFIG_START_HONOR_POINTS));
    SetArenaPoints(sWorld->getIntConfig(CONFIG_START_ARENA_POINTS));

    // Played time
    m_Last_tick = GameTime::GetGameTime();
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
    SetFullPower(POWER_MANA);

    // original spells
    LearnDefaultSkills();
    LearnCustomSpells();

    // original action bar
    for (PlayerCreateInfoActions::const_iterator action_itr = info->action.begin(); action_itr != info->action.end(); ++action_itr)
        addActionButton(action_itr->button, action_itr->action, action_itr->type);

    // original items
    if (CharStartOutfitEntry const* oEntry = GetCharStartOutfitEntry(createInfo->Race, createInfo->Class, createInfo->Gender))
    {
        for (int j = 0; j < MAX_OUTFIT_ITEMS; ++j)
        {
            if (oEntry->ItemId[j] <= 0)
                continue;

            uint32 itemId = oEntry->ItemId[j];

            // just skip, reported in ObjectMgr::LoadItemTemplates
            ItemTemplate const* iProto = sObjectMgr->GetItemTemplate(itemId);
            if (!iProto)
                continue;

            // BuyCount by default
            uint32 count = iProto->BuyCount;

            // special amount for food/drink
            if (iProto->Class == ITEM_CLASS_CONSUMABLE && iProto->SubClass == ITEM_SUBCLASS_FOOD)
            {
                switch (iProto->Spells[0].SpellCategory)
                {
                    case SPELL_CATEGORY_FOOD:                                // food
                        count = GetClass() == CLASS_DEATH_KNIGHT ? 10 : 4;
                        break;
                    case SPELL_CATEGORY_DRINK:                                // drink
                        count = 2;
                        break;
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
            // move other items to more appropriate slots (ammo not equipped in special bag)
            else
            {
                ItemPosCountVec sDest;
                msg = CanStoreItem(NULL_BAG, NULL_SLOT, sDest, pItem, false);
                if (msg == EQUIP_ERR_OK)
                {
                    RemoveItem(INVENTORY_SLOT_BAG_0, i, true);
                    StoreItem(sDest, pItem, true);
                }

                // if  this is ammo then use it
                msg = CanUseAmmo(pItem->GetEntry());
                if (msg == EQUIP_ERR_OK)
                    SetAmmo(pItem->GetEntry());
            }
        }
    }
    // all item positions resolved

    GetThreatManager().Initialize();

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
        StoreNewItem(sDest, titem_id, true, GenerateItemRandomPropertyId(titem_id));
        return true;                                        // stored
    }

    // item can't be added
    TC_LOG_ERROR("entities.player.items", "Player::StoreNewItemInBestSlots: Player '%s' (%s) can't equip or store initial item (ItemID: %u, Race: %u, Class: %u, InventoryResult: %u)",
        GetName().c_str(), GetGUID().ToString().c_str(), titem_id, GetRace(), GetClass(), msg);
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
    WorldPacket data(SMSG_START_MIRROR_TIMER, (21));
    data << (uint32)Type;
    data << CurrentValue;
    data << MaxValue;
    data << Regen;
    data << (uint8)0;
    data << (uint32)0;                                      // spell id
    SendDirectMessage(&data);
}

void Player::StopMirrorTimer(MirrorTimerType Type)
{
    m_MirrorTimer[Type] = DISABLED_MIRROR_TIMER;
    WorldPacket data(SMSG_STOP_MIRROR_TIMER, 4);
    data << (uint32)Type;
    SendDirectMessage(&data);
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
    switch (type)
    {
        case DAMAGE_LAVA:
        case DAMAGE_SLIME:
        {
            DamageInfo dmgInfo(this, this, damage, nullptr, type == DAMAGE_LAVA ? SPELL_SCHOOL_MASK_FIRE : SPELL_SCHOOL_MASK_NATURE, DIRECT_DAMAGE, BASE_ATTACK);
            Unit::CalcAbsorbResist(dmgInfo);
            absorb = dmgInfo.GetAbsorb();
            resist = dmgInfo.GetResist();
            damage = dmgInfo.GetDamage();
            break;
        }
        default:
            break;
    }

    Unit::DealDamageMods(this, damage, &absorb);

    WorldPacket data(SMSG_ENVIRONMENTALDAMAGELOG, (21));
    data << uint64(GetGUID());
    data << uint8(type != DAMAGE_FALL_TO_VOID ? type : DAMAGE_FALL);
    data << uint32(damage);
    data << uint32(absorb);
    data << uint32(resist);
    SendMessageToSet(&data, true);

    uint32 final_damage = Unit::DealDamage(this, this, damage, nullptr, SELF_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, nullptr, false);

    if (!IsAlive())
    {
        if (type == DAMAGE_FALL)                               // DealDamage does not apply item durability loss from self-induced damage.
        {
            TC_LOG_DEBUG("entities.player", "Player::EnvironmentalDamage: Player '%s' (%s) fall to death, losing 10%% durability",
                GetName().c_str(), GetGUID().ToString().c_str());
            DurabilityLossAll(0.10f, false);
            // durability lost message
            WorldPacket data2(SMSG_DURABILITY_DAMAGE_DEATH, 0);
            SendDirectMessage(&data2);
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
            UnderWaterTime *= GetTotalAuraMultiplier(SPELL_AURA_MOD_WATER_BREATHING);
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
            m_MirrorTimer[BREATH_TIMER] -= time_diff;
            // Timer limit - need deal damage
            if (m_MirrorTimer[BREATH_TIMER] < 0)
            {
                m_MirrorTimer[BREATH_TIMER] += 1 * IN_MILLISECONDS;
                // Calculate and deal damage
                /// @todo Check this formula
                uint32 damage = GetMaxHealth() / 5 + urand(0, GetLevel() - 1);
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
        m_MirrorTimer[BREATH_TIMER] += 10 * time_diff;
        if (m_MirrorTimer[BREATH_TIMER] >= UnderWaterTime || !IsAlive())
            StopMirrorTimer(BREATH_TIMER);
        else if (m_MirrorTimerFlagsLast & UNDERWATER_INWATER)
            SendMirrorTimer(BREATH_TIMER, UnderWaterTime, m_MirrorTimer[BREATH_TIMER], 10);
    }

    // In dark water
    if (m_MirrorTimerFlags & UNDERWATER_INDARKWATER)
    {
        // Fatigue timer not activated - activate it
        if (m_MirrorTimer[FATIGUE_TIMER] == DISABLED_MIRROR_TIMER)
        {
            m_MirrorTimer[FATIGUE_TIMER] = getMaxTimer(FATIGUE_TIMER);
            SendMirrorTimer(FATIGUE_TIMER, m_MirrorTimer[FATIGUE_TIMER], m_MirrorTimer[FATIGUE_TIMER], -1);
        }
        else
        {
            m_MirrorTimer[FATIGUE_TIMER] -= time_diff;
            // Timer limit - need deal damage or teleport ghost to graveyard
            if (m_MirrorTimer[FATIGUE_TIMER] < 0)
            {
                m_MirrorTimer[FATIGUE_TIMER] += 1 * IN_MILLISECONDS;
                if (IsAlive())                                            // Calculate and deal damage
                {
                    uint32 damage = GetMaxHealth() / 5 + urand(0, GetLevel() - 1);
                    EnvironmentalDamage(DAMAGE_EXHAUSTED, damage);
                }
                else if (HasFlag(PLAYER_FLAGS, PLAYER_FLAGS_GHOST))       // Teleport ghost to graveyard
                    RepopAtGraveyard();
            }
            else if (!(m_MirrorTimerFlagsLast & UNDERWATER_INDARKWATER))
                SendMirrorTimer(FATIGUE_TIMER, getMaxTimer(FATIGUE_TIMER), m_MirrorTimer[FATIGUE_TIMER], -1);
        }
    }
    else if (m_MirrorTimer[FATIGUE_TIMER] != DISABLED_MIRROR_TIMER)       // Regen timer
    {
        int32 DarkWaterTime = getMaxTimer(FATIGUE_TIMER);
        m_MirrorTimer[FATIGUE_TIMER] += 10 * time_diff;
        if (m_MirrorTimer[FATIGUE_TIMER] >= DarkWaterTime || !IsAlive())
            StopMirrorTimer(FATIGUE_TIMER);
        else if (m_MirrorTimerFlagsLast & UNDERWATER_INDARKWATER)
            SendMirrorTimer(FATIGUE_TIMER, DarkWaterTime, m_MirrorTimer[FATIGUE_TIMER], 10);
    }

    if (m_MirrorTimerFlags & (UNDERWATER_INLAVA /*| UNDERWATER_INSLIME*/) && !(_lastLiquid && _lastLiquid->SpellId))
    {
        // Breath timer not activated - activate it
        if (m_MirrorTimer[FIRE_TIMER] == DISABLED_MIRROR_TIMER)
            m_MirrorTimer[FIRE_TIMER] = getMaxTimer(FIRE_TIMER);
        else
        {
            m_MirrorTimer[FIRE_TIMER] -= time_diff;
            if (m_MirrorTimer[FIRE_TIMER] < 0)
            {
                m_MirrorTimer[FIRE_TIMER] += 1 * IN_MILLISECONDS;
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
    m_MirrorTimerFlags &= ~UNDERWATER_EXIST_TIMERS;
    for (uint8 i = 0; i < MAX_TIMERS; ++i)
    {
        if (m_MirrorTimer[i] != DISABLED_MIRROR_TIMER)
        {
            m_MirrorTimerFlags |= UNDERWATER_EXIST_TIMERS;
            break;
        }
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

    WorldPacket data(SMSG_CROSSED_INEBRIATION_THRESHOLD, (8+4+4));
    data << uint64(GetGUID());
    data << uint32(newDrunkenState);
    data << uint32(itemId);
    SendMessageToSet(&data, true);
}

void Player::Update(uint32 p_time)
{
    if (!IsInWorld())
        return;

    // undelivered mail
    if (m_nextMailDelivereTime && m_nextMailDelivereTime <= GameTime::GetGameTime())
    {
        SendNewMail();
        ++unReadMails;

        // It will be recalculate at mailbox open (for unReadMails important non-0 until mailbox open, it also will be recalculated)
        m_nextMailDelivereTime = 0;
    }

    // Update cinematic location, if 500ms have passed and we're doing a cinematic now.
    _cinematicMgr->m_cinematicDiff += p_time;
    if (_cinematicMgr->m_cinematicCamera && _cinematicMgr->m_activeCinematicCameraId && GetMSTimeDiffToNow(_cinematicMgr->m_lastCinematicCheck) > CINEMATIC_UPDATEDIFF)
    {
        _cinematicMgr->m_lastCinematicCheck = GameTime::GetGameTimeMS();
        _cinematicMgr->UpdateCinematicLocation(p_time);
    }

    //used to implement delayed far teleports
    SetCanDelayTeleport(true);
    Unit::Update(p_time);
    SetCanDelayTeleport(false);

    time_t now = GameTime::GetGameTime();

    UpdatePvPFlag(now);

    UpdateContestedPvP(p_time);

    UpdateDuelFlag(now);

    CheckDuelDistance(now);

    UpdateAfkReport(now);

    Unit::AIUpdateTick(p_time);

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
            time_t currTime = GameTime::GetGameTime();
            time_t timeDiff = currTime - _restTime;
            if (timeDiff >= 10)                             // freeze update
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

    // not auto-free ghost from body in instances or if its affected by risen ally
    if (m_deathTimer > 0 && !GetBaseMap()->Instanceable() && !HasAuraType(SPELL_AURA_PREVENT_RESURRECTION) && !IsGhouled())
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

    if (GetClass() == CLASS_DEATH_KNIGHT)
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
    m_groupUpdateTimer.Update(p_time);
    if (m_groupUpdateTimer.Passed())
    {
        SendUpdateToOutOfRangeGroupMembers();
        m_groupUpdateTimer.Reset(5000);
    }

    Pet* pet = GetPet();
    if (pet && !pet->IsWithinDistInMap(this, GetMap()->GetVisibilityRange()) && !pet->isPossessed())
    //if (pet && !pet->IsWithinDistInMap(this, GetMap()->GetVisibilityDistance()) && (GetCharmGUID() && (pet->GetGUID() != GetCharmGUID())))
        RemovePet(pet, PET_SAVE_NOT_IN_SLOT, true);

    if (IsAlive())
    {
        if (m_hostileReferenceCheckTimer <= p_time)
        {
            m_hostileReferenceCheckTimer = 15 * IN_MILLISECONDS;
            if (!GetMap()->IsDungeon())
                GetCombatManager().EndCombatBeyondRange(GetVisibilityRange(), true);
        }
        else
            m_hostileReferenceCheckTimer -= p_time;
    }

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

        // reset all death criterias
        ResetAchievementCriteria(ACHIEVEMENT_CRITERIA_CONDITION_NO_DEATH, 0);
    }

    Unit::setDeathState(s);

    // restore resurrection spell id for player after aura remove
    if (s == JUST_DIED && cur && ressSpellId)
        SetUInt32Value(PLAYER_SELF_RES_SPELL, ressSpellId);

    if (IsAlive() && !cur)
        //clear aura case after resurrection by another way (spells will be applied before next death)
        SetUInt32Value(PLAYER_SELF_RES_SPELL, 0);
}

bool Player::BuildEnumData(PreparedQueryResult result, WorldPacket* data)
{
    //        0                1                2                3                 4                  5                6                7
    // SELECT characters.guid, characters.name, characters.race, characters.class, characters.gender, characters.skin, characters.face, characters.hairStyle,
    // 8                     9                       10                11               12              13                     14                     15
    // characters.hairColor, characters.facialStyle, characters.level, characters.zone, characters.map, characters.position_x, characters.position_y, characters.position_z,
    // 16                    17                      18                   19                   20                     21                   22
    // guild_member.guildid, characters.playerFlags, characters.at_login, character_pet.entry, character_pet.modelid, character_pet.level, characters.equipmentCache,
    // 23                     24
    // character_banned.guid, character_declinedname.genitive

    Field* fields = result->Fetch();

    ObjectGuid::LowType guid = fields[0].GetUInt32();
    uint8 plrRace = fields[2].GetUInt8();
    uint8 plrClass = fields[3].GetUInt8();
    uint8 gender = fields[4].GetUInt8();

    PlayerInfo const* info = sObjectMgr->GetPlayerInfo(plrRace, plrClass);
    if (!info)
    {
        TC_LOG_ERROR("entities.player.loading", "Player %u has incorrect race/class pair. Don't build enum.", guid);
        return false;
    }
    else if (!IsValidGender(gender))
    {
        TC_LOG_ERROR("entities.player.loading", "Player (%u) has incorrect gender (%u), don't build enum.", guid, gender);
        return false;
    }

    *data << ObjectGuid(HighGuid::Player, guid);
    *data << fields[1].GetString();                         // name
    *data << uint8(plrRace);                                // race
    *data << uint8(plrClass);                               // class
    *data << uint8(gender);                                 // gender

    uint8 skin = fields[5].GetUInt8();
    uint8 face = fields[6].GetUInt8();
    uint8 hairStyle = fields[7].GetUInt8();
    uint8 hairColor = fields[8].GetUInt8();
    uint8 facialStyle = fields[9].GetUInt8();

    uint16 atLoginFlags = fields[18].GetUInt16();

    if (!ValidateAppearance(uint8(plrRace), uint8(plrClass), gender, hairStyle, hairColor, face, facialStyle, skin))
    {
        TC_LOG_ERROR("entities.player.loading", "Player %u has wrong Appearance values (Hair/Skin/Color), forcing recustomize", guid);

        // Make sure customization always works properly - send all zeroes instead
        skin = 0, face = 0, hairStyle = 0, hairColor = 0, facialStyle = 0;

        if (!(atLoginFlags & AT_LOGIN_CUSTOMIZE))
        {
            PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_ADD_AT_LOGIN_FLAG);
            stmt->setUInt16(0, uint16(AT_LOGIN_CUSTOMIZE));
            stmt->setUInt32(1, guid);
            CharacterDatabase.Execute(stmt);
            atLoginFlags |= AT_LOGIN_CUSTOMIZE;
        }
    }

    *data << uint8(skin);
    *data << uint8(face);
    *data << uint8(hairStyle);
    *data << uint8(hairColor);
    *data << uint8(facialStyle);

    *data << uint8(fields[10].GetUInt8());                   // level
    *data << uint32(fields[11].GetUInt16());                 // zone
    *data << uint32(fields[12].GetUInt16());                 // map

    *data << fields[13].GetFloat();                         // x
    *data << fields[14].GetFloat();                         // y
    *data << fields[15].GetFloat();                         // z

    *data << uint32(fields[16].GetUInt32());                // guild id

    uint32 charFlags = 0;
    uint32 playerFlags = fields[17].GetUInt32();
    if (atLoginFlags & AT_LOGIN_RESURRECT)
        playerFlags &= ~PLAYER_FLAGS_GHOST;
    if (playerFlags & PLAYER_FLAGS_HIDE_HELM)
        charFlags |= CHARACTER_FLAG_HIDE_HELM;
    if (playerFlags & PLAYER_FLAGS_HIDE_CLOAK)
        charFlags |= CHARACTER_FLAG_HIDE_CLOAK;
    if (playerFlags & PLAYER_FLAGS_GHOST)
        charFlags |= CHARACTER_FLAG_GHOST;
    if (atLoginFlags & AT_LOGIN_RENAME)
        charFlags |= CHARACTER_FLAG_RENAME;
    if (fields[23].GetUInt32())
        charFlags |= CHARACTER_FLAG_LOCKED_BY_BILLING;
    if (sWorld->getBoolConfig(CONFIG_DECLINED_NAMES_USED))
    {
        if (!fields[24].GetString().empty())
            charFlags |= CHARACTER_FLAG_DECLINED;
    }
    else
        charFlags |= CHARACTER_FLAG_DECLINED;

    *data << uint32(charFlags);                             // character flags

    // character customize flags
    if (atLoginFlags & AT_LOGIN_CUSTOMIZE)
        *data << uint32(CHAR_CUSTOMIZE_FLAG_CUSTOMIZE);
    else if (atLoginFlags & AT_LOGIN_CHANGE_FACTION)
        *data << uint32(CHAR_CUSTOMIZE_FLAG_FACTION);
    else if (atLoginFlags & AT_LOGIN_CHANGE_RACE)
        *data << uint32(CHAR_CUSTOMIZE_FLAG_RACE);
    else
        *data << uint32(CHAR_CUSTOMIZE_FLAG_NONE);

    // First login
    *data << uint8(atLoginFlags & AT_LOGIN_FIRST ? 1 : 0);

    // Pets info
    uint32 petDisplayId = 0;
    uint32 petLevel = 0;
    CreatureFamily petFamily = CREATURE_FAMILY_NONE;

    // show pet at selection character in character list only for non-ghost character
    if (result && !(playerFlags & PLAYER_FLAGS_GHOST) && (plrClass == CLASS_WARLOCK || plrClass == CLASS_HUNTER || plrClass == CLASS_DEATH_KNIGHT))
    {
        uint32 entry = fields[19].GetUInt32();
        CreatureTemplate const* creatureInfo = sObjectMgr->GetCreatureTemplate(entry);
        if (creatureInfo)
        {
            petDisplayId = fields[20].GetUInt32();
            petLevel = fields[21].GetUInt16();
            petFamily = creatureInfo->family;
        }
    }

    *data << uint32(petDisplayId);
    *data << uint32(petLevel);
    *data << uint32(petFamily);

    Tokenizer equipment(fields[22].GetString(), ' ');
    for (uint8 slot = 0; slot < INVENTORY_SLOT_BAG_END; ++slot)
    {
        uint32 visualBase = slot * 2;
        uint32 itemId = GetUInt32ValueFromArray(equipment, visualBase);
        ItemTemplate const* proto = sObjectMgr->GetItemTemplate(itemId);
        if (!proto)
        {
            *data << uint32(0);
            *data << uint8(0);
            *data << uint32(0);
            continue;
        }

        SpellItemEnchantmentEntry const* enchant = nullptr;

        uint32 enchants = GetUInt32ValueFromArray(equipment, visualBase + 1);
        for (uint8 enchantSlot = PERM_ENCHANTMENT_SLOT; enchantSlot <= TEMP_ENCHANTMENT_SLOT; ++enchantSlot)
        {
            // values stored in 2 uint16
            uint32 enchantId = 0x0000FFFF & (enchants >> enchantSlot * 16);
            if (!enchantId)
                continue;

            enchant = sSpellItemEnchantmentStore.LookupEntry(enchantId);
            if (enchant)
                break;
        }

        *data << uint32(proto->DisplayInfoID);
        *data << uint8(proto->InventoryType);
        *data << uint32(enchant ? enchant->aura_id : 0);
    }

    return true;
}

void Player::ToggleAFK()
{
    ToggleFlag(PLAYER_FLAGS, PLAYER_FLAGS_AFK);

    // afk player not allowed in battleground
    if (!IsGameMaster() && isAFK() && InBattleground() && !InArena())
        LeaveBattleground();
}

void Player::ToggleDND()
{
    ToggleFlag(PLAYER_FLAGS, PLAYER_FLAGS_DND);
}

uint8 Player::GetChatTag() const
{
    uint8 tag = CHAT_TAG_NONE;

    if (isGMChat())
        tag |= CHAT_TAG_GM;
    if (isDND())
        tag |= CHAT_TAG_DND;
    if (isAFK())
        tag |= CHAT_TAG_AFK;
    if (HasFlag(PLAYER_FLAGS, PLAYER_FLAGS_DEVELOPER))
        tag |= CHAT_TAG_DEV;

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
        TC_LOG_ERROR("entities.player.cheat", "Player::TeleportTo: Player '%s' (%s) tried to enter a forbidden map (MapID: %u)", GetGUID().ToString().c_str(), GetName().c_str(), mapid);
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
    if (GetSession()->Expansion() < mEntry->Expansion())
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
    DisableSpline();
    GetMotionMaster()->Remove(EFFECT_MOTION_TYPE);

    if (Transport* transport = GetTransport())
    {
        if (options & TELE_TO_NOT_LEAVE_TRANSPORT)
            AddUnitMovementFlag(MOVEMENTFLAG_ONTRANSPORT);
        else
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

        if (!IsAlive() && options & TELE_REVIVE_AT_TELEPORT)
            ResurrectPlayer(0.5f);

        if (!(options & TELE_TO_NOT_LEAVE_COMBAT))
            CombatStop();

        // this will be used instead of the current location in SaveToDB
        m_teleport_dest = WorldLocation(mapid, x, y, z, orientation);
        SetFallInformation(0, GetPositionZ());

        // code for finish transfer called in WorldSession::HandleMovementOpcodes()
        // at client packet MSG_MOVE_TELEPORT_ACK
        SetSemaphoreTeleportNear(true);
        // near teleport, triggering send MSG_MOVE_TELEPORT_ACK from client at landing
        if (!GetSession()->PlayerLogout())
            SendTeleportPacket(m_teleport_dest, (options & TELE_TO_TRANSPORT_TELEPORT) != 0);
    }
    else
    {
        if (GetClass() == CLASS_DEATH_KNIGHT && GetMapId() == 609 && !IsGameMaster() && !HasSpell(50977))
            return false;

        // far teleport to another map
        Map* oldmap = IsInWorld() ? GetMap() : nullptr;
        // check if we can enter before stopping combat / removing pet / totems / interrupting spells

        // Check enter rights before map getting to avoid creating instance copy for player
        // this check not dependent from map instance copy and same for all instance copies of selected map
        if (sMapMgr->PlayerCannotEnter(mapid, this, false))
            return false;

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
            if (mEntry->IsBattleArena() && !IsGameMaster())
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

            if (!GetSession()->PlayerLogout())
            {
                // send transfer packets
                WorldPacket data(SMSG_TRANSFER_PENDING, 4 + 4 + 4);
                data << uint32(mapid);
                if (Transport* transport = GetTransport())
                    data << transport->GetEntry() << GetMapId();

                SendDirectMessage(&data);
            }

            // remove from old map now
            if (oldmap)
                oldmap->RemovePlayerFromMap(this, false);

            m_teleport_dest = WorldLocation(mapid, x, y, z, orientation);
            m_teleport_options = options;
            SetFallInformation(0, GetPositionZ());
            // if the player is saved before worldportack (at logout for example)
            // this will be used instead of the current location in SaveToDB

            if (!GetSession()->PlayerLogout())
            {
                WorldPacket data(SMSG_NEW_WORLD, 4 + 4 + 4 + 4 + 4);
                data << uint32(mapid);
                if (GetTransport())
                    data << m_movementInfo.transport.pos.PositionXYZOStream();
                else
                    data << m_teleport_dest.PositionXYZOStream();

                SendDirectMessage(&data);
                SendSavedInstances();
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

bool Player::TeleportTo(WorldLocation const& loc, uint32 options /*= 0*/)
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
        ClearComboPoints();
        ClearComboPointHolders();
        ObjectGuid lootGuid = GetLootGUID();
        if (!lootGuid.IsEmpty())
            m_session->DoLootRelease(lootGuid);
        sOutdoorPvPMgr->HandlePlayerLeaveZone(this, m_zoneUpdateId);
        sBattlefieldMgr->HandlePlayerLeaveZone(this, m_zoneUpdateId);
    }

    // Remove items from world before self - player must be found in Item::RemoveFromObjectUpdate
    for (uint8 i = PLAYER_SLOT_START; i < PLAYER_SLOT_END; ++i)
    {
        if (m_items[i])
            m_items[i]->RemoveFromWorld();
    }

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

void Player::SetObjectScale(float scale)
{
    Unit::SetObjectScale(scale);
    SetFloatValue(UNIT_FIELD_BOUNDINGRADIUS, scale * DEFAULT_PLAYER_BOUNDING_RADIUS);
    SetFloatValue(UNIT_FIELD_COMBATREACH, scale * DEFAULT_PLAYER_COMBAT_REACH);
}

bool Player::IsImmunedToSpellEffect(SpellInfo const* spellInfo, uint32 index, WorldObject const* caster) const
{
    // players are immune to taunt (the aura and the spell effect)
    if (spellInfo->Effects[index].IsAura(SPELL_AURA_MOD_TAUNT))
        return true;
    if (spellInfo->Effects[index].IsEffect(SPELL_EFFECT_ATTACK_ME))
        return true;

    return Unit::IsImmunedToSpellEffect(spellInfo, index, caster);
}

void Player::RegenerateAll()
{
    //if (m_regenTimer <= 500)
    //    return;

    m_regenTimerCount += m_regenTimer;
    m_foodEmoteTimerCount += m_regenTimer;

    Regenerate(POWER_ENERGY);

    Regenerate(POWER_MANA);

    // Runes act as cooldowns, and they don't need to send any data
    if (GetClass() == CLASS_DEATH_KNIGHT)
        for (uint8 i = 0; i < MAX_RUNES; ++i)
            if (uint32 cd = GetRuneCooldown(i))
                SetRuneCooldown(i, (cd > m_regenTimer) ? cd - m_regenTimer : 0);

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
        if (GetClass() == CLASS_DEATH_KNIGHT)
            Regenerate(POWER_RUNIC_POWER);

        m_regenTimerCount -= 2000;
    }

    m_regenTimer = 0;

    // Handles the emotes for drinking and eating.
    // According to sniffs there is a background timer going on that repeats independed from the time window where the aura applies.
    // That's why we dont need to reset the timer on apply. In sniffs I have seen that the first call for the spell visual is totally random, then after
    // 5 seconds over and over again which confirms my theory that we have a independed timer.
    if (m_foodEmoteTimerCount >= 5000)
    {
        std::vector<AuraEffect*> auraList;
        AuraEffectList const& ModRegenAuras = GetAuraEffectsByType(SPELL_AURA_MOD_REGEN);
        AuraEffectList const& ModPowerRegenAuras = GetAuraEffectsByType(SPELL_AURA_MOD_POWER_REGEN);

        auraList.reserve(ModRegenAuras.size() + ModPowerRegenAuras.size());
        auraList.insert(auraList.end(), ModRegenAuras.begin(), ModRegenAuras.end());
        auraList.insert(auraList.end(), ModPowerRegenAuras.begin(), ModPowerRegenAuras.end());

        for (auto itr = auraList.begin(); itr != auraList.end(); ++itr)
        {
            // Food emote comes above drinking emote if we have to decide (mage regen food for example)
            if ((*itr)->GetBase()->HasEffectType(SPELL_AURA_MOD_REGEN) && (*itr)->GetSpellInfo()->AuraInterruptFlags & AURA_INTERRUPT_FLAG_NOT_SEATED)
            {
                SendPlaySpellVisual(SPELL_VISUAL_KIT_FOOD);
                break;
            }
            else if ((*itr)->GetBase()->HasEffectType(SPELL_AURA_MOD_POWER_REGEN) && (*itr)->GetSpellInfo()->AuraInterruptFlags & AURA_INTERRUPT_FLAG_NOT_SEATED)
            {
                SendPlaySpellVisual(SPELL_VISUAL_KIT_DRINK);
                break;
            }
        }
        m_foodEmoteTimerCount -= 5000;
    }
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

    float addvalue = 0.0f;

    switch (power)
    {
        case POWER_MANA:
        {
            bool recentCast = IsUnderLastManaUseEffect();
            float ManaIncreaseRate = sWorld->getRate(RATE_POWER_MANA);

            if (GetLevel() < 15)
                ManaIncreaseRate = sWorld->getRate(RATE_POWER_MANA) * (2.066f - (GetLevel() * 0.066f));

            if (recentCast) // Trinity Updates Mana in intervals of 2s, which is correct
                addvalue += GetFloatValue(UNIT_FIELD_POWER_REGEN_INTERRUPTED_FLAT_MODIFIER) *  ManaIncreaseRate * 0.001f * m_regenTimer;
            else
                addvalue += GetFloatValue(UNIT_FIELD_POWER_REGEN_FLAT_MODIFIER) * ManaIncreaseRate * 0.001f * m_regenTimer;
        }   break;
        case POWER_RAGE:                                    // Regenerate rage
        {
            if (!IsInCombat() && !HasAuraType(SPELL_AURA_INTERRUPT_REGEN))
            {
                float RageDecreaseRate = sWorld->getRate(RATE_POWER_RAGE_LOSS);
                addvalue += -20 * RageDecreaseRate;               // 2 rage by tick (= 2 seconds => 1 rage/sec)
            }
        }   break;
        case POWER_ENERGY:                                  // Regenerate energy (rogue)
            addvalue += 0.01f * m_regenTimer * sWorld->getRate(RATE_POWER_ENERGY);
            break;
        case POWER_RUNIC_POWER:
        {
            if (!IsInCombat() && !HasAuraType(SPELL_AURA_INTERRUPT_REGEN))
            {
                float RunicPowerDecreaseRate = sWorld->getRate(RATE_POWER_RUNICPOWER_LOSS);
                addvalue += -30 * RunicPowerDecreaseRate;         // 3 RunicPower by tick
            }
        }   break;
        case POWER_RUNE:
        case POWER_FOCUS:
        case POWER_HAPPINESS:
            break;
        case POWER_HEALTH:
            return;
        default:
            break;
    }

    // Mana regen calculated in Player::UpdateManaRegen()
    if (power != POWER_MANA)
    {
        addvalue *= GetTotalAuraMultiplierByMiscValue(SPELL_AURA_MOD_POWER_REGEN_PERCENT, power);

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

    addvalue += m_powerFraction[power];
    uint32 integerValue = uint32(std::fabs(addvalue));

    if (addvalue < 0.0f)
    {
        if (curValue > integerValue)
        {
            curValue -= integerValue;
            m_powerFraction[power] = addvalue + integerValue;
        }
        else
        {
            curValue = 0;
            m_powerFraction[power] = 0;
        }
    }
    else
    {
        curValue += integerValue;

        if (curValue > maxValue)
        {
            curValue = maxValue;
            m_powerFraction[power] = 0;
        }
        else
            m_powerFraction[power] = addvalue - integerValue;
    }
    if (m_regenTimerCount >= 2000)
        SetPower(power, curValue);
    else
        UpdateUInt32Value(UNIT_FIELD_POWER1 + power, curValue);
}

void Player::RegenerateHealth()
{
    uint32 curValue = GetHealth();
    uint32 maxValue = GetMaxHealth();

    if (curValue >= maxValue)
        return;

    float HealthIncreaseRate = sWorld->getRate(RATE_HEALTH);

    if (GetLevel() < 15)
        HealthIncreaseRate = sWorld->getRate(RATE_HEALTH) * (2.066f - (GetLevel() * 0.066f));

    float addValue = 0.0f;

    // polymorphed case
    if (IsPolymorphed())
        addValue = float(GetMaxHealth()) / 3.0f;
    // normal regen case (maybe partly in combat case)
    else if (!IsInCombat() || HasAuraType(SPELL_AURA_MOD_REGEN_DURING_COMBAT))
    {
        addValue = OCTRegenHPPerSpirit() * HealthIncreaseRate;
        if (!IsInCombat())
        {
            addValue *= GetTotalAuraMultiplier(SPELL_AURA_MOD_HEALTH_REGEN_PERCENT);

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
    SetFullHealth();
    switch (GetPowerType())
    {
        case POWER_MANA:
            SetFullPower(POWER_MANA);
            break;
        case POWER_RAGE:
            SetPower(POWER_RAGE, 0);
            break;
        case POWER_ENERGY:
            SetFullPower(POWER_ENERGY);
            break;
        case POWER_RUNIC_POWER:
            SetPower(POWER_RUNIC_POWER, 0);
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

Creature* Player::GetNPCIfCanInteractWith(ObjectGuid const& guid, uint32 npcflagmask) const
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
    if (!IsAlive() && !(creature->GetCreatureTemplate()->type_flags & CREATURE_TYPE_FLAG_GHOST_VISIBLE))
        return nullptr;

    // alive or spirit healer
    if (!creature->IsAlive() && !(creature->GetCreatureTemplate()->type_flags & CREATURE_TYPE_FLAG_CAN_INTERACT_WHILE_DEAD))
        return nullptr;

    // appropriate npc type
    if (npcflagmask && !creature->HasFlag(UNIT_NPC_FLAGS, npcflagmask))
        return nullptr;

    // not allow interaction under control, but allow with own pets
    if (creature->GetCharmerGUID())
        return nullptr;

    // not unfriendly/hostile
    if (creature->GetReactionTo(this) <= REP_UNFRIENDLY)
        return nullptr;

    // not too far, taken from CGGameUI::SetInteractTarget
    if (!creature->IsWithinDistInMap(this, creature->GetCombatReach() + 4.0f))
        return nullptr;

    return creature;
}

GameObject* Player::GetGameObjectIfCanInteractWith(ObjectGuid const& guid) const
{
    if (!guid)
        return nullptr;

    if (!IsInWorld())
        return nullptr;

    if (IsInFlight())
        return nullptr;

    // exist
    GameObject* go = ObjectAccessor::GetGameObject(*this, guid);
    if (!go)
        return nullptr;

    // Players cannot interact with gameobjects that use the "Point" icon
    if (go->GetGOInfo()->IconName == "Point")
        return nullptr;

    if (!go->IsWithinDistInMap(this))
        return nullptr;

    return go;
}

GameObject* Player::GetGameObjectIfCanInteractWith(ObjectGuid const& guid, GameobjectTypes type) const
{
    GameObject* go = GetGameObjectIfCanInteractWith(guid);
    if (!go)
        return nullptr;

    if (go->GetGoType() != type)
        return nullptr;

    return go;
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
}

bool Player::IsInAreaTriggerRadius(AreaTriggerEntry const* trigger) const
{
    if (!trigger || GetMapId() != trigger->mapid)
        return false;

    if (trigger->radius > 0.f)
    {
        // if we have radius check it
        float dist = GetDistance(trigger->x, trigger->y, trigger->z);
        if (dist > trigger->radius)
            return false;
    }
    else
    {
        Position center(trigger->x, trigger->y, trigger->z, trigger->box_orientation);
        if (!IsWithinBox(center, trigger->box_x / 2.f, trigger->box_y / 2.f, trigger->box_z / 2.f))
            return false;
    }

    return true;
}

void Player::SetGameMaster(bool on)
{
    if (on)
    {
        m_ExtraFlags |= PLAYER_EXTRA_GM_ON;
        SetFaction(FACTION_FRIENDLY);
        SetFlag(PLAYER_FLAGS, PLAYER_FLAGS_GM);
        SetFlag(UNIT_FIELD_FLAGS_2, UNIT_FLAG2_ALLOW_CHEAT_SPELLS);

        if (Pet* pet = GetPet())
            pet->SetFaction(FACTION_FRIENDLY);

        RemoveByteFlag(UNIT_FIELD_BYTES_2, UNIT_BYTES_2_OFFSET_PVP_FLAG, UNIT_BYTE2_FLAG_FFA_PVP);
        ResetContestedPvP();

        CombatStopWithPets();

        SetPhaseMask(uint32(PHASEMASK_ANYWHERE), false);    // see and visible in all phases
        m_serverSideVisibilityDetect.SetValue(SERVERSIDE_VISIBILITY_GM, GetSession()->GetSecurity());
    }
    else
    {
        // restore phase
        uint32 newPhase = 0;
        AuraEffectList const& phases = GetAuraEffectsByType(SPELL_AURA_PHASE);
        if (!phases.empty())
            for (AuraEffectList::const_iterator itr = phases.begin(); itr != phases.end(); ++itr)
                newPhase |= (*itr)->GetMiscValue();

        if (!newPhase)
            newPhase = PHASEMASK_NORMAL;

        SetPhaseMask(newPhase, false);

        m_ExtraFlags &= ~ PLAYER_EXTRA_GM_ON;
        SetFactionForRace(GetRace());
        RemoveFlag(PLAYER_FLAGS, PLAYER_FLAGS_GM);
        RemoveFlag(UNIT_FIELD_FLAGS_2, UNIT_FLAG2_ALLOW_CHEAT_SPELLS);

        if (Pet* pet = GetPet())
            pet->SetFaction(GetFaction());

        // restore FFA PvP Server state
        if (sWorld->IsFFAPvPRealm())
            SetByteFlag(UNIT_FIELD_BYTES_2, UNIT_BYTES_2_OFFSET_PVP_FLAG, UNIT_BYTE2_FLAG_FFA_PVP);

        // restore FFA PvP area state, remove not allowed for GM mounts
        UpdateArea(m_areaUpdateId);

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

    for (Channel* channel : m_channels)
        channel->SetInvisible(this, !on);
}

bool Player::IsGroupVisibleFor(Player const* p) const
{
    switch (sWorld->getIntConfig(CONFIG_GROUP_VISIBILITY))
    {
        default: return IsInSameGroupWith(p);
        case 1:  return IsInSameRaidWith(p);
        case 2:  return GetTeam() == p->GetTeam();
        case 3:  return false;
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
void Player::UninviteFromGroup()
{
    Group* group = GetGroupInvite();
    if (!group)
        return;

    group->RemoveInvite(this);

    if (group->IsCreated())
    {
        if (group->GetMembersCount() <= 1) // group has just 1 member => disband
            group->Disband(true);
    }
    else
    {
        if (group->GetInviteeCount() <= 1)
        {
            group->RemoveAllInvites();
            delete group;
        }
    }
}

void Player::RemoveFromGroup(Group* group, ObjectGuid guid, RemoveMethod method /*= GROUP_REMOVEMETHOD_DEFAULT*/, ObjectGuid kicker /*= ObjectGuid::Empty*/, char const* reason /*= nullptr*/)
{
    if (!group)
        return;

    group->RemoveMember(guid, method, kicker, reason);
}

void Player::SendLogXPGain(uint32 GivenXP, Unit* victim, uint32 BonusXP, bool recruitAFriend, float /*group_rate*/) const
{
    WorldPacket data(SMSG_LOG_XPGAIN, 21); // guess size?
    data << uint64(victim ? victim->GetGUID() : ObjectGuid::Empty);
    data << uint32(GivenXP + BonusXP);                      // given experience
    data << uint8(victim ? 0 : 1);                          // 00-kill_xp type, 01-non_kill_xp type

    if (victim)
    {
        data << uint32(GivenXP);                            // experience without bonus

        // should use group_rate here but can't figure out how
        data << float(1);                                   // 1 - none 0 - 100% group bonus output
    }

    data << uint8(recruitAFriend ? 1 : 0);                  // does the GivenXP include a RaF bonus?
    SendDirectMessage(&data);
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

    uint8 level = GetLevel();

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

    SendLogXPGain(xp, victim, bonus_xp, recruitAFriend, group_rate);

    uint32 nextLvlXP = GetUInt32Value(PLAYER_NEXT_LEVEL_XP);
    uint32 newXP = GetXP() + xp + bonus_xp;

    while (newXP >= nextLvlXP && level < sWorld->getIntConfig(CONFIG_MAX_PLAYER_LEVEL))
    {
        newXP -= nextLvlXP;

        if (level < sWorld->getIntConfig(CONFIG_MAX_PLAYER_LEVEL))
            GiveLevel(level + 1);

        level = GetLevel();
        nextLvlXP = GetUInt32Value(PLAYER_NEXT_LEVEL_XP);
    }

    SetXP(newXP);
}

// Update player to next level
// Current player experience not update (must be update by caller)
void Player::GiveLevel(uint8 level)
{
    uint8 oldLevel = GetLevel();
    if (level == oldLevel)
        return;

    if (Guild* guild = GetGuild())
        guild->UpdateMemberData(this, GUILD_MEMBER_DATA_LEVEL, level);

    PlayerLevelInfo info;
    sObjectMgr->GetPlayerLevelInfo(GetRace(), GetClass(), level, &info);

    PlayerClassLevelInfo classInfo;
    sObjectMgr->GetPlayerClassLevelInfo(GetClass(), level, &classInfo);

    // send levelup info to client
    WorldPacket data(SMSG_LEVELUP_INFO, (4+4+MAX_POWERS*4+MAX_STATS*4));
    data << uint32(level);
    data << uint32(int32(classInfo.basehealth) - int32(GetCreateHealth()));
    // for (int i = 0; i < MAX_POWERS; ++i)                  // Powers loop (0-6)
    data << uint32(int32(classInfo.basemana)   - int32(GetCreateMana()));
    data << uint32(0);
    data << uint32(0);
    data << uint32(0);
    data << uint32(0);
    data << uint32(0);
    data << uint32(0);
    // end for
    for (uint8 i = STAT_STRENGTH; i < MAX_STATS; ++i)          // Stats loop (0-4)
        data << uint32(int32(info.stats[i]) - GetCreateStat(Stats(i)));

    SendDirectMessage(&data);

    SetUInt32Value(PLAYER_NEXT_LEVEL_XP, sObjectMgr->GetXPForLevel(level));

    //update level, max level of skills
    m_Played_time[PLAYED_TIME_LEVEL] = 0;                   // Level Played Time reset

    _ApplyAllLevelScaleItemMods(false);

    SetLevel(level);

    UpdateSkillsForLevel();

    // save base values (bonuses already included in stored stats
    for (uint8 i = STAT_STRENGTH; i < MAX_STATS; ++i)
        SetCreateStat(Stats(i), info.stats[i]);

    SetCreateHealth(classInfo.basehealth);
    SetCreateMana(classInfo.basemana);

    InitTalentForLevel();
    InitTaxiNodesForLevel();
    InitGlyphsForLevel();

    UpdateAllStats();

    if (sWorld->getBoolConfig(CONFIG_ALWAYS_MAXSKILL)) // Max weapon skill when leveling up
        UpdateWeaponsSkillsToMaxSkillsForLevel();

    _ApplyAllLevelScaleItemMods(true);

    // set current level health and mana/energy to maximum after applying all mods.
    SetFullHealth();
    SetFullPower(POWER_MANA);

    // update level to hunter/summon pet
    if (Pet* pet = GetPet())
        pet->SynchronizeLevelWithOwner();

    if (MailLevelReward const* mailReward = sObjectMgr->GetMailLevelReward(level, GetRaceMask()))
    {
        /// @todo Poor design of mail system
        SQLTransaction trans = CharacterDatabase.BeginTransaction();
        MailDraft(mailReward->mailTemplateId).SendMailTo(trans, this, MailSender(MAIL_CREATURE, mailReward->senderEntry));
        CharacterDatabase.CommitTransaction(trans);
    }

    UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_REACH_LEVEL);

    // Refer-A-Friend
    if (GetSession()->GetRecruiterId())
        if (level < sWorld->getIntConfig(CONFIG_MAX_RECRUIT_A_FRIEND_BONUS_PLAYER_LEVEL))
            if (level % 2 == 0)
            {
                ++m_grantableLevels;

                if (!HasByteFlag(PLAYER_FIELD_BYTES, PLAYER_FIELD_BYTES_OFFSET_RAF_GRANTABLE_LEVEL, 0x01))
                    SetByteFlag(PLAYER_FIELD_BYTES, PLAYER_FIELD_BYTES_OFFSET_RAF_GRANTABLE_LEVEL, 0x01);
            }

    SendQuestGiverStatusMultiple();

    sScriptMgr->OnPlayerLevelChanged(this, oldLevel);
}

void Player::InitTalentForLevel()
{
    uint8 level = GetLevel();
    // talents base at level diff (talents = level - 9 but some can be used already)
    if (level < 10)
    {
        // Remove all talent points
        if (m_usedTalentCount > 0)                           // Free any used talents
        {
            ResetTalents(true); /// @todo: Has to (collectively) be renamed to ResetTalents
            SetFreeTalentPoints(0);
        }
    }
    else
    {
        if (level < sWorld->getIntConfig(CONFIG_MIN_DUALSPEC_LEVEL) || m_specsCount == 0)
        {
            m_specsCount = 1;
            m_activeSpec = 0;
        }

        uint32 talentPointsForLevel = CalculateTalentsPoints();

        // if used more that have then reset
        if (m_usedTalentCount > talentPointsForLevel)
        {
            if (!GetSession()->HasPermission(rbac::RBAC_PERM_SKIP_CHECK_MORE_TALENTS_THAN_ALLOWED))
                ResetTalents(true);
            else
                SetFreeTalentPoints(0);
        }
        // else update amount of free points
        else
            SetFreeTalentPoints(talentPointsForLevel - m_usedTalentCount);
    }

    if (!GetSession()->PlayerLoading())
        SendTalentsInfoData(false);                         // update at client
}

void Player::InitStatsForLevel(bool reapplyMods)
{
    if (reapplyMods)                                        //reapply stats values only on .reset stats (level) command
        _RemoveAllStatBonuses();

    PlayerClassLevelInfo classInfo;
    sObjectMgr->GetPlayerClassLevelInfo(GetClass(), GetLevel(), &classInfo);

    PlayerLevelInfo info;
    sObjectMgr->GetPlayerLevelInfo(GetRace(), GetClass(), GetLevel(), &info);

    SetUInt32Value(PLAYER_FIELD_MAX_LEVEL, sWorld->getIntConfig(CONFIG_MAX_PLAYER_LEVEL));
    SetUInt32Value(PLAYER_NEXT_LEVEL_XP, sObjectMgr->GetXPForLevel(GetLevel()));

    // reset before any aura state sources (health set/aura apply)
    SetUInt32Value(UNIT_FIELD_AURASTATE, 0);

    UpdateSkillsForLevel();

    // set default cast time multiplier
    SetFloatValue(UNIT_MOD_CAST_SPEED, 1.0f);

    // reset size before reapply auras
    SetObjectScale(1.0f);

    // save base values (bonuses already included in stored stats
    for (uint8 i = STAT_STRENGTH; i < MAX_STATS; ++i)
        SetCreateStat(Stats(i), info.stats[i]);

    for (uint8 i = STAT_STRENGTH; i < MAX_STATS; ++i)
        SetStat(Stats(i), info.stats[i]);

    SetCreateHealth(classInfo.basehealth);

    //set create powers
    SetCreateMana(classInfo.basemana);

    SetArmor(int32(m_createStats[STAT_AGILITY]*2));

    InitStatBuffMods();

    //reset rating fields values
    for (uint16 index = PLAYER_FIELD_COMBAT_RATING_1; index < PLAYER_FIELD_COMBAT_RATING_1 + MAX_COMBAT_RATING; ++index)
        SetUInt32Value(index, 0);

    SetUInt32Value(PLAYER_FIELD_MOD_HEALING_DONE_POS, 0);
    for (uint8 i = SPELL_SCHOOL_NORMAL; i < MAX_SPELL_SCHOOL; ++i)
    {
        SetInt32Value(PLAYER_FIELD_MOD_DAMAGE_DONE_NEG + i, 0);
        SetInt32Value(PLAYER_FIELD_MOD_DAMAGE_DONE_POS + i, 0);
        SetFloatValue(PLAYER_FIELD_MOD_DAMAGE_DONE_PCT + i, 1.00f);
    }

    //reset attack power, damage and attack speed fields
    for (uint8 i = BASE_ATTACK; i < MAX_ATTACK; ++i)
        SetFloatValue(UNIT_FIELD_BASEATTACKTIME + i, float(BASE_ATTACK_TIME));

    SetFloatValue(UNIT_FIELD_MINDAMAGE, 0.0f);
    SetFloatValue(UNIT_FIELD_MAXDAMAGE, 0.0f);
    SetFloatValue(UNIT_FIELD_MINOFFHANDDAMAGE, 0.0f);
    SetFloatValue(UNIT_FIELD_MAXOFFHANDDAMAGE, 0.0f);
    SetFloatValue(UNIT_FIELD_MINRANGEDDAMAGE, 0.0f);
    SetFloatValue(UNIT_FIELD_MAXRANGEDDAMAGE, 0.0f);

    SetInt32Value(UNIT_FIELD_ATTACK_POWER,            0);
    SetInt32Value(UNIT_FIELD_ATTACK_POWER_MODS,       0);
    SetFloatValue(UNIT_FIELD_ATTACK_POWER_MULTIPLIER, 0.0f);
    SetInt32Value(UNIT_FIELD_RANGED_ATTACK_POWER,     0);
    SetInt32Value(UNIT_FIELD_RANGED_ATTACK_POWER_MODS, 0);
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
    SetUInt32Value(PLAYER_SHIELD_BLOCK, 0);

    // Dodge percentage
    SetFloatValue(PLAYER_DODGE_PERCENTAGE, 0.0f);

    // set armor (resistance 0) to original value (create_agility*2)
    SetArmor(int32(m_createStats[STAT_AGILITY]*2));
    SetFloatValue(UNIT_FIELD_RESISTANCEBUFFMODSPOSITIVE + SPELL_SCHOOL_NORMAL, 0.0f);
    SetFloatValue(UNIT_FIELD_RESISTANCEBUFFMODSNEGATIVE + SPELL_SCHOOL_NORMAL, 0.0f);
    // set other resistance to original value (0)
    for (uint8 i = SPELL_SCHOOL_HOLY; i < MAX_SPELL_SCHOOL; ++i)
    {
        SetResistance(SpellSchools(i), 0);
        SetFloatValue(UNIT_FIELD_RESISTANCEBUFFMODSPOSITIVE + i, 0.0f);
        SetFloatValue(UNIT_FIELD_RESISTANCEBUFFMODSNEGATIVE + i, 0.0f);
    }

    SetUInt32Value(PLAYER_FIELD_MOD_TARGET_RESISTANCE, 0);
    SetUInt32Value(PLAYER_FIELD_MOD_TARGET_PHYSICAL_RESISTANCE, 0);
    for (uint8 i = SPELL_SCHOOL_NORMAL; i < MAX_SPELL_SCHOOL; ++i)
    {
        SetUInt32Value(UNIT_FIELD_POWER_COST_MODIFIER + i, 0);
        SetFloatValue(UNIT_FIELD_POWER_COST_MULTIPLIER + i, 0.0f);
    }
    // Reset no reagent cost field
    for (uint8 i = 0; i < 3; ++i)
        SetUInt32Value(PLAYER_NO_REAGENT_COST_1 + i, 0);
    // Init data for form but skip reapply item mods for form
    InitDataForForm(reapplyMods);

    // save new stats
    for (uint8 i = POWER_MANA; i < MAX_POWERS; ++i)
        SetMaxPower(Powers(i), uint32(GetCreatePowerValue(Powers(i))));

    SetMaxHealth(classInfo.basehealth);                     // stamina bonus will applied later

    // cleanup mounted state (it will set correctly at aura loading if player saved at mount.
    SetUInt32Value(UNIT_FIELD_MOUNTDISPLAYID, 0);

    // cleanup unit flags (will be re-applied if need at aura load).
    RemoveFlag(UNIT_FIELD_FLAGS,
        UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_REMOVE_CLIENT_CONTROL | UNIT_FLAG_NOT_ATTACKABLE_1 |
        UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC  | UNIT_FLAG_LOOTING          |
        UNIT_FLAG_PET_IN_COMBAT  | UNIT_FLAG_SILENCED     | UNIT_FLAG_PACIFIED         |
        UNIT_FLAG_STUNNED        | UNIT_FLAG_IN_COMBAT    | UNIT_FLAG_DISARMED         |
        UNIT_FLAG_CONFUSED       | UNIT_FLAG_FLEEING      | UNIT_FLAG_NOT_SELECTABLE   |
        UNIT_FLAG_SKINNABLE      | UNIT_FLAG_MOUNT        | UNIT_FLAG_TAXI_FLIGHT      );
    SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_PLAYER_CONTROLLED);   // must be set

    SetFlag(UNIT_FIELD_FLAGS_2, UNIT_FLAG2_REGENERATE_POWER);// must be set

    // cleanup player flags (will be re-applied if need at aura load), to avoid have ghost flag without ghost aura, for example.
    RemoveFlag(PLAYER_FLAGS, PLAYER_FLAGS_AFK | PLAYER_FLAGS_DND | PLAYER_FLAGS_GM | PLAYER_FLAGS_GHOST | PLAYER_ALLOW_ONLY_ABILITY);

    RemoveStandFlags(UNIT_STAND_FLAGS_ALL);                 // one form stealth modified bytes
    RemoveByteFlag(UNIT_FIELD_BYTES_2, UNIT_BYTES_2_OFFSET_PVP_FLAG, UNIT_BYTE2_FLAG_FFA_PVP | UNIT_BYTE2_FLAG_SANCTUARY);

    // restore if need some important flags
    SetUInt32Value(PLAYER_FIELD_BYTES2, 0);                 // flags empty by default

    if (reapplyMods)                                        // reapply stats values only on .reset stats (level) command
        _ApplyAllStatBonuses();

    // set current level health and mana/energy to maximum after applying all mods.
    SetFullHealth();
    SetFullPower(POWER_MANA);
    SetFullPower(POWER_ENERGY);
    if (GetPower(POWER_RAGE) > GetMaxPower(POWER_RAGE))
        SetFullPower(POWER_RAGE);
    SetFullPower(POWER_FOCUS);
    SetPower(POWER_HAPPINESS, 0);
    SetPower(POWER_RUNIC_POWER, 0);

    // update level to hunter/summon pet
    if (Pet* pet = GetPet())
        pet->SynchronizeLevelWithOwner();
}

void Player::SendInitialSpells()
{
    uint16 spellCooldowns = GetSpellHistory()->GetCooldownsSizeForPacket();
    uint16 spellCount = 0;

    WorldPacket data(SMSG_INITIAL_SPELLS, (1 + 2 + 4 * m_spells.size() + 2 + spellCooldowns * (2 + 2 + 2 + 4 + 4)));
    data << uint8(0);

    size_t countPos = data.wpos();
    data << uint16(spellCount);                             // spell count placeholder

    for (PlayerSpellMap::const_iterator itr = m_spells.begin(); itr != m_spells.end(); ++itr)
    {
        if (itr->second->state == PLAYERSPELL_REMOVED)
            continue;

        if (!itr->second->active || itr->second->disabled)
            continue;

        data << uint32(itr->first);
        data << uint16(0);                                  // it's not slot id

        spellCount +=1;
    }

    data.put<uint16>(countPos, spellCount);                  // write real count value

    GetSpellHistory()->WritePacket<Player>(data);

    SendDirectMessage(&data);
}

void Player::SendUnlearnSpells()
{
    WorldPacket data(SMSG_SEND_UNLEARN_SPELLS, 4 + 4 * m_spells.size());

    uint32 spellCount = 0;
    size_t countPos = data.wpos();
    data << uint32(spellCount);                             // spell count placeholder

    for (PlayerSpellMap::const_iterator itr = m_spells.begin(); itr != m_spells.end(); ++itr)
    {
        if (itr->second->state == PLAYERSPELL_REMOVED)
            continue;

        if (itr->second->active || itr->second->disabled)
            continue;

        auto skillLineAbilities = sSpellMgr->GetSkillLineAbilityMapBounds(itr->first);
        if (skillLineAbilities.first == skillLineAbilities.second)
            continue;

        bool hasSupercededSpellInfoInClient = false;
        for (auto boundsItr = skillLineAbilities.first; boundsItr != skillLineAbilities.second; ++boundsItr)
        {
            if (boundsItr->second->forward_spellid)
            {
                hasSupercededSpellInfoInClient = true;
                break;
            }
        }

        if (hasSupercededSpellInfoInClient)
            continue;

        uint32 nextRank = sSpellMgr->GetNextSpellInChain(itr->first);
        if (!nextRank || !HasSpell(nextRank))
            continue;

        data << uint32(itr->first);

        ++spellCount;
    }

    data.put<uint32>(countPos, spellCount);                  // write real count value

    SendDirectMessage(&data);
}

void Player::SendTameFailure(uint8 result)
{
    WorldPacket data(SMSG_PET_TAME_FAILURE, 1);
    data << uint8(result);
    SendDirectMessage(&data);
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
    WorldPacket data(SMSG_SEND_MAIL_RESULT, (4+4+4+(4+4)));
    data << (uint32) mailId;
    data << (uint32) mailAction;
    data << (uint32) mailError;
    if (mailError == MAIL_ERR_EQUIP_ERROR)
        data << (uint32) equipError;
    else if (mailAction == MAIL_ITEM_TAKEN)
    {
        data << (uint32) item_guid;                         // item guid low?
        data << (uint32) item_count;                        // item count?
    }
    SendDirectMessage(&data);
}

void Player::SendNewMail() const
{
    // deliver undelivered mail
    WorldPacket data(SMSG_RECEIVED_MAIL, 4);
    data << (uint32) 0;
    SendDirectMessage(&data);
}

void Player::UpdateNextMailTimeAndUnreads()
{
    // calculate next delivery time (min. from non-delivered mails
    // and recalculate unReadMail
    time_t cTime = GameTime::GetGameTime();
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
    if (deliver_time <= GameTime::GetGameTime())                          // ready now
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

bool Player::AddTalent(uint32 spellId, uint8 spec, bool learning)
{
    SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(spellId);
    if (!spellInfo)
    {
        // do character spell book cleanup (all characters)
        if (!IsInWorld() && !learning)                       // spell load case
        {
            TC_LOG_ERROR("spells", "Player::AddTalent: Spell (ID: %u) does not exist. Deleting for all characters in `character_spell` and `character_talent`.", spellId);

            DeleteSpellFromAllPlayers(spellId);
        }
        else
            TC_LOG_ERROR("spells", "Player::AddTalent: Spell (ID: %u) does not exist", spellId);

        return false;
    }

    if (!SpellMgr::IsSpellValid(spellInfo, this, false))
    {
        // do character spell book cleanup (all characters)
        if (!IsInWorld() && !learning)                       // spell load case
        {
            TC_LOG_ERROR("spells", "Player::AddTalent: Spell (ID: %u) is invalid. Deleting for all characters in `character_spell` and `character_talent`.", spellId);

            DeleteSpellFromAllPlayers(spellId);
        }
        else
            TC_LOG_ERROR("spells", "Player::AddTalent: Spell (ID: %u) is invalid", spellId);

        return false;
    }

    PlayerTalentMap::iterator itr = m_talents[spec]->find(spellId);
    if (itr != m_talents[spec]->end())
        itr->second->state = PLAYERSPELL_UNCHANGED;
    else if (TalentSpellPos const* talentPos = GetTalentSpellPos(spellId))
    {
        if (TalentEntry const* talentInfo = sTalentStore.LookupEntry(talentPos->talent_id))
        {
            for (uint8 rank = 0; rank < MAX_TALENT_RANK; ++rank)
            {
                // skip learning spell and no rank spell case
                uint32 rankSpellId = talentInfo->RankID[rank];
                if (!rankSpellId || rankSpellId == spellId)
                    continue;

                itr = m_talents[spec]->find(rankSpellId);
                if (itr != m_talents[spec]->end())
                    itr->second->state = PLAYERSPELL_REMOVED;
            }
        }

        PlayerTalent* newtalent = new PlayerTalent();

        newtalent->state = learning ? PLAYERSPELL_NEW : PLAYERSPELL_UNCHANGED;
        newtalent->spec = spec;

        (*m_talents[spec])[spellId] = newtalent;
        return true;
    }
    return false;
}

static bool IsUnlearnSpellsPacketNeededForSpell(uint32 spellId)
{
    SpellInfo const* spellInfo = sSpellMgr->AssertSpellInfo(spellId);
    if (spellInfo->IsRanked() && !spellInfo->IsStackableWithRanks())
    {
        auto skillLineAbilities = sSpellMgr->GetSkillLineAbilityMapBounds(spellId);
        if (skillLineAbilities.first != skillLineAbilities.second)
        {
            bool hasSupercededSpellInfoInClient = false;
            for (auto boundsItr = skillLineAbilities.first; boundsItr != skillLineAbilities.second; ++boundsItr)
            {
                if (boundsItr->second->forward_spellid)
                {
                    hasSupercededSpellInfoInClient = true;
                    break;
                }
            }

            return !hasSupercededSpellInfoInClient;
        }
    }

    return false;
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
                if (spellInfo->IsPassive() && HandlePassiveSpellLearn(spellInfo))
                    CastSpell(this, spellId, true);
            }
            else if (IsInWorld())
            {
                if (next_active_spell_id)
                {
                    SendSupercededSpell(spellId, next_active_spell_id);
                    if (IsUnlearnSpellsPacketNeededForSpell(spellId))
                        SendUnlearnSpells();
                }
                else
                {
                    WorldPacket data(SMSG_REMOVED_SPELL, 4);
                    data << uint32(spellId);
                    SendDirectMessage(&data);
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
        // talent: unlearn all other talent ranks (high and low)
        if (TalentSpellPos const* talentPos = GetTalentSpellPos(spellId))
        {
            if (TalentEntry const* talentInfo = sTalentStore.LookupEntry(talentPos->talent_id))
            {
                for (uint8 rank = 0; rank < MAX_TALENT_RANK; ++rank)
                {
                    // skip learning spell and no rank spell case
                    uint32 rankSpellId = talentInfo->RankID[rank];
                    if (!rankSpellId || rankSpellId == spellId)
                        continue;

                    RemoveSpell(rankSpellId, false, false);
                }
            }
        }
        // non talent spell: learn low ranks (recursive call)
        else if (uint32 prev_spell = sSpellMgr->GetPrevSpellInChain(spellId))
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

        bool needsUnlearnSpellsPacket = false;

        // replace spells in action bars and spellbook to bigger rank if only one spell rank must be accessible
        if (newspell->active && !newspell->disabled && !spellInfo->IsStackableWithRanks() && spellInfo->IsRanked())
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
                            {
                                SendSupercededSpell(itr2->first, spellId);
                                needsUnlearnSpellsPacket = needsUnlearnSpellsPacket || IsUnlearnSpellsPacketNeededForSpell(itr2->first);
                            }

                            // mark old spell as disable (SMSG_SUPERCEDED_SPELL replace it in client by new)
                            itr2->second->active = false;
                            if (itr2->second->state != PLAYERSPELL_NEW)
                                itr2->second->state = PLAYERSPELL_CHANGED;
                            superceded_old = true;          // new spell replace old in action bars and spell book.
                        }
                        else
                        {
                            if (IsInWorld())                 // not send spell (re-/over-)learn packets at loading
                            {
                                SendSupercededSpell(spellId, itr2->first);
                                needsUnlearnSpellsPacket = needsUnlearnSpellsPacket || IsUnlearnSpellsPacketNeededForSpell(spellId);
                            }

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

        if (needsUnlearnSpellsPacket)
            SendUnlearnSpells();

        // return false if spell disabled
        if (newspell->disabled)
            return false;
    }

    uint32 talentCost = GetTalentSpellCost(spellId);

    // cast talents with SPELL_EFFECT_LEARN_SPELL (other dependent spells will learned later as not auto-learned)
    // note: all spells with SPELL_EFFECT_LEARN_SPELL isn't passive
    if (!loading && talentCost > 0 && spellInfo->HasEffect(SPELL_EFFECT_LEARN_SPELL))
    {
        // ignore stance requirement for talent learn spell (stance set for spell only for client spell description show)
        CastSpell(this, spellId, true);
    }
    // also cast passive spells (including all talents without SPELL_EFFECT_LEARN_SPELL) with additional checks
    else if (spellInfo->IsPassive())
    {
        if (HandlePassiveSpellLearn(spellInfo))
            CastSpell(this, spellId, true);
    }
    else if (spellInfo->HasEffect(SPELL_EFFECT_SKILL_STEP))
    {
        CastSpell(this, spellId, true);
        return false;
    }

    // update used talent points count
    m_usedTalentCount += talentCost;

    // update free primary prof.points (if any, can be none in case GM .learn prof. learning)
    if (uint32 freeProfs = GetFreePrimaryProfessionPoints())
    {
        if (spellInfo->IsPrimaryProfessionFirstRank())
            SetFreePrimaryProfessions(freeProfs-1);
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

            if (sWorld->getBoolConfig(CONFIG_ALWAYS_MAXSKILL) && !IsProfessionOrRidingSkill(spellLearnSkill->skill))
                skill_value = skill_max_value;

            SetSkill(spellLearnSkill->skill, spellLearnSkill->step, skill_value, skill_max_value);
        }
    }
    else
    {
        // not ranked skills
        for (SkillLineAbilityMap::const_iterator _spell_idx = skill_bounds.first; _spell_idx != skill_bounds.second; ++_spell_idx)
        {
            SkillLineEntry const* pSkill = sSkillLineStore.LookupEntry(_spell_idx->second->skillId);
            if (!pSkill)
                continue;

            if (pSkill->id == fromSkill)
                continue;

            ///@todo: confirm if rogues start with lockpicking skill at level 1 but only receive the spell to use it at level 16
            // Also added for runeforging. It's already confirmed this happens upon learning for Death Knights, not from character creation.
            if ((_spell_idx->second->AutolearnType == SKILL_LINE_ABILITY_LEARNED_ON_SKILL_LEARN && !HasSkill(pSkill->id)) || ((pSkill->id == SKILL_LOCKPICKING || pSkill->id == SKILL_RUNEFORGING) && _spell_idx->second->max_value == 0))
                LearnDefaultSkill(pSkill->id, 0);

            if (pSkill->id == SKILL_MOUNTS && !Has310Flyer(false))
                for (uint8 i = 0; i < MAX_SPELL_EFFECTS; ++i)
                    if (spellInfo->Effects[i].ApplyAuraName == SPELL_AURA_MOD_INCREASE_MOUNTED_FLIGHT_SPEED &&
                        spellInfo->Effects[i].CalcValue() == 310)
                        SetHas310Flyer(true);
        }
    }

    // learn dependent spells
    SpellLearnSpellMapBounds spell_bounds = sSpellMgr->GetSpellLearnSpellMapBounds(spellId);

    for (SpellLearnSpellMap::const_iterator itr2 = spell_bounds.first; itr2 != spell_bounds.second; ++itr2)
    {
        if (!itr2->second.autoLearned)
        {
            if (!IsInWorld() || !itr2->second.active)       // at spells loading, no output, but allow save
                AddSpell(itr2->second.spell, itr2->second.active, true, true, false);
            else                                            // at normal learning
                LearnSpell(itr2->second.spell, true);
        }
    }

    if (!GetSession()->PlayerLoading())
    {
        // not ranked skills
        for (SkillLineAbilityMap::const_iterator _spell_idx = skill_bounds.first; _spell_idx != skill_bounds.second; ++_spell_idx)
        {
            UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_LEARN_SKILL_LINE, _spell_idx->second->skillId);
            UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_LEARN_SKILLLINE_SPELLS, _spell_idx->second->skillId);
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

bool Player::HandlePassiveSpellLearn(SpellInfo const* spellInfo)
{
    // note: form passives activated with shapeshift spells be implemented by HandleShapeshiftBoosts instead of spell_learn_spell
    // talent dependent passives activated at form apply have proper stance data
    ShapeshiftForm form = GetShapeshiftForm();
    bool need_cast = (!spellInfo->Stances || (form && (spellInfo->Stances & (UI64LIT(1) << (form - 1)))) ||
        (!form && spellInfo->HasAttribute(SPELL_ATTR2_NOT_NEED_SHAPESHIFT)));

    // Check EquippedItemClass
    // passive spells which apply aura and have an item requirement are to be added manually, instead of casted
    if (spellInfo->EquippedItemClass >= 0)
    {
        for (uint8 i = 0; i < MAX_SPELL_EFFECTS; ++i)
        {
            if (spellInfo->Effects[i].IsAura())
            {
                if (!HasAura(spellInfo->Id) && HasItemFitToSpellRequirements(spellInfo))
                    AddAura(spellInfo->Id, this);
                return false;
            }
        }
    }

    //Check CasterAuraStates
    return need_cast && (!spellInfo->CasterAuraState || HasAuraState(AuraStateType(spellInfo->CasterAuraState)));
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
        WorldPacket data(SMSG_LEARNED_SPELL, 6);
        data << uint32(spell_id);
        data << uint16(0);
        SendDirectMessage(&data);
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
        if (HasSpell(nextSpell) && !GetTalentSpellPos(nextSpell))
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

    bool giveTalentPoints = disabled || !itr->second->disabled;

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

    // free talent points
    uint32 talentCosts = GetTalentSpellCost(spell_id);
    if (talentCosts > 0 && giveTalentPoints)
    {
        if (talentCosts < m_usedTalentCount)
            m_usedTalentCount -= talentCosts;
        else
            m_usedTalentCount = 0;
    }

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
    else
    {
        // not ranked skills
        SkillLineAbilityMapBounds bounds = sSpellMgr->GetSkillLineAbilityMapBounds(spell_id);

        // most likely will never be used, haven't heard of cases where players unlearn a mount
        if (Has310Flyer(false) && spellInfo)
        {
            for (SkillLineAbilityMap::const_iterator _spell_idx = bounds.first; _spell_idx != bounds.second; ++_spell_idx)
            {
                SkillLineEntry const* pSkill = sSkillLineStore.LookupEntry(_spell_idx->second->skillId);
                if (!pSkill)
                    continue;

                if (_spell_idx->second->skillId == SKILL_MOUNTS)
                {
                    for (uint8 i = 0; i < MAX_SPELL_EFFECTS; ++i)
                    {
                        if (spellInfo->Effects[i].ApplyAuraName == SPELL_AURA_MOD_INCREASE_MOUNTED_FLIGHT_SPEED &&
                            spellInfo->Effects[i].CalcValue() == 310)
                        {
                            Has310Flyer(true, spell_id);    // with true as first argument its also used to set/remove the flag
                            break;
                        }
                    }
                }
            }
        }
    }

    // remove dependent spells
    SpellLearnSpellMapBounds spell_bounds = sSpellMgr->GetSpellLearnSpellMapBounds(spell_id);

    for (SpellLearnSpellMap::const_iterator itr2 = spell_bounds.first; itr2 != spell_bounds.second; ++itr2)
        RemoveSpell(itr2->second.spell, disabled);

    // activate lesser rank in spellbook/action bar, and cast it if need
    bool prev_activate = false;
    bool needsUnlearnSpellsPacket = false;

    if (uint32 prev_id = sSpellMgr->GetPrevSpellInChain(spell_id))
    {
        // if talent then lesser rank also talent and need learn
        if (talentCosts)
        {
            // I cannot see why mangos has these lines.
            //if (learn_low_rank)
            //    learnSpell(prev_id, false);
        }
        // if ranked non-stackable spell: need activate lesser rank and update dendence state
        /// No need to check for spellInfo != nullptr here because if cur_active is true, then that means that the spell was already in m_spells, and only valid spells can be pushed there.
        else if (cur_active && !spellInfo->IsStackableWithRanks() && spellInfo->IsRanked())
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
                if (!prev_itr->second->active && learn_low_rank)
                {
                    if (AddSpell(prev_id, true, false, prev_itr->second->dependent, prev_itr->second->disabled))
                    {
                        // downgrade spell ranks in spellbook and action bar
                        SendSupercededSpell(spell_id, prev_id);
                        needsUnlearnSpellsPacket = IsUnlearnSpellsPacketNeededForSpell(prev_id);
                        prev_activate = true;
                    }
                }
            }
        }
    }

    if (spell_id == 46917 && m_canTitanGrip)
    {
        RemoveAurasDueToSpell(m_titanGripPenaltySpellId);
        SetCanTitanGrip(false);
    }

    if (spell_id == 674 && m_canDualWield)
        SetCanDualWield(false);

    if (sWorld->getBoolConfig(CONFIG_OFFHAND_CHECK_AT_SPELL_UNLEARN))
        AutoUnequipOffhandIfNeed();

    if (needsUnlearnSpellsPacket)
        SendUnlearnSpells();

    // remove from spell book if not replaced by lesser rank
    if (!prev_activate)
    {
        WorldPacket data(SMSG_REMOVED_SPELL, 4);
        data << uint32(spell_id);
        SendDirectMessage(&data);
    }
}

bool Player::Has310Flyer(bool checkAllSpells, uint32 excludeSpellId)
{
    if (!checkAllSpells)
        return (m_ExtraFlags & PLAYER_EXTRA_HAS_310_FLYER) != 0;
    else
    {
        SetHas310Flyer(false);
        SpellInfo const* spellInfo;
        for (PlayerSpellMap::iterator itr = m_spells.begin(); itr != m_spells.end(); ++itr)
        {
            if (itr->first == excludeSpellId)
                continue;

            SkillLineAbilityMapBounds bounds = sSpellMgr->GetSkillLineAbilityMapBounds(itr->first);
            for (SkillLineAbilityMap::const_iterator _spell_idx = bounds.first; _spell_idx != bounds.second; ++_spell_idx)
            {
                if (_spell_idx->second->skillId != SKILL_MOUNTS)
                    break;  // We can break because mount spells belong only to one skillline (at least 310 flyers do)

                spellInfo = sSpellMgr->AssertSpellInfo(itr->first);
                for (uint8 i = 0; i < MAX_SPELL_EFFECTS; ++i)
                    if (spellInfo->Effects[i].ApplyAuraName == SPELL_AURA_MOD_INCREASE_MOUNTED_FLIGHT_SPEED &&
                        spellInfo->Effects[i].CalcValue() == 310)
                    {
                        SetHas310Flyer(true);
                        return true;
                    }
            }
        }
    }

    return false;
}

void Player::RemoveArenaSpellCooldowns(bool removeActivePetCooldowns)
{
    // remove cooldowns on spells that have < 10 min CD
    GetSpellHistory()->ResetCooldowns([](SpellHistory::CooldownStorageType::iterator itr) -> bool
    {
        SpellInfo const* spellInfo = sSpellMgr->AssertSpellInfo(itr->first);
        return spellInfo->RecoveryTime < 10 * MINUTE * IN_MILLISECONDS && spellInfo->CategoryRecoveryTime < 10 * MINUTE * IN_MILLISECONDS;
    }, true);

    // pet cooldowns
    if (removeActivePetCooldowns)
        if (Pet* pet = GetPet())
            pet->GetSpellHistory()->ResetAllCooldowns();
}

uint32 Player::ResetTalentsCost() const
{
    // The first time reset costs 1 gold
    if (m_resetTalentsCost < 1*GOLD)
        return 1*GOLD;
    // then 5 gold
    else if (m_resetTalentsCost < 5*GOLD)
        return 5*GOLD;
    // After that it increases in increments of 5 gold
    else if (m_resetTalentsCost < 10*GOLD)
        return 10*GOLD;
    else
    {
        uint64 months = (GameTime::GetGameTime() - m_resetTalentsTime)/MONTH;
        if (months > 0)
        {
            // This cost will be reduced by a rate of 5 gold per month
            int32 new_cost = int32(m_resetTalentsCost - 5*GOLD*months);
            // to a minimum of 10 gold.
            return (new_cost < 10*GOLD ? 10*GOLD : new_cost);
        }
        else
        {
            // After that it increases in increments of 5 gold
            int32 new_cost = m_resetTalentsCost + 5*GOLD;
            // until it hits a cap of 50 gold.
            if (new_cost > 50*GOLD)
                new_cost = 50*GOLD;
            return new_cost;
        }
    }
}

bool Player::ResetTalents(bool no_cost)
{
    sScriptMgr->OnPlayerTalentsReset(this, no_cost);

    // not need after this call
    if (HasAtLoginFlag(AT_LOGIN_RESET_TALENTS))
        RemoveAtLoginFlag(AT_LOGIN_RESET_TALENTS, true);

    uint32 talentPointsForLevel = CalculateTalentsPoints();

    if (m_usedTalentCount == 0)
    {
        SetFreeTalentPoints(talentPointsForLevel);
        return false;
    }

    uint32 cost = 0;

    if (!no_cost && !sWorld->getBoolConfig(CONFIG_NO_RESET_TALENT_COST))
    {
        cost = ResetTalentsCost();

        if (!HasEnoughMoney(cost))
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

        TalentTabEntry const* talentTabInfo = sTalentTabStore.LookupEntry(talentInfo->TalentTab);

        if (!talentTabInfo)
            continue;

        // unlearn only talents for character class
        // some spell learned by one class as normal spells or know at creation but another class learn it as talent,
        // to prevent unexpected lost normal learned spell skip another class talents
        if ((GetClassMask() & talentTabInfo->ClassMask) == 0)
            continue;

        for (int8 rank = MAX_TALENT_RANK-1; rank >= 0; --rank)
        {
            // skip non-existing talent ranks
            if (talentInfo->RankID[rank] == 0)
                continue;
            SpellInfo const* _spellEntry = sSpellMgr->GetSpellInfo(talentInfo->RankID[rank]);
            if (!_spellEntry)
                continue;
            RemoveSpell(talentInfo->RankID[rank], true);
            // search for spells that the talent teaches and unlearn them
            for (uint8 i = 0; i < MAX_SPELL_EFFECTS; ++i)
                if (_spellEntry->Effects[i].TriggerSpell > 0 && _spellEntry->Effects[i].Effect == SPELL_EFFECT_LEARN_SPELL)
                    RemoveSpell(_spellEntry->Effects[i].TriggerSpell, true);
            // if this talent rank can be found in the PlayerTalentMap, mark the talent as removed so it gets deleted
            PlayerTalentMap::iterator plrTalent = m_talents[m_activeSpec]->find(talentInfo->RankID[rank]);
            if (plrTalent != m_talents[m_activeSpec]->end())
                plrTalent->second->state = PLAYERSPELL_REMOVED;
        }
    }

    SQLTransaction trans = CharacterDatabase.BeginTransaction();
    _SaveTalents(trans);
    _SaveSpells(trans);
    CharacterDatabase.CommitTransaction(trans);

    SetFreeTalentPoints(talentPointsForLevel);

    if (!no_cost)
    {
        ModifyMoney(-(int32)cost);
        UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_GOLD_SPENT_FOR_TALENTS, cost);
        UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_NUMBER_OF_TALENT_RESETS, 1);

        m_resetTalentsCost = cost;
        m_resetTalentsTime = GameTime::GetGameTime();
    }

    /* when prev line will dropped use next line
    if (Pet* pet = GetPet())
    {
        if (pet->getPetType() == HUNTER_PET && !pet->GetCreatureTemplate()->IsTameable(CanTameExoticPets()))
            RemovePet(nullptr, PET_SAVE_NOT_IN_SLOT, true);
    }
    */

    return true;
}

void Player::SetFreeTalentPoints(uint32 points)
{
    sScriptMgr->OnPlayerFreeTalentPointsChanged(this, points);
    SetUInt32Value(PLAYER_CHARACTER_POINTS1, points);
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
        for (uint8 i = KEYRING_SLOT_START; i < CURRENCYTOKEN_SLOT_END; ++i)
        {
            if (m_items[i] == nullptr)
                continue;

            m_items[i]->BuildCreateUpdateBlockForPlayer(data, target);
        }
    }

    Unit::BuildCreateUpdateBlockForPlayer(data, target);
}

void Player::DestroyForPlayer(Player* target, bool onDeath) const
{
    Unit::DestroyForPlayer(target, onDeath);

    for (uint8 i = 0; i < EQUIPMENT_SLOT_END; ++i)
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
        for (uint8 i = KEYRING_SLOT_START; i < CURRENCYTOKEN_SLOT_END; ++i)
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

bool Player::HasTalent(uint32 spell, uint8 spec) const
{
    PlayerTalentMap::const_iterator itr = m_talents[spec]->find(spell);
    return (itr != m_talents[spec]->end() && itr->second->state != PLAYERSPELL_REMOVED);
}

bool Player::HasActiveSpell(uint32 spell) const
{
    PlayerSpellMap::const_iterator itr = m_spells.find(spell);
    return (itr != m_spells.end() && itr->second->state != PLAYERSPELL_REMOVED &&
        itr->second->active && !itr->second->disabled);
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
    uint32 charDelete_method = sWorld->getIntConfig(CONFIG_CHARDELETE_METHOD);
    CharacterCacheEntry const* characterInfo = sCharacterCache->GetCharacterCacheByGuid(playerguid);
    std::string name;
    if (characterInfo)
        name = characterInfo->Name;

    if (deleteFinally)
        charDelete_method = CHAR_DELETE_REMOVE;
    else if (characterInfo)    // To avoid a query, we select loaded data. If it doesn't exist, return.
    {
        // Define the required variables
        uint32 charDelete_minLvl = sWorld->getIntConfig(characterInfo->Class != CLASS_DEATH_KNIGHT ? CONFIG_CHARDELETE_MIN_LEVEL : CONFIG_CHARDELETE_DEATH_KNIGHT_MIN_LEVEL);

        // if we want to finalize the character removal or the character does not meet the level requirement of either heroic or non-heroic settings,
        // we set it to mode CHAR_DELETE_REMOVE
        if (characterInfo->Level < charDelete_minLvl)
            charDelete_method = CHAR_DELETE_REMOVE;
    }

    SQLTransaction trans = CharacterDatabase.BeginTransaction();
    if (ObjectGuid::LowType guildId = sCharacterCache->GetCharacterGuildIdByGuid(playerguid))
        if (Guild* guild = sGuildMgr->GetGuildById(guildId))
            guild->DeleteMember(trans, playerguid, false, false, true);

    // close player ticket if any
    GmTicket* ticket = sTicketMgr->GetTicketByPlayer(playerguid);
    if (ticket)
        sTicketMgr->CloseTicket(ticket->GetId(), playerguid);

    // remove from arena teams
    LeaveAllArenaTeams(playerguid);

    // the player was uninvited already on logout so just remove from group
    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_GROUP_MEMBER);
    stmt->setUInt32(0, guid);
    PreparedQueryResult resultGroup = CharacterDatabase.Query(stmt);

    if (resultGroup)
        if (Group* group = sGroupMgr->GetGroupByDbStoreId((*resultGroup)[0].GetUInt32()))
            RemoveFromGroup(group, playerguid);

    // Remove signs from petitions (also remove petitions if owner);
    RemovePetitionsAndSigns(playerguid, CHARTER_TYPE_ANY);

    switch (charDelete_method)
    {
        // Completely remove from the database
        case CHAR_DELETE_REMOVE:
        {
            stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHAR_COD_ITEM_MAIL);
            stmt->setUInt32(0, guid);
            PreparedQueryResult resultMail = CharacterDatabase.Query(stmt);

            if (resultMail)
            {
                do
                {
                    Field* mailFields = resultMail->Fetch();

                    uint32 mail_id       = mailFields[0].GetUInt32();
                    uint8 mailType       = mailFields[1].GetUInt8();
                    uint16 mailTemplateId= mailFields[2].GetUInt16();
                    uint32 sender        = mailFields[3].GetUInt32();
                    std::string subject  = mailFields[4].GetString();
                    std::string body     = mailFields[5].GetString();
                    uint32 money         = mailFields[6].GetUInt32();
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
                                ObjectGuid::LowType item_guidlow = itemFields[11].GetUInt32();
                                uint32 item_template = itemFields[12].GetUInt32();

                                ItemTemplate const* itemProto = sObjectMgr->GetItemTemplate(item_template);
                                if (!itemProto)
                                {
                                    stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_ITEM_INSTANCE);
                                    stmt->setUInt32(0, item_guidlow);
                                    trans->Append(stmt);
                                    continue;
                                }

                                Item* pItem = NewItemOrBag(itemProto);
                                if (!pItem->LoadFromDB(item_guidlow, playerguid, itemFields, item_template))
                                {
                                    pItem->FSetState(ITEM_REMOVED);
                                    pItem->SaveToDB(trans);              // it also deletes item object!
                                    continue;
                                }

                                draft.AddItem(pItem);
                            }
                            while (resultItems->NextRow());
                        }
                    }

                    stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_MAIL_ITEM_BY_ID);
                    stmt->setUInt32(0, mail_id);
                    trans->Append(stmt);

                    uint32 pl_account = sCharacterCache->GetCharacterAccountIdByGuid(playerguid);

                    draft.AddMoney(money).SendReturnToSender(pl_account, guid, sender, trans);
                }
                while (resultMail->NextRow());
            }

            // Unsummon and delete for pets in world is not required: player deleted from CLI or character list with not loaded pet.
            // NOW we can finally clear other DB data related to character
            stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHAR_PETS);
            stmt->setUInt32(0, guid);
            PreparedQueryResult resultPets = CharacterDatabase.Query(stmt);

            if (resultPets)
            {
                do
                {
                    ObjectGuid::LowType petguidlow = (*resultPets)[0].GetUInt32();
                    Pet::DeleteFromDB(petguidlow);
                } while (resultPets->NextRow());
            }

            // Delete char from social list of online chars
            stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHAR_SOCIAL);
            stmt->setUInt32(0, guid);

            if (PreparedQueryResult resultFriends = CharacterDatabase.Query(stmt))
            {
                do
                {
                    if (Player* playerFriend = ObjectAccessor::FindPlayer(ObjectGuid(HighGuid::Player, 0, (*resultFriends)[0].GetUInt32())))
                    {
                        playerFriend->GetSocial()->RemoveFromSocialList(playerguid, SOCIAL_FLAG_ALL);
                        sSocialMgr->SendFriendStatus(playerFriend, FRIEND_REMOVED, playerguid);
                    }
                } while (resultFriends->NextRow());
            }

            stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHARACTER);
            stmt->setUInt32(0, guid);
            trans->Append(stmt);

            stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_PLAYER_ACCOUNT_DATA);
            stmt->setUInt32(0, guid);
            trans->Append(stmt);

            stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHAR_DECLINED_NAME);
            stmt->setUInt32(0, guid);
            trans->Append(stmt);

            stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHAR_ACTION);
            stmt->setUInt32(0, guid);
            trans->Append(stmt);

            stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHARACTER_ARENA_STATS);
            stmt->setUInt32(0, guid);
            trans->Append(stmt);

            stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHAR_AURA);
            stmt->setUInt32(0, guid);
            trans->Append(stmt);

            stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_PLAYER_BGDATA);
            stmt->setUInt32(0, guid);
            trans->Append(stmt);

            stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_BATTLEGROUND_RANDOM);
            stmt->setUInt32(0, guid);
            trans->Append(stmt);

            stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHAR_GIFT);
            stmt->setUInt32(0, guid);
            trans->Append(stmt);

            stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_PLAYER_HOMEBIND);
            stmt->setUInt32(0, guid);
            trans->Append(stmt);

            stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHAR_INSTANCE);
            stmt->setUInt32(0, guid);
            trans->Append(stmt);

            stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHAR_INVENTORY);
            stmt->setUInt32(0, guid);
            trans->Append(stmt);

            stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHAR_QUESTSTATUS);
            stmt->setUInt32(0, guid);
            trans->Append(stmt);

            stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHAR_QUESTSTATUS_REWARDED);
            stmt->setUInt32(0, guid);
            trans->Append(stmt);

            stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHAR_REPUTATION);
            stmt->setUInt32(0, guid);
            trans->Append(stmt);

            stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHAR_SPELL);
            stmt->setUInt32(0, guid);
            trans->Append(stmt);

            stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHAR_SPELL_COOLDOWNS);
            stmt->setUInt32(0, guid);
            trans->Append(stmt);

            if (sWorld->getBoolConfig(CONFIG_DELETE_CHARACTER_TICKET_TRACE))
            {
                stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_PLAYER_GM_TICKETS_ON_CHAR_DELETION);
                stmt->setUInt32(0, guid);
                trans->Append(stmt);
            }
            else
            {
                stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_PLAYER_GM_TICKETS);
                stmt->setUInt32(0, guid);
                trans->Append(stmt);
            }

            stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_ITEM_INSTANCE_BY_OWNER);
            stmt->setUInt32(0, guid);
            trans->Append(stmt);

            stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHAR_SOCIAL_BY_FRIEND);
            stmt->setUInt32(0, guid);
            trans->Append(stmt);

            stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHAR_SOCIAL_BY_GUID);
            stmt->setUInt32(0, guid);
            trans->Append(stmt);

            stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_MAIL);
            stmt->setUInt32(0, guid);
            trans->Append(stmt);

            stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_MAIL_ITEMS);
            stmt->setUInt32(0, guid);
            trans->Append(stmt);

            stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHAR_PET_BY_OWNER);
            stmt->setUInt32(0, guid);
            trans->Append(stmt);

            stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHAR_PET_DECLINEDNAME_BY_OWNER);
            stmt->setUInt32(0, guid);
            trans->Append(stmt);

            stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHAR_ACHIEVEMENTS);
            stmt->setUInt32(0, guid);
            trans->Append(stmt);

            stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHAR_ACHIEVEMENT_PROGRESS);
            stmt->setUInt32(0, guid);
            trans->Append(stmt);

            stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHAR_EQUIPMENTSETS);
            stmt->setUInt32(0, guid);
            trans->Append(stmt);

            stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_GUILD_EVENTLOG_BY_PLAYER);
            stmt->setUInt32(0, guid);
            stmt->setUInt32(1, guid);
            trans->Append(stmt);

            stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_GUILD_BANK_EVENTLOG_BY_PLAYER);
            stmt->setUInt32(0, guid);
            trans->Append(stmt);

            stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHAR_GLYPHS);
            stmt->setUInt32(0, guid);
            trans->Append(stmt);

            stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHARACTER_QUESTSTATUS_DAILY);
            stmt->setUInt32(0, guid);
            trans->Append(stmt);

            stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHARACTER_QUESTSTATUS_WEEKLY);
            stmt->setUInt32(0, guid);
            trans->Append(stmt);

            stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHARACTER_QUESTSTATUS_MONTHLY);
            stmt->setUInt32(0, guid);
            trans->Append(stmt);

            stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHARACTER_QUESTSTATUS_SEASONAL);
            stmt->setUInt32(0, guid);
            trans->Append(stmt);

            stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHAR_TALENT);
            stmt->setUInt32(0, guid);
            trans->Append(stmt);

            stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHAR_SKILLS);
            stmt->setUInt32(0, guid);
            trans->Append(stmt);

            stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHAR_STATS);
            stmt->setUInt32(0, guid);
            trans->Append(stmt);

            stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHAR_FISHINGSTEPS);
            stmt->setUInt32(0, guid);
            trans->Append(stmt);

            Corpse::DeleteFromDB(playerguid, trans);
            break;
        }
        // The character gets unlinked from the account, the name gets freed up and appears as deleted ingame
        case CHAR_DELETE_UNLINK:
        {
            stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_DELETE_INFO);
            stmt->setUInt32(0, guid);
            trans->Append(stmt);
            break;
        }
        default:
            TC_LOG_ERROR("entities.player.cheat", "Player::DeleteFromDB: Tried to delete player (%s) with unsupported delete method (%u).",
                playerguid.ToString().c_str(), charDelete_method);

            if (trans->GetSize() > 0)
                CharacterDatabase.CommitTransaction(trans);
            return;
    }

    CharacterDatabase.CommitTransaction(trans);

    if (updateRealmChars)
        sWorld->UpdateRealmCharCount(accountId);

    sCharacterCache->DeleteCharacterCacheEntry(playerguid, name);
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
    stmt->setUInt32(0, uint32(GameTime::GetGameTime() - time_t(keepDays * DAY)));
    PreparedQueryResult result = CharacterDatabase.Query(stmt);

    if (result)
    {
         TC_LOG_DEBUG("entities.player", "Player::DeleteOldCharacters: Found " UI64FMTD " character(s) to delete", result->GetRowCount());
         do
         {
            Field* fields = result->Fetch();
            Player::DeleteFromDB(ObjectGuid(HighGuid::Player, fields[0].GetUInt32()), fields[1].GetUInt32(), true, true);
         }
         while (result->NextRow());
    }
}

void Player::SetMovement(PlayerMovementType pType)
{
    WorldPacket data;
    switch (pType)
    {
        case MOVE_ROOT:       data.Initialize(SMSG_FORCE_MOVE_ROOT,   GetPackGUID().size()+4); break;
        case MOVE_UNROOT:     data.Initialize(SMSG_FORCE_MOVE_UNROOT, GetPackGUID().size()+4); break;
        case MOVE_WATER_WALK: data.Initialize(SMSG_MOVE_WATER_WALK,   GetPackGUID().size()+4); break;
        case MOVE_LAND_WALK:  data.Initialize(SMSG_MOVE_LAND_WALK,    GetPackGUID().size()+4); break;
        default:
            TC_LOG_ERROR("entities.player", "Player::SetMovement: Unsupported move type (%d), data not sent to client.", pType);
            return;
    }
    data << GetPackGUID();
    data << uint32(0);
    SendDirectMessage(&data);
}

/* Preconditions:
  - a resurrectable corpse must not be loaded for the player (only bones)
  - the player must be in world
*/
void Player::BuildPlayerRepop()
{
    WorldPacket data(SMSG_PRE_RESURRECT, GetPackGUID().size());
    data << GetPackGUID();
    SendDirectMessage(&data);

    if (GetRace() == RACE_NIGHTELF)
        CastSpell(this, 20584, true);
    CastSpell(this, 8326, true);

    // there must be SMSG.FORCE_RUN_SPEED_CHANGE, SMSG.FORCE_SWIM_SPEED_CHANGE, SMSG.MOVE_WATER_WALK
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
    setDeathState(DEAD);
    SetHealth(1);

    SetMovement(MOVE_WATER_WALK);
    if (!GetSession()->isLogingOut())
        SetMovement(MOVE_UNROOT);

    // BG - remove insignia related
    RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_SKINNABLE);

    int32 corpseReclaimDelay = CalculateCorpseReclaimDelay();

    if (corpseReclaimDelay >= 0)
        SendCorpseReclaimDelay(corpseReclaimDelay);

    // to prevent cheating
    corpse->ResetGhostTime();

    StopMirrorTimers();                                     //disable timers(bars)

    // set and clear other
    SetByteValue(UNIT_FIELD_BYTES_1, UNIT_BYTES_1_OFFSET_ANIM_TIER, UNIT_BYTE1_FLAG_ALWAYS_STAND);

    // OnPlayerRepop hook
    sScriptMgr->OnPlayerRepop(this);
}

void Player::ResurrectPlayer(float restore_percent, bool applySickness)
{
    WorldPacket data(SMSG_DEATH_RELEASE_LOC, 4*4);          // remove spirit healer position
    data << uint32(-1);
    data << float(0);
    data << float(0);
    data << float(0);
    SendDirectMessage(&data);

    // speed change, land walk

    // remove death flag + set aura
    SetByteValue(UNIT_FIELD_BYTES_1, UNIT_BYTES_1_OFFSET_ANIM_TIER, 0);
    RemoveFlag(PLAYER_FLAGS, PLAYER_FLAGS_IS_OUT_OF_BOUNDS);

    // This must be called always even on Players with race != RACE_NIGHTELF in case of faction change
    RemoveAurasDueToSpell(20584);                           // RACE_NIGHTELF speed bonuses
    RemoveAurasDueToSpell(8326);                            // SPELL_AURA_GHOST

    if (GetSession()->IsARecruiter() || (GetSession()->GetRecruiterId() != 0))
        SetFlag(UNIT_DYNAMIC_FLAGS, UNIT_DYNFLAG_REFER_A_FRIEND);

    setDeathState(ALIVE);

    SetMovement(MOVE_LAND_WALK);
    SetMovement(MOVE_UNROOT);

    m_deathTimer = 0;

    // set health/powers (0- will be set in caller)
    if (restore_percent > 0.0f)
    {
        SetHealth(uint32(GetMaxHealth()*restore_percent));
        SetPower(POWER_MANA, uint32(GetMaxPower(POWER_MANA)*restore_percent));
        SetPower(POWER_RAGE, 0);
        SetPower(POWER_ENERGY, uint32(GetMaxPower(POWER_ENERGY)*restore_percent));
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

    // recast lost by death auras of any items held in the inventory
    CastAllObtainSpells();

    if (!applySickness)
        return;

    //Characters from level 1-10 are not affected by resurrection sickness.
    //Characters from level 11-19 will suffer from one minute of sickness
    //for each level they are above 10.
    //Characters level 20 and up suffer from ten minutes of sickness.
    int32 startLevel = sWorld->getIntConfig(CONFIG_DEATH_SICKNESS_LEVEL);

    if (int32(GetLevel()) >= startLevel)
    {
        // set resurrection sickness
        CastSpell(this, 15007, true);

        // not full duration
        if (int32(GetLevel()) < startLevel+9)
        {
            int32 delta = (int32(GetLevel()) - startLevel + 1)*MINUTE;

            if (Aura* aur = GetAura(15007, GetGUID()))
            {
                aur->SetDuration(delta*IN_MILLISECONDS);
            }
        }
    }
}

void Player::RemoveGhoul()
{
    RemoveAura(SPELL_DK_RAISE_ALLY);
}

void Player::KillPlayer()
{
    if (IsFlying() && !GetTransport())
        GetMotionMaster()->MoveFall();

    SetMovement(MOVE_ROOT);

    StopMirrorTimers();                                     //disable timers(bars)

    setDeathState(CORPSE);
    //SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_IN_PVP);

    SetUInt32Value(UNIT_DYNAMIC_FLAGS, UNIT_DYNFLAG_NONE);
    ApplyModFlag(PLAYER_FIELD_BYTES, PLAYER_FIELD_BYTE_RELEASE_TIMER, !sMapStore.LookupEntry(GetMapId())->Instanceable() && !HasAuraType(SPELL_AURA_PREVENT_RESURRECTION));

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
    // prevent the existence of 2 corpses for one player
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

    _cfb1 = ((0x00) | (GetRace() << 8) | (GetNativeGender() << 16) | (GetSkinId() << 24));
    _cfb2 = (GetFaceId() | (GetHairStyleId() << 8) | (GetHairColorId() << 16) | (GetFacialStyle() << 24));

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

    corpse->SetUInt32Value(CORPSE_FIELD_GUILD, GetGuildId());

    uint32 iDisplayID;
    uint32 iIventoryType;
    uint32 _cfi;
    for (uint8 i = 0; i < EQUIPMENT_SLOT_END; i++)
    {
        if (m_items[i])
        {
            iDisplayID = m_items[i]->GetTemplate()->DisplayInfoID;
            iIventoryType = m_items[i]->GetTemplate()->InventoryType;

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

        // keys not have durability
        //for (int i = KEYRING_SLOT_START; i < KEYRING_SLOT_END; i++)

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

        // keys not have durability
        //for (int i = KEYRING_SLOT_START; i < KEYRING_SLOT_END; i++)

        for (uint8 i = INVENTORY_SLOT_BAG_START; i < INVENTORY_SLOT_BAG_END; i++)
            if (Bag* pBag = static_cast<Bag*>(GetItemByPos(INVENTORY_SLOT_BAG_0, i)))
                for (uint32 j = 0; j < pBag->GetBagSize(); j++)
                    if (Item* pItem = GetItemByPos(i, j))
                        DurabilityPointsLoss(pItem, points);
    }
}

void Player::DurabilityPointsLoss(Item* item, int32 points)
{
    if (HasAuraType(SPELL_AURA_PREVENT_DURABILITY_LOSS))
        return;

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

            DurabilityCostsEntry const* dcost = sDurabilityCostsStore.LookupEntry(ditemProto->ItemLevel);
            if (!dcost)
            {
                TC_LOG_ERROR("entities.player.items", "Player::DurabilityRepair: Player '%s' (%s) tried to repair an item (ItemID: %u) with invalid item level %u",
                    GetName().c_str(), GetGUID().ToString().c_str(), ditemProto->ItemId, ditemProto->ItemLevel);
                return TotalCost;
            }

            uint32 dQualitymodEntryId = (ditemProto->Quality+1)*2;
            DurabilityQualityEntry const* dQualitymodEntry = sDurabilityQualityStore.LookupEntry(dQualitymodEntryId);
            if (!dQualitymodEntry)
            {
                TC_LOG_ERROR("entities.player.items", "Player::DurabilityRepair: Player '%s' (%s) tried to repair an item (ItemID: %u) with invalid QualitymodEntry %u",
                    GetName().c_str(), GetGUID().ToString().c_str(), ditemProto->ItemId, dQualitymodEntryId);
                return TotalCost;
            }

            uint32 dmultiplier = dcost->multiplier[ItemSubClassToDurabilityMultiplierId(ditemProto->Class, ditemProto->SubClass)];
            uint32 costs = uint32(LostDurability*dmultiplier*double(dQualitymodEntry->quality_mod));

            costs = uint32(costs * discountMod * sWorld->getRate(RATE_REPAIRCOST));

            if (costs == 0)                                   //fix for ITEM_QUALITY_ARTIFACT
                costs = 1;

            if (guildBank)
            {
                if (GetGuildId() == 0)
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
            else if (!HasEnoughMoney(costs))
            {
                TC_LOG_DEBUG("entities.player.items", "Player::DurabilityRepair: Player '%s' (%s) has not enough money to repair item",
                    GetName().c_str(), GetGUID().ToString().c_str());
                return TotalCost;
            }
            else
                ModifyMoney(-int32(costs));
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

    bool shouldResurrect = false;
    // Such zones are considered unreachable as a ghost and the player must be automatically revived
    if ((!IsAlive() && zone && zone->flags & AREA_FLAG_NEED_FLY) || GetTransport() || GetPositionZ() < GetMap()->GetMinHeight(GetPositionX(), GetPositionY()))
    {
        shouldResurrect = true;
        SpawnCorpseBones();
    }

    WorldSafeLocsEntry const* ClosestGrave;

    // Special handle for battleground maps
    if (Battleground* bg = GetBattleground())
        ClosestGrave = bg->GetClosestGraveyard(this);
    else
    {
        if (Battlefield* bf = sBattlefieldMgr->GetBattlefieldToZoneId(GetZoneId()))
            ClosestGrave = bf->GetClosestGraveyard(this);
        else
            ClosestGrave = sObjectMgr->GetClosestGraveyard(GetPositionX(), GetPositionY(), GetPositionZ(), GetMapId(), GetTeam());
    }

    // stop countdown until repop
    m_deathTimer = 0;

    // if no grave found, stay at the current location
    // and don't show spirit healer location
    if (ClosestGrave)
    {
        TeleportTo(ClosestGrave->map_id, ClosestGrave->x, ClosestGrave->y, ClosestGrave->z, GetOrientation(), shouldResurrect ? TELE_REVIVE_AT_TELEPORT : 0);
        if (isDead())                                        // not send if alive, because it used in TeleportTo()
        {
            WorldPacket data(SMSG_DEATH_RELEASE_LOC, 4*4);  // show spirit healer position on minimap
            data << ClosestGrave->map_id;
            data << TaggedPosition<Position::XYZ>(ClosestGrave->x, ClosestGrave->y, ClosestGrave->z);
            SendDirectMessage(&data);
        }
    }
    else if (GetPositionZ() < GetMap()->GetMinHeight(GetPositionX(), GetPositionY()))
        TeleportTo(m_homebindMapId, m_homebindX, m_homebindY, m_homebindZ, GetOrientation());

    RemoveFlag(PLAYER_FLAGS, PLAYER_FLAGS_IS_OUT_OF_BOUNDS);
}

bool Player::CanJoinConstantChannelInZone(ChatChannelsEntry const* channel, AreaTableEntry const* zone) const
{
    if (channel->flags & CHANNEL_DBC_FLAG_ZONE_DEP && zone->flags & AREA_FLAG_ARENA_INSTANCE)
        return false;

    if ((channel->flags & CHANNEL_DBC_FLAG_CITY_ONLY) && (!(zone->flags & AREA_FLAG_SLAVE_CAPITAL)))
        return false;

    if ((channel->flags & CHANNEL_DBC_FLAG_GUILD_REQ) && GetGuildId())
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
        ch->LeaveChannel(this, false);                     // not send to client, not remove from player's channel list

        // delete channel if empty
        if (ChannelMgr* cMgr = ChannelMgr::forTeam(GetTeam()))
            if (ch->IsConstant())
                cMgr->LeftChannel(ch->GetChannelId(), ch->GetZoneEntry());
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

    ChannelMgr* cMgr = ChannelMgr::forTeam(GetTeam());
    if (!cMgr)
        return;

    for (uint32 i = 0; i < sChatChannelsStore.GetNumRows(); ++i)
    {
        ChatChannelsEntry const* channelEntry = sChatChannelsStore.LookupEntry(i);
        if (!channelEntry)
            continue;

        Channel* usedChannel = nullptr;
        for (Channel* channel : m_channels)
        {
            if (channel->GetChannelId() == i)
            {
                usedChannel = channel;
                break;
            }
        }

        Channel* removeChannel = nullptr;
        Channel* joinChannel = nullptr;
        bool sendRemove = true;

        if (CanJoinConstantChannelInZone(channelEntry, current_zone))
        {
            if (!(channelEntry->flags & CHANNEL_DBC_FLAG_GLOBAL))
            {
                if (channelEntry->flags & CHANNEL_DBC_FLAG_CITY_ONLY && usedChannel)
                    continue;                            // Already on the channel, as city channel names are not changing

                joinChannel = cMgr->GetSystemChannel(channelEntry->ChannelID, current_zone);
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
                joinChannel = cMgr->GetSystemChannel(channelEntry->ChannelID);
        }
        else
            removeChannel = usedChannel;

        if (joinChannel)
            joinChannel->JoinChannel(this);          // Changed Channel: ... or Joined Channel: ...

        if (removeChannel)
        {
            removeChannel->LeaveChannel(this, sendRemove);                                      // Leave old channel

            LeftChannel(removeChannel);                                                         // Remove from player's channel list
            cMgr->LeftChannel(removeChannel->GetChannelId(), removeChannel->GetZoneEntry());    // Delete if empty
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

void Player::UpdateDefense()
{
    if (UpdateSkill(SKILL_DEFENSE, sWorld->getIntConfig(CONFIG_SKILL_GAIN_DEFENSE)))
        UpdateDefenseBonusesMod(); // update dependent from defense skill part
}

void Player::HandleBaseModFlatValue(BaseModGroup modGroup, float amount, bool apply)
{
    if (modGroup >= BASEMOD_END)
    {
        TC_LOG_ERROR("spells", "Player::HandleBaseModValue: Invalid BaseModGroup/BaseModType (%u/%u) for player '%s' (%s)",
            modGroup, FLAT_MOD, GetName().c_str(), GetGUID().ToString().c_str());
        return;
    }

    m_auraBaseFlatMod[modGroup] += apply ? amount : -amount;
    UpdateBaseModGroup(modGroup);
}

void Player::ApplyBaseModPctValue(BaseModGroup modGroup, float pct)
{
    if (modGroup >= BASEMOD_END)
    {
        TC_LOG_ERROR("spells", "Player::HandleBaseModValue: Invalid BaseModGroup/BaseModType (%u/%u) for player '%s' (%s)",
            modGroup, FLAT_MOD, GetName().c_str(), GetGUID().ToString().c_str());
        return;
    }

    AddPct(m_auraBasePctMod[modGroup], pct);
    UpdateBaseModGroup(modGroup);
}

void Player::SetBaseModFlatValue(BaseModGroup modGroup, float val)
{
    if (m_auraBaseFlatMod[modGroup] == val)
        return;

    m_auraBaseFlatMod[modGroup] = val;
    UpdateBaseModGroup(modGroup);
}

void Player::SetBaseModPctValue(BaseModGroup modGroup, float val)
{
    if (m_auraBasePctMod[modGroup] == val)
        return;

    m_auraBasePctMod[modGroup] = val;
    UpdateBaseModGroup(modGroup);
}

void Player::UpdateDamageDoneMods(WeaponAttackType attackType, int32 skipEnchantSlot /*= -1*/)
{
    Unit::UpdateDamageDoneMods(attackType, skipEnchantSlot);

    UnitMods unitMod;
    switch (attackType)
    {
        case BASE_ATTACK:
            unitMod = UNIT_MOD_DAMAGE_MAINHAND;
            break;
        case OFF_ATTACK:
            unitMod = UNIT_MOD_DAMAGE_OFFHAND;
            break;
        case RANGED_ATTACK:
            unitMod = UNIT_MOD_DAMAGE_RANGED;
            break;
        default:
            ABORT();
            break;
    }

    float amount = 0.0f;
    Item* item = GetWeaponForAttack(attackType, true);
    if (!item)
        return;

    for (uint8 slot = 0; slot < MAX_ENCHANTMENT_SLOT; ++slot)
    {
        if (skipEnchantSlot == slot)
            continue;

        SpellItemEnchantmentEntry const* enchantmentEntry = sSpellItemEnchantmentStore.LookupEntry(item->GetEnchantmentId(EnchantmentSlot(slot)));
        if (!enchantmentEntry)
            continue;

        for (uint8 i = 0; i < MAX_ITEM_ENCHANTMENT_EFFECTS; ++i)
        {
            switch (enchantmentEntry->type[i])
            {
                case ITEM_ENCHANTMENT_TYPE_DAMAGE:
                    amount += enchantmentEntry->amount[i];
                    break;
                case ITEM_ENCHANTMENT_TYPE_TOTEM:
                    if (GetClass() == CLASS_SHAMAN)
                        amount += enchantmentEntry->amount[i] * item->GetTemplate()->Delay / 1000.0f;
                    break;
                default:
                    break;
            }
        }
    }

    HandleStatFlatModifier(unitMod, TOTAL_VALUE, amount, true);
}

void Player::UpdateBaseModGroup(BaseModGroup modGroup)
{
    if (!CanModifyStats())
        return;

    switch (modGroup)
    {
        case CRIT_PERCENTAGE:              UpdateCritPercentage(BASE_ATTACK);                          break;
        case RANGED_CRIT_PERCENTAGE:       UpdateCritPercentage(RANGED_ATTACK);                        break;
        case OFFHAND_CRIT_PERCENTAGE:      UpdateCritPercentage(OFF_ATTACK);                           break;
        case SHIELD_BLOCK_VALUE:           UpdateShieldBlockValue();                                   break;
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

    return (modType == FLAT_MOD ? m_auraBaseFlatMod[modGroup] : m_auraBasePctMod[modGroup]);
}

float Player::GetTotalBaseModValue(BaseModGroup modGroup) const
{
    if (modGroup >= BASEMOD_END)
    {
        TC_LOG_ERROR("spells", "Player::GetTotalBaseModValue: Invalid BaseModGroup (%u) for player '%s' (%s)",
            modGroup, GetName().c_str(), GetGUID().ToString().c_str());
        return 0.0f;
    }

    return m_auraBaseFlatMod[modGroup] * m_auraBasePctMod[modGroup];
}

uint32 Player::GetShieldBlockValue() const
{
    float value = std::max(0.f, (m_auraBaseFlatMod[SHIELD_BLOCK_VALUE] + GetStat(STAT_STRENGTH) * 0.5f - 10) * m_auraBasePctMod[SHIELD_BLOCK_VALUE]);
    return uint32(value);
}

float Player::GetMeleeCritFromAgility() const
{
    uint8 level = GetLevel();
    uint32 pclass = GetClass();

    if (level > GT_MAX_LEVEL)
        level = GT_MAX_LEVEL;

    GtChanceToMeleeCritBaseEntry const* critBase  = sGtChanceToMeleeCritBaseStore.LookupEntry(pclass-1);
    GtChanceToMeleeCritEntry     const* critRatio = sGtChanceToMeleeCritStore.LookupEntry((pclass-1)*GT_MAX_LEVEL + level-1);
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
         0.036640f, // Warrior
         0.034943f, // Paladin
        -0.040873f, // Hunter
         0.020957f, // Rogue
         0.034178f, // Priest
         0.036640f, // DK
         0.021080f, // Shaman
         0.036587f, // Mage
         0.024211f, // Warlock
         0.0f,      // ??
         0.056097f  // Druid
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

    uint8 level = GetLevel();
    uint32 pclass = GetClass();

    if (level > GT_MAX_LEVEL)
        level = GT_MAX_LEVEL;

    // Dodge per agility is proportional to crit per agility, which is available from DBC files
    GtChanceToMeleeCritEntry  const* dodgeRatio = sGtChanceToMeleeCritStore.LookupEntry((pclass-1)*GT_MAX_LEVEL + level-1);
    if (dodgeRatio == nullptr || pclass > MAX_CLASSES)
        return;

    /// @todo research if talents/effects that increase total agility by x% should increase non-diminishing part
    float base_agility = GetCreateStat(STAT_AGILITY) * GetPctModifierValue(UnitMods(UNIT_MOD_STAT_START + STAT_AGILITY), BASE_PCT);
    float bonus_agility = GetStat(STAT_AGILITY) - base_agility;

    // calculate diminishing (green in char screen) and non-diminishing (white) contribution
    diminishing = 100.0f * bonus_agility * dodgeRatio->ratio * crit_to_dodge[pclass-1];
    nondiminishing = 100.0f * (dodge_base[pclass-1] + base_agility * dodgeRatio->ratio * crit_to_dodge[pclass-1]);
}

float Player::GetSpellCritFromIntellect() const
{
    uint8 level = GetLevel();
    uint32 pclass = GetClass();

    if (level > GT_MAX_LEVEL)
        level = GT_MAX_LEVEL;

    GtChanceToSpellCritBaseEntry const* critBase  = sGtChanceToSpellCritBaseStore.LookupEntry(pclass-1);
    GtChanceToSpellCritEntry     const* critRatio = sGtChanceToSpellCritStore.LookupEntry((pclass-1)*GT_MAX_LEVEL + level-1);
    if (critBase == nullptr || critRatio == nullptr)
        return 0.0f;

    float crit = critBase->base + GetStat(STAT_INTELLECT) * critRatio->ratio;
    return crit * 100.0f;
}

float Player::GetRatingMultiplier(CombatRating cr) const
{
    uint8 level = GetLevel();

    if (level > GT_MAX_LEVEL)
        level = GT_MAX_LEVEL;

    GtCombatRatingsEntry const* Rating = sGtCombatRatingsStore.LookupEntry(cr*GT_MAX_LEVEL+level-1);
    // gtOCTClassCombatRatingScalarStore.dbc starts with 1, CombatRating with zero, so cr+1
    GtOCTClassCombatRatingScalarEntry const* classRating = sGtOCTClassCombatRatingScalarStore.LookupEntry((GetClass()-1)*GT_MAX_RATING+cr+1);
    if (!Rating || !classRating)
        return 1.0f;                                        // By default use minimum coefficient (not must be called)

    return classRating->ratio / Rating->ratio;
}

float Player::GetRatingBonusValue(CombatRating cr) const
{
    return float(GetUInt32Value(PLAYER_FIELD_COMBAT_RATING_1 + cr)) * GetRatingMultiplier(cr);
}

float Player::GetExpertiseDodgeOrParryReduction(WeaponAttackType attType) const
{
    switch (attType)
    {
        case BASE_ATTACK:
            return GetUInt32Value(PLAYER_EXPERTISE) / 4.0f;
        case OFF_ATTACK:
            return GetUInt32Value(PLAYER_OFFHAND_EXPERTISE) / 4.0f;
        default:
            break;
    }
    return 0.0f;
}

float Player::OCTRegenHPPerSpirit() const
{
    uint8 level = GetLevel();
    uint32 pclass = GetClass();

    if (level > GT_MAX_LEVEL)
        level = GT_MAX_LEVEL;

    GtOCTRegenHPEntry     const* baseRatio = sGtOCTRegenHPStore.LookupEntry((pclass-1)*GT_MAX_LEVEL + level-1);
    GtRegenHPPerSptEntry  const* moreRatio = sGtRegenHPPerSptStore.LookupEntry((pclass-1)*GT_MAX_LEVEL + level-1);
    if (baseRatio == nullptr || moreRatio == nullptr)
        return 0.0f;

    // Formula from PaperDollFrame script
    float spirit = GetStat(STAT_SPIRIT);
    float baseSpirit = spirit;
    if (baseSpirit > 50)
        baseSpirit = 50;
    float moreSpirit = spirit - baseSpirit;
    float regen = baseSpirit * baseRatio->ratio + moreSpirit * moreRatio->ratio;
    return regen;
}

float Player::OCTRegenMPPerSpirit() const
{
    uint8 level = GetLevel();
    uint32 pclass = GetClass();

    if (level > GT_MAX_LEVEL)
        level = GT_MAX_LEVEL;

//    GtOCTRegenMPEntry     const* baseRatio = sGtOCTRegenMPStore.LookupEntry((pclass-1)*GT_MAX_LEVEL + level-1);
    GtRegenMPPerSptEntry  const* moreRatio = sGtRegenMPPerSptStore.LookupEntry((pclass-1)*GT_MAX_LEVEL + level-1);
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
    for (AuraEffect const* aurEff : modRatingFromStat)
        if (aurEff->GetMiscValue() & (1 << cr))
            amount += int32(CalculatePct(GetStat(Stats(aurEff->GetMiscValueB())), aurEff->GetAmount()));

    if (amount < 0)
        amount = 0;
    SetUInt32Value(PLAYER_FIELD_COMBAT_RATING_1 + cr, uint32(amount));

    bool affectStats = CanModifyStats();

    switch (cr)
    {
        case CR_WEAPON_SKILL:                               // Implemented in Unit::RollMeleeOutcomeAgainst
        case CR_DEFENSE_SKILL:
            UpdateDefenseBonusesMod();
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
        case CR_HIT_TAKEN_MELEE:                            // Implemented in Unit::MeleeMissChanceCalc
        case CR_HIT_TAKEN_RANGED:
            break;
        case CR_HIT_TAKEN_SPELL:                            // Implemented in Unit::MagicSpellHitResult
            break;
        case CR_CRIT_TAKEN_MELEE:                           // Implemented in Unit::RollMeleeOutcomeAgainst (only for chance to crit)
        case CR_CRIT_TAKEN_RANGED:
            break;
        case CR_CRIT_TAKEN_SPELL:                           // Implemented in Unit::SpellCriticalBonus (only for chance to crit)
            break;
        case CR_HASTE_MELEE:                                // Implemented in Player::ApplyRatingMod
        case CR_HASTE_RANGED:
        case CR_HASTE_SPELL:
            break;
        case CR_WEAPON_SKILL_MAINHAND:                      // Implemented in Unit::RollMeleeOutcomeAgainst
        case CR_WEAPON_SKILL_OFFHAND:
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
    }
}

void Player::UpdateAllRatings()
{
    for (uint8 cr = 0; cr < MAX_COMBAT_RATING; ++cr)
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
            if (proto->Delay)
                SetAttackTime(WeaponAttackType(i), proto->Delay);
        }
        else
            SetAttackTime(WeaponAttackType(i), BASE_ATTACK_TIME);  // If there is no weapon reset attack time to base (might have been changed from forms)
    }
}

void Player::StoreRaidMapDifficulty()
{
    m_raidMapDifficulty = GetMap()->GetDifficulty();
}

//skill+step, checking for max value
bool Player::UpdateSkill(uint32 skill_id, uint32 step)
{
    if (!skill_id)
        return false;

    SkillStatusMap::iterator itr = mSkillStatus.find(skill_id);
    if (itr == mSkillStatus.end() || itr->second.uState == SKILL_DELETED)
        return false;

    uint32 valueIndex = PLAYER_SKILL_VALUE_INDEX(itr->second.pos);
    uint32 data = GetUInt32Value(valueIndex);
    uint32 value = SKILL_VALUE(data);
    uint32 max = SKILL_MAX(data);

    if ((!max) || (!value) || (value >= max))
        return false;

    if (value < max)
    {
        uint32 new_value = value + step;
        if (new_value > max)
            new_value = max;

        SetUInt32Value(valueIndex, MAKE_SKILL_VALUE(new_value, max));
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
        if (_spell_idx->second->skillId)
        {
            uint32 SkillValue = GetPureSkillValue(_spell_idx->second->skillId);

            // Alchemy Discoveries here
            SpellInfo const* spellEntry = sSpellMgr->GetSpellInfo(spellid);
            if (spellEntry && spellEntry->Mechanic == MECHANIC_DISCOVERY)
            {
                if (uint32 discoveredSpell = GetSkillDiscoverySpell(_spell_idx->second->skillId, spellid, this))
                    LearnSpell(discoveredSpell, false);
            }

            uint32 craft_skill_gain = sWorld->getIntConfig(CONFIG_SKILL_GAIN_CRAFTING);

            return UpdateSkillPro(_spell_idx->second->skillId, SkillGainChance(SkillValue,
                _spell_idx->second->max_value,
                (_spell_idx->second->max_value + _spell_idx->second->min_value)/2,
                _spell_idx->second->min_value),
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

uint8 GetFishingStepsNeededToLevelUp(uint32 SkillValue)
{
    // These formulas are guessed to be as close as possible to how the skill difficulty curve for fishing was on Retail.
    if (SkillValue < 75)
        return 1;

    if (SkillValue <= 300)
        return SkillValue / 44;

    return SkillValue / 31;
}

bool Player::UpdateFishingSkill()
{
    TC_LOG_DEBUG("entities.player.skills", "Player::UpdateFishingSkill: Player '%s' (%s)", GetName().c_str(), GetGUID().ToString().c_str());

    uint32 SkillValue = GetPureSkillValue(SKILL_FISHING);

    if (SkillValue >= GetMaxSkillValue(SKILL_FISHING))
        return false;

    uint8 stepsNeededToLevelUp = GetFishingStepsNeededToLevelUp(SkillValue);
    ++m_fishingSteps;

    if (m_fishingSteps >= stepsNeededToLevelUp)
    {
        m_fishingSteps = 0;

        uint32 gathering_skill_gain = sWorld->getIntConfig(CONFIG_SKILL_GAIN_GATHERING);
        return UpdateSkillPro(SKILL_FISHING, 100*10, gathering_skill_gain);
    }

    return false;
}

// levels sync. with spell requirement for skill levels to learn
// bonus abilities in sSkillLineAbilityStore
// Used only to avoid scan DBC at each skill grow
static uint32 bonusSkillLevels[ ] = {75, 150, 225, 300, 375, 450};
static const size_t bonusSkillLevelsSize = sizeof(bonusSkillLevels) / sizeof(uint32);

bool Player::UpdateSkillPro(uint16 SkillId, int32 Chance, uint32 step)
{
    TC_LOG_DEBUG("entities.player.skills",  "Player::UpdateSkillPro: Player '%s' (%s), SkillID: %u, Chance: %3.1f%%)",
        GetName().c_str(), GetGUID().ToString().c_str(), SkillId, Chance / 10.0f);
    if (!SkillId)
        return false;

    if (Chance <= 0)                                         // speedup in 0 chance case
    {
        TC_LOG_DEBUG("entities.player.skills", "Player::UpdateSkillPro: Player '%s' (%s), SkillID: %u, Chance: %3.1f%% missed",
            GetName().c_str(), GetGUID().ToString().c_str(), SkillId, Chance / 10.0f);
        return false;
    }

    SkillStatusMap::iterator itr = mSkillStatus.find(SkillId);
    if (itr == mSkillStatus.end() || itr->second.uState == SKILL_DELETED)
        return false;

    uint32 valueIndex = PLAYER_SKILL_VALUE_INDEX(itr->second.pos);

    uint32 data = GetUInt32Value(valueIndex);
    uint16 SkillValue = SKILL_VALUE(data);
    uint16 MaxValue   = SKILL_MAX(data);

    if (!MaxValue || !SkillValue || SkillValue >= MaxValue)
        return false;

    int32 Roll = irand(1, 1000);

    if (Roll <= Chance)
    {
        uint32 new_value = SkillValue+step;
        if (new_value > MaxValue)
            new_value = MaxValue;

        SetUInt32Value(valueIndex, MAKE_SKILL_VALUE(new_value, MaxValue));
        if (itr->second.uState != SKILL_NEW)
            itr->second.uState = SKILL_CHANGED;
        for (size_t i = 0; i < bonusSkillLevelsSize; ++i)
        {
            uint32 bsl = bonusSkillLevels[i];
            if (SkillValue < bsl && new_value >= bsl)
            {
                LearnSkillRewardedSpells(SkillId, new_value);
                break;
            }
        }
        UpdateSkillEnchantments(SkillId, SkillValue, new_value);
        UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_REACH_SKILL_LEVEL, SkillId);
        TC_LOG_DEBUG("entities.player.skills", "Player::UpdateSkillPro: Player '%s' (%s), SkillID: %u, Chance: %3.1f%% taken",
            GetName().c_str(), GetGUID().ToString().c_str(), SkillId, Chance / 10.0f);
        return true;
    }

    TC_LOG_DEBUG("entities.player.skills", "Player::UpdateSkillPro: Player '%s' (%s), SkillID: %u, Chance: %3.1f%% missed",
        GetName().c_str(), GetGUID().ToString().c_str(), SkillId, Chance / 10.0f);
    return false;
}

void Player::UpdateWeaponSkill(WeaponAttackType attType)
{
    // no skill gain in pvp
    Unit* victim = GetVictim();
    if (victim && victim->GetTypeId() == TYPEID_PLAYER)
        return;

    if (IsInFeralForm())
        return;                                             // always maximized SKILL_FERAL_COMBAT in fact

    if (GetShapeshiftForm() == FORM_TREE)
        return;                                             // use weapon but not skill up

    if (victim && victim->GetTypeId() == TYPEID_UNIT && (victim->ToCreature()->GetCreatureTemplate()->flags_extra & CREATURE_FLAG_EXTRA_NO_SKILLGAIN))
        return;

    uint32 weapon_skill_gain = sWorld->getIntConfig(CONFIG_SKILL_GAIN_WEAPON);

    Item* tmpitem = GetWeaponForAttack(attType, true);
    if (!tmpitem && attType == BASE_ATTACK)
    {
        // Keep unarmed & fist weapon skills in sync
        UpdateSkill(SKILL_UNARMED, weapon_skill_gain);
        UpdateSkill(SKILL_FIST_WEAPONS, weapon_skill_gain);
    }
    else if (tmpitem)
    {
        switch (tmpitem->GetTemplate()->SubClass)
        {
            case ITEM_SUBCLASS_WEAPON_FISHING_POLE:
                break;
            case ITEM_SUBCLASS_WEAPON_FIST:
                UpdateSkill(SKILL_UNARMED, weapon_skill_gain);
                /* fallthrough */
            default:
                UpdateSkill(tmpitem->GetSkill(), weapon_skill_gain);
                break;
        }
    }

    UpdateAllCritPercentages();
}

void Player::UpdateCombatSkills(Unit* victim, WeaponAttackType attType, bool defense)
{
    uint8 plevel = GetLevel();                              // if defense than victim == attacker
    uint8 greylevel = Trinity::XP::GetGrayLevel(plevel);
    uint8 moblevel = victim->GetLevelForTarget(this);

    if (moblevel > plevel + 5)
        moblevel = plevel + 5;

    uint8 lvldif = moblevel - greylevel;
    if (lvldif < 3)
        lvldif = 3;

    uint32 skilldif = 5 * plevel - (defense ? GetBaseDefenseSkillValue() : GetBaseWeaponSkillValue(attType));
    if (skilldif <= 0)
        return;

    float chance = float(3 * lvldif * skilldif) / plevel;
    if (!defense)
        if (GetClass() == CLASS_WARRIOR || GetClass() == CLASS_ROGUE)
            chance += chance * 0.02f * GetStat(STAT_INTELLECT);

    chance = chance < 1.0f ? 1.0f : chance;                 //minimum chance to increase skill is 1%

    if (roll_chance_f(chance))
    {
        if (defense)
            UpdateDefense();
        else
            UpdateWeaponSkill(attType);
    }
    else
        return;
}

void Player::ModifySkillBonus(uint32 skillid, int32 val, bool talent)
{
    SkillStatusMap::const_iterator itr = mSkillStatus.find(skillid);
    if (itr == mSkillStatus.end() || itr->second.uState == SKILL_DELETED)
        return;

    uint32 bonusIndex = PLAYER_SKILL_BONUS_INDEX(itr->second.pos);

    uint32 bonus_val = GetUInt32Value(bonusIndex);
    int16 temp_bonus = SKILL_TEMP_BONUS(bonus_val);
    int16 perm_bonus = SKILL_PERM_BONUS(bonus_val);

    if (talent)                                          // permanent bonus stored in high part
        SetUInt32Value(bonusIndex, MAKE_SKILL_BONUS(temp_bonus, perm_bonus+val));
    else                                                // temporary/item bonus stored in low part
        SetUInt32Value(bonusIndex, MAKE_SKILL_BONUS(temp_bonus+val, perm_bonus));
}

void Player::UpdateSkillsForLevel()
{
    uint16 maxconfskill = sWorld->GetConfigMaxSkillValue();
    uint32 maxSkill = GetMaxSkillValueForLevel();

    bool alwaysMaxSkill = sWorld->getBoolConfig(CONFIG_ALWAYS_MAX_SKILL_FOR_LEVEL);

    for (SkillStatusMap::iterator itr = mSkillStatus.begin(); itr != mSkillStatus.end(); ++itr)
    {
        if (itr->second.uState == SKILL_DELETED)
            continue;

        uint32 pskill = itr->first;
        SkillRaceClassInfoEntry const* rcEntry = GetSkillRaceClassInfo(pskill, GetRace(), GetClass());
        if (!rcEntry)
            continue;

        if (GetSkillRangeType(rcEntry) != SKILL_RANGE_LEVEL)
            continue;

        uint32 valueIndex = PLAYER_SKILL_VALUE_INDEX(itr->second.pos);
        uint32 data = GetUInt32Value(valueIndex);
        uint32 max = SKILL_MAX(data);
        uint32 val = SKILL_VALUE(data);

        /// update only level dependent max skill values
        if (max != 1)
        {
            /// maximize skill always
            if (alwaysMaxSkill)
            {
                SetUInt32Value(valueIndex, MAKE_SKILL_VALUE(maxSkill, maxSkill));
                if (itr->second.uState != SKILL_NEW)
                    itr->second.uState = SKILL_CHANGED;
            }
            else if (max != maxconfskill)                    /// update max skill value if current max skill not maximized
            {
                SetUInt32Value(valueIndex, MAKE_SKILL_VALUE(val, maxSkill));
                if (itr->second.uState != SKILL_NEW)
                    itr->second.uState = SKILL_CHANGED;
            }
        }
    }
}

void Player::UpdateWeaponsSkillsToMaxSkillsForLevel()
{
    for (SkillStatusMap::iterator itr = mSkillStatus.begin(); itr != mSkillStatus.end(); ++itr)
    {
        if (itr->second.uState == SKILL_DELETED)
            continue;

        uint32 pskill = itr->first;
        if (IsProfessionOrRidingSkill(pskill))
            continue;
        uint32 valueIndex = PLAYER_SKILL_VALUE_INDEX(itr->second.pos);
        uint32 data = GetUInt32Value(valueIndex);
        uint32 max = SKILL_MAX(data);

        if (max > 1)
        {
            SetUInt32Value(valueIndex, MAKE_SKILL_VALUE(max, max));
            if (itr->second.uState != SKILL_NEW)
                itr->second.uState = SKILL_CHANGED;
        }
        if (pskill == SKILL_DEFENSE)
            UpdateDefenseBonusesMod();
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
        currVal = SKILL_VALUE(GetUInt32Value(PLAYER_SKILL_VALUE_INDEX(itr->second.pos)));
        if (newVal)
        {
            // if skill value is going down, update enchantments before setting the new value
            if (newVal < currVal)
                UpdateSkillEnchantments(id, currVal, newVal);
            // update step
            SetUInt32Value(PLAYER_SKILL_INDEX(itr->second.pos), MAKE_PAIR32(id, step));
            // update value
            SetUInt32Value(PLAYER_SKILL_VALUE_INDEX(itr->second.pos), MAKE_SKILL_VALUE(newVal, maxVal));
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
            SetUInt32Value(PLAYER_SKILL_INDEX(itr->second.pos), 0);
            SetUInt32Value(PLAYER_SKILL_VALUE_INDEX(itr->second.pos), 0);
            SetUInt32Value(PLAYER_SKILL_BONUS_INDEX(itr->second.pos), 0);

            // mark as deleted or simply remove from map if not saved yet
            if (itr->second.uState != SKILL_NEW)
                itr->second.uState = SKILL_DELETED;
            else
                mSkillStatus.erase(itr);

            // remove all spells that related to this skill
            for (uint32 j = 0; j < sSkillLineAbilityStore.GetNumRows(); ++j)
                if (SkillLineAbilityEntry const* pAbility = sSkillLineAbilityStore.LookupEntry(j))
                    if (pAbility->skillId == id)
                        RemoveSpell(sSpellMgr->GetFirstSpellInChain(pAbility->spellId));
        }
    }
    else if (newVal)                                        //add
    {
        currVal = 0;
        for (int i=0; i < PLAYER_MAX_SKILLS; ++i)
        {
            if (!GetUInt32Value(PLAYER_SKILL_INDEX(i)))
            {
                SkillLineEntry const* pSkill = sSkillLineStore.LookupEntry(id);
                if (!pSkill)
                {
                    TC_LOG_ERROR("misc", "Player::SetSkill: Skill (SkillID: %u) not found in SkillLineStore for player '%s' (%s)",
                        id, GetName().c_str(), GetGUID().ToString().c_str());
                    return;
                }

                SetUInt32Value(PLAYER_SKILL_INDEX(i), MAKE_PAIR32(id, step));
                SetUInt32Value(PLAYER_SKILL_VALUE_INDEX(i), MAKE_SKILL_VALUE(newVal, maxVal));
                UpdateSkillEnchantments(id, currVal, newVal);

                // insert new entry or update if not deleted old entry yet
                if (itr != mSkillStatus.end())
                {
                    itr->second.pos = i;
                    itr->second.uState = SKILL_CHANGED;
                }
                else
                    mSkillStatus.insert(SkillStatusMap::value_type(id, SkillStatusData(i, SKILL_NEW)));

                // apply skill bonuses
                SetUInt32Value(PLAYER_SKILL_BONUS_INDEX(i), 0);

                // temporary bonuses
                AuraEffectList const& mModSkill = GetAuraEffectsByType(SPELL_AURA_MOD_SKILL);
                for (AuraEffectList::const_iterator j = mModSkill.begin(); j != mModSkill.end(); ++j)
                    if ((*j)->GetMiscValue() == int32(id))
                        (*j)->HandleEffect(this, AURA_EFFECT_HANDLE_SKILL, true);

                // permanent bonuses
                AuraEffectList const& mModSkillTalent = GetAuraEffectsByType(SPELL_AURA_MOD_SKILL_TALENT);
                for (AuraEffectList::const_iterator j = mModSkillTalent.begin(); j != mModSkillTalent.end(); ++j)
                    if ((*j)->GetMiscValue() == int32(id))
                        (*j)->HandleEffect(this, AURA_EFFECT_HANDLE_SKILL, true);

                // Learn all spells for skill
                LearnSkillRewardedSpells(id, newVal);
                UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_REACH_SKILL_LEVEL, id);
                UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_LEARN_SKILL_LEVEL, id);
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

    return PAIR32_HIPART(GetUInt32Value(PLAYER_SKILL_INDEX(itr->second.pos)));
}

uint16 Player::GetSkillValue(uint32 skill) const
{
    if (!skill)
        return 0;

    SkillStatusMap::const_iterator itr = mSkillStatus.find(skill);
    if (itr == mSkillStatus.end() || itr->second.uState == SKILL_DELETED)
        return 0;

    uint32 bonus = GetUInt32Value(PLAYER_SKILL_BONUS_INDEX(itr->second.pos));

    int32 result = int32(SKILL_VALUE(GetUInt32Value(PLAYER_SKILL_VALUE_INDEX(itr->second.pos))));
    result += SKILL_TEMP_BONUS(bonus);
    result += SKILL_PERM_BONUS(bonus);
    return result < 0 ? 0 : result;
}

uint16 Player::GetMaxSkillValue(uint32 skill) const
{
    if (!skill)
        return 0;

    SkillStatusMap::const_iterator itr = mSkillStatus.find(skill);
    if (itr == mSkillStatus.end() || itr->second.uState == SKILL_DELETED)
        return 0;

    uint32 bonus = GetUInt32Value(PLAYER_SKILL_BONUS_INDEX(itr->second.pos));

    int32 result = int32(SKILL_MAX(GetUInt32Value(PLAYER_SKILL_VALUE_INDEX(itr->second.pos))));
    result += SKILL_TEMP_BONUS(bonus);
    result += SKILL_PERM_BONUS(bonus);
    return result < 0 ? 0 : result;
}

uint16 Player::GetPureMaxSkillValue(uint32 skill) const
{
    if (!skill)
        return 0;

    SkillStatusMap::const_iterator itr = mSkillStatus.find(skill);
    if (itr == mSkillStatus.end() || itr->second.uState == SKILL_DELETED)
        return 0;

    return SKILL_MAX(GetUInt32Value(PLAYER_SKILL_VALUE_INDEX(itr->second.pos)));
}

uint16 Player::GetBaseSkillValue(uint32 skill) const
{
    if (!skill)
        return 0;

    SkillStatusMap::const_iterator itr = mSkillStatus.find(skill);
    if (itr == mSkillStatus.end() || itr->second.uState == SKILL_DELETED)
        return 0;

    int32 result = int32(SKILL_VALUE(GetUInt32Value(PLAYER_SKILL_VALUE_INDEX(itr->second.pos))));
    result += SKILL_PERM_BONUS(GetUInt32Value(PLAYER_SKILL_BONUS_INDEX(itr->second.pos)));
    return result < 0 ? 0 : result;
}

uint16 Player::GetPureSkillValue(uint32 skill) const
{
    if (!skill)
        return 0;

    SkillStatusMap::const_iterator itr = mSkillStatus.find(skill);
    if (itr == mSkillStatus.end() || itr->second.uState == SKILL_DELETED)
        return 0;

    return SKILL_VALUE(GetUInt32Value(PLAYER_SKILL_VALUE_INDEX(itr->second.pos)));
}

int16 Player::GetSkillPermBonusValue(uint32 skill) const
{
    if (!skill)
        return 0;

    SkillStatusMap::const_iterator itr = mSkillStatus.find(skill);
    if (itr == mSkillStatus.end() || itr->second.uState == SKILL_DELETED)
        return 0;

    return SKILL_PERM_BONUS(GetUInt32Value(PLAYER_SKILL_BONUS_INDEX(itr->second.pos)));
}

int16 Player::GetSkillTempBonusValue(uint32 skill) const
{
    if (!skill)
        return 0;

    SkillStatusMap::const_iterator itr = mSkillStatus.find(skill);
    if (itr == mSkillStatus.end() || itr->second.uState == SKILL_DELETED)
        return 0;

    return SKILL_TEMP_BONUS(GetUInt32Value(PLAYER_SKILL_BONUS_INDEX(itr->second.pos)));
}

void Player::SendActionButtons(uint32 state) const
{
    WorldPacket data(SMSG_ACTION_BUTTONS, 1+(MAX_ACTION_BUTTONS*4));
    data << uint8(state);
    /*
        state can be 0, 1, 2
        0 - Looks to be sent when initial action buttons get sent, however on Trinity we use 1 since 0 had some difficulties
        1 - Used in any SMSG_ACTION_BUTTONS packet with button data on Trinity. Only used after spec swaps on retail.
        2 - Clears the action bars client sided. This is sent during spec swap before unlearning and before sending the new buttons
    */
    if (state != 2)
    {
        for (uint8 button = 0; button < MAX_ACTION_BUTTONS; ++button)
        {
            ActionButtonList::const_iterator itr = m_actionButtons.find(button);
            if (itr != m_actionButtons.end() && itr->second.uState != ACTIONBUTTON_DELETED)
                data << uint32(itr->second.packedData);
            else
                data << uint32(0);
        }
    }

    SendDirectMessage(&data);

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
                TC_LOG_DEBUG("entities.player", "Player::IsActionButtonDataValid: Spell action %u not added into button %u for player %s (%s): spell does not exist. This can be due to a character imported from a different expansion",
                    action, button, GetName().c_str(), GetGUID().ToString().c_str());
                return false;
            }

            if (!HasSpell(action))
            {
                TC_LOG_DEBUG("entities.player", "Player::IsActionButtonDataValid: Spell action %u not added into button %u for player %s (%s): player does not known this spell, this can be due to a player changing their talents",
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
        case ACTION_BUTTON_C:
        case ACTION_BUTTON_CMACRO:
        case ACTION_BUTTON_MACRO:
        case ACTION_BUTTON_EQSET:
            break;
        default:
            TC_LOG_ERROR("entities.player", "Player::IsActionButtonDataValid: Unknown action type %u", type);
            return false;                                          // other cases not checked at this moment
    }

    return true;
}

ActionButton* Player::addActionButton(uint8 button, uint32 action, uint8 type)
{
    if (!IsActionButtonDataValid(button, action, type))
        return nullptr;

    // it create new button (NEW state) if need or return existing
    ActionButton& ab = m_actionButtons[button];

    // set data and update to CHANGED if not NEW
    ab.SetActionAndType(action, ActionButtonType(type));

    TC_LOG_DEBUG("entities.player", "Player::AddActionButton: Player '%s' (%s) added action '%u' (type %u) to button '%u'",
        GetName().c_str(), GetGUID().ToString().c_str(), action, type, button);
    return &ab;
}

void Player::removeActionButton(uint8 button)
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

    // Update player zone if needed
    if (m_needsZoneUpdate)
    {
        uint32 newZone, newArea;
        GetZoneAndAreaId(newZone, newArea);
        UpdateZone(newZone, newArea);
        m_needsZoneUpdate = false;
    }

    // group update
    if (GetGroup())
        SetGroupUpdateFlag(GROUP_UPDATE_FLAG_POSITION);

    CheckAreaExploreAndOutdoor();

    return true;
}

void Player::SendMessageToSetInRange(WorldPacket const* data, float dist, bool self) const
{
    if (self)
        SendDirectMessage(data);

    Trinity::MessageDistDeliverer notifier(this, data, dist);
    Cell::VisitWorldObjects(this, notifier, dist);
}

void Player::SendMessageToSetInRange(WorldPacket const* data, float dist, bool self, bool own_team_only) const
{
    if (self)
        SendDirectMessage(data);

    Trinity::MessageDistDeliverer notifier(this, data, dist, own_team_only);
    Cell::VisitWorldObjects(this, notifier, dist);
}

void Player::SendMessageToSet(WorldPacket const* data, Player const* skipped_rcvr) const
{
    if (skipped_rcvr != this)
        SendDirectMessage(data);

    // we use World::GetMaxVisibleDistance() because i cannot see why not use a distance
    // update: replaced by GetMap()->GetVisibilityDistance()
    Trinity::MessageDistDeliverer notifier(this, data, GetVisibilityRange(), false, skipped_rcvr);
    Cell::VisitWorldObjects(this, notifier, GetVisibilityRange());
}

void Player::SendDirectMessage(WorldPacket const* data) const
{
    m_session->SendPacket(data);
}

void Player::SendCinematicStart(uint32 CinematicSequenceId) const
{
    WorldPacket data(SMSG_TRIGGER_CINEMATIC, 4);
    data << uint32(CinematicSequenceId);
    SendDirectMessage(&data);
    if (CinematicSequencesEntry const* sequence = sCinematicSequencesStore.LookupEntry(CinematicSequenceId))
        _cinematicMgr->SetActiveCinematicCamera(sequence->cinematicCamera);
}

void Player::SendMovieStart(uint32 MovieId) const
{
    WorldPacket data(SMSG_TRIGGER_MOVIE, 4);
    data << uint32(MovieId);
    SendDirectMessage(&data);
}

void Player::CheckAreaExploreAndOutdoor()
{
    if (!IsAlive())
        return;

    if (IsInFlight())
        return;

    if (sWorld->getBoolConfig(CONFIG_VMAP_INDOOR_CHECK) && !IsOutdoors())
        RemoveAurasWithAttribute(SPELL_ATTR0_OUTDOORS_ONLY);

    uint32 const areaId = GetAreaId();
    if (!areaId)
        return;

    AreaTableEntry const* areaEntry = sAreaTableStore.LookupEntry(areaId);
    if (!areaEntry)
    {
        TC_LOG_ERROR("entities.player", "Player '%s' (%s) discovered unknown area (x: %f y: %f z: %f map: %u)",
            GetName().c_str(), GetGUID().ToString().c_str(), GetPositionX(), GetPositionY(), GetPositionZ(), GetMapId());
        return;
    }

    uint32 offset = areaEntry->exploreFlag / 32;

    if (offset >= PLAYER_EXPLORED_ZONES_SIZE)
    {
        TC_LOG_ERROR("entities.player", "Player::CheckAreaExploreAndOutdoor: Wrong area flag %u in map data for (X: %f Y: %f) point to field PLAYER_EXPLORED_ZONES_1 + %u ( %u must be < %u ).",
            areaEntry->exploreFlag, GetPositionX(), GetPositionY(), offset, offset, PLAYER_EXPLORED_ZONES_SIZE);
        return;
    }

    uint32 val = (uint32)(1 << (areaEntry->exploreFlag % 32));
    uint32 currFields = GetUInt32Value(PLAYER_EXPLORED_ZONES_1 + offset);

    if (!(currFields & val))
    {
        SetUInt32Value(PLAYER_EXPLORED_ZONES_1 + offset, (uint32)(currFields | val));

        UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_EXPLORE_AREA, GetAreaId());

        if (areaEntry->area_level > 0)
        {
            if (GetLevel() >= sWorld->getIntConfig(CONFIG_MAX_PLAYER_LEVEL))
            {
                SendExplorationExperience(areaId, 0);
            }
            else
            {
                int32 diff = int32(GetLevel()) - areaEntry->area_level;
                uint32 XP;
                if (diff < -5)
                {
                    XP = uint32(sObjectMgr->GetBaseXP(GetLevel()+5)*sWorld->getRate(RATE_XP_EXPLORE));
                }
                else if (diff > 5)
                {
                    int32 exploration_percent = 100 - ((diff - 5) * 5);
                    if (exploration_percent < 0)
                        exploration_percent = 0;

                    XP = uint32(sObjectMgr->GetBaseXP(areaEntry->area_level)*exploration_percent/100*sWorld->getRate(RATE_XP_EXPLORE));
                }
                else
                {
                    XP = uint32(sObjectMgr->GetBaseXP(areaEntry->area_level)*sWorld->getRate(RATE_XP_EXPLORE));
                }

                if (sWorld->getIntConfig(CONFIG_MIN_DISCOVERED_SCALED_XP_RATIO))
                {
                    uint32 minScaledXP = uint32(sObjectMgr->GetBaseXP(areaEntry->area_level)*sWorld->getRate(RATE_XP_EXPLORE)) * sWorld->getIntConfig(CONFIG_MIN_DISCOVERED_SCALED_XP_RATIO) / 100;
                    XP = std::max(minScaledXP, XP);
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
            case 1: return HORDE;
            case 7: return ALLIANCE;
        }
        TC_LOG_ERROR("entities.player", "Race (%u) has wrong teamid (%u) in DBC: wrong DBC files?", uint32(race), rEntry->TeamID);
    }
    else
        TC_LOG_ERROR("entities.player", "Race (%u) not found in DBC: wrong DBC files?", uint32(race));

    return ALLIANCE;
}

void Player::SetFactionForRace(uint8 race)
{
    m_team = TeamForRace(race);

    ChrRacesEntry const* rEntry = sChrRacesStore.LookupEntry(race);
    SetFaction(rEntry ? rEntry->FactionID : 0);
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

    if (rate != 1.0f && creatureOrQuestLevel <= Trinity::XP::GetGrayLevel(GetLevel()))
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
            if (LFGDungeonEntry const* dungeon = GetLFGDungeon(map->GetId(), map->GetDifficulty()))
                if (dungeon->reclevel == 80)
                    ChampioningFaction = GetChampioningFaction();
    }

    uint32 team = GetTeam();

    if (Rep->RepFaction1 && (!Rep->TeamDependent || team == ALLIANCE))
    {
        int32 donerep1 = CalculateReputationGain(REPUTATION_SOURCE_KILL, victim->GetLevel(), Rep->RepValue1, ChampioningFaction ? ChampioningFaction : Rep->RepFaction1);
        donerep1 = int32(donerep1 * rate);

        FactionEntry const* factionEntry1 = sFactionStore.LookupEntry(ChampioningFaction ? ChampioningFaction : Rep->RepFaction1);
        uint32 current_reputation_rank1 = GetReputationMgr().GetRank(factionEntry1);
        if (factionEntry1)
            GetReputationMgr().ModifyReputation(factionEntry1, donerep1, current_reputation_rank1 > Rep->ReputationMaxCap1);
    }

    if (Rep->RepFaction2 && (!Rep->TeamDependent || team == HORDE))
    {
        int32 donerep2 = CalculateReputationGain(REPUTATION_SOURCE_KILL, victim->GetLevel(), Rep->RepValue2, ChampioningFaction ? ChampioningFaction : Rep->RepFaction2);
        donerep2 = int32(donerep2 * rate);

        FactionEntry const* factionEntry2 = sFactionStore.LookupEntry(ChampioningFaction ? ChampioningFaction : Rep->RepFaction2);
        uint32 current_reputation_rank2 = GetReputationMgr().GetRank(factionEntry2);
        if (factionEntry2)
            GetReputationMgr().ModifyReputation(factionEntry2, donerep2, current_reputation_rank2 > Rep->ReputationMaxCap2);
    }
}

// Calculate how many reputation points player gain with the quest
void Player::RewardReputation(Quest const* quest)
{
    for (uint8 i = 0; i < QUEST_REPUTATIONS_COUNT; ++i)
    {
        uint32 rewardFactionId = quest->RewardFactionId[i];

        if (!rewardFactionId)
            continue;

        if (!GetReputationMgr().IsReputationAllowedForTeam(GetTeamId(), rewardFactionId))
            continue;

        int32 rep = 0;
        bool noQuestBonus = false;

        if (quest->RewardFactionValueIdOverride[i])
        {
            rep = quest->RewardFactionValueIdOverride[i] / 100;
            noQuestBonus = true;
        }
        else
        {
            uint32 row = ((quest->RewardFactionValueId[i] < 0) ? 1 : 0) + 1;
            if (QuestFactionRewEntry const* questFactionRewEntry = sQuestFactionRewardStore.LookupEntry(row))
            {
                uint32 field = abs(quest->RewardFactionValueId[i]);
                rep = questFactionRewEntry->QuestRewFactionValue[field];
            }
        }

        if (!rep)
            continue;

        if (quest->IsDaily())
            rep = CalculateReputationGain(REPUTATION_SOURCE_DAILY_QUEST, GetQuestLevel(quest), rep, rewardFactionId, noQuestBonus);
        else if (quest->IsWeekly())
            rep = CalculateReputationGain(REPUTATION_SOURCE_WEEKLY_QUEST, GetQuestLevel(quest), rep, rewardFactionId, noQuestBonus);
        else if (quest->IsMonthly())
            rep = CalculateReputationGain(REPUTATION_SOURCE_MONTHLY_QUEST, GetQuestLevel(quest), rep, rewardFactionId, noQuestBonus);
        else if (quest->IsRepeatable())
            rep = CalculateReputationGain(REPUTATION_SOURCE_REPEATABLE_QUEST, GetQuestLevel(quest), rep, rewardFactionId, noQuestBonus);
        else
            rep = CalculateReputationGain(REPUTATION_SOURCE_QUEST, GetQuestLevel(quest), rep, rewardFactionId, noQuestBonus);

        if (FactionEntry const* factionEntry = sFactionStore.LookupEntry(rewardFactionId))
            GetReputationMgr().ModifyReputation(factionEntry, rep);
    }
}

void Player::UpdateHonorFields()
{
    /// called when rewarding honor and at each save
    time_t now = GameTime::GetGameTime();
    time_t today = GameTime::GetGameTime() / DAY * DAY;

    if (m_lastHonorUpdateTime < today)
    {
        time_t yesterday = today - DAY;

        uint16 kills_today = PAIR32_LOPART(GetUInt32Value(PLAYER_FIELD_KILLS));

        // update yesterday's contribution
        if (m_lastHonorUpdateTime >= yesterday)
        {
            SetUInt32Value(PLAYER_FIELD_YESTERDAY_CONTRIBUTION, GetUInt32Value(PLAYER_FIELD_TODAY_CONTRIBUTION));

            // this is the first update today, reset today's contribution
            SetUInt32Value(PLAYER_FIELD_TODAY_CONTRIBUTION, 0);
            SetUInt32Value(PLAYER_FIELD_KILLS, MAKE_PAIR32(0, kills_today));
        }
        else
        {
            // no honor/kills yesterday or today, reset
            SetUInt32Value(PLAYER_FIELD_YESTERDAY_CONTRIBUTION, 0);
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

            uint8 k_level = GetLevel();
            uint8 k_grey = Trinity::XP::GetGrayLevel(k_level);
            uint8 v_level = victim->GetLevel();

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
            ApplyModUInt32Value(PLAYER_FIELD_KILLS, 1, true);
            // and those in a lifetime
            ApplyModUInt32Value(PLAYER_FIELD_LIFETIME_HONORABLE_KILLS, 1, true);
            UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_EARN_HONORABLE_KILL);
            UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_HK_CLASS, victim->GetClass());
            UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_HK_RACE, victim->GetRace());
            UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_HONORABLE_KILL_AT_AREA, GetAreaId());
            UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_HONORABLE_KILL, 1, 0, victim);
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
    WorldPacket data(SMSG_PVP_CREDIT, 4+8+4);
    data << uint32(honor);
    data << uint64(victim_guid);
    data << uint32(victim_rank);

    SendDirectMessage(&data);

    // add honor points
    ModifyHonorPoints(honor);

    ApplyModUInt32Value(PLAYER_FIELD_TODAY_CONTRIBUTION, honor, true);

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

void Player::SetHonorPoints(uint32 value)
{
    if (value > sWorld->getIntConfig(CONFIG_MAX_HONOR_POINTS))
        value = sWorld->getIntConfig(CONFIG_MAX_HONOR_POINTS);
    SetUInt32Value(PLAYER_FIELD_HONOR_CURRENCY, value);
    if (value)
        AddKnownCurrency(ITEM_HONOR_POINTS_ID);
}

void Player::SetArenaPoints(uint32 value)
{
    if (value > sWorld->getIntConfig(CONFIG_MAX_ARENA_POINTS))
        value = sWorld->getIntConfig(CONFIG_MAX_ARENA_POINTS);
    SetUInt32Value(PLAYER_FIELD_ARENA_CURRENCY, value);
    if (value)
        AddKnownCurrency(ITEM_ARENA_POINTS_ID);
}

void Player::ModifyHonorPoints(int32 value, SQLTransaction trans)
{
    int32 newValue = int32(GetHonorPoints()) + value;
    if (newValue < 0)
        newValue = 0;
    SetHonorPoints(uint32(newValue));

    if (trans)
    {
        PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_CHAR_HONOR_POINTS);
        stmt->setUInt32(0, newValue);
        stmt->setUInt32(1, GetGUID().GetCounter());
        trans->Append(stmt);
    }
}

void Player::ModifyArenaPoints(int32 value, SQLTransaction trans)
{
    int32 newValue = int32(GetArenaPoints()) + value;
    if (newValue < 0)
        newValue = 0;
    SetArenaPoints(uint32(newValue));

    if (trans)
    {
        PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_CHAR_ARENA_POINTS);
        stmt->setUInt32(0, newValue);
        stmt->setUInt32(1, GetGUID().GetCounter());
        trans->Append(stmt);
    }
}

void Player::SetInArenaTeam(uint32 ArenaTeamId, uint8 slot, uint8 type)
{
    SetArenaTeamInfoField(slot, ARENA_TEAM_ID, ArenaTeamId);
    SetArenaTeamInfoField(slot, ARENA_TEAM_TYPE, type);
}

void Player::SetArenaTeamInfoField(uint8 slot, ArenaTeamInfoType type, uint32 value)
{
    SetUInt32Value(PLAYER_FIELD_ARENA_TEAM_INFO_1_1 + (slot * ARENA_TEAM_END) + type, value);
}

uint32 Player::GetZoneIdFromDB(ObjectGuid guid)
{
    ObjectGuid::LowType guidLow = guid.GetCounter();
    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHAR_ZONE);
    stmt->setUInt32(0, guidLow);
    PreparedQueryResult result = CharacterDatabase.Query(stmt);

    if (!result)
        return 0;
    Field* fields = result->Fetch();
    uint32 zone = fields[0].GetUInt16();

    if (!zone)
    {
        // stored zone is zero, use generic and slow zone detection
        stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHAR_POSITION_XYZ);
        stmt->setUInt32(0, guidLow);
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
            stmt->setUInt32(1, guidLow);

            CharacterDatabase.Execute(stmt);
        }
    }

    return zone;
}

void Player::UpdateArea(uint32 newArea)
{
    // FFA_PVP flags are area and not zone id dependent
    // so apply them accordingly
    m_areaUpdateId = newArea;

    AreaTableEntry const* area = sAreaTableStore.LookupEntry(newArea);
    bool oldFFAPvPArea = pvpInfo.IsInFFAPvPArea;
    pvpInfo.IsInFFAPvPArea = area && (area->flags & AREA_FLAG_ARENA);
    UpdatePvPState(true);

    // check if we were in ffa arena and we left
    if (oldFFAPvPArea && !pvpInfo.IsInFFAPvPArea)
        ValidateAttackersAndOwnTarget();

    UpdateAreaDependentAuras(newArea);

    // previously this was in UpdateZone (but after UpdateArea) so nothing will break
    pvpInfo.IsInNoPvPArea = false;
    if (area && area->IsSanctuary())    // in sanctuary
    {
        SetByteFlag(UNIT_FIELD_BYTES_2, UNIT_BYTES_2_OFFSET_PVP_FLAG, UNIT_BYTE2_FLAG_SANCTUARY);
        pvpInfo.IsInNoPvPArea = true;
        if (!duel)
            CombatStopWithPets();
    }
    else
        RemoveByteFlag(UNIT_FIELD_BYTES_2, UNIT_BYTES_2_OFFSET_PVP_FLAG, UNIT_BYTE2_FLAG_SANCTUARY);

    uint32 const areaRestFlag = (GetTeam() == ALLIANCE) ? AREA_FLAG_REST_ZONE_ALLIANCE : AREA_FLAG_REST_ZONE_HORDE;
    if (area && area->flags & areaRestFlag)
        SetRestFlag(REST_FLAG_IN_FACTION_AREA);
    else
        RemoveRestFlag(REST_FLAG_IN_FACTION_AREA);
}

void Player::UpdateZone(uint32 newZone, uint32 newArea)
{
    if (!IsInWorld())
        return;

    uint32 const oldZone = m_zoneUpdateId;
    m_zoneUpdateId = newZone;
    m_zoneUpdateTimer = ZONE_UPDATE_INTERVAL;

    GetMap()->UpdatePlayerZoneStats(oldZone, newZone);

    // call leave script hooks immedately (before updating flags)
    if (oldZone != newZone)
    {
        sOutdoorPvPMgr->HandlePlayerLeaveZone(this, oldZone);
        sBattlefieldMgr->HandlePlayerLeaveZone(this, oldZone);
    }

    // group update
    if (GetGroup())
        SetGroupUpdateFlag(GROUP_UPDATE_FULL);

    // zone changed, so area changed as well, update it
    UpdateArea(newArea);

    AreaTableEntry const* zone = sAreaTableStore.LookupEntry(newZone);
    if (!zone)
        return;

    if (sWorld->getBoolConfig(CONFIG_WEATHER))
        GetMap()->GetOrGenerateZoneDefaultWeather(newZone);

    GetMap()->SendZoneDynamicInfo(newZone, this);


    // in PvP, any not controlled zone (except zone->team == 6, default case)
    // in PvE, only opposition team capital
    switch (zone->team)
    {
        case AREATEAM_ALLY:
            pvpInfo.IsInHostileArea = GetTeam() != ALLIANCE && (sWorld->IsPvPRealm() || zone->flags & AREA_FLAG_CAPITAL);
            break;
        case AREATEAM_HORDE:
            pvpInfo.IsInHostileArea = GetTeam() != HORDE && (sWorld->IsPvPRealm() || zone->flags & AREA_FLAG_CAPITAL);
            break;
        case AREATEAM_NONE:
            // overwrite for battlegrounds, maybe batter some zone flags but current known not 100% fit to this
            pvpInfo.IsInHostileArea = sWorld->IsPvPRealm() || InBattleground() || zone->flags & AREA_FLAG_WINTERGRASP;
            break;
        default:                                            // 6 in fact
            pvpInfo.IsInHostileArea = false;
            break;
    }

    // Treat players having a quest flagging for PvP as always in hostile area
    pvpInfo.IsHostile = pvpInfo.IsInHostileArea || HasPvPForcingQuest();

    if (zone->flags & AREA_FLAG_CAPITAL)                     // Is in a capital city
    {
        if (!pvpInfo.IsHostile || zone->IsSanctuary())
            SetRestFlag(REST_FLAG_IN_CITY);

        pvpInfo.IsInNoPvPArea = true;
    }
    else
        RemoveRestFlag(REST_FLAG_IN_CITY); // Recently left a capital city

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

    // call enter script hooks after everyting else has processed
    sScriptMgr->OnPlayerUpdateZone(this, newZone, newArea);
    if (oldZone != newZone)
    {
        sOutdoorPvPMgr->HandlePlayerEnterZone(this, newZone);
        sBattlefieldMgr->HandlePlayerEnterZone(this, newZone);
        SendInitWorldStates(newZone, newArea);              // only if really enters to new zone, not just area change, works strange...
        if (Guild* guild = GetGuild())
            guild->UpdateMemberData(this, GUILD_MEMBER_DATA_ZONEID, newZone);
    }
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

    if (!duel->OutOfBoundsTime)
    {
        if (!IsWithinDistInMap(obj, 50))
        {
            duel->OutOfBoundsTime = currTime + 10;

            WorldPacket data(SMSG_DUEL_OUTOFBOUNDS, 0);
            SendDirectMessage(&data);
        }
    }
    else
    {
        if (IsWithinDistInMap(obj, 40))
        {
            duel->OutOfBoundsTime = 0;

            WorldPacket data(SMSG_DUEL_INBOUNDS, 0);
            SendDirectMessage(&data);
        }
        else if (currTime >= duel->OutOfBoundsTime)
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

    // Check if DuelComplete() has been called already up in the stack and in that case don't do anything else here
    if (duel->State == DUEL_STATE_COMPLETED)
        return;

    Player* opponent = duel->Opponent;
    duel->State = DUEL_STATE_COMPLETED;
    opponent->duel->State = DUEL_STATE_COMPLETED;

    TC_LOG_DEBUG("entities.unit", "Player::DuelComplete: Player '%s' (%s), Opponent: '%s' (%s)",
        GetName().c_str(), GetGUID().ToString().c_str(), opponent->GetName().c_str(), opponent->GetGUID().ToString().c_str());

    WorldPacket data(SMSG_DUEL_COMPLETE, (1));
    data << uint8((type != DUEL_INTERRUPTED) ? 1 : 0);
    SendDirectMessage(&data);
    if (opponent->GetSession())
        opponent->SendDirectMessage(&data);

    if (type != DUEL_INTERRUPTED)
    {
        data.Initialize(SMSG_DUEL_WINNER, (1+20));          // we guess size
        data << uint8(type == DUEL_WON ? 0 : 1);            // 0 = just won; 1 = fled
        data << opponent->GetName();
        data << GetName();
        SendMessageToSet(&data, true);
    }

    sScriptMgr->OnPlayerDuelEnd(opponent, this, type);

    switch (type)
    {
        case DUEL_FLED:
            // if initiator and opponent are on the same team
            // or initiator and opponent are not PvP enabled, forcibly stop attacking
            if (GetTeam() == opponent->GetTeam())
            {
                AttackStop();
                opponent->AttackStop();
            }
            else
            {
                if (!IsPvP())
                    AttackStop();
                if (!opponent->IsPvP())
                    opponent->AttackStop();
            }
            break;
        case DUEL_WON:
            UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_LOSE_DUEL, 1);
            opponent->UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_WIN_DUEL, 1);

            // Credit for quest Death's Challenge
            if (GetClass() == CLASS_DEATH_KNIGHT && opponent->GetQuestStatus(12733) == QUEST_STATUS_INCOMPLETE)
                opponent->CastSpell(opponent, 52994, true);

            // Honor points after duel (the winner) - ImpConfig
            if (uint32 amount = sWorld->getIntConfig(CONFIG_HONOR_AFTER_DUEL))
                opponent->RewardHonor(nullptr, 1, amount);

            break;
        default:
            break;
    }

    // Victory emote spell
    if (type != DUEL_INTERRUPTED)
        opponent->CastSpell(opponent, 52852, true);

    //Remove Duel Flag object
    GameObject* obj = GetMap()->GetGameObject(GetGuidValue(PLAYER_DUEL_ARBITER));
    if (obj)
        duel->Initiator->RemoveGameObject(obj, true);

    /* remove auras */
    AuraApplicationMap &itsAuras = opponent->GetAppliedAuras();
    for (AuraApplicationMap::iterator i = itsAuras.begin(); i != itsAuras.end();)
    {
        Aura const* aura = i->second->GetBase();
        if (!i->second->IsPositive() && aura->GetCasterGUID() == GetGUID() && aura->GetApplyTime() >= duel->StartTime)
            opponent->RemoveAura(i);
        else
            ++i;
    }

    AuraApplicationMap &myAuras = GetAppliedAuras();
    for (AuraApplicationMap::iterator i = myAuras.begin(); i != myAuras.end();)
    {
        Aura const* aura = i->second->GetBase();
        if (!i->second->IsPositive() && aura->GetCasterGUID() == opponent->GetGUID() && aura->GetApplyTime() >= duel->StartTime)
            RemoveAura(i);
        else
            ++i;
    }

    // cleanup combo points
    if (GetComboTarget() && GetComboTarget()->GetControllingPlayer() == opponent)
        ClearComboPoints();

    if (opponent->GetComboTarget() && opponent->GetComboTarget()->GetControllingPlayer() == this)
        opponent->ClearComboPoints();

    //cleanups
    SetGuidValue(PLAYER_DUEL_ARBITER, ObjectGuid::Empty);
    SetUInt32Value(PLAYER_DUEL_TEAM, 0);
    opponent->SetGuidValue(PLAYER_DUEL_ARBITER, ObjectGuid::Empty);
    opponent->SetUInt32Value(PLAYER_DUEL_TEAM, 0);

    opponent->duel.reset(nullptr);
    duel.reset(nullptr);
}

//---------------------------------------------------------//

void Player::_ApplyItemMods(Item* item, uint8 slot, bool apply, bool updateItemAuras /*= true*/)
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

    if (proto->Socket[0].Color)                              //only (un)equipping of items with sockets can influence metagems, so no need to waste time with normal items
        CorrectMetaGemEnchants(slot, apply);

    _ApplyItemBonuses(proto, slot, apply);

    if (slot == EQUIPMENT_SLOT_RANGED)
        _ApplyAmmoBonuses();

    ApplyItemEquipSpell(item, apply);
    if (updateItemAuras)
    {
        ApplyItemDependentAuras(item, apply);

        WeaponAttackType const attackType = Player::GetAttackBySlot(slot);
        if (attackType != MAX_ATTACK)
            UpdateWeaponDependentAuras(attackType);
    }

    ApplyEnchantment(item, apply);

    TC_LOG_DEBUG("entities.player.items", "Player::_ApplyItemMods: completed");
}

ScalingStatDistributionEntry const* Player::GetScalingStatDistributionFor(ItemTemplate const& itemTemplate) const
{
    if (!itemTemplate.ScalingStatDistribution)
        return nullptr;

    return sScalingStatDistributionStore.LookupEntry(itemTemplate.ScalingStatDistribution);
}

ScalingStatValuesEntry const* Player::GetScalingStatValuesFor(ItemTemplate const& itemTemplate) const
{
    if (!itemTemplate.ScalingStatValue)
        return nullptr;

    ScalingStatDistributionEntry const* ssd = GetScalingStatDistributionFor(itemTemplate);
    if (!ssd)
        return nullptr;

    // req. check at equip, but allow use for extended range if range limit max level, set proper level
    uint32 const ssd_level = std::min(uint32(GetLevel()), ssd->MaxLevel);
    return sScalingStatValuesStore.LookupEntry(ssd_level);
}

void Player::_ApplyItemBonuses(ItemTemplate const* proto, uint8 slot, bool apply, bool only_level_scale /*= false*/)
{
    if (slot >= INVENTORY_SLOT_BAG_END || !proto)
        return;

    ScalingStatDistributionEntry const* ssd = GetScalingStatDistributionFor(*proto);
    ScalingStatValuesEntry const* ssv = GetScalingStatValuesFor(*proto);
    if (only_level_scale && (!ssd || !ssv))
        return;

    for (uint8 i = 0; i < MAX_ITEM_PROTO_STATS; ++i)
    {
        uint32 statType = 0;
        int32  val = 0;
        // If set ScalingStatDistribution need get stats and values from it
        if (ssd && ssv)
        {
            if (ssd->StatMod[i] < 0)
                continue;
            statType = ssd->StatMod[i];
            val = (ssv->getssdMultiplier(proto->ScalingStatValue) * ssd->Modifier[i]) / 10000;
        }
        else
        {
            if (i >= proto->StatsCount)
                continue;
            statType = proto->ItemStat[i].ItemStatType;
            val = proto->ItemStat[i].ItemStatValue;
        }

        if (val == 0)
            continue;

        switch (statType)
        {
            case ITEM_MOD_MANA:
                HandleStatFlatModifier(UNIT_MOD_MANA, BASE_VALUE, float(val), apply);
                break;
            case ITEM_MOD_HEALTH:                           // modify HP
                HandleStatFlatModifier(UNIT_MOD_HEALTH, BASE_VALUE, float(val), apply);
                break;
            case ITEM_MOD_AGILITY:                          // modify agility
                HandleStatFlatModifier(UNIT_MOD_STAT_AGILITY, BASE_VALUE, float(val), apply);
                UpdateStatBuffMod(STAT_AGILITY);
                break;
            case ITEM_MOD_STRENGTH:                         //modify strength
                HandleStatFlatModifier(UNIT_MOD_STAT_STRENGTH, BASE_VALUE, float(val), apply);
                UpdateStatBuffMod(STAT_STRENGTH);
                break;
            case ITEM_MOD_INTELLECT:                        //modify intellect
                HandleStatFlatModifier(UNIT_MOD_STAT_INTELLECT, BASE_VALUE, float(val), apply);
                UpdateStatBuffMod(STAT_INTELLECT);
                break;
            case ITEM_MOD_SPIRIT:                           //modify spirit
                HandleStatFlatModifier(UNIT_MOD_STAT_SPIRIT, BASE_VALUE, float(val), apply);
                UpdateStatBuffMod(STAT_SPIRIT);
                break;
            case ITEM_MOD_STAMINA:                          //modify stamina
                HandleStatFlatModifier(UNIT_MOD_STAT_STAMINA, BASE_VALUE, float(val), apply);
                UpdateStatBuffMod(STAT_STAMINA);
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
            case ITEM_MOD_HIT_TAKEN_MELEE_RATING:
                ApplyRatingMod(CR_HIT_TAKEN_MELEE, int32(val), apply);
                break;
            case ITEM_MOD_HIT_TAKEN_RANGED_RATING:
                ApplyRatingMod(CR_HIT_TAKEN_RANGED, int32(val), apply);
                break;
            case ITEM_MOD_HIT_TAKEN_SPELL_RATING:
                ApplyRatingMod(CR_HIT_TAKEN_SPELL, int32(val), apply);
                break;
            case ITEM_MOD_CRIT_TAKEN_MELEE_RATING:
                ApplyRatingMod(CR_CRIT_TAKEN_MELEE, int32(val), apply);
                break;
            case ITEM_MOD_CRIT_TAKEN_RANGED_RATING:
                ApplyRatingMod(CR_CRIT_TAKEN_RANGED, int32(val), apply);
                break;
            case ITEM_MOD_CRIT_TAKEN_SPELL_RATING:
                ApplyRatingMod(CR_CRIT_TAKEN_SPELL, int32(val), apply);
                break;
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
            case ITEM_MOD_HIT_TAKEN_RATING:
                ApplyRatingMod(CR_HIT_TAKEN_MELEE, int32(val), apply);
                ApplyRatingMod(CR_HIT_TAKEN_RANGED, int32(val), apply);
                ApplyRatingMod(CR_HIT_TAKEN_SPELL, int32(val), apply);
                break;
            case ITEM_MOD_CRIT_TAKEN_RATING:
                ApplyRatingMod(CR_CRIT_TAKEN_MELEE, int32(val), apply);
                ApplyRatingMod(CR_CRIT_TAKEN_RANGED, int32(val), apply);
                ApplyRatingMod(CR_CRIT_TAKEN_SPELL, int32(val), apply);
                break;
            case ITEM_MOD_RESILIENCE_RATING:
                ApplyRatingMod(CR_CRIT_TAKEN_MELEE, int32(val), apply);
                ApplyRatingMod(CR_CRIT_TAKEN_RANGED, int32(val), apply);
                ApplyRatingMod(CR_CRIT_TAKEN_SPELL, int32(val), apply);
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
                HandleStatFlatModifier(UNIT_MOD_ATTACK_POWER, TOTAL_VALUE, float(val), apply);
                HandleStatFlatModifier(UNIT_MOD_ATTACK_POWER_RANGED, TOTAL_VALUE, float(val), apply);
                break;
            case ITEM_MOD_RANGED_ATTACK_POWER:
                HandleStatFlatModifier(UNIT_MOD_ATTACK_POWER_RANGED, TOTAL_VALUE, float(val), apply);
                break;
//            case ITEM_MOD_FERAL_ATTACK_POWER:
//                ApplyFeralAPBonus(int32(val), apply);
//                break;
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
            case ITEM_MOD_BLOCK_VALUE:
                HandleBaseModFlatValue(SHIELD_BLOCK_VALUE, float(val), apply);
                break;
            // deprecated item mods
            case ITEM_MOD_SPELL_HEALING_DONE:
            case ITEM_MOD_SPELL_DAMAGE_DONE:
                break;
        }
    }

    // Apply Spell Power from ScalingStatValue if set
    if (ssv)
        if (int32 spellbonus = ssv->getSpellBonus(proto->ScalingStatValue))
            ApplySpellPowerBonus(spellbonus, apply);

    // If set ScalingStatValue armor get it or use item armor
    uint32 armor = proto->Armor;
    if (ssv)
    {
        if (uint32 ssvarmor = ssv->getArmorMod(proto->ScalingStatValue))
            armor = ssvarmor;
    }
    else if (armor && proto->ArmorDamageModifier)
        armor -= uint32(proto->ArmorDamageModifier);

    if (armor)
    {
        UnitModifierFlatType modType = TOTAL_VALUE;
        if (proto->Class == ITEM_CLASS_ARMOR)
        {
            switch (proto->SubClass)
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
        HandleStatFlatModifier(UNIT_MOD_ARMOR, modType, float(armor), apply);
    }

    // Add armor bonus from ArmorDamageModifier if > 0
    if (proto->ArmorDamageModifier > 0)
        HandleStatFlatModifier(UNIT_MOD_ARMOR, TOTAL_VALUE, float(proto->ArmorDamageModifier), apply);

    if (proto->Block)
        HandleBaseModFlatValue(SHIELD_BLOCK_VALUE, float(proto->Block), apply);

    if (proto->HolyRes)
        HandleStatFlatModifier(UNIT_MOD_RESISTANCE_HOLY, BASE_VALUE, float(proto->HolyRes), apply);

    if (proto->FireRes)
        HandleStatFlatModifier(UNIT_MOD_RESISTANCE_FIRE, BASE_VALUE, float(proto->FireRes), apply);

    if (proto->NatureRes)
        HandleStatFlatModifier(UNIT_MOD_RESISTANCE_NATURE, BASE_VALUE, float(proto->NatureRes), apply);

    if (proto->FrostRes)
        HandleStatFlatModifier(UNIT_MOD_RESISTANCE_FROST, BASE_VALUE, float(proto->FrostRes), apply);

    if (proto->ShadowRes)
        HandleStatFlatModifier(UNIT_MOD_RESISTANCE_SHADOW, BASE_VALUE, float(proto->ShadowRes), apply);

    if (proto->ArcaneRes)
        HandleStatFlatModifier(UNIT_MOD_RESISTANCE_ARCANE, BASE_VALUE, float(proto->ArcaneRes), apply);

    WeaponAttackType attType = Player::GetAttackBySlot(slot);
    if (attType != MAX_ATTACK)
        _ApplyWeaponDamage(slot, proto, apply);

    // Druids get feral AP bonus from weapon dps (also use DPS from ScalingStatValue)
    if (GetClass() == CLASS_DRUID)
    {
        int32 dpsMod = 0;
        int32 feral_bonus = 0;
        if (ssv)
        {
            dpsMod = ssv->getDPSMod(proto->ScalingStatValue);
            feral_bonus += ssv->getFeralBonus(proto->ScalingStatValue);
        }

        feral_bonus += proto->getFeralBonus(dpsMod);
        if (feral_bonus)
            ApplyFeralAPBonus(feral_bonus, apply);
    }
}

void Player::_ApplyWeaponDamage(uint8 slot, ItemTemplate const* proto, bool apply)
{
    WeaponAttackType attType = Player::GetAttackBySlot(slot);
    if (!IsInFeralForm() && apply && !CanUseAttackType(attType))
        return;

    ScalingStatValuesEntry const* ssv = GetScalingStatValuesFor(*proto);
    for (uint8 i = 0; i < MAX_ITEM_PROTO_DAMAGES; ++i)
    {
        float minDamage = proto->Damage[i].DamageMin;
        float maxDamage = proto->Damage[i].DamageMax;

        // If set dpsMod in ScalingStatValue use it for min (70% from average), max (130% from average) damage
        if (ssv && i == 0) // scaling stats only for first damage
        {
            int32 extraDPS = ssv->getDPSMod(proto->ScalingStatValue);
            if (extraDPS)
            {
                float average = extraDPS * proto->Delay / 1000.0f;
                minDamage = 0.7f * average;
                maxDamage = 1.3f * average;
            }
        }

        if (apply)
        {
            if (minDamage > 0.f)
                SetBaseWeaponDamage(attType, MINDAMAGE, minDamage, i);

            if (maxDamage > 0.f)
                SetBaseWeaponDamage(attType, MAXDAMAGE, maxDamage, i);
        }
    }

    if (!apply)
    {
        for (uint8 i = 0; i < MAX_ITEM_PROTO_DAMAGES; ++i)
        {
            SetBaseWeaponDamage(attType, MINDAMAGE, 0.f, i);
            SetBaseWeaponDamage(attType, MAXDAMAGE, 0.f, i);
        }

        if (attType == BASE_ATTACK)
        {
            SetBaseWeaponDamage(BASE_ATTACK, MINDAMAGE, BASE_MINDAMAGE);
            SetBaseWeaponDamage(BASE_ATTACK, MAXDAMAGE, BASE_MAXDAMAGE);
        }
    }

    if (proto->Delay && !IsInFeralForm())
        SetAttackTime(attType, apply ? proto->Delay : BASE_ATTACK_TIME);

    // No need to modify any physical damage for ferals as it is calculated from stats only
    if (IsInFeralForm())
        return;

    if (CanModifyStats() && (GetWeaponDamageRange(attType, MAXDAMAGE) || proto->Delay))
        UpdateDamagePhysical(attType);
}

SpellSchoolMask Player::GetMeleeDamageSchoolMask(WeaponAttackType attackType /*= BASE_ATTACK*/, uint8 damageIndex /*= 0*/) const
{
    if (Item const* weapon = GetWeaponForAttack(attackType, true))
        return SpellSchoolMask(1 << weapon->GetTemplate()->Damage[damageIndex].DamageType);

    return SPELL_SCHOOL_MASK_NORMAL;
}

void Player::CastAllObtainSpells()
{
    for (uint8 slot = INVENTORY_SLOT_ITEM_START; slot < INVENTORY_SLOT_ITEM_END; ++slot)
        if (Item* item = GetItemByPos(INVENTORY_SLOT_BAG_0, slot))
            ApplyItemObtainSpells(item, true);

    for (uint8 i = INVENTORY_SLOT_BAG_START; i < INVENTORY_SLOT_BAG_END; ++i)
    {
        Bag* bag = GetBagByPos(i);
        if (!bag)
            continue;

        for (uint32 slot = 0; slot < bag->GetBagSize(); ++slot)
            if (Item* item = bag->GetItemByPos(slot))
                ApplyItemObtainSpells(item, true);
    }
}

void Player::ApplyItemObtainSpells(Item* item, bool apply)
{
    ItemTemplate const* itemTemplate = item->GetTemplate();
    for (uint8 i = 0; i < MAX_ITEM_PROTO_SPELLS; ++i)
    {
        if (itemTemplate->Spells[i].SpellTrigger != ITEM_SPELLTRIGGER_ON_NO_DELAY_USE) // On obtain trigger
            continue;

        int32 const spellId = itemTemplate->Spells[i].SpellId;
        if (spellId <= 0)
            continue;

        if (apply)
        {
            if (!HasAura(spellId))
                CastSpell(this, spellId, item);
        }
        else
            RemoveAurasDueToSpell(spellId);
    }
}

// this one rechecks weapon auras and stores them in BaseModGroup container
// needed for things like axe specialization applying only to axe weapons in case of dual-wield
void Player::UpdateWeaponDependentCritAuras(WeaponAttackType attackType)
{
    BaseModGroup modGroup;
    switch (attackType)
    {
        case BASE_ATTACK:
            modGroup = CRIT_PERCENTAGE;
            break;
        case OFF_ATTACK:
            modGroup = OFFHAND_CRIT_PERCENTAGE;
            break;
        case RANGED_ATTACK:
            modGroup = RANGED_CRIT_PERCENTAGE;
            break;
        default:
            ABORT();
            break;
    }

    float amount = 0.0f;
    amount += GetTotalAuraModifier(SPELL_AURA_MOD_WEAPON_CRIT_PERCENT, std::bind(&Unit::CheckAttackFitToAuraRequirement, this, attackType, std::placeholders::_1));

    // these auras don't have item requirement (only Combat Expertise in 3.3.5a)
    amount += GetTotalAuraModifier(SPELL_AURA_MOD_CRIT_PCT);

    SetBaseModFlatValue(modGroup, amount);
}

void Player::UpdateAllWeaponDependentCritAuras()
{
    for (uint8 i = BASE_ATTACK; i < MAX_ATTACK; ++i)
        UpdateWeaponDependentCritAuras(WeaponAttackType(i));
}

void Player::UpdateWeaponDependentAuras(WeaponAttackType attackType)
{
    UpdateWeaponDependentCritAuras(attackType);
    UpdateDamageDoneMods(attackType);
    UpdateDamagePctDoneMods(attackType);
}

void Player::ApplyItemDependentAuras(Item* item, bool apply)
{
    if (apply)
    {
        PlayerSpellMap const& spells = GetSpellMap();
        for (auto itr = spells.begin(); itr != spells.end(); ++itr)
        {
            if (itr->second->state == PLAYERSPELL_REMOVED || itr->second->disabled)
                continue;

            SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(itr->first);
            if (!spellInfo || !spellInfo->IsPassive() || spellInfo->EquippedItemClass < 0)
                continue;

            if (!HasAura(itr->first) && HasItemFitToSpellRequirements(spellInfo))
                AddAura(itr->first, this);  // no SMSG_SPELL_GO in sniff found
        }
    }
    else
        RemoveItemDependentAurasAndCasts(item);
}

bool Player::CheckAttackFitToAuraRequirement(WeaponAttackType attackType, AuraEffect const* aurEff) const
{
    SpellInfo const* spellInfo = aurEff->GetSpellInfo();
    if (spellInfo->EquippedItemClass == -1)
        return true;

    Item* item = GetWeaponForAttack(attackType, true);
    if (!item || !item->IsFitToSpellRequirements(spellInfo))
        return false;

    return true;
}

void Player::ApplyItemEquipSpell(Item* item, bool apply, bool form_change)
{
    if (!item)
        return;

    ItemTemplate const* proto = item->GetTemplate();
    if (!proto)
        return;

    for (uint8 i = 0; i < MAX_ITEM_PROTO_SPELLS; ++i)
    {
        _Spell const& spellData = proto->Spells[i];

        // no spell
        if (spellData.SpellId <= 0)
            continue;

        // wrong triggering type
        if (apply && spellData.SpellTrigger != ITEM_SPELLTRIGGER_ON_EQUIP)
            continue;

        // check if it is valid spell
        SpellInfo const* spellproto = sSpellMgr->GetSpellInfo(spellData.SpellId);
        if (!spellproto)
            continue;

        ApplyEquipSpell(spellproto, item, apply, form_change);
    }
}

void Player::ApplyEquipSpell(SpellInfo const* spellInfo, Item* item, bool apply, bool form_change)
{
    if (apply)
    {
        // Cannot be used in this stance/form
        if (spellInfo->CheckShapeshift(GetShapeshiftForm()) != SPELL_CAST_OK)
            return;

        if (form_change)                                    // check aura active state from other form
        {
            AuraApplicationMapBounds range = GetAppliedAuras().equal_range(spellInfo->Id);
            for (AuraApplicationMap::const_iterator itr = range.first; itr != range.second; ++itr)
                if (!item || itr->second->GetBase()->GetCastItemGUID() == item->GetGUID())
                    return;
        }

        TC_LOG_DEBUG("entities.player", "Player::ApplyEquipSpell: Player '%s' (%s) cast %s equip spell (ID: %i)",
            GetName().c_str(), GetGUID().ToString().c_str(), (item ? "item" : "itemset"), spellInfo->Id);

        CastSpell(this, spellInfo->Id, item);
    }
    else
    {
        if (form_change)                                     // check aura compatibility
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
        if (m_items[i] && !m_items[i]->IsBroken() && CanUseAttackType(GetAttackBySlot(i)))
        {
            ApplyItemEquipSpell(m_items[i], false, true);     // remove spells that not fit to form
            ApplyItemEquipSpell(m_items[i], true, true);      // add spells that fit form but not active
        }
    }

    // item set bonuses not dependent from item broken state
    for (size_t setindex = 0; setindex < ItemSetEff.size(); ++setindex)
    {
        ItemSetEffect* eff = ItemSetEff[setindex];
        if (!eff)
            continue;

        for (uint32 y = 0; y < MAX_ITEM_SET_SPELLS; ++y)
        {
            SpellInfo const* spellInfo = eff->spells[y];
            if (!spellInfo)
                continue;

            ApplyEquipSpell(spellInfo, nullptr, false, true);       // remove spells that not fit to form
            ApplyEquipSpell(spellInfo, nullptr, true, true);        // add spells that fit form but not active
        }
    }
}

void Player::CastItemCombatSpell(DamageInfo const& damageInfo)
{
    Unit* target = damageInfo.GetVictim();
    if (!target || !target->IsAlive() || target == this)
        return;

    for (uint8 i = EQUIPMENT_SLOT_START; i < EQUIPMENT_SLOT_END; ++i)
    {
        // If usable, try to cast item spell
        if (Item* item = GetItemByPos(INVENTORY_SLOT_BAG_0, i))
        {
            if (!item->IsBroken() && CanUseAttackType(damageInfo.GetAttackType()))
            {
                if (ItemTemplate const* proto = item->GetTemplate())
                {
                    // Additional check for weapons
                    if (proto->Class == ITEM_CLASS_WEAPON)
                    {
                        // offhand item cannot proc from main hand hit etc
                        EquipmentSlots slot;
                        switch (damageInfo.GetAttackType())
                        {
                            case BASE_ATTACK:
                                slot = EQUIPMENT_SLOT_MAINHAND;
                                break;
                            case OFF_ATTACK:
                                slot = EQUIPMENT_SLOT_OFFHAND;
                                break;
                            case RANGED_ATTACK:
                                slot = EQUIPMENT_SLOT_RANGED;
                                break;
                            default:
                                slot = EQUIPMENT_SLOT_END;
                                break;
                        }
                        if (slot != i)
                            continue;
                        // Check if item is useable (forms or disarm)
                        if (damageInfo.GetAttackType() == BASE_ATTACK)
                            if (!IsUseEquipedWeapon(true) && !IsInFeralForm())
                                continue;
                    }

                    CastItemCombatSpell(damageInfo, item, proto);
                }
            }
        }
    }
}

void Player::CastItemCombatSpell(DamageInfo const& damageInfo, Item* item, ItemTemplate const* proto)
{
    // Can do effect if any damage done to target
    // for done procs allow normal + critical + absorbs by default
    bool canTrigger = (damageInfo.GetHitMask() & (PROC_HIT_NORMAL | PROC_HIT_CRITICAL | PROC_HIT_ABSORB)) != 0;
    if (canTrigger)
    {
        for (uint8 i = 0; i < MAX_ITEM_PROTO_SPELLS; ++i)
        {
            _Spell const& spellData = proto->Spells[i];

            // no spell
            if (spellData.SpellId <= 0)
                continue;

            // wrong triggering type
            if (spellData.SpellTrigger != ITEM_SPELLTRIGGER_CHANCE_ON_HIT)
                continue;

            SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(spellData.SpellId);
            if (!spellInfo)
            {
                TC_LOG_ERROR("entities.player.items", "Player::CastItemCombatSpell: Player '%s' (%s) cast unknown item spell (ID: %i)",
                    GetName().c_str(), GetGUID().ToString().c_str(), spellData.SpellId);
                continue;
            }

            // not allow proc extra attack spell at extra attack
            if (m_extraAttacks && spellInfo->HasEffect(SPELL_EFFECT_ADD_EXTRA_ATTACKS))
                return;

            float chance = (float)spellInfo->ProcChance;

            if (spellData.SpellPPMRate)
            {
                uint32 WeaponSpeed = GetAttackTime(damageInfo.GetAttackType());
                chance = GetPPMProcChance(WeaponSpeed, spellData.SpellPPMRate, spellInfo);
            }
            else if (chance > 100.0f)
                chance = GetWeaponProcChance();

            if (roll_chance_f(chance) && sScriptMgr->OnCastItemCombatSpell(this, damageInfo.GetVictim(), spellInfo, item))
                CastSpell(damageInfo.GetVictim(), spellInfo->Id, item);
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
            if (pEnchant->type[s] != ITEM_ENCHANTMENT_TYPE_COMBAT_SPELL)
                continue;

            SpellEnchantProcEntry const* entry = sSpellMgr->GetSpellEnchantProcEvent(enchant_id);
            if (entry && entry->HitMask)
            {
                // Check hit/crit/dodge/parry requirement
                if ((entry->HitMask & damageInfo.GetHitMask()) == 0)
                    continue;
            }
            else
            {
                // Can do effect if any damage done to target
                // for done procs allow normal + critical + absorbs by default
                if (!canTrigger)
                    continue;
            }

            // check if enchant procs only on white hits
            if (entry && (entry->AttributesMask & ENCHANT_PROC_ATTR_WHITE_HIT) && damageInfo.GetSpellInfo())
                continue;

            SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(pEnchant->spellid[s]);
            if (!spellInfo)
            {
                TC_LOG_ERROR("entities.player.items", "Player::CastItemCombatSpell: Player '%s' (%s) cast unknown spell (EnchantID: %u, SpellID: %i), ignoring",
                    GetName().c_str(), GetGUID().ToString().c_str(), pEnchant->ID, pEnchant->spellid[s]);
                continue;
            }

            float chance = pEnchant->amount[s] != 0 ? float(pEnchant->amount[s]) : GetWeaponProcChance();
            if (entry)
            {
                if (entry->ProcsPerMinute)
                    chance = GetPPMProcChance(proto->Delay, entry->ProcsPerMinute, spellInfo);
                else if (entry->Chance)
                    chance = entry->Chance;
            }

            // Apply spell mods
            ApplySpellMod(pEnchant->spellid[s], SPELLMOD_CHANCE_OF_SUCCESS, chance);

            // Shiv has 100% chance to apply the poison
            if (FindCurrentSpellBySpellId(5938) && e_slot == TEMP_ENCHANTMENT_SLOT)
                chance = 100.0f;

            if (roll_chance_f(chance))
            {
                Unit* target = spellInfo->IsPositive() ? this : damageInfo.GetVictim();

                CastSpellExtraArgs args(item);
                // reduce effect values if enchant is limited
                if (entry && (entry->AttributesMask & ENCHANT_PROC_ATTR_LIMIT_60) && target->GetLevel() > 60)
                {
                    int32 const lvlDifference = target->GetLevel() - 60;
                    int32 const lvlPenaltyFactor = 4; // 4% lost effectiveness per level

                    int32 const effectPct = std::max(0, 100 - (lvlDifference * lvlPenaltyFactor));

                    for (uint8 i = 0; i < MAX_SPELL_EFFECTS; ++i)
                    {
                        if (spellInfo->Effects[i].IsEffect())
                            args.AddSpellMod(static_cast<SpellValueMod>(SPELLVALUE_BASE_POINT0 + i), CalculatePct(spellInfo->Effects[i].CalcValue(this), effectPct));
                    }
                }
                CastSpell(target, spellInfo->Id, args);
            }
        }
    }
}

void Player::CastItemUseSpell(Item* item, SpellCastTargets const& targets, uint8 cast_count, uint32 glyphIndex)
{
    ItemTemplate const* proto = item->GetTemplate();
    // special learning case
    if (proto->Spells[0].SpellId == 483 || proto->Spells[0].SpellId == 55884)
    {
        uint32 learn_spell_id = proto->Spells[0].SpellId;
        uint32 learning_spell_id = proto->Spells[1].SpellId;

        SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(learn_spell_id);
        if (!spellInfo)
        {
            TC_LOG_ERROR("entities.player", "Player::CastItemUseSpell: Item (Entry: %u) has wrong spell id %u, ignoring.", proto->ItemId, learn_spell_id);
            SendEquipError(EQUIP_ERR_NONE, item, nullptr);
            return;
        }

        Spell* spell = new Spell(this, spellInfo, TRIGGERED_NONE);
        spell->m_CastItem = item;
        spell->m_cast_count = cast_count;                   //set count of casts
        spell->SetSpellValue(SPELLVALUE_BASE_POINT0, learning_spell_id);
        spell->prepare(targets);
        return;
    }

    // item spells cast at use
    for (uint8 i = 0; i < MAX_ITEM_PROTO_SPELLS; ++i)
    {
        _Spell const& spellData = proto->Spells[i];

        // no spell
        if (spellData.SpellId <= 0)
            continue;

        // wrong triggering type
        if (spellData.SpellTrigger != ITEM_SPELLTRIGGER_ON_USE)
            continue;

        SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(spellData.SpellId);
        if (!spellInfo)
        {
            TC_LOG_ERROR("entities.player", "Player::CastItemUseSpell: Item (Entry: %u) has wrong spell id %u, ignoring", proto->ItemId, spellData.SpellId);
            continue;
        }

        Spell* spell = new Spell(this, spellInfo, TRIGGERED_NONE);
        spell->m_CastItem = item;
        spell->m_cast_count = cast_count;                   // set count of casts
        spell->m_glyphIndex = glyphIndex;                   // glyph index
        spell->prepare(targets);
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
            if (pEnchant->type[s] != ITEM_ENCHANTMENT_TYPE_USE_SPELL)
                continue;

            SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(pEnchant->spellid[s]);
            if (!spellInfo)
            {
                TC_LOG_ERROR("entities.player", "Player::CastItemUseSpell: Enchant %i, cast unknown spell %i", pEnchant->ID, pEnchant->spellid[s]);
                continue;
            }

            Spell* spell = new Spell(this, spellInfo, TRIGGERED_NONE);
            spell->m_CastItem = item;
            spell->m_cast_count = cast_count;               // set count of casts
            spell->m_glyphIndex = glyphIndex;               // glyph index
            spell->prepare(targets);
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
            if (proto->ItemSet)
                RemoveItemsSetItem(this, proto);

            if (m_items[i]->IsBroken() || !CanUseAttackType(GetAttackBySlot(i)))
                continue;

            ApplyItemEquipSpell(m_items[i], false);
            ApplyEnchantment(m_items[i], false);
        }
    }

    for (uint8 i = 0; i < INVENTORY_SLOT_BAG_END; ++i)
    {
        if (m_items[i])
        {
            if (m_items[i]->IsBroken() || !CanUseAttackType(GetAttackBySlot(i)))
                continue;
            ItemTemplate const* proto = m_items[i]->GetTemplate();
            if (!proto)
                continue;

            ApplyItemDependentAuras(m_items[i], false);
            _ApplyItemBonuses(proto, i, false);

            if (i == EQUIPMENT_SLOT_RANGED)
                _ApplyAmmoBonuses();
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
            if (m_items[i]->IsBroken() || !CanUseAttackType(GetAttackBySlot(i)))
                continue;

            ItemTemplate const* proto = m_items[i]->GetTemplate();
            if (!proto)
                continue;

            ApplyItemDependentAuras(m_items[i], true);
            _ApplyItemBonuses(proto, i, true);

            WeaponAttackType const attackType = Player::GetAttackBySlot(i);
            if (attackType != MAX_ATTACK)
                UpdateWeaponDependentAuras(attackType);

            if (i == EQUIPMENT_SLOT_RANGED)
                _ApplyAmmoBonuses();
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
            if (proto->ItemSet)
                AddItemsSetItem(this, m_items[i]);

            if (m_items[i]->IsBroken() || !CanUseAttackType(GetAttackBySlot(i)))
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
            if (m_items[i]->IsBroken() || !CanUseAttackType(GetAttackBySlot(i)))
                continue;

            ItemTemplate const* proto = m_items[i]->GetTemplate();
            if (!proto)
                continue;

            _ApplyItemBonuses(proto, i, apply, true);
        }
    }
}

void Player::_ApplyAmmoBonuses()
{
    // check ammo
    uint32 ammo_id = GetUInt32Value(PLAYER_AMMO_ID);
    if (!ammo_id)
        return;

    float currentAmmoDPS;

    ItemTemplate const* ammo_proto = sObjectMgr->GetItemTemplate(ammo_id);
    if (!ammo_proto || ammo_proto->Class != ITEM_CLASS_PROJECTILE || !CheckAmmoCompatibility(ammo_proto))
        currentAmmoDPS = 0.0f;
    else
        currentAmmoDPS = (ammo_proto->Damage[0].DamageMin + ammo_proto->Damage[0].DamageMax) / 2;

    if (currentAmmoDPS == GetAmmoDPS())
        return;

    m_ammoDPS = currentAmmoDPS;

    if (CanModifyStats())
        UpdateDamagePhysical(RANGED_ATTACK);
}

bool Player::CheckAmmoCompatibility(ItemTemplate const* ammo_proto) const
{
    if (!ammo_proto)
        return false;

    // check ranged weapon
    Item* weapon = GetWeaponForAttack(RANGED_ATTACK);
    if (!weapon  || weapon->IsBroken())
        return false;

    ItemTemplate const* weapon_proto = weapon->GetTemplate();
    if (!weapon_proto || weapon_proto->Class != ITEM_CLASS_WEAPON)
        return false;

    // check ammo ws. weapon compatibility
    switch (weapon_proto->SubClass)
    {
        case ITEM_SUBCLASS_WEAPON_BOW:
        case ITEM_SUBCLASS_WEAPON_CROSSBOW:
            if (ammo_proto->SubClass != ITEM_SUBCLASS_ARROW)
                return false;
            break;
        case ITEM_SUBCLASS_WEAPON_GUN:
            if (ammo_proto->SubClass != ITEM_SUBCLASS_BULLET)
                return false;
            break;
        default:
            return false;
    }

    return true;
}

/*  If in a battleground a player dies, and an enemy removes the insignia, the player's bones is lootable
    Called by remove insignia spell effect    */
void Player::RemovedInsignia(Player* looterPlr)
{
    // If player is not in battleground and not in wintergrasp
    if (!GetBattlegroundId() && GetZoneId() != AREA_WINTERGRASP)
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
    bones->loot.gold = GetLevel();
    bones->lootRecipient = looterPlr;
    looterPlr->SendLoot(bones->GetGUID(), LOOT_INSIGNIA);
}

void Player::SendLootRelease(ObjectGuid guid) const
{
    WorldPacket data(SMSG_LOOT_RELEASE_RESPONSE, (8+1));
    data << uint64(guid) << uint8(1);
    SendDirectMessage(&data);
}

void Player::SendLoot(ObjectGuid guid, LootType loot_type)
{
    if (ObjectGuid lguid = GetLootGUID())
        m_session->DoLootRelease(lguid);

    Loot* loot;
    PermissionTypes permission = ALL_PERMISSION;

    TC_LOG_DEBUG("loot", "Player::SendLoot: Player: '%s' (%s), Loot: %s",
        GetName().c_str(), GetGUID().ToString().c_str(), guid.ToString().c_str());
    if (guid.IsGameObject())
    {
        GameObject* go = GetMap()->GetGameObject(guid);
        auto shouldLootRelease = [this](GameObject* go, LootType lootType) -> bool
        {
            // not check distance for GO in case owned GO (fishing bobber case, for example)
            // And permit out of range GO with no owner in case fishing hole
            if (!go)
                return true;

            if (lootType == LOOT_SKINNING)
            {
                // Disarm Trap
                if (!go->IsWithinDistInMap(this, 20.f))
                    return true;
            }
            else
            {
                if (lootType != LOOT_FISHINGHOLE && ((lootType != LOOT_FISHING && lootType != LOOT_FISHING_JUNK) || go->GetOwnerGUID() != GetGUID()) && !go->IsWithinDistInMap(this))
                    return true;

                if (lootType == LOOT_CORPSE && go->GetRespawnTime() && go->isSpawnedByDefault())
                    return true;
            }

            return false;
        };

        if (shouldLootRelease(go, loot_type))
        {
            SendLootRelease(guid);
            return;
        }

        loot = &go->loot;

        // loot was generated and respawntime has passed since then, allow to recreate loot
        // to avoid bugs, this rule covers spawned gameobjects only
        // Don't allow to regenerate chest loot inside instances and raids, to avoid exploits with duplicate boss loot being given for some encounters
        if (go->isSpawnedByDefault() && go->getLootState() == GO_ACTIVATED && !go->loot.isLooted() && !go->GetMap()->Instanceable() && go->GetLootGenerationTime() + go->GetRespawnDelay() < GameTime::GetGameTime())
            go->SetLootState(GO_READY);

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
                bool groupRules = (group && go->GetGOInfo()->type == GAMEOBJECT_TYPE_CHEST && go->GetGOInfo()->chest.groupLootRules);

                // check current RR player and get next if necessary
                if (groupRules)
                    group->UpdateLooterGuid(go, true);

                loot->FillLoot(lootid, LootTemplates_Gameobject, this, !groupRules, false, go->GetLootMode());
                go->SetLootGenerationTime();

                // get next RR player (for next loot)
                if (groupRules && !go->loot.empty())
                    group->UpdateLooterGuid(go);
            }

            if (go->GetLootMode() > 0)
                if (GameObjectTemplateAddon const* addon = go->GetTemplateAddon())
                    loot->generateMoneyLoot(addon->Mingold, addon->Maxgold);

            if (loot_type == LOOT_FISHING)
                go->getFishLoot(loot, this);
            else if (loot_type == LOOT_FISHING_JUNK)
                go->getFishLootJunk(loot, this);

            if (go->GetGOInfo()->type == GAMEOBJECT_TYPE_CHEST && go->GetGOInfo()->chest.groupLootRules)
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

        // Store container id
        loot->containerID = item->GetGUID().GetCounter();

        // If item doesn't already have loot, attempt to load it. If that
        // fails then this is first time opening, generate loot
        if (!item->m_lootGenerated && !sLootItemStorage->LoadStoredLoot(item, this))
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
                        sLootItemStorage->AddNewStoredLoot(loot, this);

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

        if (loot->loot_type == LOOT_NONE)
        {
            uint32 pLevel = bones->loot.gold;
            bones->loot.clear();

            // For AV Achievement
            if (Battleground* bg = GetBattleground())
            {
                if (bg->GetTypeID(true) == BATTLEGROUND_AV)
                    loot->FillLoot(PLAYER_CORPSE_LOOT_ENTRY, LootTemplates_Creature, this, true);
            }
            // For wintergrasp Quests
            else if (GetZoneId() == AREA_WINTERGRASP)
                loot->FillLoot(PLAYER_CORPSE_LOOT_ENTRY, LootTemplates_Creature, this, true);

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
                    const uint32 a = urand(0, creature->GetLevel() / 2);
                    const uint32 b = urand(0, GetLevel() / 2);
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
            // exploit fix
            if (!creature->HasFlag(UNIT_DYNAMIC_FLAGS, UNIT_DYNFLAG_LOOTABLE))
            {
                SendLootError(guid, LOOT_ERROR_DIDNT_KILL);
                return;
            }

            // the player whose group may loot the corpse
            Player* recipient = creature->GetLootRecipient();
            Group* recipientGroup = creature->GetLootRecipientGroup();
            if (!recipient && !recipientGroup)
            {
                SendLootError(guid, LOOT_ERROR_DIDNT_KILL);
                return;
            }

            if (loot->loot_type == LOOT_NONE)
            {
                // for creature, loot is filled when creature is killed.
                if (Group* group = creature->GetLootRecipientGroup())
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
                permission = creature->GetLootRecipientGUID() == GetGUID() ? OWNER_PERMISSION : NONE_PERMISSION;
            }
            else if (loot_type == LOOT_SKINNING)
            {
                loot->clear();
                loot->FillLoot(creature->GetCreatureTemplate()->SkinLootId, LootTemplates_Skinning, this, true);
                permission = OWNER_PERMISSION;

                // Set new loot recipient
                creature->SetLootRecipient(this, false);
            }
            // set group rights only for loot_type != LOOT_SKINNING
            else
            {
                if (creature->GetLootRecipientGroup())
                {
                    Group* group = GetGroup();
                    if (group == creature->GetLootRecipientGroup())
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
                else if (creature->GetLootRecipient() == this)
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
        SetLootGUID(guid);

        WorldPacket data(SMSG_LOOT_RESPONSE, (9 + 50));           // we guess size
        data << uint64(guid);
        data << uint8(loot_type);
        data << LootView(*loot, this, permission);
        SendDirectMessage(&data);

        // add 'this' player as one of the players that are looting 'loot'
        loot->AddLooter(GetGUID());

        if (loot_type == LOOT_CORPSE && !guid.IsItem())
            SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_LOOTING);
    }
    else
        SendLootError(GetLootGUID(), LOOT_ERROR_DIDNT_KILL);
}

void Player::SendLootError(ObjectGuid guid, LootError error) const
{
    WorldPacket data(SMSG_LOOT_RESPONSE, 10);
    data << uint64(guid);
    data << uint8(LOOT_NONE);
    data << uint8(error);
    SendDirectMessage(&data);
}

void Player::SendNotifyLootMoneyRemoved() const
{
    WorldPacket data(SMSG_LOOT_CLEAR_MONEY, 0);
    SendDirectMessage(&data);
}

void Player::SendNotifyLootItemRemoved(uint8 lootSlot) const
{
    WorldPacket data(SMSG_LOOT_REMOVED, 1);
    data << uint8(lootSlot);
    SendDirectMessage(&data);
}

void Player::SendUpdateWorldState(uint32 variable, uint32 value) const
{
    WorldPackets::WorldState::UpdateWorldState worldstate;
    worldstate.VariableID = variable;
    worldstate.Value = value;
    SendDirectMessage(worldstate.Write());
}

// TODO - InitWorldStates should NOT always send the same states
//        Some should keep the same value between different zoneIds and areaIds on the same map
void Player::SendInitWorldStates(uint32 zoneId, uint32 areaId)
{
    uint32 mapId = GetMapId();
    Battleground* battleground = GetBattleground();
    OutdoorPvP* outdoorPvP = sOutdoorPvPMgr->GetOutdoorPvPToZoneId(zoneId);
    InstanceScript* instance = GetInstanceScript();
    Battlefield* battlefield = sBattlefieldMgr->GetBattlefieldToZoneId(zoneId);

    TC_LOG_DEBUG("network", "Player::SendInitWorldStates: Sending SMSG_INIT_WORLD_STATES for Map: %u, Zone: %u", mapId, zoneId);

    WorldPackets::WorldState::InitWorldStates packet;
    packet.MapID = mapId;
    packet.ZoneID = zoneId;
    packet.AreaID = areaId;

    packet.Worldstates.emplace_back(2264, 0); // SCOURGE_EVENT_WORLDSTATE_EASTERN_PLAGUELANDS
    packet.Worldstates.emplace_back(2263, 0); // SCOURGE_EVENT_WORLDSTATE_TANARIS
    packet.Worldstates.emplace_back(2262, 0); // SCOURGE_EVENT_WORLDSTATE_BURNING_STEPPES
    packet.Worldstates.emplace_back(2261, 0); // SCOURGE_EVENT_WORLDSTATE_BLASTED_LANDS
    packet.Worldstates.emplace_back(2260, 0); // SCOURGE_EVENT_WORLDSTATE_AZSHARA
    packet.Worldstates.emplace_back(2259, 0); // SCOURGE_EVENT_WORLDSTATE_WINTERSPRING

    // ARENA_SEASON_IN_PROGRESS
    //   7 - arena season in progress
    //   0 - end of season
    packet.Worldstates.emplace_back(3191, sWorld->getBoolConfig(CONFIG_ARENA_SEASON_IN_PROGRESS) ? sWorld->getIntConfig(CONFIG_ARENA_SEASON_ID) : 0);

    // Previous arena season id
    int32 previousArenaSeason = 0;
    if (sWorld->getBoolConfig(CONFIG_ARENA_SEASON_IN_PROGRESS) && sWorld->getIntConfig(CONFIG_ARENA_SEASON_ID) > 0)
        previousArenaSeason = sWorld->getIntConfig(CONFIG_ARENA_SEASON_ID) - 1;
    packet.Worldstates.emplace_back(3901, previousArenaSeason);

    if (mapId == 530) // Outland
    {
        packet.Worldstates.emplace_back(2495, 0);  // NA_UI_OUTLAND_01 "Progress: %2494w"
        packet.Worldstates.emplace_back(2493, 15); // NA_UI_GUARDS_MAX
        packet.Worldstates.emplace_back(2491, 15); // NA_UI_GUARDS_LEFT
    }

    switch (zoneId)
    {
        case 1: // Dun Morogh
        case 11: // Wetlands
        case 12: // Elwynn Forest
        case 38: // Loch Modan
        case 40: // Westfall
        case 51: // Searing Gorge
        case 1519: // Stormwind City
        case 1537: // Ironforge
        case 2257: // Deeprun Tram
        case 3703: // Shattrath City
            break;
        case 139: // Eastern Plaguelands
            if (outdoorPvP && outdoorPvP->GetTypeId() == OUTDOOR_PVP_EP)
                outdoorPvP->FillInitialWorldStates(packet);
            else
            {
                packet.Worldstates.emplace_back(2426, 0);  // GENERAL_WORLDSTATES_01 "Progress: %2427w"
                packet.Worldstates.emplace_back(2327, 0);  // EP_UI_TOWER_COUNT_A
                packet.Worldstates.emplace_back(2328, 0);  // EP_UI_TOWER_COUNT_H
                packet.Worldstates.emplace_back(2427, 50); // GENERAL_WORLDSTATES_02
                packet.Worldstates.emplace_back(2428, 50); // GENERAL_WORLDSTATES_03
                packet.Worldstates.emplace_back(2355, 1);  // EP_CGT_N
                packet.Worldstates.emplace_back(2374, 0);  // EP_CGT_N_A
                packet.Worldstates.emplace_back(2375, 0);  // EP_CGT_N_H
                packet.Worldstates.emplace_back(2376, 0);  // GENERAL_WORLDSTATES_04
                packet.Worldstates.emplace_back(2377, 0);  // GENERAL_WORLDSTATES_05
                packet.Worldstates.emplace_back(2378, 0);  // EP_CGT_A
                packet.Worldstates.emplace_back(2379, 0);  // EP_CGT_H
                packet.Worldstates.emplace_back(2354, 0);  // EP_EWT_A
                packet.Worldstates.emplace_back(2356, 0);  // EP_EWT_H
                packet.Worldstates.emplace_back(2357, 0);  // GENERAL_WORLDSTATES_06
                packet.Worldstates.emplace_back(2358, 0);  // GENERAL_WORLDSTATES_07
                packet.Worldstates.emplace_back(2359, 0);  // EP_EWT_N_A
                packet.Worldstates.emplace_back(2360, 0);  // EP_EWT_N_H
                packet.Worldstates.emplace_back(2361, 1);  // EP_EWT_N
                packet.Worldstates.emplace_back(2352, 1);  // EP_NPT_N
                packet.Worldstates.emplace_back(2362, 0);  // EP_NPT_N_A
                packet.Worldstates.emplace_back(2363, 0);  // GENERAL_WORLDSTATES_08
                packet.Worldstates.emplace_back(2364, 0);  // GENERAL_WORLDSTATES_09
                packet.Worldstates.emplace_back(2365, 0);  // GENERAL_WORLDSTATES_10
                packet.Worldstates.emplace_back(2372, 0);  // EP_NPT_A
                packet.Worldstates.emplace_back(2373, 0);  // EP_NPT_H
                packet.Worldstates.emplace_back(2353, 1);  // EP_PWT_N
                packet.Worldstates.emplace_back(2366, 0);  // EP_PWT_N_A
                //packet.Worldstates.emplace_back(2367, 1); // GENERAL_WORLDSTATES_13 grey horde not in dbc!
                packet.Worldstates.emplace_back(2368, 0);  // GENERAL_WORLDSTATES_11
                packet.Worldstates.emplace_back(2369, 0);  // GENERAL_WORLDSTATES_12
                packet.Worldstates.emplace_back(2370, 0);  // EP_PWT_A
                packet.Worldstates.emplace_back(2371, 0);  // EP_PWT_H
            }
            break;
        case 1377: // Silithus
            if (outdoorPvP && outdoorPvP->GetTypeId() == OUTDOOR_PVP_SI)
                outdoorPvP->FillInitialWorldStates(packet);
            else
            {
                packet.Worldstates.emplace_back(2313, 0); // SI_GATHERED_A
                packet.Worldstates.emplace_back(2314, 0); // SI_GATHERED_H
                packet.Worldstates.emplace_back(2317, 0); // SI_SILITHYST_MAX
            }
            // unknown, aq opening?
            packet.Worldstates.emplace_back(2322, 0); // AQ_SANDWORM_N
            packet.Worldstates.emplace_back(2323, 0); // AQ_SANDWORM_S
            packet.Worldstates.emplace_back(2324, 0); // AQ_SANDWORM_SW
            packet.Worldstates.emplace_back(2325, 0); // AQ_SANDWORM_E
            break;
        case 2597: // Alterac Valley
            if (battleground && battleground->GetTypeID(true) == BATTLEGROUND_AV)
                battleground->FillInitialWorldStates(packet);
            else
            {
                packet.Worldstates.emplace_back(1966, 1); // AV_SNOWFALL_N
                packet.Worldstates.emplace_back(1330, 1); // AV_FROSTWOLFHUT_H_C
                packet.Worldstates.emplace_back(1329, 0); // AV_FROSTWOLFHUT_A_C
                packet.Worldstates.emplace_back(1326, 0); // AV_AID_A_A
                packet.Worldstates.emplace_back(1393, 0); // East Frostwolf Tower Horde Assaulted - UNUSED
                packet.Worldstates.emplace_back(1392, 0); // West Frostwolf Tower Horde Assaulted - UNUSED
                packet.Worldstates.emplace_back(1383, 1); // AV_FROSTWOLFE_CONTROLLED
                packet.Worldstates.emplace_back(1382, 1); // AV_FROSTWOLFW_CONTROLLED
                packet.Worldstates.emplace_back(1360, 1); // AV_N_MINE_N
                packet.Worldstates.emplace_back(1348, 0); // AV_ICEBLOOD_A_A
                packet.Worldstates.emplace_back(1334, 0); // AV_PIKEGRAVE_H_C
                packet.Worldstates.emplace_back(1333, 1); // AV_PIKEGRAVE_A_C
                packet.Worldstates.emplace_back(1304, 0); // AV_STONEHEART_A_A
                packet.Worldstates.emplace_back(1303, 0); // AV_STONEHEART_H_A
                packet.Worldstates.emplace_back(1396, 0); // unk
                packet.Worldstates.emplace_back(1395, 0); // Iceblood Tower Horde Assaulted - UNUSED
                packet.Worldstates.emplace_back(1394, 0); // Towerpoint Horde Assaulted - UNUSED
                packet.Worldstates.emplace_back(1391, 0); // unk
                packet.Worldstates.emplace_back(1390, 0); // AV_ICEBLOOD_ASSAULTED
                packet.Worldstates.emplace_back(1389, 0); // AV_TOWERPOINT_ASSAULTED
                packet.Worldstates.emplace_back(1388, 0); // AV_FROSTWOLFE_ASSAULTED
                packet.Worldstates.emplace_back(1387, 0); // AV_FROSTWOLFW_ASSAULTED
                packet.Worldstates.emplace_back(1386, 1); // unk
                packet.Worldstates.emplace_back(1385, 1); // AV_ICEBLOOD_CONTROLLED
                packet.Worldstates.emplace_back(1384, 1); // AV_TOWERPOINT_CONTROLLED
                packet.Worldstates.emplace_back(1381, 0); // AV_STONEH_ASSAULTED
                packet.Worldstates.emplace_back(1380, 0); // AV_ICEWING_ASSAULTED
                packet.Worldstates.emplace_back(1379, 0); // AV_DUNN_ASSAULTED
                packet.Worldstates.emplace_back(1378, 0); // AV_DUNS_ASSAULTED
                packet.Worldstates.emplace_back(1377, 0); // Stoneheart Bunker Alliance Assaulted - UNUSED
                packet.Worldstates.emplace_back(1376, 0); // Icewing Bunker Alliance Assaulted - UNUSED
                packet.Worldstates.emplace_back(1375, 0); // Dunbaldar South Alliance Assaulted - UNUSED
                packet.Worldstates.emplace_back(1374, 0); // Dunbaldar North Alliance Assaulted - UNUSED
                packet.Worldstates.emplace_back(1373, 0); // AV_STONEH_DESTROYED
                packet.Worldstates.emplace_back(966, 0);  // AV_UNK_02
                packet.Worldstates.emplace_back(964, 0);  // AV_UNK_01
                packet.Worldstates.emplace_back(962, 0);  // AV_STORMPIKE_COMMANDERS
                packet.Worldstates.emplace_back(1302, 1); // AV_STONEHEART_A_C
                packet.Worldstates.emplace_back(1301, 0); // AV_STONEHEART_H_C
                packet.Worldstates.emplace_back(950, 0);  // AV_STORMPIKE_LIEUTENANTS
                packet.Worldstates.emplace_back(1372, 0); // AV_ICEWING_DESTROYED
                packet.Worldstates.emplace_back(1371, 0); // AV_DUNN_DESTROYED
                packet.Worldstates.emplace_back(1370, 0); // AV_DUNS_DESTROYED
                packet.Worldstates.emplace_back(1369, 0); // unk
                packet.Worldstates.emplace_back(1368, 0); // AV_ICEBLOOD_DESTROYED
                packet.Worldstates.emplace_back(1367, 0); // AV_TOWERPOINT_DESTROYED
                packet.Worldstates.emplace_back(1366, 0); // AV_FROSTWOLFE_DESTROYED
                packet.Worldstates.emplace_back(1365, 0); // AV_FROSTWOLFW_DESTROYED
                packet.Worldstates.emplace_back(1364, 1); // AV_STONEH_CONTROLLED
                packet.Worldstates.emplace_back(1363, 1); // AV_ICEWING_CONTROLLED
                packet.Worldstates.emplace_back(1362, 1); // AV_DUNN_CONTROLLED
                packet.Worldstates.emplace_back(1361, 1); // AV_DUNS_CONTROLLED
                packet.Worldstates.emplace_back(1359, 0); // AV_N_MINE_H
                packet.Worldstates.emplace_back(1358, 0); // AV_N_MINE_A
                packet.Worldstates.emplace_back(1357, 1); // AV_S_MINE_N
                packet.Worldstates.emplace_back(1356, 0); // AV_S_MINE_H
                packet.Worldstates.emplace_back(1355, 0); // AV_S_MINE_A
                packet.Worldstates.emplace_back(1349, 0); // AV_ICEBLOOD_H_A
                packet.Worldstates.emplace_back(1347, 1); // AV_ICEBLOOD_H_C
                packet.Worldstates.emplace_back(1346, 0); // AV_ICEBLOOD_A_C
                packet.Worldstates.emplace_back(1344, 0); // AV_SNOWFALL_H_A
                packet.Worldstates.emplace_back(1343, 0); // AV_SNOWFALL_A_A
                packet.Worldstates.emplace_back(1342, 0); // AV_SNOWFALL_H_C
                packet.Worldstates.emplace_back(1341, 0); // AV_SNOWFALL_A_C
                packet.Worldstates.emplace_back(1340, 0); // AV_FROSTWOLF_H_A
                packet.Worldstates.emplace_back(1339, 0); // AV_FROSTWOLF_A_A
                packet.Worldstates.emplace_back(1338, 1); // AV_FROSTWOLF_H_C
                packet.Worldstates.emplace_back(1337, 0); // AV_FROSTWOLF_A_C
                packet.Worldstates.emplace_back(1336, 0); // AV_PIKEGRAVE_H_A
                packet.Worldstates.emplace_back(1335, 0); // AV_PIKEGRAVE_A_A
                packet.Worldstates.emplace_back(1332, 0); // AV_FROSTWOLFHUT_H_A
                packet.Worldstates.emplace_back(1331, 0); // AV_FROSTWOLFHUT_A_A
                packet.Worldstates.emplace_back(1328, 0); // AV_AID_H_A
                packet.Worldstates.emplace_back(1327, 0); // AV_AID_H_C
                packet.Worldstates.emplace_back(1325, 1); // AV_AID_A_C
            }
            break;
        case 3277: // Warsong Gulch
            if (battleground && battleground->GetTypeID(true) == BATTLEGROUND_WS)
                battleground->FillInitialWorldStates(packet);
            else
            {
                packet.Worldstates.emplace_back(1581, 0); // alliance flag captures
                packet.Worldstates.emplace_back(1582, 0); // horde flag captures
                packet.Worldstates.emplace_back(1545, 0); // unk, set to 1 on alliance flag pickup...
                packet.Worldstates.emplace_back(1546, 0); // unk, set to 1 on horde flag pickup, after drop it's -1
                packet.Worldstates.emplace_back(1547, 2); // unk
                packet.Worldstates.emplace_back(1601, 3); // unk (max flag captures?)
                packet.Worldstates.emplace_back(2338, 1); // horde (0 - hide, 1 - flag ok, 2 - flag picked up (flashing), 3 - flag picked up (not flashing)
                packet.Worldstates.emplace_back(2339, 1); // alliance (0 - hide, 1 - flag ok, 2 - flag picked up (flashing), 3 - flag picked up (not flashing)
            }
            break;
        case 3358: // Arathi Basin
            if (battleground && battleground->GetTypeID(true) == BATTLEGROUND_AB)
                battleground->FillInitialWorldStates(packet);
            else
            {
                packet.Worldstates.emplace_back(1767, 0);    // stables alliance
                packet.Worldstates.emplace_back(1768, 0);    // stables horde
                packet.Worldstates.emplace_back(1769, 0);    // stables alliance controlled
                packet.Worldstates.emplace_back(1770, 0);    // stables horde controlled
                packet.Worldstates.emplace_back(1772, 0);    // farm alliance
                packet.Worldstates.emplace_back(1773, 0);    // farm horde
                packet.Worldstates.emplace_back(1774, 0);    // farm alliance controlled
                packet.Worldstates.emplace_back(1775, 0);    // farm horde controlled
                packet.Worldstates.emplace_back(1776, 0);    // alliance resources
                packet.Worldstates.emplace_back(1777, 0);    // horde resources
                packet.Worldstates.emplace_back(1778, 0);    // horde bases
                packet.Worldstates.emplace_back(1779, 0);    // alliance bases
                packet.Worldstates.emplace_back(1780, 2000); // max resources (2000)
                packet.Worldstates.emplace_back(1782, 0);    // blacksmith alliance
                packet.Worldstates.emplace_back(1783, 0);    // blacksmith horde
                packet.Worldstates.emplace_back(1784, 0);    // blacksmith alliance controlled
                packet.Worldstates.emplace_back(1785, 0);    // blacksmith horde controlled
                packet.Worldstates.emplace_back(1787, 0);    // gold mine alliance
                packet.Worldstates.emplace_back(1788, 0);    // gold mine horde
                packet.Worldstates.emplace_back(1789, 0);    // gold mine alliance controlled
                packet.Worldstates.emplace_back(1790, 0);    // gold mine horde controlled
                packet.Worldstates.emplace_back(1792, 0);    // lumber mill alliance
                packet.Worldstates.emplace_back(1793, 0);    // lumber mill horde
                packet.Worldstates.emplace_back(1794, 0);    // lumber mill alliance controlled
                packet.Worldstates.emplace_back(1795, 0);    // lumber mill horde controlled
                packet.Worldstates.emplace_back(1842, 1);    // stables (1 - uncontrolled)
                packet.Worldstates.emplace_back(1843, 1);    // gold mine (1 - uncontrolled)
                packet.Worldstates.emplace_back(1844, 1);    // lumber mill (1 - uncontrolled)
                packet.Worldstates.emplace_back(1845, 1);    // farm (1 - uncontrolled)
                packet.Worldstates.emplace_back(1846, 1);    // blacksmith (1 - uncontrolled)
                packet.Worldstates.emplace_back(1861, 2);    // unk
                packet.Worldstates.emplace_back(1955, 1800); // warning limit (1800)
            }
            break;
        case 3820: // Eye of the Storm
            if (battleground && battleground->GetTypeID(true) == BATTLEGROUND_EY)
                battleground->FillInitialWorldStates(packet);
            else
            {
                packet.Worldstates.emplace_back(2753, 0);   // Horde Bases
                packet.Worldstates.emplace_back(2752, 0);   // Alliance Bases
                packet.Worldstates.emplace_back(2742, 0);   // Mage Tower - Horde conflict
                packet.Worldstates.emplace_back(2741, 0);   // Mage Tower - Alliance conflict
                packet.Worldstates.emplace_back(2740, 0);   // Fel Reaver - Horde conflict
                packet.Worldstates.emplace_back(2739, 0);   // Fel Reaver - Alliance conflict
                packet.Worldstates.emplace_back(2738, 0);   // Draenei - Alliance conflict
                packet.Worldstates.emplace_back(2737, 0);   // Draenei - Horde conflict
                packet.Worldstates.emplace_back(2736, 0);   // unk (0 at start)
                packet.Worldstates.emplace_back(2735, 0);   // unk (0 at start)
                packet.Worldstates.emplace_back(2733, 0);   // Draenei - Horde control
                packet.Worldstates.emplace_back(2732, 0);   // Draenei - Alliance control
                packet.Worldstates.emplace_back(2731, 1);   // Draenei uncontrolled (1 - yes, 0 - no)
                packet.Worldstates.emplace_back(2730, 0);   // Mage Tower - Alliance control
                packet.Worldstates.emplace_back(2729, 0);   // Mage Tower - Horde control
                packet.Worldstates.emplace_back(2728, 1);   // Mage Tower uncontrolled (1 - yes, 0 - no)
                packet.Worldstates.emplace_back(2727, 0);   // Fel Reaver - Horde control
                packet.Worldstates.emplace_back(2726, 0);   // Fel Reaver - Alliance control
                packet.Worldstates.emplace_back(2725, 1);   // Fel Reaver uncontrolled (1 - yes, 0 - no)
                packet.Worldstates.emplace_back(2724, 0);   // Boold Elf - Horde control
                packet.Worldstates.emplace_back(2723, 0);   // Boold Elf - Alliance control
                packet.Worldstates.emplace_back(2722, 1);   // Boold Elf uncontrolled (1 - yes, 0 - no)
                packet.Worldstates.emplace_back(2757, 1);   // Flag (1 - show, 0 - hide) - doesn't work exactly this way!
                packet.Worldstates.emplace_back(2770, 1);   // Horde top-stats (1 - show, 0 - hide) // 02 -> horde picked up the flag
                packet.Worldstates.emplace_back(2769, 1);   // Alliance top-stats (1 - show, 0 - hide) // 02 -> alliance picked up the flag
                packet.Worldstates.emplace_back(2750, 0);   // Horde resources
                packet.Worldstates.emplace_back(2749, 0);   // Alliance resources
                packet.Worldstates.emplace_back(2565, 142); // unk, constant?
                packet.Worldstates.emplace_back(2720, 0);   // Capturing progress-bar (100 -> empty (only grey), 0 -> blue|red (no grey), default 0)
                packet.Worldstates.emplace_back(2719, 0);   // Capturing progress-bar (0 - left, 100 - right)
                packet.Worldstates.emplace_back(2718, 0);   // Capturing progress-bar (1 - show, 0 - hide)
                packet.Worldstates.emplace_back(3085, 379); // unk, constant?
                // missing unknowns
            }
            break;
        case 3483: // Hellfire Peninsula
            if (outdoorPvP && outdoorPvP->GetTypeId() == OUTDOOR_PVP_HP)
                outdoorPvP->FillInitialWorldStates(packet);
            else
            {
                packet.Worldstates.emplace_back(2490, 1);   // add ally tower main gui icon
                packet.Worldstates.emplace_back(2489, 1);   // add horde tower main gui icon
                packet.Worldstates.emplace_back(2485, 0);   // show neutral broken hill icon
                packet.Worldstates.emplace_back(2484, 1);   // show icon above broken hill
                packet.Worldstates.emplace_back(2483, 0);   // show ally broken hill icon
                packet.Worldstates.emplace_back(2482, 0);   // show neutral overlook icon
                packet.Worldstates.emplace_back(2481, 1);   // show the overlook arrow
                packet.Worldstates.emplace_back(2480, 0);   // show ally overlook icon
                packet.Worldstates.emplace_back(2478, 0);   // horde pvp objectives captured
                packet.Worldstates.emplace_back(2476, 0);   // ally pvp objectives captured
                packet.Worldstates.emplace_back(2475, 100); // horde slider grey area
                packet.Worldstates.emplace_back(2474, 50);  // horde slider percentage, 100 for ally, 0 for horde
                packet.Worldstates.emplace_back(2473, 0);   // horde slider display
                packet.Worldstates.emplace_back(2472, 0);   // show the neutral stadium icon
                packet.Worldstates.emplace_back(2471, 0);   // show the ally stadium icon
                packet.Worldstates.emplace_back(2470, 1);   // show the horde stadium icon
            }
            break;
        case 3518: // Nagrand
            if (outdoorPvP && outdoorPvP->GetTypeId() == OUTDOOR_PVP_NA)
                outdoorPvP->FillInitialWorldStates(packet);
            else
            {
               packet.Worldstates.emplace_back(2503, 0); // NA_UI_HORDE_GUARDS_SHOW
               packet.Worldstates.emplace_back(2502, 0); // NA_UI_ALLIANCE_GUARDS_SHOW
               packet.Worldstates.emplace_back(2493, 0); // NA_UI_GUARDS_MAX
               packet.Worldstates.emplace_back(2491, 0); // NA_UI_GUARDS_LEFT
               packet.Worldstates.emplace_back(2495, 0); // NA_UI_OUTLAND_01
               packet.Worldstates.emplace_back(2494, 0); // NA_UI_UNK_1
               packet.Worldstates.emplace_back(2497, 0); // NA_UI_UNK_2
               packet.Worldstates.emplace_back(2762, 0); // NA_MAP_WYVERN_NORTH_NEU_H
               packet.Worldstates.emplace_back(2662, 0); // NA_MAP_WYVERN_NORTH_NEU_A
               packet.Worldstates.emplace_back(2663, 0); // NA_MAP_WYVERN_NORTH_H
               packet.Worldstates.emplace_back(2664, 0); // NA_MAP_WYVERN_NORTH_A
               packet.Worldstates.emplace_back(2760, 0); // NA_MAP_WYVERN_SOUTH_NEU_H
               packet.Worldstates.emplace_back(2670, 0); // NA_MAP_WYVERN_SOUTH_NEU_A
               packet.Worldstates.emplace_back(2668, 0); // NA_MAP_WYVERN_SOUTH_H
               packet.Worldstates.emplace_back(2669, 0); // NA_MAP_WYVERN_SOUTH_A
               packet.Worldstates.emplace_back(2761, 0); // NA_MAP_WYVERN_WEST_NEU_H
               packet.Worldstates.emplace_back(2667, 0); // NA_MAP_WYVERN_WEST_NEU_A
               packet.Worldstates.emplace_back(2665, 0); // NA_MAP_WYVERN_WEST_H
               packet.Worldstates.emplace_back(2666, 0); // NA_MAP_WYVERN_WEST_A
               packet.Worldstates.emplace_back(2763, 0); // NA_MAP_WYVERN_EAST_NEU_H
               packet.Worldstates.emplace_back(2659, 0); // NA_MAP_WYVERN_EAST_NEU_A
               packet.Worldstates.emplace_back(2660, 0); // NA_MAP_WYVERN_EAST_H
               packet.Worldstates.emplace_back(2661, 0); // NA_MAP_WYVERN_EAST_A
               packet.Worldstates.emplace_back(2671, 0); // NA_MAP_HALAA_NEUTRAL
               packet.Worldstates.emplace_back(2676, 0); // NA_MAP_HALAA_NEU_A
               packet.Worldstates.emplace_back(2677, 0); // NA_MAP_HALAA_NEU_H
               packet.Worldstates.emplace_back(2672, 0); // NA_MAP_HALAA_HORDE
               packet.Worldstates.emplace_back(2673, 0); // NA_MAP_HALAA_ALLIANCE
            }
            break;
        case 3519: // Terokkar Forest
            if (outdoorPvP && outdoorPvP->GetTypeId() == OUTDOOR_PVP_TF)
                outdoorPvP->FillInitialWorldStates(packet);
            else
            {
                packet.Worldstates.emplace_back(2625, 0);  // TF_UI_CAPTURE_BAR_POS
                packet.Worldstates.emplace_back(2624, 20); // TF_UI_CAPTURE_BAR_NEUTRAL
                packet.Worldstates.emplace_back(2623, 0);  // TF_UI_SHOW CAPTURE BAR
                packet.Worldstates.emplace_back(2622, 0);  // TF_UI_TOWER_COUNT_H
                packet.Worldstates.emplace_back(2621, 5);  // TF_UI_TOWER_COUNT_A
                packet.Worldstates.emplace_back(2620, 0);  // TF_UI_TOWERS_CONTROLLED_DISPLAY
                packet.Worldstates.emplace_back(2696, 0);  // TF_TOWER_NUM_15 - SE Neutral
                packet.Worldstates.emplace_back(2695, 0);  // TF_TOWER_NUM_14 - SE Horde
                packet.Worldstates.emplace_back(2694, 0);  // TF_TOWER_NUM_13 - SE Alliance
                packet.Worldstates.emplace_back(2693, 0);  // TF_TOWER_NUM_12 - S Neutral
                packet.Worldstates.emplace_back(2692, 0);  // TF_TOWER_NUM_11 - S Horde
                packet.Worldstates.emplace_back(2691, 0);  // TF_TOWER_NUM_10 - S Alliance
                packet.Worldstates.emplace_back(2690, 0);  // TF_TOWER_NUM_09 - NE Neutral
                packet.Worldstates.emplace_back(2689, 0);  // TF_TOWER_NUM_08 - NE Horde
                packet.Worldstates.emplace_back(2688, 0);  // TF_TOWER_NUM_07 - NE Alliance
                packet.Worldstates.emplace_back(2687, 0);  // TF_TOWER_NUM_16 - unk
                packet.Worldstates.emplace_back(2686, 0);  // TF_TOWER_NUM_06 - N Neutral
                packet.Worldstates.emplace_back(2685, 0);  // TF_TOWER_NUM_05 - N Horde
                packet.Worldstates.emplace_back(2684, 0);  // TF_TOWER_NUM_04 - N Alliance
                packet.Worldstates.emplace_back(2683, 0);  // TF_TOWER_NUM_03 - NW Alliance
                packet.Worldstates.emplace_back(2682, 0);  // TF_TOWER_NUM_02 - NW Horde
                packet.Worldstates.emplace_back(2681, 0);  // TF_TOWER_NUM_01 - NW Neutral
                packet.Worldstates.emplace_back(2512, 5);  // TF_UI_LOCKED_TIME_MINUTES_FIRST_DIGIT
                packet.Worldstates.emplace_back(2510, 0);  // TF_UI_LOCKED_TIME_MINUTES_SECOND_DIGIT
                packet.Worldstates.emplace_back(2509, 0);  // TF_UI_LOCKED_TIME_HOURS
                packet.Worldstates.emplace_back(2508, 0);  // TF_UI_LOCKED_DISPLAY_NEUTRAL
                packet.Worldstates.emplace_back(2768, 0);  // TF_UI_LOCKED_DISPLAY_HORDE
                packet.Worldstates.emplace_back(2767, 1);  // TF_UI_LOCKED_DISPLAY_ALLIANCE
            }
            break;
        case 3521: // Zangarmarsh
            if (outdoorPvP && outdoorPvP->GetTypeId() == OUTDOOR_PVP_ZM)
                outdoorPvP->FillInitialWorldStates(packet);
            else
            {
                packet.Worldstates.emplace_back(2529, 0); // ZM_UNK_1
                packet.Worldstates.emplace_back(2528, 0); // ZM_UNK_2
                packet.Worldstates.emplace_back(2527, 0); // ZM_UNK_3
                packet.Worldstates.emplace_back(2653, 1); // ZM_WORLDSTATE_UNK_1
                packet.Worldstates.emplace_back(2652, 0); // ZM_MAP_TOWER_EAST_N
                packet.Worldstates.emplace_back(2651, 1); // ZM_MAP_TOWER_EAST_H
                packet.Worldstates.emplace_back(2650, 0); // ZM_MAP_TOWER_EAST_A
                packet.Worldstates.emplace_back(2649, 1); // ZM_MAP_GRAVEYARD_H - Twin spire graveyard horde
                packet.Worldstates.emplace_back(2648, 0); // ZM_MAP_GRAVEYARD_A
                packet.Worldstates.emplace_back(2647, 0); // ZM_MAP_GRAVEYARD_N
                packet.Worldstates.emplace_back(2646, 0); // ZM_MAP_TOWER_WEST_N
                packet.Worldstates.emplace_back(2645, 1); // ZM_MAP_TOWER_WEST_H
                packet.Worldstates.emplace_back(2644, 0); // ZM_MAP_TOWER_WEST_A
                packet.Worldstates.emplace_back(2535, 0); // ZM_UNK_4
                packet.Worldstates.emplace_back(2534, 0); // ZM_UNK_5
                packet.Worldstates.emplace_back(2533, 0); // ZM_UNK_6
                packet.Worldstates.emplace_back(2560, 0); // ZM_UI_TOWER_EAST_N
                packet.Worldstates.emplace_back(2559, 1); // ZM_UI_TOWER_EAST_H
                packet.Worldstates.emplace_back(2558, 0); // ZM_UI_TOWER_EAST_A
                packet.Worldstates.emplace_back(2557, 0); // ZM_UI_TOWER_WEST_N
                packet.Worldstates.emplace_back(2556, 1); // ZM_UI_TOWER_WEST_H
                packet.Worldstates.emplace_back(2555, 0); // ZM_UI_TOWER_WEST_A
                packet.Worldstates.emplace_back(2658, 0); // ZM_MAP_HORDE_FLAG_READY
                packet.Worldstates.emplace_back(2657, 1); // ZM_MAP_HORDE_FLAG_NOT_READY
                packet.Worldstates.emplace_back(2656, 1); // ZM_MAP_ALLIANCE_FLAG_NOT_READY
                packet.Worldstates.emplace_back(2655, 0); // ZM_MAP_ALLIANCE_FLAG_READY
            }
            break;
        case 3698: // Nagrand Arena
            if (battleground && battleground->GetTypeID(true) == BATTLEGROUND_NA)
                battleground->FillInitialWorldStates(packet);
            else
            {
                 packet.Worldstates.emplace_back(2575, 0); // BATTLEGROUND_NAGRAND_ARENA_GOLD
                 packet.Worldstates.emplace_back(2576, 0); // BATTLEGROUND_NAGRAND_ARENA_GREEN
                 packet.Worldstates.emplace_back(2577, 0); // BATTLEGROUND_NAGRAND_ARENA_SHOW
            }
            break;
        case 3702: // Blade's Edge Arena
            if (battleground && battleground->GetTypeID(true) == BATTLEGROUND_BE)
                battleground->FillInitialWorldStates(packet);
            else
            {
                packet.Worldstates.emplace_back(2544, 0); // BATTLEGROUND_BLADES_EDGE_ARENA_GOLD
                packet.Worldstates.emplace_back(2545, 0); // BATTLEGROUND_BLADES_EDGE_ARENA_GREEN
                packet.Worldstates.emplace_back(2547, 0); // BATTLEGROUND_BLADES_EDGE_ARENA_SHOW
            }
            break;
        case 3968: // Ruins of Lordaeron
            if (battleground && battleground->GetTypeID(true) == BATTLEGROUND_RL)
                battleground->FillInitialWorldStates(packet);
            else
            {
                packet.Worldstates.emplace_back(3000, 0); // BATTELGROUND_RUINS_OF_LORDAERNON_GOLD
                packet.Worldstates.emplace_back(3001, 0); // BATTELGROUND_RUINS_OF_LORDAERNON_GREEN
                packet.Worldstates.emplace_back(3002, 0); // BATTELGROUND_RUINS_OF_LORDAERNON_SHOW
            }
            break;
        case 4378: // Dalaran Sewers
            if (battleground && battleground->GetTypeID(true) == BATTLEGROUND_DS)
                battleground->FillInitialWorldStates(packet);
            else
            {
                packet.Worldstates.emplace_back(3601, 0); // ARENA_WORLD_STATE_ALIVE_PLAYERS_GOLD
                packet.Worldstates.emplace_back(3600, 0); // ARENA_WORLD_STATE_ALIVE_PLAYERS_GREEN
                packet.Worldstates.emplace_back(3610, 0); // ARENA_WORLD_STATE_ALIVE_PLAYERS_SHOW
            }
            break;
        case 4384: // Strand of the Ancients
            if (battleground && battleground->GetTypeID(true) == BATTLEGROUND_SA)
                battleground->FillInitialWorldStates(packet);
            else
            {
                packet.Worldstates.emplace_back(3849, 0); // Gate of Temple
                packet.Worldstates.emplace_back(3638, 0); // Gate of Yellow Moon
                packet.Worldstates.emplace_back(3623, 0); // Gate of Green Emerald
                packet.Worldstates.emplace_back(3620, 0); // Gate of Blue Sapphire
                packet.Worldstates.emplace_back(3617, 0); // Gate of Red Sun
                packet.Worldstates.emplace_back(3614, 0); // Gate of Purple Ametyst
                packet.Worldstates.emplace_back(3571, 0); // bonus timer (1 - on, 0 - off)
                packet.Worldstates.emplace_back(3565, 0); // Horde Attacker
                packet.Worldstates.emplace_back(3564, 0); // Alliance Attacker

                // End Round timer, example: 19:59 -> A:BC
                packet.Worldstates.emplace_back(3561, 0); // C
                packet.Worldstates.emplace_back(3560, 0); // B
                packet.Worldstates.emplace_back(3559, 0); // A

                packet.Worldstates.emplace_back(3637, 0); // BG_SA_CENTER_GY_ALLIANCE
                packet.Worldstates.emplace_back(3636, 0); // BG_SA_RIGHT_GY_ALLIANCE
                packet.Worldstates.emplace_back(3635, 0); // BG_SA_LEFT_GY_ALLIANCE
                packet.Worldstates.emplace_back(3634, 0); // BG_SA_CENTER_GY_HORDE
                packet.Worldstates.emplace_back(3633, 0); // BG_SA_LEFT_GY_HORDE
                packet.Worldstates.emplace_back(3632, 0); // BG_SA_RIGHT_GY_HORDE
                packet.Worldstates.emplace_back(3631, 0); // BG_SA_HORDE_DEFENCE_TOKEN
                packet.Worldstates.emplace_back(3630, 0); // BG_SA_ALLIANCE_DEFENCE_TOKEN
                packet.Worldstates.emplace_back(3629, 0); // BG_SA_LEFT_ATT_TOKEN_HRD
                packet.Worldstates.emplace_back(3628, 0); // BG_SA_RIGHT_ATT_TOKEN_HRD
                packet.Worldstates.emplace_back(3627, 0); // BG_SA_RIGHT_ATT_TOKEN_ALL
                packet.Worldstates.emplace_back(3626, 0); // BG_SA_LEFT_ATT_TOKEN_ALL
                // missing unknowns
            }
            break;
        case 4406: // Ring of Valor
            if (battleground && battleground->GetTypeID(true) == BATTLEGROUND_RV)
                battleground->FillInitialWorldStates(packet);
            else
            {
               packet.Worldstates.emplace_back(3600, 0); // ARENA_WORLD_STATE_ALIVE_PLAYERS_GREEN
               packet.Worldstates.emplace_back(3601, 0); // ARENA_WORLD_STATE_ALIVE_PLAYERS_GOLD
               packet.Worldstates.emplace_back(3610, 0); // ARENA_WORLD_STATE_ALIVE_PLAYERS_SHOW
            }
            break;
        case 4710: // Isle of Conquest
            if (battleground && battleground->GetTypeID(true) == BATTLEGROUND_IC)
                battleground->FillInitialWorldStates(packet);
            else
            {
                packet.Worldstates.emplace_back(4221, 1);   // BG_IC_ALLIANCE_RENFORT_SET
                packet.Worldstates.emplace_back(4222, 1);   // BG_IC_HORDE_RENFORT_SET
                packet.Worldstates.emplace_back(4226, 300); // BG_IC_ALLIANCE_RENFORT
                packet.Worldstates.emplace_back(4227, 300); // BG_IC_HORDE_RENFORT
                packet.Worldstates.emplace_back(4322, 1);   // BG_IC_GATE_FRONT_H_WS_OPEN
                packet.Worldstates.emplace_back(4321, 1);   // BG_IC_GATE_WEST_H_WS_OPEN
                packet.Worldstates.emplace_back(4320, 1);   // BG_IC_GATE_EAST_H_WS_OPEN
                packet.Worldstates.emplace_back(4323, 1);   // BG_IC_GATE_FRONT_A_WS_OPEN
                packet.Worldstates.emplace_back(4324, 1);   // BG_IC_GATE_WEST_A_WS_OPEN
                packet.Worldstates.emplace_back(4325, 1);   // BG_IC_GATE_EAST_A_WS_OPEN
                packet.Worldstates.emplace_back(4317, 1);   // unk
                packet.Worldstates.emplace_back(4301, 1);   // BG_IC_DOCKS_UNCONTROLLED
                packet.Worldstates.emplace_back(4296, 1);   // BG_IC_HANGAR_UNCONTROLLED
                packet.Worldstates.emplace_back(4306, 1);   // BG_IC_QUARRY_UNCONTROLLED
                packet.Worldstates.emplace_back(4311, 1);   // BG_IC_REFINERY_UNCONTROLLED
                packet.Worldstates.emplace_back(4294, 1);   // BG_IC_WORKSHOP_UNCONTROLLED
                packet.Worldstates.emplace_back(4243, 1);   // unk
                packet.Worldstates.emplace_back(4345, 1);   // unk
            }
            break;
        case 4987: // The Ruby Sanctum
            if (instance)
                instance->FillInitialWorldStates(packet);
            else
            {
                packet.Worldstates.emplace_back(5049, 50); // WORLDSTATE_CORPOREALITY_MATERIAL
                packet.Worldstates.emplace_back(5050, 50); // WORLDSTATE_CORPOREALITY_TWILIGHT
                packet.Worldstates.emplace_back(5051, 0);  // WORLDSTATE_CORPOREALITY_TOGGLE
            }
            break;
        case 4812: // Icecrown Citadel
            if (instance)
                instance->FillInitialWorldStates(packet);
            else
            {
                packet.Worldstates.emplace_back(4903, 0);  // WORLDSTATE_SHOW_TIMER (Blood Quickening weekly)
                packet.Worldstates.emplace_back(4904, 30); // WORLDSTATE_EXECUTION_TIME
                packet.Worldstates.emplace_back(4940, 0);  // WORLDSTATE_SHOW_ATTEMPTS
                packet.Worldstates.emplace_back(4941, 50); // WORLDSTATE_ATTEMPTS_REMAINING
                packet.Worldstates.emplace_back(4942, 50); // WORLDSTATE_ATTEMPTS_MAX
            }
            break;
        case 4100: // The Culling of Stratholme
            if (instance)
                instance->FillInitialWorldStates(packet);
            else
            {
                packet.Worldstates.emplace_back(3479, 0);  // WORLDSTATE_SHOW_CRATES
                packet.Worldstates.emplace_back(3480, 0);  // WORLDSTATE_CRATES_REVEALED
                packet.Worldstates.emplace_back(3504, 0);  // WORLDSTATE_WAVE_COUNT
                packet.Worldstates.emplace_back(3931, 25); // WORLDSTATE_TIME_GUARDIAN
                packet.Worldstates.emplace_back(3932, 0);  // WORLDSTATE_TIME_GUARDIAN_SHOW
            }
            break;
        case 4228: // The Oculus
            if (instance)
                instance->FillInitialWorldStates(packet);
            else
            {
                packet.Worldstates.emplace_back(3524, 0); // WORLD_STATE_CENTRIFUGE_CONSTRUCT_SHOW
                packet.Worldstates.emplace_back(3486, 0); // WORLD_STATE_CENTRIFUGE_CONSTRUCT_AMOUNT
            }
            break;
        case 4273: // Ulduar
            if (instance)
                instance->FillInitialWorldStates(packet);
            else
            {
                packet.Worldstates.emplace_back(4132, 0); // WORLDSTATE_ALGALON_TIMER_ENABLED
                packet.Worldstates.emplace_back(4131, 0); // WORLDSTATE_ALGALON_DESPAWN_TIMER
            }
            break;
        case 4415: // Violet Hold
            if (instance)
                instance->FillInitialWorldStates(packet);
            else
            {
               packet.Worldstates.emplace_back(3816, 0);   // WORLD_STATE_VH_SHOW
               packet.Worldstates.emplace_back(3815, 100); // WORLD_STATE_VH_PRISON_STATE
               packet.Worldstates.emplace_back(3810, 0);   // WORLD_STATE_VH_WAVE_COUNT
            }
            break;
        case 4820: // Halls of Refection
            if (instance)
                instance->FillInitialWorldStates(packet);
            else
            {
                packet.Worldstates.emplace_back(4884, 0); // WORLD_STATE_HOR_WAVES_ENABLED
                packet.Worldstates.emplace_back(4882, 0); // WORLD_STATE_HOR_WAVE_COUNT
            }
            break;
        case 4197: // Wintergrasp
            if (battlefield && battlefield->GetTypeId() == BATTLEFIELD_WG)
                battlefield->FillInitialWorldStates(packet);
            else
            {
            }
            break;
        default:
            break;
    }

    SendDirectMessage(packet.Write());
    SendBGWeekendWorldStates();
    SendBattlefieldWorldStates();
}

void Player::SendBGWeekendWorldStates() const
{
    for (uint32 i = 1; i < sBattlemasterListStore.GetNumRows(); ++i)
    {
        BattlemasterListEntry const* bl = sBattlemasterListStore.LookupEntry(i);
        if (bl && bl->HolidayWorldStateId)
        {
            if (BattlegroundMgr::IsBGWeekend((BattlegroundTypeId)bl->id))
                SendUpdateWorldState(bl->HolidayWorldStateId, 1);
            else
                SendUpdateWorldState(bl->HolidayWorldStateId, 0);
        }
    }
}

void Player::SendBattlefieldWorldStates() const
{
    /// Send misc stuff that needs to be sent on every login, like the battle timers.
    if (sWorld->getBoolConfig(CONFIG_WINTERGRASP_ENABLE))
    {
        if (BattlefieldWG* wg = static_cast<BattlefieldWG*>(sBattlefieldMgr->GetBattlefieldByBattleId(BATTLEFIELD_BATTLEID_WG)))
        {
            SendUpdateWorldState(BATTLEFIELD_WG_WORLD_STATE_ACTIVE, wg->IsWarTime() ? 0 : 1);
            uint32 timer = wg->IsWarTime() ? 0 : (wg->GetTimer() / 1000); // 0 - Time to next battle
            SendUpdateWorldState(ClockWorldState[1], uint32(GameTime::GetGameTime() + timer));
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
    WorldPacket data(SMSG_BINDER_CONFIRM, 8);
    data << uint64(guid);
    SendDirectMessage(&data);
}

void Player::SendTalentWipeConfirm(ObjectGuid guid) const
{
    WorldPacket data(MSG_TALENT_WIPE_CONFIRM, (8+4));
    data << uint64(guid);
    uint32 cost = sWorld->getBoolConfig(CONFIG_NO_RESET_TALENT_COST) ? 0 : ResetTalentsCost();
    data << cost;
    SendDirectMessage(&data);
}

void Player::ResetPetTalents()
{
    // This needs another gossip option + NPC text as a confirmation.
    // The confirmation gossip listid has the text: "Yes, please do."
    Pet* pet = GetPet();

    if (!pet || pet->getPetType() != HUNTER_PET || pet->m_usedTalentCount == 0)
        return;

    CharmInfo* charmInfo = pet->GetCharmInfo();
    if (!charmInfo)
    {
        TC_LOG_ERROR("entities.player", "Object (GUID: %u TypeId: %u) is considered pet-like, but doesn't have charm info!", pet->GetGUID().GetCounter(), pet->GetTypeId());
        return;
    }
    pet->resetTalents();
    SendTalentsInfoData(true);
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
        else
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
    uint8 playerClass = GetClass();

    uint8 slots[4];
    slots[0] = NULL_SLOT;
    slots[1] = NULL_SLOT;
    slots[2] = NULL_SLOT;
    slots[3] = NULL_SLOT;
    switch (proto->InventoryType)
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
            slots[0] = EQUIPMENT_SLOT_RANGED;
            break;
        case INVTYPE_2HWEAPON:
            slots[0] = EQUIPMENT_SLOT_MAINHAND;
            if (Item* mhWeapon = GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND))
            {
                if (ItemTemplate const* mhWeaponProto = mhWeapon->GetTemplate())
                {
                    if (mhWeaponProto->SubClass == ITEM_SUBCLASS_WEAPON_POLEARM || mhWeaponProto->SubClass == ITEM_SUBCLASS_WEAPON_STAFF)
                    {
                        const_cast<Player*>(this)->AutoUnequipOffhandIfNeed(true);
                        break;
                    }
                }
            }

            if (GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND))
            {
                if (proto->SubClass == ITEM_SUBCLASS_WEAPON_POLEARM || proto->SubClass == ITEM_SUBCLASS_WEAPON_STAFF)
                {
                    const_cast<Player*>(this)->AutoUnequipOffhandIfNeed(true);
                    break;
                }
            }
            if (CanDualWield() && CanTitanGrip() && proto->SubClass != ITEM_SUBCLASS_WEAPON_POLEARM && proto->SubClass != ITEM_SUBCLASS_WEAPON_STAFF)
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
        case INVTYPE_THROWN:
            slots[0] = EQUIPMENT_SLOT_RANGED;
            break;
        case INVTYPE_RANGEDRIGHT:
            slots[0] = EQUIPMENT_SLOT_RANGED;
            break;
        case INVTYPE_BAG:
            slots[0] = INVENTORY_SLOT_BAG_START + 0;
            slots[1] = INVENTORY_SLOT_BAG_START + 1;
            slots[2] = INVENTORY_SLOT_BAG_START + 2;
            slots[3] = INVENTORY_SLOT_BAG_START + 3;
            break;
        case INVTYPE_RELIC:
        {
            switch (proto->SubClass)
            {
                case ITEM_SUBCLASS_ARMOR_LIBRAM:
                    if (playerClass == CLASS_PALADIN)
                        slots[0] = EQUIPMENT_SLOT_RANGED;
                    break;
                case ITEM_SUBCLASS_ARMOR_IDOL:
                    if (playerClass == CLASS_DRUID)
                        slots[0] = EQUIPMENT_SLOT_RANGED;
                    break;
                case ITEM_SUBCLASS_ARMOR_TOTEM:
                    if (playerClass == CLASS_SHAMAN)
                        slots[0] = EQUIPMENT_SLOT_RANGED;
                    break;
                case ITEM_SUBCLASS_ARMOR_MISC:
                    if (playerClass == CLASS_WARLOCK)
                        slots[0] = EQUIPMENT_SLOT_RANGED;
                    break;
                case ITEM_SUBCLASS_ARMOR_SIGIL:
                    if (playerClass == CLASS_DEATH_KNIGHT)
                        slots[0] = EQUIPMENT_SLOT_RANGED;
                    break;
            }
            break;
        }
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

    for (uint8 i = KEYRING_SLOT_START; i < CURRENCYTOKEN_SLOT_END; ++i)
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

    for (uint8 i = KEYRING_SLOT_START; i < CURRENCYTOKEN_SLOT_END; ++i)
        if (Item* pItem = GetItemByPos(INVENTORY_SLOT_BAG_0, i))
            if (pItem != skipItem && pItem->GetEntry() == item)
                count += pItem->GetCount();

    for (uint8 i = INVENTORY_SLOT_BAG_START; i < INVENTORY_SLOT_BAG_END; ++i)
        if (Bag* pBag = GetBagByPos(i))
            count += pBag->GetItemCount(item, skipItem);

    if (skipItem && skipItem->GetTemplate()->GemProperties)
        for (uint8 i = EQUIPMENT_SLOT_START; i < INVENTORY_SLOT_ITEM_END; ++i)
            if (Item* pItem = GetItemByPos(INVENTORY_SLOT_BAG_0, i))
                if (pItem != skipItem && pItem->GetTemplate()->Socket[0].Color)
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

        if (skipItem && skipItem->GetTemplate()->GemProperties)
            for (uint8 i = BANK_SLOT_ITEM_START; i < BANK_SLOT_ITEM_END; ++i)
                if (Item* pItem = GetItemByPos(INVENTORY_SLOT_BAG_0, i))
                    if (pItem != skipItem && pItem->GetTemplate()->Socket[0].Color)
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
                    if (pProto->ItemLimitCategory == limitCategory)
                        count += pItem->GetCount();

    for (int i = KEYRING_SLOT_START; i < CURRENCYTOKEN_SLOT_END; ++i)
        if (Item* pItem = GetItemByPos(INVENTORY_SLOT_BAG_0, i))
            if (pItem != skipItem)
                if (ItemTemplate const* pProto = pItem->GetTemplate())
                    if (pProto->ItemLimitCategory == limitCategory)
                        count += pItem->GetCount();

    for (int i = INVENTORY_SLOT_BAG_START; i < INVENTORY_SLOT_BAG_END; ++i)
        if (Bag* pBag = GetBagByPos(i))
            count += pBag->GetItemCountWithLimitCategory(limitCategory, skipItem);

    for (int i = BANK_SLOT_ITEM_START; i < BANK_SLOT_BAG_END; ++i)
        if (Item* pItem = GetItemByPos(INVENTORY_SLOT_BAG_0, i))
            if (pItem != skipItem)
                if (ItemTemplate const* pProto = pItem->GetTemplate())
                    if (pProto->ItemLimitCategory == limitCategory)
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

    for (uint8 i = KEYRING_SLOT_START; i < CURRENCYTOKEN_SLOT_END; ++i)
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
    if (bag == INVENTORY_SLOT_BAG_0 && (slot < BANK_SLOT_BAG_END || (slot >= KEYRING_SLOT_START && slot < CURRENCYTOKEN_SLOT_END)))
        return m_items[slot];
    if (Bag* pBag = GetBagByPos(bag))
        return pBag->GetItemByPos(slot);
    return nullptr;
}

//Does additional check for disarmed weapons
Item* Player::GetUseableItemByPos(uint8 bag, uint8 slot) const
{
    if (!CanUseAttackType(GetAttackBySlot(slot)))
        return nullptr;
    return GetItemByPos(bag, slot);
}

Bag* Player::GetBagByPos(uint8 bag) const
{
    if ((bag >= INVENTORY_SLOT_BAG_START && bag < INVENTORY_SLOT_BAG_END)
        || (bag >= BANK_SLOT_BAG_START && bag < BANK_SLOT_BAG_END))
        if (Item* item = GetItemByPos(INVENTORY_SLOT_BAG_0, bag))
            return item->ToBag();
    return nullptr;
}

uint32 Player::GetFreeInventorySpace() const
{
    uint32 freeSpace = 0;

    // Check backpack
    for (uint8 slot = INVENTORY_SLOT_ITEM_START; slot < INVENTORY_SLOT_ITEM_END; ++slot)
    {
        Item* item = GetItemByPos(INVENTORY_SLOT_BAG_0, slot);
        if (!item)
            freeSpace += 1;
    }

    // Check bags
    for (uint8 i = INVENTORY_SLOT_BAG_START; i < INVENTORY_SLOT_BAG_END; i++)
    {
        if (Bag* bag = GetBagByPos(i))
            freeSpace += bag->GetFreeSlots();
    }

    return freeSpace;
}

Item* Player::GetWeaponForAttack(WeaponAttackType attackType, bool useable /*= false*/) const
{
    uint8 slot;
    switch (attackType)
    {
        case BASE_ATTACK:   slot = EQUIPMENT_SLOT_MAINHAND; break;
        case OFF_ATTACK:    slot = EQUIPMENT_SLOT_OFFHAND;  break;
        case RANGED_ATTACK: slot = EQUIPMENT_SLOT_RANGED;   break;
        default: return nullptr;
    }

    Item* item;
    if (useable)
        item = GetUseableItemByPos(INVENTORY_SLOT_BAG_0, slot);
    else
        item = GetItemByPos(INVENTORY_SLOT_BAG_0, slot);
    if (!item || item->GetTemplate()->Class != ITEM_CLASS_WEAPON)
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
    if (!item || item->GetTemplate()->Class != ITEM_CLASS_ARMOR)
        return nullptr;

    if (!useable)
        return item;

    if (item->IsBroken())
        return nullptr;

    return item;
}

WeaponAttackType Player::GetAttackBySlot(uint8 slot)
{
    switch (slot)
    {
        case EQUIPMENT_SLOT_MAINHAND: return BASE_ATTACK;
        case EQUIPMENT_SLOT_OFFHAND:  return OFF_ATTACK;
        case EQUIPMENT_SLOT_RANGED:   return RANGED_ATTACK;
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
    if (bag == INVENTORY_SLOT_BAG_0 && (slot >= KEYRING_SLOT_START && slot < CURRENCYTOKEN_SLOT_END))
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

        // keyring slots
        if (slot >= KEYRING_SLOT_START && slot < KEYRING_SLOT_END)
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
    for (uint8 i = KEYRING_SLOT_START; i < CURRENCYTOKEN_SLOT_END; ++i)
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
    if (pProto && pProto->GemProperties)
    {
        for (uint8 i = EQUIPMENT_SLOT_START; i < EQUIPMENT_SLOT_END; ++i)
        {
            if (i == except_slot)
                continue;

            Item* pItem = GetItemByPos(INVENTORY_SLOT_BAG_0, i);
            if (pItem && pItem->GetTemplate()->Socket[0].Color)
            {
                tempcount += pItem->GetGemCountWithID(item);
                if (tempcount >= count)
                    return true;
            }
        }
    }

    return false;
}

bool Player::HasItemWithLimitCategoryEquipped(uint32 limitCategory, uint32 count, uint8 except_slot) const
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

        if (pProto->ItemLimitCategory == limitCategory)
        {
            tempcount += pItem->GetCount();
            if (tempcount >= count)
                return true;
        }
    }

    return false;
}

bool Player::HasGemWithLimitCategoryEquipped(uint32 limitCategory, uint32 count, uint8 except_slot) const
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

        if (pProto->Socket[0].Color || pItem->GetEnchantmentId(PRISMATIC_ENCHANTMENT_SLOT))
        {
            tempcount += pItem->GetGemCountWithLimitCategory(limitCategory);
            if (tempcount >= count)
                return true;
        }
    }

    return false;
}

InventoryResult Player::CanTakeMoreSimilarItems(uint32 entry, uint32 count, Item* pItem, uint32* no_space_count /*= nullptr*/, uint32* itemLimitCategory /*= nullptr*/) const
{
    ItemTemplate const* pProto = sObjectMgr->GetItemTemplate(entry);
    if (!pProto)
    {
        if (no_space_count)
            *no_space_count = count;
        return EQUIP_ERR_CANT_CARRY_MORE_OF_THIS;
    }

    if (pItem && pItem->m_lootGenerated)
        return EQUIP_ERR_ALREADY_LOOTED;

    // no maximum
    if ((pProto->MaxCount <= 0 && pProto->ItemLimitCategory == 0) || pProto->MaxCount == 2147483647)
        return EQUIP_ERR_OK;

    if (pProto->MaxCount > 0)
    {
        uint32 curcount = GetItemCount(pProto->ItemId, true, pItem);
        if (curcount + count > uint32(pProto->MaxCount))
        {
            if (no_space_count)
                *no_space_count = count + curcount - pProto->MaxCount;
            return EQUIP_ERR_CANT_CARRY_MORE_OF_THIS;
        }
    }

    // check unique-equipped limit
    if (pProto->ItemLimitCategory)
    {
        ItemLimitCategoryEntry const* limitEntry = sItemLimitCategoryStore.LookupEntry(pProto->ItemLimitCategory);
        if (!limitEntry)
        {
            if (no_space_count)
                *no_space_count = count;
            return EQUIP_ERR_ITEM_CANT_BE_EQUIPPED;
        }

        if (limitEntry->mode == ITEM_LIMIT_CATEGORY_MODE_HAVE)
        {
            uint32 curcount = GetItemCountWithLimitCategory(pProto->ItemLimitCategory, pItem);
            if (curcount + count > uint32(limitEntry->maxCount))
            {
                if (no_space_count)
                    *no_space_count = count + curcount - limitEntry->maxCount;
                if (itemLimitCategory)
                    *itemLimitCategory = pProto->ItemLimitCategory;
                return EQUIP_ERR_ITEM_MAX_LIMIT_CATEGORY_COUNT_EXCEEDED;
            }
        }
    }

    return EQUIP_ERR_OK;
}

InventoryResult Player::CanTakeMoreSimilarItems(Item* pItem, uint32* itemLimitCategory /*= nullptr*/) const
{
    return CanTakeMoreSimilarItems(pItem->GetEntry(), pItem->GetCount(), pItem, nullptr, itemLimitCategory);
}

InventoryResult Player::CanStoreNewItem(uint8 bag, uint8 slot, ItemPosCountVec& dest, uint32 item, uint32 count, uint32* no_space_count /*= nullptr*/) const
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
    Item* pItem;
    for (uint8 i = EQUIPMENT_SLOT_START; i < INVENTORY_SLOT_ITEM_END; ++i)
    {
        pItem = GetUseableItemByPos(INVENTORY_SLOT_BAG_0, i);
        if (pItem && IsTotemCategoryCompatiableWith(pItem->GetTemplate()->TotemCategory, TotemCategory))
            return true;
    }
    for (uint8 i = KEYRING_SLOT_START; i < CURRENCYTOKEN_SLOT_END; ++i)
    {
        pItem = GetUseableItemByPos(INVENTORY_SLOT_BAG_0, i);
        if (pItem && IsTotemCategoryCompatiableWith(pItem->GetTemplate()->TotemCategory, TotemCategory))
            return true;
    }
    for (uint8 i = INVENTORY_SLOT_BAG_START; i < INVENTORY_SLOT_BAG_END; ++i)
    {
        if (Bag* pBag = GetBagByPos(i))
        {
            for (uint32 j = 0; j < pBag->GetBagSize(); ++j)
            {
                pItem = GetUseableItemByPos(i, j);
                if (pItem && IsTotemCategoryCompatiableWith(pItem->GetTemplate()->TotemCategory, TotemCategory))
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
        return EQUIP_ERR_CAN_ONLY_DO_WITH_EMPTY_BAGS;

    // empty specific slot - check item fit to slot
    if (!pItem2 || swap)
    {
        if (bag == INVENTORY_SLOT_BAG_0)
        {
            // keyring case
            if (slot >= KEYRING_SLOT_START && slot < KEYRING_SLOT_START+GetMaxKeyringSize() && !(pProto->BagFamily & BAG_FAMILY_MASK_KEYS))
                return EQUIP_ERR_ITEM_DOESNT_GO_INTO_BAG;

            // currencytoken case
            if (slot >= CURRENCYTOKEN_SLOT_START && slot < CURRENCYTOKEN_SLOT_END && !(pProto->IsCurrencyToken()))
                return EQUIP_ERR_ITEM_DOESNT_GO_INTO_BAG;

            // prevent cheating
            if ((slot >= BUYBACK_SLOT_START && slot < BUYBACK_SLOT_END) || slot >= PLAYER_SLOT_END)
                return EQUIP_ERR_ITEM_DOESNT_GO_INTO_BAG;
        }
        else
        {
            Bag* pBag = GetBagByPos(bag);
            if (!pBag)
                return EQUIP_ERR_ITEM_DOESNT_GO_INTO_BAG;

            ItemTemplate const* pBagProto = pBag->GetTemplate();
            if (!pBagProto)
                return EQUIP_ERR_ITEM_DOESNT_GO_INTO_BAG;

            if (slot >= pBagProto->ContainerSlots)
                return EQUIP_ERR_ITEM_DOESNT_GO_INTO_BAG;

            if (!ItemCanGoIntoBag(pProto, pBagProto))
                return EQUIP_ERR_ITEM_DOESNT_GO_INTO_BAG;
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
        return EQUIP_ERR_ITEM_DOESNT_GO_INTO_BAG;

    // skip non-existing bag or self targeted bag
    Bag* pBag = GetBagByPos(bag);
    if (!pBag || pBag == pSrcItem)
        return EQUIP_ERR_ITEM_DOESNT_GO_INTO_BAG;

    if (pSrcItem && pSrcItem->IsNotEmptyBag())
        return EQUIP_ERR_CAN_ONLY_DO_WITH_EMPTY_BAGS;

    ItemTemplate const* pBagProto = pBag->GetTemplate();
    if (!pBagProto)
        return EQUIP_ERR_ITEM_DOESNT_GO_INTO_BAG;

    // specialized bag mode or non-specialized
    if (non_specialized != (pBagProto->Class == ITEM_CLASS_CONTAINER && pBagProto->SubClass == ITEM_SUBCLASS_CONTAINER))
        return EQUIP_ERR_ITEM_DOESNT_GO_INTO_BAG;

    if (!ItemCanGoIntoBag(pProto, pBagProto))
        return EQUIP_ERR_ITEM_DOESNT_GO_INTO_BAG;

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
            if (pItem2->CanBeMergedPartlyWith(pProto) != EQUIP_ERR_OK)
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
        return EQUIP_ERR_CAN_ONLY_DO_WITH_EMPTY_BAGS;

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
            if (pItem2->CanBeMergedPartlyWith(pProto) != EQUIP_ERR_OK)
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
        return swap ? EQUIP_ERR_ITEMS_CANT_BE_SWAPPED : EQUIP_ERR_ITEM_NOT_FOUND;
    }

    if (pItem)
    {
        // item used
        if (pItem->m_lootGenerated)
        {
            if (no_space_count)
                *no_space_count = count;
            return EQUIP_ERR_ALREADY_LOOTED;
        }

        if (pItem->IsBindedNotWith(this))
        {
            if (no_space_count)
                *no_space_count = count;
            return EQUIP_ERR_DONT_OWN_THAT_ITEM;
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
            return EQUIP_ERR_CANT_CARRY_MORE_OF_THIS;
        }
    }

    // not specific slot or have space for partly store only in specific slot

    // in specific bag
    if (bag != NULL_BAG)
    {
        // search stack in bag for merge to
        if (pProto->Stackable != 1)
        {
            if (bag == INVENTORY_SLOT_BAG_0)               // inventory
            {
                res = CanStoreItem_InInventorySlots(KEYRING_SLOT_START, CURRENCYTOKEN_SLOT_END, dest, pProto, count, true, pItem, bag, slot);
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
                    return EQUIP_ERR_CANT_CARRY_MORE_OF_THIS;
                }

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
                    return EQUIP_ERR_CANT_CARRY_MORE_OF_THIS;
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
                    return EQUIP_ERR_CANT_CARRY_MORE_OF_THIS;
                }
            }
        }

        // search free slot in bag for place to
        if (bag == INVENTORY_SLOT_BAG_0)                     // inventory
        {
            // search free slot - keyring case
            if (pProto->BagFamily & BAG_FAMILY_MASK_KEYS)
            {
                uint32 keyringSize = GetMaxKeyringSize();
                res = CanStoreItem_InInventorySlots(KEYRING_SLOT_START, KEYRING_SLOT_START+keyringSize, dest, pProto, count, false, pItem, bag, slot);
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
                    return EQUIP_ERR_CANT_CARRY_MORE_OF_THIS;
                }

                res = CanStoreItem_InInventorySlots(CURRENCYTOKEN_SLOT_START, CURRENCYTOKEN_SLOT_END, dest, pProto, count, false, pItem, bag, slot);
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
                    return EQUIP_ERR_CANT_CARRY_MORE_OF_THIS;
                }
            }
            else if (pProto->IsCurrencyToken())
            {
                res = CanStoreItem_InInventorySlots(CURRENCYTOKEN_SLOT_START, CURRENCYTOKEN_SLOT_END, dest, pProto, count, false, pItem, bag, slot);
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
                    return EQUIP_ERR_CANT_CARRY_MORE_OF_THIS;
                }
            }

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
                return EQUIP_ERR_CANT_CARRY_MORE_OF_THIS;
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
                return EQUIP_ERR_CANT_CARRY_MORE_OF_THIS;
            }
        }
    }

    // not specific bag or have space for partly store only in specific bag

    // search stack for merge to
    if (pProto->Stackable != 1)
    {
        res = CanStoreItem_InInventorySlots(KEYRING_SLOT_START, CURRENCYTOKEN_SLOT_END, dest, pProto, count, true, pItem, bag, slot);
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
            return EQUIP_ERR_CANT_CARRY_MORE_OF_THIS;
        }

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
            return EQUIP_ERR_CANT_CARRY_MORE_OF_THIS;
        }

        if (pProto->BagFamily)
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
                    return EQUIP_ERR_CANT_CARRY_MORE_OF_THIS;
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
                return EQUIP_ERR_CANT_CARRY_MORE_OF_THIS;
            }
        }
    }

    // search free slot - special bag case
    if (pProto->BagFamily)
    {
        if (pProto->BagFamily & BAG_FAMILY_MASK_KEYS)
        {
            uint32 keyringSize = GetMaxKeyringSize();
            res = CanStoreItem_InInventorySlots(KEYRING_SLOT_START, KEYRING_SLOT_START+keyringSize, dest, pProto, count, false, pItem, bag, slot);
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
                return EQUIP_ERR_CANT_CARRY_MORE_OF_THIS;
            }
        }
        else if (pProto->IsCurrencyToken())
        {
            res = CanStoreItem_InInventorySlots(CURRENCYTOKEN_SLOT_START, CURRENCYTOKEN_SLOT_END, dest, pProto, count, false, pItem, bag, slot);
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
                return EQUIP_ERR_CANT_CARRY_MORE_OF_THIS;
            }
        }

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
                return EQUIP_ERR_CANT_CARRY_MORE_OF_THIS;
            }
        }
    }

    if (pItem && pItem->IsNotEmptyBag())
        return EQUIP_ERR_NONEMPTY_BAG_OVER_OTHER_BAG;

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
        return EQUIP_ERR_CANT_CARRY_MORE_OF_THIS;
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
            return EQUIP_ERR_CANT_CARRY_MORE_OF_THIS;
        }
    }

    if (no_space_count)
        *no_space_count = count + no_similar_count;

    return EQUIP_ERR_INVENTORY_FULL;
}

//////////////////////////////////////////////////////////////////////////
InventoryResult Player::CanStoreItems(Item** items, int count, uint32* itemLimitCategory) const
{
    Item* item2;

    // fill space table
    uint32 inventoryCounts[INVENTORY_SLOT_ITEM_END - INVENTORY_SLOT_ITEM_START];
    uint32 bagCounts[INVENTORY_SLOT_BAG_END - INVENTORY_SLOT_BAG_START][MAX_BAG_SIZE];
    uint32 keyringCounts[KEYRING_SLOT_END - KEYRING_SLOT_START];
    uint32 currencyCounts[CURRENCYTOKEN_SLOT_END - CURRENCYTOKEN_SLOT_START];

    memset(inventoryCounts, 0, sizeof(uint32) * (INVENTORY_SLOT_ITEM_END - INVENTORY_SLOT_ITEM_START));
    memset(bagCounts, 0, sizeof(uint32) * (INVENTORY_SLOT_BAG_END - INVENTORY_SLOT_BAG_START) * MAX_BAG_SIZE);
    memset(keyringCounts, 0, sizeof(uint32) * (KEYRING_SLOT_END - KEYRING_SLOT_START));
    memset(currencyCounts, 0, sizeof(uint32) * (CURRENCYTOKEN_SLOT_END - CURRENCYTOKEN_SLOT_START));

    for (uint8 i = INVENTORY_SLOT_ITEM_START; i < INVENTORY_SLOT_ITEM_END; i++)
    {
        item2 = GetItemByPos(INVENTORY_SLOT_BAG_0, i);
        if (item2 && !item2->IsInTrade())
            inventoryCounts[i - INVENTORY_SLOT_ITEM_START] = item2->GetCount();
    }

    for (uint8 i = KEYRING_SLOT_START; i < KEYRING_SLOT_END; i++)
    {
        item2 = GetItemByPos(INVENTORY_SLOT_BAG_0, i);
        if (item2 && !item2->IsInTrade())
            keyringCounts[i - KEYRING_SLOT_START] = item2->GetCount();
    }

    for (uint8 i = CURRENCYTOKEN_SLOT_START; i < CURRENCYTOKEN_SLOT_END; i++)
    {
        item2 = GetItemByPos(INVENTORY_SLOT_BAG_0, i);
        if (item2 && !item2->IsInTrade())
            currencyCounts[i - CURRENCYTOKEN_SLOT_START] = item2->GetCount();
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
            return EQUIP_ERR_ALREADY_LOOTED;

        // item it 'bind'
        if (item->IsBindedNotWith(this))
            return EQUIP_ERR_DONT_OWN_THAT_ITEM;

        ItemTemplate const* pBagProto;

        // item is 'one item only'
        InventoryResult res = CanTakeMoreSimilarItems(item, itemLimitCategory);
        if (res != EQUIP_ERR_OK)
            return res;

        // search stack for merge to
        if (pProto->Stackable != 1)
        {
            bool b_found = false;

            for (uint8 t = KEYRING_SLOT_START; t < KEYRING_SLOT_END; ++t)
            {
                item2 = GetItemByPos(INVENTORY_SLOT_BAG_0, t);
                if (item2 && item2->CanBeMergedPartlyWith(pProto) == EQUIP_ERR_OK && keyringCounts[t-KEYRING_SLOT_START] + item->GetCount() <= pProto->GetMaxStackSize())
                {
                    keyringCounts[t-KEYRING_SLOT_START] += item->GetCount();
                    b_found = true;
                    break;
                }
            }
            if (b_found)
                continue;

            for (int t = CURRENCYTOKEN_SLOT_START; t < CURRENCYTOKEN_SLOT_END; ++t)
            {
                item2 = GetItemByPos(INVENTORY_SLOT_BAG_0, t);
                if (item2 && item2->CanBeMergedPartlyWith(pProto) == EQUIP_ERR_OK && currencyCounts[t-CURRENCYTOKEN_SLOT_START] + item->GetCount() <= pProto->GetMaxStackSize())
                {
                    currencyCounts[t-CURRENCYTOKEN_SLOT_START] += item->GetCount();
                    b_found = true;
                    break;
                }
            }
            if (b_found)
                continue;

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
        if (pProto->BagFamily)
        {
            bool b_found = false;
            if (pProto->BagFamily & BAG_FAMILY_MASK_KEYS)
            {
                uint32 keyringSize = GetMaxKeyringSize();
                for (uint32 t = KEYRING_SLOT_START; t < KEYRING_SLOT_START+keyringSize; ++t)
                {
                    if (keyringCounts[t-KEYRING_SLOT_START] == 0)
                    {
                        keyringCounts[t-KEYRING_SLOT_START] = 1;
                        b_found = true;
                        break;
                    }
                }
            }

            if (b_found)
                continue;

            if (pProto->IsCurrencyToken())
            {
                for (uint32 t = CURRENCYTOKEN_SLOT_START; t < CURRENCYTOKEN_SLOT_END; ++t)
                {
                    if (currencyCounts[t-CURRENCYTOKEN_SLOT_START] == 0)
                    {
                        currencyCounts[t-CURRENCYTOKEN_SLOT_START] = 1;
                        b_found = true;
                        break;
                    }
                }
            }

            if (b_found)
                continue;

            for (int t = INVENTORY_SLOT_BAG_START; !b_found && t < INVENTORY_SLOT_BAG_END; ++t)
            {
                if (Bag* bag = GetBagByPos(t))
                {
                    pBagProto = bag->GetTemplate();

                    // not plain container check
                    if (pBagProto && (pBagProto->Class != ITEM_CLASS_CONTAINER || pBagProto->SubClass != ITEM_SUBCLASS_CONTAINER) &&
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
        for (uint8 t = INVENTORY_SLOT_BAG_START; !b_found && t < INVENTORY_SLOT_BAG_END; ++t)
        {
            if (Bag* bag = GetBagByPos(t))
            {
                pBagProto = bag->GetTemplate();

                // special bag already checked
                if (pBagProto && (pBagProto->Class != ITEM_CLASS_CONTAINER || pBagProto->SubClass != ITEM_SUBCLASS_CONTAINER))
                    continue;

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
                return EQUIP_ERR_ALREADY_LOOTED;

            if (pItem->IsBindedNotWith(this))
                return EQUIP_ERR_DONT_OWN_THAT_ITEM;

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
                    return EQUIP_ERR_YOU_ARE_STUNNED;

                if (IsCharmed())
                    return EQUIP_ERR_CANT_DO_RIGHT_NOW; // @todo is this the correct error?

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

                if (IsInCombat()&& (pProto->Class == ITEM_CLASS_WEAPON || pProto->InventoryType == INVTYPE_RELIC) && m_weaponChangeTimer != 0)
                    return EQUIP_ERR_CANT_DO_RIGHT_NOW;         // maybe exist better err

                if (IsNonMeleeSpellCast(false))
                    return EQUIP_ERR_CANT_DO_RIGHT_NOW;
            }

            ScalingStatDistributionEntry const* ssd = pProto->ScalingStatDistribution ? sScalingStatDistributionStore.LookupEntry(pProto->ScalingStatDistribution) : 0;
            // check allowed level (extend range to upper values if MaxLevel more or equal max player level, this let GM set high level with 1...max range items)
            if (ssd && ssd->MaxLevel < DEFAULT_MAX_LEVEL && ssd->MaxLevel < GetLevel())
                return EQUIP_ERR_ITEM_CANT_BE_EQUIPPED;

            uint8 eslot = FindEquipSlot(pProto, slot, swap);
            if (eslot == NULL_SLOT)
                return EQUIP_ERR_ITEM_CANT_BE_EQUIPPED;

            res = CanUseItem(pItem, not_loading);
            if (res != EQUIP_ERR_OK)
                return res;

            if (!swap && GetItemByPos(INVENTORY_SLOT_BAG_0, eslot))
                return EQUIP_ERR_NO_EQUIPMENT_SLOT_AVAILABLE;

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
            if (pProto->Class == ITEM_CLASS_QUIVER)
                for (uint8 i = INVENTORY_SLOT_BAG_START; i < INVENTORY_SLOT_BAG_END; ++i)
                    if (Item* pBag = GetItemByPos(INVENTORY_SLOT_BAG_0, i))
                        if (pBag != pItem)
                            if (ItemTemplate const* pBagProto = pBag->GetTemplate())
                                if (pBagProto->Class == pProto->Class && (!swap || pBag->GetSlot() != eslot))
                                    return (pBagProto->SubClass == ITEM_SUBCLASS_AMMO_POUCH)
                                        ? EQUIP_ERR_CAN_EQUIP_ONLY1_AMMOPOUCH
                                        : EQUIP_ERR_CAN_EQUIP_ONLY1_QUIVER;

            uint32 type = pProto->InventoryType;

            if (eslot == EQUIPMENT_SLOT_OFFHAND)
            {
                // Do not allow polearm to be equipped in the offhand (rare case for the only 1h polearm 41750)
                if (type == INVTYPE_WEAPON && pProto->SubClass == ITEM_SUBCLASS_WEAPON_POLEARM)
                    return EQUIP_ERR_ITEM_DOESNT_GO_TO_SLOT;

                else if (type == INVTYPE_WEAPON || type == INVTYPE_WEAPONOFFHAND)
                {
                    if (!CanDualWield())
                        return EQUIP_ERR_CANT_DUAL_WIELD;
                }
                else if (type == INVTYPE_2HWEAPON)
                {
                    if (!CanDualWield() || !CanTitanGrip())
                        return EQUIP_ERR_CANT_DUAL_WIELD;
                }

                if (IsTwoHandUsed())
                    return EQUIP_ERR_CANT_EQUIP_WITH_TWOHANDED;
            }

            // equip two-hand weapon case (with possible unequip 2 items)
            if (type == INVTYPE_2HWEAPON)
            {
                if (eslot == EQUIPMENT_SLOT_OFFHAND)
                {
                    if (!CanTitanGrip())
                        return EQUIP_ERR_ITEM_CANT_BE_EQUIPPED;
                }
                else if (eslot != EQUIPMENT_SLOT_MAINHAND)
                    return EQUIP_ERR_ITEM_CANT_BE_EQUIPPED;

                if (!CanTitanGrip())
                {
                    // offhand item must can be stored in inventory for offhand item and it also must be unequipped
                    Item* offItem = GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND);
                    ItemPosCountVec off_dest;
                    if (offItem && (!not_loading ||
                        CanUnequipItem(uint16(INVENTORY_SLOT_BAG_0) << 8 | EQUIPMENT_SLOT_OFFHAND, false) != EQUIP_ERR_OK ||
                        CanStoreItem(NULL_BAG, NULL_SLOT, off_dest, offItem, false) != EQUIP_ERR_OK))
                        return swap ? EQUIP_ERR_ITEMS_CANT_BE_SWAPPED : EQUIP_ERR_INVENTORY_FULL;
                }
            }
            dest = ((INVENTORY_SLOT_BAG_0 << 8) | eslot);
            return EQUIP_ERR_OK;
        }
    }

    return !swap ? EQUIP_ERR_ITEM_NOT_FOUND : EQUIP_ERR_ITEMS_CANT_BE_SWAPPED;
}

InventoryResult Player::CanUnequipItem(uint16 pos, bool swap) const
{
    // Applied only to equipped items and bank bags
    if (!IsEquipmentPos(pos) && !IsBagPos(pos))
        return EQUIP_ERR_OK;

    Item* pItem = GetItemByPos(pos);

    // Applied only to existing equipped item
    if (!pItem)
        return EQUIP_ERR_OK;

    TC_LOG_DEBUG("entities.player.items", "Player::CanUnequipItem: Player '%s' (%s), Slot: %u, Item: %u, Count: %u",
        GetName().c_str(), GetGUID().ToString().c_str(), pos, pItem->GetEntry(), pItem->GetCount());

    ItemTemplate const* pProto = pItem->GetTemplate();
    if (!pProto)
        return EQUIP_ERR_ITEM_NOT_FOUND;

    // item used
    if (pItem->m_lootGenerated)
        return EQUIP_ERR_ALREADY_LOOTED;

    if (IsCharmed())
        return EQUIP_ERR_CANT_DO_RIGHT_NOW; // @todo is this the correct error?

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
        return EQUIP_ERR_CAN_ONLY_DO_WITH_EMPTY_BAGS;

    return EQUIP_ERR_OK;
}

InventoryResult Player::CanBankItem(uint8 bag, uint8 slot, ItemPosCountVec &dest, Item* pItem, bool swap, bool not_loading) const
{
    if (!pItem)
        return swap ? EQUIP_ERR_ITEMS_CANT_BE_SWAPPED : EQUIP_ERR_ITEM_NOT_FOUND;

    uint32 count = pItem->GetCount();

    TC_LOG_DEBUG("entities.player.items", "Player::CanBankItem: Player '%s' (%s), Bag: %u, Slot: %u, Item: %u, Count: %u",
        GetName().c_str(), GetGUID().ToString().c_str(), bag, slot, pItem->GetEntry(), pItem->GetCount());
    ItemTemplate const* pProto = pItem->GetTemplate();
    if (!pProto)
        return swap ? EQUIP_ERR_ITEMS_CANT_BE_SWAPPED : EQUIP_ERR_ITEM_NOT_FOUND;

    // item used
    if (pItem->m_lootGenerated)
        return EQUIP_ERR_ALREADY_LOOTED;

    if (pItem->IsBindedNotWith(this))
        return EQUIP_ERR_DONT_OWN_THAT_ITEM;

    // Currency tokens are not supposed to be swapped out of their hidden bag
    uint8 pItemslot = pItem->GetSlot();
    if (pItemslot >= CURRENCYTOKEN_SLOT_START && pItemslot < CURRENCYTOKEN_SLOT_END)
    {
        TC_LOG_ERROR("entities.player.cheat", "Possible hacking attempt: Player %s (%s) tried to move token [%s entry: %u] out of the currency bag!",
            GetName().c_str(), GetGUID().ToString().c_str(), pItem->GetGUID().ToString().c_str(), pProto->ItemId);
        return EQUIP_ERR_ITEMS_CANT_BE_SWAPPED;
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
                return EQUIP_ERR_ITEM_DOESNT_GO_TO_SLOT;

            if (slot - BANK_SLOT_BAG_START >= GetBankBagSlotCount())
                return EQUIP_ERR_MUST_PURCHASE_THAT_BAG_SLOT;

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
            return EQUIP_ERR_NONEMPTY_BAG_OVER_OTHER_BAG;

        // search stack in bag for merge to
        if (pProto->Stackable != 1)
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
    if (pProto->Stackable != 1)
    {
        // in slots
        res = CanStoreItem_InInventorySlots(BANK_SLOT_ITEM_START, BANK_SLOT_ITEM_END, dest, pProto, count, true, pItem, bag, slot);
        if (res != EQUIP_ERR_OK)
            return res;

        if (count == 0)
            return EQUIP_ERR_OK;

        // in special bags
        if (pProto->BagFamily)
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
    if (pProto->BagFamily)
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
            return EQUIP_ERR_YOU_ARE_DEAD;

        //if (isStunned())
        //    return EQUIP_ERR_YOU_ARE_STUNNED;

        ItemTemplate const* pProto = pItem->GetTemplate();
        if (pProto)
        {
            if (pItem->IsBindedNotWith(this))
                return EQUIP_ERR_DONT_OWN_THAT_ITEM;

            InventoryResult res = CanUseItem(pProto);
            if (res != EQUIP_ERR_OK)
                return res;

            if (pItem->GetSkill() != 0)
            {
                bool allowEquip = false;
                uint32 itemSkill = pItem->GetSkill();
                // Armor that is binded to account can "morph" from plate to mail, etc. if skill is not learned yet.
                if (pProto->Quality == ITEM_QUALITY_HEIRLOOM && pProto->Class == ITEM_CLASS_ARMOR && !HasSkill(itemSkill))
                {
                    /// @todo when you right-click already equipped item it throws EQUIP_ERR_NO_REQUIRED_PROFICIENCY.

                    // In fact it's a visual bug, everything works properly... I need sniffs of operations with
                    // binded to account items from off server.

                    switch (GetClass())
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
                    return EQUIP_ERR_NO_REQUIRED_PROFICIENCY;
            }

            if (pProto->RequiredReputationFaction && uint32(GetReputationRank(pProto->RequiredReputationFaction)) < pProto->RequiredReputationRank)
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

    if (((proto->Flags2 & ITEM_FLAG2_FACTION_HORDE) && GetTeam() != HORDE) ||
        (((proto->Flags2 & ITEM_FLAG2_FACTION_ALLIANCE) && GetTeam() != ALLIANCE)))
        return EQUIP_ERR_YOU_CAN_NEVER_USE_THAT_ITEM;

    if ((proto->AllowableClass & GetClassMask()) == 0 || (proto->AllowableRace & GetRaceMask()) == 0)
        return EQUIP_ERR_YOU_CAN_NEVER_USE_THAT_ITEM;

    if (proto->RequiredSkill != 0)
    {
        if (GetSkillValue(proto->RequiredSkill) == 0)
            return EQUIP_ERR_NO_REQUIRED_PROFICIENCY;
        else if (GetSkillValue(proto->RequiredSkill) < proto->RequiredSkillRank)
            return EQUIP_ERR_CANT_EQUIP_SKILL;
    }

    if (proto->RequiredSpell != 0 && !HasSpell(proto->RequiredSpell))
        return EQUIP_ERR_NO_REQUIRED_PROFICIENCY;

    if (GetLevel() < proto->RequiredLevel)
        return EQUIP_ERR_CANT_EQUIP_LEVEL_I;

    // If World Event is not active, prevent using event dependant items
    if (proto->HolidayId && !IsHolidayActive((HolidayIds)proto->HolidayId))
        return EQUIP_ERR_CANT_DO_RIGHT_NOW;

    // learning (recipes, mounts, pets, etc.)
    if (proto->Spells[0].SpellId == 483 || proto->Spells[0].SpellId == 55884)
        if (HasSpell(proto->Spells[1].SpellId))
            return EQUIP_ERR_NONE;

    return EQUIP_ERR_OK;
}

InventoryResult Player::CanRollForItemInLFG(ItemTemplate const* proto, WorldObject const* lootedObject) const
{
    if (!GetGroup() || !GetGroup()->isLFGGroup())
        return EQUIP_ERR_OK;    // not in LFG group

    // check if looted object is inside the lfg dungeon
    Map const* map = lootedObject->GetMap();
    if (!sLFGMgr->inLfgDungeonMap(GetGroup()->GetGUID(), map->GetId(), map->GetDifficulty()))
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

    if ((proto->AllowableClass & GetClassMask()) == 0 || (proto->AllowableRace & GetRaceMask()) == 0)
        return EQUIP_ERR_YOU_CAN_NEVER_USE_THAT_ITEM;

    if (proto->RequiredSpell != 0 && !HasSpell(proto->RequiredSpell))
        return EQUIP_ERR_NO_REQUIRED_PROFICIENCY;

    if (proto->RequiredSkill != 0)
    {
        if (!GetSkillValue(proto->RequiredSkill))
            return EQUIP_ERR_NO_REQUIRED_PROFICIENCY;
        else if (GetSkillValue(proto->RequiredSkill) < proto->RequiredSkillRank)
            return EQUIP_ERR_CANT_EQUIP_SKILL;
    }

    uint8 _class = GetClass();

    if (proto->Class == ITEM_CLASS_WEAPON && GetSkillValue(item_weapon_skills[proto->SubClass]) == 0)
        return EQUIP_ERR_NO_REQUIRED_PROFICIENCY;

    if (proto->Class == ITEM_CLASS_ARMOR && proto->SubClass > ITEM_SUBCLASS_ARMOR_MISC && proto->SubClass < ITEM_SUBCLASS_ARMOR_BUCKLER && proto->InventoryType != INVTYPE_CLOAK)
    {
        if (_class == CLASS_WARRIOR || _class == CLASS_PALADIN || _class == CLASS_DEATH_KNIGHT)
        {
            if (GetLevel() < 40)
            {
                if (proto->SubClass != ITEM_SUBCLASS_ARMOR_MAIL)
                    return EQUIP_ERR_CANT_DO_RIGHT_NOW;
            }
            else if (proto->SubClass != ITEM_SUBCLASS_ARMOR_PLATE)
                return EQUIP_ERR_CANT_DO_RIGHT_NOW;
        }
        else if (_class == CLASS_HUNTER || _class == CLASS_SHAMAN)
        {
            if (GetLevel() < 40)
            {
                if (proto->SubClass != ITEM_SUBCLASS_ARMOR_LEATHER)
                    return EQUIP_ERR_CANT_DO_RIGHT_NOW;
            }
            else if (proto->SubClass != ITEM_SUBCLASS_ARMOR_MAIL)
                return EQUIP_ERR_CANT_DO_RIGHT_NOW;
        }

        if (_class == CLASS_ROGUE || _class == CLASS_DRUID)
            if (proto->SubClass != ITEM_SUBCLASS_ARMOR_LEATHER)
                return EQUIP_ERR_CANT_DO_RIGHT_NOW;

        if (_class == CLASS_MAGE || _class == CLASS_PRIEST || _class == CLASS_WARLOCK)
            if (proto->SubClass != ITEM_SUBCLASS_ARMOR_CLOTH)
                return EQUIP_ERR_CANT_DO_RIGHT_NOW;
    }

    return EQUIP_ERR_OK;
}

InventoryResult Player::CanUseAmmo(uint32 item) const
{
    TC_LOG_DEBUG("entities.player.items", "STORAGE: CanUseAmmo item = %u", item);
    if (!IsAlive())
        return EQUIP_ERR_YOU_ARE_DEAD;
    //if (isStunned())
    //    return EQUIP_ERR_YOU_ARE_STUNNED;
    ItemTemplate const* pProto = sObjectMgr->GetItemTemplate(item);
    if (pProto)
    {
        if (pProto->InventoryType!= INVTYPE_AMMO)
            return EQUIP_ERR_ONLY_AMMO_CAN_GO_HERE;

        InventoryResult res = CanUseItem(pProto);
        if (res != EQUIP_ERR_OK)
            return res;

        /*if (GetReputationMgr().GetReputation() < pProto->RequiredReputation)
        return EQUIP_ERR_CANT_EQUIP_REPUTATION;
        */

        // Requires No Ammo
        if (HasAura(46699))
            return EQUIP_ERR_BAG_FULL6;

        return EQUIP_ERR_OK;
    }
    return EQUIP_ERR_ITEM_NOT_FOUND;
}

void Player::SetAmmo(uint32 item)
{
    if (!item)
        return;

    // already set
    if (GetUInt32Value(PLAYER_AMMO_ID) == item)
        return;

    // check ammo
    InventoryResult msg = CanUseAmmo(item);
    if (msg != EQUIP_ERR_OK)
    {
        SendEquipError(msg, nullptr, nullptr, item);
        return;
    }

    SetUInt32Value(PLAYER_AMMO_ID, item);

    _ApplyAmmoBonuses();
}

void Player::RemoveAmmo()
{
    SetUInt32Value(PLAYER_AMMO_ID, 0);

    m_ammoDPS = 0.0f;

    if (CanModifyStats())
        UpdateDamagePhysical(RANGED_ATTACK);
}

// Return stored item (if stored to stack, it can diff. from pItem). And pItem ca be deleted in this case.
Item* Player::StoreNewItem(ItemPosCountVec const& dest, uint32 item, bool update, int32 randomPropertyId, GuidSet const& allowedLooters)
{
    uint32 count = 0;
    for (ItemPosCountVec::const_iterator itr = dest.begin(); itr != dest.end(); ++itr)
        count += itr->count;

    Item* pItem = Item::CreateItem(item, count, this);
    if (pItem)
    {
        ItemAddedQuestCheck(item, count);
        UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_RECEIVE_EPIC_ITEM, item, count);
        UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_OWN_ITEM, item, count);
        if (randomPropertyId)
            pItem->SetItemRandomProperties(randomPropertyId);
        pItem = StoreItem(dest, pItem, update);

        if (allowedLooters.size() > 1 && pItem->GetTemplate()->GetMaxStackSize() == 1 && pItem->IsSoulBound())
        {
            pItem->SetSoulboundTradeable(allowedLooters);
            pItem->SetUInt32Value(ITEM_FIELD_CREATE_PLAYED_TIME, GetTotalPlayedTime());
            AddTradeableItem(pItem);

            // save data
            std::ostringstream ss;
            GuidSet::const_iterator itr = allowedLooters.begin();
            ss << *itr;
            for (++itr; itr != allowedLooters.end(); ++itr)
                ss << ' ' << itr->GetCounter();

            PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_ITEM_BOP_TRADE);
            stmt->setUInt32(0, pItem->GetGUID().GetCounter());
            stmt->setString(1, ss.str());
            CharacterDatabase.Execute(stmt);
        }
    }
    return pItem;
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

        if (pItem->GetTemplate()->Bonding == BIND_WHEN_PICKED_UP ||
            pItem->GetTemplate()->Bonding == BIND_QUEST_ITEM ||
            (pItem->GetTemplate()->Bonding == BIND_WHEN_EQUIPED && IsBagPos(pos)))
            pItem->SetBinding(true);

        Bag* pBag = (bag == INVENTORY_SLOT_BAG_0) ? nullptr : GetBagByPos(bag);
        if (!pBag)
        {
            m_items[slot] = pItem;
            SetGuidValue(PLAYER_FIELD_INV_SLOT_HEAD + (slot * 2), pItem->GetGUID());
            pItem->SetGuidValue(ITEM_FIELD_CONTAINED, GetGUID());
            pItem->SetGuidValue(ITEM_FIELD_OWNER, GetGUID());

            pItem->SetSlot(slot);
            pItem->SetContainer(nullptr);

            // need update known currency
            if (slot >= CURRENCYTOKEN_SLOT_START && slot < CURRENCYTOKEN_SLOT_END)
                AddKnownCurrency(pItem->GetEntry());
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

        if (bag == INVENTORY_SLOT_BAG_0 || (bag >= INVENTORY_SLOT_BAG_START && bag < INVENTORY_SLOT_BAG_END))
            ApplyItemObtainSpells(pItem, true);

        return pItem;
    }
    else
    {
        if (pItem2->GetTemplate()->Bonding == BIND_WHEN_PICKED_UP ||
            pItem2->GetTemplate()->Bonding == BIND_QUEST_ITEM ||
            (pItem2->GetTemplate()->Bonding == BIND_WHEN_EQUIPED && IsBagPos(pos)))
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

        if (bag == INVENTORY_SLOT_BAG_0 || (bag >= INVENTORY_SLOT_BAG_START && bag < INVENTORY_SLOT_BAG_END))
            ApplyItemObtainSpells(pItem2, true);

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
            if (pProto && pProto->ItemSet)
                AddItemsSetItem(this, pItem);

            _ApplyItemMods(pItem, slot, true);

            if (pProto && IsInCombat() && (pProto->Class == ITEM_CLASS_WEAPON || pProto->InventoryType == INVTYPE_RELIC) && m_weaponChangeTimer == 0)
            {
                uint32 cooldownSpell = GetClass() == CLASS_ROGUE ? 6123 : 6119;
                SpellInfo const* spellProto = sSpellMgr->GetSpellInfo(cooldownSpell);

                if (!spellProto)
                    TC_LOG_ERROR("entities.player", "Player::EquipItem: Weapon switch cooldown spell %u for player '%s' (%s) couldn't be found in Spell.dbc",
                        cooldownSpell, GetName().c_str(), GetGUID().ToString().c_str());
                else
                {
                    m_weaponChangeTimer = spellProto->StartRecoveryTime;

                    GetSpellHistory()->AddGlobalCooldown(spellProto, m_weaponChangeTimer);
                    WorldPacket data;
                    GetSpellHistory()->BuildCooldownPacket(data, SPELL_COOLDOWN_FLAG_INCLUDE_GCD, cooldownSpell, 0);
                    SendDirectMessage(&data);
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
            case EQUIPMENT_SLOT_RANGED:
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

    if (slot == EQUIPMENT_SLOT_MAINHAND || slot == EQUIPMENT_SLOT_OFFHAND)
        CheckTitanGripPenalty();

    // only for full equip instead adding to stack
    UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_EQUIP_ITEM, pItem->GetEntry());
    UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_EQUIP_EPIC_ITEM, slot, pItem->GetEntry());

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

        if (slot == EQUIPMENT_SLOT_MAINHAND || slot == EQUIPMENT_SLOT_OFFHAND)
            CheckTitanGripPenalty();

        UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_EQUIP_ITEM, pItem->GetEntry());
        UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_EQUIP_EPIC_ITEM, slot, pItem->GetEntry());
    }
}

void Player::SetVisibleItemSlot(uint8 slot, Item* pItem)
{
    if (pItem)
    {
        SetUInt32Value(PLAYER_VISIBLE_ITEM_1_ENTRYID + (slot * 2), pItem->GetEntry());
        SetUInt16Value(PLAYER_VISIBLE_ITEM_1_ENCHANTMENT + (slot * 2), 0, pItem->GetEnchantmentId(PERM_ENCHANTMENT_SLOT));
        SetUInt16Value(PLAYER_VISIBLE_ITEM_1_ENCHANTMENT + (slot * 2), 1, pItem->GetEnchantmentId(TEMP_ENCHANTMENT_SLOT));
    }
    else
    {
        SetUInt32Value(PLAYER_VISIBLE_ITEM_1_ENTRYID + (slot * 2), 0);
        SetUInt32Value(PLAYER_VISIBLE_ITEM_1_ENCHANTMENT + (slot * 2), 0);
    }
}

void Player::VisualizeItem(uint8 slot, Item* pItem)
{
    if (!pItem)
        return;

    // check also  BIND_WHEN_PICKED_UP and BIND_QUEST_ITEM for .additem or .additemset case by GM (not binded at adding to inventory)
    if (pItem->GetTemplate()->Bonding == BIND_WHEN_EQUIPED || pItem->GetTemplate()->Bonding == BIND_WHEN_PICKED_UP || pItem->GetTemplate()->Bonding == BIND_QUEST_ITEM)
        pItem->SetBinding(true);

    TC_LOG_DEBUG("entities.player.items", "Player::SetVisibleItemSlot: Player '%s' (%s), Slot: %u, Item: %u",
        GetName().c_str(), GetGUID().ToString().c_str(), slot, pItem->GetEntry());

    m_items[slot] = pItem;
    SetGuidValue(PLAYER_FIELD_INV_SLOT_HEAD + (slot * 2), pItem->GetGUID());
    pItem->SetGuidValue(ITEM_FIELD_CONTAINED, GetGUID());
    pItem->SetGuidValue(ITEM_FIELD_OWNER, GetGUID());
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
                // item set bonuses applied only at equip and removed at unequip, and still active for broken items
                ItemTemplate const* pProto = ASSERT_NOTNULL(pItem->GetTemplate());
                if (pProto->ItemSet)
                    RemoveItemsSetItem(this, pProto);

                _ApplyItemMods(pItem, slot, false, update);

                // remove item dependent auras and casts (only weapon and armor slots)
                if (slot < EQUIPMENT_SLOT_END)
                {
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
                        case EQUIPMENT_SLOT_RANGED:
                            RecalculateRating(CR_ARMOR_PENETRATION);
                        default:
                            break;
                    }
                }
            }

            m_items[slot] = nullptr;
            SetGuidValue(PLAYER_FIELD_INV_SLOT_HEAD + (slot * 2), ObjectGuid::Empty);

            if (slot < EQUIPMENT_SLOT_END)
            {
                SetVisibleItemSlot(slot, nullptr);
                if (slot == EQUIPMENT_SLOT_MAINHAND || slot == EQUIPMENT_SLOT_OFFHAND)
                    CheckTitanGripPenalty();
            }
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
        RemoveItemFromUpdateQueueOf(it, this);
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

    // only set if not merged to existing stack (pItem can be deleted already but we can compare pointers any way)
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

            stmt->setUInt32(0, pItem->GetGUID().GetCounter());

            CharacterDatabase.Execute(stmt);
        }

        RemoveEnchantmentDurations(pItem);
        RemoveItemDurations(pItem);

        pItem->SetNotRefundable(this);
        pItem->ClearSoulboundTradeable(this);
        RemoveTradeableItem(pItem);

        ApplyItemObtainSpells(pItem, false);

        ItemRemovedQuestCheck(pItem->GetEntry(), pItem->GetCount());
        sScriptMgr->OnItemRemove(this, pItem);

        ItemTemplate const* pProto = pItem->GetTemplate();
        if (bag == INVENTORY_SLOT_BAG_0)
        {
            SetGuidValue(PLAYER_FIELD_INV_SLOT_HEAD + (slot * 2), ObjectGuid::Empty);

            // equipment and equipped bags can have applied bonuses
            if (slot < INVENTORY_SLOT_BAG_END)
            {
                // item set bonuses applied only at equip and removed at unequip, and still active for broken items
                if (pProto->ItemSet)
                    RemoveItemsSetItem(this, pProto);

                _ApplyItemMods(pItem, slot, false);
            }

            if (slot < EQUIPMENT_SLOT_END)
            {
                // update expertise and armor penetration - passive auras may need it
                switch (slot)
                {
                    case EQUIPMENT_SLOT_MAINHAND:
                    case EQUIPMENT_SLOT_OFFHAND:
                    case EQUIPMENT_SLOT_RANGED:
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
        if (pProto->Flags & ITEM_FLAG_HAS_LOOT)
            sLootItemStorage->RemoveStoredLootForContainer(pItem->GetGUID().GetCounter());

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

    for (uint8 i = KEYRING_SLOT_START; i < CURRENCYTOKEN_SLOT_END; ++i)
    {
        if (Item* item = GetItemByPos(INVENTORY_SLOT_BAG_0, i))
        {
            if (item->GetEntry() == itemEntry && !item->IsInTrade())
            {
                if (item->GetCount() + remcount <= count)
                {
                    // all keys can be unequipped
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
            if (item->GetEntry() == itemEntry && !item->IsInTrade())
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

    for (uint8 i = KEYRING_SLOT_START; i < CURRENCYTOKEN_SLOT_END; ++i)
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
    for (uint8 i = INVENTORY_SLOT_ITEM_START; i < INVENTORY_SLOT_ITEM_END; ++i)
        if (Item* pItem = GetItemByPos(INVENTORY_SLOT_BAG_0, i))
            if (pItem->GetEntry() == entry)
                return pItem;

    for (uint8 i = KEYRING_SLOT_START; i < CURRENCYTOKEN_SLOT_END; ++i)
        if (Item* pItem = GetItemByPos(INVENTORY_SLOT_BAG_0, i))
            if (pItem->GetEntry() == entry)
                return pItem;

    for (uint8 i = INVENTORY_SLOT_BAG_START; i < INVENTORY_SLOT_BAG_END; ++i)
        if (Bag* pBag = GetBagByPos(i))
            for (uint32 j = 0; j < pBag->GetBagSize(); ++j)
                if (Item* pItem = pBag->GetItemByPos(j))
                    if (pItem->GetEntry() == entry)
                        return pItem;

    for (uint8 i = EQUIPMENT_SLOT_START; i < INVENTORY_SLOT_BAG_END; ++i)
        if (Item* pItem = GetItemByPos(INVENTORY_SLOT_BAG_0, i))
            if (pItem->GetEntry() == entry)
                return pItem;

    return nullptr;
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
        SendEquipError(EQUIP_ERR_COULDNT_SPLIT_ITEMS, pSrcItem, nullptr);
        return;
    }

    // not let split all items (can be only at cheating)
    if (pSrcItem->GetCount() == count)
    {
        SendEquipError(EQUIP_ERR_COULDNT_SPLIT_ITEMS, pSrcItem, nullptr);
        return;
    }

    // not let split more existing items (can be only at cheating)
    if (pSrcItem->GetCount() < count)
    {
        SendEquipError(EQUIP_ERR_TRIED_TO_SPLIT_MORE_THAN_COUNT, pSrcItem, nullptr);
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
        SendEquipError(EQUIP_ERR_YOU_ARE_DEAD, pSrcItem, pDstItem);
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
        SendEquipError(EQUIP_ERR_NONEMPTY_BAG_OVER_OTHER_BAG, pSrcItem, pDstItem);
        return;
    }

    // prevent equipping bag in the same slot from its inside
    if (IsBagPos(dst) && srcbag == dstslot)
    {
        SendEquipError(EQUIP_ERR_ITEMS_CANT_BE_SWAPPED, pSrcItem, pDstItem);
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
                        SendEquipError(EQUIP_ERR_NONEMPTY_BAG_OVER_OTHER_BAG, pSrcItem, pDstItem);
                        return;
                    }

                    ++count;
                }

                if (count > emptyBag->GetBagSize())
                {
                    // too small targeted bag
                    SendEquipError(EQUIP_ERR_ITEMS_CANT_BE_SWAPPED, pSrcItem, pDstItem);
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

    // if inventory item was moved, check if we can remove dependent auras, because they were not removed in Player::RemoveItem (update was set to false)
    // do this after swaps are done, we pass nullptr because both weapons could be swapped and none of them should be ignored
    if ((srcbag == INVENTORY_SLOT_BAG_0 && srcslot < INVENTORY_SLOT_BAG_END) || (dstbag == INVENTORY_SLOT_BAG_0 && dstslot < INVENTORY_SLOT_BAG_END))
        ApplyItemDependentAuras((Item*)nullptr, false);

    // if player is moving bags and is looting an item inside this bag
    // release the loot
    if (GetLootGUID())
    {
        bool released = false;
        if (IsBagPos(src))
        {
            Bag* bag = pSrcItem->ToBag();
            for (uint32 i = 0; i < bag->GetBagSize(); ++i)
            {
                if (Item* bagItem = bag->GetItemByPos(i))
                {
                    if (bagItem->GetGUID() == GetLootGUID())
                    {
                        m_session->DoLootRelease(GetLootGUID());
                        released = true;                    // so we don't need to look at dstBag
                        break;
                    }
                }
            }
        }

        if (!released && IsBagPos(dst))
        {
            Bag* bag = pDstItem->ToBag();
            for (uint32 i = 0; i < bag->GetBagSize(); ++i)
            {
                if (Item* bagItem = bag->GetItemByPos(i))
                {
                    if (bagItem->GetGUID() == GetLootGUID())
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
        time_t base = GameTime::GetGameTime();
        uint32 etime = uint32(base - m_logintime + (30 * 3600));
        uint32 eslot = slot - BUYBACK_SLOT_START;

        SetGuidValue(PLAYER_FIELD_VENDORBUYBACK_SLOT_1 + (eslot * 2), pItem->GetGUID());
        if (ItemTemplate const* proto = pItem->GetTemplate())
            SetUInt32Value(PLAYER_FIELD_BUYBACK_PRICE_1 + eslot, proto->SellPrice * pItem->GetCount());
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
            {
                if (ItemTemplate const* itemTemplate = pItem->GetTemplate())
                    if (itemTemplate->Flags & ITEM_FLAG_HAS_LOOT)
                        sLootItemStorage->RemoveStoredLootForContainer(pItem->GetGUID().GetCounter());

                pItem->SetState(ITEM_REMOVED, this);
            }
        }

        m_items[slot] = nullptr;

        uint32 eslot = slot - BUYBACK_SLOT_START;
        SetGuidValue(PLAYER_FIELD_VENDORBUYBACK_SLOT_1 + (eslot * 2), ObjectGuid::Empty);
        SetUInt32Value(PLAYER_FIELD_BUYBACK_PRICE_1 + eslot, 0);
        SetUInt32Value(PLAYER_FIELD_BUYBACK_TIMESTAMP_1 + eslot, 0);

        // if current backslot is filled set to now free slot
        if (m_items[m_currentBuybackSlot])
            m_currentBuybackSlot = slot;
    }
}

void Player::SendEquipError(InventoryResult msg, Item* pItem, Item* pItem2, uint32 itemid) const
{

    WorldPacket data(SMSG_INVENTORY_CHANGE_FAILURE, (22));
    data << uint8(msg);

    if (msg != EQUIP_ERR_OK)
    {
        data << uint64(pItem ? pItem->GetGUID() : ObjectGuid::Empty);
        data << uint64(pItem2 ? pItem2->GetGUID() : ObjectGuid::Empty);
        data << uint8(0);                                   // bag type subclass, used with EQUIP_ERR_EVENT_AUTOEQUIP_BIND_CONFIRM and EQUIP_ERR_ITEM_DOESNT_GO_INTO_BAG2

        switch (msg)
        {
            case EQUIP_ERR_CANT_EQUIP_LEVEL_I:
            case EQUIP_ERR_PURCHASE_LEVEL_TOO_LOW:
            {
                ItemTemplate const* proto = pItem ? pItem->GetTemplate() : sObjectMgr->GetItemTemplate(itemid);
                data << uint32(proto ? proto->RequiredLevel : 0);
                break;
            }
            case EQUIP_ERR_EVENT_AUTOEQUIP_BIND_CONFIRM:    // no idea about this one...
            {
                data << uint64(0); // item guid
                data << uint32(0); // slot
                data << uint64(0); // container
                break;
            }
            case EQUIP_ERR_ITEM_MAX_LIMIT_CATEGORY_COUNT_EXCEEDED:
            case EQUIP_ERR_ITEM_MAX_LIMIT_CATEGORY_SOCKETED_EXCEEDED:
            case EQUIP_ERR_ITEM_MAX_LIMIT_CATEGORY_EQUIPPED_EXCEEDED:
            {
                ItemTemplate const* proto = pItem ? pItem->GetTemplate() : sObjectMgr->GetItemTemplate(itemid);
                data << uint32(proto ? proto->ItemLimitCategory : 0);
                break;
            }
            default:
                break;
        }
    }
    SendDirectMessage(&data);
}

void Player::SendBuyError(BuyResult msg, Creature* creature, uint32 item, uint32 param) const
{
    WorldPacket data(SMSG_BUY_FAILED, (8+4+4+1));
    data << uint64(creature ? creature->GetGUID() : ObjectGuid::Empty);
    data << uint32(item);
    if (param > 0)
        data << uint32(param);
    data << uint8(msg);
    SendDirectMessage(&data);
}

void Player::SendSellError(SellResult msg, Creature* creature, ObjectGuid guid, uint32 param) const
{
    WorldPacket data(SMSG_SELL_ITEM, (8+8+(4)+1));  // last check 2.0.10
    data << uint64(creature ? creature->GetGUID() : ObjectGuid::Empty);
    data << uint64(guid);
    if (param > 0)
        data << uint32(param);
    data << uint8(msg);
    SendDirectMessage(&data);
}

bool Player::IsUseEquipedWeapon(bool mainhand) const
{
    // disarm applied only to mainhand weapon
    return !IsInFeralForm() && (!mainhand || !HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISARMED));
}

void Player::SetCanTitanGrip(bool value, uint32 penaltySpellId /*= 0*/)
{
    if (value == m_canTitanGrip)
        return;

    m_canTitanGrip = value;
    m_titanGripPenaltySpellId = penaltySpellId;
}

void Player::CheckTitanGripPenalty()
{
    if (!CanTitanGrip())
        return;

    bool apply = IsUsingTwoHandedWeaponInOneHand();
    if (apply)
    {
        if (!HasAura(m_titanGripPenaltySpellId))
            CastSpell((Unit*)nullptr, m_titanGripPenaltySpellId, true);
    }
    else
        RemoveAurasDueToSpell(m_titanGripPenaltySpellId);
}

bool Player::IsTwoHandUsed() const
{
    Item* mainItem = GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND);
    return mainItem && mainItem->GetTemplate()->InventoryType == INVTYPE_2HWEAPON && !CanTitanGrip();
}

bool Player::IsUsingTwoHandedWeaponInOneHand() const
{
    Item* offItem = GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND);
    if (offItem && offItem->GetTemplate()->InventoryType == INVTYPE_2HWEAPON)
        return true;

    Item* mainItem = GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND);
    if (!mainItem || mainItem->GetTemplate()->InventoryType != INVTYPE_2HWEAPON)
        return false;

    if (!offItem)
        return false;

    return true;
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
    for (EnchantDurationList::iterator itr = m_enchantDuration.begin(), next; itr != m_enchantDuration.end(); itr = next)
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

void Player::RemoveEnchantmentDurationsReferences(Item* item)
{
    for (EnchantDurationList::iterator itr = m_enchantDuration.begin(); itr != m_enchantDuration.end();)
    {
        if (itr->item == item)
            itr = m_enchantDuration.erase(itr);
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
    if (duration > 0)
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

    if (!ignore_condition && pEnchant->EnchantmentCondition && !EnchantmentFitsRequirements(pEnchant->EnchantmentCondition, -1))
        return;

    if (pEnchant->requiredLevel > GetLevel())
        return;

    if (pEnchant->requiredSkill > 0 && pEnchant->requiredSkillValue > GetSkillValue(pEnchant->requiredSkill))
        return;

    // If we're dealing with a gem inside a prismatic socket we need to check the prismatic socket requirements
    // rather than the gem requirements itself. If the socket has no color it is a prismatic socket.
    if ((slot == SOCK_ENCHANTMENT_SLOT || slot == SOCK_ENCHANTMENT_SLOT_2 || slot == SOCK_ENCHANTMENT_SLOT_3)
        && !item->GetTemplate()->Socket[slot-SOCK_ENCHANTMENT_SLOT].Color)
    {
        // Check if the requirements for the prismatic socket are met before applying the gem stats
         SpellItemEnchantmentEntry const* pPrismaticEnchant = sSpellItemEnchantmentStore.LookupEntry(item->GetEnchantmentId(PRISMATIC_ENCHANTMENT_SLOT));
         if (!pPrismaticEnchant || (pPrismaticEnchant->requiredSkill > 0 && pPrismaticEnchant->requiredSkillValue > GetSkillValue(pPrismaticEnchant->requiredSkill)))
             return;
    }

    if (!item->IsBroken())
    {
        for (uint8 s = 0; s < MAX_ITEM_ENCHANTMENT_EFFECTS; ++s)
        {
            uint32 enchant_display_type = pEnchant->type[s];
            uint32 enchant_amount = pEnchant->amount[s];
            uint32 enchant_spell_id = pEnchant->spellid[s];

            switch (enchant_display_type)
            {
                case ITEM_ENCHANTMENT_TYPE_NONE:
                    break;
                case ITEM_ENCHANTMENT_TYPE_COMBAT_SPELL:
                    // processed in Player::CastItemCombatSpell
                    break;
                case ITEM_ENCHANTMENT_TYPE_DAMAGE:
                {
                    WeaponAttackType const attackType = Player::GetAttackBySlot(item->GetSlot());
                    if (attackType != MAX_ATTACK)
                        UpdateDamageDoneMods(attackType, apply ? -1 : slot);
                    break;
                }
                case ITEM_ENCHANTMENT_TYPE_EQUIP_SPELL:
                    if (enchant_spell_id)
                    {
                        if (apply)
                        {
                            int32 basepoints = 0;
                            // Random Property Exist - try found basepoints for spell (basepoints depends from item suffix factor)
                            if (item->GetItemRandomPropertyId())
                            {
                                ItemRandomSuffixEntry const* item_rand = sItemRandomSuffixStore.LookupEntry(abs(item->GetItemRandomPropertyId()));
                                if (item_rand)
                                {
                                    // Search enchant_amount
                                    for (int k = 0; k < MAX_ITEM_ENCHANTMENT_EFFECTS; ++k)
                                    {
                                        if (item_rand->enchant_id[k] == enchant_id)
                                        {
                                            basepoints = int32((item_rand->prefix[k] * item->GetItemSuffixFactor()) / 10000);
                                            break;
                                        }
                                    }
                                }
                            }

                            CastSpellExtraArgs args(item);
                            // Cast custom spell vs all equal basepoints got from enchant_amount
                            if (basepoints)
                                for (uint32 i = 0; i < MAX_SPELL_EFFECTS; ++i)
                                    args.AddSpellMod(SpellValueMod(SPELLVALUE_BASE_POINT0 + i), basepoints);

                            CastSpell(this, enchant_spell_id, args);
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
                            for (int k = 0; k < MAX_ITEM_ENCHANTMENT_EFFECTS; ++k)
                            {
                                if (item_rand->enchant_id[k] == enchant_id)
                                {
                                    enchant_amount = uint32((item_rand->prefix[k] * item->GetItemSuffixFactor()) / 10000);
                                    break;
                                }
                            }
                        }
                    }

                    HandleStatFlatModifier(UnitMods(UNIT_MOD_RESISTANCE_START + enchant_spell_id), TOTAL_VALUE, float(enchant_amount), apply);
                    break;
                case ITEM_ENCHANTMENT_TYPE_STAT:
                {
                    if (!enchant_amount)
                    {
                        ItemRandomSuffixEntry const* item_rand_suffix = sItemRandomSuffixStore.LookupEntry(abs(item->GetItemRandomPropertyId()));
                        if (item_rand_suffix)
                        {
                            for (int k = 0; k < MAX_ITEM_ENCHANTMENT_EFFECTS; ++k)
                            {
                                if (item_rand_suffix->enchant_id[k] == enchant_id)
                                {
                                    enchant_amount = uint32((item_rand_suffix->prefix[k] * item->GetItemSuffixFactor()) / 10000);
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
                            HandleStatFlatModifier(UNIT_MOD_MANA, BASE_VALUE, float(enchant_amount), apply);
                            break;
                        case ITEM_MOD_HEALTH:
                            TC_LOG_DEBUG("entities.player.items", "+ %u HEALTH", enchant_amount);
                            HandleStatFlatModifier(UNIT_MOD_HEALTH, BASE_VALUE, float(enchant_amount), apply);
                            break;
                        case ITEM_MOD_AGILITY:
                            TC_LOG_DEBUG("entities.player.items", "+ %u AGILITY", enchant_amount);
                            HandleStatFlatModifier(UNIT_MOD_STAT_AGILITY, TOTAL_VALUE, float(enchant_amount), apply);
                            UpdateStatBuffMod(STAT_AGILITY);
                            break;
                        case ITEM_MOD_STRENGTH:
                            TC_LOG_DEBUG("entities.player.items", "+ %u STRENGTH", enchant_amount);
                            HandleStatFlatModifier(UNIT_MOD_STAT_STRENGTH, TOTAL_VALUE, float(enchant_amount), apply);
                            UpdateStatBuffMod(STAT_STRENGTH);
                            break;
                        case ITEM_MOD_INTELLECT:
                            TC_LOG_DEBUG("entities.player.items", "+ %u INTELLECT", enchant_amount);
                            HandleStatFlatModifier(UNIT_MOD_STAT_INTELLECT, TOTAL_VALUE, float(enchant_amount), apply);
                            UpdateStatBuffMod(STAT_INTELLECT);
                            break;
                        case ITEM_MOD_SPIRIT:
                            TC_LOG_DEBUG("entities.player.items", "+ %u SPIRIT", enchant_amount);
                            HandleStatFlatModifier(UNIT_MOD_STAT_SPIRIT, TOTAL_VALUE, float(enchant_amount), apply);
                            UpdateStatBuffMod(STAT_SPIRIT);
                            break;
                        case ITEM_MOD_STAMINA:
                            TC_LOG_DEBUG("entities.player.items", "+ %u STAMINA", enchant_amount);
                            HandleStatFlatModifier(UNIT_MOD_STAT_STAMINA, TOTAL_VALUE, float(enchant_amount), apply);
                            UpdateStatBuffMod(STAT_STAMINA);
                            break;
                        case ITEM_MOD_DEFENSE_SKILL_RATING:
                            ApplyRatingMod(CR_DEFENSE_SKILL, enchant_amount, apply);
                            TC_LOG_DEBUG("entities.player.items", "+ %u DEFENSE", enchant_amount);
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
//                        Values from ITEM_STAT_MELEE_HA_RATING to ITEM_MOD_HASTE_RANGED_RATING are never used
//                        in Enchantments
//                        case ITEM_MOD_HIT_TAKEN_MELEE_RATING:
//                            ApplyRatingMod(CR_HIT_TAKEN_MELEE, enchant_amount, apply);
//                            break;
//                        case ITEM_MOD_HIT_TAKEN_RANGED_RATING:
//                            ApplyRatingMod(CR_HIT_TAKEN_RANGED, enchant_amount, apply);
//                            break;
//                        case ITEM_MOD_HIT_TAKEN_SPELL_RATING:
//                            ApplyRatingMod(CR_HIT_TAKEN_SPELL, enchant_amount, apply);
//                            break;
//                        case ITEM_MOD_CRIT_TAKEN_MELEE_RATING:
//                            ApplyRatingMod(CR_CRIT_TAKEN_MELEE, enchant_amount, apply);
//                            break;
//                        case ITEM_MOD_CRIT_TAKEN_RANGED_RATING:
//                            ApplyRatingMod(CR_CRIT_TAKEN_RANGED, enchant_amount, apply);
//                            break;
//                        case ITEM_MOD_CRIT_TAKEN_SPELL_RATING:
//                            ApplyRatingMod(CR_CRIT_TAKEN_SPELL, enchant_amount, apply);
//                            break;
//                        case ITEM_MOD_HASTE_MELEE_RATING:
//                            ApplyRatingMod(CR_HASTE_MELEE, enchant_amount, apply);
//                            break;
//                        case ITEM_MOD_HASTE_RANGED_RATING:
//                            ApplyRatingMod(CR_HASTE_RANGED, enchant_amount, apply);
//                            break;
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
//                        Values ITEM_MOD_HIT_TAKEN_RATING and ITEM_MOD_CRIT_TAKEN_RATING are never used in Enchantment
//                        case ITEM_MOD_HIT_TAKEN_RATING:
//                            ApplyRatingMod(CR_HIT_TAKEN_MELEE, enchant_amount, apply);
//                            ApplyRatingMod(CR_HIT_TAKEN_RANGED, enchant_amount, apply);
//                            ApplyRatingMod(CR_HIT_TAKEN_SPELL, enchant_amount, apply);
//                            break;
//                        case ITEM_MOD_CRIT_TAKEN_RATING:
//                            ApplyRatingMod(CR_CRIT_TAKEN_MELEE, enchant_amount, apply);
//                            ApplyRatingMod(CR_CRIT_TAKEN_RANGED, enchant_amount, apply);
//                            ApplyRatingMod(CR_CRIT_TAKEN_SPELL, enchant_amount, apply);
//                            break;
                        case ITEM_MOD_RESILIENCE_RATING:
                            ApplyRatingMod(CR_CRIT_TAKEN_MELEE, enchant_amount, apply);
                            ApplyRatingMod(CR_CRIT_TAKEN_RANGED, enchant_amount, apply);
                            ApplyRatingMod(CR_CRIT_TAKEN_SPELL, enchant_amount, apply);
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
                            HandleStatFlatModifier(UNIT_MOD_ATTACK_POWER, TOTAL_VALUE, float(enchant_amount), apply);
                            HandleStatFlatModifier(UNIT_MOD_ATTACK_POWER_RANGED, TOTAL_VALUE, float(enchant_amount), apply);
                            TC_LOG_DEBUG("entities.player.items", "+ %u ATTACK_POWER", enchant_amount);
                            break;
                        case ITEM_MOD_RANGED_ATTACK_POWER:
                            HandleStatFlatModifier(UNIT_MOD_ATTACK_POWER_RANGED, TOTAL_VALUE, float(enchant_amount), apply);
                            TC_LOG_DEBUG("entities.player.items", "+ %u RANGED_ATTACK_POWER", enchant_amount);
                            break;
//                        case ITEM_MOD_FERAL_ATTACK_POWER:
//                            ApplyFeralAPBonus(enchant_amount, apply);
//                            TC_LOG_DEBUG("entities.player.items", "+ %u FERAL_ATTACK_POWER", enchant_amount);
//                            break;
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
                            HandleBaseModFlatValue(SHIELD_BLOCK_VALUE, float(enchant_amount), apply);
                            TC_LOG_DEBUG("entities.player.items", "+ %u BLOCK_VALUE", enchant_amount);
                            break;
                        case ITEM_MOD_SPELL_HEALING_DONE:   // deprecated
                        case ITEM_MOD_SPELL_DAMAGE_DONE:    // deprecated
                        default:
                            break;
                    }
                    break;
                }
                case ITEM_ENCHANTMENT_TYPE_TOTEM:           // Shaman Rockbiter Weapon
                {
                    WeaponAttackType const attackType = Player::GetAttackBySlot(item->GetSlot());
                    if (attackType != MAX_ATTACK)
                        UpdateDamageDoneMods(attackType, apply ? -1 : slot);
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
            }
        }
    }

    // visualize enchantment at player and equipped items
    if (slot == PERM_ENCHANTMENT_SLOT)
        SetUInt16Value(PLAYER_VISIBLE_ITEM_1_ENCHANTMENT + (item->GetSlot() * 2), 0, apply ? item->GetEnchantmentId(slot) : 0);

    if (slot == TEMP_ENCHANTMENT_SLOT)
        SetUInt16Value(PLAYER_VISIBLE_ITEM_1_ENCHANTMENT + (item->GetSlot() * 2), 1, apply ? item->GetEnchantmentId(slot) : 0);

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

                if (Enchant->requiredSkill == skill_id)
                {
                    // Checks if the enchantment needs to be applied or removed
                    if (curr_value < Enchant->requiredSkillValue && new_value >= Enchant->requiredSkillValue)
                        ApplyEnchantment(m_items[i], EnchantmentSlot(slot), true);
                    else if (new_value < Enchant->requiredSkillValue && curr_value >= Enchant->requiredSkillValue)
                        ApplyEnchantment(m_items[i], EnchantmentSlot(slot), false);
                }

                // If we're dealing with a gem inside a prismatic socket we need to check the prismatic socket requirements
                // rather than the gem requirements itself. If the socket has no color it is a prismatic socket.
                if ((slot == SOCK_ENCHANTMENT_SLOT || slot == SOCK_ENCHANTMENT_SLOT_2 || slot == SOCK_ENCHANTMENT_SLOT_3)
                    && !m_items[i]->GetTemplate()->Socket[slot-SOCK_ENCHANTMENT_SLOT].Color)
                {
                    SpellItemEnchantmentEntry const* pPrismaticEnchant = sSpellItemEnchantmentStore.LookupEntry(m_items[i]->GetEnchantmentId(PRISMATIC_ENCHANTMENT_SLOT));

                    if (pPrismaticEnchant && pPrismaticEnchant->requiredSkill == skill_id)
                    {
                        if (curr_value < pPrismaticEnchant->requiredSkillValue && new_value >= pPrismaticEnchant->requiredSkillValue)
                            ApplyEnchantment(m_items[i], EnchantmentSlot(slot), true);
                        else if (new_value < pPrismaticEnchant->requiredSkillValue && curr_value >= pPrismaticEnchant->requiredSkillValue)
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
    {
        GetSession()->SendItemEnchantTimeUpdate(GetGUID(), itr->item->GetGUID(), itr->slot, uint32(itr->leftduration) / 1000);
    }
}

void Player::SendItemDurations()
{
    for (ItemDurationList::const_iterator itr = m_itemDuration.begin(); itr != m_itemDuration.end(); ++itr)
    {
        (*itr)->SendTimeUpdate(this);
    }
}

void Player::SendNewItem(Item* item, uint32 count, bool received, bool created, bool broadcast, bool sendChatMessage)
{
    if (!item)                                               // prevent crash
        return;

                                                            // last check 2.0.10
    WorldPacket data(SMSG_ITEM_PUSH_RESULT, (8+4+4+4+1+4+4+4+4+4));
    data << uint64(GetGUID());                              // player GUID
    data << uint32(received);                               // 0=looted, 1=from npc
    data << uint32(created);                                // 0=received, 1=created
    data << uint32(sendChatMessage);                        // bool print message to chat
    data << uint8(item->GetBagSlot());                      // bagslot
                                                            // item slot, but when added to stack: 0xFFFFFFFF
    data << uint32((item->GetCount() == count) ? item->GetSlot() : -1);
    data << uint32(item->GetEntry());                       // item id
    data << uint32(item->GetItemSuffixFactor());            // SuffixFactor
    data << int32(item->GetItemRandomPropertyId());         // random item property id
    data << uint32(count);                                  // count of items
    data << uint32(GetItemCount(item->GetEntry()));         // count of items in inventory

    if (broadcast && GetGroup())
        GetGroup()->BroadcastPacket(&data, true);
    else
        SendDirectMessage(&data);
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

    uint32 npcflags = 0;

    if (source->GetTypeId() == TYPEID_UNIT)
    {
        npcflags = source->GetUInt32Value(UNIT_NPC_FLAGS);
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
            if (!(itr->second.OptionNpcFlag & npcflags))
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
                        TC_LOG_ERROR("sql.sql", "Creature %s (Entry: %u GUID: %u DB GUID: %u) has UNIT_NPC_FLAG_VENDOR set, but has an empty trading item list.", creature->GetName().c_str(), creature->GetEntry(), creature->GetGUID().GetCounter(), creature->GetSpawnId());
                        canTalk = false;
                    }
                    break;
                }
                case GOSSIP_OPTION_LEARNDUALSPEC:
                case GOSSIP_OPTION_DUALSPEC_INFO:
                    if (!(GetSpecsCount() == 1 && creature->CanResetTalents(this, false) && !(GetLevel() < sWorld->getIntConfig(CONFIG_MIN_DUALSPEC_LEVEL))))
                        canTalk = false;
                    break;
                case GOSSIP_OPTION_UNLEARNTALENTS:
                    if (!creature->CanResetTalents(this, false))
                        canTalk = false;
                    break;
                case GOSSIP_OPTION_UNLEARNPETTALENTS:
                    if (!GetPet() || GetPet()->getPetType() != HUNTER_PET || GetPet()->m_spells.size() <= 1 || !creature->CanResetTalents(this, true))
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
                    if (GetClass() != CLASS_HUNTER)
                        canTalk = false;
                    break;
                case GOSSIP_OPTION_QUESTGIVER:
                    canTalk = false;
                    break;
                case GOSSIP_OPTION_TRAINER:
                {
                    Trainer::Trainer const* trainer = sObjectMgr->GetTrainer(creature->GetEntry());
                    if (!trainer || !trainer->IsTrainerValidForPlayer(this))
                    {
                        TC_LOG_ERROR("sql.sql", "GOSSIP_OPTION_TRAINER:: Player %s (GUID: %u) requested wrong gossip menu: %u at Creature: %s (Entry: %u)",
                            GetName().c_str(), GetGUID().GetCounter(), menu->GetGossipMenu().GetMenuId(), creature->GetName().c_str(), creature->GetEntry());
                        canTalk = false;
                    }
                }
                /* fallthrough */
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
                    TC_LOG_ERROR("sql.sql", "Creature entry %u has unknown gossip option %u for menu %u.", creature->GetEntry(), itr->second.OptionType, itr->second.MenuID);
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
            BroadcastText const* optionBroadcastText = sObjectMgr->GetBroadcastText(itr->second.OptionBroadcastTextID);
            BroadcastText const* boxBroadcastText = sObjectMgr->GetBroadcastText(itr->second.BoxBroadcastTextID);
            LocaleConstant locale = GetSession()->GetSessionDbLocaleIndex();

            if (optionBroadcastText)
                strOptionText = optionBroadcastText->GetText(locale, GetGender());
            else
                strOptionText = itr->second.OptionText;

            if (boxBroadcastText)
                strBoxText = boxBroadcastText->GetText(locale, GetGender());
            else
                strBoxText = itr->second.BoxText;

            if (locale != DEFAULT_LOCALE)
            {
                if (!optionBroadcastText)
                {
                    /// Find localizations from database.
                    if (GossipMenuItemsLocale const* gossipMenuLocale = sObjectMgr->GetGossipMenuItemsLocale(MAKE_PAIR32(menuId, itr->second.OptionID)))
                        ObjectMgr::GetLocaleString(gossipMenuLocale->OptionText, locale, strOptionText);
                }

                if (!boxBroadcastText)
                {
                    /// Find localizations from database.
                    if (GossipMenuItemsLocale const* gossipMenuLocale = sObjectMgr->GetGossipMenuItemsLocale(MAKE_PAIR32(menuId, itr->second.OptionID)))
                        ObjectMgr::GetLocaleString(gossipMenuLocale->BoxText, locale, strBoxText);
                }
            }

            menu->GetGossipMenu().AddMenuItem(itr->second.OptionID, itr->second.OptionIcon, strOptionText, 0, itr->second.OptionType, strBoxText, itr->second.BoxMoney, itr->second.BoxCoded);
            menu->GetGossipMenu().AddGossipMenuItemData(itr->second.OptionID, itr->second.ActionMenuID, itr->second.ActionPoiID);
        }
    }
}

void Player::SendPreparedGossip(WorldObject* source)
{
    if (!source)
        return;

    if (source->GetTypeId() == TYPEID_UNIT)
    {
        // in case no gossip flag and quest menu not empty, open quest menu (client expect gossip menu with this flag)
        if (!source->ToCreature()->HasFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP) && !PlayerTalkClass->GetQuestMenu().Empty())
        {
            SendPreparedQuest(source->GetGUID());
            return;
        }
    }
    else if (source->GetTypeId() == TYPEID_GAMEOBJECT)
    {
        // probably need to find a better way here
        if (!PlayerTalkClass->GetGossipMenu().GetMenuId() && !PlayerTalkClass->GetQuestMenu().Empty())
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
    if (!HasEnoughMoney(cost))
    {
        SendBuyError(BUY_ERR_NOT_ENOUGHT_MONEY, nullptr, 0, 0);
        PlayerTalkClass->SendCloseGossip();
        return;
    }

    switch (gossipOptionId)
    {
        case GOSSIP_OPTION_GOSSIP:
        case GOSSIP_OPTION_DUALSPEC_INFO:
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
                source->ToCreature()->CastSpell(source->ToCreature(), 17251, GetGUID());
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
            GetSession()->SendTrainerList(source->ToCreature());
            break;
        case GOSSIP_OPTION_LEARNDUALSPEC:
            if (GetSpecsCount() == 1 && GetLevel() >= sWorld->getIntConfig(CONFIG_MIN_DUALSPEC_LEVEL))
            {
                // Cast spells that teach dual spec
                // Both are also ImplicitTarget self and must be cast by player
                CastSpell(this, 63680, GetGUID());
                CastSpell(this, 63624, GetGUID());

                PrepareGossipMenu(source, menuItemData->GossipActionMenuId);
                SendPreparedGossip(source);
            }
            break;
        case GOSSIP_OPTION_UNLEARNTALENTS:
            PlayerTalkClass->SendCloseGossip();
            SendTalentWipeConfirm(guid);
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

            GetSession()->SendBattleGroundList(guid, bgTypeId);
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
        if (sConditionMgr->IsObjectMeetToConditions(this, source, itr->second.Conditions))
            textId = itr->second.TextID;
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
    QuestRelationResult objectQR;
    QuestRelationResult objectQIR;

    // pets also can have quests
    Creature* creature = ObjectAccessor::GetCreatureOrPetOrVehicle(*this, guid);
    if (creature)
    {
        objectQR  = sObjectMgr->GetCreatureQuestRelations(creature->GetEntry());
        objectQIR = sObjectMgr->GetCreatureQuestInvolvedRelations(creature->GetEntry());
    }
    else
    {
        //we should obtain map pointer from GetMap() in 99% of cases. Special case
        //only for quests which cast teleport spells on player
        Map* _map = IsInWorld() ? GetMap() : sMapMgr->FindMap(GetMapId(), GetInstanceId());
        ASSERT(_map);
        GameObject* pGameObject = _map->GetGameObject(guid);
        if (pGameObject)
        {
            objectQR  = sObjectMgr->GetGOQuestRelations(pGameObject->GetEntry());
            objectQIR = sObjectMgr->GetGOQuestInvolvedRelations(pGameObject->GetEntry());
        }
        else
            return;
    }

    QuestMenu &qm = PlayerTalkClass->GetQuestMenu();
    qm.ClearMenu();

    for (uint32 quest_id : objectQIR)
    {
        QuestStatus status = GetQuestStatus(quest_id);
        if (status == QUEST_STATUS_COMPLETE)
            qm.AddMenuItem(quest_id, 4);
        else if (status == QUEST_STATUS_INCOMPLETE)
            qm.AddMenuItem(quest_id, 4);
        //else if (status == QUEST_STATUS_AVAILABLE)
        //    qm.AddMenuItem(quest_id, 2);
    }

    for (uint32 quest_id : objectQR)
    {
        Quest const* quest = sObjectMgr->GetQuestTemplate(quest_id);
        if (!quest)
            continue;

        if (!CanTakeQuest(quest, false))
            continue;

        if (quest->IsAutoComplete() && (!quest->IsRepeatable() || quest->IsDaily() || quest->IsWeekly() || quest->IsMonthly()))
            qm.AddMenuItem(quest_id, 0);
        else if (quest->IsAutoComplete())
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

        // Auto open -- maybe also should verify there is no greeting
        if (Quest const* quest = sObjectMgr->GetQuestTemplate(questId))
        {
            if (qmi0.QuestIcon == 4)
                PlayerTalkClass->SendQuestGiverRequestItems(quest, guid, CanRewardQuest(quest, false), true);
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

                if (quest->IsAutoAccept() && CanAddQuest(quest, true) && CanTakeQuest(quest, true))
                    AddQuestAndCheckCompletion(quest, object);

                if ((quest->IsAutoComplete() && quest->IsRepeatable() && !quest->IsDailyOrWeekly()) || quest->HasFlag(QUEST_FLAGS_AUTOCOMPLETE))
                    PlayerTalkClass->SendQuestGiverRequestItems(quest, guid, CanCompleteRepeatableQuest(quest), true);
                else
                    PlayerTalkClass->SendQuestGiverQuestDetails(quest, guid, true);
            }
        }
    }
    // multiple entries
    else
    {
        QEmote qe;
        qe._Delay = 0;
        qe._Emote = 0;
        std::string title = "";

        // need pet case for some quests
        Creature* creature = ObjectAccessor::GetCreatureOrPetOrVehicle(*this, guid);
        if (creature)
        {
            uint32 textid = GetGossipTextId(creature);
            GossipText const* gossiptext = sObjectMgr->GetGossipText(textid);
            if (!gossiptext)
            {
                qe._Delay = 0;                              //TEXTEMOTE_MESSAGE;              //zyg: player emote
                qe._Emote = 0;                              //TEXTEMOTE_HELLO;                //zyg: NPC emote
                title.clear();
            }
            else
            {
                qe = gossiptext->Options[0].Emotes[0];

                if (!gossiptext->Options[0].Text_0.empty())
                {
                    title = gossiptext->Options[0].Text_0;

                    LocaleConstant localeConstant = GetSession()->GetSessionDbLocaleIndex();
                    if (localeConstant != LOCALE_enUS)
                        if (NpcTextLocale const* nl = sObjectMgr->GetNpcTextLocale(textid))
                            ObjectMgr::GetLocaleString(nl->Text_0[0], localeConstant, title);
                }
                else
                {
                    title = gossiptext->Options[0].Text_1;

                    LocaleConstant localeConstant = GetSession()->GetSessionDbLocaleIndex();
                    if (localeConstant != LOCALE_enUS)
                        if (NpcTextLocale const* nl = sObjectMgr->GetNpcTextLocale(textid))
                            ObjectMgr::GetLocaleString(nl->Text_1[0], localeConstant, title);
                }
            }
        }
        PlayerTalkClass->SendQuestGiverQuestList(qe, title, guid);
    }
}

bool Player::IsActiveQuest(uint32 quest_id) const
{
    return m_QuestStatus.find(quest_id) != m_QuestStatus.end();
}

Quest const* Player::GetNextQuest(ObjectGuid guid, Quest const* quest) const
{
    QuestRelationResult quests;

    Creature* creature = ObjectAccessor::GetCreatureOrPetOrVehicle(*this, guid);
    if (creature)
        quests  = sObjectMgr->GetCreatureQuestRelations(creature->GetEntry());
    else
    {
        //we should obtain map pointer from GetMap() in 99% of cases. Special case
        //only for quests which cast teleport spells on player
        Map* _map = IsInWorld() ? GetMap() : sMapMgr->FindMap(GetMapId(), GetInstanceId());
        ASSERT(_map);
        GameObject* pGameObject = _map->GetGameObject(guid);
        if (pGameObject)
            quests  = sObjectMgr->GetGOQuestRelations(pGameObject->GetEntry());
        else
            return nullptr;
    }

    if (uint32 nextQuestID = quest->GetNextQuestInChain())
        if (quests.HasQuest(nextQuestID))
            return sObjectMgr->GetQuestTemplate(nextQuestID);

    return nullptr;
}

bool Player::CanSeeStartQuest(Quest const* quest) const
{
    if (!DisableMgr::IsDisabledFor(DISABLE_TYPE_QUEST, quest->GetQuestId(), this) && SatisfyQuestClass(quest, false) && SatisfyQuestRace(quest, false) &&
        SatisfyQuestSkill(quest, false) && SatisfyQuestExclusiveGroup(quest, false) && SatisfyQuestReputation(quest, false) &&
        SatisfyQuestDependentQuests(quest, false) &&
        SatisfyQuestDay(quest, false) && SatisfyQuestWeek(quest, false) &&
        SatisfyQuestMonth(quest, false) && SatisfyQuestSeasonal(quest, false))
    {
        return GetLevel() + sWorld->getIntConfig(CONFIG_QUEST_HIGH_LEVEL_HIDE_DIFF) >= quest->GetMinLevel();
    }

    return false;
}

bool Player::CanTakeQuest(Quest const* quest, bool msg) const
{
    return !DisableMgr::IsDisabledFor(DISABLE_TYPE_QUEST, quest->GetQuestId(), this)
        && SatisfyQuestStatus(quest, msg) && SatisfyQuestExclusiveGroup(quest, msg)
        && SatisfyQuestClass(quest, msg) && SatisfyQuestRace(quest, msg) && SatisfyQuestLevel(quest, msg)
        && SatisfyQuestSkill(quest, msg) && SatisfyQuestReputation(quest, msg)
        && SatisfyQuestDependentQuests(quest, msg) && SatisfyQuestTimed(quest, msg)
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
        if (msg2 == EQUIP_ERR_CANT_CARRY_MORE_OF_THIS)
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

        if (!qInfo->IsRepeatable() && GetQuestRewardStatus(quest_id))
            return false;                                   // not allow re-complete quest

        // auto complete quest
        if ((qInfo->IsAutoComplete() || qInfo->GetFlags() & QUEST_FLAGS_AUTOCOMPLETE) && CanTakeQuest(qInfo, false))
            return true;

        QuestStatusMap::iterator itr = m_QuestStatus.find(quest_id);
        if (itr == m_QuestStatus.end())
            return false;

        QuestStatusData &q_status = itr->second;

        if (q_status.Status == QUEST_STATUS_INCOMPLETE)
        {
            if (qInfo->HasSpecialFlag(QUEST_SPECIAL_FLAGS_DELIVER))
            {
                for (uint8 i = 0; i < QUEST_ITEM_OBJECTIVES_COUNT; i++)
                {
                    if (qInfo->RequiredItemCount[i]!= 0 && q_status.ItemCount[i] < qInfo->RequiredItemCount[i])
                        return false;
                }
            }

            if (qInfo->HasSpecialFlag(QUEST_SPECIAL_FLAGS_KILL | QUEST_SPECIAL_FLAGS_CAST | QUEST_SPECIAL_FLAGS_SPEAKTO))
            {
                for (uint8 i = 0; i < QUEST_OBJECTIVES_COUNT; i++)
                {
                    if (qInfo->RequiredNpcOrGo[i] == 0)
                        continue;

                    if (qInfo->RequiredNpcOrGoCount[i] != 0 && q_status.CreatureOrGOCount[i] < qInfo->RequiredNpcOrGoCount[i])
                        return false;
                }
            }

            if (qInfo->HasSpecialFlag(QUEST_SPECIAL_FLAGS_PLAYER_KILL))
                if (qInfo->GetPlayersSlain() != 0 && q_status.PlayerCount < qInfo->GetPlayersSlain())
                    return false;

            if (qInfo->HasSpecialFlag(QUEST_SPECIAL_FLAGS_EXPLORATION_OR_EVENT) && !q_status.Explored)
                return false;

            if (qInfo->HasSpecialFlag(QUEST_SPECIAL_FLAGS_TIMED) && q_status.Timer == 0)
                return false;

            if (qInfo->GetRewOrReqMoney() < 0)
            {
                if (!HasEnoughMoney(-qInfo->GetRewOrReqMoney()))
                    return false;
            }

            uint32 repFacId = qInfo->GetRepObjectiveFaction();
            if (repFacId && GetReputationMgr().GetReputation(repFacId) < qInfo->GetRepObjectiveValue())
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
        for (uint8 i = 0; i < QUEST_ITEM_OBJECTIVES_COUNT; i++)
            if (quest->RequiredItemId[i] && quest->RequiredItemCount[i] && !HasItemCount(quest->RequiredItemId[i], quest->RequiredItemCount[i]))
                return false;

    if (!CanRewardQuest(quest, false))
        return false;

    return true;
}

bool Player::CanRewardQuest(Quest const* quest, bool msg)
{
    // quest is disabled
    if (DisableMgr::IsDisabledFor(DISABLE_TYPE_QUEST, quest->GetQuestId(), this))
        return false;

    // not auto complete quest and not completed quest (only cheating case, then ignore without message)
    if (!quest->IsDFQuest() && !quest->IsAutoComplete() && !(quest->GetFlags() & QUEST_FLAGS_AUTOCOMPLETE) && GetQuestStatus(quest->GetQuestId()) != QUEST_STATUS_COMPLETE)
        return false;

    // daily quest can't be rewarded (25 daily quest already completed)
    if (!SatisfyQuestDay(quest, msg) || !SatisfyQuestWeek(quest, msg) || !SatisfyQuestMonth(quest, msg) || !SatisfyQuestSeasonal(quest, msg))
        return false;

    // player no longer satisfies the quest's requirements (skill level etc.)
    if (!SatisfyQuestLevel(quest, msg) || !SatisfyQuestSkill(quest, msg) || !SatisfyQuestReputation(quest, msg))
        return false;

    // rewarded and not repeatable quest (only cheating case, then ignore without message)
    if (GetQuestRewardStatus(quest->GetQuestId()))
        return false;

    // prevent receive reward with quest items in bank
    if (quest->HasSpecialFlag(QUEST_SPECIAL_FLAGS_DELIVER))
    {
        for (uint8 i = 0; i < QUEST_ITEM_OBJECTIVES_COUNT; i++)
        {
            if (quest->RequiredItemCount[i]!= 0 &&
                GetItemCount(quest->RequiredItemId[i]) < quest->RequiredItemCount[i])
            {
                if (msg)
                    SendEquipError(EQUIP_ERR_ITEM_NOT_FOUND, nullptr, nullptr, quest->RequiredItemId[i]);
                return false;
            }
        }
    }

    // prevent receive reward with low money and GetRewOrReqMoney() < 0
    if (quest->GetRewOrReqMoney() < 0 && !HasEnoughMoney(-quest->GetRewOrReqMoney()))
        return false;

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
            PlayerTalkClass->ClearMenus();
            questGiver->ToCreature()->AI()->QuestAccept(this, quest);
            break;
        case TYPEID_ITEM:
        case TYPEID_CONTAINER:
        {
            Item* item = static_cast<Item*>(questGiver);
            sScriptMgr->OnQuestAccept(this, item, quest);

            // There are two cases where the source item is not destroyed when the quest is accepted:
            // - It is required to finish the quest, and is an unique item
            // - It is the same item present in the source item field (item that would be given on quest accept)
            bool destroyItem = true;

            for (int i = 0; i < QUEST_ITEM_OBJECTIVES_COUNT; ++i)
            {
                if (quest->RequiredItemId[i] == item->GetEntry() && item->GetTemplate()->MaxCount > 0)
                {
                    destroyItem = false;
                    break;
                }
            }

            if (quest->GetSrcItemId() == item->GetEntry())
                destroyItem = false;

            if (destroyItem)
                DestroyItem(item->GetBagSlot(), item->GetSlot(), true);

            break;
        }
        case TYPEID_GAMEOBJECT:
            PlayerTalkClass->ClearMenus();
            questGiver->ToGameObject()->AI()->QuestAccept(this, quest);
            break;
        default:
            break;
    }
}

bool Player::CanRewardQuest(Quest const* quest, uint32 reward, bool msg)
{
    ItemPosCountVec dest;
    if (quest->GetRewChoiceItemsCount() > 0)
    {
        if (quest->RewardChoiceItemId[reward])
        {
            InventoryResult res = CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, quest->RewardChoiceItemId[reward], quest->RewardChoiceItemCount[reward]);
            if (res != EQUIP_ERR_OK)
            {
                if (msg)
                    SendQuestFailed(quest->GetQuestId(), res);

                return false;
            }
        }
    }

    if (quest->GetRewItemsCount() > 0)
    {
        for (uint32 i = 0; i < quest->GetRewItemsCount(); ++i)
        {
            if (quest->RewardItemId[i])
            {
                InventoryResult res = CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, quest->RewardItemId[i], quest->RewardItemIdCount[i]);
                if (res != EQUIP_ERR_OK)
                {
                    if (msg)
                        SendQuestFailed(quest->GetQuestId(), res);

                    return false;
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
    questStatusData.Explored = false;

    if (quest->HasSpecialFlag(QUEST_SPECIAL_FLAGS_DELIVER))
    {
        for (uint8 i = 0; i < QUEST_ITEM_OBJECTIVES_COUNT; ++i)
            questStatusData.ItemCount[i] = 0;
    }

    if (quest->HasSpecialFlag(QUEST_SPECIAL_FLAGS_KILL | QUEST_SPECIAL_FLAGS_CAST | QUEST_SPECIAL_FLAGS_SPEAKTO))
    {
        for (uint8 i = 0; i < QUEST_OBJECTIVES_COUNT; ++i)
            questStatusData.CreatureOrGOCount[i] = 0;
    }

    if (quest->HasSpecialFlag(QUEST_SPECIAL_FLAGS_PLAYER_KILL))
        questStatusData.PlayerCount = 0;

    GiveQuestSourceItem(quest);
    AdjustQuestReqItemCount(quest, questStatusData);

    if (quest->GetRepObjectiveFaction())
        if (FactionEntry const* factionEntry = sFactionStore.LookupEntry(quest->GetRepObjectiveFaction()))
            GetReputationMgr().SetVisible(factionEntry);

    if (quest->GetRepObjectiveFaction2())
        if (FactionEntry const* factionEntry = sFactionStore.LookupEntry(quest->GetRepObjectiveFaction2()))
            GetReputationMgr().SetVisible(factionEntry);

    uint32 qtime = 0;
    if (quest->HasSpecialFlag(QUEST_SPECIAL_FLAGS_TIMED))
    {
        uint32 timeAllowed = quest->GetTimeAllowed();

        // shared timed quest
        if (questGiver && questGiver->GetTypeId() == TYPEID_PLAYER)
            timeAllowed = questGiver->ToPlayer()->getQuestStatusMap()[quest_id].Timer / IN_MILLISECONDS;

        AddTimedQuest(quest_id);
        questStatusData.Timer = timeAllowed * IN_MILLISECONDS;
        qtime = static_cast<uint32>(GameTime::GetGameTime()) + timeAllowed;
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
        stmt->setUInt32(1, GetGUID().GetCounter());
        stmt->setString(2, GitRevision::GetHash());
        stmt->setString(3, GitRevision::GetDate());

        // add to Quest Tracker
        CharacterDatabase.Execute(stmt);
    }

    sScriptMgr->OnQuestStatusChange(this, quest_id);
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
            if (qInfo->HasFlag(QUEST_FLAGS_TRACKING))
                RewardQuest(qInfo, 0, this, false);
    }

    if (sWorld->getBoolConfig(CONFIG_QUEST_ENABLE_QUEST_TRACKER)) // check if Quest Tracker is enabled
    {
        // prepare Quest Tracker data
        PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_QUEST_TRACK_COMPLETE_TIME);
        stmt->setUInt32(0, quest_id);
        stmt->setUInt32(1, GetGUID().GetCounter());

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

void Player::RewardQuest(Quest const* quest, uint32 reward, Object* questGiver, bool announce)
{
    //this THING should be here to protect code from quest, which cast on player far teleport as a reward
    //should work fine, cause far teleport will be executed in Player::Update()
    SetCanDelayTeleport(true);

    uint32 quest_id = quest->GetQuestId();

    for (uint8 i = 0; i < QUEST_ITEM_OBJECTIVES_COUNT; ++i)
    {
        if (ItemTemplate const* itemTemplate = sObjectMgr->GetItemTemplate(quest->RequiredItemId[i]))
        {
            if (quest->RequiredItemCount[i] > 0 && itemTemplate->Bonding == BIND_QUEST_ITEM && !quest->IsRepeatable() && !HasQuestForItem(quest->RequiredItemId[i], quest_id, true))
                DestroyItemCount(quest->RequiredItemId[i], 9999, true);
            else
                DestroyItemCount(quest->RequiredItemId[i], quest->RequiredItemCount[i], true);
        }
    }
    for (uint8 i = 0; i < QUEST_SOURCE_ITEM_IDS_COUNT; ++i)
    {
        if (ItemTemplate const* itemTemplate = sObjectMgr->GetItemTemplate(quest->ItemDrop[i]))
        {
            if (quest->ItemDropQuantity[i] > 0 && itemTemplate->Bonding == BIND_QUEST_ITEM && !quest->IsRepeatable() && !HasQuestForItem(quest->ItemDrop[i], quest_id))
                DestroyItemCount(quest->ItemDrop[i], 9999, true);
            else
                DestroyItemCount(quest->ItemDrop[i], quest->ItemDropQuantity[i], true);
        }
    }

    RemoveTimedQuest(quest_id);

    if (quest->GetRewItemsCount() > 0)
    {
        for (uint32 i = 0; i < quest->GetRewItemsCount(); ++i)
        {
            if (uint32 itemId = quest->RewardItemId[i])
            {
                ItemPosCountVec dest;
                if (CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, itemId, quest->RewardItemIdCount[i]) == EQUIP_ERR_OK)
                {
                    Item* item = StoreNewItem(dest, itemId, true, GenerateItemRandomPropertyId(itemId));
                    SendNewItem(item, quest->RewardItemIdCount[i], true, false, false, false);
                }
                else if (quest->IsDFQuest())
                    SendItemRetrievalMail(itemId, quest->RewardItemIdCount[i]);
            }
        }
    }

    if (quest->GetRewChoiceItemsCount() > 0)
    {
        if (uint32 itemId = quest->RewardChoiceItemId[reward])
        {
            ItemPosCountVec dest;
            if (CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, itemId, quest->RewardChoiceItemCount[reward]) == EQUIP_ERR_OK)
            {
                Item* item = StoreNewItem(dest, itemId, true, GenerateItemRandomPropertyId(itemId));
                SendNewItem(item, quest->RewardChoiceItemCount[reward], true, false, false, false);
            }
        }
    }

    uint16 log_slot = FindQuestSlot(quest_id);
    if (log_slot < MAX_QUEST_LOG_SIZE)
        SetQuestSlot(log_slot, 0);

    bool rewarded = IsQuestRewarded(quest_id) && !quest->IsDFQuest();

    // Not give XP in case already completed once repeatable quest
    uint32 XP = rewarded ? 0 : uint32(quest->GetXPReward(this)*sWorld->getRate(RATE_XP_QUEST));

    // handle SPELL_AURA_MOD_XP_QUEST_PCT auras
    XP *= GetTotalAuraMultiplier(SPELL_AURA_MOD_XP_QUEST_PCT);

    if (GetLevel() < sWorld->getIntConfig(CONFIG_MAX_PLAYER_LEVEL))
        GiveXP(XP, nullptr);

    // Give player extra money if GetRewOrReqMoney > 0 and get ReqMoney if negative
    if (int32 moneyRew = quest->GetRewOrReqMoney(this))
    {
        ModifyMoney(moneyRew);

        if (moneyRew > 0)
            UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_MONEY_FROM_QUEST_REWARD, uint32(moneyRew));
    }

    // honor reward
    if (uint32 honor = quest->CalculateHonorGain(GetLevel()))
        RewardHonor(nullptr, 0, honor);

    // title reward
    if (quest->GetCharTitleId())
    {
        if (CharTitlesEntry const* titleEntry = sCharTitlesStore.LookupEntry(quest->GetCharTitleId()))
            SetTitle(titleEntry);
    }

    if (quest->GetBonusTalents())
    {
        m_questRewardTalentCount += quest->GetBonusTalents();
        InitTalentForLevel();
    }

    if (quest->GetRewArenaPoints())
        ModifyArenaPoints(quest->GetRewArenaPoints());

    // Send reward mail
    if (uint32 mail_template_id = quest->GetRewMailTemplateId())
    {
        /// @todo Poor design of mail system
        SQLTransaction trans = CharacterDatabase.BeginTransaction();
        if (uint32 questMailSender = quest->GetRewMailSenderEntry())
            MailDraft(mail_template_id).SendMailTo(trans, this, questMailSender, MAIL_CHECK_MASK_HAS_BODY, quest->GetRewMailDelaySecs());
        else
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
    if (quest->CanIncreaseRewardedQuestCounters())
        SetRewardedQuest(quest_id);

    if (announce)
        SendQuestReward(quest, XP);

    RewardReputation(quest);

    // cast spells after mark quest complete (some spells have quest completed state requirements in spell_area data)
    if (quest->GetRewSpellCast() > 0)
    {
        SpellInfo const* spellInfo = ASSERT_NOTNULL(sSpellMgr->GetSpellInfo(quest->GetRewSpellCast()));
        if (questGiver->isType(TYPEMASK_UNIT) && !spellInfo->HasEffect(SPELL_EFFECT_LEARN_SPELL) && !spellInfo->HasEffect(SPELL_EFFECT_CREATE_ITEM) && !spellInfo->IsSelfCast())
        {
            if (Creature* creature = GetMap()->GetCreature(questGiver->GetGUID()))
                creature->CastSpell(this, quest->GetRewSpellCast(), true);
        }
        else
            CastSpell(this, quest->GetRewSpellCast(), true);
    }
    else if (quest->GetRewSpell() > 0)
    {
        SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(quest->GetRewSpell());
        if (questGiver->isType(TYPEMASK_UNIT) && !spellInfo->HasEffect(SPELL_EFFECT_LEARN_SPELL) && !spellInfo->HasEffect(SPELL_EFFECT_CREATE_ITEM) && !spellInfo->IsSelfCast())
        {
            if (Creature* creature = GetMap()->GetCreature(questGiver->GetGUID()))
                creature->CastSpell(this, quest->GetRewSpell(), true);
        }
        else
            CastSpell(this, quest->GetRewSpell(), true);
    }

    if (quest->GetZoneOrSort() > 0)
        UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_QUESTS_IN_ZONE, quest->GetZoneOrSort());
    UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_QUEST_COUNT);
    UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_QUEST, quest->GetQuestId());

    // make full db save
    SaveToDB(false);

    if (quest->HasFlag(QUEST_FLAGS_FLAGS_PVP))
    {
        pvpInfo.IsHostile = pvpInfo.IsInHostileArea || HasPvPForcingQuest();
        UpdatePvPState();
    }

    SendQuestUpdate(quest_id);

    SendQuestGiverStatusMultiple();

    //lets remove flag for delayed teleports
    SetCanDelayTeleport(false);

    sScriptMgr->OnQuestStatusChange(this, quest_id);
}

void Player::SetRewardedQuest(uint32 quest_id)
{
    m_RewardedQuests.insert(quest_id);
    m_RewardedQuestsSave[quest_id] = QUEST_DEFAULT_SAVE_TYPE;
}

void Player::FailQuest(uint32 questId)
{
    if (Quest const* quest = sObjectMgr->GetQuestTemplate(questId))
    {
        QuestStatus qStatus = GetQuestStatus(questId);

        // we can only fail incomplete quest or...
        if (qStatus != QUEST_STATUS_INCOMPLETE)
        {
            // completed timed quest with no requirements
            if (qStatus != QUEST_STATUS_COMPLETE || !quest->HasSpecialFlag(QUEST_SPECIAL_FLAGS_TIMED) || !quest->HasSpecialFlag(QUEST_SPECIAL_FLAGS_COMPLETED_AT_START))
                return;
        }

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
        for (uint8 i = 0; i < QUEST_ITEM_OBJECTIVES_COUNT; ++i)
            if (ItemTemplate const* itemTemplate = sObjectMgr->GetItemTemplate(quest->RequiredItemId[i]))
                if (quest->RequiredItemCount[i] > 0 && itemTemplate->Bonding == BIND_QUEST_ITEM)
                    DestroyItemCount(quest->RequiredItemId[i], 9999, true);

        for (uint8 i = 0; i < QUEST_SOURCE_ITEM_IDS_COUNT; ++i)
            if (ItemTemplate const* itemTemplate = sObjectMgr->GetItemTemplate(quest->ItemDrop[i]))
                if (quest->ItemDropQuantity[i] > 0 && itemTemplate->Bonding == BIND_QUEST_ITEM)
                    DestroyItemCount(quest->ItemDrop[i], 9999, true);
    }
}

void Player::AbandonQuest(uint32 questId)
{
    if (Quest const* quest = sObjectMgr->GetQuestTemplate(questId))
    {
        // Destroy quest items on quest abandon.
        for (uint8 i = 0; i < QUEST_ITEM_OBJECTIVES_COUNT; ++i)
            if (ItemTemplate const* itemTemplate = sObjectMgr->GetItemTemplate(quest->RequiredItemId[i]))
                if (quest->RequiredItemCount[i] > 0 && itemTemplate->Bonding == BIND_QUEST_ITEM)
                    DestroyItemCount(quest->RequiredItemId[i], 9999, true);

        for (uint8 i = 0; i < QUEST_SOURCE_ITEM_IDS_COUNT; ++i)
            if (ItemTemplate const* itemTemplate = sObjectMgr->GetItemTemplate(quest->ItemDrop[i]))
                if (quest->ItemDropQuantity[i] > 0 && itemTemplate->Bonding == BIND_QUEST_ITEM)
                    DestroyItemCount(quest->ItemDrop[i], 9999, true);
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
            SendCanTakeQuestResponse(INVALIDREASON_DONT_HAVE_REQ);
            TC_LOG_DEBUG("misc", "Player::SatisfyQuestSkill: Sent INVALIDREASON_DONT_HAVE_REQ (QuestID: %u) because player '%s' (%s) doesn't have the required skill value.",
                qInfo->GetQuestId(), GetName().c_str(), GetGUID().ToString().c_str());
        }

        return false;
    }

    return true;
}

bool Player::SatisfyQuestLevel(Quest const* qInfo, bool msg) const
{
    if (GetLevel() < qInfo->GetMinLevel())
    {
        if (msg)
        {
            SendCanTakeQuestResponse(INVALIDREASON_QUEST_FAILED_LOW_LEVEL);
            TC_LOG_DEBUG("misc", "Player::SatisfyQuestLevel: Sent INVALIDREASON_QUEST_FAILED_LOW_LEVEL (QuestID: %u) because player '%s' (%s) doesn't have the required (min) level.",
                qInfo->GetQuestId(), GetName().c_str(), GetGUID().ToString().c_str());
        }
        return false;
    }

    if (qInfo->GetMaxLevel() > 0 && GetLevel() > qInfo->GetMaxLevel())
    {
        if (msg)
        {
            SendCanTakeQuestResponse(INVALIDREASON_DONT_HAVE_REQ); // There doesn't seem to be a specific response for too high player level
            TC_LOG_DEBUG("misc", "Player::SatisfyQuestLevel: Sent INVALIDREASON_DONT_HAVE_REQ (QuestID: %u) because player '%s' (%s) doesn't have the required (max) level.",
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
        WorldPacket data(SMSG_QUESTLOG_FULL, 0);
        SendDirectMessage(&data);
    }
    return false;
}

bool Player::SatisfyQuestDependentQuests(Quest const* qInfo, bool msg) const
{
    return SatisfyQuestPreviousQuest(qInfo, msg) && SatisfyQuestDependentPreviousQuests(qInfo, msg) &&
           SatisfyQuestBreadcrumbQuest(qInfo, msg) && SatisfyQuestDependentBreadcrumbQuests(qInfo, msg);
}

bool Player::SatisfyQuestPreviousQuest(Quest const* qInfo, bool msg) const
{
    // No previous quest (might be first quest in a series)
    if (!qInfo->GetPrevQuestId())
        return true;

    uint32 prevId = std::abs(qInfo->GetPrevQuestId());
    // If positive previous quest rewarded, return true
    if (qInfo->GetPrevQuestId() > 0 && m_RewardedQuests.count(prevId) > 0)
        return true;

    // If negative previous quest active, return true
    if (qInfo->GetPrevQuestId() < 0 && GetQuestStatus(prevId) == QUEST_STATUS_INCOMPLETE)
        return true;

    // Has positive prev. quest in non-rewarded state
    // and negative prev. quest in non-active state
    if (msg)
    {
        SendCanTakeQuestResponse(INVALIDREASON_DONT_HAVE_REQ);
        TC_LOG_DEBUG("misc", "Player::SatisfyQuestPreviousQuest: Sent INVALIDREASON_DONT_HAVE_REQ (QuestID: %u) because player '%s' (%s) doesn't have required quest %u.",
            qInfo->GetQuestId(), GetName().c_str(), GetGUID().ToString().c_str(), prevId);
    }

    return false;
}

bool Player::SatisfyQuestDependentPreviousQuests(Quest const* qInfo, bool msg) const
{
    // No previous quest (might be first quest in a series)
    if (qInfo->DependentPreviousQuests.empty())
        return true;

    for (uint32 prevId : qInfo->DependentPreviousQuests)
    {
        // checked in startup
        Quest const* questInfo = sObjectMgr->GetQuestTemplate(prevId);
        ASSERT(questInfo);

        // If any of the previous quests completed, return true
        if (IsQuestRewarded(prevId))
        {
            // skip one-from-all exclusive group
            if (questInfo->GetExclusiveGroup() >= 0)
                return true;

            // each-from-all exclusive group (< 0)
            // can be start if only all quests in prev quest exclusive group completed and rewarded
            auto bounds = sObjectMgr->GetExclusiveQuestGroupBounds(questInfo->GetExclusiveGroup());
            for (auto itr = bounds.first; itr != bounds.second; ++itr)
            {
                // skip checked quest id, only state of other quests in group is interesting
                uint32 exclusiveQuestId = itr->second;
                if (exclusiveQuestId == prevId)
                    continue;

                // alternative quest from group also must be completed and rewarded (reported)
                if (!IsQuestRewarded(exclusiveQuestId))
                {
                    if (msg)
                    {
                        SendCanTakeQuestResponse(INVALIDREASON_DONT_HAVE_REQ);
                        TC_LOG_DEBUG("misc", "Player::SatisfyQuestDependentPreviousQuests: Sent INVALIDREASON_DONT_HAVE_REQ (QuestID: %u) because player '%s' (%s) doesn't have the required quest (1).",
                            qInfo->GetQuestId(), GetName().c_str(), GetGUID().ToString().c_str());
                    }

                    return false;
                }
            }

            return true;
        }
    }

    // Has only prev. quests in non-rewarded state
    if (msg)
    {
        SendCanTakeQuestResponse(INVALIDREASON_DONT_HAVE_REQ);
        TC_LOG_DEBUG("misc", "Player::SatisfyQuestDependentPreviousQuests: Sent INVALIDREASON_DONT_HAVE_REQ (QuestID: %u) because player '%s' (%s) doesn't have required quest (2).",
            qInfo->GetQuestId(), GetName().c_str(), GetGUID().ToString().c_str());
    }

    return false;
}

bool Player::SatisfyQuestBreadcrumbQuest(Quest const* qInfo, bool msg) const
{
    uint32 breadcrumbTargetQuestId = std::abs(qInfo->GetBreadcrumbForQuestId());

    //If this is not a breadcrumb quest.
    if (!breadcrumbTargetQuestId)
        return true;

    // If the target quest is not available
    if (!CanTakeQuest(sObjectMgr->GetQuestTemplate(breadcrumbTargetQuestId), false))
    {
        if (msg)
        {
            SendCanTakeQuestResponse(INVALIDREASON_DONT_HAVE_REQ);
            TC_LOG_DEBUG("misc", "Player::SatisfyQuestBreadcrumbQuest: Sent INVALIDREASON_DONT_HAVE_REQ (QuestID: %u) because target quest (QuestID: %u) is not available to player '%s' (%s).",
                qInfo->GetQuestId(), breadcrumbTargetQuestId, GetName().c_str(), GetGUID().ToString().c_str());
        }

        return false;
    }

    return true;
}

bool Player::SatisfyQuestDependentBreadcrumbQuests(Quest const* qInfo, bool msg) const
{
    for (uint32 breadcrumbQuestId : qInfo->DependentBreadcrumbQuests)
    {
        QuestStatus status = GetQuestStatus(breadcrumbQuestId);
        // If any of the breadcrumb quests are in the quest log, return false.
        if (status == QUEST_STATUS_INCOMPLETE || status == QUEST_STATUS_COMPLETE || status == QUEST_STATUS_FAILED)
        {
            if (msg)
            {
                SendCanTakeQuestResponse(INVALIDREASON_DONT_HAVE_REQ);
                TC_LOG_DEBUG("misc", "Player::SatisfyQuestDependentBreadcrumbQuests: Sent INVALIDREASON_DONT_HAVE_REQ (QuestID: %u) because player '%s' (%s) has a breadcrumb quest towards this quest in the quest log.",
                    qInfo->GetQuestId(), GetName().c_str(), GetGUID().ToString().c_str());
            }

            return false;
        }
    }
    return true;
}

bool Player::SatisfyQuestClass(Quest const* qInfo, bool msg) const
{
    uint32 reqClass = qInfo->GetRequiredClasses();

    if (reqClass == 0)
        return true;

    if ((reqClass & GetClassMask()) == 0)
    {
        if (msg)
        {
            SendCanTakeQuestResponse(INVALIDREASON_DONT_HAVE_REQ);
            TC_LOG_DEBUG("misc", "Player::SatisfyQuestClass: Sent INVALIDREASON_DONT_HAVE_REQ (QuestID: %u) because player '%s' (%s) doesn't have required class.",
                qInfo->GetQuestId(), GetName().c_str(), GetGUID().ToString().c_str());
        }

        return false;
    }

    return true;
}

bool Player::SatisfyQuestRace(Quest const* qInfo, bool msg) const
{
    uint32 reqraces = qInfo->GetAllowableRaces();
    if (reqraces == 0)
        return true;
    if ((reqraces & GetRaceMask()) == 0)
    {
        if (msg)
        {
            SendCanTakeQuestResponse(INVALIDREASON_QUEST_FAILED_WRONG_RACE);
            TC_LOG_DEBUG("misc", "Player::SatisfyQuestRace: Sent INVALIDREASON_QUEST_FAILED_WRONG_RACE (QuestID: %u) because player '%s' (%s) doesn't have required race.",
                qInfo->GetQuestId(), GetName().c_str(), GetGUID().ToString().c_str());

        }
        return false;
    }
    return true;
}

bool Player::SatisfyQuestReputation(Quest const* qInfo, bool msg) const
{
    uint32 fIdMin = qInfo->GetRequiredMinRepFaction();      //Min required rep
    if (fIdMin && GetReputationMgr().GetReputation(fIdMin) < qInfo->GetRequiredMinRepValue())
    {
        if (msg)
        {
            SendCanTakeQuestResponse(INVALIDREASON_DONT_HAVE_REQ);
            TC_LOG_DEBUG("misc", "Player::SatisfyQuestReputation: Sent INVALIDREASON_DONT_HAVE_REQ (QuestID: %u) because player '%s' (%s) doesn't required reputation (min).",
                qInfo->GetQuestId(), GetName().c_str(), GetGUID().ToString().c_str());
        }
        return false;
    }

    uint32 fIdMax = qInfo->GetRequiredMaxRepFaction();      //Max required rep
    if (fIdMax && GetReputationMgr().GetReputation(fIdMax) >= qInfo->GetRequiredMaxRepValue())
    {
        if (msg)
        {
            SendCanTakeQuestResponse(INVALIDREASON_DONT_HAVE_REQ);
            TC_LOG_DEBUG("misc", "SatisfyQuestReputation: Sent INVALIDREASON_DONT_HAVE_REQ (QuestID: %u) because player '%s' (%s) doesn't required reputation (max).",
                qInfo->GetQuestId(), GetName().c_str(), GetGUID().ToString().c_str());
        }
        return false;
    }

    // ReputationObjective2 does not seem to be an objective requirement but a requirement
    // to be able to accept the quest
    uint32 fIdObj = qInfo->GetRepObjectiveFaction2();
    if (fIdObj && GetReputationMgr().GetReputation(fIdObj) >= qInfo->GetRepObjectiveValue2())
    {
        if (msg)
        {
            SendCanTakeQuestResponse(INVALIDREASON_DONT_HAVE_REQ);
            TC_LOG_DEBUG("misc", "SatisfyQuestReputation: Sent INVALIDREASON_DONT_HAVE_REQ (questId: %u) because player does not have the required reputation (ReputationObjective2).", qInfo->GetQuestId());
        }
        return false;
    }

    return true;
}

bool Player::SatisfyQuestStatus(Quest const* qInfo, bool msg) const
{
    if (GetQuestStatus(qInfo->GetQuestId()) == QUEST_STATUS_REWARDED)
    {
        if (msg)
        {
            SendCanTakeQuestResponse(INVALIDREASON_QUEST_ALREADY_DONE);
            TC_LOG_DEBUG("misc", "Player::SatisfyQuestStatus: Sent QUEST_STATUS_REWARDED (QuestID: %u) because player '%s' (%s) quest status is already REWARDED.",
                qInfo->GetQuestId(), GetName().c_str(), GetGUID().ToString().c_str());
        }
        return false;
    }

    if (GetQuestStatus(qInfo->GetQuestId()) != QUEST_STATUS_NONE)
    {
        if (msg)
        {
            SendCanTakeQuestResponse(INVALIDREASON_QUEST_ALREADY_ON);
            TC_LOG_DEBUG("misc", "Player::SatisfyQuestStatus: Sent INVALIDREASON_QUEST_ALREADY_ON (QuestID: %u) because player '%s' (%s) quest status is not NONE.",
                qInfo->GetQuestId(), GetName().c_str(), GetGUID().ToString().c_str());
        }
        return false;
    }
    return true;
}

bool Player::SatisfyQuestConditions(Quest const* qInfo, bool msg) const
{
    if (!sConditionMgr->IsObjectMeetingNotGroupedConditions(CONDITION_SOURCE_TYPE_QUEST_AVAILABLE, qInfo->GetQuestId(), const_cast<Player*>(this)))
    {
        if (msg)
        {
            SendCanTakeQuestResponse(INVALIDREASON_DONT_HAVE_REQ);
            TC_LOG_DEBUG("misc", "Player::SatisfyQuestConditions: Sent INVALIDREASON_DONT_HAVE_REQ (QuestID: %u) because player '%s' (%s) doesn't meet conditions.",
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
            SendCanTakeQuestResponse(INVALIDREASON_QUEST_ONLY_ONE_TIMED);
            TC_LOG_DEBUG("misc", "Player::SatisfyQuestTimed: Sent INVALIDREASON_QUEST_ONLY_ONE_TIMED (QuestID: %u) because player '%s' (%s) is already on a timed quest.",
                qInfo->GetQuestId(), GetName().c_str(), GetGUID().ToString().c_str());
        }
        return false;
    }
    return true;
}

bool Player::SatisfyQuestExclusiveGroup(Quest const* qInfo, bool msg) const
{
    // non positive exclusive group, if > 0 then can be start if any other quest in exclusive group already started/completed
    if (qInfo->GetExclusiveGroup() <= 0)
        return true;

    auto bounds = sObjectMgr->GetExclusiveQuestGroupBounds(qInfo->GetExclusiveGroup());
    for (auto itr = bounds.first; itr != bounds.second; ++itr)
    {
        uint32 exclude_Id = itr->second;

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
                SendCanTakeQuestResponse(INVALIDREASON_DONT_HAVE_REQ);
                TC_LOG_DEBUG("misc", "Player::SatisfyQuestExclusiveGroup: Sent INVALIDREASON_DONT_HAVE_REQ (QuestID: %u) because player '%s' (%s) already did daily quests in exclusive group.",
                    qInfo->GetQuestId(), GetName().c_str(), GetGUID().ToString().c_str());
            }

            return false;
        }

        // alternative quest already started or completed - but don't check rewarded states if both are repeatable
        if (GetQuestStatus(exclude_Id) != QUEST_STATUS_NONE || (!(qInfo->IsRepeatable() && Nquest->IsRepeatable()) && GetQuestRewardStatus(exclude_Id)))
        {
            if (msg)
            {
                SendCanTakeQuestResponse(INVALIDREASON_DONT_HAVE_REQ);
                TC_LOG_DEBUG("misc", "Player::SatisfyQuestExclusiveGroup: Sent INVALIDREASON_DONT_HAVE_REQ (QuestID: %u) because player '%s' (%s) already did quest in exclusive group.",
                    qInfo->GetQuestId(), GetName().c_str(), GetGUID().ToString().c_str());
            }
            return false;
        }
    }
    return true;
}

bool Player::SatisfyQuestDay(Quest const* qInfo, bool msg) const
{
    if (!qInfo->IsDaily() && !qInfo->IsDFQuest())
        return true;

    if (qInfo->IsDFQuest())
    {
        if (m_DFQuests.find(qInfo->GetQuestId()) != m_DFQuests.end())
            return false;

        return true;
    }

    bool have_slot = false;
    for (uint32 quest_daily_idx = 0; quest_daily_idx < PLAYER_MAX_DAILY_QUESTS; ++quest_daily_idx)
    {
        uint32 id = GetUInt32Value(PLAYER_FIELD_DAILY_QUESTS_1+quest_daily_idx);
        if (qInfo->GetQuestId() == id)
            return false;

        if (!id)
            have_slot = true;
    }

    if (!have_slot)
    {
        if (msg)
        {
            SendCanTakeQuestResponse(INVALIDREASON_DAILY_QUESTS_REMAINING);
            TC_LOG_DEBUG("misc", "SatisfyQuestDay: Sent INVALIDREASON_DAILY_QUESTS_REMAINING (questId: %u) because player already did all possible quests today.", qInfo->GetQuestId());
        }
        return false;
    }

    return true;
}

bool Player::SatisfyQuestWeek(Quest const* qInfo, bool /*msg*/) const
{
    if (!qInfo->IsWeekly() || m_weeklyquests.empty())
        return true;

    // if not found in cooldown list
    return m_weeklyquests.find(qInfo->GetQuestId()) == m_weeklyquests.end();
}

bool Player::SatisfyQuestSeasonal(Quest const* qInfo, bool /*msg*/) const
{
    if (!qInfo->IsSeasonal() || m_seasonalquests.empty())
        return true;

    auto itr = m_seasonalquests.find(qInfo->GetEventIdForQuest());
    if (itr == m_seasonalquests.end() || itr->second.empty())
        return true;

    // if not found in cooldown list
    return itr->second.find(qInfo->GetQuestId()) == itr->second.end();
}

bool Player::SatisfyQuestMonth(Quest const* qInfo, bool /*msg*/) const
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
        // Don't give source item if it is the same item used to start the quest
        ItemTemplate const* itemTemplate = ASSERT_NOTNULL(sObjectMgr->GetItemTemplate(srcitem));
        if (quest->GetQuestId() == itemTemplate->StartQuest)
            return true;

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
        else if (msg == EQUIP_ERR_CANT_CARRY_MORE_OF_THIS)
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

            // There are two cases where the source item is not destroyed:
            // - Item cannot be unequipped (example: non-empty bags)
            // - The source item is the item that started the quest, so the player is supposed to keep it (otherwise it was already destroyed in AddQuestAndCheckCompletion())
            InventoryResult res = CanUnequipItems(srcItemId, count);
            if (res != EQUIP_ERR_OK)
            {
                if (msg)
                    SendEquipError(res, nullptr, nullptr, srcItemId);
                return false;
            }

            ASSERT(item);
            if (item->StartQuest != questId)
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
            return !SatisfyQuestSeasonal(qInfo, false);
        // for repeatable quests: rewarded field is set after first reward only to prevent getting XP more than once
        if (!qInfo->IsRepeatable())
            return IsQuestRewarded(quest_id);

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

        if (GetQuestRewardStatus(quest_id))
            return QUEST_STATUS_REWARDED;
    }
    return QUEST_STATUS_NONE;
}

bool Player::CanShareQuest(uint32 quest_id) const
{
    Quest const* qInfo = sObjectMgr->GetQuestTemplate(quest_id);
    if (qInfo && qInfo->HasFlag(QUEST_FLAGS_SHARABLE))
    {
        QuestStatusMap::const_iterator itr = m_QuestStatus.find(quest_id);
        if (itr != m_QuestStatus.end())
        {
            // in pool and not currently available (wintergrasp weekly, dalaran weekly) - can't share
            if (sQuestPoolMgr->IsQuestActive(quest_id))
            {
                SendPushToPartyResponse(this, QUEST_PARTY_MSG_CANT_BE_SHARED_TODAY);
                return false;
            }

            return true;
        }
    }
    return false;
}

void Player::SetQuestStatus(uint32 questId, QuestStatus status, bool update /*= true*/)
{
    if (Quest const* quest = sObjectMgr->GetQuestTemplate(questId))
    {
        m_QuestStatus[questId].Status = status;

        if (!quest->IsAutoComplete())
            m_QuestStatusSave[questId] = QUEST_DEFAULT_SAVE_TYPE;
    }

    if (update)
        SendQuestUpdate(questId);

    sScriptMgr->OnQuestStatusChange(this, questId);
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

    // Remove seasonal quest also
    Quest const* qInfo = sObjectMgr->GetQuestTemplate(questId);
    ASSERT(qInfo);
    if (qInfo->IsSeasonal())
    {
        uint16 eventId = qInfo->GetEventIdForQuest();
        if (m_seasonalquests.find(eventId) != m_seasonalquests.end())
        {
            m_seasonalquests[eventId].erase(questId);
            m_SeasonalQuestChanged = true;
        }
    }

    if (update)
        SendQuestUpdate(questId);
}

void Player::SendQuestUpdate(uint32 questId)
{
    uint32 zone = 0, area = 0;
    GetZoneAndAreaId(zone, area);

    SpellAreaForQuestAreaMapBounds saBounds = sSpellMgr->GetSpellAreaForQuestAreaMapBounds(area, questId);

    if (saBounds.first != saBounds.second)
    {
        for (SpellAreaForQuestAreaMap::const_iterator itr = saBounds.first; itr != saBounds.second; ++itr)
        {
            if (!itr->second->IsFitToRequirements(this, zone, area))
                RemoveAurasDueToSpell(itr->second->spellId);
            else if (itr->second->autocast)
                if (!HasAura(itr->second->spellId))
                    CastSpell(this, itr->second->spellId, true);
        }
    }

    UpdateVisibleGameobjectsOrSpellClicks();
}

QuestGiverStatus Player::GetQuestDialogStatus(Object* questgiver)
{
    QuestRelationResult qr, qir;

    switch (questgiver->GetTypeId())
    {
        case TYPEID_GAMEOBJECT:
        {
            if (auto ai = questgiver->ToGameObject()->AI())
                if (auto questStatus = ai->GetDialogStatus(this))
                    return *questStatus;
            qr = sObjectMgr->GetGOQuestRelations(questgiver->GetEntry());
            qir = sObjectMgr->GetGOQuestInvolvedRelations(questgiver->GetEntry());
            break;
        }
        case TYPEID_UNIT:
        {
            if (auto ai = questgiver->ToCreature()->AI())
                if (auto questStatus = ai->GetDialogStatus(this))
                    return *questStatus;
            qr = sObjectMgr->GetCreatureQuestRelations(questgiver->GetEntry());
            qir = sObjectMgr->GetCreatureQuestInvolvedRelations(questgiver->GetEntry());
            break;
        }
        default:
            // it's impossible, but check
            TC_LOG_ERROR("entities.player.quest", "GetQuestDialogStatus called for unexpected type %u", questgiver->GetTypeId());
            return DIALOG_STATUS_NONE;
    }

    QuestGiverStatus result = DIALOG_STATUS_NONE;

    for (uint32 questId : qir)
    {
        QuestGiverStatus result2 = DIALOG_STATUS_NONE;
        Quest const* quest = sObjectMgr->GetQuestTemplate(questId);
        if (!quest)
            continue;

        QuestStatus status = GetQuestStatus(questId);
        if (status == QUEST_STATUS_COMPLETE && !GetQuestRewardStatus(questId))
            result2 = DIALOG_STATUS_REWARD;
        else if (status == QUEST_STATUS_INCOMPLETE)
            result2 = DIALOG_STATUS_INCOMPLETE;

        if (quest->IsAutoComplete() && CanTakeQuest(quest, false) && quest->IsRepeatable() && !quest->IsDailyOrWeekly())
            result2 = DIALOG_STATUS_REWARD_REP;

        if (result2 > result)
            result = result2;
    }

    for (uint32 questId : qr)
    {
        QuestGiverStatus result2 = DIALOG_STATUS_NONE;
        Quest const* quest = sObjectMgr->GetQuestTemplate(questId);
        if (!quest)
            continue;

        if (!sConditionMgr->IsObjectMeetingNotGroupedConditions(CONDITION_SOURCE_TYPE_QUEST_AVAILABLE, quest->GetQuestId(), this))
            continue;

        QuestStatus status = GetQuestStatus(questId);
        if (status == QUEST_STATUS_NONE)
        {
            if (CanSeeStartQuest(quest))
            {
                if (SatisfyQuestLevel(quest, false))
                {
                    bool isNotLowLevelQuest = GetLevel() <= (GetQuestLevel(quest) + sWorld->getIntConfig(CONFIG_QUEST_LOW_LEVEL_HIDE_DIFF));
                    if (quest->IsRepeatable())
                    {
                        if (quest->IsDaily())
                        {
                            if (isNotLowLevelQuest)
                                result2 = DIALOG_STATUS_AVAILABLE_REP;
                            else
                                result2 = DIALOG_STATUS_LOW_LEVEL_AVAILABLE_REP;
                        }
                        else if (quest->IsWeekly() || quest->IsMonthly())
                        {
                            if (isNotLowLevelQuest)
                                result2 = DIALOG_STATUS_AVAILABLE;
                            else
                                result2 = DIALOG_STATUS_LOW_LEVEL_AVAILABLE;
                        }
                        else if (quest->IsAutoComplete())
                        {
                            if (isNotLowLevelQuest)
                                result2 = DIALOG_STATUS_REWARD_REP;
                            else
                                result2 = DIALOG_STATUS_LOW_LEVEL_REWARD_REP;
                        }
                        else
                        {
                            if (isNotLowLevelQuest)
                                result2 = DIALOG_STATUS_AVAILABLE;
                            else
                                result2 = DIALOG_STATUS_LOW_LEVEL_AVAILABLE;
                        }
                    }
                    else if (isNotLowLevelQuest)
                        result2 = DIALOG_STATUS_AVAILABLE;
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

    auto itr = m_QuestStatus.find(quest_id);
    if (itr != m_QuestStatus.end())
        for (uint8 j = 0; j < QUEST_OBJECTIVES_COUNT; ++j)
            if (qInfo->RequiredNpcOrGo[j] == entry)
                return itr->second.CreatureOrGOCount[j];

    return 0;
}

void Player::AdjustQuestReqItemCount(Quest const* quest, QuestStatusData& questStatusData)
{
    if (quest->HasSpecialFlag(QUEST_SPECIAL_FLAGS_DELIVER))
    {
        for (uint8 i = 0; i < QUEST_ITEM_OBJECTIVES_COUNT; ++i)
        {
            uint32 reqitemcount = quest->RequiredItemCount[i];
            if (reqitemcount != 0)
            {
                uint32 curitemcount = GetItemCount(quest->RequiredItemId[i], true);

                questStatusData.ItemCount[i] = std::min(curitemcount, reqitemcount);
                m_QuestStatusSave[quest->GetQuestId()] = QUEST_DEFAULT_SAVE_TYPE;
            }
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
    return GetUInt32Value(PLAYER_QUEST_LOG_1_1 + slot * MAX_QUEST_OFFSET + QUEST_ID_OFFSET);
}

uint32 Player::GetQuestSlotState(uint16 slot)   const
{
    return GetUInt32Value(PLAYER_QUEST_LOG_1_1 + slot * MAX_QUEST_OFFSET + QUEST_STATE_OFFSET);
}

uint16 Player::GetQuestSlotCounter(uint16 slot, uint8 counter) const
{
    return (uint16)(GetUInt64Value(PLAYER_QUEST_LOG_1_1 + slot * MAX_QUEST_OFFSET + QUEST_COUNTS_OFFSET) >> (counter * 16));
}

uint32 Player::GetQuestSlotTime(uint16 slot) const
{
    return GetUInt32Value(PLAYER_QUEST_LOG_1_1 + slot * MAX_QUEST_OFFSET + QUEST_TIME_OFFSET);
}

void Player::SetQuestSlot(uint16 slot, uint32 quest_id, uint32 timer /*= 0*/)
{
    SetUInt32Value(PLAYER_QUEST_LOG_1_1 + slot * MAX_QUEST_OFFSET + QUEST_ID_OFFSET, quest_id);
    SetUInt32Value(PLAYER_QUEST_LOG_1_1 + slot * MAX_QUEST_OFFSET + QUEST_STATE_OFFSET, 0);
    SetUInt32Value(PLAYER_QUEST_LOG_1_1 + slot * MAX_QUEST_OFFSET + QUEST_COUNTS_OFFSET, 0);
    SetUInt32Value(PLAYER_QUEST_LOG_1_1 + slot * MAX_QUEST_OFFSET + QUEST_COUNTS_OFFSET + 1, 0);
    SetUInt32Value(PLAYER_QUEST_LOG_1_1 + slot * MAX_QUEST_OFFSET + QUEST_TIME_OFFSET, timer);
}

void Player::SetQuestSlotCounter(uint16 slot, uint8 counter, uint16 count)
{
    uint64 val = GetUInt64Value(PLAYER_QUEST_LOG_1_1 + slot * MAX_QUEST_OFFSET + QUEST_COUNTS_OFFSET);
    val &= ~((uint64)0xFFFF << (counter * 16));
    val |= ((uint64)count << (counter * 16));
    SetUInt64Value(PLAYER_QUEST_LOG_1_1 + slot * MAX_QUEST_OFFSET + QUEST_COUNTS_OFFSET, val);
}

void Player::SetQuestSlotState(uint16 slot, uint32 state)
{
    SetFlag(PLAYER_QUEST_LOG_1_1 + slot * MAX_QUEST_OFFSET + QUEST_STATE_OFFSET, state);
}

void Player::RemoveQuestSlotState(uint16 slot, uint32 state)
{
    RemoveFlag(PLAYER_QUEST_LOG_1_1 + slot * MAX_QUEST_OFFSET + QUEST_STATE_OFFSET, state);
}

void Player::SetQuestSlotTimer(uint16 slot, uint32 timer)
{
    SetUInt32Value(PLAYER_QUEST_LOG_1_1 + slot * MAX_QUEST_OFFSET + QUEST_TIME_OFFSET, timer);
}

void Player::SwapQuestSlot(uint16 slot1, uint16 slot2)
{
    for (int i = 0; i < MAX_QUEST_OFFSET; ++i)
    {
        uint32 temp1 = GetUInt32Value(PLAYER_QUEST_LOG_1_1 + MAX_QUEST_OFFSET * slot1 + i);
        uint32 temp2 = GetUInt32Value(PLAYER_QUEST_LOG_1_1 + MAX_QUEST_OFFSET * slot2 + i);

        SetUInt32Value(PLAYER_QUEST_LOG_1_1 + MAX_QUEST_OFFSET * slot1 + i, temp2);
        SetUInt32Value(PLAYER_QUEST_LOG_1_1 + MAX_QUEST_OFFSET * slot2 + i, temp1);
    }
}

void Player::AreaExploredOrEventHappens(uint32 questId)
{
    if (questId)
    {
        uint16 log_slot = FindQuestSlot(questId);
        if (log_slot < MAX_QUEST_LOG_SIZE)
        {
            QuestStatusData& q_status = m_QuestStatus[questId];

            // Dont complete failed quest
            if (!q_status.Explored && q_status.Status != QUEST_STATUS_FAILED)
            {
                q_status.Explored = true;
                m_QuestStatusSave[questId] = QUEST_DEFAULT_SAVE_TYPE;

                SendQuestComplete(questId);
            }
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

        for (uint8 j = 0; j < QUEST_ITEM_OBJECTIVES_COUNT; ++j)
        {
            uint32 reqitem = qInfo->RequiredItemId[j];
            if (reqitem == entry)
            {
                uint32 reqitemcount = qInfo->RequiredItemCount[j];
                uint16 curitemcount = q_status.ItemCount[j];
                if (curitemcount < reqitemcount)
                {
                    q_status.ItemCount[j] = std::min<uint16>(q_status.ItemCount[j] + count, reqitemcount);
                    m_QuestStatusSave[questid] = QUEST_DEFAULT_SAVE_TYPE;
                }
                if (CanCompleteQuest(questid))
                    CompleteQuest(questid);
                else if (q_status.ItemCount[j] == reqitemcount) // Send quest update when an objective is completed
                    UpdateVisibleGameobjectsOrSpellClicks();
            }
        }
    }
    UpdateVisibleGameobjectsOrSpellClicks();
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

        for (uint8 j = 0; j < QUEST_ITEM_OBJECTIVES_COUNT; ++j)
        {
            uint32 reqitem = qInfo->RequiredItemId[j];
            if (reqitem == entry)
            {
                QuestStatusData& q_status = m_QuestStatus[questid];

                uint32 reqitemcount = qInfo->RequiredItemCount[j];
                uint16 curitemcount = q_status.ItemCount[j];

                if (q_status.ItemCount[j] >= reqitemcount) // we may have more than what the status shows
                    curitemcount = GetItemCount(entry, false);

                uint16 newItemCount = (count > curitemcount) ? 0 : curitemcount - count;
                newItemCount = std::min<uint16>(newItemCount, reqitemcount);
                if (newItemCount != q_status.ItemCount[j])
                {
                    q_status.ItemCount[j] = newItemCount;
                    m_QuestStatusSave[questid] = QUEST_DEFAULT_SAVE_TYPE;
                    IncompleteQuest(questid);
                }
                return;
            }
        }
    }
    UpdateVisibleGameobjectsOrSpellClicks();
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
    uint16 addkillcount = 1;
    uint32 real_entry = entry;
    Creature* killed = nullptr;
    if (guid)
    {
        killed = GetMap()->GetCreature(guid);
        if (killed && killed->GetEntry())
            real_entry = killed->GetEntry();
    }

    StartTimedAchievement(ACHIEVEMENT_TIMED_TYPE_CREATURE, real_entry);   // MUST BE CALLED FIRST
    UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_KILL_CREATURE, real_entry, addkillcount, killed);

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
        if (q_status.Status == QUEST_STATUS_INCOMPLETE && (!GetGroup() || !GetGroup()->isRaidGroup() || qInfo->IsAllowedInRaid(GetMap()->GetDifficulty())))
        {
            if (qInfo->HasSpecialFlag(QUEST_SPECIAL_FLAGS_KILL) /*&& !qInfo->HasSpecialFlag(QUEST_SPECIAL_FLAGS_CAST)*/)
            {
                for (uint8 j = 0; j < QUEST_OBJECTIVES_COUNT; ++j)
                {
                    // skip GO activate objective or none
                    if (qInfo->RequiredNpcOrGo[j] <= 0)
                        continue;

                    uint32 reqkill = qInfo->RequiredNpcOrGo[j];

                    if (reqkill == real_entry)
                    {
                        uint32 reqkillcount = qInfo->RequiredNpcOrGoCount[j];
                        uint16 curkillcount = q_status.CreatureOrGOCount[j];
                        if (curkillcount < reqkillcount)
                        {
                            q_status.CreatureOrGOCount[j] = curkillcount + addkillcount;

                            m_QuestStatusSave[questid] = QUEST_DEFAULT_SAVE_TYPE;

                            SendQuestUpdateAddCreatureOrGo(qInfo, guid, j, curkillcount, addkillcount);
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

void Player::KilledPlayerCredit(uint16 count)
{
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
        if (q_status.Status == QUEST_STATUS_INCOMPLETE && (!GetGroup() || !GetGroup()->isRaidGroup() || qInfo->IsAllowedInRaid(GetMap()->GetDifficulty())))
        {
            // PvP Killing quest require player to be in same zone as quest zone (only 2 quests so no doubt)
            if (qInfo->HasSpecialFlag(QUEST_SPECIAL_FLAGS_PLAYER_KILL) && GetZoneId() == static_cast<uint32>(qInfo->GetZoneOrSort()))
            {
                KilledPlayerCreditForQuest(count, qInfo);
                break; // there is only one quest per zone
            }
        }
    }
}

void Player::KilledPlayerCreditForQuest(uint16 count, Quest const* quest)
{
    uint32 const questId = quest->GetQuestId();
    auto it = m_QuestStatus.find(questId);
    if (it == m_QuestStatus.end())
        return;
    QuestStatusData& questStatus = it->second;

    uint16 curKill = questStatus.PlayerCount;
    uint32 reqKill = quest->GetPlayersSlain();

    if (curKill < reqKill)
    {
        count = std::min<uint16>(reqKill - curKill, count);
        questStatus.PlayerCount = curKill + count;

        m_QuestStatusSave[quest->GetQuestId()] = QUEST_DEFAULT_SAVE_TYPE;

        SendQuestUpdateAddPlayer(quest, curKill, count);
    }

    if (CanCompleteQuest(questId))
        CompleteQuest(questId);
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
                for (uint8 j = 0; j < QUEST_OBJECTIVES_COUNT; ++j)
                {
                    uint32 reqTarget = 0;

                    // GO activate objective
                    if (qInfo->RequiredNpcOrGo[j] < 0)
                        // checked at quest_template loading
                        reqTarget = - qInfo->RequiredNpcOrGo[j];

                    // other not this creature/GO related objectives
                    if (reqTarget != entry)
                        continue;

                    uint32 reqCastCount = qInfo->RequiredNpcOrGoCount[j];
                    uint16 curCastCount = q_status.CreatureOrGOCount[j];
                    if (curCastCount < reqCastCount)
                    {
                        q_status.CreatureOrGOCount[j] = curCastCount + addCastCount;

                        m_QuestStatusSave[questid] = QUEST_DEFAULT_SAVE_TYPE;

                        SendQuestUpdateAddCreatureOrGo(qInfo, guid, j, curCastCount, addCastCount);
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
                for (uint8 j = 0; j < QUEST_OBJECTIVES_COUNT; ++j)
                {
                    // skip gameobject objectives
                    if (qInfo->RequiredNpcOrGo[j] < 0)
                        continue;

                    uint32 reqTarget = 0;

                    if (qInfo->RequiredNpcOrGo[j] > 0)    // creature activate objectives
                                                            // checked at quest_template loading
                        reqTarget = qInfo->RequiredNpcOrGo[j];
                    else
                        continue;

                    if (reqTarget == entry)
                    {
                        uint32 reqTalkCount = qInfo->RequiredNpcOrGoCount[j];
                        uint16 curTalkCount = q_status.CreatureOrGOCount[j];
                        if (curTalkCount < reqTalkCount)
                        {
                            q_status.CreatureOrGOCount[j] = curTalkCount + addTalkCount;

                            m_QuestStatusSave[questid] = QUEST_DEFAULT_SAVE_TYPE;

                            SendQuestUpdateAddCreatureOrGo(qInfo, guid, j, curTalkCount, addTalkCount);
                        }
                        if (CanCompleteQuest(questid))
                            CompleteQuest(questid);

                        // same objective target can be in many active quests, but not in 2 objectives for single quest (code optimization).
                        continue;
                    }
                }
            }
        }
    }
}

void Player::MoneyChanged(uint32 count)
{
    for (uint8 i = 0; i < MAX_QUEST_LOG_SIZE; ++i)
    {
        uint32 questid = GetQuestSlotQuestId(i);
        if (!questid)
            continue;

        Quest const* qInfo = sObjectMgr->GetQuestTemplate(questid);
        if (qInfo && qInfo->GetRewOrReqMoney() < 0)
        {
            QuestStatusData& q_status = m_QuestStatus[questid];

            if (q_status.Status == QUEST_STATUS_INCOMPLETE)
            {
                if (int32(count) >= -qInfo->GetRewOrReqMoney())
                {
                    if (CanCompleteQuest(questid))
                        CompleteQuest(questid);
                }
            }
            else if (q_status.Status == QUEST_STATUS_COMPLETE)
            {
                if (int32(count) < -qInfo->GetRewOrReqMoney())
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
                if (qInfo->GetRepObjectiveFaction() == factionEntry->ID)
                {
                    QuestStatusData& q_status = m_QuestStatus[questid];
                    if (q_status.Status == QUEST_STATUS_INCOMPLETE)
                    {
                        if (GetReputationMgr().GetReputation(factionEntry) >= qInfo->GetRepObjectiveValue())
                            if (CanCompleteQuest(questid))
                                CompleteQuest(questid);
                    }
                    else if (q_status.Status == QUEST_STATUS_COMPLETE)
                    {
                        if (GetReputationMgr().GetReputation(factionEntry) < qInfo->GetRepObjectiveValue())
                            IncompleteQuest(questid);
                    }
                }
            }
        }
    }
}

void Player::ReputationChanged2(FactionEntry const* factionEntry)
{
    for (uint8 i = 0; i < MAX_QUEST_LOG_SIZE; ++i)
    {
        if (uint32 questid = GetQuestSlotQuestId(i))
        {
            if (Quest const* qInfo = sObjectMgr->GetQuestTemplate(questid))
            {
                if (qInfo->GetRepObjectiveFaction2() == factionEntry->ID)
                {
                    QuestStatusData& q_status = m_QuestStatus[questid];
                    if (q_status.Status == QUEST_STATUS_INCOMPLETE)
                    {
                        if (GetReputationMgr().GetReputation(factionEntry) >= qInfo->GetRepObjectiveValue2())
                            if (CanCompleteQuest(questid))
                                CompleteQuest(questid);
                    }
                    else if (q_status.Status == QUEST_STATUS_COMPLETE)
                    {
                        if (GetReputationMgr().GetReputation(factionEntry) < qInfo->GetRepObjectiveValue2())
                            IncompleteQuest(questid);
                    }
                }
            }
        }
    }
}

bool Player::HasQuestForItem(uint32 itemid, uint32 excludeQuestId /* 0 */, bool turnIn /* false */) const
{
    for (uint8 i = 0; i < MAX_QUEST_LOG_SIZE; ++i)
    {
        uint32 questid = GetQuestSlotQuestId(i);
        if (questid == 0 || questid == excludeQuestId)
            continue;

        QuestStatusMap::const_iterator qs_itr = m_QuestStatus.find(questid);
        if (qs_itr == m_QuestStatus.end())
            continue;

        QuestStatusData const& q_status = qs_itr->second;

        if ((q_status.Status == QUEST_STATUS_INCOMPLETE) || (turnIn && q_status.Status == QUEST_STATUS_COMPLETE))
        {
            Quest const* qinfo = sObjectMgr->GetQuestTemplate(questid);
            if (!qinfo)
                continue;

            // hide quest if player is in raid-group and quest is no raid quest
            if (GetGroup() && GetGroup()->isRaidGroup() && !qinfo->IsAllowedInRaid(GetMap()->GetDifficulty()))
                if (!InBattleground()) //there are two ways.. we can make every bg-quest a raidquest, or add this code here.. i don't know if this can be exploited by other quests, but i think all other quests depend on a specific area.. but keep this in mind, if something strange happens later
                    continue;

            // There should be no mixed ReqItem/ReqSource drop
            // This part for ReqItem drop
            for (uint8 j = 0; j < QUEST_ITEM_OBJECTIVES_COUNT; ++j)
            {
                if ((itemid == qinfo->RequiredItemId[j] && q_status.ItemCount[j] < qinfo->RequiredItemCount[j]) || (turnIn && q_status.ItemCount[j] >= qinfo->RequiredItemCount[j]))
                    return true;
            }
            // This part - for ReqSource
            for (uint8 j = 0; j < QUEST_SOURCE_ITEM_IDS_COUNT; ++j)
            {
                // examined item is a source item
                if (qinfo->ItemDrop[j] == itemid)
                {
                    ItemTemplate const* pProto = ASSERT_NOTNULL(sObjectMgr->GetItemTemplate(itemid));
                    uint32 ownedCount = GetItemCount(itemid, true);
                    // 'unique' item
                    if ((pProto->MaxCount && int32(ownedCount) < pProto->MaxCount) || (turnIn && int32(ownedCount) >= pProto->MaxCount))
                        return true;

                    // allows custom amount drop when not 0
                    if (qinfo->ItemDropQuantity[j])
                    {
                        if (ownedCount < qinfo->ItemDropQuantity[j] || turnIn )
                            return true;
                    } else if (ownedCount < pProto->GetMaxStackSize())
                        return true;
                }
            }
        }
    }
    return false;
}

void Player::SendQuestComplete(uint32 quest_id) const
{
    if (quest_id)
    {
        WorldPacket data(SMSG_QUESTUPDATE_COMPLETE, 4);
        data << uint32(quest_id);
        SendDirectMessage(&data);
    }
}

void Player::SendQuestReward(Quest const* quest, uint32 XP) const
{
    uint32 questid = quest->GetQuestId();
    sGameEventMgr->HandleQuestComplete(questid);
    WorldPacket data(SMSG_QUESTGIVER_QUEST_COMPLETE, (4+4+4+4+4));
    data << uint32(questid);

    if (GetLevel() < sWorld->getIntConfig(CONFIG_MAX_PLAYER_LEVEL))
        data << uint32(XP);
    else
        data << uint32(0);

    data << uint32(quest->GetRewOrReqMoney(this));
    data << uint32(10 * quest->CalculateHonorGain(GetQuestLevel(quest)));
    data << uint32(quest->GetBonusTalents());              // bonus talents
    data << uint32(quest->GetRewArenaPoints());
    SendDirectMessage(&data);
}

void Player::SendQuestFailed(uint32 questId, InventoryResult reason) const
{
    if (questId)
    {
        WorldPacket data(SMSG_QUESTGIVER_QUEST_FAILED, 4 + 4);
        data << uint32(questId);
        data << uint32(reason);                             // failed reason (valid reasons: 4, 16, 50, 17, 74, other values show default message)
        SendDirectMessage(&data);
    }
}

void Player::SendQuestTimerFailed(uint32 quest_id) const
{
    if (quest_id)
    {
        WorldPacket data(SMSG_QUESTUPDATE_FAILEDTIMER, 4);
        data << uint32(quest_id);
        SendDirectMessage(&data);
        TC_LOG_DEBUG("network", "WORLD: Sent SMSG_QUESTUPDATE_FAILEDTIMER");
    }
}

void Player::SendCanTakeQuestResponse(QuestFailedReason msg) const
{
    WorldPacket data(SMSG_QUESTGIVER_QUEST_INVALID, 4);
    data << uint32(msg);
    SendDirectMessage(&data);
    TC_LOG_DEBUG("network", "WORLD: Sent SMSG_QUESTGIVER_QUEST_INVALID");
}

void Player::SendQuestConfirmAccept(Quest const* quest, Player* pReceiver) const
{
    if (pReceiver)
    {
        std::string strTitle = quest->GetTitle();

        LocaleConstant localeConstant = pReceiver->GetSession()->GetSessionDbLocaleIndex();
        if (localeConstant != LOCALE_enUS)
            if (QuestLocale const* pLocale = sObjectMgr->GetQuestLocale(quest->GetQuestId()))
                ObjectMgr::GetLocaleString(pLocale->Title, localeConstant, strTitle);

        WorldPacket data(SMSG_QUEST_CONFIRM_ACCEPT, (4 + strTitle.size() + 8));
        data << uint32(quest->GetQuestId());
        data << strTitle;
        data << uint64(GetGUID());
        pReceiver->SendDirectMessage(&data);

        TC_LOG_DEBUG("network", "WORLD: Sent SMSG_QUEST_CONFIRM_ACCEPT");
    }
}

void Player::SendPushToPartyResponse(Player const* player, uint8 msg) const
{
    if (player)
    {
        WorldPacket data(MSG_QUEST_PUSH_RESULT, 8 + 1);
        data << uint64(player->GetGUID());
        data << uint8(msg);                                 // valid values: 0-8
        SendDirectMessage(&data);
        TC_LOG_DEBUG("network", "WORLD: Sent MSG_QUEST_PUSH_RESULT");
    }
}

void Player::SendQuestUpdateAddItem(Quest const* /*quest*/, uint32 /*item_idx*/, uint16 /*count*/) const
{
    WorldPacket data(SMSG_QUESTUPDATE_ADD_ITEM, 0);
    TC_LOG_DEBUG("network", "WORLD: Sent SMSG_QUESTUPDATE_ADD_ITEM");
    //data << quest->RequiredItemId[item_idx];
    //data << count;
    SendDirectMessage(&data);
}

void Player::SendQuestUpdateAddCreatureOrGo(Quest const* quest, ObjectGuid guid, uint32 creatureOrGO_idx, uint16 old_count, uint16 add_count)
{
    ASSERT(old_count + add_count < 65536 && "mob/GO count store in 16 bits 2^16 = 65536 (0..65536)");

    int32 entry = quest->RequiredNpcOrGo[creatureOrGO_idx];
    if (entry < 0)
        // client expected gameobject template id in form (id|0x80000000)
        entry = (-entry) | 0x80000000;

    WorldPacket data(SMSG_QUESTUPDATE_ADD_KILL, (4*4+8));
    TC_LOG_DEBUG("network", "WORLD: Sent SMSG_QUESTUPDATE_ADD_KILL");
    data << uint32(quest->GetQuestId());
    data << uint32(entry);
    data << uint32(old_count + add_count);
    data << uint32(quest->RequiredNpcOrGoCount[ creatureOrGO_idx ]);
    data << uint64(guid);
    SendDirectMessage(&data);

    uint16 log_slot = FindQuestSlot(quest->GetQuestId());
    if (log_slot < MAX_QUEST_LOG_SIZE)
        SetQuestSlotCounter(log_slot, creatureOrGO_idx, GetQuestSlotCounter(log_slot, creatureOrGO_idx) + add_count);

    sScriptMgr->OnQuestObjectiveProgress(this, quest, creatureOrGO_idx, old_count + add_count);
}

void Player::SendQuestUpdateAddPlayer(Quest const* quest, uint16 old_count, uint16 add_count)
{
    ASSERT(old_count + add_count < 65536 && "player count store in 16 bits");

    WorldPacket data(SMSG_QUESTUPDATE_ADD_PVP_KILL, (3*4));
    data << uint32(quest->GetQuestId());
    data << uint32(old_count + add_count);
    data << uint32(quest->GetPlayersSlain());
    SendDirectMessage(&data);

    uint16 log_slot = FindQuestSlot(quest->GetQuestId());
    if (log_slot < MAX_QUEST_LOG_SIZE)
        SetQuestSlotCounter(log_slot, QUEST_PVP_KILL_SLOT, GetQuestSlotCounter(log_slot, QUEST_PVP_KILL_SLOT) + add_count);
}

void Player::SendQuestGiverStatusMultiple()
{
    uint32 count = 0;

    WorldPacket data(SMSG_QUESTGIVER_STATUS_MULTIPLE, 4);
    data << uint32(count);                                  // placeholder

    for (auto itr = m_clientGUIDs.begin(); itr != m_clientGUIDs.end(); ++itr)
    {
        uint32 questStatus = DIALOG_STATUS_NONE;

        if (itr->IsAnyTypeCreature())
        {
            // need also pet quests case support
            Creature* questgiver = ObjectAccessor::GetCreatureOrPetOrVehicle(*this, *itr);
            if (!questgiver || questgiver->IsHostileTo(this))
                continue;
            if (!questgiver->HasFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER))
                continue;

            questStatus = GetQuestDialogStatus(questgiver);

            data << uint64(questgiver->GetGUID());
            data << uint8(questStatus);
            ++count;
        }
        else if (itr->IsGameObject())
        {
            GameObject* questgiver = GetMap()->GetGameObject(*itr);
            if (!questgiver || questgiver->GetGoType() != GAMEOBJECT_TYPE_QUESTGIVER)
                continue;

            questStatus = GetQuestDialogStatus(questgiver);

            data << uint64(questgiver->GetGUID());
            data << uint8(questStatus);
            ++count;
        }
    }

    data.put<uint32>(0, count);                             // write real count
    SendDirectMessage(&data);
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

void Player::Initialize(ObjectGuid::LowType guid)
{
    Object::_Create(guid, 0, HighGuid::Player);
}

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
            ASSERT(arenaSlot < 3);

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
            if (ObjectGuid::LowType guid = fields[5 + i].GetUInt32())
                eqSet.Data.Pieces[i] = ObjectGuid::Create<HighGuid::Item>(guid);

        if (eqSet.Data.SetID >= MAX_EQUIPMENT_SET_INDEX)    // client limit
            continue;

        _equipmentSets[eqSet.Data.Guid] = eqSet;
    } while (result->NextRow());
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
    stmt->setUInt32(0, guid.GetCounter());
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
    stmt->setUInt32(5, GetGUID().GetCounter());
    CharacterDatabase.Execute(stmt);
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
    //                                                       0     1        2     3     4      5       6      7   8      9     10    11         12         13           14         15         16
    //QueryResult* result = CharacterDatabase.PQuery("SELECT guid, account, name, race, class, gender, level, xp, money, skin, face, hairStyle, hairColor, facialStyle, bankSlots, restState, playerFlags, "
    // 17          18          19          20   21           22        23         24         25         26          27           28                 29
    //"position_x, position_y, position_z, map, orientation, taximask, cinematic, totaltime, leveltime, rest_bonus, logout_time, is_logout_resting, resettalents_cost, "
    // 30                 31       32       33       34       35         36           37            38        39    40      41                 42         43
    //"resettalents_time, trans_x, trans_y, trans_z, trans_o, transguid, extra_flags, stable_slots, at_login, zone, online, death_expire_time, taxi_path, instance_mode_mask, "
    // 44           45                46                47                    48          49          50              51           52               53              54
    //"arenaPoints, totalHonorPoints, todayHonorPoints, yesterdayHonorPoints, totalKills, todayKills, yesterdayKills, chosenTitle, knownCurrencies, watchedFaction, drunk, "
    // 55      56      57      58      59      60      61      62      63           64                 65                 66             67              68      69           70          71               72
    //"health, power1, power2, power3, power4, power5, power6, power7, instance_id, talentGroupsCount, activeTalentGroup, exploredZones, equipmentCache, ammoId, knownTitles, actionBars, grantableLevels, fishing_steps FROM characters WHERE guid = '%u'", guid);
    PreparedQueryResult result = holder->GetPreparedResult(PLAYER_LOGIN_QUERY_LOAD_FROM);
    if (!result)
    {
        std::string name = "<unknown>";
        sCharacterCache->GetCharacterNameByGuid(guid, name);
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

    Object::_Create(guid.GetCounter(), 0, HighGuid::Player);

    m_name = fields[2].GetString();

    // check name limitations
    if (ObjectMgr::CheckPlayerName(m_name, GetSession()->GetSessionDbcLocale()) != CHAR_NAME_SUCCESS ||
        (!GetSession()->HasPermission(rbac::RBAC_PERM_SKIP_CHECK_CHARACTER_CREATION_RESERVEDNAME) && sObjectMgr->IsReservedName(m_name)))
    {
        PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_ADD_AT_LOGIN_FLAG);
        stmt->setUInt16(0, uint16(AT_LOGIN_RENAME));
        stmt->setUInt32(1, guid.GetCounter());
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

    SetRace(fields[3].GetUInt8());
    SetClass(fields[4].GetUInt8());
    SetGender(gender);

    // check if race/class combination is valid
    PlayerInfo const* info = sObjectMgr->GetPlayerInfo(GetRace(), GetClass());
    if (!info)
    {
        TC_LOG_ERROR("entities.player", "Player::LoadFromDB: Player (%s) has wrong race/class (%u/%u), can't load.", guid.ToString().c_str(), GetRace(), GetClass());
        return false;
    }

    SetLevel(fields[6].GetUInt8(), false);
    SetXP(fields[7].GetUInt32());

    _LoadIntoDataField(fields[66].GetString(), PLAYER_EXPLORED_ZONES_1, PLAYER_EXPLORED_ZONES_SIZE);
    _LoadIntoDataField(fields[69].GetString(), PLAYER__FIELD_KNOWN_TITLES, KNOWN_TITLES_SIZE * 2);

    SetObjectScale(1.0f);
    SetFloatValue(UNIT_FIELD_HOVERHEIGHT, 1.0f);

    // load achievements before anything else to prevent multiple gains for the same achievement/criteria on every loading (as loading does call UpdateAchievementCriteria)
    m_achievementMgr->LoadFromDB(holder->GetPreparedResult(PLAYER_LOGIN_QUERY_LOAD_ACHIEVEMENTS), holder->GetPreparedResult(PLAYER_LOGIN_QUERY_LOAD_CRITERIA_PROGRESS));

    uint32 money = fields[8].GetUInt32();
    if (money > MAX_MONEY_AMOUNT)
        money = MAX_MONEY_AMOUNT;
    SetMoney(money);

    SetSkinId(fields[9].GetUInt8());
    SetFaceId(fields[10].GetUInt8());
    SetHairStyleId(fields[11].GetUInt8());
    SetHairColorId(fields[12].GetUInt8());
    SetFacialStyle(fields[13].GetUInt8());
    SetBankBagSlotCount(fields[14].GetUInt8());
    SetRestState(fields[15].GetUInt8());
    SetNativeGender(fields[5].GetUInt8());
    SetByteValue(PLAYER_BYTES_3, PLAYER_BYTES_3_OFFSET_INEBRIATION, fields[54].GetUInt8());

    if (!ValidateAppearance(
        fields[3].GetUInt8(), // race
        fields[4].GetUInt8(), // class
        gender, GetHairStyleId(), GetHairColorId(), GetFaceId(), GetFacialStyle(), GetSkinId()))
    {
        TC_LOG_ERROR("entities.player", "Player::LoadFromDB: Player (%s) has wrong Appearance values (Hair/Skin/Color), can't load.", guid.ToString().c_str());
        return false;
    }

    SetUInt32Value(PLAYER_FLAGS, fields[16].GetUInt32());
    SetInt32Value(PLAYER_FIELD_WATCHED_FACTION_INDEX, fields[53].GetUInt32());

    SetUInt64Value(PLAYER_FIELD_KNOWN_CURRENCIES, fields[52].GetUInt64());

    SetUInt32Value(PLAYER_AMMO_ID, fields[68].GetUInt32());

    // set which actionbars the client has active - DO NOT REMOVE EVER AGAIN (can be changed though, if it does change fieldwise)
    SetByteValue(PLAYER_FIELD_BYTES, PLAYER_FIELD_BYTES_OFFSET_ACTION_BAR_TOGGLES, fields[70].GetUInt8());

    m_fishingSteps = fields[72].GetUInt8();

    InitDisplayIds();

    // cleanup inventory related item value fields (it will be filled correctly in _LoadInventory)
    for (uint8 slot = EQUIPMENT_SLOT_START; slot < EQUIPMENT_SLOT_END; ++slot)
    {
        SetGuidValue(PLAYER_FIELD_INV_SLOT_HEAD + (slot * 2), ObjectGuid::Empty);
        SetVisibleItemSlot(slot, nullptr);

        delete m_items[slot];
        m_items[slot] = nullptr;
    }

    TC_LOG_DEBUG("entities.player.loading", "Player::LoadFromDB: Load Basic value of player '%s' is: ", m_name.c_str());
    outDebugValues();

    //Need to call it to initialize m_team (m_team can be calculated from race)
    //Other way is to saves m_team into characters table.
    SetFactionForRace(GetRace());

    // load home bind and check in same time class/race pair, it used later for restore broken positions
    if (!_LoadHomeBind(holder->GetPreparedResult(PLAYER_LOGIN_QUERY_LOAD_HOME_BIND)))
        return false;

    InitPrimaryProfessions();                               // to max set before any spell loaded

    // init saved position, and fix it later if problematic
    ObjectGuid::LowType transLowGUID = fields[35].GetUInt32();
    Relocate(fields[17].GetFloat(), fields[18].GetFloat(), fields[19].GetFloat(), fields[21].GetFloat());
    uint32 mapId = fields[20].GetUInt16();
    uint32 instanceId = fields[63].GetUInt32();

    uint32 dungeonDiff = fields[43].GetUInt8() & 0x0F;
    if (dungeonDiff >= MAX_DUNGEON_DIFFICULTY)
        dungeonDiff = DUNGEON_DIFFICULTY_NORMAL;
    uint32 raidDiff = (fields[43].GetUInt8() >> 4) & 0x0F;
    if (raidDiff >= MAX_RAID_DIFFICULTY)
        raidDiff = RAID_DIFFICULTY_10MAN_NORMAL;
    SetDungeonDifficulty(Difficulty(dungeonDiff));          // may be changed in _LoadGroup
    SetRaidDifficulty(Difficulty(raidDiff));                // may be changed in _LoadGroup

    std::string taxi_nodes = fields[42].GetString();

#define RelocateToHomebind(){ mapId = m_homebindMapId; instanceId = 0; Relocate(m_homebindX, m_homebindY, m_homebindZ); }

    _LoadGroup(holder->GetPreparedResult(PLAYER_LOGIN_QUERY_LOAD_GROUP));

    _LoadArenaTeamInfo(holder->GetPreparedResult(PLAYER_LOGIN_QUERY_LOAD_ARENA_INFO));

    SetArenaPoints(fields[44].GetUInt32());

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

    SetHonorPoints(fields[45].GetUInt32());
    SetUInt32Value(PLAYER_FIELD_TODAY_CONTRIBUTION, fields[46].GetUInt32());
    SetUInt32Value(PLAYER_FIELD_YESTERDAY_CONTRIBUTION, fields[47].GetUInt32());
    SetUInt32Value(PLAYER_FIELD_LIFETIME_HONORABLE_KILLS, fields[48].GetUInt32());
    SetUInt16Value(PLAYER_FIELD_KILLS, 0, fields[49].GetUInt16());
    SetUInt16Value(PLAYER_FIELD_KILLS, 1, fields[50].GetUInt16());

    _LoadBoundInstances(holder->GetPreparedResult(PLAYER_LOGIN_QUERY_LOAD_BOUND_INSTANCES));
    _LoadInstanceTimeRestrictions(holder->GetPreparedResult(PLAYER_LOGIN_QUERY_LOAD_INSTANCE_LOCK_TIMES));
    _LoadBGData(holder->GetPreparedResult(PLAYER_LOGIN_QUERY_LOAD_BG_DATA));

    GetSession()->SetPlayer(this);
    MapEntry const* mapEntry = sMapStore.LookupEntry(mapId);
    Map* map = nullptr;
    bool player_at_bg = false;
    if (!mapEntry || !IsPositionValid())
    {
        TC_LOG_ERROR("entities.player", "Player::LoadFromDB: Player (%s) has invalid coordinates (MapId: %u X: %f Y: %f Z: %f O: %f). Teleport to default race/class locations.",
            guid.ToString().c_str(), mapId, GetPositionX(), GetPositionY(), GetPositionZ(), GetOrientation());
        RelocateToHomebind();
    }
    // Player was saved in Arena or Bg
    else if (mapEntry->IsBattlegroundOrArena())
    {
        Battleground* currentBg = nullptr;
        if (m_bgData.bgInstanceID)                                                //saved in Battleground
            currentBg = sBattlegroundMgr->GetBattleground(m_bgData.bgInstanceID, BATTLEGROUND_TYPE_NONE);

        player_at_bg = currentBg && currentBg->IsPlayerInBattleground(GetGUID());

        if (player_at_bg && currentBg->GetStatus() != STATUS_WAIT_LEAVE)
        {
            map = currentBg->GetBgMap();

            BattlegroundQueueTypeId bgQueueTypeId = sBattlegroundMgr->BGQueueTypeId(currentBg->GetTypeID(), currentBg->GetArenaType());
            AddBattlegroundQueueId(bgQueueTypeId);

            m_bgData.bgTypeID = currentBg->GetTypeID();

            //join player to battleground group
            currentBg->EventPlayerLoggedIn(this);

            SetInviteForBattlegroundQueueType(bgQueueTypeId, currentBg->GetInstanceID());
        }
        // Bg was not found - go to Entry Point
        else
        {
            // leave bg
            if (player_at_bg)
            {
                player_at_bg = false;
                currentBg->RemovePlayerAtLeave(GetGUID(), false, true);
            }

            // Do not look for instance if bg not found
            WorldLocation const& _loc = GetBattlegroundEntryPoint();
            mapId = _loc.GetMapId();
            instanceId = 0;

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
        ObjectGuid transGUID(HighGuid::Mo_Transport, transLowGUID);

        Transport* transport = nullptr;
        if (Transport* go = HashMapHolder<Transport>::Find(transGUID))
            transport = go;

        if (transport)
        {
            float x = fields[31].GetFloat(), y = fields[32].GetFloat(), z = fields[33].GetFloat(), o = fields[34].GetFloat();
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
            TC_LOG_ERROR("entities.player", "Player::LoadFromDB: Player (%s) has problems with transport guid (%u). Teleport to bind location.",
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

            if (!nodeEntry)                                      // don't know taxi start node, teleport to homebind
            {
                TC_LOG_ERROR("entities.player", "Player::LoadFromDB: Player (%s) has wrong data in taxi destination list, teleport to homebind.", GetGUID().ToString().c_str());
                RelocateToHomebind();
            }
            else                                                // has start node, teleport to it
            {
                TC_LOG_ERROR("entities.player", "Player::LoadFromDB: Player (%s) has too short taxi destination list, teleport to original node.", GetGUID().ToString().c_str());
                mapId = nodeEntry->map_id;
                Relocate(nodeEntry->x, nodeEntry->y, nodeEntry->z, 0.0f);
            }
            m_taxi.ClearTaxiDestinations();
        }

        if (uint32 node_id = m_taxi.GetTaxiSource())
        {
            // save source node as recall coord to prevent recall and fall from sky
            TaxiNodesEntry const* nodeEntry = sTaxiNodesStore.LookupEntry(node_id);
            if (nodeEntry && nodeEntry->map_id == GetMapId())
            {
                ASSERT(nodeEntry);                                  // checked in m_taxi.LoadTaxiDestinationsFromString
                mapId = nodeEntry->map_id;
                Relocate(nodeEntry->x, nodeEntry->y, nodeEntry->z, 0.0f);
            }

            // flight will started later
        }
    }

    // Map could be changed before
    mapEntry = sMapStore.LookupEntry(mapId);
    // client without expansion support
    if (mapEntry)
    {
        if (GetSession()->Expansion() < mapEntry->Expansion())
        {
            TC_LOG_DEBUG("entities.player.loading", "Player::LoadFromDB: Player '%s' (%s) using client without required expansion tried login at non accessible map %u",
                GetName().c_str(), GetGUID().ToString().c_str(), mapId);
            RelocateToHomebind();
        }

        // fix crash (because of if (Map* map = _FindMap(instanceId)) in MapInstanced::CreateInstance)
        if (instanceId)
            if (InstanceSave* save = GetInstanceSave(mapId, mapEntry->IsRaid()))
                if (save->GetInstanceId() != instanceId)
                    instanceId = 0;
    }

    // NOW player must have valid map
    // load the player's map here if it's not already loaded
    if (!map)
        map = sMapMgr->CreateMap(mapId, this, instanceId);
    AreaTrigger const* areaTrigger = nullptr;
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
                    SendTransferAborted(map->GetId(), TRANSFER_ABORT_DIFFICULTY, map->GetDifficulty());
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
    StoreRaidMapDifficulty();
    UpdatePositionData();

    // now that map position is determined, check instance validity
    if (!CheckInstanceValidity(true) && !IsInstanceLoginGameMasterException())
        m_InstanceValid = false;

    if (player_at_bg)
        map->ToBattlegroundMap()->GetBG()->AddPlayer(this);

    // randomize first save time in range [CONFIG_INTERVAL_SAVE] around [CONFIG_INTERVAL_SAVE]
    // this must help in case next save after mass player load after server startup
    m_nextSave = urand(m_nextSave / 2, m_nextSave * 3 / 2);

    SaveRecallPosition();

    time_t now = GameTime::GetGameTime();
    time_t logoutTime = time_t(fields[27].GetUInt32());

    // since last logout (in seconds)
    uint32 time_diff = uint32(now - logoutTime); //uint64 is excessive for a time_diff in seconds.. uint32 allows for 136~ year difference.

    // set value, including drunk invisibility detection
    // calculate sobering. after 15 minutes logged out, the player will be sober again
    if (time_diff < uint32(GetDrunkValue()) * 9)
        SetDrunkValue(GetDrunkValue() - time_diff / 9);
    else
        SetDrunkValue(0);

    m_cinematic = fields[23].GetUInt8();
    m_Played_time[PLAYED_TIME_TOTAL] = fields[24].GetUInt32();
    m_Played_time[PLAYED_TIME_LEVEL] = fields[25].GetUInt32();

    m_resetTalentsCost = fields[29].GetUInt32();
    m_resetTalentsTime = time_t(fields[30].GetUInt32());

    m_taxi.LoadTaxiMask(fields[22].GetString());                // must be before InitTaxiNodesForLevel

    uint32 extraflags = fields[36].GetUInt16();

    m_stableSlots = fields[37].GetUInt8();
    if (m_stableSlots > MAX_PET_STABLES)
    {
        TC_LOG_ERROR("entities.player", "Player::LoadFromDB: Player (%s) can't have more stable slots than %u, but has %u in DB",
            GetGUID().ToString().c_str(), MAX_PET_STABLES, uint32(m_stableSlots));
        m_stableSlots = MAX_PET_STABLES;
    }

    m_atLoginFlags = fields[38].GetUInt16();

    if (HasAtLoginFlag(AT_LOGIN_RENAME))
    {
        TC_LOG_ERROR("entities.player.cheat", "Player::LoadFromDB: Player (%s) tried to login while forced to rename, can't load.'", GetGUID().ToString().c_str());
        return false;
    }

    // Honor system
    // Update Honor kills data
    m_lastHonorUpdateTime = logoutTime;
    UpdateHonorFields();

    m_deathExpireTime = time_t(fields[41].GetUInt32());

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

    // apply original stats mods before spell loading or item equipment that call before equip _RemoveStatsMods()

    //mails are loaded only when needed ;-) - when player in game click on mailbox.
    //_LoadMail();

    m_specsCount = fields[64].GetUInt8();
    m_activeSpec = fields[65].GetUInt8();

    // sanity check
    if (m_specsCount > MAX_TALENT_SPECS || m_activeSpec > MAX_TALENT_SPEC || m_specsCount < MIN_TALENT_SPECS)
    {
        TC_LOG_ERROR("entities.player", "Player::LoadFromDB: Player %s (%s) has invalid SpecCount = %u and/or invalid ActiveSpec = %u.",
            GetName().c_str(), GetGUID().ToString().c_str(), uint32(m_specsCount), uint32(m_activeSpec));
        m_activeSpec = 0;
    }

    UpdateDisplayPower();
    _LoadTalents(holder->GetPreparedResult(PLAYER_LOGIN_QUERY_LOAD_TALENTS));
    _LoadSpells(holder->GetPreparedResult(PLAYER_LOGIN_QUERY_LOAD_SPELLS));

    _LoadGlyphs(holder->GetPreparedResult(PLAYER_LOGIN_QUERY_LOAD_GLYPHS));
    _LoadAuras(holder->GetPreparedResult(PLAYER_LOGIN_QUERY_LOAD_AURAS), time_diff);
    _LoadGlyphAuras();
    // add ghost flag (must be after aura load: PLAYER_FLAGS_GHOST set in aura)
    if (HasFlag(PLAYER_FLAGS, PLAYER_FLAGS_GHOST))
        m_deathState = DEAD;

    // after spell load, learn rewarded spell if need also
    _LoadQuestStatus(holder->GetPreparedResult(PLAYER_LOGIN_QUERY_LOAD_QUEST_STATUS));
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

    // update items with duration and realtime
    UpdateItemDuration(time_diff, true);

    _LoadActions(holder->GetPreparedResult(PLAYER_LOGIN_QUERY_LOAD_ACTIONS));

    // unread mails and next delivery time, actual mails not loaded
    _LoadMailInit(holder->GetPreparedResult(PLAYER_LOGIN_QUERY_LOAD_MAIL_COUNT), holder->GetPreparedResult(PLAYER_LOGIN_QUERY_LOAD_MAIL_DATE));

    m_social = sSocialMgr->LoadFromDB(holder->GetPreparedResult(PLAYER_LOGIN_QUERY_LOAD_SOCIAL_LIST), GetGUID());

    // check PLAYER_CHOSEN_TITLE compatibility with PLAYER__FIELD_KNOWN_TITLES
    // note: PLAYER__FIELD_KNOWN_TITLES updated at quest status loaded
    uint32 curTitle = fields[51].GetUInt32();
    if (curTitle && !HasTitle(curTitle))
        curTitle = 0;

    SetUInt32Value(PLAYER_CHOSEN_TITLE, curTitle);

    // has to be called after last Relocate() in Player::LoadFromDB
    SetFallInformation(0, GetPositionZ());

    GetSpellHistory()->LoadFromDB<Player>(holder->GetPreparedResult(PLAYER_LOGIN_QUERY_LOAD_SPELL_COOLDOWNS));

    uint32 savedHealth = fields[55].GetUInt32();
    if (!savedHealth)
        m_deathState = CORPSE;

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
    SetHealth(savedHealth);
    for (uint8 i = 0; i < MAX_POWERS; ++i)
    {
        uint32 savedPower = fields[56 + i].GetUInt32();
        SetPower(static_cast<Powers>(i), savedPower);
    }

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

    InitPvP();

    // RaF stuff.
    m_grantableLevels = fields[71].GetUInt8();
    if (GetSession()->IsARecruiter() || (GetSession()->GetRecruiterId() != 0))
        SetFlag(UNIT_DYNAMIC_FLAGS, UNIT_DYNFLAG_REFER_A_FRIEND);

    if (m_grantableLevels > 0)
        SetByteValue(PLAYER_FIELD_BYTES, PLAYER_FIELD_BYTES_OFFSET_RAF_GRANTABLE_LEVEL, 0x01);

    _LoadDeclinedNames(holder->GetPreparedResult(PLAYER_LOGIN_QUERY_LOAD_DECLINED_NAMES));

    m_achievementMgr->CheckAllAchievementCriteria();

    _LoadEquipmentSets(holder->GetPreparedResult(PLAYER_LOGIN_QUERY_LOAD_EQUIPMENT_SETS));

    return true;
}

bool Player::isAllowedToLoot(Creature const* creature)
{
    if (!creature->isDead() || !creature->IsDamageEnoughForLootingAndReward())
        return false;

    if (HasPendingBind())
        return false;

    Loot const* loot = &creature->loot;
    if (loot->isLooted()) // nothing to loot or everything looted.
        return false;
    if (!loot->hasItemForAll() && !loot->hasItemFor(this)) // no loot in creature for this player
        return false;

    if (loot->loot_type == LOOT_SKINNING)
        return creature->GetLootRecipientGUID() == GetGUID();

    Group* thisGroup = GetGroup();
    if (!thisGroup)
        return this == creature->GetLootRecipient();
    else if (thisGroup != creature->GetLootRecipientGroup())
        return false;

    switch (thisGroup->GetLootMethod())
    {
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

            if (ActionButton* ab = addActionButton(button, action, type))
                ab->uState = ACTIONBUTTON_UNCHANGED;
            else
            {
                TC_LOG_DEBUG("entities.player", "Player::_LoadActions: Player '%s' (%s) has an invalid action button (Button: %u, Action: %u, Type: %u). It will be deleted at next save. This can be due to a player changing their talents.",
                    GetName().c_str(), GetGUID().ToString().c_str(), button, action, type);

                // Will be deleted in DB at next save (it can create data until save but marked as deleted).
                m_actionButtons[button].uState = ACTIONBUTTON_DELETED;
            }
        } while (result->NextRow());
    }
}

void Player::_LoadAuras(PreparedQueryResult result, uint32 timediff)
{
    TC_LOG_DEBUG("entities.player.loading", "Player::_LoadAuras: Loading auras for %s", GetGUID().ToString().c_str());

    /*                                                     0           1         2      3           4                5           6        7        8        9             10            11
    QueryResult* result = CharacterDatabase.PQuery("SELECT casterGuid, itemGuid, spell, effectMask, recalculateMask, stackCount, amount0, amount1, amount2, base_amount0, base_amount1, base_amount2,
                                                    12           13          14             15          16
                                                    maxDuration, remainTime, remainCharges, critChance, applyResilience FROM character_aura WHERE guid = '%u'", GetGUID().GetCounter());
    */

    if (result)
    {
        do
        {
            Field* fields = result->Fetch();
            int32 damage[3];
            int32 baseDamage[3];
            ObjectGuid caster_guid(fields[0].GetUInt64());
            ObjectGuid itemGuid(fields[1].GetUInt64());
            uint32 spellid = fields[2].GetUInt32();
            uint8 effmask = fields[3].GetUInt8();
            uint8 recalculatemask = fields[4].GetUInt8();
            uint8 stackcount = fields[5].GetUInt8();
            damage[0] = fields[6].GetInt32();
            damage[1] = fields[7].GetInt32();
            damage[2] = fields[8].GetInt32();
            baseDamage[0] = fields[9].GetInt32();
            baseDamage[1] = fields[10].GetInt32();
            baseDamage[2] = fields[11].GetInt32();
            int32 maxduration = fields[12].GetInt32();
            int32 remaintime = fields[13].GetInt32();
            uint8 remaincharges = fields[14].GetUInt8();
            float critChance = fields[15].GetFloat();
            bool applyResilience = fields[16].GetBool();

            SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(spellid);
            if (!spellInfo)
            {
                TC_LOG_ERROR("entities.player", "Player::_LoadAuras: Player '%s' (%s) has an invalid aura (SpellID: %u), ignoring.",
                    GetName().c_str(), GetGUID().ToString().c_str(), spellid);
                continue;
            }

            // negative effects should continue counting down after logout
            if (remaintime != -1 && ((!spellInfo->IsPositive() && spellInfo->Id != 15007) || spellInfo->HasAttribute(SPELL_ATTR4_FADES_WHILE_LOGGED_OUT))) // Resurrection sickness should not fade while logged out
            {
                if (remaintime/IN_MILLISECONDS <= int32(timediff))
                    continue;

                remaintime -= timediff*IN_MILLISECONDS;
            }

            // prevent wrong values of remaincharges
            if (spellInfo->ProcCharges)
            {
                // we have no control over the order of applying auras and modifiers allow auras
                // to have more charges than value in SpellInfo
                if (remaincharges <= 0/* || remaincharges > spellproto->procCharges*/)
                    remaincharges = spellInfo->ProcCharges;
            }
            else
                remaincharges = 0;

            AuraCreateInfo createInfo(spellInfo, effmask, this);
            createInfo
                .SetCasterGUID(caster_guid)
                .SetCastItemGUID(itemGuid)
                .SetBaseAmount(baseDamage);

            if (Aura* aura = Aura::TryCreate(createInfo))
            {
                if (!aura->CanBeSaved())
                {
                    aura->Remove();
                    continue;
                }

                aura->SetLoadedState(maxduration, remaintime, remaincharges, stackcount, recalculatemask, critChance, applyResilience, &damage[0]);
                aura->ApplyForTargets();
                TC_LOG_DEBUG("entities.player", "Player::_LoadAuras: Added aura (SpellID: %u, EffectMask: %u) to player '%s (%s)",
                    spellInfo->Id, effmask, GetName().c_str(), GetGUID().ToString().c_str());
            }
        }
        while (result->NextRow());
    }
}

void Player::_LoadGlyphAuras()
{
    for (uint8 i = 0; i < MAX_GLYPH_SLOT_INDEX; ++i)
    {
        if (uint32 glyph = GetGlyph(i))
        {
            if (GlyphPropertiesEntry const* gp = sGlyphPropertiesStore.LookupEntry(glyph))
            {
                if (GlyphSlotEntry const* gs = sGlyphSlotStore.LookupEntry(GetGlyphSlot(i)))
                {
                    if (gp->TypeFlags == gs->TypeFlags)
                    {
                        CastSpell(this, gp->SpellId, true);
                        continue;
                    }
                    else
                        TC_LOG_ERROR("entities.player", "Player::_LoadGlyphAuras: Player '%s' (%s) has glyph with typeflags %u in slot with typeflags %u, removing.", GetName().c_str(), GetGUID().ToString().c_str(), gp->TypeFlags, gs->TypeFlags);
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
        if (HasAtLoginFlag(AT_LOGIN_RESURRECT))
            ResurrectPlayer(0.5f);
        else if (result)
        {
            Field* fields = result->Fetch();
            _corpseLocation.WorldRelocate(fields[0].GetUInt16(), fields[1].GetFloat(), fields[2].GetFloat(), fields[3].GetFloat(), fields[4].GetFloat());
            ApplyModByteFlag(PLAYER_FIELD_BYTES, PLAYER_FIELD_BYTES_OFFSET_FLAGS, PLAYER_FIELD_BYTE_RELEASE_TIMER, !sMapStore.LookupEntry(_corpseLocation.GetMapId())->Instanceable());
        }
    }

    RemoveAtLoginFlag(AT_LOGIN_RESURRECT);
}

void Player::_LoadInventory(PreparedQueryResult result, uint32 timeDiff)
{
    //QueryResult* result = CharacterDatabase.PQuery("SELECT data, text, bag, slot, item, item_template FROM character_inventory JOIN item_instance ON character_inventory.item = item_instance.guid WHERE character_inventory.guid = '%u' ORDER BY bag, slot", GetGUID().GetCounter());
    //NOTE: the "order by `bag`" is important because it makes sure
    //the bagMap is filled before items in the bags are loaded
    //NOTE2: the "order by `slot`" is needed because mainhand weapons are (wrongly?)
    //expected to be equipped before offhand items (@todo fixme)

    if (result)
    {
        uint32 zoneId = GetZoneId();

        std::map<ObjectGuid::LowType, Bag*> bagMap;                  // fast guid lookup for bags
        std::map<ObjectGuid::LowType, Item*> invalidBagMap;          // fast guid lookup for bags
        std::list<Item*> problematicItems;
        SQLTransaction trans = CharacterDatabase.BeginTransaction();

        // Prevent items from being added to the queue while loading
        m_itemUpdateQueueBlocked = true;
        do
        {
            Field* fields = result->Fetch();
            if (Item* item = _LoadItem(trans, zoneId, timeDiff, fields))
            {
                ObjectGuid::LowType bagGuid = fields[11].GetUInt32();
                uint8  slot     = fields[12].GetUInt8();

                InventoryResult err = EQUIP_ERR_OK;
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
                                bagMap[item->GetGUID().GetCounter()] = pBag;
                    }
                    else
                        if (IsBagPos(item->GetPos()))
                            if (item->IsBag())
                                invalidBagMap[item->GetGUID().GetCounter()] = item;
                }
                else
                {
                    item->SetSlot(NULL_SLOT);
                    // Item is in the bag, find the bag
                    std::map<ObjectGuid::LowType, Bag*>::iterator itr = bagMap.find(bagGuid);
                    if (itr != bagMap.end())
                    {
                        ItemPosCountVec dest;
                        err = CanStoreItem(itr->second->GetSlot(), slot, dest, item);
                        if (err == EQUIP_ERR_OK)
                            item = StoreItem(dest, item, true);
                    }
                    else if (invalidBagMap.find(bagGuid) != invalidBagMap.end())
                    {
                        std::map<ObjectGuid::LowType, Item*>::iterator invalidBagItr = invalidBagMap.find(bagGuid);
                        if (std::find(problematicItems.begin(), problematicItems.end(), invalidBagItr->second) != problematicItems.end())
                            err = EQUIP_ERR_INT_BAG_ERROR;
                    }
                    else
                    {
                        TC_LOG_ERROR("entities.player", "Player::_LoadInventory: Player '%s' (%s) has item (%s, entry: %u) which doesnt have a valid bag (Bag %u, slot: %u). Possible cheat?",
                            GetName().c_str(), GetGUID().ToString().c_str(), item->GetGUID().ToString().c_str(), item->GetEntry(), bagGuid, slot);
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
                    TC_LOG_ERROR("entities.player", "Player::_LoadInventory: Player '%s' (%s) has item (%s, entry: %u) which can't be loaded into inventory (Bag %u, slot: %u) by reason %u. Item will be sent by mail.",
                        GetName().c_str(), GetGUID().ToString().c_str(), item->GetGUID().ToString().c_str(), item->GetEntry(), bagGuid, slot, uint32(err));
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

Item* Player::_LoadItem(SQLTransaction& trans, uint32 zoneId, uint32 timeDiff, Field* fields)
{
    Item* item = nullptr;
    ObjectGuid::LowType itemGuid  = fields[13].GetUInt32();
    uint32 itemEntry = fields[14].GetUInt32();
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
                TC_LOG_DEBUG("entities.player.loading", "Player::_LoadInventory: player (GUID: %u, name: '%s', map: %u) has item (GUID: %u, entry: %u) limited to another map (%u). Deleting item.",
                    GetGUID().GetCounter(), GetName().c_str(), GetMapId(), item->GetGUID().GetCounter(), item->GetEntry(), zoneId);
                remove = true;
            }
            // "Conjured items disappear if you are logged out for more than 15 minutes"
            else if (timeDiff > 15 * MINUTE && proto->Flags & ITEM_FLAG_CONJURED)
            {
                TC_LOG_DEBUG("entities.player.loading", "Player::_LoadInventory: player (GUID: %u, name: '%s', diff: %u) has conjured item (GUID: %u, entry: %u) with expired lifetime (15 minutes). Deleting item.",
                    GetGUID().GetCounter(), GetName().c_str(), timeDiff, item->GetGUID().GetCounter(), item->GetEntry());
                remove = true;
            }
            else if (item->HasFlag(ITEM_FIELD_FLAGS, ITEM_FIELD_FLAG_REFUNDABLE))
            {
                if (item->GetPlayedTime() > (2 * HOUR))
                {
                    TC_LOG_DEBUG("entities.player.loading", "Player::_LoadInventory: player (GUID: %u, name: '%s') has item (GUID: %u, entry: %u) with expired refund time (%u). Deleting refund data and removing refundable flag.",
                        GetGUID().GetCounter(), GetName().c_str(), item->GetGUID().GetCounter(), item->GetEntry(), item->GetPlayedTime());

                    stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_ITEM_REFUND_INSTANCE);
                    stmt->setUInt32(0, item->GetGUID().GetCounter());
                    trans->Append(stmt);

                    item->RemoveFlag(ITEM_FIELD_FLAGS, ITEM_FIELD_FLAG_REFUNDABLE);
                }
                else
                {
                    stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_ITEM_REFUNDS);
                    stmt->setUInt32(0, item->GetGUID().GetCounter());
                    stmt->setUInt32(1, GetGUID().GetCounter());
                    if (PreparedQueryResult result = CharacterDatabase.Query(stmt))
                    {
                        item->SetRefundRecipient((*result)[0].GetUInt32());
                        item->SetPaidMoney((*result)[1].GetUInt32());
                        item->SetPaidExtendedCost((*result)[2].GetUInt16());
                        AddRefundReference(item->GetGUID());
                    }
                    else
                    {
                        TC_LOG_DEBUG("entities.player.loading", "Player::_LoadInventory: player (GUID: %u, name: '%s') has item (GUID: %u, entry: %u) with refundable flags, but without data in item_refund_instance. Removing flag.",
                            GetGUID().GetCounter(), GetName().c_str(), item->GetGUID().GetCounter(), item->GetEntry());
                        item->RemoveFlag(ITEM_FIELD_FLAGS, ITEM_FIELD_FLAG_REFUNDABLE);
                    }
                }
            }
            else if (item->HasFlag(ITEM_FIELD_FLAGS, ITEM_FIELD_FLAG_BOP_TRADEABLE))
            {
                stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_ITEM_BOP_TRADE);
                stmt->setUInt32(0, item->GetGUID().GetCounter());
                if (PreparedQueryResult result = CharacterDatabase.Query(stmt))
                {
                    std::string strGUID = (*result)[0].GetString();
                    Tokenizer GUIDlist(strGUID, ' ');
                    GuidSet looters;
                    for (Tokenizer::const_iterator itr = GUIDlist.begin(); itr != GUIDlist.end(); ++itr)
                        looters.insert(ObjectGuid::Create<HighGuid::Player>(uint32(strtoul(*itr, nullptr, 10))));

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
                    TC_LOG_DEBUG("entities.player.loading", "Player::_LoadInventory: player (GUID: %u, name: '%s') has item (GUID: %u, entry: %u) with ITEM_FLAG_BOP_TRADEABLE flag, but without data in item_soulbound_trade_data. Removing flag.",
                        GetGUID().GetCounter(), GetName().c_str(), item->GetGUID().GetCounter(), item->GetEntry());
                    item->RemoveFlag(ITEM_FIELD_FLAGS, ITEM_FIELD_FLAG_BOP_TRADEABLE);
                }
            }
            else if (proto->HolidayId)
            {
                remove = true;
                GameEventMgr::GameEventDataMap const& events = sGameEventMgr->GetEventMap();
                GameEventMgr::ActiveEvents const& activeEventsList = sGameEventMgr->GetActiveEventList();
                for (GameEventMgr::ActiveEvents::const_iterator itr = activeEventsList.begin(); itr != activeEventsList.end(); ++itr)
                {
                    if (uint32(events[*itr].holiday_id) == proto->HolidayId)
                    {
                        remove = false;
                        break;
                    }
                }
            }
        }
        else
        {
            TC_LOG_ERROR("entities.player", "Player::_LoadInventory: player (GUID: %u, name: '%s') has a broken item (GUID: %u, entry: %u) in inventory. Deleting item.",
                GetGUID().GetCounter(), GetName().c_str(), itemGuid, itemEntry);
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
        TC_LOG_ERROR("entities.player", "Player::_LoadInventory: player (GUID: %u, name: '%s') has an unknown item (entry: %u) in inventory. Deleting item.",
            GetGUID().GetCounter(), GetName().c_str(), itemEntry);
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

        ObjectGuid::LowType itemGuid = fields[11].GetUInt32();
        uint32 itemTemplate = fields[12].GetUInt32();

        mail->AddItem(itemGuid, itemTemplate);

        ItemTemplate const* proto = sObjectMgr->GetItemTemplate(itemTemplate);

        if (!proto)
        {
            TC_LOG_ERROR("entities.player", "Player '%s' (%s) has unknown item_template in mailed items (GUID: %u, Entry: %u) in mail (%u), deleted.",
                GetName().c_str(), GetGUID().ToString().c_str(), itemGuid, itemTemplate, mail->messageID);

            stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_INVALID_MAIL_ITEM);
            stmt->setUInt32(0, itemGuid);
            CharacterDatabase.Execute(stmt);

            stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_ITEM_INSTANCE);
            stmt->setUInt32(0, itemGuid);
            CharacterDatabase.Execute(stmt);
            continue;
        }

        Item* item = NewItemOrBag(proto);

        if (!item->LoadFromDB(itemGuid, ObjectGuid(HighGuid::Player, fields[13].GetUInt32()), fields, itemTemplate))
        {
            TC_LOG_ERROR("entities.player", "Player::_LoadMailedItems: Item (GUID: %u) in mail (%u) doesn't exist, deleted from mail.", itemGuid, mail->messageID);

            stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_MAIL_ITEM);
            stmt->setUInt32(0, itemGuid);
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
    stmt->setUInt32(0, GetGUID().GetCounter());
    PreparedQueryResult result = CharacterDatabase.Query(stmt);

    if (result)
    {
        do
        {
            Field* fields = result->Fetch();
            Mail* m = new Mail;

            m->messageID      = fields[0].GetUInt32();
            m->messageType    = fields[1].GetUInt8();
            m->sender         = fields[2].GetUInt32();
            m->receiver       = fields[3].GetUInt32();
            m->subject        = fields[4].GetString();
            m->body           = fields[5].GetString();
            bool has_items    = fields[6].GetBool();
            m->expire_time    = time_t(fields[7].GetUInt32());
            m->deliver_time   = time_t(fields[8].GetUInt32());
            m->money          = fields[9].GetUInt32();
            m->COD            = fields[10].GetUInt32();
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

    ////                                                       0      1       2        3        4           5          6         7           8           9           10
    //QueryResult* result = CharacterDatabase.PQuery("SELECT quest, status, explored, timer, mobcount1, mobcount2, mobcount3, mobcount4, itemcount1, itemcount2, itemcount3,
    //                                                    11          12          13           14
    //                                                itemcount4, itemcount5, itemcount6, playercount FROM character_queststatus WHERE guid = '%u'", GetGUID().GetCounter());

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

                questStatusData.Explored = (fields[2].GetUInt8() > 0);

                time_t quest_time = time_t(fields[3].GetUInt32());

                if (quest->HasSpecialFlag(QUEST_SPECIAL_FLAGS_TIMED) && !GetQuestRewardStatus(quest_id))
                {
                    AddTimedQuest(quest_id);

                    if (quest_time <= GameTime::GetGameTime())
                        questStatusData.Timer = 1;
                    else
                        questStatusData.Timer = uint32((quest_time - GameTime::GetGameTime()) * IN_MILLISECONDS);
                }
                else
                    quest_time = 0;

                for (uint32 i = 0; i < QUEST_OBJECTIVES_COUNT; ++i)
                    questStatusData.CreatureOrGOCount[i] = fields[4 + i].GetUInt16();

                for (uint32 i = 0; i < QUEST_ITEM_OBJECTIVES_COUNT; ++i)
                    questStatusData.ItemCount[i] = fields[8 + i].GetUInt16();

                questStatusData.PlayerCount = fields[14].GetUInt16();

                // add to quest log
                if (slot < MAX_QUEST_LOG_SIZE && questStatusData.Status != QUEST_STATUS_NONE)
                {
                    SetQuestSlot(slot, quest_id, uint32(quest_time)); // cast can't be helped

                    if (questStatusData.Status == QUEST_STATUS_COMPLETE)
                        SetQuestSlotState(slot, QUEST_STATE_COMPLETE);
                    else if (questStatusData.Status == QUEST_STATUS_FAILED)
                        SetQuestSlotState(slot, QUEST_STATE_FAIL);

                    for (uint8 idx = 0; idx < QUEST_OBJECTIVES_COUNT; ++idx)
                        if (questStatusData.CreatureOrGOCount[idx])
                            SetQuestSlotCounter(slot, idx, questStatusData.CreatureOrGOCount[idx]);

                    if (questStatusData.PlayerCount)
                        SetQuestSlotCounter(slot, QUEST_PVP_KILL_SLOT, questStatusData.PlayerCount);

                    ++slot;
                }


                TC_LOG_DEBUG("entities.player.loading", "Player::_LoadQuestStatus: Quest status is {%u} for quest {%u} for player (%s)", questStatusData.Status, quest_id, GetGUID().ToString().c_str());
            }
        }
        while (result->NextRow());
    }

    // clear quest log tail
    for (uint16 i = slot; i < MAX_QUEST_LOG_SIZE; ++i)
        SetQuestSlot(i, 0);
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
                if (quest->GetCharTitleId())
                {
                    if (CharTitlesEntry const* titleEntry = sCharTitlesStore.LookupEntry(quest->GetCharTitleId()))
                        SetTitle(titleEntry);
                }

                if (quest->GetBonusTalents())
                    m_questRewardTalentCount += quest->GetBonusTalents();

                if (quest->CanIncreaseRewardedQuestCounters())
                    m_RewardedQuests.insert(quest_id);
            }
        }
        while (result->NextRow());
    }
}

void Player::_LoadDailyQuestStatus(PreparedQueryResult result)
{
    for (uint32 quest_daily_idx = 0; quest_daily_idx < PLAYER_MAX_DAILY_QUESTS; ++quest_daily_idx)
        SetUInt32Value(PLAYER_FIELD_DAILY_QUESTS_1+quest_daily_idx, 0);

    m_DFQuests.clear();

    //QueryResult* result = CharacterDatabase.PQuery("SELECT quest, time FROM character_queststatus_daily WHERE guid = '%u'", GetGUID().GetCounter());

    if (result)
    {
        uint32 quest_daily_idx = 0;

        do
        {
            Field* fields = result->Fetch();
            if (Quest const* qQuest = sObjectMgr->GetQuestTemplate(fields[0].GetUInt32()))
            {
                if (qQuest->IsDFQuest())
                {
                    m_DFQuests.insert(qQuest->GetQuestId());
                    m_lastDailyQuestTime = time_t(fields[1].GetUInt32());
                    continue;
                }
            }

            if (quest_daily_idx >= PLAYER_MAX_DAILY_QUESTS)  // max amount with exist data in query
            {
                TC_LOG_ERROR("entities.player", "Player (GUID: %u) has more than 25 daily quest records in `charcter_queststatus_daily`", GetGUID().GetCounter());
                break;
            }

            uint32 quest_id = fields[0].GetUInt32();

            // save _any_ from daily quest times (it must be after last reset anyway)
            m_lastDailyQuestTime = time_t(fields[1].GetUInt32());

            Quest const* quest = sObjectMgr->GetQuestTemplate(quest_id);
            if (!quest)
                continue;

            SetUInt32Value(PLAYER_FIELD_DAILY_QUESTS_1+quest_daily_idx, quest_id);
            ++quest_daily_idx;

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
            TC_LOG_DEBUG("entities.player.loading", "Player::_LoadMonthlyQuestStatus: Loaded monthly quest cooldown (QuestID: %u) for player '%s' (%s)",
                quest_id, GetName().c_str(), GetGUID().ToString().c_str());
        }
        while (result->NextRow());
    }

    m_MonthlyQuestChanged = false;
}

void Player::_LoadSpells(PreparedQueryResult result)
{
    //QueryResult* result = CharacterDatabase.PQuery("SELECT spell, active, disabled FROM character_spell WHERE guid = '%u'", GetGUID().GetCounter());

    if (result)
    {
        do
            AddSpell((*result)[0].GetUInt32(), (*result)[1].GetBool(), false, false, (*result)[2].GetBool(), true);
        while (result->NextRow());
    }
}

void Player::_LoadGroup(PreparedQueryResult result)
{
    //QueryResult* result = CharacterDatabase.PQuery("SELECT guid FROM group_member WHERE memberGuid=%u", GetGUID().GetCounter());
    if (result)
    {
        if (Group* group = sGroupMgr->GetGroupByDbStoreId((*result)[0].GetUInt32()))
        {
            if (group->IsLeader(GetGUID()))
                SetFlag(PLAYER_FLAGS, PLAYER_FLAGS_GROUP_LEADER);

            uint8 subgroup = group->GetMemberGroup(GetGUID());
            SetGroup(group, subgroup);

            // Make sure the player's difficulty settings are always aligned with the group's settings in order to avoid issues when checking access requirements
            SetDungeonDifficulty(group->GetDungeonDifficulty());
            SetRaidDifficulty(group->GetRaidDifficulty());
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

    //         0          1    2           3            4          5
    // SELECT id, permanent, map, difficulty, extendState, resettime FROM character_instance LEFT JOIN instance ON instance = id WHERE guid = ?
    if (result)
    {
        do
        {
            Field* fields = result->Fetch();

            bool perm = fields[1].GetBool();
            uint32 mapId = fields[2].GetUInt16();
            uint32 instanceId = fields[0].GetUInt32();
            uint8 difficulty = fields[3].GetUInt8();
            BindExtensionState extendState = BindExtensionState(fields[4].GetUInt8());

            time_t resetTime = time_t(fields[5].GetUInt64());
            // the resettime for normal instances is only saved when the InstanceSave is unloaded
            // so the value read from the DB may be wrong here but only if the InstanceSave is loaded
            // and in that case it is not used

            bool deleteInstance = false;

            MapEntry const* mapEntry = sMapStore.LookupEntry(mapId);
            std::string mapname = mapEntry ? mapEntry->name[sWorld->GetDefaultDbcLocale()] : "Unknown";

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
                MapDifficulty const* mapDiff = GetMapDifficultyData(mapId, Difficulty(difficulty));
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

                stmt->setUInt32(0, GetGUID().GetCounter());
                stmt->setUInt32(1, instanceId);

                CharacterDatabase.Execute(stmt);

                continue;
            }

            // since non permanent binds are always solo bind, they can always be reset
            if (InstanceSave* save = sInstanceSaveMgr->AddInstanceSave(mapId, instanceId, Difficulty(difficulty), resetTime, !perm, true))
               BindToInstance(save, perm, extendState, true);
        }
        while (result->NextRow());
    }
}

InstancePlayerBind* Player::GetBoundInstance(uint32 mapid, Difficulty difficulty, bool withExpired)
{
    // some instances only have one difficulty
    MapDifficulty const* mapDiff = GetDownscaledMapDifficultyData(mapid, difficulty);
    if (!mapDiff)
        return nullptr;

    BoundInstancesMap::iterator itr = m_boundInstances[difficulty].find(mapid);
    if (itr != m_boundInstances[difficulty].end())
        if (itr->second.extendState || withExpired)
            return &itr->second;
    return nullptr;
}

InstanceSave* Player::GetInstanceSave(uint32 mapid, bool raid)
{
    InstancePlayerBind* pBind = GetBoundInstance(mapid, GetDifficulty(raid));
    InstanceSave* pSave = pBind ? pBind->save : nullptr;
    if (!pBind || !pBind->perm)
        if (Group* group = GetGroup())
            if (InstanceGroupBind* groupBind = group->GetBoundInstance(GetDifficulty(raid), mapid))
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

            stmt->setUInt32(0, GetGUID().GetCounter());
            stmt->setUInt32(1, itr->second.save->GetInstanceId());

            CharacterDatabase.Execute(stmt);
        }

        if (itr->second.perm)
            GetSession()->SendCalendarRaidLockout(itr->second.save, false);

        itr->second.save->RemovePlayer(this);               // save can become invalid
        m_boundInstances[difficulty].erase(itr++);
    }
}

InstancePlayerBind* Player::BindToInstance(InstanceSave* save, bool permanent, BindExtensionState extendState, bool load)
{
    if (save)
    {
        InstancePlayerBind& bind = m_boundInstances[save->GetDifficulty()][save->GetMapId()];
        if (extendState == EXTEND_STATE_KEEP) // special flag, keep the player's current extend state when updating for new boss down
        {
            if (save == bind.save)
                extendState = bind.extendState;
            else
                extendState = EXTEND_STATE_NORMAL;
        }
        if (!load)
        {
            if (bind.save)
            {
                // update the save when the group kills a boss
                if (permanent != bind.perm || save != bind.save || extendState != bind.extendState)
                {
                    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_CHAR_INSTANCE);

                    stmt->setUInt32(0, save->GetInstanceId());
                    stmt->setBool(1, permanent);
                    stmt->setUInt8(2, extendState);
                    stmt->setUInt32(3, GetGUID().GetCounter());
                    stmt->setUInt32(4, bind.save->GetInstanceId());

                    CharacterDatabase.Execute(stmt);
                }
            }
            else
            {
                PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_CHAR_INSTANCE);

                stmt->setUInt32(0, GetGUID().GetCounter());
                stmt->setUInt32(1, save->GetInstanceId());
                stmt->setBool(2, permanent);
                stmt->setUInt8(3, extendState);

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
        bind.extendState = extendState;
        if (!load)
            TC_LOG_DEBUG("maps", "Player::BindToInstance: Player '%s' (%s) is now bound to map (ID: %d, Instance: %d, Difficulty: %d)",
                GetName().c_str(), GetGUID().ToString().c_str(), save->GetMapId(), save->GetInstanceId(), save->GetDifficulty());
        sScriptMgr->OnPlayerBindToInstance(this, save->GetDifficulty(), save->GetMapId(), permanent, extendState);
        return &bind;
    }

    return nullptr;
}

void Player::BindToInstance()
{
    InstanceSave* mapSave = sInstanceSaveMgr->GetInstanceSave(_pendingBindId);
    if (!mapSave) //it seems sometimes mapSave is nullptr, but I did not check why
        return;

    WorldPacket data(SMSG_INSTANCE_SAVE_CREATED, 4);
    data << uint32(0);
    SendDirectMessage(&data);
    if (!IsGameMaster())
    {
        BindToInstance(mapSave, true, EXTEND_STATE_KEEP);
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
    uint32 counter = 0;

    WorldPacket data(SMSG_RAID_INSTANCE_INFO, 4);

    size_t p_counter = data.wpos();
    data << uint32(counter);                                // placeholder

    time_t now = GameTime::GetGameTime();

    for (uint8 i = 0; i < MAX_DIFFICULTY; ++i)
    {
        for (BoundInstancesMap::iterator itr = m_boundInstances[i].begin(); itr != m_boundInstances[i].end(); ++itr)
        {
            InstancePlayerBind const& bind = itr->second;
            if (bind.perm)
            {
                InstanceSave* save = bind.save;
                data << uint32(save->GetMapId());                          // map id
                data << uint32(save->GetDifficulty());                     // difficulty
                data << uint64(save->GetInstanceId());                     // instance id
                data << uint8(bind.extendState != EXTEND_STATE_EXPIRED);   // expired = 0
                data << uint8(bind.extendState == EXTEND_STATE_EXTENDED);  // extended = 1
                time_t nextReset = save->GetResetTime();
                if (bind.extendState == EXTEND_STATE_EXTENDED)
                    nextReset = sInstanceSaveMgr->GetSubsequentResetTime(save->GetMapId(), save->GetDifficulty(), save->GetResetTime());
                data << uint32(nextReset - now);                // reset time
                ++counter;
            }
        }
    }
    data.put<uint32>(p_counter, counter);
    SendDirectMessage(&data);
}

/*
- called on every successful teleportation to a map
*/
void Player::SendSavedInstances()
{
    bool hasBeenSaved = false;
    WorldPacket data;

    for (uint8 i = 0; i < MAX_DIFFICULTY; ++i)
    {
        for (BoundInstancesMap::iterator itr = m_boundInstances[i].begin(); itr != m_boundInstances[i].end(); ++itr)
        {
            if (itr->second.perm)                               // only permanent binds are sent
            {
                hasBeenSaved = true;
                break;
            }
        }
    }

    //Send opcode 811. true or false means, whether you have current raid/heroic instances
    data.Initialize(SMSG_UPDATE_INSTANCE_OWNERSHIP);
    data << uint32(hasBeenSaved);
    SendDirectMessage(&data);

    if (!hasBeenSaved)
        return;

    for (uint8 i = 0; i < MAX_DIFFICULTY; ++i)
    {
        for (BoundInstancesMap::iterator itr = m_boundInstances[i].begin(); itr != m_boundInstances[i].end(); ++itr)
        {
            if (itr->second.perm)
            {
                data.Initialize(SMSG_UPDATE_LAST_INSTANCE);
                data << uint32(itr->second.save->GetMapId());
                SendDirectMessage(&data);
            }
        }
    }
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
            if (ar->levelMin && GetLevel() < ar->levelMin)
                LevelMin = ar->levelMin;
            if (ar->levelMax && GetLevel() > ar->levelMax)
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
            GetSession()->SendAreaTriggerMessage("%s", GetSession()->GetTrinityString(LANG_INSTANCE_CLOSED));
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

        Difficulty target_difficulty = GetDifficulty(mapEntry->IsRaid());
        MapDifficulty const* mapDiff = GetDownscaledMapDifficultyData(target_map, target_difficulty);
        if (LevelMin || LevelMax || missingItem || missingQuest || missingAchievement)
        {
            if (report)
            {
                if (missingQuest && !ar->questFailedText.empty())
                    ChatHandler(GetSession()).PSendSysMessage("%s", ar->questFailedText.c_str());
                else if (mapDiff->hasErrorMessage) // if (missingAchievement) covered by this case
                    SendTransferAborted(target_map, TRANSFER_ABORT_DIFFICULTY, target_difficulty);
                else if (missingItem)
                    GetSession()->SendAreaTriggerMessage(GetSession()->GetTrinityString(LANG_LEVEL_MINREQUIRED_AND_ITEM), LevelMin, ASSERT_NOTNULL(sObjectMgr->GetItemTemplate(missingItem))->Name1.c_str());
                else if (LevelMin)
                    GetSession()->SendAreaTriggerMessage(GetSession()->GetTrinityString(LANG_LEVEL_MINREQUIRED), LevelMin);
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
    Map* map = FindMap();
    if (!map || !map->IsDungeon())
        return true;

    // raid instances require the player to be in a raid group to be valid
    if (map->IsRaid() && !sWorld->getBoolConfig(CONFIG_INSTANCE_IGNORE_RAID))
        if (!GetGroup() || !GetGroup()->isRaidGroup())
            return false;

    if (Group* group = GetGroup())
    {
        // check if player's group is bound to this instance
        InstanceGroupBind* bind = group->GetBoundInstance(map->GetDifficulty(), map->GetId());
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
        InstancePlayerBind* bind = GetBoundInstance(map->GetId(), map->GetDifficulty());
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
    PlayerInfo const* info = sObjectMgr->GetPlayerInfo(GetRace(), GetClass());
    if (!info)
    {
        TC_LOG_ERROR("entities.player", "Player::_LoadHomeBind: Player '%s' (%s) has incorrect race/class (%u/%u) pair. Can't load.",
            GetGUID().ToString().c_str(), GetName().c_str(), uint32(GetRace()), uint32(GetClass()));
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
            !bindMapEntry->Instanceable() && GetSession()->Expansion() >= bindMapEntry->Expansion())
            ok = true;
        else
        {
            PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_PLAYER_HOMEBIND);
            stmt->setUInt32(0, GetGUID().GetCounter());
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
        stmt->setUInt32(0, GetGUID().GetCounter());
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

    SQLTransaction trans = CharacterDatabase.BeginTransaction();
    PreparedStatement* stmt = nullptr;
    uint8 index = 0;

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHAR_FISHINGSTEPS);
    stmt->setUInt32(0, GetGUID().GetCounter());
    trans->Append(stmt);

    auto finiteAlways = [](float f) { return std::isfinite(f) ? f : 0.0f; };

    if (create)
    {
        //! Insert query
        /// @todo: Filter out more redundant fields that can take their default value at player create
        stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_CHARACTER);
        stmt->setUInt32(index++, GetGUID().GetCounter());
        stmt->setUInt32(index++, GetSession()->GetAccountId());
        stmt->setString(index++, GetName());
        stmt->setUInt8(index++, GetRace());
        stmt->setUInt8(index++, GetClass());
        stmt->setUInt8(index++, GetNativeGender());   // save gender from PLAYER_BYTES_3, UNIT_BYTES_0 changes with every transform effect
        stmt->setUInt8(index++, GetLevel());
        stmt->setUInt32(index++, GetXP());
        stmt->setUInt32(index++, GetMoney());
        stmt->setUInt8(index++, GetSkinId());
        stmt->setUInt8(index++, GetFaceId());
        stmt->setUInt8(index++, GetHairStyleId());
        stmt->setUInt8(index++, GetHairColorId());
        stmt->setUInt8(index++, GetFacialStyle());
        stmt->setUInt8(index++, GetBankBagSlotCount());
        stmt->setUInt8(index++, GetRestState());
        stmt->setUInt32(index++, GetUInt32Value(PLAYER_FLAGS));
        stmt->setUInt16(index++, (uint16)GetMapId());
        stmt->setUInt32(index++, (uint32)GetInstanceId());
        stmt->setUInt8(index++, (uint8(GetDungeonDifficulty()) | uint8(GetRaidDifficulty()) << 4));
        stmt->setFloat(index++, finiteAlways(GetPositionX()));
        stmt->setFloat(index++, finiteAlways(GetPositionY()));
        stmt->setFloat(index++, finiteAlways(GetPositionZ()));
        stmt->setFloat(index++, finiteAlways(GetOrientation()));
        stmt->setFloat(index++, finiteAlways(GetTransOffsetX()));
        stmt->setFloat(index++, finiteAlways(GetTransOffsetY()));
        stmt->setFloat(index++, finiteAlways(GetTransOffsetZ()));
        stmt->setFloat(index++, finiteAlways(GetTransOffsetO()));
        ObjectGuid::LowType transLowGUID = 0;
        if (GetTransport())
            transLowGUID = GetTransport()->GetGUID().GetCounter();
        stmt->setUInt32(index++, transLowGUID);

        std::ostringstream ss;
        ss << m_taxi;
        stmt->setString(index++, ss.str());
        stmt->setUInt8(index++, m_cinematic);
        stmt->setUInt32(index++, m_Played_time[PLAYED_TIME_TOTAL]);
        stmt->setUInt32(index++, m_Played_time[PLAYED_TIME_LEVEL]);
        stmt->setFloat(index++, finiteAlways(m_rest_bonus));
        stmt->setUInt32(index++, uint32(GameTime::GetGameTime()));
        stmt->setUInt8(index++,  (HasFlag(PLAYER_FLAGS, PLAYER_FLAGS_RESTING) ? 1 : 0));
        //save, far from tavern/city
        //save, but in tavern/city
        stmt->setUInt32(index++, m_resetTalentsCost);
        stmt->setUInt32(index++, uint32(m_resetTalentsTime));
        stmt->setUInt16(index++, (uint16)m_ExtraFlags);
        stmt->setUInt8(index++,  m_stableSlots);
        stmt->setUInt16(index++, (uint16)m_atLoginFlags);
        stmt->setUInt16(index++, GetZoneId());
        stmt->setUInt32(index++, uint32(m_deathExpireTime));

        ss.str("");
        ss << m_taxi.SaveTaxiDestinationsToString();

        stmt->setString(index++, ss.str());
        stmt->setUInt32(index++, GetArenaPoints());
        stmt->setUInt32(index++, GetHonorPoints());
        stmt->setUInt32(index++, GetUInt32Value(PLAYER_FIELD_TODAY_CONTRIBUTION));
        stmt->setUInt32(index++, GetUInt32Value(PLAYER_FIELD_YESTERDAY_CONTRIBUTION));
        stmt->setUInt32(index++, GetUInt32Value(PLAYER_FIELD_LIFETIME_HONORABLE_KILLS));
        stmt->setUInt16(index++, GetUInt16Value(PLAYER_FIELD_KILLS, 0));
        stmt->setUInt16(index++, GetUInt16Value(PLAYER_FIELD_KILLS, 1));
        stmt->setUInt32(index++, GetUInt32Value(PLAYER_CHOSEN_TITLE));
        stmt->setUInt64(index++, GetUInt64Value(PLAYER_FIELD_KNOWN_CURRENCIES));
        stmt->setUInt32(index++, GetUInt32Value(PLAYER_FIELD_WATCHED_FACTION_INDEX));
        stmt->setUInt8(index++, GetDrunkValue());
        stmt->setUInt32(index++, GetHealth());

        for (uint32 i = 0; i < MAX_POWERS; ++i)
            stmt->setUInt32(index++, GetPower(Powers(i)));

        stmt->setUInt32(index++, GetSession()->GetLatency());

        stmt->setUInt8(index++, m_specsCount);
        stmt->setUInt8(index++, m_activeSpec);

        ss.str("");
        for (uint32 i = 0; i < PLAYER_EXPLORED_ZONES_SIZE; ++i)
            ss << GetUInt32Value(PLAYER_EXPLORED_ZONES_1 + i) << ' ';
        stmt->setString(index++, ss.str());

        ss.str("");
        // cache equipment...
        for (uint32 i = 0; i < EQUIPMENT_SLOT_END * 2; ++i)
            ss << GetUInt32Value(PLAYER_VISIBLE_ITEM_1_ENTRYID + i) << ' ';

        // ...and bags for enum opcode
        for (uint32 i = INVENTORY_SLOT_BAG_START; i < INVENTORY_SLOT_BAG_END; ++i)
        {
            if (Item* item = GetItemByPos(INVENTORY_SLOT_BAG_0, i))
                ss << item->GetEntry();
            else
                ss << '0';
            ss << " 0 ";
        }

        stmt->setString(index++, ss.str());
        stmt->setUInt32(index++, GetUInt32Value(PLAYER_AMMO_ID));

        ss.str("");
        for (uint32 i = 0; i < KNOWN_TITLES_SIZE*2; ++i)
            ss << GetUInt32Value(PLAYER__FIELD_KNOWN_TITLES + i) << ' ';

        stmt->setString(index++, ss.str());
        stmt->setUInt8(index++, GetByteValue(PLAYER_FIELD_BYTES, PLAYER_FIELD_BYTES_OFFSET_ACTION_BAR_TOGGLES));
        stmt->setUInt32(index++, m_grantableLevels);
    }
    else
    {
        // Update query
        stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_CHARACTER);
        stmt->setString(index++, GetName());
        stmt->setUInt8(index++, GetRace());
        stmt->setUInt8(index++, GetClass());
        stmt->setUInt8(index++, GetNativeGender());   // save gender from PLAYER_BYTES_3, UNIT_BYTES_0 changes with every transform effect
        stmt->setUInt8(index++, GetLevel());
        stmt->setUInt32(index++, GetXP());
        stmt->setUInt32(index++, GetMoney());
        stmt->setUInt8(index++, GetSkinId());
        stmt->setUInt8(index++, GetFaceId());
        stmt->setUInt8(index++, GetHairStyleId());
        stmt->setUInt8(index++, GetHairColorId());
        stmt->setUInt8(index++, GetFacialStyle());
        stmt->setUInt8(index++, GetBankBagSlotCount());
        stmt->setUInt8(index++, GetRestState());
        stmt->setUInt32(index++, GetUInt32Value(PLAYER_FLAGS));

        if (!IsBeingTeleported())
        {
            stmt->setUInt16(index++, (uint16)GetMapId());
            stmt->setUInt32(index++, (uint32)GetInstanceId());
            stmt->setUInt8(index++, (uint8(GetDungeonDifficulty()) | uint8(GetRaidDifficulty()) << 4));
            stmt->setFloat(index++, finiteAlways(GetPositionX()));
            stmt->setFloat(index++, finiteAlways(GetPositionY()));
            stmt->setFloat(index++, finiteAlways(GetPositionZ()));
            stmt->setFloat(index++, finiteAlways(GetOrientation()));
        }
        else
        {
            stmt->setUInt16(index++, (uint16)GetTeleportDest().GetMapId());
            stmt->setUInt32(index++, (uint32)0);
            stmt->setUInt8(index++, (uint8(GetDungeonDifficulty()) | uint8(GetRaidDifficulty()) << 4));
            stmt->setFloat(index++, finiteAlways(GetTeleportDest().GetPositionX()));
            stmt->setFloat(index++, finiteAlways(GetTeleportDest().GetPositionY()));
            stmt->setFloat(index++, finiteAlways(GetTeleportDest().GetPositionZ()));
            stmt->setFloat(index++, finiteAlways(GetTeleportDest().GetOrientation()));
        }

        stmt->setFloat(index++, finiteAlways(GetTransOffsetX()));
        stmt->setFloat(index++, finiteAlways(GetTransOffsetY()));
        stmt->setFloat(index++, finiteAlways(GetTransOffsetZ()));
        stmt->setFloat(index++, finiteAlways(GetTransOffsetO()));
        ObjectGuid::LowType transLowGUID = 0;
        if (GetTransport())
            transLowGUID = GetTransport()->GetGUID().GetCounter();
        stmt->setUInt32(index++, transLowGUID);

        std::ostringstream ss;
        ss << m_taxi;
        stmt->setString(index++, ss.str());
        stmt->setUInt8(index++, m_cinematic);
        stmt->setUInt32(index++, m_Played_time[PLAYED_TIME_TOTAL]);
        stmt->setUInt32(index++, m_Played_time[PLAYED_TIME_LEVEL]);
        stmt->setFloat(index++, finiteAlways(m_rest_bonus));
        stmt->setUInt32(index++, uint32(GameTime::GetGameTime()));
        stmt->setUInt8(index++,  (HasFlag(PLAYER_FLAGS, PLAYER_FLAGS_RESTING) ? 1 : 0));
        //save, far from tavern/city
        //save, but in tavern/city
        stmt->setUInt32(index++, m_resetTalentsCost);
        stmt->setUInt32(index++, uint32(m_resetTalentsTime));
        stmt->setUInt16(index++, (uint16)m_ExtraFlags);
        stmt->setUInt8(index++,  m_stableSlots);
        stmt->setUInt16(index++, (uint16)m_atLoginFlags);
        stmt->setUInt16(index++, GetZoneId());
        stmt->setUInt32(index++, uint32(m_deathExpireTime));

        ss.str("");
        ss << m_taxi.SaveTaxiDestinationsToString();

        stmt->setString(index++, ss.str());
        stmt->setUInt32(index++, GetArenaPoints());
        stmt->setUInt32(index++, GetHonorPoints());
        stmt->setUInt32(index++, GetUInt32Value(PLAYER_FIELD_TODAY_CONTRIBUTION));
        stmt->setUInt32(index++, GetUInt32Value(PLAYER_FIELD_YESTERDAY_CONTRIBUTION));
        stmt->setUInt32(index++, GetUInt32Value(PLAYER_FIELD_LIFETIME_HONORABLE_KILLS));
        stmt->setUInt16(index++, GetUInt16Value(PLAYER_FIELD_KILLS, 0));
        stmt->setUInt16(index++, GetUInt16Value(PLAYER_FIELD_KILLS, 1));
        stmt->setUInt32(index++, GetUInt32Value(PLAYER_CHOSEN_TITLE));
        stmt->setUInt64(index++, GetUInt64Value(PLAYER_FIELD_KNOWN_CURRENCIES));
        stmt->setUInt32(index++, GetUInt32Value(PLAYER_FIELD_WATCHED_FACTION_INDEX));
        stmt->setUInt8(index++, GetDrunkValue());
        stmt->setUInt32(index++, GetHealth());

        for (uint32 i = 0; i < MAX_POWERS; ++i)
            stmt->setUInt32(index++, GetPower(Powers(i)));

        stmt->setUInt32(index++, GetSession()->GetLatency());

        stmt->setUInt8(index++, m_specsCount);
        stmt->setUInt8(index++, m_activeSpec);

        ss.str("");
        for (uint32 i = 0; i < PLAYER_EXPLORED_ZONES_SIZE; ++i)
            ss << GetUInt32Value(PLAYER_EXPLORED_ZONES_1 + i) << ' ';
        stmt->setString(index++, ss.str());

        ss.str("");
        // cache equipment...
        for (uint32 i = 0; i < EQUIPMENT_SLOT_END * 2; ++i)
            ss << GetUInt32Value(PLAYER_VISIBLE_ITEM_1_ENTRYID + i) << ' ';

        // ...and bags for enum opcode
        for (uint32 i = INVENTORY_SLOT_BAG_START; i < INVENTORY_SLOT_BAG_END; ++i)
        {
            if (Item* item = GetItemByPos(INVENTORY_SLOT_BAG_0, i))
                ss << item->GetEntry();
            else
                ss << '0';
            ss << " 0 ";
        }

        stmt->setString(index++, ss.str());
        stmt->setUInt32(index++, GetUInt32Value(PLAYER_AMMO_ID));

        ss.str("");
        for (uint32 i = 0; i < KNOWN_TITLES_SIZE*2; ++i)
            ss << GetUInt32Value(PLAYER__FIELD_KNOWN_TITLES + i) << ' ';

        stmt->setString(index++, ss.str());
        stmt->setUInt8(index++, GetByteValue(PLAYER_FIELD_BYTES, PLAYER_FIELD_BYTES_OFFSET_ACTION_BAR_TOGGLES));
        stmt->setUInt32(index++, m_grantableLevels);

        stmt->setUInt8(index++, IsInWorld() && !GetSession()->PlayerLogout() ? 1 : 0);
        // Index
        stmt->setUInt32(index++, GetGUID().GetCounter());
    }

    trans->Append(stmt);

    if (m_fishingSteps != 0)
    {
        stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_CHAR_FISHINGSTEPS);
        index = 0;
        stmt->setUInt32(index++, GetGUID().GetCounter());
        stmt->setUInt32(index++, m_fishingSteps);
        trans->Append(stmt);
    }

    if (m_mailsUpdated)                                     //save mails only when needed
        _SaveMail(trans);

    _SaveBGData(trans);
    _SaveInventory(trans);
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

    // check if stats should only be saved on logout
    // save stats can be out of transaction
    if (m_session->isLogingOut() || !sWorld->getBoolConfig(CONFIG_STATS_SAVE_ONLY_ON_LOGOUT))
        _SaveStats(trans);

    CharacterDatabase.CommitTransaction(trans);

    // save pet (hunter pet level and experience and all type pets health/mana).
    if (Pet* pet = GetPet())
        pet->SavePetToDB(PET_SAVE_AS_CURRENT);
}

// fast save function for item/money cheating preventing - save only inventory and money state
void Player::SaveInventoryAndGoldToDB(SQLTransaction& trans)
{
    _SaveInventory(trans);
    SaveGoldToDB(trans);
}

void Player::SaveGoldToDB(SQLTransaction& trans) const
{
    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_CHAR_MONEY);
    stmt->setUInt32(0, GetMoney());
    stmt->setUInt32(1, GetGUID().GetCounter());
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
                stmt->setUInt32(0, GetGUID().GetCounter());
                stmt->setUInt8(1, m_activeSpec);
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
                stmt->setUInt32(2,  GetGUID().GetCounter());
                stmt->setUInt8(3, itr->first);
                stmt->setUInt8(4, m_activeSpec);
                trans->Append(stmt);

                itr->second.uState = ACTIONBUTTON_UNCHANGED;
                ++itr;
                break;
            case ACTIONBUTTON_DELETED:
                stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHAR_ACTION_BY_BUTTON_SPEC);
                stmt->setUInt32(0, GetGUID().GetCounter());
                stmt->setUInt8(1, itr->first);
                stmt->setUInt8(2, m_activeSpec);
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
    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHAR_AURA);
    stmt->setUInt32(0, GetGUID().GetCounter());
    trans->Append(stmt);

    for (AuraMap::const_iterator itr = m_ownedAuras.begin(); itr != m_ownedAuras.end(); ++itr)
    {
        if (!itr->second->CanBeSaved())
            continue;

        Aura* aura = itr->second;

        int32 damage[MAX_SPELL_EFFECTS];
        int32 baseDamage[MAX_SPELL_EFFECTS];
        uint8 effMask = 0;
        uint8 recalculateMask = 0;
        for (uint8 i = 0; i < MAX_SPELL_EFFECTS; ++i)
        {
            if (AuraEffect const* effect = aura->GetEffect(i))
            {
                baseDamage[i] = effect->GetBaseAmount();
                damage[i] = effect->GetAmount();
                effMask |= 1 << i;
                if (effect->CanBeRecalculated())
                    recalculateMask |= 1 << i;
            }
            else
            {
                baseDamage[i] = 0;
                damage[i] = 0;
            }
        }

        uint8 index = 0;
        stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_AURA);
        stmt->setUInt32(index++, GetGUID().GetCounter());
        stmt->setUInt64(index++, itr->second->GetCasterGUID().GetRawValue());
        stmt->setUInt64(index++, itr->second->GetCastItemGUID().GetRawValue());
        stmt->setUInt32(index++, itr->second->GetId());
        stmt->setUInt8(index++, effMask);
        stmt->setUInt8(index++, recalculateMask);
        stmt->setUInt8(index++, itr->second->GetStackAmount());
        stmt->setInt32(index++, damage[0]);
        stmt->setInt32(index++, damage[1]);
        stmt->setInt32(index++, damage[2]);
        stmt->setInt32(index++, baseDamage[0]);
        stmt->setInt32(index++, baseDamage[1]);
        stmt->setInt32(index++, baseDamage[2]);
        stmt->setInt32(index++, itr->second->GetMaxDuration());
        stmt->setInt32(index++, itr->second->GetDuration());
        stmt->setUInt8(index++, itr->second->GetCharges());
        stmt->setFloat(index++, itr->second->GetCritChance());
        stmt->setBool (index++, itr->second->CanApplyResilience());
        trans->Append(stmt);
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
        if (!item)
            continue;

        if (item->GetState() == ITEM_NEW)
        {
            if (ItemTemplate const* itemTemplate = item->GetTemplate())
                if (itemTemplate->Flags & ITEM_FLAG_HAS_LOOT)
                    sLootItemStorage->RemoveStoredLootForContainer(item->GetGUID().GetCounter());

            continue;
        }

        stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHAR_INVENTORY_BY_ITEM);
        stmt->setUInt32(0, item->GetGUID().GetCounter());
        trans->Append(stmt);

        stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_ITEM_INSTANCE);
        stmt->setUInt32(0, item->GetGUID().GetCounter());
        trans->Append(stmt);
        m_items[i]->FSetState(ITEM_NEW);

        if (ItemTemplate const* itemTemplate = item->GetTemplate())
            if (itemTemplate->Flags & ITEM_FLAG_HAS_LOOT)
                sLootItemStorage->RemoveStoredLootForContainer(item->GetGUID().GetCounter());
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

    ObjectGuid::LowType lowGuid = GetGUID().GetCounter();
    for (size_t i = 0; i < m_itemUpdateQueue.size(); ++i)
    {
        Item* item = m_itemUpdateQueue[i];
        if (!item)
            continue;

        Bag* container = item->GetContainer();
        ObjectGuid::LowType bag_guid = container ? container->GetGUID().GetCounter() : 0;

        if (item->GetState() != ITEM_REMOVED)
        {
            Item* test = GetItemByPos(item->GetBagSlot(), item->GetSlot());
            if (test == nullptr)
            {
                ObjectGuid::LowType bagTestGUID = 0;
                if (Item* test2 = GetItemByPos(INVENTORY_SLOT_BAG_0, item->GetBagSlot()))
                    bagTestGUID = test2->GetGUID().GetCounter();

                TC_LOG_ERROR("entities.player", "Player::_SaveInventory: Player '%s' (%s) has incorrect values (Bag: %u, Slot: %u) for the item (%s, State: %d). The player doesn't have an item at that position.",
                    GetName().c_str(), GetGUID().ToString().c_str(), item->GetBagSlot(), item->GetSlot(), item->GetGUID().ToString().c_str(), (int32)item->GetState());
                // according to the test that was just performed nothing should be in this slot, delete
                stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHAR_INVENTORY_BY_BAG_SLOT);
                stmt->setUInt32(0, bagTestGUID);
                stmt->setUInt8(1, item->GetSlot());
                stmt->setUInt32(2, lowGuid);
                trans->Append(stmt);

                RemoveTradeableItem(item);
                RemoveEnchantmentDurationsReferences(item);
                RemoveItemDurations(item);

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
                if (item->GetState() != ITEM_NEW) // only for existing items, no duplicates
                    item->SaveToDB(trans);
                // ...but do not save position in invntory
                continue;
            }
        }

        switch (item->GetState())
        {
            case ITEM_NEW:
            case ITEM_CHANGED:
                stmt = CharacterDatabase.GetPreparedStatement(CHAR_REP_INVENTORY_ITEM);
                stmt->setUInt32(0, lowGuid);
                stmt->setUInt32(1, bag_guid);
                stmt->setUInt8 (2, item->GetSlot());
                stmt->setUInt32(3, item->GetGUID().GetCounter());
                trans->Append(stmt);
                break;
            case ITEM_REMOVED:
                stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHAR_INVENTORY_BY_ITEM);
                stmt->setUInt32(0, item->GetGUID().GetCounter());
                trans->Append(stmt);
            case ITEM_UNCHANGED:
                break;
        }

        item->SaveToDB(trans);                                   // item have unchanged inventory record and can be save standalone
    }
    m_itemUpdateQueue.clear();
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
                for (std::vector<uint32>::iterator itr2 = m->removedItems.begin(); itr2 != m->removedItems.end(); ++itr2)
                {
                    stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_MAIL_ITEM);
                    stmt->setUInt32(0, *itr2);
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
                    stmt->setUInt32(0, itr2->item_guid);
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
                uint8 index = 0;
                stmt = CharacterDatabase.GetPreparedStatement(CHAR_REP_CHAR_QUESTSTATUS);

                stmt->setUInt32(index++, GetGUID().GetCounter());
                stmt->setUInt32(index++, statusItr->first);
                stmt->setUInt8(index++, uint8(statusItr->second.Status));
                stmt->setBool(index++, statusItr->second.Explored);
                stmt->setUInt32(index++, uint32(statusItr->second.Timer / IN_MILLISECONDS+ GameTime::GetGameTime()));

                for (uint8 i = 0; i < QUEST_OBJECTIVES_COUNT; i++)
                    stmt->setUInt16(index++, statusItr->second.CreatureOrGOCount[i]);

                for (uint8 i = 0; i < QUEST_ITEM_OBJECTIVES_COUNT; i++)
                    stmt->setUInt16(index++, statusItr->second.ItemCount[i]);

                stmt->setUInt16(index, statusItr->second.PlayerCount);
                trans->Append(stmt);
            }
        }
        else
        {
            stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHAR_QUESTSTATUS_BY_QUEST);
            stmt->setUInt32(0, GetGUID().GetCounter());
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
            stmt->setUInt32(0, GetGUID().GetCounter());
            stmt->setUInt32(1, saveItr->first);
            trans->Append(stmt);

        }
        else if (saveItr->second == QUEST_FORCE_DELETE_SAVE_TYPE || !keepAbandoned)
        {
            stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHAR_QUESTSTATUS_REWARDED_BY_QUEST);
            stmt->setUInt32(0, GetGUID().GetCounter());
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
    stmt->setUInt32(0, GetGUID().GetCounter());
    trans->Append(stmt);

    for (uint32 quest_daily_idx = 0; quest_daily_idx < PLAYER_MAX_DAILY_QUESTS; ++quest_daily_idx)
    {
        if (GetUInt32Value(PLAYER_FIELD_DAILY_QUESTS_1+quest_daily_idx))
        {
            stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_CHARACTER_QUESTSTATUS_DAILY);
            stmt->setUInt32(0, GetGUID().GetCounter());
            stmt->setUInt32(1, GetUInt32Value(PLAYER_FIELD_DAILY_QUESTS_1+quest_daily_idx));
            stmt->setUInt64(2, uint64(m_lastDailyQuestTime));
            trans->Append(stmt);
        }
    }

    if (!m_DFQuests.empty())
    {
        for (DFQuestsDoneList::iterator itr = m_DFQuests.begin(); itr != m_DFQuests.end(); ++itr)
        {
            stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_CHARACTER_QUESTSTATUS_DAILY);
            stmt->setUInt32(0, GetGUID().GetCounter());
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
    stmt->setUInt32(0, GetGUID().GetCounter());
    trans->Append(stmt);

    for (QuestSet::const_iterator iter = m_weeklyquests.begin(); iter != m_weeklyquests.end(); ++iter)
    {
        uint32 questId  = *iter;

        stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_CHARACTER_QUESTSTATUS_WEEKLY);
        stmt->setUInt32(0, GetGUID().GetCounter());
        stmt->setUInt32(1, questId);
        trans->Append(stmt);
    }

    m_WeeklyQuestChanged = false;
}

void Player::_SaveSeasonalQuestStatus(SQLTransaction& trans)
{
    if (!m_SeasonalQuestChanged)
        return;

    // we don't need transactions here.
    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHARACTER_QUESTSTATUS_SEASONAL);
    stmt->setUInt32(0, GetGUID().GetCounter());
    trans->Append(stmt);

    m_SeasonalQuestChanged = false;

    if (m_seasonalquests.empty())
        return;

    for (SeasonalEventQuestMap::const_iterator iter = m_seasonalquests.begin(); iter != m_seasonalquests.end(); ++iter)
    {
        uint16 eventId = iter->first;

        for (SeasonalQuestSet::const_iterator itr = iter->second.begin(); itr != iter->second.end(); ++itr)
        {
            uint32 questId = *itr;

            stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_CHARACTER_QUESTSTATUS_SEASONAL);
            stmt->setUInt32(0, GetGUID().GetCounter());
            stmt->setUInt32(1, questId);
            stmt->setUInt32(2, eventId);
            trans->Append(stmt);
        }
    }
}

void Player::_SaveMonthlyQuestStatus(SQLTransaction& trans)
{
    if (!m_MonthlyQuestChanged || m_monthlyquests.empty())
        return;

    // we don't need transactions here.
    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHARACTER_QUESTSTATUS_MONTHLY);
    stmt->setUInt32(0, GetGUID().GetCounter());
    trans->Append(stmt);

    for (QuestSet::const_iterator iter = m_monthlyquests.begin(); iter != m_monthlyquests.end(); ++iter)
    {
        uint32 questId = *iter;

        stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_CHARACTER_QUESTSTATUS_MONTHLY);
        stmt->setUInt32(0, GetGUID().GetCounter());
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
            stmt->setUInt32(0, GetGUID().GetCounter());
            stmt->setUInt32(1, itr->first);
            trans->Append(stmt);

            mSkillStatus.erase(itr++);
            continue;
        }

        uint32 valueData = GetUInt32Value(PLAYER_SKILL_VALUE_INDEX(itr->second.pos));
        uint16 value = SKILL_VALUE(valueData);
        uint16 max = SKILL_MAX(valueData);

        switch (itr->second.uState)
        {
            case SKILL_NEW:
                stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_CHAR_SKILLS);
                stmt->setUInt32(0, GetGUID().GetCounter());
                stmt->setUInt16(1, uint16(itr->first));
                stmt->setUInt16(2, value);
                stmt->setUInt16(3, max);
                trans->Append(stmt);

                break;
            case SKILL_CHANGED:
                stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_CHAR_SKILLS);
                stmt->setUInt16(0, value);
                stmt->setUInt16(1, max);
                stmt->setUInt32(2, GetGUID().GetCounter());
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
            stmt->setUInt32(1, GetGUID().GetCounter());
            trans->Append(stmt);
        }

        // add only changed/new not dependent spells
        if (!itr->second->dependent && (itr->second->state == PLAYERSPELL_NEW || itr->second->state == PLAYERSPELL_CHANGED))
        {
            stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_CHAR_SPELL);
            stmt->setUInt32(0, GetGUID().GetCounter());
            stmt->setUInt32(1, itr->first);
            stmt->setBool(2, itr->second->active);
            stmt->setBool(3, itr->second->disabled);
            trans->Append(stmt);
        }

        if (itr->second->state == PLAYERSPELL_REMOVED)
        {
            delete itr->second;
            itr = m_spells.erase(itr);
            continue;
        }

        if (itr->second->state != PLAYERSPELL_TEMPORARY)
            itr->second->state = PLAYERSPELL_UNCHANGED;

        ++itr;
    }
}

// save player stats -- only for external usage
// real stats will be recalculated on player login
void Player::_SaveStats(SQLTransaction& trans) const
{
    // check if stat saving is enabled and if char level is high enough
    if (!sWorld->getIntConfig(CONFIG_MIN_LEVEL_STAT_SAVE) || GetLevel() < sWorld->getIntConfig(CONFIG_MIN_LEVEL_STAT_SAVE))
        return;

    PreparedStatement* stmt;

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHAR_STATS);
    stmt->setUInt32(0, GetGUID().GetCounter());
    trans->Append(stmt);

    uint8 index = 0;

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_CHAR_STATS);
    stmt->setUInt32(index++, GetGUID().GetCounter());
    stmt->setUInt32(index++, GetMaxHealth());

    for (uint8 i = 0; i < MAX_POWERS; ++i)
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
    stmt->setUInt32(index++, GetUInt32Value(PLAYER_FIELD_COMBAT_RATING_1 + CR_CRIT_TAKEN_SPELL));

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

    time_t current = GameTime::GetGameTime();
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
    return  GetSession()->m_muteTime <= GameTime::GetGameTime();
}

/*********************************************************/
/***              LOW LEVEL FUNCTIONS:Notifiers        ***/
/*********************************************************/

void Player::SendAttackSwingNotInRange() const
{
    WorldPacket data(SMSG_ATTACKSWING_NOTINRANGE, 0);
    SendDirectMessage(&data);
}

void Player::SavePositionInDB(WorldLocation const& loc, uint16 zoneId, ObjectGuid guid, SQLTransaction& trans)
{
    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_CHARACTER_POSITION);

    stmt->setFloat(0, loc.GetPositionX());
    stmt->setFloat(1, loc.GetPositionY());
    stmt->setFloat(2, loc.GetPositionZ());
    stmt->setFloat(3, loc.GetOrientation());
    stmt->setUInt16(4, uint16(loc.GetMapId()));
    stmt->setUInt16(5, zoneId);
    stmt->setUInt32(6, guid.GetCounter());

    CharacterDatabase.ExecuteOrAppend(trans, stmt);
}

void Player::SetUInt32ValueInArray(Tokenizer& tokens, uint16 index, uint32 value)
{
    char buf[11];
    snprintf(buf, 11, "%u", value);

    if (index >= tokens.size())
        return;

    tokens[index] = buf;
}

void Player::Customize(CharacterCustomizeInfo const* customizeInfo, SQLTransaction& trans)
{
    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_GENDER_AND_APPEARANCE);

    stmt->setUInt8(0, customizeInfo->Gender);
    stmt->setUInt8(1, customizeInfo->Skin);
    stmt->setUInt8(2, customizeInfo->Face);
    stmt->setUInt8(3, customizeInfo->HairStyle);
    stmt->setUInt8(4, customizeInfo->HairColor);
    stmt->setUInt8(5, customizeInfo->FacialHair);
    stmt->setUInt32(6, customizeInfo->Guid.GetCounter());

    CharacterDatabase.ExecuteOrAppend(trans, stmt);
}

void Player::SendAttackSwingDeadTarget() const
{
    WorldPacket data(SMSG_ATTACKSWING_DEADTARGET, 0);
    SendDirectMessage(&data);
}

void Player::SendAttackSwingCantAttack() const
{
    WorldPacket data(SMSG_ATTACKSWING_CANT_ATTACK, 0);
    SendDirectMessage(&data);
}

void Player::SendAttackSwingCancelAttack() const
{
    WorldPacket data(SMSG_CANCEL_COMBAT, 0);
    SendDirectMessage(&data);
}

void Player::SendAttackSwingBadFacingAttack() const
{
    WorldPacket data(SMSG_ATTACKSWING_BADFACING, 0);
    SendDirectMessage(&data);
}

void Player::SendAutoRepeatCancel(Unit* target)
{
    WorldPacket data(SMSG_CANCEL_AUTO_REPEAT, target->GetPackGUID().size());
    data << target->GetPackGUID();                     // may be it's target guid
    SendMessageToSet(&data, true);
}

void Player::SendExplorationExperience(uint32 Area, uint32 Experience) const
{
    WorldPacket data(SMSG_EXPLORATION_EXPERIENCE, 8);
    data << uint32(Area);
    data << uint32(Experience);
    SendDirectMessage(&data);
}

void Player::SendDungeonDifficulty(bool IsInGroup) const
{
    uint8 val = 0x00000001;
    WorldPacket data(MSG_SET_DUNGEON_DIFFICULTY, 12);
    data << (uint32)GetDungeonDifficulty();
    data << uint32(val);
    data << uint32(IsInGroup);
    SendDirectMessage(&data);
}

void Player::SendRaidDifficulty(bool IsInGroup, int32 forcedDifficulty) const
{
    uint8 val = 0x00000001;
    WorldPacket data(MSG_SET_RAID_DIFFICULTY, 12);
    data << uint32(forcedDifficulty == -1 ? GetRaidDifficulty() : forcedDifficulty);
    data << uint32(val);
    data << uint32(IsInGroup);
    SendDirectMessage(&data);
}

void Player::SendResetFailedNotify(uint32 mapid) const
{
    WorldPacket data(SMSG_RESET_FAILED_NOTIFY, 4);
    data << uint32(mapid);
    SendDirectMessage(&data);
}

/// Reset all solo instances and optionally send a message on success for each
void Player::ResetInstances(uint8 method, bool isRaid)
{
    // method can be INSTANCE_RESET_ALL, INSTANCE_RESET_CHANGE_DIFFICULTY, INSTANCE_RESET_GROUP_JOIN

    // we assume that when the difficulty changes, all instances that can be reset will be
    Difficulty diff = GetDifficulty(isRaid);

    for (BoundInstancesMap::iterator itr = m_boundInstances[diff].begin(); itr != m_boundInstances[diff].end();)
    {
        InstanceSave* p = itr->second.save;
        MapEntry const* entry = sMapStore.LookupEntry(itr->first);
        if (!entry || entry->IsRaid() != isRaid || !p->CanReset())
        {
            ++itr;
            continue;
        }

        if (method == INSTANCE_RESET_ALL)
        {
            // the "reset all instances" method can only reset normal maps
            if (entry->map_type == MAP_RAID || diff == DUNGEON_DIFFICULTY_HEROIC)
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
    WorldPacket data(SMSG_INSTANCE_RESET, 4);
    data << uint32(MapId);
    SendDirectMessage(&data);
}

void Player::SendResetInstanceFailed(uint32 reason, uint32 MapId) const
{
    /*reasons for instance reset failure:
    // 0: There are players inside the instance.
    // 1: There are players offline in your party.
    // 2>: There are players in your party attempting to zone into an instance.
    */
    WorldPacket data(SMSG_INSTANCE_RESET_FAILED, 4);
    data << uint32(reason);
    data << uint32(MapId);
    SendDirectMessage(&data);
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

void Player::SetContestedPvP(Player* attackedPlayer)
{
    if (attackedPlayer && (attackedPlayer == this || (duel && duel->Opponent == attackedPlayer)))
        return;

    SetContestedPvPTimer(30000);
    if (!HasUnitState(UNIT_STATE_ATTACK_PLAYER))
    {
        AddUnitState(UNIT_STATE_ATTACK_PLAYER);
        SetFlag(PLAYER_FLAGS, PLAYER_FLAGS_CONTESTED_PVP);
        // call MoveInLineOfSight for nearby contested guards
        Trinity::AIRelocationNotifier notifier(*this);
        Cell::VisitWorldObjects(this, notifier, GetVisibilityRange());
    }
    for (Unit* unit : m_Controlled)
    {
        if (!unit->HasUnitState(UNIT_STATE_ATTACK_PLAYER))
        {
            unit->AddUnitState(UNIT_STATE_ATTACK_PLAYER);
            Trinity::AIRelocationNotifier notifier(*unit);
            Cell::VisitWorldObjects(this, notifier, GetVisibilityRange());
        }
    }
}

void Player::UpdateContestedPvP(uint32 diff)
{
    if (!m_contestedPvPTimer || IsInCombat())
        return;

    if (m_contestedPvPTimer <= diff)
        ResetContestedPvP();
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
    if (pvpInfo.EndTimer && pvpInfo.EndTimer <= currTime)
    {
        pvpInfo.EndTimer = 0;
        RemoveFlag(PLAYER_FLAGS, PLAYER_FLAGS_PVP_TIMER);
    }

    if (IsPvP() && !pvpInfo.IsHostile && !HasFlag(PLAYER_FLAGS, PLAYER_FLAGS_IN_PVP | PLAYER_FLAGS_PVP_TIMER))
        UpdatePvP(false);
}

void Player::UpdateDuelFlag(time_t currTime)
{
    if (duel && duel->State == DUEL_STATE_COUNTDOWN && duel->StartTime <= currTime)
    {
        sScriptMgr->OnPlayerDuelStart(this, duel->Opponent);

        SetUInt32Value(PLAYER_DUEL_TEAM, 1);
        duel->Opponent->SetUInt32Value(PLAYER_DUEL_TEAM, 2);

        duel->State = DUEL_STATE_IN_PROGRESS;
        duel->Opponent->duel->State = DUEL_STATE_IN_PROGRESS;
    }
}

Pet* Player::GetPet() const
{
    if (ObjectGuid pet_guid = GetPetGUID())
    {
        if (!pet_guid.IsPet())
            return nullptr;

        Pet* pet = ObjectAccessor::GetPet(*this, pet_guid);

        if (!pet)
            return nullptr;

        if (IsInWorld())
            return pet;

        // there may be a guardian in this slot
        //TC_LOG_ERROR("entities.player", "Player::GetPet: Pet %u does not exist.", GUID_LOPART(pet_guid));
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
        WorldPacket data(SMSG_PET_SPELLS, 8);
        data << uint64(0);
        SendDirectMessage(&data);

        if (GetGroup())
            SetGroupUpdateFlag(GROUP_UPDATE_PET);
    }
}

void Player::AddPetAura(PetAura const* petSpell)
{
    m_petAuras.insert(petSpell);
    if (Pet* pet = GetPet())
        pet->CastPetAura(petSpell);
}

void Player::RemovePetAura(PetAura const* petSpell)
{
    m_petAuras.erase(petSpell);
    if (Pet* pet = GetPet())
        pet->RemoveAurasDueToSpell(petSpell->GetAura(pet->GetEntry()));
}

void Player::StopCastingCharm()
{
    if (IsGhouled())
    {
        RemoveGhoul();
        return;
    }

    Unit* charm = GetCharmed();
    if (!charm)
        return;

    if (charm->GetTypeId() == TYPEID_UNIT)
    {
        if (charm->ToCreature()->HasUnitTypeMask(UNIT_MASK_PUPPET))
            static_cast<Puppet*>(charm)->UnSummon();
        else if (charm->IsVehicle())
            ExitVehicle();
    }
    if (GetCharmedGUID())
        charm->RemoveCharmAuras();

    if (GetCharmedGUID())
    {
        TC_LOG_FATAL("entities.player", "Player::StopCastingCharm: Player '%s' (%s) is not able to uncharm unit (%s)", GetName().c_str(), GetGUID().ToString().c_str(), GetCharmedGUID().ToString().c_str());
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

    WorldPacket data;
    ChatHandler::BuildChatPacket(data, CHAT_MSG_SAY, language, this, this, _text);
    SendMessageToSetInRange(&data, sWorld->getFloatConfig(CONFIG_LISTEN_RANGE_SAY), true);
}

void Player::Say(uint32 textId, WorldObject const* target /*= nullptr*/)
{
    Talk(textId, CHAT_MSG_SAY, sWorld->getFloatConfig(CONFIG_LISTEN_RANGE_SAY), target);
}

void Player::Yell(std::string const& text, Language language, WorldObject const* /*= nullptr*/)
{
    std::string _text(text);
    sScriptMgr->OnPlayerChat(this, CHAT_MSG_YELL, language, _text);

    WorldPacket data;
    ChatHandler::BuildChatPacket(data, CHAT_MSG_YELL, language, this, this, _text);
    SendMessageToSetInRange(&data, sWorld->getFloatConfig(CONFIG_LISTEN_RANGE_YELL), true);
}

void Player::Yell(uint32 textId, WorldObject const* target /*= nullptr*/)
{
    Talk(textId, CHAT_MSG_YELL, sWorld->getFloatConfig(CONFIG_LISTEN_RANGE_YELL), target);
}

void Player::TextEmote(std::string const& text, WorldObject const* /*= nullptr*/, bool /*= false*/)
{
    std::string _text(text);
    sScriptMgr->OnPlayerChat(this, CHAT_MSG_EMOTE, LANG_UNIVERSAL, _text);

    WorldPacket data;
    ChatHandler::BuildChatPacket(data, CHAT_MSG_EMOTE, LANG_UNIVERSAL, this, this, _text);
    SendMessageToSetInRange(&data, sWorld->getFloatConfig(CONFIG_LISTEN_RANGE_TEXTEMOTE), true, !GetSession()->HasPermission(rbac::RBAC_PERM_TWO_SIDE_INTERACTION_CHAT));
}

void Player::TextEmote(uint32 textId, WorldObject const* target /*= nullptr*/, bool /*isBossEmote = false*/)
{
    Talk(textId, CHAT_MSG_EMOTE, sWorld->getFloatConfig(CONFIG_LISTEN_RANGE_TEXTEMOTE), target);
}

void Player::Whisper(std::string const& text, Language language, Player* target, bool /*= false*/)
{
    ASSERT(target);

    bool isAddonMessage = language == LANG_ADDON;

    if (!isAddonMessage)                                    // if not addon data
        language = LANG_UNIVERSAL;                          // whispers should always be readable

    std::string _text(text);
    sScriptMgr->OnPlayerChat(this, CHAT_MSG_WHISPER, language, _text, target);

    WorldPacket data;
    ChatHandler::BuildChatPacket(data, CHAT_MSG_WHISPER, Language(language), this, this, _text);
    target->SendDirectMessage(&data);

    // rest stuff shouldn't happen in case of addon message
    if (isAddonMessage)
        return;

    ChatHandler::BuildChatPacket(data, CHAT_MSG_WHISPER_INFORM, Language(language), target, target, _text);
    SendDirectMessage(&data);

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

void Player::Whisper(uint32 textId, Player* target, bool /*isBossWhisper = false*/)
{
    if (!target)
        return;

    BroadcastText const* bct = sObjectMgr->GetBroadcastText(textId);
    if (!bct)
    {
        TC_LOG_ERROR("entities.unit", "WorldObject::MonsterWhisper: `broadcast_text` was not %u found", textId);
        return;
    }

    LocaleConstant locale = target->GetSession()->GetSessionDbLocaleIndex();
    WorldPacket data;
    ChatHandler::BuildChatPacket(data, CHAT_MSG_WHISPER, LANG_UNIVERSAL, this, target, bct->GetText(locale, GetGender()), 0, "", locale);
    target->SendDirectMessage(&data);
}

Item* Player::GetMItem(uint32 id)
{
    ItemMap::const_iterator itr = mMitems.find(id);
    return itr != mMitems.end() ? itr->second : nullptr;
}

void Player::AddMItem(Item* it)
{
    ASSERT(it);
    //ASSERT deleted, because items can be added before loading
    mMitems[it->GetGUID().GetCounter()] = it;
}

bool Player::RemoveMItem(uint32 id)
{
    return mMitems.erase(id) ? true : false;
}

void Player::SendOnCancelExpectedVehicleRideAura() const
{
    WorldPacket data(SMSG_ON_CANCEL_EXPECTED_RIDE_VEHICLE_AURA, 0);
    SendDirectMessage(&data);
}

void Player::PetSpellInitialize()
{
    Pet* pet = GetPet();

    if (!pet)
        return;

    CharmInfo* charmInfo = pet->GetCharmInfo();

    WorldPacket data(SMSG_PET_SPELLS, 8+2+4+4+4*MAX_UNIT_ACTION_BAR_INDEX+1+1);
    data << uint64(pet->GetGUID());
    data << uint16(pet->GetCreatureTemplate()->family);         // creature family (required for pet talents)
    data << uint32(pet->GetDuration());
    data << uint8(pet->GetReactState());
    data << uint8(charmInfo->GetCommandState());
    data << uint16(0); // Flags, mostly unknown

    TC_LOG_DEBUG("entities.pet", "Player::PetspellInitialize: Creating spellgroups for summoned pet");

    // action bar loop
    charmInfo->BuildActionBar(&data);

    size_t spellsCountPos = data.wpos();

    // spells count
    uint8 addlist = 0;
    data << uint8(addlist);                                 // placeholder

    if (pet->IsPermanentPetFor(this))
    {
        // spells loop
        for (PetSpellMap::iterator itr = pet->m_spells.begin(); itr != pet->m_spells.end(); ++itr)
        {
            if (itr->second.state == PETSPELL_REMOVED)
                continue;

            data << uint32(MAKE_UNIT_ACTION_BUTTON(itr->first, itr->second.active));
            ++addlist;
        }
    }

    data.put<uint8>(spellsCountPos, addlist);

    //Cooldowns
    pet->GetSpellHistory()->WritePacket<Pet>(data);

    SendDirectMessage(&data);
}

void Player::PossessSpellInitialize()
{
    Unit* charm = GetCharmed();
    if (!charm)
        return;

    CharmInfo* charmInfo = charm->GetCharmInfo();

    if (!charmInfo)
    {
        TC_LOG_ERROR("entities.player", "Player::PossessSpellInitialize: charm (%s) has no charminfo!", charm->GetGUID().ToString().c_str());
        return;
    }

    WorldPacket data(SMSG_PET_SPELLS, 8+2+4+4+4*MAX_UNIT_ACTION_BAR_INDEX+1+1);
    data << uint64(charm->GetGUID());
    data << uint16(0);
    data << uint32(0);
    data << uint32(0);

    charmInfo->BuildActionBar(&data);

    data << uint8(0);                                       // spells count
    data << uint8(0);                                       // cooldowns count

    SendDirectMessage(&data);
}

void Player::VehicleSpellInitialize()
{
    Creature* vehicle = GetVehicleCreatureBase();
    if (!vehicle)
        return;

    uint8 cooldownCount = vehicle->GetSpellHistory()->GetCooldownsSizeForPacket();

    WorldPacket data(SMSG_PET_SPELLS, 8 + 2 + 4 + 4 + 4 * 10 + 1 + 1 + cooldownCount * (4 + 2 + 4 + 4));
    data << uint64(vehicle->GetGUID());                     // Guid
    data << uint16(0);                                      // Pet Family (0 for all vehicles)
    data << uint32(vehicle->IsSummon() ? vehicle->ToTempSummon()->GetTimer() : 0); // Duration
    // The following three segments are read by the client as one uint32
    data << uint8(vehicle->GetReactState());                // React State
    data << uint8(0);                                       // Command State
    data << uint16(0x800);                                  // DisableActions (set for all vehicles)

    for (uint32 i = 0; i < MAX_CREATURE_SPELLS; ++i)
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

    for (uint32 i = MAX_CREATURE_SPELLS; i < MAX_SPELL_CONTROL_BAR; ++i)
        data << uint32(0);

    data << uint8(0); // Auras?

    // Cooldowns
    vehicle->GetSpellHistory()->WritePacket<Pet>(data);
    SendDirectMessage(&data);
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
        //if (cinfo && cinfo->type == CREATURE_TYPE_DEMON && GetClass() == CLASS_WARLOCK)
        {
            for (uint32 i = 0; i < MAX_SPELL_CHARM; ++i)
                if (charmInfo->GetCharmSpell(i)->GetAction())
                    ++addlist;
        }
    }

    WorldPacket data(SMSG_PET_SPELLS, 8+2+4+4+4*MAX_UNIT_ACTION_BAR_INDEX+1+4*addlist+1);
    data << uint64(charm->GetGUID());
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

    data << uint8(0);                                       // cooldowns count

    SendDirectMessage(&data);
}

void Player::SendRemoveControlBar() const
{
    WorldPacket data(SMSG_PET_SPELLS, 8);
    data << uint64(0);
    SendDirectMessage(&data);
}

bool Player::IsAffectedBySpellmod(SpellInfo const* spellInfo, SpellModifier* mod, Spell* spell)
{
    if (!mod || !spellInfo)
        return false;

    // First time this aura applies a mod to us and is out of charges
    if (spell && mod->ownerAura->IsUsingCharges() && !mod->ownerAura->GetCharges() && !spell->m_appliedMods.count(mod->ownerAura))
        return false;

    // +duration to infinite duration spells making them limited
    if (mod->op == SPELLMOD_DURATION && spellInfo->GetDuration() == -1)
        return false;

    // mod crit to spells that can't crit
    if (mod->op == SPELLMOD_CRITICAL_CHANCE && !spellInfo->HasAttribute(SPELL_ATTR0_CU_CAN_CRIT))
        return false;

    return spellInfo->IsAffectedBySpellMod(mod);
}

template <class T>
void Player::ApplySpellMod(uint32 spellId, SpellModOp op, T& basevalue, Spell* spell /*= nullptr*/) const
{
    SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(spellId);
    if (!spellInfo)
        return;

    float totalmul = 1.0f;
    int32 totalflat = 0;

    auto calculateSpellMod = [&](SpellModifier* mod)
    {
        switch (mod->type)
        {
            case SPELLMOD_FLAT:
                totalflat += mod->value;
                break;
            case SPELLMOD_PCT:
                // special case (skip > 10sec spell casts for instant cast setting)
                if (op == SPELLMOD_CASTING_TIME && mod->value <= -100 && basevalue >= T(10000))
                    return;

                totalmul += CalculatePct(1.0f, mod->value);
                break;
        }

        Player::ApplyModToSpell(mod, spell);
    };

    // Drop charges for triggering spells instead of triggered ones
    if (m_spellModTakingSpell)
        spell = m_spellModTakingSpell;

    SpellModifier* chargedMod = nullptr;
    for (SpellModifier* mod : m_spellMods[op])
    {
        if (!IsAffectedBySpellmod(spellInfo, mod, spell))
            continue;

        if (mod->ownerAura->IsUsingCharges())
        {
            if (!chargedMod || (chargedMod->ownerAura->GetSpellInfo()->Priority < mod->ownerAura->GetSpellInfo()->Priority))
                chargedMod = mod;
            continue;
        }

        calculateSpellMod(mod);
    }

    if (chargedMod)
        calculateSpellMod(chargedMod);

    basevalue = T(float(basevalue + totalflat) * totalmul);
}

template TC_GAME_API void Player::ApplySpellMod(uint32 spellId, SpellModOp op, int32& basevalue, Spell* spell) const;
template TC_GAME_API void Player::ApplySpellMod(uint32 spellId, SpellModOp op, uint32& basevalue, Spell* spell) const;
template TC_GAME_API void Player::ApplySpellMod(uint32 spellId, SpellModOp op, float& basevalue, Spell* spell) const;

void Player::AddSpellMod(SpellModifier* mod, bool apply)
{
    TC_LOG_DEBUG("spells", "Player::AddSpellMod: Player '%s' (%s), SpellID: %d", GetName().c_str(), GetGUID().ToString().c_str(), mod->spellId);
    uint16 Opcode = (mod->type == SPELLMOD_FLAT) ? SMSG_SET_FLAT_SPELL_MODIFIER : SMSG_SET_PCT_SPELL_MODIFIER;

    flag96 modMask;
    for (uint8 i = 0; i < 3; ++i)
    {
        for (uint32 eff = 0; eff < 32; ++eff)
        {
            modMask[i] = uint32(1) << eff;
            if ((mod->mask & modMask))
            {
                int32 val = 0;
                for (SpellModifier* spellMod : m_spellMods[mod->op])
                {
                    if (spellMod->type == mod->type && (spellMod->mask & modMask))
                        val += spellMod->value;
                }
                val += apply ? mod->value : -(mod->value);
                WorldPacket data(Opcode, (1 + 1 + 4));
                data << uint8(eff + 32 * i);
                data << uint8(mod->op);
                data << int32(val);
                SendDirectMessage(&data);
            }
        }

        modMask[i] = 0;
    }

    if (apply)
        m_spellMods[mod->op].insert(mod);
    else
        m_spellMods[mod->op].erase(mod);
}

void Player::ApplyModToSpell(SpellModifier* mod, Spell* spell)
{
    if (!spell)
        return;

    // don't do anything with no charges
    if (mod->ownerAura->IsUsingCharges() && !mod->ownerAura->GetCharges())
        return;

    // register inside spell, proc system uses this to drop charges
    spell->m_appliedMods.insert(mod->ownerAura);
}

void Player::SetSpellModTakingSpell(Spell* spell, bool apply)
{
    if (apply && m_spellModTakingSpell != nullptr)
        return;

    if (!apply && (!m_spellModTakingSpell || m_spellModTakingSpell != spell))
        return;

    m_spellModTakingSpell = apply ? spell : nullptr;
}

// send Proficiency
void Player::SendProficiency(ItemClass itemClass, uint32 itemSubclassMask) const
{
    WorldPacket data(SMSG_SET_PROFICIENCY, 1 + 4);
    data << uint8(itemClass) << uint32(itemSubclassMask);
    SendDirectMessage(&data);
}

void Player::RemovePetitionsAndSigns(ObjectGuid guid, CharterTypes type)
{
    sPetitionMgr->RemoveSignaturesBySignerAndType(guid, type);
    sPetitionMgr->RemovePetitionsByOwnerAndType(guid, type);
}

void Player::LeaveAllArenaTeams(ObjectGuid guid)
{
    CharacterCacheEntry const* characterInfo = sCharacterCache->GetCharacterCacheByGuid(guid);
    if (!characterInfo)
        return;

    for (uint8 i = 0; i < MAX_ARENA_SLOT; ++i)
    {
        uint32 arenaTeamId = characterInfo->ArenaTeamId[i];
        if (arenaTeamId != 0)
        {
            ArenaTeam* arenaTeam = sArenaTeamMgr->GetArenaTeamById(arenaTeamId);
            if (arenaTeam)
                arenaTeam->DelMember(guid, true);
        }
    }
}

void Player::SetRestBonus(float rest_bonus_new)
{
    // Prevent resting on max level
    if (GetLevel() >= sWorld->getIntConfig(CONFIG_MAX_PLAYER_LEVEL))
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
        SetRestState(REST_STATE_RAF_LINKED);
    else
    {
        if (m_rest_bonus > 10)
            SetRestState(REST_STATE_RESTED);
        else if (m_rest_bonus <= 1)
            SetRestState(REST_STATE_NOT_RAF_LINKED);
    }

    //RestTickUpdate
    SetUInt32Value(PLAYER_REST_STATE_EXPERIENCE, uint32(m_rest_bonus));
}

bool Player::ActivateTaxiPathTo(std::vector<uint32> const& nodes, Creature* npc /*= nullptr*/, uint32 spellid /*= 0*/)
{
    if (nodes.size() < 2)
        return false;

    // not let cheating with start flight in time of logout process || while in combat || has type state: stunned || has type state: root
    if (GetSession()->isLogingOut() || IsInCombat() || HasUnitState(UNIT_STATE_STUNNED) || HasUnitState(UNIT_STATE_ROOT))
    {
        GetSession()->SendActivateTaxiReply(ERR_TAXIPLAYERBUSY);
        return false;
    }

    if (HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_REMOVE_CLIENT_CONTROL))
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
    uint32 mount_display_id = sObjectMgr->GetTaxiMountDisplayId(sourcenode, GetTeam(), npc == nullptr || (sourcenode == 315 && GetClass() == CLASS_DEATH_KNIGHT));

    // in spell case allow 0 model
    if ((mount_display_id == 0 && spellid == 0) || sourcepath == 0)
    {
        GetSession()->SendActivateTaxiReply(ERR_TAXIUNSPECIFIEDSERVERERROR);
        m_taxi.ClearTaxiDestinations();
        return false;
    }

    uint32 money = GetMoney();

    if (npc)
    {
        float discount = GetReputationPriceDiscount(npc);
        totalcost = uint32(ceil(totalcost * discount));
        firstcost = uint32(ceil(firstcost * discount));
        m_taxi.SetFlightMasterFactionTemplateId(npc->GetFaction());
    }
    else
        m_taxi.SetFlightMasterFactionTemplateId(0);

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
        ModifyMoney(-(int32)totalcost);
        UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_GOLD_SPENT_FOR_TRAVELLING, totalcost);
        TeleportTo(lastPathNode->map_id, lastPathNode->x, lastPathNode->y, lastPathNode->z, GetOrientation());
        return false;
    }
    else
    {
        ModifyMoney(-(int32)firstcost);
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
    nodes[0] = entry->from;
    nodes[1] = entry->to;

    return ActivateTaxiPathTo(nodes, nullptr, spellid);
}

void Player::FinishTaxiFlight()
{
    if (!IsInFlight())
        return;

    GetMotionMaster()->Remove(FLIGHT_MOTION_TYPE);
    m_taxi.ClearTaxiDestinations(); // not destinations, clear source node
}

void Player::CleanupAfterTaxiFlight()
{
    m_taxi.ClearTaxiDestinations(); // not destinations, clear source node
    Dismount();
    RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_REMOVE_CLIENT_CONTROL | UNIT_FLAG_TAXI_FLIGHT);
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
    float distNext = GetExactDistSq(nodeList[0]->LocX, nodeList[0]->LocY, nodeList[0]->LocZ);

    for (uint32 i = 1; i < nodeList.size(); ++i)
    {
        TaxiPathNodeEntry const* node = nodeList[i];
        TaxiPathNodeEntry const* prevNode = nodeList[i-1];

        // skip nodes at another map
        if (node->MapID != GetMapId())
            continue;

        distPrev = distNext;

        distNext = GetExactDistSq(node->LocX, node->LocY, node->LocZ);

        float distNodes =
            (node->LocX - prevNode->LocX)*(node->LocX - prevNode->LocX) +
            (node->LocY - prevNode->LocY)*(node->LocY - prevNode->LocY) +
            (node->LocZ - prevNode->LocZ)*(node->LocZ - prevNode->LocZ);

        if (distNext + distPrev < distNodes)
        {
            startNode = i;
            break;
        }
    }

    GetSession()->SendDoFlight(mountDisplayId, path, startNode);
}

void Player::SendTaxiNodeStatusMultiple()
{
    for (auto itr = m_clientGUIDs.begin(); itr != m_clientGUIDs.end(); ++itr)
    {
        if (!itr->IsCreature())
            continue;
        Creature* creature = ObjectAccessor::GetCreature(*this, *itr);
        if (!creature || creature->IsHostileTo(this))
            continue;
        if (!creature->HasFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_FLIGHTMASTER))
            continue;
        uint32 nearestNode = sObjectMgr->GetNearestTaxiNode(creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ(), creature->GetMapId(), GetTeam());
        if (!nearestNode)
            continue;
        WorldPacket data(SMSG_TAXINODE_STATUS, 9);
        data << *itr;
        data << uint8(m_taxi.IsTaximaskNodeKnown(nearestNode) ? 1 : 0);
        SendDirectMessage(&data);
    }
}

void Player::InitDataForForm(bool reapplyMods)
{
    ShapeshiftForm form = GetShapeshiftForm();

    SpellShapeshiftEntry const* ssEntry = sSpellShapeshiftStore.LookupEntry(form);
    if (ssEntry && ssEntry->attackSpeed)
    {
        SetAttackTime(BASE_ATTACK, ssEntry->attackSpeed);
        SetAttackTime(OFF_ATTACK, ssEntry->attackSpeed);
        SetAttackTime(RANGED_ATTACK, BASE_ATTACK_TIME);
    }
    else
        SetRegularAttackTime();

    UpdateDisplayPower();

    // update auras at form change, ignore this at mods reapply (.reset stats/etc) when form not change.
    if (!reapplyMods)
        UpdateEquipSpellsAtFormChange();

    UpdateAttackPowerAndDamage();
    UpdateAttackPowerAndDamage(true);
}

void Player::InitDisplayIds()
{
    PlayerInfo const* info = sObjectMgr->GetPlayerInfo(GetRace(), GetClass());
    if (!info)
    {
        TC_LOG_ERROR("entities.player", "Player::InitDisplayIds: Player '%s' (%s) has incorrect race/class pair. Can't init display ids.", GetName().c_str(), GetGUID().ToString().c_str());
        return;
    }

    uint8 gender = GetNativeGender();
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
    ItemPosCountVec vDest;
    uint16 uiDest = 0;
    InventoryResult msg = bStore ?
        CanStoreNewItem(bag, slot, vDest, item, pProto->BuyCount * count) :
        CanEquipNewItem(slot, uiDest, item, false);
    if (msg != EQUIP_ERR_OK)
    {
        SendEquipError(msg, nullptr, nullptr, item);
        return false;
    }

    ModifyMoney(-price);

    if (crItem->ExtendedCost)                            // case for new honor system
    {
        ItemExtendedCostEntry const* iece = sItemExtendedCostStore.LookupEntry(crItem->ExtendedCost);
        ASSERT(iece);
        if (iece->reqhonorpoints)
            ModifyHonorPoints(-int32(iece->reqhonorpoints * count));

        if (iece->reqarenapoints)
            ModifyArenaPoints(-int32(iece->reqarenapoints * count));

        for (uint8 i = 0; i < MAX_ITEM_EXTENDED_COST_REQUIREMENTS; ++i)
        {
            if (iece->reqitem[i])
                DestroyItemCount(iece->reqitem[i], (iece->reqitemcount[i] * count), true);
        }
    }

    Item* it = bStore ?
        StoreNewItem(vDest, item, true) :
        EquipNewItem(uiDest, item, true);
    if (it)
    {
        uint32 new_count = pVendor->UpdateVendorItemCurrentCount(crItem, pProto->BuyCount * count);

        WorldPacket data(SMSG_BUY_ITEM, (8+4+4+4));
        data << uint64(pVendor->GetGUID());
        data << uint32(vendorslot + 1);                   // numbered from 1 at client
        data << int32(crItem->maxcount > 0 ? new_count : 0xFFFFFFFF);
        data << uint32(count);
        SendDirectMessage(&data);
        SendNewItem(it, pProto->BuyCount * count, true, false, false);

        if (!bStore)
            AutoUnequipOffhandIfNeed();

        if (pProto->Flags & ITEM_FLAG_ITEM_PURCHASE_RECORD && crItem->ExtendedCost && pProto->GetMaxStackSize() == 1)
        {
            it->SetFlag(ITEM_FIELD_FLAGS, ITEM_FIELD_FLAG_REFUNDABLE);
            it->SetRefundRecipient(GetGUID().GetCounter());
            it->SetPaidMoney(price);
            it->SetPaidExtendedCost(crItem->ExtendedCost);
            it->SaveRefundDataToDB();
            AddRefundReference(it->GetGUID());
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

    if (!(pProto->AllowableClass & GetClassMask()) && pProto->Bonding == BIND_WHEN_PICKED_UP && !IsGameMaster())
    {
        SendBuyError(BUY_ERR_CANT_FIND_ITEM, nullptr, item, 0);
        return false;
    }

    if (!IsGameMaster() && ((pProto->Flags2 & ITEM_FLAG2_FACTION_HORDE && GetTeam() == ALLIANCE) || (pProto->Flags2 == ITEM_FLAG2_FACTION_ALLIANCE && GetTeam() == HORDE)))
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
        if (creature->GetVendorItemCurrentCount(crItem) < pProto->BuyCount * count)
        {
            SendBuyError(BUY_ERR_ITEM_ALREADY_SOLD, creature, item, 0);
            return false;
        }
    }

    if (pProto->RequiredReputationFaction && (uint32(GetReputationRank(pProto->RequiredReputationFaction)) < pProto->RequiredReputationRank))
    {
        SendBuyError(BUY_ERR_REPUTATION_REQUIRE, creature, item, 0);
        return false;
    }

    if (crItem->ExtendedCost)
    {
        ItemExtendedCostEntry const* iece = sItemExtendedCostStore.LookupEntry(crItem->ExtendedCost);
        if (!iece)
        {
            TC_LOG_ERROR("entities.player", "Player::BuyItemFromVendorSlot: Item %u has wrong ExtendedCost field value %u", pProto->ItemId, crItem->ExtendedCost);
            return false;
        }

        // honor points price
        if (GetHonorPoints() < (iece->reqhonorpoints * count))
        {
            SendEquipError(EQUIP_ERR_NOT_ENOUGH_HONOR_POINTS, nullptr, nullptr);
            return false;
        }

        // arena points price
        if (GetArenaPoints() < (iece->reqarenapoints * count))
        {
            SendEquipError(EQUIP_ERR_NOT_ENOUGH_ARENA_POINTS, nullptr, nullptr);
            return false;
        }

        // item base price
        for (uint8 i = 0; i < MAX_ITEM_EXTENDED_COST_REQUIREMENTS; ++i)
        {
            if (iece->reqitem[i] && !HasItemCount(iece->reqitem[i], (iece->reqitemcount[i] * count)))
            {
                SendEquipError(EQUIP_ERR_VENDOR_MISSING_TURNINS, nullptr, nullptr);
                return false;
            }
        }

        // check for personal arena rating requirement
        if (GetMaxPersonalArenaRatingRequirement(iece->reqarenaslot) < iece->reqpersonalarenarating)
        {
            // probably not the proper equip err
            SendEquipError(EQUIP_ERR_CANT_EQUIP_RANK, nullptr, nullptr);
            return false;
        }
    }

    uint32 price = 0;
    if (crItem->IsGoldRequired(pProto) && pProto->BuyPrice > 0) //Assume price cannot be negative (do not know why it is int32)
    {
        uint32 maxCount = MAX_MONEY_AMOUNT / pProto->BuyPrice;
        if ((uint32)count > maxCount)
        {
            TC_LOG_ERROR("entities.player.cheat", "Player::BuyItemFromVendorSlot: Player '%s' (%s) tried to buy item (ItemID: %u, Count: %u), causing overflow",
                GetName().c_str(), GetGUID().ToString().c_str(), pProto->ItemId, (uint32)count);
            count = (uint8)maxCount;
        }
        price = pProto->BuyPrice * count; //it should not exceed MAX_MONEY_AMOUNT

        // reputation discount
        price = uint32(floor(price * GetReputationPriceDiscount(creature)));

        if (!HasEnoughMoney(price))
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
        if (pProto->BuyCount * count != 1)
        {
            SendEquipError(EQUIP_ERR_ITEM_CANT_BE_EQUIPPED, nullptr, nullptr);
            return false;
        }
        if (!_StoreOrEquipNewItem(vendorslot, item, count, bag, slot, price, pProto, creature, crItem, false))
            return false;
    }
    else
    {
        SendEquipError(EQUIP_ERR_ITEM_DOESNT_GO_TO_SLOT, nullptr, nullptr);
        return false;
    }

    return crItem->maxcount != 0;
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
        if (m_HomebindTimer)                                 // instance valid, but timer not reset
        {
            // hide reminder
            WorldPacket data(SMSG_RAID_GROUP_ONLY, 4+4);
            data << uint32(0);
            data << uint32(0);
            SendDirectMessage(&data);
        }
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
        WorldPacket data(SMSG_RAID_GROUP_ONLY, 4+4);
        data << uint32(m_HomebindTimer);
        data << uint32(1);
        SendDirectMessage(&data);
        TC_LOG_DEBUG("maps", "Player::UpdateHomebindTime: Player '%s' (%s) will be teleported to homebind in 60 seconds",
            GetName().c_str(), GetGUID().ToString().c_str());
    }
}

void Player::InitPvP()
{
    if (HasFlag(PLAYER_FLAGS, PLAYER_FLAGS_IN_PVP))
        UpdatePvP(true, true);
    else if (HasFlag(PLAYER_FLAGS, PLAYER_FLAGS_PVP_TIMER))
    {
        UpdatePvP(true, true);
        if (!pvpInfo.IsHostile)
            pvpInfo.EndTimer = GameTime::GetGameTime() + 300;
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
            SetByteFlag(UNIT_FIELD_BYTES_2, UNIT_BYTES_2_OFFSET_PVP_FLAG, UNIT_BYTE2_FLAG_FFA_PVP);
            for (ControlList::iterator itr = m_Controlled.begin(); itr != m_Controlled.end(); ++itr)
                (*itr)->SetByteValue(UNIT_FIELD_BYTES_2, UNIT_BYTES_2_OFFSET_PVP_FLAG, UNIT_BYTE2_FLAG_FFA_PVP);
        }
    }
    else if (IsFFAPvP())
    {
        RemoveByteFlag(UNIT_FIELD_BYTES_2, UNIT_BYTES_2_OFFSET_PVP_FLAG, UNIT_BYTE2_FLAG_FFA_PVP);
        for (ControlList::iterator itr = m_Controlled.begin(); itr != m_Controlled.end(); ++itr)
            (*itr)->RemoveByteFlag(UNIT_FIELD_BYTES_2, UNIT_BYTES_2_OFFSET_PVP_FLAG, UNIT_BYTE2_FLAG_FFA_PVP);
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
            pvpInfo.EndTimer = GameTime::GetGameTime() + 300;                  // start toggle-off
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
        pvpInfo.EndTimer = GameTime::GetGameTime() + 300;
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
        // spell/item pair let set proper cooldown (except non-existing charged spell cooldown spellmods for potions)
        if (ItemTemplate const* proto = sObjectMgr->GetItemTemplate(m_lastPotionId))
            for (uint8 idx = 0; idx < MAX_ITEM_PROTO_SPELLS; ++idx)
                if (proto->Spells[idx].SpellId && proto->Spells[idx].SpellTrigger == ITEM_SPELLTRIGGER_ON_USE)
                    if (SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(proto->Spells[idx].SpellId))
                        GetSpellHistory()->SendCooldownEvent(spellInfo, m_lastPotionId);
    }
    // from spell cases (m_lastPotionId set in Spell::SendSpellCooldown)
    else
    {
        if (spell->IsIgnoringCooldowns())
            return;
        else
            GetSpellHistory()->SendCooldownEvent(spell->m_spellInfo, m_lastPotionId, spell);
    }

    m_lastPotionId = 0;
}

void Player::SetResurrectRequestData(WorldObject const* caster, uint32 health, uint32 mana, uint32 appliedAura)
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
        if (pItem2 && !pItem2->IsBroken() && pItem2->GetTemplate()->Socket[0].Color)
        {
            for (uint32 enchant_slot = SOCK_ENCHANTMENT_SLOT; enchant_slot < SOCK_ENCHANTMENT_SLOT+3; ++enchant_slot)
            {
                uint32 enchant_id = pItem2->GetEnchantmentId(EnchantmentSlot(enchant_slot));
                if (!enchant_id)
                    continue;

                SpellItemEnchantmentEntry const* enchantEntry = sSpellItemEnchantmentStore.LookupEntry(enchant_id);
                if (!enchantEntry)
                    continue;

                uint32 gemid = enchantEntry->GemID;
                if (!gemid)
                    continue;

                ItemTemplate const* gemProto = sObjectMgr->GetItemTemplate(gemid);
                if (!gemProto)
                    continue;

                GemPropertiesEntry const* gemProperty = sGemPropertiesStore.LookupEntry(gemProto->GemProperties);
                if (!gemProperty)
                    continue;

                uint8 GemColor = gemProperty->color;

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
        if (!Condition->Color[i])
            continue;

        uint32 _cur_gem = curcount[Condition->Color[i] - 1];

        // if have <CompareColor> use them as count, else use <value> from Condition
        uint32 _cmp_gem = Condition->CompareColor[i] ? curcount[Condition->CompareColor[i] - 1]: Condition->Value[i];

        switch (Condition->Comparator[i])
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

        if (!pItem || !pItem->GetTemplate()->Socket[0].Color)
            continue;

        for (uint32 enchant_slot = SOCK_ENCHANTMENT_SLOT; enchant_slot < SOCK_ENCHANTMENT_SLOT+3; ++enchant_slot)
        {
            uint32 enchant_id = pItem->GetEnchantmentId(EnchantmentSlot(enchant_slot));
            if (!enchant_id)
                continue;

            SpellItemEnchantmentEntry const* enchantEntry = sSpellItemEnchantmentStore.LookupEntry(enchant_id);
            if (!enchantEntry)
                continue;

            uint32 condition = enchantEntry->EnchantmentCondition;
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

        if (!pItem || !pItem->GetTemplate()->Socket[0].Color)   //if item has no sockets or no item is equipped go to next item
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
            uint32 condition = enchantEntry->EnchantmentCondition;
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
            if (WorldSafeLocsEntry const* entry = sObjectMgr->GetClosestGraveyard(GetPositionX(), GetPositionY(), GetPositionZ(), GetMapId(), GetTeam()))
                m_bgData.joinPos = WorldLocation(entry->map_id, entry->x, entry->y, entry->z, 0.0f);
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
    SetArenaFaction(uint8(team == ALLIANCE ? 1 : 0));
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

        // track if player leaves the BG while inside it
        if (bg->isBattleground() && sWorld->getBoolConfig(CONFIG_BATTLEGROUND_TRACK_DESERTERS) &&
                (bg->GetStatus() == STATUS_IN_PROGRESS || bg->GetStatus() == STATUS_WAIT_JOIN))
        {
            PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_DESERTER_TRACK);
            stmt->setUInt32(0, GetGUID().GetCounter());
            stmt->setUInt8(1, BG_DESERTION_TYPE_LEAVE_BG);
            CharacterDatabase.Execute(stmt);
        }
    }
}

bool Player::CanJoinToBattleground(Battleground const* bg) const
{
    uint32 perm = rbac::RBAC_PERM_JOIN_NORMAL_BG;
    if (bg->isArena())
        perm = rbac::RBAC_PERM_JOIN_ARENAS;
    else if (bg->IsRandom())
        perm = rbac::RBAC_PERM_JOIN_RANDOM_BG;

    return GetSession()->HasPermission(perm);
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
    Battleground* bg = GetBattleground();
    // Battleground also must be in progress!
    if (!bg || bg != reporter->GetBattleground() || GetTeam() != reporter->GetTeam() || bg->GetStatus() != STATUS_IN_PROGRESS)
        return;

    // check if player has 'Idle' or 'Inactive' debuff
    if (m_bgData.bgAfkReporter.find(reporter->GetGUID().GetCounter()) == m_bgData.bgAfkReporter.end() && !HasAura(43680) && !HasAura(43681) && reporter->CanReportAfkDueToLimit())
    {
        m_bgData.bgAfkReporter.insert(reporter->GetGUID().GetCounter());
        // by default 3 players have to complain to apply debuff
        if (m_bgData.bgAfkReporter.size() >= sWorld->getIntConfig(CONFIG_BATTLEGROUND_REPORT_AFK))
        {
            // cast 'Idle' spell
            CastSpell(this, 43680, true);
            m_bgData.bgAfkReporter.clear();
        }
    }
}

WorldLocation Player::GetStartPosition() const
{
    PlayerInfo const* info = sObjectMgr->GetPlayerInfo(GetRace(), GetClass());
    ASSERT(info);
    uint32 mapId = info->mapId;
    if (GetClass() == CLASS_DEATH_KNIGHT && HasSpell(50977))
        mapId = 0;
    return WorldLocation(mapId, info->positionX, info->positionY, info->positionZ, 0);
}

bool Player::HaveAtClient(Object const* u) const
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
    if (GetUnitBeingMoved() == obj)
        return true;

    if (ObjectGuid guid = GetGuidValue(PLAYER_FARSIGHT))
        if (obj->GetGUID() == guid)
            return true;

    return false;
}

bool Player::IsAlwaysDetectableFor(WorldObject const* seer) const
{
    if (Unit::IsAlwaysDetectableFor(seer))
        return true;

    if (duel && duel->State != DUEL_STATE_CHALLENGED && duel->Opponent == seer)
        return false;

    if (Player const* seerPlayer = seer->ToPlayer())
        if (IsGroupVisibleFor(seerPlayer))
            return true;

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
    if ((target->GetGOInfo()->type != GAMEOBJECT_TYPE_TRANSPORT))
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
                TC_LOG_DEBUG("maps", "Object %u (Type: %u) out of range for player %u. Distance = %f", target->GetGUID().GetCounter(), target->GetTypeId(), GetGUID().GetCounter(), GetDistance(target));
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
                TC_LOG_DEBUG("maps", "Object %u (Type: %u) is visible now for player %u. Distance = %f", target->GetGUID().GetCounter(), target->GetTypeId(), GetGUID().GetCounter(), GetDistance(target));
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

    UpdateData udata;
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
    SendDirectMessage(&packet);
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
                TC_LOG_DEBUG("maps", "Object %u (Type: %u, Entry: %u) is out of range for player %u. Distance = %f", target->GetGUID().GetCounter(), target->GetTypeId(), target->GetEntry(), GetGUID().GetCounter(), GetDistance(target));
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
                TC_LOG_DEBUG("maps", "Object %u (Type: %u, Entry: %u) is visible now for player %u. Distance = %f", target->GetGUID().GetCounter(), target->GetTypeId(), target->GetEntry(), GetGUID().GetCounter(), GetDistance(target));
            #endif
        }
    }
}

template void Player::UpdateVisibilityOf(Player*        target, UpdateData& data, std::set<Unit*>& visibleNow);
template void Player::UpdateVisibilityOf(Creature*      target, UpdateData& data, std::set<Unit*>& visibleNow);
template void Player::UpdateVisibilityOf(Corpse*        target, UpdateData& data, std::set<Unit*>& visibleNow);
template void Player::UpdateVisibilityOf(GameObject*    target, UpdateData& data, std::set<Unit*>& visibleNow);
template void Player::UpdateVisibilityOf(DynamicObject* target, UpdateData& data, std::set<Unit*>& visibleNow);

void Player::UpdateObjectVisibility(bool forced)
{
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
    Cell::VisitAllObjects(m_seer, notifier, GetSightRange());
    notifier.SendToSelf();   // send gathered data
}

void Player::SetPhaseMask(uint32 newPhaseMask, bool update)
{
    if (newPhaseMask == GetPhaseMask())
        return;

    Unit::SetPhaseMask(newPhaseMask, false);

    if (Unit* vehicle = GetVehicleRoot())
        vehicle->SetPhaseMask(newPhaseMask, update);

    if (update)
        UpdateObjectVisibility();
}

void Player::InitPrimaryProfessions()
{
    SetFreePrimaryProfessions(sWorld->getIntConfig(CONFIG_MAX_PRIMARY_TRADE_SKILL));
}

bool Player::ModifyMoney(int32 amount, bool sendError /*= true*/)
{
    if (!amount)
        return true;

    sScriptMgr->OnPlayerMoneyChanged(this, amount);

    if (amount < 0)
        SetMoney (GetMoney() > uint32(-amount) ? GetMoney() + amount : 0);
    else
    {
        if (GetMoney() < MAX_MONEY_AMOUNT - static_cast<uint32>(amount))
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

void Player::SetMoney(uint32 value)
{
    SetUInt32Value(PLAYER_FIELD_COINAGE, value);
    MoneyChanged(value);
    UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_GOLD_VALUE_OWNED);
}

bool Player::IsQuestRewarded(uint32 quest_id) const
{
    return m_RewardedQuests.find(quest_id) != m_RewardedQuests.end();
}

Unit* Player::GetSelectedUnit() const
{
    if (ObjectGuid selectionGUID = GetTarget())
        return ObjectAccessor::GetUnit(*this, selectionGUID);
    return nullptr;
}

Player* Player::GetSelectedPlayer() const
{
    if (ObjectGuid selectionGUID = GetTarget())
        return ObjectAccessor::FindConnectedPlayer(selectionGUID);
    return nullptr;
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

    // guild bank list wtf?

    // Homebind
    WorldPacket data(SMSG_BINDPOINTUPDATE, 5*4);
    data << m_homebindX << m_homebindY << m_homebindZ;
    data << (uint32) m_homebindMapId;
    data << (uint32) m_homebindAreaId;
    SendDirectMessage(&data);

    // SMSG_SET_PROFICIENCY
    // SMSG_SET_PCT_SPELL_MODIFIER
    // SMSG_SET_FLAT_SPELL_MODIFIER
    // SMSG_UPDATE_AURA_DURATION

    SendTalentsInfoData(false);

    // SMSG_INSTANCE_DIFFICULTY
    data.Initialize(SMSG_INSTANCE_DIFFICULTY, 4+4);
    data << uint32(GetMap()->GetDifficulty());
    data << uint32(GetMap()->GetEntry()->IsDynamicDifficultyMap() && GetMap()->IsHeroic()); // Raid dynamic difficulty
    SendDirectMessage(&data);

    SendInitialSpells();
    SendUnlearnSpells();

    SendInitialActionButtons();
    m_reputationMgr->SendInitialReputations();
    m_achievementMgr->SendAllAchievementData();

    SendEquipmentSetList();

    data.Initialize(SMSG_LOGIN_SETTIMESPEED, 4 + 4 + 4);
    data.AppendPackedTime(GameTime::GetGameTime());
    data << float(0.01666667f);                             // game speed
    data << uint32(0);                                      // added in 3.1.2
    SendDirectMessage(&data);

    GetReputationMgr().SendForceReactions();                // SMSG_SET_FORCED_REACTIONS

    // SMSG_TALENTS_INFO x 2 for pet (unspent points and talents in separate packets...)
    // SMSG_PET_GUIDS
    // SMSG_UPDATE_WORLD_STATE
    // SMSG_POWER_UPDATE

    ResyncRunes();

    SetMovedUnit(this);
}

void Player::SendInitialPacketsAfterAddToMap()
{
    UpdateVisibilityForPlayer();

    // update zone
    uint32 newzone, newarea;
    GetZoneAndAreaId(newzone, newarea);
    UpdateZone(newzone, newarea);                            // also call SendInitWorldStates();

    GetSession()->ResetTimeSync();
    GetSession()->SendTimeSync();

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
        SetMovement(MOVE_ROOT);

    WorldPacket setCompoundState(SMSG_MULTIPLE_MOVES, 100);
    setCompoundState << uint32(0); // size placeholder

    // manual send package (have code in HandleEffect(this, AURA_EFFECT_HANDLE_SEND_FOR_CLIENT, true); that must not be re-applied.
    if (HasAuraType(SPELL_AURA_MOD_ROOT))
    {
        setCompoundState << uint8(2 + GetPackGUID().size() + 4);
        setCompoundState << uint16(SMSG_FORCE_MOVE_ROOT);
        setCompoundState << GetPackGUID();
        setCompoundState << uint32(0);          //! movement counter
    }

    if (HasAuraType(SPELL_AURA_FEATHER_FALL))
    {
        setCompoundState << uint8(2 + GetPackGUID().size() + 4);
        setCompoundState << uint16(SMSG_MOVE_FEATHER_FALL);
        setCompoundState << GetPackGUID();
        setCompoundState << uint32(0);          //! movement counter0
    }

    if (HasAuraType(SPELL_AURA_WATER_WALK))
    {
        setCompoundState << uint8(2 + GetPackGUID().size() + 4);
        setCompoundState << uint16(SMSG_MOVE_WATER_WALK);
        setCompoundState << GetPackGUID();
        setCompoundState << uint32(0);          //! movement counter0
    }

    if (HasAuraType(SPELL_AURA_HOVER))
    {
        setCompoundState << uint8(2 + GetPackGUID().size() + 4);
        setCompoundState << uint16(SMSG_MOVE_SET_HOVER);
        setCompoundState << GetPackGUID();
        setCompoundState << uint32(0);          //! movement counter0
    }

    if (setCompoundState.size() > 4)
    {
        setCompoundState.put<uint32>(0, setCompoundState.size() - 4);
        SendDirectMessage(&setCompoundState);
    }

    SendAurasForTarget(this);
    SendEnchantmentDurations();                             // must be after add to map
    SendItemDurations();                                    // must be after add to map
    SendQuestGiverStatusMultiple();
    SendTaxiNodeStatusMultiple();

    // raid downscaling - send difficulty to player
    if (GetMap()->IsRaid())
    {
        if (GetMap()->GetDifficulty() != GetRaidDifficulty())
        {
            StoreRaidMapDifficulty();
            SendRaidDifficulty(GetGroup() != nullptr, GetStoredRaidDifficulty());
        }
    }
    else if (GetRaidDifficulty() != GetStoredRaidDifficulty())
        SendRaidDifficulty(GetGroup() != nullptr);

    if (GetPlayerSharingQuest())
    {
        if (Quest const* quest = sObjectMgr->GetQuestTemplate(GetSharedQuestID()))
            PlayerTalkClass->SendQuestGiverQuestDetails(quest, GetGUID(), true);
        else
            ClearQuestSharingInfo();
    }
}

void Player::SendUpdateToOutOfRangeGroupMembers()
{
    if (m_groupUpdateMask == GROUP_UPDATE_FLAG_NONE)
        return;
    if (Group* group = GetGroup())
        group->UpdatePlayerOutOfRange(this);

    m_groupUpdateMask = GROUP_UPDATE_FLAG_NONE;
    m_auraRaidUpdateMask = 0;
    if (Pet* pet = GetPet())
        pet->ResetAuraUpdateMaskForRaid();
}

void Player::SendTransferAborted(uint32 mapid, TransferAbortReason reason, uint8 arg) const
{
    WorldPacket data(SMSG_TRANSFER_ABORTED, 4+2);
    data << uint32(mapid);
    data << uint8(reason);                                 // transfer abort reason
    switch (reason)
    {
        case TRANSFER_ABORT_INSUF_EXPAN_LVL:
        case TRANSFER_ABORT_DIFFICULTY:
        case TRANSFER_ABORT_UNIQUE_MESSAGE:
            // these are the ONLY cases that have an extra argument in the packet!!!
            data << uint8(arg);
            break;
        default:
            break;
    }
    SendDirectMessage(&data);
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

    WorldPacket data(SMSG_RAID_INSTANCE_MESSAGE, 4+4+4+4);
    data << uint32(type);
    data << uint32(mapid);
    data << uint32(difficulty);                             // difficulty
    data << uint32(time);
    if (type == RAID_INSTANCE_WELCOME)
    {
        data << uint8(0);                                   // is locked
        data << uint8(0);                                   // is extended, ignored if prev field is 0
    }
    SendDirectMessage(&data);
}

void Player::ApplyEquipCooldown(Item* pItem)
{
    if (pItem->GetTemplate()->Flags & ITEM_FLAG_NO_EQUIP_COOLDOWN)
        return;

    std::chrono::steady_clock::time_point now = GameTime::GetGameTimeSteadyPoint();
    for (uint8 i = 0; i < MAX_ITEM_PROTO_SPELLS; ++i)
    {
        _Spell const& spellData = pItem->GetTemplate()->Spells[i];

        // no spell
        if (spellData.SpellId <= 0)
            continue;

        // apply proc cooldown to equip auras if we have any
        if (spellData.SpellTrigger == ITEM_SPELLTRIGGER_ON_EQUIP)
        {
            SpellProcEntry const* procEntry = sSpellMgr->GetSpellProcEntry(spellData.SpellId);
            if (!procEntry)
                continue;

            if (Aura* itemAura = GetAura(spellData.SpellId, GetGUID(), pItem->GetGUID()))
                itemAura->AddProcCooldown(now + procEntry->Cooldown);
            continue;
        }

        // wrong triggering type (note: ITEM_SPELLTRIGGER_ON_NO_DELAY_USE not have cooldown)
        if (spellData.SpellTrigger != ITEM_SPELLTRIGGER_ON_USE)
            continue;

        // Don't replace longer cooldowns by equip cooldown if we have any.
        if (GetSpellHistory()->GetRemainingCooldown(sSpellMgr->AssertSpellInfo(spellData.SpellId)) > 30 * IN_MILLISECONDS)
            continue;

        GetSpellHistory()->AddCooldown(spellData.SpellId, pItem->GetEntry(), std::chrono::seconds(30));

        WorldPacket data(SMSG_ITEM_COOLDOWN, 8 + 4);
        data << uint64(pItem->GetGUID());
        data << uint32(spellData.SpellId);
        SendDirectMessage(&data);
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
        ChrClassesEntry const* clsEntry = sChrClassesStore.LookupEntry(GetClass());
        if (!clsEntry)
            return;
        family = clsEntry->spellfamily;

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

            // skip spells with first rank learned as talent (and all talents then also)
            uint32 firstRank = spellInfo->GetFirstRankSpell()->Id;
            if (GetTalentSpellCost(firstRank) > 0)
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
    PlayerInfo const* info = sObjectMgr->GetPlayerInfo(GetRace(), GetClass());
    ASSERT(info);
    for (PlayerCreateInfoSpells::const_iterator itr = info->customSpells.begin(); itr != info->customSpells.end(); ++itr)
    {
        uint32 tspell = *itr;
        TC_LOG_DEBUG("entities.player.loading", "Player::LearnCustomSpells: Player '%s' (%s, Class: %u Race: %u): Adding initial spell (SpellID: %u)",
            GetName().c_str(), GetGUID().ToString().c_str(), uint32(GetClass()), uint32(GetRace()), tspell);
        if (!IsInWorld())                                    // will send in INITIAL_SPELLS in list anyway at map add
            AddSpell(tspell, true, true, true, false);
        else                                                // but send in normal spell in game learn case
            LearnSpell(tspell, true);
    }
}

void Player::LearnDefaultSkills()
{
    // learn default race/class skills
    PlayerInfo const* info = sObjectMgr->GetPlayerInfo(GetRace(), GetClass());
    ASSERT(info);
    for (PlayerCreateInfoSkills::const_iterator itr = info->skills.begin(); itr != info->skills.end(); ++itr)
    {
        uint32 skillId = itr->SkillId;
        if (HasSkill(skillId))
            continue;

        LearnDefaultSkill(skillId, itr->Rank);
    }
}

void Player::LearnDefaultSkill(uint32 skillId, uint16 rank)
{
    SkillRaceClassInfoEntry const* rcInfo = GetSkillRaceClassInfo(skillId, GetRace(), GetClass());
    if (!rcInfo)
        return;

    TC_LOG_DEBUG("entities.player.loading", "PLAYER (Class: %u Race: %u): Adding initial skill, id = %u", uint32(GetClass()), uint32(GetRace()), skillId);
    switch (GetSkillRangeType(rcInfo))
    {
        case SKILL_RANGE_LANGUAGE:
            SetSkill(skillId, 0, 300, 300);
            break;
        case SKILL_RANGE_LEVEL:
        {
            uint16 skillValue = 1;
            uint16 maxValue = GetMaxSkillValueForLevel();
            if (sWorld->getBoolConfig(CONFIG_ALWAYS_MAXSKILL) && !IsProfessionOrRidingSkill(skillId))
                skillValue = maxValue;
            else if (rcInfo->Flags & SKILL_FLAG_ALWAYS_MAX_VALUE)
                skillValue = maxValue;
            else if (GetClass() == CLASS_DEATH_KNIGHT)
                skillValue = std::min(std::max<uint16>({ 1, uint16((GetLevel() - 1) * 5) }), maxValue);
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
            if (!rank)
                break;

            SkillTiersEntry const* tier = sSkillTiersStore.LookupEntry(rcInfo->SkillTier);
            uint16 maxValue = tier->MaxSkill[std::max<int32>(rank - 1, 0)];
            uint16 skillValue = 1;
            if (rcInfo->Flags & SKILL_FLAG_ALWAYS_MAX_VALUE)
                skillValue = maxValue;
            else if (GetClass() == CLASS_DEATH_KNIGHT)
                skillValue = std::min(std::max<uint16>({ uint16(1), uint16((GetLevel() - 1) * 5) }), maxValue);

            SetSkill(skillId, rank, skillValue, maxValue);
            break;
        }
        default:
            break;
    }
}

void Player::LearnQuestRewardedSpells(Quest const* quest)
{
    int32 spell_id = quest->GetRewSpellCast();
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
    for (uint8 i = 0; i < MAX_SPELL_EFFECTS; ++i)
    {
        if (spellInfo->Effects[i].Effect == SPELL_EFFECT_LEARN_SPELL && !HasSpell(spellInfo->Effects[i].TriggerSpell))
        {
            found = true;
            break;
        }
    }

    // skip quests with not teaching spell or already known spell
    if (!found)
        return;

    uint32 learned_0 = spellInfo->Effects[0].TriggerSpell;
    if (!HasSpell(learned_0))
    {
        SpellInfo const* learnedInfo = sSpellMgr->GetSpellInfo(learned_0);
        if (!learnedInfo)
            return;

       // profession specialization can be re-learned from npc
       if (learnedInfo->Effects[0].Effect == SPELL_EFFECT_TRADE_SKILL && learnedInfo->Effects[1].Effect == 0 && !learnedInfo->SpellLevel)
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
    uint32 raceMask  = GetRaceMask();
    uint32 classMask = GetClassMask();
    for (uint32 j = 0; j < sSkillLineAbilityStore.GetNumRows(); ++j)
    {
        SkillLineAbilityEntry const* ability = sSkillLineAbilityStore.LookupEntry(j);
        if (!ability || ability->skillId != skillId)
            continue;

        if (!sSpellMgr->GetSpellInfo(ability->spellId))
            continue;

        if (ability->AutolearnType != SKILL_LINE_ABILITY_LEARNED_ON_SKILL_VALUE && ability->AutolearnType != SKILL_LINE_ABILITY_LEARNED_ON_SKILL_LEARN)
            continue;

        // Check race if set
        if (ability->racemask && !(ability->racemask & raceMask))
            continue;

        // Check class if set
        if (ability->classmask && !(ability->classmask & classMask))
            continue;

        // need unlearn spell
        if (skillValue < ability->req_skill_value && ability->AutolearnType == SKILL_LINE_ABILITY_LEARNED_ON_SKILL_VALUE)
            RemoveSpell(ability->spellId);
        // need learn
        else
        {
            // used to avoid double Seal of Righteousness on paladins, it's the only player spell which has both spell and forward spell in auto learn
            if (ability->AutolearnType == SKILL_LINE_ABILITY_LEARNED_ON_SKILL_LEARN && ability->forward_spellid)
            {
                bool skipCurrent = false;
                auto bounds = sSpellMgr->GetSkillLineAbilityMapBounds(ability->forward_spellid);
                for (auto itr = bounds.first; itr != bounds.second; ++itr)
                {
                    if (itr->second->AutolearnType == SKILL_LINE_ABILITY_LEARNED_ON_SKILL_LEARN && skillValue >= itr->second->req_skill_value)
                    {
                        skipCurrent = true;
                        break;
                    }
                }

                if (skipCurrent)
                    continue;
            }

            if (!IsInWorld())
                AddSpell(ability->spellId, true, true, true, false, false, ability->skillId);
            else
                LearnSpell(ability->spellId, true, ability->skillId);
        }
    }
}

void Player::SendAurasForTarget(Unit* target) const
{
    if (!target || target->GetVisibleAuras()->empty())                  // speedup things
        return;

    WorldPacket data(SMSG_AURA_UPDATE_ALL);
    data << target->GetPackGUID();

    Unit::VisibleAuraMap const* visibleAuras = target->GetVisibleAuras();
    for (Unit::VisibleAuraMap::const_iterator itr = visibleAuras->begin(); itr != visibleAuras->end(); ++itr)
    {
        AuraApplication * auraApp = itr->second;
        auraApp->BuildUpdatePacket(data, false);
    }

    SendDirectMessage(&data);
}

void Player::SetDailyQuestStatus(uint32 quest_id)
{
    if (Quest const* qQuest = sObjectMgr->GetQuestTemplate(quest_id))
    {
        if (!qQuest->IsDFQuest())
        {
            for (uint32 quest_daily_idx = 0; quest_daily_idx < PLAYER_MAX_DAILY_QUESTS; ++quest_daily_idx)
            {
                if (!GetUInt32Value(PLAYER_FIELD_DAILY_QUESTS_1+quest_daily_idx))
                {
                    SetUInt32Value(PLAYER_FIELD_DAILY_QUESTS_1+quest_daily_idx, quest_id);
                    m_lastDailyQuestTime = GameTime::GetGameTime();              // last daily quest time
                    m_DailyQuestChanged = true;
                    break;
                }
            }
        } else
        {
            m_DFQuests.insert(quest_id);
            m_lastDailyQuestTime = GameTime::GetGameTime();
            m_DailyQuestChanged = true;
        }
    }
}

bool Player::IsDailyQuestDone(uint32 quest_id)
{
    bool found = false;
    if (sObjectMgr->GetQuestTemplate(quest_id))
    {
        for (uint32 quest_daily_idx = 0; quest_daily_idx < PLAYER_MAX_DAILY_QUESTS; ++quest_daily_idx)
        {
            if (GetUInt32Value(PLAYER_FIELD_DAILY_QUESTS_1 + quest_daily_idx) == quest_id)
            {
                found = true;
                break;
            }
        }
    }

    return found;
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

    m_seasonalquests[quest->GetEventIdForQuest()].insert(quest_id);
    m_SeasonalQuestChanged = true;
}

void Player::SetMonthlyQuestStatus(uint32 quest_id)
{
    m_monthlyquests.insert(quest_id);
    m_MonthlyQuestChanged = true;
}

void Player::ResetDailyQuestStatus()
{
    for (uint32 quest_daily_idx = 0; quest_daily_idx < PLAYER_MAX_DAILY_QUESTS; ++quest_daily_idx)
        SetUInt32Value(PLAYER_FIELD_DAILY_QUESTS_1+quest_daily_idx, 0);

    m_DFQuests.clear(); // Dungeon Finder Quests.

    // DB data deleted in caller
    m_DailyQuestChanged = false;
    m_lastDailyQuestTime = 0;
}

void Player::ResetWeeklyQuestStatus()
{
    if (m_weeklyquests.empty())
        return;

    m_weeklyquests.clear();
    // DB data deleted in caller
    m_WeeklyQuestChanged = false;
}

void Player::ResetSeasonalQuestStatus(uint16 event_id)
{
    if (m_seasonalquests.empty() || m_seasonalquests[event_id].empty())
        return;

    m_seasonalquests.erase(event_id);
    // DB data deleted in caller
    m_SeasonalQuestChanged = false;
}

void Player::ResetMonthlyQuestStatus()
{
    if (m_monthlyquests.empty())
        return;

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

bool Player::InBattlegroundQueue(bool ignoreArena) const
{
    for (uint8 i = 0; i < PLAYER_MAX_BATTLEGROUND_QUEUES; ++i)
        if (m_bgBattlegroundQueueID[i].bgQueueTypeId != BATTLEGROUND_QUEUE_NONE && (!ignoreArena ||
            (ignoreArena && m_bgBattlegroundQueueID[i].bgQueueTypeId != BATTLEGROUND_QUEUE_2v2 &&
            m_bgBattlegroundQueueID[i].bgQueueTypeId != BATTLEGROUND_QUEUE_3v3 &&
            m_bgBattlegroundQueueID[i].bgQueueTypeId != BATTLEGROUND_QUEUE_5v5)))
            return true;
    return false;
}

BattlegroundQueueTypeId Player::GetBattlegroundQueueTypeId(uint32 index) const
{
    return m_bgBattlegroundQueueID[index].bgQueueTypeId;
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
    uint32 level = GetLevel();
    if (level > DEFAULT_MAX_LEVEL)
        level = DEFAULT_MAX_LEVEL;

    if (level < bg->GetMinLevel() || level > bg->GetMaxLevel())
        return false;

    return true;
}

float Player::GetReputationPriceDiscount(Creature const* creature) const
{
    return GetReputationPriceDiscount(creature->GetFactionTemplateEntry());
}

float Player::GetReputationPriceDiscount(FactionTemplateEntry const* factionTemplate) const
{
    if (!factionTemplate || !factionTemplate->faction)
        return 1.0f;

    ReputationRank rank = GetReputationRank(factionTemplate->faction);
    if (rank <= REP_NEUTRAL)
        return 1.0f;

    return 1.0f - 0.05f* (rank - REP_NEUTRAL);
}

Player* Player::GetTrader() const
{
    return m_trade ? m_trade->GetTrader() : nullptr;
}

bool Player::IsSpellFitByClassAndRace(uint32 spell_id) const
{
    uint32 racemask  = GetRaceMask();
    uint32 classmask = GetClassMask();

    SkillLineAbilityMapBounds bounds = sSpellMgr->GetSkillLineAbilityMapBounds(spell_id);
    if (bounds.first == bounds.second)
        return true;

    for (SkillLineAbilityMap::const_iterator _spell_idx = bounds.first; _spell_idx != bounds.second; ++_spell_idx)
    {
        // skip wrong race skills
        if (_spell_idx->second->racemask && (_spell_idx->second->racemask & racemask) == 0)
            continue;

        // skip wrong class skills
        if (_spell_idx->second->classmask && (_spell_idx->second->classmask & classmask) == 0)
            continue;

        // skip wrong class and race skill saved in SkillRaceClassInfo.dbc
        if (!GetSkillRaceClassInfo(_spell_idx->second->skillId, GetRace(), GetClass()))
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
            Quest const* qinfo = sObjectMgr->GetQuestTemplate(questid);
            if (!qinfo)
                continue;

            if (GetGroup() && GetGroup()->isRaidGroup() && !qinfo->IsAllowedInRaid(GetMap()->GetDifficulty()))
                continue;

            for (uint8 j = 0; j < QUEST_OBJECTIVES_COUNT; ++j)
            {
                if (qinfo->RequiredNpcOrGo[j] >= 0)       //skip non GO case
                    continue;

                if ((-1)*GOId == qinfo->RequiredNpcOrGo[j] && qs.CreatureOrGOCount[j] < qinfo->RequiredNpcOrGoCount[j])
                    return true;
            }
        }
    }
    return false;
}

void Player::UpdateVisibleGameobjectsOrSpellClicks()
{
    if (m_clientGUIDs.empty())
        return;

    UpdateData udata;
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
            if (!obj->HasFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_SPELLCLICK))
                continue;

            auto clickBounds = sObjectMgr->GetSpellClickInfoMapBounds(obj->GetEntry());
            for (auto const& clickPair : clickBounds)
            {
                if (ConditionContainer const* conds = sConditionMgr->GetConditionsForSpellClickEvent(obj->GetEntry(), clickPair.second.spellId))
                {
                    obj->BuildValuesUpdateBlockForPlayer(&udata, this);
                    break;
                }
            }
        }
    }
    udata.BuildPacket(&packet);
    SendDirectMessage(&packet);
}

bool Player::HasSummonPending() const
{
    return m_summon_expire >= GameTime::GetGameTime();
}

void Player::SendSummonRequestFrom(Unit* summoner)
{
    if (!summoner)
        return;

    // Player already has active summon request
    if (HasSummonPending())
        return;

    // Evil Twin (ignore player summon, but hide this for summoner)
    if (HasAura(23445))
        return;

    m_summon_expire = GameTime::GetGameTime() + MAX_PLAYER_SUMMON_DELAY;
    m_summon_location.WorldRelocate(*summoner);

    WorldPacket data(SMSG_SUMMON_REQUEST, 8 + 4 + 4);
    data << uint64(summoner->GetGUID());                     // summoner guid
    data << uint32(summoner->GetZoneId());                   // summoner zone
    data << uint32(MAX_PLAYER_SUMMON_DELAY*IN_MILLISECONDS); // auto decline after msecs
    SendDirectMessage(&data);
}

void Player::SummonIfPossible(bool agree)
{
    if (!agree)
    {
        m_summon_expire = 0;
        return;
    }

    // expire and auto declined
    if (m_summon_expire < GameTime::GetGameTime())
        return;

    // stop taxi flight at summon
    FinishTaxiFlight();

    // drop flag at summon
    // this code can be reached only when GM is summoning player who carries flag, because player should be immune to summoning spells when he carries flag
    if (Battleground* bg = GetBattleground())
        bg->EventPlayerDroppedFlag(this);

    m_summon_expire = 0;

    UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_ACCEPTED_SUMMONINGS, 1);

    TeleportTo(m_summon_location);
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
     if (!CanDualWield() && (offItem->GetTemplate()->InventoryType == INVTYPE_WEAPONOFFHAND || offItem->GetTemplate()->InventoryType == INVTYPE_WEAPON))
          force = true;

    // need unequip offhand for 2h-weapon without TitanGrip (in any from hands)
    if (!force && (CanTitanGrip() || (offItem->GetTemplate()->InventoryType != INVTYPE_2HWEAPON && !IsTwoHandUsed())))
        return;

    ItemPosCountVec off_dest;
    if (CanStoreItem(NULL_BAG, NULL_SLOT, off_dest, offItem, false) == EQUIP_ERR_OK)
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
            for (uint8 i = EQUIPMENT_SLOT_MAINHAND; i < EQUIPMENT_SLOT_TABARD; ++i)
                if (Item* item = GetUseableItemByPos(INVENTORY_SLOT_BAG_0, i))
                    if (item != ignoreItem && item->IsFitToSpellRequirements(spellInfo))
                        return true;
            break;
        }
        case ITEM_CLASS_ARMOR:
        {
            // most used check: shield only
            if (spellInfo->EquippedItemSubClassMask & ((1 << ITEM_SUBCLASS_ARMOR_BUCKLER) | (1 << ITEM_SUBCLASS_ARMOR_SHIELD)))
            {
                if (Item* item = GetUseableItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND))
                    if (item != ignoreItem && item->IsFitToSpellRequirements(spellInfo))
                        return true;

                // special check to filter things like Shield Wall, the aura is not permanent and must stay even without required item
                if (!spellInfo->IsPassive())
                {
                    for (uint8 i = 0; i < MAX_SPELL_EFFECTS; ++i)
                        if (spellInfo->Effects[i].IsAura())
                            return true;
                }
            }

            // tabard not have dependent spells
            for (uint8 i = EQUIPMENT_SLOT_START; i < EQUIPMENT_SLOT_MAINHAND; ++i)
                if (Item* item = GetUseableItemByPos(INVENTORY_SLOT_BAG_0, i))
                    if (item != ignoreItem && item->IsFitToSpellRequirements(spellInfo))
                        return true;

            // ranged slot can have some armor subclasses
            if (Item* item = GetUseableItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_RANGED))
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
    flag96 noReagentMask;
    noReagentMask[0] = GetUInt32Value(PLAYER_NO_REAGENT_COST_1);
    noReagentMask[1] = GetUInt32Value(PLAYER_NO_REAGENT_COST_1+1);
    noReagentMask[2] = GetUInt32Value(PLAYER_NO_REAGENT_COST_1+2);
    if (spellInfo->SpellFamilyFlags  & noReagentMask)
        return true;

    return false;
}

void Player::RemoveItemDependentAurasAndCasts(Item* pItem)
{
    for (AuraMap::iterator itr = m_ownedAuras.begin(); itr != m_ownedAuras.end();)
    {
        Aura* aura = itr->second;

        // skip not self applied auras
        SpellInfo const* spellInfo = aura->GetSpellInfo();
        if (aura->GetCasterGUID() != GetGUID())
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

uint32 Player::GetResurrectionSpellId()
{
    // search priceless resurrection possibilities
    uint32 prio = 0;
    uint32 spell_id = 0;
    AuraEffectList const& dummyAuras = GetAuraEffectsByType(SPELL_AURA_DUMMY);
    for (AuraEffectList::const_iterator itr = dummyAuras.begin(); itr != dummyAuras.end(); ++itr)
    {
        // Soulstone Resurrection                           // prio: 3 (max, non death persistent)
        if (prio < 2 && (*itr)->GetSpellInfo()->SpellVisual[0] == 99 && (*itr)->GetSpellInfo()->SpellIconID == 92)
        {
            switch ((*itr)->GetId())
            {
                case 20707: spell_id =  3026; break;        // rank 1
                case 20762: spell_id = 20758; break;        // rank 2
                case 20763: spell_id = 20759; break;        // rank 3
                case 20764: spell_id = 20760; break;        // rank 4
                case 20765: spell_id = 20761; break;        // rank 5
                case 27239: spell_id = 27240; break;        // rank 6
                case 47883: spell_id = 47882; break;        // rank 7
                default:
                    TC_LOG_ERROR("entities.player", "Unhandled spell %u: S.Resurrection", (*itr)->GetId());
                    continue;
            }

            prio = 3;
        }
        // Twisting Nether                                  // prio: 2 (max)
        else if ((*itr)->GetId() == 23701 && roll_chance_i(10))
        {
            prio = 2;
            spell_id = 23700;
        }
    }

    // Reincarnation (passive spell)  // prio: 1                  // Glyph of Renewed Life
    if (prio < 1 && HasSpell(20608) && !GetSpellHistory()->HasCooldown(21169) && (HasAura(58059) || HasItemCount(17030)))
        spell_id = 21169;

    return spell_id;
}

// Used in triggers for check "Only to targets that grant experience or honor" req
bool Player::isHonorOrXPTarget(Unit* victim) const
{
    uint8 v_level = victim->GetLevel();
    uint8 k_grey  = Trinity::XP::GetGrayLevel(GetLevel());

    // Victim level less gray level
    if (v_level <= k_grey && !sWorld->getIntConfig(CONFIG_MIN_CREATURE_SCALED_XP_RATIO))
        return false;

    if (Creature const* creature = victim->ToCreature())
    {
        if (!creature->CanGiveExperience())
            return false;
    }
    return true;
}

bool Player::GetsRecruitAFriendBonus(bool forXP)
{
    bool recruitAFriend = false;
    if (GetLevel() <= sWorld->getIntConfig(CONFIG_MAX_RECRUIT_A_FRIEND_BONUS_PLAYER_LEVEL) || !forXP)
    {
        if (Group* group = GetGroup())
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
                    if (player->GetLevel() > sWorld->getIntConfig(CONFIG_MAX_RECRUIT_A_FRIEND_BONUS_PLAYER_LEVEL))
                        continue;

                    // level difference must be small enough to get RaF bonus, UNLESS we are lower level
                    if (player->GetLevel() < GetLevel())
                        if (uint8(GetLevel() - player->GetLevel()) > sWorld->getIntConfig(CONFIG_MAX_RECRUIT_A_FRIEND_BONUS_PLAYER_LEVEL_DIFFERENCE))
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
    if (!pRewardSource || !IsInMap(pRewardSource))
        return false;

    WorldObject const* player = GetCorpse();
    if (!player || IsAlive())
        player = this;

    if (pRewardSource->GetMap()->IsDungeon())
        return true;

    return pRewardSource->GetDistance(player) <= sWorld->getFloatConfig(CONFIG_GROUP_XP_DISTANCE);
}

bool Player::IsAtRecruitAFriendDistance(WorldObject const* pOther) const
{
    if (!pOther || !IsInMap(pOther))
        return false;

    WorldObject const* player = GetCorpse();
    if (!player || IsAlive())
        player = this;

    return pOther->GetDistance(player) <= sWorld->getFloatConfig(CONFIG_MAX_RECRUIT_A_FRIEND_DISTANCE);
}

uint32 Player::GetBaseWeaponSkillValue(WeaponAttackType attType) const
{
    Item* item = GetWeaponForAttack(attType, true);

    // unarmed only with base attack
    if (attType != BASE_ATTACK && !item)
        return 0;

    // weapon skill or (unarmed for base attack)
    uint32  skill = item ? item->GetSkill() : uint32(SKILL_UNARMED);
    return GetBaseSkillValue(skill);
}

void Player::ResurrectUsingRequestData()
{
    RemoveGhoul();

    if (uint32 aura = _resurrectionData->Aura)
    {
        CastSpell(this, aura, _resurrectionData->GUID);
        return;
    }

    // Teleport before resurrecting by player, otherwise the player might get attacked from creatures near his corpse
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
    // save health and mana before resurrecting, _resurrectionData can be erased
    uint32 resurrectHealth = _resurrectionData->Health;
    uint32 resurrectMana = _resurrectionData->Mana;

    ResurrectPlayer(0.0f, false);

    SetHealth(resurrectHealth);
    SetPower(POWER_MANA, resurrectMana);

    SetPower(POWER_RAGE, 0);
    SetFullPower(POWER_ENERGY);

    SpawnCorpseBones();
}

void Player::SetClientControl(Unit* target, bool allowMove)
{
    // a player can never client control nothing
    ASSERT(target);

    // don't allow possession to be overridden
    if (target->HasUnitState(UNIT_STATE_CHARMED) && (GetGUID() != target->GetCharmerGUID()))
    {
        TC_LOG_ERROR("entities.player", "Player '%s' attempt to client control '%s', which is charmed by GUID %s",
                     GetName().c_str(), target->GetName().c_str(), target->GetCharmerGUID().ToString().c_str());
        return;
    }

    // still affected by some aura that shouldn't allow control, only allow on last such aura to be removed
    if (target->HasUnitState(UNIT_STATE_FLEEING | UNIT_STATE_CONFUSED))
        allowMove = false;

    WorldPacket data(SMSG_CLIENT_CONTROL_UPDATE, target->GetPackGUID().size()+1);
    data << target->GetPackGUID();
    data << uint8(allowMove ? 1 : 0);
    SendDirectMessage(&data);

    WorldObject* viewpoint = GetViewpoint();
    if (!viewpoint)
        viewpoint = this;
    if (target != viewpoint)
    {
        if (viewpoint != this)
            SetViewpoint(viewpoint, false);
        if (target != this)
            SetViewpoint(target, true);
    }

    SetMovedUnit(target);
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
        if (iter->second->GetSpellInfo()->CheckLocation(GetMapId(), m_zoneUpdateId, newArea, this, false) != SPELL_CAST_OK)
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

    time_t now = GameTime::GetGameTime();
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

    time_t now = GameTime::GetGameTime();

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
        time_t now = GameTime::GetGameTime();

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
    WorldPacket data(SMSG_CORPSE_RECLAIM_DELAY, 4);
    data << uint32(delay);
    SendDirectMessage(&data);
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
            if (itr->GetSource() && itr->GetSource()->IsInMap(this) && itr->GetSource()->IsInCombat())
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
        return sLFGMgr->inLfgDungeonMap(GetGUID(), map->GetId(), map->GetDifficulty());
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

void Player::ProcessTerrainStatusUpdate(ZLiquidStatus status, Optional<LiquidData> const& liquidData)
{
    // process liquid auras using generic unit code
    Unit::ProcessTerrainStatusUpdate(status, liquidData);

    // player specific logic for mirror timers
    if (status && liquidData)
    {
        // Breath bar state (under water in any liquid type)
        if (liquidData->type_flags & MAP_ALL_LIQUIDS)
        {
            if (status & LIQUID_MAP_UNDER_WATER)
                m_MirrorTimerFlags |= UNDERWATER_INWATER;
            else
                m_MirrorTimerFlags &= ~UNDERWATER_INWATER;
        }

        // Fatigue bar state (if not on flight path or transport)
        if ((liquidData->type_flags & MAP_LIQUID_TYPE_DARK_WATER) && !IsInFlight() && !GetTransport())
            m_MirrorTimerFlags |= UNDERWATER_INDARKWATER;
        else
            m_MirrorTimerFlags &= ~UNDERWATER_INDARKWATER;

        // Lava state (any contact)
        if (liquidData->type_flags & MAP_LIQUID_TYPE_MAGMA)
        {
            if (status & MAP_LIQUID_STATUS_IN_CONTACT)
                m_MirrorTimerFlags |= UNDERWATER_INLAVA;
            else
                m_MirrorTimerFlags &= ~UNDERWATER_INLAVA;
        }

        // Slime state (any contact)
        if (liquidData->type_flags & MAP_LIQUID_TYPE_SLIME)
        {
            if (status & MAP_LIQUID_STATUS_IN_CONTACT)
                m_MirrorTimerFlags |= UNDERWATER_INSLIME;
            else
                m_MirrorTimerFlags &= ~UNDERWATER_INSLIME;
        }
    }
    else
        m_MirrorTimerFlags &= ~(UNDERWATER_INWATER | UNDERWATER_INLAVA | UNDERWATER_INSLIME | UNDERWATER_INDARKWATER);
}

void Player::AtExitCombat()
{
    Unit::AtExitCombat();
    UpdatePotionCooldown();

    if (GetClass() == CLASS_DEATH_KNIGHT)
        for (uint8 i = 0; i < MAX_RUNES; ++i)
        {
            SetRuneTimer(i, 0xFFFFFFFF);
            SetLastRuneGraceTimer(i, 0);
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
        SetSeer(target);
    }
    else
    {
        TC_LOG_DEBUG("maps", "Player::CreateViewpoint: Player %s removed seer", GetName().c_str());

        if (!RemoveGuidValue(PLAYER_FARSIGHT, target->GetGUID()))
        {
            TC_LOG_FATAL("entities.player", "Player::CreateViewpoint: Player '%s' (%s) cannot remove current viewpoint!", GetName().c_str(), GetGUID().ToString().c_str());
            return;
        }

        if (target->isType(TYPEMASK_UNIT) && target != GetVehicleBase())
            static_cast<Unit*>(target)->RemovePlayerFromVision(this);

        //must immediately set seer back otherwise may crash
        SetSeer(this);

        //WorldPacket data(SMSG_CLEAR_FAR_SIGHT_IMMEDIATE, 0);
        //SendDirectMessage(&data);
    }

    // HACK: Make sure update for PLAYER_FARSIGHT is received before SMSG_PET_SPELLS to properly hide "Release spirit" dialog
    if (target->GetTypeId() == TYPEID_UNIT && static_cast<Unit*>(target)->HasUnitTypeMask(UNIT_MASK_MINION) && static_cast<Minion*>(target)->IsRisenAlly())
    {
        if (apply)
        {
            UpdateDataMapType update_players;
            BuildUpdate(update_players);
            WorldPacket packet;
            for (UpdateDataMapType::iterator iter = update_players.begin(); iter != update_players.end(); ++iter)
            {
                iter->second.BuildPacket(&packet);
                iter->first->SendDirectMessage(&packet);
                packet.clear();
            }
        }
        else
        {
            m_deathTimer = 6 * MINUTE * IN_MILLISECONDS;

            // Reset "Release spirit" timer clientside
            WorldPacket data(SMSG_FORCED_DEATH_UPDATE);
            SendDirectMessage(&data);
        }
    }
}

WorldObject* Player::GetViewpoint() const
{
    if (ObjectGuid guid = GetGuidValue(PLAYER_FARSIGHT))
        return static_cast<WorldObject*>(ObjectAccessor::GetObjectByTypeMask(*this, guid, TYPEMASK_SEER));
    return nullptr;
}

bool Player::CanUseBattlegroundObject(GameObject* gameobject) const
{
    // It is possible to call this method with a null pointer, only skipping faction check.
    if (gameobject)
    {
        FactionTemplateEntry const* playerFaction = GetFactionTemplateEntry();
        FactionTemplateEntry const* faction = sFactionTemplateStore.LookupEntry(gameobject->GetFaction());

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

uint32 Player::GetBarberShopCost(uint8 newhairstyle, uint8 newhaircolor, uint8 newfacialhair, BarberShopStyleEntry const* newSkin) const
{
    uint8 level = GetLevel();

    if (level > GT_MAX_LEVEL)
        level = GT_MAX_LEVEL;                               // max level in this dbc

    uint8 hairstyle = GetHairStyleId();
    uint8 haircolor = GetHairColorId();
    uint8 facialhair = GetFacialStyle();
    uint8 skincolor = GetSkinId();

    if ((hairstyle == newhairstyle) && (haircolor == newhaircolor) && (facialhair == newfacialhair) && (!newSkin || (newSkin->hair_id == skincolor)))
        return 0;

    GtBarberShopCostBaseEntry const* bsc = sGtBarberShopCostBaseStore.LookupEntry(level - 1);

    if (!bsc)                                                // shouldn't happen
        return 0xFFFFFFFF;

    float cost = 0;

    if (hairstyle != newhairstyle)
        cost += bsc->cost;                                  // full price

    if ((haircolor != newhaircolor) && (hairstyle == newhairstyle))
        cost += bsc->cost * 0.5f;                           // +1/2 of price

    if (facialhair != newfacialhair)
        cost += bsc->cost * 0.75f;                          // +3/4 of price

    if (newSkin && skincolor != newSkin->hair_id)
        cost += bsc->cost * 0.75f;                          // +5/6 of price

    return uint32(cost);
}

void Player::InitGlyphsForLevel()
{
    for (uint32 i = 0; i < sGlyphSlotStore.GetNumRows(); ++i)
        if (GlyphSlotEntry const* gs = sGlyphSlotStore.LookupEntry(i))
            if (gs->Order)
                SetGlyphSlot(gs->Order - 1, gs->Id);

    uint8 level = GetLevel();
    uint32 value = 0;

    // 0x3F = 0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 for 80 level
    if (level >= 15)
        value |= (0x01 | 0x02);
    if (level >= 30)
        value |= 0x08;
    if (level >= 50)
        value |= 0x04;
    if (level >= 70)
        value |= 0x10;
    if (level >= 80)
        value |= 0x20;

    SetUInt32Value(PLAYER_GLYPHS_ENABLED, value);
}

void Player::SetGlyph(uint8 slot, uint32 glyph)
{
    m_Glyphs[m_activeSpec][slot] = glyph;
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

bool Player::HasTitle(CharTitlesEntry const* title) const
{
    return HasTitle(title->bit_index);
}

void Player::SetTitle(CharTitlesEntry const* title, bool lost)
{
    uint32 fieldIndexOffset = title->bit_index / 32;
    uint32 flag = 1 << (title->bit_index % 32);

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

    WorldPacket data(SMSG_TITLE_EARNED, 4 + 4);
    data << uint32(title->bit_index);
    data << uint32(lost ? 0 : 1);                           // 1 - earned, 0 - lost
    SendDirectMessage(&data);
}

uint32 Player::GetRuneBaseCooldown(uint8 index)
{
    uint8 rune = GetBaseRune(index);
    uint32 cooldown = RUNE_BASE_COOLDOWN;

    AuraEffectList const& regenAura = GetAuraEffectsByType(SPELL_AURA_MOD_POWER_REGEN_PERCENT);
    for (AuraEffectList::const_iterator i = regenAura.begin();i != regenAura.end(); ++i)
    {
        if ((*i)->GetMiscValue() == POWER_RUNE && (*i)->GetMiscValueB() == rune)
            cooldown = cooldown * (100 - (*i)->GetAmount()) / 100;
    }

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

    ResyncRunes();
}

void Player::SetRuneConvertAura(uint8 index, AuraEffect const* aura)
{
    m_runes->runes[index].ConvertAuras.insert(aura);
}

void Player::RemoveRuneConvertAura(uint8 index, AuraEffect const* aura)
{
    m_runes->runes[index].ConvertAuras.erase(aura);
}

void Player::AddRuneByAuraEffect(uint8 index, RuneType newType, AuraEffect const* aura)
{
    SetRuneConvertAura(index, aura);
    ConvertRune(index, newType);
}

void Player::RemoveRunesByAuraEffect(AuraEffect const* aura)
{
    for (uint8 itr = 0; itr < MAX_RUNES; ++itr)
    {
        RemoveRuneConvertAura(itr, aura);

        if (m_runes->runes[itr].ConvertAuras.empty())
            ConvertRune(itr, GetBaseRune(itr));
    }
}

void Player::RestoreBaseRune(uint8 index)
{
    std::vector<AuraEffect const*> removeList;
    std::unordered_set<AuraEffect const*>& auras = m_runes->runes[index].ConvertAuras;

    auto criteria = [&removeList](AuraEffect const* storedAura) -> bool
    {
        // AuraEffect already gone
        if (!storedAura)
            return true;

        if (storedAura->GetSpellInfo()->HasAttribute(SPELL_ATTR0_PASSIVE))
        {
            // Don't drop passive talents providing rune conversion
            if (storedAura->GetAuraType() == SPELL_AURA_CONVERT_RUNE)
                removeList.push_back(storedAura);
            return true;
        }

        // If rune was converted by a non-passive aura that is still active we should keep it converted
        return false;
    };

    Trinity::Containers::EraseIf(auras, criteria);

    if (!auras.empty())
        return;

    ConvertRune(index, GetBaseRune(index));

    if (removeList.empty())
        return;

    // Filter auras set to be removed if they are converting any other rune index
    for (AuraEffect const* storedAura : removeList)
    {
        uint8 itr = 0;
        for (; itr < MAX_RUNES; ++itr)
        {
            if (m_runes->runes[itr].ConvertAuras.find(storedAura) != m_runes->runes[itr].ConvertAuras.end())
                break;
        }

        if (itr == MAX_RUNES)
            storedAura->GetBase()->Remove();
    }
}

void Player::ConvertRune(uint8 index, RuneType newType)
{
    SetCurrentRune(index, newType);

    WorldPacket data(SMSG_CONVERT_RUNE, 2);
    data << uint8(index);
    data << uint8(newType);
    SendDirectMessage(&data);
}

void Player::ResyncRunes() const
{
    if (GetClass() != CLASS_DEATH_KNIGHT)
        return;

    WorldPackets::Spells::ResyncRunes packet;
    packet.Count = MAX_RUNES;
    for (uint32 itr = 0; itr < MAX_RUNES; ++itr)
    {
        WorldPackets::Spells::ResyncRune resyncRune;
        resyncRune.RuneType = GetCurrentRune(itr);
        resyncRune.Cooldown = uint8(255) - uint8(GetRuneCooldown(itr) * uint32(255) / uint32(RUNE_BASE_COOLDOWN)); // cooldown time (0-255)
        packet.Runes.emplace_back(resyncRune);
    }
    SendDirectMessage(packet.Write());
}

void Player::AddRunePower(uint8 index) const
{
    WorldPacket data(SMSG_ADD_RUNE_POWER, 4);
    data << uint32(1 << index);                             // mask (0x00-0x3F probably)
    SendDirectMessage(&data);
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
    if (GetClass() != CLASS_DEATH_KNIGHT)
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
        SetFloatValue(PLAYER_RUNE_REGEN_1 + i, 0.1f);
}

bool Player::IsBaseRuneSlotsOnCooldown(RuneType runeType) const
{
    for (uint8 i = 0; i < MAX_RUNES; ++i)
        if (GetBaseRune(i) == runeType && GetRuneCooldown(i) == 0)
            return false;

    return true;
}

void Player::AutoStoreLoot(uint8 bag, uint8 slot, uint32 loot_id, LootStore const& store, bool broadcast, bool createdByPlayer)
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

        Item* pItem = StoreNewItem(dest, lootItem->itemid, true, lootItem->randomPropertyId);
        SendNewItem(pItem, lootItem->count, false, createdByPlayer, broadcast);
    }
}

void Player::StoreLootItem(uint8 lootSlot, Loot* loot)
{
    NotNormalLootItem* qitem = nullptr;
    NotNormalLootItem* ffaitem = nullptr;
    NotNormalLootItem* conditem = nullptr;

    LootItem* item = loot->LootItemInSlot(lootSlot, this, &qitem, &ffaitem, &conditem);

    if (!item)
    {
        SendEquipError(EQUIP_ERR_ALREADY_LOOTED, nullptr, nullptr);
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

    // dont allow protected item to be looted by someone else
    if (!item->rollWinnerGUID.IsEmpty() && item->rollWinnerGUID != GetGUID())
    {
        SendLootRelease(GetLootGUID());
        return;
    }

    ItemPosCountVec dest;
    InventoryResult msg = CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, item->itemid, item->count);
    if (msg == EQUIP_ERR_OK)
    {
        GuidSet looters = item->GetAllowedLooters();
        Item* newitem = StoreNewItem(dest, item->itemid, true, item->randomPropertyId, looters);

        if (qitem)
        {
            qitem->is_looted = true;
            //freeforall is 1 if everyone's supposed to get the quest item.
            if (item->freeforall || loot->GetPlayerQuestItems().size() == 1)
                SendNotifyLootItemRemoved(lootSlot);
            else
                loot->NotifyQuestItemRemoved(qitem->index);
        }
        else
        {
            if (ffaitem)
            {
                //freeforall case, notify only one player of the removal
                ffaitem->is_looted = true;
                SendNotifyLootItemRemoved(lootSlot);
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

        SendNewItem(newitem, uint32(item->count), false, false, true);
        UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_LOOT_ITEM, item->itemid, item->count);
        UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_LOOT_TYPE, loot->loot_type, item->count);
        UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_LOOT_EPIC_ITEM, item->itemid, item->count);

        // LootItem is being removed (looted) from the container, delete it from the DB.
        if (loot->containerID > 0)
            sLootItemStorage->RemoveStoredLootItemForContainer(loot->containerID, item->itemid, item->count);

    }
    else
        SendEquipError(msg, nullptr, nullptr, item->itemid);
}

uint32 Player::CalculateTalentsPoints() const
{
    uint32 base_talent = GetLevel() < 10 ? 0 : GetLevel()-9;

    if (GetClass() != CLASS_DEATH_KNIGHT || GetMapId() != 609)
        return uint32(base_talent * sWorld->getRate(RATE_TALENT));

    uint32 talentPointsForLevel = GetLevel() < 56 ? 0 : GetLevel() - 55;
    talentPointsForLevel += m_questRewardTalentCount;

    if (talentPointsForLevel > base_talent)
        talentPointsForLevel = base_talent;

    return uint32(talentPointsForLevel * sWorld->getRate(RATE_TALENT));
}

bool Player::CanFlyInZone(uint32 mapid, uint32 zone, SpellInfo const* bySpell) const
{
    // continent checked in SpellInfo::CheckLocation at cast and area update
    uint32 v_map = GetVirtualMapForMapAndZone(mapid, zone);
    if (v_map == 571 && !bySpell->HasAttribute(SPELL_ATTR7_IGNORE_COLD_WEATHER_FLYING))
        if (!HasSpell(54197)) // 54197 = Cold Weather Flying
            return false;

    return true;
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
    std::unordered_map<uint32, uint32> loadedSkillValues;
    if (result)
    {
        do
        {
            Field* fields = result->Fetch();
            uint16 skill    = fields[0].GetUInt16();
            uint16 value    = fields[1].GetUInt16();
            uint16 max      = fields[2].GetUInt16();

            SkillRaceClassInfoEntry const* rcEntry = GetSkillRaceClassInfo(skill, GetRace(), GetClass());
            if (!rcEntry)
            {
                TC_LOG_ERROR("entities.player", "Player::_LoadSkills: Player '%s' (%s, Race: %u, Class: %u) has forbidden skill %u for his race/class combination",
                    GetName().c_str(), GetGUID().ToString().c_str(), uint32(GetRace()), uint32(GetClass()), skill);

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

                stmt->setUInt32(0, GetGUID().GetCounter());
                stmt->setUInt16(1, skill);

                CharacterDatabase.Execute(stmt);

                continue;
            }

            uint16 skillStep = 0;
            if (SkillTiersEntry const* skillTier = sSkillTiersStore.LookupEntry(rcEntry->SkillTier))
            {
                for (uint32 i = 0; i < MAX_SKILL_STEP; ++i)
                {
                    if (skillTier->MaxSkill[skillStep] == max)
                    {
                        skillStep = i + 1;
                        break;
                    }
                }
            }

            SetUInt32Value(PLAYER_SKILL_INDEX(count), MAKE_PAIR32(skill, skillStep));

            SetUInt32Value(PLAYER_SKILL_VALUE_INDEX(count), MAKE_SKILL_VALUE(value, max));
            SetUInt32Value(PLAYER_SKILL_BONUS_INDEX(count), 0);

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

    for (; count < PLAYER_MAX_SKILLS; ++count)
    {
        SetUInt32Value(PLAYER_SKILL_INDEX(count), 0);
        SetUInt32Value(PLAYER_SKILL_VALUE_INDEX(count), 0);
        SetUInt32Value(PLAYER_SKILL_BONUS_INDEX(count), 0);
    }

    if (HasSkill(SKILL_FIST_WEAPONS))
        SetSkill(SKILL_FIST_WEAPONS, 0, GetSkillValue(SKILL_UNARMED), GetMaxSkillValueForLevel());
}

uint32 Player::GetPhaseMaskForSpawn() const
{
    uint32 phase = PHASEMASK_NORMAL;
    if (!IsGameMaster())
        phase = GetPhaseMask();
    else
    {
        AuraEffectList const& phases = GetAuraEffectsByType(SPELL_AURA_PHASE);
        if (!phases.empty())
            phase = phases.front()->GetMiscValue();
    }

    // some aura phases include 1 normal map in addition to phase itself
    if (uint32 n_phase = phase & ~PHASEMASK_NORMAL)
        return n_phase;

    return PHASEMASK_NORMAL;
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

        ItemTemplate const* pGem = sObjectMgr->GetItemTemplate(enchantEntry->GemID);
        if (!pGem)
            continue;

        // include for check equip another gems with same limit category for not equipped item (and then not counted)
        uint32 gem_limit_count = !pItem->IsEquipped() && pGem->ItemLimitCategory
            ? pItem->GetGemCountWithLimitCategory(pGem->ItemLimitCategory) : 1;

        if (InventoryResult res = CanEquipUniqueItem(pGem, eslot, gem_limit_count))
            return res;
    }

    return EQUIP_ERR_OK;
}

InventoryResult Player::CanEquipUniqueItem(ItemTemplate const* itemProto, uint8 except_slot, uint32 limit_count) const
{
    // check unique-equipped on item
    if (itemProto->Flags & ITEM_FLAG_UNIQUE_EQUIPPABLE)
    {
        // there is an equip limit on this item
        if (HasItemOrGemWithIdEquipped(itemProto->ItemId, 1, except_slot))
            return EQUIP_ERR_ITEM_UNIQUE_EQUIPABLE;
    }

    // check unique-equipped limit
    if (itemProto->ItemLimitCategory)
    {
        ItemLimitCategoryEntry const* limitEntry = sItemLimitCategoryStore.LookupEntry(itemProto->ItemLimitCategory);
        if (!limitEntry)
            return EQUIP_ERR_ITEM_CANT_BE_EQUIPPED;

        // NOTE: limitEntry->mode not checked because if item have have-limit then it applied and to equip case

        if (limit_count > limitEntry->maxCount)
            return EQUIP_ERR_ITEM_MAX_LIMIT_CATEGORY_EQUIPPED_EXCEEDED;

        // there is an equip limit on this item
        if (HasItemWithLimitCategoryEquipped(itemProto->ItemLimitCategory, limitEntry->maxCount - limit_count + 1, except_slot))
            return EQUIP_ERR_ITEM_MAX_LIMIT_CATEGORY_EQUIPPED_EXCEEDED;
        else if (HasGemWithLimitCategoryEquipped(itemProto->ItemLimitCategory, limitEntry->maxCount - limit_count + 1, except_slot))
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
    //TC_LOG_DEBUG("zDiff = %f", z_diff);

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
            TC_LOG_DEBUG("entities.player", "FALLDAMAGE z=%f sz=%f pZ=%f FallTime=%d mZ=%f damage=%d SF=%d", movementInfo.pos.GetPositionZ(), height, GetPositionZ(), movementInfo.fallTime, height, damage, safe_fall);
        }
    }
}

void Player::ResetAchievements()
{
    m_achievementMgr->Reset();
}

void Player::SendRespondInspectAchievements(Player* player) const
{
    m_achievementMgr->SendRespondInspectAchievements(player);
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

void Player::ResetAchievementCriteria(AchievementCriteriaCondition condition, uint32 value, bool evenIfCriteriaComplete /* = false*/)
{
    m_achievementMgr->ResetAchievementCriteria(condition, value, evenIfCriteriaComplete);
}

void Player::UpdateAchievementCriteria(AchievementCriteriaTypes type, uint32 miscValue1 /*= 0*/, uint32 miscValue2 /*= 0*/, WorldObject* ref /*= nullptr*/)
{
    m_achievementMgr->UpdateAchievementCriteria(type, miscValue1, miscValue2, ref);
}

void Player::CompletedAchievement(AchievementEntry const* entry)
{
    m_achievementMgr->CompletedAchievement(entry);
}

void Player::LearnTalent(uint32 talentId, uint32 talentRank)
{
    uint32 CurTalentPoints = GetFreeTalentPoints();

    if (CurTalentPoints == 0)
        return;

    if (talentRank >= MAX_TALENT_RANK)
        return;

    TalentEntry const* talentInfo = sTalentStore.LookupEntry(talentId);

    if (!talentInfo)
        return;

    TalentTabEntry const* talentTabInfo = sTalentTabStore.LookupEntry(talentInfo->TalentTab);

    if (!talentTabInfo)
        return;

    // prevent learn talent for different class (cheating)
    if ((GetClassMask() & talentTabInfo->ClassMask) == 0)
        return;

    // find current max talent rank (0~5)
    uint8 curtalent_maxrank = 0; // 0 = not learned any rank
    for (int8 rank = MAX_TALENT_RANK-1; rank >= 0; --rank)
    {
        if (talentInfo->RankID[rank] && HasSpell(talentInfo->RankID[rank]))
        {
            curtalent_maxrank = (rank + 1);
            break;
        }
    }

    // we already have same or higher talent rank learned
    if (curtalent_maxrank >= (talentRank + 1))
        return;

    // check if we have enough talent points
    if (CurTalentPoints < (talentRank - curtalent_maxrank + 1))
        return;

    // Check if it requires another talent
    if (talentInfo->DependsOn > 0)
    {
        if (TalentEntry const* depTalentInfo = sTalentStore.LookupEntry(talentInfo->DependsOn))
        {
            bool hasEnoughRank = false;
            for (uint8 rank = talentInfo->DependsOnRank; rank < MAX_TALENT_RANK; rank++)
            {
                if (depTalentInfo->RankID[rank] != 0)
                    if (HasSpell(depTalentInfo->RankID[rank]))
                        hasEnoughRank = true;
            }
            if (!hasEnoughRank)
                return;
        }
    }

    // Find out how many points we have in this field
    uint32 spentPoints = 0;

    uint32 tTab = talentInfo->TalentTab;
    if (talentInfo->Row > 0)
        for (uint32 i = 0; i < sTalentStore.GetNumRows(); i++)          // Loop through all talents.
            if (TalentEntry const* tmpTalent = sTalentStore.LookupEntry(i))                                  // the way talents are tracked
                if (tmpTalent->TalentTab == tTab)
                    for (uint8 rank = 0; rank < MAX_TALENT_RANK; rank++)
                        if (tmpTalent->RankID[rank] != 0)
                            if (HasSpell(tmpTalent->RankID[rank]))
                                spentPoints += (rank + 1);

    // not have required min points spent in talent tree
    if (spentPoints < (talentInfo->Row * MAX_TALENT_RANK))
        return;

    // spell not set in talent.dbc
    uint32 spellid = talentInfo->RankID[talentRank];
    if (spellid == 0)
    {
        TC_LOG_ERROR("entities.player", "Player::LearnTalent: Talent.dbc has no spellInfo for talent: %u (spell id = 0)", talentId);
        return;
    }

    // already known
    if (HasSpell(spellid))
        return;

    // learn! (other talent ranks will unlearned at learning)
    LearnSpell(spellid, false);
    AddTalent(spellid, m_activeSpec, true);

    TC_LOG_DEBUG("misc", "Player::LearnTalent: TalentID: %u Spell: %u Group: %u\n", talentId, spellid, uint32(m_activeSpec));

    // update free talent points
    SetFreeTalentPoints(CurTalentPoints - (talentRank - curtalent_maxrank + 1));
}

void Player::LearnPetTalent(ObjectGuid petGuid, uint32 talentId, uint32 talentRank)
{
    Pet* pet = GetPet();

    if (!pet)
        return;

    if (petGuid != pet->GetGUID())
        return;

    uint32 CurTalentPoints = pet->GetFreeTalentPoints();

    if (CurTalentPoints == 0)
        return;

    if (talentRank >= MAX_PET_TALENT_RANK)
        return;

    TalentEntry const* talentInfo = sTalentStore.LookupEntry(talentId);

    if (!talentInfo)
        return;

    TalentTabEntry const* talentTabInfo = sTalentTabStore.LookupEntry(talentInfo->TalentTab);

    if (!talentTabInfo)
        return;

    CreatureTemplate const* ci = pet->GetCreatureTemplate();

    if (!ci)
        return;

    CreatureFamilyEntry const* pet_family = sCreatureFamilyStore.LookupEntry(ci->family);

    if (!pet_family)
        return;

    if (pet_family->petTalentType < 0)                       // not hunter pet
        return;

    // prevent learn talent for different family (cheating)
    if (!((1 << pet_family->petTalentType) & talentTabInfo->petTalentMask))
        return;

    // find current max talent rank (0~5)
    uint8 curtalent_maxrank = 0; // 0 = not learned any rank
    for (int8 rank = MAX_TALENT_RANK-1; rank >= 0; --rank)
    {
        if (talentInfo->RankID[rank] && pet->HasSpell(talentInfo->RankID[rank]))
        {
            curtalent_maxrank = (rank + 1);
            break;
        }
    }

    // we already have same or higher talent rank learned
    if (curtalent_maxrank >= (talentRank + 1))
        return;

    // check if we have enough talent points
    if (CurTalentPoints < (talentRank - curtalent_maxrank + 1))
        return;

    // Check if it requires another talent
    if (talentInfo->DependsOn > 0)
    {
        if (TalentEntry const* depTalentInfo = sTalentStore.LookupEntry(talentInfo->DependsOn))
        {
            bool hasEnoughRank = false;
            for (uint8 rank = talentInfo->DependsOnRank; rank < MAX_TALENT_RANK; rank++)
            {
                if (depTalentInfo->RankID[rank] != 0)
                    if (pet->HasSpell(depTalentInfo->RankID[rank]))
                        hasEnoughRank = true;
            }
            if (!hasEnoughRank)
                return;
        }
    }

    // Find out how many points we have in this field
    uint32 spentPoints = 0;

    uint32 tTab = talentInfo->TalentTab;
    if (talentInfo->Row > 0)
    {
        uint32 numRows = sTalentStore.GetNumRows();
        for (uint32 i = 0; i < numRows; ++i)          // Loop through all talents.
        {
            // Someday, someone needs to revamp
            TalentEntry const* tmpTalent = sTalentStore.LookupEntry(i);
            if (tmpTalent)                                  // the way talents are tracked
            {
                if (tmpTalent->TalentTab == tTab)
                {
                    for (uint8 rank = 0; rank < MAX_TALENT_RANK; rank++)
                    {
                        if (tmpTalent->RankID[rank] != 0)
                        {
                            if (pet->HasSpell(tmpTalent->RankID[rank]))
                            {
                                spentPoints += (rank + 1);
                            }
                        }
                    }
                }
            }
        }
    }

    // not have required min points spent in talent tree
    if (spentPoints < (talentInfo->Row * MAX_PET_TALENT_RANK))
        return;

    // spell not set in talent.dbc
    uint32 spellid = talentInfo->RankID[talentRank];
    if (spellid == 0)
    {
        TC_LOG_ERROR("entities.player", "Talent.dbc contains talent: %u Rank: %u spell id = 0", talentId, talentRank);
        return;
    }

    // already known
    if (pet->HasSpell(spellid))
        return;

    // learn! (other talent ranks will unlearned at learning)
    pet->learnSpell(spellid);
    TC_LOG_DEBUG("entities.player", "PetTalentID: %u Rank: %u Spell: %u\n", talentId, talentRank, spellid);

    // update free talent points
    pet->SetFreeTalentPoints(CurTalentPoints - (talentRank - curtalent_maxrank + 1));
}

void Player::AddKnownCurrency(uint32 itemId)
{
    if (CurrencyTypesEntry const* ctEntry = sCurrencyTypesStore.LookupEntry(itemId))
        SetFlag64(PLAYER_FIELD_KNOWN_CURRENCIES, (1LL << (ctEntry->BitIndex-1)));
}

void Player::UpdateFallInformationIfNeed(MovementInfo const& minfo, uint16 opcode)
{
    if (m_lastFallTime >= minfo.fallTime || m_lastFallZ <= minfo.pos.GetPositionZ() || opcode == MSG_MOVE_FALL_LAND)
        SetFallInformation(minfo.fallTime, minfo.pos.GetPositionZ());
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

    if (GetPetGUID())
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
    if (!c->HasFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_SPELLCLICK))
        return false;

    auto clickBounds = sObjectMgr->GetSpellClickInfoMapBounds(c->GetEntry());
    if (clickBounds.begin() == clickBounds.end())
        return false;

    for (auto const& clickPair : clickBounds)
    {
        if (!clickPair.second.IsFitToRequirements(this, c))
            return false;

        if (sConditionMgr->IsObjectMeetingSpellClickConditions(c->GetEntry(), clickPair.second.spellId, const_cast<Player*>(this), const_cast<Creature*>(c)))
            return true;
    }

    return false;
}

void Player::BuildPlayerTalentsInfoData(WorldPacket* data)
{
    *data << uint32(GetFreeTalentPoints());                 // unspentTalentPoints
    *data << uint8(m_specsCount);                           // talent group count (0, 1 or 2)
    *data << uint8(m_activeSpec);                           // talent group index (0 or 1)

    if (m_specsCount)
    {
        if (m_specsCount > MAX_TALENT_SPECS)
            m_specsCount = MAX_TALENT_SPECS;

        // loop through all specs (only 1 for now)
        for (uint32 specIdx = 0; specIdx < m_specsCount; ++specIdx)
        {
            uint8 talentIdCount = 0;
            size_t pos = data->wpos();
            *data << uint8(talentIdCount);                  // [PH], talentIdCount

            // find class talent tabs (all players have 3 talent tabs)
            uint32 const* talentTabIds = GetTalentTabPages(GetClass());

            for (uint8 i = 0; i < MAX_TALENT_TABS; ++i)
            {
                uint32 talentTabId = talentTabIds[i];

                for (uint32 talentId = 0; talentId < sTalentStore.GetNumRows(); ++talentId)
                {
                    TalentEntry const* talentInfo = sTalentStore.LookupEntry(talentId);
                    if (!talentInfo)
                        continue;

                    // skip another tab talents
                    if (talentInfo->TalentTab != talentTabId)
                        continue;

                    // find max talent rank (0~4)
                    int8 curtalent_maxrank = -1;
                    for (int8 rank = MAX_TALENT_RANK-1; rank >= 0; --rank)
                    {
                        if (talentInfo->RankID[rank] && HasTalent(talentInfo->RankID[rank], specIdx))
                        {
                            curtalent_maxrank = rank;
                            break;
                        }
                    }

                    // not learned talent
                    if (curtalent_maxrank < 0)
                        continue;

                    *data << uint32(talentInfo->TalentID);  // Talent.dbc
                    *data << uint8(curtalent_maxrank);      // talentMaxRank (0-4)

                    ++talentIdCount;
                }
            }

            data->put<uint8>(pos, talentIdCount);           // put real count

            *data << uint8(MAX_GLYPH_SLOT_INDEX);           // glyphs count

            for (uint8 i = 0; i < MAX_GLYPH_SLOT_INDEX; ++i)
                *data << uint16(m_Glyphs[specIdx][i]);               // GlyphProperties.dbc
        }
    }
}

void Player::BuildPetTalentsInfoData(WorldPacket* data)
{
    uint32 unspentTalentPoints = 0;
    size_t pointsPos = data->wpos();
    *data << uint32(unspentTalentPoints);                   // [PH], unspentTalentPoints

    uint8 talentIdCount = 0;
    size_t countPos = data->wpos();
    *data << uint8(talentIdCount);                          // [PH], talentIdCount

    Pet* pet = GetPet();
    if (!pet)
        return;

    unspentTalentPoints = pet->GetFreeTalentPoints();

    data->put<uint32>(pointsPos, unspentTalentPoints);      // put real points

    CreatureTemplate const* ci = pet->GetCreatureTemplate();
    if (!ci)
        return;

    CreatureFamilyEntry const* pet_family = sCreatureFamilyStore.LookupEntry(ci->family);
    if (!pet_family || pet_family->petTalentType < 0)
        return;

    for (uint32 talentTabId = 1; talentTabId < sTalentTabStore.GetNumRows(); ++talentTabId)
    {
        TalentTabEntry const* talentTabInfo = sTalentTabStore.LookupEntry(talentTabId);
        if (!talentTabInfo)
            continue;

        if (!((1 << pet_family->petTalentType) & talentTabInfo->petTalentMask))
            continue;

        for (uint32 talentId = 0; talentId < sTalentStore.GetNumRows(); ++talentId)
        {
            TalentEntry const* talentInfo = sTalentStore.LookupEntry(talentId);
            if (!talentInfo)
                continue;

            // skip another tab talents
            if (talentInfo->TalentTab != talentTabId)
                continue;

            // find max talent rank (0~4)
            int8 curtalent_maxrank = -1;
            for (int8 rank = MAX_TALENT_RANK-1; rank >= 0; --rank)
            {
                if (talentInfo->RankID[rank] && pet->HasSpell(talentInfo->RankID[rank]))
                {
                    curtalent_maxrank = rank;
                    break;
                }
            }

            // not learned talent
            if (curtalent_maxrank < 0)
                continue;

            *data << uint32(talentInfo->TalentID);          // Talent.dbc
            *data << uint8(curtalent_maxrank);              // talentMaxRank (0-4)

            ++talentIdCount;
        }

        data->put<uint8>(countPos, talentIdCount);          // put real count

        break;
    }
}

void Player::SendTalentsInfoData(bool pet)
{
    WorldPacket data(SMSG_TALENTS_INFO, 50);
    data << uint8(pet ? 1 : 0);
    if (pet)
        BuildPetTalentsInfoData(&data);
    else
        BuildPlayerTalentsInfoData(&data);
    SendDirectMessage(&data);
}

void Player::BuildEnchantmentsInfoData(WorldPacket* data)
{
    uint32 slotUsedMask = 0;
    size_t slotUsedMaskPos = data->wpos();
    *data << uint32(slotUsedMask);                          // slotUsedMask < 0x80000

    for (uint32 i = 0; i < EQUIPMENT_SLOT_END; ++i)
    {
        Item* item = GetItemByPos(INVENTORY_SLOT_BAG_0, i);

        if (!item)
            continue;

        slotUsedMask |= (1 << i);

        *data << uint32(item->GetEntry());                  // item entry

        uint16 enchantmentMask = 0;
        size_t enchantmentMaskPos = data->wpos();
        *data << uint16(enchantmentMask);                   // enchantmentMask < 0x1000

        for (uint32 j = 0; j < MAX_ENCHANTMENT_SLOT; ++j)
        {
            uint32 enchId = item->GetEnchantmentId(EnchantmentSlot(j));

            if (!enchId)
                continue;

            enchantmentMask |= (1 << j);

            *data << uint16(enchId);                        // enchantmentId?
        }

        data->put<uint16>(enchantmentMaskPos, enchantmentMask);

        *data << uint16(0);                                 // unknown
        *data << item->GetGuidValue(ITEM_FIELD_CREATOR).WriteAsPacked(); // item creator
        *data << uint32(0);                                 // seed?
    }

    data->put<uint32>(slotUsedMaskPos, slotUsedMask);
}

void Player::SendEquipmentSetList()
{
    uint32 count = 0;
    WorldPacket data(SMSG_EQUIPMENT_SET_LIST, 1000); // guess size
    size_t count_pos = data.wpos();
    data << uint32(count);                                  // count placeholder

    for (EquipmentSetContainer::value_type const& eqSet : _equipmentSets)
    {
        if (eqSet.second.State == EQUIPMENT_SET_DELETED)
            continue;

        data.appendPackGUID(eqSet.first);
        data << uint32(eqSet.second.Data.SetID);
        data << eqSet.second.Data.SetName;
        data << eqSet.second.Data.SetIcon;

        for (uint32 i = 0; i < EQUIPMENT_SLOT_END; ++i)
        {
            // ignored slots stored in IgnoreMask, client wants "1" as raw GUID, so no HighGuid::Item
            if (eqSet.second.Data.IgnoreMask & (1 << i))
                data.appendPackGUID(uint64(1));
            else
                data.appendPackGUID(eqSet.second.Data.Pieces[i]);
        }

        ++count;                                            // client have limit but it checked at loading and set
    }
    data.put<uint32>(count_pos, count);
    SendDirectMessage(&data);
}

void Player::SetEquipmentSet(EquipmentSetInfo::EquipmentSetData const& eqSet)
{
    if (eqSet.Guid != 0)
    {
        // something wrong...
        auto itr = _equipmentSets.find(eqSet.Guid);
        if (itr == _equipmentSets.end() || itr->second.Data.Guid != eqSet.Guid)
        {
            TC_LOG_ERROR("entities.player", "Player::SetEquipmentSet: Player '%s' (%s) tried to save nonexistent equipment set " UI64FMTD " (index: %u)",
                GetName().c_str(), GetGUID().ToString().c_str(), eqSet.Guid, eqSet.SetID);
            return;
        }
    }

    EquipmentSetInfo& eqSlot = _equipmentSets[eqSet.Guid];

    EquipmentSetUpdateState oldState = eqSlot.State;
    eqSlot.Data = eqSet;

    if (eqSet.Guid == 0)
    {
        eqSlot.Data.Guid = sObjectMgr->GenerateEquipmentSetGuid();

        WorldPacket data(SMSG_EQUIPMENT_SET_SAVED, 4 + 1);
        data << uint32(eqSlot.Data.SetID);
        data.appendPackGUID(eqSlot.Data.Guid);
        SendDirectMessage(&data);
    }

    eqSlot.State = (oldState == EQUIPMENT_SET_NEW ? EQUIPMENT_SET_NEW : EQUIPMENT_SET_CHANGED);
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
                    stmt->setUInt32(j++, eqSet.Data.Pieces[i].GetCounter());
                stmt->setUInt32(j++, GetGUID().GetCounter());
                stmt->setUInt64(j++, eqSet.Data.Guid);
                stmt->setUInt32(j, eqSet.Data.SetID);
                trans->Append(stmt);
                eqSet.State = EQUIPMENT_SET_UNCHANGED;
                ++itr;
                break;
            case EQUIPMENT_SET_NEW:
                stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_EQUIP_SET);
                stmt->setUInt32(j++, GetGUID().GetCounter());
                stmt->setUInt64(j++, eqSet.Data.Guid);
                stmt->setUInt32(j++, eqSet.Data.SetID);
                stmt->setString(j++, eqSet.Data.SetName);
                stmt->setString(j++, eqSet.Data.SetIcon);
                stmt->setUInt32(j++, eqSet.Data.IgnoreMask);
                for (uint8 i = 0; i < EQUIPMENT_SLOT_END; ++i)
                    stmt->setUInt32(j++, eqSet.Data.Pieces[i].GetCounter());
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
    stmt->setUInt32(0, GetGUID().GetCounter());
    trans->Append(stmt);
    /* guid, bgInstanceID, bgTeam, x, y, z, o, map, taxi[0], taxi[1], mountSpell */
    stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_PLAYER_BGDATA);
    stmt->setUInt32(0, GetGUID().GetCounter());
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

void Player::DeleteEquipmentSet(uint64 setGuid)
{
    for (EquipmentSetContainer::iterator itr = _equipmentSets.begin(); itr != _equipmentSets.end();)
    {
        if (itr->second.Data.Guid == setGuid)
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
        stmt->setUInt32(1, GetGUID().GetCounter());

        CharacterDatabase.Execute(stmt);
    }
}

void Player::ResetMap()
{
    // this may be called during Map::Update
    // after decrement+unlink, ++m_mapRefIter will continue correctly
    // when the first element of the list is being removed
    // nocheck_prev will return the padding element of the RefManager
    // instead of nullptr in the case of prev
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
    // SELECT talentGroup, glyph1, glyph2, glyph3, glyph4, glyph5, glyph6 from character_glyphs WHERE guid = '%u'
    if (!result)
        return;

    do
    {
        Field* fields = result->Fetch();

        uint8 spec = fields[0].GetUInt8();
        if (spec >= m_specsCount)
            continue;

        m_Glyphs[spec][0] = fields[1].GetUInt16();
        m_Glyphs[spec][1] = fields[2].GetUInt16();
        m_Glyphs[spec][2] = fields[3].GetUInt16();
        m_Glyphs[spec][3] = fields[4].GetUInt16();
        m_Glyphs[spec][4] = fields[5].GetUInt16();
        m_Glyphs[spec][5] = fields[6].GetUInt16();
    }
    while (result->NextRow());
}

void Player::_SaveGlyphs(SQLTransaction& trans) const
{
    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHAR_GLYPHS);
    stmt->setUInt32(0, GetGUID().GetCounter());
    trans->Append(stmt);


    for (uint8 spec = 0; spec < m_specsCount; ++spec)
    {
        uint8 index = 0;

        stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_CHAR_GLYPHS);
        stmt->setUInt32(index++, GetGUID().GetCounter());

        stmt->setUInt8(index++, spec);

        for (uint8 i = 0; i < MAX_GLYPH_SLOT_INDEX; ++i)
            stmt->setUInt16(index++, uint16(m_Glyphs[spec][i]));

        trans->Append(stmt);
    }
}

void Player::_LoadTalents(PreparedQueryResult result)
{
    // SetPQuery(PLAYER_LOGIN_QUERY_LOADTALENTS, "SELECT spell, talentGroup FROM character_talent WHERE guid = '%u'", GUID_LOPART(m_guid));
    if (result)
    {
        do
            AddTalent((*result)[0].GetUInt32(), (*result)[1].GetUInt8(), false);
        while (result->NextRow());
    }
}

void Player::_SaveTalents(SQLTransaction& trans)
{
    PreparedStatement* stmt = nullptr;

    for (uint8 i = 0; i < MAX_TALENT_SPECS; ++i)
    {
        for (PlayerTalentMap::iterator itr = m_talents[i]->begin(); itr != m_talents[i]->end();)
        {
            if (itr->second->state == PLAYERSPELL_REMOVED || itr->second->state == PLAYERSPELL_CHANGED)
            {
                stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHAR_TALENT_BY_SPELL_SPEC);
                stmt->setUInt32(0, GetGUID().GetCounter());
                stmt->setUInt32(1, itr->first);
                stmt->setUInt8(2, itr->second->spec);
                trans->Append(stmt);
            }

            if (itr->second->state == PLAYERSPELL_NEW || itr->second->state == PLAYERSPELL_CHANGED)
            {
                stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_CHAR_TALENT);
                stmt->setUInt32(0, GetGUID().GetCounter());
                stmt->setUInt32(1, itr->first);
                stmt->setUInt8(2, itr->second->spec);
                trans->Append(stmt);
            }

            if (itr->second->state == PLAYERSPELL_REMOVED)
            {
                delete itr->second;
                m_talents[i]->erase(itr++);
            }
            else
            {
                itr->second->state = PLAYERSPELL_UNCHANGED;
                ++itr;
            }
        }
    }
}

void Player::UpdateSpecCount(uint8 count)
{
    uint32 curCount = GetSpecsCount();
    if (curCount == count)
        return;

    if (m_activeSpec >= count)
        ActivateSpec(0);

    SQLTransaction trans = CharacterDatabase.BeginTransaction();
    PreparedStatement* stmt;

    // Copy spec data
    if (count > curCount)
    {
        _SaveActions(trans); // make sure the button list is cleaned up
        for (ActionButtonList::iterator itr = m_actionButtons.begin(); itr != m_actionButtons.end(); ++itr)
        {
            stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_CHAR_ACTION);
            stmt->setUInt32(0, GetGUID().GetCounter());
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
        stmt->setUInt8(0, m_activeSpec);
        stmt->setUInt32(1, GetGUID().GetCounter());
        trans->Append(stmt);

        m_activeSpec = 0;
    }

    CharacterDatabase.CommitTransaction(trans);

    SetSpecsCount(count);

    SendTalentsInfoData(false);
}

void Player::ActivateSpec(uint8 spec)
{
    if (GetActiveSpec() == spec)
        return;

    if (spec > GetSpecsCount())
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

    // remove single target auras at other targets
    AuraList& scAuras = GetSingleCastAuras();
    for (AuraList::iterator iter = scAuras.begin(); iter != scAuras.end();)
    {
        Aura* aura = *iter;
        if (aura->GetUnitOwner() != this)
        {
            aura->Remove();
            iter = scAuras.begin();
        }
        else
            ++iter;
    }
    /*RemoveAllAurasOnDeath();
    if (GetPet())
        GetPet()->RemoveAllAurasOnDeath();*/

    //RemoveAllAuras(GetGUID(), nullptr, false, true); // removes too many auras
    //ExitVehicle(); // should be impossible to switch specs from inside a vehicle..

    // Let client clear his current Actions
    SendActionButtons(2);
    // m_actionButtons.clear() is called in the next _LoadActionButtons
    for (uint32 talentId = 0; talentId < sTalentStore.GetNumRows(); ++talentId)
    {
        TalentEntry const* talentInfo = sTalentStore.LookupEntry(talentId);

        if (!talentInfo)
            continue;

        TalentTabEntry const* talentTabInfo = sTalentTabStore.LookupEntry(talentInfo->TalentTab);

        if (!talentTabInfo)
            continue;

        // unlearn only talents for character class
        // some spell learned by one class as normal spells or know at creation but another class learn it as talent,
        // to prevent unexpected lost normal learned spell skip another class talents
        if ((GetClassMask() & talentTabInfo->ClassMask) == 0)
            continue;

        for (int8 rank = MAX_TALENT_RANK-1; rank >= 0; --rank)
        {
            // skip non-existing talent ranks
            if (talentInfo->RankID[rank] == 0)
                continue;
            RemoveSpell(talentInfo->RankID[rank], true); // removes the talent, and all dependant, learned, and chained spells..
            if (SpellInfo const* _spellEntry = sSpellMgr->GetSpellInfo(talentInfo->RankID[rank]))
                for (uint8 i = 0; i < MAX_SPELL_EFFECTS; ++i)                  // search through the SpellInfo for valid trigger spells
                    if (_spellEntry->Effects[i].TriggerSpell > 0 && _spellEntry->Effects[i].Effect == SPELL_EFFECT_LEARN_SPELL)
                        RemoveSpell(_spellEntry->Effects[i].TriggerSpell, true); // and remove any spells that the talent teaches
            // if this talent rank can be found in the PlayerTalentMap, mark the talent as removed so it gets deleted
            //PlayerTalentMap::iterator plrTalent = m_talents[m_activeSpec]->find(talentInfo->RankID[rank]);
            //if (plrTalent != m_talents[m_activeSpec]->end())
            //    plrTalent->second->state = PLAYERSPELL_REMOVED;
        }
    }

    // set glyphs
    for (uint8 slot = 0; slot < MAX_GLYPH_SLOT_INDEX; ++slot)
        // remove secondary glyph
        if (uint32 oldglyph = m_Glyphs[m_activeSpec][slot])
            if (GlyphPropertiesEntry const* old_gp = sGlyphPropertiesStore.LookupEntry(oldglyph))
                RemoveAurasDueToSpell(old_gp->SpellId);

    SetActiveSpec(spec);
    uint32 spentTalents = 0;

    for (uint32 talentId = 0; talentId < sTalentStore.GetNumRows(); ++talentId)
    {
        TalentEntry const* talentInfo = sTalentStore.LookupEntry(talentId);

        if (!talentInfo)
            continue;

        TalentTabEntry const* talentTabInfo = sTalentTabStore.LookupEntry(talentInfo->TalentTab);

        if (!talentTabInfo)
            continue;

        // learn only talents for character class
        if ((GetClassMask() & talentTabInfo->ClassMask) == 0)
            continue;

        // learn highest talent rank that exists in newly activated spec
        for (int8 rank = MAX_TALENT_RANK-1; rank >= 0; --rank)
        {
            // skip non-existing talent ranks
            if (talentInfo->RankID[rank] == 0)
                continue;
            // if the talent can be found in the newly activated PlayerTalentMap
            if (HasTalent(talentInfo->RankID[rank], m_activeSpec))
            {
                LearnSpell(talentInfo->RankID[rank], false); // add the talent to the PlayerSpellMap
                spentTalents += (rank + 1);                  // increment the spentTalents count
            }
        }
    }

    // set glyphs
    for (uint8 slot = 0; slot < MAX_GLYPH_SLOT_INDEX; ++slot)
    {
        uint32 glyph = m_Glyphs[m_activeSpec][slot];

        // apply primary glyph
        if (glyph)
            if (GlyphPropertiesEntry const* gp = sGlyphPropertiesStore.LookupEntry(glyph))
                CastSpell(this, gp->SpellId, true);

        SetGlyph(slot, glyph);
    }

    m_usedTalentCount = spentTalents;
    InitTalentForLevel();

    // load them asynchronously
    {
        PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHARACTER_ACTIONS_SPEC);
        stmt->setUInt32(0, GetGUID().GetCounter());
        stmt->setUInt8(1, m_activeSpec);

        WorldSession* mySess = GetSession();
        mySess->GetQueryProcessor().AddQuery(CharacterDatabase.AsyncQuery(stmt)
            .WithPreparedCallback([mySess](PreparedQueryResult result)
        {
            // safe callback, we can't pass this pointer directly
            // in case player logs out before db response (player would be deleted in that case)
            if (Player* thisPlayer = mySess->GetPlayer())
                thisPlayer->LoadActions(result);
        }));
    }

    Powers pw = GetPowerType();
    if (pw != POWER_MANA)
        SetPower(POWER_MANA, 0); // Mana must be 0 even if it isn't the active power type.

    SetPower(pw, 0);

    Unit::AuraEffectList const& shapeshiftAuras = GetAuraEffectsByType(SPELL_AURA_MOD_SHAPESHIFT);
    for (AuraEffect* aurEff : shapeshiftAuras)
    {
        aurEff->HandleShapeshiftBoosts(this, false);
        aurEff->HandleShapeshiftBoosts(this, true);
    }
}

void Player::LoadActions(PreparedQueryResult result)
{
    if (result)
        _LoadActions(result);

    SendActionButtons(1);
}

void Player::SetReputation(uint32 factionentry, uint32 value)
{
    GetReputationMgr().SetReputation(sFactionStore.LookupEntry(factionentry), value);
}
uint32 Player::GetReputation(uint32 factionentry) const
{
    return GetReputationMgr().GetReputation(sFactionStore.LookupEntry(factionentry));
}

std::string const& Player::GetGuildName() const
{
    return sGuildMgr->GetGuildById(GetGuildId())->GetName();
}

void Player::SendDuelCountdown(uint32 counter)
{
    WorldPacket data(SMSG_DUEL_COUNTDOWN, 4);
    data << uint32(counter);                                // seconds
    SendDirectMessage(&data);
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
    // This function call unsets ITEM_FLAGS_REFUNDABLE if played time is over 2 hours.
    item->UpdatePlayedTime(this);

    if (!item->HasFlag(ITEM_FIELD_FLAGS, ITEM_FIELD_FLAG_REFUNDABLE))
    {
        TC_LOG_DEBUG("entities.player.items", "Item refund: item not refundable!");
        return;
    }

    if (GetGUID().GetCounter() != item->GetRefundRecipient()) // Formerly refundable item got traded
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

    WorldPacket data(SMSG_ITEM_REFUND_INFO_RESPONSE, 8+4+4+4+4*4+4*4+4+4);
    data << uint64(item->GetGUID());                    // item guid
    data << uint32(item->GetPaidMoney());               // money cost
    data << uint32(iece->reqhonorpoints);               // honor point cost
    data << uint32(iece->reqarenapoints);               // arena point cost
    for (uint8 i = 0; i < MAX_ITEM_EXTENDED_COST_REQUIREMENTS; ++i)                       // item cost data
    {
        data << uint32(iece->reqitem[i]);
        data << uint32(iece->reqitemcount[i]);
    }
    data << uint32(0);
    data << uint32(GetTotalPlayedTime() - item->GetPlayedTime());
    SendDirectMessage(&data);
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

    Item* item = StoreNewItem(dest, itemId, true, GenerateItemRandomPropertyId(itemId));
    if (item)
        SendNewItem(item, count, true, false);
    else
        return false;
    return true;
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
        WorldPacket data(SMSG_ITEM_REFUND_RESULT, 8+4);
        data << uint64(item->GetGUID());             // Guid
        data << uint32(10);                          // Error!
        SendDirectMessage(&data);
        return;
    }

    if (GetGUID().GetCounter() != item->GetRefundRecipient()) // Formerly refundable item got traded
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
    for (uint8 i = 0; i < MAX_ITEM_EXTENDED_COST_REQUIREMENTS; ++i)
    {
        uint32 count = iece->reqitemcount[i];
        uint32 itemid = iece->reqitem[i];

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
        WorldPacket data(SMSG_ITEM_REFUND_RESULT, 8+4);
        data << uint64(item->GetGUID());                 // Guid
        data << uint32(10);                              // Error!
        SendDirectMessage(&data);
        return;
    }

    WorldPacket data(SMSG_ITEM_REFUND_RESULT, 8+4+4+4+4+4*4+4*4);
    data << uint64(item->GetGUID());                    // item guid
    data << uint32(0);                                  // 0, or error code
    data << uint32(item->GetPaidMoney());               // money cost
    data << uint32(iece->reqhonorpoints);               // honor point cost
    data << uint32(iece->reqarenapoints);               // arena point cost
    for (uint8 i = 0; i < MAX_ITEM_EXTENDED_COST_REQUIREMENTS; ++i) // item cost data
    {
        data << uint32(iece->reqitem[i]);
        data << uint32(iece->reqitemcount[i]);
    }
    SendDirectMessage(&data);

    uint32 moneyRefund = item->GetPaidMoney();  // item-> will be invalidated in DestroyItem

    // Save all relevant data to DB to prevent desynchronisation exploits
    SQLTransaction trans = CharacterDatabase.BeginTransaction();

    // Delete any references to the refund data
    item->SetNotRefundable(this, true, &trans);

    // Destroy item
    DestroyItem(item->GetBagSlot(), item->GetSlot(), true);

    // Grant back extendedcost items
    for (uint8 i = 0; i < MAX_ITEM_EXTENDED_COST_REQUIREMENTS; ++i)
    {
        uint32 count = iece->reqitemcount[i];
        uint32 itemid = iece->reqitem[i];
        if (count && itemid)
        {
            ItemPosCountVec dest;
            InventoryResult msg = CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, itemid, count);
            ASSERT(msg == EQUIP_ERR_OK); /// Already checked before
            Item* it = StoreNewItem(dest, itemid, true);
            SendNewItem(it, count, true, false, true);
        }
    }

    // Grant back money
    if (moneyRefund)
        ModifyMoney(moneyRefund); // Saved in SaveInventoryAndGoldToDB

    // Grant back Honor points
    if (uint32 honorRefund = iece->reqhonorpoints)
        ModifyHonorPoints(honorRefund, trans);

    // Grant back Arena points
    if (uint32 arenaRefund = iece->reqarenapoints)
        ModifyArenaPoints(arenaRefund, trans);

    SaveInventoryAndGoldToDB(trans);

    CharacterDatabase.CommitTransaction(trans);
}

void Player::SendItemRetrievalMail(uint32 itemEntry, uint32 count)
{
    MailSender sender(MAIL_CREATURE, 34337 /* The Postmaster */);
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

        stmt->setUInt32(0, GetGUID().GetCounter());

        CharacterDatabase.Execute(stmt);
    }
}

void Player::_LoadRandomBGStatus(PreparedQueryResult result)
{
    //QueryResult result = CharacterDatabase.PQuery("SELECT guid FROM character_battleground_random WHERE guid = '%u'", GetGUID().GetCounter());

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
            sum += m_items[i]->GetTemplate()->GetItemLevelIncludingQuality();

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

bool Player::SetDisableGravity(bool disable, bool packetOnly /*= false*/)
{
    if (!packetOnly && !Unit::SetDisableGravity(disable))
        return false;

    WorldPacket data(disable ? SMSG_MOVE_GRAVITY_DISABLE : SMSG_MOVE_GRAVITY_ENABLE, 12);
    data << GetPackGUID();
    data << uint32(0);          //! movement counter
    SendDirectMessage(&data);

    data.Initialize(MSG_MOVE_GRAVITY_CHNG, 64);
    data << GetPackGUID();
    BuildMovementPacket(&data);
    SendMessageToSet(&data, false);
    return true;
}

bool Player::SetCanFly(bool apply, bool packetOnly /*= false*/)
{
    if (!apply)
        SetFallInformation(0, GetPositionZ());

    WorldPacket data(apply ? SMSG_MOVE_SET_CAN_FLY : SMSG_MOVE_UNSET_CAN_FLY, 12);
    data << GetPackGUID();
    data << uint32(0);          //! movement counter
    SendDirectMessage(&data);

    if (packetOnly || Unit::SetCanFly(apply))
    {
        data.Initialize(MSG_MOVE_UPDATE_CAN_FLY, 64);
        data << GetPackGUID();
        BuildMovementPacket(&data);
        SendMessageToSet(&data, false);
        return true;
    }
    else
        return false;
}

bool Player::SetHover(bool apply, bool packetOnly /*= false*/)
{
    if (!packetOnly && !Unit::SetHover(apply))
        return false;

    WorldPacket data(apply ? SMSG_MOVE_SET_HOVER : SMSG_MOVE_UNSET_HOVER, 12);
    data << GetPackGUID();
    data << uint32(0);          //! movement counter
    SendDirectMessage(&data);

    data.Initialize(MSG_MOVE_HOVER, 64);
    data << GetPackGUID();
    BuildMovementPacket(&data);
    SendMessageToSet(&data, false);
    return true;
}

bool Player::SetWaterWalking(bool apply, bool packetOnly /*= false*/)
{
    if (!packetOnly && !Unit::SetWaterWalking(apply))
        return false;

    WorldPacket data(apply ? SMSG_MOVE_WATER_WALK : SMSG_MOVE_LAND_WALK, 12);
    data << GetPackGUID();
    data << uint32(0);          //! movement counter
    SendDirectMessage(&data);

    data.Initialize(MSG_MOVE_WATER_WALK, 64);
    data << GetPackGUID();
    BuildMovementPacket(&data);
    SendMessageToSet(&data, false);
    return true;
}

bool Player::SetFeatherFall(bool apply, bool packetOnly /*= false*/)
{
    if (!packetOnly && !Unit::SetFeatherFall(apply))
        return false;

    WorldPacket data(apply ? SMSG_MOVE_FEATHER_FALL : SMSG_MOVE_NORMAL_FALL, 12);
    data << GetPackGUID();
    data << uint32(0);          //! movement counter
    SendDirectMessage(&data);

    data.Initialize(MSG_MOVE_FEATHER_FALL, 64);
    data << GetPackGUID();
    BuildMovementPacket(&data);
    SendMessageToSet(&data, false);
    return true;
}

std::string Player::GetMapAreaAndZoneString() const
{
    uint32 areaId = GetAreaId();
    std::string areaName = "Unknown";
    std::string zoneName = "Unknown";
    if (AreaTableEntry const* area = sAreaTableStore.LookupEntry(areaId))
    {
        int locale = GetSession()->GetSessionDbcLocale();
        areaName = area->area_name[locale];
        if (AreaTableEntry const* zone = sAreaTableStore.LookupEntry(area->zone))
            zoneName = zone->area_name[locale];
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

void Player::SetInGuild(uint32 guildId)
{
    SetUInt32Value(PLAYER_GUILDID, guildId);
    sCharacterCache->UpdateCharacterGuildId(GetGUID(), guildId);
}

Guild* Player::GetGuild()
{
    uint32 guildId = GetGuildId();
    return guildId ? sGuildMgr->GetGuildById(guildId) : nullptr;
}

Pet* Player::SummonPet(uint32 entry, float x, float y, float z, float ang, PetType petType, uint32 duration, bool aliveOnly)
{
    Pet* pet = new Pet(this, petType);

    if (petType == SUMMON_PET && pet->LoadPetFromDB(this, entry))
    {
        if (aliveOnly && !pet->IsAlive())
        {
            pet->DespawnOrUnsummon();
            SendTameFailure(PETTAME_DEAD);
            return nullptr;
        }

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

        // Generate a new name for the newly summoned ghoul
        if (pet->IsPetGhoul())
        {
            std::string new_name = sObjectMgr->GeneratePetName(entry);
            if (!new_name.empty())
                pet->SetName(new_name);
        }

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
    if (!pet->Create(map->GenerateLowGuid<HighGuid::Pet>(), map, GetPhaseMask(), entry, pet_number))
    {
        TC_LOG_ERROR("misc", "Player::SummonPet: No such creature entry %u", entry);
        delete pet;
        return nullptr;
    }

    pet->SetCreatorGUID(GetGUID());
    pet->SetFaction(GetFaction());

    pet->SetUInt32Value(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_NONE);
    pet->SetUInt32Value(UNIT_FIELD_BYTES_1, 0);
    pet->InitStatsForLevel(GetLevel());

    SetMinion(pet, true);

    switch (petType)
    {
        case SUMMON_PET:
            // this enables pet details window (Shift+P)
            pet->GetCharmInfo()->SetPetNumber(pet_number, true);
            pet->SetClass(CLASS_MAGE);
            pet->SetUInt32Value(UNIT_FIELD_PETEXPERIENCE, 0);
            pet->SetUInt32Value(UNIT_FIELD_PETNEXTLEVELEXP, 1000);
            pet->SetFullHealth();
            pet->SetPower(POWER_MANA, pet->GetMaxPower(POWER_MANA));
            pet->SetUInt32Value(UNIT_FIELD_PET_NAME_TIMESTAMP, uint32(GameTime::GetGameTime())); // cast can't be helped in this case
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

void Player::SendSupercededSpell(uint32 oldSpell, uint32 newSpell) const
{
    WorldPacket data(SMSG_SUPERCEDED_SPELL, 8);
    data << uint32(oldSpell) << uint32(newSpell);
    SendDirectMessage(&data);
}

bool Player::ValidateAppearance(uint8 race, uint8 class_, uint8 gender, uint8 hairID, uint8 hairColor, uint8 faceID, uint8 facialHair, uint8 skinColor, bool create /*=false*/)
{
    auto validateCharSection = [class_, create](CharSectionsEntry const* entry) -> bool
    {
        if (!entry)
            return false;

        // Check Death Knight exclusive
        if (class_ != CLASS_DEATH_KNIGHT && entry->HasFlag(SECTION_FLAG_DEATH_KNIGHT))
            return false;

        // Character creation/customize has some limited sections (as opposed to barbershop)
        if (create && !entry->HasFlag(SECTION_FLAG_PLAYER))
            return false;

        return true;
    };

    // For Skin type is always 0
    CharSectionsEntry const* skinEntry = GetCharSectionEntry(race, SECTION_TYPE_SKIN, gender, 0, skinColor);
    if (!validateCharSection(skinEntry))
        return false;

    // Skin Color defined as Face color, too
    CharSectionsEntry const* faceEntry = GetCharSectionEntry(race, SECTION_TYPE_FACE, gender, faceID, skinColor);
    if (!validateCharSection(faceEntry))
        return false;

    // Check Hair
    CharSectionsEntry const* hairEntry = GetCharSectionEntry(race, SECTION_TYPE_HAIR, gender, hairID, hairColor);
    if (!validateCharSection(hairEntry))
        return false;

    // These combinations don't have an entry of Type SECTION_TYPE_FACIAL_HAIR, exclude them from that check
    bool const excludeCheck = (race == RACE_TAUREN) || (race == RACE_DRAENEI) || (gender == GENDER_FEMALE && race != RACE_NIGHTELF && race != RACE_UNDEAD_PLAYER);
    if (!excludeCheck)
    {
        CharSectionsEntry const* facialHairEntry = GetCharSectionEntry(race, SECTION_TYPE_FACIAL_HAIR, gender, facialHair, hairColor);
        if (!validateCharSection(facialHairEntry))
            return false;
    }

    CharacterFacialHairStylesEntry const* entry = GetCharFacialHairEntry(race, gender, facialHair);
    if (!entry)
        return false;

    return true;
}

void Player::SetRestFlag(RestFlag restFlag, uint32 triggerId /*= 0*/)
{
    uint32 oldRestMask = _restFlagMask;
    _restFlagMask |= restFlag;

    if (!oldRestMask && _restFlagMask) // only set flag/time on the first rest state
    {
        _restTime = GameTime::GetGameTime();
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

uint32 Player::DoRandomRoll(uint32 minimum, uint32 maximum)
{
    ASSERT(maximum <= 10000);

    uint32 roll = urand(minimum, maximum);

    WorldPacket data(MSG_RANDOM_ROLL, 4 + 4 + 4 + 8);
    data << uint32(minimum);
    data << uint32(maximum);
    data << uint32(roll);
    data << GetGUID();
    if (Group* group = GetGroup())
        group->BroadcastPacket(&data, false);
    else
        SendDirectMessage(&data);

    return roll;
}

void Player::RemoveSocial()
{
    sSocialMgr->RemovePlayerSocial(GetGUID());
    m_social = nullptr;
}

std::string Player::GetDebugInfo() const
{
    std::stringstream sstr;
    sstr << Unit::GetDebugInfo();
    return sstr.str();
}
