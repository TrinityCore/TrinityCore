#include "bot_ai.h"
//#include "botcommon.h"
#include "bot_Events.h"
#include "bot_GridNotifiers.h"
#include "botmgr.h"
#include "botdatamgr.h"
#include "bpet_ai.h"
#include "Bag.h"
#include "CellImpl.h"
#include "CharacterCache.h"
#include "Chat.h"
//#include "EventProcessor.h"
#include "GameEventMgr.h"
#include "GridNotifiersImpl.h"
#include "Item.h"
#include "LFG.h"
#include "LFGMgr.h"
#include "Mail.h"
#include "MapManager.h"
#include "MotionMaster.h"
#include "ScriptedGossip.h"
#include "SpellAuraEffects.h"
/*
NpcBot System by Trickerer (https://bitbucket.org/trickerer/trinity-bots; onlysuffering@gmail.com)
Original idea: https://bitbucket.org/lordpsyan/trinitycore-patches/src/3b8b9072280e/Individual/11185-BOTS-NPCBots.patch
TODO:
dk pets (garg, aod, rdw)
Specs
'Go there and do stuff' scenarios
Encounter Scenarios
Notes:
Methods may have null arg1 (Unit*):
DamageTaken(Unit*, ), JustDied(Unit*, ), OwnerAttackedBy(Unit*, ), HealReceived(Unit*, )
Possibly others
*/
#define MAX_AMMO_LEVEL 13
uint8 const AmmoDPSForLevel[MAX_AMMO_LEVEL][2] =
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
#define MAX_POTION_SPELLS 8
#define MAX_FEAST_SPELLS 11
uint32 const ManaPotionSpells[MAX_POTION_SPELLS][2] =
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
uint32 const HealingPotionSpells[MAX_POTION_SPELLS][2] =
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
uint32 const DrinkSpells[MAX_FEAST_SPELLS][2] =
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
uint32 const EatSpells[MAX_FEAST_SPELLS][2] =
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
uint8 GroupIconsFlags[TARGETICONCOUNT] =
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

void ApplyBotPercentModFloatVar(float &var, float val, bool apply)
{
    var *= (apply ? ((100.f + val) / 100.f) : (100.f / (100.f + val)));
}

static uint16 __rand; //calculated for each bot separately once every updateAI tick

static std::set<uint32> BotCustomSpells;
static bool SPELLS_DEFINED = false;

extern uint32 _npcBotUpdateDelayBase;
extern bool _botPvP;
extern bool _botMovementFoodInterrupt;
extern uint8 _maxClassNpcBots;
extern uint8 _healTargetIconFlags;
extern float _mult_healing;
extern bool _displayEquipment;

extern bool allBotsLoaded;

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

    _reviveTimer = 0;
    _powersTimer = 0;
    _chaseTimer = 0;

    _jumpCount = 0;
    _evadeCount = 0;

    _lastTargetGuid = ObjectGuid::Empty;

    if (_displayEquipment == false)
    {
        (const_cast<CreatureTemplate*>(me->GetCreatureTemplate()))->unit_flags2 &= ~(UNIT_FLAG2_MIRROR_IMAGE);
        me->SetFlag(UNIT_FIELD_FLAGS_2, me->GetCreatureTemplate()->unit_flags2);
    }

    m_botCommandState = COMMAND_FOLLOW;
    checkMasterTimer = urand(5000, 15000);
    feast_health = false;
    feast_mana = false;
    spawned = false;
    firstspawn = true;
    _evadeMode = false;
    _atHome = true;
    _roleMask = 0;
    haste = 0;
    hit = 0.f;
    parry = 0.f;
    dodge = 0.f;
    block = 0.f;
    crit = 0.f;
    dmg_taken_phy = 1.f;
    dmg_taken_mag = 1.f;
    armor_pen = 0.f;
    expertise = 0;
    spellpower = 0;
    spellpen = 0;
    defense = 0;
    blockvalue = 1;
    regenTimer = 0;
    m_botSpellInfo = nullptr;
    waitTimer = 0;
    GC_Timer = 0;
    lastdiff = 0;
    _energyFraction = 0.f;
    _bootTimer = -1;
    _updateTimerMedium = 0;
    _updateTimerEx1 = urand(12000, 15000);
    checkAurasTimer = 0;
    roleTimer = 0;
    doHealth = false;
    doMana = false;
    //shouldUpdateStats = true;
    pos.m_positionX = 0.f;
    pos.m_positionY = 0.f;
    pos.m_positionZ = 0.f;
    aftercastTargetGuid = ObjectGuid::Empty;

    _deathsCount = 0;
    _killsCount = 0;
    _pvpKillsCount = 0;
    _playerKillsCount = 0;

    for (uint8 i = 0; i != 6; ++i)
        resistbonus[i] = 0;

    botPet = nullptr;
    canUpdate = true;

    teleHomeEvent = nullptr;
    teleFinishEvent = nullptr;

    _ownerGuid = 0;

    ResetBotAI(BOTAI_RESET_INIT);
}
bot_ai::~bot_ai()
{
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

void bot_ai::BotSay(char const* text, Player const* target) const
{
    if (!target && master->GetTypeId() == TYPEID_PLAYER)
        target = master;
    if (!target)
        return;

    me->Say(text, LANG_UNIVERSAL, target);
}
void bot_ai::BotWhisper(char const* text, Player const* target) const
{
    if (!target && master->GetTypeId() == TYPEID_PLAYER)
        target = master;
    if (!target)
        return;

    Player* playerTarget = const_cast<Player*>(target);

    me->Whisper(text, LANG_UNIVERSAL, playerTarget);
}
void bot_ai::BotYell(char const* text, Player const* /*target*/) const
{
    //if (!target && master->GetTypeId() == TYPEID_PLAYER)
    //    target = master;
    //if (!target)
    //    return;

    me->Yell(text, LANG_UNIVERSAL);
}

bool bot_ai::SetBotOwner(Player* newowner)
{
    ASSERT(newowner && "Trying to set NULL owner!!!");
    ASSERT(newowner->GetGUID().IsPlayer() && "Trying to set a non-player as owner!!!");
    //ASSERT(master->GetGUID() == me->GetGUID());
    //ASSERT(IAmFree());

    //have master already
    if (master->GetGUID() != me->GetGUID())
    {
        TC_LOG_ERROR("entities.player", "bot_ai::SetBotOwner(): bot %s (id: %u) has master %s while trying to set to %s...",
            me->GetName().c_str(), me->GetEntry(), master->GetName().c_str(), newowner->GetName().c_str());
        return false;
    }
    if (!IAmFree())
    {
        TC_LOG_ERROR("entities.player", "bot_ai::SetBotOwner(): minion bot %s (id: %u) IS NOT FREE (has master %s) while trying to set to %s",
            me->GetName().c_str(), me->GetEntry(), master->GetName().c_str(), newowner->GetName().c_str());
        return false;
    }

    BotMgr* mgr = newowner->GetBotMgr();
    if (!mgr)
        mgr = new BotMgr(newowner);

    bool takeMoney = (_ownerGuid != newowner->GetGUID().GetCounter());
    if (mgr->AddBot(me, takeMoney) & BOT_ADD_FATAL)
    {
        //TC_LOG_ERROR("entities.player", "bot_ai::SetBotOwner(): player %s (%u) can't add bot %s (FATAL), removing...",
        //    master->GetName().c_str(), master->GetGUID().GetCounter(), me->GetName().c_str());
        //failed to add bot
        //if (_ownerGuid)
        //{
        //    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_NPCBOT_OWNER);
        //    //"UPDATE characters_npcbot SET owner = ? WHERE entry = ?", CONNECTION_ASYNC
        //    stmt->setUInt32(0, uint32(0));
        //    stmt->setUInt32(1, me->GetEntry());
        //    CharacterDatabase.Execute(stmt);
        //}

        if (_ownerGuid)
        {
            TC_LOG_ERROR("entities.player", "bot_ai::SetBotOwner(): %s's master %s (guid: %u) is found but bot failed to set owner (fatal)! Unbinding bot temporarily (until server restart)...",
                me->GetName().c_str(), newowner->GetName().c_str(), newowner->GetGUID().GetCounter());
            _ownerGuid = 0;
        }

        checkMasterTimer = 30000;
        ResetBotAI(BOTAI_RESET_LOST);
        return false;
    }

    (const_cast<CreatureTemplate*>(me->GetCreatureTemplate()))->unit_flags2 &= ~(UNIT_FLAG2_ALLOW_ENEMY_INTERACT);
    me->SetUInt32Value(UNIT_FIELD_FLAGS_2, me->GetCreatureTemplate()->unit_flags2);

    //recursive
    if (master->GetGUID() == newowner->GetGUID())
        return true;

    master = newowner;
    _ownerGuid = newowner->GetGUID().GetCounter();
    spawned = false;

    ASSERT(me->IsInWorld());
    AbortTeleport();
    return true;
}

void bot_ai::ResetBotAI(uint8 resetType)
{
    //ASSERT(me->IsInWorld());

    master = reinterpret_cast<Player*>(me);
    if (resetType & BOTAI_RESET_MASK_ABANDON_MASTER)
        _ownerGuid = 0;

    (const_cast<CreatureTemplate*>(me->GetCreatureTemplate()))->unit_flags2 |= (UNIT_FLAG2_ALLOW_ENEMY_INTERACT);
    me->SetUInt32Value(UNIT_FIELD_FLAGS_2, me->GetCreatureTemplate()->unit_flags2);

    //me->IsAIEnabled = true;
    canUpdate = true;

    if (spawned)
        ReturnHome();

    if (!me->IsInWorld())
    {
        AbortTeleport();

        //if no master - will teleport to spawn position
        //otherwise - will teleport to master
        teleHomeEvent = new TeleportHomeEvent(this);
        Events.AddEvent(teleHomeEvent, Events.CalculateTime(0)); //make sure event will be deleted
        if (teleHomeEvent->IsActive())
            teleHomeEvent->ScheduleAbort(); //make sure event will not be executed twice
        teleHomeEvent->Execute(0,0);
    }
    else
    {
        _atHome = false;
        spawned = false;
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

    if (victim->GetTypeId() == TYPEID_PLAYER && victim->ToPlayer()->IsGameMaster())
        return SPELL_FAILED_BAD_TARGETS;

    SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(spellId);
    if (!spellInfo)
        return SPELL_FAILED_DONT_REPORT;

    if (me->IsMounted() && !(spellInfo->Attributes & SPELL_ATTR0_CASTABLE_WHILE_MOUNTED))
        return SPELL_FAILED_NOT_MOUNTED;

    if (int32(me->GetPower(Powers(spellInfo->PowerType))) < spellInfo->CalcPowerCost(me, spellInfo->GetSchoolMask()))
        return SPELL_FAILED_NO_POWER;

    if (!IsSpellReady(spellInfo->GetFirstRankSpell()->Id, lastdiff, false))
        return SPELL_FAILED_NOT_READY;

    //if (victim->isType(TYPEMASK_UNIT) && InDuel(victim))
    //    return SPELL_FAILED_BAD_TARGETS;

    //if (!spellInfo->IsPassive() && spellInfo->IsRanked() && victim->isType(TYPEMASK_UNIT))
    //{
    //    bool needRankSelection = false;
    //    for (uint8 i = 0; i != MAX_SPELL_EFFECTS; ++i)
    //    {
    //        if (spellInfo->IsPositiveEffect(i) &&
    //            (spellInfo->Effects[i].Effect == SPELL_EFFECT_APPLY_AURA ||
    //            spellInfo->Effects[i].Effect == SPELL_EFFECT_APPLY_AREA_AURA_PARTY ||
    //            spellInfo->Effects[i].Effect == SPELL_EFFECT_APPLY_AREA_AURA_RAID))
    //        {
    //            needRankSelection = true;
    //            break;
    //        }
    //    }
    //    if (needRankSelection && victim->GetLevel() < spellInfo->GetFirstRankSpell()->BaseLevel)
    //    {
    //        //TC_LOG_ERROR("entities.player", "bot_ai::CheckBotCast(): %s returns SPELL_FAILED_LOWLEVEL", spellInfo->SpellName[0]);
    //        return SPELL_FAILED_LOWLEVEL;
    //    }
    //}

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
                int32 castTime = spellInfo->CastTimeEntry ? spellInfo->CastTimeEntry->CastTime : 0;
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
            break;
        default:
            TC_LOG_ERROR("entities.player", "CheckBotCast(): Unknown bot class %u", _botclass);
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

    //select aura level
    if (victim->isType(TYPEMASK_UNIT))
        if (SpellInfo const* actualSpellInfo = m_botSpellInfo->GetAuraRankForLevel(victim->GetLevel()))
            m_botSpellInfo = actualSpellInfo;

    if (victim->isType(TYPEMASK_UNIT) && (flags & TRIGGERED_FULL_MASK) != TRIGGERED_FULL_MASK &&
        !(m_botSpellInfo->AttributesEx2 & SPELL_ATTR2_CAN_TARGET_NOT_IN_LOS) &&
        !IsInBotParty(victim) && !me->IsWithinLOSInMap(victim))
        return false;

    //check wrong spell interruption attempts
    if (/*victim->isType(TYPEMASK_UNIT) && */!CastingUnitCheck::CastInterruptionCheck(victim, m_botSpellInfo))
        return false;

    //for debug only
    if (victim->isType(TYPEMASK_UNIT) && !victim->IsAlive() &&
        !(m_botSpellInfo->AttributesEx2 & SPELL_ATTR2_CAN_TARGET_DEAD) &&
        !m_botSpellInfo->HasEffect(SPELL_EFFECT_RESURRECT) &&
        !m_botSpellInfo->HasEffect(SPELL_EFFECT_RESURRECT_NEW) &&
        !m_botSpellInfo->HasEffect(SPELL_EFFECT_SELF_RESURRECT))
    {
        TC_LOG_ERROR("entities.player", "bot_ai::doCast(): %s (bot class %u) tried to cast spell %u on a dead target %s",
            me->GetName().c_str(), _botclass, spellId, victim->GetName().c_str());
        //return false;
    }

    if (me->isMoving() &&
        ((m_botSpellInfo->InterruptFlags & SPELL_INTERRUPT_FLAG_MOVEMENT)
        //autorepeat spells missing SPELL_INTERRUPT_FLAG_MOVEMENT
        || spellId == SHOOT_WAND
        //channeled spells missing SPELL_INTERRUPT_FLAG_MOVEMENT
        //Mind Flay (Rank 8)
        || spellId == 48155) &&
        !(m_botSpellInfo->Attributes & SPELL_ATTR0_ON_NEXT_SWING) && !m_botSpellInfo->IsAutoRepeatRangedSpell() &&
        !(flags & TRIGGERED_FULL_MASK) && (m_botSpellInfo->IsChanneled() || m_botSpellInfo->CalcCastTime()))
    {
        if (JumpingOrFalling())
            return false;
        if (!m_botSpellInfo->HasEffect(SPELL_EFFECT_HEAL) && Rand() > (IAmFree() ? 80 : 50))
            return false;

        //if (m_botSpellInfo->IsChanneled())
        //    TC_LOG_ERROR("entities.player", "bot_ai::doCast(): spell %u interrupts movement", spellId);
        me->BotStopMovement();
    }

    if ((!victim->isType(TYPEMASK_UNIT) || IsInBotParty(victim)) && !victim->IsWithinLOSInMap(me))
    {
        if (!IAmFree())
        {
            if (me->GetDistance(victim) > 10.f)
            {
                Position pos = victim->GetPosition();
                //victim->GetPosition(&pos);
                me->GetMotionMaster()->MovePoint(me->GetMapId(), pos);
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
            if (!const_cast<bot_ai*>(this)->removeShapeshiftForm())
                return false;
    }

    //CHECKS PASSED, NOW DO IT

    if (me->GetStandState() == UNIT_STAND_STATE_SIT && !(m_botSpellInfo->Attributes & SPELL_ATTR0_CASTABLE_WHILE_SITTING))
    {
        if (!doMana && (me->GetInterruptMask() & AURA_INTERRUPT_FLAG_NOT_SEATED))
            UpdateMana();

        feast_health = false;
        feast_mana = false;
        me->SetStandState(UNIT_STAND_STATE_STAND);
    }

    //debug
    //TC_LOG_ERROR("entities.player", "CheckBotCast(): %s (%u) by %s on %s", m_botSpellInfo->SpellName[0], spellId, me->GetName().c_str(), victim->GetName().c_str());

    bool triggered = (flags & TRIGGERED_CAST_DIRECTLY);
    SpellCastTargets targets;
    targets.SetUnitTarget(victim);
    Spell* spell = new Spell(me, m_botSpellInfo, flags);
    spell->prepare(targets); //sets current spell if succeed

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
        if (int32 castTime = m_botSpellInfo->CastTimeEntry->CastTime)
        {
            if (castTime > 0)
            {
                ApplyClassSpellCastTimeMods(m_botSpellInfo, castTime);
                if (castTime < gcd)
                    gcd = castTime;
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
void bot_ai::_calculatePos(Position& pos) const
{
    ASSERT(!IAmFree());

    uint8 followdist = master->GetBotMgr()->GetBotFollowDist();
    float mydist, angle;

    if (HasRole(BOT_ROLE_TANK) && !IsTank(master))
    {
        uint8 tanks = master->GetBotMgr()->GetNpcBotsCountByRole(BOT_ROLE_TANK);
        uint8 slot = master->GetBotMgr()->GetNpcBotSlotByRole(BOT_ROLE_TANK, me);
        angle = M_PI / 6.0f; //max bias (left of right) //total arc is angle * 2
        angle = (angle / tanks) * (slot - (slot % 2)); //bias
        if (slot % 2) angle *= -1.f; //bias interchange
        mydist = 3.5f;
    }
    else if (HasRole(BOT_ROLE_RANGED))
    {
        uint8 rangeds = master->GetBotMgr()->GetNpcBotsCountByRole(BOT_ROLE_RANGED);
        uint8 slot = master->GetBotMgr()->GetNpcBotSlotByRole(BOT_ROLE_RANGED, me);
        angle = M_PI / 3.5f; //max bias (left of right) //total arc is angle * 2
        angle = (angle / rangeds) * (slot - (slot % 2)); //bias
        if (slot % 2) angle *= -1.f; //bias interchange
        angle += M_PI; //behind
        mydist = 1.0f;
    }
    else if (HasRole(BOT_ROLE_DPS))
    {
        uint8 dpss = master->GetBotMgr()->GetNpcBotsCountByRole(BOT_ROLE_DPS);
        uint8 slot = master->GetBotMgr()->GetNpcBotSlotByRole(BOT_ROLE_DPS, me);
        angle = M_PI / 7.5f; //max bias (left of right) //total arc is angle * 2
        angle = (angle / dpss) * (slot); //bias
        if (slot % 2) angle *= -1.f; //bias interchange
        angle += ((slot % 4) < 2) ? (M_PI/2.f) : -(M_PI/2.f); //sides
        mydist = 2.0f;
    }
    else
    {
        angle = (me->GetEntry() % 2) ? (M_PI/2.f) : -(M_PI/2.f);
        mydist = 0.5f;
    }

    mydist += std::max<float>(int8(followdist) - 30, 5) / 7.f; //1.f-10.f
    mydist = std::max<float>(mydist - 2.f, 0.0f); //get bots closer
    angle += master->GetOrientation();

    float x(0),y(0),z(master->GetPositionZ());
    float size = me->GetCombatReach()/3.f;
    bool over = false;
    for (uint8 i = 0; i != 5 + over; ++i)
    {
        if (over)
        {
            mydist *= 0.2f;
            break;
        }
        //master->GetNearPoint(me, x, y, z, mydist, angle);
        master->GetNearPoint2D(nullptr, x, y, mydist+size, angle);
        if (!master->IsWithinLOS(x,y,z)) //try to get much closer to master
        {
            mydist *= 0.4f - float(i*0.07f);
            size *= 0.1f;
            if (size < 0.1)
                size = 0.f;
        }
        else
            over = true;
    }

    //plan ahead
    uint32 movFlags = master->m_movementInfo.GetMovementFlags();
    if ((movFlags & MOVEMENTFLAG_FORWARD) && !(movFlags & MOVEMENTFLAG_FALLING_FAR))
    {
        float const aheadDist = std::max<float>(followdist * 0.08, 6.f);
        x += aheadDist * std::cos(master->GetOrientation());
        y += aheadDist * std::sin(master->GetOrientation());
    }
    if (!me->CanFly())
        me->UpdateGroundPositionZ(x, y, z);
    if (me->GetPositionZ() < z)
        z += 0.5f; //prevent going underground

    pos.m_positionX = x;
    pos.m_positionY = y;
    pos.m_positionZ = z;

    //         TTT
    //      m       m
    //     m    M    m
    //      m       m
    //        rrrrr
    //
    //M - master
    //T - bot tank (ROLE_TANK)
    //r - ranged (ROLE_RANGED)
    //m - melee (ROLE_DPS)
}
// Movement set
// Uses MovePoint() for following instead of MoveFollow()
// This helps bots overcome a bug with fanthom walls on grid borders blocking pathing
void bot_ai::SetBotCommandState(CommandStates st, bool force, Position* newpos)
{
    if (!me->IsAlive())
        return;

    if (JumpingOrFalling())
        return;

    if (st == COMMAND_FOLLOW && !IsChanneling() &&
        ((!me->isMoving() && !IsCasting() && master->IsAlive() && !Feasting()) || force))
    {
        if (!me->IsInMap(master)) return;
        if (CCed(me, true)/* || master->HasUnitState(UNIT_STATE_FLEEING)*/) return;
        if (me->isMoving() && Rand() > 10) return;
        if (!newpos)
            _calculatePos(pos);
        else
        {
            pos.m_positionX = newpos->m_positionX;
            pos.m_positionY = newpos->m_positionY;
            pos.m_positionZ = newpos->m_positionZ;
        }
        if (me->GetStandState() == UNIT_STAND_STATE_SIT && !Feasting())
            me->SetStandState(UNIT_STAND_STATE_STAND);
        if (IsShootingWand())
            me->InterruptSpell(CURRENT_AUTOREPEAT_SPELL);
        me->GetMotionMaster()->MovePoint(master->GetMapId(), pos);
        //me->GetMotionMaster()->MoveFollow(master, mydist, angle);
    }
    else if (st == COMMAND_STAY)
    {
        if (me->isMoving())
            me->BotStopMovement();
    }
    else if (st == COMMAND_ATTACK)
    { }
    m_botCommandState = st;
}
// Buffs And Heal (really)
// Priority as follows: 1) heal players 2) buff players 3) heal bots 4) buff bots
// Priority adjustments to be considered
void bot_ai::BuffAndHealGroup(uint32 diff)
{
    if (GC_Timer > diff) return;
    if (me->IsMounted()) return;
    if (IsCasting() || Feasting()) return;

    if (IAmFree())
    {
        //heals
        //if (HealTarget(me, diff))
        //    return;
        //if (botPet)
        //{
        //    if (botPet->IsAlive())
        //    {
        //        if (HealTarget(botPet, diff))
        //            return;
        //    }
        //}

        bool omniHostile = (me->GetFaction() == 14 || me->HasAura(BERSERK));

        //if (!omniHostile && HasRole(BOT_ROLE_HEAL))
        //{
        //    std::list<Unit*> targets1;
        //    GetNearbyFriendlyTargetsList(targets1, 38);
        //    targets1.remove_if(BOTAI_PRED::HealTargetExclude());
        //    if (!targets1.empty() && HealTarget(Trinity::Containers::SelectRandomContainerElement(targets1), diff))
        //        return;
        //}

        //buffs
        if (BuffTarget(me, diff))
            return;

        if (!omniHostile)
        {
            std::list<Unit*> targets2;
            GetNearbyFriendlyTargetsList(targets2, 30);
            targets2.remove_if(BOTAI_PRED::BuffTargetExclude());
            for (std::list<Unit*>::const_iterator itr = targets2.begin(); itr != targets2.end(); ++itr)
                if (urand(1,100) <= 30 && BuffTarget(*itr, diff))
                    return;
        }

        return;
    }

    BotMap const* map;
    Group const* pGroup = master->GetGroup();
    if (!pGroup)
    {
        //heals
        map = master->GetBotMgr()->GetBotMap();
        if (HasRole(BOT_ROLE_HEAL))
        {
            std::list<Unit*> targets3;
            if (master->IsAlive() && !master->HasUnitState(UNIT_STATE_ISOLATED) && GetHealthPCT(master) < 95 && me->GetDistance(master) < 40)
                targets3.push_back(master);
            //if (Unit* veh = master->GetVehicleBase())
            //    if (veh->GetTypeId() == TYPEID_UNIT)
            //        if (veh->ToCreature()->GetCreatureTemplate()->type != CREATURE_TYPE_MECHANICAL)
            //            targets3.push_back(veh);
            for (BotMap::const_iterator itr = map->begin(); itr != map->end(); ++itr)
            {
                Unit* u = itr->second;
                if (!(!u->IsInWorld() || me->GetMap() != u->FindMap() || !u->IsAlive() || u->HasUnitState(UNIT_STATE_ISOLATED) ||
                    u->ToCreature()->IsTempBot() || me->GetDistance(u) > 40 ||
                    (GetHealthPCT(u) > 95 && !IsTank(u))))
                    targets3.push_back(u);

                u = itr->second->GetBotsPet();

                if (!(!u || !u->IsAlive() || u->HasUnitState(UNIT_STATE_ISOLATED) || me->GetDistance(u) > 40 || GetHealthPCT(u) > 95))
                    targets3.push_back(u);
            }
            for (Unit::ControlList::const_iterator itr = master->m_Controlled.begin(); itr != master->m_Controlled.end(); ++itr)
            {
                Unit* u = *itr;
                if (!u->IsInWorld() || me->GetMap() != u->FindMap() || !u->IsAlive() || u->HasUnitState(UNIT_STATE_ISOLATED) ||
                    u->IsTotem() || u->GetEntry() == SHAMAN_EARTH_ELEMENTAL || me->GetDistance(u) > 40 ||
                    (GetHealthPCT(u) > 95 && !IsTank(u)))
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
            if (!Bots)
                Bots = true;
            if (!tPlayer->IsAlive() || tPlayer->HasUnitState(UNIT_STATE_ISOLATED)) continue;
            if (me->GetDistance(tPlayer) > 40) continue;
            if (GetHealthPCT(tPlayer) < 95 || IsTank(tPlayer))
                targets5.push_back(tPlayer);
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
                    for (BotMap::const_iterator itr = map->begin(); itr != map->end(); ++itr)
                    {
                        Unit* u = itr->second;
                        if (!(!u->IsInWorld() || me->GetMap() != u->FindMap() || !u->IsAlive() || u->HasUnitState(UNIT_STATE_ISOLATED) ||
                            u->ToCreature()->IsTempBot() || me->GetDistance(u) > 40 ||
                            (GetHealthPCT(u) > 95 && !IsTank(u))))
                            targets5.push_back(u);

                        u = itr->second->GetBotsPet();

                        if (!(!u || !u->IsAlive() || u->HasUnitState(UNIT_STATE_ISOLATED) || me->GetDistance(u) > 40 || GetHealthPCT(u) > 95))
                            targets5.push_back(u);
                    }
                }
                for (Unit::ControlList::const_iterator itr = master->m_Controlled.begin(); itr != master->m_Controlled.end(); ++itr)
                {
                    Unit* u = *itr;
                    if (!u || !u->IsInWorld() || me->GetMap() != u->FindMap() || !u->IsAlive() || u->HasUnitState(UNIT_STATE_ISOLATED) ||
                        u->IsTotem() || u->GetEntry() == SHAMAN_EARTH_ELEMENTAL || me->GetDistance(u) > 40 ||
                        (GetHealthPCT(u) > 95 && !IsTank(u)))
                        continue;

                    targets5.push_back(u);
                }
            }
        }

        //check if we have pointed heal target
        for (uint8 i = 0; i != TARGETICONCOUNT; ++i)
        {
            if (_healTargetIconFlags & GroupIconsFlags[i])
            {
                if (ObjectGuid guid = pGroup->GetTargetIcons()[i])//check this one
                {
                    if (Unit* unit = ObjectAccessor::GetUnit(*me, guid))
                    {
                        if (unit->IsAlive() && !unit->HasUnitState(UNIT_STATE_ISOLATED) && me->GetMap() == unit->FindMap() && me->GetDistance(unit) < 40 &&
                            GetHealthPCT(unit) < 95 && master->GetVictim() != unit && !IsInBotParty(unit->GetVictim()) &&
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
        if (!Bots)
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
                for (BotMap::const_iterator itr = map->begin(); itr != map->end(); ++itr)
                {
                    Unit* u = itr->second;
                    if (!(!u->IsInWorld() || me->GetMap() != u->FindMap() || !u->IsAlive() || u->HasUnitState(UNIT_STATE_ISOLATED) ||
                        u->IsTotem() || me->GetDistance(u) > 30))
                        targets6.push_back(u);

                    //u = itr->second->GetBotsPet();

                    //if (!(!u || !u->IsAlive() || u->HasUnitState(UNIT_STATE_ISOLATED) || me->GetDistance(u) > 30))
                    //    targets6.push_back(u);
                }
            }
            for (Unit::ControlList::const_iterator itr = master->m_Controlled.begin(); itr != master->m_Controlled.end(); ++itr)
            {
                Unit* u = *itr;
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
void bot_ai::RezGroup(uint32 REZZ)
{
    if (!REZZ || Rand() > 10)
        return;

    //TC_LOG_ERROR("entities.player", "RezGroup by %s", me->GetName().c_str());

    if (IAmFree())
    {
        if (me->GetFaction() == 14 || me->HasAura(BERSERK))
            return;

        WorldObject* playerOrCorpse = GetNearbyRezTarget();
        if (!playerOrCorpse)
            return;

        if (!playerOrCorpse->IsWithinLOSInMap(me))
            me->Relocate(*playerOrCorpse);

        Unit* target = playerOrCorpse->GetTypeId() == TYPEID_PLAYER ? playerOrCorpse->ToUnit() : (Unit*)playerOrCorpse->ToCorpse();
        if (doCast(target, REZZ)) //rezzing it
        {
            if (Player const* player = playerOrCorpse->GetTypeId() == TYPEID_PLAYER ? playerOrCorpse->ToPlayer() : ObjectAccessor::FindPlayer(playerOrCorpse->ToCorpse()->GetOwnerGUID()))
                BotWhisper("Rezzing You", player);
        }

        return;
    }

    Group const* group = master->GetGroup();
    if (!group)
    {
        if (master->IsAlive() || master->IsResurrectRequested())
            return;

        Unit* target = master;
        if (master->HasFlag(PLAYER_FLAGS, PLAYER_FLAGS_GHOST))
            target = (Unit*)master->GetCorpse();
        if (!target || !target->IsInWorld()) return;
        if (me->GetMap() != target->FindMap()) return;
        if (me->GetDistance(target) > 30)
        {
            me->GetMotionMaster()->MovePoint(master->GetMapId(), *target);
            return;
        }
        else if (me->GetDistance(target) < 15 && !target->IsWithinLOSInMap(me))
            me->Relocate(*target);

        if (doCast(target, REZZ))//rezzing it
            BotWhisper("Rezzing You");

        return;
    }

    bool Bots = false;
    Player* player;
    Unit* target;
    for (GroupReference const* itr = group->GetFirstMember(); itr != nullptr; itr = itr->next())
    {
        player = itr->GetSource();
        target = player;
        if (!player || player->FindMap() != me->GetMap()) continue;
        if (!Bots && player->HaveBot())
            Bots = true;
        if (player->IsAlive() || player->IsResurrectRequested()) continue;
        if (player->HasFlag(PLAYER_FLAGS, PLAYER_FLAGS_GHOST))
            target = (Unit*)player->GetCorpse();
        if (!target || !target->IsInWorld()) continue;
        if (target->GetTypeId() != player->GetTypeId() && me->GetMap() != target->FindMap()) continue;
        if (me->GetDistance(target) > 30)
        {
            if (player == master)
            {
                me->GetMotionMaster()->MovePoint(me->GetMapId(), *target);
                return;
            }
            continue;
        }
        else if (me->GetDistance(target) < 15 && !target->IsWithinLOSInMap(me))
            me->Relocate(*target);

        if (doCast(target, REZZ))//rezzing it
        {
            BotWhisper("Rezzing You", player);
            if (player != master)
            {
                std::string rezstr = "Rezzing ";
                rezstr += player->GetName();
                BotWhisper(rezstr.c_str());
            }
            return;
        }
    }

    if (!Bots)
        return;

    std::list<Unit*> targets;
    BotMap const* map;
    for (GroupReference const* itr = group->GetFirstMember(); itr != nullptr; itr = itr->next())
    {
        player = itr->GetSource();
        if (!player || player->FindMap() != me->GetMap() || !player->HaveBot()) continue;

        map = player->GetBotMgr()->GetBotMap();
        for (BotMap::const_iterator itr = map->begin(); itr != map->end(); ++itr)
        {
            target = itr->second;
            if (!target || !target->IsInWorld() || target->IsAlive()) continue;
            if (itr->second->GetBotAI()->GetReviveTimer() < 15000) continue;
            if (me->GetDistance(target) < 30 && target->IsWithinLOSInMap(me))
                targets.push_back(target);
        }
    }

    //TC_LOG_ERROR("entities.unit", "RezGroup: %s found %u targets", me->GetName().c_str(), uint32(targets.size()));

    if (targets.empty())
        return;

    target = targets.size() < 2 ? targets.front() : Trinity::Containers::SelectRandomContainerElement(targets);

    if (doCast(target, REZZ))
    {
        Player const* targetOwner = target->ToCreature()->GetBotOwner();
        if (targetOwner != master)
        {
            std::string rezstr1 = "Rezzing ";
            rezstr1 += target->GetName();
            rezstr1 += " (your bot)";

            std::string rezstr2 = "Rezzing ";
            rezstr2 += target->GetName();
            rezstr2 += " (";
            rezstr2 += targetOwner->GetName();
            rezstr2 += "'s bot)";

            BotWhisper(rezstr1.c_str(), targetOwner);
            BotWhisper(rezstr2.c_str());
        }
        else
        {
            std::string rezstr3 = "Rezzing ";
            rezstr3 += target->GetName();
            BotWhisper(rezstr3.c_str());
        }
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
                if (_canCureTarget(*itr, cureSpell))
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

    //TC_LOG_ERROR("entities.player", "%s: CureGroup() on %s", me->GetName().c_str(), pTarget->GetName().c_str());
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
            Unit* u = *itr;
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
                for (BotMap::const_iterator itr = map->begin(); itr != map->end(); ++itr)
                {
                    u = itr->second;
                    if (!u || !u->IsInWorld() || me->GetMap() != u->FindMap() || !u->IsAlive()) continue;
                    if (_canCureTarget(u, cureSpell))
                        targets.push_back(u);
                }
            }

            for (Unit::ControlList::const_iterator itr = tPlayer->m_Controlled.begin(); itr != tPlayer->m_Controlled.end(); ++itr)
            {
                Unit* u = *itr;
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

    SpellInfo const* info = sSpellMgr->GetSpellInfo(cureSpell);
    if (!info)
        return false;

    if (me->GetDistance(target) > CalcSpellMaxRange(cureSpell, false))
        return false;

    uint32 dispelMask = 0;
    for (uint8 i = 0; i != MAX_SPELL_EFFECTS; ++i)
        if (info->Effects[i].Effect == SPELL_EFFECT_DISPEL)
            dispelMask |= SpellInfo::GetDispelMask(DispelType(info->Effects[i].MiscValue));

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
//protected
// Quick check if current target has school immunities to prevent cast attempts spam
// CheckBotCast()->_checkImmunities()
// Only called after opponent is validated in CheckAttackTarget()->_getTarget()
bool bot_ai::CanAffectVictim(uint32 schoolMask) const
{
    if (schoolMask == SPELL_SCHOOL_MASK_NONE)
    {
        TC_LOG_ERROR("entities.player", "bot_ai::CanDamageVictim(): schoolMask is not present (class = %u)", _botclass);
        return false;
    }

    Unit::AuraEffectList const& schoolImmunityAurasList = opponent->GetAuraEffectsByType(SPELL_AURA_SCHOOL_IMMUNITY);
    if (!schoolImmunityAurasList.empty())
    {
        uint32 finalMask = 0;
        for (Unit::AuraEffectList::const_iterator itr = schoolImmunityAurasList.begin(); itr != schoolImmunityAurasList.end(); ++itr)
        {
            finalMask |= ((*itr)->GetMiscValue() & schoolMask);
            if (finalMask == schoolMask)
                return false;
        }
    }

    return true;
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

    if (!spellInfo->IsPositive() && spellInfo->DmgClass == SPELL_DAMAGE_CLASS_MAGIC &&
        !(spellInfo->Attributes & SPELL_ATTR0_ABILITY) && !(spellInfo->AttributesEx & SPELL_ATTR1_CANT_BE_REFLECTED) &&
        !(spellInfo->Attributes & SPELL_ATTR0_UNAFFECTED_BY_INVULNERABILITY))
    {
        //bool directDamage = false;
        //for (uint8 i = 0; i != MAX_SPELL_EFFECTS; ++i)
        //{
        //    if (spellInfo->Effects[i].TargetA.GetTarget() == TARGET_UNIT_TARGET_ENEMY)
        //    {
        //        if (spellInfo->Effects[i].IsEffect(SPELL_EFFECT_SCHOOL_DAMAGE) ||
        //            spellInfo->Effects[i].IsAura(SPELL_AURA_PERIODIC_DAMAGE) ||
        //            spellInfo->Effects[i].IsAura(SPELL_AURA_PERIODIC_LEECH) ||
        //            spellInfo->Effects[i].IsAura(SPELL_AURA_MOD_SPEED_SLOW_ALL) ||//Icy Touch
        //            spellInfo->Effects[i].IsAura(SPELL_AURA_HASTE_SPELLS))//Slow
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
    botstring << "ListAuras for" << unit->GetName().c_str() << "(class: " << uint32(bot_pet_player_class) << "), ";
    if (unit->GetTypeId() == TYPEID_PLAYER)
        botstring << "player";
    else if (unit->GetTypeId() == TYPEID_UNIT && unit->ToCreature()->IsNPCBot())
    {
        bot_ai const* ai = unit->ToCreature()->GetBotAI();
        botstring << "master: ";
        Player const* owner = ai->GetBotOwner();
        botstring << (owner != unit ? owner->GetName() : "none");
    }
    uint8 locale = player->GetSession()->GetSessionDbcLocale();
    Unit::AuraMap const &vAuras = unit->GetOwnedAuras();
    for (Unit::AuraMap::const_iterator itr = vAuras.begin(); itr != vAuras.end(); ++itr)
    {
        SpellInfo const* spellInfo = itr->second->GetSpellInfo();
        if (!spellInfo)
            continue;
        uint32 id = spellInfo->Id;
        SpellInfo const* learnSpellInfo = sSpellMgr->GetSpellInfo(spellInfo->Effects[0].TriggerSpell);
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
            botstring << " Rank " << rank;
        if (talentcost > 0)
            botstring << " [talent]";
        if (spellInfo->IsPassive())
            botstring << " [passive]";
        if ((spellInfo->Attributes & SPELL_ATTR0_HIDDEN_CLIENTSIDE) ||
            (spellInfo->AttributesEx & SPELL_ATTR1_DONT_DISPLAY_IN_AURA_BAR))
            botstring << " [hidden]";
        if (unit->GetTypeId() == TYPEID_PLAYER && unit->ToPlayer()->HasSpell(id))
            botstring << " [known]";
        else if (unit == me && GetSpell(spellInfo->GetFirstRankSpell()->Id))
            botstring << " [ability]";
    }
    botstring.precision(1);
    for (uint8 i = STAT_STRENGTH; i != MAX_STATS; ++i)
    {
        std::string mystat;
        switch (i)
        {
            case STAT_STRENGTH: mystat = "str"; break;
            case STAT_AGILITY: mystat = "agi"; break;
            case STAT_STAMINA: mystat = "sta"; break;
            case STAT_INTELLECT: mystat = "int"; break;
            case STAT_SPIRIT: mystat = "spi"; break;
            default: mystat = "unk stat"; break;
        }
        //ch.PSendSysMessage("base %s: %.1f", mystat.c_str(), unit->GetCreateStat(Stats(i));
        float totalstat = unit->GetTotalStatValue(Stats(i));
        //ch.PSendSysMessage("base total %s: %.1f", mystat.c_str(), totalstat);
        if (unit == me)
        {
            int8 t = -1;
            switch (i)
            {
                case STAT_STRENGTH:     t = BOT_STAT_MOD_STRENGTH;  break;
                case STAT_AGILITY:      t = BOT_STAT_MOD_AGILITY;   break;
                case STAT_STAMINA:      t = BOT_STAT_MOD_STAMINA;   break;
                case STAT_INTELLECT:    t = BOT_STAT_MOD_INTELLECT; break;
                case STAT_SPIRIT:       t = BOT_STAT_MOD_SPIRIT;    break;
                default:                                            break;
            }

            if (t >= BOT_STAT_MOD_MANA)
                totalstat = GetTotalBotStat(t);
        }
        botstring << "\ntotal" << mystat << ": " << float(totalstat);
    }
    botstring.precision(2);
    botstring << "\nMelee AP: " << int32(unit->GetTotalAttackPowerValue(BASE_ATTACK));
    botstring << "\nRanged AP: " << int32(unit->GetTotalAttackPowerValue(RANGED_ATTACK));
    botstring << "\narmor: " << uint32(unit->GetArmor());
    botstring << "\ncrit: " << float(unit->GetUnitCriticalChanceDone(BASE_ATTACK));
    botstring << "\ndefense: " << uint32(unit->GetDefenseSkillValue());
    botstring << "\nmiss : " << float(unit->GetUnitMissChance());
    botstring << "\ndodge: " << float(unit->GetUnitDodgeChance(BASE_ATTACK, me));
    botstring << "\nparry: " << float(unit->GetUnitParryChance(BASE_ATTACK, me));
    botstring << "\nblock: " << float(unit->GetUnitBlockChance(BASE_ATTACK, me));
    botstring << "\nblock value: " << uint32(unit->GetShieldBlockValue());
    botstring << "\nDamage taken melee: " << float(dmg_taken_phy * unit->GetTotalAuraMultiplierByMiscMask(SPELL_AURA_MOD_DAMAGE_PERCENT_TAKEN, SPELL_SCHOOL_MASK_NORMAL));
    botstring << "\nDamage taken spell: " << float(dmg_taken_mag * unit->GetTotalAuraMultiplierByMiscMask(SPELL_AURA_MOD_DAMAGE_PERCENT_TAKEN, SPELL_SCHOOL_MASK_MAGIC));

    WeaponAttackType type = BASE_ATTACK;
    float attSpeed = (unit->GetAttackTime(type) * unit->m_modAttackSpeedPct[type])/1000.f;
    botstring << "\nDamage range mainhand: min: " << int32(unit->GetFloatValue(UNIT_FIELD_MINDAMAGE)) << ", max: " << int32(unit->GetFloatValue(UNIT_FIELD_MAXDAMAGE));
    botstring << "\nDamage mult mainhand: " << float(unit->GetPctModifierValue(UNIT_MOD_DAMAGE_MAINHAND, BASE_PCT)*unit->GetPctModifierValue(UNIT_MOD_DAMAGE_MAINHAND, TOTAL_PCT));
    botstring << "\nAttack time mainhand: " << float(attSpeed)
        << " (" << float(((unit->GetFloatValue(UNIT_FIELD_MINDAMAGE) + unit->GetFloatValue(UNIT_FIELD_MAXDAMAGE)) / 2) / attSpeed) << " DPS)";
    if (unit->haveOffhandWeapon())
    {
        type = OFF_ATTACK;
        attSpeed = (unit->GetAttackTime(type) * unit->m_modAttackSpeedPct[type])/1000.f;
        botstring << "\nDamage range offhand: min: " << int32(unit->GetFloatValue(UNIT_FIELD_MINOFFHANDDAMAGE)) << ", max: " << int32(unit->GetFloatValue(UNIT_FIELD_MAXOFFHANDDAMAGE));
        botstring << "\nDamage mult offhand: " << float(unit->GetPctModifierValue(UNIT_MOD_DAMAGE_OFFHAND, BASE_PCT)*unit->GetPctModifierValue(UNIT_MOD_DAMAGE_OFFHAND, TOTAL_PCT));
        botstring << "\nAttack time offhand: " << float(attSpeed)
            << " (" << float(((unit->GetFloatValue(UNIT_FIELD_MINOFFHANDDAMAGE) + unit->GetFloatValue(UNIT_FIELD_MAXOFFHANDDAMAGE)) / 2) / attSpeed) << " DPS)";
    }
    if (unit != me ||
        (me->GetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID + 2) &&
        _botclass != BOT_CLASS_PALADIN &&
        _botclass != BOT_CLASS_DEATH_KNIGHT &&
        _botclass != BOT_CLASS_DRUID &&
        _botclass != BOT_CLASS_SHAMAN))
    {
        type = RANGED_ATTACK;
        attSpeed = (unit->GetAttackTime(type) * unit->m_modAttackSpeedPct[type])/1000.f;
        botstring << "\nDamage range ranged: min: " << int32(unit->GetFloatValue(UNIT_FIELD_MINRANGEDDAMAGE)) << ", max: " << int32(unit->GetFloatValue(UNIT_FIELD_MAXRANGEDDAMAGE));
        botstring << "\nDamage mult ranged: " << float(unit->GetPctModifierValue(UNIT_MOD_DAMAGE_RANGED, BASE_PCT)*unit->GetPctModifierValue(UNIT_MOD_DAMAGE_RANGED, TOTAL_PCT));
        botstring << "\nAttack time ranged: " << float(attSpeed)
            << " (" << float(((unit->GetFloatValue(UNIT_FIELD_MINRANGEDDAMAGE) + unit->GetFloatValue(UNIT_FIELD_MAXRANGEDDAMAGE)) / 2) / attSpeed)
            << " (" << float(unit->GetTypeId() == TYPEID_PLAYER ? unit->ToPlayer()->GetAmmoDPS() : unit->ToCreature()->GetCreatureAmmoDPS()) << " from ammo) DPS)";
    }
    botstring << "\nbase hp: " << int32(unit->GetCreateHealth());
    botstring << "\ntotal hp: " << int32(unit->GetMaxHealth());
    botstring << "\nbase mana: " << int32(unit->GetCreateMana());
    botstring << "\ntotal mana: " << int32(unit->GetMaxPower(POWER_MANA));
    if (unit->GetMaxPower(POWER_MANA) > 1 && unit->GetPowerType() != POWER_MANA)
        botstring << "\ncur mana: " << int32(unit->GetPower(POWER_MANA));

    if (unit == me)
    {
        botstring << "\nspell power: " << int32(me->SpellBaseDamageBonusDone(SPELL_SCHOOL_MASK_MAGIC));
        botstring << "\nhealth regen_5 bonus: " << int32(_getTotalBotStat(BOT_STAT_MOD_HEALTH_REGEN));
        if (me->GetMaxPower(POWER_MANA) > 1)
        {
            botstring << "\nmana regen_5 casting: " << float((_botclass == BOT_CLASS_SPHYNX ? -1.f : 1.f) * me->GetFloatValue(UNIT_FIELD_POWER_REGEN_INTERRUPTED_FLAT_MODIFIER) * sWorld->getRate(RATE_POWER_MANA) * 5.0f);
            botstring << "\nmana regen_5 no cast: " << float((_botclass == BOT_CLASS_SPHYNX ? -1.f : 1.f) * me->GetFloatValue(UNIT_FIELD_POWER_REGEN_FLAT_MODIFIER) * sWorld->getRate(RATE_POWER_MANA) * 5.0f);
        }
        botstring << "\nhaste: " << (haste >= 0 ? "+" : "-") << float(haste) << " pct";
        botstring << "\nhit: +" << float (hit) << " pct";
        botstring << "\nexpertise: " << int32(expertise) << " (-" << float(float(expertise) * 0.25f) << " pct)";
        botstring << "\narmor penetration: " << float(me->GetCreatureArmorPenetrationCoef()) << " pct";
        botstring << "\nspell penetration: " << uint32(spellpen);

        for (uint8 i = SPELL_SCHOOL_HOLY; i != MAX_SPELL_SCHOOL; ++i)
        {
            uint32 curresist = me->GetResistance(SpellSchools(i)) + resistbonus[i-1];

            const char* resist = nullptr;
            switch (i)
            {
                case 1: resist = "holy";   break;
                case 2: resist = "fire";   break;
                case 3: resist = "nature"; break;
                case 4: resist = "frost";  break;
                case 5: resist = "shadow"; break;
                case 6: resist = "arcane"; break;
            }
            botstring << "\nResistance " << resist << ": " << uint32(curresist);
        }
        botstring << "\nBotCommandState: " << (m_botCommandState == COMMAND_FOLLOW ? "Follow" : m_botCommandState == COMMAND_ATTACK ? "Attack" : m_botCommandState == COMMAND_STAY ? "Stay" : m_botCommandState == COMMAND_ABANDON ? "Reset" : "none");
        if (!IAmFree())
            botstring << "\nFollow distance: " << uint32(master->GetBotMgr()->GetBotFollowDist());

        //botstring << "\nBoot timer: %i", _bootTimer);
        botstring << "\nBot roles mask main: " << uint32(_roleMask & BOT_ROLE_MASK_MAIN);
        botstring << "\nBot roles mask gathering: " << uint32(_roleMask & BOT_ROLE_MASK_GATHERING);

        botstring << "\nPvP kills: " << uint32(_pvpKillsCount) << ", players: " << uint32(_playerKillsCount) << ", total: " << uint32(_killsCount);
        botstring << "\nDied " << uint32(_deathsCount) << " times";

        //debug
        //for (uint32 i = 0; i != 148; ++i)
        //{
        //    float val = me->GetFloatValue(i);
        //    ch.PSendSysMessage("Float value at %u: %.9f", i, val);
        //}

        //ch.PSendSysMessage("healTargetIconFlags: %u", healTargetIconFlags);

        //ch.PSendSysMessage("Roles:");
        //for (uint16 i = BOT_MAX_ROLE; i != BOT_ROLE_NONE; i >>= 1)
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

    uint8 myclass = _botclass;
    uint8 mylevel = std::min<uint8>(master->GetLevel(), 80);

    if (myclass == BOT_CLASS_DRUID && GetBotStance() != BOT_STANCE_NONE)
        myclass = GetBotStance();

    shouldUpdateStats = false;
    /*TC_LOG_ERROR("entities.player", "*etStats(): Updating bot %s, class: %u, race: %u, level %u, master: %s",
        me->GetName().c_str(), myclass, myrace, mylevel, master->GetName().c_str());*/

    switch (me->GetCreatureTemplate()->rank) //TODO: conditions
    {
        case CREATURE_ELITE_RARE:       mylevel += 1;   break;
        case CREATURE_ELITE_ELITE:      mylevel += 2;   break;
        case CREATURE_ELITE_RAREELITE:  mylevel += 3;   break;
        default:                                        break;
    }
    mylevel = std::min<uint8>(mylevel, 83);

    //Do not remove this code
    if (_botclass == BOT_CLASS_DEATH_KNIGHT)
        mylevel = std::max<uint8>(mylevel, 55);
    else if (_botclass == BOT_CLASS_SPHYNX)
        mylevel = std::max<uint8>(mylevel, 60);
    else if (_botclass == BOT_CLASS_ARCHMAGE)
        mylevel = std::max<uint8>(mylevel, 20);
    else if (_botclass == BOT_CLASS_DREADLORD)
        mylevel = std::max<uint8>(mylevel, 60);
    else if (_botclass == BOT_CLASS_SPELLBREAKER)
        mylevel = std::max<uint8>(mylevel, 20);
    else if (_botclass == BOT_CLASS_DARK_RANGER)
        mylevel = std::max<uint8>(mylevel, 40);

    //LEVEL
    if (me->GetLevel() != mylevel)
    {
        me->SetLevel(mylevel);
        force = true; //reinit spells/passives/other
    }
    if (force)
    {
        InitPowers();
        InitSpells(); //this must stay before class passives
        ApplyClassPassives();
        InitHeals();
    }

    //INIT STATS
    //get base class stats, we'll need all this later
    sObjectMgr->GetPlayerClassLevelInfo(GetPlayerClass(), std::min<uint8>(mylevel, 80), _classinfo);

    if (force)
    {
        PlayerLevelInfo info;
        sObjectMgr->GetPlayerLevelInfo(GetPlayerRace(), GetPlayerClass(), std::min<uint8>(mylevel, 80), &info);
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
        //case DRUID_FLIGHT_FORM:
        case BOT_CLASS_BM:
        case BOT_CLASS_SPHYNX:
        case BOT_CLASS_ARCHMAGE:
        case BOT_CLASS_DREADLORD:
        case BOT_CLASS_SPELLBREAKER:
        case BOT_CLASS_DARK_RANGER:
            break;

        default:
            TC_LOG_ERROR("entities.player", "minion_ai: *etStats():Init - unknown bot class %u, real class: %u, _botclass: %u", myclass, GetPlayerClass(), _botclass);
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
        SpellShapeshiftEntry const* ssEntry = sSpellShapeshiftStore.LookupEntry(me->GetShapeshiftForm());
        if (!ssEntry || !ssEntry->attackSpeed)
            delay = _equips[BOT_SLOT_MAINHAND] ? _equips[BOT_SLOT_MAINHAND]->GetTemplate()->Delay : me->GetCreatureTemplate()->BaseAttackTime;
        else
            delay = ssEntry->attackSpeed;

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
        //case DRUID_FLIGHT_FORM:
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
            strmult = 0.f; agimult = 5.f; break;
        default:
            TC_LOG_ERROR("entities.player", "_MeleeDamageUpdate(): NIY myclass %u!", uint32(myclass));
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
        if (mylevel >= 35 && myclass == DRUID_CAT_FORM)
            ap_mod *= 1.1f;
        //Protector of the Pack part 2
        if (mylevel >= 45 && myclass == DRUID_BEAR_FORM)
            ap_mod *= 1.06f;
    }
    if (_botclass == BOT_CLASS_ROGUE)
    {
        //Deadliness
        if (mylevel >= 35)
            ap_mod *= 1.1f;
        //Savage Combat
        if (mylevel >= 50)
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
        if (me->GetLevel() >= 30)
            atpower += 0.3f * _getTotalBotStat(BOT_STAT_MOD_STAMINA);
    }
    if (_botclass == BOT_CLASS_SHAMAN)
    {
        //Mental Dexterity
        if (me->GetLevel() >= 30)
            atpower += _getTotalBotStat(BOT_STAT_MOD_INTELLECT);
    }
    if (_botclass == BOT_CLASS_DARK_RANGER)
    {
        atpower += 2.f * _getTotalBotStat(BOT_STAT_MOD_INTELLECT);
        if (me->GetLevel() >= 60)
            ap_mod *= 1.15f;
    }

    atpower *= ap_mod;
    me->SetStatFlatModifier(UNIT_MOD_ATTACK_POWER, BASE_VALUE, atpower);

    me->UpdateAttackPowerAndDamage();
    if (_botclass == BOT_CLASS_WARRIOR || _botclass == BOT_CLASS_HUNTER || _botclass == BOT_CLASS_ROGUE ||
        _botclass == BOT_CLASS_MAGE || _botclass == BOT_CLASS_PRIEST || _botclass == BOT_CLASS_WARLOCK ||
        _botclass == BOT_CLASS_DARK_RANGER)
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
                armor_mod += 0.33f + (me->GetShapeshiftForm() == FORM_BEAR ? 1.8 : 3.7f);
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
    }

    value *= armor_mod;
    me->SetStatFlatModifier(UNIT_MOD_ARMOR, BASE_VALUE, value);
    me->UpdateArmor(); //buffs will be processed here

    //RESISTANCES
    //Do not store resistance bonuses directly lest we want calcs screwed up
    for (uint8 i = SPELL_SCHOOL_HOLY; i != MAX_SPELL_SCHOOL; ++i)
    {
        value = IAmFree() ? 0 : mylevel;
        value += _getTotalBotStat(BOT_STAT_MOD_RESIST_HOLY + (i - 1));

        //res bonuses
        if (_botclass == BOT_CLASS_SPHYNX)
            value += mylevel * 5; //total 498 at 83
        if (_botclass == BOT_CLASS_DREADLORD)
            value += mylevel * 3; //total 332 at 83
        if (_botclass == BOT_CLASS_DARK_RANGER)
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
    if (_botclass == BOT_CLASS_ROGUE && mylevel >= 45)
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
        if (mylevel >= 60)
            tempval -= 0.06f;
        //Improved Frost Presence
        if (mylevel >= 61 && GetBotStance() == DEATH_KNIGHT_FROST_PRESENCE)
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
        if (mylevel >= 35 && botPet && botPet->IsAlive())
        {
            if (GetAIMiscValue(BOTAI_MISC_PET_TYPE) == BOT_PET_VOIDWALKER)
                value -= 0.1f;
            else if (GetAIMiscValue(BOTAI_MISC_PET_TYPE) == BOT_PET_FELHUNTER)
                tempval -= 0.1f;
        }
    }
    //Frozen Core (everything), Prismatic Cloak part 1
    if (_botclass == BOT_CLASS_MAGE && mylevel >= 30)
    {
        if (mylevel >= 35)
            value -= 0.06f;
        tempval -= mylevel >= 35 ? 0.12f : 0.06f;
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

    dmg_taken_phy = value;
    dmg_taken_mag = tempval;

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

    value =  IAmFree() ? std::max<int32>(int32(mylevel) - 50, 0) : 0; // +30%/+0% haste at 80

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
        if (mylevel >= 30)      ratingBonus *= 4;

        tempval += (float)ratingBonus;
    }

    value += tempval * ((_botclass == BOT_CLASS_HUNTER || _botclass == BOT_CLASS_DARK_RANGER) ?
        _getRatingMultiplier(CR_HASTE_RANGED) :
        std::max<float>(_getRatingMultiplier(CR_HASTE_MELEE), _getRatingMultiplier(CR_HASTE_SPELL)));

    //class-specific
    if (_botclass == BOT_CLASS_HUNTER)
    {
        value += 15.f; //innate ranged haste bonus 15% for hunters (still applies to all haste types)
        //Serpent's Swiftness
        if (mylevel >= 45)
            value += 20.f;
    }
    if (_botclass == BOT_CLASS_ROGUE)
    {
        //Lightning Reflexes part 2
        if (mylevel >= 25)
            value += 10.f;
    }
    if (_botclass == BOT_CLASS_PRIEST)
    {
        //Enlightenment part 2
        if (mylevel >= 35)
            value += 6.f;
    }
    if (_botclass == BOT_CLASS_MAGE)
    {
        //Netherwind Presence
        if (mylevel >= 55)
            value += 6.f;
    }
    if (_botclass == BOT_CLASS_BM)
    {
        //Blademaster haste
        value += 70.f;
    }
    if (_botclass == BOT_CLASS_DREADLORD)
    {
        //Dreadlord haste
        value += 70.f;
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
        if (_botclass == BOT_CLASS_PALADIN && mylevel >= 55)
            value += 4.f;
        //Virulence part 1, Nerves of Cold Steel part 1
        if (_botclass == BOT_CLASS_DEATH_KNIGHT)
            value += 3.f;
        //Dual Wield Specialization
        if (_botclass == BOT_CLASS_SHAMAN && mylevel >= 40 && me->haveOffhandWeapon())
            value += 6.f;
        //Precision
        if (_botclass == BOT_CLASS_WARRIOR && mylevel >= 30)
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
    if (_botclass == BOT_CLASS_DEATH_KNIGHT && mylevel >= 64)
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
    if (mylevel >= 35 && _botclass == BOT_CLASS_ROGUE)
        value += 10.f;
    //Combat Expertise
    if (mylevel >= 45 && _botclass == BOT_CLASS_PALADIN)
        value += 6.f;
    if (_botclass == BOT_CLASS_WARRIOR)
    {
        //Vitality: 6, Strength of Arms: 4
        if (mylevel >= 45)
            value += 10.f;
        else if (mylevel >= 40)
            value += 4.f;
    }
    if (_botclass == BOT_CLASS_DEATH_KNIGHT)
    {
        //Tundra Stalker, Rage of Rivendare: 5 + 5
        //Veteral of the Third War part 3: 6
        if (mylevel >= 64)
            value += 16.f;
        else if (mylevel >= 59)
            value += 6.f;
    }
    if (_botclass == BOT_CLASS_DREADLORD)
    {
        value += 40.f;
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
            value += (critBaseMelee->base + _getTotalBotStat(BOT_STAT_MOD_AGILITY) * critRatioMelee->ratio) * 100.0f;

        //crit from intellect
        GtChanceToSpellCritBaseEntry const* critBaseSpell  = sGtChanceToSpellCritBaseStore.LookupEntry(GetPlayerClass()-1);
        GtChanceToSpellCritEntry const* critRatioSpell = sGtChanceToSpellCritStore.LookupEntry((GetPlayerClass()-1)*GT_MAX_LEVEL + mylevel-1);
        if (critBaseSpell && critRatioSpell)
            tempval += (critBaseSpell->base + _getTotalBotStat(BOT_STAT_MOD_INTELLECT) * critRatioSpell->ratio) * 100.f;

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
            if (mylevel >= 30)      ratingBonus *= 4;

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
                        mainhand->GetTemplate()->SubClass == ITEM_SUBCLASS_WEAPON_FIST))
                        value += 5.f;
                }
            }
        }
        if (_botclass == BOT_CLASS_PALADIN)
        {
            //Sanctity of Battle part 1
            if (mylevel >= 25)
                value += 3.f;
            //Combat Expertise
            if (mylevel >= 45)
                value += 6.f;
        }
        if (_botclass == BOT_CLASS_HUNTER)
        {
            //Killer Instinct
            if (mylevel >= 30)
                value += 3.f;
            //Master Marksman
            if (mylevel >= 45)
                value += 5.f;
        }
        if (_botclass == BOT_CLASS_PRIEST)
        {
            //Focused Will part 1
            if (mylevel >= 40)
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
            if (mylevel >= 45)
                value += 10.f;
        }
        if (_botclass == BOT_CLASS_MAGE)
        {
            //Arcane Instability part 2
            if (mylevel >= 35)
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
            float tempval = _getTotalBotStat(BOT_STAT_MOD_PARRY_RATING);
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
            value += _getTotalBotStat(BOT_STAT_MOD_AGILITY) * dodgeRatio->ratio * 100.0f;

        if (mylevel >= 10)
        {
            //53 DR = 1% dodge at 80
            float tempval = _getTotalBotStat(BOT_STAT_MOD_DODGE_RATING);
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
        float tempval = _getTotalBotStat(BOT_STAT_MOD_BLOCK_RATING);
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
        if (_botclass == BOT_CLASS_WARRIOR && mylevel >= 20)
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
            //Touched by the Light / Sheath of Light - 60% of strength (30% attack power) to spell power
            if (HasRole(BOT_ROLE_TANK | BOT_ROLE_DPS))
                value += 0.3f * me->GetTotalAttackPowerValue(BASE_ATTACK);
            //Holy Guidance - 20% Intellect to spell power
            if (HasRole(BOT_ROLE_HEAL) && HasRole(BOT_ROLE_RANGED))
                value += 0.2f * _getTotalBotStat(BOT_STAT_MOD_INTELLECT);
        }
        if (_botclass == BOT_CLASS_PRIEST && mylevel >= 30)
        {
            float totalSpi = _getTotalBotStat(BOT_STAT_MOD_SPIRIT);
            //Spiritual Guidance - 25% Spirit to spell power
            if (HasRole(BOT_ROLE_HEAL))
                value += 0.25f * totalSpi;
            //Twisted Faith - 20% Spirit to spell power
            else if (HasRole(BOT_ROLE_DPS) && mylevel >= 55)
                value += 0.2f * totalSpi;
            //Shadowy Insight (Glyph of Shadow)
            if (mylevel >= 30 &&
                me->GetAuraEffect(SPELL_AURA_MOD_SPELL_DAMAGE_OF_STAT_PERCENT, SPELLFAMILY_GENERIC, 1499, 0))
                value += 0.3f * totalSpi;
        }
        if (_botclass == BOT_CLASS_SHAMAN && mylevel >= 50)
        {
            //Mental Quickness - 30% attack power to spell power (only enhancement)
            if (HasRole(BOT_ROLE_DPS) && !HasRole(BOT_ROLE_RANGED))
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
        if (_botclass == BOT_CLASS_MAGE && mylevel >= 45)
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
            if (botPet && botPet->IsAlive() && mylevel >= 40)
                value += 0.12f * botPet->GetStat(STAT_STAMINA) + botPet->GetStat(STAT_INTELLECT);
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

        spellpower = uint32(value);
    }
    //else
    //{
    //    spellpower = 0;
    //}

    //if init or levelup
    if (force)
    {
        me->SetFullHealth();
        me->SetPower(POWER_MANA, me->GetMaxPower(POWER_MANA));
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
            SetBotCommandState(COMMAND_STAY);
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
            SetBotCommandState(COMMAND_FOLLOW, true);
            //BotWhisper("Following!", player);
            break;
        case TEXT_EMOTE_TICKLE:
        {
            if (master != player)
                break;

            if ((me->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_STUNNED) || me->HasUnitState(UNIT_STATE_STUNNED)) &&
                !me->HasAuraType(SPELL_AURA_MOD_STUN))
            {
                me->ClearUnitState(UNIT_STATE_STUNNED);
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_STUNNED);
            }
            if ((me->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_CONFUSED) || me->HasUnitState(UNIT_STATE_CONFUSED)) &&
                !me->HasAuraType(SPELL_AURA_MOD_CONFUSE))
            {
                me->ClearUnitState(UNIT_STATE_CONFUSED);
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_CONFUSED);
            }
            if ((me->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_FLEEING) || me->HasUnitState(UNIT_STATE_FLEEING)) &&
                !me->HasAuraType(SPELL_AURA_MOD_FEAR))
            {
                me->ClearUnitState(UNIT_STATE_FLEEING);
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_FLEEING);
            }
            std::ostringstream msg;
            msg << "%s (bot) pulls "
                << (me->GetGender() == GENDER_MALE ? "himself" : me->GetGender() == GENDER_FEMALE ? "herself" : "itself")
                << " together.";
            me->TextEmote(msg.str().c_str());
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
    if (!unit) return false;
    if (unit == master || unit == me || unit == botPet) return true;

    if (IAmFree())
    {
        if (me->GetFaction() == 14 || unit->GetFaction() == 14)
            return false;

        if (me->HasByteFlag(UNIT_FIELD_BYTES_2, 1, UNIT_BYTE2_FLAG_FFA_PVP) ||
            unit->HasByteFlag(UNIT_FIELD_BYTES_2, 1, UNIT_BYTE2_FLAG_FFA_PVP))
            return false;

        return
            (unit->GetTypeId() == TYPEID_PLAYER || unit->ToCreature()->IsPet() || unit->ToCreature()->IsNPCBot() || unit->ToCreature()->IsNPCBotPet()) &&
            (unit->GetFaction() == me->GetFaction() ||
            (me->GetReactionTo(unit) >= REP_FRIENDLY && unit->GetReactionTo(me) >= REP_FRIENDLY));
    }

    //cheap check
    if (Group const* gr = master->GetGroup())
    {
        //group member case
        if (gr->IsMember(unit->GetGUID()))
            return true;
        //pointed target case
        for (uint8 i = 0; i != TARGETICONCOUNT; ++i)
            if (_healTargetIconFlags & GroupIconsFlags[i])
                if (ObjectGuid guid = gr->GetTargetIcons()[i])//check this one
                    if (guid == unit->GetGUID())
                        return true;
    }

    //Player-controlled creature case
    if (Creature const* cre = unit->ToCreature())
    {
        ObjectGuid ownerGuid = unit->GetOwnerGUID();
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

//REFRESHAURA
//Applies/removes/reapplies aura stacks
void bot_ai::RefreshAura(uint32 spellId, int8 count, Unit* target) const
{
    if (count < 0 || count > 1)
    {
        TC_LOG_ERROR("entities.player", "bot_ai::RefreshAura(): count is out of bounds (%i) for bot %s (botclass: %u, entry: %u)",
            int32(count), me->GetName().c_str(), uint32(_botclass), me->GetEntry());
        return;
    }

    if (!spellId)
    {
        TC_LOG_ERROR("entities.player", "bot_ai::RefreshAura(): spellId is 0 for bot %s (botclass: %u, entry: %u)",
            me->GetName().c_str(), uint32(_botclass), me->GetEntry());
        return;
    }

    SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(spellId);
    if (!spellInfo)
    {
        TC_LOG_ERROR("entities.player", "bot_ai::RefreshAura(): Invalid spellInfo for spell %u! Bot - %s (botclass: %u, entry: %u)",
            spellId, me->GetName().c_str(), uint32(_botclass), me->GetEntry());
        return;
    }

    if (!target)
        target = me;

    target->RemoveAurasDueToSpell(spellId);

    //for (int8 i = 0; i < count; ++i)
    if (count)
        target->AddAura(spellInfo, MAX_EFFECT_MASK, target);
}

bool bot_ai::CanBotAttack(Unit const* target, int8 byspell) const
{
    if (!target)
        return false;
    if (!_botPvP && !IAmFree() && target->IsControlledByPlayer())
        return false;
    if (me->GetFaction() == 35 && IAmFree() && target->GetTypeId() == TYPEID_UNIT && target->GetVictim() != me)
        return false;
    if (target->GetFaction() == 35 && me->GetFaction() != 14)
        return false;
    uint8 followdist = IAmFree() ? BotMgr::GetBotFollowDistDefault() : master->GetBotMgr()->GetBotFollowDist();
    float foldist = _getAttackDistance(float(followdist));

    SpellSchoolMask mainMask;
    if (!byspell)
        mainMask = SPELL_SCHOOL_MASK_NORMAL;
    else
    {
        switch (_botclass)
        {
            case BOT_CLASS_PRIEST:      mainMask = SPELL_SCHOOL_MASK_SHADOW;                                                                break;
            case BOT_CLASS_SHAMAN:      mainMask = Rand() > 50 && me->GetLevel() >= 70 ? SPELL_SCHOOL_MASK_FIRE : SPELL_SCHOOL_MASK_NATURE; break;
            case BOT_CLASS_MAGE:        mainMask = Rand() > 50 ? SPELL_SCHOOL_MASK_FIRE : SPELL_SCHOOL_MASK_FROST;                          break;
            case BOT_CLASS_WARLOCK:     mainMask = Rand() > 50 ? SPELL_SCHOOL_MASK_SHADOW : SPELL_SCHOOL_MASK_FIRE;                         break;
            case BOT_CLASS_DRUID:       mainMask = Rand() > 50 ? SPELL_SCHOOL_MASK_ARCANE : SPELL_SCHOOL_MASK_NATURE;                       break;
            case BOT_CLASS_SPHYNX:      mainMask = SPELL_SCHOOL_MASK_NONE;                                                                  break;
            case BOT_CLASS_ARCHMAGE:    mainMask = SPELL_SCHOOL_MASK_NONE;                                                                 break;
            case BOT_CLASS_DREADLORD:   mainMask = SPELL_SCHOOL_MASK_NONE;                                                                 break;
            case BOT_CLASS_SPELLBREAKER:mainMask = SPELL_SCHOOL_MASK_NONE;                                                                 break;
            case BOT_CLASS_DARK_RANGER: mainMask = SPELL_SCHOOL_MASK_NONE;                                                                 break;
            default:                    mainMask = SPELL_SCHOOL_MASK_NORMAL;                                                                break;
        }
    }

    return
       (target->IsAlive() && target->IsVisible() && me->IsValidAttackTarget(target) &&
       ((me->CanSeeOrDetect(target) && target->InSamePhase(me)) || CanSeeEveryone()) &&
       //!target->HasStealthAura() && !target->HasInvisibilityAura() &&
       (!master->IsAlive() || target->IsControlledByPlayer() ||
       (target->GetDistance(master) < foldist && me->GetDistance(master) < followdist)) &&//if master is killed pursue to the end
        target->isTargetableForAttack() && !IsInBotParty(target) &&
        (target->IsHostileTo(master) ||
        (target->GetReactionTo(master) < REP_FRIENDLY/* && master->GetVictim() == target*/ && (master->IsInCombat() || target->IsInCombat())) ||//master has pointed this target
        target->IsHostileTo(me)) &&//if master is controlled
        //target->IsWithinLOSInMap(me) &&
        (byspell == -1 || !target->IsTotem()) &&
        (byspell == -1 || !mainMask || !target->IsImmunedToDamage(mainMask)));
}
//GETTARGET
//Returns attack target or 'no target'
//All code above 'x = _getTarget() call must not dereference opponent since it can be invalid
Unit* bot_ai::_getTarget(bool byspell, bool ranged, bool &reset) const
{
    //if (_evadeMode) //IAmFree() case only
    //    return nullptr;

    Unit* mytar = me->GetVictim();

    //check if no need to change target
    //TC_LOG_ERROR("entities.player", "bot_ai::getTarget(): bot: %s", me->GetName().c_str());

    if (mytar && me->HasAuraType(SPELL_AURA_MOD_TAUNT))
        return mytar;

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
        //TC_LOG_ERROR("entities.player", "bot %s continues attack common target %s", me->GetName().c_str(), u->GetName().c_str());
        return u;//forced
    }
    //Follow if...
    uint8 followdist = IAmFree() ? BotMgr::GetBotFollowDistDefault() : master->GetBotMgr()->GetBotFollowDist();
    float foldist = _getAttackDistance(float(followdist));
    if ((!u || IAmFree()) && master->IsAlive() && (me->GetDistance(master) > foldist ||
        (IAmFree() && mytar && me->GetDistance(mytar) > followdist) ||
        (mytar && master->GetDistance(mytar) > followdist / 2 && !mytar->IsWithinLOSInMap(me)) ||
        (mytar && master->GetDistance(mytar) > foldist && me->GetDistance(master) > foldist)))
    {
        //TC_LOG_ERROR("entities.player", "bot %s cannot attack target %s, too far away or not in LoS", me->GetName().c_str(), mytar ? mytar->GetName().c_str() : "");
        return nullptr;
    }

    if (u && !IAmFree() && (master->IsInCombat() || u->IsInCombat())/* && !InDuel(u)*/ && !IsInBotParty(u) && (_botPvP || !u->IsControlledByPlayer()))
    {
        //TC_LOG_ERROR("entities.player", "bot %s starts attack master's target %s", me->GetName().c_str(), u->GetName().c_str());
        return u;
    }

    if (mytar && (!IAmFree() || me->GetDistance(mytar) < BOT_MAX_CHASE_RANGE) && CanBotAttack(mytar, byspell) &&/* !InDuel(mytar) &&*/
        !(mytar->GetVictim() != nullptr && IsTank() && IsTank(mytar->GetVictim())))
    {
        //TC_LOG_ERROR("entities.player", "bot %s continues attack its target %s", me->GetName().c_str(), mytar->GetName().c_str());
        if (me->GetDistance(mytar) > (ranged ? 20.f : 5.f) && m_botCommandState != COMMAND_STAY && m_botCommandState != COMMAND_FOLLOW)
            reset = true;
        return mytar;
    }

    if (followdist == 0 && master->IsAlive())
        return nullptr; //do not bother

    //check group
    if (!IAmFree())
    {
        Group const* gr = master->GetGroup();
        if (!gr)
        {
            Creature const* bot;
            BotMap const* map = master->GetBotMgr()->GetBotMap();
            for (BotMap::const_iterator itr = map->begin(); itr != map->end(); ++itr)
            {
                bot = itr->second;
                if (!bot || !bot->InSamePhase(me) || bot == me) continue;
                if (IsTank() && IsTank(bot)) continue;
                u = bot->GetVictim();
                if (u && (bot->IsInCombat() || u->IsInCombat()) &&
                    (!master->IsAlive() || master->GetDistance(u) < foldist) &&
                    CanBotAttack(u, byspell))
                {
                    //TC_LOG_ERROR("entities.player", "bot %s hooked %s's victim %s", me->GetName().c_str(), bot->GetName().c_str(), u->GetName().c_str());
                    return u;
                }
            }
        }
        else
        {
            Player const* pl;
            Creature const* bot;
            for (GroupReference const* ref = gr->GetFirstMember(); ref != nullptr; ref = ref->next())
            {
                pl = ref->GetSource();
                if (!pl || !pl->IsInWorld() || pl->IsBeingTeleported()) continue;
                if (me->GetMap() != pl->FindMap() || !pl->InSamePhase(me)) continue;
                if (IsTank() && IsTank(pl)) continue;
                u = pl->GetVictim();
                if (u && pl != master &&
                    (pl->IsInCombat() || u->IsInCombat()) &&
                    (!master->IsAlive() || master->GetDistance(u) < foldist) &&
                    CanBotAttack(u, byspell))
                {
                    //TC_LOG_ERROR("entities.player", "bot %s hooked %s's victim %s", me->GetName().c_str(), pl->GetName().c_str(), u->GetName().c_str());
                    return u;
                }
                if (!pl->HaveBot()) continue;
                BotMap const* map = pl->GetBotMgr()->GetBotMap();
                for (BotMap::const_iterator it = map->begin(); it != map->end(); ++it)
                {
                    bot = it->second;
                    if (!bot || !bot->InSamePhase(me) || bot == me) continue;
                    if (!bot->IsInWorld()) continue;
                    if (me->GetMap() != bot->FindMap()) continue;
                    if (IsTank() && IsTank(bot)) continue;
                    u = bot->GetVictim();
                    if (u && (bot->IsInCombat() || u->IsInCombat()) &&
                        (!master->IsAlive() || master->GetDistance(u) < foldist) &&
                        CanBotAttack(u, byspell))
                    {
                        //TC_LOG_ERROR("entities.player", "bot %s hooked %s's victim %s", me->GetName().c_str(), bot->GetName().c_str(), u->GetName().c_str());
                        return u;
                    }
                }
            }
        }
    }

    //check targets around
    Unit* t = nullptr;
    float maxdist = InitAttackRange(float(followdist), ranged);
    //first cycle we search non-cced target, then, if not found, check all
    for (uint8 i = 0; i != 2; ++i)
    {
        if (!t)
        {
            bool attackCC = i;
            NearestHostileUnitCheck check(me, maxdist, byspell, this, attackCC);
            Trinity::UnitLastSearcher <NearestHostileUnitCheck> searcher(master, t, check);
            Cell::VisitAllObjects(master, searcher, maxdist);
            //me->VisitNearbyObject(maxdist, searcher);
        }
    }

    if (t && opponent && t != opponent)
        reset = true;

    //Allow free bots to ignore temp invulnerabilities if no other target is present
    if (IAmFree() && t == nullptr)
        t = mytar;

    //if (t)
    //    TC_LOG_ERROR("entities.player", "bot %s has found new target %s", me->GetName().c_str(), t->GetName().c_str());

    return t;
}
//'CanAttack' function
//Only called in class ai UpdateAI function
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
                //case DRUID_FLIGHT_FORM:
                    ranged = true;
                    break;
                case DRUID_MOONKIN_FORM:
                    byspell = true;
                    break;
                case BOT_STANCE_NONE:
                    byspell = ranged && HasRole(BOT_ROLE_DPS);
                    break;
                default:
                    TC_LOG_ERROR("entities.player", "bot_ai::CheckAttackTarget(): druid has NYI bot stance %u", uint32(GetBotStance()));
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
            break;
        default:
            TC_LOG_ERROR("entities.player", "bot_ai: CheckAttackTarget() - unknown bot class %u", _botclass);
            return false;
    }

    opponent = _getTarget(byspell, ranged, reset);

    if (!opponent)
    {
        //TC_LOG_ERROR("entities.player", "bot_ai: CheckAttackTarget() - bot %s lost target", me->GetName().c_str());
        if (me->GetVictim() || me->IsInCombat()/* || !me->GetThreatManager().isThreatListEmpty()*/)
        {
            //TC_LOG_ERROR("entities.player", "bot_ai: CheckAttackTarget() - bot %s Evades", me->GetName().c_str());
            if (me->GetVictim())
                me->AttackStop();
            else if (me->IsInCombat())
                Evade();
        }

        return false;
    }

    //boss engage phase // CanHaveThreatList checks for typeid == UNIT
    if (!IsTank() && opponent != me->GetVictim() && opponent->CanHaveThreatList() &&
        opponent->ToCreature()->GetCreatureTemplate()->rank == CREATURE_ELITE_WORLDBOSS && me->GetMap()->IsRaid())
    {
        Unit* supposedTank = opponent->GetVictim();
        if (supposedTank && uint32(opponent->ToCreature()->GetThreatManager().GetThreat(supposedTank)) < supposedTank->GetMaxHealth())
            return false;
    }

    if (reset)
        m_botCommandState = COMMAND_ABANDON;//reset AttackStart()

    if (opponent != me->GetVictim())
        me->Attack(opponent, !ranged);

    return true;
}
//POSITION
//Returns attack range based on given range
//If mounted: 20%
//If ranged: 125%
//If master is dead: max range
float bot_ai::InitAttackRange(float origRange, bool ranged) const
{
    /*if (IAmFree())
        origRange = sWorld->GetMaxVisibleDistanceOnContinents();
    else */if (!master->IsAlive())
        origRange = sWorld->GetMaxVisibleDistanceOnContinents();
    else if (me->HasAuraType(SPELL_AURA_MOUNTED))
        origRange *= 0.2f;
    else if (ranged)
        origRange *= 1.25f;

    return origRange;
}
//Ranged attack position
void bot_ai::CalculateAttackPos(Unit const* target, Position& pos) const
{
    uint8 followdist = IAmFree() ? BotMgr::GetBotFollowDistDefault() : master->GetBotMgr()->GetBotFollowDist();
    uint8 rangeMode = IAmFree() ? BOT_ATTACK_RANGE_LONG : master->GetBotMgr()->GetBotAttackRangeMode();
    uint8 exactRange = rangeMode != BOT_ATTACK_RANGE_EXACT || IAmFree() ? 255 : master->GetBotMgr()->GetBotExactAttackRange();
    float x(0),y(0),z(0),
        dist = (rangeMode == BOT_ATTACK_RANGE_EXACT) ? exactRange :
        followdist >= 40 ? followdist :
        _botclass == BOT_CLASS_HUNTER ?
        8 + urand(followdist/2, followdist/2 + 5) :/*23-33 at 40, 18-28 at 30*/
        5 + urand(followdist/3, followdist/3 + 5)/*18-23 at 40, 15-20 at 30*/,
        angle = target->GetAbsoluteAngle(me);
    bool boss = target->GetTypeId() == TYPEID_UNIT &&
        (target->ToCreature()->isWorldBoss() || target->ToCreature()->IsDungeonBoss() || target->ToCreature()->GetCreatureTemplate()->rank == CREATURE_ELITE_WORLDBOSS);
    //most ranged classes have some sort of 20yd spell
    if (rangeMode != BOT_ATTACK_RANGE_EXACT)
        dist = std::min<float>(dist, GetSpellAttackRange(rangeMode == BOT_ATTACK_RANGE_LONG) - 4.f);
    if (target->HasInArc(M_PI/2, me) && (target->m_movementInfo.GetMovementFlags() & MOVEMENTFLAG_FORWARD))
        dist = std::min<float>(dist + 10, 30);

    float clockwise = (me->GetEntry() % 2) ? 1.f : -1.f;
    float angleDelta1 = ((IsTank(master) && !IsTank(me)) ? frand(M_PI*0.40f, M_PI*0.60f) : frand(0.0f, M_PI*0.15f)) * clockwise;
    float angleDelta2 = frand(0.0f, M_PI*0.08f) * clockwise;
    if (boss && IsTank())
        angle += M_PI*(IsMelee() ? 0.5f : 0.33f);

    for (uint8 i = 0; i < 5; ++i)
    {
        target->GetNearPoint(me, x, y, z, dist, Position::NormalizeOrientation(angle));
        bool toofaraway = master->GetDistance(x,y,z) > (followdist > 38.f ? 38.f : followdist < 20 ? 20.f : float(followdist));
        bool outoflos = !target->IsWithinLOS(x,y,z);
        if (!toofaraway && !outoflos)
            break;

        if (toofaraway)
        {
            angle = target->GetAbsoluteAngle(master);
            if (i >= 3)
                angle += angleDelta1;
            if (i >= 1 && i <= 3)
                dist = std::max<float>(0.f, dist - 5.f);
        }
        if (outoflos)
        {
            if (rangeMode != BOT_ATTACK_RANGE_EXACT)
                dist *= i >= 3 ? 0.1f : 0.33f;
            if (i >= 4 && IAmFree())
                angle += angleDelta2;
        }
    }

    pos.m_positionX = x;
    pos.m_positionY = y;
    pos.m_positionZ = z;
}
// Forces bot to chase opponent (if ranged then distance depends on follow distance)
void bot_ai::GetInPosition(bool force, Unit* newtarget, Position* mypos)
{
    if (CCed(me, true) || JumpingOrFalling())
        return;
    if (!newtarget)
        newtarget = me->GetVictim();
    if (!newtarget)
        return;
    if ((!newtarget->IsInCombat() || m_botCommandState == COMMAND_STAY || (me->isMoving()/* && Rand() > 50*/)) && !force)
        return;
    if (IsCasting())
        return;
    if (IsShootingWand() && newtarget->GetVictim() == me)
        return;
    if (UpdateImpossibleChase(newtarget))
        return;

    if (!IAmFree() && master->GetBotMgr()->GetBotAttackRangeMode() == BOT_ATTACK_RANGE_EXACT &&
        master->GetBotMgr()->GetBotExactAttackRange() == 0)
    {
        attackpos.m_positionX = newtarget->GetPositionX() - frand(0.5f, 1.5f) * std::cos(me->GetAbsoluteAngle(newtarget));
        attackpos.m_positionY = newtarget->GetPositionY() - frand(0.5f, 1.5f) * std::sin(me->GetAbsoluteAngle(newtarget));
        attackpos.m_positionZ = newtarget->GetPositionZ();
        if (me->GetExactDist2d(&attackpos) > 3.5f)
            me->GetMotionMaster()->MovePoint(newtarget->GetMapId(), attackpos);
        return;
    }

    uint8 followdist = IAmFree() ? BotMgr::GetBotFollowDistDefault() : master->GetBotMgr()->GetBotFollowDist();
    if (HasRole(BOT_ROLE_RANGED))
    {
        //do not allow constant runaway from player
        if (!force && newtarget->GetTypeId() == TYPEID_PLAYER &&
            me->GetDistance(newtarget) < 6 + urand(followdist/4, followdist/3))
            return;

        if (!mypos)
            CalculateAttackPos(newtarget, attackpos);
        else
        {
            attackpos.m_positionX = mypos->m_positionX;
            attackpos.m_positionY = mypos->m_positionY;
            attackpos.m_positionZ = mypos->m_positionZ;
        }
        if (me->GetExactDist2d(&attackpos) > 4.f || !me->IsWithinLOSInMap(newtarget))
        {
            me->GetMotionMaster()->MovePoint(newtarget->GetMapId(), attackpos);
            if (!me->HasUnitState(UNIT_STATE_MELEE_ATTACKING))
                me->SetInFront(newtarget);
        }
    }
    else if (!JumpingOrFalling() && ((!me->HasUnitState(UNIT_STATE_CHASE) && !me->isMoving()) || (!me->HasUnitState(UNIT_STATE_CHASE_MOVE) && me->GetDistance(newtarget) > 1.5f)))
        me->GetMotionMaster()->MoveChase(newtarget);

    if (newtarget != me->GetVictim())
    {
        if (!me->Attack(newtarget, !HasRole(BOT_ROLE_RANGED)))
            me->SetInFront(newtarget);
    }
}

void bot_ai::CheckAttackState()
{
    if (me->GetVictim())
    {
        if (HasRole(BOT_ROLE_DPS) && !me->HasAuraType(SPELL_AURA_MOD_STEALTH) && !me->HasAuraType(SPELL_AURA_MOD_INVISIBILITY) &&
            !IsShootingWand())
            DoMeleeAttackIfReady();
    }
    else
        Evade();
}

void bot_ai::MoveBehind(Unit const* target) const
{
    if (HasRole(BOT_ROLE_RANGED) || (IsTank() && target->GetVictim() == me) || CCed(me, true)) return;
    if (JumpingOrFalling()) return;
    if (((_botclass == BOT_CLASS_ROGUE || GetBotStance() == DRUID_CAT_FORM) ?
        target->GetVictim() != me || CCed(target) || target->GetTypeId() == TYPEID_PLAYER :
        target->GetVictim() != me && !CCed(target))      &&
        target->IsWithinCombatRange(me, ATTACK_DISTANCE) &&
        target->HasInArc(M_PI, me))
    {
        float x(0),y(0),z(0);
        target->GetNearPoint(me, x, y, z, me->GetCombatReach(), target->GetAbsoluteAngle(me) + M_PI);
        me->GetMotionMaster()->MovePoint(me->GetMapId(), x, y, z);
        const_cast<bot_ai*>(this)->waitTimer = 500;
    }
}
//MOUNT SUPPORT
void bot_ai::_updateMountedState()
{
    if (IAmFree())
        return;
    //if (GetBotCommandState() != COMMAND_FOLLOW)
    //    return;

    bool aura = me->HasAuraType(SPELL_AURA_MOUNTED);
    bool mounted = me->IsMounted() && (_botclass != BOT_CLASS_ARCHMAGE || aura);

    //allow dismount
    if (!CanMount() && !aura && !mounted)
        return;

    if ((!master->IsMounted() || aura != mounted || (me->IsInCombat() && opponent)) && (aura || mounted))
    {
        const_cast<CreatureTemplate*>(me->GetCreatureTemplate())->Movement.Flight = CreatureFlightMovementType::None;
        me->SetCanFly(false);
        me->SetDisableGravity(false);
        me->RemoveAurasByType(SPELL_AURA_MOUNTED);
        me->Dismount();
        me->RemoveUnitMovementFlag(MOVEMENTFLAG_FALLING|MOVEMENTFLAG_FALLING_FAR|MOVEMENTFLAG_PITCH_UP|MOVEMENTFLAG_PITCH_DOWN|MOVEMENTFLAG_SPLINE_ELEVATION|MOVEMENTFLAG_FALLING_SLOW);
        me->BotStopMovement();
        return;
    }
    if (me->IsInCombat() || IsCasting()/* || me->HasUnitMovementFlag(MOVEMENTFLAG_SWIMMING)*/)
        return;

    if (master->IsMounted() && !me->IsMounted() && !master->IsInCombat() && !me->IsInCombat() && !me->GetVictim())
    {
        uint32 mount = 0;
        Unit::AuraEffectList const &mounts = master->GetAuraEffectsByType(SPELL_AURA_MOUNTED);
        if (!mounts.empty())
        {
            //Winter Veil addition
            if (sGameEventMgr->IsActiveEvent(GAME_EVENT_WINTER_VEIL))
                mount = master->CanFly() ? REINDEER_FLY : REINDEER;
            else
                mount = mounts.front()->GetId();
        }
        if (mount)
        {
            if (me->HasAuraType(SPELL_AURA_MOUNTED))
                me->RemoveAurasByType(SPELL_AURA_MOUNTED);

            //me->RemoveAurasWithInterruptFlags(AURA_INTERRUPT_FLAG_NOT_MOUNTED);

            //if (!GetSpell(mount))
            //    InitSpellMap(mount, true); //learn

            me->BotStopMovement();
            if (_botclass == BOT_CLASS_DRUID && me->GetShapeshiftForm() != FORM_NONE)
                const_cast<bot_ai*>(this)->removeShapeshiftForm();
            if (doCast(me, mount))
            { }

            //RemoveSpell(mount);
        }
    }
}
//STANDSTATE
void bot_ai::_updateStandState() const
{
    if (IAmFree())
    {
        if (CanSit())
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
        else if (me->IsSitState() && !(me->GetInterruptMask() & AURA_INTERRUPT_FLAG_NOT_SEATED))
            me->SetStandState(UNIT_STAND_STATE_STAND);

        return;
    }

    if ((master->GetStandState() == UNIT_STAND_STATE_STAND || !CanSit()) &&
        me->GetStandState() == UNIT_STAND_STATE_SIT &&
        !(me->GetInterruptMask() & AURA_INTERRUPT_FLAG_NOT_SEATED))
        me->SetStandState(UNIT_STAND_STATE_STAND);
    if (CanSit() && !me->IsInCombat() && !me->isMoving() &&
        (master->GetStandState() == UNIT_STAND_STATE_SIT || (me->GetInterruptMask() & AURA_INTERRUPT_FLAG_NOT_SEATED)) &&
        me->GetStandState() == UNIT_STAND_STATE_STAND)
        me->SetStandState(UNIT_STAND_STATE_SIT);
}
//RATIONS
void bot_ai::_updateRations()
{
    bool noFeast = me->IsInCombat() || (_botMovementFoodInterrupt && me->isMoving()) || me->GetVictim() || CCed(me);

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
        !me->IsInCombat() && !IsCasting() && GetManaPCT(me) < 75 && urand(0, 100) < 20)
    {
        //me->SetStandState(UNIT_STAND_STATE_SIT);
        CastSpellExtraArgs args(TRIGGERED_FULL_MASK);
        me->CastSpell(me, GetRation(true), args);
    }

    //eat
    if (!feast_health && !me->HasAuraType(SPELL_AURA_MOUNTED) && !me->isMoving() && CanEat() &&
        !me->IsInCombat() && !IsCasting() && GetHealthPCT(me) < 80 && urand(0, 100) < 20)
    {
        //me->SetStandState(UNIT_STAND_STATE_SIT);
        CastSpellExtraArgs args(TRIGGERED_FULL_MASK);
        me->CastSpell(me, GetRation(false), args);
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
            int32 add = me->IsInCombat() ? 0 : IAmFree() && !me->GetVictim() ? me->GetMaxHealth() / 32 : 5 + me->GetCreateHealth() / 256;
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

            addvalue *= sWorld->getRate(RATE_POWER_MANA) * REGEN_CD * 0.001f; //regenTimer threshold / 1000

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
            me->UpdateUInt32Value(UNIT_FIELD_POWER1 + POWER_ENERGY, curValue);
    }
}

bool bot_ai::Feasting() const
{
    if (!(me->GetInterruptMask() & AURA_INTERRUPT_FLAG_NOT_SEATED))
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
        TC_LOG_ERROR("entities.player", "bot_ai::FindAffectedTarget(): hostile = %u Setting to ALL...", hostile);
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

    return Trinity::Containers::SelectRandomContainerElement(unitList);
}
// Returns target for dest AOE spell (blizzard, hurricane, etc.) based on crowd size, movement state and direction
Unit* bot_ai::FindAOETarget(float dist) const
{
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
            !(*itr)->HasInArc(M_PI*0.75f, (*itr)->GetVictim())))
            continue;

        if (!unit && (*itr)->GetVictim() && (*itr)->GetDistance((*itr)->GetVictim()) < dist * 0.334f)
        {
            unit = *itr;
            continue;
        }
        if (!unit)
        {
            float destDist = me->GetDistance((*itr)->GetPositionX(), (*itr)->GetPositionY(), (*itr)->GetPositionZ());
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
                        if (me->GetDistance(*it) < me->GetDistance(unit) && unit->HasInArc(M_PI/2, me))
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

    ManaDrainUnitCheck check(me, maxdist);
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
        TC_LOG_ERROR("entities.player", "InitSpell(): No SpellInfo found for spell %u", spell);
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
        TC_LOG_ERROR("entities.player", "bot_ai::InitSpellMap(): No SpellInfo found for base spell %u", basespell);
        return; //invalid spell id
    }

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
}
//Using first-rank spell as source, return current spell id
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
        ((itr->second->enabled == true || IAmFree()) && itr->second->spellId != 0 && itr->second->cooldown <= diff);
}
//Using first-rank spell as source, sets cooldown for current spell
void bot_ai::SetSpellCooldown(uint32 basespell, uint32 msCooldown)
{
    //if (!msCooldown)
    //    return;

    BotSpellMap::iterator itr = _spells.find(basespell);
    if (itr != _spells.end())
    {
        itr->second->cooldown = msCooldown;
        return;
    }
    else if (!msCooldown)
        return;

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
        return;

    SpellInfo const* info;
    for (BotSpellMap::iterator itr = _spells.begin(); itr != _spells.end(); ++itr)
    {
        //skip spell which has triggered this category cooldown
        if (itr->first == spellInfo->Id && itr->second->cooldown >= msCooldown)
            continue;

        info = sSpellMgr->GetSpellInfo(itr->second->spellId);
        if (info && info->GetCategory() == category && itr->second->cooldown < msCooldown)
            itr->second->cooldown = msCooldown;
    }
}
//Handles spell cooldowns for spell with IsCooldownStartedOnEvent() == true
void bot_ai::ReleaseSpellCooldown(uint32 basespell)
{
    SpellInfo const* baseInfo = sSpellMgr->GetSpellInfo(basespell);

    if (!baseInfo->IsCooldownStartedOnEvent())
    {
        TC_LOG_ERROR("spells", "bot_ai::ReleaseSpellCooldown is called for wrong spell %u!", basespell);
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
//See CommonTimers(uint32)
void bot_ai::SpellTimers(uint32 diff)
{
    // spell must be initialized!!!
    for (BotSpellMap::iterator itr = _spells.begin(); itr != _spells.end(); ++itr)
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
                    TC_LOG_ERROR("entities.player", "RaceSpellForClass(): unknows race:class combo %u, %u", uint32(myrace), uint32(myclass));
                    return 0;
            }
            break;
        default:
            TC_LOG_ERROR("entities.player", "RaceSpellForClass(): unknows race:class combo %u, %u", uint32(myrace), uint32(myclass));
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
    //TC_LOG_ERROR("entities.player", "_OnHealthUpdate(): updating bot %s", me->GetName().c_str());
    float pct = me->GetHealth() == me->GetMaxHealth() ? 100.f : me->GetHealthPct(); // needs for regeneration
    uint32 m_basehp = _classinfo->basehealth;
    //TC_LOG_ERROR("entities.player", "class base health: %u", m_basehp);
    me->SetCreateHealth(m_basehp);

    float stamValue = _getTotalBotStat(BOT_STAT_MOD_STAMINA);

    stamValue -= std::min<float>(me->GetCreateStat(STAT_STAMINA), 20.f); //not a mistake
    stamValue = std::max<float>(stamValue, 0.f);

    //TC_LOG_ERROR("entities.player", "bot's stats to health add: Stamina (%f), value: %f", stamValue, stamValue * 10.f);
    float hp_add = stamValue * 10.f + 20; //20 is not a mistake;
    //hp_add += IAmFree() ? mylevel * 375.f : 0; //+30000/+0 hp at 80
    hp_add += _getTotalBotStat(BOT_STAT_MOD_HEALTH);
    //TC_LOG_ERROR("entities.player", "health to add after stam mod: %i", hp_add);
    uint32 m_totalhp = m_basehp + int32(hp_add); //m_totalhp = uint32(float(m_basehp + hp_add) * stammod);
    //TC_LOG_ERROR("entities.player", "total base health: %u", m_totalhp);

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
    //Dreadlord's vitality
    if (_botclass == BOT_CLASS_DREADLORD)
        bonuspct += 20;
    if (bonuspct)
        m_totalhp = (m_totalhp * (100 + bonuspct)) / 100;

    //m_totalhp = float(uint32(m_totalhp) - (uint32(m_totalhp) % 10));
    me->SetStatFlatModifier(UNIT_MOD_HEALTH, BASE_VALUE, float(m_totalhp)); //replaces base hp at max lvl
    me->UpdateMaxHealth(); //will use our values we just set (update base health and buffs)
    //TC_LOG_ERROR("entities.player", "overall hp: %u", me->GetMaxHealth());
    me->SetHealth(pct == 100.f ? me->GetMaxHealth() : uint32(0.5f + float(me->GetMaxHealth()) * pct / 100.f)); //restore pct
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

    //TC_LOG_ERROR("entities.player", "_OnManaUpdate(): updating bot %s", me->GetName().c_str());
    float pct = me->GetPower(POWER_MANA) == me->GetMaxPower(POWER_MANA) ? 100.f :
        (float(me->GetPower(POWER_MANA)) * 100.f) / float(me->GetMaxPower(POWER_MANA));
    float m_basemana = _classinfo->basemana;
    if (_botclass == BOT_CLASS_BM)
        m_basemana = BASE_MANA_1_BM + (BASE_MANA_10_BM - BASE_MANA_1_BM) * (mylevel/81.f);
    if (_botclass == BOT_CLASS_SPHYNX)
        m_basemana = BASE_MANA_SPHYNX;
    if (_botclass == BOT_CLASS_ARCHMAGE)
        m_basemana = BASE_MANA_1_ARCHMAGE + (BASE_MANA_10_ARCHMAGE - BASE_MANA_1_ARCHMAGE) * ((mylevel - 20)/81.f);
    if (_botclass == BOT_CLASS_DREADLORD)
        m_basemana = BASE_MANA_1_DREADLORD + (BASE_MANA_10_DREADLORD - BASE_MANA_1_DREADLORD) * ((mylevel - 60)/83.f);
    if (_botclass == BOT_CLASS_SPELLBREAKER)
        m_basemana = BASE_MANA_SPELLBREAKER;
    if (_botclass == BOT_CLASS_DARK_RANGER)
        m_basemana = BASE_MANA_1_DARK_RANGER + (BASE_MANA_10_DARK_RANGER - BASE_MANA_1_DARK_RANGER) * ((mylevel - 40)/82.f);
    //TC_LOG_ERROR("entities.player", "classinfo base mana = %f", m_basemana);

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
    me->SetPower(POWER_MANA, pct == 100.f ? me->GetMaxPower(POWER_MANA) :
        uint32(0.5f + float(me->GetMaxPower(POWER_MANA)) * pct / 100.f)); //restore pct

    _OnManaRegenUpdate();
}
//Mana regen for minions
void bot_ai::_OnManaRegenUpdate() const
{
    //regen_normal
    uint8 mylevel = me->GetLevel();
    float value = IAmFree() ? mylevel/2 : 0; //200/0 mp5 at 80

    float power_regen_mp5;
    int32 modManaRegenInterrupt;
    if (_botclass < BOT_CLASS_EX_START)
    {
        // Mana regen from spirit and intellect
        float spiregen = 0.001f;
        if (GtRegenMPPerSptEntry const* moreRatio = sGtRegenMPPerSptStore.LookupEntry((_botclass-1)*GT_MAX_LEVEL + mylevel-1))
            spiregen = moreRatio->ratio * _getTotalBotStat(BOT_STAT_MOD_SPIRIT);

        // PCT bonus from SPELL_AURA_MOD_POWER_REGEN_PERCENT aura on spirit base regen
        value += sqrt(_getTotalBotStat(BOT_STAT_MOD_INTELLECT)) * spiregen * me->GetTotalAuraMultiplierByMiscValue(SPELL_AURA_MOD_POWER_REGEN_PERCENT, POWER_MANA);
        // regen from SPELL_AURA_MOD_POWER_REGEN aura (per second)
        power_regen_mp5 = 0.2f * (me->GetTotalAuraModifierByMiscValue(SPELL_AURA_MOD_POWER_REGEN, POWER_MANA) + _getTotalBotStat(BOT_STAT_MOD_MANA_REGENERATION));
        if (IAmFree())
            power_regen_mp5 += float(mylevel);
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
            else
                basemana = 0.f;

            value = basemana * 0.0087f + 0.08f * GetTotalBotStat(BOT_STAT_MOD_INTELLECT);
            value += 0.2f * (me->GetTotalAuraModifierByMiscValue(SPELL_AURA_MOD_POWER_REGEN, POWER_MANA) + _getTotalBotStat(BOT_STAT_MOD_MANA_REGENERATION));
            value *= me->GetTotalAuraMultiplierByMiscValue(SPELL_AURA_MOD_POWER_REGEN_PERCENT, POWER_MANA);
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
        else
            value = 0;

        if (IAmFree())
            value += float(mylevel);
    }
    //Unrelenting Storm, Dreamstate: 12% of intellect as mana regen always (divided by 5)
    if (_botclass == BOT_CLASS_SHAMAN || _botclass == BOT_CLASS_DRUID)
        power_regen_mp5 += 0.024f * _getTotalBotStat(BOT_STAT_MOD_INTELLECT);

    me->SetStatFloatValue(UNIT_FIELD_POWER_REGEN_INTERRUPTED_FLAT_MODIFIER, power_regen_mp5 + CalculatePct(value, modManaRegenInterrupt));
    me->SetStatFloatValue(UNIT_FIELD_POWER_REGEN_FLAT_MODIFIER, power_regen_mp5 + value);
}
//Bots cannot dodge/parry from behind so try to condense enemies at front
//opponent is always valid
void bot_ai::AdjustTankingPosition() const
{
    //problem: chasing unit is constantly moving. Whoever the hell did that
//    if (/*!IsTank() || */!me->IsInCombat() || me->isMoving() || IsCasting() ||
//        JumpingOrFalling() || CCed(me, true) || Rand() > 10 + 20*me->GetMap()->IsDungeon())
//        return;
    if (/*!IsTank() || */!me->IsInCombat() || IsCasting() ||
        JumpingOrFalling() || CCed(me, true) || Rand() > 10 + 20*me->GetMap()->IsDungeon())
        return;

    Unit::AttackerSet const& myattackers = me->getAttackers();
    if (myattackers.size() < 2)
        return;

    //TC_LOG_ERROR("entities.player", "AdjustTankingPosition() by %s", me->GetName().c_str());

    uint32 bCount = 0;
    for (Unit::AttackerSet::const_iterator itr = myattackers.begin(); itr != myattackers.end(); ++itr)
    {
        if (/*!CCed(*itr) && */(*itr)->GetDistance(me) < 5 && !me->HasInArc(M_PI, *itr))
            ++bCount;
            //if (++bCount)
            //    break;
    }

    if (bCount == 0)
        return;

    //TC_LOG_ERROR("entities.player", "AdjustTankingPosition(): atts %u, behind %u", uint32(myattackers.size()), bCount);

    //calculate new position
    float x = me->GetPositionX();
    float y = me->GetPositionY();
    float z = me->GetPositionZ();
    float ori = CCed(opponent, true) ? me->GetOrientation() + 0.75f * M_PI : me->GetOrientation();
    float const moveDist = -1.f * std::max<float>(opponent->GetCombatReach() * 0.6f, 3.f);
    float moveX;
    float moveY;
    //bool move = false;
    for (uint8 i = 0; i != 3; ++i)
    {
        if (i)
        {
            ori = Position::NormalizeOrientation(ori + (i+1)*(M_PI*0.5f));
        }

        //move back
        moveX = moveDist * std::cos(ori);
        moveY = moveDist * std::sin(ori);

        if (me->IsWithinLOS(x+moveX, y+moveY, z))
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

    //if (CCed(opponent, true))
    //    me->AttackStop();
    //me->SetOrientation(ori);
    //me->BotStopMovement();
    me->GetMotionMaster()->MovePoint(me->GetMapId(), x, y, z, false);
    //TC_LOG_ERROR("entities.player", "AdjustTankingPosition(): moving %s from %.2f %.2f to %.2f %.2f",
    //    me->GetName().c_str(), me->GetPositionX(), me->GetPositionY(), x, y);
}
//SpellHit()... OnSpellHit()
void bot_ai::OnSpellHit(Unit* caster, SpellInfo const* spell)
{
    //uint32 const spellId = spell->Id;

    if (spell->HasAura(SPELL_AURA_MOD_TAUNT) || spell->HasEffect(SPELL_EFFECT_ATTACK_ME))
        if (caster && me->Attack(caster, !HasRole(BOT_ROLE_RANGED)))
        {}//me->GetMotionMaster()->MoveChase(caster);

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

    for (uint8 i = 0; i != MAX_SPELL_EFFECTS; ++i)
    {
        uint32 const auraname = spell->Effects[i].ApplyAuraName;
        //remove pet on mount
        if (auraname == SPELL_AURA_MOUNTED)
        {
            //TC_LOG_ERROR("entities.unit", "OnSpellHit: mount on %s", me->GetName().c_str());
            UnsummonAll();
            if (master->HasAuraType(SPELL_AURA_MOD_INCREASE_VEHICLE_FLIGHT_SPEED) ||
                master->HasAuraType(SPELL_AURA_MOD_INCREASE_MOUNTED_FLIGHT_SPEED))
            {
                //TC_LOG_ERROR("entities.unit", "OnSpellHit: modding flight speed");
                const_cast<CreatureTemplate*>(me->GetCreatureTemplate())->Movement.Flight = CreatureFlightMovementType::CanFly;
                me->SetCanFly(true);
                me->SetDisableGravity(true);
                if (Aura* mount = me->GetAura(spell->Id))
                {
                    //TC_LOG_ERROR("entities.unit", "OnSpellHit: found aura");
                    for (uint8 j = 0; j != MAX_SPELL_EFFECTS; ++j)
                    {
                        if (spell->Effects[j].ApplyAuraName != SPELL_AURA_MOD_INCREASE_VEHICLE_FLIGHT_SPEED &&
                            spell->Effects[j].ApplyAuraName != SPELL_AURA_MOD_INCREASE_MOUNTED_FLIGHT_SPEED &&
                            spell->Effects[j].ApplyAuraName != SPELL_AURA_MOD_INCREASE_MOUNTED_SPEED)
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

        uint32 const effect = spell->Effects[i].Effect;
        if (effect == SPELL_EFFECT_RESURRECT || effect == SPELL_EFFECT_RESURRECT_NEW || effect == SPELL_EFFECT_SELF_RESURRECT)
        {
            //resurrect effects are not handled for creatures
            if (!me->IsAlive())
            {
                uint32 health = 0;
                uint32 mana = 0;
                int32 damage = spell->Effects[i].BasePoints;

                if (effect == SPELL_EFFECT_RESURRECT_NEW)
                {
                    //Glyph of Rebirth: resurrect with 100% health
                    if (spell->IsRankOf(sSpellMgr->GetSpellInfo(20484)))
                        health = me->GetMaxHealth();
                    else
                        health = damage;
                    mana = spell->Effects[i].MiscValue;
                }
                else if (damage < 0)
                {
                    health = uint32(-damage);
                    mana = spell->Effects[i].MiscValue;
                }
                else
                {
                    health = me->CountPctFromMaxHealth(damage);
                    if (me->GetMaxPower(POWER_MANA) > 1)
                        mana = CalculatePct(me->GetMaxPower(POWER_MANA), damage);
                }
                me->Relocate(caster);
                me->SetUInt32Value(UNIT_NPC_FLAGS, me->GetCreatureTemplate()->npcflag);
                me->ClearUnitState(uint32(UNIT_STATE_ALL_STATE));
                me->RemoveFlag(UNIT_FIELD_FLAGS, uint32(-1));
                me->setDeathState(ALIVE);
                me->SetPvP(master->IsPvP());
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_PLAYER_CONTROLLED);

                me->SetHealth(health);
                if (me->GetMaxPower(POWER_MANA) > 1)
                    me->SetPower(POWER_MANA, mana);

                shouldUpdateStats = true;
            }
        }
        //ravasaur poison (EffectEnchantHeldItem) for mh and oh
        if (effect == SPELL_EFFECT_ENCHANT_HELD_ITEM)
        {
            uint32 enchant_id = spell->Effects[i].MiscValue;
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
//Update delay
//Skip UpdateAI cycles for randomization of bots' reaction and performance adjustments
bool bot_ai::Wait()
{
    if (waitTimer > lastdiff || !master->IsInWorld())
        return true;

    if (IAmFree())
        waitTimer = me->IsInCombat() ? 500 : urand(750, 1250);
    else if (!master->GetMap()->IsRaid())
        waitTimer = std::min<uint32>(uint32(50 * (master->GetNpcBotsCount() - 1) + __rand + __rand), 500);
    else
        waitTimer = __rand;

    waitTimer += _npcBotUpdateDelayBase;

    return false;
}
//Spell Mod Hooks
void bot_ai::ApplyBotDamageMultiplierMelee(uint32& damage, CalcDamageInfo& damageinfo) const
{
    //WHITE ATTACKS damage bonus
    ApplyClassDamageMultiplierMelee(damage, damageinfo);
}
void bot_ai::ApplyBotDamageMultiplierMelee(int32& damage, SpellNonMeleeDamage& damageinfo, SpellInfo const* spellInfo, WeaponAttackType attackType, bool crit) const
{
    //MELEE ABILITIES damage bonus (DMG_CLASS != DMG_CLASS_MAGIC)
    ApplyClassDamageMultiplierMelee(damage, damageinfo, spellInfo, attackType, crit);
}
void bot_ai::ApplyBotDamageMultiplierSpell(int32& damage, SpellNonMeleeDamage& damageinfo, SpellInfo const* spellInfo, WeaponAttackType attackType, bool crit) const
{
    //DAMAGE SPELLS damage bonus (DMG_CLASS_MAGIC)
    ApplyClassDamageMultiplierSpell(damage, damageinfo, spellInfo, attackType, crit);
}
void bot_ai::ApplyBotDamageMultiplierHeal(Unit const* victim, float& heal, SpellInfo const* spellInfo, DamageEffectType damagetype, uint32 stack) const
{
    //HEALING SPELLS amount bonus
    ApplyClassDamageMultiplierHeal(victim, heal, spellInfo, damagetype, stack);
    heal = (heal * _mult_healing);
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
void bot_ai::ApplyBotEffectMods(Unit const* target, SpellInfo const* spellInfo, uint8 effIndex, float& value) const
{
    //ALL SPELLS SPELLMOD_EFFECT_X bonus (target-specific)
    ApplyClassEffectMods(target, spellInfo, effIndex, value);
}
//Spell Mod Utilities
float bot_ai::CalcSpellMaxRange(uint32 spellId, bool enemy) const
{
    SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(spellId);
    //ASSERT(spellInfo);

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
    if (!BotMgr::IsNpcBotModEnabled() || !BotMgr::IsClassEnabled(_botclass) ||
        IsTempBot() || me->IsInCombat() || CCed(me) || IsCasting() || IsDuringTeleport())
    {
        player->PlayerTalkClass->SendCloseGossip();
        return true;
    }

    if (me->isMoving())
        me->BotStopMovement();

    uint32 gossipTextId;
    if (!IAmFree())
    {
        if (_botclass == BOT_CLASS_SPHYNX)
            gossipTextId = GOSSIP_NORMAL_CUSTOM_SPHYNX;
        else if (_botclass == BOT_CLASS_DREADLORD)
            gossipTextId = GOSSIP_NORMAL_CUSTOM_DREADLORD;
        else if (_botclass == BOT_CLASS_DARK_RANGER)
            gossipTextId = GOSSIP_NORMAL_CUSTOM_DARKRANGER;
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
        else
            gossipTextId = GOSSIP_GREET_NEED_SMTH;
    }

    bool menus = false;

    if (player->IsGameMaster())
    {
        AddGossipItemFor(player, GOSSIP_ICON_CHAT, "<Debug>", GOSSIP_SENDER_DEBUG, GOSSIP_ACTION_INFO_DEF + 1);
        menus = true;
    }

    if (player->GetGUID().GetCounter() != _ownerGuid)
    {
        if (IAmFree())
        {
            uint32 cost = BotMgr::GetNpcBotCost(player->GetLevel(), me);

            int8 reason = 0;
            if (me->HasAura(BERSERK))
                reason = -1;
            if (!reason && _ownerGuid)
                reason = 1;
            if (!reason && player->GetNpcBotsCount() >= BotMgr::GetMaxNpcBots())
                reason = 2;
            if (!reason && !player->HasEnoughMoney(cost))
                reason = 3;

            if (!reason && _maxClassNpcBots && player->HaveBot())
            {
                uint8 count = 0;
                BotMap const* map = player->GetBotMgr()->GetBotMap();
                for (BotMap::const_iterator itr = map->begin(); itr != map->end(); ++itr)
                    if (itr->second->GetBotClass() == _botclass)
                        ++count;

                if (!reason && count >= _maxClassNpcBots)
                    reason = 4;
            }

            std::ostringstream message1;
            std::ostringstream message2;
            if (_botclass == BOT_CLASS_SPHYNX)
            {
                message1 << "Are you sure you want to risk drawing " << me->GetName() << "'s attention?";
                message2 << "<Insert Coin>";
            }
            else if (_botclass == BOT_CLASS_DREADLORD)
            {
                message1 << "Do you want to entice " << me->GetName() << '?';
                message2 << "<Try to make an offering>";
            }
            else
            {
                message1 << "Do you wish to hire " << me->GetName() << '?';
                message2 << "<Hire bot>";
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
            AddGossipItemFor(player, GOSSIP_ICON_TALK, "Manage equipment...", GOSSIP_SENDER_EQUIPMENT, GOSSIP_ACTION_INFO_DEF + 1);
            AddGossipItemFor(player, GOSSIP_ICON_TALK, "Manage roles...", GOSSIP_SENDER_ROLES_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
            AddGossipItemFor(player, GOSSIP_ICON_TALK, "Manage formation...", GOSSIP_SENDER_FORMATION, GOSSIP_ACTION_INFO_DEF + 1);
            AddGossipItemFor(player, GOSSIP_ICON_TALK, "Manage abilities...", GOSSIP_SENDER_ABILITIES, GOSSIP_ACTION_INFO_DEF + 1);
            if (_botclass < BOT_CLASS_EX_START)
                AddGossipItemFor(player, GOSSIP_ICON_TALK, "Give consumable...", GOSSIP_SENDER_USEITEM, GOSSIP_ACTION_INFO_DEF + 1);

            if (!gr)
            {
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "<Create group>", GOSSIP_SENDER_JOIN_GROUP, GOSSIP_ACTION_INFO_DEF + 1);
                if (player->GetNpcBotsCount() > 1)
                    AddGossipItemFor(player, GOSSIP_ICON_CHAT, "<Create group (all bots)>", GOSSIP_SENDER_JOIN_GROUP, GOSSIP_ACTION_INFO_DEF + 2);
            }
            else if (!gr->IsMember(me->GetGUID()))
            {
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "<Add to group>", GOSSIP_SENDER_JOIN_GROUP, GOSSIP_ACTION_INFO_DEF + 1);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "<Add all bots to group>", GOSSIP_SENDER_JOIN_GROUP, GOSSIP_ACTION_INFO_DEF + 2);
            }
            else
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "<Remove from group>", GOSSIP_SENDER_LEAVE_GROUP, GOSSIP_ACTION_INFO_DEF + 1);
        }
        if (player == master || (gr && gr->IsMember(master->GetGUID())))
        {
            //class-specific for party: mage rations, rogue lockpicking etc.
            //TODO: priest lightwell (manual only) maybe move into abilities
            switch (_botclass)
            {
                case BOT_CLASS_MAGE:
                {
                    AddGossipItemFor(player, GOSSIP_ICON_CHAT, "I need food", GOSSIP_SENDER_CLASS, GOSSIP_ACTION_INFO_DEF + 1);
                    AddGossipItemFor(player, GOSSIP_ICON_CHAT, "I need water", GOSSIP_SENDER_CLASS, GOSSIP_ACTION_INFO_DEF + 2);
                    if (me->GetLevel() >= 70)
                        AddGossipItemFor(player, GOSSIP_ICON_CHAT, "I need a refreshment table", GOSSIP_SENDER_CLASS, GOSSIP_ACTION_INFO_DEF + 3);
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
                        msg << "Help me pick a lock (" << uint32(me->GetLevel() * 5) << ")";
                        AddGossipItemFor(player, GOSSIP_ICON_CHAT, msg.str().c_str(), GOSSIP_SENDER_CLASS, GOSSIP_ACTION_INFO_DEF + 1);
                        menus = true;
                    }
                    break;
                }
                case BOT_CLASS_WARLOCK:
                {
                    AddGossipItemFor(player, GOSSIP_ICON_CHAT, "I need your your healthstone", GOSSIP_SENDER_CLASS, GOSSIP_ACTION_INFO_DEF + 1);
                    if (me->GetLevel() >= 68)
                        AddGossipItemFor(player, GOSSIP_ICON_CHAT, "I need a soulwell", GOSSIP_SENDER_CLASS, GOSSIP_ACTION_INFO_DEF + 3);
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
                case BOT_CLASS_ROGUE:
                {
                    if (me->GetLevel() >= 20)
                    {
                        AddGossipItemFor(player, GOSSIP_ICON_CHAT, "I need you to refresh poisons", GOSSIP_SENDER_CLASS, GOSSIP_ACTION_INFO_DEF + 2);
                        AddGossipItemFor(player, GOSSIP_ICON_TALK, "<Choose poison (Main Hand)>", GOSSIP_SENDER_CLASS, GOSSIP_ACTION_INFO_DEF + 3);
                        Item const* oweap = _equips[BOT_SLOT_OFFHAND];
                        if (oweap && oweap->GetTemplate()->Class == ITEM_CLASS_WEAPON)
                            AddGossipItemFor(player, GOSSIP_ICON_TALK, "<Choose poison (Offhand)>", GOSSIP_SENDER_CLASS, GOSSIP_ACTION_INFO_DEF + 4);
                    }
                    break;
                }
                case BOT_CLASS_SHAMAN:
                {
                    if (me->GetLevel() >= 10)
                    {
                        AddGossipItemFor(player, GOSSIP_ICON_CHAT, "I need you to refresh enchants", GOSSIP_SENDER_CLASS, GOSSIP_ACTION_INFO_DEF + 2);
                        AddGossipItemFor(player, GOSSIP_ICON_TALK, "<Choose enchant (Main Hand)>", GOSSIP_SENDER_CLASS, GOSSIP_ACTION_INFO_DEF + 3);
                        Item const* oweap = _equips[BOT_SLOT_OFFHAND];
                        if (oweap && oweap->GetTemplate()->Class == ITEM_CLASS_WEAPON)
                            AddGossipItemFor(player, GOSSIP_ICON_TALK, "<Choose enchant (Offhand)>", GOSSIP_SENDER_CLASS, GOSSIP_ACTION_INFO_DEF + 4);
                    }
                    AddGossipItemFor(player, GOSSIP_ICON_CHAT, "I need you to remove shapeshift", GOSSIP_SENDER_CLASS, GOSSIP_ACTION_INFO_DEF + 5);
                    break;
                }
                case BOT_CLASS_DRUID:
                {
                    AddGossipItemFor(player, GOSSIP_ICON_CHAT, "I need you to remove shapeshift", GOSSIP_SENDER_CLASS, GOSSIP_ACTION_INFO_DEF + 1);
                    break;
                }
                case BOT_CLASS_HUNTER:
                {
                    if (me->GetLevel() >= 10)
                        AddGossipItemFor(player, GOSSIP_ICON_CHAT, "<Choose pet type>", GOSSIP_SENDER_CLASS, GOSSIP_ACTION_INFO_DEF + 2);

                    break;
                }
                case BOT_CLASS_WARLOCK:
                {
                    AddGossipItemFor(player, GOSSIP_ICON_CHAT, "<Choose pet type>", GOSSIP_SENDER_CLASS, GOSSIP_ACTION_INFO_DEF + 2);
                    break;
                }
                default:
                    break;
            }

            std::ostringstream astr;
            astr << "Are you going to abandon " << me->GetName() << "? You may regret it...";
            player->PlayerTalkClass->GetGossipMenu().AddMenuItem(-1, GOSSIP_ICON_TAXI, "You are dismissed",
                GOSSIP_SENDER_DISMISS, GOSSIP_ACTION_INFO_DEF + 1, astr.str().c_str(), 0, false);

            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Pull yourself together, damnit", GOSSIP_SENDER_TROUBLESHOOTING, GOSSIP_ACTION_INFO_DEF + 1);
        }
    }

    if (_botclass >= BOT_CLASS_EX_START)
    {
        menus = true;
        AddGossipItemFor(player, GOSSIP_ICON_CHAT, "<Study the creature>", GOSSIP_SENDER_SCAN, GOSSIP_ACTION_INFO_DEF + 1);
    }

    if (!menus)
    {
        player->PlayerTalkClass->SendCloseGossip();
        return true;
    }

    AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Nevermind", 0, GOSSIP_ACTION_INFO_DEF + 1);
    player->PlayerTalkClass->SendGossipMenu(gossipTextId, me->GetGUID());
    return true;
}

//GossipSelect
bool bot_ai::OnGossipSelect(Player* player, Creature* creature/* == me*/, uint32 sender, uint32 action)
{
    //if (!IsInBotParty(player))
    //{
    //    player->PlayerTalkClass->SendCloseGossip();
    //    return true;
    //}

    if (!BotMgr::IsNpcBotModEnabled() || me->HasUnitState(UNIT_STATE_CASTING) || CCed(me) || IsDuringTeleport())
    {
        player->PlayerTalkClass->SendCloseGossip();
        return true;
    }

    uint32 gossipTextId;
    if (!IAmFree())
    {
        if (_botclass == BOT_CLASS_SPHYNX)
            gossipTextId = GOSSIP_NORMAL_CUSTOM_SPHYNX;
        else if (_botclass == BOT_CLASS_DREADLORD)
            gossipTextId = GOSSIP_NORMAL_CUSTOM_DREADLORD;
        else if (_botclass == BOT_CLASS_DARK_RANGER)
            gossipTextId = GOSSIP_NORMAL_CUSTOM_DARKRANGER;
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
                            std::string errorstr = "I can't conjure ";
                            errorstr += iswater ? "water" : "food";
                            errorstr += " yet";
                            BotWhisper(errorstr.c_str(), player);
                            //player->PlayerTalkClass->ClearMenus();
                            //return OnGossipHello(player, me);
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
                            BotWhisper("I can't do it right now", player);
                        }
                        else
                        {
                            aftercastTargetGuid = player->GetGUID();
                            foodspell->prepare(targets);
                            BotWhisper("Here you go...", player);
                        }
                        break;
                    }
                    else if (option == 3) //refreshment table
                    {
                        uint32 tableSpellId = GetSpell(43987); //Ritual of Refreshment
                        if (!tableSpellId)
                        {
                            BotWhisper("Disabled", player);
                            break;
                        }
                        if (!IsSpellReady(43987, GetLastDiff(), false))
                        {
                            BotWhisper("Not ready yet", player);
                            break;
                        }
                        uint32 tableGOForSpell = (tableSpellId == 43987 ? GO_REFRESHMENT_TABLE_1 : GO_REFRESHMENT_TABLE_2);
                        GameObjectTemplate const* goInfo = sObjectMgr->GetGameObjectTemplate(tableGOForSpell);
                        if (!goInfo)
                        {
                            BotWhisper("Invalid object type", player);
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
                            BotWhisper("Failed to create table", player);
                            break;
                        }

                        SetSpellCooldown(43987, 300000);

                        table->SetRespawnTime(180);
                        //table->SetOwnerGUID(master->GetGUID());
                        master->AddGameObject(table);
                        table->SetSpellId(tableSpellId);
                        me->GetMap()->AddToMap(table);

                        BotWhisper("Done", player);
                        break;
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
                            msg << obj->GetGOInfo()->name << " (dist = " << player->GetExactDist(obj) << ")";
                            AddGossipItemFor(player, GOSSIP_ICON_CHAT, msg.str().c_str(), GOSSIP_SENDER_CLASS_ACTION, GOSSIP_ACTION_INFO_DEF + ++count);
                        }

                        //2 Inventory
                        Item* item = nullptr;
                        LockEntry const* lockInfo;

                        //backpack
                        for (uint8 i = INVENTORY_SLOT_ITEM_START; i != INVENTORY_SLOT_ITEM_END; i++)
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
                                        AddGossipItemFor(player, GOSSIP_ICON_CHAT, name.str().c_str(), GOSSIP_SENDER_CLASS_ACTION, GOSSIP_ACTION_INFO_DEF + item->GetGUID().GetCounter());
                                        break;
                                    }
                                }
                            }
                        }
                        //bags
                        for (uint8 i = INVENTORY_SLOT_BAG_START; i != INVENTORY_SLOT_BAG_END; i++)
                        {
                            if (Bag const* bag = player->GetBagByPos(i))
                            {
                                for (uint32 j = 0; j != bag->GetBagSize() && count <= maxcounter; j++)
                                {
                                    item = player->GetItemByPos(i, j);
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
                                                AddGossipItemFor(player, GOSSIP_ICON_CHAT, name.str().c_str(), GOSSIP_SENDER_CLASS_ACTION, GOSSIP_ACTION_INFO_DEF + item->GetGUID().GetCounter());
                                                ++count;
                                                break;
                                            }
                                        }
                                    }
                                }
                            }
                        }

                        AddGossipItemFor(player, GOSSIP_ICON_CHAT, "BACK", 1, GOSSIP_ACTION_INFO_DEF + ++count);
                    }
                    else if (action == 2)
                    {
                        //Clear poisons (autorefresh is in class ai DoNonCombatActions
                        RemoveItemClassEnchants();
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
                                AddGossipItemFor(player, same ? GOSSIP_ICON_BATTLE : GOSSIP_ICON_CHAT, availableInfo->SpellName[0], GOSSIP_SENDER_CLASS_ACTION2, GOSSIP_ACTION_INFO_DEF + possiblePoison);
                            }
                        }
                        AddGossipItemFor(player, isauto ? GOSSIP_ICON_BATTLE : GOSSIP_ICON_CHAT, "<Auto>", GOSSIP_SENDER_CLASS_ACTION2, GOSSIP_ACTION_INFO_DEF + 0);
                        AddGossipItemFor(player, GOSSIP_ICON_CHAT, "BACK", 1, GOSSIP_ACTION_INFO_DEF + 1);
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
                                AddGossipItemFor(player, same ? GOSSIP_ICON_BATTLE : GOSSIP_ICON_CHAT, availableInfo->SpellName[0], GOSSIP_SENDER_CLASS_ACTION3, GOSSIP_ACTION_INFO_DEF + possiblePoison);
                            }
                        }
                        AddGossipItemFor(player, isauto ? GOSSIP_ICON_BATTLE : GOSSIP_ICON_CHAT, "<Auto>", GOSSIP_SENDER_CLASS_ACTION3, GOSSIP_ACTION_INFO_DEF + 0);
                        AddGossipItemFor(player, GOSSIP_ICON_CHAT, "BACK", 1, GOSSIP_ACTION_INFO_DEF + 1);
                    }

                    break;
                }
                case BOT_CLASS_SHAMAN:
                {
                    action -= GOSSIP_ACTION_INFO_DEF;

                    if (action == 2)
                    {
                        //Clear enchants (autorefresh is in class ai DoNonCombatActions
                        RemoveItemClassEnchants();
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
                                AddGossipItemFor(player, same ? GOSSIP_ICON_BATTLE : GOSSIP_ICON_CHAT, availableInfo->SpellName[0], GOSSIP_SENDER_CLASS_ACTION2, GOSSIP_ACTION_INFO_DEF + possibleEnchant);
                            }
                        }
                        AddGossipItemFor(player, isauto ? GOSSIP_ICON_BATTLE : GOSSIP_ICON_CHAT, "<Auto>", GOSSIP_SENDER_CLASS_ACTION2, GOSSIP_ACTION_INFO_DEF + 0);
                        AddGossipItemFor(player, GOSSIP_ICON_CHAT, "BACK", 1, GOSSIP_ACTION_INFO_DEF + 1);
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
                                AddGossipItemFor(player, same ? GOSSIP_ICON_BATTLE : GOSSIP_ICON_CHAT, availableInfo->SpellName[0], GOSSIP_SENDER_CLASS_ACTION3, GOSSIP_ACTION_INFO_DEF + possibleEnchant);
                            }
                        }
                        AddGossipItemFor(player, isauto ? GOSSIP_ICON_BATTLE : GOSSIP_ICON_CHAT, "<Auto>", GOSSIP_SENDER_CLASS_ACTION3, GOSSIP_ACTION_INFO_DEF + 0);
                        AddGossipItemFor(player, GOSSIP_ICON_CHAT, "BACK", 1, GOSSIP_ACTION_INFO_DEF + 1);
                    }
                    else if (action == 5)
                    {
                        if (me->GetShapeshiftForm() == FORM_NONE)
                        {
                            BotWhisper("I am not shapeshifted", player);
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
                                if (possibleType >= BOT_PET_EXOTIC_START && me->GetLevel() < 80)
                                    continue;

                                std::string name;
                                if (possibleType == BOT_PET_CUNNING_START)
                                {
                                    name = "Random (Cunning)";
                                    possibleType = urand(BOT_PET_CUNNING_START, BOT_PET_CUNNING_END);
                                }
                                else if (possibleType == BOT_PET_FEROCITY_START)
                                {
                                    name = "Random (Ferocity)";
                                    possibleType = urand(BOT_PET_FEROCITY_START, BOT_PET_FEROCITY_END);
                                }
                                else if (possibleType == BOT_PET_TENACITY_START)
                                {
                                    name = "Random (Tenacity)";
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
                        AddGossipItemFor(player, noPet ? GOSSIP_ICON_BATTLE : GOSSIP_ICON_CHAT, "<None>", GOSSIP_SENDER_CLASS_ACTION4, GOSSIP_ACTION_INFO_DEF + BOT_PET_INVALID);
                        AddGossipItemFor(player, GOSSIP_ICON_CHAT, "<Auto>", GOSSIP_SENDER_CLASS_ACTION4, GOSSIP_ACTION_INFO_DEF + 0);
                        AddGossipItemFor(player, GOSSIP_ICON_CHAT, "BACK", 1, GOSSIP_ACTION_INFO_DEF + 1);
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
                        AddGossipItemFor(player, noPet ? GOSSIP_ICON_BATTLE : GOSSIP_ICON_CHAT, "<None>", GOSSIP_SENDER_CLASS_ACTION4, GOSSIP_ACTION_INFO_DEF + BOT_PET_INVALID);
                        AddGossipItemFor(player, GOSSIP_ICON_CHAT, "<Auto>", GOSSIP_SENDER_CLASS_ACTION4, GOSSIP_ACTION_INFO_DEF + 0);
                        AddGossipItemFor(player, GOSSIP_ICON_CHAT, "BACK", 1, GOSSIP_ACTION_INFO_DEF + 1);
                    }
                    else if (action == 1)
                    {
                        if (GetAIMiscValue(6201) == 0)
                        {
                            BotWhisper("I don't have a healthstone", player);
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
                            BotWhisper("I can't create healthstones yet!", player);
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
                            BotWhisper("Disabled", player);
                            break;
                        }
                        if (!IsSpellReady(29893, GetLastDiff(), false))
                        {
                            BotWhisper("Not ready yet", player);
                            break;
                        }
                        uint32 wellGOForSpell = (wellSpellId == 29893 ? GO_SOULWELL_1 : GO_SOULWELL_2);
                        GameObjectTemplate const* goInfo = sObjectMgr->GetGameObjectTemplate(wellGOForSpell);
                        if (!goInfo)
                        {
                            BotWhisper("Invalid object type", player);
                            break;
                        }
                        float x,y,z;
                        me->GetClosePoint(x, y, z, me->GetCombatReach(), 0.f, 0.f);
                        QuaternionData rot = QuaternionData::fromEulerAnglesZYX(me->GetOrientation(), 0.f, 0.f);

                        GameObject* soulwell = new GameObject;
                        if (!soulwell->Create(me->GetMap()->GenerateLowGuid<HighGuid::GameObject>(), wellGOForSpell, me->GetMap(),
                            me->GetPhaseMask(), Position(x,y,z,me->GetOrientation()), rot, 255, GO_STATE_READY))                        {
                            delete soulwell;
                            BotWhisper("Failed to create soulwell", player);
                            break;
                        }

                        SetSpellCooldown(29893, 300000);

                        soulwell->SetRespawnTime(180);
                        //soulwell->SetOwnerGUID(master->GetGUID());
                        master->AddGameObject(soulwell);
                        soulwell->SetSpellId(wellSpellId);
                        me->GetMap()->AddToMap(soulwell);

                        BotWhisper("Done", player);
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
                        BotWhisper("I am not shapeshifted", player);
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
        case GOSSIP_SENDER_CLASS_ACTION:
        {
            switch (_botclass)
            {
                case BOT_CLASS_ROGUE:
                {
                    if (!IsCasting())
                    {
                        // Pick Lock
                        uint32 picklock = InitSpell(me, 1804);
                        if (!picklock)
                        {
                            BotWhisper("WTF I don't have lockpicking!", player);
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
                            for (uint8 i = INVENTORY_SLOT_ITEM_START; i != INVENTORY_SLOT_ITEM_END; i++)
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
                                for (uint8 i = INVENTORY_SLOT_BAG_START; i != INVENTORY_SLOT_BAG_END; i++)
                                {
                                    if (Bag const* bag = player->GetBagByPos(i))
                                    {
                                        for (uint32 j = 0; j != bag->GetBagSize(); j++)
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
                                BotWhisper("My skill level in not high enough", player);
                            else
                                BotWhisper("Failed", player);
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
                trans->SetDuration(500);
                trans->SetMaxDuration(500);
            }
            break;
        }
        case GOSSIP_SENDER_EQUIPMENT: //equips change s1: send what slots we can use
        {
            subMenu = true;

            //general
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Show me your inventory", GOSSIP_SENDER_EQUIPMENT_LIST, GOSSIP_ACTION_INFO_DEF + 1);

            //auto-equip
            AddGossipItemFor(player, GOSSIP_ICON_TALK, "Auto-equip...", GOSSIP_SENDER_EQUIP_AUTOEQUIP, GOSSIP_ACTION_INFO_DEF + 1);

            //weapons
            AddGossipItemFor(player, GOSSIP_ICON_TALK, "Main hand...", GOSSIP_SENDER_EQUIPMENT_SHOW, GOSSIP_ACTION_INFO_DEF + BOT_SLOT_MAINHAND);
            if (_canUseOffHand())
                AddGossipItemFor(player, GOSSIP_ICON_TALK, "Off-hand...", GOSSIP_SENDER_EQUIPMENT_SHOW, GOSSIP_ACTION_INFO_DEF + BOT_SLOT_OFFHAND);
            if (_canUseRanged())
                AddGossipItemFor(player, GOSSIP_ICON_TALK, "Ranged...", GOSSIP_SENDER_EQUIPMENT_SHOW, GOSSIP_ACTION_INFO_DEF + BOT_SLOT_RANGED);
            if (_canUseRelic())
                AddGossipItemFor(player, GOSSIP_ICON_TALK, "Relic...", GOSSIP_SENDER_EQUIPMENT_SHOW, GOSSIP_ACTION_INFO_DEF + BOT_SLOT_RANGED);

            //armor
            AddGossipItemFor(player, GOSSIP_ICON_TALK, "Head...", GOSSIP_SENDER_EQUIPMENT_SHOW, GOSSIP_ACTION_INFO_DEF + BOT_SLOT_HEAD);
            AddGossipItemFor(player, GOSSIP_ICON_TALK, "Shoulders...", GOSSIP_SENDER_EQUIPMENT_SHOW, GOSSIP_ACTION_INFO_DEF + BOT_SLOT_SHOULDERS);
            AddGossipItemFor(player, GOSSIP_ICON_TALK, "Chest...", GOSSIP_SENDER_EQUIPMENT_SHOW, GOSSIP_ACTION_INFO_DEF + BOT_SLOT_CHEST);
            AddGossipItemFor(player, GOSSIP_ICON_TALK, "Waist...", GOSSIP_SENDER_EQUIPMENT_SHOW, GOSSIP_ACTION_INFO_DEF + BOT_SLOT_WAIST);
            AddGossipItemFor(player, GOSSIP_ICON_TALK, "Legs...", GOSSIP_SENDER_EQUIPMENT_SHOW, GOSSIP_ACTION_INFO_DEF + BOT_SLOT_LEGS);
            AddGossipItemFor(player, GOSSIP_ICON_TALK, "Feet...", GOSSIP_SENDER_EQUIPMENT_SHOW, GOSSIP_ACTION_INFO_DEF + BOT_SLOT_FEET);
            AddGossipItemFor(player, GOSSIP_ICON_TALK, "Wrist...", GOSSIP_SENDER_EQUIPMENT_SHOW, GOSSIP_ACTION_INFO_DEF + BOT_SLOT_WRIST);
            AddGossipItemFor(player, GOSSIP_ICON_TALK, "Hands...", GOSSIP_SENDER_EQUIPMENT_SHOW, GOSSIP_ACTION_INFO_DEF + BOT_SLOT_HANDS);

            if (IsHumanoidClass(_botclass))
            {
                AddGossipItemFor(player, GOSSIP_ICON_TALK, "Back...", GOSSIP_SENDER_EQUIPMENT_SHOW, GOSSIP_ACTION_INFO_DEF + BOT_SLOT_BACK);
                AddGossipItemFor(player, GOSSIP_ICON_TALK, "Shirt...", GOSSIP_SENDER_EQUIPMENT_SHOW, GOSSIP_ACTION_INFO_DEF + BOT_SLOT_BODY);
                AddGossipItemFor(player, GOSSIP_ICON_TALK, "Finger1...", GOSSIP_SENDER_EQUIPMENT_SHOW, GOSSIP_ACTION_INFO_DEF + BOT_SLOT_FINGER1);
                AddGossipItemFor(player, GOSSIP_ICON_TALK, "Finger2...", GOSSIP_SENDER_EQUIPMENT_SHOW, GOSSIP_ACTION_INFO_DEF + BOT_SLOT_FINGER2);
                AddGossipItemFor(player, GOSSIP_ICON_TALK, "Trinket1...", GOSSIP_SENDER_EQUIPMENT_SHOW, GOSSIP_ACTION_INFO_DEF + BOT_SLOT_TRINKET1);
                AddGossipItemFor(player, GOSSIP_ICON_TALK, "Trinket2...", GOSSIP_SENDER_EQUIPMENT_SHOW, GOSSIP_ACTION_INFO_DEF + BOT_SLOT_TRINKET2);
                AddGossipItemFor(player, GOSSIP_ICON_TALK, "Neck...", GOSSIP_SENDER_EQUIPMENT_SHOW, GOSSIP_ACTION_INFO_DEF + BOT_SLOT_NECK);
            }

            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Unequip all", GOSSIP_SENDER_UNEQUIP_ALL, GOSSIP_ACTION_INFO_DEF + 1);
            if (creature->GetCreatureTemplate()->unit_flags2 & UNIT_FLAG2_MIRROR_IMAGE)
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Update visual", GOSSIP_SENDER_MODEL_UPDATE, GOSSIP_ACTION_INFO_DEF + 1);
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "BACK", 1, GOSSIP_ACTION_INFO_DEF + 1);

            break;
        }
        case GOSSIP_SENDER_EQUIPMENT_LIST: //list inventory
        {
            //if (action - GOSSIP_ACTION_INFO_DEF != BOT_SLOT_NONE)
            //    break;

            int8 id = 1;
            EquipmentInfo const* einfo = sObjectMgr->GetEquipmentInfo(me->GetEntry(), id);
            ASSERT(einfo && "Trying to send equipment list for bot with no equip info!");

            for (uint8 i = BOT_SLOT_MAINHAND; i != BOT_INVENTORY_SIZE; ++i)
            {
                Item const* item = _equips[i];
                if (!item) continue;
                std::ostringstream msg;
                _AddItemLink(player, item, msg/*, false*/);
                //uncomment if needed
                //msg << " in slot " << uint32(i) << " (" << _getNameForSlot(i + 1) << ')';
                if (i <= BOT_SLOT_RANGED && einfo->ItemEntry[i] == item->GetEntry())
                    msg << " |cffe6cc80|h[!visual only!]|h|r";
                BotWhisper(msg.str().c_str(), player);
            }

            break;
        }
        case GOSSIP_SENDER_EQUIPMENT_INFO: //request equip item info
        {
            //GOSSIP ITEMS RESTRICTED
            //subMenu = true; //needed for return

            int8 id = 1;
            EquipmentInfo const* einfo = sObjectMgr->GetEquipmentInfo(me->GetEntry(), id);
            ASSERT(einfo && "Trying to send equipment info for bot with no equip info!");

            uint8 slot = action - GOSSIP_ACTION_INFO_DEF;
            Item const* item = _equips[slot];
            ASSERT(item);

            std::ostringstream msg;
            _AddItemLink(player, item, msg, false);

            if (slot <= BOT_SLOT_RANGED && einfo->ItemEntry[slot] == item->GetEntry())
                msg << " |cffe6cc80|h[!visual only!]|h|r";

            BotWhisper(msg.str().c_str(), player);

            //break; //no break here - return to menu
        }
        case GOSSIP_SENDER_EQUIPMENT_SHOW: //equips change s2: send list of equippable items
        {
            subMenu = true;

            int8 id = 1;
            EquipmentInfo const* einfo = sObjectMgr->GetEquipmentInfo(me->GetEntry(), id);
            ASSERT(einfo && "Trying to send equipment show for bot with no equip info!");

            std::set<uint32> itemList, idsList;

            //s2.1: build list
            //s2.1.1: backpack
            for (uint8 i = INVENTORY_SLOT_ITEM_START; i != INVENTORY_SLOT_ITEM_END; i++)
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
                    if (_canEquip(pItem->GetTemplate(), action - GOSSIP_ACTION_INFO_DEF, true) &&
                        /*itemList.find(pItem->GetGUID().GetCounter()) == itemList.end() &&*/
                        (pItem->GetItemRandomPropertyId() == 0 ? idsList.find(pItem->GetEntry()) == idsList.end() : true))
                    {
                        itemList.insert(pItem->GetGUID().GetCounter());
                        idsList.insert(pItem->GetEntry());
                    }
                }
            }

            //s2.1.2: other bags
            for (uint8 i = INVENTORY_SLOT_BAG_START; i != INVENTORY_SLOT_BAG_END; i++)
            {
                if (Bag const* pBag = player->GetBagByPos(i))
                {
                    for (uint32 j = 0; j != pBag->GetBagSize(); j++)
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
                            if (_canEquip(pItem->GetTemplate(), action - GOSSIP_ACTION_INFO_DEF, true) &&
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
            uint8 slot = action - GOSSIP_ACTION_INFO_DEF;
            std::ostringstream str;
            str << "Equipped: ";
            if (Item const* item = _equips[slot])
            {
                _AddItemLink(player, item, str);
                if (slot <= BOT_SLOT_RANGED && einfo->ItemEntry[slot] == item->GetEntry())
                    str << " |cffe6cc80|h[!visual only!]|h|r";

                AddGossipItemFor(player, GOSSIP_ICON_CHAT, str.str().c_str(), GOSSIP_SENDER_EQUIPMENT_INFO, action);
            }
            else
            {
                str << "nothing";
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, str.str().c_str(), GOSSIP_SENDER_EQUIPMENT_SHOW, action);
            }

            if (_equips[slot])
            {
                //s2.2.1 add unequip option if have weapon (GMs only)
                if (slot <= BOT_SLOT_RANGED)
                {
                    if (einfo->ItemEntry[slot] != 0)
                        AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Use your old equipment", GOSSIP_SENDER_EQUIP_RESET, action);
                    else
                        AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Unequip it", GOSSIP_SENDER_UNEQUIP, action);
                }

                //s2.2.2 add unequip option for non-weapons
                if (slot > BOT_SLOT_RANGED)
                    AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Unequip it", GOSSIP_SENDER_UNEQUIP, action);
            }

            //s2.2.3a: add an empty submenu with info if no items are found
            if (itemList.empty())
            {
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Hm... I have nothing to give you", 0, GOSSIP_ACTION_INFO_DEF + 1);
            }
            else
            {
                uint32 counter = 0;
                uint32 maxcounter = BOT_GOSSIP_MAX_ITEMS - 4; //unequip, reset, current, back
                uint32 slot = action - GOSSIP_ACTION_INFO_DEF;
                Item const* item;
                //s2.2.3b: add items as gossip options
                for (std::set<uint32>::const_iterator itr = itemList.begin(); itr != itemList.end() && counter < maxcounter; ++itr)
                {
                    bool found = false;
                    for (uint8 i = INVENTORY_SLOT_ITEM_START; i != INVENTORY_SLOT_ITEM_END; i++)
                    {
                        item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, i);
                        if (item && item->GetGUID().GetCounter() == (*itr))
                        {
                            std::ostringstream name;
                            _AddItemLink(player, item, name);
                            AddGossipItemFor(player, GOSSIP_ICON_CHAT, name.str().c_str(), GOSSIP_SENDER_EQUIP + slot, GOSSIP_ACTION_INFO_DEF + item->GetGUID().GetCounter());
                            ++counter;
                            found = true;
                            break;
                        }
                    }

                    if (found)
                        continue;

                    for (uint8 i = INVENTORY_SLOT_BAG_START; i != INVENTORY_SLOT_BAG_END; i++)
                    {
                        if (Bag const* pBag = player->GetBagByPos(i))
                        {
                            for (uint32 j = 0; j != pBag->GetBagSize(); j++)
                            {
                                item = player->GetItemByPos(i, j);
                                if (item && item->GetGUID().GetCounter() == (*itr))
                                {
                                    std::ostringstream name;
                                    _AddItemLink(player, item, name);
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

            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "BACK", GOSSIP_SENDER_EQUIPMENT, GOSSIP_ACTION_INFO_DEF + 2);

            //TC_LOG_ERROR("entities.player", "OnGossipSelect(bot): added %u item(s) to list of %s (requester: %s)",
            //    counter, me->GetName().c_str(), player->GetName().c_str());

            break;
        }
        case GOSSIP_SENDER_UNEQUIP: //equips change s3: Unequip DEPRECATED
        {
            if (!_unequip(action - GOSSIP_ACTION_INFO_DEF))
            {} //BotWhisper("Impossible...", player);
            break;
        }
        case GOSSIP_SENDER_UNEQUIP_ALL:
        {
            bool suc = true;
            for (uint8 i = BOT_SLOT_MAINHAND; i != BOT_INVENTORY_SIZE; ++i)
            {
                if (!(i <= BOT_SLOT_RANGED ? _resetEquipment(i) : _unequip(i)))
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
            for (uint8 i = INVENTORY_SLOT_ITEM_START; i != INVENTORY_SLOT_ITEM_END; i++)
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
                for (uint8 i = INVENTORY_SLOT_BAG_START; i != INVENTORY_SLOT_BAG_END; i++)
                {
                    if (Bag const* pBag = player->GetBagByPos(i))
                    {
                        for (uint32 j = 0; j != pBag->GetBagSize(); j++)
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

            if (found && _equip(sender - GOSSIP_SENDER_EQUIP_AUTOEQUIP_EQUIP, item)){}

            //break; //no break: update list
        }
        case GOSSIP_SENDER_EQUIP_AUTOEQUIP:
        {
            subMenu = true;

            int8 id = 1;
            EquipmentInfo const* einfo = sObjectMgr->GetEquipmentInfo(me->GetEntry(), id);
            ASSERT(einfo && "Trying to send auto-equip for bot with no equip info!");

            std::set<uint32> itemList, idsList;

            //1: build list
            //1.1: backpack
            for (uint8 i = INVENTORY_SLOT_ITEM_START; i != INVENTORY_SLOT_ITEM_END; i++)
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
                        if (_canEquip(pItem->GetTemplate(), k))
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
            for (uint8 i = INVENTORY_SLOT_BAG_START; i != INVENTORY_SLOT_BAG_END; i++)
            {
                if (Bag const* pBag = player->GetBagByPos(i))
                {
                    for (uint32 j = 0; j != pBag->GetBagSize(); j++)
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
                                if (_canEquip(pItem->GetTemplate(), k))
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
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Hm... I have nothing to give you", 0, GOSSIP_ACTION_INFO_DEF + 1);
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
                    for (uint8 i = INVENTORY_SLOT_ITEM_START; i != INVENTORY_SLOT_ITEM_END; i++)
                    {
                        item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, i);
                        if (item && item->GetGUID().GetCounter() == (*itr))
                        {
                            uint8 k = 0;
                            for (; k != BOT_INVENTORY_SIZE; ++k)
                            {
                                if (_canEquip(item->GetTemplate(), k))
                                {
                                    //workaround for double slots
                                    //if first slot is occupied and second slot is vacant use second slot
                                    if (k == BOT_SLOT_FINGER1 || k == BOT_SLOT_TRINKET1)
                                        if (_equips[k] != nullptr && _canEquip(item->GetTemplate(), k + 1))
                                            ++k;
                                    break;
                                }
                            }

                            std::ostringstream name;
                            _AddItemLink(player, item, name);
                            AddGossipItemFor(player, GOSSIP_ICON_CHAT, name.str().c_str(), GOSSIP_SENDER_EQUIP_AUTOEQUIP_EQUIP + k, GOSSIP_ACTION_INFO_DEF + item->GetGUID().GetCounter());
                            ++counter;
                            found = true;
                            break;
                        }
                    }

                    if (found)
                        continue;

                    for (uint8 i = INVENTORY_SLOT_BAG_START; i != INVENTORY_SLOT_BAG_END; i++)
                    {
                        if (Bag const* pBag = player->GetBagByPos(i))
                        {
                            for (uint32 j = 0; j != pBag->GetBagSize(); j++)
                            {
                                item = player->GetItemByPos(i, j);
                                if (item && item->GetGUID().GetCounter() == (*itr))
                                {
                                    uint8 k = 0;
                                    for (; k != BOT_INVENTORY_SIZE; ++k)
                                    {
                                        if (_canEquip(item->GetTemplate(), k))
                                        {
                                            //workaround for double slots
                                            //if first slot is occupied and second slot is vacant use second slot
                                            if (k == BOT_SLOT_FINGER1 || k == BOT_SLOT_TRINKET1)
                                                if (_equips[k] != nullptr && _canEquip(item->GetTemplate(), k + 1))
                                                    ++k;
                                            break;
                                        }
                                    }

                                    std::ostringstream name;
                                    _AddItemLink(player, item, name);
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

            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "BACK", GOSSIP_SENDER_EQUIPMENT, GOSSIP_ACTION_INFO_DEF + 2);
            break;
        }
        case GOSSIP_SENDER_EQUIP_RESET: //equips change s4a: reset equipment
        {
            if (_resetEquipment(action - GOSSIP_ACTION_INFO_DEF)){}
            break;
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
            for (uint8 i = INVENTORY_SLOT_ITEM_START; i != INVENTORY_SLOT_ITEM_END; i++)
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
                for (uint8 i = INVENTORY_SLOT_BAG_START; i != INVENTORY_SLOT_BAG_END; i++)
                {
                    if (Bag const* pBag = player->GetBagByPos(i))
                    {
                        for (uint32 j = 0; j != pBag->GetBagSize(); j++)
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

            if (found && _equip(sender - GOSSIP_SENDER_EQUIP, item)){}
            break;
        }
        case GOSSIP_SENDER_ROLES_MAIN_TOGGLE: //ROLES 2: set/unset
        {
            ToggleRole(action - GOSSIP_ACTION_INFO_DEF, false);

            //break;
        }
        case GOSSIP_SENDER_ROLES_MAIN: //ROLES 1: list
        {
            subMenu = true;

            AddGossipItemFor(player, GOSSIP_ICON_TALK, "Gathering...", GOSSIP_SENDER_ROLES_GATHERING, GOSSIP_ACTION_INFO_DEF + 1);

            uint16 role = BOT_ROLE_TANK;
            for (; role != BOT_MAX_ROLE; role <<= 1)
            {
                if (!(role & BOT_ROLE_MASK_MAIN)) //hidden
                    continue;
                if (role == BOT_ROLE_HEAL && !IsHealingClass(_botclass))
                    continue;

                AddGossipItemFor(player, GetRoleIcon(role), GetRoleString(role), GOSSIP_SENDER_ROLES_MAIN_TOGGLE, GOSSIP_ACTION_INFO_DEF + role);
            }

            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "BACK", 1, GOSSIP_ACTION_INFO_DEF + 1);

            break;
        }
        case GOSSIP_SENDER_ROLES_GATHERING_TOGGLE:
        {
            ToggleRole(action - GOSSIP_ACTION_INFO_DEF, false);

            //break;
        }
        case GOSSIP_SENDER_ROLES_GATHERING:
        {
            subMenu = true;

            uint16 role = BOT_ROLE_GATHERING_MINING;
            for (; role != BOT_MAX_ROLE; role <<= 1)
            {
                if (!(role & BOT_ROLE_MASK_GATHERING)) //hidden
                    continue;

                AddGossipItemFor(player, GetRoleIcon(role), GetRoleString(role), GOSSIP_SENDER_ROLES_GATHERING_TOGGLE, GOSSIP_ACTION_INFO_DEF + role);
            }

            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "BACK", GOSSIP_SENDER_ROLES_MAIN, GOSSIP_ACTION_INFO_DEF + 1);

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
        }
        case GOSSIP_SENDER_ABILITIES:
        {
            subMenu = true;

            if (HasAbilitiesSpecifics())
                AddGossipItemFor(player, GOSSIP_ICON_TALK, "Abilities status...", GOSSIP_SENDER_ABILITIES_SPECIFICS_LIST, GOSSIP_ACTION_INFO_DEF + 1);
            if (HasAblitiesAllowedList())
                AddGossipItemFor(player, GOSSIP_ICON_TALK, "Manage allowed abilities...", GOSSIP_SENDER_ABILITIES_USAGE_LIST, GOSSIP_ACTION_INFO_DEF + 2);

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
                name << "Use ";
                _AddSpellLink(player, spellInfo, name);
                AddGossipItemFor(player, GOSSIP_ICON_TRAINER, name.str().c_str(), GOSSIP_SENDER_ABILITIES_USE, GOSSIP_ACTION_INFO_DEF + basespell);
            }

            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Update", sender, action);
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "BACK", 1, GOSSIP_ACTION_INFO_DEF + 2);

            break;
        }
        case GOSSIP_SENDER_ABILITIES_SPECIFICS_LIST:
        {
            subMenu = true;

            std::list<std::string> specList;
            FillAbilitiesSpecifics(specList);
            for (std::list<std::string>::const_iterator itr = specList.begin(); itr != specList.end(); ++itr)
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, *itr, GOSSIP_SENDER_ABILITIES, GOSSIP_ACTION_INFO_DEF);

            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "BACK", GOSSIP_SENDER_ABILITIES, GOSSIP_ACTION_INFO_DEF + 1);

            break;
        }
        case GOSSIP_SENDER_ABILITIES_USAGE_TOGGLE:
        {
            uint32 basespell = action - GOSSIP_ACTION_INFO_DEF;
            BotSpellMap const& myspells = GetSpellMap();
            for (BotSpellMap::const_iterator itr = myspells.begin(); itr != myspells.end(); ++itr)
            {
                if (itr->first == basespell)
                {
                    itr->second->enabled = !itr->second->enabled;
                    break;
                }
            }
        }
        case GOSSIP_SENDER_ABILITIES_USAGE_LIST:
        {
            subMenu = true;

            uint32 counter = 0;
            uint32 basespell;
            SpellInfo const* spellInfo;
            BotSpellMap const& myspells = GetSpellMap();
            for (BotSpellMap::const_iterator itr = myspells.begin(); itr != myspells.end(); ++itr)
            {
                basespell = itr->first; //always valid
                spellInfo = sSpellMgr->GetSpellInfo(basespell); //always valid

                bool skip = false;
                if (itr->second->spellId == 0) //not init'ed
                    skip = true;
                else if (spellInfo->SpellFamilyName == SPELLFAMILY_GENERIC) //not a class spell
                    skip = true;
                //spells innate for a class and cannot be disabled
                else if (basespell == 2457 || basespell == 71 || basespell == 2458)//warrior stances
                    skip = true;
                else if (basespell == 48266 || basespell == 48263 || basespell == 48265)//DK stances
                    skip = true;

                if (skip)
                    continue;

                std::ostringstream name;
                _AddSpellLink(player, spellInfo, name);
                //DEBUG
                //name << " (" << basespell << ") " << itr->second->spellId;
                uint8 icon = itr->second->enabled ? BOT_ICON_ON : BOT_ICON_OFF;
                AddGossipItemFor(player, icon, name.str().c_str(), GOSSIP_SENDER_ABILITIES_USAGE_TOGGLE, GOSSIP_ACTION_INFO_DEF + basespell);
                if (++counter >= BOT_GOSSIP_MAX_ITEMS - 1) //back
                    break;
            }

            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "BACK", GOSSIP_SENDER_ABILITIES, GOSSIP_ACTION_INFO_DEF + 2);
            break;
        }
        case GOSSIP_SENDER_USEITEM_USE:
        {
            if (uint32 guidLow = action - GOSSIP_ACTION_INFO_DEF)
            {
                Item const* item = nullptr;
                bool found = false;
                for (uint8 i = INVENTORY_SLOT_ITEM_START; i != INVENTORY_SLOT_ITEM_END; i++)
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
                    for (uint8 i = INVENTORY_SLOT_BAG_START; i != INVENTORY_SLOT_BAG_END; i++)
                    {
                        if (Bag const* pBag = player->GetBagByPos(i))
                        {
                            for (uint32 j = 0; j != pBag->GetBagSize(); j++)
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
        }
        case GOSSIP_SENDER_USEITEM:
        {
            subMenu = true;

            uint32 counter = 0;
            uint32 maxcounter = BOT_GOSSIP_MAX_ITEMS - 2; //update, back
            Item const* item;
            ItemTemplate const* proto;
            for (uint8 i = INVENTORY_SLOT_ITEM_START; i != INVENTORY_SLOT_ITEM_END; i++)
            {
                item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, i);
                //if (item && item->IsSoulBound()) continue;
                proto = item ? item->GetTemplate() : nullptr;
                if (proto && proto->Class == ITEM_CLASS_CONSUMABLE &&
                    (proto->SubClass == ITEM_SUBCLASS_POTION || proto->SubClass == ITEM_SUBCLASS_ELIXIR ||
                    proto->SubClass == ITEM_SUBCLASS_FLASK || proto->SubClass == ITEM_SUBCLASS_FOOD ||
                    proto->SubClass == ITEM_SUBCLASS_POTION || proto->SubClass == ITEM_SUBCLASS_CONSUMABLE ||
                    proto->SubClass == ITEM_SUBCLASS_CONSUMABLE_OTHER) &&
                    (proto->AllowableClass & (1<<(_botclass-1))) &&
                    proto->RequiredSkill == 0 &&
                    proto->RequiredSpell == 0 &&
                    me->GetLevel() >= proto->RequiredLevel)
                {
                    std::ostringstream name;
                    _AddItemLink(player, item, name);
                    AddGossipItemFor(player, GOSSIP_ICON_CHAT, name.str().c_str(), GOSSIP_SENDER_USEITEM_USE, GOSSIP_ACTION_INFO_DEF + item->GetGUID().GetCounter());
                    ++counter; //no need to check max counter here
                }
            }

            for (uint8 i = INVENTORY_SLOT_BAG_START; i != INVENTORY_SLOT_BAG_END; i++)
            {
                if (Bag const* pBag = player->GetBagByPos(i))
                {
                    for (uint32 j = 0; j != pBag->GetBagSize() && counter < maxcounter; j++)
                    {
                        item = player->GetItemByPos(i, j);
                        //if (item && item->IsSoulBound()) continue;
                        proto = item ? item->GetTemplate() : nullptr;
                        if (proto && proto->Class == ITEM_CLASS_CONSUMABLE &&
                            //proto->Spells[0].SpellCategory != SPELL_CATEGORY_FOOD && proto->Spells[0].SpellCategory != SPELL_CATEGORY_DRINK
                            (proto->SubClass == ITEM_SUBCLASS_POTION || proto->SubClass == ITEM_SUBCLASS_ELIXIR ||
                            proto->SubClass == ITEM_SUBCLASS_FLASK || proto->SubClass == ITEM_SUBCLASS_FOOD ||
                            proto->SubClass == ITEM_SUBCLASS_POTION || proto->SubClass == ITEM_SUBCLASS_CONSUMABLE ||
                            proto->SubClass == ITEM_SUBCLASS_CONSUMABLE_OTHER) &&
                            (proto->AllowableClass & (1<<(_botclass-1))) &&
                            proto->RequiredSkill == 0 &&
                            proto->RequiredSpell == 0 &&
                            me->GetLevel() >= proto->RequiredLevel)
                        {
                            std::ostringstream name;
                            _AddItemLink(player, item, name);
                            AddGossipItemFor(player, GOSSIP_ICON_CHAT, name.str().c_str(), GOSSIP_SENDER_USEITEM_USE, GOSSIP_ACTION_INFO_DEF + item->GetGUID().GetCounter());
                            ++counter;
                        }
                    }
                }
            }

            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Update", sender, action);
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "BACK", 1, GOSSIP_ACTION_INFO_DEF + 1);

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
                    ch.PSendSysMessage("%s will not join you until owner dismisses %s", me->GetName().c_str(), (me->GetGender() == GENDER_MALE ? "him" : "her"));
                    break;
                }

                if (_botclass == BOT_CLASS_DEATH_KNIGHT && player->GetLevel() < 55)
                {
                    BotWhisper("Go away, weakling", player);
                    ChatHandler ch(player->GetSession());
                    ch.PSendSysMessage("%s will not join you until you are level 55", me->GetName().c_str());
                    break;
                }
                if (_botclass == BOT_CLASS_SPHYNX && player->GetLevel() < 60)
                {
                    std::string msg1 = me->GetName() + " is not convinced by " + player->GetName() + "'s actions";
                    me->TextEmote(msg1.c_str());
                    ChatHandler ch(player->GetSession());
                    ch.PSendSysMessage("%s will not join you until you are level 60", me->GetName().c_str());
                    break;
                }
                if (_botclass == BOT_CLASS_ARCHMAGE && player->GetLevel() < 20)
                {
                    BotWhisper("I am not going to waste my time on just anything", player);
                    ChatHandler ch(player->GetSession());
                    ch.PSendSysMessage("%s will not join you until you are level 20", me->GetName().c_str());
                    break;
                }
                if (_botclass == BOT_CLASS_DREADLORD && player->GetLevel() < 60)
                {
                    //BotWhisper("placeholder", player);
                    ChatHandler ch(player->GetSession());
                    ch.PSendSysMessage("%s will not join you until you are level 60", me->GetName().c_str());
                    break;
                }
                if (_botclass == BOT_CLASS_SPELLBREAKER && player->GetLevel() < 20)
                {
                    //BotWhisper("placeholder", player);
                    ChatHandler ch(player->GetSession());
                    ch.PSendSysMessage("%s will not join you until you are level 20", me->GetName().c_str());
                    break;
                }
                if (_botclass == BOT_CLASS_DARK_RANGER && player->GetLevel() < 40)
                {
                    //BotWhisper("placeholder", player);
                    ChatHandler ch(player->GetSession());
                    ch.PSendSysMessage("%s will not join you until you are level 40", me->GetName().c_str());
                    break;
                }

                if (SetBotOwner(player))
                {
                    if (_botclass == BOT_CLASS_SPHYNX)
                    {
                        std::string msg1 = me->GetName() + " makes a grinding sound and begins to follow " + player->GetName();
                        me->TextEmote(msg1.c_str());
                    }
                    else
                        BotWhisper("I am ready", player);
                }
                else
                    BotSay("...", player);
            }
            else if (reason == -1)
            {
                me->SetFaction(14);
                if (botPet)
                    botPet->SetFaction(14);
                BotYell("Die!", player);
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
                        ostr << "Go away. I serve my master ";
                        if (sCharacterCache->GetCharacterNameByGuid(ObjectGuid(HighGuid::Player, _ownerGuid), name))
                            ostr << name;
                        else
                            ostr << "unknown (" << _ownerGuid << ')';
                        BotWhisper(ostr.str().c_str(), player);
                        ch.PSendSysMessage("%s will not join you until owner dismisses %s", me->GetName().c_str(), (me->GetGender() == GENDER_MALE ? "him" : "her"));
                        break;
                    }
                    case 2: //max npcbots exceed
                        ch.PSendSysMessage("You exceed max npcbots (%u)", BotMgr::GetMaxNpcBots());
                        BotSay("...", player);
                        break;
                    case 3: //not enough money
                    {
                        std::string str = "You don't have enough money (";
                        str += BotMgr::GetNpcBotCostStr(player->GetLevel(), me);
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

                        ch.PSendSysMessage("You cannot have more bots of that class! %u of %u", count, _maxClassNpcBots);
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
                if (!(i <= BOT_SLOT_RANGED ? _resetEquipment(i) : _unequip(i)))
                {
                    std::ostringstream estr;
                    estr << "Cannot reset equipment in slot " << uint32(i) << " (" << _getNameForSlot(i) << ")! Cannot dismiss bot!";
                    ChatHandler ch(player->GetSession());
                    ch.SendSysMessage(estr.str().c_str());
                    abort = true;
                    break;
                }
            }

            if (abort)
                break;

            mgr->RemoveBot(me->GetGUID(), BOT_REMOVE_DISMISS);
            if (Aura* bers = me->AddAura(BERSERK, me))
            {
                uint32 dur = 5 * MINUTE * IN_MILLISECONDS;
                bers->SetDuration(dur);
                bers->SetMaxDuration(dur);
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
            player->GetBotMgr()->RemoveBotFromGroup(me, false);
            break;
        }
        case GOSSIP_SENDER_FORMATION:
        {
            subMenu = true;
            std::ostringstream diststr;
            diststr << "Follow distance (current: " << uint32(master->GetBotMgr()->GetBotFollowDist()) << ')';
            player->PlayerTalkClass->GetGossipMenu().AddMenuItem(-1, GOSSIP_ICON_CHAT, diststr.str(),
                GOSSIP_SENDER_FORMATION_FOLLOW_DISTANCE_SET, GOSSIP_ACTION_INFO_DEF + 1, "", 0, true);

            if (HasRole(BOT_ROLE_RANGED))
                AddGossipItemFor(player, GOSSIP_ICON_TALK, "Attack distance...", GOSSIP_SENDER_FORMATION_ATTACK, GOSSIP_ACTION_INFO_DEF + 2);

            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "BACK", 1, GOSSIP_ACTION_INFO_DEF + 3);
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
         case GOSSIP_SENDER_FORMATION_ATTACK:
        {
            subMenu = true;

            uint8 mode = master->GetBotMgr()->GetBotAttackRangeMode();
            AddGossipItemFor(player, mode == BOT_ATTACK_RANGE_SHORT ? GOSSIP_ICON_BATTLE : GOSSIP_ICON_CHAT, "Short range attacks", GOSSIP_SENDER_FORMATION_ATTACK_DISTANCE_SET, GOSSIP_ACTION_INFO_DEF + 1);
            AddGossipItemFor(player, mode == BOT_ATTACK_RANGE_LONG ? GOSSIP_ICON_BATTLE : GOSSIP_ICON_CHAT, "Long range attacks", GOSSIP_SENDER_FORMATION_ATTACK_DISTANCE_SET, GOSSIP_ACTION_INFO_DEF + 2);

            std::ostringstream diststr;
            if (mode == BOT_ATTACK_RANGE_EXACT)
                diststr << "Exact (current: " << uint32(master->GetBotMgr()->GetBotExactAttackRange()) << ')';
            else
                diststr << "Exact (0-50)";
            player->PlayerTalkClass->GetGossipMenu().AddMenuItem(-1, mode == BOT_ATTACK_RANGE_EXACT ? GOSSIP_ICON_BATTLE : GOSSIP_ICON_CHAT,
                diststr.str(), GOSSIP_SENDER_FORMATION_ATTACK_DISTANCE_SET, GOSSIP_ACTION_INFO_DEF + 3, "", 0, true);

            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "BACK", 1, GOSSIP_ACTION_INFO_DEF + 4);
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
                //        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_STUNNED);
                //    }
                //    if (me->HasUnitState(UNIT_STATE_CONFUSED) && !me->HasAuraType(SPELL_AURA_MOD_CONFUSE))
                //    {
                //        me->ClearUnitState(UNIT_STATE_CONFUSED);
                //        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_CONFUSED);
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
                        //1 passive, negative spells, hidden, locked, shapeshift spells (no hook for that)
                        if (info->IsPassive() || !info->IsPositive())
                            continue;
                        if ((info->Attributes & (SPELL_ATTR0_CANT_CANCEL | SPELL_ATTR0_HIDDEN_CLIENTSIDE)) ||
                            (info->AttributesEx & SPELL_ATTR1_DONT_DISPLAY_IN_AURA_BAR))
                            continue;
                        if (info->HasAura(SPELL_AURA_MOD_SHAPESHIFT))
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

                    AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Update", sender, action);
                    AddGossipItemFor(player, GOSSIP_ICON_CHAT, "BACK", 1, GOSSIP_ACTION_INFO_DEF + 1);
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
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Remove buff...", GOSSIP_SENDER_TROUBLESHOOTING_FIX, GOSSIP_ACTION_INFO_DEF + 2);
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Fix your power type", GOSSIP_SENDER_TROUBLESHOOTING_FIX, GOSSIP_ACTION_INFO_DEF + 3);
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "BACK", 1, GOSSIP_ACTION_INFO_DEF + 4);
            break;
        }
        case GOSSIP_SENDER_DEBUG_ACTION:
        {
            //!!! player != owner !!!
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
                    for (uint16 i = BOT_MAX_ROLE; i != BOT_ROLE_NONE; i >>= 1)
                    {
                        if (_roleMask & i)
                        {
                            switch (i)
                            {
                                case BOT_ROLE_TANK:
                                    ch.SendSysMessage("BOT_ROLE_TANK");
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
        case GOSSIP_SENDER_DEBUG:
        {
            //!!! player != owner !!!
            subMenu = true;

            std::ostringstream ostr;
            std::string name;
            ostr << "Bot: " << me->GetName()
                << " (Id: " << me->GetEntry()
                << ", guidlow: " << me->GetGUID().GetCounter()
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
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "<Reload Config>", GOSSIP_SENDER_DEBUG_ACTION, GOSSIP_ACTION_INFO_DEF + 6);

            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "BACK", 1, GOSSIP_ACTION_INFO_DEF + 1);
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
                default:
                    break;
            }

            //AddGossipItemFor(player, GOSSIP_ICON_CHAT, "BACK", 1, GOSSIP_ACTION_INFO_DEF + 1);

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

    if (!BotMgr::IsNpcBotModEnabled() || me->HasUnitState(UNIT_STATE_CASTING) || CCed(me) || IsDuringTeleport())
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
            return OnGossipSelect(player, creature, GOSSIP_SENDER_FORMATION_ATTACK, action);
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
        if (u && u->IsInCombat() && !CCed(u) && u->isTargetableForAttack() && IsInBotParty(u->GetVictim()) && me->IsWithinLOSInMap(u))
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
                    if (IsInBotParty(spell->m_targets.GetUnitTarget()) && spell->GetTimer() < 1000)
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
    if (me->GetVictim() && (!IAmFree() || me->GetDistance(me->GetVictim()) < me->GetDistance(attacker)))
        return;
    else if (!IsMelee() && opponent)
        return;
    //if (InDuel(attacker))
    //    return;

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
            //TC_LOG_ERROR("entities.player", "minion_ai: OnOwnerDamagedBy() - unknown bot class %u", uint8(_botclass));
            break;
    }

    if (!CanBotAttack(attacker, byspell))
        return;

    m_botCommandState = COMMAND_ABANDON; //reset AttackStart()
    me->Attack(attacker, !HasRole(BOT_ROLE_RANGED));
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
    //dreadlord can on only equip in main hand
    if (_botclass == BOT_CLASS_DREADLORD)
        return false;

    //warrior can wield any offhand with titan's grip
    if (_botclass == BOT_CLASS_WARRIOR && me->GetLevel() >= 60)
        return true;

    ItemTemplate const* protoMH = _equips[BOT_SLOT_MAINHAND] ? _equips[BOT_SLOT_MAINHAND]->GetTemplate() : nullptr;

    //no mainhand weapon OR
    //mainhand is an one-hand weapon
    if (!protoMH)
        return true;

    if (protoMH->Class == ITEM_CLASS_WEAPON &&
        (protoMH->InventoryType == INVTYPE_WEAPON || protoMH->InventoryType == INVTYPE_WEAPONMAINHAND) &&
        (protoMH->SubClass == ITEM_SUBCLASS_WEAPON_AXE || protoMH->SubClass == ITEM_SUBCLASS_WEAPON_DAGGER ||
        protoMH->SubClass == ITEM_SUBCLASS_WEAPON_FIST || protoMH->SubClass == ITEM_SUBCLASS_WEAPON_MACE ||
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
        _botclass == BOT_CLASS_DARK_RANGER);
}

bool bot_ai::_canUseRelic() const
{
    return (_botclass == BOT_CLASS_PALADIN || _botclass == BOT_CLASS_SHAMAN ||
        _botclass == BOT_CLASS_DRUID || _botclass == BOT_CLASS_DEATH_KNIGHT);
}

bool bot_ai::_canEquip(ItemTemplate const* item, uint8 slot, bool ignoreItemLevel) const
{
    int8 id = 1;
    EquipmentInfo const* einfo = sObjectMgr->GetEquipmentInfo(me->GetEntry(), id);

    if (Item const* oldItem = _equips[slot])
    {
        ItemTemplate const* oldProto = oldItem->GetTemplate();
        //prevent reequipping same items
        if (item->ItemId == oldProto->ItemId && !oldItem->GetItemRandomPropertyId())
            return false;
        //prevent equipping worse items (only standard or not)
        if (!ignoreItemLevel)
            if (slot > BOT_SLOT_RANGED || einfo->ItemEntry[slot] != oldProto->ItemId)
                if (IAmFree() || !master->IsGameMaster())
                    if (oldProto->ItemLevel > item->ItemLevel)
                        return false;
    }

    if (slot == BOT_SLOT_OFFHAND && !_canUseOffHand())
        return false;

    //level requirements
    if (me->GetLevel() < item->RequiredLevel)
        return false;

    //class requirements
    if (_botclass < BOT_CLASS_EX_START && !(item->AllowableClass & (1<<(_botclass-1))))
        return false;

    //skip race requirements

    //inventory related conditions
    if (item->Class == ITEM_CLASS_WEAPON)
    {
        switch (slot)
        {
            case BOT_SLOT_MAINHAND:
                switch (_botclass)
                {
                    case BOT_CLASS_BM:
                        if (item->SubClass != ITEM_SUBCLASS_WEAPON_POLEARM &&
                            item->SubClass != ITEM_SUBCLASS_WEAPON_AXE2 &&
                            item->SubClass != ITEM_SUBCLASS_WEAPON_SWORD2)
                            return false;
                        break;
                    case BOT_CLASS_ARCHMAGE:
                        if (item->SubClass != ITEM_SUBCLASS_WEAPON_STAFF)
                            return false;
                        break;
                    default:
                        break;
                }
                break;
            case BOT_SLOT_OFFHAND:
                if (item->SubClass == ITEM_SUBCLASS_WEAPON_POLEARM || item->SubClass == ITEM_SUBCLASS_WEAPON_STAFF)
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
                        if (me->GetLevel() < 40)
                            return false;
                        break;
                    case BOT_CLASS_SPHYNX:
                        break;
                    case BOT_CLASS_DARK_RANGER:
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

        switch (item->InventoryType)
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
                switch (item->SubClass)
                {
                    case ITEM_SUBCLASS_WEAPON_AXE:
                    case ITEM_SUBCLASS_WEAPON_AXE2:
                    case ITEM_SUBCLASS_WEAPON_MACE:
                    case ITEM_SUBCLASS_WEAPON_MACE2:
                    case ITEM_SUBCLASS_WEAPON_SWORD:
                    case ITEM_SUBCLASS_WEAPON_SWORD2:
                    case ITEM_SUBCLASS_WEAPON_POLEARM:
                    case ITEM_SUBCLASS_WEAPON_STAFF:
                    case ITEM_SUBCLASS_WEAPON_FIST:
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
                switch (item->SubClass)
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
                switch (item->SubClass)
                {
                    case ITEM_SUBCLASS_WEAPON_AXE:
                    case ITEM_SUBCLASS_WEAPON_AXE2:
                    //case ITEM_SUBCLASS_WEAPON_MACE:
                    //case ITEM_SUBCLASS_WEAPON_MACE2:
                    case ITEM_SUBCLASS_WEAPON_SWORD:
                    case ITEM_SUBCLASS_WEAPON_SWORD2:
                    case ITEM_SUBCLASS_WEAPON_POLEARM:
                    case ITEM_SUBCLASS_WEAPON_STAFF:
                    case ITEM_SUBCLASS_WEAPON_FIST:
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
                switch (item->SubClass)
                {
                    case ITEM_SUBCLASS_WEAPON_AXE:
                    case ITEM_SUBCLASS_WEAPON_MACE:
                    case ITEM_SUBCLASS_WEAPON_SWORD:
                    case ITEM_SUBCLASS_WEAPON_FIST:
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
                switch (item->SubClass)
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
                switch (item->SubClass)
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
                switch (item->SubClass)
                {
                    case ITEM_SUBCLASS_WEAPON_MACE:
                    case ITEM_SUBCLASS_WEAPON_MACE2:
                    case ITEM_SUBCLASS_WEAPON_POLEARM:
                    case ITEM_SUBCLASS_WEAPON_STAFF:
                    case ITEM_SUBCLASS_WEAPON_FIST:
                    case ITEM_SUBCLASS_WEAPON_DAGGER:
                        break;
                    default:
                        return false;
                }
                break;
            case BOT_CLASS_SHAMAN:
                switch (item->SubClass)
                {
                    case ITEM_SUBCLASS_WEAPON_AXE:
                    case ITEM_SUBCLASS_WEAPON_AXE2:
                    case ITEM_SUBCLASS_WEAPON_MACE:
                    case ITEM_SUBCLASS_WEAPON_MACE2:
                    case ITEM_SUBCLASS_WEAPON_STAFF:
                    case ITEM_SUBCLASS_WEAPON_FIST:
                    case ITEM_SUBCLASS_WEAPON_DAGGER:
                        break;
                    default:
                        return false;
                }
                break;
            case BOT_CLASS_BM:
                switch (item->SubClass)
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
                switch (item->SubClass)
                {
                    //case ITEM_SUBCLASS_WEAPON_MACE:
                    //case ITEM_SUBCLASS_WEAPON_MACE2:
                    //case ITEM_SUBCLASS_WEAPON_SWORD:
                    //case ITEM_SUBCLASS_WEAPON_DAGGER:
                    //case ITEM_SUBCLASS_WEAPON_STAFF:
                    case ITEM_SUBCLASS_WEAPON_WAND:
                        break;
                    default:
                        return false;
                }
                break;
            case BOT_CLASS_ARCHMAGE:
                switch (item->SubClass)
                {
                    case ITEM_SUBCLASS_WEAPON_STAFF:
                        break;
                    default:
                        return false;
                }
                break;
            case BOT_CLASS_DREADLORD:
                switch (item->SubClass)
                {
                    case ITEM_SUBCLASS_WEAPON_AXE:
                    case ITEM_SUBCLASS_WEAPON_AXE2:
                    case ITEM_SUBCLASS_WEAPON_MACE:
                    case ITEM_SUBCLASS_WEAPON_MACE2:
                    case ITEM_SUBCLASS_WEAPON_SWORD:
                    case ITEM_SUBCLASS_WEAPON_SWORD2:
                    case ITEM_SUBCLASS_WEAPON_POLEARM:
                    case ITEM_SUBCLASS_WEAPON_STAFF:
                    case ITEM_SUBCLASS_WEAPON_FIST:
                    case ITEM_SUBCLASS_WEAPON_DAGGER:
                        break;
                    default:
                        return false;
                }
                break;
            case BOT_CLASS_SPELLBREAKER:
                switch (item->SubClass)
                {
                    case ITEM_SUBCLASS_WEAPON_AXE:
                    case ITEM_SUBCLASS_WEAPON_MACE:
                    case ITEM_SUBCLASS_WEAPON_SWORD:
                    case ITEM_SUBCLASS_WEAPON_FIST:
                    case ITEM_SUBCLASS_WEAPON_DAGGER:
                        break;
                    default:
                        return false;
                }
                break;
            case BOT_CLASS_DARK_RANGER:
                switch (item->SubClass)
                {
                    case ITEM_SUBCLASS_WEAPON_SWORD:
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
    else if (item->Class == ITEM_CLASS_ARMOR/* || item->Class == ITEM_CLASS_QUEST*/)
    {
        switch (item->InventoryType)
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
                        break;;
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
                        break;;
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
                        break;;
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
                        break;;
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
                        break;;
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
                        break;;
                }
                break;
            case INVTYPE_RELIC:
                if (slot != BOT_SLOT_RANGED)
                    return false;
                break;
            default:
                return false;
        }

        switch (item->SubClass)
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
                        break;
                    case BOT_CLASS_WARRIOR:
                    case BOT_CLASS_PALADIN:
                    case BOT_CLASS_DEATH_KNIGHT:
                        if (me->GetLevel() >= 40)
                            break;
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
                        break;
                    case BOT_CLASS_WARRIOR:
                    case BOT_CLASS_PALADIN:
                    case BOT_CLASS_DEATH_KNIGHT:
                        break;
                    case BOT_CLASS_SHAMAN:
                    case BOT_CLASS_HUNTER:
                        if (me->GetLevel() >= 40)
                            break;
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
                        if (item->InventoryType != INVTYPE_CLOAK)
                            return false;
                        break;
                    default:
                        break;
                }
                break;
            case ITEM_SUBCLASS_ARMOR_MISC:
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

bool bot_ai::_unequip(uint8 slot)
{
    ASSERT(!IAmFree());

    int8 id = 1;
    EquipmentInfo const* einfo = sObjectMgr->GetEquipmentInfo(me->GetEntry(), id);
    ASSERT(einfo && "Trying to unequip item for bot with no equip info!");

    Item* item = _equips[slot];
    if (!item)
        return true; //already unequipped

    uint32 itemId = item->GetEntry();

    RemoveItemBonuses(slot);
    ApplyItemSetBonuses(item, false);

    //hand old weapon to master
    if (slot > BOT_SLOT_RANGED || einfo->ItemEntry[slot] != itemId)
    {
        ItemPosCountVec dest;
        uint32 no_space = 0;
        InventoryResult msg = master->CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, itemId, 1, &no_space);
        if (msg != EQUIP_ERR_OK)
        {
            std::ostringstream istr, iistr;
            istr << "Cannot unequip ";
            _AddItemLink(master, item, iistr, false);
            istr << iistr.str() << " for some stupid reason! Sending through mail";
            ChatHandler ch(master->GetSession());
            ch.SendSysMessage(istr.str().c_str());

            //MailHnadler::HandleSendMail()
            item->SetOwnerGUID(master->GetGUID());

            SQLTransaction trans = CharacterDatabase.BeginTransaction();
            item->SaveToDB(trans);
            MailDraft(iistr.str(), "").AddItem(item).SendMailTo(trans, MailReceiver(master), MailSender(me));
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

    //offhand check
    if (slot == BOT_SLOT_OFFHAND)
    {
        if (me->CanDualWield())
            me->SetCanDualWield(false);
        if (!(me->GetCreatureTemplate()->flags_extra & CREATURE_FLAG_EXTRA_NO_BLOCK))
            const_cast<CreatureTemplate*>(me->GetCreatureTemplate())->flags_extra |= CREATURE_FLAG_EXTRA_NO_BLOCK;
    }

    return true;
}

bool bot_ai::_equip(uint8 slot, Item* newItem)
{
    ASSERT(!IAmFree());
    ASSERT(newItem);

    int8 id = 1;
    EquipmentInfo const* einfo = sObjectMgr->GetEquipmentInfo(me->GetEntry(), id);
    ASSERT(einfo && "Trying to equip item for bot with no equip info!");

    ItemTemplate const* proto = newItem->GetTemplate();

    if (newItem->GetState() == ITEM_REMOVED)
    {
        TC_LOG_ERROR("entities.player",
            "minion_ai::_equip(): player %s (guidLow: %u) is trying to make bot %s (id: %u) equip item: %s (id: %u, guidLow: %u) which has state ITEM_REMOVED!",
            master->GetName().c_str(), master->GetGUID().GetCounter(), me->GetName().c_str(), me->GetEntry(), proto->Name1.c_str(), proto->ItemId, newItem->GetGUID().GetCounter());
        return false;
    }

    uint32 newItemId = newItem->GetEntry();

    if (Item const* oldItem = _equips[slot])
    {
        //same id
        if (oldItem->GetEntry() == newItemId && !newItem->GetItemRandomPropertyId())
            return false;
    }

    if (!_unequip(slot))
    {
        //BotWhisper("You have no space for my current item", master);
        return false;
    }

    if (slot > BOT_SLOT_RANGED || einfo->ItemEntry[slot] != newItemId)
    {
        //cheating
        if (newItem->GetOwnerGUID() != master->GetGUID() || !master->HasItemCount(newItemId, 1))
        {
            //std::ostringstream msg;
            //msg << "Cannot find ";
            //_AddItemLink(master, newItem, msg, false);
            //msg << " (id: " << uint32(newItemId) << ")!";
            //BotWhisper(msg.str().c_str());

            TC_LOG_ERROR("entities.player",
                "minion_ai::_equip(): player %s (guidLow: %u) is trying to make bot %s (id: %u) equip item: %s (id: %u, guidLow: %u) but either does not have this item or does not own it",
                master->GetName().c_str(), master->GetGUID().GetCounter(), me->GetName().c_str(), me->GetEntry(), proto->Name1.c_str(), proto->ItemId, newItem->GetGUID().GetCounter());
            return false;
        }

        master->MoveItemFromInventory(newItem->GetBagSlot(), newItem->GetSlot(), true);
        //Item is removed from inventory table in _updateEquips(slot, newItem);
        newItem->SetOwnerGUID(ObjectGuid::Empty); //needed to prevent some logs to be sent to master, restored at unequip
    }

    if (slot <= BOT_SLOT_RANGED)
    {
        if (CanChangeEquip(slot))
            me->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID + slot, newItemId);
        uint32 delay =
            /*einfo->ItemEntry[slot] != newItemId || */RespectEquipsAttackTime() || slot == BOT_SLOT_OFFHAND ? proto->Delay :
            slot == BOT_SLOT_RANGED ? me->GetCreatureTemplate()->RangeAttackTime : me->GetCreatureTemplate()->BaseAttackTime;
        //attack time will be updated in SetStats() -> OnMeleeDamageUpdate()
        if (!me->IsInFeralForm())
            me->SetAttackTime(WeaponAttackType(slot), delay); //set attack speed
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
        if (proto->InventoryType == INVTYPE_2HWEAPON && !(_botclass == BOT_CLASS_WARRIOR && me->GetLevel() >= 60))
        {
            //if have incompatible offhand unequip it
            if (_equips[BOT_SLOT_OFFHAND] != nullptr)
                _unequip(BOT_SLOT_OFFHAND);
        }
        else if (_equips[BOT_SLOT_OFFHAND] == nullptr && einfo->ItemEntry[BOT_SLOT_OFFHAND])
            _resetEquipment(BOT_SLOT_OFFHAND);
    }

    //send info to class ai
    if (proto->Class == ITEM_CLASS_WEAPON)
    {
        if (slot == BOT_SLOT_MAINHAND)
        {
            SetAIMiscValue(BOTAI_MISC_DAGGER_MAINHAND, proto->SubClass == ITEM_SUBCLASS_WEAPON_DAGGER);
            SetAIMiscValue(BOTAI_MISC_ENCHANT_CAN_EXPIRE_MH, newItem->GetEnchantmentId(TEMP_ENCHANTMENT_SLOT));
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
bool bot_ai::_resetEquipment(uint8 slot)
{
    ASSERT(!IAmFree());
    ASSERT(slot <= BOT_SLOT_RANGED);

    int8 id = 1;
    EquipmentInfo const* einfo = sObjectMgr->GetEquipmentInfo(me->GetEntry(), id);
    ASSERT(einfo && "Trying to reset equipment for bot with no equip info!");

    uint32 itemId = einfo->ItemEntry[slot];
    if (!itemId)
        return _unequip(slot);
    else if (Item const* oldItem = _equips[slot])
        if (oldItem->GetEntry() == itemId)
            return true;

    if (slot == BOT_SLOT_MAINHAND && !(_botclass == BOT_CLASS_WARRIOR && me->GetLevel() >= 60))
    {
        if (ItemTemplate const* proto = sObjectMgr->GetItemTemplate(itemId))
        {
            if (proto->Class == ITEM_CLASS_WEAPON &&
                (proto->SubClass == ITEM_SUBCLASS_WEAPON_AXE2 || proto->SubClass == ITEM_SUBCLASS_WEAPON_MACE2 ||
                proto->SubClass == ITEM_SUBCLASS_WEAPON_SWORD2 || proto->SubClass == ITEM_SUBCLASS_WEAPON_POLEARM ||
                proto->SubClass == ITEM_SUBCLASS_WEAPON_STAFF || proto->SubClass == ITEM_SUBCLASS_WEAPON_SPEAR))
            {
                if (!_unequip(BOT_SLOT_OFFHAND))
                    return false;
            }
        }
    }

    //we have our standard weapon itemId which we should use to create new item
    Item* stItem = Item::CreateItem(itemId, 1, nullptr);
    ASSERT(stItem && "Failed to create standard Item for bot!");

    if (!_equip(slot, stItem))
    {
        TC_LOG_ERROR("entities.player", "minion_ai::_resetEquipment(): player %s (guidLow: %u) failed to reset equipment for bot %s (id: %u) in slot %u",
            master->GetName().c_str(), master->GetGUID().GetCounter(), me->GetName().c_str(), me->GetEntry(), slot);
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
    if (ssd && ssd_level > ssd->MaxLevel)
        ssd_level = ssd->MaxLevel;

    ScalingStatValuesEntry const* ssv = proto->ScalingStatValue ? sScalingStatValuesStore.LookupEntry(ssd_level) : nullptr;

    for (uint8 i = 0; i != MAX_ITEM_PROTO_STATS; ++i)
    {
        uint32 statType = 0;
        int32  val = 0;
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

    int8 id = 1;
    EquipmentInfo const* einfo = sObjectMgr->GetEquipmentInfo(me->GetEntry(), id);
    if (item->GetEntry() != einfo->ItemEntry[slot])
    {
        if (ssv)
        {
            float average = ssv->getDPSMod(proto->ScalingStatValue) * proto->Delay / 1000.0f;
            _stats[slot][BOT_STAT_MOD_DAMAGE_MIN] += 0.7f * average;
            _stats[slot][BOT_STAT_MOD_DAMAGE_MIN] += 1.3f * average;
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

    if (pEnchant->requiredLevel > me->GetLevel())
        return;

    uint32 enchant_display_type;
    uint32 enchant_amount;
    uint32 enchant_spell_id;

    for (uint8 s = 0; s != MAX_ITEM_ENCHANTMENT_EFFECTS; ++s)
    {
        enchant_display_type = pEnchant->type[s];
        enchant_amount = pEnchant->amount[s];
        enchant_spell_id = pEnchant->spellid[s];

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
                                if (item_rand->enchant_id[k] == enchant_id)
                                {
                                    basepoints = int32((item_rand->prefix[k] * item->GetItemSuffixFactor()) / 10000);
                                    break;
                                }
                            }
                        }
                    }
                    // Cast custom spell vs all equal basepoints got from enchant_amount
                    CastSpellExtraArgs args(item);
                    if (basepoints)
                    {
                        args.AddSpellBP0(basepoints);
                    }
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
                            if (item_rand->enchant_id[k] == enchant_id)
                            {
                                enchant_amount = uint32((item_rand->prefix[k] * item->GetItemSuffixFactor()) / 10000);
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
                            if (item_rand_suffix->enchant_id[k] == enchant_id)
                            {
                                enchant_amount = uint32((item_rand_suffix->prefix[k] * item->GetItemSuffixFactor()) / 10000);
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
    //if (pEnchant->requiredLevel > me->GetLevel())
    //    return;

    uint32 enchant_display_type;
    //uint32 enchant_amount;
    uint32 enchant_spell_id;

    for (uint8 s = 0; s != MAX_ITEM_ENCHANTMENT_EFFECTS; ++s)
    {
        enchant_display_type = pEnchant->type[s];
        //enchant_amount = pEnchant->amount[s];
        enchant_spell_id = pEnchant->spellid[s];

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

void bot_ai::RemoveItemClassEnchants()
{
    uint8 eslot = TEMP_ENCHANTMENT_SLOT;
    for (uint8 k = BOT_SLOT_MAINHAND; k != BOT_SLOT_RANGED; ++k)
    {
        if (!GetAIMiscValue(k == BOT_SLOT_MAINHAND ? BOTAI_MISC_ENCHANT_CAN_EXPIRE_MH : BOTAI_MISC_ENCHANT_CAN_EXPIRE_OH))
            continue;

        Item* weap = _equips[k];
        if (!weap || !weap->GetEnchantmentId(EnchantmentSlot(eslot)))
            continue;

        RemoveItemEnchantment(weap, EnchantmentSlot(eslot));

        for (uint8 i = 0; i != MAX_ITEM_ENCHANTMENT_EFFECTS; ++i)
            weap->SetUInt32Value(ITEM_FIELD_ENCHANTMENT_1_1 + eslot*MAX_ENCHANTMENT_OFFSET + i, 0);
    }
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
        if (pEnchant->requiredLevel > me->GetLevel())
            continue;

        uint32 enchant_display_type;
        uint32 enchant_amount;
        uint32 enchant_spell_id;

        for (uint8 s = 0; s != MAX_ITEM_ENCHANTMENT_EFFECTS; ++s)
        {
            enchant_display_type = pEnchant->type[s];
            enchant_amount = pEnchant->amount[s];
            enchant_spell_id = pEnchant->spellid[s];

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
                                if (item_rand->enchant_id[k] == enchant_id)
                                {
                                    basepoints = int32((item_rand->prefix[k] * item->GetItemSuffixFactor()) / 10000);
                                    break;
                                }
                            }
                        }
                    }
                    // Cast custom spell vs all equal basepoints got from enchant_amount
                    CastSpellExtraArgs args(item);
                    if (basepoints)
                    {
                        args.AddSpellBP0(basepoints);
                    }
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
            if (!itemSet->spells[i])
                continue;
            if (itemSet->items_to_triggerspell[i] != setItemCount)
                continue;

            SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(itemSet->spells[i]);
            if (!spellInfo)
                continue;

            //TC_LOG_ERROR("entities.player", "ApplyItemSetBonusesB: %s's %s, %s (%u), %s (%u), icount %u",
            //    me->GetName().c_str(), apply ? "apply" : "remove", itemSet->name[0], setId, spellInfo->SpellName[0], spellInfo->Id, uint32(setItemCount));

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
            if (!itemSet->spells[j])
                continue;
            if (itemSet->items_to_triggerspell[j] > setItemCount)
                continue;

            SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(itemSet->spells[j]);
            if (!spellInfo)
                continue;

            //TC_LOG_ERROR("entities.player", "ApplyItemSetBonusesB (all): %s's %s, %s (%u), %s (%u), c %u, req %u",
            //    me->GetName().c_str(), apply ? "apply" : "remove", itemSet->name[0], *itr, spellInfo->SpellName[0], spellInfo->Id, uint32(setItemCount), itemSet->items_to_triggerspell[j]);

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

inline float bot_ai::_getBotStat(uint8 slot, uint8 stat) const
{
    return float(static_cast<BotStat>(_stats[slot])[stat]);
}

inline float bot_ai::_getTotalBotStat(uint8 stat) const
{
    int32 value = 0;
    for (uint8 slot = BOT_SLOT_MAINHAND; slot != BOT_INVENTORY_SIZE; ++slot)
        value += static_cast<BotStat>(_stats[slot])[stat];

    uint8 lvl = me->GetLevel();
    float fval = float(value);

    switch (stat)
    {
        case BOT_STAT_MOD_STRENGTH:
            fval += me->GetTotalStatValue(STAT_STRENGTH);
            switch (_botclass)
            {
                case BOT_CLASS_WARRIOR:
                    //Vitality, Strength of Arms
                    if (lvl >= 45)
                        fval *= 1.06f;
                    if (lvl >= 40)
                        fval *= 1.04f;
                    //Improved Berserker Stance part 1 (all stances)
                    if (lvl >= 45/* && GetBotStance() == WARRIOR_BERSERKER_STANCE*/)
                        fval *= 1.2f;
                    break;
                case BOT_CLASS_PALADIN:
                    //Divine Strength
                    if (lvl >= 10)
                        fval *= 1.15f;
                    break;
                case BOT_CLASS_DEATH_KNIGHT:
                    //Ravenous Dead part 1
                    //Endless Winter part 1
                    //Veteran of the Third War part 1
                    //Abomination's might part 2
                    if (lvl >= 56)
                        fval *= 1.03f;
                    if (lvl >= 58)
                        fval *= 1.04f;
                    if (lvl >= 59)
                        fval *= 1.06f;
                    if (lvl >= 60)
                        fval *= 1.02f;
                    //Frost Presence passive / Improved Frost Presence
                    if (lvl >= 61 || GetBotStance() == DEATH_KNIGHT_FROST_PRESENCE)
                        fval *= 1.08f;
                    break;
                case BOT_CLASS_DRUID:
                    //Survival of the Fittest, Improved Mark of the Wild
                    if (lvl >= 35)
                        fval *= 1.08f;
                    else if (lvl >= 10)
                        fval *= 1.02f;
                    break;
                default:
                    break;
            }
            break;
        case BOT_STAT_MOD_AGILITY:
            fval += me->GetTotalStatValue(STAT_AGILITY);
            switch (_botclass)
            {
                case BOT_CLASS_HUNTER:
                    //Combat Experience, Lightning Reflexes
                    if (lvl >= 35)
                        fval *= 1.19f;
                    //Hunting Party
                    if (lvl >= 35)
                        fval *= 1.03f;
                    break;
                case BOT_CLASS_ROGUE:
                    //Sinister Calling
                    if (lvl >= 45)
                        fval *= 1.15f;
                    break;
                case BOT_CLASS_DRUID:
                    //Survival of the Fittest, Improved Mark of the Wild
                    if (lvl >= 35)
                        fval *= 1.08f;
                    else if (lvl >= 10)
                        fval *= 1.02f;
                    break;
                default:
                    break;
            }
            break;
        case BOT_STAT_MOD_STAMINA:
            fval += me->GetTotalStatValue(STAT_STAMINA);
            switch (_botclass)
            {
                case BOT_CLASS_WARRIOR:
                    //Vitality, Strength of Arms
                    if (lvl >= 45)
                        fval *= 1.09f;
                    if (lvl >= 40)
                        fval *= 1.04f;
                    break;
                case BOT_CLASS_PALADIN:
                    //Combat Expertise, Sacred Duty
                    if (lvl >= 45)
                        fval *= 1.06f;
                    if (lvl >= 35)
                        fval *= 1.04f;
                    break;
                case BOT_CLASS_HUNTER:
                    //Survivalist
                    if (lvl >= 20)
                        fval *= 1.1f;
                    break;
                case BOT_CLASS_ROGUE:
                    //Lightning Reflexes part 2
                    if (lvl >= 20)
                        fval *= 1.04f;
                    break;
                case BOT_CLASS_PRIEST:
                    //Improved Power Word: Shield
                    if (lvl >= 15)
                        fval *= 1.04f;
                    break;
                case BOT_CLASS_DEATH_KNIGHT:
                    //Veteran of the Third War part 2
                    if (lvl >= 59)
                        fval *= 1.03f;
                    break;
                case BOT_CLASS_WARLOCK:
                    //Demonic Embrace: 10% stam bonus
                    if (lvl >= 10)
                        fval *= 1.1f;
                    break;
                case BOT_CLASS_DRUID:
                    if (GetBotStance() == DRUID_BEAR_FORM)
                    {
                        //Bear form: stamina bonus base 25%
                        //Heart of the Wild: 10% stam bonus for bear
                        fval *= 1.25f;
                        if (lvl >= 35)
                            fval *= 1.1f;
                    }
                    //Survival of the Fittest, Improved Mark of the Wild
                    if (lvl >= 35)
                        fval *= 1.06f;
                    if (lvl >= 10)
                        fval *= 1.02f;
                    break;
                default:
                    break;
            }
            break;
        case BOT_STAT_MOD_INTELLECT:
            fval += me->GetTotalStatValue(STAT_INTELLECT);
            switch (_botclass)
            {
                case BOT_CLASS_PALADIN:
                    //Divine Intellect
                    if (lvl >= 15)
                        fval *= 1.1f;
                    break;
                case BOT_CLASS_HUNTER:
                    //Combat Experience
                    if (lvl >= 35)
                        fval *= 1.04f;
                    break;
                case BOT_CLASS_MAGE:
                    //Arcane Mind
                    if (lvl >= 30)
                        fval *= 1.15f;
                    break;
                case BOT_CLASS_PRIEST:
                    //Mental Strength
                    if (lvl >= 30)
                        fval *= 1.15f;
                    break;
                case BOT_CLASS_SHAMAN:
                    //Ancestral Knowledge
                    if (lvl >= 10)
                        fval *= 1.1f;
                    break;
                case BOT_CLASS_DRUID:
                    //Survival of the Fittest, Improved Mark of the Wild
                    if (lvl >= 35)
                        fval *= 1.08f;
                    else if (lvl >= 10)
                        fval *= 1.02f;
                    //Furor (Moonkin Form)
                    if (GetBotStance() == DRUID_MOONKIN_FORM)
                        fval *= 1.1f;
                    //Heart of the Wild: ferals only (tanks included)
                    if (lvl >= 35 && (IAmFree() || IsMelee()))
                        fval *= 1.2f;
                    break;
                default:
                    break;
            }
            break;
        case BOT_STAT_MOD_SPIRIT:
            fval += me->GetTotalStatValue(STAT_SPIRIT);
            switch (_botclass)
            {
                case BOT_CLASS_PRIEST:
                    //Spirit of Redemption part 1
                    if (lvl >= 30)
                        fval *= 1.05f;
                    //Enlightenment part 1
                    if (lvl >= 35)
                        fval *= 1.06f;
                    break;
                case BOT_CLASS_MAGE:
                    //Student of the Mind
                    if (lvl >= 20)
                        fval *= 1.1f;
                    break;
                case BOT_CLASS_DRUID:
                    //Survival of the Fittest, Improved Mark of the Wild
                    if (lvl >= 35)
                        fval *= 1.08f;
                    else if (lvl >= 10)
                        fval *= 1.02f;
                    //Living Spirit
                    if (lvl >= 40)
                        fval *= 1.15f;
                    break;
                default:
                    break;
            }
            break;
    }

    return fval;
}

inline float bot_ai::_getRatingMultiplier(CombatRating cr) const
{
    GtCombatRatingsEntry const* Rating = sGtCombatRatingsStore.LookupEntry(cr*GT_MAX_LEVEL + (me->GetLevel()-1));
    GtOCTClassCombatRatingScalarEntry const* classRating = sGtOCTClassCombatRatingScalarStore.LookupEntry((GetPlayerClass()-1)*GT_MAX_RATING + cr + 1);
    if (!Rating || !classRating)
        return 1.0f;

    return classRating->ratio / Rating->ratio;
}

char const* bot_ai::_getNameForSlot(uint8 slot) const
{
    switch (slot)
    {
        case BOT_SLOT_MAINHAND:
            return "Main Hand Weapon";
        case BOT_SLOT_OFFHAND:
            return "Offhand Weapon";
        case BOT_SLOT_RANGED:
            return "Ranged Weapon";
        case BOT_SLOT_HEAD:
            return "Head";
        case BOT_SLOT_SHOULDERS:
            return "Shoulders";
        case BOT_SLOT_CHEST:
            return "Chest";
        case BOT_SLOT_WAIST:
            return "Waist";
        case BOT_SLOT_LEGS:
            return "Legs";
        case BOT_SLOT_FEET:
            return "Feet";
        case BOT_SLOT_WRIST:
            return "Wrist";
        case BOT_SLOT_HANDS:
            return "Hands";
        case BOT_SLOT_BACK:
            return "Back";
        case BOT_SLOT_BODY:
            return "Body";
        case BOT_SLOT_FINGER1:
            return "Finger1";
        case BOT_SLOT_FINGER2:
            return "Finger2";
        case BOT_SLOT_TRINKET1:
            return "Trinket1";
        case BOT_SLOT_TRINKET2:
            return "Trinket2";
        case BOT_SLOT_NECK:
            return "Neck";
        default:
            return "Unknown";
    }
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
            if (pEnchant->type[s] != ITEM_ENCHANTMENT_TYPE_USE_SPELL)
                continue;

            spellInfo = sSpellMgr->GetSpellInfo(pEnchant->spellid[s]);
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

/////////
//ROLES//
/////////
uint8 bot_ai::GetRoleIcon(uint16 role) const
{
    return HasRole(role) ? BOT_ICON_ON : BOT_ICON_OFF;
}

char const* bot_ai::GetRoleString(uint16 role) const
{
    switch (role)
    {
        //case BOT_ROLE_NONE:
        //    return "???";
        case BOT_ROLE_TANK:
            return "Tanking";
        case BOT_ROLE_DPS:
            return "DPS";
        case BOT_ROLE_HEAL:
            return "Heal";
        case BOT_ROLE_RANGED:
            return "Ranged";
        case BOT_ROLE_GATHERING_MINING:
            return "Miner";
        case BOT_ROLE_GATHERING_HERBALISM:
            return "Herbalist";
        case BOT_ROLE_GATHERING_SKINNING:
            return "Skinner";
        case BOT_ROLE_GATHERING_ENGINEERING:
            return "Engineer";
        default:
        {
            std::ostringstream str;
            str << "role " << uint32(role);
            return str.str().c_str();
        }
    }
}

void bot_ai::ToggleRole(uint16 role, bool force)
{
    if (!force && roleTimer > lastdiff)
        return;

    roleTimer = 350; //delay next attempt (prevent abuse)

    HasRole(role) ? _roleMask &= ~role : _roleMask |= role;

    BotDataMgr::UpdateNpcBotData(me->GetEntry(), NPCBOT_UPDATE_ROLES, &_roleMask);

    //Update passives
    shouldUpdateStats = true;
}

bool bot_ai::IsTank(Unit const* unit) const
{
    if (!unit || unit == me)
        return HasRole(BOT_ROLE_TANK);

    if (Creature const* bot = unit->ToCreature())
        return bot->GetBotAI() && bot->GetBotAI()->HasRole(BOT_ROLE_TANK);

    //Maybe use highest hp? TODO: a way to find multiple tanks
    if (Player const* player = unit->ToPlayer())
    {
        if (Group const* gr = player->GetGroup())
        {
            /*//player role in lfg group
            if (gr->isLFGGroup())
            {
                if (sLFGMgr->GetRoles(unit->GetGUID()) & lfg::PLAYER_ROLE_TANK)
                    return true;
            }
            //raid group Main Tank (/mt)
            else */if (gr->isRaidGroup())
            {
                Group::MemberSlotList const& slots = gr->GetMemberSlots();
                for (Group::member_citerator itr = slots.begin(); itr != slots.end(); ++itr)
                    if (itr->guid == unit->GetGUID())
                        return itr->flags & MEMBER_FLAG_MAINTANK;
            }
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
    if (spawned) return;
    spawned = true;

    if (!firstspawn)
    {
        me->RemoveAllAuras();
        RemoveItemClassEnchants(); //clear rogue poisons / shaman ecnhants
        ApplyItemsSpells(); //restore item equip spells
    }

    if (firstspawn)
        InitRace();

    if (!IsTempBot())
        ApplyRacials();

    me->SetPvP(master->IsPvP());
    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_PLAYER_CONTROLLED);
    if (sWorld->IsFFAPvPRealm())
        me->SetByteFlag(UNIT_FIELD_BYTES_2, 1, UNIT_BYTE2_FLAG_FFA_PVP);
    else if (IAmFree())
        me->SetByteFlag(UNIT_FIELD_BYTES_2, 1, 0);

    InitRoles();
    SetStats(true); // Class passives included

    if (firstspawn)
    {
        firstspawn = false;
        ASSERT(!me->GetBotAI());
        ASSERT(!me->GetBotPetAI());
        me->SetBotAI(this);

        if (!IsTempBot())
        {
            InitFaction();
            InitOwner();
            InitEquips();
        }
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
            RefreshAura(20552); //Arcane Resistance
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
            RefreshAura(6562); //Heroic Presence (28878 is not present)
            RefreshAura(20579); //Shadow Resistance (universal since creatures do not lose cast time on damage anyways)
            if (firstspawn)
                InitSpellMap(RaceSpellForClass(myrace, _botclass), true, false);
            break;
        default:
            //TC_LOG_ERROR("entities.player", "bot_ai::ApplyRacePassives(): unknown race %u for bot %s (%u)", uint32(me->GetRace()), me->GetName().c_str(), me->GetEntry());
            return;
    }
}

void bot_ai::InitFaction()
{
    NpcBotData const* npcBotData = BotDataMgr::SelectNpcBotData(me->GetEntry());
    ASSERT(npcBotData && "bot_ai::InitFaction(): data not found!");

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
    ASSERT(npcBotExtras && "bot_ai::InitRace: extra data not found!");

    me->SetByteValue(UNIT_FIELD_BYTES_0, 0, npcBotExtras->race); //set race
}

void bot_ai::InitOwner()
{
    NpcBotData const* npcBotData = BotDataMgr::SelectNpcBotData(me->GetEntry());
    ASSERT(npcBotData && "bot_ai::InitOwner(): data not found!");

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
        _roleMask = BOT_ROLE_DPS;
        if (!IsMeleeClass(_botclass))
        {
            //make about 33% of free druid bots feral
            if (_botclass != BOT_CLASS_DRUID || urand(1,100) <= 67)
                _roleMask |= BOT_ROLE_RANGED;
        }
        //if (IsHealingClass(_botclass))
        //    _roleMask |= BOT_ROLE_HEAL;

        return;
    }

    NpcBotData const* npcBotData = BotDataMgr::SelectNpcBotData(me->GetEntry());
    ASSERT(npcBotData && "bot_ai::InitRoles(): data not found!");

    _roleMask = npcBotData->roles;
}

void bot_ai::InitEquips()
{
    int8 id = 1;
    EquipmentInfo const* einfo = sObjectMgr->GetEquipmentInfo(me->GetEntry(), id);
    ASSERT(einfo && "Trying to spawn bot with no equip info!");

    NpcBotData const* npcBotData = BotDataMgr::SelectNpcBotData(me->GetEntry());
    ASSERT(npcBotData && "bot_ai::InitEquips(): data not found!");

    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_NPCBOT_EQUIP_BY_ITEM_INSTANCE);
    //                    0                   1         2            3           4         5                6                    7              8             9        10       11            12             13
    //SELECT ii.creatorGuid, ii.giftCreatorGuid, ii.count, ii.duration, ii.charges, ii.flags, ii.enchantments, ii.randomPropertyId, ii.durability, ii.playedTime, ii.text, ii.guid, ii.itemEntry, ii.owner_guid "
    //  "FROM item_instance ii JOIN characters_npcbot cn ON ii.guid IN "
    //  "(cn.equipMhEx, cn.equipOhEx, cn.equipRhEx, cn.equipHead, cn.equipShoulders, cn.equipChest, cn.equipWaist, cn.equipLegs, cn.equipFeet, cn.equipWrist, cn.equipHands, cn.equipBack, cn.equipBody, cn.equipFinger1, cn.equipFinger2, cn.equipTrinket1, cn.equipTrinket2, cn.equipNeck) "
    //  "WHERE cn.entry = ?", CONNECTION_SYNCH
    stmt->setUInt32(0, me->GetEntry());
    PreparedQueryResult iiresult = CharacterDatabase.Query(stmt);

    Field* fields2;
    uint32 itemId;
    uint32 itemGuidLow;
    Item* item;

    if (!iiresult) //blank bot - fill with standard items
    {
        for (uint8 i = 0; i != MAX_EQUIPMENT_ITEMS; ++i)
        {
            itemId = einfo->ItemEntry[i];
            if (!itemId)
                continue;

            item = Item::CreateItem(itemId, 1, nullptr);
            ASSERT(item && "Failed to init standard Item for bot!");
            _equips[i] = item;
        }
    }
    else
    {
        do
        {
            fields2 = iiresult->Fetch();
            itemGuidLow = fields2[11].GetUInt32();
            itemId = fields2[12].GetUInt32();
            item = new Item;
            ASSERT(item->LoadFromDB(itemGuidLow, ObjectGuid::Empty, fields2, itemId));
            //gonna find where to store our new item
            bool found = false;
            for (uint8 i = BOT_SLOT_MAINHAND; i != BOT_INVENTORY_SIZE; ++i)
            {
                if (npcBotData->equips[i] == itemGuidLow && !_equips[i])
                {
                    _equips[i] = item;
                    found = true;
                    break;
                }
            }
            ASSERT(found);
            //ItemTemplate const* proto = item->GetTemplate();
            //TC_LOG_ERROR("entities.player", "minion_ai::InitEquips(): bot %s (id: %u): found item: for slot %u: %s (id: %u, guidLow: %u)",
            //    me->GetName().c_str(), me->GetEntry(), i, proto->Name1.c_str(), itemId, itemGuidLow);

        } while (iiresult->NextRow());
    }

    //visualize
    for (uint8 i = BOT_SLOT_MAINHAND; i <= BOT_SLOT_RANGED; ++i)
    {
        if (CanChangeEquip(i) && _equips[i])
            me->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID + i, _equips[i]->GetEntry());
        else if (einfo->ItemEntry[i])
            me->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID + i, einfo->ItemEntry[i]);
    }

    //apply weapons' parameters
    if (Item const* MH = _equips[BOT_SLOT_MAINHAND])
    {
        itemId = MH->GetEntry();
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
        itemId = OH->GetEntry();
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
        itemId = RH->GetEntry();
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
                continue;

            //if bot has no equips but equip template then use those
            item = Item::CreateItem(einfo->ItemEntry[i], 1, nullptr);
            ASSERT(item && "Failed to init standard Item for bot point 2!");
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
}

void bot_ai::FindMaster()
{
    //totally free
    if (!_ownerGuid)
        return;
    if (!_atHome || _evadeMode)
        return;

    //delay
    if (checkMasterTimer > lastdiff)
        return;

    checkMasterTimer = urand(1000, 3000);

    //already have master
    if (!IAmFree())
        return;
    if (IsDuringTeleport())
        return;

    if (Player* player = ObjectAccessor::FindPlayerByLowGUID(_ownerGuid))
    {
        //prevent bot being screwed up because of wrong flags
        if (player->IsGameMaster() || player->GetSession()->isLogingOut())
            return;

        SetBotOwner(player);

        //fail
        if (master != player)
            return;

        //if (!IsTempBot())
        //    BotWhisper("Hey...", master);
        return;
    }
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
//Unused
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
    ItemRandomSuffixEntry const* item_rand = sItemRandomSuffixStore.LookupEntry(abs(item->GetItemRandomPropertyId()));
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
    str << me->GetLevel();

    //name
    _LocalizeItem(forPlayer, name, suffix, item);

    str << "|h[" << name;
    if (suffix.length() > 0)
        str << ' ' << suffix;
    str <<"]|h|r";

    //quantity
    if (item->GetCount() > 1)
        str << "x" << item->GetCount() << ' ';

    //TC_LOG_ERROR("entities.player", "bot_ai::_AddItemLink(): %s", str.str().c_str());
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
        str << "|cffffd000|Htrade:" << spellInfo->Id << ':' << curValue << ':' << maxValue << ':' << master->GetGUID().GetCounter() << ":6AAAAAAAAAAAAAAAAAAAAAAOAADAAAAAAAAAAAAAAAAIAAAAAAAAA" << "|h[" << skillInfo->name[loc] << "]|h|r";
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
    if (loc > 0 && itemInfo && !itemInfo->Name[loc].empty())
    {
        const std::string name = itemInfo->Name[loc];
        if (Utf8FitTo(name, wnamepart))
            itemName = name;
    }

    int32 randomPropId = item->GetItemRandomPropertyId();
    //TC_LOG_ERROR("entities.player", "bot_ai::_LocalizeItem(): randomPropId = %i", randomPropId);
    if (!randomPropId)
        return;

    if (randomPropId > 0)
    {
        if (ItemRandomPropertiesEntry const* item_rand = sItemRandomPropertiesStore.LookupEntry(randomPropId))
        {
            char* const* suffs = item_rand->nameSuffix;
            if (suffs)
            {
                //for (uint8 i = 0; i != MAX_LOCALES; ++i)
                //    TC_LOG_ERROR("entities.player", "bot_ai::_LocalizeItem(): rand prop suffix for loc %u = %s", i, suffs[i]);
                suffix = suffs[loc];
            }
        }
    }
    else
    {
        if (ItemRandomSuffixEntry const* item_rand = sItemRandomSuffixStore.LookupEntry(-randomPropId))
        {
            char* const* suffs = item_rand->nameSuffix;
            if (suffs)
            {
                //for (uint8 i = 0; i != MAX_LOCALES; ++i)
                //    TC_LOG_ERROR("entities.player", "bot_ai::_LocalizeItem(): rand suff suffix for loc %u = %s", i, suffs[i]);
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

void bot_ai::BotJump(Position const* pos)
{
    ++_jumpCount;

    me->BotStopMovement();
    me->GetMotionMaster()->MoveJump(*pos, me->GetExactDist2d(pos->m_positionX, pos->m_positionY), 10.0f);

    //float dx = pos->m_positionX - me->m_positionX;
    //float dy = pos->m_positionY - me->m_positionY;
    //float fdx = fabs(dx); float fdy = fabs(dy);
    //float divider = fdx > 400 || fdy > 400 ? 5.0f : fdx > 200 || fdy > 200 ? 3.0f : fdx > 100 || fdy > 100 ? 2.0f : 1.5f;
    //dx = dx / divider + me->m_positionX;
    //dy = dy / divider + me->m_positionY;
    //float z = me->GetMap()->GetHeight(dx, dy, std::max<float>(me->m_positionZ, pos->m_positionZ));

    //if (z > INVALID_HEIGHT)
    //    me->GetMotionMaster()->MoveJump(dx, dy, z, me->GetExactDist2d(dx, dy), 10.0f);
}

bool bot_ai::UpdateImpossibleChase(Unit const* target)
{
    if (_chaseTimer > lastdiff || me->isMoving() || !IAmFree())
        return false;

    if (JumpingOrFalling())
        return false;

    if (!me->IsWithinDist(target, HasRole(BOT_ROLE_RANGED) ? 75 : 50) || (me->GetDistance(target) < (HasRole(BOT_ROLE_RANGED) ? 35 : 10)))
    {
        ResetChaseTimer(target);
        me->GetMotionMaster()->MovePoint(me->GetMapId(), *target, false);
        return true;
    }

    if (_jumpCount >= 3)
    {
        me->AttackStop();
        Evade();
        return true;
    }

    ResetChaseTimer(target);
    if (!HasRole(BOT_ROLE_RANGED))
        BotJump(target);
    return true;
}

void bot_ai::ResetChaseTimer(Position const* /*pos*/)
{
    _chaseTimer = 30000;//std::max<uint32>(5000, me->GetDistance2d(pos->m_positionX, pos->m_positionY) * 400);
    //me->GetDistance2d(pos->m_positionX, pos->m_positionY) * 1000 / me->GetSpeed(MOVE_WALK);
}

void bot_ai::ResetChase(Position const* pos)
{
    if (!IAmFree())
        return;

    ResetChaseTimer(pos);
    _jumpCount = 0;
}

void bot_ai::OnStartAttack(Unit const* u)
{
    AdjustTankingPosition();

    if (u->GetGUID() != _lastTargetGuid)
    {
        ResetChase(u);
        _lastTargetGuid = u->GetGUID();
    }
}

void bot_ai::JustEnteredCombat(Unit* u)
{
    _atHome = false;

    //clear gossip during combat. See CheckAuras() for restore
    if (me->HasFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP))
        me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);

    if (!IAmFree())
        return;

    _evadeMode = false;
    AbortTeleport();

    ResetChase(u);
}
//killer may be NULL
void bot_ai::JustDied(Unit*)
{
    AbortTeleport();
    KillEvents(false);

    if (IsTempBot())
    {
        //TC_LOG_ERROR("entities.player", "Unsummoning temp bot %s (guidLow: %u), owner: %s (guidLow: %u)...",
        //    me->GetName().c_str(), me->GetGUID().GetCounter(), master->GetName().c_str(), master->GetGUID().GetCounter());

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

    _reviveTimer = IAmFree() ? 180000 : 60000; //3min/1min
    _atHome = false;
    _evadeMode = false;
    spawned = false;

    ++_deathsCount;
}

void bot_ai::KilledUnit(Unit* u)
{
    ++_killsCount;
    if (u->IsControlledByPlayer() || u->IsPvP())
        ++_pvpKillsCount;
    if (u->isType(TYPEMASK_PLAYER))
        ++_playerKillsCount;
}

void bot_ai::MoveInLineOfSight(Unit* /*u*/)
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
                cre->LowerPlayerDamageReq(cre->GetHealth() < damage ?  cre->GetHealth() : damage);
        }
    }

    if (victim->GetTypeId() == TYPEID_PLAYER)
        ResetChase(victim);
}
//This function is called after Spell::SendSpellCooldown() and Spell::DoAllEffects...() call
void bot_ai::OnBotSpellGo(Spell const* spell)
{
    SpellInfo const* curInfo = spell->GetSpellInfo();

    //Set cooldown
    if (!curInfo->IsCooldownStartedOnEvent() && !curInfo->IsPassive())
    {
        uint32 rec = curInfo->RecoveryTime;
        uint32 catrec = curInfo->CategoryRecoveryTime;

        if (rec > 0)
            ApplyBotSpellCooldownMods(curInfo, rec);
        if (catrec > 0 && !(curInfo->AttributesEx6 & SPELL_ATTR6_IGNORE_CATEGORY_COOLDOWN_MODS))
            ApplyBotSpellCategoryCooldownMods(curInfo, catrec);

        SetSpellCooldown(curInfo->GetFirstRankSpell()->Id, rec);
        SetSpellCategoryCooldown(curInfo->GetFirstRankSpell(), catrec);
    }

    if (curInfo->Id == PVPTRINKET)
        SetSpellCooldown(PVPTRINKET, 120000);
    if (IsPotionSpell(curInfo->Id))
        StartPotionTimer();

    OnClassSpellGo(curInfo);
}

void bot_ai::OnBotSpellInterrupted(SpellSchoolMask schoolMask, uint32 unTimeMs)
{
    SpellInfo const* info;

    for (BotSpellMap::iterator itr = _spells.begin(); itr != _spells.end(); ++itr)
    {
        info = sSpellMgr->GetSpellInfo(itr->second->spellId);
        if (!info || !(info->GetSchoolMask() & schoolMask)) continue;
        if (info->IsCooldownStartedOnEvent()) continue;
        if (info->PreventionType != SPELL_PREVENTION_TYPE_SILENCE) continue;

        itr->second->cooldown += unTimeMs;
        //TC_LOG_ERROR("entities.player", "OnBotSpellInterrupted(): Adding cooldown (%u, new: %u) to spell %s (id: %u, schoolmask: %u), reqSchoolMask = %u",
        //    unTimeMs, itr->second.second, info->SpellName[0], info->Id, info->SchoolMask, schoolMask);
    }

    GC_Timer = 0; //reset global cooldown since cast is canceled
}

void bot_ai::CastBotItemCombatSpell(Unit* target, WeaponAttackType attType, uint32 procVictim, uint32 procEx)
{
    if (!target || !target->IsAlive() || target == me)
        return;

    if (!me->CanUseAttackType(attType))
        return;

    Item* item;
    ItemTemplate const* proto;
    int8 slot;
    //int8 id = 1;
    //EquipmentInfo const* einfo = sObjectMgr->GetEquipmentInfo(me->GetEntry(), id);

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
            switch (attType)
            {
                case BASE_ATTACK:   slot = BOT_SLOT_MAINHAND;   break;
                case OFF_ATTACK:    slot = BOT_SLOT_OFFHAND;    break;
                case RANGED_ATTACK: slot = BOT_SLOT_RANGED;     break;
                default:            slot = -1;                  break;
            }
            if (slot != i)
                continue;
        }

        CastBotItemCombatSpell(target, attType, procVictim, procEx, item, proto);
    }
}

void bot_ai::CastBotItemCombatSpell(Unit* target, WeaponAttackType attType, uint32 procVictim, uint32 procEx, Item* item, ItemTemplate const* proto)
{
    //TODO: custom spell triggers maybe?

    // Can do effect if any damage done to target
    if (procVictim & PROC_FLAG_TAKEN_DAMAGE)
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
                //TC_LOG_ERROR("entities.player.items", "WORLD: unknown Item spellid %i", spellData.SpellId);
                continue;
            }

            if (me->m_extraAttacks && spellInfo->HasEffect(SPELL_EFFECT_ADD_EXTRA_ATTACKS))
                return;

            float chance = (float)spellInfo->ProcChance;

            if (spellData.SpellPPMRate)
            {
                uint32 WeaponSpeed = me->GetAttackTime(attType);
                chance = me->GetPPMProcChance(WeaponSpeed, spellData.SpellPPMRate, spellInfo);
            }
            else if (chance > 100.0f)
                chance = me->GetWeaponProcChance();

            if (roll_chance_f(chance))
            {
                CastSpellExtraArgs args(item);
                me->CastSpell(me, spellInfo->Id, args);
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
            if (pEnchant->type[s] != ITEM_ENCHANTMENT_TYPE_COMBAT_SPELL)
                continue;

            SpellEnchantProcEntry const* entry = sSpellMgr->GetSpellEnchantProcEvent(enchant_id);

            if (entry && entry->HitMask)
            {
                // Check hit/crit/dodge/parry requirement
                if ((entry->HitMask & procEx) == 0)
                    continue;
            }
            else
            {
                // Can do effect if any damage done to target
                if (!(procVictim & PROC_FLAG_TAKEN_DAMAGE))
                    continue;
            }

            SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(pEnchant->spellid[s]);
            if (!spellInfo)
            {
                //TC_LOG_ERROR("entities.player.items", "Player::CastItemCombatSpell(GUID: %u, name: %s, enchant: %i): unknown spell %i is casted, ignoring...",
                //    GetGUID().GetCounter(), GetName().c_str(), pEnchant->ID, pEnchant->spellid[s]);
                continue;
            }

            float chance = pEnchant->amount[s] != 0 ? float(pEnchant->amount[s]) : me->GetWeaponProcChance();

            if (entry)
            {
                if (entry->ProcsPerMinute)
                {
                    chance = me->GetPPMProcChance(proto->Delay, entry->ProcsPerMinute, spellInfo);
                    //handle SPELLMOD_PROC_PER_MINUTE spellmods
                    if (_botclass == BOT_CLASS_ROGUE)
                    {
                        //Improved Poisons
                        if (me->GetLevel() >= 25 && (spellInfo->SpellFamilyFlags[0] & 0x2000))
                            chance *= 1.5f;
                    }
                }
                else if (entry->Chance)
                    chance = (float)entry->Chance;
            }

            // Apply SPELLMOD_CHANCE_OF_SUCCESS spell mods
            if (_botclass == BOT_CLASS_ROGUE)
            {
                //Improved Poisons
                if (me->GetLevel() >= 25 && (spellInfo->SpellFamilyFlags[0] & 0x10000))
                    chance += 20.f;
            }

            // Shiv has 100% chance to apply the poison
            if (me->FindCurrentSpellBySpellId(5938) && e_slot == TEMP_ENCHANTMENT_SLOT)
                chance = 100.0f;

            if (roll_chance_f(chance))
            {
                CastSpellExtraArgs args(item);
                me->CastSpell(spellInfo->IsPositive() ? me : target, spellInfo->Id, args);
            }
        }
    }
}
//GLOBAL UPDATE
//opponent unsafe
bool bot_ai::GlobalUpdate(uint32 diff)
{
    if (allBotsLoaded == false)
    {
        //TC_LOG_ERROR("entities.unit", "GlobalUpdate: bots are not loaded!");
        return false;
    }

    ReduceCD(diff);

    lastdiff = diff;

    if (_updateTimerMedium <= diff)
    {
        _updateTimerMedium = 500;

        //Medium-timed updates

        //send stats update for group frames
        if (me->IsInWorld() && !IAmFree())
        {
            if (Group const* gr = master->GetGroup())
            {
                if (gr->IsMember(me->GetGUID()))
                {
                    WorldPacket data;
                    BuildGrouUpdatePacket(&data);

                    Player* member;
                    for (GroupReference const* itr = gr->GetFirstMember(); itr != nullptr; itr = itr->next())
                    {
                        member = itr->GetSource();
                        if (member/* && !member->IsWithinDist(me, member->GetSightRange(), false)*/)
                            member->GetSession()->SendPacket(&data);
                    }
                }
            }

            //update pvp state
            if (me->GetByteValue(UNIT_FIELD_BYTES_2, 1) != master->GetByteValue(UNIT_FIELD_BYTES_2, 1))
                me->SetByteValue(UNIT_FIELD_BYTES_2, 1, master->GetByteValue(UNIT_FIELD_BYTES_2, 1));
        }
    }

    if (!me->IsAlive())
        return false;

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

    //if (me->HasInvisibilityAura() || me->HasStealthAura())
    //    return false;

    //Check current cast state: interrupt casts that became pointless
    if (me->HasUnitState(UNIT_STATE_CASTING) && urand(1,100) <= 75)
    {
        bool interrupt;
        for (uint8 i = CURRENT_FIRST_NON_MELEE_SPELL; i != CURRENT_AUTOREPEAT_SPELL; ++i)
        {
            interrupt = false;
            Spell const* spell = me->GetCurrentSpell(CurrentSpellTypes(i));
            if (!spell)
                continue;
            Unit const* target = spell->m_targets.GetUnitTarget();
            if (!target)
                continue;
            SpellInfo const* info = spell->GetSpellInfo();
            if (!info->CastTimeEntry)
                continue;
            if (!info->IsPositive())
            {
                if (!target->IsAlive())
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
                    !me->IsWithinLOSInMap(target))
                    interrupt = true; //LoS
                else if (info->Id == 64382 && !target->HasAuraWithMechanic(1<<MECHANIC_IMMUNE_SHIELD))
                    interrupt = true; //Shattering Throw wasting
            }
            if (!interrupt && !(target == master && me->GetDistance(target) < INTERACTION_DISTANCE) &&
                info->HasEffect(SPELL_EFFECT_HEAL) && GetHealthPCT(target) > 90)
            {
                bool isAreaSpell = false;
                for (uint8 j = 0; j != 3 && isAreaSpell == false; ++j)
                {
                    if (info->Effects[j].IsEffect() && info->Effects[j].TargetA.GetTarget())
                    {
                        if (info->Effects[j].TargetA.GetSelectionCategory() == TARGET_SELECT_CATEGORY_NEARBY ||
                            info->Effects[j].TargetA.GetSelectionCategory() == TARGET_SELECT_CATEGORY_AREA)
                            isAreaSpell = true;
                        if (!isAreaSpell)
                        {
                            switch (info->Effects[j].TargetA.GetTarget())
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

            if (interrupt)
            {
                me->InterruptSpell(CurrentSpellTypes(i));
                GC_Timer = 0;
                break;
            }
        }
    }

    if (_updateTimerEx1 <= diff && !IAmFree())
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
        //        else if (m_botCommandState != COMMAND_STAY && !me->isMoving())
        //        {
        //            m_botCommandState = COMMAND_ABANDON; //reset movement after
        //        }
        //    }
        //}

        //Gathering
        if (me->IsInWorld() && (_roleMask & BOT_ROLE_MASK_GATHERING) && !me->IsInCombat() && !master->IsInCombat() && !master->IsMounted() && !CCed(me) &&
            master->GetLootGUID().IsEmpty() && !me->isMoving() && !master->isMoving() && master->IsStandState() && !Feasting() && !IsCasting() && !IsCasting(master))
        {
            //TC_LOG_ERROR("spells", "bot_ai:UpdateEx by %s, found free master, my skills: %u:", me->GetName().c_str(), uint32(_roleMask & BOT_ROLE_MASK_GATHERING));
            std::list<WorldObject*> woList;
            NearbyObjectBySkillCheck check(master, INTERACTION_DISTANCE - 1.0f, (_roleMask & BOT_ROLE_MASK_GATHERING));
            Trinity::WorldObjectListSearcher<NearbyObjectBySkillCheck> searcher(me, woList, check, GRID_MAP_TYPE_MASK_CREATURE|GRID_MAP_TYPE_MASK_GAMEOBJECT);
            Cell::VisitAllObjects(me, searcher, 20.f);
            //me->VisitNearbyObject(20.f, searcher);
            //TC_LOG_ERROR("spells", "bot_ai:UpdateEx: list is %s", woList.empty() ? "empty" : "not empty");
            if (!woList.empty())
            {
                WorldObject* wo = Trinity::Containers::SelectRandomContainerElement(woList);
                //TC_LOG_ERROR("spells", "bot_ai:UpdateEx: processing %s", wo->GetName().c_str());
                if (me->GetDistance(wo) <= INTERACTION_DISTANCE * 0.5f && me->HasInArc(M_PI * 0.75f, wo))
                {
                    //cosmetic
                    CastSpellExtraArgs args(TRIGGERED_FULL_MASK);
                    me->CastSpell(wo->GetTypeId() == TYPEID_UNIT ? wo->ToUnit() : me, SPELL_COMBAT_SPECIAL_2H_ATTACK, args);

                    master->SendLoot(wo->GetGUID(), LOOT_SKINNING);

                    if (wo->GetTypeId() == TYPEID_UNIT)
                        wo->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_SKINNABLE);

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
                        me->GetMotionMaster()->MovePoint(me->GetMapId(), pos, false);
                    }
                    else
                    {
                        me->SetFacingTo(me->GetAbsoluteAngle(wo));
                        _updateTimerEx1 = urand(1500, 1800);
                    }
                }
            }
        }
    }

    if (_bootTimer >= 0 && _bootTimer <= int32(lastdiff))
    {
        //timer will be cancelled at bot removal so we are always free here
        //_bootTimer = -1; //Set in AbortTeleport()
        //master->m_Controlled.erase(me);
        BotMgr::TeleportBot(me, master->GetMap(), master);
        return false;
    }

    if (!IsTempBot())
    {
        Regenerate();
        _updateRations(); //safe
    }

    CheckAttackState();

    //update flags
    if (!me->IsInCombat() && !_evadeMode && _atHome)
    {
        if (!me->HasFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP))
            me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
        if (me->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_PET_IN_COMBAT))
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_PET_IN_COMBAT);
    }

    if (checkAurasTimer <= lastdiff)
    {
        Unit* victim = me->GetVictim(); //safe
        checkAurasTimer += uint32(__rand + __rand + (IAmFree() ? 1000 : 40 * (1 + master->GetNpcBotsCount())));

        //group demand
        if (!IAmFree() && HasRole(BOT_ROLE_PARTY) && (!master->GetGroup() || !master->GetGroup()->IsMember(me->GetGUID())))
        {
            //TC_LOG_ERROR("entities.player", "CheckAuras(): adding %s to group", me->GetName().c_str());
            master->GetBotMgr()->AddBotToGroup(me);
        }

        if (m_botCommandState != COMMAND_FOLLOW && m_botCommandState != COMMAND_STAY && victim && !CCed(me, true) &&
            !me->isMoving() && !IsCasting() && !IsShootingWand())
        {
            if (!IAmFree() && master->GetBotMgr()->GetBotAttackRangeMode() == BOT_ATTACK_RANGE_EXACT &&
                master->GetBotMgr()->GetBotExactAttackRange() == 0)
            {
                GetInPosition(true, victim);
            }
            else if (!HasRole(BOT_ROLE_RANGED))
            {
                if (me->GetDistance(victim) > 1.5f)
                    GetInPosition(true, victim);
            }
            else
            {
                CalculateAttackPos(victim, attackpos);
                if (me->GetExactDist2d(&attackpos) > 4.f || !me->IsWithinLOSInMap(victim))
                    GetInPosition(true, victim, &attackpos);
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
        if (_atHome && Rand() < 10)
            _atHome = false;
    }

    if (Wait())
        return false;

    FindMaster();

    GenerateRand();
    BreakCC(diff);

    if (CCed(me))
        return false;

    //opponent unsafe
    if (!opponent && !IAmFree())
    {
        if (!master->IsAlive())
        {
            //If ghost move to corpse, else move to dead player
            if (master->HasFlag(PLAYER_FLAGS, PLAYER_FLAGS_GHOST))
            {
                Corpse const* corpse = master->GetCorpse();
                if (corpse && me->GetMap() == corpse->FindMap() && !me->IsInCombat() && !me->HasUnitState(UNIT_STATE_MOVING) &&
                    !IsCasting() && !IsShootingWand() && !CCed(me) && me->GetDistance(corpse) > 5)
                    me->GetMotionMaster()->MovePoint(corpse->GetMapId(), *corpse);
            }
            else
            {
                if (m_botCommandState != COMMAND_FOLLOW || me->GetDistance(master) > 30 - 20 * (!me->IsWithinLOSInMap(master)))
                    Follow(true);
            }
        }
        else if (m_botCommandState != COMMAND_STAY && !IsCasting() && (!IsShootingWand() || Rand() < 10))
        {
            _calculatePos(pos);
            float maxdist = std::max<float>(master->GetBotMgr()->GetBotFollowDist() * (master->isMoving() ? 0.02f : 0.35f), 4.f);
            if (!me->isMoving())
            {
                if (me->GetExactDist(&pos) > maxdist)
                    Follow(true, &pos);
            }
            else
            {
                Position destPos;
                me->GetMotionMaster()->GetDestination(destPos.m_positionX, destPos.m_positionY, destPos.m_positionZ);
                if (destPos.GetExactDist(&pos) > maxdist)
                    Follow(true, &pos);
            }
        }
    }
    if (!IsCasting() && !IsShootingWand())
    {
        if ((me->IsInCombat() && !me->IsSitState()) || !CanSheath())
        {
            if (_botclass == BOT_CLASS_HUNTER || _botclass == BOT_CLASS_DARK_RANGER)
            {
                if (me->GetSheath() != SHEATH_STATE_RANGED)
                    me->SetSheath(SHEATH_STATE_RANGED);
            }
            else if (me->GetSheath() != SHEATH_STATE_MELEE)
                me->SetSheath(SHEATH_STATE_MELEE);
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

    return true;
}

void bot_ai::CommonTimers(uint32 diff)
{
    Events.Update(diff);
    SpellTimers(diff);

    if (GC_Timer > diff)            GC_Timer -= diff;
    if (checkAurasTimer > diff)     checkAurasTimer -= diff;
    if (waitTimer > diff)           waitTimer -= diff;
    if (roleTimer > diff)           roleTimer -= diff;
    if (checkMasterTimer > diff)    checkMasterTimer -= diff;

    if (_powersTimer > diff)        _powersTimer -= diff;
    if (_chaseTimer > diff)         _chaseTimer -= diff;

    if (_potionTimer > diff && (_potionTimer < POTION_CD || !me->IsInCombat())) _potionTimer -= diff;

    if (IAmFree())
        UpdateReviveTimer(diff);

    if (_bootTimer > int32(diff))   _bootTimer -= diff;

    if (_updateTimerMedium > diff)  _updateTimerMedium -= diff;
    if (_updateTimerEx1 > diff)     _updateTimerEx1 -= diff;
}

void bot_ai::UpdateReviveTimer(uint32 diff)
{
    if (me->IsAlive())
        return;

    if (_reviveTimer > diff)        _reviveTimer -= diff;
    else
    {
        if (IAmFree())
            BotMgr::ReviveBot(me);
        else
            if (_reviveTimer > 0)   _reviveTimer = 0;
    }
}

void bot_ai::Evade()
{
    if (_atHome && !_evadeMode)
        return;
    //if (me->IsInCombat())
    //    return;
    if (me->GetVictim())
        return;
    if (IsCasting())
        return;
    if (CCed(me, true))
        return;

    _atHome = true;

    if (!IAmFree() || IsTempBot())
    {
        _evadeMode = false;
        return;
    }

    uint16 mapid;
    Position pos;
    GetHomePosition(mapid, &pos);

    if (mapid != me->GetMapId() || _evadeCount >= 3 || me->GetDistance(pos) > 1000.f)
    {
        //TeleportHome();

        if (!teleHomeEvent || !teleHomeEvent->IsActive())
        {
            teleHomeEvent = new TeleportHomeEvent(this);
            Events.AddEvent(teleHomeEvent, Events.CalculateTime(5000));

            //if bot has been removed manually and while in dungeon
            if (mapid != me->GetMapId())
            {
                teleHomeEvent->ScheduleAbort();
                teleHomeEvent->Execute(0,0);
            }
        }
        _evadeMode = false;
        return;
    }

    float dist = me->GetDistance(pos);
    if (dist > 1.5f)
    {
        if (!_evadeMode)
            ++_evadeCount;
        else if (Rand() < 4 && fabs(me->GetPositionZ() - pos.GetPositionZ()) > 30.f && !me->HasInArc(M_PI*0.5f, &pos))
            ++_evadeCount;
        else if (me->isMoving() && Rand() > 10)
            return;

        _evadeMode = true;

        //me->BotStopMovement();

        bool farpoint = true;
        if (dist > 50)
        {
            float dx = pos.m_positionX - me->m_positionX;
            float dy = pos.m_positionY - me->m_positionY;
            float fdx = fabs(dx); float fdy = fabs(dy);
            float divider =
                fdx > 900  || fdy > 900  ?  60.0f :
                fdx > 600  || fdy > 600  ?  30.0f :
                fdx > 400  || fdy > 400  ?  20.0f :
                fdx > 200  || fdy > 200  ?  10.0f :
                fdx > 100  || fdy > 100  ?   7.0f : 3.0f;
            dx = dx / divider + me->m_positionX;
            dy = dy / divider + me->m_positionY;
            float z = me->GetMap()->GetHeight(dx, dy, me->m_positionZ);

            if (z > INVALID_HEIGHT && fabs(me->m_positionZ - z) > 0.05f)
            {
                me->GetMotionMaster()->MovePoint(mapid, dx, dy, z + 0.1f, true);
                farpoint = false;
            }
        }

        if (farpoint)
            me->GetMotionMaster()->MovePoint(mapid, pos);

        return;
    }

    if (me->isMoving())
        return;

    _evadeMode = false;
    _evadeCount = 0;

    me->SetFacingTo(pos.GetOrientation());
    me->SetFaction(me->GetCreatureTemplate()->faction);
}
//TeleportHome() ONLY CALLED THROUGH EVENTPROCESSOR
void bot_ai::TeleportHome()
{
    ASSERT(teleHomeEvent);
    //ASSERT(IAmFree());

    AbortTeleport();

    uint16 mapid;
    Position pos;
    GetHomePosition(mapid, &pos);

    Map* map = sMapMgr->CreateBaseMap(mapid);
    ASSERT(map && !map->Instanceable());
    BotMgr::TeleportBot(me, map, &pos);

    spawned = false;
    _evadeCount = 0;
}
//FinishTeleport(uint32, float, float, float, float) ONLY CALLED THROUGH EVENTPROCESSOR
bool bot_ai::FinishTeleport(/*uint32 mapId, uint32 instanceId, float x, float y, float z, float o*/)
{
    ASSERT(teleFinishEvent);
    //ASSERT(!IAmFree());
    ASSERT(!me->IsInWorld());

    AbortTeleport();

    //1) Cannot teleport: master disappeared - return home
    if (IAmFree()/* || master->GetSession()->isLogingOut()*/)
    {
        uint16 mapid;
        Position pos;
        GetHomePosition(mapid, &pos);

        teleHomeEvent = new TeleportHomeEvent(this);
        Events.AddEvent(teleHomeEvent, Events.CalculateTime(0)); //make sure event will be deleted
        if (teleHomeEvent->IsActive())
            teleHomeEvent->ScheduleAbort(); //make sure event will not be executed twice
        teleHomeEvent->Execute(0,0);
        _evadeMode = false;

        return false;
    }

    Map* map = master->FindMap();
    //2) Cannot teleport: map not found or forbidden - delay teleport
    if (!map || !master->IsAlive() || master->GetBotMgr()->RestrictBots(me, true))
    {
        //ChatHandler ch(master->GetSession());
        //ch.PSendSysMessage("Your bot %s cannot teleport to you. Restricted bot access on this map...", me->GetName().c_str());
        teleFinishEvent = new TeleportFinishEvent(this);
        Events.AddEvent(teleFinishEvent, Events.CalculateTime(5000));
        return false;
    }

    me->SetMap(map);
    me->Relocate(master);
    map->AddToMap(me);
    me->BotStopMovement();
    //bot->SetAI(oldAI);
    //me->IsAIEnabled = true;
    canUpdate = true;

    //master->m_Controlled.insert(me);
    CastSpellExtraArgs args(TRIGGERED_FULL_MASK);
    me->CastSpell(me, COSMETIC_TELEPORT_EFFECT, args);
    //me->CastSpell(me, HONORLESS_TARGET, true);

    //update group member online state
    if (Group* gr = master->GetGroup())
        if (gr->IsMember(me->GetGUID()))
            gr->SendUpdate();

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

    CancelBoot();
}

void bot_ai::GetHomePosition(uint16& mapid, Position* pos) const
{
    CreatureData const* data = me->GetCreatureData();
    mapid = data->spawnPoint.GetMapId();
    pos->Relocate(data->spawnPoint.GetPositionX(), data->spawnPoint.GetPositionY(), data->spawnPoint.GetPositionZ(), data->spawnPoint.GetOrientation());
}

void bot_ai::KillEvents(bool force)
{
    Events.KillAllEvents(force);
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

void bot_ai::BuildGrouUpdatePacket(WorldPacket* data)
{
    uint32 mask = GROUP_UPDATE_FULL;

    if (mask & GROUP_UPDATE_FLAG_POWER_TYPE)                // if update power type, update current/max power also
        mask |= (GROUP_UPDATE_FLAG_CUR_POWER | GROUP_UPDATE_FLAG_MAX_POWER);

    if (mask & GROUP_UPDATE_FLAG_PET_POWER_TYPE)            // same for pets
        mask |= (GROUP_UPDATE_FLAG_PET_CUR_POWER | GROUP_UPDATE_FLAG_PET_MAX_POWER);

    uint32 byteCount = 0;
    for (uint8 i = 1; i < GROUP_UPDATE_FLAGS_COUNT; ++i)
        if (mask & (1 << i))
            byteCount += GroupUpdateLength[i];

    data->Initialize(SMSG_PARTY_MEMBER_STATS, 8 + 4 + byteCount);
    *data << me->GetGUID().WriteAsPacked();
    *data << uint32(mask);

    if (mask & GROUP_UPDATE_FLAG_STATUS)
    {
        uint16 playerStatus = MEMBER_STATUS_ONLINE;
        if (me->IsPvP())
            playerStatus |= MEMBER_STATUS_PVP;

        if (!me->IsAlive())
            playerStatus |= MEMBER_STATUS_DEAD;

        if (me->HasByteFlag(UNIT_FIELD_BYTES_2, 1, UNIT_BYTE2_FLAG_FFA_PVP))
            playerStatus |= MEMBER_STATUS_PVP_FFA;

        *data << uint16(playerStatus);
    }

    if (mask & GROUP_UPDATE_FLAG_CUR_HP)
        *data << uint32(me->GetHealth());

    if (mask & GROUP_UPDATE_FLAG_MAX_HP)
        *data << uint32(me->GetMaxHealth());

    Powers powerType = me->GetPowerType();
    if (mask & GROUP_UPDATE_FLAG_POWER_TYPE)
        *data << uint8(powerType);

    if (mask & GROUP_UPDATE_FLAG_CUR_POWER)
        *data << uint16(me->GetPower(powerType));

    if (mask & GROUP_UPDATE_FLAG_MAX_POWER)
        *data << uint16(me->GetMaxPower(powerType));

    if (mask & GROUP_UPDATE_FLAG_LEVEL)
        *data << uint16(me->GetLevel());

    if (mask & GROUP_UPDATE_FLAG_ZONE)
        *data << uint16(me->GetZoneId());

    if (mask & GROUP_UPDATE_FLAG_POSITION)
    {
        *data << uint16(me->GetPositionX());
        *data << uint16(me->GetPositionY());
    }

    //TODO: ...?
    //if (mask & GROUP_UPDATE_FLAG_AURAS)
    //{
    //    uint64 auramask = player->GetAuraUpdateMaskForRaid();
    //    *data << uint64(auramask);
    //    for (uint32 i = 0; i < MAX_AURAS_GROUP_UPDATE; ++i)
    //    {
    //        if (auramask & (uint64(1) << i))
    //        {
    //            AuraApplication const* aurApp = player->GetVisibleAura(i);
    //            *data << uint32(aurApp ? aurApp->GetBase()->GetId() : 0);
    //            *data << uint8(1);
    //        }
    //    }
    //}

    //if (mask & GROUP_UPDATE_FLAG_VEHICLE_SEAT)
    //{
    //    if (Vehicle* veh = me->GetVehicle())
    //        *data << uint32(veh->GetVehicleInfo()->m_seatID[me->m_movementInfo.transport.seat]);
    //    else
    //        *data << uint32(0);
    //}
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
uint8 bot_ai::GetBotStance() const
{
    return BOT_STANCE_NONE;
}

uint8 bot_ai::GetPlayerClass() const
{
    if (_botclass >= BOT_CLASS_EX_START)
    {
        switch (_botclass)
        {
            case BOT_CLASS_BM:
                return BOT_CLASS_WARRIOR;
            case BOT_CLASS_SPHYNX:
                return BOT_CLASS_WARLOCK;
            case BOT_CLASS_ARCHMAGE:
                return BOT_CLASS_MAGE;
            case BOT_CLASS_DREADLORD:
                return BOT_CLASS_WARLOCK;
            case BOT_CLASS_SPELLBREAKER:
                return BOT_CLASS_PALADIN;
            case BOT_CLASS_DARK_RANGER:
                return BOT_CLASS_ROGUE;
            default:
                TC_LOG_ERROR("entities.unit", "GetPlayerClass: %s has unknown Ex bot class %u!", me->GetName().c_str(), _botclass);
                return BOT_CLASS_PALADIN;
        }
    }

    return _botclass;
}
uint8 bot_ai::GetPlayerRace() const
{
    if (_botclass >= BOT_CLASS_EX_START)
    {
        switch (_botclass)
        {
            case BOT_CLASS_BM:
                return RACE_ORC;
            case BOT_CLASS_SPHYNX:
                return RACE_UNDEAD_PLAYER;
            case BOT_CLASS_ARCHMAGE:
                return RACE_HUMAN;
            case BOT_CLASS_DREADLORD:
                return RACE_UNDEAD_PLAYER;
            case BOT_CLASS_SPELLBREAKER:
                return RACE_BLOODELF;
            case BOT_CLASS_DARK_RANGER:
                return RACE_BLOODELF;
            default:
                TC_LOG_ERROR("entities.unit", "GetPlayerRace: %s has unknown Ex bot class %u!", me->GetName().c_str(), _botclass);
                return RACE_HUMAN;
        }
    }

    return me->GetRace();
}

uint8 bot_ai::GetBotComboPoints() const
{
    return uint8(GetAIMiscValue(BOTAI_MISC_COMBO_POINTS));
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
        m_class == BOT_CLASS_SPELLBREAKER);
}
bool bot_ai::IsTankingClass(uint8 m_class)
{
    return (m_class == CLASS_WARRIOR || m_class == CLASS_PALADIN ||
        m_class == CLASS_DEATH_KNIGHT || m_class == BOT_CLASS_SPHYNX || m_class == BOT_CLASS_SPELLBREAKER);
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
        m_class == BOT_CLASS_SPELLBREAKER || m_class == BOT_CLASS_DARK_RANGER);
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
    return m_class == BOT_CLASS_BM || m_class == BOT_CLASS_ARCHMAGE ||
        m_class == BOT_CLASS_DREADLORD || m_class == BOT_CLASS_DARK_RANGER;
}
bool bot_ai::IsMelee() const
{
    return !HasRole(BOT_ROLE_RANGED) && HasRole(BOT_ROLE_DPS|BOT_ROLE_TANK);
}

bool bot_ai::IsShootingWand(Unit const* u) const
{
    if (!u) u = me;

    Spell const* spell = u->GetCurrentSpell(CURRENT_AUTOREPEAT_SPELL);
    return spell && spell->GetSpellInfo()->Id == SHOOT_WAND;
}

void bot_ai::StartPotionTimer()
{
    _potionTimer = POTION_CD;
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
            return true;
        default:
            return _botclass < BOT_CLASS_EX_START;
    }
}
bool bot_ai::CanUseAmmo() const
{
    if ((_botclass == BOT_CLASS_HUNTER || _botclass == BOT_CLASS_ROGUE ||
        _botclass == BOT_CLASS_WARRIOR || _botclass == BOT_CLASS_DARK_RANGER) &&
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
        _botclass != BOT_CLASS_DREADLORD && _botclass != BOT_CLASS_SPELLBREAKER && _botclass != BOT_CLASS_DARK_RANGER) ||
        slot > BOT_SLOT_RANGED;
}

bool bot_ai::GossipHello(Player* player)
{
    return OnGossipHello(player, 0);
}
bool bot_ai::GossipSelect(Player* player, uint32 menuId, uint32 gossipListId)
{
    uint32 sender = player->PlayerTalkClass->GetGossipOptionSender(gossipListId);
    uint32 action = player->PlayerTalkClass->GetGossipOptionAction(gossipListId);
    return OnGossipSelect(player, me, sender, action);
}
bool bot_ai::GossipSelectCode(Player* player, uint32 menuId, uint32 gossipListId, char const* code)
{
    uint32 sender = player->PlayerTalkClass->GetGossipOptionSender(gossipListId);
    uint32 action = player->PlayerTalkClass->GetGossipOptionAction(gossipListId);
    return OnGossipSelectCode(player, me, sender, action, code);
}

bool bot_ai::IsBotCustomSpell(uint32 spellId)
{
    return BotCustomSpells.find(spellId) != BotCustomSpells.end();
}

void bot_ai::InitBotCustomSpells()
{
    if (SPELLS_DEFINED)
    {
        //TC_LOG_ERROR("entities.player", "Bot custom spells initialization... fail...");
        return;
    }
    //TC_LOG_ERROR("entities.player", "Bot custom spells initialization... success...");
    SPELLS_DEFINED = true;

    //see bot_ai.h::CommonValues::CUSTOM_SPELLS
    //all ids must be here

    //BotCustomSpells.insert(SPELL_COMBAT_SPECIAL_2H_ATTACK); //exclusive
    BotCustomSpells.insert(SPELL_TRANSPARENCY_50);//3.1
    BotCustomSpells.insert(SPELL_NETHERWALK);//3
    BotCustomSpells.insert(SPELL_MIRROR_IMAGE_BM);//4
    BotCustomSpells.insert(SPELL_SHADOW_BLAST);//5
    BotCustomSpells.insert(SPELL_SHADOW_BOLT);//6
    //BotCustomSpells.insert(SPELL_ATTACK_MELEE_RANDOM);//7 //exclusive
    //BotCustomSpells.insert(SHADOWFURY_VISUAL);//8 //exclusive
    BotCustomSpells.insert(SPELL_DEVOUR_MAGIC);//9
    BotCustomSpells.insert(SPELL_DRAIN_MANA);//10
    BotCustomSpells.insert(SPELL_REPLENISH_MANA);//11
    BotCustomSpells.insert(SPELL_REPLENISH_HEALTH);//12
    BotCustomSpells.insert(SPELL_BRILLIANCE_AURA);//13
    BotCustomSpells.insert(SPELL_FIREBALL);//14
    BotCustomSpells.insert(SPELL_BLIZZARD);//15
    BotCustomSpells.insert(SPELL_SUMMON_WATER_ELEMENTAL);//16
    BotCustomSpells.insert(SPELL_WATERBOLT);//17
    BotCustomSpells.insert(SPELL_VAMPIRIC_AURA);//18
    //BotCustomSpells.insert(SPELL_TRIGGERED_HEAL);//19 //exclusive
    BotCustomSpells.insert(SPELL_SLEEP);//20
    BotCustomSpells.insert(SPELL_CARRION_SWARM);//21
    BotCustomSpells.insert(SPELL_INFERNO);//22
    //BotCustomSpells.insert(SPELL_INFERNO_METEOR_VISUAL);//23 //exclusive
    //BotCustomSpells.insert(SPELL_STEAL_MAGIC);//24 //exclusive
    BotCustomSpells.insert(SPELL_FEEDBACK);//25
    //BotCustomSpells.insert(SPELL_BLACK_ARROW);//26 //exclusive
    //BotCustomSpells.insert(SPELL_DRAIN_LIFE);//27 //exclusive
    //BotCustomSpells.insert(SPELL_SILENCE);//28 //exclusive

    uint32 trig;
    SpellInfo* trigInfo;
    uint32 spellId;
    SpellInfo* sinfo;

    //BLADEMASTER

    //2) SPELL_COMBAT_SPECIAL_2H_ATTACK
    spellId = SPELL_COMBAT_SPECIAL_2H_ATTACK; //1132
    sinfo = const_cast<SpellInfo*>(sSpellMgr->GetSpellInfo(spellId));
    sinfo->RangeEntry = sSpellRangeStore.LookupEntry(6); //6 - 100 yds
    sinfo->Attributes &= ~(SPELL_ATTR0_CANT_USED_IN_COMBAT);
    sinfo->AttributesEx2 |= SPELL_ATTR2_CAN_TARGET_DEAD;
    //2) END SPELL_COMBAT_SPECIAL_2H_ATTACK

    //3) WINDWALK
    //3.1) TRANSPARENCY
    trig = SPELL_TRANSPARENCY_50; //44816
    trigInfo = const_cast<SpellInfo*>(sSpellMgr->GetSpellInfo(trig));
    trigInfo->Attributes |= (SPELL_ATTR0_NOT_SHAPESHIFT | SPELL_ATTR0_CASTABLE_WHILE_SITTING);
    trigInfo->AttributesEx |= (SPELL_ATTR1_NOT_BREAK_STEALTH);
    trigInfo->AuraInterruptFlags =
        AURA_INTERRUPT_FLAG_SPELL_ATTACK | AURA_INTERRUPT_FLAG_MELEE_ATTACK |
        AURA_INTERRUPT_FLAG_NOT_ABOVEWATER | AURA_INTERRUPT_FLAG_MOUNT; //0x00003C07;vanish
    trigInfo->CasterAuraStateNot = 0;
    //3.1) END TRANSPARENCY

    spellId = SPELL_NETHERWALK; //31599
    sinfo = const_cast<SpellInfo*>(sSpellMgr->GetSpellInfo(spellId));

    sinfo->SpellLevel = 0;
    sinfo->MaxLevel = 0;
    sinfo->RecoveryTime = 5000;
    sinfo->PowerType = POWER_MANA;
    sinfo->ManaCost = 75 * 5;
    sinfo->ManaCostPercentage = 0;
    sinfo->ManaCostPerlevel = 0;
    sinfo->Attributes &= ~(SPELL_ATTR0_UNK11);
    sinfo->Attributes |= (SPELL_ATTR0_NOT_SHAPESHIFT | SPELL_ATTR0_CASTABLE_WHILE_SITTING | SPELL_ATTR0_UNAFFECTED_BY_INVULNERABILITY);
    sinfo->AttributesEx &= ~SPELL_ATTR1_UNK11;
    sinfo->AttributesEx |= (SPELL_ATTR1_NOT_BREAK_STEALTH | SPELL_ATTR1_NO_THREAT);
    sinfo->AttributesEx2 |= SPELL_ATTR2_UNK1;
    sinfo->AuraInterruptFlags =
        AURA_INTERRUPT_FLAG_SPELL_ATTACK | AURA_INTERRUPT_FLAG_MELEE_ATTACK |
        AURA_INTERRUPT_FLAG_NOT_ABOVEWATER | AURA_INTERRUPT_FLAG_MOUNT; //0x00003C07;vanish
    sinfo->CasterAuraStateNot = 0;

    sinfo->Effects[0].Effect = SPELL_EFFECT_APPLY_AURA;
    sinfo->Effects[0].BasePoints = 100;
    sinfo->Effects[0].RealPointsPerLevel = 2.5f;
    sinfo->Effects[0].ValueMultiplier = 1.0f;
    sinfo->Effects[0].TargetA = SpellImplicitTargetInfo(TARGET_UNIT_CASTER);
    sinfo->Effects[0].ApplyAuraName = SPELL_AURA_MOD_INVISIBILITY;
    sinfo->Effects[0].Amplitude = 0;
    sinfo->Effects[0].TriggerSpell = 0;
    sinfo->Effects[0].RadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_0_YARDS);

    sinfo->Effects[1].Effect = SPELL_EFFECT_APPLY_AURA;
    sinfo->Effects[1].BasePoints = 10;
    sinfo->Effects[1].RealPointsPerLevel = 0.5f;
    sinfo->Effects[1].ValueMultiplier = 1.0f;
    sinfo->Effects[1].TargetA = SpellImplicitTargetInfo(TARGET_UNIT_CASTER);
    sinfo->Effects[1].TargetB = SpellImplicitTargetInfo(0);
    sinfo->Effects[1].ApplyAuraName = SPELL_AURA_MOD_INCREASE_SPEED;
    sinfo->Effects[1].Amplitude = 0;
    sinfo->Effects[1].TriggerSpell = 0;
    sinfo->Effects[1].RadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_0_YARDS); //14

    sinfo->Effects[2].Effect = SPELL_EFFECT_TRIGGER_SPELL;
    sinfo->Effects[2].BasePoints = 0;
    sinfo->Effects[2].TargetA = SpellImplicitTargetInfo(TARGET_UNIT_CASTER);
    sinfo->Effects[2].TargetB = SpellImplicitTargetInfo(0);
    sinfo->Effects[2].ApplyAuraName = SPELL_AURA_NONE;
    sinfo->Effects[2].Amplitude = 0;
    sinfo->Effects[2].TriggerSpell = trig;
    sinfo->Effects[2].RadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_0_YARDS); //14
    //3) END WINDWALK

    //4) MIRROR IMAGE (BLADEMASTER)
    spellId = SPELL_MIRROR_IMAGE_BM; //69936
    sinfo = const_cast<SpellInfo*>(sSpellMgr->GetSpellInfo(spellId));

    sinfo->RangeEntry = sSpellRangeStore.LookupEntry(1); //1 - self only //6 - 100 yds
    sinfo->DurationEntry = sSpellDurationStore.LookupEntry(566); //566 - 0 sec //3 - 60 sec //1 - 10 sec //32 - 6 seconds
    sinfo->RecoveryTime = 8000;
    sinfo->PowerType = POWER_MANA;
    sinfo->ManaCost = 125 * 5;
    sinfo->ManaCostPercentage = 0;
    sinfo->ManaCostPerlevel = 0;
    sinfo->Attributes |= (SPELL_ATTR0_NOT_SHAPESHIFT/* | SPELL_ATTR0_CASTABLE_WHILE_SITTING | SPELL_ATTR0_UNAFFECTED_BY_INVULNERABILITY*/);
    sinfo->AttributesEx2 &= ~(SPELL_ATTR2_CAN_TARGET_NOT_IN_LOS);
    //sinfo->AttributesEx3 |= SPELL_ATTR3_DONT_DISPLAY_RANGE;

    sinfo->Effects[0].Effect = SPELL_EFFECT_DUMMY;
    sinfo->Effects[0].TargetA = SpellImplicitTargetInfo(TARGET_UNIT_CASTER);
    sinfo->Effects[0].MiscValue = 0;
    sinfo->Effects[0].MiscValueB = 0;
    sinfo->Effects[0].RadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_0_YARDS);
    //4) END MIRROR IMAGE (BLADEMASTER)

    //SPHYNX

    //5) SHADOW BLAST (SPLASH ATTACK)
    //TODO: balance
    spellId = SPELL_SHADOW_BLAST; //38085
    sinfo = const_cast<SpellInfo*>(sSpellMgr->GetSpellInfo(spellId));

    sinfo->SpellFamilyName = SPELLFAMILY_WARLOCK;
    sinfo->SpellLevel = 60;
    sinfo->MaxLevel = 83;
    sinfo->ManaCost = BASE_MANA_SPHYNX/16;
    sinfo->ManaCostPercentage = 0;
    sinfo->ManaCostPerlevel = 0;
    sinfo->CastTimeEntry = nullptr;
    sinfo->RangeEntry = sSpellRangeStore.LookupEntry(4); //30 yds
    sinfo->SchoolMask = SPELL_SCHOOL_MASK_SHADOW | SPELL_SCHOOL_MASK_ARCANE;
    sinfo->ExplicitTargetMask = TARGET_FLAG_UNIT | TARGET_FLAG_DEST_LOCATION;
    //sinfo->MaxAffectedTargets = 1000;
    //sinfo->Attributes |= SPELL_ATTR0_HIDE_IN_COMBAT_LOG | SPELL_ATTR0_HIDDEN_CLIENTSIDE | SPELL_ATTR0_DONT_AFFECT_SHEATH_STATE;
    sinfo->Attributes &= ~(SPELL_ATTR0_LEVEL_DAMAGE_CALCULATION);
    //sinfo->AttributesEx2 |= SPELL_ATTR2_CAN_TARGET_NOT_IN_LOS;
    sinfo->AttributesEx3 |= SPELL_ATTR3_IGNORE_HIT_RESULT;

    sinfo->Effects[0].BasePoints = 200;
    sinfo->Effects[0].DieSides = 0;
    sinfo->Effects[0].BonusMultiplier = 0.f;
    sinfo->Effects[0].DamageMultiplier = 1.0f;
    sinfo->Effects[0].RealPointsPerLevel = 10.f;
    //sinfo->Effects[0].ValueMultiplier = 1.f;

    sinfo->Effects[1].Effect = SPELL_EFFECT_SCHOOL_DAMAGE;
    sinfo->Effects[1].BasePoints = 150;
    sinfo->Effects[1].BonusMultiplier = 2.0f;
    sinfo->Effects[1].DamageMultiplier = 1.0f;
    sinfo->Effects[1].DieSides = /*17*/25;
    sinfo->Effects[1].RealPointsPerLevel = 10.f;
    //sinfo->Effects[1].ValueMultiplier = 1.f;
    sinfo->Effects[1].TargetA = SpellImplicitTargetInfo(TARGET_UNIT_TARGET_ENEMY);
    sinfo->Effects[1].TargetB = SpellImplicitTargetInfo(TARGET_UNIT_DEST_AREA_ENEMY);
    sinfo->Effects[1].RadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_12_YARDS);
    //5) END SHADOW BLAST (SPLASH ATTACK)

    //6) SHADOW BOLT (BASE ATTACK)
    spellId = SPELL_SHADOW_BOLT; //16408
    sinfo = const_cast<SpellInfo*>(sSpellMgr->GetSpellInfo(spellId));

    sinfo->PreventionType = SPELL_PREVENTION_TYPE_NONE;
    sinfo->SpellLevel = 60;
    sinfo->MaxLevel = 83;
    sinfo->ManaCost = 0;
    sinfo->ManaCostPercentage = 0;
    sinfo->ManaCostPerlevel = 0;
    sinfo->CastTimeEntry = nullptr;
    sinfo->RangeEntry = sSpellRangeStore.LookupEntry(4); //30 yds
    sinfo->SchoolMask = SPELL_SCHOOL_MASK_SHADOW | SPELL_SCHOOL_MASK_ARCANE;
    //sinfo->Attributes |= SPELL_ATTR0_HIDE_IN_COMBAT_LOG | SPELL_ATTR0_HIDDEN_CLIENTSIDE | SPELL_ATTR0_DONT_AFFECT_SHEATH_STATE;
    //sinfo->AttributesEx3 |= SPELL_ATTR3_DONT_DISPLAY_RANGE;

    sinfo->Effects[0].BasePoints = 200;
    sinfo->Effects[0].DieSides = /*12*/25;
    sinfo->Effects[0].BonusMultiplier = 1.15f;
    sinfo->Effects[0].DamageMultiplier = 1.f;
    sinfo->Effects[0].RealPointsPerLevel = 10.f;
    //sinfo->Effects[0].ValueMultiplier = 1.f;
    //6) END SHADOW BOLT (BASE ATTACK)

    //7) ATTACK ANIMATION
    spellId = SPELL_ATTACK_MELEE_RANDOM; //42902
    sinfo = const_cast<SpellInfo*>(sSpellMgr->GetSpellInfo(spellId));

    sinfo->Attributes &= ~(SPELL_ATTR0_CANT_USED_IN_COMBAT);
    //7) ATTACK ANIMATION

    //8) SPLASH ANIMATION
    spellId = SHADOWFURY_VISUAL; //48582
    sinfo = const_cast<SpellInfo*>(sSpellMgr->GetSpellInfo(spellId));

    sinfo->SpellLevel = 0;
    sinfo->MaxLevel = 0;
    sinfo->ManaCost = 0;
    sinfo->ManaCostPercentage = 0;
    sinfo->ManaCostPerlevel = 0;
    sinfo->RangeEntry = sSpellRangeStore.LookupEntry(6); //100 yds
    sinfo->ExplicitTargetMask = TARGET_FLAG_DEST_LOCATION;
    sinfo->MaxAffectedTargets = 1;
    sinfo->Stances = 0;
    sinfo->Speed = 0.f;
    sinfo->Attributes |= SPELL_ATTR0_CASTABLE_WHILE_DEAD | SPELL_ATTR0_UNAFFECTED_BY_INVULNERABILITY;
    sinfo->AttributesEx |= SPELL_ATTR1_UNAFFECTED_BY_SCHOOL_IMMUNE | SPELL_ATTR1_NO_THREAT;
    sinfo->AttributesEx2 |= SPELL_ATTR2_CAN_TARGET_DEAD | SPELL_ATTR2_CAN_TARGET_NOT_IN_LOS;
    sinfo->AttributesEx3 |= SPELL_ATTR3_IGNORE_HIT_RESULT;
    sinfo->AttributesEx5 |= SPELL_ATTR5_USABLE_WHILE_STUNNED | SPELL_ATTR5_USABLE_WHILE_CONFUSED | SPELL_ATTR5_USABLE_WHILE_FEARED;

    sinfo->Effects[0].Effect = SPELL_EFFECT_DUMMY;
    sinfo->Effects[0].BasePoints = 1;
    sinfo->Effects[0].RealPointsPerLevel = 0.f;
    sinfo->Effects[0].ValueMultiplier = 0.f;
    sinfo->Effects[0].RealPointsPerLevel = 0.f;
    sinfo->Effects[0].DamageMultiplier = 0.f;
    sinfo->Effects[0].TargetB = SpellImplicitTargetInfo(0);
    sinfo->Effects[0].RadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_0_YARDS);
    sinfo->Effects[0].TargetA = SpellImplicitTargetInfo(TARGET_DEST_DEST);
    //8) END SPLASH ANIMATION

    //9) DEVOUR MAGIC
    spellId = SPELL_DEVOUR_MAGIC; //17012
    sinfo = const_cast<SpellInfo*>(sSpellMgr->GetSpellInfo(spellId));

    sinfo->InterruptFlags = 0xF;
    sinfo->SpellLevel = 0;
    sinfo->MaxLevel = 0;
    sinfo->MaxTargetLevel = 83;
    sinfo->RecoveryTime = 7000;
    sinfo->PowerType = POWER_MANA;
    sinfo->ManaCost = 0;
    sinfo->ManaCostPercentage = 0;
    sinfo->ManaCostPerlevel = 0;
    sinfo->CastTimeEntry = sSpellCastTimesStore.LookupEntry(4); //1000ms
    sinfo->RangeEntry = sSpellRangeStore.LookupEntry(5); //40 yds
    sinfo->SchoolMask = SPELL_SCHOOL_MASK_SHADOW | SPELL_SCHOOL_MASK_ARCANE;
    sinfo->DmgClass = SPELL_DAMAGE_CLASS_MAGIC;
    sinfo->ExplicitTargetMask = TARGET_FLAG_DEST_LOCATION;
    //sinfo->MaxAffectedTargets = 100;
    sinfo->Attributes |= SPELL_ATTR0_UNAFFECTED_BY_INVULNERABILITY;
    sinfo->AttributesEx |= SPELL_ATTR1_NO_THREAT;
    //sinfo->Attributes &= ~(SPELL_ATTR0_HIDE_IN_COMBAT_LOG);
    //sinfo->AttributesEx3 |= SPELL_ATTR3_DONT_DISPLAY_RANGE;

    sinfo->Effects[0].Effect = SPELL_EFFECT_DISPEL;
    sinfo->Effects[0].BasePoints = 2;
    sinfo->Effects[0].MiscValue = DISPEL_MAGIC;
    sinfo->Effects[0].TargetA = SpellImplicitTargetInfo(TARGET_UNIT_DEST_AREA_ALLY);
    sinfo->Effects[0].RadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_20_YARDS);

    sinfo->Effects[1].Effect = SPELL_EFFECT_DISPEL;
    sinfo->Effects[1].BasePoints = 2;
    sinfo->Effects[1].MiscValue = DISPEL_CURSE;
    sinfo->Effects[1].TargetA = SpellImplicitTargetInfo(TARGET_UNIT_DEST_AREA_ALLY);
    sinfo->Effects[1].RadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_20_YARDS);

    sinfo->Effects[2].Effect = SPELL_EFFECT_DISPEL;
    sinfo->Effects[2].BasePoints = 2;
    sinfo->Effects[2].MiscValue = DISPEL_MAGIC;
    sinfo->Effects[2].TargetA = SpellImplicitTargetInfo(TARGET_UNIT_DEST_AREA_ENEMY);
    sinfo->Effects[2].RadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_20_YARDS);
    //9) END DEVOUR MAGIC

    //10) DRAIN MANA
    spellId = SPELL_DRAIN_MANA; //25755
    sinfo = const_cast<SpellInfo*>(sSpellMgr->GetSpellInfo(spellId));

    sinfo->SpellLevel = 0;
    sinfo->MaxLevel = 0;
    sinfo->MaxTargetLevel = 83;
    sinfo->RecoveryTime = 0;//60000;
    //sinfo->PowerType = POWER_MANA;
    //sinfo->ManaCost = 0;
    //sinfo->ManaCostPercentage = 0;
    //sinfo->ManaCostPerlevel = 0;
    sinfo->Speed = 0.f;
    sinfo->CastTimeEntry = sSpellCastTimesStore.LookupEntry(4); //1000ms
    sinfo->RangeEntry = sSpellRangeStore.LookupEntry(5); //40 yds
    sinfo->SchoolMask = SPELL_SCHOOL_MASK_SHADOW | SPELL_SCHOOL_MASK_ARCANE;
    //sinfo->DmgClass = SPELL_DAMAGE_CLASS_MAGIC;
    sinfo->ExplicitTargetMask = TARGET_FLAG_UNIT;
    sinfo->Attributes |= SPELL_ATTR0_ABILITY | SPELL_ATTR0_DONT_AFFECT_SHEATH_STATE;
    sinfo->AttributesEx3 |= SPELL_ATTR3_IGNORE_HIT_RESULT | SPELL_ATTR3_NO_DONE_BONUS;

    //sinfo->Effects[0].Effect = SPELL_EFFECT_POWER_DRAIN;
    sinfo->Effects[0].BasePoints = 999999;
    sinfo->Effects[0].RealPointsPerLevel = 0.f;
    sinfo->Effects[0].ValueMultiplier = 1.f;
    sinfo->Effects[0].RealPointsPerLevel = 0.f;
    sinfo->Effects[0].DamageMultiplier = 1.f;
    sinfo->Effects[0].TargetA = SpellImplicitTargetInfo(TARGET_UNIT_TARGET_ANY);

    sinfo->Effects[1].Effect = 0;
    //10) END DRAIN MANA

    //11) REPLENISH MANA
    spellId = SPELL_REPLENISH_MANA; //33394
    sinfo = const_cast<SpellInfo*>(sSpellMgr->GetSpellInfo(spellId));

    sinfo->SpellFamilyName = SPELLFAMILY_WARLOCK;
    sinfo->SpellLevel = 0;
    sinfo->RecoveryTime = 3000;
    sinfo->CategoryEntry = nullptr;
    sinfo->PowerType = POWER_MANA;
    sinfo->CastTimeEntry = nullptr;//sSpellCastTimesStore.LookupEntry(2); //250ms
    sinfo->SchoolMask = SPELL_SCHOOL_MASK_SHADOW | SPELL_SCHOOL_MASK_ARCANE;
    sinfo->ExplicitTargetMask = TARGET_FLAG_UNIT;
    sinfo->MaxAffectedTargets = 10;
    sinfo->Attributes |= SPELL_ATTR0_ABILITY | SPELL_ATTR0_DONT_AFFECT_SHEATH_STATE | SPELL_ATTR0_IS_REPLENISHMENT | SPELL_ATTR0_HIDE_IN_COMBAT_LOG;
    sinfo->AttributesEx |= SPELL_ATTR1_DRAIN_ALL_POWER/* | SPELL_ATTR1_CANT_TARGET_SELF*/;
    sinfo->AttributesEx2 |= SPELL_ATTR2_CAN_TARGET_NOT_IN_LOS;
    sinfo->AttributesEx3 |= SPELL_ATTR3_NO_DONE_BONUS;
    sinfo->AttributesEx4 |= SPELL_ATTR4_NOT_CHECK_SELFCAST_POWER;
    sinfo->AttributesEx5 |= SPELL_ATTR5_DONT_TURN_DURING_CAST;
    sinfo->AttributesEx6 |= SPELL_ATTR6_CAN_TARGET_POSSESSED_FRIENDS;

    sinfo->Effects[0].Effect = SPELL_EFFECT_TRIGGER_SPELL;
    sinfo->Effects[0].BasePoints = 1;
    sinfo->Effects[0].DieSides = 0;
    sinfo->Effects[0].RealPointsPerLevel = 0.f;
    sinfo->Effects[0].ValueMultiplier = 0.f;
    sinfo->Effects[0].RealPointsPerLevel = 0.f;
    sinfo->Effects[0].DamageMultiplier = 0.f;
    sinfo->Effects[0].TriggerSpell = SPELL_TRIGGERED_ENERGIZE;
    sinfo->Effects[0].TargetA = SpellImplicitTargetInfo(TARGET_SRC_CASTER);
    sinfo->Effects[0].TargetB = SpellImplicitTargetInfo(TARGET_UNIT_SRC_AREA_ALLY);
    sinfo->Effects[0].RadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_15_YARDS);
    //11) END REPLENISH MANA

    //12) REPLENISH HEALTH
    spellId = SPELL_REPLENISH_HEALTH; //34756
    sinfo = const_cast<SpellInfo*>(sSpellMgr->GetSpellInfo(spellId));

    sinfo->SpellFamilyName = SPELLFAMILY_WARLOCK;
    sinfo->SpellLevel = 0;
    sinfo->RecoveryTime = 3000;
    sinfo->CategoryEntry = nullptr;
    sinfo->PowerType = POWER_MANA;
    sinfo->CastTimeEntry = nullptr;//sSpellCastTimesStore.LookupEntry(2); //250ms
    sinfo->SchoolMask = SPELL_SCHOOL_MASK_SHADOW | SPELL_SCHOOL_MASK_ARCANE;
    sinfo->ExplicitTargetMask = TARGET_FLAG_UNIT;
    sinfo->MaxAffectedTargets = 10;
    sinfo->Attributes |= SPELL_ATTR0_ABILITY | SPELL_ATTR0_DONT_AFFECT_SHEATH_STATE | SPELL_ATTR0_IS_REPLENISHMENT | SPELL_ATTR0_HIDE_IN_COMBAT_LOG;
    sinfo->AttributesEx |= SPELL_ATTR1_DRAIN_ALL_POWER/* | SPELL_ATTR1_CANT_TARGET_SELF*/;
    sinfo->AttributesEx &= ~(SPELL_ATTR1_CANT_TARGET_SELF);
    sinfo->AttributesEx2 |= SPELL_ATTR2_CAN_TARGET_NOT_IN_LOS;
    sinfo->AttributesEx3 |= SPELL_ATTR3_NO_DONE_BONUS;
    sinfo->AttributesEx4 |= SPELL_ATTR4_NOT_CHECK_SELFCAST_POWER;
    sinfo->AttributesEx5 |= SPELL_ATTR5_DONT_TURN_DURING_CAST;
    sinfo->AttributesEx6 |= SPELL_ATTR6_CAN_TARGET_POSSESSED_FRIENDS;

    sinfo->Effects[0].Effect = SPELL_EFFECT_TRIGGER_SPELL;
    sinfo->Effects[0].BasePoints = 2;
    sinfo->Effects[0].DieSides = 0;
    sinfo->Effects[0].RealPointsPerLevel = 0.f;
    sinfo->Effects[0].ValueMultiplier = 0.f;
    sinfo->Effects[0].RealPointsPerLevel = 0.f;
    sinfo->Effects[0].DamageMultiplier = 0.f;
    sinfo->Effects[0].TriggerSpell = SPELL_TRIGGERED_HEAL;
    sinfo->Effects[0].TargetA = SpellImplicitTargetInfo(TARGET_SRC_CASTER);
    sinfo->Effects[0].TargetB = SpellImplicitTargetInfo(TARGET_UNIT_SRC_AREA_ALLY);
    sinfo->Effects[0].RadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_15_YARDS);
    //12) END REPLENISH HEALTH

    //ARCHMAGE

    //13) BRILLIANCE AURA
    spellId = SPELL_BRILLIANCE_AURA; //1234
    sinfo = const_cast<SpellInfo*>(sSpellMgr->GetSpellInfo(spellId));

    sinfo->SpellLevel = 0;
    sinfo->MaxLevel = 0;
    sinfo->MaxTargetLevel = 0;
    sinfo->RangeEntry = sSpellRangeStore.LookupEntry(1); //0 yds
    sinfo->ExplicitTargetMask = TARGET_FLAG_UNIT;
    sinfo->Attributes |= SPELL_ATTR0_ABILITY | SPELL_ATTR0_PASSIVE;
    sinfo->AttributesEx4 |= SPELL_ATTR4_UNK21; //party aura
    sinfo->AttributesEx7 |= SPELL_ATTR7_CONSOLIDATED_RAID_BUFF;

    sinfo->Effects[0].Effect = SPELL_EFFECT_APPLY_AREA_AURA_RAID;
    sinfo->Effects[0].ApplyAuraName = SPELL_AURA_MOD_POWER_REGEN_PERCENT;
    sinfo->Effects[0].TargetA = SpellImplicitTargetInfo(TARGET_UNIT_CASTER);
    sinfo->Effects[0].BasePoints = 100;
    sinfo->Effects[0].RadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_40_YARDS);

    sinfo->Effects[1].Effect = SPELL_EFFECT_APPLY_AREA_AURA_RAID;
    sinfo->Effects[1].ApplyAuraName = SPELL_AURA_MOD_INCREASE_ENERGY_PERCENT;
    sinfo->Effects[1].TargetA = SpellImplicitTargetInfo(TARGET_UNIT_CASTER);
    sinfo->Effects[1].BasePoints = 10;
    sinfo->Effects[1].RadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_40_YARDS);

    //for stacking rule
    /*
    sinfo->Effects[2].Effect = SPELL_EFFECT_APPLY_AURA;
    sinfo->Effects[2].ApplyAuraName = SPELL_AURA_DUMMY;
    sinfo->Effects[2].TargetA = SpellImplicitTargetInfo(TARGET_UNIT_CASTER);
    sinfo->Effects[2].BasePoints = 1;
    sinfo->Effects[2].RadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_0_YARDS);
    */
    //13) END BRILLIANCE AURA

    //14) FIREBALL (MAIN_ATTACK)
    //TODO: balance
    spellId = SPELL_FIREBALL; //9488
    sinfo = const_cast<SpellInfo*>(sSpellMgr->GetSpellInfo(spellId));

    sinfo->SpellLevel = 20;
    sinfo->BaseLevel = 20;
    sinfo->MaxLevel = 81;
    sinfo->ManaCost = 0;
    sinfo->ManaCostPercentage = 0;
    sinfo->ManaCostPerlevel = 0;
    sinfo->CastTimeEntry = nullptr;
    sinfo->RangeEntry = sSpellRangeStore.LookupEntry(4); //30 yds
    sinfo->SchoolMask = SPELL_SCHOOL_MASK_FIRE | SPELL_SCHOOL_MASK_ARCANE;
    //sinfo->ExplicitTargetMask = TARGET_FLAG_UNIT;
    //sinfo->MaxAffectedTargets = 1000;
    sinfo->Attributes |= SPELL_ATTR0_DONT_AFFECT_SHEATH_STATE | SPELL_ATTR0_ABILITY | SPELL_ATTR0_CASTABLE_WHILE_MOUNTED;
    sinfo->Attributes &= ~(SPELL_ATTR0_LEVEL_DAMAGE_CALCULATION);
    sinfo->AttributesEx3 |= SPELL_ATTR3_IGNORE_HIT_RESULT;

    sinfo->Effects[0].BasePoints = 15;
    sinfo->Effects[0].DieSides = 9;
    sinfo->Effects[0].BonusMultiplier = 0.5f;
    sinfo->Effects[0].DamageMultiplier = 1.f;
    sinfo->Effects[0].RealPointsPerLevel = 15.f;
    sinfo->Effects[0].ValueMultiplier = 1.f;
    //14) END FIREBALL (MAIN ATTACK)

    //15) BLIZZARD
    //TODO: balance
    spellId = SPELL_BLIZZARD; //15783
    sinfo = const_cast<SpellInfo*>(sSpellMgr->GetSpellInfo(spellId));

    sinfo->SpellFamilyName = SPELLFAMILY_MAGE;
    sinfo->SpellLevel = 20;
    sinfo->BaseLevel = 20;
    sinfo->MaxLevel = 0;
    sinfo->ManaCost = 75 * 5;
    sinfo->ManaCostPercentage = 0;
    sinfo->ManaCostPerlevel = 0;
    sinfo->CastTimeEntry = nullptr;
    sinfo->RecoveryTime = 6000;
    sinfo->RangeEntry = sSpellRangeStore.LookupEntry(4); //30 yds
    sinfo->SchoolMask = SPELL_SCHOOL_MASK_FROST | SPELL_SCHOOL_MASK_ARCANE;
    ///sinfo->ExplicitTargetMask = TARGET_FLAG_DEST_LOCATION;
    //sinfo->MaxAffectedTargets = 1000;
    sinfo->Attributes |= SPELL_ATTR0_DONT_AFFECT_SHEATH_STATE | SPELL_ATTR0_ABILITY | SPELL_ATTR0_CASTABLE_WHILE_MOUNTED;
    sinfo->AttributesEx2 |= SPELL_ATTR2_CAN_TARGET_NOT_IN_LOS | SPELL_ATTR2_UNK22;
    sinfo->AttributesEx3 |= SPELL_ATTR3_IGNORE_HIT_RESULT;
    sinfo->AttributesEx5 |= SPELL_ATTR5_HASTE_AFFECT_DURATION;

    sinfo->Effects[0].BasePoints = 26;
    sinfo->Effects[0].DieSides = 0;
    sinfo->Effects[0].BonusMultiplier = 1.f;
    sinfo->Effects[0].DamageMultiplier = 1.f;
    sinfo->Effects[0].RealPointsPerLevel = 15.f;
    sinfo->Effects[0].ValueMultiplier = 1.f;
    sinfo->Effects[0].RadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_13_YARDS);
    sinfo->Effects[0].Amplitude = 1000;
    //15) END BLIZZARD

    //16) SUMMON WATER ELEMENTAL (dummy spell)
    spellId = SPELL_SUMMON_WATER_ELEMENTAL; //35593
    sinfo = const_cast<SpellInfo*>(sSpellMgr->GetSpellInfo(spellId));

    sinfo->SpellFamilyName = SPELLFAMILY_MAGE;
    sinfo->SpellLevel = 20;
    sinfo->BaseLevel = 20;
    sinfo->MaxLevel = 0;
    sinfo->RecoveryTime = 20000;
    sinfo->PowerType = POWER_MANA;
    sinfo->ManaCost = 125 * 5;
    sinfo->ManaCostPercentage = 0;
    sinfo->ManaCostPerlevel = 0;
    sinfo->CastTimeEntry = sSpellCastTimesStore.LookupEntry(3); //500ms
    sinfo->SchoolMask = SPELL_SCHOOL_MASK_FROST | SPELL_SCHOOL_MASK_ARCANE;
    sinfo->ExplicitTargetMask = TARGET_FLAG_UNIT;

    sinfo->Effects[0].Effect = SPELL_EFFECT_DUMMY;
    //sinfo->Effects[0].BasePoints = 1;
    sinfo->Effects[0].TargetA = SpellImplicitTargetInfo(TARGET_UNIT_CASTER);
    sinfo->Effects[0].RadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_0_YARDS);
    //16) END SUMMON WATER ELEMENTAL

    //17) WATERBOLT (MAIN_ATTACK)
    //TODO: balance, we only have 1 of 3 possible elementals so boost damage
    spellId = SPELL_WATERBOLT; //72898
    sinfo = const_cast<SpellInfo*>(sSpellMgr->GetSpellInfo(spellId));

    sinfo->SpellFamilyName = SPELLFAMILY_GENERIC;
    sinfo->SpellLevel = 20;
    sinfo->BaseLevel = 20;
    sinfo->MaxTargetLevel = 83;
    sinfo->ManaCost = 0;
    sinfo->ManaCostPercentage = 0;
    sinfo->ManaCostPerlevel = 0;
    sinfo->CastTimeEntry = sSpellCastTimesStore.LookupEntry(5); //2000ms
    sinfo->RangeEntry = sSpellRangeStore.LookupEntry(4); //30 yds
    sinfo->SchoolMask = SPELL_SCHOOL_MASK_FROST | SPELL_SCHOOL_MASK_ARCANE;
    sinfo->AttributesEx3 |= SPELL_ATTR3_IGNORE_HIT_RESULT;

    sinfo->Effects[0].BasePoints = 25;
    sinfo->Effects[0].DieSides = 20;
    sinfo->Effects[0].BonusMultiplier = 1.f;
    sinfo->Effects[0].DamageMultiplier = 1.f;
    sinfo->Effects[0].RealPointsPerLevel = 25.f;
    sinfo->Effects[0].ValueMultiplier = 1.f;
    //17) END WATERBOLT (MAIN ATTACK)

    //DREADLORD

    //18) VAMPIRIC AURA
    spellId = SPELL_VAMPIRIC_AURA; //20810
    sinfo = const_cast<SpellInfo*>(sSpellMgr->GetSpellInfo(spellId));

    sinfo->ProcFlags = PROC_FLAG_DONE_MELEE_AUTO_ATTACK | PROC_FLAG_DONE_SPELL_MELEE_DMG_CLASS;
    sinfo->SchoolMask = SPELL_SCHOOL_MASK_SHADOW | SPELL_SCHOOL_MASK_ARCANE;
    sinfo->PreventionType = SPELL_PREVENTION_TYPE_NONE;
    sinfo->DmgClass = SPELL_DAMAGE_CLASS_NONE;
    sinfo->SpellLevel = 0;
    sinfo->BaseLevel = 0;
    sinfo->MaxTargetLevel = 0;
    sinfo->RangeEntry = sSpellRangeStore.LookupEntry(1); //0 yds
    sinfo->ExplicitTargetMask = TARGET_FLAG_UNIT;
    sinfo->Attributes |= SPELL_ATTR0_ABILITY | SPELL_ATTR0_PASSIVE;
    sinfo->AttributesEx3 |= SPELL_ATTR3_CAN_PROC_WITH_TRIGGERED;
    sinfo->AttributesEx4 |= SPELL_ATTR4_UNK21; //party aura
    sinfo->AttributesEx7 |= SPELL_ATTR7_CONSOLIDATED_RAID_BUFF;

    sinfo->Effects[0].Effect = SPELL_EFFECT_APPLY_AREA_AURA_RAID;
    sinfo->Effects[0].ApplyAuraName = SPELL_AURA_MOD_CRIT_DAMAGE_BONUS;
    sinfo->Effects[0].TargetA = SpellImplicitTargetInfo(TARGET_UNIT_CASTER);
    sinfo->Effects[0].BasePoints = 5;
    sinfo->Effects[0].MiscValue = SPELL_SCHOOL_MASK_NORMAL;
    sinfo->Effects[0].RadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_40_YARDS);

    sinfo->Effects[1].Effect = SPELL_EFFECT_APPLY_AREA_AURA_RAID;
    sinfo->Effects[1].ApplyAuraName = SPELL_AURA_PROC_TRIGGER_SPELL;
    sinfo->Effects[1].TargetA = SpellImplicitTargetInfo(TARGET_UNIT_CASTER);
    sinfo->Effects[1].BasePoints = 1;
    sinfo->Effects[1].TriggerSpell = SPELL_TRIGGERED_HEAL;
    sinfo->Effects[1].RadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_40_YARDS);

    //for stacking rule
    /*
    sinfo->Effects[2].Effect = SPELL_EFFECT_APPLY_AURA;
    sinfo->Effects[2].ApplyAuraName = SPELL_AURA_DUMMY;
    sinfo->Effects[2].TargetA = SpellImplicitTargetInfo(TARGET_UNIT_CASTER);
    sinfo->Effects[2].BasePoints = 1;
    sinfo->Effects[2].RadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_0_YARDS);
    */
    //18) END VAMPIRIC AURA

    //19) VAMPIRIC HEAL
    spellId = SPELL_TRIGGERED_HEAL; //25155
    sinfo = const_cast<SpellInfo*>(sSpellMgr->GetSpellInfo(spellId));

    sinfo->PreventionType = SPELL_PREVENTION_TYPE_NONE;
    sinfo->DmgClass = SPELL_DAMAGE_CLASS_NONE;
    sinfo->SchoolMask = SPELL_SCHOOL_MASK_SHADOW | SPELL_SCHOOL_MASK_ARCANE;
    sinfo->Attributes &= ~(SPELL_ATTR0_NOT_SHAPESHIFT);
    sinfo->AttributesEx |= SPELL_ATTR1_CANT_BE_REFLECTED | SPELL_ATTR1_CANT_BE_REDIRECTED | SPELL_ATTR1_NO_THREAT;
    sinfo->AttributesEx2 |= SPELL_ATTR2_CANT_CRIT;
    sinfo->AttributesEx3 |= SPELL_ATTR3_IGNORE_HIT_RESULT | SPELL_ATTR3_DISABLE_PROC | SPELL_ATTR3_CAN_PROC_WITH_TRIGGERED | SPELL_ATTR3_NO_DONE_BONUS;

    sinfo->Effects[0].BasePoints = 1;

    sinfo->Effects[1].Effect = 0;
    //19) END VAMPIRIC HEAL

    //20) SLEEP
    spellId = SPELL_SLEEP; //20663
    sinfo = const_cast<SpellInfo*>(sSpellMgr->GetSpellInfo(spellId));

    sinfo->SpellFamilyName = SPELLFAMILY_WARLOCK;
    sinfo->SchoolMask = SPELL_SCHOOL_MASK_SHADOW | SPELL_SCHOOL_MASK_ARCANE;
    sinfo->InterruptFlags = 0xF;
    sinfo->SpellLevel = 0;
    sinfo->BaseLevel = 0;
    sinfo->MaxTargetLevel = 83;
    sinfo->Dispel = DISPEL_MAGIC;
    sinfo->Mechanic = MECHANIC_SLEEP;
    sinfo->RangeEntry = sSpellRangeStore.LookupEntry(4); //30 yds
    sinfo->CastTimeEntry = sSpellCastTimesStore.LookupEntry(3); //500ms
    sinfo->RecoveryTime = 6000;
    //sinfo->StartRecoveryCategory = 133;
    //sinfo->StartRecoveryTime = 1000;
    sinfo->DurationEntry = sSpellDurationStore.LookupEntry(3); //60000ms
    sinfo->ManaCost = 50 * 5;
    sinfo->ManaCostPercentage = 0;
    sinfo->ManaCostPerlevel = 0;
    sinfo->AuraInterruptFlags = AURA_INTERRUPT_FLAG_DIRECT_DAMAGE;
    sinfo->ExplicitTargetMask = TARGET_FLAG_UNIT;
    sinfo->Attributes &= ~(SPELL_ATTR0_NOT_SHAPESHIFT | SPELL_ATTR0_HEARTBEAT_RESIST_CHECK);
    sinfo->AttributesEx |= SPELL_ATTR1_CANT_BE_REDIRECTED | SPELL_ATTR1_CANT_BE_REFLECTED;
    sinfo->AttributesEx3 |= SPELL_ATTR3_IGNORE_HIT_RESULT;

    //sinfo->Effects[0].Effect = SPELL_EFFECT_APPLY_AURA;
    //sinfo->Effects[0].ApplyAuraName = SPELL_AURA_MOD_STUN;
    //sinfo->Effects[0].TargetA = SpellImplicitTargetInfo(TARGET_UNIT_TARGET_ENEMY);
    //sinfo->Effects[0].BasePoints = 1;

    sinfo->Effects[1].Effect = SPELL_EFFECT_APPLY_AURA;
    sinfo->Effects[1].ApplyAuraName = SPELL_AURA_MOD_RESISTANCE_PCT;
    sinfo->Effects[1].MiscValue = SPELL_SCHOOL_MASK_NORMAL;
    sinfo->Effects[1].TargetA = SpellImplicitTargetInfo(TARGET_UNIT_TARGET_ENEMY);
    sinfo->Effects[1].BasePoints = -100;
    //20) END SLEEP

    //21) CARRION SWARM
    //TODO: balance
    spellId = SPELL_CARRION_SWARM; //34240
    sinfo = const_cast<SpellInfo*>(sSpellMgr->GetSpellInfo(spellId));

    sinfo->SpellFamilyName = SPELLFAMILY_WARLOCK;
    sinfo->DmgClass = SPELL_DAMAGE_CLASS_MAGIC;
    sinfo->SchoolMask = SPELL_SCHOOL_MASK_SHADOW | SPELL_SCHOOL_MASK_ARCANE;
    sinfo->PreventionType = SPELL_PREVENTION_TYPE_NONE;
    sinfo->SpellLevel = 40;
    sinfo->BaseLevel = 40;
    sinfo->MaxTargetLevel = 83;
    sinfo->RangeEntry = sSpellRangeStore.LookupEntry(4); //30 yds
    sinfo->RecoveryTime = 10000;
    sinfo->StartRecoveryCategory = 133;
    sinfo->StartRecoveryTime = 1500;
    sinfo->ManaCost = 110 * 5;
    //sinfo->MaxAffectedTargets = 1000;
    //sinfo->ExplicitTargetMask = TARGET_FLAG_UNIT;
    sinfo->Attributes &= ~(SPELL_ATTR0_UNK11);
    sinfo->AttributesEx |= SPELL_ATTR1_CANT_BE_REDIRECTED | SPELL_ATTR1_CANT_BE_REFLECTED;
    sinfo->AttributesEx2 |= SPELL_ATTR2_CANT_CRIT/* | SPELL_ATTR2_CAN_TARGET_NOT_IN_LOS*/;
    sinfo->AttributesEx3 |= SPELL_ATTR3_IGNORE_HIT_RESULT;

    //sinfo->Effects[0].Effect = SPELL_EFFECT_SCHOOL_DAMAGE;
    sinfo->Effects[0].TargetA = SpellImplicitTargetInfo(TARGET_UNIT_CONE_ENEMY_104);
    sinfo->Effects[0].BasePoints = 425;
    sinfo->Effects[0].DieSides = 150;
    sinfo->Effects[0].BonusMultiplier = 2.f;
    sinfo->Effects[0].DamageMultiplier = 1.f;
    sinfo->Effects[0].RealPointsPerLevel = 37.5f; //2000 avg at 80
    sinfo->Effects[0].ValueMultiplier = 1.f;
    sinfo->Effects[0].RadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_40_YARDS);
    //21) END CARRION SWARM

    //22) INFERNO (dummy summon)
    spellId = SPELL_INFERNO; //12740
    sinfo = const_cast<SpellInfo*>(sSpellMgr->GetSpellInfo(spellId));

    sinfo->SpellFamilyName = SPELLFAMILY_WARLOCK;
    sinfo->SpellLevel = 60;
    sinfo->BaseLevel = 60;
    sinfo->RangeEntry = sSpellRangeStore.LookupEntry(4); //30 yds
    sinfo->CastTimeEntry = sSpellCastTimesStore.LookupEntry(3); //500ms
    sinfo->RecoveryTime = 180000;
    sinfo->StartRecoveryCategory = 133;
    sinfo->StartRecoveryTime = 1500;
    sinfo->ManaCost = 175 * 5;
    sinfo->ExplicitTargetMask = TARGET_FLAG_DEST_LOCATION;
    sinfo->Attributes &= ~(SPELL_ATTR0_ABILITY);
    sinfo->AttributesEx |= /*SPELL_ATTR1_UNAFFECTED_BY_SCHOOL_IMMUNE | */SPELL_ATTR1_NO_THREAT;
    //sinfo->AttributesEx3 |= SPELL_ATTR3_IGNORE_HIT_RESULT;

    sinfo->Effects[0].Effect = SPELL_EFFECT_DUMMY;
    sinfo->Effects[0].TargetA = SpellImplicitTargetInfo(TARGET_DEST_DEST);
    sinfo->Effects[0].BasePoints = 1;
    //22) END INFERNO

    //23) INFERNO VISUAL (dummy summon)
    spellId = SPELL_INFERNO_METEOR_VISUAL; //5739
    sinfo = const_cast<SpellInfo*>(sSpellMgr->GetSpellInfo(spellId));

    sinfo->ExplicitTargetMask = TARGET_FLAG_DEST_LOCATION;

    //sinfo->Effects[0].Effect = SPELL_EFFECT_DUMMY;
    sinfo->Effects[0].TargetA = SpellImplicitTargetInfo(TARGET_DEST_DEST);
    //23) END INFERNO VISUAL

    //SPELL BREAKER

    //24) STEAL MAGIC
    spellId = SPELL_STEAL_MAGIC; //30036
    sinfo = const_cast<SpellInfo*>(sSpellMgr->GetSpellInfo(spellId));

    sinfo->SpellFamilyName = SPELLFAMILY_PALADIN;
    sinfo->RangeEntry = sSpellRangeStore.LookupEntry(34); //25 yds
    sinfo->RecoveryTime = 3000;
    sinfo->ManaCost = 75 * 5;
    sinfo->ManaCostPercentage = 0;
    sinfo->ManaCostPerlevel = 0;
    sinfo->ExplicitTargetMask = TARGET_FLAG_UNIT;
    sinfo->AttributesEx |= SPELL_ATTR1_CANT_BE_REDIRECTED | SPELL_ATTR1_CANT_BE_REFLECTED;
    sinfo->AttributesEx3 |= SPELL_ATTR3_IGNORE_HIT_RESULT;
    sinfo->AttributesEx6 |= SPELL_ATTR6_CAN_TARGET_POSSESSED_FRIENDS;

    sinfo->Effects[0].Effect = SPELL_EFFECT_DUMMY;
    sinfo->Effects[0].TargetA = SpellImplicitTargetInfo(TARGET_UNIT_TARGET_ANY);

    sinfo->Effects[1].Effect = 0;
    //24) END STEAL MAGIC

    //25) FEEDBACK
    spellId = SPELL_FEEDBACK; //32897
    sinfo = const_cast<SpellInfo*>(sSpellMgr->GetSpellInfo(spellId));

    sinfo->SpellFamilyName = SPELLFAMILY_PALADIN;
    sinfo->SchoolMask = SPELL_SCHOOL_MASK_ARCANE;
    sinfo->PreventionType = SPELL_PREVENTION_TYPE_NONE;
    sinfo->SpellLevel = 0;
    sinfo->BaseLevel = 0;
    sinfo->RangeEntry = sSpellRangeStore.LookupEntry(13); //50000 yds
    sinfo->ManaCost = 0;
    sinfo->ManaCostPercentage = 0;
    sinfo->ManaCostPerlevel = 0;
    sinfo->ExplicitTargetMask = TARGET_FLAG_UNIT;
    sinfo->Attributes &= ~(SPELL_ATTR0_NOT_SHAPESHIFT);
    sinfo->AttributesEx |= SPELL_ATTR1_CANT_BE_REDIRECTED | SPELL_ATTR1_CANT_BE_REFLECTED | SPELL_ATTR1_UNAFFECTED_BY_SCHOOL_IMMUNE;
    sinfo->AttributesEx2 |= SPELL_ATTR2_CANT_CRIT;
    sinfo->AttributesEx3 |= SPELL_ATTR3_IGNORE_HIT_RESULT;

    sinfo->Effects[0].Effect = SPELL_EFFECT_POWER_BURN;
    sinfo->Effects[0].DieSides = 0;
    sinfo->Effects[0].ValueMultiplier = 1.f;
    //25) END FEEDBACK

    // DARK RANGER

    //26) BLACK ARROW
    //TODO: balance
    spellId = SPELL_BLACK_ARROW; //20733
    sinfo = const_cast<SpellInfo*>(sSpellMgr->GetSpellInfo(spellId));

    sinfo->SpellFamilyName = SPELLFAMILY_WARLOCK;
    sinfo->SpellFamilyFlags[0] = 0x1; //custom, not present in db
    //sinfo->SpellFamilyFlags[1] = 0x0;
    //sinfo->SpellFamilyFlags[2] = 0x0;
    sinfo->DmgClass = SPELL_DAMAGE_CLASS_RANGED;
    sinfo->SchoolMask = SPELL_SCHOOL_MASK_SHADOW | SPELL_SCHOOL_MASK_ARCANE;
    sinfo->PreventionType = SPELL_PREVENTION_TYPE_PACIFY;
    sinfo->Dispel = DISPEL_NONE;
    sinfo->Mechanic = MECHANIC_NONE;
    sinfo->SpellLevel = 40;
    sinfo->BaseLevel = 40;
    sinfo->MaxTargetLevel = 83;
    sinfo->CastTimeEntry = sSpellCastTimesStore.LookupEntry(3); //500ms
    sinfo->RangeEntry = sSpellRangeStore.LookupEntry(4); //5-30 yds
    sinfo->DurationEntry = sSpellDurationStore.LookupEntry(85); //18 sec
    sinfo->RecoveryTime = 3000;
    sinfo->StartRecoveryCategory = 133;
    sinfo->StartRecoveryTime = 1500;
    sinfo->ManaCost = 6 * 5 * 2; //need to increase cost since ability is not autocast, has cd and deals more damage
    sinfo->MaxAffectedTargets = 1;
    sinfo->AuraInterruptFlags = AURA_INTERRUPT_FLAG_CHANGE_MAP;
    sinfo->ExplicitTargetMask = TARGET_FLAG_UNIT;
    sinfo->Attributes |= SPELL_ATTR0_IMPOSSIBLE_DODGE_PARRY_BLOCK;
    sinfo->AttributesEx |= SPELL_ATTR1_CANT_BE_REDIRECTED | SPELL_ATTR1_CANT_BE_REFLECTED;
    sinfo->AttributesEx2 |= SPELL_ATTR2_NOT_RESET_AUTO_ACTIONS/* | SPELL_ATTR2_CANT_CRIT*/;
    sinfo->AttributesEx4 |= SPELL_ATTR4_IGNORE_RESISTANCES;

    sinfo->Effects[0].Effect = SPELL_EFFECT_WEAPON_PERCENT_DAMAGE;
    sinfo->Effects[0].TargetA = SpellImplicitTargetInfo(TARGET_UNIT_TARGET_ENEMY);
    sinfo->Effects[0].BasePoints = 150;
    sinfo->Effects[0].DieSides = 0;
    sinfo->Effects[0].BonusMultiplier = 1.f;
    sinfo->Effects[0].DamageMultiplier = 1.f;
    sinfo->Effects[0].RealPointsPerLevel = 0.f;
    sinfo->Effects[0].ValueMultiplier = 1.f;
    sinfo->Effects[0].RadiusEntry = nullptr;

    sinfo->Effects[1].Effect = SPELL_EFFECT_APPLY_AURA;
    sinfo->Effects[1].TargetA = SpellImplicitTargetInfo(TARGET_UNIT_TARGET_ENEMY);
    sinfo->Effects[1].ApplyAuraName = SPELL_AURA_PERIODIC_DAMAGE;
    sinfo->Effects[1].BasePoints = 100;
    sinfo->Effects[1].DieSides = 0;
    sinfo->Effects[1].BonusMultiplier = 2.f;
    sinfo->Effects[1].DamageMultiplier = 1.f;
    sinfo->Effects[1].RealPointsPerLevel = 10.f;
    sinfo->Effects[1].ValueMultiplier = 1.f;
    sinfo->Effects[1].RadiusEntry = nullptr;
    sinfo->Effects[1].Amplitude = 2000;
    //26) END BLACK ARROW

    //27) DRAIN LIFE
    //TODO: balance
    spellId = SPELL_DRAIN_LIFE; //17238
    sinfo = const_cast<SpellInfo*>(sSpellMgr->GetSpellInfo(spellId));

    sinfo->SpellFamilyName = SPELLFAMILY_WARLOCK;
    sinfo->DmgClass = SPELL_DAMAGE_CLASS_MAGIC;
    sinfo->SchoolMask = SPELL_SCHOOL_MASK_SHADOW;
    sinfo->PreventionType = SPELL_PREVENTION_TYPE_SILENCE;
    sinfo->Dispel = DISPEL_NONE;
    sinfo->Mechanic = MECHANIC_NONE;
    sinfo->SpellLevel = 40;
    sinfo->BaseLevel = 40;
    sinfo->MaxTargetLevel = 83;
    sinfo->CastTimeEntry = nullptr;
    sinfo->RangeEntry = sSpellRangeStore.LookupEntry(4); //30 yds
    //sinfo->DurationEntry = sSpellDurationStore.LookupEntry(85); //18 sec
    sinfo->RecoveryTime = 5000;
    sinfo->StartRecoveryCategory = 133;
    sinfo->StartRecoveryTime = 1500;
    sinfo->ManaCost = 75 * 5;
    sinfo->MaxAffectedTargets = 1;
    sinfo->AuraInterruptFlags = 0x0;
    sinfo->ExplicitTargetMask = TARGET_FLAG_UNIT;
    sinfo->Attributes |= SPELL_ATTR0_IMPOSSIBLE_DODGE_PARRY_BLOCK;
    sinfo->AttributesEx |= SPELL_ATTR1_CANT_BE_REDIRECTED | SPELL_ATTR1_CANT_BE_REFLECTED;
    sinfo->AttributesEx3 |= SPELL_ATTR3_NO_INITIAL_AGGRO | SPELL_ATTR3_IGNORE_HIT_RESULT;
    sinfo->AttributesEx4 |= SPELL_ATTR4_IGNORE_RESISTANCES;
    sinfo->AttributesEx5 |= SPELL_ATTR5_START_PERIODIC_AT_APPLY;

    sinfo->Effects[0].Effect = SPELL_EFFECT_APPLY_AURA;
    sinfo->Effects[0].TargetA = SpellImplicitTargetInfo(TARGET_UNIT_TARGET_ENEMY);
    sinfo->Effects[0].ApplyAuraName = SPELL_AURA_PERIODIC_LEECH;
    sinfo->Effects[0].BasePoints = 45;
    sinfo->Effects[0].DieSides = 0;
    sinfo->Effects[0].BonusMultiplier = 1.f;
    sinfo->Effects[0].DamageMultiplier = 1.f;
    sinfo->Effects[0].RealPointsPerLevel = 6.f;
    sinfo->Effects[0].ValueMultiplier = 2.f;
    sinfo->Effects[0].RadiusEntry = nullptr;
    sinfo->Effects[0].Amplitude = 1000;
    //27) END DRAIN LIFE

    //28) SILENCE
    //TODO: balance
    spellId = SPELL_SILENCE; //29943
    sinfo = const_cast<SpellInfo*>(sSpellMgr->GetSpellInfo(spellId));

    sinfo->SpellFamilyName = SPELLFAMILY_WARLOCK;
    sinfo->DmgClass = SPELL_DAMAGE_CLASS_NONE;
    sinfo->SchoolMask = SPELL_SCHOOL_MASK_SHADOW | SPELL_SCHOOL_MASK_ARCANE;
    sinfo->PreventionType = SPELL_PREVENTION_TYPE_SILENCE;
    sinfo->Dispel = DISPEL_MAGIC;
    sinfo->Mechanic = MECHANIC_SILENCE;
    sinfo->SpellLevel = 60;
    sinfo->BaseLevel = 60;
    sinfo->MaxTargetLevel = 83;
    sinfo->CastTimeEntry = sSpellCastTimesStore.LookupEntry(2); //250ms
    sinfo->RangeEntry = sSpellRangeStore.LookupEntry(4); //30 yds
    //sinfo->DurationEntry = sSpellDurationStore.LookupEntry(85); //18 sec
    sinfo->RecoveryTime = 15000;
    sinfo->StartRecoveryCategory = 133;
    sinfo->StartRecoveryTime = 1500;
    sinfo->ManaCost = 75 * 5;
    sinfo->MaxAffectedTargets = 5;
    sinfo->AuraInterruptFlags = 0x0;
    sinfo->ExplicitTargetMask = TARGET_FLAG_UNIT | TARGET_FLAG_DEST_LOCATION;
    sinfo->AttributesEx |= SPELL_ATTR1_CANT_BE_REFLECTED | SPELL_ATTR1_CANT_BE_REDIRECTED;

    sinfo->Effects[0].Effect = SPELL_EFFECT_APPLY_AURA;
    sinfo->Effects[0].TargetA = SpellImplicitTargetInfo(TARGET_UNIT_TARGET_ENEMY);
    sinfo->Effects[0].TargetB = SpellImplicitTargetInfo(TARGET_UNIT_DEST_AREA_ENEMY);
    sinfo->Effects[0].ApplyAuraName = SPELL_AURA_MOD_SILENCE;
    sinfo->Effects[0].BasePoints = 1;
    sinfo->Effects[0].RadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_15_YARDS);
    //28) END SILENCE

    TC_LOG_INFO("server.loading", "Re-Loading Spell Proc conditions...");
    sSpellMgr->LoadSpellProcs();
}
