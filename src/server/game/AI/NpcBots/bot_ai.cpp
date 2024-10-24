#include "Battleground.h"
#include "BattlegroundAB.h"
#include "BattlegroundAV.h"
#include "BattlegroundWS.h"
#include "bot_ai.h"
#include "bot_Events.h"
#include "bot_GridNotifiers.h"
#include "botdatamgr.h"
#include "botlog.h"
#include "botmgr.h"
#include "botgearscore.h"
#include "botgossip.h"
#include "botspell.h"
#include "bottext.h"
#include "botwanderful.h"
#include "bpet_ai.h"
#include "Bag.h"
#include "BattlegroundMgr.h"
#include "CellImpl.h"
#include "CharacterCache.h"
#include "CharacterDatabase.h"
#include "Chat.h"
#include "Containers.h"
#include "DatabaseEnv.h"
#include "DBCStores.h"
#include "GameEventMgr.h"
#include "GameObjectAI.h"
#include "GossipDef.h"
#include "GridNotifiersImpl.h"
#include "InstanceScript.h"
#include "Item.h"
#include "LFGMgr.h"
#include "Log.h"
#include "Loot.h"
#include "LootMgr.h"
#include "Mail.h"
#include "MapManager.h"
#include "MotionMaster.h"
#include "ObjectMgr.h"
#include "PathGenerator.h"
#include "PointMovementGenerator.h"
#include "ScriptedGossip.h"
#include "ScriptMgr.h"
#include "SpellAuraEffects.h"
#include "TemporarySummon.h"
#include "Transport.h"
#include "World.h"

#include "G3DPosition.hpp"
/*
NpcBot System by Trickerer (https://github.com/trickerer/Trinity-Bots; onlysuffering@gmail.com)
Version 5.2.77a
Original idea: https://bitbucket.org/lordpsyan/trinitycore-patches/src/3b8b9072280e/Individual/11185-BOTS-NPCBots.patch
TODO:
dk pets (garg, aod, rdw)
'Go there and do stuff' scenarios
Encounter Scenarios
Notes:
Methods may have null arg1 (Unit*):
DamageTaken(Unit*, ), JustDied(Unit*, ), OwnerAttackedBy(Unit*, ), HealReceived(Unit*, )
Possibly others
*/

#ifdef _MSC_VER
# pragma warning(push, 4)
#endif

static constexpr GossipOptionIcon BOT_ICON_ON = GOSSIP_ICON_BATTLE;
static constexpr GossipOptionIcon BOT_ICON_OFF = GOSSIP_ICON_CHAT;

static constexpr uint32 MAX_AMMO_LEVEL = 13;
static constexpr uint8 AmmoDPSForLevel[MAX_AMMO_LEVEL][2] =
{
    {  1,  1 },
    {  5,  2 },
    { 10,  3 },
    { 15,  4 },
    { 25,  7 },
    { 30,  8 },
    { 37, 12 },
    { 44, 15 },
    { 52, 17 },
    { 57, 26 },
    { 62, 43 },
    { 72, 67 },
    { 80, 91 }
};
static constexpr uint32 MAX_POTION_SPELLS = 8;
static constexpr uint32 MAX_FEAST_SPELLS = 11;
static constexpr uint32 ManaPotionSpells[MAX_POTION_SPELLS][2] =
{
    {  5,   437 },
    { 14,   438 },
    { 22,  2023 },
    { 31, 11903 },
    { 41, 17530 },
    { 49, 17531 },
    { 55, 28499 },
    { 70, 43186 }
};
static constexpr uint32 HealingPotionSpells[MAX_POTION_SPELLS][2] =
{
    {  1,   439 },
    {  3,   440 },
    { 12,   441 },
    { 21,  2024 },
    { 35,  4042 },
    { 45, 17534 },
    { 55, 28495 },
    { 70, 43185 }
};
static constexpr uint32 DrinkSpells[MAX_FEAST_SPELLS][2] =
{
    {  1,   430 },
    {  5,   431 },
    { 15,   432 },
    { 25,  1133 },
    { 35,  1135 },
    { 45,  1137 },
    { 60, 34291 },
    { 65, 27089 },
    { 70, 43182 },
    { 75, 43183 },
    { 80, 57073 }
};
static constexpr uint32 EatSpells[MAX_FEAST_SPELLS][2] =
{
    {  1,   433 },
    {  5,   434 },
    { 15,   435 },
    { 25,  1127 },
    { 35,  1129 },
    { 45,  1131 },
    { 55, 27094 },
    { 65, 35270 },
    { 70, 43180 }, //req 65 but
    { 75, 45548 },
    { 80, 45548 }
};
uint8 GroupIconsFlags[TARGET_ICONS_COUNT] =
{
    /*STAR        = */0x001,
    /*CIRCLE      = */0x002,
    /*DIAMOND     = */0x004,
    /*TRIANGLE    = */0x008,
    /*MOON        = */0x010,
    /*SQUARE      = */0x020,
    /*CROSS       = */0x040,
    /*SKULL       = */0x080
};

struct TSpellSummary
{
    uint8 Targets; // set of enum SelectTarget
    uint8 Effects; // set of enum SelectEffect
};
extern TSpellSummary* SpellSummary;

void ApplyBotPercentModFloatVar(float &var, float val, bool apply)
{
    var *= (apply ? ((100.f + val) / 100.f) : (100.f / (100.f + val)));
}

static uint16 __rand; //calculated for each bot separately once every updateAI tick

static std::set<uint32> BotCustomSpells;

bot_ai::bot_ai(Creature* creature) : CreatureAI(creature)
{
    //moved
    _potionTimer = 0;

    _classinfo = new PlayerClassLevelInfo();

    for (uint8 i = BOT_SLOT_MAINHAND; i != BOT_INVENTORY_SIZE; ++i)
        for (uint8 j = 0; j != MAX_BOT_ITEM_MOD; ++j)
            _stats[i][j] = 0;

    for (uint8 i = BOT_SLOT_MAINHAND; i != BOT_INVENTORY_SIZE; ++i)
        _equips[i] = nullptr;

    _powersTimer = 0;
    _chaseTimer = 0;
    _engageTimer = 0;

    _unreachableCount = 0;
    _jumpCount = 0;
    _evadeCount = 0;

    _lastTargetGuid = ObjectGuid::Empty;

    checkMasterTimer = urand(5000, 15000);
    feast_health = false;
    feast_mana = false;
    spawned = false;
    firstspawn = true;
    _evadeMode = false;
    _atHome = true;
    _roleMask = 0;
    _healHpPctThreshold = 95;
    _primaryIconTank = -1;
    _primaryIconDamage = -1;
    haste = 0;
    hit = 0.f;
    parry = 0.f;
    dodge = 0.f;
    block = 0.f;
    crit = 0.f;
    dmg_taken_phy = 1.f;
    dmg_taken_mag = 1.f;
    armor_pen = 0.f;
    resilience = 0.f;
    expertise = 0;
    spellpower = 0;
    spellpen = 0;
    defense = 0;
    blockvalue = 1;
    regenTimer = 0;
    m_botSpellInfo = nullptr;
    waitTimer = 0;
    _moveBehindTimer = 0;
    itemsAutouseTimer = 0;
    _usableItemSlotsMask = 0;
    evadeDelayTimer = 0;
    indoorsTimer = 0;
    outdoorsTimer = 0;
    GC_Timer = 0;
    lastdiff = 0;
    _energyFraction = 0.f;
    _updateTimerMedium = 0;
    _updateTimerEx1 = urand(12000, 15000);
    _updateTimerEx2 = urand(8000, 12000);
    checkAurasTimer = 0;
    roleTimer = 0;
    ordersTimer = 0;
    doHealth = false;
    doMana = false;
    //shouldUpdateStats = true;
    movepos.m_positionX = 0.f;
    movepos.m_positionY = 0.f;
    movepos.m_positionZ = 0.f;
    aftercastTargetGuid = ObjectGuid::Empty;

    shouldEnterVehicle = false;

    _saveDisabledSpellsTimer = 0;
    _saveDisabledSpells = false;

    _deathsCount = 0;
    _killsCount = 0;
    _pvpKillsCount = 0;
    _playerKillsCount = 0;

    for (uint8 i = SPELL_SCHOOL_HOLY; i != MAX_SPELL_SCHOOL; ++i)
        resistbonus[i - 1] = 0;

    botPet = nullptr;
    canUpdate = true;
    _duringTeleport = false;
    _canAppearInWorld = false;

    teleHomeEvent = nullptr;
    teleFinishEvent = nullptr;
    awaitStateRemEvent = nullptr;

    _lastZoneId = 0;
    _lastAreaId = 0;
    _lastWMOAreaId = 0;

    _selfrez_spell_id = 0;

    _wmoAreaUpdateTimer = 0;

    _contestedPvPTimer = 0;
    _groupUpdateTimer = BOT_GROUP_UPDATE_TIMER;

    _ownerGuid = 0;

    _wanderer = false;
    _baseLevel = 0;
    _travel_node_last = nullptr;
    _travel_node_cur = nullptr;

    _groupUpdateMask = 0;
    _auraRaidUpdateMask = 0;
    _bg = nullptr;

    opponent = nullptr;
    disttarget = nullptr;

    ResetBotAI(BOTAI_RESET_INIT);

    if (!IsTempBot())
        BotDataMgr::RegisterBot(me);
}
bot_ai::~bot_ai()
{
    TC_LOG_INFO("scripts", "bot_ai destructor call for {} ({})", me->GetName(), me->GetEntry());

    while (!_spells.empty())
    {
        BotSpellMap::iterator itr = _spells.begin();
        delete itr->second;
        _spells.erase(itr);
    }

    for (uint8 i = BOT_SLOT_MAINHAND; i != BOT_INVENTORY_SIZE; ++i)
        if (_equips[i])
            delete _equips[i];

    delete _classinfo;

    BotDataMgr::UnregisterBot(me);
}

uint16 bot_ai::Rand() const
{
    return __rand;
}
//0-178
void bot_ai::GenerateRand() const
{
    __rand = urand(0, IAmFree() ? 100 : 100 + (master->GetNpcBotsCount() - 1) * 2);
}

const std::string& bot_ai::LocalizedNpcText(Player const* forPlayer, uint32 textId)
{
    LocaleConstant loc = forPlayer ? forPlayer->GetSession()->GetSessionDbLocaleIndex() : sWorld->GetDefaultDbcLocale();

    if (GossipText const* nt = sObjectMgr->GetGossipText(textId))
    {
        std::wstring wnamepart;
        NpcTextLocale const* ntl = sObjectMgr->GetNpcTextLocale(textId);
        if (loc != DEFAULT_LOCALE && ntl && ntl->Text_0[0].size() > size_t(loc) && !ntl->Text_0[0][loc].empty() && Utf8FitTo(ntl->Text_0[0][loc], wnamepart))
            return ntl->Text_0[0][loc];
        else
            return nt->Options[0].Text_0;
    }

    {
        static std::map<uint32, std::string> unk_botstrings;

        if (!unk_botstrings.contains(textId))
        {
            TC_LOG_ERROR("entities.player", "NPCBots: bot text string #{} is not localized, at least for {}",
                textId, localeNames[loc]);

            std::ostringstream msg;
            msg << (loc == DEFAULT_LOCALE ? "<undefined string " : "<unlocalized string ") << textId << ">";
            unk_botstrings[textId] = msg.str();
        }

        return unk_botstrings[textId];
    }
}

void bot_ai::InitializeAI()
{
    if (!me->GetSpawnId() && !IsTempBot())
        SetWanderer();

    Reset();
}

void bot_ai::BotSay(const std::string &text, Player const* target) const
{
    if (!target && master->GetTypeId() == TYPEID_PLAYER)
        target = master;
    if (!target)
        return;

    me->Say(text, LANG_UNIVERSAL, target);
}
void bot_ai::BotWhisper(const std::string &text, Player const* target) const
{
    if (!target && master->GetTypeId() == TYPEID_PLAYER)
        target = master;
    if (!target)
        return;

    Player* playerTarget = const_cast<Player*>(target);

    me->Whisper(text, LANG_UNIVERSAL, playerTarget);
}
void bot_ai::BotYell(const std::string &text, Player const* /*target*/) const
{
    //if (!target && master->GetTypeId() == TYPEID_PLAYER)
    //    target = master;
    //if (!target)
    //    return;

    me->Yell(text, LANG_UNIVERSAL);
}
void bot_ai::BotSay(std::string&& text, Player const* target) const
{
    if (!target && master->GetTypeId() == TYPEID_PLAYER)
        target = master;
    if (!target)
        return;

    me->Say(text, LANG_UNIVERSAL, target);
}
void bot_ai::BotWhisper(std::string&& text, Player const* target) const
{
    if (!target && master->GetTypeId() == TYPEID_PLAYER)
        target = master;
    if (!target)
        return;

    Player* playerTarget = const_cast<Player*>(target);

    me->Whisper(text, LANG_UNIVERSAL, playerTarget);
}
void bot_ai::BotYell(std::string&& text, Player const* /*target*/) const
{
    me->Yell(text, LANG_UNIVERSAL);
}

void bot_ai::ReportSpellCast(uint32 spellId, const std::string& followedByString, Player const* target) const
{
    std::string spellName;
    _LocalizeSpell(target, spellName, spellId);
    BotWhisper(spellName + followedByString, target);
}

bool bot_ai::SetBotOwner(Player* newowner)
{
    ASSERT(newowner, "Trying to set NULL owner!!!");
    ASSERT(newowner->GetGUID().IsPlayer(), "Trying to set a non-player as owner!!!");
    //ASSERT(master->GetGUID() == me->GetGUID());
    //ASSERT(IAmFree());

    //have master already
    if (master->GetGUID() != me->GetGUID())
    {
        TC_LOG_ERROR("entities.player", "bot_ai::SetBotOwner(): bot {} (id: {}) has master {} while trying to set to {}...",
            me->GetName(), me->GetEntry(), master->GetName(), newowner->GetName());
        return false;
    }
    if (!IAmFree())
    {
        TC_LOG_ERROR("entities.player", "bot_ai::SetBotOwner(): minion bot {} (id: {}) IS NOT FREE (has master {}) while trying to set to {}",
            me->GetName(), me->GetEntry(), master->GetName(), newowner->GetName());
        return false;
    }

    if (newowner->GetBotMgr()->AddBot(me) & BOT_ADD_FATAL)
    {
        checkMasterTimer += 30000;
        return false;
    }

    spawned = false;

    (const_cast<CreatureTemplate*>(me->GetCreatureTemplate()))->unit_flags2 &= ~(UNIT_FLAG2_ALLOW_ENEMY_INTERACT);
    me->ReplaceAllUnitFlags2(UnitFlags2(me->GetCreatureTemplate()->unit_flags2));

    //recursive
    if (master->GetGUID() == newowner->GetGUID())
        return true;

    master = newowner;
    _ownerGuid = newowner->GetGUID().GetCounter();
    _checkOwershipTimer = BotMgr::GetOwnershipExpireTime() ? CalculateOwnershipCheckTime() : 0;

    return true;
}
//Check if should totally unlink from owner
void bot_ai::CheckOwnerExpiry()
{
    if (!BotMgr::GetOwnershipExpireTime())
        return; //disabled

    if (IsTempBot() || !IAmFree())
        return;

    NpcBotData const* npcBotData = BotDataMgr::SelectNpcBotData(me->GetEntry());
    ASSERT(npcBotData, "bot_ai::CheckOwnerExpiry(): data not found!");

    NpcBotExtras const* npcBotExtra = BotDataMgr::SelectNpcBotExtras(me->GetEntry());
    ASSERT(npcBotExtra, "bot_ai::CheckOwnerExpiry(): extra data not found!");

    if (npcBotData->owner == 0)
        return;

    ObjectGuid ownerGuid = ObjectGuid(HighGuid::Player, 0, npcBotData->owner);
    time_t timeNow = time(0);
    time_t expireTime = time_t(BotMgr::GetOwnershipExpireTime());
    time_t baseTimeStamp;

    if (BotMgr::GetOwnershipExpireMode() == BOT_OWNERSHIP_EXPIRE_OFFLINE)
    {
        uint32 accId = sCharacterCache->GetCharacterAccountIdByGuid(ownerGuid);
        QueryResult result = accId ? CharacterDatabase.PQuery("SELECT MAX(logout_time) FROM characters WHERE account = {}", accId) : nullptr;

        Field* fields = result ? result->Fetch() : nullptr;
        time_t lastLoginTime = fields ? time_t(fields[0].GetUInt32()) : timeNow;
        baseTimeStamp = lastLoginTime;
    }
    else //if (BotMgr::GetOwnershipExpireMode() == BOT_OWNERSHIP_EXPIRE_HIRE)
    {
        baseTimeStamp = time_t(npcBotData->hire_time);
    }

    //either expired or owner does not exist
    if (timeNow >= baseTimeStamp + expireTime)
    {
        std::string name = "unknown";
        sCharacterCache->GetCharacterNameByGuid(ownerGuid, name);
        TC_LOG_DEBUG("npcbots", "{}'s (guid: {}) ownership over bot {} ({}) has expired!",
            name, npcBotData->owner, me->GetName(), me->GetEntry());

        //send all items back
        CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_NPCBOT_EQUIP_BY_ITEM_INSTANCE);
        //        0            1                2      3         4        5      6             7                 8           9           10    11    12         13
        //"SELECT creatorGuid, giftCreatorGuid, count, duration, charges, flags, enchantments, randomPropertyId, durability, playedTime, text, guid, itemEntry, owner_guid "
        //  "FROM item_instance WHERE guid IN (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)", CONNECTION_SYNCH

        for (uint8 i = 0; i != BOT_INVENTORY_SIZE; ++i)
            stmt->setUInt32(i, npcBotData->equips[i] ? npcBotData->equips[i] : std::numeric_limits<uint32>::max());

        PreparedQueryResult iiresult = CharacterDatabase.Query(stmt);
        if (iiresult)
        {
            std::vector<Item*> items;

            do
            {
                Field* fields2 = iiresult->Fetch();
                uint32 itemGuidLow = fields2[11].GetUInt32();
                uint32 itemId = fields2[12].GetUInt32();
                uint8 item_idx = std::numeric_limits<uint8>::max();

                for (uint8 i = 0; i != BOT_INVENTORY_SIZE; ++i)
                {
                    if (_equips[i] && _equips[i]->GetEntry() == itemId)
                    {
                        item_idx = i;
                        break;
                    }
                }
                if (item_idx >= BOT_INVENTORY_SIZE)
                    TC_LOG_ERROR("npcbots", "bot_ai::CheckOwnerExpiry(): item id {} guid {} not found in bot's inventory!\n{}", itemId, itemGuidLow, me->GetGUID().ToString());

                items.push_back(_equips[item_idx]);
                _removeEquipment(item_idx);

            } while (iiresult->NextRow());

            CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();
            while (!items.empty())
            {
                static const std::string subject = LocalizedNpcText(nullptr, BOT_TEXT_OWNERSHIP_EXPIRED);
                MailDraft draft(subject, "");
                for (uint8 i = 0; !items.empty() && i < MAX_MAIL_ITEMS; ++i)
                {
                    Item* item = items.back();
                    items.pop_back();
                    item->SetOwnerGUID(ownerGuid);
                    item->FSetState(ITEM_CHANGED);
                    item->SaveToDB(trans);
                    draft.AddItem(item);
                }
                draft.SendMailTo(trans, MailReceiver(npcBotData->owner), MailSender(me, MAIL_STATIONERY_GM));
            }
            CharacterDatabase.CommitTransaction(trans);

            for (uint8 slot = BOT_SLOT_MAINHAND; slot <= BOT_SLOT_RANGED; ++slot)
                _resetEquipment(slot, ObjectGuid::Empty);

            BotDataMgr::UpdateNpcBotData(me->GetEntry(), NPCBOT_UPDATE_EQUIPS, _equips);
        }

        //hard reset owner
        _ownerGuid = 0;
        uint32 newOwner = 0;
        BotDataMgr::UpdateNpcBotData(me->GetEntry(), NPCBOT_UPDATE_OWNER, &newOwner);
        //...spec
        uint8 spec = SelectSpecForClass(npcBotExtra->bclass);
        BotDataMgr::UpdateNpcBotData(me->GetEntry(), NPCBOT_UPDATE_SPEC, &spec);
        //...and roles
        uint32 roleMask = DefaultRolesForClass(npcBotExtra->bclass, spec);
        BotDataMgr::UpdateNpcBotData(me->GetEntry(), NPCBOT_UPDATE_ROLES, &roleMask);

        if (Group* gr = GetGroup())
            gr->RemoveMember(me->GetGUID());
    }
}

void bot_ai::InitUnitFlags()
{
    if (BotMgr::DisplayEquipment() == true && CanDisplayNonWeaponEquipmentChanges())
    {
        (const_cast<CreatureTemplate*>(me->GetCreatureTemplate()))->unit_flags2 |= UNIT_FLAG2_MIRROR_IMAGE;
        me->ReplaceAllUnitFlags2(UnitFlags2(me->GetCreatureTemplate()->unit_flags2));
    }
    (const_cast<CreatureMovementData&>(me->GetMovementTemplate())).Chase = CreatureChaseMovementType::CanWalk;
}

void bot_ai::ResetBotAI(uint8 resetType)
{
    //ASSERT(me->IsInWorld());

    _botCommandState = 0;
    _botAwaitState = BOT_AWAIT_NONE;
    _reviveTimer = 0;

    master = reinterpret_cast<Player*>(me);
    if (resetType & BOTAI_RESET_MASK_ABANDON_MASTER)
        _ownerGuid = 0;
    if (resetType == BOTAI_RESET_INIT || resetType == BOTAI_RESET_LOGOUT)
    {
        NpcBotData const* npcBotData = BotDataMgr::SelectNpcBotData(me->GetEntry());
        _checkOwershipTimer = (BotMgr::GetOwnershipExpireTime() && npcBotData->owner) ? (resetType == BOTAI_RESET_INIT) ? 1000 : CalculateOwnershipCheckTime() : 0;
        if (resetType == BOTAI_RESET_INIT)
            homepos.Relocate(me);
        else //if (resetType == BOTAI_RESET_LOGOUT)
            _saveStats();
    }

    if (!IsWanderer() || BotMgr::IsWanderingWorldBot(me))
    {
        (const_cast<CreatureTemplate*>(me->GetCreatureTemplate()))->unit_flags2 |= (UNIT_FLAG2_ALLOW_ENEMY_INTERACT);
        me->ReplaceAllUnitFlags2(UnitFlags2(me->GetCreatureTemplate()->unit_flags2));
    }

    if ((resetType == BOTAI_RESET_DISMISS || resetType == BOTAI_RESET_LOGOUT) && !IsTempBot())
    {
        EnableAllSpells(resetType == BOTAI_RESET_DISMISS);
        InitRoles();
    }

    //me->IsAIEnabled = true;
    canUpdate = true;

    if (spawned)
        ReturnHome();

    if (!me->IsInWorld() || resetType == BOTAI_RESET_FORCERECALL)
    {
        TeleportHomeStart(resetType != BOTAI_RESET_UNBIND);
    }
    else
    {
        _atHome = false;
        spawned = false;
        ResetContestedPvP();
    }
}

bool bot_ai::_checkImmunities(Unit const* target, SpellInfo const* spellInfo) const
{
    return target && spellInfo && !target->IsImmunedToDamage(spellInfo);
}

SpellCastResult bot_ai::CheckBotCast(Unit const* victim, uint32 spellId) const
{
    if (spellId == 0)
        return SPELL_FAILED_DONT_REPORT;

    if (HasBotCommandState(BOT_COMMAND_NO_CAST | BOT_COMMAND_INACTION))
        return SPELL_FAILED_DONT_REPORT;

    if (victim->GetTypeId() == TYPEID_PLAYER && victim->ToPlayer()->IsGameMaster())
        return SPELL_FAILED_BAD_TARGETS;

    SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(spellId);
    if (!spellInfo)
        return SPELL_FAILED_DONT_REPORT;

    spellInfo = spellInfo->TryGetSpellInfoOverride(me);

    if (me->IsMounted() && !(spellInfo->Attributes & SPELL_ATTR0_CASTABLE_WHILE_MOUNTED))
        return SPELL_FAILED_NOT_MOUNTED;

    if (spellInfo->IsChanneled() && HasBotCommandState(BOT_COMMAND_NO_CAST_LONG))
        return SPELL_FAILED_NOT_IDLE;

    if (spellInfo->CastTimeEntry)
    {
        int32 castTime = spellInfo->CastTimeEntry->Base;
        if (castTime > 0)
            ApplyClassSpellCastTimeMods(spellInfo, castTime);

        if (castTime > 0)
        {
            if (HasBotCommandState(BOT_COMMAND_NO_CAST_LONG) || (me->GetMap()->IsDungeon() && !CCed(me, true) && IsWithinAoERadius(*me)))
                return SPELL_FAILED_NOT_IDLE;
        }
    }

    if (int32(me->GetPower(spellInfo->PowerType)) < spellInfo->CalcPowerCost(me, spellInfo->GetSchoolMask()))
        return SPELL_FAILED_NO_POWER;

    if (!IsSpellReady(spellInfo->GetFirstRankSpell()->Id, lastdiff, false))
        return SPELL_FAILED_NOT_READY;

    //if (victim->isType(TYPEMASK_UNIT) && InDuel(victim))
    //    return SPELL_FAILED_BAD_TARGETS;

    if (!CanBotAttackOnVehicle())
        return SPELL_FAILED_CASTER_AURASTATE;

    //forced to follow but not close enough to master
    if (!IAmFree() && !master->GetBotMgr()->GetBotAllowCombatPositioning())
    {
        Position mpos;
        _calculatePos(master, mpos);

        if (me->GetDistance(mpos) > float(std::max<uint8>(5, master->GetBotMgr()->GetBotFollowDist() / 8)))
            return SPELL_FAILED_NOT_IDLE;
    }

    //scaling aura
    if (victim->isType(TYPEMASK_UNIT) && victim != me &&
        !spellInfo->IsPassive() && spellInfo->SpellLevel && !spellInfo->IsChanneled() &&
        (victim->GetLevel() + 10) < int32(spellInfo->GetFirstRankSpell()->SpellLevel))
    {
        for (uint8 i = 0; i < MAX_SPELL_EFFECTS; ++i)
        {
            if (spellInfo->_effects[i].Effect == SPELL_EFFECT_APPLY_AURA && spellInfo->IsPositiveEffect(i))
            {
                //TC_LOG_ERROR("scripts", "CheckBotCast(): deny cast of {} by {} on low-level target {} (lvl {})",
                //    spellInfo->SpellName[0], me->GetName(), victim->GetName(), victim->GetLevel());
                return SPELL_FAILED_LOWLEVEL;
            }
        }
    }

    //disarmed
    if (spellInfo->EquippedItemClass == ITEM_CLASS_WEAPON)
    {
        if (spellInfo->EquippedItemInventoryTypeMask != 0)
        {
            if ((spellInfo->EquippedItemInventoryTypeMask & (1<<INVTYPE_WEAPONMAINHAND)) &&
                !me->CanUseAttackType(BASE_ATTACK))
                return SPELL_FAILED_EQUIPPED_ITEM_CLASS_MAINHAND;
            if ((spellInfo->EquippedItemInventoryTypeMask & (1<<INVTYPE_WEAPONOFFHAND)) &&
                !me->CanUseAttackType(OFF_ATTACK))
                return SPELL_FAILED_EQUIPPED_ITEM_CLASS_OFFHAND;
            if ((spellInfo->EquippedItemInventoryTypeMask & ((1<<INVTYPE_RANGED)|(1<<INVTYPE_RANGEDRIGHT)|(1<<INVTYPE_THROWN))) &&
                !me->CanUseAttackType(RANGED_ATTACK))
                return SPELL_FAILED_EQUIPPED_ITEM_CLASS;
        }
        else if (!me->CanUseAttackType(BASE_ATTACK))
            return SPELL_FAILED_EQUIPPED_ITEM_CLASS_MAINHAND;
    }

    //immunities
    if (victim->isType(TYPEMASK_UNIT))
    {
        if (spellInfo->HasEffect(SPELL_EFFECT_HEAL) || spellInfo->HasAura(SPELL_AURA_PERIODIC_HEAL))
        {
            //banish or something
            Unit::AuraEffectList const& healPctEffects = victim->GetAuraEffectsByType(SPELL_AURA_MOD_HEALING_PCT);
            if (!healPctEffects.empty())
            {
                int32 castTime = spellInfo->CastTimeEntry ? spellInfo->CastTimeEntry->Base : 0;
                if (castTime)
                    ApplyClassSpellCastTimeMods(spellInfo, castTime);
                for (Unit::AuraEffectList::const_iterator itr = healPctEffects.begin(); itr != healPctEffects.end(); ++itr)
                    if ((*itr)->GetAmount() <= -100 && (!castTime || (*itr)->GetBase()->GetDuration() >= castTime))
                        return SPELL_FAILED_BAD_TARGETS;
            }
        }
        else if (//spells that ignore immunities
            spellId != 64382 && //shattering throw
            spellId != 32375 && //mass dispel
            !_checkImmunities(victim, spellInfo))
            return SPELL_FAILED_BAD_TARGETS;
    }

    switch (_botclass)
    {
        case BOT_CLASS_PALADIN:
        case BOT_CLASS_MAGE:
        case BOT_CLASS_PRIEST:
        case BOT_CLASS_DRUID:
        case BOT_CLASS_WARLOCK:
        case BOT_CLASS_SHAMAN:
            if (Feasting() && !master->IsInCombat() && !master->HasAuraType(SPELL_AURA_PERIODIC_DAMAGE))
                return SPELL_FAILED_CANT_DO_THAT_RIGHT_NOW;
            break;
        case BOT_CLASS_WARRIOR: //BladeStorm
        case BOT_CLASS_BM: //BladeStorm PLACEHOLDER
        case BOT_CLASS_ROGUE: //Killing Spree
            if (me->HasAuraType(SPELL_AURA_ALLOW_ONLY_ABILITY))
                return SPELL_FAILED_CANT_DO_THAT_RIGHT_NOW;
            break;
        case BOT_CLASS_HUNTER:
        case BOT_CLASS_DEATH_KNIGHT:
        case BOT_CLASS_SPHYNX:
        case BOT_CLASS_ARCHMAGE:
        case BOT_CLASS_DREADLORD:
        case BOT_CLASS_SPELLBREAKER:
        case BOT_CLASS_DARK_RANGER:
        case BOT_CLASS_NECROMANCER:
        case BOT_CLASS_SEA_WITCH:
        case BOT_CLASS_CRYPT_LORD:
            break;
        default:
            TC_LOG_ERROR("entities.player", "CheckBotCast(): Unknown bot class {}", _botclass);
            break;
    }

    return SPELL_CAST_OK;
}

bool bot_ai::doCast(Unit* victim, uint32 spellId, bool triggered)
{
    return doCast(victim, spellId, triggered ? TRIGGERED_FULL_MASK : TRIGGERED_NONE);
}

bool bot_ai::doCast(Unit* victim, uint32 spellId, TriggerCastFlags flags)
{
    if (spellId == 0) return false;
    if (!victim || !victim->IsInWorld() || me->GetMap() != victim->FindMap()) return false;
    if (IsCasting()) return false;

    m_botSpellInfo = sSpellMgr->GetSpellInfo(spellId);
    if (!m_botSpellInfo)
        return false;

    m_botSpellInfo = m_botSpellInfo->TryGetSpellInfoOverride(me);

    //select aura level
    if (victim->isType(TYPEMASK_UNIT))
    {
        if (SpellInfo const* actualSpellInfo = m_botSpellInfo->GetAuraRankForLevel(victim->GetLevel()))
            m_botSpellInfo = actualSpellInfo;

        if (!m_botSpellInfo->IsTargetingArea())
        {
            uint8 approximateAuraEffectMask = 0;
            uint8 nonAuraEffectMask = 0;
            for (uint8 i = 0; i < MAX_SPELL_EFFECTS; ++i)
            {
                if (m_botSpellInfo->_effects[i].IsAura())
                    approximateAuraEffectMask |= 1 << i;
                else if (m_botSpellInfo->_effects[i].IsEffect())
                    nonAuraEffectMask |= 1 << i;
            }

            for (uint8 i = 0; i < MAX_SPELL_EFFECTS; ++i)
            {
                // check if target already has the same type, but more powerful aura
                if (!nonAuraEffectMask && (approximateAuraEffectMask & (1 << i)))
                    if (!victim->IsHighestExclusiveAuraEffect(m_botSpellInfo, AuraType(m_botSpellInfo->_effects[i].ApplyAuraName),
                        m_botSpellInfo->_effects[i].CalcValue(me, &m_botSpellInfo->_effects[i].BasePoints), approximateAuraEffectMask, false))
                        return false;
            }
        }

        if ((flags & TRIGGERED_FULL_MASK) != TRIGGERED_FULL_MASK &&
            !(m_botSpellInfo->AttributesEx2 & SPELL_ATTR2_CAN_TARGET_NOT_IN_LOS) &&
            !IsInBotParty(victim) && !me->IsWithinLOSInMap(victim, LINEOFSIGHT_ALL_CHECKS, VMAP::ModelIgnoreFlags::M2))
            return false;
    }

    //check wrong spell interruption attempts
    if (/*victim->isType(TYPEMASK_UNIT) && */!HasBotCommandState(BOT_COMMAND_ISSUED_ORDER) &&
        !CastingUnitCheck::CastInterruptionCheck(victim, m_botSpellInfo))
        return false;

    //for debug only
    if (victim->isType(TYPEMASK_UNIT) && victim->isDead())
    {
        if (victim->getDeathState() == DeathState::DEAD)
            TC_LOG_DEBUG("npcbots", "bot_ai::doCast(): {} (bot class {}) tried to cast spell {} on a DEAD target {}", me->GetName(), _botclass, spellId, victim->GetName());
        else if (!(m_botSpellInfo->AttributesEx2 & SPELL_ATTR2_CAN_TARGET_DEAD) &&
            !m_botSpellInfo->HasEffect(SPELL_EFFECT_RESURRECT) &&
            !m_botSpellInfo->HasEffect(SPELL_EFFECT_RESURRECT_NEW) &&
            !m_botSpellInfo->HasEffect(SPELL_EFFECT_SELF_RESURRECT))
            TC_LOG_DEBUG("npcbots", "bot_ai::doCast(): {} (bot class {}) tried to cast spell {} on a CORPSE target {}", me->GetName(), _botclass, spellId, victim->GetName());
        //return false;
    }

    //spells with cast time
    if (me->isMoving() && !(flags & TRIGGERED_CAST_DIRECTLY) && !m_botSpellInfo->IsAutoRepeatRangedSpell() && (m_botSpellInfo->InterruptFlags & SPELL_INTERRUPT_FLAG_MOVEMENT) &&
        !m_botSpellInfo->HasAttribute(SPELL_ATTR0_ON_NEXT_SWING))
    {
        int32 cast_time;
        if (m_botSpellInfo->IsChanneled())
            cast_time = m_botSpellInfo->GetDuration();
        else
        {
            cast_time = int32(m_botSpellInfo->CalcCastTime());
            me->ModSpellCastTime(m_botSpellInfo, cast_time);
        }

        if (cast_time > 0)
        {
            if (!HasBotCommandState(BOT_COMMAND_ISSUED_ORDER))
            {
                if (JumpingOrFalling() || HasBotCommandState(BOT_COMMAND_STAY))
                    return false;
                if (!me->GetVictim() && me->IsInWorld() && (me->GetMap()->IsRaid() || me->GetMap()->IsHeroic()) &&
                    !m_botSpellInfo->HasAura(SPELL_AURA_MOUNTED))
                    return false;
                if (!m_botSpellInfo->HasEffect(SPELL_EFFECT_HEAL) && Rand() > (IAmFree() ? 80 : 50))
                    return false;
            }

            me->BotStopMovement();
        }
    }

    if ((!victim->isType(TYPEMASK_UNIT) || IsInBotParty(victim)) && !victim->IsWithinLOSInMap(me, LINEOFSIGHT_ALL_CHECKS, VMAP::ModelIgnoreFlags::M2) &&
        !HasBotCommandState(BOT_COMMAND_STAY) && !me->GetVehicle())
    {
        if (!IAmFree())
        {
            if (me->GetDistance(victim) > 10.f)
            {
                Position pos = victim->GetPosition();
                //victim->GetPosition(&pos);
                BotMovement(BOT_MOVE_POINT, &pos);
                //me->GetMotionMaster()->MovePoint(me->GetMapId(), pos);
            }
            else
                me->Relocate(victim);
        }
        else
            return false;
    }

    //remove shapeshifts manually to restore powers/stats
    if (me->GetShapeshiftForm() != FORM_NONE)
    {
        if (m_botSpellInfo->CheckShapeshift(me->GetShapeshiftForm()) != SPELL_CAST_OK)
            if (!removeShapeshiftForm())
                return false;
    }

    //CHECKS PASSED, NOW DO IT

    if (me->GetStandState() == UNIT_STAND_STATE_SIT && !(m_botSpellInfo->Attributes & SPELL_ATTR0_CASTABLE_WHILE_SITTING))
    {
        if (!doMana && me->HasInterruptFlag(AURA_INTERRUPT_FLAG_NOT_SEATED))
            UpdateMana();

        feast_health = false;
        feast_mana = false;
        me->SetStandState(UNIT_STAND_STATE_STAND);
    }

    //debug
    //TC_LOG_ERROR("entities.player", "CheckBotCast(): {} ({}) by {} on {}", m_botSpellInfo->SpellName[0], spellId, me->GetName(), victim->GetName());

    bool triggered = !!(flags & TRIGGERED_CAST_DIRECTLY);
    SpellCastTargets targets;
    targets.SetUnitTarget(victim);
    Spell* spell = new Spell(me, m_botSpellInfo, flags);
    spell->prepare(targets); //sets current spell if succeed
/*
    SpellCastResult result = spell->CheckCast(true);
    if (result != SPELL_CAST_OK)
        TC_LOG_ERROR("entities.player", "doCast(): {} ({}) by {} on {} failed with {}",
        m_botSpellInfo->SpellName[0], spellId, me->GetName(), victim->GetName(), uint32(result));
*/
    bool casted = triggered; //triggered casts are casted immediately
    for (uint8 i = 0; i != CURRENT_MAX_SPELL; ++i)
    {
        if (me->GetCurrentSpell(i) == spell)
        {
            casted = true;
            break;
        }
    }

    if (!casted)
    {
        //failed to cast
        if (HasBotCommandState(BOT_COMMAND_ISSUED_ORDER) &&
            !_orders.empty() && _orders.front()._type == BOT_ORDER_SPELLCAST &&
            _orders.front().params.spellCastParams.baseSpell == m_botSpellInfo->GetFirstRankSpell()->Id)
        {
            if (DEBUG_BOT_ORDERS)
                TC_LOG_ERROR("entities.player", "doCast(): ordered spell {} is not casted!", m_botSpellInfo->Id);
            CancelOrder(_orders.front());
        }

        return false;
    }

    if (triggered)
        return true;
    if (m_botSpellInfo->IsPassive() || m_botSpellInfo->IsCooldownStartedOnEvent())
        return true;
    if (!m_botSpellInfo->StartRecoveryCategory || !m_botSpellInfo->StartRecoveryTime)
        return true;

    float gcd = float(m_botSpellInfo->StartRecoveryTime);

    ApplyBotSpellGlobalCooldownMods(m_botSpellInfo, gcd);
    //Apply haste to cooldown
    if (haste && m_botSpellInfo->StartRecoveryCategory == 133 && m_botSpellInfo->StartRecoveryTime == 1500 &&
        m_botSpellInfo->DmgClass != SPELL_DAMAGE_CLASS_MELEE && m_botSpellInfo->DmgClass != SPELL_DAMAGE_CLASS_RANGED &&
        !(m_botSpellInfo->Attributes & (SPELL_ATTR0_REQ_AMMO|SPELL_ATTR0_ABILITY)))
        ApplyBotPercentModFloatVar(gcd, float(haste), false);

    //if cast time is lower than 1.5 sec it also reduces gcd but only if not instant
    if (m_botSpellInfo->CastTimeEntry)
    {
        if (int32 castTime = m_botSpellInfo->CastTimeEntry->Base)
        {
            if (castTime > 0)
            {
                ApplyClassSpellCastTimeMods(m_botSpellInfo, castTime);
                if (castTime < gcd)
                    gcd = float(castTime);
            }
        }
    }

    GC_Timer = uint32(gcd);
    //global cd cannot be less than 1000 ms
    GC_Timer = std::max<uint32>(GC_Timer, 1000);
    //global cd cannot be greater than 1500 ms
    GC_Timer = std::min<uint32>(GC_Timer, 1500);

    return true;
}
//Follow point calculation
void bot_ai::_calculatePos(Unit const* followUnit, Position& pos, float* speed/* = nullptr*/) const
{
    Player const* player = followUnit->ToPlayer();
    uint8 followdist = !player ? BotMgr::GetBotFollowDistMax() / 2 : player->GetBotMgr()->GetBotFollowDist();
    float mydist, angle;

    if (HasRole(BOT_ROLE_TANK) && !IsTank(followUnit))
    {
        uint8 tanks = player != master ? 10 : std::max<uint8>(1, player->GetBotMgr()->GetNpcBotsCountByRole(BOT_ROLE_TANK));
        uint8 slot = player != master ? urand(0, 9) : player->GetBotMgr()->GetNpcBotSlotByRole(BOT_ROLE_TANK, me);
        angle = float(M_PI) / 6.0f; //max bias (left of right) //total arc is angle * 2
        angle = (angle / tanks) * (slot - (slot % 2)); //bias
        if (slot % 2) angle *= -1.f; //bias interchange
        mydist = 3.5f;
    }
    else if (HasRole(BOT_ROLE_RANGED))
    {
        uint8 rangeds = player != master ? 20 : std::max<uint8>(1, player->GetBotMgr()->GetNpcBotsCountByRole(BOT_ROLE_RANGED));
        uint8 slot = player != master ? urand(0, 19) : player->GetBotMgr()->GetNpcBotSlotByRole(BOT_ROLE_RANGED, me);
        angle = float(M_PI) / 3.5f; //max bias (left of right) //total arc is angle * 2
        angle = (angle / rangeds) * (slot - (slot % 2)); //bias
        if (slot % 2) angle *= -1.f; //bias interchange
        angle += float(M_PI); //behind
        mydist = 1.0f;
    }
    else if (HasRole(BOT_ROLE_DPS))
    {
        uint8 dpss = player != master ? 20 : std::max<uint8>(1, player->GetBotMgr()->GetNpcBotsCountByRole(BOT_ROLE_DPS));
        uint8 slot = player != master ? urand(0, 19) : player->GetBotMgr()->GetNpcBotSlotByRole(BOT_ROLE_DPS, me);
        angle = float(M_PI) / 7.5f; //max bias (left of right) //total arc is angle * 2
        angle = (angle / dpss) * (slot); //bias
        if (slot % 2) angle *= -1.f; //bias interchange
        angle += float(((slot % 4) < 2) ? (M_PI/2.f) : -(M_PI/2.f)); //sides
        mydist = 2.0f;
    }
    else
    {
        angle = float((me->GetEntry() % 2) ? (M_PI/2.f) : -(M_PI/2.f));
        mydist = 0.5f;
    }

    mydist += std::max<int32>(int32(followdist) - 30, 5) / 7.f; //1.f-10.f
    mydist = std::max<float>(mydist - 2.f, 0.0f); //get bots closer

    if (me->GetVehicle())
        mydist *= 2.f;

    Position mpos;
    Unit const* bmover = me->GetVehicle() ? me->GetVehicleBase() : me;
    Unit const* mmover = followUnit->GetVehicle() ? followUnit->GetVehicleBase() : followUnit;
    uint32 movFlags = mmover->m_movementInfo.GetMovementFlags();
    float size = bmover->GetCombatReach() * 2;
    if (bmover->CanFly())
    {
        angle += mmover->GetOrientation();
        float &x = mpos.m_positionX, &y = mpos.m_positionY, &z = mpos.m_positionZ;
        bool over = false;
        for (uint8 i = 0; i != 5 + over; ++i)
        {
            if (over)
            {
                mydist *= 0.2f;
                break;
            }
            mmover->GetNearPoint(bmover, x, y, z, mydist, angle);
            if (!followUnit->IsWithinLOS(x,y,z)) //try to get much closer to follow unit
            {
                mydist *= 0.4f - float(i*0.07f);
                size *= 0.1f;
                if (size < 0.1)
                    size = 0.f;
            }
            else
                over = true;
        }
    }
    else
        mpos = mmover->GetFirstCollisionPosition(mydist+size, angle);

    if ((movFlags & MOVEMENTFLAG_FORWARD) && !(movFlags & MOVEMENTFLAG_FALLING_FAR))
    {
        float const aheadDist = std::max<float>(followdist * 0.08f, 6.f);
        float tx = mpos.m_positionX + aheadDist * std::cos(mmover->GetOrientation());
        float ty = mpos.m_positionY + aheadDist * std::sin(mmover->GetOrientation());
        float tz = mpos.m_positionZ;
        if (!bmover->CanFly())
            bmover->UpdateAllowedPositionZ(tx, ty, tz);
        if (mmover->IsWithinLOS(tx, ty, tz))
            mpos.Relocate(tx, ty, tz);
    }

    if (me->GetPositionZ() < mpos.GetPositionZ())
        mpos.m_positionZ += 0.5f; //prevent going underground while moving

    if (speed && !IAmFree() && player == master)
    {
        const float posdist = bmover->GetDistance(mpos);
        if (mmover->IsWalking() || HasBotCommandState(BOT_COMMAND_WALK))
        {
            const float basewalkspeed = bmover->GetSpeed(MOVE_WALK);
            *speed = basewalkspeed;
            if (!HasBotCommandState(BOT_COMMAND_WALK) && posdist > 10.0f && bmover->GetDistance(mmover) > 10.0f)
                *speed = bmover->GetSpeed(MOVE_RUN);
            else if (posdist > 7.5f)
                *speed = basewalkspeed * 1.15f;
        }
        else
        {
            const float baserunspeed = bmover->GetSpeed(MOVE_RUN);
            if (posdist > 50.0f)
                *speed = baserunspeed * 2.0f;
            else if (posdist > 30.0f)
                *speed = baserunspeed * 1.5f;
            else if (posdist > 10.0f)
                *speed = baserunspeed * 1.25f;
        }
    }

    pos.Relocate(mpos);

    //         TTT
    //      m       m
    //     m    M    m
    //      m       m
    //        rrrrr
    //
    //M - master (followUnit)
    //T - bot tank (ROLE_TANK)
    //r - ranged (ROLE_RANGED)
    //m - melee (ROLE_DPS)
}
// Movement set
// Uses MovePoint() for following instead of MoveFollow()
// This helps bots overcome a bug with fanthom walls on grid borders blocking pathing
void bot_ai::BotMovement(BotMovementType type, Position const* pos, Unit* target, bool generatePath, float speed) const
{
    Vehicle* veh = me->GetVehicle();
    VehicleSeatEntry const* seat = veh ? veh->GetSeatForPassenger(me) : nullptr;
    bool canControl = seat ? (seat->Flags & VEHICLE_SEAT_FLAG_CAN_CONTROL) : false;
    Unit* mover = canControl ? veh->GetBase() : !veh ? me : nullptr;
    if (!mover)
        return;

    switch (type)
    {
        case BOT_MOVE_CHASE:
            ASSERT(target);
            mover->GetMotionMaster()->MoveChase(target, {}, ChaseAngle(target->GetRelativeAngle(me), float(target->IsPlayer() ? M_PI * 2.0 : M_PI / 8.0)));
            break;
        case BOT_MOVE_POINT:
            mover->GetMotionMaster()->Add(new PointMovementGenerator<Creature>(1, pos->m_positionX, pos->m_positionY, pos->m_positionZ, generatePath, speed));
            break;
        default:
            TC_LOG_ERROR("scripts", "BotMovement: unhandled bot movement type {}", uint32(type));
            return;
    }
}
bool bot_ai::CanBotMoveVehicle() const
{
    if (VehicleSeatEntry const* seat = me->GetVehicle() ? me->GetVehicle()->GetSeatForPassenger(me) : nullptr)
        return seat->Flags & VEHICLE_SEAT_FLAG_CAN_CONTROL;

    return false;
}
void bot_ai::MoveToSendPosition(Position const& mpos)
{
    EventRemoveBotAwaitState(BOT_AWAIT_SEND);
    if (me->GetExactDist(mpos) <= 70.0f && !CCed(me, true))
    {
        SetBotCommandState(BOT_COMMAND_STAY);
        BotMovement(BOT_MOVE_POINT, &mpos, nullptr, false);
        if (botPet && !CCed(botPet, true))
        {
            botPet->GetBotPetAI()->SetBotCommandState(BOT_COMMAND_STAY);
            botPet->GetMotionMaster()->MovePoint(me->GetMapId(), mpos, false);
        }
        sendlastpos.Relocate(me);
        BotWhisper("Moving to position!");
    }
    else
        BotWhisper("Position is too far away!");
}
void bot_ai::MoveToSendPosition(uint32 point_id)
{
    ASSERT(point_id < MAX_SEND_POINTS);

    MoveToSendPosition(sendpos[point_id]);
}
void bot_ai::MarkSendPosition(uint32 point_id)
{
    ASSERT(point_id < MAX_SEND_POINTS);

    sendpos[point_id].Relocate(me);
}

void bot_ai::SetBotAwaitState(uint8 state)
{
    if (HasBotAwaitState(state))
        return;

    if (!me->IsAlive())
        return;

    _botAwaitState |= state;

    AbortAwaitStateRemoval();
    awaitStateRemEvent = new AwaitStateRemovalEvent(this, state);
    Events.AddEvent(awaitStateRemEvent, Events.CalculateTime(30s));
}

void bot_ai::EventRemoveBotAwaitState(uint8 state)
{
    AbortAwaitStateRemoval();
    RemoveBotAwaitState(state);
}

void bot_ai::AbortAwaitStateRemoval()
{
    if (awaitStateRemEvent)
    {
        if (awaitStateRemEvent->IsActive())
            awaitStateRemEvent->ScheduleAbort();
        awaitStateRemEvent = nullptr;
    }
}

void bot_ai::SetBotCommandState(uint32 st, bool force, Position* newpos, float* speed/* = nullptr*/)
{
    if (!(st & (BOT_COMMAND_UNBIND | BOT_COMMAND_INACTION)))
    {
        if (!me->IsAlive() || JumpingOrFalling())
            return;
    }

    Vehicle* veh = me->GetVehicle();
    VehicleSeatEntry const* seat = veh ? veh->GetSeatForPassenger(me) : nullptr;
    bool canControl = seat ? (seat->Flags & VEHICLE_SEAT_FLAG_CAN_CONTROL) : false;
    Unit* mover = canControl ? veh->GetBase() : !veh ? me : nullptr;
    if (mover)
    {
        if ((st & BOT_COMMAND_FOLLOW) && !IsChanneling() &&
            (force || (!mover->isMoving() && !IsCasting() && master->IsAlive() && !Feasting())))
        {
            if (!me->IsInMap(master)) return;
            if (CCed(mover, true)/* || master->HasUnitState(UNIT_STATE_FLEEING)*/) return;
            float myspeed = 0.0f;
            if (!newpos)
            {
                ASSERT(!IAmFree());
                _calculatePos(master, movepos, &myspeed);
            }
            else
            {
                movepos.m_positionX = newpos->m_positionX;
                movepos.m_positionY = newpos->m_positionY;
                movepos.m_positionZ = newpos->m_positionZ;
            }
            if (me->GetStandState() == UNIT_STAND_STATE_SIT && !Feasting())
                me->SetStandState(UNIT_STAND_STATE_STAND);
            if (IsShootingWand())
                me->InterruptSpell(CURRENT_AUTOREPEAT_SPELL);
            BotMovement(BOT_MOVE_POINT, &movepos, nullptr, true, speed ? *speed : myspeed);
            //me->GetMotionMaster()->MovePoint(master->GetMapId(), pos);
            //me->GetMotionMaster()->MoveFollow(master, mydist, angle);
            RemoveBotCommandState(BOT_COMMAND_STAY | BOT_COMMAND_FULLSTOP | BOT_COMMAND_ATTACK | BOT_COMMAND_COMBATRESET);
        }
        else if (st & BOT_COMMAND_MASK_NOCAST_ANY)
        {
            uint32 removeMask = BOT_COMMAND_MASK_NOCAST_ANY & GetBotCommandState();
            st &= ~removeMask;
            RemoveBotCommandState(removeMask);
            me->InterruptNonMeleeSpells(false);
            if (mover != me->ToUnit())
                mover->InterruptNonMeleeSpells(false);
        }
        else if (st & BOT_COMMAND_INACTION)
        {
            uint32 removeMask = BOT_COMMAND_INACTION & GetBotCommandState();
            st &= ~removeMask;
            RemoveBotCommandState(removeMask | BOT_COMMAND_MASK_NOCAST_ANY | BOT_COMMAND_STAY | BOT_COMMAND_FULLSTOP | BOT_COMMAND_ATTACK | BOT_COMMAND_COMBATRESET);
            me->AttackStop();
            me->InterruptNonMeleeSpells(true);
            if (mover != me->ToUnit())
            {
                mover->AttackStop();
                mover->InterruptNonMeleeSpells(true);
            }
            opponent = nullptr;
        }
        else if (st & BOT_COMMAND_FULLSTOP)
        {
            RemoveBotCommandState(BOT_COMMAND_FOLLOW | BOT_COMMAND_STAY | BOT_COMMAND_ATTACK);
            me->AttackStop();
            me->InterruptNonMeleeSpells(true);
            if (mover != me->ToUnit())
            {
                mover->AttackStop();
                mover->InterruptNonMeleeSpells(true);
            }
            opponent = nullptr;
            if (mover->isMoving())
                mover->ToCreature()->BotStopMovement();
        }
        else if (st & BOT_COMMAND_STAY)
        {
            RemoveBotCommandState(BOT_COMMAND_FOLLOW | BOT_COMMAND_FULLSTOP);
            if (mover->isMoving())
                mover->ToCreature()->BotStopMovement();
        }
        else if (st & BOT_COMMAND_ATTACK)
        {
            RemoveBotCommandState(BOT_COMMAND_FOLLOW);
        }
        else if (st & BOT_COMMAND_COMBATRESET)
        {
            RemoveBotCommandState(BOT_COMMAND_ATTACK);
        }
    }

    _botCommandState |= st;
}

void bot_ai::RemoveBotCommandState(uint32 st)
{
    _botCommandState &= ~st;
}

bool bot_ai::IsPointedTarget(Unit const* target, uint8 targetFlags) const
{
    if (Group const* gr = (IAmFree() ? nullptr : master->GetGroup()))
        if (targetFlags)
            for (uint8 i = 0; i != TARGET_ICONS_COUNT; ++i)
                if (targetFlags & GroupIconsFlags[i])
                    if (target->GetGUID() == gr->GetTargetIcons()[i])
                        return true;

    return false;
}
bool bot_ai::IsPointedHealTarget(Unit const* target) const
{
    return IsPointedTarget(target, BotMgr::GetHealTargetIconFlags());
}
bool bot_ai::IsPointedTankingTarget(Unit const* target) const
{
    return IsPointedTarget(target, BotMgr::GetTankTargetIconFlags());
}
bool bot_ai::IsPointedOffTankingTarget(Unit const* target) const
{
    return IsPointedTarget(target, BotMgr::GetOffTankTargetIconFlags());
}
//unused
bool bot_ai::IsPointedDPSTarget(Unit const* target) const
{
    return IsPointedTarget(target, BotMgr::GetDPSTargetIconFlags());
}
//unused
bool bot_ai::IsPointedRangedDPSTarget(Unit const* target) const
{
    return IsPointedTarget(target, BotMgr::GetRangedDPSTargetIconFlags());
}
bool bot_ai::IsPointedNoDPSTarget(Unit const* target) const
{
    return IsPointedTarget(target, BotMgr::GetNoDPSTargetIconFlags());
}
bool bot_ai::IsPointedAnyAttackTarget(Unit const* target) const
{
    return IsPointedTarget(target, BotMgr::GetOffTankTargetIconFlags() | BotMgr::GetDPSTargetIconFlags() | BotMgr::GetRangedDPSTargetIconFlags());
}
// Buffs And Heal (really)
// Priority as follows: 1) heal players 2) buff players 3) heal bots 4) buff bots
// Priority adjustments to be considered
void bot_ai::BuffAndHealGroup(uint32 diff)
{
    if (GC_Timer > diff) return;
    if (me->IsMounted() && !IsWanderer()) return;
    if (IsCasting() || Feasting()) return;

    if (IAmFree())
    {
        if (BuffTarget(me, diff))
            return;

        if (HealTarget(me, diff))
            return;

        if (me->GetFaction() == 14 || me->HasAura(BERSERK))
            return;

        std::list<Unit*> targets2;
        GetNearbyFriendlyTargetsList(targets2, 30);
        targets2.remove_if(BOTAI_PRED::BuffTargetExclude());
        targets2.remove_if([this](Unit const* unit) {
            return unit->GetTypeId() != TYPEID_PLAYER && !(IsWanderer() && unit->IsNPCBot() && unit->ToCreature()->GetBotAI()->IsWanderer());
        });
        if (!targets2.empty() && BuffTarget(targets2.size() == 1 ? targets2.front() : Trinity::Containers::SelectRandomContainerElement(targets2), diff))
            return;
        for (std::list<Unit*>::const_iterator itr = targets2.begin(); itr != targets2.end(); ++itr)
            if (GetHealthPCT(*itr) < 95 && urand(1, 100) <= (30 + 30*uint32(GetBG() != nullptr)) && HealTarget(*itr, diff))
                break;

        return;
    }

    BotMap const* map;
    Group const* pGroup = master->GetGroup();
    uint8 hppctthreshold = GetHealHpPctThreshold();
    if (!pGroup)
    {
        //heals
        map = master->GetBotMgr()->GetBotMap();
        if (HasRole(BOT_ROLE_HEAL))
        {
            std::list<Unit*> targets3;
            if (master->IsAlive() && !master->HasUnitState(UNIT_STATE_ISOLATED) && GetHealthPCT(master) <= hppctthreshold && me->GetDistance(master) < 40)
                targets3.push_back(master);
            if (master->GetVehicleBase() && !(master->GetVehicleBase()->GetTypeId() == TYPEID_UNIT &&
                master->GetVehicleCreatureBase()->GetCreatureTemplate()->type == CREATURE_TYPE_MECHANICAL) &&
                !master->GetVehicleBase()->HasUnitState(UNIT_STATE_ISOLATED) && GetHealthPCT(master->GetVehicleBase()) <= hppctthreshold &&
                me->GetDistance(master->GetVehicleBase()) < 40)
                targets3.push_back(master->GetVehicleBase());
            for (BotMap::const_iterator itr = map->begin(); itr != map->end(); ++itr)
            {
                Unit* u = itr->second;
                if (!(!u->IsInWorld() || me->GetMap() != u->FindMap() || !u->IsAlive() || u->HasUnitState(UNIT_STATE_ISOLATED) ||
                    u->ToCreature()->IsTempBot() || me->GetDistance(u) > 40 ||
                    (GetHealthPCT(u) > hppctthreshold && !IsTank(u))))
                    targets3.push_back(u);

                u = itr->second->GetBotsPet();

                if (!(!u || !u->IsAlive() || u->HasUnitState(UNIT_STATE_ISOLATED) || me->GetDistance(u) > 40 || GetHealthPCT(u) > hppctthreshold))
                    targets3.push_back(u);

                u = itr->second->GetVehicleBase();
                if (u && !(u->GetTypeId() == TYPEID_UNIT && u->ToCreature()->GetCreatureTemplate()->type == CREATURE_TYPE_MECHANICAL) &&
                    !u->HasUnitState(UNIT_STATE_ISOLATED) && GetHealthPCT(u) <= hppctthreshold && me->GetDistance(u) < 40)
                    targets3.push_back(u);
            }
            for (Unit::ControlList::const_iterator itr = master->m_Controlled.begin(); itr != master->m_Controlled.end(); ++itr)
            {
                Unit* u = *itr;
                if (!u->IsInWorld() || me->GetMap() != u->FindMap() || !u->IsAlive() || u->HasUnitState(UNIT_STATE_ISOLATED) ||
                    u->IsTotem() || u->GetEntry() == SHAMAN_EARTH_ELEMENTAL || me->GetDistance(u) > 40 ||
                    (GetHealthPCT(u) > hppctthreshold && !IsTank(u)))
                    continue;

                targets3.push_back(u);
            }

            if (!targets3.empty() && HealTarget(Trinity::Containers::SelectRandomContainerElement(targets3), diff))
                return;
        }
        //buffs
        std::list<Unit*> targets4;
        if (master->IsAlive() && me->GetDistance(master) < 30)
            targets4.push_back(master);
        for (BotMap::const_iterator itr = map->begin(); itr != map->end(); ++itr)
        {
            Unit* u = itr->second;
            if (!(!u->IsInWorld() || me->GetMap() != u->FindMap() || !u->IsAlive() || u->HasUnitState(UNIT_STATE_ISOLATED) ||
                u->IsTotem() || me->GetDistance(u) > 30))
                targets4.push_back(u);

            //u = itr->second->GetBotsPet();

            //if (!(!u || !u->IsAlive() || u->HasUnitState(UNIT_STATE_ISOLATED) || me->GetDistance(u) > 30))
            //    targets4.push_back(u);
        }
        for (Unit::ControlList::const_iterator itr = master->m_Controlled.begin(); itr != master->m_Controlled.end(); ++itr)
        {
            Unit* u = *itr;
            if (!u || !u->IsPet() || me->GetMap() != u->FindMap() || !u->IsAlive() || u->HasUnitState(UNIT_STATE_ISOLATED) ||
                u->IsTotem() || me->GetDistance(u) > 30) continue;

            targets4.push_back(u);
        }

        if (!targets4.empty() && BuffTarget(Trinity::Containers::SelectRandomContainerElement(targets4), diff))
            return;

        return;
    }
    bool Bots = false;
    //heals
    if (HasRole(BOT_ROLE_HEAL))
    {
        std::list<Unit*> targets5;
        for (GroupReference const* itr = pGroup->GetFirstMember(); itr != nullptr; itr = itr->next())
        {
            Player* tPlayer = itr->GetSource();
            if (tPlayer == nullptr) continue;
            if (me->GetMap() != tPlayer->FindMap()) continue;
            if (tPlayer->HaveBot() && !Bots)
                Bots = true;
            if (!tPlayer->IsAlive() || tPlayer->HasUnitState(UNIT_STATE_ISOLATED)) continue;
            if (me->GetDistance(tPlayer) > 40) continue;
            if (GetHealthPCT(tPlayer) <= hppctthreshold || IsTank(tPlayer))
                targets5.push_back(tPlayer);
            if (tPlayer->GetVehicleBase() && !(tPlayer->GetVehicleBase()->GetTypeId() == TYPEID_UNIT &&
                tPlayer->GetVehicleCreatureBase()->GetCreatureTemplate()->type == CREATURE_TYPE_MECHANICAL) &&
                !tPlayer->GetVehicleBase()->HasUnitState(UNIT_STATE_ISOLATED) && GetHealthPCT(tPlayer->GetVehicleBase()) <= hppctthreshold &&
                me->GetDistance(tPlayer->GetVehicleBase()) < 40)
                targets5.push_back(tPlayer->GetVehicleBase());
        }
        if (Bots)
        {
            for (GroupReference const* itr = pGroup->GetFirstMember(); itr != nullptr; itr = itr->next())
            {
                Player const* tPlayer = itr->GetSource();
                if (tPlayer == nullptr) continue;
                if (me->GetMap() != tPlayer->FindMap()) continue;

                if (tPlayer->HaveBot())
                {
                    map = tPlayer->GetBotMgr()->GetBotMap();
                    for (BotMap::const_iterator bitr = map->begin(); bitr != map->end(); ++bitr)
                    {
                        Unit* u = bitr->second;
                        if (!(!u->IsInWorld() || me->GetMap() != u->FindMap() || !u->IsAlive() || u->HasUnitState(UNIT_STATE_ISOLATED) ||
                            u->ToCreature()->IsTempBot() || me->GetDistance(u) > 40 ||
                            (GetHealthPCT(u) > hppctthreshold && !IsTank(u))))
                            targets5.push_back(u);

                        u = bitr->second->GetBotsPet();

                        if (!(!u || !u->IsAlive() || u->HasUnitState(UNIT_STATE_ISOLATED) || me->GetDistance(u) > 40 || GetHealthPCT(u) > hppctthreshold))
                            targets5.push_back(u);

                        u = bitr->second->GetVehicleBase();
                        if (u && !(u->GetTypeId() == TYPEID_UNIT && u->ToCreature()->GetCreatureTemplate()->type == CREATURE_TYPE_MECHANICAL) &&
                            !u->HasUnitState(UNIT_STATE_ISOLATED) && GetHealthPCT(u) <= hppctthreshold && me->GetDistance(u) < 40)
                            targets5.push_back(u);
                    }
                }
                for (Unit::ControlList::const_iterator bitr = master->m_Controlled.begin(); bitr != master->m_Controlled.end(); ++bitr)
                {
                    Unit* u = *bitr;
                    if (!u || !u->IsInWorld() || me->GetMap() != u->FindMap() || !u->IsAlive() || u->HasUnitState(UNIT_STATE_ISOLATED) ||
                        u->IsTotem() || u->GetEntry() == SHAMAN_EARTH_ELEMENTAL || me->GetDistance(u) > 40 ||
                        (GetHealthPCT(u) > hppctthreshold && !IsTank(u)))
                        continue;

                    targets5.push_back(u);
                }
            }
        }

        //check if we have pointed heal target
        for (uint8 i = 0; i != TARGET_ICONS_COUNT; ++i)
        {
            if (BotMgr::GetHealTargetIconFlags() & GroupIconsFlags[i])
            {
                if (ObjectGuid guid = pGroup->GetTargetIcons()[i])
                {
                    if (Unit* unit = ObjectAccessor::GetUnit(*me, guid))
                    {
                        if (unit->IsAlive() && !unit->HasUnitState(UNIT_STATE_ISOLATED) && me->GetMap() == unit->FindMap() && me->GetDistance(unit) < 40 &&
                            !unit->IsFullHealth() && master->GetVictim() != unit && !IsInBotParty(unit->GetVictim()) &&
                            unit->GetEntry() != SHAMAN_EARTH_ELEMENTAL &&
                            !(unit->GetTypeId() == TYPEID_UNIT && unit->ToCreature()->GetCreatureTemplate()->type == CREATURE_TYPE_MECHANICAL) &&
                            unit->GetReactionTo(master) >= REP_NEUTRAL)
                        {
                            targets5.push_back(unit);
                        }
                    }
                }
            }
        }
        if (!targets5.empty() && HealTarget(Trinity::Containers::SelectRandomContainerElement(targets5), diff))
            return;
    }
    //buffs
    std::list<Unit*> targets6;
    for (GroupReference const* itr = pGroup->GetFirstMember(); itr != nullptr; itr = itr->next())
    {
        Player* tPlayer = itr->GetSource();
        if (tPlayer == nullptr) continue;
        if (me->GetMap() != tPlayer->FindMap()) continue;
        if (tPlayer->HaveBot() && !Bots)
            Bots = true;
        if (!tPlayer->IsAlive() || tPlayer->HasUnitState(UNIT_STATE_ISOLATED)) continue;
        if (me->GetDistance(tPlayer) > 30) continue;
        targets6.push_back(tPlayer);
    }
    if (Bots)
    {
        for (GroupReference const* itr = pGroup->GetFirstMember(); itr != nullptr; itr = itr->next())
        {
            Player const* tPlayer = itr->GetSource();
            if (tPlayer == nullptr) continue;
            if (me->GetMap() != tPlayer->FindMap()) continue;

            if (tPlayer->HaveBot())
            {
                map = tPlayer->GetBotMgr()->GetBotMap();
                for (BotMap::const_iterator bitr = map->begin(); bitr != map->end(); ++bitr)
                {
                    Unit* u = bitr->second;
                    if (!(!u->IsInWorld() || me->GetMap() != u->FindMap() || !u->IsAlive() || u->HasUnitState(UNIT_STATE_ISOLATED) ||
                        u->IsTotem() || me->GetDistance(u) > 30))
                        targets6.push_back(u);

                    //u = bitr->second->GetBotsPet();

                    //if (!(!u || !u->IsAlive() || u->HasUnitState(UNIT_STATE_ISOLATED) || me->GetDistance(u) > 30))
                    //    targets6.push_back(u);
                }
            }
            for (Unit::ControlList::const_iterator bitr = master->m_Controlled.begin(); bitr != master->m_Controlled.end(); ++bitr)
            {
                Unit* u = *bitr;
                if (!u || !u->IsPet() || me->GetMap() != u->FindMap() || !u->IsAlive() || u->HasUnitState(UNIT_STATE_ISOLATED) ||
                    u->IsTotem() || me->GetDistance(u) > 30) continue;

                targets6.push_back(u);
            }
        }
    }

    if (!targets6.empty() && BuffTarget(Trinity::Containers::SelectRandomContainerElement(targets6), diff))
        return;
}
// Attempt to resurrect dead players and bots
// Target is either bot, player or player corpse
// no need to check global cooldown
void bot_ai::ResurrectGroup(uint32 spell_id)
{
    if (!spell_id || Rand() > 10)
        return;

    SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(spell_id);
    ASSERT(spellInfo);
    spellInfo = spellInfo->TryGetSpellInfoOverride(me);
    if (int32(me->GetPower(spellInfo->PowerType)) < spellInfo->CalcPowerCost(me, spellInfo->GetSchoolMask()))
        return;

    //TC_LOG_ERROR("entities.player", "ResurrectGroup by {}", me->GetName());

    if (IAmFree())
    {
        if (me->GetFaction() == 14 || me->HasAura(BERSERK))
            return;

        WorldObject* playerOrCorpse = GetNearbyRezTarget();
        if (!playerOrCorpse)
            return;

        if (!playerOrCorpse->IsWithinLOSInMap(me, LINEOFSIGHT_ALL_CHECKS, VMAP::ModelIgnoreFlags::M2))
            me->Relocate(*playerOrCorpse);

        Unit* target = playerOrCorpse->GetTypeId() == TYPEID_PLAYER ? playerOrCorpse->ToUnit() : (Unit*)playerOrCorpse->ToCorpse();
        if (doCast(target, spell_id)) //rezzing it
        {
            if (Player const* player = playerOrCorpse->GetTypeId() == TYPEID_PLAYER ? playerOrCorpse->ToPlayer() : ObjectAccessor::FindPlayer(playerOrCorpse->ToCorpse()->GetOwnerGUID()))
                BotWhisper(LocalizedNpcText(player, BOT_TEXT_REZZING_YOU), player);
        }

        return;
    }

    Group const* group = master->GetGroup();
    std::vector<Creature*> bottargets;
    BotMap const* map;
    Player* player;
    Unit* target;
    if (!group)
    {
        player = master;
        if (!player->IsAlive() && !player->IsResurrectRequested() && !player->GetUInt32Value(PLAYER_SELF_RES_SPELL))
        {
            target = player->HasFlag(PLAYER_FLAGS, PLAYER_FLAGS_GHOST) ? player->ToUnit() : (Unit*)player->GetCorpse();
            if (target && target->IsInWorld() && me->GetMap() == target->FindMap() &&
                !player->GetBotMgr()->IsBeingResurrected(target))
            {
                if (me->GetDistance(target) > 30 && !HasBotCommandState(BOT_COMMAND_STAY) && !me->GetVehicle())
                {
                    BotMovement(BOT_MOVE_POINT, target);
                    //me->GetMotionMaster()->MovePoint(master->GetMapId(), *target);
                    return;
                }
                else if (me->GetDistance(target) < 15 && !target->IsWithinLOSInMap(me, LINEOFSIGHT_ALL_CHECKS, VMAP::ModelIgnoreFlags::M2))
                    me->Relocate(*target);

                if (doCast(target, spell_id))//rezzing it
                {
                    BotWhisper(LocalizedNpcText(player, BOT_TEXT_REZZING_YOU));
                    return;
                }
            }
        }

        map = player->GetBotMgr()->GetBotMap();
        for (BotMap::const_iterator bitr = map->begin(); bitr != map->end(); ++bitr)
        {
            target = bitr->second;
            if (!target || !target->IsInWorld() || target->IsAlive()) continue;
            if (bitr->second->GetBotAI()->GetReviveTimer() < 15000 || bitr->second->GetBotAI()->GetSelfRezSpell()) continue;
            if (me->GetDistance(target) < 30 && target->IsWithinLOSInMap(me, LINEOFSIGHT_ALL_CHECKS, VMAP::ModelIgnoreFlags::M2) &&
                !player->GetBotMgr()->IsBeingResurrected(target))
                bottargets.push_back(bitr->second);
        }
    }
    else
    {
        bool Bots = false;
        for (GroupReference const* itr = group->GetFirstMember(); itr != nullptr; itr = itr->next())
        {
            player = itr->GetSource();
            target = player;
            if (!player || player->FindMap() != me->GetMap()) continue;
            if (!Bots && player->HaveBot())
                Bots = true;
            if (player->IsAlive() || player->IsResurrectRequested() || player->GetUInt32Value(PLAYER_SELF_RES_SPELL)) continue;
            if (player->HasFlag(PLAYER_FLAGS, PLAYER_FLAGS_GHOST))
                target = (Unit*)player->GetCorpse();
            if (!target || !target->IsInWorld()) continue;
            if (target->GetTypeId() != player->GetTypeId() && me->GetMap() != target->FindMap()) continue;
            if (master->GetBotMgr()->IsBeingResurrected(target)) return;
            if (me->GetDistance(target) > 30 && !HasBotCommandState(BOT_COMMAND_STAY) && !me->GetVehicle())
            {
                if (player == master)
                {
                    BotMovement(BOT_MOVE_POINT, target);
                    //me->GetMotionMaster()->MovePoint(me->GetMapId(), *target);
                    return;
                }
                continue;
            }
            else if (me->GetDistance(target) < 15 && !target->IsWithinLOSInMap(me, LINEOFSIGHT_ALL_CHECKS, VMAP::ModelIgnoreFlags::M2))
                me->Relocate(*target);

            if (doCast(target, spell_id))//rezzing it
            {
                BotWhisper(LocalizedNpcText(player, BOT_TEXT_REZZING_YOU), player);
                if (player != master)
                    BotWhisper(LocalizedNpcText(master, BOT_TEXT_REZZING_) + player->GetName());
                return;
            }
        }

        if (!Bots)
            return;

        for (GroupReference const* itr = group->GetFirstMember(); itr != nullptr; itr = itr->next())
        {
            player = itr->GetSource();
            if (!player || player->FindMap() != me->GetMap() || !player->HaveBot()) continue;

            map = player->GetBotMgr()->GetBotMap();
            for (BotMap::const_iterator bitr = map->begin(); bitr != map->end(); ++bitr)
            {
                target = bitr->second;
                if (!target || !target->IsInWorld() || target->IsAlive()) continue;
                if (bitr->second->GetBotAI()->GetReviveTimer() < 15000 || bitr->second->GetBotAI()->GetSelfRezSpell()) continue;
                if (me->GetDistance(target) < 30 && target->IsWithinLOSInMap(me, LINEOFSIGHT_ALL_CHECKS, VMAP::ModelIgnoreFlags::M2) &&
                    !player->GetBotMgr()->IsBeingResurrected(target))
                    bottargets.push_back(bitr->second);
            }
        }
    }

    //TC_LOG_ERROR("entities.unit", "ResurrectGroup: {} found {} targets", me->GetName(), uint32(bottargets.size()));

    if (bottargets.empty())
        return;

    target = bottargets.size() < 2 ? bottargets.front() : Trinity::Containers::SelectRandomContainerElement(bottargets);

    if (doCast(target, spell_id))
    {
        Player const* targetOwner = target->ToCreature()->GetBotOwner();
        if (targetOwner != master)
        {
            std::string rezstr1 =
                LocalizedNpcText(targetOwner, BOT_TEXT_REZZING_) + target->GetName() + " (" + LocalizedNpcText(targetOwner, BOT_TEXT_YOUR_BOT) + ")";
            std::string rezstr2 =
                LocalizedNpcText(master, BOT_TEXT_REZZING_) + target->GetName() + " (" + targetOwner->GetName() + LocalizedNpcText(master, BOT_TEXT__S_BOT) + ")";

            BotWhisper(std::move(rezstr1), targetOwner);
            BotWhisper(std::move(rezstr2));
        }
        else
            BotWhisper(LocalizedNpcText(master, BOT_TEXT_REZZING_) + target->GetName());

        return;
    }
}
// CURES
//cycle through the group sending members for cure
void bot_ai::CureGroup(uint32 cureSpell, uint32 diff)
{
    if (!cureSpell) return;
    if (GC_Timer > diff) return;
    if (me->IsMounted())
    if (IsTank() && me->GetVictim() && me->GetMap()->IsRaid()) return;
    if (IsCasting()) return;

    if (IAmFree())
    {
        std::list<Unit*> cureTargets;

        if (_canCureTarget(me, cureSpell))
            cureTargets.push_back(me);
        if (botPet && _canCureTarget(botPet, cureSpell))
            cureTargets.push_back(botPet);

        if (!(me->GetFaction() == 14 || me->HasAura(BERSERK)))
        {
            std::list<Unit*> targets1;
            GetNearbyFriendlyTargetsList(targets1, 38);
            for (std::list<Unit*>::const_iterator itr = targets1.begin(); itr != targets1.end(); ++itr)
                if (((*itr)->IsPlayer() || (*itr)->ToPet()) && _canCureTarget(*itr, cureSpell))
                    cureTargets.push_back(*itr);
        }

        if (!cureTargets.empty())
        {
            if (doCast(Trinity::Containers::SelectRandomContainerElement(cureTargets), cureSpell))
                return;
        }

        return;
    }

    if (!master->GetMap()->IsRaid() && Rand() > 35)
        return;

    //TC_LOG_ERROR("entities.player", "{}: CureGroup() on {}", me->GetName(), pTarget->GetName());
    std::list<Unit*> targets;
    Group const* pGroup = master->GetGroup();
    BotMap const* map;
    Unit* u;
    if (!pGroup)
    {
        if (_canCureTarget(master, cureSpell))
            targets.push_back(master);

        map = master->GetBotMgr()->GetBotMap();
        for (BotMap::const_iterator itr = map->begin(); itr != map->end(); ++itr)
        {
            u = itr->second;
            if (!u || !u->IsInWorld() || me->GetMap() != u->FindMap() || !u->IsAlive()) continue;
            if (_canCureTarget(u, cureSpell))
                targets.push_back(u);
        }

        for (Unit::ControlList::const_iterator itr = master->m_Controlled.begin(); itr != master->m_Controlled.end(); ++itr)
        {
            u = *itr;
            if (!u || !u->IsPet() || !u->IsAlive() || me->GetDistance(u) > 30) continue;

            if (_canCureTarget(u, cureSpell))
                targets.push_back(u);
        }
    }
    else
    {
        bool Bots = false;
        for (GroupReference const* itr = pGroup->GetFirstMember(); itr != nullptr; itr = itr->next())
        {
            Player* tPlayer = itr->GetSource();
            if (!tPlayer || (!tPlayer->IsAlive() && !tPlayer->HaveBot())) continue;
            if (!tPlayer->IsInWorld() || tPlayer->IsBeingTeleported()) continue;
            if (me->GetMap() != tPlayer->FindMap()) continue;
            if (!Bots && tPlayer->HaveBot())
                Bots = true;
            if (_canCureTarget(tPlayer, cureSpell))
                targets.push_back(tPlayer);
        }
        if (!Bots) return;
        for (GroupReference const* itr = pGroup->GetFirstMember(); itr != nullptr; itr = itr->next())
        {
            Player* tPlayer = itr->GetSource();
            if (tPlayer == nullptr) continue;
            if (!tPlayer->IsInWorld() || tPlayer->IsBeingTeleported()) continue;
            if (me->GetMap() != tPlayer->FindMap()) continue;

            if (tPlayer->HaveBot())
            {
                map = tPlayer->GetBotMgr()->GetBotMap();
                for (BotMap::const_iterator bitr = map->begin(); bitr != map->end(); ++bitr)
                {
                    u = bitr->second;
                    if (!u || !u->IsInWorld() || me->GetMap() != u->FindMap() || !u->IsAlive()) continue;
                    if (_canCureTarget(u, cureSpell))
                        targets.push_back(u);
                }
            }

            for (Unit::ControlList::const_iterator bitr = tPlayer->m_Controlled.begin(); bitr != tPlayer->m_Controlled.end(); ++bitr)
            {
                u = *bitr;
                if (!u || !u->IsPet() || !u->IsAlive() || me->GetDistance(u) > 30) continue;

                if (_canCureTarget(u, cureSpell))
                    targets.push_back(u);
            }
        }
    }

    if (!targets.empty())
    {
        if (doCast(Trinity::Containers::SelectRandomContainerElement(targets), cureSpell))
            return;
    }
}

// determines if unit has something to cure
bool bot_ai::_canCureTarget(Unit const* target, uint32 cureSpell) const
{
    if (me->GetLevel() < 10 || target->GetLevel() < 10) return false;
    if (target->HasUnitState(UNIT_STATE_ISOLATED)) return false;
    if (target->GetTypeId() == TYPEID_UNIT && target->ToCreature()->IsTempBot()) return false;
    if (target->HasAuraType(SPELL_AURA_MOD_POSSESS) && !IsInBotParty(target)) return false;

    SpellInfo const* info = sSpellMgr->GetSpellInfo(cureSpell);
    if (!info)
        return false;
    info = info->TryGetSpellInfoOverride(me);

    if (me->GetDistance(target) > CalcSpellMaxRange(cureSpell, false))
        return false;

    uint32 dispelMask = 0;
    for (uint8 i = 0; i != MAX_SPELL_EFFECTS; ++i)
        if (info->_effects[i].Effect == SPELL_EFFECT_DISPEL)
            dispelMask |= SpellInfo::GetDispelMask(DispelType(info->_effects[i].MiscValue));

    //SpellBreaker addins
    if (cureSpell == SPELL_STEAL_MAGIC)
        dispelMask |= (1<<DISPEL_MAGIC) | (1<<DISPEL_CURSE);

    if (dispelMask == 0)
        return false;

    std::list<Aura const*> dispel_list;
    _getBotDispellableAuraList(target, dispelMask, dispel_list);

    return !(dispel_list.empty());
}

void bot_ai::_getBotDispellableAuraList(Unit const* target, uint32 dispelMask, std::list<Aura const*> &dispelList) const
{
    //Unholy Blight prevents diseases from being dispelled
    if ((dispelMask & (1<<DISPEL_DISEASE)) &&
        target->GetAuraEffect(SPELL_AURA_PERIODIC_DAMAGE, SPELLFAMILY_DEATHKNIGHT, 1494, 0))
        dispelMask &= ~(1<<DISPEL_DISEASE);

    Unit::AuraMap const& auras = target->GetOwnedAuras();
    for (Unit::AuraMap::const_iterator itr = auras.begin(); itr != auras.end(); ++itr)
    {
        Aura const* aura = itr->second;

        if (aura->IsPassive())
            continue;

        AuraApplication const* aurApp = aura->GetApplicationOfTarget(target->GetGUID());
        if (!aurApp)
            continue;

        if (aura->GetSpellInfo()->GetDispelMask() & dispelMask)
        {
            //do not dispel positive auras from enemies and negative ones from friends
            if (aurApp->IsPositive() == target->IsFriendlyTo(me))
                continue;

            //skip Vampiric Touch to prevent being CCed just heal it out
            if (HasRole(BOT_ROLE_HEAL) && aura->GetSpellInfo()->IsRankOf(sSpellMgr->GetSpellInfo(34914)))
                continue;

            if (((aura->GetSpellInfo()->AttributesEx7 & SPELL_ATTR7_DISPEL_CHARGES) ? aura->GetCharges() : aura->GetStackAmount()) > 0)
                dispelList.push_back(aura);
        }
    }
}
// Check if can cast some spell out of main rotation to use up target's spell reflection charges
// Supposed to check instant non-damaging spells but these checks are not performed (Shaman, Priest)
bool bot_ai::CanRemoveReflectSpells(Unit const* target, uint32 spellId) const
{
    if (!target || !spellId)
        return false;

    if (!target->HasAuraType(SPELL_AURA_REFLECT_SPELLS) && !target->HasAuraType(SPELL_AURA_REFLECT_SPELLS_SCHOOL))
        return false;

    SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(spellId);
    if (!spellInfo)
        return false;
    spellInfo = spellInfo->TryGetSpellInfoOverride(me);

    if (!spellInfo->IsPositive() && spellInfo->DmgClass == SPELL_DAMAGE_CLASS_MAGIC &&
        !(spellInfo->Attributes & SPELL_ATTR0_ABILITY) && !(spellInfo->AttributesEx & SPELL_ATTR1_CANT_BE_REFLECTED) &&
        !(spellInfo->Attributes & SPELL_ATTR0_UNAFFECTED_BY_INVULNERABILITY))
    {
        //bool directDamage = false;
        //for (uint8 i = 0; i != MAX_SPELL_EFFECTS; ++i)
        //{
        //    if (spellInfo->_effects[i].TargetA.GetTarget() == TARGET_UNIT_TARGET_ENEMY)
        //    {
        //        if (spellInfo->_effects[i].IsEffect(SPELL_EFFECT_SCHOOL_DAMAGE) ||
        //            spellInfo->_effects[i].IsAura(SPELL_AURA_PERIODIC_DAMAGE) ||
        //            spellInfo->_effects[i].IsAura(SPELL_AURA_PERIODIC_LEECH) ||
        //            spellInfo->_effects[i].IsAura(SPELL_AURA_MOD_SPEED_SLOW_ALL) ||//Icy Touch
        //            spellInfo->_effects[i].IsAura(SPELL_AURA_HASTE_SPELLS))//Slow
        //        {
        //            directDamage = true;
        //            break;
        //        }
        //    }
        //}
        //if (directDamage)
        //{
            Unit::AuraEffectList const& reflectAuras1 = target->GetAuraEffectsByType(SPELL_AURA_REFLECT_SPELLS);
            for (Unit::AuraEffectList::const_iterator itr = reflectAuras1.begin(); itr != reflectAuras1.end(); ++itr)
            {
                //All existing SPELL_AURA_REFLECT_SPELLS spells have at least amount 50
                if ((*itr)->GetBase()->IsUsingCharges() &&
                    (*itr)->GetBase()->GetCharges() <= target->getAttackers().size() * ((*itr)->GetBase()->GetDuration() / 1000) / 4)
                    return true;
            }

            Unit::AuraEffectList const& reflectAuras2 = target->GetAuraEffectsByType(SPELL_AURA_REFLECT_SPELLS_SCHOOL);
            for (Unit::AuraEffectList::const_iterator itr = reflectAuras2.begin(); itr != reflectAuras2.end(); ++itr)
            {
                if ((*itr)->GetBase()->IsUsingCharges() &&
                    (*itr)->GetAmount() >= 50 && ((*itr)->GetMiscValue() & spellInfo->GetSchoolMask()) &&
                    (*itr)->GetBase()->GetCharges() <= ((*itr)->GetBase()->GetDuration() / 1000) / 4)
                    return true;
            }
        //}
    }

    return false;
}
//LIST AURAS
// Debug: Returns bot's info to called player
void bot_ai::_listAuras(Player const* player, Unit const* unit) const
{
    //if (player->GetSession()->GetSecurity() == SEC_PLAYER) return;
    if (!player->IsGameMaster() && (IAmFree() || !IsInBotParty(player))) return;
    if (!IsInBotParty(unit)) return;
    ChatHandler ch(player->GetSession());
    std::ostringstream botstring;
    botstring.setf(std::ios_base::fixed);
    uint32 const bot_pet_player_class = unit->GetTypeId() == TYPEID_PLAYER ? unit->GetClass() : unit->ToCreature()->GetBotAI()->GetBotClass();
    botstring << unit->GetName() << " (" << LocalizedNpcText(player, BOT_TEXT_CLASS) << ": " << uint32(bot_pet_player_class) << "), ";
    if (unit->GetTypeId() == TYPEID_PLAYER)
        botstring << LocalizedNpcText(player, BOT_TEXT_PLAYER);
    else if (unit->IsNPCBot())
    {
        bot_ai const* ai = unit->ToCreature()->GetBotAI();
        botstring << LocalizedNpcText(player, BOT_TEXT_MASTER) << ": ";
        Player const* owner = ai->GetBotOwner();
        botstring << (owner != unit ? owner->GetName() : LocalizedNpcText(player, BOT_TEXT_NONE));
    }
    uint8 locale = player->GetSession()->GetSessionDbcLocale();
    Unit::AuraMap const &vAuras = unit->GetOwnedAuras();
    for (Unit::AuraMap::const_iterator itr = vAuras.begin(); itr != vAuras.end(); ++itr)
    {
        SpellInfo const* spellInfo = itr->second->GetSpellInfo();
        if (!spellInfo)
            continue;
        spellInfo = spellInfo->TryGetSpellInfoOverride(me);
        uint32 id = spellInfo->Id;
        SpellInfo const* learnSpellInfo = sSpellMgr->GetSpellInfo(spellInfo->_effects[0].TriggerSpell);
        const std::string name = spellInfo->SpellName[locale];
        botstring << "\n" << id << " - |cffffffff|Hspell:" << id << "|h[" << name;
        botstring << ' ' << localeNames[locale] << "]|h|r";
        uint32 talentcost = GetTalentSpellCost(id);
        uint32 rank = 0;
        if (talentcost > 0 && (spellInfo->GetNextRankSpell() || spellInfo->GetPrevRankSpell()))
            rank = talentcost;
        else if (learnSpellInfo && (spellInfo->GetNextRankSpell() || spellInfo->GetPrevRankSpell()))
            rank = spellInfo->GetRank();
        else if (spellInfo->GetNextRankSpell() || spellInfo->GetPrevRankSpell())
            rank = spellInfo->GetRank();
        if (rank > 0)
            botstring << " " << LocalizedNpcText(player, BOT_TEXT_RANK) << " " << rank;
        if (talentcost > 0)
            botstring << " [" << LocalizedNpcText(player, BOT_TEXT_TALENT) << "]";
        if (spellInfo->IsPassive())
            botstring << " [" << LocalizedNpcText(player, BOT_TEXT_PASSIVE) << "]";
        if ((spellInfo->Attributes & SPELL_ATTR0_HIDDEN_CLIENTSIDE) ||
            (spellInfo->AttributesEx & SPELL_ATTR1_DONT_DISPLAY_IN_AURA_BAR))
            botstring << " [" << LocalizedNpcText(player, BOT_TEXT_HIDDEN) << "]";
        if (unit->GetTypeId() == TYPEID_PLAYER && unit->ToPlayer()->HasSpell(id))
            botstring << " [" << LocalizedNpcText(player, BOT_TEXT_KNOWN) << "]";
        else if (unit == me && GetSpell(spellInfo->GetFirstRankSpell()->Id))
            botstring << " [" << LocalizedNpcText(player, BOT_TEXT_ABILITY) << "]";
    }
    botstring.precision(1);
    for (uint8 i = STAT_STRENGTH; i != MAX_STATS; ++i)
    {
        std::string mystat;
        switch (i)
        {
            case STAT_STRENGTH: mystat = LocalizedNpcText(player, BOT_TEXT_STAT_STR); break;
            case STAT_AGILITY: mystat = LocalizedNpcText(player, BOT_TEXT_STAT_AGI); break;
            case STAT_STAMINA: mystat = LocalizedNpcText(player, BOT_TEXT_STAT_STA); break;
            case STAT_INTELLECT: mystat = LocalizedNpcText(player, BOT_TEXT_STAT_INT); break;
            case STAT_SPIRIT: mystat = LocalizedNpcText(player, BOT_TEXT_STAT_SPI); break;
            default: mystat = LocalizedNpcText(player, BOT_TEXT_STAT_UNK); break;
        }
        //ch.PSendSysMessage("base %s: {}", mystat, unit->GetCreateStat(Stats(i));
        float totalstat = unit->GetTotalStatValue(Stats(i));
        //ch.PSendSysMessage("base total %s: {}", mystat, totalstat);
        if (unit == me)
        {
            BotStatMods t = MAX_BOT_ITEM_MOD;
            switch (i)
            {
                case STAT_STRENGTH:     t = BOT_STAT_MOD_STRENGTH;  break;
                case STAT_AGILITY:      t = BOT_STAT_MOD_AGILITY;   break;
                case STAT_STAMINA:      t = BOT_STAT_MOD_STAMINA;   break;
                case STAT_INTELLECT:    t = BOT_STAT_MOD_INTELLECT; break;
                case STAT_SPIRIT:       t = BOT_STAT_MOD_SPIRIT;    break;
                default:                                            break;
            }

            if (t < MAX_BOT_ITEM_MOD)
                totalstat = GetTotalBotStat(t);
        }
        botstring << "\n" << LocalizedNpcText(player, BOT_TEXT_TOTAL) << " " << mystat << ": " << float(totalstat);
    }
    botstring.precision(2);
    botstring << "\n" << LocalizedNpcText(player, BOT_TEXT_MELEE_AP) << ": " << int32(unit->GetTotalAttackPowerValue(BASE_ATTACK));
    botstring << "\n" << LocalizedNpcText(player, BOT_TEXT_RANGED_AP) << ": " << int32(unit->GetTotalAttackPowerValue(RANGED_ATTACK));
    botstring << "\n" << LocalizedNpcText(player, BOT_TEXT_ARMOR) << ": " << uint32(unit->GetArmor());
    botstring << "\n" << LocalizedNpcText(player, BOT_TEXT_CRIT) << ": " << float(unit->GetUnitCriticalChanceDone(BASE_ATTACK));
    botstring << "\n" << LocalizedNpcText(player, BOT_TEXT_DEFENSE) << ": " << uint32(unit->GetDefenseSkillValue());
    botstring << "\n" << LocalizedNpcText(player, BOT_TEXT_MISS) << ": " << float(unit->GetUnitMissChance());
    botstring << "\n" << LocalizedNpcText(player, BOT_TEXT_DODGE) << ": " << float(unit->GetUnitDodgeChance(BASE_ATTACK, me));
    botstring << "\n" << LocalizedNpcText(player, BOT_TEXT_PARRY) << ": " << float(unit->GetUnitParryChance(BASE_ATTACK, me));
    botstring << "\n" << LocalizedNpcText(player, BOT_TEXT_BLOCK) << ": " << float(unit->GetUnitBlockChance(BASE_ATTACK, me));
    botstring << "\n" << LocalizedNpcText(player, BOT_TEXT_BLOCKVALUE) << ": " << uint32(unit->GetShieldBlockValue());
    botstring << "\n" << LocalizedNpcText(player, BOT_TEXT_DMG_TAKEN_MELEE) << ": " << float(dmg_taken_phy * unit->GetTotalAuraMultiplierByMiscMask(SPELL_AURA_MOD_DAMAGE_PERCENT_TAKEN, SPELL_SCHOOL_MASK_NORMAL));
    botstring << "\n" << LocalizedNpcText(player, BOT_TEXT_DMG_TAKEN_SPELL) << ": " << float(dmg_taken_mag * unit->GetTotalAuraMultiplierByMiscMask(SPELL_AURA_MOD_DAMAGE_PERCENT_TAKEN, SPELL_SCHOOL_MASK_MAGIC));

    //float resilience_base = unit->GetMeleeCritChanceReduction();
    //botstring << "\n" << "Resilience pct" << ": -" << resilience_base << " / -" << float(resilience_base * 2.2f) << " / -" << float(resilience_base * 2.0f);

    WeaponAttackType type = BASE_ATTACK;
    float attSpeed = (unit->GetAttackTime(type) * unit->m_modAttackSpeedPct[type])/1000.f;
    botstring << "\n" << LocalizedNpcText(player, BOT_TEXT_DMG_RANGE_MAINHAND) << ": " << LocalizedNpcText(player, BOT_TEXT_MIN) << ": " << int32(unit->GetFloatValue(UNIT_FIELD_MINDAMAGE)) << ", " << LocalizedNpcText(player, BOT_TEXT_MAX) << ": " << int32(unit->GetFloatValue(UNIT_FIELD_MAXDAMAGE) + 1.f);
    botstring << "\n" << LocalizedNpcText(player, BOT_TEXT_DMG_MULT_MAINHAND) << ": " << float(unit->GetPctModifierValue(UNIT_MOD_DAMAGE_MAINHAND, BASE_PCT)*unit->GetPctModifierValue(UNIT_MOD_DAMAGE_MAINHAND, TOTAL_PCT));
    botstring << "\n" << LocalizedNpcText(player, BOT_TEXT_ATTACK_TIME_MAINHAND) << ": " << float(attSpeed)
        << " (" << float(((unit->GetFloatValue(UNIT_FIELD_MINDAMAGE) + unit->GetFloatValue(UNIT_FIELD_MAXDAMAGE)) / 2) / attSpeed) << " " << LocalizedNpcText(player, BOT_TEXT_DPS) << ")";
    if (unit->haveOffhandWeapon())
    {
        type = OFF_ATTACK;
        attSpeed = (unit->GetAttackTime(type) * unit->m_modAttackSpeedPct[type])/1000.f;
        botstring << "\n" << LocalizedNpcText(player, BOT_TEXT_DMG_RANGE_OFFHAND) << ": " << LocalizedNpcText(player, BOT_TEXT_MIN) << ": " << int32(unit->GetFloatValue(UNIT_FIELD_MINOFFHANDDAMAGE)) << ", " << LocalizedNpcText(player, BOT_TEXT_MAX) << ": " << int32(unit->GetFloatValue(UNIT_FIELD_MAXOFFHANDDAMAGE) + 1.f);
        botstring << "\n" << LocalizedNpcText(player, BOT_TEXT_DMG_MULT_OFFHAND) << ": " << float(unit->GetPctModifierValue(UNIT_MOD_DAMAGE_OFFHAND, BASE_PCT)*unit->GetPctModifierValue(UNIT_MOD_DAMAGE_OFFHAND, TOTAL_PCT));
        botstring << "\n" << LocalizedNpcText(player, BOT_TEXT_ATTACK_TIME_OFFHAND) << ": " << float(attSpeed)
            << " (" << float(((unit->GetFloatValue(UNIT_FIELD_MINOFFHANDDAMAGE) + unit->GetFloatValue(UNIT_FIELD_MAXOFFHANDDAMAGE)) / 2) / attSpeed) << " " << LocalizedNpcText(player, BOT_TEXT_DPS) << ")";
    }
    if (unit != me ||
        (me->GetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID + uint32(BOT_SLOT_RANGED)) &&
        _botclass != BOT_CLASS_PALADIN &&
        _botclass != BOT_CLASS_DEATH_KNIGHT &&
        _botclass != BOT_CLASS_DRUID &&
        _botclass != BOT_CLASS_SHAMAN))
    {
        type = RANGED_ATTACK;
        attSpeed = (unit->GetAttackTime(type) * unit->m_modAttackSpeedPct[type])/1000.f;
        botstring << "\n" << LocalizedNpcText(player, BOT_TEXT_DMG_RANGE_RANGED) << ": " << LocalizedNpcText(player, BOT_TEXT_MIN) << ": " << int32(unit->GetFloatValue(UNIT_FIELD_MINRANGEDDAMAGE)) << ", " << LocalizedNpcText(player, BOT_TEXT_MAX) << ": " << int32(unit->GetFloatValue(UNIT_FIELD_MAXRANGEDDAMAGE) + 1.f);
        botstring << "\n" << LocalizedNpcText(player, BOT_TEXT_DMG_MULT_RANGED) << ": " << float(unit->GetPctModifierValue(UNIT_MOD_DAMAGE_RANGED, BASE_PCT)*unit->GetPctModifierValue(UNIT_MOD_DAMAGE_RANGED, TOTAL_PCT));
        botstring << "\n" << LocalizedNpcText(player, BOT_TEXT_ATTACK_TIME_RANGED) << ": " << float(attSpeed)
            << " (" << float(((unit->GetFloatValue(UNIT_FIELD_MINRANGEDDAMAGE) + unit->GetFloatValue(UNIT_FIELD_MAXRANGEDDAMAGE)) / 2) / attSpeed) << " " << LocalizedNpcText(player, BOT_TEXT_DPS) << ")";
    }
    botstring << "\n" << LocalizedNpcText(player, BOT_TEXT_BASE_HP) << ": " << int32(unit->GetCreateHealth());
    botstring << "\n" << LocalizedNpcText(player, BOT_TEXT_TOTAL_HP) << ": " << int32(unit->GetMaxHealth());
    botstring << "\n" << LocalizedNpcText(player, BOT_TEXT_BASE_MP) << ": " << int32(unit->GetCreateMana());
    botstring << "\n" << LocalizedNpcText(player, BOT_TEXT_TOTAL_MP) << ": " << int32(unit->GetMaxPower(POWER_MANA));
    if (unit->GetMaxPower(POWER_MANA) > 1 && unit->GetPowerType() != POWER_MANA)
        botstring << "\n" << LocalizedNpcText(player, BOT_TEXT_CURR_MP) << ": " << int32(unit->GetPower(POWER_MANA));

    if (unit == me)
    {
        botstring << "\n" << LocalizedNpcText(player, BOT_TEXT_SPELLPOWER) << ": " << int32(me->SpellBaseDamageBonusDone(SPELL_SCHOOL_MASK_MAGIC));
        botstring << "\n" << LocalizedNpcText(player, BOT_TEXT_REGEN_HP) << ": " << int32(_getTotalBotStat(BOT_STAT_MOD_HEALTH_REGEN));
        if (me->GetMaxPower(POWER_MANA) > 1)
        {
            botstring << "\n" << LocalizedNpcText(player, BOT_TEXT_REGEN_MP_CAST) << ": " << float((_botclass == BOT_CLASS_SPHYNX ? -1.f : 1.f) * me->GetFloatValue(UNIT_FIELD_POWER_REGEN_INTERRUPTED_FLAT_MODIFIER) * sWorld->getRate(RATE_POWER_MANA) * 5.0f);
            botstring << "\n" << LocalizedNpcText(player, BOT_TEXT_REGEN_MP_NOCAST) << ": " << float((_botclass == BOT_CLASS_SPHYNX ? -1.f : 1.f) * me->GetFloatValue(UNIT_FIELD_POWER_REGEN_FLAT_MODIFIER) * sWorld->getRate(RATE_POWER_MANA) * 5.0f);
        }
        botstring << "\n" << LocalizedNpcText(player, BOT_TEXT_HASTE) << ": " << (haste >= 0 ? "+" : "-") << float(haste) << " " << LocalizedNpcText(player, BOT_TEXT_PCT);
        botstring << "\n" << LocalizedNpcText(player, BOT_TEXT_HIT) << ": +" << float(hit) << " " << LocalizedNpcText(player, BOT_TEXT_PCT);
        botstring << "\n" << LocalizedNpcText(player, BOT_TEXT_EXPERTISE) << ": " << int32(expertise) << " (-" << float(float(expertise) * 0.25f) << " " << LocalizedNpcText(player, BOT_TEXT_PCT) << ")";
        botstring << "\n" << LocalizedNpcText(player, BOT_TEXT_ARMOR_PEN) << ": " << float(me->GetCreatureArmorPenetrationCoef()) << " " << LocalizedNpcText(player, BOT_TEXT_PCT);
        botstring << "\n" << LocalizedNpcText(player, BOT_TEXT_SPELL_PEN) << ": " << uint32(spellpen) + uint32(std::abs(me->GetTotalAuraModifierByMiscMask(SPELL_AURA_MOD_TARGET_RESISTANCE, SPELL_SCHOOL_MASK_MAGIC)));

        for (uint8 i = SPELL_SCHOOL_HOLY; i != MAX_SPELL_SCHOOL; ++i)
        {
            uint32 curresist = me->GetResistance(SpellSchools(i)) + resistbonus[i-1];

            std::string resist;
            switch (i)
            {
                case 1: resist = LocalizedNpcText(player, BOT_TEXT_HOLY);   break;
                case 2: resist = LocalizedNpcText(player, BOT_TEXT_FIRE);   break;
                case 3: resist = LocalizedNpcText(player, BOT_TEXT_NATURE); break;
                case 4: resist = LocalizedNpcText(player, BOT_TEXT_FROST);  break;
                case 5: resist = LocalizedNpcText(player, BOT_TEXT_SHADOW); break;
                case 6: resist = LocalizedNpcText(player, BOT_TEXT_ARCANE); break;
            }
            botstring << "\n" << LocalizedNpcText(player, BOT_TEXT_RESISTANCE) << ": " << resist << ": " << uint32(curresist);
        }

        auto scores = GetBotGearScores();
        botstring << "\nGear score total: " << scores.first << ", avg: " << scores.second;

        botstring << "\n" << LocalizedNpcText(player, BOT_TEXT_COMMAND_STATES) << "(" << GetBotCommandState() << "):";
        if (HasBotCommandState(BOT_COMMAND_FOLLOW))
            botstring << " " << LocalizedNpcText(player, BOT_TEXT_COMMAND_FOLLOW);
        if (HasBotCommandState(BOT_COMMAND_ATTACK))
            botstring << " " << LocalizedNpcText(player, BOT_TEXT_COMMAND_ATTACK);
        if (HasBotCommandState(BOT_COMMAND_STAY))
            botstring << " " << LocalizedNpcText(player, BOT_TEXT_COMMAND_STAY);
        if (HasBotCommandState(BOT_COMMAND_COMBATRESET))
            botstring << " " << LocalizedNpcText(player, BOT_TEXT_COMMAND_RESET);
        if (HasBotCommandState(BOT_COMMAND_FULLSTOP))
            botstring << " " << LocalizedNpcText(player, BOT_TEXT_COMMAND_FULLSTOP);
        if (!IAmFree())
            botstring << "\n" << LocalizedNpcText(player, BOT_TEXT_FOLLOW_DISTANCE) << ": " << uint32(master->GetBotMgr()->GetBotFollowDist());

        if (_botclass < BOT_CLASS_EX_START)
            botstring << "\n" << LocalizedNpcText(player, BOT_TEXT_SPEC) << ": " << uint32(_spec);

        if (IsWanderer())
            botstring << "\n_baseLevel: " << uint32(_baseLevel);

        botstring << "\n" << LocalizedNpcText(player, BOT_TEXT_BOT_ROLEMASK_MAIN) << ": " << uint32(_roleMask & BOT_ROLE_MASK_MAIN);
        botstring << "\n" << LocalizedNpcText(player, BOT_TEXT_BOT_ROLEMASK_GATHERING) << ": " << uint32(_roleMask & BOT_ROLE_MASK_GATHERING);

        botstring << "\n" << LocalizedNpcText(player, BOT_TEXT_PVP_KILLS) << ": " << uint32(_pvpKillsCount) << ", " << LocalizedNpcText(player, BOT_TEXT_PLAYERS) << ": " << uint32(_playerKillsCount) << ", " << LocalizedNpcText(player, BOT_TEXT_TOTAL) << ": " << uint32(_killsCount);
        botstring << "\n" << LocalizedNpcText(player, BOT_TEXT_DIED_) << uint32(_deathsCount) << LocalizedNpcText(player, BOT_TEXT__TIMES);

        //debug
        botstring << "\n_lastWMOAreaId: " << uint32(_lastWMOAreaId);
        botstring << "\nGCD: " << uint32(GC_Timer);
        //botstring << "\nPotion CD: " << uint32(_potionTimer);
        //botstring << "\ncurrent Engage timer: " << GetEngageTimer();
        //for (uint32 i = 0; i != 148; ++i)
        //{
        //    float val = me->GetFloatValue(i);
        //    ch.PSendSysMessage("Float value at %u: {}", i, val);
        //}

        //ch.PSendSysMessage("healTargetIconFlags: %u", healTargetIconFlags);

        //ch.PSendSysMessage("Roles:");
        //for (uint32 i = BOT_MAX_ROLE; i != BOT_ROLE_NONE; i >>= 1)
        //{
        //    if (_roleMask & i)
        //    {
        //        switch (i)
        //        {
        //            case BOT_ROLE_TANK:
        //                ch.PSendSysMessage("BOT_ROLE_TANK");
        //                break;
        //            case BOT_ROLE_DPS:
        //                ch.PSendSysMessage("BOT_ROLE_DPS");
        //                break;
        //            case BOT_ROLE_HEAL:
        //                ch.PSendSysMessage("BOT_ROLE_HEAL");
        //                break;
        //            //case BOT_ROLE_MELEE:
        //            //    ch.PSendSysMessage("BOT_ROLE_MELEE");
        //            //    break;
        //            case BOT_ROLE_RANGED:
        //                ch.PSendSysMessage("BOT_ROLE_RANGED");
        //                break;
        //        }
        //    }
        //}

        //ch.PSendSysMessage("Stat bonuses:");
        //for (uint8 i = 0; i != MAX_BOT_ITEM_MOD; ++i)
        //{
        //    int32 val = 0;
        //    uint32 const a = i;
        //    for (uint8 j = 0; j != BOT_INVENTORY_SIZE; ++j)
        //        val += static_cast<BotStat>(_stats[j])[a];

        //    if (val != 0)
        //        ch.PSendSysMessage("Item mod %u: bonus = %i", i, val);
        //}
    }

    ch.SendSysMessage(botstring.str().c_str());
}
//SetStats
// Health, Armor, Powers, Combat Ratings, and global update setup
void bot_ai::SetStats(bool force)
{
    if (IsTempBot() && !force)
        return;

    shouldUpdateStats = false;

    uint8 myclass = _botclass;
    if (myclass == BOT_CLASS_DRUID && GetBotStance() != BOT_STANCE_NONE)
        myclass = GetBotStance();

    uint8 mylevel = std::min<uint8>(master->GetLevel(), DEFAULT_MAX_LEVEL);
    if (IsWanderer())
    {
        if (_baseLevel == 0) //this only happens once
        {
            mylevel = urand(me->GetCreatureTemplate()->minlevel, me->GetCreatureTemplate()->maxlevel);
            mylevel += BotDataMgr::GetLevelBonusForBotRank(me->GetCreatureTemplate()->rank);
            _baseLevel = std::max<uint8>(mylevel, BotDataMgr::GetMinLevelForBotClass(_botclass));
            if (me->GetMap()->IsBattlegroundOrArena())
                TC_LOG_DEBUG("npcbots", "BG bot {} id {} selected level {}...", me->GetName(), me->GetEntry(), uint32(_baseLevel));
            else
                TC_LOG_DEBUG("npcbots", "Wandering bot {} id {} selected level {}...", me->GetName(), me->GetEntry(), uint32(_baseLevel));
        }
        else if (me->GetMap()->GetEntry()->IsContinent())
        {
            uint8 mapmaxlevel = BotDataMgr::GetMaxLevelForMapId(me->GetMap()->GetEntry()->ID);
            mapmaxlevel += BotDataMgr::GetLevelBonusForBotRank(me->GetCreatureTemplate()->rank);
            //TODO: experience system for levelups
            mylevel = std::max<uint8>(mylevel, std::min<uint8>(_baseLevel + uint8(uint32(float(_killsCount) * BotMgr::GetBotWandererXPGainMod()) / (mylevel * 20)), mapmaxlevel));
        }
    }
    else
        mylevel += BotDataMgr::GetLevelBonusForBotRank(me->GetCreatureTemplate()->rank);

    mylevel = std::min<uint8>(mylevel, DEFAULT_MAX_LEVEL + 3);

    //Do not remove this code
    mylevel = std::max<uint8>(mylevel, BotDataMgr::GetMinLevelForBotClass(_botclass));

    //LEVEL
    if (me->GetLevel() != mylevel)
    {
        if (me->GetLevel() > mylevel)
            UnsummonAll(false);

        me->SetLevel(mylevel);
        force = true; //reinit spells/passives/other
    }
    if (force)
    {
        InitPowers();
        InitSpells(); //this must stay before class passives
        ApplyClassPassives();

        sObjectMgr->GetPlayerClassLevelInfo(GetPlayerClass(), std::min<uint8>(mylevel, DEFAULT_MAX_LEVEL), _classinfo);

        PlayerLevelInfo info;
        sObjectMgr->GetPlayerLevelInfo(GetPlayerRace(), GetPlayerClass(), std::min<uint8>(mylevel, DEFAULT_MAX_LEVEL), &info);
        for (uint8 i = STAT_STRENGTH; i != MAX_STATS; ++i)
            me->SetCreateStat(Stats(i), info.stats[i]);
    }

    switch (myclass)
    {
        case BOT_CLASS_WARRIOR:
        case BOT_CLASS_DEATH_KNIGHT:
        case BOT_CLASS_PALADIN:
        case BOT_CLASS_ROGUE:
        case BOT_CLASS_HUNTER:
        case BOT_CLASS_SHAMAN:
        case BOT_CLASS_DRUID:
        case BOT_CLASS_MAGE:
        case BOT_CLASS_PRIEST:
        case BOT_CLASS_WARLOCK:
        case DRUID_BEAR_FORM:
        case DRUID_CAT_FORM:
        case DRUID_MOONKIN_FORM:
        case DRUID_TREE_FORM:
        case DRUID_TRAVEL_FORM:
        case DRUID_AQUATIC_FORM:
        case DRUID_FLIGHT_FORM:
        case BOT_CLASS_BM:
        case BOT_CLASS_SPHYNX:
        case BOT_CLASS_ARCHMAGE:
        case BOT_CLASS_DREADLORD:
        case BOT_CLASS_SPELLBREAKER:
        case BOT_CLASS_DARK_RANGER:
        case BOT_CLASS_NECROMANCER:
        case BOT_CLASS_SEA_WITCH:
        case BOT_CLASS_CRYPT_LORD:
            break;

        default:
            TC_LOG_ERROR("entities.player", "minion_ai: *etStats():Init - unknown bot class {}, real class: {}, _botclass: {}", myclass, GetPlayerClass(), _botclass);
            break;
    }

    float value;
    float tempval;
    float ap_mod = 1.0f, armor_mod = 1.0f;

    //DAMAGE PHYSICAL
    for (uint8 i = 0; i != MAX_EQUIPMENT_ITEMS; ++i)
    {
        float weap_damage_base_min = _getBotStat(i, BOT_STAT_MOD_DAMAGE_MIN);
        float weap_damage_base_max = _getBotStat(i, BOT_STAT_MOD_DAMAGE_MAX);
        me->SetBaseWeaponDamage(WeaponAttackType(BASE_ATTACK + i), MINDAMAGE, std::max<float>(weap_damage_base_min, 1.f));
        me->SetBaseWeaponDamage(WeaponAttackType(BASE_ATTACK + i), MAXDAMAGE, std::max<float>(weap_damage_base_max, 1.f));
    }

    //Update Attack Time on main hand for shapeshifters
    //do not add me->GetShapeshiftForm() check here, need to change attack time after shapeshift removal too
    if (_botclass == BOT_CLASS_DRUID && RespectEquipsAttackTime())
    {
        uint32 delay;
        SpellShapeshiftFormEntry const* ssEntry = sSpellShapeshiftFormStore.LookupEntry(me->GetShapeshiftForm());
        if (!ssEntry || !ssEntry->CombatRoundTime)
            delay = _equips[BOT_SLOT_MAINHAND] ? _equips[BOT_SLOT_MAINHAND]->GetTemplate()->Delay : me->GetCreatureTemplate()->BaseAttackTime;
        else
            delay = ssEntry->CombatRoundTime;

        me->SetAttackTime(BASE_ATTACK, delay);
    }

    float atpower = float(me->GetLevel() * (/*IAmFree() ? 100 : */3)); //+8000/+240(legit) base ap at 80
    atpower += _getTotalBotStat(BOT_STAT_MOD_ATTACK_POWER);

    float strmult, agimult;
    switch (myclass)
    {
        case BOT_CLASS_WARRIOR:
        case BOT_CLASS_PALADIN:
        case BOT_CLASS_DEATH_KNIGHT:
        case BOT_CLASS_DRUID:
            strmult = 2.f; agimult = 0.f; break;
        case BOT_CLASS_ROGUE:
        case BOT_CLASS_SHAMAN:
            strmult = 1.f; agimult = 1.f; break;
        case BOT_CLASS_HUNTER:
            strmult = 0.5f; agimult = 1.f;break; //until attack power is separated
        case BOT_CLASS_PRIEST:
        case BOT_CLASS_MAGE:
        case BOT_CLASS_WARLOCK:
            strmult = 1.f; agimult = 0.f; break;
        case DRUID_CAT_FORM:
            strmult = 2.f; agimult = 1.f; break;
        case DRUID_BEAR_FORM:
        case DRUID_MOONKIN_FORM:
        case DRUID_TREE_FORM:
        case DRUID_TRAVEL_FORM:
        case DRUID_AQUATIC_FORM:
        case DRUID_FLIGHT_FORM:
            strmult = 2.f; agimult = 0.f; break;
        case BOT_CLASS_BM:
            strmult = 0.f; agimult = 9.f; break;
        case BOT_CLASS_SPHYNX:
            strmult = 2.f; agimult = 0.f; break;
        case BOT_CLASS_ARCHMAGE:
            strmult = 0.f; agimult = 0.f; break;
        case BOT_CLASS_DREADLORD:
            strmult = 8.f; agimult = 0.f; break;
        case BOT_CLASS_SPELLBREAKER:
            strmult = 5.f; agimult = 0.f; break;
        case BOT_CLASS_DARK_RANGER:
            strmult = 0.f; agimult = 4.f; break;
        case BOT_CLASS_NECROMANCER:
            strmult = 0.f; agimult = 0.f; break;
        case BOT_CLASS_SEA_WITCH:
            strmult = 0.f; agimult = 2.f; break;
        case BOT_CLASS_CRYPT_LORD:
            strmult = 9.f; agimult = 0.f; break;
        default:
            TC_LOG_ERROR("entities.player", "_MeleeDamageUpdate(): NIY myclass {}!", uint32(myclass));
            strmult = 0.f; agimult = 0.f; break;
    }

    atpower += (strmult != 0x0) ? strmult * _getTotalBotStat(BOT_STAT_MOD_STRENGTH) : 0.f;
    atpower += (agimult != 0x0) ? agimult * _getTotalBotStat(BOT_STAT_MOD_AGILITY) : 0.f;

    //hunter Expose Weakness checked
    Unit::AuraEffectList const& mAPbyStat = me->GetAuraEffectsByType(SPELL_AURA_MOD_ATTACK_POWER_OF_STAT_PERCENT);
    for (Unit::AuraEffectList::const_iterator i = mAPbyStat.begin(); i != mAPbyStat.end(); ++i)
        atpower += CalculatePct(me->GetStat(Stats((*i)->GetMiscValue())), (*i)->GetAmount());

    atpower += me->GetTotalAuraModifier(SPELL_AURA_MOD_ATTACK_POWER_OF_ARMOR);

    //Unit::AuraEffectList const& mAPbyArmor = me->GetAuraEffectsByType(SPELL_AURA_MOD_ATTACK_POWER_OF_ARMOR);
    //for (Unit::AuraEffectList::const_iterator iter = mAPbyArmor.begin(); iter != mAPbyArmor.end(); ++iter)
    //    atpower += int32(me->GetArmor() / (*iter)->GetAmount());

    //Handle mods
    if (_botclass == BOT_CLASS_DRUID)
    {
        //Heart of the Wild part 3
        if (mylevel >= 35 && myclass == DRUID_CAT_FORM && GetSpec() == BOT_SPEC_DRUID_FERAL)
            ap_mod *= 1.1f;
        //Protector of the Pack part 2
        if (mylevel >= 45 && myclass == DRUID_BEAR_FORM && GetSpec() == BOT_SPEC_DRUID_FERAL)
            ap_mod *= 1.06f;
    }
    if (_botclass == BOT_CLASS_ROGUE)
    {
        //Deadliness
        if (mylevel >= 35 && GetSpec() == BOT_SPEC_ROGUE_SUBTLETY)
            ap_mod *= 1.1f;
        //Savage Combat
        if (mylevel >= 50 && GetSpec() == BOT_SPEC_ROGUE_COMBAT)
            ap_mod *= 1.04f;
    }
    //from stats mods
    if (myclass == DRUID_BEAR_FORM || myclass == DRUID_CAT_FORM)
    {
        atpower += _getTotalBotStat(BOT_STAT_MOD_FERAL_ATTACK_POWER);
        //Predatory Strikes
        if (me->GetLevel() >= 25)
        {
            uint8 slot = BOT_SLOT_MAINHAND;
            atpower += 1.5f * me->GetLevel();
            atpower += 0.2f * (
                _getBotStat(slot, BOT_STAT_MOD_FERAL_ATTACK_POWER)
                + _getBotStat(slot, BOT_STAT_MOD_ATTACK_POWER)
                //+ _getBotStat(slot, BOT_STAT_MOD_RANGED_ATTACK_POWER)
                );
        }
    }
    if (_botclass == BOT_CLASS_HUNTER)
    {
        //Careful Aim
        if (me->GetLevel() >= 15)
            atpower += _getTotalBotStat(BOT_STAT_MOD_INTELLECT);
        //Hunter vs. Wild
        if (me->GetLevel() >= 30 && GetSpec() == BOT_SPEC_HUNTER_SURVIVAL)
            atpower += 0.3f * _getTotalBotStat(BOT_STAT_MOD_STAMINA);
    }
    if (_botclass == BOT_CLASS_SHAMAN)
    {
        //Mental Dexterity
        if (me->GetLevel() >= 30 && GetSpec() == BOT_SPEC_SHAMAN_ENHANCEMENT)
            atpower += _getTotalBotStat(BOT_STAT_MOD_INTELLECT);
    }
    if (_botclass == BOT_CLASS_DARK_RANGER)
    {
        atpower += 2.f * _getTotalBotStat(BOT_STAT_MOD_INTELLECT);
        if (me->GetLevel() >= 60)
            ap_mod *= 1.15f;
    }
    if (_botclass == BOT_CLASS_SEA_WITCH)
    {
        if (me->GetLevel() >= 20)
            atpower += 2.f * _getTotalBotStat(BOT_STAT_MOD_INTELLECT);
        else if (me->GetLevel() >= 10)
            atpower += 1.f * _getTotalBotStat(BOT_STAT_MOD_INTELLECT);
    }

    atpower *= ap_mod;
    me->SetStatFlatModifier(UNIT_MOD_ATTACK_POWER, BASE_VALUE, atpower);

    me->UpdateAttackPowerAndDamage();
    if (_botclass == BOT_CLASS_WARRIOR || _botclass == BOT_CLASS_HUNTER || _botclass == BOT_CLASS_ROGUE ||
        _botclass == BOT_CLASS_MAGE || _botclass == BOT_CLASS_PRIEST || _botclass == BOT_CLASS_WARLOCK ||
        _botclass == BOT_CLASS_DARK_RANGER || _botclass == BOT_CLASS_SEA_WITCH)
    {
        atpower += _getTotalBotStat(BOT_STAT_MOD_RANGED_ATTACK_POWER) * ap_mod;
        me->SetStatFlatModifier(UNIT_MOD_ATTACK_POWER_RANGED, BASE_VALUE, atpower);
        me->UpdateAttackPowerAndDamage(true);
    }

    //ARMOR
    //value = IAmFree() ? 0 : me->GetLevel() * 10; //0/800 at 80
    value = 2.f * _getTotalBotStat(BOT_STAT_MOD_AGILITY);
    value += _getTotalBotStat(BOT_STAT_MOD_ARMOR);

    if (mylevel >= 10)
    {
        //Toughness
        if (mylevel >= 20 && (_botclass == BOT_CLASS_WARRIOR || _botclass == BOT_CLASS_PALADIN || _botclass == BOT_CLASS_DEATH_KNIGHT))
            armor_mod += 0.1f;
        //Frost Presence
        if (GetBotStance() == DEATH_KNIGHT_FROST_PRESENCE)
            armor_mod += 0.6f;
        if (_botclass == BOT_CLASS_DRUID)
        {
            //Thick Hide
            if (mylevel >= 15)
                armor_mod += 0.1f;
            //Survival of the Fittest
            if (myclass == DRUID_BEAR_FORM)
                armor_mod += (GetSpec() == BOT_SPEC_DRUID_FERAL ? 0.33f : 0.0f) + (me->GetShapeshiftForm() == FORM_BEAR ? 1.8f : 3.7f);
            //Moonkin Form innate
            else if (myclass == DRUID_MOONKIN_FORM)
                armor_mod += 3.7f;
            //Improved Tree Form
            else if (myclass == DRUID_TREE_FORM)
                armor_mod += 2.0f;
            //Improved Barkskin
            //else if (myclass == DRUID_TRAVEL_FORM || GetBotStance() == BOT_STANCE_NONE)
            //    armor_mod += 1.6f;
        }
        if (_botclass == BOT_CLASS_HUNTER)
        {
            //Thick Hide
            if (mylevel >= 15)
                armor_mod += 0.1f;
        }
        if (_botclass == BOT_CLASS_MAGE)
        {
            //Arcane Fortitude
            if (mylevel >= 15)
                value += 1.5f * _getTotalBotStat(BOT_STAT_MOD_INTELLECT);
        }
        if (_botclass == BOT_CLASS_SPHYNX)
        {
            value += 5.f * _getTotalBotStat(BOT_STAT_MOD_INTELLECT);
            armor_mod += 0.5f;
        }
        if (_botclass == BOT_CLASS_ARCHMAGE)
        {
            value += 5.f * _getTotalBotStat(BOT_STAT_MOD_INTELLECT);
        }
        if (_botclass == BOT_CLASS_DREADLORD)
        {
            armor_mod += 0.5f;
        }
        if (_botclass == BOT_CLASS_SPELLBREAKER)
        {
            armor_mod += -0.3f; // reduce armor so cannot really tank
        }
        if (_botclass == BOT_CLASS_NECROMANCER)
        {
            value += 5.f * _getTotalBotStat(BOT_STAT_MOD_INTELLECT);
        }
        if (_botclass == BOT_CLASS_CRYPT_LORD)
        {
            armor_mod += mylevel >= 60 ? 1.0f : mylevel >= 40 ? 0.5f : mylevel >= 20 ? 0.25f : 0.125f;
        }
    }

    value *= armor_mod;
    //Druid armor mods should not affect armor from weapons
    if (_botclass == BOT_CLASS_DRUID && _stats[BOT_SLOT_MAINHAND][BOT_STAT_MOD_ARMOR] != 0 && armor_mod > 1.f)
        value -= _stats[BOT_SLOT_MAINHAND][BOT_STAT_MOD_ARMOR] * (armor_mod - 1.f);
    me->SetStatFlatModifier(UNIT_MOD_ARMOR, BASE_VALUE, value);
    me->UpdateArmor(); //buffs will be processed here

    //RESISTANCES
    //Do not store resistance bonuses directly lest we want calcs screwed up
    for (uint8 i = SPELL_SCHOOL_HOLY; i != MAX_SPELL_SCHOOL; ++i)
    {
        value = IAmFree() ? 0 : mylevel;
        value += _getTotalBotStat(BotStatMods(BOT_STAT_MOD_RESIST_HOLY + (i - 1)));

        //res bonuses
        if (_botclass == BOT_CLASS_SPHYNX)
            value += mylevel * 5; //total 498 at 83
        if (_botclass == BOT_CLASS_DREADLORD)
            value += mylevel * 3; //total 332 at 83
        if (_botclass == BOT_CLASS_DARK_RANGER || _botclass == BOT_CLASS_SEA_WITCH || _botclass == BOT_CLASS_CRYPT_LORD)
            value += mylevel * 2; //total 249 at 83

        resistbonus[i-1] = int32(value);
        //me->UpdateResistances(i);
    }

    //DAMAGE TAKEN
    value = 1.0f;
    tempval = 1.0f;

    //class-specified
    //Protector of the Pack part 1
    if (myclass == DRUID_BEAR_FORM && mylevel >= 45)
    {
        value -= 0.12f;
        tempval -= 0.12f;
    }
    //Deadened Nerves
    if (_botclass == BOT_CLASS_ROGUE && mylevel >= 45 && GetSpec() == BOT_SPEC_ROGUE_ASSASINATION)
    {
        value -= 0.06f;
        tempval -= 0.06f;
    }
    //Survival Instincts
    if (_botclass == BOT_CLASS_HUNTER && mylevel >= 15)
    {
        value -= 0.04f;
        tempval -= 0.04f;
    }
    //Spell Warding
    if (_botclass == BOT_CLASS_PRIEST && mylevel >= 15)
        tempval -= 0.1f;
    //Elemental Warding
    if (_botclass == BOT_CLASS_SHAMAN && mylevel >= 15)
    {
        value -= 0.06f;
        tempval -= 0.06f;
    }
    if (_botclass == BOT_CLASS_DEATH_KNIGHT)
    {
        //Magic Suppression (everything)
        if (mylevel >= 60 && GetSpec() == BOT_SPEC_DK_UNHOLY)
            tempval -= 0.06f;
        //Improved Frost Presence
        if (mylevel >= 61 && GetBotStance() == DEATH_KNIGHT_FROST_PRESENCE && GetSpec() == BOT_SPEC_DK_FROST)
        {
            value -= 0.02f;
            tempval -= 0.02f;
        }
    }
    if (_botclass == BOT_CLASS_WARLOCK)
    {
        //Molten Skin
        if (mylevel >= 15)
        {
            value -= 0.06f;
            tempval -= 0.06f;
        }
        //Master Demonologist part 2, Master Demonologist part 4
        if (mylevel >= 35 && GetSpec() == BOT_SPEC_WARLOCK_DEMONOLOGY && botPet && botPet->IsAlive())
        {
            if (GetAIMiscValue(BOTAI_MISC_PET_TYPE) == BOT_PET_VOIDWALKER)
                value -= 0.1f;
            else if (GetAIMiscValue(BOTAI_MISC_PET_TYPE) == BOT_PET_FELHUNTER)
                tempval -= 0.1f;
        }
    }
    //Frozen Core (everything), Prismatic Cloak part 1
    if (_botclass == BOT_CLASS_MAGE)
    {
        if (mylevel >= 30 && GetSpec() == BOT_SPEC_MAGE_FROST)
            tempval -= 0.06f;
        else if (mylevel >= 35 && GetSpec() == BOT_SPEC_MAGE_ARCANE)
        {
            value -= 0.06f;
            tempval -= 0.06f;
        }
    }
    if (_botclass == BOT_CLASS_SPHYNX)
    {
        value -= 0.33f;
        tempval -= 0.33f;
    }
    if (_botclass == BOT_CLASS_ARCHMAGE)
    {
        value -= 0.1f;
        tempval -= 0.35f;
    }
    if (_botclass == BOT_CLASS_DREADLORD)
    {
        value -= 0.15f;
        tempval -= 0.2f;
    }
    if (_botclass == BOT_CLASS_SPELLBREAKER)
    {
        value -= 0.2f;
        tempval -= 0.75f;
    }
    if (_botclass == BOT_CLASS_DARK_RANGER)
    {
        tempval -= 0.35f;
    }
    if (_botclass == BOT_CLASS_NECROMANCER)
    {
        tempval -= 0.2f;
    }
    if (_botclass == BOT_CLASS_SEA_WITCH)
    {
        tempval -= 0.3f;
    }
    if (_botclass == BOT_CLASS_CRYPT_LORD)
    {
        value -= 0.3f;
        tempval -= 0.15f;
    }

    dmg_taken_phy = value;
    dmg_taken_mag = tempval;

    //RESILIENCE
    value = 0.f;

    tempval = std::max<float>(_getTotalBotStat(BOT_STAT_MOD_CRIT_TAKEN_MELEE_RATING), std::max<float>(_getTotalBotStat(BOT_STAT_MOD_CRIT_TAKEN_RANGED_RATING), _getTotalBotStat(BOT_STAT_MOD_CRIT_TAKEN_SPELL_RATING)));
    tempval += me->GetTotalAuraModifierByMiscMask(SPELL_AURA_MOD_RATING, (1 << CR_CRIT_TAKEN_MELEE) | (1 << CR_CRIT_TAKEN_RANGED) | (1 << CR_CRIT_TAKEN_SPELL));
    value += tempval * std::max<float>(_getRatingMultiplier(CR_CRIT_TAKEN_MELEE), std::max<float>(_getRatingMultiplier(CR_CRIT_TAKEN_RANGED), _getRatingMultiplier(CR_CRIT_TAKEN_SPELL)));

    resilience = value;

    //HEALTH
    _OnHealthUpdate();

    //HASTE
    if (haste)
    {
        //unapply old haste
        for (uint8 att = BASE_ATTACK; att != MAX_ATTACK; ++att)
            me->ApplyAttackTimePercentMod(WeaponAttackType(att), float(haste), false);
        me->ApplyCastTimePercentMod(float(haste), false);
    }

    value = IAmFree() ? std::max<int32>(int32(mylevel) - 50, 0) : 0; // +30%/+0% haste at 80

    //25.5 HR = 1% haste at 80
    tempval = _getTotalBotStat(BOT_STAT_MOD_HASTE_MELEE_RATING) + _getTotalBotStat(BOT_STAT_MOD_HASTE_RANGED_RATING) + _getTotalBotStat(BOT_STAT_MOD_HASTE_SPELL_RATING) + _getTotalBotStat(BOT_STAT_MOD_HASTE_RATING);
    tempval += me->GetTotalAuraModifierByMiscMask(SPELL_AURA_MOD_RATING, (1 << CR_HASTE_MELEE) | (1 << CR_HASTE_RANGED) | (1 << CR_HASTE_SPELL));

    if (_botclass == BOT_CLASS_WARLOCK)
    {
        //Spellstone: just emulate the rating bonus
        uint8 ratingBonus;
        if      (mylevel >= 78) ratingBonus = 60;
        else if (mylevel >= 72) ratingBonus = 50;
        else if (mylevel >= 66) ratingBonus = 40;
        else if (mylevel >= 60) ratingBonus = 30;
        else if (mylevel >= 48) ratingBonus = 20;
        else if (mylevel >= 36) ratingBonus = 10;
        else                    ratingBonus = 0;

        //Master Conjuror
        if (mylevel >= 30 && GetSpec() == BOT_SPEC_WARLOCK_DEMONOLOGY)
            ratingBonus *= 4;

        tempval += (float)ratingBonus;
    }

    value += tempval * ((_botclass == BOT_CLASS_HUNTER || _botclass == BOT_CLASS_DARK_RANGER || _botclass == BOT_CLASS_SEA_WITCH) ?
        _getRatingMultiplier(CR_HASTE_RANGED) :
        std::max<float>(_getRatingMultiplier(CR_HASTE_MELEE), _getRatingMultiplier(CR_HASTE_SPELL)));

    //class-specific
    if (_botclass == BOT_CLASS_HUNTER)
    {
        value += 15.f; //innate ranged haste bonus 15% for hunters (still applies to all haste types)
        //Serpent's Swiftness
        if (mylevel >= 45 && GetSpec() == BOT_SPEC_HUNTER_BEASTMASTERY)
            value += 20.f;
    }
    if (_botclass == BOT_CLASS_ROGUE)
    {
        //Lightning Reflexes part 2
        if (mylevel >= 25 && GetSpec() == BOT_SPEC_ROGUE_COMBAT)
            value += 10.f;
    }
    if (_botclass == BOT_CLASS_PRIEST)
    {
        //Enlightenment part 2
        if (mylevel >= 35 && GetSpec() == BOT_SPEC_PRIEST_DISCIPLINE)
            value += 6.f;
    }
    if (_botclass == BOT_CLASS_MAGE)
    {
        //Netherwind Presence
        if (mylevel >= 55 && GetSpec() == BOT_SPEC_MAGE_ARCANE)
            value += 6.f;
    }
    if (_botclass >= BOT_CLASS_EX_START)
    {
        float haste_per_lvl;
        switch (_botclass)
        {
            case BOT_CLASS_BM:
            case BOT_CLASS_DREADLORD:
                haste_per_lvl = 0.875f;
                break;
            case BOT_CLASS_ARCHMAGE:
            case BOT_CLASS_DARK_RANGER:
            case BOT_CLASS_SEA_WITCH:
                haste_per_lvl = 0.5f;
                break;
            case BOT_CLASS_CRYPT_LORD:
                haste_per_lvl = 0.35f;
                break;
            default:
                haste_per_lvl = 0.25f;
                break;
        }
        value += mylevel * haste_per_lvl;
    }

    haste = int32(value);

    if (haste)
    {
        //apply new haste (using truncated value - gonna need it for unapply on next SetStats)
        for (uint8 att = BASE_ATTACK; att != MAX_ATTACK; ++att)
            me->ApplyAttackTimePercentMod(WeaponAttackType(att), float(haste), true);
        me->ApplyCastTimePercentMod(float(haste), true);
    }

    //HIT
    if (CanMiss())
    {
        value = IAmFree() ? mylevel / 8 : 0; // +10%/+0% at 80
        //32.5 HR = 1% hit at 80
        tempval = _getTotalBotStat(BOT_STAT_MOD_HIT_MELEE_RATING) + _getTotalBotStat(BOT_STAT_MOD_HIT_RANGED_RATING) + _getTotalBotStat(BOT_STAT_MOD_HIT_SPELL_RATING) + _getTotalBotStat(BOT_STAT_MOD_HIT_RATING);
        tempval += me->GetTotalAuraModifierByMiscMask(SPELL_AURA_MOD_RATING, (1 << CR_HIT_MELEE) | (1 << CR_HIT_RANGED) | (1 << CR_HIT_SPELL));
        value += tempval * (_botclass == BOT_CLASS_HUNTER ? _getRatingMultiplier(CR_HIT_RANGED) : std::max<float>(_getRatingMultiplier(CR_HIT_MELEE), _getRatingMultiplier(CR_HIT_SPELL)));

        //class-specific
        //Precision
        if (_botclass == BOT_CLASS_ROGUE && mylevel >= 15)
            value += 5.f;
        //Enlightened Judgements part 2,3
        if (_botclass == BOT_CLASS_PALADIN && GetSpec() == BOT_SPEC_PALADIN_HOLY && mylevel >= 55)
            value += 4.f;
        //Virulence part 1, Nerves of Cold Steel part 1
        if (_botclass == BOT_CLASS_DEATH_KNIGHT)
            value += 3.f;
        //Dual Wield Specialization
        if (_botclass == BOT_CLASS_SHAMAN && mylevel >= 40 && me->haveOffhandWeapon())
            value += 6.f;
        //Precision
        if (_botclass == BOT_CLASS_WARRIOR && mylevel >= 30 && GetSpec() == BOT_SPEC_WARRIOR_FURY)
            value += 3.f;
        //Focused Aim
        if (_botclass == BOT_CLASS_HUNTER && mylevel >= 10)
            value += 3.f;
        //Shadow Focus part 1
        if (_botclass == BOT_CLASS_PRIEST && mylevel >= 15)
            value += 3.f;
        //Arcane Focus part 1, Precision part 2
        if (_botclass == BOT_CLASS_MAGE && mylevel >= 10)
            value += mylevel >= 15 ? 6.f : 3.f;
        //Suppression
        if (_botclass == BOT_CLASS_WARLOCK && mylevel >= 10)
            value += 3.f;

        hit = value;
    }
    else
        hit = 100.0f;

    //ARMOR PENETRATION
    value = IAmFree() ? 5 + mylevel / 4 : 0; // 25%/0% at 80
    //? APR = 1% armor ignored at 80
    tempval = _getTotalBotStat(BOT_STAT_MOD_ARMOR_PENETRATION_RATING);
    tempval += me->GetTotalAuraModifierByMiscMask(SPELL_AURA_MOD_RATING, (1 << CR_ARMOR_PENETRATION));
    value += tempval * _getRatingMultiplier(CR_ARMOR_PENETRATION);

    //class-specific
    //Blood Gorged
    if (_botclass == BOT_CLASS_DEATH_KNIGHT && mylevel >= 64 && GetSpec() == BOT_SPEC_DK_BLOOD)
        value += 10.f;

    if (_botclass == BOT_CLASS_DARK_RANGER)
        value += 50.f;

    armor_pen = value;

    //EXPERTISE
    value = IAmFree() ? mylevel / 2 : 0; // -10%/-0% at 80
    //~8.0 ER = 1 expertise at 80
    tempval = _getTotalBotStat(BOT_STAT_MOD_EXPERTISE_RATING);
    tempval += me->GetTotalAuraModifierByMiscMask(SPELL_AURA_MOD_RATING, (1 << CR_EXPERTISE));
    value += tempval * _getRatingMultiplier(CR_EXPERTISE);

    //class-specific
    //Weapon Expertise
    if (mylevel >= 35 && _botclass == BOT_CLASS_ROGUE && GetSpec() == BOT_SPEC_ROGUE_COMBAT)
        value += 10.f;
    //Combat Expertise
    if (mylevel >= 45 && _botclass == BOT_CLASS_PALADIN && GetSpec() == BOT_SPEC_PALADIN_PROTECTION)
        value += 6.f;
    if (_botclass == BOT_CLASS_WARRIOR)
    {
        //Vitality: 6, Strength of Arms: 4
        if (mylevel >= 45 && GetSpec() == BOT_SPEC_WARRIOR_PROTECTION)
            value += 10.f;
        else if (mylevel >= 40 && GetSpec() == BOT_SPEC_WARRIOR_ARMS)
            value += 4.f;
    }
    if (_botclass == BOT_CLASS_DEATH_KNIGHT)
    {
        //Tundra Stalker, Rage of Rivendare: 5
        //Veteral of the Third War part 3: 6
        if (mylevel >= 64 && GetSpec() == BOT_SPEC_DK_FROST)
            value += 5.f;
        else if (mylevel >= 64 && GetSpec() == BOT_SPEC_DK_UNHOLY)
            value += 5.f;
        else if (mylevel >= 59 && GetSpec() == BOT_SPEC_DK_BLOOD)
            value += 6.f;
    }
    if (_botclass == BOT_CLASS_DREADLORD)
    {
        value += 40.f;
    }
    if (_botclass == BOT_CLASS_CRYPT_LORD)
    {
        value += 20.f;
    }

    expertise = value;

    //CRIT
    if (CanCrit())
    {
        value = IAmFree() ? mylevel / 4 : 0; // +20%/+0% at 80
        tempval = value;

        GtChanceToMeleeCritBaseEntry const* critBaseMelee  = sGtChanceToMeleeCritBaseStore.LookupEntry(GetPlayerClass()-1);
        GtChanceToMeleeCritEntry const* critRatioMelee = sGtChanceToMeleeCritStore.LookupEntry((GetPlayerClass()-1)*GT_MAX_LEVEL + mylevel-1);
        if (critBaseMelee && critRatioMelee)
            value += (critBaseMelee->Data + _getTotalBotStat(BOT_STAT_MOD_AGILITY) * critRatioMelee->Data) * 100.0f;

        //crit from intellect
        GtChanceToSpellCritBaseEntry const* critBaseSpell  = sGtChanceToSpellCritBaseStore.LookupEntry(GetPlayerClass()-1);
        GtChanceToSpellCritEntry const* critRatioSpell = sGtChanceToSpellCritStore.LookupEntry((GetPlayerClass()-1)*GT_MAX_LEVEL + mylevel-1);
        if (critBaseSpell && critRatioSpell)
            tempval += (critBaseSpell->Data + _getTotalBotStat(BOT_STAT_MOD_INTELLECT) * critRatioSpell->Data) * 100.f;

        value = std::max<float>(value, tempval);

        //45 CR = 1% crit at 80
        tempval = _getTotalBotStat(BOT_STAT_MOD_CRIT_MELEE_RATING) + _getTotalBotStat(BOT_STAT_MOD_CRIT_RANGED_RATING) + _getTotalBotStat(BOT_STAT_MOD_CRIT_SPELL_RATING) + _getTotalBotStat(BOT_STAT_MOD_CRIT_RATING);
        tempval += me->GetTotalAuraModifierByMiscMask(SPELL_AURA_MOD_RATING, (1 << CR_CRIT_MELEE) | (1 << CR_CRIT_RANGED) | (1 << CR_CRIT_SPELL));

        //Molten Armor: 35% spirit to crit rating (+40% double-glyphed + 15% T9P2 bonus)
        if (_botclass == BOT_CLASS_MAGE && me->HasAuraTypeWithFamilyFlags(SPELL_AURA_MOD_RATING_FROM_STAT, SPELLFAMILY_MAGE, 0x40000))
            tempval += _getTotalBotStat(BOT_STAT_MOD_SPIRIT) * (mylevel >= 80 ? 0.9f : mylevel >= 70 ? 0.75f : 0.55f);
        //Firestone: just emulate the rating bonus
        if (_botclass == BOT_CLASS_WARLOCK)
        {
            uint8 ratingBonus;
            if      (mylevel >= 80) ratingBonus = 49;
            else if (mylevel >= 74) ratingBonus = 42;
            else if (mylevel >= 66) ratingBonus = 35;
            else if (mylevel >= 56) ratingBonus = 28;
            else if (mylevel >= 46) ratingBonus = 21;
            else if (mylevel >= 36) ratingBonus = 14;
            else if (mylevel >= 28) ratingBonus = 7;
            else                    ratingBonus = 0;

            //Master Conjuror
            if (mylevel >= 30 && GetSpec() == BOT_SPEC_WARLOCK_DEMONOLOGY)
                ratingBonus *= 4;

            tempval += (float)ratingBonus;
        }

        value += tempval * (_botclass == BOT_CLASS_HUNTER ? _getRatingMultiplier(CR_CRIT_RANGED) : std::max<float>(_getRatingMultiplier(CR_CRIT_MELEE), _getRatingMultiplier(CR_CRIT_SPELL)));

        //common crit talents
        if (mylevel >= 10 &&
            (_botclass != BOT_CLASS_MAGE && _botclass != BOT_CLASS_PRIEST &&
            _botclass != BOT_CLASS_DRUID && _botclass != BOT_CLASS_WARLOCK))
            value += 5.f;

        //class-specific
        if (_botclass == BOT_CLASS_DRUID)
        {
            //Sharpened Claws
            if (mylevel >= 20 && (myclass == DRUID_CAT_FORM || myclass == DRUID_BEAR_FORM))
                value += 6.f;
        }
        if (_botclass == BOT_CLASS_ROGUE)
        {
            //Close Quarters Combat
            if (mylevel >= 20)
            {
                if (Item const* mainhand = _equips[BOT_SLOT_MAINHAND])
                {
                    if (mainhand->GetTemplate()->Class == ITEM_CLASS_WEAPON &&
                        (mainhand->GetTemplate()->SubClass == ITEM_SUBCLASS_WEAPON_DAGGER ||
                        mainhand->GetTemplate()->SubClass == ITEM_SUBCLASS_WEAPON_FIST_WEAPON))
                        value += 5.f;
                }
            }
        }
        if (_botclass == BOT_CLASS_PALADIN)
        {
            //Sanctity of Battle part 1
            if (mylevel >= 25 && GetSpec() == BOT_SPEC_PALADIN_RETRIBUTION)
                value += 3.f;
            //Combat Expertise
            if (mylevel >= 45 && GetSpec() == BOT_SPEC_PALADIN_PROTECTION)
                value += 6.f;
        }
        if (_botclass == BOT_CLASS_HUNTER)
        {
            //Killer Instinct
            if (mylevel >= 30 && GetSpec() == BOT_SPEC_HUNTER_BEASTMASTERY)
                value += 3.f;
            //Master Marksman
            if (mylevel >= 45 && GetSpec() == BOT_SPEC_HUNTER_MARKSMANSHIP)
                value += 5.f;
        }
        if (_botclass == BOT_CLASS_PRIEST)
        {
            //Focused Will part 1
            if (mylevel >= 40 && GetSpec() == BOT_SPEC_PRIEST_DISCIPLINE)
                value += 3.f;
        }
        if (_botclass == BOT_CLASS_DEATH_KNIGHT)
        {
            //Annihilation part 1
            if (mylevel >= 57)
                value += 3.f;
        }
        if (_botclass == BOT_CLASS_WARLOCK)
        {
            //Backlash
            if (mylevel >= 30)
                value += 3.f;
            //Demonic Tactics part 1, part 2 (me)
            if (mylevel >= 45 && GetSpec() == BOT_SPEC_WARLOCK_DEMONOLOGY)
                value += 10.f;
        }
        if (_botclass == BOT_CLASS_MAGE)
        {
            //Arcane Instability part 2
            if (mylevel >= 35 && GetSpec() == BOT_SPEC_MAGE_ARCANE)
                value += 3.f;
        }
        if (_botclass == BOT_CLASS_DREADLORD)
        {
            value = value * 2.f;
        }
        if (_botclass == BOT_CLASS_DARK_RANGER)
        {
            value += 20.f;
        }

        if (BotMgr::IsBotStatsLimitsEnabled())
            crit = std::min<float>(value, BotMgr::GetBotStatLimitCrit());
        else
            crit = value;

        if (crit < 0.0f)
            crit = 0.0f;
    }
    else
        crit = 0.0f;

    //DEFENSE
    value = 0.f;
    tempval = _getTotalBotStat(BOT_STAT_MOD_DEFENSE_SKILL_RATING);
    tempval += me->GetTotalAuraModifierByMiscMask(SPELL_AURA_MOD_RATING, (1 << CR_DEFENSE_SKILL));
    value += tempval * _getRatingMultiplier(CR_DEFENSE_SKILL);
    value += me->GetTotalAuraModifierByMiscValue(SPELL_AURA_MOD_SKILL, SKILL_DEFENSE);
    defense = mylevel * 5 + uint32(value); //truncate

    float defbonus = defense - mylevel * 5; //difference

    //PARRY
    if (CanParry())
    {
        value = 5.0f + (IAmFree() ? mylevel / 8 : 0); // +10%/+0% at 80

        if (mylevel >= 10)
        {
            //67 PR = 1% parry at 80
            tempval = _getTotalBotStat(BOT_STAT_MOD_PARRY_RATING);
            tempval += me->GetTotalAuraModifierByMiscMask(SPELL_AURA_MOD_RATING, (1 << CR_PARRY));

            //Forceful Deflection: 25% of strength goes to parry rating
            if (_botclass == BOT_CLASS_DEATH_KNIGHT/* && mylevel >= 55*/)
                tempval += _getTotalBotStat(BOT_STAT_MOD_STRENGTH) * 0.25f;

            value += tempval * _getRatingMultiplier(CR_PARRY);
            //125 DR = 1% block/parry/dodge at 80
            value += defbonus * 0.04f;
        }

        //Deflection (general)
        if ((_botclass == BOT_CLASS_WARRIOR || _botclass == BOT_CLASS_ROGUE || _botclass == BOT_CLASS_PALADIN) && mylevel >= 10)
            value += 5.0f;
        if (_botclass == BOT_CLASS_HUNTER && mylevel >= 20)
            value += 3.f;

        if (_botclass == BOT_CLASS_SEA_WITCH)
            value += 25.f;

        if (BotMgr::IsBotStatsLimitsEnabled())
            parry = std::min<float>(value, BotMgr::GetBotStatLimitParry());
        else
            parry = value;

        if (parry < 0.0f)
            parry = 0.0f;
    }
    else
        parry = 0.0f;

    //DODGE
    if (CanDodge())
    {
        value = 5.0f + (IAmFree() ? mylevel / 8 : 0); // +10%/+0% at 80

        if (GtChanceToMeleeCritEntry  const* dodgeRatio = sGtChanceToMeleeCritStore.LookupEntry((GetPlayerClass()-1)*GT_MAX_LEVEL + mylevel-1))
            value += _getTotalBotStat(BOT_STAT_MOD_AGILITY) * dodgeRatio->Data * 100.0f;

        if (mylevel >= 10)
        {
            //53 DR = 1% dodge at 80
            tempval = _getTotalBotStat(BOT_STAT_MOD_DODGE_RATING);
            tempval += me->GetTotalAuraModifierByMiscMask(SPELL_AURA_MOD_RATING, (1 << CR_DODGE));
            value += tempval * _getRatingMultiplier(CR_DODGE);
            //125 DR = 1% block/parry/dodge at 80
            value += defbonus * 0.04f;
        }

        //evasion, anticipation (general)
        if ((_botclass == BOT_CLASS_WARRIOR || _botclass == BOT_CLASS_ROGUE || _botclass == BOT_CLASS_PALADIN ||
            _botclass == BOT_CLASS_DEATH_KNIGHT || _botclass == BOT_CLASS_SHAMAN) && mylevel >= 15)
            value += 5.0f;

        //class-specific
        if (_botclass == BOT_CLASS_DRUID)
        {
            //Feral Swiftness
            if (mylevel >= 20 && (myclass == DRUID_CAT_FORM || myclass == DRUID_BEAR_FORM))
                value += 4.f;
        }

        if (_botclass == BOT_CLASS_DARK_RANGER)
        {
            //base dodge 30%
            value += 30.f;
        }

        if (_botclass == BOT_CLASS_SEA_WITCH && IsInContactWithWater())
        {
            //TC_LOG_ERROR("scripts", "BOT_CLASS_SEA_WITCH dodge: {} now in water", me->GetName());
            value += 50.f;
        }

        if (BotMgr::IsBotStatsLimitsEnabled())
            dodge = std::min<float>(value, BotMgr::GetBotStatLimitDodge());
        else
            dodge = value;

        if (dodge < 0.0f)
            dodge = 0.0f;
    }
    else
        dodge = 0.0f;

    //BLOCK
    if (IsBlockingClass(_botclass))
    {
        value = 5.0f + (IAmFree() ? mylevel / 4 : 0); // +20%/+0% at 80

        //16.5 BR = 1% block at 80
        tempval = _getTotalBotStat(BOT_STAT_MOD_BLOCK_RATING);
        tempval += me->GetTotalAuraModifierByMiscMask(SPELL_AURA_MOD_RATING, (1 << CR_BLOCK));
        value += tempval * _getRatingMultiplier(CR_BLOCK);
        //125 DR = 1% block/parry/dodge at 80
        value += defbonus * 0.04f;

        //base block chance is capped at 75%
        if (BotMgr::IsBotStatsLimitsEnabled())
            block = std::min<float>(value, BotMgr::GetBotStatLimitBlock());
        else
            block = std::min<float>(value, 75.0f);

        if (block < 0.0f)
            block = 0.0f;

        //Spellbreaker wears tall shield so should always block
        if (_botclass == BOT_CLASS_SPELLBREAKER)
            block += 90.f;

        //BLOCK VALUE
        //2 str = 1 block value
        value = 0.5f * _getTotalBotStat(BOT_STAT_MOD_STRENGTH) - 10.f;
        value += _getTotalBotStat(BOT_STAT_MOD_BLOCK_VALUE);

        //Shield Mastery part 1
        if (_botclass == BOT_CLASS_WARRIOR && mylevel >= 20 && GetSpec() == BOT_SPEC_WARRIOR_PROTECTION)
            value *= 1.3f;
        //Redoubt handled in passives
        //if (mylevel >= 45 && _botclass == BOT_CLASS_PALADIN)
        //    value *= 1.3f;

        blockvalue = std::max<float>(int32(value), 1.f);
    }
    //else
    //{
    //    block = 0.0f;
    //    blockvalue = 0;
    //}

    //MANA
    _OnManaUpdate();

    if (IsCastingClass(_botclass))
    {
        //SPELL PENETRATION
        value = IAmFree() ? mylevel : 0; // 80/0 at 80
        //~1 SPPR = 1 spell penetration
        value += _getTotalBotStat(BOT_STAT_MOD_SPELL_PENETRATION);
        spellpen = uint32(value);

        //SPELL POWER
        value = /*IAmFree() ? std::max<int32>((int8(mylevel) - 30) * 40, 0) : */0; // +2000/+0 spp at 80
        value += _getTotalBotStat(BOT_STAT_MOD_SPELL_POWER);

        //class-specified mods
        if (_botclass == BOT_CLASS_PALADIN && mylevel >= 50)
        {
            //Touched by the Light - 60% of strength to spell power
            if (GetSpec() == BOT_SPEC_PALADIN_PROTECTION)
                value += 0.6f * _getTotalBotStat(BOT_STAT_MOD_STRENGTH);
            //Sheath of Light - 30% attack power to spell power
            if (GetSpec() == BOT_SPEC_PALADIN_RETRIBUTION)
                value += 0.3f * me->GetTotalAttackPowerValue(BASE_ATTACK);
            //Holy Guidance - 20% Intellect to spell power
            if (GetSpec() == BOT_SPEC_PALADIN_HOLY)
                value += 0.2f * _getTotalBotStat(BOT_STAT_MOD_INTELLECT);
        }
        if (_botclass == BOT_CLASS_PRIEST && mylevel >= 30)
        {
            float totalSpi = _getTotalBotStat(BOT_STAT_MOD_SPIRIT);
            //Spiritual Guidance - 25% Spirit to spell power
            if (GetSpec() == BOT_SPEC_PRIEST_HOLY)
                value += 0.25f * totalSpi;
            //Twisted Faith - 20% Spirit to spell power
            else if (mylevel >= 55 && GetSpec() == BOT_SPEC_PRIEST_SHADOW)
                value += 0.2f * totalSpi;
            //Shadowy Insight (Glyph of Shadow)
            if (mylevel >= 30 &&
                me->GetAuraEffect(SPELL_AURA_MOD_SPELL_DAMAGE_OF_STAT_PERCENT, SPELLFAMILY_GENERIC, 1499, 0))
                value += 0.3f * totalSpi;
        }
        if (_botclass == BOT_CLASS_SHAMAN && mylevel >= 50 && GetSpec() == BOT_SPEC_SHAMAN_ENHANCEMENT)
        {
            //Mental Quickness - 30% attack power to spell power (only enhancement)
            value += 0.3f * me->GetTotalAttackPowerValue(BASE_ATTACK);
        }
        if (_botclass == BOT_CLASS_DRUID && mylevel >= 30)
        {
            //Nurturing Instinct - 70% Agility to spell power
            value += 0.7f * _getTotalBotStat(BOT_STAT_MOD_AGILITY);
            //Lunar Guidance - 12% Intellect to spell power
            value += 0.12f * _getTotalBotStat(BOT_STAT_MOD_INTELLECT);
            //Improved Moonkin Form - 30% Spirit to spell power
            if (mylevel >= 40 && myclass == DRUID_MOONKIN_FORM)
                value += 0.3f * _getTotalBotStat(BOT_STAT_MOD_SPIRIT);
            //Improved Tree (of Life) Form - 15% Spirit to spell power
            if (mylevel >= 50 && myclass == DRUID_TREE_FORM)
                value += 0.15f * _getTotalBotStat(BOT_STAT_MOD_SPIRIT);
        }
        if (_botclass == BOT_CLASS_MAGE && mylevel >= 45 && GetSpec() == BOT_SPEC_MAGE_ARCANE)
        {
            //Mind Mastery - 15% Intellect to spell power
            value += 0.15f * _getTotalBotStat(BOT_STAT_MOD_INTELLECT);
        }
        if (_botclass == BOT_CLASS_WARLOCK)
        {
            if (me->GetAuraEffect(SPELL_AURA_MOD_SPELL_DAMAGE_OF_STAT_PERCENT, SPELLFAMILY_WARLOCK, 0x0, 0x20000000, 0x0))
            {
                //Fel Armor + Demonic Aegis - 39% Spirit to spell power
                value += 0.39f * _getTotalBotStat(BOT_STAT_MOD_SPIRIT);
            }
            //Demonic Knowledge
            if (botPet && botPet->IsAlive() && mylevel >= 40 && GetSpec() == BOT_SPEC_WARLOCK_DEMONOLOGY)
                value += 0.12f * botPet->GetStat(STAT_STAMINA) + botPet->GetStat(STAT_INTELLECT);
            //Glyph of Life Tap: 20% of spirit to spellpower
            if (me->GetAuraEffect(SPELL_AURA_MOD_SPELL_DAMAGE_OF_STAT_PERCENT, SPELLFAMILY_WARLOCK, 208, 0))
                value += 0.2f * _getTotalBotStat(BOT_STAT_MOD_SPIRIT);
        }
        if (_botclass == BOT_CLASS_SPHYNX)
        {
            //bonus from attack power (for tank) or intellect (ranged)
            value += 2.0f *_getTotalBotStat(BOT_STAT_MOD_INTELLECT);
            value += 0.5f * me->GetTotalAttackPowerValue(BASE_ATTACK);
            //from wands
            for (uint8 i = BOT_SLOT_MAINHAND; i <= BOT_SLOT_OFFHAND; ++i)
                if (ItemTemplate const* proto = _equips[i] ? _equips[i]->GetTemplate() : nullptr)
                    value += proto->getDPS() * 1.35f;
        }
        if (_botclass == BOT_CLASS_ARCHMAGE)
        {
            //bonus from intellect
            value += _getTotalBotStat(BOT_STAT_MOD_INTELLECT);
        }
        if (_botclass == BOT_CLASS_DREADLORD)
        {
            //bonus from strength
            value += 2.f * _getTotalBotStat(BOT_STAT_MOD_STRENGTH);
        }
        if (_botclass == BOT_CLASS_SPELLBREAKER)
        {
            //bonus from strength
            value += 2.f * _getTotalBotStat(BOT_STAT_MOD_STRENGTH);
        }
        if (_botclass == BOT_CLASS_DARK_RANGER)
        {
            //bonus from intellect
            value += 0.5f * _getTotalBotStat(BOT_STAT_MOD_INTELLECT);
        }
        if (_botclass == BOT_CLASS_NECROMANCER)
        {
            //bonus from intellect
            value += _getTotalBotStat(BOT_STAT_MOD_INTELLECT);
        }
        if (_botclass == BOT_CLASS_SEA_WITCH)
        {
            //bonus from intellect
            value += 2.f * _getTotalBotStat(BOT_STAT_MOD_INTELLECT);
        }
        if (_botclass == BOT_CLASS_CRYPT_LORD)
        {
            //bonus from strength
            value += 2.f * _getTotalBotStat(BOT_STAT_MOD_STRENGTH);
        }

        spellpower = uint32(value);
    }
    //else
    //{
    //    spellpower = 0;
    //}

    //if init or levelup
    if (force)
    {
        InitHeals();
        me->SetFullHealth();
        if (_botclass != BOT_CLASS_SPHYNX)
            me->SetPower(POWER_MANA, me->GetMaxPower(POWER_MANA));

        me->ResetPlayerDamageReq();
    }

    if (botPet)
        botPet->GetBotPetAI()->SetShouldUpdateStats();
}

//Emotion-based action
void bot_ai::ReceiveEmote(Player* player, uint32 emote)
{
    switch (emote)
    {
        case TEXT_EMOTE_BONK:
            _listAuras(player, me);
            break;
        case TEXT_EMOTE_SALUTE:
            _listAuras(player, player);
            break;
        case TEXT_EMOTE_STAND:
            if (master != player)
            {
                me->HandleEmoteCommand(EMOTE_ONESHOT_RUDE);
                break;
            }
            SetBotCommandState(BOT_COMMAND_STAY);
            //BotWhisper("Standing Still.", player);
            break;
        case TEXT_EMOTE_WAVE:
            if (master != player)
            {
                me->HandleEmoteCommand(EMOTE_ONESHOT_RUDE);
                break;
            }
            if (me->IsNonMeleeSpellCast(true))
                me->InterruptNonMeleeSpells(true);
            SetBotCommandState(BOT_COMMAND_FOLLOW, true);
            //BotWhisper("Following!", player);
            break;
        case TEXT_EMOTE_TICKLE:
        {
            if (master != player)
                break;

            if ((me->HasUnitFlag(UNIT_FLAG_STUNNED) || me->HasUnitState(UNIT_STATE_STUNNED)) &&
                !me->HasAuraType(SPELL_AURA_MOD_STUN))
            {
                me->ClearUnitState(UNIT_STATE_STUNNED);
                me->RemoveUnitFlag(UNIT_FLAG_STUNNED);
            }
            if ((me->HasUnitFlag(UNIT_FLAG_CONFUSED) || me->HasUnitState(UNIT_STATE_CONFUSED)) &&
                !me->HasAuraType(SPELL_AURA_MOD_CONFUSE))
            {
                me->ClearUnitState(UNIT_STATE_CONFUSED);
                me->RemoveUnitFlag(UNIT_FLAG_CONFUSED);
            }
            if ((me->HasUnitFlag(UNIT_FLAG_FLEEING) || me->HasUnitState(UNIT_STATE_FLEEING)) &&
                !me->HasAuraType(SPELL_AURA_MOD_FEAR))
            {
                me->ClearUnitState(UNIT_STATE_FLEEING);
                me->RemoveUnitFlag(UNIT_FLAG_FLEEING);
            }
            me->BotStopMovement();

            me->TextEmote(LocalizedNpcText(player, BOT_TEXT_BOT_TICKLED).c_str());
            break;
        }
        default:
            break;
    }
}

//ISINBOTPARTY
//Returns group members (and their npcbots too)
//For now all your puppets are in your group automatically
bool bot_ai::IsInBotParty(Unit const* unit) const
{
    if (!unit)
        return false;
    if (unit == master || unit == me || unit == botPet)
        return true;

    if (IAmFree())
    {
        if (me->GetFaction() == 14 || unit->GetFaction() == 14)
            return false;

        if (me->HasByteFlag(UNIT_FIELD_BYTES_2, 1, UNIT_BYTE2_FLAG_FFA_PVP) ||
            unit->HasByteFlag(UNIT_FIELD_BYTES_2, 1, UNIT_BYTE2_FLAG_FFA_PVP))
            return false;

        return
            (unit->GetTypeId() == TYPEID_PLAYER || unit->ToCreature()->IsPet() || unit->ToCreature()->IsNPCBotOrPet()) &&
            (unit->GetFaction() == me->GetFaction() || (me->GetBotGroup() && me->GetBotGroup()->IsMember(unit->GetGUID())) ||
            (me->GetReactionTo(unit) >= REP_FRIENDLY && unit->GetReactionTo(me) >= REP_FRIENDLY));
    }

    //cheap check
    if (Group const* gr = master->GetGroup())
    {
        //group member case
        if (gr->IsMember(unit->GetGUID()))
            return true;
        //pointed target case
        for (uint8 i = 0; i != TARGET_ICONS_COUNT; ++i)
            if ((BotMgr::GetHealTargetIconFlags() & GroupIconsFlags[i]) &&
                !((BotMgr::GetOffTankTargetIconFlags() | BotMgr::GetDPSTargetIconFlags() | BotMgr::GetRangedDPSTargetIconFlags()) & GroupIconsFlags[i]))
                if (ObjectGuid guid = gr->GetTargetIcons()[i])
                    if (guid == unit->GetGUID())
                        return true;
    }

    //Player-controlled creature case
    if (Creature const* cre = unit->ToCreature())
    {
        ObjectGuid ownerGuid = unit->GetOwnerGUID() ? unit->GetOwnerGUID() : unit->GetCreator() ? unit->GetCreator()->GetGUID() : ObjectGuid::Empty;
        if (!ownerGuid && unit->IsVehicle())
            ownerGuid = unit->GetCharmerGUID();
        //controlled by master
        if (ownerGuid == master->GetGUID())
            return true;
        //npcbot/npcbot's pet case
        if (cre->GetBotOwner() == master)
            return true;
        if (ownerGuid && master->GetBotMgr()->GetBot(ownerGuid))
            return true;
        //controlled by group member
        //pets, minions, guardians etc.
        //bot pets too
        if (ownerGuid)
            if (Group const* gr = master->GetGroup())
                if (gr->IsMember(ownerGuid))
                    return true;
    }

    return false;
}

bool bot_ai::IsInBotParty(ObjectGuid guid) const
{
    if (!guid) return false;
    if (guid == master->GetGUID() || guid == me->GetGUID()) return true;
    if (master->GetVehicle() && guid == master->GetCharmedGUID()) return true;
    if (me->GetVehicle() && guid == me->GetCharmedGUID()) return true;

    if (IAmFree())
    {
        if (me->HasByteFlag(UNIT_FIELD_BYTES_2, 1, UNIT_BYTE2_FLAG_FFA_PVP))
            return false;

        return !(me->GetVictim() && me->GetVictim()->GetGUID() == guid);
    }

    //cheap check
    if (Group const* gr = master->GetGroup())
    {
        //group member case
        if (gr->IsMember(guid))
            return true;
        //pointed target case
        for (uint8 i = 0; i != TARGET_ICONS_COUNT; ++i)
            if ((BotMgr::GetHealTargetIconFlags() & GroupIconsFlags[i]) &&
                !((BotMgr::GetOffTankTargetIconFlags() | BotMgr::GetDPSTargetIconFlags()) & GroupIconsFlags[i]))
                if (ObjectGuid gguid = gr->GetTargetIcons()[i])
                    if (gguid == guid)
                        return true;

        for (GroupReference const* ref = gr->GetFirstMember(); ref != nullptr; ref = ref->next())
        {
            Player const* p = ref->GetSource();
            if (p && (p->GetPetGUID() == guid || (p->GetVehicle() && p->GetCharmedGUID() == guid)))
                return true;
            if (p && p->HaveBot())
            {
                if (Creature const* bot = p->GetBotMgr()->GetBot(guid))
                    if (bot->GetGUID() == guid || (bot->GetBotsPet() && bot->GetBotsPet()->GetGUID() == guid) ||
                        (bot->GetVehicle() && bot->GetCharmedGUID() == guid))
                        return true;
            }
        }
    }
    else
    {
        if (master->GetPetGUID() == guid || (master->GetVehicle() && master->GetCharmedGUID() == guid))
            return true;
        if (Creature const* bot = master->GetBotMgr()->GetBot(guid))
            if (bot->GetGUID() == guid || (bot->GetBotsPet() && bot->GetBotsPet()->GetGUID() == guid) ||
                (bot->GetVehicle() && bot->GetCharmedGUID() == guid))
                return true;
    }

    return false;
}

//REFRESHAURA
//Applies/removes/reapplies aura
void bot_ai::RefreshAura(uint32 spellId, int8 count, Unit* target) const
{
    if (count < 0 || count > 1)
    {
        TC_LOG_ERROR("entities.player", "bot_ai::RefreshAura(): count is out of bounds ({}) for bot {} (botclass: {}, entry: {})",
            int32(count), me->GetName(), uint32(_botclass), me->GetEntry());
        return;
    }

    if (!spellId)
    {
        TC_LOG_ERROR("entities.player", "bot_ai::RefreshAura(): spellId is 0 for bot {} (botclass: {}, entry: {})",
            me->GetName(), uint32(_botclass), me->GetEntry());
        return;
    }

    SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(spellId);
    if (!spellInfo)
    {
        TC_LOG_ERROR("entities.player", "bot_ai::RefreshAura(): Invalid spellInfo for spell {}! Bot - {} (botclass: {}, entry: {})",
            spellId, me->GetName(), uint32(_botclass), me->GetEntry());
        return;
    }
    spellInfo = spellInfo->TryGetSpellInfoOverride(me);

    if (!target)
        target = me;

    target->RemoveAurasDueToSpell(spellId);

    //for (int8 i = 0; i < count; ++i)
    if (count)
        target->AddAura(spellInfo, MAX_EFFECT_MASK, target);
}

bool bot_ai::CanBotAttack(Unit const* target, int8 byspell, bool secondary) const
{
    if (!target)
        return false;
    if (HasBotCommandState(BOT_COMMAND_FULLSTOP | BOT_COMMAND_INACTION))
        return false;
    if (target->HasUnitState(UNIT_STATE_EVADE | UNIT_STATE_IN_FLIGHT))
        return false;
    if (target->IsCombatDisallowed())
        return false;
    if (target->CanHaveThreatList() && GetEngageTimer() > lastdiff)
        return false;
    if (!BotMgr::IsPvPEnabled() && me->IsPvP() && target->IsControlledByPlayer())
        return false;
    if (me->GetFaction() == 35 && IAmFree() && target->GetTypeId() == TYPEID_UNIT && target->GetVictim() != me)
        return false;
    if ((target->GetFaction() == 35 || target->GetFaction() == me->GetFaction()) && me->GetFaction() != 14)
        return false;
    if (!CanBotAttackOnVehicle())
        return false;
    if (IsPointedNoDPSTarget(target))
        return false;

    if (IsWanderer() && target->IsCreature() && target->GetVictim() != me)
    {
        if (BotMgr::EnableWanderingUntargetNpcQuestgiver() && target->IsQuestGiver())
            return false;
        if (BotMgr::EnableWanderingUntargetNpcFlightmaster() && target->IsTaxi())
            return false;
    }

    if (IAmFree())
    {
        switch (target->GetEntry())
        {
            case 33229: case 33243: case 33272: // AT Training dummy targets
            case 4952: case 17578: case 24792: case 30527: case 31143: case 31144: case 31146: // training dummy
            case 32541: case 32542: case 32543: case 32545: case 32546: case 32547: case 32666: case 32667: // training dummy
            case 7668: case 7669: case 7670: case 7671: // Blasted Lands servants
                return false;
            case 21416: case 21709: case 21710: case 21711: // Shadowmoon Valley Broken element corruptors
                if (target->HasAuraTypeWithMiscvalue(SPELL_AURA_SCHOOL_IMMUNITY, 127))
                    return false;
                break;
            default:
                break;
        }
    }

    bool pulling = IsLastOrder(BOT_ORDER_PULL, 0, target->GetGUID());
    uint8 followdist = IAmFree() ? BotMgr::GetBotFollowDistMax() : master->GetBotMgr()->GetBotFollowDist();
    float foldist = _getAttackDistance(float(followdist));
    if (!IAmFree() && IsRanged() && me->IsWithinLOSInMap(target, LINEOFSIGHT_ALL_CHECKS, VMAP::ModelIgnoreFlags::M2))
        _extendAttackRange(foldist);

    uint32 mainMask;
    if (!byspell)
        mainMask = SPELL_SCHOOL_MASK_NORMAL;
    else
    {
        switch (_botclass)
        {
            case BOT_CLASS_PRIEST:      mainMask = SPELL_SCHOOL_MASK_SHADOW;                                                                break;
            case BOT_CLASS_SHAMAN:      mainMask = IsMelee() ? SPELL_SCHOOL_MASK_NORMAL : (SPELL_SCHOOL_MASK_FIRE|SPELL_SCHOOL_MASK_NATURE);break;
            case BOT_CLASS_MAGE:        mainMask = Rand() > 50 ? SPELL_SCHOOL_MASK_FIRE : SPELL_SCHOOL_MASK_FROST;                          break;
            case BOT_CLASS_WARLOCK:     mainMask = Rand() > 50 ? SPELL_SCHOOL_MASK_SHADOW : SPELL_SCHOOL_MASK_FIRE;                         break;
            case BOT_CLASS_DRUID:       mainMask = Rand() > 50 ? SPELL_SCHOOL_MASK_ARCANE : SPELL_SCHOOL_MASK_NATURE;                       break;
            case BOT_CLASS_SPHYNX:      mainMask = SPELL_SCHOOL_MASK_NONE;                                                                  break;
            case BOT_CLASS_ARCHMAGE:    mainMask = SPELL_SCHOOL_MASK_NONE;                                                                  break;
            case BOT_CLASS_DREADLORD:   mainMask = SPELL_SCHOOL_MASK_NONE;                                                                  break;
            case BOT_CLASS_SPELLBREAKER:mainMask = SPELL_SCHOOL_MASK_NONE;                                                                  break;
            case BOT_CLASS_DARK_RANGER: mainMask = SPELL_SCHOOL_MASK_NONE;                                                                  break;
            case BOT_CLASS_NECROMANCER: mainMask = SPELL_SCHOOL_MASK_NONE;                                                                  break;
            case BOT_CLASS_SEA_WITCH:   mainMask = SPELL_SCHOOL_MASK_NONE;                                                                  break;
            default:                    mainMask = SPELL_SCHOOL_MASK_NORMAL;                                                                break;
        }
    }

    return
        ((master->IsInCombat() || target->IsInCombat() || IsWanderer() || (IAmFree() && me->GetFaction() == 14) || pulling) &&
        target->IsVisible() && target->isTargetableForAttack(false) && me->IsValidAttackTarget(target) &&
        (!master->IsAlive() || target->IsControlledByPlayer() || pulling ||
        (followdist > 0 && (master->GetDistance(target) <= foldist || HasBotCommandState(BOT_COMMAND_STAY)))) &&//if master is killed pursue to the end
        !IsInBotParty(target) && (target->InSamePhase(me) || CanSeeEveryone()) &&
        (!HasBotCommandState(BOT_COMMAND_STAY) ||
        ((!IsRanged() && !secondary) ? me->IsWithinMeleeRange(target) : me->GetDistance(target) <= foldist)) &&//if stationery check own distance
        (byspell == -1 || !target->IsTotem()) &&
        (byspell == -1 || !mainMask || !target->IsImmunedToDamage(SpellSchoolMask(mainMask))));
}
bool bot_ai::CanBotAttackOnVehicle() const
{
    if (VehicleSeatEntry const* seat = me->GetVehicle() ? me->GetVehicle()->GetSeatForPassenger(me) : nullptr)
        return seat->Flags & VEHICLE_SEAT_FLAG_CAN_ATTACK;

    return true;
}
//GETVEHICLETARGET
//Returns attack target or 'no target'
//All code above 'x = _getVehicleTarget() call must not dereference opponent since it can be invalid
Unit* bot_ai::_getVehicleTarget(BotVehicleStrats /*strat*/) const
{
    ASSERT(!IAmFree());
    Creature* veh = me->GetVehicleCreatureBase();
    Creature* masterVeh = master->GetVehicleCreatureBase();
    ASSERT(veh);
    //ASSERT(masterVeh);
    Unit* mmover = masterVeh ? masterVeh->ToUnit() : master->ToUnit();
    ObjectGuid curTarget = veh->GetTarget();

    Unit* mytar = !curTarget.IsEmpty() ? ObjectAccessor::GetUnit(*veh, curTarget) : nullptr;

    if (mytar && veh->HasAuraType(SPELL_AURA_MOD_TAUNT))
        return mytar;

    Group const* gr = !IAmFree() ? master->GetGroup() : nullptr;

    if (gr && IsOffTank())
    {
        Unit* tankTar = nullptr;
        for (int8 i = TARGET_ICONS_COUNT - 1; i >= 0; --i)
        {
            if (BotMgr::GetOffTankTargetIconFlags() & GroupIconsFlags[i])
            {
                if (ObjectGuid guid = gr->GetTargetIcons()[i])
                {
                    if (mytar && mytar->GetGUID() == guid && mytar->GetVictim() == veh)
                        return mytar;

                    if (Unit* unit = ObjectAccessor::GetUnit(*veh, guid))
                    {
                        if (unit->IsVisible() && unit->isTargetableForAttack(false) && veh->IsValidAttackTarget(unit) &&
                            unit->IsInCombat() && (CanSeeEveryone() || (veh->CanSeeOrDetect(unit) && unit->InSamePhase(veh))))
                        {
                            Unit* tempTar = tankTar ? tankTar : unit;
                            tankTar = unit;
                            Unit* tVic = unit->GetVictim();
                            if (!tVic || (tVic != veh && tVic->GetVictim() == unit && IsTank(tVic) && IsInBotParty(tVic)))
                            {
                                tankTar = tempTar;
                                continue;
                            }
                        }
                    }
                }
            }
        }
        if (tankTar)
            return tankTar;
    }
    if (gr)
    {
        for (int8 i = TARGET_ICONS_COUNT - 1; i >= 0; --i)
        {
            if (ObjectGuid guid = gr->GetTargetIcons()[i])
            {
                if ((HasRole(BOT_ROLE_RANGED)|| HasVehicleRoleOverride(BOT_ROLE_RANGED)) &&
                    (BotMgr::GetRangedDPSTargetIconFlags() & GroupIconsFlags[i]))
                {
                    if (mytar && mytar->GetGUID() == guid)
                        return mytar;

                    if (Unit* unit = ObjectAccessor::GetUnit(*me, guid))
                    {
                        if (unit->IsVisible() && unit->isTargetableForAttack(false) && me->IsValidAttackTarget(unit) &&
                            unit->IsInCombat() && (CanSeeEveryone() || (me->CanSeeOrDetect(unit) && unit->InSamePhase(me))))
                        {
                            //TC_LOG_ERROR("entities.unit", "_getTarget: found dps icon target {}", unit->GetName());
                            return unit;
                        }
                    }
                }
                if (BotMgr::GetDPSTargetIconFlags() & GroupIconsFlags[i])
                {
                    if (mytar && mytar->GetGUID() == guid)
                        return mytar;

                    if (Unit* unit = ObjectAccessor::GetUnit(*veh, guid))
                    {
                        if (unit->IsVisible() && unit->isTargetableForAttack(false) && veh->IsValidAttackTarget(unit) &&
                            unit->IsInCombat() && (CanSeeEveryone() || (veh->CanSeeOrDetect(unit) && unit->InSamePhase(veh))))
                            return unit;
                    }
                }
            }
        }
    }

    float followdist = float (master->GetBotMgr()->GetBotFollowDist() * 2);
    if (float distOverride = GetVehicleAttackDistanceOverride())
        followdist = distOverride * 2.f;
    if (mytar && mytar->GetTypeId() == TYPEID_UNIT &&
        mytar->ToCreature()->GetCreatureTemplate()->rank == CREATURE_ELITE_WORLDBOSS)
        followdist *= 1.5f;
    else if (mmover->isMoving() && veh->GetMapId() == 578) //oculus
        followdist *= 0.5f;

    if (mytar && (veh->IsInCombat() || mytar->IsInCombat()) &&
        (!masterVeh || !mmover->IsAlive() || mmover->GetDistance(mytar) < followdist) && veh->IsValidAttackTarget(mytar))
        return mytar;

    if (mmover->IsAlive())
    {
        if (followdist == 0 || (mytar &&
            (mmover->GetDistance(mytar) > followdist || (mmover->GetDistance(mytar) > followdist * 0.75f && !mytar->IsWithinLOSInMap(veh)))))
        {
            //if (mytar)
            //{
            //    TC_LOG_ERROR("scripts", "_getVehicleTarget {}'s veh is too far from master - lost target ({} > {})",
            //        me->GetName(), veh->GetDistance(mmover), followdist);
            //}
            return nullptr;
        }
    }

    //check targets around
    float maxdist = InitAttackRange(followdist, IsRanged());
    Unit* t = nullptr;
    NearbyHostileVehicleTargetCheck check(veh, maxdist, this);
    Trinity::UnitSearcher <NearbyHostileVehicleTargetCheck> searcher(veh, t, check);
    Cell::VisitAllObjects(veh, searcher, maxdist);
    //veh->VisitNearbyObject(maxdist, searcher);

    return t;
}
//GETTARGET
//Returns attack target or 'no target' and distant check target or 'no target'
//All code above 'x = _getTarget() call must not dereference opponent or disttarget since it can be invalid
std::tuple<Unit*, Unit*> bot_ai::_getTargets(bool byspell, bool ranged, bool &reset) const
{
    //if (_evadeMode) //IAmFree() case only
    //    return { nullptr, nullptr };

    if (!CanBotAttackOnVehicle())
        return { nullptr, nullptr };

    Unit* mytar = me->GetVictim();

    //check if no need to change target
    //TC_LOG_ERROR("entities.player", "bot_ai::getTarget(): bot: {}", me->GetName());

    if (mytar && me->HasAuraType(SPELL_AURA_MOD_TAUNT))
        return { mytar, mytar };

    //Immediate targets
    //orders
    if (!IAmFree() && HasOrders() && HasRole(BOT_ROLE_DPS) && !me->IsInCombat() && me->getAttackers().empty())
    {
        if (_orders.front()._type == BOT_ORDER_PULL)
        {
            ObjectGuid orderTargetGuid = ObjectGuid(_orders.front().params.pullParams.targetGuid);
            if (Unit* orderTarget = mytar && mytar->GetGUID() == orderTargetGuid ? mytar : ObjectAccessor::GetUnit(*me, orderTargetGuid))
            {
                if (CanBotAttack(orderTarget))
                    return { orderTarget, nullptr };
            }
        }
    }
    //maps
    if (!IAmFree() && me->GetMap()->GetEntry() && !me->GetMap()->GetEntry()->IsWorldMap())
    {
        static const std::array WMOAreaGroupLashlayer = { 29476u }; // Halls of Strife
        static const std::array WMOAreaGroupMarrowgar = { 47833u }; // The Spire
        static const std::array WMOAreaGroupSindragosa = { 48066u }; // Frost Queen's Lair
        static const std::array WMOAreaGroupLichKing = { 50038u, 50040u }; // The Frozen Throne

        static auto isInWMOArea = [this](auto const& ids) {
            for (auto wmoId : ids) {
                if (wmoId == _lastWMOAreaId)
                    return true;
            }
            return false;
        };

        // Blackwing Lair
        if (me->GetMapId() == 469 && GetBotClass() == BOT_CLASS_ROGUE && !HasRole(BOT_ROLE_DPS) && me->HasStealthAura() && isInWMOArea(WMOAreaGroupLashlayer)) // BWL - Bloodlord Lashlayer
            return { nullptr, nullptr };

        // Icecrown Citadel - Lord Marrowgar
        if (me->GetMapId() == 631 && isInWMOArea(WMOAreaGroupMarrowgar) && me->IsInCombat() && HasRole(BOT_ROLE_DPS) && !IsTank())
        {
            static const std::array BoneSpikeIds = { CREATURE_ICC_BONE_SPIKE1, CREATURE_ICC_BONE_SPIKE2, CREATURE_ICC_BONE_SPIKE3 };

            auto boneSpikeCheck = [this, mydist = 50.f](Unit const* unit) mutable {
                if (!unit->IsAlive())
                    return false;
                for (uint32 bsId : BoneSpikeIds) {
                    if (unit->GetEntry() == bsId)  {
                        if (HasRole(BOT_ROLE_RANGED))
                            return true;
                        float dist = me->GetDistance2d(unit);
                        if (dist < mydist) {
                            mydist = dist;
                            return true;
                        }
                    }
                }
                return false;
            };

            std::list<Creature*> cList;
            Trinity::CreatureListSearcher searcher(me, cList, boneSpikeCheck);
            Cell::VisitAllObjects(me, searcher, 50.f);

            if (Creature* spike = cList.empty() ? nullptr : cList.size() == 1 ? cList.front() :
                Trinity::Containers::SelectRandomContainerElement(cList))
            {
                // Bone Spike is always attackable - no additional checks needed
                return { spike, nullptr };
            }
        }

        // Icecrown Citadel - Sindragosa
        if (me->GetMapId() == 631 && isInWMOArea(WMOAreaGroupSindragosa)/* &&
            (!mytar || (mytar->GetEntry() != CREATURE_ICC_ICE_TOMB1 && mytar->GetEntry() != CREATURE_ICC_ICE_TOMB2 &&
            mytar->GetEntry() != CREATURE_ICC_ICE_TOMB3 && mytar->GetEntry() != CREATURE_ICC_ICE_TOMB4))*/)
        {
            static const std::array IceTombIds = { CREATURE_ICC_ICE_TOMB1, CREATURE_ICC_ICE_TOMB2, CREATURE_ICC_ICE_TOMB3, CREATURE_ICC_ICE_TOMB4 };
            static const std::array SindragosaIds = { CREATURE_ICC_SINDRAGOSA1, CREATURE_ICC_SINDRAGOSA2, CREATURE_ICC_SINDRAGOSA3, CREATURE_ICC_SINDRAGOSA4 };

            static auto SiItCheck = [=](Unit const* unit) {
                if (unit->IsAlive())
                {
                    for (uint32 itId : IceTombIds)
                        if (unit->GetEntry() == itId)
                            return true;
                    for (uint32 siId : SindragosaIds)
                        if (unit->GetEntry() == siId)
                            return true;
                }
                return false;
            };

            std::list<Creature*> cList;
            Trinity::CreatureListSearcher searcher(master, cList, SiItCheck);
            Cell::VisitAllObjects(me, searcher, 200.f);

            if (!cList.empty())
            {
                Creature* sindragosa = nullptr;
                Creature* icetomb = nullptr;
                for (Creature* siit : cList)
                {
                    if (!icetomb)
                    {
                        for (uint32 itId : IceTombIds)
                        {
                            if (siit->GetEntry() == itId)
                            {
                                icetomb = siit;
                                break;
                            }
                        }
                    }
                    if (!sindragosa)
                    {
                        for (uint32 siId : SindragosaIds)
                        {
                            if (siit->GetEntry() == siId)
                            {
                                sindragosa = siit;
                                break;
                            }
                        }
                    }
                    else
                        break;
                }

                if (icetomb)
                {
                    bool air_phase = sindragosa && sindragosa->GetReactState() == REACT_PASSIVE;
                    bool above35 = GetHealthPCT(icetomb) > 35;
                    if (!air_phase || above35)
                        return { icetomb, nullptr };
                    else if (mytar == icetomb || !master->GetVictim())
                    {
                        if (botPet && botPet->GetVictim())
                            botPet->AttackStop();
                        return { nullptr, nullptr };
                    }
                }
            }
        }

        // Icecrown Citadel - The Lich King
        if (me->GetMapId() == 631 && isInWMOArea(WMOAreaGroupLichKing) && me->IsInCombat() && HasRole(BOT_ROLE_DPS) && !IsTank())
        {
            static const std::array IceSphereIds = { CREATURE_ICC_ICE_SPHERE1, CREATURE_ICC_ICE_SPHERE2, CREATURE_ICC_ICE_SPHERE3, CREATURE_ICC_ICE_SPHERE4 };
            static const std::array ValkyrShadowguardIds = { CREATURE_ICC_VALKYR_LK1, CREATURE_ICC_VALKYR_LK2, CREATURE_ICC_VALKYR_LK3, CREATURE_ICC_VALKYR_LK4 };

            static auto valkyrCheck = [=](Unit const* unit) {
                for (uint32 vsId : ValkyrShadowguardIds) {
                    if (unit->IsAlive() && unit->GetEntry() == vsId && !unit->HasUnitFlag(UNIT_FLAG_UNINTERACTIBLE))
                        return true;
                }
                return false;
            };

            Creature* valkyr = nullptr;
            Trinity::CreatureSearcher searcher(me, valkyr, valkyrCheck);
            Cell::VisitAllObjects(me, searcher, 50.f);

            if (valkyr)
                return { valkyr, nullptr };

            Unit const* usearcher = master->IsAlive() ? master->ToUnit() : me->ToUnit();
            auto iceSphereCheck = [this, usearcher = usearcher, mydist = 30.f](Unit const* unit) mutable {
                for (uint32 isId : IceSphereIds) {
                    if (unit->IsAlive() && unit->GetEntry() == isId) {
                        float dist = usearcher->GetDistance2d(unit);
                        if (dist < mydist && (HasRole(BOT_ROLE_RANGED) || dist < 7.f)) {
                            mydist = dist;
                            return true;
                        }
                    }
                }
                return false;
            };

            Creature* sphere = nullptr;
            Trinity::CreatureLastSearcher searcher2(usearcher, sphere, iceSphereCheck);
            Cell::VisitAllObjects(usearcher, searcher2, 30.f);

            if (sphere)
                return { sphere, nullptr };
        }
    }

    Group const* gr = !IAmFree() ? master->GetGroup() : nullptr;

    if (gr && IsOffTank())
    {
        if (_primaryIconTank >= 0 && BotMgr::GetOffTankTargetIconFlags() & (1u << _primaryIconTank))
        {
            if (ObjectGuid guid = gr->GetTargetIcons()[_primaryIconTank])
            {
                if (mytar && mytar->GetGUID() == guid)
                    return { mytar, mytar };

                if (Unit* unit = ObjectAccessor::GetUnit(*me, guid))
                {
                    if (unit->IsVisible() && unit->isTargetableForAttack(false) && me->IsValidAttackTarget(unit) &&
                        (unit->IsInCombat() || me->IsInCombat() || master->IsInCombat()) && (CanSeeEveryone() || (me->CanSeeOrDetect(unit) && unit->InSamePhase(me))))
                    {
                        return { unit, unit };
                    }
                }
            }
        }

        Unit* tankTar = nullptr;
        for (int8 i = TARGET_ICONS_COUNT - 1; i >= 0; --i)
        {
            if (i == _primaryIconTank)
                continue;

            if (BotMgr::GetOffTankTargetIconFlags() & GroupIconsFlags[i])
            {
                if (ObjectGuid guid = gr->GetTargetIcons()[i])
                {
                    if (mytar && mytar->GetGUID() == guid && mytar->GetVictim() == me)
                    {
                        //TC_LOG_ERROR("entities.unit", "_getTarget: {} continues {}", me->GetName(), mytar->GetName());
                        return { mytar, mytar };
                    }

                    if (Unit* unit = ObjectAccessor::GetUnit(*me, guid))
                    {
                        if (unit->IsVisible() && unit->isTargetableForAttack(false) && me->IsValidAttackTarget(unit) &&
                            unit->IsInCombat() && (CanSeeEveryone() || (me->CanSeeOrDetect(unit) && unit->InSamePhase(me))))
                        {
                            //TC_LOG_ERROR("entities.unit", "_getTarget: {} found new offtanking icon target {}", me->GetName(), unit->GetName());
                            Unit* tempTar = tankTar ? tankTar : unit;
                            tankTar = unit;
                            Unit* tVic = unit->GetVictim();
                            if (!tVic || (tVic != me && tVic->GetVictim() == unit && IsTank(tVic) && IsInBotParty(tVic)))
                            {
                                //TC_LOG_ERROR("entities.unit", "_getTarget: {} skipped {} ({})", me->GetName(), unit->GetName(), tVic->GetName());
                                tankTar = tempTar;
                                continue;
                            }
                        }
                    }
                }
            }
        }
        if (tankTar)
        {
            //TC_LOG_ERROR("entities.unit", "_getTarget: {} returning {}", me->GetName(), tankTar->GetName());
            return { tankTar, tankTar };
        }
    }
    if (gr && IsTank())
    {
        if (_primaryIconTank >= 0 && BotMgr::GetTankTargetIconFlags() & (1u << _primaryIconTank))
        {
            if (ObjectGuid guid = gr->GetTargetIcons()[_primaryIconTank])
            {
                if (mytar && mytar->GetGUID() == guid)
                    return { mytar, mytar };

                if (Unit* unit = ObjectAccessor::GetUnit(*me, guid))
                {
                    if (unit->IsVisible() && unit->isTargetableForAttack(false) && me->IsValidAttackTarget(unit) &&
                        (unit->IsInCombat() || me->IsInCombat() || master->IsInCombat()) && (CanSeeEveryone() || (me->CanSeeOrDetect(unit) && unit->InSamePhase(me))))
                    {
                        return { unit, unit };
                    }
                }
            }
        }

        Unit* tankTar = nullptr;
        for (int8 i = TARGET_ICONS_COUNT - 1; i >= 0; --i)
        {
            if (i == _primaryIconTank)
                continue;

            if (BotMgr::GetTankTargetIconFlags() & GroupIconsFlags[i])
            {
                if (ObjectGuid guid = gr->GetTargetIcons()[i])
                {
                    if (mytar && mytar->GetGUID() == guid && mytar->GetVictim() == me)
                    {
                        //TC_LOG_ERROR("entities.unit", "_getTarget: {} continues {}", me->GetName(), mytar->GetName());
                        return { mytar, mytar };
                    }

                    if (Unit* unit = ObjectAccessor::GetUnit(*me, guid))
                    {
                        if (unit->IsVisible() && unit->isTargetableForAttack(false) && me->IsValidAttackTarget(unit) &&
                            unit->IsInCombat() && (CanSeeEveryone() || (me->CanSeeOrDetect(unit) && unit->InSamePhase(me))))
                        {
                            //TC_LOG_ERROR("entities.unit", "_getTarget: {} found new mtanking icon target {}", me->GetName(), unit->GetName());
                            Unit* tempTar = tankTar ? tankTar : unit;
                            tankTar = unit;
                            Unit* tVic = unit->GetVictim();
                            if (!tVic || (tVic != me && tVic->GetVictim() == unit && IsTank(tVic) && IsInBotParty(tVic)))
                            {
                                //TC_LOG_ERROR("entities.unit", "_getTarget: {} skipped {} ({})", me->GetName(), unit->GetName(), tVic->GetName());
                                tankTar = tempTar;
                                continue;
                            }
                        }
                    }
                }
            }
        }
        if (tankTar)
        {
            //TC_LOG_ERROR("entities.unit", "_getTarget: {} returning {}", me->GetName(), tankTar->GetName());
            return { tankTar, tankTar };
        }
    }
    if (gr)
    {
        if (_primaryIconDamage >= 0)
        {
            uint32 iconMask = BotMgr::GetDPSTargetIconFlags();
            if (HasRole(BOT_ROLE_RANGED))
                iconMask |= BotMgr::GetRangedDPSTargetIconFlags();
            if (iconMask & (1u << _primaryIconDamage))
            {
                if (ObjectGuid guid = gr->GetTargetIcons()[_primaryIconDamage])
                {
                    if (mytar && mytar->GetGUID() == guid)
                        return { mytar, mytar };

                    if (Unit* unit = ObjectAccessor::GetUnit(*me, guid))
                    {
                        if (unit->IsVisible() && unit->isTargetableForAttack(false) && me->IsValidAttackTarget(unit) &&
                            (unit->IsInCombat() || me->IsInCombat() || master->IsInCombat()) && (CanSeeEveryone() || (me->CanSeeOrDetect(unit) && unit->InSamePhase(me))))
                        {
                            return { unit, unit };
                        }
                    }
                }
            }
        }

        for (int8 i = TARGET_ICONS_COUNT - 1; i >= 0; --i)
        {
            if (i == _primaryIconDamage)
                continue;

            if (ObjectGuid guid = gr->GetTargetIcons()[i])
            {
                if (HasRole(BOT_ROLE_RANGED) && (BotMgr::GetRangedDPSTargetIconFlags() & GroupIconsFlags[i]))
                {
                    if (mytar && mytar->GetGUID() == guid)
                        return { mytar, mytar };

                    if (Unit* unit = ObjectAccessor::GetUnit(*me, guid))
                    {
                        if (unit->IsVisible() && unit->isTargetableForAttack(false) && me->IsValidAttackTarget(unit) &&
                            unit->IsInCombat() && (CanSeeEveryone() || (me->CanSeeOrDetect(unit) && unit->InSamePhase(me))))
                        {
                            //TC_LOG_ERROR("entities.unit", "_getTarget: found rdps icon target {}", unit->GetName());
                            return { unit, unit };
                        }
                    }
                }
                if (BotMgr::GetDPSTargetIconFlags() & GroupIconsFlags[i])
                {
                    if (mytar && mytar->GetGUID() == guid)
                        return { mytar, mytar };

                    if (Unit* unit = ObjectAccessor::GetUnit(*me, guid))
                    {
                        if (unit->IsVisible() && unit->isTargetableForAttack(false) && me->IsValidAttackTarget(unit) &&
                            unit->IsInCombat() && (CanSeeEveryone() || (me->CanSeeOrDetect(unit) && unit->InSamePhase(me))))
                        {
                            //TC_LOG_ERROR("entities.unit", "_getTarget: found dps icon target {}", unit->GetName());
                            return { unit, unit };
                        }
                    }
                }
            }
        }
    }

    Unit* u = master->GetVictim();
//Disabled due to a bug:
//when spell cast is finished target is immideately put in combat which makes bots attack immediately
//caster must be put in combat at spell launch
//but target must be put in combat at spell hit
/*
    if (!u && !IAmFree() && master->IsInCombat() && Rand() < 15)
    {
        for (uint8 i = CURRENT_FIRST_NON_MELEE_SPELL; i != CURRENT_MAX_SPELL; ++i)
        {
            if (Spell const* spell = master->GetCurrentSpell(CurrentSpellTypes(i)))
            {
                //if (spell->getState() == SPELL_STATE_FINISHED)
                //    continue;

                if (mytar && spell->m_targets.GetUnitTargetGUID() == mytar->GetGUID())
                {
                    u = mytar;
                    break;
                }

                //direct damaging spells
                if (!spell->GetSpellInfo()->IsPositive() &&
                    (spell->GetSpellInfo()->HasEffect(SPELL_EFFECT_WEAPON_DAMAGE) ||
                    spell->GetSpellInfo()->HasEffect(SPELL_EFFECT_SCHOOL_DAMAGE) ||
                    spell->GetSpellInfo()->HasEffect(SPELL_EFFECT_WEAPON_DAMAGE_NOSCHOOL)))
                {
                    Unit* victim = ObjectAccessor::GetUnit(*me, spell->m_targets.GetUnitTargetGUID());
                    if (victim && victim->IsInCombat())
                    {
                        u = victim;
                        break;
                    }
                }
            }
        }
    }
*/
    if (u && u == mytar && !IAmFree() && u->GetTypeId() == TYPEID_PLAYER && CanBotAttack(u, byspell))
    {
        //TC_LOG_ERROR("entities.player", "bot {} continues attack common target {}", me->GetName(), u->GetName());
        return { u, u };//forced
    }
    //Follow if...
    uint8 followdist = IAmFree() ? BotMgr::GetBotFollowDistMax() / 2 : master->GetBotMgr()->GetBotFollowDist();
    if (IsWanderer() && me->GetMap()->GetEntry()->IsBattlegroundOrArena())
        followdist += 30;
    float foldist = _getAttackDistance(float(followdist));
    if (!IAmFree() && IsRanged())
    {
        _extendAttackRange(foldist);
        //TC_LOG_ERROR("entities.player", "bot {} ranged foldist {} spelldist {}", me->GetName(), foldist, spelldist);
    }
    bool dropTarget = followdist == 0 && master->IsAlive();
    if (!dropTarget && (!u || IAmFree()) && master->IsAlive() && mytar && mytar == opponent)
    {
        dropTarget = IAmFree() ?
            me->GetDistance(mytar) > (IsWanderer() ? float(followdist + 10) : foldist) :
            HasBotCommandState(BOT_COMMAND_STAY) ?
            (!IsRanged() ? !me->IsWithinMeleeRange(mytar) : me->GetDistance(mytar) > foldist) :
            (master->GetDistance(mytar) > foldist || (master->GetDistance(mytar) > foldist * 0.75f && !mytar->IsWithinLOSInMap(me, LINEOFSIGHT_ALL_CHECKS, VMAP::ModelIgnoreFlags::M2)));
    }
    if (dropTarget)
    {
        //TC_LOG_ERROR("entities.player", "bot {} cannot attack target {}, too far away or not in LoS", me->GetName(), mytar ? mytar->GetName() : "unk");
        mytar = nullptr;
    }

    if (u && !IAmFree() && (master->IsInCombat() || u->IsInCombat())/* && !InDuel(u)*/ && !IsInBotParty(u) && (BotMgr::IsPvPEnabled() || !u->IsControlledByPlayer()) &&
        (!HasBotCommandState(BOT_COMMAND_STAY) || (!IsRanged() ? me->IsWithinMeleeRange(u) : me->GetDistance(u) < foldist)))
    {
        //TC_LOG_ERROR("entities.player", "bot {} starts attack master's target {}", me->GetName(), u->GetName());
        return { u, u };
    }

    bool canAttack = mytar && CanBotAttack(mytar, byspell);
    if (mytar && (!IAmFree() || me->GetDistance(mytar) < float(BOT_MAX_CHASE_RANGE)) && canAttack &&/* !InDuel(mytar) &&*/
        !(mytar->GetVictim() != nullptr && IsTank() && IsTank(mytar->GetVictim())))
    {
        //TC_LOG_ERROR("entities.player", "bot {} continues attack its target {}", me->GetName(), mytar->GetName());
        if (me->GetDistance(mytar) > (ranged ? 20.f : 5.f) && !HasBotCommandState(BOT_COMMAND_MASK_UNCHASE))
            reset = true;
        return { mytar, mytar };
    }

    //check group
    if (!IAmFree())
    {
        if (!gr)
        {
            BotMap const* map = master->GetBotMgr()->GetBotMap();
            for (BotMap::const_iterator itr = map->begin(); itr != map->end(); ++itr)
            {
                Creature const* bot = itr->second;
                if (!bot || bot == me || !bot->InSamePhase(me)) continue;
                if (IsTank() && IsTank(bot)) continue;
                u = bot->GetVictim();
                if (u && (bot->IsInCombat() || u->IsInCombat()) && CanBotAttack(u, byspell))
                {
                    //TC_LOG_ERROR("entities.player", "bot {} hooked {}'s victim {}", me->GetName(), bot->GetName(), u->GetName());
                    return { u, u };
                }
            }
        }
        else
        {
            for (GroupReference const* ref = gr->GetFirstMember(); ref != nullptr; ref = ref->next())
            {
                Player const* pl = ref->GetSource();
                if (!pl || !pl->IsInWorld() || pl->IsBeingTeleported()) continue;
                if (me->GetMap() != pl->FindMap() || !pl->InSamePhase(me)) continue;
                if (IsTank() && IsTank(pl)) continue;
                u = pl->GetVictim();
                if (u && pl != master && (pl->IsInCombat() || u->IsInCombat()) && CanBotAttack(u, byspell))
                {
                    //TC_LOG_ERROR("entities.player", "bot {} hooked {}'s victim {}", me->GetName(), pl->GetName(), u->GetName());
                    return { u, u };
                }
                if (!pl->HaveBot()) continue;
                BotMap const* map = pl->GetBotMgr()->GetBotMap();
                for (BotMap::const_iterator it = map->begin(); it != map->end(); ++it)
                {
                    Creature const* bot = it->second;
                    if (!bot || bot == me || !bot->InSamePhase(me)) continue;
                    if (!bot->IsInWorld()) continue;
                    if (me->GetMap() != bot->FindMap()) continue;
                    if (IsTank() && IsTank(bot)) continue;
                    u = bot->GetVictim();
                    if (u && (bot->IsInCombat() || u->IsInCombat()) && CanBotAttack(u, byspell))
                    {
                        //TC_LOG_ERROR("entities.player", "bot {} hooked {}'s victim {}", me->GetName(), bot->GetName(), u->GetName());
                        return { u, u };
                    }
                }
            }
        }
    }
    else if (!canAttack)
    {
        //check attackers
        u = nullptr;
        for (Unit* att : me->getAttackers())
            if (_canSwitchToTarget(u, att, byspell))
                u = att;
        if (!u && botPet)
            for (Unit* att : botPet->getAttackers())
                if (_canSwitchToTarget(u, att, byspell))
                    u = att;
        if (u)
            return { u, u };
    }

    if (IAmFree() && IsWanderer() && !me->IsInCombat() && me->getAttackers().empty() && (evadeDelayTimer > 7500 || Feasting() || me->GetHealthPct() < 85.f))
        return { nullptr, nullptr };

    //check targets around
    float maxdist = InitAttackRange(float(followdist + 10), ranged);
    std::array<std::pair<Unit*, float>, 2u> ts{};
    std::list<Unit*> unitList;
    NearestHostileUnitCheck check(me, maxdist, byspell, this);
    Trinity::UnitListSearcher searcher(master->ToUnit(), unitList, check);
    Cell::VisitAllObjects(HasBotCommandState(BOT_COMMAND_STAY) ? me->ToUnit() : master->ToUnit(), searcher, maxdist);

    if (IAmFree())
    {
        decltype(unitList) closeList;
        if (IsWanderer())
        {
            //Try to prioritize flag carrier
            if (me->GetMap()->IsBattlegroundOrArena())
            {
                for (decltype(unitList)::iterator it = unitList.begin(); it != unitList.end(); ++it)
                {
                    if (IsFlagCarrier(*it) && CanBotAttack(*it, byspell))
                    {
                        closeList.push_back(*it);
                        break;
                    }
                }
            }

            unitList.remove_if([me = me](Unit const* unit) -> bool {
                if (!unit->IsInCombatWith(me) && !(unit->IsNPCBot() && unit->ToCreature()->IsWandererBot()))
                {
                    if (unit->IsPlayer())
                    {
                        if (me->GetLevel() + 12 < unit->GetLevel())
                            return true;
                        if (unit->GetLevel() + 9 < me->GetLevel())
                            return true;
                    }
                    else
                    {
                        if (me->GetLevel() + (unit->ToCreature()->isElite() ? 3 : 6) < unit->GetLevel())
                            return true;
                        if (unit->GetLevel() + (unit->ToCreature()->isElite() ? 8 : 4) < me->GetLevel())
                            return true;
                        if (unit->IsCritter())
                            return true;
                    }
                }
                return false;
            });
        }

        for (decltype(unitList)::iterator it = unitList.begin(); it != unitList.end();)
        {
            if (!CanBotAttack(*it, byspell))
                it = unitList.erase(it);
            else if (me->GetDistance(*it) < 15.f)
            {
                closeList.push_back(*it);
                it = unitList.erase(it);
            }
            else
                ++it;
        }

        if (!closeList.empty())
        {
            ts[0].first = closeList.size() == 1 ? closeList.front() : Trinity::Containers::SelectRandomContainerElement(closeList);
            ts[0].second = me->GetDistance(ts[0].first);
        }
        else if (!unitList.empty())
        {
            ts[0].first = unitList.size() == 1 ? unitList.front() : Trinity::Containers::SelectRandomContainerElement(unitList);
            ts[0].second = me->GetDistance(ts[0].first);
        }
    }
    else
    {
        bool checkSecondary = !IsRanged() && HasBotCommandState(BOT_COMMAND_STAY);
        for (Unit* un : unitList)
        {
            uint32 res = !CanBotAttack(un, byspell) ? (checkSecondary && CanBotAttack(un, byspell, checkSecondary)) ? 2 : 0 : 1;
            switch (res)
            {
                case 1: case 2:
                    if (!ts[res - 1].first || me->GetDistance(un) < ts[res - 1].second)
                        ts[res - 1] = { un, me->GetDistance(un) };
                    break;
                default:
                    break;
            }
        }
    }
    Unit* t1 = ts[0].first;
    Unit* t2 = ts[1].first;

    Unit const* curtar = opponent ? opponent : disttarget ? disttarget : nullptr;
    if (t1 && curtar && t1 != curtar)
        reset = true;

    //Allow free bots to ignore temp invulnerabilities if no other target is present
    if (IAmFree() && t1 == nullptr)
        t1 = mytar;

    //if (t)
    //    TC_LOG_ERROR("entities.player", "bot {} has found new target {}", me->GetName(), t->GetName());

    return { t1, t2 };
}
//'CanAttack' function
//Only called in class ai UpdateAI function
//Side effects: opponent, disttarget
bool bot_ai::CheckAttackTarget()
{
    if (IsDuringTeleport()/* || _evadeMode*/)
    {
        //me->AttackStop(); //already in CombatStop()
        me->CombatStop(true);
        return false;
    }

    if (IAmFree() && Feasting())
        return false;

    bool ranged = HasRole(BOT_ROLE_RANGED);
    bool byspell = false;
    bool reset = false;

    switch (_botclass)
    {
        case BOT_CLASS_DRUID:
            switch (GetBotStance())
            {
                case DRUID_CAT_FORM:
                case DRUID_BEAR_FORM:
                    break;
                case DRUID_TREE_FORM:
                case DRUID_TRAVEL_FORM:
                case DRUID_AQUATIC_FORM:
                case DRUID_FLIGHT_FORM:
                    ranged = true;
                    break;
                case DRUID_MOONKIN_FORM:
                    byspell = true;
                    break;
                case BOT_STANCE_NONE:
                    byspell = ranged && HasRole(BOT_ROLE_DPS);
                    break;
                default:
                    TC_LOG_ERROR("entities.player", "bot_ai::CheckAttackTarget(): druid has NYI bot stance {}", uint32(GetBotStance()));
                    break;
            }
            break;
        case BOT_CLASS_PRIEST:
        case BOT_CLASS_MAGE:
        case BOT_CLASS_WARLOCK:
        case BOT_CLASS_SHAMAN:
            byspell = ranged && HasRole(BOT_ROLE_DPS);
            break;
        case BOT_CLASS_SPHYNX:
        case BOT_CLASS_ARCHMAGE:
        case BOT_CLASS_NECROMANCER:
            byspell = HasRole(BOT_ROLE_DPS);
            break;
        case BOT_CLASS_HUNTER:
        case BOT_CLASS_DEATH_KNIGHT:
        case BOT_CLASS_PALADIN:
        case BOT_CLASS_WARRIOR:
        case BOT_CLASS_ROGUE:
        case BOT_CLASS_BM:
        case BOT_CLASS_DREADLORD:
        case BOT_CLASS_SPELLBREAKER:
        case BOT_CLASS_DARK_RANGER:
        case BOT_CLASS_SEA_WITCH:
        case BOT_CLASS_CRYPT_LORD:
            break;
        default:
            TC_LOG_ERROR("entities.player", "bot_ai: CheckAttackTarget() - unknown bot class {}", _botclass);
            return false;
    }

    std::tie(opponent, disttarget) = _getTargets(byspell, ranged, reset);

    if (!opponent && !disttarget)
    {
        //TC_LOG_ERROR("entities.player", "bot_ai: CheckAttackTarget() - bot {} lost target", me->GetName());
        if (me->GetVictim() || me->IsInCombat()/* || !me->GetThreatManager().isThreatListEmpty()*/)
        {
            //TC_LOG_ERROR("entities.player", "bot_ai: CheckAttackTarget() - bot {} Evades", me->GetName());
            if (me->GetVictim())
                me->AttackStop();
            else if (me->IsInCombat())
                Evade();
        }

        return false;
    }

    Unit* mytar = opponent ? opponent : disttarget;
    //boss engage phase // CanHaveThreatList checks for typeid == UNIT
    if (GetEngageTimer() > lastdiff)
        return false;
    else if (!IsTank() && mytar != me->GetVictim() && mytar->GetVictim() && mytar->CanHaveThreatList() &&
        mytar->ToCreature()->GetCreatureTemplate()->rank == CREATURE_ELITE_WORLDBOSS && me->GetMap()->IsRaid())
    {
        uint32 threat = uint32(mytar->ToCreature()->GetThreatManager().GetThreat(mytar->GetVictim()));
        if (threat < std::min<uint32>(50000, mytar->GetVictim()->GetMaxHealth() / 2))
            return false;
    }

    if (reset)
        SetBotCommandState(BOT_COMMAND_COMBATRESET);//reset AttackStart()

    if (mytar != me->GetVictim())
        me->Attack(mytar, !ranged);

    return true;
}
//IMMEDIATE TARGETS
bool bot_ai::ProcessImmediateNonAttackTarget()
{
    if ((me->GetMap()->GetEntry() && me->GetMap()->GetEntry()->IsWorldMap()) || IAmFree() || IsCasting())
        return false;

    static constexpr std::array<uint32, 1> WMOAreaGroupLashlayer = { 29476 }; // Halls of Strife
    static constexpr std::array<uint32, 2> WMOAreaGroupMuru = { 41736, 42759 }; // Shrine of the Eclipse
    static constexpr std::array<uint32, 2> WMOAreaGroupNajentus = { 41129, 41130 }; // Karabor Sewers
    static constexpr std::array<uint32, 1> WMOAreaGroupVashj = { 37594 }; // Serpentshrine Cavern
    static constexpr std::array<uint32, 2> WMOAreaGroupSvalna = { 48061, 48335 }; // The Frostwing Halls

    static auto isInWMOArea = [](auto lastWMO, auto const& ids) {
        for (auto wmoId : ids) {
            if (wmoId == lastWMO)
                return true;
        }
        return false;
    };

    if (me->GetMapId() == 469 && GetBotClass() == BOT_CLASS_ROGUE && isInWMOArea(_lastWMOAreaId, WMOAreaGroupLashlayer)) // BWL - Bloodlord Lashlayer
    {
        static const uint32 SPELL_DISARM_TRAP_1 = 1842u;

        if (!IsCasting() && IsSpellReady(SPELL_DISARM_TRAP_1, lastdiff, false) && (me->HasAuraType(SPELL_AURA_MOD_STEALTH) || IsSpellReady(1784, lastdiff, false)) && Rand() < 20) // Stealth
        {
            SpellInfo const* disarmTrapSpellInfo = sSpellMgr->AssertSpellInfo(SPELL_DISARM_TRAP_1);
            float max_range = disarmTrapSpellInfo->GetMaxRange();
            ApplyBotSpellRangeMods(disarmTrapSpellInfo, max_range);

            std::list<GameObject*> goList;
            Trinity::AllGameObjectsWithEntryInRange check(me, 179784, max_range); // Suppression Device
            Trinity::GameObjectListSearcher<Trinity::AllGameObjectsWithEntryInRange> searcher(me, goList, check);
            Cell::VisitAllObjects(me, searcher, max_range);

            goList.remove_if([](GameObject const* gobject) { return gobject->HasFlag(GO_FLAG_NOT_SELECTABLE); });

            if (GameObject* device = goList.empty() ? nullptr : goList.size() == 1u ? goList.front() : Trinity::Containers::SelectRandomContainerElement(goList))
            {
                if (me->HasAuraType(SPELL_AURA_MOD_STEALTH) || doCast(me, GetSpell(1784)))
                me->CastSpell(device, SPELL_DISARM_TRAP_1);
                return true;
            }
        }
    }

    if (me->GetMapId() == 580 && isInWMOArea(_lastWMOAreaId, WMOAreaGroupMuru)) // Sunwell - M'uru
    {
        static const uint32 SPELL_PURGE_1 = 370u;
        static const uint32 SPELL_DISPEL_MAGIC_1 = 527u;
        uint32 dspell = 0;
        if (_botclass == BOT_CLASS_SHAMAN)
            dspell = SPELL_PURGE_1;
        else if (_botclass == BOT_CLASS_PRIEST)
            dspell = SPELL_DISPEL_MAGIC_1;

        if (dspell && IsSpellReady(dspell, lastdiff))
        {
            std::list<Creature*> cList;
            Trinity::AllCreaturesOfEntryInRange check(me, 25744, 30.f); // Dark Fiend
            Trinity::CreatureListSearcher<Trinity::AllCreaturesOfEntryInRange> searcher(me, cList, check);
            Cell::VisitAllObjects(me, searcher, 30.f);

            //Dark Fiends do not die instantly, remove purged ones
            cList.remove_if(Trinity::UnitAuraCheck(false, 45934)); // "Dark Fiend"

            if (Unit* fiend = cList.empty() ? nullptr : cList.size() == 1u ? cList.front() :
                Trinity::Containers::SelectRandomContainerElement(cList))
            {
                if (CheckBotCast(fiend, GetSpell(dspell)) == SPELL_CAST_OK)
                    if (doCast(fiend, GetSpell(dspell)))
                        return true;
            }
        }
    }
    if (me->GetMapId() == 564 && isInWMOArea(_lastWMOAreaId, WMOAreaGroupNajentus) && Rand() < 10) // Black Temple - High Warlord Naj'entus
    {
        if (Group const* gr = master->GetGroup())
        {
            if (Rand() < 4)
            {
                InstanceScript* iscript = me->GetMap()->ToInstanceMap()->GetInstanceScript();
                Unit* najentus = iscript ? iscript->GetCreature(0) : nullptr; // boss_warlord_najentus.cpp::DATA_HIGH_WARLORD_NAJENTUS

                if (najentus && najentus->HasAuraTypeWithMiscvalue(SPELL_AURA_SCHOOL_IMMUNITY, 127)) // Tidal Shield
                {
                    //Try to grab spines from corpses of dead players
                    std::vector<Player*> spiners;
                    for (GroupReference const* itr = gr->GetFirstMember(); itr != nullptr; itr = itr->next())
                    {
                        Player* pl = itr->GetSource();
                        if (pl && pl->IsInWorld() && me->GetMap() == pl->FindMap() && !pl->IsAlive() &&
                            me->GetDistance(pl) < 25.f && pl->HasItemCount(32408)) // Naj'entus Spine
                            spiners.push_back(pl);
                    }

                    if (Player* pl = spiners.empty() ? nullptr : spiners.size() == 1u ? spiners.front() :
                        Trinity::Containers::SelectRandomContainerElement(spiners))
                    {
                        BotWhisper("Taking 1 Naj'entus Spine from you");
                        me->CastSpell(najentus, 39948, true); // Hurl Spine
                        pl->DestroyItemCount(32408, 1, true); // Naj'entus Spine
                    }
                }
            }

            std::vector<Unit*> spines;
            //Find and free impaled player (player gets the spine)
            for (GroupReference const* itr = gr->GetFirstMember(); itr != nullptr; itr = itr->next())
            {
                Player* pl = itr->GetSource();
                //We don't make bots run to player to "click" the spine, so range is rather big
                if (pl && pl->IsInWorld() && me->GetMap() == pl->FindMap())
                {
                    auto is_impaled = [this](Unit const* unit) -> bool {
                        return unit->IsAlive() && unit->HasUnitState(UNIT_STATE_STUNNED) &&
                            me->GetDistance(unit) < 25.f && unit->HasAura(39837); // "Impaling Spine"
                    };

                    if (is_impaled(pl))
                        spines.push_back(pl->ToUnit());
                    if (pl->HaveBot())
                    {
                        BotMap const* bmap = pl->GetBotMgr()->GetBotMap();
                        for (BotMap::const_iterator ci = bmap->begin(); ci != bmap->end(); ++ci)
                        {
                            Creature* bot = ci->second;
                            if (bot && is_impaled(bot))
                                spines.push_back(bot->ToUnit());
                        }
                    }
                }
            }

            if (Unit* u = spines.empty() ? nullptr : spines.size() == 1u ? spines.front() :
                Trinity::Containers::SelectRandomContainerElement(spines))
            {
                if (GameObject const* spine = u->GetFirstGameObjectById(185584)) // Naj'entus Spine
                {
                    Player* receiver = u->GetTypeId() == TYPEID_PLAYER ? u->ToPlayer() : master;
                    if (spine->AI() && spine->AI()->OnGossipHello(receiver))
                    {
                        // Item is created by spell 39956 Create Naj'entus Spine - cannot target dead, force add item
                        if (!receiver->IsAlive())
                            receiver->AddItem(32408, 1); // Naj'entus Spine
                        return true;
                    }
                }
            }
        }
    }

    if (me->GetMapId() == 548 && isInWMOArea(_lastWMOAreaId, WMOAreaGroupVashj) && Rand() < 15) // Serpentshrine Cavern - Lady Vashj
    {
        uint32 alive_players = 0;
        std::vector<Player*> taintPlayers;
        for (MapReference const& ref : me->GetMap()->GetPlayers())
        {
            if (Player* player = ref.GetSource())
            {
                if (player->IsAlive())
                    ++alive_players;
                if (player->HasAuraType(SPELL_AURA_MOD_ROOT) && me->IsWithinDistInMap(player, 20.0f) &&
                    player->HasItemCount(31088, 1)) // Tainted Core
                    taintPlayers.push_back(player);
            }
        }

        if (!taintPlayers.empty() && alive_players <= 1)
        {
#if defined(TRINITY_COMPILER)
            static const uint32 ShieldGeneratorTriggerNPC = 19870;
#elif defined(AC_COMPILER)
            static const uint32 ShieldGeneratorTriggerNPC = WORLD_TRIGGER;
#endif
            std::list<Creature*> cList;
            Trinity::AllCreaturesOfEntryInRange check(me, ShieldGeneratorTriggerNPC, 100.f); // Invis KV Shield Generator
            Trinity::CreatureListSearcher<Trinity::AllCreaturesOfEntryInRange> csearcher(me, cList, check);
            Cell::VisitAllObjects(me, csearcher, 100.f);

            std::list<GameObject*> gList;
            auto is_shield_go = [](GameObject const* gobject) {
                switch (gobject->GetEntry())
                {
                    case 185051:
                    case 185052:
                    case 185053:
                    case 185054:
                        return true;
                    default:
                        return false;
                }
            };
            Trinity::GameObjectListSearcher gsearcher(me, gList, is_shield_go);
            Cell::VisitAllObjects(me, gsearcher, 100.f);

            static const auto get_shield_creature = [](GameObject const* gobject, std::list<Creature*> const& clist) {
                Creature* c = nullptr;
                float mindist = 10.0f;
                for (Creature* creature : clist)
                {
                    float dist = gobject->GetDistance(creature);
                    if (dist < mindist)
                    {
                        c = creature;
                        mindist = dist;
                    }
                }
                return c;
            };

            gList.remove_if([&cList](GameObject const* gobject) {
                Creature const* c = get_shield_creature(gobject, cList);
                return !c || c->GetCurrentSpell(CURRENT_CHANNELED_SPELL) == nullptr;
            });
            cList.remove_if([](Creature const* creature) {
                return creature->GetCurrentSpell(CURRENT_CHANNELED_SPELL) == nullptr;
            });

            ASSERT(cList.size() == gList.size());

            if (!gList.empty())
            {
                Player* player = taintPlayers.size() == 1u ? taintPlayers.front() : Trinity::Containers::SelectRandomContainerElement(taintPlayers);
                BotWhisper("Taking Tainted Core from you");
                GameObject* go = gList.size() == 1u ? gList.front() : Trinity::Containers::SelectRandomContainerElement(gList);
#if defined(TRINITY_COMPILER)
                Item* item = player->GetItemByEntry(31088); // Tainted Core
                SpellCastTargets targets;
                targets.SetGOTarget(go);
                sScriptMgr->OnItemUse(player, item, targets);
#elif defined(AC_COMPILER)
                Creature* cre = get_shield_creature(go, cList);
                ASSERT(cre);
                cre->DespawnOrUnsummon(1);
                player->DestroyItemCount(31088, 1, true); // Tainted Core
#endif
                return true;
            }
        }
    }

    if (me->GetMapId() == 631 && isInWMOArea(_lastWMOAreaId, WMOAreaGroupSvalna) && Rand() < 10) // Icecrown Citadel - Sister Svalna
    {
        if (Group const* gr = master->GetGroup())
        {
            if (Rand() < 4)
            {
                InstanceScript* iscript = me->GetMap()->ToInstanceMap()->GetInstanceScript();
                Creature* svalna = iscript ? iscript->GetCreature(9) : nullptr; // icecrown_citadel.h::DATA_SISTER_SVALNA
                if (!svalna)
                {
                    static const uint32 CREATURE_SISTER_SVALNA_N = 37126;
                    static const uint32 CREATURE_SISTER_SVALNA_H = 37126; //Acore - same id is used
                    Trinity::AllCreaturesOfEntryInRange check(master, me->GetMap()->IsHeroic() ? CREATURE_SISTER_SVALNA_H : CREATURE_SISTER_SVALNA_N, 60.f);
                    Trinity::CreatureSearcher<Trinity::AllCreaturesOfEntryInRange> searcher(master, svalna, check);
                    Cell::VisitAllObjects(master, searcher, 60.f);
                }

                if (svalna && svalna->HasAuraTypeWithMiscvalue(SPELL_AURA_SCHOOL_IMMUNITY, 127)) // Aether Shield
                {
                    //Try to grab spears from corpses of dead players
                    std::vector<Player*> spearers;
                    for (GroupReference const* itr = gr->GetFirstMember(); itr != nullptr; itr = itr->next())
                    {
                        Player* pl = itr->GetSource();
                        if (pl && pl->IsInWorld() && me->GetMap() == pl->FindMap() && !pl->IsAlive() &&
                            me->GetDistance(pl) < 25.f && pl->HasItemCount(50307)) // Infernal Spear
                            spearers.push_back(pl);
                    }

                    if (Player* pl = spearers.empty() ? nullptr : spearers.size() == 1u ? spearers.front() :
                        Trinity::Containers::SelectRandomContainerElement(spearers))
                    {
                        BotWhisper("Taking 1 Infernal Spear from you");
                        me->CastSpell(svalna, 71466, true); // Hurl Spear
                        pl->DestroyItemCount(50307, 1, true); // Infernal Spear
                    }
                }
            }

            auto is_impaled = [this](Unit const* unit) -> bool {
                return unit->IsAlive() && unit->HasUnitState(UNIT_STATE_STUNNED) &&
                    me->GetDistance(unit) < 25.f && unit->HasAura(71443); // "Impaling Spear"
            };

            std::vector<Unit*> spears;
            //Find and free impaled player (player gets the spear)
            for (GroupReference const* itr = gr->GetFirstMember(); itr != nullptr; itr = itr->next())
            {
                Player* pl = itr->GetSource();
                //We don't make bots run to player to "click" the spine, so range is rather big
                if (pl && pl->IsInWorld() && me->GetMap() == pl->FindMap())
                {

                    if (is_impaled(pl))
                        spears.push_back(pl->ToUnit());
                    if (pl->HaveBot())
                    {
                        BotMap const* bmap = pl->GetBotMgr()->GetBotMap();
                        for (BotMap::const_iterator ci = bmap->begin(); ci != bmap->end(); ++ci)
                        {
                            Creature* bot = ci->second;
                            if (bot && is_impaled(bot))
                                spears.push_back(bot->ToUnit());
                        }
                    }
                }
            }

            if (Unit* u = spears.empty() ? nullptr : spears.size() == 1u ? spears.front() :
                Trinity::Containers::SelectRandomContainerElement(spears))
            {
                Creature* spear = nullptr;
                Trinity::NearestCreatureEntryWithLiveStateInObjectRangeCheck check(*u, 38248, true, 5.f);
                Trinity::CreatureSearcher<Trinity::NearestCreatureEntryWithLiveStateInObjectRangeCheck> searcher(u, spear, check);
                Cell::VisitAllObjects(u, searcher, 5.f);

                if (spear)
                {
                    Player* receiver = u->GetTypeId() == TYPEID_PLAYER ? u->ToPlayer() : master;
                    me->CastSpell(spear, 71462, true); // "Remove Spear"
                    receiver->AddItem(50307, 1); // Infernal Spear
                    return true;
                }
            }
        }
    }

    return false;
}
//POSITION
AoeSpotsVec const& bot_ai::GetAoeSpots() const
{
    return IAmFree() ? _aoeSpots : master->GetBotMgr()->GetAoeSpots();
}

void bot_ai::CalculateAoeSpots(Unit const* unit, AoeSpotsVec& spots)
{
    std::list<WorldObject*> doList;
    NearbyHostileAoEDynobjectCheck check(unit, 60.f);
    Trinity::WorldObjectListSearcher<NearbyHostileAoEDynobjectCheck> searcher(unit, doList, check, GRID_MAP_TYPE_MASK_DYNAMICOBJECT);
    //unit->VisitNearbyObject(60.f, searcher);
    Cell::VisitAllObjects(unit, searcher, 60.f);

    //if (!doList.empty())
    //    TC_LOG_ERROR("scripts", "CalculateAoeSpots {} aoes around {}", uint32(doList.size()), unit->GetName());

    //filter and add to list
    DynamicObject const* dObj;
    SpellInfo const* spellInfo;
    for (std::list<WorldObject*>::const_iterator ci = doList.begin(); ci != doList.end(); ++ci)
    {
        dObj = (*ci)->ToDynObject();
        ASSERT_NODEBUGINFO(dObj);
        ASSERT_NODEBUGINFO(dObj->GetSpellId());
        spellInfo = sSpellMgr->GetSpellInfo(dObj->GetSpellId());
        if (IsPeriodicDynObjAOEDamage(spellInfo))
        {
            //TC_LOG_ERROR("scripts", "CalculateAoeSpots found {}'s aoe {} ({}) radius {} size {}",
            //    dObj->GetCaster()->GetName(), spellInfo->SpellName[0], spellInfo->Id, dObj->GetRadius(), dObj->GetObjectSize());

            float radius = dObj->GetRadius() + DEFAULT_PLAYER_BOUNDING_RADIUS;
            radius += (unit->GetVehicle() ? unit->GetVehicleBase()->GetCombatReach() : DEFAULT_PLAYER_COMBAT_REACH) * 1.2f;
            spots.push_back(AoeSpotsVec::value_type(*dObj, radius));
        }
    }

    if (unit->IsNPCBot() && unit->ToCreature()->IsFreeBot())
        return;

    //Additional: aoe coming from spawned npcs

    //Molten Core
    if (unit->GetMapId() == 409)  
    {
        std::list<GameObject*> gListMC;
        Trinity::AllGameObjectsWithEntryInRange checkMC(unit, GAMEOBJECT_HOT_COAL, 60.f);  
        Trinity::GameObjectListSearcher<Trinity::AllGameObjectsWithEntryInRange> searcherMC(unit, gListMC, checkMC);
        Cell::VisitAllObjects(unit, searcherMC, 60.f);

        float radius = 15.0f + DEFAULT_PLAYER_COMBAT_REACH;  
        for (std::list<GameObject*>::const_iterator ci = gListMC.cbegin(); ci != gListMC.cend(); ++ci)
            spots.push_back(AoeSpotsVec::value_type(*(*ci), radius));
    }
    //Aucheai Crypts
    else if (unit->GetMapId() == 558)
    {
        Creature* creature = nullptr;
        static const auto focus_fire_check = [](Creature const* c) {
            return (c->GetEntry() == CREATURE_FOCUS_FIRE_N || c->GetEntry() == CREATURE_FOCUS_FIRE_H);
        };
        Trinity::CreatureSearcher searcher2(unit, creature, focus_fire_check);
        Cell::VisitAllObjects(unit, searcher2, 50.f);

        if (creature)
        {
            spellInfo = sSpellMgr->GetSpellInfo(32302); //Fiery Blast
            float radius = spellInfo->_effects[0].CalcRadius() + DEFAULT_PLAYER_COMBAT_REACH * 2.0f;
            spots.push_back(AoeSpotsVec::value_type(*creature, radius));
        }
    }
    //The Eye of Eternity
    else if (unit->GetMapId() == 616 && unit->GetVehicle())
    {
        std::list<Creature*> cList;
        Trinity::AllCreaturesOfEntryInRange check2(unit->GetVehicleBase(), CREATURE_EOE_STATIC_FIELD, 60.f);
        Trinity::CreatureListSearcher<Trinity::AllCreaturesOfEntryInRange> searcher2(unit->GetVehicleBase(), cList, check2);
        //unit->GetVehicleBase()->VisitNearbyObject(60.f, searcher2);
        Cell::VisitAllObjects(unit->GetVehicleBase(), searcher2, 60.f);

        spellInfo = sSpellMgr->GetSpellInfo(57429); //Static Field damage
        float radius = spellInfo->_effects[0].CalcRadius() + unit->GetVehicleBase()->GetCombatReach() * 1.2f;
        for (std::list<Creature*>::const_iterator ci = cList.begin(); ci != cList.end(); ++ci)
            spots.push_back(AoeSpotsVec::value_type(*(*ci), radius));
    }
    //Magister's Terrace
    else if (unit->GetMapId() == 585)
    {
        std::list<Creature*> cList;
        static const auto kael_aoe_check = [](Creature const* c) {
            return (c->GetEntry() == CREATURE_MT_PHOENIX || c->GetEntry() == CREATURE_MT_ARCANE_SPHERE_N || c->GetEntry() == CREATURE_MT_ARCANE_SPHERE_H);
        };
        Trinity::CreatureListSearcher searcher3(unit, cList, kael_aoe_check);
        Cell::VisitAllObjects(unit, searcher3, 40.f);

        if (!cList.empty())
        {
            spellInfo = sSpellMgr->GetSpellInfo(44198); //Burn damage (44197 -> 44198)
            float radius = spellInfo->_effects[0].CalcRadius() + DEFAULT_PLAYER_COMBAT_REACH * 3.0f;
            for (Creature* c : cList)
                spots.emplace_back(*c, radius);
        }
    }
    //Zul'Aman
    else if (unit->GetMapId() == 568)
    {
        std::list<Creature*> cList;
        Trinity::AllCreaturesOfEntryInRange check2(unit, CREATURE_ZA_FIRE_BOMB, 40.f);
        Trinity::CreatureListSearcher<Trinity::AllCreaturesOfEntryInRange> searcher2(unit, cList, check2);
        //unit->VisitNearbyObject(40.f, searcher2);
        Cell::VisitAllObjects(unit, searcher2, 40.f);

        spellInfo = sSpellMgr->GetSpellInfo(42630); //Fire Bomb
        float radius = spellInfo->_effects[0].CalcRadius() + DEFAULT_PLAYER_COMBAT_REACH * 1.2f;
        for (std::list<Creature*>::const_iterator ci = cList.begin(); ci != cList.end(); ++ci)
            spots.push_back(AoeSpotsVec::value_type(*(*ci), radius));
    }
    //Uthgarde Keep
    else if (unit->GetMapId() == 574)
    {
        Creature* creature = nullptr;
        static const auto shadow_axe_check = [](Creature const* c) {
            return (c->GetEntry() == CREATURE_UK_SHADOW_AXE_N || c->GetEntry() == CREATURE_UK_SHADOW_AXE_H);
        };
        Trinity::CreatureSearcher searcher2(unit, creature, shadow_axe_check);
        Cell::VisitAllObjects(unit, searcher2, 40.f);

        if (creature)
        {
            spellInfo = sSpellMgr->GetSpellInfo(42751); //Shadow Axe
            float radius = spellInfo->_effects[0].CalcRadius() + DEFAULT_PLAYER_COMBAT_REACH * 2.0f;
            spots.push_back(AoeSpotsVec::value_type(*creature, radius));
        }
    }
    //Icecrown Citadel
    else if (unit->GetMapId() == 631)
    {
        std::list<Creature*> cList;
        Trinity::AllCreaturesOfEntryInRange check2(unit, CREATURE_ICC_OOZE_PUDDLE, 50.f);
        Trinity::CreatureListSearcher<Trinity::AllCreaturesOfEntryInRange> searcher2(unit, cList, check2);
        //unit->VisitNearbyObject(50.f, searcher2);
        Cell::VisitAllObjects(unit, searcher2, 50.f);

        for (std::list<Creature*>::const_iterator ci = cList.begin(); ci != cList.end(); ++ci)
        {
            float radius = (*ci)->GetObjectScale() * 2.5f + DEFAULT_PLAYER_COMBAT_REACH * 3.f; //grows
            spots.push_back(AoeSpotsVec::value_type(*(*ci), radius));
        }
    }

    //STUB
    //if (!unit->IsPlayer() || !unit->ToPlayer()->HaveBot())
    //    return;

    //switch (unit->GetMapId())
    //{
    //    case 409: //Molten Core
    //        break;
    //    default:
    //        return;
    //}

    //BotMap const* bmap = unit->ToPlayer()->GetBotMgr()->GetBotMap();
    //for (BotMap::const_iterator itr = bmap->begin(); itr != bmap->end(); ++itr)
    //{
    //    if (itr->second && itr->second->IsInWorld() && itr->second->IsAlive())
    //    {
    //        // Living Bomb
    //        if (unit->GetMapId() == 409 && !!itr->second->GetAuraEffect(SPELL_AURA_PERIODIC_TRIGGER_SPELL, SPELLFAMILY_GENERIC, 1646, 0))
    //            spots.push_back(AoeSpotsVec::value_type(itr->second->GetPosition(), 18.0));
    //    }
    //}
}

void bot_ai::CalculateAoeSafeSpots(Unit* target, float maxdist, AoeSafeSpotsVec& safespots) const
{
    if (!GetAoeSpots().empty())
    {
        //find 200 safe spots
        Position ppos;
        float distdelta = maxdist / 200.f;
        float angledelta = float(M_PI) / 12.5f;
        float aoedist = 0.f;
        float aoeangle;
        for (uint8 i = 0; i < 8; ++i)
        {
            aoeangle = 0.0f;
            for (uint8 j = 0; j < 25; ++j)
            {
                aoedist += distdelta;
                aoeangle += angledelta;

                ppos = target->GetFirstCollisionPosition(aoedist, Position::NormalizeOrientation(aoeangle - target->GetOrientation()));
                bool toofaraway = master->GetDistance(ppos) > maxdist;

                if (!toofaraway && !IsWithinAoERadius(ppos))
                    safespots.push_back(ppos);
            }
        }
    }
}

bool bot_ai::IsPeriodicDynObjAOEDamage(SpellInfo const* spellInfo)
{
    if (!spellInfo->IsPositive())
    {
        for (uint8 i = 0; i != MAX_SPELL_EFFECTS; ++i)
        {
            if (spellInfo->_effects[i].Effect == SPELL_EFFECT_PERSISTENT_AREA_AURA &&
                spellInfo->_effects[i].ApplyAuraName != 0)
            {
                switch (spellInfo->_effects[i].ApplyAuraName)
                {
                    case SPELL_AURA_PERIODIC_DAMAGE:
                    case SPELL_AURA_PERIODIC_DAMAGE_PERCENT:
                    case SPELL_AURA_POWER_BURN:
                    case SPELL_AURA_PERIODIC_LEECH:
                    //Most of these are damaging spells
                    case SPELL_AURA_PERIODIC_TRIGGER_SPELL:
                    case SPELL_AURA_PERIODIC_TRIGGER_SPELL_WITH_VALUE:
                    //Scripted spells (mostly, some of these are wrong or not periodic damage)
                    case SPELL_AURA_PERIODIC_DUMMY:
                    //Channeled spells with SPELL_AURA_PERIODIC_TRIGGER_SPELL -> damage on TARGET_DEST_CHANNEL_TARGET (mostly)
                    case SPELL_AURA_DUMMY:
                        return true;
                    default:
                        break;
                }
            }
        }
    }
    return false;
}
bool bot_ai::IsWithinAoERadius(Position const& pos) const
{
    AoeSpotsVec const& spots = GetAoeSpots();
    if (!spots.empty())
    {
        Unit const* mover = me->GetVehicle() ? me->GetVehicleBase() : me;
        float cr_diff = mover->GetCombatReach() - DEFAULT_PLAYER_COMBAT_REACH;
        for (AoeSpotsVec::const_iterator ci = spots.begin(); ci != spots.end(); ++ci)
            if (pos.GetExactDist(&ci->first) - cr_diff < ci->second)
                return true;
    }

    return false;
}
//Returns attack range based on given range
//If mounted: 20%
//If ranged: 125%
//If master is dead: max range
//If wanderer: 65% max range
float bot_ai::InitAttackRange(float origRange, bool ranged) const
{
    if (IsWanderer())
    {
        origRange = sWorld->GetMaxVisibleDistanceOnContinents() * 0.65f;
        if (IsFlagCarrier(me))
            origRange *= 0.67f;
    }
    else if (!master->IsAlive())
        origRange = sWorld->GetMaxVisibleDistanceOnContinents();
    else if (me->HasAuraType(SPELL_AURA_MOUNTED))
        origRange *= 0.2f;
    else if (ranged)
        origRange *= 1.25f;

    return origRange;
}
void bot_ai::_extendAttackRange(float& dist) const
{
    ASSERT(!IAmFree());

    uint8 rangeMode = master->GetBotMgr()->GetBotAttackRangeMode();
    if (master->GetBotMgr()->GetBotFollowDist() > 0)
    {
        float spelldist;
        if (rangeMode == BOT_ATTACK_RANGE_EXACT)
            spelldist = master->GetBotMgr()->GetBotExactAttackRange();
        else
            spelldist = GetSpellAttackRange(rangeMode == BOT_ATTACK_RANGE_LONG);
        dist = std::max<float>(dist, spelldist * 0.5f + 4.f);
    }
}
bool bot_ai::_canSwitchToTarget(Unit const* from, Unit const* newTarget, int8 byspell) const
{
    if (newTarget)
    {
        if (IAmFree())
        {
            if (newTarget != me->GetVictim() &&
                (!from || me->GetDistance(newTarget) < me->GetDistance(from) - 10.0f || newTarget->GetHealth() < from->GetHealth()) &&
                CanBotAttack(newTarget, byspell))
                return true;
        }
    }

    return false;
}
//Ranged attack position
void bot_ai::CalculateAttackPos(Unit* target, Position& pos, bool& force) const
{
    uint8 followdist = IAmFree() ? BotMgr::GetBotFollowDistMax() : master->GetBotMgr()->GetBotFollowDist();
    uint8 rangeMode = IAmFree() ? uint8(BOT_ATTACK_RANGE_LONG) : master->GetBotMgr()->GetBotAttackRangeMode();
    uint8 exactRange = rangeMode != BOT_ATTACK_RANGE_EXACT || IAmFree() ? 255 : master->GetBotMgr()->GetBotExactAttackRange();
    uint8 angleMode = IAmFree() ? uint8(BOT_ATTACK_ANGLE_NORMAL) : master->GetBotMgr()->GetBotAttackAngleMode();
    float dist = (rangeMode == BOT_ATTACK_RANGE_EXACT) ? exactRange : GetSpellAttackRange(rangeMode == BOT_ATTACK_RANGE_LONG) - 5.f;
    float angle = target->GetAbsoluteAngle(me);
    if (_botclass == BOT_CLASS_SPHYNX && target->GetVictim() == me && me->GetExactDist(target) < 30.0f)
        dist = me->GetExactDist(target);
    if ((target->m_movementInfo.GetMovementFlags() & MOVEMENTFLAG_FORWARD) && target->HasInArc(float(M_PI)/1.5f, me))
        dist = std::min<float>(dist + 4.f, 30.f);

    //if ranged try to acquire a position in the back (will be ignored if too far away from master)
    if (angleMode == BOT_ATTACK_ANGLE_AVOID_FRONTAL_AOE)
    {
        static const float rangedAngleDelta = float(M_PI) * 0.62f;
        if (HasRole(BOT_ROLE_RANGED) && !IAmFree() && !target->IsControlledByPlayer() && target->HasInArc(float(M_PI), me) &&
            (IsTank(master) || master->GetDistance(target) < 2.5f || !target->HasInArc(float(M_PI), master)))
            angle += (target->GetRelativeAngle(master) > 0.f) ? rangedAngleDelta : -rangedAngleDelta;
    }

    float clockwise = (me->GetEntry() % 2) ? 1.f : -1.f;
    float angleDelta1 = ((IsTank(master) && !IsTank(me)) ? frand(float(M_PI)*0.40f, float(M_PI)*0.60f) : frand(0.0f, float(M_PI)*0.15f)) * clockwise;
    float angleDelta2 = frand(0.0f, float(M_PI)*0.08f) * clockwise;

    Position ppos;

    if (me->GetVehicle())
    {
        ASSERT(!IAmFree());

        if (float vehdist = GetVehicleAttackDistanceOverride())
            dist = vehdist + 5.f;

        uint8 posSlot = master->GetBotMgr()->GetNpcBotSlot(me);
        clockwise = (posSlot % 2) ? 1.f : -1.f;

        Unit* angunit = target->GetVictim() ? target->GetVictim() : master->GetVehicle() ? master->GetVehicleBase() : master;
        if (angunit == me->GetVehicleBase() || angunit == me)
            angle = target->GetAbsoluteAngle(me->GetVehicleBase());
        else
            angle = target->GetAbsoluteAngle(angunit) + 0.5f * M_PI / master->GetNpcBotsCount() * posSlot * clockwise;

        for (uint8 i = 0; i < 4; ++i)
        {
            if (me->GetVehicleBase()->CanFly())
            {
                //collision point bug, distance shinked to 0, so use GetNearPoint
                float &tx = ppos.m_positionX, &ty = ppos.m_positionY, &tz = ppos.m_positionZ;
                target->GetNearPoint(me->GetVehicleBase(), tx, ty, tz, dist, Position::NormalizeOrientation(angle));
                if (!target->IsWithinLOS(tx, ty, tz))
                    dist *= i >= 3 ? 0.2f : i >= 2 ? 0.5f : 0.75f;
            }
            else
                ppos = target->GetFirstCollisionPosition(dist, Position::NormalizeOrientation(angle - target->GetOrientation()));
            //target->GetNearPoint(me->GetVehicleBase(), x, y, z, 0.f, dist, Position::NormalizeOrientation(angle));

            bool toofar = master->GetDistance(ppos) > (followdist > 30.f ? 60.f : followdist < 10 ? 20.f : float(followdist*2));
            bool isinaoe = (i == 0 && me->GetVehicleBase()->GetDistance(ppos) < 4.f && IsWithinAoERadius(*me->GetVehicleBase())) || IsWithinAoERadius(ppos);
            if (!toofar && !isinaoe)
                break;

            if (toofar)
            {
                if (i >= 1)
                    angle += -(clockwise) * angleDelta1/* * i*/;
                if (i >= 2)
                    dist = std::max(0.f, dist - 5.f);
            }
            if (isinaoe)
            {
                //TC_LOG_ERROR("scripts", "CalculateAttackPos {} veh skipped aoe pos", me->GetName());
                if (me->GetVehicleBase()->CanFly())
                    ppos.m_positionZ += (master->GetPositionZ() < target->GetPositionZ()) ? -8.f : 8.f;
                else
                    angle += angleDelta2 * 2.f;
            }
        }

        pos.Relocate(ppos);
        //pos.m_positionX = x;
        //pos.m_positionY = y;
        //pos.m_positionZ = z;

        return;
    }

    AoeSpotsVec const& aoespots = GetAoeSpots();

    bool toofaraway;

    if (!aoespots.empty())
    {
        ppos.Relocate(me);
        toofaraway = master->GetDistance(ppos) > (followdist > 38 ? 38.f : followdist < 20 ? 20.f : float(followdist));
        bool outoflos = !target->IsWithinLOS(ppos.m_positionX, ppos.m_positionY, ppos.m_positionZ);
        bool isinaoe = IsWithinAoERadius(ppos);
        bool canattack = HasRole(BOT_ROLE_RANGED) || me->IsWithinMeleeRangeAt(ppos, target);
        if (!toofaraway && !outoflos && !isinaoe && canattack)
        {
            //if (!aoespots.empty())
            //    TC_LOG_ERROR("scripts", "CalculateAttackPos {} spot is still safe", me->GetName());

            pos.Relocate(ppos);
            return;
        }
    }

    AoeSafeSpotsVec safespots;
    CalculateAoeSafeSpots(target, float(followdist), safespots);

    bool angle_reset_to_master = false;
    uint8 collision_dist_max = IAmFree() ? 30 : 38;
    for (uint8 i = 0; i < 5; ++i)
    {
        ppos = target->GetFirstCollisionPosition(dist, Position::NormalizeOrientation(angle - target->GetOrientation()));
        toofaraway = master->GetDistance(ppos) > (followdist > collision_dist_max ? float(collision_dist_max) : followdist < 20 ? 20.f : float(followdist));
        if (!toofaraway)
            break;

        if (!angle_reset_to_master)
        {
            angle_reset_to_master = true;
            angle = target->GetAbsoluteAngle(master);
        }
        else
            angle += angleDelta1;

        if (i >= 1 && i <= 3)
            dist = std::max<float>(0.f, dist - 5.f);
    }

    if (!safespots.empty())
    {
        //find closest safe spot
        Position const* closestPos = nullptr;
        Position const* closestAttackPos = nullptr;
        float minposdist = 100.f;
        float minattackposdist = 100.f;
        for (AoeSafeSpotsVec::const_iterator ci = safespots.begin(); ci != safespots.end(); ++ci)
        {
            float curdist = me->GetExactDist2d(*ci);
            if (curdist < minposdist)
            {
                closestPos = &(*ci);
                minposdist = curdist;
            }
            if (curdist < minattackposdist &&
                (HasRole(BOT_ROLE_RANGED) ? (target->GetDistance(*ci) - me->GetCombatReach() < dist) : me->IsWithinMeleeRangeAt(*ci, target)))
            {
                closestAttackPos = &(*ci);
                minattackposdist = curdist;
            }
        }

        //TC_LOG_ERROR("scripts", "CalculateAttackPos {} safe spots, chosen at dist {}", uint32(safespots.size()), mindist);
        pos.Relocate(closestAttackPos ? closestAttackPos : closestPos ? closestPos : me);
        force = true;
        return;
    }
    else if (!aoespots.empty() && !IAmFree())
    {
        pos.Relocate(master);
        force = true;
        return;
    }

    // Ranged bots that are being targeted should move towards a tank bot or towards the player
    if (!IAmFree() && !IsTank(me) && HasRole(BOT_ROLE_RANGED) && target->GetVictim() == me && !CCed(target))
    {
        std::vector<Unit const*> safetyTargets;
        if (Group const* gr = master->GetGroup())
        {
            for (GroupReference const* itr = gr->GetFirstMember(); itr != nullptr; itr = itr->next())
            {
                Player const* pl = itr->GetSource();
                if (!pl || !pl->IsInMap(me) || pl->GetDistance(me) > VISIBILITY_DISTANCE_NORMAL)
                    continue;
                if (pl->IsAlive() && !pl->HasUnitState(UNIT_STATE_ISOLATED) && IsTank(pl))
                    safetyTargets.push_back(pl);
                if (!pl->HaveBot())
                    continue;
                BotMap const* map = pl->GetBotMgr()->GetBotMap();
                for (BotMap::const_iterator citr = map->begin(); citr != map->end(); ++citr)
                {
                    Creature const* c = citr->second;
                    if (c && c->IsInWorld() && me->GetMap() == c->FindMap() && c->IsAlive() && !c->HasUnitState(UNIT_STATE_ISOLATED) && IsTank(c) && c->GetBotAI()->HasRole(BOT_ROLE_DPS))
                        safetyTargets.push_back(c);
                }
            }
        }
        else
        {
            BotMap const* map = master->GetBotMgr()->GetBotMap();
            for (BotMap::const_iterator citr = map->begin(); citr != map->end(); ++citr)
            {
                Creature const* c = citr->second;
                if (c && c->IsInWorld() && me->GetMap() == c->FindMap() && c->IsAlive() && !c->HasUnitState(UNIT_STATE_ISOLATED) && IsTank(c) && c->GetBotAI()->HasRole(BOT_ROLE_DPS))
                    safetyTargets.push_back(c);
            }
        }
        if (safetyTargets.empty() && master->IsAlive())
            safetyTargets.push_back(master);

        if (!safetyTargets.empty())
        {
            static const float ThresholdDistance = 1.5f;
            Unit const* moveTarget = safetyTargets.size() == 1u ? safetyTargets.front() : safetyTargets[me->GetEntry() % safetyTargets.size()];
            if (moveTarget->GetDistance(target) > ThresholdDistance && me->GetDistance(moveTarget) > ThresholdDistance * 2.0f)
            {
                float distanceMod = moveTarget->HasInArc(float(M_PI), target) ? 0.5f : -1.5f;
                pos.Relocate(moveTarget->GetFirstCollisionPosition(ThresholdDistance * distanceMod, Position::NormalizeOrientation(moveTarget->GetAbsoluteAngle(target) - moveTarget->GetOrientation())));
                force = true;
                return;
            }
        }
    }

    pos.Relocate(ppos);
    if (!me->IsWithinLOSInMap(target, LINEOFSIGHT_ALL_CHECKS, VMAP::ModelIgnoreFlags::M2))
        force = true;
}
// Forces bot to chase opponent (if ranged then distance depends on follow distance)
void bot_ai::GetInPosition(bool force, Unit* newtarget, Position* mypos)
{
    Unit* mover = me->GetVehicle() ? me->GetVehicleBase() : me;
    if (HasBotCommandState(BOT_COMMAND_STAY))
        return;
    if (!IAmFree() && !master->GetBotMgr()->GetBotAllowCombatPositioning())
        return;
    if (CCed(mover, true) || (mover == me && JumpingOrFalling()))
        return;
    if (!newtarget)
        newtarget = me->GetVictim();
    if (!newtarget)
        return;
    if ((!newtarget->IsInCombat() || (mover->isMoving()/* && Rand() > 50*/)) && !force && !(_atHome && _evadeMode))
        return;
    if (IsCasting(mover))
        return;
    if (IsShootingWand(mover) && newtarget->GetVictim() == mover)
        return;
    if (UpdateImpossibleChase(newtarget))
        return;
    if (AdjustTankingPosition(newtarget))
        return;

    if (!IAmFree() && master->GetBotMgr()->GetBotAttackRangeMode() == BOT_ATTACK_RANGE_EXACT &&
        master->GetBotMgr()->GetBotExactAttackRange() == 0)
    {
        attackpos.m_positionX = newtarget->GetPositionX() - frand(0.5f, 1.5f) * std::cos(me->GetAbsoluteAngle(newtarget));
        attackpos.m_positionY = newtarget->GetPositionY() - frand(0.5f, 1.5f) * std::sin(me->GetAbsoluteAngle(newtarget));
        attackpos.m_positionZ = newtarget->GetPositionZ();
        if (me->GetExactDist2d(&attackpos) > 3.5f)
            BotMovement(BOT_MOVE_POINT, &attackpos);
            //me->GetMotionMaster()->MovePoint(newtarget->GetMapId(), attackpos);
        return;
    }

    uint8 followdist = IAmFree() ? BotMgr::GetBotFollowDistMax() : master->GetBotMgr()->GetBotFollowDist();
    if (IsRanged() || (!IAmFree() && !GetAoeSpots().empty()))
    {
        //do not allow constant runaway from player
        if (!force && newtarget->GetTypeId() == TYPEID_PLAYER &&
            me->GetDistance(newtarget) < 6 + urand(followdist/4, followdist/3))
            return;

        if (!mypos)
            CalculateAttackPos(newtarget, attackpos, force);
        else
        {
            attackpos.m_positionX = mypos->m_positionX;
            attackpos.m_positionY = mypos->m_positionY;
            attackpos.m_positionZ = mypos->m_positionZ;
        }
        //TC_LOG_ERROR("scripts", "GetInPosition {} to {} dist {}, to pos {}", me->GetName(),
        //    newtarget->GetName(), me->GetExactDist2d(newtarget), me->GetExactDist2d(&attackpos));
        if (mover->GetExactDist2d(&attackpos) > (force ? 0.1f : 4.f))
        {
            BotMovement(BOT_MOVE_POINT, &attackpos);
            //me->GetMotionMaster()->MovePoint(newtarget->GetMapId(), attackpos);
            if (mover == me && !me->HasUnitState(UNIT_STATE_MELEE_ATTACKING) && CanBotAttackOnVehicle())
                me->SetInFront(newtarget);
            else if (!mover->HasUnitState(UNIT_STATE_MELEE_ATTACKING))
                mover->SetInFront(newtarget);
        }
    }
    else
    {
        if (!JumpingOrFalling() && ((!mover->HasUnitState(UNIT_STATE_CHASE) && !mover->isMoving()) || (!mover->HasUnitState(UNIT_STATE_CHASE_MOVE) && mover->GetDistance(newtarget) > 1.5f)))
            BotMovement(BOT_MOVE_CHASE, nullptr, newtarget);
            //me->GetMotionMaster()->MoveChase(newtarget);
    }

    if (newtarget != me->GetVictim() && (mover == me || CanBotAttackOnVehicle()))
    {
        if (!me->Attack(newtarget, !HasRole(BOT_ROLE_RANGED)))
            me->SetInFront(newtarget);
    }
}
//Bots cannot dodge/parry from behind so try to condense enemies at front
//opponent is always valid
bool bot_ai::AdjustTankingPosition(Unit const* mytarget) const
{
    //problem: chasing unit is constantly moving. Whoever the hell did that
//    if (/*!IsTank() || */!me->IsInCombat() || me->isMoving() || IsCasting() ||
//        JumpingOrFalling() || CCed(me, true) || Rand() > 10 + 20*me->GetMap()->IsDungeon())
//        return;
    if (/*!IsTank() || */!me->IsInCombat() || IsCasting() || me->GetVehicle() ||
        JumpingOrFalling() || CCed(me, true) || Rand() > 10 + 20*me->GetMap()->IsDungeon() ||
        HasBotCommandState(BOT_COMMAND_MASK_UNMOVING))
        return false;

    Unit::AttackerSet const& myattackers = me->getAttackers();
    if (myattackers.size() < 2)
        return false;

    if (IsMelee())
    {
        if (!me->IsWithinMeleeRange(mytarget))
            return false;
    }
    else
    {
        uint8 rangeMode = IAmFree() ? uint8(BOT_ATTACK_RANGE_LONG) : master->GetBotMgr()->GetBotAttackRangeMode();
        uint8 exactRange = rangeMode != BOT_ATTACK_RANGE_EXACT || IAmFree() ? 255 : master->GetBotMgr()->GetBotExactAttackRange();
        float dist = (rangeMode == BOT_ATTACK_RANGE_EXACT) ? exactRange : GetSpellAttackRange(rangeMode == BOT_ATTACK_RANGE_LONG);

        if (me->GetDistance(mytarget) > dist)
            return false;
    }

    //TC_LOG_ERROR("entities.player", "AdjustTankPosition() by {}", me->GetName());

    uint32 bCount = 0;
    for (Unit::AttackerSet::const_iterator itr = myattackers.begin(); itr != myattackers.end(); ++itr)
    {
        if (/*!CCed(*itr) && */(*itr)->IsWithinMeleeRange(me) && !me->HasInArc(float(M_PI), *itr))
            ++bCount;
            //if (++bCount)
            //    break;
    }

    if (bCount == 0)
        return false;

    //TC_LOG_ERROR("entities.player", "AdjustTankPosition(): atts {}, behind {}", uint32(myattackers.size()), bCount);

    //calculate new position
    float x = me->GetPositionX();
    float y = me->GetPositionY();
    float z = me->GetPositionZ();
    float ori = CCed(mytarget, true) ? me->GetOrientation() + 0.75f * M_PI : me->GetOrientation();
    float const moveDist = -1.f * std::max<float>(mytarget->GetCombatReach(), 3.f);
    float moveX;
    float moveY;
    //bool move = false;
    for (uint32 i = 0; i != 6; ++i)
    {
        if (i)
        {
            ori = Position::NormalizeOrientation(ori + (i+1)*(M_PI*0.31f));
        }

        //move back
        moveX = moveDist * std::cos(ori);
        moveY = moveDist * std::sin(ori);

        Position ppos;
        ppos.Relocate(x+moveX, y+moveY, z);
        if (me->IsWithinLOS(x+moveX, y+moveY, z) && !IsWithinAoERadius(ppos))
            break;

        if (i == 2)
        {
            moveX *= 0.2f;
            moveY *= 0.2f;
        }
    }

    x+= moveX;
    y+= moveY;

    me->UpdateAllowedPositionZ(x, y, z);
    if (me->GetPositionZ() < z)
        z += 0.75f; //prevent going underground

    //if (CCed(mytarget, true))
    //    me->AttackStop();
    //me->SetOrientation(ori);
    Position position;
    position.Relocate(x, y, z);
    BotMovement(BOT_MOVE_POINT, &position);
    //me->GetMotionMaster()->MovePoint(me->GetMapId(), x, y, z, false);
    return true;
}

void bot_ai::CheckAttackState()
{
    if (me->GetVictim() && me->GetVictim()->IsAlive())
    {
        if (HasRole(BOT_ROLE_DPS) && !me->HasAuraType(SPELL_AURA_MOD_STEALTH) && !me->HasAuraType(SPELL_AURA_MOD_INVISIBILITY) &&
            !IsShootingWand())
            DoMeleeAttackIfReady();
    }
}
//Move behind current target if needed (avoid cleaves and dodges/parries, also rogues/ferals)
void bot_ai::MoveBehind(Unit const* target) const
{
    if (_moveBehindTimer > lastdiff || HasBotCommandState(BOT_COMMAND_MASK_UNMOVING) || HasRole(BOT_ROLE_RANGED) || JumpingOrFalling() ||
        /*(me->isMoving() && target->GetTypeId() != TYPEID_PLAYER) ||*/
        me->GetVehicle() || (IsTank() && target->GetVictim() == me) || CCed(me, true) ||
        !target->IsWithinCombatRange(me, ATTACK_DISTANCE) || !target->HasInArc(float(M_PI), me))
        return;

    const bool targetMe = target->GetVictim() == me;
    const bool cced = CCed(target);
    const bool isPlayer = target->GetTypeId() == TYPEID_PLAYER;

    if ((_botclass == BOT_CLASS_ROGUE || GetBotStance() == DRUID_CAT_FORM) ? (!targetMe || cced || isPlayer) : (!targetMe && (!cced || isPlayer)))
    {
        float myangle = Position::NormalizeOrientation(target->GetAbsoluteAngle(me) + float(M_PI));
        float mydist = me->GetCombatReach();
        Position position;
        target->GetNearPoint(me, position.m_positionX, position.m_positionY, position.m_positionZ, mydist, myangle);

        if (IsWithinAoERadius(position))
            return;

        BotMovement(BOT_MOVE_POINT, &position);
        const_cast<bot_ai*>(this)->_moveBehindTimer = urand(1000, (_botclass == BOT_CLASS_ROGUE || GetBotStance() == DRUID_CAT_FORM) ? 2000 : 4000);
    }
}
//MOUNT SUPPORT
uint32 bot_ai::_selectMountSpell() const
{
    uint8 minLevel60 = BotMgr::GetNpcBotMountLevel60();
    uint8 minLevel100 = BotMgr::GetNpcBotMountLevel100();

    if (me->GetLevel() < minLevel60)
        return 0;

    uint32 myMountSpellId = 0;
    uint32 masterMountSpellId = 0;

    InstanceTemplate const* instt = sObjectMgr->GetInstanceTemplate(me->GetMap()->GetId());
    bool map_allows_mount = (!me->GetMap()->IsDungeon() || me->GetMap()->IsBattlegroundOrArena()) && (!instt || instt->AllowMount);
    if (!IAmFree() ? !master->IsMounted() : !(map_allows_mount && evadeDelayTimer < lastdiff * 2))
        return 0;

    Unit::AuraEffectList const& mounts = master->GetAuraEffectsByType(SPELL_AURA_MOUNTED);
    int32 maxMountSpeed = !IAmFree() ? 0 : 999;
    if (!IAmFree())
    {
        Aura const* mountAura = nullptr;
        for (AuraEffect const* meff : mounts)
        {
            for (uint8 i = EFFECT_0; i < MAX_SPELL_EFFECTS; ++i)
            {
                AuraEffect const* maeff = meff->GetBase()->GetEffect(i);
                if (maeff && (maeff->GetSpellEffectInfo().IsAura(master->CanFly() ? SPELL_AURA_MOD_INCREASE_MOUNTED_FLIGHT_SPEED : SPELL_AURA_MOD_INCREASE_MOUNTED_SPEED)) &&
                    maeff->GetAmount() > maxMountSpeed)
                {
                    maxMountSpeed = maeff->GetAmount();
                    mountAura = meff->GetBase();
                }
            }
        }

        if (maxMountSpeed < 20)
            return 0;

        masterMountSpellId = mountAura ? mountAura->GetId() : 0;
    }

    //Winter Veil addition
    if (sGameEventMgr->IsActiveEvent(GAME_EVENT_WINTER_VEIL))
        myMountSpellId = master->CanFly() ? REINDEER_FLY : REINDEER;
    if (!myMountSpellId && me->GetMapId() == 531) //Ahn'Qiraj
    {
        //Select AQ40 mount
        static const std::array<uint32, 4> QirajiMountSpellIds = { QIRAJI_BATTLE_TANK_1, QIRAJI_BATTLE_TANK_2, QIRAJI_BATTLE_TANK_3, QIRAJI_BATTLE_TANK_4 };
        //Count Black Qiraji Battle Tank too
        if (masterMountSpellId == 26656 || std::find(QirajiMountSpellIds.cbegin(), QirajiMountSpellIds.cend(), masterMountSpellId) != QirajiMountSpellIds.cend())
            myMountSpellId = QirajiMountSpellIds[me->GetEntry() % QirajiMountSpellIds.size()];
    }

    if (!myMountSpellId)
    {
        using MountArray = std::array<uint32, NUM_MOUNTS_PER_SPEED>;

        bool can_fly = !IAmFree() ? master->CanFly() : false; //(!instt && me->GetMap()->GetEntry()->ExpansionID > 0);
        bool useSlowMount = can_fly ? (me->GetLevel() < 70 || maxMountSpeed < 220) : (me->GetLevel() < minLevel100 || maxMountSpeed < 80);

        if (!can_fly)
        {
            //Select by class
            switch (_botclass)
            {
                case BOT_CLASS_DARK_RANGER:
                    myMountSpellId = BOT_DARK_RANGER_MOUNT;
                    break;
                case BOT_CLASS_WARLOCK:
                    myMountSpellId = useSlowMount ? BOT_WARLOCK_MOUNT : BOT_WARLOCK_FAST_MOUNT;
                    break;
                case BOT_CLASS_PALADIN:
                    if (me->GetRace() == RACE_BLOODELF)
                        myMountSpellId = useSlowMount ? BOT_BE_PALLY_MOUNT : BOT_BE_PALLY_FAST_MOUNT;
                    else
                        myMountSpellId = useSlowMount ? BOT_ALLI_PALLY_MOUNT : BOT_ALLI_PALLY_FAST_MOUNT;
                    break;
                case BOT_CLASS_DEATH_KNIGHT:
                    myMountSpellId = BOT_DEATH_KNIGHT_MOUNT;
                    break;
                default:
                    break;
            }
            //Select by race
            if (!myMountSpellId)
            {
                static const MountArray MOUNTS_60_HUMAN = { BOT_MOUNT_HUMAN_60_1, BOT_MOUNT_HUMAN_60_2, BOT_MOUNT_HUMAN_60_3 };
                static const MountArray MOUNTS_60_ORC = { BOT_MOUNT_ORC_60_1, BOT_MOUNT_ORC_60_2, BOT_MOUNT_ORC_60_3 };
                static const MountArray MOUNTS_60_DWARF = { BOT_MOUNT_DWARF_60_1, BOT_MOUNT_DWARF_60_2, BOT_MOUNT_DWARF_60_3 };
                static const MountArray MOUNTS_60_NIGHTELF = { BOT_MOUNT_NIGHTELF_60_1, BOT_MOUNT_NIGHTELF_60_2, BOT_MOUNT_NIGHTELF_60_3 };
                static const MountArray MOUNTS_60_FORSAKEN = { BOT_MOUNT_FORSAKEN_60_1, BOT_MOUNT_FORSAKEN_60_2, BOT_MOUNT_FORSAKEN_60_3 };
                static const MountArray MOUNTS_60_TAUREN = { BOT_MOUNT_TAUREN_60_1, BOT_MOUNT_TAUREN_60_2, BOT_MOUNT_TAUREN_60_3 };
                static const MountArray MOUNTS_60_GNOME = { BOT_MOUNT_GNOME_60_1, BOT_MOUNT_GNOME_60_2, BOT_MOUNT_GNOME_60_3 };
                static const MountArray MOUNTS_60_TROLL = { BOT_MOUNT_TROLL_60_1, BOT_MOUNT_TROLL_60_2, BOT_MOUNT_TROLL_60_3 };
                static const MountArray MOUNTS_60_BLOODELF = { BOT_MOUNT_BLOODELF_60_1, BOT_MOUNT_BLOODELF_60_2, BOT_MOUNT_BLOODELF_60_3 };
                static const MountArray MOUNTS_60_DRAENEI = { BOT_MOUNT_DRAENEI_60_1, BOT_MOUNT_DRAENEI_60_2, BOT_MOUNT_DRAENEI_60_3 };

                static const MountArray MOUNTS_100_HUMAN = { BOT_MOUNT_HUMAN_100_1, BOT_MOUNT_HUMAN_100_2, BOT_MOUNT_HUMAN_100_3 };
                static const MountArray MOUNTS_100_ORC = { BOT_MOUNT_ORC_100_1, BOT_MOUNT_ORC_100_2, BOT_MOUNT_ORC_100_3 };
                static const MountArray MOUNTS_100_DWARF = { BOT_MOUNT_DWARF_100_1, BOT_MOUNT_DWARF_100_2, BOT_MOUNT_DWARF_100_3 };
                static const MountArray MOUNTS_100_NIGHTELF = { BOT_MOUNT_NIGHTELF_100_1, BOT_MOUNT_NIGHTELF_100_2, BOT_MOUNT_NIGHTELF_100_3 };
                static const MountArray MOUNTS_100_FORSAKEN = { BOT_MOUNT_FORSAKEN_100_1, BOT_MOUNT_FORSAKEN_100_2, BOT_MOUNT_FORSAKEN_100_3 };
                static const MountArray MOUNTS_100_TAUREN = { BOT_MOUNT_TAUREN_100_1, BOT_MOUNT_TAUREN_100_2, BOT_MOUNT_TAUREN_100_3 };
                static const MountArray MOUNTS_100_GNOME = { BOT_MOUNT_GNOME_100_1, BOT_MOUNT_GNOME_100_2, BOT_MOUNT_GNOME_100_3 };
                static const MountArray MOUNTS_100_TROLL = { BOT_MOUNT_TROLL_100_1, BOT_MOUNT_TROLL_100_2, BOT_MOUNT_TROLL_100_3 };
                static const MountArray MOUNTS_100_BLOODELF = { BOT_MOUNT_BLOODELF_100_1, BOT_MOUNT_BLOODELF_100_2, BOT_MOUNT_BLOODELF_100_3 };
                static const MountArray MOUNTS_100_DRAENEI = { BOT_MOUNT_DRAENEI_100_1, BOT_MOUNT_DRAENEI_100_2, BOT_MOUNT_DRAENEI_100_3 };

                Optional<MountArray> myMounts;
                switch (me->GetRace())
                {
                    case RACE_HUMAN:         myMounts = useSlowMount ? MOUNTS_60_HUMAN : MOUNTS_100_HUMAN;       break;
                    case RACE_ORC:           myMounts = useSlowMount ? MOUNTS_60_ORC : MOUNTS_100_ORC;           break;
                    case RACE_DWARF:         myMounts = useSlowMount ? MOUNTS_60_DWARF : MOUNTS_100_DWARF;       break;
                    case RACE_NIGHTELF:      myMounts = useSlowMount ? MOUNTS_60_NIGHTELF : MOUNTS_100_NIGHTELF; break;
                    case RACE_UNDEAD_PLAYER: myMounts = useSlowMount ? MOUNTS_60_FORSAKEN : MOUNTS_100_FORSAKEN; break;
                    case RACE_TAUREN:        myMounts = useSlowMount ? MOUNTS_60_TAUREN : MOUNTS_100_TAUREN;     break;
                    case RACE_GNOME:         myMounts = useSlowMount ? MOUNTS_60_GNOME : MOUNTS_100_GNOME;       break;
                    case RACE_TROLL:         myMounts = useSlowMount ? MOUNTS_60_TROLL : MOUNTS_100_TROLL;       break;
                    case RACE_BLOODELF:      myMounts = useSlowMount ? MOUNTS_60_BLOODELF : MOUNTS_100_BLOODELF; break;
                    case RACE_DRAENEI:       myMounts = useSlowMount ? MOUNTS_60_DRAENEI : MOUNTS_100_DRAENEI;   break;
                    default:                                                                                     break;
                }

                if (myMounts)
                    myMountSpellId = (*myMounts)[me->GetEntry() % myMounts->size()];
            }
        }
        else //if (can_fly)
        {
            if (GetBotClass() == BOT_CLASS_DRUID && GetSpell(33943))
                myMountSpellId = useSlowMount ? 33943 : GetSpell(33943);
            else
            {
                static const MountArray MOUNTS_150_ALLIANCE = { BOT_MOUNT_FLY_ALLIANCE_150_1, BOT_MOUNT_FLY_ALLIANCE_150_2, BOT_MOUNT_FLY_ALLIANCE_150_3 };
                static const MountArray MOUNTS_150_HORDE = { BOT_MOUNT_FLY_HORDE_150_1, BOT_MOUNT_FLY_HORDE_150_2, BOT_MOUNT_FLY_HORDE_150_3 };
                static const MountArray MOUNTS_280_ALLIANCE = { BOT_MOUNT_FLY_ALLIANCE_280_1, BOT_MOUNT_FLY_ALLIANCE_280_2, BOT_MOUNT_FLY_ALLIANCE_280_3 };
                static const MountArray MOUNTS_280_HORDE = { BOT_MOUNT_FLY_HORDE_280_1, BOT_MOUNT_FLY_HORDE_280_2, BOT_MOUNT_FLY_HORDE_280_3 };

                Optional<MountArray> myMounts;
                if (me->GetRaceMask() & RACEMASK_ALLIANCE)
                    myMounts = useSlowMount ? MOUNTS_150_ALLIANCE : MOUNTS_280_ALLIANCE;
                else if (me->GetRaceMask() & RACEMASK_HORDE)
                    myMounts = useSlowMount ? MOUNTS_150_HORDE : MOUNTS_280_HORDE;

                if (myMounts)
                    myMountSpellId = (*myMounts)[me->GetEntry() % myMounts->size()];
            }
        }
    }

    if (!myMountSpellId) // shouldn't happen normally
    {
        if (masterMountSpellId)
            myMountSpellId = masterMountSpellId;
        else if (!mounts.empty())
            myMountSpellId = mounts.front()->GetId();
    }

    return myMountSpellId;
}
void bot_ai::_updateMountedState()
{
    bool aura = me->HasAuraType(SPELL_AURA_MOUNTED);
    bool mounted = me->IsMounted() && (_botclass != BOT_CLASS_ARCHMAGE || aura);
    bool template_fly = me->GetCreatureTemplate()->Movement.Flight != CreatureFlightMovementType::None;
    bool druid_fly = GetBotStance() == DRUID_FLIGHT_FORM;
    Unit const* victim = me->GetVictim();

    //allow dismount
    if (!CanMount() && !aura && !mounted && !druid_fly)
        return;

    if ((aura || mounted || template_fly || druid_fly) &&
        (!master->IsMounted() || aura != mounted || (!mounted && !druid_fly && template_fly) ||
            (me->IsInCombat() && (opponent || disttarget)) ||
            (IAmFree() && victim && me->IsWithinDist(victim, IsMelee() ? 5.0f : GetSpellAttackRange(true), false))))
    {
        if (druid_fly)
            removeShapeshiftForm();
        else
            DismountBot();
        return;
    }

    if (druid_fly || me->IsMounted() || me->GetVehicle() || me->HasUnitMovementFlag(MOVEMENTFLAG_SWIMMING) || !IsOutdoors() ||
        master->IsInCombat() || me->IsInCombat() || me->GetVictim() || IsCasting() || IsFlagCarrier(me) ||
        (HasBotCommandState(BOT_COMMAND_STAY) && GetBG() && GetBG()->GetStatus() != STATUS_IN_PROGRESS))
        return;

    if (IAmFree())
    {
        if (!IsWanderer() || me->GetLevel() < BotMgr::GetNpcBotMountLevel60() || me->HasAuraType(SPELL_AURA_PERIODIC_DAMAGE) ||
            Feasting() || GetHealthPCT(me) < 80 || (CanDrink() && me->GetMaxPower(POWER_MANA) > 1 && GetManaPCT(me) < 70))
            return;
    }

    if (uint32 mount_spell_id = _selectMountSpell())
    {
        if (me->HasAuraType(SPELL_AURA_MOUNTED))
            me->RemoveAurasByType(SPELL_AURA_MOUNTED);

        if (!((_botclass == BOT_CLASS_DRUID || _botclass == BOT_CLASS_SHAMAN) && me->GetShapeshiftForm() != FORM_NONE) || removeShapeshiftForm())
            doCast(me, mount_spell_id);
    }
}
//STANDSTATE
void bot_ai::_updateStandState() const
{
    if (IAmFree())
    {
        if (CanSit() && !IsWanderer())
        {
            if (_atHome && !_evadeMode && !me->IsInCombat() && !me->isMoving() &&
                me->IsStandState() && Rand() < 15)
            {
                uint16 mapid;
                Position pos;
                GetHomePosition(mapid, &pos);
                if (me->GetExactDist(&pos) < 5 && me->GetOrientation() == pos.GetOrientation())
                {
                    if (_botclass == BOT_CLASS_DRUID && me->GetShapeshiftForm() != FORM_NONE)
                        const_cast<bot_ai*>(this)->removeShapeshiftForm();

                    me->SetStandState(UNIT_STAND_STATE_SIT);
                }
            }
        }
        else if (me->IsSitState() && !me->HasInterruptFlag(AURA_INTERRUPT_FLAG_NOT_SEATED))
            me->SetStandState(UNIT_STAND_STATE_STAND);

        return;
    }

    if (me->GetVehicle())
        return;

    if ((master->GetStandState() == UNIT_STAND_STATE_STAND || !CanSit()) &&
        me->GetStandState() == UNIT_STAND_STATE_SIT &&
        !me->HasInterruptFlag(AURA_INTERRUPT_FLAG_NOT_SEATED))
        me->SetStandState(UNIT_STAND_STATE_STAND);
    if (CanSit() && !me->IsInCombat() && !me->isMoving() &&
        (master->GetStandState() == UNIT_STAND_STATE_SIT || me->HasInterruptFlag(AURA_INTERRUPT_FLAG_NOT_SEATED)) &&
        me->GetStandState() == UNIT_STAND_STATE_STAND)
        me->SetStandState(UNIT_STAND_STATE_SIT);
}
//RATIONS
void bot_ai::_updateRations()
{
    bool noFeast = me->IsInCombat() || (BotMgr::IsFoodInterruptedByMovement() && me->isMoving()) || me->GetVictim() || CCed(me) || IsFlagCarrier(me);

    //check
    if (IAmFree() || !master->IsSitState())
    {
        if (feast_mana)
        {
            if (noFeast || me->IsStandState() || me->GetMaxPower(POWER_MANA) <= 1 || me->GetPower(POWER_MANA) >= me->GetMaxPower(POWER_MANA))
            {
                std::list<uint32> spellIds;
                Unit::AuraApplicationMap const& aurApps = me->GetAppliedAuras();
                for (Unit::AuraApplicationMap::const_iterator ci = aurApps.begin(); ci != aurApps.end(); ++ci)
                    if (ci->second->GetBase()->GetSpellInfo()->GetSpellSpecific() == SPELL_SPECIFIC_DRINK &&
                        !ci->second->GetBase()->GetSpellInfo()->HasAura(SPELL_AURA_PERIODIC_TRIGGER_SPELL)) //skip buffing food
                        spellIds.push_back(ci->first);
                for (std::list<uint32>::const_iterator cit = spellIds.begin(); cit != spellIds.end(); ++cit)
                    me->RemoveAurasDueToSpell(*cit);
                feast_mana = false;
                UpdateMana();
            }
        }
        if (feast_health)
        {
            if (noFeast || me->IsStandState() || me->GetHealth() >= me->GetMaxHealth())
            {
                std::list<uint32> spellIds;
                Unit::AuraApplicationMap const& aurApps = me->GetAppliedAuras();
                for (Unit::AuraApplicationMap::const_iterator ci = aurApps.begin(); ci != aurApps.end(); ++ci)
                    if (ci->second->GetBase()->GetSpellInfo()->GetSpellSpecific() == SPELL_SPECIFIC_FOOD &&
                        !ci->second->GetBase()->GetSpellInfo()->HasAura(SPELL_AURA_PERIODIC_TRIGGER_SPELL)) //skip buffing food
                        spellIds.push_back(ci->first);
                for (std::list<uint32>::const_iterator cit = spellIds.begin(); cit != spellIds.end(); ++cit)
                    me->RemoveAurasDueToSpell(*cit);
                feast_health = false;
            }
        }
    }

    if (noFeast)
        return;

    //drink
    if (!feast_mana && me->GetMaxPower(POWER_MANA) > 1 && !me->HasAuraType(SPELL_AURA_MOUNTED) && !me->isMoving() && CanDrink() &&
        !me->IsInCombat() && !me->GetVehicle() && !IsCasting() && GetManaPCT(me) < 75 && urand(0, 100) < 20)
    {
        me->CastSpell(me, GetRation(true), true);
    }

    //eat
    if (!feast_health && !me->HasAuraType(SPELL_AURA_MOUNTED) && !me->isMoving() && CanEat() &&
        !me->IsInCombat() && !me->GetVehicle() && !IsCasting() && GetHealthPCT(me) < 80 && urand(0, 100) < 20)
    {
        me->CastSpell(me, GetRation(false), true);
    }
}
//Health and Powers regeneration
//Rage regen is handled inside class AI UpdateAI()
void bot_ai::Regenerate()
{
    regenTimer += lastdiff;

    //every tick
    if (me->GetPowerType() == POWER_ENERGY)
        RegenerateEnergy();

    if (regenTimer >= REGEN_CD)
    {
        regenTimer -= REGEN_CD;
        // Regen Health
        int32 baseRegen = int32(_getTotalBotStat(BOT_STAT_MOD_HEALTH_REGEN));
        if ((!me->IsInCombat() || me->IsPolymorphed() || CanRegenInCombat() || baseRegen > 0 ||
            me->HasAuraType(SPELL_AURA_MOD_REGEN_DURING_COMBAT) || me->HasAuraType(SPELL_AURA_MOD_HEALTH_REGEN_IN_COMBAT)) &&
            me->GetHealth() < me->GetMaxHealth())
        {
            int32 add = me->IsInCombat() ? 0 : IAmFree() && !me->GetVictim() ? me->GetMaxHealth() / 64 : 5 + me->GetCreateHealth() / 256;
            if (baseRegen > 0)
                add += std::max<int32>(baseRegen / 5, 1);

            //cannot eat
            if (_botclass == BOT_CLASS_SPHYNX)
                add += me->GetMaxHealth() / 100; //1%

            if (me->IsPolymorphed())
                add += me->GetMaxHealth() / 6;
            else if (!me->IsInCombat() || me->HasAuraType(SPELL_AURA_MOD_REGEN_DURING_COMBAT))
            {
                if (!me->IsInCombat())
                {
                    Unit::AuraEffectList const& mModHealthRegenPct = me->GetAuraEffectsByType(SPELL_AURA_MOD_HEALTH_REGEN_PERCENT);
                    for (Unit::AuraEffectList::const_iterator i = mModHealthRegenPct.begin(); i != mModHealthRegenPct.end(); ++i)
                        AddPct(add, (*i)->GetAmount());

                    add += me->GetTotalAuraModifier(SPELL_AURA_MOD_REGEN) * REGEN_CD / 5000;
                }
                else if (me->HasAuraType(SPELL_AURA_MOD_REGEN_DURING_COMBAT))
                    ApplyPct(add, me->GetTotalAuraModifier(SPELL_AURA_MOD_REGEN_DURING_COMBAT));
            }

            add += me->GetTotalAuraModifier(SPELL_AURA_MOD_HEALTH_REGEN_IN_COMBAT);

            if (add < 0)
                add = 0;

            me->ModifyHealth(add);
        }

        // Regen Mana
        if (me->GetMaxPower(POWER_MANA) > 1 &&
            (me->GetPower(POWER_MANA) < me->GetMaxPower(POWER_MANA) || _botclass == BOT_CLASS_SPHYNX))
        {
            float addvalue;
            if (me->IsUnderLastManaUseEffect())
                addvalue = me->GetFloatValue(UNIT_FIELD_POWER_REGEN_INTERRUPTED_FLAT_MODIFIER);
            else
                addvalue = me->GetFloatValue(UNIT_FIELD_POWER_REGEN_FLAT_MODIFIER);

            addvalue *= sWorld->getRate(RATE_POWER_MANA) * float(REGEN_CD) * 0.001f; //regenTimer threshold / 1000

            if (addvalue < 0.0f)
                addvalue = 0.0f;

            if (_botclass == BOT_CLASS_SPHYNX)
                addvalue *= -1.f;

            me->ModifyPower(POWER_MANA, int32(addvalue));
        }
    }
}

void bot_ai::RegenerateEnergy()
{
    uint32 curValue = me->GetPower(POWER_ENERGY);
    uint32 maxValue = me->GetMaxPower(POWER_ENERGY);

    if (curValue < maxValue)
    {
        float addvalue = 0.01f * lastdiff * sWorld->getRate(RATE_POWER_ENERGY); //10 per sec
        Unit::AuraEffectList const& ModPowerRegenPCTAuras = me->GetAuraEffectsByType(SPELL_AURA_MOD_POWER_REGEN_PERCENT);
        for (Unit::AuraEffectList::const_iterator i = ModPowerRegenPCTAuras.begin(); i != ModPowerRegenPCTAuras.end(); ++i)
            if (Powers((*i)->GetMiscValue()) == POWER_ENERGY)
                AddPct(addvalue, (*i)->GetAmount());

        //not present in db
        //addvalue += me->GetTotalAuraModifierByMiscValue(SPELL_AURA_MOD_POWER_REGEN, POWER_ENERGY) * lastdiff / 5000;
        //me->ModifyPower(POWER_ENERGY, int32(addvalue));

        addvalue += _energyFraction;

        if (addvalue == 0x0) //only if world rate for enegy is 0
            return;

        uint32 integerValue = uint32(fabs(addvalue));

        curValue += integerValue;

        if (curValue > maxValue)
        {
            curValue = maxValue;
            _energyFraction = 0.f;
        }
        else
            _energyFraction = addvalue - float(integerValue);

        if (curValue == maxValue || regenTimer >= REGEN_CD)
            me->SetPower(POWER_ENERGY, curValue);
        else
            me->UpdateUInt32Value(UNIT_FIELD_POWER1 + uint16(POWER_ENERGY), curValue);
    }
}

bool bot_ai::Feasting() const
{
    if (!me->HasInterruptFlag(AURA_INTERRUPT_FLAG_NOT_SEATED))
        return false;

    return
        me->IsSitState() &&
        (me->HasAuraType(SPELL_AURA_MOD_REGEN)       || me->HasAuraType(SPELL_AURA_OBS_MOD_HEALTH) ||
         me->HasAuraType(SPELL_AURA_MOD_POWER_REGEN) || me->HasAuraType(SPELL_AURA_OBS_MOD_POWER));
}
uint32 bot_ai::GetRation(bool drink) const
{
    for (int8 i = MAX_FEAST_SPELLS - 1; i >= 0; --i)
        if (me->GetLevel() >= (drink ? DrinkSpells[i][0] : EatSpells[i][0]))
            return (drink ? DrinkSpells[i][1] : EatSpells[i][1]);

    return (drink ? DrinkSpells[0][1] : EatSpells[0][1]);
}

void bot_ai::DrinkPotion(bool mana)
{
    if (IsCasting())
        return;

    me->CastSpell(me, GetPotion(mana));
}
bool bot_ai::IsPotionReady() const
{
    return _potionTimer <= lastdiff;
}
uint32 bot_ai::GetPotion(bool mana) const
{
    for (int8 i = MAX_POTION_SPELLS - 1; i >= 0; --i)
        if (me->GetLevel() >= (mana ? ManaPotionSpells[i][0] : HealingPotionSpells[i][0]))
            return (mana ? ManaPotionSpells[i][1] : HealingPotionSpells[i][1]);

    return (mana ? ManaPotionSpells[0][1] : HealingPotionSpells[0][1]);
}
bool bot_ai::IsPotionSpell(uint32 spellId) const
{
    return spellId == GetPotion(true) || spellId == GetPotion(false);
}

/*static */BotItemUseSpellTargeting SelectTargeTypetForItemSpell(uint32 spellId, Unit const* caster)
{
    SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(spellId);
    if (!spellInfo || spellInfo->CalcCastTime() > 1500)
        return BOT_ITEM_USE_SPELL_TARGET_NONE;

    TSpellSummary const& sum = SpellSummary[spellId];
    if (sum.Effects & (1u << (SELECT_EFFECT_DAMAGE-1)))
    {
        if (sum.Targets & ((1u << (SELECT_TARGET_SINGLE_ENEMY-1)) | (1u << (SELECT_TARGET_ANY_ENEMY-1))))
            return BOT_ITEM_USE_SPELL_TARGET_ATTACKTARGET;
        else if (sum.Targets & (1u << (SELECT_TARGET_AOE_ENEMY-1)))
            return BOT_ITEM_USE_SPELL_TARGET_SELF;
    }
    else if (sum.Effects & (1u << (SELECT_EFFECT_HEALING-1)))
    {
        if (sum.Targets & ((1u << (SELECT_TARGET_SELF-1)) | (1u << (SELECT_TARGET_SINGLE_FRIEND-1)) | (1u << (SELECT_TARGET_AOE_FRIEND-1)) | (1u << (SELECT_TARGET_ANY_FRIEND-1))))
            if (caster->GetHealthPct() < 75.f)
                return BOT_ITEM_USE_SPELL_TARGET_SELF;
    }
    else if (sum.Effects & (1u << (SELECT_EFFECT_AURA-1)))
    {
        if (sum.Targets & ((1u << (SELECT_TARGET_SELF-1)) | (1u << (SELECT_TARGET_AOE_FRIEND-1)) | (1u << (SELECT_TARGET_AOE_ENEMY-1))))
            return BOT_ITEM_USE_SPELL_TARGET_SELF;
        else if (sum.Targets & ((1u << (SELECT_TARGET_SINGLE_FRIEND-1)) | (1u << (SELECT_TARGET_ANY_FRIEND-1))))
            return BOT_ITEM_USE_SPELL_TARGET_ALLY;
        else if (sum.Targets & ((1u << (SELECT_TARGET_SINGLE_ENEMY-1)) | (1u << (SELECT_TARGET_ANY_ENEMY-1))))
            return BOT_ITEM_USE_SPELL_TARGET_ATTACKTARGET;
    }
    else // if (sum.Effects == 0)
    {
        if (sum.Targets & ((1u << (SELECT_TARGET_SINGLE_ENEMY-1)) | (1u << (SELECT_TARGET_ANY_ENEMY-1))))
            return BOT_ITEM_USE_SPELL_TARGET_ATTACKTARGET;
        else if (sum.Targets & ((1u << (SELECT_TARGET_AOE_ENEMY-1)) | (1u << (SELECT_TARGET_SELF-1)) | (1u << (SELECT_TARGET_SINGLE_FRIEND-1)) | (1u << (SELECT_TARGET_AOE_FRIEND-1)) | (1u << (SELECT_TARGET_ANY_FRIEND-1))))
            return BOT_ITEM_USE_SPELL_TARGET_SELF;
        else // if (sum.Targets == 0)
            return BOT_ITEM_USE_SPELL_TARGET_SELF;
    }

    return BOT_ITEM_USE_SPELL_TARGET_NONE;
}
bool bot_ai::IsUsableItem(Item const* item)
{
    if (ItemTemplate const* proto = item->GetTemplate())
    {
        for (auto const& itemSpell : proto->Spells)
        {
            if (itemSpell.SpellId != 0 && itemSpell.SpellTrigger == ITEM_SPELLTRIGGER_ON_USE)
                return true;
        }
    }

    return false;
}
uint32 bot_ai::GetItemSpellCooldown(uint32 spellId) const
{
    for (Item const* item : _equips)
    {
        if (item && IsUsableItem(item))
        {
            ItemTemplate const* proto = item->GetTemplate();
            for (auto const& itemSpell : proto->Spells)
            {
                if (itemSpell.SpellId == decltype(itemSpell.SpellId)(spellId))
                    return itemSpell.SpellCooldown;
            }
        }
    }

    return 0;
}
void bot_ai::CheckUsableItems(uint32 diff)
{
    if (!_usableItemSlotsMask || itemsAutouseTimer > diff || !me->IsInCombat() || IsCasting() || (!me->GetVictim() && me->getAttackers().empty()))
        return;

    itemsAutouseTimer = urand(2500, 5500);

    for (uint8 slot = BOT_SLOT_MAINHAND; slot < BOT_INVENTORY_SIZE; ++slot)
    {
        if (_usableItemSlotsMask & (1ul << slot))
        {
            if (Item const* item = _equips[slot])
            {
                bool is_spell_ready = false;
                uint32 firstItemSpellId = 0;
                for (auto const& itemSpell : item->GetTemplate()->Spells)
                {
                    if (itemSpell.SpellId > 0 && itemSpell.SpellTrigger == ITEM_SPELLTRIGGER_ON_USE)
                    {
                        if (firstItemSpellId == 0)
                            firstItemSpellId = itemSpell.SpellId;

                        if (IsSpellReady(itemSpell.SpellId, diff, false))
                            is_spell_ready = true;
                        else
                        {
                            is_spell_ready = false;
                            break;
                        }
                    }
                }
                if (!is_spell_ready)
                    continue;

                uint32 targetType = SelectTargeTypetForItemSpell(firstItemSpellId, me);
                Unit* castTarget = nullptr;
                switch (targetType)
                {
                    case BOT_ITEM_USE_SPELL_TARGET_SELF:
                        castTarget = me;
                        break;
                    case BOT_ITEM_USE_SPELL_TARGET_ATTACKTARGET:
                        castTarget = me->GetVictim();
                        break;
                    case BOT_ITEM_USE_SPELL_TARGET_ALLY:
                        castTarget = me->GetNextRandomRaidMemberOrPet(10.f);
                        if (!castTarget)
                            castTarget = me;
                        break;
                    case BOT_ITEM_USE_SPELL_TARGET_NONE:
                    default:
                        break;
                }

                //TC_LOG_ERROR("scripts", "bot_ai::CheckUsableItems(): bot {}, slot {}, spell {}, target {}",
                //    me->GetName(), uint32(slot), firstItemSpellId, targetType);

                if (!castTarget)
                    continue;

                SpellCastTargets targets;
                targets.SetUnitTarget(castTarget);
                _castBotItemUseSpell(item, targets);

                // do not delay next check unless all items were checked
                if (slot < BOT_SLOT_TRINKET2)
                    itemsAutouseTimer = 0;

                break;
            }
            else
                TC_LOG_ERROR("scripts", "bot_ai::CheckUsableItems(): slot {} is in mask but no item exists in that slot!", uint32(slot));
        }
    }
}
//check if our party players are in duel. if so - ignore them, their opponents and any bots they have
//Deprecated after 4c26c85
//bool bot_ai::InDuel(Unit const* target) const
//{
//    if (!target) return false;
//    bool isbot = target->GetTypeId() == TYPEID_UNIT && target->ToCreature()->IsNPCBot();
//    Player const* player = target->GetTypeId() == TYPEID_PLAYER ? target->ToPlayer() : isbot ? target->ToCreature()->GetBotOwner()->ToPlayer() : nullptr;
//    if (!player)
//    {
//        if (!target->IsControlledByPlayer())
//            return false;
//        player = target->GetCharmerOrOwnerPlayerOrPlayerItself();
//    }
//
//    return (player && player->duel && (IsInBotParty(player) || IsInBotParty(player->duel->opponent)));
//}
////////////////
//GRID SEARCHERS
////////////////
//Finds player or it's corpse for resurrection returned as WorldObject*
WorldObject* bot_ai::GetNearbyRezTarget(float dist) const
{
    std::list<WorldObject*> list;

    NearbyRezTargetCheck check(me, dist, this);
    Trinity::WorldObjectListSearcher <NearbyRezTargetCheck> searcher(me, list, check);
    Cell::VisitWorldObjects(me, searcher, dist);

    if (list.empty())
        return nullptr;
    if (list.size() == 1)
        return *list.begin();

    return Trinity::Containers::SelectRandomContainerElement(list);
}
//Finds target for warrior's Shattering Throw
Unit* bot_ai::FindImmunityShieldDispelTarget(float dist) const
{
    //not checking range
    if (me->GetVictim() && me->GetVictim()->HasAuraWithMechanic(1<<MECHANIC_IMMUNE_SHIELD))
        return me->GetVictim();

    Unit* unit = nullptr;

    ImmunityShieldDispelTargetCheck check(me, dist, this);
    Trinity::UnitSearcher <ImmunityShieldDispelTargetCheck> searcher(me, unit, check);
    Cell::VisitAllObjects(me, searcher, dist);
    //me->VisitNearbyObject(dist, searcher);

    return unit;
}
//Used to find target for priest's dispels, mage's spellsteal and shaman's purge
//Returns dispellable/stealable 'Any Hostile Unit Attacking BotParty'
Unit* bot_ai::FindHostileDispelTarget(float dist, bool stealable) const
{
    std::list<Unit*> unitList;

    HostileDispelTargetCheck check(me, dist, stealable, this);
    Trinity::UnitListSearcher <HostileDispelTargetCheck> searcher(me, unitList, check);
    Cell::VisitAllObjects(me, searcher, dist);
    //me->VisitNearbyObject(dist, searcher);

    if (unitList.empty())
        return nullptr;
    if (unitList.size() == 1)
        return *unitList.begin();

    return Trinity::Containers::SelectRandomContainerElement(unitList);
}
//Finds single target affected by given spell (and given caster if is)
//Can check:
//    hostile targets  (hostile = 0) <default>
// DEPRECATED our party players (hostile = 1)
// DEPRECATED our party members  (hostile = 2)
//    any friendly target (hostile = 3)
//    any friendly player (hostile = 4)
//    any target in range  (hostile = any other value)
Unit* bot_ai::FindAffectedTarget(uint32 spellId, ObjectGuid caster, float dist, uint8 hostile) const
{
    if (!spellId)
        return nullptr;
    if ((hostile == 2 || hostile == 1)/* && IAmFree()*/)
    {
        TC_LOG_ERROR("entities.player", "bot_ai::FindAffectedTarget(): hostile = {} Setting to ALL...", hostile);
        hostile = 255;
    }
    if (master->GetMap()->Instanceable())
        dist = DEFAULT_VISIBILITY_INSTANCE;

    Unit* unit = nullptr;

    AffectedTargetCheck check(caster, dist, spellId, master, hostile);
    Trinity::UnitSearcher <AffectedTargetCheck> searcher(master, unit, check);
    Cell::VisitAllObjects(me, searcher, dist);
    //me->VisitNearbyObject(dist, searcher);

    return unit;
}
//Finds target for mage's polymorph or shaman's hex
Unit* bot_ai::FindPolyTarget(float dist) const
{
    std::list<Unit*> unitList;

    PolyUnitCheck check(me, dist);
    Trinity::UnitListSearcher <PolyUnitCheck> searcher(me, unitList, check);
    Cell::VisitAllObjects(me, searcher, dist);
    //me->VisitNearbyObject(dist, searcher);

    if (unitList.empty())
        return nullptr;
    if (unitList.size() == 1)
        return *unitList.begin();
    decltype(unitList)::const_iterator it = std::find_if(unitList.cbegin(), unitList.cend(), [this](Unit const* u) { return IsPointedNoDPSTarget(u); });
    if (it != unitList.cend())
        return *it;

    return Trinity::Containers::SelectRandomContainerElement(unitList);
}
//Finds target for direct fear (warlock, hunter)
Unit* bot_ai::FindFearTarget(float dist) const
{
    std::list<Unit*> unitList;

    FearUnitCheck check(me, dist);
    Trinity::UnitListSearcher <FearUnitCheck> searcher(me, unitList, check);
    Cell::VisitAllObjects(me, searcher, dist);
    //me->VisitNearbyObject(dist, searcher);

    if (unitList.empty())
        return nullptr;
    if (unitList.size() == 1)
        return *unitList.begin();
    decltype(unitList)::const_iterator it = std::find_if(unitList.cbegin(), unitList.cend(), [this](Unit const* u) { return IsPointedNoDPSTarget(u); });
    if (it != unitList.cend())
        return *it;

    return Trinity::Containers::SelectRandomContainerElement(unitList);
}
//Finds target for CC spells with MECHANIC_STUN
Unit* bot_ai::FindStunTarget(float dist) const
{
    std::list<Unit*> unitList;

    StunUnitCheck check(me, dist);
    Trinity::UnitListSearcher <StunUnitCheck> searcher(me, unitList, check);
    Cell::VisitAllObjects(me, searcher, dist);
    //me->VisitNearbyObject(dist, searcher);

    if (unitList.empty())
        return nullptr;
    if (unitList.size() == 1)
        return *unitList.begin();
    decltype(unitList)::const_iterator it = std::find_if(unitList.cbegin(), unitList.cend(), [this](Unit const* u) { return IsPointedNoDPSTarget(u); });
    if (it != unitList.cend())
        return *it;

    return Trinity::Containers::SelectRandomContainerElement(unitList);
}
//Finds target for priest's shackles
Unit* bot_ai::FindUndeadCCTarget(float dist, uint32 spellId, bool unattacked) const
{
    if (!spellId)
        return nullptr;

    std::list<Unit*> unitList;

    UndeadCCUnitCheck check(me, dist, this, spellId, unattacked);
    Trinity::UnitListSearcher <UndeadCCUnitCheck> searcher(me, unitList, check);
    Cell::VisitAllObjects(me, searcher, dist);
    //me->VisitNearbyObject(dist, searcher);

    if (unitList.empty())
        return nullptr;
    if (unitList.size() == 1)
        return *unitList.begin();
    decltype(unitList)::const_iterator it = std::find_if(unitList.cbegin(), unitList.cend(), [this](Unit const* u) { return IsPointedNoDPSTarget(u); });
    if (it != unitList.cend())
        return *it;

    return Trinity::Containers::SelectRandomContainerElement(unitList);
}
//Finds target for druid's Entangling Roots
Unit* bot_ai::FindRootTarget(float dist, uint32 spellId) const
{
    if (!spellId)
        return nullptr;

    std::list<Unit*> unitList;

    RootUnitCheck check(me, dist, this, spellId);
    Trinity::UnitListSearcher <RootUnitCheck> searcher(me, unitList, check);
    Cell::VisitAllObjects(me, searcher, dist);
    //me->VisitNearbyObject(dist, searcher);

    if (unitList.empty())
        return nullptr;
    if (unitList.size() == 1)
        return *unitList.begin();
    decltype(unitList)::const_iterator it = std::find_if(unitList.cbegin(), unitList.cend(), [this](Unit const* u) { return IsPointedNoDPSTarget(u); });
    if (it != unitList.cend())
        return *it;

    return Trinity::Containers::SelectRandomContainerElement(unitList);
}
//Finds casting target (neutral or enemy)
//Can be used to get silence/interruption/reflect/grounding check
Unit* bot_ai::FindCastingTarget(float maxdist, float mindist, uint32 spellId, uint8 minHpPct) const
{
    std::list<Unit*> unitList;

    CastingUnitCheck check(me, mindist, maxdist, spellId, minHpPct);
    Trinity::UnitListSearcher <CastingUnitCheck> searcher(me, unitList, check);
    Cell::VisitAllObjects(me, searcher, maxdist);
    //me->VisitNearbyObject(maxdist, searcher);

    if (unitList.empty())
        return nullptr;
    if (unitList.size() == 1)
        return *unitList.begin();
    decltype(unitList)::const_iterator it = std::find_if(unitList.cbegin(), unitList.cend(), [this](Unit const* u) { return IsPointedNoDPSTarget(u); });
    if (it != unitList.cend())
        return *it;

    return Trinity::Containers::SelectRandomContainerElement(unitList);
}
// Returns target for dest AOE spell (blizzard, hurricane, etc.) based on crowd size, movement state and direction
Unit* bot_ai::FindAOETarget(float dist, WorldObject const* src) const
{
    if (!src)
        src = me;

    std::list<Unit*> unitList;
    GetNearbyTargetsList(unitList, dist, 0);

    if (unitList.size() < 3)
        return nullptr;

    Unit* unit = nullptr;
    float mydist = dist;
    for (std::list<Unit*>::const_iterator itr = unitList.begin(); itr != unitList.end(); ++itr)
    {
        if ((*itr)->isMoving() && (*itr)->GetVictim() &&
            ((*itr)->GetDistance2d((*itr)->GetVictim()->GetPositionX(), (*itr)->GetVictim()->GetPositionY()) > 7.5f ||
            !(*itr)->HasInArc(float(M_PI)*0.75f, (*itr)->GetVictim())))
            continue;

        if (!unit && (*itr)->GetVictim() && (*itr)->GetDistance((*itr)->GetVictim()) < dist * 0.334f)
        {
            unit = *itr;
            continue;
        }
        if (!unit)
        {
            float destDist = src->GetDistance((*itr)->GetPositionX(), (*itr)->GetPositionY(), (*itr)->GetPositionZ());
            if (destDist < mydist)
            {
                mydist = destDist;
                unit = *itr;
            }
        }
        if (unit)
        {
            uint8 count = 0;
            for (std::list<Unit*>::const_iterator it = unitList.begin(); it != unitList.end(); ++it)
            {
                if (*it != unit && (*it)->GetDistance2d(unit->GetPositionX(), unit->GetPositionY()) < 5.f)
                {
                    if (++count > 2)
                    {
                        if (src->GetDistance(*it) < src->GetDistance(unit) && unit->HasInArc(float(M_PI)/2, src))
                            unit = *it;
                        break;
                    }
                }
            }
            if (count > 2)
                break;

            unit = nullptr;
        }
    }

    return unit;
}
// Finds secondary target for spells like Cleave, Swipe, etc.
Unit* bot_ai::FindSplashTarget(float dist, Unit* To, float splashdist) const
{
    if (!To)
        To = me->GetVictim();
    if (!To)
        return nullptr;

    if (me->GetDistance(To) > dist)
        return nullptr;

    Unit* unit = nullptr;

    SecondEnemyCheck check(me, dist, splashdist, To, this);
    Trinity::UnitSearcher <SecondEnemyCheck> searcher(me, unit, check);
    Cell::VisitAllObjects(me, searcher, dist);
    //me->VisitNearbyObject(dist, searcher);

    return unit;
}
// Finds secondary target for AoE spells like Mind Sear (not damaging primary target)
Unit* bot_ai::FindSplashTarget(float dist, Unit* To, float splashdist, uint8 minTargets) const
{
    if (!To || minTargets < 1)
        return nullptr;

    if (me->GetDistance(To) > dist)
        return nullptr;

    std::list<Unit*> unitList;

    SecondEnemyCheck check(me, dist, splashdist, To, this);
    Trinity::UnitListSearcher <SecondEnemyCheck> searcher(me, unitList, check);
    Cell::VisitAllObjects(me, searcher, dist);
    //me->VisitNearbyObject(dist, searcher);

    if (uint8(unitList.size()) < minTargets)
        return nullptr;
    if (unitList.size() == 1)
        return *unitList.begin();

    return Trinity::Containers::SelectRandomContainerElement(unitList);
}
//Finds target for hunter's Tranquilizing Shot (has dispellable magic or enrage effect)
Unit* bot_ai::FindTranquilTarget(float mindist, float maxdist) const
{
    Unit* unit = nullptr;

    TranquilTargetCheck check(me, mindist, maxdist, this);
    Trinity::UnitSearcher <TranquilTargetCheck> searcher(me, unit, check);
    Cell::VisitAllObjects(me, searcher, maxdist);
    //me->VisitNearbyObject(maxdist, searcher);

    return unit;
}
//Find target to cast taunt on
//In case of paladin's Righetoous Defense returns IsInBotParty() unit
Unit* bot_ai::FindDistantTauntTarget(float maxdist, bool ally) const
{
    std::list<Unit*> unitList;

    FarTauntUnitCheck check(me, maxdist, ally, this);
    Trinity::UnitListSearcher <FarTauntUnitCheck> searcher(me, unitList, check);
    Cell::VisitAllObjects(me, searcher, maxdist);
    //me->VisitNearbyObject(maxdist, searcher);

    if (unitList.empty())
        return nullptr;

    Unit* unit = unitList.size() == 1 ? *unitList.begin() : Trinity::Containers::SelectRandomContainerElement(unitList);
    return ally ? unit->GetVictim() : unit;
}
//Finds target for Warlock's Mana Drain
//Returns nearby CCed unit with most mana
Unit* bot_ai::FindDrainTarget(float maxdist) const
{
    Unit* unit = nullptr;

    ManaDrainUnitCheck check(me, maxdist, this);
    Trinity::UnitLastSearcher <ManaDrainUnitCheck> searcher(me, unit, check);
    Cell::VisitAllObjects(me, searcher, maxdist);
    //me->VisitNearbyObject(maxdist, searcher);

    return unit;
}
//Finds all targets within given range
//used for finding targets for spells which need reasonable amount of targets (ex. Death Knight AOE spells)
//CCoption:= mask
//1 - not CCed
//2 - has no periodic damage auras (can be safely CCed)
void bot_ai::GetNearbyTargetsList(std::list<Unit*> &targets, float maxdist, uint8 CCoption, WorldObject const* source) const
{
    if (!source)
        source = me;

    NearbyHostileUnitCheck check(me, maxdist, this, CCoption, source);
    Trinity::UnitListSearcher <NearbyHostileUnitCheck> searcher(me, targets, check);
    Cell::VisitAllObjects(me, searcher, maxdist);
    //me->VisitNearbyObject(maxdist, searcher);
}
//Find all targets within given range in cone in front of caster; angle is PI/2 (TC confirmed)
//used by mage Dragon's Breath and Cone of Cold spells
//also Swipe (Bear) and Swipe (Cat)
void bot_ai::GetNearbyTargetsInConeList(std::list<Unit*> &targets, float maxdist) const
{
    NearbyHostileUnitInConeCheck check(me, maxdist, this);
    Trinity::UnitListSearcher <NearbyHostileUnitInConeCheck> searcher(me, targets, check);
    Cell::VisitAllObjects(me, searcher, maxdist);
    //me->VisitNearbyObject(maxdist, searcher);
}
//Finds all friendly targets within given range
//used for finding targets to heal/buff for uncontrolled bots
void bot_ai::GetNearbyFriendlyTargetsList(std::list<Unit*> &targets, float maxdist) const
{
    NearbyFriendlyUnitCheck check(me, maxdist, this);
    Trinity::UnitListSearcher <NearbyFriendlyUnitCheck> searcher(me, targets, check);
    Cell::VisitAllObjects(me, searcher, maxdist);
    //me->VisitNearbyObject(maxdist, searcher);
}
//////////
//SPELLMAP
//////////
//Using first-rank spell as source, returns spellId of max rank allowed for given caster
//If you want bot to use this spell through doCast() go InitSpellMap(uint32) instead
uint32 bot_ai::InitSpell(Unit const* caster, uint32 spell)
{
    SpellInfo const* info = sSpellMgr->GetSpellInfo(spell);
    if (!info)
    {
        TC_LOG_ERROR("entities.player", "InitSpell(): No SpellInfo found for spell {}", spell);
        return 0; //weird spell with no info, disable it
    }

    uint8 lvl = caster->GetLevel();
    if (lvl < info->BaseLevel) //only 1st rank spells check
        return 0; //cannot use this spell

    if (SpellInfo const* spInfo = info->GetNextRankSpell())
    {
        if (lvl < spInfo->BaseLevel)
            return spell; //cannot use next rank, use this one
        else
            return InitSpell(caster, spInfo->Id); //can use next rank, forward check
    }

    return spell; //max rank, use this
}
//Using first-rank spell as source, puts spell of max rank allowed for given caster in spellmap
void bot_ai::InitSpellMap(uint32 basespell, bool forceadd, bool forwardRank)
{
    SpellInfo const* info = sSpellMgr->GetSpellInfo(basespell);
    if (!info)
    {
        TC_LOG_ERROR("entities.player", "bot_ai::InitSpellMap(): No SpellInfo found for base spell {}", basespell);
        return; //invalid spell id
    }
    info = info->TryGetSpellInfoOverride(me);

    uint8 lvl = me->GetLevel();
    uint32 spellId = forceadd ? basespell : 0;

    while (info != nullptr && forwardRank && (forceadd || lvl >= info->BaseLevel))
    {
        spellId = info->Id; //can use this spell
        info = info->GetNextRankSpell(); //check next rank
    }

    BotSpell* newSpell = _spells[basespell];
    if (!newSpell)
    {
        newSpell = new BotSpell();
        _spells[basespell] = newSpell;
    }

    newSpell->spellId = spellId;

    NpcBotData const* npcBotData = BotDataMgr::SelectNpcBotData(me->GetEntry());
    if (npcBotData && npcBotData->disabled_spells.find(basespell) != npcBotData->disabled_spells.end())
    {
        newSpell->enabled = false;
        //TC_LOG_ERROR("entities.player", "bot_ai::InitSpellMap(): {} ({} -> {}) is disabled for {}!",
        //    sSpellMgr->GetSpellInfo(basespell)->SpellName[0], basespell, spellId, me->GetName());
    }
}
//Using first-rank spell as source, return true if spell is inited
bool bot_ai::HasSpell(uint32 basespell) const
{
    BotSpellMap::const_iterator itr = _spells.find(basespell);
    return itr != _spells.end() && (itr->second->spellId != 0);
}
//Using spell name as source, return first-rank spell if spell is inited
uint32 bot_ai::GetBaseSpell(std::string_view spell_name, LocaleConstant locale) const
{
    uint32 basespell = 0;
    std::wstring wname;
    if (Utf8toWStr(spell_name, wname))
    {
        wstrToLower(wname);
        for (BotSpellMap::const_iterator itr = _spells.begin(); itr != _spells.end(); ++itr)
        {
            //we ignore enabled state since this is exactly what we want
            if (itr->second->spellId == 0) //not init'ed
                continue;
            spell_name = sSpellMgr->GetSpellInfo(itr->first)->SpellName[locale];
            std::wstring wcname;
            if (!Utf8toWStr(spell_name, wcname))
                continue;
            wstrToLower(wcname);
            if (wcname == wname)
            {
                basespell = itr->first;
                break;
            }
        }
    }

    return basespell;
}
//Using first-rank spell as source, return current spell id if inited and enabled
uint32 bot_ai::GetSpell(uint32 basespell) const
{
    BotSpellMap::const_iterator itr = _spells.find(basespell);
    return itr != _spells.end() && (itr->second->enabled == true || IAmFree()) ? itr->second->spellId : 0;
}
//Using first-rank spell as source, returns cooldown on current spell
uint32 bot_ai::GetSpellCooldown(uint32 basespell) const
{
    BotSpellMap::const_iterator itr = _spells.find(basespell);
    return itr != _spells.end() ? itr->second->cooldown : 0;
}
bool bot_ai::IsSpellReady(uint32 basespell, uint32 diff, bool checkGCD) const
{
    if (checkGCD && GC_Timer > diff)
        return false;

    BotSpellMap::const_iterator itr = _spells.find(basespell);
    return itr == _spells.end() ? true :
        ((itr->second->enabled == true || IAmFree() || IsLastOrder(BOT_ORDER_SPELLCAST, basespell)) &&
            itr->second->spellId != 0 && itr->second->cooldown <= diff);
}
//Using first-rank spell as source, sets cooldown for current spell
void bot_ai::SetSpellCooldown(uint32 basespell, uint32 msCooldown)
{
    //if (!msCooldown)
    //    return;

    BotSpellMap::const_iterator itr = _spells.find(basespell);
    if (itr != _spells.end())
    {
        itr->second->cooldown = msCooldown;
        return;
    }
    //else if (!msCooldown)
    //    return;

    InitSpellMap(basespell, true, false);
    SetSpellCooldown(basespell, msCooldown);
}
//Using first-rank spell as source, sets cooldown for spells of that category
void bot_ai::SetSpellCategoryCooldown(SpellInfo const* spellInfo, uint32 msCooldown)
{
    if (!msCooldown)
        return;

    uint32 category = spellInfo->GetCategory();
    if (!category)
        category = spellInfo->StartRecoveryCategory;
    if (!category)
        return;

    SpellInfo const* info;
    for (BotSpellMap::const_iterator itr = _spells.begin(); itr != _spells.end(); ++itr)
    {
        //skip spell which has triggered this category cooldown
        if (itr->first == spellInfo->Id && itr->second->cooldown >= msCooldown)
            continue;

        info = sSpellMgr->GetSpellInfo(itr->second->spellId);
        info = info ? info->TryGetSpellInfoOverride(me) : info;
        if (info && itr->first == spellInfo->Id && info->GetCategory() != category && info->StartRecoveryCategory != category)
        {
            //if (itr->first != 7814) // Lash of Pain
            {
                TC_LOG_ERROR("scripts", "Warning: SetSpellCategoryCooldown: {} has baseId {} but category {}, not {}!",
                    info->Id, itr->first, info->GetCategory(), category);
            }
        }
        if (info && (info->GetCategory() == category || info->StartRecoveryCategory == category || itr->first == spellInfo->Id) && itr->second->cooldown < msCooldown)
            itr->second->cooldown = msCooldown;
    }
}
//Handles spell cooldowns for spell with IsCooldownStartedOnEvent() == true
void bot_ai::ReleaseSpellCooldown(uint32 basespell)
{
    SpellInfo const* baseInfo = sSpellMgr->GetSpellInfo(basespell);

    baseInfo = baseInfo->TryGetSpellInfoOverride(me);

    if (!baseInfo->IsCooldownStartedOnEvent())
    {
        TC_LOG_ERROR("spells", "bot_ai::ReleaseSpellCooldown is called for wrong spell {}!", basespell);
        return;
    }

    uint32 rec = baseInfo->RecoveryTime;
    uint32 catrec = baseInfo->CategoryRecoveryTime;

    ApplyBotSpellCooldownMods(baseInfo, rec);
    ApplyBotSpellCategoryCooldownMods(baseInfo, catrec);

    SetSpellCooldown(baseInfo->Id, rec > 0 ? rec : 0);
    SetSpellCategoryCooldown(baseInfo, catrec > 0 && !(baseInfo->AttributesEx6 & SPELL_ATTR6_IGNORE_CATEGORY_COOLDOWN_MODS) ? catrec : 0);
}
//Using first-rank spell as source, disables certain spell for this bot
void bot_ai::RemoveSpell(uint32 basespell)
{
    BotSpell* newSpell;
    BotSpellMap::iterator itr = _spells.find(basespell);
    if (itr == _spells.end())
    {
        newSpell = new BotSpell();
        _spells[basespell] = newSpell;
    }
    else
        newSpell = itr->second;

    newSpell->spellId = 0;
    newSpell->cooldown = 0;
}
//
//void bot_ai::RemoveAllSpells()
//{
//    for (BotSpellMap::const_iterator itr = _spells.begin(); itr != _spells.end(); ++itr)
//        itr->second->spellId = 0;
//}
void bot_ai::EnableAllSpells(bool save)
{
    if (save)
    {
        NpcBotData* npcBotData = const_cast<NpcBotData*>(BotDataMgr::SelectNpcBotData(me->GetEntry()));
        npcBotData->disabled_spells.clear();
        _saveDisabledSpells = true;
    }

    for (BotSpellMap::const_iterator itr = _spells.begin(); itr != _spells.end(); ++itr)
        if (itr->second->enabled == false)
            itr->second->enabled = true;
}
//See CommonTimers(uint32)
void bot_ai::SpellTimers(uint32 diff)
{
    // spell must be initialized!!!
    for (BotSpellMap::const_iterator itr = _spells.begin(); itr != _spells.end(); ++itr)
    {
        if (itr->second->cooldown >= diff)
            itr->second->cooldown -= diff;
        else if (itr->second->cooldown > 0)
            itr->second->cooldown = 0;
    }
}
uint32 bot_ai::RaceSpellForClass(uint8 myrace, uint8 myclass)
{
    switch (myrace)
    {
        case RACE_ORC:
            switch (myclass)
            {
                case BOT_CLASS_WARLOCK:
                    return RACIAL_BLOOD_FURY_WARLOCK;
                case BOT_CLASS_SHAMAN:
                    return RACIAL_BLOOD_FURY_SHAMAN;
                default:
                    return RACIAL_BLOOD_FURY_OTHERS;
            }
            break;
        case RACE_BLOODELF:
            switch (myclass)
            {
                case BOT_CLASS_DEATH_KNIGHT:
                    return RACIAL_ARCANE_TORRENT_DEATHKNIGHT;
                case BOT_CLASS_ROGUE:
                    return RACIAL_ARCANE_TORRENT_ROGUE;
                default:
                    return RACIAL_ARCANE_TORRENT_OTHERS;
            }
            break;
        case RACE_DRAENEI:
            switch (myclass)
            {
                case BOT_CLASS_WARRIOR:
                    return RACIAL_GIFT_OF_NAARU_WARRIOR;
                case BOT_CLASS_PALADIN:
                    return RACIAL_GIFT_OF_NAARU_PALADIN;
                case BOT_CLASS_HUNTER:
                    return RACIAL_GIFT_OF_NAARU_HUNTER;
                case BOT_CLASS_PRIEST:
                    return RACIAL_GIFT_OF_NAARU_PRIEST;
                case BOT_CLASS_DEATH_KNIGHT:
                    return RACIAL_GIFT_OF_NAARU_DEATHKNIGHT;
                case BOT_CLASS_SHAMAN:
                    return RACIAL_GIFT_OF_NAARU_SHAMAN;
                case BOT_CLASS_MAGE:
                    return RACIAL_GIFT_OF_NAARU_MAGE;
                default:
                    TC_LOG_ERROR("entities.player", "RaceSpellForClass(): unknows race:class combo {}, {}", uint32(myrace), uint32(myclass));
                    return 0;
            }
            break;
        default:
            TC_LOG_ERROR("entities.player", "RaceSpellForClass(): unknows race:class combo {}, {}", uint32(myrace), uint32(myclass));
            return 0;
    }
}
//Health magement for minions
//Including health calcs, set
void bot_ai::_OnHealthUpdate() const
{
    uint8 myclass = _botclass;
    uint8 mylevel = master->GetLevel();
    if (myclass == BOT_CLASS_DRUID && GetBotStance() != BOT_STANCE_NONE)
        myclass = GetBotStance();
    //TC_LOG_ERROR("entities.player", "_OnHealthUpdate(): updating bot {}", me->GetName());
    bool fullhp = me->GetHealth() == me->GetMaxHealth();
    float pct = fullhp ? 100.f : me->GetHealthPct(); // needs for regeneration
    uint32 m_basehp = uint32(_classinfo->basehealth * (BotMgr::IsWanderingWorldBot(me) ? BotMgr::GetBotWandererHPMod() : BotMgr::GetBotHPMod()));
    //TC_LOG_ERROR("entities.player", "class base health: {}", m_basehp);
    me->SetCreateHealth(m_basehp);

    float stamValue = _getTotalBotStat(BOT_STAT_MOD_STAMINA);

    stamValue -= std::min<float>(me->GetCreateStat(STAT_STAMINA), 20.f); //not a mistake
    stamValue = std::max<float>(stamValue, 0.f);

    //TC_LOG_ERROR("entities.player", "bot's stats to health add: Stamina ({}), value: {}", stamValue, stamValue * 10.f);
    float hp_add = stamValue * 10.f + 20; //20 is not a mistake;
    //hp_add += IAmFree() ? mylevel * 375.f : 0; //+30000/+0 hp at 80
    hp_add += _getTotalBotStat(BOT_STAT_MOD_HEALTH);
    //TC_LOG_ERROR("entities.player", "health to add after stam mod: {}", hp_add);
    uint32 m_totalhp = m_basehp + int32(hp_add * (BotMgr::IsWanderingWorldBot(me) ? BotMgr::GetBotWandererHPMod() : BotMgr::GetBotHPMod()));
    //TC_LOG_ERROR("entities.player", "total base health: {}", m_totalhp);

    //hp bonuses
    uint8 bonuspct = 0;
    //Endurance Training
    if (_botclass == BOT_CLASS_HUNTER && mylevel >= 10)
        bonuspct += 5;
    //Fel Vitality
    if (_botclass == BOT_CLASS_WARLOCK && mylevel >= 15)
        bonuspct += 3;
    //Sphynx bonus (some equip slots unavailable)
    if (_botclass == BOT_CLASS_SPHYNX)
        bonuspct += 50;
    //Dreadlord's / Crypt Lord's vitality
    if (_botclass == BOT_CLASS_DREADLORD || _botclass == BOT_CLASS_CRYPT_LORD)
        bonuspct += 20;
    if (bonuspct)
        m_totalhp = (m_totalhp * (100 + bonuspct)) / 100;

    //m_totalhp = float(uint32(m_totalhp) - (uint32(m_totalhp) % 10));
    me->SetStatFlatModifier(UNIT_MOD_HEALTH, BASE_VALUE, float(m_totalhp)); //replaces base hp at max lvl
    me->UpdateMaxHealth(); //will use our values we just set (update base health and buffs)
    //TC_LOG_ERROR("entities.player", "overall hp: {}", me->GetMaxHealth());
    me->SetHealth(fullhp ? me->GetMaxHealth() : uint32(0.5f + float(me->GetMaxHealth()) * pct / 100.f)); //restore pct
}
//Mana management for minions
//Including calcs and set
void bot_ai::_OnManaUpdate() const
{
    if (me->GetMaxPower(POWER_MANA) <= 1)
        return;

    uint8 myclass = _botclass;
    uint8 mylevel = master->GetLevel();
    if (myclass == BOT_CLASS_DRUID && GetBotStance() != BOT_STANCE_NONE)
        myclass = GetBotStance();

    //TC_LOG_ERROR("entities.player", "_OnManaUpdate(): updating bot {}", me->GetName());
    bool fullmana = me->GetPower(POWER_MANA) == me->GetMaxPower(POWER_MANA);
    float pct = fullmana ? 100.f : (float(me->GetPower(POWER_MANA)) * 100.f) / float(me->GetMaxPower(POWER_MANA));
    float m_basemana = _classinfo->basemana;
    if (_botclass == BOT_CLASS_BM)
        m_basemana = float(BASE_MANA_1_BM) + float(BASE_MANA_10_BM - BASE_MANA_1_BM) * (mylevel/81.f);
    if (_botclass == BOT_CLASS_SPHYNX)
        m_basemana = BASE_MANA_SPHYNX;
    if (_botclass == BOT_CLASS_ARCHMAGE)
        m_basemana = float(BASE_MANA_1_ARCHMAGE) + float(BASE_MANA_10_ARCHMAGE - BASE_MANA_1_ARCHMAGE) * ((mylevel - 20)/81.f);
    if (_botclass == BOT_CLASS_DREADLORD)
        m_basemana = float(BASE_MANA_1_DREADLORD) + float(BASE_MANA_10_DREADLORD - BASE_MANA_1_DREADLORD) * ((mylevel - 60)/83.f);
    if (_botclass == BOT_CLASS_SPELLBREAKER)
        m_basemana = BASE_MANA_SPELLBREAKER;
    if (_botclass == BOT_CLASS_DARK_RANGER)
        m_basemana = float(BASE_MANA_1_DARK_RANGER) + float(BASE_MANA_10_DARK_RANGER - BASE_MANA_1_DARK_RANGER) * ((mylevel - 40)/82.f);
    if (_botclass == BOT_CLASS_NECROMANCER)
        m_basemana = BASE_MANA_NECROMANCER;
    if (_botclass == BOT_CLASS_SEA_WITCH)
        m_basemana = float(BASE_MANA_1_SEA_WITCH) + float(BASE_MANA_10_SEA_WITCH - BASE_MANA_1_SEA_WITCH) * (mylevel/83.f);
    if (_botclass == BOT_CLASS_CRYPT_LORD)
        m_basemana = float(BASE_MANA_1_CRYPT_LORD) + float(BASE_MANA_10_CRYPT_LORD - BASE_MANA_1_CRYPT_LORD) * (mylevel/83.f);
    //TC_LOG_ERROR("entities.player", "classinfo base mana = {}", m_basemana);

    me->SetCreateMana(uint32(m_basemana));

    float intValue = _getTotalBotStat(BOT_STAT_MOD_INTELLECT);

    intValue -= std::min<float>(me->GetCreateStat(STAT_INTELLECT), 20.f); //not a mistake
    intValue = std::max<float>(intValue, 0.f);

    float intMult = _botclass < BOT_CLASS_EX_START ? 15.f : IsHeroExClass(_botclass) ? 5.f : 1.5f;

    m_basemana = intValue * intMult + 20.f; //20.f is not a mistake
    //m_basemana += IAmFree() ? mylevel * 50.f : 0; //+4000/+0 mana at 80
    m_basemana += _getTotalBotStat(BOT_STAT_MOD_MANA);

    //mana bonuses
    uint8 bonuspct = 0;
    //Fel Vitality
    if (_botclass == BOT_CLASS_WARLOCK && mylevel >= 15)
        bonuspct += 3;
    if (bonuspct)
        m_basemana = (m_basemana * (100 + bonuspct)) / 100;

    //m_basemana = float(uint32(m_basemana) - (uint32(m_basemana) % 5));
    me->SetStatFlatModifier(UNIT_MOD_MANA, BASE_VALUE, m_basemana);
    me->UpdateMaxPower(POWER_MANA);
    me->SetPower(POWER_MANA, fullmana ? me->GetMaxPower(POWER_MANA) :
        uint32(0.5f + float(me->GetMaxPower(POWER_MANA)) * pct / 100.f)); //restore pct

    _OnManaRegenUpdate();
}
//Mana regen for minions
void bot_ai::_OnManaRegenUpdate() const
{
    //regen_normal
    uint8 mylevel = me->GetLevel();
    float value = (IAmFree() && _botclass != BOT_CLASS_SPHYNX) ? mylevel/2 : 0; //200/0 mp5 at 80

    float power_regen_mp5;
    int32 modManaRegenInterrupt;
    if (_botclass < BOT_CLASS_EX_START)
    {
        // Mana regen from spirit and intellect
        float spiregen = 0.001f;
        if (GtRegenMPPerSptEntry const* moreRatio = sGtRegenMPPerSptStore.LookupEntry((_botclass-1)*GT_MAX_LEVEL + mylevel-1))
            spiregen = moreRatio->Data * _getTotalBotStat(BOT_STAT_MOD_SPIRIT);

        // PCT bonus from SPELL_AURA_MOD_POWER_REGEN_PERCENT aura on spirit base regen
        value += sqrt(_getTotalBotStat(BOT_STAT_MOD_INTELLECT)) * spiregen * me->GetTotalAuraMultiplierByMiscValue(SPELL_AURA_MOD_POWER_REGEN_PERCENT, POWER_MANA);
        // regen from SPELL_AURA_MOD_POWER_REGEN aura (per second)
        power_regen_mp5 = 0.2f * (me->GetTotalAuraModifierByMiscValue(SPELL_AURA_MOD_POWER_REGEN, POWER_MANA) + _getTotalBotStat(BOT_STAT_MOD_MANA_REGENERATION));

        // bonus from SPELL_AURA_MOD_MANA_REGEN_FROM_STAT aura
        Unit::AuraEffectList const& regenAura = me->GetAuraEffectsByType(SPELL_AURA_MOD_MANA_REGEN_FROM_STAT);
        for (Unit::AuraEffectList::const_iterator i = regenAura.begin(); i != regenAura.end(); ++i)
            power_regen_mp5 += me->GetStat(Stats((*i)->GetMiscValue())) * (*i)->GetAmount() * 0.002f; //per second

        //bot also receive bonus from SPELL_AURA_MOD_POWER_REGEN_PERCENT for mp5 regen
        power_regen_mp5 *= me->GetTotalAuraMultiplierByMiscValue(SPELL_AURA_MOD_POWER_REGEN_PERCENT, POWER_MANA);

        // Set regen rate in cast state apply only on spirit based regen
        modManaRegenInterrupt = std::min<int32>(100, me->GetTotalAuraModifier(SPELL_AURA_MOD_MANA_REGEN_INTERRUPT));
    }
    else
    {
        modManaRegenInterrupt = 100;
        power_regen_mp5 = 0.0f;

        if (IsHeroExClass(_botclass))
        {
            float basemana;
            if (_botclass == BOT_CLASS_BM)
                basemana = BASE_MANA_1_BM;
            else if (_botclass == BOT_CLASS_ARCHMAGE)
                basemana = BASE_MANA_1_ARCHMAGE;
            else if (_botclass == BOT_CLASS_DREADLORD)
                basemana = BASE_MANA_1_DREADLORD;
            else if (_botclass == BOT_CLASS_DARK_RANGER)
                basemana = BASE_MANA_1_DARK_RANGER;
            else if (_botclass == BOT_CLASS_SEA_WITCH)
                basemana = BASE_MANA_1_SEA_WITCH;
            else if (_botclass == BOT_CLASS_CRYPT_LORD)
                basemana = BASE_MANA_1_CRYPT_LORD;
            else
                basemana = 0.f;

            value = basemana * 0.0087f + 0.08f * GetTotalBotStat(BOT_STAT_MOD_INTELLECT);
            value += 0.2f * (me->GetTotalAuraModifierByMiscValue(SPELL_AURA_MOD_POWER_REGEN, POWER_MANA) + _getTotalBotStat(BOT_STAT_MOD_MANA_REGENERATION));
            value *= me->GetTotalAuraMultiplierByMiscValue(SPELL_AURA_MOD_POWER_REGEN_PERCENT, POWER_MANA);

            //if (_botclass == BOT_CLASS_SEA_WITCH && me->HasAuraType(SPELL_AURA_MANA_SHIELD))
            //    modManaRegenInterrupt *= 0.25f;
        }
        else if (_botclass == BOT_CLASS_SPHYNX)
        {
            value = CalculatePct(me->GetCreateMana(), 2); //-2% basemana/sec
        }
        else if (_botclass == BOT_CLASS_SPELLBREAKER)
        {
            value = 4.f; //base 0.8/sec
            value += 0.2f * (me->GetTotalAuraModifierByMiscValue(SPELL_AURA_MOD_POWER_REGEN, POWER_MANA) + _getTotalBotStat(BOT_STAT_MOD_MANA_REGENERATION));
            value *= me->GetTotalAuraMultiplierByMiscValue(SPELL_AURA_MOD_POWER_REGEN_PERCENT, POWER_MANA);
        }
        else if (_botclass == BOT_CLASS_NECROMANCER)
        {
            value = 7.5f; //base 1.5/sec
            value += 0.2f * (me->GetTotalAuraModifierByMiscValue(SPELL_AURA_MOD_POWER_REGEN, POWER_MANA) + _getTotalBotStat(BOT_STAT_MOD_MANA_REGENERATION));
            value *= me->GetTotalAuraMultiplierByMiscValue(SPELL_AURA_MOD_POWER_REGEN_PERCENT, POWER_MANA);
        }
        else
            value = 0;
    }

    //Unrelenting Storm, Dreamstate: 12% of intellect as mana regen always (divided by 5)
    if ((_botclass == BOT_CLASS_SHAMAN && GetSpec() == BOT_SPEC_SHAMAN_ELEMENTAL) ||
        (_botclass == BOT_CLASS_DRUID && GetSpec() == BOT_SPEC_DRUID_BALANCE))
        power_regen_mp5 += 0.024f * _getTotalBotStat(BOT_STAT_MOD_INTELLECT);

    me->SetStatFloatValue(UNIT_FIELD_POWER_REGEN_INTERRUPTED_FLAT_MODIFIER, power_regen_mp5 + CalculatePct(value, modManaRegenInterrupt));
    me->SetStatFloatValue(UNIT_FIELD_POWER_REGEN_FLAT_MODIFIER, power_regen_mp5 + value);
}

void bot_ai::_UpdateWMOArea()
{
    _wmoAreaUpdateTimer = urand(7000, 9000);

    uint32 mogpFlags;
    int32 adtId, rootId, groupId;
    me->GetMap()->GetAreaInfo(me->GetPhaseMask(), me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(),
        mogpFlags, adtId, rootId, groupId);

    if (WMOAreaTableEntry const* wmoEntry = GetWMOAreaTableEntryByTripple(rootId, adtId, groupId))
    {
        _lastWMOAreaId = wmoEntry->ID;
        //TC_LOG_ERROR("scripts", "_UpdateWMOArea(): bot {}: area {}, wmoarea {}", me->GetName(), _lastAreaId, _lastWMOAreaId);
    }
}

void bot_ai::_OnZoneUpdate(uint32 zoneId, uint32 areaId)
{
    ASSERT(me->IsInWorld());

    _lastZoneId = zoneId;

    SetGroupUpdateFlag(GROUP_UPDATE_FULL);

    _OnAreaUpdate(areaId);

    if (!IAmFree())
    {
        SpellAreaForAreaMapBounds saBounds = sSpellMgr->GetSpellAreaForAreaMapBounds(zoneId);
        for (SpellAreaForAreaMap::const_iterator itr = saBounds.first; itr != saBounds.second; ++itr)
        {
            if (itr->second->autocast && itr->second->IsFitToRequirements(master, zoneId, 0))
            {
                if (!me->HasAura(itr->second->spellId))
                    me->CastSpell(me, itr->second->spellId, true);
                if (botPet && !botPet->HasAura(itr->second->spellId))
                    botPet->CastSpell(botPet, itr->second->spellId, true);
            }
        }
    }
}

void bot_ai::_OnAreaUpdate(uint32 areaId)
{
    ASSERT(me->IsInWorld());

    _lastAreaId = areaId;

    if (!IAmFree())
    {
        Unit::AuraMap const& ownerAuras = me->GetOwnedAuras();
        for (Unit::AuraMap::const_iterator iter = ownerAuras.cbegin(); iter != ownerAuras.cend(); ++iter)
        {
            if (iter->second->GetSpellInfo()->HasAura(SPELL_AURA_MOUNTED))
                continue;

            if (iter->second->GetSpellInfo()->CheckLocation(me->GetMapId(), _lastZoneId, areaId, master, false) != SPELL_CAST_OK)
            {
                //me->RemoveOwnedAura(iter);
                //we assume 1 aura at a time at most for area (once per 1.5 sec)
                uint32 spellId = iter->first;
                me->RemoveAurasDueToSpell(spellId);
                if (botPet)
                    botPet->RemoveAurasDueToSpell(spellId);
                break;
            }
        }

        SpellAreaForAreaMapBounds saBounds = sSpellMgr->GetSpellAreaForAreaMapBounds(areaId);
        for (SpellAreaForAreaMap::const_iterator itr = saBounds.first; itr != saBounds.second; ++itr)
        {
            if (itr->second->autocast && itr->second->IsFitToRequirements(master, _lastZoneId, 0))
            {
                if (!me->HasAura(itr->second->spellId))
                    me->CastSpell(me, itr->second->spellId, true);
                if (botPet && !botPet->HasAura(itr->second->spellId))
                    botPet->CastSpell(botPet, itr->second->spellId, true);
            }
        }

        for (uint8 slot = BOT_SLOT_MAINHAND; slot <= BOT_SLOT_RANGED; ++slot)
        {
            if (Item const* item = _equips[slot])
                if (item->IsLimitedToAnotherMapOrZone(me->GetMapId(), areaId))
                    if (_resetEquipment(slot, ObjectGuid::Empty))
                        continue;
        }
    }

    AreaTableEntry const* area = sAreaTableStore.LookupEntry(areaId);
    if (area && area->IsSanctuary())
    {
        if (!me->HasByteFlag(UNIT_FIELD_BYTES_2, 1, UNIT_BYTE2_FLAG_SANCTUARY))
        {
            me->SetByteFlag(UNIT_FIELD_BYTES_2, 1, UNIT_BYTE2_FLAG_SANCTUARY);
            me->CombatStop();
            if (botPet)
                botPet->CombatStop();
        }
    }
    else if (me->HasByteFlag(UNIT_FIELD_BYTES_2, 1, UNIT_BYTE2_FLAG_SANCTUARY))
        me->RemoveByteFlag(UNIT_FIELD_BYTES_2, 1, UNIT_BYTE2_FLAG_SANCTUARY);
}

bool bot_ai::IsInHeroicOrRaid() const
{
    return me->FindMap() && (me->GetMap()->IsHeroic() || me->GetMap()->IsRaid());
}

//SpellHit()... OnSpellHit()
void bot_ai::OnSpellHit(Unit* caster, SpellInfo const* spell)
{
    //uint32 const spellId = spell->Id;

    if (!spell->IsPositive() && spell->GetMaxDuration() > 1000 && caster->IsControlledByPlayer() &&
        _botclass >= BOT_CLASS_EX_START)
    {
        //bots of W3 classes will not be easily CCed
        if (spell->HasAura(SPELL_AURA_MOD_STUN) || spell->HasAura(SPELL_AURA_MOD_CONFUSE) ||
            spell->HasAura(SPELL_AURA_MOD_PACIFY) || spell->HasAura(SPELL_AURA_MOD_ROOT))
        {
            if (Aura* cont = me->GetAura(spell->Id, caster->GetGUID()))
            {
                if (AuraApplication const* aurApp = cont->GetApplicationOfTarget(me->GetGUID()))
                {
                    if (!aurApp->IsPositive())
                    {
                        int32 dur = std::max<int32>(cont->GetMaxDuration() / 3, 1000);
                        cont->SetDuration(dur);
                        cont->SetMaxDuration(dur);
                    }
                }
            }
        }
    }

    if (!HasBotCommandState(BOT_COMMAND_FULLSTOP | BOT_COMMAND_INACTION))
    {
        if (spell->HasAura(SPELL_AURA_MOD_TAUNT) || spell->HasEffect(SPELL_EFFECT_ATTACK_ME))
            if (caster && me->Attack(caster, !HasRole(BOT_ROLE_RANGED)))
            {}//me->GetMotionMaster()->MoveChase(caster);
    }

    if (spell->GetSpellSpecific() == SPELL_SPECIFIC_DRINK)
    {
        feast_mana = true;
        UpdateMana();
        regenTimer = 0;
    }
    else if (spell->GetSpellSpecific() == SPELL_SPECIFIC_FOOD)
    {
        feast_health = true;
        regenTimer = 0;
    }

    switch (spell->Id)
    {
        case WANDERER_HEARTHSTONE:
            if (IsWanderer())
            {
                Map* targetMap = (me->GetMap()->GetEntry()->IsContinent() && _travel_node_cur->GetMapId() != me->GetMap()->GetId()) ?
                    sMapMgr->CreateBaseMap(_travel_node_cur->GetMapId()) : me->GetMap();
                BotMgr::TeleportBot(me, targetMap, _travel_node_cur, true);
                _evadeCount = 0;
            }
            return;
        default:
            break;
    }

    for (uint8 i = 0; i != MAX_SPELL_EFFECTS; ++i)
    {
        uint32 const auraname = spell->_effects[i].ApplyAuraName;
        //remove pet on mount
        if (auraname == SPELL_AURA_MOUNTED || (!spell->HasAura(SPELL_AURA_MOUNTED) && auraname == SPELL_AURA_MOD_INCREASE_VEHICLE_FLIGHT_SPEED))
        {
            //TC_LOG_ERROR("entities.unit", "OnSpellHit: mount on {}", me->GetName());
            if (master->HasAuraType(SPELL_AURA_MOD_INCREASE_VEHICLE_FLIGHT_SPEED) ||
                master->HasAuraType(SPELL_AURA_MOD_INCREASE_MOUNTED_FLIGHT_SPEED))
            {
                //TC_LOG_ERROR("entities.unit", "OnSpellHit: modding flight speed");
                UnsummonAll(false);
                const_cast<CreatureTemplate*>(me->GetCreatureTemplate())->Movement.Flight = CreatureFlightMovementType::DisableGravity;
                me->SetCanFly(true);
                me->SetDisableGravity(true);
                if (Aura* mount = me->GetAura(spell->Id))
                {
                    //TC_LOG_ERROR("entities.unit", "OnSpellHit: found aura");
                    for (uint8 j = 0; j != MAX_SPELL_EFFECTS; ++j)
                    {
                        if (spell->_effects[j].ApplyAuraName != SPELL_AURA_MOD_INCREASE_VEHICLE_FLIGHT_SPEED &&
                            spell->_effects[j].ApplyAuraName != SPELL_AURA_MOD_INCREASE_MOUNTED_FLIGHT_SPEED &&
                            spell->_effects[j].ApplyAuraName != SPELL_AURA_MOD_INCREASE_MOUNTED_SPEED &&
                            !(GetBotStance() == DRUID_FLIGHT_FORM && spell->_effects[j].ApplyAuraName == SPELL_AURA_MOD_INCREASE_SPEED))
                            continue;
                        if (AuraEffect* meff = mount->GetEffect(j))
                        {
                            meff->ChangeAmount(meff->GetAmount() * 3);
                        }
                    }
                }
                //me->SetSpeedRate(MOVE_FLIGHT, master->GetSpeedRate(MOVE_FLIGHT) * 1.37f);
                //me->SetSpeedRate(MOVE_RUN, master->GetSpeedRate(MOVE_FLIGHT) * 1.37f);
            }
            else
                me->SetSpeedRate(MOVE_RUN, master->GetSpeedRate(MOVE_RUN) * 1.1f);
        }

        //update stats
        if (auraname == SPELL_AURA_MOD_STAT || auraname == SPELL_AURA_MOD_PERCENT_STAT ||
            auraname == SPELL_AURA_MOD_TOTAL_STAT_PERCENTAGE || auraname == SPELL_AURA_MOD_SKILL ||
            auraname == SPELL_AURA_MOD_ATTACK_POWER || auraname == SPELL_AURA_MOD_ATTACK_POWER_PCT ||
            auraname == SPELL_AURA_MOD_ATTACK_POWER_OF_STAT_PERCENT || auraname == SPELL_AURA_MOD_ATTACK_POWER_OF_ARMOR ||
            auraname == SPELL_AURA_MOD_SPELL_DAMAGE_OF_STAT_PERCENT ||
            auraname == SPELL_AURA_MOD_RATING || auraname == SPELL_AURA_MOD_RATING_FROM_STAT)
            shouldUpdateStats = true;
        else if (auraname == SPELL_AURA_MOD_INCREASE_HEALTH ||
            auraname == SPELL_AURA_MOD_INCREASE_HEALTH_2 ||
            auraname == SPELL_AURA_230 ||//SPELL_AURA_MOD_INCREASE_HEALTH_2 blood pact, commanding shout
            auraname == SPELL_AURA_MOD_INCREASE_HEALTH_PERCENT)
            UpdateHealth();
        else if (auraname == SPELL_AURA_MOD_INCREASE_ENERGY || auraname == SPELL_AURA_MOD_INCREASE_ENERGY_PERCENT)
            UpdateMana(); //Divine Hymn - max mana increase

        uint32 const effect = spell->_effects[i].Effect;
        if (effect == SPELL_EFFECT_RESURRECT || effect == SPELL_EFFECT_RESURRECT_NEW || effect == SPELL_EFFECT_SELF_RESURRECT)
        {
            //resurrect effects are not handled for creatures
            if (!me->IsAlive())
            {
                uint32 health = 0;
                uint32 mana = 0;
                int32 damage = spell->_effects[i].BasePoints;

                if (effect == SPELL_EFFECT_RESURRECT_NEW)
                {
                    //Glyph of Rebirth: resurrect with 100% health
                    if (spell->IsRankOf(sSpellMgr->GetSpellInfo(20484)))
                        health = me->GetMaxHealth();
                    else
                        health = damage;
                    mana = spell->_effects[i].MiscValue;
                }
                else if (damage < 0)
                {
                    health = uint32(-damage);
                    mana = spell->_effects[i].MiscValue;
                }
                else
                {
                    health = me->CountPctFromMaxHealth(damage);
                    if (me->GetMaxPower(POWER_MANA) > 1)
                        mana = CalculatePct(me->GetMaxPower(POWER_MANA), damage);
                }

                BotMgr::ReviveBot(me, caster);
                _selfrez_spell_id = 0;

                me->SetHealth(health);
                if (me->GetMaxPower(POWER_MANA) > 1)
                    me->SetPower(POWER_MANA, mana);
            }
        }
        //ravasaur poison (EffectEnchantHeldItem) for mh and oh
        if (effect == SPELL_EFFECT_ENCHANT_HELD_ITEM)
        {
            uint32 enchant_id = spell->_effects[i].MiscValue;
            if (!enchant_id)
                continue;

            EnchantmentSlot slot = TEMP_ENCHANTMENT_SLOT;
            Item* weap = _equips[BOT_SLOT_MAINHAND];
            if (!weap || weap->GetEnchantmentId(slot))
                weap = _equips[BOT_SLOT_OFFHAND];
            if (!weap || weap->GetTemplate()->Class != ITEM_CLASS_WEAPON || weap->GetEnchantmentId(slot))
                continue;

            int32 duration = spell->GetDuration();
            if (!duration)
                duration = 10; //10 sec default

            if (!IAmFree())
                master->GetSession()->SendEnchantmentLog(me->GetGUID(), caster->GetGUID(), weap->GetEntry(), enchant_id);

            weap->SetUInt32Value(ITEM_FIELD_ENCHANTMENT_1_1 + slot*MAX_ENCHANTMENT_OFFSET + ENCHANTMENT_ID_OFFSET, enchant_id);
            weap->SetUInt32Value(ITEM_FIELD_ENCHANTMENT_1_1 + slot*MAX_ENCHANTMENT_OFFSET + ENCHANTMENT_DURATION_OFFSET, duration * IN_MILLISECONDS);
            weap->SetUInt32Value(ITEM_FIELD_ENCHANTMENT_1_1 + slot*MAX_ENCHANTMENT_OFFSET + ENCHANTMENT_CHARGES_OFFSET, 0);
            ApplyItemBonuses(weap == _equips[BOT_SLOT_MAINHAND] ? BOT_SLOT_MAINHAND : BOT_SLOT_OFFHAND);
        }
    }

    //TODO:
    if (/*!(spell->AttributesEx & SPELL_ATTR1_NO_THREAT) &&
        !(spell->AttributesEx3 & SPELL_ATTR3_NO_INITIAL_AGGRO) && !CCed(me) && */
        !me->GetVictim() &&
        (me->IsHostileTo(caster) || caster->IsHostileTo(me)))
    {
        //_atHome = false;
        if (!me->CanSeeOrDetect(caster))
        {
            if (_evadeMode)
                me->BotStopMovement();
        }
        else if (caster->IsInCombat() || me->IsInCombat())
            this->OwnerAttackedBy(caster);
        //if (_evadeMode == true && me->isMoving() && IAmFree())
    }
}
void bot_ai::OnSpellHitTarget(Unit* /*target*/, SpellInfo const* spell)
{
    if (me->GetVehicle())
    {
        uint32 spellId = spell->Id;

        //Flame Spike, Revivify
        if (spellId == 56091 || spellId == 57090)
        {
            vehcomboPoints = std::min(vehcomboPoints + 1, 5);
            //TC_LOG_ERROR("scripts", "OnBotSpellGo(): veh cp spell {} now cp {}", curInfo->Id, uint32(vehcomboPoints));
        }
        //Engulf in Flames, Life Burst, Flame Shield   moved to globalupdate
        if (spellId == 56092 || spellId == 57143 || spellId == 57108)
        {
            vehcomboPoints = 0;
            //TC_LOG_ERROR("scripts", "OnSpellHitTarget(): veh cp waster {}", curInfo->Id);
        }
    }
}
//Update delay
//Skip UpdateAI cycles for randomization of bots' reaction and performance adjustments
bool bot_ai::Wait()
{
    if (waitTimer > lastdiff || !master->IsInWorld())
        return true;

    if (IAmFree())
        waitTimer = (me->IsInCombat() || me->GetVictim() || me->GetMap()->IsBattlegroundOrArena()) ? 500 : ((__rand + 100) * 20);
    else if (!master->GetMap()->IsRaid())
        waitTimer = std::min<uint32>(uint32(50 * (master->GetNpcBotsCount() - 1) + __rand), 500);
    else
        waitTimer = __rand;

    waitTimer += BotMgr::GetBaseUpdateDelay();

    return false;
}
//Spell Mod Hooks
void bot_ai::ApplyBotDamageMultiplierMelee(uint32& damage, CalcDamageInfo& damageinfo) const
{
    //WHITE ATTACKS damage bonus
    damage *= BotMgr::GetBotDamageModByClass(GetBotClass());
    damage *= BotMgr::GetBotDamageModByLevel(me->GetLevel());
    ApplyClassDamageMultiplierMelee(damage, damageinfo);
}
void bot_ai::ApplyBotDamageMultiplierMelee(int32& damage, SpellNonMeleeDamage& damageinfo, SpellInfo const* spellInfo, WeaponAttackType attackType, bool iscrit) const
{
    //MELEE ABILITIES damage bonus (DMG_CLASS != DMG_CLASS_MAGIC)
    damage *= BotMgr::GetBotDamageModByClass(GetBotClass());
    damage *= BotMgr::GetBotDamageModByLevel(me->GetLevel());
    ApplyClassDamageMultiplierMeleeSpell(damage, damageinfo, spellInfo, attackType, iscrit);
}
void bot_ai::ApplyBotDamageMultiplierSpell(int32& damage, SpellNonMeleeDamage& damageinfo, SpellInfo const* spellInfo, WeaponAttackType attackType, bool iscrit) const
{
    //DAMAGE SPELLS damage bonus (DMG_CLASS_MAGIC)
    damage *= BotMgr::GetBotDamageModByClass(GetBotClass());
    damage *= BotMgr::GetBotDamageModByLevel(me->GetLevel());
    ApplyClassDamageMultiplierSpell(damage, damageinfo, spellInfo, attackType, iscrit);
}
void bot_ai::ApplyBotDamageMultiplierHeal(Unit const* victim, float& heal, SpellInfo const* spellInfo, DamageEffectType damagetype, uint32 stack) const
{
    //HEALING SPELLS amount bonus
    ApplyClassDamageMultiplierHeal(victim, heal, spellInfo, damagetype, stack);
    heal = (heal * (BotMgr::IsWanderingWorldBot(me) ? BotMgr::GetBotWandererHealingMod() : BotMgr::GetBotHealingMod()));
}
void bot_ai::ApplyBotCritMultiplierAll(Unit const* victim, float& crit_chance, SpellInfo const* spellInfo, SpellSchoolMask schoolMask, WeaponAttackType attackType) const
{
    //ALL SPELLS crit bonus + base
    ApplyClassSpellCritMultiplierAll(victim, crit_chance, spellInfo, schoolMask, attackType);
    crit_chance += crit;
}
void bot_ai::ApplyBotSpellCostMods(SpellInfo const* spellInfo, int32& cost) const
{
    //ALL SPELLS power cost bonus
    ApplyClassSpellCostMods(spellInfo, cost);
}
void bot_ai::ApplyBotSpellCastTimeMods(SpellInfo const* spellInfo, int32& casttime) const
{
    //ALL SPELLS cast time bonus
    ApplyClassSpellCastTimeMods(spellInfo, casttime);
}
void bot_ai::ApplyBotSpellCooldownMods(SpellInfo const* spellInfo, uint32& cooldown) const
{
    //ALL SPELLS cooldown bonus
    ApplyClassSpellCooldownMods(spellInfo, cooldown);
}
void bot_ai::ApplyBotSpellCategoryCooldownMods(SpellInfo const* spellInfo, uint32& cooldown) const
{
    //ALL SPELLS category cooldown bonus
    ApplyClassSpellCategoryCooldownMods(spellInfo, cooldown);
}
void bot_ai::ApplyBotSpellGlobalCooldownMods(SpellInfo const* spellInfo, float& cooldown) const
{
    //ALL SPELLS global cooldown bonus
    ApplyClassSpellGlobalCooldownMods(spellInfo, cooldown);
}
void bot_ai::ApplyBotSpellRadiusMods(SpellInfo const* spellInfo, float& radius) const
{
    //ALL SPELLS radius bonus (not range)
    ApplyClassSpellRadiusMods(spellInfo, radius);
}
void bot_ai::ApplyBotSpellRangeMods(SpellInfo const* spellInfo, float& maxrange) const
{
    //ALL SPELLS range bonus
    ApplyClassSpellRangeMods(spellInfo, maxrange);
}
void bot_ai::ApplyBotSpellMaxTargetsMods(SpellInfo const* spellInfo, uint32& targets) const
{
    //ALL SPELLS max targets bonus
    ApplyClassSpellMaxTargetsMods(spellInfo, targets);
}
void bot_ai::ApplyBotSpellChanceOfSuccessMods(SpellInfo const* spellInfo, float& chance) const
{
    //ALL CLASS PROC_TRIGGER_SPELL SPELLS chance of success bonus
    ApplyClassSpellChanceOfSuccessMods(spellInfo, chance);
}
void bot_ai::ApplyBotEffectMods(SpellInfo const* spellInfo, uint8 effIndex, float& value) const
{
    //ALL SPELLS SPELLMOD_EFFECT_X bonus
    ApplyClassEffectMods(spellInfo, effIndex, value);
}
void bot_ai::ApplyBotThreatMods(SpellInfo const* spellInfo, float& threat) const
{
    //ALL threat mods
    ApplyClassThreatMods(spellInfo, threat);
}
void bot_ai::ApplyBotEffectValueMultiplierMods(SpellInfo const* spellInfo, SpellEffIndex effIndex, float& multiplier) const
{
    //ALL SPELLMOD_VALUE_MULTIPLIER mods
    ApplyClassEffectValueMultiplierMods(spellInfo, effIndex, multiplier);
}
//Spell Mod Utilities
float bot_ai::CalcSpellMaxRange(uint32 spellId, bool enemy) const
{
    SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(spellId);
    //ASSERT(spellInfo);
    spellInfo = spellInfo->TryGetSpellInfoOverride(me);

    float maxRange = spellInfo->GetMaxRange(!enemy);
    if (maxRange == 0x0)
        return maxRange;

    ApplyClassSpellRangeMods(spellInfo, maxRange);
    return maxRange;
}
//////////
//GOSSIP//
//////////
//GossipHello
bool bot_ai::OnGossipHello(Player* player, uint32 /*option*/)
{
    if (!BotMgr::IsNpcBotModEnabled() || !(IsWanderer() ? BotMgr::IsWanderingClassEnabled(_botclass) : BotMgr::IsClassEnabled(_botclass)) ||
        IsTempBot() || me->IsInCombat() || CCed(me) || IsCasting() || IsDuringTeleport() ||
        HasBotCommandState(BOT_COMMAND_ISSUED_ORDER | BOT_COMMAND_NOGOSSIP) ||
        (me->GetVehicle() && me->GetVehicle()->GetBase()->IsInCombat()) ||
        (!player->IsGameMaster() && IsWanderer()))
    {
        player->PlayerTalkClass->SendCloseGossip();
        return true;
    }

    if (me->isMoving())
        me->BotStopMovement();

    evadeDelayTimer = std::max<decltype(evadeDelayTimer)>(evadeDelayTimer, 10000);

    uint32 gossipTextId;
    if (!IAmFree())
    {
        if (_botclass == BOT_CLASS_SPHYNX)
            gossipTextId = GOSSIP_NORMAL_CUSTOM_SPHYNX;
        else if (_botclass == BOT_CLASS_DREADLORD)
            gossipTextId = GOSSIP_NORMAL_CUSTOM_DREADLORD;
        else if (_botclass == BOT_CLASS_DARK_RANGER)
            gossipTextId = GOSSIP_NORMAL_CUSTOM_DARKRANGER;
        else if (_botclass == BOT_CLASS_SEA_WITCH)
            gossipTextId = GOSSIP_NORMAL_CUSTOM_SEAWITCH;
        else if (_botclass == BOT_CLASS_CRYPT_LORD)
            gossipTextId = GOSSIP_NORMAL_CUSTOM_CRYPTLORD;
        else
            gossipTextId = GOSSIP_NORMAL_SERVE_MASTER;
    }
    else
    {
        if (_botclass == BOT_CLASS_SPHYNX)
            gossipTextId = GOSSIP_GREET_CUSTOM_SPHYNX;
        else if (_botclass == BOT_CLASS_DREADLORD)
            gossipTextId = GOSSIP_GREET_CUSTOM_DREADLORD;
        else if (_botclass == BOT_CLASS_DARK_RANGER)
            gossipTextId = GOSSIP_GREET_CUSTOM_DARKRANGER;
        else if (_botclass == BOT_CLASS_SEA_WITCH)
            gossipTextId = GOSSIP_GREET_CUSTOM_SEAWITCH;
        else if (_botclass == BOT_CLASS_CRYPT_LORD)
            gossipTextId = GOSSIP_GREET_CUSTOM_CRYPTLORD;
        else
            gossipTextId = GOSSIP_GREET_NEED_SMTH;
    }

    bool menus = false;

    if (player->IsGameMaster())
    {
        AddGossipItemFor(player, GOSSIP_ICON_CHAT, LocalizedNpcText(player, BOT_TEXT_DEBUG), GOSSIP_SENDER_DEBUG, GOSSIP_ACTION_INFO_DEF + 1);
        menus = true;
    }

    if (player->GetGUID().GetCounter() != _ownerGuid)
    {
        if (IAmFree() && !IsWanderer())
        {
            uint32 cost = BotMgr::GetNpcBotCost(player->GetLevel(), _botclass);

            int8 reason = 0;
            if (me->HasAura(BERSERK))
                reason = -1;
            if (!reason && _ownerGuid)
                reason = 1;
            if (!reason && BotDataMgr::GetOwnedBotsCount(player->GetGUID()) >= BotMgr::GetMaxNpcBots(player->GetLevel()))
                reason = 2;
            if (!reason && !player->HasEnoughMoney(cost))
                reason = 3;
            if (!reason && BotMgr::GetMaxClassBots() && BotDataMgr::GetOwnedBotsCount(player->GetGUID(), me->GetClassMask()) >= BotMgr::GetMaxClassBots())
                reason = 4;

            std::ostringstream message1;
            std::ostringstream message2;
            if (_botclass == BOT_CLASS_SPHYNX)
            {
                message1 << LocalizedNpcText(player, BOT_TEXT_HIREWARN_SPHYNX_1) << me->GetName() << LocalizedNpcText(player, BOT_TEXT_HIREWARN_SPHYNX_2);
                message2 << LocalizedNpcText(player, BOT_TEXT_HIREOPTION_SPHYNX);
            }
            else if (_botclass == BOT_CLASS_DREADLORD)
            {
                message1 << LocalizedNpcText(player, BOT_TEXT_HIREWARN_DREADLORD) << me->GetName() << '?';
                message2 << LocalizedNpcText(player, BOT_TEXT_HIREOPTION_DREADLORD);
            }
            else if (_botclass == BOT_CLASS_SEA_WITCH)
            {
                message1 << LocalizedNpcText(player, BOT_TEXT_HIREWARN_SEAWITCH);
                message2 << LocalizedNpcText(player, BOT_TEXT_HIREOPTION_SEAWITCH);
            }
            else if (_botclass == BOT_CLASS_CRYPT_LORD)
            {
                message1 << LocalizedNpcText(player, BOT_TEXT_HIREWARN_CRYPTLORD);
                message2 << LocalizedNpcText(player, BOT_TEXT_HIREOPTION_CRYPTLORD);
            }
            else
            {
                message1 << LocalizedNpcText(player, BOT_TEXT_HIREWARN_DEFAULT) << me->GetName() << '?';
                message2 << LocalizedNpcText(player, BOT_TEXT_HIREOPTION_DEFAULT);
            }

            if (!reason)
            {
                player->PlayerTalkClass->GetGossipMenu().AddMenuItem(-1, GOSSIP_ICON_TAXI, message2.str().c_str(),
                    GOSSIP_SENDER_HIRE, GOSSIP_ACTION_INFO_DEF + 0, message1.str().c_str(), cost, false);
            }
            else
                AddGossipItemFor(player, GOSSIP_ICON_TAXI, message2.str().c_str(), GOSSIP_SENDER_HIRE, GOSSIP_ACTION_INFO_DEF + reason);

            menus = true;
        }
    }

    if (_ownerGuid)
    {
        Group const* gr = player->GetGroup();

        if (player == master)
        {
            menus = true;

            //general: equips, roles, distance, abilities, comsumables, group
            AddGossipItemFor(player, GOSSIP_ICON_TALK, LocalizedNpcText(player, BOT_TEXT_MANAGE_EQUIPMENT), GOSSIP_SENDER_EQUIPMENT, GOSSIP_ACTION_INFO_DEF + 1);
            AddGossipItemFor(player, GOSSIP_ICON_TALK, LocalizedNpcText(player, BOT_TEXT_MANAGE_ROLES), GOSSIP_SENDER_ROLES_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
            AddGossipItemFor(player, GOSSIP_ICON_TALK, LocalizedNpcText(player, BOT_TEXT_MANAGE_FORMATION), GOSSIP_SENDER_FORMATION, GOSSIP_ACTION_INFO_DEF + 1);
            AddGossipItemFor(player, GOSSIP_ICON_TALK, LocalizedNpcText(player, BOT_TEXT_MANAGE_ABILITIES), GOSSIP_SENDER_ABILITIES, GOSSIP_ACTION_INFO_DEF + 1);
            if (_botclass < BOT_CLASS_EX_START)
            {
                if (me->GetLevel() >= 10)
                    AddGossipItemFor(player, GOSSIP_ICON_TALK, LocalizedNpcText(player, BOT_TEXT_MANAGE_TALENTS), GOSSIP_SENDER_SPEC, GOSSIP_ACTION_INFO_DEF + 1);
                AddGossipItemFor(player, GOSSIP_ICON_TALK, LocalizedNpcText(player, BOT_TEXT_GIVE_CONSUMABLE), GOSSIP_SENDER_USEITEM, GOSSIP_ACTION_INFO_DEF + 1);
            }

            if (!gr)
            {
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, LocalizedNpcText(player, BOT_TEXT_CREATE_GROUP), GOSSIP_SENDER_JOIN_GROUP, GOSSIP_ACTION_INFO_DEF + 1);
                if (player->GetNpcBotsCount() > 1)
                    AddGossipItemFor(player, GOSSIP_ICON_CHAT, LocalizedNpcText(player, BOT_TEXT_CREATE_GROUP_ALL), GOSSIP_SENDER_JOIN_GROUP, GOSSIP_ACTION_INFO_DEF + 2);
            }
            else if (!gr->IsMember(me->GetGUID()))
            {
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, LocalizedNpcText(player, BOT_TEXT_ADD_TO_GROUP), GOSSIP_SENDER_JOIN_GROUP, GOSSIP_ACTION_INFO_DEF + 1);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, LocalizedNpcText(player, BOT_TEXT_ADD_TO_GROUP_ALL), GOSSIP_SENDER_JOIN_GROUP, GOSSIP_ACTION_INFO_DEF + 2);
            }
            else
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, LocalizedNpcText(player, BOT_TEXT_REMOVE_FROM_GROUP), GOSSIP_SENDER_LEAVE_GROUP, GOSSIP_ACTION_INFO_DEF + 1);

            //movement toggle
            if (HasBotCommandState(BOT_COMMAND_MASK_UNMOVING))
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, LocalizedNpcText(player, BOT_TEXT_FOLLOW_ME), GOSSIP_SENDER_FOLLOWME, GOSSIP_ACTION_INFO_DEF + 1);
            if (!HasBotCommandState(BOT_COMMAND_STAY))
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, LocalizedNpcText(player, BOT_TEXT_HOLD_POSITION), GOSSIP_SENDER_HOLDPOSITION, GOSSIP_ACTION_INFO_DEF + 1);
            if (!HasBotCommandState(BOT_COMMAND_FULLSTOP))
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, LocalizedNpcText(player, BOT_TEXT_STAY_HERE), GOSSIP_SENDER_DONOTHING, GOSSIP_ACTION_INFO_DEF + 1);
        }
        if (player == master || (gr && gr->IsMember(master->GetGUID())))
        {
            //class-specific for party: mage rations, rogue lockpicking etc.
            //TODO: priest lightwell (manual only) maybe move into abilities
            switch (_botclass)
            {
                case BOT_CLASS_MAGE:
                {
                    AddGossipItemFor(player, GOSSIP_ICON_CHAT, LocalizedNpcText(player, BOT_TEXT_MAGE_FOOD), GOSSIP_SENDER_CLASS, GOSSIP_ACTION_INFO_DEF + 1);
                    AddGossipItemFor(player, GOSSIP_ICON_CHAT, LocalizedNpcText(player, BOT_TEXT_MAGE_DRINK), GOSSIP_SENDER_CLASS, GOSSIP_ACTION_INFO_DEF + 2);
                    if (me->GetLevel() >= 70)
                        AddGossipItemFor(player, GOSSIP_ICON_CHAT, LocalizedNpcText(player, BOT_TEXT_MAGE_TABLE), GOSSIP_SENDER_CLASS, GOSSIP_ACTION_INFO_DEF + 3);
                    menus = true;
                    break;
                }
                case BOT_CLASS_ROGUE:
                {
                    //Learned at 16
                    //Allow rogues to gain skill with bot's help
                    if (me->GetLevel() >= 16/* && !player->HasSkill(SKILL_LOCKPICKING)*/)
                    {
                        std::ostringstream msg;
                        msg << LocalizedNpcText(player, BOT_TEXT_ROGUE_PICKLOCK) << " (" << uint32(me->GetLevel() * 5) << ")";
                        AddGossipItemFor(player, GOSSIP_ICON_CHAT, msg.str().c_str(), GOSSIP_SENDER_CLASS, GOSSIP_ACTION_INFO_DEF + 1);
                        menus = true;
                    }
                    break;
                }
                case BOT_CLASS_WARLOCK:
                {
                    AddGossipItemFor(player, GOSSIP_ICON_CHAT, LocalizedNpcText(player, BOT_TEXT_WARLOCK_HEALTHSTONE), GOSSIP_SENDER_CLASS, GOSSIP_ACTION_INFO_DEF + 1);
                    if (me->GetLevel() >= 68)
                        AddGossipItemFor(player, GOSSIP_ICON_CHAT, LocalizedNpcText(player, BOT_TEXT_WARLOCK_SOULWELL), GOSSIP_SENDER_CLASS, GOSSIP_ACTION_INFO_DEF + 3);
                    menus = true;
                    break;
                }
                default:
                    break;
            }
        }
        if (player == master)
        {
            //class-specific for owner: poisons, enchants, etc.
            switch (_botclass)
            {
                case BOT_CLASS_MAGE:
                {
                    if (me->GetLevel() >= 40)
                        AddGossipItemFor(player, GOSSIP_ICON_TALK, LocalizedNpcText(player, BOT_TEXT_I_NEED_A_PORTAL), GOSSIP_SENDER_CLASS, GOSSIP_ACTION_INFO_DEF + 4);
                    break;
                }
                case BOT_CLASS_ROGUE:
                {
                    if (me->GetLevel() >= 20)
                    {
                        AddGossipItemFor(player, GOSSIP_ICON_CHAT, LocalizedNpcText(player, BOT_TEXT_ROGUE_POISON_REFRESH), GOSSIP_SENDER_CLASS, GOSSIP_ACTION_INFO_DEF + 2);
                        AddGossipItemFor(player, GOSSIP_ICON_TALK, LocalizedNpcText(player, BOT_TEXT_ROGUE_POISON_MH), GOSSIP_SENDER_CLASS, GOSSIP_ACTION_INFO_DEF + 3);
                        Item const* oweap = _equips[BOT_SLOT_OFFHAND];
                        if (oweap && oweap->GetTemplate()->Class == ITEM_CLASS_WEAPON)
                            AddGossipItemFor(player, GOSSIP_ICON_TALK, LocalizedNpcText(player, BOT_TEXT_ROGUE_POISON_OH), GOSSIP_SENDER_CLASS, GOSSIP_ACTION_INFO_DEF + 4);
                    }
                    break;
                }
                case BOT_CLASS_SHAMAN:
                {
                    if (me->GetLevel() >= 10)
                    {
                        AddGossipItemFor(player, GOSSIP_ICON_CHAT, LocalizedNpcText(player, BOT_TEXT_SHAMAN_ENCH_REFRESH), GOSSIP_SENDER_CLASS, GOSSIP_ACTION_INFO_DEF + 2);
                        AddGossipItemFor(player, GOSSIP_ICON_TALK, LocalizedNpcText(player, BOT_TEXT_SHAMAN_ENCH_MH), GOSSIP_SENDER_CLASS, GOSSIP_ACTION_INFO_DEF + 3);
                        Item const* oweap = _equips[BOT_SLOT_OFFHAND];
                        if (oweap && oweap->GetTemplate()->Class == ITEM_CLASS_WEAPON)
                            AddGossipItemFor(player, GOSSIP_ICON_TALK, LocalizedNpcText(player, BOT_TEXT_SHAMAN_ENCH_OH), GOSSIP_SENDER_CLASS, GOSSIP_ACTION_INFO_DEF + 4);
                    }
                    if (me->GetShapeshiftForm() != FORM_NONE)
                        AddGossipItemFor(player, GOSSIP_ICON_CHAT, LocalizedNpcText(player, BOT_TEXT_REMOVE_SHAPESHIFT), GOSSIP_SENDER_CLASS, GOSSIP_ACTION_INFO_DEF + 5);
                    break;
                }
                case BOT_CLASS_DRUID:
                {
                    if (me->GetShapeshiftForm() != FORM_NONE)
                        AddGossipItemFor(player, GOSSIP_ICON_CHAT, LocalizedNpcText(player, BOT_TEXT_REMOVE_SHAPESHIFT), GOSSIP_SENDER_CLASS, GOSSIP_ACTION_INFO_DEF + 1);
                    break;
                }
                case BOT_CLASS_HUNTER:
                {
                    if (me->GetLevel() >= 10)
                        AddGossipItemFor(player, GOSSIP_ICON_CHAT, LocalizedNpcText(player, BOT_TEXT_CHOOSE_PET_TYPE), GOSSIP_SENDER_CLASS, GOSSIP_ACTION_INFO_DEF + 2);

                    break;
                }
                case BOT_CLASS_WARLOCK:
                {
                    AddGossipItemFor(player, GOSSIP_ICON_CHAT, LocalizedNpcText(player, BOT_TEXT_CHOOSE_PET_TYPE), GOSSIP_SENDER_CLASS, GOSSIP_ACTION_INFO_DEF + 2);
                    break;
                }
                default:
                    break;
            }

            std::ostringstream astr;
            astr << LocalizedNpcText(player, BOT_TEXT_ABANDON_WARN_1) << me->GetName() << "? " << (BotMgr::IsEnrageOnDimissEnabled() ? LocalizedNpcText(player, BOT_TEXT_ABANDON_WARN_2) : "");
            player->PlayerTalkClass->GetGossipMenu().AddMenuItem(-1, GOSSIP_ICON_TAXI, LocalizedNpcText(player, BOT_TEXT_UR_DISMISSED),
                GOSSIP_SENDER_DISMISS, GOSSIP_ACTION_INFO_DEF + 1, astr.str().c_str(), 0, false);

            AddGossipItemFor(player, GOSSIP_ICON_CHAT, LocalizedNpcText(player, BOT_TEXT_PULL_URSELF), GOSSIP_SENDER_TROUBLESHOOTING, GOSSIP_ACTION_INFO_DEF + 1);
        }
    }

    if (_botclass >= BOT_CLASS_EX_START)
    {
        menus = true;
        AddGossipItemFor(player, GOSSIP_ICON_CHAT, LocalizedNpcText(player, BOT_TEXT_STUDY_CREATURE), GOSSIP_SENDER_SCAN, GOSSIP_ACTION_INFO_DEF + 1);
    }

    if (!menus)
    {
        player->PlayerTalkClass->SendCloseGossip();
        return true;
    }

    AddGossipItemFor(player, GOSSIP_ICON_CHAT, LocalizedNpcText(player, BOT_TEXT_NEVERMIND), 0, GOSSIP_ACTION_INFO_DEF + 1);
    player->PlayerTalkClass->SendGossipMenu(gossipTextId, me->GetGUID());
    return true;
}

//GossipSelect
bool bot_ai::OnGossipSelect(Player* player, Creature* creature/* == me*/, uint32 sender, uint32 action)
{
    if (!BotMgr::IsNpcBotModEnabled() || me->HasUnitState(UNIT_STATE_CASTING) || CCed(me) || HasBotCommandState(BOT_COMMAND_ISSUED_ORDER) ||
        (me->GetVehicle() && me->GetVehicle()->GetBase()->IsInCombat()))
    {
        player->PlayerTalkClass->SendCloseGossip();
        return true;
    }

    if (me->isMoving())
        me->BotStopMovement();

    evadeDelayTimer = std::max<decltype(evadeDelayTimer)>(evadeDelayTimer, 10000);

    uint32 gossipTextId;
    if (!IAmFree())
    {
        if (_botclass == BOT_CLASS_SPHYNX)
            gossipTextId = GOSSIP_NORMAL_CUSTOM_SPHYNX;
        else if (_botclass == BOT_CLASS_DREADLORD)
            gossipTextId = GOSSIP_NORMAL_CUSTOM_DREADLORD;
        else if (_botclass == BOT_CLASS_DARK_RANGER)
            gossipTextId = GOSSIP_NORMAL_CUSTOM_DARKRANGER;
        else if (_botclass == BOT_CLASS_SEA_WITCH)
            gossipTextId = GOSSIP_NORMAL_CUSTOM_SEAWITCH;
        else if (_botclass == BOT_CLASS_CRYPT_LORD)
            gossipTextId = GOSSIP_NORMAL_CUSTOM_CRYPTLORD;
        else
            gossipTextId = GOSSIP_NORMAL_SERVE_MASTER;
    }
    else
    {
        if (_botclass == BOT_CLASS_SPHYNX)
            gossipTextId = GOSSIP_GREET_CUSTOM_SPHYNX;
        else if (_botclass == BOT_CLASS_DREADLORD)
            gossipTextId = GOSSIP_GREET_CUSTOM_DREADLORD;
        else if (_botclass == BOT_CLASS_DARK_RANGER)
            gossipTextId = GOSSIP_GREET_CUSTOM_DARKRANGER;
        else if (_botclass == BOT_CLASS_SEA_WITCH)
            gossipTextId = GOSSIP_GREET_CUSTOM_SEAWITCH;
        else if (_botclass == BOT_CLASS_CRYPT_LORD)
            gossipTextId = GOSSIP_GREET_CUSTOM_CRYPTLORD;
        else
            gossipTextId = GOSSIP_GREET_NEED_SMTH;
    }

    player->PlayerTalkClass->ClearMenus();
    bool subMenu = false;

    switch (sender)
    {
        case 0: //any kind of fail
        {
            BotSay("...", player);
            break;
        }
        case 1: //BACK: return to main menu
        {
            return bot_ai::OnGossipHello(player, 0);
        }
        case GOSSIP_SENDER_CLASS:
        {
            switch (_botclass)
            {
                case BOT_CLASS_MAGE:
                {
                    if (IsCasting())
                    {
                        player->SendEquipError(EQUIP_ERR_OBJECT_IS_BUSY, nullptr);
                        break;
                    }

                    uint32 option = action - GOSSIP_ACTION_INFO_DEF;
                    if (option == 1 || option == 2) //food, water
                    {
                        //Prevent high-leveled consumables for low-level characters
                        Unit* checker;
                        if (player->GetLevel() < me->GetLevel())
                            checker = player;
                        else
                            checker = me;

                        // Conjure Refreshment rank 1
                        uint32 food = InitSpell(checker, 42955);
                        bool iswater = (option == 2);
                        if (!food)
                        {
                            if (!iswater)// Conjure Food rank 1
                                food = InitSpell(checker, 587);
                            else// Conjure Water rank 1
                                food = InitSpell(checker, 5504);
                        }
                        if (!food)
                        {
                            BotWhisper(LocalizedNpcText(player, iswater ? BOT_TEXT_CANT_CONJURE_WATER_YET : BOT_TEXT_CANT_CONJURE_FOOD_YET), player);
                            break;
                        }
                        SpellInfo const* Info = sSpellMgr->GetSpellInfo(food);
                        Spell* foodspell = new Spell(me, Info, TRIGGERED_NONE, player->GetGUID());
                        SpellCastTargets targets;
                        targets.SetUnitTarget(player);
                        SpellCastResult result = me->IsMounted() || CCed(me) ? SPELL_FAILED_CUSTOM_ERROR : foodspell->CheckPetCast(player);
                        if (result != SPELL_CAST_OK)
                        {
                            foodspell->finish(false);
                            delete foodspell;
                            BotWhisper(LocalizedNpcText(player, BOT_TEXT_CANT_RIGHT_NOW), player);
                        }
                        else
                        {
                            aftercastTargetGuid = player->GetGUID();
                            foodspell->prepare(targets);
                            BotWhisper(LocalizedNpcText(player, BOT_TEXT_HERE_YOU_GO), player);
                        }
                        break;
                    }
                    else if (option == 3) //refreshment table
                    {
                        uint32 tableSpellId = GetSpell(43987); //Ritual of Refreshment
                        if (!tableSpellId)
                        {
                            BotWhisper(LocalizedNpcText(player, BOT_TEXT_DISABLED), player);
                            break;
                        }
                        if (!IsSpellReady(43987, GetLastDiff(), false))
                        {
                            BotWhisper(LocalizedNpcText(player, BOT_TEXT_NOT_READY_YET), player);
                            break;
                        }
                        uint32 tableGOForSpell = (tableSpellId == 43987 ? GO_REFRESHMENT_TABLE_1 : GO_REFRESHMENT_TABLE_2);
                        GameObjectTemplate const* goInfo = sObjectMgr->GetGameObjectTemplate(tableGOForSpell);
                        if (!goInfo)
                        {
                            BotWhisper(LocalizedNpcText(player, BOT_TEXT_INVALID_OBJECT_TYPE), player);
                            break;
                        }
                        float x,y,z;
                        me->GetClosePoint(x, y, z, me->GetCombatReach(), 0.f, 0.f);
                        QuaternionData rot = QuaternionData::fromEulerAnglesZYX(me->GetOrientation(), 0.f, 0.f);

                        GameObject* table = new GameObject;
                        if (!table->Create(me->GetMap()->GenerateLowGuid<HighGuid::GameObject>(), tableGOForSpell, me->GetMap(),
                            me->GetPhaseMask(), Position(x,y,z,me->GetOrientation()), rot, 255, GO_STATE_READY))
                        {
                            delete table;
                            BotWhisper(LocalizedNpcText(player, BOT_TEXT_FAILED), player);
                            break;
                        }

                        SetSpellCooldown(43987, 300000);

                        table->SetRespawnTime(180);
                        //table->SetOwnerGUID(master->GetGUID());
                        master->AddGameObject(table);
                        table->SetSpellId(tableSpellId);
                        me->GetMap()->AddToMap(table);

                        BotWhisper(LocalizedNpcText(player, BOT_TEXT_DONE), player);
                        break;
                    }
                    else if (option == 4) // portal
                    {
                        subMenu = true;

                        if (player->GetTeamId() == TEAM_ALLIANCE)
                        {
                            AddGossipItemFor(player, GOSSIP_ICON_CHAT, LocalizedNpcText(player, BOT_TEXT_STORMWIND), GOSSIP_SENDER_CLASS_ACTION1, GOSSIP_ACTION_INFO_DEF + uint32(PORTAL_STORMWIND));
                            AddGossipItemFor(player, GOSSIP_ICON_CHAT, LocalizedNpcText(player, BOT_TEXT_IRONFORGE), GOSSIP_SENDER_CLASS_ACTION1, GOSSIP_ACTION_INFO_DEF + uint32(PORTAL_IRONFORGE));
                            AddGossipItemFor(player, GOSSIP_ICON_CHAT, LocalizedNpcText(player, BOT_TEXT_DARNASSUS), GOSSIP_SENDER_CLASS_ACTION1, GOSSIP_ACTION_INFO_DEF + uint32(PORTAL_DARNASSUS));
                            AddGossipItemFor(player, GOSSIP_ICON_CHAT, LocalizedNpcText(player, BOT_TEXT_EXORDAR), GOSSIP_SENDER_CLASS_ACTION1, GOSSIP_ACTION_INFO_DEF + uint32(PORTAL_EXODAR));
                            if (me->GetLevel() >= 65)
                                AddGossipItemFor(player, GOSSIP_ICON_CHAT, LocalizedNpcText(player, BOT_TEXT_SHATTRATH), GOSSIP_SENDER_CLASS_ACTION1, GOSSIP_ACTION_INFO_DEF + uint32(PORTAL_SHATTRATH_A));
                        }
                        else
                        {
                            AddGossipItemFor(player, GOSSIP_ICON_CHAT, LocalizedNpcText(player, BOT_TEXT_ORGRIMMAR), GOSSIP_SENDER_CLASS_ACTION1, GOSSIP_ACTION_INFO_DEF + uint32(PORTAL_ORGRIMMAR));
                            AddGossipItemFor(player, GOSSIP_ICON_CHAT, LocalizedNpcText(player, BOT_TEXT_UNDERCITY), GOSSIP_SENDER_CLASS_ACTION1, GOSSIP_ACTION_INFO_DEF + uint32(PORTAL_UNDERCITY));
                            AddGossipItemFor(player, GOSSIP_ICON_CHAT, LocalizedNpcText(player, BOT_TEXT_THUNDER_BLUFF), GOSSIP_SENDER_CLASS_ACTION1, GOSSIP_ACTION_INFO_DEF + uint32(PORTAL_THUNDERBLUFF));
                            AddGossipItemFor(player, GOSSIP_ICON_CHAT, LocalizedNpcText(player, BOT_TEXT_SILVERMOON), GOSSIP_SENDER_CLASS_ACTION1, GOSSIP_ACTION_INFO_DEF + uint32(PORTAL_SILVERMOON));
                            if (me->GetLevel() >= 65)
                                AddGossipItemFor(player, GOSSIP_ICON_CHAT, LocalizedNpcText(player, BOT_TEXT_SHATTRATH), GOSSIP_SENDER_CLASS_ACTION1, GOSSIP_ACTION_INFO_DEF + uint32(PORTAL_SHATTRATH_H));
                        }
                        if (me->GetLevel() >= 74)
                            AddGossipItemFor(player, GOSSIP_ICON_CHAT, LocalizedNpcText(player, BOT_TEXT_DALARAN), GOSSIP_SENDER_CLASS_ACTION1, GOSSIP_ACTION_INFO_DEF + uint32(PORTAL_DALARAN));
                        AddGossipItemFor(player, GOSSIP_ICON_CHAT, LocalizedNpcText(player, BOT_TEXT_BACK), 1, GOSSIP_ACTION_INFO_DEF + 7);
                    }
                    break;
                }
                case BOT_CLASS_ROGUE:
                {
                    action -= GOSSIP_ACTION_INFO_DEF;

                    if (action == 1)
                    {
                        // Pick Lock
                        subMenu = true;

                        uint32 count = 0;
                        uint32 maxcounter = BOT_GOSSIP_MAX_ITEMS - 1; //BACK

                        //1 Nearest gameobject
                        GameObject* obj = nullptr;
                        NearestLockedGameObjectInRangeCheck check(player, 4.f);
                        Trinity::GameObjectLastSearcher<NearestLockedGameObjectInRangeCheck> searcher(player, obj, check);
                        Cell::VisitAllObjects(player, searcher, 4.f);
                        //player->VisitNearbyGridObject(4.f, searcher);
                        if (obj)
                        {
                            std::ostringstream msg;
                            msg << obj->GetGOInfo()->name << " (" << LocalizedNpcText(player, BOT_TEXT_DISTANCE_SHORT) << " = " << player->GetExactDist(obj) << ")";
                            AddGossipItemFor(player, GOSSIP_ICON_CHAT, msg.str().c_str(), GOSSIP_SENDER_CLASS_ACTION1, GOSSIP_ACTION_INFO_DEF + ++count);
                        }

                        //2 Inventory
                        Item* item = nullptr;
                        LockEntry const* lockInfo;

                        //backpack
                        for (uint8 i = INVENTORY_SLOT_ITEM_START; i != INVENTORY_SLOT_ITEM_END; ++i)
                        {
                            item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, i);
                            if (item && item->IsLocked() && item->GetTemplate()->LockID)
                            {
                                lockInfo = sLockStore.LookupEntry(item->GetTemplate()->LockID);
                                if (!lockInfo)
                                    continue;

                                for (uint8 j = 0; j != MAX_LOCK_CASE; ++j)
                                {
                                    if (lockInfo->Type[j] == LOCK_KEY_SKILL && lockInfo->Index[j] == LOCKTYPE_PICKLOCK &&
                                        lockInfo->Skill[j] <= uint32(15 + creature->GetLevel() * 5))
                                    {
                                        std::ostringstream name;
                                        _AddItemLink(player, item, name, false);
                                        AddGossipItemFor(player, GOSSIP_ICON_CHAT, name.str().c_str(), GOSSIP_SENDER_CLASS_ACTION1, GOSSIP_ACTION_INFO_DEF + item->GetGUID().GetCounter());
                                        break;
                                    }
                                }
                            }
                        }
                        //bags
                        for (uint8 i = INVENTORY_SLOT_BAG_START; i != INVENTORY_SLOT_BAG_END; ++i)
                        {
                            if (Bag const* bag = player->GetBagByPos(i))
                            {
                                for (uint32 j = 0; j != bag->GetBagSize() && count <= maxcounter; ++j)
                                {
                                    item = player->GetItemByPos(i, j);
                                    if (item && item->IsLocked() && item->GetTemplate()->LockID)
                                    {
                                        lockInfo = sLockStore.LookupEntry(item->GetTemplate()->LockID);
                                        if (!lockInfo)
                                            continue;

                                        for (uint8 k = 0; k != MAX_LOCK_CASE; ++k)
                                        {
                                            if (lockInfo->Type[k] == LOCK_KEY_SKILL && lockInfo->Index[k] == LOCKTYPE_PICKLOCK &&
                                                lockInfo->Skill[k] <= uint32(15 + creature->GetLevel() * 5))
                                            {
                                                std::ostringstream name;
                                                _AddItemLink(player, item, name, false);
                                                AddGossipItemFor(player, GOSSIP_ICON_CHAT, name.str().c_str(), GOSSIP_SENDER_CLASS_ACTION1, GOSSIP_ACTION_INFO_DEF + item->GetGUID().GetCounter());
                                                ++count;
                                                break;
                                            }
                                        }
                                    }
                                }
                            }
                        }

                        AddGossipItemFor(player, GOSSIP_ICON_CHAT, LocalizedNpcText(player, BOT_TEXT_BACK), 1, GOSSIP_ACTION_INFO_DEF + ++count);
                    }
                    else if (action == 2)
                    {
                        //Clear poisons (autorefresh is in class ai DoNonCombatActions
                        RemoveItemClassEnchantments();
                    }
                    else if (action == 3)
                    {
                        subMenu = true;
                        bool isauto = GetAIMiscValue(BOTAI_MISC_ENCHANT_IS_AUTO_MH);
                        //Send list of available poisons on MH
                        for (uint32 i = BOTAI_MISC_ENCHANT_AVAILABLE_1; i <= BOTAI_MISC_ENCHANT_AVAILABLE_6; ++i)
                        {
                            uint32 possiblePoison = GetAIMiscValue(i);
                            if (uint32 possiblePoisonMaxRank = GetSpell(possiblePoison))
                            {
                                SpellInfo const* availableInfo = sSpellMgr->GetSpellInfo(possiblePoisonMaxRank);
                                uint32 curMHId = GetAIMiscValue(BOTAI_MISC_ENCHANT_CURRENT_MH);
                                bool same = possiblePoison == curMHId;
                                std::string spellName;
                                _LocalizeSpell(player, spellName, availableInfo->Id);
                                AddGossipItemFor(player, same ? GOSSIP_ICON_BATTLE : GOSSIP_ICON_CHAT, spellName, GOSSIP_SENDER_CLASS_ACTION2, GOSSIP_ACTION_INFO_DEF + possiblePoison);
                            }
                        }
                        AddGossipItemFor(player, isauto ? GOSSIP_ICON_BATTLE : GOSSIP_ICON_CHAT, LocalizedNpcText(player, BOT_TEXT_AUTO), GOSSIP_SENDER_CLASS_ACTION2, GOSSIP_ACTION_INFO_DEF + 0);
                        AddGossipItemFor(player, GOSSIP_ICON_CHAT, LocalizedNpcText(player, BOT_TEXT_BACK), 1, GOSSIP_ACTION_INFO_DEF + 1);
                    }
                    else if (action == 4)
                    {
                        subMenu = true;
                        bool isauto = GetAIMiscValue(BOTAI_MISC_ENCHANT_IS_AUTO_OH);
                        //Send list of available poisons on OH
                        for (uint32 i = BOTAI_MISC_ENCHANT_AVAILABLE_1; i <= BOTAI_MISC_ENCHANT_AVAILABLE_6; ++i)
                        {
                            uint32 possiblePoison = GetAIMiscValue(i);
                            if (uint32 possiblePoisonMaxRank = GetSpell(possiblePoison))
                            {
                                SpellInfo const* availableInfo = sSpellMgr->GetSpellInfo(possiblePoisonMaxRank);
                                uint32 curOHId = GetAIMiscValue(BOTAI_MISC_ENCHANT_CURRENT_OH);
                                bool same = possiblePoison == curOHId;
                                std::string spellName;
                                _LocalizeSpell(player, spellName, availableInfo->Id);
                                AddGossipItemFor(player, same ? GOSSIP_ICON_BATTLE : GOSSIP_ICON_CHAT, spellName, GOSSIP_SENDER_CLASS_ACTION3, GOSSIP_ACTION_INFO_DEF + possiblePoison);
                            }
                        }
                        AddGossipItemFor(player, isauto ? GOSSIP_ICON_BATTLE : GOSSIP_ICON_CHAT, LocalizedNpcText(player, BOT_TEXT_AUTO), GOSSIP_SENDER_CLASS_ACTION3, GOSSIP_ACTION_INFO_DEF + 0);
                        AddGossipItemFor(player, GOSSIP_ICON_CHAT, LocalizedNpcText(player, BOT_TEXT_BACK), 1, GOSSIP_ACTION_INFO_DEF + 1);
                    }

                    break;
                }
                case BOT_CLASS_SHAMAN:
                {
                    action -= GOSSIP_ACTION_INFO_DEF;

                    if (action == 2)
                    {
                        //Clear enchants (autorefresh is in class ai DoNonCombatActions
                        RemoveItemClassEnchantments();
                    }
                    else if (action == 3)
                    {
                        subMenu = true;
                        bool isauto = GetAIMiscValue(BOTAI_MISC_ENCHANT_IS_AUTO_MH);
                        //Send list of available enchants on MH
                        for (uint32 i = BOTAI_MISC_ENCHANT_AVAILABLE_1; i <= BOTAI_MISC_ENCHANT_AVAILABLE_5; ++i)
                        {
                            uint32 possibleEnchant = GetAIMiscValue(i);
                            if (uint32 possibleEcnhantMaxRank = GetSpell(possibleEnchant))
                            {
                                SpellInfo const* availableInfo = sSpellMgr->GetSpellInfo(possibleEcnhantMaxRank);
                                uint32 curMHId = GetAIMiscValue(BOTAI_MISC_ENCHANT_CURRENT_MH);
                                bool same = possibleEnchant == curMHId;
                                std::string spellName;
                                _LocalizeSpell(player, spellName, availableInfo->Id);
                                AddGossipItemFor(player, same ? GOSSIP_ICON_BATTLE : GOSSIP_ICON_CHAT, spellName, GOSSIP_SENDER_CLASS_ACTION2, GOSSIP_ACTION_INFO_DEF + possibleEnchant);
                            }
                        }
                        AddGossipItemFor(player, isauto ? GOSSIP_ICON_BATTLE : GOSSIP_ICON_CHAT, LocalizedNpcText(player, BOT_TEXT_AUTO), GOSSIP_SENDER_CLASS_ACTION2, GOSSIP_ACTION_INFO_DEF + 0);
                        AddGossipItemFor(player, GOSSIP_ICON_CHAT, LocalizedNpcText(player, BOT_TEXT_BACK), 1, GOSSIP_ACTION_INFO_DEF + 1);
                    }
                    else if (action == 4)
                    {
                        subMenu = true;
                        bool isauto = GetAIMiscValue(BOTAI_MISC_ENCHANT_IS_AUTO_OH);
                        //Send list of available enchants on OH
                        for (uint32 i = BOTAI_MISC_ENCHANT_AVAILABLE_1; i <= BOTAI_MISC_ENCHANT_AVAILABLE_5; ++i)
                        {
                            uint32 possibleEnchant = GetAIMiscValue(i);
                            if (uint32 possibleEcnhantMaxRank = GetSpell(possibleEnchant))
                            {
                                SpellInfo const* availableInfo = sSpellMgr->GetSpellInfo(possibleEcnhantMaxRank);
                                uint32 curOHId = GetAIMiscValue(BOTAI_MISC_ENCHANT_CURRENT_OH);
                                bool same = possibleEnchant == curOHId;
                                std::string spellName;
                                _LocalizeSpell(player, spellName, availableInfo->Id);
                                AddGossipItemFor(player, same ? GOSSIP_ICON_BATTLE : GOSSIP_ICON_CHAT, spellName, GOSSIP_SENDER_CLASS_ACTION3, GOSSIP_ACTION_INFO_DEF + possibleEnchant);
                            }
                        }
                        AddGossipItemFor(player, isauto ? GOSSIP_ICON_BATTLE : GOSSIP_ICON_CHAT, LocalizedNpcText(player, BOT_TEXT_AUTO), GOSSIP_SENDER_CLASS_ACTION3, GOSSIP_ACTION_INFO_DEF + 0);
                        AddGossipItemFor(player, GOSSIP_ICON_CHAT, LocalizedNpcText(player, BOT_TEXT_BACK), 1, GOSSIP_ACTION_INFO_DEF + 1);
                    }
                    else if (action == 5)
                    {
                        if (me->GetShapeshiftForm() == FORM_NONE)
                        {
                            BotWhisper(LocalizedNpcText(player, BOT_TEXT_NOT_SHAPESHIFTED), player);
                            break;
                        }
                        removeShapeshiftForm();
                    }

                    break;
                }
                case BOT_CLASS_HUNTER:
                {
                    if (IsCasting())
                    {
                        player->SendEquipError(EQUIP_ERR_OBJECT_IS_BUSY, nullptr);
                        break;
                    }

                    action -= GOSSIP_ACTION_INFO_DEF;

                    if (action == 2)
                    {
                        subMenu = true;
                        uint32 curType = GetAIMiscValue(BOTAI_MISC_PET_TYPE);
                        for (uint32 i = BOTAI_MISC_PET_AVAILABLE_1; i <= BOTAI_MISC_PET_AVAILABLE_11; ++i)
                        {
                            if (uint32 possibleType = GetAIMiscValue(i))
                            {
                                std::string name;
                                if (possibleType == BOT_PET_CUNNING_START)
                                {
                                    name = LocalizedNpcText(player, BOT_TEXT_RANDOMPET_CUNNING);
                                    possibleType = urand(BOT_PET_CUNNING_START, BOT_PET_CUNNING_END);
                                }
                                else if (possibleType == BOT_PET_FEROCITY_START)
                                {
                                    name = LocalizedNpcText(player, BOT_TEXT_RANDOMPET_FEROCITY);
                                    possibleType = urand(BOT_PET_FEROCITY_START, BOT_PET_FEROCITY_END);
                                }
                                else if (possibleType == BOT_PET_TENACITY_START)
                                {
                                    name = LocalizedNpcText(player, BOT_TEXT_RANDOMPET_TENACITY);
                                    possibleType = urand(BOT_PET_TENACITY_START, BOT_PET_TENACITY_END);
                                }
                                else
                                {
                                    CreatureTemplate const* cinfo = sObjectMgr->GetCreatureTemplate(possibleType);
                                    ASSERT(cinfo);
                                    name = cinfo->Name;
                                }
                                bool same = possibleType == curType;
                                AddGossipItemFor(player, same ? GOSSIP_ICON_BATTLE : GOSSIP_ICON_CHAT, name.c_str(), GOSSIP_SENDER_CLASS_ACTION4, GOSSIP_ACTION_INFO_DEF + possibleType);
                            }
                        }
                        bool noPet = curType == BOT_PET_INVALID;
                        AddGossipItemFor(player, noPet ? GOSSIP_ICON_BATTLE : GOSSIP_ICON_CHAT, LocalizedNpcText(player, BOT_TEXT_NONE2), GOSSIP_SENDER_CLASS_ACTION4, GOSSIP_ACTION_INFO_DEF + uint32(BOT_PET_INVALID));
                        AddGossipItemFor(player, GOSSIP_ICON_CHAT, LocalizedNpcText(player, BOT_TEXT_AUTO), GOSSIP_SENDER_CLASS_ACTION4, GOSSIP_ACTION_INFO_DEF + 0);
                        AddGossipItemFor(player, GOSSIP_ICON_CHAT, LocalizedNpcText(player, BOT_TEXT_BACK), 1, GOSSIP_ACTION_INFO_DEF + 1);
                    }
                    break;
                }
                case BOT_CLASS_WARLOCK:
                {
                    if (IsCasting())
                    {
                        player->SendEquipError(EQUIP_ERR_OBJECT_IS_BUSY, nullptr);
                        break;
                    }

                    action -= GOSSIP_ACTION_INFO_DEF;

                    if (action == 2)
                    {
                        subMenu = true;
                        uint32 curType = GetAIMiscValue(BOTAI_MISC_PET_TYPE);
                        for (uint32 i = BOTAI_MISC_PET_AVAILABLE_1; i <= BOTAI_MISC_PET_AVAILABLE_5; ++i)
                        {
                            if (uint32 possibleType = GetAIMiscValue(i))
                            {
                                CreatureTemplate const* cinfo = sObjectMgr->GetCreatureTemplate(possibleType);
                                ASSERT(cinfo);
                                bool same = possibleType == curType;
                                AddGossipItemFor(player, same ? GOSSIP_ICON_BATTLE : GOSSIP_ICON_CHAT, cinfo->Name.c_str(), GOSSIP_SENDER_CLASS_ACTION4, GOSSIP_ACTION_INFO_DEF + possibleType);
                            }
                        }
                        bool noPet = curType == BOT_PET_INVALID;
                        AddGossipItemFor(player, noPet ? GOSSIP_ICON_BATTLE : GOSSIP_ICON_CHAT, LocalizedNpcText(player, BOT_TEXT_NONE2), GOSSIP_SENDER_CLASS_ACTION4, GOSSIP_ACTION_INFO_DEF + uint32(BOT_PET_INVALID));
                        AddGossipItemFor(player, GOSSIP_ICON_CHAT, LocalizedNpcText(player, BOT_TEXT_AUTO), GOSSIP_SENDER_CLASS_ACTION4, GOSSIP_ACTION_INFO_DEF + 0);
                        AddGossipItemFor(player, GOSSIP_ICON_CHAT, LocalizedNpcText(player, BOT_TEXT_BACK), 1, GOSSIP_ACTION_INFO_DEF + 1);
                    }
                    else if (action == 1)
                    {
                        if (GetAIMiscValue(6201) == 0)
                        {
                            BotWhisper(LocalizedNpcText(player, BOT_TEXT_NO_HEALTHSTONE), player);
                            break;
                        }

                        //Prevent high-leveled healthstone for low-level characters
                        Unit* checker;
                        if (player->GetLevel() < me->GetLevel())
                            checker = player;
                        else
                            checker = me;

                        static uint32 HealthStones[8] = { 19005,19007,19009,19011,19013,22105,36891,36894 };
                        uint32 spellId = InitSpell(me, 6201); //Create Healthstone Rank 1
                        SpellInfo const* spellInfo = spellId ? sSpellMgr->GetSpellInfo(spellId) : nullptr;
                        if (!spellInfo)
                        {
                            BotWhisper(LocalizedNpcText(player, BOT_TEXT_CANT_CREATE_HEALTHSTONE), player);
                            break;
                        }

                        int8 i = spellInfo->GetRank() - 1;
                        for (; i != 0; --i)
                            if (ItemTemplate const* stone = sObjectMgr->GetItemTemplate(HealthStones[i]))
                                if (stone->RequiredLevel <= checker->GetLevel())
                                    break;

                        //at least rank 1 (even if player is level 1)
                        ItemPosCountVec dest;
                        InventoryResult msg = player->CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, HealthStones[i], 1);
                        if (msg != EQUIP_ERR_OK)
                        {
                            player->SendEquipError(msg, nullptr, nullptr, HealthStones[i]);
                            break;
                        }
                        Item* item = player->StoreNewItem(dest, HealthStones[i], true, 0);
                        if (!item)
                        {
                            player->SendEquipError(EQUIP_ERR_ITEM_NOT_FOUND, nullptr, nullptr);
                            break;
                        }

                        //remove healthstone
                        SetAIMiscValue(6201, 0);

                        player->SendNewItem(item, 1, true, false, true);
                    }
                    else if (action == 3) //soulwell
                    {
                        uint32 wellSpellId = GetSpell(29893); //Ritual of Souls
                        if (!wellSpellId)
                        {
                            BotWhisper(LocalizedNpcText(player, BOT_TEXT_DISABLED), player);
                            break;
                        }
                        if (!IsSpellReady(29893, GetLastDiff(), false))
                        {
                            BotWhisper(LocalizedNpcText(player, BOT_TEXT_NOT_READY_YET), player);
                            break;
                        }
                        uint32 wellGOForSpell = (wellSpellId == 29893 ? GO_SOULWELL_1 : GO_SOULWELL_2);
                        GameObjectTemplate const* goInfo = sObjectMgr->GetGameObjectTemplate(wellGOForSpell);
                        if (!goInfo)
                        {
                            BotWhisper(LocalizedNpcText(player, BOT_TEXT_INVALID_OBJECT_TYPE), player);
                            break;
                        }
                        float x,y,z;
                        me->GetClosePoint(x, y, z, me->GetCombatReach(), 0.f, 0.f);
                        QuaternionData rot = QuaternionData::fromEulerAnglesZYX(me->GetOrientation(), 0.f, 0.f);

                        GameObject* soulwell = new GameObject;
                        if (!soulwell->Create(me->GetMap()->GenerateLowGuid<HighGuid::GameObject>(), wellGOForSpell, me->GetMap(),
                            me->GetPhaseMask(), Position(x,y,z,me->GetOrientation()), rot, 255, GO_STATE_READY))
                        {
                            delete soulwell;
                            BotWhisper(LocalizedNpcText(player, BOT_TEXT_FAILED), player);
                            break;
                        }

                        SetSpellCooldown(29893, 300000);

                        soulwell->SetRespawnTime(180);
                        //soulwell->SetOwnerGUID(master->GetGUID());
                        master->AddGameObject(soulwell);
                        soulwell->SetSpellId(wellSpellId);
                        me->GetMap()->AddToMap(soulwell);

                        BotWhisper(LocalizedNpcText(player, BOT_TEXT_DONE), player);
                        break;
                    }
                    break;
                }
                case BOT_CLASS_DRUID:
                {
                    if (IsCasting())
                    {
                        player->SendEquipError(EQUIP_ERR_OBJECT_IS_BUSY, nullptr);
                        break;
                    }
                    if (me->GetShapeshiftForm() == FORM_NONE)
                    {
                        BotWhisper(LocalizedNpcText(player, BOT_TEXT_NOT_SHAPESHIFTED), player);
                        break;
                    }

                    removeShapeshiftForm();
                    break;
                }

                default:
                    break;
            }
            break;
        }
        case GOSSIP_SENDER_CLASS_ACTION1:
        {
            switch (_botclass)
            {
                case BOT_CLASS_MAGE:
                {
                    if (!IsCasting())
                    {
                        uint32 portal_spell_id = action - GOSSIP_ACTION_INFO_DEF;
                        if (!portal_spell_id)
                            break;

                        if (!IsSpellReady(portal_spell_id, lastdiff, false))
                        {
                            BotWhisper(LocalizedNpcText(player, BOT_TEXT_NOT_READY_YET), player);
                            return OnGossipSelect(player, creature, GOSSIP_SENDER_CLASS, GOSSIP_ACTION_INFO_DEF + 4);
                        }

                        CastSpellExtraArgs args;
                        args.SetOriginalCaster(player->GetGUID());
                        me->CastSpell(me, portal_spell_id, args);
                    }
                    break;
                }
                case BOT_CLASS_ROGUE:
                {
                    if (!IsCasting())
                    {
                        // Pick Lock
                        uint32 picklock = InitSpell(me, 1804);
                        if (!picklock)
                        {
                            BotWhisper(LocalizedNpcText(player, BOT_TEXT_NO_LOCKPICKING), player);
                            break;
                        }

                        SpellInfo const* Info = sSpellMgr->GetSpellInfo(picklock);
                        Spell* lockpickspell = new Spell(player, Info, TRIGGERED_NONE, me->GetGUID());
                        SpellCastTargets targets;

                        if (action == GOSSIP_ACTION_INFO_DEF + 1)
                        {
                            //1 Nearest gameobject
                            GameObject* obj = nullptr;
                            NearestLockedGameObjectInRangeCheck check(player, 4.f);
                            Trinity::GameObjectLastSearcher<NearestLockedGameObjectInRangeCheck> searcher(player, obj, check);
                            Cell::VisitAllObjects(player, searcher, 4.f);
                            //player->VisitNearbyGridObject(4.f, searcher);
                            if (obj)
                            {
                                targets.SetGOTarget(obj);
                                lockpickspell->m_targets.SetGOTarget(obj); //for checkCast only
                            }
                        }
                        else
                        {
                            //2 Inventory
                            Item* item = nullptr;
                            uint32 guidLow = action - GOSSIP_ACTION_INFO_DEF;

                            bool found = false;
                            //backpack
                            for (uint8 i = INVENTORY_SLOT_ITEM_START; i != INVENTORY_SLOT_ITEM_END; ++i)
                            {
                                item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, i);
                                if (item && item->GetGUID().GetCounter() == guidLow)
                                {
                                    targets.SetItemTarget(item);
                                    lockpickspell->m_targets.SetItemTarget(item); //for checkCast only
                                    found = true;
                                    break;
                                }
                            }
                            //bags
                            if (!found)
                            {
                                for (uint8 i = INVENTORY_SLOT_BAG_START; i != INVENTORY_SLOT_BAG_END; ++i)
                                {
                                    if (Bag const* bag = player->GetBagByPos(i))
                                    {
                                        for (uint32 j = 0; j != bag->GetBagSize(); ++j)
                                        {
                                            item = player->GetItemByPos(i, j);
                                            if (item && item->GetGUID().GetCounter() == guidLow)
                                            {
                                                targets.SetItemTarget(item);
                                                lockpickspell->m_targets.SetItemTarget(item); //for checkCast only
                                                found = true;
                                                break;
                                            }
                                        }
                                    }

                                    if (found)
                                        break;
                                }
                            }
                        }

                        SpellCastResult result = me->IsMounted() || CCed(me) ? SPELL_FAILED_CUSTOM_ERROR : lockpickspell->CheckCast(false);
                        if (result != SPELL_CAST_OK)
                        {
                            lockpickspell->finish(false);
                            delete lockpickspell;
                            if (result == SPELL_FAILED_LOW_CASTLEVEL)
                                BotWhisper(LocalizedNpcText(player, BOT_TEXT_SKILL_LEVEL_TOO_LOW), player);
                            else
                                BotWhisper(LocalizedNpcText(player, BOT_TEXT_FAILED), player);
                        }
                        else
                        {
                            lockpickspell->prepare(targets);
                            //BotWhisper("Here...", player);
                        }
                    }
                    return OnGossipSelect(player, creature, GOSSIP_SENDER_CLASS, GOSSIP_ACTION_INFO_DEF + 1);
                    //break;
                }
                default:
                    break;
            }
            break;
        }
        case GOSSIP_SENDER_CLASS_ACTION2: //set cur MH enchant
        {
            switch (_botclass)
            {
                case BOT_CLASS_ROGUE:
                {
                    uint32 baseId = action - GOSSIP_ACTION_INFO_DEF;
                    SetAIMiscValue(BOTAI_MISC_ENCHANT_CURRENT_MH, baseId);
                    break;
                }
                case BOT_CLASS_SHAMAN:
                {
                    uint32 baseId = action - GOSSIP_ACTION_INFO_DEF;
                    SetAIMiscValue(BOTAI_MISC_ENCHANT_CURRENT_MH, baseId);
                    break;
                }
            }
            return OnGossipHello(player, 0);
        }
        case GOSSIP_SENDER_CLASS_ACTION3: //set cur OH enchant
        {
            switch (_botclass)
            {
                case BOT_CLASS_ROGUE:
                {
                    uint32 baseId = action - GOSSIP_ACTION_INFO_DEF;
                    SetAIMiscValue(BOTAI_MISC_ENCHANT_CURRENT_OH, baseId);
                    break;
                }
                case BOT_CLASS_SHAMAN:
                {
                    uint32 baseId = action - GOSSIP_ACTION_INFO_DEF;
                    SetAIMiscValue(BOTAI_MISC_ENCHANT_CURRENT_OH, baseId);
                    break;
                }
            }
            return OnGossipHello(player, 0);
        }
        case GOSSIP_SENDER_CLASS_ACTION4: //set pet type
        {
            switch (_botclass)
            {
                case BOT_CLASS_HUNTER:
                {
                    uint32 petType = action - GOSSIP_ACTION_INFO_DEF;
                    SetAIMiscValue(BOTAI_MISC_PET_TYPE, petType);
                    break;
                }
                case BOT_CLASS_WARLOCK:
                {
                    uint32 petType = action - GOSSIP_ACTION_INFO_DEF;
                    SetAIMiscValue(BOTAI_MISC_PET_TYPE, petType);
                    break;
                }
            }
            return OnGossipHello(player, 0);
        }
        case GOSSIP_SENDER_MODEL_UPDATE:
        {
            if (Aura* trans = me->AddAura(MODEL_TRANSITION, me))
            {
                me->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID + uint32(BOT_SLOT_OFFHAND), 0); //debug: remove offhand visuals
                trans->SetDuration(500);
                trans->SetMaxDuration(500);
            }
            break;
        }
        case GOSSIP_SENDER_EQUIPMENT: //equips change s1: send what slots we can use
        {
            subMenu = true;

            //general
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, LocalizedNpcText(player, BOT_TEXT_SHOW_INVENTORY), GOSSIP_SENDER_EQUIPMENT_LIST, GOSSIP_ACTION_INFO_DEF + 1);
            if (BotMgr::IsGearBankEnabled())
                AddGossipItemFor(player, GOSSIP_ICON_TALK, LocalizedNpcText(player, BOT_TEXT_BOT_GEAR_BANK), GOSSIP_SENDER_EQUIPMENT_BANK_MENU, GOSSIP_ACTION_INFO_DEF + 1);

            //auto-equip
            AddGossipItemFor(player, GOSSIP_ICON_TALK, LocalizedNpcText(player, BOT_TEXT_AUTOEQUIP) + "...", GOSSIP_SENDER_EQUIP_AUTOEQUIP, GOSSIP_ACTION_INFO_DEF + 1);

            //weapons
            AddGossipItemFor(player, GOSSIP_ICON_TALK, LocalizedNpcText(player, BOT_TEXT_SLOT_MH) + "...", GOSSIP_SENDER_EQUIPMENT_SHOW, GOSSIP_ACTION_INFO_DEF + uint32(BOT_SLOT_MAINHAND));
            if (_canUseOffHand())
                AddGossipItemFor(player, GOSSIP_ICON_TALK, LocalizedNpcText(player, BOT_TEXT_SLOT_OH) + "...", GOSSIP_SENDER_EQUIPMENT_SHOW, GOSSIP_ACTION_INFO_DEF + uint32(BOT_SLOT_OFFHAND));
            if (_canUseRanged())
                AddGossipItemFor(player, GOSSIP_ICON_TALK, LocalizedNpcText(player, BOT_TEXT_SLOT_RH) + "...", GOSSIP_SENDER_EQUIPMENT_SHOW, GOSSIP_ACTION_INFO_DEF + uint32(BOT_SLOT_RANGED));
            if (_canUseRelic())
                AddGossipItemFor(player, GOSSIP_ICON_TALK, LocalizedNpcText(player, BOT_TEXT_SLOT_RELIC) + "...", GOSSIP_SENDER_EQUIPMENT_SHOW, GOSSIP_ACTION_INFO_DEF + uint32(BOT_SLOT_RANGED));

            //armor
            AddGossipItemFor(player, GOSSIP_ICON_TALK, LocalizedNpcText(player, BOT_TEXT_SLOT_HEAD) + "...", GOSSIP_SENDER_EQUIPMENT_SHOW, GOSSIP_ACTION_INFO_DEF + uint32(BOT_SLOT_HEAD));
            AddGossipItemFor(player, GOSSIP_ICON_TALK, LocalizedNpcText(player, BOT_TEXT_SLOT_SHOULDERS) + "...", GOSSIP_SENDER_EQUIPMENT_SHOW, GOSSIP_ACTION_INFO_DEF + uint32(BOT_SLOT_SHOULDERS));
            AddGossipItemFor(player, GOSSIP_ICON_TALK, LocalizedNpcText(player, BOT_TEXT_SLOT_CHEST) + "...", GOSSIP_SENDER_EQUIPMENT_SHOW, GOSSIP_ACTION_INFO_DEF + uint32(BOT_SLOT_CHEST));
            AddGossipItemFor(player, GOSSIP_ICON_TALK, LocalizedNpcText(player, BOT_TEXT_SLOT_WAIST) + "...", GOSSIP_SENDER_EQUIPMENT_SHOW, GOSSIP_ACTION_INFO_DEF + uint32(BOT_SLOT_WAIST));
            AddGossipItemFor(player, GOSSIP_ICON_TALK, LocalizedNpcText(player, BOT_TEXT_SLOT_LEGS) + "...", GOSSIP_SENDER_EQUIPMENT_SHOW, GOSSIP_ACTION_INFO_DEF + uint32(BOT_SLOT_LEGS));
            AddGossipItemFor(player, GOSSIP_ICON_TALK, LocalizedNpcText(player, BOT_TEXT_SLOT_FEET) + "...", GOSSIP_SENDER_EQUIPMENT_SHOW, GOSSIP_ACTION_INFO_DEF + uint32(BOT_SLOT_FEET));
            AddGossipItemFor(player, GOSSIP_ICON_TALK, LocalizedNpcText(player, BOT_TEXT_SLOT_WRIST) + "...", GOSSIP_SENDER_EQUIPMENT_SHOW, GOSSIP_ACTION_INFO_DEF + uint32(BOT_SLOT_WRIST));
            AddGossipItemFor(player, GOSSIP_ICON_TALK, LocalizedNpcText(player, BOT_TEXT_SLOT_HANDS) + "...", GOSSIP_SENDER_EQUIPMENT_SHOW, GOSSIP_ACTION_INFO_DEF + uint32(BOT_SLOT_HANDS));

            if (IsHumanoidClass(_botclass))
            {
                AddGossipItemFor(player, GOSSIP_ICON_TALK, LocalizedNpcText(player, BOT_TEXT_SLOT_BACK) + "...", GOSSIP_SENDER_EQUIPMENT_SHOW, GOSSIP_ACTION_INFO_DEF + uint32(BOT_SLOT_BACK));
                AddGossipItemFor(player, GOSSIP_ICON_TALK, LocalizedNpcText(player, BOT_TEXT_SLOT_SHIRT) + "...", GOSSIP_SENDER_EQUIPMENT_SHOW, GOSSIP_ACTION_INFO_DEF + uint32(BOT_SLOT_BODY));
                AddGossipItemFor(player, GOSSIP_ICON_TALK, LocalizedNpcText(player, BOT_TEXT_SLOT_FINGER1) + "...", GOSSIP_SENDER_EQUIPMENT_SHOW, GOSSIP_ACTION_INFO_DEF + uint32(BOT_SLOT_FINGER1));
                AddGossipItemFor(player, GOSSIP_ICON_TALK, LocalizedNpcText(player, BOT_TEXT_SLOT_FINGER2) + "...", GOSSIP_SENDER_EQUIPMENT_SHOW, GOSSIP_ACTION_INFO_DEF + uint32(BOT_SLOT_FINGER2));
                AddGossipItemFor(player, GOSSIP_ICON_TALK, LocalizedNpcText(player, BOT_TEXT_SLOT_TRINKET1) + "...", GOSSIP_SENDER_EQUIPMENT_SHOW, GOSSIP_ACTION_INFO_DEF + uint32(BOT_SLOT_TRINKET1));
                AddGossipItemFor(player, GOSSIP_ICON_TALK, LocalizedNpcText(player, BOT_TEXT_SLOT_TRINKET2) + "...", GOSSIP_SENDER_EQUIPMENT_SHOW, GOSSIP_ACTION_INFO_DEF + uint32(BOT_SLOT_TRINKET2));
                AddGossipItemFor(player, GOSSIP_ICON_TALK, LocalizedNpcText(player, BOT_TEXT_SLOT_NECK) + "...", GOSSIP_SENDER_EQUIPMENT_SHOW, GOSSIP_ACTION_INFO_DEF + uint32(BOT_SLOT_NECK));
            }

            AddGossipItemFor(player, GOSSIP_ICON_CHAT, LocalizedNpcText(player, BOT_TEXT_UNEQUIP_ALL), GOSSIP_SENDER_UNEQUIP_ALL, GOSSIP_ACTION_INFO_DEF + 1, LocalizedNpcText(player, BOT_TEXT_UNEQUIP_ALL) + "?", 0, false);
            if (creature->GetCreatureTemplate()->unit_flags2 & UNIT_FLAG2_MIRROR_IMAGE)
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, LocalizedNpcText(player, BOT_TEXT_UPDATE_VISUAL), GOSSIP_SENDER_MODEL_UPDATE, GOSSIP_ACTION_INFO_DEF + 1);
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, LocalizedNpcText(player, BOT_TEXT_BACK), 1, GOSSIP_ACTION_INFO_DEF + 1);

            break;
        }
        case GOSSIP_SENDER_EQUIPMENT_LIST: //list inventory
        {
            //if (action - GOSSIP_ACTION_INFO_DEF != BOT_SLOT_NONE)
            //    break;

            EquipmentInfo const* einfo = BotDataMgr::GetBotEquipmentInfo(me->GetEntry());
            ASSERT(einfo, "Trying to send equipment list for bot with no equip info!");

            for (uint8 i = BOT_SLOT_MAINHAND; i != BOT_INVENTORY_SIZE; ++i)
            {
                Item const* item = _equips[i];
                if (!item) continue;
                std::ostringstream msg;
                _AddItemLink(player, item, msg/*, false*/);
                //uncomment if needed
                //msg << " in slot " << uint32(i) << " (" << _getNameForSlot(i + 1) << ')';
                if (i <= BOT_SLOT_RANGED && einfo->ItemEntry[i] == item->GetEntry())
                    msg << " |cffe6cc80|h[!" << LocalizedNpcText(player, BOT_TEXT_VISUALONLY) << "!]|h|r";
                BotWhisper(msg.str(), player);
            }

            std::ostringstream msg2;
            msg2 << "GS: " << uint32(GetBotGearScores().first);
            BotWhisper(msg2.str(), player);

            break;
        }
        case GOSSIP_SENDER_EQUIP_TRANSMOGRIFY_MHAND:     //0 - 1 main hand
        case GOSSIP_SENDER_EQUIP_TRANSMOGRIFY_OHAND:     //1 - 1 off hand
        case GOSSIP_SENDER_EQUIP_TRANSMOGRIFY_RANGED:    //2 - 1 ranged
        case GOSSIP_SENDER_EQUIP_TRANSMOGRIFY_HEAD:      //3 - 1 head
        case GOSSIP_SENDER_EQUIP_TRANSMOGRIFY_SHOULDERS: //4 - 1 shoulders
        case GOSSIP_SENDER_EQUIP_TRANSMOGRIFY_CHEST:     //5 - 1 chest
        case GOSSIP_SENDER_EQUIP_TRANSMOGRIFY_WAIST:     //6 - 1 waist
        case GOSSIP_SENDER_EQUIP_TRANSMOGRIFY_LEGS:      //7 - 1 legs
        case GOSSIP_SENDER_EQUIP_TRANSMOGRIFY_FEET:      //8 - 1 feet
        case GOSSIP_SENDER_EQUIP_TRANSMOGRIFY_WRIST:     //9 - 1 wrist
        case GOSSIP_SENDER_EQUIP_TRANSMOGRIFY_HANDS:     //10 - 1 hands
        case GOSSIP_SENDER_EQUIP_TRANSMOGRIFY_BACK:      //11 - 1 back
        case GOSSIP_SENDER_EQUIP_TRANSMOGRIFY_BODY:      //12 - 1 body
        {
            uint8 slot = sender - GOSSIP_SENDER_EQUIP_TRANSMOGRIFY;
            int32 itemId = (action == std::numeric_limits<uint32>::max()) ? -1 : int32(action);
            uint32 itemId_u = uint32(std::max<int32>(itemId, 0));

            Item const* item = _equips[slot];
            ASSERT(item);

            BotDataMgr::UpdateNpcBotTransmogData(me->GetEntry(), slot, item->GetEntry(), itemId);

            if (slot <= BOT_SLOT_RANGED)
                me->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID + slot, itemId_u ? itemId_u : item->GetEntry());

            return OnGossipSelect(player, creature, GOSSIP_SENDER_EQUIPMENT, GOSSIP_ACTION_INFO_DEF + 1);
        }
        case GOSSIP_SENDER_EQUIP_TRANSMOG_INFO:
        {
            uint8 slot = action - GOSSIP_ACTION_INFO_DEF;

            NpcBotTransmogData const* tramsmogData = BotDataMgr::SelectNpcBotTransmogs(me->GetEntry());
            ASSERT(tramsmogData);
            ASSERT(tramsmogData->transmogs[slot].second >= 0);

            uint32 item_id = uint32(tramsmogData->transmogs[slot].second);
            ItemTemplate const* proto = item_id ? sObjectMgr->GetItemTemplate(item_id) : nullptr;
            if (proto)
            {
                std::ostringstream msg;
                _AddItemTemplateLink(player, proto, msg);

                BotWhisper(msg.str(), player);
            }

            //break; //no break here - return to menu
        }
        [[fallthrough]];
        case GOSSIP_SENDER_EQUIP_TRANSMOGS:
        {
            subMenu = true;

            uint8 slot = action - GOSSIP_ACTION_INFO_DEF;
            Item const* item = _equips[slot];
            ASSERT(item);

            std::set<uint32> itemList, idsList;

            //s5.1: build list
            //s5.1.1: backpack
            for (uint8 i = INVENTORY_SLOT_ITEM_START; i != INVENTORY_SLOT_ITEM_END; ++i)
            {
                if (Item const* pItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, i))
                {
                    if (IsValidTransmog(slot, pItem->GetTemplate()) && idsList.find(pItem->GetEntry()) == idsList.end())
                    {
                        itemList.insert(pItem->GetGUID().GetCounter());
                        idsList.insert(pItem->GetEntry());
                    }
                }
            }

            //s5.1.2: other bags
            for (uint8 i = INVENTORY_SLOT_BAG_START; i != INVENTORY_SLOT_BAG_END; ++i)
            {
                if (Bag const* pBag = player->GetBagByPos(i))
                {
                    for (uint32 j = 0; j != pBag->GetBagSize(); ++j)
                    {
                        if (Item const* pItem = player->GetItemByPos(i, j))
                        {
                            if (IsValidTransmog(slot, pItem->GetTemplate()) && idsList.find(pItem->GetEntry()) == idsList.end())
                            {
                                itemList.insert(pItem->GetGUID().GetCounter());
                                idsList.insert(pItem->GetEntry());
                            }
                        }
                    }
                }
            }

            //s5.1.3: inventory
            for (uint8 i = EQUIPMENT_SLOT_START; i != EQUIPMENT_SLOT_END; ++i)
            {
                if (Item const* pItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, i))
                {
                    if (IsValidTransmog(slot, pItem->GetTemplate()) && idsList.find(pItem->GetEntry()) == idsList.end())
                    {
                        itemList.insert(pItem->GetGUID().GetCounter());
                        idsList.insert(pItem->GetEntry());
                    }
                }
            }

            //s5.2: add gossips
            NpcBotTransmogData const* tramsmogData = BotDataMgr::SelectNpcBotTransmogs(me->GetEntry());
            if (tramsmogData && tramsmogData->transmogs[slot].first)
            {
                int32 item_id = tramsmogData->transmogs[slot].second;
                if (item_id >= 0)
                {
                    //s5.2.1.1: current
                    std::ostringstream msg;
                    if (item_id == 0)
                        msg << LocalizedNpcText(player, BOT_TEXT_HIDDEN);
                    else if (ItemTemplate const* proto = sObjectMgr->GetItemTemplate(uint32(item_id)))
                        _AddItemTemplateLink(player, proto, msg);
                    else
                        msg << '<' << LocalizedNpcText(player, BOT_TEXT_UNKNOWN) << "(" << item_id << ")>";

                    AddGossipItemFor(player, GOSSIP_ICON_BATTLE, msg.str(), GOSSIP_SENDER_EQUIP_TRANSMOG_INFO, GOSSIP_ACTION_INFO_DEF + slot);

                    //s5.2.1.2a: reset
                    AddGossipItemFor(player, GOSSIP_ICON_CHAT, LocalizedNpcText(player, BOT_TEXT_NONE), GOSSIP_SENDER_EQUIP_TRANSMOGRIFY + slot, std::numeric_limits<uint32>::max());
                }
                else
                {
                    //s5.2.1.2b: None
                    AddGossipItemFor(player, GOSSIP_ICON_BATTLE, LocalizedNpcText(player, BOT_TEXT_NONE), GOSSIP_SENDER_EQUIP_TRANSMOGS, action);
                }
            }

            //s5.2.1.2c: hide
            if (slot > BOT_SLOT_RANGED &&
                !(tramsmogData && tramsmogData->transmogs[slot].first && tramsmogData->transmogs[slot].second == 0))
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, LocalizedNpcText(player, BOT_TEXT_HIDDEN), GOSSIP_SENDER_EQUIP_TRANSMOGRIFY + slot, 0);

            if (!itemList.empty())
            {
                uint32 counter = 0;
                uint32 maxcounter = BOT_GOSSIP_MAX_ITEMS - 3; //current, reset, back
                //s5.2.2: add items as gossip options
                for (std::set<uint32>::const_iterator itr = itemList.begin(); itr != itemList.end() && counter < maxcounter; ++itr)
                {
                    bool found = false;
                    for (uint8 i = INVENTORY_SLOT_ITEM_START; i != INVENTORY_SLOT_ITEM_END; ++i)
                    {
                        item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, i);
                        if (item && item->GetGUID().GetCounter() == (*itr))
                        {
                            std::ostringstream name;
                            _AddItemLink(player, item, name);
                            AddGossipItemFor(player, GOSSIP_ICON_CHAT, name.str(), GOSSIP_SENDER_EQUIP_TRANSMOGRIFY + slot, item->GetEntry());
                            ++counter;
                            found = true;
                            break;
                        }
                    }

                    if (found)
                        continue;

                    for (uint8 i = EQUIPMENT_SLOT_START; i != EQUIPMENT_SLOT_END; ++i)
                    {
                        item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, i);
                        if (item && item->GetGUID().GetCounter() == (*itr))
                        {
                            std::ostringstream name;
                            _AddItemLink(player, item, name);
                            AddGossipItemFor(player, GOSSIP_ICON_CHAT, name.str(), GOSSIP_SENDER_EQUIP_TRANSMOGRIFY + slot, item->GetEntry());
                            ++counter;
                            found = true;
                            break;
                        }
                    }

                    if (found)
                        continue;

                    for (uint8 i = INVENTORY_SLOT_BAG_START; i != INVENTORY_SLOT_BAG_END; ++i)
                    {
                        if (Bag const* pBag = player->GetBagByPos(i))
                        {
                            for (uint32 j = 0; j != pBag->GetBagSize(); ++j)
                            {
                                item = player->GetItemByPos(i, j);
                                if (item && item->GetGUID().GetCounter() == (*itr))
                                {
                                    std::ostringstream name;
                                    _AddItemLink(player, item, name);
                                    AddGossipItemFor(player, GOSSIP_ICON_CHAT, name.str(), GOSSIP_SENDER_EQUIP_TRANSMOGRIFY + slot, item->GetEntry());
                                    ++counter;
                                    found = true;
                                    break;
                                }
                            }
                        }

                        if (found)
                            break;
                    }

                    if (found)
                        continue;
                }
            }

            AddGossipItemFor(player, GOSSIP_ICON_CHAT, LocalizedNpcText(player, BOT_TEXT_BACK), GOSSIP_SENDER_EQUIPMENT, GOSSIP_ACTION_INFO_DEF + 2);

            break;
        }
        case GOSSIP_SENDER_EQUIPMENT_INFO: //request equip item info
        {
            //GOSSIP ITEMS RESTRICTED
            //subMenu = true; //needed for return

            EquipmentInfo const* einfo = BotDataMgr::GetBotEquipmentInfo(me->GetEntry());
            ASSERT(einfo, "Trying to send equipment info for bot with no equip info!");

            uint8 slot = action - GOSSIP_ACTION_INFO_DEF;
            Item const* item = _equips[slot];
            ASSERT(item);

            std::ostringstream msg;
            _AddItemLink(player, item, msg, false);

            if (slot <= BOT_SLOT_RANGED && einfo->ItemEntry[slot] == item->GetEntry())
                msg << " |cffe6cc80|h[!" << LocalizedNpcText(player, BOT_TEXT_VISUALONLY) << "!]|h|r";

            msg << " GS: " << uint32(CalculateItemGearScore(me->GetEntry(), me->GetLevel(), GetBotClass(), GetSpec(), slot, item->GetTemplate()));

            BotWhisper(msg.str(), player);

            //break; //no break here - return to menu
        }
        [[fallthrough]];
        case GOSSIP_SENDER_EQUIPMENT_SHOW: //equips change s2: send list of equippable items
        {
            subMenu = true;

            EquipmentInfo const* einfo = BotDataMgr::GetBotEquipmentInfo(me->GetEntry());
            ASSERT(einfo, "Trying to send equipment show for bot with no equip info!");

            std::set<uint32> itemList, idsList;

            //s2.1: build list
            //s2.1.1: backpack
            for (uint8 i = INVENTORY_SLOT_ITEM_START; i != INVENTORY_SLOT_ITEM_END; ++i)
            {
                if (Item const* pItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, i))
                {
                    bool standard = false;
                    for (uint8 j = 0; j != MAX_EQUIPMENT_ITEMS; ++j)
                    {
                        if (einfo->ItemEntry[j] == pItem->GetEntry())
                        {
                            standard = true;
                            break;
                        }
                    }
                    if (standard)
                        continue;
                    if (_canEquip(pItem->GetTemplate(), action - GOSSIP_ACTION_INFO_DEF, true, pItem) &&
                        /*itemList.find(pItem->GetGUID().GetCounter()) == itemList.end() &&*/
                        (pItem->GetItemRandomPropertyId() == 0 ? idsList.find(pItem->GetEntry()) == idsList.end() : true))
                    {
                        itemList.insert(pItem->GetGUID().GetCounter());
                        idsList.insert(pItem->GetEntry());
                    }
                }
            }

            //s2.1.2: other bags
            for (uint8 i = INVENTORY_SLOT_BAG_START; i != INVENTORY_SLOT_BAG_END; ++i)
            {
                if (Bag const* pBag = player->GetBagByPos(i))
                {
                    for (uint32 j = 0; j != pBag->GetBagSize(); ++j)
                    {
                        if (Item const* pItem = player->GetItemByPos(i, j))
                        {
                            bool standard = false;
                            for (uint8 k = 0; k != MAX_EQUIPMENT_ITEMS; ++k)
                            {
                                if (einfo->ItemEntry[k] == pItem->GetEntry())
                                {
                                    standard = true;
                                    break;
                                }
                            }
                            if (standard)
                                continue;
                            if (_canEquip(pItem->GetTemplate(), action - GOSSIP_ACTION_INFO_DEF, true, pItem) &&
                                /*itemList.find(pItem->GetGUID().GetCounter()) == itemList.end() &&*/
                                (pItem->GetItemRandomPropertyId() == 0 ? idsList.find(pItem->GetEntry()) == idsList.end() : true))
                            {
                                itemList.insert(pItem->GetGUID().GetCounter());
                                idsList.insert(pItem->GetEntry());
                            }
                        }
                    }
                }
            }

            //s2.2: add gossips

            //s2.2.0 add current item (with return)
            uint8 const slot = action - GOSSIP_ACTION_INFO_DEF;
            std::ostringstream str;
            str << LocalizedNpcText(player, BOT_TEXT_EQUIPPED) << ": ";
            if (Item const* item = _equips[slot])
            {
                bool visual_only = slot <= BOT_SLOT_RANGED && einfo->ItemEntry[slot] == item->GetEntry();

                _AddItemLink(player, item, str);
                if (visual_only)
                    str << " |cffe6cc80|h[!" << LocalizedNpcText(player, BOT_TEXT_VISUALONLY) << "!]|h|r";

                str << " GS: " << uint32(CalculateItemGearScore(me->GetEntry(), me->GetLevel(), GetBotClass(), GetSpec(), slot, item->GetTemplate()));

                AddGossipItemFor(player, GOSSIP_ICON_CHAT, str.str().c_str(), GOSSIP_SENDER_EQUIPMENT_INFO, action);

                if (!visual_only && BotMgr::DisplayEquipment() && BotMgr::IsTransmogEnabled() && slot < BOT_TRANSMOG_INVENTORY_SIZE && CanDisplayNonWeaponEquipmentChanges())
                    AddGossipItemFor(player, GOSSIP_ICON_TALK, LocalizedNpcText(player, BOT_TEXT_TRANSMOGRIFICATION), GOSSIP_SENDER_EQUIP_TRANSMOGS, action);
            }
            else
            {
                str << LocalizedNpcText(player, BOT_TEXT_NOTHING);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, str.str().c_str(), GOSSIP_SENDER_EQUIPMENT_SHOW, action);
            }

            if (_equips[slot])
            {
                //s2.2.1 add unequip option if have weapon (GMs only)
                if (slot <= BOT_SLOT_RANGED)
                {
                    if (einfo->ItemEntry[slot] != 0)
                        AddGossipItemFor(player, GOSSIP_ICON_CHAT, LocalizedNpcText(player, BOT_TEXT_USE_OLD_EQUIPMENT), GOSSIP_SENDER_EQUIP_RESET, action);
                    else
                        AddGossipItemFor(player, GOSSIP_ICON_CHAT, LocalizedNpcText(player, BOT_TEXT_UNEQUIP), GOSSIP_SENDER_UNEQUIP, action);
                }

                //s2.2.2 add unequip option for non-weapons
                if (slot > BOT_SLOT_RANGED)
                    AddGossipItemFor(player, GOSSIP_ICON_CHAT, LocalizedNpcText(player, BOT_TEXT_UNEQUIP), GOSSIP_SENDER_UNEQUIP, action);
            }

            //s2.2.3a: add an empty submenu with info if no items are found
            if (itemList.empty())
            {
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, LocalizedNpcText(player, BOT_TEXT_NOTHING_TO_GIVE), 0, GOSSIP_ACTION_INFO_DEF + 1);
            }
            else
            {
                uint32 counter = 0;
                uint32 maxcounter = BOT_GOSSIP_MAX_ITEMS - 5; //unequip, reset, current, transmog, back
                Item const* item;
                //s2.2.3b: add items as gossip options
                for (std::set<uint32>::const_iterator itr = itemList.begin(); itr != itemList.end() && counter < maxcounter; ++itr)
                {
                    bool found = false;
                    for (uint8 i = INVENTORY_SLOT_ITEM_START; i != INVENTORY_SLOT_ITEM_END; ++i)
                    {
                        item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, i);
                        if (item && item->GetGUID().GetCounter() == (*itr))
                        {
                            std::ostringstream name;
                            _AddItemLink(player, item, name);
                            name << " GS: " << uint32(CalculateItemGearScore(me->GetEntry(), me->GetLevel(), GetBotClass(), GetSpec(), slot, item->GetTemplate()));
                            if (BotMgr::SendEquipListItems())
                                BotWhisper(name.str(), player);
                            AddGossipItemFor(player, GOSSIP_ICON_CHAT, name.str().c_str(), GOSSIP_SENDER_EQUIP + slot, GOSSIP_ACTION_INFO_DEF + item->GetGUID().GetCounter());
                            ++counter;
                            found = true;
                            break;
                        }
                    }

                    if (found)
                        continue;

                    for (uint8 i = INVENTORY_SLOT_BAG_START; i != INVENTORY_SLOT_BAG_END; ++i)
                    {
                        if (Bag const* pBag = player->GetBagByPos(i))
                        {
                            for (uint32 j = 0; j != pBag->GetBagSize(); ++j)
                            {
                                item = player->GetItemByPos(i, j);
                                if (item && item->GetGUID().GetCounter() == (*itr))
                                {
                                    std::ostringstream name;
                                    _AddItemLink(player, item, name);
                                    name << " GS: " << uint32(CalculateItemGearScore(me->GetEntry(), me->GetLevel(), GetBotClass(), GetSpec(), slot, item->GetTemplate()));
                                    if (BotMgr::SendEquipListItems())
                                        BotWhisper(name.str(), player);
                                    AddGossipItemFor(player, GOSSIP_ICON_CHAT, name.str().c_str(), GOSSIP_SENDER_EQUIP + slot, GOSSIP_ACTION_INFO_DEF + item->GetGUID().GetCounter());
                                    ++counter;
                                    found = true;
                                    break;
                                }
                            }
                        }

                        if (found)
                            break;
                    }

                    if (found)
                        continue;
                }
            }

            AddGossipItemFor(player, GOSSIP_ICON_CHAT, LocalizedNpcText(player, BOT_TEXT_BACK), GOSSIP_SENDER_EQUIPMENT, GOSSIP_ACTION_INFO_DEF + 2);

            //TC_LOG_ERROR("entities.player", "OnGossipSelect(bot): added {} item(s) to list of {} (requester: {})",
            //    counter, me->GetName(), player->GetName());

            break;
        }
        case GOSSIP_SENDER_UNEQUIP: //equips change s3: Unequip DEPRECATED
        {
            if (!_unequip(action - GOSSIP_ACTION_INFO_DEF, player->GetGUID()))
            {} //BotWhisper("Impossible...", player);
            return OnGossipSelect(player, creature, GOSSIP_SENDER_EQUIPMENT, GOSSIP_ACTION_INFO_DEF + 1);
        }
        case GOSSIP_SENDER_UNEQUIP_ALL:
        {
            bool suc = true;
            for (uint8 i = BOT_SLOT_MAINHAND; i != BOT_INVENTORY_SIZE; ++i)
            {
                if (!(i <= BOT_SLOT_RANGED ? _resetEquipment(i, player->GetGUID()) : _unequip(i, player->GetGUID())))
                {
                    suc = false;
                    //std::ostringstream estr;
                    //estr << "Cannot reset equipment in slot " << uint32(i) << " (" << _getNameForSlot(i) << ")!";
                    //BotWhisper(estr.str().c_str(), player);
                }
            }

            if (suc)
                me->HandleEmoteCommand(EMOTE_ONESHOT_CRY);

            break;
        }
        //autoequips change s5b: AtoEquip item
        //base is GOSSIP_SENDER_EQUIP_AUTOEQUIP + 0...1...2... etc.
        case GOSSIP_SENDER_EQUIP_AUTOEQUIP_MHAND:     //0 - 1 main hand
        case GOSSIP_SENDER_EQUIP_AUTOEQUIP_OHAND:     //1 - 1 off hand
        case GOSSIP_SENDER_EQUIP_AUTOEQUIP_RANGED:    //2 - 1 ranged
        case GOSSIP_SENDER_EQUIP_AUTOEQUIP_HEAD:      //3 - 1 head
        case GOSSIP_SENDER_EQUIP_AUTOEQUIP_SHOULDERS: //4 - 1 shoulders
        case GOSSIP_SENDER_EQUIP_AUTOEQUIP_CHEST:     //5 - 1 chest
        case GOSSIP_SENDER_EQUIP_AUTOEQUIP_WAIST:     //6 - 1 waist
        case GOSSIP_SENDER_EQUIP_AUTOEQUIP_LEGS:      //7 - 1 legs
        case GOSSIP_SENDER_EQUIP_AUTOEQUIP_FEET:      //8 - 1 feet
        case GOSSIP_SENDER_EQUIP_AUTOEQUIP_WRIST:     //9 - 1 wrist
        case GOSSIP_SENDER_EQUIP_AUTOEQUIP_HANDS:     //10 - 1 hands
        case GOSSIP_SENDER_EQUIP_AUTOEQUIP_BACK:      //11 - 1 back
        case GOSSIP_SENDER_EQUIP_AUTOEQUIP_BODY:      //12 - 1 body
        case GOSSIP_SENDER_EQUIP_AUTOEQUIP_FINGER1:   //13 - 1 finger
        case GOSSIP_SENDER_EQUIP_AUTOEQUIP_FINGER2:   //14 - 2 finger
        case GOSSIP_SENDER_EQUIP_AUTOEQUIP_TRINKET1:  //15 - 1 trinket
        case GOSSIP_SENDER_EQUIP_AUTOEQUIP_TRINKET2:  //16 - 2 trinket
        case GOSSIP_SENDER_EQUIP_AUTOEQUIP_NECK:      //17 - 1 neck
        {
            Item* item = nullptr;
            uint32 guidLow = action - GOSSIP_ACTION_INFO_DEF;

            bool found = false;
            for (uint8 i = INVENTORY_SLOT_ITEM_START; i != INVENTORY_SLOT_ITEM_END; ++i)
            {
                item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, i);
                if (item && item->GetGUID().GetCounter() == guidLow)
                {
                    found = true;
                    break;
                }
            }

            if (!found)
            {
                for (uint8 i = INVENTORY_SLOT_BAG_START; i != INVENTORY_SLOT_BAG_END; ++i)
                {
                    if (Bag const* pBag = player->GetBagByPos(i))
                    {
                        for (uint32 j = 0; j != pBag->GetBagSize(); ++j)
                        {
                            item = player->GetItemByPos(i, j);
                            if (item && item->GetGUID().GetCounter() == guidLow)
                            {
                                found = true;
                                break;
                            }
                        }
                    }

                    if (found)
                        break;
                }
            }

            if (found && _equip(sender - GOSSIP_SENDER_EQUIP_AUTOEQUIP_EQUIP, item, player->GetGUID())){}

            //break; //no break: update list
        }
        [[fallthrough]];
        case GOSSIP_SENDER_EQUIP_AUTOEQUIP:
        {
            subMenu = true;

            EquipmentInfo const* einfo = BotDataMgr::GetBotEquipmentInfo(me->GetEntry());
            ASSERT(einfo, "Trying to send auto-equip for bot with no equip info!");

            std::set<uint32> itemList, idsList;

            //1: build list
            //1.1: backpack
            for (uint8 i = INVENTORY_SLOT_ITEM_START; i != INVENTORY_SLOT_ITEM_END; ++i)
            {
                if (Item const* pItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, i))
                {
                    bool standard = false;
                    for (uint8 j = 0; j != MAX_EQUIPMENT_ITEMS; ++j)
                    {
                        if (einfo->ItemEntry[j] == pItem->GetEntry())
                        {
                            standard = true;
                            break;
                        }
                    }
                    if (standard)
                        continue;

                    bool canEquip = false;

                    for (uint8 k = BOT_SLOT_MAINHAND; k != BOT_INVENTORY_SIZE; ++k)
                    {
                        if (_canEquip(pItem->GetTemplate(), k, false, pItem))
                        {
                            canEquip = true;
                            break;
                        }
                    }

                    if (canEquip &&/* itemList.find(pItem->GetGUID().GetCounter()) == itemList.end() &&*/
                        (pItem->GetItemRandomPropertyId() == 0 ? idsList.find(pItem->GetEntry()) == idsList.end() : true))
                    {
                        itemList.insert(pItem->GetGUID().GetCounter());
                        idsList.insert(pItem->GetEntry());
                    }
                }
            }

            //1.2: other bags
            for (uint8 i = INVENTORY_SLOT_BAG_START; i != INVENTORY_SLOT_BAG_END; ++i)
            {
                if (Bag const* pBag = player->GetBagByPos(i))
                {
                    for (uint32 j = 0; j != pBag->GetBagSize(); ++j)
                    {
                        if (Item const* pItem = player->GetItemByPos(i, j))
                        {
                            bool standard = false;
                            for (uint8 k = 0; k != MAX_EQUIPMENT_ITEMS; ++k)
                            {
                                if (einfo->ItemEntry[k] == pItem->GetEntry())
                                {
                                    standard = true;
                                    break;
                                }
                            }
                            if (standard)
                                continue;

                            bool canEquip = false;

                            for (uint8 k = BOT_SLOT_MAINHAND; k != BOT_INVENTORY_SIZE; ++k)
                            {
                                if (_canEquip(pItem->GetTemplate(), k, false, pItem))
                                {
                                    canEquip = true;
                                    break;
                                }
                            }

                            if (canEquip &&/* itemList.find(pItem->GetGUID().GetCounter()) == itemList.end() &&*/
                                (pItem->GetItemRandomPropertyId() == 0 ? idsList.find(pItem->GetEntry()) == idsList.end() : true))
                            {
                                itemList.insert(pItem->GetGUID().GetCounter());
                                idsList.insert(pItem->GetEntry());
                            }
                        }
                    }
                }
            }

            //2: add gossips

            if (itemList.empty())
            {
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, LocalizedNpcText(player, BOT_TEXT_NOTHING_TO_GIVE), 0, GOSSIP_ACTION_INFO_DEF + 1);
            }
            else
            {
                uint32 counter = 0;
                uint32 maxcounter = BOT_GOSSIP_MAX_ITEMS - 1; // back
                Item const* item;
                //add items as gossip options
                for (std::set<uint32>::const_iterator itr = itemList.begin(); itr != itemList.end() && counter < maxcounter; ++itr)
                {
                    bool found = false;
                    for (uint8 i = INVENTORY_SLOT_ITEM_START; i != INVENTORY_SLOT_ITEM_END; ++i)
                    {
                        item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, i);
                        if (item && item->GetGUID().GetCounter() == (*itr))
                        {
                            uint8 k = 0;
                            for (; k != BOT_INVENTORY_SIZE; ++k)
                            {
                                if (_canEquip(item->GetTemplate(), k, false, item))
                                {
                                    //workaround for double slots
                                    //if first slot is occupied and second slot is vacant use second slot
                                    if (k == BOT_SLOT_FINGER1 || k == BOT_SLOT_TRINKET1)
                                        if (_equips[k] != nullptr && _canEquip(item->GetTemplate(), k + 1, false, item))
                                            ++k;
                                    break;
                                }
                            }

                            std::ostringstream name;
                            _AddItemLink(player, item, name);
                            if (BotMgr::SendEquipListItems())
                                BotWhisper(name.str(), player);
                            AddGossipItemFor(player, GOSSIP_ICON_CHAT, name.str().c_str(), GOSSIP_SENDER_EQUIP_AUTOEQUIP_EQUIP + k, GOSSIP_ACTION_INFO_DEF + item->GetGUID().GetCounter());
                            ++counter;
                            found = true;
                            break;
                        }
                    }

                    if (found)
                        continue;

                    for (uint8 i = INVENTORY_SLOT_BAG_START; i != INVENTORY_SLOT_BAG_END; ++i)
                    {
                        if (Bag const* pBag = player->GetBagByPos(i))
                        {
                            for (uint32 j = 0; j != pBag->GetBagSize(); ++j)
                            {
                                item = player->GetItemByPos(i, j);
                                if (item && item->GetGUID().GetCounter() == (*itr))
                                {
                                    uint8 k = 0;
                                    for (; k != BOT_INVENTORY_SIZE; ++k)
                                    {
                                        if (_canEquip(item->GetTemplate(), k, false, item))
                                        {
                                            //workaround for double slots
                                            //if first slot is occupied and second slot is vacant use second slot
                                            if (k == BOT_SLOT_FINGER1 || k == BOT_SLOT_TRINKET1)
                                                if (_equips[k] != nullptr && _canEquip(item->GetTemplate(), k + 1, false, item))
                                                    ++k;
                                            break;
                                        }
                                    }

                                    std::ostringstream name;
                                    _AddItemLink(player, item, name);
                                    if (BotMgr::SendEquipListItems())
                                        BotWhisper(name.str(), player);
                                    AddGossipItemFor(player, GOSSIP_ICON_CHAT, name.str().c_str(), GOSSIP_SENDER_EQUIP_AUTOEQUIP_EQUIP + k, GOSSIP_ACTION_INFO_DEF + item->GetGUID().GetCounter());
                                    ++counter;
                                    found = true;
                                    break;
                                }
                            }
                        }

                        if (found)
                            break;
                    }

                    if (found)
                        continue;
                }
            }

            AddGossipItemFor(player, GOSSIP_ICON_CHAT, LocalizedNpcText(player, BOT_TEXT_BACK), GOSSIP_SENDER_EQUIPMENT, GOSSIP_ACTION_INFO_DEF + 2);
            break;
        }
        case GOSSIP_SENDER_EQUIP_RESET: //equips change s4a: reset equipment
        {
            if (_resetEquipment(action - GOSSIP_ACTION_INFO_DEF, player->GetGUID())){}
            return OnGossipSelect(player, creature, GOSSIP_SENDER_EQUIPMENT, GOSSIP_ACTION_INFO_DEF + 1);
        }
        //equips change s4b: Equip item
        //base is GOSSIP_SENDER_EQUIP + 0...1...2... etc.
        case GOSSIP_SENDER_EQUIP_MHAND:     //0 - 1 main hand
        case GOSSIP_SENDER_EQUIP_OHAND:     //1 - 1 off hand
        case GOSSIP_SENDER_EQUIP_RANGED:    //2 - 1 ranged
        case GOSSIP_SENDER_EQUIP_HEAD:      //3 - 1 head
        case GOSSIP_SENDER_EQUIP_SHOULDERS: //4 - 1 shoulders
        case GOSSIP_SENDER_EQUIP_CHEST:     //5 - 1 chest
        case GOSSIP_SENDER_EQUIP_WAIST:     //6 - 1 waist
        case GOSSIP_SENDER_EQUIP_LEGS:      //7 - 1 legs
        case GOSSIP_SENDER_EQUIP_FEET:      //8 - 1 feet
        case GOSSIP_SENDER_EQUIP_WRIST:     //9 - 1 wrist
        case GOSSIP_SENDER_EQUIP_HANDS:     //10 - 1 hands
        case GOSSIP_SENDER_EQUIP_BACK:      //11 - 1 back
        case GOSSIP_SENDER_EQUIP_BODY:      //12 - 1 body
        case GOSSIP_SENDER_EQUIP_FINGER1:   //13 - 1 finger
        case GOSSIP_SENDER_EQUIP_FINGER2:   //14 - 1 finger
        case GOSSIP_SENDER_EQUIP_TRINKET1:  //15 - 1 trinket
        case GOSSIP_SENDER_EQUIP_TRINKET2:  //16 - 1 trinket
        case GOSSIP_SENDER_EQUIP_NECK:      //17 - 1 neck
        {
            Item* item = nullptr;
            uint32 guidLow = action - GOSSIP_ACTION_INFO_DEF;

            bool found = false;
            for (uint8 i = INVENTORY_SLOT_ITEM_START; i != INVENTORY_SLOT_ITEM_END; ++i)
            {
                item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, i);
                if (item && item->GetGUID().GetCounter() == guidLow)
                {
                    found = true;
                    break;
                }
            }

            if (!found)
            {
                for (uint8 i = INVENTORY_SLOT_BAG_START; i != INVENTORY_SLOT_BAG_END; ++i)
                {
                    if (Bag const* pBag = player->GetBagByPos(i))
                    {
                        for (uint32 j = 0; j != pBag->GetBagSize(); ++j)
                        {
                            item = player->GetItemByPos(i, j);
                            if (item && item->GetGUID().GetCounter() == guidLow)
                            {
                                found = true;
                                break;
                            }
                        }
                    }

                    if (found)
                        break;
                }
            }

            if (found && _equip(sender - GOSSIP_SENDER_EQUIP, item, player->GetGUID())){}
            return OnGossipSelect(player, creature, GOSSIP_SENDER_EQUIPMENT, GOSSIP_ACTION_INFO_DEF + 1);
        }
        case GOSSIP_SENDER_EQUIPMENT_BANK_DEPOSIT_ITEM:
        {
            ObjectGuid::LowType itemGuidLow = action - GOSSIP_ACTION_INFO_DEF;
            Item* item = player->GetItemByGuid(ObjectGuid::Create<HighGuid::Item>(itemGuidLow));
            if (!item)
            {
                TC_LOG_ERROR("npcbots", "GOSSIP_SENDER_EQUIPMENT_BANK_DEPOSIT_ITEM: item {} not found on player {}! Cheater?",
                    itemGuidLow, player->GetName());
                break;
            }

            BotDataMgr::DepositBotBankItem(player->GetGUID(), item);
            player->MoveItemFromInventory(item->GetBagSlot(), item->GetSlot(), true);

            action = GOSSIP_ACTION_INFO_DEF; //return to page 0
            //break;
            [[fallthrough]];
        }
        case GOSSIP_SENDER_EQUIPMENT_BANK_DEPOSIT:
        {
            subMenu = true;
            uint32 page = action - GOSSIP_ACTION_INFO_DEF;
            uint32 items_per_page = BOT_GOSSIP_MAX_ITEMS - 3; // prev page, back, next page
            uint32 counter = 0;
            uint32 can_add_count = 0;
            uint32 k = 0;

            static const auto is_bot_equippable_item = [](ItemTemplate const* proto) {
                switch (proto->InventoryType)
                {
                    case INVTYPE_NON_EQUIP: case INVTYPE_BAG: case INVTYPE_TABARD: case INVTYPE_AMMO: case INVTYPE_QUIVER:
                        return false;
                    default:
                        return true;
                }
            };

            //backpack
            for (uint8 i = INVENTORY_SLOT_ITEM_START; i != INVENTORY_SLOT_ITEM_END && can_add_count <= items_per_page; ++i)
            {
                if (Item const* pItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, i))
                {
                    if (is_bot_equippable_item(pItem->GetTemplate()))
                    {
                        ++k;
                        if (k <= page * items_per_page)
                            continue;
                        ++can_add_count;
                        if (counter >= items_per_page)
                            continue;
                        ++counter;
                        std::ostringstream name;
                        _AddItemLink(player, pItem, name);
                        AddGossipItemFor(player, GOSSIP_ICON_CHAT, name.str(), GOSSIP_SENDER_EQUIPMENT_BANK_DEPOSIT_ITEM, GOSSIP_ACTION_INFO_DEF + pItem->GetGUID().GetCounter());
                    }
                }
            }

            //other bags
            for (uint8 i = INVENTORY_SLOT_BAG_START; i != INVENTORY_SLOT_BAG_END && can_add_count <= items_per_page; ++i)
            {
                Bag const* pBag = player->GetBagByPos(i);
                if (!pBag)
                    continue;
                for (uint32 j = 0; j != pBag->GetBagSize() && can_add_count <= items_per_page; ++j)
                {
                    Item const* pItem = player->GetItemByPos(i, j);
                    if (!pItem)
                        continue;
                    if (is_bot_equippable_item(pItem->GetTemplate()))
                    {
                        ++k;
                        if (k <= page * items_per_page)
                            continue;
                        ++can_add_count;
                        if (counter >= items_per_page)
                            continue;
                        ++counter;
                        std::ostringstream name;
                        _AddItemLink(player, pItem, name);
                        AddGossipItemFor(player, GOSSIP_ICON_CHAT, name.str(), GOSSIP_SENDER_EQUIPMENT_BANK_DEPOSIT_ITEM, GOSSIP_ACTION_INFO_DEF + pItem->GetGUID().GetCounter());
                    }
                }
            }

            if (page > 0)
                AddGossipItemFor(player, GOSSIP_ICON_TALK, LocalizedNpcText(player, BOT_TEXT_PREVIOUS_PAGE), GOSSIP_SENDER_EQUIPMENT_BANK_DEPOSIT, action - 1);
            if (can_add_count > items_per_page)
                AddGossipItemFor(player, GOSSIP_ICON_TALK, LocalizedNpcText(player, BOT_TEXT_NEXT_PAGE), GOSSIP_SENDER_EQUIPMENT_BANK_DEPOSIT, action + 1);
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, LocalizedNpcText(player, BOT_TEXT_BACK), GOSSIP_SENDER_EQUIPMENT_BANK_MENU, GOSSIP_ACTION_INFO_DEF + 1);
            break;
        }
        case GOSSIP_SENDER_EQUIPMENT_BANK_WITHDRAW_ITEM:
        {
            ObjectGuid::LowType itemGuidLow = action - GOSSIP_ACTION_INFO_DEF;

            //BotBankItemContainer const& botBankItems = BotDataMgr::GetBotBankItems(player->GetGUID());
            //Item const* item = std::find_if(std::cbegin(botBankItems), std::cend(botBankItems), [guidLow = itemGuidLow](Item const* item) {
            //    return item->GetGUID().GetCounter() == guidLow;
            //});
            Item* item = BotDataMgr::WithdrawBotBankItem(player->GetGUID(), itemGuidLow);
            if (!item)
            {
                TC_LOG_ERROR("npcbots", "GOSSIP_SENDER_EQUIPMENT_BANK_WITHDRAW_ITEM: item {} not found on player {}! Cheater?",
                    itemGuidLow, player->GetName());
                break;
            }

            ItemPosCountVec dest;
            uint32 no_space = 0;
            InventoryResult msg = player->CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, item->GetEntry(), 1, &no_space);
            if (msg != EQUIP_ERR_OK)
            {
                std::ostringstream istr;
                _AddItemLink(player, item, istr, false);
                ChatHandler ch(player->GetSession());
                ch.PSendSysMessage(LocalizedNpcText(player, BOT_TEXT_CANT_UNEQUIP_MAILING).c_str(), istr.str().c_str());

                item->SetOwnerGUID(player->GetGUID());

                CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();
                item->FSetState(ITEM_CHANGED);
                item->SaveToDB(trans);
                MailDraft(istr.str(), "").AddItem(item).SendMailTo(trans, MailReceiver(player), MailSender(me));
                CharacterDatabase.CommitTransaction(trans);

                player->SendEquipError(msg, nullptr, nullptr, item->GetEntry());
            }
            else
            {
                Item* pItem = player->StoreItem(dest, item, true);
                player->SendNewItem(pItem, 1, true, false, false);
            }

            action = GOSSIP_ACTION_INFO_DEF; //return to page 0
            //break;
            [[fallthrough]];
        }
        case GOSSIP_SENDER_EQUIPMENT_BANK_WITHDRAW:
        {
            uint32 page = action - GOSSIP_ACTION_INFO_DEF;
            uint32 items_per_page = BOT_GOSSIP_MAX_ITEMS - 3; // page prev, page next, back
            uint32 counter = 0;

            BotBankItemContainer const* botBankItems = BotDataMgr::GetBotBankItems(player->GetGUID());
            if (!botBankItems || botBankItems->empty())
            {
                BotWhisper(LocalizedNpcText(player, BOT_TEXT_BANK_IS_EMPTY), player);
                return OnGossipSelect(player, me, GOSSIP_SENDER_EQUIPMENT_BANK_MENU, action);
                break;
            }

            subMenu = true;

            BotBankItemContainer::const_iterator bcit = botBankItems->cbegin();
            size_t i = 0;
            for (; i < page * items_per_page && i < botBankItems->size(); ++i, ++bcit);
            for (; i < botBankItems->size() && counter < items_per_page; ++i, ++bcit)
            {
                Item const* item = *bcit;
                ++counter;
                std::ostringstream name;
                _AddItemLink(player, item, name);
                ItemTemplate const* proto = item->GetTemplate();
                uint8 slot = BOT_SLOT_BODY;
                if (GetBotClass() == BOT_CLASS_HUNTER)
                {
                    if (_canEquip(proto, BOT_SLOT_RANGED, true))
                        slot = BOT_SLOT_RANGED;
                    else if (_canEquip(proto, BOT_SLOT_MAINHAND, true))
                        slot = BOT_SLOT_MAINHAND;
                    else if (_canEquip(proto, BOT_SLOT_OFFHAND, true))
                        slot = BOT_SLOT_OFFHAND;
                }
                else if (GetBotClass() == BOT_CLASS_WARRIOR && _canEquip(proto, BOT_SLOT_MAINHAND, true))
                    slot = BOT_SLOT_MAINHAND;

                name << " GS: " << uint32(CalculateItemGearScore(me->GetEntry(), me->GetLevel(), GetBotClass(), GetSpec(), slot, proto));
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, name.str(), GOSSIP_SENDER_EQUIPMENT_BANK_WITHDRAW_ITEM, GOSSIP_ACTION_INFO_DEF + item->GetGUID().GetCounter());
            }

            if (page > 0)
                AddGossipItemFor(player, GOSSIP_ICON_TALK, LocalizedNpcText(player, BOT_TEXT_PREVIOUS_PAGE), GOSSIP_SENDER_EQUIPMENT_BANK_WITHDRAW, action - 1);
            if (botBankItems->size() > (page + 1) * items_per_page)
                AddGossipItemFor(player, GOSSIP_ICON_TALK, LocalizedNpcText(player, BOT_TEXT_NEXT_PAGE), GOSSIP_SENDER_EQUIPMENT_BANK_WITHDRAW, action + 1);
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, LocalizedNpcText(player, BOT_TEXT_BACK), GOSSIP_SENDER_EQUIPMENT_BANK_MENU, GOSSIP_ACTION_INFO_DEF + 1);
            break;
        }
        case GOSSIP_SENDER_EQUIPMENT_BANK_MENU:
        {
            subMenu = true;

            AddGossipItemFor(player, GOSSIP_ICON_TALK, LocalizedNpcText(player, BOT_TEXT_DEPOSIT_ITEMS), GOSSIP_SENDER_EQUIPMENT_BANK_DEPOSIT, GOSSIP_ACTION_INFO_DEF + 0);
            AddGossipItemFor(player, GOSSIP_ICON_TALK, LocalizedNpcText(player, BOT_TEXT_WITHDRAW_ITEMS), GOSSIP_SENDER_EQUIPMENT_BANK_WITHDRAW, GOSSIP_ACTION_INFO_DEF + 0);
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, LocalizedNpcText(player, BOT_TEXT_BACK), 1, GOSSIP_ACTION_INFO_DEF + 1);

            break;
        }
        case GOSSIP_SENDER_ROLES_MAIN_TOGGLE: //ROLES 2: set/unset
        {
            ToggleRole(action - GOSSIP_ACTION_INFO_DEF, false);

            [[fallthrough]];
            //break;
        }
        case GOSSIP_SENDER_ROLES_MAIN: //ROLES 1: list
        {
            subMenu = true;

            if (IsHumanoidClass(_botclass))
                AddGossipItemFor(player, GOSSIP_ICON_TALK, LocalizedNpcText(player, BOT_TEXT_GATHERING) + "...", GOSSIP_SENDER_ROLES_GATHERING, GOSSIP_ACTION_INFO_DEF + 1);
            AddGossipItemFor(player, GOSSIP_ICON_TALK, LocalizedNpcText(player, BOT_TEXT_LOOTING) + "...", GOSSIP_SENDER_ROLES_LOOTING, GOSSIP_ACTION_INFO_DEF + 2);

            uint32 role = BOT_ROLE_TANK;
            for (; role != BOT_MAX_ROLE; role <<= 1)
            {
                if (!(role & BOT_ROLE_MASK_MAIN)) //hidden
                    continue;
                if (role == BOT_ROLE_HEAL && !IsHealingClass(_botclass))
                    continue;

                AddGossipItemFor(player, GetRoleIcon(role), LocalizedNpcText(player, GetRoleString(role)), GOSSIP_SENDER_ROLES_MAIN_TOGGLE, GOSSIP_ACTION_INFO_DEF + role);
            }

            AddGossipItemFor(player, GOSSIP_ICON_CHAT, LocalizedNpcText(player, BOT_TEXT_BACK), 1, GOSSIP_ACTION_INFO_DEF + 1);

            break;
        }
        case GOSSIP_SENDER_ROLES_GATHERING_TOGGLE:
        {
            ToggleRole(action - GOSSIP_ACTION_INFO_DEF, false);

            [[fallthrough]];
            //break;
        }
        case GOSSIP_SENDER_ROLES_GATHERING:
        {
            subMenu = true;

            uint32 role = BOT_ROLE_GATHERING_MINING;
            for (; role != BOT_MAX_ROLE; role <<= 1)
            {
                if (!(role & BOT_ROLE_MASK_GATHERING)) //hidden
                    continue;

                AddGossipItemFor(player, GetRoleIcon(role), LocalizedNpcText(player, GetRoleString(role)), GOSSIP_SENDER_ROLES_GATHERING_TOGGLE, GOSSIP_ACTION_INFO_DEF + role);
            }

            AddGossipItemFor(player, GOSSIP_ICON_CHAT, LocalizedNpcText(player, BOT_TEXT_BACK), GOSSIP_SENDER_ROLES_MAIN, GOSSIP_ACTION_INFO_DEF + 1);

            break;
        }
        case GOSSIP_SENDER_ROLES_LOOTING_TOGGLE:
        {
            ToggleRole(action - GOSSIP_ACTION_INFO_DEF, false);

            [[fallthrough]];
            //break;
        }
        case GOSSIP_SENDER_ROLES_LOOTING:
        {
            subMenu = true;

            uint32 role = BOT_ROLE_AUTOLOOT;
            for (; role != BOT_MAX_ROLE; role <<= 1)
            {
                if (!(role & (BOT_ROLE_AUTOLOOT | BOT_ROLE_MASK_LOOTING)))
                    continue;

                AddGossipItemFor(player, GetRoleIcon(role), LocalizedNpcText(player, GetRoleString(role)), GOSSIP_SENDER_ROLES_LOOTING_TOGGLE, GOSSIP_ACTION_INFO_DEF + role);
            }

            AddGossipItemFor(player, GOSSIP_ICON_CHAT, LocalizedNpcText(player, BOT_TEXT_BACK), GOSSIP_SENDER_ROLES_MAIN, GOSSIP_ACTION_INFO_DEF + 1);

            break;
        }
        case GOSSIP_SENDER_ABILITIES_USE:
        {
            if (uint32 basespell = action - GOSSIP_ACTION_INFO_DEF)
                //if (CheckBotCast(me, basespell, me->GetBotClass()) == SPELL_CAST_OK)
                    if (IsSpellReady(basespell, lastdiff, true))
                        doCast(player, GetSpell(basespell));

            //break;
            action = GOSSIP_ACTION_INFO_DEF;
            [[fallthrough]];
        }
        case GOSSIP_SENDER_ABILITIES:
        {
            subMenu = true;

            if (HasAbilitiesSpecifics())
                AddGossipItemFor(player, GOSSIP_ICON_TALK, LocalizedNpcText(player, BOT_TEXT_ABILITIES_STATUS) + "...", GOSSIP_SENDER_ABILITIES_SPECIFICS_LIST, GOSSIP_ACTION_INFO_DEF + 1);
            AddGossipItemFor(player, GOSSIP_ICON_TALK, LocalizedNpcText(player, BOT_TEXT_ALLOWED_ABILITIES) + "...", GOSSIP_SENDER_ABILITIES_USAGE_LIST, GOSSIP_ACTION_INFO_DEF + 2);

            uint32 basespell;
            SpellInfo const* spellInfo;
            BotSpellMap const& myspells = GetSpellMap();
            for (BotSpellMap::const_iterator itr = myspells.begin(); itr != myspells.end(); ++itr)
            {
                basespell = itr->first; //always valid
                if (!CanUseManually(basespell)) continue;
                if (!IsSpellReady(basespell, lastdiff, false)) continue;
                spellInfo = sSpellMgr->GetSpellInfo(basespell); //always valid

                std::ostringstream name;
                name << LocalizedNpcText(player, BOT_TEXT_USE_);
                _AddSpellLink(player, spellInfo, name);
                AddGossipItemFor(player, GOSSIP_ICON_TRAINER, name.str().c_str(), GOSSIP_SENDER_ABILITIES_USE, GOSSIP_ACTION_INFO_DEF + basespell);
            }

            AddGossipItemFor(player, GOSSIP_ICON_CHAT, LocalizedNpcText(player, BOT_TEXT_UPDATE), sender, action);
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, LocalizedNpcText(player, BOT_TEXT_BACK), 1, GOSSIP_ACTION_INFO_DEF + 2);

            break;
        }
        case GOSSIP_SENDER_ABILITIES_SPECIFICS_LIST:
        {
            subMenu = true;

            std::list<std::string> specList;
            FillAbilitiesSpecifics(player, specList);
            for (std::list<std::string>::const_iterator itr = specList.begin(); itr != specList.end(); ++itr)
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, *itr, GOSSIP_SENDER_ABILITIES, GOSSIP_ACTION_INFO_DEF);

            AddGossipItemFor(player, GOSSIP_ICON_CHAT, LocalizedNpcText(player, BOT_TEXT_BACK), GOSSIP_SENDER_ABILITIES, GOSSIP_ACTION_INFO_DEF + 1);

            break;
        }
        case GOSSIP_SENDER_ABILITIES_USAGE_TOGGLE_DAMAGE:
        case GOSSIP_SENDER_ABILITIES_USAGE_TOGGLE_CC:
        case GOSSIP_SENDER_ABILITIES_USAGE_TOGGLE_HEAL:
        case GOSSIP_SENDER_ABILITIES_USAGE_TOGGLE_SUPPORT:
        {
            NpcBotData* npcBotData = const_cast<NpcBotData*>(BotDataMgr::SelectNpcBotData(me->GetEntry()));

            uint32 basespell = action - GOSSIP_ACTION_INFO_DEF;
            BotSpellMap const& myspells = GetSpellMap();
            for (BotSpellMap::const_iterator itr = myspells.begin(); itr != myspells.end(); ++itr)
            {
                if (itr->first == basespell)
                {
                    itr->second->enabled = !itr->second->enabled;
                    if (itr->second->enabled)
                        npcBotData->disabled_spells.erase(basespell);
                    else
                        npcBotData->disabled_spells.insert(basespell);

                    _saveDisabledSpells = true;
                    break;
                }
            }

            uint32 newSender;
            switch (sender)
            {
                case GOSSIP_SENDER_ABILITIES_USAGE_TOGGLE_DAMAGE:
                    newSender = GOSSIP_SENDER_ABILITIES_USAGE_LIST_DAMAGE;  break;
                case GOSSIP_SENDER_ABILITIES_USAGE_TOGGLE_CC:
                    newSender = GOSSIP_SENDER_ABILITIES_USAGE_LIST_CC;      break;
                case GOSSIP_SENDER_ABILITIES_USAGE_TOGGLE_HEAL:
                    newSender = GOSSIP_SENDER_ABILITIES_USAGE_LIST_HEAL;    break;
                case GOSSIP_SENDER_ABILITIES_USAGE_TOGGLE_SUPPORT:
                    newSender = GOSSIP_SENDER_ABILITIES_USAGE_LIST_SUPPORT; break;
                default:
                    ASSERT(false);
            }
            sender = newSender;
        }
        [[fallthrough]];
        case GOSSIP_SENDER_ABILITIES_USAGE_LIST_DAMAGE:
        case GOSSIP_SENDER_ABILITIES_USAGE_LIST_CC:
        case GOSSIP_SENDER_ABILITIES_USAGE_LIST_HEAL:
        case GOSSIP_SENDER_ABILITIES_USAGE_LIST_SUPPORT:
        {
            subMenu = true;

            uint32 toggleSender;
            std::vector<uint32> const* myspells;
            switch (sender)
            {
                case GOSSIP_SENDER_ABILITIES_USAGE_LIST_DAMAGE:
                    toggleSender = GOSSIP_SENDER_ABILITIES_USAGE_TOGGLE_DAMAGE;
                    myspells = GetDamagingSpellsList();
                    break;
                case GOSSIP_SENDER_ABILITIES_USAGE_LIST_CC:
                    toggleSender = GOSSIP_SENDER_ABILITIES_USAGE_TOGGLE_CC;
                    myspells = GetCCSpellsList();
                    break;
                case GOSSIP_SENDER_ABILITIES_USAGE_LIST_HEAL:
                    toggleSender = GOSSIP_SENDER_ABILITIES_USAGE_TOGGLE_HEAL;
                    myspells = GetHealingSpellsList();
                    break;
                case GOSSIP_SENDER_ABILITIES_USAGE_LIST_SUPPORT:
                    toggleSender = GOSSIP_SENDER_ABILITIES_USAGE_TOGGLE_SUPPORT;
                    myspells = GetSupportSpellsList();
                    break;
                default:
                    ASSERT(false);
            }

            ASSERT(myspells);

            uint32 counter = 0;
            SpellInfo const* spellInfo;
            for (std::vector<uint32>::const_iterator itr = myspells->begin(); itr != myspells->end(); ++itr)
            {
                if (!HasSpell(*itr)) //not init'ed (cannot be used)
                    continue;

                spellInfo = sSpellMgr->GetSpellInfo(*itr); //always valid
                std::ostringstream name;
                _AddSpellLink(player, spellInfo, name);

                GossipOptionIcon icon = (GetSpell(*itr) != 0) ? BOT_ICON_ON : BOT_ICON_OFF;
                AddGossipItemFor(player, icon, name.str().c_str(), toggleSender, GOSSIP_ACTION_INFO_DEF + *itr);
                if (++counter >= BOT_GOSSIP_MAX_ITEMS - 1) //back
                {
                    TC_LOG_ERROR("scripts", "bot_ai: gossip abilities list overflow with sender {} for bot class {}!",
                        sender, uint32(_botclass));
                    break;
                }
            }

            AddGossipItemFor(player, GOSSIP_ICON_CHAT, LocalizedNpcText(player, BOT_TEXT_BACK), GOSSIP_SENDER_ABILITIES_USAGE_LIST, GOSSIP_ACTION_INFO_DEF + 2);
            break;
        }
        case GOSSIP_SENDER_ABILITIES_USAGE_LIST:
        {
            subMenu = true;

            if (GetDamagingSpellsList())
                AddGossipItemFor(player, GOSSIP_ICON_TALK, LocalizedNpcText(player, BOT_TEXT_DAMAGE) + "...", GOSSIP_SENDER_ABILITIES_USAGE_LIST_DAMAGE, GOSSIP_ACTION_INFO_DEF + 1);
            if (GetCCSpellsList())
                AddGossipItemFor(player, GOSSIP_ICON_TALK, LocalizedNpcText(player, BOT_TEXT_CONTROL) + "...", GOSSIP_SENDER_ABILITIES_USAGE_LIST_CC, GOSSIP_ACTION_INFO_DEF + 2);
            if (GetHealingSpellsList())
                AddGossipItemFor(player, GOSSIP_ICON_TALK, LocalizedNpcText(player, BOT_TEXT_HEAL) + "...", GOSSIP_SENDER_ABILITIES_USAGE_LIST_HEAL, GOSSIP_ACTION_INFO_DEF + 3);
            if (GetSupportSpellsList())
                AddGossipItemFor(player, GOSSIP_ICON_TALK, LocalizedNpcText(player, BOT_TEXT_OTHER) + "...", GOSSIP_SENDER_ABILITIES_USAGE_LIST_SUPPORT, GOSSIP_ACTION_INFO_DEF + 4);

            AddGossipItemFor(player, GOSSIP_ICON_CHAT, LocalizedNpcText(player, BOT_TEXT_BACK), GOSSIP_SENDER_ABILITIES, GOSSIP_ACTION_INFO_DEF + 5);
            break;
        }
        case GOSSIP_SENDER_SPEC_SET:
        {
            uint8 newSpec = action - GOSSIP_ACTION_INFO_DEF;

            if (newSpec != _spec && newSpec >= BOT_SPEC_BEGIN && newSpec <= BOT_SPEC_END)
            {
                _newspec = newSpec;
                me->CastSpell(me, ACTIVATE_SPEC, false);
                BotWhisper(LocalizedNpcText(player, BOT_TEXT_CHANGING_MY_SPEC_TO_) + LocalizedNpcText(player, TextForSpec(_newspec)));
                break;
            }
        }
        [[fallthrough]];
        case GOSSIP_SENDER_SPEC:
        {
            subMenu = true;

            uint8 specIndex;
            switch (_botclass)
            {
                case BOT_CLASS_WARRIOR:         specIndex = BOT_SPEC_WARRIOR_ARMS;          break;
                case BOT_CLASS_PALADIN:         specIndex = BOT_SPEC_PALADIN_HOLY;          break;
                case BOT_CLASS_HUNTER:          specIndex = BOT_SPEC_HUNTER_BEASTMASTERY;   break;
                case BOT_CLASS_ROGUE:           specIndex = BOT_SPEC_ROGUE_ASSASINATION;    break;
                case BOT_CLASS_PRIEST:          specIndex = BOT_SPEC_PRIEST_DISCIPLINE;     break;
                case BOT_CLASS_DEATH_KNIGHT:    specIndex = BOT_SPEC_DK_BLOOD;              break;
                case BOT_CLASS_SHAMAN:          specIndex = BOT_SPEC_SHAMAN_ELEMENTAL;      break;
                case BOT_CLASS_MAGE:            specIndex = BOT_SPEC_MAGE_ARCANE;           break;
                case BOT_CLASS_WARLOCK:         specIndex = BOT_SPEC_WARLOCK_AFFLICTION;    break;
                case BOT_CLASS_DRUID:           specIndex = BOT_SPEC_DRUID_BALANCE;         break;
                default:
                    TC_LOG_ERROR("entities.unit", "bot_ai:GOSSIP_SENDER_SPEC called for class {} with no specs!", uint32(_botclass));
                    return true;
            }

            for (uint8 i = specIndex; i < specIndex + 3; ++i)
            {
                GossipOptionIcon icon = (GetSpec() == i) ? BOT_ICON_ON : BOT_ICON_OFF;
                AddGossipItemFor(player, icon, LocalizedNpcText(player, TextForSpec(i)), GOSSIP_SENDER_SPEC_SET, GOSSIP_ACTION_INFO_DEF + i);
            }

            AddGossipItemFor(player, GOSSIP_ICON_CHAT, LocalizedNpcText(player, BOT_TEXT_BACK), 1, GOSSIP_ACTION_INFO_DEF + 2);
            break;
        }
        case GOSSIP_SENDER_USEITEM_USE:
        {
            if (uint32 guidLow = action - GOSSIP_ACTION_INFO_DEF)
            {
                Item const* item = nullptr;
                bool found = false;
                for (uint8 i = INVENTORY_SLOT_ITEM_START; i != INVENTORY_SLOT_ITEM_END; ++i)
                {
                    item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, i);
                    if (item && item->GetGUID().GetCounter() == guidLow)
                    {
                        found = true;
                        break;
                    }
                }

                if (!found)
                {
                    for (uint8 i = INVENTORY_SLOT_BAG_START; i != INVENTORY_SLOT_BAG_END; ++i)
                    {
                        if (Bag const* pBag = player->GetBagByPos(i))
                        {
                            for (uint32 j = 0; j != pBag->GetBagSize(); ++j)
                            {
                                item = player->GetItemByPos(i, j);
                                if (item && item->GetGUID().GetCounter() == guidLow)
                                {
                                    found = true;
                                    break;
                                }
                            }
                        }

                        if (found)
                            break;
                    }
                }

                if (found)
                {
                    ItemTemplate const* proto = item->GetTemplate();
                    // Learning (483 / 55884)
                    if (proto->Spells[0].SpellId == 483 || proto->Spells[0].SpellId == 55884)
                        break;

                    // cast item spell
                    SpellCastTargets targets;
                    targets.SetUnitTarget(me);
                    _castBotItemUseSpell(item, targets);
                }
            }

            //break;
            action = GOSSIP_ACTION_INFO_DEF;
            [[fallthrough]];
        }
        case GOSSIP_SENDER_USEITEM:
        {
            subMenu = true;

            uint32 counter = 0;
            uint32 maxcounter = BOT_GOSSIP_MAX_ITEMS - 2; //update, back
            Item const* item;

            static const auto is_consumable_item = [](Item const* item, Creature const* bot) {
                if (ItemTemplate const* proto = item ? item->GetTemplate() : nullptr)
                {
                    if (!(proto->Class != ITEM_CLASS_WEAPON && proto->Class != ITEM_CLASS_ARMOR &&
                        (proto->AllowableClass == 0 || (proto->AllowableClass & (1 << (bot->GetBotClass() - 1)))) &&
                        proto->RequiredSkill == 0 && proto->RequiredSpell == 0 && bot->GetLevel() >= proto->RequiredLevel))
                        return false;
                    bool has_spell = false;
                    for (auto const& ispell: proto->Spells)
                    {
                        if (ispell.SpellId != 0)
                        {
                            if (SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(ispell.SpellId))
                            {
                                if (spellInfo->IsPassive())
                                    continue;
                                bool valid_effect = true;
                                for (uint8 i = EFFECT_0; i < MAX_SPELL_EFFECTS; ++i)
                                {
                                    SpellEffectInfo const& effect = spellInfo->GetEffect(SpellEffIndex(i));
                                    if (!effect.IsEffect())
                                        continue;
                                    if (effect.TargetA.GetTarget() != TARGET_UNIT_CASTER || effect.TargetB.GetTarget() != 0)
                                        valid_effect = false;
                                    else
                                    {
                                        switch (effect.Effect)
                                        {
                                            case SPELL_EFFECT_SUMMON:
                                            case SPELL_EFFECT_CREATE_ITEM:
                                                valid_effect = false;
                                                break;
                                            default:
                                                break;
                                        }
                                    }
                                }
                                if (!valid_effect)
                                    continue;
                                has_spell = true;
                            }
                        }
                    }
                    return has_spell;
                }
                return false;
            };

            for (uint8 i = INVENTORY_SLOT_ITEM_START; i != INVENTORY_SLOT_ITEM_END; ++i)
            {
                item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, i);
                if (is_consumable_item(item, me))
                {
                    std::ostringstream name;
                    _AddItemLink(player, item, name);
                    AddGossipItemFor(player, GOSSIP_ICON_CHAT, name.str().c_str(), GOSSIP_SENDER_USEITEM_USE, GOSSIP_ACTION_INFO_DEF + item->GetGUID().GetCounter());
                    ++counter; //no need to check max counter here
                }
            }

            for (uint8 i = INVENTORY_SLOT_BAG_START; i != INVENTORY_SLOT_BAG_END; ++i)
            {
                if (Bag const* pBag = player->GetBagByPos(i))
                {
                    for (uint32 j = 0; j != pBag->GetBagSize() && counter < maxcounter; ++j)
                    {
                        item = player->GetItemByPos(i, j);
                        if (is_consumable_item(item, me))
                        {
                            std::ostringstream name;
                            _AddItemLink(player, item, name);
                            AddGossipItemFor(player, GOSSIP_ICON_CHAT, name.str().c_str(), GOSSIP_SENDER_USEITEM_USE, GOSSIP_ACTION_INFO_DEF + item->GetGUID().GetCounter());
                            ++counter;
                        }
                    }
                }
            }

            AddGossipItemFor(player, GOSSIP_ICON_CHAT, LocalizedNpcText(player, BOT_TEXT_UPDATE), sender, action);
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, LocalizedNpcText(player, BOT_TEXT_BACK), 1, GOSSIP_ACTION_INFO_DEF + 1);

            break;
        }
        case GOSSIP_SENDER_HIRE:
        {
            int32 reason = action - GOSSIP_ACTION_INFO_DEF;
            if (!reason)
            {
                if (_ownerGuid)
                {
                    //std::ostringstream ostr;
                    //std::string name;
                    //ostr << "Go away. I serve my master ";
                    //if (sCharacterCache->GetCharacterNameByGuid(ObjectGuid(HighGuid::Player, _ownerGuid), name))
                    //    ostr << name;
                    //else
                    //    ostr << "unknown (" << _ownerGuid << ')';
                    //BotWhisper(ostr.str().c_str(), player);
                    ChatHandler ch(player->GetSession());
                    ch.PSendSysMessage(LocalizedNpcText(player, BOT_TEXT_HIREFAIL_OWNED).c_str(), me->GetName().c_str());
                    break;
                }

                uint8 minlvl = BotDataMgr::GetMinLevelForBotClass(_botclass);
                if (player->GetLevel() < minlvl)
                {
                    ChatHandler ch(player->GetSession());
                    uint32 locStringId;
                    switch (minlvl)
                    {
                        case 55: locStringId = BOT_TEXT_HIREFAIL_LVL55; break;
                        case 20: locStringId = BOT_TEXT_HIREFAIL_LVL20; break;
                        case 40: locStringId = BOT_TEXT_HIREFAIL_LVL40; break;
                        case 60: locStringId = BOT_TEXT_HIREFAIL_LVL60; break;
                        default:
                            TC_LOG_ERROR("scripts", "No message exists for min class level {}!", uint32(minlvl));
                            locStringId = BOT_TEXT_HIREFAIL_LVL60;
                            break;
                    }
                    switch (_botclass)
                    {
                        case BOT_CLASS_DEATH_KNIGHT:
                            BotWhisper(LocalizedNpcText(player, BOT_TEXT_HIREDENY_DK), player);
                            break;
                        case BOT_CLASS_SPHYNX:
                            me->TextEmote((me->GetName() + LocalizedNpcText(player, BOT_TEXT_HIREDENY_SPHYNX)).c_str());
                            break;
                        case BOT_CLASS_ARCHMAGE:
                            BotWhisper(LocalizedNpcText(player, BOT_TEXT_HIREDENY_ARCHMAGE), player);
                            break;
                    }
                    ch.PSendSysMessage(LocalizedNpcText(player, locStringId).c_str(), me->GetName().c_str());
                    break;
                }

                if (uint32 maxBotsPerAccount = BotMgr::GetMaxAccountBots())
                {
                    uint32 accountBotsCount = BotDataMgr::GetAccountBotsCount(player->GetSession()->GetAccountId());
                    if (accountBotsCount >= maxBotsPerAccount)
                    {
                        ChatHandler ch(player->GetSession());
                        ch.PSendSysMessage(LocalizedNpcText(player, BOT_TEXT_HIREFAIL_MAXBOTS_ACCOUNT).c_str(), accountBotsCount, maxBotsPerAccount);
                        break;
                    }
                }

                if (SetBotOwner(player))
                {
                    if (_botclass == BOT_CLASS_SPHYNX)
                    {
                        std::string msg1 = me->GetName() + LocalizedNpcText(player, BOT_TEXT_HIRE_EMOTE_SPHYNX) + player->GetName();
                        me->TextEmote(msg1.c_str());
                    }
                    else
                        BotWhisper(LocalizedNpcText(player, BOT_TEXT_HIRE_SUCCESS), player);
                }
                else
                    BotSay("...", player);
            }
            else if (reason == -1)
            {
                me->SetFaction(14);
                if (botPet)
                    botPet->SetFaction(14);
                BotYell(LocalizedNpcText(player, BOT_TEXT_DIE), player);
                me->Attack(player, true);
                break;
            }
            else
            {
                ChatHandler ch(player->GetSession());
                switch (reason)
                {
                    case 1: //has owner
                    {
                        std::ostringstream ostr;
                        std::string name;
                        ostr << LocalizedNpcText(player, BOT_TEXT_HIREDENY_MY_MASTER_IS_);
                        if (sCharacterCache->GetCharacterNameByGuid(ObjectGuid(HighGuid::Player, _ownerGuid), name))
                            ostr << name;
                        else
                            ostr << LocalizedNpcText(player, BOT_TEXT_UNKNOWN) + " (" << _ownerGuid << ')';
                        BotWhisper(ostr.str().c_str(), player);
                        ch.PSendSysMessage(LocalizedNpcText(player, BOT_TEXT_HIREFAIL_OWNED).c_str(), me->GetName().c_str());
                        break;
                    }
                    case 2: //max npcbots exceed
                        ch.PSendSysMessage(LocalizedNpcText(player, BOT_TEXT_HIREFAIL_MAXBOTS).c_str(), BotMgr::GetMaxNpcBots(player->GetLevel()));
                        BotSay("...", player);
                        break;
                    case 3: //not enough money
                    {
                        std::string str = LocalizedNpcText(player, BOT_TEXT_HIREFAIL_COST) + " (";
                        str += BotMgr::GetNpcBotCostStr(player->GetLevel(), _botclass);
                        str += ")!";
                        ch.SendSysMessage(str.c_str());
                        player->SendBuyError(BUY_ERR_NOT_ENOUGHT_MONEY, 0, 0, 0);
                        BotSay("...", player);
                        break;
                    }
                    case 4: //class bots exceed
                    {
                        uint8 count = 0;
                        BotMap const* map = player->GetBotMgr()->GetBotMap();
                        for (BotMap::const_iterator itr = map->begin(); itr != map->end(); ++itr)
                            if (itr->second->GetBotClass() == GetBotClass())
                                ++count;

                        ch.PSendSysMessage(LocalizedNpcText(player, BOT_TEXT_HIREFAIL_MAXCLASSBOTS).c_str(), count, BotMgr::GetMaxClassBots());
                        BotSay("...", player);
                        break;
                    }
                    default:
                        break;
                }
            }
            break;
        }
        case GOSSIP_SENDER_DISMISS:
        {
            BotMgr* mgr = player->GetBotMgr();
            ASSERT(mgr);

            //send items to owner -- Unequip all
            bool abort = false;
            for (uint8 i = BOT_SLOT_MAINHAND; i != BOT_INVENTORY_SIZE; ++i)
            {
                if (!(i <= BOT_SLOT_RANGED ? _resetEquipment(i, player->GetGUID()) : _unequip(i, player->GetGUID())))
                {
                    ChatHandler ch(player->GetSession());
                    ch.PSendSysMessage(LocalizedNpcText(player, BOT_TEXT_CANT_DISMISS_EQUIPMENT).c_str(),
                        uint32(i), LocalizedNpcText(player, BOT_TEXT_SLOT_MH + i).c_str());
                    abort = true;
                    break;
                }
            }

            if (abort)
                break;

            mgr->RemoveBot(me->GetGUID(), BOT_REMOVE_DISMISS);
            if (BotMgr::IsEnrageOnDimissEnabled())
            {
                if (Aura* bers = me->AddAura(BERSERK, me))
                {
                    uint32 dur = 5 * MINUTE * IN_MILLISECONDS;
                    bers->SetDuration(dur);
                    bers->SetMaxDuration(dur);
                }
            }
            //if (urand(1,100) <= 25)
            //{
            //    me->SetFaction(14);
            //    if (Creature* pet = GetBotsPet())
            //        pet->SetFaction(14);
            //    BotSay("Fool...", player);
            //    me->Attack(player, true);
            //}
            //else
                BotSay("...", player);

            break;
        }
        case GOSSIP_SENDER_JOIN_GROUP:
        {
            uint32 option = action - GOSSIP_ACTION_INFO_DEF;
            switch (option)
            {
                case 1: //single bot
                    player->GetBotMgr()->AddBotToGroup(me);
                    break;
                case 2: //all bots
                {
                    BotMap const* bmap = player->GetBotMgr()->GetBotMap();
                    for (BotMap::const_iterator citr = bmap->begin(); citr != bmap->end(); ++citr)
                    {
                        if (!citr->second)
                            continue;
                        player->GetBotMgr()->AddBotToGroup(citr->second);
                    }
                    break;
                }
            }
            break;
        }
        case GOSSIP_SENDER_LEAVE_GROUP:
        {
            player->GetBotMgr()->RemoveBotFromGroup(me);
            break;
        }
        case GOSSIP_SENDER_HOLDPOSITION:
        {
            SetBotCommandState(BOT_COMMAND_STAY);
            //BotWhisper("Standing still");
            break;
        }
        case GOSSIP_SENDER_DONOTHING:
        {
            SetBotCommandState(BOT_COMMAND_FULLSTOP);
            //BotWhisper("As you wish");
            break;
        }
        case GOSSIP_SENDER_FOLLOWME:
        {
            SetBotCommandState(BOT_COMMAND_FOLLOW, true);
            //BotWhisper("Following");
            break;
        }
        case GOSSIP_SENDER_FORMATION_TOGGLE_COMBAT_POSITIONING:
        {
            player->GetBotMgr()->SetBotAllowCombatPositioning(!player->GetBotMgr()->GetBotAllowCombatPositioning());

            //break; //return to menu
        }
        [[fallthrough]];
        case GOSSIP_SENDER_FORMATION:
        {
            subMenu = true;
            std::ostringstream diststr;
            diststr << LocalizedNpcText(player, BOT_TEXT_FOLLOW_DISTANCE) << " (" << LocalizedNpcText(player, BOT_TEXT_CURRENT) << ": " << uint32(master->GetBotMgr()->GetBotFollowDist()) << ')';
            player->PlayerTalkClass->GetGossipMenu().AddMenuItem(-1, GOSSIP_ICON_CHAT, diststr.str(),
                GOSSIP_SENDER_FORMATION_FOLLOW_DISTANCE_SET, GOSSIP_ACTION_INFO_DEF + 1, "", 0, true);

            if (HasRole(BOT_ROLE_RANGED))
            {
                AddGossipItemFor(player, !player->GetBotMgr()->GetBotAllowCombatPositioning() ? GOSSIP_ICON_BATTLE : GOSSIP_ICON_CHAT,
                    LocalizedNpcText(player, BOT_TEXT_DISABLE_COMBAT_POSITIONING), GOSSIP_SENDER_FORMATION_TOGGLE_COMBAT_POSITIONING, GOSSIP_ACTION_INFO_DEF + 2);
                AddGossipItemFor(player, GOSSIP_ICON_TALK, LocalizedNpcText(player, BOT_TEXT_ATTACK_DISTANCE) + "...", GOSSIP_SENDER_FORMATION_ATTACK_DISTANCE, GOSSIP_ACTION_INFO_DEF + 3);
                AddGossipItemFor(player, GOSSIP_ICON_TALK, LocalizedNpcText(player, BOT_TEXT_ATTACK_ANGLE) + "...", GOSSIP_SENDER_FORMATION_ATTACK_ANGLE, GOSSIP_ACTION_INFO_DEF + 4);
            }

            if (!HasRole(BOT_ROLE_TANK) && HasRole(BOT_ROLE_DPS | BOT_ROLE_HEAL))
                AddGossipItemFor(player, GOSSIP_ICON_TALK, LocalizedNpcText(player, BOT_TEXT_ENGAGE_BEHAVIOR) + "...", GOSSIP_SENDER_ENGAGE_BEHAVIOR, GOSSIP_ACTION_INFO_DEF + 5);

            if (player->GetGroup())
            {
                for (uint32 role = BOT_ROLE_TANK; !!(role & BOT_ROLE_MASK_MAIN); role <<= 1)
                {
                    if (role & (BOT_ROLE_TANK | BOT_ROLE_DPS) && HasRole(role))
                        AddGossipItemFor(player, GOSSIP_ICON_TALK, LocalizedNpcText(player, BOT_TEXT_PRIORITY_TARGET) + " (" + LocalizedNpcText(player, GetRoleString(role)) + ")...", GOSSIP_SENDER_PRIORITY_TARGET, uint32(GOSSIP_ACTION_INFO_DEF) + role);
                }
            }

            AddGossipItemFor(player, GOSSIP_ICON_CHAT, LocalizedNpcText(player, BOT_TEXT_BACK), 1, GOSSIP_ACTION_INFO_DEF + 6);
            break;
        }
        case GOSSIP_SENDER_FORMATION_ATTACK_DISTANCE_SET:
        {
            uint32 choice = action - GOSSIP_ACTION_INFO_DEF;
            if (choice == 1) //short
            {
                player->GetBotMgr()->SetBotAttackRangeMode(BOT_ATTACK_RANGE_SHORT);
            }
            else if (choice == 2) //long
            {
                player->GetBotMgr()->SetBotAttackRangeMode(BOT_ATTACK_RANGE_LONG);
            }

            //break; //return to menu
        }
        [[fallthrough]];
        case GOSSIP_SENDER_FORMATION_ATTACK_DISTANCE:
        {
            subMenu = true;

            uint8 mode = master->GetBotMgr()->GetBotAttackRangeMode();
            AddGossipItemFor(player, mode == BOT_ATTACK_RANGE_SHORT ? GOSSIP_ICON_BATTLE : GOSSIP_ICON_CHAT, LocalizedNpcText(player, BOT_TEXT_SHORT_RANGE_ATTACKS), GOSSIP_SENDER_FORMATION_ATTACK_DISTANCE_SET, GOSSIP_ACTION_INFO_DEF + 1);
            AddGossipItemFor(player, mode == BOT_ATTACK_RANGE_LONG ? GOSSIP_ICON_BATTLE : GOSSIP_ICON_CHAT, LocalizedNpcText(player, BOT_TEXT_LONG_RANGE_ATTACKS), GOSSIP_SENDER_FORMATION_ATTACK_DISTANCE_SET, GOSSIP_ACTION_INFO_DEF + 2);

            std::ostringstream diststr;
            if (mode == BOT_ATTACK_RANGE_EXACT)
                diststr << LocalizedNpcText(player, BOT_TEXT_EXACT) << " (" << LocalizedNpcText(player, BOT_TEXT_CURRENT) << ": " << uint32(master->GetBotMgr()->GetBotExactAttackRange()) << ')';
            else
                diststr << LocalizedNpcText(player, BOT_TEXT_EXACT) << " (0-50)";
            player->PlayerTalkClass->GetGossipMenu().AddMenuItem(-1, mode == BOT_ATTACK_RANGE_EXACT ? GOSSIP_ICON_BATTLE : GOSSIP_ICON_CHAT,
                diststr.str(), GOSSIP_SENDER_FORMATION_ATTACK_DISTANCE_SET, GOSSIP_ACTION_INFO_DEF + 3, "", 0, true);

            AddGossipItemFor(player, GOSSIP_ICON_CHAT, LocalizedNpcText(player, BOT_TEXT_BACK), 1, GOSSIP_ACTION_INFO_DEF + 4);
            break;
        }
        case GOSSIP_SENDER_FORMATION_ATTACK_ANGLE_SET:
        {
            uint32 choice = action - GOSSIP_ACTION_INFO_DEF;
            if (choice == 1) //normal
            {
                player->GetBotMgr()->SetBotAttackAngleMode(BOT_ATTACK_ANGLE_NORMAL);
            }
            if (choice == 2) //avoid frontal aoe
            {
                player->GetBotMgr()->SetBotAttackAngleMode(BOT_ATTACK_ANGLE_AVOID_FRONTAL_AOE);
            }

            //break; //return to menu
        }
        [[fallthrough]];
        case GOSSIP_SENDER_FORMATION_ATTACK_ANGLE:
        {
            subMenu = true;

            uint8 mode = master->GetBotMgr()->GetBotAttackAngleMode();
            AddGossipItemFor(player, mode == BOT_ATTACK_ANGLE_NORMAL ? GOSSIP_ICON_BATTLE : GOSSIP_ICON_CHAT, LocalizedNpcText(player, BOT_TEXT_NORMAL), GOSSIP_SENDER_FORMATION_ATTACK_ANGLE_SET, GOSSIP_ACTION_INFO_DEF + 1);
            AddGossipItemFor(player, mode == BOT_ATTACK_ANGLE_AVOID_FRONTAL_AOE ? GOSSIP_ICON_BATTLE : GOSSIP_ICON_CHAT, LocalizedNpcText(player, BOT_TEXT_AVOID_FRONTAL_AOE), GOSSIP_SENDER_FORMATION_ATTACK_ANGLE_SET, GOSSIP_ACTION_INFO_DEF + 2);

            AddGossipItemFor(player, GOSSIP_ICON_CHAT, LocalizedNpcText(player, BOT_TEXT_BACK), 1, GOSSIP_ACTION_INFO_DEF + 3);
            break;
        }
        case GOSSIP_SENDER_ENGAGE_BEHAVIOR:
        {
            subMenu = true;

            if (HasRole(BOT_ROLE_DPS))
            {
                std::ostringstream delaystr;
                delaystr.setf(std::ios_base::fixed);
                delaystr.precision(2);
                delaystr << LocalizedNpcText(player, BOT_TEXT_DELAY_ATTACK_BY) << ": " << float(player->GetBotMgr()->GetEngageDelayDPS() / 1000.f) << LocalizedNpcText(player, BOT_TEXT_SECOND_SHORT);
                player->PlayerTalkClass->GetGossipMenu().AddMenuItem(-1, GOSSIP_ICON_CHAT, delaystr.str(),
                    GOSSIP_SENDER_ENGAGE_DELAY_SET_ATTACK, GOSSIP_ACTION_INFO_DEF + 1, "", 0, true);
            }
            if (HasRole(BOT_ROLE_HEAL))
            {
                std::ostringstream delaystr;
                delaystr.setf(std::ios_base::fixed);
                delaystr.precision(2);
                delaystr << LocalizedNpcText(player, BOT_TEXT_DELAY_HEALING_BY) << ": " << float(player->GetBotMgr()->GetEngageDelayHeal() / 1000.f) << LocalizedNpcText(player, BOT_TEXT_SECOND_SHORT);
                player->PlayerTalkClass->GetGossipMenu().AddMenuItem(-1, GOSSIP_ICON_CHAT, delaystr.str(), GOSSIP_SENDER_ENGAGE_DELAY_SET_HEALING, GOSSIP_ACTION_INFO_DEF + 2, "", 0, true);
                if (GetBotClass() != BOT_CLASS_SPHYNX)
                {
                    std::ostringstream thresholdstr;
                    thresholdstr << LocalizedNpcText(player, BOT_TEXT_HEAL_TARGET_HEALTH_THRESHOLD) << ": " << uint32(GetHealHpPctThreshold()) << "%";
                    player->PlayerTalkClass->GetGossipMenu().AddMenuItem(-1, GOSSIP_ICON_CHAT, thresholdstr.str(), GOSSIP_SENDER_HEAL_HEALTH_THRESHOLD_SET, GOSSIP_ACTION_INFO_DEF + 3, "", 0, true);
                }
            }

            AddGossipItemFor(player, GOSSIP_ICON_CHAT, LocalizedNpcText(player, BOT_TEXT_BACK), 1, GOSSIP_ACTION_INFO_DEF + 4);
            break;
        }
        case GOSSIP_SENDER_PRIORITY_TARGET_SET_TANK:
        case GOSSIP_SENDER_PRIORITY_TARGET_SET_DPS:
        {
            Group const* gr = player->GetGroup();
            if (!gr)
                break;

            uint32 role = sender - GOSSIP_SENDER_PRIORITY_TARGET;
            int8 icon = decltype(icon)(action - GOSSIP_ACTION_INFO_DEF);

            switch (role)
            {
                case BOT_ROLE_TANK:
                    _primaryIconTank = icon;
                    break;
                case BOT_ROLE_DPS:
                    _primaryIconDamage = icon;
                    break;
                default:
                    break;
            }

            //break;
            action = uint32(GOSSIP_ACTION_INFO_DEF) + role; //restore role value and return to the menu
        }
        [[fallthrough]];
        case GOSSIP_SENDER_PRIORITY_TARGET:
        {
            Group const* gr = player->GetGroup();
            if (!gr)
                break;

            subMenu = true;

            uint32 role = action - GOSSIP_ACTION_INFO_DEF;
            switch (role)
            {
                case BOT_ROLE_TANK:
                    for (int8 i = TARGET_ICONS_COUNT - 1; i >= 0; --i)
                    {
                        bool prio = i == _primaryIconTank;
                        ObjectGuid guid = gr->GetTargetIcons()[i];
                        if (guid && BotMgr::GetTankTargetIconFlags() & GroupIconsFlags[i])
                            AddGossipItemFor(player, prio ? GOSSIP_ICON_BATTLE : GOSSIP_ICON_CHAT, player->GetBotMgr()->GetTargetIconString(uint8(i)), GOSSIP_SENDER_PRIORITY_TARGET_SET_TANK, uint32(GOSSIP_ACTION_INFO_DEF) + uint32(i));
                    }
                    AddGossipItemFor(player, (_primaryIconTank == -1) ? GOSSIP_ICON_BATTLE : GOSSIP_ICON_CHAT, LocalizedNpcText(player, BOT_TEXT_NONE2), GOSSIP_SENDER_PRIORITY_TARGET_SET_TANK, uint32(GOSSIP_ACTION_INFO_DEF - 1));
                    break;
                case BOT_ROLE_DPS:
                    for (int8 i = TARGET_ICONS_COUNT - 1; i >= 0; --i)
                    {
                        bool prio = i == _primaryIconDamage;
                        ObjectGuid guid = gr->GetTargetIcons()[i];
                        uint32 iconMask = BotMgr::GetDPSTargetIconFlags();
                        if (HasRole(BOT_ROLE_RANGED))
                            iconMask |= BotMgr::GetRangedDPSTargetIconFlags();
                        if (guid && iconMask & GroupIconsFlags[i])
                            AddGossipItemFor(player, prio ? GOSSIP_ICON_BATTLE : GOSSIP_ICON_CHAT, player->GetBotMgr()->GetTargetIconString(uint8(i)), GOSSIP_SENDER_PRIORITY_TARGET_SET_DPS, uint32(GOSSIP_ACTION_INFO_DEF) + uint32(i));
                    }
                    AddGossipItemFor(player, (_primaryIconDamage == -1) ? GOSSIP_ICON_BATTLE : GOSSIP_ICON_CHAT, LocalizedNpcText(player, BOT_TEXT_NONE2), GOSSIP_SENDER_PRIORITY_TARGET_SET_DPS, uint32(GOSSIP_ACTION_INFO_DEF - 1));
                    break;
                default:
                    BotWhisper("unknown role " + std::to_string(role));
                    break;
            }

            AddGossipItemFor(player, GOSSIP_ICON_CHAT, LocalizedNpcText(player, BOT_TEXT_BACK), 1, GOSSIP_ACTION_INFO_DEF + 3);
            break;
        }
        case GOSSIP_SENDER_TROUBLESHOOTING_AURA:
        {
            uint32 spellId = action - GOSSIP_ACTION_INFO_DEF;
            Unit::AuraMap const& auras = me->GetOwnedAuras();
            for (Unit::AuraMap::const_iterator itr = auras.begin(); itr != auras.end(); ++itr)
            {
                if (itr->first != spellId)
                    continue;

                SpellInfo const* info = itr->second->GetSpellInfo();
                if (info->IsChanneled())
                    if (Spell const* curSpell = me->GetCurrentSpell(CURRENT_CHANNELED_SPELL))
                        if (curSpell->m_spellInfo->Id == spellId)
                            me->InterruptSpell(CURRENT_CHANNELED_SPELL);

                //Debug
                //std::ostringstream msg;
                //msg << "Removing ";
                //_AddSpellLink(player, info, msg);
                //msg << " by ";
                //ObjectGuid casterGuid = itr->second->GetCasterGUID();
                //Unit* caster = casterGuid ? ObjectAccessor::GetUnit(*me, casterGuid) : nullptr;
                //if (caster)
                //{
                //    if (casterGuid == me->GetGUID())
                //        msg << "me";
                //    else
                //        msg << caster->GetName();
                //}
                //else
                //    msg << "Unknown unit";
                //BotWhisper(msg.str().c_str());

                me->RemoveOwnedAura(spellId, ObjectGuid::Empty, 0, AURA_REMOVE_BY_CANCEL);
                break;
            }

            //break;
            action = GOSSIP_ACTION_INFO_DEF + 2; //return to the list and update
        }
        [[fallthrough]];
        case GOSSIP_SENDER_TROUBLESHOOTING_FIX:
        {
            uint32 option = action - GOSSIP_ACTION_INFO_DEF;
            switch (option)
            {
                //MOVED TO RECEIVEEMOTE
                //case 1: //Bot is not mounting, not following while player is mounted
                //{
                //    //Reason: creature can sometimes retain UNIT_FLAG_X and UNIT_STATE_X
                //    //rare occasion, even for bots, you can still talk to them so yeah, stange
                //    if (me->HasUnitState(UNIT_STATE_STUNNED) && !me->HasAuraType(SPELL_AURA_MOD_STUN))
                //    {
                //        me->ClearUnitState(UNIT_STATE_STUNNED);
                //        me->RemoveUnitFlag(UNIT_FLAG_STUNNED);
                //    }
                //    if (me->HasUnitState(UNIT_STATE_CONFUSED) && !me->HasAuraType(SPELL_AURA_MOD_CONFUSE))
                //    {
                //        me->ClearUnitState(UNIT_STATE_CONFUSED);
                //        me->RemoveUnitFlag(UNIT_FLAG_CONFUSED);
                //    }
                //    break;
                //}
                case 2: //Remove a visible buff
                {
                    subMenu = true;
                    uint32 count = 0;
                    Unit::AuraMap const& auras = me->GetOwnedAuras();
                    for (Unit::AuraMap::const_iterator itr = auras.begin(); itr != auras.end(); ++itr)
                    {
                        SpellInfo const* info = itr->second->GetSpellInfo();
                        //spells we cannot remove
                        //1 passive, negative spells, hidden, locked, shapeshift / mount spells (no hook for that)
                        if (info->IsPassive() || !info->IsPositive())
                            continue;
                        if ((info->Attributes & (SPELL_ATTR0_CANT_CANCEL | SPELL_ATTR0_HIDDEN_CLIENTSIDE)) ||
                            (info->AttributesEx & SPELL_ATTR1_DONT_DISPLAY_IN_AURA_BAR))
                            continue;
                        if (info->HasAura(SPELL_AURA_MOD_SHAPESHIFT))
                            continue;
                        if (info->HasAura(SPELL_AURA_MOUNTED) && player->HasAura(info->Id))
                            continue;
                        //2 custom list
                        //2.1 Leader of the Pack AOE (supposed to be passive)
                        if (info->Id == 24932)
                            continue;
                        //2.2 Tree of Life AOE (supposed to be passive)
                        if (info->Id == 34123)
                            continue;
                        //2.3 Moonkin Aura AOE (supposed to be passive)
                        if (info->Id == 24907)
                            continue;
                        //2.4 Blood Pact AOE (supposed to be passive)
                        if (info->GetFirstRankSpell()->Id == 6307)
                            continue;
                        //2.5 Fel Intelligence AOE (supposed to be passive)
                        if (info->GetFirstRankSpell()->Id == 54424)
                            continue;

                        std::ostringstream msg;
                        _AddSpellLink(player, info, msg);
                        AddGossipItemFor(player, GOSSIP_ICON_CHAT, msg.str().c_str(), GOSSIP_SENDER_TROUBLESHOOTING_AURA, GOSSIP_ACTION_INFO_DEF + itr->first);

                        if (++count >= BOT_GOSSIP_MAX_ITEMS - 2) //update, back
                            break;
                    }

                    AddGossipItemFor(player, GOSSIP_ICON_CHAT, LocalizedNpcText(player, BOT_TEXT_UPDATE), sender, action);
                    AddGossipItemFor(player, GOSSIP_ICON_CHAT, LocalizedNpcText(player, BOT_TEXT_BACK), 1, GOSSIP_ACTION_INFO_DEF + 1);
                    break;
                }
                case 3: //Fix Powers
                {
                    InitPowers();
                    break;
                }
                default:
                    //BotWhisper("Unknown action in GOSSIP_SENDER_TROUBLESHOOTING_FIX", player);
                    break;
            }
            break;
        }
        case GOSSIP_SENDER_TROUBLESHOOTING:
        {
            subMenu = true;
            //AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Fix not mounting/following", GOSSIP_SENDER_TROUBLESHOOTING_FIX, GOSSIP_ACTION_INFO_DEF + 1);
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, LocalizedNpcText(player, BOT_TEXT_REMOVE_BUFF) + "...", GOSSIP_SENDER_TROUBLESHOOTING_FIX, GOSSIP_ACTION_INFO_DEF + 2);
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, LocalizedNpcText(player, BOT_TEXT_FIX_POWER), GOSSIP_SENDER_TROUBLESHOOTING_FIX, GOSSIP_ACTION_INFO_DEF + 3);
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, LocalizedNpcText(player, BOT_TEXT_BACK), 1, GOSSIP_ACTION_INFO_DEF + 4);
            break;
        }
        case GOSSIP_SENDER_DEBUG_ACTION:
        {
            //!!! player != owner !!!
            //DEBUG ACTIONS ARE NOT LOCALIZED
            bool close = true;
            switch (action - GOSSIP_ACTION_INFO_DEF)
            {
                case 1: //reset owner
                    if (!IAmFree())
                        master->GetBotMgr()->RemoveBot(me->GetGUID(), BOT_REMOVE_DISMISS);
                    else
                    {
                        uint32 newOwner = 0;
                        BotDataMgr::UpdateNpcBotData(me->GetEntry(), NPCBOT_UPDATE_OWNER, &newOwner);
                        ResetBotAI(BOTAI_RESET_DISMISS);
                    }
                    break;
                case 2: //reset stats
                    spawned = false;
                    DefaultInit();
                    break;
                case 3: //list stats
                    close = false;
                    ReceiveEmote(player, TEXT_EMOTE_BONK);
                    break;
                case 4: //list roles
                {
                    close = false;
                    ChatHandler ch(player->GetSession());
                    ch.PSendSysMessage("%s's Roles:", me->GetName().c_str());
                    for (uint32 i = BOT_MAX_ROLE; i != BOT_ROLE_NONE; i >>= 1)
                    {
                        if (_roleMask & i)
                        {
                            switch (i)
                            {
                                case BOT_ROLE_TANK:
                                    ch.SendSysMessage("BOT_ROLE_TANK");
                                    break;
                                case BOT_ROLE_TANK_OFF:
                                    ch.SendSysMessage("BOT_ROLE_TANK_OFF");
                                    break;
                                case BOT_ROLE_DPS:
                                    ch.SendSysMessage("BOT_ROLE_DPS");
                                    break;
                                case BOT_ROLE_HEAL:
                                    ch.SendSysMessage("BOT_ROLE_HEAL");
                                    break;
                                //case BOT_ROLE_MELEE:
                                //    ch.SendSysMessage("BOT_ROLE_MELEE");
                                //    break;
                                case BOT_ROLE_RANGED:
                                    ch.SendSysMessage("BOT_ROLE_RANGED");
                                    break;
                                case BOT_ROLE_PARTY:
                                    ch.SendSysMessage("BOT_ROLE_PARTY");
                                    break;
                                default:
                                    ch.PSendSysMessage("BOT_ROLE_%u",i);
                                    break;
                            }
                        }
                    }
                    break;
                }
                case 5: //list spells
                {
                    close = false;
                    ChatHandler ch(player->GetSession());
                    ch.PSendSysMessage("%s's Spells:", me->GetName().c_str());
                    uint32 counter = 0;
                    SpellInfo const* spellInfo;
                    BotSpellMap const& myspells = GetSpellMap();
                    for (BotSpellMap::const_iterator itr = myspells.begin(); itr != myspells.end(); ++itr)
                    {
                        //if (itr->second->spellId == 0)
                        //    continue;

                        ++counter;
                        std::ostringstream sstr;
                        spellInfo = sSpellMgr->GetSpellInfo(itr->first); //always valid
                        _AddSpellLink(player, spellInfo, sstr);
                        sstr << " id: " <<  itr->second->spellId << ", base: " << itr->first
                            << ", cd: " << itr->second->cooldown << ", base: " << std::max<uint32>(spellInfo->RecoveryTime, spellInfo->CategoryRecoveryTime);
                        if (itr->second->enabled == false)
                            sstr << " (disabled)";
                        ch.PSendSysMessage("%u) %s", counter, sstr.str().c_str());
                    }
                    break;
                }
                case 6: //reload config
                {
                    close = false;
                    ChatHandler ch(player->GetSession());

                    TC_LOG_INFO("misc", "Re-Loading config settings...");
                    sWorld->LoadConfigSettings(true);
                    sMapMgr->InitializeVisibilityDistanceInfo();
                    ch.SendGlobalGMSysMessage("World config settings reloaded.");
                    BotMgr::ReloadConfig();
                    ch.SendGlobalGMSysMessage("NpcBot config settings reloaded.");

                    break;
                }
                default:
                    close = false;
                    break;
            }

            if (close)
                break;
        }
        [[fallthrough]];
        case GOSSIP_SENDER_DEBUG:
        {
            //!!! player != owner !!!
            subMenu = true;

            std::ostringstream ostr;
            std::string name;
            ostr << "Bot: " << me->GetName()
                << " (Id: " << me->GetEntry()
                << ", guidlow: " << me->GetGUID().GetCounter()
                << ", spec: " << uint32(_spec) << '(' << LocalizedNpcText(player, TextForSpec(_spec)) << ')'
                << ", faction: " << me->GetFaction()
                << "). owner: ";
            if (_ownerGuid && sCharacterCache->GetCharacterNameByGuid(ObjectGuid(HighGuid::Player, _ownerGuid), name))
                ostr << name << " (" << _ownerGuid << ')';
            else
                ostr << "none";

            AddGossipItemFor(player, GOSSIP_ICON_CHAT, ostr.str().c_str(), GOSSIP_SENDER_DEBUG_ACTION, GOSSIP_ACTION_INFO_DEF + 0);

            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "<Reset Owner>", GOSSIP_SENDER_DEBUG_ACTION, GOSSIP_ACTION_INFO_DEF + 1);
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "<Reset Stats>", GOSSIP_SENDER_DEBUG_ACTION, GOSSIP_ACTION_INFO_DEF + 2);
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "<List Stats>", GOSSIP_SENDER_DEBUG_ACTION, GOSSIP_ACTION_INFO_DEF + 3);
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "<List Roles>", GOSSIP_SENDER_DEBUG_ACTION, GOSSIP_ACTION_INFO_DEF + 4);
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "<List Spells>", GOSSIP_SENDER_DEBUG_ACTION, GOSSIP_ACTION_INFO_DEF + 5);
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "<List Items>", GOSSIP_SENDER_EQUIPMENT_LIST, GOSSIP_ACTION_INFO_DEF + 1);
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "<Reload Config>", GOSSIP_SENDER_DEBUG_ACTION, GOSSIP_ACTION_INFO_DEF + 6);

            AddGossipItemFor(player, GOSSIP_ICON_CHAT, LocalizedNpcText(player, BOT_TEXT_BACK), 1, GOSSIP_ACTION_INFO_DEF + 1);
            break;
        }
        case GOSSIP_SENDER_SCAN:
        {
            subMenu = true;

            switch (_botclass)
            {
                case BOT_CLASS_BM:
                    gossipTextId = GOSSIP_CLASSDESC_BM;
                    break;
                case BOT_CLASS_SPHYNX:
                    gossipTextId = GOSSIP_CLASSDESC_SPHYNX;
                    break;
                case BOT_CLASS_ARCHMAGE:
                    gossipTextId = GOSSIP_CLASSDESC_ARCHMAGE;
                    break;
                case BOT_CLASS_DREADLORD:
                    gossipTextId = GOSSIP_CLASSDESC_DREADLORD;
                    break;
                case BOT_CLASS_SPELLBREAKER:
                    gossipTextId = GOSSIP_CLASSDESC_SPELLBREAKER;
                    break;
                case BOT_CLASS_DARK_RANGER:
                    gossipTextId = GOSSIP_CLASSDESC_DARKRANGER;
                    break;
                case BOT_CLASS_NECROMANCER:
                    gossipTextId = GOSSIP_CLASSDESC_NECROMANCER;
                    break;
                case BOT_CLASS_SEA_WITCH:
                    gossipTextId = GOSSIP_CLASSDESC_SEAWITCH;
                    break;
                case BOT_CLASS_CRYPT_LORD:
                    gossipTextId = GOSSIP_CLASSDESC_CRYPTLORD;
                    break;
                default:
                    break;
            }

            //AddGossipItemFor(player, GOSSIP_ICON_CHAT, LocalizedNpcText(player, BOT_TEXT_BACK), 1, GOSSIP_ACTION_INFO_DEF + 1);

            break;
        }
        default:
            break;
    }

    //if we add submenus send them else we should return
    if (subMenu)
        player->PlayerTalkClass->SendGossipMenu(gossipTextId, me->GetGUID());
    else
        player->PlayerTalkClass->SendCloseGossip();

    return true;
}

//GossipSelectCode
bool bot_ai::OnGossipSelectCode(Player* player, Creature* creature/* == me*/, uint32 sender, uint32 action, char const* code)
{
    if (!*code)
        return true;

    if (!BotMgr::IsNpcBotModEnabled() || me->HasUnitState(UNIT_STATE_CASTING) || CCed(me) || IsDuringTeleport() ||
        HasBotCommandState(BOT_COMMAND_ISSUED_ORDER) ||
        (me->GetVehicle() && me->GetVehicle()->GetBase()->IsInCombat()))
    {
        player->PlayerTalkClass->SendCloseGossip();
        return true;
    }

    uint32 gossipTextId;
    if (player->GetGUID().GetCounter() == _ownerGuid || !IAmFree())
    {
        if (_botclass == BOT_CLASS_SPHYNX)
            gossipTextId = GOSSIP_NORMAL_CUSTOM_SPHYNX;
        else if (_botclass == BOT_CLASS_DREADLORD)
            gossipTextId = GOSSIP_NORMAL_CUSTOM_DREADLORD;
        else if (_botclass == BOT_CLASS_DARK_RANGER)
            gossipTextId = GOSSIP_NORMAL_CUSTOM_DARKRANGER;
        else if (_botclass == BOT_CLASS_SEA_WITCH)
            gossipTextId = GOSSIP_NORMAL_CUSTOM_SEAWITCH;
        else if (_botclass == BOT_CLASS_CRYPT_LORD)
            gossipTextId = GOSSIP_NORMAL_CUSTOM_CRYPTLORD;
        else
            gossipTextId = GOSSIP_NORMAL_SERVE_MASTER;
    }
    else
    {
        if (_botclass == BOT_CLASS_SPHYNX)
            gossipTextId = GOSSIP_GREET_CUSTOM_SPHYNX;
        else if (_botclass == BOT_CLASS_DREADLORD)
            gossipTextId = GOSSIP_GREET_CUSTOM_DREADLORD;
        else if (_botclass == BOT_CLASS_DARK_RANGER)
            gossipTextId = GOSSIP_GREET_CUSTOM_DARKRANGER;
        else if (_botclass == BOT_CLASS_SEA_WITCH)
            gossipTextId = GOSSIP_GREET_CUSTOM_SEAWITCH;
        else if (_botclass == BOT_CLASS_CRYPT_LORD)
            gossipTextId = GOSSIP_GREET_CUSTOM_CRYPTLORD;
        else
            gossipTextId = GOSSIP_GREET_NEED_SMTH;
    }

    player->PlayerTalkClass->ClearMenus();

    bool subMenu = false;

    switch (sender)
    {
        case GOSSIP_SENDER_FORMATION_FOLLOW_DISTANCE_SET:
        {
            char* dist = strtok((char*)code, "");
            uint8 distance = (uint8)std::min<int32>(std::max<int32>(atoi(dist), 0), 100);

            player->GetBotMgr()->SetBotFollowDist(distance);

            player->PlayerTalkClass->SendCloseGossip();
            return OnGossipSelect(player, creature, GOSSIP_SENDER_FORMATION, action);
        }
        case GOSSIP_SENDER_FORMATION_ATTACK_DISTANCE_SET:
        {
            uint32 choice = action - GOSSIP_ACTION_INFO_DEF;
            if (choice == 3) //exact
            {
                char* dist = strtok((char*)code, "");
                uint8 distance = (uint8)std::min<int32>(std::max<int32>(atoi(dist), 0), 50);

                player->GetBotMgr()->SetBotAttackRangeMode(BOT_ATTACK_RANGE_EXACT, distance);
            }

            player->PlayerTalkClass->SendCloseGossip();
            return OnGossipSelect(player, creature, GOSSIP_SENDER_FORMATION_ATTACK_DISTANCE, action);
        }
        case GOSSIP_SENDER_ENGAGE_DELAY_SET_ATTACK:
        {
            char* dist = strtok((char*)code, "");
            float delay = std::min<float>(std::max<float>(atof(dist), 0.f), 10.f);

            player->GetBotMgr()->SetEngageDelayDPS(uint32(delay * 1000));

            player->PlayerTalkClass->SendCloseGossip();
            return OnGossipSelect(player, creature, GOSSIP_SENDER_ENGAGE_BEHAVIOR, action);
        }
        case GOSSIP_SENDER_ENGAGE_DELAY_SET_HEALING:
        {
            char* dist = strtok((char*)code, "");
            float delay = std::min<float>(std::max<float>(atof(dist), 0.f), 10.f);

            player->GetBotMgr()->SetEngageDelayHeal(uint32(delay * 1000));

            player->PlayerTalkClass->SendCloseGossip();
            return OnGossipSelect(player, creature, GOSSIP_SENDER_ENGAGE_BEHAVIOR, action);
        }
        case GOSSIP_SENDER_HEAL_HEALTH_THRESHOLD_SET:
        {
            char* dist = strtok((char*)code, "");
            float threshold = std::min<float>(std::max<float>(atof(dist), 0.f), 99.f);

            SetHealHpPctThreshold(uint8(threshold));

            player->PlayerTalkClass->SendCloseGossip();
            return OnGossipSelect(player, creature, GOSSIP_SENDER_ENGAGE_BEHAVIOR, action);
        }
        default:
            break;
    }

    if (subMenu)
        player->PlayerTalkClass->SendGossipMenu(gossipTextId, me->GetGUID());
    else
        player->PlayerTalkClass->SendCloseGossip();

    return true;
}
//PvP trinket for minions
void bot_ai::BreakCC(uint32 diff)
{
    if (_botclass < BOT_CLASS_EX_START && me->GetLevel() >= 60 && IsSpellReady(PVPTRINKET, diff, false) &&
        CCed(me, true) && (me->GetVictim() || !me->getAttackers().empty()) && Rand() < 20)
    {
        if (doCast(me, PVPTRINKET))
            return;
    }

    uint8 myrace = me->GetRace();

    //Racial 6) Every Man for Himself
    if (myrace == RACE_HUMAN && IsSpellReady(RACIAL_EVERY_MAN_FOR_HIMSELF, diff, false) && CCed(me, true) &&
        !me->HasAuraType(SPELL_AURA_MOD_STEALTH) &&
        (me->IsInCombat() || !me->getAttackers().empty()) && Rand() < 40 && !IsCasting() &&
        (me->GetLevel() < 60 || !IsSpellReady(PVPTRINKET, diff, false)))
    {
        if (doCast(me, RACIAL_EVERY_MAN_FOR_HIMSELF))
            return;
    }
    //Racial 5) Forsaken (Will of the Forsaken)
    if (myrace == RACE_UNDEAD_PLAYER && IsSpellReady(RACIAL_WILL_OF_THE_FORSAKEN, diff, false) &&
        (me->IsInCombat() || !me->getAttackers().empty()) && CCed(me) &&
        Rand() < 10 && !me->HasAuraType(SPELL_AURA_MOD_STEALTH) && !IsCasting() &&
        (me->GetLevel() < 60 || !IsSpellReady(PVPTRINKET, diff, false)) &&
        me->HasAuraWithMechanic((1<<MECHANIC_CHARM)|(1<<MECHANIC_FEAR)|(1<<MECHANIC_SLEEP)))
    {
        if (doCast(me, RACIAL_WILL_OF_THE_FORSAKEN))
            return;
    }
    //Racial 7) Escape Artist
    if (me->GetRace() == RACE_GNOME && IsSpellReady(RACIAL_ESCAPE_ARTIST, diff, false) && CCed(me, true) &&
        !me->HasAuraType(SPELL_AURA_MOD_STEALTH) &&
        (me->IsInCombat() || !me->getAttackers().empty()) && Rand() < 40 && !IsCasting() &&
        (me->GetLevel() < 60 || !IsSpellReady(PVPTRINKET, diff, false)) &&
        me->HasAuraWithMechanic((1<<MECHANIC_SNARE)|(1<<MECHANIC_ROOT)))
    {
        if (doCast(me, RACIAL_ESCAPE_ARTIST))
            return;
    }
}
//Racial abilities
void bot_ai::CheckRacials(uint32 diff)
{
    //At this point checked CCed and pots
    uint8 myrace = me->GetRace();
    //Racial 1) Tauren (War Stomp)
    if (myrace == RACE_TAUREN && IsSpellReady(RACIAL_WARSTOMP, diff, false) &&
        (!IsTank() || me->GetShapeshiftForm() == FORM_NONE) &&
        Rand() < 20 && !me->HasAuraType(SPELL_AURA_MOD_STEALTH) && !IsCasting())
    {
        Unit const* u = me->SelectNearestTarget(7);
        if (u && u->IsInCombat() && !CCed(u) && u->isTargetableForAttack(false) && IsInBotParty(u->GetVictim()) && me->IsWithinLOSInMap(u))
        {
            if (doCast(me, RACIAL_WARSTOMP))
                return;
        }
    }
    //Racial 2) Orc (Blood Fury)
    if (myrace == RACE_ORC)
    {
        uint32 bloodFury = RaceSpellForClass(myrace, _botclass);
        if (IsSpellReady(bloodFury, diff, false) && me->GetVictim() && GetHealthPCT(me) > 35 && !CCed(me, true) &&
            (me->GetVictim()->GetHealth() > me->GetMaxHealth() / 2 || me->getAttackers().size() > 1) &&
            Rand() < 20 && !me->HasAuraType(SPELL_AURA_MOD_STEALTH) && !IsCasting())
        {
            if (doCast(me, bloodFury))
                return;
        }
    }
    //Racial 3) Dwarf (Stoneform)
    if (myrace == RACE_DWARF && IsSpellReady(RACIAL_STONEFORM, diff, false) && GetHealthPCT(me) < 80 &&
        Rand() < 10 && !me->HasAuraType(SPELL_AURA_MOD_STEALTH) && !IsCasting())
    {
        //Unholy Blight prevents diseases from being dispelled
        uint32 const dispelMask = me->GetAuraEffect(SPELL_AURA_PERIODIC_DAMAGE, SPELLFAMILY_DEATHKNIGHT, 1494, 0) ?
            (1<<DISPEL_POISON) : (1<<DISPEL_DISEASE)|(1<<DISPEL_POISON);
        uint8 count = 0;
        Unit::AuraMap const& auras = me->GetOwnedAuras();
        for (Unit::AuraMap::const_iterator itr = auras.begin(); itr != auras.end(); ++itr)
        {
            Aura const* aura = itr->second;

            if (aura->IsPassive())
                continue;

            AuraApplication const* aurApp = aura->GetApplicationOfTarget(me->GetGUID());
            if (!aurApp)
                continue;
            if (aurApp->IsPositive())
                continue;

            if ((aura->GetSpellInfo()->GetDispelMask() & dispelMask) ||
                aura->GetSpellInfo()->Mechanic == MECHANIC_BLEED)
                if (++count > 1)
                    break;
        }

        if (count > 1 - 1*(me->IsInCombat()) && doCast(me, RACIAL_STONEFORM))
            return;
    }
    //Racial 4) Night Elf (Shadowmeld)
    if (myrace == RACE_NIGHTELF && IsSpellReady(RACIAL_SHADOWMELD, diff, false) && !me->IsInCombat() && me->GetVictim() &&
        me->GetVictim()->GetTypeId() == TYPEID_PLAYER && Rand() < 50 &&
        !me->HasAuraType(SPELL_AURA_MOD_STEALTH) && !IsCasting())
    {
        if (Spell const* spell = me->GetVictim()->GetCurrentSpell(CURRENT_GENERIC_SPELL))
        {
            if (spell->m_targets.GetUnitTarget() == me && spell->GetTimer() < 500 &&
                spell->GetSpellInfo()->HasEffect(SPELL_EFFECT_SCHOOL_DAMAGE))
                if (doCast(me, RACIAL_SHADOWMELD))
                    return;
        }
    }
    //Racial 8) Troll (Berserking)
    if (myrace == RACE_TROLL && IsSpellReady(RACIAL_BERSERKING, diff, false) && me->GetVictim() &&
        GetHealthPCT(me) > 35 && !CCed(me, true) &&
        (me->GetVictim()->GetHealth() > me->GetMaxHealth() / 2 || me->getAttackers().size() > 1) &&
        Rand() < 20 && !me->HasAuraType(SPELL_AURA_MOD_STEALTH) && !IsCasting())
    {
        if (doCast(me, RACIAL_BERSERKING))
            return;
    }
    //Racial 9) Blood Elf (Arcane Torrent)
    if (myrace == RACE_BLOODELF)
    {
        uint32 arcaneTorrent = RaceSpellForClass(myrace, _botclass);
        if (IsSpellReady(arcaneTorrent, diff, false) && !IsCasting() && !Feasting())
        {
            Unit const* victim = me->GetVictim();
            if (victim && victim->IsNonMeleeSpellCast(false, false, true) &&
                (me->GetVictim()->GetHealth() > me->GetHealth() / 4 || me->getAttackers().size() > 1) &&
                me->GetDistance(victim) < 7 && Rand() < 30 && !me->HasAuraType(SPELL_AURA_MOD_STEALTH))
            {
                if (Spell const* spell = victim->GetCurrentSpell(CURRENT_GENERIC_SPELL))
                {
                    if (IsInBotParty(spell->m_targets.GetUnitTargetGUID()) && spell->GetTimer() < 1000)
                        if (doCast(me, arcaneTorrent))
                            return;
                }
            }
            else if (GetManaPCT(me) < 25)
                if (doCast(me, arcaneTorrent))
                    return;
        }
    }
    //Racial 10) Draenei (Gift of The Naaru) - self only
    if (myrace == RACE_DRAENEI)
    {
        uint32 giftOfNaaru = RaceSpellForClass(myrace, _botclass);
        if (IsSpellReady(giftOfNaaru, diff, false) && (me->IsInCombat() || !me->getAttackers().empty()) &&
            GetHealthPCT(me) < 60 - 10*me->HasAuraType(SPELL_AURA_PERIODIC_HEAL) &&
            Rand() < 50 && !IsCasting())
        {
            if (doCast(me, giftOfNaaru))
                return;
        }
    }
}
//Force bots to start attack anyone who tries to DAMAGE me or master
//This means that anyone who attacks party will be attacked by whole bot party (see GetTarget())
void bot_ai::OnOwnerDamagedBy(Unit* attacker)
{
    if (HasBotCommandState(BOT_COMMAND_FULLSTOP | BOT_COMMAND_INACTION))
        return;

    bool byspell = false;
    switch (_botclass)
    {
        case BOT_CLASS_DRUID:
            byspell = GetBotStance() == BOT_STANCE_NONE || GetBotStance() == DRUID_MOONKIN_FORM;
            break;
        case BOT_CLASS_PRIEST:
        case BOT_CLASS_MAGE:
        case BOT_CLASS_WARLOCK:
        case BOT_CLASS_SHAMAN:
        case BOT_CLASS_SPHYNX:
        case BOT_CLASS_ARCHMAGE:
            byspell = true;
            break;
        default:
            //TC_LOG_ERROR("entities.player", "minion_ai: OnOwnerDamagedBy() - unknown bot class {}", uint8(_botclass));
            break;
    }

    if (!_canSwitchToTarget(me->GetVictim(), attacker, byspell))
        return;

    SetBotCommandState(BOT_COMMAND_COMBATRESET); //reset AttackStart()
    me->Attack(attacker, !HasRole(BOT_ROLE_RANGED));
}
//force vehicle targeting and attack if vehicle is damaged
void bot_ai::OnOwnerVehicleDamagedBy(Unit* attacker)
{
    if (HasBotCommandState(BOT_COMMAND_FULLSTOP | BOT_COMMAND_INACTION))
        return;

    Creature* veh = me->GetVehicleCreatureBase();
    if (!veh || (veh->GetTarget() && HasBotCommandState(BOT_COMMAND_ATTACK)) || !veh->IsValidAttackTarget(attacker))
        return;

    veh->SetTarget(attacker->GetGUID());
    SetBotCommandState(BOT_COMMAND_ATTACK);
    me->GetVehicleBase()->Attack(attacker, false);
}
//////////
///LOOT///
//////////
void bot_ai::SpawnKillReward(Player* looter) const
{
    ASSERT(IsWanderer());

    if (!me->GetMap()->GetEntry()->IsContinent())
        return;

    QuaternionData rotation = QuaternionData::fromEulerAnglesZYX(looter->GetOrientation(), 0.f, 0.f);
    GameObject* moneyBag = looter->SummonGameObject(GO_BOT_MONEY_BAG, *me, rotation, std::chrono::duration_cast<Seconds>(Milliseconds(REVIVE_TIMER_DEFAULT)));
    moneyBag->SetSpellId(GO_BOT_MONEY_BAG + me->GetEntry());
}
void bot_ai::FillKillReward(GameObject* go) const
{
    static const uint32 MAX_KILL_REWARD_ITEMS = 2;

    ASSERT(IsWanderer());
    ASSERT(go->GetEntry() == GO_BOT_MONEY_BAG);
    ASSERT((go->GetSpellId() - go->GetEntry()) == me->GetEntry());

    go->SetObjectScale(0.875f);

    Loot& loot = go->loot;

    loot.clear();
    loot.loot_type = LOOT_CORPSE;

    //gold
    float lvl = float(std::min<uint8>(me->GetLevel(), DEFAULT_MAX_LEVEL));
    float gold = 125.0f;
    switch (me->GetLevel() / 10)
    {
        case 0: gold *= 0.100f; break;
        case 1: gold *= 0.125f; break;
        case 2: gold *= 0.175f; break;
        case 3: gold *= 0.225f; break;
        case 4: gold *= 0.300f; break;
        case 5: gold *= 0.400f; break;
        case 6: gold *= 0.550f; break;
        case 7: gold *= 0.750f; break;
        default:gold *= 1.000f; break;
    }

    loot.gold = uint32(lvl * std::min<float>(std::max<float>(gold + _killsCount * gold * 0.04f - _deathsCount * gold * 0.4f, gold), gold * 10.0f));

    //items
    uint32 loot_items_count = 0;
    for (Item const* item : _equips)
    {
        if (item)
        {
            ItemTemplate const* proto = item->GetTemplate();
            if (proto->Quality == ITEM_QUALITY_UNCOMMON || proto->Quality == ITEM_QUALITY_RARE)
            {
                if (roll_chance_f(5.0f))
                {
                    loot.AddItem(LootStoreItem(proto->ItemId, 0, 100.0f, false, 0, 0, 1, 1));

                    if (++loot_items_count >= std::min<uint32>(MAX_KILL_REWARD_ITEMS, MAX_NR_LOOT_ITEMS))
                        break;
                }
            }
        }
    }
}
uint32 bot_ai::_getLootQualityMask() const
{
    uint32 lootRoleMask = (_roleMask & BOT_ROLE_MASK_LOOTING);
    uint32 lootMask = 0;

    if (lootRoleMask & BOT_ROLE_AUTOLOOT_POOR)
        lootMask |= (1 << ITEM_QUALITY_POOR);
    if (lootRoleMask & BOT_ROLE_AUTOLOOT_COMMON)
        lootMask |= (1 << ITEM_QUALITY_NORMAL);
    if (lootRoleMask & BOT_ROLE_AUTOLOOT_UNCOMMON)
        lootMask |= (1 << ITEM_QUALITY_UNCOMMON);
    if (lootRoleMask & BOT_ROLE_AUTOLOOT_RARE)
        lootMask |= (1 << ITEM_QUALITY_RARE);
    if (lootRoleMask & BOT_ROLE_AUTOLOOT_EPIC)
        lootMask |= (1 << ITEM_QUALITY_EPIC);
    if (lootRoleMask & BOT_ROLE_AUTOLOOT_LEGENDARY)
        lootMask |= (1 << ITEM_QUALITY_LEGENDARY);

    return lootMask;
}
uint32 bot_ai::_getLootQualityThreshold() const
{
    uint32 lootThreshold;
    Group const* gr = master->GetGroup();
    if (!gr)
        lootThreshold = uint32(MAX_ITEM_QUALITY);
    else
    {
        switch (gr->GetLootMethod())
        {
            case GROUP_LOOT: case NEED_BEFORE_GREED: case MASTER_LOOT:
                lootThreshold = uint32(gr->GetLootThreshold()); break;
            default:
                lootThreshold = uint32(MAX_ITEM_QUALITY);       break;
        }
    }

    return lootThreshold;
}
bool bot_ai::_canLootItemForPlayer(Player* player, Creature* creature, uint8 slot) const
{
    NotNormalLootItem* qitem = nullptr;
    NotNormalLootItem* ffaitem = nullptr;
    NotNormalLootItem* conditem = nullptr;

    LootItem const* item = creature->loot.LootItemInSlot(slot, player, &qitem, &ffaitem, &conditem);
    if (!item || item->is_looted)
    {
        //TC_LOG_ERROR("scripts", "can't loot item {}, no item", slot);
        return false;
    }

    if (!qitem && item->is_blocked)
    {
        //TC_LOG_ERROR("scripts", "can't loot item {} ({}), blocked", slot, item->itemid);
        return false;
    }

    if (!item->rollWinnerGUID.IsEmpty() && item->rollWinnerGUID != player->GetGUID())
    {
        //TC_LOG_ERROR("scripts", "can't loot item {} ({}), roll won", slot, item->itemid);
        return false;
    }

    ItemPosCountVec dest;
    if (player->CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, item->itemid, item->count) == EQUIP_ERR_OK)
        return true;

    //TC_LOG_ERROR("scripts", "can't loot item {} ({}), can't store", slot, item->itemid);
    return false;
}
bool bot_ai::_canLootCreatureForPlayer(Player* player, Creature* creature, uint32 lootQualityMask, uint32 lootThreshold) const
{
    if (!player || master->GetMap() != player->FindMap()/* || !player->IsAlive() || !p->IsAtGroupRewardDistance(creature)*/)
        return false;

    bool canLoot = false;
    uint8 slot = 0;
    for (std::vector<LootItem>::const_iterator i = creature->loot.items.begin(); i != creature->loot.items.end(); ++i)
    {
        ++slot;

        if (i->is_blocked || i->is_looted)
        {
            //TC_LOG_ERROR("scripts", "item {} is blocked", i->itemid);
            continue;
        }

        if (!i->rollWinnerGUID.IsEmpty() && i->rollWinnerGUID != player->GetGUID())
        {
            //TC_LOG_ERROR("scripts", "can't loot item {} ({}), roll won", slot, i->itemid);
            continue;
        }

        ItemTemplate const* itemProto = sObjectMgr->GetItemTemplate(i->itemid);
        if (!itemProto)
        {
            //TC_LOG_ERROR("scripts", "no item proto for itemId {}", i->itemid);
            return false;
        }

        if (itemProto->Quality >= lootThreshold)
        {
            //TC_LOG_ERROR("scripts", "item {} group quality threshold mismatch", i->itemid);
            continue;
        }

        if (!((1 << itemProto->Quality) & lootQualityMask))
        {
            //TC_LOG_ERROR("scripts", "item {} lootQualityMask mismatch", i->itemid);
            continue;
        }

        if (_canLootItemForPlayer(player, creature, slot - 1) && i->AllowedForPlayer(player))
        {
            canLoot = true;
            break;
        }
    }
    if (!canLoot)
    {
        NotNormalLootItemMap const& lootPlayerQuestItems = creature->loot.GetPlayerQuestItems();
        NotNormalLootItemMap::const_iterator q_itr = lootPlayerQuestItems.find(player->GetGUID());
        if (q_itr != lootPlayerQuestItems.end())
        {
            NotNormalLootItemList* q_list = q_itr->second;
            for (NotNormalLootItemList::const_iterator qi = q_list->begin(); qi != q_list->end(); ++qi)
            {
                LootItem* i = &creature->loot.quest_items[qi->index];
                if (i->is_looted || qi->is_looted)
                {
                    //TC_LOG_ERROR("scripts", "item {} is looted", i->itemid);
                    continue;
                }

                if (!i->rollWinnerGUID.IsEmpty() && i->rollWinnerGUID != player->GetGUID())
                {
                    //TC_LOG_ERROR("scripts", "can't loot item {} ({}), roll won", slot, i->itemid);
                    continue;
                }

                ItemTemplate const* itemProto = sObjectMgr->GetItemTemplate(i->itemid);

                if (itemProto->Quality >= lootThreshold)
                {
                    //TC_LOG_ERROR("scripts", "item {} group quality threshold mismatch", i->itemid);
                    continue;
                }

                if (!((1 << itemProto->Quality) & lootQualityMask))
                {
                    //TC_LOG_ERROR("scripts", "item {} lootQualityMask mismatch", i->itemid);
                    continue;
                }

                uint8 qslot = uint8(creature->loot.items.size() + (qi - q_list->begin()));

                if (_canLootItemForPlayer(player, creature, qslot) && i->AllowedForPlayer(player))
                {
                    canLoot = true;
                    break;
                }
            }
        }
    }

    return canLoot;
}
bool bot_ai::_canLootCreature(Creature* creature) const
{
    Loot* loot = &creature->loot;

    if (loot->gold)
        return true;

    uint32 lootQualityMask = _getLootQualityMask();
    uint32 lootThreshold = _getLootQualityThreshold();
    //TC_LOG_ERROR("scripts", "lootQualityMask {}, lootThreshold {}", lootQualityMask, lootThreshold);
    bool canLootQuality = false;

    //std::vector<LootItem> const& lootItems = loot->quest_items;
    for (std::vector<LootItem>::const_iterator ci = loot->quest_items.begin(); ci != loot->quest_items.end(); ++ci)
    {
        ItemTemplate const* itemProto = sObjectMgr->GetItemTemplate(ci->itemid);
        if (!itemProto)
        {
            //TC_LOG_ERROR("scripts", "no item proto for itemId {}", ci->itemid);
            return false;
        }

        if (itemProto->Quality >= lootThreshold)
        {
            //TC_LOG_ERROR("scripts", "item {} group quality threshold mismatch", i->itemid);
            continue;
        }

        if ((1 << itemProto->Quality) & lootQualityMask)
        {
            canLootQuality = true;
            break;
        }
    }
    if (!canLootQuality)
    {
        for (std::vector<LootItem>::const_iterator ci = loot->items.begin(); ci != loot->items.end(); ++ci)
        {
            ItemTemplate const* itemProto = sObjectMgr->GetItemTemplate(ci->itemid);
            if (!itemProto)
            {
                //TC_LOG_ERROR("scripts", "no item proto for itemId {}", ci->itemid);
                return false;
            }

            if (itemProto->Quality >= lootThreshold)
            {
                //TC_LOG_ERROR("scripts", "item {} group quality threshold mismatch", i->itemid);
                continue;
            }

            if ((1 << itemProto->Quality) & lootQualityMask)
            {
                canLootQuality = true;
                break;
            }
        }
    }

    if (!canLootQuality)
    {
        //TC_LOG_ERROR("scripts", "can't loot by quality");
        return false;
    }

    bool canLootPlayers = false;

    Group const* gr = master->GetGroup();
    if (!gr)
        canLootPlayers = _canLootCreatureForPlayer(master, creature, lootQualityMask, lootThreshold);
    else
    {
        for (GroupReference const* itr = gr->GetFirstMember(); itr != nullptr; itr = itr->next())
        {
            if (_canLootCreatureForPlayer(itr->GetSource(), creature, lootQualityMask, lootThreshold))
            {
                canLootPlayers = true;
                break;
            }
        }
    }

    if (!canLootPlayers)
    {
        //TC_LOG_ERROR("scripts", "can't loot by canLootPlayers");
        return false;
    }

    return true;
}
void bot_ai::_autoLootCreatureGold(Creature* creature) const
{
    Loot* loot = &creature->loot;

    //sScriptMgr->OnBeforeLootMoney(master, loot);
    loot->NotifyMoneyRemoved();
    Group const* gr = master->GetGroup();
    if (!gr)
    {
        master->ModifyMoney(loot->gold);
        master->UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_LOOT_MONEY, loot->gold);

        WorldPacket data(SMSG_LOOT_MONEY_NOTIFY, 4 + 1);
        data << uint32(loot->gold);
        data << uint8(1);   // "You loot..."
        master->GetSession()->SendPacket(&data);
    }
    else
    {
        std::vector<Player*> players;
        for (GroupReference const* itr = gr->GetFirstMember(); itr != nullptr; itr = itr->next())
        {
            Player* p = itr->GetSource();
            if (p && p->IsAtGroupRewardDistance(creature))
                players.push_back(p);
        }

        uint32 goldPerPlayer = uint32(loot->gold / uint32(players.size()));

        for (std::vector<Player*>::const_iterator i = players.begin(); i != players.end(); ++i)
        {
            (*i)->ModifyMoney(goldPerPlayer);
            (*i)->UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_LOOT_MONEY, goldPerPlayer);

            WorldPacket data(SMSG_LOOT_MONEY_NOTIFY, 4 + 1);
            data << uint32(goldPerPlayer);
            data << uint8(players.size() <= 1); // Controls the text displayed in chat. 0 is "Your share is..." and 1 is "You loot..."
            (*i)->SendDirectMessage(&data);
        }
    }

    loot->gold = 0;

    if (loot->isLooted())
    {
        //TC_LOG_ERROR("scripts", "creature gold is looted, releasing");
        creature->AllLootRemovedFromCorpse();
        creature->RemoveDynamicFlag(UNIT_DYNFLAG_LOOTABLE);
        loot->clear();
    }
}
void bot_ai::_autoLootCreatureItems(Player* receiver, Creature* creature, uint32 lootQualityMask, uint32 lootThreshold) const
{
    uint8 slot = 0;
    for (std::vector<LootItem>::iterator i = creature->loot.items.begin(); i != creature->loot.items.end(); ++i)
    {
        ++slot;

        if (i->is_blocked || i->is_looted)
        {
            //TC_LOG_ERROR("scripts", "item {} is blocked", i->itemid);
            continue;
        }

        if (!i->rollWinnerGUID.IsEmpty() && i->rollWinnerGUID != receiver->GetGUID())
        {
            //TC_LOG_ERROR("scripts", "can't loot item {} ({}), roll won", slot, i->itemid);
            continue;
        }

        ItemTemplate const* itemProto = sObjectMgr->GetItemTemplate(i->itemid);

        if (itemProto->Quality >= lootThreshold)
            continue;
        if (!((1 << itemProto->Quality) & lootQualityMask))
            continue;

        if (_canLootItemForPlayer(receiver, creature, slot - 1) && i->AllowedForPlayer(receiver))
        {
            //TC_LOG_ERROR("scripts", "looting {} ({}), quality {}, threshold {}",
            //    itemProto->Name1, itemProto->ItemId, itemProto->Quality, lootThreshold);
            receiver->StoreLootItem(slot - 1, &creature->loot);
        }
    }

    NotNormalLootItemMap const& lootPlayerQuestItems = creature->loot.GetPlayerQuestItems();
    NotNormalLootItemMap::const_iterator q_itr = lootPlayerQuestItems.find(receiver->GetGUID());
    if (q_itr != lootPlayerQuestItems.end())
    {
        NotNormalLootItemList* q_list = q_itr->second;
        for (NotNormalLootItemList::const_iterator qi = q_list->begin(); qi != q_list->end(); ++qi)
        {
            LootItem* i = &creature->loot.quest_items[qi->index];
            if (i->is_looted || qi->is_looted)
            {
                //TC_LOG_ERROR("scripts", "item {} is looted", i->itemid);
                continue;
            }

            if (!i->rollWinnerGUID.IsEmpty() && i->rollWinnerGUID != receiver->GetGUID())
            {
                //TC_LOG_ERROR("scripts", "can't loot item {} ({}), roll won", slot, i->itemid);
                continue;
            }

            ItemTemplate const* itemProto = sObjectMgr->GetItemTemplate(i->itemid);

            if (itemProto->Quality >= lootThreshold)
                continue;
            if (!((1 << itemProto->Quality) & lootQualityMask))
                continue;

            //if (!receiver->HasQuestForItem(i->itemid))
            //    continue;

            uint8 qslot = uint8(creature->loot.items.size() + (qi - q_list->begin()));

            if (_canLootItemForPlayer(receiver, creature, qslot) && i->AllowedForPlayer(receiver))
                receiver->StoreLootItem(qslot, &creature->loot);
        }
    }
    if (creature->loot.isLooted())
    {
        //TC_LOG_ERROR("scripts", "creature items is looted, releasing");
        creature->AllLootRemovedFromCorpse();
        creature->RemoveDynamicFlag(UNIT_DYNFLAG_LOOTABLE);
        creature->loot.clear();
    }
}
void bot_ai::_autoLootCreature(Creature* creature)
{
    //money
    if (creature->loot.gold)
    {
        _autoLootCreatureGold(creature);

        //nothing but gold was there
        if (creature->loot.empty())
            return;
    }

    //items
    uint32 lootQualityMask = _getLootQualityMask();
    uint32 lootThreshold = _getLootQualityThreshold();

    std::set<Player*> pLooters;
    Group* gr = master->GetGroup();
    if (!gr)
    {
        if (_canLootCreatureForPlayer(master, creature, lootQualityMask, lootThreshold))
            pLooters.insert(master);
    }
    else
    {
        for (GroupReference const* itr = gr->GetFirstMember(); itr != nullptr; itr = itr->next())
        {
            if (_canLootCreatureForPlayer(itr->GetSource(), creature, lootQualityMask, lootThreshold))
                pLooters.insert(itr->GetSource());
        }
    }

    //creature->lootForBody = true;

    if (gr && creature->loot.loot_type == LOOT_NONE)
    {
        switch (gr->GetLootMethod())
        {
            case GROUP_LOOT:        gr->GroupLoot(&creature->loot, creature);       break;
            case NEED_BEFORE_GREED: gr->NeedBeforeGreed(&creature->loot, creature); break;
            case MASTER_LOOT:       gr->MasterLoot(&creature->loot, creature);      break;
            default:                                                                break;
        }
    }

    if (creature->loot.loot_type != LOOT_SKINNING)
        creature->loot.loot_type = LOOT_CORPSE;

    Player* receiver = pLooters.size() == 1 ? *pLooters.begin() :
        creature->loot.roundRobinPlayer ? ObjectAccessor::GetPlayer(*creature, creature->loot.roundRobinPlayer) : nullptr;

    if (!receiver)
    {
        if (pLooters.empty())
            return;

        ASSERT(pLooters.size() >= 2);

        do
        {
            receiver = Trinity::Containers::SelectRandomContainerElement(pLooters);
        } while (receiver == _prevRRobin);
    }

    _prevRRobin = receiver;

    _autoLootCreatureItems(receiver, creature, lootQualityMask, lootThreshold);
}
//////////
//EQUIPS//
//////////
bool bot_ai::_canUseOffHand() const
{
    //bm can on only equip in main hand
    if (_botclass == BOT_CLASS_BM)
        return false;
    //sphynx can grab anything
    if (_botclass == BOT_CLASS_SPHYNX)
        return true;
    //dreadlord / cryptlord can on only equip in main hand
    if (_botclass == BOT_CLASS_DREADLORD || _botclass == BOT_CLASS_CRYPT_LORD)
        return false;
    //staff-only classes
    if (_botclass == BOT_CLASS_ARCHMAGE || _botclass == BOT_CLASS_NECROMANCER)
        return false;

    //warrior can wield any offhand with titan's grip
    if (_botclass == BOT_CLASS_WARRIOR && me->GetLevel() >= 60 && GetSpec() == BOT_SPEC_WARRIOR_FURY)
        return true;

    ItemTemplate const* protoMH = _equips[BOT_SLOT_MAINHAND] ? _equips[BOT_SLOT_MAINHAND]->GetTemplate() : nullptr;

    //no mainhand weapon OR
    //mainhand is an one-hand weapon
    if (!protoMH)
        return true;

    if (protoMH->Class == ITEM_CLASS_WEAPON &&
        (protoMH->InventoryType == INVTYPE_WEAPON || protoMH->InventoryType == INVTYPE_WEAPONMAINHAND) &&
        (protoMH->SubClass == ITEM_SUBCLASS_WEAPON_AXE || protoMH->SubClass == ITEM_SUBCLASS_WEAPON_DAGGER ||
        protoMH->SubClass == ITEM_SUBCLASS_WEAPON_FIST_WEAPON || protoMH->SubClass == ITEM_SUBCLASS_WEAPON_MACE ||
        protoMH->SubClass == ITEM_SUBCLASS_WEAPON_SWORD))
        return true;

    //NO
    return false;
}

bool bot_ai::_canUseRanged() const
{
    return (_botclass == BOT_CLASS_HUNTER || _botclass == BOT_CLASS_ROGUE ||
        _botclass == BOT_CLASS_WARRIOR || _botclass == BOT_CLASS_PRIEST ||
        _botclass == BOT_CLASS_MAGE || _botclass == BOT_CLASS_WARLOCK ||
        _botclass == BOT_CLASS_DARK_RANGER || _botclass == BOT_CLASS_SEA_WITCH);
}

bool bot_ai::_canUseRelic() const
{
    return (_botclass == BOT_CLASS_PALADIN || _botclass == BOT_CLASS_SHAMAN ||
        _botclass == BOT_CLASS_DRUID || _botclass == BOT_CLASS_DEATH_KNIGHT);
}

bool bot_ai::_canEquip(ItemTemplate const* newProto, uint8 slot, bool ignoreItemLevel, Item const* newItem) const
{
    EquipmentInfo const* einfo = BotDataMgr::GetBotEquipmentInfo(me->GetEntry());

    if (Item const* oldItem = _equips[slot])
    {
        ItemTemplate const* oldProto = oldItem->GetTemplate();
        //prevent reequipping same items
        if (newProto->ItemId == oldProto->ItemId && (!newItem || !newItem->GetItemRandomPropertyId()))
            return false;
        //prevent equipping worse items (only standard or not)
        if (!ignoreItemLevel)
            if (slot > BOT_SLOT_RANGED || einfo->ItemEntry[slot] != oldProto->ItemId)
                if (IAmFree() || !master->IsGameMaster())
                    if (_getItemGearStatScore(oldProto, slot, oldItem) > _getItemGearStatScore(newProto, slot, newItem))
                        return false;
    }

    if (slot == BOT_SLOT_OFFHAND && !_canUseOffHand())
        return false;

    //level requirements
    if (me->GetLevel() < newProto->RequiredLevel)
        return false;

    //class requirements
    if (_botclass < BOT_CLASS_EX_START && !(newProto->AllowableClass & (1<<(_botclass-1))))
        return false;

    //skip race requirements

    //inventory related conditions
    if (newProto->Class == ITEM_CLASS_WEAPON)
    {
        switch (slot)
        {
            case BOT_SLOT_MAINHAND:
                switch (_botclass)
                {
                    case BOT_CLASS_BM:
                        if (newProto->SubClass != ITEM_SUBCLASS_WEAPON_POLEARM &&
                            newProto->SubClass != ITEM_SUBCLASS_WEAPON_AXE2 &&
                            newProto->SubClass != ITEM_SUBCLASS_WEAPON_SWORD2)
                            return false;
                        break;
                    case BOT_CLASS_ARCHMAGE:
                    case BOT_CLASS_NECROMANCER:
                        if (newProto->SubClass != ITEM_SUBCLASS_WEAPON_STAFF)
                            return false;
                        break;
                    default:
                        break;
                }
                break;
            case BOT_SLOT_OFFHAND:
                if (newProto->SubClass == ITEM_SUBCLASS_WEAPON_POLEARM || newProto->SubClass == ITEM_SUBCLASS_WEAPON_STAFF)
                    return false;
                switch (_botclass)
                {
                    case BOT_CLASS_DEATH_KNIGHT:
                    case BOT_CLASS_ROGUE:
                        break;
                    case BOT_CLASS_WARRIOR:
                    case BOT_CLASS_HUNTER:
                        if (me->GetLevel() < 20)
                            return false;
                        break;
                    case BOT_CLASS_SHAMAN:
                        if (me->GetLevel() < 40 || _spec != BOT_SPEC_SHAMAN_ENHANCEMENT)
                            return false;
                        break;
                    case BOT_CLASS_SPHYNX:
                        break;
                    case BOT_CLASS_DARK_RANGER:
                        break;
                    case BOT_CLASS_SEA_WITCH:
                        break;
                    default:
                        return false;
                }
                break;
            case BOT_SLOT_RANGED:
                if (!_canUseRanged())
                    return false;
                break;
            default:
                return false;
        }

        switch (newProto->InventoryType)
        {
            case INVTYPE_WEAPONMAINHAND:
                if (slot != BOT_SLOT_MAINHAND)
                    return false;
                break;
            case INVTYPE_WEAPONOFFHAND:
                if (slot != BOT_SLOT_OFFHAND)
                    return false;
                break;
            case INVTYPE_2HWEAPON:
                switch (_botclass)
                {
                    case BOT_CLASS_WARRIOR:
                        switch (slot)
                        {
                            case BOT_SLOT_OFFHAND:
                                if (me->GetLevel() < 60)
                                    return false;
                                break;
                            case BOT_SLOT_RANGED:
                                return false;
                            default:
                                break;
                        }
                        break;
                    case BOT_CLASS_SPHYNX:
                        break;
                    default:
                        if (slot != BOT_SLOT_MAINHAND)
                            return false;
                        break;
                }
                break;
            case INVTYPE_WEAPON:
                if (slot != BOT_SLOT_MAINHAND && slot != BOT_SLOT_OFFHAND)
                    return false;
                break;
            case INVTYPE_THROWN:
            case INVTYPE_RANGED:
                if (slot != BOT_SLOT_RANGED)
                    return false;
                break;
            case INVTYPE_RANGEDRIGHT:
                switch (_botclass)
                {
                    case BOT_CLASS_SPHYNX:
                        if (slot != BOT_SLOT_MAINHAND && slot != BOT_SLOT_OFFHAND)
                            return false;
                        break;
                    default:
                        if (slot != BOT_SLOT_RANGED)
                            return false;
                        break;
                }
                break;
            default:
                return false;
        }

        switch (_botclass)
        {
            case BOT_CLASS_WARRIOR:
                switch (newProto->SubClass)
                {
                    case ITEM_SUBCLASS_WEAPON_AXE:
                    case ITEM_SUBCLASS_WEAPON_AXE2:
                    case ITEM_SUBCLASS_WEAPON_MACE:
                    case ITEM_SUBCLASS_WEAPON_MACE2:
                    case ITEM_SUBCLASS_WEAPON_SWORD:
                    case ITEM_SUBCLASS_WEAPON_SWORD2:
                    case ITEM_SUBCLASS_WEAPON_POLEARM:
                    case ITEM_SUBCLASS_WEAPON_STAFF:
                    case ITEM_SUBCLASS_WEAPON_FIST_WEAPON:
                    case ITEM_SUBCLASS_WEAPON_DAGGER:
                    case ITEM_SUBCLASS_WEAPON_BOW:
                    case ITEM_SUBCLASS_WEAPON_CROSSBOW:
                    case ITEM_SUBCLASS_WEAPON_GUN:
                    case ITEM_SUBCLASS_WEAPON_THROWN:
                    //case ITEM_SUBCLASS_WEAPON_WAND:
                        break;
                    default:
                        return false;
                }
                break;
            case BOT_CLASS_PALADIN:
            case BOT_CLASS_DEATH_KNIGHT:
                switch (newProto->SubClass)
                {
                    case ITEM_SUBCLASS_WEAPON_AXE:
                    case ITEM_SUBCLASS_WEAPON_AXE2:
                    case ITEM_SUBCLASS_WEAPON_MACE:
                    case ITEM_SUBCLASS_WEAPON_MACE2:
                    case ITEM_SUBCLASS_WEAPON_SWORD:
                    case ITEM_SUBCLASS_WEAPON_SWORD2:
                    case ITEM_SUBCLASS_WEAPON_POLEARM:
                        break;
                    default:
                        return false;
                }
                break;
            case BOT_CLASS_HUNTER:
                switch (newProto->SubClass)
                {
                    case ITEM_SUBCLASS_WEAPON_AXE:
                    case ITEM_SUBCLASS_WEAPON_AXE2:
                    //case ITEM_SUBCLASS_WEAPON_MACE:
                    //case ITEM_SUBCLASS_WEAPON_MACE2:
                    case ITEM_SUBCLASS_WEAPON_SWORD:
                    case ITEM_SUBCLASS_WEAPON_SWORD2:
                    case ITEM_SUBCLASS_WEAPON_POLEARM:
                    case ITEM_SUBCLASS_WEAPON_STAFF:
                    case ITEM_SUBCLASS_WEAPON_FIST_WEAPON:
                    case ITEM_SUBCLASS_WEAPON_DAGGER:
                    case ITEM_SUBCLASS_WEAPON_BOW:
                    case ITEM_SUBCLASS_WEAPON_CROSSBOW:
                    case ITEM_SUBCLASS_WEAPON_GUN:
                    //case ITEM_SUBCLASS_WEAPON_THROWN: //hunters can use thrown but bots can't, also pointless
                        break;
                    default:
                        return false;
                }
                break;
            case BOT_CLASS_ROGUE:
                switch (newProto->SubClass)
                {
                    case ITEM_SUBCLASS_WEAPON_AXE:
                    case ITEM_SUBCLASS_WEAPON_MACE:
                    case ITEM_SUBCLASS_WEAPON_SWORD:
                    case ITEM_SUBCLASS_WEAPON_FIST_WEAPON:
                    case ITEM_SUBCLASS_WEAPON_DAGGER:
                    case ITEM_SUBCLASS_WEAPON_BOW:
                    case ITEM_SUBCLASS_WEAPON_CROSSBOW:
                    case ITEM_SUBCLASS_WEAPON_GUN:
                    case ITEM_SUBCLASS_WEAPON_THROWN:
                        break;
                    default:
                        return false;
                }
                break;
            case BOT_CLASS_PRIEST:
                switch (newProto->SubClass)
                {
                    case ITEM_SUBCLASS_WEAPON_MACE:
                    case ITEM_SUBCLASS_WEAPON_STAFF:
                    case ITEM_SUBCLASS_WEAPON_DAGGER:
                    case ITEM_SUBCLASS_WEAPON_WAND:
                        break;
                    default:
                        return false;
                }
                break;
            case BOT_CLASS_MAGE:
            case BOT_CLASS_WARLOCK:
                switch (newProto->SubClass)
                {
                    case ITEM_SUBCLASS_WEAPON_SWORD:
                    case ITEM_SUBCLASS_WEAPON_STAFF:
                    case ITEM_SUBCLASS_WEAPON_DAGGER:
                    case ITEM_SUBCLASS_WEAPON_WAND:
                        break;
                    default:
                        return false;
                }
                break;
            case BOT_CLASS_DRUID:
                switch (newProto->SubClass)
                {
                    case ITEM_SUBCLASS_WEAPON_MACE:
                    case ITEM_SUBCLASS_WEAPON_MACE2:
                    case ITEM_SUBCLASS_WEAPON_POLEARM:
                    case ITEM_SUBCLASS_WEAPON_STAFF:
                    case ITEM_SUBCLASS_WEAPON_FIST_WEAPON:
                    case ITEM_SUBCLASS_WEAPON_DAGGER:
                        break;
                    default:
                        return false;
                }
                break;
            case BOT_CLASS_SHAMAN:
                switch (newProto->SubClass)
                {
                    case ITEM_SUBCLASS_WEAPON_AXE:
                    case ITEM_SUBCLASS_WEAPON_AXE2:
                    case ITEM_SUBCLASS_WEAPON_MACE:
                    case ITEM_SUBCLASS_WEAPON_MACE2:
                    case ITEM_SUBCLASS_WEAPON_STAFF:
                    case ITEM_SUBCLASS_WEAPON_FIST_WEAPON:
                    case ITEM_SUBCLASS_WEAPON_DAGGER:
                        break;
                    default:
                        return false;
                }
                break;
            case BOT_CLASS_BM:
                switch (newProto->SubClass)
                {
                    case ITEM_SUBCLASS_WEAPON_AXE2:
                    case ITEM_SUBCLASS_WEAPON_SWORD2:
                    case ITEM_SUBCLASS_WEAPON_POLEARM:
                        break;
                    default:
                        return false;
                }
                break;
            case BOT_CLASS_SPHYNX:
                switch (newProto->SubClass)
                {
                    case ITEM_SUBCLASS_WEAPON_WAND:
                        break;
                    default:
                        return false;
                }
                break;
            case BOT_CLASS_ARCHMAGE:
            case BOT_CLASS_NECROMANCER:
                switch (newProto->SubClass)
                {
                    case ITEM_SUBCLASS_WEAPON_STAFF:
                        break;
                    default:
                        return false;
                }
                break;
            case BOT_CLASS_DREADLORD:
            case BOT_CLASS_CRYPT_LORD:
                switch (newProto->SubClass)
                {
                    case ITEM_SUBCLASS_WEAPON_AXE:
                    case ITEM_SUBCLASS_WEAPON_AXE2:
                    case ITEM_SUBCLASS_WEAPON_MACE:
                    case ITEM_SUBCLASS_WEAPON_MACE2:
                    case ITEM_SUBCLASS_WEAPON_SWORD:
                    case ITEM_SUBCLASS_WEAPON_SWORD2:
                    case ITEM_SUBCLASS_WEAPON_POLEARM:
                    case ITEM_SUBCLASS_WEAPON_STAFF:
                    case ITEM_SUBCLASS_WEAPON_FIST_WEAPON:
                    case ITEM_SUBCLASS_WEAPON_DAGGER:
                        break;
                    default:
                        return false;
                }
                break;
            case BOT_CLASS_SPELLBREAKER:
                switch (newProto->SubClass)
                {
                    case ITEM_SUBCLASS_WEAPON_AXE:
                    case ITEM_SUBCLASS_WEAPON_MACE:
                    case ITEM_SUBCLASS_WEAPON_SWORD:
                    case ITEM_SUBCLASS_WEAPON_FIST_WEAPON:
                    case ITEM_SUBCLASS_WEAPON_DAGGER:
                        break;
                    default:
                        return false;
                }
                break;
            case BOT_CLASS_DARK_RANGER:
                switch (newProto->SubClass)
                {
                    case ITEM_SUBCLASS_WEAPON_SWORD:
                    case ITEM_SUBCLASS_WEAPON_DAGGER:
                    case ITEM_SUBCLASS_WEAPON_BOW:
                        break;
                    default:
                        return false;
                }
                break;
            case BOT_CLASS_SEA_WITCH:
                switch (newProto->SubClass)
                {
                    case ITEM_SUBCLASS_WEAPON_DAGGER:
                    case ITEM_SUBCLASS_WEAPON_BOW:
                        break;
                    default:
                        return false;
                }
                break;
            default:
                return false;
        }

        return true;
    }
    else if (newProto->Class == ITEM_CLASS_ARMOR/* || newProto->Class == ITEM_CLASS_QUEST*/)
    {
        switch (newProto->InventoryType)
        {
            case INVTYPE_HEAD:
                if (slot != BOT_SLOT_HEAD)
                    return false;
                break;
            case INVTYPE_SHOULDERS:
                if (slot != BOT_SLOT_SHOULDERS)
                    return false;
                break;
            case INVTYPE_BODY:
                if (slot != BOT_SLOT_BODY)
                    return false;
                switch (_botclass)
                {
                    case BOT_CLASS_SPHYNX:
                        return false;
                    default:
                        break;
                }
                break;
            case INVTYPE_CHEST:
            case INVTYPE_ROBE:
                if (slot != BOT_SLOT_CHEST)
                    return false;
                break;
            case INVTYPE_WAIST:
                if (slot != BOT_SLOT_WAIST)
                    return false;
                break;
            case INVTYPE_LEGS:
                if (slot != BOT_SLOT_LEGS)
                    return false;
                break;
            case INVTYPE_FEET:
                if (slot != BOT_SLOT_FEET)
                    return false;
                break;
            case INVTYPE_WRISTS:
                if (slot != BOT_SLOT_WRIST)
                    return false;
                break;
            case INVTYPE_HANDS:
                if (slot != BOT_SLOT_HANDS)
                    return false;
                break;
            case INVTYPE_FINGER:
                if (slot != BOT_SLOT_FINGER1 && slot != BOT_SLOT_FINGER2)
                    return false;
                switch (_botclass)
                {
                    case BOT_CLASS_SPHYNX:
                        return false;
                    default:
                        break;
                }
                break;
            case INVTYPE_TRINKET:
                if (slot != BOT_SLOT_TRINKET1 && slot != BOT_SLOT_TRINKET2)
                    return false;
                switch (_botclass)
                {
                    case BOT_CLASS_SPHYNX:
                        return false;
                    default:
                        break;
                }
                break;
            case INVTYPE_NECK:
                if (slot != BOT_SLOT_NECK)
                    return false;
                switch (_botclass)
                {
                    case BOT_CLASS_SPHYNX:
                        return false;
                    default:
                        break;
                }
                break;
            case INVTYPE_CLOAK:
                if (slot != BOT_SLOT_BACK)
                    return false;
                switch (_botclass)
                {
                    case BOT_CLASS_SPHYNX:
                        return false;
                    default:
                        break;
                }
                break;
            case INVTYPE_HOLDABLE:
            case INVTYPE_SHIELD:
                if (slot != BOT_SLOT_OFFHAND)
                    return false;
                switch (_botclass)
                {
                    case BOT_CLASS_SPHYNX:
                        return false;
                    default:
                        break;
                }
                break;
            case INVTYPE_RELIC:
                if (slot != BOT_SLOT_RANGED)
                    return false;
                break;
            default:
                return false;
        }

        switch (newProto->SubClass)
        {
            case ITEM_SUBCLASS_ARMOR_SHIELD:
                if (slot != BOT_SLOT_OFFHAND)
                    return false;
                switch (_botclass)
                {
                    case BOT_CLASS_SPELLBREAKER:
                        break;
                    case BOT_CLASS_WARRIOR:
                    case BOT_CLASS_PALADIN:
                    case BOT_CLASS_SHAMAN:
                        break;
                    default:
                        return false;
                }
                break;
            case ITEM_SUBCLASS_ARMOR_PLATE:
                switch (_botclass)
                {
                    case BOT_CLASS_BM:
                    case BOT_CLASS_SPHYNX:
                    case BOT_CLASS_DREADLORD:
                    case BOT_CLASS_SPELLBREAKER:
                    case BOT_CLASS_CRYPT_LORD:
                        break;
                    case BOT_CLASS_WARRIOR:
                    case BOT_CLASS_PALADIN:
                    case BOT_CLASS_DEATH_KNIGHT:
                        if (me->GetLevel() >= 40 || newProto->Quality == ITEM_QUALITY_HEIRLOOM)
                            break;
                        return false;
                    default:
                        return false;
                }
                break;
            case ITEM_SUBCLASS_ARMOR_MAIL:
                switch (_botclass)
                {
                    case BOT_CLASS_BM:
                    case BOT_CLASS_SPHYNX:
                    case BOT_CLASS_SPELLBREAKER:
                    case BOT_CLASS_CRYPT_LORD:
                        break;
                    case BOT_CLASS_WARRIOR:
                    case BOT_CLASS_PALADIN:
                    case BOT_CLASS_DEATH_KNIGHT:
                        break;
                    case BOT_CLASS_SHAMAN:
                    case BOT_CLASS_HUNTER:
                        if (me->GetLevel() >= 40 || newProto->Quality == ITEM_QUALITY_HEIRLOOM)
                            break;
                        return false;
                    default:
                        return false;
                }
                break;
            case ITEM_SUBCLASS_ARMOR_LEATHER:
                switch (_botclass)
                {
                    case BOT_CLASS_DARK_RANGER:
                        break;
                    case BOT_CLASS_WARRIOR:
                    case BOT_CLASS_PALADIN:
                    case BOT_CLASS_DEATH_KNIGHT:
                    case BOT_CLASS_BM:
                    case BOT_CLASS_SHAMAN:
                    case BOT_CLASS_HUNTER:
                    case BOT_CLASS_ROGUE:
                    case BOT_CLASS_DRUID:
                        break;
                    default:
                        return false;
                }
                break;
            case ITEM_SUBCLASS_ARMOR_CLOTH:
                switch (_botclass)
                {
                    case BOT_CLASS_SPHYNX:
                        return false;
                    case BOT_CLASS_DREADLORD:
                    case BOT_CLASS_SPELLBREAKER:
                    case BOT_CLASS_CRYPT_LORD:
                        if (newProto->InventoryType != INVTYPE_CLOAK)
                            return false;
                        break;
                    default:
                        break;
                }
                break;
            case ITEM_SUBCLASS_ARMOR_MISCELLANEOUS:
                switch (_botclass)
                {
                    case BOT_CLASS_SPHYNX:
                        return false;
                    default:
                        break;
                }
                break;
            case ITEM_SUBCLASS_ARMOR_LIBRAM:
                switch (_botclass)
                {
                    case BOT_CLASS_PALADIN:
                        break;
                    default:
                        return false;
                }
                break;
            case ITEM_SUBCLASS_ARMOR_IDOL:
                switch (_botclass)
                {
                    case BOT_CLASS_DRUID:
                        break;
                    default:
                        return false;
                }
                break;
            case ITEM_SUBCLASS_ARMOR_TOTEM:
                switch (_botclass)
                {
                    case BOT_CLASS_SHAMAN:
                        break;
                    default:
                        return false;
                }
                break;
            case ITEM_SUBCLASS_ARMOR_SIGIL:
                switch (_botclass)
                {
                    case BOT_CLASS_DEATH_KNIGHT:
                        break;
                    default:
                        return false;
                }
                break;
            default:
                return false;
        }

        return true;
    }

    return false;
}

void bot_ai::_removeEquipment(uint8 slot)
{
    Item* item = _equips[slot];
    if (!item)
        return; //already unequipped

    _usableItemSlotsMask &= ~(1ul << slot);

    RemoveItemBonuses(slot);
    ApplyItemSetBonuses(item, false);

    if (slot == BOT_SLOT_OFFHAND)
    {
        if (me->CanDualWield())
            me->SetCanDualWield(false);
        if (!(me->GetCreatureTemplate()->flags_extra & CREATURE_FLAG_EXTRA_NO_BLOCK))
            const_cast<CreatureTemplate*>(me->GetCreatureTemplate())->flags_extra |= CREATURE_FLAG_EXTRA_NO_BLOCK;
    }

    _equips[slot] = nullptr;
}

bool bot_ai::_unequip(uint8 slot, ObjectGuid receiver)
{
    EquipmentInfo const* einfo = BotDataMgr::GetBotEquipmentInfo(me->GetEntry());
    ASSERT(einfo, "Trying to unequip item for bot with no equip info!");

    Item* item = _equips[slot];
    if (!item)
        return true; //already unequipped

    uint32 itemId = item->GetEntry();

    BotLogger::Log(NPCBOT_LOG_UNEQUIP, me, uint32(slot), uint32(item->GetGUID().GetCounter()), uint32(itemId), uint32(receiver.GetCounter()));

    _removeEquipment(slot);

    //hand old weapon to master
    if (receiver && (slot > BOT_SLOT_RANGED || einfo->ItemEntry[slot] != itemId))
    {
        if (receiver == master->GetGUID())
        {
            ItemPosCountVec dest;
            uint32 no_space = 0;
            InventoryResult msg = master->CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, itemId, 1, &no_space);
            if (msg != EQUIP_ERR_OK)
            {
                std::ostringstream istr;
                _AddItemLink(master, item, istr, false);
                ChatHandler ch(master->GetSession());
                ch.PSendSysMessage(LocalizedNpcText(master, BOT_TEXT_CANT_UNEQUIP_MAILING).c_str(), istr.str().c_str());

                item->SetOwnerGUID(master->GetGUID());

                CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();
                item->FSetState(ITEM_CHANGED);
                item->SaveToDB(trans);
                MailDraft(istr.str(), "").AddItem(item).SendMailTo(trans, MailReceiver(master), MailSender(me));
                CharacterDatabase.CommitTransaction(trans);

                //master->SendEquipError(msg, nullptr, nullptr, itemId);
                //return false;
            }
            else
            {
                Item* pItem = master->StoreItem(dest, item, true);
                master->SendNewItem(pItem, 1, true, false, false);
            }
        }
        else
        {
            item->SetOwnerGUID(receiver);

            CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();
            item->FSetState(ITEM_CHANGED);
            item->SaveToDB(trans);
            static const std::string subject = LocalizedNpcText(nullptr, BOT_TEXT_OWNERSHIP_EXPIRED);
            MailDraft(subject, "").AddItem(item).SendMailTo(trans, MailReceiver(receiver.GetCounter()), MailSender(me));
            CharacterDatabase.CommitTransaction(trans);
        }
    }
    else
    {
        //slot < BOT_SLOT_RANGED && einfo->ItemEntry[slot] == itemId
        //we have our standard weapon which we should get rid of
        //item->SetState(ITEM_REMOVED, master); //delete Item object
        delete item; //!Invalidated!
        //item = nullptr; //already in "_updateEquips(slot, nullptr);"
    }

    if (slot <= BOT_SLOT_RANGED && CanChangeEquip(slot)) //weapons
    {
        me->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID + slot, 0);
        me->SetAttackTime(WeaponAttackType(slot), BASE_ATTACK_TIME); //without weapon
    }

    _updateEquips(slot, nullptr);
    return true;
}

bool bot_ai::_equip(uint8 slot, Item* newItem, ObjectGuid receiver)
{
    ASSERT(newItem);

    EquipmentInfo const* einfo = BotDataMgr::GetBotEquipmentInfo(me->GetEntry());
    ASSERT(einfo, "Trying to equip item for bot with no equip info!");

    ItemTemplate const* proto = newItem->GetTemplate();

    if (newItem->GetState() == ITEM_REMOVED)
    {
        TC_LOG_ERROR("entities.player",
            "minion_ai::_equip(): player {} ({}) is trying to make bot {} (id: {}) equip item: {} (id: {}, {}) which has state ITEM_REMOVED!",
            master->GetName(), master->GetGUID().ToString(), me->GetName(), me->GetEntry(), proto->Name1, proto->ItemId, newItem->GetGUID().ToString());
        return false;
    }

    uint32 newItemId = newItem->GetEntry();

    if (Item const* oldItem = _equips[slot])
    {
        //same id
        if (oldItem->GetEntry() == newItemId && !newItem->GetItemRandomPropertyId())
            return false;
    }

    if (!_unequip(slot, receiver))
    {
        //BotWhisper("You have no space for my current item", master);
        return false;
    }

    BotLogger::Log(NPCBOT_LOG_EQUIP, me, uint32(slot), uint32(newItem->GetGUID().GetCounter()), uint32(newItemId), uint32(receiver.GetCounter()));

    if (receiver && (slot > BOT_SLOT_RANGED || einfo->ItemEntry[slot] != newItemId))
    {
        ASSERT(receiver == master->GetGUID());

        //cheating
        if (newItem->GetOwnerGUID() != master->GetGUID() || !master->HasItemCount(newItemId, 1))
        {
            //std::ostringstream msg;
            //msg << "Cannot find ";
            //_AddItemLink(master, newItem, msg, false);
            //msg << " (id: " << uint32(newItemId) << ")!";
            //BotWhisper(msg.str().c_str());

            TC_LOG_ERROR("entities.player",
                "minion_ai::_equip(): player {} ({}) is trying to make bot {} (id: {}) equip item: {} (id: {}, {}) but either does not have this item or does not own it",
                master->GetName(), master->GetGUID().ToString(), me->GetName(), me->GetEntry(), proto->Name1, proto->ItemId, newItem->GetGUID().ToString());
            return false;
        }

        master->MoveItemFromInventory(newItem->GetBagSlot(), newItem->GetSlot(), true);
        //Item is removed from inventory table in _updateEquips(slot, newItem);
        //newItem->SetOwnerGUID(ObjectGuid::Empty); //needed to prevent some logs to be sent to master, restored at unequip
    }

    if (slot <= BOT_SLOT_RANGED)
    {
        if (CanChangeEquip(slot))
        {
            NpcBotTransmogData const* transmogData = BotDataMgr::SelectNpcBotTransmogs(me->GetEntry());
            if (einfo->ItemEntry[slot] != newItemId && transmogData && BotMgr::IsTransmogEnabled() && (transmogData->transmogs[slot].first == newItemId || BotMgr::TransmogUseEquipmentSlots()) &&
                transmogData->transmogs[slot].second >= 0)
                me->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID + slot, uint32(transmogData->transmogs[slot].second));
            else
                me->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID + slot, newItemId);
        }
        uint32 delay =
            /*einfo->ItemEntry[slot] != newItemId || */RespectEquipsAttackTime() || slot == BOT_SLOT_OFFHAND ? proto->Delay :
            slot == BOT_SLOT_RANGED ? me->GetCreatureTemplate()->RangeAttackTime : me->GetCreatureTemplate()->BaseAttackTime;
        //attack time will be updated in SetStats() -> OnMeleeDamageUpdate()
        if (!me->IsInFeralForm())
            me->SetAttackTime(WeaponAttackType(slot), delay); //set attack speed
    }

    if (IsUsableItem(newItem))
    {
        uint32 slotMask = 1ul << slot;
        ASSERT(!(_usableItemSlotsMask & slotMask));
        _usableItemSlotsMask |= slotMask;
    }

    _updateEquips(slot, newItem);

    //only for non-standard items
    if (slot > BOT_SLOT_RANGED || einfo->ItemEntry[slot] != newItemId)
        ApplyItemBonuses(slot);
    ApplyItemSetBonuses(newItem, true);

    if (slot == BOT_SLOT_OFFHAND)
    {
        if (proto->Class == ITEM_CLASS_WEAPON)
        {
            if (!me->CanDualWield())
                me->SetCanDualWield(true);
        }
        else if (proto->Class == ITEM_CLASS_ARMOR && proto->SubClass == ITEM_SUBCLASS_ARMOR_SHIELD)
        {
            if (me->GetCreatureTemplate()->flags_extra & CREATURE_FLAG_EXTRA_NO_BLOCK)
                const_cast<CreatureTemplate*>(me->GetCreatureTemplate())->flags_extra &= ~CREATURE_FLAG_EXTRA_NO_BLOCK;
        }
    }
    else if (slot == BOT_SLOT_MAINHAND)
    {
        if (proto->InventoryType == INVTYPE_2HWEAPON && !(_botclass == BOT_CLASS_WARRIOR && me->GetLevel() >= 60 && GetSpec() == BOT_SPEC_WARRIOR_FURY))
        {
            //if have incompatible offhand unequip it
            if (_equips[BOT_SLOT_OFFHAND] != nullptr)
                _unequip(BOT_SLOT_OFFHAND, receiver);
        }
        else if (_equips[BOT_SLOT_OFFHAND] == nullptr && einfo->ItemEntry[BOT_SLOT_OFFHAND])
            _resetEquipment(BOT_SLOT_OFFHAND, receiver);
    }

    //send info to class ai
    if (proto->Class == ITEM_CLASS_WEAPON)
    {
        if (slot == BOT_SLOT_MAINHAND)
        {
            SetAIMiscValue(BOTAI_MISC_DAGGER_MAINHAND, proto->SubClass == ITEM_SUBCLASS_WEAPON_DAGGER);
            SetAIMiscValue(BOTAI_MISC_ENCHANT_CAN_EXPIRE_MH, newItem->GetEnchantmentId(TEMP_ENCHANTMENT_SLOT));
            SetAIMiscValue(BOTAI_MISC_WEAPON_SPEC, proto->SubClass);
        }
        if (slot == BOT_SLOT_OFFHAND)
        {
            SetAIMiscValue(BOTAI_MISC_DAGGER_OFFHAND, proto->SubClass == ITEM_SUBCLASS_WEAPON_DAGGER);
            SetAIMiscValue(BOTAI_MISC_ENCHANT_CAN_EXPIRE_OH, newItem->GetEnchantmentId(TEMP_ENCHANTMENT_SLOT));
        }
    }

    return true;
}

void bot_ai::_updateEquips(uint8 slot, Item* item)
{
    _equips[slot] = item;
    BotDataMgr::UpdateNpcBotData(me->GetEntry(), NPCBOT_UPDATE_EQUIPS, _equips);
}
//Called from gossip menu only (applies only to weapons)
bool bot_ai::_resetEquipment(uint8 slot, ObjectGuid receiver)
{
    if (IsWanderer())
    {
        TC_LOG_ERROR("scripts", "bot_ai::_resetEquipment() is called for wanderer bot {} ({}), slot {}!",
            me->GetName(), me->GetEntry(), uint32(slot));
        return false;
    }

    ASSERT(slot <= BOT_SLOT_RANGED);

    EquipmentInfo const* einfo = BotDataMgr::GetBotEquipmentInfo(me->GetEntry());
    ASSERT(einfo, "Trying to reset equipment for bot with no equip info!");

    uint32 itemId = einfo->ItemEntry[slot];
    Item const* oldItem = _equips[slot];

    BotLogger::Log(NPCBOT_LOG_EQUIP_RESET, me, uint32(slot), uint32(oldItem ? oldItem->GetGUID().GetCounter() : 0), uint32(oldItem ? oldItem->GetEntry() : 0), uint32(receiver.GetCounter()), uint32(itemId));

    if (!itemId)
        return _unequip(slot, receiver);
    else if (oldItem)
        if (oldItem->GetEntry() == itemId)
            return true;

    if (slot == BOT_SLOT_MAINHAND && !(_botclass == BOT_CLASS_WARRIOR && me->GetLevel() >= 60 && GetSpec() == BOT_SPEC_WARRIOR_FURY))
    {
        if (ItemTemplate const* proto = sObjectMgr->GetItemTemplate(itemId))
        {
            if (proto->Class == ITEM_CLASS_WEAPON &&
                (proto->SubClass == ITEM_SUBCLASS_WEAPON_AXE2 || proto->SubClass == ITEM_SUBCLASS_WEAPON_MACE2 ||
                proto->SubClass == ITEM_SUBCLASS_WEAPON_SWORD2 || proto->SubClass == ITEM_SUBCLASS_WEAPON_POLEARM ||
                proto->SubClass == ITEM_SUBCLASS_WEAPON_STAFF || proto->SubClass == ITEM_SUBCLASS_WEAPON_SPEAR))
            {
                if (!_unequip(BOT_SLOT_OFFHAND, receiver))
                    return false;
            }
        }
    }

    //we have our standard weapon itemId which we should use to create new item
    Item* stItem = Item::CreateItem(itemId, 1, nullptr);
    ASSERT(stItem, "Failed to create standard Item for bot!");

    if (!_equip(slot, stItem, receiver))
    {
        TC_LOG_ERROR("entities.player", "minion_ai::_resetEquipment(): player {} ({}) failed to reset equipment for bot {} (id: {}) in slot {}",
            master->GetName(), master->GetGUID().ToString(), me->GetName(), me->GetEntry(), slot);
        return false;
    }
    return true;
}

void bot_ai::ApplyItemBonuses(uint8 slot)
{
    //ensurance to set zeros
    RemoveItemBonuses(slot);

    Item* item = _equips[slot];
    if (!item)
        return;

    ItemTemplate const* proto = sObjectMgr->GetItemTemplate(item->GetEntry());
    if (!proto)
        return;

    ScalingStatDistributionEntry const* ssd = proto->ScalingStatDistribution ? sScalingStatDistributionStore.LookupEntry(proto->ScalingStatDistribution) : nullptr;

    uint32 ssd_level = me->GetLevel();
    if (ssd && ssd_level > ssd->Maxlevel)
        ssd_level = ssd->Maxlevel;

    ScalingStatValuesEntry const* ssv = proto->ScalingStatValue ? sScalingStatValuesStore.LookupEntry(ssd_level) : nullptr;

    for (uint8 i = 0; i != MAX_ITEM_PROTO_STATS; ++i)
    {
        uint32 statType = 0;
        int32  val      = 0;
        if (ssd && ssv)
        {
            if (ssd->StatID[i] < 0)
                continue;
            statType = ssd->StatID[i];
            val = (ssv->getssdMultiplier(proto->ScalingStatValue) * ssd->Bonus[i]) / 10000;
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

        _stats[slot][statType] += val;
    }

    _stats[slot][BOT_STAT_MOD_RESIST_HOLY] += proto->HolyRes;
    _stats[slot][BOT_STAT_MOD_RESIST_FIRE] += proto->FireRes;
    _stats[slot][BOT_STAT_MOD_RESIST_NATURE] += proto->NatureRes;
    _stats[slot][BOT_STAT_MOD_RESIST_FROST] += proto->FrostRes;
    _stats[slot][BOT_STAT_MOD_RESIST_SHADOW] += proto->ShadowRes;
    _stats[slot][BOT_STAT_MOD_RESIST_ARCANE] += proto->ArcaneRes;

    _stats[slot][BOT_STAT_MOD_ARMOR] += proto->Armor;
    _stats[slot][BOT_STAT_MOD_BLOCK_VALUE] += proto->Block;

    EquipmentInfo const* einfo = BotDataMgr::GetBotEquipmentInfo(me->GetEntry());
    if (slot > BOT_SLOT_RANGED || item->GetEntry() != einfo->ItemEntry[slot])
    {
        if (ssv)
        {
            int32 extraDPS = ssv->getDPSMod(proto->ScalingStatValue);
            if (extraDPS)
            {
                float average = extraDPS * proto->Delay / 1000.0f;
                float mod = ssv->isTwoHand(proto->ScalingStatValue) ? 0.2f : 0.3f;

                _stats[slot][BOT_STAT_MOD_DAMAGE_MIN] += (1.0f - mod) * average;
                _stats[slot][BOT_STAT_MOD_DAMAGE_MAX] += (1.0f + mod) * average;
            }
        }
        else
        {
            _stats[slot][BOT_STAT_MOD_DAMAGE_MIN] += proto->Damage[0].DamageMin + proto->Damage[1].DamageMin;
            _stats[slot][BOT_STAT_MOD_DAMAGE_MAX] += proto->Damage[0].DamageMax + proto->Damage[1].DamageMax;
        }

        if (_botclass == BOT_CLASS_DRUID)
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
                _stats[slot][BOT_STAT_MOD_FERAL_ATTACK_POWER] += feral_bonus;
                //ApplyFeralAPBonus(feral_bonus, apply);
        }
    }

    ApplyItemEnchantments(item, slot);
    ApplyItemEquipSpells(item, true);

    shouldUpdateStats = true;
}

void bot_ai::RemoveItemBonuses(uint8 slot)
{
    Item* item = _equips[slot];
    if (!item)
        return;

    ItemTemplate const* proto = sObjectMgr->GetItemTemplate(item->GetEntry());
    if (!proto)
        return;

    for (uint8 i = 0; i != MAX_BOT_ITEM_MOD; ++i)
        _stats[slot][i] = 0;

    RemoveItemEnchantments(item); //remove spells
    ApplyItemEquipSpells(item, false);

    shouldUpdateStats = true;
}

void bot_ai::ApplyItemEnchantments(Item* item, uint8 slot)
{
    for (uint8 i = 0; i != MAX_ENCHANTMENT_SLOT; ++i)
        ApplyItemEnchantment(item, EnchantmentSlot(i), slot);
}

void bot_ai::ApplyItemEnchantment(Item* item, EnchantmentSlot eslot, uint8 slot)
{
    uint32 enchant_id = item->GetEnchantmentId(eslot);
    if (!enchant_id)
        return;

    SpellItemEnchantmentEntry const* pEnchant = sSpellItemEnchantmentStore.LookupEntry(enchant_id);
    if (!pEnchant)
        return;

    if (pEnchant->MinLevel > me->GetLevel())
        return;

    uint32 enchant_display_type;
    uint32 enchant_amount;
    uint32 enchant_spell_id;

    for (uint8 s = 0; s != MAX_ITEM_ENCHANTMENT_EFFECTS; ++s)
    {
        enchant_display_type = pEnchant->Effect[s];
        enchant_amount = pEnchant->EffectPointsMin[s];
        enchant_spell_id = pEnchant->EffectArg[s];

        switch (enchant_display_type)
        {
            case ITEM_ENCHANTMENT_TYPE_DAMAGE:
                _stats[slot][BOT_STAT_MOD_DAMAGE_MIN] += enchant_amount;
                _stats[slot][BOT_STAT_MOD_DAMAGE_MAX] += enchant_amount;
                break;
            case ITEM_ENCHANTMENT_TYPE_EQUIP_SPELL:
                if (enchant_spell_id)
                {
                    int32 basepoints = 0;
                    // Random Property Exist - try found basepoints for spell (basepoints depends from item suffix factor)
                    if (item->GetItemRandomPropertyId())
                    {
                        ItemRandomSuffixEntry const* item_rand = sItemRandomSuffixStore.LookupEntry(abs(item->GetItemRandomPropertyId()));
                        if (item_rand)
                        {
                            // Search enchant_amount
                            for (uint8 k = 0; k != MAX_ITEM_ENCHANTMENT_EFFECTS; ++k)
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
                    CastSpellExtraArgs args(item);
                    if (basepoints)
                        for (uint8 i = 0; i < MAX_SPELL_EFFECTS; ++i)
                            args.AddSpellMod(SpellValueMod(SPELLVALUE_BASE_POINT0 + i), basepoints);
                    me->CastSpell(me, enchant_spell_id, args);
                }
                break;
            case ITEM_ENCHANTMENT_TYPE_RESISTANCE:
                if (!enchant_amount)
                {
                    ItemRandomSuffixEntry const* item_rand = sItemRandomSuffixStore.LookupEntry(abs(item->GetItemRandomPropertyId()));
                    if (item_rand)
                    {
                        for (uint8 k = 0; k < MAX_ITEM_ENCHANTMENT_EFFECTS; ++k)
                        {
                            if (item_rand->Enchantment[k] == enchant_id)
                            {
                                enchant_amount = uint32((item_rand->AllocationPct[k] * item->GetItemSuffixFactor()) / 10000);
                                break;
                            }
                        }
                    }
                }
                _stats[slot][BOT_STAT_MOD_RESISTANCE_START + enchant_spell_id] += enchant_amount;
                break;
            case ITEM_ENCHANTMENT_TYPE_STAT:
            {
                if (!enchant_amount)
                {
                    ItemRandomSuffixEntry const* item_rand_suffix = sItemRandomSuffixStore.LookupEntry(abs(item->GetItemRandomPropertyId()));
                    if (item_rand_suffix)
                    {
                        for (uint8 k = 0; k != MAX_ITEM_ENCHANTMENT_EFFECTS; ++k)
                        {
                            if (item_rand_suffix->Enchantment[k] == enchant_id)
                            {
                                enchant_amount = uint32((item_rand_suffix->AllocationPct[k] * item->GetItemSuffixFactor()) / 10000);
                                break;
                            }
                        }
                    }
                }

                switch (enchant_spell_id)
                {
                    case ITEM_MOD_MANA:
                    case ITEM_MOD_HEALTH:
                    case ITEM_MOD_AGILITY:
                    case ITEM_MOD_STRENGTH:
                    case ITEM_MOD_INTELLECT:
                    case ITEM_MOD_SPIRIT:
                    case ITEM_MOD_STAMINA:
                    case ITEM_MOD_DEFENSE_SKILL_RATING:
                    case ITEM_MOD_DODGE_RATING:
                    case ITEM_MOD_PARRY_RATING:
                    case ITEM_MOD_BLOCK_RATING:
                    case ITEM_MOD_HIT_MELEE_RATING:
                    case ITEM_MOD_HIT_RANGED_RATING:
                    case ITEM_MOD_HIT_SPELL_RATING:
                    case ITEM_MOD_CRIT_MELEE_RATING:
                    case ITEM_MOD_CRIT_RANGED_RATING:
                    case ITEM_MOD_CRIT_SPELL_RATING:
                    //case ITEM_MOD_HIT_TAKEN_MELEE_RATING:
                    //case ITEM_MOD_HIT_TAKEN_RANGED_RATING:
                    //case ITEM_MOD_HIT_TAKEN_SPELL_RATING:
                    //case ITEM_MOD_CRIT_TAKEN_MELEE_RATING:
                    //case ITEM_MOD_CRIT_TAKEN_RANGED_RATING:
                    //case ITEM_MOD_CRIT_TAKEN_SPELL_RATING:
                    case ITEM_MOD_HASTE_MELEE_RATING:
                    case ITEM_MOD_HASTE_RANGED_RATING:
                    case ITEM_MOD_HASTE_SPELL_RATING:
                    case ITEM_MOD_HIT_RATING:
                    case ITEM_MOD_CRIT_RATING:
                    case ITEM_MOD_HASTE_RATING:
                    case ITEM_MOD_RESILIENCE_RATING:
                    case ITEM_MOD_EXPERTISE_RATING:
                    case ITEM_MOD_ATTACK_POWER:
                    case ITEM_MOD_RANGED_ATTACK_POWER:
                    case ITEM_MOD_MANA_REGENERATION:
                    case ITEM_MOD_ARMOR_PENETRATION_RATING:
                    case ITEM_MOD_SPELL_POWER:
                    case ITEM_MOD_HEALTH_REGEN:
                    case ITEM_MOD_SPELL_PENETRATION:
                    case ITEM_MOD_BLOCK_VALUE:
                    case ITEM_MOD_SPELL_HEALING_DONE:   // deprecated
                    case ITEM_MOD_SPELL_DAMAGE_DONE:    // deprecated
                        _stats[slot][enchant_spell_id] += enchant_amount;
                        break;
                    default:
                        break;
                }
                break;
            }
            case ITEM_ENCHANTMENT_TYPE_TOTEM:           // Shaman Rockbiter Weapon
            case ITEM_ENCHANTMENT_TYPE_USE_SPELL:
            case ITEM_ENCHANTMENT_TYPE_PRISMATIC_SOCKET:
                break;
            default:
                break;
        }
    }
}

void bot_ai::RemoveItemEnchantments(Item const* item)
{
    for (uint8 i = 0; i != MAX_ENCHANTMENT_SLOT; ++i)
        RemoveItemEnchantment(item, EnchantmentSlot(i));
}

void bot_ai::RemoveItemEnchantment(Item const* item, EnchantmentSlot eslot)
{
    uint32 enchant_id = item->GetEnchantmentId(eslot);
    if (!enchant_id)
        return;

    SpellItemEnchantmentEntry const* pEnchant = sSpellItemEnchantmentStore.LookupEntry(enchant_id);
    if (!pEnchant)
        return;

    ////skip level reqs
    //if (pEnchant->MinLevel > me->GetLevel())
    //    return;

    uint32 enchant_display_type;
    //uint32 enchant_amount;
    uint32 enchant_spell_id;

    for (uint8 s = 0; s != MAX_ITEM_ENCHANTMENT_EFFECTS; ++s)
    {
        enchant_display_type = pEnchant->Effect[s];
        //enchant_amount = pEnchant->EffectPointsMin[s];
        enchant_spell_id = pEnchant->EffectArg[s];

        switch (enchant_display_type)
        {
            case ITEM_ENCHANTMENT_TYPE_DAMAGE:
                //Already removed in RemoveItemBonuses()
                break;
            case ITEM_ENCHANTMENT_TYPE_EQUIP_SPELL:
                if (enchant_spell_id)
                    me->RemoveAurasDueToItemSpell(enchant_spell_id, item->GetGUID());
                break;
            case ITEM_ENCHANTMENT_TYPE_RESISTANCE:
                //Already removed in RemoveItemBonuses()
                break;
            case ITEM_ENCHANTMENT_TYPE_STAT:
                //Already removed in RemoveItemBonuses()
                break;
            case ITEM_ENCHANTMENT_TYPE_TOTEM:           // Shaman Rockbiter Weapon
            case ITEM_ENCHANTMENT_TYPE_USE_SPELL:
            case ITEM_ENCHANTMENT_TYPE_PRISMATIC_SOCKET:
                break;
            default:
                break;
        }
    }
}

void bot_ai::RemoveItemClassEnchantment(uint8 slot)
{
    uint8 eslot = TEMP_ENCHANTMENT_SLOT;

    if (!GetAIMiscValue(slot == BOT_SLOT_MAINHAND ? BOTAI_MISC_ENCHANT_CAN_EXPIRE_MH : BOTAI_MISC_ENCHANT_CAN_EXPIRE_OH))
        return;

    Item* weap = _equips[slot];
    if (!weap || !weap->GetEnchantmentId(EnchantmentSlot(eslot)))
        return;

    RemoveItemEnchantment(weap, EnchantmentSlot(eslot));

    for (uint8 i = 0; i != MAX_ITEM_ENCHANTMENT_EFFECTS; ++i)
        weap->SetUInt32Value(ITEM_FIELD_ENCHANTMENT_1_1 + eslot*MAX_ENCHANTMENT_OFFSET + i, 0);
}

void bot_ai::RemoveItemClassEnchantments()
{
    for (uint8 k = BOT_SLOT_MAINHAND; k != BOT_SLOT_RANGED; ++k)
        RemoveItemClassEnchantment(k);
}

void bot_ai::ApplyItemEquipSpells(Item* item, bool apply)
{
    if (!item)
        return;

    ItemTemplate const* proto = item->GetTemplate();
    if (!proto)
        return;

    for (uint8 i = 0; i != MAX_ITEM_PROTO_SPELLS; ++i)
    {
        _Spell const& spellData = proto->Spells[i];

        if (!spellData.SpellId)
            continue;

        // wrong triggering type
        if (apply && spellData.SpellTrigger != ITEM_SPELLTRIGGER_ON_EQUIP)
            continue;

        // check if it is valid spell
        SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(spellData.SpellId);
        if (!spellInfo)
            continue;

        //ApplyEquipSpell(spellproto, item, apply);

        //if (apply)
        //    me->AddAura(spellInfo->Id, me);
        //else
        //    me->RemoveAura(spellInfo->Id);

        CastSpellExtraArgs args(item);
        if (apply)
            me->CastSpell(me, spellInfo->Id, args);
        else
            me->RemoveAurasDueToItemSpell(spellInfo->Id, item->GetGUID());  // un-apply all spells, not only at-equipped
    }
}

void bot_ai::ApplyItemEquipEnchantmentSpells(Item* item)
{
    for (uint8 e_slot = 0; e_slot != MAX_ENCHANTMENT_SLOT; ++e_slot)
    {
        uint32 enchant_id = item->GetEnchantmentId(EnchantmentSlot(e_slot));
        if (!enchant_id)
            continue;
        SpellItemEnchantmentEntry const* pEnchant = sSpellItemEnchantmentStore.LookupEntry(enchant_id);
        if (!pEnchant)
            continue;
        if (pEnchant->MinLevel > me->GetLevel())
            continue;

        uint32 enchant_display_type;
        //uint32 enchant_amount;
        uint32 enchant_spell_id;

        for (uint8 s = 0; s != MAX_ITEM_ENCHANTMENT_EFFECTS; ++s)
        {
            enchant_display_type = pEnchant->Effect[s];
            //enchant_amount = pEnchant->EffectPointsMin[s];
            enchant_spell_id = pEnchant->EffectArg[s];

            switch (enchant_display_type)
            {
                case ITEM_ENCHANTMENT_TYPE_EQUIP_SPELL:
                {
                    if (!enchant_spell_id)
                        break;
                    int32 basepoints = 0;
                    // Random Property Exist - try found basepoints for spell (basepoints depends from item suffix factor)
                    if (item->GetItemRandomPropertyId())
                    {
                        ItemRandomSuffixEntry const* item_rand = sItemRandomSuffixStore.LookupEntry(abs(item->GetItemRandomPropertyId()));
                        if (item_rand)
                        {
                            // Search enchant_amount
                            for (uint8 k = 0; k != MAX_ITEM_ENCHANTMENT_EFFECTS; ++k)
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
                    CastSpellExtraArgs args(item);
                    if (basepoints)
                        for (uint8 i = 0; i < MAX_SPELL_EFFECTS; ++i)
                            args.AddSpellMod(SpellValueMod(SPELLVALUE_BASE_POINT0 + i), basepoints);
                    me->CastSpell(me, enchant_spell_id, args);
                    break;
                }
                default:
                    break;
            }
        }
    }
}

void bot_ai::ApplyItemSetBonuses(Item* item, bool apply)
{
    if (item) //(un)equip, NOT from loops
    {
        ItemTemplate const* proto = item->GetTemplate();
        if (!proto)
            return;

        uint32 setId = proto->ItemSet;
        if (!setId)
            return;

        ItemSetEntry const* itemSet = sItemSetStore.LookupEntry(setId);
        if (!itemSet)
            return;

        uint8 setItemCount = 0;
        for (uint8 i = BOT_SLOT_MAINHAND; i != BOT_INVENTORY_SIZE; ++i)
            if (_equips[i] && _equips[i]->GetTemplate()->ItemSet == setId)
                ++setItemCount; //same at equip and unequip

        for (uint8 i = 0; i != MAX_ITEM_SET_SPELLS; ++i)
        {
            if (!itemSet->SetSpellID[i])
                continue;
            if (itemSet->SetThreshold[i] != setItemCount)
                continue;

            SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(itemSet->SetSpellID[i]);
            if (!spellInfo)
                continue;

            //TC_LOG_ERROR("entities.player", "ApplyItemSetBonusesB: {}'s {}, {} ({}), {} ({}), icount {}",
            //    me->GetName(), apply ? "apply" : "remove", itemSet->name[0], setId, spellInfo->SpellName[0], spellInfo->Id, uint32(setItemCount));

            if (apply)
            {
                CastSpellExtraArgs args(item);
                me->CastSpell(me, spellInfo->Id, args);
            }
            else
                me->RemoveAurasDueToSpell(spellInfo->Id);           // un-apply spell (item set case)
        }
        return;
    }

    //no item means all (init, reset, reset (lvl change))
    std::list<uint32> itemSets;
    for (uint8 i = BOT_SLOT_MAINHAND; i != BOT_INVENTORY_SIZE; ++i)
    {
        item = _equips[i];
        if (!item)
            continue;

        ItemTemplate const* proto = item->GetTemplate();
        if (!proto)
            continue;

        uint32 setId = proto->ItemSet;
        if (!setId)
            continue;

        ItemSetEntry const* itemSet = sItemSetStore.LookupEntry(setId);
        if (!itemSet)
            continue;

        itemSets.push_back(setId);
    }

    itemSets.sort();
    itemSets.unique();
    for (std::list<uint32>::const_iterator itr = itemSets.begin(); itr != itemSets.end(); ++itr)
    {
        ItemSetEntry const* itemSet = sItemSetStore.LookupEntry(*itr);
        uint8 setItemCount = 0;
        for (uint8 k = BOT_SLOT_MAINHAND; k != BOT_INVENTORY_SIZE; ++k)
            if (_equips[k] && _equips[k]->GetTemplate()->ItemSet == *itr)
                ++setItemCount;

        for (uint8 j = 0; j != MAX_ITEM_SET_SPELLS; ++j)
        {
            if (!itemSet->SetSpellID[j])
                continue;
            if (itemSet->SetThreshold[j] > setItemCount)
                continue;

            SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(itemSet->SetSpellID[j]);
            if (!spellInfo)
                continue;

            //TC_LOG_ERROR("entities.player", "ApplyItemSetBonusesB (all): {}'s {}, {} ({}), {} ({}), c {}, req {}",
            //    me->GetName(), apply ? "apply" : "remove", itemSet->name[0], *itr, spellInfo->SpellName[0], spellInfo->Id, uint32(setItemCount), itemSet->SetThreshold[j]);

            if (apply)
            {
                CastSpellExtraArgs args(item);
                me->CastSpell(me, spellInfo->Id, args);
            }
            else
                me->RemoveAurasDueToSpell(spellInfo->Id);           // un-apply spell (item set case)
        }
    }
}

void bot_ai::ApplyItemsSpells()
{
    for (uint8 slot = BOT_SLOT_MAINHAND; slot != BOT_INVENTORY_SIZE; ++slot)
    {
        if (Item* item = _equips[slot])
        {
            ApplyItemEquipSpells(item, true); //item template spells
            ApplyItemEquipEnchantmentSpells(item); //item enchants
        }
    }

    ApplyItemSetBonuses(nullptr, true); //item set bonuses
}
//stats bonuses from equipment
inline float bot_ai::_getBotStat(uint8 slot, BotStatMods stat) const
{
    return float(_stats[slot][stat]);
}

float bot_ai::_getTotalBotStat(BotStatMods stat) const
{
    int32 value = 0;
    for (uint8 slot = BOT_SLOT_MAINHAND; slot != BOT_INVENTORY_SIZE; ++slot)
        value += _stats[slot][stat];

    uint8 lvl = me->GetLevel();
    Stats fstat = STAT_STRENGTH;
    UnitMods fmod = UNIT_MOD_END;
    float fpct = 0.0f;
    float fval = float(value);

    switch (stat)
    {
        case BOT_STAT_MOD_STRENGTH:
            fstat = STAT_STRENGTH;
            fmod = UNIT_MOD_STAT_STRENGTH;
            switch (_botclass)
            {
                case BOT_CLASS_WARRIOR:
                    //Vitality, Strength of Arms
                    if (lvl >= 45 && GetSpec() == BOT_SPEC_WARRIOR_PROTECTION)
                        fpct += 0.06f;
                    if (lvl >= 40 && GetSpec() == BOT_SPEC_WARRIOR_ARMS)
                        fpct += 0.04f;
                    //Improved Berserker Stance part 1 (all stances)
                    if (lvl >= 45 && GetSpec() == BOT_SPEC_WARRIOR_FURY/* && GetBotStance() == WARRIOR_BERSERKER_STANCE*/)
                        fpct += 0.2f;
                    break;
                case BOT_CLASS_PALADIN:
                    //Divine Strength
                    if (lvl >= 10)
                        fpct += 0.15f;
                    break;
                case BOT_CLASS_DEATH_KNIGHT:
                    //Ravenous Dead part 1
                    //Endless Winter part 1
                    //Veteran of the Third War part 1
                    //Abomination's might part 2
                    if (lvl >= 56)
                        fpct += 0.03f;
                    if (lvl >= 58)
                        fpct += 0.04f;
                    if (lvl >= 59 && GetSpec() == BOT_SPEC_DK_BLOOD)
                        fpct += 0.06f;
                    if (lvl >= 60 && GetSpec() == BOT_SPEC_DK_BLOOD)
                        fpct += 0.02f;
                    //Frost Presence passive / Improved Frost Presence
                    if (lvl >= 61 && GetBotStance() == DEATH_KNIGHT_FROST_PRESENCE && GetSpec() == BOT_SPEC_DK_FROST)
                        fpct += 0.08f;
                    break;
                case BOT_CLASS_DRUID:
                    //Survival of the Fittest, Improved Mark of the Wild
                    if (lvl >= 35 && GetSpec() == BOT_SPEC_DRUID_FERAL)
                        fpct += 0.08f;
                    else if (lvl >= 10)
                        fpct += 0.02f;
                    break;
                default:
                    break;
            }
            break;
        case BOT_STAT_MOD_AGILITY:
            fstat = STAT_AGILITY;
            fmod = UNIT_MOD_STAT_AGILITY;
            switch (_botclass)
            {
                case BOT_CLASS_HUNTER:
                    //Combat Experience, Lightning Reflexes
                    if (lvl >= 35 && GetSpec() == BOT_SPEC_HUNTER_MARKSMANSHIP)
                        fpct += 0.04f;
                    if (lvl >= 35 && GetSpec() == BOT_SPEC_HUNTER_SURVIVAL)
                        fpct += 0.15f;
                    //Hunting Party
                    if (lvl >= 35 && GetSpec() == BOT_SPEC_HUNTER_SURVIVAL)
                        fpct += 0.03f;
                    break;
                case BOT_CLASS_ROGUE:
                    //Sinister Calling
                    if (lvl >= 45 && GetSpec() == BOT_SPEC_ROGUE_SUBTLETY)
                        fpct += 0.15f;
                    break;
                case BOT_CLASS_DRUID:
                    //Survival of the Fittest, Improved Mark of the Wild
                    if (lvl >= 35 && GetSpec() == BOT_SPEC_DRUID_FERAL)
                        fpct += 0.08f;
                    else if (lvl >= 10)
                        fpct += 0.02f;
                    break;
                default:
                    break;
            }
            break;
        case BOT_STAT_MOD_STAMINA:
            fstat = STAT_STAMINA;
            fmod = UNIT_MOD_STAT_STAMINA;
            switch (_botclass)
            {
                case BOT_CLASS_WARRIOR:
                    //Vitality, Strength of Arms
                    if (lvl >= 45 && GetSpec() == BOT_SPEC_WARRIOR_PROTECTION)
                        fpct += 0.09f;
                    if (lvl >= 40 && GetSpec() == BOT_SPEC_WARRIOR_ARMS)
                        fpct += 0.04f;
                    break;
                case BOT_CLASS_PALADIN:
                    //Combat Expertise, Sacred Duty
                    if (lvl >= 45 && GetSpec() == BOT_SPEC_PALADIN_PROTECTION)
                        fpct += 0.06f;
                    if (lvl >= 35 && GetSpec() == BOT_SPEC_PALADIN_PROTECTION)
                        fpct += 0.04f;
                    break;
                case BOT_CLASS_HUNTER:
                    //Survivalist
                    if (lvl >= 20)
                        fpct += 0.1f;
                    break;
                case BOT_CLASS_ROGUE:
                    //Lightning Reflexes part 2
                    if (lvl >= 25 && GetSpec() == BOT_SPEC_ROGUE_COMBAT)
                        fpct += 0.04f;
                    break;
                case BOT_CLASS_PRIEST:
                    //Improved Power Word: Fortitude
                    if (lvl >= 15)
                        fpct += 0.04f;
                    break;
                case BOT_CLASS_DEATH_KNIGHT:
                    //Veteran of the Third War part 2
                    if (lvl >= 59 && GetSpec() == BOT_SPEC_DK_BLOOD)
                        fpct += 0.03f;
                    break;
                case BOT_CLASS_WARLOCK:
                    //Demonic Embrace: 10% stam bonus
                    if (lvl >= 10)
                        fpct += 0.1f;
                    break;
                case BOT_CLASS_DRUID:
                    if (GetBotStance() == DRUID_BEAR_FORM)
                    {
                        //Bear form: stamina bonus base 25%
                        //Heart of the Wild: 10% stam bonus for bear
                        fpct += 0.25f;
                        if (lvl >= 35 && GetSpec() == BOT_SPEC_DRUID_FERAL)
                            fpct += 0.1f;
                    }
                    //Survival of the Fittest, Improved Mark of the Wild
                    if (lvl >= 35 && GetSpec() == BOT_SPEC_DRUID_FERAL)
                        fpct += 0.06f;
                    if (lvl >= 10)
                        fpct += 0.02f;
                    break;
                default:
                    break;
            }
            break;
        case BOT_STAT_MOD_INTELLECT:
            fstat = STAT_INTELLECT;
            fmod = UNIT_MOD_STAT_INTELLECT;
            switch (_botclass)
            {
                case BOT_CLASS_PALADIN:
                    //Divine Intellect
                    if (lvl >= 15)
                        fpct += 0.1f;
                    break;
                case BOT_CLASS_HUNTER:
                    //Combat Experience
                    if (lvl >= 35 && GetSpec() == BOT_SPEC_HUNTER_MARKSMANSHIP)
                        fpct += 0.04f;
                    break;
                case BOT_CLASS_MAGE:
                    //Arcane Mind
                    if (lvl >= 30 && GetSpec() == BOT_SPEC_MAGE_ARCANE)
                        fpct += 0.15f;
                    break;
                case BOT_CLASS_PRIEST:
                    //Mental Strength
                    if (lvl >= 30 && GetSpec() == BOT_SPEC_PRIEST_DISCIPLINE)
                        fpct += 0.15f;
                    break;
                case BOT_CLASS_SHAMAN:
                    //Ancestral Knowledge
                    if (lvl >= 10)
                        fpct += 0.1f;
                    break;
                case BOT_CLASS_DRUID:
                    //Survival of the Fittest, Improved Mark of the Wild
                    if (lvl >= 35 && GetSpec() == BOT_SPEC_DRUID_FERAL)
                        fpct += 0.08f;
                    else if (lvl >= 10)
                        fpct += 0.02f;
                    //Furor (Moonkin Form)
                    if (GetBotStance() == DRUID_MOONKIN_FORM)
                        fpct += 0.1f;
                    //Heart of the Wild: ferals only (tanks included)
                    if (lvl >= 35 && GetSpec() == BOT_SPEC_DRUID_FERAL)
                        fpct += 0.2f;
                    break;
                default:
                    break;
            }
            break;
        case BOT_STAT_MOD_SPIRIT:
            fstat = STAT_SPIRIT;
            fmod = UNIT_MOD_STAT_SPIRIT;
            switch (_botclass)
            {
                case BOT_CLASS_PRIEST:
                    //Spirit of Redemption part 1
                    if (lvl >= 30 && GetSpec() == BOT_SPEC_PRIEST_HOLY)
                        fpct += 0.05f;
                    //Enlightenment part 1
                    if (lvl >= 35 && GetSpec() == BOT_SPEC_PRIEST_DISCIPLINE)
                        fpct += 0.06f;
                    break;
                case BOT_CLASS_MAGE:
                    //Student of the Mind
                    if (lvl >= 20)
                        fpct += 0.1f;
                    break;
                case BOT_CLASS_DRUID:
                    //Survival of the Fittest, Improved Mark of the Wild
                    if (lvl >= 35 && GetSpec() == BOT_SPEC_DRUID_FERAL)
                        fpct += 0.08f;
                    else if (lvl >= 10)
                        fpct += 0.02f;
                    //Living Spirit
                    if (lvl >= 40 && GetSpec() == BOT_SPEC_DRUID_RESTORATION)
                        fpct += 0.15f;
                    break;
                default:
                    break;
            }
            break;
        default:
            break;
    }

    if (fmod != UNIT_MOD_END)
    {
        fpct += me->GetPctModifierValue(fmod, TOTAL_PCT);
        fval *= fpct;
        fval += me->GetTotalStatValue(fstat);
    }
    return fval;
}

inline float bot_ai::_getRatingMultiplier(CombatRating cr) const
{
    GtCombatRatingsEntry const* Rating = sGtCombatRatingsStore.LookupEntry(cr*GT_MAX_LEVEL + (me->GetLevel()-1));
    GtOCTClassCombatRatingScalarEntry const* classRating = sGtOCTClassCombatRatingScalarStore.LookupEntry((GetPlayerClass()-1)*GT_MAX_RATING + cr + 1);
    if (!Rating || !classRating)
        return 1.0f;

    return classRating->Data / Rating->Data;
}

float bot_ai::_getStatScore(uint8 stat) const
{
    static const float fone = 1.0f;
    static const float fzero = 0.0f;

    float tankMod = IsTank() ? fone : fzero;
    float healMod = HasRole(BOT_ROLE_HEAL) ? fone : fzero;
    float castMod = IsCastingClass(_botclass) ? fone : fzero;
    float spiritMod = (_botclass == BOT_CLASS_PRIEST || _botclass == BOT_CLASS_MAGE || _botclass == BOT_CLASS_WARLOCK || (_botclass == BOT_CLASS_DRUID && _spec != BOT_SPEC_DRUID_FERAL)) ? fone : fzero;
    float dpsMod = HasRole(BOT_ROLE_DPS) ? fone : fzero;
    float meleeMod = !HasRole(BOT_ROLE_RANGED) ? fone : fzero;
    float manaMod = (_botclass == BOT_CLASS_DRUID || me->GetPowerType() == POWER_MANA) ? fone : fzero;

    switch (stat)
    {
        case BOT_STAT_MOD_MANA:
            return 0.1f * manaMod;
        case BOT_STAT_MOD_HEALTH:
            return 0.1f;
        case BOT_STAT_MOD_AGILITY:
            return _botclass == BOT_CLASS_ROGUE ? 1.2f * dpsMod * meleeMod : (_botclass == BOT_CLASS_HUNTER ? 1.0f : 0.5f) * dpsMod;
        case BOT_STAT_MOD_STRENGTH:
            return (IsMeleeClass(_botclass) ? 1.0f : 0.5f) * dpsMod * meleeMod;
        case BOT_STAT_MOD_INTELLECT:
            return 1.0f * castMod;
        case BOT_STAT_MOD_SPIRIT:
            return 1.0f * spiritMod;
        case BOT_STAT_MOD_STAMINA:
            return IsTank() ? 2.0f : 1.0f;
        case BOT_STAT_MOD_DEFENSE_SKILL_RATING:
            return 2.0f * tankMod;
        case BOT_STAT_MOD_DODGE_RATING:
        case BOT_STAT_MOD_PARRY_RATING:
            return 2.0f * tankMod;
        case BOT_STAT_MOD_BLOCK_RATING:
            return CanBlock() ? 2.0f : 0.0f * tankMod;
        case BOT_STAT_MOD_BLOCK_VALUE:
            return CanBlock() ? 0.67f : 0.0f * tankMod;
        case BOT_STAT_MOD_HIT_TAKEN_RATING:
        case BOT_STAT_MOD_CRIT_TAKEN_RATING:
            return 1.0f * tankMod;
        case BOT_STAT_MOD_HIT_TAKEN_MELEE_RATING:
        case BOT_STAT_MOD_HIT_TAKEN_RANGED_RATING:
        case BOT_STAT_MOD_HIT_TAKEN_SPELL_RATING:
        case BOT_STAT_MOD_CRIT_TAKEN_MELEE_RATING:
        case BOT_STAT_MOD_CRIT_TAKEN_RANGED_RATING:
        case BOT_STAT_MOD_CRIT_TAKEN_SPELL_RATING:
            return 0.4f * tankMod;
        case BOT_STAT_MOD_ARMOR:
            return 0.05f * tankMod;
        case BOT_STAT_MOD_HIT_MELEE_RATING:
        case BOT_STAT_MOD_HIT_RANGED_RATING:
        case BOT_STAT_MOD_HIT_SPELL_RATING:
            return 1.0f * dpsMod;
        case BOT_STAT_MOD_CRIT_MELEE_RATING:
        case BOT_STAT_MOD_CRIT_RANGED_RATING:
        case BOT_STAT_MOD_CRIT_SPELL_RATING:
        case BOT_STAT_MOD_HASTE_MELEE_RATING:
        case BOT_STAT_MOD_HASTE_RANGED_RATING:
        case BOT_STAT_MOD_HASTE_SPELL_RATING:
        case BOT_STAT_MOD_HIT_RATING:
        case BOT_STAT_MOD_CRIT_RATING:
        case BOT_STAT_MOD_HASTE_RATING:
            return HasRole(BOT_ROLE_DPS|BOT_ROLE_HEAL) ? 1.0f : 0.0f;
        case BOT_STAT_MOD_EXPERTISE_RATING:
            return 2.0f * dpsMod * meleeMod;
        case BOT_STAT_MOD_ATTACK_POWER:
            return ((IsMeleeClass(_botclass) || _botclass == BOT_CLASS_HUNTER) ? 0.43f : 0.1f) * dpsMod;
        case BOT_STAT_MOD_RANGED_ATTACK_POWER:
            switch (_botclass)
            {
                case BOT_CLASS_HUNTER: case BOT_CLASS_DARK_RANGER: case BOT_CLASS_SEA_WITCH:    return 0.43f * dpsMod;
                case BOT_CLASS_PRIEST: case BOT_CLASS_MAGE: case BOT_CLASS_WARLOCK:             return 0.15f * dpsMod;
                default:                                                                        return 0.0f;
            }
        case BOT_STAT_MOD_FERAL_ATTACK_POWER:
            return GetSpec() == BOT_SPEC_DRUID_FERAL ? 0.43f : 0.0f;
        case BOT_STAT_MOD_SPELL_HEALING_DONE:
            return 1.25f * healMod;
        case BOT_STAT_MOD_SPELL_DAMAGE_DONE:
            return 1.25f * dpsMod * castMod;
        case BOT_STAT_MOD_MANA_REGENERATION:
            return _botclass == BOT_CLASS_SPHYNX ? 0.0f : 1.2f * manaMod;
        case BOT_STAT_MOD_ARMOR_PENETRATION_RATING:
            return 2.0f * dpsMod * meleeMod;
        case BOT_STAT_MOD_SPELL_POWER:
            return 1.25f * castMod;
        case BOT_STAT_MOD_HEALTH_REGEN:
            return 0.33f * tankMod;
        case BOT_STAT_MOD_SPELL_PENETRATION:
            return 1.2f * castMod * dpsMod;
        case BOT_STAT_MOD_DAMAGE_MIN:
        case BOT_STAT_MOD_DAMAGE_MAX:
            return ((IsMeleeClass(_botclass) || _botclass == BOT_CLASS_HUNTER) ? 0.33f : 0.0f) * dpsMod;
        case BOT_STAT_MOD_RESIST_HOLY:
        case BOT_STAT_MOD_RESIST_FIRE:
        case BOT_STAT_MOD_RESIST_NATURE:
        case BOT_STAT_MOD_RESIST_FROST:
        case BOT_STAT_MOD_RESIST_SHADOW:
        case BOT_STAT_MOD_RESIST_ARCANE:
            return IsTank() ? 1.25f : 0.25f;
        default:
            return 0.0f;
    }
}

float bot_ai::_getItemGearStatScore(ItemTemplate const* iproto, uint8 forslot, Item const* item) const
{
    ItemTemplate const* proto = item ? sObjectMgr->GetItemTemplate(item->GetEntry()) : iproto;
    if (!proto)
        return 0.0f;

    //TC_LOG_ERROR("scripts", "_getItemGearScore for {} - {}", proto->ItemId, proto->Name1);

    ItemStatBonus istats = {};
    //for (uint8 i = 0; i != MAX_BOT_ITEM_MOD; ++i)
    //    TC_LOG_ERROR("scripts", "_getItemGearScore at {} {}", uint32(i), istats[i]);

    ScalingStatDistributionEntry const* ssd = proto->ScalingStatDistribution ? sScalingStatDistributionStore.LookupEntry(proto->ScalingStatDistribution) : NULL;

    uint32 ssd_level = me->GetLevel();
    if (ssd && ssd_level > ssd->Maxlevel)
        ssd_level = ssd->Maxlevel;

    ScalingStatValuesEntry const* ssv = proto->ScalingStatValue ? sScalingStatValuesStore.LookupEntry(ssd_level) : NULL;

    for (uint8 i = 0; i != MAX_ITEM_PROTO_STATS; ++i)
    {
        uint32 statType = 0;
        int32  val      = 0;
        if (ssd && ssv)
        {
            if (ssd->StatID[i] < 0)
                continue;
            statType = ssd->StatID[i];
            val = (ssv->getssdMultiplier(proto->ScalingStatValue) * ssd->Bonus[i]) / 10000;
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

        istats[statType] += val;
    }

    istats[BOT_STAT_MOD_RESIST_HOLY] += proto->HolyRes;
    istats[BOT_STAT_MOD_RESIST_FIRE] += proto->FireRes;
    istats[BOT_STAT_MOD_RESIST_NATURE] += proto->NatureRes;
    istats[BOT_STAT_MOD_RESIST_FROST] += proto->FrostRes;
    istats[BOT_STAT_MOD_RESIST_SHADOW] += proto->ShadowRes;
    istats[BOT_STAT_MOD_RESIST_ARCANE] += proto->ArcaneRes;

    istats[BOT_STAT_MOD_ARMOR] += proto->Armor;
    istats[BOT_STAT_MOD_BLOCK_VALUE] += proto->Block;

    EquipmentInfo const* einfo = BotDataMgr::GetBotEquipmentInfo(me->GetEntry());
    if (forslot > BOT_SLOT_RANGED || proto->ItemId != einfo->ItemEntry[forslot])
    {
        if (ssv)
        {
            int32 extraDPS = ssv->getDPSMod(proto->ScalingStatValue);
            if (extraDPS)
            {
                float average = extraDPS * proto->Delay / 1000.0f;
                float mod = ssv->isTwoHand(proto->ScalingStatValue) ? 0.2f : 0.3f;

                istats[BOT_STAT_MOD_DAMAGE_MIN] += (1.0f - mod) * average;
                istats[BOT_STAT_MOD_DAMAGE_MAX] += (1.0f + mod) * average;
            }
        }
        else
        {
            istats[BOT_STAT_MOD_DAMAGE_MIN] += proto->Damage[0].DamageMin + proto->Damage[1].DamageMin;
            istats[BOT_STAT_MOD_DAMAGE_MAX] += proto->Damage[0].DamageMax + proto->Damage[1].DamageMax;
        }

        if (_botclass == BOT_CLASS_DRUID)
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
                istats[BOT_STAT_MOD_FERAL_ATTACK_POWER] += feral_bonus;
        }
    }

    for (uint8 i = 0; i != MAX_ENCHANTMENT_SLOT && item != nullptr; ++i)
    {
        EnchantmentSlot eslot = EnchantmentSlot(i);
        uint32 enchant_id = item->GetEnchantmentId(eslot);
        if (!enchant_id)
            continue;

        SpellItemEnchantmentEntry const* pEnchant = sSpellItemEnchantmentStore.LookupEntry(enchant_id);
        if (!pEnchant)
            continue;

        uint32 enchant_display_type;
        uint32 enchant_amount;
        uint32 enchant_spell_id;

        for (uint8 s = 0; s != MAX_ITEM_ENCHANTMENT_EFFECTS; ++s)
        {
            enchant_display_type = pEnchant->Effect[s];
            enchant_amount = pEnchant->EffectPointsMin[s];
            enchant_spell_id = pEnchant->EffectArg[s];

            switch (enchant_display_type)
            {
                case ITEM_ENCHANTMENT_TYPE_DAMAGE:
                    istats[BOT_STAT_MOD_DAMAGE_MIN] += enchant_amount;
                    istats[BOT_STAT_MOD_DAMAGE_MAX] += enchant_amount;
                    break;
                case ITEM_ENCHANTMENT_TYPE_RESISTANCE:
                    if (!enchant_amount)
                    {
                        ItemRandomSuffixEntry const* item_rand = sItemRandomSuffixStore.LookupEntry(abs(item->GetItemRandomPropertyId()));
                        if (item_rand)
                        {
                            for (uint8 k = 0; k < MAX_ITEM_ENCHANTMENT_EFFECTS; ++k)
                            {
                                if (item_rand->Enchantment[k] == enchant_id)
                                {
                                    enchant_amount = uint32((item_rand->AllocationPct[k] * item->GetItemSuffixFactor()) / 10000);
                                    break;
                                }
                            }
                        }
                    }
                    istats[BOT_STAT_MOD_RESISTANCE_START + enchant_spell_id] += enchant_amount;
                    break;
                case ITEM_ENCHANTMENT_TYPE_STAT:
                {
                    if (!enchant_amount)
                    {
                        ItemRandomSuffixEntry const* item_rand_suffix = sItemRandomSuffixStore.LookupEntry(abs(item->GetItemRandomPropertyId()));
                        if (item_rand_suffix)
                        {
                            for (uint8 k = 0; k != MAX_ITEM_ENCHANTMENT_EFFECTS; ++k)
                            {
                                if (item_rand_suffix->Enchantment[k] == enchant_id)
                                {
                                    enchant_amount = uint32((item_rand_suffix->AllocationPct[k] * item->GetItemSuffixFactor()) / 10000);
                                    break;
                                }
                            }
                        }
                    }

                    switch (enchant_spell_id)
                    {
                        case ITEM_MOD_MANA:
                        case ITEM_MOD_HEALTH:
                        case ITEM_MOD_AGILITY:
                        case ITEM_MOD_STRENGTH:
                        case ITEM_MOD_INTELLECT:
                        case ITEM_MOD_SPIRIT:
                        case ITEM_MOD_STAMINA:
                        case ITEM_MOD_DEFENSE_SKILL_RATING:
                        case ITEM_MOD_DODGE_RATING:
                        case ITEM_MOD_PARRY_RATING:
                        case ITEM_MOD_BLOCK_RATING:
                        case ITEM_MOD_HIT_MELEE_RATING:
                        case ITEM_MOD_HIT_RANGED_RATING:
                        case ITEM_MOD_HIT_SPELL_RATING:
                        case ITEM_MOD_CRIT_MELEE_RATING:
                        case ITEM_MOD_CRIT_RANGED_RATING:
                        case ITEM_MOD_CRIT_SPELL_RATING:
                        case ITEM_MOD_HASTE_MELEE_RATING:
                        case ITEM_MOD_HASTE_RANGED_RATING:
                        case ITEM_MOD_HASTE_SPELL_RATING:
                        case ITEM_MOD_HIT_RATING:
                        case ITEM_MOD_CRIT_RATING:
                        case ITEM_MOD_HASTE_RATING:
                        case ITEM_MOD_RESILIENCE_RATING:
                        case ITEM_MOD_EXPERTISE_RATING:
                        case ITEM_MOD_ATTACK_POWER:
                        case ITEM_MOD_RANGED_ATTACK_POWER:
                        case ITEM_MOD_MANA_REGENERATION:
                        case ITEM_MOD_ARMOR_PENETRATION_RATING:
                        case ITEM_MOD_SPELL_POWER:
                        case ITEM_MOD_HEALTH_REGEN:
                        case ITEM_MOD_SPELL_PENETRATION:
                        case ITEM_MOD_BLOCK_VALUE:
                            istats[enchant_spell_id] += enchant_amount;
                            break;
                        default:
                            break;
                    }
                    break;
                }
            }
        }
    }

    //for (uint8 i = 0; i != MAX_BOT_ITEM_MOD; ++i)
    //    TC_LOG_ERROR("scripts", "_getItemGearScore total {} {}", uint32(i), istats[i]);

    //stats are fetched, not calculate
    float itemScore = 0.0f;

    for (uint8 i = 0; i != MAX_BOT_ITEM_MOD; ++i)
        itemScore += istats[i] * _getStatScore(i);

    float itemGearScore = CalculateItemGearScore(me->GetEntry(), me->GetLevel(), GetBotClass(), GetSpec(), forslot, iproto);
    itemScore += itemGearScore;

    //TC_LOG_ERROR("scripts", "_getItemGearScore total score {}", itemScore);
    return itemScore;
}

void bot_ai::_saveStats()
{
    NpcBotStats stats;
    stats.entry = me->GetEntry();
    stats.maxhealth = me->GetMaxHealth();
    stats.maxpower = me->GetMaxPower(_botclass == BOT_CLASS_DRUID ? POWER_MANA : me->GetPowerType());
    stats.strength = GetTotalBotStat(BOT_STAT_MOD_STRENGTH);
    stats.agility = GetTotalBotStat(BOT_STAT_MOD_AGILITY);
    stats.stamina = GetTotalBotStat(BOT_STAT_MOD_STAMINA);
    stats.intellect = GetTotalBotStat(BOT_STAT_MOD_INTELLECT);
    stats.spirit = GetTotalBotStat(BOT_STAT_MOD_SPIRIT);
    stats.armor = me->GetArmor();
    stats.defense = me->GetDefenseSkillValue();
    stats.resHoly = me->GetResistance(SPELL_SCHOOL_HOLY) + resistbonus[SPELL_SCHOOL_HOLY-1];
    stats.resFire = me->GetResistance(SPELL_SCHOOL_FIRE) + resistbonus[SPELL_SCHOOL_FIRE-1];
    stats.resNature = me->GetResistance(SPELL_SCHOOL_NATURE) + resistbonus[SPELL_SCHOOL_NATURE-1];
    stats.resFrost = me->GetResistance(SPELL_SCHOOL_FROST) + resistbonus[SPELL_SCHOOL_FROST-1];
    stats.resShadow = me->GetResistance(SPELL_SCHOOL_SHADOW) + resistbonus[SPELL_SCHOOL_SHADOW-1];
    stats.resArcane = me->GetResistance(SPELL_SCHOOL_ARCANE) + resistbonus[SPELL_SCHOOL_ARCANE-1];
    stats.blockPct = me->GetUnitBlockChance(BASE_ATTACK, me);
    stats.dodgePct = me->GetUnitDodgeChance(BASE_ATTACK, me);
    stats.parryPct = me->GetUnitParryChance(BASE_ATTACK, me);
    stats.critPct = crit + me->GetTotalAuraModifier(SPELL_AURA_MOD_WEAPON_CRIT_PERCENT) + me->GetTotalAuraModifier(SPELL_AURA_MOD_CRIT_PCT);
    stats.attackPower = me->GetTotalAttackPowerValue(BASE_ATTACK);
    stats.spellPower = me->SpellBaseDamageBonusDone(SPELL_SCHOOL_MASK_MAGIC);
    stats.spellPen = spellpen;
    stats.hastePct = std::max<float>(haste, 0.f);
    stats.hitBonusPct = std::max<float>(hit, 0.f);
    stats.expertise = expertise;
    stats.armorPenPct = me->GetCreatureArmorPenetrationCoef();

    BotDataMgr::SaveNpcBotStats(&stats);
}

//!Copied from Player::CastItemUseSpell
void bot_ai::_castBotItemUseSpell(Item const* item, SpellCastTargets const& targets/*, uint8 cast_count, uint32 glyphIndex*/)
{
    ItemTemplate const* proto = item->GetTemplate();

    // use triggered flag only for items with many spell casts and for not first cast
    uint8 count = 0;

    // item spells casted at use
    SpellInfo const* spellInfo;
    for (uint8 i = 0; i != MAX_ITEM_PROTO_SPELLS; ++i)
    {
        _Spell const& spellData = proto->Spells[i];
        if (!spellData.SpellId || spellData.SpellTrigger != ITEM_SPELLTRIGGER_ON_USE)
            continue;

        spellInfo = sSpellMgr->GetSpellInfo(spellData.SpellId);
        if (!spellInfo)
            continue;

        Spell* spell = new Spell(me, spellInfo, (count > 0) ? TRIGGERED_FULL_MASK : TRIGGERED_NONE);
        //spell->m_CastItem = item; // DO NOT TAKE ITEM
        //spell->m_cast_count = cast_count;                   // set count of casts
        //spell->m_glyphIndex = glyphIndex;                   // glyph index
        spell->prepare(targets);
        ++count;
    }

    // Item enchantments spells casted at use
    for (uint8 e_slot = 0; e_slot != MAX_ENCHANTMENT_SLOT; ++e_slot)
    {
        uint32 enchant_id = item->GetEnchantmentId(EnchantmentSlot(e_slot));
        SpellItemEnchantmentEntry const* pEnchant = sSpellItemEnchantmentStore.LookupEntry(enchant_id);
        if (!pEnchant)
            continue;

        for (uint8 s = 0; s != MAX_ITEM_ENCHANTMENT_EFFECTS; ++s)
        {
            if (pEnchant->Effect[s] != ITEM_ENCHANTMENT_TYPE_USE_SPELL)
                continue;

            spellInfo = sSpellMgr->GetSpellInfo(pEnchant->EffectArg[s]);
            if (!spellInfo)
                continue;

            Spell* spell = new Spell(me, spellInfo, (count > 0) ? TRIGGERED_FULL_MASK : TRIGGERED_NONE);
            //spell->m_CastItem = item; // DO NOT TAKE ITEM
            //spell->m_cast_count = cast_count;               // set count of casts
            //spell->m_glyphIndex = glyphIndex;               // glyph index
            spell->prepare(targets);
            ++count;
        }
    }
}

Item* bot_ai::GetEquipsByGuid(ObjectGuid itemGuid) const
{
    for (uint8 i = BOT_SLOT_MAINHAND; i != BOT_INVENTORY_SIZE; ++i)
    {
        if (Item* item = _equips[i])
            if (item->GetGUID() == itemGuid)
                return item;
    }

    return nullptr;
}

uint32 bot_ai::GetEquipDisplayId(uint8 slot) const
{
    int32 displayId = -1;
    if (_equips[slot])
    {
        NpcBotTransmogData const* transmogData = BotDataMgr::SelectNpcBotTransmogs(me->GetEntry());
        if (transmogData && BotMgr::IsTransmogEnabled() &&
            (_equips[slot]->GetTemplate()->ItemId == transmogData->transmogs[slot].first || BotMgr::TransmogUseEquipmentSlots()))
        {
            int32 item_id = transmogData->transmogs[slot].second;
            if (item_id > 0)
            {
                if (ItemTemplate const* proto = sObjectMgr->GetItemTemplate(uint32(item_id)))
                {
                    displayId = proto->DisplayInfoID;
                }
                else
                {
                    TC_LOG_ERROR("scripts", "bot_ai::GetEquipDisplayId(): invalid item Id {} for bot {} {} slot {}",
                        item_id, me->GetEntry(), me->GetName(), uint32(slot));
                }
            }
            else
                displayId = item_id;
        }
        if (displayId == -1)
            displayId = int32(_equips[slot]->GetTemplate()->DisplayInfoID);
    }

    return uint32(std::max<int32>(displayId, 0));
}

bool bot_ai::UnEquipAll(ObjectGuid receiver)
{
    bool suc = true;
    for (uint8 i = BOT_SLOT_MAINHAND; i != BOT_INVENTORY_SIZE; ++i)
    {
        if (!(i <= BOT_SLOT_RANGED ? _resetEquipment(i, receiver) : _unequip(i, receiver)))
        {
            suc = false;
            break;
        }
    }

    return suc;
}

bool bot_ai::HasRealEquipment() const
{
    EquipmentInfo const* einfo = BotDataMgr::GetBotEquipmentInfo(me->GetEntry());
    ASSERT(einfo, "Trying to call HasRealEquipment for bot with no equip info!");

    for (uint8 i = BOT_SLOT_MAINHAND; i != BOT_INVENTORY_SIZE; ++i)
    {
        if (Item const* item = GetEquips(i))
        {
            if (i > BOT_SLOT_RANGED || einfo->ItemEntry[i] != item->GetEntry())
                return true;
        }
    }

    return false;
}

float bot_ai::GetAverageItemLevel() const
{
    float sum = 0.f;
    uint32 count = 0;
    for (uint8 i = BOT_SLOT_MAINHAND; i != BOT_INVENTORY_SIZE; ++i)
    {
        if (_equips[i] && !(/*i == BOT_SLOT_TABARD || */i == BOT_SLOT_OFFHAND || i == BOT_SLOT_RANGED || i == BOT_SLOT_BODY))
        {
            if (ItemTemplate const* itemProto = _equips[i]->GetTemplate())
            {
                ++count;
                sum += itemProto->GetItemLevelIncludingQuality();
            }
        }
    }

    return !count ? 0.f : (sum / float(count));
}
std::pair<float, float> bot_ai::GetBotGearScores() const
{
    return CalculateBotGearScore(me->GetEntry(), me->GetLevel(), GetBotClass(), GetSpec(), _equips);
}
/////////
//ROLES//
/////////
GossipOptionIcon bot_ai::GetRoleIcon(uint32 role) const
{
    return HasRole(role) ? BOT_ICON_ON : BOT_ICON_OFF;
}

uint32 bot_ai::GetRoleString(uint32 role)
{
    switch (role)
    {
        case BOT_ROLE_TANK:                 return BOT_TEXT_TANK;
        case BOT_ROLE_TANK_OFF:             return BOT_TEXT_TANK_OFF;
        case BOT_ROLE_DPS:                  return BOT_TEXT_DPS;
        case BOT_ROLE_HEAL:                 return BOT_TEXT_HEAL;
        case BOT_ROLE_RANGED:               return BOT_TEXT_RANGED;
        case BOT_ROLE_GATHERING_MINING:     return BOT_TEXT_MINER;
        case BOT_ROLE_GATHERING_HERBALISM:  return BOT_TEXT_HERBALIST;
        case BOT_ROLE_GATHERING_SKINNING:   return BOT_TEXT_SKINNER;
        case BOT_ROLE_GATHERING_ENGINEERING:return BOT_TEXT_ENGINEER;
        case BOT_ROLE_AUTOLOOT:             return BOT_TEXT_LOOTING;
        case BOT_ROLE_AUTOLOOT_POOR:        return BOT_TEXT_POOR;
        case BOT_ROLE_AUTOLOOT_COMMON:      return BOT_TEXT_COMMON;
        case BOT_ROLE_AUTOLOOT_UNCOMMON:    return BOT_TEXT_UNCOMMON;
        case BOT_ROLE_AUTOLOOT_RARE:        return BOT_TEXT_RARE;
        case BOT_ROLE_AUTOLOOT_EPIC:        return BOT_TEXT_EPIC;
        case BOT_ROLE_AUTOLOOT_LEGENDARY:   return BOT_TEXT_LEGENDARY;
        default:                            return BOT_TEXT_UNKNOWN;
    }
}

void bot_ai::ToggleRole(uint32 role, bool force)
{
    if (!force && roleTimer > lastdiff)
        return;

    roleTimer = 350; //delay next attempt (prevent abuse)

    if (HasRole(role))
    {
        //linked roles
        if (role & BOT_ROLE_TANK)
            role |= BOT_ROLE_TANK_OFF;

        _roleMask &= ~role;
    }
    else
    {
        //linked roles
        if (role & BOT_ROLE_TANK_OFF)
            role |= BOT_ROLE_TANK;

        _roleMask |= role;
    }

    BotDataMgr::UpdateNpcBotData(me->GetEntry(), NPCBOT_UPDATE_ROLES, &_roleMask);

    //Update passives
    shouldUpdateStats = true;
}

uint32 bot_ai::DefaultRolesForClass(uint8 m_class, uint8 spec)
{
    uint32 roleMask = BOT_ROLE_DPS;

    //if (bot_ai::IsHealingClass(m_class))
    //    roleMask |= BOT_ROLE_HEAL;

    if (!bot_ai::IsMeleeClass(m_class))
    {
        switch (spec)
        {
            case BOT_SPEC_SHAMAN_ENHANCEMENT:
            case BOT_SPEC_DRUID_FERAL:
                break;
            default:
                roleMask |= BOT_ROLE_RANGED;
                break;
        }
    }

    return roleMask;
}

bool bot_ai::IsTank(Unit const* unit) const
{
    if (!unit || unit == me)
        return HasRole(BOT_ROLE_TANK);

    if (Creature const* bot = unit->ToCreature())
        return bot->GetBotAI() && bot->GetBotAI()->HasRole(BOT_ROLE_TANK);

    if (Player const* player = unit->ToPlayer())
    {
        if (Group const* gr = player->GetGroup())
        {
            if (gr->GetMemberFlags(unit->GetGUID()) & (MEMBER_FLAG_MAINTANK | MEMBER_FLAG_MAINASSIST))
                return true;
            if (gr->isLFGGroup() && sLFGMgr->GetRoles(unit->GetGUID()) & lfg::PLAYER_ROLE_TANK)
                return true;
        }
    }

    return false;
}

bool bot_ai::IsOffTank(Unit const* unit) const
{
    if (!unit || unit == me)
        return HasRole(BOT_ROLE_TANK_OFF);

    if (Creature const* bot = unit->ToCreature())
        return bot->GetBotAI() && bot->GetBotAI()->HasRole(BOT_ROLE_TANK_OFF);

    if (Player const* player = unit->ToPlayer())
    {
        if (Group const* gr = player->GetGroup())
        {
            if (gr->GetMemberFlags(unit->GetGUID()) & (MEMBER_FLAG_MAINTANK | MEMBER_FLAG_MAINASSIST))
                return true;
        }
    }

    return false;
}

bool bot_ai::CCed(Unit const* target, bool root)
{
    return target ? target->HasUnitState(UNIT_STATE_CONFUSED | UNIT_STATE_STUNNED | UNIT_STATE_FLEEING | UNIT_STATE_DISTRACTED | UNIT_STATE_CONFUSED_MOVE | UNIT_STATE_FLEEING_MOVE) || (root && (target->HasUnitState(UNIT_STATE_ROOT) || target->IsFrozen() || target->IsRooted())) : true;
}
//AI initialization common
//Called at ai reset, level change (spawned = true)
void bot_ai::DefaultInit()
{
    //only once
    if (spawned)
        return;

    spawned = true;

    if (!firstspawn)
    {
        me->RemoveAllAurasExceptType(SPELL_AURA_CONTROL_VEHICLE);
        RemoveItemClassEnchantments(); //clear rogue poisons / shaman ecnhants
        ApplyItemsSpells(); //restore item equip spells
    }
    else
    {
        InitRace();
        ASSERT(!me->GetBotAI());
        ASSERT(!me->GetBotPetAI());
        me->SetBotAI(this);
        BotLogger::Log(NPCBOT_LOG_SPAWN, me);
    }

    me->SetPvP(master->IsPvP() || IsWanderer());
    if (sWorld->IsFFAPvPRealm())
        me->SetByteFlag(UNIT_FIELD_BYTES_2, 1, UNIT_BYTE2_FLAG_FFA_PVP);
    else if (IAmFree())
        me->SetByteFlag(UNIT_FIELD_BYTES_2, 1, 0);

    InitSpec();
    InitRoles();

    if (IsWanderer())
    {
        _travel_node_cur = ASSERT_NOTNULL(BotDataMgr::GetClosestWanderNode(me));
        if (firstspawn && BotMgr::IsWanderingWorldBot(me))
            StartPotionTimer();
    }

    SetStats(true); // Class passives included

    if (!IsTempBot())
        ApplyRacials();

    if (firstspawn)
    {
        if (!IsTempBot())
        {
            InitFaction();
            InitOwner();
            InitEquips();
        }

        firstspawn = false;
    }
}

void bot_ai::ApplyRacials()
{
    uint8 myrace = me->GetRace();
    switch (myrace)
    {
        case RACE_HUMAN:
            RefreshAura(20598); //Human Spirit
            RefreshAura(20864); //Mace Specialization
            RefreshAura(20597); //Sword Specialization
            //RefreshAura(58985); //Perception pointless
            if (firstspawn)
                InitSpellMap(RACIAL_EVERY_MAN_FOR_HIMSELF, true, false);
            break;
        case RACE_ORC:
            RefreshAura(20573); //Hardiness
            RefreshAura(20574); //Axe Specialization
            //Blood Fury
            if (firstspawn)
                InitSpellMap(RaceSpellForClass(myrace, _botclass), true, false);
            break;
        case RACE_DWARF:
            RefreshAura(20595); //Gun Specialization
            RefreshAura(59224); //Mace Specialization
            RefreshAura(20596); //Frost Resistance
            if (firstspawn)
                InitSpellMap(RACIAL_STONEFORM, true, false);
            break;
        case RACE_NIGHTELF:
            RefreshAura(20583); //Nature Resistance
            RefreshAura(20582); //Quickness
            InitSpellMap(RACIAL_SHADOWMELD, true, false);
            break;
        case RACE_UNDEAD_PLAYER:
            RefreshAura(20579); //Shadow Resistance
            if (firstspawn)
                InitSpellMap(RACIAL_WILL_OF_THE_FORSAKEN, true, false);
            //cannibalize is skipped
            break;
        case RACE_TAUREN:
            RefreshAura(20550); //Endurance
            RefreshAura(20551); //Nature Resistance
            if (firstspawn)
                InitSpellMap(RACIAL_WARSTOMP, true, false);
            break;
        case RACE_GNOME:
            RefreshAura(20592); //Arcane Resistance
            RefreshAura(20591); //Expansive Mind
            if (firstspawn)
                InitSpellMap(RACIAL_ESCAPE_ARTIST, true, false);
            break;
        case RACE_TROLL:
            RefreshAura(20557); //Beast Slaying
            RefreshAura(20558); //Thrown Specialization
            RefreshAura(26290); //Bow Specialization
            RefreshAura(58943); //Da Voodoo Shuffle
            RefreshAura(20555); //Regeneration
            if (firstspawn)
                InitSpellMap(RACIAL_BERSERKING, true, false);
            break;
        case RACE_BLOODELF:
            RefreshAura(822); //Magic Resistance
            if (firstspawn)
                InitSpellMap(RaceSpellForClass(myrace, _botclass), true, false);
            break;
        case RACE_DRAENEI:
            RefreshAura(6562, uint8(!IAmFree())); //Heroic Presence (28878 is not present)
            RefreshAura(20579); //Shadow Resistance (universal since creatures do not lose cast time on damage anyways)
            if (firstspawn)
                InitSpellMap(RaceSpellForClass(myrace, _botclass), true, false);
            break;
        default:
            //TC_LOG_ERROR("entities.player", "bot_ai::ApplyRacePassives(): unknown race {} for bot {} ({})", uint32(me->GetRace()), me->GetName(), me->GetEntry());
            return;
    }
}

void bot_ai::InitFaction()
{
    NpcBotData const* npcBotData = BotDataMgr::SelectNpcBotData(me->GetEntry());
    ASSERT(npcBotData, "bot_ai::InitFaction(): data not found!");

    uint32 faction = npcBotData->faction;

    //if (faction == 14)
    //    faction = 35;

    me->SetFaction(faction);
    if (botPet)
        botPet->SetFaction(faction);
    const_cast<CreatureTemplate*>(me->GetCreatureTemplate())->faction = faction;
}

void bot_ai::InitRace()
{
    NpcBotExtras const* npcBotExtras = BotDataMgr::SelectNpcBotExtras(me->GetEntry());
    ASSERT(npcBotExtras, "bot_ai::InitRace: extra data not found!");

    me->SetByteValue(UNIT_FIELD_BYTES_0, 0, npcBotExtras->race); //set race
}

void bot_ai::InitOwner()
{
    NpcBotData const* npcBotData = BotDataMgr::SelectNpcBotData(me->GetEntry());
    ASSERT(npcBotData, "bot_ai::InitOwner(): data not found!");

    _ownerGuid = npcBotData->owner;
}

void bot_ai::InitRoles()
{
    if (IsTempBot())
    {
        _roleMask = BOT_ROLE_DPS;
        return;
    }
    else if (IAmFree())
    {
        //default roles
        _roleMask = DefaultRolesForClass(_botclass, GetSpec());
        return;
    }

    NpcBotData const* npcBotData = BotDataMgr::SelectNpcBotData(me->GetEntry());
    ASSERT(npcBotData, "bot_ai::InitRoles(): data not found!");

    _roleMask = npcBotData->roles;
}

void bot_ai::InitSpec()
{
    uint8 spec;
    if (IAmFree())
        spec = SelectSpecForClass(_botclass);
    else
    {
        NpcBotData const* npcBotData = BotDataMgr::SelectNpcBotData(me->GetEntry());
        ASSERT(npcBotData, "bot_ai::InitSpec(): data not found!");

        spec = npcBotData->spec;
    }

    //TC_LOG_ERROR("entities.unit", "bot_ai::InitSpec(): bot {} class {} spec: {}", me->GetEntry(), uint32(_botclass), uint32(spec));

    if (spec < BOT_SPEC_BEGIN || spec > BOT_SPEC_END)
    {
        TC_LOG_ERROR("entities.unit", "bot_ai::InitSpec(): spec ({}) is out of range for bot {}! Falling to default (1)...",
            uint32(spec), me->GetEntry());

        spec = BOT_SPEC_DEFAULT;
    }

    SetSpec(spec, false);
}

void bot_ai::SetSpec(uint8 spec, bool activate)
{
    ASSERT(spec >= BOT_SPEC_BEGIN && spec <= BOT_SPEC_END);

    _spec = spec;

    if (activate)
    {
        BotDataMgr::UpdateNpcBotData(me->GetEntry(), NPCBOT_UPDATE_SPEC, &spec);

        UnsummonAll(false);
        removeShapeshiftForm();
        //from DefaultInit
        me->RemoveAllAurasExceptType(SPELL_AURA_CONTROL_VEHICLE);
        //RemoveItemClassEnchants();
        ApplyItemsSpells();
        ApplyRacials();
        //from SetStats
        //InitPowers();
        InitSpells();
        ApplyClassPassives();
        InitHeals();

        me->SetPower(POWER_MANA, 0);
        me->SetPower(POWER_RAGE, 0);
        me->SetPower(POWER_ENERGY, 0);
    }
}

uint8 bot_ai::GetSpec() const
{
    return me->GetLevel() < 10 ? uint8(BOT_SPEC_DEFAULT) : _spec;
}

uint8 bot_ai::SelectSpecForClass(uint8 m_class)
{
    std::vector<uint8> specs;
    specs.reserve(3);
    switch (m_class)
    {
        case BOT_CLASS_WARRIOR: //any
            specs.push_back(BOT_SPEC_WARRIOR_ARMS);
            specs.push_back(BOT_SPEC_WARRIOR_FURY);
            specs.push_back(BOT_SPEC_WARRIOR_PROTECTION);
            break;
        case BOT_CLASS_PALADIN: //retri
            specs.push_back(BOT_SPEC_PALADIN_RETRIBUTION);
            break;
        case BOT_CLASS_HUNTER: //any
            specs.push_back(BOT_SPEC_HUNTER_BEASTMASTERY);
            specs.push_back(BOT_SPEC_HUNTER_MARKSMANSHIP);
            specs.push_back(BOT_SPEC_HUNTER_SURVIVAL);
            break;
        case BOT_CLASS_ROGUE: //any
            specs.push_back(BOT_SPEC_ROGUE_ASSASINATION);
            specs.push_back(BOT_SPEC_ROGUE_COMBAT);
            specs.push_back(BOT_SPEC_ROGUE_SUBTLETY);
            break;
        case BOT_CLASS_PRIEST: //discipline, shadow
            specs.push_back(BOT_SPEC_PRIEST_DISCIPLINE);
            specs.push_back(BOT_SPEC_PRIEST_SHADOW);
            break;
        case BOT_CLASS_DEATH_KNIGHT: //any
            specs.push_back(BOT_SPEC_DK_BLOOD);
            specs.push_back(BOT_SPEC_DK_FROST);
            specs.push_back(BOT_SPEC_DK_UNHOLY);
            break;
        case BOT_CLASS_SHAMAN: //elem, enh
            specs.push_back(BOT_SPEC_SHAMAN_ELEMENTAL);
            specs.push_back(BOT_SPEC_SHAMAN_ENHANCEMENT);
            break;
        case BOT_CLASS_MAGE: //fire, frost
            specs.push_back(BOT_SPEC_MAGE_FIRE);
            specs.push_back(BOT_SPEC_MAGE_FROST);
            break;
        case BOT_CLASS_WARLOCK: //affli, destr
            specs.push_back(BOT_SPEC_WARLOCK_AFFLICTION);
            specs.push_back(BOT_SPEC_WARLOCK_DESTRUCTION);
            break;
        case BOT_CLASS_DRUID: //balance, feral
            specs.push_back(BOT_SPEC_DRUID_BALANCE);
            specs.push_back(BOT_SPEC_DRUID_FERAL);
            break;
        default:
            specs.push_back(BOT_SPEC_DEFAULT);
            break;
    }

    return specs.size() == 1 ? specs.front() : Trinity::Containers::SelectRandomContainerElement(specs);
}

uint32 bot_ai::TextForSpec(uint8 spec)
{
    switch (spec)
    {
        case BOT_SPEC_WARRIOR_ARMS:         return BOT_TEXT_SPEC_ARMS;
        case BOT_SPEC_WARRIOR_FURY:         return BOT_TEXT_SPEC_FURY;
        case BOT_SPEC_WARRIOR_PROTECTION:   return BOT_TEXT_SPEC_PROTECTION;
        case BOT_SPEC_PALADIN_HOLY:         return BOT_TEXT_SPEC_HOLY;
        case BOT_SPEC_PALADIN_PROTECTION:   return BOT_TEXT_SPEC_PROTECTION;
        case BOT_SPEC_PALADIN_RETRIBUTION:  return BOT_TEXT_SPEC_RETRIBUTION;
        case BOT_SPEC_HUNTER_BEASTMASTERY:  return BOT_TEXT_SPEC_BEASTMASTERY;
        case BOT_SPEC_HUNTER_MARKSMANSHIP:  return BOT_TEXT_SPEC_MARKSMANSHIP;
        case BOT_SPEC_HUNTER_SURVIVAL:      return BOT_TEXT_SPEC_SURVIVAL;
        case BOT_SPEC_ROGUE_ASSASINATION:   return BOT_TEXT_SPEC_ASSASINATION;
        case BOT_SPEC_ROGUE_COMBAT:         return BOT_TEXT_SPEC_COMBAT;
        case BOT_SPEC_ROGUE_SUBTLETY:       return BOT_TEXT_SPEC_SUBTLETY;
        case BOT_SPEC_PRIEST_DISCIPLINE:    return BOT_TEXT_SPEC_DISCIPLINE;
        case BOT_SPEC_PRIEST_HOLY:          return BOT_TEXT_SPEC_HOLY;
        case BOT_SPEC_PRIEST_SHADOW:        return BOT_TEXT_SPEC_SHADOW;
        case BOT_SPEC_DK_BLOOD:             return BOT_TEXT_SPEC_BLOOD;
        case BOT_SPEC_DK_FROST:             return BOT_TEXT_SPEC_FROST;
        case BOT_SPEC_DK_UNHOLY:            return BOT_TEXT_SPEC_UNHOLY;
        case BOT_SPEC_SHAMAN_ELEMENTAL:     return BOT_TEXT_SPEC_ELEMENTAL;
        case BOT_SPEC_SHAMAN_ENHANCEMENT:   return BOT_TEXT_SPEC_ENHANCEMENT;
        case BOT_SPEC_SHAMAN_RESTORATION:   return BOT_TEXT_SPEC_RESTORATION;
        case BOT_SPEC_MAGE_ARCANE:          return BOT_TEXT_SPEC_ARCANE;
        case BOT_SPEC_MAGE_FIRE:            return BOT_TEXT_SPEC_FIRE;
        case BOT_SPEC_MAGE_FROST:           return BOT_TEXT_SPEC_FROST;
        case BOT_SPEC_WARLOCK_AFFLICTION:   return BOT_TEXT_SPEC_AFFLICTION;
        case BOT_SPEC_WARLOCK_DEMONOLOGY:   return BOT_TEXT_SPEC_DEMONOLOGY;
        case BOT_SPEC_WARLOCK_DESTRUCTION:  return BOT_TEXT_SPEC_DESTRUCTION;
        case BOT_SPEC_DRUID_BALANCE:        return BOT_TEXT_SPEC_BALANCE;
        case BOT_SPEC_DRUID_FERAL:          return BOT_TEXT_SPEC_FERAL;
        case BOT_SPEC_DRUID_RESTORATION:    return BOT_TEXT_SPEC_RESTORATION;
        case BOT_SPEC_DEFAULT: default:     return BOT_TEXT_SPEC_UNKNOWN;
    }
}

bool bot_ai::IsValidSpecForClass(uint8 m_class, uint8 spec)
{
    switch (m_class)
    {
        case BOT_CLASS_WARRIOR:
            switch (spec)
            {
                case BOT_SPEC_WARRIOR_ARMS:
                case BOT_SPEC_WARRIOR_FURY:
                case BOT_SPEC_WARRIOR_PROTECTION:
                    return true;
                default:
                    break;
            }
            break;
        case BOT_CLASS_PALADIN:
            switch (spec)
            {
                case BOT_SPEC_PALADIN_HOLY:
                case BOT_SPEC_PALADIN_PROTECTION:
                case BOT_SPEC_PALADIN_RETRIBUTION:
                    return true;
                default:
                    break;
            }
            break;
        case BOT_CLASS_HUNTER:
            switch (spec)
            {
                case BOT_SPEC_HUNTER_BEASTMASTERY:
                case BOT_SPEC_HUNTER_MARKSMANSHIP:
                case BOT_SPEC_HUNTER_SURVIVAL:
                    return true;
                default:
                    break;
            }
            break;
        case BOT_CLASS_ROGUE:
            switch (spec)
            {
                case BOT_SPEC_ROGUE_ASSASINATION:
                case BOT_SPEC_ROGUE_COMBAT:
                case BOT_SPEC_ROGUE_SUBTLETY:
                    return true;
                default:
                    break;
            }
            break;
        case BOT_CLASS_PRIEST:
            switch (spec)
            {
                case BOT_SPEC_PRIEST_DISCIPLINE:
                case BOT_SPEC_PRIEST_HOLY:
                case BOT_SPEC_PRIEST_SHADOW:
                    return true;
                default:
                    break;
            }
            break;
        case BOT_CLASS_DEATH_KNIGHT:
            switch (spec)
            {
                case BOT_SPEC_DK_BLOOD:
                case BOT_SPEC_DK_FROST:
                case BOT_SPEC_DK_UNHOLY:
                    return true;
                default:
                    break;
            }
            break;
        case BOT_CLASS_SHAMAN:
            switch (spec)
            {
                case BOT_SPEC_SHAMAN_ELEMENTAL:
                case BOT_SPEC_SHAMAN_ENHANCEMENT:
                case BOT_SPEC_SHAMAN_RESTORATION:
                    return true;
                default:
                    break;
            }
            break;
        case BOT_CLASS_MAGE:
            switch (spec)
            {
                case BOT_SPEC_MAGE_ARCANE:
                case BOT_SPEC_MAGE_FIRE:
                case BOT_SPEC_MAGE_FROST:
                    return true;
                default:
                    break;
            }
            break;
        case BOT_CLASS_WARLOCK:
            switch (spec)
            {
                case BOT_SPEC_WARLOCK_AFFLICTION:
                case BOT_SPEC_WARLOCK_DEMONOLOGY:
                case BOT_SPEC_WARLOCK_DESTRUCTION:
                    return true;
                default:
                    break;
            }
            break;
        case BOT_CLASS_DRUID:
            switch (spec)
            {
                case BOT_SPEC_DRUID_BALANCE:
                case BOT_SPEC_DRUID_FERAL:
                case BOT_SPEC_DRUID_RESTORATION:
                    return true;
                default:
                    break;
            }
            break;
        case BOT_CLASS_BM:
        case BOT_CLASS_SPHYNX:
        case BOT_CLASS_ARCHMAGE:
        case BOT_CLASS_DREADLORD:
        case BOT_CLASS_SPELLBREAKER:
        case BOT_CLASS_DARK_RANGER:
        case BOT_CLASS_NECROMANCER:
        case BOT_CLASS_SEA_WITCH:
        case BOT_CLASS_CRYPT_LORD:
            return spec == BOT_SPEC_DEFAULT;
        default:
            break;
    }
    return false;
}

void bot_ai::InitEquips()
{
    EquipmentInfo const* einfo = BotDataMgr::GetBotEquipmentInfo(me->GetEntry());
    ASSERT(einfo, "Trying to spawn bot with no equip info!");

    NpcBotData const* npcBotData = BotDataMgr::SelectNpcBotData(me->GetEntry());
    ASSERT(npcBotData, "bot_ai::InitEquips(): data not found!");

    if (IsWanderer())
    {
        GenerateRand();
        uint8 lvl = me->GetLevel();
        std::ostringstream gss;
        gss << "bot_ai::InitEquips(): Wanderer bot " << me->GetName() << " id " << me->GetEntry() << ' ' << "level " << uint32(lvl) << " generated gear:";
        for (uint8 i = BOT_SLOT_MAINHAND; i < BOT_INVENTORY_SIZE; ++i)
        {
            if (i == BOT_SLOT_OFFHAND && (!_canUseOffHand() || (lvl < 10 && IsCastingClass(_botclass))))
                continue;
            if ((i == BOT_SLOT_FINGER1 || i == BOT_SLOT_FINGER2 || i == BOT_SLOT_NECK || i == BOT_SLOT_SHOULDERS) && lvl < 20)
                continue;
            if ((i == BOT_SLOT_TRINKET1 || i == BOT_SLOT_TRINKET2 || i == BOT_SLOT_HEAD) && lvl < 30)
                continue;

            Item* item = BotDataMgr::GenerateWanderingBotItem(i, _botclass, lvl, [this, lslot = i](ItemTemplate const* proto) {
                if (!_canEquip(proto, lslot, true))
                    return false;

                if (me->GetLevel() >= DEFAULT_MAX_LEVEL && me->GetMap()->IsBattlegroundOrArena() && Rand() < 50)
                {
                    if (Rand() < 20 && proto->ItemLevel < 245)
                        return false;
                    if (Rand() < 10 && proto->ItemLevel < 264)
                        return false;

                    switch (lslot)
                    {
                        case BOT_SLOT_HEAD:
                        case BOT_SLOT_SHOULDERS:
                        case BOT_SLOT_CHEST:
                        case BOT_SLOT_WAIST:
                        case BOT_SLOT_LEGS:
                        case BOT_SLOT_FEET:
                        case BOT_SLOT_WRIST:
                        case BOT_SLOT_HANDS:
                            if (!std::any_of(proto->ItemStat.cbegin(), proto->ItemStat.cend(), [](_ItemStat const& stat) {
                                return stat.ItemStatType == ITEM_MOD_RESILIENCE_RATING && stat.ItemStatValue > 0;
                            }))
                                return false;
                            break;
                        default:
                            break;
                    }
                }

                switch (GetSpec())
                {
                    case BOT_SPEC_WARRIOR_ARMS:
                        switch (lslot)
                        {
                            case BOT_SLOT_MAINHAND:
                                return proto->InventoryType == INVTYPE_2HWEAPON;
                            default:
                                break;
                        }
                        break;
                    case BOT_SPEC_WARRIOR_FURY:
                        switch (lslot)
                        {
                            case BOT_SLOT_MAINHAND:
                                return (me->GetLevel() < 60) ? (proto->InventoryType == INVTYPE_WEAPON || proto->InventoryType == INVTYPE_WEAPONMAINHAND) :
                                    (proto->InventoryType == INVTYPE_2HWEAPON);
                            case BOT_SLOT_OFFHAND:
                                return (me->GetLevel() < 60) ? (proto->InventoryType == INVTYPE_WEAPON || proto->InventoryType == INVTYPE_WEAPONOFFHAND) :
                                    (proto->InventoryType == INVTYPE_2HWEAPON);
                            default:
                                break;
                        }
                        break;
                    case BOT_SPEC_WARRIOR_PROTECTION:
                        switch (lslot)
                        {
                            case BOT_SLOT_MAINHAND:
                                return proto->InventoryType == INVTYPE_WEAPON || proto->InventoryType == INVTYPE_WEAPONMAINHAND;
                            case BOT_SLOT_OFFHAND:
                                return proto->InventoryType == INVTYPE_SHIELD;
                            default:
                                break;
                        }
                        break;
                    case BOT_SPEC_PALADIN_PROTECTION:
                        switch (lslot)
                        {
                            case BOT_SLOT_MAINHAND:
                                if (!(proto->InventoryType == INVTYPE_WEAPON || proto->InventoryType == INVTYPE_WEAPONMAINHAND))
                                    return false;
                                if (me->GetLevel() < 70)
                                    break;
                                return !std::any_of(proto->ItemStat.cbegin(), proto->ItemStat.cend(), [](_ItemStat const& stat) {
                                    return stat.ItemStatType == ITEM_MOD_INTELLECT && stat.ItemStatValue > 0;
                                });
                            case BOT_SLOT_OFFHAND:
                                if (!(proto->InventoryType == INVTYPE_SHIELD))
                                    return false;
                                if (me->GetLevel() < 70)
                                    break;
                                return !std::any_of(proto->ItemStat.cbegin(), proto->ItemStat.cend(), [](_ItemStat const& stat) {
                                    return stat.ItemStatType == ITEM_MOD_INTELLECT && stat.ItemStatValue > 0;
                                });
                            default:
                                break;
                        }
                        break;
                    case BOT_SPEC_PALADIN_HOLY:
                    case BOT_SPEC_SHAMAN_ELEMENTAL:
                    case BOT_SPEC_SHAMAN_RESTORATION:
                        switch (lslot)
                        {
                            case BOT_SLOT_MAINHAND:
                                if (!(proto->InventoryType == INVTYPE_WEAPON || proto->InventoryType == INVTYPE_WEAPONMAINHAND))
                                    return false;
                                if (me->GetLevel() < 70)
                                    break;
                                return std::any_of(proto->ItemStat.cbegin(), proto->ItemStat.cend(), [](_ItemStat const& stat) {
                                    return stat.ItemStatType == ITEM_MOD_INTELLECT && stat.ItemStatValue > 0;
                                });
                            case BOT_SLOT_OFFHAND:
                                if (!(proto->InventoryType == INVTYPE_SHIELD))
                                    return false;
                                if (me->GetLevel() < 70)
                                    break;
                                return std::any_of(proto->ItemStat.cbegin(), proto->ItemStat.cend(), [](_ItemStat const& stat) {
                                    return stat.ItemStatType == ITEM_MOD_INTELLECT && stat.ItemStatValue > 0;
                                });
                            default:
                                if (me->GetLevel() < 70)
                                    break;
                                return std::any_of(proto->ItemStat.cbegin(), proto->ItemStat.cend(), [](_ItemStat const& stat) {
                                    return stat.ItemStatType == ITEM_MOD_INTELLECT && stat.ItemStatValue > 0;
                                });
                        }
                        break;
                    case BOT_SPEC_PALADIN_RETRIBUTION:
                        switch (lslot)
                        {
                            case BOT_SLOT_MAINHAND:
                                return proto->InventoryType == INVTYPE_2HWEAPON;
                            default:
                                break;
                        }
                        break;
                    case BOT_SPEC_HUNTER_BEASTMASTERY:
                    case BOT_SPEC_HUNTER_MARKSMANSHIP:
                    case BOT_SPEC_HUNTER_SURVIVAL:
                        switch (lslot)
                        {
                            case BOT_SLOT_TRINKET1: case BOT_SLOT_TRINKET2:
                                break;
                            default:
                                if (me->GetLevel() < 70)
                                    break;
                                return std::any_of(proto->ItemStat.cbegin(), proto->ItemStat.cend(), [](_ItemStat const& stat) {
                                    return stat.ItemStatType == ITEM_MOD_AGILITY && stat.ItemStatValue > 0;
                                });
                                break;
                        }
                        break;
                    case BOT_SPEC_ROGUE_ASSASINATION:
                        switch (lslot)
                        {
                            case BOT_SLOT_MAINHAND: case BOT_SLOT_OFFHAND:
                                return proto->SubClass == ITEM_SUBCLASS_WEAPON_DAGGER;
                            case BOT_SLOT_RANGED:
                                return me->GetLevel() < 64 || proto->SubClass == ITEM_SUBCLASS_WEAPON_THROWN;
                            default:
                                break;
                        }
                        break;
                    case BOT_SPEC_ROGUE_COMBAT:
                        switch (lslot)
                        {
                            case BOT_SLOT_MAINHAND: case BOT_SLOT_OFFHAND:
                                return proto->SubClass == ITEM_SUBCLASS_WEAPON_SWORD || proto->SubClass == ITEM_SUBCLASS_WEAPON_AXE;
                            case BOT_SLOT_RANGED:
                                return me->GetLevel() < 64 || proto->SubClass == ITEM_SUBCLASS_WEAPON_THROWN;
                            default:
                                break;
                        }
                        break;
                    case BOT_SPEC_ROGUE_SUBTLETY:
                        switch (lslot)
                        {
                            case BOT_SLOT_MAINHAND: case BOT_SLOT_OFFHAND:
                                return proto->SubClass == ITEM_SUBCLASS_WEAPON_MACE;
                            case BOT_SLOT_RANGED:
                                return me->GetLevel() < 64 || proto->SubClass == ITEM_SUBCLASS_WEAPON_THROWN;
                            default:
                                break;
                        }
                        break;
                    case BOT_SPEC_DK_FROST:
                        switch (lslot)
                        {
                            case BOT_SLOT_MAINHAND:
                                return me->GetLevel() < 61 || proto->InventoryType == INVTYPE_2HWEAPON;
                            default:
                                break;
                        }
                        break;
                    case BOT_SPEC_SHAMAN_ENHANCEMENT:
                        switch (lslot)
                        {
                            case BOT_SLOT_OFFHAND:
                                return proto->InventoryType == INVTYPE_WEAPON || proto->InventoryType == INVTYPE_WEAPONOFFHAND;
                            case BOT_SLOT_TRINKET1: case BOT_SLOT_TRINKET2:
                                break;
                            default:
                                if (me->GetLevel() < 70)
                                    break;
                                return std::any_of(proto->ItemStat.cbegin(), proto->ItemStat.cend(), [](_ItemStat const& stat) {
                                    return stat.ItemStatType == ITEM_MOD_AGILITY && stat.ItemStatValue > 0;
                                });
                        }
                        break;
                    case BOT_SPEC_DRUID_FERAL:
                        switch (lslot)
                        {
                            case BOT_SLOT_TRINKET1: case BOT_SLOT_TRINKET2:
                                break;
                            case BOT_SLOT_MAINHAND:
                                if (proto->InventoryType != INVTYPE_2HWEAPON)
                                    return false;
                            [[fallthrough]];
                            default:
                                if (me->GetLevel() < 70)
                                    break;
                                return std::any_of(proto->ItemStat.cbegin(), proto->ItemStat.cend(), [](_ItemStat const& stat) {
                                    return stat.ItemStatType == ITEM_MOD_AGILITY && stat.ItemStatValue > 0;
                                });
                        }
                        break;
                    case BOT_SPEC_DRUID_BALANCE:
                        switch (lslot)
                        {
                            case BOT_SLOT_TRINKET1: case BOT_SLOT_TRINKET2:
                                break;
                            default:
                                if (me->GetLevel() < 70)
                                    break;
                                return std::any_of(proto->ItemStat.cbegin(), proto->ItemStat.cend(), [](_ItemStat const& stat) {
                                    return stat.ItemStatType == ITEM_MOD_INTELLECT && stat.ItemStatValue > 0;
                                });
                        }
                        break;
                    default:
                        break;
                }

                return true;
            });

            if (!item)
            {
                if (i <= BOT_SLOT_RANGED && einfo->ItemEntry[i] != 0)
                {
                    TC_LOG_WARN("npcbots", "Wanderer bot {} id {} level {} can't generate req gear in slot {}, generating standard item!",
                        me->GetName(), me->GetEntry(), uint32(me->GetLevel()), uint32(i));

                    item = Item::CreateItem(einfo->ItemEntry[i], 1);
                    ASSERT(item, "Failed to init standard Item for wandering bot!");
                    _equips[i] = item;
                }
            }
            else
            {
                _equips[i] = item;
                if (GetSpec() != BOT_SPEC_DEFAULT && BotDataMgr::GenerateWanderingBotItemEnchants(item, i, GetSpec())) {}

                gss << " [" << uint32(i) << "] " << _equips[i]->GetTemplate()->Name1 << " (" << _equips[i]->GetEntry() << ')';
            }
        }
        TC_LOG_TRACE("npcbots", "{}", gss.str());
    }
    else
    {
        CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_NPCBOT_EQUIP_BY_ITEM_INSTANCE);
        //        0            1                2      3         4        5      6             7                 8           9           10    11    12         13
        //"SELECT creatorGuid, giftCreatorGuid, count, duration, charges, flags, enchantments, randomPropertyId, durability, playedTime, text, guid, itemEntry, owner_guid "
        //  "FROM item_instance WHERE guid IN (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)", CONNECTION_SYNCH

        std::array<uint32, BOT_INVENTORY_SIZE> assigned_item_guids{};
        for (uint8 i = 0; i != BOT_INVENTORY_SIZE; ++i)
        {
            stmt->setUInt32(i, npcBotData->equips[i]);
            assigned_item_guids[i] = npcBotData->equips[i];
        }

        PreparedQueryResult iiresult = CharacterDatabase.Query(stmt);

        if (!iiresult) //blank bot - fill with standard items
        {
            for (uint8 i = 0; i != MAX_EQUIPMENT_ITEMS; ++i)
            {
                uint32 itemId = einfo->ItemEntry[i];
                if (!itemId)
                    continue;

                Item* item = Item::CreateItem(itemId, 1, nullptr);
                ASSERT(item, "Failed to init standard Item for bot!");
                _equips[i] = item;
            }
        }
        else
        {
            Field* fields2;
            do
            {
                fields2 = iiresult->Fetch();
                uint32 itemGuidLow = fields2[11].GetUInt32();
                uint32 itemId = fields2[12].GetUInt32();
                Item* item = new Item;
                ASSERT(item->LoadFromDB(itemGuidLow, ObjectGuid::Empty, fields2, itemId));
                //gonna find where to store our new item
                bool found = false;
                for (uint8 i = BOT_SLOT_MAINHAND; i != BOT_INVENTORY_SIZE; ++i)
                {
                    if (npcBotData->equips[i] == itemGuidLow && !_equips[i])
                    {
                        _equips[i] = item;
                        found = true;
                        BotLogger::Log(NPCBOT_LOG_INIT_EQUIP, me, uint32(i), uint32(itemGuidLow), uint32(itemId));
                        break;
                    }
                }
                ASSERT(found);
                for (uint8 i = 0; i != BOT_INVENTORY_SIZE; ++i)
                {
                    if (assigned_item_guids[i] == itemGuidLow)
                        assigned_item_guids[i] = 0;
                }

            } while (iiresult->NextRow());
        }

        for (uint8 i = 0; i != BOT_INVENTORY_SIZE; ++i)
        {
            if (assigned_item_guids[i] != 0)
                TC_LOG_ERROR("npcbots", "InitEquips: bot {} {} owner {} has item guid {} assigned to slot {} which doesn't exist in DB!",
                    me->GetEntry(), me->GetName(), _ownerGuid, assigned_item_guids[i], uint32(i));
        }
    }

    //visualize
    for (uint8 i = BOT_SLOT_MAINHAND; i <= BOT_SLOT_RANGED; ++i)
    {
        if (CanChangeEquip(i) && _equips[i])
        {
            NpcBotTransmogData const* transmogData = BotDataMgr::SelectNpcBotTransmogs(me->GetEntry());
            if (einfo->ItemEntry[i] != _equips[i]->GetEntry() && transmogData && BotMgr::IsTransmogEnabled() && (transmogData->transmogs[i].first == _equips[i]->GetEntry() || BotMgr::TransmogUseEquipmentSlots()))
                me->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID + i, uint32(std::max<int32>(transmogData->transmogs[i].second, 0)));
            else
                me->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID + i, _equips[i]->GetEntry());
        }
        else if (einfo->ItemEntry[i])
            me->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID + i, einfo->ItemEntry[i]);
    }

    //apply weapons' parameters
    if (Item const* MH = _equips[BOT_SLOT_MAINHAND])
    {
        uint32 itemId = MH->GetEntry();
        if (einfo->ItemEntry[0] != itemId)
        {
            if (ItemTemplate const* proto = sObjectMgr->GetItemTemplate(itemId))
            {
                if (RespectEquipsAttackTime())
                    me->SetAttackTime(BASE_ATTACK, proto->Delay);
                ApplyItemBonuses(BOT_SLOT_MAINHAND);
            }
        }
    }
    if (Item const* OH = _equips[BOT_SLOT_OFFHAND])
    {
        uint32 itemId = OH->GetEntry();
        if (ItemTemplate const* proto = sObjectMgr->GetItemTemplate(itemId))
        {
            if (einfo->ItemEntry[1] != itemId)
                ApplyItemBonuses(BOT_SLOT_OFFHAND);

            if (proto->Class == ITEM_CLASS_WEAPON)
            {
                if (RespectEquipsAttackTime())
                    me->SetAttackTime(OFF_ATTACK, proto->Delay);
                me->SetCanDualWield(true);
            }
            else if (proto->Class == ITEM_CLASS_ARMOR && proto->SubClass == ITEM_SUBCLASS_ARMOR_SHIELD)
            {
                if (me->GetCreatureTemplate()->flags_extra & CREATURE_FLAG_EXTRA_NO_BLOCK)
                    const_cast<CreatureTemplate*>(me->GetCreatureTemplate())->flags_extra &= ~CREATURE_FLAG_EXTRA_NO_BLOCK;
            }
        }
    }
    if (Item const* RH = _equips[BOT_SLOT_RANGED])
    {
        uint32 itemId = RH->GetEntry();
        if (einfo->ItemEntry[2] != itemId)
        {
            if (ItemTemplate const* proto = sObjectMgr->GetItemTemplate(itemId))
            {
                if (proto->Class == ITEM_CLASS_WEAPON)
                    if (RespectEquipsAttackTime())
                        me->SetAttackTime(RANGED_ATTACK, proto->Delay);

                ApplyItemBonuses(BOT_SLOT_RANGED);
            }
        }
    }

    for (uint8 i = BOT_SLOT_RANGED + 1; i != BOT_INVENTORY_SIZE; ++i)
        ApplyItemBonuses(i);

    ApplyItemSetBonuses(nullptr, true);

    for (uint8 i = 0; i != MAX_EQUIPMENT_ITEMS; ++i)
    {
        if (_equips[i] == nullptr && einfo->ItemEntry[i] != 0)
        {
            if (i == BOT_SLOT_OFFHAND && !_canUseOffHand())
            {
                me->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID + i, uint32(0));
                continue;
            }

            //if bot has no equips but equip template then use those
            Item* item = Item::CreateItem(einfo->ItemEntry[i], 1, nullptr);
            ASSERT(item, "Failed to init standard Item for bot point 2!");
            _equips[i] = item;

            me->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID + i, einfo->ItemEntry[i]);
            if (i == BOT_SLOT_OFFHAND)
            {
                if (ItemTemplate const* proto = sObjectMgr->GetItemTemplate(einfo->ItemEntry[i]))
                {
                    if (proto->Class == ITEM_CLASS_WEAPON)
                    {
                        me->SetAttackTime(OFF_ATTACK, _botclass == BOT_CLASS_ROGUE ? 1400 : 1800);
                        me->SetCanDualWield(true);
                    }
                    else if (proto->Class == ITEM_CLASS_ARMOR && proto->SubClass == ITEM_SUBCLASS_ARMOR_SHIELD)
                    {
                        if (me->GetCreatureTemplate()->flags_extra & CREATURE_FLAG_EXTRA_NO_BLOCK)
                            const_cast<CreatureTemplate*>(me->GetCreatureTemplate())->flags_extra &= ~CREATURE_FLAG_EXTRA_NO_BLOCK;
                    }
                }
            }
        }
    }

    for (uint8 slot = BOT_SLOT_MAINHAND; slot < BOT_INVENTORY_SIZE; ++slot)
    {
        if (_equips[slot] && IsUsableItem(_equips[slot]))
        {
            uint32 slotMask = 1ul << slot;
            ASSERT(!(_usableItemSlotsMask & slotMask));
            _usableItemSlotsMask |= slotMask;
        }
    }
}

void bot_ai::FindMaster()
{
    //totally free
    if (!_ownerGuid)
        return;
    if (me->IsInWorld() && (!_atHome || _evadeMode))
        return;
    if (!BotMgr::IsClassEnabled(_botclass))
        return;

    //delay
    if (checkMasterTimer > lastdiff)
        return;

    checkMasterTimer = urand(1000, 3000);

    //already have master
    if (!IAmFree())
        return;
    if (HasBotCommandState(BOT_COMMAND_UNBIND))
        return;

    if (Player* player = ObjectAccessor::FindPlayerByLowGUID(_ownerGuid))
    {
        //prevent bot being screwed up because of wrong flags
        if (player->IsGameMaster() || player->GetSession()->isLogingOut() || player->GetSession()->PlayerLogout())
            return;

        if (!SetBotOwner(player))
            return; //fail

        //if (!IsTempBot())
        //    BotWhisper("Hey...", master);
    }
}

uint32 bot_ai::CalculateOwnershipCheckTime()
{
    NpcBotData const* npcBotData = BotDataMgr::SelectNpcBotData(me->GetEntry());
    if (!npcBotData->owner)
        return 0;

    if (!IAmFree() || BotMgr::GetOwnershipExpireMode() == BOT_OWNERSHIP_EXPIRE_OFFLINE)
        return static_cast<uint32>(std::min<uint32>(BotMgr::GetOwnershipExpireTime(), urand(3 * MINUTE, 7 * MINUTE)) * IN_MILLISECONDS);

    return static_cast<uint32>(std::max<time_t>(time_t(npcBotData->hire_time + BotMgr::GetOwnershipExpireTime() + 1) - time(0), 5) * IN_MILLISECONDS);
}

bool bot_ai::IAmFree() const
{
    if (!_ownerGuid)
        return true;
    if (_ownerGuid != master->GetGUID().GetRawValue())
        return true;
    //if (!me->HasUnitTypeMask(UNIT_MASK_MINION))
    //    return true;

    return false;
    //return (!_ownerGuid || _ownerGuid != master->GetGUID() || !me->HasUnitTypeMask(UNIT_MASK_MINION));
    //        //has owner   and   //owner is found          and        //bound to owner
}

//UTILITIES
void bot_ai::_AddItemTemplateLink(Player const* forPlayer, ItemTemplate const* item, std::ostringstream &str) const
{
    //color
    str << "|c";
    switch (item->Quality)
    {
        case ITEM_QUALITY_POOR:     str << "ff9d9d9d"; break;  //GREY
        case ITEM_QUALITY_NORMAL:   str << "ffffffff"; break;  //WHITE
        case ITEM_QUALITY_UNCOMMON: str << "ff1eff00"; break;  //GREEN
        case ITEM_QUALITY_RARE:     str << "ff0070dd"; break;  //BLUE
        case ITEM_QUALITY_EPIC:     str << "ffa335ee"; break;  //PURPLE
        case ITEM_QUALITY_LEGENDARY:str << "ffff8000"; break;  //ORANGE
        case ITEM_QUALITY_ARTIFACT: str << "ffe6cc80"; break;  //LIGHT YELLOW
        case ITEM_QUALITY_HEIRLOOM: str << "ffe6cc80"; break;  //LIGHT YELLOW
        default:                    str << "ff000000"; break;  //UNK BLACK
    }
    str << "|Hitem:" << uint32(item->ItemId) << ':';

    //permanent enchantment, 3 gems, 4 unknowns, reporter_level (9)
    str << "0:0:0:0:0:0:0:0:0";

    //name
    std::string name = item->Name1;
    _LocalizeItem(forPlayer, name, item->ItemId);
    str << "|h[" << name << "]|h|r";

    //max in stack
    if (item->BuyCount > 1)
        str<< "|cff009900x" << item->BuyCount << ".|r";
    else
        str << "|cff009900.|r";
}
// |TInterface\\Icons\\INV_<iconName>:<iconSize>|t|color|Hitem:item_id:perm_ench_id:gem1:gem2:gem3:0:random_property:suffix_factor:reporter_level|h[name]|h|r
// |TInterface\\Icons\\INV_Misc_Staff_01:16|t|cffa335ee|Hitem:812:0:0:0:0:0:0:0:70|h[Glowing Brightwood Staff]|h|r
void bot_ai::_AddItemLink(Player const* forPlayer, Item const* item, std::ostringstream &str, bool addIcon) const
{
    ItemTemplate const* proto = item->GetTemplate();
    //ItemRandomSuffixEntry const* item_rand = sItemRandomSuffixStore.LookupEntry(abs(item->GetItemRandomPropertyId()));
    uint32 g1 = 0, g2 = 0, g3 = 0;
    //uint32 bpoints = 0;
    std::string name = proto->Name1;
    std::string suffix = "";

    //icon
    if (addIcon)
    {
        ItemDisplayInfoEntry const* itemDisplayEntry = sItemDisplayInfoStore.LookupEntry(item->GetTemplate()->DisplayInfoID);
        if (itemDisplayEntry)
            str << "|TInterface\\Icons\\" << itemDisplayEntry->InventoryIcon << ":16|t";
    }

    //color
    str << "|c";
    switch (proto->Quality)
    {
        case ITEM_QUALITY_POOR:     str << "ff9d9d9d"; break;  //GREY
        case ITEM_QUALITY_NORMAL:   str << "ffffffff"; break;  //WHITE
        case ITEM_QUALITY_UNCOMMON: str << "ff1eff00"; break;  //GREEN
        case ITEM_QUALITY_RARE:     str << "ff0070dd"; break;  //BLUE
        case ITEM_QUALITY_EPIC:     str << "ffa335ee"; break;  //PURPLE
        case ITEM_QUALITY_LEGENDARY:str << "ffff8000"; break;  //ORANGE
        case ITEM_QUALITY_ARTIFACT: str << "ffe6cc80"; break;  //LIGHT YELLOW
        case ITEM_QUALITY_HEIRLOOM: str << "ffe6cc80"; break;  //LIGHT YELLOW
        default:                    str << "ff000000"; break;  //UNK BLACK
    }
    str << "|Hitem:" << proto->ItemId << ':';

    //permanent enchantment
    str << item->GetEnchantmentId(PERM_ENCHANTMENT_SLOT) << ':';
    //gems 3
    for (uint32 slot = SOCK_ENCHANTMENT_SLOT; slot != SOCK_ENCHANTMENT_SLOT + MAX_ITEM_PROTO_SOCKETS; ++slot)
    {
        uint32 eId = item->GetEnchantmentId(EnchantmentSlot(slot));

        switch (slot - SOCK_ENCHANTMENT_SLOT)
        {
            case 0: g1 = eId;   break;
            case 1: g2 = eId;   break;
            case 2: g3 = eId;   break;
        }
    }
    str << g1 << ':' << g2 << ':' << g3 << ':';
    //always zero
    str << 0 << ':';
    //random property
    str << item->GetItemRandomPropertyId() << ':';
    str << item->GetItemSuffixFactor() << ':';

    //reporter level
    str << uint32(me->GetLevel());

    //name
    _LocalizeItem(forPlayer, name, suffix, item);

    str << "|h[" << name;
    if (suffix.length() > 0)
        str << ' ' << suffix;
    str <<"]|h|r";

    //quantity
    if (item->GetCount() > 1)
        str << "x" << item->GetCount() << ' ';

    //TC_LOG_ERROR("entities.player", "bot_ai::_AddItemLink(): {}", str.str());
}
//Unused
void bot_ai::_AddQuestLink(Player const* forPlayer, Quest const* quest, std::ostringstream &str) const
{
    std::string questTitle = quest->GetTitle();
    _LocalizeQuest(forPlayer, questTitle, quest->GetQuestId());
    str << "|cFFEFFD00|Hquest:" << quest->GetQuestId() << ':' << quest->GetQuestLevel() << "|h[" << questTitle << "]|h|r";
}
//Unsused
void bot_ai::_AddWeaponSkillLink(Player const* forPlayer, SpellInfo const* spellInfo, std::ostringstream &str, uint32 skillid) const
{
    uint32 loc = forPlayer->GetSession()->GetSessionDbcLocale();
    str << "|cff00ffff|Hspell:" << spellInfo->Id << "|h[" << spellInfo->SpellName[loc] << " : " << master->GetSkillValue(skillid) << " /" << master->GetMaxSkillValue(skillid) << "]|h|r";
}
//|cff71d5ff|Hspell:21563|h[Command]|h|r
void bot_ai::_AddSpellLink(Player const* forPlayer, SpellInfo const* spellInfo, std::ostringstream &str, bool color/* = true*/) const
{
    uint32 loc = forPlayer->GetSession()->GetSessionDbcLocale();
    str << "|c";

    if (color)
    {
        switch (GetFirstSchoolInMask(spellInfo->GetSchoolMask()))
        {
            case SPELL_SCHOOL_NORMAL:       str << "ffffff00"; break; //YELLOW
            case SPELL_SCHOOL_HOLY:         str << "ffffe680"; break; //LIGHT YELLOW
            case SPELL_SCHOOL_FIRE:         str << "ffff8000"; break; //ORANGE
            case SPELL_SCHOOL_NATURE:       str << "ff4dff4d"; break; //GREEN
            case SPELL_SCHOOL_FROST:        str << "ff80ffff"; break; //LIGHT BLUE
            case SPELL_SCHOOL_SHADOW:       str << "ff8080ff"; break; //DARK BLUE
            case SPELL_SCHOOL_ARCANE:       str << "ffff80ff"; break; //LIGHT PURPLE
            default:                        str << "ffffffff"; break; //UNK WHITE
        }
    }
    else
        str << "ffffffff"; //default white

    str << "|Hspell:" << spellInfo->Id << "|h[" << spellInfo->SpellName[loc] << "]|h|r";
}
//Unused
void bot_ai::_AddProfessionLink(Player const* forPlayer, SpellInfo const* spellInfo, std::ostringstream &str, uint32 skillId) const
{
    ASSERT(master->HasSkill(skillId));
    // |cffffd000|Htrade:4037:1:150:1:6AAAAAAAAAAAAAAAAAAAAAAOAADAAAAAAAAAAAAAAAAIAAAAAAAAA|h[Engineering]|h|r
    uint32 loc = forPlayer->GetSession()->GetSessionDbcLocale();
    SkillLineEntry const* skillInfo = sSkillLineStore.LookupEntry(skillId);
    if (skillInfo)
    {
        uint32 curValue = master->GetPureSkillValue(skillId);
        uint32 maxValue  = master->GetPureMaxSkillValue(skillId);
        str << "|cffffd000|Htrade:" << spellInfo->Id << ':' << curValue << ':' << maxValue << ':' << master->GetGUID().GetCounter() << ":6AAAAAAAAAAAAAAAAAAAAAAOAADAAAAAAAAAAAAAAAAIAAAAAAAAA" << "|h[" << skillInfo->DisplayName[loc] << "]|h|r";
    }
}
//Localization
void bot_ai::_LocalizeItem(Player const* forPlayer, std::string &itemName, uint32 entry) const
{
    uint32 loc = forPlayer->GetSession()->GetSessionDbLocaleIndex();
    std::wstring wnamepart;

    ItemLocale const* itemInfo = sObjectMgr->GetItemLocale(entry);
    if (!itemInfo)
        return;

    if (itemInfo->Name.size() > loc && !itemInfo->Name[loc].empty())
    {
        const std::string name = itemInfo->Name[loc];
        if (Utf8FitTo(name, wnamepart))
            itemName = name;
    }
}

void bot_ai::_LocalizeItem(Player const* forPlayer, std::string &itemName, std::string &suffix, Item const* item) const
{
    uint32 loc = forPlayer->GetSession()->GetSessionDbLocaleIndex();
    std::wstring wnamepart;

    ItemLocale const* itemInfo = sObjectMgr->GetItemLocale(item->GetEntry());
    if (loc > 0 && itemInfo && itemInfo->Name.size() > loc && !itemInfo->Name[loc].empty())
    {
        const std::string name = itemInfo->Name[loc];
        if (Utf8FitTo(name, wnamepart))
            itemName = name;
    }

    int32 randomPropId = item->GetItemRandomPropertyId();
    //TC_LOG_ERROR("entities.player", "bot_ai::_LocalizeItem(): randomPropId = {}", randomPropId);
    if (!randomPropId)
        return;

    if (randomPropId > 0)
    {
        if (ItemRandomPropertiesEntry const* item_rand = sItemRandomPropertiesStore.LookupEntry(randomPropId))
        {
            std::array<char const*, 16> const& suffs = item_rand->Name;
            //if (suffs)
            {
                //for (uint8 i = 0; i != MAX_LOCALES; ++i)
                //    TC_LOG_ERROR("entities.player", "bot_ai::_LocalizeItem(): rand prop suffix for loc {} = {}", i, suffs[i]);
                suffix = suffs[loc];
            }
        }
    }
    else
    {
        if (ItemRandomSuffixEntry const* item_rand = sItemRandomSuffixStore.LookupEntry(-randomPropId))
        {
            std::array<char const*, 16> const& suffs = item_rand->Name;
            //if (suffs)
            {
                //for (uint8 i = 0; i != MAX_LOCALES; ++i)
                //    TC_LOG_ERROR("entities.player", "bot_ai::_LocalizeItem(): rand suff suffix for loc {} = {}", i, suffs[i]);
                suffix = suffs[loc];
            }
        }
    }
}

void bot_ai::_LocalizeQuest(Player const* forPlayer, std::string &questTitle, uint32 entry) const
{
    uint32 loc = forPlayer->GetSession()->GetSessionDbLocaleIndex();
    std::wstring wnamepart;

    QuestLocale const* questInfo = sObjectMgr->GetQuestLocale(entry);
    if (!questInfo)
        return;

    if (questInfo->Title.size() > loc && !questInfo->Title[loc].empty())
    {
        const std::string title = questInfo->Title[loc];
        if (Utf8FitTo(title, wnamepart))
            questTitle = title;
    }
}

void bot_ai::_LocalizeCreature(Player const* forPlayer, std::string &creatureName, uint32 entry) const
{
    uint32 loc = forPlayer->GetSession()->GetSessionDbLocaleIndex();
    std::wstring wnamepart;

    CreatureLocale const* creatureInfo = sObjectMgr->GetCreatureLocale(entry);
    if (!creatureInfo)
        return;

    if (creatureInfo->Name.size() > loc && !creatureInfo->Name[loc].empty())
    {
        const std::string title = creatureInfo->Name[loc];
        if (Utf8FitTo(title, wnamepart))
            creatureName = title;
    }
}

void bot_ai::_LocalizeGameObject(Player const* forPlayer, std::string &gameobjectName, uint32 entry) const
{
    uint32 loc = forPlayer->GetSession()->GetSessionDbLocaleIndex();
    std::wstring wnamepart;

    GameObjectLocale const* gameObjectInfo = sObjectMgr->GetGameObjectLocale(entry);
    if (!gameObjectInfo)
        return;

    if (gameObjectInfo->Name.size() > loc && !gameObjectInfo->Name[loc].empty())
    {
        const std::string title = gameObjectInfo->Name[loc];
        if (Utf8FitTo(title, wnamepart))
            gameobjectName = title;
    }
}

void bot_ai::_LocalizeSpell(Player const* forPlayer, std::string &spellName, uint32 entry) const
{
    uint32 loc = forPlayer->GetSession()->GetSessionDbcLocale();
    std::wstring wnamepart;

    SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(entry);
    if (!spellInfo)
    {
        spellName = LocalizedNpcText(forPlayer, BOT_TEXT_UNKNOWN);
        return;
    }

    std::string title = spellInfo->SpellName[loc];
    if (Utf8FitTo(title, wnamepart))
        spellName = title;
    else
        spellName = spellInfo->SpellName[sWorld->GetDefaultDbcLocale()];
}

void bot_ai::BotJump(Position const* pos, bool count)
{
    if (count)
        ++_jumpCount;

    me->BotStopMovement();
    me->GetMotionMaster()->MoveJump(*pos, me->GetExactDist2d(pos->m_positionX, pos->m_positionY), 10.0f);
}

bool bot_ai::UpdateImpossibleChase(Unit const* target)
{
    if (_chaseTimer > lastdiff || me->isMoving() || !IAmFree())
        return false;

    if (JumpingOrFalling())
        return false;

    if (_jumpCount >= 3)
    {
        me->AttackStop();
        Evade();
        return true;
    }

    if (_unreachableCount < 5)
    {
        if ((IsRanged() ? me->GetDistance(target) > 40.0f : !me->IsWithinMeleeRange(target)) ||
            (target->GetTypeId() == TYPEID_UNIT && !me->IsWithinLOSInMap(target, LINEOFSIGHT_ALL_CHECKS, VMAP::ModelIgnoreFlags::M2)))
        {
            ++_unreachableCount;
            ResetChaseTimer(target);
            BotMovement(BOT_MOVE_POINT, target, nullptr, false);
        }
        else
            _unreachableCount = 0;

        return true;
    }

    if (target->IsPlayer() && (!me->IsWithinDist(target, HasRole(BOT_ROLE_RANGED) ? 65 : 40) || me->IsWithinDist(target, HasRole(BOT_ROLE_RANGED) ? 35 : 10)))
        return false;

    _unreachableCount = 0;

    ResetChaseTimer(target);

    BotJump(target);
    return true;
}

void bot_ai::ResetChaseTimer(Position const* /*pos*/)
{
    _chaseTimer = IsWanderer() ? 5000 : 20000;
}

void bot_ai::ResetChase(Position const* pos)
{
    if (!IAmFree())
        return;

    ResetChaseTimer(pos);
    _unreachableCount = 0;
    _jumpCount = 0;
}

void bot_ai::ResetEngageTimer(uint32 delay)
{
    _engageTimer = delay;
}

void bot_ai::OnStartAttack(Unit const* u)
{
    if (u->GetGUID() != _lastTargetGuid)
    {
        ResetChase(u);
        _lastTargetGuid = u->GetGUID();
    }
}

bool bot_ai::StartAttack(Unit const* u, bool force)
{
    if (HasBotCommandState(BOT_COMMAND_ATTACK) && !force)
        return false;

    SetBotCommandState(BOT_COMMAND_ATTACK);
    OnStartAttack(u);
    return true;
}

void bot_ai::JustEnteredCombat(Unit* u)
{
    _atHome = false;

    //clear gossip during combat. See CheckAuras() for restore
    if (me->HasNpcFlag(UNIT_NPC_FLAG_GOSSIP))
        me->RemoveNpcFlag(UNIT_NPC_FLAG_GOSSIP);

    _evadeMode = false;
    _evadeCount = 0;
    evadeDelayTimer = 0;
    AbortTeleport();

    ResetChase(u);

    if (IsLastOrder(BOT_ORDER_PULL, 0, u->GetGUID()))
        CompleteOrder(_orders.front());

    if (IAmFree() && me->GetVictim() && me->GetVictim() != u &&
        (me->getAttackers().empty() || (me->getAttackers().size() == 1u && *me->getAttackers().begin() == u)) &&
        me->GetVictim()->GetVictim() != me && !(me->GetVictim()->IsInCombat() || me->GetVictim()->IsInCombatWith(me)))
    {
        bool byspell = false;
        switch (_botclass)
        {
            case BOT_CLASS_DRUID:
                byspell = GetBotStance() == BOT_STANCE_NONE || GetBotStance() == DRUID_MOONKIN_FORM;
                break;
            case BOT_CLASS_PRIEST:
            case BOT_CLASS_MAGE:
            case BOT_CLASS_WARLOCK:
            case BOT_CLASS_SHAMAN:
            case BOT_CLASS_SPHYNX:
            case BOT_CLASS_ARCHMAGE:
                byspell = true;
                break;
            default:
                break;
        }

        if (CanBotAttack(u, byspell))
        {
            me->AttackStop();
            me->BotStopMovement();
            SetBotCommandState(BOT_COMMAND_COMBATRESET); //reset AttackStart()
            me->Attack(u, !HasRole(BOT_ROLE_RANGED));
        }
    }
}
//killer may be NULL
void bot_ai::JustDied(Unit* u)
{
    AbortTeleport();
    AbortAwaitStateRemoval();
    KillEvents(false);
    CancelAllOrders();

    if (me->GetVehicle())
        me->ExitVehicle();

    if (me->GetTransport())
    {
        me->ClearUnitState(UNIT_STATE_IGNORE_PATHFINDING);
        me->GetTransport()->RemovePassenger(me);
    }

    if (IsTempBot())
    {
        //TC_LOG_ERROR("entities.player", "Unsummoning temp bot {} ({}), owner: {} ({})...",
        //    me->GetName(), me->GetGUID().ToString(), master->GetName(), master->GetGUID().ToString());

        if (!IAmFree())
            master->GetBotMgr()->RemoveBot(me->GetGUID(), BOT_REMOVE_UNSUMMON);

        me->AddObjectToRemoveList();
        return;
    }
    else if (!IAmFree())
    {
        if (Group* gr = master->GetGroup())
            if (gr->IsMember(me->GetGUID()))
                gr->SendUpdate();
    }

    if (IsWanderer() && me->GetMap()->IsBattlegroundOrArena())
    {
        if (Battleground const* bg = GetBG())
        {
            TeamId my_team = BotDataMgr::GetTeamIdForFaction(me->GetFaction());
            if (WorldSafeLocsEntry const* gy = bg->GetClosestGraveyardForBot(*me, my_team == TEAM_HORDE ? HORDE : ALLIANCE))
            {
                Position pos(gy->Loc.X, gy->Loc.Y, gy->Loc.Z, me->GetOrientation());
                Events.AddEventAtOffset([me = me, pos = pos]() { BotMgr::TeleportBot(me, me->GetMap(), &pos, true); }, 5s);
            }
        }
    }
    else if (u && (u->IsPvP() || u->IsControlledByPlayer() || u->IsNPCBotOrPet()))
    {
        TC_LOG_DEBUG("npcbots", "{} {} id {} class {} level {} WAS KILLED BY {} {} id {} class {} level {} on their way to {}!",
            IsWanderer() ? "Wandering bot" : "Bot", me->GetName(), me->GetEntry(), uint32(_botclass), uint32(me->GetLevel()),
            (u->IsPlayer() ? "player" : u->IsNPCBot() ? u->ToCreature()->GetBotAI()->IsWanderer() ? "wandering bot" : "bot" : u->IsNPCBotPet() ? "botpet" : "creature"),
            u->GetName(), u->GetEntry(), uint32(u->GetClass()), uint32(u->GetLevel()),
            IsWanderer() ? _travel_node_cur->GetName() : "''");
    }

    _reviveTimer = (IsWanderer() && !(u && u->IsControlledByPlayer())) ? REVIVE_TIMER_MEDIUM :
        IAmFree() ? REVIVE_TIMER_DEFAULT : master->InBattleground() ? REVIVE_TIMER_SHORT / 2 : REVIVE_TIMER_SHORT;
    _atHome = false;
    _evadeMode = false;
    spawned = false;
    _botAwaitState = BOT_AWAIT_NONE;

    ++_deathsCount;
}
//This is triggered before SetDeathState(JUST_DIED) call
//attacker may be NULL
void bot_ai::OnDeath([[maybe_unused]] Unit* attacker/* = nullptr*/)
{
    if (AuraEffect const* sstone = me->GetDummyAuraEffect(SPELLFAMILY_GENERIC, 92, 0))
    {
        uint32 spell_id;
        switch (sstone->GetBase()->GetId())
        {
            case 20707: spell_id = 3026;  break;        // rank 1
            case 20762: spell_id = 20758; break;        // rank 2
            case 20763: spell_id = 20759; break;        // rank 3
            case 20764: spell_id = 20760; break;        // rank 4
            case 20765: spell_id = 20761; break;        // rank 5
            case 27239: spell_id = 27240; break;        // rank 6
            case 47883: spell_id = 47882; break;        // rank 7
            default:    spell_id = 0;     break;
        }
        _selfrez_spell_id = spell_id;
    }
    else
        _selfrez_spell_id = 0;
}

void bot_ai::KilledUnit(Unit* u)
{
    ++_killsCount;
    if (u->IsControlledByPlayer() || u->IsPvP() || u->IsNPCBotOrPet())
    {
        ++_pvpKillsCount;
        if (!me->GetMap()->IsBattlegroundOrArena())
        {
            if (IsWanderer())
            {
                TC_LOG_DEBUG("npcbots", "Wandering bot {} id {} class {} level {} KILLED {} {} id {} class {} level {} on their way to {}!",
                    me->GetName(), me->GetEntry(), uint32(_botclass), uint32(me->GetLevel()),
                    (u->IsPlayer() ? "player" : u->IsNPCBot() ? u->ToCreature()->GetBotAI()->IsWanderer() ? "wandering bot" : "bot" : u->IsNPCBotPet() ? "botpet" : "creature"),
                    u->GetName(), u->GetEntry(), uint32(u->GetClass()), uint32(u->GetLevel()),
                    _travel_node_cur->GetName());
            }
            else if (u->IsNPCBot() && u->ToCreature()->GetBotAI()->IsWanderer())
            {
                TC_LOG_DEBUG("npcbots", "Bot {} id {} class {} level {} KILLED wandering bot {} id {} class {} level {} on their way to {}!",
                    me->GetName(), me->GetEntry(), uint32(_botclass), uint32(me->GetLevel()),
                    u->GetName(), u->GetEntry(), uint32(u->GetClass()), uint32(u->GetLevel()),
                    IsWanderer() ? _travel_node_cur->GetName() : "''");
            }
        }
    }

    //handle BG kill BvP, BvB, BvC
    if (me->GetMap()->IsBattleground())
    {
        Battleground* bg = GetBG();
        //could be removed from BG
        if (bg && bg->GetBots().find(me->GetGUID()) != bg->GetBots().end() &&
            (u->IsNPCBot() ? bg->GetBots().find(u->GetGUID()) != bg->GetBots().end() :
            bg->GetPlayers().find(u->GetGUID()) != bg->GetPlayers().end()))
        {
            if (u->IsPlayer())
                bg->HandleBotKillPlayer(me, u->ToPlayer());
            else if (u->IsNPCBot())
                bg->HandleBotKillBot(me, u->ToCreature());
        }
        else if (bg && u->GetTypeId() == TYPEID_UNIT && !u->IsNPCBotOrPet())
            bg->HandleBotKillUnit(me, u->ToCreature());

        outdoorsTimer = 0;
    }

    if (u->isType(TYPEMASK_PLAYER))
        ++_playerKillsCount;

    if (IsWanderer())
    {
        shouldUpdateStats = true;

        if (me->GetMap()->GetEntry()->IsContinent())
            evadeDelayTimer = 3000;
    }
}

void bot_ai::UnsummonCreature(Creature* creature, bool /*save*/)
{
    if (creature)
    {
        if (bot_pet_ai* petai = creature->GetBotPetAI())
        {
            petai->KillEvents(true);
            petai->canUpdate = false;
        }

        ASSERT_NOTNULL(creature->ToTempSummon())->UnSummon();
    }
}
void bot_ai::UnsummonPet(bool save)
{
    UnsummonCreature(botPet, save);
}

void bot_ai::MoveInLineOfSight(Unit* /*u*/)
{
}

void bot_ai::AttackStart(Unit* /*u*/)
{
}

void bot_ai::DamageDealt(Unit* victim, uint32& damage, DamageEffectType /*damageType*/)
{
    if (victim == me)
        return;

    if (damage)
    {
        if (Creature* cre = victim->ToCreature())
        {
            if (!cre->hasLootRecipient())
                cre->SetLootRecipient(master);

            //controlled case is handled in Unit::DealDamage
            if (IAmFree())
                cre->LowerPlayerDamageReq(std::min<uint32>(cre->GetHealth(), damage) / (IsWanderer() ? 4 : 2));
        }
    }

    if (victim->GetTypeId() == TYPEID_PLAYER)
        ResetChase(victim);
}
void bot_ai::OnBotSpellStart(SpellInfo const* spellInfo)
{
    OnClassSpellStart(spellInfo);
}
//This function is called after Spell::SendSpellCooldown() and Spell::DoAllEffects...() call
void bot_ai::OnBotSpellGo(Spell const* spell, bool ok)
{
    SpellInfo const* curInfo = spell->GetSpellInfo();

    if (ok)
    {
        if (CanBotAttackOnVehicle())
        {
            //Set cooldown
            if (!curInfo->IsCooldownStartedOnEvent() && !curInfo->IsPassive())
            {
                uint32 rec = curInfo->RecoveryTime ? curInfo->GetRecoveryTime() : GetItemSpellCooldown(curInfo->Id);
                uint32 catrec = curInfo->CategoryRecoveryTime;
                if (!catrec && curInfo->StartRecoveryCategory == 133 && !curInfo->CalcCastTime())
                    catrec = curInfo->StartRecoveryTime;

                if (rec || (!spell->GetCastTime() && curInfo->CalcCastTime()))
                    ApplyBotSpellCooldownMods(curInfo, rec);
                if (catrec && !(curInfo->AttributesEx6 & SPELL_ATTR6_IGNORE_CATEGORY_COOLDOWN_MODS))
                    ApplyBotSpellCategoryCooldownMods(curInfo, catrec);

                if (rec || catrec)
                    SetSpellCooldown(curInfo->GetFirstRankSpell()->Id, rec);
                SetSpellCategoryCooldown(curInfo->GetFirstRankSpell(), catrec);

                if (GC_Timer < lastdiff && !IAmFree())
                    waitTimer = 0; //allow next cast to be immediate
            }

            if (curInfo->Id == PVPTRINKET)
                SetSpellCooldown(PVPTRINKET, 120000);
            if (IsPotionSpell(curInfo->Id))
                StartPotionTimer();
            if (curInfo->Id == ACTIVATE_SPEC)
                SetSpec(_newspec);
            if (curInfo->Id == GetSelfRezSpell())
                OnSpellHit(me, curInfo);

            OnClassSpellGo(curInfo);
        }

        if (me->GetVehicleCreatureBase() && me->GetVehicleCreatureBase()->HasSpell(curInfo->Id))
        {
            //delay next cast to allow cp to proc
            if (curInfo->AttributesEx & (SPELL_ATTR1_REQ_COMBO_POINTS1 | SPELL_ATTR1_REQ_COMBO_POINTS2))
                GC_Timer = std::max<uint32>(2000, curInfo->StartRecoveryTime);
            else if (curInfo->Speed > 0.0f)
                GC_Timer = std::max<uint32>(1500, curInfo->StartRecoveryTime);
            else
                GC_Timer = curInfo->StartRecoveryTime;
        }
    }
    else
        GC_Timer = 0;

    if (HasBotCommandState(BOT_COMMAND_ISSUED_ORDER) &&
        !_orders.empty() && _orders.front()._type == BOT_ORDER_SPELLCAST &&
        _orders.front().params.spellCastParams.baseSpell == curInfo->GetFirstRankSpell()->Id)
    {
        if (DEBUG_BOT_ORDERS)
            TC_LOG_ERROR("entities.player", "doCast(): ordered spell {} by {} was {}!",
                curInfo->Id, me->GetName(), ok ? "successful" : "unsuccessful");
        CompleteOrder(_orders.front());
    }
}

void bot_ai::OnBotOwnerSpellGo(Spell const* spell, bool ok)
{
    if (!ok)
        return;

    SpellInfo const* spellInfo = spell->GetSpellInfo();

    if (spellInfo->IsPassive())
        return;

    //TC_LOG_ERROR("entities.player", "OnBotOwnerSpellGo(): {} by {}", spellInfo->Id, master->GetName());

    if (spell->m_targets.HasDst() && HasBotAwaitState(BOT_AWAIT_SEND) && (me->GetTransport() == master->GetTransport()))
    {
        Position const* spell_dest = spell->m_targets.GetDstPos();
        MoveToSendPosition(*spell_dest);
    }

    if (master->GetVehicle() && me->GetVehicle() && !master->HasSpell(spellInfo->Id) && !spell->m_targets.GetGOTargetGUID())
    {
        //if (((spellInfo->AttributesCu & SPELL_ATTR0_CU_DIRECT_DAMAGE) || spellInfo->HasAura(SPELL_AURA_PERIODIC_DAMAGE)) &&
        //    (spell->m_targets.GetTargetMask() & TARGET_FLAG_UNIT) && spell->m_targets.GetUnitTargetGUID() && !me->GetVehicleBase()->GetTarget() &&
        //    spell->m_targets.GetUnitTargetGUID() != master->GetVehicleBase()->GetGUID())
        //{
        //    //master->GetVehicleBase()->SetTarget(spell->m_targets.GetUnitTargetGUID());
        //    me->GetVehicleBase()->SetTarget(spell->m_targets.GetUnitTargetGUID());
        //    SetBotCommandState(BOT_COMMAND_ATTACK);
        //    //hack
        //    if (!me->GetVehicleBase()->GetVictim())
        //    {
        //        if (Unit* target = ObjectAccessor::GetUnit(*me->GetVehicleBase(), spell->m_targets.GetUnitTargetGUID()))
        //            me->GetVehicleBase()->Attack(target, false);
        //    }
        //}

        Vehicle const* veh = me->GetVehicle();
        if (veh && veh->GetBase()->GetTypeId() == TYPEID_UNIT && curVehStrat == BOT_VEH_STRAT_GENERIC &&
            veh->GetBase()->ToCreature()->HasSpell(spellInfo->Id))
        {
            SpellCastTargets targets;
            if (spell->m_targets.HasDst())
            {
                targets.SetDst(spell->m_targets);
                veh->GetBase()->ToCreature()->BotStopMovement();
                float destangle = veh->GetBase()->GetAbsoluteAngle(spell->m_targets.GetDstPos());
                if (veh->GetBase()->GetTransport())
                    destangle = Position::NormalizeOrientation(destangle - veh->GetBase()->GetTransport()->GetOrientation());
                veh->GetBase()->SetFacingTo(destangle);
                //force orientation (inconsistent with SetFacingTo)
                veh->GetBase()->SetOrientation(destangle);
            }
            if (spell->m_targets.GetSpeed() != 0)
                targets.SetSpeed(spell->m_targets.GetSpeed());
            if (spell->m_targets.GetElevation() != 0)
                targets.SetElevation(spell->m_targets.GetElevation());
            if (spell->m_targets.GetUnitTargetGUID())
            {
                if (Unit* target = ObjectAccessor::GetUnit(*veh->GetBase(), spell->m_targets.GetUnitTargetGUID()))
                {
                    targets.SetUnitTarget(target);
                    veh->GetBase()->SetFacingTo(me->GetAbsoluteAngle(target));
                }
            }

            //bug: gameobject damage is not sent to players (not visible in log)
            //tempfix: set bot as original caster
            Spell* vehspell = new Spell(veh->GetBase(), spellInfo, TRIGGERED_NONE/*, me->GetGUID()*/);
            vehspell->prepare(targets);
        }
    }
}

void bot_ai::OnBotChannelFinish(Spell const* spell)
{
    OnClassChannelFinish(spell);
}

void bot_ai::OnBotSpellInterrupted(SpellSchoolMask schoolMask, uint32 unTimeMs)
{
    SpellInfo const* info;

    for (BotSpellMap::const_iterator itr = _spells.begin(); itr != _spells.end(); ++itr)
    {
        info = sSpellMgr->GetSpellInfo(itr->second->spellId);
        if (!info || !(info->GetSchoolMask() & schoolMask)) continue;
        if (info->IsCooldownStartedOnEvent()) continue;
        if (info->PreventionType != SPELL_PREVENTION_TYPE_SILENCE) continue;

        if (HasBotCommandState(BOT_COMMAND_ISSUED_ORDER) &&
            !_orders.empty() && _orders.front()._type == BOT_ORDER_SPELLCAST &&
            _orders.front().params.spellCastParams.baseSpell == itr->first)
        {
            if (DEBUG_BOT_ORDERS)
                TC_LOG_ERROR("entities.player", "doCast(): ordered spell {} was interrupted!", info->Id);
            CompleteOrder(_orders.front());
        }

        itr->second->cooldown += unTimeMs;
        //TC_LOG_ERROR("entities.player", "OnBotSpellInterrupted(): Adding cooldown ({}, new: {}) to spell {} (id: {}, schoolmask: {}), reqSchoolMask = {}",
        //    unTimeMs, itr->second.second, info->SpellName[0], info->Id, info->SchoolMask, schoolMask);
    }

    GC_Timer = 0; //reset global cooldown since cast is canceled
}

void bot_ai::CastBotItemCombatSpell(DamageInfo const& damageInfo)
{
    Unit* target = damageInfo.GetVictim();
    if (!target || !target->IsAlive() || target == me)
        return;

    if (!me->CanUseAttackType(damageInfo.GetAttackType()))
        return;

    Item* item;
    ItemTemplate const* proto;
    int8 slot;

    for (uint8 i = BOT_SLOT_MAINHAND; i != BOT_INVENTORY_SIZE; ++i)
    {
        item = _equips[i];
        if (!item)
            continue;

        //skip standard items
        //if (i < BOT_SLOT_RANGED && einfo->ItemEntry[i] == item->GetEntry())
        //    continue;

        proto = item->GetTemplate();
        if (!proto)
            continue;

        // Additional check for weapons
        if (proto->Class == ITEM_CLASS_WEAPON)
        {
            // offhand item cannot proc from main hand hit etc
            switch (damageInfo.GetAttackType())
            {
                case BASE_ATTACK:   slot = BOT_SLOT_MAINHAND;   break;
                case OFF_ATTACK:    slot = BOT_SLOT_OFFHAND;    break;
                case RANGED_ATTACK: slot = BOT_SLOT_RANGED;     break;
                default:            slot = -1;                  break;
            }
            if (slot != i)
                continue;
        }

        CastBotItemCombatSpell(damageInfo, item, proto);
    }
}

void bot_ai::CastBotItemCombatSpell(DamageInfo const& damageInfo, Item* item, ItemTemplate const* proto)
{
    //TODO: custom spell triggers maybe?

    // Can do effect if any damage done to target
    bool canTrigger = (damageInfo.GetHitMask() & (PROC_HIT_NORMAL | PROC_HIT_CRITICAL | PROC_HIT_ABSORB)) != 0;
    if (canTrigger)
    {
        for (uint8 i = 0; i != MAX_ITEM_PROTO_SPELLS; ++i)
        {
            _Spell const& spellData = proto->Spells[i];

            // no spell
            if (!spellData.SpellId)
                continue;

            // wrong triggering type
            if (spellData.SpellTrigger != ITEM_SPELLTRIGGER_CHANCE_ON_HIT)
                continue;

            SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(spellData.SpellId);
            if (!spellInfo)
            {
                //TC_LOG_ERROR("entities.player.items", "WORLD: unknown Item spellid {}", spellData.SpellId);
                continue;
            }

            float chance = (float)spellInfo->ProcChance;

            if (spellData.SpellPPMRate)
            {
                uint32 WeaponSpeed = me->GetAttackTime(damageInfo.GetAttackType());
                chance = me->GetPPMProcChance(WeaponSpeed, spellData.SpellPPMRate, spellInfo);
            }
            else if (chance > 100.0f)
                chance = me->GetWeaponProcChance();

            if (roll_chance_f(chance))
            {
                CastSpellExtraArgs args(item);
                me->CastSpell(damageInfo.GetVictim(), spellInfo->Id, args);
            }
        }
    }

    // item combat enchantments
    for (uint8 e_slot = 0; e_slot != MAX_ENCHANTMENT_SLOT; ++e_slot)
    {
        uint32 enchant_id = item->GetEnchantmentId(EnchantmentSlot(e_slot));
        SpellItemEnchantmentEntry const* pEnchant = sSpellItemEnchantmentStore.LookupEntry(enchant_id);
        if (!pEnchant)
            continue;

        for (uint8 s = 0; s != MAX_ITEM_ENCHANTMENT_EFFECTS; ++s)
        {
            if (pEnchant->Effect[s] != ITEM_ENCHANTMENT_TYPE_COMBAT_SPELL)
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
                if (!canTrigger)
                    continue;
            }

            // check if enchant procs only on white hits
            if (entry && (entry->AttributesMask & ENCHANT_PROC_ATTR_WHITE_HIT) && damageInfo.GetSpellInfo())
                continue;

            SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(pEnchant->EffectArg[s]);
            if (!spellInfo)
                continue;

            float chance = pEnchant->EffectPointsMin[s] != 0 ? float(pEnchant->EffectPointsMin[s]) : me->GetWeaponProcChance();
            if (entry)
            {
                if (entry->ProcsPerMinute)
                {
                    chance = entry->ProcsPerMinute;
                    //handle SPELLMOD_PROC_PER_MINUTE spellmods
                    //Envenom
                    if (GetSpec() == BOT_SPEC_ROGUE_ASSASINATION && me->HasAuraTypeWithFamilyFlags(SPELL_AURA_ADD_FLAT_MODIFIER, SPELLFAMILY_ROGUE, 0x800000))
                        chance *= 1.75f;
                    //Improved Poisons
                    if (GetSpec() == BOT_SPEC_ROGUE_ASSASINATION && me->GetLevel() >= 25 && (spellInfo->SpellFamilyFlags[0] & 0x2000))
                        chance *= 1.5f;

                    chance = me->GetPPMProcChance(proto->Delay, chance, spellInfo);
                }
                else if (entry->Chance)
                    chance = (float)entry->Chance;
            }

            // Apply SPELLMOD_CHANCE_OF_SUCCESS spell mods
            //Envenom
            if (GetSpec() == BOT_SPEC_ROGUE_ASSASINATION && me->HasAuraTypeWithFamilyFlags(SPELL_AURA_ADD_FLAT_MODIFIER, SPELLFAMILY_ROGUE, 0x800000))
                chance += 15.f;
            //Improved Poisons
            if (GetSpec() == BOT_SPEC_ROGUE_ASSASINATION && me->GetLevel() >= 25 && (spellInfo->SpellFamilyFlags[0] & 0x10000))
                chance += 20.f;

            // Shiv has 100% chance to apply the poison
            if (me->FindCurrentSpellBySpellId(5938) && e_slot == TEMP_ENCHANTMENT_SLOT)
                chance = 100.0f;

            if (roll_chance_f(chance))
            {
                CastSpellExtraArgs args(item);
                me->CastSpell(spellInfo->IsPositive() ? me : damageInfo.GetVictim(), spellInfo->Id, args);
            }
        }
    }
}
//ORDERS
bool bot_ai::AddOrder(BotOrder&& order)
{
    if (_orders.size() >= MAX_BOT_ORDERS_QUEUE_SIZE)
    {
        TC_LOG_ERROR("scripts", "bot_ai::AddOrder: orders limit reached for {} ({})!", me->GetName(), uint32(_orders.size()));
        return false;
    }

    _orders.push(std::move(order));
    return true;
}
void bot_ai::CancelOrder(BotOrder const& order)
{
    if (_orders.empty())
    {
        TC_LOG_ERROR("scripts", "bot_ai::CancelOrder: {} orders are empty while trying to remove order type {}!",
            me->GetName(), uint32(order._type));
        return;
    }
    if (_orders.front()._type != order._type)
    {
        TC_LOG_ERROR("scripts", "bot_ai::CancelOrder: {} front order (type {}) is different from cur order (type {})!",
            me->GetName(), uint32(_orders.front()._type), uint32(order._type));
        return;
    }

    RemoveBotCommandState(BOT_COMMAND_ISSUED_ORDER);
    _orders.pop();
}
void bot_ai::CompleteOrder(BotOrder const& order)
{
    if (_orders.empty())
    {
        TC_LOG_ERROR("scripts", "bot_ai::CompleteOrder: {} orders are empty while trying to remove order type {}!",
            me->GetName(), uint32(order._type));
        return;
    }
    if (_orders.front()._type != order._type)
    {
        TC_LOG_ERROR("scripts", "bot_ai::CompleteOrder: {} front order (type {}) is different from cur order (type {})!",
            me->GetName(), uint32(_orders.front()._type), uint32(order._type));
        return;
    }

    RemoveBotCommandState(BOT_COMMAND_ISSUED_ORDER);
    _orders.pop();
}
void bot_ai::CancelAllOrders()
{
    RemoveBotCommandState(BOT_COMMAND_ISSUED_ORDER);
    while (!_orders.empty())
        _orders.pop();
}
void bot_ai::_ProcessOrders()
{
    ordersTimer = 500;

    while (!_orders.empty())
    {
        BotOrder const& order = _orders.front();
        if (order._timeout <= time(0))
        {
            if (DEBUG_BOT_ORDERS)
                TC_LOG_DEBUG("npcbots", "bot_ai::_ProcessOrders: {} front order (type {}) expired...", me->GetName(), uint32(order._type));
            CancelOrder(order);
        }
        else if (order._type == BOT_ORDER_PULL && (!HasRole(BOT_ROLE_DPS) || me->IsInCombat() || !me->getAttackers().empty()))
            CompleteOrder(order);
        else
            break;
    }

    if (HasBotCommandState(BOT_COMMAND_ISSUED_ORDER))
        return;

    if (JumpingOrFalling())
        return;

    if (_orders.empty())
        return;

    BotOrder const& order = _orders.front();
    Unit* target = nullptr;
    switch (order._type)
    {
        case BOT_ORDER_SPELLCAST:
        {
            if (CCed(me))
                break;

            SetBotCommandState(BOT_COMMAND_ISSUED_ORDER);

            ObjectGuid guid(order.params.spellCastParams.targetGuid);
            if (guid == me->GetGUID())
                target = me;
            else if (guid == master->GetGUID())
                target = master;
            else if (guid != 0)
            {
                if (!IAmFree())
                    target = master->GetBotMgr()->GetBot(guid);
                if (!target)
                    target = ObjectAccessor::GetUnit(*me, guid);
            }
            else
            {
                TC_LOG_ERROR("scripts", "bot_ai:_ProcessOrders: invalid spellCastParams.targetGuid {}!", order.params.spellCastParams.targetGuid);
                CancelOrder(order);
                return;
            }

            if (!target || !target->IsInWorld())
            {
                TC_LOG_ERROR("scripts", "bot_ai:_ProcessOrders: target {} not found!", order.params.spellCastParams.targetGuid);
                CancelOrder(order);
                return;
            }

            if (IsCasting())
                me->InterruptNonMeleeSpells(false);

            doCast(target, _spells[order.params.spellCastParams.baseSpell]->spellId);
            break;
        }
        case BOT_ORDER_PULL:
        {
            if (me->GetVictim())
                break;
            if (CCed(me))
                break;

            SetBotCommandState(BOT_COMMAND_ISSUED_ORDER);

            if (order.params.pullParams.targetGuid)
                target = ObjectAccessor::GetUnit(*me, ObjectGuid(order.params.pullParams.targetGuid));
            else
            {
                TC_LOG_ERROR("scripts", "bot_ai:_ProcessOrders: invalid pullParams.targetGuid {}!", order.params.pullParams.targetGuid);
                CancelOrder(order);
                return;
            }

            if (!target || !target->IsInWorld())
            {
                TC_LOG_ERROR("scripts", "bot_ai:_ProcessOrders: target {} not found!", order.params.pullParams.targetGuid);
                CancelOrder(order);
                return;
            }
            if (!target->IsAlive() || target->IsInCombat() || !CanBotAttack(target))
            {
                TC_LOG_ERROR("scripts", "bot_ai:_ProcessOrders: target {} cannot be pulled!", order.params.pullParams.targetGuid);
                CancelOrder(order);
                return;
            }
            break;
        }
        default:
            TC_LOG_ERROR("scripts", "bot_ai:_ProcessOrders: invalid order type {}!", uint32(order._type));
            CancelOrder(order);
            return;
    }
}
bool bot_ai::IsLastOrder(BotOrderTypes order_type, uint32 param1, ObjectGuid guidparam1) const
{
    if (!_orders.empty())
    {
        BotOrder const& order = _orders.front();
        if (order_type == order._type)
        {
            switch (order_type)
            {
                case BOT_ORDER_SPELLCAST:
                    if (!param1 || order.params.spellCastParams.baseSpell == param1)
                        return true;
                    break;
                case BOT_ORDER_PULL:
                    if (!guidparam1 || order.params.pullParams.targetGuid == guidparam1.GetRawValue())
                        return true;
                    break;
                default:
                    TC_LOG_ERROR("scripts", "bot_ai:IsLastOrder: invalid order type {}!", uint32(order_type));
                    break;
            }
        }
    }

    return false;
}
//VEHICLES
//helpers
bool bot_ai::HasAuraTypeWithValueAtLeast(AuraType auratype, int32 minvalue, Unit const* unit) const
{
    if (!unit)
        unit = me;

    Unit::AuraEffectList const& mTotalAuraList = unit->GetAuraEffectsByType(auratype);
    for (Unit::AuraEffectList::const_iterator i = mTotalAuraList.begin(); i != mTotalAuraList.end(); ++i)
        if ((*i)->GetAmount() >= minvalue)
            return true;

    return false;
}
//strats - opponent is always valid
void bot_ai::DoSkytalonVehicleStrats(uint32 diff)
{
    if (GC_Timer > diff)
        return;

    GC_Timer = 350; //at least this delay

    if (!CheckVehicleAttackTarget(curVehStrat))
        return;

    Creature* drake = me->GetVehicleCreatureBase();
    Unit* target = nullptr;
    uint32 drakespell = 0;
    uint32 drakePower = drake->GetPower(POWER_ENERGY);

    //finishers
    uint8 finishComboPoints;
    uint32 finishPower;
    if (GetHealthPCT(drake) <= (40 + 40*drake->HasAuraType(SPELL_AURA_PERIODIC_DAMAGE)) ||
        HasAuraTypeWithValueAtLeast(SPELL_AURA_PERIODIC_DAMAGE, drake->GetMaxHealth() / 16, drake))
    {
        finishComboPoints = 3;
        finishPower = 25;
    }
    //if (HasRole(BOT_ROLE_HEAL))
    //{
    //    finishComboPoints = 4;
    //    finishPower = 50;
    //}
    else
    {
        finishComboPoints = 4;
        finishPower = 50;
    }

    if (vehcomboPoints >= finishComboPoints && (Rand() < 75 + 40*(vehcomboPoints >= 5 || drakePower < finishPower)))
    {
        if (drakePower >= finishPower)
        {
            if (GetHealthPCT(drake) < 60 && !drake->HasAuraEffect(drake->m_spells[4], EFFECT_0))
            {
                drakespell = drake->m_spells[4]; //flame shield
                target = drake;
            }
            else if (HasRole(BOT_ROLE_HEAL))
            {
                drakespell = drake->m_spells[3]; //life burst
                bool cast = false;
                //find damaged target
                if (master->GetVehicle() && GetHealthPCT(master->GetVehicleBase()) < 90 && master->GetVehicleBase()->GetDistance(drake) < 60)
                    cast = true;
                else if (GetHealthPCT(drake) < 90)
                    cast = true;
                else
                {
                    std::vector<Unit*> vec = BotMgr::GetAllGroupMembers(master);
                    cast = std::any_of(vec.cbegin(), vec.cend(), [drake = drake](Unit const* member) {
                        return drake->GetMap() == member->FindMap() && member->GetVehicle() &&
                            member->GetVehicleBase()->GetHealthPct() < 90.0f && member->GetVehicleBase()->GetDistance(drake) < 60;
                    });
                }
                if (cast)
                    target = drake;
            }
            else
            {
                drakespell = drake->m_spells[1]; //engulf in flames
                target = opponent;
            }
        }
    }
    else if (drakePower >= 35)
    {
        if (HasRole(BOT_ROLE_DPS))
        {
            drakespell = drake->m_spells[0]; //flame spike
            target = opponent;
        }
        else if (HasRole(BOT_ROLE_HEAL))
        {
            drakespell = drake->m_spells[2]; //revivify
            //bots won't care about target they have cp on so choose randomly
            std::list<Unit*> targets1;
            BotMap const* map;
            Group const* gr = master->GetGroup();
            if (gr)
            {
                bool Bots = false;
                for (GroupReference const* itr = gr->GetFirstMember(); itr != nullptr; itr = itr->next())
                {
                    Player const* p = itr->GetSource();
                    if (!p || me->GetMap() != p->FindMap()) continue;
                    if (p->HaveBot() && !Bots)
                        Bots = true;
                    Unit* u = p->GetVehicleBase();
                    if (u && u->IsAlive() && !u->HasUnitState(UNIT_STATE_ISOLATED) && drake->GetDistance(u) < 60.f &&
                        !(GetHealthPCT(u) > 95 && !IsTank(p)) &&
                        (GetHealthPCT(u) < 95 || (u->IsInCombat() && !u->getAttackers().empty())))
                        targets1.push_back(u);
                }
                if (Bots)
                {
                    for (GroupReference const* itr = gr->GetFirstMember(); itr != nullptr; itr = itr->next())
                    {
                        Player const* p = itr->GetSource();
                        if (!p || me->GetMap() != p->FindMap() || !p->HaveBot()) continue;

                        map = p->GetBotMgr()->GetBotMap();
                        for (BotMap::const_iterator bitr = map->begin(); bitr != map->end(); ++bitr)
                        {
                            Unit* u = bitr->second ? bitr->second->GetVehicleBase() : nullptr;
                            if (u && u->IsAlive() && !u->HasUnitState(UNIT_STATE_ISOLATED) && drake->GetDistance(u) < 60.f &&
                                !(GetHealthPCT(u) > 95 && !IsTank(bitr->second)) &&
                                (GetHealthPCT(u) < 95 || (u->IsInCombat() && !u->getAttackers().empty())))
                                targets1.push_back(u);
                        }
                    }
                }
            }
            else
            {
                map = master->GetBotMgr()->GetBotMap();
                for (BotMap::const_iterator itr = map->begin(); itr != map->end(); ++itr)
                {
                    Unit* u = itr->second ? itr->second->GetVehicleBase() : nullptr;
                    if (u && u->IsAlive() && !u->HasUnitState(UNIT_STATE_ISOLATED) && drake->GetDistance(u) < 60.f &&
                        !(GetHealthPCT(u) > 95 && !IsTank(itr->second)) &&
                        (GetHealthPCT(u) < 95 || (u->IsInCombat() && !u->getAttackers().empty())))
                        targets1.push_back(u);
                }
            }

            uint8 minhppct = 0;
            for (std::list<Unit*>::const_iterator ci = targets1.begin(); ci != targets1.end(); ++ci)
                if (uint8 hppct = GetHealthPCT(*ci))
                    if (minhppct == 0 || minhppct > hppct)
                        minhppct = hppct;

            if (minhppct <= 75)
                targets1.remove_if(BOTAI_PRED::HpPctAboveExclude(float(minhppct + 10)));

            if (!targets1.empty())
                target = Trinity::Containers::SelectRandomContainerElement(targets1);

            if (target && drakePower < 80)
                if (Aura const* revi = target->GetAura(57090, drake->GetGUID())) //revivify
                    if (revi->GetStackAmount() >= 5 && revi->GetDuration() >= 4000)
                        target = nullptr;
        }
    }

    //if (!HasRole(BOT_ROLE_TANK|BOT_ROLE_HEAL) && drake->GetMap()->IsRaid() && target && target->GetVictim() == drake)
    //    target = nullptr;

    if (!target)
        return;

    if (!drakespell)
    {
        TC_LOG_ERROR("scripts", "DoSkytalonVehicleStrats no spell for role mask {} cp {}, power {}, target {}",
            GetBotRoles(), uint32(vehcomboPoints), drakePower, target->GetName());
        return;
    }

    //TC_LOG_ERROR("scripts", "DoSkytalonVehicleStrats {} on {}", drakespell, target->GetName());

    SetBotCommandState(BOT_COMMAND_ATTACK);
    drake->BotStopMovement();
    drake->SetInFront(target);
    drake->CastSpell(target, drakespell);
}
void bot_ai::DoRubyDrakeVehicleStrats(uint32 diff)
{
    if (GC_Timer > diff)
        return;

    GC_Timer = 350; //at least this delay

    if (!CheckVehicleAttackTarget(curVehStrat))
        return;

    Creature* drake = me->GetVehicleCreatureBase();
    ASSERT(drake);
    Unit* target = nullptr;
    uint32 drakespell = 0;

    //IS TANK
    //50232 Searing Wrath
    //50241 Evasive Charges
    //50240 Evasive Maneuvers
    //50253 Martyr

    Aura const* evas = drake->GetAura(50241); //Evasive Charges
    uint8 vehicles = LivingVehiclesCount();
    //bool eregos = opponent->GetEntry() == CREATURE_BOSS_EREGOS_N || opponent->GetEntry() == CREATURE_BOSS_EREGOS_H;

    bool finalEncounter = master->GetInstanceScript() && master->GetInstanceScript()->GetBossState(2) == DONE; //DATA_UROM

    if (vehicles > 1 && evas)
    {
        bool canManeuver = !drake->HasAuraType(SPELL_AURA_MOD_ATTACKER_SPELL_HIT_CHANCE) && evas->GetStackAmount() >= 5 &&
            !drake->HasSpellCooldown(50240);
        bool canMartyr = !drake->HasAuraType(SPELL_AURA_SPELL_MAGNET) &&
            !drake->HasSpellCooldown(50253);

        if ((!finalEncounter || canMartyr) && canManeuver)
        {
            drakespell = drake->m_spells[1]; //Evasive Maneuvers
            target = drake;
        }
        else if (finalEncounter && canMartyr)
        {
            drakespell = drake->m_spells[2]; //Martyr
            target = drake;
        }
    }
    if (!target)
    {
        drakespell = drake->m_spells[0]; //Searing Wrath
        target = opponent;
    }

    if (!target)
        return;

    if (!drakespell)
    {
        TC_LOG_ERROR("scripts", "DoRubyDrakeVehicleStrats no spell for target {}", target->GetName());
        return;
    }

    SetBotCommandState(BOT_COMMAND_ATTACK);
    drake->BotStopMovement();
    drake->SetInFront(target);
    drake->CastSpell(target, drakespell);
}
void bot_ai::DoEmeraldDrakeVehicleStrats(uint32 diff)
{
    if (GC_Timer > diff)
        return;

    GC_Timer = 350; //at least this delay

    Creature* drake = me->GetVehicleCreatureBase();
    Unit const* mmover = master->GetVehicle() ? master->GetVehicleBase() : master;
    Unit* target = nullptr;
    uint32 drakespell = 0;

    //IS HEALER
    //50328 Leeching Poison
    //50341 Touch the Nightmare
    //50344 Dream Funnel

    uint8 drakeHpPct = GetHealthPCT(drake);

    //canceling channel
    if (IsCasting(drake))
    {
        bool interrupt = false;
        if (drakeHpPct <= 30)
            interrupt = true;
        else if (mmover->isMoving() && drake->GetDistance(mmover) >= 75.f && !mmover->HasInArc(float(M_PI) / 2, drake))
            interrupt = true;
        else if (Spell const* funnel = drake->GetCurrentSpell(CURRENT_CHANNELED_SPELL))
            if (ObjectGuid guid = funnel->m_targets.GetUnitTargetGUID())
                if (Unit const* tar = ObjectAccessor::GetUnit(*drake, guid))
                    if (GetHealthPCT(tar) > 95)
                        interrupt = true;

        if (interrupt)
            drake->InterruptNonMeleeSpells(false);
        else
            return;
    }

    if (!CheckVehicleAttackTarget(curVehStrat))
        return;

    Aura const* pois = opponent->GetAura(50328, drake->GetGUID()); //Leeching Poison
    Aura const* rift = opponent->GetAura(49592); //Temporal Rift
    uint8 vehicles = LivingVehiclesCount();
    bool eregos = opponent->GetEntry() == CREATURE_BOSS_EREGOS_N || opponent->GetEntry() == CREATURE_BOSS_EREGOS_H;

    bool finalEncounter = master->GetInstanceScript() && master->GetInstanceScript()->GetBossState(2) == DONE; //DATA_UROM
    bool canheal = finalEncounter && vehicles > 1 && (!eregos || drake->GetDistance(mmover) < 30.f) &&
        drakeHpPct >= (eregos ? 70 : 50) - (pois ? 5 * pois->GetStackAmount() : 0);

    if (canheal && Rand() < 90)
    {
        drakespell = drake->m_spells[2]; //Dream Funnel
        std::list<Unit*> targets1;
        BotMap const* map;
        Group const* gr = master->GetGroup();
        if (gr)
        {
            bool Bots = false;
            for (GroupReference const* itr = gr->GetFirstMember(); itr != nullptr; itr = itr->next())
            {
                Player const* p = itr->GetSource();
                if (!p || me->GetMap() != p->FindMap()) continue;
                if (p->HaveBot() && !Bots)
                    Bots = true;
                Unit* u = p->GetVehicleBase();
                if (u && u->IsAlive() && !u->HasUnitState(UNIT_STATE_ISOLATED) && drake->GetDistance(u) < 60.f &&
                    GetHealthPCT(u) <= (IsTank(p) ? 50 : 35) + (rift ? 15 : 0))
                    targets1.push_back(u);
            }
            if (Bots)
            {
                for (GroupReference const* itr = gr->GetFirstMember(); itr != nullptr; itr = itr->next())
                {
                    Player const* p = itr->GetSource();
                    if (!p || me->GetMap() != p->FindMap() || !p->HaveBot()) continue;

                    map = p->GetBotMgr()->GetBotMap();
                    for (BotMap::const_iterator bitr = map->begin(); bitr != map->end(); ++bitr)
                    {
                        Unit* u = bitr->second ? bitr->second->GetVehicleBase() : nullptr;
                        if (u && u != drake && u->IsAlive() && !u->HasUnitState(UNIT_STATE_ISOLATED) && drake->GetDistance(u) < 60.f &&
                            GetHealthPCT(u) <= (IsTank(bitr->second) ? 50 : 35) + (rift ? 15 : 0))
                            targets1.push_back(u);
                    }
                }
            }
        }
        else
        {
            map = master->GetBotMgr()->GetBotMap();
            for (BotMap::const_iterator itr = map->begin(); itr != map->end(); ++itr)
            {
                Unit* u = itr->second ? itr->second->GetVehicleBase() : nullptr;
                if (u && u != drake && u->IsAlive() && !u->HasUnitState(UNIT_STATE_ISOLATED) && drake->GetDistance(u) < 60.f &&
                    GetHealthPCT(u) <= (IsTank(itr->second) ? 50 : 35) + (rift ? 15 : 0))
                    targets1.push_back(u);
            }
        }

        uint8 minhppct = 0;
        for (std::list<Unit*>::const_iterator ci = targets1.begin(); ci != targets1.end(); ++ci)
            if (uint8 hppct = GetHealthPCT(*ci))
                if (minhppct == 0 || minhppct > hppct)
                    minhppct = hppct;

        if (minhppct <= 50)
            targets1.remove_if(BOTAI_PRED::HpPctAboveExclude(float(minhppct + 20)));

        if (!targets1.empty())
            target = Trinity::Containers::SelectRandomContainerElement(targets1);
    }
    if (!target)
    {
        drakespell = drake->m_spells[1]; //Touch the Nightmare
        if (!drake->HasSpellCooldown(drakespell))
        {
            if ((eregos && drakeHpPct >= ((opponent->GetHealth() < (rift ? 50000u : 25000u)) ? 31 : 80)) ||
                (drakeHpPct >= 90 && Rand() < 50 && !opponent->HasAura(drakespell)))
                target = opponent;
        }
    }
    if (!target)
    {
        drakespell = drake->m_spells[0]; //Leeching Poison
        if (!pois || pois->GetStackAmount() < 3 || pois->GetDuration() < 4000)
            target = opponent;
        else
        {
            //random target
            std::list<Unit*> targets;
            Trinity::AnyUnfriendlyUnitInObjectRangeCheck check(drake, drake, 60.f);
            Trinity::UnitListSearcher <Trinity::AnyUnfriendlyUnitInObjectRangeCheck> searcher(drake, targets, check);
            //drake->VisitNearbyObject(60.f, searcher);
            Cell::VisitAllObjects(drake, searcher, 60.f);
            targets.remove_if(BOTAI_PRED::UnitExclude(opponent));
            targets.remove_if(BOTAI_PRED::UnitCombatStateExclude(false));
            targets.remove_if(BOTAI_PRED::AuraedTargetExcludeByCaster(drakespell, drake->GetGUID(), 3));
            targets.remove_if(BOTAI_PRED::AuraedTargetExclude(49836, 5)); //Shock Charge 1-shots

            if (!targets.empty())
                target = Trinity::Containers::SelectRandomContainerElement(targets);
        }
    }

    if (!target)
        return;

    if (!drakespell)
    {
        TC_LOG_ERROR("scripts", "DoEmeraldDrakeVehicleStrats no spell for target {}", target->GetName());
        return;
    }

    SetBotCommandState(BOT_COMMAND_ATTACK);
    drake->BotStopMovement();
    drake->SetInFront(target);
    drake->CastSpell(target, drakespell);
}
void bot_ai::DoAmberDrakeVehicleStrats(uint32 diff)
{
    if (GC_Timer > diff)
        return;

    GC_Timer = 350; //at least this delay

    if (!CheckVehicleAttackTarget(curVehStrat))
        return;

    Creature* drake = me->GetVehicleCreatureBase();
    ASSERT(drake);
    Unit const* mmover = master->GetVehicle() ? master->GetVehicleBase() : master;
    Unit* target = nullptr;
    uint32 drakespell = 0;

    //IS DPS
    //49840 Shock Lance
    //49838 Stop Time
    //49592 Temporal Rift
    //49836 Shock Charge

    Aura const* shoc = opponent->GetAura(49836, drake->GetGUID()); //Shock Charge

    //canceling channel
    if (IsCasting(drake))
    {
        bool interrupt = false;

        if (mmover->isMoving() && drake->GetDistance(mmover) >= 60.f && !mmover->HasInArc(float(M_PI) / 2, drake))
            interrupt = true;
        else if (shoc && shoc->GetStackAmount() >= 10)
            interrupt = true;

        if (interrupt)
            drake->InterruptNonMeleeSpells(false);
        else
            return;
    }

    Aura const* rift = opponent->GetAura(49592); //Temporal Rift
    uint8 vehicles = LivingVehiclesCount();
    bool eregos = opponent->GetEntry() == CREATURE_BOSS_EREGOS_N || opponent->GetEntry() == CREATURE_BOSS_EREGOS_H;

    bool finalEncounter = master->GetInstanceScript() && master->GetInstanceScript()->GetBossState(2) == DONE; //DATA_UROM

    if (eregos && !drake->HasSpellCooldown(drake->m_spells[1]) && IsCasting(opponent) &&
        opponent->HasAuraType(SPELL_AURA_MOD_CASTING_SPEED_NOT_STACK) && opponent->GetDiminishing(DIMINISHING_STUN) <= DIMINISHING_LEVEL_2)
    {
        drakespell = drake->m_spells[1]; //Stop Time
        target = drake;
    }
    if (!target && shoc && shoc->GetStackAmount() >= 5)
    {
        drakespell = drake->m_spells[0]; //Shock Lance
        if (eregos && shoc->GetStackAmount() >= 10 && (rift || shoc->GetDuration() < 25000 || Rand() < 30))
            target = opponent;
        else
        {
            //random 1-shot target
            std::list<Unit*> targets;
            Trinity::AnyUnfriendlyUnitInObjectRangeCheck check(drake, drake, 60.f);
            Trinity::UnitListSearcher <Trinity::AnyUnfriendlyUnitInObjectRangeCheck> searcher(drake, targets, check);
            //drake->VisitNearbyObject(60.f, searcher);
            Cell::VisitAllObjects(drake, searcher, 60.f);
            targets.remove_if(BOTAI_PRED::UnitExclude(opponent));

            if (!targets.empty())
                target = Trinity::Containers::SelectRandomContainerElement(targets);
        }
    }
    if (!target)
    {
        if (finalEncounter && vehicles > 1)
        {
            drakespell = drake->m_spells[2]; //Temporal Rift
            target = opponent;
        }
        else
        {
            drakespell = drake->m_spells[0]; //Shock Lance
            target = opponent;
        }
    }

    if (!target)
        return;

    if (!drakespell)
    {
        TC_LOG_ERROR("scripts", "DoAmberDrakeVehicleStrats no spell for target {}", target->GetName());
        return;
    }

    SetBotCommandState(BOT_COMMAND_ATTACK);
    drake->BotStopMovement();
    drake->SetInFront(target);
    drake->CastSpell(target, drakespell);
}
void bot_ai::DoArgentMountVehicleStrats(uint32 diff)
{
    if (GC_Timer > diff)
        return;

    GC_Timer = 200; //at least this delay

    Creature* mount = me->GetVehicleCreatureBase();

    //Tounament spells
    //62544 Thrust
    //62575 Shield-Breaker
    //62960 Charge
    //62552 Defend
    //64077 Refresh Mount

    //ToC5 spells
    //68505 Thrust
    //62575 Shield-Breaker
    //68282 Charge
    //62552 Defend

    if (!mount->HasSpellCooldown(mount->m_spells[3])) //Defend
    {
        Aura const* myde = mount->GetAura(mount->m_spells[3]);
        if (!myde || myde->GetStackAmount() < myde->GetSpellInfo()->StackAmount || myde->GetDuration() <= 8000)
        {
            mount->CastSpell(mount, mount->m_spells[3]);
            return;
        }
    }

    if (!CheckVehicleAttackTarget(curVehStrat))
        return;

    //Unit const* mmover = master->GetVehicle() ? master->GetVehicleBase() : master;
    Unit* target = nullptr;
    uint32 mountspell = 0;

    if (mount->GetDistance(opponent) > 5.f)
    {
        //Defend
        AuraEffect const* def = opponent->GetAuraEffect(SPELL_AURA_MOD_DAMAGE_PERCENT_TAKEN,SPELLFAMILY_GENERIC, 2007, EFFECT_0);
        if (!def)
            def = opponent->GetAuraEffect(SPELL_AURA_MOD_DAMAGE_PERCENT_TAKEN,SPELLFAMILY_GENERIC, 2007, EFFECT_2);
        if ((!def || def->GetBase()->GetStackAmount() < 2) && !mount->HasSpellCooldown(mount->m_spells[2]))
        {
            mountspell = mount->m_spells[2]; //Charge
            target = opponent;
        }
        else
        {
            mountspell = mount->m_spells[1]; //Shield-Breaker
            target = opponent;
        }
    }
    else
    {
        mountspell = mount->m_spells[0]; //Thrust
        target = opponent;
    }

    if (!target)
        return;

    if (!mountspell)
    {
        TC_LOG_ERROR("scripts", "DoArgentMountVehicleStrats no spell for target {}", target->GetName());
        return;
    }

    SetBotCommandState(BOT_COMMAND_ATTACK);
    mount->BotStopMovement();
    mount->SetInFront(target);
    mount->CastSpell(target, mountspell);
}
void bot_ai::DoDemolisherVehicleStrats(uint32 diff)
{
    if (GC_Timer > diff)
        return;

    GC_Timer = 350; //at least this delay

    if (!CheckVehicleAttackTarget(curVehStrat))
        return;
}
void bot_ai::DoSiegeEngineVehicleStrats(uint32 diff)
{
    if (GC_Timer > diff)
        return;

    GC_Timer = 350; //at least this delay

    if (!CheckVehicleAttackTarget(curVehStrat))
        return;
}
void bot_ai::DoChopperVehicleStrats(uint32 diff)
{
    if (GC_Timer > diff)
        return;

    GC_Timer = 350; //at least this delay

    if (!CheckVehicleAttackTarget(curVehStrat))
        return;
}
void bot_ai::DoGenericVehicleStrats(uint32 diff)
{
    if (GC_Timer > diff)
        return;

    GC_Timer = 350; //at least this delay

    if (!CheckVehicleAttackTarget(curVehStrat))
        return;
}
void bot_ai::DoVehicleStrats(BotVehicleStrats strat, uint32 diff)
{
    if (curVehStrat != strat)
    {
        //TC_LOG_ERROR("scripts", "DoVehicleStrats doing strat {}", uint32(strat));
        curVehStrat = strat;
    }

    //if (!master->GetVehicle() || me->GetVehicle()->GetCreatureEntry() != master->GetVehicle()->GetCreatureEntry())
    //{
    //    TC_LOG_ERROR("scripts", "DoVehicleStrats cannot do strats: master not on vehicle or on different one");
    //    return;
    //}

    switch (strat)
    {
        case BOT_VEH_STRAT_WYRMREST_SKYTALON:
            DoSkytalonVehicleStrats(diff);
            break;
        case BOT_VEH_STRAT_RUBY_DRAKE:
            DoRubyDrakeVehicleStrats(diff);
            break;
        case BOT_VEH_STRAT_EMERALD_DRAKE:
            DoEmeraldDrakeVehicleStrats(diff);
            break;
        case BOT_VEH_STRAT_AMBER_DRAKE:
            DoAmberDrakeVehicleStrats(diff);
            break;
        case BOT_VEH_STRAT_TOC5_MOUNT:
            DoArgentMountVehicleStrats(diff);
            break;
        case BOT_VEH_STRAT_ULDUAR_DEMOLISHER:
            DoDemolisherVehicleStrats(diff);
            break;
        case BOT_VEH_STRAT_ULDUAR_SIEGEENGINE:
            DoSiegeEngineVehicleStrats(diff);
            break;
        case BOT_VEH_STRAT_ULDUAR_CHOPPER:
            DoChopperVehicleStrats(diff);
            break;
        case BOT_VEH_STRAT_GENERIC:
            DoGenericVehicleStrats(diff);
            break;
        default:
            TC_LOG_ERROR("scripts", "Unhandled vehicle strat {}", uint32(strat));
            break;
    }
}
void bot_ai::DoVehicleActions(uint32 diff)
{
    if (!me->GetVehicle())
        return;

    //choose strat
    BotVehicleStrats strat;
    switch (me->GetVehicleBase()->GetEntry())
    {
        case CREATURE_NEXUS_SKYTALON_1:
        case CREATURE_EOE_SKYTALON_N:
        case CREATURE_EOE_SKYTALON_H:
            strat = BOT_VEH_STRAT_WYRMREST_SKYTALON;
            break;
        case CREATURE_OCULUS_DRAKE_RUBY:
            strat = BOT_VEH_STRAT_RUBY_DRAKE;
            break;
        case CREATURE_OCULUS_DRAKE_EMERALD:
            strat = BOT_VEH_STRAT_EMERALD_DRAKE;
            break;
        case CREATURE_OCULUS_DRAKE_AMBER:
            strat = BOT_VEH_STRAT_AMBER_DRAKE;
            break;
        //case CREATURE_TOC_STEED_QUELDOREI:
        //case CREATURE_TOC_NIGHTSABER:
        //case CREATURE_TOC_STEED_STORMWIND:
        //case CREATURE_TOC_MECHANOSTRIDER:
        //case CREATURE_TOC_RAM:
        //case CREATURE_TOC_ELEKK:
        //case CREATURE_TOC_HAWKSTRIDER_SUNREAVER:
        //case CREATURE_TOC_RAPTOR:
        //case CREATURE_TOC_WARHORSE:
        //case CREATURE_TOC_WOLF:
        //case CREATURE_TOC_HAWKSTRIDER_SILVERMOON:
        //case CREATURE_TOC_KODO:
        case CREATURE_TOC5_WARHORSE:
        case CREATURE_TOC5_BATTLEWORG:
            strat = BOT_VEH_STRAT_TOC5_MOUNT;
            break;
        /*
        case CREATURE_ULDUAR_DEMOLISHER:
            strat = BOT_VEH_STRAT_ULDUAR_DEMOLISHER;
            break;
        case CREATURE_ULDUAR_SIEGE_ENGINE:
            strat = BOT_VEH_STRAT_ULDUAR_SIEGEENGINE;
            break;
        case CREATURE_ULDUAR_CHOPPER:
        case CREATURE_ULDUAR_CHOPPER1:
            strat = BOT_VEH_STRAT_ULDUAR_CHOPPER;
            break;
        */
        default:
            strat = BOT_VEH_STRAT_GENERIC;
            if (curVehStrat != strat)
                TC_LOG_DEBUG("scripts", "bot_ai DoVehicleActions: {} has to use generic strat for vehicle creature {} ({})",
                me->GetName(), me->GetVehicleBase()->GetName(), me->GetVehicleBase()->GetEntry());
            break;
    }

    DoVehicleStrats(strat, diff);
}
bool bot_ai::CheckVehicleAttackTarget(BotVehicleStrats strat)
{
    opponent = _getVehicleTarget(strat);

    if (!opponent)
    {
        if (me->GetVehicleBase()->GetTarget())
        {
            me->GetVehicleBase()->AttackStop();
            me->GetVehicleBase()->SetTarget(ObjectGuid::Empty);
        }
        else if (!master->GetVehicle() && me->GetVehicleBase()->GetDistance(master) < ((Rand() < 25) ? 35 : 15))
        {
            //if (VehicleSeatEntry const* seat = me->GetVehicle()->GetSeatForPassenger(me))
            //{
                //if (seat->CanEnterOrExit())
                    me->ExitVehicle();
                    //me->BotStopMovement();
            //}
        }

        return false;
    }

    if (opponent->GetGUID() != me->GetVehicleBase()->GetTarget())
    {
        me->GetVehicleBase()->SetTarget(opponent->GetGUID());
        SetBotCommandState(BOT_COMMAND_ATTACK);
        me->GetVehicleBase()->Attack(opponent, false);
    }

    return true;
}

bool bot_ai::HasVehicleRoleOverride(uint32 role) const
{
    if (Creature const* veh = me->GetVehicleCreatureBase())
    {
        switch (veh->GetEntry())
        {
            case CREATURE_NEXUS_SKYTALON_1:
            case CREATURE_EOE_SKYTALON_N:
            case CREATURE_EOE_SKYTALON_H:
            case CREATURE_OCULUS_DRAKE_RUBY:
            case CREATURE_OCULUS_DRAKE_EMERALD:
            case CREATURE_OCULUS_DRAKE_AMBER:
            //case CREATURE_TOC_STEED_QUELDOREI:
            //case CREATURE_TOC_NIGHTSABER:
            //case CREATURE_TOC_STEED_STORMWIND:
            //case CREATURE_TOC_MECHANOSTRIDER:
            //case CREATURE_TOC_RAM:
            //case CREATURE_TOC_ELEKK:
            //case CREATURE_TOC_HAWKSTRIDER_SUNREAVER:
            //case CREATURE_TOC_RAPTOR:
            //case CREATURE_TOC_WARHORSE:
            //case CREATURE_TOC_WOLF:
            //case CREATURE_TOC_HAWKSTRIDER_SILVERMOON:
            //case CREATURE_TOC_KODO:
            case CREATURE_TOC5_WARHORSE:
            case CREATURE_TOC5_BATTLEWORG:
            case CREATURE_ULDUAR_DEMOLISHER:
                switch (role)
                {
                    case BOT_ROLE_RANGED:
                        return true;
                    default:
                        break;
                }
                break;
            default:
                break;
        }
    }

    return false;
}
float bot_ai::GetVehicleAttackDistanceOverride() const
{
    if (Creature const* veh = me->GetVehicleCreatureBase())
    {
        switch (veh->GetEntry())
        {
            case CREATURE_NEXUS_SKYTALON_1:
            case CREATURE_EOE_SKYTALON_N:
            case CREATURE_EOE_SKYTALON_H:
            case CREATURE_OCULUS_DRAKE_RUBY:
            case CREATURE_OCULUS_DRAKE_EMERALD:
            case CREATURE_OCULUS_DRAKE_AMBER:
                return 30.f;
            //case CREATURE_TOC_STEED_QUELDOREI:
            //case CREATURE_TOC_NIGHTSABER:
            //case CREATURE_TOC_STEED_STORMWIND:
            //case CREATURE_TOC_MECHANOSTRIDER:
            //case CREATURE_TOC_RAM:
            //case CREATURE_TOC_ELEKK:
            //case CREATURE_TOC_HAWKSTRIDER_SUNREAVER:
            //case CREATURE_TOC_RAPTOR:
            //case CREATURE_TOC_WARHORSE:
            //case CREATURE_TOC_WOLF:
            //case CREATURE_TOC_HAWKSTRIDER_SILVERMOON:
            //case CREATURE_TOC_KODO:
            case CREATURE_TOC5_WARHORSE:
            case CREATURE_TOC5_BATTLEWORG:
                return 15.f;
            case CREATURE_ULDUAR_DEMOLISHER:
                return 40.f;
            default:
                break;
        }
    }

    return 0.0f;
}
uint8 bot_ai::LivingVehiclesCount(uint32 entry) const
{
    if (IAmFree())
        return 0;

    uint8 count = 0;
    if (master->GetVehicle())
        ++count;
    BotMap const* map = master->GetBotMgr()->GetBotMap();
    for (BotMap::const_iterator itr = map->begin(); itr != map->end(); ++itr)
        if (itr->second && itr->second->GetVehicle() && (!entry || entry == itr->second->GetVehicleBase()->GetEntry()))
            ++count;

    return count;
}
//GLOBAL UPDATE
void bot_ai::UpdateDeadAI(uint32 diff)
{
    // group update
    if (_groupUpdateTimer <= diff)
        SendUpdateToOutOfRangeBotGroupMembers();

    // soulstone
    if (GetSelfRezSpell() && (IAmFree() || !master->GetBotMgr()->IsPartyInCombat()) && Rand() < 15)
        me->CastSpell(me, GetSelfRezSpell());
}
//opponent unsafe
bool bot_ai::GlobalUpdate(uint32 diff)
{
    if (!BotMgr::IsNpcBotModEnabled() || !BotDataMgr::AllBotsLoaded())
        return false;

    if (IsWanderer())
    {
        if (Battleground* bg = GetBG())
        {
            if (bg->GetStatus() == STATUS_WAIT_LEAVE)
            {
                if (std::find_if(bg->GetPlayers().cbegin(), bg->GetPlayers().cend(), [](auto const& kv) { return kv.first.IsPlayer(); }) == bg->GetPlayers().cend())
                    bg->RemoveBotAtLeave(me->GetGUID());
                return false;
            }
        }
    }
    else
    {
        if (_checkOwershipTimer && _checkOwershipTimer <= diff)
        {
            if (IAmFree())
            {
                NpcBotData const* npcBotData = BotDataMgr::SelectNpcBotData(me->GetEntry());
                if (npcBotData->owner != 0)
                {
                    CheckOwnerExpiry();
                    if (npcBotData->owner == 0)
                    {
                        _checkOwershipTimer = 0;
                        return false;
                    }
                }
            }
            _checkOwershipTimer = CalculateOwnershipCheckTime();
        }
    }

    //db saves with cd
    //  1) disabled spells
    if (_saveDisabledSpells && _saveDisabledSpellsTimer <= diff)
    {
        _saveDisabledSpells = false;
        _saveDisabledSpellsTimer = 5000;

        if (!IsTempBot())
        {
            NpcBotData* npcBotData = const_cast<NpcBotData*>(BotDataMgr::SelectNpcBotData(me->GetEntry()));
            BotDataMgr::UpdateNpcBotData(me->GetEntry(), NPCBOT_UPDATE_DISABLED_SPELLS, &npcBotData->disabled_spells);
        }
    }

    if (_updateTimerEx2 <= diff)
    {
        _updateTimerEx2 = urand(2000, 4000);

        if (BotMgr::HideBotSpawns() && IAmFree() && !IsWanderer())
        {
            // !!bot may be out of world!!
            Map* mymap = me->FindMap();
            if (mymap)
            {
                std::list<Player*> plist;
                Trinity::AnyPlayerInPositionRangeCheck pcheck(me, 15.0f, false);
                Trinity::PlayerListSearcher<decltype(pcheck)> searcher(me, plist, pcheck);
                Cell::VisitWorldObjects(me, searcher, 20.f);
                _canAppearInWorld = std::any_of(plist.cbegin(), plist.cend(), [](Player const* pl) { return pl->GetSession()->GetSecurity() > SEC_PLAYER; });
                if (!CanAppearInWorld() && !IsDuringTeleport())
                    BotMgr::TeleportBot(me, mymap, me, true);
            }
            else
            {
                _canAppearInWorld = false;
                TC_LOG_ERROR("npcbots", "Bot {} tried to check hide status but doesn't have a valid map set", me->GetEntry());
            }
        }
        else
            _canAppearInWorld = true;
    }

    ReduceCD(diff);

    UpdateContestedPvP();

    lastdiff = diff;

    FindMaster();

    if (IsDuringTeleport())
        return false;

    if (_updateTimerMedium <= diff)
    {
        _updateTimerMedium = 500;

        //Medium-timed updates

        //send stats update for group frames
        if (me->IsInWorld() && !IAmFree())
        {
            //update pvp state
            if (me->GetByteValue(UNIT_FIELD_BYTES_2, 1) != master->GetByteValue(UNIT_FIELD_BYTES_2, 1))
                me->SetByteValue(UNIT_FIELD_BYTES_2, 1, master->GetByteValue(UNIT_FIELD_BYTES_2, 1));

            //vehicle enter delayed
            if (shouldEnterVehicle && master->IsInWorld() && me->IsAlive() &&/* !HasBotCommandState(BOT_COMMAND_MASK_UNMOVING) &&*/
                !me->GetVehicle() && master->GetVehicle() && !CCed(me, true) && !IsCasting())
            {
                shouldEnterVehicle = false;
                AfterBotOwnerEnterVehicle();
            }

            //gossip availability check
            if (HasBotCommandState(BOT_COMMAND_NOGOSSIP) && me->HasNpcFlag(UNIT_NPC_FLAG_GOSSIP))
                me->RemoveNpcFlag(UNIT_NPC_FLAG_GOSSIP);
        }

        if (me->IsInWorld() && me->IsAlive() && IAmFree())
        {
            if (me->HasAuraType(SPELL_AURA_MOUNTED) && IsIndoors() && sWorld->getBoolConfig(CONFIG_VMAP_INDOOR_CHECK))
                me->RemoveAurasWithAttribute(SPELL_ATTR0_OUTDOORS_ONLY);
        }
    }

    if (!me->IsAlive())
        return false;

    if (!me->IsInWorld())
    {
        if (IAmFree())
            TC_LOG_ERROR("scripts", "bot_ai::GlobalUpdate is called for free bot not in world: {} ({}) class {} level {}",
                me->GetName(), me->GetEntry(), uint32(_botclass), uint32(me->GetLevel()));
        return false;
    }

    if (doHealth)
    {
        doHealth = false;
        _OnHealthUpdate();
    }
    if (doMana)
    {
        doMana = false;
        _OnManaUpdate();
    }

    // group update
    if (_groupUpdateTimer <= diff)
        SendUpdateToOutOfRangeBotGroupMembers();

    if (ordersTimer <= diff)
        _ProcessOrders();

    //if (me->HasInvisibilityAura() || me->HasStealthAura())
    //    return false;

    //Check current cast state: interrupt casts that became pointless
    if (me->HasUnitState(UNIT_STATE_CASTING) && !HasBotCommandState(BOT_COMMAND_ISSUED_ORDER) && urand(1,100) <= 75)
    {
        bool interrupt;
        Unit const* target;
        for (uint8 i = CURRENT_FIRST_NON_MELEE_SPELL; i != CURRENT_MAX_SPELL; ++i)
        {
            interrupt = false;
            Spell* spell = me->GetCurrentSpell(CurrentSpellTypes(i));
            if (!spell)
                continue;

            SpellInfo const* info = spell->GetSpellInfo();
            if (!info->CastTimeEntry)
                continue;

            if (info->Id == SHOOT_WAND && me->isMoving())
                interrupt = true;
            else
            {
                // not interrupted yet, next checks require target, ensure validity
                // kidna expensive but prevents invalid targets
                if (spell->m_targets.GetObjectTargetGUID().IsAnyTypeCreature())
                    spell->m_targets.Update(me);
                target = spell->m_targets.GetUnitTarget();
                if (!target)
                    continue;
            }

            if (!interrupt && !info->IsPositive())
            {
                if (!target->IsAlive() && info->Id != SPELL_CORPSE_EXPLOSION && info->Id != SPELL_RAISE_DEAD)
                    interrupt = true;
                else if ((info->Mechanic == MECHANIC_POLYMORPH || info->Mechanic == MECHANIC_SHACKLE ||
                    info->Mechanic == MECHANIC_DISORIENTED || info->Mechanic == MECHANIC_SLEEP ||
                    info->Mechanic == MECHANIC_CHARM || info->Mechanic == MECHANIC_BANISH ||
                    info->Mechanic == MECHANIC_STUN || info->Mechanic == MECHANIC_FREEZE) &&
                    info->GetFirstRankSpell()->Id != 710 && info->GetFirstRankSpell()->Id != SPELL_SLEEP &&
                    !target->getAttackers().empty() && !IsCasting(target))
                    interrupt = true; //useless control (except banish, checked inside class ai)
                else if (target->HasAuraType(SPELL_AURA_PERIODIC_DAMAGE) && !IsCasting(target) &&
                    (info->AuraInterruptFlags & AURA_INTERRUPT_FLAG_TAKE_DAMAGE) && _botclass != BOT_CLASS_MAGE)
                    interrupt = true; //useless control breaks immediately (skip glyphed poly)
                else if (info->DmgClass == SPELL_DAMAGE_CLASS_MAGIC && !(info->Attributes & SPELL_ATTR0_ABILITY) &&
                    !(info->AttributesEx & SPELL_ATTR1_CANT_BE_REFLECTED) &&
                    !(info->Attributes & SPELL_ATTR0_UNAFFECTED_BY_INVULNERABILITY) &&
                    (target->GetTotalAuraModifier(SPELL_AURA_REFLECT_SPELLS) > 60 ||
                    target->GetTotalAuraModifierByMiscMask(SPELL_AURA_REFLECT_SPELLS_SCHOOL, info->GetSchoolMask()) > 60))
                    interrupt = true; // reflect
                else if (
                    info->Id != 64382 && //shattering throw
                    info->Id != 32375 && //mass dispel
                    info->GetFirstRankSpell()->Id != 710 && //banish
                    target->IsImmunedToSpell(info, me))
                    interrupt = true; // immune
                else if (i != CURRENT_CHANNELED_SPELL && //channeled targeted spells will be interrupted in Spell::update()
                    spell->GetCastTime() < spell->GetTimer() * 3 && // >=33% cast time remains
                    !me->IsWithinLOSInMap(target, LINEOFSIGHT_ALL_CHECKS, VMAP::ModelIgnoreFlags::M2))
                    interrupt = true; //LoS
                else if (info->Id == 64382 && !target->HasAuraWithMechanic(1<<MECHANIC_IMMUNE_SHIELD))
                    interrupt = true; //Shattering Throw wasting
            }
            if (!interrupt && !(target == master && me->GetDistance(target) < INTERACTION_DISTANCE) &&
                info->HasEffect(SPELL_EFFECT_HEAL) && GetHealthPCT(target) > 90 && !IsPointedHealTarget(target))
            {
                bool isAreaSpell = false;
                for (uint8 j = 0; j != 3 && isAreaSpell == false; ++j)
                {
                    if (info->_effects[j].IsEffect() && info->_effects[j].TargetA.GetTarget())
                    {
                        if (info->_effects[j].TargetA.GetSelectionCategory() == TARGET_SELECT_CATEGORY_NEARBY ||
                            info->_effects[j].TargetA.GetSelectionCategory() == TARGET_SELECT_CATEGORY_AREA)
                            isAreaSpell = true;
                        if (!isAreaSpell)
                        {
                            switch (info->_effects[j].TargetA.GetTarget())
                            {
                            case TARGET_UNIT_CASTER_AREA_PARTY:
                            case TARGET_DEST_CHANNEL_TARGET:
                                isAreaSpell = true;
                                break;
                            case TARGET_UNIT_TARGET_CHAINHEAL_ALLY:
                                //Healing Wave falls under TARGET_UNIT_TARGET_CHAINHEAL_ALLY
                                if (info->GetFirstRankSpell()->Id == 331)
                                    break;
                                isAreaSpell = true;
                                break;
                            default:
                                break;
                            }
                        }
                        break;
                    }
                }

                if (isAreaSpell == false)
                {
                    if (!IsTank(target) || target->getAttackers().empty() ||
                        spell->GetTimer() * 4 <= spell->GetCastTime()) //<=25% cast time remains
                        interrupt = true;
                }
            }
            if (!interrupt && (info->HasEffect(SPELL_EFFECT_RESURRECT) || info->HasEffect(SPELL_EFFECT_RESURRECT_NEW)) &&
                (target->IsAlive() || (target->GetTypeId() == TYPEID_PLAYER && target->ToPlayer()->IsResurrectRequested())))
                interrupt = true;
            if (!interrupt && checkAurasTimer <= diff && me->GetMap()->IsDungeon() && !CCed(me, true) && IsWithinAoERadius(*me))
                interrupt = true;

            if (interrupt)
            {
                me->InterruptSpell(CurrentSpellTypes(i));
                GC_Timer = 0;
                break;
            }
        }
    }

    if (_updateTimerEx1 <= diff)
    {
        _updateTimerEx1 = urand(2000, 2500);

        //Ex1-timed updates

        //DEBUG
        /*
        Sometimes bots are affected by zone (instance) scripts
        Good example is CoT: Battle for Mount Hyjal
        */
        //Faction
        //ensure master is not controlled
        ChrRacesEntry const* rEntry = sChrRacesStore.LookupEntry(master->GetRace());
        uint32 fac = rEntry ? rEntry->FactionID : 0;
        if (me->GetFaction() != master->GetFaction() && master->GetFaction() == fac)
        {
            //std::ostringstream msg;
            //msg << "Something changed my faction (now " << me->GetFaction() << "), changing back to " << fac << "!";
            //BotWhisper(msg.str().c_str());
            me->SetFaction(fac);
        }
        //Visibility
        if (!me->IsVisible() && master->IsVisible())
        {
            //BotWhisper("Something changed my visibility status! Making visible...");
            me->SetVisible(true);
        }
        if (me->IsVisible() && !master->IsVisible())
        {
            //BotWhisper("Something changed my visibility status! Making invisible...");
            me->SetVisible(false);
        }
        //Phase
        if (me->GetPhaseMask() != master->GetPhaseMask())
        {
            //BotWhisper("Somehow we are not is same phase! Fixing that...");
            me->SetPhaseMask(master->GetPhaseMask(), true);
        }
        //Vehicle state
        //if (me->GetVehicle() && !master->GetVehicle())
        //{
        //    BotWhisper("Somehow i'm still in the vehicle! Exiting...");
        //    OnBotOwnerExitVehicle(nullptr);
        //}
        ////Vehicle speed
        //if (me->GetVehicle() && master->GetVehicle() && me->GetVehicleBase()->GetTypeId() == TYPEID_UNIT &&
        //    (me->GetVehicleBase()->ToCreature()->GetCreatureTemplate()->InhabitType & INHABIT_AIR) &&
        //    me->GetVehicleBase()->GetSpeed(MOVE_FLIGHT) != master->GetVehicleBase()->GetSpeed(MOVE_FLIGHT))
        //{
        //    me->GetVehicleBase()->SetSpeed(MOVE_FLIGHT, master->GetVehicleBase()->GetSpeedRate(MOVE_FLIGHT) * 1.37f);
        //    me->GetVehicleBase()->SetSpeed(MOVE_RUN, master->GetVehicleBase()->GetSpeedRate(MOVE_FLIGHT) * 1.37f);
        //}
        //Transport state
        if (me->GetTransport() != master->GetTransport())
        {
            if (master->GetTransport())
            {
                if (me->GetDistance2d(master) < 20.f)
                {
                    master->GetTransport()->AddPassenger(me);
                    me->m_movementInfo.transport.pos.Relocate(master->GetTransOffset());
                    me->Relocate(GetAbsoluteTransportPosition(master));
                    me->AddUnitState(UNIT_STATE_IGNORE_PATHFINDING);
                }
            }
            else
            {
                me->ClearUnitState(UNIT_STATE_IGNORE_PATHFINDING);
                me->GetTransport()->RemovePassenger(me);
            }
        }
        //Model size / Combat reach
        if (me->GetDisplayId() == me->GetNativeDisplayId())
        {
            me->SetFloatValue(UNIT_FIELD_BOUNDINGRADIUS, DEFAULT_PLAYER_BOUNDING_RADIUS * me->GetObjectScale());
            me->SetFloatValue(UNIT_FIELD_COMBATREACH,  DEFAULT_PLAYER_COMBAT_REACH * me->GetObjectScale());

            //debug: restore offhand visual if needed
            if (me->GetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID + uint32(BOT_SLOT_OFFHAND)) == 0 && _canUseOffHand())
            {
                EquipmentInfo const* einfo = BotDataMgr::GetBotEquipmentInfo(me->GetEntry());
                if (CanChangeEquip(BOT_SLOT_OFFHAND) && _equips[BOT_SLOT_OFFHAND])
                {
                    NpcBotTransmogData const* transmogData = BotDataMgr::SelectNpcBotTransmogs(me->GetEntry());
                    if (einfo->ItemEntry[BOT_SLOT_OFFHAND] != _equips[BOT_SLOT_OFFHAND]->GetEntry() &&
                        transmogData && BotMgr::IsTransmogEnabled() && (transmogData->transmogs[BOT_SLOT_OFFHAND].first == _equips[BOT_SLOT_OFFHAND]->GetEntry() || BotMgr::TransmogUseEquipmentSlots()) &&
                        transmogData->transmogs[BOT_SLOT_OFFHAND].second >= 0)
                        me->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID + uint32(BOT_SLOT_OFFHAND), uint32(transmogData->transmogs[BOT_SLOT_OFFHAND].second));
                    else
                        me->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID + uint32(BOT_SLOT_OFFHAND), _equips[BOT_SLOT_OFFHAND]->GetEntry());
                }
                else
                {
                    me->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID + uint32(BOT_SLOT_OFFHAND), einfo->ItemEntry[BOT_SLOT_OFFHAND]);
                }
            }
        }
        //end DEBUG

        //Check if moving through air
        //if (me->IsInWorld() && !JumpingFlyingOrFalling() &&
        //    !me->HasUnitMovementFlag((MOVEMENTFLAG_ONTRANSPORT)|(MOVEMENTFLAG_DISABLE_GRAVITY)|(MOVEMENTFLAG_ROOT)|(MOVEMENTFLAG_SWIMMING)))
        //{
        //    //skip case such as moving back up from abyss (movement glitches)
        //    float x,y,z;
        //    if (!me->GetMotionMaster()->GetDestination(x,y,z) || z < me->GetPositionZ())
        //    {
        //        float groundz = me->GetMap()->GetHeight(me->GetPhaseMask(), me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), true, MAX_FALL_DISTANCE);
        //        if (groundz > INVALID_HEIGHT)
        //        {
        //            me->GetMotionMaster()->MoveFall();
        //        }
        //        else if (GetBotCommandState() != BOT_COMMAND_STAY && !me->isMoving())
        //        {
        //            SetBotCommandState(BOT_COMMAND_ABANDON); //reset movement after
        //        }
        //    }
        //}

        //Zone / Area / WMOArea
        if (me->IsInWorld())
        {
            uint32 newzone, newarea;
            me->GetZoneAndAreaId(newzone, newarea);

            if (_lastZoneId != newzone)
                _OnZoneUpdate(newzone, newarea); // also updates area
            else// if (_lastAreaId != newarea)
                _OnAreaUpdate(newarea);

            if (_wmoAreaUpdateTimer <= diff)
                _UpdateWMOArea();
        }

        //Meeting Stone
        if (me->IsInWorld() && !IAmFree() && !me->IsInCombat() && !master->IsInCombat() && IsChanneling(master) && !CCed(me) && !IsCasting() && !me->GetVehicle())
        {
            if (Spell const* curMasterSpell = master->GetCurrentSpell(CURRENT_CHANNELED_SPELL))
            {
                if (curMasterSpell->m_spellInfo->Id == SUMMONING_STONE_EFFECT)
                {
                    if (GameObject* portal = master->GetGameObject(SUMMONING_STONE_EFFECT))
                    {
                        portal->Use(me);
                    }
                }
            }
        }

        //Gathering
        if (me->IsInWorld() && !IAmFree() && HasRole(BOT_ROLE_MASK_GATHERING) && !me->IsInCombat() && !master->IsInCombat() && !master->IsMounted() && !CCed(me) &&
            master->GetLootGUID().IsEmpty() && !me->isMoving() && !master->isMoving() && master->IsStandState() && !Feasting() && !IsCasting() && !IsCasting(master) &&
            !HasBotCommandState(BOT_COMMAND_MASK_UNMOVING) && !me->GetVehicle())
        {
            //TC_LOG_ERROR("spells", "bot_ai:UpdateEx by {}, found free master, my skills: {}:", me->GetName(), uint32(_roleMask & BOT_ROLE_MASK_GATHERING));
            std::list<WorldObject*> woList;
            NearbyObjectBySkillCheck check(master, INTERACTION_DISTANCE - 1.0f, (_roleMask & BOT_ROLE_MASK_GATHERING));
            Trinity::WorldObjectListSearcher<NearbyObjectBySkillCheck> searcher(me, woList, check, GRID_MAP_TYPE_MASK_CREATURE|GRID_MAP_TYPE_MASK_GAMEOBJECT);
            Cell::VisitAllObjects(me, searcher, 20.f);
            //me->VisitNearbyObject(20.f, searcher);
            //TC_LOG_ERROR("spells", "bot_ai:UpdateEx: list is {}", woList.empty() ? "empty" : "not empty");
            if (!woList.empty())
            {
                WorldObject* wo = nullptr;
                float minangle = float(M_PI);
                for (WorldObject* wob : woList)
                {
                    float angle = me->GetAbsoluteAngle(wob);
                    if (me->GetDistance(wob) <= INTERACTION_DISTANCE * 0.5f && angle < minangle)
                    {
                        minangle = angle;
                        wo = wob;
                    }
                }

                wo = wo ? wo : Trinity::Containers::SelectRandomContainerElement(woList);
                //TC_LOG_ERROR("spells", "bot_ai:UpdateEx: processing {}", wo->GetName());
                if (me->GetDistance(wo) <= INTERACTION_DISTANCE * 0.5f && me->HasInArc(float(M_PI), wo))
                {
                    //cosmetic
                    CastSpellExtraArgs args(TRIGGERED_FULL_MASK);
                    me->CastSpell(wo->GetTypeId() == TYPEID_UNIT ? wo->ToUnit() : me, SPELL_COMBAT_SPECIAL_2H_ATTACK, args);

                    if (wo->GetTypeId() == TYPEID_UNIT)
                        wo->ToUnit()->SetDynamicFlag(UNIT_DYNFLAG_LOOTABLE);

                    master->SendLoot(wo->GetGUID(), LOOT_SKINNING);

                    if (wo->GetTypeId() == TYPEID_UNIT)
                        wo->ToUnit()->RemoveUnitFlag(UNIT_FLAG_SKINNABLE);

                    _updateTimerEx1 = urand(1500, 2100);
                }
                else
                {
                    std::ostringstream msg;
                    std::string name = wo->GetName();
                    if (wo->GetTypeId() == TYPEID_UNIT)
                    {
                        _LocalizeCreature(master, name, wo->GetEntry());
                        msg << name << "..."; // TODO
                    }
                    else
                    {
                        _LocalizeGameObject(master, name, wo->GetEntry());
                        msg << name << "!";
                    }
                    BotWhisper(msg.str().c_str());

                    if (me->GetDistance(wo) > INTERACTION_DISTANCE * 0.5f)
                    {
                        Position pos;
                        wo->GetNearPoint(me, pos.m_positionX, pos.m_positionY, pos.m_positionZ, CONTACT_DISTANCE, wo->GetAbsoluteAngle(me));
                        BotMovement(BOT_MOVE_POINT, &pos, nullptr, false);
                        //me->GetMotionMaster()->MovePoint(me->GetMapId(), pos, false);
                    }
                    else
                    {
                        me->SetFacingTo(me->GetAbsoluteAngle(wo));
                        _updateTimerEx1 = urand(1500, 1800);
                    }
                }
            }
        }

        //Looting
        if (me->IsInWorld() && !IAmFree() && HasRole(BOT_ROLE_AUTOLOOT) && HasRole(BOT_ROLE_MASK_LOOTING) &&
            !me->GetVictim() && !master->IsMounted() && !CCed(me) && !Feasting() && !IsCasting() &&
            !HasBotCommandState(BOT_COMMAND_MASK_UNMOVING))
        {
            //TC_LOG_ERROR("scripts", "bot_ai Looting by {}, my mask: {}:", me->GetName(), uint32(_roleMask & BOT_ROLE_MASK_LOOTING));
            std::list<Unit*> crList;
            NearbyLootableCreatureCheck check(master, std::min(30.f, std::max(5.f, sWorld->getFloatConfig(CONFIG_GROUP_XP_DISTANCE) - 10.f)));
            Trinity::UnitListSearcher<NearbyLootableCreatureCheck> searcher(me, crList, check);
            Cell::VisitAllObjects(me, searcher, 40.f);
            //me->VisitNearbyObject(40.f, searcher);
            for (std::list<Unit*>::iterator itr = crList.begin(); itr != crList.end();)
            {
                if (!_canLootCreature((*itr)->ToCreature()))
                {
                    //TC_LOG_ERROR("scripts", "bot_ai Looting: cannot loot {} ({})", (*itr)->GetName(), (*itr)->GetGUIDLow());
                    crList.erase(itr++);
                    continue;
                }
                ++itr;
            }

            if (!crList.empty())
            {
                Unit* un = Trinity::Containers::SelectRandomContainerElement(crList);

                std::ostringstream msg;
                std::string name = un->GetName();
                _LocalizeCreature(master, name, un->GetEntry());
                msg << LocalizedNpcText(master, BOT_TEXT_LOOTING) << ' ' << name;
                BotWhisper(msg.str().c_str());

                _autoLootCreature(un->ToCreature());

                if (crList.size() > 1)
                    _updateTimerEx1 = urand(400, 600);
                /*//TC_LOG_ERROR("scripts", "bot_ai Looting: processing {}", un->GetName());
                if (me->GetDistance(un) < INTERACTION_DISTANCE + 2.f)
                {
                    //TC_LOG_ERROR("scripts", "bot_ai Looting: looting {}", un->GetName());
                    _autoLootCreature(un->ToCreature());
                    _updateTimerEx1 = urand(500, 1000);
                }
                else
                {
                    //TC_LOG_ERROR("scripts", "bot_ai Looting: moving towards {}", un->GetName());
                    Position pos;
                    un->GetNearPoint(me, pos.m_positionX, pos.m_positionY, pos.m_positionZ, 0.f, CONTACT_DISTANCE, un->GetAbsoluteAngle(me));
                    me->GetMotionMaster()->MovePoint(me->GetMapId(), pos, false);
                }*/
            }
        }
    }

    if (!IsTempBot())
        Regenerate();

    //update flags
    if (!me->IsInCombat() && ((!_evadeMode && _atHome) || IsWanderer()))
    {
        if (!me->HasNpcFlag(UNIT_NPC_FLAG_GOSSIP) && !HasBotCommandState(BOT_COMMAND_NOGOSSIP))
            me->SetNpcFlag(UNIT_NPC_FLAG_GOSSIP);
        if (me->HasUnitFlag(UNIT_FLAG_PET_IN_COMBAT))
            me->RemoveUnitFlag(UNIT_FLAG_PET_IN_COMBAT);
    }

    if (!me->GetVictim())
        Evade();

    if (HasBotCommandState(BOT_COMMAND_FULLSTOP))
        return false;

    if (!IsTempBot())
        _updateRations(); //safe

    if (checkAurasTimer <= lastdiff)
    {
        checkAurasTimer += uint32(__rand + __rand + (IAmFree() ? 1000 : 40 * (1 + master->GetNpcBotsCount())));

        //group demand
        if (!IAmFree() && HasRole(BOT_ROLE_PARTY) && (!master->GetGroup() || !master->GetGroup()->IsMember(me->GetGUID())))
        {
            //TC_LOG_ERROR("entities.player", "CheckAuras(): adding {} to group", me->GetName());
            master->GetBotMgr()->AddBotToGroup(me);
        }

        Unit* mover = me->GetVehicle() ? me->GetVehicleBase() : me;
        if (!HasBotCommandState(BOT_COMMAND_MASK_UNCHASE) && !CCed(mover, true) &&
            (IAmFree() || master->GetBotMgr()->GetBotAllowCombatPositioning()) &&
            (!mover->isMoving() || Rand() < 50) && !IsCasting(mover) && !IsShootingWand(mover))
        {
            if (Unit* victim = CanBotAttackOnVehicle() ? me->GetVictim() : mover->GetTarget() ? ObjectAccessor::GetUnit(*mover, mover->GetTarget()) : nullptr)
            {
                _aoeSpots.clear();
                if (IAmFree())
                    CalculateAoeSpots(me, _aoeSpots);

                //TC_LOG_ERROR("scripts", "GetInPos prepare by {}", me->GetName());
                if (!IAmFree() && master->GetBotMgr()->GetBotAttackRangeMode() == BOT_ATTACK_RANGE_EXACT &&
                    master->GetBotMgr()->GetBotExactAttackRange() == 0 && !GetVehicleAttackDistanceOverride() &&
                    !(!IAmFree() && !GetAoeSpots().empty()))
                {
                    GetInPosition(true, victim);
                }
                else if (!HasRole(BOT_ROLE_RANGED) && !HasVehicleRoleOverride(BOT_ROLE_RANGED) &&
                    !(!IAmFree() && !GetAoeSpots().empty()))
                {
                    if (me->GetDistance(victim) > 1.5f)
                        GetInPosition(true, victim);
                }
                else
                {
                    //TC_LOG_ERROR("scripts", "{} calculates attack pos to attack {}", me->GetName(), victim->GetName());
                    bool force = false;
                    CalculateAttackPos(victim, attackpos, force);
                    if (mover->GetExactDist2d(&attackpos) > (force ? 0.1f : 4.f) || (force && IsWanderer()))
                    {
                        //TC_LOG_ERROR("scripts", "{} moving to x {} y {} z {} to attack {}",
                        //    me->GetName(), attackpos.m_positionX, attackpos.m_positionY, attackpos.m_positionZ, victim->GetName());
                        GetInPosition(true, victim, &attackpos);
                    }
                }
            }
        }
        if (shouldUpdateStats && me->GetPhaseMask() == master->GetPhaseMask())
            SetStats(false);
        else if (_powersTimer <= lastdiff && !IsTempBot())
        {
            _powersTimer += REGEN_CD; //do not mistake for regen, this is only for updating max health/mana
            UpdateHealth();
            UpdateMana();
        }
    }

    if (Wait())
        return false;

    GenerateRand();

    if (CanBotAttackOnVehicle())
        BreakCC(diff);

    if (!me->GetVehicle() && CCed(me))
        return false;

    //opponent unsafe
    if ((IsWanderer() || (!IAmFree() && (!opponent || !master->GetBotMgr()->GetBotAllowCombatPositioning()))) &&
        !HasBotCommandState(BOT_COMMAND_STAY) &&
        (!me->GetVehicle() || (!CCed(me->GetVehicleBase(), true) && !me->GetVehicleBase()->GetTarget())))
    {
        Unit const* mover = me->GetVehicle() ? me->GetVehicleBase() : me;

        if (!master->IsAlive())
        {
            //If ghost move to corpse, else move to dead player
            if (master->HasFlag(PLAYER_FLAGS, PLAYER_FLAGS_GHOST))
            {
                Corpse const* corpse = master->GetCorpse();
                if (corpse && me->GetMap() == corpse->FindMap() && !me->IsInCombat() && !me->HasUnitState(UNIT_STATE_MOVING) &&
                    !IsCasting() && !IsShootingWand() && me->GetDistance(corpse) > 5)
                    BotMovement(BOT_MOVE_POINT, corpse);
                    //me->GetMotionMaster()->MovePoint(corpse->GetMapId(), *corpse);
            }
            else
            {
                if (!HasBotCommandState(BOT_COMMAND_FOLLOW) || me->GetDistance(master) > 30 - 20 * (!me->IsWithinLOSInMap(master)))
                    SetBotCommandState(BOT_COMMAND_FOLLOW, true);
            }
        }
        else if (!IsCasting(mover) && (!IsShootingWand(mover) || Rand() < 10))
        {
            Unit const* mmover = !IAmFree() ? master : nullptr;
            if (!mmover && me->GetMap()->IsBattleground() && !IsFlagCarrier(me))
            {
                //GET BG FOLLOW UNIT
                static const std::function<bool(Unit const*)> flag_carrier_pred = [](Unit const* u) {
                    return bot_ai::IsFlagCarrier(u);
                };

                Unit* nmover = nullptr;
                Trinity::UnitSearcher searcher(me, nmover, flag_carrier_pred);
                Cell::VisitAllObjects(me, searcher, 80.0f);
                if (nmover)
                    mmover = nmover;
            }

            if (mmover)
            {
                float speed = 0.0f;
                _calculatePos(mmover, movepos, &speed);
                float maxdist = std::max<float>((mmover->IsPlayer() ? mmover->ToPlayer()->GetBotMgr()->GetBotFollowDist() : BotMgr::GetBotFollowDistMax() / 2) *
                    ((mmover->m_movementInfo.GetMovementFlags() & MOVEMENTFLAG_FORWARD) ? 0.125f : mmover->isMoving() ? 0.03125f : 0.25f), 3.f);
                Position destPos;
                if (me->isMoving())
                    me->GetMotionMaster()->GetDestination(destPos.m_positionX, destPos.m_positionY, destPos.m_positionZ);
                else
                    destPos = me->GetPosition();

                if (!HasBotCommandState(BOT_COMMAND_FOLLOW) || destPos.GetExactDist(&movepos) > maxdist)
                    SetBotCommandState(BOT_COMMAND_FOLLOW, true, &movepos, &speed);
            }
            else
                RemoveBotCommandState(BOT_COMMAND_FOLLOW);
        }
    }

    if (!IsCasting() && !IsShootingWand())
    {
        if ((me->IsInCombat() && !me->IsSitState() && CanBotAttackOnVehicle()) || !CanSheath())
        {
            if (_botclass == BOT_CLASS_HUNTER || _botclass == BOT_CLASS_DARK_RANGER || _botclass == BOT_CLASS_SEA_WITCH)
            {
                if (me->GetSheath() != SHEATH_STATE_RANGED)
                    me->SetSheath(SHEATH_STATE_RANGED);
            }
            else
            {
                //classes which don't display weapons
                if (_botclass == BOT_CLASS_DREADLORD || _botclass == BOT_CLASS_SPELLBREAKER || _botclass == BOT_CLASS_CRYPT_LORD)
                {
                    if (me->GetSheath() != SHEATH_STATE_UNARMED)
                        me->SetSheath(SHEATH_STATE_UNARMED);
                }
                else if (me->GetSheath() != SHEATH_STATE_MELEE)
                    me->SetSheath(SHEATH_STATE_MELEE);
            }
        }
        else if (me->IsStandState() && me->GetSheath() != SHEATH_STATE_UNARMED && Rand() < 50)
        {
            if (me->GetSheath() == SHEATH_STATE_RANGED)
                me->SetSheath(SHEATH_STATE_MELEE);
            else
                me->SetSheath(SHEATH_STATE_UNARMED);
        }
    }

    _updateMountedState();
    _updateStandState();

    if (HasBotCommandState(BOT_COMMAND_INACTION))
        return false;

    return true;
}

void bot_ai::CommonTimers(uint32 diff)
{
    Events.Update(diff);
    SpellTimers(diff);

    if (GC_Timer > diff)            GC_Timer -= diff;
    if (checkAurasTimer > diff)     checkAurasTimer -= diff;
    if (waitTimer > diff)           waitTimer -= diff;
    if (_moveBehindTimer > diff)    _moveBehindTimer -= diff;
    if (itemsAutouseTimer > diff)   itemsAutouseTimer -= diff;
    if (evadeDelayTimer > diff)     evadeDelayTimer -= diff;
    if (roleTimer > diff)           roleTimer -= diff;
    if (ordersTimer > diff)         ordersTimer -= diff;
    if (checkMasterTimer > diff)    checkMasterTimer -= diff;
    if (_checkOwershipTimer > diff) _checkOwershipTimer -= diff;

    if (_powersTimer > diff)        _powersTimer -= diff;
    if (_chaseTimer > diff)         _chaseTimer -= diff;
    if (_engageTimer > diff)        _engageTimer -= diff;

    if (_potionTimer > diff && (_potionTimer < POTION_CD || !me->IsInCombat())) _potionTimer -= diff;

    if (IAmFree())
        UpdateReviveTimer(diff);

    if (me->IsInWorld())
    {
        if (_wmoAreaUpdateTimer > diff) _wmoAreaUpdateTimer -= diff;

        if (me->IsOutdoors())
        {
            outdoorsTimer += diff;
            if (indoorsTimer)
                indoorsTimer = 0;
        }
        else
        {
            indoorsTimer += diff;
            if (outdoorsTimer)
                outdoorsTimer = 0;
        }
    }

    if (_contestedPvPTimer > diff)  _contestedPvPTimer -= diff;

    if (_groupUpdateTimer > diff)   _groupUpdateTimer -= diff;
    else if (_groupUpdateTimer)     _groupUpdateTimer = 0;

    if (_updateTimerMedium > diff)  _updateTimerMedium -= diff;
    if (_updateTimerEx1 > diff)     _updateTimerEx1 -= diff;
    if (_updateTimerEx2 > diff)     _updateTimerEx2 -= diff;

    if (_saveDisabledSpellsTimer > diff) _saveDisabledSpellsTimer -= diff;
}

void bot_ai::UpdateReviveTimer(uint32 diff)
{
    if (me->IsAlive())
        return;

    if (_reviveTimer > diff)        _reviveTimer -= diff;
    else
    {
        if (IAmFree())
        {
            BotMgr::ReviveBot(me);

            if (IsWanderer())
            {
                outdoorsTimer = 0;
                if (me->GetMap()->GetEntry()->IsContinent() || me->GetMap()->IsBattleground())
                {
                    Position safePos(*me);
                    WanderNode const* nextNode = GetNextTravelNode(&safePos, true);
                    if (!nextNode)
                    {
                        TC_LOG_FATAL("scripts", "Bot {} ({}) is unable to get next travel node (1)! cur {}, last {}, position: {}. BOT WAS DISABLED",
                            me->GetName(), me->GetEntry(), _travel_node_cur->GetWPId(), _travel_node_last ? _travel_node_last->GetWPId() : 0, me->GetPosition().ToString());
                        canUpdate = false;
                        return;
                    }

                    homepos.Relocate(nextNode);
                    if (me->GetMap()->GetEntry()->IsContinent())
                        BotMgr::TeleportBot(me, sMapMgr->CreateBaseMap(nextNode->GetMapId()), nextNode, true);

                    TC_LOG_TRACE("npcbots", "Bot {} id {} class {} level {} died on the way from node {} to {} ('{}'), NEW {} ('{}'), {}, dist {} yd!",
                        me->GetName(), me->GetEntry(), uint32(_botclass), uint32(me->GetLevel()), _travel_node_last ? _travel_node_last->GetWPId() : 0, _travel_node_cur->GetWPId(),
                        _travel_node_cur->GetName(), nextNode->GetWPId(), nextNode->GetName(), homepos.ToString(), safePos.GetExactDist(homepos));

                    _travel_node_last = _travel_node_cur;
                    _travel_node_cur = nextNode;
                    return;
                }
            }
        }
        else
            if (_reviveTimer > 0)   _reviveTimer = 0;
    }
}

void bot_ai::Evade()
{
    if (_atHome && !_evadeMode)
        return;
    if (evadeDelayTimer > lastdiff)
        return;
    if (me->GetVictim())
        return;
    if (IAmFree() && HasBotCommandState(BOT_COMMAND_FOLLOW))
        return;
    if (IsWanderer() && Feasting())
        return;
    if (JumpingOrFalling())
        return;
    if (IsCasting())
        return;
    if (CCed(me, true))
        return;

    if (!IAmFree() || IsTempBot())
    {
        _atHome = true;
        _evadeMode = false;
        return;
    }

    if (HasBotCommandState(BOT_COMMAND_MASK_UNMOVING))
        return;

    //delay evade
    if (evadeDelayTimer == 0 && me->GetMap()->GetEntry()->IsContinent())
    {
        evadeDelayTimer = 5000;
        return;
    }

    uint16 mapid;
    Position pos;
    GetHomePosition(mapid, &pos);

    float dist = me->GetExactDist2d(pos);

    if (IsWanderer())
    {
        if (mapid != me->GetMap()->GetId() || _evadeCount >= 50 || me->GetExactDist2d(pos) > MAX_WANDER_NODE_DISTANCE ||
            me->GetPositionZ() <= INVALID_HEIGHT || (me->GetExactDist2d(pos) < 20.0f && me->GetExactDist(pos) > 100.0f))
        {
            TC_LOG_DEBUG("npcbots", "Bot {} id {} class {} level {} map {} TELEPORTING to node {} ('{}') map {}, {}, dist {} yd!",
                me->GetName(), me->GetEntry(), uint32(_botclass), uint32(me->GetLevel()), me->GetMapId(), _travel_node_cur->GetWPId(),
                _travel_node_cur->GetName(), uint32(mapid), pos.ToString(), me->GetExactDist(pos));

            evadeDelayTimer = 12000;
            me->CastSpell(me, WANDERER_HEARTHSTONE);
            return;
        }
    }
    else if (mapid != me->GetMapId() || _evadeCount >= 10 || me->GetDistance(pos) > float(SIZE_OF_GRIDS * 0.5f) || !CanAppearInWorld())
    {
        if (!teleHomeEvent || !teleHomeEvent->IsActive())
        {
            teleHomeEvent = new TeleportHomeEvent(this, false);
            Events.AddEvent(teleHomeEvent, Events.CalculateTime(std::chrono::seconds(5)));

            //if bot has been removed manually and while in dungeon
            if (mapid != me->GetMapId())
            {
                teleHomeEvent->ScheduleAbort();
                teleHomeEvent->Execute(0,0);
            }
        }
        return;
    }

    if (botPet && !me->IsWithinDist2d(botPet, 20.0f))
        return;

    if (!IsWanderer())
        _atHome = true;
    else if (!me->IsInCombat() && me->GetMap()->GetEntry()->IsContinent() && GetHealthPCT(me) < 90)
        return;

    if (dist > 1.5f || IsWanderer())
    {
        _evadeMode = true;

        if (!me->isMoving())
        {
            ++_evadeCount;

            if (dist > (me->GetMap()->GetEntry()->IsContinent() ? 15.0f : 3.0f))
            {
                bool use_path =
                    !(_travel_node_cur && _travel_node_last &&
                    _travel_node_cur->HasFlag(BotWPFlags::BOTWP_FLAG_MOVEMENT_IGNORES_PATHING) &&
                    _travel_node_last->HasFlag(BotWPFlags::BOTWP_FLAG_MOVEMENT_IGNORES_PATHING));
                GetNextEvadeMovePoint(pos, use_path);
                if (pos.m_positionZ <= INVALID_HEIGHT)
                {
                    TC_LOG_ERROR("npcbots", "Bot {} '{}' class {} level {} evade move point has invalid height {} (usepath: {})!\nWPs: cur {}, last {}\nPositions:\ncurrent: {}\ntarget: {}",
                        me->GetEntry(), me->GetName(), uint32(_botclass), uint32(me->GetLevel()), pos.m_positionZ, uint32(use_path),
                        _travel_node_cur->GetWPId(), _travel_node_last ? _travel_node_last->GetWPId() : 0, me->GetPosition().ToString(), pos.ToString());
                    _evadeCount = 100;
                    return;
                }

                //if (TempSummon* wpc = me->GetMap()->SummonCreature(VISUAL_WAYPOINT, pos, nullptr, 20000))
                //    wpc->SetTempSummonType(TEMPSUMMON_TIMED_DESPAWN);

                movepos.Relocate(me);
                BotMovement(BOT_MOVE_POINT, &pos, nullptr, use_path);
                return;
            }
            else if (IsWanderer())
            {
                OnWanderNodeReached();

                WanderNode const* nextNode = GetNextTravelNode(&pos, false);
                if (!nextNode)
                {
                    TC_LOG_FATAL("npcbots", "Bot {} ({}) is unable to get next travel node! cur {}, last {}, position: {}. BOT WAS DISABLED",
                        me->GetName(), me->GetEntry(), _travel_node_cur->GetWPId(), _travel_node_last ? _travel_node_last->GetWPId() : 0, me->GetPosition().ToString());
                    canUpdate = false;
                    return;
                }

                if (nextNode == _travel_node_cur)
                {
                    //same node: mill about
                    float angle = Position::NormalizeOrientation(me->GetRelativeAngle(nextNode) + frand(float(-M_PI_2), float(M_PI_2)));
                    Position cnpos = me->GetFirstCollisionPosition(frand(8.0f, 15.0f), angle);
                    homepos.Relocate(cnpos);
                }
                else
                    homepos.Relocate(nextNode);

                TC_LOG_TRACE("npcbots", "Bot {} id {} class {} level {} wandered from node {} to {}, next {} ('{}'), {}, dist {} yd!",
                    me->GetName(), me->GetEntry(), uint32(_botclass), uint32(me->GetLevel()), _travel_node_last ? _travel_node_last->GetWPId() : 0, _travel_node_cur->GetWPId(),
                    nextNode->GetWPId(), nextNode->GetName(), homepos.ToString(), pos.GetExactDist(homepos));

                if (me->GetMap()->GetEntry()->IsContinent())
                    evadeDelayTimer = urand(3000, 7000);
                else if (nextNode == _travel_node_cur)
                    evadeDelayTimer = urand(4000, 6000);

                _travel_node_last = _travel_node_cur;
                _travel_node_cur = nextNode;
                _evadeCount = 0;
                return;
            }

            movepos.Relocate(me);
            BotMovement(BOT_MOVE_POINT, &pos);
        }

        return;
    }

    if (me->isMoving())
        return;

    _evadeMode = false;
    _evadeCount = 0;
    evadeDelayTimer = 0;

    me->SetFacingTo(pos.GetOrientation());
    me->SetFaction(me->GetCreatureTemplate()->faction);
}
void bot_ai::GetNextEvadeMovePoint(Position& pos, bool& use_path) const
{
    //const uint8 evade_jump_threshold = me->HasUnitMovementFlag(MOVEMENTFLAG_SWIMMING) ? 50 : 25;
    const float base_angle = me->GetRelativeAngle(pos);
    const float orig_z = pos.m_positionZ;
    float ground, floor;

    float fulldist = std::min<float>(me->GetExactDist2d(pos), float((MAX_POINT_PATH_LENGTH - 1) * SMOOTH_PATH_STEP_SIZE - 2.0f));
    PathGenerator path(me);
    while (path.GetPathType() == PATHFIND_BLANK || (path.GetPathType() & (PATHFIND_NOPATH | PATHFIND_SHORTCUT | PATHFIND_SHORT)))
    {
        if (std::fabs(fulldist - me->GetExactDist2d(pos)) > 15.0f)
        {
            pos.Relocate(me->m_positionX, me->m_positionY, me->m_positionZ);
            pos.m_positionX += fulldist * std::cos(me->ToAbsoluteAngle(base_angle));
            pos.m_positionY += fulldist * std::sin(me->ToAbsoluteAngle(base_angle));

            Trinity::NormalizeMapCoord(pos.m_positionX);
            Trinity::NormalizeMapCoord(pos.m_positionY);
            ground = me->GetMapHeight(pos.m_positionX, pos.m_positionY, MAX_HEIGHT, true, MAX_FALL_DISTANCE);
            floor = me->GetMapHeight(pos.m_positionX, pos.m_positionY, pos.m_positionZ);
            pos.m_positionZ = std::fabs(ground - pos.m_positionZ) <= std::fabs(floor - pos.m_positionZ) ? ground : floor;
            if (pos.m_positionZ <= INVALID_HEIGHT)
            {
                me->UpdateGroundPositionZ(pos.m_positionX, pos.m_positionY, pos.m_positionZ);
                if (pos.m_positionZ <= INVALID_HEIGHT)
                    pos.m_positionZ = orig_z;
            }
        }

        path.CalculatePath(pos.m_positionX, pos.m_positionY, pos.m_positionZ);
        if (path.GetPathType() == PATHFIND_BLANK ||
            (path.GetPathType() == PATHFIND_INCOMPLETE && path.GetPath().size() > 2) ||
            (path.GetPathType() & (PATHFIND_NORMAL | PATHFIND_NOT_USING_PATH | PATHFIND_FARFROMPOLY_START)))
            break;

        fulldist *= 0.72f;

        if (fulldist < 25.0f)
            break;
    }

    if ((path.GetPathType() & (PATHFIND_NORMAL | PATHFIND_NOT_USING_PATH)) == (PATHFIND_NORMAL | PATHFIND_NOT_USING_PATH) &&
        path.GetPath().size() > 4)
        return;

    if (me->IsInWater())
        TC_LOG_TRACE("npcbots", "Bot {} id {} class {} level {} is pathing from water!", me->GetName(), me->GetEntry(), uint32(_botclass), uint32(me->GetLevel()));

    switch (path.GetPathType())
    {
        case PATHFIND_NOT_USING_PATH: //swimming
        case PATHFIND_NORMAL: //found path
            if (me->GetExactDist(Vector3ToPosition(path.GetEndPosition())) > 15.0f)
                path.ShortenPathUntilDist(path.GetEndPosition(), frand(7.5f, 15.0f));
            return;
        case PATHFIND_BLANK: // invalid coords
        case PATHFIND_NOPATH:
        case PATHFIND_SHORTCUT:
        case PATHFIND_SHORT:
        case PATHFIND_INCOMPLETE:
        case PATHFIND_FARFROMPOLY: // invalid coords
        case PATHFIND_FARFROMPOLY_START: //invalid start coords
        case PATHFIND_FARFROMPOLY_END: //invalid end coords
            if (path.GetPath().size() > 4)
            {
                path.ShortenPathUntilDist(path.GetEndPosition(), frand(5.0f, 15.0f));
                return;
            }
            //log error and use direct point movement
            TC_LOG_DEBUG("npcbots", "Bot {} id {} class {} level {} can't find full path to node {} (res {}) from pos {}, falling back to default PF!",
                me->GetName(), me->GetEntry(), uint32(_botclass), uint32(me->GetLevel()), IsWanderer() ? _travel_node_cur->GetWPId() : 0, uint32(path.GetPathType()),
                me->GetPosition().ToString());
            break;
        default:
            break;
    }

    use_path = false;

    // No path: proceed to destination in small steps, maybe it's just a fluke... Move to surface if needed
    Position mypos = me->GetPosition();
    float movedist = std::min<float>(fulldist * 0.25f, 15.0f);
    mypos.m_positionX += movedist * std::cos(me->ToAbsoluteAngle(base_angle));
    mypos.m_positionY += movedist * std::sin(me->ToAbsoluteAngle(base_angle));
    Trinity::NormalizeMapCoord(mypos.m_positionX);
    Trinity::NormalizeMapCoord(pos.m_positionY);

    ground = me->GetMapHeight(mypos.m_positionX, mypos.m_positionY, MAX_HEIGHT, true, MAX_FALL_DISTANCE);
    floor = me->GetMapHeight(mypos.m_positionX, mypos.m_positionY, mypos.m_positionZ);
    mypos.m_positionZ = std::fabs(ground - mypos.m_positionZ) <= std::fabs(floor - mypos.m_positionZ) ? ground : floor;
    LiquidData ldata;
    ZLiquidStatus lstatus = me->GetMap()->GetLiquidStatus(
        me->GetPhaseMask(), mypos.m_positionX, mypos.m_positionY, mypos.m_positionZ, MAP_ALL_LIQUIDS, &ldata, me->GetCollisionHeight());
    if (me->IsInWater() != !!(lstatus & MAP_LIQUID_STATUS_IN_CONTACT))
        mypos.m_positionZ = std::max<float>(ldata.level, mypos.m_positionZ);
    if (mypos.m_positionZ <= INVALID_HEIGHT)
        mypos.m_positionZ = orig_z;
    pos.Relocate(mypos);
}
bool bot_ai::CanAppearInWorld() const
{
    return _canAppearInWorld;
}
void bot_ai::TeleportHomeStart(bool reset)
{
    AbortTeleport();

    //if no master - will teleport to spawn position
    //otherwise - will teleport to master
    teleHomeEvent = new TeleportHomeEvent(this, reset);
    Events.AddEvent(teleHomeEvent, Events.CalculateTime(0ms)); //make sure event will be deleted
    if (teleHomeEvent->IsActive())
        teleHomeEvent->ScheduleAbort(); //make sure event will not be executed twice
    teleHomeEvent->Execute(0,0);
}
//TeleportHome() ONLY CALLED THROUGH EVENTPROCESSOR
void bot_ai::TeleportHome(bool reset)
{
    ASSERT(teleHomeEvent);
    //ASSERT(IAmFree());

    AbortTeleport();

    uint16 mapid;
    Position pos;
    GetHomePosition(mapid, &pos);

    Map* map = sMapMgr->CreateBaseMap(mapid);
    ASSERT(!map->Instanceable(), "%s", map->GetDebugInfo().c_str());
    BotMgr::TeleportBot(me, map, &pos, false, reset, this);

    spawned = false;
    _evadeCount = 0;
}
//FinishTeleport(uint32, float, float, float, float) ONLY CALLED THROUGH EVENTPROCESSOR
bool bot_ai::FinishTeleport(bool reset)
{
    ASSERT(teleFinishEvent);
    //ASSERT(!IAmFree());
    ASSERT(!me->IsInWorld());

    AbortTeleport();

    //1) Cannot teleport: master disappeared - return home
    if (IAmFree()/* || master->GetSession()->isLogingOut()*/)
    {
        uint16 mapid = uint16(me->GetMapId());
        Position pos;
        if (BotMgr::HideBotSpawns() && !CanAppearInWorld())
            GetHomePosition(mapid, &pos);
        if (BotMgr::HideBotSpawns() && !CanAppearInWorld() && me->GetMapId() == mapid && me->GetExactDist2d(pos) < 10.0f)
        {
            AbortTeleport();
            TeleportFinishEvent* delayedTeleportEvent = new TeleportFinishEvent(this, reset);
            std::chrono::milliseconds delay(urand(5000, 8000));
            Events.AddEvent(delayedTeleportEvent, Events.CalculateTime(delay));
            SetTeleportFinishEvent(delayedTeleportEvent);
        }
        else
            TeleportHomeStart(!BotMgr::HideBotSpawns());

        _evadeMode = false;
        return false;
    }

    BotLogger::Log(NPCBOT_LOG_TELEPORT_FINISH, me, me->IsInGrid(), me->IsWandererBot(), CanAppearInWorld());

    BotMgr::AddDelayedTeleportCallback([this, reset]() {
        Map* map = master->FindMap();
        //2) Cannot teleport: map not found or forbidden - delay teleport
        if (!map || !master->IsAlive() || master->GetBotMgr()->RestrictBots(me, true))
        {
            //ChatHandler ch(master->GetSession());
            //ch.PSendSysMessage("Your bot %s cannot teleport to you. Restricted bot access on this map...", me->GetName().c_str());
            teleFinishEvent = new TeleportFinishEvent(this, reset);
            Events.AddEvent(teleFinishEvent, Events.CalculateTime(std::chrono::seconds(5)));
            return;
        }

        if (me->FindMap())
            me->ResetMap();

        me->SetMap(map);
        if (master->GetTransport())
        {
            master->GetTransport()->AddPassenger(me);
            me->m_movementInfo.transport.pos.Relocate(master->GetTransOffset());
            me->Relocate(GetAbsoluteTransportPosition(master));
            me->AddUnitState(UNIT_STATE_IGNORE_PATHFINDING);
        }
        else
        {
            Position destpos;
            _calculatePos(master, destpos);
            me->Relocate(destpos);
        }

        map->AddToMap(me);
        me->BotStopMovement();
        if (reset)
            this->Reset();
        //bot->SetAI(oldAI);
        //me->IsAIEnabled = true;
        canUpdate = true;
        outdoorsTimer = 0;

        //master->m_Controlled.insert(me);
        if (me->IsAlive())
        {
            CastSpellExtraArgs args(TRIGGERED_FULL_MASK);
            me->CastSpell(me, COSMETIC_TELEPORT_EFFECT, args);
        }
        //me->CastSpell(me, HONORLESS_TARGET, true);

        //update group member online state
        if (Group* gr = master->GetGroup())
            if (gr->IsMember(me->GetGUID()))
                gr->SendUpdate();

        //map hooks
        if (InstanceScript* iscr = master->GetInstanceScript())
            iscr->OnNPCBotEnter(me);

        SetIsDuringTeleport(false);
    });

    return true;
}

void bot_ai::AbortTeleport()
{
    if (teleHomeEvent)
    {
        if (teleHomeEvent->IsActive())
            teleHomeEvent->ScheduleAbort();
        teleHomeEvent = nullptr;
    }

    if (teleFinishEvent)
    {
        if (teleFinishEvent->IsActive())
            teleFinishEvent->ScheduleAbort();
        teleFinishEvent = nullptr;
    }
}

void bot_ai::GetHomePosition(uint16& mapid, Position* pos) const
{
    if (IsWanderer())
    {
        mapid = _travel_node_cur->GetMapId();
        pos->Relocate(homepos);
    }
    else
    {
        CreatureData const* data = me->GetCreatureData();
        mapid = data->mapId;
        pos->Relocate(data->spawnPoint);
    }
}

WanderNode const* bot_ai::GetNextTravelNode(Position const* from, bool random) const
{
    ASSERT(IsWanderer());

    int8 mylevelbonus = BotDataMgr::GetLevelBonusForBotRank(me->GetCreatureTemplate()->rank);
    uint8 mylevelbase = std::max<int8>(int8(me->GetLevel()) - mylevelbonus, int8(BotDataMgr::GetMinLevelForBotClass(_botclass)));

    if (!random)
    {
        if (WanderNode const* bgNode = GetNextBGTravelNode())
            return bgNode;
    }

    return BotDataMgr::GetNextWanderNode(_travel_node_cur, _travel_node_last, from, me, mylevelbase, random);
}

WanderNode const* bot_ai::GetNextBGTravelNode() const
{
    if (!me->GetMap()->IsBattleground() || !GetBG() || !GetGroup() || _travel_node_cur->GetLinks().size() <= 1)
        return nullptr;

    Battleground* bg = GetBG();
    switch (bg->GetTypeID())
    {
        case BATTLEGROUND_AV:
        {
            using NodeList = std::list<WanderNode const*>;

            constexpr uint32 CRETYPE_CAPTAIN_A = AV_CPLACE_MAX + 61;
            constexpr uint32 CRETYPE_CAPTAIN_H = AV_CPLACE_MAX + 59;
            constexpr uint32 CRETYPE_BOSS_A = AV_CPLACE_MAX + 60;
            constexpr uint32 CRETYPE_BOSS_H = AV_CPLACE_MAX + 122;

            static const std::function boss_room_wp_pred_a = [](WanderNode const* wp) { return wp->HasFlag(BotWPFlags::BOTWP_FLAG_ALLIANCE_BOSS_ROOM); };
            static const std::function boss_room_wp_pred_h = [](WanderNode const* wp) { return wp->HasFlag(BotWPFlags::BOTWP_FLAG_HORDE_BOSS_ROOM); };

            uint32 faction = me->GetFaction();
            TeamId myTeamId = bg->GetBotTeamId(me->GetGUID());
            std::vector<Unit*> const team_members = BotMgr::GetAllGroupMembers(me);
            uint32 myTeam = myTeamId == TEAM_ALLIANCE ? ALLIANCE : HORDE;
            WanderNode const* curNode = _travel_node_cur;
            NodeList links;
            for (WanderNode const* wp : curNode->GetLinks())
            {
                if (BotDataMgr::IsWanderNodeAvailableForBotFaction(wp, faction, false))
                    links.push_back(wp);
            }
            if (links.size() > 1 && _travel_node_last && !curNode->HasFlag(BotWPFlags::BOTWP_FLAG_CAN_BACKTRACK_FROM))
                links.remove(_travel_node_last);

            //if (links.size() == 1)
            //    return links.front();

            BattlegroundAV* av = dynamic_cast<BattlegroundAV*>(bg);
            // Above all: check conditions to rush final boss
            for (TeamId teamId : { TEAM_ALLIANCE, TEAM_HORDE })
            {
                if (myTeamId != teamId)
                    continue;

                //Condition 1: all bunkers/towers destroyed
                bool all_tb_down = true;
                for (BG_AV_Nodes counter = BG_AV_NODES_DUNBALDAR_SOUTH; counter <= BG_AV_NODES_FROSTWOLF_WTOWER; ++counter)
                {
                    BG_AV_NodeInfo const& c = av->GetNodes()[counter];
                    switch (counter)
                    {
                        case BG_AV_NODES_DUNBALDAR_SOUTH:
                        case BG_AV_NODES_DUNBALDAR_NORTH:
                        case BG_AV_NODES_ICEWING_BUNKER:
                        case BG_AV_NODES_STONEHEART_BUNKER:
                            if (teamId == TEAM_HORDE && c.State != BG_AV_States::POINT_DESTROYED)
                                all_tb_down = false;
                            break;
                        case BG_AV_NODES_ICEBLOOD_TOWER:
                        case BG_AV_NODES_TOWER_POINT:
                        case BG_AV_NODES_FROSTWOLF_ETOWER:
                        case BG_AV_NODES_FROSTWOLF_WTOWER:
                            if (teamId == TEAM_ALLIANCE && c.State != BG_AV_States::POINT_DESTROYED)
                                all_tb_down = false;
                            break;
                        default:
                            break;
                    }
                }
                if (all_tb_down)
                {
                    //Condition 2: boss node is in reach
                    auto const& pred = teamId == TEAM_ALLIANCE ? boss_room_wp_pred_h : boss_room_wp_pred_a;
                    Creature const* boss = ASSERT_NOTNULL(av->GetBGCreature(teamId == TEAM_ALLIANCE ? CRETYPE_BOSS_H : CRETYPE_BOSS_A));
                    WanderNode const* bossWP = ASSERT_NOTNULL(WanderNode::FindInAreaWPs(boss->GetAreaId(), pred));
                    if (curNode->HasLink(bossWP))
                    {
                        //Condition 3: team is ready OR boss is already engaged
                        bool team_ready = boss->IsInCombat();
                        if (!team_ready)
                        {
                            uint32 ready_count = 0;
                            for (Unit const* member : team_members)
                            {
                                if (!member->IsAlive())
                                    continue;
                                if (member->IsPlayer())
                                {
                                    if (member->IsWithinDist2d(me, 40.0f) || member->ToPlayer()->GetTarget() == boss->GetGUID())
                                        ++ready_count;
                                }
                                else if (member->ToCreature()->GetBotAI()->_travel_node_cur == bossWP || member->GetVictim() == boss ||
                                    (!member->GetVictim() && member->IsWithinDist2d(me, 30.0f)))
                                    ++ready_count;
                            }
                            team_ready = ready_count >= team_members.size() / 4u * 3u;
                        }
                        if (team_ready)
                            return bossWP;
                        else
                            return curNode;
                    }
                }
            }
            // Firstly: check a boss room to defend
            for (auto const& p : { std::pair{TEAM_ALLIANCE, CRETYPE_BOSS_A}, std::pair{TEAM_HORDE, CRETYPE_BOSS_H} })
            {
                if (myTeamId != p.first)
                    continue;
                Creature const* boss = ASSERT_NOTNULL(av->GetBGCreature(p.second));
                if (boss->IsInCombat())
                {
                    auto const& pred = p.first == TEAM_ALLIANCE ? boss_room_wp_pred_a : boss_room_wp_pred_h;
                    WanderNode const* bossWP = ASSERT_NOTNULL(WanderNode::FindInAreaWPs(boss->GetAreaId(), pred));
                    NodeList vlinks = curNode->GetShortestPathLinks(bossWP, links);
                    if (!vlinks.empty())
                        return vlinks.size() == 1u ? vlinks.front() : Trinity::Containers::SelectRandomContainerElement(vlinks);
                }
            }
            // Secondly: check captain room to defend
            for (auto const& p : { std::pair{TEAM_ALLIANCE, CRETYPE_CAPTAIN_A}, std::pair{TEAM_HORDE, CRETYPE_CAPTAIN_H} })
            {
                if (myTeamId != p.first)
                    continue;
                Creature const* captain = ASSERT_NOTNULL(av->GetBGCreature(p.second));
                if (captain->IsAlive() && captain->IsInCombat())
                {
                    WanderNode const* cap_node = nullptr;
                    float mindist = 50000.0f;
                    WanderNode::DoForAllAreaWPs(captain->GetAreaId(), [&cap_node, &mindist, fac = faction, pos = captain](WanderNode const* wp) {
                        float dist = pos->GetExactDist2d(wp);
                        if (dist < mindist && BotDataMgr::IsWanderNodeAvailableForBotFaction(wp, fac, false))
                        {
                            mindist = dist;
                            cap_node = wp;
                        }
                    });
                    if (cap_node && curNode->HasLink(cap_node))
                        return cap_node;
                }
            }
            // Thirdly: find next defend point
            // Fourthly: find a currently assaulted point by our team and make sure someone defends it
            // Ex. some GYs to base on are beyound directly accessible tower/bunker or captain room
            // Fithly: find a GY/tower/bunker in non-assaulted state in reach to assault
            for (TeamId teamId : { TEAM_ALLIANCE, TEAM_HORDE })
            {
                if (myTeamId != teamId)
                    continue;

                constexpr std::array<uint8, BG_AV_NODES_MAX> defend_priority_a{ 9, 7, 6, 3, 4, 2, 1, 8, 8, 5, 5, 0, 0, 0, 0 };
                constexpr std::array<uint8, BG_AV_NODES_MAX> defend_priority_h{ 1, 2, 4, 3, 6, 7, 9, 0, 0, 0, 0, 5, 5, 8, 8 };

                static const std::function flag_wp_pred = [](WanderNode const* wp) { return wp->HasFlag(BotWPFlags::BOTWP_FLAG_BG_FLAG_PICKUP_TARGET); };
                static const std::function bunker_wp_pred = [](WanderNode const* wp) { return wp->HasFlag(BotWPFlags::BOTWP_FLAG_BG_FLAG_PICKUP_TARGET) && wp->HasFlag(BotWPFlags::BOTWP_FLAG_ALLIANCE_ONLY); };
                static const std::function tower_wp_pred = [](WanderNode const* wp) { return wp->HasFlag(BotWPFlags::BOTWP_FLAG_BG_FLAG_PICKUP_TARGET) && wp->HasFlag(BotWPFlags::BOTWP_FLAG_HORDE_ONLY); };

                auto const& def_prio = teamId == TEAM_ALLIANCE ? defend_priority_a : defend_priority_h;
                auto const& defe_pred = teamId == TEAM_ALLIANCE ? bunker_wp_pred : tower_wp_pred;
                auto const& assa_pred = teamId == TEAM_ALLIANCE ? tower_wp_pred : bunker_wp_pred;

                std::pair<uint8, WanderNode const*> defNode{};
                NodeList assdlist;
                NodeList assalist;
                std::set<std::pair<uint8, BG_AV_NodeInfo const*>> defendable_nodes;
                std::set<std::pair<uint32, BG_AV_NodeInfo const*>> assaulted_nodes;
                std::set<std::pair<uint32, BG_AV_NodeInfo const*>> assaultable_nodes;
                NodeList accessible_nodes = links; //copy
                accessible_nodes.push_back(curNode);
                for (BG_AV_Nodes counter = BG_AV_NODES_FIRSTAID_STATION; counter < BG_AV_NODES_MAX; ++counter)
                {
                    BG_AV_NodeInfo const& c = av->GetNodes()[counter];
                    if (c.State == BG_AV_States::POINT_ASSAULTED)
                    {
                        if (c.Owner != myTeam && def_prio[counter] > 0)
                            defendable_nodes.insert({ uint8(counter), &c });
                        else if (c.Owner == myTeam)
                            assaulted_nodes.insert({ av->GetObjectThroughNodeForBot(counter), &c });
                    }
                    else if (c.State == BG_AV_States::POINT_NEUTRAL || (c.State == BG_AV_States::POINT_CONTROLED && c.Owner != myTeam))
                    {
                        if (c.Tower)
                            assaultable_nodes.insert({ av->GetObjectThroughNodeForBot(counter), &c });
                        else
                            assaultable_nodes.insert({ av->GetObjectThroughNodeForBot(counter), &c });
                    }
                    else if (counter == (teamId == TEAM_ALLIANCE ? BG_AV_NODES_FROSTWOLF_HUT : BG_AV_NODES_FIRSTAID_STATION))
                        assaultable_nodes.insert({ av->GetObjectThroughNodeForBot(counter), &c });
                }
                WanderNode::DoForAllMapWPs(av->GetMapId(), [&](WanderNode const* wp) {
                    if (defe_pred(wp))
                    {
                        for (auto const& vt : defendable_nodes)
                        {
                            if (defNode.second != nullptr && def_prio[vt.first] < def_prio[defNode.first])
                                continue;
                            uint32 objType = av->GetObjectThroughNodeForBot(BG_AV_Nodes(vt.first));
                            if (GameObject const* go = av->BgObjects[objType] ? av->GetBGObject(objType) : nullptr)
                            {
                                if (go->IsWithinDist2d(wp, INTERACTION_DISTANCE * 2.0f))
                                {
                                    defNode = { vt.first, wp };
                                    break;
                                }
                            }
                        }
                    }
                });
                if (WanderNode const* dnode = defNode.second)
                {
                    NodeList defLinks = curNode->GetShortestPathLinks(dnode, links);
                    if (!defLinks.empty())
                        return defLinks.size() == 1u ? defLinks.front() : Trinity::Containers::SelectRandomContainerElement(defLinks);
                }
                WanderNode::DoForContainerWPs(accessible_nodes, [&](WanderNode const* wp) {
                    if (flag_wp_pred(wp))
                    {
                        for (auto const& vt : assaulted_nodes)
                        {
                            uint32 defenders_count = 0;
                            for (Unit const* member : team_members)
                            {
                                if (member != me && member->IsAlive() && (member->GetExactDist2d(wp) < 40.0f ||
                                    (member->IsNPCBot() && member->ToCreature()->GetBotAI()->_travel_node_cur == wp)))
                                    ++defenders_count;
                            }
                            if (defenders_count >= 2)
                                continue;
                            if (GameObject const* go = av->BgObjects[vt.first] ? av->GetBGObject(vt.first) : nullptr)
                            {
                                if (go->IsWithinDist2d(wp, INTERACTION_DISTANCE * 2.0f))
                                {
                                    assdlist.push_back(wp);
                                    break;
                                }
                            }
                        }
                        if (assa_pred(wp))
                        {
                            for (auto const& vt : assaultable_nodes)
                            {
                                if (vt.first == BG_AV_OBJECT_FLAG_N_SNOWFALL_GRAVE)
                                {
                                    uint32 attackers_count = 0;
                                    for (Unit const* member : team_members)
                                        if (member != me && member->IsAlive() && member->IsNPCBot() && member->ToCreature()->GetBotAI()->_travel_node_cur == wp)
                                            ++attackers_count;
                                    if (attackers_count >= 3)
                                        continue;
                                }
                                if (GameObject const* go = av->BgObjects[vt.first] ? av->GetBGObject(vt.first) : nullptr)
                                {
                                    if (go->IsWithinDist2d(wp, INTERACTION_DISTANCE * 2.0f))
                                    {
                                        assalist.push_back(wp);
                                        break;
                                    }
                                }
                            }
                        }
                    }
                });
                if (!assdlist.empty())
                {
                    if (std::find(assdlist.cbegin(), assdlist.cend(), curNode) != assdlist.cend())
                        return curNode;
                    //remove non-empty points
                    assdlist.remove_if([&team_members, except_wp = curNode](WanderNode const* wp) {
                        if (wp != except_wp)
                        {
                            for (Unit const* member : team_members)
                            {
                                if (member->IsAlive() && (member->GetExactDist2d(wp) < 40.0f ||
                                    (member->IsNPCBot() && member->ToCreature()->GetBotAI()->_travel_node_cur == wp)))
                                    return true;
                            }
                        }
                        return false;
                    });
                }
                if (!assdlist.empty())
                    return assdlist.size() == 1u ? assdlist.front() : Trinity::Containers::SelectRandomContainerElement(assdlist);
                if (!assalist.empty())
                    return assalist.size() == 1u ? assalist.front() : Trinity::Containers::SelectRandomContainerElement(assalist);
            }
            //Last thing: try to capture the mines (2 people at most)
            for (auto const& p : { std::pair{TEAM_ALLIANCE, std::array{AV_CPLACE_MINE_N_3, AV_CPLACE_MINE_S_3}}, std::pair{TEAM_HORDE, std::array{AV_CPLACE_MINE_S_3, AV_CPLACE_MINE_N_3}} })
            {
                if (myTeamId != p.first)
                    continue;

                static const std::function mine_pred = [](WanderNode const* wp) { return wp->HasFlag(BotWPFlags::BOTWP_FLAG_BG_MISC_OBJECTIVE_1); };

                for (BG_AV_CreaturePlace sptype : p.second)
                {
                    Creature const* mboss = ASSERT_NOTNULL(av->GetBGCreature(uint32(sptype)));
                    if (mboss->IsAlive() && !mboss->IsInCombat() && me->IsWithinDist2d(mboss, SIZE_OF_GRIDS * 0.75f))
                    {
                        WanderNode const* mineWP = ASSERT_NOTNULL(WanderNode::FindInMapWPs(mboss->GetMapId(), mine_pred));
                        WanderNode const* mineLink = mineWP->GetLinks().front();
                        NodeList mlinks = curNode->GetShortestPathLinks(mineWP, links);
                        if (!mlinks.empty())
                        {
                            uint32 attackers_count = 0;
                            for (Unit const* member : team_members)
                            {
                                if (member == me || !member->IsAlive() || !member->IsNPCBot())
                                    continue;
                                WanderNode const* mwp = member->ToCreature()->GetBotAI()->_travel_node_cur;
                                if (!mwp)
                                    continue;
                                if (mwp == mineWP || mwp == mineLink || member->GetVictim() == mboss ||
                                    std::find(mlinks.cbegin(), mlinks.cend(), mwp) != mlinks.cend() ||
                                    (!mwp->GetLinks().empty() && std::find(mwp->GetLinks().cbegin(), mwp->GetLinks().cend(), mineLink) != mwp->GetLinks().cend()))
                                    ++attackers_count;
                            }
                            if (attackers_count <= 1)
                            {
                                TC_LOG_DEBUG("npcbots", "Bot {} {} team {} goes for a mine! Cur node: {} {}",
                                    me->GetName(), me->GetEntry(), uint32(myTeamId), curNode->GetWPId(), curNode->GetName());
                                return mlinks.size() == 1u ? mlinks.front() : Trinity::Containers::SelectRandomContainerElement(mlinks);
                            }
                        }
                    }
                }
            }
            //No immediate target: rush enemy captain
            for (TeamId teamId : { TEAM_ALLIANCE, TEAM_HORDE })
            {
                if (myTeamId != teamId)
                    continue;
                Creature const* captain = av->GetBGCreature(teamId == TEAM_ALLIANCE ? CRETYPE_CAPTAIN_H : CRETYPE_CAPTAIN_A);
                if (captain && captain->IsAlive())
                {
                    WanderNode const* cap_node = nullptr;
                    float mindist = 50000.0f;
                    WanderNode::DoForAllAreaWPs(captain->GetAreaId(), [&cap_node, &mindist, fac = faction, pos = captain](WanderNode const* wp) {
                        float dist = pos->GetExactDist2d(wp);
                        if (dist < mindist && BotDataMgr::IsWanderNodeAvailableForBotFaction(wp, fac, false))
                        {
                            mindist = dist;
                            cap_node = wp;
                        }
                    });
                    if (cap_node && curNode->HasLink(cap_node))
                        return cap_node;
                }
            }
            //No immediate target: find a point next to enemy boss and try going there
            for (TeamId teamId : { TEAM_ALLIANCE, TEAM_HORDE })
            {
                if (myTeamId != teamId)
                    continue;
                if (Creature const* boss = av->GetBGCreature(teamId == TEAM_ALLIANCE ? CRETYPE_BOSS_H : CRETYPE_BOSS_A))
                {
                    auto const& pred = teamId == TEAM_ALLIANCE ? boss_room_wp_pred_h : boss_room_wp_pred_a;
                    WanderNode const* bossWP = ASSERT_NOTNULL(WanderNode::FindInAreaWPs(boss->GetAreaId(), pred));
                    NodeList vlinks = curNode->GetShortestPathLinks(bossWP->GetLinks().front(), links);
                    if (!vlinks.empty())
                        return vlinks.size() == 1u ? vlinks.front() : Trinity::Containers::SelectRandomContainerElement(vlinks);
                }
            }

            if (links.size() > 1)
            {
                TC_LOG_DEBUG("npcbots", "Bot {} {} team {} has no target point in BG_AV! Falling back to random ({} links)!. Cur node: {} {}",
                    me->GetName(), me->GetEntry(), uint32(myTeamId), uint32(curNode->GetLinks().size()), curNode->GetWPId(), curNode->GetName());
            }

            break;
        }
        case BATTLEGROUND_WS:
        case BATTLEGROUND_AB:
        default:
            break;
    }

    return nullptr;
}

void bot_ai::OnWanderNodeReached()
{
    ASSERT(me->IsInWorld());
    ASSERT(_travel_node_cur != nullptr, "%s", me->GetGUID().ToString().c_str());

    if (Battleground* bg = GetBG())
    {
        if (_travel_node_cur->HasFlag(BotWPFlags::BOTWP_FLAG_BG_FLAG_DELIVER_TARGET) && IsFlagCarrier(me, bg->GetTypeID()))
        {
            switch (bg->GetTypeID())
            {
                case BATTLEGROUND_WS:
                    if (bg->GetBotTeamId(me->GetGUID()) == TEAM_ALLIANCE && _travel_node_cur->HasFlag(BotWPFlags::BOTWP_FLAG_ALLIANCE_ONLY))
                        bg->HandleBotAreaTrigger(me, 3646);
                    if (bg->GetBotTeamId(me->GetGUID()) == TEAM_HORDE && _travel_node_cur->HasFlag(BotWPFlags::BOTWP_FLAG_HORDE_ONLY))
                        bg->HandleBotAreaTrigger(me, 3647);
                    break;
                default:
                    break;
            }
        }
        if (_travel_node_cur->HasFlag(BotWPFlags::BOTWP_FLAG_BG_FLAG_PICKUP_TARGET) && !IsFlagCarrier(me, bg->GetTypeID()))
        {
            switch (bg->GetTypeID())
            {
                case BATTLEGROUND_AV:
                {
                    static const uint32 SPELL_OPENING_FLAG = 21651u;

                    GameObject* obj = nullptr;

                    BattlegroundAV* av = dynamic_cast<BattlegroundAV*>(bg);
                    for (BG_AV_Nodes counter = BG_AV_NODES_FIRSTAID_STATION; counter < BG_AV_NODES_MAX; ++counter)
                    {
                        BG_AV_NodeInfo const& c = av->GetNodes()[counter];
                        if (c.State == BG_AV_States::POINT_DESTROYED)
                            continue;
                        if (c.State == BG_AV_States::POINT_NEUTRAL || c.Owner != bg->GetBotTeam(me->GetGUID()))
                        {
                            uint32 node_type = av->GetObjectThroughNodeForBot(counter);
                            GameObject* go = bg->BgObjects[node_type] ? bg->GetBGObject(node_type) : nullptr;
                            if (go && me->IsWithinDistInMap(go, 10.0f))
                            {
                                obj = go;
                                break;
                            }
                        }
                    }

                    if (!obj)
                        break;

                    bool already_used = false;
                    for (Unit const* member : BotMgr::GetAllGroupMembers(me))
                    {
                        if (member->GetGUID() == me->GetGUID())
                            continue;
                        if (Spell const* curSpell = member->GetCurrentSpell(CURRENT_GENERIC_SPELL))
                        {
                            if (curSpell->m_spellInfo->Id == SPELL_OPENING_FLAG && curSpell->m_targets.GetGOTargetGUID() == obj->GetGUID())
                            {
                                already_used = true;
                                break;
                            }
                        }
                    }
                    if (already_used)
                        break;

                    //TC_LOG_ERROR("npcbots", "OnWanderNodeReached: [AV] Bot {} USES flag {} at node {}", me->GetName(), obj->GetName(), node);

                    if (me->IsMounted())
                        DismountBot();
                    me->CastSpell(obj, SPELL_OPENING_FLAG);

                    break;
                }
                case BATTLEGROUND_WS:
                {
                    if (bg->GetBotTeamId(me->GetGUID()) == TEAM_ALLIANCE && _travel_node_cur->HasFlag(BotWPFlags::BOTWP_FLAG_HORDE_ONLY))
                    {
                        if (GameObject* go = bg->GetBGObject(BG_WS_OBJECT_H_FLAG, true))
                        {
                            //TC_LOG_ERROR("npcbots", "OnWanderNodeReached: [WSG] Horde flag dist: {}", me->GetExactDist(go));
                            if (me->IsMounted())
                                DismountBot();
                            bg->EventBotClickedOnFlag(me, go);
                        }
                    }
                    if (bg->GetBotTeamId(me->GetGUID()) == TEAM_HORDE && _travel_node_cur->HasFlag(BotWPFlags::BOTWP_FLAG_ALLIANCE_ONLY))
                    {
                        if (GameObject* go = bg->GetBGObject(BG_WS_OBJECT_A_FLAG, true))
                        {
                            //TC_LOG_ERROR("npcbots", "OnWanderNodeReached: [WSG] Alliance flag dist: {}", me->GetExactDist(go));
                            if (me->IsMounted())
                                DismountBot();
                            bg->EventBotClickedOnFlag(me, go);
                        }
                    }
                    break;
                }
                case BATTLEGROUND_AB:
                {
                    static const uint32 SPELL_OPENING_FLAG = 21651u;

                    uint8 node = BG_AB_NODE_STABLES;
                    GameObject* obj = bg->GetBGObject(node*8+BG_AB_OBJECT_BANNER_NEUTRAL);
                    while (node < BG_AB_DYNAMIC_NODES_COUNT && (!obj || !me->IsWithinDistInMap(obj, 10.0f)))
                    {
                        ++node;
                        obj = bg->GetBGObject(node*8+BG_AB_OBJECT_BANNER_NEUTRAL);
                    }
                    if (node < BG_AB_DYNAMIC_NODES_COUNT)
                    {
                        TeamId teamId = bg->GetBotTeamId(me->GetGUID());
                        BattlegroundAB const* bgab = dynamic_cast<BattlegroundAB const*>(bg);

                        if (bgab->IsNodeOccupied(node, teamId) || bgab->IsNodeContested(node, teamId))
                            break;

                        //at this point node is either neutral or owned/contested by other team
                        uint8 new_bg_obj_type;
                        if (bgab->IsNodeOccupied(node, bg->GetOtherTeamId(teamId)))
                            new_bg_obj_type = BG_AB_OBJECT_BANNER_HORDE;
                        else if (bgab->IsNodeContested(node, bg->GetOtherTeamId(teamId)))
                            new_bg_obj_type = BG_AB_OBJECT_BANNER_CONT_H;
                        else
                            new_bg_obj_type = BG_AB_OBJECT_BANNER_NEUTRAL;

                        obj = bg->GetBGObject(node*8+new_bg_obj_type);
                        ASSERT(obj != nullptr);

                        bool already_used = false;
                        for (Unit const* member : BotMgr::GetAllGroupMembers(me))
                        {
                            if (member->GetGUID() == me->GetGUID())
                                continue;
                            if (Spell const* curSpell = member->GetCurrentSpell(CURRENT_GENERIC_SPELL))
                            {
                                if (curSpell->m_spellInfo->Id == SPELL_OPENING_FLAG && curSpell->m_targets.GetGOTargetGUID() == obj->GetGUID())
                                {
                                    already_used = true;
                                    break;
                                }
                            }
                        }
                        if (already_used)
                            break;

                        //TC_LOG_ERROR("npcbots", "OnWanderNodeReached: [AB] Bot {} USES flag {} at node {}",
                        //    me->GetName(), obj->GetName(), uint32(node));
                        if (me->IsMounted())
                            DismountBot();
                        me->CastSpell(obj, SPELL_OPENING_FLAG);
                    }
                    break;
                }
                default:
                    break;
            }
        }
    }
}

void bot_ai::OnBotEnterBattleground()
{
    Battleground* bg = ASSERT_NOTNULL(GetBG());

    if (bg->GetStatus() != STATUS_IN_PROGRESS && IsWanderer())
    {
        uint32 mapId = bg->GetBgMap()->GetId();
        float mindist = 50000.0f;
        WanderNode const* startNode = nullptr;
        WanderNode::DoForAllMapWPs(mapId, [pos = me->GetPosition(), &mindist, &startNode](WanderNode const* wp) {
            if (wp->HasFlag(BotWPFlags::BOTWP_FLAG_SPAWN))
            {
                float dist = pos.GetExactDist2d(wp);
                if (dist < mindist)
                {
                    startNode = wp;
                    mindist = dist;
                }
            }
        });

        SetBotCommandState(BOT_COMMAND_STAY);
        if (startNode)
        {
            if (TempSummon* wpc = me->GetMap()->SummonCreature(VISUAL_WAYPOINT, *startNode, nullptr, 1000))
            {
                wpc->SetTempSummonType(TEMPSUMMON_TIMED_DESPAWN);
                float angle = bg->GetTypeID() == BATTLEGROUND_WS ? frand(float(M_PI * 0.75), float(M_PI * 1.25)) : frand(0.001f, float(M_PI * 1.995));
                Position myStartPos = wpc->GetFirstCollisionPosition(frand(5.0f, 20.0f), angle);
                BotMovement(BOT_MOVE_POINT, &myStartPos);
            }
        }
    }
}

void bot_ai::SetWanderer()
{
    if (IAmFree())
    {
        _wanderer = true;
        if (botPet)
            botPet->GetBotPetAI()->SetWanderer();
    }
}

void bot_ai::KillEvents(bool force)
{
    Events.KillAllEvents(force);
}

void bot_ai::OnBotEnterVehicle(Vehicle const* vehicle)
{
    if (VehicleSeatEntry const* seat = vehicle->GetSeatForPassenger(me))
    {
        if (seat->Flags & VEHICLE_SEAT_FLAG_CAN_CONTROL)
        {
            vehicle->GetBase()->SetFaction(master->GetFaction());
            //vehicle->GetBase()->SetOwnerGUID(master->GetGUID());
            vehicle->GetBase()->SetCreator(master);
            vehicle->GetBase()->SetUnitFlag(UNIT_FLAG_POSSESSED);
            vehicle->GetBase()->SetUnitFlag(UNIT_FLAG_PLAYER_CONTROLLED);
            vehicle->GetBase()->SetByteValue(UNIT_FIELD_BYTES_2, 1, master->GetByteValue(UNIT_FIELD_BYTES_2, 1));
            ASSERT(vehicle->GetBase()->SetCharmedBy(me, CHARM_TYPE_VEHICLE));
            vehicle->GetBase()->SetControlledByPlayer(true);

            vehcomboPoints = 0;
            //flight mode
            switch (vehicle->GetBase()->GetEntry())
            {
                case CREATURE_NEXUS_SKYTALON_1:
                case CREATURE_EOE_SKYTALON_N:
                case CREATURE_EOE_SKYTALON_H:
                case CREATURE_OCULUS_DRAKE_RUBY:
                case CREATURE_OCULUS_DRAKE_EMERALD:
                case CREATURE_OCULUS_DRAKE_AMBER:
                    UnsummonAll(false);
                    vehicle->GetBase()->SetCanFly(true);
                    vehicle->GetBase()->SetDisableGravity(true);
                    break;
                default:
                    break;
            }
        }

        if (Unit* oVeh = master->GetVehicleBase())
        {
            CreatureTemplate const* vehTemplate = vehicle->GetBase()->GetTypeId() == TYPEID_UNIT ? vehicle->GetBase()->ToCreature()->GetCreatureTemplate() : nullptr;
            ////Set hp and mana percent to avoid abuse
            //vehicle->GetBase()->SetHealth(vehicle->GetBase()->GetMaxHealth() * oVeh->GetHealthPct() / 100.f + 0.5f);
            //if (oVeh->GetPowerType() == POWER_MANA)
            //{
            //    float mpPct = oVeh->GetPower(POWER_MANA) * 100.f / oVeh->GetMaxPower(POWER_MANA);
            //    vehicle->GetBase()->SetPower(POWER_MANA, vehicle->GetBase()->GetMaxPower(POWER_MANA) * mpPct / 100.f + 0.5f);
            //}
            //speed
            if (vehTemplate &&
                (vehTemplate->Movement.Flight == CreatureFlightMovementType::CanFly ||
                vehTemplate->Movement.Flight == CreatureFlightMovementType::DisableGravity))
            {
                //hack to use vehicle speed
                vehicle->GetBase()->RemoveAurasByType(SPELL_AURA_MOD_INCREASE_VEHICLE_FLIGHT_SPEED);
                vehicle->GetBase()->RemoveAurasByType(SPELL_AURA_MOD_VEHICLE_SPEED_ALWAYS);
                vehicle->GetBase()->RemoveAurasByType(SPELL_AURA_MOD_FLIGHT_SPEED_NOT_STACK);
                vehicle->GetBase()->RemoveAurasByType(SPELL_AURA_MOD_MOUNTED_SPEED_NOT_STACK);
                vehicle->GetBase()->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_INCREASE_VEHICLE_FLIGHT_SPEED, true);
                vehicle->GetBase()->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_VEHICLE_SPEED_ALWAYS, true);
                vehicle->GetBase()->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_FLIGHT_SPEED_NOT_STACK, true);
                vehicle->GetBase()->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_MOUNTED_SPEED_NOT_STACK, true);
                vehicle->GetBase()->SetSpeedRate(MOVE_FLIGHT, oVeh->GetSpeedRate(MOVE_FLIGHT) * 1.17f);
                vehicle->GetBase()->SetSpeedRate(MOVE_RUN, oVeh->GetSpeedRate(MOVE_FLIGHT) * 1.17f);
                vehicle->GetBase()->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_DECREASE_SPEED, true);
                vehicle->GetBase()->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_SPEED_SLOW_ALL, true);
            }
        }
    }
}

void bot_ai::OnBotExitVehicle(Vehicle const* vehicle)
{
    if (VehicleSeatEntry const* seat = vehicle->GetSeatForPassenger(me))
    {
        if (seat->Flags & VEHICLE_SEAT_FLAG_CAN_CONTROL)
        {
            vehicle->GetBase()->SetControlledByPlayer(false);
            vehicle->GetBase()->RemoveCharmedBy(me);
            vehicle->GetBase()->RestoreFaction();
            //vehicle->GetBase()->SetOwnerGUID(ObjectGuid::Empty);
            vehicle->GetBase()->SetCreator(nullptr);
            vehicle->GetBase()->RemoveUnitFlag(UNIT_FLAG_PLAYER_CONTROLLED);
            if (vehicle->GetBase()->GetTypeId() == TYPEID_UNIT)
                vehicle->GetBase()->RemoveUnitFlag(UNIT_FLAG_POSSESSED);
            vehicle->GetBase()->SetByteValue(UNIT_FIELD_BYTES_2, 1, 0);

            curVehStrat = BOT_VEH_STRAT_NONE;
            if (vehicle->GetBase()->IsSummon())
                vehicle->GetBase()->ToCreature()->DespawnOrUnsummon(1ms);
        }
    }
}

void bot_ai::AfterBotOwnerEnterVehicle()
{
    if (!me->GetVehicle() && master->GetVehicleCreatureBase() && master->GetVehicleCreatureBase()->m_spells[0] &&
        master->GetVehicleBase()->IsControlledByPlayer())
    {
        VehicleSeatEntry const* seat = master->GetVehicle()->GetSeatForPassenger(master);
        if (seat && seat->CanEnterOrExit())
        {
            uint32 creEntry = 0;
            uint32 vehEntry;

            ChooseVehicleForEncounter(creEntry, vehEntry);
            if (!creEntry)
            {
                TC_LOG_DEBUG("scripts", "OnBotOwnerEnterVehicle: no vehicle selected for bot master veh {}!",
                    master->GetVehicleCreatureBase()->GetName());
                return;
            }
            Unit* veh = SpawnVehicle(creEntry, vehEntry);
            ASSERT(veh);

            removeShapeshiftForm();
            //me->BotStopMovement();

            //DO NOT use spellclick here, this is undefined behaviour if target selection is not explicit
            //veh->HandleSpellClick(me);
            switch (creEntry) //select vehicle ride spell
            {
                //TODO
            case CREATURE_EOE_SKYTALON_N:
            case CREATURE_EOE_SKYTALON_H:
                me->CastSpell(veh, 56071); //Ride Red Dragon Buddy
                break;
            case CREATURE_OCULUS_DRAKE_RUBY:
            case CREATURE_OCULUS_DRAKE_EMERALD:
            case CREATURE_OCULUS_DRAKE_AMBER:
            {
                me->EnterVehicle(veh); //cannot cast ride spell (49464, 49346, 49460) due to targeting (TARGET_UNIT_NEARBY_ENTRY)
                CastSpellExtraArgs args(true);
                args.SetOriginalCaster(me->GetGUID());
                veh->CastSpell(veh, 66667, args); //Gear Scaling
                break;
            }
            //case CREATURE_TOC_STEED_QUELDOREI:
            //case CREATURE_TOC_NIGHTSABER:
            //case CREATURE_TOC_STEED_STORMWIND:
            //case CREATURE_TOC_MECHANOSTRIDER:
            //case CREATURE_TOC_RAM:
            //case CREATURE_TOC_ELEKK:
            //case CREATURE_TOC_HAWKSTRIDER_SUNREAVER:
            //case CREATURE_TOC_RAPTOR:
            //case CREATURE_TOC_WARHORSE:
            //case CREATURE_TOC_WOLF:
            //case CREATURE_TOC_HAWKSTRIDER_SILVERMOON:
            //case CREATURE_TOC_KODO:
            //    me->CastSpell(veh, 63151); //Ride Vehicle
            //    break;
            case CREATURE_TOC5_WARHORSE:
            case CREATURE_TOC5_BATTLEWORG:
                me->CastSpell(veh, 67830); //Ride Vehicle
                break;
            default:
                me->EnterVehicle(veh);
                break;
            }
            return;
        }
    }

    //TC_LOG_ERROR("scripts", "OnBotOwnerEnterVehicle: master not in vehicle or no veh found for bot {}!", me->GetName());
}

void bot_ai::OnBotOwnerEnterVehicle(Vehicle const* /*vehicle*/)
{
    shouldEnterVehicle = true;
}

void bot_ai::OnBotOwnerExitVehicle(Vehicle const* /*vehicle*/)
{
    shouldEnterVehicle = false;
    if (me->GetVehicle())
    {
        if (me->GetMapId() == 631) // Icecrown Citadel
        {
            me->ExitVehicle();
            me->BotStopMovement();
        }
    }
}

Unit* bot_ai::SpawnVehicle(uint32 creEntry, uint32 vehEntry)
{
    ASSERT(sObjectMgr->GetCreatureTemplate(creEntry));
    if (vehEntry != 0)
        ASSERT(sVehicleStore.LookupEntry(vehEntry));

    Map* map = me->GetMap();
    float x, y, z, o;
    TempSummon* vc;
    if (!me->GetTransport())
    {
        o = master->GetOrientation();
        me->GetClosePoint(x, y, z, me->GetCombatReach());
        vc = new TempSummon(nullptr, me, false);
        ASSERT(vc->Create(map->GenerateLowGuid<HighGuid::Unit>(), map, master->GetPhaseMask(), creEntry, Position(x,y,z,o), nullptr, vehEntry, true));
        vc->SetTempSummonType(TEMPSUMMON_CORPSE_DESPAWN);
        vc->InitStats(0);
        ASSERT(map->AddToMap(vc->ToCreature()));
        vc->InitSummon(); //not needed really
    }
    else
    {
        if (master->GetVehicle())
            o = master->GetVehicleBase()->GetTransOffsetO();
        else
            o = master->GetTransOffsetO();
        x = me->GetTransOffsetX();
        y = me->GetTransOffsetY();
        z = me->GetTransOffsetZ();
        Position vehpos(x, y, z, o);
        me->GetTransport()->CalculatePassengerPosition(x, y, z, &o);
        vc = new TempSummon(nullptr, me, false);
        ASSERT(vc->Create(map->GenerateLowGuid<HighGuid::Unit>(), map, master->GetPhaseMask(), creEntry, Position(x,y,z,o), nullptr, vehEntry, true));

        //vc->SetTransport(me->GetTransport());
        //vc->AddUnitMovementFlag(MOVEMENTFLAG_ONTRANSPORT);
        //vc->m_movementInfo.transport.guid = GetGUID();
        me->GetTransport()->AddPassenger(vc);

        vc->m_movementInfo.transport.pos.Relocate(vehpos);
        vc->Relocate(x, y, z, o);
        vc->SetHomePosition(x, y, z, o);
        vc->SetTransportHomePosition(vehpos);

        vc->AddUnitState(UNIT_STATE_IGNORE_PATHFINDING);
        vc->InitStats(0);
        ASSERT(map->AddToMap(vc->ToCreature()));
        vc->InitSummon(); //not needed really
        vc->SetTempSummonType(TEMPSUMMON_CORPSE_DESPAWN);
        //vc = me->GetTransport()->SummonPassenger(creEntry, vehpos, TEMPSUMMON_CORPSE_DESPAWN);
    }

    return vc;
}

void bot_ai::ChooseVehicleForEncounter(uint32 &creEntry, uint32 &vehEntry) const
{
    Vehicle* mVeh = master->GetVehicle();
    ASSERT_NODEBUGINFO(mVeh);
    ASSERT_NODEBUGINFO(mVeh->GetBase()->GetTypeId() == TYPEID_UNIT);

    vehEntry = 0; // will be chosen at creature spawn
    switch (mVeh->GetBase()->GetEntry())
    {
        //TODO
        case CREATURE_NEXUS_SKYTALON_1:
        case CREATURE_EOE_SKYTALON_N:
        case CREATURE_EOE_SKYTALON_H:
        case CREATURE_ULDUAR_DEMOLISHER:
        case CREATURE_ULDUAR_SIEGE_ENGINE:
        case CREATURE_ULDUAR_CHOPPER:
        case CREATURE_ULDUAR_CHOPPER1:
        //case CREATURE_TOC_STEED_QUELDOREI:
        //case CREATURE_TOC_HAWKSTRIDER_SUNREAVER:
        case CREATURE_TOC5_WARHORSE:
        case CREATURE_TOC5_BATTLEWORG:
            creEntry = mVeh->GetBase()->GetEntry();
            break;
        case CREATURE_OCULUS_DRAKE_RUBY:
        case CREATURE_OCULUS_DRAKE_EMERALD:
        case CREATURE_OCULUS_DRAKE_AMBER:
            creEntry = (HasRole(BOT_ROLE_TANK)/* && mVeh->GetBase()->GetEntry() != CREATURE_OCULUS_DRAKE_RUBY*/) ? CREATURE_OCULUS_DRAKE_RUBY :
                (HasRole(BOT_ROLE_HEAL)/* && mVeh->GetBase()->GetEntry() != CREATURE_OCULUS_DRAKE_EMERALD*/) ? CREATURE_OCULUS_DRAKE_EMERALD :
                CREATURE_OCULUS_DRAKE_AMBER;
            break;
        //case CREATURE_TOC_NIGHTSABER:
        //case CREATURE_TOC_STEED_STORMWIND:
        //case CREATURE_TOC_MECHANOSTRIDER:
        //case CREATURE_TOC_RAM:
        //case CREATURE_TOC_ELEKK:
        //case CREATURE_TOC_RAPTOR:
        //case CREATURE_TOC_WARHORSE:
        //case CREATURE_TOC_WOLF:
        //case CREATURE_TOC_HAWKSTRIDER_SILVERMOON:
        //case CREATURE_TOC_KODO:
        //    switch (GetPlayerRace())
        //    {
        //        case RACE_HUMAN:         creEntry = CREATURE_TOC_STEED_STORMWIND;        break;
        //        case RACE_ORC:           creEntry = CREATURE_TOC_WOLF;                   break;
        //        case RACE_DWARF:         creEntry = CREATURE_TOC_RAM;                    break;
        //        case RACE_NIGHTELF:      creEntry = CREATURE_TOC_NIGHTSABER;             break;
        //        case RACE_UNDEAD_PLAYER: creEntry = CREATURE_TOC_WARHORSE;               break;
        //        case RACE_TAUREN:        creEntry = CREATURE_TOC_KODO;                   break;
        //        case RACE_GNOME:         creEntry = CREATURE_TOC_MECHANOSTRIDER;         break;
        //        case RACE_TROLL:         creEntry = CREATURE_TOC_RAPTOR;                 break;
        //        case RACE_BLOODELF:      creEntry = CREATURE_TOC_HAWKSTRIDER_SILVERMOON; break;
        //        case RACE_DRAENEI:       creEntry = CREATURE_TOC_ELEKK;                  break;
        //        default:                 creEntry = CREATURE_TOC_STEED_QUELDOREI;        break;
        //    }
        //    break;
        case CREATURE_ICC_GUNSHIPCANNON_ALLIANCE:
        case CREATURE_ICC_GUNSHIPCANNON_HORDE:
            //limited amount of cannons
            if (!IsTank() && HasRole(BOT_ROLE_DPS) &&
                master->GetBotMgr()->GetNpcBotsCountByVehicleEntry(mVeh->GetBase()->GetEntry()) <
                std::max<uint8>(master->GetBotMgr()->GetNpcBotsCount() / 2, 8))
                creEntry = mVeh->GetBase()->GetEntry();
            break;
        case CREATURE_ICC_MUTATED_ABOMINATION1:
        case CREATURE_ICC_MUTATED_ABOMINATION2:
        case CREATURE_ICC_MUTATED_ABOMINATION3:
        case CREATURE_ICC_MUTATED_ABOMINATION4:
        case CREATURE_ICC_MUTATED_ABOMINATION5:
        case CREATURE_ICC_MUTATED_ABOMINATION6:
        case CREATURE_ICC_MUTATED_ABOMINATION7:
        case CREATURE_ICC_MUTATED_ABOMINATION8:
            //no abomination bots
            break;
        default:
            if (VehicleSeatEntry const* seat = mVeh->GetSeatForPassenger(master))
            {
                if (seat->Flags & VEHICLE_SEAT_FLAG_CAN_CONTROL)
                {
                    //can use generic strat for that
                    creEntry = mVeh->GetBase()->GetEntry();
                    break;
                }
            }

            TC_LOG_ERROR("scripts", "ChooseVehicleForEncounter: unhandled master vehicle creature {} ({})",
                master->GetVehicleBase()->GetName(), master->GetVehicleBase()->GetEntry());
            return;
    }

    if (creEntry && creEntry != mVeh->GetBase()->GetEntry())
    {
        CreatureTemplate const* cProto = sObjectMgr->GetCreatureTemplate(creEntry);
        ASSERT_NODEBUGINFO(cProto);
        vehEntry = cProto->VehicleId;
        ASSERT_NODEBUGINFO(sVehicleStore.LookupEntry(vehEntry));
    }
}

Position bot_ai::GetAbsoluteTransportPosition(WorldObject const* object)
{
    if (!object->GetTransport())
        return object->GetPosition();

    Position p = object->GetTransport()->GetPosition();
    Position t = object->GetTransOffset();
    t.m_positionX += p.m_positionX;
    t.m_positionY += p.m_positionY;
    t.m_positionZ += p.m_positionZ;
    t.SetOrientation(Position::NormalizeOrientation(t.GetOrientation() + p.GetOrientation()));

    return t;
}

int32 bot_ai::GetBotResistanceBonus(SpellSchoolMask mask) const
{
    int32 resist = 0;
    for (uint8 i = SPELL_SCHOOL_HOLY; i != MAX_SPELL_SCHOOL; ++i)
        if ((mask & (1 << i)) && (resist == 0 || resist > resistbonus[i-1]))
            resist = resistbonus[i-1];

    return resist;
}

MeleeHitOutcome bot_ai::BotRollCustomMeleeOutcomeAgainst(Unit const* victim, WeaponAttackType attType) const
{
    if (GetNextAttackMeleeOutCome() != MELEE_HIT_CRUSHING)
        return GetNextAttackMeleeOutCome();
    return me->RollMeleeOutcomeAgainst(victim, attType);
}

void bot_ai::BotJumpInPlaceInFrontOf(Position const* pos, float speedXY, float maxHeight)
{
    float sign = (me->GetPositionX() < pos->GetPositionX()) ? 1.f : -1.f;
    float x = me->GetPositionX() + 0.14f * sign;
    sign = (me->GetPositionY() < pos->GetPositionY()) ? 1.f : -1.f;
    float y = me->GetPositionY() + 0.14f * sign;
    float z = me->GetPositionZ() - 0.01f;
    //float floorz = Map::GetHeight(x, y, z, true, 5.f);
    speedXY = std::max<float>(speedXY, speedXY / me->m_modAttackSpeedPct[BASE_ATTACK]);

    //me->AttackStop();
    //me->BotStopMovement();
    me->GetMotionMaster()->MoveJump(x, y, z, me->GetOrientation(), speedXY, maxHeight);
}

void bot_ai::DismountBot()
{
    const_cast<CreatureTemplate*>(me->GetCreatureTemplate())->Movement.Flight = CreatureFlightMovementType::None;
    me->SetCanFly(false);
    me->m_movementInfo.RemoveMovementFlag(MOVEMENTFLAG_HOVER | MOVEMENTFLAG_CAN_FLY);
    me->SetDisableGravity(false);
    me->RemoveAurasByType(SPELL_AURA_MOUNTED);
    me->Dismount();
    me->BotStopMovement();
}

//DPS TRACKER
uint32 bot_ai::GetDPSTaken(Unit const* u) const
{
    return IAmFree() ? 0 : master->GetBotMgr()->GetDPSTaken(u);
}
int32 bot_ai::GetHPSTaken(Unit const* u) const
{
    return IAmFree() ? 0 : master->GetBotMgr()->GetHPSTaken(u);
}
//Health per second
int32 bot_ai::GetHPS(Unit const* u) const
{
    return IAmFree() ? 0 : GetHPSTaken(u) - GetDPSTaken(u);
}
//Health percent per second
int32 bot_ai::GetHPPCTPS(Unit const* u) const
{
    return int32(GetHPS(u) * 100.f / float(u->GetMaxHealth()));
}
//%health unit is going to have after x ms
//0-100
uint8 bot_ai::GetExpectedHPPCT(Unit const* u, uint32 mseconds) const
{
    if (IAmFree())
        return GetHealthPCT(u);

    int32 pct = int32(GetHealthPCT(u)) + int32(GetHPPCTPS(u) * (mseconds * 0.001f));

    if (pct > 100)
        pct = 100;
    else if (pct < 0)
        pct = 0;

    return uint8(pct);
}

//Moved from header
bool bot_ai::IsChanneling(Unit const* u/* = nullptr*/) const
{
    if (!u)
        u = me;
    return u->GetCurrentSpell(CURRENT_CHANNELED_SPELL);
}
bool bot_ai::IsCasting(Unit const* u/* = nullptr*/) const
{
    if (!u)
        u = me;
    return (u->HasUnitState(UNIT_STATE_CASTING) || IsChanneling(u) || u->IsNonMeleeSpellCast(false, false, true, false, false));
}
bool bot_ai::JumpingFlyingOrFalling() const
{
    return Jumping() || JumpingOrFalling() || me->HasUnitMovementFlag(MOVEMENTFLAG_SPLINE_ELEVATION);
}
bool bot_ai::JumpingOrFalling() const
{
    return Jumping() || me->IsFalling() || me->HasUnitMovementFlag(MOVEMENTFLAG_PITCH_UP|MOVEMENTFLAG_PITCH_DOWN|MOVEMENTFLAG_FALLING_SLOW);
}
bool bot_ai::Jumping() const
{
    return me->HasUnitState(UNIT_STATE_JUMPING);
}
bool bot_ai::IsIndoors() const
{
    return indoorsTimer >= INOUTDOORS_ENSURE_TIMER && outdoorsTimer == 0;
}
bool bot_ai::IsOutdoors() const
{
    return outdoorsTimer >= INOUTDOORS_ENSURE_TIMER && indoorsTimer == 0;
}
bool bot_ai::IsInContactWithWater() const
{
    return me->IsInWorld() &&
        (me->GetMap()->GetLiquidStatus(me->GetPhaseMask(), me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(),
            MAP_LIQUID_TYPE_WATER | MAP_LIQUID_TYPE_OCEAN) & MAP_LIQUID_STATUS_IN_CONTACT);
}

bool bot_ai::IsTempBot() const
{
    return me->GetEntry() == BOT_ENTRY_MIRROR_IMAGE_BM;
}

uint32 bot_ai::GetLostHP(Unit const* unit)
{
    return unit->GetMaxHealth() - unit->GetHealth();
}
uint8 bot_ai::GetHealthPCT(Unit const* u)
{
    if (!u || !u->IsAlive() || u->GetMaxHealth() <= 1)
        return 100;
    return uint8(((float(u->GetHealth()))/u->GetMaxHealth()) * 100);
}
uint8 bot_ai::GetManaPCT(Unit const* u)
{
    if (!u || !u->IsAlive() || u->GetMaxPower(POWER_MANA) <= 1)
        return 100;
    return (u->GetPower(POWER_MANA)*10/(1 + u->GetMaxPower(POWER_MANA)/10));
}

MeleeHitOutcome bot_ai::GetNextAttackMeleeOutCome() const
{
    return MELEE_HIT_CRUSHING;
}

uint8 bot_ai::GetBotStance() const
{
    return BOT_STANCE_NONE;
}

uint8 bot_ai::GetPlayerClass() const
{
    return BotMgr::GetBotPlayerClass(_botclass);
}
uint8 bot_ai::GetPlayerRace() const
{
    return BotMgr::GetBotPlayerRace(_botclass, me->GetRace());
}

uint8 bot_ai::GetBotComboPoints() const
{
    return me->GetVehicle() ? vehcomboPoints : uint8(GetAIMiscValue(BOTAI_MISC_COMBO_POINTS));
}

float bot_ai::GetBotAmmoDPS() const
{
    if (CanUseAmmo())
    {
        for (int8 i = MAX_AMMO_LEVEL - 1; i >= 0; --i)
            if (me->GetLevel() >= AmmoDPSForLevel[i][0])
                return float(AmmoDPSForLevel[i][1]);

        return float(AmmoDPSForLevel[0][1]);
    }

    return 0.0f;
}

uint32 bot_ai::GetPetOriginalEntry(uint32 entry)
{
    switch (entry)
    {
        case BOT_PET_IMP:
            return ORIGINAL_ENTRY_IMP;
        case BOT_PET_VOIDWALKER:
            return ORIGINAL_ENTRY_VOIDWALKER;
        case BOT_PET_SUCCUBUS:
            return ORIGINAL_ENTRY_SUCCUBUS;
        case BOT_PET_FELHUNTER:
            return ORIGINAL_ENTRY_FELHUNTER;
        case BOT_PET_FELGUARD:
            return ORIGINAL_ENTRY_FELGUARD;
        case BOT_PET_WATER_ELEMENTAL:
            return ORIGINAL_ENTRY_WATER_ELEMENTAL;
        case BOT_PET_GHOUL:
            //doesn't have pet template
            //return ORIGINAL_ENTRY_GHOUL;
        case BOT_PET_SHADOWFIEND:
            //return ORIGINAL_ENTRY_SHADOWFIEND;
        case BOT_PET_SPIRIT_WOLF:
            //return ORIGINAL_ENTRY_SPIRIT_WOLF;
        case BOT_PET_FORCE_OF_NATURE:
            //return ORIGINAL_ENTRY_FORCE_OF_NATURE;
        default:
            return ORIGINAL_ENTRY_HUNTER_PET;
    }
}

bool bot_ai::IsPetMelee(uint32 entry)
{
    switch (entry)
    {
        case BOT_PET_IMP:
        case BOT_PET_WATER_ELEMENTAL:
        case BOT_PET_AWATER_ELEMENTAL:
            return false;
        default:
            return true;
    }
}

bool bot_ai::IsMeleeClass(uint8 m_class)
{
    return
        (m_class == CLASS_WARRIOR || m_class == CLASS_ROGUE || m_class == CLASS_PALADIN ||
        m_class == CLASS_DEATH_KNIGHT || m_class == BOT_CLASS_BM || m_class == BOT_CLASS_DREADLORD ||
        m_class == BOT_CLASS_SPELLBREAKER || m_class == BOT_CLASS_CRYPT_LORD);
}
bool bot_ai::IsTankingClass(uint8 m_class)
{
    return (m_class == CLASS_WARRIOR || m_class == CLASS_PALADIN ||
        m_class == CLASS_DEATH_KNIGHT || m_class == BOT_CLASS_SPHYNX ||
        m_class == BOT_CLASS_SPELLBREAKER || m_class == BOT_CLASS_CRYPT_LORD);
}
bool bot_ai::IsBlockingClass(uint8 m_class)
{
    return (m_class == CLASS_WARRIOR || m_class == CLASS_PALADIN || m_class == CLASS_SHAMAN ||
        m_class == BOT_CLASS_SPELLBREAKER);
}
bool bot_ai::IsCastingClass(uint8 m_class)
{
    //Class can benefit from spellpower
    return (m_class == CLASS_PALADIN || m_class == CLASS_PRIEST || m_class == CLASS_SHAMAN ||
        m_class == CLASS_MAGE || m_class == CLASS_WARLOCK || m_class == CLASS_DRUID ||
        m_class == BOT_CLASS_SPHYNX || m_class == BOT_CLASS_ARCHMAGE || m_class == BOT_CLASS_DREADLORD ||
        m_class == BOT_CLASS_SPELLBREAKER || m_class == BOT_CLASS_DARK_RANGER || m_class == BOT_CLASS_NECROMANCER ||
        m_class == BOT_CLASS_SEA_WITCH);
}
bool bot_ai::IsHealingClass(uint8 m_class)
{
    return
        (m_class == BOT_CLASS_PRIEST || m_class == BOT_CLASS_DRUID ||
        m_class == BOT_CLASS_SHAMAN || m_class == BOT_CLASS_PALADIN ||
        m_class == BOT_CLASS_SPHYNX);
}
bool bot_ai::IsHumanoidClass(uint8 m_class)
{
    return m_class != BOT_CLASS_SPHYNX;
}
bool bot_ai::IsHeroExClass(uint8 m_class)
{
    return m_class == BOT_CLASS_BM || m_class == BOT_CLASS_ARCHMAGE || m_class == BOT_CLASS_DREADLORD ||
        m_class == BOT_CLASS_DARK_RANGER || m_class == BOT_CLASS_SEA_WITCH || m_class == BOT_CLASS_CRYPT_LORD;
}
bool bot_ai::IsMelee() const
{
    return !IsRanged() && HasRole(BOT_ROLE_DPS|BOT_ROLE_TANK);
}
bool bot_ai::IsRanged() const
{
    return HasRole(BOT_ROLE_RANGED) || HasVehicleRoleOverride(BOT_ROLE_RANGED);
}

bool bot_ai::IsShootingWand(Unit const* u) const
{
    if (!u) u = me;

    Spell const* spell = u->GetCurrentSpell(CURRENT_AUTOREPEAT_SPELL);
    return spell && spell->GetSpellInfo()->Id == SHOOT_WAND;
}

void bot_ai::StartPotionTimer()
{
    _potionTimer = POTION_CD * (BotMgr::IsWanderingWorldBot(me) ? std::max<uint32>(uint32(Rand()) >> 3, 1u) : 1u);
}

bool bot_ai::CanBlock() const
{
    return me->CanUseAttackType(OFF_ATTACK) &&
        (_botclass == BOT_CLASS_SPELLBREAKER || !(me->GetCreatureTemplate()->flags_extra & CREATURE_FLAG_EXTRA_NO_BLOCK));
}
bool bot_ai::CanParry() const
{
    if (me->GetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID) && me->CanUseAttackType(BASE_ATTACK))
    {
        switch (_botclass)
        {
            case BOT_CLASS_SPHYNX:
            case BOT_CLASS_SPELLBREAKER:
            case BOT_CLASS_SEA_WITCH:
                return true;
            case BOT_CLASS_WARRIOR:
            case BOT_CLASS_PALADIN:
            case BOT_CLASS_ROGUE:
            case BOT_CLASS_HUNTER:
                return me->GetLevel() >= 10;
            case BOT_CLASS_SHAMAN:
                return me->GetLevel() >= 30;
            case BOT_CLASS_DEATH_KNIGHT:
                return me->GetLevel() >= 55;
            default:
                break;
        }
    }
    return false;
}
bool bot_ai::CanDodge() const
{
    return _botclass != BOT_CLASS_BM;
}
bool bot_ai::CanCrit() const
{
    return _botclass != BOT_CLASS_BM;
}
bool bot_ai::CanMiss() const
{
    return _botclass < BOT_CLASS_EX_START;
}
bool bot_ai::CanSheath() const
{
    return _botclass < BOT_CLASS_EX_START;
}
bool bot_ai::CanSit() const
{
    return _botclass < BOT_CLASS_EX_START || _botclass == BOT_CLASS_DARK_RANGER;
}
bool bot_ai::CanEat() const
{
    return _botclass != BOT_CLASS_SPHYNX;
}
bool bot_ai::CanDrink() const
{
    return _botclass < BOT_CLASS_EX_START;
}
bool bot_ai::CanRegenInCombat() const
{
    return _botclass == BOT_CLASS_SPHYNX;
}
bool bot_ai::CanMount() const
{
    switch (_botclass)
    {
        case BOT_CLASS_BM:
        case BOT_CLASS_SPELLBREAKER:
        case BOT_CLASS_DARK_RANGER:
        case BOT_CLASS_NECROMANCER:
            return true;
        default:
            return _botclass < BOT_CLASS_EX_START;
    }
}
bool bot_ai::CanUseAmmo() const
{
    if ((_botclass == BOT_CLASS_HUNTER || _botclass == BOT_CLASS_ROGUE ||
        _botclass == BOT_CLASS_WARRIOR || _botclass == BOT_CLASS_DARK_RANGER ||
        _botclass == BOT_CLASS_SEA_WITCH) &&
        _equips[BOT_SLOT_RANGED])
    {
        ItemTemplate const* ranged = _equips[BOT_SLOT_RANGED]->GetTemplate();
        if (ranged->Class == ITEM_CLASS_WEAPON &&
            (ranged->SubClass == ITEM_SUBCLASS_WEAPON_BOW ||
            ranged->SubClass == ITEM_SUBCLASS_WEAPON_CROSSBOW ||
            ranged->SubClass == ITEM_SUBCLASS_WEAPON_GUN))
            return true;
    }
    return false;
}

bool bot_ai::RespectEquipsAttackTime() const
{
    return _botclass < BOT_CLASS_EX_START;
}
bool bot_ai::CanChangeEquip(uint8 slot) const
{
    return (_botclass != BOT_CLASS_BM && _botclass != BOT_CLASS_ARCHMAGE &&
        _botclass != BOT_CLASS_DREADLORD && _botclass != BOT_CLASS_SPELLBREAKER &&
        _botclass != BOT_CLASS_DARK_RANGER && _botclass != BOT_CLASS_NECROMANCER &&
        _botclass != BOT_CLASS_SEA_WITCH && _botclass != BOT_CLASS_CRYPT_LORD) ||
        slot > BOT_SLOT_RANGED;
}
bool bot_ai::CanDisplayNonWeaponEquipmentChanges() const
{
    return (_botclass < BOT_CLASS_EX_START || _botclass == BOT_CLASS_ARCHMAGE);
}
bool bot_ai::IsValidTransmog(uint8 slot, ItemTemplate const* source) const
{
    ASSERT(slot < BOT_TRANSMOG_INVENTORY_SIZE);

    if (!CanChangeEquip(slot))
        return false;

    Item const* item = _equips[slot];
    if (!item)
        return false;

    ItemTemplate const* target = item->GetTemplate();

    if (target->ItemId == source->ItemId)
        return false;
    if (target->Class != source->Class)
        return false;

    switch (target->InventoryType)
    {
        case INVTYPE_RELIC:
        case INVTYPE_NECK:
        case INVTYPE_FINGER:
        case INVTYPE_TRINKET:
        case INVTYPE_THROWN:
            return false;
        default:
            break;
    }
    switch (source->InventoryType)
    {
        case INVTYPE_RELIC:
        case INVTYPE_NECK:
        case INVTYPE_FINGER:
        case INVTYPE_TRINKET:
        case INVTYPE_THROWN:
        case INVTYPE_BAG:
        case INVTYPE_AMMO:
        case INVTYPE_QUIVER:
        case INVTYPE_NON_EQUIP:
            return false;
        default:
            break;
    }

    if (target->SubClass != source->SubClass)
    {
        if (target->Class == ITEM_CLASS_WEAPON && !BotMgr::MixWeaponClasses())
            return false;
        if (target->Class == ITEM_CLASS_ARMOR && !BotMgr::MixArmorClasses())
            return false;
    }

    if (target->InventoryType != source->InventoryType)
    {
        if (target->Class == ITEM_CLASS_ARMOR)
        {
            if (!((target->InventoryType == INVTYPE_ROBE || target->InventoryType == INVTYPE_CHEST) &&
                (source->InventoryType == INVTYPE_ROBE || source->InventoryType == INVTYPE_CHEST)))
                return false;
        }
        if (target->Class == ITEM_CLASS_WEAPON && !BotMgr::MixWeaponInventoryTypes())
            return false;
    }

    NpcBotTransmogData const* transmogData = BotDataMgr::SelectNpcBotTransmogs(me->GetEntry());
    if (transmogData && transmogData->transmogs[slot].second == int32(source->ItemId))
        return false;

    return true;
}

bool bot_ai::OnGossipHello(Player* player)
{
    return OnGossipHello(player, 0);
}
bool bot_ai::OnGossipSelect(Player* player, uint32 /*menuId*/, uint32 gossipListId)
{
    uint32 sender = player->PlayerTalkClass->GetGossipOptionSender(gossipListId);
    uint32 action = player->PlayerTalkClass->GetGossipOptionAction(gossipListId);
    return OnGossipSelect(player, me, sender, action);
}
bool bot_ai::OnGossipSelectCode(Player* player, uint32 /*menuId*/, uint32 gossipListId, char const* code)
{
    uint32 sender = player->PlayerTalkClass->GetGossipOptionSender(gossipListId);
    uint32 action = player->PlayerTalkClass->GetGossipOptionAction(gossipListId);
    return OnGossipSelectCode(player, me, sender, action, code);
}

bool bot_ai::IsDamagingSpell(SpellInfo const* spellInfo)
{
    for (uint8 i = 0; i < MAX_SPELL_EFFECTS; ++i)
    {
        if (spellInfo->_effects[i].IsEffect())
        {
            switch (spellInfo->_effects[i].Effect)
            {
                case SPELL_EFFECT_WEAPON_DAMAGE:
                case SPELL_EFFECT_WEAPON_DAMAGE_NOSCHOOL:
                case SPELL_EFFECT_NORMALIZED_WEAPON_DMG:
                case SPELL_EFFECT_WEAPON_PERCENT_DAMAGE:
                case SPELL_EFFECT_SCHOOL_DAMAGE:
                case SPELL_EFFECT_ENVIRONMENTAL_DAMAGE:
                case SPELL_EFFECT_HEALTH_LEECH:
                    return true;
                default:
                    break;
            }
        }
    }

    return false;
}

bool bot_ai::IsImmunedToMySpellEffect(Unit const* unit, SpellInfo const* spellInfo, SpellEffIndex index) const
{
    return unit->IsImmunedToSpellEffect(spellInfo, spellInfo->GetEffect(index), me);
}

//CONTESTED PVP
bool bot_ai::IsContestedPvP() const
{
    return me->HasUnitState(UNIT_STATE_ATTACK_PLAYER);
}
void bot_ai::SetContestedPvP()
{
    _contestedPvPTimer = 30000;
    if (!me->HasUnitState(UNIT_STATE_ATTACK_PLAYER))
    {
        me->AddUnitState(UNIT_STATE_ATTACK_PLAYER);
        Trinity::AIRelocationNotifier notifier(*me);
        Cell::VisitWorldObjects(me, notifier, me->GetVisibilityRange());
    }
    if (botPet && !botPet->HasUnitState(UNIT_STATE_ATTACK_PLAYER))
    {
        botPet->AddUnitState(UNIT_STATE_ATTACK_PLAYER);
        Trinity::AIRelocationNotifier notifier(*botPet);
        Cell::VisitWorldObjects(me, notifier, me->GetVisibilityRange());
    }
}
void bot_ai::ResetContestedPvP()
{
    _contestedPvPTimer = 0;
    me->ClearUnitState(UNIT_STATE_ATTACK_PLAYER);
    if (botPet && botPet->HasUnitState(UNIT_STATE_ATTACK_PLAYER))
        botPet->ClearUnitState(UNIT_STATE_ATTACK_PLAYER);
}
void bot_ai::UpdateContestedPvP()
{
    if (_contestedPvPTimer > 0 && _contestedPvPTimer <= lastdiff && !me->IsInCombat())
        ResetContestedPvP();
}

void bot_ai::SetGroup(Group* group, int8 subgroup)
{
    if (group == nullptr)
        _group.unlink();
    else
    {
        // never use SetGroup without a subgroup unless you specify NULL for group
        ASSERT(subgroup >= 0);
        _group.link(group, me);
        _group.setSubGroup((uint8)subgroup);
    }

    me->UpdateObjectVisibility(false);
}
void bot_ai::SetBattlegroundOrBattlefieldRaid(Group* group, int8 subgroup)
{
    SetOriginalGroup(GetGroup(), GetSubGroup());
    _group.unlink();
    _group.link(group, me);
    _group.setSubGroup((uint8)subgroup);
}
void bot_ai::RemoveFromBattlegroundOrBattlefieldRaid()
{
    _group.unlink();
    if (Group* group = GetOriginalGroup())
    {
        _group.link(group, me);
        _group.setSubGroup(GetOriginalSubGroup());
    }
    SetOriginalGroup(nullptr, -1);
}
void bot_ai::SetOriginalGroup(Group* group, int8 subgroup)
{
    if (group == nullptr)
        _originalGroup.unlink();
    else
    {
        ASSERT(subgroup >= 0);
        _originalGroup.link(group, me);
        _originalGroup.setSubGroup((uint8)subgroup);
    }
}

void bot_ai::SendUpdateToOutOfRangeBotGroupMembers()
{
    _groupUpdateTimer = BOT_GROUP_UPDATE_TIMER;

    if (_groupUpdateMask == GROUP_UPDATE_FLAG_NONE)
        return;
    if (Group* group = GetGroup())
        group->UpdateBotOutOfRange(me);

    _groupUpdateMask = GROUP_UPDATE_FLAG_NONE;
    _auraRaidUpdateMask = 0;
    if (botPet)
        botPet->GetBotPetAI()->ResetAuraUpdateMaskForRaid();
}

//BATTLEGROUNDS
bool bot_ai::IsFlagCarrier(Unit const* unit, BattlegroundTypeId bgTypeId)
{
    if (unit->IsInWorld() && unit->GetMap()->IsBattleground() && unit->HasAuraType(SPELL_AURA_EFFECT_IMMUNITY))
    {
        uint32 spellId = unit->GetAuraEffectsByType(SPELL_AURA_EFFECT_IMMUNITY).front()->GetBase()->GetId();
        switch (bgTypeId)
        {
            case BATTLEGROUND_TYPE_NONE: //must contain all possible checks
                switch (spellId)
                {
                    case 23333: // Warsong Flag (WSG)
                    case 23335: // Silverwing Flag (WSG)
                        return true;
                    default:
                        break;
                }
                break;
            case BATTLEGROUND_AV:
                break;
            case BATTLEGROUND_WS:
                switch (spellId)
                {
                    case 23333: // Warsong Flag (WSG)
                    case 23335: // Silverwing Flag (WSG)
                        return true;
                    default:
                        break;
                }
                break;
            case BATTLEGROUND_AB:
            case BATTLEGROUND_EY:
            case BATTLEGROUND_SA:
            case BATTLEGROUND_IC:
            default:
                break;
        }
    }

    return false;
}

#ifdef _MSC_VER
# pragma warning(pop)
#endif
