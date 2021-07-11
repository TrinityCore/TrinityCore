/*
 * Copyright (C) 2005-2011 MaNGOS <http://getmangos.com/>
 * Copyright (C) 2009-2011 MaNGOSZero <https://github.com/mangos/zero>
 * Copyright (C) 2011-2016 Nostalrius <https://nostalrius.org>
 * Copyright (C) 2016-2017 Elysium Project <https://github.com/elysium-project>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include <unordered_map>
#include <cmath>

#include "Player.h"
#include "Bag.h"
#include "Language.h"
#include "Database/DatabaseEnv.h"
#include "Log.h"
#include "Opcodes.h"
#include "SpellMgr.h"
#include "World.h"
#include "WorldPacket.h"
#include "WorldSession.h"
#include "UpdateMask.h"
#include "QuestDef.h"
#include "GossipDef.h"
#include "UpdateData.h"
#include "Channel.h"
#include "ChannelMgr.h"
#include "MapManager.h"
#include "MapPersistentStateMgr.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"
#include "CellImpl.h"
#include "ObjectMgr.h"
#include "ObjectAccessor.h"
#include "Formulas.h"
#include "Group.h"
#include "Guild.h"
#include "GuildMgr.h"
#include "Pet.h"
#include "Util.h"
#include "Transport.h"
#include "Weather.h"
#include "BattleGround.h"
#include "BattleGroundAV.h"
#include "BattleGroundMgr.h"
#include "Chat.h"
#include "Database/DatabaseImpl.h"
#include "Spell.h"
#include "ScriptMgr.h"
#include "SocialMgr.h"
#include "Mail.h"
#include "WaypointMovementGenerator.h"
#include "GMTicketMgr.h"
#include "MasterPlayer.h"
#include "MovementPacketSender.h"
#include "Config/Config.h"
#include "ZoneScript.h"
#include "ZoneScriptMgr.h"
#include "PlayerBotMgr.h"
#include "PlayerBotAI.h"
#include "AccountMgr.h"
#include "Anticheat.h"
#include "MovementBroadcaster.h"
#include "PlayerBroadcaster.h"
#include "CharacterDatabaseCache.h"
#include "GameEventMgr.h"
#include "world/scourge_invasion.h"
#include "world/world_event_wareffort.h"

#define ZONE_UPDATE_INTERVAL (1*IN_MILLISECONDS)

#define PLAYER_SKILL_INDEX(x)       (PLAYER_SKILL_INFO_1_1 + ((x)*3))
#define PLAYER_SKILL_VALUE_INDEX(x) (PLAYER_SKILL_INDEX(x)+1)
#define PLAYER_SKILL_BONUS_INDEX(x) (PLAYER_SKILL_INDEX(x)+2)

#define SKILL_VALUE(x)         PAIR32_LOPART(x)
#define SKILL_MAX(x)           PAIR32_HIPART(x)
#define MAKE_SKILL_VALUE(v, m) MAKE_PAIR32(v,m)

#define SKILL_TEMP_BONUS(x)    int16(PAIR32_LOPART(x))
#define SKILL_PERM_BONUS(x)    int16(PAIR32_HIPART(x))
#define MAKE_SKILL_BONUS(t, p) MAKE_PAIR32(t,p)

// [-ZERO] need recheck, some values known not existed in 1.12.1
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

// corpse reclaim times
#define DEATH_EXPIRE_STEP (5*MINUTE)
#define MAX_DEATH_COUNT 3

static uint32 copseReclaimDelay[MAX_DEATH_COUNT] = { 30, 60, 120 };

//== MirrorTimer ===============================================

MirrorTimer::Status MirrorTimer::FetchStatus()
{
    Status status = m_status;
    m_status = UNCHANGED;
    return status;
}

void MirrorTimer::Stop()
{
    if (m_active)
    {
        m_active = false;
        m_pulse.SetCurrent(0);
        m_tracker.SetCurrent(0);
        m_status = STATUS_UPDATE;
    }
}

void MirrorTimer::Start(uint32 interval, uint32 spellId/* = 0*/)
{
    if (m_scale < 0)
    {
        m_active = true;
        m_pulse.SetCurrent(0);
        m_pulse.SetInterval(2 * IN_MILLISECONDS);
        m_tracker.SetCurrent(0);
        m_tracker.SetInterval(interval);
        m_spellId = spellId;
        m_status = FULL_UPDATE;
    }
    else
        Stop();
}

void MirrorTimer::Start(uint32 current, uint32 max, uint32 spellId)
{
    Start(max, spellId);

    if (m_active)
    {
        m_tracker.SetCurrent(max - current);
        SetFrozen(false);
    }
}

void MirrorTimer::SetRemaining(uint32 duration)
{
    if (!duration)
        return Stop();

    if (IsActive() && duration != GetRemaining())
        m_status = FULL_UPDATE;

    m_tracker.SetCurrent(GetDuration() - duration);
}

void MirrorTimer::SetDuration(uint32 duration)
{
    if (!duration)
        return Stop();

    if (IsActive() && duration != GetDuration())
        m_status = FULL_UPDATE;

    m_tracker.SetInterval(duration);
}

void MirrorTimer::SetFrozen(bool state)
{
    if (IsActive() && state != IsFrozen())
        m_status = STATUS_UPDATE;

    m_frozen = state;
}

void MirrorTimer::SetScale(int32 scale)
{
    if (!scale)
        return SetFrozen(true);

    if (IsActive() && scale != m_scale)
        m_status = FULL_UPDATE;

    m_scale = scale;
}

bool MirrorTimer::Update(uint32 diff)
{
    if (!IsActive() || IsFrozen())
        return true;

    diff *= uint32(std::abs(m_scale));

    if (m_scale < 0)    // Timer running out
    {
        m_tracker.Update(diff);

        if (!m_tracker.Passed())
            return true;

        const uint32 interval = m_tracker.GetInterval();
        const uint32 overflow = (m_tracker.GetCurrent() - interval);

        m_tracker.SetCurrent(interval);

        if (overflow == diff)   // Pulse: subsequent ticks after instant tick on expiration
        {
            m_pulse.Update(overflow);

            if (!m_pulse.Passed())
                return true;

            m_pulse.Reset();
        }

        return false;
    }
    else                // Timer regenerating
    {
        const uint32 current = m_tracker.GetCurrent();

        if (current > diff)
        {
            m_tracker.SetCurrent(current - diff);
            m_pulse.SetCurrent(0);
        }
        else
            Stop();

        return true;
    }
}

//== PlayerTaxi ================================================

PlayerTaxi::PlayerTaxi()
{
    // Taxi nodes
    memset(m_taximask, 0, sizeof(m_taximask));
}

void PlayerTaxi::InitTaxiNodes(uint32 race, uint32 level)
{
    memset(m_taximask, 0, sizeof(m_taximask));
    // capital and taxi hub masks
    ChrRacesEntry const* rEntry = sChrRacesStore.LookupEntry(race);
    m_taximask[0] = rEntry->startingTaxiMask;
}

void PlayerTaxi::LoadTaxiMask(char const* data)
{
    if (!data)
        return;

    Tokens tokens = StrSplit(data, " ");

    int index;
    Tokens::iterator iter;
    for (iter = tokens.begin(), index = 0;
            (index < TaxiMaskSize) && (iter != tokens.end()); ++iter, ++index)
    {
        // load and set bits only for existing taxi nodes
        m_taximask[index] = sTaxiNodesMask[index] & uint32(atol((*iter).c_str()));
    }
}

void PlayerTaxi::AppendTaximaskTo(ByteBuffer& data, bool all)
{
    if (all)
    {
        for (uint32 i : sTaxiNodesMask)
            data << uint32(i);              // all existing nodes
    }
    else
    {
        for (uint32 i : m_taximask)
            data << uint32(i);                  // known nodes
    }
}

bool PlayerTaxi::LoadTaxiDestinationsFromString(std::string const& values, Team team)
{
    ClearTaxiDestinations();

    Tokens tokens = StrSplit(values, " ");

    for (Tokens::iterator iter = tokens.begin(); iter != tokens.end(); ++iter)
    {
        uint32 node = uint32(atol(iter->c_str()));
        AddTaxiDestination(node);
    }

    if (m_TaxiDestinations.empty())
        return true;

    // Check integrity
    if (m_TaxiDestinations.size() < 2)
        return false;

    for (size_t i = 1; i < m_TaxiDestinations.size(); ++i)
    {
        uint32 cost;
        uint32 path;
        sObjectMgr.GetTaxiPath(m_TaxiDestinations[i - 1], m_TaxiDestinations[i], path, cost);
        if (!path)
            return false;
    }

    // can't load taxi path without mount set (quest taxi path?)
    return sObjectMgr.GetTaxiMountDisplayId(GetTaxiSource(), team, true) != 0;
}

std::string PlayerTaxi::SaveTaxiDestinationsToString() const
{
    if (m_TaxiDestinations.size() < 2)
        return "";

    std::ostringstream ss;

    // save only the current path
    for (size_t i = 0; i < 2; ++i)
        ss << m_TaxiDestinations[i] << " ";

    return ss.str();
}

uint32 PlayerTaxi::GetCurrentTaxiPath() const
{
    if (m_TaxiDestinations.size() < 2)
        return 0;

    uint32 path;
    uint32 cost;

    sObjectMgr.GetTaxiPath(m_TaxiDestinations[0], m_TaxiDestinations[1], path, cost);

    return path;
}

uint32 PlayerTaxi::GetCurrentTaxiCost() const
{
    if (m_TaxiDestinations.size() < 2)
        return 0;

    uint32 path;
    uint32 cost;

    sObjectMgr.GetTaxiPath(m_TaxiDestinations[0], m_TaxiDestinations[1], path, cost);

    return (uint32)ceil(cost * m_discount);
}

std::ostringstream& operator<< (std::ostringstream& ss, PlayerTaxi const& taxi)
{
    for (uint32 i : taxi.m_taximask)
        ss << i << " ";
    return ss;
}

SpellModifier::SpellModifier(SpellModOp _op, SpellModType _type, int32 _value, SpellEntry const* spellEntry, SpellEffectIndex eff, int16 _charges /*= 0*/) :
    op(_op), type(_type), charges(_charges), value(_value), spellId(spellEntry->Id), ownerAura(nullptr)
{
    mask = sSpellMgr.GetSpellAffectMask(spellEntry->Id, eff);
}

SpellModifier::SpellModifier(SpellModOp _op, SpellModType _type, int32 _value, Aura* aura, int16 _charges /*= 0*/) :
    op(_op), type(_type), charges(_charges), value(_value), spellId(aura->GetId()), ownerAura(aura)
{
    mask = sSpellMgr.GetSpellAffectMask(aura->GetId(), aura->GetEffIndex());
}

bool SpellModifier::isAffectedOnSpell(SpellEntry const* spell) const
{
    SpellEntry const* affect_spell = sSpellMgr.GetSpellEntry(spellId);
    // False if affect_spell == nullptr or spellFamily not equal
    if (!affect_spell || affect_spell->SpellFamilyName != spell->SpellFamilyName)
        return false;
    return spell->IsFitToFamilyMask(mask);
}

//== TradeData =================================================

TradeData* TradeData::GetTraderData() const
{
    return m_trader->GetTradeData();
}

Item* TradeData::GetItem(TradeSlots slot) const
{
    return m_items[slot] ? m_player->GetItemByGuid(m_items[slot]) : nullptr;
}

bool TradeData::HasItem(ObjectGuid item_guid) const
{
    for (const auto& item : m_items)
        if (item == item_guid)
            return true;
    return false;
}

TradeSlots TradeData::GetTradeSlotForItem(ObjectGuid itemGuid) const
{
    for (uint8 i = 0; i < TRADE_SLOT_COUNT; ++i)
        if (m_items[i] == itemGuid)
            return TradeSlots(i);

    return TRADE_SLOT_INVALID;
}

void TradeData::FillTransactionLog(TransactionPart& log) const
{
    log.money = m_money;
    log.lowGuid = m_player->GetGUIDLow();
    log.spell = m_spell;
    for (int i = 0; i < log.MAX_TRANSACTION_ITEMS && i < TRADE_SLOT_COUNT; ++i)
    {
        if (Item* item = GetItem(TradeSlots(i)))
        {
            log.itemsCount[i] = item->GetCount();
            log.itemsEntries[i] = item->GetEntry();
            log.itemsGuid[i] = item->GetGUIDLow();
        }
    }
}

Item* TradeData::GetSpellCastItem() const
{
    return m_spellCastItem ?  m_player->GetItemByGuid(m_spellCastItem) : nullptr;
}

void TradeData::SetItem(TradeSlots slot, Item* item)
{
    ObjectGuid itemGuid = item ? item->GetObjectGuid() : ObjectGuid();

    if (m_items[slot] == itemGuid)
        return;

    m_items[slot] = itemGuid;

    SetAccepted(false);
    GetTraderData()->SetAccepted(false);

    Update();

    // need remove possible trader spell applied to changed item
    if (slot == TRADE_SLOT_NONTRADED)
        GetTraderData()->SetSpell(0);

    // need remove possible player spell applied (possible move reagent)
    SetSpell(0);
}

void TradeData::SetSpell(uint32 spellId, Item* castItem /*= nullptr*/)
{
    ObjectGuid itemGuid = castItem ? castItem->GetObjectGuid() : ObjectGuid();

    if (m_spell == spellId && m_spellCastItem == itemGuid)
        return;

    m_spell = spellId;
    m_spellCastItem = itemGuid;

    SetAccepted(false);
    GetTraderData()->SetAccepted(false);

    Update(true);                                           // send spell info to item owner
    Update(false);                                          // send spell info to caster self
}

void TradeData::SetMoney(uint32 money)
{
    if (m_money == money)
        return;

    m_money = money;

    SetAccepted(false);
    GetTraderData()->SetAccepted(false);

    Update();
}

void TradeData::Update(bool for_trader /*= true*/)
{
    if (for_trader)
        m_trader->GetSession()->SendUpdateTrade(true);      // player state for trader
    else
        m_player->GetSession()->SendUpdateTrade(false);     // player state for player
}

void TradeData::SetAccepted(bool state, bool crosssend /*= false*/)
{
    m_accepted = state;

    if (!state)
    {
        if (crosssend)
            m_trader->GetSession()->SendTradeStatus(TRADE_STATUS_BACK_TO_TRADE);
        else
            m_player->GetSession()->SendTradeStatus(TRADE_STATUS_BACK_TO_TRADE);
    }
}

//== Player ====================================================

Player::Player(WorldSession* session) : Unit(),
    m_mover(this), m_camera(this), m_reputationMgr(this),
    m_enableInstanceSwitch(true), m_currentTicketCounter(0), m_castingSpell(0), m_repopAtGraveyardPending(false),
    m_honorMgr(this), m_bNextRelocationsIgnored(0), m_personalXpRate(-1.0f), m_isStandUpScheduled(false), m_foodEmoteTimer(0)
{
    m_objectType |= TYPEMASK_PLAYER;
    m_objectTypeId = TYPEID_PLAYER;

    m_valuesCount = PLAYER_END;

    m_honorMgr.ClearHonorData();

    m_isActiveObject = true;                                // player is always active object

    m_session = session;

    m_ExtraFlags = 0;
    if (GetSession()->GetSecurity() > SEC_PLAYER)
    {
        m_currentTicketCounter = sTicketMgr->GetLastTicketId();
        SetAcceptTicket(true);
    }

    // players always accept
    if (GetSession()->GetSecurity() == SEC_PLAYER)
        SetAcceptWhispers(true);

    m_comboPoints = 0;

    m_usedTalentCount = 0;

    m_modManaRegen = 0;
    m_modManaRegenInterrupt = 0;
    m_carryHealthRegen = 0;
    for (float & s : m_SpellCritPercentage)
        s = 0.0f;
    m_regenTimer = 0;
    m_weaponChangeTimer = 0;

    m_zoneUpdateId = 0;
    m_zoneUpdateTimer = 0;

    m_areaUpdateId = 0;

    m_nextSave = sWorld.getConfig(CONFIG_UINT32_INTERVAL_SAVE);

    // randomize first save time in range [CONFIG_UINT32_INTERVAL_SAVE] around [CONFIG_UINT32_INTERVAL_SAVE]
    // this must help in case next save after mass player load after server startup
    m_nextSave = urand(m_nextSave / 2, m_nextSave * 3 / 2);

    ClearResurrectRequestData();

    memset(m_items, 0, sizeof(Item*)*PLAYER_SLOTS_COUNT);

    // group is initialized in the reference constructor
    SetGroupInvite(nullptr);
    m_groupUpdateMask = 0;
    m_auraUpdateMask = 0;

    duel = nullptr;

    m_GuildIdInvited = 0;

    m_atLoginFlags = AT_LOGIN_NONE;

    mSemaphoreTeleport_Near = false;
    mSemaphoreTeleport_Far = false;
    mPendingFarTeleport = false;

    m_DelayedOperations = 0;
    m_bCanDelayTeleport = false;
    m_bHasDelayedTeleport = false;
    m_bHasBeenAliveAtDelayedTeleport = true;                // overwrite always at setup teleport data, so not used infact
    m_teleport_options = 0;

    m_trade = nullptr;

    PlayerTalkClass = new PlayerMenu(GetSession());
    m_currentBuybackSlot = BUYBACK_SLOT_START;

    m_lastLiquid = nullptr;

    m_drunkTimer = 0;
    m_drunk = 0;
    m_restTime = 0;
    m_deathTimer = 0;
    m_deathExpireTime = 0;

    m_swingErrorMsg = ATTACK_RESULT_OK;

    for (auto& j : m_bgBattleGroundQueueID)
    {
        j.bgQueueTypeId  = BATTLEGROUND_QUEUE_NONE;
        j.invitedToInstance = 0;
    }

    m_loginTime = time(nullptr);
    m_createTime = m_loginTime;
    m_lastTick = m_loginTime;
    m_WeaponProficiency = 0;
    m_ArmorProficiency = 0;
    m_canParry = false;
    m_canBlock = false;
    m_canDualWield = false;
    m_ammoDPS = 0.0f;

    m_temporaryUnsummonedPetNumber = 0;

    ////////////////////Rest System/////////////////////
    m_timeInnEnter = 0;
    m_innTriggerId = 0;
    m_restBonus = 0;
    m_restType = REST_TYPE_NO;
    ////////////////////Rest System/////////////////////

    m_resetTalentsMultiplier = 0;
    m_resetTalentsTime = 0;
    m_itemUpdateQueueBlocked = false;

    m_stableSlots = 0;

    /////////////////// Instance System /////////////////////

    m_HomebindTimer = 0;
    m_InstanceValid = true;

    for (auto& i : m_auraBaseMod)
    {
        i[FLAT_MOD] = 0.0f;
        i[PCT_MOD] = 1.0f;
    }

    // Player summoning
    m_summon_expire = 0;
    m_summon_mapid = 0;
    m_summon_x = 0.0f;
    m_summon_y = 0.0f;
    m_summon_z = 0.0f;

    m_lastFallTime = 0;
    m_lastFallZ = 0;

    m_currentCinematicEntry = 0;

    m_cannotBeDetectedTimer = 0;

    // Phasing
    worldMask = WORLD_DEFAULT_CHAR;
    i_AI = nullptr;
    m_cheatOptions = 0x0;
    m_DbSaveDisabled = false;

    m_lastFromClientCastedSpellID = 0;

    // Anti undermap
    m_undermapPosValid = false;
    session->InitCheatData(this);
    m_petEntry = 0;
    m_petSpell = 0;
    m_areaCheckTimer = 0;
    m_skippedUpdateTime = 0;
    m_DetectInvTimer = 1 * IN_MILLISECONDS;

    // GM variables
    m_gmInvisibilityLevel = session->GetSecurity();

    if (session->GetSecurity() > SEC_MODERATOR)
        m_smartInstanceRebind = true;

    // TODO: remove it
    launched = false;
    xy_speed = 0.0f;

    m_justBoarded = false;

    m_longSightSpell = 0;
    m_longSightRange = 0.0f;
}

Player::~Player()
{
    DeletePacketBroadcaster();

    RemoveAI();
    CleanupsBeforeDelete();

    // Note: buy back item already deleted from DB when player was saved
    for (const auto& item : m_items)
        delete item;

    CleanupChannels();

    delete PlayerTalkClass;

    for (const auto& x : m_ItemSetEff)
         delete x;

    // clean up player-instance binds, may unload some instance saves
    for (const auto& itr : m_boundInstances)
        itr.second.state->RemovePlayer(this);

    // Cleanup delayed teleport if it was not executed before object deletion
    // This shouldn't actually happen, but if someone does a bad we need to
    // clean up anyway
    sMapMgr.CancelDelayedPlayerTeleport(this);

    ASSERT(!m_groupInvite);
}

void Player::CleanupsBeforeDelete()
{
    if (m_uint32Values)                                     // only for fully created Object
    {
        TradeCancel(false);
        DuelComplete(DUEL_FLED);
    }

    Unit::CleanupsBeforeDelete();
}

bool Player::ValidateAppearance(uint8 race, uint8 class_, uint8 gender, uint8 hairID, uint8 hairColor, uint8 faceID, uint8 facialHair, uint8 skinColor, bool create /*=false*/)
{
    // For Skin type is always 0
    CharSectionsEntry const* skinEntry = GetCharSectionEntry(race, SECTION_TYPE_SKIN, gender, 0, skinColor);
    if (!skinEntry)
        return false;

    // Skin Color defined as Face color, too
    CharSectionsEntry const* faceEntry = GetCharSectionEntry(race, SECTION_TYPE_FACE, gender, faceID, skinColor);
    if (!faceEntry)
        return false;

    // Check Hair
    CharSectionsEntry const* hairEntry = GetCharSectionEntry(race, SECTION_TYPE_HAIR, gender, hairID, hairColor);
    if (!hairEntry)
        return false;

    // These combinations don't have an entry of Type SECTION_TYPE_FACIAL_HAIR, exclude them from that check
    bool const excludeCheck = (race == RACE_TAUREN) || (gender == GENDER_FEMALE && race != RACE_NIGHTELF && race != RACE_UNDEAD);
    if (!excludeCheck)
    {
        CharSectionsEntry const* facialHairEntry = GetCharSectionEntry(race, SECTION_TYPE_FACIAL_HAIR, gender, facialHair, hairColor);
        if (!facialHairEntry)
            return false;
    }

    CharacterFacialHairStylesEntry const* entry = GetCharFacialHairEntry(race, gender, facialHair);
    if (!entry)
        return false;

    return true;
}

bool Player::Create(uint32 guidlow, std::string const& name, uint8 race, uint8 class_, uint8 gender, uint8 skin, uint8 face, uint8 hairStyle, uint8 hairColor, uint8 facialHair)
{
    Object::_Create(guidlow, 0, HIGHGUID_PLAYER);

    m_name = name;

    PlayerInfo const* info = sObjectMgr.GetPlayerInfo(race, class_);
    if (!info)
    {
        sLog.outError("Player have incorrect race/class pair. Can't be loaded.");
        return false;
    }

    ChrClassesEntry const* cEntry = sChrClassesStore.LookupEntry(class_);
    if (!cEntry)
    {
        sLog.outError("Class %u not found in DBC (Wrong DBC files?)", class_);
        return false;
    }

    // player store gender in single bit
    if (gender != uint8(GENDER_MALE) && gender != uint8(GENDER_FEMALE))
    {
        sLog.outError("Invalid gender %u at player creating", uint32(gender));
        return false;
    }

    // cleanup inventory related item value fields (its will be filled correctly in _LoadInventory)
    for (uint8 slot = EQUIPMENT_SLOT_START; slot < EQUIPMENT_SLOT_END; ++slot)
    {
        SetGuidValue(PLAYER_FIELD_INV_SLOT_HEAD + (slot * 2), ObjectGuid());
        SetVisibleItemSlot(slot, nullptr);
    }

    for (auto& item : m_items)
        item = nullptr;

    SetLocationMapId(info->mapId);
    Relocate(info->positionX, info->positionY, info->positionZ, info->orientation);

    if (GetMapId() <= 1)
        SetLocationInstanceId(sMapMgr.GetContinentInstanceId(GetMapId(), GetPositionX(), GetPositionY()));
    SetMap(sMapMgr.CreateMap(info->mapId, this));

    uint8 powertype = cEntry->powerType;

    SetFactionForRace(race);

    SetByteValue(UNIT_FIELD_BYTES_0, UNIT_BYTES_0_OFFSET_RACE, race);
    SetByteValue(UNIT_FIELD_BYTES_0, UNIT_BYTES_0_OFFSET_CLASS, class_);
    SetByteValue(UNIT_FIELD_BYTES_0, UNIT_BYTES_0_OFFSET_GENDER, gender);
    SetByteValue(UNIT_FIELD_BYTES_0, UNIT_BYTES_0_OFFSET_POWER_TYPE, powertype);

    InitPlayerDisplayIds();                                       // model, scale and model data

    // is it need, only in pre-2.x used and field byte removed later?
    if (powertype == POWER_RAGE || powertype == POWER_MANA)
        SetByteValue(UNIT_FIELD_BYTES_1, UNIT_BYTES_1_OFFSET_PET_LOYALTY, 0xEE);

    SetByteValue(UNIT_FIELD_BYTES_2, UNIT_BYTES_2_OFFSET_MISC_FLAGS, UNIT_BYTE2_FLAG_UNK3 | UNIT_BYTE2_FLAG_UNK5 | UNIT_BYTE2_FLAG_PVP);
    SetUInt32Value(UNIT_FIELD_FLAGS, UNIT_FLAG_PLAYER_CONTROLLED);

    // fix cast time showed in spell tooltip on client
#if SUPPORTED_CLIENT_BUILD >= CLIENT_BUILD_1_12_1
    SetFloatValue(UNIT_MOD_CAST_SPEED, 1.0f);
#else
    SetInt32Value(UNIT_MOD_CAST_SPEED, 0);
#endif

#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_9_4
    SetInt32Value(PLAYER_FIELD_WATCHED_FACTION_INDEX, -1);  // -1 is default value
#endif

    SetByteValue(PLAYER_BYTES, 0, skin);
    SetByteValue(PLAYER_BYTES, 1, face);
    SetByteValue(PLAYER_BYTES, 2, hairStyle);
    SetByteValue(PLAYER_BYTES, 3, hairColor);

    SetByteValue(PLAYER_BYTES_2, 0, facialHair);
    SetByteValue(PLAYER_BYTES_2, 3, REST_STATE_NORMAL);

    SetUInt16Value(PLAYER_BYTES_3, 0, gender);              // only GENDER_MALE/GENDER_FEMALE (1 bit) allowed, drunk state = 0
    SetByteValue(PLAYER_BYTES_3, 3, 0);                     // BattlefieldArenaFaction (0 or 1)

    SetUInt32Value(PLAYER_GUILDID, 0);
    SetUInt32Value(PLAYER_GUILDRANK, 0);
    SetUInt32Value(PLAYER_GUILD_TIMESTAMP, 0);

    // set starting level
    if (GetSession()->GetSecurity() >= SEC_MODERATOR)
        SetUInt32Value(UNIT_FIELD_LEVEL, sWorld.getConfig(CONFIG_UINT32_START_GM_LEVEL));
    else
        SetUInt32Value(UNIT_FIELD_LEVEL, sWorld.getConfig(CONFIG_UINT32_START_PLAYER_LEVEL));

    SetUInt32Value(PLAYER_FIELD_COINAGE, sWorld.getConfig(CONFIG_UINT32_START_PLAYER_MONEY));

    // Played time
    m_lastTick = time(nullptr);
    m_playedTime[PLAYED_TIME_TOTAL] = 0;
    m_playedTime[PLAYED_TIME_LEVEL] = 0;

    // base stats and related field values
    InitStatsForLevel();
    InitTaxiNodes();
    InitTalentForLevel();
    InitPrimaryProfessions();                               // to max set before any spell added
    m_reputationMgr.LoadFromDB(nullptr);

    // apply original stats mods before spell loading or item equipment that call before equip _RemoveStatsMods()
    UpdateMaxHealth();                                      // Update max Health (for add bonus from stamina)
    SetHealth(GetMaxHealth());

    if (GetPowerType() == POWER_MANA)
    {
        UpdateMaxPower(POWER_MANA);                         // Update max Mana (for add bonus from intellect)
        SetPower(POWER_MANA, GetMaxPower(POWER_MANA));
    }

    // original spells
    LearnDefaultSpells();

    // original items
    AddStartingItems();

    // Phasing
    SetWorldMask(WORLD_DEFAULT_CHAR);

    return true;
}

void Player::AddStartingItems()
{
    PlayerInfo const* info = sObjectMgr.GetPlayerInfo(GetRace(), GetClass());
    if (!info)
    {
        sLog.outError("Player have incorrect race/class pair. Can't add starting items.");
        return;
    }

    // Starting items.
    for (const auto& item_id_itr : info->item)
        StoreNewItemInBestSlots(item_id_itr.item_id, item_id_itr.item_amount);

    // bags and main-hand weapon must equipped at this moment
    // now second pass for not equipped (offhand weapon/shield if it attempt equipped before main-hand weapon)
    // or ammo not equipped in special bag
    for (int i = INVENTORY_SLOT_ITEM_START; i < INVENTORY_SLOT_ITEM_END; ++i)
    {
        if (Item* pItem = GetItemByPos(INVENTORY_SLOT_BAG_0, i))
        {
            uint16 eDest;
            // equip offhand weapon/shield if it attempt equipped before main-hand weapon
            uint8 msg = CanEquipItem(NULL_SLOT, eDest, pItem, false);
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
                    pItem = StoreItem(sDest, pItem, true);
                }

                // if  this is ammo then use it
                msg = CanUseAmmo(pItem->GetEntry());
                if (msg == EQUIP_ERR_OK)
                    SetAmmo(pItem->GetEntry());
            }
        }
    }
    // all item positions resolved
}

bool Player::StoreNewItemInBestSlots(uint32 itemId, uint32 amount, uint32 enchantId)
{
    DEBUG_LOG("STORAGE: Creating initial item, itemId = %u, count = %u", itemId, amount);

    // attempt equip by one
    while (amount > 0)
    {
        uint16 eDest;
        uint8 msg = CanEquipNewItem(NULL_SLOT, eDest, itemId, false);
        if (msg != EQUIP_ERR_OK)
            break;

        if (Item* pItem = EquipNewItem(eDest, itemId, true))
        {
            bool needReApplyItemMods = false;
            if (enchantId)
            {
                pItem->ClearEnchantment(PERM_ENCHANTMENT_SLOT);
                pItem->SetEnchantment(PERM_ENCHANTMENT_SLOT, enchantId, 0, 0);
                needReApplyItemMods = true;
            }
            if (uint32 randomPropertyId = Item::GenerateItemRandomPropertyId(itemId))
            {
                pItem->SetItemRandomProperties(randomPropertyId);
                needReApplyItemMods = true;
            }
            // Since the item is enchanted after it is equipped, item mods need to be re-applied.
            if (needReApplyItemMods)
            {
                uint8 slot = eDest & 255;
                _ApplyItemMods(pItem, slot, false);
                _ApplyItemMods(pItem, slot, true);
            }

            AutoUnequipOffhandIfNeed();

            if ((amount > 1) && (amount <= pItem->GetProto()->GetMaxStackSize()))
            {
                pItem->SetCount(amount);
                amount = 0;
                break;
            }
        }
        
        --amount;
    }

    if (amount == 0)
        return true;                                        // equipped

    // attempt store
    ItemPosCountVec sDest;
    // store in main bag to simplify second pass (special bags can be not equipped yet at this moment)
    uint8 msg = CanStoreNewItem(INVENTORY_SLOT_BAG_0, NULL_SLOT, sDest, itemId, amount);
    if (msg == EQUIP_ERR_OK)
    {
        if (Item* pItem = StoreNewItem(sDest, itemId, true, Item::GenerateItemRandomPropertyId(itemId)))
        {
            if (enchantId)
            {
                pItem->ClearEnchantment(PERM_ENCHANTMENT_SLOT);
                pItem->SetEnchantment(PERM_ENCHANTMENT_SLOT, enchantId, 0, 0);
            }
        }
        return true;                                        // stored
    }

    // item can't be added
    sLog.outError("STORAGE: Can't equip or store initial item %u for race %u class %u , error msg = %u", itemId, GetRace(), GetClass(), msg);
    return false;
}

// helper function, mainly for script side, but can be used for simple task in mangos also.
Item* Player::StoreNewItemInInventorySlot(uint32 itemId, uint32 amount)
{
    ItemPosCountVec vDest;

    uint8 msg = CanStoreNewItem(INVENTORY_SLOT_BAG_0, NULL_SLOT, vDest, itemId, amount);

    if (msg == EQUIP_ERR_OK)
    {
        if (Item* pItem = StoreNewItem(vDest, itemId, true, Item::GenerateItemRandomPropertyId(itemId)))
            return pItem;
    }

    return nullptr;
}

void Player::SatisfyItemRequirements(ItemPrototype const* pItem)
{
    if (GetLevel() < pItem->RequiredLevel)
    {
        GiveLevel(pItem->RequiredLevel);
        InitTalentForLevel();
        SetUInt32Value(PLAYER_XP, 0);
    }

    // Set required honor rank
    auto playerRank = (sWorld.getConfig(CONFIG_BOOL_ACCURATE_PVP_EQUIP_REQUIREMENTS) && sWorld.GetWowPatch() < WOW_PATCH_106) ? m_honorMgr.GetRank().rank : m_honorMgr.GetHighestRank().rank;
    if (playerRank < (uint8)pItem->RequiredHonorRank)
    {
        HonorRankInfo rank;
        rank.rank = pItem->RequiredHonorRank;
        m_honorMgr.CalculateRankInfo(rank);
        m_honorMgr.SetHighestRank(rank);
        m_honorMgr.SetRank(rank);
    }

    // Set required reputation
    if (pItem->RequiredReputationFaction && pItem->RequiredReputationRank)
        if (FactionEntry const* pFaction = sObjectMgr.GetFactionEntry(pItem->RequiredReputationFaction))
            if (GetReputationMgr().GetRank(pFaction) < pItem->RequiredReputationRank)
                GetReputationMgr().SetReputation(pFaction, GetReputationMgr().GetRepPointsToRank(ReputationRank(pItem->RequiredReputationRank)));

    // Learn required spell
    if (pItem->RequiredSpell && !HasSpell(pItem->RequiredSpell))
        LearnSpell(pItem->RequiredSpell, false, false);

    // Learn required profession
    if (pItem->RequiredSkill && (!HasSkill(pItem->RequiredSkill) || (GetSkill(pItem->RequiredSkill, false, false) <  pItem->RequiredSkillRank)))
        SetSkill(pItem->RequiredSkill, pItem->RequiredSkillRank, 300);

    // Learn Dual Wield Specialization
    if (pItem->InventoryType == INVTYPE_WEAPONOFFHAND && !HasSpell(674))
        LearnSpell(674, false, false);

    // Learn required proficiency
    if (uint32 proficiencySpellId = pItem->GetProficiencySpell())
        if (!HasSpell(proficiencySpellId))
            LearnSpell(proficiencySpellId, false, false);
}

uint32 Player::EnvironmentalDamage(EnvironmentalDamageType type, uint32 damage)
{
    if (!IsAlive() || IsGameMaster())
        return 0;

    // Absorb, resist some environmental damage type
    uint32 absorb = 0;
    int32 resist = 0;

    if ((type == DAMAGE_LAVA) || (type == DAMAGE_FIRE))
        CalculateDamageAbsorbAndResist(this, SPELL_SCHOOL_MASK_FIRE, DIRECT_DAMAGE, damage, &absorb, &resist, nullptr);
    else if (type == DAMAGE_SLIME)
        CalculateDamageAbsorbAndResist(this, SPELL_SCHOOL_MASK_NATURE, DIRECT_DAMAGE, damage, &absorb, &resist, nullptr);

    uint32 const bonus = (resist < 0 ? uint32(std::abs(resist)) : 0);
    damage += bonus;
    uint32 const malus = (resist > 0 ? (absorb + uint32(resist)) : absorb);
    damage = (damage <= malus ? 0 : (damage - malus));

    DealDamageMods(this, damage, &absorb);

    SendEnvironmentalDamageLog(type, damage, absorb, resist);

    uint32 final_damage = DealDamage(this, damage, nullptr, SELF_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, nullptr, false);

    if (type == DAMAGE_FALL && !IsAlive())                  // DealDamage not apply item durability loss at self damage
    {
        DEBUG_LOG("We are fall to death, loosing 10 percents durability");
        DurabilityLossAll(0.10f, false);
        // durability lost message
        WorldPacket data2(SMSG_DURABILITY_DAMAGE_DEATH, 0);
        GetSession()->SendPacket(&data2);
    }

    return final_damage;
}

///The player sobers by 256 every 10 seconds
void Player::HandleSobering()
{
    m_drunkTimer = 0;

    uint32 drunk = (m_drunk <= 256) ? 0 : (m_drunk - 256);
    SetDrunkValue(drunk);
}

DrunkenState Player::GetDrunkenstateByValue(uint16 value)
{
    if (value >= 23000)
        return DRUNKEN_SMASHED;
    if (value >= 12800)
        return DRUNKEN_DRUNK;
    if (value & 0xFFFE)
        return DRUNKEN_TIPSY;
    return DRUNKEN_SOBER;
}

void Player::SetDrunkValue(uint16 newDrunkenValue, uint32 itemId)
{
    m_drunk = newDrunkenValue;
    SetUInt16Value(PLAYER_BYTES_3, 0, uint16(GetGender()) | (m_drunk & 0xFFFE));

    uint32 newDrunkenState = Player::GetDrunkenstateByValue(m_drunk);

    // special drunk invisibility detection
    if (newDrunkenState >= DRUNKEN_DRUNK)
        m_detectInvisibilityMask |= (1 << 6);
    else
        m_detectInvisibilityMask &= ~(1 << 6);
}

uint32 Player::GetWaterBreathingInterval() const
{
    return uint32(sWorld.getConfig(CONFIG_UINT32_MIRRORTIMER_BREATH_MAX) * IN_MILLISECONDS * m_environmentBreathingMultiplier);
}

void Player::SetWaterBreathingIntervalMultiplier(float multiplier)
{
    m_environmentBreathingMultiplier = multiplier;

    if (const uint32 interval = GetWaterBreathingInterval())
    {
        m_mirrorTimers[MirrorTimer::BREATH].SetDuration(interval);
        m_mirrorTimers[MirrorTimer::BREATH].SetScale(IsUnderwater() ? -1 : 10);
    }
    else
        m_mirrorTimers[MirrorTimer::BREATH].SetScale(10);
}

void Player::SetEnvironmentFlags(EnvironmentFlags flags, bool apply)
{
    if (bool(m_environmentFlags & flags) == apply)
        return;

    if (apply)
        m_environmentFlags |= flags;
    else
        m_environmentFlags &= ~flags;

    // On liquid in/out
    if (flags & ENVIRONMENT_MASK_IN_LIQUID)
    {
        // move player's guid into HateOfflineList of those mobs
        // which can't swim and move guid back into ThreatList when
        // on surface.
        // TODO: exist also swimming mobs, and function must be symmetric to enter/leave water
        GetHostileRefManager().updateThreatTables();
    }

    // Remove auras that need land or water
    if (flags & ENVIRONMENT_FLAG_HIGH_LIQUID)
    {
        InterruptSpellsWithChannelFlags(apply ? CHANNEL_FLAG_ABOVE_WATER_CANCELS : CHANNEL_FLAG_UNDER_WATER_CANCELS);
        RemoveAurasWithInterruptFlags(apply ? AURA_INTERRUPT_FLAG_NOT_ABOVEWATER : AURA_INTERRUPT_FLAG_NOT_UNDERWATER);
    }

    // On moving in/out high sea area: affect fatigue timer
    if (flags & ENVIRONMENT_FLAG_HIGH_SEA)
        m_mirrorTimers[MirrorTimer::FATIGUE].SetScale(apply ? -1 : 10);

    // On swimming down/up liquid surface level: affect breath timer
    if (flags & ENVIRONMENT_FLAG_UNDERWATER)
        m_mirrorTimers[MirrorTimer::BREATH].SetScale((apply && GetWaterBreathingInterval()) ? -1 : 10);

    // On moving in/out hazardous liquids: affect environmental timer
    if ((flags & ENVIRONMENT_MASK_LIQUID_HAZARD))
        m_mirrorTimers[MirrorTimer::ENVIRONMENTAL].SetScale((m_environmentFlags & ENVIRONMENT_MASK_LIQUID_HAZARD) ? -1 : 10);
}

void Player::SendMirrorTimerStart(uint32 type, uint32 remaining, uint32 duration, int32 scale, bool paused/* = false*/, uint32 spellId/* = 0*/)
{
    WorldPacket data(SMSG_START_MIRROR_TIMER, (4 + 4 + 4 + 4 + 1 + 4));
    data << uint32(type);
    data << uint32(remaining);
    data << uint32(duration);
    data << int32(scale);
    data << uint8(paused);
    data << uint32(spellId);
    GetSession()->SendPacket(&data);
}

void Player::SendMirrorTimerStop(uint32 type)
{
    WorldPacket data(SMSG_STOP_MIRROR_TIMER, 4);
    data << uint32(type);
    GetSession()->SendPacket(&data);
}

void Player::SendMirrorTimerPause(uint32 type, bool state)
{
    // Note: Default UI handler for this is bugged, args dont match
    // Gotta do a full update with SMSG_START_MIRROR_TIMER to avoid lua errors
    WorldPacket data(SMSG_PAUSE_MIRROR_TIMER, (4 + 1));
    data << uint32(type);
    data << uint8(state);
    GetSession()->SendPacket(&data);
}

void Player::FreezeMirrorTimers(bool state)
{
    for (auto& timer : m_mirrorTimers)
    {
        if (!timer.GetSpellId())
            timer.SetFrozen(state);
    }
}

void Player::SendMirrorTimers(bool forced/*= false*/)
{
    for (auto& timer : m_mirrorTimers)
    {
        if (timer.GetType() >= MirrorTimer::NUM_CLIENT_TIMERS)
            return;

        MirrorTimer::Status status = timer.FetchStatus();

        if (forced && timer.IsActive())
            status = MirrorTimer::FULL_UPDATE;

        switch (status)
        {
            case MirrorTimer::FULL_UPDATE:
                SendMirrorTimerStart(timer.GetType(), timer.GetRemaining(), timer.GetDuration(), timer.GetScale(), timer.IsFrozen(), timer.GetSpellId());
                break;
            case MirrorTimer::STATUS_UPDATE:
                if (!timer.IsActive())
                    SendMirrorTimerStop(timer.GetType());
                else
                {
                    // NOTE: Replaced with full resend due to clientside UI bug, details inside
                    // SendMirrorTimerPause(timer.GetType(), timer.IsFrozen());
                    SendMirrorTimerStart(timer.GetType(), timer.GetRemaining(), timer.GetDuration(), timer.GetScale(), timer.IsFrozen(), timer.GetSpellId());
                }
                break;
            default:
                break;
        }
    }
}

void Player::UpdateMirrorTimers(uint32 diff, bool send/* = true*/)
{
    for (auto& timer : m_mirrorTimers)
    {
        const MirrorTimer::Type type = timer.GetType();
        const bool active = timer.IsActive();

        if (active || CheckMirrorTimerActivation(type))
        {
            if (CheckMirrorTimerDeactivation(type))
                 m_mirrorTimers[type].Stop();
            else
            {
                if (active)
                {
                    if (timer.GetSpellId())
                    {
                        if (auto buff = GetMirrorTimerBuff(type))
                            m_mirrorTimers[type].SetRemaining(uint32(std::abs(buff->GetAuraDuration())));
                        else
                            m_mirrorTimers[type].Stop();
                    }

                    if (!timer.Update(diff))
                        OnMirrorTimerExpirationPulse(type);
                }
                else
                {
                    if (auto buff = GetMirrorTimerBuff(type))
                        m_mirrorTimers[type].Start(uint32(std::abs(buff->GetAuraDuration())), uint32(std::abs(buff->GetAuraMaxDuration())), buff->GetId());
                    else
                        m_mirrorTimers[type].Start(GetMirrorTimerMaxDuration(type));
                }
            }
        }
    }

    if (send)
        SendMirrorTimers();
}

bool Player::CheckMirrorTimerActivation(MirrorTimer::Type timer) const
{
    switch (timer)
    {
        case MirrorTimer::FATIGUE:
            return (IsInHighSea() && !IsTaxiFlying() && !GetTransport());
        case MirrorTimer::BREATH:
            return (IsUnderwater() && GetWaterBreathingInterval());
        case MirrorTimer::FEIGNDEATH:
            return (IsFeigningDeath());
        case MirrorTimer::ENVIRONMENTAL:
            return ((m_environmentFlags & ENVIRONMENT_MASK_LIQUID_HAZARD) && !(m_lastLiquid && m_lastLiquid->SpellId));
        default:
            return false;
    }
}

bool Player::CheckMirrorTimerDeactivation(MirrorTimer::Type timer) const
{
    // Spirit of redemption: just drop all mirror timers at once
    if (GetShapeshiftForm() == FORM_SPIRITOFREDEMPTION)
        return true;

    switch (timer)
    {
        case MirrorTimer::FATIGUE:
            return (!(m_environmentFlags & ENVIRONMENT_FLAG_LIQUID) || (!IsAlive() && !HasFlag(PLAYER_FLAGS, PLAYER_FLAGS_GHOST)));
        case MirrorTimer::BREATH:
            return (!(m_environmentFlags & ENVIRONMENT_FLAG_LIQUID) || !IsAlive());
        case MirrorTimer::FEIGNDEATH:
            return (!IsFeigningDeath());
        case MirrorTimer::ENVIRONMENTAL:
            return (!(m_environmentFlags & ENVIRONMENT_FLAG_LIQUID) || !IsAlive());
        default:
            return false;
    }
}
void Player::OnMirrorTimerExpirationPulse(MirrorTimer::Type timer)
{
    switch (timer)
    {
        case MirrorTimer::FATIGUE:
            if (IsAlive())                                      // Deal damage to living player
                EnvironmentalDamage(DAMAGE_EXHAUSTED, ((GetMaxHealth() / 5) + urand(0, (GetLevel() - 1))));
            else if (HasFlag(PLAYER_FLAGS, PLAYER_FLAGS_GHOST)) // Teleport ghost to graveyard
                RepopAtGraveyard();
            break;
        case MirrorTimer::BREATH:
            // TODO: Check this formula
            EnvironmentalDamage(DAMAGE_DROWNING, ((GetMaxHealth() / 5) + urand(0, (GetLevel() - 1))));
            break;
        case MirrorTimer::ENVIRONMENTAL:
            // TODO: Check these formulas
            if (IsInMagma())
                EnvironmentalDamage(DAMAGE_LAVA, urand(600, 700));
            // FIXME: Need to skip slime damage in Undercity, maybe someone can find better way to handle environmental damage
            //if (IsInSlime() && m_zoneUpdateId != 1497)
            //    EnvironmentalDamage(DAMAGE_SLIME, urand(600, 700));
            break;
        case MirrorTimer::FEIGNDEATH:
            // Vanilla: kill player on feigning death for too long
            DealDamage(this, GetHealth(), nullptr, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, nullptr, false);
            break;
        default:
            return;
    }
}
uint32 Player::GetMirrorTimerMaxDuration(MirrorTimer::Type timer) const
{
    switch (timer)
    {
        case MirrorTimer::FATIGUE:
            return (sWorld.getConfig(CONFIG_UINT32_MIRRORTIMER_FATIGUE_MAX) * IN_MILLISECONDS);
        case MirrorTimer::BREATH:
            return GetWaterBreathingInterval();
        case MirrorTimer::FEIGNDEATH:
            return m_mirrorTimers[MirrorTimer::FEIGNDEATH].GetDuration();
        case MirrorTimer::ENVIRONMENTAL:
            return (sWorld.getConfig(CONFIG_UINT32_MIRRORTIMER_ENVIRONMENTAL_MAX) * IN_MILLISECONDS);
        default:
            return 0;
    }
}
SpellAuraHolder const* Player::GetMirrorTimerBuff(MirrorTimer::Type timer) const
{
    switch (timer)
    {
        case MirrorTimer::FEIGNDEATH:
        {
            SpellAuraHolder const* buff = nullptr;
            if (IsFeigningDeath())
            {
                for (auto aura : GetAurasByType(SPELL_AURA_FEIGN_DEATH))
                {
                    if (auto holder = aura->GetHolder())
                    {
                        if (!buff || holder->GetAuraMaxDuration() > buff->GetAuraMaxDuration())
                            buff = holder;
                    }
                }
            }
            return buff;
        }
        default:
            return nullptr;
    }
}

bool Player::IsCityProtector() { return m_ExtraFlags & PLAYER_EXTRA_CITY_PROTECTOR; }

void Player::SetCityTitle()
{
    SetByteValue(PLAYER_BYTES_3, 2, GetRace());
    m_ExtraFlags |= PLAYER_EXTRA_CITY_PROTECTOR;
}

void Player::RemoveCityTitle()
{
    SetByteValue(PLAYER_BYTES_3, 2, 0);
    m_ExtraFlags &= ~PLAYER_EXTRA_CITY_PROTECTOR;
}

AutoAttackCheckResult Player::CanAutoAttackTarget(Unit const* pVictim) const
{
    if (!IsValidAttackTarget(pVictim))
        return ATTACK_RESULT_FRIENDLY_TARGET;

    return Unit::CanAutoAttackTarget(pVictim);
}

void Player::Update(uint32 update_diff, uint32 p_time)
{
    if (!IsInWorld())
        return;

    UpdateMirrorTimers(update_diff);

    //used to implement delayed far teleports
    SetCanDelayTeleport(true);
    Unit::Update(update_diff, p_time);
    if (i_AI)
        i_AI->UpdateAI(p_time);
    SetCanDelayTeleport(false);

    time_t now = time(nullptr);

    UpdatePvPFlagTimer(update_diff);

    UpdatePvPContestedFlagTimer(update_diff);

    // Delay delete duel
    if (duel && duel->finished)
    {
        delete duel;
        duel = nullptr;
    }
    UpdateDuelFlag(now);

    CheckDuelDistance(now);

    // Handle detect stealth units
    if (m_DetectInvTimer > 0)
    {
        if (update_diff >= m_DetectInvTimer)
        {
            HandleStealthedUnitsDetection();
            m_DetectInvTimer = 2000;
        }
        else
            m_DetectInvTimer -= update_diff;
    }

    // Update items that have just a limited lifetime
    if (now > m_lastTick)
        UpdateItemDuration(uint32(now - m_lastTick));

    if (!m_timedquests.empty())
    {
        QuestSet::iterator iter = m_timedquests.begin();
        while (iter != m_timedquests.end())
        {
            QuestStatusData& q_status = mQuestStatus[*iter];
            if (q_status.m_timer <= update_diff)
            {
                uint32 quest_id  = *iter;
                ++iter;                                     // current iter will be removed in FailQuest
                FailQuest(quest_id);
            }
            else
            {
                q_status.m_timer -= update_diff;
                if (q_status.uState != QUEST_NEW) q_status.uState = QUEST_CHANGED;
                ++iter;
            }
        }
    }

    if (HasUnitState(UNIT_STAT_MELEE_ATTACKING))
    {
        UpdateMeleeAttackingState();

        Unit const* pVictim = GetVictim();
        if (pVictim && !IsNonMeleeSpellCasted(false) && CanReachWithMeleeAutoAttack(pVictim))
            TogglePlayerPvPFlagOnAttackVictim(pVictim);
    }

    if (HasFlag(PLAYER_FLAGS, PLAYER_FLAGS_RESTING))
    {
        if (GetTimeInnEnter() > 0)                          // Freeze update
        {
            time_t time_inn = now - GetTimeInnEnter();
            if (time_inn >= 10)                             // Freeze update
            {
                SetRestBonus(GetRestBonus() + ComputeRest(time_inn));
                UpdateInnerTime(now);
            }
        }
    }

    if (m_weaponChangeTimer > 0)
    {
        if (update_diff >= m_weaponChangeTimer)
            m_weaponChangeTimer = 0;
        else
            m_weaponChangeTimer -= update_diff;
    }

    if (m_zoneUpdateTimer > 0)
    {
        if (update_diff >= m_zoneUpdateTimer)
        {
            uint32 newzone, newarea;
            GetZoneAndAreaId(newzone, newarea);

            if (m_zoneUpdateId != newzone)
                UpdateZone(newzone, newarea);               // also update area
            else
            {
                // use area updates as well
                if (m_areaUpdateId != newarea)
                    UpdateArea(newarea);

                m_zoneUpdateTimer = ZONE_UPDATE_INTERVAL;
            }
        }
        else
            m_zoneUpdateTimer -= update_diff;
    }

    if (m_cannotBeDetectedTimer > 0)
        m_cannotBeDetectedTimer -= update_diff;

    if (IsAlive())
    {
        m_regenTimer -= update_diff;
        HandleFoodEmotes(update_diff);
        RegenerateAll();
    }
    else
    {
        m_regenTimer = 0;
    }

    if (m_deathState == JUST_DIED)
        KillPlayer();

    if (m_nextSave > 0)
    {
        if (update_diff >= m_nextSave)
        {
            // m_nextSave reseted in SaveToDB call
            SaveToDB();
            DETAIL_LOG("Player '%s' (GUID: %u) saved", GetName(), GetGUIDLow());
        }
        else
            m_nextSave -= update_diff;
    }

    // Played time
    if (now > m_lastTick)
    {
        uint32 elapsed = uint32(now - m_lastTick);
        m_playedTime[PLAYED_TIME_TOTAL] += elapsed;        // Total played time
        m_playedTime[PLAYED_TIME_LEVEL] += elapsed;        // Level played time
        m_lastTick = now;
    }

    if (m_drunk)
    {
        m_drunkTimer += update_diff;

        if (m_drunkTimer > 10 * IN_MILLISECONDS)
            HandleSobering();
    }

    // World of Warcraft Client Patch 1.11.0 (2006-06-20)
    // - Release timers have been be removed from instances. This includes 
    //   dungeons, battlegrounds, and raid instances.
#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_10_2
    // not auto-free ghost from body in instances
    if (GetDeathState() == CORPSE  && !GetMap()->Instanceable())
#else
    if (GetDeathState() == CORPSE)
#endif
    {
        if (p_time >= m_deathTimer)
        {
            BuildPlayerRepop();
            ScheduleRepopAtGraveyard();
        }
        else
            m_deathTimer -= p_time;
    }

    UpdateEnchantTime(update_diff);
    UpdateHomebindTime(update_diff);

    if (m_currentCinematicEntry)
        UpdateCinematic(p_time);

    // group update
    SendUpdateToOutOfRangeGroupMembers();

    if (IsHasDelayedTeleport())
        TeleportTo(m_teleport_dest, m_teleport_options, m_teleportRecoverDelayed);
    // Movement extrapolation & cheat computation - only if not already kicked!
    if (!GetSession()->IsConnected())
        return;

    if (m_enableInstanceSwitch && !IsTaxiFlying() && IsInWorld() && GetMap()->IsContinent() && !GetTransport() && !IsBeingTeleported())
    {
        bool transition = false;
        uint16 newInstanceId = sMapMgr.GetContinentInstanceId(GetMap()->GetId(), GetPositionX(), GetPositionY(), &transition);
        if (newInstanceId != GetInstanceId())
            if (!transition || !IsInCombat())
                sMapMgr.ScheduleInstanceSwitch(this, newInstanceId);
    }
    if (IsInWorld())
    {
        if (m_repopAtGraveyardPending && !HasPendingMovementChange())
        {
            RepopAtGraveyard();
            return;
        }

        if (m_areaCheckTimer)
        {
            if (m_areaCheckTimer <= p_time)
            {
                UpdateTerainEnvironmentFlags();
                CheckAreaExploreAndOutdoor();
                LoadMapCellsAround(GetMap()->GetGridActivationDistance());
                m_areaCheckTimer = 0;
            }
            else
                m_areaCheckTimer -= p_time;
        }

        // Anticheat sanction
        std::stringstream reason;
        uint32 cheatAction = GetCheatData()->Update(p_time, reason);
        if (cheatAction)
            GetSession()->ProcessAnticheatAction("MovementAnticheat", reason.str().c_str(), cheatAction, sWorld.getConfig(CONFIG_UINT32_AC_MOVEMENT_BAN_DURATION));
    }
}

void Player::OnDisconnected()
{
    // Anticheat sanction
    std::stringstream reason;
    uint32 cheatAction = GetCheatData()->Finalize(reason);
    if (cheatAction)
        GetSession()->ProcessAnticheatAction("MovementAnticheat", reason.str().c_str(), cheatAction, sWorld.getConfig(CONFIG_UINT32_AC_MOVEMENT_BAN_DURATION));

    if (IsInWorld() && FindMap())
    {
        if (!HasUnitState(UNIT_STAT_FLEEING | UNIT_STAT_CONFUSED | UNIT_STAT_TAXI_FLIGHT))
        {
            float const height = GetMap()->GetHeight(GetPositionX(), GetPositionY(), GetPositionZ());
            if ((GetPositionZ() < height + 0.1f) && !IsInWater())
                SetStandState(UNIT_STAND_STATE_SIT);
        }

        // Update position after bot takes over
        // And remove movement flags, so he doesn't run into the void
        if (!GetMover()->HasUnitState(UNIT_STAT_FLEEING | UNIT_STAT_CONFUSED | UNIT_STAT_TAXI_FLIGHT))
        {
            GetMover()->RemoveUnitMovementFlag(MOVEFLAG_MASK_MOVING_OR_TURN);
            GetMover()->SendHeartBeat(GetMover() != this);
        }

        if (ObjectGuid lootGuid = GetLootGuid())
            GetSession()->DoLootRelease(lootGuid);
    }

    // Player should be leave from channels
    CleanupChannels();
}

void Player::RelocateToLastClientPosition()
{
    if (m_movementInfo.ctime >  0)
    {
        float x = m_movementInfo.pos.x;
        float y = m_movementInfo.pos.y;
        float z = m_movementInfo.pos.z;
        float o = m_movementInfo.pos.o;
        GetMap()->DoPlayerGridRelocation(this, x, y, z, o);
        m_position.x = x;
        m_position.y = y;
        m_position.z = z;
        m_position.o = o;
    }
}

void Player::GetSafePosition(float &x, float &y, float &z, GenericTransport* onTransport) const
{
    if (!onTransport && m_movementInfo.ctime >  0)
    {
        x = m_movementInfo.pos.x;
        y = m_movementInfo.pos.y;
        z = m_movementInfo.pos.z;
    }
    else
        GetPosition(x, y, z, onTransport);
}

// Nostalrius : Phasing
void Player::SetWorldMask(uint32 newMask)
{
    if (GetWorldMask() == newMask)
        return;

    sObjectMgr.SetPlayerWorldMask(GetGUID(), newMask);
    WorldObject::SetWorldMask(newMask);
}

void Player::UpdateCinematic(uint32 diff)
{
    m_cinematicElapsedTime += diff;
    // On check une nouvelle position toutes les secondes.
    if ((m_cinematicLastCheck + 1000) > m_cinematicElapsedTime)
        return;

    m_cinematicLastCheck = m_cinematicElapsedTime;
    Position const* tpPosition = nullptr;
    if ((tpPosition = sObjectMgr.GetCinematicPosition(m_currentCinematicEntry, m_cinematicElapsedTime)) == nullptr)
        tpPosition = sObjectMgr.GetCinematicInitialPosition(m_currentCinematicEntry);

    if (!tpPosition)
        return;

    float x_diff = (m_cinematicStartPos.x - tpPosition->x);
    float y_diff = (m_cinematicStartPos.y - tpPosition->y);
    // Re-tp a la position de fin de la cinematique
    if ((x_diff * x_diff) <= 20 || (y_diff * y_diff) <= 20)
    {
        GetCamera().ResetView();
        return;
    }
    // Sinon on place un petit waypoint sur lequel on met notre camera, pour voir les mobs alentour
    if (Creature* viewPoint = SummonCreature(1, tpPosition->x, tpPosition->y, tpPosition->z - 20, 0.0f, TEMPSUMMON_TIMED_DESPAWN, 5000, true))
        GetCamera().SetView(viewPoint);
}

void Player::CinematicStart(uint32 id)
{
    m_cinematicStartPos.x = GetPositionX();
    m_cinematicStartPos.y = GetPositionY();
    m_cinematicStartPos.z = GetPositionZ();
    m_cinematicStartPos.o = GetOrientation();

    m_cinematicLastCheck = 0;
    m_cinematicElapsedTime = 0;
    m_currentCinematicEntry = id;

    // Pour teleporter a la premiere position de la cinematique
    UpdateCinematic(1);
}

void Player::CinematicEnd()
{
    GetCamera().ResetView();

    m_currentCinematicEntry = 0;
    m_cinematicLastCheck = 0;
    m_cinematicElapsedTime = 0;

    // When you make a new character, current area gets
    // explored after you finish watching the cinematic.
    CheckAreaExploreAndOutdoor();
}

void Player::SetDeathState(DeathState s)
{
    uint32 ressSpellId = 0;

    bool cur = IsAlive();

    if (s == JUST_DIED && cur)
    {
        ResetExtraAttacks(); // Plus de charges de retribution par exemple

        // drunken state is cleared on death
        SetDrunkValue(0);
        // lost combo points at any target (targeted combo points clear in Unit::SetDeathState)
        ClearComboPoints();

        ClearResurrectRequestData();

        // remove form before other mods to prevent incorrect stats calculation
        RemoveAuraTypeOnDeath(SPELL_AURA_MOD_SHAPESHIFT);

        RemovePet(PET_SAVE_REAGENTS);
        Uncharm();

        // remove uncontrolled pets
        RemoveMiniPet();

        if (ObjectGuid lootGuid = GetLootGuid())
            GetSession()->DoLootRelease(lootGuid);

        // save value before aura remove in Unit::SetDeathState
        ressSpellId = GetUInt32Value(PLAYER_SELF_RES_SPELL);

        // passive spell
        if (!ressSpellId)
            ressSpellId = GetResurrectionSpellId();

        if (m_zoneScript)
            m_zoneScript->OnPlayerDeath(this);
    }

    Unit::SetDeathState(s);

    // restore resurrection spell id for player after aura remove
    if (s == JUST_DIED && cur && ressSpellId)
        SetUInt32Value(PLAYER_SELF_RES_SPELL, ressSpellId);

    if (IsAlive() && !cur)
    {
        //clear aura case after resurrection by another way (spells will be applied before next death)
        SetUInt32Value(PLAYER_SELF_RES_SPELL, 0);

        UpdatePvPContested(false, true);
    }
}

void Player::AutoReSummonPet()
{
    uint32 entry = m_petEntry;
    uint32 spell = m_petSpell;
    m_petSpell = m_petEntry = 0;

    if (!IsPlayer() || !entry || !spell)
        return;

    Player* me = ToPlayer();
    SpellEntry const* spellEntry = sSpellMgr.GetSpellEntry(spell);
    if (spellEntry)
    {
        // 1. Ensure that we have the needed items (Soul shard, ...)
        for (uint32 x = 0; x < MAX_SPELL_REAGENTS; ++x)
        {
            if (spellEntry->Reagent[x] <= 0)
                continue;

            uint32 itemid = spellEntry->Reagent[x];
            uint32 itemcount = spellEntry->ReagentCount[x];
            if (!me->HasItemCount(itemid, itemcount))
                return;
        }
        // 2. Remove reagents
        for (uint32 x = 0; x < MAX_SPELL_REAGENTS; ++x)
        {
            if (spellEntry->Reagent[x] <= 0)
                continue;

            uint32 itemid = spellEntry->Reagent[x];
            uint32 itemcount = spellEntry->ReagentCount[x];
            me->DestroyItemCount(itemid, itemcount, true);
        }
    }

    // 3. Execute the pet summon spell effect
    EffectSummonPet(spell, entry, GetLevel());

    // 4. We may want to resurrect the pet
    Pet* pet = GetPet();
    if (!pet || pet->IsAlive())
        return;

    pet->SetUInt32Value(UNIT_DYNAMIC_FLAGS, UNIT_DYNFLAG_NONE);
    pet->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_SKINNABLE);
    pet->SetDeathState(ALIVE);
    pet->ClearUnitState(UNIT_STAT_ALL_DYN_STATES);
    pet->SetHealth(pet->GetMaxHealth());
}


bool Player::BuildEnumData(QueryResult* result, WorldPacket* p_data)
{
    //                0                1                2                3                 4                  5                6                7                      8                      9                       10
    //    "SELECT characters.guid, characters.name, characters.race, characters.class, characters.gender, characters.skin, characters.face, characters.hair_style, characters.hair_color, characters.facial_hair, characters.level, "
    //         11               12              13                     14                     15                     16                     17
    //    "characters.zone, characters.map, characters.position_x, characters.position_y, characters.position_z, guild_member.guild_id, characters.player_flags, "
    //         18                         19                   20                        21                   22
    //    "characters.at_login_flags, character_pet.entry, character_pet.display_id, character_pet.level, characters.equipment_cache "

    Field* fields = result->Fetch();

    uint32 guid = fields[0].GetUInt32();
    uint8 pRace = fields[2].GetUInt8();
    uint8 pClass = fields[3].GetUInt8();

    PlayerInfo const* info = sObjectMgr.GetPlayerInfo(pRace, pClass);
    if (!info)
    {
        sLog.outError("Player %u has incorrect race/class pair. Don't build enum.", guid);
        return false;
    }

    *p_data << ObjectGuid(HIGHGUID_PLAYER, guid);
    *p_data << fields[1].GetString();                       // name
    *p_data << uint8(pRace);                                // race
    *p_data << uint8(pClass);                               // class
    *p_data << uint8(fields[4].GetUInt8());                 // gender

    uint8 skin = fields[5].GetUInt8();
    uint8 face = fields[6].GetUInt8();
    uint8 hairStyle = fields[7].GetUInt8();
    uint8 hairColor = fields[8].GetUInt8();
    *p_data << uint8(skin);                                 // skin
    *p_data << uint8(face);                                 // face
    *p_data << uint8(hairStyle);                            // hair style
    *p_data << uint8(hairColor);                            // hair color

    uint8 facialHair = fields[9].GetUInt8();
    *p_data << uint8(facialHair);                           // facial hair

    *p_data << uint8(fields[10].GetUInt8());                // level
    *p_data << uint32(fields[11].GetUInt32());              // zone
    *p_data << uint32(fields[12].GetUInt32());              // map

    *p_data << fields[13].GetFloat();                       // x
    *p_data << fields[14].GetFloat();                       // y
    *p_data << fields[15].GetFloat();                       // z

    *p_data << uint32(fields[16].GetUInt32());              // guild id

    uint32 char_flags = 0;
    uint32 playerFlags = fields[17].GetUInt32();
    uint32 atLoginFlags = fields[18].GetUInt32();
    if (playerFlags & PLAYER_FLAGS_HIDE_HELM)
        char_flags |= CHARACTER_FLAG_HIDE_HELM;
    if (playerFlags & PLAYER_FLAGS_HIDE_CLOAK)
        char_flags |= CHARACTER_FLAG_HIDE_CLOAK;
    if (playerFlags & PLAYER_FLAGS_GHOST)
        char_flags |= CHARACTER_FLAG_GHOST;
    if (atLoginFlags & AT_LOGIN_RENAME)
        char_flags |= CHARACTER_FLAG_RENAME;

    *p_data << uint32(char_flags);                          // character flags

    // First login
    *p_data << uint8(atLoginFlags & AT_LOGIN_FIRST ? 1 : 0);

    // Pets info
    {
        uint32 petDisplayId = 0;
        uint32 petLevel = 0;
        uint32 petFamily = 0;

        // show pet at selection character in character list only for non-ghost character
        if (result && !(playerFlags & PLAYER_FLAGS_GHOST) && (pClass == CLASS_WARLOCK || pClass == CLASS_HUNTER))
        {
            uint32 entry = fields[19].GetUInt32();
            CreatureInfo const* cInfo = sCreatureStorage.LookupEntry<CreatureInfo>(entry);
            if (cInfo)
            {
                petDisplayId = fields[20].GetUInt32();
                petLevel = fields[21].GetUInt32();
                petFamily = cInfo->pet_family;
            }
        }

        *p_data << uint32(petDisplayId);
        *p_data << uint32(petLevel);
        *p_data << uint32(petFamily);
    }


    Tokens data = StrSplit(fields[22].GetCppString(), " ");
    for (uint8 slot = 0; slot < INVENTORY_SLOT_BAG_START + 1; slot++)
    {
        uint32 visualbase = slot * 2;                       // entry, perm ench., temp ench.
        uint32 item_id = GetUInt32ValueFromArray(data, visualbase);
        ItemPrototype const* proto = ObjectMgr::GetItemPrototype(item_id);
        if (!proto)
        {
            *p_data << uint32(0);
            *p_data << uint8(0);
            continue;
        }

        *p_data << uint32(proto->DisplayInfoID);
        *p_data << uint8(proto->InventoryType);
    }

    return true;
}

bool Player::ToggleAFK()
{
    ToggleFlag(PLAYER_FLAGS, PLAYER_FLAGS_AFK);

    if (GetGroup())
        SetGroupUpdateFlag(GROUP_UPDATE_FLAG_STATUS);

    bool state = IsAFK();

    // afk player not allowed in battleground
    if (state && InBattleGround())
        LeaveBattleground();

    return state;
}

bool Player::ToggleDND()
{
    ToggleFlag(PLAYER_FLAGS, PLAYER_FLAGS_DND);

    if (GetGroup())
        SetGroupUpdateFlag(GROUP_UPDATE_FLAG_STATUS);

    return HasFlag(PLAYER_FLAGS, PLAYER_FLAGS_DND);
}

uint8 Player::GetChatTag() const
{
    if (IsGMChat())
        return CHAT_TAG_GM;
    if (IsDND())
        return CHAT_TAG_DND;
    if (IsAFK())
        return CHAT_TAG_AFK;
    
    return CHAT_TAG_NONE;
}

bool Player::SwitchInstance(uint32 newInstanceId)
{
    if (!IsInWorld())
        return false;
    if (BattleGround const* bg = GetBattleGround())
        return false;
    if (IsTaxiFlying())
        return false;

    Map* oldmap = GetMap();

    // Leave transport if absent from new instance
    // normally it should have switched before the player
    if (m_transport && m_transport->GetInstanceId() != newInstanceId)
    {
        m_transport->RemovePassenger(this);
        m_movementInfo.ClearTransportData();
        m_movementInfo.RemoveMovementFlag(MOVEFLAG_ONTRANSPORT);
    }
    // Stop duel
    if (duel)
        if (GameObject* obj = GetMap()->GetGameObject(GetGuidValue(PLAYER_DUEL_ARBITER)))
            DuelComplete(DUEL_FLED);
    // Fix movement flags
    m_movementInfo.RemoveMovementFlag(MOVEFLAG_MASK_MOVING_OR_TURN);

    SetSelectionGuid(ObjectGuid());
    CombatStop();
    /*
     * Fix exploit:
     * 1. Use summoning ritual to teleport a player
     * 2. The teleported player tp to homebind <- Should remove teleport invitation
     * 3. And accepts teleport to come back to the instance
     */
    m_summon_expire = 0;

    // remove pet on map change
    UnsummonPetTemporaryIfAny();

    // remove all dyn objects
    RemoveAllDynObjects();

    // stop spellcasting
    // not attempt interrupt teleportation spell at caster teleport
    if (IsNonMeleeSpellCasted(true))
        InterruptNonMeleeSpells(true);

    //remove auras before removing from map...
    RemoveAurasWithInterruptFlags(AURA_INTERRUPT_FLAG_CHANGE_MAP | AURA_INTERRUPT_FLAG_MOVE | AURA_INTERRUPT_FLAG_TURNING);
    RemoveCharmAuras();
    DisableSpline();
    SetMover(this);

    // Clear hostile refs so that we have no cross-map (and thread) references being maintained
    GetHostileRefManager().deleteReferences();

    // remove from old map now
    oldmap->Remove(this, false);

    SetLocationInstanceId(newInstanceId);
    Map* newmap = sMapMgr.CreateMap(oldmap->GetId(), this);
    ASSERT(newmap);
    SetMap(newmap);

    for (const auto& guid : m_visibleGUIDs)
    {
        WorldPacket data(SMSG_DESTROY_OBJECT, 8);
        data << guid;
        GetSession()->SendPacket(&data);
    }

    ASSERT(newmap->Add(this));
    SendInitialPacketsAfterAddToMap(false);
    ResummonPetTemporaryUnSummonedIfAny();
    ProcessDelayedOperations();
    return true;
}

bool Player::TeleportTo(uint32 mapid, float x, float y, float z, float orientation, uint32 options, std::function<void()> recover)
{
    if (!MapManager::IsValidMapCoord(mapid, x, y, z, orientation))
    {
        sLog.outError("TeleportTo: invalid map %d or absent instance template.", mapid);
        return false;
    }

    // preparing unsummon pet if lost (we must get pet before teleportation or will not find it later)
    Pet* pet = GetPet();

    MapEntry const* mEntry = sMapStorage.LookupEntry<MapEntry>(mapid);

    // don't let enter battlegrounds without assigned battleground id (for example through areatrigger)...
    // don't let gm level > 1 either
    if (!InBattleGround() && mEntry->IsBattleGround())
        return false;

    DEBUG_LOG("Player %s will teleported to map %u", GetName(), mapid);

    // if we were on a transport, leave
    if (!(options & TELE_TO_NOT_LEAVE_TRANSPORT) && m_transport)
    {
        m_transport->RemovePassenger(this);
        m_movementInfo.ClearTransportData();
    }

    if (ObjectGuid lootGuid = GetLootGuid())
        GetSession()->DoLootRelease(lootGuid);

    // The player was ported to another map and looses the duel immediately.
    // We have to perform this check before the teleport, otherwise the
    // ObjectAccessor won't find the flag.
    if (duel && GetMapId() != mapid)
        if (GameObject* obj = GetMap()->GetGameObject(GetGuidValue(PLAYER_DUEL_ARBITER)))
            DuelComplete(DUEL_FLED);

    // reset movement flags at teleport, because player will continue move with these flags after teleport
    m_movementInfo.RemoveMovementFlag(MOVEFLAG_MASK_MOVING_OR_TURN);
    if (!(options & TELE_TO_NOT_LEAVE_TRANSPORT) || !m_transport)
        m_movementInfo.RemoveMovementFlag(MOVEFLAG_ONTRANSPORT);

    // Near teleport, let it happen immediately since we remain in the same map
    if ((GetMapId() == mapid) && (!m_transport) && !(options & TELE_TO_FORCE_MAP_CHANGE))
    {
        //lets reset far teleport flag if it wasn't reset during chained teleports
        SetSemaphoreTeleportFar(false);
        //setup delayed teleport flag
        //if teleport spell is casted in Unit::Update() func
        //then we need to delay it until update process will be finished
        if (SetDelayedTeleportFlagIfCan())
        {
            SetSemaphoreTeleportNear(true);
            //lets save teleport destination for player
            m_teleport_dest = WorldLocation(mapid, x, y, z, orientation);
            m_teleport_options = options;
            m_teleportRecoverDelayed = recover;
            return true;
        }

        if (!(options & TELE_TO_NOT_UNSUMMON_PET))
        {
            //same map, only remove pet if out of range for new position
            if (pet && !pet->IsWithinDist3d(x, y, z, GetMap()->GetGridActivationDistance()))
                UnsummonPetTemporaryIfAny();
        }

        if (!(options & TELE_TO_NOT_LEAVE_COMBAT))
        {
            ScheduleDelayedOperation(DELAYED_CAST_HONORLESS_TARGET);
            CombatStop();
        }

        if (!IsWithinDist3d(x, y, z, GetMap()->GetVisibilityDistance()))
            RemoveAurasWithInterruptFlags(AURA_INTERRUPT_FLAG_TELEPORTED);

        // this will be used instead of the current location in SaveToDB
        m_teleport_dest = WorldLocation(mapid, x, y, z, orientation);
        DisableSpline();
        SetFallInformation(0, z);

        // code for finish transfer called in WorldSession::HandleMovementOpcodes()
        // at client packet MSG_MOVE_TELEPORT_ACK
        SetSemaphoreTeleportNear(true);

        // near teleport, triggering send MSG_MOVE_TELEPORT_ACK from client at landing
        if (!GetSession()->PlayerLogout())
        {
            const auto wps = [this](){
                MovementPacketSender::SendTeleportToController(this, m_teleport_dest.x, 
                                                                     m_teleport_dest.y, 
                                                                     m_teleport_dest.z, 
                                                                     m_teleport_dest.o);
            };
            if (recover)
                m_teleportRecover = recover;
            else
                m_teleportRecover = wps;
            wps();
        }
        m_movementInfo.moveFlags &= ~MOVEFLAG_MASK_MOVING_OR_TURN; // For extrapolation
    }
    else
    {
        // Revive player who died inside instance.
        if ((GetDeathState() == DEAD) && (mapid > 1) && (GetMapId() != mapid))
        {
            if (Corpse* corpse = GetCorpse())
            {
                if (mapid == corpse->GetMapId())
                {
                    ResurrectPlayer(0.5f);
                    SpawnCorpseBones();
                }
            }
        }

        // check if we can enter before stopping combat / removing pet / totems / interrupting spells
        // Check enter rights before map getting to avoid creating instance copy for player
        // this check not dependent from map instance copy and same for all instance copies of selected map
        if (!sMapMgr.CanPlayerEnter(mapid, this))
            return false;

        DungeonPersistentState* state = GetBoundInstanceSaveForSelfOrGroup(mapid);
        uint32 instanceId = 0;
        if (state)
            instanceId = state->GetInstanceId();
        if (mapid <= 1)
            instanceId = sMapMgr.GetContinentInstanceId(mapid, x, y);
        Map* map = sMapMgr.FindMap(mapid, instanceId);
        if (map && !map->CanEnter(this))
            return false;

        // Far teleport to another map. We can't do this right now since it means
        // we need to remove from this map mid-update. Instead, schedule it for
        // after updates are complete
        ScheduledTeleportData* data = new ScheduledTeleportData(mapid, x, y, z, orientation, options, recover);

        sMapMgr.ScheduleFarTeleport(this, data);
    }
    return true;
}

bool Player::ExecuteTeleportFar(ScheduledTeleportData* data)
{
    Map* oldmap = IsInWorld() ? GetMap() : nullptr;
    // check if we can enter before stopping combat / removing pet / totems / interrupting spells

    // Check enter rights before map getting to avoid creating instance copy for player
    // this check not dependent from map instance copy and same for all instance copies of selected map
    uint32 mapid = data->targetMapId;
    if (!sMapMgr.CanPlayerEnter(mapid, this))
        return false;

    // If the map is not created, assume it is possible to enter it.
    // It will be created in the WorldPortAck.
    DungeonPersistentState* state = GetBoundInstanceSaveForSelfOrGroup(mapid);
    uint32 instanceId = 0;
    if (state)
        instanceId = state->GetInstanceId();
    if (mapid <= 1)
        instanceId = sMapMgr.GetContinentInstanceId(mapid, data->x, data->y);
    Map* map = sMapMgr.FindMap(mapid, instanceId);
    if (!map || map->CanEnter(this))
    {
        //lets reset near teleport flag if it wasn't reset during chained teleports
        SetSemaphoreTeleportNear(false);

        SetSelectionGuid(ObjectGuid());
        CombatStop();
        UpdatePvPContested(false, true);
        RemoveAurasWithInterruptFlags(AURA_INTERRUPT_FLAG_TELEPORTED);

        // reset extraAttack counter
        ResetExtraAttacks();

        /*
        * Fix exploit:
        * 1. Use summoning ritual to teleport a player
        * 2. The teleported player tp to homebind <- Should remove teleport invitation
        * 3. And accepts teleport to come back to the instance
        */
        m_summon_expire = 0;

        // remove player from battleground on far teleport (when changing maps)
        if (BattleGround const* bg = GetBattleGround())
        {
            // Note: at battleground join battleground id set before teleport
            // and we already will found "current" battleground
            // just need check that this is targeted map or leave
            if (bg->GetMapId() != mapid)
                LeaveBattleground(false);                   // don't teleport to entry point
        }

        // remove pet on map change
        Pet* pet = GetPet();
        if (pet)
            UnsummonPetTemporaryIfAny();

        // remove all dyn objects
        RemoveAllDynObjects();

        // stop spellcasting
        // not attempt interrupt teleportation spell at caster teleport
        if (!(data->options & TELE_TO_SPELL))
            if (IsNonMeleeSpellCasted(true))
                InterruptNonMeleeSpells(true);

        //remove auras before removing from map...
        RemoveAurasWithInterruptFlags(AURA_INTERRUPT_FLAG_CHANGE_MAP | AURA_INTERRUPT_FLAG_MOVE | AURA_INTERRUPT_FLAG_TURNING);
        RemoveCharmAuras();
        ResolvePendingMovementChanges(false, false);

        if (!GetSession()->PlayerLogout())
        {
            // send transfer packet to display load screen
            WorldPacket data(SMSG_TRANSFER_PENDING, (4 + 4 + 4));
            data << uint32(mapid);
            if (m_transport)
            {
                data << uint32(m_transport->GetEntry());
                data << uint32(GetMapId());
            }
            GetSession()->SendPacket(&data);
        }

        // remove from old map now
        if (oldmap)
            oldmap->Remove(this, false);

        m_teleport_dest = WorldLocation(mapid, data->x, data->y, data->z, data->orientation);
        DisableSpline();
        SetFallInformation(0, data->z);
        ScheduleDelayedOperation(DELAYED_CAST_HONORLESS_TARGET);

        // Clear hostile refs so that we have no cross-map (and thread) references being maintained
        GetHostileRefManager().deleteReferences();

        // if the player is saved before worldport ack (at logout for example)
        // this will be used instead of the current location in SaveToDB

        // move packet sent by client always after far teleport
        // code for finish transfer to new map called in WorldSession::HandleMoveWorldportAckOpcode at client packet
        SetSemaphoreTeleportFar(true);

        if (!GetSession()->PlayerLogout())
        {
            const auto wps = [this, mapid]() {
                // transfer finished, inform client to start load
                WorldPacket data(SMSG_NEW_WORLD, (20));
                data << uint32(mapid);
                if (m_transport)
                {
                    data << m_movementInfo.GetTransportPos().x;
                    data << m_movementInfo.GetTransportPos().y;
                    data << m_movementInfo.GetTransportPos().z;
                    data << m_movementInfo.GetTransportPos().o;
                }
                else
                {
                    data << m_teleport_dest.x;
                    data << m_teleport_dest.y;
                    data << m_teleport_dest.z;
                    data << m_teleport_dest.o;
                }
                GetSession()->SendPacket(&data);
                SendMovementMessageToSet(std::move(data), true);
                SendSavedInstances();
            };
            if (data->recover)
                m_teleportRecover = data->recover;
            else
                m_teleportRecover = wps;
            wps();
        }

        return true;
    }

    return false;
}

void Player::RestorePendingTeleport()
{
    if (m_teleportRecover)
        m_teleportRecover();
}

bool Player::TeleportToBGEntryPoint()
{
    if (m_bgData.joinPos.x == 0.0f && m_bgData.joinPos.y == 0.0f && m_bgData.joinPos.z == 0.0f)
        m_bgData.joinPos = WorldLocation(m_homebindMapId, m_homebindX, m_homebindY, m_homebindZ, 0.0f);

    return TeleportTo(m_bgData.joinPos);
}

void Player::ProcessDelayedOperations()
{
    if (m_DelayedOperations == 0)
        return;

    if (m_DelayedOperations & DELAYED_RESURRECT_PLAYER)
    {
        ResurrectPlayer(0.0f, false);

        if (GetMaxHealth() > m_resurrectHealth)
            SetHealth(m_resurrectHealth);
        else
            SetHealth(GetMaxHealth());

        if (GetMaxPower(POWER_MANA) > m_resurrectMana)
            SetPower(POWER_MANA, m_resurrectMana);
        else
            SetPower(POWER_MANA, GetMaxPower(POWER_MANA));

        SetPower(POWER_RAGE, 0);
        SetPower(POWER_ENERGY, GetMaxPower(POWER_ENERGY));

        SpawnCorpseBones();
    }

    if (m_DelayedOperations & DELAYED_SAVE_PLAYER)
        SaveToDB();

    if (m_DelayedOperations & DELAYED_SPELL_CAST_DESERTER)
        CastSpell(this, 26013, true);               // Deserter

    if (m_DelayedOperations & DELAYED_CAST_HONORLESS_TARGET)
        CastSpell(this, 2479, true);

    //we have executed ALL delayed ops, so clear the flag
    m_DelayedOperations = 0;
}

void Player::AddToWorld()
{
    ///- Do not add/remove the player from the object storage
    ///- It will crash when updating the ObjectAccessor
    ///- The player should only be added when logging in
    Unit::AddToWorld();

    for (int i = PLAYER_SLOT_START; i < PLAYER_SLOT_END; ++i)
    {
        if (m_items[i])
            m_items[i]->AddToWorld();
    }
    sPlayerBotMgr.OnPlayerInWorld(this);
}

void Player::RemoveFromWorld()
{
    if (m_transport)
        SendDestroyGroupMembers(true);

    if (IsInWorld())
    {
        ///- Release charmed creatures, unsummon totems and remove pets/guardians
        UnsummonAllTotems();
        RemoveMiniPet();
        sZoneScriptMgr.HandlePlayerLeaveZone(this, m_zoneUpdateId);
        TradeCancel(false);

        if (ObjectGuid lootGuid = GetLootGuid())
            GetSession()->DoLootRelease(lootGuid);
    }

    for (int i = PLAYER_SLOT_START; i < PLAYER_SLOT_END; ++i)
    {
        if (m_items[i])
            m_items[i]->RemoveFromWorld();
    }

    // remove duel before calling Unit::RemoveFromWorld
    // otherwise there will be an existing duel flag pointer but no entry in m_gameObj
    DuelComplete(DUEL_INTERRUPTED);

    ///- Do not add/remove the player from the object storage
    ///- It will crash when updating the ObjectAccessor
    ///- The player should only be removed when logging out
    if (IsInWorld())
        GetCamera().ResetView();

    SetEscortingGuid(ObjectGuid());

    Unit::RemoveFromWorld();
}

void Player::RewardRage(uint32 damage, bool attacker)
{
    // Vanilla rage formula source http://blue.mmo-champion.com/topic/18325-the-new-rage-formula-by-kalgan/
    float addRage;

    float rageconversion = float((0.0091107836 * GetLevel() * GetLevel()) + 3.225598133 * GetLevel()) + 4.2652911f;

    if (attacker)
    {
        // Nostalrius - fix regen rage.
        addRage = (damage / rageconversion) * 7.5f; //TBC formula: ((damage/rageconversion*7.5f + weaponSpeedHitFactor)/2.0f);
    }
    else
    {
        addRage = damage / rageconversion * 2.5f;

        // Berserker Rage effect
        if (HasAura(18499, EFFECT_INDEX_0))
            addRage *= 1.3f;
    }

    addRage *= sWorld.getConfig(CONFIG_FLOAT_RATE_POWER_RAGE_INCOME);

    ModifyPower(POWER_RAGE, uint32(addRage * 10));
}

void Player::HandleFoodEmotes(uint32 diff)
{
    // Handles the emotes for drinking and eating.
    // According to sniffs there is a background timer going on that repeats independed from the time window where the aura applies.
    // That's why we dont need to reset the timer on apply. In sniffs I have seen that the first call for the spell visual is totally random, then after
    // 5 seconds over and over again which confirms my theory that we have a independed timer.
    if (m_foodEmoteTimer <= diff)
    {
        AuraList const& lModRegenAuras = GetAurasByType(SPELL_AURA_MOD_REGEN);
        AuraList const& lModPowerRegenAuras = GetAurasByType(SPELL_AURA_MOD_POWER_REGEN);

        for (const auto pAura : lModRegenAuras)
        {
            if (pAura->GetSpellProto()->HasAura(SPELL_AURA_MOD_REGEN) && pAura->GetSpellProto()->AuraInterruptFlags & AURA_INTERRUPT_FLAG_NOT_SEATED)
            {
                SendPlaySpellVisual(SPELL_VISUAL_KIT_FOOD);
                break;
            }
        }

        for (const auto pAura : lModPowerRegenAuras)
        {
            if (pAura->GetSpellProto()->HasAura(SPELL_AURA_MOD_POWER_REGEN) && pAura->GetSpellProto()->AuraInterruptFlags & AURA_INTERRUPT_FLAG_NOT_SEATED)
            {
                SendPlaySpellVisual(SPELL_VISUAL_KIT_DRINK);
                break;
            }
        }

        m_foodEmoteTimer = 5000;
    }
    else
        m_foodEmoteTimer -= diff;
}

void Player::RegenerateAll()
{
    if (m_regenTimer > 0)
        return;

    // Not in combat or they have regeneration
    if (!IsInCombat() || HasAuraType(SPELL_AURA_MOD_REGEN_DURING_COMBAT) ||
            HasAuraType(SPELL_AURA_MOD_HEALTH_REGEN_IN_COMBAT) || IsPolymorphed())
    {
        RegenerateHealth();
        if (!IsInCombat() && !HasAuraType(SPELL_AURA_INTERRUPT_REGEN))
            Regenerate(POWER_RAGE);
    }

    Regenerate(POWER_ENERGY);
    Regenerate(POWER_MANA);

    m_regenTimer += REGEN_TIME_FULL;
}

void Player::Regenerate(Powers power)
{
    uint32 curValue = GetPower(power);
    uint32 maxValue = GetMaxPower(power);

    float addvalue = 0.0f;

    switch (power)
    {
        case POWER_MANA:
        {
            bool recentCast = IsUnderLastManaUseEffect();
            float ManaIncreaseRate = sWorld.getConfig(CONFIG_FLOAT_RATE_POWER_MANA);
            if (recentCast)
            {
                // Mangos Updates Mana in intervals of 2s, which is correct
                addvalue = m_modManaRegenInterrupt * ManaIncreaseRate * 2.00f;
            }
            else
                addvalue = m_modManaRegen * ManaIncreaseRate * 2.00f;
        }
        break;
        case POWER_RAGE:                                    // Regenerate rage
        {
            float RageDecreaseRate = sWorld.getConfig(CONFIG_FLOAT_RATE_POWER_RAGE_LOSS);
            addvalue = 20 * RageDecreaseRate;               // 2 rage by tick (= 2 seconds => 1 rage/sec)
        }
        break;
        case POWER_ENERGY:                                  // Regenerate energy (rogue)
        {
            float EnergyRate = sWorld.getConfig(CONFIG_FLOAT_RATE_POWER_ENERGY);
            addvalue = 20 * EnergyRate;
            break;
        }
        case POWER_FOCUS:
        case POWER_HAPPINESS:
        case POWER_HEALTH:
            break;
    }

    // Mana regen calculated in Player::UpdateManaRegen()
    // Exist only for POWER_MANA, POWER_ENERGY, POWER_FOCUS auras
    if (power != POWER_MANA)
    {
        AuraList const& lModPowerRegenPCTAuras = GetAurasByType(SPELL_AURA_MOD_POWER_REGEN_PERCENT);
        for (const auto itr : lModPowerRegenPCTAuras)
            if (itr->GetModifier()->m_miscvalue == int32(power))
                addvalue *= (itr->GetModifier()->m_amount + 100) / 100.0f;
    }

    if (power != POWER_RAGE)
    {
        curValue += uint32(addvalue);
        if (curValue > maxValue)
            curValue = maxValue;
    }
    else
    {
        if (curValue <= uint32(addvalue))
            curValue = 0;
        else
            curValue -= uint32(addvalue);
    }
    SetPower(power, curValue);
}

void Player::RegenerateHealth()
{
    uint32 curValue = GetHealth();
    uint32 maxValue = GetMaxHealth();

    if (curValue >= maxValue) return;

    float HealthIncreaseRate = sWorld.getConfig(CONFIG_FLOAT_RATE_HEALTH);

    float addvalue = 0.0f;

    // polymorphed case
    if (IsPolymorphed())
        addvalue = (float)GetMaxHealth() / 10;
    // normal regen case (maybe partly in combat case)
    else if (!IsInCombat() || HasAuraType(SPELL_AURA_MOD_REGEN_DURING_COMBAT))
    {
        addvalue = GetRegenHPPerSpirit() * HealthIncreaseRate;
        if (!IsInCombat())
        {
            AuraList const& lModHealthRegenPct = GetAurasByType(SPELL_AURA_MOD_HEALTH_REGEN_PERCENT);
            for (const auto i : lModHealthRegenPct)
                addvalue *= (100.0f + i->GetModifier()->m_amount) / 100.0f;
        }
        else if (HasAuraType(SPELL_AURA_MOD_REGEN_DURING_COMBAT))
            addvalue *= GetTotalAuraModifier(SPELL_AURA_MOD_REGEN_DURING_COMBAT) / 100.0f;

        if (!IsStandingUp())
            addvalue *= 1.5;

        // Food
        if (!IsInCombat())
        {
            AuraList const& lModHealthRegen = GetAurasByType(SPELL_AURA_MOD_REGEN);
            for (const auto i : lModHealthRegen)
                addvalue += i->GetModifier()->m_amount * (float(REGEN_TIME_FULL) / float(i->GetModifier()->periodictime));
        }
    }

    // always regeneration bonus (including combat)
    // This function is called every 2 seconds.
    addvalue += HealthIncreaseRate * 2.0f * (GetTotalAuraModifier(SPELL_AURA_MOD_HEALTH_REGEN_IN_COMBAT) / 5.0f);

    // Health fractions get carried to the next tick
    addvalue += m_carryHealthRegen;
    m_carryHealthRegen = addvalue - int32(addvalue);

    if (addvalue < 0)
        addvalue = 0;

    ModifyHealth(int32(addvalue));
}

bool Player::CanInteractWithQuestGiver(Object* questGiver) const
{
    switch (questGiver->GetTypeId())
    {
        case TYPEID_UNIT:
            return CanInteractWithNPC(static_cast<Creature*>(questGiver), UNIT_NPC_FLAG_QUESTGIVER);
        case TYPEID_GAMEOBJECT:
            return CanInteractWithGameObject(static_cast<GameObject*>(questGiver), GAMEOBJECT_TYPE_QUESTGIVER);
        case TYPEID_PLAYER:
            return IsAlive() && static_cast<Player*>(questGiver)->IsAlive();
        case TYPEID_ITEM:
            return IsAlive();
        default:
            break;
    }
    return false;
}

Creature* Player::FindNearestInteractableNpcWithFlag(uint32 npcFlags) const
{
    Creature* pCreature = nullptr;

    MaNGOS::NearestInteractableNpcWithFlag u_check(this, npcFlags);
    MaNGOS::CreatureLastSearcher<MaNGOS::NearestInteractableNpcWithFlag> searcher(pCreature, u_check);

    Cell::VisitGridObjects(this, searcher, INTERACTION_DISTANCE);

    return pCreature;
}

Creature* Player::GetNPCIfCanInteractWith(ObjectGuid guid, uint32 npcflagmask) const
{
    // some basic checks
    if (!guid || !IsInWorld() || IsTaxiFlying())
        return nullptr;

    // exist (we need look pets also for some interaction (quest/etc)
    Creature* pCreature = GetMap()->GetAnyTypeCreature(guid);
    
    return CanInteractWithNPC(pCreature, npcflagmask) ? pCreature : nullptr;
}

bool Player::CanInteractWithNPC(Creature const* pCreature, uint32 npcflagmask) const
{
    if (!pCreature)
        return false;

    // some basic checks
    if (!IsInWorld() || IsTaxiFlying())
        return false;

    // not in interactive state
    if (HasUnitState(UNIT_STAT_CAN_NOT_REACT_OR_LOST_CONTROL))
        return false;

    // appropriate npc type
    if (npcflagmask && !pCreature->HasFlag(UNIT_NPC_FLAGS, npcflagmask))
        return false;

    if (npcflagmask == UNIT_NPC_FLAG_STABLEMASTER)
    {
        if (GetClass() != CLASS_HUNTER)
            return false;
    }

    if (!pCreature->IsAlive())
        return false;

    if (IsAlive() && pCreature->IsInvisibleForAlive())
        return false;

    if (!IsAlive() && !pCreature->HasTypeFlag(CREATURE_TYPEFLAGS_GHOST_VISIBLE))
        return false;

    // not allow interaction under control, but allow with own pets
    if (pCreature->GetCharmerGuid())
        return false;

    // not enemy
    if (pCreature->IsHostileTo(this))
        return false;

    // combat check
    if (pCreature->IsInCombat())
        return false;

    // not unfriendly
    if (FactionTemplateEntry const* factionTemplate = sObjectMgr.GetFactionTemplateEntry(pCreature->GetFactionTemplateId()))
        if (factionTemplate->faction)
            if (FactionEntry const* faction = sObjectMgr.GetFactionEntry(factionTemplate->faction))
                if (faction->reputationListID >= 0 && GetReputationMgr().GetRank(faction) <= REP_UNFRIENDLY)
                    return false;

    // not too far
    if (!pCreature->IsWithinDistInMap(this, INTERACTION_DISTANCE))
        return false;

    return true;
}

GameObject* Player::GetGameObjectIfCanInteractWith(ObjectGuid guid, uint32 gameobject_type) const
{
    // some basic checks
    if (!guid || !IsInWorld() || IsTaxiFlying())
        return nullptr;

    GameObject* pGo = GetMap()->GetGameObject(guid);
    return CanInteractWithGameObject(pGo, gameobject_type) ? pGo : nullptr;
}

bool Player::CanInteractWithGameObject(GameObject const* pGo, uint32 gameobject_type) const
{
    if (!pGo)
        return false;

    // some basic checks
    if (!IsInWorld() || IsTaxiFlying())
        return false;

    // not in interactive state
    if (HasUnitState(UNIT_STAT_CAN_NOT_REACT_OR_LOST_CONTROL))
        return false;

    if (!IsAlive())
        return false;

    if (uint32(pGo->GetGoType()) == gameobject_type || gameobject_type == MAX_GAMEOBJECT_TYPE)
    {
        if (pGo->IsAtInteractDistance(this) && pGo->isSpawned())
            return true;

        sLog.outError("CanInteractWithGameObject: GameObject '%s' [GUID: %u] is too far away from player %s [GUID: %u] to be used by him",
            pGo->GetGOInfo()->name, pGo->GetGUIDLow(), GetName(), GetGUIDLow());
    }

    return false;
}

bool Player::CanSeeHealthOf(Unit const* pTarget) const
{
    Player* pOwner = pTarget->GetCharmerOrOwnerPlayerOrPlayerItself();
    if (pOwner && IsInSameRaidWith(pOwner))
        return true;

    // Beast Lore
    return CanSeeSpecialInfoOf(pTarget);
}

bool Player::CanSeeSpecialInfoOf(Unit const* pTarget) const
{
    for (const auto& aura : pTarget->GetAurasByType(SPELL_AURA_EMPATHY))
    {
        if (aura->GetCasterGuid() == this->GetObjectGuid())
            return true;
    }

    return false;
}

struct SetGameMasterOnHelper
{
    explicit SetGameMasterOnHelper() {}
    void operator()(Unit* unit) const
    {
        unit->SetFactionTemplateId(35);
        unit->GetHostileRefManager().setOnlineOfflineState(false);
    }
};

struct SetGameMasterOffHelper
{
    explicit SetGameMasterOffHelper(uint32 _faction) : faction(_faction) {}
    void operator()(Unit* unit) const
    {
        unit->SetFactionTemplateId(faction);
        unit->GetHostileRefManager().setOnlineOfflineState(true);
    }
    uint32 faction;
};

void Player::SetGMChat(bool on, bool notify)
{
    if (on)
    {
        m_ExtraFlags |= PLAYER_EXTRA_GM_CHAT;
        if (notify)
        {
            ChatHandler(this).SendSysMessage(LANG_GM_CHAT_ON);
            GetSession()->SendNotification(LANG_GM_CHAT_ON);
        }
    }
    else
    {
        m_ExtraFlags &= ~PLAYER_EXTRA_GM_CHAT;
        if (notify)
        {
            ChatHandler(this).SendSysMessage(LANG_GM_CHAT_OFF);
            GetSession()->SendNotification(LANG_GM_CHAT_OFF);
        }
    }
}

void Player::SetGameMaster(bool on, bool notify)
{
    if (on)
    {
        m_ExtraFlags |= PLAYER_EXTRA_GM_ON;
        SetFactionTemplateId(35);
        SetFlag(PLAYER_FLAGS, PLAYER_FLAGS_GM);

        CallForAllControlledUnits(SetGameMasterOnHelper(), CONTROLLED_PET | CONTROLLED_TOTEMS | CONTROLLED_GUARDIANS | CONTROLLED_CHARM);

        FreezeMirrorTimers(true);

        SetFFAPvP(false);
        UpdatePvPContested(false, true);

        GetHostileRefManager().setOnlineOfflineState(false);
        CombatStopWithPets();

        if (notify)
        {
            ChatHandler(this).SendSysMessage(LANG_GM_ON);
            GetSession()->SendNotification(LANG_GM_ON);
        }
    }
    else
    {
        m_ExtraFlags &= ~ PLAYER_EXTRA_GM_ON;
        SetFactionForRace(GetRace());
        RemoveFlag(PLAYER_FLAGS, PLAYER_FLAGS_GM);

        CallForAllControlledUnits(SetGameMasterOffHelper(GetFactionTemplateId()), CONTROLLED_PET | CONTROLLED_TOTEMS | CONTROLLED_GUARDIANS | CONTROLLED_CHARM);

        FreezeMirrorTimers(false);

        // restore FFA PvP Server state
        if (sWorld.IsFFAPvPRealm())
            SetFFAPvP(true);

        // restore FFA PvP area state, remove not allowed for GM mounts
        UpdateArea(m_areaUpdateId);

        GetHostileRefManager().setOnlineOfflineState(true);

        if (notify)
        {
            ChatHandler(this).SendSysMessage(LANG_GM_OFF);
            GetSession()->SendNotification(LANG_GM_OFF);
        }
    }

    m_camera.UpdateVisibilityForOwner();
    UpdateObjectVisibility();
    UpdateForQuestWorldObjects();

    // GM can select (UNIT_FIELD_FLAGS) everybody.
    UpdateMask m;
    m.SetCount(UNIT_END);
    m.SetBit(UNIT_FIELD_FLAGS);
    RefreshBitsForVisibleUnits(&m, TYPEMASK_UNIT);
    m.SetCount(PLAYER_END);
    m.SetBit(UNIT_FIELD_FLAGS);
    RefreshBitsForVisibleUnits(&m, TYPEMASK_PLAYER);
}

void Player::SetGMVisible(bool on, bool notify)
{
    // 'Invisibilite superieure'
    uint32 const VISUAL_AURA = 16380;
    if (on)
    {
        RemoveAurasDueToSpell(VISUAL_AURA);
        m_ExtraFlags &= ~PLAYER_EXTRA_GM_INVISIBLE;         //remove flag

        // Reapply stealth/invisibility if active or show if not any
        if (HasAuraType(SPELL_AURA_MOD_STEALTH))
            SetVisibility(VISIBILITY_GROUP_STEALTH);
        else if (HasAuraType(SPELL_AURA_MOD_INVISIBILITY))
            SetVisibility(VISIBILITY_GROUP_INVISIBILITY);
        else
            SetVisibility(VISIBILITY_ON);

        if (notify)
        {
            ChatHandler(this).SendSysMessage(LANG_INVISIBLE_VISIBLE);
            GetSession()->SendNotification(LANG_INVIS_OFF);
        }
    }
    else
    {
        AddAura(VISUAL_AURA, ADD_AURA_PERMANENT);
        m_ExtraFlags |= PLAYER_EXTRA_GM_INVISIBLE;          //add flag

        SetAcceptWhispers(false);
        if (MasterPlayer* masterPlayer = GetSession()->GetMasterPlayer())
            masterPlayer->ClearAllowedWhisperers();
        SetGameMaster(true);

        SetVisibility(VISIBILITY_OFF);

        if (notify)
        {
            ChatHandler(this).PSendSysMessage(LANG_INVISIBLE_INVISIBLE, GetGMInvisibilityLevel());
            GetSession()->SendNotification(LANG_INVIS_ON);
        }
    }
    // Sauvegarde directement pour que le site n'affiche plus le MJ parmis les joueurs co.
    CharacterDatabase.PExecute("UPDATE characters SET extra_flags = %u WHERE guid = %u", m_ExtraFlags, GetGUIDLow());
}

void Player::SetCheatGod(bool on, bool notify)
{
    SetCheatOption(PLAYER_CHEAT_GOD, on);

    if (notify)
    {
        GetSession()->SendNotification(on ? LANG_GOD_ON : LANG_GOD_OFF);
    }
}

void Player::SetCheatNoCooldown(bool on, bool notify)
{
    SetCheatOption(PLAYER_CHEAT_NO_COOLDOWN, on);

    if (notify)
    {
        GetSession()->SendNotification(on ? LANG_CHEAT_NO_CD_ON : LANG_CHEAT_NO_CD_OFF);
    }
}

void Player::SetCheatInstantCast(bool on, bool notify)
{
    SetCheatOption(PLAYER_CHEAT_NO_CAST_TIME, on);

    if (notify)
    {
        GetSession()->SendNotification(on ? LANG_CHEAT_INSTANT_CAST_ON : LANG_CHEAT_INSTANT_CAST_OFF);
    }
}

void Player::SetCheatNoPowerCost(bool on, bool notify)
{
    SetCheatOption(PLAYER_CHEAT_NO_POWER, on);

    if (notify)
    {
        GetSession()->SendNotification(on ? LANG_CHEAT_NO_POWER_COST_ON : LANG_CHEAT_NO_POWER_COST_OFF);
    }
}

void Player::SetCheatDebuffImmunity(bool on, bool notify)
{
    SetCheatOption(PLAYER_CHEAT_DEBUFF_IMMUNITY, on);

    if (notify)
    {
        GetSession()->SendNotification(on ? LANG_CHEAT_DEBUFF_IMMUNITY_ON : LANG_CHEAT_DEBUFF_IMMUNITY_OFF);
    }
}

void Player::SetCheatAlwaysCrit(bool on, bool notify)
{
    SetCheatOption(PLAYER_CHEAT_ALWAYS_CRIT, on);

    if (notify)
    {
        GetSession()->SendNotification(on ? LANG_CHEAT_ALWAYS_CRIT_ON : LANG_CHEAT_ALWAYS_CRIT_OFF);
    }
}

void Player::SetCheatNoCastCheck(bool on, bool notify)
{
    SetCheatOption(PLAYER_CHEAT_NO_CHECK_CAST, on);

    if (notify)
    {
        GetSession()->SendNotification(on ? LANG_CHEAT_NO_CAST_CHECK_ON : LANG_CHEAT_NO_CAST_CHECK_OFF);
    }
}

void Player::SetCheatAlwaysProc(bool on, bool notify)
{
    SetCheatOption(PLAYER_CHEAT_ALWAYS_PROC, on);

    if (notify)
    {
        GetSession()->SendNotification(on ? LANG_CHEAT_ALWAYS_PROC_ON : LANG_CHEAT_ALWAYS_PROC_OFF);
    }
}

void Player::SetCheatTriggerPass(bool on, bool notify)
{
    SetCheatOption(PLAYER_CHEAT_TRIGGER_PASS, on);

    if (notify)
    {
        GetSession()->SendNotification(on ? LANG_CHEAT_TRIGGER_PASS_ON : LANG_CHEAT_TRIGGER_PASS_OFF);
    }
}

void Player::SetCheatIgnoreTriggers(bool on, bool notify)
{
    SetCheatOption(PLAYER_CHEAT_IGNORE_TRIGGERS, on);

    if (notify)
    {
        GetSession()->SendNotification(on ? LANG_CHEAT_IGNORE_TRIGGERS_ON : LANG_CHEAT_IGNORE_TRIGGERS_OFF);
    }
}

bool Player::IsAllowedWhisperFrom(ObjectGuid guid) const
{
    if (PlayerSocial const* social = GetSocial())
        if (social->HasFriend(guid))
            return true;

    if (Group const* group = GetGroup())
        if (group->IsMember(guid))
            return true;

    if (Guild* guild = sGuildMgr.GetGuildById(GetGuildId()))
        if (guild->GetMemberSlot(guid))
            return true;

    return false;
}

bool Player::IsGroupVisibleFor(Player const* p) const
{
    switch (sWorld.getConfig(CONFIG_UINT32_GROUP_VISIBILITY))
    {
        default:
            return IsInSameGroupWith(p);
        case 1:
            return IsInSameRaidWith(p);
        case 2:
            return GetTeam() == p->GetTeam();
    }
}

bool Player::IsInSameGroupWith(Player const* p) const
{
    return (p == this || (GetGroup() != nullptr &&
                          GetGroup()->SameSubGroup((Player*)this, (Player*)p)));
}

///- If the player is invited, remove him. If the group if then only 1 person, disband the group.
/// \todo Shouldn't we also check if there is no other invitees before disbanding the group?
void Player::UninviteFromGroup()
{
    Group* group = GetGroupInvite();
    if (!group)
        return;

    group->RemoveInvite(this);

    if (group->GetMembersCount() <= 1)                      // group has just 1 member => disband
    {
        if (group->IsCreated())
        {
            group->Disband(true);
            sObjectMgr.RemoveGroup(group);
        }
        else
            group->RemoveAllInvites();

        delete group;
    }
}

void Player::RemoveFromGroup(Group* group, ObjectGuid guid)
{
    if (group)
    {
        if (group->RemoveMember(guid, 0) <= 1)
        {
            // group->Disband(); already disbanded in RemoveMember
            sObjectMgr.RemoveGroup(group);
            delete group;
            // removemember sets the player's group pointer to nullptr
        }
    }
}

#if SUPPORTED_CLIENT_BUILD <= CLIENT_BUILD_1_8_4
uint32 Player::GetWhoListPartyStatus() const
{
    if (sLFGMgr.IsPlayerInQueue(GetObjectGuid()))
        return WHO_PARTY_STATUS_LFG;

    if (GetGroup())
        return WHO_PARTY_STATUS_IN_PARTY;

    return WHO_PARTY_STATUS_NOT_IN_PARTY;
}
#endif

void Player::SendLogXPGain(uint32 GivenXP, Unit* victim, uint32 RestXP) const
{
    WorldPacket data(SMSG_LOG_XPGAIN, 21);
    data << (victim ? victim->GetObjectGuid() : ObjectGuid());// guid
    data << uint32(GivenXP + RestXP);                       // given experience
    data << uint8(victim ? 0 : 1);                          // 00-kill_xp type, 01-non_kill_xp type
    if (victim)
    {
        data << uint32(GivenXP);                            // experience without rested bonus
        data << float(1);                                   // 1 - none 0 - 100% group bonus output
    }
    GetSession()->SendPacket(&data);
}

void Player::GiveXP(uint32 xp, Unit* victim)
{
    if (xp < 1)
        return;

    if (!IsAlive())
        return;

    uint32 level = GetLevel();

    // XP to money conversion processed in Player::RewardQuest
    if (level >= sWorld.getConfig(CONFIG_UINT32_MAX_PLAYER_LEVEL))
        return;

    // XP resting bonus for kill
    uint32 rested_bonus_xp = victim ? GetXPRestBonus(xp) : 0;

    SendLogXPGain(xp, victim, rested_bonus_xp);

    uint32 curXP = GetUInt32Value(PLAYER_XP);
    uint32 nextLvlXP = GetUInt32Value(PLAYER_NEXT_LEVEL_XP);
    uint32 newXP = curXP + xp + rested_bonus_xp;

    while (newXP >= nextLvlXP && level < sWorld.getConfig(CONFIG_UINT32_MAX_PLAYER_LEVEL))
    {
        newXP -= nextLvlXP;

        if (level < sWorld.getConfig(CONFIG_UINT32_MAX_PLAYER_LEVEL))
            GiveLevel(level + 1);

        level = GetLevel();
        nextLvlXP = GetUInt32Value(PLAYER_NEXT_LEVEL_XP);
    }

    SetUInt32Value(PLAYER_XP, newXP);
}

// Update player to next level
// Current player experience not update (must be update by caller)
void Player::GiveLevel(uint32 level)
{
    if (level == GetLevel())
        return;

    uint32 numInstanceMembers = 0;
    uint32 numGroupMembers = 0;

    // Record who is in the group
    std::stringstream groupInfo;
    if (Group* group = GetGroup())
    {
        bool first = true;
        numGroupMembers = group->GetMembersCount();
        for (GroupReference* itr = group->GetFirstMember(); itr != nullptr; itr = itr->next())
        {
            if (Player* player = itr->getSource())
            {
                if (!first)
                    groupInfo << ", ";

                groupInfo << player->GetName();
                first = false;
            }
        }
    }
    else
        groupInfo << "None";

    // Record who is in the instance if we're in one
    std::stringstream instanceInfo;
    Map* map = FindMap();
    if (map && (GetMap()->IsDungeon() || GetMap()->IsRaid()))
    {
        bool first = true;
        for (auto itr = map->GetPlayers().getFirst(); itr != nullptr; itr = itr->next())
        {
            if (auto player = itr->getSource())
            {
                if (!first)
                    instanceInfo << ", ";

                instanceInfo << player->GetName();
                first = false;
            }

            // This is a raid. Don't log anymore
            if (++numInstanceMembers >= 10)
                break;
        }
    }
    else
        instanceInfo << "None";

    sLog.out(LOG_LEVELUP, "Character %s:%u [c%u r%u] reaches level %2u, zone %u, pos: [%0.2f, %0.2f, %0.2f] [Group: %s] [Instance: %s]",
        GetName(), GetGUIDLow(), GetClass(), GetRace(), level, GetZoneId(), GetPositionX(), GetPositionY(), GetPositionZ(),
        groupInfo.str().c_str(), instanceInfo.str().c_str());

    // If we have instance members, and the number of players in the instance is not
    // equal to the number of group members, then the player is likely mob tagging
    // and dropping group. Or they are soloing a dungeon, which is questionable.
    // Alert GMs
    if (!!numInstanceMembers && numInstanceMembers > numGroupMembers)
    {
        std::stringstream message;
        message << GetGuidStr() << " levelup in dungeon with "
                << numInstanceMembers << " instance members, but "
                << numGroupMembers << " group members";

        sWorld.SendGMText(LANG_GM_ANNOUNCE_COLOR, "LevelUpAlert", message.str().c_str());
    }

    PlayerLevelInfo info;
    sObjectMgr.GetPlayerLevelInfo(GetRace(), GetClass(), level, &info);

    PlayerClassLevelInfo classInfo;
    sObjectMgr.GetPlayerClassLevelInfo(GetClass(), level, &classInfo);

    uint32 hp = uint32((int32(classInfo.basehealth) - int32(GetCreateHealth()))
        + (int32(GetHealthBonusFromStamina(info.stats[STAT_STAMINA])) - int32(GetHealthBonusFromStamina(GetCreateStat(STAT_STAMINA)))));

    uint32 mana = uint32((int32(classInfo.basemana) - int32(GetCreateMana()))
        + (int32(GetManaBonusFromIntellect(info.stats[STAT_INTELLECT])) - int32(GetManaBonusFromIntellect(GetCreateStat(STAT_INTELLECT)))));

    // send levelup info to client
    WorldPacket data(SMSG_LEVELUP_INFO, (4 + 4 + MAX_POWERS * 4 + MAX_STATS * 4));
    data << uint32(level);
    data << hp;
    data << uint32(GetPowerType() == POWER_MANA ? mana : 0);
    data << uint32(0);
    data << uint32(0);
    data << uint32(0);
    data << uint32(0);
    // end for
    for (int i = STAT_STRENGTH; i < MAX_STATS; ++i)         // Stats loop (0-4)
        data << uint32(int32(info.stats[i]) - GetCreateStat(Stats(i)));

    GetSession()->SendPacket(&data);
    
    SetUInt32Value(PLAYER_NEXT_LEVEL_XP, sObjectMgr.GetXPForLevel(level));

    //update level, max level of skills
    if (GetLevel() != level)
        m_playedTime[PLAYED_TIME_LEVEL] = 0;               // Level Played Time reset
    SetLevel(level);
    UpdateSkillsForLevel();

    // save base values (bonuses already included in stored stats
    for (int i = STAT_STRENGTH; i < MAX_STATS; ++i)
        SetCreateStat(Stats(i), info.stats[i]);

    SetCreateHealth(classInfo.basehealth);
    SetCreateMana(classInfo.basemana);

    InitTalentForLevel();

    UpdateAllStats();

    // set current level health and mana/energy to maximum after applying all mods.
    if (IsAlive())
        SetHealth(GetMaxHealth());
    SetPower(POWER_MANA, GetMaxPower(POWER_MANA));
    SetPower(POWER_ENERGY, GetMaxPower(POWER_ENERGY));

    if (GetPower(POWER_RAGE) > GetMaxPower(POWER_RAGE))
        SetPower(POWER_RAGE, GetMaxPower(POWER_RAGE));
    SetPower(POWER_FOCUS, 0);
    SetPower(POWER_HAPPINESS, 0);

    // update level to hunter/summon pet
    if (Pet* pet = GetPet())
        pet->SynchronizeLevelWithOwner();

    if (m_session->ShouldBeBanned(GetLevel()))
        sWorld.BanAccount(BAN_ACCOUNT, m_session->GetUsername(), 0, m_session->GetScheduleBanReason(), "");
}

void Player::UpdateFreeTalentPoints(bool resetIfNeed)
{
    uint32 level = GetLevel();
    // talents base at level diff (talents = level - 9 but some can be used already)
    if (level < 10)
    {
        // Remove all talent points
        if (m_usedTalentCount > 0)                           // Free any used talents
        {
            if (resetIfNeed)
                ResetTalents(true);
            SetFreeTalentPoints(0);
        }
    }
    else
    {
        uint32 talentPointsForLevel = CalculateTalentsPoints();

        // if used more that have then reset
        if (m_usedTalentCount > talentPointsForLevel)
        {
            if (resetIfNeed && GetSession()->GetSecurity() < SEC_ADMINISTRATOR)
                ResetTalents(true);
            else
                SetFreeTalentPoints(0);
        }
        // else update amount of free points
        else
            SetFreeTalentPoints(talentPointsForLevel - m_usedTalentCount);
    }
}

void Player::InitTalentForLevel()
{
    UpdateFreeTalentPoints();
}

void Player::InitStatsForLevel(bool reapplyMods)
{
    if (reapplyMods)                                        //reapply stats values only on .reset stats (level) command
        _RemoveAllStatBonuses();

    PlayerClassLevelInfo classInfo;
    sObjectMgr.GetPlayerClassLevelInfo(GetClass(), GetLevel(), &classInfo);

    PlayerLevelInfo info;
    sObjectMgr.GetPlayerLevelInfo(GetRace(), GetClass(), GetLevel(), &info);

    SetUInt32Value(PLAYER_NEXT_LEVEL_XP, sObjectMgr.GetXPForLevel(GetLevel()));

    // reset before any aura state sources (health set/aura apply)
    SetUInt32Value(UNIT_FIELD_AURASTATE, 0);

    UpdateSkillsForLevel();

    // set default cast time multiplier
#if SUPPORTED_CLIENT_BUILD >= CLIENT_BUILD_1_12_1
    SetFloatValue(UNIT_MOD_CAST_SPEED, 1.0f);
#else
    SetInt32Value(UNIT_MOD_CAST_SPEED, 0);
#endif

    // save base values (bonuses already included in stored stats)
    for (int i = STAT_STRENGTH; i < MAX_STATS; ++i)
        SetCreateStat(Stats(i), info.stats[i]);

    for (int i = STAT_STRENGTH; i < MAX_STATS; ++i)
        SetStat(Stats(i), info.stats[i]);

    SetCreateHealth(classInfo.basehealth);

    //set create powers
    SetCreateMana(classInfo.basemana);

    SetArmor(int32(m_createStats[STAT_AGILITY] * 2));

    InitStatBuffMods();

    //[-ZERO] SetUInt32Value(PLAYER_FIELD_MOD_HEALING_DONE_POS,0);
    for (int i = 0; i < MAX_SPELL_SCHOOL; ++i)
    {
        SetUInt32Value(PLAYER_FIELD_MOD_DAMAGE_DONE_NEG + i, 0);
        SetUInt32Value(PLAYER_FIELD_MOD_DAMAGE_DONE_POS + i, 0);
        SetFloatValue(PLAYER_FIELD_MOD_DAMAGE_DONE_PCT + i, 1.00f);
    }

    //reset attack power, damage and attack speed fields
    SetFloatValue(UNIT_FIELD_BASEATTACKTIME, 2000.0f);
    SetFloatValue(UNIT_FIELD_BASEATTACKTIME + 1, 2000.0f);  // offhand attack time
    SetFloatValue(UNIT_FIELD_RANGEDATTACKTIME, 2000.0f);

    SetFloatValue(UNIT_FIELD_MINDAMAGE, 0.0f);
    SetFloatValue(UNIT_FIELD_MAXDAMAGE, 0.0f);
    SetFloatValue(UNIT_FIELD_MINOFFHANDDAMAGE, 0.0f);
    SetFloatValue(UNIT_FIELD_MAXOFFHANDDAMAGE, 0.0f);
    SetFloatValue(UNIT_FIELD_MINRANGEDDAMAGE, 0.0f);
    SetFloatValue(UNIT_FIELD_MAXRANGEDDAMAGE, 0.0f);

    SetInt32Value(UNIT_FIELD_ATTACK_POWER,            0);
    SetInt32Value(UNIT_FIELD_ATTACK_POWER_MODS,       0);
#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_8_4
    SetFloatValue(UNIT_FIELD_ATTACK_POWER_MULTIPLIER, 0.0f);
#endif
    SetInt32Value(UNIT_FIELD_RANGED_ATTACK_POWER,     0);
    SetInt32Value(UNIT_FIELD_RANGED_ATTACK_POWER_MODS, 0);
#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_8_4
    SetFloatValue(UNIT_FIELD_RANGED_ATTACK_POWER_MULTIPLIER, 0.0f);
#endif

    // Base crit values (will be recalculated in UpdateAllStats() at loading and in _ApplyAllStatBonuses() at reset
    SetFloatValue(PLAYER_CRIT_PERCENTAGE, 0.0f);
    SetFloatValue(PLAYER_RANGED_CRIT_PERCENTAGE, 0.0f);

    // Init spell schools (will be recalculated in UpdateAllStats() at loading and in _ApplyAllStatBonuses() at reset
    for (float & i : m_SpellCritPercentage)
        i = 0.0f;

    SetFloatValue(PLAYER_PARRY_PERCENTAGE, 0.0f);
    SetFloatValue(PLAYER_BLOCK_PERCENTAGE, 0.0f);

    // Dodge percentage
    SetFloatValue(PLAYER_DODGE_PERCENTAGE, 0.0f);

    // set armor (resistance 0) to original value (create_agility*2)
    SetArmor(int32(m_createStats[STAT_AGILITY] * 2));
    SetResistanceBuffMods(SpellSchools(0), true, 0.0f);
    SetResistanceBuffMods(SpellSchools(0), false, 0.0f);
    // set other resistance to original value (0)
    for (int i = 1; i < MAX_SPELL_SCHOOL; ++i)
    {
        SetResistance(SpellSchools(i), 0);
        SetResistanceBuffMods(SpellSchools(i), true, 0.0f);
        SetResistanceBuffMods(SpellSchools(i), false, 0.0f);
    }

//[-ZERO]    SetUInt32Value(PLAYER_FIELD_MOD_TARGET_RESISTANCE,0);
//[-ZERO]    SetUInt32Value(PLAYER_FIELD_MOD_TARGET_PHYSICAL_RESISTANCE,0);
#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_6_1
    for (int i = 0; i < MAX_SPELL_SCHOOL; ++i)
    {
        SetUInt32Value(UNIT_FIELD_POWER_COST_MODIFIER + i, 0);
        SetFloatValue(UNIT_FIELD_POWER_COST_MULTIPLIER + i, 0.0f);
    }
#endif
    // Init data for form but skip reapply item mods for form
    InitDataForForm(reapplyMods);

    // save new stats
    for (int i = POWER_MANA; i < MAX_POWERS; ++i)
        SetMaxPower(Powers(i),  GetCreatePowers(Powers(i)));

    SetMaxHealth(classInfo.basehealth);                     // stamina bonus will applied later

    // cleanup mounted state (it will set correctly at aura loading if player saved at mount.
    SetUInt32Value(UNIT_FIELD_MOUNTDISPLAYID, 0);

    // cleanup unit flags (will be re-applied if need at aura load).
    RemoveFlag(UNIT_FIELD_FLAGS,
               UNIT_FLAG_NON_ATTACKABLE   | UNIT_FLAG_DISABLE_MOVE  | UNIT_FLAG_NOT_ATTACKABLE_1 |
               UNIT_FLAG_IMMUNE_TO_PLAYER | UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_LOOTING          |
               UNIT_FLAG_PET_IN_COMBAT    | UNIT_FLAG_SILENCED      | UNIT_FLAG_PACIFIED         |
               UNIT_FLAG_STUNNED          | UNIT_FLAG_IN_COMBAT     | UNIT_FLAG_DISARMED         |
               UNIT_FLAG_CONFUSED         | UNIT_FLAG_FLEEING       | UNIT_FLAG_NOT_SELECTABLE   |
               UNIT_FLAG_SKINNABLE        | UNIT_FLAG_IMMUNE        | UNIT_FLAG_AURAS_VISIBLE    | UNIT_FLAG_TAXI_FLIGHT);
    SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_PLAYER_CONTROLLED);    // must be set

    // cleanup player flags (will be re-applied if need at aura load), to avoid have ghost flag without ghost aura, for example.
    RemoveFlag(PLAYER_FLAGS, PLAYER_FLAGS_AFK | PLAYER_FLAGS_DND | PLAYER_FLAGS_GM | PLAYER_FLAGS_GHOST | PLAYER_FLAGS_FFA_PVP);

    // one form stealth modified bytes
    RemoveByteFlag(UNIT_FIELD_BYTES_1, UNIT_BYTES_1_OFFSET_VIS_FLAG, UNIT_VIS_FLAGS_ALL);

    // restore if need some important flags
    SetUInt32Value(PLAYER_FIELD_BYTES2, 0);                 // flags empty by default

    if (reapplyMods)                                        //reapply stats values only on .reset stats (level) command
        _ApplyAllStatBonuses();

    // set current level health and mana/energy to maximum after applying all mods.
    SetHealth(GetMaxHealth());
    SetPower(POWER_MANA, GetMaxPower(POWER_MANA));
    SetPower(POWER_ENERGY, GetMaxPower(POWER_ENERGY));
    if (GetPower(POWER_RAGE) > GetMaxPower(POWER_RAGE))
        SetPower(POWER_RAGE, GetMaxPower(POWER_RAGE));
    SetPower(POWER_FOCUS, 0);
    SetPower(POWER_HAPPINESS, 0);

    // update level to hunter/summon pet
    if (Pet* pet = GetPet())
        pet->SynchronizeLevelWithOwner();
}

void Player::SendInitialSpells() const
{
    uint16 spellCount = 0;

    WorldPacket data(SMSG_INITIAL_SPELLS, (1 + 2 + 4 * m_spells.size() + 2 + m_cooldownMap.size() * (2 + 2 + 2 + 4 + 4)));
    data << uint8(0);

    size_t countPos = data.wpos();
    data << uint16(spellCount);                             // spell count placeholder

    for (const auto& spell : m_spells)
    {
        if (spell.second.state == PLAYERSPELL_REMOVED)
            continue;

        if (!spell.second.active || spell.second.disabled)
            continue;

        data << uint16(spell.first);
        data << uint16(0);                                  // it's not slot id

        spellCount += 1;
    }

    data.put<uint16>(countPos, spellCount);                 // write real count value

    // write cooldown data
    uint32 cdCount = 0;
    const size_t cdCountPos = data.wpos();
    data << uint16(0);
    auto currTime = sWorld.GetCurrentClockTime();

    for (auto& cdItr : m_cooldownMap)
    {
        auto& cdData = cdItr.second;
        TimePoint spellRecTime = currTime;
        TimePoint catRecTime = currTime;
        cdData->GetSpellCDExpireTime(spellRecTime);
        cdData->GetCatCDExpireTime(catRecTime);
        uint32 spellCDDuration = 0;
        uint32 catCDDuration = 0;
        if (spellRecTime > currTime)
            spellCDDuration = std::chrono::duration_cast<std::chrono::milliseconds>(spellRecTime - currTime).count();
        if (catRecTime > currTime)
            catCDDuration = std::chrono::duration_cast<std::chrono::milliseconds>(catRecTime - currTime).count();

        if (!spellCDDuration && !catCDDuration && !cdData->IsPermanent())
            continue;

        if (cdData->IsPermanent())
        {
            spellCDDuration = uint32(1);                              // cooldown
            catCDDuration |= 0x80000000;
        }

        data << uint16(cdData->GetSpellId());
        data << uint16(cdData->GetItemId());                // cast item id
        data << uint16(cdData->GetCategory());              // spell category
        data << uint32(spellCDDuration);                    // cooldown
        data << uint32(catCDDuration);                      // category cooldown
        ++cdCount;
    }

    data.put<uint16>(cdCountPos, cdCount);

    GetSession()->SendPacket(&data);

    DETAIL_LOG("CHARACTER: Sent Initial Spells");
}

bool Player::AddSpell(uint32 spellId, bool active, bool learning, bool dependent, bool disabled)
{
    SpellEntry const* spellInfo = sSpellMgr.GetSpellEntry(spellId);
    if (!spellInfo)
    {
        // do character spell book cleanup (all characters)
        if (!IsInWorld() && !learning)                      // spell load case
        {
            sLog.outError("Player::AddSpell: nonexistent in SpellStore spell #%u request, deleting for all characters in `character_spell`.", spellId);
            CharacterDatabase.PExecute("DELETE FROM `character_spell` WHERE `spell` = '%u'", spellId);
        }
        else
            sLog.outError("Player::AddSpell: nonexistent in SpellStore spell #%u request.", spellId);

        return false;
    }

    if (!SpellMgr::IsSpellValid(spellInfo, this, false))
    {
        // do character spell book cleanup (all characters)
        if (!IsInWorld() && !learning)                      // spell load case
        {
            sLog.outError("Player::AddSpell: Broken spell #%u learning not allowed, deleting for all characters in `character_spell`.", spellId);
            CharacterDatabase.PExecute("DELETE FROM `character_spell` WHERE `spell` = '%u'", spellId);
        }
        else
            sLog.outError("Player::AddSpell: Broken spell #%u learning not allowed.", spellId);

        return false;
    }

    PlayerSpellState state = learning ? PLAYERSPELL_NEW : PLAYERSPELL_UNCHANGED;

    bool disabled_case = false;
    bool superceded_old = false;

    PlayerSpellMap::iterator itr = m_spells.find(spellId);
    if (itr != m_spells.end())
    {
        uint32 next_active_spell_id = 0;
        bool dependent_set = false;

        // fix activate state for non-stackable low rank (and find next spell for !active case)
        if (uint32 nextId = sSpellMgr.GetSpellBookSuccessorSpellId(spellInfo->Id))
        {
            if (HasSpell(nextId))
            {
                // high rank already known so this must !active
                active = false;
                next_active_spell_id = nextId;
            }
        }

        // not do anything if already known in expected state
        if (itr->second.state != PLAYERSPELL_REMOVED && itr->second.active == active &&
                itr->second.dependent == dependent && itr->second.disabled == disabled)
        {
            if (!IsInWorld() && !learning)                  // explicitly load from DB and then exist in it already and set correctly
                itr->second.state = PLAYERSPELL_UNCHANGED;

            return false;
        }

        // dependent spell known as not dependent, overwrite state
        if (itr->second.state != PLAYERSPELL_REMOVED && !itr->second.dependent && dependent)
        {
            itr->second.dependent = dependent;
            if (itr->second.state != PLAYERSPELL_NEW)
                itr->second.state = PLAYERSPELL_CHANGED;
            dependent_set = true;
        }

        // update active state for known spell
        if (itr->second.active != active && itr->second.state != PLAYERSPELL_REMOVED && !itr->second.disabled)
        {
            itr->second.active = active;

            if (!IsInWorld() && !learning && !dependent_set) // explicitly load from DB and then exist in it already and set correctly
                itr->second.state = PLAYERSPELL_UNCHANGED;
            else if (itr->second.state != PLAYERSPELL_NEW)
                itr->second.state = PLAYERSPELL_CHANGED;

            if (active)
            {
                if (IsNeedCastPassiveLikeSpellAtLearn(spellInfo))
                    CastSpell(this, spellId, true);
            }
            else if (IsInWorld())
            {
                if (next_active_spell_id)
                {
                    // update spell ranks in spellbook and action bar
                    WorldPacket data(SMSG_SUPERCEDED_SPELL, (4));
                    data << uint16(spellId);
                    data << uint16(next_active_spell_id);
                    GetSession()->SendPacket(&data);
                }
                else
                    SendSpellRemoved(spellId);
            }

            return active;                                  // learn (show in spell book if active now)
        }

        if (itr->second.disabled != disabled && itr->second.state != PLAYERSPELL_REMOVED)
        {
            if (itr->second.state != PLAYERSPELL_NEW)
                itr->second.state = PLAYERSPELL_CHANGED;
            itr->second.disabled = disabled;

            if (disabled)
                return false;

            disabled_case = true;
        }
        else switch (itr->second.state)
            {
                case PLAYERSPELL_UNCHANGED:                     // known saved spell
                    return false;
                case PLAYERSPELL_REMOVED:                       // re-learning removed not saved spell
                {
                    m_spells.erase(itr);
                    state = PLAYERSPELL_CHANGED;
                    break;                                      // need re-add
                }
                default:                                        // known not saved yet spell (new or modified)
                {
                    // can be in case spell loading but learned at some previous spell loading
                    if (!IsInWorld() && !learning && !dependent_set)
                        itr->second.state = PLAYERSPELL_UNCHANGED;

                    return false;
                }
            }
    }

    TalentSpellPos const* talentPos = GetTalentSpellPos(spellId);

    if (!disabled_case) // skip new spell adding if spell already known (disabled spells case)
    {
        // talent: unlearn all other talent ranks (high and low)
        if (talentPos)
        {
            if (TalentEntry const* talentInfo = sTalentStore.LookupEntry(talentPos->talent_id))
            {
                for (uint32 rankSpellId : talentInfo->RankID)
                {
                    // skip learning spell and no rank spell case
                    if (!rankSpellId || rankSpellId == spellId)
                        continue;

                    RemoveSpell(rankSpellId, false, false);
                }
            }
        }
        // non talent spell: learn low ranks (recursive call)
        else if (uint32 prev_spell = sSpellMgr.GetPrevSpellInChain(spellId))
        {
            if (!IsInWorld() || disabled)                   // at spells loading, no output, but allow save
                AddSpell(prev_spell, active, true, true, disabled);
            else                                            // at normal learning
                LearnSpell(prev_spell, true);
        }

        PlayerSpell newspell;
        newspell.state     = state;
        newspell.active    = active;
        newspell.dependent = dependent;
        newspell.disabled  = disabled;

        // replace spells in action bars and spellbook to bigger rank if only one spell rank must be accessible
        if (newspell.active && !newspell.disabled)
        {
            for (auto& m_spell : m_spells)
            {
                PlayerSpell& playerSpell2 = m_spell.second;

                if (playerSpell2.state == PLAYERSPELL_REMOVED)
                    continue;

                if (uint32 nextId = sSpellMgr.GetSpellBookSuccessorSpellId(m_spell.first))
                {
                    if (playerSpell2.active)
                    {
                        if (nextId == spellId)
                        {
                            if (IsInWorld())                // not send spell (re-/over-)learn packets at loading
                            {
                                WorldPacket data(SMSG_SUPERCEDED_SPELL, (4));
                                data << uint16(m_spell.first);
                                data << uint16(spellId);
                                GetSession()->SendPacket(&data);
                            }

                            // mark old spell as disable (SMSG_SUPERCEDED_SPELL replace it in client by new)
                            playerSpell2.active = false;
                            if (playerSpell2.state != PLAYERSPELL_NEW)
                                playerSpell2.state = PLAYERSPELL_CHANGED;
                            superceded_old = true;          // new spell replace old in action bars and spell book.
                        }
                        else if (m_spell.first == spellId)
                        {
                            if (IsInWorld())                // not send spell (re-/over-)learn packets at loading
                            {
                                WorldPacket data(SMSG_SUPERCEDED_SPELL, (4));
                                data << uint16(spellId);
                                data << uint16(m_spell.first);
                                GetSession()->SendPacket(&data);
                            }

                            // mark new spell as disable (not learned yet for client and will not learned)
                            newspell.active = false;
                            if (newspell.state != PLAYERSPELL_NEW)
                                newspell.state = PLAYERSPELL_CHANGED;
                            playerSpell2.disabled = false;
                            playerSpell2.state = PLAYERSPELL_CHANGED;
                        }
                    }
                }
            }
        }

        m_spells[spellId] = newspell;

        // return false if spell disabled
        if (newspell.disabled)
            return false;
    }

    if (talentPos)
    {
        // update used talent points count
        m_usedTalentCount += GetTalentSpellCost(talentPos);
        UpdateFreeTalentPoints(false);
    }

    // update free primary prof.points (if any, can be none in case GM .learn prof. learning)
    if (uint32 freeProfs = GetFreePrimaryProfessionPoints())
    {
        if (sSpellMgr.IsPrimaryProfessionFirstRankSpell(spellId))
            SetFreePrimaryProfessions(freeProfs - 1);
    }

    // cast talents with SPELL_EFFECT_LEARN_SPELL (other dependent spells will learned later as not auto-learned)
    // note: all spells with SPELL_EFFECT_LEARN_SPELL isn't passive
    if (talentPos && spellInfo->HasEffect(SPELL_EFFECT_LEARN_SPELL))
    {
        // ignore stance requirement for talent learn spell (stance set for spell only for client spell description show)
        CastSpell(this, spellId, true);
    }
    // also cast passive (and passive like) spells (including all talents without SPELL_EFFECT_LEARN_SPELL) with additional checks
    else if (IsNeedCastPassiveLikeSpellAtLearn(spellInfo))
        CastSpell(this, spellId, true);
    else if (spellInfo->HasEffect(SPELL_EFFECT_SKILL_STEP))
    {
        CastSpell(this, spellId, true);
        return false;
    }

    // add dependent skills
    UpdateSpellTrainedSkills(spellId, true);

    // learn dependent spells
    SpellLearnSpellMapBounds spell_bounds = sSpellMgr.GetSpellLearnSpellMapBounds(spellId);

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

    // return true (for send learn packet) only if spell active (in case ranked spells) and not replace old spell
    return active && !disabled && !superceded_old;
}

bool Player::IsNeedCastPassiveLikeSpellAtLearn(SpellEntry const* spellInfo) const
{
    ShapeshiftForm form = GetShapeshiftForm();

    if (spellInfo->IsNeedCastSpellAtFormApply(form))        // SPELL_ATTR_PASSIVE | SPELL_ATTR_UNK7 spells
        return true;                                        // all stance req. cases, not have auarastate cases

    if (!(spellInfo->Attributes & SPELL_ATTR_PASSIVE))
        return false;

    // note: form passives activated with shapeshift spells be implemented by HandleShapeshiftBoosts instead of spell_learn_spell
    // talent dependent passives activated at form apply have proper stance data
    bool need_cast = (!spellInfo->Stances || (!form && (spellInfo->AttributesEx2 & SPELL_ATTR_EX2_NOT_NEED_SHAPESHIFT)));

    // Check CasterAuraStates
    return need_cast && (!spellInfo->CasterAuraState || HasAuraState(AuraState(spellInfo->CasterAuraState)));
}

void Player::LearnSpell(uint32 spellId, bool dependent, bool talent)
{
    PlayerSpellMap::iterator itr = m_spells.find(spellId);

    bool disabled = (itr != m_spells.end()) ? itr->second.disabled : false;
    bool active = disabled ? itr->second.active : true;

    bool learning = AddSpell(spellId, active, true, dependent, false);

    // prevent duplicated entires in spell book, also not send if not in world (loading)
    if (learning && IsInWorld())
    {
        WorldPacket data(SMSG_LEARNED_SPELL, 4);
        data << uint32(spellId);
        GetSession()->SendPacket(&data);
    }

    // learn all disabled higher ranks (recursive) - skip for talent spells
    if (disabled || talent)
    {
        SpellChainMapNext const& nextMap = sSpellMgr.GetSpellChainNext();
        for (SpellChainMapNext::const_iterator i = nextMap.lower_bound(spellId); i != nextMap.upper_bound(spellId); ++i)
        {
            PlayerSpellMap::iterator iter = m_spells.find(i->second);
            if (iter != m_spells.end() && iter->second.disabled)
                LearnSpell(i->second, false);
        }
    }
}

void Player::RemoveSpell(uint32 spellId, bool disabled, bool learn_low_rank)
{
    PlayerSpellMap::iterator itr = m_spells.find(spellId);
    if (itr == m_spells.end())
        return;

    // Always try to remove all dependent spells if present (needed to reset some talents properly)
    SpellLearnSpellMapBounds spell_bounds = sSpellMgr.GetSpellLearnSpellMapBounds(spellId);
    for (SpellLearnSpellMap::const_iterator child_itr = spell_bounds.first; child_itr != spell_bounds.second; ++child_itr)
        RemoveSpell(child_itr->second.spell, !Spells::IsPassiveSpell(child_itr->second.spell), !Spells::IsPassiveSpell(child_itr->second.spell));

    // search again just in case
    itr = m_spells.find(spellId);
    if (itr == m_spells.end())
        return;

    PlayerSpell& playerSpell = itr->second;
    if (playerSpell.state == PLAYERSPELL_REMOVED || (disabled && playerSpell.disabled))
        return;

    if (disabled && GetTalentSpellPos(spellId))
        disabled = false; // talents should never be marked as disabled

                          // unlearn non talent higher ranks (recursive)
    SpellChainMapNext const& nextMap = sSpellMgr.GetSpellChainNext();
    for (SpellChainMapNext::const_iterator itr2 = nextMap.lower_bound(spellId); itr2 != nextMap.upper_bound(spellId); ++itr2)
        if (HasSpell(itr2->second) && !GetTalentSpellPos(itr2->second))
            RemoveSpell(itr2->second, !Spells::IsPassiveSpell(itr2->second), false);

    // re-search, it can be corrupted in prev loop
    itr = m_spells.find(spellId);
    if (itr == m_spells.end() || playerSpell.state == PLAYERSPELL_REMOVED)
        return;

    bool cur_active    = itr->second.active;
    bool cur_dependent = itr->second.dependent;

    if (disabled)
    {
        itr->second.disabled = disabled;
        if (itr->second.state != PLAYERSPELL_NEW)
            itr->second.state = PLAYERSPELL_CHANGED;
    }
    else
    {
        if (itr->second.state == PLAYERSPELL_NEW)
            m_spells.erase(itr);
        else
            itr->second.state = PLAYERSPELL_REMOVED;
    }

    RemoveAurasDueToSpell(spellId);

    // remove pet auras
    if (PetAura const* petSpell = sSpellMgr.GetPetAura(spellId))
        RemovePetAura(petSpell);

    TalentSpellPos const* talentPos = GetTalentSpellPos(spellId);
    if (talentPos)
    {
        // free talent points
        uint32 talentCosts = GetTalentSpellCost(talentPos);

        if (talentCosts < m_usedTalentCount)
            m_usedTalentCount -= talentCosts;
        else
            m_usedTalentCount = 0;

        UpdateFreeTalentPoints(false);
    }

    // update free primary prof.points (if not overflow setting, can be in case GM use before .learn prof. learning)
    if (sSpellMgr.IsPrimaryProfessionFirstRankSpell(spellId))
    {
        uint32 freeProfs = GetFreePrimaryProfessionPoints() + 1;
        if (freeProfs <= sWorld.getConfig(CONFIG_UINT32_MAX_PRIMARY_TRADE_SKILL))
            SetFreePrimaryProfessions(freeProfs);
    }

    // remove dependent skills
    UpdateSpellTrainedSkills(spellId, false);

    // activate lesser rank in spellbook/action bar, and cast it if need
    bool prev_activate = false;

    if (uint32 prev_id = sSpellMgr.GetPrevSpellInChain(spellId))
    {
        uint32 nextId = sSpellMgr.GetSpellBookSuccessorSpellId(prev_id);

        // if talent then lesser rank also talent and need learn
        if (talentPos)
        {
            if (learn_low_rank)
                LearnSpell(prev_id, false);
        }
        // if ranked non-stackable spell: need activate lesser rank and update dependence state
        else if (cur_active && nextId == spellId)
        {
            // need manually update dependence state (learn spell ignore like attempts)
            PlayerSpellMap::iterator prev_itr = m_spells.find(prev_id);
            if (prev_itr != m_spells.end())
            {
                PlayerSpell& spell = prev_itr->second;
                if (spell.dependent != cur_dependent)
                {
                    spell.dependent = cur_dependent;
                    if (spell.state != PLAYERSPELL_NEW)
                        spell.state = PLAYERSPELL_CHANGED;
                }

                // now re-learn if need re-activate
                if (cur_active && !spell.active && learn_low_rank)
                {
                    if (AddSpell(prev_id, true, false, spell.dependent, spell.disabled))
                    {
                        // downgrade spell ranks in spellbook and action bar
                        WorldPacket data(SMSG_SUPERCEDED_SPELL, 4);
                        data << uint16(spellId);
                        data << uint16(prev_id);
                        GetSession()->SendPacket(&data);
                        prev_activate = true;
                    }
                }
            }
}
    }

    // remove from spell book if not replaced by lesser rank
    if (!prev_activate)
        SendSpellRemoved(spellId);
}

void Player::_LoadSpellCooldowns(QueryResult* result)
{
    // some cooldowns can be already set at aura loading...
    // QueryResult *result = CharacterDatabase.PQuery("SELECT `spell`, `spell_expire_time`, `category`, `category_expire_time`, `item_id` FROM `character_spell_cooldown` WHERE `guid` = '%u'",GetGUIDLow());

    if (result)
    {
        auto curTime = sWorld.GetCurrentClockTime();

        do
        {
            Field* fields = result->Fetch();

            uint32 spellId = fields[0].GetUInt32();
            uint64 spellTime = fields[1].GetUInt64();
            uint32 category = fields[2].GetUInt32();
            uint64 categoryTime = fields[3].GetUInt64();
            uint32 itemId = fields[4].GetUInt32();

            SpellEntry const* spellEntry = sSpellMgr.GetSpellEntry(spellId);
            if (!spellEntry)
            {
                sLog.outError("%s has unknown spell %u in `character_spell_cooldown`, skipping.", GetGuidStr().c_str(), spellId);
                continue;
            }

            ItemPrototype const* itemProto = nullptr;
            if (itemId)
            {
                itemProto = ObjectMgr::GetItemPrototype(itemId);
                if (!itemProto)
                {
                    sLog.outError("%s has unknown item ID %u in `character_spell_cooldown`, skipping.", GetGuidStr().c_str(), itemId);
                    continue;
                }
            }

            TimePoint spellExpireTime = std::chrono::time_point_cast<std::chrono::milliseconds>(Clock::from_time_t(spellTime));
            TimePoint catExpireTime = std::chrono::time_point_cast<std::chrono::milliseconds>(Clock::from_time_t(categoryTime));
            std::chrono::milliseconds spellRecTime = std::chrono::milliseconds::zero();
            std::chrono::milliseconds catRecTime = std::chrono::milliseconds::zero();
            if (spellExpireTime > curTime)
                spellRecTime = std::chrono::duration_cast<std::chrono::milliseconds>(spellExpireTime - curTime);
            if (catExpireTime > curTime)
                catRecTime = std::chrono::duration_cast<std::chrono::milliseconds>(catExpireTime - curTime);

            // skip outdated cooldown
            if (spellRecTime == std::chrono::milliseconds::zero() && catRecTime == std::chrono::milliseconds::zero())
                continue;

            m_cooldownMap.AddCooldown(curTime, spellId, uint32(spellRecTime.count()), category, uint32(catRecTime.count()), itemId);
#ifdef _DEBUG
            uint32 spellCDDuration = std::chrono::duration_cast<std::chrono::seconds>(spellRecTime).count();
            uint32 catCDDuration = std::chrono::duration_cast<std::chrono::seconds>(catRecTime).count();
            std::string itemStr = "";
            if (itemId)
                itemStr = " caused by item id(" + std::to_string(itemId) + ") ";
            sLog.outDebug("Adding spell cooldown to %s, SpellID(%u), recDuration(%us), category(%u), catRecDuration(%us)%s.", GetGuidStr().c_str(),
                spellId, spellCDDuration, category, catCDDuration, itemStr.c_str());
#endif
        }
        while (result->NextRow());
    }
}

void Player::_SaveSpellCooldowns()
{
    static SqlStatementID deleteSpellCooldown;

    // delete all old cooldown
    SqlStatement stmt = CharacterDatabase.CreateStatement(deleteSpellCooldown, "DELETE FROM `character_spell_cooldown` WHERE `guid` = ?");
    stmt.PExecute(GetGUIDLow());

    static SqlStatementID insertSpellCooldown;

    for (auto& cdItr : m_cooldownMap)
    {
        auto& cdData = cdItr.second;
        if (!cdData->IsPermanent())
        {
            TimePoint sTime = TimePoint::min();
            TimePoint cTime = TimePoint::min();
            cdData->GetSpellCDExpireTime(sTime);
            cdData->GetCatCDExpireTime(cTime);
            uint64 spellExpireTime = uint64(Clock::to_time_t(sTime));
            uint64 catExpireTime = uint64(Clock::to_time_t(cTime));

            stmt = CharacterDatabase.CreateStatement(insertSpellCooldown, "INSERT INTO `character_spell_cooldown` (`guid`, `spell`, `spell_expire_time`, `category`, `category_expire_time`, `item_id`) VALUES( ?, ?, ?, ?, ?, ?)");
            stmt.addUInt32(GetGUIDLow());
            stmt.addUInt32(cdData->GetSpellId());
            stmt.addUInt64(spellExpireTime);
            stmt.addUInt32(cdData->GetCategory());
            stmt.addUInt64(catExpireTime);
            stmt.addUInt32(cdData->GetItemId());
            stmt.Execute();
        }
    }
}

void Player::UpdateResetTalentsMultiplier() const
{
    time_t months = (sWorld.GetGameTime() - m_resetTalentsTime) / MONTH;

    if (months > 0)
    {
        uint32 minMulti = sWorld.getConfig(CONFIG_UINT32_RESPEC_MIN_MULTIPLIER);
        bool clamp = m_resetTalentsMultiplier >= minMulti;

        if (months > m_resetTalentsMultiplier)
        {
            m_resetTalentsMultiplier = 0;
        }
        else
        {
            m_resetTalentsMultiplier -= months;
        }

        if (clamp && m_resetTalentsMultiplier < minMulti)
        {
            m_resetTalentsMultiplier = minMulti;
        }
    }
}

uint32 Player::GetResetTalentsCost() const
{
    // decay respec cost
    if (!sWorld.getConfig(CONFIG_BOOL_NO_RESPEC_PRICE_DECAY) || (sWorld.GetWowPatch() >= WOW_PATCH_111))
        UpdateResetTalentsMultiplier();

    if (!m_resetTalentsMultiplier) // initial respec
    {
        return sWorld.getConfig(CONFIG_UINT32_RESPEC_BASE_COST) * GOLD;
    }

    uint32 multiCost = sWorld.getConfig(CONFIG_UINT32_RESPEC_MULTIPLICATIVE_COST);
    uint32 maxMulti = sWorld.getConfig(CONFIG_UINT32_RESPEC_MAX_MULTIPLIER);

    if (m_resetTalentsMultiplier > maxMulti)
    {
        return (multiCost * maxMulti) * GOLD;
    }

    return (m_resetTalentsMultiplier * multiCost) * GOLD;
}

bool Player::ResetTalents(bool no_cost)
{
    // not need after this call
    if (HasAtLoginFlag(AT_LOGIN_RESET_TALENTS))
        RemoveAtLoginFlag(AT_LOGIN_RESET_TALENTS, true);

    if (m_usedTalentCount == 0)
    {
        UpdateFreeTalentPoints(false);                      // for fix if need counter
        return false;
    }

    uint32 cost = 0;

    if (!no_cost)
    {
        cost = GetResetTalentsCost();

        if (GetMoney() < cost)
        {
            SendBuyError(BUY_ERR_NOT_ENOUGHT_MONEY, 0, 0, 0);
            return false;
        }
    }

    for (uint32 i = 0; i < sTalentStore.GetNumRows(); ++i)
    {
        TalentEntry const* talentInfo = sTalentStore.LookupEntry(i);

        if (!talentInfo) continue;

        TalentTabEntry const* talentTabInfo = sTalentTabStore.LookupEntry(talentInfo->TalentTab);

        if (!talentTabInfo)
            continue;

        // unlearn only talents for character class
        // some spell learned by one class as normal spells or know at creation but another class learn it as talent,
        // to prevent unexpected lost normal learned spell skip another class talents
        if ((GetClassMask() & talentTabInfo->ClassMask) == 0)
            continue;

        for (uint32 j : talentInfo->RankID)
        {
            SpellEntry const* pInfos = sSpellMgr.GetSpellEntry(j);
            if (pInfos)
                for (uint32 eff : pInfos->EffectTriggerSpell)
                    if (eff)
                        RemoveAurasDueToSpell(eff);

            if (j)
                RemoveSpell(j, !Spells::IsPassiveSpell(j), false);
        }
    }

    UpdateFreeTalentPoints(false);

    if (!no_cost)
    {
        ModifyMoney(-(int32)cost);

        ++m_resetTalentsMultiplier;

        if (m_resetTalentsMultiplier > sWorld.getConfig(CONFIG_UINT32_RESPEC_MAX_MULTIPLIER))
        {
            m_resetTalentsMultiplier = sWorld.getConfig(CONFIG_UINT32_RESPEC_MAX_MULTIPLIER);
        }

        m_resetTalentsTime = time(nullptr);
    }

    //FIXME: remove pet before or after unlearn spells? for now after unlearn to allow removing of talent related, pet affecting auras
    RemovePet(PET_SAVE_REAGENTS);
    return true;
}

void Player::BuildCreateUpdateBlockForPlayer(UpdateData& data, Player* target) const
{
    if (target == this)
    {
        for (int i = 0; i < EQUIPMENT_SLOT_END; ++i)
        {
            if (m_items[i] == nullptr)
                continue;

            m_items[i]->BuildCreateUpdateBlockForPlayer(data, target);
        }
        for (int i = INVENTORY_SLOT_BAG_START; i < BANK_SLOT_BAG_END; ++i)
        {
            if (m_items[i] == nullptr)
                continue;

            m_items[i]->BuildCreateUpdateBlockForPlayer(data, target);
        }
#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_7_1
        for (int i = BUYBACK_SLOT_START; i < BUYBACK_SLOT_END; ++i)
        {
            if (m_items[i] == nullptr)
                continue;

            m_items[i]->BuildCreateUpdateBlockForPlayer(data, target);
        }
#endif
        for (int i = KEYRING_SLOT_START; i < KEYRING_SLOT_END; ++i)
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

    for (int i = 0; i < INVENTORY_SLOT_BAG_END; ++i)
    {
        if (m_items[i] == nullptr)
            continue;

        m_items[i]->DestroyForPlayer(target);
    }

    if (target == this)
    {
        for (int i = INVENTORY_SLOT_BAG_START; i < BANK_SLOT_BAG_END; ++i)
        {
            if (m_items[i] == nullptr)
                continue;

            m_items[i]->DestroyForPlayer(target);
        }
        for (int i = KEYRING_SLOT_START; i < KEYRING_SLOT_END; ++i)
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
    return (itr != m_spells.end() && itr->second.state != PLAYERSPELL_REMOVED &&
            !itr->second.disabled);
}

bool Player::HasActiveSpell(uint32 spell) const
{
    PlayerSpellMap::const_iterator itr = m_spells.find(spell);
    return (itr != m_spells.end() && itr->second.state != PLAYERSPELL_REMOVED &&
            itr->second.active && !itr->second.disabled);
}

TrainerSpellState Player::GetTrainerSpellState(TrainerSpell const* trainer_spell) const
{
    if (!trainer_spell)
        return TRAINER_SPELL_RED;

    if (!trainer_spell->spell)
        return TRAINER_SPELL_RED;

    // exist, already checked at loading
    SpellEntry const* spell = sSpellMgr.GetSpellEntry(trainer_spell->spell);
    SpellEntry const* TriggerSpell = sSpellMgr.GetSpellEntry(spell->EffectTriggerSpell[0]);


    // known spell
    if (HasSpell(TriggerSpell->Id))
        return TRAINER_SPELL_GRAY;

    // check race/class requirement
    if (!IsSpellFitByClassAndRace(TriggerSpell->Id))
        return TRAINER_SPELL_RED;

    // check level requirement
    uint32 spellLevel = trainer_spell->reqLevel ? trainer_spell->reqLevel : TriggerSpell->spellLevel;
    if (GetLevel() < spellLevel)
        return TRAINER_SPELL_RED;

    if (SpellChainNode const* spell_chain = sSpellMgr.GetSpellChainNode(TriggerSpell->Id))
    {
        // check prev.rank requirement
        if (spell_chain->prev && !HasSpell(spell_chain->prev))
            return TRAINER_SPELL_RED;

        // check additional spell requirement
        if (spell_chain->req && !HasSpell(spell_chain->req))
            return TRAINER_SPELL_RED;
    }

    // check skill requirement
    if (trainer_spell->reqSkill && GetSkillValueBase(trainer_spell->reqSkill) < trainer_spell->reqSkillValue)
        return TRAINER_SPELL_RED;

    // exist, already checked at loading
    // SpellEntry const* spell = sSpellMgr.GetSpellEntry(trainer_spell->spell);

    // secondary prof. or not prof. spell
    uint32 skill = spell->EffectMiscValue[1];

    // Some skill professions train a spell (2581 teaches 2575). We need to loop teached spell.
    bool isProfessionLearnSpell = spell->Effect[1] == SPELL_EFFECT_SKILL;
    bool isProfessionFirstRank = sSpellMgr.IsPrimaryProfessionFirstRankSpell(spell->Id);
    for (int i = 0; i < MAX_SPELL_EFFECTS && !isProfessionLearnSpell; ++i)
        if (spell->Effect[i] == SPELL_EFFECT_LEARN_SPELL)
            if (SpellEntry const* teachedSpell = sSpellMgr.GetSpellEntry(spell->EffectTriggerSpell[i]))
            {
                if (teachedSpell->Effect[1] == SPELL_EFFECT_SKILL)
                    isProfessionLearnSpell = true;
                if (sSpellMgr.IsPrimaryProfessionFirstRankSpell(teachedSpell->Id))
                    isProfessionFirstRank = true;
            }

    // Check Can learn 2581, profFirst=0, Skill=186
    if (!isProfessionLearnSpell || !IsPrimaryProfessionSkill(skill))
        return TRAINER_SPELL_GREEN;

    // check primary prof. limit
    if (isProfessionFirstRank && GetFreePrimaryProfessionPoints() == 0)
        return TRAINER_SPELL_GREEN_DISABLED;

    return TRAINER_SPELL_GREEN;
}

/**
 * Deletes a character from the database
 *
 * The way, how the characters will be deleted is decided based on the config option.
 *
 * @see Player::DeleteOldCharacters
 *
 * @param playerGuid       the low-GUID from the player which should be deleted
 * @param accountId        the account id from the player
 * @param updateRealmChars when this flag is set, the amount of characters on that realm will be updated in the realmlist
 * @param deleteFinally    if this flag is set, the config option will be ignored and the character will be permanently removed from the database
 */
void Player::DeleteFromDB(ObjectGuid playerGuid, uint32 accountId, bool updateRealmChars, bool deleteFinally)
{
    // for nonexistent account avoid update realm
    if (accountId == 0)
        updateRealmChars = false;

    uint32 charDelete_method = sWorld.getConfig(CONFIG_UINT32_CHARDELETE_METHOD);
    uint32 charDelete_minLvl = sWorld.getConfig(CONFIG_UINT32_CHARDELETE_MIN_LEVEL);

    // if we want to finally delete the character or the character does not meet the level requirement, we set it to mode 0
    if (deleteFinally)
        charDelete_method = 0;
    else
    {
        PlayerCacheData const* data = sObjectMgr.GetPlayerDataByGUID(playerGuid);
        if (data && data->uiLevel < charDelete_minLvl)
            charDelete_method = 0;
    }

    uint32 lowguid = playerGuid.GetCounter();

    // convert corpse to bones if exist (to prevent exiting Corpse in World without DB entry)
    // bones will be deleted by corpse/bones deleting thread shortly
    sObjectAccessor.ConvertCorpseForPlayer(playerGuid);

    // remove from guild
    if (Guild* guild = sGuildMgr.GetPlayerGuild(playerGuid))
    {
        if (guild->DelMember(playerGuid))
        {
            guild->Disband();
            delete guild;
        }
    }

    // the player was uninvited already on logout so just remove from group
    if (Group* group = sObjectMgr.GetGroupByMember(playerGuid))
        RemoveFromGroup(group, playerGuid);

    // remove signs from petitions (also remove petitions if owner);
    RemovePetitionsAndSigns(playerGuid);
    sObjectMgr.DeletePlayerFromCache(lowguid);

    switch (charDelete_method)
    {
        // completely remove from the database
        case 0:
        {
            // return back all mails with COD and Item                 0      1               2                   3              4          5               6        7
            QueryResult* resultMail = CharacterDatabase.PQuery("SELECT `id`, `message_type`, `mail_template_id`, `sender_guid`, `subject`, `item_text_id`, `money`, `has_items` FROM `mail` WHERE `receiver_guid`='%u' AND `has_items`<>0 AND `cod`<>0", lowguid);
            if (resultMail)
            {
                do
                {
                    Field* fields = resultMail->Fetch();

                    uint32 mail_id       = fields[0].GetUInt32();
                    uint16 mailType      = fields[1].GetUInt16();
                    uint16 mailTemplateId = fields[2].GetUInt16();
                    uint32 sender        = fields[3].GetUInt32();
                    std::string subject  = fields[4].GetCppString();
                    uint32 itemTextId    = fields[5].GetUInt32();
                    uint32 money         = fields[6].GetUInt32();
                    bool has_items       = fields[7].GetBool();

                    //we can return mail now
                    //so firstly delete the old one
                    CharacterDatabase.PExecute("DELETE FROM `mail` WHERE `id` = '%u'", mail_id);

                    // mail not from player
                    if (mailType != MAIL_NORMAL)
                    {
                        if (has_items)
                            CharacterDatabase.PExecute("DELETE FROM `mail_items` WHERE `mail_id` = '%u'", mail_id);
                        continue;
                    }

                    MailDraft draft;
                    if (mailTemplateId)
                        draft.SetMailTemplate(mailTemplateId, false); // items already included
                    else
                        draft.SetSubjectAndBodyId(subject, itemTextId);

                    if (has_items)
                    {
                        // data needs to be at first place for Item::LoadFromDB      0               1                    2        3                      5        6               7                     8             9       10                           11         12
                        QueryResult* resultItems = CharacterDatabase.PQuery("SELECT `creator_guid`, `gift_creator_guid`, `count`, `duration`, `charges`, `flags`, `enchantments`, `random_property_id`, `durability`, `text`, `item_guid`, `item_instance`.`item_id`, `generated_loot` FROM `mail_items` JOIN `item_instance` ON `item_guid` = `guid` WHERE `mail_id`='%u'", mail_id);
                        if (resultItems)
                        {
                            do
                            {
                                Field* fields2 = resultItems->Fetch();

                                uint32 itemGuidLow = fields2[10].GetUInt32();
                                uint32 itemId = fields2[11].GetUInt32();

                                ItemPrototype const* itemProto = ObjectMgr::GetItemPrototype(itemId);
                                if (!itemProto)
                                {
                                    CharacterDatabase.PExecute("DELETE FROM `item_instance` WHERE `guid` = '%u'", itemGuidLow);
                                    continue;
                                }

                                Item* pItem = NewItemOrBag(itemProto);
                                if (!pItem->LoadFromDB(itemGuidLow, playerGuid, fields2, itemId))
                                {
                                    pItem->FSetState(ITEM_REMOVED);
                                    pItem->SaveToDB();              // it also deletes item object !
                                    continue;
                                }

                                draft.AddItem(pItem);
                            }
                            while (resultItems->NextRow());

                            delete resultItems;
                        }
                    }

                    CharacterDatabase.PExecute("DELETE FROM `mail_items` WHERE `mail_id` = '%u'", mail_id);

                    uint32 pl_account = sObjectMgr.GetPlayerAccountIdByGUID(playerGuid);

                    draft.SetMoney(money).SendReturnToSender(pl_account, playerGuid, ObjectGuid(HIGHGUID_PLAYER, sender));
                }
                while (resultMail->NextRow());

                delete resultMail;
            }

            // unsummon and delete for pets in world is not required: player deleted from CLI or character list with not loaded pet.
            // Get guids of character's pets, will deleted in transaction
            QueryResult* resultPets = CharacterDatabase.PQuery("SELECT `id` FROM `character_pet` WHERE `owner_guid` = '%u'", lowguid);

            // NOW we can finally clear other DB data related to character
            CharacterDatabase.BeginTransaction();
            if (resultPets)
            {
                do
                {
                    Field* fields3 = resultPets->Fetch();
                    uint32 petguidlow = fields3[0].GetUInt32();
                    //do not create separate transaction for pet delete otherwise we will get fatal error!
                    Pet::DeleteFromDB(petguidlow, false);
                }
                while (resultPets->NextRow());
                delete resultPets;
            }

            CharacterDatabase.PExecute("DELETE FROM `characters` WHERE `guid` = '%u'", lowguid);
            CharacterDatabase.PExecute("DELETE FROM `character_action` WHERE `guid` = '%u'", lowguid);
            CharacterDatabase.PExecute("DELETE FROM `character_aura` WHERE `guid` = '%u'", lowguid);
            CharacterDatabase.PExecute("DELETE FROM `character_battleground_data` WHERE `guid` = '%u'", lowguid);
            CharacterDatabase.PExecute("DELETE FROM `character_deleted_items` WHERE `player_guid` = '%u'", lowguid);
            CharacterDatabase.PExecute("DELETE FROM `character_gifts` WHERE `guid` = '%u'", lowguid);
            CharacterDatabase.PExecute("DELETE FROM `character_homebind` WHERE `guid` = '%u'", lowguid);
            CharacterDatabase.PExecute("DELETE FROM `character_instance` WHERE `guid` = '%u'", lowguid);
            CharacterDatabase.PExecute("DELETE FROM `group_instance` WHERE `leader_guid` = '%u'", lowguid);
            CharacterDatabase.PExecute("DELETE FROM `character_inventory` WHERE `guid` = '%u'", lowguid);
            CharacterDatabase.PExecute("DELETE FROM `character_queststatus` WHERE `guid` = '%u'", lowguid);
            CharacterDatabase.PExecute("DELETE FROM `character_reputation` WHERE `guid` = '%u'", lowguid);
            CharacterDatabase.PExecute("DELETE FROM `character_skills` WHERE `guid` = '%u'", lowguid);
            CharacterDatabase.PExecute("DELETE FROM `character_forgotten_skills` WHERE `guid` = '%u'", lowguid);
            CharacterDatabase.PExecute("DELETE FROM `character_spell` WHERE `guid` = '%u'", lowguid);
            CharacterDatabase.PExecute("DELETE FROM `character_spell_cooldown` WHERE `guid` = '%u'", lowguid);
            CharacterDatabase.PExecute("DELETE FROM `item_instance` WHERE `owner_guid` = '%u'", lowguid);
            CharacterDatabase.PExecute("DELETE FROM `character_social` WHERE `guid` = '%u' OR `friend`='%u'", lowguid, lowguid);
            CharacterDatabase.PExecute("DELETE FROM `mail` WHERE `receiver_guid` = '%u'", lowguid);
            CharacterDatabase.PExecute("DELETE FROM `mail_items` WHERE `receiver_guid` = '%u'", lowguid);
            CharacterDatabase.PExecute("DELETE FROM `character_pet` WHERE `owner_guid` = '%u'", lowguid);
            CharacterDatabase.PExecute("DELETE FROM `guild_eventlog` WHERE `player_guid1` = '%u' OR `player_guid2` = '%u'", lowguid, lowguid);
            CharacterDatabase.CommitTransaction();
            break;
        }
        // The character gets unlinked from the account, the name gets freed up and appears as deleted ingame
        case 1:
            CharacterDatabase.PExecute("UPDATE `characters` SET `deleted_name`=`name`, `deleted_account`=`account`, `deleted_time`='" UI64FMTD "', `name`='', `account`=0 WHERE `guid`=%u", uint64(time(nullptr)), lowguid);
            break;
        default:
            sLog.outError("Player::DeleteFromDB: Unsupported delete method: %u.", charDelete_method);
    }

    if (updateRealmChars)
        sWorld.UpdateRealmCharCount(accountId);
}

/**
 * Characters which were kept back in the database after being deleted and are now too old (see config option "CharDelete.KeepDays"), will be completely deleted.
 *
 * @see Player::DeleteFromDB
 */
void Player::DeleteOldCharacters()
{
    uint32 keepDays = sWorld.getConfig(CONFIG_UINT32_CHARDELETE_KEEP_DAYS);
    if (!keepDays)
        return;

    Player::DeleteOldCharacters(keepDays);
}

/**
 * Characters which were kept back in the database after being deleted and are older than the specified amount of days, will be completely deleted.
 *
 * @see Player::DeleteFromDB
 *
 * @param keepDays overrite the config option by another amount of days
 */
void Player::DeleteOldCharacters(uint32 keepDays)
{
    QueryResult* resultChars = CharacterDatabase.PQuery("SELECT `guid`, `deleted_account` FROM `characters` WHERE `deleted_time` IS NOT NULL AND `deleted_time` < '" UI64FMTD "' LIMIT 0,2", uint64(time(nullptr) - time_t(keepDays * DAY)));
    if (resultChars)
    {
        do
        {
            Field* charFields = resultChars->Fetch();
            ObjectGuid guid = ObjectGuid(HIGHGUID_PLAYER, charFields[0].GetUInt32());
            Player::DeleteFromDB(guid, charFields[1].GetUInt32(), true, true);
        }
        while (resultChars->NextRow());
        delete resultChars;
    }
}

void Player::SetFly(bool enable)
{
    if (enable)
    {
        m_movementInfo.moveFlags = (MOVEFLAG_LEVITATING | MOVEFLAG_SWIMMING | MOVEFLAG_CAN_FLY | MOVEFLAG_FLYING);
        AddUnitState(UNIT_STAT_FLYING_ALLOWED);
    }
    else
    {
        m_movementInfo.moveFlags = (MOVEFLAG_NONE);
        ClearUnitState(UNIT_STAT_FLYING_ALLOWED);
    }

    SendHeartBeat(true);
}

/* Preconditions:
  - a resurrectable corpse must not be loaded for the player (only bones)
  - the player must be in world
*/
void Player::BuildPlayerRepop()
{
    // Waiting to Resurrect (probably redundant cast, yet to check thoroughly)
    if (InBattleGround())
        CastSpell(this, 2584, true);

    //this is spirit release confirm?
    RemovePet(PET_SAVE_REAGENTS);

    if (GetRace() == RACE_NIGHTELF)
        CastSpell(this, 20584, true);                       // auras SPELL_AURA_INCREASE_SPEED(+speed in wisp form), SPELL_AURA_INCREASE_SWIM_SPEED(+swim speed in wisp form), SPELL_AURA_TRANSFORM (to wisp form)
    CastSpell(this, 8326, true);                            // auras SPELL_AURA_GHOST, SPELL_AURA_INCREASE_SPEED(why?), SPELL_AURA_INCREASE_SWIM_SPEED(why?)

    // the player cannot have a corpse already, only bones which are not returned by GetCorpse
    Corpse* corpse;
    if (corpse = GetCorpse())
    {
        sLog.outInfo("[Player/Crash] 'BuildPlayerRepop' %s (%u) {%.2f %.2f %.2f %u,%u} a deja un corps {%.2f %.2f %.2f %u,%u}",
                        GetName(), GetGUIDLow(), GetPositionX(), GetPositionY(), GetPositionZ(), GetMapId(), GetInstanceId(),
                        corpse->GetPositionX(), corpse->GetPositionY(), corpse->GetPositionZ(), corpse->GetMapId(), corpse->GetInstanceId());
        // La fonction s'en sort tres bien meme si y'a deja un corpse.
        //return;
    }

    // create a corpse and place it at the player's location
    corpse = CreateCorpse();
    if (!corpse)
    {
        sLog.outError("Error creating corpse for Player %s [%u]", GetName(), GetGUIDLow());
        return;
    }
    GetMap()->Add(corpse);

    // convert player body to ghost
    SetHealth(1);

    SetWaterWalking(true);
    if (!GetSession()->isLogingOut())
        SetRooted(false);

    // BG - remove insignia related
    RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_SKINNABLE);

    SendCorpseReclaimDelay();

    // to prevent cheating
    corpse->ResetGhostTime();

    // interrupt resurrect spells
    InterruptSpellsCastedOnMe(false, true);

    // stop countdown until repop
    m_deathTimer = 0;
    SetDeathState(DEAD);
}

void Player::ResurrectPlayer(float restore_percent, bool applySickness)
{
    // Interrupt resurrect spells
    InterruptSpellsCastedOnMe(false, true);

    SetDeathState(ALIVE);

    if (GetRace() == RACE_NIGHTELF)
        RemoveAurasDueToSpell(20584);                       // speed bonuses
    RemoveAurasDueToSpell(8326);                            // SPELL_AURA_GHOST

    SetWaterWalking(false);
    SetRooted(false);

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

    m_deathTimer = 0;

    // update visibility of world around viewpoint
    m_camera.UpdateVisibilityForOwner();
    // update visibility of player for nearby cameras
    UpdateObjectVisibility();

    if (!applySickness)
        return;

    //Characters from level 1-10 are not affected by resurrection sickness.
    //Characters from level 11-19 will suffer from one minute of sickness
    //for each level they are above 10.
    //Characters level 20 and up suffer from ten minutes of sickness.
    int32 const startLevel = sWorld.getConfig(CONFIG_INT32_DEATH_SICKNESS_LEVEL);
    ChrRacesEntry const* raceEntry = sChrRacesStore.LookupEntry(GetRace());
    uint32 const spellId = raceEntry ? raceEntry->resSicknessSpellId : SPELL_ID_PASSIVE_RESURRECTION_SICKNESS;

    if (int32(GetLevel()) >= startLevel)
    {
        // set resurrection sickness
        CastSpell(this, spellId, true);

        // not full duration
        if (int32(GetLevel()) < startLevel + 9)
        {
            int32 delta = (int32(GetLevel()) - startLevel + 1) * MINUTE;

            if (SpellAuraHolder* holder = GetSpellAuraHolder(spellId))
            {
                holder->SetAuraDuration(delta * IN_MILLISECONDS);
                holder->UpdateAuraDuration();
            }
        }
    }
}

void Player::KillPlayer()
{
    SetDeathState(CORPSE);
    //SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_IN_PVP);

    SetUInt32Value(UNIT_DYNAMIC_FLAGS, UNIT_DYNFLAG_NONE);
    ApplyModByteFlag(PLAYER_FIELD_BYTES, 0, PLAYER_FIELD_BYTE_RELEASE_TIMER, !sMapStorage.LookupEntry<MapEntry>(GetMapId())->Instanceable());

    // 6 minutes until repop at graveyard
    m_deathTimer = CORPSE_REPOP_TIME;

    UpdateCorpseReclaimDelay();                             // dependent at use SetDeathPvP() call before kill

    // don't create corpse at this moment, player might be falling

    // update visibility
    UpdateObjectVisibility();
}

Corpse* Player::CreateCorpse()
{
    // prevent existence 2 corpse for player
    SpawnCorpseBones();

    Corpse* corpse = new Corpse((m_ExtraFlags & PLAYER_EXTRA_PVP_DEATH) ? CORPSE_RESURRECTABLE_PVP : CORPSE_RESURRECTABLE_PVE);
    SetPvPDeath(false);

    if (!corpse->Create(sObjectMgr.GenerateCorpseLowGuid(), this))
    {
        delete corpse;
        return nullptr;
    }

    uint8 skin       = GetByteValue(PLAYER_BYTES, 0);
    uint8 face       = GetByteValue(PLAYER_BYTES, 1);
    uint8 hairstyle  = GetByteValue(PLAYER_BYTES, 2);
    uint8 haircolor  = GetByteValue(PLAYER_BYTES, 3);
    uint8 facialhair = GetByteValue(PLAYER_BYTES_2, 0);

    corpse->SetByteValue(CORPSE_FIELD_BYTES_1, 1, GetRace());
    corpse->SetByteValue(CORPSE_FIELD_BYTES_1, 2, GetGender());
    corpse->SetByteValue(CORPSE_FIELD_BYTES_1, 3, skin);

    corpse->SetByteValue(CORPSE_FIELD_BYTES_2, 0, face);
    corpse->SetByteValue(CORPSE_FIELD_BYTES_2, 1, hairstyle);
    corpse->SetByteValue(CORPSE_FIELD_BYTES_2, 2, haircolor);
    corpse->SetByteValue(CORPSE_FIELD_BYTES_2, 3, facialhair);

    uint32 flags = CORPSE_FLAG_UNK2;
    if (HasFlag(PLAYER_FLAGS, PLAYER_FLAGS_HIDE_HELM))
        flags |= CORPSE_FLAG_HIDE_HELM;
    if (HasFlag(PLAYER_FLAGS, PLAYER_FLAGS_HIDE_CLOAK))
        flags |= CORPSE_FLAG_HIDE_CLOAK;
    if (InBattleGround())
        flags |= CORPSE_FLAG_LOOTABLE;                      // to be able to remove insignia
    corpse->SetUInt32Value(CORPSE_FIELD_FLAGS, flags);

    corpse->SetUInt32Value(CORPSE_FIELD_DISPLAY_ID, GetNativeDisplayId());

    corpse->SetUInt32Value(CORPSE_FIELD_GUILD, GetGuildId());

    uint32 iDisplayID;
    uint32 iIventoryType;
    uint32 _cfi;
    for (int i = 0; i < EQUIPMENT_SLOT_END; ++i)
    {
        if (m_items[i])
        {
            iDisplayID = m_items[i]->GetProto()->DisplayInfoID;
            iIventoryType = m_items[i]->GetProto()->InventoryType;

            _cfi =  iDisplayID | (iIventoryType << 24);
            corpse->SetUInt32Value(CORPSE_FIELD_ITEM + i, _cfi);
        }
    }

    // we not need saved corpses for BG/arenas
    if (!GetMap()->IsBattleGround() &&
        !IsBot())
        corpse->SaveToDB();

    // register for player, but not show
    sObjectAccessor.AddCorpse(corpse);
    return corpse;
}

void Player::SpawnCorpseBones()
{
    sObjectAccessor.ConvertCorpseForPlayer(GetObjectGuid());
}

Corpse* Player::GetCorpse() const
{
    return sObjectAccessor.GetCorpseForPlayerGUID(GetObjectGuid());
}

void Player::DurabilityLossAll(double percent, bool inventory)
{
    for (int i = EQUIPMENT_SLOT_START; i < EQUIPMENT_SLOT_END; ++i)
        if (Item* pItem = GetItemByPos(INVENTORY_SLOT_BAG_0, i))
            DurabilityLoss(pItem, percent);

    if (inventory)
    {
        // bags not have durability
        // for(int i = INVENTORY_SLOT_BAG_START; i < INVENTORY_SLOT_BAG_END; ++i)

        for (int i = INVENTORY_SLOT_ITEM_START; i < INVENTORY_SLOT_ITEM_END; ++i)
            if (Item* pItem = GetItemByPos(INVENTORY_SLOT_BAG_0, i))
                DurabilityLoss(pItem, percent);

        // keys not have durability
        //for(int i = KEYRING_SLOT_START; i < KEYRING_SLOT_END; ++i)

        for (int i = INVENTORY_SLOT_BAG_START; i < INVENTORY_SLOT_BAG_END; ++i)
            if (Bag* pBag = (Bag*)GetItemByPos(INVENTORY_SLOT_BAG_0, i))
                for (uint32 j = 0; j < pBag->GetBagSize(); ++j)
                    if (Item* pItem = GetItemByPos(i, j))
                        DurabilityLoss(pItem, percent);
    }
}

void Player::DurabilityLoss(Item* item, double percent)
{
    if (!item)
        return;

    uint32 pMaxDurability =  item ->GetUInt32Value(ITEM_FIELD_MAXDURABILITY);

    if (!pMaxDurability)
        return;

    uint32 pDurabilityLoss = uint32(pMaxDurability * percent);

    if (pDurabilityLoss < 1)
        pDurabilityLoss = 1;

    DurabilityPointsLoss(item, pDurabilityLoss);
}

void Player::DurabilityPointsLossAll(int32 points, bool inventory)
{
    for (int i = EQUIPMENT_SLOT_START; i < EQUIPMENT_SLOT_END; ++i)
        if (Item* pItem = GetItemByPos(INVENTORY_SLOT_BAG_0, i))
            DurabilityPointsLoss(pItem, points);

    if (inventory)
    {
        // bags not have durability
        // for(int i = INVENTORY_SLOT_BAG_START; i < INVENTORY_SLOT_BAG_END; ++i)

        for (int i = INVENTORY_SLOT_ITEM_START; i < INVENTORY_SLOT_ITEM_END; ++i)
            if (Item* pItem = GetItemByPos(INVENTORY_SLOT_BAG_0, i))
                DurabilityPointsLoss(pItem, points);

        // keys not have durability
        //for(int i = KEYRING_SLOT_START; i < KEYRING_SLOT_END; ++i)

        for (int i = INVENTORY_SLOT_BAG_START; i < INVENTORY_SLOT_BAG_END; ++i)
            if (Bag* pBag = (Bag*)GetItemByPos(INVENTORY_SLOT_BAG_0, i))
                for (uint32 j = 0; j < pBag->GetBagSize(); ++j)
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

uint32 Player::DurabilityRepairAll(bool cost, float discountMod)
{
    uint32 TotalCost = 0;
    // equipped, backpack, bags itself
    for (int i = EQUIPMENT_SLOT_START; i < INVENTORY_SLOT_ITEM_END; ++i)
        TotalCost += DurabilityRepair(((INVENTORY_SLOT_BAG_0 << 8) | i), cost, discountMod);

    // bank, buyback and keys not repaired

    // items in inventory bags
    for (int j = INVENTORY_SLOT_BAG_START; j < INVENTORY_SLOT_BAG_END; ++j)
        for (int i = 0; i < MAX_BAG_SIZE; ++i)
            TotalCost += DurabilityRepair(((j << 8) | i), cost, discountMod);
    return TotalCost;
}

uint32 Player::DurabilityRepair(uint16 pos, bool cost, float discountMod)
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
        if (LostDurability > 0)
        {
            ItemPrototype const* ditemProto = item->GetProto();

            DurabilityCostsEntry const* dcost = sDurabilityCostsStore.LookupEntry(ditemProto->ItemLevel);
            if (!dcost)
            {
                sLog.outError("RepairDurability: Wrong item lvl %u", ditemProto->ItemLevel);
                return TotalCost;
            }

            uint32 dQualitymodEntryId = (ditemProto->Quality + 1) * 2;
            DurabilityQualityEntry const* dQualitymodEntry = sDurabilityQualityStore.LookupEntry(dQualitymodEntryId);
            if (!dQualitymodEntry)
            {
                sLog.outError("RepairDurability: Wrong dQualityModEntry %u", dQualitymodEntryId);
                return TotalCost;
            }

            uint32 dmultiplier = dcost->multiplier[ItemSubClassToDurabilityMultiplierId(ditemProto->Class, ditemProto->SubClass)];
            uint32 costs = uint32(LostDurability * dmultiplier * double(dQualitymodEntry->quality_mod));

            costs = uint32(costs * discountMod);

            if (costs == 0)                                 //fix for ITEM_QUALITY_ARTIFACT
                costs = 1;

            if (GetMoney() < costs)
            {
                DEBUG_LOG("You do not have enough money");
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

void Player::ScheduleRepopAtGraveyard()
{
    if (IsInWorld() && GetSession()->IsConnected())
        m_repopAtGraveyardPending = true;
    else
        RepopAtGraveyard();
}

void Player::RepopAtGraveyard()
{
    // note: this can be called also when the player is alive
    // for example from WorldSession::HandleMovementOpcodes

    m_repopAtGraveyardPending = false;
    WorldSafeLocsEntry const* ClosestGrave = nullptr;

    // Special handle for battleground maps
    std::function<void()> recover;
    if (BattleGround* bg = GetBattleGround())
    {
        ClosestGrave = bg->GetClosestGraveYard(this);
        recover = [this](){
            RepopAtGraveyard();
        };
    }
    else
        ClosestGrave = sObjectMgr.GetClosestGraveYard(GetPositionX(), GetPositionY(), GetPositionZ(), GetMapId(), GetTeam());

    float orientation = GetOrientation();

    // World of Warcraft Client Patch 1.8.0 (2005-10-11)
    // - All graveyards that needed adjustment were changed so that a 
    //   character's spirit comes into the world facing toward the Spirit Healer.
#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_7_1
    if (ClosestGrave)
        if (float facing = sObjectMgr.GetWorldSafeLocFacing(ClosestGrave->ID))
            orientation = facing;
#endif

    if (IsAlive())
    {
        if (ClosestGrave)
            TeleportTo(ClosestGrave->map_id, ClosestGrave->x, ClosestGrave->y, ClosestGrave->z, orientation, 0, std::move(recover));
    }
    else
    {
        // if no grave found, stay at the current location
        // and don't show spirit healer location
        if (ClosestGrave)
        {
            // Release spirit from transport => Teleport alive at nearest graveyard.
            if (GetTransport())
            {
                GetTransport()->RemovePassenger(this);
                ResurrectPlayer(1.0f);
            }
            TeleportTo(ClosestGrave->map_id, ClosestGrave->x, ClosestGrave->y, ClosestGrave->z, orientation, 0, std::move(recover));
        }

        // Fix invisible spirit healer if you die close to graveyard.
        if (IsInWorld())
            UpdateVisibilityAndView();
    }
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
        ch->Leave(GetObjectGuid(), false);                  // not send to client, not remove from player's channel list
        if (ChannelMgr* cMgr = channelMgr(GetTeam()))
            cMgr->LeftChannel(ch->GetName());               // deleted channel if empty

    }
    DEBUG_LOG("Player: channels cleaned up!");
}

void Player::UpdateLocalChannels(uint32 newZone)
{
    // Updated client-side
}

void Player::LeaveLFGChannel()
{
    for (const auto& channel : m_channels)
    {
        if (channel->IsLFG())
        {
            channel->Leave(GetObjectGuid());
            break;
        }
    }
}

void Player::HandleBaseModValue(BaseModGroup modGroup, BaseModType modType, float amount, bool apply)
{
    if (modGroup >= BASEMOD_END || modType >= MOD_END)
    {
        sLog.outError("ERROR in HandleBaseModValue(): nonexistent BaseModGroup of wrong BaseModType!");
        return;
    }

    float val = 1.0f;

    switch (modType)
    {
        case FLAT_MOD:
            m_auraBaseMod[modGroup][modType] += apply ? amount : -amount;
            break;
        case PCT_MOD:
            if (amount <= -100.0f)
                amount = -200.0f;

            val = (100.0f + amount) / 100.0f;
            m_auraBaseMod[modGroup][modType] *= apply ? val : (1.0f / val);
            break;
    }

    if (!CanModifyStats())
        return;

    switch (modGroup)
    {
        case CRIT_PERCENTAGE:
            UpdateCritPercentage(BASE_ATTACK);
            break;
        case RANGED_CRIT_PERCENTAGE:
            UpdateCritPercentage(RANGED_ATTACK);
            break;
        default:
            break;
    }
}

float Player::GetBaseModValue(BaseModGroup modGroup, BaseModType modType) const
{
    if (modGroup >= BASEMOD_END || modType > MOD_END)
    {
        sLog.outError("trial to access nonexistent BaseModGroup or wrong BaseModType!");
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
        sLog.outError("wrong BaseModGroup in GetTotalBaseModValue()!");
        return 0.0f;
    }

    if (m_auraBaseMod[modGroup][PCT_MOD] <= 0.0f)
        return 0.0f;

    return m_auraBaseMod[modGroup][FLAT_MOD] * m_auraBaseMod[modGroup][PCT_MOD];
}

uint32 Player::GetShieldBlockValue() const
{
    float value = (m_auraBaseMod[SHIELD_BLOCK_VALUE][FLAT_MOD] + GetStat(STAT_STRENGTH) / 20 - 1) * m_auraBaseMod[SHIELD_BLOCK_VALUE][PCT_MOD];

    value = (value < 0) ? 0 : value;

    return uint32(value);
}

float Player::GetMeleeCritFromAgility() const
{
    float valLevel1 = 0.0f;
    float valLevel60 = 0.0f;
    // critical
    switch (GetClass())
    {
        case CLASS_PALADIN:
        case CLASS_SHAMAN:
        case CLASS_DRUID:
            valLevel1 = 4.6f;
            valLevel60 = 20.0f;
            break;
        case CLASS_MAGE:
            valLevel1 = 12.9f;
            valLevel60 = 20.0f;
            break;
        case CLASS_ROGUE:
            valLevel1 = 2.2f;
            valLevel60 = 29.0f;
            break;
        case CLASS_HUNTER:
            valLevel1 = 3.5f;
            valLevel60 = 53.0f;
            break;
        case CLASS_PRIEST:
            valLevel1 = 11.0f;
            valLevel60 = 20.0f;
            break;
        case CLASS_WARLOCK:
            valLevel1 = 8.4f;
            valLevel60 = 20.0f;
            break;
        case CLASS_WARRIOR:
            valLevel1 = 3.9f;
            valLevel60 = 20.0f;
            break;
        default:
            return 0.0f;
    }
    float classrate = valLevel1 * float(60.0f - GetLevel()) / 59.0f + valLevel60 * float(GetLevel() - 1.0f) / 59.0f;
    return GetStat(STAT_AGILITY) / classrate;
}

float Player::GetDodgeFromAgility() const
{
    float valLevel1 = 0.0f;
    float valLevel60 = 0.0f;
    // critical
    switch (GetClass())
    {
        case CLASS_PALADIN:
        case CLASS_SHAMAN:
        case CLASS_DRUID:
            valLevel1 = 4.6f;
            valLevel60 = 20.0f;
            break;
        case CLASS_MAGE:
            valLevel1 = 12.9f;
            valLevel60 = 20.0f;
            break;
        case CLASS_ROGUE:
            valLevel1 = 1.1f;
            valLevel60 = 14.5f;
            break;
        case CLASS_HUNTER:
            valLevel1 = 1.8f;
            valLevel60 = 26.5f;
            break;
        case CLASS_PRIEST:
            valLevel1 = 11.0f;
            valLevel60 = 20.0f;
            break;
        case CLASS_WARLOCK:
            valLevel1 = 8.4f;
            valLevel60 = 20.0f;
            break;
        case CLASS_WARRIOR:
            valLevel1 = 3.9f;
            valLevel60 = 20.0f;
            break;
        default:
            return 0.0f;
    }
    float classrate = valLevel1 * float(60.0f - GetLevel()) / 59.0f + valLevel60 * float(GetLevel() - 1.0f) / 59.0f;
    return GetStat(STAT_AGILITY) / classrate;
}

float Player::GetSpellCritFromIntellect() const
{
// Chance to crit is computed from INT and LEVEL as follows:
    //   chance = base + INT / (rate0 + rate1 * LEVEL)
    // The formula keeps the crit chance at %5 on every level unless the player
    // increases his intelligence by other means (enchants, buffs, talents, ...)

    //[TZERO] from mangos 3462 for 1.12 MUST BE CHECKED

    static const struct
    {
        float base;
        float rate0, rate1;
    }
    crit_data[MAX_CLASSES] =
    {
        {   0.0f,   0.0f,  10.0f  },                        //  0: unused
        {   0.0f,   0.0f,  10.0f  },                        //  1: warrior
        {   3.70f, 14.77f,  0.65f },                        //  2: paladin
        {   0.0f,   0.0f,  10.0f  },                        //  3: hunter
        {   0.0f,   0.0f,  10.0f  },                        //  4: rogue
        {   2.97f, 10.03f,  0.82f },                        //  5: priest
        {   0.0f,   0.0f,  10.0f  },                        //  6: unused
        {   3.54f, 11.51f,  0.80f },                        //  7: shaman
        {   3.70f, 14.77f,  0.65f },                        //  8: mage
        {   3.18f, 11.30f,  0.82f },                        //  9: warlock
        {   0.0f,   0.0f,  10.0f  },                        // 10: unused
        {   3.33f, 12.41f,  0.79f }                         // 11: druid
    };
    float crit_chance;

    // only players use intelligence for critical chance computations
    if (GetTypeId() == TYPEID_PLAYER)
    {
        int my_class = GetClass();
        float crit_ratio = crit_data[my_class].rate0 + crit_data[my_class].rate1 * GetLevel();
        crit_chance = crit_data[my_class].base + GetStat(STAT_INTELLECT) / crit_ratio;
    }
    else
        crit_chance = m_baseSpellCritChance;

    crit_chance = crit_chance > 0.0 ? crit_chance : 0.0;

    return crit_chance;
}

void Player::SetRegularAttackTime(bool resetTimer)
{
    for (int i = 0; i < MAX_ATTACK; ++i)
    {
        Item* tmpitem = GetWeaponForAttack(WeaponAttackType(i), true, false);
        if (tmpitem)
        {
            ItemPrototype const* proto = tmpitem->GetProto();
            if (proto->Delay)
                SetAttackTime(WeaponAttackType(i), proto->Delay, resetTimer);
            else
                SetAttackTime(WeaponAttackType(i), BASE_ATTACK_TIME, resetTimer);
        }
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

    uint32 valueIndex = PLAYER_SKILL_VALUE_INDEX(itr->second.pos);
    uint32 data = GetUInt32Value(valueIndex);
    uint32 value = SKILL_VALUE(data);
    uint32 max = SKILL_MAX(data);

    if ((!max) || (!value) || (value >= max))
        return false;

   uint32 new_value = value + step;

   if (new_value > max)
       new_value = max;

    SetUInt32Value(valueIndex, MAKE_SKILL_VALUE(new_value, max));
    if (itr->second.uState != SKILL_NEW)
        itr->second.uState = SKILL_CHANGED;

    return true;
}

inline int SkillGainChance(uint32 SkillValue, uint32 GrayLevel, uint32 GreenLevel, uint32 YellowLevel)
{
    if (SkillValue >= GrayLevel)
        return sWorld.getConfig(CONFIG_UINT32_SKILL_CHANCE_GREY) * 10;
    if (SkillValue >= GreenLevel)
        return sWorld.getConfig(CONFIG_UINT32_SKILL_CHANCE_GREEN) * 10;
    if (SkillValue >= YellowLevel)
        return sWorld.getConfig(CONFIG_UINT32_SKILL_CHANCE_YELLOW) * 10;
    return sWorld.getConfig(CONFIG_UINT32_SKILL_CHANCE_ORANGE) * 10;
}

bool Player::UpdateCraftSkill(uint32 spellid)
{
    DEBUG_LOG("UpdateCraftSkill spellid %d", spellid);

    SkillLineAbilityMapBounds bounds = sSpellMgr.GetSkillLineAbilityMapBoundsBySpellId(spellid);

    for (SkillLineAbilityMap::const_iterator _spell_idx = bounds.first; _spell_idx != bounds.second; ++_spell_idx)
    {
        if (_spell_idx->second->skillId)
        {
            uint32 SkillValue = GetSkillValuePure(_spell_idx->second->skillId);

            uint32 craft_skill_gain = sWorld.getConfig(CONFIG_UINT32_SKILL_GAIN_CRAFTING);

            return UpdateSkillPro(_spell_idx->second->skillId, SkillGainChance(SkillValue,
                                  _spell_idx->second->max_value,
                                  (_spell_idx->second->max_value + _spell_idx->second->min_value) / 2,
                                  _spell_idx->second->min_value),
                                  craft_skill_gain);
        }
    }
    return false;
}

bool Player::UpdateGatherSkill(uint32 SkillId, uint32 SkillValue, uint32 RedLevel, uint32 Multiplicator)
{
    DEBUG_LOG("UpdateGatherSkill(SkillId %d SkillLevel %d RedLevel %d)", SkillId, SkillValue, RedLevel);

    uint32 gathering_skill_gain = sWorld.getConfig(CONFIG_UINT32_SKILL_GAIN_GATHERING);

    // For skinning and Mining chance decrease with level. 1-74 - no decrease, 75-149 - 2 times, 225-299 - 8 times
    switch (SkillId)
    {
        case SKILL_HERBALISM:
        case SKILL_LOCKPICKING:
            return UpdateSkillPro(SkillId, SkillGainChance(SkillValue, RedLevel + 100, RedLevel + 50, RedLevel + 25) * Multiplicator, gathering_skill_gain);
        case SKILL_SKINNING:
            if (sWorld.getConfig(CONFIG_UINT32_SKILL_CHANCE_SKINNING_STEPS) == 0)
                return UpdateSkillPro(SkillId, SkillGainChance(SkillValue, RedLevel + 100, RedLevel + 50, RedLevel + 25) * Multiplicator, gathering_skill_gain);
            else
                return UpdateSkillPro(SkillId, (SkillGainChance(SkillValue, RedLevel + 100, RedLevel + 50, RedLevel + 25) * Multiplicator) >> (SkillValue / sWorld.getConfig(CONFIG_UINT32_SKILL_CHANCE_SKINNING_STEPS)), gathering_skill_gain);
        case SKILL_MINING:
            if (sWorld.getConfig(CONFIG_UINT32_SKILL_CHANCE_MINING_STEPS) == 0)
                return UpdateSkillPro(SkillId, SkillGainChance(SkillValue, RedLevel + 100, RedLevel + 50, RedLevel + 25) * Multiplicator, gathering_skill_gain);
            else
                return UpdateSkillPro(SkillId, (SkillGainChance(SkillValue, RedLevel + 100, RedLevel + 50, RedLevel + 25) * Multiplicator) >> (SkillValue / sWorld.getConfig(CONFIG_UINT32_SKILL_CHANCE_MINING_STEPS)), gathering_skill_gain);
    }
    return false;
}

bool Player::UpdateFishingSkill()
{
    DEBUG_LOG("UpdateFishingSkill");

    uint32 SkillValue = GetSkillValuePure(SKILL_FISHING);

    int32 chance = SkillValue < 75 ? 100 : 2500 / (SkillValue - 50);

    uint32 gathering_skill_gain = sWorld.getConfig(CONFIG_UINT32_SKILL_GAIN_GATHERING);

    return UpdateSkillPro(SKILL_FISHING, chance * 10, gathering_skill_gain);
}

bool Player::UpdateSkillPro(uint16 SkillId, int32 Chance, uint32 step)
{
    DEBUG_LOG("UpdateSkillPro(SkillId %d, Chance %3.1f%%)", SkillId, Chance / 10.0);
    if (!SkillId)
        return false;

    if (Chance <= 0)                                        // speedup in 0 chance case
    {
        DEBUG_LOG("Player::UpdateSkillPro Chance=%3.1f%% missed", Chance / 10.0);
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
        uint32 new_value = SkillValue + step;
        if (new_value > MaxValue)
            new_value = MaxValue;

        SetUInt32Value(valueIndex, MAKE_SKILL_VALUE(new_value, MaxValue));
        if (itr->second.uState != SKILL_NEW)
            itr->second.uState = SKILL_CHANGED;
        DEBUG_LOG("Player::UpdateSkillPro Chance=%3.1f%% taken", Chance / 10.0);
        return true;
    }

    DEBUG_LOG("Player::UpdateSkillPro Chance=%3.1f%% missed", Chance / 10.0);
    return true;
}

void Player::UpdateCombatSkills(Unit* pVictim, WeaponAttackType attType, bool defence)
{
    if (!pVictim)
        return;

    // No skill gain in pvp
    if (pVictim->IsCharmerOrOwnerPlayerOrPlayerItself())
        return;

    // No weapon skill gain while in tree/feral form
    if (!defence && (GetShapeshiftForm() == FORM_TREE || IsInFeralForm()))
        return; 

    uint32 playerLevel      = GetLevel();
    uint32 currentSkillValue = defence ? GetBaseDefenseSkillValue() : GetBaseWeaponSkillValue(attType);
    uint32 currentSkillMax  = 5 * playerLevel;

    // Max skill reached for level.
    // Can in some cases be less than 0: having max skill and then .level -1 as example.
    if (currentSkillMax <= currentSkillValue)
        return;

    uint32 skillDiff = currentSkillMax - currentSkillValue;

    // Calculate base chance to increase
    float chance = 0.0f;
    if (defence) // TODO: more research needed. Seems to increase slower than weapon skill. Using old formula:
    {
        uint32 greylevel = MaNGOS::XP::GetGrayLevel(playerLevel);
        uint32 mobLevel = pVictim->GetLevelForTarget(this);

        if (mobLevel > playerLevel + 5)
            mobLevel = playerLevel + 5;

        int32 lvldif = mobLevel - greylevel;
        if (lvldif < 3)
            lvldif = 3;

        chance = float(3 * lvldif * skillDiff) / playerLevel;
    }
    else // weapon skill https://classic.wowhead.com/guides/classic-wow-weapon-skills
    {
        if (currentSkillMax * 0.9f > currentSkillValue)
        {
            // Skill progress: 1% - 90% - chance decreases from 100% to 50%
            chance = std::min(100.0f, float(currentSkillMax * 0.9f * 50) / currentSkillValue);
        }
        else
        {
            // Skill progress: 90% - 100% - chance decreases from 50% to a minimum which is level dependent
            chance = (0.5f - 0.0168966f * currentSkillValue * (300.0f / currentSkillMax) + 0.0152069f * currentSkillMax * (300.0f / currentSkillMax)) * 100.0f;
            if (skillDiff <= 3)
                chance *= (0.5f / (4 - skillDiff));
        }      

        // Add intellect bonus (capped at 10% - guessed)
        chance += std::min(10.0f, 0.02f * GetStat(STAT_INTELLECT));
    }

    chance = std::min(100.0f, chance);

    DEBUG_LOG("Player::UpdateCombatSkills(defence=%d, playerLevel=%i) -> (%i/%i) chance to increase skill is %f ", defence, playerLevel, currentSkillValue, currentSkillMax, chance);

    if (roll_chance_f(chance))
    {
        if (defence)
        {
            uint32 defense_skill_gain = sWorld.getConfig(CONFIG_UINT32_SKILL_GAIN_DEFENSE);

            if (UpdateSkill(SKILL_DEFENSE, defense_skill_gain))
            {
                // Update values related to defense skill 
                UpdateDefenseBonusesMod();
            }
        }
        else // Weapon
        {
            uint32 weapon_skill_gain = sWorld.getConfig(CONFIG_UINT32_SKILL_GAIN_WEAPON);
            Item* tmpitem = GetWeaponForAttack(attType, true, true);

            switch (attType)
            {
                case BASE_ATTACK:
                {
                    if (!tmpitem)
                        UpdateSkill(SKILL_UNARMED, weapon_skill_gain);
                    else if (tmpitem->GetProto()->SubClass != ITEM_SUBCLASS_WEAPON_FISHING_POLE)
                        UpdateSkill(tmpitem->GetProto()->GetProficiencySkill(), weapon_skill_gain);
                    break;
                }
                case OFF_ATTACK:
                case RANGED_ATTACK:
                {
                    if (tmpitem)
                        UpdateSkill(tmpitem->GetProto()->GetProficiencySkill(), weapon_skill_gain);
                    break;
                }
            }
            // Update values related to weapon skill 
            UpdateAllCritPercentages();
        }
    }
}

void Player::UpdateSkillsForLevel()
{
    uint16 maxconfskill = sWorld.GetConfigMaxSkillValue();
    uint32 maxSkill = GetSkillMaxForLevel();

    bool alwaysMaxSkill = sWorld.getConfig(CONFIG_BOOL_ALWAYS_MAX_SKILL_FOR_LEVEL);

    for (SkillStatusMap::iterator itr = mSkillStatus.begin(); itr != mSkillStatus.end(); ++itr)
    {
        if (itr->second.uState == SKILL_DELETED)
            continue;

        uint32 pskill = itr->first;

        SkillLineEntry const* pSkill = sSkillLineStore.LookupEntry(pskill);
        if (!pSkill)
            continue;

        if (GetSkillRangeType(pSkill, false) != SKILL_RANGE_LEVEL)
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
            else if (max != maxconfskill)                   /// update max skill value if current max skill not maximized
            {
                SetUInt32Value(valueIndex, MAKE_SKILL_VALUE(val, maxSkill));
                if (itr->second.uState != SKILL_NEW)
                    itr->second.uState = SKILL_CHANGED;
            }
        }
    }
}

void Player::UpdateSkillsToMaxSkillsForLevel()
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
void Player::SetSkill(uint16 id, uint16 currVal, uint16 maxVal, uint16 step /*=0*/)
{
    if (!id)
        return;

    SkillStatusMap::iterator itr = mSkillStatus.find(id);

    //has skill
    if (itr != mSkillStatus.end() && itr->second.uState != SKILL_DELETED)
    {
        if (currVal)
        {
            if (step)                                      // need update step
                SetUInt32Value(PLAYER_SKILL_INDEX(itr->second.pos), MAKE_PAIR32(id, step));
            // update value
            SetUInt32Value(PLAYER_SKILL_VALUE_INDEX(itr->second.pos), MAKE_SKILL_VALUE(currVal, maxVal));
            if (itr->second.uState != SKILL_NEW)
                itr->second.uState = SKILL_CHANGED;

            // Learn all spells auto-trained by this skill on change
            UpdateSkillTrainedSpells(id, currVal);
        }
        else                                                //remove
        {
            // Unapply skill bonuses
            // temporary bonuses
            AuraList const& lModSkill = GetAurasByType(SPELL_AURA_MOD_SKILL);
            for (const auto j : lModSkill)
                if (j->GetModifier()->m_miscvalue == int32(id))
                    j->ApplyModifier(false);

            // permanent bonuses
            AuraList const& lModSkillTalent = GetAurasByType(SPELL_AURA_MOD_SKILL_TALENT);
            for (const auto j : lModSkillTalent)
                if (j->GetModifier()->m_miscvalue == int32(id))
                    j->ApplyModifier(false);

            // clear skill fields
            SetUInt32Value(PLAYER_SKILL_INDEX(itr->second.pos), 0);
            SetUInt32Value(PLAYER_SKILL_VALUE_INDEX(itr->second.pos), 0);
            SetUInt32Value(PLAYER_SKILL_BONUS_INDEX(itr->second.pos), 0);

            // mark as deleted or simply remove from map if not saved yet
            if (itr->second.uState != SKILL_NEW)
                itr->second.uState = SKILL_DELETED;
            else
                mSkillStatus.erase(itr);

            // Remove all spells dependent on this skill unconditionally
            UpdateSkillTrainedSpells(id, 0);

            // remove all quests related to this skill (else the spell will be automatically learned at next login, cf Player::LearnQuestRewardedSpells)
            for (auto& itr : mQuestStatus)
            { 
                if (Quest const* quest = sObjectMgr.GetQuestTemplate(itr.first))
                {
                    if (quest->GetRequiredSkill() == id)
                    {
                        // remove all quest entries for 'entry' from quest log
                        for (uint8 slot = 0; slot < MAX_QUEST_LOG_SIZE; ++slot)
                        {
                            if (GetQuestSlotQuestId(slot) == itr.first)
                            {
                                SetQuestSlot(slot, 0);
                                TakeOrReplaceQuestStartItems(itr.first, false, false);
                                break;
                            }
                        }

                        // set quest status to not started (will updated in DB at next save)
                        SetQuestStatus(itr.first, QUEST_STATUS_NONE); // Does not invalidate the iterator
                        itr.second.uState = QUEST_DELETED;
                    }
                }
            }
        }
    }
    else if (currVal)                                       // add
    {
        for (int i = 0; i < PLAYER_MAX_SKILLS; ++i)
        {
            if (!GetUInt32Value(PLAYER_SKILL_INDEX(i)))
            {
                SkillLineEntry const* pSkill = sSkillLineStore.LookupEntry(id);
                if (!pSkill)
                {
                    sLog.outError("Skill not found in SkillLineStore: skill #%u", id);
                    return;
                }

                SetUInt32Value(PLAYER_SKILL_INDEX(i), MAKE_PAIR32(id, step));
                SetUInt32Value(PLAYER_SKILL_VALUE_INDEX(i), MAKE_SKILL_VALUE(currVal, maxVal));

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
                AuraList const& lModSkill = GetAurasByType(SPELL_AURA_MOD_SKILL);
                for (const auto j : lModSkill)
                    if (j->GetModifier()->m_miscvalue == int32(id))
                        j->ApplyModifier(true);

                // permanent bonuses
                AuraList const& lModSkillTalent = GetAurasByType(SPELL_AURA_MOD_SKILL_TALENT);
                for (const auto j : lModSkillTalent)
                    if (j->GetModifier()->m_miscvalue == int32(id))
                        j->ApplyModifier(true);

                // Learn all spells auto-trained by this skill
                UpdateSkillTrainedSpells(id, currVal);
                return;
            }
        }
    }
}

bool Player::HasSkill(uint16 id) const
{
    if (!id)
        return false;

    SkillStatusMap::const_iterator itr = mSkillStatus.find(id);
    return (itr != mSkillStatus.end() && itr->second.uState != SKILL_DELETED);
}

uint16 Player::GetSkill(uint16 id, bool bonusPerm, bool bonusTemp, bool max/* = false*/) const
{
    if (!id)
        return 0;

    SkillStatusMap::const_iterator itr = mSkillStatus.find(id);
    if (itr == mSkillStatus.end() || itr->second.uState == SKILL_DELETED)
        return 0;

    SkillStatusData const& skillStatus = itr->second;

    uint32 field = GetUInt32Value(PLAYER_SKILL_VALUE_INDEX(skillStatus.pos));

    // Pure value
    int32 value = (max ? SKILL_MAX(field) : SKILL_VALUE(field));

    // Bonus values
    if (bonusPerm || bonusTemp)
    {
        uint32 bonus = GetUInt32Value(PLAYER_SKILL_BONUS_INDEX(skillStatus.pos));

        if (bonusPerm)
            value += SKILL_PERM_BONUS(bonus);

        if (bonusTemp)
            value += SKILL_TEMP_BONUS(bonus);
    }

    return uint16(std::max(0, value));
}

bool Player::ModifySkillBonus(uint16 id, int16 diff, bool permanent/* = false*/)
{
    if (!id || !diff)
        return false;

    SkillStatusMap::const_iterator itr = mSkillStatus.find(id);
    if (itr == mSkillStatus.end() || itr->second.uState == SKILL_DELETED)
        return false;

    uint16 bonusIndex = PLAYER_SKILL_BONUS_INDEX(itr->second.pos);
    uint32 bonus = GetUInt32Value(bonusIndex);
    int16 const bonusTemporary = SKILL_TEMP_BONUS(bonus);
    int16 const bonusPermanent = SKILL_PERM_BONUS(bonus);

    if (permanent)
        SetUInt32Value(bonusIndex, MAKE_SKILL_BONUS(bonusTemporary, (bonusPermanent + diff))); // permanent bonus stored in high part
    else
        SetUInt32Value(bonusIndex, MAKE_SKILL_BONUS((bonusTemporary + diff), bonusPermanent)); // temporary/item bonus stored in low part

    return true;
}

int16 Player::GetSkillBonus(uint16 id, bool permanent/*= false*/) const
{
    if (!id)
        return 0;

    SkillStatusMap::const_iterator itr = mSkillStatus.find(id);
    if (itr == mSkillStatus.end() || itr->second.uState == SKILL_DELETED)
        return 0;

    SkillStatusData const& skillStatus = itr->second;

    uint32 bonus = GetUInt32Value(PLAYER_SKILL_BONUS_INDEX(skillStatus.pos));

    return (permanent ? SKILL_PERM_BONUS(bonus) : SKILL_TEMP_BONUS(bonus));
}

void Player::UpdateSkillTrainedSpells(uint16 id, uint16 currVal)
{
    uint32 raceMask = GetRaceMask();
    uint32 classMask = GetClassMask();

    SkillLineAbilityMapBounds bounds = sSpellMgr.GetSkillLineAbilityMapBoundsBySkillId(id);

    for (auto itr = bounds.first; itr != bounds.second; ++itr)
    {
        if (SkillLineAbilityEntry const* pAbility = itr->second)
        {
            // Update training: skill removal mode, wipe all dependent spells regardless of training method
            if (!currVal)
            {
                RemoveSpell(pAbility->spellId);
                continue;
            }

            // Check if auto-training method is set, skip if not
            if (!pAbility->learnOnGetSkill)
                continue;

            // Check race if set
            if (pAbility->racemask && !(pAbility->racemask & raceMask))
                continue;

            // Check class if set
            if (pAbility->classmask && !(pAbility->classmask & classMask))
                continue;

            // Update training: needs unlearning spell if current value is too low
            if (currVal < pAbility->req_skill_value)
                RemoveSpell(pAbility->spellId);
            // Update training: needs learning
            else if (!IsInWorld())
                AddSpell(pAbility->spellId, true, true, true, false);
            else
                LearnSpell(pAbility->spellId, true);
        }
    }
}

void Player::UpdateSpellTrainedSkills(uint32 spellId, bool apply)
{
    if (SpellLearnSkillNode const* skillLearnInfo = sSpellMgr.GetSpellLearnSkill(spellId))
    {
        if (apply)
        {
            uint16 value = std::max(skillLearnInfo->value, GetSkillValuePure(skillLearnInfo->skill));
            uint16 max = std::max((!skillLearnInfo->maxvalue ? GetSkillMaxForLevel() : skillLearnInfo->maxvalue), GetSkillMaxPure(skillLearnInfo->skill));
            SetSkill(skillLearnInfo->skill, value, max, skillLearnInfo->step);
        }
        else
        {
            uint32 prev_spell = sSpellMgr.GetPrevSpellInChain(spellId);
            if (!prev_spell)                                    // first rank, remove skill
                SetSkill(skillLearnInfo->skill, 0, 0);
            else
            {
                // search prev. skill setting by spell ranks chain
                SpellLearnSkillNode const* prevSkill = sSpellMgr.GetSpellLearnSkill(prev_spell);
                while (!prevSkill && prev_spell)
                {
                    prev_spell = sSpellMgr.GetPrevSpellInChain(prev_spell);
                    prevSkill = sSpellMgr.GetSpellLearnSkill(sSpellMgr.GetFirstSpellInChain(prev_spell));
                }

                if (!prevSkill)                                 // not found prev skill setting, remove skill
                    SetSkill(skillLearnInfo->skill, 0, 0);
                else                                            // set to prev. skill setting values
                {
                    uint16 value = std::min(prevSkill->value, GetSkillValuePure(prevSkill->skill));
                    uint16 max = std::min((!prevSkill->maxvalue ? GetSkillMaxForLevel() : prevSkill->maxvalue), GetSkillMaxPure(prevSkill->skill));
                    SetSkill(prevSkill->skill, value, max, prevSkill->step);
                }
            }
        }
    }
    else
    {
        SkillLineAbilityMapBounds bounds = sSpellMgr.GetSkillLineAbilityMapBoundsBySpellId(spellId);
        for (auto itr = bounds.first; itr != bounds.second; ++itr)
        {
            SkillLineAbilityEntry const* skillAbility = itr->second;
            SkillLineEntry const* pSkill = sSkillLineStore.LookupEntry(skillAbility->skillId);
            if (!pSkill)
                continue;

            if (apply)
            {
                if (HasSkill(uint16(pSkill->id)))
                    continue;

                if (skillAbility->learnOnGetSkill == ABILITY_LEARNED_ON_GET_RACE_OR_CLASS_SKILL ||
                    // poison special case, not have ABILITY_LEARNED_ON_GET_RACE_OR_CLASS_SKILL
                    ((pSkill->id == SKILL_POISONS) && (skillAbility->max_value == 0)) ||
                    // lockpicking special case, not have ABILITY_LEARNED_ON_GET_RACE_OR_CLASS_SKILL
                    ((pSkill->id == SKILL_LOCKPICKING) && (skillAbility->max_value == 0)))
                {
                    switch (GetSkillRangeType(pSkill, skillAbility->racemask != 0))
                    {
                        case SKILL_RANGE_LANGUAGE:
                            SetSkill(uint16(pSkill->id), 300, 300);
                            break;
                        case SKILL_RANGE_LEVEL:
                        {
                            uint16 newSkillValue = sWorld.getConfig(CONFIG_BOOL_ALWAYS_MAX_SKILL_FOR_LEVEL) ? GetSkillMaxForLevel() : 1;

                            // World of Warcraft Client Patch 1.11.0 (2006-06-20)
                            // - Two-Handed Axes/Maces (Enhancement Talent) - Skill levels gained 
                            //   with these two weapons will now be retained if you decide to unspend
                            //   this talent point and return to it later.
#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_10_2
                            if (pSkill->categoryId == SKILL_CATEGORY_WEAPON)
                            {
                                const auto savedValue = m_mForgottenSkills.find(pSkill->id);

                                if (savedValue != m_mForgottenSkills.end())
                                    if (savedValue->second <= GetSkillMaxForLevel())
                                        newSkillValue = savedValue->second;
                            }
#endif
                            SetSkill(uint16(pSkill->id), newSkillValue, GetSkillMaxForLevel());
                            break;
                        }
                        case SKILL_RANGE_MONO:
                            SetSkill(uint16(pSkill->id), 1, 1);
                            break;
                        default:
                            break;
                    }
                }
            }
            else
            {
                if ((skillAbility->learnOnGetSkill == ABILITY_LEARNED_ON_GET_RACE_OR_CLASS_SKILL &&
                    pSkill->categoryId != SKILL_CATEGORY_CLASS) ||// not unlearn class skills (spellbook/talent pages)
                                                                  // poisons/lockpicking special case, not have ABILITY_LEARNED_ON_GET_RACE_OR_CLASS_SKILL
                    ((pSkill->id == SKILL_POISONS || pSkill->id == SKILL_LOCKPICKING) && skillAbility->max_value == 0))
                {
                    // not reset skills for professions and racial abilities
                    if ((pSkill->categoryId == SKILL_CATEGORY_SECONDARY || pSkill->categoryId == SKILL_CATEGORY_PROFESSION) &&
                        (IsProfessionSkill(pSkill->id) || skillAbility->racemask != 0))
                        continue;

                    // World of Warcraft Client Patch 1.11.0 (2006-06-20)
                    // - Two-Handed Axes/Maces (Enhancement Talent) - Skill levels gained 
                    //   with these two weapons will now be retained if you decide to unspend
                    //   this talent point and return to it later.
#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_10_2
                    if (pSkill->categoryId == SKILL_CATEGORY_WEAPON)
                        if (GetSkillValuePure(pSkill->id) > m_mForgottenSkills[pSkill->id])
                            m_mForgottenSkills[pSkill->id] = GetSkillValuePure(pSkill->id);
#endif

                    SetSkill(uint16(pSkill->id), 0, 0);

                    if (pSkill->categoryId == SKILL_CATEGORY_WEAPON)
                        AutoUnequipWeaponsIfNeed();  
                }
            }
        }
    }
}

bool Player::IsActionButtonDataValid(uint8 button, uint32 action, uint8 type, Player* player)
{
    if (button >= MAX_ACTION_BUTTONS)
        return false;

    if (action >= MAX_ACTION_BUTTON_ACTION_VALUE)
        return false;

    switch (type)
    {
        case ACTION_BUTTON_SPELL:
        {
            SpellEntry const* spellProto = sSpellMgr.GetSpellEntry(action);
            if (!spellProto)
                return false;

            if (player)
            {
                if (!player->HasSpell(spellProto->Id))
                    return false;
                else if (spellProto->IsPassiveSpell())
                    return false;
            }
            break;
        }
        case ACTION_BUTTON_ITEM:
        {
            if (!ObjectMgr::GetItemPrototype(action))
                return false;
            break;
        }
        default:
            break;                                          // other cases not checked at this moment
    }

    return true;
}

bool Player::SetPosition(float x, float y, float z, float orientation, bool teleport)
{
    // prevent crash when a bad coord is sent by the client
    if (!MaNGOS::IsValidMapCoord(x, y, z, orientation))
    {
        DEBUG_LOG("Player::SetPosition(%f, %f, %f, %f, %d) .. bad coordinates for player %d!", x, y, z, orientation, teleport, GetGUIDLow());
        return false;
    }

    Map* m = GetMap();

    float const old_x = GetPositionX();
    float const old_y = GetPositionY();
    float const old_z = GetPositionZ();
    float const old_r = GetOrientation();

    if (teleport || old_x != x || old_y != y || old_z != z || old_r != orientation)
    {
        if (teleport || old_x != x || old_y != y || old_z != z)
            RemoveAurasWithInterruptFlags(AURA_INTERRUPT_FLAG_MOVE | AURA_INTERRUPT_FLAG_TURNING);
        else
            RemoveAurasWithInterruptFlags(AURA_INTERRUPT_FLAG_TURNING);

        RemoveSpellsCausingAura(SPELL_AURA_FEIGN_DEATH);

        // move and update visible state if need
        m->PlayerRelocation(this, x, y, z, orientation);

        // reread after Map::Relocation
        m = GetMap();
        x = GetPositionX();
        y = GetPositionY();
        z = GetPositionZ();

        // group update
        if (GetGroup() && (uint16(old_x) != uint16(x) || uint16(old_y) != uint16(y)))
            SetGroupUpdateFlag(GROUP_UPDATE_FLAG_POSITION);

        if (GetTrader() && !IsWithinDistInMap(GetTrader(), INTERACTION_DISTANCE))
            GetSession()->SendCancelTrade();   // will close both side trade windows
    }

    if (!m_areaCheckTimer && sWorld.getConfig(CONFIG_UINT32_RELOCATION_VMAP_CHECK_TIMER))
        m_areaCheckTimer = sWorld.getConfig(CONFIG_UINT32_RELOCATION_VMAP_CHECK_TIMER);
    else
    {
        UpdateTerainEnvironmentFlags();
        CheckAreaExploreAndOutdoor();
        LoadMapCellsAround(GetMap()->GetGridActivationDistance());
    }

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

void Player::SendMessageToSet(WorldPacket* data, bool self) const
{
    if (IsInWorld())
        GetMap()->MessageBroadcast(this, data, false);

    //if player is not in world and map in not created/already destroyed
    //no need to create one, just send packet for itself!
    if (self)
        GetSession()->SendPacket(data);
}

void Player::SendMessageToSetInRange(WorldPacket* data, float dist, bool self) const
{
    if (IsInWorld())
        GetMap()->MessageDistBroadcast(this, data, dist, false);

    if (self)
        GetSession()->SendPacket(data);
}

void Player::SendMessageToSetInRange(WorldPacket* data, float dist, bool self, bool own_team_only) const
{
    if (IsInWorld())
        GetMap()->MessageDistBroadcast(this, data, dist, false, own_team_only);

    if (self)
        GetSession()->SendPacket(data);
}

void Player::SendDirectMessage(WorldPacket* data) const
{
    GetSession()->SendPacket(data);
}

void Player::SendCinematicStart(uint32 CinematicSequenceId)
{
    WorldPacket data(SMSG_TRIGGER_CINEMATIC, 4);
    data << uint32(CinematicSequenceId);
    SendDirectMessage(&data);

    CinematicStart(CinematicSequenceId);
}

void Player::CheckAreaExploreAndOutdoor()
{
    if (!IsAlive())
        return;

    if (IsTaxiFlying())
        return;

    // Wait for cinematic to complete.
    if (m_currentCinematicEntry)
        return;

    bool isOutdoor;
    uint16 areaFlag = GetTerrain()->GetAreaFlag(GetPositionX(), GetPositionY(), GetPositionZ(), &isOutdoor);

    if (isOutdoor)
    {
        if (HasFlag(PLAYER_FLAGS, PLAYER_FLAGS_RESTING) && GetRestType() == REST_TYPE_IN_TAVERN)
        {
            AreaTriggerEntry const* at = sObjectMgr.GetAreaTrigger(m_innTriggerId);
            if (!at || !IsPointInAreaTriggerZone(at, GetMapId(), GetPositionX(), GetPositionY(), GetPositionZ()))
            {
                // Player left inn (REST_TYPE_IN_CITY overrides REST_TYPE_IN_TAVERN, so just clear rest)
                SetRestType(REST_TYPE_NO);
            }
        }
        // On reapplique les sorts retires lorsque l'on entre une zone interieure
        if (sWorld.getConfig(CONFIG_BOOL_VMAP_INDOOR_CHECK))
        {
            // Celerite feline - Druide
            if (GetShapeshiftForm() == FORM_CAT)
            {
                PlayerSpellMap const& sp_list = GetSpellMap();
                for (const auto& itr : sp_list)
                {
                    if (itr.second.state == PLAYERSPELL_REMOVED)
                        continue;
                    SpellEntry const* spellInfo = sSpellMgr.GetSpellEntry(itr.first);
                    if (!spellInfo || !spellInfo->IsNeedCastSpellAtFormApply(GetShapeshiftForm()) ||
                            !(spellInfo->Attributes & SPELL_ATTR_OUTDOORS_ONLY) ||
                            HasAura(spellInfo->Id))
                        continue;
                    CastSpell(this, itr.first, true);
                }
            }
            // Rapidite bestiale - Chasseur
            if (HasSpell(19596) && !HasAura(19596))
                CastSpell(this, 19596, true);
        }
    }
    else if (sWorld.getConfig(CONFIG_BOOL_VMAP_INDOOR_CHECK) && !IsGameMaster())
        RemoveAurasWithAttribute(SPELL_ATTR_OUTDOORS_ONLY);

    if (areaFlag == 0xffff)
        return;

    int offset = areaFlag / 32;

    if (offset >= PLAYER_EXPLORED_ZONES_SIZE)
    {
        sLog.outError("Wrong area flag %u in map data for (X: %f Y: %f) point to field PLAYER_EXPLORED_ZONES_1 + %u ( %u must be < %u ).", areaFlag, GetPositionX(), GetPositionY(), offset, offset, PLAYER_EXPLORED_ZONES_SIZE);
        return;
    }

    uint32 val = (uint32)(1 << (areaFlag % 32));
    uint32 currFields = GetUInt32Value(PLAYER_EXPLORED_ZONES_1 + offset);

    if (!(currFields & val))
    {
        SetUInt32Value(PLAYER_EXPLORED_ZONES_1 + offset, (uint32)(currFields | val));

        const auto* p = AreaEntry::GetByAreaFlagAndMap(areaFlag, GetMapId());
        if (!p)
            sLog.outError("PLAYER: Player %u discovered unknown area (x: %f y: %f map: %u", GetGUIDLow(), GetPositionX(), GetPositionY(), GetMapId());
        else
        {
            GetCheatData()->OnExplore(p);
            uint32 area = p->Id;
            uint32 xp = 0;
            if (p->AreaLevel > 0 && GetLevel() < sWorld.getConfig(CONFIG_UINT32_MAX_PLAYER_LEVEL))
            {
                float const explorationRate = GetPersonalXpRate() >= 0.0f ? GetPersonalXpRate() : sWorld.getConfig(CONFIG_FLOAT_RATE_XP_EXPLORE);
                int32 const diff = int32(GetLevel()) - p->AreaLevel;
                if (diff < -5)
                    xp = uint32(sObjectMgr.GetBaseXP(GetLevel() + 5) * explorationRate);
                else if (diff > 5)
                {
                    int32 exploration_percent = (100 - ((diff - 5) * 5));
                    if (exploration_percent > 100)
                        exploration_percent = 100;
                    else if (exploration_percent < 0)
                        exploration_percent = 0;

                    xp = uint32(sObjectMgr.GetBaseXP(p->AreaLevel) * exploration_percent / 100 * explorationRate);
                }
                else
                    xp = uint32(sObjectMgr.GetBaseXP(p->AreaLevel) * explorationRate);

                GiveXP(xp, nullptr);
            }

            // Exploration packet should be sent even if no XP is gained.
            SendExplorationExperience(area, xp);
            DETAIL_LOG("PLAYER: Player %u discovered a new area: %u", GetGUIDLow(), area);
        }
    }
}

Team Player::TeamForRace(uint8 race)
{
    ChrRacesEntry const* rEntry = sChrRacesStore.LookupEntry(race);
    if (!rEntry)
    {
        sLog.outError("Race %u not found in DBC: wrong DBC files?", uint32(race));
        return ALLIANCE;
    }

    switch (rEntry->TeamID)
    {
        case 7:
            return ALLIANCE;
        case 1:
            return HORDE;
    }

    sLog.outError("Race %u have wrong teamid %u in DBC: wrong DBC files?", uint32(race), rEntry->TeamID);
    return TEAM_NONE;
}

uint32 Player::GetFactionForRace(uint8 race)
{
    ChrRacesEntry const* rEntry = sChrRacesStore.LookupEntry(race);
    if (!rEntry)
    {
        sLog.outError("Race %u not found in DBC: wrong DBC files?", uint32(race));
        return 0;
    }

    return rEntry->FactionID;
}

void Player::SetFactionForRace(uint8 race)
{
    m_team = TeamForRace(race);
    SetFactionTemplateId(GetFactionForRace(race));
}

ReputationRank Player::GetReputationRank(uint32 faction) const
{
    FactionEntry const* factionEntry = sObjectMgr.GetFactionEntry(faction);
    return GetReputationMgr().GetRank(factionEntry);
}

//Calculate total reputation percent player gain with quest/creature level
int32 Player::CalculateReputationGain(ReputationSource source, int32 rep, int32 faction, uint32 creatureOrQuestLevel, bool noAuraBonus)
{
    float percent = 100.0f;

    float repMod = noAuraBonus ? 0.0f : (float)GetTotalAuraModifier(SPELL_AURA_MOD_REPUTATION_GAIN);

    // faction specific auras only seem to apply to kills
    if (source == REPUTATION_SOURCE_KILL)
        repMod += GetTotalAuraModifierByMiscValue(SPELL_AURA_MOD_FACTION_REPUTATION_GAIN, faction);

    percent += rep > 0 ? repMod : -repMod;

    // Ustaag <Nostalrius> : apply reduction from difference lvl between mob/quest and player (since patch 1.9)
    //  "When a monster is grey, or a quest is six levels below you, you lose 20%
    // of the total Reputation experience possible for that kill or quest for each level.
    // This descrease continues until you reach the minimum reputation gain of 20%."
    // Example : for a lvl 50 quest (25 reputation reward)
    // CharacterLvl     Reputation earned       Reputation rate
    //      50                  25                  100 %
    //      56                  20                  80 %
    //      57                  15                  60 %
    //      58                  10                  40 %
    //      59                  5                   20 %
    //      60                  5                   20 %

    float rate;
    float diffLvlRate;
    uint32 diffLvl = 0;
    switch (source)
    {
        case REPUTATION_SOURCE_KILL:
            rate = sWorld.getConfig(CONFIG_FLOAT_RATE_REPUTATION_LOWLEVEL_KILL);
            // Ustaag <Nostalrius> : a priori, deja gere ailleurs... deque le mob est gris, la reput est divisee par 5.
            /*if (MaNGOS::XP::GetGrayLevel(GetLevel()) >= creatureOrQuestLevel)
                diffLvl = MaNGOS::XP::GetGrayLevel(GetLevel()) - creatureOrQuestLevel;
            else
                diffLvl = 0;*/
            break;
        case REPUTATION_SOURCE_QUEST:
            rate = sWorld.getConfig(CONFIG_FLOAT_RATE_REPUTATION_LOWLEVEL_QUEST);
            if (GetLevel() >= creatureOrQuestLevel + 5)
                diffLvl = GetLevel() - creatureOrQuestLevel - 5;
            else
                diffLvl = 0;
            break;
        case REPUTATION_SOURCE_SPELL:
        default:
            rate = 1.0f;
            break;
    }

    switch (diffLvl)
    {
        case 0:
            diffLvlRate = 1.0f;
            break;
        case 1:
            diffLvlRate = 0.8f;
            break;
        case 2:
            diffLvlRate = 0.6f;
            break;
        case 3:
            diffLvlRate = 0.4f;
            break;
        default:
            diffLvlRate = 0.2f;
            break;
    }

    // Ustaag <Nostalrius> : uniquement pour les quetes, cf. plus haut
    if (source == REPUTATION_SOURCE_QUEST)
        percent *= diffLvlRate;

    if (rate != 1.0f && creatureOrQuestLevel <= MaNGOS::XP::GetGrayLevel(GetLevel()))
        percent *= rate;

    if (percent <= 0.0f)
        return 0;

    // Multiply result with the faction specific rate
    if (RepRewardRate const* repData = sObjectMgr.GetRepRewardRate(faction))
    {
        float repRate = 0.0f;
        switch (source)
        {
            case REPUTATION_SOURCE_KILL:
                repRate = repData->creature_rate;
                break;
            case REPUTATION_SOURCE_QUEST:
                repRate = repData->quest_rate;
                break;
            case REPUTATION_SOURCE_SPELL:
                repRate = repData->spell_rate;
                break;
        }

        // for custom, a rate of 0.0 will totally disable reputation gain for this faction/type
        if (repRate <= 0.0f)
            return 0;

        percent *= repRate;
    }

    return int32(round_float(sWorld.getConfig(CONFIG_FLOAT_RATE_REPUTATION_GAIN) * rep * percent / 100.0f));
}

//Calculates how many reputation points player gains in victim's enemy factions
void Player::RewardReputation(Unit* pVictim, float rate)
{
    if (!pVictim || pVictim->IsPlayer())
        return;

    // World of Warcraft Client Patch 1.10.0 (2006-03-28)
    // - Pets no longer modify your reputation if you kill them.
    if (pVictim->IsPet() && sWorld.GetWowPatch() >= WOW_PATCH_110)
        return;

    ReputationOnKillEntry const* Rep = sObjectMgr.GetReputationOnKillEntry(((Creature*)pVictim)->GetEntry());

    if (!Rep)
        return;

    if (Rep->repfaction1 && (!Rep->team_dependent || GetTeam() == ALLIANCE))
    {
        int32 donerep1 = CalculateReputationGain(REPUTATION_SOURCE_KILL, Rep->repvalue1, Rep->repfaction1, pVictim->GetLevel());
        donerep1 = int32(donerep1 * rate);
        FactionEntry const* factionEntry1 = sObjectMgr.GetFactionEntry(Rep->repfaction1);
        uint32 current_reputation_rank1 = GetReputationMgr().GetRank(factionEntry1);

        // World of Warcraft Client Patch 1.9.0 (2006-01-03)
        // - Reputation caps for killing monsters now happen at the end of a 
        //   level, rather than in the middle of it. For example : if reputation
        //   gains for killing a monster were previously capped at the middle of
        //   the range for Friendly on a monster, then they are now capped at the
        //   end of Friendly.
#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_8_4
        if (factionEntry1 && current_reputation_rank1 <= Rep->reputation_max_cap1)
#else
        if (factionEntry1 && (GetReputationMgr().GetReputation(factionEntry1) < (ReputationMgr::GetRepPointsToRank(ReputationRank(Rep->reputation_max_cap1)) + (ReputationMgr::PointsInRank[Rep->reputation_max_cap1] / 2))))
#endif
            GetReputationMgr().ModifyReputation(factionEntry1, donerep1);

        // Wiki: Team factions value divided by 2
        if (factionEntry1 && Rep->is_teamaward1)
        {
            FactionEntry const* team1_factionEntry = sObjectMgr.GetFactionEntry(factionEntry1->team);
            if (team1_factionEntry)
                GetReputationMgr().ModifyReputation(team1_factionEntry, donerep1 / 2, true);
        }
    }

    if (Rep->repfaction2 && (!Rep->team_dependent || GetTeam() == HORDE))
    {
        int32 donerep2 = CalculateReputationGain(REPUTATION_SOURCE_KILL, Rep->repvalue2, Rep->repfaction2, pVictim->GetLevel());
        donerep2 = int32(donerep2 * rate);
        FactionEntry const* factionEntry2 = sObjectMgr.GetFactionEntry(Rep->repfaction2);
        uint32 current_reputation_rank2 = GetReputationMgr().GetRank(factionEntry2);

#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_8_4
        if (factionEntry2 && current_reputation_rank2 <= Rep->reputation_max_cap2)
#else
        if (factionEntry2 && (GetReputationMgr().GetReputation(factionEntry2) < (ReputationMgr::GetRepPointsToRank(ReputationRank(Rep->reputation_max_cap2)) + (ReputationMgr::PointsInRank[Rep->reputation_max_cap2] / 2))))
#endif
            GetReputationMgr().ModifyReputation(factionEntry2, donerep2);

        // Wiki: Team factions value divided by 2
        if (factionEntry2 && Rep->is_teamaward2)
        {
            FactionEntry const* team2_factionEntry = sObjectMgr.GetFactionEntry(factionEntry2->team);
            if (team2_factionEntry)
                GetReputationMgr().ModifyReputation(team2_factionEntry, donerep2 / 2, true);
        }
    }
}

//Calculate how many reputation points player gain with the quest
void Player::RewardReputation(Quest const* pQuest)
{
    // quest reputation reward/loss
    for (int i = 0; i < QUEST_REPUTATIONS_COUNT; ++i)
    {
        if (!pQuest->RewRepFaction[i])
            continue;

        if (pQuest->RewRepValue[i])
        {
            int32 rep = CalculateReputationGain(REPUTATION_SOURCE_QUEST,  pQuest->RewRepValue[i], pQuest->RewRepFaction[i], GetQuestLevelForPlayer(pQuest));

            if (FactionEntry const* factionEntry = sObjectMgr.GetFactionEntry(pQuest->RewRepFaction[i]))
                GetReputationMgr().ModifyReputation(factionEntry, rep);
        }
    }

    // TODO: implement reputation spillover
}

uint32 Player::GetGuildIdFromDB(ObjectGuid guid)
{
    uint32 lowguid = guid.GetCounter();

    QueryResult* result = CharacterDatabase.PQuery("SELECT `guild_id` FROM `guild_member` WHERE `guid`='%u'", lowguid);
    if (!result)
        return 0;

    uint32 id = result->Fetch()[0].GetUInt32();
    delete result;
    return id;
}

uint32 Player::GetRankFromDB(ObjectGuid guid)
{
    QueryResult* result = CharacterDatabase.PQuery("SELECT `rank` FROM `guild_member` WHERE `guid`='%u'", guid.GetCounter());
    if (result)
    {
        uint32 v = result->Fetch()[0].GetUInt32();
        delete result;
        return v;
    }
    else
        return 0;
}

uint32 Player::GetZoneIdFromDB(ObjectGuid guid)
{
    uint32 lowguid = guid.GetCounter();
    uint32 zone = 0;
    if (PlayerCacheData* data = sObjectMgr.GetPlayerDataByGUID(guid))
    {
        if (data->uiZoneId)
            zone = data->uiZoneId;
        else
            zone = sTerrainMgr.GetZoneId(data->uiMapId, data->fPosX, data->fPosY, data->fPosZ);
    }
    else
    {
        QueryResult* result = CharacterDatabase.PQuery("SELECT `zone` FROM `characters` WHERE `guid`='%u'", lowguid);
        if (!result)
            return 0;
        Field* fields = result->Fetch();
        zone = fields[0].GetUInt32();
        delete result;

        if (!zone)
        {
            // stored zone is zero, use generic and slow zone detection
            result = CharacterDatabase.PQuery("SELECT `map`, `position_x`, `position_y`, `position_z` FROM `characters` WHERE `guid`='%u'", lowguid);
            if (!result)
                return 0;
            fields = result->Fetch();
            uint32 map = fields[0].GetUInt32();
            float posx = fields[1].GetFloat();
            float posy = fields[2].GetFloat();
            float posz = fields[3].GetFloat();
            delete result;

            zone = sTerrainMgr.GetZoneId(map, posx, posy, posz);

            if (zone > 0)
                CharacterDatabase.PExecute("UPDATE `characters` SET `zone`='%u' WHERE `guid`='%u'", zone, lowguid);
        }
    }
    return zone;
}

uint32 Player::GetLevelFromDB(ObjectGuid guid)
{
    uint32 lowguid = guid.GetCounter();

    if (PlayerCacheData* data = sObjectMgr.GetPlayerDataByGUID(lowguid))
    {
        return data->uiLevel;
    }
    else
    {
        QueryResult* result = CharacterDatabase.PQuery("SELECT `level` FROM `characters` WHERE `guid`='%u'", lowguid);
        if (!result)
            return 0;

        Field* fields = result->Fetch();
        uint32 level = fields[0].GetUInt32();
        delete result;

        return level;
    }
}

void Player::DismountCheck()
{
    if (IsMounted())
    {
        auto auras = this->GetAurasByType(SPELL_AURA_MOUNTED);

        for (auto& aura : auras)
        {
            Spell mountSpell(this, aura->GetSpellProto(), true);
            SpellCastResult pCheck = mountSpell.CheckCast(true);

            if (pCheck == SPELL_FAILED_NO_MOUNTS_ALLOWED || pCheck == SPELL_FAILED_NOT_HERE)
            {
                RemoveSpellsCausingAura(SPELL_AURA_MOUNTED);
                Unmount(true);
            }
        }
    }
}

void Player::SetTransport(GenericTransport* t)
{
    WorldObject::SetTransport(t);

    if (t) // don't bother checking when exiting a transport
    {
        DismountCheck();
    }
}

void Player::UpdateArea(uint32 newArea)
{
    m_areaUpdateId    = newArea;

    DismountCheck();

    const auto* areaEntry = AreaEntry::GetById(newArea);

    // FFA_PVP flags are area and not zone id dependent
    // so apply them accordingly
    if (areaEntry && (areaEntry->Flags & AREA_FLAG_ARENA))
    {
        if (!IsGameMaster())
            SetFFAPvP(true);
    }
    else
    {
        // remove ffa flag only if not ffapvp realm
        // removal in sanctuaries and capitals is handled in zone update
        if (IsFFAPvP() && !sWorld.IsFFAPvPRealm())
            SetFFAPvP(false);
    }

    UpdateAreaDependentAuras();
}

void Player::UpdateZone(uint32 newZone, uint32 newArea)
{
    uint32 oldZoneId  = m_zoneUpdateId;

    const auto* zoneEntry = AreaEntry::GetById(newZone);
    if (!zoneEntry)
        return;

    if (m_zoneUpdateId != newZone)
    {
        sZoneScriptMgr.HandlePlayerLeaveZone(this, oldZoneId);
        SendInitWorldStates(newZone);                       // only if really enters to new zone, not just area change, works strange...
        sZoneScriptMgr.HandlePlayerEnterZone(this, newZone);

        if (sWorld.getConfig(CONFIG_BOOL_WEATHER))
        {
            Weather* wth = GetMap()->GetWeatherSystem()->FindOrCreateWeather(newZone);
            wth->SendWeatherUpdateToPlayer(this);
        }
    }

    m_zoneUpdateId    = newZone;
    m_zoneUpdateTimer = ZONE_UPDATE_INTERVAL;

    // zone changed, so area changed as well, update it
    UpdateArea(newArea);

    // in PvP, any not controlled zone (except zone->team == 6, default case)
    // in PvE, only opposition team capital
    switch (zoneEntry->Team)
    {
        case AREATEAM_ALLY:
            pvpInfo.inPvPEnforcedArea = GetTeam() != ALLIANCE && (sWorld.IsPvPRealm() || zoneEntry->Flags & AREA_FLAG_CAPITAL);
            break;
        case AREATEAM_HORDE:
            pvpInfo.inPvPEnforcedArea = GetTeam() != HORDE && (sWorld.IsPvPRealm() || zoneEntry->Flags & AREA_FLAG_CAPITAL);
            break;
        case AREATEAM_NONE:
            // overwrite for battlegrounds, maybe batter some zone flags but current known not 100% fit to this
            pvpInfo.inPvPEnforcedArea = sWorld.IsPvPRealm() || InBattleGround();
            break;
        default:                                            // 6 in fact
            pvpInfo.inPvPEnforcedArea = false;
            break;
    }

    if (pvpInfo.inPvPEnforcedArea && !IsTaxiFlying()) // in hostile area
        UpdatePvP(true);

    if ((zoneEntry->Flags & AREA_FLAG_CAPITAL) && !pvpInfo.inPvPEnforcedArea) // in capital city
        SetRestType(REST_TYPE_IN_CITY);
    else if (HasFlag(PLAYER_FLAGS, PLAYER_FLAGS_RESTING) && GetRestType() != REST_TYPE_IN_TAVERN)
        // resting and not in tavern (leave city then); tavern leave handled in CheckAreaExploreAndOutdoor
        SetRestType(REST_TYPE_NO);

    // remove items with area/map limitations (delete only for alive player to allow back in ghost mode)
    // if player resurrected at teleport this will be applied in resurrect code
    if (IsAlive())
        DestroyZoneLimitedItem(true, newZone);

    // recent client version not send leave/join channel packets for built-in local channels
    // When flying in a taxi, we don't change channels in preBC :
    // http://youtube.be/iUFpZeNGPSs?t=32m
    if (!IsTaxiFlying())
        UpdateLocalChannels(newZone);

    // group update
    if (GetGroup())
        SetGroupUpdateFlag(GROUP_UPDATE_FLAG_ZONE);

    UpdateZoneDependentAuras();
    SetZoneScript();
}

//If players are too far way of duel flag... then player loose the duel
void Player::CheckDuelDistance(time_t currTime)
{
    if (!duel || duel->finished)
        return;

    GameObject* obj = GetMap()->GetGameObject(GetGuidValue(PLAYER_DUEL_ARBITER));
    if (!obj)
    {
        // player not at duel start map
        DuelComplete(DUEL_FLED);
        return;
    }

    bool inRange = true;
    if (duel->transportGuid)
        inRange = GetTransport() && GetTransport()->GetGUIDLow() == duel->transportGuid;
    else if (!IsWithinDistInMap(obj, duel->outOfBound ? 70.0f : 75.0f))
        inRange = false;
    if (duel->outOfBound == 0)
    {
        // Nostalrius : modification de la distance de duel (50 -> 75m)
        if (!inRange)
        {
            duel->outOfBound = currTime;

            WorldPacket data(SMSG_DUEL_OUTOFBOUNDS, 0);
            GetSession()->SendPacket(&data);
        }
    }
    else
    {
        // Nostalrius : modification de la distance de duel
        if (inRange)
        {
            duel->outOfBound = 0;

            WorldPacket data(SMSG_DUEL_INBOUNDS, 0);
            GetSession()->SendPacket(&data);
        }
        else if (currTime >= (duel->outOfBound + 10))
        {
            CombatStopWithPets(true);
            if (duel->opponent)
                duel->opponent->CombatStopWithPets(true);

            DuelComplete(DUEL_FLED);
        }
    }
}

bool Player::IsOutdoorPvPActive() const
{
    return (IsAlive() && !HasInvisibilityAura() && !HasStealthAura() &&
            (HasFlag(PLAYER_FLAGS, PLAYER_FLAGS_PVP_DESIRED) || sWorld.IsPvPRealm()) && !IsTaxiFlying());
}

void Player::DuelComplete(DuelCompleteType type)
{
    // duel not requested
    if (!duel || duel->finished)
        return;

    WorldPacket data(SMSG_DUEL_COMPLETE, (1));
    data << (uint8)((type != DUEL_INTERRUPTED) ? 1 : 0);
    GetSession()->SendPacket(&data);
    duel->opponent->GetSession()->SendPacket(&data);

    if (type != DUEL_INTERRUPTED)
    {
        data.Initialize(SMSG_DUEL_WINNER, (1 + 20));        // we guess size
        data << (uint8)((type == DUEL_WON) ? 0 : 1);        // 0 = just won; 1 = fled
        data << duel->opponent->GetName();
        data << GetName();
        SendObjectMessageToSet(&data, true);
    }

    //Remove Duel Flag object
    if (GameObject* obj = GetMap()->GetGameObject(GetGuidValue(PLAYER_DUEL_ARBITER)))
        duel->initiator->RemoveGameObject(obj, true);

    /* remove auras */
    std::vector<uint32> auras2remove;
    SpellAuraHolderMap const& vAuras = duel->opponent->GetSpellAuraHolderMap();
    for (const auto& itr : vAuras)
    {
        if (!itr.second->IsPositive() && itr.second->GetCasterGuid() == GetObjectGuid() && itr.second->GetAuraApplyTime() >= duel->startTime)
            auras2remove.push_back(itr.second->GetId());
    }

    for (uint32 i : auras2remove)
        duel->opponent->RemoveAurasDueToSpell(i);

    auras2remove.clear();
    SpellAuraHolderMap const& auras = GetSpellAuraHolderMap();
    for (const auto& aura : auras)
    {
        if (!aura.second->IsPositive() && aura.second->GetCasterGuid() == duel->opponent->GetObjectGuid() && aura.second->GetAuraApplyTime() >= duel->startTime)
            auras2remove.push_back(aura.second->GetId());
    }
    for (uint32 i : auras2remove)
        RemoveAurasDueToSpell(i);

    // cleanup combo points
    if (GetComboTargetGuid() == duel->opponent->GetObjectGuid())
        ClearComboPoints();
    else if (GetComboTargetGuid() == duel->opponent->GetPetGuid())
        ClearComboPoints();

    if (duel->opponent->GetComboTargetGuid() == GetObjectGuid())
        duel->opponent->ClearComboPoints();
    else if (duel->opponent->GetComboTargetGuid() == GetPetGuid())
        duel->opponent->ClearComboPoints();

    // reset extraAttacks counter
    if (type != DUEL_INTERRUPTED)
    {
        ResetExtraAttacks();
        duel->opponent->ResetExtraAttacks();
    }

    //cleanups
    SetGuidValue(PLAYER_DUEL_ARBITER, ObjectGuid());
    SetUInt32Value(PLAYER_DUEL_TEAM, 0);
    duel->opponent->SetGuidValue(PLAYER_DUEL_ARBITER, ObjectGuid());
    duel->opponent->SetUInt32Value(PLAYER_DUEL_TEAM, 0);

    if (duel->opponent->duel)
        duel->opponent->duel->finished = true;;
    duel->finished = true;
}

//---------------------------------------------------------//

void Player::_ApplyItemMods(Item* item, uint8 slot, bool apply)
{
    if (slot >= INVENTORY_SLOT_BAG_END || !item)
        return;

    // not apply/remove mods for broken item
    if (item->IsBroken())
        return;

    ItemPrototype const* proto = item->GetProto();

    if (!proto)
        return;

    DETAIL_LOG("applying mods for item %u ", item->GetGUIDLow());

    if (apply)
    {
        uint32 attacktype = Player::GetAttackBySlot(slot);
        if (attacktype < MAX_ATTACK)
            _ApplyWeaponDependentAuraMods(item, WeaponAttackType(attacktype), true);

        _ApplyItemBonuses(proto, slot, true);

        if (slot == EQUIPMENT_SLOT_RANGED)
            _ApplyAmmoBonuses();

        ApplyItemEquipSpell(item, true);
        ApplyEnchantment(item, true);
    }
    else // order must be reversed when removing weapon dependent aura mods
    {
        ApplyItemEquipSpell(item, false);
        ApplyEnchantment(item, false);

        uint32 attacktype = Player::GetAttackBySlot(slot);
        if (attacktype < MAX_ATTACK)
            _ApplyWeaponDependentAuraMods(item, WeaponAttackType(attacktype), false);

        _ApplyItemBonuses(proto, slot, false);

        if (slot == EQUIPMENT_SLOT_RANGED)
            _ApplyAmmoBonuses();
    }

    DEBUG_LOG("_ApplyItemMods complete.");
}

void Player::_ApplyItemBonuses(ItemPrototype const* proto, uint8 slot, bool apply)
{
    if (slot >= INVENTORY_SLOT_BAG_END || !proto)
        return;

    for (const auto& i : proto->ItemStat)
    {
        float val = float(i.ItemStatValue);

        if (val == 0)
            continue;

        switch (i.ItemStatType)
        {
            case ITEM_MOD_MANA:
                HandleStatModifier(UNIT_MOD_MANA, BASE_VALUE, float(val), apply);
                break;
            case ITEM_MOD_HEALTH:                           // modify HP
                HandleStatModifier(UNIT_MOD_HEALTH, BASE_VALUE, float(val), apply);
                break;
            case ITEM_MOD_AGILITY:                          // modify agility
                HandleStatModifier(UNIT_MOD_STAT_AGILITY, BASE_VALUE, float(val), apply);
                ApplyStatBuffMod(STAT_AGILITY, float(val), apply);
                break;
            case ITEM_MOD_STRENGTH:                         //modify strength
                HandleStatModifier(UNIT_MOD_STAT_STRENGTH, BASE_VALUE, float(val), apply);
                ApplyStatBuffMod(STAT_STRENGTH, float(val), apply);
                break;
            case ITEM_MOD_INTELLECT:                        //modify intellect
                HandleStatModifier(UNIT_MOD_STAT_INTELLECT, BASE_VALUE, float(val), apply);
                ApplyStatBuffMod(STAT_INTELLECT, float(val), apply);
                break;
            case ITEM_MOD_SPIRIT:                           //modify spirit
                HandleStatModifier(UNIT_MOD_STAT_SPIRIT, BASE_VALUE, float(val), apply);
                ApplyStatBuffMod(STAT_SPIRIT, float(val), apply);
                break;
            case ITEM_MOD_STAMINA:                          //modify stamina
                HandleStatModifier(UNIT_MOD_STAT_STAMINA, BASE_VALUE, float(val), apply);
                ApplyStatBuffMod(STAT_STAMINA, float(val), apply);
                break;
        }
    }

    if (proto->Armor)
        HandleStatModifier(UNIT_MOD_ARMOR, BASE_VALUE, float(proto->Armor), apply);

    if (proto->Block)
        HandleBaseModValue(SHIELD_BLOCK_VALUE, FLAT_MOD, float(proto->Block), apply);

    if (proto->HolyRes)
        HandleStatModifier(UNIT_MOD_RESISTANCE_HOLY, BASE_VALUE, float(proto->HolyRes), apply);

    if (proto->FireRes)
        HandleStatModifier(UNIT_MOD_RESISTANCE_FIRE, BASE_VALUE, float(proto->FireRes), apply);

    if (proto->NatureRes)
        HandleStatModifier(UNIT_MOD_RESISTANCE_NATURE, BASE_VALUE, float(proto->NatureRes), apply);

    if (proto->FrostRes)
        HandleStatModifier(UNIT_MOD_RESISTANCE_FROST, BASE_VALUE, float(proto->FrostRes), apply);

    if (proto->ShadowRes)
        HandleStatModifier(UNIT_MOD_RESISTANCE_SHADOW, BASE_VALUE, float(proto->ShadowRes), apply);

    if (proto->ArcaneRes)
        HandleStatModifier(UNIT_MOD_RESISTANCE_ARCANE, BASE_VALUE, float(proto->ArcaneRes), apply);

    if (proto->IsWeapon())
    {
        WeaponAttackType attType = BASE_ATTACK;

        if (slot == EQUIPMENT_SLOT_RANGED && proto->IsRangedWeapon())
            attType = RANGED_ATTACK;
        else if (slot == EQUIPMENT_SLOT_OFFHAND)
            attType = OFF_ATTACK;

        bool hasDamage = false;
        m_weaponDamageCount[attType] = 0;

        for (uint8 i = 0; i < MAX_ITEM_PROTO_DAMAGES; i++)
        {
            if (proto->Damage[i].DamageMax == 0)
                break;

            hasDamage = true;

            float minDamage = 0.0f;
            float maxDamage = 0.0f;
            SpellSchools school = SPELL_SCHOOL_NORMAL;

            if (apply)
            {
                minDamage = proto->Damage[i].DamageMin;
                maxDamage = proto->Damage[i].DamageMax;
                school = SpellSchools(proto->Damage[i].DamageType);

                m_weaponDamageCount[attType]++;
            }

            SetBaseWeaponDamage(attType, MINDAMAGE, minDamage, i);
            SetBaseWeaponDamage(attType, MAXDAMAGE, maxDamage, i);
            SetWeaponDamageSchool(attType, school, i);
        }

        if (m_weaponDamageCount[attType] == 0)
            m_weaponDamageCount[attType] = 1;

        if (!CanUseEquippedWeapon(attType))
            return;

        if (proto->Delay)
        {
            if (slot == EQUIPMENT_SLOT_RANGED)
                SetAttackTime(RANGED_ATTACK, apply ? proto->Delay : BASE_ATTACK_TIME);
            else if (slot == EQUIPMENT_SLOT_MAINHAND)
                SetAttackTime(BASE_ATTACK, apply ? proto->Delay : BASE_ATTACK_TIME);
            else if (slot == EQUIPMENT_SLOT_OFFHAND)
                SetAttackTime(OFF_ATTACK, apply ? proto->Delay : BASE_ATTACK_TIME);
        }

        if (CanModifyStats() && proto->Delay)
            UpdateDamagePhysical(attType);
    }
}

void Player::_ApplyWeaponDependentAuraMods(Item* item, WeaponAttackType attackType, bool apply)
{
    if (apply && !CanUseEquippedWeapon(attackType))
        return;

    AuraList const& auraCritList = GetAurasByType(SPELL_AURA_MOD_CRIT_PERCENT);
    for (const auto itr : auraCritList)
        _ApplyWeaponDependentAuraCritMod(item, attackType, itr, apply);

    AuraList const& auraDamageFlatList = GetAurasByType(SPELL_AURA_MOD_DAMAGE_DONE);
    for (const auto itr : auraDamageFlatList)
        _ApplyWeaponDependentAuraDamageMod(item, attackType, itr, apply);

    AuraList const& auraDamagePCTList = GetAurasByType(SPELL_AURA_MOD_DAMAGE_PERCENT_DONE);
    for (const auto itr : auraDamagePCTList)
        _ApplyWeaponDependentAuraDamageMod(item, attackType, itr, apply);
}

void Player::_ApplyWeaponDependentAuraCritMod(Item* item, WeaponAttackType attackType, Aura* aura, bool apply)
{
    // don't apply mod if item is broken or cannot be used
    if (item->IsBroken() || !CanUseEquippedWeapon(attackType))
        return;

    // generic not weapon specific case processes in aura code
    if (aura->GetSpellProto()->EquippedItemClass == -1)
        return;

    // handled only auras applied by this item (enchants) or all auras without itemCaster (talents)
    if (aura->GetCastItemGuid() && aura->GetCastItemGuid() != item->GetObjectGuid())
        return;

    // auras without itemCaster not applied in offhand crit and not removing mods if has eligible weapon
    if (!aura->GetCastItemGuid() && attackType == OFF_ATTACK)
        return;

    BaseModGroup mod = BASEMOD_END;
    switch (attackType)
    {
        case BASE_ATTACK:
            mod = CRIT_PERCENTAGE;
            break;
        case OFF_ATTACK:
            mod = OFFHAND_CRIT_PERCENTAGE;
            break;
        case RANGED_ATTACK:
            mod = RANGED_CRIT_PERCENTAGE;
            break;
        default:
            return;
    }

    if (item->IsFitToSpellRequirements(aura->GetSpellProto()))
        HandleBaseModValue(mod, FLAT_MOD, aura->GetModifier()->m_amount, apply);
}

void Player::_ApplyWeaponDependentAuraDamageMod(Item* item, WeaponAttackType attackType, Aura* aura, bool apply)
{
    // ignore spell mods for not wands
    Modifier const* modifier = aura->GetModifier();
    if ((modifier->m_miscvalue & SPELL_SCHOOL_MASK_NORMAL) == 0 && (GetClassMask() & CLASSMASK_WAND_USERS) == 0)
        return;

    // generic not weapon specific case processes in aura code
    if (aura->GetSpellProto()->EquippedItemClass == -1)
        return;

    UnitMods unitMod = UNIT_MOD_END;
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
            return;
    }

    UnitModifierType unitModType = TOTAL_VALUE;
    switch (modifier->m_auraname)
    {
        case SPELL_AURA_MOD_DAMAGE_DONE:
            unitModType = TOTAL_VALUE;
            break;
        case SPELL_AURA_MOD_DAMAGE_PERCENT_DONE:
            unitModType = TOTAL_PCT;
            break;
        default:
            return;
    }

    if (item->IsFitToSpellRequirements(aura->GetSpellProto()))
        HandleStatModifier(unitMod, unitModType, modifier->m_amount, apply);
}

void Player::ApplyItemEquipSpell(Item* item, bool apply, bool form_change)
{
    if (!item)
        return;

    ItemPrototype const* proto = item->GetProto();
    if (!proto)
        return;

    for (const auto& spellData : proto->Spells)
    {
        // no spell
        if (!spellData.SpellId)
            continue;

        if (apply)
        {
            // apply only at-equip spells
            if (spellData.SpellTrigger != ITEM_SPELLTRIGGER_ON_EQUIP)
                continue;
        }
        else
        {
            // at un-apply remove all spells (not only at-apply, so any at-use active affects from item and etc)
            // except with at-use with negative charges, so allow consuming item spells (including with extra flag that prevent consume really)
            // applied to player after item remove from equip slot
            if (spellData.SpellTrigger == ITEM_SPELLTRIGGER_ON_USE && spellData.SpellCharges < 0)
                continue;
        }

        // check if it is valid spell
        SpellEntry const* spellproto = sSpellMgr.GetSpellEntry(spellData.SpellId);
        if (!spellproto)
            continue;

        // Nostalrius : Ne pas dissiper ces sorts quand on desequipe / supprime le bijoux (pierre de sort)
        if (!apply && spellData.SpellTrigger == ITEM_SPELLTRIGGER_ON_USE)
            continue;

        ApplyEquipSpell(spellproto, item, apply, form_change);
    }
}

void Player::ApplyEquipSpell(SpellEntry const* spellInfo, Item* item, bool apply, bool form_change)
{
    if (apply)
    {
        // Cannot be used in this stance/form
        if (spellInfo->GetErrorAtShapeshiftedCast(GetShapeshiftForm()) != SPELL_CAST_OK)
            return;

        if (form_change)                                    // check aura active state from other form
        {
            bool found = false;
            for (uint8 i = 0; i < MAX_EFFECT_INDEX; ++i)
            {
                SpellAuraHolderBounds spair = GetSpellAuraHolderBounds(spellInfo->Id);
                for (SpellAuraHolderMap::const_iterator iter = spair.first; iter != spair.second; ++iter)
                {
                    if (!item || iter->second->GetCastItemGuid() == item->GetObjectGuid())
                    {
                        found = true;
                        break;
                    }
                }
                if (found)
                    break;
            }

            if (found)                                      // and skip re-cast already active aura at form change
                return;
        }

        DEBUG_LOG("WORLD: cast %s Equip spellId - %i", (item ? "item" : "itemset"), spellInfo->Id);

        CastSpell(this, spellInfo, true, item);
    }
    else
    {
        if (form_change)                                    // check aura compatibility
        {
            // Cannot be used in this stance/form
            if (spellInfo->GetErrorAtShapeshiftedCast(GetShapeshiftForm()) == SPELL_CAST_OK)
                return;                                     // and remove only not compatible at form change
        }

        if (item)
            RemoveAurasDueToItemSpell(item, spellInfo->Id); // un-apply all spells , not only at-equipped
        else
            RemoveSingleAuraDueToItemSet(spellInfo->Id);    // un-apply spell (item set case)
    }
}

void Player::UpdateEquipSpellsAtFormChange()
{
    for (int i = 0; i < INVENTORY_SLOT_BAG_END; ++i)
    {
        if (m_items[i] && !m_items[i]->IsBroken())
        {
            ApplyItemEquipSpell(m_items[i], false, true);   // remove spells that not fit to form
            ApplyItemEquipSpell(m_items[i], true, true);    // add spells that fit form but not active
        }
    }

    // item set bonuses not dependent from item broken state
    for (const auto eff : m_ItemSetEff)
    {
        if (!eff)
            continue;

        for (const auto spellInfo : eff->spells)
        {
            if (!spellInfo)
                continue;

            ApplyEquipSpell(spellInfo, nullptr, false, true);    // remove spells that not fit to form
            ApplyEquipSpell(spellInfo, nullptr, true, true);     // add spells that fit form but not active
        }
    }
}

void Player::CastItemCombatSpell(Unit* Target, WeaponAttackType attType)
{
    Item* item = GetWeaponForAttack(attType, true, true);
    if (!item)
        return;

    ItemPrototype const* proto = item->GetProto();
    if (!proto)
        return;

    if (!Target || Target == this)
        return;

    uint32 WeaponSpeed = proto->Delay;

    for (const auto& spellData : proto->Spells)
    {
        // no spell
        if (!spellData.SpellId)
            continue;

        // wrong triggering type
        if (spellData.SpellTrigger != ITEM_SPELLTRIGGER_CHANCE_ON_HIT)
            continue;

        SpellEntry const* spellInfo = sSpellMgr.GetSpellEntry(spellData.SpellId);
        if (!spellInfo)
        {
            sLog.outError("WORLD: unknown Item spellid %i", spellData.SpellId);
            continue;
        }

        // not allow proc extra attack spell at extra attack
        if (GetExtraAttacks() && spellInfo->HasEffect(SPELL_EFFECT_ADD_EXTRA_ATTACKS))
            return;

        // Need to check gcd here because the cast is triggered and skips it.
        if (HasGCD(spellInfo))
            continue;

        float chance = (float)spellInfo->procChance;

        if (spellData.SpellPPMRate)
        {
            chance = GetPPMProcChance(WeaponSpeed, spellData.SpellPPMRate);
        }
        else if (chance > 100.0f)
            chance = GetPPMProcChance(WeaponSpeed, 1.0f);   // default to 1 PPM for unknown proc rates

        if (roll_chance_f(chance))
            CastSpell(Target, spellInfo->Id, true, item);
    }

    // item combat enchantments
    for (int e_slot = 0; e_slot < MAX_ENCHANTMENT_SLOT; ++e_slot)
    {
        uint32 enchant_id = item->GetEnchantmentId(EnchantmentSlot(e_slot));
        SpellItemEnchantmentEntry const* pEnchant = sSpellItemEnchantmentStore.LookupEntry(enchant_id);
        if (!pEnchant) continue;
        for (int s = 0; s < 3; ++s)
        {
            uint32 proc_spell_id = pEnchant->spellid[s];

            if (pEnchant->type[s] != ITEM_ENCHANTMENT_TYPE_COMBAT_SPELL)
                continue;

            SpellEntry const* spellInfo = sSpellMgr.GetSpellEntry(proc_spell_id);
            if (!spellInfo)
            {
                sLog.outError("Player::CastItemCombatSpell Enchant %i, cast unknown spell %i", pEnchant->ID, proc_spell_id);
                continue;
            }

            // Use first rank to access spell item enchant procs
            float ppmRate = sSpellMgr.GetItemEnchantProcChance(spellInfo->Id);

            float chance = ppmRate
                           ? GetPPMProcChance(WeaponSpeed, ppmRate)
                           : pEnchant->amount[s] != 0 ? float(pEnchant->amount[s]) : GetPPMProcChance(WeaponSpeed, 1.0f);
                                                                                     // default to 1 PPM


            ApplySpellMod(spellInfo->Id, SPELLMOD_CHANCE_OF_SUCCESS, chance);

            if (roll_chance_f(chance) || HasCheatOption(PLAYER_CHEAT_ALWAYS_PROC))
            {
                uint32 charges = item->GetEnchantmentCharges(EnchantmentSlot(e_slot));

                // PMonsterSay("Casted spell %u with %u charges.", proc_spell_id, charges);
                if (spellInfo->IsPositiveSpell())
                    CastSpell(this, spellInfo->Id, true, item);
                else
                    CastSpell(Target, spellInfo->Id, true, item);

                if (charges > 1)
                    item->SetEnchantmentCharges(TEMP_ENCHANTMENT_SLOT, charges - 1);
                else if (charges == 1)
                {
                    ApplyEnchantment(item, TEMP_ENCHANTMENT_SLOT, false);
                    item->ClearEnchantment(TEMP_ENCHANTMENT_SLOT);
                }
            }
        }
    }
}

void Player::CastItemUseSpell(Item* item, SpellCastTargets const& targets)
{
    ItemPrototype const* proto = item->GetProto();

    // use triggered flag only for items with many spell casts and for not first cast
    int count = 0;

    // item spells casted at use
    for (const auto& spellData : proto->Spells)
    {
        // no spell
        if (!spellData.SpellId)
            continue;

        // wrong triggering type
        if (spellData.SpellTrigger != ITEM_SPELLTRIGGER_ON_USE && spellData.SpellTrigger != ITEM_SPELLTRIGGER_ON_NO_DELAY_USE)
            continue;

        SpellEntry const* spellInfo = sSpellMgr.GetSpellEntry(spellData.SpellId);
        if (!spellInfo)
        {
            sLog.outError("Player::CastItemUseSpell: Item (Entry: %u) in have wrong spell id %u, ignoring", proto->ItemId, spellData.SpellId);
            continue;
        }

        Spell* spell = new Spell(this, spellInfo, (count > 0));
        spell->SetCastItem(item);
        spell->prepare(targets);

        ++count;
    }
}

void Player::_RemoveAllItemMods()
{
    DEBUG_LOG("_RemoveAllItemMods start.");

    for (int i = 0; i < INVENTORY_SLOT_BAG_END; ++i)
    {
        if (m_items[i])
        {
            ItemPrototype const* proto = m_items[i]->GetProto();
            if (!proto)
                continue;

            // item set bonuses not dependent from item broken state
            if (proto->ItemSet)
                RemoveItemsSetItem(this, proto);

            if (m_items[i]->IsBroken())
                continue;

            ApplyItemEquipSpell(m_items[i], false);
            ApplyEnchantment(m_items[i], false);
        }
    }

    for (int i = 0; i < INVENTORY_SLOT_BAG_END; ++i)
    {
        if (m_items[i])
        {
            if (m_items[i]->IsBroken())
                continue;
            ItemPrototype const* proto = m_items[i]->GetProto();
            if (!proto)
                continue;

            uint32 attacktype = Player::GetAttackBySlot(i);
            if (attacktype < MAX_ATTACK)
                _ApplyWeaponDependentAuraMods(m_items[i], WeaponAttackType(attacktype), false);

            _ApplyItemBonuses(proto, i, false);

            if (i == EQUIPMENT_SLOT_RANGED)
                _ApplyAmmoBonuses();
        }
    }

    DEBUG_LOG("_RemoveAllItemMods complete.");
}

void Player::_ApplyAllItemMods()
{
    DEBUG_LOG("_ApplyAllItemMods start.");

    for (int i = 0; i < INVENTORY_SLOT_BAG_END; ++i)
    {
        if (m_items[i])
        {
            if (m_items[i]->IsBroken())
                continue;

            ItemPrototype const* proto = m_items[i]->GetProto();
            if (!proto)
                continue;

            uint32 attacktype = Player::GetAttackBySlot(i);
            if (attacktype < MAX_ATTACK)
                _ApplyWeaponDependentAuraMods(m_items[i], WeaponAttackType(attacktype), true);

            _ApplyItemBonuses(proto, i, true);

            if (i == EQUIPMENT_SLOT_RANGED)
                _ApplyAmmoBonuses();
        }
    }

    for (int i = 0; i < INVENTORY_SLOT_BAG_END; ++i)
    {
        if (m_items[i])
        {
            ItemPrototype const* proto = m_items[i]->GetProto();
            if (!proto)
                continue;

            // item set bonuses not dependent from item broken state
            if (proto->ItemSet)
                AddItemsSetItem(this, m_items[i]);

            if (m_items[i]->IsBroken())
                continue;

            ApplyItemEquipSpell(m_items[i], true);
            ApplyEnchantment(m_items[i], true);
        }
    }

    DEBUG_LOG("_ApplyAllItemMods complete.");
}

void Player::_ApplyAmmoBonuses()
{
    // check ammo
    uint32 ammo_id = GetUInt32Value(PLAYER_AMMO_ID);
    if (!ammo_id)
        return;

    float currentAmmoDPS;

    ItemPrototype const* ammo_proto = ObjectMgr::GetItemPrototype(ammo_id);
    if (!ammo_proto || ammo_proto->Class != ITEM_CLASS_PROJECTILE || !CheckAmmoCompatibility(ammo_proto))
        currentAmmoDPS = 0.0f;
    else
        currentAmmoDPS = (ammo_proto->Damage[0].DamageMin + ammo_proto->Damage[0].DamageMax) / 2.0f;

    if (currentAmmoDPS == GetAmmoDPS())
        return;

    m_ammoDPS = currentAmmoDPS;

    if (CanModifyStats())
        UpdateDamagePhysical(RANGED_ATTACK);
}

bool Player::CheckAmmoCompatibility(ItemPrototype const* ammo_proto) const
{
    if (!ammo_proto)
        return false;

    // check ranged weapon
    Item* weapon = GetWeaponForAttack(RANGED_ATTACK, true, false);
    if (!weapon)
        return false;

    ItemPrototype const* weapon_proto = weapon->GetProto();
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
void Player::RemovedInsignia(Player* looterPlr, Corpse* corpse)
{
    if (!GetBattleGroundId())
        return;

    // If not released spirit, do it !
    if (GetDeathState() != DEAD)
    {
        BuildPlayerRepop();
        ScheduleRepopAtGraveyard();
    }

    if (!corpse)
        corpse = GetCorpse();
    if (!corpse)
        return;

    WorldPacket data(SMSG_PLAYER_SKINNED,0);
    GetSession()->SendPacket(&data);

    sObjectAccessor.ConvertCorpseForPlayer(GetObjectGuid(), looterPlr);
}

void Player::SendLootRelease(ObjectGuid guid) const
{
    WorldPacket data(SMSG_LOOT_RELEASE_RESPONSE, (8 + 1));
    data << guid;
    data << uint8(1);
    SendDirectMessage(&data);
}

void Player::SendLoot(ObjectGuid guid, LootType loot_type, Player* pVictim)
{
    // Nostalrius : desactivation des loots / map
    if (Map* myMap = FindMap())
    {
        if (sObjectMgr.IsMapLootDisabled(myMap->GetId()))
        {
            SendLootRelease(guid);
            return;
        }
    }
    else
        return;

    if (ObjectGuid lootGuid = GetLootGuid())
        m_session->DoLootRelease(lootGuid);

    Loot* loot = 0;
    PermissionTypes permission = ALL_PERMISSION;

    DEBUG_LOG("Player::SendLoot");

    if (loot_type != LOOT_PICKPOCKETING)
        RemoveSpellsCausingAura(SPELL_AURA_MOD_STEALTH); // TODO: Utiliser AuraInterruptFlags ?

    switch (guid.GetHigh())
    {
        case HIGHGUID_GAMEOBJECT:
        {
            DEBUG_LOG("       IS_GAMEOBJECT_GUID(guid)");
            GameObject* go = GetMap()->GetGameObject(guid);

            // not check distance for GO in case owned GO (fishing bobber case, for example)
            // And permit out of range GO with no owner in case fishing hole
            if (!go || (loot_type != LOOT_FISHINGHOLE && ((loot_type != LOOT_FISHING && loot_type != LOOT_FISHING_FAIL) || go->GetOwnerGuid() != GetObjectGuid()) && !go->IsAtInteractDistance(this)))
            {
                SendLootRelease(guid);
                return;
            }
            // Allowed to loot chest ?
            if (GameObjectInfo const* goInfo = go->GetGOInfo())
                if (goInfo->type == GAMEOBJECT_TYPE_CHEST && goInfo->chest.level > (GetLevel() + 10))
                {
                    std::stringstream oss;
                    oss << "Level " << GetLevel() << " attempt to loot chest " << go->GetDBTableGUIDLow() << " (level " << goInfo->chest.level << ")";
                    GetSession()->ProcessAnticheatAction("PassiveAnticheat", oss.str().c_str(), CHEAT_ACTION_LOG | CHEAT_ACTION_REPORT_GMS);
                    SendLootRelease(guid);
                    return;
                }

            loot = &go->loot;

            // generate loot only if ready for open and spawned in world
            if (go->getLootState() == GO_READY && go->isSpawned())
            {
                uint32 lootid =  go->GetGOInfo()->GetLootId();
                // Entry 0 in fishing loot template used for store junk fish loot at fishing fail it junk allowed by config option
                // this is overwrite fishinghole loot for example
                if (loot_type == LOOT_FISHING_FAIL)
                    loot->FillLoot(0, LootTemplates_Fishing, this, true);
                else if (lootid)
                {
                    loot->clear();

                    Group* group = GetGroup();
                    bool groupRules = (group && go->GetGOInfo()->type == GAMEOBJECT_TYPE_CHEST && go->GetGOInfo()->chest.groupLootRules);

                    // check current RR player and get next if necessary
                    if (groupRules)
                    {
                        group->UpdateLooterGuid(go, true);
                        loot->SetTeam(group->GetTeam());
                    }

                    loot->FillLoot(lootid, LootTemplates_Gameobject, this, !groupRules, false);
                    if (go->GetInstanceId())
                        go->GetMap()->BindToInstanceOrRaid(this, go->GetRespawnTimeEx(), false);

                    // get next RR player (for next loot)
                    if (groupRules)
                        group->UpdateLooterGuid(go);
                }
                else if (loot_type == LOOT_FISHING)
                    go->getFishLoot(loot, this);
                go->SetLootState(GO_ACTIVATED);
            }
            else if (go->getLootState() == GO_ACTIVATED)
                loot->FillNotNormalLootFor(this);
            break;
        }
        case HIGHGUID_ITEM:
        {
            Item* item = GetItemByGuid(guid);

            if (!item)
            {
                SendLootRelease(guid);
                return;
            }

            permission = OWNER_PERMISSION;

            loot = &item->loot;

            if (!item->HasGeneratedLoot())
            {
                if (item->HasGeneratedLootSecondary()) // temporary check, merge conditions later
                {
                    sLog.outError("%s attempted to regenerate %s at map %u, zone %u, area %u - grouped? %s",
                        GetGuidStr().c_str(), item->GetGuidStr().c_str(), GetMap()->GetId(), GetZoneId(), GetAreaId(), GetGroup()? "yes" : "no");
                    GetSession()->ProcessAnticheatAction("PassiveAnticheat", "Player::SendLoot: attempted to regenerate container loot", CHEAT_ACTION_LOG | CHEAT_ACTION_REPORT_GMS);
                    SendLootRelease(guid);
                    return;
                }

                item->loot.clear();

                switch (loot_type)
                {
                    case LOOT_DISENCHANTING:
                        loot->FillLoot(item->GetProto()->DisenchantID, LootTemplates_Disenchant, this, true);
                        item->SetLootState(ITEM_LOOT_TEMPORARY);
                        break;
                    default:
                        loot->FillLoot(item->GetEntry(), LootTemplates_Item, this, true, item->GetProto()->MaxMoneyLoot == 0);
                        loot->generateMoneyLoot(item->GetProto()->MinMoneyLoot, item->GetProto()->MaxMoneyLoot);
                        item->SetLootState(ITEM_LOOT_CHANGED);
                        item->SetGeneratedLoot(true);
                        break;
                }
            }
            break;
        }
        case HIGHGUID_CORPSE:                               // remove insignia
        {
            Corpse* bones = GetMap()->GetCorpse(guid);

            if (!bones || !((loot_type == LOOT_CORPSE) || (loot_type == LOOT_INSIGNIA)))
            {
                SendLootRelease(guid);
                return;
            }
            loot = &bones->loot;

            if (!bones->lootForBody)
            {
                bones->lootForBody = true;
                // uint32 pLevel = bones->loot.gold;
                bones->loot.clear();
                // It may need a better formula
                // Now it works like this: lvl10: ~6copper, lvl70: ~9silver
                if (pVictim != nullptr)
                {
                    uint32 level = pVictim->GetLevel();
                    bones->loot.gold = (uint32)(urand(50, 150) * 0.016f * pow(((float)level) / 5.76f, 2.5f) * sWorld.getConfig(CONFIG_FLOAT_RATE_DROP_MONEY));
                    bones->loot.m_personal = true; // Everyone can loot the corpse
                    if (BattleGround* bg = GetBattleGround())
                    {
                        if (bg->GetTypeID() == BATTLEGROUND_AV)
                        {
                            uint8 race = pVictim->GetRace();
                            uint32 rank = pVictim->GetHonorMgr().GetHighestRank().visualRank;
                            uint32 raceItem = 0;
                            uint32 rankItem = 0;
                            uint32 questItem = 0;
                            switch (race)
                            {
                            case RACE_HUMAN:
                                raceItem = 18144;
                                questItem = 17306;
                                break;
                            case RACE_DWARF:
                                raceItem = 18206;
                                questItem = 17306;
                                break;
                            case RACE_NIGHTELF:
                                raceItem = 18142;
                                questItem = 17306;
                                break;
                            case RACE_GNOME:
                                raceItem = 18143;
                                questItem = 17306;
                                break;
                            case RACE_ORC:
                                raceItem = 18207;
                                questItem = 17423;
                                break;
                            case RACE_UNDEAD:
                                raceItem = 18147;
                                questItem = 17423;
                                break;
                            case RACE_TAUREN:
                                raceItem = 18145;
                                questItem = 17423;
                                break;
                            case RACE_TROLL:
                                raceItem = 18146;
                                questItem = 17423;
                                break;
                            }
                            if (rank < 6)
                                if (pVictim->GetTeam() == ALLIANCE)
                                    rankItem = 17326;
                                else
                                    rankItem = 17502;
                            else if (rank < 10)
                                if (pVictim->GetTeam() == ALLIANCE)
                                    rankItem = 17327;
                                else
                                    rankItem = 17503;
                            else if (pVictim->GetTeam() == ALLIANCE)
                                rankItem = 17328;
                            else
                                rankItem = 17504;

                            if (raceItem > 0)
                            {
                                LootStoreItem storeitem = LootStoreItem(raceItem, 100, 0, 0, 1, 1);
                                bones->loot.AddItem(storeitem);
                            }
                            if (questItem > 0)
                            {
                                LootStoreItem storeitem = LootStoreItem(questItem, 100, 0, 0, 1, 1);
                                bones->loot.AddItem(storeitem);
                            }
                            if (rankItem > 0)
                            {
                                LootStoreItem storeitem = LootStoreItem(rankItem, 75, 0, 0, 0, 1);
                                bones->loot.AddItem(storeitem);
                            }

                            LootStoreItem storeitem = LootStoreItem(17422, 75, 0, 0, 0, 20);
                            bones->loot.AddItem(storeitem);
                        }
                    }
                }
            }

            permission = ALL_PERMISSION; // Everyone can loot in AV.
            bones->SetFlag(CORPSE_FIELD_DYNAMIC_FLAGS, CORPSE_DYNFLAG_LOOTABLE);
            bones->ForceValuesUpdateAtIndex(CORPSE_DYNFLAG_LOOTABLE);
            break;
        }
        case HIGHGUID_UNIT:
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

            if (creature->AI() && !creature->AI()->CanBeLooted())
            {
                SendLootRelease(guid);
                return;
            }

            loot = &creature->loot;

            if (loot_type == LOOT_PICKPOCKETING)
            {

                uint32 lootid = creature->GetCreatureInfo()->pickpocket_loot_id;

                if (!creature->lootForPickPocketed)
                {
                    loot->clear();
                    // Fill loot for first time
                    if (lootid)
                        loot->FillLoot(lootid, LootTemplates_Pickpocketing, this, false);

                    // Generate extra money for pick pocket loot
                    uint32 const a = urand(0, creature->GetLevel() / 2);
                    uint32 const b = urand(0, GetLevel() / 2);
                    loot->gold += uint32(10 * (a + b) * sWorld.getConfig(CONFIG_FLOAT_RATE_DROP_MONEY));

                    creature->lootForPickPocketed = true;
                }
                else if (loot->empty() || !loot->IsOriginalLooter(GetObjectGuid()))
                {
                    // If not original pickpocketer or empty
                    // Clear loot and generate only q items
                    loot->clear();

                    if (lootid)
                        loot->FillLoot(lootid, LootTemplates_Pickpocketing, this, false);

                    loot->leaveOnlyQuestItems();
                }

                permission = OWNER_PERMISSION;

                if (creature->GetInstanceId())
                    creature->GetMap()->BindToInstanceOrRaid(this, creature->GetRespawnTimeEx(), false);
            }
            else
            {
                // the player whose group may loot the corpse
                Player* recipient = creature->GetLootRecipient();
                if (!recipient)
                    return;

                if (creature->lootForPickPocketed)
                {
                    creature->lootForPickPocketed = false;
                    loot->clear();
                }

                if (!creature->lootForBody)
                {
                    creature->lootForBody = true;

                    if (Group* group = creature->GetGroupLootRecipient())
                    {
                        //group->UpdateLooterGuid(creature,true);

                        switch (group->GetLootMethod())
                        {
                            case GROUP_LOOT:
                                // GroupLoot delete items over threshold (threshold even not implemented), and roll them. Items with quality<threshold, round robin
                                group->GroupLoot(creature, loot);
                                break;
                            case NEED_BEFORE_GREED:
                                group->NeedBeforeGreed(creature, loot);
                                break;
                            case MASTER_LOOT:
                                group->MasterLoot(creature, loot);
                                break;
                            default:
                                break;
                        }
                    }
                    else if (Group* group = recipient->GetGroup())
                    {
                        if (group->isBGGroup() && group->GetLootMethod() == GROUP_LOOT)
                            group->GroupLoot(creature, loot);
                    }
                }

                // possible only if creature->lootForBody && loot->empty() at spell cast check
                if (loot_type == LOOT_SKINNING)
                {
                    if (!creature->lootForSkin)
                    {
                        creature->lootForSkin = true;
                        loot->clear();
                        loot->FillLoot(creature->GetCreatureInfo()->skinning_loot_id, LootTemplates_Skinning, this, false);

                        // let reopen skinning loot if will closed.
                        if (!loot->empty())
                            creature->SetUInt32Value(UNIT_DYNAMIC_FLAGS, UNIT_DYNFLAG_LOOTABLE);

                        permission = OWNER_PERMISSION;
                    }
                    if (creature->GetInstanceId())
                        creature->GetMap()->BindToInstanceOrRaid(this, creature->GetRespawnTimeEx(), false);
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
                                    permission = MASTER_PERMISSION;
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
            break;
        }
        default:
        {
            sLog.outError("%s is unsupported for looting.", guid.GetString().c_str());
            return;
        }
    }

    SetLootGuid(guid);
    ALL_SESSION_SCRIPTS(GetSession(), OnLoot(guid, loot_type));

    // need know for proper finish item loots (internal pre-switch loot type set in different from 3.x code version)
    // in fact this meaning that it send same loot types for interesting cases like 3.x version code (skip pre-3.x client loot type limitaitons)
    loot->loot_type = loot_type;

    // LOOT_SKINNING, LOOT_PROSPECTING, LOOT_INSIGNIA and LOOT_FISHINGHOLE unsupported by client
    switch (loot_type)
    {
        case LOOT_SKINNING:
            loot_type = LOOT_PICKPOCKETING;
            break;
        case LOOT_INSIGNIA:
            loot_type = LOOT_PICKPOCKETING;
            break;
        case LOOT_FISHING_FAIL:
            loot_type = LOOT_FISHING;
            break;
        case LOOT_FISHINGHOLE:
            loot_type = LOOT_FISHING;
            break;
        default:
            break;
    }

    WorldPacket data(SMSG_LOOT_RESPONSE, (9 + 50));         // we guess size
    data << ObjectGuid(guid);
    data << uint8(loot_type);
    data << LootView(*loot, this, permission);
    SendDirectMessage(&data);

    // add 'this' player as one of the players that are looting 'loot'
    if (permission != NONE_PERMISSION)
        loot->AddLooter(GetObjectGuid());

    if (loot_type == LOOT_CORPSE && !guid.IsItem())
        SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_LOOTING);
}

void Player::SendNotifyLootMoneyRemoved() const
{
    WorldPacket data(SMSG_LOOT_CLEAR_MONEY, 0);
    GetSession()->SendPacket(&data);
}

void Player::SendNotifyLootItemRemoved(uint8 lootSlot) const
{
    WorldPacket data(SMSG_LOOT_REMOVED, 1);
    data << uint8(lootSlot);
    GetSession()->SendPacket(&data);
}

void Player::SendUpdateWorldState(uint32 Field, uint32 Value) const
{
    WorldPacket data(SMSG_UPDATE_WORLD_STATE, 8);
    data << Field;
    data << Value;
    GetSession()->SendPacket(&data);
}

// TODO: Determine what these values mean, if anything.
static WorldStatePair def_world_states[] =
{
    { 0x07AE, 0x01 },
    { 0x0532, 0x01 },
    { 0x0531, 0x00 },
    { 0x052E, 0x00 },
    { 0x06F9, 0x00 },
    { 0x06F3, 0x00 },
    { 0x06F1, 0x00 },
    { 0x06EE, 0x00 },
    { 0x06ED, 0x00 },
    { 0x0571, 0x00 },
    { 0x0570, 0x00 },
    { 0x0567, 0x01 },
    { 0x0566, 0x01 },
    { 0x0550, 0x01 },
    { 0x0544, 0x00 },
    { 0x0536, 0x00 },
    { 0x0535, 0x01 },
    { 0x03C6, 0x00 },
    { 0x03C4, 0x00 },
    { 0x03C2, 0x00 },
    { 0x07A8, 0x00 },
    { 0x07A3, 0x270F },
    { 0x0574, 0x00 },
    { 0x0573, 0x00 },
    { 0x0572, 0x00 },
    { 0x056F, 0x00 },
    { 0x056E, 0x00 },
    { 0x056D, 0x00 },
    { 0x056C, 0x00 },
    { 0x056B, 0x00 },
    { 0x056A, 0x01 },
    { 0x0569, 0x01 },
    { 0x0568, 0x01 },
    { 0x0565, 0x00 },
    { 0x0564, 0x00 },
    { 0x0563, 0x00 },
    { 0x0562, 0x00 },
    { 0x0561, 0x00 },
    { 0x0560, 0x00 },
    { 0x055F, 0x00 },
    { 0x055E, 0x00 },
    { 0x055D, 0x00 },
    { 0x055C, 0x00 },
    { 0x055B, 0x00 },
    { 0x055A, 0x00 },
    { 0x0559, 0x00 },
    { 0x0558, 0x00 },
    { 0x0557, 0x00 },
    { 0x0556, 0x00 },
    { 0x0555, 0x00 },
    { 0x0554, 0x01 },
    { 0x0553, 0x01 },
    { 0x0552, 0x01 },
    { 0x0551, 0x01 },
    { 0x054F, 0x00 },
    { 0x054E, 0x00 },
    { 0x054D, 0x01 },
    { 0x054C, 0x00 },
    { 0x054B, 0x00 },
    { 0x0545, 0x00 },
    { 0x0543, 0x01 },
    { 0x0542, 0x00 },
    { 0x0540, 0x00 },
    { 0x053F, 0x00 },
    { 0x053E, 0x00 },
    { 0x053D, 0x00 },
    { 0x053C, 0x00 },
    { 0x053B, 0x00 },
    { 0x053A, 0x01 },
    { 0x0539, 0x00 },
    { 0x0538, 0x00 },
    { 0x0537, 0x00 },
    { 0x0534, 0x00 },
    { 0x0533, 0x00 },
    { 0x0530, 0x00 },
    { 0x052F, 0x00 },
    { 0x052D, 0x01 },
    { 0x0516, 0x01 },
    { 0x0515, 0x00 },
    { 0x03B6, 0x00 },
    { 0x0745, 0x02 },
    { 0x0736, 0x01 },
    { 0x0735, 0x01 },
    { 0x0734, 0x01 },
    { 0x0733, 0x01 },
    { 0x0732, 0x01 },
    { 0x0702, 0x00 },
    { 0x0701, 0x00 },
    { 0x0700, 0x00 },
    { 0x06FE, 0x00 },
    { 0x06FD, 0x00 },
    { 0x06FC, 0x00 },
    { 0x06FB, 0x00 },
    { 0x06F8, 0x00 },
    { 0x06F7, 0x00 },
    { 0x06F6, 0x00 },
    { 0x06F4, 0x7D0 },
    { 0x06F2, 0x00 },
    { 0x06F0, 0x00 },
    { 0x06EF, 0x00 },
    { 0x06EC, 0x00 },
    { 0x06EA, 0x00 },
    { 0x06E9, 0x00 },
    { 0x06E8, 0x00 },
    { 0x06E7, 0x00 },
    { 0x0518, 0x00 },
    { 0x0517, 0x00 },
    { 0x0703, 0x00 },
    { 0x0,    0x0 } // terminator
};



void Player::SendInitWorldStates(uint32 zoneid) const
{
    uint32 mapid = GetMapId();

    DEBUG_LOG("Sending SMSG_INIT_WORLD_STATES to Map:%u, Zone: %u", mapid, zoneid);

    uint32 count = 1; // count of world states in packet, 1 extra for the terminator

    WorldPacket data(SMSG_INIT_WORLD_STATES, (4 + 4 + 2 + 6));
    data << uint32(mapid);                              // mapid
    data << uint32(zoneid);                             // zone id
    size_t count_pos = data.wpos();
    data << uint16(0);                                  // count of uint32 blocks, placeholder

    // Scourge Invasion - Patch 1.11
    if (sGameEventMgr.IsActiveEvent(GAME_EVENT_SCOURGE_INVASION))
    {
        int VICTORIES = sObjectMgr.GetSavedVariable(VARIABLE_SI_ATTACK_COUNT);
        int REMAINING_AZSHARA = sObjectMgr.GetSavedVariable(VARIABLE_SI_AZSHARA_REMAINING);
        int REMAINING_BLASTED_LANDS = sObjectMgr.GetSavedVariable(VARIABLE_SI_BLASTED_LANDS_REMAINING);
        int REMAINING_BURNING_STEPPES = sObjectMgr.GetSavedVariable(VARIABLE_SI_BURNING_STEPPES_REMAINING);
        int REMAINING_EASTERN_PLAGUELANDS = sObjectMgr.GetSavedVariable(VARIABLE_SI_EASTERN_PLAGUELANDS_REMAINING);
        int REMAINING_TANARIS = sObjectMgr.GetSavedVariable(VARIABLE_SI_TANARIS_REMAINING);
        int REMAINING_WINTERSPRING = sObjectMgr.GetSavedVariable(VARIABLE_SI_WINTERSPRING_REMAINING);

        data << uint32(WORLDSTATE_AZSHARA)              << uint32(REMAINING_AZSHARA > 0 ? 1 : 0);
        data << uint32(WORLDSTATE_BLASTED_LANDS)        << uint32(REMAINING_BLASTED_LANDS > 0 ? 1 : 0);
        data << uint32(WORLDSTATE_BURNING_STEPPES)      << uint32(REMAINING_BURNING_STEPPES > 0 ? 1 : 0);
        data << uint32(WORLDSTATE_EASTERN_PLAGUELANDS)  << uint32(REMAINING_EASTERN_PLAGUELANDS > 0 ? 1 : 0);
        data << uint32(WORLDSTATE_TANARIS)              << uint32(REMAINING_TANARIS > 0 ? 1 : 0);
        data << uint32(WORLDSTATE_WINTERSPRING)         << uint32(REMAINING_WINTERSPRING > 0 ? 1 : 0);

        // Battles & remaining necropolisses
        data << uint32(WORLDSTATE_SI_BATTLES_WON) << uint32(VICTORIES);
        data << uint32(WORLDSTATE_SI_AZSHARA_REMAINING) << uint32(REMAINING_AZSHARA);
        data << uint32(WORLDSTATE_SI_BLASTED_LANDS_REMAINING) << uint32(REMAINING_BLASTED_LANDS);
        data << uint32(WORLDSTATE_SI_BURNING_STEPPES_REMAINING) << uint32(REMAINING_BURNING_STEPPES);
        data << uint32(WORLDSTATE_SI_EASTERN_PLAGUELANDS) << uint32(REMAINING_EASTERN_PLAGUELANDS);
        data << uint32(WORLDSTATE_SI_TANARIS) << uint32(REMAINING_TANARIS);
        data << uint32(WORLDSTATE_SI_WINTERSPRING) << uint32(REMAINING_WINTERSPRING);

        count += 13;
    }

    for (WorldStatePair const* itr = def_world_states; itr->state; ++itr)
    {
        data << uint32(itr->state);
        data << uint32(itr->value);
        ++count;
    }

    if (ZoneScript* zoneScript = GetZoneScript())
        count += zoneScript->FillInitialWorldStates(data);
    switch (zoneid)
    {
        case 2597:                                      // AV
        case 3277:                                      // WS
        case 3358:                                      // AB
            if (BattleGround* bg = GetBattleGround())
                bg->FillInitialWorldStates(data, count);
            break;
    }

    // Ahn'Qiraj War Effort
    if (sGameEventMgr.IsActiveEvent(EVENT_WAR_EFFORT))
    {
        count += BuildWarEffortWorldStates(data);
    }

    data << uint32(0) << uint32(0);     // [-ZERO] Add terminator to prevent repeating audio bug.
    data.put<uint16>(count_pos, count); // set actual world state amount
    GetSession()->SendPacket(&data);
}

uint32 Player::GetXPRestBonus(uint32 xp)
{
    uint32 rested_bonus = (uint32)GetRestBonus();           // xp for each rested bonus

    if (rested_bonus > xp)                                  // max rested_bonus == xp or (r+x) = 200% xp
        rested_bonus = xp;

    SetRestBonus(GetRestBonus() - rested_bonus);

    DETAIL_LOG("Player gain %u xp (+ %u Rested Bonus). Rested points=%f", xp + rested_bonus, rested_bonus, GetRestBonus());
    return rested_bonus;
}

float Player::ComputeRest(time_t timePassed, bool offline /*= false*/, bool inRestPlace /*= false*/)
{
    // Every 8h in resting zone we gain a bubble
    // A bubble is 5% of the total xp so there is 20 bubbles
    // So we gain (total XP/20 every 8h) (8h = 288800 sec)
    // (TotalXP/20)/28800; simplified to (TotalXP/576000) per second
    // Client automatically double the value sent so we have to divide it by 2
    // So final formula (TotalXP/1152000)
    float bonus = timePassed * (GetUInt32Value(PLAYER_NEXT_LEVEL_XP) / 1152000.0f); // Get the gained rest xp for given second
    if (!offline)
        bonus *= sWorld.getConfig(CONFIG_FLOAT_RATE_REST_INGAME);                   // Apply the custom setting
    else
    {
        if (inRestPlace)
            bonus *= sWorld.getConfig(CONFIG_FLOAT_RATE_REST_OFFLINE_IN_TAVERN_OR_CITY);
        else
            bonus *= sWorld.getConfig(CONFIG_FLOAT_RATE_REST_OFFLINE_IN_WILDERNESS) / 4.0f; // bonus is reduced by 4 when not in rest place
    }
    return bonus;
}

void Player::SetBindPoint(ObjectGuid guid) const
{
    WorldPacket data(SMSG_BINDER_CONFIRM, 8);
    data << ObjectGuid(guid);
    GetSession()->SendPacket(&data);
}

void Player::SendTalentWipeConfirm(ObjectGuid guid) const
{
    WorldPacket data(MSG_TALENT_WIPE_CONFIRM, (8 + 4));
    data << ObjectGuid(guid);
    data << uint32(GetResetTalentsCost());
    GetSession()->SendPacket(&data);
}

void Player::SendPetSkillWipeConfirm() const
{
    Pet* pet = GetPet();
    if (!pet)
        return;
    WorldPacket data(SMSG_PET_UNLEARN_CONFIRM, (8 + 4));
    data << ObjectGuid(pet->GetObjectGuid());
    data << uint32(pet->GetResetTalentsCost());
    GetSession()->SendPacket(&data);
}

/*********************************************************/
/***                    STORAGE SYSTEM                 ***/
/*********************************************************/

void Player::SetVirtualItemSlot(uint8 i, Item* item)
{
    MANGOS_ASSERT(i < 3);
    if (i < 2 && item)
    {
        if (!item->GetEnchantmentId(TEMP_ENCHANTMENT_SLOT))
            return;
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
        {
            SetVirtualItemSlot(0, GetWeaponForAttack(BASE_ATTACK, true, true));
            SetVirtualItemSlot(1, GetWeaponForAttack(OFF_ATTACK, true, true));
            SetVirtualItemSlot(2, nullptr);
        };
        break;
        case SHEATH_STATE_RANGED:                           // prepared ranged weapon
            SetVirtualItemSlot(0, nullptr);
            SetVirtualItemSlot(1, nullptr);
            SetVirtualItemSlot(2, GetWeaponForAttack(RANGED_ATTACK, true, true));
            break;
        default:
            SetVirtualItemSlot(0, nullptr);
            SetVirtualItemSlot(1, nullptr);
            SetVirtualItemSlot(2, nullptr);
            break;
    }
    Unit::SetSheath(sheathed);                              // this must visualize Sheath changing for other players...
}

uint8 Player::FindEquipSlot(ItemPrototype const* proto, uint32 slot, bool swap) const
{
    uint8 slots[4];
    proto->GetAllowedEquipSlots(slots, GetClass(), CanDualWield());

    if (slot != NULL_SLOT)
    {
        if (swap || !GetItemByPos(INVENTORY_SLOT_BAG_0, slot))
        {
            for (uint8 i : slots)
            {
                if (i == slot)
                    return slot;
            }
        }
    }
    else
    {
        // search free slot at first
        for (uint8 slot : slots)
        {
            if (slot != NULL_SLOT && !GetItemByPos(INVENTORY_SLOT_BAG_0, slot))
            {
                // in case 2hand equipped weapon offhand slot empty but not free
                if (slot != EQUIPMENT_SLOT_OFFHAND || !IsTwoHandUsed())
                    return slot;
            }
        }

        // if not found free and can swap return first appropriate from used
        for (uint8 slot : slots)
        {
            if (slot != NULL_SLOT && swap)
                return slot;
        }
    }

    // no free position
    return NULL_SLOT;
}

InventoryResult Player::CanUnequipItems(uint32 item, uint32 count) const
{
    Item* pItem;
    uint32 tempcount = 0;

    InventoryResult res = EQUIP_ERR_OK;

    for (int i = EQUIPMENT_SLOT_START; i < INVENTORY_SLOT_BAG_END; ++i)
    {
        pItem = GetItemByPos(INVENTORY_SLOT_BAG_0, i);
        if (pItem && pItem->GetEntry() == item)
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
    }
    for (int i = INVENTORY_SLOT_ITEM_START; i < INVENTORY_SLOT_ITEM_END; ++i)
    {
        pItem = GetItemByPos(INVENTORY_SLOT_BAG_0, i);
        if (pItem && pItem->GetEntry() == item)
        {
            tempcount += pItem->GetCount();
            if (tempcount >= count)
                return EQUIP_ERR_OK;
        }
    }
    for (int i = KEYRING_SLOT_START; i < KEYRING_SLOT_END; ++i)
    {
        pItem = GetItemByPos(INVENTORY_SLOT_BAG_0, i);
        if (pItem && pItem->GetEntry() == item)
        {
            tempcount += pItem->GetCount();
            if (tempcount >= count)
                return EQUIP_ERR_OK;
        }
    }
    
    for (int i = INVENTORY_SLOT_BAG_START; i < INVENTORY_SLOT_BAG_END; ++i)
    {
        if (Bag* pBag = (Bag*)GetItemByPos(INVENTORY_SLOT_BAG_0, i))
        {
            for (uint32 j = 0; j < pBag->GetBagSize(); ++j)
            {
                pItem = GetItemByPos(i, j);
                if (pItem && pItem->GetEntry() == item)
                {
                    tempcount += pItem->GetCount();
                    if (tempcount >= count)
                        return EQUIP_ERR_OK;
                }
            }
        }
    }

    // not found req. item count and have unequippable items
    return res;
}

uint32 Player::GetItemCount(uint32 item, bool inBankAlso, Item* skipItem) const
{
    uint32 count = 0;
    for (int i = EQUIPMENT_SLOT_START; i < INVENTORY_SLOT_ITEM_END; ++i)
    {
        Item* pItem = GetItemByPos(INVENTORY_SLOT_BAG_0, i);
        if (pItem && pItem != skipItem &&  pItem->GetEntry() == item)
            count += pItem->GetCount();
    }
    for (int i = KEYRING_SLOT_START; i < KEYRING_SLOT_END; ++i)
    {
        Item* pItem = GetItemByPos(INVENTORY_SLOT_BAG_0, i);
        if (pItem && pItem != skipItem && pItem->GetEntry() == item)
            count += pItem->GetCount();
    }
    for (int i = INVENTORY_SLOT_BAG_START; i < INVENTORY_SLOT_BAG_END; ++i)
    {
        Bag* pBag = (Bag*)GetItemByPos(INVENTORY_SLOT_BAG_0, i);
        if (pBag)
            count += pBag->GetItemCount(item, skipItem);
    }

    if (inBankAlso)
    {
        for (int i = BANK_SLOT_ITEM_START; i < BANK_SLOT_BAG_END; ++i)
        {
            Item* pItem = GetItemByPos(INVENTORY_SLOT_BAG_0, i);
            if (pItem && pItem != skipItem && pItem->GetEntry() == item)
                count += pItem->GetCount();
        }
        for (int i = BANK_SLOT_BAG_START; i < BANK_SLOT_BAG_END; ++i)
        {
            Bag* pBag = (Bag*)GetItemByPos(INVENTORY_SLOT_BAG_0, i);
            if (pBag)
                count += pBag->GetItemCount(item, skipItem);
        }
    }

    return count;
}

Item* Player::GetItemByGuid(ObjectGuid guid) const
{
    for (int i = EQUIPMENT_SLOT_START; i < INVENTORY_SLOT_ITEM_END; ++i)
        if (Item* pItem = GetItemByPos(INVENTORY_SLOT_BAG_0, i))
            if (pItem->GetObjectGuid() == guid)
                return pItem;

    for (int i = KEYRING_SLOT_START; i < KEYRING_SLOT_END; ++i)
        if (Item* pItem = GetItemByPos(INVENTORY_SLOT_BAG_0, i))
            if (pItem->GetObjectGuid() == guid)
                return pItem;

    for (int i = INVENTORY_SLOT_BAG_START; i < INVENTORY_SLOT_BAG_END; ++i)
        if (Bag* pBag = (Bag*)GetItemByPos(INVENTORY_SLOT_BAG_0, i))
            for (uint32 j = 0; j < pBag->GetBagSize(); ++j)
                if (Item* pItem = pBag->GetItemByPos(j))
                    if (pItem->GetObjectGuid() == guid)
                        return pItem;

    for (int i = BANK_SLOT_ITEM_START; i < BANK_SLOT_ITEM_END; ++i)
        if (Item* pItem = GetItemByPos(INVENTORY_SLOT_BAG_0, i))
            if (pItem->GetObjectGuid() == guid)
                return pItem;

    for (int i = BANK_SLOT_BAG_START; i < BANK_SLOT_BAG_END; ++i)
        if (Bag* pBag = (Bag*)GetItemByPos(INVENTORY_SLOT_BAG_0, i))
            for (uint32 j = 0; j < pBag->GetBagSize(); ++j)
                if (Item* pItem = pBag->GetItemByPos(j))
                    if (pItem->GetObjectGuid() == guid)
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
    if (bag == INVENTORY_SLOT_BAG_0 && (slot < BANK_SLOT_BAG_END || (slot >= KEYRING_SLOT_START && slot < KEYRING_SLOT_END)))
        return m_items[slot];
    else if ((bag >= INVENTORY_SLOT_BAG_START && bag < INVENTORY_SLOT_BAG_END)
             || (bag >= BANK_SLOT_BAG_START && bag < BANK_SLOT_BAG_END))
    {
        Bag* pBag = (Bag*)GetItemByPos(INVENTORY_SLOT_BAG_0, bag);
        if (pBag)
            return pBag->GetItemByPos(slot);
    }
    return nullptr;
}

Item* Player::GetWeaponForAttack(WeaponAttackType attackType, bool nonbroken, bool useable) const
{
    uint8 slot;
    switch (attackType)
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
            return nullptr;
    }

    Item* item = GetItemByPos(INVENTORY_SLOT_BAG_0, slot);
    if (!item || item->GetProto()->Class != ITEM_CLASS_WEAPON)
        return nullptr;

    if (useable && !CanUseEquippedWeapon(attackType))
        return nullptr;

    if (nonbroken && item->IsBroken())
        return nullptr;

    return item;
}

uint32 Player::GetAttackBySlot(uint8 slot)
{
    switch (slot)
    {
        case EQUIPMENT_SLOT_MAINHAND:
            return BASE_ATTACK;
        case EQUIPMENT_SLOT_OFFHAND:
            return OFF_ATTACK;
        case EQUIPMENT_SLOT_RANGED:
            return RANGED_ATTACK;
        default:
            return MAX_ATTACK;
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
    if (bag == INVENTORY_SLOT_BAG_0 && (slot >= KEYRING_SLOT_START && slot < KEYRING_SLOT_END))
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

    // bag/bank content slots
    if ((bag >= INVENTORY_SLOT_BAG_START && bag < INVENTORY_SLOT_BAG_END) ||
            (bag >= BANK_SLOT_BAG_START && bag < BANK_SLOT_BAG_END))
    {
        Bag* pBag = (Bag*)GetItemByPos(INVENTORY_SLOT_BAG_0, bag);
        if (!pBag)
            return false;

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
    for (int i = EQUIPMENT_SLOT_START; i < INVENTORY_SLOT_ITEM_END; ++i)
    {
        Item* pItem = GetItemByPos(INVENTORY_SLOT_BAG_0, i);
        if (pItem && pItem->GetEntry() == item && !pItem->IsInTrade())
        {
            tempcount += pItem->GetCount();
            if (tempcount >= count)
                return true;
        }
    }
    for (int i = KEYRING_SLOT_START; i < KEYRING_SLOT_END; ++i)
    {
        Item* pItem = GetItemByPos(INVENTORY_SLOT_BAG_0, i);
        if (pItem && pItem->GetEntry() == item && !pItem->IsInTrade())
        {
            tempcount += pItem->GetCount();
            if (tempcount >= count)
                return true;
        }
    }
    for (int i = INVENTORY_SLOT_BAG_START; i < INVENTORY_SLOT_BAG_END; ++i)
    {
        if (Bag* pBag = (Bag*)GetItemByPos(INVENTORY_SLOT_BAG_0, i))
        {
            for (uint32 j = 0; j < pBag->GetBagSize(); ++j)
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
        for (int i = BANK_SLOT_ITEM_START; i < BANK_SLOT_BAG_END; ++i)
        {
            Item* pItem = GetItemByPos(INVENTORY_SLOT_BAG_0, i);
            if (pItem && pItem->GetEntry() == item && !pItem->IsInTrade())
            {
                tempcount += pItem->GetCount();
                if (tempcount >= count)
                    return true;
            }
        }
        for (int i = BANK_SLOT_BAG_START; i < BANK_SLOT_BAG_END; ++i)
        {
            if (Bag* pBag = (Bag*)GetItemByPos(INVENTORY_SLOT_BAG_0, i))
            {
                for (uint32 j = 0; j < pBag->GetBagSize(); ++j)
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

bool Player::HasItemWithIdEquipped(uint32 item, uint32 count, uint8 except_slot) const
{
    uint32 tempcount = 0;
    for (int i = EQUIPMENT_SLOT_START; i < EQUIPMENT_SLOT_END; ++i)
    {
        if (i == int(except_slot))
            continue;

        Item* pItem = GetItemByPos(INVENTORY_SLOT_BAG_0, i);
        if (pItem && pItem->GetEntry() == item)
        {
            tempcount += pItem->GetCount();
            if (tempcount >= count)
                return true;
        }
    }

    return false;
}

InventoryResult Player::_CanTakeMoreSimilarItems(uint32 entry, uint32 count, Item* pItem, uint32* no_space_count) const
{
    ItemPrototype const* pProto = ObjectMgr::GetItemPrototype(entry);
    if (!pProto)
    {
        if (no_space_count)
            *no_space_count = count;
        return EQUIP_ERR_CANT_CARRY_MORE_OF_THIS;
    }

    // no maximum
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


    return EQUIP_ERR_OK;
}

InventoryResult Player::_CanStoreItem_InSpecificSlot(uint8 bag, uint8 slot, ItemPosCountVec &dest, ItemPrototype const* pProto, uint32& count, bool swap, Item* pSrcItem) const
{
    Item* pItem2 = GetItemByPos(bag, slot);

    // ignore move item (this slot will be empty at move)
    if (pItem2 == pSrcItem)
        pItem2 = nullptr;

    // Fix dupe exploit (move non empty bag)
    if (pSrcItem && pSrcItem->IsBag() && !((Bag*)pSrcItem)->IsEmpty())
    {
        GetSession()->ProcessAnticheatAction("PassiveAnticheat", "_CanStoreItem_InSpecificSlot: moving non empty bag", CHEAT_ACTION_LOG);
        return EQUIP_ERR_CAN_ONLY_DO_WITH_EMPTY_BAGS;
    }

    uint32 need_space;

    // empty specific slot - check item fit to slot
    if (!pItem2 || swap)
    {
        if (bag == INVENTORY_SLOT_BAG_0)
        {
            // keyring case
            if (slot >= KEYRING_SLOT_START && slot < KEYRING_SLOT_START + GetMaxKeyringSize() && !(pProto->BagFamily == BAG_FAMILY_KEYS))
                return EQUIP_ERR_ITEM_DOESNT_GO_INTO_BAG;

            // prevent cheating
            if ((slot >= BUYBACK_SLOT_START && slot < BUYBACK_SLOT_END) || slot >= PLAYER_SLOT_END)
                return EQUIP_ERR_ITEM_DOESNT_GO_INTO_BAG;
        }
        else
        {
            Bag* pBag = (Bag*)GetItemByPos(INVENTORY_SLOT_BAG_0, bag);
            if (!pBag || pBag == pSrcItem)
            {
                sLog.outInfo("[DUPLIC] Alerte sur '%s', itemId %u, type 2.", GetName(), pProto->ItemId);
                return EQUIP_ERR_ITEM_DOESNT_GO_INTO_BAG;
            }

            ItemPrototype const* pBagProto = pBag->GetProto();
            if (!pBagProto)
                return EQUIP_ERR_ITEM_DOESNT_GO_INTO_BAG;

            if (slot >= pBagProto->ContainerSlots)
                return EQUIP_ERR_ITEM_DOESNT_GO_INTO_BAG;

            if (!ItemCanGoIntoBag(pProto, pBagProto))
                return EQUIP_ERR_ITEM_DOESNT_GO_INTO_BAG;
        }

        // non empty stack with space
        need_space = pProto->Stackable;
    }
    // non empty slot, check item type
    else
    {
        // can be merged at least partly
        InventoryResult res  = pItem2->CanBeMergedPartlyWith(pProto);
        if (res != EQUIP_ERR_OK)
            return res;

        need_space = pProto->Stackable - pItem2->GetCount();
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

InventoryResult Player::_CanStoreItem_InBag(uint8 bag, ItemPosCountVec &dest, ItemPrototype const* pProto, uint32& count, bool merge, bool non_specialized, Item* pSrcItem, uint8 skip_bag, uint8 skip_slot) const
{
    // skip specific bag already processed in first called _CanStoreItem_InBag
    if (bag == skip_bag)
        return EQUIP_ERR_ITEM_DOESNT_GO_INTO_BAG;

    // skip nonexistent bag or self targeted bag
    Bag* pBag = (Bag*)GetItemByPos(INVENTORY_SLOT_BAG_0, bag);
    if (!pBag || pBag == pSrcItem)
        return EQUIP_ERR_ITEM_DOESNT_GO_INTO_BAG;

    ItemPrototype const* pBagProto = pBag->GetProto();
    if (!pBagProto)
        return EQUIP_ERR_ITEM_DOESNT_GO_INTO_BAG;

    // Fix dupe exploit (move non empty bag)
    if (pSrcItem && pSrcItem->IsBag() && !((Bag*)pSrcItem)->IsEmpty())
    {
        GetSession()->ProcessAnticheatAction("PassiveAnticheat", "_CanStoreItem_InBag: moving non empty bag", CHEAT_ACTION_LOG | CHEAT_ACTION_REPORT_GMS);
        return EQUIP_ERR_CAN_ONLY_DO_WITH_EMPTY_BAGS;
    }

    // specialized bag mode or non-specilized
    if (non_specialized != (pBagProto->Class == ITEM_CLASS_CONTAINER && pBagProto->SubClass == ITEM_SUBCLASS_CONTAINER))
        return EQUIP_ERR_ITEM_DOESNT_GO_INTO_BAG;

    if (!ItemCanGoIntoBag(pProto, pBagProto))
        return EQUIP_ERR_ITEM_DOESNT_GO_INTO_BAG;

    for (uint32 j = 0; j < pBag->GetBagSize(); ++j)
    {
        // skip specific slot already processed in first called _CanStoreItem_InSpecificSlot
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

            // decrease at current stacksize
            need_space -= pItem2->GetCount();
        }

        if (need_space > count)
            need_space = count;

        ItemPosCount newPosition = ItemPosCount((bag << 8) | j, need_space);
        if (!newPosition.isContainedIn(dest))
        {
            dest.push_back(newPosition);
            count -= need_space;

            if (count == 0)
                return EQUIP_ERR_OK;
        }
    }
    return EQUIP_ERR_OK;
}

InventoryResult Player::_CanStoreItem_InInventorySlots(uint8 slot_begin, uint8 slot_end, ItemPosCountVec &dest, ItemPrototype const* pProto, uint32& count, bool merge, Item* pSrcItem, uint8 skip_bag, uint8 skip_slot) const
{
    // Fix dupe exploit (move non empty bag)
    if (pSrcItem && pSrcItem->IsBag() && !((Bag*)pSrcItem)->IsEmpty())
    {
        GetSession()->ProcessAnticheatAction("PassiveAnticheat", "_CanStoreItem_InSpecificSlot: moving non empty bag", CHEAT_ACTION_LOG);
        return EQUIP_ERR_CAN_ONLY_DO_WITH_EMPTY_BAGS;
    }
    for (uint32 j = slot_begin; j < slot_end; ++j)
    {
        // skip specific slot already processed in first called _CanStoreItem_InSpecificSlot
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

            if (count == 0)
                return EQUIP_ERR_OK;
        }
    }
    return EQUIP_ERR_OK;
}

#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_10_2
#define LAST_ITEM_SLOT_FIELD (PLAYER_FIELD_KEYRING_SLOT_1 + (MAX_KEYRING_SLOTS - 1) * 2)
#elif SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_7_1
#define LAST_ITEM_SLOT_FIELD (PLAYER_FIELD_VENDORBUYBACK_SLOT_1 + (BUYBACK_SLOT_END - BUYBACK_SLOT_START - 1) * 2)
#else
#define LAST_ITEM_SLOT_FIELD PLAYER_FIELD_VENDORBUYBACK_SLOT
#endif

InventoryResult Player::_CanStoreItem(uint8 bag, uint8 slot, ItemPosCountVec &dest, uint32 entry, uint32 count, Item* pItem, bool swap, uint32* no_space_count) const
{
    DEBUG_LOG("STORAGE: CanStoreItem bag = %u, slot = %u, item = %u, count = %u", bag, slot, entry, count);

    ItemPrototype const* pProto = ObjectMgr::GetItemPrototype(entry);
    if (!pProto)
    {
        if (no_space_count)
            *no_space_count = count;
        return swap ? EQUIP_ERR_ITEMS_CANT_BE_SWAPPED : EQUIP_ERR_ITEM_NOT_FOUND;
    }
    
    if (pItem)
    {
        // item used
        if (pItem->HasTemporaryLoot())
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
    InventoryResult res = _CanTakeMoreSimilarItems(entry, count, pItem, &no_similar_count);
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
        // Prevent storing item in wrong field. 
        if ((bag == INVENTORY_SLOT_BAG_0) && (PLAYER_FIELD_INV_SLOT_HEAD + (slot * 2) > LAST_ITEM_SLOT_FIELD))
            return EQUIP_ERR_ITEM_DOESNT_GO_TO_SLOT;

        res = _CanStoreItem_InSpecificSlot(bag, slot, dest, pProto, count, swap, pItem);
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
        if (pProto->Stackable > 1)
        {
            if (bag == INVENTORY_SLOT_BAG_0)               // inventory
            {
                res = _CanStoreItem_InInventorySlots(KEYRING_SLOT_START, KEYRING_SLOT_END, dest, pProto, count, true, pItem, bag, slot);
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

                res = _CanStoreItem_InInventorySlots(INVENTORY_SLOT_ITEM_START, INVENTORY_SLOT_ITEM_END, dest, pProto, count, true, pItem, bag, slot);
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
                res = _CanStoreItem_InBag(bag, dest, pProto, count, true, false, pItem, NULL_BAG, slot);
                if (res != EQUIP_ERR_OK)
                    res = _CanStoreItem_InBag(bag, dest, pProto, count, true, true, pItem, NULL_BAG, slot);

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
        if (bag == INVENTORY_SLOT_BAG_0)                    // inventory
        {
            // search free slot - keyring case
            if (pProto->BagFamily == BAG_FAMILY_KEYS)
            {
                uint32 keyringSize = GetMaxKeyringSize();
                res = _CanStoreItem_InInventorySlots(KEYRING_SLOT_START, KEYRING_SLOT_START + keyringSize, dest, pProto, count, false, pItem, bag, slot);
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

            res = _CanStoreItem_InInventorySlots(INVENTORY_SLOT_ITEM_START, INVENTORY_SLOT_ITEM_END, dest, pProto, count, false, pItem, bag, slot);
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
            res = _CanStoreItem_InBag(bag, dest, pProto, count, false, false, pItem, NULL_BAG, slot);
            if (res != EQUIP_ERR_OK)
                res = _CanStoreItem_InBag(bag, dest, pProto, count, false, true, pItem, NULL_BAG, slot);

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
    if (pProto->Stackable > 1)
    {
        res = _CanStoreItem_InInventorySlots(KEYRING_SLOT_START, KEYRING_SLOT_END, dest, pProto, count, true, pItem, bag, slot);
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

        res = _CanStoreItem_InInventorySlots(INVENTORY_SLOT_ITEM_START, INVENTORY_SLOT_ITEM_END, dest, pProto, count, true, pItem, bag, slot);
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
            for (int i = INVENTORY_SLOT_BAG_START; i < INVENTORY_SLOT_BAG_END; ++i)
            {
                res = _CanStoreItem_InBag(i, dest, pProto, count, true, false, pItem, bag, slot);
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

        for (int i = INVENTORY_SLOT_BAG_START; i < INVENTORY_SLOT_BAG_END; ++i)
        {
            res = _CanStoreItem_InBag(i, dest, pProto, count, true, true, pItem, bag, slot);
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
        if (pProto->BagFamily == BAG_FAMILY_KEYS)
        {
            uint32 keyringSize = GetMaxKeyringSize();
            res = _CanStoreItem_InInventorySlots(KEYRING_SLOT_START, KEYRING_SLOT_START + keyringSize, dest, pProto, count, false, pItem, bag, slot);
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

        for (int i = INVENTORY_SLOT_BAG_START; i < INVENTORY_SLOT_BAG_END; ++i)
        {
            res = _CanStoreItem_InBag(i, dest, pProto, count, false, false, pItem, bag, slot);
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

    // Normally it would be impossible to autostore not empty bags
    if (pItem && pItem->IsBag() && !((Bag*)pItem)->IsEmpty())
        return EQUIP_ERR_NONEMPTY_BAG_OVER_OTHER_BAG;

    // search free slot
    res = _CanStoreItem_InInventorySlots(INVENTORY_SLOT_ITEM_START, INVENTORY_SLOT_ITEM_END, dest, pProto, count, false, pItem, bag, slot);
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

    for (int i = INVENTORY_SLOT_BAG_START; i < INVENTORY_SLOT_BAG_END; ++i)
    {
        res = _CanStoreItem_InBag(i, dest, pProto, count, false, true, pItem, bag, slot);
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
InventoryResult Player::CanStoreItems(Item** pItems, int count) const
{
    Item* pItem2;

    // fill space table
    int inv_slot_items[INVENTORY_SLOT_ITEM_END - INVENTORY_SLOT_ITEM_START];
    int inv_bags[INVENTORY_SLOT_BAG_END - INVENTORY_SLOT_BAG_START][MAX_BAG_SIZE];
    int inv_keys[KEYRING_SLOT_END - KEYRING_SLOT_START];

    memset(inv_slot_items, 0, sizeof(int) * (INVENTORY_SLOT_ITEM_END - INVENTORY_SLOT_ITEM_START));
    memset(inv_bags, 0, sizeof(int) * (INVENTORY_SLOT_BAG_END - INVENTORY_SLOT_BAG_START)*MAX_BAG_SIZE);
    memset(inv_keys, 0, sizeof(int) * (KEYRING_SLOT_END - KEYRING_SLOT_START));

    for (int i = INVENTORY_SLOT_ITEM_START; i < INVENTORY_SLOT_ITEM_END; ++i)
    {
        pItem2 = GetItemByPos(INVENTORY_SLOT_BAG_0, i);

        if (pItem2 && !pItem2->IsInTrade())
            inv_slot_items[i - INVENTORY_SLOT_ITEM_START] = pItem2->GetCount();
    }

    for (int i = KEYRING_SLOT_START; i < KEYRING_SLOT_END; ++i)
    {
        pItem2 = GetItemByPos(INVENTORY_SLOT_BAG_0, i);

        if (pItem2 && !pItem2->IsInTrade())
            inv_keys[i - KEYRING_SLOT_START] = pItem2->GetCount();
    }

    for (int i = INVENTORY_SLOT_BAG_START; i < INVENTORY_SLOT_BAG_END; ++i)
    {
        if (Bag* pBag = (Bag*)GetItemByPos(INVENTORY_SLOT_BAG_0, i))
        {
            for (uint32 j = 0; j < pBag->GetBagSize(); ++j)
            {
                pItem2 = GetItemByPos(i, j);
                if (pItem2 && !pItem2->IsInTrade())
                    inv_bags[i - INVENTORY_SLOT_BAG_START][j] = pItem2->GetCount();
            }
        }
    }

    // check free space for all items
    for (int k = 0; k < count; ++k)
    {
        Item* pItem = pItems[k];

        // no item
        if (!pItem)  continue;

        // Fix dupe exploit (move non empty bag)
        if (pItem->IsBag() && !((Bag*)pItem)->IsEmpty())
        {
            GetSession()->ProcessAnticheatAction("PassiveAnticheat", "Player::CanStoreItems: can't store non empty bag", CHEAT_ACTION_LOG);
            return EQUIP_ERR_CAN_ONLY_DO_WITH_EMPTY_BAGS;
        }

        DEBUG_LOG("STORAGE: CanStoreItems %i. item = %u, count = %u", k + 1, pItem->GetEntry(), pItem->GetCount());
        ItemPrototype const* pProto = pItem->GetProto();

        // strange item
        if (!pProto)
            return EQUIP_ERR_ITEM_NOT_FOUND;

        // item used
        if (pItem->HasTemporaryLoot())
            return EQUIP_ERR_ALREADY_LOOTED;

        // item it 'bind'
        if (pItem->IsBindedNotWith(this))
            return EQUIP_ERR_DONT_OWN_THAT_ITEM;

        Bag* pBag;
        ItemPrototype const* pBagProto;

        // item is 'one item only'
        InventoryResult res = CanTakeMoreSimilarItems(pItem);
        if (res != EQUIP_ERR_OK)
            return res;

        // search stack for merge to
        if (pProto->Stackable > 1)
        {
            bool b_found = false;

            for (int t = KEYRING_SLOT_START; t < KEYRING_SLOT_END; ++t)
            {
                pItem2 = GetItemByPos(INVENTORY_SLOT_BAG_0, t);
                if (pItem2 && pItem2->CanBeMergedPartlyWith(pProto) == EQUIP_ERR_OK && inv_keys[t - KEYRING_SLOT_START] + pItem->GetCount() <= pProto->GetMaxStackSize())
                {
                    inv_keys[t - KEYRING_SLOT_START] += pItem->GetCount();
                    b_found = true;
                    break;
                }
            }
            if (b_found) continue;

            for (int t = INVENTORY_SLOT_ITEM_START; t < INVENTORY_SLOT_ITEM_END; ++t)
            {
                pItem2 = GetItemByPos(INVENTORY_SLOT_BAG_0, t);
                if (pItem2 && pItem2->CanBeMergedPartlyWith(pProto) == EQUIP_ERR_OK && inv_slot_items[t - INVENTORY_SLOT_ITEM_START] + pItem->GetCount() <= pProto->GetMaxStackSize())
                {
                    inv_slot_items[t - INVENTORY_SLOT_ITEM_START] += pItem->GetCount();
                    b_found = true;
                    break;
                }
            }
            if (b_found) continue;

            for (int t = INVENTORY_SLOT_BAG_START; !b_found && t < INVENTORY_SLOT_BAG_END; ++t)
            {
                pBag = (Bag*)GetItemByPos(INVENTORY_SLOT_BAG_0, t);
                if (pBag)
                {
                    for (uint32 j = 0; j < pBag->GetBagSize(); ++j)
                    {
                        pItem2 = GetItemByPos(t, j);
                        if (pItem2 && pItem2->CanBeMergedPartlyWith(pProto) == EQUIP_ERR_OK && inv_bags[t - INVENTORY_SLOT_BAG_START][j] + pItem->GetCount() <= pProto->GetMaxStackSize())
                        {
                            inv_bags[t - INVENTORY_SLOT_BAG_START][j] += pItem->GetCount();
                            b_found = true;
                            break;
                        }
                    }
                }
            }
            if (b_found) continue;
        }

        // special bag case
        if (pProto->BagFamily)
        {
            bool b_found = false;
            if (pProto->BagFamily == BAG_FAMILY_KEYS)
            {
                uint32 keyringSize = GetMaxKeyringSize();
                for (uint32 t = KEYRING_SLOT_START; t < KEYRING_SLOT_START + keyringSize; ++t)
                {
                    if (inv_keys[t - KEYRING_SLOT_START] == 0)
                    {
                        inv_keys[t - KEYRING_SLOT_START] = 1;
                        b_found = true;
                        break;
                    }
                }
            }

            if (b_found) continue;

            for (int t = INVENTORY_SLOT_BAG_START; !b_found && t < INVENTORY_SLOT_BAG_END; ++t)
            {
                pBag = (Bag*)GetItemByPos(INVENTORY_SLOT_BAG_0, t);
                if (pBag)
                {
                    pBagProto = pBag->GetProto();

                    // not plain container check
                    if (pBagProto && (pBagProto->Class != ITEM_CLASS_CONTAINER || pBagProto->SubClass != ITEM_SUBCLASS_CONTAINER) &&
                            ItemCanGoIntoBag(pProto, pBagProto))
                    {
                        for (uint32 j = 0; j < pBag->GetBagSize(); ++j)
                        {
                            if (inv_bags[t - INVENTORY_SLOT_BAG_START][j] == 0)
                            {
                                inv_bags[t - INVENTORY_SLOT_BAG_START][j] = 1;
                                b_found = true;
                                break;
                            }
                        }
                    }
                }
            }
            if (b_found) continue;
        }

        // search free slot
        bool b_found = false;
        for (int t = INVENTORY_SLOT_ITEM_START; t < INVENTORY_SLOT_ITEM_END; ++t)
        {
            if (inv_slot_items[t - INVENTORY_SLOT_ITEM_START] == 0)
            {
                inv_slot_items[t - INVENTORY_SLOT_ITEM_START] = 1;
                b_found = true;
                break;
            }
        }
        if (b_found) continue;

        // search free slot in bags
        for (int t = INVENTORY_SLOT_BAG_START; !b_found && t < INVENTORY_SLOT_BAG_END; ++t)
        {
            pBag = (Bag*)GetItemByPos(INVENTORY_SLOT_BAG_0, t);
            if (pBag)
            {
                pBagProto = pBag->GetProto();

                // special bag already checked
                if (pBagProto && (pBagProto->Class != ITEM_CLASS_CONTAINER || pBagProto->SubClass != ITEM_SUBCLASS_CONTAINER))
                    continue;

                for (uint32 j = 0; j < pBag->GetBagSize(); ++j)
                {
                    if (inv_bags[t - INVENTORY_SLOT_BAG_START][j] == 0)
                    {
                        inv_bags[t - INVENTORY_SLOT_BAG_START][j] = 1;
                        b_found = true;
                        break;
                    }
                }
            }
        }

        // no free slot found?
        if (!b_found)
            return EQUIP_ERR_INVENTORY_FULL;
    }

    return EQUIP_ERR_OK;
}

//////////////////////////////////////////////////////////////////////////
InventoryResult Player::CanEquipNewItem(uint8 slot, uint16& dest, uint32 item, bool swap) const
{
    dest = 0;
    Item* pItem = Item::CreateItem(item, 1, GetObjectGuid());
    if (pItem)
    {
        InventoryResult result = CanEquipItem(slot, dest, pItem, swap);
        delete pItem;
        return result;
    }

    return EQUIP_ERR_ITEM_NOT_FOUND;
}

InventoryResult Player::CanEquipItem(uint8 slot, uint16& dest, Item* pItem, bool swap, bool not_loading) const
{
    dest = 0;
    if (pItem)
    {
        DEBUG_LOG("STORAGE: CanEquipItem slot = %u, item = %u, count = %u", slot, pItem->GetEntry(), pItem->GetCount());
        ItemPrototype const* pProto = pItem->GetProto();
        if (pProto)
        {
            // item used
            if (pItem->HasTemporaryLoot())
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
                if (HasUnitState(UNIT_STAT_STUNNED | UNIT_STAT_PENDING_STUNNED))
                    return EQUIP_ERR_YOU_ARE_STUNNED;

                // do not allow equipping gear except weapons, offhands, projectiles, relics in
                // - combat
                if (!pProto->CanChangeEquipStateInCombat())
                {
                    if (IsInCombat())
                        return EQUIP_ERR_NOT_IN_COMBAT;
                }

                // prevent equip item in process logout
                if (GetSession()->isLogingOut())
                    return EQUIP_ERR_YOU_ARE_STUNNED;

                if (IsInCombat() && pProto->Class == ITEM_CLASS_WEAPON && m_weaponChangeTimer != 0)
                    return EQUIP_ERR_CANT_DO_RIGHT_NOW;         // maybe exist better err

                // Check is possibly not in vanilla.
                //if (IsNonMeleeSpellCasted(false, true, true))
                //    return EQUIP_ERR_CANT_DO_RIGHT_NOW;
            }

            uint8 eslot = FindEquipSlot(pProto, slot, swap);
            if (eslot == NULL_SLOT)
                return EQUIP_ERR_ITEM_CANT_BE_EQUIPPED;

            InventoryResult msg = CanUseItem(pItem , not_loading);
            if (msg != EQUIP_ERR_OK)
                return msg;
            if (!swap && GetItemByPos(INVENTORY_SLOT_BAG_0, eslot))
                return EQUIP_ERR_NO_EQUIPMENT_SLOT_AVAILABLE;

            // if swap ignore item (equipped also)
            if (InventoryResult res2 = CanEquipUniqueItem(pItem, swap ? eslot : NULL_SLOT))
                return res2;

            // check unique-equipped special item classes
            if (pProto->Class == ITEM_CLASS_QUIVER)
            {
                for (int i = INVENTORY_SLOT_BAG_START; i < INVENTORY_SLOT_BAG_END; ++i)
                {
                    if (Item* pBag = GetItemByPos(INVENTORY_SLOT_BAG_0, i))
                    {
                        if (pBag != pItem)
                        {
                            if (ItemPrototype const* pBagProto = pBag->GetProto())
                            {
                                if (pBagProto->Class == pProto->Class && (!swap || pBag->GetSlot() != eslot))
                                    return (pBagProto->SubClass == ITEM_SUBCLASS_AMMO_POUCH)
                                           ? EQUIP_ERR_CAN_EQUIP_ONLY1_AMMOPOUCH
                                           : EQUIP_ERR_CAN_EQUIP_ONLY1_QUIVER;
                            }
                        }
                    }
                }
            }

            uint32 type = pProto->InventoryType;

            if (eslot == EQUIPMENT_SLOT_OFFHAND)
            {
                if (type == INVTYPE_WEAPON || type == INVTYPE_WEAPONOFFHAND)
                {
                    if (!CanDualWield())
                        return EQUIP_ERR_CANT_DUAL_WIELD;
                }
                else if (type == INVTYPE_2HWEAPON)
                    return EQUIP_ERR_CANT_DUAL_WIELD;

                if (IsTwoHandUsed())
                    return EQUIP_ERR_CANT_EQUIP_WITH_TWOHANDED;
            }

            // equip two-hand weapon case (with possible unequip 2 items)
            if (type == INVTYPE_2HWEAPON)
            {
                if (eslot != EQUIPMENT_SLOT_MAINHAND)
                    return EQUIP_ERR_ITEM_CANT_BE_EQUIPPED;

                // offhand item must can be stored in inventory for offhand item and it also must be unequipped
                Item* offItem = GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND);
                ItemPosCountVec off_dest;
                if (offItem && (!not_loading ||
                                CanUnequipItem(uint16(INVENTORY_SLOT_BAG_0) << 8 | EQUIPMENT_SLOT_OFFHAND, false) !=  EQUIP_ERR_OK ||
                                CanStoreItem(NULL_BAG, NULL_SLOT, off_dest, offItem, false) !=  EQUIP_ERR_OK))
                    return swap ? EQUIP_ERR_ITEMS_CANT_BE_SWAPPED : EQUIP_ERR_INVENTORY_FULL;
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

    DEBUG_LOG("STORAGE: CanUnequipItem slot = %u, item = %u, count = %u", pos, pItem->GetEntry(), pItem->GetCount());

    ItemPrototype const* pProto = pItem->GetProto();
    if (!pProto)
        return EQUIP_ERR_ITEM_NOT_FOUND;

    // item used
    if (pItem->HasTemporaryLoot())
        return EQUIP_ERR_ALREADY_LOOTED;

    // do not allow unequipping gear except weapons, offhands, projectiles, relics in
    // - combat
    if (!pProto->CanChangeEquipStateInCombat())
    {
        if (IsInCombat())
            return EQUIP_ERR_NOT_IN_COMBAT;
    }

    // prevent unequip item in process logout
    if (GetSession()->isLogingOut())
        return EQUIP_ERR_YOU_ARE_STUNNED;

    if (!swap && pItem->IsBag() && !((Bag*)pItem)->IsEmpty())
        return EQUIP_ERR_CAN_ONLY_DO_WITH_EMPTY_BAGS;

    // Check is possibly not in vanilla.
    //if (IsNonMeleeSpellCasted(false, true, true))
    //    return EQUIP_ERR_CANT_DO_RIGHT_NOW;

    return EQUIP_ERR_OK;
}

InventoryResult Player::CanBankItem(uint8 bag, uint8 slot, ItemPosCountVec &dest, Item* pItem, bool swap, bool not_loading) const
{
    if (!pItem)
        return swap ? EQUIP_ERR_ITEMS_CANT_BE_SWAPPED : EQUIP_ERR_ITEM_NOT_FOUND;

    uint32 count = pItem->GetCount();

    DEBUG_LOG("STORAGE: CanBankItem bag = %u, slot = %u, item = %u, count = %u", bag, slot, pItem->GetEntry(), pItem->GetCount());
    ItemPrototype const* pProto = pItem->GetProto();
    if (!pProto)
        return swap ? EQUIP_ERR_ITEMS_CANT_BE_SWAPPED : EQUIP_ERR_ITEM_NOT_FOUND;

    // item used
    if (pItem->HasTemporaryLoot())
        return EQUIP_ERR_ALREADY_LOOTED;

    if (pItem->IsBindedNotWith(this))
        return EQUIP_ERR_DONT_OWN_THAT_ITEM;

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

        res = _CanStoreItem_InSpecificSlot(bag, slot, dest, pProto, count, swap, pItem);
        if (res != EQUIP_ERR_OK)
            return res;

        if (count == 0)
            return EQUIP_ERR_OK;
    }

    // not specific slot or have space for partly store only in specific slot

    // in specific bag
    if (bag != NULL_BAG)
    {
        if (pProto->InventoryType == INVTYPE_BAG)
        {
            Bag* pBag = (Bag*)pItem;
            if (pBag && !pBag->IsEmpty())
                return EQUIP_ERR_NONEMPTY_BAG_OVER_OTHER_BAG;
        }

        // search stack in bag for merge to
        if (pProto->Stackable > 1)
        {
            if (bag == INVENTORY_SLOT_BAG_0)
            {
                res = _CanStoreItem_InInventorySlots(BANK_SLOT_ITEM_START, BANK_SLOT_ITEM_END, dest, pProto, count, true, pItem, bag, slot);
                if (res != EQUIP_ERR_OK)
                    return res;

                if (count == 0)
                    return EQUIP_ERR_OK;
            }
            else
            {
                res = _CanStoreItem_InBag(bag, dest, pProto, count, true, false, pItem, NULL_BAG, slot);
                if (res != EQUIP_ERR_OK)
                    res = _CanStoreItem_InBag(bag, dest, pProto, count, true, true, pItem, NULL_BAG, slot);

                if (res != EQUIP_ERR_OK)
                    return res;

                if (count == 0)
                    return EQUIP_ERR_OK;
            }
        }

        // search free slot in bag
        if (bag == INVENTORY_SLOT_BAG_0)
        {
            res = _CanStoreItem_InInventorySlots(BANK_SLOT_ITEM_START, BANK_SLOT_ITEM_END, dest, pProto, count, false, pItem, bag, slot);
            if (res != EQUIP_ERR_OK)
                return res;

            if (count == 0)
                return EQUIP_ERR_OK;
        }
        else
        {
            res = _CanStoreItem_InBag(bag, dest, pProto, count, false, false, pItem, NULL_BAG, slot);
            if (res != EQUIP_ERR_OK)
                res = _CanStoreItem_InBag(bag, dest, pProto, count, false, true, pItem, NULL_BAG, slot);

            if (res != EQUIP_ERR_OK)
                return res;

            if (count == 0)
                return EQUIP_ERR_OK;
        }
    }

    // not specific bag or have space for partly store only in specific bag

    // search stack for merge to
    if (pProto->Stackable > 1)
    {
        // in slots
        res = _CanStoreItem_InInventorySlots(BANK_SLOT_ITEM_START, BANK_SLOT_ITEM_END, dest, pProto, count, true, pItem, bag, slot);
        if (res != EQUIP_ERR_OK)
            return res;

        if (count == 0)
            return EQUIP_ERR_OK;

        // in special bags
        if (pProto->BagFamily)
        {
            for (int i = BANK_SLOT_BAG_START; i < BANK_SLOT_BAG_END; ++i)
            {
                res = _CanStoreItem_InBag(i, dest, pProto, count, true, false, pItem, bag, slot);
                if (res != EQUIP_ERR_OK)
                    continue;

                if (count == 0)
                    return EQUIP_ERR_OK;
            }
        }

        for (int i = BANK_SLOT_BAG_START; i < BANK_SLOT_BAG_END; ++i)
        {
            res = _CanStoreItem_InBag(i, dest, pProto, count, true, true, pItem, bag, slot);
            if (res != EQUIP_ERR_OK)
                continue;

            if (count == 0)
                return EQUIP_ERR_OK;
        }
    }

    // search free place in special bag
    if (pProto->BagFamily)
    {
        for (int i = BANK_SLOT_BAG_START; i < BANK_SLOT_BAG_END; ++i)
        {
            res = _CanStoreItem_InBag(i, dest, pProto, count, false, false, pItem, bag, slot);
            if (res != EQUIP_ERR_OK)
                continue;

            if (count == 0)
                return EQUIP_ERR_OK;
        }
    }

    // search free space
    res = _CanStoreItem_InInventorySlots(BANK_SLOT_ITEM_START, BANK_SLOT_ITEM_END, dest, pProto, count, false, pItem, bag, slot);
    if (res != EQUIP_ERR_OK)
        return res;

    if (count == 0)
        return EQUIP_ERR_OK;

    for (int i = BANK_SLOT_BAG_START; i < BANK_SLOT_BAG_END; ++i)
    {
        res = _CanStoreItem_InBag(i, dest, pProto, count, false, true, pItem, bag, slot);
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
        DEBUG_LOG("STORAGE: CanUseItem item = %u", pItem->GetEntry());

        if (!IsAlive() && not_loading)
            return EQUIP_ERR_YOU_ARE_DEAD;

        //if (isStunned())
        //    return EQUIP_ERR_YOU_ARE_STUNNED;

        ItemPrototype const* pProto = pItem->GetProto();
        if (pProto)
        {
            if (pItem->IsBindedNotWith(this))
                return EQUIP_ERR_DONT_OWN_THAT_ITEM;

            InventoryResult msg = CanUseItem(pProto, not_loading);
            if (msg != EQUIP_ERR_OK)
                return msg;

            if (uint32 skill = pProto->GetProficiencySkill())
            {
                // Fist weapons use unarmed skill calculations, but we must query fist weapon skill presence to use this item
                if (pProto->SubClass == ITEM_SUBCLASS_WEAPON_FIST)
                    skill = SKILL_FIST_WEAPONS;
                if (!GetSkillValue(skill))
                    return EQUIP_ERR_NO_REQUIRED_PROFICIENCY;
            }

            if (pProto->RequiredReputationFaction && uint32(GetReputationRank(pProto->RequiredReputationFaction)) < pProto->RequiredReputationRank)
#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_6_1
                return EQUIP_ERR_CANT_EQUIP_REPUTATION;
#else
                return EQUIP_ERR_CANT_DO_RIGHT_NOW;
#endif

            return EQUIP_ERR_OK;
        }
    }
    return EQUIP_ERR_ITEM_NOT_FOUND;
}

InventoryResult Player::CanUseItem(ItemPrototype const* pProto, bool not_loading) const
{
    // Used by group, function NeedBeforeGreed, to know if a prototype can be used by a player

    if (pProto)
    {
        if ((pProto->AllowableClass & GetClassMask()) == 0 || (pProto->AllowableRace & GetRaceMask()) == 0)
            return EQUIP_ERR_YOU_CAN_NEVER_USE_THAT_ITEM;

        if (pProto->RequiredSkill != 0)
        {
            if (GetSkillValue(pProto->RequiredSkill) == 0)
                return EQUIP_ERR_NO_REQUIRED_PROFICIENCY;
            else if (GetSkillValue(pProto->RequiredSkill) < pProto->RequiredSkillRank)
                return EQUIP_ERR_CANT_EQUIP_SKILL;
        }

        if (pProto->RequiredSpell != 0 && !HasSpell(pProto->RequiredSpell))
            return EQUIP_ERR_NO_REQUIRED_PROFICIENCY;

        auto playerRank = (sWorld.getConfig(CONFIG_BOOL_ACCURATE_PVP_EQUIP_REQUIREMENTS) && sWorld.GetWowPatch() < WOW_PATCH_106) ? m_honorMgr.GetRank().rank : m_honorMgr.GetHighestRank().rank;

        if (not_loading && playerRank < (uint8)pProto->RequiredHonorRank)
            return EQUIP_ERR_CANT_EQUIP_RANK;

        if (GetLevel() < pProto->RequiredLevel)
            return EQUIP_ERR_CANT_EQUIP_LEVEL_I;

        return EQUIP_ERR_OK;
    }
    return EQUIP_ERR_ITEM_NOT_FOUND;
}

InventoryResult Player::CanUseAmmo(uint32 item) const
{
    DEBUG_LOG("STORAGE: CanUseAmmo item = %u", item);
    if (!IsAlive())
        return EQUIP_ERR_YOU_ARE_DEAD;
    //if (isStunned())
    //    return EQUIP_ERR_YOU_ARE_STUNNED;
    ItemPrototype const* pProto = ObjectMgr::GetItemPrototype(item);
    if (pProto)
    {
        if (pProto->InventoryType != INVTYPE_AMMO)
            return EQUIP_ERR_ONLY_AMMO_CAN_GO_HERE;

        InventoryResult msg = CanUseItem(pProto);
        if (msg != EQUIP_ERR_OK)
            return msg;

        /*if (GetReputationMgr().GetReputation() < pProto->RequiredReputation)
        return EQUIP_ERR_CANT_EQUIP_REPUTATION;
        */

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
    if (item)
    {
        InventoryResult msg = CanUseAmmo(item);
        if (msg != EQUIP_ERR_OK)
        {
            SendEquipError(msg, nullptr, nullptr, item);
            return;
        }
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
Item* Player::StoreNewItem(ItemPosCountVec const& dest, uint32 item, bool update, int32 randomPropertyId)
{
    uint32 count = 0;
    for (const auto& itr : dest)
        count += itr.count;

    Item* pItem = Item::CreateItem(item, count, GetObjectGuid());
    if (pItem)
    {
        ItemAddedQuestCheck(item, count);
        if (randomPropertyId)
            pItem->SetItemRandomProperties(randomPropertyId);
        pItem = StoreItem(dest, pItem, update);
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
    
    DEBUG_LOG("STORAGE: StoreItem bag = %u, slot = %u, item = %u, count = %u", bag, slot, pItem->GetEntry(), count);

    Item* pItem2 = GetItemByPos(bag, slot);

    if (!pItem2)
    {
        if (clone)
            pItem = pItem->CloneItem(count, this);
        else
            pItem->SetCount(count);

        if (!pItem)
            return nullptr;

        if (pItem->GetProto()->Bonding == BIND_WHEN_PICKED_UP ||
                pItem->GetProto()->Bonding == BIND_QUEST_ITEM ||
                (pItem->GetProto()->Bonding == BIND_WHEN_EQUIPPED && IsBagPos(pos)))
            pItem->SetBinding(true);

        if (bag == INVENTORY_SLOT_BAG_0)
        {
            if (PLAYER_FIELD_INV_SLOT_HEAD + (slot * 2) > LAST_ITEM_SLOT_FIELD)
                sLog.outError("Item being stored in wrong update field! Item Id: %u Slot: %u Field %u", pItem->GetEntry(), slot, PLAYER_FIELD_INV_SLOT_HEAD + (slot * 2));

            m_items[slot] = pItem;
            SetGuidValue(PLAYER_FIELD_INV_SLOT_HEAD + (slot * 2), pItem->GetObjectGuid());
            pItem->SetGuidValue(ITEM_FIELD_CONTAINED, GetObjectGuid());
            pItem->SetGuidValue(ITEM_FIELD_OWNER, GetObjectGuid());

            pItem->SetSlot(slot);
            pItem->SetContainer(nullptr);

            if (IsInWorld() && update)
            {
                pItem->AddToWorld();
                pItem->SendCreateUpdateToPlayer(this);
            }

            pItem->SetState(ITEM_CHANGED, this);
        }
        else if (Bag* pBag = (Bag*)GetItemByPos(INVENTORY_SLOT_BAG_0, bag))
        {
            pBag->StoreItem(slot, pItem, update);
            if (IsInWorld() && update)
            {
                pItem->AddToWorld();
                pItem->SendCreateUpdateToPlayer(this);
            }
            pItem->SetState(ITEM_CHANGED, this);
            pBag->SetState(ITEM_CHANGED, this);
        }

        AddEnchantmentDurations(pItem);
        AddItemDurations(pItem);

        return pItem;
    }
    else
    {
        if (pItem2->GetProto()->Bonding == BIND_WHEN_PICKED_UP ||
                pItem2->GetProto()->Bonding == BIND_QUEST_ITEM ||
                (pItem2->GetProto()->Bonding == BIND_WHEN_EQUIPPED && IsBagPos(pos)))
            pItem2->SetBinding(true);

        pItem2->SetCount(pItem2->GetCount() + count);
        if (IsInWorld() && update)
            pItem2->SendCreateUpdateToPlayer(this);

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

            pItem->SetOwnerGuid(GetObjectGuid());           // prevent error at next SetState in case trade/mail/buy from vendor
            pItem->SetState(ITEM_REMOVED, this);
        }

        // AddItemDurations(pItem2); - pItem2 already have duration listed for player
        AddEnchantmentDurations(pItem2);

        pItem2->SetState(ITEM_CHANGED, this);

        return pItem2;
    }
}

Item* Player::EquipNewItem(uint16 pos, uint32 item, bool update)
{
    if (Item* pItem = Item::CreateItem(item, 1, GetObjectGuid()))
    {
        ItemAddedQuestCheck(item, 1);
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
            ItemPrototype const* pProto = pItem->GetProto();

            // item set bonuses applied only at equip and removed at unequip, and still active for broken items
            if (pProto && pProto->ItemSet)
                AddItemsSetItem(this, pItem);

            _ApplyItemMods(pItem, slot, true);

            // World of Warcraft Client Patch 1.7.0 (2005-09-13)
            // - Switching weapons in combat triggers a 1 second global cooldown for
            //   all abilities for rogues and a 1.5 second global cooldown for
            //   everyone else.
#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_6_1
            // Weapons and also Totem/Relic/Sigil/etc
            if (pProto && IsInCombat() && (pProto->Class == ITEM_CLASS_WEAPON || pProto->InventoryType == INVTYPE_RELIC) && m_weaponChangeTimer == 0)
            {
                uint32 cooldownSpell = SPELL_ID_WEAPON_SWITCH_COOLDOWN_1_5s;

                // There doesn't appear to be a 1 sec combat swap cd spell before 1.9.
#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_8_4
                if (GetClass() == CLASS_ROGUE)
                    cooldownSpell = SPELL_ID_WEAPON_SWITCH_COOLDOWN_1_0s;
#endif

                SpellEntry const* spellProto = sSpellMgr.GetSpellEntry(cooldownSpell);

                if (!spellProto)
                    sLog.outError("Weapon switch cooldown spell %u couldn't be found in Spell.dbc", cooldownSpell);
                else
                {
#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_8_4
                    m_weaponChangeTimer = spellProto->StartRecoveryTime;
#else
                    m_weaponChangeTimer = (GetClass() == CLASS_ROGUE) ? 1000 : spellProto->StartRecoveryTime;
#endif
                    AddGCD(*spellProto, true);
                }
            }
#endif
        }

        if (IsInWorld() && update)
        {
            pItem->AddToWorld();
            pItem->SendCreateUpdateToPlayer(this);
        }

        ApplyEquipCooldown(pItem);

    }
    else
    {
        pItem2->SetCount(pItem2->GetCount() + pItem->GetCount());
        if (IsInWorld() && update)
            pItem2->SendCreateUpdateToPlayer(this);

        // delete item (it not in any slot currently)
        //pItem->DeleteFromDB();
        if (IsInWorld() && update)
        {
            pItem->RemoveFromWorld();
            pItem->DestroyForPlayer(this);
        }

        RemoveEnchantmentDurations(pItem);
        RemoveItemDurations(pItem);

        pItem->SetOwnerGuid(GetObjectGuid());               // prevent error at next SetState in case trade/mail/buy from vendor
        pItem->SetState(ITEM_REMOVED, this);
        pItem2->SetState(ITEM_CHANGED, this);

        ApplyEquipCooldown(pItem2);

        return pItem2;
    }

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
            pItem->SendCreateUpdateToPlayer(this);
        }
    }
}

void Player::SetVisibleItemSlot(uint8 slot, Item* pItem)
{
    if (pItem)
    {
        SetGuidValue(PLAYER_VISIBLE_ITEM_1_CREATOR + (slot * MAX_VISIBLE_ITEM_OFFSET), pItem->GetGuidValue(ITEM_FIELD_CREATOR));

        int VisibleBase = PLAYER_VISIBLE_ITEM_1_0 + (slot * MAX_VISIBLE_ITEM_OFFSET);
        SetUInt32Value(VisibleBase + 0, pItem->GetEntry());

        for (int i = 0; i < MAX_INSPECTED_ENCHANTMENT_SLOT; ++i)
            SetUInt32Value(VisibleBase + 1 + i, pItem->GetEnchantmentId(EnchantmentSlot(i)));

        // Use SetInt16Value to prevent set high part to FFFF for negative value
        SetInt16Value(PLAYER_VISIBLE_ITEM_1_PROPERTIES + (slot * MAX_VISIBLE_ITEM_OFFSET), 0, pItem->GetItemRandomPropertyId());
        SetUInt32Value(PLAYER_VISIBLE_ITEM_1_PROPERTIES + 1 + (slot * MAX_VISIBLE_ITEM_OFFSET), pItem->GetItemSuffixFactor());
    }
    else
    {
        SetGuidValue(PLAYER_VISIBLE_ITEM_1_CREATOR + (slot * MAX_VISIBLE_ITEM_OFFSET), ObjectGuid());

        int VisibleBase = PLAYER_VISIBLE_ITEM_1_0 + (slot * MAX_VISIBLE_ITEM_OFFSET);
        SetUInt32Value(VisibleBase + 0, 0);

        for (int i = 0; i < MAX_INSPECTED_ENCHANTMENT_SLOT; ++i)
            SetUInt32Value(VisibleBase + 1 + i, 0);

        SetUInt32Value(PLAYER_VISIBLE_ITEM_1_PROPERTIES + 0 + (slot * MAX_VISIBLE_ITEM_OFFSET), 0);
        SetUInt32Value(PLAYER_VISIBLE_ITEM_1_PROPERTIES + 1 + (slot * MAX_VISIBLE_ITEM_OFFSET), 0);
    }
}

void Player::VisualizeItem(uint8 slot, Item* pItem)
{
    if (!pItem)
        return;

    // check also  BIND_WHEN_PICKED_UP and BIND_QUEST_ITEM for .additem or .additemset case by GM (not binded at adding to inventory)
    if (pItem->GetProto()->Bonding == BIND_WHEN_EQUIPPED || pItem->GetProto()->Bonding == BIND_WHEN_PICKED_UP || pItem->GetProto()->Bonding == BIND_QUEST_ITEM)
        pItem->SetBinding(true);

    DEBUG_LOG("STORAGE: EquipItem slot = %u, item = %u", slot, pItem->GetEntry());

    m_items[slot] = pItem;
    SetGuidValue(PLAYER_FIELD_INV_SLOT_HEAD + (slot * 2), pItem->GetObjectGuid());
    pItem->SetGuidValue(ITEM_FIELD_CONTAINED, GetObjectGuid());
    pItem->SetGuidValue(ITEM_FIELD_OWNER, GetObjectGuid());
    pItem->SetSlot(slot);
    pItem->SetContainer(nullptr);

    if (slot < EQUIPMENT_SLOT_END)
        SetVisibleItemSlot(slot, pItem);

    pItem->SetState(ITEM_CHANGED, this);
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
        DEBUG_LOG("STORAGE: RemoveItem bag = %u, slot = %u, item = %u", bag, slot, pItem->GetEntry());

        RemoveEnchantmentDurations(pItem);
        RemoveItemDurations(pItem);

        if (bag == INVENTORY_SLOT_BAG_0)
        {
            if (slot < INVENTORY_SLOT_BAG_END)
            {
                ItemPrototype const* pProto = pItem->GetProto();
                // item set bonuses applied only at equip and removed at unequip, and still active for broken items

                if (pProto && pProto->ItemSet)
                    RemoveItemsSetItem(this, pProto);

                _ApplyItemMods(pItem, slot, false);

                // remove item dependent auras and casts (only weapon and armor slots)
                if (slot < EQUIPMENT_SLOT_END)
                {
                    RemoveItemDependentAurasAndCasts(pItem);

                    // remove held enchantments
                    if (slot == EQUIPMENT_SLOT_MAINHAND)
                        pItem->ClearEnchantment(PROP_ENCHANTMENT_SLOT_3);

                    // reset extraAttacks counter
                    if (slot == EQUIPMENT_SLOT_MAINHAND || slot == EQUIPMENT_SLOT_OFFHAND || slot == EQUIPMENT_SLOT_RANGED)
                        ResetExtraAttacks();
                }
            }

            m_items[slot] = nullptr;
            SetGuidValue(PLAYER_FIELD_INV_SLOT_HEAD + (slot * 2), ObjectGuid());

            if (slot < EQUIPMENT_SLOT_END)
                SetVisibleItemSlot(slot, nullptr);
        }
        else
        {
            Bag* pBag = (Bag*)GetItemByPos(INVENTORY_SLOT_BAG_0, bag);
            if (pBag)
                pBag->RemoveItem(slot, update);
        }
        pItem->SetGuidValue(ITEM_FIELD_CONTAINED, ObjectGuid());
        // pItem->SetGuidValue(ITEM_FIELD_OWNER, ObjectGuid()); not clear owner at remove (it will be set at store). This used in mail and auction code
        pItem->SetSlot(NULL_SLOT);
        if (IsInWorld() && update)
            pItem->SendCreateUpdateToPlayer(this);
    }
}

// Common operation need to remove item from inventory without delete in trade, auction, guild bank, mail....
void Player::MoveItemFromInventory(uint8 bag, uint8 slot, bool update)
{
    if (Item* it = GetItemByPos(bag, slot))
    {
        ItemRemovedQuestCheck(it->GetEntry(), it->GetCount());
        RemoveItem(bag, slot, update);
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

    // store item
    Item* pLastItem = StoreItem(dest, pItem, update);

    // only set if not merged to existing stack (pItem can be deleted already but we can compare pointers any way)
    if (pLastItem == pItem)
    {
        // update owner for last item (this can be original item with wrong owner
        if (pLastItem->GetOwnerGuid() != GetObjectGuid())
            pLastItem->SetOwnerGuid(GetObjectGuid());

        // if this original item then it need create record in inventory
        // in case trade we already have item in other player inventory
        pLastItem->SetState(in_characterInventoryDB ? ITEM_CHANGED : ITEM_NEW, this);
    }
}

// It should be assumed that the item is deleted after calling this. No further
// access to any item pointer referencing the item in this slot can be performed
void Player::DestroyItem(uint8 bag, uint8 slot, bool update)
{
    Item* pItem = GetItemByPos(bag, slot);
    if (pItem)
    {
        DEBUG_LOG("STORAGE: DestroyItem bag = %u, slot = %u, item = %u", bag, slot, pItem->GetEntry());

        // start from destroy contained items (only equipped bag can have its)
        // This if () prevents item saving crashes if the condition for a bag to be empty before being destroyed was bypassed somehow.
        if (pItem->IsBag())
        {
            if (pItem->IsEquipped())
            {
                for (int i = 0; i < MAX_BAG_SIZE; ++i)
                    DestroyItem(slot, i, update);
            }
            else if (!((Bag*)pItem)->IsEmpty())
                GetSession()->ProcessAnticheatAction("PassiveAnticheat", "Player::DestroyItem: destroying non equipped bag with items inside!", CHEAT_ACTION_LOG | CHEAT_ACTION_REPORT_GMS);
        }

        if (pItem->HasFlag(ITEM_FIELD_FLAGS, ITEM_DYNFLAG_WRAPPED))
        {
            static SqlStatementID delGifts ;

            SqlStatement stmt = CharacterDatabase.CreateStatement(delGifts, "DELETE FROM `character_gifts` WHERE `item_guid` = ?");
            stmt.PExecute(pItem->GetGUIDLow());
        }

        RemoveEnchantmentDurations(pItem);
        RemoveItemDurations(pItem);

        ItemRemovedQuestCheck(pItem->GetEntry(), pItem->GetCount());

        if (bag == INVENTORY_SLOT_BAG_0)
        {
            SetGuidValue(PLAYER_FIELD_INV_SLOT_HEAD + (slot * 2), ObjectGuid());

            // equipment and equipped bags can have applied bonuses
            if (slot < INVENTORY_SLOT_BAG_END)
            {
                ItemPrototype const* pProto = pItem->GetProto();

                // item set bonuses applied only at equip and removed at unequip, and still active for broken items
                if (pProto && pProto->ItemSet)
                    RemoveItemsSetItem(this, pProto);

                _ApplyItemMods(pItem, slot, false);
            }

            if (slot < EQUIPMENT_SLOT_END)
            {
                // remove item dependent auras and casts (only weapon and armor slots)
                RemoveItemDependentAurasAndCasts(pItem);

                // equipment visual show
                SetVisibleItemSlot(slot, nullptr);
            }

            m_items[slot] = nullptr;
        }
        else if (Bag* pBag = (Bag*)GetItemByPos(INVENTORY_SLOT_BAG_0, bag))
            pBag->RemoveItem(slot, update);

        if (IsInWorld() && update)
        {
            pItem->RemoveFromWorld();
            pItem->DestroyForPlayer(this);
        }

        // If destroying a charter, destroy the petition too
        if (pItem->IsCharter())
        {
            uint32 petitionId = pItem->GetEnchantmentId(EnchantmentSlot(0));
            if (Petition* petition = sGuildMgr.GetPetitionById(petitionId))
                sGuildMgr.DeletePetition(petition);
        }

        //pItem->SetOwnerGUID(0);
        pItem->SetGuidValue(ITEM_FIELD_CONTAINED, ObjectGuid());
        pItem->SetSlot(NULL_SLOT);
        // NOTE: Will delete the data pointed to by pItem if it is ITEM_NEW
        pItem->SetState(ITEM_REMOVED, this);
    }
}

void Player::DestroyItemCount(uint32 item, uint32 count, bool update, bool unequip_check, bool check_bank)
{
    DEBUG_LOG("STORAGE: DestroyItemCount item = %u, count = %u", item, count);
    uint32 remcount = 0;

    // in inventory
    for (int i = INVENTORY_SLOT_ITEM_START; i < INVENTORY_SLOT_ITEM_END; ++i)
    {
        if (Item* pItem = GetItemByPos(INVENTORY_SLOT_BAG_0, i))
        {
            if (pItem->GetEntry() == item && !pItem->IsInTrade())
            {
                if (pItem->GetCount() + remcount <= count)
                {
                    // all items in inventory can unequipped
                    remcount += pItem->GetCount();
                    DestroyItem(INVENTORY_SLOT_BAG_0, i, update);

                    if (remcount >= count)
                        return;
                }
                else
                {
                    ItemRemovedQuestCheck(pItem->GetEntry(), count - remcount);
                    pItem->SetCount(pItem->GetCount() - count + remcount);
                    if (IsInWorld() & update)
                        pItem->SendCreateUpdateToPlayer(this);
                    pItem->SetState(ITEM_CHANGED, this);
                    return;
                }
            }
        }
    }

    for (int i = KEYRING_SLOT_START; i < KEYRING_SLOT_END; ++i)
    {
        if (Item* pItem = GetItemByPos(INVENTORY_SLOT_BAG_0, i))
        {
            if (pItem->GetEntry() == item && !pItem->IsInTrade())
            {
                if (pItem->GetCount() + remcount <= count)
                {
                    // all keys can be unequipped
                    remcount += pItem->GetCount();
                    DestroyItem(INVENTORY_SLOT_BAG_0, i, update);

                    if (remcount >= count)
                        return;
                }
                else
                {
                    ItemRemovedQuestCheck(pItem->GetEntry(), count - remcount);
                    pItem->SetCount(pItem->GetCount() - count + remcount);
                    if (IsInWorld() & update)
                        pItem->SendCreateUpdateToPlayer(this);
                    pItem->SetState(ITEM_CHANGED, this);
                    return;
                }
            }
        }
    }

    // in inventory bags
    for (int i = INVENTORY_SLOT_BAG_START; i < INVENTORY_SLOT_BAG_END; ++i)
    {
        if (Bag* pBag = (Bag*)GetItemByPos(INVENTORY_SLOT_BAG_0, i))
        {
            for (uint32 j = 0; j < pBag->GetBagSize(); ++j)
            {
                if (Item* pItem = pBag->GetItemByPos(j))
                {
                    if (pItem->GetEntry() == item && !pItem->IsInTrade())
                    {
                        // all items in bags can be unequipped
                        if (pItem->GetCount() + remcount <= count)
                        {
                            remcount += pItem->GetCount();
                            DestroyItem(i, j, update);

                            if (remcount >= count)
                                return;
                        }
                        else
                        {
                            ItemRemovedQuestCheck(pItem->GetEntry(), count - remcount);
                            pItem->SetCount(pItem->GetCount() - count + remcount);
                            if (IsInWorld() && update)
                                pItem->SendCreateUpdateToPlayer(this);
                            pItem->SetState(ITEM_CHANGED, this);
                            return;
                        }
                    }
                }
            }
        }
    }

    // in equipment and bag list
    for (int i = EQUIPMENT_SLOT_START; i < INVENTORY_SLOT_BAG_END; ++i)
    {
        if (Item* pItem = GetItemByPos(INVENTORY_SLOT_BAG_0, i))
        {
            if (pItem && pItem->GetEntry() == item && !pItem->IsInTrade())
            {
                if (pItem->GetCount() + remcount <= count)
                {
                    if (!unequip_check || CanUnequipItem(INVENTORY_SLOT_BAG_0 << 8 | i, false) == EQUIP_ERR_OK)
                    {
                        remcount += pItem->GetCount();
                        DestroyItem(INVENTORY_SLOT_BAG_0, i, update);

                        if (remcount >= count)
                            return;
                    }
                }
                else
                {
                    ItemRemovedQuestCheck(pItem->GetEntry(), count - remcount);
                    pItem->SetCount(pItem->GetCount() - count + remcount);
                    if (IsInWorld() & update)
                        pItem->SendCreateUpdateToPlayer(this);
                    pItem->SetState(ITEM_CHANGED, this);
                    return;
                }
            }
        }
    }

    if (check_bank)
    {
        // in bank
        for (int i = BANK_SLOT_ITEM_START; i < BANK_SLOT_ITEM_END; ++i)
        {
            if (Item* pItem = GetItemByPos(INVENTORY_SLOT_BAG_0, i))
            {
                if (pItem->GetEntry() == item && !pItem->IsInTrade())
                {
                    if (pItem->GetCount() + remcount <= count)
                    {
                        remcount += pItem->GetCount();
                        DestroyItem(INVENTORY_SLOT_BAG_0, i, update);

                        if (remcount >= count)
                            return;
                    }
                    else
                    {
                        pItem->SetCount(pItem->GetCount() - count + remcount);
                        if (IsInWorld() & update)
                            pItem->SendCreateUpdateToPlayer(this);
                        pItem->SetState(ITEM_CHANGED, this);
                        return;
                    }
                }
            }
        }

        // in bank bags
        for (int i = BANK_SLOT_BAG_START; i < BANK_SLOT_BAG_END; ++i)
        {
            if (Bag* pBag = (Bag*)GetItemByPos(INVENTORY_SLOT_BAG_0, i))
            {
                for (uint32 j = 0; j < pBag->GetBagSize(); ++j)
                {
                    if (Item* pItem = pBag->GetItemByPos(j))
                    {
                        if (pItem->GetEntry() == item && !pItem->IsInTrade())
                        {
                            if (pItem->GetCount() + remcount <= count)
                            {
                                remcount += pItem->GetCount();
                                DestroyItem(i, j, update);

                                if (remcount >= count)
                                    return;
                            }
                            else
                            {
                                pItem->SetCount(pItem->GetCount() - count + remcount);
                                if (IsInWorld() && update)
                                    pItem->SendCreateUpdateToPlayer(this);
                                pItem->SetState(ITEM_CHANGED, this);
                                return;
                            }
                        }
                    }
                }
            }
        }
    }
}

bool Player::DestroyEquippedItem(uint32 itemId)
{
    // in equipment and bag list
    for (int i = EQUIPMENT_SLOT_START; i < EQUIPMENT_SLOT_END; ++i)
    {
        if (Item* pItem = GetItemByPos(INVENTORY_SLOT_BAG_0, i))
        {
            if (pItem && pItem->GetEntry() == itemId && !pItem->IsInTrade())
            {
                DestroyItem(INVENTORY_SLOT_BAG_0, i, true);
                return true;
            }
        }
    }
    return false;
}

void Player::DestroyZoneLimitedItem(bool update, uint32 new_zone)
{
    DEBUG_LOG("STORAGE: DestroyZoneLimitedItem in map %u and area %u", GetMapId(), new_zone);

    // in inventory
    for (int i = INVENTORY_SLOT_ITEM_START; i < INVENTORY_SLOT_ITEM_END; ++i)
        if (Item* pItem = GetItemByPos(INVENTORY_SLOT_BAG_0, i))
            if (pItem->IsLimitedToAnotherMapOrZone(GetMapId(), new_zone))
                DestroyItem(INVENTORY_SLOT_BAG_0, i, update);

    for (int i = KEYRING_SLOT_START; i < KEYRING_SLOT_END; ++i)
        if (Item* pItem = GetItemByPos(INVENTORY_SLOT_BAG_0, i))
            if (pItem->IsLimitedToAnotherMapOrZone(GetMapId(), new_zone))
                DestroyItem(INVENTORY_SLOT_BAG_0, i, update);

    // in inventory bags
    for (int i = INVENTORY_SLOT_BAG_START; i < INVENTORY_SLOT_BAG_END; ++i)
        if (Bag* pBag = (Bag*)GetItemByPos(INVENTORY_SLOT_BAG_0, i))
            for (uint32 j = 0; j < pBag->GetBagSize(); ++j)
                if (Item* pItem = pBag->GetItemByPos(j))
                    if (pItem->IsLimitedToAnotherMapOrZone(GetMapId(), new_zone))
                        DestroyItem(i, j, update);

    // in equipment and bag list
    for (int i = EQUIPMENT_SLOT_START; i < INVENTORY_SLOT_BAG_END; ++i)
        if (Item* pItem = GetItemByPos(INVENTORY_SLOT_BAG_0, i))
            if (pItem->IsLimitedToAnotherMapOrZone(GetMapId(), new_zone))
                DestroyItem(INVENTORY_SLOT_BAG_0, i, update);
}

void Player::DestroyConjuredItems(bool update)
{
    // destroys all conjured items
    DEBUG_LOG("STORAGE: DestroyConjuredItems");

    // in inventory
    for (int i = INVENTORY_SLOT_ITEM_START; i < INVENTORY_SLOT_ITEM_END; ++i)
        if (Item* pItem = GetItemByPos(INVENTORY_SLOT_BAG_0, i))
            if (pItem->IsConjuredConsumable())
                DestroyItem(INVENTORY_SLOT_BAG_0, i, update);

    // in inventory bags
    for (int i = INVENTORY_SLOT_BAG_START; i < INVENTORY_SLOT_BAG_END; ++i)
        if (Bag* pBag = (Bag*)GetItemByPos(INVENTORY_SLOT_BAG_0, i))
            for (uint32 j = 0; j < pBag->GetBagSize(); ++j)
                if (Item* pItem = pBag->GetItemByPos(j))
                    if (pItem->IsConjuredConsumable())
                        DestroyItem(i, j, update);

    // in equipment and bag list
    for (int i = EQUIPMENT_SLOT_START; i < INVENTORY_SLOT_BAG_END; ++i)
        if (Item* pItem = GetItemByPos(INVENTORY_SLOT_BAG_0, i))
            if (pItem->IsConjuredConsumable())
                DestroyItem(INVENTORY_SLOT_BAG_0, i, update);
}

void Player::DestroyItemCount(Item* pItem, uint32& count, bool update)
{
    if (!pItem)
        return;

    DEBUG_LOG("STORAGE: DestroyItemCount item (GUID: %u, Entry: %u) count = %u", pItem->GetGUIDLow(), pItem->GetEntry(), count);

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
        if (IsInWorld() & update)
            pItem->SendCreateUpdateToPlayer(this);
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

    if (pSrcItem->HasGeneratedLoot())                       // prevent split looting item (stackable items can has only temporary loot and this meaning that loot window open)
    {
        //best error message found for attempting to split while looting
        SendEquipError(EQUIP_ERR_COULDNT_SPLIT_ITEMS, pSrcItem, nullptr);
        return;
    }

    // not let split all items (can be only at cheating)
    if (pSrcItem->GetCount() == count)
    {
        GetSession()->ProcessAnticheatAction("PassiveAnticheat", "Attempt to split full item stack", CHEAT_ACTION_LOG | CHEAT_ACTION_REPORT_GMS);
        SendEquipError(EQUIP_ERR_COULDNT_SPLIT_ITEMS, pSrcItem, nullptr);
        return;
    }

    // not let split more existing items (can be only at cheating)
    if (pSrcItem->GetCount() < count)
    {
        GetSession()->ProcessAnticheatAction("PassiveAnticheat", "Attempt to split more items than have", CHEAT_ACTION_LOG | CHEAT_ACTION_REPORT_GMS);
        SendEquipError(EQUIP_ERR_TRIED_TO_SPLIT_MORE_THAN_COUNT, pSrcItem, nullptr);
        return;
    }

    //! If trading
    if (TradeData* tradeData = GetTradeData())
    {
        //! If current item is in trade window (only possible with packet spoofing - silent return)
        if (tradeData->GetTradeSlotForItem(pSrcItem->GetObjectGuid()) != TRADE_SLOT_INVALID)
        {
            GetSession()->ProcessAnticheatAction("PassiveAnticheat", "Attempt to split item in trade", CHEAT_ACTION_LOG | CHEAT_ACTION_REPORT_GMS);
            return;
        }
    }

    DEBUG_LOG("STORAGE: SplitItem bag = %u, slot = %u, item = %u, count = %u", dstbag, dstslot, pSrcItem->GetEntry(), count);
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
            pSrcItem->SendCreateUpdateToPlayer(this);
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
            pSrcItem->SendCreateUpdateToPlayer(this);
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
            pSrcItem->SendCreateUpdateToPlayer(this);
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

    DEBUG_LOG("STORAGE: SwapItem bag = %u, slot = %u, item = %u", dstbag, dstslot, pSrcItem->GetEntry());

    if (!IsAlive() && !(IsInventoryPos(src) && IsInventoryPos(dst)))
    {
        SendEquipError(EQUIP_ERR_YOU_ARE_DEAD, pSrcItem, pDstItem);
        return;
    }

    // SRC checks

    // check unequip potability for equipped items and bank bags
    if (IsEquipmentPos(src) || IsBagPos(src))
    {
        // bags can be swapped with empty bag slots, or with empty bag (items move possibility checked later)
        InventoryResult msg = CanUnequipItem(src, !IsBagPos(src) || IsBagPos(dst) || (pDstItem && pDstItem->IsBag() && ((Bag*)pDstItem)->IsEmpty()));
        if (msg != EQUIP_ERR_OK)
        {
            SendEquipError(msg, pSrcItem, pDstItem);
            return;
        }
    }

    // prevent put equipped/bank bag in self
    if (IsBagPos(src) && srcslot == dstbag)
    {
        GetSession()->ProcessAnticheatAction("PassiveAnticheat", "SwapItem: put equipped/bank bag in self (srcslot == dstbag)", CHEAT_ACTION_LOG | CHEAT_ACTION_REPORT_GMS);
        SendEquipError(EQUIP_ERR_NONEMPTY_BAG_OVER_OTHER_BAG, pSrcItem, pDstItem);
        return;
    }

    // prevent put equipped/bank bag in self
    if (IsBagPos(dst) && dstslot == srcbag)
    {
        GetSession()->ProcessAnticheatAction("PassiveAnticheat", "SwapItem: put equipped/bank bag in self (dstslot == srcbag)", CHEAT_ACTION_LOG | CHEAT_ACTION_REPORT_GMS);
        SendEquipError(EQUIP_ERR_NONEMPTY_BAG_OVER_OTHER_BAG, pDstItem, pSrcItem);
        return;
    }

    // DST checks

    if (pDstItem)
    {
        // check unequip potability for equipped items and bank bags
        if (IsEquipmentPos(dst) || IsBagPos(dst))
        {
            // bags can be swapped with empty bag slots, or with empty bag (items move possibility checked later)
            InventoryResult msg = CanUnequipItem(dst, !IsBagPos(dst) || IsBagPos(src) || (pSrcItem->IsBag() && ((Bag*)pSrcItem)->IsEmpty()));
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
        uint16 eDest;
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
            if (pSrcItem->GetCount() + pDstItem->GetCount() <= pSrcItem->GetProto()->GetMaxStackSize())
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
                pSrcItem->SetCount(pSrcItem->GetCount() + pDstItem->GetCount() - pSrcItem->GetProto()->GetMaxStackSize());
                pDstItem->SetCount(pSrcItem->GetProto()->GetMaxStackSize());
                pSrcItem->SetState(ITEM_CHANGED, this);
                pDstItem->SetState(ITEM_CHANGED, this);
                if (IsInWorld())
                {
                    pSrcItem->SendCreateUpdateToPlayer(this);
                    pDstItem->SendCreateUpdateToPlayer(this);
                }
            }
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
    if (pSrcItem->IsBag() && pDstItem->IsBag())
    {
        Bag* emptyBag = nullptr;
        Bag* fullBag = nullptr;
        if (((Bag*)pSrcItem)->IsEmpty() && !IsBagPos(src))
        {
            emptyBag = (Bag*)pSrcItem;
            fullBag  = (Bag*)pDstItem;
        }
        else if (((Bag*)pDstItem)->IsEmpty() && !IsBagPos(dst))
        {
            emptyBag = (Bag*)pDstItem;
            fullBag  = (Bag*)pSrcItem;
        }

        // bag swap (with items exchange) case
        if (emptyBag && fullBag)
        {
            ItemPrototype const* emotyProto = emptyBag->GetProto();

            uint32 count = 0;

            for (uint32 i = 0; i < fullBag->GetBagSize(); ++i)
            {
                Item* bagItem = fullBag->GetItemByPos(i);
                if (!bagItem)
                    continue;

                ItemPrototype const* bagItemProto = bagItem->GetProto();
                if (!bagItemProto || !ItemCanGoIntoBag(bagItemProto, emotyProto))
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
            for (uint32 i = 0; i < fullBag->GetBagSize(); ++i)
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
    if (GetLootGuid())
    {
        bool released = false;
        if (IsBagPos(src))
        {
            Bag* bag = (Bag*)pSrcItem;
            for (uint32 i = 0; i < bag->GetBagSize(); ++i)
            {
                if (Item* bagItem = bag->GetItemByPos(i))
                {
                    if (bagItem->HasGeneratedLoot())
                    {
                        m_session->DoLootRelease(GetLootGuid());
                        released = true;                    // so we don't need to look at dstBag
                        break;
                    }
                }
            }
        }

        if (!released && IsBagPos(dst) && pDstItem)
        {
            Bag* bag = (Bag*)pDstItem;
            for (uint32 i = 0; i < bag->GetBagSize(); ++i)
            {
                if (Item* bagItem = bag->GetItemByPos(i))
                {
                    if (bagItem->HasGeneratedLoot())
                    {
                        m_session->DoLootRelease(GetLootGuid());
                        released = true;                    // not realy needed here
                        break;
                    }
                }
            }
        }
    }

    AutoUnequipOffhandIfNeed();
}

void Player::AddItemToBuyBackSlot(Item* pItem, uint32 money, ObjectGuid vendorGuid)
{
    MANGOS_ASSERT(!!pItem);

    uint32 slot = m_currentBuybackSlot;
#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_7_1
    // if current back slot non-empty search oldest or free
    if (m_items[slot])
    {
        uint32 oldest_time = GetUInt32Value(PLAYER_FIELD_BUYBACK_TIMESTAMP_1);
        uint32 oldest_slot = BUYBACK_SLOT_START;

        for (uint32 i = BUYBACK_SLOT_START + 1; i < BUYBACK_SLOT_END; ++i)
        {
            // found empty
            if (!m_items[i])
            {
                slot = i;
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
    DEBUG_LOG("STORAGE: AddItemToBuyBackSlot item = %u, slot = %u", pItem->GetEntry(), slot);

    m_items[slot] = pItem;
    time_t base = time(nullptr);
    uint32 etime = uint32(base - m_loginTime + (30 * 3600));
    uint32 eslot = slot - BUYBACK_SLOT_START;

    SetGuidValue(PLAYER_FIELD_VENDORBUYBACK_SLOT_1 + (eslot * 2), pItem->GetObjectGuid());
    SetUInt32Value(PLAYER_FIELD_BUYBACK_PRICE_1 + eslot, money);
    SetUInt32Value(PLAYER_FIELD_BUYBACK_TIMESTAMP_1 + eslot, (uint32)etime);

    // move to next (for non filled list is move most optimized choice)
    if (m_currentBuybackSlot < BUYBACK_SLOT_END - 1)
        ++m_currentBuybackSlot;
#else
    RemoveItemFromBuyBackSlot(slot, true);
    DEBUG_LOG("STORAGE: AddItemToBuyBackSlot item = %u, slot = %u", pItem->GetEntry(), slot);
    m_items[slot] = pItem;
    SetGuidValue(PLAYER_FIELD_VENDORBUYBACK_SLOT, pItem->GetObjectGuid());
    SetUInt32Value(PLAYER_FIELD_BUYBACK_ITEM_ID, pItem->GetEntry());
    SetUInt32Value(PLAYER_FIELD_BUYBACK_RANDOM_PROPERTIES_ID, pItem->GetItemRandomPropertyId());
    SetUInt32Value(PLAYER_FIELD_BUYBACK_SEED, pItem->GetItemSuffixFactor());
    SetUInt32Value(PLAYER_FIELD_BUYBACK_PRICE, (pItem->GetProto()->BuyPrice / pItem->GetProto()->BuyCount) * pItem->GetCount());
    SetUInt32Value(PLAYER_FIELD_BUYBACK_DURABILITY, pItem->GetUInt32Value(ITEM_FIELD_DURABILITY));
    SetUInt32Value(PLAYER_FIELD_BUYBACK_COUNT, pItem->GetCount());
    SetUInt64Value(PLAYER_FIELD_BUYBACK_NPC, vendorGuid);
#endif

}

Item* Player::GetItemFromBuyBackSlot(uint32 slot)
{
    DEBUG_LOG("STORAGE: GetItemFromBuyBackSlot slot = %u", slot);
    if (slot >= BUYBACK_SLOT_START && slot < BUYBACK_SLOT_END)
        return m_items[slot];
    return nullptr;
}

void Player::RemoveItemFromBuyBackSlot(uint32 slot, bool del)
{
    DEBUG_LOG("STORAGE: RemoveItemFromBuyBackSlot slot = %u", slot);
    if (slot >= BUYBACK_SLOT_START && slot < BUYBACK_SLOT_END)
    {
        Item* pItem = m_items[slot];
        if (pItem)
        {
            pItem->RemoveFromWorld();
            if (del) pItem->SetState(ITEM_REMOVED, this);
        }

        m_items[slot] = nullptr;

#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_7_1
        uint32 eslot = slot - BUYBACK_SLOT_START;
        SetGuidValue(PLAYER_FIELD_VENDORBUYBACK_SLOT_1 + (eslot * 2), ObjectGuid());
        SetUInt32Value(PLAYER_FIELD_BUYBACK_PRICE_1 + eslot, 0);
        SetUInt32Value(PLAYER_FIELD_BUYBACK_TIMESTAMP_1 + eslot, 0);
#else
        SetGuidValue(PLAYER_FIELD_VENDORBUYBACK_SLOT, ObjectGuid());
        SetUInt32Value(PLAYER_FIELD_BUYBACK_ITEM_ID, 0);
        SetUInt32Value(PLAYER_FIELD_BUYBACK_RANDOM_PROPERTIES_ID, 0);
        SetUInt32Value(PLAYER_FIELD_BUYBACK_SEED, 0);
        SetUInt32Value(PLAYER_FIELD_BUYBACK_PRICE, 0);
        SetUInt32Value(PLAYER_FIELD_BUYBACK_DURABILITY, 0);
        SetUInt32Value(PLAYER_FIELD_BUYBACK_COUNT, 0);
#endif

        // if current backslot is filled set to now free slot
        if (m_items[m_currentBuybackSlot])
            m_currentBuybackSlot = slot;
    }
}

void Player::SendEquipError(InventoryResult msg, Item* pItem, Item* pItem2, uint32 itemid /*= 0*/) const
{
    DEBUG_LOG("WORLD: Sent SMSG_INVENTORY_CHANGE_FAILURE (%u)", msg);
    WorldPacket data(SMSG_INVENTORY_CHANGE_FAILURE, (msg == EQUIP_ERR_CANT_EQUIP_LEVEL_I ? 22 : (msg == EQUIP_ERR_OK ? 1 : 18)));
    data << uint8(msg);

    if (msg != EQUIP_ERR_OK)
    {
        if (msg == EQUIP_ERR_CANT_EQUIP_LEVEL_I)
        {
            ItemPrototype const* proto = pItem ? pItem->GetProto() : ObjectMgr::GetItemPrototype(itemid);
            data << uint32(proto ? proto->RequiredLevel : 0);
        }
        data << (pItem ? pItem->GetObjectGuid() : ObjectGuid());
        data << (pItem2 ? pItem2->GetObjectGuid() : ObjectGuid());
        data << uint8(0);                                   // bag type subclass, used with EQUIP_ERR_EVENT_AUTOEQUIP_BIND_CONFIRM and EQUIP_ERR_ITEM_DOESNT_GO_INTO_BAG2
    }
    GetSession()->SendPacket(&data);
}

void Player::SendOpenContainer() const
{
    DEBUG_LOG("WORLD: Sent SMSG_OPEN_CONTAINER");
    WorldPacket data(SMSG_OPEN_CONTAINER, 8);   // opens the main bag in the UI
    data << GetObjectGuid();
    GetSession()->SendPacket(&data);
}

void Player::SendBuyError(BuyResult msg, Creature* pCreature, uint32 item, uint32 /*param*/) const
{
    DEBUG_LOG("WORLD: Sent SMSG_BUY_FAILED");
    WorldPacket data(SMSG_BUY_FAILED, (8 + 4 + 1));
    data << (pCreature ? pCreature->GetObjectGuid() : ObjectGuid());
    data << uint32(item);
    //if (param > 0)
    //    data << uint32(param);    // [-ZERO]
    data << uint8(msg);
    GetSession()->SendPacket(&data);
}

void Player::SendSellError(SellResult msg, Creature* pCreature, ObjectGuid itemGuid, uint32 /*param*/) const
{
    DEBUG_LOG("WORLD: Sent SMSG_SELL_ITEM");
    WorldPacket data(SMSG_SELL_ITEM, (8 + 8 + /*(param ? 4 : 0) +*/ 1)); // last check [ZERO]
    data << (pCreature ? pCreature->GetObjectGuid() : ObjectGuid());
    data << ObjectGuid(itemGuid);
    //if (param > 0)
    //    data << uint32(param);    // [-ZERO]
    data << uint8(msg);
    GetSession()->SendPacket(&data);
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

void Player::UpdateItemDuration(uint32 time, bool realtimeonly)
{
    if (m_itemDuration.empty())
        return;

    DEBUG_LOG("Player::UpdateItemDuration(%u,%u)", time, realtimeonly);

    for (ItemDurationList::const_iterator itr = m_itemDuration.begin(); itr != m_itemDuration.end();)
    {
        Item* item = *itr;
        ++itr;                                              // current element can be erased in UpdateDuration

        if (!realtimeonly || (item->GetProto()->Flags & ITEM_FLAG_REAL_DURATION))
            item->UpdateDuration(this, time);
    }
}

void Player::UpdateEnchantTime(uint32 time)
{
    for (EnchantDurationList::iterator itr = m_enchantDuration.begin(), next; itr != m_enchantDuration.end(); itr = next)
    {
        MANGOS_ASSERT(itr->item);
        next = itr;
        if (!itr->item->GetEnchantmentId(itr->slot))
            next = m_enchantDuration.erase(itr);
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
            item->SetEnchantmentDuration(EnchantmentSlot(itr->slot), itr->leftduration);
            itr = m_enchantDuration.erase(itr);
        }
        else
            ++itr;
    }
}

void Player::RemoveAllEnchantments(EnchantmentSlot slot)
{
    // remove enchantments from equipped items first to clean up the m_enchantDuration list
    for (EnchantDurationList::iterator itr = m_enchantDuration.begin(), next; itr != m_enchantDuration.end(); itr = next)
    {
        next = itr;
        if (itr->slot == slot)
        {
            if (itr->item && itr->item->GetEnchantmentId(slot))
            {
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
    for (int i = INVENTORY_SLOT_ITEM_START; i < INVENTORY_SLOT_ITEM_END; ++i)
        if (Item* pItem = GetItemByPos(INVENTORY_SLOT_BAG_0, i))
            if (pItem->GetEnchantmentId(slot))
                pItem->ClearEnchantment(slot);

    // in inventory bags
    for (int i = INVENTORY_SLOT_BAG_START; i < INVENTORY_SLOT_BAG_END; ++i)
        if (Bag* pBag = (Bag*)GetItemByPos(INVENTORY_SLOT_BAG_0, i))
            for (uint32 j = 0; j < pBag->GetBagSize(); ++j)
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
            itr->item->SetEnchantmentDuration(itr->slot, itr->leftduration);
            m_enchantDuration.erase(itr);
            break;
        }
    }
    if (item && duration > 0)
    {
        GetSession()->SendItemEnchantTimeUpdate(GetObjectGuid(), item->GetObjectGuid(), slot, uint32(duration / 1000));
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
    if (!item)
        return;

    if (slot >= MAX_ENCHANTMENT_SLOT)
        return;

    uint32 enchant_id = item->GetEnchantmentId(slot);
    if (!enchant_id)
        return;

    SpellItemEnchantmentEntry const* pEnchant = sSpellItemEnchantmentStore.LookupEntry(enchant_id);
    if (!pEnchant)
        return;

    if (item->IsEquipped() && !item->IsBroken())
    // Process modifiers to Player stats
    {
        for (int s = 0; s < 3; ++s)
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
                    if (item->GetSlot() == EQUIPMENT_SLOT_MAINHAND)
                        HandleStatModifier(UNIT_MOD_DAMAGE_MAINHAND, TOTAL_VALUE, float(enchant_amount), apply);
                    else if (item->GetSlot() == EQUIPMENT_SLOT_OFFHAND)
                        HandleStatModifier(UNIT_MOD_DAMAGE_OFFHAND, TOTAL_VALUE, float(enchant_amount), apply);
                    else if (item->GetSlot() == EQUIPMENT_SLOT_RANGED)
                        HandleStatModifier(UNIT_MOD_DAMAGE_RANGED, TOTAL_VALUE, float(enchant_amount), apply);
                    break;
                case ITEM_ENCHANTMENT_TYPE_EQUIP_SPELL:
                {
                    if (enchant_spell_id)
                    {
                        if (apply)
                            CastSpell(this, enchant_spell_id, true, item);
                        else
                            RemoveAurasDueToItemSpell(item, enchant_spell_id);
                    }
                    break;
                }
                case ITEM_ENCHANTMENT_TYPE_RESISTANCE:
                    HandleStatModifier(UnitMods(UNIT_MOD_RESISTANCE_START + enchant_spell_id), TOTAL_VALUE, float(enchant_amount), apply);
                    break;
                case ITEM_ENCHANTMENT_TYPE_STAT:
                {
                    DEBUG_LOG("Adding %u to stat nb %u", enchant_amount, enchant_spell_id);
                    switch (enchant_spell_id)
                    {
                        case ITEM_MOD_MANA:
                            DEBUG_LOG("+ %u MANA", enchant_amount);
                            HandleStatModifier(UNIT_MOD_MANA, BASE_VALUE, float(enchant_amount), apply);
                            break;
                        case ITEM_MOD_HEALTH:
                            DEBUG_LOG("+ %u HEALTH", enchant_amount);
                            HandleStatModifier(UNIT_MOD_HEALTH, BASE_VALUE, float(enchant_amount), apply);
                            break;
                        case ITEM_MOD_AGILITY:
                            DEBUG_LOG("+ %u AGILITY", enchant_amount);
                            HandleStatModifier(UNIT_MOD_STAT_AGILITY, TOTAL_VALUE, float(enchant_amount), apply);
                            ApplyStatBuffMod(STAT_AGILITY, float(enchant_amount), apply);
                            break;
                        case ITEM_MOD_STRENGTH:
                            DEBUG_LOG("+ %u STRENGTH", enchant_amount);
                            HandleStatModifier(UNIT_MOD_STAT_STRENGTH, TOTAL_VALUE, float(enchant_amount), apply);
                            ApplyStatBuffMod(STAT_STRENGTH, float(enchant_amount), apply);
                            break;
                        case ITEM_MOD_INTELLECT:
                            DEBUG_LOG("+ %u INTELLECT", enchant_amount);
                            HandleStatModifier(UNIT_MOD_STAT_INTELLECT, TOTAL_VALUE, float(enchant_amount), apply);
                            ApplyStatBuffMod(STAT_INTELLECT, float(enchant_amount), apply);
                            break;
                        case ITEM_MOD_SPIRIT:
                            DEBUG_LOG("+ %u SPIRIT", enchant_amount);
                            HandleStatModifier(UNIT_MOD_STAT_SPIRIT, TOTAL_VALUE, float(enchant_amount), apply);
                            ApplyStatBuffMod(STAT_SPIRIT, float(enchant_amount), apply);
                            break;
                        case ITEM_MOD_STAMINA:
                            DEBUG_LOG("+ %u STAMINA", enchant_amount);
                            HandleStatModifier(UNIT_MOD_STAT_STAMINA, TOTAL_VALUE, float(enchant_amount), apply);
                            ApplyStatBuffMod(STAT_STAMINA, float(enchant_amount), apply);
                            break;
                        default:
                            break;
                    }
                    break;
                }
                case ITEM_ENCHANTMENT_TYPE_TOTEM:           // Shaman Rockbiter Weapon
                {
                    if (GetClass() == CLASS_SHAMAN)
                    {
                        float addValue = 0.0f;
                        if (item->GetSlot() == EQUIPMENT_SLOT_MAINHAND)
                        {
                            addValue = float(enchant_amount * item->GetProto()->Delay / 1000.0f);
                            HandleStatModifier(UNIT_MOD_DAMAGE_MAINHAND, TOTAL_VALUE, addValue, apply);
                        }
                        else if (item->GetSlot() == EQUIPMENT_SLOT_OFFHAND)
                        {
                            addValue = float(enchant_amount * item->GetProto()->Delay / 1000.0f);
                            HandleStatModifier(UNIT_MOD_DAMAGE_OFFHAND, TOTAL_VALUE, addValue, apply);
                        }
                    }
                    break;
                }
                default:
                    sLog.outError("Unknown item enchantment (id = %d) display type: %d", enchant_id, enchant_display_type);
                    break;
            }                                               /*switch(enchant_display_type)*/
        }                                                   /*for*/
    }

    // visualize enchantment of equipped player items (mostly weapon glows)
    if (item->IsEquipped() && slot < MAX_INSPECTED_ENCHANTMENT_SLOT)
    {
        int VisibleBase = PLAYER_VISIBLE_ITEM_1_0 + (item->GetSlot() * MAX_VISIBLE_ITEM_OFFSET);
        SetUInt32Value(VisibleBase + 1 + slot, apply ? item->GetEnchantmentId(slot) : 0);
    }

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

void Player::SendEnchantmentDurations() const
{
    for (const auto& itr : m_enchantDuration)
        GetSession()->SendItemEnchantTimeUpdate(GetObjectGuid(), itr.item->GetObjectGuid(), itr.slot, uint32(itr.leftduration) / 1000);
}

void Player::SendItemDurations() const
{
    for (const auto& itr : m_itemDuration)
        itr->SendTimeUpdate(this);
}

void Player::SendNewItem(Item* item, uint32 count, bool received, bool created, bool broadcast /*=false*/, bool showInChat /*=true*/)
{
    if (!item)                                              // prevent crash
        return;

    // last check 2.0.10
    WorldPacket data(SMSG_ITEM_PUSH_RESULT, (8 + 4 + 4 + 4 + 1 + 4 + 4 + 4 + 4 + 4));
    data << GetObjectGuid();                                // player GUID
    data << uint32(received);                               // 0=looted, 1=from npc
    data << uint32(created);                                // 0=received, 1=created
    data << uint32(showInChat);                             // showInChat
    data << uint8(item->GetBagSlot());                      // bagslot
    // item slot, but when added to stack: 0xFFFFFFFF
#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_10_2
    data << uint32((item->GetCount() == count) ? item->GetSlot() : -1);
#endif
    data << uint32(item->GetEntry());                       // item id
    data << uint32(item->GetItemSuffixFactor());            // SuffixFactor
    data << uint32(item->GetItemRandomPropertyId());        // random item property id
    data << uint32(count);                                  // count of items
    //data << uint32(GetItemCount(item->GetEntry()));       // [-ZERO] count of items in inventory

    if (broadcast && GetGroup())
        GetGroup()->BroadcastPacket(&data, true);
    else
        GetSession()->SendPacket(&data);
}

/*********************************************************/
/***                    GOSSIP SYSTEM                  ***/
/*********************************************************/

void Player::PrepareGossipMenu(WorldObject* pSource, uint32 menuId)
{
    PlayerMenu* pMenu = PlayerTalkClass;
    pMenu->ClearMenus();

    pMenu->GetGossipMenu().SetMenuId(menuId);

    GossipMenuItemsMapBounds pMenuItemBounds = sObjectMgr.GetGossipMenuItemsMapBounds(menuId);

    // prepares quest menu when true
    bool defaultMenu = menuId == pSource->GetDefaultGossipMenuId();
    bool canSeeQuests = defaultMenu;

    // If we're not a quest giver, don't show quests in the gossip
    if (canSeeQuests && (
        (pSource->IsGameObject() && pSource->ToGameObject()->GetGOInfo()->type != GAMEOBJECT_TYPE_QUESTGIVER) ||
        (pSource->IsCreature() && !pSource->HasFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER))))
    {
        canSeeQuests = false;
    }

    // if canSeeQuests (the default, top level menu) and no menu options exist for this, use options from default options
    if (pMenuItemBounds.first == pMenuItemBounds.second && defaultMenu)
        pMenuItemBounds = sObjectMgr.GetGossipMenuItemsMapBounds(0);

    for (GossipMenuItemsMap::const_iterator itr = pMenuItemBounds.first; itr != pMenuItemBounds.second; ++itr)
    {
        bool hasMenuItem = true;
        bool isGMSkipConditionCheck = false;

        if (itr->second.condition_id && !IsConditionSatisfied(itr->second.condition_id, this, GetMap(), pSource, CONDITION_FROM_GOSSIP_OPTION))
        {
            if (IsGameMaster())                             // Let GM always see menu items regardless of conditions
                isGMSkipConditionCheck = true;
            else
            {
                if (itr->second.option_id == GOSSIP_OPTION_QUESTGIVER)
                    canSeeQuests = false;
                continue;                                   // Skip this option
            }
        }

        if (pSource->GetTypeId() == TYPEID_UNIT)
        {
            Creature* pCreature = (Creature*)pSource;

            uint32 npcflags = pCreature->GetUInt32Value(UNIT_NPC_FLAGS);

            if (!(itr->second.npc_option_npcflag & npcflags))
                continue;

            switch (itr->second.option_id)
            {
                case GOSSIP_OPTION_GOSSIP:
                    break;
                case GOSSIP_OPTION_QUESTGIVER:
                    hasMenuItem = false;
                    break;
                case GOSSIP_OPTION_ARMORER:
                    hasMenuItem = false;                    // added in special mode
                    break;
                case GOSSIP_OPTION_SPIRITHEALER:
                    if (!IsDead())
                        hasMenuItem = false;
                    break;
                case GOSSIP_OPTION_VENDOR:
                {
                    VendorItemData const* vItems = pCreature->GetVendorItems();
                    VendorItemData const* tItems = pCreature->GetVendorTemplateItems();
                    if ((!vItems || vItems->Empty()) && (!tItems || tItems->Empty()))
                    {
                        sLog.outErrorDb("Creature %u (Entry: %u) have UNIT_NPC_FLAG_VENDOR but have empty trading item list.", pCreature->GetGUIDLow(), pCreature->GetEntry());
                        hasMenuItem = false;
                    }
                    break;
                }
                case GOSSIP_OPTION_TRAINER:
                    if (!pCreature->IsTrainerOf(this, false))
                        hasMenuItem = false;
                    break;
                case GOSSIP_OPTION_UNLEARNTALENTS:
                    if (!pCreature->CanTrainAndResetTalentsOf(this))
                        hasMenuItem = false;
                    break;
                case GOSSIP_OPTION_UNLEARNPETSKILLS:
                    if (!GetPet() || GetPet()->getPetType() != HUNTER_PET || GetPet()->m_petSpells.size() <= 1 || pCreature->GetCreatureInfo()->trainer_type != TRAINER_TYPE_PETS || pCreature->GetCreatureInfo()->trainer_class != CLASS_HUNTER)
                        hasMenuItem = false;
                    break;
                case GOSSIP_OPTION_TAXIVENDOR:
                    if (GetSession()->SendLearnNewTaxiNode(pCreature))
                        pMenu->GetGossipMenu().SetDiscoveredNode();
                    break;
                case GOSSIP_OPTION_BATTLEFIELD:
                    if (!pCreature->CanInteractWithBattleMaster(this, false))
                        hasMenuItem = false;
                    break;
                case GOSSIP_OPTION_STABLEPET:
                    if (GetClass() != CLASS_HUNTER)
                        hasMenuItem = false;
                    break;
                case GOSSIP_OPTION_SPIRITGUIDE:
                case GOSSIP_OPTION_INNKEEPER:
                case GOSSIP_OPTION_BANKER:
                case GOSSIP_OPTION_PETITIONER:
                case GOSSIP_OPTION_TABARDDESIGNER:
                case GOSSIP_OPTION_AUCTIONEER:
                    break;                                  // no checks
                default:
                    sLog.outErrorDb("Creature entry %u have unknown gossip option %u for menu %u", pCreature->GetEntry(), itr->second.option_id, itr->second.menu_id);
                    hasMenuItem = false;
                    break;
            }
        }
        else if (pSource->GetTypeId() == TYPEID_GAMEOBJECT)
        {
            GameObject* pGo = (GameObject*)pSource;

            switch (itr->second.option_id)
            {
                case GOSSIP_OPTION_QUESTGIVER:
                    hasMenuItem = false;
                    break;
                case GOSSIP_OPTION_GOSSIP:
                    if (pGo->GetGoType() != GAMEOBJECT_TYPE_QUESTGIVER && pGo->GetGoType() != GAMEOBJECT_TYPE_GOOBER)
                        hasMenuItem = false;
                    break;
                default:
                    hasMenuItem = false;
                    break;
            }
        }

        if (hasMenuItem)
        {
            std::string strOptionText, strBoxText;
            int loc_idx = GetSession()->GetSessionDbLocaleIndex();

            if (itr->second.option_broadcast_text)
                strOptionText = sObjectMgr.GetBroadcastTextLocale(itr->second.option_broadcast_text)->GetText(loc_idx, GetGender(), false);
            else
                strOptionText = itr->second.option_text;

            if (itr->second.box_broadcast_text)
                strBoxText = sObjectMgr.GetBroadcastTextLocale(itr->second.box_broadcast_text)->GetText(loc_idx, GetGender(), false);
            else
                strBoxText = itr->second.box_text;

            if (loc_idx >= 0)
            {
                uint32 idxEntry = MAKE_PAIR32(menuId, itr->second.id);

                if (!itr->second.option_broadcast_text)
                    if (GossipMenuItemsLocale const* no = sObjectMgr.GetGossipMenuItemsLocale(idxEntry))
                        if (no->OptionText.size() > (size_t)loc_idx && !no->OptionText[loc_idx].empty())
                            strOptionText = no->OptionText[loc_idx];

                if (!itr->second.box_broadcast_text)
                    if (GossipMenuItemsLocale const* no = sObjectMgr.GetGossipMenuItemsLocale(idxEntry))
                        if (no->BoxText.size() > (size_t)loc_idx && !no->BoxText[loc_idx].empty())
                            strBoxText = no->BoxText[loc_idx];
            }

            if (isGMSkipConditionCheck)
            {
                strOptionText.append(" (");
                strOptionText.append(GetSession()->GetMangosString(LANG_GM_ON));
                strOptionText.append(")");
            }

            pMenu->GetGossipMenu().AddMenuItem(itr->second.option_icon, strOptionText, 0, itr->second.option_id, strBoxText, itr->second.box_coded);
            pMenu->GetGossipMenu().AddGossipMenuItemData(itr->second.action_menu_id, itr->second.action_poi_id, itr->second.action_script_id);
        }
    }

    if (canSeeQuests)
        PrepareQuestMenu(pSource->GetObjectGuid());
}

void Player::SendPreparedGossip(WorldObject* pSource)
{
    if (!pSource)
        return;

    GossipMenu gossipMenu = PlayerTalkClass->GetGossipMenu();
    QuestMenu questMenu = PlayerTalkClass->GetQuestMenu();

    if (pSource->GetTypeId() == TYPEID_UNIT)
    {
        if (gossipMenu.IsJustDiscoveredNode() && questMenu.Empty())
            return;

        // in case no gossip flag and quest menu not empty, open quest menu (client expect gossip menu with this flag)
        if (!((Creature*)pSource)->HasFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP) && !questMenu.Empty()
                && !((Creature*)pSource)->HasFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_VENDOR)) // Fix mobs vendeurs avec des quetes.
        {
            SendPreparedQuest(pSource->GetObjectGuid());
            return;
        }
    }
    else if (pSource->GetTypeId() == TYPEID_GAMEOBJECT)
    {
        // probably need to find a better way here
        if (!gossipMenu.GetMenuId() && !questMenu.Empty())
        {
            SendPreparedQuest(pSource->GetObjectGuid());
            return;
        }
    }

    // in case non empty gossip menu (that not included quests list size) show it
    // (quest entries from quest menu will be included in list)

    uint32 textId = GetGossipTextId(pSource);

    if (uint32 menuId = gossipMenu.GetMenuId())
        textId = GetGossipTextId(menuId, pSource);

    // Gameobjects should not greet players
    if (pSource->GetTypeId() == TYPEID_GAMEOBJECT && PlayerTalkClass->GetQuestMenu().Empty() && PlayerTalkClass->GetGossipMenu().Empty() && textId == DEFAULT_GOSSIP_MESSAGE)
        return;

    PlayerTalkClass->SendGossipMenu(textId, pSource->GetObjectGuid());
}

void Player::OnGossipSelect(WorldObject* pSource, uint32 gossipListId)
{
    GossipMenu& gossipmenu = PlayerTalkClass->GetGossipMenu();

    if (gossipListId >= gossipmenu.MenuItemCount())
        return;

    GossipMenuItem const&  menu_item = gossipmenu.GetItem(gossipListId);

    uint32 gossipOptionId = menu_item.m_gOptionId;
    ObjectGuid guid = pSource->GetObjectGuid();

    if (pSource->GetTypeId() == TYPEID_GAMEOBJECT)
    {
        if (gossipOptionId > GOSSIP_OPTION_QUESTGIVER)
        {
            sLog.outError("Player guid %u request invalid gossip option for GameObject entry %u", GetGUIDLow(), pSource->GetEntry());
            return;
        }
    }

    GossipMenuItemData pMenuData = gossipmenu.GetItemData(gossipListId);

    switch (gossipOptionId)
    {
        case GOSSIP_OPTION_GOSSIP:
        {
            if (pMenuData.m_gAction_poi)
                PlayerTalkClass->SendPointOfInterest(pMenuData.m_gAction_poi);

            // send new menu || close gossip || stay at current menu
            if (pMenuData.m_gAction_menu > 0)
            {
                PrepareGossipMenu(pSource, uint32(pMenuData.m_gAction_menu));
                SendPreparedGossip(pSource);
            }
            else if (pMenuData.m_gAction_menu < 0)
            {
                PlayerTalkClass->CloseGossip();
                TalkedToCreature(pSource->GetEntry(), pSource->GetObjectGuid());
            }

            break;
        }
        case GOSSIP_OPTION_SPIRITHEALER:
            if (IsDead())
                ((Creature*)pSource)->CastSpell(((Creature*)pSource), 17251, true, nullptr, nullptr, GetObjectGuid());
            break;
        case GOSSIP_OPTION_QUESTGIVER:
            PrepareQuestMenu(guid);
            SendPreparedQuest(guid);
            break;
        case GOSSIP_OPTION_VENDOR:
        case GOSSIP_OPTION_ARMORER:
            GetSession()->SendListInventory(guid, pMenuData.m_gAction_menu ? pMenuData.m_gAction_menu : VENDOR_MENU_ALL);
            break;
        case GOSSIP_OPTION_STABLEPET:
            GetSession()->SendStablePet(guid);
            break;
        case GOSSIP_OPTION_TRAINER:
            GetSession()->SendTrainerList(guid);
            break;
        case GOSSIP_OPTION_UNLEARNTALENTS:
            PlayerTalkClass->CloseGossip();
            SendTalentWipeConfirm(guid);
            break;
        case GOSSIP_OPTION_UNLEARNPETSKILLS:
            PlayerTalkClass->CloseGossip();
            SendPetSkillWipeConfirm();
            break;
        case GOSSIP_OPTION_TAXIVENDOR:
            GetSession()->SendTaxiMenu(((Creature*)pSource));
            break;
        case GOSSIP_OPTION_INNKEEPER:
            PlayerTalkClass->CloseGossip();
#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_6_1
            SetBindPoint(guid);
#else
            GetSession()->SendBindPoint((Creature*)pSource);
#endif
            break;
        case GOSSIP_OPTION_BANKER:
            GetSession()->SendShowBank(guid);
            break;
        case GOSSIP_OPTION_PETITIONER:
            PlayerTalkClass->CloseGossip();
            GetSession()->SendPetitionShowList(guid);
            break;
        case GOSSIP_OPTION_TABARDDESIGNER:
            PlayerTalkClass->CloseGossip();
            GetSession()->SendTabardVendorActivate(guid);
            break;
        case GOSSIP_OPTION_AUCTIONEER:
            GetSession()->SendAuctionHello(((Creature*)pSource));
            break;
        case GOSSIP_OPTION_SPIRITGUIDE:
            PrepareGossipMenu(pSource);
            SendPreparedGossip(pSource);
            break;
        case GOSSIP_OPTION_BATTLEFIELD:
        {
            BattleGroundTypeId bgTypeId = sBattleGroundMgr.GetBattleMasterBG(pSource->GetEntry());

            if (bgTypeId == BATTLEGROUND_TYPE_NONE)
            {
                sLog.outError("a user (guid %u) requested battlegroundlist from a npc who is no battlemaster", GetGUIDLow());
                return;
            }

            GetSession()->SendBattleGroundList(guid, bgTypeId);
            break;
        }
    }

    if (pMenuData.m_gAction_script)
    {
        if (pSource->GetTypeId() == TYPEID_GAMEOBJECT)
            GetMap()->ScriptsStart(sGossipScripts, pMenuData.m_gAction_script, GetObjectGuid(), pSource->GetObjectGuid());
        else if (pSource->GetTypeId() == TYPEID_UNIT)
            GetMap()->ScriptsStart(sGossipScripts, pMenuData.m_gAction_script, pSource->GetObjectGuid(), GetObjectGuid());
    }
}

uint32 Player::GetGossipTextId(WorldObject* pSource)
{
    if (!pSource || pSource->GetTypeId() != TYPEID_UNIT)
        return DEFAULT_GOSSIP_MESSAGE;

    if (uint32 pos = sObjectMgr.GetNpcGossip(((Creature*)pSource)->GetGUIDLow()))
        return pos;

    return DEFAULT_GOSSIP_MESSAGE;
}

uint32 Player::GetGossipTextId(uint32 menuId, WorldObject* pSource)
{
    uint32 textId = DEFAULT_GOSSIP_MESSAGE;

    if (!menuId)
        return textId;

    uint32 scriptId = 0;
    uint32 lastConditionId = 0;

    GossipMenusMapBounds pMenuBounds = sObjectMgr.GetGossipMenusMapBounds(menuId);
    for (GossipMenusMap::const_iterator itr = pMenuBounds.first; itr != pMenuBounds.second; ++itr)
    {
        // Take the text that has the highest conditionId of all fitting
        // No condition and no text with condition found OR higher and fitting condition found
        if ((!itr->second.condition_id && !lastConditionId) ||
                (itr->second.condition_id > lastConditionId && IsConditionSatisfied(itr->second.condition_id, this, GetMap(), pSource, CONDITION_FROM_GOSSIP_MENU)))
        {
            lastConditionId = itr->second.condition_id;
            textId = itr->second.text_id;
            scriptId = itr->second.script_id;
        }
    }

    // Start related script
    if (scriptId)
        GetMap()->ScriptsStart(sGossipScripts, scriptId, pSource ? pSource->GetObjectGuid() : ObjectGuid(), GetObjectGuid());

    return textId;
}

/*********************************************************/
/***                    QUEST SYSTEM                   ***/
/*********************************************************/

void Player::PrepareQuestMenu(ObjectGuid guid, uint32 exceptQuestId)
{
    QuestRelationsMapBounds rbounds;
    QuestRelationsMapBounds irbounds;

    // pets also can have quests
    if (Creature* pCreature = GetMap()->GetAnyTypeCreature(guid))
    {
        rbounds = sObjectMgr.GetCreatureQuestRelationsMapBounds(pCreature->GetEntry());
        irbounds = sObjectMgr.GetCreatureQuestInvolvedRelationsMapBounds(pCreature->GetEntry());
    }
    else
    {
        //we should obtain map pointer from GetMap() in 99% of cases. Special case
        //only for quests which cast teleport spells on player
        Map* _map = IsInWorld() ? GetMap() : sMapMgr.FindMap(GetMapId(), GetInstanceId());
        MANGOS_ASSERT(_map);

        if (GameObject* pGameObject = _map->GetGameObject(guid))
        {
            rbounds = sObjectMgr.GetGOQuestRelationsMapBounds(pGameObject->GetEntry());
            irbounds = sObjectMgr.GetGOQuestInvolvedRelationsMapBounds(pGameObject->GetEntry());
        }
        else
            return;
    }

    QuestMenu &qm = PlayerTalkClass->GetQuestMenu();
    qm.ClearMenu();

    for (QuestRelationsMap::const_iterator itr = irbounds.first; itr != irbounds.second; ++itr)
    {
        uint32 quest_id = itr->second;
        if (quest_id == exceptQuestId)
            continue;

        Quest const* pQuest = sObjectMgr.GetQuestTemplate(quest_id);

        if (!pQuest || !pQuest->IsActive())
            continue;

        QuestStatus status = GetQuestStatus(quest_id);

        if (status == QUEST_STATUS_COMPLETE && !GetQuestRewardStatus(quest_id))
            qm.AddMenuItem(quest_id, DIALOG_STATUS_REWARD_REP);
        else if (status == QUEST_STATUS_INCOMPLETE)
            qm.AddMenuItem(quest_id, DIALOG_STATUS_INCOMPLETE);
        else if (status == QUEST_STATUS_AVAILABLE)
            qm.AddMenuItem(quest_id, DIALOG_STATUS_CHAT);
    }

    for (QuestRelationsMap::const_iterator itr = rbounds.first; itr != rbounds.second; ++itr)
    {
        uint32 quest_id = itr->second;
        if (quest_id == exceptQuestId)
            continue;

        Quest const* pQuest = sObjectMgr.GetQuestTemplate(quest_id);

        if (!pQuest || !pQuest->IsActive())
            continue;

        QuestStatus status = GetQuestStatus(quest_id);

        if (pQuest->IsAutoComplete() && CanTakeQuest(pQuest, false))
            qm.AddMenuItem(quest_id, DIALOG_STATUS_REWARD_REP);
        else if (status == QUEST_STATUS_NONE && CanTakeQuest(pQuest, false))
            qm.AddMenuItem(quest_id, DIALOG_STATUS_AVAILABLE);
    }
}

void Player::SendPreparedQuest(ObjectGuid guid)
{
    QuestMenu& questMenu = PlayerTalkClass->GetQuestMenu();
    if (questMenu.Empty())
        return;

    QuestMenuItem const& qmi0 = questMenu.GetItem(0);

    uint32 status = qmi0.m_qIcon;

    // single element case
    if (questMenu.MenuItemCount() == 1)
    {
        // Auto open -- maybe also should verify there is no greeting
        uint32 quest_id = qmi0.m_qId;
        Quest const* pQuest = sObjectMgr.GetQuestTemplate(quest_id);

        if (pQuest)
        {
            if (status == DIALOG_STATUS_REWARD_REP && !GetQuestRewardStatus(quest_id))
                PlayerTalkClass->SendQuestGiverRequestItems(pQuest, guid, CanRewardQuest(pQuest, false), true);
            else if (status == DIALOG_STATUS_INCOMPLETE)
                PlayerTalkClass->SendQuestGiverRequestItems(pQuest, guid, false, true);
            // Send completable on repeatable quest if player don't have quest
            else if (pQuest->IsRepeatable() && CanCompleteRepeatableQuest(pQuest))
                PlayerTalkClass->SendQuestGiverRequestItems(pQuest, guid, true, true);
            else
                PlayerTalkClass->SendQuestGiverQuestDetails(pQuest, guid, true);
        }
    }
    // multiply entries
    else
    {
        QEmote qe;
        qe._Delay = 0;
        qe._Emote = 0;
        std::string title;

        // need pet case for some quests
        if (Creature* pCreature = GetMap()->GetAnyTypeCreature(guid))
        {
            uint32 textid = sObjectMgr.GetNpcGossip(pCreature->GetGUIDLow());

            NpcText const* gossiptext = sObjectMgr.GetNpcText(textid);
            if (gossiptext && gossiptext->Options[0].BroadcastTextID)
            {
                if (BroadcastText const* bct = sObjectMgr.GetBroadcastTextLocale(gossiptext->Options[0].BroadcastTextID))
                {
                    qe._Emote = bct->emoteId1;
                    qe._Delay = bct->emoteDelay1;
                    int loc_idx = GetSession()->GetSessionDbLocaleIndex();
                    title = bct->GetText(loc_idx, pCreature->GetGender(), false);
                }
                
            }
        }
        PlayerTalkClass->SendQuestGiverQuestList(qe, title, guid);
    }
}

bool Player::IsActiveQuest(uint32 quest_id) const
{
    QuestStatusMap::const_iterator itr = mQuestStatus.find(quest_id);

    return itr != mQuestStatus.end() && itr->second.m_status != QUEST_STATUS_NONE;
}

bool Player::IsCurrentQuest(uint32 quest_id, uint8 completedOrNot) const
{
    QuestStatusMap::const_iterator itr = mQuestStatus.find(quest_id);
    if (itr == mQuestStatus.end())
        return false;

    QuestStatusData const& questStatus = itr->second;

    switch (completedOrNot)
    {
        case 1:
            return questStatus.m_status == QUEST_STATUS_INCOMPLETE;
        case 2:
            return questStatus.m_status == QUEST_STATUS_COMPLETE && !questStatus.m_rewarded;
        default:
            return questStatus.m_status == QUEST_STATUS_INCOMPLETE || (questStatus.m_status == QUEST_STATUS_COMPLETE && !questStatus.m_rewarded);
    }
}

Quest const* Player::GetNextQuest(ObjectGuid guid, Quest const* pQuest)
{
    QuestRelationsMapBounds rbounds;

    if (Creature* pCreature = GetMap()->GetAnyTypeCreature(guid))
        rbounds = sObjectMgr.GetCreatureQuestRelationsMapBounds(pCreature->GetEntry());
    else
    {
        //we should obtain map pointer from GetMap() in 99% of cases. Special case
        //only for quests which cast teleport spells on player
        Map* _map = IsInWorld() ? GetMap() : sMapMgr.FindMap(GetMapId(), GetInstanceId());
        MANGOS_ASSERT(_map);

        if (GameObject* pGameObject = _map->GetGameObject(guid))
            rbounds = sObjectMgr.GetGOQuestRelationsMapBounds(pGameObject->GetEntry());
        else
            return nullptr;
    }

    uint32 nextQuestID = pQuest->GetNextQuestInChain();
    for (QuestRelationsMap::const_iterator itr = rbounds.first; itr != rbounds.second; ++itr)
    {
        if (itr->second == nextQuestID)
            return sObjectMgr.GetQuestTemplate(nextQuestID);
    }

    return nullptr;
}

/**
* Check if a player could see a start quest
* Basic Quest-taking requirements: Class, Race, Skill, Quest-Line, ...
* Check if the quest-level is not too high (related config value CONFIG_INT32_QUEST_HIGH_LEVEL_HIDE_DIFF)
*/
bool Player::CanSeeStartQuest(Quest const* pQuest) const
{
    if (SatisfyQuestClass(pQuest, false) && SatisfyQuestRace(pQuest, false) && SatisfyQuestSkill(pQuest, false) && SatisfyQuestCondition(pQuest, false) &&
            SatisfyQuestExclusiveGroup(pQuest, false) && SatisfyQuestReputation(pQuest, false) &&
            SatisfyQuestPreviousQuest(pQuest, false) && SatisfyQuestNextChain(pQuest, false) &&
            SatisfyQuestPrevChain(pQuest, false) &&
            pQuest->IsActive())
    {
        int32 highLevelDiff = sWorld.getConfig(CONFIG_INT32_QUEST_HIGH_LEVEL_HIDE_DIFF);
        if (highLevelDiff < 0)
            return true;
        return GetLevel() + uint32(highLevelDiff) >= pQuest->GetMinLevel();
    }

    return false;
}

bool Player::CanTakeQuest(Quest const* pQuest, bool msg, bool skipStatusCheck /*false*/) const
{
    if (pQuest->GetMaxLevel() && pQuest->GetMaxLevel() < GetLevel())
        return false;

    return (skipStatusCheck || SatisfyQuestStatus(pQuest, msg)) && SatisfyQuestExclusiveGroup(pQuest, msg) &&
           SatisfyQuestClass(pQuest, msg) && SatisfyQuestRace(pQuest, msg) && SatisfyQuestLevel(pQuest, msg) &&
           SatisfyQuestSkill(pQuest, msg) && SatisfyQuestCondition(pQuest, msg) && SatisfyQuestReputation(pQuest, msg) &&
           SatisfyQuestPreviousQuest(pQuest, msg) && SatisfyQuestTimed(pQuest, msg) &&
           SatisfyQuestNextChain(pQuest, msg) && SatisfyQuestPrevChain(pQuest, msg) &&
           pQuest->IsActive();
}

bool Player::CanAddQuest(Quest const* pQuest, bool msg) const
{
    if (!SatisfyQuestLog(msg))
        return false;

    if (!CanGiveQuestSourceItemIfNeed(pQuest))
        return false;

    return true;
}

bool Player::CanCompleteQuest(uint32 quest_id) const
{
    if (!quest_id)
        return false;

    QuestStatusMap::const_iterator q_itr = mQuestStatus.find(quest_id);

    // some quests can be auto taken and auto completed in one step
    QuestStatus status = q_itr != mQuestStatus.end() ? q_itr->second.m_status : QUEST_STATUS_NONE;

    if (status == QUEST_STATUS_COMPLETE)
        return false;                                       // not allow re-complete quest

    Quest const* qInfo = sObjectMgr.GetQuestTemplate(quest_id);

    if (!qInfo)
        return false;

    // only used for "flag" quests and not real in-game quests
    if (qInfo->HasQuestFlag(QUEST_FLAGS_AUTO_REWARDED))
    {
        // a few checks, not all "satisfy" is needed
        return SatisfyQuestPreviousQuest(qInfo, false) && SatisfyQuestLevel(qInfo, false) &&
                SatisfyQuestSkill(qInfo, false) && SatisfyQuestRace(qInfo, false) && SatisfyQuestClass(qInfo, false);
    }

    // auto complete quest
    if (qInfo->IsAutoComplete() && CanTakeQuest(qInfo, false))
        return true;

    if (status != QUEST_STATUS_INCOMPLETE)
        return false;

    // incomplete quest have status data
    QuestStatusData const& q_status = q_itr->second;

    if (qInfo->HasSpecialFlag(QUEST_SPECIAL_FLAG_DELIVER))
    {
        for (int i = 0; i < QUEST_OBJECTIVES_COUNT; ++i)
        {
            if (qInfo->ReqItemCount[i] != 0 && q_status.m_itemcount[i] < qInfo->ReqItemCount[i])
                return false;
        }
    }

    if (qInfo->HasSpecialFlag(QuestSpecialFlags(QUEST_SPECIAL_FLAG_KILL_OR_CAST | QUEST_SPECIAL_FLAG_SPEAKTO)))
    {
        for (int i = 0; i < QUEST_OBJECTIVES_COUNT; ++i)
        {
            if (qInfo->ReqCreatureOrGOId[i] == 0)
                continue;

            if (qInfo->ReqCreatureOrGOCount[i] != 0 && q_status.m_creatureOrGOcount[i] < qInfo->ReqCreatureOrGOCount[i])
                return false;
        }
    }

    if (qInfo->HasSpecialFlag(QUEST_SPECIAL_FLAG_EXPLORATION_OR_EVENT) && !q_status.m_explored)
        return false;

    if (qInfo->HasSpecialFlag(QUEST_SPECIAL_FLAG_TIMED) && q_status.m_timer == 0)
        return false;

    if (qInfo->GetRewOrReqMoney() < 0)
    {
        if (GetMoney() < uint32(-qInfo->GetRewOrReqMoney()))
            return false;
    }

    uint32 repFacId = qInfo->GetRepObjectiveFaction();
    return !(repFacId && GetReputationMgr().GetReputation(repFacId) < qInfo->GetRepObjectiveValue());
}

bool Player::CanCompleteRepeatableQuest(Quest const* pQuest) const
{
    // Solve problem that player don't have the quest and try complete it.
    // if repeatable she must be able to complete event if player don't have it.
    // Seem that all repeatable quest are DELIVER Flag so, no need to add more.
    if (!CanTakeQuest(pQuest, false))
        return false;

    if (pQuest->HasSpecialFlag(QUEST_SPECIAL_FLAG_DELIVER))
        for (int i = 0; i < QUEST_ITEM_OBJECTIVES_COUNT; ++i)
            if (pQuest->ReqItemId[i] && pQuest->ReqItemCount[i] && !HasItemCount(pQuest->ReqItemId[i], pQuest->ReqItemCount[i]))
                return false;

    if (!CanRewardQuest(pQuest, false))
        return false;

    return true;
}

bool Player::CanRewardQuest(Quest const* pQuest, bool msg) const
{
    // Prevent packet-editing exploits
    // Players must meet prereqs for AutoComplete quests
    if (pQuest->IsAutoComplete())
    {
        if (!CanTakeQuest(pQuest, false, true))
            return false;
    }
    else
    {
        // Normal quests must be accepted and have a complete status
        if (GetQuestStatus(pQuest->GetQuestId()) != QUEST_STATUS_COMPLETE)
            return false;
    }

    // Prevent completing the same quest twice
    if (GetQuestRewardStatus(pQuest->GetQuestId()))
        return false;

    // prevent receive reward with quest items in bank
    if (pQuest->HasSpecialFlag(QUEST_SPECIAL_FLAG_DELIVER))
    {
        for (int i = 0; i < QUEST_ITEM_OBJECTIVES_COUNT; ++i)
        {
            if (pQuest->ReqItemCount[i] != 0 &&
                    GetItemCount(pQuest->ReqItemId[i]) < pQuest->ReqItemCount[i])
            {
                if (msg)
                    SendEquipError(EQUIP_ERR_ITEM_NOT_FOUND, nullptr, nullptr, pQuest->ReqItemId[i]);
                return false;
            }
        }
    }

    // Check if players have enough money to complete the quest
    if (pQuest->GetRewOrReqMoney() < 0 && GetMoney() < uint32(-pQuest->GetRewOrReqMoney()))
    {
        SendCanTakeQuestResponse(INVALIDREASON_QUEST_FAILED_NOT_ENOUGH_MONEY);
        return false;
    }

    return true;
}

bool Player::CanRewardQuest(Quest const* pQuest, uint32 reward, bool msg) const
{
    // prevent receive reward with quest items in bank or for not completed quest
    if (!CanRewardQuest(pQuest, msg))
        return false;

    uint32 numRewardedItems = 0;
    if (pQuest->GetRewChoiceItemsCount() > 0)
    {
        ++numRewardedItems;
        if (pQuest->RewChoiceItemId[reward])
        {
            ItemPosCountVec dest;
            InventoryResult res = CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, pQuest->RewChoiceItemId[reward], pQuest->RewChoiceItemCount[reward]);
            if (res != EQUIP_ERR_OK)
            {
                if (res == EQUIP_ERR_INVENTORY_FULL)
                    SendQuestFailedAtTaker(pQuest->GetQuestId(), INVALIDREASON_QUEST_FAILED_INVENTORY_FULL);
                else if (res == EQUIP_ERR_CANT_CARRY_MORE_OF_THIS)
                    SendQuestFailedAtTaker(pQuest->GetQuestId(), INVALIDREASON_QUEST_FAILED_DUPLICATE_ITEM);
                else
                    SendEquipError(res, nullptr, nullptr, pQuest->RewChoiceItemId[reward]);
                return false;
            }
        }
    }

    if (pQuest->GetRewItemsCount() > 0)
    {
        for (uint32 i = 0; i < pQuest->GetRewItemsCount(); ++i)
        {
            if (pQuest->RewItemId[i])
            {
                ItemPosCountVec dest;
                InventoryResult res = CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, pQuest->RewItemId[i], pQuest->RewItemCount[i]);
                if (res != EQUIP_ERR_OK)
                {
                    if (res == EQUIP_ERR_INVENTORY_FULL)
                        SendQuestFailedAtTaker(pQuest->GetQuestId(), INVALIDREASON_QUEST_FAILED_INVENTORY_FULL);
                    else if (res == EQUIP_ERR_CANT_CARRY_MORE_OF_THIS)
                        SendQuestFailedAtTaker(pQuest->GetQuestId(), INVALIDREASON_QUEST_FAILED_DUPLICATE_ITEM);
                    else
                        SendEquipError(res, nullptr, nullptr);
                    return false;
                }
                numRewardedItems += dest.size();
            }
        }
    }
    if (CountFreeInventorySlots() < numRewardedItems)
    {
        SendEquipError(EQUIP_ERR_INVENTORY_FULL, nullptr, nullptr);
        return false;
    }
    return true;
}

uint32 Player::CountFreeInventorySlots() const
{
    uint32 freeSlots = 0;
    for (int i = INVENTORY_SLOT_ITEM_START; i < INVENTORY_SLOT_ITEM_END; ++i)
        if (!GetItemByPos(INVENTORY_SLOT_BAG_0, i))
            ++freeSlots;
    for (int i = INVENTORY_SLOT_BAG_START; i < INVENTORY_SLOT_BAG_END; ++i)
        if (Bag* pBag = (Bag*)GetItemByPos(INVENTORY_SLOT_BAG_0, i))
            if (pBag->GetProto()->Class == ITEM_CLASS_CONTAINER && pBag->GetProto()->SubClass == ITEM_SUBCLASS_CONTAINER)
                for (uint32 j = 0; j < pBag->GetBagSize(); ++j)
                    if (!GetItemByPos(i, j))
                        ++freeSlots;
    return freeSlots;
}

void Player::SendPetTameFailure(PetTameFailureReason reason) const
{
    WorldPacket data(SMSG_PET_TAME_FAILURE, 1);
    data << uint8(reason);
    GetSession()->SendPacket(&data);
}

void Player::AddQuest(Quest const* pQuest, Object* questGiver)
{
    uint16 log_slot = FindQuestSlot(0);
    MANGOS_ASSERT(log_slot < MAX_QUEST_LOG_SIZE);

    uint32 quest_id = pQuest->GetQuestId();

    // if not exist then created with set uState==NEW and rewarded=false
    QuestStatusData& questStatusData = mQuestStatus[quest_id];

    // check for repeatable quests status reset
    questStatusData.m_status = QUEST_STATUS_INCOMPLETE;
    questStatusData.m_explored = false;

    if (pQuest->HasSpecialFlag(QUEST_SPECIAL_FLAG_DELIVER))
    {
        for (uint32 & i : questStatusData.m_itemcount)
            i = 0;
    }

    if (pQuest->HasSpecialFlag(QuestSpecialFlags(QUEST_SPECIAL_FLAG_KILL_OR_CAST | QUEST_SPECIAL_FLAG_SPEAKTO)))
    {
        for (uint32 & i : questStatusData.m_creatureOrGOcount)
            i = 0;
    }

    if (pQuest->GetRepObjectiveFaction())
        if (FactionEntry const* factionEntry = sObjectMgr.GetFactionEntry(pQuest->GetRepObjectiveFaction()))
            GetReputationMgr().SetVisible(factionEntry);

    uint32 qtime = 0;
    if (pQuest->HasSpecialFlag(QUEST_SPECIAL_FLAG_TIMED))
    {
        uint32 limittime = pQuest->GetLimitTime();

        // shared timed quest
        if (questGiver && questGiver->GetTypeId() == TYPEID_PLAYER)
            limittime = ((Player*)questGiver)->getQuestStatusMap()[quest_id].m_timer / IN_MILLISECONDS;

        AddTimedQuest(quest_id);
        questStatusData.m_timer = limittime * IN_MILLISECONDS;
        qtime = static_cast<uint32>(time(nullptr)) + limittime;
    }
    else
        questStatusData.m_timer = 0;

    // Set PvP flag for PvP quests
    if (pQuest->GetType() == QUEST_TYPE_PVP)
        UpdatePvP(true, true);

    SetQuestSlot(log_slot, quest_id, qtime);

    if (questStatusData.uState != QUEST_NEW)
        questStatusData.uState = QUEST_CHANGED;

    // quest accept scripts
    if (questGiver)
    {
        switch (questGiver->GetTypeId())
        {
            case TYPEID_UNIT:
                sScriptMgr.OnQuestAccept(this, (Creature*)questGiver, pQuest);
                break;
            case TYPEID_GAMEOBJECT:
                sScriptMgr.OnQuestAccept(this, (GameObject*)questGiver, pQuest);
                break;
        }

        // starting initial DB quest script
        if (pQuest->GetQuestStartScript() != 0)
            if (WorldObject* pQuestGiver = questGiver->ToWorldObject())
                GetMap()->ScriptsStart(sQuestStartScripts, pQuest->GetQuestStartScript(), pQuestGiver->GetObjectGuid(), GetObjectGuid());

    }

    // remove start item if not need
    if (questGiver && questGiver->isType(TYPEMASK_ITEM))
    {
        // destroy not required for quest finish quest starting item
        bool notRequiredItem = true;
        for (uint32 i : pQuest->ReqItemId)
        {
            if (i == questGiver->GetEntry())
            {
                notRequiredItem = false;
                break;
            }
        }

        if (pQuest->GetSrcItemId() == questGiver->GetEntry())
            notRequiredItem = false;

        if (notRequiredItem)
            DestroyItem(((Item*)questGiver)->GetBagSlot(), ((Item*)questGiver)->GetSlot(), true);
    }

    GiveQuestSourceItemIfNeed(pQuest);

    AdjustQuestReqItemCount(pQuest, questStatusData);

    // Some spells applied at quest activation
    SpellAreaForQuestMapBounds saBounds = sSpellMgr.GetSpellAreaForQuestMapBounds(quest_id, true);
    if (saBounds.first != saBounds.second)
    {
        uint32 zone, area;
        GetZoneAndAreaId(zone, area);

        for (SpellAreaForAreaMap::const_iterator itr = saBounds.first; itr != saBounds.second; ++itr)
            if (itr->second->autocast && itr->second->IsFitToRequirements(this, zone, area))
                if (!HasAura(itr->second->spellId, EFFECT_INDEX_0))
                    CastSpell(this, itr->second->spellId, true);
    }

    UpdateForQuestWorldObjects();
}

void Player::FullQuestComplete(uint32 questId)
{
    Quest const* pQuest = sObjectMgr.GetQuestTemplate(questId);

    // If player doesn't have the quest
    if (!pQuest || GetQuestStatus(questId) == QUEST_STATUS_NONE)
        return;

    // Add quest items for quests that require items
    for (uint8 x = 0; x < QUEST_ITEM_OBJECTIVES_COUNT; ++x)
    {
        uint32 id = pQuest->ReqItemId[x];
        uint32 count = pQuest->ReqItemCount[x];
        if (!id || !count)
            continue;

        uint32 curItemCount = GetItemCount(id, true);

        ItemPosCountVec dest;
        uint8 msg = CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, id, count - curItemCount);
        if (msg == EQUIP_ERR_OK)
        {
            Item* item = StoreNewItem(dest, id, true);
            SendNewItem(item, count - curItemCount, true, false);
        }
    }

    // All creature/GO slain/casted (not required, but otherwise it will display "Creature slain 0/10")
    for (uint8 i = 0; i < QUEST_OBJECTIVES_COUNT; ++i)
    {
        int32 creature = pQuest->ReqCreatureOrGOId[i];
        uint32 creaturecount = pQuest->ReqCreatureOrGOCount[i];

        if (uint32 spellId = pQuest->ReqSpell[i])
        {
            for (uint16 z = 0; z < creaturecount; ++z)
                CastedCreatureOrGO(creature, ObjectGuid(), spellId);
        }
        else if (creature > 0)
        {
            if (CreatureInfo const* cInfo = ObjectMgr::GetCreatureTemplate(creature))
                for (uint16 z = 0; z < creaturecount; ++z)
                    KilledMonster(cInfo, ObjectGuid());
        }
        else if (creature < 0)
        {
            for (uint16 z = 0; z < creaturecount; ++z)
                CastedCreatureOrGO(-creature, ObjectGuid(), 0);
        }
    }

    // If the quest requires reputation to complete
    if (uint32 repFaction = pQuest->GetRepObjectiveFaction())
    {
        uint32 repValue = pQuest->GetRepObjectiveValue();
        uint32 curRep = GetReputationMgr().GetReputation(repFaction);
        if (curRep < repValue)
            if (FactionEntry const* factionEntry = sObjectMgr.GetFactionEntry(repFaction))
                GetReputationMgr().SetReputation(factionEntry, repValue);
    }

    // If the quest requires money
    int32 ReqOrRewMoney = pQuest->GetRewOrReqMoney();
    if (ReqOrRewMoney < 0)
        ModifyMoney(-ReqOrRewMoney);

    CompleteQuest(questId);
}

void Player::CompleteQuest(uint32 quest_id)
{
    if (quest_id)
    {
        SetQuestStatus(quest_id, QUEST_STATUS_COMPLETE);

        uint16 log_slot = FindQuestSlot(quest_id);
        if (log_slot < MAX_QUEST_LOG_SIZE)
            SetQuestSlotState(log_slot, QUEST_STATE_COMPLETE);

        if (Quest const* qInfo = sObjectMgr.GetQuestTemplate(quest_id))
        {
            if (qInfo->HasQuestFlag(QUEST_FLAGS_AUTO_REWARDED))
                RewardQuest(qInfo, 0, this, false);
        }
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

void Player::RemoveQuest(uint32 quest_id)
{
    if (Quest const* pQuest = sObjectMgr.GetQuestTemplate(quest_id))
    {
        uint16 slot = FindQuestSlot(quest_id);

        RemoveQuestAtSlot(slot);
    }
}

void Player::RemoveQuestAtSlot(uint32 slot)
{
    if (slot < MAX_QUEST_LOG_SIZE)
    {
        if (uint32 quest = GetQuestSlotQuestId(slot))
        {
            // can't un-equip some items, reject quest cancel
            if (!TakeOrReplaceQuestStartItems(quest, true, true))
                return;

            if (Quest const* pQuest = sObjectMgr.GetQuestTemplate(quest))
            {
                if (pQuest->HasSpecialFlag(QUEST_SPECIAL_FLAG_TIMED))
                    RemoveTimedQuest(quest);

                // Destroying items on abandoning quest was added in 1.12.1.
                // https://www.engadget.com/2006-10-10-quest-items-disappear-when-abandoning-quests.html
#if SUPPORTED_CLIENT_BUILD >= CLIENT_BUILD_1_12_1
                for (int i = 0; i < QUEST_ITEM_OBJECTIVES_COUNT; i++)
                {
                    if (uint32 itemId = pQuest->ReqItemId[i])
                        if (ItemPrototype const* pItem = sObjectMgr.GetItemPrototype(itemId))
                            if (pItem->Bonding == BIND_QUEST_ITEM || pItem->Bonding == BIND_QUEST_ITEM1)
                                if (uint32 count = GetItemCount(itemId, true))
                                    DestroyItemCount(itemId, count, true, false, true);
                }
#endif
            }

            SetQuestStatus(quest, QUEST_STATUS_NONE);
        }

        SetQuestSlot(slot, 0);
    }
}

void Player::RewardQuest(Quest const* pQuest, uint32 reward, WorldObject* questEnder, bool announce)
{
    uint32 quest_id = pQuest->GetQuestId();

    for (int i = 0; i < QUEST_ITEM_OBJECTIVES_COUNT; ++i)
    {
        if (pQuest->ReqItemId[i])
            DestroyItemCount(pQuest->ReqItemId[i], pQuest->ReqItemCount[i], true);
    }

    RemoveTimedQuest(quest_id);

    if (BattleGround* bg = GetBattleGround())
        if ((bg->GetTypeID() == BATTLEGROUND_AV) && (questEnder->GetTypeId() == TYPEID_UNIT))
            ((BattleGroundAV*)bg)->HandleQuestComplete(questEnder->ToUnit(), pQuest->GetQuestId(), this);

    if (pQuest->GetRewChoiceItemsCount() > 0)
    {
        if (uint32 itemId = pQuest->RewChoiceItemId[reward])
        {
            ItemPosCountVec dest;
            if (CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, itemId, pQuest->RewChoiceItemCount[reward]) == EQUIP_ERR_OK)
            {
                Item* item = StoreNewItem(dest, itemId, true, Item::GenerateItemRandomPropertyId(itemId));
                SendNewItem(item, pQuest->RewChoiceItemCount[reward], true, false, false, false);
            }
        }
    }

    if (pQuest->GetRewItemsCount() > 0)
    {
        for (uint32 i = 0; i < pQuest->GetRewItemsCount(); ++i)
        {
            if (uint32 itemId = pQuest->RewItemId[i])
            {
                ItemPosCountVec dest;
                if (CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, itemId, pQuest->RewItemCount[i]) == EQUIP_ERR_OK)
                {
                    Item* item = StoreNewItem(dest, itemId, true, Item::GenerateItemRandomPropertyId(itemId));
                    SendNewItem(item, pQuest->RewItemCount[i], true, false, false, false);
                }
            }
        }
    }

    RewardReputation(pQuest);

    uint16 log_slot = FindQuestSlot(quest_id);
    if (log_slot < MAX_QUEST_LOG_SIZE)
        SetQuestSlot(log_slot, 0);

    QuestStatusData& q_status = mQuestStatus[quest_id];
    q_status.m_reward_choice = pQuest->RewChoiceItemId[reward];

    // Used for client inform but rewarded only in case not max level
    uint32 xp = uint32(pQuest->XPValue(this) * (GetPersonalXpRate() >= 0.0f ? GetPersonalXpRate() : sWorld.getConfig(CONFIG_FLOAT_RATE_XP_QUEST)));

    if (GetLevel() < sWorld.getConfig(CONFIG_UINT32_MAX_PLAYER_LEVEL))
        GiveXP(xp , nullptr);
    else if (int32 money = pQuest->GetRewMoneyMaxLevelAtComplete())
        LogModifyMoney(money, "QuestMaxLevel", questEnder->GetObjectGuid(), quest_id);

    // Give player extra money if GetRewOrReqMoney > 0 and get ReqMoney if negative
    LogModifyMoney(pQuest->GetRewOrReqMoney(), "Quest", questEnder->GetObjectGuid(), quest_id);

    // Send reward mail
    if (int32 mail_template_id = pQuest->GetRewMailTemplateId())
    {
        // Send mail by quest giver not ender if id is negative
        uint32 creatureId = 0;
        if (mail_template_id < 0)
        {
            mail_template_id = -mail_template_id;
            for (const auto& relation : sObjectMgr.GetCreatureQuestRelationsMap())
            {
                if (relation.second == quest_id)
                {
                    creatureId = relation.first;
                    break;
                }
            }
        }
        
        MailDraft(mail_template_id, true, GetSession()->GetSessionDbcLocale()).SetMoney(pQuest->GetRewMailMoney()).SendMailTo(this, creatureId ? MailSender(MAIL_CREATURE, creatureId) : questEnder, MAIL_CHECK_MASK_HAS_BODY, pQuest->GetRewMailDelaySecs());

    }
        
    q_status.m_rewarded = true;
    if (!pQuest->IsRepeatable())
        SetQuestStatus(quest_id, QUEST_STATUS_COMPLETE);
    else
        SetQuestStatus(quest_id, QUEST_STATUS_NONE);

    if (q_status.uState != QUEST_NEW)
        q_status.uState = QUEST_CHANGED;

    if (announce)
        SendQuestReward(pQuest, xp, questEnder);

    bool handled = false;

    switch (questEnder->GetTypeId())
    {
        case TYPEID_UNIT:
            handled = sScriptMgr.OnQuestRewarded(this, (Creature*)questEnder, pQuest);
            break;
        case TYPEID_GAMEOBJECT:
            handled = sScriptMgr.OnQuestRewarded(this, (GameObject*)questEnder, pQuest);
            break;
    }

    if (!handled && pQuest->GetQuestCompleteScript() != 0)
        GetMap()->ScriptsStart(sQuestEndScripts, pQuest->GetQuestCompleteScript(), questEnder->GetObjectGuid(), GetObjectGuid());

    // Find spell cast on spell reward if any, then find the appropriate caster and cast it
    uint32 spellId = pQuest->GetRewSpellCast() ? pQuest->GetRewSpellCast() : pQuest->GetRewSpell();

    if (spellId)
    {
        if (SpellEntry const* spellProto = sSpellMgr.GetSpellEntry(spellId))
        {
            Unit* caster = this;

            if (questEnder->GetTypeId() == TYPEID_UNIT)
            {
                for (uint8 i = 0; i < MAX_EFFECT_INDEX; ++i)
                {
                    if (spellProto->Effect[i] == SPELL_EFFECT_LEARN_SPELL ||
                        spellProto->Effect[i] == SPELL_EFFECT_CREATE_ITEM ||
                        spellProto->EffectImplicitTargetA[i] == TARGET_UNIT ||
                        spellProto->EffectImplicitTargetA[i] == TARGET_UNIT_FRIEND)
                    {
                        caster = (Unit*)questEnder;
                        break;
                    }
                }
            }

            caster->CastSpell(this, spellId, true);
        }
    }

    uint32 zone = 0;
    uint32 area = 0;

    // remove auras from spells with quest reward state limitations
    SpellAreaForQuestMapBounds saEndBounds = sSpellMgr.GetSpellAreaForQuestEndMapBounds(quest_id);
    if (saEndBounds.first != saEndBounds.second)
    {
        GetZoneAndAreaId(zone, area);

        for (SpellAreaForAreaMap::const_iterator itr = saEndBounds.first; itr != saEndBounds.second; ++itr)
            if (!itr->second->IsFitToRequirements(this, zone, area))
                RemoveAurasDueToSpell(itr->second->spellId);
    }

    // Some spells applied at quest reward
    SpellAreaForQuestMapBounds saBounds = sSpellMgr.GetSpellAreaForQuestMapBounds(quest_id, false);
    if (saBounds.first != saBounds.second)
    {
        if (!zone || !area)
            GetZoneAndAreaId(zone, area);

        for (SpellAreaForAreaMap::const_iterator itr = saBounds.first; itr != saBounds.second; ++itr)
            if (itr->second->autocast && itr->second->IsFitToRequirements(this, zone, area))
                if (!HasAura(itr->second->spellId, EFFECT_INDEX_0))
                    CastSpell(this, itr->second->spellId, true);
    }
}

void Player::FailQuest(uint32 questId)
{
    if (Quest const* pQuest = sObjectMgr.GetQuestTemplate(questId))
    {
        uint16 log_slot = FindQuestSlot(questId);
        
        if (pQuest->HasSpecialFlag(QUEST_SPECIAL_FLAG_REPEATABLE) && !pQuest->HasSpecialFlag(QUEST_SPECIAL_FLAG_TIMED))
        {
            SendQuestFailed(questId);
            RemoveQuestAtSlot(log_slot);
            return;
        }

        if (log_slot < MAX_QUEST_LOG_SIZE)
        {
            SetQuestSlotTimer(log_slot, 1);
            SetQuestSlotState(log_slot, QUEST_STATE_FAIL);
            SetQuestStatus(questId, QUEST_STATUS_FAILED);
        }

        if (pQuest->HasSpecialFlag(QUEST_SPECIAL_FLAG_TIMED))
        {
            QuestStatusData& q_status = mQuestStatus[questId];

            RemoveTimedQuest(questId);
            q_status.m_timer = 0;

            SendQuestTimerFailed(questId);
        }
        else
            SendQuestFailed(questId);
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
            SendCanTakeQuestResponse(INVALIDREASON_DONT_HAVE_REQ);

        return false;
    }

    return true;
}

bool Player::SatisfyQuestCondition(Quest const* qInfo, bool msg) const
{
    if (uint32 conditionId = qInfo->GetRequiredCondition())
    {
        bool result = IsConditionSatisfied(conditionId, this, GetMap(), nullptr, CONDITION_FROM_QUEST);

        if (!result && msg)
            SendCanTakeQuestResponse(INVALIDREASON_DONT_HAVE_REQ);

        return result;
    }
    return true;
}

bool Player::SatisfyQuestLevel(Quest const* qInfo, bool msg) const
{
    if (GetLevel() < qInfo->GetMinLevel())
    {
        if (msg)
            SendCanTakeQuestResponse(INVALIDREASON_DONT_HAVE_REQ);

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
        GetSession()->SendPacket(&data);
        DEBUG_LOG("WORLD: Sent SMSG_QUESTLOG_FULL");
    }
    return false;
}

bool Player::SatisfyQuestPreviousQuest(Quest const* qInfo, bool msg) const
{
    // No previous quest (might be first quest in a series)
    if (qInfo->prevQuests.empty())
        return true;

    for (const auto prevQuest : qInfo->prevQuests)
    {
        uint32 prevId = abs(prevQuest);

        QuestStatusMap::const_iterator i_prevstatus = mQuestStatus.find(prevId);
        Quest const* qPrevInfo = sObjectMgr.GetQuestTemplate(prevId);

        if (qPrevInfo && i_prevstatus != mQuestStatus.end())
        {
            // If any of the positive previous quests completed, return true
            if (prevQuest > 0 && i_prevstatus->second.m_rewarded)
            {
                // skip one-from-all exclusive group
                if (qPrevInfo->GetExclusiveGroup() >= 0)
                    return true;

                // each-from-all exclusive group ( < 0)
                // can be start if only all quests in prev quest exclusive group completed and rewarded
                ExclusiveQuestGroupsMapBounds bounds = sObjectMgr.GetExclusiveQuestGroupsMapBounds(qPrevInfo->GetExclusiveGroup());

                MANGOS_ASSERT(bounds.first != bounds.second); // always must be found if qPrevInfo->ExclusiveGroup != 0

                for (ExclusiveQuestGroupsMap::const_iterator iter2 = bounds.first; iter2 != bounds.second; ++iter2)
                {
                    uint32 exclude_Id = iter2->second;

                    // skip checked quest id, only state of other quests in group is interesting
                    if (exclude_Id == prevId)
                        continue;

                    QuestStatusMap::const_iterator i_exstatus = mQuestStatus.find(exclude_Id);

                    // alternative quest from group also must be completed and rewarded(reported)
                    if (i_exstatus == mQuestStatus.end() || !i_exstatus->second.m_rewarded)
                    {
                        if (msg)
                            SendCanTakeQuestResponse(INVALIDREASON_DONT_HAVE_REQ);

                        return false;
                    }
                }
                return true;
            }
            // If any of the negative previous quests active, return true
            if (prevQuest < 0 && IsCurrentQuest(prevId))
            {
                // skip one-from-all exclusive group
                if (qPrevInfo->GetExclusiveGroup() >= 0)
                    return true;

                // each-from-all exclusive group ( < 0)
                // can be start if only all quests in prev quest exclusive group active
                ExclusiveQuestGroupsMapBounds bounds = sObjectMgr.GetExclusiveQuestGroupsMapBounds(qPrevInfo->GetExclusiveGroup());

                MANGOS_ASSERT(bounds.first != bounds.second); // always must be found if qPrevInfo->ExclusiveGroup != 0

                for (ExclusiveQuestGroupsMap::const_iterator iter2 = bounds.first; iter2 != bounds.second; ++iter2)
                {
                    uint32 exclude_Id = iter2->second;

                    // skip checked quest id, only state of other quests in group is interesting
                    if (exclude_Id == prevId)
                        continue;

                    // alternative quest from group also must be active
                    if (!IsCurrentQuest(exclude_Id))
                    {
                        if (msg)
                            SendCanTakeQuestResponse(INVALIDREASON_DONT_HAVE_REQ);

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
        SendCanTakeQuestResponse(INVALIDREASON_DONT_HAVE_REQ);

    return false;
}

bool Player::SatisfyQuestClass(Quest const* qInfo, bool msg) const
{
    uint32 reqClass = qInfo->GetRequiredClasses();

    if (reqClass == 0)
        return true;

    if ((reqClass & GetClassMask()) == 0)
    {
        if (msg)
            SendCanTakeQuestResponse(INVALIDREASON_DONT_HAVE_REQ);

        return false;
    }

    return true;
}

bool Player::SatisfyQuestRace(Quest const* qInfo, bool msg) const
{
    uint32 reqraces = qInfo->GetRequiredRaces();

    if (reqraces == 0)
        return true;

    if ((reqraces & GetRaceMask()) == 0)
    {
        if (msg)
            SendCanTakeQuestResponse(INVALIDREASON_QUEST_FAILED_WRONG_RACE);

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
            SendCanTakeQuestResponse(INVALIDREASON_DONT_HAVE_REQ);

        return false;
    }

    uint32 fIdMax = qInfo->GetRequiredMaxRepFaction();      //Max required rep
    if (fIdMax && GetReputationMgr().GetReputation(fIdMax) >= qInfo->GetRequiredMaxRepValue())
    {
        if (msg)
            SendCanTakeQuestResponse(INVALIDREASON_DONT_HAVE_REQ);

        return false;
    }

    return true;
}

bool Player::SatisfyQuestStatus(Quest const* qInfo, bool msg) const
{
    QuestStatusMap::const_iterator itr = mQuestStatus.find(qInfo->GetQuestId());

    if (itr != mQuestStatus.end() && itr->second.m_status != QUEST_STATUS_NONE)
    {
        if (msg)
            SendCanTakeQuestResponse(INVALIDREASON_QUEST_ALREADY_ON);

        return false;
    }

    return true;
}

bool Player::SatisfyQuestTimed(Quest const* qInfo, bool msg) const
{
    if (!m_timedquests.empty() && qInfo->HasSpecialFlag(QUEST_SPECIAL_FLAG_TIMED))
    {
        if (msg)
            SendCanTakeQuestResponse(INVALIDREASON_QUEST_ONLY_ONE_TIMED);

        return false;
    }

    return true;
}

bool Player::SatisfyQuestExclusiveGroup(Quest const* qInfo, bool msg) const
{
    // non positive exclusive group, if > 0 then can be start if any other quest in exclusive group already started/completed
    if (qInfo->GetExclusiveGroup() <= 0)
        return true;

    ExclusiveQuestGroupsMapBounds bounds = sObjectMgr.GetExclusiveQuestGroupsMapBounds(qInfo->GetExclusiveGroup());

    MANGOS_ASSERT(bounds.first != bounds.second);           // must always be found if qInfo->ExclusiveGroup != 0

    for (ExclusiveQuestGroupsMap::const_iterator iter = bounds.first; iter != bounds.second; ++iter)
    {
        uint32 exclude_Id = iter->second;

        // skip checked quest id, only state of other quests in group is interesting
        if (exclude_Id == qInfo->GetQuestId())
            continue;

        QuestStatusMap::const_iterator i_exstatus = mQuestStatus.find(exclude_Id);

        // alternative quest already started or completed
        if (i_exstatus != mQuestStatus.end() &&
                (i_exstatus->second.m_status == QUEST_STATUS_COMPLETE || i_exstatus->second.m_status == QUEST_STATUS_INCOMPLETE))
        {
            if (msg)
                SendCanTakeQuestResponse(INVALIDREASON_DONT_HAVE_REQ);

            return false;
        }
    }

    return true;
}

bool Player::SatisfyQuestNextChain(Quest const* qInfo, bool msg) const
{
    if (!qInfo->GetNextQuestInChain())
        return true;

    // next quest in chain already started or completed
    QuestStatusMap::const_iterator itr = mQuestStatus.find(qInfo->GetNextQuestInChain());
    if (itr != mQuestStatus.end() &&
            (itr->second.m_status == QUEST_STATUS_COMPLETE || itr->second.m_status == QUEST_STATUS_INCOMPLETE))
    {
        if (msg)
            SendCanTakeQuestResponse(INVALIDREASON_DONT_HAVE_REQ);

        return false;
    }

    // check for all quests further up the chain
    // only necessary if there are quest chains with more than one quest that can be skipped
    //return SatisfyQuestNextChain(qInfo->GetNextQuestInChain(), msg);
    return true;
}

bool Player::SatisfyQuestPrevChain(Quest const* qInfo, bool msg) const
{
    // No previous quest in chain
    if (qInfo->prevChainQuests.empty())
        return true;

    for (const auto prevId : qInfo->prevChainQuests)
    {
        // If any of the previous quests in chain active, return false
        if (IsCurrentQuest(prevId))
        {
            if (msg)
                SendCanTakeQuestResponse(INVALIDREASON_DONT_HAVE_REQ);

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

bool Player::CanGiveQuestSourceItemIfNeed(Quest const* pQuest, ItemPosCountVec* dest) const
{
    if (uint32 srcitem = pQuest->GetSrcItemId())
    {
        uint32 count = pQuest->GetSrcItemCount();

        // player already have max amount required item (including bank), just report success
        uint32 has_count = GetItemCount(srcitem, true);
        if (has_count >= count)
            return true;

        count -= has_count;                                 // real need amount

        InventoryResult msg;
        if (!dest)
        {
            ItemPosCountVec destTemp;
            msg = CanStoreNewItem(NULL_BAG, NULL_SLOT, destTemp, srcitem, count);
        }
        else
            msg = CanStoreNewItem(NULL_BAG, NULL_SLOT, *dest, srcitem, count);

        if (msg == EQUIP_ERR_OK)
            return true;
        else
        {
            if (msg == EQUIP_ERR_INVENTORY_FULL)
                SendQuestFailedAtTaker(pQuest->GetQuestId(), INVALIDREASON_QUEST_FAILED_INVENTORY_FULL);
            else if (msg == EQUIP_ERR_CANT_CARRY_MORE_OF_THIS)
                SendQuestFailedAtTaker(pQuest->GetQuestId(), INVALIDREASON_QUEST_FAILED_DUPLICATE_ITEM);
            else
                SendEquipError(msg, nullptr, nullptr, srcitem);
        }

        return false;
    }

    return true;
}

void Player::GiveQuestSourceItemIfNeed(Quest const* pQuest)
{
    ItemPosCountVec dest;
    if (CanGiveQuestSourceItemIfNeed(pQuest, &dest) && !dest.empty())
    {
        uint32 count = 0;
        for (const auto& c_itr : dest)
            count += c_itr.count;

        Item* item = StoreNewItem(dest, pQuest->GetSrcItemId(), true);
        SendNewItem(item, count, true, false);
    }
}


bool Player::TakeOrReplaceQuestStartItems(uint32 quest_id, bool msg, bool giveQuestStartItem)
{
    Quest const* qInfo = sObjectMgr.GetQuestTemplate(quest_id);

    if (!qInfo)
        return true;

    uint32 srcItemID = qInfo->GetSrcItemId();

    if (0 == srcItemID)
        return true;

    // If nullptr, someone messed up in DB
    ItemPrototype const* pItem = sObjectMgr.GetItemPrototype(srcItemID);

    if (!pItem)
        return true;

    uint32 count = qInfo->GetSrcItemCount();

    if (giveQuestStartItem && quest_id == pItem->StartQuest)
    {
        // Quest-starting item and item given at quest start identical. Just leave it.
        return true;
    }
    else
    {
        // Can't destroy items in certain cases.
        InventoryResult res = CanUnequipItems(srcItemID, count);

        if (res != EQUIP_ERR_OK)
        {
            if (msg)
                SendEquipError(res, nullptr, nullptr, srcItemID);

            return false;
        }

        // Additional check to prevent possible unlimited gold
        if (!HasItemCount(srcItemID, count, true))
            return true;

        // Start- and given item not the same, destroy it.
        DestroyItemCount(srcItemID, count, true, true);

        // Replace item, if requested
        if (giveQuestStartItem)
        {
            if (uint32 questStartingItemID = sObjectMgr.GetQuestStartingItemID(quest_id))
                AddItem(questStartingItemID, count);

        }

    }

    return true;
}

bool Player::GetQuestRewardStatus(uint32 quest_id) const
{
    Quest const* qInfo = sObjectMgr.GetQuestTemplate(quest_id);
    if (qInfo)
    {
        // for repeatable quests: rewarded field is set after first reward only to prevent getting XP more than once
        QuestStatusMap::const_iterator itr = mQuestStatus.find(quest_id);
        if (itr != mQuestStatus.end() && itr->second.m_status != QUEST_STATUS_NONE
                && !qInfo->IsRepeatable())
            return itr->second.m_rewarded;

        return false;
    }
    return false;
}

QuestStatusData const* Player::GetQuestStatusData(uint32 quest_id) const
{
    auto it = mQuestStatus.find(quest_id);

    if (it != mQuestStatus.end())
    {
        return &it->second;
    }

    return nullptr;
}

QuestStatus Player::GetQuestStatus(uint32 quest_id) const
{
    if (quest_id)
    {
        QuestStatusMap::const_iterator itr = mQuestStatus.find(quest_id);
        if (itr != mQuestStatus.end())
            return itr->second.m_status;
    }
    return QUEST_STATUS_NONE;
}

bool Player::CanShareQuest(uint32 quest_id) const
{
    if (Quest const* qInfo = sObjectMgr.GetQuestTemplate(quest_id))
        if (qInfo->HasQuestFlag(QUEST_FLAGS_SHARABLE))
            return IsCurrentQuest(quest_id);

    return false;
}

void Player::SetQuestStatus(uint32 quest_id, QuestStatus status)
{
    if (sObjectMgr.GetQuestTemplate(quest_id))
    {
        QuestStatusData& q_status = mQuestStatus[quest_id];

        q_status.m_status = status;

        if (q_status.uState != QUEST_NEW)
            q_status.uState = QUEST_CHANGED;

        UpdateForQuestWorldObjects();
    }
}

void Player::AdjustQuestReqItemCount(Quest const* pQuest, QuestStatusData& questStatusData)
{
    if (pQuest->HasSpecialFlag(QUEST_SPECIAL_FLAG_DELIVER))
    {
        for (int i = 0; i < QUEST_ITEM_OBJECTIVES_COUNT; ++i)
        {
            uint32 reqItemCount = pQuest->ReqItemCount[i];
            if (reqItemCount != 0)
            {
                uint32 curItemCount = GetItemCount(pQuest->ReqItemId[i], true);

                questStatusData.m_itemcount[i] = std::min(curItemCount, reqItemCount);
                if (questStatusData.uState != QUEST_NEW) questStatusData.uState = QUEST_CHANGED;
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

void Player::AreaExploredOrEventHappens(uint32 questId)
{
    if (questId)
    {
        uint16 log_slot = FindQuestSlot(questId);
        if (log_slot < MAX_QUEST_LOG_SIZE)
        {
            QuestStatusData& q_status = mQuestStatus[questId];

            if (!q_status.m_explored)
            {
                SetQuestSlotState(log_slot, QUEST_STATE_COMPLETE);
                SendQuestCompleteEvent(questId);
                q_status.m_explored = true;

                if (q_status.uState != QUEST_NEW)
                    q_status.uState = QUEST_CHANGED;
            }
        }
        if (CanCompleteQuest(questId))
            CompleteQuest(questId);
    }
}

//not used in mangosd, function for external script library
void Player::GroupEventHappens(uint32 questId, WorldObject const* pEventObject)
{
    if (Group* pGroup = GetGroup())
    {
        for (GroupReference* itr = pGroup->GetFirstMember(); itr != nullptr; itr = itr->next())
        {
            Player* pGroupGuy = itr->getSource();

            // for any leave or dead (with not released body) group member at appropriate distance
            if (pGroupGuy && pGroupGuy->IsAtGroupRewardDistance(pEventObject) && !pGroupGuy->HasFlag(PLAYER_FLAGS, PLAYER_FLAGS_GHOST))
                pGroupGuy->AreaExploredOrEventHappens(questId);
        }
    }
    else
        AreaExploredOrEventHappens(questId);
}

void Player::GroupEventFailHappens(uint32 questId)
{
    if (Group* pGroup = GetGroup())
    {
        for (GroupReference* itr = pGroup->GetFirstMember(); itr != nullptr; itr = itr->next())
        {
            Player* pGroupGuy = itr->getSource();
            
            // Fail regardless of distance
            if (pGroupGuy && pGroupGuy->GetQuestStatus(questId) == QUEST_STATUS_INCOMPLETE)
                pGroupGuy->FailQuest(questId);
        }
    }
    else if (GetQuestStatus(questId) == QUEST_STATUS_INCOMPLETE)
        FailQuest(questId);
}

void Player::ItemAddedQuestCheck(uint32 entry, uint32 count)
{
    for (int i = 0; i < MAX_QUEST_LOG_SIZE; ++i)
    {
        uint32 questid = GetQuestSlotQuestId(i);
        if (questid == 0)
            continue;

        QuestStatusData& q_status = mQuestStatus[questid];

        if (q_status.m_status != QUEST_STATUS_INCOMPLETE)
            continue;

        Quest const* qInfo = sObjectMgr.GetQuestTemplate(questid);
        if (!qInfo || !qInfo->HasSpecialFlag(QUEST_SPECIAL_FLAG_DELIVER))
            continue;

        for (int j = 0; j < QUEST_ITEM_OBJECTIVES_COUNT; ++j)
        {
            uint32 reqitem = qInfo->ReqItemId[j];
            if (reqitem == entry)
            {
                uint32 reqItemCount = qInfo->ReqItemCount[j];
                uint32 curItemCount = q_status.m_itemcount[j];
                if (curItemCount < reqItemCount)
                {
                    uint16 newItemCount = std::min<uint16>(q_status.m_itemcount[j] + count, reqItemCount);
                    q_status.m_itemcount[j] = newItemCount;
                    if (q_status.uState != QUEST_NEW)
                        q_status.uState = QUEST_CHANGED;

                    if (entry != qInfo->GetSrcItemId())
                        SendQuestUpdateAddItem(qInfo, j, curItemCount, newItemCount - curItemCount);
                }

                if (CanCompleteQuest(questid))
                    CompleteQuest(questid);
                break;
            }
        }
    }
    UpdateForQuestWorldObjects();
}

void Player::ItemRemovedQuestCheck(uint32 entry, uint32 count)
{
    for (int i = 0; i < MAX_QUEST_LOG_SIZE; ++i)
    {
        uint32 questid = GetQuestSlotQuestId(i);
        if (!questid)
            continue;

        Quest const* qInfo = sObjectMgr.GetQuestTemplate(questid);
        if (!qInfo)
            continue;
        if (!qInfo->HasSpecialFlag(QUEST_SPECIAL_FLAG_DELIVER))
            continue;

        for (int j = 0; j < QUEST_ITEM_OBJECTIVES_COUNT; ++j)
        {
            uint32 reqitem = qInfo->ReqItemId[j];
            if (reqitem == entry)
            {
                QuestStatusData& q_status = mQuestStatus[questid];

                uint32 reqItemCount = qInfo->ReqItemCount[j];
                uint32 curItemCount = q_status.m_itemcount[j];

                // With non-quest items, you can have more than the required by the quest.
                if (curItemCount >= reqItemCount)
                    curItemCount = GetItemCount(entry, false);

                uint16 newItemCount = (count > curItemCount) ? 0 : curItemCount - count;
                newItemCount = std::min<uint16>(newItemCount, reqItemCount);

                if (newItemCount != reqItemCount)
                {
                    q_status.m_itemcount[j] = newItemCount;
                    if (q_status.uState != QUEST_NEW)
                        q_status.uState = QUEST_CHANGED;
                    IncompleteQuest(questid);
                }
                break;
            }
        }
    }
    UpdateForQuestWorldObjects();
}

void Player::KilledMonster(CreatureInfo const* cInfo, ObjectGuid guid)
{
    if (cInfo->entry)
        KilledMonsterCredit(cInfo->entry, guid);
}

void Player::KilledMonsterCredit(uint32 entry, ObjectGuid guid)
{
    uint32 addkillcount = 1;

    for (int i = 0; i < MAX_QUEST_LOG_SIZE; ++i)
    {
        uint32 questid = GetQuestSlotQuestId(i);
        if (!questid)
            continue;

        Quest const* qInfo = sObjectMgr.GetQuestTemplate(questid);
        if (!qInfo)
            continue;
        // just if !ingroup || !noraidgroup || raidgroup
        QuestStatusData& q_status = mQuestStatus[questid];
        if (q_status.m_status == QUEST_STATUS_INCOMPLETE && (!GetGroup() || !GetGroup()->isRaidGroup() || qInfo->IsAllowedInRaid()))
        {
            if (qInfo->HasSpecialFlag(QUEST_SPECIAL_FLAG_KILL_OR_CAST))
            {
                for (int j = 0; j < QUEST_OBJECTIVES_COUNT; ++j)
                {
                    // skip GO activate objective or none
                    if (qInfo->ReqCreatureOrGOId[j] <= 0)
                        continue;

                    // skip Cast at creature objective
                    if (qInfo->ReqSpell[j] != 0)
                        continue;

                    uint32 reqkill = qInfo->ReqCreatureOrGOId[j];

                    if (reqkill == entry)
                    {
                        uint32 reqkillcount = qInfo->ReqCreatureOrGOCount[j];
                        uint32 curkillcount = q_status.m_creatureOrGOcount[j];
                        if (curkillcount < reqkillcount)
                        {
                            q_status.m_creatureOrGOcount[j] = curkillcount + addkillcount;
                            if (q_status.uState != QUEST_NEW)
                                q_status.uState = QUEST_CHANGED;

                            SendQuestUpdateAddCreatureOrGo(qInfo, guid, j, q_status.m_creatureOrGOcount[j]);
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

void Player::CastedCreatureOrGO(uint32 entry, ObjectGuid guid, uint32 spellId, bool originalCaster)
{
    bool isCreature = guid.IsCreature();

    uint32 addCastCount = 1;
    for (int i = 0; i < MAX_QUEST_LOG_SIZE; ++i)
    {
        uint32 questid = GetQuestSlotQuestId(i);
        if (!questid)
            continue;

        Quest const* qInfo = sObjectMgr.GetQuestTemplate(questid);
        if (!qInfo)
            continue;

        if (!originalCaster && !qInfo->HasQuestFlag(QUEST_FLAGS_SHARABLE))
            continue;

        if (!qInfo->HasSpecialFlag(QUEST_SPECIAL_FLAG_KILL_OR_CAST))
            continue;

        QuestStatusData& q_status = mQuestStatus[questid];

        if (q_status.m_status != QUEST_STATUS_INCOMPLETE)
            continue;

        for (int j = 0; j < QUEST_OBJECTIVES_COUNT; ++j)
        {
            // skip kill creature objective (0) or wrong spell casts
            if (qInfo->ReqSpell[j] != spellId)
                continue;

            uint32 reqTarget = 0;

            if (isCreature)
            {
                // creature activate objectives
                if (qInfo->ReqCreatureOrGOId[j] > 0)
                    // checked at quest_template loading
                    reqTarget = qInfo->ReqCreatureOrGOId[j];
            }
            else
            {
                // GO activate objective
                if (qInfo->ReqCreatureOrGOId[j] < 0)
                    // checked at quest_template loading
                    reqTarget = - qInfo->ReqCreatureOrGOId[j];
            }

            // other not this creature/GO related objectives
            if (reqTarget != entry)
                continue;

            uint32 reqCastCount = qInfo->ReqCreatureOrGOCount[j];
            uint32 curCastCount = q_status.m_creatureOrGOcount[j];
            if (curCastCount < reqCastCount)
            {
                q_status.m_creatureOrGOcount[j] = curCastCount + addCastCount;
                if (q_status.uState != QUEST_NEW)
                    q_status.uState = QUEST_CHANGED;

                SendQuestUpdateAddCreatureOrGo(qInfo, guid, j, q_status.m_creatureOrGOcount[j]);
            }

            if (CanCompleteQuest(questid))
                CompleteQuest(questid);

            // same objective target can be in many active quests, but not in 2 objectives for single quest (code optimization).
            break;
        }
    }
}

void Player::TalkedToCreature(uint32 entry, ObjectGuid guid)
{
    uint32 addTalkCount = 1;
    for (int i = 0; i < MAX_QUEST_LOG_SIZE; ++i)
    {
        uint32 questid = GetQuestSlotQuestId(i);
        if (!questid)
            continue;

        Quest const* qInfo = sObjectMgr.GetQuestTemplate(questid);
        if (!qInfo)
            continue;

        QuestStatusData& q_status = mQuestStatus[questid];

        if (q_status.m_status == QUEST_STATUS_INCOMPLETE)
        {
            if (qInfo->HasSpecialFlag(QuestSpecialFlags(QUEST_SPECIAL_FLAG_KILL_OR_CAST | QUEST_SPECIAL_FLAG_SPEAKTO)) 
                && !qInfo->HasSpecialFlag(QuestSpecialFlags(QUEST_SPECIAL_FLAG_EXPLORATION_OR_EVENT)))
            {
                for (int j = 0; j < QUEST_OBJECTIVES_COUNT; ++j)
                {
                    // skip spell casts and Gameobject objectives
                    if (qInfo->ReqSpell[j] > 0 || qInfo->ReqCreatureOrGOId[j] < 0)
                        continue;

                    uint32 reqTarget = 0;

                    if (qInfo->ReqCreatureOrGOId[j] > 0)    // creature activate objectives
                        // checked at quest_template loading
                        reqTarget = qInfo->ReqCreatureOrGOId[j];
                    else
                        continue;

                    if (reqTarget == entry)
                    {
                        uint32 reqTalkCount = qInfo->ReqCreatureOrGOCount[j];
                        uint32 curTalkCount = q_status.m_creatureOrGOcount[j];
                        if (curTalkCount < reqTalkCount)
                        {
                            q_status.m_creatureOrGOcount[j] = curTalkCount + addTalkCount;
                            if (q_status.uState != QUEST_NEW) q_status.uState = QUEST_CHANGED;

                            SendQuestUpdateAddCreatureOrGo(qInfo, guid, j, q_status.m_creatureOrGOcount[j]);
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

void Player::LogModifyMoney(int32 d, char const* type, ObjectGuid fromGuid, uint32 data)
{
    // Always log GM transactions regardless of threshold
    if (uint32(abs(d)) > sWorld.getConfig(CONFIG_UINT32_LOG_MONEY_TRADES_TRESHOLD) || GetSession()->GetSecurity() > SEC_PLAYER)
    {
        sLog.out(LOG_MONEY_TRADES, "[%s] %s gets %ic (data: %u|%s)", type, GetShortDescription().c_str(), d, data, fromGuid.GetString().c_str());
        if (d > 0)
            sWorld.LogMoneyTrade(fromGuid, GetObjectGuid(), d, type, data);
        else
            sWorld.LogMoneyTrade(GetObjectGuid(), fromGuid, -d, type, data);
    }
    ModifyMoney(d);
}

void Player::MoneyChanged(uint32 count)
{
    for (int i = 0; i < MAX_QUEST_LOG_SIZE; ++i)
    {
        uint32 questid = GetQuestSlotQuestId(i);
        if (!questid)
            continue;

        Quest const* qInfo = sObjectMgr.GetQuestTemplate(questid);
        if (qInfo && qInfo->GetRewOrReqMoney() < 0)
        {
            QuestStatusData& q_status = mQuestStatus[questid];

            if (q_status.m_status == QUEST_STATUS_INCOMPLETE)
            {
                if (int32(count) >= -qInfo->GetRewOrReqMoney())
                {
                    if (CanCompleteQuest(questid))
                        CompleteQuest(questid);
                }
            }
            else if (q_status.m_status == QUEST_STATUS_COMPLETE)
            {
                if (int32(count) < -qInfo->GetRewOrReqMoney())
                    IncompleteQuest(questid);
            }
        }
    }
}

void Player::ReputationChanged(FactionEntry const* factionEntry)
{
    for (int i = 0; i < MAX_QUEST_LOG_SIZE; ++i)
    {
        if (uint32 questid = GetQuestSlotQuestId(i))
        {
            if (Quest const* qInfo = sObjectMgr.GetQuestTemplate(questid))
            {
                if (qInfo->GetRepObjectiveFaction() == factionEntry->ID)
                {
                    QuestStatusData& q_status = mQuestStatus[questid];
                    if (q_status.m_status == QUEST_STATUS_INCOMPLETE)
                    {
                        if (GetReputationMgr().GetReputation(factionEntry) >= qInfo->GetRepObjectiveValue())
                            if (CanCompleteQuest(questid))
                                CompleteQuest(questid);
                    }
                    else if (q_status.m_status == QUEST_STATUS_COMPLETE)
                    {
                        if (GetReputationMgr().GetReputation(factionEntry) < qInfo->GetRepObjectiveValue())
                            IncompleteQuest(questid);
                    }
                }
            }
        }
    }
}

bool Player::HasQuestForItem(uint32 itemid) const
{
    for (int i = 0; i < MAX_QUEST_LOG_SIZE; ++i)
    {
        uint32 questid = GetQuestSlotQuestId(i);
        if (questid == 0)
            continue;

        QuestStatusMap::const_iterator qs_itr = mQuestStatus.find(questid);
        if (qs_itr == mQuestStatus.end())
            continue;

        QuestStatusData const& q_status = qs_itr->second;

        if (q_status.m_status == QUEST_STATUS_INCOMPLETE)
        {
            Quest const* qinfo = sObjectMgr.GetQuestTemplate(questid);
            if (!qinfo)
                continue;

            // hide quest if player is in raid-group and quest is no raid quest
            if (GetGroup() && GetGroup()->isRaidGroup() && !qinfo->IsAllowedInRaid() && !InBattleGround())
                continue;

            // There should be no mixed ReqItem/ReqSource drop
            // This part for ReqItem drop
            for (int j = 0; j < QUEST_ITEM_OBJECTIVES_COUNT; ++j)
            {
                if (itemid == qinfo->ReqItemId[j] && q_status.m_itemcount[j] < qinfo->ReqItemCount[j])
                    return true;
            }
            // This part - for ReqSource
            for (int j = 0; j < QUEST_SOURCE_ITEM_IDS_COUNT; ++j)
            {
                // examined item is a source item
                if (qinfo->ReqSourceId[j] == itemid)
                {
                    ItemPrototype const* pProto = ObjectMgr::GetItemPrototype(itemid);

                    // 'unique' item
                    if (pProto->MaxCount && GetItemCount(itemid, true) < pProto->MaxCount)
                        return true;

                    // allows custom amount drop when not 0
                    if (qinfo->ReqSourceCount[j])
                    {
                        if (GetItemCount(itemid, true) < qinfo->ReqSourceCount[j])
                            return true;
                    }
                    else if (GetItemCount(itemid, true) < pProto->Stackable)
                        return true;
                }
            }
        }
    }
    return false;
}

// Used for quests having some event (explore, escort, "external event") as quest objective.
void Player::SendQuestCompleteEvent(uint32 quest_id) const
{
    if (quest_id)
    {
        WorldPacket data(SMSG_QUESTUPDATE_COMPLETE, 4);
        data << uint32(quest_id);
        GetSession()->SendPacket(&data);
        DEBUG_LOG("WORLD: Sent SMSG_QUESTUPDATE_COMPLETE quest = %u", quest_id);
    }
}

void Player::SendQuestReward(Quest const* pQuest, uint32 XP, Object* questGiver) const
{
    uint32 questid = pQuest->GetQuestId();
    DEBUG_LOG("WORLD: Sent SMSG_QUESTGIVER_QUEST_COMPLETE quest = %u", questid);
    WorldPacket data(SMSG_QUESTGIVER_QUEST_COMPLETE, (4 + 4 + 4 + 4 + 4 + pQuest->GetRewItemsCount() * 8));
    data << questid;
    data << uint32(0x03);

    if (GetLevel() < sWorld.getConfig(CONFIG_UINT32_MAX_PLAYER_LEVEL))
    {
        data << XP;
        data << uint32(pQuest->GetRewOrReqMoney());
    }
    else
    {
        data << uint32(0);
        data << uint32(pQuest->GetRewOrReqMoney() + pQuest->GetRewMoneyMaxLevelAtComplete());
    }
    data << uint32(pQuest->GetRewItemsCount());             // max is 5

    for (uint32 i = 0; i < pQuest->GetRewItemsCount(); ++i)
    {
        if (pQuest->RewItemId[i] > 0)
            data << pQuest->RewItemId[i] << pQuest->RewItemCount[i];
        else
            data << uint32(0) << uint32(0);
    }
    GetSession()->SendPacket(&data);
}

/// Sent when a quest is failed to be given off at questtaker. Specifically handled reasons:
/// INVALIDREASON_QUEST_FAILED_INVENTORY_FULL=4 (or 50)
/// INVALIDREASON_QUEST_FAILED_DUPLICATE_ITEM=17
void Player::SendQuestFailedAtTaker(uint32 quest_id, uint32 reason) const
{
    if (quest_id)
    {
        WorldPacket data(SMSG_QUESTGIVER_QUEST_FAILED, 8);
        data << uint32(quest_id);
        data << uint32(reason);
        GetSession()->SendPacket(&data);
        DEBUG_LOG("WORLD: Sent SMSG_QUESTGIVER_QUEST_FAILED");
    }
}

void Player::SendQuestFailed(uint32 quest_id) const
{
    if (quest_id)
    {
        WorldPacket data(SMSG_QUESTUPDATE_FAILED, 4);
        data << quest_id;
        GetSession()->SendPacket(&data);
        DEBUG_LOG("WORLD: Sent SMSG_QUESTUPDATE_FAILED");
    }
}

void Player::SendQuestTimerFailed(uint32 quest_id) const
{
    if (quest_id)
    {
        WorldPacket data(SMSG_QUESTUPDATE_FAILEDTIMER, 4);
        data << uint32(quest_id);
        GetSession()->SendPacket(&data);
        DEBUG_LOG("WORLD: Sent SMSG_QUESTUPDATE_FAILEDTIMER");
    }
}

void Player::SendCanTakeQuestResponse(uint32 msg) const
{
    WorldPacket data(SMSG_QUESTGIVER_QUEST_INVALID, 4);
    data << uint32(msg);
    GetSession()->SendPacket(&data);
    DEBUG_LOG("WORLD: Sent SMSG_QUESTGIVER_QUEST_INVALID");
}

void Player::SendQuestConfirmAccept(Quest const* pQuest, Player* pReceiver) const
{
    if (pReceiver)
    {
        std::string strTitle = pQuest->GetTitle();

        int loc_idx = pReceiver->GetSession()->GetSessionDbLocaleIndex();

        if (loc_idx >= 0)
        {
            if (QuestLocale const* pLocale = sObjectMgr.GetQuestLocale(pQuest->GetQuestId()))
            {
                if ((int32)pLocale->Title.size() > loc_idx && !pLocale->Title[loc_idx].empty())
                    strTitle = pLocale->Title[loc_idx];
            }
        }

        WorldPacket data(SMSG_QUEST_CONFIRM_ACCEPT, (4 + strTitle.size() + 8));
        data << uint32(pQuest->GetQuestId());
        data << strTitle;
        data << GetObjectGuid();
        pReceiver->GetSession()->SendPacket(&data);

        DEBUG_LOG("WORLD: Sent SMSG_QUEST_CONFIRM_ACCEPT");
    }
}

void Player::SendPushToPartyResponse(Player* pPlayer, uint8 msg) const
{
    if (pPlayer)
    {
        WorldPacket data(MSG_QUEST_PUSH_RESULT, (8 + 1));
        data << pPlayer->GetObjectGuid();
        data << uint8(msg);                                 // enum QuestShareMessages
        GetSession()->SendPacket(&data);
        DEBUG_LOG("WORLD: Sent MSG_QUEST_PUSH_RESULT");
    }
}

void Player::SendQuestUpdateAddItem(Quest const* pQuest, uint32 item_idx, uint32 current, uint32 count)
{
    MANGOS_ASSERT(count < 64 && "Quest slot count store is limited to 6 bits 2^6 = 64 (0..63)");

    // Update quest watcher and fire QUEST_WATCH_UPDATE
    DEBUG_LOG("WORLD: Sent SMSG_QUESTUPDATE_ADD_ITEM");
    WorldPacket data(SMSG_QUESTUPDATE_ADD_ITEM, (4 + 4));
    data << pQuest->ReqItemId[item_idx];
    data << count;
    GetSession()->SendPacket(&data);

    // Update player field and fire UNIT_QUEST_LOG_CHANGED for self
    uint16 slot = FindQuestSlot(pQuest->GetQuestId());
    if (slot < MAX_QUEST_LOG_SIZE)
        SetQuestSlotCounter(slot + pQuest->GetReqCreatureOrGOcount(), uint8(item_idx), uint8(current + count));
}

void Player::SendQuestUpdateAddCreatureOrGo(Quest const* pQuest, ObjectGuid guid, uint32 creatureOrGO_idx, uint32 count)
{
    MANGOS_ASSERT(count < 64 && "Quest slot count store is limited to 6 bits 2^6 = 64 (0..63)");

    int32 entry = pQuest->ReqCreatureOrGOId[ creatureOrGO_idx ];
    if (entry < 0)
        // client expected gameobject template id in form (id|0x80000000)
        entry = (-entry) | 0x80000000;

    // Update quest watcher and fire QUEST_WATCH_UPDATE
    WorldPacket data(SMSG_QUESTUPDATE_ADD_KILL, (4 * 4 + 8));
    DEBUG_LOG("WORLD: Sent SMSG_QUESTUPDATE_ADD_KILL");
    data << uint32(pQuest->GetQuestId());
    data << uint32(entry);
    data << uint32(count);
    data << uint32(pQuest->ReqCreatureOrGOCount[ creatureOrGO_idx ]);
    data << guid;
    GetSession()->SendPacket(&data);

    // Update player field and fire UNIT_QUEST_LOG_CHANGED for self
    uint16 slot = FindQuestSlot(pQuest->GetQuestId());
    if (slot < MAX_QUEST_LOG_SIZE)
        SetQuestSlotCounter(slot, uint8(creatureOrGO_idx), uint8(count));
    ALL_SESSION_SCRIPTS(GetSession(), OnQuestKillUpdated(guid));
}

/*********************************************************/
/***                   LOAD SYSTEM                     ***/
/*********************************************************/


void Player::Initialize(uint32 guid)
{
    Object::_Create(guid, 0, HIGHGUID_PLAYER);
}

void Player::_LoadBGData(QueryResult* result)
{
    if (!result)
        return;

    // Expecting only one row
    Field* fields = result->Fetch();
    /* bgInstanceID, bgTeam, x, y, z, o, map */
    m_bgData.bgInstanceID = fields[0].GetUInt32();
    m_bgData.bgTeam       = Team(fields[1].GetUInt32());
    if (MaNGOS::IsValidMapCoord(fields[2].GetFloat(), fields[3].GetFloat(), fields[4].GetFloat(), fields[5].GetFloat()))
        m_bgData.joinPos      = WorldLocation(fields[6].GetUInt32(),    // Map
                                              fields[2].GetFloat(),     // X
                                              fields[3].GetFloat(),     // Y
                                              fields[4].GetFloat(),     // Z
                                              fields[5].GetFloat());    // Orientation
    else
        m_bgData.joinPos      = WorldLocation(m_homebindMapId, m_homebindX, m_homebindY, m_homebindZ, 0.0f);
}

bool Player::LoadPositionFromDB(ObjectGuid guid, uint32& mapid, float& x, float& y, float& z, float& o, bool& in_flight)
{
    if (PlayerCacheData* data = sObjectMgr.GetPlayerDataByGUID(guid.GetCounter()))
    {
        x = data->fPosX;
        y = data->fPosY;
        z = data->fPosZ;
        o = data->fOrientation;
        mapid = data->uiMapId;
        in_flight = data->bInFlight;
    }
    else
    {
        QueryResult* result = CharacterDatabase.PQuery("SELECT `position_x`, `position_y`, `position_z`, `orientation`, `map`, `current_taxi_path` FROM `characters` WHERE `guid` = '%u'", guid.GetCounter());
        if (!result)
            return false;

        Field* fields = result->Fetch();

        x = fields[0].GetFloat();
        y = fields[1].GetFloat();
        z = fields[2].GetFloat();
        o = fields[3].GetFloat();
        mapid = fields[4].GetUInt32();
        in_flight = !fields[5].GetCppString().empty();

        delete result;
    }
    return true;
}

void Player::_LoadIntoDataField(char const* data, uint32 startOffset, uint32 count)
{
    if (!data)
        return;

    Tokens tokens = StrSplit(data, " ");

    if (tokens.size() != count)
        return;

    Tokens::iterator iter;
    uint32 index;
    for (iter = tokens.begin(), index = 0; index < count; ++iter, ++index)
        m_uint32Values[startOffset + index] = atol((*iter).c_str());
}

bool Player::LoadFromDB(ObjectGuid guid, SqlQueryHolder* holder)
{
    //       0     1        2     3     4      5       6      7   8      9     10    11          12          13           14              15
    //SELECT guid, account, name, race, class, gender, level, xp, money, skin, face, hair_style, hair_color, facial_hair, bank_bag_slots, player_flags,
    // 16          17          18          19   20           21               22                 23                 24          25           26                 27
    //"position_x, position_y, position_z, map, orientation, known_taxi_mask, played_time_total, played_time_level, rest_bonus, logout_time, is_logout_resting, reset_talents_multiplier,"
    // 28                  29              30           31           32           33           34           35            36              37    38      39                 40
    //"reset_talents_time, transport_guid, transport_x, transport_y, transport_z, transport_o, extra_flags, stable_slots, at_login_flags, zone, online, death_expire_time, current_taxi_path,
    // 41                 42                  43              44                  45                  46               47
    //"honor_rank_points, honor_highest_rank, honor_standing, honor_last_week_hk, honor_last_week_cp, honor_stored_hk, honor_stored_dk,"
    // 48                49     50      51      52      53      54      55      56              57               58       59
    //"watched_faction,  drunk, health, power1, power2, power3, power4, power5, explored_zones, equipment_cache, ammo_id, action_bars,"
    // 60                61
    //"world_phase_mask, create_time FROM characters WHERE guid = '%u'", GUID_LOPART(m_guid));

    QueryResult* result = holder->GetResult(PLAYER_LOGIN_QUERY_LOADFROM);

    if (!result)
    {
        sLog.outError("%s not found in table `characters`, can't load. ", guid.GetString().c_str());
        return false;
    }

    Field* fields = result->Fetch();

    uint32 dbAccountId = fields[1].GetUInt32();

    // check if the character's account in the db and the logged in account match.
    // player should be able to load/delete character only with correct account!
    if (!IsBot() && dbAccountId != GetSession()->GetAccountId())
    {
        sLog.outError("%s loading from wrong account (is: %u, should be: %u)",
                      guid.GetString().c_str(), GetSession()->GetAccountId(), dbAccountId);
        return false;
    }

    Object::_Create(guid.GetCounter(), 0, HIGHGUID_PLAYER);

    m_name = fields[2].GetCppString();

    // check name limitations
    if (ObjectMgr::CheckPlayerName(m_name) != CHAR_NAME_SUCCESS ||
            (GetSession()->GetSecurity() == SEC_PLAYER && sObjectMgr.IsReservedName(m_name)))
    {
        CharacterDatabase.PExecute("UPDATE `characters` SET `at_login_flags` = `at_login_flags` | '%u' WHERE `guid` ='%u'",
                                   uint32(AT_LOGIN_RENAME), guid.GetCounter());
        return false;
    }

    // overwrite possible wrong/corrupted guid
    SetGuidValue(OBJECT_FIELD_GUID, guid);

    // Phasing
    SetWorldMask(fields[60].GetUInt32());

    // overwrite some data fields
    SetByteValue(UNIT_FIELD_BYTES_0, UNIT_BYTES_0_OFFSET_RACE, fields[3].GetUInt8()); // race
    SetByteValue(UNIT_FIELD_BYTES_0, UNIT_BYTES_0_OFFSET_CLASS, fields[4].GetUInt8()); // class

    uint8 gender = fields[5].GetUInt8() & 0x01;             // allowed only 1 bit values male/female cases (for fit drunk gender part)
    SetByteValue(UNIT_FIELD_BYTES_0, UNIT_BYTES_0_OFFSET_GENDER, gender);            // gender

    SetByteValue(UNIT_FIELD_BYTES_2, UNIT_BYTES_2_OFFSET_MISC_FLAGS, UNIT_BYTE2_FLAG_UNK3 | UNIT_BYTE2_FLAG_UNK5);

    SetUInt32Value(UNIT_FIELD_LEVEL, fields[6].GetUInt8());
    SetUInt32Value(PLAYER_XP, fields[7].GetUInt32());

    _LoadIntoDataField(fields[56].GetString(), PLAYER_EXPLORED_ZONES_1, PLAYER_EXPLORED_ZONES_SIZE);

    InitPlayerDisplayIds();                                       // model, scale and model data

    uint32 money = fields[8].GetUInt32();
    if (money > MAX_MONEY_AMOUNT)
        money = MAX_MONEY_AMOUNT;
    SetMoney(money);

    SetByteValue(PLAYER_BYTES, 0, fields[9].GetUInt8());  // skin
    SetByteValue(PLAYER_BYTES, 1, fields[10].GetUInt8()); // face
    SetByteValue(PLAYER_BYTES, 2, fields[11].GetUInt8()); // hair style
    SetByteValue(PLAYER_BYTES, 3, fields[12].GetUInt8()); // hair color
    SetByteValue(PLAYER_BYTES_2, 0, fields[13].GetUInt8()); // facial hair
    SetBankBagSlotCount(fields[14].GetUInt8());

    m_drunk = fields[49].GetUInt16();

    SetUInt16Value(PLAYER_BYTES_3, 0, (m_drunk & 0xFFFE) | gender);

    SetUInt32Value(PLAYER_FLAGS, fields[15].GetUInt32());

    if (HasFlag(PLAYER_FLAGS, PLAYER_FLAGS_PVP_DESIRED))
    {
        UpdatePvP(true);
        RemoveFlag(PLAYER_FLAGS, PLAYER_FLAGS_PVP_DESIRED);
    }

#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_9_4
    SetInt32Value(PLAYER_FIELD_WATCHED_FACTION_INDEX, fields[48].GetInt32());
#endif

    SetUInt32Value(PLAYER_AMMO_ID, fields[58].GetUInt32());

    // Action bars state
    SetByteValue(PLAYER_FIELD_BYTES, 2, fields[59].GetUInt8());

    // cleanup inventory related item value fields (its will be filled correctly in _LoadInventory)
    for (uint8 slot = EQUIPMENT_SLOT_START; slot < EQUIPMENT_SLOT_END; ++slot)
    {
        SetGuidValue(PLAYER_FIELD_INV_SLOT_HEAD + (slot * 2), ObjectGuid());
        SetVisibleItemSlot(slot, nullptr);

        if (m_items[slot])
        {
            delete m_items[slot];
            m_items[slot] = nullptr;
        }
    }

    DEBUG_FILTER_LOG(LOG_FILTER_PLAYER_STATS, "Load Basic value of player %s is: ", m_name.c_str());
    outDebugStatsValues();

    //Need to call it to initialize m_team (m_team can be calculated from race)
    //Other way is to saves m_team into characters table.
    SetFactionForRace(GetRace());
    SetCharm(nullptr);

    // load home bind and check in same time class/race pair, it used later for restore broken positions
    if (!_LoadHomeBind(holder->GetResult(PLAYER_LOGIN_QUERY_LOADHOMEBIND)))
        return false;

    InitPrimaryProfessions();                               // to max set before any spell loaded

    // init saved position, and fix it later if problematic
    uint32 transGUID = fields[29].GetUInt32();

    if (!MaNGOS::IsValidMapCoord(fields[16].GetFloat(), fields[17].GetFloat(), fields[18].GetFloat(), fields[20].GetFloat()))
    {
        sLog.outError("%s have invalid coordinates (X: %f Y: %f Z: %f O: %f). Teleport to default race/class locations.",
                      guid.GetString().c_str(), GetPositionX(), GetPositionY(), GetPositionZ(), GetOrientation());
        RelocateToHomebind();

        transGUID = 0;

        m_movementInfo.ClearTransportData();
    }
    else
    {
        Relocate(fields[16].GetFloat(), fields[17].GetFloat(), fields[18].GetFloat(), fields[20].GetFloat());
        SetLocationMapId(fields[19].GetUInt32());
    }

    _LoadGroup(holder->GetResult(PLAYER_LOGIN_QUERY_LOADGROUP));

    m_honorMgr.SetRankPoints(fields[41].GetFloat());
    m_honorMgr.SetHighestRank(fields[42].GetUInt32());
    m_honorMgr.SetStanding(fields[43].GetUInt32());
    m_honorMgr.SetLastWeekHK(fields[44].GetUInt32());
    m_honorMgr.SetLastWeekCP(fields[45].GetFloat());
    m_honorMgr.SetStoredHK(fields[46].GetUInt32());
    m_honorMgr.SetStoredDK(fields[47].GetUInt32());

    m_honorMgr.Load(holder->GetResult(PLAYER_LOGIN_QUERY_LOADHONORCP));
    _LoadBoundInstances(holder->GetResult(PLAYER_LOGIN_QUERY_LOADBOUNDINSTANCES));
    _LoadBGData(holder->GetResult(PLAYER_LOGIN_QUERY_LOADBGDATA));

    _LoadGuild(holder->GetResult(PLAYER_LOGIN_QUERY_LOADGUILD));

    MapEntry const* mapEntry = sMapStorage.LookupEntry<MapEntry>(GetMapId());

    // Check for valid map
    if (!mapEntry)
    {
        sLog.outError("Player %s in invalid map. Relocating to home.", guid.GetString().c_str());
        RelocateToHomebind();
    }
    else if (mapEntry->IsBattleGround())
    // if server restart after player save in BG
    // player can have current coordinates in to BG map, fix this
    {
        WorldLocation const& _loc = GetBattleGroundEntryPoint();
        SetLocationMapId(_loc.mapId);
        Relocate(_loc.x, _loc.y, _loc.z, _loc.o);

        // We are not in BG anymore
        SetBattleGroundId(0, BATTLEGROUND_TYPE_NONE);
        // remove outdated DB data in DB
        _SaveBGData();
    }

    // load the player's map here if it's not already loaded
    if (GetMapId() <= 1)
        SetLocationInstanceId(sMapMgr.GetContinentInstanceId(GetMapId(), GetPositionX(), GetPositionY()));
    SetMap(sMapMgr.CreateMap(GetMapId(), this));

    if (transGUID != 0)
    {
        ObjectGuid guid = sObjectMgr.GetFullTransportGuidFromLowGuid(transGUID);

        if (GenericTransport* transport = GetMap()->GetTransport(guid))
        {
            float x = fields[30].GetFloat(), y = fields[31].GetFloat(), z = fields[32].GetFloat(), o = fields[33].GetFloat();
            m_movementInfo.SetTransportData(guid, x, y, z, o, 0);
            transport->CalculatePassengerPosition(x, y, z, &o);

            if (!MaNGOS::IsValidMapCoord(x, y, z, o) ||
                    // transport size limited
                    std::fabs(m_movementInfo.GetTransportPos().x) > 250.0f ||
                    std::fabs(m_movementInfo.GetTransportPos().y) > 250.0f ||
                    std::fabs(m_movementInfo.GetTransportPos().z) > 250.0f)
            {
                sLog.outError("Player %s have invalid transport coordinates (X: %f Y: %f Z: %f O: %f). Teleport to bind location.",
                              guid.GetString().c_str(), x, y, z, o);

                m_movementInfo.ClearTransportData();

                RelocateToHomebind();
            }
            else
            {
                if (transport->GetMap() != this->GetMap())
                {
                    if (transport->GetMapId() <= 1)
                        SetLocationInstanceId(sMapMgr.GetContinentInstanceId(transport->GetMapId(), transport->GetPositionX(), transport->GetPositionY()));
                    SetMap(transport->GetMap());
                }
                Relocate(x, y, z, o);

                transport->AddPassenger(this);
            }
        }
        else
        {
            sLog.outError("Player %s have problems with transport guid (%u). Teleport to bind location.",
                          guid.GetString().c_str(), transGUID);

            RelocateToHomebind();
        }
    }

    if (PlayerBotEntry* e = GetSession()->GetBot())
        e->ai->BeforeAddToMap(this);

    // player bounded instance saves loaded in _LoadBoundInstances, group versions at group loading
    DungeonPersistentState* state = GetBoundInstanceSaveForSelfOrGroup(GetMapId());

    mapEntry = sMapStorage.LookupEntry<MapEntry>(GetMapId());
    if (mapEntry && mapEntry->IsDungeon())
    {
        // if the player is in an instance and it has been reset in the meantime teleport him to the entrance
        if (!state)
        {
            AreaTriggerTeleport const* at = sObjectMgr.GetGoBackTrigger(GetMapId());
            if (at)
            {
                Relocate(at->destination.x, at->destination.y, at->destination.z, at->destination.o);
                SetLocationMapId(at->destination.mapId);
                if (GetMapId() <= 1)
                    SetLocationInstanceId(sMapMgr.GetContinentInstanceId(GetMapId(), GetPositionX(), GetPositionY()));
                SetMap(sMapMgr.CreateMap(GetMapId(), this));
            }
            else if (GetMapId() == 533) // Naxxramas
            {
                // There is no exit areatrigger for Naxx, but exit destination for
                // all dungeons is stored in WorldSafeLocs.db2 in 1.13 classic client.
                Relocate(3362.15f, -3379.35f, 144.782f, 6.28319f);
                SetLocationMapId(0);
                if (GetMapId() <= 1)
                    SetLocationInstanceId(sMapMgr.GetContinentInstanceId(GetMapId(), GetPositionX(), GetPositionY()));
                SetMap(sMapMgr.CreateMap(GetMapId(), this));
            }
        }
    }

    SaveRecallPosition();

    time_t now = time(nullptr);
    time_t logoutTime = time_t(fields[25].GetUInt64());

    // since last logout (in seconds)
    uint32 time_diff = uint32(now - logoutTime);

    // set value, including drunk invisibility detection
    // calculate sobering. after 15 minutes logged out, the player will be sober again
    float soberFactor;
    if (time_diff > 15 * MINUTE)
        soberFactor = 0;
    else
        soberFactor = 1 - time_diff / (15.0f * MINUTE);
    uint16 newDrunkenValue = uint16(soberFactor * m_drunk);
    SetDrunkValue(newDrunkenValue);

    m_playedTime[PLAYED_TIME_TOTAL] = fields[22].GetUInt32();
    m_playedTime[PLAYED_TIME_LEVEL] = fields[23].GetUInt32();
    m_createTime = fields[61].GetUInt64();

    m_resetTalentsMultiplier = fields[27].GetUInt32();
    m_resetTalentsTime = time_t(fields[28].GetUInt64());

    // reserve some flags
    uint32 old_safe_flags = GetUInt32Value(PLAYER_FLAGS) & (PLAYER_FLAGS_HIDE_CLOAK | PLAYER_FLAGS_HIDE_HELM);

    if (HasFlag(PLAYER_FLAGS, PLAYER_FLAGS_GM))
        SetUInt32Value(PLAYER_FLAGS, 0 | old_safe_flags);

    m_taxi.LoadTaxiMask(fields[21].GetString());

    uint32 extraflags = fields[34].GetUInt32();

    m_stableSlots = fields[35].GetUInt32();
    if (m_stableSlots > MAX_PET_STABLES)
    {
        sLog.outError("Player can have not more %u stable slots, but have in DB %u", MAX_PET_STABLES, uint32(m_stableSlots));
        m_stableSlots = MAX_PET_STABLES;
    }

    m_atLoginFlags = fields[36].GetUInt32();

    m_deathExpireTime = (time_t)fields[39].GetUInt64();
    if (m_deathExpireTime > now + MAX_DEATH_COUNT * DEATH_EXPIRE_STEP)
        m_deathExpireTime = now + MAX_DEATH_COUNT * DEATH_EXPIRE_STEP - 1;

    std::string taxi_nodes = fields[40].GetCppString();

    // clear channel spell data (if saved at channel spell casting)
    SetChannelObjectGuid(ObjectGuid());
    SetUInt32Value(UNIT_CHANNEL_SPELL, 0);

    // clear charm/summon related fields
    SetCharm(nullptr);
    SetPet(nullptr);
    SetTargetGuid(ObjectGuid());
    SetCharmerGuid(ObjectGuid());
    SetOwnerGuid(ObjectGuid());
    SetCreatorGuid(ObjectGuid());

    // reset some aura modifiers before aura apply

    SetGuidValue(PLAYER_FARSIGHT, ObjectGuid());
    SetUInt32Value(PLAYER_TRACK_CREATURES, 0);
    SetUInt32Value(PLAYER_TRACK_RESOURCES, 0);

    // cleanup aura list explicitly before skill load where some spells can be applied
    RemoveAllAuras();

    // make sure the unit is considered out of combat for proper loading
    ClearInCombat();

    // make sure the unit is considered not in duel for proper loading
    SetGuidValue(PLAYER_DUEL_ARBITER, ObjectGuid());
    SetUInt32Value(PLAYER_DUEL_TEAM, 0);

    // reset stats before loading any modifiers
    InitStatsForLevel();

    // is it need, only in pre-2.x used and field byte removed later?
    if (GetPowerType() == POWER_RAGE || GetPowerType() == POWER_MANA)
        SetByteValue(UNIT_FIELD_BYTES_1, UNIT_BYTES_1_OFFSET_PET_LOYALTY, 0xEE);

    // rest bonus can only be calculated after InitStatsForLevel()
    m_restBonus = fields[24].GetFloat();

    if (time_diff > 0)
        SetRestBonus(GetRestBonus() + ComputeRest(time_diff, true, (fields[26].GetInt32() > 0)));

    // load skills after InitStatsForLevel because it triggering aura apply also
    _LoadSkills(holder->GetResult(PLAYER_LOGIN_QUERY_LOADSKILLS));

#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_10_2
    _LoadForgottenSkills(holder->GetResult(PLAYER_LOGIN_QUERY_FORGOTTEN_SKILLS));
#endif

    // apply original stats mods before spell loading or item equipment that call before equip _RemoveStatsMods()

    _LoadAuras(holder->GetResult(PLAYER_LOGIN_QUERY_LOADAURAS), time_diff);

    // add ghost flag (must be after aura load: PLAYER_FLAGS_GHOST set in aura)
    if (HasFlag(PLAYER_FLAGS, PLAYER_FLAGS_GHOST))
        m_deathState = DEAD;

    _LoadSpells(holder->GetResult(PLAYER_LOGIN_QUERY_LOADSPELLS));

    // after spell load
    InitTalentForLevel();
    LearnDefaultSpells();

    // after spell load, learn rewarded spell if need also
    _LoadQuestStatus(holder->GetResult(PLAYER_LOGIN_QUERY_LOADQUESTSTATUS));

    // must be before inventory (some items required reputation check)
    m_reputationMgr.LoadFromDB(holder->GetResult(PLAYER_LOGIN_QUERY_LOADREPUTATION));

    bool hasEpicMount = false; // Needed for riding skill replacement in patch 1.12.
    bool hasItems = _LoadInventory(holder->GetResult(PLAYER_LOGIN_QUERY_LOADINVENTORY), time_diff, hasEpicMount);

    if (!hasItems && HasAtLoginFlag(AT_LOGIN_FIRST))
        AddStartingItems();

    _LoadItemLoot(holder->GetResult(PLAYER_LOGIN_QUERY_LOADITEMLOOT));

    // update items with duration and realtime
    UpdateItemDuration(time_diff, true);

    if (!m_taxi.LoadTaxiDestinationsFromString(taxi_nodes, GetTeam()))
    {
        // problems with taxi path loading
        TaxiNodesEntry const* nodeEntry = nullptr;
        if (uint32 node_id = m_taxi.GetTaxiSource())
            nodeEntry = sObjectMgr.GetTaxiNodeEntry(node_id);

        if (!nodeEntry)                                     // don't know taxi start node, to homebind
        {
            sLog.outError("Character %u have wrong data in taxi destination list, teleport to homebind.", GetGUIDLow());
            RelocateToHomebind();
        }
        else                                                // have start node, to it
        {
            sLog.outError("Character %u have too short taxi destination list, teleport to original node.", GetGUIDLow());
            SetLocationMapId(nodeEntry->map_id);
            Relocate(nodeEntry->x, nodeEntry->y, nodeEntry->z, 0.0f);
        }

        //we can be relocated from taxi and still have an outdated Map pointer!
        //so we need to get a new Map pointer!
        if (GetMapId() <= 1)
            SetLocationInstanceId(sMapMgr.GetContinentInstanceId(GetMapId(), GetPositionX(), GetPositionY()));
        SetMap(sMapMgr.CreateMap(GetMapId(), this));
        SaveRecallPosition();                           // save as recall also to prevent recall and fall from sky

        m_taxi.ClearTaxiDestinations();
    }

    if (uint32 node_id = m_taxi.GetTaxiSource())
    {
        // save source node as recall coord to prevent recall and fall from sky
        TaxiNodesEntry const* nodeEntry = sObjectMgr.GetTaxiNodeEntry(node_id);
        MANGOS_ASSERT(nodeEntry);                           // checked in m_taxi.LoadTaxiDestinationsFromString
        m_recallMap = nodeEntry->map_id;
        m_recallX = nodeEntry->x;
        m_recallY = nodeEntry->y;
        m_recallZ = nodeEntry->z;

        // flight will started later
    }

    // has to be called after last Relocate() in Player::LoadFromDB
    SetFallInformation(0, GetPositionZ());

    _LoadSpellCooldowns(holder->GetResult(PLAYER_LOGIN_QUERY_LOADSPELLCOOLDOWNS));

    // Spell code allow apply any auras to dead character in load time in aura/spell/item loading
    // Do now before stats re-calculation cleanup for ghost state unexpected auras
    if (!IsAlive())
        RemoveAllAurasOnDeath();

    //apply all stat bonuses from items and auras
    SetCanModifyStats(true);
    UpdateAllStats();

    // restore remembered power/health values (but not more max values)
    uint32 savedhealth = fields[50].GetUInt32();
    SetHealth(savedhealth > GetMaxHealth() ? GetMaxHealth() : savedhealth);
    for (uint32 i = 0; i < MAX_POWERS; ++i)
    {
        uint32 savedpower = fields[51 + i].GetUInt32();
        SetPower(Powers(i), savedpower > GetMaxPower(Powers(i)) ? GetMaxPower(Powers(i)) : savedpower);
    }

    DEBUG_FILTER_LOG(LOG_FILTER_PLAYER_STATS, "The value of player %s after load item and aura is: ", m_name.c_str());
    outDebugStatsValues();

    // GM state
    if (GetSession()->GetSecurity() > SEC_MODERATOR)
    {
        switch (sWorld.getConfig(CONFIG_UINT32_GM_LOGIN_STATE))
        {
            default:
            case 0:
                break;             // disable
            case 1:
                SetGameMaster(true);
                break;             // enable
            case 2:                                         // save state
                if (extraflags & PLAYER_EXTRA_GM_ON)
                    SetGameMaster(true);
                break;
        }

        switch (sWorld.getConfig(CONFIG_UINT32_GM_VISIBLE_STATE))
        {
            default:
            case 0:
                SetGMVisible(false);
                break;             // invisible
            case 1:
                break;             // visible
            case 2:                                         // save state
                if (extraflags & PLAYER_EXTRA_GM_INVISIBLE)
                    SetGMVisible(false);
                break;
        }

        switch (sWorld.getConfig(CONFIG_UINT32_GM_ACCEPT_TICKETS))
        {
            default:
            case 0:
                break;           // disable
            case 1:
                SetAcceptTicket(true);
                break;           // enable
            case 2:                                         // save state
                if (extraflags & PLAYER_EXTRA_GM_ACCEPT_TICKETS)
                    SetAcceptTicket(true);
                break;
        }

        switch (sWorld.getConfig(CONFIG_UINT32_GM_CHAT))
        {
            default:
            case 0:
                break;                 // disable
            case 1:
                SetGMChat(true);
                break;                 // enable
            case 2:                                         // save state
                if (extraflags & PLAYER_EXTRA_GM_CHAT)
                    SetGMChat(true);
                break;
        }

        switch (sWorld.getConfig(CONFIG_UINT32_GM_WISPERING_TO))
        {
            default:
            case 0:
                break;         // disable
            case 1:
                SetAcceptWhispers(true);
                break;         // enable
            case 2:                                         // save state
                if (extraflags & PLAYER_EXTRA_ACCEPT_WHISPERS)
                    SetAcceptWhispers(true);
                break;
        }
        SetCheatGod(true);
    }

    if (extraflags & PLAYER_EXTRA_WHISP_RESTRICTION)
        SetWhisperRestriction(true);

    if ((extraflags & PLAYER_EXTRA_CITY_PROTECTOR) && sWorld.getConfig(CONFIG_BOOL_ENABLE_CITY_PROTECTOR))
        SetCityTitle();

    sBattleGroundMgr.PlayerLoggedIn(this); // Add to BG queue if needed
    CreatePacketBroadcaster();

    if (sWorld.GetWowPatch() >= WOW_PATCH_112)
        UpdateOldRidingSkillToNew(hasEpicMount);

    return true;
}

// The new riding skills (Apprentice/Journeyman) were added in patch 1.12.
// Prior to that there was a separate skill of each type of mount.
// All players who have the old skill need to have it swapped for the new one.
void Player::UpdateOldRidingSkillToNew(bool hasEpicMount)
{
    // Already has the new skill, no need to do anything.
    if (HasSkill(SKILL_RIDING))
        return;

    bool has_old_riding_skill = false;

    if (HasSkill(SKILL_RIDING_HORSE))
    {
        SetSkill(SKILL_RIDING_HORSE, 0, 0);
        has_old_riding_skill = true;
    }

    if (HasSkill(SKILL_RIDING_WOLF))
    {
        SetSkill(SKILL_RIDING_WOLF, 0, 0);
        has_old_riding_skill = true;
    }

    if (HasSkill(SKILL_RIDING_TIGER))
    {
        SetSkill(SKILL_RIDING_TIGER, 0, 0);
        has_old_riding_skill = true;
    }

    if (HasSkill(SKILL_RIDING_RAM))
    {
        SetSkill(SKILL_RIDING_RAM, 0, 0);
        has_old_riding_skill = true;
    }

    if (HasSkill(SKILL_RIDING_RAPTOR))
    {
        SetSkill(SKILL_RIDING_RAPTOR, 0, 0);
        has_old_riding_skill = true;
    }

    if (HasSkill(SKILL_RIDING_MECHANOSTRIDER))
    {
        SetSkill(SKILL_RIDING_MECHANOSTRIDER, 0, 0);
        has_old_riding_skill = true;
    }

    if (HasSkill(SKILL_RIDING_UNDEAD_HORSE))
    {
        SetSkill(SKILL_RIDING_UNDEAD_HORSE, 0, 0);
        has_old_riding_skill = true;
    }

    if (HasSkill(SKILL_RIDING_KODO))
    {
        SetSkill(SKILL_RIDING_KODO, 0, 0);
        has_old_riding_skill = true;
    }

    // Paladin and Warlock level 40 mounts
    if (HasSpell(13819u) || HasSpell(5784u))
        has_old_riding_skill = true;

    // Paladin and Warlock level 60 mounts
    if (HasSpell(23214u) || HasSpell(23161u))
        hasEpicMount = true;

    if (!has_old_riding_skill)
        return;
    
    if (hasEpicMount)
        LearnSpell(33391u, false); // Journeyman Riding
    else
        LearnSpell(33388u, false); // Apprentice Riding
}

void Player::SendPacketsAtRelogin()
{
    SendProficiency(ITEM_CLASS_WEAPON, GetWeaponProficiency());
    SendProficiency(ITEM_CLASS_ARMOR, GetArmorProficiency());
    for (const auto& modList : m_spellMods)
    {
        for (const auto& mod : modList)
            SendSpellMod(mod);
    }  
}

bool Player::IsAllowedToLoot(Creature const* creature)
{
    if (!creature->IsDead())
        return false;

    if (creature->AI() && !creature->AI()->CanBeLooted())
        return false;

    Loot const* loot = &creature->loot;
    if (loot->isLooted()) // nothing to loot or everything looted.
        return false;

    // Nostalrius: pas possible de looter si on n'etait pas la a la mort du mob.
    if (!loot->IsAllowedLooter(GetObjectGuid()))
        return false;

    Group* thisGroup = GetGroup();

    if (!thisGroup)
        return (this == creature->GetOriginalLootRecipient());
    // Verif suivante impossible en cas de groupe de BG
    // puisque tous les groupes de BG ont comme ID = 0.
    else if (thisGroup->isBGGroup())
        return true;
    else if (thisGroup != creature->GetGroupLootRecipient())
        return false;

    switch (thisGroup->GetLootMethod())
    {
        case FREE_FOR_ALL:
            return true;
        case MASTER_LOOT:
            // On peut toujours voir ces items.
            if (loot->hasOverThresholdItem())
                return true;
        case ROUND_ROBIN:
            // may only loot if the player is the loot roundrobin player
            // or if there are free/quest/conditional item for the player
            if (loot->roundRobinPlayer == 0 || loot->roundRobinPlayer == GetGUID())
                return true;

            return loot->hasItemFor(this);
        case GROUP_LOOT:
        case NEED_BEFORE_GREED:
            // may only loot if the player is the loot roundrobin player
            // or item over threshold (so roll(s) can be launched)
            // or if there are free/quest/conditional item for the player
            if (loot->roundRobinPlayer == 0 || loot->roundRobinPlayer == GetGUID())
                return true;

            if (loot->hasOverThresholdItem())
                return true;

            return loot->hasItemFor(this);
    }
    return false;
}

void Player::_LoadAuras(QueryResult* result, uint32 timediff)
{
    //RemoveAllAuras(); -- some spells casted before aura load, for example in LoadSkills, aura list explicitly cleaned early

    // all aura related fields
    for (int i = UNIT_FIELD_AURA; i <= UNIT_FIELD_AURASTATE; ++i)
        SetUInt32Value(i, 0);

    //QueryResult* result = CharacterDatabase.PQuery("SELECT caster_guid, item_guid, spell, stacks, charges, base_points0, base_points1, base_points2, periodic_time0, periodic_time1, periodic_time2, max_duration, duration, effect_index_mask FROM character_aura WHERE guid = '%u'",GetGUIDLow());

    if (result)
    {
        do
        {
            Field* fields = result->Fetch();
            AuraSaveStruct s;
            s.casterGuid  = ObjectGuid(fields[0].GetUInt64());
            s.itemLowGuid = fields[1].GetUInt32();
            s.spellId     = fields[2].GetUInt32();
            s.stacks      = fields[3].GetUInt32();
            s.charges     = fields[4].GetUInt32();

            for (uint8 i = 0; i < MAX_EFFECT_INDEX; ++i)
            {
                s.damage[i]       = fields[i + 5].GetFloat();
                s.periodicTime[i] = fields[i + 8].GetUInt32();
            }

            s.maxDuration  = fields[11].GetInt32();
            s.duration     = fields[12].GetInt32();
            s.effIndexMask = fields[13].GetUInt8();

            LoadAura(s, timediff);
        }
        while (result->NextRow());
    }

    if (GetClass() == CLASS_WARRIOR && !HasAuraType(SPELL_AURA_MOD_SHAPESHIFT))
        CastSpell(this, SPELL_ID_PASSIVE_BATTLE_STANCE, true);

    if (GetGroup())
        SetGroupUpdateFlag(GROUP_UPDATE_FLAG_STATUS);
}

void Player::LoadAura(AuraSaveStruct& s, uint32 timediff)
{
    SpellEntry const* spellproto = sSpellMgr.GetSpellEntry(s.spellId);
    if (!spellproto)
    {
        sLog.outError("Player::_LoadAuras: Unknown spell (spellid %u), ignore.", s.spellId);
        return;
    }

    if (s.duration != -1 && spellproto->HasRealTimeDuration())
    {
        if (timediff > (INT_MAX / IN_MILLISECONDS))
            return;

        if (s.duration <= int32(timediff) * IN_MILLISECONDS)
            return;

        s.duration -= timediff * IN_MILLISECONDS;
    }

    // Special case for chat silenced indicator
    if (spellproto->Id == SPELL_PLAYER_MUTED_VISUAL)
    {
        auto currTime = time(nullptr);
        auto muteTime = GetSession()->m_muteTime;
        if (muteTime <= currTime)
            return;
        s.duration = (muteTime - currTime) * IN_MILLISECONDS;
    }

    // prevent wrong values of remaincharges
    if (spellproto->procCharges == 0)
        s.charges = 0;

    if (!spellproto->StackAmount)
        s.stacks = 1;
    else if (spellproto->StackAmount < s.stacks)
        s.stacks = spellproto->StackAmount;
    else if (!s.stacks)
        s.stacks = 1;

    SpellAuraHolder* holder = CreateSpellAuraHolder(spellproto, this, nullptr, nullptr);
    holder->SetLoadedState(s.casterGuid, ObjectGuid(HIGHGUID_ITEM, s.itemLowGuid), s.stacks, s.charges, s.maxDuration, s.duration);

    for (uint8 i = 0; i < MAX_EFFECT_INDEX; ++i)
    {
        if ((s.effIndexMask & (1 << i)) == 0 || !spellproto->EffectApplyAuraName[i])
            continue;

        Aura* aura = CreateAura(spellproto, SpellEffectIndex(i), nullptr, holder, this);
        if (!s.damage[i])
            s.damage[i] = aura->GetModifier()->m_amount;

        aura->SetLoadedState(s.damage[i], s.periodicTime[i]);
        holder->AddAura(aura, SpellEffectIndex(i));
    }

    if (!holder->IsEmptyHolder())
    {
        // reset stolen single target auras
        if (s.casterGuid != GetObjectGuid() && holder->IsSingleTarget())
            holder->SetIsSingleTarget(false);

        if (!AddSpellAuraHolder(holder))
            holder = nullptr;
        DETAIL_LOG("Added auras from spellid %u", spellproto->Id);
    }
    else
        delete holder;
}

void Player::LoadCorpse()
{
    if (IsAlive())
        sObjectAccessor.ConvertCorpseForPlayer(GetObjectGuid());
    else
    {
        if (Corpse* corpse = GetCorpse())
            ApplyModByteFlag(PLAYER_FIELD_BYTES, 0, PLAYER_FIELD_BYTE_RELEASE_TIMER, corpse && !sMapStorage.LookupEntry<MapEntry>(corpse->GetMapId())->Instanceable());
        else
        {
            //Prevent Dead Player login without corpse
            ResurrectPlayer(0.5f);
        }
    }
}

bool Player::_LoadInventory(QueryResult* result, uint32 timediff, bool& hasEpicMount)
{
    //       0             1                  2      3         4        5      6             7                   8           9     10   11    12         13              14
    //SELECT creator_guid, gift_creator_guid, count, duration, charges, flags, enchantments, random_property_id, durability, text, bag, slot, item_guid, item_id, generated_loot

    if (result)
    {
        std::unordered_map<uint32, Bag*> bagMap;                          // fast guid lookup for bags
        //NOTE: the "order by `bag`" is important because it makes sure
        //the bagMap is filled before items in the bags are loaded
        //NOTE2: the "order by `slot`" is needed because mainhand weapons are (wrongly?)
        //expected to be equipped before offhand items (TODO: fixme)

        std::set<uint32> itemGuids;
        uint32 zone = GetZoneId();

        std::list<Item*> problematicItems;

        // prevent items from being added to the queue when stored
        m_itemUpdateQueueBlocked = true;
        do
        {
            Field* fields = result->Fetch();
            uint32 bag_guid     = fields[10].GetUInt32();
            uint8  slot         = fields[11].GetUInt8();
            uint32 item_lowguid = fields[12].GetUInt32();
            uint32 item_id      = fields[13].GetUInt32();

            ItemPrototype const* proto = ObjectMgr::GetItemPrototype(item_id);

            if (!proto)
            {
                CharacterDatabase.PExecute("DELETE FROM `character_inventory` WHERE `item_guid` = '%u'", item_lowguid);
                CharacterDatabase.PExecute("DELETE FROM `item_instance` WHERE `guid` = '%u'", item_lowguid);
                CharacterDatabase.PExecute("INSERT INTO `character_deleted_items` (`player_guid`, `item_id`, `stack_count`) VALUES ('%u', '%u', '%u')", GetGUIDLow(), item_id, fields[2].GetUInt32());
                sLog.outError("Player::_LoadInventory: Player %s has an unknown item (id: #%u) in inventory, deleted.", GetName(), item_id);
                continue;
            }

            // Needed for riding skill replacement in patch 1.12.
            if ((proto->RequiredSkill == SKILL_RIDING) && (proto->RequiredSkillRank == 150))
                hasEpicMount = true;

            // Duplicate check. Player listed item in AH and then immediately relogged, before the item
            // was deleted from the inventory in the DB
            if (Item* item = sAuctionMgr.GetAItem(item_lowguid))
            {
                std::stringstream oss;
                oss << "Duplicate item (via AH) " << item_id << " GUID:" << item_lowguid << ", count: " << item->GetCount() << ", bag: " << bag_guid << ", slot: " << uint32(slot);
                CharacterDatabase.PExecute("DELETE FROM `character_inventory` WHERE `item_guid` = '%u'", item_lowguid);
                GetSession()->ProcessAnticheatAction("PassiveAnticheat", oss.str().c_str(), CHEAT_ACTION_LOG | CHEAT_ACTION_REPORT_GMS);
                DETAIL_LOG(oss.str().c_str());
                continue;
            }

            Item* item = NewItemOrBag(proto);

            /*
             * LoadFromDB is called from multiple places but with a different set of fields - this is workaround
             * so I don't need to fix the mess of queries and probably break something until a later date
             */
            item->SetGeneratedLoot(fields[14].GetBool());

            if (!item->LoadFromDB(item_lowguid, GetObjectGuid(), fields, item_id))
            {
                sLog.outError("Player::_LoadInventory: Player %s has broken item (id: #%u) in inventory, deleted.", GetName(), item_id);
                CharacterDatabase.PExecute("DELETE FROM `character_inventory` WHERE `item_guid` = '%u'", item_lowguid);
                item->FSetState(ITEM_REMOVED);
                item->SaveToDB();                           // it also deletes item object !
                continue;
            }

            // Duplic guid check
            if (itemGuids.find(item_lowguid) != itemGuids.end())
            {
                std::stringstream oss;
                oss << "Duplicate item " << item_id << " GUID:" << item_lowguid << ", count: " << item->GetCount() << ", bag: " << bag_guid << ", slot: " << uint32(slot);
                GetSession()->ProcessAnticheatAction("PassiveAnticheat", oss.str().c_str(), CHEAT_ACTION_LOG | CHEAT_ACTION_REPORT_GMS);
            }
            itemGuids.insert(item_lowguid);

            // not allow have in alive state item limited to another map/zone
            if (IsAlive() && item->IsLimitedToAnotherMapOrZone(GetMapId(), zone))
            {
                CharacterDatabase.PExecute("DELETE FROM `character_inventory` WHERE `item_guid` = '%u'", item_lowguid);
                item->FSetState(ITEM_REMOVED);
                item->SaveToDB();                           // it also deletes item object !
                continue;
            }

            // "Conjured items disappear if you are logged out for more than 15 minutes"
            if (timediff > 15 * MINUTE && (item->GetProto()->Flags & ITEM_FLAG_CONJURED))
            {
                CharacterDatabase.PExecute("DELETE FROM `character_inventory` WHERE `item_guid` = '%u'", item_lowguid);
                item->FSetState(ITEM_REMOVED);
                item->SaveToDB();                           // it also deletes item object !
                continue;
            }

            bool success = true;

            // the item/bag is not in a bag
            if (!bag_guid)
            {
                item->SetContainer(nullptr);
                item->SetSlot(slot);

                if (IsInventoryPos(INVENTORY_SLOT_BAG_0, slot))
                {
                    ItemPosCountVec dest;
                    if (CanStoreItem(INVENTORY_SLOT_BAG_0, slot, dest, item, false) == EQUIP_ERR_OK)
                        item = StoreItem(dest, item, true);
                    else
                    {
                        GetSession()->ProcessAnticheatAction("PassiveAnticheat", "Item Load failed: cannot store", CHEAT_ACTION_LOG | CHEAT_ACTION_REPORT_GMS);
                        success = false;
                    }
                }
                else if (IsEquipmentPos(INVENTORY_SLOT_BAG_0, slot))
                {
                    uint16 dest;
                    if (CanEquipItem(slot, dest, item, false, false) == EQUIP_ERR_OK)
                        QuickEquipItem(dest, item);
                    else
                    {
                        GetSession()->ProcessAnticheatAction("PassiveAnticheat", "Item Load failed: cannot QuickEquip", CHEAT_ACTION_LOG | CHEAT_ACTION_REPORT_GMS);
                        success = false;
                    }
                }
                else if (IsBankPos(INVENTORY_SLOT_BAG_0, slot))
                {
                    ItemPosCountVec dest;
                    if (CanBankItem(INVENTORY_SLOT_BAG_0, slot, dest, item, false, false) == EQUIP_ERR_OK)
                        item = BankItem(dest, item, true);
                    else
                    {
                        GetSession()->ProcessAnticheatAction("PassiveAnticheat", "Item Load failed: cannot Bank", CHEAT_ACTION_LOG | CHEAT_ACTION_REPORT_GMS);
                        success = false;
                    }
                }

                if (success)
                {
                    // store bags that may contain items in them
                    if (item->IsBag() && IsBagPos(item->GetPos()))
                        bagMap[item_lowguid] = (Bag*)item;
                }
            }
            // the item/bag in a bag
            else
            {
                item->SetSlot(NULL_SLOT);
                // the item is in a bag, find the bag
                std::unordered_map<uint32, Bag*>::const_iterator itr = bagMap.find(bag_guid);
                if (itr != bagMap.end() && slot < itr->second->GetBagSize())
                {
                    ItemPosCountVec dest;
                    if (CanStoreItem(itr->second->GetSlot(), slot, dest, item, false) == EQUIP_ERR_OK)
                        item = StoreItem(dest, item, true);
                    else
                    {
                        GetSession()->ProcessAnticheatAction("PassiveAnticheat", "Item Load failed: can't store inside bag", CHEAT_ACTION_LOG | CHEAT_ACTION_REPORT_GMS);
                        success = false;
                    }
                }
                else
                {
                    GetSession()->ProcessAnticheatAction("PassiveAnticheat", "Item Load failed: invalid bag pos", CHEAT_ACTION_LOG | CHEAT_ACTION_REPORT_GMS);
                    success = false;
                }
            }

            // item's state may have changed after stored
            if (success)
            {
                item->SetState(ITEM_UNCHANGED, this);

                // restore container unchanged state also
                if (item->GetContainer())
                    item->GetContainer()->SetState(ITEM_UNCHANGED, this);
            }
            else
            {
                // Un probleme avec la maniere
                // dont le PNJ de Bienvenue ajoute le stuff ...
                //sLog.outError("Player::_LoadInventory: Player %s has item (GUID: %u Entry: %u) can't be loaded to inventory (Bag GUID: %u Slot: %u) by some reason, will send by mail.", GetName(),item_lowguid, item_id, bag_guid, slot);
                CharacterDatabase.PExecute("DELETE FROM `character_inventory` WHERE `item_guid` = '%u'", item_lowguid);
                problematicItems.push_back(item);
                std::stringstream oss;
                oss << "Broken item " << item->GetEntry() << " GUID:" << item->GetGUIDLow() << " count:" << item->GetCount() << " bag:" << bag_guid << " slot:" << uint32(slot);
                GetSession()->ProcessAnticheatAction("PassiveAnticheat", oss.str().c_str(), CHEAT_ACTION_LOG);
            }
        }
        while (result->NextRow());
        m_itemUpdateQueueBlocked = false;

        // send by mail problematic items
        while (!problematicItems.empty())
        {
            std::string subject = GetSession()->GetMangosString(LANG_NOT_EQUIPPED_ITEM);

            // fill mail
            MailDraft draft(subject);

            for (int i = 0; !problematicItems.empty() && i < MAX_MAIL_ITEMS; ++i)
            {
                Item* item = problematicItems.front();
                problematicItems.pop_front();

                draft.AddItem(item);
            }

            draft.SendMailTo(this, MailSender(this, MAIL_STATIONERY_GM), MAIL_CHECK_MASK_COPIED);
        }
        
        // if (IsAlive())
        _ApplyAllItemMods();
        return true;
    }
    
    return false;
}

void Player::_LoadItemLoot(QueryResult* result)
{
    //QueryResult* result = CharacterDatabase.PQuery("SELECT guid, item_id, amount, property FROM item_loot WHERE guid = '%u'", GetGUIDLow());

    if (result)
    {
        do
        {
            Field* fields = result->Fetch();
            uint32 item_guid   = fields[0].GetUInt32();

            Item* item = GetItemByGuid(ObjectGuid(HIGHGUID_ITEM, item_guid));

            if (!item)
            {
                CharacterDatabase.PExecute("DELETE FROM `item_loot` WHERE `guid` = '%u'", item_guid);
                sLog.outError("Player::_LoadItemLoot: Player %s has loot for nonexistent item (GUID: %u) in `item_loot`, deleted.", GetName(), item_guid);
                continue;
            }

            item->LoadLootFromDB(fields);

        }
        while (result->NextRow());
    }
}

void Player::LoadPet()
{
    //fixme: the pet should still be loaded if the player is not in world
    // just not added to the map
    if (IsInWorld())
    {
        Pet* pet = new Pet;
        if (!pet->LoadPetFromDB(this, 0, 0, true))
            delete pet;
    }
}

void Player::_LoadQuestStatus(QueryResult* result)
{
    mQuestStatus.clear();

    uint32 slot = 0;

    ////                                                     0      1       2         3         4      5           6           7           8           9            10           11           12           13
    //QueryResult* result = CharacterDatabase.PQuery("SELECT quest, status, rewarded, explored, timer, mob_count1, mob_count2, mob_count3, mob_count4, item_count1, item_count2, item_count3, item_count4, reward_choice FROM character_queststatus WHERE guid = '%u'", GetGUIDLow());

    if (result)
    {
        do
        {
            Field* fields = result->Fetch();

            uint32 quest_id = fields[0].GetUInt32();
            // used to be new, no delete?
            Quest const* pQuest = sObjectMgr.GetQuestTemplate(quest_id);
            if (pQuest)
            {
                // find or create
                QuestStatusData& questStatusData = mQuestStatus[quest_id];

                uint32 qstatus = fields[1].GetUInt32();
                if (qstatus < MAX_QUEST_STATUS)
                    questStatusData.m_status = QuestStatus(qstatus);
                else
                {
                    questStatusData.m_status = QUEST_STATUS_NONE;
                    sLog.outError("Player %s have invalid quest %d status (%d), replaced by QUEST_STATUS_NONE(0).", GetName(), quest_id, qstatus);
                }

                questStatusData.m_rewarded = (fields[2].GetUInt8() > 0);
                questStatusData.m_explored = (fields[3].GetUInt8() > 0);

                time_t quest_time = time_t(fields[4].GetUInt64());

                if (pQuest->HasSpecialFlag(QUEST_SPECIAL_FLAG_TIMED) && !GetQuestRewardStatus(quest_id) && questStatusData.m_status != QUEST_STATUS_NONE)
                {
                    AddTimedQuest(quest_id);

                    if (quest_time <= sWorld.GetGameTime())
                        questStatusData.m_timer = 1;
                    else
                        questStatusData.m_timer = uint32(quest_time - sWorld.GetGameTime()) * IN_MILLISECONDS;
                }
                else
                    quest_time = 0;

                questStatusData.m_creatureOrGOcount[0] = fields[5].GetUInt32();
                questStatusData.m_creatureOrGOcount[1] = fields[6].GetUInt32();
                questStatusData.m_creatureOrGOcount[2] = fields[7].GetUInt32();
                questStatusData.m_creatureOrGOcount[3] = fields[8].GetUInt32();
                questStatusData.m_itemcount[0] = fields[9].GetUInt32();
                questStatusData.m_itemcount[1] = fields[10].GetUInt32();
                questStatusData.m_itemcount[2] = fields[11].GetUInt32();
                questStatusData.m_itemcount[3] = fields[12].GetUInt32();

                questStatusData.uState = QUEST_UNCHANGED;

                // add to quest log
                if (slot < MAX_QUEST_LOG_SIZE &&
                        ((questStatusData.m_status == QUEST_STATUS_INCOMPLETE ||
                          questStatusData.m_status == QUEST_STATUS_COMPLETE ||
                          questStatusData.m_status == QUEST_STATUS_FAILED) &&
                         (!questStatusData.m_rewarded || pQuest->IsRepeatable())))
                {
                    SetQuestSlot(slot, quest_id, uint32(quest_time));

                    if (questStatusData.m_explored)
                        SetQuestSlotState(slot, QUEST_STATE_COMPLETE);

                    if (questStatusData.m_status == QUEST_STATUS_COMPLETE)
                        SetQuestSlotState(slot, QUEST_STATE_COMPLETE);

                    if (questStatusData.m_status == QUEST_STATUS_FAILED)
                        SetQuestSlotState(slot, QUEST_STATE_FAIL);

                    for (uint8 idx = 0; idx < QUEST_OBJECTIVES_COUNT; ++idx)
                        if (questStatusData.m_creatureOrGOcount[idx])
                            SetQuestSlotCounter(slot, idx, questStatusData.m_creatureOrGOcount[idx]);

                    ++slot;
                }

                if (questStatusData.m_rewarded)
                {
                    questStatusData.m_reward_choice = fields[13].GetUInt32();
                    LearnQuestRewardedSpells(pQuest); // learn rewarded spell if unknown
                }

                DEBUG_LOG("Quest status is {%u} for quest {%u} for player (GUID: %u)", questStatusData.m_status, quest_id, GetGUIDLow());
            }
        }
        while (result->NextRow());
    }

    // clear quest log tail
    for (uint16 i = slot; i < MAX_QUEST_LOG_SIZE; ++i)
        SetQuestSlot(i, 0);
}

void Player::_LoadSpells(QueryResult* result)
{
    //QueryResult* result = CharacterDatabase.PQuery("SELECT spell,active,disabled FROM character_spell WHERE guid = '%u'",GetGUIDLow());

    if (result)
    {
        do
        {
            Field* fields = result->Fetch();

            uint32 spellId = fields[0].GetUInt32();

            AddSpell(spellId, fields[1].GetBool(), false, false, fields[2].GetBool());
        }
        while (result->NextRow());
    }
}

void Player::_LoadGroup(QueryResult* result)
{
    //QueryResult* result = CharacterDatabase.PQuery("SELECT group_id FROM group_member WHERE member_guid='%u'", GetGUIDLow());
    if (result)
    {
        uint32 groupId = (*result)[0].GetUInt32();

        if (Group* group = sObjectMgr.GetGroupById(groupId))
        {
            uint8 subgroup = group->GetMemberGroup(GetObjectGuid());
            SetGroup(group, subgroup);
        }
    }
    UpdateGroupLeaderFlag();
}

void Player::_LoadBoundInstances(QueryResult* result)
{
    m_boundInstances.clear();

    Group* group = GetGroup();

    //QueryResult* result = CharacterDatabase.PQuery("SELECT id, permanent, map, reset_time FROM character_instance LEFT JOIN instance ON instance = id WHERE guid = '%u'", GUID_LOPART(m_guid));
    if (result)
    {
        do
        {
            Field* fields = result->Fetch();
            bool perm = fields[1].GetBool();
            uint32 mapId = fields[2].GetUInt32();
            uint32 instanceId = fields[0].GetUInt32();
            time_t resetTime = (time_t)fields[3].GetUInt64();
            // the reset_time for normal instances is only saved when the InstanceSave is unloaded
            // so the value read from the DB may be wrong here but only if the InstanceSave is loaded
            // and in that case it is not used

            MapEntry const* mapEntry = sMapStorage.LookupEntry<MapEntry>(mapId);
            if (!mapEntry || !mapEntry->IsDungeon())
            {
                sLog.outError("_LoadBoundInstances: player %s(%d) has bind to nonexistent or not dungeon map %d", GetName(), GetGUIDLow(), mapId);
                CharacterDatabase.PExecute("DELETE FROM `character_instance` WHERE `guid` = '%u' AND `instance` = '%u'", GetGUIDLow(), instanceId);
                continue;
            }

            if (!perm && group)
            {
                sLog.outError("_LoadBoundInstances: %s is in group (Id: %d) but has a non-permanent character bind to map %d,%d",
                              GetGuidStr().c_str(), group->GetId(), mapId, instanceId);
                CharacterDatabase.PExecute("DELETE FROM `character_instance` WHERE `guid` = '%u' AND `instance` = '%u'",
                                           GetGUIDLow(), instanceId);
                continue;
            }

            // since non permanent binds are always solo bind, they can always be reset
            DungeonPersistentState* state = (DungeonPersistentState*)sMapPersistentStateMgr.AddPersistentState(mapEntry, instanceId, resetTime, !perm, true);
            if (state) BindToInstance(state, perm, true);
        }
        while (result->NextRow());
    }
}

InstancePlayerBind* Player::GetBoundInstance(uint32 mapid)
{
    BoundInstancesMap::iterator itr = m_boundInstances.find(mapid);
    if (itr != m_boundInstances.end())
        return &itr->second;
    else
        return nullptr;
}

void Player::UnbindInstance(uint32 mapid, bool unload)
{
    BoundInstancesMap::iterator itr = m_boundInstances.find(mapid);
    UnbindInstance(itr, unload);
}

void Player::UnbindInstance(BoundInstancesMap::iterator &itr, bool unload)
{
    if (itr != m_boundInstances.end())
    {
        if (!unload)
            CharacterDatabase.PExecute("DELETE FROM `character_instance` WHERE `guid` = '%u' AND `instance` = '%u'",
                                       GetGUIDLow(), itr->second.state->GetInstanceId());
        itr->second.state->RemovePlayer(this);              // state can become invalid
        m_boundInstances.erase(itr++);
    }
}

InstancePlayerBind* Player::BindToInstance(DungeonPersistentState* state, bool permanent, bool load)
{
    if (state)
    {
        ASSERT(state->GetMapId() > 1);
        InstancePlayerBind& bind = m_boundInstances[state->GetMapId()];

        if (bind.state)
        {
            // update the state when the group kills a boss
            if (permanent != bind.perm || state != bind.state)
                if (!load)
                    CharacterDatabase.PExecute("UPDATE `character_instance` SET `instance` = '%u', `permanent` = '%u' WHERE `guid` = '%u' AND `instance` = '%u'",
                                               state->GetInstanceId(), permanent, GetGUIDLow(), bind.state->GetInstanceId());
        }
        else
        {
            if (!load)
                CharacterDatabase.PExecute("INSERT INTO `character_instance` (`guid`, `instance`, `permanent`) VALUES ('%u', '%u', '%u')",
                                           GetGUIDLow(), state->GetInstanceId(), permanent);
        }

        if (bind.state != state)
        {
            if (bind.state)
                bind.state->RemovePlayer(this);
            state->AddPlayer(this);
        }

        if (permanent)
            state->SetCanReset(false);

        bind.state = state;
        bind.perm = permanent;
        if (!load)
            DEBUG_LOG("Player::BindToInstance: %s(%d) is now bound to map %d, instance %d",
                      GetName(), GetGUIDLow(), state->GetMapId(), state->GetInstanceId());
        return &bind;
    }
    else
        return nullptr;
}

DungeonPersistentState* Player::GetBoundInstanceSaveForSelfOrGroup(uint32 mapid)
{
    MapEntry const* mapEntry = sMapStorage.LookupEntry<MapEntry>(mapid);
    if (!mapEntry)
        return nullptr;

    InstancePlayerBind* pBind = GetBoundInstance(mapid);
    DungeonPersistentState* state = pBind ? pBind->state : nullptr;

    // the player's permanent player bind is taken into consideration first
    // then the player's group bind and finally the solo bind.
    if (!pBind || !pBind->perm)
    {
        if (Group* group = GetGroup())
            if (InstanceGroupBind* groupBind = group->GetBoundInstance(mapid))
                state = groupBind->state;
    }

    return state;
}

void Player::SendRaidInfo() const
{
    uint32 counter = 0;

    WorldPacket data(SMSG_RAID_INSTANCE_INFO, 4);

    size_t p_counter = data.wpos();
    data << uint32(counter);                                // placeholder

    for (const auto& itr : m_boundInstances)
    {
        if (itr.second.perm)
        {
            DungeonPersistentState* state = itr.second.state;
            data << uint32(state->GetMapId());              // map id

            // Permanent dungeons (raids) don't have a valid reset timer since it's
            // on a schedule. Send the scheduled time instead of state reset time
            time_t resetTime = sMapPersistentStateMgr.GetScheduler().GetResetTimeFor(state->GetMapId());
            data << uint32(resetTime - time(nullptr));
            data << uint32(state->GetInstanceId());         // instance id

            counter++;
        }
    }

    data.put<uint32>(p_counter, counter);
    GetSession()->SendPacket(&data);
}

/*
- called on every successful teleportation to a map
*/
void Player::SendSavedInstances() const
{
#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_8_4
    bool hasBeenSaved = false;
    WorldPacket data;

    for (const auto& itr : m_boundInstances)
    {
        if (itr.second.perm)                               // only permanent binds are sent
        {
            hasBeenSaved = true;
            break;
        }
    }

    //Send opcode 811. true or false means, whether you have current raid instances
    data.Initialize(SMSG_UPDATE_INSTANCE_OWNERSHIP, 4);
    data << uint32(hasBeenSaved);
    GetSession()->SendPacket(&data);

    if (!hasBeenSaved)
        return;

    for (const auto& itr : m_boundInstances)
    {
        if (itr.second.perm)
        {
            data.Initialize(SMSG_UPDATE_LAST_INSTANCE, 4);
            data << uint32(itr.second.state->GetMapId());
            GetSession()->SendPacket(&data);
        }
    }
#endif
}

/// convert the player's binds to the group
void Player::ConvertInstancesToGroup(Player* player, Group* group, ObjectGuid player_guid)
{
    bool has_binds = false;
    bool has_solo = false;

    if (player)
    {
        player_guid = player->GetObjectGuid();
        if (!group)
            group = player->GetGroup();
    }

    MANGOS_ASSERT(player_guid);

    // copy all binds to the group, when changing leader it's assumed the character
    // will not have any solo binds

    if (player)
    {
        for (BoundInstancesMap::iterator itr = player->m_boundInstances.begin(); itr != player->m_boundInstances.end();)
        {
            has_binds = true;

            if (group)
                group->BindToInstance(itr->second.state, itr->second.perm, true);

            // permanent binds are not removed
            if (!itr->second.perm)
            {
                // increments itr in call
                player->UnbindInstance(itr, true);
                has_solo = true;
            }
            else
                ++itr;
        }
    }

    uint32 player_lowguid = player_guid.GetCounter();

    // if the player's not online we don't know what binds it has
    if (!player || !group || has_binds)
        CharacterDatabase.PExecute("INSERT INTO `group_instance` SELECT `guid`, `instance`, `permanent` FROM `character_instance` WHERE `guid` = '%u'", player_lowguid);

    // the following should not get executed when changing leaders
    if (!player || has_solo)
        CharacterDatabase.PExecute("DELETE FROM `character_instance` WHERE `guid` = '%u' AND `permanent` = 0", player_lowguid);
}

bool Player::_LoadHomeBind(QueryResult* result)
{
    PlayerInfo const* info = sObjectMgr.GetPlayerInfo(GetRace(), GetClass());
    if (!info)
    {
        sLog.outError("Player have incorrect race/class pair. Can't be loaded.");
        return false;
    }

    bool ok = false;
    //QueryResult* result = CharacterDatabase.PQuery("SELECT map,zone,position_x,position_y,position_z FROM character_homebind WHERE guid = '%u'", GUID_LOPART(playerGuid));
    if (result)
    {
        Field* fields = result->Fetch();
        m_homebindMapId = fields[0].GetUInt32();
        m_homebindAreaId = fields[1].GetUInt16();
        m_homebindX = fields[2].GetFloat();
        m_homebindY = fields[3].GetFloat();
        m_homebindZ = fields[4].GetFloat();

        MapEntry const* bindMapEntry = sMapStorage.LookupEntry<MapEntry>(m_homebindMapId);

        // accept saved data only for valid position (and non instanceable), and accessable
        if (MapManager::IsValidMapCoord(m_homebindMapId, m_homebindX, m_homebindY, m_homebindZ) &&
                !bindMapEntry->Instanceable())
            ok = true;
        else
            CharacterDatabase.PExecute("DELETE FROM `character_homebind` WHERE `guid` = '%u'", GetGUIDLow());
    }

    if (!ok)
    {
        m_homebindMapId = info->mapId;
        m_homebindAreaId = info->areaId;
        m_homebindX = info->positionX;
        m_homebindY = info->positionY;
        m_homebindZ = info->positionZ;

        CharacterDatabase.PExecute("INSERT INTO `character_homebind` (`guid`, `map`, `zone`, `position_x`, `position_y`, `position_z`) VALUES ('%u', '%u', '%u', '%f', '%f', '%f')", GetGUIDLow(), m_homebindMapId, (uint32)m_homebindAreaId, m_homebindX, m_homebindY, m_homebindZ);
    }

    DEBUG_LOG("Setting player home position: mapid is: %u, zoneid is %u, X is %f, Y is %f, Z is %f",
              m_homebindMapId, m_homebindAreaId, m_homebindX, m_homebindY, m_homebindZ);

    return true;
}

void Player::_LoadGuild(QueryResult* result)
{
    //"SELECT guild_id, rank FROM guild_member WHERE guid = '%u'",pCurrChar->GetGUIDLow());

    if (result)
    {
        Field* fields = result->Fetch();
        SetInGuild(fields[0].GetUInt32());
        SetRank(fields[1].GetUInt32());
    }
    else                       // clear guild related fields in case wrong data about nonexistent membership
    {
        SetInGuild(0);
        SetRank(0);
    }

    if (GetGuildId() != 0)
    {
        Guild* guild = sGuildMgr.GetGuildById(GetGuildId());
        if (!guild)
        {
            // remove wrong guild data
            sLog.outError("%s marked as member of nonexistent guild (id: %u), removing guild membership for player.", GetGuidStr().c_str(), GetGuildId());
            SetInGuild(0);
            SetRank(0);
        }
    }
}

/*********************************************************/
/***                   SAVE SYSTEM                     ***/
/*********************************************************/

bool Player::SaveNewPlayer(WorldSession* session, uint32 guidlow, std::string const& name, uint8 raceId, uint8 classId, uint8 gender, uint8 skin, uint8 face, uint8 hairStyle, uint8 hairColor, uint8 facialHair)
{
    PlayerInfo const* info = sObjectMgr.GetPlayerInfo(raceId, classId);
    if (!info)
    {
        sLog.outError("Player have incorrect race/class pair. Can't be loaded.");
        return false;
    }

    ChrClassesEntry const* cEntry = sChrClassesStore.LookupEntry(classId);
    if (!cEntry)
    {
        sLog.outError("Class %u not found in DBC (Wrong DBC files?)", classId);
        return false;
    }

    // player store gender in single bit
    if (gender != uint8(GENDER_MALE) && gender != uint8(GENDER_FEMALE))
    {
        sLog.outError("Invalid gender %u at player creating", uint32(gender));
        return false;
    }

    CharacterDatabase.BeginTransaction(guidlow);

    static SqlStatementID insChar;

    SqlStatement uberInsert = CharacterDatabase.CreateStatement(insChar,"REPLACE INTO `characters` (`guid`, `account`, `name`, `race`, `class`, `gender`, `level`, `money`, "
        "`skin`, `face`, `hair_style`, `hair_color`, `facial_hair`, "
        "`map`, `position_x`, `position_y`, `position_z`, `orientation`, "
        "`known_taxi_mask`, `current_taxi_path`, `online`, `extra_flags`, `at_login_flags`, "
        "`health`, `power1`, `power2`, `power3`, `power4`, `power5`, "
        "`explored_zones`, `equipment_cache`, `ammo_id`, `world_phase_mask`, `create_time`, `logout_time`) "
        "VALUES ( ?, ?, ?, ?, ?, ?, ?, ?, "
        "?, ?, ?, ?, ?, "
        "?, ?, ?, ?, ?, "
        "?, ?, ?, ?, ?, "
        "?, ?, ?, ?, ?, ?, "
        "?, ?, ?, ?, ?, ?)");

    uberInsert.addUInt32(guidlow);
    uberInsert.addUInt32(session->GetAccountId());
    uberInsert.addString(name);
    uberInsert.addUInt8(raceId);
    uberInsert.addUInt8(classId);
    uberInsert.addUInt8(gender);

    uint32 const startingLevel = sWorld.getConfig((session->GetSecurity() >= SEC_MODERATOR) ? CONFIG_UINT32_START_GM_LEVEL : CONFIG_UINT32_START_PLAYER_LEVEL);
    uberInsert.addUInt32(startingLevel);
    uberInsert.addUInt32(sWorld.getConfig(CONFIG_UINT32_START_PLAYER_MONEY));

    uberInsert.addInt8(skin);
    uberInsert.addInt8(face);
    uberInsert.addInt8(hairStyle);
    uberInsert.addInt8(hairColor);
    uberInsert.addUInt8(facialHair);

    uberInsert.addUInt32(info->mapId);
    uberInsert.addFloat(info->positionX);
    uberInsert.addFloat(info->positionY);
    uberInsert.addFloat(info->positionZ);
    uberInsert.addFloat(info->orientation);

    PlayerTaxi taxi;
    taxi.InitTaxiNodes(raceId, classId);
    std::ostringstream ss;
    ss << taxi; // string with TaxiMaskSize numbers
    uberInsert.addString(ss);

    ss << taxi.SaveTaxiDestinationsToString(); // string
    uberInsert.addString(ss);

    uberInsert.addUInt32(0); // online

    uint32 extraFlags = 0;
    if (session->GetSecurity() > SEC_PLAYER)
        extraFlags |= PLAYER_EXTRA_GM_ACCEPT_TICKETS;
    else
        extraFlags |= PLAYER_EXTRA_ACCEPT_WHISPERS;
    uberInsert.addUInt32(extraFlags);

    uberInsert.addUInt32(AT_LOGIN_FIRST); // login flags

    PlayerLevelInfo levelInfo;
    sObjectMgr.GetPlayerLevelInfo(raceId, classId, startingLevel, &levelInfo);

    PlayerClassLevelInfo classInfo;
    sObjectMgr.GetPlayerClassLevelInfo(classId, startingLevel, &classInfo);

    uint32 hp = uint32(classInfo.basehealth + GetHealthBonusFromStamina(levelInfo.stats[STAT_STAMINA]));
    uint32 powers[MAX_POWERS] = {};
    if (cEntry->powerType == POWER_MANA)
        powers[POWER_MANA] = uint32(classInfo.basemana + GetManaBonusFromIntellect(levelInfo.stats[STAT_INTELLECT]));
    else if (cEntry->powerType == POWER_ENERGY)
        powers[POWER_ENERGY] = 100;

    uberInsert.addUInt32(hp);

    for (uint32 i = 0; i < MAX_POWERS; ++i)
        uberInsert.addUInt32(powers[i]);

    for (uint32 i = 0; i < PLAYER_EXPLORED_ZONES_SIZE; ++i)
        ss << "0 ";
    uberInsert.addString(ss); // explored zones

    uint32 ammoId = 0;
    uint32 startingItems[INVENTORY_SLOT_BAG_START+1] = {};

    // Starting items.
    for (const auto& itr : info->item)
    {
        if (ItemPrototype const* pProto = sObjectMgr.GetItemPrototype(itr.item_id))
        {
            uint8 slots[4];
            pProto->GetAllowedEquipSlots(slots, classId, false);

            for (uint32 i = 0; i < 4; i++)
            {
                if (slots[i] != NULL_SLOT)
                {
                    if (!startingItems[slots[i]])
                        startingItems[slots[i]] = itr.item_id;
                }
            }

            if (pProto->InventoryType == INVTYPE_AMMO)
                ammoId = itr.item_id;
        }
    }

    for (uint32 i = 0; i < INVENTORY_SLOT_BAG_START + 1; ++i)         // string: item id, ench (perm/temp)
    {
        ss << startingItems[i] << " ";
        ss << uint32(MAKE_PAIR32(0, 0)) << " ";
    }

    uberInsert.addString(ss);

    uberInsert.addUInt32(ammoId);
    uberInsert.addUInt32(WORLD_DEFAULT_CHAR);
    uberInsert.addUInt64(uint64(time(nullptr))); // create time
    uberInsert.addUInt64(uint64(time(nullptr))); // logout time (for rested xp)
    uberInsert.Execute();

    sObjectMgr.SetPlayerWorldMask(guidlow, WORLD_DEFAULT_CHAR);
    session->SaveTutorialsData(); // changed only while character in game

    CharacterDatabase.CommitTransaction();

    uint32 zoneId = 0;
    uint32 areaId = 0;
    if (auto map = sMapMgr.FindMap(info->mapId))
        map->GetTerrain()->GetZoneAndAreaId(zoneId, areaId, info->positionX, info->positionY, info->positionZ);

    MasterPlayer masterPlayer(session);
    masterPlayer.Create(ObjectGuid(HIGHGUID_PLAYER, guidlow), raceId, classId);
    masterPlayer.SaveToDB();
    PlayerCacheData* cacheData = sObjectMgr.InsertPlayerInCache(guidlow, raceId, classId, gender, session->GetAccountId(), name, startingLevel, zoneId);
    sObjectMgr.UpdatePlayerCachedPosition(cacheData, info->mapId, info->positionX, info->positionY, info->positionZ, info->orientation, false);
    sWorld.LogCharacter(session, guidlow, name, "Create");

    return true;
}

void Player::SaveToDB(bool online, bool force)
{
    // we should assure this: ASSERT((m_nextSave != sWorld.getConfig(CONFIG_UINT32_INTERVAL_SAVE)));
    // delay auto save at any saves (manual, in code, or autosave)
    m_nextSave = sWorld.getConfig(CONFIG_UINT32_INTERVAL_SAVE);

    // Do not save bots
    if (IsBot())
        return;
    if (m_DbSaveDisabled)
        return;

    //lets allow only players in world to be saved
    if (!force && IsBeingTeleportedFar())
    {
        ScheduleDelayedOperation(DELAYED_SAVE_PLAYER);
        return;
    }

    //DEBUG_FILTER_LOG(LOG_FILTER_PLAYER_STATS, "The value of player %s at save: ", m_name.c_str());
    //outDebugStatsValues();

    CharacterDatabase.BeginTransaction(GetGUIDLow());

    m_honorMgr.Update();

    static SqlStatementID insChar;

    SqlStatement uberInsert = CharacterDatabase.CreateStatement(insChar, "REPLACE INTO `characters` (`guid`, `account`, `name`, `race`, `class`, `gender`, `level`, `xp`, `money`, `skin`, `face`, `hair_style`, `hair_color`, `facial_hair`, `bank_bag_slots`, `player_flags`,"
                              "`map`, `position_x`, `position_y`, `position_z`, `orientation`, "
                              "`transport_guid`, `transport_x`, `transport_y`, `transport_z`, `transport_o`, "
                              "`known_taxi_mask`, `current_taxi_path`, `online`, `played_time_total`, `played_time_level`, "
                              "`rest_bonus`, `logout_time`, `is_logout_resting`, `reset_talents_multiplier`, `reset_talents_time`, "
                              "`extra_flags`, `stable_slots`, `at_login_flags`, `zone`, `death_expire_time`,"
                              "`honor_rank_points`, `honor_highest_rank`, `honor_standing`, `honor_last_week_hk`, `honor_last_week_cp`, `honor_stored_hk`, `honor_stored_dk`, "
                              "`watched_faction`, `drunk`, `health`, `power1`, `power2`, `power3`, `power4`, `power5`, "
                              "`explored_zones`, `equipment_cache`, `ammo_id`, `action_bars`, `world_phase_mask`, `create_time`) "
                              "VALUES ( ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, "
                              "?, ?, ?, ?, ?, "
                               "?, ?, ?, ?, ?, "
                              "?, ?, ?, ?, ?, "
                              "?, ?, ?, ?, ?, "
                              "?, ?, ?, ?, ?, "
                              "?, ?, ?, ?, ?, ?, ?, "
                              "?, ?, ?, ?, ?, ?, ?, ?, "
                              "?, ?, ?, ?, ?, ?)");

    uberInsert.addUInt32(GetGUIDLow());
    uberInsert.addUInt32(GetSession()->GetAccountId());
    uberInsert.addString(m_name);
    uberInsert.addUInt8(GetRace());
    uberInsert.addUInt8(GetClass());
    uberInsert.addUInt8(GetGender());
    uberInsert.addUInt32(GetLevel());
    uberInsert.addUInt32(GetUInt32Value(PLAYER_XP));
    uberInsert.addUInt32(GetMoney());
    uberInsert.addUInt8(GetByteValue(PLAYER_BYTES, 0));     // skin
    uberInsert.addUInt8(GetByteValue(PLAYER_BYTES, 1));     // face
    uberInsert.addUInt8(GetByteValue(PLAYER_BYTES, 2));     // hair style
    uberInsert.addUInt8(GetByteValue(PLAYER_BYTES, 3));     // hair color
    uberInsert.addUInt32(GetByteValue(PLAYER_BYTES_2, 0));  // facial hair
    uberInsert.addUInt32(GetByteValue(PLAYER_BYTES_2, 2));  // bank bag slots

    // Nostalrius: Fix toggled PvP flag after relog.
    uint32 playerFlags = GetUInt32Value(PLAYER_FLAGS) & ~(PLAYER_FLAGS_PVP_DESIRED);
    if (IsPvP())
        playerFlags |= PLAYER_FLAGS_PVP_DESIRED;
    uberInsert.addUInt32(playerFlags);

    if (!IsBeingTeleported())
    {
        uberInsert.addUInt32(GetMapId());
        uberInsert.addFloat(finiteAlways(GetPositionX()));
        uberInsert.addFloat(finiteAlways(GetPositionY()));
        uberInsert.addFloat(finiteAlways(GetPositionZ()));
        uberInsert.addFloat(MapManager::NormalizeOrientation(finiteAlways(GetOrientation())));
    }
    else
    {
        uberInsert.addUInt32(GetTeleportDest().mapId);
        uberInsert.addFloat(finiteAlways(GetTeleportDest().x));
        uberInsert.addFloat(finiteAlways(GetTeleportDest().y));
        uberInsert.addFloat(finiteAlways(GetTeleportDest().z));
        uberInsert.addFloat(MapManager::NormalizeOrientation(finiteAlways(GetTeleportDest().o)));
    }

    if (m_transport)
        uberInsert.addUInt32(m_transport->GetGUIDLow());
    else
        uberInsert.addUInt32(0);
    uberInsert.addFloat(finiteAlways(m_movementInfo.GetTransportPos().x));
    uberInsert.addFloat(finiteAlways(m_movementInfo.GetTransportPos().y));
    uberInsert.addFloat(finiteAlways(m_movementInfo.GetTransportPos().z));
    uberInsert.addFloat(MapManager::NormalizeOrientation(finiteAlways(m_movementInfo.GetTransportPos().o)));

    std::ostringstream ss;
    ss << m_taxi;                                   // string with TaxiMaskSize numbers
    uberInsert.addString(ss);

    ss << m_taxi.SaveTaxiDestinationsToString();
    uberInsert.addString(ss);

    if (!IsInWorld())
        online = false;
    uberInsert.addUInt32(online);

    uberInsert.addUInt32(m_playedTime[PLAYED_TIME_TOTAL]);
    uberInsert.addUInt32(m_playedTime[PLAYED_TIME_LEVEL]);

    uberInsert.addFloat(finiteAlways(m_restBonus));
    uberInsert.addUInt64(uint64(time(nullptr)));
    uberInsert.addUInt32(HasFlag(PLAYER_FLAGS, PLAYER_FLAGS_RESTING) ? 1 : 0);

    uberInsert.addUInt32(m_resetTalentsMultiplier);
    uberInsert.addUInt64(uint64(m_resetTalentsTime));

    uberInsert.addUInt32(m_ExtraFlags);

    uberInsert.addUInt32(uint32(m_stableSlots));                    // to prevent save uint8 as char

    uberInsert.addUInt32(uint32(m_atLoginFlags));

    uberInsert.addUInt32(IsInWorld() ? GetZoneId() : GetCachedZoneId());

    uberInsert.addUInt64(uint64(m_deathExpireTime));

    // Honor stored data
    uberInsert.addFloat(finiteAlways(m_honorMgr.GetRankPoints()));
    uberInsert.addUInt32(uint32(m_honorMgr.GetHighestRank().rank));
    uberInsert.addUInt32(m_honorMgr.GetStanding());
    uberInsert.addUInt32(m_honorMgr.GetLastWeekHK());
    uberInsert.addFloat(finiteAlways(m_honorMgr.GetLastWeekCP()));
    uberInsert.addUInt32(m_honorMgr.GetStoredHK());
    uberInsert.addUInt32(m_honorMgr.GetStoredDK());

#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_9_4
    uberInsert.addInt32(GetInt32Value(PLAYER_FIELD_WATCHED_FACTION_INDEX));
#else
    uberInsert.addInt32(-1);
#endif

    uberInsert.addUInt16(uint16(GetUInt32Value(PLAYER_BYTES_3) & 0xFFFE));

    uberInsert.addUInt32(GetHealth());

    for (uint32 i = 0; i < MAX_POWERS; ++i)
        uberInsert.addUInt32(GetPower(Powers(i)));

    for (uint32 i = 0; i < PLAYER_EXPLORED_ZONES_SIZE; ++i)         //string
        ss << GetUInt32Value(PLAYER_EXPLORED_ZONES_1 + i) << " ";
    uberInsert.addString(ss);

    for (uint32 i = 0; i < EQUIPMENT_SLOT_END; ++i)         //string: item id, ench (perm/temp)
    {
        ss << GetUInt32Value(PLAYER_VISIBLE_ITEM_1_0 + i * MAX_VISIBLE_ITEM_OFFSET) << " ";

        uint32 ench1 = GetUInt32Value(PLAYER_VISIBLE_ITEM_1_0 + i * MAX_VISIBLE_ITEM_OFFSET + 1 + PERM_ENCHANTMENT_SLOT);
        uint32 ench2 = GetUInt32Value(PLAYER_VISIBLE_ITEM_1_0 + i * MAX_VISIBLE_ITEM_OFFSET + 1 + TEMP_ENCHANTMENT_SLOT);
        ss << uint32(MAKE_PAIR32(ench1, ench2)) << " ";
    }
    // 1 in vanilla/tbc - 4 in wotlk
    for (uint32 i = INVENTORY_SLOT_BAG_START; i < INVENTORY_SLOT_BAG_START + 1; ++i) // string: item id, ench (perm/temp)
    {
        ss << (m_items[i] ? m_items[i]->GetEntry() : 0) << " ";
        ss << uint32(MAKE_PAIR32(0, 0)) << " ";
    }
    uberInsert.addString(ss);

    uberInsert.addUInt32(GetUInt32Value(PLAYER_AMMO_ID));

    uberInsert.addUInt32(uint32(GetByteValue(PLAYER_FIELD_BYTES, 2)));
    uberInsert.addUInt32(GetWorldMask());
    uberInsert.addUInt64(uint64(m_createTime));
    uberInsert.Execute();

    _SaveBGData();
    _SaveInventory();
    _SaveQuestStatus();
    _SaveSpells();
    _SaveSpellCooldowns();
    _SaveAuras();
    _SaveSkills();
    m_reputationMgr.SaveToDB();
    m_honorMgr.Save();

    // Systeme de phasing
    sObjectMgr.SetPlayerWorldMask(GetGUIDLow(), GetWorldMask());
    GetSession()->SaveTutorialsData();                      // changed only while character in game

    CharacterDatabase.CommitTransaction();

    // check if stats should only be saved on logout
    // save stats can be out of transaction
    if (m_session->isLogingOut() || !sWorld.getConfig(CONFIG_BOOL_STATS_SAVE_ONLY_ON_LOGOUT))
        _SaveStats();

    // save pet (hunter pet level and experience and all type pets health/mana).
    if (Pet* pet = GetPet())
        pet->SavePetToDB(PET_SAVE_AS_CURRENT);
    if (PlayerCacheData* data = sObjectMgr.GetPlayerDataByGUID(GetGUIDLow()))
    {
        data->uiLevel = GetLevel();
        data->uiZoneId = GetCachedZoneId();
    }
}

// fast save function for item/money cheating preventing - save only inventory and money state
// Must be serialized in a transaction with the player GUID, or it can lead to duping by
// relogging before the query completes
void Player::SaveInventoryAndGoldToDB()
{
    bool haveTransaction = CharacterDatabase.InTransaction();
    if (!haveTransaction)
        CharacterDatabase.BeginTransaction(GetGUIDLow());
    else if (CharacterDatabase.GetTransactionSerialId() != GetGUIDLow())
        sLog.outError("[PLAYER SAVE] Player %s items are being saved in a transaction that is not serialized with its own GUID... potential dupe avenue", GetGuidStr().c_str());

    _SaveInventory();
    SaveGoldToDB();

    if (!haveTransaction)
        CharacterDatabase.CommitTransaction();
}

// Must be serialized in a transaction with the player GUID, or it can lead to duping by
// relogging before the query completes
void Player::SaveGoldToDB()
{
    static SqlStatementID updateGold ;

    SqlStatement stmt = CharacterDatabase.CreateStatement(updateGold, "UPDATE `characters` SET `money` = ? WHERE `guid` = ?");
    stmt.PExecute(GetMoney(), GetGUIDLow());
}

void Player::_SaveAuras()
{
    static SqlStatementID deleteAuras ;
    static SqlStatementID insertAuras ;

    SqlStatement stmt = CharacterDatabase.CreateStatement(deleteAuras, "DELETE FROM `character_aura` WHERE `guid` = ?");
    stmt.PExecute(GetGUIDLow());

    SpellAuraHolderMap const& auraHolders = GetSpellAuraHolderMap();

    if (auraHolders.empty())
        return;

    stmt = CharacterDatabase.CreateStatement(insertAuras, "INSERT INTO `character_aura` (`guid`, `caster_guid`, `item_guid`, `spell`, `stacks`, `charges`, "
            "`base_points0`, `base_points1`, `base_points2`, `periodic_time0`, `periodic_time1`, `periodic_time2`, `max_duration`, `duration`, `effect_index_mask`) "
            "VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)");

    AuraSaveStruct s;
    for (const auto& auraHolder : auraHolders)
    {
        SpellAuraHolder* holder = auraHolder.second;

        if (!SaveAura(holder, s))
            continue;

        stmt.addUInt32(GetGUIDLow());
        stmt.addUInt64(s.casterGuid.GetRawValue());
        stmt.addUInt32(s.itemLowGuid);
        stmt.addUInt32(s.spellId);
        stmt.addUInt32(s.stacks);
        stmt.addUInt8(s.charges);

        for (float i : s.damage)
            stmt.addFloat(i);

        for (uint32 i : s.periodicTime)
            stmt.addUInt32(i);

        stmt.addInt32(s.maxDuration);
        stmt.addInt32(s.duration);
        stmt.addInt8(s.effIndexMask);
        stmt.Execute();
    }
}

bool Player::SaveAura(SpellAuraHolder* holder, AuraSaveStruct& saveStruct)
{
    // Double croise : pas de sauvegarde dans la DB (clef unique, peut pas avoir 2x meme aura)
    if (holder->GetId() == 20007)
        return false;

    //skip all holders from spells that are passive or channeled
    //do not save single target holders (unless they were cast by the player)
    if (!holder->IsPassive() && !holder->GetSpellProto()->IsChanneledSpell() && (holder->GetCasterGuid() == GetObjectGuid() || !holder->IsSingleTarget()))
    {
        saveStruct.effIndexMask = 0;

        for (uint8 i = 0; i < MAX_EFFECT_INDEX; ++i)
        {
            saveStruct.damage[i] = 0;
            saveStruct.periodicTime[i] = 0;

            if (Aura* aur = holder->GetAuraByEffectIndex(SpellEffectIndex(i)))
            {
                // don't save not own area auras
                if (aur->IsAreaAura() && holder->GetCasterGuid() != GetObjectGuid())
                    return false;

                saveStruct.damage[i] = aur->GetModifier()->m_amount;
                saveStruct.periodicTime[i] = aur->GetModifier()->periodictime;
                saveStruct.effIndexMask |= (1 << i);
            }
        }

        if (!saveStruct.effIndexMask)
            return false;

        saveStruct.casterGuid = holder->GetCasterGuid();
        saveStruct.itemLowGuid = holder->GetCastItemGuid().GetCounter();
        saveStruct.spellId = holder->GetId();
        saveStruct.stacks = holder->GetStackAmount();
        saveStruct.charges = holder->GetAuraCharges();
        saveStruct.duration = holder->GetAuraDuration();
        saveStruct.maxDuration = holder->GetAuraMaxDuration();
        for (uint8 i = 0; i < MAX_EFFECT_INDEX; ++i)
            saveStruct.charges = holder->GetAuraCharges();
        return true;
    }
    return false;
}

void Player::_SaveInventory()
{
    // force items in buyback slots to new state
    // and remove those that aren't already
    for (uint8 i = BUYBACK_SLOT_START; i < BUYBACK_SLOT_END; ++i)
    {
        Item* item = m_items[i];
        if (!item || item->GetState() == ITEM_NEW) continue;

        static SqlStatementID delInv ;
        static SqlStatementID delItemInst ;

        SqlStatement stmt = CharacterDatabase.CreateStatement(delInv, "DELETE FROM `character_inventory` WHERE `item_guid` = ?");
        stmt.PExecute(item->GetGUIDLow());

        stmt = CharacterDatabase.CreateStatement(delItemInst, "DELETE FROM `item_instance` WHERE `guid` = ?");
        stmt.PExecute(item->GetGUIDLow());

        m_items[i]->FSetState(ITEM_NEW);
    }

    // update enchantment durations
    for (auto& itr : m_enchantDuration)
        itr.item->SetEnchantmentDuration(itr.slot, itr.leftduration);

    // if no changes
    if (m_itemUpdateQueue.empty()) return;

    for (auto& item : m_itemUpdateQueue)
    {
        if (!item)
            continue;

        if (item->GetState() != ITEM_REMOVED)
        {
            // Plusieurs tests anti dupli ...
            Item* test = GetItemByPos(item->GetBagSlot(), item->GetSlot());

            if (test == nullptr)
            {
                uint32 bagTestGUID = 0;
                if (Item* test2 = GetItemByPos(INVENTORY_SLOT_BAG_0, item->GetBagSlot()))
                    bagTestGUID = test2->GetGUIDLow();
                // according to the test that was just performed nothing should be in this slot, delete
                static SqlStatementID deleteInventoryAntiDupli;
                SqlStatement stmt = CharacterDatabase.CreateStatement(deleteInventoryAntiDupli, "DELETE FROM `character_inventory` WHERE `bag`=? AND `slot`=? AND `guid`=?");
                stmt.addUInt32(bagTestGUID);
                stmt.addUInt32(item->GetSlot());
                stmt.addUInt32(GetGUIDLow());
                stmt.Execute();
                // also THIS item should be somewhere else, cheat attempt
                GetSession()->ProcessAnticheatAction("PassiveAnticheat", "_SaveInventory: item not found", CHEAT_ACTION_LOG | CHEAT_ACTION_REPORT_GMS);
                item->FSetState(ITEM_REMOVED); // we are IN updateQueue right now, can't use SetState which modifies the queue
                // don't skip, let the switch delete it
            }
            else if (test != item)
            {
                if (item->GetState() != ITEM_NEW) // only for existing items, no dupes
                    item->SaveToDB();
                // ...but do not save position in inventory
                continue;
            }
        }
        if (item->GetOwnerGuid() != GetObjectGuid())
            GetSession()->ProcessAnticheatAction("PassiveAnticheat", "_SaveInventory: attempting to save not owned item", CHEAT_ACTION_LOG | CHEAT_ACTION_REPORT_GMS);

        static SqlStatementID insertInventory ;
        static SqlStatementID updateInventory ;
        static SqlStatementID deleteInventory ;

        Bag* container = item->GetContainer();
        uint32 bag_guid = container ? container->GetGUIDLow() : 0;

        switch (item->GetState())
        {
            case ITEM_NEW:
            {
                SqlStatement stmt = CharacterDatabase.CreateStatement(insertInventory, "INSERT INTO `character_inventory` (`guid`, `bag`, `slot`, `item_guid`, `item_id`) VALUES (?, ?, ?, ?, ?)");
                stmt.addUInt32(GetGUIDLow());
                stmt.addUInt32(bag_guid);
                stmt.addUInt8(item->GetSlot());
                stmt.addUInt32(item->GetGUIDLow());
                stmt.addUInt32(item->GetEntry());
                stmt.Execute();
            }
            break;
            case ITEM_CHANGED:
            {
                SqlStatement stmt = CharacterDatabase.CreateStatement(updateInventory, "UPDATE `character_inventory` SET `guid` = ?, `bag` = ?, `slot` = ?, `item_id` = ? WHERE `item_guid` = ?");
                stmt.addUInt32(GetGUIDLow());
                stmt.addUInt32(bag_guid);
                stmt.addUInt8(item->GetSlot());
                stmt.addUInt32(item->GetEntry());
                stmt.addUInt32(item->GetGUIDLow());
                stmt.Execute();
            }
            break;
            case ITEM_REMOVED:
            {
                SqlStatement stmt = CharacterDatabase.CreateStatement(deleteInventory, "DELETE FROM `character_inventory` WHERE `item_guid` = ?");
                stmt.PExecute(item->GetGUIDLow());
            }
            break;
            case ITEM_UNCHANGED:
                break;
        }

        item->SaveToDB();                                   // item have unchanged inventory record and can be save standalone
    }
    m_itemUpdateQueue.clear();
}

void Player::_SaveQuestStatus()
{
    static SqlStatementID insertQuestStatus ;

    static SqlStatementID updateQuestStatus ;

    // we don't need transactions here.
    for (QuestStatusMap::iterator i = mQuestStatus.begin(); i != mQuestStatus.end();)
    {
        // Nostalrius
        if (i->second.uState == QUEST_DELETED)
        {
            static SqlStatementID deleteQuestStatus ;
            SqlStatement stmt = CharacterDatabase.CreateStatement(deleteQuestStatus, "DELETE FROM `character_queststatus` WHERE `guid` = ? AND `quest` = ?");
            stmt.PExecute(GetGUIDLow(), i->first);
            mQuestStatus.erase(i);
            i = mQuestStatus.begin();
            continue;
        }
        switch (i->second.uState)
        {
            case QUEST_NEW :
            {
                SqlStatement stmt = CharacterDatabase.CreateStatement(insertQuestStatus, "INSERT INTO `character_queststatus` (`guid`, `quest`, `status`, `rewarded`, `explored`, `timer`, `mob_count1`, `mob_count2`, `mob_count3`, `mob_count4`, `item_count1`, `item_count2`, `item_count3`, `item_count4`, `reward_choice`) "
                                    "VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)");

                stmt.addUInt32(GetGUIDLow());
                stmt.addUInt32(i->first);
                stmt.addUInt8(i->second.m_status);
                stmt.addUInt8(i->second.m_rewarded);
                stmt.addUInt8(i->second.m_explored);
                stmt.addUInt64(uint64(i->second.m_timer / IN_MILLISECONDS + sWorld.GetGameTime()));
                for (uint32 k : i->second.m_creatureOrGOcount)
                    stmt.addUInt32(k);
                for (uint32 k : i->second.m_itemcount)
                    stmt.addUInt32(k);
                stmt.addUInt32(i->second.m_reward_choice);
                stmt.Execute();
            }
            break;
            case QUEST_CHANGED :
            {
                SqlStatement stmt = CharacterDatabase.CreateStatement(updateQuestStatus, "UPDATE `character_queststatus` SET `status` = ?, `rewarded` = ?, `reward_choice` = ?, `explored` = ?, `timer` = ?,"
                                    "`mob_count1` = ?, `mob_count2` = ?, `mob_count3` = ?, `mob_count4` = ?, `item_count1` = ?, `item_count2` = ?, `item_count3` = ?, `item_count4` = ?  WHERE `guid` = ? AND `quest` = ?");

                stmt.addUInt8(i->second.m_status);
                stmt.addUInt8(i->second.m_rewarded);
                stmt.addUInt32(i->second.m_reward_choice);
                stmt.addUInt8(i->second.m_explored);
                stmt.addUInt64(uint64(i->second.m_timer / IN_MILLISECONDS + sWorld.GetGameTime()));
                for (uint32 k : i->second.m_creatureOrGOcount)
                    stmt.addUInt32(k);
                for (uint32 k : i->second.m_itemcount)
                    stmt.addUInt32(k);
                stmt.addUInt32(GetGUIDLow());
                stmt.addUInt32(i->first);
                stmt.Execute();
            }
            break;
            case QUEST_UNCHANGED:
                break;
        };
        i->second.uState = QUEST_UNCHANGED;
        ++i;
    }
}

void Player::_SaveSkills()
{
    static SqlStatementID delSkills;
    static SqlStatementID insSkills;
    static SqlStatementID updSkills;

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
            SqlStatement stmt = CharacterDatabase.CreateStatement(delSkills, "DELETE FROM `character_skills` WHERE `guid` = ? AND `skill` = ?");
            stmt.PExecute(GetGUIDLow(), itr->first);
            mSkillStatus.erase(itr++);
            continue;
        }

        uint32 valueData = GetUInt32Value(PLAYER_SKILL_VALUE_INDEX(itr->second.pos));
        uint16 value = SKILL_VALUE(valueData);
        uint16 max = SKILL_MAX(valueData);

        switch (itr->second.uState)
        {
            case SKILL_NEW:
            {
                SqlStatement stmt = CharacterDatabase.CreateStatement(insSkills, "INSERT INTO `character_skills` (`guid`, `skill`, `value`, `max`) VALUES (?, ?, ?, ?)");
                stmt.PExecute(GetGUIDLow(), itr->first, value, max);
            }
            break;
            case SKILL_CHANGED:
            {
                SqlStatement stmt = CharacterDatabase.CreateStatement(updSkills, "UPDATE `character_skills` SET `value` = ?, `max` = ? WHERE `guid` = ? AND `skill` = ?");
                stmt.PExecute(value, max, GetGUIDLow(), itr->first);
            }
            break;
            case SKILL_UNCHANGED:
            case SKILL_DELETED:
                MANGOS_ASSERT(false);
                break;
        };
        itr->second.uState = SKILL_UNCHANGED;

        ++itr;
    }

    
#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_10_2
    // Forgotten weapon skills.
    static SqlStatementID forSkills;

    for (const auto itr : m_mForgottenSkills)
    {
        if (itr.second > 1)
        {
            SqlStatement stmt = CharacterDatabase.CreateStatement(forSkills, "REPLACE INTO `character_forgotten_skills` (`guid`, `skill`, `value`) VALUES (?, ?, ?)");
            stmt.PExecute(GetGUIDLow(), itr.first, itr.second);
        }
    }
#endif
}

void Player::_SaveSpells()
{
    static SqlStatementID delSpells ;
    static SqlStatementID insSpells ;

    SqlStatement stmtDel = CharacterDatabase.CreateStatement(delSpells, "DELETE FROM `character_spell` WHERE `guid` = ? and `spell` = ?");
    SqlStatement stmtIns = CharacterDatabase.CreateStatement(insSpells, "INSERT INTO `character_spell` (`guid`, `spell`, `active`, `disabled`) VALUES (?, ?, ?, ?)");

    for (PlayerSpellMap::iterator itr = m_spells.begin(); itr != m_spells.end();)
    {
        if (itr->second.state == PLAYERSPELL_REMOVED || itr->second.state == PLAYERSPELL_CHANGED)
            stmtDel.PExecute(GetGUIDLow(), itr->first);

        // add only changed/new not dependent spells
        if (!itr->second.dependent && (itr->second.state == PLAYERSPELL_NEW || itr->second.state == PLAYERSPELL_CHANGED))
            stmtIns.PExecute(GetGUIDLow(), itr->first, uint8(itr->second.active ? 1 : 0), uint8(itr->second.disabled ? 1 : 0));

        if (itr->second.state == PLAYERSPELL_REMOVED)
            m_spells.erase(itr++);
        else
        {
            itr->second.state = PLAYERSPELL_UNCHANGED;
            ++itr;
        }

    }
}

// save player stats -- only for external usage
// real stats will be recalculated on player login
void Player::_SaveStats()
{
    // check if stat saving is enabled and if char level is high enough
    if (!sWorld.getConfig(CONFIG_UINT32_MIN_LEVEL_STAT_SAVE) || GetLevel() < sWorld.getConfig(CONFIG_UINT32_MIN_LEVEL_STAT_SAVE))
        return;

    static SqlStatementID delStats ;
    static SqlStatementID insertStats ;

    SqlStatement stmt = CharacterDatabase.CreateStatement(delStats, "DELETE FROM `character_stats` WHERE `guid` = ?");
    stmt.PExecute(GetGUIDLow());

    stmt = CharacterDatabase.CreateStatement(insertStats, "INSERT INTO `character_stats` (`guid`, `max_health`, `max_power1`, `max_power2`, `max_power3`, `max_power4`, `max_power5`, "
            "`strength`, `agility`, `stamina`, `intellect`, `spirit`, `armor`, `holy_res`, `fire_res`, `nature_res`, `frost_res`, `shadow_res`, `arcane_res`, "
            "`block_chance`, `dodge_chance`, `parry_chance`, `crit_chance`, `ranged_crit_chance`, `attack_power`, `ranged_attack_power`) "
            "VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)");

    stmt.addUInt32(GetGUIDLow());
    stmt.addUInt32(GetMaxHealth());
    for (int i = 0; i < MAX_POWERS; ++i)
        stmt.addUInt32(GetMaxPower(Powers(i)));
    for (int i = 0; i < MAX_STATS; ++i)
        stmt.addFloat(GetStat(Stats(i)));
    // armor + school resistances
    for (int i = 0; i < MAX_SPELL_SCHOOL; ++i)
        stmt.addInt32(GetResistance(SpellSchools(i)));
    stmt.addFloat(GetFloatValue(PLAYER_BLOCK_PERCENTAGE));
    stmt.addFloat(GetFloatValue(PLAYER_DODGE_PERCENTAGE));
    stmt.addFloat(GetFloatValue(PLAYER_PARRY_PERCENTAGE));
    stmt.addFloat(GetFloatValue(PLAYER_CRIT_PERCENTAGE));
    stmt.addFloat(GetFloatValue(PLAYER_RANGED_CRIT_PERCENTAGE));
    stmt.addUInt32(GetUInt32Value(UNIT_FIELD_ATTACK_POWER));
    stmt.addUInt32(GetUInt32Value(UNIT_FIELD_RANGED_ATTACK_POWER));

    stmt.Execute();
}

void Player::outDebugStatsValues() const
{
    // optimize disabled debug output
    if (!sLog.HasLogLevelOrHigher(LOG_LVL_DEBUG) || sLog.HasLogFilter(LOG_FILTER_PLAYER_STATS))
        return;

    DEBUG_LOG("HP is: \t\t\t%u\t\tMP is: \t\t\t%u", GetMaxHealth(), GetMaxPower(POWER_MANA));
    DEBUG_LOG("AGILITY is: \t\t%f\t\tSTRENGTH is: \t\t%f", GetStat(STAT_AGILITY), GetStat(STAT_STRENGTH));
    DEBUG_LOG("INTELLECT is: \t\t%f\t\tSPIRIT is: \t\t%f", GetStat(STAT_INTELLECT), GetStat(STAT_SPIRIT));
    DEBUG_LOG("STAMINA is: \t\t%f", GetStat(STAT_STAMINA));
    DEBUG_LOG("Armor is: \t\t%i\t\tBlock is: \t\t%f", GetArmor(), GetFloatValue(PLAYER_BLOCK_PERCENTAGE));
    DEBUG_LOG("HolyRes is: \t\t%i\t\tFireRes is: \t\t%i", GetResistance(SPELL_SCHOOL_HOLY), GetResistance(SPELL_SCHOOL_FIRE));
    DEBUG_LOG("NatureRes is: \t\t%i\t\tFrostRes is: \t\t%i", GetResistance(SPELL_SCHOOL_NATURE), GetResistance(SPELL_SCHOOL_FROST));
    DEBUG_LOG("ShadowRes is: \t\t%i\t\tArcaneRes is: \t\t%i", GetResistance(SPELL_SCHOOL_SHADOW), GetResistance(SPELL_SCHOOL_ARCANE));
    DEBUG_LOG("MIN_DAMAGE is: \t\t%f\tMAX_DAMAGE is: \t\t%f", GetFloatValue(UNIT_FIELD_MINDAMAGE), GetFloatValue(UNIT_FIELD_MAXDAMAGE));
    DEBUG_LOG("MIN_OFFHAND_DAMAGE is: \t%f\tMAX_OFFHAND_DAMAGE is: \t%f", GetFloatValue(UNIT_FIELD_MINOFFHANDDAMAGE), GetFloatValue(UNIT_FIELD_MAXOFFHANDDAMAGE));
    DEBUG_LOG("MIN_RANGED_DAMAGE is: \t%f\tMAX_RANGED_DAMAGE is: \t%f", GetFloatValue(UNIT_FIELD_MINRANGEDDAMAGE), GetFloatValue(UNIT_FIELD_MAXRANGEDDAMAGE));
    DEBUG_LOG("ATTACK_TIME is: \t%u\t\tRANGE_ATTACK_TIME is: \t%u", GetAttackTime(BASE_ATTACK), GetAttackTime(RANGED_ATTACK));
}

/*********************************************************/
/***               FLOOD FILTER SYSTEM                 ***/
/*********************************************************/

bool Player::CanSpeak() const
{
    return  GetSession()->m_muteTime <= time(nullptr);
}

/*********************************************************/
/***              LOW LEVEL FUNCTIONS:Notifiers        ***/
/*********************************************************/

void Player::SavePositionInDB(ObjectGuid guid, uint32 mapid, float x, float y, float z, float o, uint32 zone)
{
    std::ostringstream ss;
    ss << "UPDATE `characters` SET `position_x`=" << x << ", `position_y`=" << y
       << ", `position_z`=" << z << ", `orientation`=" << o << " ,`map`=" << mapid
       << " ,`zone`=" << zone << " ,`transport_x`=0, `transport_y`=0, `transport_z`=0, "
       << "`transport_guid`=0, `current_taxi_path`='' WHERE `guid`=" << guid.GetCounter();
    DEBUG_LOG("%s", ss.str().c_str());
    CharacterDatabase.Execute(ss.str().c_str());
}

void Player::SendAttackSwingNotInRange() const
{
    WorldPacket data(SMSG_ATTACKSWING_NOTINRANGE, 0);
    GetSession()->SendPacket(&data);
}

void Player::SendAttackSwingNotStanding() const
{
    WorldPacket data(SMSG_ATTACKSWING_NOTSTANDING, 0);
    GetSession()->SendPacket(&data);
}

void Player::SendAttackSwingDeadTarget() const
{
    WorldPacket data(SMSG_ATTACKSWING_DEADTARGET, 0);
    GetSession()->SendPacket(&data);
}

void Player::SendAttackSwingCantAttack() const
{
    WorldPacket data(SMSG_ATTACKSWING_CANT_ATTACK, 0);
    GetSession()->SendPacket(&data);
}

void Player::SendAttackSwingCancelAttack() const
{
    WorldPacket data(SMSG_CANCEL_COMBAT, 0);
    GetSession()->SendPacket(&data);
}

void Player::SendAttackSwingBadFacingAttack() const
{
    WorldPacket data(SMSG_ATTACKSWING_BADFACING, 0);
    GetSession()->SendPacket(&data);
}

void Player::SendAutoRepeatCancel() const
{
    WorldPacket data(SMSG_CANCEL_AUTO_REPEAT, 0);
    GetSession()->SendPacket(&data);
}

void Player::SendFeignDeathResisted() const
{
    WorldPacket data(SMSG_FEIGN_DEATH_RESISTED, 0);
    GetSession()->SendPacket(&data);
}

void Player::SendExplorationExperience(uint32 Area, uint32 Experience) const
{
    WorldPacket data(SMSG_EXPLORATION_EXPERIENCE, 8);
    data << uint32(Area);
    data << uint32(Experience);
    GetSession()->SendPacket(&data);
}

void Player::SendFactionAtWar(uint32 reputationId, bool apply) const
{
#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_8_4
    WorldPacket data(SMSG_SET_FACTION_ATWAR, 4 + 1);
    data << uint32(reputationId);
    data << uint8(apply ? FACTION_FLAG_AT_WAR : 0);
    GetSession()->SendPacket(&data);
#endif
}

void Player::SendResetFailedNotify()
{
    ChatHandler(this).SendSysMessage(LANG_LEAVE_TO_RESET_INSTANCE);
}

/// Reset all solo instances and optionally send a message on success for each
void Player::ResetInstances(InstanceResetMethod method)
{
    // method can be INSTANCE_RESET_ALL, INSTANCE_RESET_GROUP_JOIN
    for (BoundInstancesMap::iterator itr = m_boundInstances.begin(); itr != m_boundInstances.end();)
    {
        DungeonPersistentState* state = itr->second.state;
        MapEntry const* entry = sMapStorage.LookupEntry<MapEntry>(itr->first);
        if (!entry || !state->CanReset())
        {
            ++itr;
            continue;
        }

        if (method == INSTANCE_RESET_ALL)
        {
            // the "reset all instances" method can only reset normal maps
            if (entry->mapType == MAP_RAID)
            {
                ++itr;
                continue;
            }

            // solo player cannot reset instance while inside
            if (IsInWorld() && itr->first == GetMapId())
            {
                ++itr;
                continue;
            }
        }

        // if the map is loaded, reset it
        if (Map* map = sMapMgr.FindMap(state->GetMapId(), state->GetInstanceId()))
            if (map->IsDungeon())
                ((DungeonMap*)map)->Reset(method);

        // since this is a solo instance there should not be any players inside
        if (method == INSTANCE_RESET_ALL)
            SendResetInstanceSuccess(state->GetMapId());

        state->DeleteFromDB();
        m_boundInstances.erase(itr++);

        // the following should remove the instance save from the manager and delete it as well
        state->RemovePlayer(this);
    }
}

void Player::SendResetInstanceSuccess(uint32 MapId) const
{
#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_8_4
    WorldPacket data(SMSG_INSTANCE_RESET, 4);
    data << uint32(MapId);
    GetSession()->SendPacket(&data);
#endif
}

void Player::SendResetInstanceFailed(uint32 reason, uint32 MapId) const
{
#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_8_4
    // reason: see enum InstanceResetFailReason
    WorldPacket data(SMSG_INSTANCE_RESET_FAILED, 8);
    data << uint32(reason);
    data << uint32(MapId);
    GetSession()->SendPacket(&data);
#endif
}

/** Implementation of hourly maximum instances per account */
bool Player::CheckInstanceCount(uint32 instanceId) const
{
    return IsGameMaster() || sAccountMgr.CheckInstanceCount(GetSession()->GetAccountId(), instanceId, MAX_INSTANCE_PER_ACCOUNT_PER_HOUR);
}

void Player::AddInstanceEnterTime(uint32 instanceId, time_t enterTime) const
{
    sAccountMgr.AddInstanceEnterTime(GetSession()->GetAccountId(), instanceId, enterTime);
}

/*********************************************************/
/***              Update timers                        ***/
/*********************************************************/

void Player::UpdatePvPFlagTimer(uint32 diff)
{
    // Freeze flag timer while participating in PvP combat, in pvp enforced zone, in capture points, when carrying flag or on player preference
    if (!pvpInfo.inPvPCombat && !pvpInfo.inPvPEnforcedArea && !pvpInfo.inPvPCapturePoint && !pvpInfo.isPvPFlagCarrier && !HasFlag(PLAYER_FLAGS, PLAYER_FLAGS_PVP_DESIRED))
        pvpInfo.timerPvPRemaining -= std::min(pvpInfo.timerPvPRemaining, diff);

    // Timer tries to drop flag if all conditions are met and time has passed
    UpdatePvP(false);
}

void Player::UpdatePvPContestedFlagTimer(uint32 diff)
{
    // Freeze flag timer while participating in PvP combat
    if (!pvpInfo.inPvPCombat)
        pvpInfo.timerPvPContestedRemaining -= std::min(pvpInfo.timerPvPContestedRemaining, diff);

    // Timer tries to drop flag if all conditions are met and time has passed
    UpdatePvPContested(false);
}

void Player::SetFFAPvP(bool state)
{
    if (state)
        SetFlag(PLAYER_FLAGS, PLAYER_FLAGS_FFA_PVP);
    else
        RemoveFlag(PLAYER_FLAGS, PLAYER_FLAGS_FFA_PVP);

    if (GetGroup())
        SetGroupUpdateFlag(GROUP_UPDATE_FLAG_STATUS);
}

bool Player::IsInInterFactionMode() const
{
    return true; // Always enable interfaction
    if (IsFFAPvP())
        return true;

    Map* tMap = FindMap();
    return (tMap != nullptr) && (tMap->IsDungeon());
}

void Player::UpdateDuelFlag(time_t currTime)
{
    if (!duel || duel->finished || duel->startTimer == 0 || currTime < duel->startTimer + 3)
        return;

    SetUInt32Value(PLAYER_DUEL_TEAM, 1);
    duel->opponent->SetUInt32Value(PLAYER_DUEL_TEAM, 2);

    duel->startTimer = 0;
    duel->startTime  = currTime;
    if (duel->opponent->duel)
    {
        duel->opponent->duel->startTimer = 0;
        duel->opponent->duel->startTime  = currTime;
    }
}

void Player::RemovePet(PetSaveMode mode)
{
    if (Pet* pet = GetPet())
        pet->Unsummon(mode, this);
}

void Player::RemoveMiniPet()
{
    if (Pet* pet = GetMiniPet())
        pet->Unsummon(PET_SAVE_AS_DELETED);
}

Pet* Player::GetMiniPet() const
{
    if (m_miniPetGuid.IsEmpty())
        return nullptr;

    return GetMap()->GetPet(m_miniPetGuid);
}

void Player::Say(std::string const& text, uint32 const language) const
{
    WorldPacket data;
    ChatHandler::BuildChatPacket(data, CHAT_MSG_SAY, text.c_str(), Language(language), GetChatTag(), GetObjectGuid(), GetName());
    float range = std::min(sWorld.getConfig(CONFIG_FLOAT_LISTEN_RANGE_SAY), GetYellRange());
    SendMessageToSetInRange(&data, range, true);
}

float Player::GetYellRange() const
{
    float range = sWorld.getConfig(CONFIG_FLOAT_LISTEN_RANGE_YELL);
    uint32 linearScaleMaxLevel     = sWorld.getConfig(CONFIG_UINT32_YELLRANGE_LINEARSCALE_MAXLEVEL);
    uint32 quadraticScaleMaxLevel  = sWorld.getConfig(CONFIG_UINT32_YELLRANGE_QUADRATICSCALE_MAXLEVEL);
    if (GetLevel() < linearScaleMaxLevel)
        range *= GetLevel() / float(linearScaleMaxLevel);
    if (GetLevel() < quadraticScaleMaxLevel)
        range *= GetLevel() * GetLevel() / float(quadraticScaleMaxLevel * quadraticScaleMaxLevel);
    if (range < sWorld.getConfig(CONFIG_UINT32_YELLRANGE_MIN))
        range = sWorld.getConfig(CONFIG_UINT32_YELLRANGE_MIN);
    return range;
}

void Player::Yell(std::string const& text, uint32 const language) const
{
    WorldPacket data;
    ChatHandler::BuildChatPacket(data, CHAT_MSG_YELL, text.c_str(), Language(language), GetChatTag(), GetObjectGuid(), GetName());
    SendMessageToSetInRange(&data, GetYellRange(), true);
}

void Player::TextEmote(std::string const& text) const
{
    WorldPacket data;
    ChatHandler::BuildChatPacket(data, CHAT_MSG_EMOTE, text.c_str(), LANG_UNIVERSAL, GetChatTag(), GetObjectGuid(), GetName());
    SendMessageToSetInRange(&data, sWorld.getConfig(CONFIG_FLOAT_LISTEN_RANGE_TEXTEMOTE), true, !sWorld.getConfig(CONFIG_BOOL_ALLOW_TWO_SIDE_INTERACTION_CHAT));
}

void Player::PetSpellInitialize()
{
    Pet* pet = GetPet();

    if (!pet)
        return;

    DEBUG_LOG("Pet Spells Groups");

    CharmInfo* charmInfo = pet->GetCharmInfo();

    WorldPacket data(SMSG_PET_SPELLS, 8 + 4 + 1 + 1 + 2 + 4 * MAX_UNIT_ACTION_BAR_INDEX + 1 + 1);
    data << pet->GetObjectGuid();
    data << uint32(0);
    data << uint8(pet->GetReactState());
    data << uint8(charmInfo->GetCommandState());
    data << uint8(0);
    data << uint8(pet->IsEnabled() ? 0x0 : 0x8);

    // action bar loop
    charmInfo->BuildActionBar(&data);

    size_t spellsCountPos = data.wpos();

    // spells count
    uint8 addlist = 0;
    data << uint8(addlist);                                 // placeholder

    if (pet->IsPermanentPetFor(this))
    {
        // spells loop
        for (PetSpellMap::const_iterator itr = pet->m_petSpells.begin(); itr != pet->m_petSpells.end(); ++itr)
        {
            if (itr->second.state == PETSPELL_REMOVED)
                continue;

            data << uint32(MAKE_UNIT_ACTION_BUTTON(itr->first, itr->second.active));
            ++addlist;
        }
    }

    data.put<uint8>(spellsCountPos, addlist);
    pet->WritePetSpellsCooldown(data);
    GetSession()->SendPacket(&data);
}

void Player::PossessSpellInitialize()
{
    Unit* charm = GetCharm();

    if (!charm)
        return;

    CharmInfo* charmInfo = charm->GetCharmInfo();

    if (!charmInfo)
    {
        sLog.outError("Player::PossessSpellInitialize(): charm (GUID: %u TypeId: %u) has no charminfo!", charm->GetGUIDLow(), charm->GetTypeId());
        return;
    }

    WorldPacket data(SMSG_PET_SPELLS, 8 + 4 + 4 + 4 * MAX_UNIT_ACTION_BAR_INDEX + 1 + 1);
    data << charm->GetObjectGuid();
    data << uint32(0);
    data << uint32(0);

    charmInfo->BuildActionBar(&data);

    data << uint8(0);                                       // spells count
    charm->WritePetSpellsCooldown(data);

    GetSession()->SendPacket(&data);
}

void Player::CharmSpellInitialize()
{
    Unit* charm = GetCharm();

    if (!charm)
        return;

    CharmInfo* charmInfo = charm->GetCharmInfo();
    if (!charmInfo)
    {
        sLog.outError("Player::CharmSpellInitialize(): the player's charm (GUID: %u TypeId: %u) has no charminfo!", charm->GetGUIDLow(), charm->GetTypeId());
        return;
    }

    uint8 addlist = 0;

    if (charm->GetTypeId() != TYPEID_PLAYER)
    {
        CreatureInfo const* cinfo = ((Creature*)charm)->GetCreatureInfo();

        if (cinfo && cinfo->type == CREATURE_TYPE_DEMON && GetClass() == CLASS_WARLOCK)
        {
            for (uint32 i = 0; i < CREATURE_MAX_SPELLS; ++i)
            {
                if (charmInfo->GetCharmSpell(i)->GetAction())
                    ++addlist;
            }
        }
    }

    WorldPacket data(SMSG_PET_SPELLS, 8 + 4 + 1 + 1 + 2 + 4 * MAX_UNIT_ACTION_BAR_INDEX + 1 + 4 * addlist + 1);
    data << charm->GetObjectGuid();
    data << uint32(0x00000000);

    data << uint8(charmInfo->GetReactState()) << uint8(charmInfo->GetCommandState()) << uint16(0);

    charmInfo->BuildActionBar(&data);

    data << uint8(addlist);

    if (addlist)
    {
        for (uint32 i = 0; i < CREATURE_MAX_SPELLS; ++i)
        {
            CharmSpellEntry* cspell = charmInfo->GetCharmSpell(i);
            if (cspell->GetAction())
                data << uint32(cspell->packedData);
        }
    }

    charm->WritePetSpellsCooldown(data);

    GetSession()->SendPacket(&data);
}

void Player::RemovePetActionBar()
{
    WorldPacket data(SMSG_PET_SPELLS, 8);
    data << ObjectGuid();
    SendDirectMessage(&data);
}

// This will create a new creature and set the current unit as the controller of that new creature
Creature* Player::SummonPossessedMinion(uint32 creatureId, uint32 spellId, float x, float y, float z, float ang)
{
    // Possess is a unique advertised charm, another advertised charm already exists: we should get rid of it first
    if (!GetCharmGuid().IsEmpty())
        return nullptr;

    Creature* pCreature = SummonCreature(creatureId, x, y, z, ang, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 5000, false, 0, nullptr, GetTransport());

    if (!pCreature)
        return nullptr;

    pCreature->SetFactionTemporary(GetFactionTemplateId(), TEMPFACTION_NONE);     // set same faction as player
    pCreature->SetCharmerGuid(GetObjectGuid());                         // save guid of the charmer
    pCreature->SetPossessorGuid(GetObjectGuid());
    pCreature->SetUInt32Value(UNIT_CREATED_BY_SPELL, spellId);          // set the spell id used to create this
    pCreature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_POSSESSED);          // set flag for client that mean this unit is controlled by a player
    pCreature->AddUnitState(UNIT_STAT_POSSESSED);                       // also set internal unit state flag
    pCreature->SetLevel(GetLevel());                                    // set level to same level than summoner TODO:: not sure its always the case...
    pCreature->SetWalk(IsWalking(), true);                              // sync the walking state with the summoner
    SetCharmGuid(pCreature->GetObjectGuid());                           // save guid of charmed creature

    UnsummonPetTemporaryIfAny();

    GetCamera().SetView(pCreature);                         // modify camera view to the creature view
    pCreature->UpdateControl();                             // transfer client control to the creature after altering flags
    SetMover(pCreature);                                    // set mover so now we know that creature is "moved" by this unit
    SendForcedObjectUpdate();

    // Initialize pet bar
    if (CharmInfo* charmInfo = pCreature->InitCharmInfo(pCreature))
        charmInfo->InitPossessCreateSpells();

    PossessSpellInitialize();

    return pCreature;
}

void Player::UnsummonPossessedMinion()
{
    Unit* pMinion = GetCharm();

    SetCharm(nullptr);
    SetMover(nullptr);
    UpdateControl();
    GetCamera().ResetView();
    RemovePetActionBar();
    SendForcedObjectUpdate();
    ResummonPetTemporaryUnSummonedIfAny();

    if (!pMinion)
        return;

    SetClientControl(pMinion, false);
    pMinion->SetCharmerGuid(ObjectGuid());
    pMinion->SetPossessorGuid(ObjectGuid());
    pMinion->ClearUnitState(UNIT_STAT_POSSESSED);
    pMinion->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_POSSESSED);
    pMinion->DoKillUnit();
}

bool Player::HasInstantCastingSpellMod(SpellEntry const* spellInfo) const
{
    for (const auto& mod : m_spellMods[SPELLMOD_CASTING_TIME])
    {
        if ((mod->type == SPELLMOD_PCT) && (mod->value <= -100) && mod->isAffectedOnSpell(spellInfo))
            return true;
    }
    return false;
}

bool Player::IsAffectedBySpellmod(SpellEntry const* spellInfo, SpellModifier* mod, Spell* spell) const
{
    if (!mod || !spellInfo)
        return false;

    // Mod out of charges
    if (spell)
    {
        std::list<SpellModifier*>::iterator iterMod = spell->m_appliedMods.begin();
        while (iterMod != spell->m_appliedMods.end() && (*iterMod) != mod)
            ++iterMod;
        if (mod->charges == -1 && iterMod == spell->m_appliedMods.end())
            return false;
    }

    return mod->isAffectedOnSpell(spellInfo);
}

void Player::AddSpellMod(SpellModifier* mod, bool apply)
{
    ASSERT(mod);

    if (apply)
        m_spellMods[mod->op].push_back(mod);
    else
        m_spellMods[mod->op].remove(mod);

    SendSpellMod(mod);

    if (!apply)
        delete mod;
}

void Player::SendSpellMod(SpellModifier const* mod) const
{
    uint16 Opcode = (mod->type == SPELLMOD_FLAT) ? SMSG_SET_FLAT_SPELL_MODIFIER : SMSG_SET_PCT_SPELL_MODIFIER;

    for (int eff = 0; eff < 64; ++eff)
    {
        uint64 _mask = uint64(1) << eff;
        if (!!(mod->mask & _mask))
        {
            int32 val = 0;
            for (SpellModList::const_iterator itr = m_spellMods[mod->op].begin(); itr != m_spellMods[mod->op].end(); ++itr)
            {
                if ((*itr)->type == mod->type && !!((*itr)->mask & _mask))
                    val += (*itr)->value;
            }
            WorldPacket data(Opcode, (1 + 1 + 4));
            data << uint8(eff);
            data << uint8(mod->op);
            data << int32(val);
            SendDirectMessage(&data);
        }
    }
}

SpellModifier* Player::GetSpellMod(SpellModOp op, uint32 spellId) const
{
    for (const auto itr : m_spellMods[op])
        if (itr->spellId == spellId)
            return itr;

    return nullptr;
}

// Restore spellmods in case of failed cast
void Player::RestoreSpellMods(Spell* spell, uint32 ownerAuraId, Aura* aura)
{
    if (!spell || spell->m_appliedMods.empty())
        return;

    for (const auto& modList : m_spellMods)
    {
        for (const auto& mod : modList)
        {
            if (aura && mod->ownerAura != aura)
                continue;

            // check if mod affected this spell
            // first, check if the mod aura applied at least one spellmod to this spell
            std::list<SpellModifier*>::iterator iterMod = spell->m_appliedMods.begin();
            while (iterMod != spell->m_appliedMods.end() && (*iterMod) != mod)
                ++iterMod;
            if (iterMod == spell->m_appliedMods.end())
                continue;

            // remove from list
            spell->m_appliedMods.erase(iterMod);

            // add mod charges back to mod
            if (mod->charges == -1)
                mod->charges = 1;
            else
                mod->charges++;

            // Do not set more spellmods than avalible
            //if (mod->ownerAura->GetCharges() < mod->charges)
            //    mod->charges = mod->ownerAura->GetCharges();

            // Skip this check for now - aura charges may change due to various reason
            // TODO: trac these changes correctly
            //ASSERT (mod->ownerAura->GetCharges() <= mod->charges);
        }
    }
}

void Player::RestoreAllSpellMods(uint32 ownerAuraId, Aura* aura)
{
    for (uint32 i = 0; i < CURRENT_MAX_SPELL; ++i)
        if (GetCurrentSpell(CurrentSpellTypes(i)))
            RestoreSpellMods(GetCurrentSpell(CurrentSpellTypes(i)), ownerAuraId, aura);
}

void Player::RemoveSpellMods(Spell* spell)
{
    if (!spell)
        return;

    if (spell->m_appliedMods.empty())
        return;

    for (const auto& modList : m_spellMods)
    {
        for (SpellModList::const_iterator itr = modList.begin(); itr != modList.end();)
        {
            SpellModifier* mod = *itr;
            ++itr;

            // check if mod affected this spell
            std::list<SpellModifier*>::iterator iterMod = spell->m_appliedMods.begin();
            while (iterMod != spell->m_appliedMods.end() && (*iterMod) != mod)
                ++iterMod;
            if (iterMod == spell->m_appliedMods.end())
                continue;

            // remove from list
            spell->m_appliedMods.erase(iterMod);

            if (mod->charges == -1)
            {
                RemoveAurasDueToSpell(mod->spellId);
                itr = modList.begin();
            }
        }
    }
}

void Player::DropModCharge(SpellModifier* mod, Spell* spell)
{
    ASSERT(mod);

    if (!spell || spell->HasModifierApplied(mod))
        return;

    // don't handle spells with proc_event entry defined
    // this is a temporary workaround, because all spellmods should be handled like that
    //if (sSpellMgr.GetSpellProcEvent(mod->spellId))
    //    return;

    if (mod->charges > 0)
    {
        --mod->charges;
        if (mod->charges == 0)
            mod->charges = -1;

        spell->m_appliedMods.push_back(mod);
    }
}

// send Proficiency
void Player::SendProficiency(ItemClass itemClass, uint32 itemSubclassMask) const
{
    WorldPacket data(SMSG_SET_PROFICIENCY, 1 + 4);
    data << uint8(itemClass) << uint32(itemSubclassMask);
    GetSession()->SendPacket(&data);
}

void Player::RemovePetitionsAndSigns(ObjectGuid guid)
{
    uint32 lowguid = guid.GetCounter();

    CharacterDatabase.BeginTransaction();
    CharacterDatabase.PExecute("DELETE FROM `petition` WHERE `owner_guid` = '%u'", lowguid);
    CharacterDatabase.PExecute("DELETE FROM `petition_sign` WHERE `owner_guid` = '%u'", lowguid);
    CharacterDatabase.CommitTransaction();
}

void Player::SetRestBonus(float rest_bonus_new)
{
    // Prevent resting on max level
    if (GetLevel() >= sWorld.getConfig(CONFIG_UINT32_MAX_PLAYER_LEVEL))
        rest_bonus_new = 0;

    if (rest_bonus_new < 0)
        rest_bonus_new = 0;

    float rest_bonus_max = (float)GetUInt32Value(PLAYER_NEXT_LEVEL_XP) * 1.5f / 2.0f;

    if (rest_bonus_new > rest_bonus_max)
        m_restBonus = rest_bonus_max;
    else
        m_restBonus = rest_bonus_new;

    // update data for client
    if (m_restBonus > 10)
        SetByteValue(PLAYER_BYTES_2, 3, REST_STATE_RESTED);
    else if (m_restBonus <= 1)
        SetByteValue(PLAYER_BYTES_2, 3, REST_STATE_NORMAL);

    // RestTickUpdate
    SetUInt32Value(PLAYER_REST_STATE_EXPERIENCE, uint32(m_restBonus));
}

bool Player::ActivateTaxiPathTo(std::vector<uint32> const& nodes, Creature* npc /*= nullptr*/, uint32 spellid /*= 0*/, bool nocheck)
{
    if (nodes.size() < 2)
        return false;

    // not let cheating with start flight in time of logout process || if casting not finished || while in combat || if not use Spell's with EffectSendTaxi
    if (GetSession()->isLogingOut() || IsInCombat())
    {
        WorldPacket data(SMSG_ACTIVATETAXIREPLY, 4);
        data << uint32(ERR_TAXIPLAYERBUSY);
        GetSession()->SendPacket(&data);
        return false;
    }

    if (HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE))
        return false;

    // No hack here
    if (!IsTaxiCheater() && !nocheck)
        for (uint32 node : nodes)
            if (!m_taxi.IsTaximaskNodeKnown(node))
            {
                GetSession()->ProcessAnticheatAction("PassiveAnticheat", "Taxi: Attempt to use unknown node.", CHEAT_ACTION_LOG | CHEAT_ACTION_REPORT_GMS);
                return false;
            }

    // taximaster case
    if (npc)
    {
        // not let cheating with start flight mounted
        if (IsMounted())
        {
            WorldPacket data(SMSG_ACTIVATETAXIREPLY, 4);
            data << uint32(ERR_TAXIPLAYERALREADYMOUNTED);
            GetSession()->SendPacket(&data);
            return false;
        }

        if (IsInDisallowedMountForm())
        {
            WorldPacket data(SMSG_ACTIVATETAXIREPLY, 4);
            data << uint32(ERR_TAXIPLAYERSHAPESHIFTED);
            GetSession()->SendPacket(&data);
            return false;
        }

        // not let cheating with start flight in time of logout process || if casting not finished || while in combat || if not use Spell's with EffectSendTaxi
        if (IsNonMeleeSpellCasted(false))
        {
            WorldPacket data(SMSG_ACTIVATETAXIREPLY, 4);
            data << uint32(ERR_TAXIPLAYERBUSY);
            GetSession()->SendPacket(&data);
            return false;
        }
    }
    // cast case or scripted call case
    else
    {
        RemoveSpellsCausingAura(SPELL_AURA_MOUNTED);

        if (IsInDisallowedMountForm())
            RemoveSpellsCausingAura(SPELL_AURA_MOD_SHAPESHIFT);

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
    TaxiNodesEntry const* node = sObjectMgr.GetTaxiNodeEntry(sourcenode);
    if (!node)
    {
        WorldPacket data(SMSG_ACTIVATETAXIREPLY, 4);
        data << uint32(ERR_TAXINOSUCHPATH);
        GetSession()->SendPacket(&data);
        return false;
    }

    // check node starting pos data set case if provided
    if (node->x != 0.0f || node->y != 0.0f || node->z != 0.0f)
    {
        if (node->map_id != GetMapId() ||
                (node->x - GetPositionX()) * (node->x - GetPositionX()) +
                (node->y - GetPositionY()) * (node->y - GetPositionY()) +
                (node->z - GetPositionZ()) * (node->z - GetPositionZ()) >
                (2 * INTERACTION_DISTANCE) * (2 * INTERACTION_DISTANCE) * (2 * INTERACTION_DISTANCE))
        {
            WorldPacket data(SMSG_ACTIVATETAXIREPLY, 4);
            data << uint32(ERR_TAXITOOFARAWAY);
            GetSession()->SendPacket(&data);
            return false;
        }
    }
    // node must have pos if taxi master case (npc != nullptr)
    else if (npc)
    {
        WorldPacket data(SMSG_ACTIVATETAXIREPLY, 4);
        data << uint32(ERR_TAXIUNSPECIFIEDSERVERERROR);
        GetSession()->SendPacket(&data);
        return false;
    }

    // Prepare to flight start now

    // stop combat at start taxi flight if any
    CombatStop();

    // stop trade (client cancel trade at taxi map open but cheating tools can be used for reopen it)
    TradeCancel(true);

    // clean not finished taxi path if any
    m_taxi.ClearTaxiDestinations();

    // 0 element current node
    m_taxi.AddTaxiDestination(sourcenode);

    float discount = npc ? GetReputationPriceDiscount(npc) : 1.0f;
    m_taxi.SetDiscount(discount);

    // fill destinations path tail
    uint32 sourcepath = 0;
    uint32 sourceCost = 0;
    uint32 totalcost = 0;
    uint32 lastPath = 0;
    uint32 lastNode = nodes[1];
    sObjectMgr.GetTaxiPath(sourcenode, lastNode, sourcepath, sourceCost);
    if (!sourcepath)
    {
        m_taxi.ClearTaxiDestinations();
        return false;
    }
    lastPath = sourcepath;
    sourceCost = (uint32)ceil(sourceCost * discount);
    totalcost += sourceCost;

    // multiple path
    if (nodes.size() > 2)
    {
        uint32 nextNode = 0;
        uint32 nextCost = 0;
        uint32 nextPath = 0;
        uint32 lastOutNode = 0;
        for (uint32 nodeIndex = 2; nodeIndex < nodes.size(); ++nodeIndex)
        {
            nextNode = nodes[nodeIndex];
            sObjectMgr.GetTaxiPath(lastNode, nextNode, nextPath, nextCost);
            if (!nextPath)
            {
                m_taxi.ClearTaxiDestinations();
                return false;
            }
            totalcost += (uint32)ceil(nextCost * discount);

            // find a transition
            uint32 inNode = 0;
            uint32 outNode = 0;
            bool transitionFound = false;
            TaxiPathTransitionsMapBounds bounds = sObjectMgr.GetTaxiPathTransitionsMapBounds(lastPath);
            for (auto it = bounds.first; it != bounds.second; ++it)
                if (it->second.outPath == nextPath)
                {
                    transitionFound = true;
                    inNode = it->second.inNode;
                    outNode = it->second.outNode;
                    break;
                }
            if (!transitionFound)
                sLog.outErrorDb("Table `taxi_path_transitions` is missing a transition between paths %u and %u", lastPath, nextPath);

            // default values in database, init them to n-1 -> 1
            if (!inNode)
                inNode = sTaxiPathNodesByPath[lastPath].size() - 2;
            if (!outNode)
                outNode = 1;

            // add previous path nodes
            for (uint32 i = lastOutNode; i <= inNode; ++i)
                m_taxi.AddTaxiPathNode(sTaxiPathNodesByPath[lastPath][i]);
            m_taxi.AddTaxiDestination(lastNode);

            lastNode = nextNode;
            lastPath = nextPath;
            lastOutNode = outNode;
        }

        // add last path nodes
        for (int i = lastOutNode; i < sTaxiPathNodesByPath[lastPath].size(); ++i)
            m_taxi.AddTaxiPathNode(sTaxiPathNodesByPath[lastPath][i]);
        m_taxi.AddTaxiDestination(lastNode);
    }
    else // single path
        m_taxi.AddTaxiDestination(lastNode);

    // get mount display id (in case non taximaster (npc==nullptr) allow more wide lookup)
    uint32 mount_display_id = sObjectMgr.GetTaxiMountDisplayId(sourcenode, GetTeam(), npc == nullptr);

    // in spell case allow display id to be 0
    if ((mount_display_id == 0 && spellid == 0) || sourcepath == 0)
    {
        WorldPacket data(SMSG_ACTIVATETAXIREPLY, 4);
        data << uint32(ERR_TAXIUNSPECIFIEDSERVERERROR);
        GetSession()->SendPacket(&data);
        m_taxi.ClearTaxiDestinations();
        return false;
    }

    uint32 money = GetMoney();

    if (money < totalcost)
    {
        WorldPacket data(SMSG_ACTIVATETAXIREPLY, 4);
        data << uint32(ERR_TAXINOTENOUGHMONEY);
        GetSession()->SendPacket(&data);
        m_taxi.ClearTaxiDestinations();
        return false;
    }

    // Remove pvp flag when starting a flight
    UpdatePvP(false);

    //Checks and preparations done, DO FLIGHT
    ModifyMoney(-(int32)sourceCost);

    // prevent stealth flight
    RemoveSpellsCausingAura(SPELL_AURA_MOD_STEALTH);

    // reset extraAttacks counter
    ResetExtraAttacks();

    if (GetPet())
        RemovePet(PET_SAVE_REAGENTS);

    WorldPacket data(SMSG_ACTIVATETAXIREPLY, 4);
    data << uint32(ERR_TAXIOK);
    GetSession()->SendPacket(&data);

    DEBUG_LOG("WORLD: Sent SMSG_ACTIVATETAXIREPLY");

    GetSession()->SendDoFlight(mount_display_id, sourcepath);

    return true;
}

bool Player::ActivateTaxiPathTo(uint32 taxi_path_id, uint32 spellid /*= 0*/, bool nocheck)
{
    TaxiPathEntry const* entry = sTaxiPathStore.LookupEntry(taxi_path_id);
    if (!entry)
        return false;

    std::vector<uint32> nodes;

    nodes.resize(2);
    nodes[0] = entry->from;
    nodes[1] = entry->to;

    return ActivateTaxiPathTo(nodes, nullptr, spellid, nocheck);
}

void Player::ContinueTaxiFlight()
{
    uint32 sourceNode = m_taxi.GetTaxiSource();
    if (!sourceNode)
        return;

    DEBUG_LOG("WORLD: Restart character %u taxi flight", GetGUIDLow());

    uint32 mountDisplayId = sObjectMgr.GetTaxiMountDisplayId(sourceNode, GetTeam(), true);
    uint32 path = m_taxi.GetCurrentTaxiPath();

    // search appropriate start path node
    uint32 startNode = 0;

    TaxiPathNodeList const& nodeList = sTaxiPathNodesByPath[path];

    float distPrev = MAP_SIZE * MAP_SIZE;
    float distNext =
        (nodeList[0].x - GetPositionX()) * (nodeList[0].x - GetPositionX()) +
        (nodeList[0].y - GetPositionY()) * (nodeList[0].y - GetPositionY()) +
        (nodeList[0].z - GetPositionZ()) * (nodeList[0].z - GetPositionZ());

    for (uint32 i = 1; i < nodeList.size(); ++i)
    {
        TaxiPathNodeEntry const& node = nodeList[i];
        TaxiPathNodeEntry const& prevNode = nodeList[i - 1];

        // skip nodes at another map
        if (node.mapid != GetMapId())
            continue;

        distPrev = distNext;

        distNext =
            (node.x - GetPositionX()) * (node.x - GetPositionX()) +
            (node.y - GetPositionY()) * (node.y - GetPositionY()) +
            (node.z - GetPositionZ()) * (node.z - GetPositionZ());

        float distNodes =
            (node.x - prevNode.x) * (node.x - prevNode.x) +
            (node.y - prevNode.y) * (node.y - prevNode.y) +
            (node.z - prevNode.z) * (node.z - prevNode.z);

        if (distNext + distPrev < distNodes)
        {
            startNode = i;
            break;
        }
    }

    GetSession()->SendDoFlight(mountDisplayId, path, startNode);
}

UnitMountResult Player::Mount(uint32 mount, uint32 spellId)
{
    if (!mount)
    {
        RemoveSpellsCausingAura(SPELL_AURA_MOUNTED);
        SendMountResult(MOUNTRESULT_NOTMOUNTABLE);
        return MOUNTRESULT_NOTMOUNTABLE;
    }

    if (IsMounted())
    {
        SendMountResult(MOUNTRESULT_ALREADYMOUNTED);
        return MOUNTRESULT_ALREADYMOUNTED;
    }

    if (!spellId && IsInDisallowedMountForm())
    {
        RemoveSpellsCausingAura(SPELL_AURA_MOUNTED);
        SendMountResult(MOUNTRESULT_SHAPESHIFTED);
        return MOUNTRESULT_SHAPESHIFTED;
    }

    if (HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_LOOTING))
    {
        RemoveSpellsCausingAura(SPELL_AURA_MOUNTED);
        SendMountResult(MOUNTRESULT_LOOTING);
        return MOUNTRESULT_LOOTING;
    }

    Unit::Mount(mount, spellId);

    // Called by Taxi system / GM command
    if (!spellId)
        UnsummonPetTemporaryIfAny();
    // Called by mount aura
    else
    {
        // Normal case (Unsummon only permanent pet)
        if (Pet* pet = GetPet())
        {
            if (pet->IsPermanentPetFor((Player*)this) &&
                sWorld.getConfig(CONFIG_BOOL_PET_UNSUMMON_AT_MOUNT))
                UnsummonPetTemporaryIfAny();
            else
                pet->SetEnabled(false);
        }
    }

    /*
    I wanted to take a moment to provide some clarification around what changed in 1.13.3 with Reckoning.
    There were several systemic issues with extra attack procs behaving incorrectly, which we fixed in the patch.
    A secondary effect of these fixes were two notable changes to Reckoning:
    - Reckoning stacks are lost when you mount up.
    - Reckoning stacks are lost when you initiate an auto-attack against a target and cancel it before it goes off.
    However, both of these behaviors were correct behaviors in the 1.12 reference client and as such are considered bug fixes.
    https://us.forums.blizzard.com/en/wow/t/reckoning-is-broken-after-yesterdays-patch/386476/123
    */
    ResetExtraAttacks();

    SendMountResult(MOUNTRESULT_OK);
    return MOUNTRESULT_OK;
}

UnitDismountResult Player::Unmount(bool from_aura)
{
    if (!IsMounted())
    {
        if (!from_aura)
            SendDismountResult(DISMOUNTRESULT_NOTMOUNTED);

        return DISMOUNTRESULT_NOTMOUNTED;
    }

    Unit::Unmount(from_aura);

    // only resummon old pet if the player is already added to a map
    // this prevents adding a pet to a not created map which would otherwise cause a crash
    // (it could probably happen when logging in after a previous crash)
    if (Pet* pet = GetPet())
        pet->SetEnabled(true);
    else
        ResummonPetTemporaryUnSummonedIfAny();

    SendDismountResult(DISMOUNTRESULT_OK);
    return DISMOUNTRESULT_OK;
}

void Player::SendMountResult(UnitMountResult result) const
{
    WorldPacket data(SMSG_MOUNTRESULT, 4);
    data << uint32(result);
    GetSession()->SendPacket(&data);
}

void Player::SendDismountResult(UnitDismountResult result) const
{
    WorldPacket data(SMSG_DISMOUNTRESULT, 4);
    data << uint32(result);
    GetSession()->SendPacket(&data);
}

void Player::ScheduleStandUp()
{
    if (sWorld.getConfig(CONFIG_UINT32_SPELL_PROC_DELAY))
        m_isStandUpScheduled = true;
    else
        SetStandState(UNIT_STAND_STATE_STAND);
}

void Player::InitDataForForm(bool reapplyMods)
{
    ShapeshiftForm form = GetShapeshiftForm();

    switch (form)
    {
        case FORM_CAT:
        {
            SetAttackTime(BASE_ATTACK, 1000, false);               //Speed 1
            SetAttackTime(OFF_ATTACK, 1000, false);                //Speed 1

            if (GetPowerType() != POWER_ENERGY)
                SetPowerType(POWER_ENERGY);
            break;
        }
        case FORM_BEAR:
        case FORM_DIREBEAR:
        {
            SetAttackTime(BASE_ATTACK, 2500, false);               //Speed 2.5
            SetAttackTime(OFF_ATTACK, 2500, false);                //Speed 2.5

            if (GetPowerType() != POWER_RAGE)
                SetPowerType(POWER_RAGE);
            break;
        }
        default:                                            // 0, for example
        {
            SetRegularAttackTime(false);

            ChrClassesEntry const* cEntry = sChrClassesStore.LookupEntry(GetClass());
            if (cEntry && cEntry->powerType < MAX_POWERS && uint32(GetPowerType()) != cEntry->powerType)
                SetPowerType(Powers(cEntry->powerType));

            break;
        }
    }

    // update auras at form change, ignore this at mods reapply (.reset stats/etc) when form not change.
    if (!reapplyMods)
        UpdateEquipSpellsAtFormChange();

    UpdateAttackPowerAndDamage();
    UpdateAttackPowerAndDamage(true);
}

// Return true is the bought item has a max count to force refresh of window by caller
bool Player::BuyItemFromVendor(ObjectGuid vendorGuid, uint32 item, uint8 count, uint8 bag, uint8 slot)
{
    // cheating attempt
    if (count < 1) count = 1;

    if (!IsAlive())
        return false;

    ItemPrototype const* pProto = ObjectMgr::GetItemPrototype(item);
    if (!pProto)
    {
        SendBuyError(BUY_ERR_CANT_FIND_ITEM, nullptr, item, 0);
        return false;
    }

    Creature* pCreature = GetNPCIfCanInteractWith(vendorGuid, UNIT_NPC_FLAG_VENDOR);
    if (!pCreature)
    {
        DEBUG_LOG("WORLD: BuyItemFromVendor - %s not found or you can't interact with him.", vendorGuid.GetString().c_str());
        SendBuyError(BUY_ERR_DISTANCE_TOO_FAR, nullptr, item, 0);
        return false;
    }

    VendorItemData const* vItems = pCreature->GetVendorItems();
    VendorItemData const* tItems = pCreature->GetVendorTemplateItems();
    
    if ((!vItems || vItems->Empty()) && (!tItems || tItems->Empty()))
    {
        SendBuyError(BUY_ERR_CANT_FIND_ITEM, pCreature, item, 0);
        return false;
    }

    uint32 vCount = vItems ? vItems->GetItemCount() : 0;
    uint32 tCount = tItems ? tItems->GetItemCount() : 0;

    size_t vendorslot = vItems ? vItems->FindItemSlot(item) : vCount;

    // If item was not found in npc_vendor, check npc_vendor_template.
    if (vendorslot >= vCount)
    {
        vendorslot = tItems ? tItems->FindItemSlot(item) + vCount : tCount + vCount;
    }

    if (vendorslot >= vCount + tCount)
    {
        SendBuyError(BUY_ERR_CANT_FIND_ITEM, pCreature, item, 0);
        return false;
    }

    VendorItem const* crItem = vendorslot < vCount ? vItems->GetItem(vendorslot) : tItems->GetItem(vendorslot - vCount);
    if (!crItem || crItem->item != item)                    // store diff item (cheating)
    {
        SendBuyError(BUY_ERR_CANT_FIND_ITEM, pCreature, item, 0);
        return false;
    }

    uint32 totalCount = pProto->BuyCount * count;

    // check current item amount if it limited
    if (crItem->maxcount != 0)
    {
        if (pCreature->GetVendorItemCurrentCount(crItem) < totalCount)
        {
            SendBuyError(BUY_ERR_ITEM_ALREADY_SOLD, pCreature, item, 0);
            return false;
        }
    }

    uint32 reqFaction = pProto->RequiredReputationFaction;
    if (!reqFaction && pProto->RequiredReputationRank > 0)
        reqFaction = pCreature->getFactionTemplateEntry()->faction;

    if (uint32(GetReputationRank(reqFaction)) < pProto->RequiredReputationRank)
    {
        SendBuyError(BUY_ERR_REPUTATION_REQUIRE, pCreature, item, 0);
        return false;
    }

    auto playerRank = (sWorld.GetWowPatch() < WOW_PATCH_107) && sWorld.getConfig(CONFIG_BOOL_ACCURATE_PVP_PURCHASE_REQUIREMENTS) ?
        m_honorMgr.GetHighestRank().rank : m_honorMgr.GetRank().rank;

    // do not check level requirement for normal items (PvP related bonus items is another case)
    if (pProto->RequiredHonorRank && (playerRank < (uint8)pProto->RequiredHonorRank || GetLevel() < pProto->RequiredLevel))
    {
        SendBuyError(BUY_ERR_RANK_REQUIRE, pCreature, item, 0);
        return false;
    }

    if (crItem->conditionId && !IsGameMaster() && !IsConditionSatisfied(crItem->conditionId, this, pCreature->GetMap(), pCreature, CONDITION_FROM_VENDOR))
    {
        SendBuyError(BUY_ERR_CANT_FIND_ITEM, pCreature, item, 0);
        return false;
    }

    uint32 price  = pProto->BuyPrice * count;

    // reputation discount
    price = uint32(floor(price * GetReputationPriceDiscount(pCreature)));

    if (GetMoney() < price)
    {
        SendBuyError(BUY_ERR_NOT_ENOUGHT_MONEY, pCreature, item, 0);
        return false;
    }

    Item* pItem = nullptr;

    if ((bag == NULL_BAG && slot == NULL_SLOT) || IsInventoryPos(bag, slot))
    {
        ItemPosCountVec dest;
        InventoryResult msg = CanStoreNewItem(bag, slot, dest, item, totalCount);
        if (msg != EQUIP_ERR_OK)
        {
            SendEquipError(msg, nullptr, nullptr, item);
            return false;
        }

        LogModifyMoney(-int32(price), "BuyItem", vendorGuid, item);

        pItem = StoreNewItem(dest, item, true, Item::GenerateItemRandomPropertyId(item));
    }
    else if (IsEquipmentPos(bag, slot))
    {
        if (totalCount != 1)
        {
            SendEquipError(EQUIP_ERR_ITEM_CANT_BE_EQUIPPED, nullptr, nullptr);
            return false;
        }

        uint16 dest;
        InventoryResult msg = CanEquipNewItem(slot, dest, item, false);
        if (msg != EQUIP_ERR_OK)
        {
            SendEquipError(msg, nullptr, nullptr, item);
            return false;
        }

        LogModifyMoney(-int32(price), "BuyItem", vendorGuid, item);

        pItem = EquipNewItem(dest, item, true);

        if (pItem)
            AutoUnequipOffhandIfNeed();
    }
    else
    {
        SendEquipError(EQUIP_ERR_ITEM_DOESNT_GO_TO_SLOT, nullptr, nullptr);
        return false;
    }

    if (!pItem)
        return false;

    uint32 new_count = pCreature->UpdateVendorItemCurrentCount(crItem, totalCount);

    WorldPacket data(SMSG_BUY_ITEM, 8 + 4 + 4 + 4);
    data << pCreature->GetObjectGuid();
    data << uint32(vendorslot + 1);                 // numbered from 1 at client
    data << uint32(crItem->maxcount > 0 ? new_count : 0xFFFFFFFF);
    data << uint32(count);
    GetSession()->SendPacket(&data);

    SendNewItem(pItem, totalCount, true, false, false);

    return crItem->maxcount != 0;
}

void Player::UpdateHomebindTime(uint32 time)
{
    // GMs never get homebind timer online
    if (m_InstanceValid || IsGameMaster())
    {
        if (m_HomebindTimer)                                // instance valid, but timer not reset
        {
            // hide reminder
            WorldPacket data(SMSG_RAID_GROUP_ONLY, 4 + 4);
            data << uint32(0);
            data << uint32(ERR_RAID_GROUP_REQUIRED);            // error used only when timer = 0
            GetSession()->SendPacket(&data);
        }
        // instance is valid, reset homebind timer
        m_HomebindTimer = 0;
    }
    else if (m_HomebindTimer > 0)
    {
        if (time >= m_HomebindTimer)
        {
            // teleport to homebind location
            TeleportToHomebind();
        }
        else
            m_HomebindTimer -= time;
    }
    else
    {
        // instance is invalid, start homebind timer
        m_HomebindTimer = 60000;
        // send message to player
        WorldPacket data(SMSG_RAID_GROUP_ONLY, 4 + 4);
        data << uint32(m_HomebindTimer);
        data << uint32(ERR_RAID_GROUP_REQUIRED);                // error used only when timer = 0
        GetSession()->SendPacket(&data);
        DEBUG_LOG("PLAYER: Player '%s' (GUID: %u) will be teleported to homebind in 60 seconds", GetName(), GetGUIDLow());
    }
}

void Player::UpdatePvP(bool state, bool overriding)
{
    if (!state || overriding)
    {
        // Updating into unset state or overriding anything
        if (!pvpInfo.timerPvPRemaining || overriding)
        {
            if (IsPvP() != state)
            {
                SetPvP(state);
                pvpInfo.timerPvPRemaining = 0;
            }
        }
    }
    else
    {
        // Updating into set state
        if (!IsPvP())
            SetPvP(state);

        // Refresh timer
        pvpInfo.timerPvPRemaining = 300000;
    }
}

void Player::UpdatePvPContested(bool state, bool overriding)
{
    if (!state || overriding)
    {
        // Updating into unset state or overriding anything
        if (!pvpInfo.timerPvPContestedRemaining || overriding)
        {
            if (HasFlag(PLAYER_FLAGS, PLAYER_FLAGS_CONTESTED_PVP) != state)
            {
                SetPvPContested(state);
                pvpInfo.timerPvPContestedRemaining = 0;
            }
        }
    }
    else
    {
        // Updating into set state
        if (!HasFlag(PLAYER_FLAGS, PLAYER_FLAGS_CONTESTED_PVP))
        {
            SetPvPContested(state);

            // Legacy way of calling MoveInLineOfSight for nearby contested guards
            // TODO: Find a better way to do this, needs marking for a delayed reaction update
            UpdateVisibilityAndView();
        }

        // Refresh timer
        pvpInfo.timerPvPContestedRemaining = 30000;
    }
}

void Player::SetBattleGroundEntryPoint(uint32 mapId, float x, float y, float z, float o)
{
    m_bgData.joinPos = WorldLocation(mapId, x, y, z, o);
    m_bgData.m_needSave = true;
}

void Player::SetBattleGroundEntryPoint(Player* leader /*= nullptr*/, bool queuedAtBGPortal /*= false*/)
{
    // Already in BG ? Then we already have a teleport back point
    if (InBattleGround())
        return;
    // chat command use case, or non-group join
    if (!leader || !leader->IsInWorld() || leader->IsTaxiFlying() || leader->GetMap()->IsDungeon() || leader->GetMap()->IsBattleGround())
        leader = this;

    if (leader->IsInWorld() && !leader->IsTaxiFlying())
    {
        // If leader queued at a BG portal, use that portal's exit coordinates as the entry point
        // coords were already defined in HandleAreaTriggerOpcode, so just re-use them
        if (queuedAtBGPortal)
        {
            m_bgData.joinPos = WorldLocation(leader->GetBattleGroundEntryPoint());
            m_bgData.m_needSave = true;
            return;
        }
        // If map is dungeon find linked graveyard
        if (leader->GetMap()->IsDungeon())
        {
            if (WorldSafeLocsEntry const* entry = sObjectMgr.GetClosestGraveYard(leader->GetPositionX(), leader->GetPositionY(), leader->GetPositionZ(), leader->GetMapId(), leader->GetTeam()))
            {
                m_bgData.joinPos = WorldLocation(entry->map_id, entry->x, entry->y, entry->z, sObjectMgr.GetWorldSafeLocFacing(entry->ID));
                m_bgData.m_needSave = true;
                return;
            }
            else
                sLog.outError("SetBattleGroundEntryPoint: Dungeon map %u has no linked graveyard, setting home location as entry point.", leader->GetMapId());
        }
        // If new entry point is not BG or arena set it
        else if (!leader->GetMap()->IsBattleGround())
        {
            m_bgData.joinPos = WorldLocation(leader->GetMapId(), leader->GetPositionX(), leader->GetPositionY(), leader->GetPositionZ(), leader->GetOrientation());
            m_bgData.m_needSave = true;
            return;
        }
    }

    // In error cases use homebind position
    m_bgData.joinPos = WorldLocation(m_homebindMapId, m_homebindX, m_homebindY, m_homebindZ, 0.0f);
    m_bgData.m_needSave = true;
}

void Player::LeaveBattleground(bool teleportToEntryPoint)
{
    //ClearUpdateMask(true);
    if (BattleGround* bg = GetBattleGround())
    {
        // nor more Waiting to Resurrect
        RemoveAurasDueToSpell(2584);

        if (!IsGameMaster() &&
                sWorld.getConfig(CONFIG_BOOL_BATTLEGROUND_CAST_DESERTER) &&
                !sWorld.IsStopped() &&
                (bg->GetStatus() == STATUS_IN_PROGRESS || bg->GetStatus() == STATUS_WAIT_JOIN)
                )
        {
            //lets check if player was teleported from BG and schedule delayed Deserter spell cast
            if (IsBeingTeleportedFar())
                ScheduleDelayedOperation(DELAYED_SPELL_CAST_DESERTER);
            else
                AddAura(26013, 0, this);               // Deserter
        }
        bg->RemovePlayerAtLeave(GetObjectGuid(), teleportToEntryPoint, true);
        sLog.out(LOG_BG, "[%u,%u]: %s:%u [%u:%s] leaves",
                 bg->GetMapId(), bg->GetInstanceID(),
                 GetName(),
                 GetGUIDLow(), GetSession()->GetAccountId(), GetSession()->GetRemoteAddress().c_str(),
                 bg->GetTypeID());
    }
}

bool Player::CanJoinToBattleground() const
{
    // check Deserter debuff
    return !HasAura(26013);
}

bool Player::IsVisibleInGridForPlayer(Player const* pl) const
{
    // gamemaster in GM mode see all, including ghosts
    if (pl->IsGameMaster() && GetSession()->GetSecurity() <= pl->GetSession()->GetSecurity())
        return true;

    // Nostalrius: visibilite des fantomes par membres du raid.
    if (IsInSameRaidWith(pl))
        return true;

    // Live player see live player or dead player with not realized corpse
    if (pl->GetDeathState() != DEAD)
        return GetDeathState() != DEAD;

    // Ghost see other friendly ghosts, that's for sure
    if (GetDeathState() == DEAD && IsFriendlyTo(pl))
        return true;

    // Dead player see live players near own corpse
    if (IsAlive())
    {
        Corpse* corpse = pl->GetCorpse();
        if (corpse)
        {
            // 20 - aggro distance for same level, 25 - max additional distance if player level less that creature level
            // Fix Nostalrius : la distance est fix a 100m.
            if (corpse->IsWithinDistInMap(this, 100))
                return true;
        }
    }

    // and not see any other
    return false;
}

bool Player::IsVisibleGloballyFor(Player* viewer) const
{
    if (!viewer)
        return false;

    // Always can see self
    if (viewer == this)
        return true;

    // Check Phasing
    if (!viewer->CanSeeInWorld(this))
        return false;

    // Visible units, always are visible for all players
    if (GetVisibility() == VISIBILITY_ON)
        return true;

    // GMs are visible for higher gms (or players are visible for gms)
    uint8 security = viewer->GetSession()->GetSecurity();
    if (security > SEC_PLAYER)
        return m_gmInvisibilityLevel <= security;

    // non faction visibility non-breakable for non-GMs
    if (GetVisibility() == VISIBILITY_OFF)
        return false;

    // non-gm stealth/invisibility not hide from global player lists
    return true;
}

void Player::UpdateVisibilityOf(WorldObject const* viewPoint, WorldObject* target)
{
    bool inVisibleList = IsInVisibleList(target);
    if (inVisibleList)
    {
        if (!target->FindMap() || !target->isWithinVisibilityDistanceOf(this, viewPoint, inVisibleList) || !target->IsVisibleForInState(this, viewPoint, true))
        {
            ObjectGuid t_guid = target->GetObjectGuid();

            target->DestroyForPlayer(this);
            std::unique_lock<std::shared_timed_mutex> lock(m_visibleGUIDs_lock);
            m_visibleGUIDs.erase(t_guid);
            lock.unlock();

            if (Player* plTarget = target->ToPlayer())
                if (plTarget->m_broadcaster)
                    plTarget->m_broadcaster->RemoveListener(this);

            DEBUG_FILTER_LOG(LOG_FILTER_VISIBILITY_CHANGES, "%s out of range for player %u. Distance = %f", t_guid.GetString().c_str(), GetGUIDLow(), GetDistance(target));
        }
    }
    else
    {
        if (target->FindMap() && target->isWithinVisibilityDistanceOf(this, viewPoint, inVisibleList) && target->IsVisibleForInState(this, viewPoint, false))
        {
            target->SendCreateUpdateToPlayer(this);
            if (target->GetTypeId() != TYPEID_GAMEOBJECT || !((GameObject*)target)->IsMoTransport())
            {
                std::unique_lock<std::shared_timed_mutex> lock(m_visibleGUIDs_lock);
                m_visibleGUIDs.insert(target->GetObjectGuid());
                lock.unlock();

                if (Player* plTarget = target->ToPlayer())
                    if (plTarget->m_broadcaster)
                        plTarget->m_broadcaster->AddListener(this);
            }

            DEBUG_FILTER_LOG(LOG_FILTER_VISIBILITY_CHANGES, "Object %u (Type: %u) is visible now for player %u. Distance = %f", target->GetGUIDLow(), target->GetTypeId(), GetGUIDLow(), GetDistance(target));
        }
    }
}

template<class T>
inline void UpdateVisibilityOf_helper(ObjectGuidSet& s64, T* target)
{
    s64.insert(target->GetObjectGuid());
}

template<>
inline void UpdateVisibilityOf_helper(ObjectGuidSet& s64, GameObject* target)
{
    // Naxxramas necropolis. Always visible.
    if (target->GetEntry() == 181223)
        return;

    if (!target->IsMoTransport())
    {
        s64.insert(target->GetObjectGuid());
    }
}

template<class T>
void AddBroadcastListener(T* target, Player* me)
{
}
template<>
void AddBroadcastListener(Player* target, Player* me)
{
    if (target->m_broadcaster)
        target->m_broadcaster->AddListener(me);
}

template<class T>
void RemoveBroadcastListener(T* target, Player* me)
{
}
template<>
void RemoveBroadcastListener(Player* target, Player* me)
{
    if (target->m_broadcaster)
        target->m_broadcaster->RemoveListener(me);
}

// Only called if player is in combat and not in dungeon.
void Player::BeforeVisibilityDestroy(Creature* creature)
{
    if (creature->IsInCombat() && IsInCombatWithCreature(creature))
        GetHostileRefManager().deleteReference(creature);
}

template<class T>
void Player::UpdateVisibilityOf(WorldObject const* viewPoint, T* target, UpdateData& data, std::set<WorldObject*>& visibleNow)
{
    bool inVisibleList = IsInVisibleList(target);
    if (inVisibleList)
    {
        if (!target->FindMap() || !target->isWithinVisibilityDistanceOf(this, viewPoint, inVisibleList) || !target->IsVisibleForInState(this, viewPoint, true))
        {
            ObjectGuid t_guid = target->GetObjectGuid();

            // Make sure mobs who become out of range leave combat before grid unload.
            if (target->IsCreature() && IsInCombat() && !GetMap()->IsDungeon())
                BeforeVisibilityDestroy((Creature*)target);

            target->BuildOutOfRangeUpdateBlock(data);
            std::unique_lock<std::shared_timed_mutex> lock(m_visibleGUIDs_lock);
            m_visibleGUIDs.erase(t_guid);
            lock.unlock();

            RemoveBroadcastListener(target, this);
            DEBUG_FILTER_LOG(LOG_FILTER_VISIBILITY_CHANGES, "%s is out of range for %s. Distance = %f", t_guid.GetString().c_str(), GetGuidStr().c_str(), GetDistance(target));
        }
    }
    else
    {
        if (target->FindMap() && target->isWithinVisibilityDistanceOf(this, viewPoint, inVisibleList) && target->IsVisibleForInState(this, viewPoint, false))
        {
            visibleNow.insert(target);
            target->BuildCreateUpdateBlockForPlayer(data, this);
            std::unique_lock<std::shared_timed_mutex> lock(m_visibleGUIDs_lock);
            UpdateVisibilityOf_helper(m_visibleGUIDs, target);
            lock.unlock();

            AddBroadcastListener(target, this);
            DEBUG_FILTER_LOG(LOG_FILTER_VISIBILITY_CHANGES, "%s is visible now for %s. Distance = %f", target->GetGuidStr().c_str(), GetGuidStr().c_str(), GetDistance(target));
        }
    }
}

template void Player::UpdateVisibilityOf(WorldObject const* viewPoint, Player*        target, UpdateData& data, std::set<WorldObject*>& visibleNow);
template void Player::UpdateVisibilityOf(WorldObject const* viewPoint, Creature*      target, UpdateData& data, std::set<WorldObject*>& visibleNow);
template void Player::UpdateVisibilityOf(WorldObject const* viewPoint, Corpse*        target, UpdateData& data, std::set<WorldObject*>& visibleNow);
template void Player::UpdateVisibilityOf(WorldObject const* viewPoint, GameObject*    target, UpdateData& data, std::set<WorldObject*>& visibleNow);
template void Player::UpdateVisibilityOf(WorldObject const* viewPoint, DynamicObject* target, UpdateData& data, std::set<WorldObject*>& visibleNow);
template void Player::UpdateVisibilityOf(WorldObject const* viewPoint, WorldObject*   target, UpdateData& data, std::set<WorldObject*>& visibleNow);

void Player::SetLongSight(Aura const* aura)
{
    if (aura)
    {
        // already an active long sight spell
        if (m_longSightSpell)
            return;
        m_longSightSpell = aura->GetSpellProto()->Id;
        // Should the viewpoint be placed at a fixed range or at visibility distance ?
        // In absence of evidence, let's move the camera at visibility distance in front of the player
        m_longSightRange = GetMap()->GetVisibilityDistance();
        DynamicObject* dynObj = new DynamicObject;
        if (!dynObj->Create(GetMap()->GenerateLocalLowGuid(HIGHGUID_DYNAMICOBJECT), this, m_longSightSpell,
            aura->GetEffIndex(), GetPositionX(), GetPositionY(), GetPositionZ(), 0, 0, DYNAMIC_OBJECT_FARSIGHT_FOCUS))
        {
            m_longSightSpell = 0;
            m_longSightRange = 0.0f;
            delete dynObj;
            return;
        }
        AddDynObject(dynObj);
        // Needed so the dyn object is properly removed
        SetChannelObjectGuid(dynObj->GetObjectGuid());
        GetMap()->Add(dynObj);
        UpdateLongSight();
        GetCamera().SetView(dynObj, false);
    }
    else
    {
        m_longSightSpell = 0;
        m_longSightRange = 0.0f;
        GetCamera().ResetView(false);
    }
}

void Player::UpdateLongSight()
{
    if (!m_longSightSpell)
        return;
    if (DynamicObject* dynObj = GetDynObject(m_longSightSpell))
        dynObj->Relocate(GetPositionX() + m_longSightRange * cos(GetOrientation()),
                         GetPositionY() + m_longSightRange * sin(GetOrientation()),
                         GetPositionZ());
}

void Player::InitPrimaryProfessions()
{
    SetFreePrimaryProfessions(sWorld.getConfig(CONFIG_UINT32_MAX_PRIMARY_TRADE_SKILL));
}

void Player::SetComboPoints()
{
    Unit* combotarget = ObjectAccessor::GetUnit(*this, m_comboTargetGuid);
    if (combotarget)
    {
        SetGuidValue(PLAYER_FIELD_COMBO_TARGET, combotarget->GetObjectGuid());
        SetByteValue(PLAYER_FIELD_BYTES, 1, m_comboPoints);
    }
    /*else
    {
        // can be nullptr, and then points=0. Use unknown; to reset points of some sort?
        data << PackedGuid();
        data << uint8(0);
        GetSession()->SendPacket(&data);
    }*/
}

void Player::AddComboPoints(Unit* target, int8 count)
{
    if (!count)
        return;

    // without combo points lost (duration checked in aura)
    RemoveSpellsCausingAura(SPELL_AURA_RETAIN_COMBO_POINTS);

    if (target->GetObjectGuid() == m_comboTargetGuid)
        m_comboPoints += count;
    else
    {
        if (m_comboTargetGuid)
            if (Unit* target2 = ObjectAccessor::GetUnit(*this, m_comboTargetGuid))
                target2->RemoveComboPointHolder(GetGUIDLow());

        m_comboTargetGuid = target->GetObjectGuid();
        m_comboPoints = count;

        target->AddComboPointHolder(GetGUIDLow());
    }

    if (m_comboPoints > 5) m_comboPoints = 5;
    if (m_comboPoints < 0) m_comboPoints = 0;

    SetComboPoints();
}

void Player::ClearComboPoints()
{
    if (!m_comboTargetGuid)
        return;

    // without combopoints lost (duration checked in aura)
    RemoveSpellsCausingAura(SPELL_AURA_RETAIN_COMBO_POINTS);

    m_comboPoints = 0;

    SetComboPoints();

    if (Unit* target = ObjectAccessor::GetUnit(*this, m_comboTargetGuid))
        target->RemoveComboPointHolder(GetGUIDLow());

    m_comboTargetGuid.Clear();
}

void Player::SetGroup(Group* group, int8 subgroup)
{
    if (group == nullptr)
        m_group.unlink();
    else
    {
        // never use SetGroup without a subgroup unless you specify nullptr for group
        MANGOS_ASSERT(subgroup >= 0);
        m_group.link(group, this);
        m_group.setSubGroup((uint8)subgroup);
    }
}

void Player::SendInitialPacketsBeforeAddToMap()
{
    WorldPacket data(SMSG_SET_REST_START, 4);
    data << uint32(0);                                      // rest state time
    GetSession()->SendPacket(&data);

    // Homebind
    data.Initialize(SMSG_BINDPOINTUPDATE, 5 * 4);
    data << m_homebindX << m_homebindY << m_homebindZ;
    data << (uint32) m_homebindMapId;
    data << (uint32) m_homebindAreaId;
    GetSession()->SendPacket(&data);

    // SMSG_SET_PROFICIENCY
    // SMSG_UPDATE_AURA_DURATION

    // tutorial stuff
    GetSession()->SendTutorialsData();

    SendInitialSpells();

    if (MasterPlayer* masterPlayer = GetSession()->GetMasterPlayer())
        masterPlayer->SendInitialActionButtons();

    m_reputationMgr.SendInitialReputations();
    m_honorMgr.Update();

    // SMSG_SET_AURA_SINGLE

    data.Initialize(SMSG_LOGIN_SETTIMESPEED, 4 + 4);
    data << uint32(secsToTimeBitFields(sWorld.GetGameTime()));
    data << (float)0.01666667f;                             // game speed
    GetSession()->SendPacket(&data);

    // set fly flag if in fly form or taxi flight to prevent visually drop at ground in showup moment
    if (IsTaxiFlying())
        m_movementInfo.AddMovementFlag(MOVEFLAG_FLYING);

    SetMover(this);
}

void Player::SendInitialPacketsAfterAddToMap(bool login)
{
    // update zone
    uint32 newzone, newarea;
    GetZoneAndAreaId(newzone, newarea);
    UpdateZone(newzone, newarea);                           // also call SendInitWorldStates();

    if (login)
        CastSpell(this, 836, true);                             // LOGINEFFECT

    // set some aura effects that send packet to player client after add player to map
    // SendMessageToSet not send it to player not it map, only for aura that not changed anything at re-apply
    // same auras state lost at far teleport, send it one more time in this case also
    static const AuraType auratypes[] =
    {
        SPELL_AURA_MOD_FEAR,     SPELL_AURA_TRANSFORM,                 SPELL_AURA_WATER_WALK,
        SPELL_AURA_FEATHER_FALL, SPELL_AURA_HOVER,                     SPELL_AURA_SAFE_FALL,
        SPELL_AURA_NONE
    };
    for (AuraType const* itr = &auratypes[0]; itr && itr[0] != SPELL_AURA_NONE; ++itr)
    {
        Unit::AuraList const& auraList = GetAurasByType(*itr);
        if (!auraList.empty())
            auraList.front()->ApplyModifier(true, true);
    }

    if (HasAuraType(SPELL_AURA_MOD_STUN))
        SetRooted(true);

    SendEnchantmentDurations();                             // must be after add to map
    SendItemDurations();                                    // must be after add to map
}

void Player::SendUpdateToOutOfRangeGroupMembers()
{
    if (m_groupUpdateMask == GROUP_UPDATE_FLAG_NONE)
        return;
    if (Group* group = GetGroup())
        group->UpdatePlayerOutOfRange(this);

    m_groupUpdateMask = GROUP_UPDATE_FLAG_NONE;
    m_auraUpdateMask = 0;
    if (Pet* pet = GetPet())
        pet->ResetAuraUpdateMask();
}

void Player::SendTransferAborted(uint8 reason) const
{
    WorldPacket data(SMSG_TRANSFER_ABORTED, 1);
    data << uint8(reason);                                  // transfer abort reason
    GetSession()->SendPacket(&data);
}

void Player::SendInstanceResetWarning(uint32 mapid, uint32 _time) const
{
#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_8_4
    // type of warning, based on the time remaining until reset
    uint32 type;
    if (_time > 3600)
        type = RAID_INSTANCE_WELCOME;
    else if (_time > 900 && _time <= 3600)
        type = RAID_INSTANCE_WARNING_HOURS;
    else if (_time > 300 && _time <= 900)
        type = RAID_INSTANCE_WARNING_MIN;
    else
        type = RAID_INSTANCE_WARNING_MIN_SOON;
    WorldPacket data(SMSG_RAID_INSTANCE_MESSAGE, 4 + 4 + 4);
    data << uint32(type);
    data << uint32(mapid);
    data << uint32(_time);
    GetSession()->SendPacket(&data);
#endif
}

void Player::ApplyEquipCooldown(Item* pItem)
{
    if (pItem->GetProto()->Flags & ITEM_FLAG_NO_EQUIP_COOLDOWN)
        return;

    for (const auto& spellData : pItem->GetProto()->Spells)
    {
        // no spell
        if (!spellData.SpellId)
            continue;

        // wrong triggering type (note: ITEM_SPELLTRIGGER_ON_NO_DELAY_USE not have cooldown)
        if (spellData.SpellTrigger != ITEM_SPELLTRIGGER_ON_USE)
            continue;

        SpellEntry const* spellentry = sSpellMgr.GetSpellEntry(spellData.SpellId);
        if (!spellentry)
            continue;

        AddCooldown(*spellentry, nullptr, false, 30 * IN_MILLISECONDS);

        WorldPacket data(SMSG_ITEM_COOLDOWN, 12);
        data << ObjectGuid(pItem->GetObjectGuid());
        data << uint32(spellData.SpellId);
        GetSession()->SendPacket(&data);
    }
}

void Player::ResetSpells()
{
    // not need after this call
    if (HasAtLoginFlag(AT_LOGIN_RESET_SPELLS))
        RemoveAtLoginFlag(AT_LOGIN_RESET_SPELLS, true);

    // make full copy of map (spells removed and marked as deleted at another spell remove
    // and we can't use original map for safe iterative with visit each spell at loop end
    PlayerSpellMap smap = GetSpellMap();

    for (const auto& iter : smap)
        RemoveSpell(iter.first, false, false);             // only iter->first can be accessed, object by iter->second can be deleted already

    LearnDefaultSpells();
    LearnQuestRewardedSpells();
}

void Player::LearnDefaultSpells()
{
    // learn default race/class spells
    PlayerInfo const* info = sObjectMgr.GetPlayerInfo(GetRace(), GetClass());
    if (!info)
        return;

    for (const auto spell : info->spell)
    {
        DEBUG_LOG("PLAYER (Class: %u Race: %u): Adding initial spell, id = %u", uint32(GetClass()), uint32(GetRace()), spell);
        if (!IsInWorld())                                   // will send in INITIAL_SPELLS in list anyway at map add
            AddSpell(spell, true, true, true, false);
        else                                                // but send in normal spell in game learn case
            LearnSpell(spell, true);
    }
}

void Player::LearnQuestRewardedSpells(Quest const* quest)
{
    uint32 spellId = quest->GetRewSpellCast();

    // skip quests without rewarded spell
    if (!spellId)
        return;

    SpellEntry const* spellInfo = sSpellMgr.GetSpellEntry(spellId);
    if (!spellInfo)
        return;

    // check learned spells state
    bool found = false;
    for (uint8 i = 0; i < MAX_EFFECT_INDEX; ++i)
    {
        if (spellInfo->Effect[i] == SPELL_EFFECT_LEARN_SPELL && !HasSpell(spellInfo->EffectTriggerSpell[i]))
        {
            found = true;
            break;
        }
    }

    // skip quests with not teaching spell or already known spell
    if (!found)
        return;

    // prevent learn non first rank unknown profession and second specialization for same profession)
    uint32 learned_0 = spellInfo->EffectTriggerSpell[EFFECT_INDEX_0];
    if (sSpellMgr.GetSpellRank(learned_0) > 1 && !HasSpell(learned_0))
    {
        // not have first rank learned (unlearned prof?)
        uint32 first_spell = sSpellMgr.GetFirstSpellInChain(learned_0);
        if (!HasSpell(first_spell))
            return;

        SpellEntry const* learnedInfo = sSpellMgr.GetSpellEntry(learned_0);
        if (!learnedInfo)
            return;

        // specialization
        if (learnedInfo->Effect[EFFECT_INDEX_0] == SPELL_EFFECT_TRADE_SKILL && learnedInfo->Effect[EFFECT_INDEX_1] == 0)
        {
            // search other specialization for same prof
            for (const auto& itr : m_spells)
            {
                if (itr.second.state == PLAYERSPELL_REMOVED || itr.first == learned_0)
                    continue;

                SpellEntry const* itrInfo = sSpellMgr.GetSpellEntry(itr.first);
                if (!itrInfo)
                    return;

                // compare only specializations
                if (itrInfo->Effect[EFFECT_INDEX_0] != SPELL_EFFECT_TRADE_SKILL || itrInfo->Effect[EFFECT_INDEX_1] != 0)
                    continue;

                // compare same chain spells
                if (sSpellMgr.GetFirstSpellInChain(itr.first) != first_spell)
                    continue;

                // now we have 2 specialization, learn possible only if found is lesser specialization rank
                if (!sSpellMgr.IsHighRankOfSpell(learned_0, itr.first))
                    return;
            }
        }
    }

    CastSpell(this, spellId, true);
}

void Player::LearnQuestRewardedSpells()
{
    // learn spells received from quest completing
    for (const auto& itr : mQuestStatus)
    {
        // skip no rewarded quests
        if (!itr.second.m_rewarded)
            continue;

        Quest const* quest = sObjectMgr.GetQuestTemplate(itr.first);
        if (!quest)
            continue;

        LearnQuestRewardedSpells(quest);
    }
}

void Player::SetSemaphoreTeleportNear(bool semphsetting)
{
    mSemaphoreTeleport_Near = semphsetting;
    if (!IsBeingTeleported())
    {
        m_teleportRecover = std::function<void()>();
        m_teleportRecoverDelayed = std::function<void()>();
    }
}

void Player::SetSemaphoreTeleportFar(bool semphsetting)
{
    mSemaphoreTeleport_Far = semphsetting;
    if (!IsBeingTeleported())
    {
        m_teleportRecover = std::function<void()>();
        m_teleportRecoverDelayed = std::function<void()>();
    }
}

BattleGround* Player::GetBattleGround() const
{
    if (GetBattleGroundId() == 0)
        return nullptr;

    return sBattleGroundMgr.GetBattleGround(GetBattleGroundId(), m_bgData.bgTypeID);
}

bool Player::GetBGAccessByLevel(BattleGroundTypeId bgTypeId) const
{
    // get a template bg instead of running one
    BattleGround* bg = sBattleGroundMgr.GetBattleGroundTemplate(bgTypeId);
    if (!bg)
        return false;

    if (GetLevel() < bg->GetMinLevel() || GetLevel() > bg->GetMaxLevel())
        return false;

    return true;
}

uint32 Player::GetMinLevelForBattleGroundBracketId(BattleGroundBracketId bracket_id, BattleGroundTypeId bgTypeId)
{
    if (bgTypeId == BATTLEGROUND_AV)
        return 51;
    if (bgTypeId == BATTLEGROUND_AB)
        bracket_id = BattleGroundBracketId(uint32(bracket_id) + 1);

    if (bracket_id > BG_BRACKET_ID_LAST)
        bracket_id = BG_BRACKET_ID_LAST;

    BattleGround* bg = sBattleGroundMgr.GetBattleGroundTemplate(bgTypeId);
    ASSERT(bg);
    if (bgTypeId == BATTLEGROUND_AB)
        return 10 * bracket_id + bg->GetMinLevel() - 10;
    else
        return 10 * bracket_id + bg->GetMinLevel();
}

uint32 Player::GetMaxLevelForBattleGroundBracketId(BattleGroundBracketId bracket_id, BattleGroundTypeId bgTypeId)
{
    if (bgTypeId == BATTLEGROUND_AV)
        return 61;
    if (bracket_id >= BG_BRACKET_ID_LAST || (bgTypeId == BATTLEGROUND_AB && bracket_id == (BG_BRACKET_ID_LAST - 1)))
        return (GetMinLevelForBattleGroundBracketId(BG_BRACKET_ID_LAST, bgTypeId) + 1);

    return GetMinLevelForBattleGroundBracketId(bracket_id, bgTypeId) + 10;
}

BattleGroundBracketId Player::GetBattleGroundBracketIdFromLevel(BattleGroundTypeId bgTypeId) const
{
    BattleGround* bg = sBattleGroundMgr.GetBattleGroundTemplate(bgTypeId);
    ASSERT(bg);

    if (GetLevel() < bg->GetMinLevel())
        return BG_BRACKET_ID_NONE;

    uint32 bracket_id = (GetLevel() - bg->GetMinLevel()) / 10;
    if (bracket_id > MAX_BATTLEGROUND_BRACKETS)
        return BG_BRACKET_ID_LAST;

    return BattleGroundBracketId(bracket_id);
}

float Player::GetReputationPriceDiscount(Creature const* pCreature) const
{
    FactionTemplateEntry const* vendor_faction = pCreature->getFactionTemplateEntry();
    if (!vendor_faction || !vendor_faction->faction)
        return 1.0f;

    float mod = 1.0f;
    ReputationRank rank = GetReputationRank(vendor_faction->faction);
    if (rank >= REP_HONORED)
        mod -= 0.1f;

    switch (vendor_faction->faction)
    {
        // Alliance
        case 72:  // Stormwind
        case 47:  // Ironforge
        case 54:  // Gnomeregan
        case 69:  // Darnassus
        case 730: // Stormpike Guard
        // Horde
        case 68:  // Undercity
        case 76:  // Orgrimmar
        case 81:  // Thunder Bluff
        case 530: // Darkspear
        case 729: // Frostwolf Clan
        {
            // honor rank >= 3
            if (m_honorMgr.GetRank().visualRank >= 3)
                mod -= 0.1f;
            break;
        }
    }

    return mod;
}

/**
 * Check spell availability for training base at SkillLineAbility/SkillRaceClassInfo data.
 * Checked allowed race/class and dependent from race/class allowed min level
 *
 * @param spellId   checked spell id
 * @param pReqlevel if arg provided then function work in view mode (level check not applied but detected minlevel returned to var by arg pointer.
                    if arg not provided then considered train action mode and level checked
 * @return          true if spell available for show in trainer list (with skip level check) or training.
 */
bool Player::IsSpellFitByClassAndRace(uint32 spellId, uint32* pReqlevel /*= nullptr*/) const
{
    uint32 racemask  = GetRaceMask();
    uint32 classmask = GetClassMask();

    SkillLineAbilityMapBounds bounds = sSpellMgr.GetSkillLineAbilityMapBoundsBySpellId(spellId);
    if (bounds.first == bounds.second)
        return true;

    for (SkillLineAbilityMap::const_iterator _spell_idx = bounds.first; _spell_idx != bounds.second; ++_spell_idx)
    {
        SkillLineAbilityEntry const* abilityEntry = _spell_idx->second;
        // skip wrong race skills
        if (abilityEntry->racemask && (abilityEntry->racemask & racemask) == 0)
            continue;

        // skip wrong class skills
        if (abilityEntry->classmask && (abilityEntry->classmask & classmask) == 0)
            continue;

        SkillRaceClassInfoMapBounds bounds = sSpellMgr.GetSkillRaceClassInfoMapBounds(abilityEntry->skillId);
        for (SkillRaceClassInfoMap::const_iterator itr = bounds.first; itr != bounds.second; ++itr)
        {
            SkillRaceClassInfoEntry const* skillRCEntry = itr->second;
            if ((skillRCEntry->raceMask & racemask) && (skillRCEntry->classMask & classmask))
            {
                if (skillRCEntry->flags & ABILITY_SKILL_NONTRAINABLE)
                    return false;

                if (pReqlevel)                              // show trainers list case
                {
                    if (skillRCEntry->reqLevel)
                    {
                        *pReqlevel = skillRCEntry->reqLevel;
                        return true;
                    }
                }
                else                                        // check availble case at train
                {
                    if (skillRCEntry->reqLevel && GetLevel() < skillRCEntry->reqLevel)
                        return false;
                }
            }
        }

        return true;
    }

    return false;
}

bool Player::HasQuestForGO(int32 GOId) const
{
    for (int i = 0; i < MAX_QUEST_LOG_SIZE; ++i)
    {
        uint32 questid = GetQuestSlotQuestId(i);
        if (questid == 0)
            continue;

        QuestStatusMap::const_iterator qs_itr = mQuestStatus.find(questid);
        if (qs_itr == mQuestStatus.end())
            continue;

        QuestStatusData const& qs = qs_itr->second;

        if (qs.m_status == QUEST_STATUS_INCOMPLETE)
        {
            Quest const* qinfo = sObjectMgr.GetQuestTemplate(questid);
            if (!qinfo)
                continue;

            if (GetGroup() && GetGroup()->isRaidGroup() && !qinfo->IsAllowedInRaid())
                continue;

            for (int j = 0; j < QUEST_OBJECTIVES_COUNT; ++j)
            {
                if (qinfo->ReqCreatureOrGOId[j] >= 0)       //skip non GO case
                    continue;

                if ((-1)*GOId == qinfo->ReqCreatureOrGOId[j] && qs.m_creatureOrGOcount[j] < qinfo->ReqCreatureOrGOCount[j])
                    return true;
            }
        }
    }
    return false;
}

void Player::UpdateForQuestWorldObjects()
{
    // Don't process updates if we're not in the world (map is nullptr)
    if (!IsInWorld() || !FindMap())
        return;

    uint32 count = 0;
    UpdateData upd;
    std::shared_lock<std::shared_timed_mutex> lock(m_visibleGUIDs_lock);
    for (const auto& guid : m_visibleGUIDs)
    {
        if (guid.IsGameObject())
        {
            if (GameObject* obj = GetMap()->GetGameObject(guid))
                if (!obj->IsTransport())
                    if (m_visibleGobjQuestActivated[obj->GetObjectGuid()] != obj->ActivateToQuest(this))
                    {
                        ++count;
                        obj->BuildCreateUpdateBlockForPlayer(upd, this); //[-ZERO] we must send create packet because of GAMEOBJECT_FLAGS change (not dynamic) - probably incorrect
                    }
        }
    }
    lock.unlock();
    if (count)
        upd.Send(GetSession());
}

void Player::SendSummonRequest(ObjectGuid summonerGuid, uint32 mapId, uint32 zoneId, float x, float y, float z)
{
    SetSummonPoint(mapId, x, y, z);

    WorldPacket data(SMSG_SUMMON_REQUEST, 8 + 4 + 4);
    data << summonerGuid;                    // summoner guid
    data << uint32(zoneId);                  // summoner zone
    data << uint32(MAX_PLAYER_SUMMON_DELAY * IN_MILLISECONDS); // auto decline after msecs
    GetSession()->SendPacket(&data);
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
    if (IsTaxiFlying())
    {
        GetMotionMaster()->MovementExpired();
        m_taxi.ClearTaxiDestinations();
    }

    // drop flag at summon
    // this code can be reached only when GM is summoning player who carries flag, because player should be immune to summoning spells when he carries flag
    if (BattleGround* bg = GetBattleGround())
        bg->EventPlayerDroppedFlag(this);

    m_summon_expire = 0;

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

void Player::AutoUnequipWeaponsIfNeed()
{
    if (Item* pMainHandWeapon = GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND))
        if (CanUseItem(pMainHandWeapon, false) != EQUIP_ERR_OK)
            AutoUnequipItemFromSlot(EQUIPMENT_SLOT_MAINHAND);

    if (Item* pOffHandWeapon = GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND))
        if (CanUseItem(pOffHandWeapon, false) != EQUIP_ERR_OK)
            AutoUnequipItemFromSlot(EQUIPMENT_SLOT_OFFHAND);

    if (Item* pOffHandWeapon = GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_RANGED))
        if (CanUseItem(pOffHandWeapon, false) != EQUIP_ERR_OK)
            AutoUnequipItemFromSlot(EQUIPMENT_SLOT_RANGED);
}

void Player::AutoUnequipOffhandIfNeed()
{
    // need to unequip offhand for 2h-weapon
    if (!IsTwoHandUsed())
        return;

    AutoUnequipItemFromSlot(EQUIPMENT_SLOT_OFFHAND);
}

void Player::AutoUnequipItemFromSlot(uint32 slot)
{
    Item* pItem = GetItemByPos(INVENTORY_SLOT_BAG_0, slot);
    if (!pItem)
        return;

    ItemPosCountVec itemDestination;
    uint8 main_msg = CanStoreItem(NULL_BAG, NULL_SLOT, itemDestination, pItem, false);
    if (main_msg == EQUIP_ERR_OK)
    {
        RemoveItem(INVENTORY_SLOT_BAG_0, slot, true);
        StoreItem(itemDestination, pItem, true);
    }
    else
    {
        MoveItemFromInventory(INVENTORY_SLOT_BAG_0, slot, true);
        CharacterDatabase.BeginTransaction(GetGUIDLow());
        pItem->DeleteFromInventoryDB();                   // deletes item from character's inventory
        pItem->SaveToDB();                                // recursive and not have transaction guard into self, item not in inventory and can be save standalone
        CharacterDatabase.CommitTransaction();

        std::string subject = GetSession()->GetMangosString(LANG_NOT_EQUIPPED_ITEM);
        MailDraft(subject).AddItem(pItem).SendMailTo(this, MailSender(this, MAIL_STATIONERY_GM), MAIL_CHECK_MASK_COPIED);
    }
}

ZoneScript* Player::GetZoneScript() const
{
    return sZoneScriptMgr.GetZoneScriptToZoneId(GetZoneId());
}

bool Player::HasItemFitToSpellReqirements(SpellEntry const* spellInfo, Item const* ignoreItem)
{
    if (spellInfo->EquippedItemClass < 0)
        return true;

    // scan other equipped items for same requirements (mostly 2 daggers/etc)
    // for optimize check 2 used cases only
    switch (spellInfo->EquippedItemClass)
    {
        case ITEM_CLASS_WEAPON:
        {
            for (int i = EQUIPMENT_SLOT_MAINHAND; i < EQUIPMENT_SLOT_TABARD; ++i)
                if (Item* item = GetItemByPos(INVENTORY_SLOT_BAG_0, i))
                    if (item != ignoreItem && item->IsFitToSpellRequirements(spellInfo) && !item->IsBroken())
                        return true;
            break;
        }
        case ITEM_CLASS_ARMOR:
        {
            // tabard not have dependent spells
            for (int i = EQUIPMENT_SLOT_START; i < EQUIPMENT_SLOT_MAINHAND; ++i)
                if (Item* item = GetItemByPos(INVENTORY_SLOT_BAG_0, i))
                    if (item != ignoreItem && item->IsFitToSpellRequirements(spellInfo) && !item->IsBroken())
                        return true;

            // shields can be equipped to offhand slot
            if (Item* item = GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND))
                if (item != ignoreItem && item->IsFitToSpellRequirements(spellInfo) && !item->IsBroken())
                    return true;

            // ranged slot can have some armor subclasses
            if (Item* item = GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_RANGED))
                if (item != ignoreItem && item->IsFitToSpellRequirements(spellInfo) && !item->IsBroken())
                    return true;

            break;
        }
        default:
            sLog.outError("HasItemFitToSpellReqirements: Not handled spell requirement for item class %u", spellInfo->EquippedItemClass);
            break;
    }

    return false;
}

void Player::RemoveItemDependentAurasAndCasts(Item* pItem)
{
    ItemPrototype const* itemProto = pItem->GetProto();
    // Nostalrius: certains items ne retirent pas de buff.
    switch (itemProto->ItemId)
    {
        // Pierres de sort
        case 5522:
        case 13602:
        case 13603:
            return;
    }
    SpellAuraHolderMap& auras = GetSpellAuraHolderMap();
    for (SpellAuraHolderMap::const_iterator itr = auras.begin(); itr != auras.end();)
    {
        SpellAuraHolder* holder = itr->second;

        // skip passive (passive item dependent spells work in another way) and not self applied auras
        if (holder->IsPassive() ||  holder->GetCasterGuid() != GetObjectGuid())
        {
            ++itr;
            continue;
        }

        // skip if not item dependent or have alternative item
        // NOSTALRIUS
        bool auraOfItem = false;
        for (const auto& spellData : itemProto->Spells)
        {
            if (spellData.SpellId == holder->GetId())
            {
                auraOfItem = true;
                break;
            }
        } 
        if (!auraOfItem)
        {
            ++itr;
            continue;
        }

        // no alt item, remove aura, restart check
        RemoveAurasDueToSpell(holder->GetId());
        itr = auras.begin();
    }

    // currently casted spells can be dependent from item
    for (uint32 i = 0; i < CURRENT_MAX_SPELL; ++i)
    { 
        if (Spell* spell = GetCurrentSpell(CurrentSpellTypes(i)))
        { 
            if (spell->getState() != SPELL_STATE_DELAYED)
            {
                if (!HasItemFitToSpellReqirements(spell->m_spellInfo, pItem))
                    InterruptSpell(CurrentSpellTypes(i));
                else
                {
                    for (const auto& spellData : itemProto->Spells)
                    {
                        if (spellData.SpellId == spell->m_spellInfo->Id && spellData.SpellTrigger == 0)
                            InterruptSpell(CurrentSpellTypes(i));
                    }
                }
            }
        }
    }
}

uint32 Player::GetResurrectionSpellId() const
{
    // search priceless resurrection possibilities
    uint32 prio = 0;
    uint32 spellId = 0;
    AuraList const& dummyAuras = GetAurasByType(SPELL_AURA_DUMMY);
    for (const auto dummyAura : dummyAuras)
    {
        // Soulstone Resurrection                           // prio: 3 (max, non death persistent)
        if (prio < 2 && dummyAura->GetSpellProto()->SpellVisual == 99 && dummyAura->GetSpellProto()->SpellIconID == 92)
        {
            switch (dummyAura->GetId())
            {
                case 20707:
                    spellId =  3026;
                    break;        // rank 1
                case 20762:
                    spellId = 20758;
                    break;        // rank 2
                case 20763:
                    spellId = 20759;
                    break;        // rank 3
                case 20764:
                    spellId = 20760;
                    break;        // rank 4
                case 20765:
                    spellId = 20761;
                    break;        // rank 5
                case 27239:
                    spellId = 27240;
                    break;        // rank 6
                default:
                    sLog.outError("Unhandled spell %u: S.Resurrection", dummyAura->GetId());
                    continue;
            }

            prio = 3;
        }
        // Twisting Nether                                  // prio: 2 (max)
        else if (dummyAura->GetId() == 23701 && roll_chance_i(10))
        {
            prio = 2;
            spellId = 23700;
        }
    }

    // Reincarnation (passive spell)                        // prio: 1
    if (prio < 1 && HasSpell(20608) && IsSpellReady(21169) && HasItemCount(17030, EFFECT_INDEX_1))
        spellId = 21169;

    return spellId;
}

// Used in triggers for check "Only to targets that grant experience or honor" req
bool Player::IsHonorOrXPTarget(Unit* pVictim) const
{
    uint32 v_level = pVictim->GetLevel();
    uint32 k_grey  = MaNGOS::XP::GetGrayLevel(GetLevel());

    // Victim level less gray level
    if (v_level <= k_grey)
        return false;

    if (pVictim->GetTypeId() == TYPEID_UNIT)
    {
        if (((Creature*)pVictim)->IsTotem() ||
            ((Creature*)pVictim)->IsPet() ||
            ((Creature*)pVictim)->GetCreatureInfo()->xp_multiplier==0 ||
            pVictim->HasUnitState(UNIT_STAT_NO_KILL_REWARD))
            return false;
    }
    return true;
}

void Player::RewardSinglePlayerAtKill(Unit* pVictim)
{
    bool PvP = pVictim->IsCharmerOrOwnerPlayerOrPlayerItself();
    uint32 xp = PvP ? 0 : MaNGOS::XP::Gain(this, static_cast<Creature*>(pVictim));
    
    // honor can be in PvP and !PvP (racial leader) cases
    RewardHonor(pVictim, 1);

    // xp and reputation only in !PvP case
    if (!PvP)
    {
        RewardReputation(pVictim, 1);
        GiveXP(xp, pVictim);

        // Pet should only gain XP if mob is not grey to Owner.
        if (xp)
        {
            if (Pet* pet = GetPet())
                pet->GivePetXP(MaNGOS::XP::Gain(pet, static_cast<Creature*>(pVictim)));
        }

        // normal creature (not pet/etc) can be only in !PvP case
        if (pVictim->GetTypeId() == TYPEID_UNIT)
            KilledMonster(((Creature*)pVictim)->GetCreatureInfo(), pVictim->GetObjectGuid());
    }
}

void Player::RewardPlayerAndGroupAtEvent(uint32 creature_id, WorldObject* pRewardSource)
{
    ObjectGuid creature_guid = pRewardSource->GetTypeId() == TYPEID_UNIT ? pRewardSource->GetObjectGuid() : ObjectGuid();

    // prepare data for near group iteration
    if (Group* pGroup = GetGroup())
    {
        for (GroupReference* itr = pGroup->GetFirstMember(); itr != nullptr; itr = itr->next())
        {
            Player* pGroupGuy = itr->getSource();
            if (!pGroupGuy)
                continue;

            if (!pGroupGuy->IsAtGroupRewardDistance(pRewardSource))
                continue;                               // member (alive or dead) or his corpse at req. distance

            // quest objectives updated only for alive group member or dead but with not released body
            if (pGroupGuy->IsAlive() || !pGroupGuy->HasFlag(PLAYER_FLAGS, PLAYER_FLAGS_GHOST))
                pGroupGuy->KilledMonsterCredit(creature_id, creature_guid);
        }
    }
    else                                                    // if (!pGroup)
        KilledMonsterCredit(creature_id, creature_guid);
}

void Player::RewardPlayerAndGroupAtCast(WorldObject* pRewardSource, uint32 spellid)
{
    // prepare data for near group iteration
    if (Group* pGroup = GetGroup())
    {
        for (GroupReference* itr = pGroup->GetFirstMember(); itr != nullptr; itr = itr->next())
        {
            Player* pGroupGuy = itr->getSource();
            if (!pGroupGuy)
                continue;

            if (!pGroupGuy->IsAtGroupRewardDistance(pRewardSource))
                continue;                               // member (alive or dead) or his corpse at req. distance

            // quest objectives updated only for alive group member or dead but with not released body
            if (pGroupGuy->IsAlive() || !pGroupGuy->HasFlag(PLAYER_FLAGS, PLAYER_FLAGS_GHOST))
                pGroupGuy->CastedCreatureOrGO(pRewardSource->GetEntry(), pRewardSource->GetObjectGuid(), spellid, pGroupGuy == this);
        }
    }
    else                                                    // if (!pGroup)
        CastedCreatureOrGO(pRewardSource->GetEntry(), pRewardSource->GetObjectGuid(), spellid);
}

bool Player::IsAtGroupRewardDistance(WorldObject const* pRewardSource) const
{
    if (!pRewardSource)
        return false;

    //if (pRewardSource->IsWithinDistInMap(this, sWorld.getConfig(CONFIG_FLOAT_GROUP_XP_DISTANCE)))
    if (IsWithinLootXPDist(pRewardSource))
        return true;

    if (IsAlive())
        return false;

    Corpse* corpse = GetCorpse();
    if (!corpse)
        return false;

    return corpse->IsWithinLootXPDist(pRewardSource); // pRewardSource->IsWithinDistInMap(corpse, sWorld.getConfig(CONFIG_FLOAT_GROUP_XP_DISTANCE));
}

uint32 Player::GetBaseWeaponSkillValue(WeaponAttackType attType) const
{
    Item* item = GetWeaponForAttack(attType, true, true);

    // unarmed only with base attack
    if (attType != BASE_ATTACK && !item)
        return 0;

    // weapon skill or (unarmed for base attack)
    uint32  skill = item ? item->GetProto()->GetProficiencySkill() : uint32(SKILL_UNARMED);
    return GetSkillValuePure(skill);
}

void Player::ResurectUsingRequestData()
{
    /// Teleport before resurrecting by player, otherwise the player might get attacked from creatures near his corpse
    if (m_resurrectGuid.IsPlayer())
        TeleportTo(m_resurrectMap, m_resurrectX, m_resurrectY, m_resurrectZ, GetOrientation());

    //we cannot resurrect player when we triggered any kind of teleport
    //player will be resurrected upon teleportation (in MSG_MOVE_TELEPORT_ACK handler)
    if (IsBeingTeleported())
    {
        ScheduleDelayedOperation(DELAYED_RESURRECT_PLAYER);
        return;
    }

    ResurrectPlayer(0.0f, false);

    if (GetMaxHealth() > m_resurrectHealth)
        SetHealth(m_resurrectHealth);
    else
        SetHealth(GetMaxHealth());

    if (GetMaxPower(POWER_MANA) > m_resurrectMana)
        SetPower(POWER_MANA, m_resurrectMana);
    else
        SetPower(POWER_MANA, GetMaxPower(POWER_MANA));

    SetPower(POWER_RAGE, 0);

    SetPower(POWER_ENERGY, GetMaxPower(POWER_ENERGY));

    SpawnCorpseBones();
}

void Player::SetClientControl(Unit* target, uint8 allowMove)
{
#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_8_4
    WorldPacket data(SMSG_CLIENT_CONTROL_UPDATE, target->GetPackGUID().size() + 1);
    data << target->GetPackGUID();
    data << uint8(allowMove);
    GetSession()->SendPacket(&data);
#endif
}

bool Player::HasSelfMovementControl() const
{
    // Using Mind Vision
    if (GetUInt64Value(PLAYER_FARSIGHT))
        return false;

    // Using Far Sight
    if (m_longSightSpell)
        return false;

    if (HasUnitState(UNIT_STAT_LOST_CONTROL | UNIT_STAT_CONFUSED | UNIT_STAT_TAXI_FLIGHT))
        return false;

    return true;
}

bool Player::IsAllowedToMove(Unit* unit) const
{
    if (unit == this)
        return !HasUnitState(UNIT_STAT_POSSESSED | UNIT_STAT_FLEEING | UNIT_FLAG_CONFUSED);
    return !unit->HasUnitState(UNIT_STAT_FLEEING | UNIT_FLAG_CONFUSED);
}

void Player::UpdateZoneDependentAuras()
{
    // Some spells applied at enter into zone (with subzones), aura removed in UpdateAreaDependentAuras that called always at zone->area update
    SpellAreaForAreaMapBounds saBounds = sSpellMgr.GetSpellAreaForAreaMapBounds(m_zoneUpdateId);
    for (SpellAreaForAreaMap::const_iterator itr = saBounds.first; itr != saBounds.second; ++itr)
        if (itr->second->autocast && itr->second->IsFitToRequirements(this, m_zoneUpdateId, 0))
            if (!HasAura(itr->second->spellId, EFFECT_INDEX_0))
                CastSpell(this, itr->second->spellId, true);
}

void Player::UpdateAreaDependentAuras()
{
    // remove auras from spells with area limitations
    for (SpellAuraHolderMap::iterator iter = m_spellAuraHolders.begin(); iter != m_spellAuraHolders.end();)
    {
        // use m_zoneUpdateId for speed: UpdateArea called from UpdateZone or instead UpdateZone in both cases m_zoneUpdateId up-to-date
        if (sSpellMgr.GetSpellAllowedInLocationError(iter->second->GetSpellProto(), m_zoneUpdateId, m_areaUpdateId, this) != SPELL_CAST_OK)
        {
            RemoveSpellAuraHolder(iter->second);
            iter = m_spellAuraHolders.begin();
        }
        else
            ++iter;
    }

    // some auras applied at subzone enter
    SpellAreaForAreaMapBounds saBounds = sSpellMgr.GetSpellAreaForAreaMapBounds(m_areaUpdateId);
    for (SpellAreaForAreaMap::const_iterator itr = saBounds.first; itr != saBounds.second; ++itr)
        if (itr->second->autocast && itr->second->IsFitToRequirements(this, m_zoneUpdateId, m_areaUpdateId))
            if (!HasAura(itr->second->spellId, EFFECT_INDEX_0))
                CastSpell(this, itr->second->spellId, true);
}

uint32 Player::GetCorpseReclaimDelay(bool pvp) const
{
    if ((pvp && !sWorld.getConfig(CONFIG_BOOL_DEATH_CORPSE_RECLAIM_DELAY_PVP)) ||
            (!pvp && !sWorld.getConfig(CONFIG_BOOL_DEATH_CORPSE_RECLAIM_DELAY_PVE)))
        return copseReclaimDelay[0];

    time_t now = time(nullptr);
    // 0..2 full period
    uint32 count = (now < m_deathExpireTime) ? uint32((m_deathExpireTime - now) / DEATH_EXPIRE_STEP) : 0;
    if (count >= 2)
        count = 2;
    return copseReclaimDelay[count];
}

void Player::UpdateCorpseReclaimDelay()
{
    bool pvp = m_ExtraFlags & PLAYER_EXTRA_PVP_DEATH;

    if ((pvp && !sWorld.getConfig(CONFIG_BOOL_DEATH_CORPSE_RECLAIM_DELAY_PVP)) ||
            (!pvp && !sWorld.getConfig(CONFIG_BOOL_DEATH_CORPSE_RECLAIM_DELAY_PVE)))
        return;

    time_t now = time(nullptr);
    if (now < m_deathExpireTime)
    {
        // full and partly periods 1..3
        uint32 count = uint32((m_deathExpireTime - now) / DEATH_EXPIRE_STEP + 1);
        if (count < MAX_DEATH_COUNT)
            m_deathExpireTime = now + (count + 1) * DEATH_EXPIRE_STEP;
        else
            m_deathExpireTime = now + MAX_DEATH_COUNT * DEATH_EXPIRE_STEP;
    }
    else
        m_deathExpireTime = now + DEATH_EXPIRE_STEP;
}

void Player::SendCorpseReclaimDelay(bool load) const
{
    Corpse* corpse = GetCorpse();
    if (!corpse)
        return;

    uint32 delay;
    if (load)
    {
        if (corpse->GetGhostTime() > m_deathExpireTime)
            return;

        bool pvp = corpse->GetType() == CORPSE_RESURRECTABLE_PVP;

        uint32 count;
        if ((pvp && sWorld.getConfig(CONFIG_BOOL_DEATH_CORPSE_RECLAIM_DELAY_PVP)) ||
                (!pvp && sWorld.getConfig(CONFIG_BOOL_DEATH_CORPSE_RECLAIM_DELAY_PVE)))
        {
            count = uint32(m_deathExpireTime - corpse->GetGhostTime()) / DEATH_EXPIRE_STEP;
            if (count >= MAX_DEATH_COUNT)
                count = MAX_DEATH_COUNT - 1;
        }
        else
            count = 0;

        time_t expected_time = corpse->GetGhostTime() + copseReclaimDelay[count];

        time_t now = time(nullptr);
        if (now >= expected_time)
            return;

        delay = uint32(expected_time - now);
    }
    else
        delay = GetCorpseReclaimDelay(corpse->GetType() == CORPSE_RESURRECTABLE_PVP);

    //! corpse reclaim delay 30 * 1000ms or longer at often deaths
    WorldPacket data(SMSG_CORPSE_RECLAIM_DELAY, 4);
    data << uint32(delay * IN_MILLISECONDS);
    GetSession()->SendPacket(&data);
}

Player* Player::GetNextRandomRaidMember(float radius)
{
    Group* pGroup = GetGroup();
    if (!pGroup)
        return nullptr;

    std::vector<Player*> nearMembers;
    nearMembers.reserve(pGroup->GetMembersCount());

    for (GroupReference* itr = pGroup->GetFirstMember(); itr != nullptr; itr = itr->next())
    {
        Player* Target = itr->getSource();

        // IsHostileTo check duel and controlled by enemy
        if (Target && Target != this && IsWithinDistInMap(Target, radius) &&
                !Target->HasInvisibilityAura() && !IsHostileTo(Target))
            nearMembers.push_back(Target);
    }

    if (nearMembers.empty())
        return nullptr;

    uint32 randTarget = urand(0, nearMembers.size() - 1);
    return nearMembers[randTarget];
}

PartyResult Player::CanUninviteFromGroup(ObjectGuid uninvitedGuid) const
{
    Group const* grp = GetGroup();
    if (!grp)
        return ERR_NOT_IN_GROUP;

    if (grp->GetLeaderGuid() == uninvitedGuid) // prevent assists kicking leader
        return ERR_NOT_LEADER;

    if (!grp->IsLeader(GetObjectGuid()) && !grp->IsAssistant(GetObjectGuid()))
        return ERR_NOT_LEADER;

    if (InBattleGround())
        return ERR_INTERNAL_BATTLEGROUND;

    return ERR_PARTY_RESULT_OK;
}

void Player::UpdateGroupLeaderFlag(bool const remove /*= false*/)
{
    Group const* group = GetGroup();
    if (HasFlag(PLAYER_FLAGS, PLAYER_FLAGS_GROUP_LEADER))
    {
        if (remove || !group || group->GetLeaderGuid() != GetObjectGuid())
            RemoveFlag(PLAYER_FLAGS, PLAYER_FLAGS_GROUP_LEADER);
    }
    else if (!remove && group && group->GetLeaderGuid() == GetObjectGuid())
        SetFlag(PLAYER_FLAGS, PLAYER_FLAGS_GROUP_LEADER);
}

void Player::SetBattleGroundRaid(Group* group, int8 subgroup)
{
    //we must move references from m_group to m_originalGroup
    SetOriginalGroup(GetGroup(), GetSubGroup());

    m_group.unlink();
    m_group.link(group, this);
    m_group.setSubGroup((uint8)subgroup);
}

void Player::RemoveFromBattleGroundRaid()
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
        // never use SetOriginalGroup without a subgroup unless you specify nullptr for group
        ASSERT(subgroup >= 0);
        m_originalGroup.link(group, this);
        m_originalGroup.setSubGroup((uint8)subgroup);
    }
}

void Player::UpdateTerainEnvironmentFlags()
{
    Map* m = GetMap();
    float x, y, z;
    GetPosition(x, y, z);

    GridMapLiquidData liquid_status;
    GridMapLiquidStatus res = m->GetTerrain()->getLiquidStatus(x, y, z, MAP_ALL_LIQUIDS, &liquid_status);
    if (!res)
    {
        SetEnvironmentFlags(ENVIRONMENT_MASK_LIQUID_FLAGS, false);
        if (m_lastLiquid && m_lastLiquid->SpellId)
            RemoveAurasDueToSpell(m_lastLiquid->SpellId);
        m_lastLiquid = nullptr;
        return;
    }

    // Environment has liquid information
    SetEnvironmentFlags(ENVIRONMENT_FLAG_LIQUID, true);

    if (uint32 liqEntry = liquid_status.entry)
    {
        LiquidTypeEntry const* liquid = sTerrainMgr.GetLiquidType(liqEntry);
        if (m_lastLiquid && m_lastLiquid->SpellId && m_lastLiquid->Id != liqEntry)
            RemoveAurasDueToSpell(m_lastLiquid->SpellId);

        if (liquid && liquid->SpellId)
        {
            if (res & (LIQUID_MAP_UNDER_WATER | LIQUID_MAP_IN_WATER))
            {
                if (!HasAura(liquid->SpellId))
                    CastSpell(this, liquid->SpellId, true);
            }
            else
                RemoveAurasDueToSpell(liquid->SpellId);
        }

        m_lastLiquid = liquid;
    }
    else if (m_lastLiquid && m_lastLiquid->SpellId)
    {
        RemoveAurasDueToSpell(m_lastLiquid->SpellId);
        m_lastLiquid = nullptr;
    }

    // All liquid types: check under surface level
    if (liquid_status.type_flags & (MAP_LIQUID_TYPE_WATER | MAP_LIQUID_TYPE_OCEAN | MAP_LIQUID_TYPE_MAGMA | MAP_LIQUID_TYPE_SLIME))
        SetEnvironmentFlags(ENVIRONMENT_FLAG_UNDERWATER, (res & LIQUID_MAP_UNDER_WATER));

    // In water: on or under surface level
    if (liquid_status.type_flags & (MAP_LIQUID_TYPE_WATER | MAP_LIQUID_TYPE_OCEAN))
        SetEnvironmentFlags(ENVIRONMENT_FLAG_IN_WATER, (res & (LIQUID_MAP_UNDER_WATER | LIQUID_MAP_IN_WATER)));

    // In magma: on, under, or slightly above surface level
    if (liquid_status.type_flags & MAP_LIQUID_TYPE_MAGMA)
        SetEnvironmentFlags(ENVIRONMENT_FLAG_IN_MAGMA, (res & (LIQUID_MAP_UNDER_WATER | LIQUID_MAP_IN_WATER | LIQUID_MAP_WATER_WALK)));

    // In slime: on, under, or slightly above surface level
    if (liquid_status.type_flags & MAP_LIQUID_TYPE_SLIME)
        SetEnvironmentFlags(ENVIRONMENT_FLAG_IN_SLIME, (res & (LIQUID_MAP_UNDER_WATER | LIQUID_MAP_IN_WATER | LIQUID_MAP_WATER_WALK)));

    // In deep water: on, under, above surface level
    SetEnvironmentFlags(ENVIRONMENT_FLAG_HIGH_SEA, (liquid_status.type_flags & MAP_LIQUID_TYPE_DEEP_WATER));

    // All liquid types: check if deep enough level for swimming
    SetEnvironmentFlags(ENVIRONMENT_FLAG_HIGH_LIQUID, ((res & (LIQUID_MAP_UNDER_WATER | LIQUID_MAP_IN_WATER)) && liquid_status.level > (liquid_status.depth_level + 1.5f)));
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

bool ItemPosCount::isContainedIn(ItemPosCountVec const& vec) const
{
    for (const auto& itr : vec)
        if (itr.pos == pos)
            return true;

    return false;
}

bool Player::CanUseBattleGroundObject() const
{
    // Spirit of redemption case
    if (GetClass() == CLASS_PRIEST && HasAura(27827))
        return false;
    if (IsGameMaster())
        return false;
    // TODO : some spells gives player ForceReaction to one faction (ReputationMgr::ApplyForceReaction)
    // maybe gameobject code should handle that ForceReaction usage
    return (//InBattleGround() &&                          // in battleground - not need, check in other cases
               !IsMounted() &&
               //player cannot use object when he is invulnerable (immune)
               !IsTotalImmune() &&                            // not totally immune
               //i'm not sure if these two are correct, because invisible players should get visible when they click on flag
               //!HasStealthAura() &&                           // not stealthed
               //!HasInvisibilityAura() &&                      // not invisible
               IsAlive() &&                                   // live player
               !HasUnitState(UNIT_STAT_CAN_NOT_REACT_OR_LOST_CONTROL)  // Nostalrius : en cecite ou fear par exemple
           );
}

bool Player::IsTotalImmune() const
{
    AuraList const& immune = GetAurasByType(SPELL_AURA_SCHOOL_IMMUNITY);

    uint32 immuneMask = 0;
    for (const auto itr : immune)
    {
        immuneMask |= itr->GetModifier()->m_miscvalue;
    }

    return (immuneMask == SPELL_SCHOOL_MASK_ALL);
}

void Player::AutoStoreLoot(Loot& loot, bool broadcast, uint8 bag, uint8 slot)
{
    uint32 max_slot = loot.GetMaxSlotInLootFor(GetGUIDLow());
    for (uint32 i = 0; i < max_slot; ++i)
    {
        LootItem* lootItem = loot.LootItemInSlot(i, GetGUIDLow());
        // Don't bypass conditions
        if (lootItem->conditionId && !lootItem->AllowedForPlayer(this, loot.GetLootTarget()))
            continue;

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

        SendNotifyLootItemRemoved(i);
        Item* pItem = StoreNewItem(dest, lootItem->itemid, true, lootItem->randomPropertyId);
        SendNewItem(pItem, lootItem->count, false, false, broadcast);
    }
}

uint32 Player::CalculateTalentsPoints() const
{
    uint32 talentPointsForLevel = GetLevel() < 10 ? 0 : GetLevel() - 9;
    return uint32(talentPointsForLevel * sWorld.getConfig(CONFIG_FLOAT_RATE_TALENT));
}

struct DoPlayerLearnSpell
{
    DoPlayerLearnSpell(Player& _player) : player(_player) {}
    void operator()(uint32 spellId)
    {
        player.LearnSpell(spellId, false);
    }
    Player& player;
};

void Player::LearnSpellHighRank(uint32 spellid)
{
    LearnSpell(spellid, false);

    DoPlayerLearnSpell worker(*this);
    sSpellMgr.doForHighRanks(spellid, worker);
}

void Player::_LoadSkills(QueryResult* result)
{
    //                                                           0      1      2
    // SetPQuery(PLAYER_LOGIN_QUERY_LOADSKILLS,          "SELECT skill, value, max FROM character_skills WHERE guid = '%u'", GUID_LOPART(m_guid));

    uint32 count = 0;
    if (result)
    {
        do
        {
            Field* fields = result->Fetch();

            uint16 skill    = fields[0].GetUInt16();
            uint16 value    = fields[1].GetUInt16();
            uint16 max      = fields[2].GetUInt16();

            SkillLineEntry const* pSkill = sSkillLineStore.LookupEntry(skill);
            if (!pSkill)
            {
                sLog.outError("Character %u has skill %u that does not exist.", GetGUIDLow(), skill);
                continue;
            }

            // set fixed skill ranges
            switch (GetSkillRangeType(pSkill, false))
            {
                case SKILL_RANGE_LANGUAGE:                      // 300..300
                    value = max = 300;
                    break;
                case SKILL_RANGE_MONO:                          // 1..1, grey monolite bar
                    value = max = 1;
                    break;
                default:
                    break;
            }

            if (value == 0)
            {
                sLog.outError("Character %u has skill %u with value 0. Will be deleted.", GetGUIDLow(), skill);
                CharacterDatabase.PExecute("DELETE FROM `character_skills` WHERE `guid` = '%u' AND `skill` = '%u' ", GetGUIDLow(), skill);
                continue;
            }

            SetUInt32Value(PLAYER_SKILL_INDEX(count), skill);
            SetUInt32Value(PLAYER_SKILL_VALUE_INDEX(count), MAKE_SKILL_VALUE(value, max));
            SetUInt32Value(PLAYER_SKILL_BONUS_INDEX(count), 0);

            mSkillStatus.insert(SkillStatusMap::value_type(skill, SkillStatusData(count, SKILL_UNCHANGED)));
            UpdateSkillTrainedSpells(skill, value);

            ++count;

            if (count >= PLAYER_MAX_SKILLS)                     // client limit
            {
                sLog.outError("Character %u has more than %u skills.", GetGUIDLow(), PLAYER_MAX_SKILLS);
                break;
            }
        }
        while (result->NextRow());
    }

    for (; count < PLAYER_MAX_SKILLS; ++count)
    {
        SetUInt32Value(PLAYER_SKILL_INDEX(count), 0);
        SetUInt32Value(PLAYER_SKILL_VALUE_INDEX(count), 0);
        SetUInt32Value(PLAYER_SKILL_BONUS_INDEX(count), 0);
    }
}

#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_10_2
void Player::_LoadForgottenSkills(QueryResult* result)
{
    //                                                                 0      1
    // SetPQuery(PLAYER_LOGIN_QUERY_FORGOTTEN_SKILLS,          "SELECT skill, value FROM character_forgotten_skills WHERE guid = '%u'", GUID_LOPART(m_guid));

    if (result)
    {
        do
        {
            Field* fields = result->Fetch();

            uint16 skill    = fields[0].GetUInt16();
            uint16 value    = fields[1].GetUInt16();

            SkillLineEntry const* pSkill = sSkillLineStore.LookupEntry(skill);
            if (!pSkill)
            {
                sLog.outError("Character %u has saved value for forgotten skill %u that does not exist.", GetGUIDLow(), skill);
                continue;
            }

            if (pSkill->categoryId != SKILL_CATEGORY_WEAPON)
            {
                sLog.outError("Character %u has saved value for forgotten skill %u that is not a weapon skill.", GetGUIDLow(), skill);
                continue;
            }

            m_mForgottenSkills.insert(std::make_pair(skill, value));
        }
        while (result->NextRow());
    }
}
#endif

void Player::LoadSkillsFromFields()
{
    for (uint8 i = 0; i < PLAYER_MAX_SKILLS; ++i)
    {
        if (uint16 skill = PAIR32_LOPART(GetUInt32Value(PLAYER_SKILL_INDEX(i))))
        {
            mSkillStatus.insert(SkillStatusMap::value_type(skill, SkillStatusData(i, SKILL_UNCHANGED)));
            UpdateSkillTrainedSpells(skill, SKILL_VALUE(GetUInt32Value(PLAYER_SKILL_VALUE_INDEX(i))));
        }
    }
}

InventoryResult Player::CanEquipUniqueItem(Item* pItem, uint8 eslot) const
{
    ItemPrototype const* pProto = pItem->GetProto();

    // proto based limitations
    if (InventoryResult res = CanEquipUniqueItem(pProto, eslot))
        return res;

    return EQUIP_ERR_OK;
}

InventoryResult Player::CanEquipUniqueItem(ItemPrototype const* itemProto, uint8 except_slot) const
{
    // check unique-equipped on item
    if (itemProto->Flags & ITEM_FLAG_UNIQUE_EQUIPPED)
    {
        // there is an equip limit on this item
        if (HasItemWithIdEquipped(itemProto->ItemId, 1, except_slot))
            return EQUIP_ERR_ITEM_CANT_BE_EQUIPPED;
    }

    return EQUIP_ERR_OK;
}

void Player::HandleFall(MovementInfo const& movementInfo)
{
    // calculate total z distance of the fall
    float z_diff = m_lastFallZ - movementInfo.GetPos().z;
    DEBUG_LOG("zDiff = %f", z_diff);

    //Players with low fall distance, Feather Fall or physical immunity (charges used) are ignored
    // 14.57 can be calculated by resolving damageperc formula below to 0
    if (z_diff >= 14.57f && !IsDead() && !IsGameMaster() &&
            !HasAuraType(SPELL_AURA_HOVER) && !HasAuraType(SPELL_AURA_FEATHER_FALL) &&
            !IsImmuneToDamage(SPELL_SCHOOL_MASK_NORMAL))
    {
        //Safe fall, fall height reduction
        int32 safe_fall = GetTotalAuraModifier(SPELL_AURA_SAFE_FALL);

        float damageperc = 0.018f * (z_diff - safe_fall) - 0.2426f;

        if (damageperc > 0)
        {
            float TakenTotalMod = 1.0f;
            TakenTotalMod *= GetTotalAuraMultiplierByMiscMask(SPELL_AURA_MOD_DAMAGE_PERCENT_TAKEN, SPELL_SCHOOL_MASK_NORMAL);

            uint32 damage = (uint32)(damageperc * GetMaxHealth() * sWorld.getConfig(CONFIG_FLOAT_RATE_DAMAGE_FALL) * TakenTotalMod);

            float height = movementInfo.GetPos().z;
            UpdateAllowedPositionZ(movementInfo.GetPos().x, movementInfo.GetPos().y, height);

            if (damage > 0)
            {
                //Prevent fall damage from being more than the player maximum health
                if (damage > GetMaxHealth())
                    damage = GetMaxHealth();

                EnvironmentalDamage(DAMAGE_FALL, damage);
            }

            //Z given by moveinfo, LastZ, FallTime, WaterZ, MapZ, Damage, Safefall reduction
            DEBUG_LOG("FALLDAMAGE z=%f sz=%f pZ=%f FallTime=%d mZ=%f damage=%d SF=%d" , movementInfo.GetPos().z, height, GetPositionZ(), movementInfo.GetFallTime(), height, damage, safe_fall);
        }
    }
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

    // find current max talent rank
    uint32 curtalent_maxrank = 0;
    for (int32 k = MAX_TALENT_RANK - 1; k > -1; --k)
    {
        if (talentInfo->RankID[k] && HasSpell(talentInfo->RankID[k]))
        {
            curtalent_maxrank = k + 1;
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
            for (int i = talentInfo->DependsOnRank; i < MAX_TALENT_RANK; ++i)
            {
                if (depTalentInfo->RankID[i] != 0)
                    if (HasSpell(depTalentInfo->RankID[i]))
                        hasEnoughRank = true;
            }

            if (!hasEnoughRank)
                return;
        }
    }

    // Check if it requires spell
    if (talentInfo->DependsOnSpell && !HasSpell(talentInfo->DependsOnSpell))
        return;

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
                    for (int j = 0; j < MAX_TALENT_RANK; ++j)
                    {
                        if (tmpTalent->RankID[j] != 0)
                        {
                            if (HasSpell(tmpTalent->RankID[j]))
                                spentPoints += j + 1;
                        }
                    }
                }
            }
        }
    }

    // not have required min points spent in talent tree
    if (spentPoints < (talentInfo->Row * MAX_TALENT_RANK))
        return;

    // spell not set in talent.dbc
    uint32 spellid = talentInfo->RankID[talentRank];
    if (spellid == 0)
    {
        sLog.outError("Talent.dbc have for talent: %u Rank: %u spell id = 0", talentId, talentRank);
        return;
    }

    // already known
    if (HasSpell(spellid))
        return;

    // learn! (other talent ranks will unlearned at learning)
    LearnSpell(spellid, false, true);
    DETAIL_LOG("TalentID: %u Rank: %u Spell: %u\n", talentId, talentRank, spellid);
}

void Player::UpdateFallInformationIfNeed(MovementInfo const& minfo, uint16 opcode)
{
    if (m_lastFallTime >= minfo.GetFallTime() || m_lastFallZ <= minfo.GetPos().z || opcode == MSG_MOVE_FALL_LAND)
        SetFallInformation(minfo.GetFallTime(), minfo.GetPos().z);
}

/**
 * FallMode = 0 implies that the player is dying, or already dead, and the proper death state will be set.
 *          = 1 simply causes the player to plummet towards the ground, and not suffer any damage.
 *          = 2 causes the player to plummet towards the ground, and causes falling damage, regardless
 *              of any auras that might of prevented fall damage.
 */
bool Player::FallGround(uint8 FallMode)
{
    // Let's abort after we called this function one time
    if (GetDeathState() == CORPSE_FALLING && FallMode == 0)
        return false;

    float x, y, z;
    GetPosition(x, y, z);
    float ground_Z = GetMap()->GetHeight(x, y, true);
    if (ground_Z > INVALID_HEIGHT)
        ground_Z = z;

    float z_diff = 0.0f;
    if ((z_diff = fabs(ground_Z - z)) < 0.1f)
        return false;


    // Below formula for falling damage is from Player::HandleFall
    if (FallMode == 2 && z_diff >= 14.57f)
    {
        uint32 damage = std::min(GetMaxHealth(), (uint32)((0.018f * z_diff - 0.2426f) * GetMaxHealth()));
        if (damage > 0) EnvironmentalDamage(DAMAGE_FALL, damage);
    }
    else if (FallMode == 0)
        Unit::SetDeathState(CORPSE_FALLING);
    return true;
}

void Player::UnsummonPetTemporaryIfAny()
{
    Pet* pet = GetPet();
    if (!pet)
        return;

    if (!m_temporaryUnsummonedPetNumber && pet->isControlled() && !pet->isTemporarySummoned())
        m_temporaryUnsummonedPetNumber = pet->GetCharmInfo()->GetPetNumber();

    pet->Unsummon(PET_SAVE_AS_CURRENT, this);
}

void Player::ResummonPetTemporaryUnSummonedIfAny()
{
    if (!m_temporaryUnsummonedPetNumber)
        return;

    // not resummon in not appropriate state
    if (IsPetNeedBeTemporaryUnsummoned())
        return;

    if (GetPetGuid())
        return;

    Pet* NewPet = new Pet;
    if (!NewPet->LoadPetFromDB(this, 0, m_temporaryUnsummonedPetNumber, true))
        delete NewPet;

    m_temporaryUnsummonedPetNumber = 0;
}

void Player::_SaveBGData()
{
    // nothing save
    if (!m_bgData.m_needSave)
        return;

    static SqlStatementID delBGData ;
    static SqlStatementID insBGData ;

    SqlStatement stmt =  CharacterDatabase.CreateStatement(delBGData, "DELETE FROM `character_battleground_data` WHERE `guid` = ?");

    stmt.PExecute(GetGUIDLow());

    if (m_bgData.bgInstanceID || InBattleGroundQueue())
    {
        stmt = CharacterDatabase.CreateStatement(insBGData, "INSERT INTO `character_battleground_data` VALUES (?, ?, ?, ?, ?, ?, ?, ?)");
        /* guid, bgInstanceID, bgTeam, x, y, z, o, map */
        stmt.addUInt32(GetGUIDLow());
        stmt.addUInt32(m_bgData.bgInstanceID);
        stmt.addUInt32(uint32(m_bgData.bgTeam));
        stmt.addFloat(m_bgData.joinPos.x);
        stmt.addFloat(m_bgData.joinPos.y);
        stmt.addFloat(m_bgData.joinPos.z);
        stmt.addFloat(m_bgData.joinPos.o);
        stmt.addUInt32(m_bgData.joinPos.mapId);

        stmt.Execute();
    }

    m_bgData.m_needSave = false;
}

void Player::RemoveAtLoginFlag(AtLoginFlags f, bool in_db_also /*= false*/)
{
    m_atLoginFlags &= ~f;

    if (in_db_also)
        CharacterDatabase.PExecute("UPDATE `characters` SET `at_login_flags` = `at_login_flags` & ~ %u WHERE `guid` ='%u'", uint32(f), GetGUIDLow());
}

void Player::SendClearCooldown(uint32 spellId, Unit* target) const
{
    WorldPacket data(SMSG_CLEAR_COOLDOWN, 4 + 8);
    data << uint32(spellId);
    data << target->GetObjectGuid();
    SendDirectMessage(&data);
}

void Player::SendClearAllCooldowns(Unit* target) const
{
    WorldPacket data(SMSG_COOLDOWN_CHEAT, 8);
    data << target->GetObjectGuid();
    SendDirectMessage(&data);
}

void Player::SendSpellCooldown(uint32 spellId, uint32 cooldown, ObjectGuid target) const
{
    WorldPacket data(SMSG_SPELL_COOLDOWN, 8 + 4 + 4);
    data << target;
    data << uint32(spellId);
    data << uint32(cooldown);
    GetSession()->SendPacket(&data);
}

void Player::SendSpellRemoved(uint32 spellId) const
{
    WorldPacket data(SMSG_REMOVED_SPELL, 4);
    data << uint16(spellId);
    GetSession()->SendPacket(&data);
}

bool Player::HasMovementFlag(MovementFlags f) const
{
    return m_movementInfo.HasMovementFlag(f);
}

void Player::SetHomebindToLocation(WorldLocation const& loc, uint32 area_id)
{
    m_homebindMapId = loc.mapId;
    m_homebindAreaId = area_id;
    m_homebindX = loc.x;
    m_homebindY = loc.y;
    m_homebindZ = loc.z;

    // update sql homebind
    CharacterDatabase.PExecute("UPDATE `character_homebind` SET `map` = '%u', `zone` = '%u', `position_x` = '%f', `position_y` = '%f', `position_z` = '%f' WHERE `guid` = '%u'",
                               m_homebindMapId, m_homebindAreaId, m_homebindX, m_homebindY, m_homebindZ, GetGUIDLow());
}

bool Player::TeleportToHomebind(uint32 options, bool hearthCooldown) 
{
    UpdatePvPContested(false, true);
    if (hearthCooldown)
    {
        // Initiate hearthstone cooldown
        SpellEntry const* spellInfo = sSpellMgr.GetSpellEntry(8690);
        ItemPrototype const* itemProto = sObjectMgr.GetItemPrototype(6948);
        AddCooldown(*spellInfo, itemProto);
    }
    return TeleportTo(m_homebindMapId, m_homebindX, m_homebindY, m_homebindZ, GetOrientation(), (options | TELE_TO_FORCE_MAP_CHANGE));
}

Object* Player::GetObjectByTypeMask(ObjectGuid guid, TypeMask typemask)
{
    switch (guid.GetHigh())
    {
        case HIGHGUID_ITEM:
            if (typemask & TYPEMASK_ITEM)
                return GetItemByGuid(guid);
            break;
        case HIGHGUID_PLAYER:
            if (GetObjectGuid() == guid)
                return this;
            if ((typemask & TYPEMASK_PLAYER) && IsInWorld())
                return ObjectAccessor::FindPlayer(guid);
            break;
        case HIGHGUID_TRANSPORT:
        case HIGHGUID_GAMEOBJECT:
            if ((typemask & TYPEMASK_GAMEOBJECT) && IsInWorld())
                return GetMap()->GetGameObject(guid);
            break;
        case HIGHGUID_UNIT:
            if ((typemask & TYPEMASK_UNIT) && IsInWorld())
                return GetMap()->GetCreature(guid);
            break;
        case HIGHGUID_PET:
            if ((typemask & TYPEMASK_UNIT) && IsInWorld())
                return GetMap()->GetPet(guid);
            break;
        case HIGHGUID_DYNAMICOBJECT:
            if ((typemask & TYPEMASK_DYNAMICOBJECT) && IsInWorld())
                return GetMap()->GetDynamicObject(guid);
            break;
        case HIGHGUID_CORPSE:
        case HIGHGUID_MO_TRANSPORT:
            break;
    }

    return nullptr;
}

void Player::SetRestType(RestType n_r_type, uint32 areaTriggerId /*= 0*/)
{
    m_restType = n_r_type;
    if (m_restType == REST_TYPE_NO)
    {
        RemoveFlag(PLAYER_FLAGS, PLAYER_FLAGS_RESTING);

        // Set player to FFA PVP when not in rested environment.
        if (sWorld.IsFFAPvPRealm())
            SetFFAPvP(true);
    }
    else
    {
        if (GetLevel() < sWorld.getConfig(CONFIG_UINT32_MAX_PLAYER_LEVEL) && m_timeInnEnter == 0 || time(nullptr) - m_timeInnEnter > 180)
            SetByteValue(PLAYER_BYTES_2, 3, REST_STATE_RESTED);

        SetFlag(PLAYER_FLAGS, PLAYER_FLAGS_RESTING);

        m_innTriggerId = areaTriggerId;
        m_timeInnEnter = time(nullptr);

        if (sWorld.IsFFAPvPRealm())
            SetFFAPvP(false);
    }
}

void Player::SendDuelCountdown(uint32 counter) const
{
    WorldPacket data(SMSG_DUEL_COUNTDOWN, 4);
    data << uint32(counter);                                // seconds
    GetSession()->SendPacket(&data);
}

void Player::RemoveAI()
{
    if (i_AI)
        i_AI->Remove();
}

void Player::RemoveTemporaryAI()
{
    PlayerBotEntry* pBot = GetSession()->GetBot();

    if (!pBot || (pBot->ai != AI()))
        RemoveAI();

    if (pBot && (pBot->ai != AI()))
        SetAI(pBot->ai);
}

void Player::SetControlledBy(Unit* pWho)
{
    if (i_AI)
    {
        PlayerBotEntry* pBot = GetSession()->GetBot();

        // Careful not to delete bot ai
        if (!pBot || (pBot->ai != i_AI))
            delete i_AI;

        i_AI = nullptr;
    }
    i_AI = new PlayerControlledAI(this, pWho);
}

#define CHANGERACE_LOG(format, ...) sLog.outString("[RaceChanger/Log] " format, ##__VA_ARGS__)
#define CHANGERACE_ERR(format, ...) sLog.outError("[RaceChanger/Err] " format, ##__VA_ARGS__)

bool Player::ChangeRace(uint8 newRace)
{
    PlayerInfo const* info = sObjectMgr.GetPlayerInfo(newRace, GetClass());
    if (!info)
        return false;

    uint8 oldRace = GetRace();
    bool bChangeTeam = (TeamForRace(oldRace) != TeamForRace(newRace));

    m_DbSaveDisabled = true;
    if (!ChangeSpellsForRace(oldRace, newRace))
    {
        CHANGERACE_ERR("Impossible de changer les spells.");
        return false;
    }

    // Le chanegement de race en lui meme.
    SetByteValue(UNIT_FIELD_BYTES_0, UNIT_BYTES_0_OFFSET_RACE, newRace);
    LearnDefaultSpells();

    SetFactionForRace(newRace);

    if (!ChangeReputationsForRace(oldRace, newRace))
    {
        CHANGERACE_ERR("Impossible de changer les reputations.");
        return false;
    }
    if (!ChangeQuestsForRace(oldRace, newRace))
    {
        CHANGERACE_ERR("Impossible de changer les quetes.");
        return false;
    }
    if (!ChangeItemsForRace(oldRace, newRace))
    {
        CHANGERACE_ERR("Impossible de changer les items.");
        return false;
    }
    /*
    On sauvegarde le changement de faction, et apres faut deco-reco.
    */
    m_DbSaveDisabled = false;
    // Suppression des montures mises
    RemoveSpellsCausingAura(SPELL_AURA_MOUNTED);
    SaveToDB();
    m_DbSaveDisabled = true;
    if (bChangeTeam)
    {
        // Changement de HomeBind / Teleportation capitale
        if (TeamForRace(newRace) == ALLIANCE)
        {
            SavePositionInDB(GetObjectGuid(), 0, -8867.68f, 673.373f, 97.9034f, 0.0f, 1519);
            SetHomebindToLocation(WorldLocation(0, -8867.68f, 673.373f, 97.9034f, 0.0f), 1519);
        }
        else
        {
            SavePositionInDB(GetObjectGuid(), 1, 1633.33f, -4439.11f, 15.7588f, 0.0f, 1637);
            SetHomebindToLocation(WorldLocation(1, 1633.33f, -4439.11f, 15.7588f, 0.0f), 1637);
        }
    }
    // Sauvegarde dans ObjectMgr aussi (sinon mauvaise faction prise en compte dans la distrib PvP)
    if (PlayerCacheData* data = sObjectMgr.GetPlayerDataByGUID(GetGUIDLow()))
        data->uiRace = newRace;

    m_session->LogoutPlayer(false);
    return true;
}

uint32 GetPriestSpellForRace(uint8 race)
{
    switch (race)
    {
        case RACE_HUMAN:
            return 19243; // Priere de desespoir
        case RACE_UNDEAD:
            return 19280; // Peste devorante
        case RACE_DWARF:
            return 6346; // Gardien de peur
        case RACE_NIGHTELF:
            return 2651; // Grace d'Elune
        default:
            return 0;
    }
}

uint32 GetCapitalReputationForRace(uint8 race)
{
    switch (race)
    {
        case RACE_HUMAN:
            return 72; // Hurlevent
        case RACE_TROLL:
        case RACE_ORC:
            return 76; // Orgrimmar
        case RACE_DWARF:
        case RACE_GNOME:
            return 47; // Ironforge
        case RACE_NIGHTELF:
            return 69; // Darnassus
        case RACE_UNDEAD:
            return 68; // Undercity
        case RACE_TAUREN:
            return 81; // Thunder Bluff

        default:
            return 0;
    }
}

bool Player::ConvertSpell(uint32 oldSpellId, uint32 newSpellId)
{
    // Conversion des boutons d'actions
    ActionButtonList& actions = GetSession()->GetMasterPlayer()->GetActionButtons();
    for (auto& action : actions)
    {
        if (action.second.uState == ACTIONBUTTON_DELETED)
            continue;
        if (action.second.GetType() != ACTION_BUTTON_SPELL || action.second.GetAction() != oldSpellId)
            continue;
        if (newSpellId > 0) // Changer le bouton
            action.second.SetActionAndType(newSpellId, ACTION_BUTTON_SPELL);
        else // Sinon le supprimer
            action.second.uState = ACTIONBUTTON_DELETED;
    }
    // Le sort en lui meme
    PlayerSpellMap::const_iterator mySpells_itr = m_spells.find(oldSpellId);
    if (mySpells_itr != m_spells.end() && mySpells_itr->second.state != PLAYERSPELL_REMOVED)
    {
        CHANGERACE_LOG("Changement sort %u -> %u", oldSpellId, newSpellId);
        RemoveSpell(oldSpellId, false, false);
        if (newSpellId > 0)
            LearnSpell(newSpellId, false);
    }
    //else
    //    CHANGERACE_LOG("N'a pas le sort %u.", oldSpellId);
    return true;
}

bool Player::ChangeSpellsForRace(uint8 oldRace, uint8 newRace)
{
    Team oldTeam = TeamForRace(oldRace);
    // Les classes qui ont des sorts differents
    switch (GetClass())
    {
        case CLASS_PRIEST:
        {
            uint32 uiRemoveSpell = GetPriestSpellForRace(oldRace);
            uint32 newSpell = GetPriestSpellForRace(newRace);
            ConvertSpell(uiRemoveSpell, newSpell);
            break;
        }
    }

    PlayerInfo const* info = sObjectMgr.GetPlayerInfo(oldRace, GetClass());
    ASSERT(info);
    for (const auto spell : info->spell)
    {
        ConvertSpell(spell, 0);
    }
    // Spell conversion
    for (std::map<uint32, uint32>::const_iterator it = sObjectMgr.factionchange_spells.begin(); it != sObjectMgr.factionchange_spells.end(); ++it)
    {
        uint32 myOldSpellId = oldTeam == ALLIANCE ? it->first : it->second;
        uint32 myNewSpellId = oldTeam == ALLIANCE ? it->second : it->first;
        ConvertSpell(myOldSpellId, myNewSpellId);
    }
    CHANGERACE_LOG("Transfert des sorts [OK]");
    return true;
}

bool Player::ChangeItemsForRace(uint8 oldRace, uint8 newRace)
{
    Team newTeam = TeamForRace(newRace);
    // 1- Changement des montures
    for (int i = PLAYER_SLOT_START; i < PLAYER_SLOT_END; ++i)
    {
        // Une monture
        Item* item = GetItemByPos(INVENTORY_SLOT_BAG_0, i);
        if (item && item->GetProto()->Class == ITEM_CLASS_JUNK && item->GetProto()->RequiredSkill == 762)
        {
            Races currMountRace;
            uint8 currRaceNum   = 0;
            if (!sObjectMgr.GetMountDataByEntry(item->GetEntry(), currMountRace, currRaceNum))
            {
                CHANGERACE_ERR("Monture %u non renseignee dans `player_factionchange_mounts`.", item->GetEntry());
                continue;
            }
            // Soit :
            // - monture de mon ancienne race -> Traduire en nouvelle race
            // - monture d'une autre race     -> Traduire en la race opposee
            Races mountNewRace = (currMountRace == oldRace) ? Races(newRace) : sObjectMgr.GetOppositeRace(currMountRace);
            uint32 newMountId = sObjectMgr.GetMountItemEntry(mountNewRace, currRaceNum);
            // Si on trouve pas, une monture aleatoire de la race opposee suffira.
            if (!newMountId)
                newMountId = sObjectMgr.GetRandomMountForRace(mountNewRace);
            // Sinon ben tampis.
            if (!newMountId)
            {
                CHANGERACE_ERR("Pas de monture pour la race %u dans `player_factionchange_mounts` pour transferer %u.", mountNewRace, item->GetEntry());
                continue;
            }
            ItemPrototype const* pNewMountProto  = ObjectMgr::GetItemPrototype(newMountId);
            CHANGERACE_LOG("Changement de la monture %u en %u.", item->GetEntry(), newMountId);
            if (!pNewMountProto || !item->ChangeEntry(pNewMountProto))
            {
                CHANGERACE_ERR("Impossible de changer l'item %u.", item->GetEntry());
                return false;
            }
        }
        //else if (m_items[i])
        //    CHANGERACE_LOG("Item %u pas une monture. Class %u != %u. RequiredSkill = %u", item->GetEntry(), item->GetProto()->Class, ITEM_CLASS_JUNK, m_items[i]->GetProto()->RequiredSkill);
    }

    // 2- Les items a inverser
    for (std::map<uint32, uint32>::const_iterator it = sObjectMgr.factionchange_items.begin(); it != sObjectMgr.factionchange_items.end(); ++it)
    {
        ItemPrototype const* pNewItemProto    = ObjectMgr::GetItemPrototype(newTeam == ALLIANCE ? it->first : it->second);
        if (!pNewItemProto)
            continue;
        uint32 removeItemId = newTeam == ALLIANCE ? it->second : it->first;
        for (int i = PLAYER_SLOT_START; i < PLAYER_SLOT_END; ++i)
        {
            Item* item = GetItemByPos(INVENTORY_SLOT_BAG_0, i);
            if (item && item->GetEntry() == removeItemId)
            {
                CHANGERACE_LOG("Changement item %u -> %u.", removeItemId, pNewItemProto->ItemId);
                if (!item->ChangeEntry(pNewItemProto))
                {
                    CHANGERACE_ERR("Impossible de changer %u en %u.", removeItemId, pNewItemProto->ItemId);
                    return false;
                }
            }
        }
    }

    // 3- Et on regarde finalement si il reste des items non equipables
    //std::map<uint32, uint32> addItems;
    for (int i = PLAYER_SLOT_START; i < PLAYER_SLOT_END; ++i)
    {
        if (Item* pItem = GetItemByPos(INVENTORY_SLOT_BAG_0, i))
        {
            // Item deja gere ? (ObjectMgr)
            bool previouslyHandled = false;
            for (std::map<uint32, uint32>::const_iterator it2 = sObjectMgr.factionchange_items.begin(); it2 != sObjectMgr.factionchange_items.end(); ++it2)
            {
                if ((it2->first == pItem->GetEntry()) || (pItem->GetEntry() == it2->second))
                {
                    previouslyHandled = true;
                    CHANGERACE_LOG("Item %u deja gere.", pItem->GetEntry());
                    break;
                }
            }
            if (previouslyHandled)
                continue;

            ItemPrototype const* pProto = pItem->GetProto();

            bool canEquip = true;
            uint32 raceMask = (1 << (newRace - 1));
            if ((pProto->AllowableRace & raceMask) == 0)
                canEquip = false;
            if (pProto->RequiredHonorRank != 0)
                canEquip = false;

            if (!canEquip)
            {
                CHANGERACE_ERR("Objet %u non gere ! A ajouter dans player_factionchange_items.", pProto->ItemId);
                //DestroyItem(pItem->GetBagSlot(), pItem->GetSlot(), true);
            }
        }
    }
    CHANGERACE_LOG("Changement des items [OK]");
    return true;
}

bool Player::ChangeReputationsForRace(uint8 oldRace, uint8 newRace)
{
    bool changeTeam = (TeamForRace(oldRace) != TeamForRace(newRace));
    uint32 oldRaceMask = 1 << (oldRace - 1);
    uint32 newRaceMask = 1 << (newRace - 1);
    uint32 newCapitalId = GetCapitalReputationForRace(newRace);
    FactionEntry const* oldCapitalFaction = sObjectMgr.GetFactionEntry(GetCapitalReputationForRace(oldRace));
    FactionEntry const* newCapitalFaction = sObjectMgr.GetFactionEntry(newCapitalId);

    if (!newCapitalFaction || !oldCapitalFaction)
        return false;
    if (newCapitalFaction->reputationListID < 0 || oldCapitalFaction->reputationListID < 0)
        return false;

    FactionState const* pStateAtCapital = GetReputationMgr().GetState(oldCapitalFaction);
    FactionState const* pStateAtOldCapital = GetReputationMgr().GetState(newCapitalId);

    int32 standingAtCapital = pStateAtCapital ? pStateAtCapital->Standing : 0;
    int32 standingAtOldCapital  = pStateAtOldCapital ? pStateAtOldCapital->Standing : 0;
    FactionStateList const& stateList = GetReputationMgr().GetStateList();

    // Gestion des capitales
    if (changeTeam)
    {
        GetReputationMgr().SetReputation(oldCapitalFaction, -standingAtOldCapital + GetReputationMgr().GetBaseReputation(oldCapitalFaction));
        GetReputationMgr().SetReputation(newCapitalFaction, -standingAtCapital + GetReputationMgr().GetBaseReputation(newCapitalFaction));
    }
    else
    {
        GetReputationMgr().SetReputation(oldCapitalFaction, standingAtOldCapital + GetReputationMgr().GetBaseReputation(oldCapitalFaction));
        GetReputationMgr().SetReputation(newCapitalFaction, standingAtCapital + GetReputationMgr().GetBaseReputation(newCapitalFaction));
    }
    // Les autres de maniere generique
    for (FactionStateList::const_iterator it = stateList.begin(); it != stateList.end(); ++it)
    {
        // Deja fait plus haut.
        if (it->second.ID == oldCapitalFaction->ID || it->second.ID == newCapitalFaction->ID)
            continue;
        // Ou gere plus tard avec sObjectMgr
        bool found = false;
        for (std::map<uint32, uint32>::const_iterator it2 = sObjectMgr.factionchange_reputations.begin(); it2 != sObjectMgr.factionchange_reputations.end(); ++it2)
        {
            if (it2->first == it->second.ID || it2->second == it->second.ID)
            {
                found = true;
                break;
            }
        }
        if (found)
            continue;
        FactionState* pState = (FactionState*)GetReputationMgr().GetState(it->second.ID);
        FactionEntry const* pFactionEntry = sObjectMgr.GetFactionEntry(it->second.ID);
        if (!pState || !pFactionEntry)
            continue;

        // Calcul des reputations/flags de base
        int newIdx = pFactionEntry->GetIndexFitTo(newRaceMask, GetClassMask());
        int32 newBaseRep = newIdx >= 0 ? pFactionEntry->BaseRepValue[newIdx] : 0;
        int oldIdx = pFactionEntry->GetIndexFitTo(oldRaceMask, GetClassMask());
        int32 oldBaseRep = oldIdx >= 0 ? pFactionEntry->BaseRepValue[oldIdx] : 0;

        // De signe different et non nulles.
        if (newBaseRep * oldBaseRep < 0)
        {
            CHANGERACE_LOG("Inversion du Standing de %u (%i)", it->second.ID, pState->Standing);
            pState->Standing = -pState->Standing;
            GetReputationMgr().SendState(pState);
            pState->needSave = true;
        }
    }
    if (!changeTeam)
        return true;
    Team newTeam = TeamForRace(newRace);
#define SWAP_TYPE(type, val1, val2) { type tmp; tmp = val1; val1 = val2; val2 = tmp; }
    // Certaines reputs a inverser
    for (std::map<uint32, uint32>::const_iterator it = sObjectMgr.factionchange_reputations.begin(); it != sObjectMgr.factionchange_reputations.end(); ++it)
    {
        FactionEntry const* my_new_reputation = sObjectMgr.GetFactionEntry(newTeam == ALLIANCE ? it->first : it->second);
        FactionEntry const* my_old_reputation = sObjectMgr.GetFactionEntry(newTeam == ALLIANCE ? it->second : it->first);
        // 'my_new_reputation' = 'my_old_reputation'
        // Et on supprime 'my_old_reputation'
        FactionState* pNew = (FactionState*)GetReputationMgr().GetState(my_new_reputation);
        FactionState* pOld = (FactionState*)GetReputationMgr().GetState(my_old_reputation);

        if (!pNew || !pOld)
            continue;
        CHANGERACE_LOG("Changement reputation %u (%i) <-> %u (%i)", my_new_reputation->ID, pNew->Standing, my_old_reputation->ID, pOld->Standing);
        SWAP_TYPE(uint32, pNew->Flags, pOld->Flags);
        SWAP_TYPE(int32, pNew->Standing, pOld->Standing);
        pOld->needSave = true;
        pNew->needSave = true;
        GetReputationMgr().SendState(pOld);
        GetReputationMgr().SendState(pNew);
    }
    CHANGERACE_LOG("Changements reputations OK");
    return true;
}

bool Player::ChangeQuestsForRace(uint8 oldRace, uint8 newRace)
{
    Team newTeam = TeamForRace(newRace);
    // 1 - Les quetes a inverser (player_factionchange_quests)
    for (std::map<uint32, uint32>::const_iterator it = sObjectMgr.factionchange_quests.begin(); it != sObjectMgr.factionchange_quests.end(); ++it)
    {
        if (it->first == it->second)
            continue;

        Quest const* pNewQuest    = sObjectMgr.GetQuestTemplate(newTeam == ALLIANCE ? it->first : it->second);
        if (!pNewQuest)
            continue;
        uint32 removeQuestId = newTeam == ALLIANCE ? it->second : it->first;
        for (auto& itr : mQuestStatus)
        {
            if (itr.first == removeQuestId)
            {
                Quest const* pRemoveQuest = sObjectMgr.GetQuestTemplate(removeQuestId);
                if (!pRemoveQuest) // ??
                    continue;

                uint16 log_slot = FindQuestSlot(removeQuestId);
                // Reset des objectifs si en cours.
                if (log_slot != MAX_QUEST_LOG_SIZE)
                {
                    // Reset
                    if (pRemoveQuest->HasSpecialFlag(QUEST_SPECIAL_FLAG_TIMED))
                        RemoveTimedQuest(removeQuestId);
                    SetQuestSlotState(log_slot, QUEST_STATUS_NONE);
                    SetQuestSlot(log_slot, 0);
                    TakeOrReplaceQuestStartItems(removeQuestId, true, false);
                    // Et prendre la nouvelle
                    if (!CanAddQuest(pNewQuest, true))
                    {
                        CHANGERACE_ERR("Impossible d'ajouter la quete %u !", pNewQuest->GetQuestId());
                        return false;
                    }
                    CHANGERACE_LOG("Changement quete %u -> %u (En cours)", pRemoveQuest->GetQuestId(), pNewQuest->GetQuestId());
                    AddQuest(pNewQuest, nullptr);
                }
                else // Ne pas reset. Juste changer l'ID.
                {
                    CHANGERACE_LOG("Changement quete %u -> %u (Deja completee)", pRemoveQuest->GetQuestId(), pNewQuest->GetQuestId());
                    QuestStatusData newQuestStatus;
                    newQuestStatus.uState = QUEST_NEW;
                    newQuestStatus.m_rewarded = itr.second.m_rewarded;
                    newQuestStatus.m_explored = itr.second.m_explored;
                    newQuestStatus.m_timer = itr.second.m_timer;
                    newQuestStatus.m_status = itr.second.m_status;
                    // Pas de duplicate dans les quetes
                    QuestStatusMap::iterator eraseNewQuest = mQuestStatus.find(pNewQuest->GetQuestId());
                    if (eraseNewQuest != mQuestStatus.end())
                        mQuestStatus.erase(eraseNewQuest);
                    mQuestStatus[pNewQuest->GetQuestId()] = newQuestStatus;
                    itr.second.uState = QUEST_DELETED;
                }
                break;
            }
        }
    }

    // 2 - Et supprimer les quetes non accessibles.
    QuestStatusMap::iterator itr = mQuestStatus.begin();
    while (itr != mQuestStatus.end())
    {
        uint32 quest_id = itr->first;
        Quest const* pQuest = sObjectMgr.GetQuestTemplate(quest_id);
        // Probleme de quete, ou deja supprimee
        if (!pQuest || !pQuest->IsActive() || itr->second.uState == QUEST_DELETED)
        {
            ++itr;
            continue;
        }
        if (SatisfyQuestSkill(pQuest, false) && SatisfyQuestRace(pQuest, false) && SatisfyQuestReputation(pQuest, false) && SatisfyQuestClass(pQuest, false))
        {
            ++itr;
            continue; // Pas besoin de toucher a cette quete
        }
        // Sinon, il faut supprimer
        uint16 log_slot = FindQuestSlot(quest_id);
        // En cours de completion, et pas deja supprimee dans la boucle precedente.
        if (log_slot != MAX_QUEST_LOG_SIZE)
        {
            if (pQuest->HasSpecialFlag(QUEST_SPECIAL_FLAG_TIMED))
                RemoveTimedQuest(itr->first);

            TakeOrReplaceQuestStartItems(itr->first, true, false);
        }
        itr->second.uState = QUEST_DELETED;
        CHANGERACE_LOG("Suppression de la quete %u", quest_id);
        ++itr;
    }
    return true;
}

bool Player::IsImmuneToSpellEffect(SpellEntry const* spellInfo, SpellEffectIndex index, bool castOnSelf) const
{
    if (HasCheatOption(PLAYER_CHEAT_DEBUFF_IMMUNITY) && spellInfo->EffectApplyAuraName[index] && !spellInfo->IsPositiveEffect(index))
        return true;

    switch (spellInfo->Effect[index])
    {
        case SPELL_EFFECT_ATTACK_ME:
            return true;
        default:
            break;
    }
    switch (spellInfo->EffectApplyAuraName[index])
    {
        case SPELL_AURA_MOD_TAUNT:
            return true;
        default:
            break;
    }
    return Unit::IsImmuneToSpellEffect(spellInfo, index, castOnSelf);
}

Item* Player::AddItem(uint32 itemId, uint32 count)
{
    uint32 noSpaceForCount = 0;
    ItemPosCountVec dest;
    InventoryResult msg = CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, itemId, count, &noSpaceForCount);
    if (msg != EQUIP_ERR_OK)
        count = noSpaceForCount;

    if (count == 0 || dest.empty())
    {
        // -- TODO: Send to mailbox if no space
        ChatHandler(this).PSendSysMessage("You don't have any space in your bags.");
        return nullptr;
    }

    Item* item = StoreNewItem(dest, itemId, true, Item::GenerateItemRandomPropertyId(itemId));
    if (item)
        SendNewItem(item, count, true, false);
    else
        return nullptr;
    return item;
}

void Player::SendDestroyGroupMembers(bool includingSelf)
{
    if (Group* group = GetGroup())
        for (const auto& itr : group->GetMemberSlots())
        {
            if (!includingSelf && itr.guid == GetObjectGuid())
                continue;
            WorldPacket data(SMSG_DESTROY_OBJECT, 8);
            data << itr.guid;
            GetSession()->SendPacket(&data);
            m_visibleGUIDs.erase(itr.guid);

            if (Player* player = GetMap()->GetPlayer(itr.guid))
                if (player->m_broadcaster)
                    player->m_broadcaster->RemoveListener(this);
        }
}

void Player::RefreshBitsForVisibleUnits(UpdateMask* mask, uint32 objectTypeMask)
{
    UpdateData data;
    for (const auto& guid : m_visibleGUIDs)
    {
        if (Object* obj = GetObjectByTypeMask(guid, TypeMask(objectTypeMask)))
        {
            ByteBuffer buff(50);

            buff << uint8(UPDATETYPE_VALUES);
#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_8_4
            buff << obj->GetPackGUID();
#else
            buff << obj->GetGUID();
#endif
            obj->BuildValuesUpdate(UPDATETYPE_VALUES, &buff, mask, this);
            data.AddUpdateBlock(buff);
        }
    }
    data.Send(GetSession());
}

void Player::SetSession(WorldSession* s)
{
    m_session = s;
    // PlayerTalkClass stores a pointer to WorldSession
    ASSERT(PlayerTalkClass);
    delete PlayerTalkClass;
    PlayerTalkClass = new PlayerMenu(GetSession());
}

void Player::InterruptSpellsWithCastItem(Item* item)
{
    // Interrupt current spells
    for (uint32 i = CURRENT_FIRST_NON_MELEE_SPELL; i < CURRENT_MAX_SPELL; i++)
        if (Spell* spell = GetCurrentSpell(CurrentSpellTypes(i)))
            if (spell->m_CastItem == item)
            {
                spell->ClearCastItem();
                if (i != CURRENT_CHANNELED_SPELL)
                    InterruptSpell(CurrentSpellTypes(i), true);
            }

    // Interrupt eventually delayed spells
    auto i_Events = m_Events.GetEvents().begin();
    for (; i_Events != m_Events.GetEvents().end(); ++i_Events)
        if (SpellEvent* event = dynamic_cast<SpellEvent*>(i_Events->second))
            if (event && event->GetSpell()->m_CastItem == item)
            {
                event->GetSpell()->ClearCastItem();
                if (event->GetSpell()->getState() != SPELL_STATE_FINISHED)
                    event->GetSpell()->cancel();
            }
}

std::string Player::GetShortDescription() const
{
    std::stringstream oss;
    oss << GetName() << ":" << GetGUIDLow() << " [" << GetSession()->GetUsername().c_str() << ":" << GetSession()->GetAccountId() << "@" << GetSession()->GetRemoteAddress().c_str() << "]";
    return oss.str();
}

void Player::LootMoney(int32 money, Loot* loot)
{
    WorldObject const* target = loot->GetLootTarget();
    sLog.out(LOG_LOOTS, "%s gets %ug%us%uc [loot from %s]",
             GetShortDescription().c_str(), money / 100000, (money / 100) % 100, money % 100, target ? target->GetGuidStr().c_str() : "NULL");
    LogModifyMoney(money, "Loot", target ? target->GetObjectGuid() : ObjectGuid());
}

void Player::RewardHonor(Unit* uVictim, uint32 groupSize)
{
    // Honor System was added in 1.4.
    if (sWorld.GetWowPatch() < WOW_PATCH_104 && sWorld.getConfig(CONFIG_BOOL_ACCURATE_PVP_TIMELINE))
        return;

    if (!uVictim)
        return;

    // Honorless Target
    if (uVictim->GetAura(2479, EFFECT_INDEX_0))
        return;

    if (uVictim->GetTypeId() == TYPEID_UNIT)
    {
        Creature* cVictim = (Creature*)uVictim;
        if (cVictim->IsCivilian() && !IsHonorOrXPTarget(cVictim))
        {
            if (!sWorld.getConfig(CONFIG_BOOL_ENABLE_DK))
                return;

            // Dishonorable kills were added in 1.5.
            if (sWorld.GetWowPatch() < WOW_PATCH_105 && sWorld.getConfig(CONFIG_BOOL_ACCURATE_PVP_TIMELINE))
                return;

            m_honorMgr.Add(HonorMgr::DishonorableKillPoints(GetLevel()), DISHONORABLE, cVictim);
            return;
        }

        if (cVictim->IsRacialLeader())
        {
            m_honorMgr.Add(488.0, HONORABLE, cVictim);
            //honor_points = MaNGOS::XP::xp_in_group_rate(groupsize, false) * 15000.0f / groupsize;
            //kill_type = HONORABLE;
            return;
        }
    }
    // for PvP see ::HonorRewardInPvP
}

void Player::RewardHonorOnDeath()
{
    // Honor System was added in 1.4.
    if (sWorld.GetWowPatch() < WOW_PATCH_104 && sWorld.getConfig(CONFIG_BOOL_ACCURATE_PVP_TIMELINE))
        return;

    if (GetAura(2479, EFFECT_INDEX_0))             // Honorless Target
        return;

    // " you need to be alive and close by at the time of the kill to get your share of the Honor"
    // First, get damage done per group, less than 1 minute before now
    uint32 totalDamage = 0;
    std::map<Group*, uint32> damagePerGroup;
    std::map<Player*, uint32> damagePerAlonePlayer;
    for (const auto& itr : m_damageTakenHistory)
    {
        totalDamage += itr.second;
        if (Player* attacker = GetMap()->GetPlayer(itr.first))
        {
            if (Group* g = attacker->GetGroup())
                damagePerGroup[g] += itr.second;
            else if (attacker->IsAtGroupRewardDistance(this) && attacker->IsAlive() && attacker->GetTeam() != GetTeam())
                damagePerAlonePlayer[attacker] += itr.second;
        }
    }

    if (!totalDamage)
    {
        m_damageTakenHistory.clear();
        return;
    }

    // Distribute honor ratio per group
    for (const auto& itr : damagePerGroup)
    {
        Group* g = itr.first;
        std::list<Player*> rewarded;
        for (const auto& grItr : g->GetMemberSlots())
            if (Player* pl = GetMap()->GetPlayer(grItr.guid))
                if (pl->IsAtGroupRewardDistance(this) && pl->IsAlive() && pl->GetTeam() != GetTeam())
                    rewarded.push_back(pl);

        uint32 totalRewarded = rewarded.size();
        float honorRate = itr.second;
        honorRate *= MaNGOS::XP::xp_in_group_rate(totalRewarded, false);
        honorRate /= totalDamage;
        honorRate /= totalRewarded;

        for (const auto& rewItr : rewarded)
        {
            if (!rewItr->IsHonorOrXPTarget(this))
                continue;

            uint32 rewPoints = uint32(HonorMgr::HonorableKillPoints(rewItr, this, 1) * honorRate);
            if (rewPoints)
                rewItr->GetHonorMgr().Add(rewPoints, HONORABLE, this);
        }
    }

    // Distribute honor to single players
    for (const auto& rewItr : damagePerAlonePlayer)
    {
        if (!rewItr.first->IsHonorOrXPTarget(this))
            continue;

        uint32 rewPoints = uint32(HonorMgr::HonorableKillPoints(rewItr.first, this, 1) * rewItr.second / float(totalDamage));
        if (rewPoints)
            rewItr.first->GetHonorMgr().Add(rewPoints, HONORABLE, this);
    }

    m_damageTakenHistory.clear();
}

void Player::OnReceivedItem(Item* item)
{
    if (item->GetProto()->Quality >= sWorld.getConfig(CONFIG_UINT32_ITEM_INSTANTSAVE_QUALITY))
        SetSaveTimer(1);
}


bool Player::HasFreeBattleGroundQueueId() const
{
    for (uint32 i = 0; i < sWorld.getConfig(CONFIG_UINT32_BATTLEGROUND_QUEUES_COUNT); ++i)
        if (m_bgBattleGroundQueueID[i].bgQueueTypeId == BATTLEGROUND_QUEUE_NONE)
            return true;
    return false;
}

void Player::TaxiStepFinished()
{
    if (!IsInWorld())
        return;

    // in taxi flight packet received in 2 case:
    // 1) end taxi path in far (multi-node) flight
    // 2) switch from one map to other in case multi-map taxi path
    // we need process only (1)
    uint32 curDest = m_taxi.GetTaxiDestination();
    if (!curDest)
        return;

    TaxiNodesEntry const* curDestNode = sObjectMgr.GetTaxiNodeEntry(curDest);

    // far teleport case
    if (curDestNode && curDestNode->map_id != GetMapId())
    {
        if (GetMotionMaster()->GetCurrentMovementGeneratorType() == FLIGHT_MOTION_TYPE)
        {
            // short preparations to continue flight
            FlightPathMovementGenerator* flight = (FlightPathMovementGenerator*)(GetMotionMaster()->top());

            flight->Interrupt(*this);                // will reset at map landing

            flight->SetCurrentNodeAfterTeleport();
            TaxiPathNodeEntry const& node = flight->GetPath()[flight->GetCurrentNode()];
            flight->SkipCurrentNode();

            TeleportTo(curDestNode->map_id, node.x, node.y, node.z, GetOrientation());
        }
        return;
    }

    uint32 destinationnode = m_taxi.NextTaxiDestination();
    if (destinationnode > 0)                                // if more destinations to go
    {
        // current source node for next destination
        uint32 sourcenode = m_taxi.GetTaxiSource();

        // Add to taximask middle hubs in taxicheat mode (to prevent having player with disabled taxicheat and not having back flight path)
        if (IsTaxiCheater())
        {
            if (m_taxi.SetTaximaskNode(sourcenode))
            {
                WorldPacket data(SMSG_NEW_TAXI_PATH, 0);
                GetSession()->SendPacket(&data);
            }
        }

        DEBUG_LOG("WORLD: Taxi has to go from %u to %u", sourcenode, destinationnode);

        uint32 mountDisplayId = sObjectMgr.GetTaxiMountDisplayId(sourcenode, GetTeam());

        uint32 path, cost;
        sObjectMgr.GetTaxiPath(sourcenode, destinationnode, path, cost);

        if (path && mountDisplayId)
            GetSession()->SendDoFlight(mountDisplayId, path, 1);          // skip start fly node
        else
            m_taxi.ClearTaxiDestinations();    // clear problematic path and next
    }
    else
    {
        // When the player reaches the last flight point, teleport to destination taxi node location
        TeleportTo(curDestNode->map_id, curDestNode->x, curDestNode->y, curDestNode->z, GetOrientation());
        m_taxi.ClearTaxiDestinations();        // not destinations, clear source node
    } 
}


// Do not need to lock m_visibleGUIDs because this function is single-threaded
void Player::HandleStealthedUnitsDetection()
{
    if (!FindMap())
        return;

    std::list<Unit*> stealthedUnits;

    MaNGOS::AnyStealthedCheck u_check(this);
    MaNGOS::UnitListSearcher<MaNGOS::AnyStealthedCheck > searcher(stealthedUnits, u_check);
    Cell::VisitAllObjects(this, searcher, sWorld.getConfig(CONFIG_FLOAT_MAX_PLAYERS_STEALTH_DETECT_RANGE));

    WorldObject const* viewPoint = GetCamera().GetBody();
    for (const auto stealthedUnit : stealthedUnits)
    {
        if (stealthedUnit == this)
            continue;

        bool hasDetected = stealthedUnit->IsVisibleForOrDetect(this, viewPoint, true);

        if (hasDetected)
        {
            if (!IsInVisibleList_Unsafe(stealthedUnit))
            {
                if (Player* i_player = stealthedUnit->ToPlayer())
                    if (i_player->m_broadcaster)
                        i_player->m_broadcaster->AddListener(this);

                m_visibleGUIDs.insert(stealthedUnit->GetObjectGuid());
                stealthedUnit->SendCreateUpdateToPlayer(this);
            }
        }
        else
        {
            if (IsInVisibleList_Unsafe(stealthedUnit))
            {
                stealthedUnit->DestroyForPlayer(this);

                if (Player* i_player = stealthedUnit->ToPlayer())
                    if (i_player->m_broadcaster)
                        i_player->m_broadcaster->RemoveListener(this);

                m_visibleGUIDs.erase(stealthedUnit->GetObjectGuid());
            }
        }
    }
}


bool Player::IsInVisibleList(WorldObject const* u) const
{
    if (u == this)
        return true;
    std::shared_lock<std::shared_timed_mutex> lock(m_visibleGUIDs_lock);
    bool atClient = m_visibleGUIDs.find(u->GetObjectGuid()) != m_visibleGUIDs.end();
    return atClient;
}


PlayerSocial* Player::GetSocial() const
{
    MasterPlayer* masterPlayer = GetSession()->GetMasterPlayer();
    ASSERT(masterPlayer);
    return masterPlayer->GetSocial();
}

PlayerSocial* Player::FindSocial() const
{
    MasterPlayer* masterPlayer = GetSession()->GetMasterPlayer();
    return masterPlayer ? masterPlayer->GetSocial() : nullptr;
}

void Player::DeletePacketBroadcaster()
{
    if (m_broadcaster)
    {
        sWorld.GetBroadcaster()->RemovePlayer(m_broadcaster);
        // Remove reference to socket, so we can free descriptor, buffers, etc...
        m_broadcaster->FreeAtLogout();
        m_broadcaster.reset();
    }
}

void Player::CreatePacketBroadcaster()
{
    ASSERT(!m_broadcaster);
    // Register player packet queue with the packet broadcaster
    m_broadcaster = std::make_shared<PlayerBroadcaster>(m_session->GetSocket(), GetObjectGuid());
    sWorld.GetBroadcaster()->RegisterPlayer(m_broadcaster);
}


void Player::AddGCD(SpellEntry const& spellEntry, uint32 /*forcedDuration = 0*/, bool updateClient /*= false*/)
{
    int32 gcdDuration = spellEntry.StartRecoveryTime;
    if (!spellEntry.StartRecoveryCategory && !gcdDuration)
        return;

    // gcd modifier auras applied only to self spells and only player have mods for this
    ApplySpellMod(spellEntry.Id, SPELLMOD_GLOBAL_COOLDOWN, gcdDuration);

    // apply haste rating
    if (spellEntry.StartRecoveryCategory == 133 && gcdDuration == 1500 &&
        spellEntry.DmgClass != SPELL_DAMAGE_CLASS_MELEE && spellEntry.DmgClass != SPELL_DAMAGE_CLASS_RANGED &&
        !spellEntry.HasAttribute(SPELL_ATTR_RANGED) && !spellEntry.HasAttribute(SPELL_ATTR_IS_ABILITY))
    {
#if SUPPORTED_CLIENT_BUILD >= CLIENT_BUILD_1_12_1
        gcdDuration = int32(float(gcdDuration) * GetFloatValue(UNIT_MOD_CAST_SPEED));
#else
        gcdDuration = int32(float(gcdDuration) * (1.0f + GetInt32Value(UNIT_MOD_CAST_SPEED) / 100.0f));
#endif
        gcdDuration = std::max(gcdDuration, 1000);
        gcdDuration = std::min(gcdDuration, 1500);
    }

    if (!gcdDuration)
        return;

    // TODO: Remove this once spells are queuable and GCD is checked on execute
    if (uint32 latency = GetSession()->GetLatency())
    {
        if (latency > 300)
            gcdDuration -= 300;
        else
            gcdDuration -= latency;

        gcdDuration -= sWorld.GetCurrentDiff() > 200 ? 200 : sWorld.GetCurrentDiff();
    }

    SpellCaster::AddGCD(spellEntry, gcdDuration);

    if (!updateClient)
        return;

    // send to client
    SendSpellCooldown(spellEntry.Id, 0, GetObjectGuid());
}

void Player::AddCooldown(SpellEntry const& spellEntry, ItemPrototype const* itemProto /*= nullptr*/, bool permanent /*= false*/, uint32 forcedDuration /*= 0*/)
{
    uint32 spellCategory = spellEntry.Category;
    uint32 recTime = spellEntry.RecoveryTime; // int because of spellmod calculations
    uint32 categoryRecTime = spellEntry.CategoryRecoveryTime; // int because of spellmod calculations
    uint32 itemId = 0;

    if (itemProto)
    {
        for (const auto& Spell : itemProto->Spells)
        {
            if (Spell.SpellId == spellEntry.Id)
            {
                if (Spell.SpellCategory)
                    spellCategory = Spell.SpellCategory;
                if (Spell.SpellCooldown != -1)
                    recTime = Spell.SpellCooldown;
                if (Spell.SpellCategoryCooldown != -1)
                    categoryRecTime = Spell.SpellCategoryCooldown;
                itemId = itemProto->ItemId;
                break;
            }
        }
    }

    bool haveToSendEvent = false;
    auto cdDataItr = m_cooldownMap.FindBySpellId(spellEntry.Id);
    if (cdDataItr != m_cooldownMap.end())
    {
        auto& cdData = cdDataItr->second;
        if (!cdData->IsPermanent())
        {
            sLog.outError("Player::AddCooldown> Spell(%u) try to add and already existing cooldown?", spellEntry.Id);
            return;
        }
        m_cooldownMap.erase(cdDataItr);
        haveToSendEvent = true;
    }

    if (permanent)
    {
        m_cooldownMap.AddCooldown(sWorld.GetCurrentClockTime(), spellEntry.Id, recTime, spellCategory, categoryRecTime, itemId, true);
        return;
    }

    if (forcedDuration)
        recTime = forcedDuration;
    else
    {
        // shoot spells used equipped item cooldown values already assigned in GetAttackTime(RANGED_ATTACK)
        // prevent 0 cooldowns set by another way
        if (spellEntry.HasAttribute(SPELL_ATTR_RANGED) && !spellEntry.HasAttribute(SPELL_ATTR_EX2_NOT_RESET_AUTO_ACTIONS))
            recTime += GetFloatValue(UNIT_FIELD_RANGEDATTACKTIME);
    }

    // blizzlike code for choosing which is recTime > categoryRecTime after spellmod application
    if (recTime)
        ApplySpellMod(spellEntry.Id, SPELLMOD_COOLDOWN, recTime);
    else if (spellCategory && categoryRecTime)
        ApplySpellMod(spellEntry.Id, SPELLMOD_COOLDOWN, categoryRecTime);

    if (recTime || categoryRecTime)
    {
        // ready to add the cooldown
        m_cooldownMap.AddCooldown(sWorld.GetCurrentClockTime(), spellEntry.Id, recTime, spellCategory, categoryRecTime, itemId);

        // after some aura fade or potion activation we have to send cooldown event to start cd client side
        if (haveToSendEvent)
        {
            // Send activate cooldown timer (possible 0) at client side
            WorldPacket data(SMSG_COOLDOWN_EVENT, (4 + 8));
            data << uint32(spellEntry.Id);
            data << GetObjectGuid();
            SendDirectMessage(&data);
            sLog.outDebug("Sending SMSG_COOLDOWN_EVENT with spell id = %u", spellEntry.Id);
        }
    }
}

void Player::RemoveSpellCooldown(SpellEntry const& spellEntry, bool updateClient /*= true*/)
{
    m_cooldownMap.RemoveBySpellId(spellEntry.Id);

    if (updateClient)
        SendClearCooldown(spellEntry.Id, this);
}

void Player::RemoveSpellCategoryCooldown(uint32 category, bool updateClient /*= true*/)
{
    auto spellItr = m_cooldownMap.FindByCategory(category);
    if (spellItr == m_cooldownMap.end())
        return;

    auto& cdData = spellItr->second;
    if (updateClient)
        SendClearCooldown(cdData->GetSpellId(), this);

    m_cooldownMap.erase(spellItr);
}

void Player::RemoveAllCooldowns(bool sendOnly /*= false*/)
{
    std::set<uint32> spellsSent;
    // not reset gcd (usually small enough)

    // reset normal cd
    for (auto& cdItr : m_cooldownMap)
    {
        auto& cdData = cdItr.second;
        if (!cdData->IsPermanent())
        {
            spellsSent.emplace(cdData->GetSpellId());
        }
    }

    // reset lockout spell
    for (auto& lockoutItr : m_lockoutMap)
    {
        SpellSchoolMask lockoutSchoolMask = SpellSchoolMask(1 << lockoutItr.first);
        RemoveSpellLockout(lockoutSchoolMask, &spellsSent);
    }

    SendClearAllCooldowns(this);

    if (!sendOnly)
    {
        m_cooldownMap.clear();
        m_lockoutMap.clear();
    }
}

void Player::LockOutSpells(SpellSchoolMask schoolMask, uint32 duration)
{
    TimePoint lockoutExpireTime = std::chrono::milliseconds(duration) + sWorld.GetCurrentClockTime();
    ByteBuffer cdData;
    uint32 spellCount = 0;

    // Send CD to clients
    for (auto ownerSpellItr : GetSpellMap())
    {
        if (ownerSpellItr.second.state == PLAYERSPELL_REMOVED)
            continue;

        uint32 unSpellId = ownerSpellItr.first;
        SpellEntry const* spellEntry = sSpellMgr.GetSpellEntry(unSpellId);

        // Not send cooldown for this spells
        if (spellEntry->HasAttribute(SPELL_ATTR_DISABLED_WHILE_ACTIVE))
            continue;

        TimePoint expireTime;
        bool isInfinite;
        bool spellCDFound = GetExpireTime(*spellEntry, expireTime, isInfinite);

        if ((schoolMask & spellEntry->GetSpellSchoolMask()) && (!spellCDFound || expireTime < lockoutExpireTime))
        {
            cdData << uint32(unSpellId);
            cdData << uint32(duration);                     // in m.secs
            ++spellCount;
        }
    }

    WorldPacket data(SMSG_SPELL_COOLDOWN, 8 + 1 + spellCount * 8);
    data << GetObjectGuid();
    //data << uint8(0x0);                                     // flags (0x1, 0x2)
    data.append(cdData);
    GetSession()->SendPacket(&data);

    // store lockout
    SpellCaster::LockOutSpells(schoolMask, duration);
}

void Player::RemoveSpellLockout(SpellSchoolMask spellSchoolMask, std::set<uint32>* spellAlreadySent /*= nullptr*/)
{
    for (auto ownerSpellItr : GetSpellMap())
    {
        if (ownerSpellItr.second.state == PLAYERSPELL_REMOVED)
            continue;

        uint32 unSpellId = ownerSpellItr.first;
        SpellEntry const* spellEntry = sSpellMgr.GetSpellEntry(unSpellId);

        // Not send cooldown for this spells
        if (!spellEntry || !(spellEntry->GetSpellSchoolMask() & spellSchoolMask) || spellEntry->HasAttribute(SPELL_ATTR_DISABLED_WHILE_ACTIVE))
            continue;

        if (spellAlreadySent)
        {
            if (spellAlreadySent->find(spellEntry->Id) != spellAlreadySent->end())
                continue;

            spellAlreadySent->emplace(spellEntry->Id);
        }

        SendClearCooldown(spellEntry->Id, this);
    }
}

bool Player::IsInCombatWithCreature(Creature const* pCreature)
{
    HostileReference* pReference = GetHostileRefManager().getFirst();

    while (pReference)
    {
        if (pCreature == pReference->getSourceUnit())
            return true;

        pReference = pReference->next();
    }

    return false;
}
