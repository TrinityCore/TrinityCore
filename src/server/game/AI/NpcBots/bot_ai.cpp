#include "bot_ai.h"
#include "bot_Events.h"
#include "bot_GridNotifiers.h"
#include "botmgr.h"
#include "CellImpl.h"
#include "Chat.h"
#include "GameEventMgr.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"
#include "MapManager.h"
#include "ScriptedGossip.h"
#include "SpellAuraEffects.h"
#include "CreatureAIImpl.h"
#include "Mail.h"
#include "TemporarySummon.h"
/*
NpcBot System by Graff (onlysuffering@gmail.com)
Original patch from: LordPsyan https://bitbucket.org/lordpsyan/trinitycore-patches/src/3b8b9072280e/Individual/11185-BOTS-NPCBots.patch
TODO:
Implement Racial Abilities
Quests
I NEED MORE

Further updates/features by: thesawolf (@ gmail . com) 
*/
const uint8 GroupIconsFlags[TARGETICONCOUNT] =
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

static std::set<uint32> BotCustomSpells;
static bool SPELLS_DEFINED = false;

extern bool _enableNpcBots;
extern bool _botPvP;
extern uint8 _maxClassNpcBots;
extern uint8 _healTargetIconFlags;
extern float _mult_dmg_melee;
extern float _mult_dmg_spell;
extern float _mult_healing;

bot_minion_ai::bot_minion_ai(Creature* creature) : bot_ai(creature)
{
    Potion_cd = 0;
    pvpTrinket_cd = 30000;
    rezz_cd = 0;
    myangle = 0.f;
    mana_cd = 0;
    health_cd = 0;
    feast_health = false;
    feast_mana = false;
    _classinfo = new PlayerClassLevelInfo();

    for (uint8 i = 0; i != BOT_INVENTORY_SIZE; ++i)
        for (uint8 j = 0; j != MAX_BOT_ITEM_MOD; ++j)
            _stats[i][j] = 0;

    for (uint8 i = 0; i != BOT_INVENTORY_SIZE; ++i)
        _equips[i] = NULL;

    _reviveTimer = 0;
    _saveTimer = 0;
    _powersTimer = 0;
    _chaseTimer = 0;

    _jumpCount = 0;
    _evadeCount = 0;

    _lastTargetGuid.Clear();
}
bot_minion_ai::~bot_minion_ai()
{
    for (uint8 i = 0; i != BOT_INVENTORY_SIZE; ++i)
        if (_equips[i])
            delete _equips[i];
    delete _classinfo;
}

bot_pet_ai::bot_pet_ai(Creature* creature) : bot_ai(creature)
{
    m_creatureOwner = me->GetCreatureOwner();
    basearmor = 0;
}
bot_pet_ai::~bot_pet_ai() { }

bot_ai::bot_ai(Creature* creature) : ScriptedAI(creature)
{
    bot_ai::InitBotCustomSpells();

    ResetBotAI(BOTAI_RESET_INIT);
    m_botCommandState = COMMAND_FOLLOW;
    checkMasterTimer = urand(5000, 15000);
    needparty = false;
    spawned = false;
    firstspawn = true;
    _evadeMode = false;
    _atHome = true;
    _temp = me->GetSpawnId() ? false : true;
    _roleMask = 0;
    haste = 0;
    blockvalue = 1;
    hit = 0.f;
    parry = 0.f;
    dodge = 0.f;
    block = 0.f;
    crit = 0.f;
    dmg_taken = 1.f;
    expertise = 0;
    spellpower = 0;
    spellpen = 0;
    regen_mp = 0;
    regenTimer_hp = 0;
    regenTimer_mp = 0;
    regenTimer_nrg = 0;
    m_botSpellInfo = NULL;
    clear_cd = 2;
    temptimer = 0;
    wait = 15;
    GC_Timer = 0;
    lastdiff = 0;
    _bootTimer = -1;
    _updateTimerMedium = 0;
    checkAurasTimer = 20;
    roleTimer = 0;
    cost = 0;
    doHealth = false;
    doMana = false;
    //shouldUpdateStats = true;
    pos.m_positionX = 0.f;
    pos.m_positionY = 0.f;
    pos.m_positionZ = 0.f;
    aftercastTargetGuid.Clear();
    currentSpell = 0;

    //visUpEvent = NULL;
    teleHomeEvent = NULL;
    //evadeEvent = NULL;
    teleFinishEvent = NULL;
}
bot_ai::~bot_ai() { }

uint16 bot_ai::Rand() const
{
    if (IsMinionAI())
        return IAmFree() ? urand(0, 100) : urand(0, 100 + (master->GetNpcBotsCount() - 1) * 10);
    else
        return IAmFree() ? urand(0, 100) : urand(0, 100);
}

void bot_ai::BotSay(char const* text, Player const* target) const
{
    if (!target && master->GetTypeId() == TYPEID_PLAYER)
        target = master;
    if (!target)
        return;

    me->Say(text, LANG_UNIVERSAL, target);
}
void bot_ai::BotWhisper(char const* text, Player* target) const
{
    if (!target && master->GetTypeId() == TYPEID_PLAYER)
        target = master;
    if (!target)
        return;

    me->Whisper(text, LANG_UNIVERSAL, target);
}
void bot_ai::BotYell(char const* text, Player const* target) const
{
    if (!target && master->GetTypeId() == TYPEID_PLAYER)
        target = master;
    if (!target)
        return;

    me->Yell(text, LANG_UNIVERSAL, target);
}
//thesawolf - let's play sound
bool bot_ai::PlaySound(uint32 emote)
{
    if (EmotesTextSoundEntry const* soundEntry = FindTextSoundEmoteFor(emote, me->getRace(), me->getGender()))
    {
        me->PlayDistanceSound(soundEntry->SoundId);
        return true;
    }
    
    return false;
}
bool bot_ai::SetBotOwner(Player* newowner)
{
    ASSERT(newowner && "Trying to set NULL owner!!!");
    ASSERT(newowner->GetGUID().IsPlayer() && "Trying to set a non-player as owner!!!");
    //ASSERT(master->GetGUID() == me->GetGUID());
    //ASSERT(!IsMinionAI() || IAmFree());

    //have master already
    if (master->GetGUID() != me->GetGUID())
    {
        TC_LOG_ERROR("entities.player", "bot_ai::SetBotOwner(): bot %s (id: %u) has master %s while trying to set to %s...",
            me->GetName().c_str(), me->GetEntry(), master->GetName().c_str(), newowner->GetName().c_str());
        return false;
    }
    if (IsMinionAI() && !IAmFree())
    {
        TC_LOG_ERROR("entities.player", "bot_ai::SetBotOwner(): minion bot %s (id: %u) IS NOT FREE (has master %s) while trying to set to %s",
            me->GetName().c_str(), me->GetEntry(), master->GetName().c_str(), newowner->GetName().c_str());
        return false;
    }

    if (IsMinionAI())
    {
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
                TC_LOG_ERROR("entities.player", "bot_ai::FindMaster(): %s's master %s (guid: %u) is found but bot failed to set owner (fatal)! Unbinding bot temporarily (until server restart)...",
                    me->GetName().c_str(), newowner->GetName().c_str(), newowner->GetGUID().GetCounter());
                _ownerGuid = 0;
            }

            checkMasterTimer = 30000;
            ResetBotAI(BOTAI_RESET_LOST);
            return false;
        }

        (const_cast<CreatureTemplate*>(me->GetCreatureTemplate()))->unit_flags2 &= ~(UNIT_FLAG2_ALLOW_ENEMY_INTERACT);
        me->SetUInt32Value(UNIT_FIELD_FLAGS_2, me->GetCreatureTemplate()->unit_flags2);
    }

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
    if (resetType & BOTAI_RESET_ABANDON_MASTER)
        _ownerGuid = 0;

    (const_cast<CreatureTemplate*>(me->GetCreatureTemplate()))->unit_flags2 |= (UNIT_FLAG2_ALLOW_ENEMY_INTERACT);
    me->SetUInt32Value(UNIT_FIELD_FLAGS_2, me->GetCreatureTemplate()->unit_flags2);

    me->IsAIEnabled = true;
    me->SetCanUpdate(true);

    if (spawned)
        ReturnHome();

    if (!me->IsInWorld())
    {
        ASSERT(IsMinionAI());
        AbortTeleport();

        //if no master - will teleport to spawn position
        //otherwise - will teleport to master
        teleHomeEvent = new TeleportHomeEvent(ToMinionAI());
        events.AddEvent(teleHomeEvent, events.CalculateTime(0)); //make sure event will be deleted
        //thesawolf - TC commit 1ad73212dca0cf8a829d15ffdbcc4cd611e64d4e
        //		changed this, updating to new calls
        //teleHomeEvent->to_Abort = true; //make sure event will not be executed twice
//        teleHomeEvent->ScheduleAbort(); //thesawolf - test teleport fix
        teleHomeEvent->Execute(0,0);
    }
    else
    {
        _atHome = false;
        spawned = false;
    }
}

SpellCastResult bot_ai::CheckBotCast(Unit* victim, uint32 spellId, uint8 botclass) const
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

    //if (Powers(spellInfo->PowerType) == me->getPowerType() &&
    //    (int32)me->GetPower(me->getPowerType()) < spellInfo->CalcPowerCost(me, spellInfo->GetSchoolMask()))
    //    return SPELL_FAILED_NO_POWER;

    if ((int32)me->GetPower(Powers(spellInfo->PowerType)) < spellInfo->CalcPowerCost(me, spellInfo->GetSchoolMask()) && botclass != BOT_CLASS_ROGUE)
        return SPELL_FAILED_NO_POWER;

    if (victim->isType(TYPEMASK_UNIT) && InDuel(victim))
        return SPELL_FAILED_BAD_TARGETS;

    if (victim->isType(TYPEMASK_UNIT) && !spellInfo->IsPassive())
    {
        bool needRankSelection = false;
        for (uint8 i = 0; i != MAX_SPELL_EFFECTS; ++i)
        {
            if (spellInfo->IsPositiveEffect(i) &&
                (spellInfo->Effects[i].Effect == SPELL_EFFECT_APPLY_AURA ||
                spellInfo->Effects[i].Effect == SPELL_EFFECT_APPLY_AREA_AURA_PARTY ||
                spellInfo->Effects[i].Effect == SPELL_EFFECT_APPLY_AREA_AURA_RAID))
            {
                needRankSelection = true;
                break;
            }
        }
        if (needRankSelection && victim->getLevel() < spellInfo->GetFirstRankSpell()->BaseLevel)
            return SPELL_FAILED_LOWLEVEL;
    }

    //disarmed
    if (spellInfo->EquippedItemClass == ITEM_CLASS_WEAPON)
    {
        if (spellInfo->EquippedItemInventoryTypeMask != 0)
        {
            if ((spellInfo->EquippedItemInventoryTypeMask & (1 << INVTYPE_WEAPONMAINHAND)) &&
                !me->CanUseAttackType(BASE_ATTACK))
                return SPELL_FAILED_EQUIPPED_ITEM_CLASS_MAINHAND;
            if ((spellInfo->EquippedItemInventoryTypeMask & (1 << INVTYPE_WEAPONOFFHAND)) &&
                !me->CanUseAttackType(OFF_ATTACK))
                return SPELL_FAILED_EQUIPPED_ITEM_CLASS_OFFHAND;
            if ((spellInfo->EquippedItemInventoryTypeMask & ((1 << INVTYPE_RANGED) | (1 << INVTYPE_RANGEDRIGHT))) &&
                !me->CanUseAttackType(RANGED_ATTACK))
                return SPELL_FAILED_EQUIPPED_ITEM_CLASS;
        }
        else if (!me->CanUseAttackType(BASE_ATTACK))
            return SPELL_FAILED_EQUIPPED_ITEM_CLASS_MAINHAND;
    }

    if (victim->isType(TYPEMASK_UNIT) && !CheckImmunities(spellId, victim))
        return SPELL_FAILED_BAD_TARGETS;

    switch (botclass)
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
        case BOT_CLASS_WARRIOR:
            //BladeStorm
            if (me->HasAura(46924/*67541*/))
                return SPELL_FAILED_CANT_DO_THAT_RIGHT_NOW;
            break;
        case BOT_CLASS_BM:
            //BladeStorm PLACEHOLDER
            if (me->HasAura(46924/*67541*/))
                return SPELL_FAILED_CANT_DO_THAT_RIGHT_NOW;
            break;
        case BOT_CLASS_ROGUE:
        case BOT_CLASS_HUNTER:
        case BOT_CLASS_DEATH_KNIGHT:
            break;
        default:
            TC_LOG_ERROR("entities.player", "CheckBotCast(): Unknown bot class %u", botclass);
            break;
    }

    return SPELL_CAST_OK;
}

bool bot_ai::doCast(Unit* victim, uint32 spellId, bool triggered, ObjectGuid originalCaster)
{
    if (spellId == 0) return false;
    if (IsCasting()) return false;
    if (!victim || !victim->IsInWorld() || me->GetMap() != victim->FindMap()) return false;

    m_botSpellInfo = sSpellMgr->GetSpellInfo(spellId);
    if (!m_botSpellInfo)
        return false;

    //select aura level
    if (victim->isType(TYPEMASK_UNIT))
        if (SpellInfo const* actualSpellInfo = m_botSpellInfo->GetAuraRankForLevel(victim->getLevel()))
            m_botSpellInfo = actualSpellInfo;

    if (m_botSpellInfo->CalcCastTime() && JumpingFlyingOrFalling())
        return false;

    if (spellId == MANAPOTION)
    {
        value = urand(me->GetMaxPower(POWER_MANA)/4, me->GetMaxPower(POWER_MANA)/2);
        me->CastCustomSpell(victim, spellId, &value, 0, 0, true);
        return true;
    }
    else if (spellId == HEALINGPOTION)
    {
        value = urand(me->GetMaxHealth()/3, me->GetMaxHealth()/2);
        me->CastCustomSpell(victim, spellId, &value, 0, 0, true);
        return true;
    }

    //check cooldown
    if (!IsSpellReady(m_botSpellInfo->GetFirstRankSpell()->Id, lastdiff, false))
        return false;

    //remove shapeshifts manually to restore powers/stats
    if (me->GetShapeshiftForm() != FORM_NONE)
    {
        if (m_botSpellInfo->CheckShapeshift(me->GetShapeshiftForm()) != SPELL_CAST_OK)
            removeFeralForm(true);
    }

    if (!(m_botSpellInfo->Attributes & SPELL_ATTR0_CASTABLE_WHILE_SITTING))
        me->SetStandState(UNIT_STAND_STATE_STAND);

    if (!IAmFree() && victim->isType(TYPEMASK_UNIT) && !victim->IsWithinLOSInMap(me) && IsInBotParty(victim))
    {
        //std::ostringstream msg;
        //msg << "casting " << spellInfo->SpellName[0] << " on " << victim->GetName();
        //BotWhisper(msg.str().c_str(), master);
        me->Relocate(victim);
    }

    if (me->isMoving() && m_botSpellInfo->CalcCastTime() > 0)
        me->BotStopMovement();

    TriggerCastFlags flags = triggered ? TRIGGERED_FULL_MASK : TRIGGERED_NONE;
    SpellCastTargets targets;
    targets.SetUnitTarget(victim);
    Spell* spell = new Spell(me, m_botSpellInfo, flags, originalCaster);
    spell->prepare(&targets); //sets current spell if succeed

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
        //delete spell; //crash due to invalid event added to master's eventmap
        return false;
    }

    currentSpell = spellId;

    float gcd;

    if (_botclass == BOT_CLASS_ROGUE || GetBotStance() == DRUID_CAT_FORM || GetBotStance() == DEATH_KNIGHT_UNHOLY_PRESENCE)
        gcd = 1000.f;
    else
        gcd = 1500.f;

    ApplyBotSpellGlobalCooldownMods(m_botSpellInfo, gcd);

    //Apply haste to cooldown
    if (haste)
        ApplyPercentModFloatVar(gcd, float(haste), false);
    //global cd cannot be less than 500 ms
    GC_Timer = std::max<int32>(gcd, 500);
    //global cd cannot be greater than 1500 ms
    GC_Timer = std::min<int32>(gcd, 1500);

    return true;
}
//Follow point calculation
void bot_minion_ai::_calculatePos(Position& pos)
{
    ASSERT(!IAmFree());

    uint8 followdist = master->GetBotFollowDist();
    float mydist, angle;

    if (IsTank())
    {
        mydist = frand(1.5f, 4.5f); //stand a bit farther
        angle = (M_PI/2.f) / 16.f * frand(-3.f, 3.f); //in front +-pi/5
    }
    else if (IsMelee())
    {
        mydist = frand(0.5f, 2.f);
        angle = (M_PI/2.f) / 8.f * RAND(frand(5.f, 10.f), frand(-10.f, -5.f)); //to the sides +-(pi/3 to pi/1.6)
    }
    else
    {
        mydist = frand(0.15f, 0.8f);
        angle = (M_PI/2.f) / 6.f * frand(10.5f, 13.5f); //behind pi+-pi/4.5
    }
    //myangle = angle used last time
    //if difference between last angle and cur angle is too big, use new angle
    //else use last angle (prevent constant struggling)
    if (abs(abs(myangle) - abs(angle)) > M_PI/3.f)
        myangle = angle;
    else
        angle = myangle;
    mydist += std::max<float>(int8(followdist) - 30, 0) / 5.f; //0.f-9.f
    //mydist += followdist > 10 ? float(followdist - 10)/4.f : 0.f; //distance from 10+ is reduced
    mydist = std::min<float>(mydist, 50.f); //do not spread bots too much
    //thesawolf - spread out some
    //mydist = std::max<float>(mydist - 5.f, 0.0f); //get bots closer
    angle += master->GetOrientation();
    float x(0),y(0),z(0);
    float size = me->GetObjectSize()/3.f;
    bool over = false;
    for (uint8 i = 0; i != 5 + over; ++i)
    {
        if (over)
        {
            mydist *= 0.2f;
            break;
        }
        master->GetNearPoint(me, x, y, z, size, mydist, angle);
        if (!master->IsWithinLOS(x,y,z)) //try to get much closer to master
        {
            mydist *= 0.4f - float(i*0.07f);
            size *= 0.1f;
            if (size < 0.1)
                size = 0.f;
            if (size == 0.f && me->GetPositionZ() < master->GetPositionZ())
                z += 0.25f; //prevent going underground
        }
        else
            over = true;
    }
    pos.m_positionX = x;
    pos.m_positionY = y;
    pos.m_positionZ = z;

    //           TTT
    //     m      T      m
    //    mmmmmm MMM mmmmmm
    //     m   ddddddd   m
    //      ddddddddddddd
    //        ddddddddd
    //
    //MMM - master
    //T - bot tank (ROLE_TANK)
    //m - melee (ROLE_MELEE)
    //d - default
}
// Movement set
void bot_minion_ai::SetBotCommandState(CommandStates st, bool force, Position* newpos)
{
    if (!me->IsAlive())
        return;

    if (JumpingFlyingOrFalling())
        return;

    if (st == COMMAND_FOLLOW && !IsChanneling() && ((!me->isMoving() && !IsCasting() && master->IsAlive()) || force))
    {
        if (!me->IsInMap(master)) return;
        if (CCed(me, true)/* || master->HasUnitState(UNIT_STATE_FLEEING)*/) return;
        if (me->isMoving() && Rand() > 20) return;
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
        me->GetMotionMaster()->MovePoint(master->GetMapId(), pos);
        //me->GetMotionMaster()->MoveFollow(master, mydist, angle);
    }
    else if (st == COMMAND_STAY)
    {
        me->BotStopMovement();
    }
    else if (st == COMMAND_ATTACK)
    { }
    m_botCommandState = st;
    if (Creature* m_botsPet = me->GetBotsPet())
        m_botsPet->SetBotCommandState(st, force);
}

void bot_pet_ai::SetBotCommandState(CommandStates st, bool force, Position* /*newpos*/)
{
    if (me->isDead() || IAmDead())
        return;

    if (JumpingFlyingOrFalling())
        return;

    if (st == COMMAND_FOLLOW && ((!me->isMoving() && !IsCasting() && master->IsAlive()) || force))
    {
        if (!me->IsInMap(master)) return;
        if (CCed(me, true)) return;
        if (me->isMoving() && Rand() > 20) return;
        Unit* followtarget = m_creatureOwner;
        if (CCed(m_creatureOwner))
            followtarget = master;
        if (followtarget == m_creatureOwner)
        {
            if (!me->HasUnitState(UNIT_STATE_FOLLOW) || me->GetDistance(master)*0.75f < me->GetDistance(m_creatureOwner))
                me->GetMotionMaster()->MoveFollow(m_creatureOwner, PET_FOLLOW_DIST, PET_FOLLOW_ANGLE);
        }
        else
            if (!me->HasUnitState(UNIT_STATE_FOLLOW) || me->GetDistance(m_creatureOwner)*0.75f < me->GetDistance(master))
                me->GetMotionMaster()->MoveFollow(master, PET_FOLLOW_DIST, PET_FOLLOW_ANGLE);
    }
    else if (st == COMMAND_STAY)//NUY
    {
        me->BotStopMovement();
    }
    else if (st == COMMAND_ATTACK)
    { }
    m_botCommandState = st;
}
// Buffs And Heal (really)
void bot_minion_ai::BuffAndHealGroup(Player* gPlayer, uint32 diff)
{
    if (GC_Timer > diff) return;
    if (me->IsMounted()) return;
    if (IsCasting() || Feasting()) return;

    if (IAmFree())
    {
        if (HealTarget(me, GetHealthPCT(me), diff))
            return;
        if (BuffTarget(me, diff))
            return;
        if (Creature* pet = me->GetBotsPet())
        {
            if (HealTarget(pet, GetHealthPCT(pet), diff))
                return;
            if (BuffTarget(pet, diff))
                return;
        }

        if (me->HasAura(BERSERK))
            return;

        std::list<Unit*> targets;
        GetNearbyFriendlyTargetsList(targets, 30);
        for (std::list<Unit*>::const_iterator itr = targets.begin(); itr != targets.end(); ++itr)
        {
            if (Unit* u = *itr)
            {
                if (HealTarget(u, GetHealthPCT(u), diff))
                    return;
                if (BuffTarget(u, diff))
                    return;
            }
        }

        return;
    }

    Group* pGroup = gPlayer->GetGroup();
    if (!pGroup)
    {
        if (!master->IsInWorld() || master->IsBeingTeleported())
            return;
        if (HasRole(BOT_ROLE_HEAL) && HealTarget(master, GetHealthPCT(master), diff))
            return;
        if (BuffTarget(master, diff))
            return;
        for (Unit::ControlList::const_iterator itr = master->m_Controlled.begin(); itr != master->m_Controlled.end(); ++itr)
        {
            Unit* u = *itr;
            if (!u || !u->IsInWorld() || me->GetMap() != u->FindMap() || !u->IsAlive()) continue;
            if (HasRole(BOT_ROLE_HEAL) && HealTarget(u, GetHealthPCT(u), diff))
                return;
            if (Creature* cre = u->ToCreature())
                if (cre->GetIAmABot() || cre->IsPet())
                    if (BuffTarget(u, diff))
                        return;
        }
        return;
    }
    bool Bots = false;
    for (GroupReference* itr = pGroup->GetFirstMember(); itr != NULL; itr = itr->next())
    {
        Player* tPlayer = itr->GetSource();
        if (tPlayer == NULL) continue;
        if (me->GetMap() != tPlayer->FindMap()) continue;
        if (!tPlayer->m_Controlled.empty())
            Bots = true;
        if (!tPlayer->IsAlive()) continue;
        if (HasRole(BOT_ROLE_HEAL) && HealTarget(tPlayer, GetHealthPCT(tPlayer), diff))
            return;
        if (BuffTarget(tPlayer, diff))
            return;
    }
    if (Bots)
    {
        for (GroupReference* itr = pGroup->GetFirstMember(); itr != NULL; itr = itr->next())
        {
            Player* tPlayer = itr->GetSource();
            if (tPlayer == NULL || tPlayer->m_Controlled.empty()) continue;
            if (me->GetMap() != tPlayer->FindMap()) continue;
            for (Unit::ControlList::const_iterator itr = tPlayer->m_Controlled.begin(); itr != tPlayer->m_Controlled.end(); ++itr)
            {
                Unit* u = *itr;
                if (!u || !u->IsInWorld() || me->GetMap() != u->FindMap() || !u->IsAlive()) continue;
                if (HasRole(BOT_ROLE_HEAL) && HealTarget(u, GetHealthPCT(u), diff))
                    return;
                if (Creature* cre = u->ToCreature())
                    if (cre->GetIAmABot() || cre->IsPet())
                        if (BuffTarget(u, diff))
                            return;
            }
        }
    }
    //check if we have pointed heal target
    if (HasRole(BOT_ROLE_HEAL))
    {
        for (uint8 i = 0; i != TARGETICONCOUNT; ++i)
        {
            if (_healTargetIconFlags & GroupIconsFlags[i])
            {
                if (ObjectGuid guid = pGroup->GetTargetIcons()[i])//check this one
                {
                    if (Unit* unit = ObjectAccessor::FindConnectedPlayer(guid))
                    {
                        if (unit->IsAlive() && me->GetMap() == unit->FindMap() &&
                            master->GetVictim() != unit && unit->GetVictim() != master &&
                            unit->GetReactionTo(master) >= REP_NEUTRAL)
                        {
                            if (HealTarget(unit, GetHealthPCT(unit), diff))
                                return;
                            //if (CureTarget(unit, getCureSpell(), diff))
                            //    return;
                        }
                    }
                }
            }
        }
    }
}
// Attempt to resurrect dead players using class spells
// Target is either player or its corpse
void bot_minion_ai::RezGroup(uint32 REZZ, Player* gPlayer)
{
    if (!REZZ || !gPlayer || me->IsMounted()) return;
    if (rezz_cd > 0 || Rand() > 10) return;

    if (IAmFree())
    {
        if (me->HasAura(BERSERK))
            return;

        WorldObject* playerOrCorpse = GetNearbyRezTarget(30);
        if (!playerOrCorpse)
            return;

        if (!playerOrCorpse->IsWithinLOSInMap(me))
            me->Relocate(*playerOrCorpse);

        Unit* target = playerOrCorpse->GetTypeId() == TYPEID_PLAYER ? playerOrCorpse->ToUnit() : (Unit*)playerOrCorpse->ToCorpse();
        if (doCast(target, REZZ)) //rezzing it
        {
            if (Player* player = playerOrCorpse->GetTypeId() == TYPEID_PLAYER ? playerOrCorpse->ToPlayer() : ObjectAccessor::FindPlayer(playerOrCorpse->ToCorpse()->GetOwnerGUID()))
                BotWhisper("Rezzing You", player);
            rezz_cd = 20;
        }

        return;
    }

    //TC_LOG_ERROR("entities.player", "RezGroup by %s", me->GetName().c_str());
    Group* pGroup = gPlayer->GetGroup();
    if (!pGroup)
    {
        Unit* target = master;
        if (master->IsAlive()) return;
        if (master->IsResurrectRequested()) return; //resurrected
        if (master->HasFlag(PLAYER_FLAGS, PLAYER_FLAGS_GHOST))
            target = (Unit*)master->GetCorpse();
        if (!target || !target->IsInWorld()) return;
        if (me->GetMap() != target->FindMap()) return;
        if (me->GetDistance(target) > 30)
        {
            me->GetMotionMaster()->MovePoint(master->GetMapId(), *target);
            rezz_cd = 3;//6-9 sec reset
            return;
        }
        else if (!target->IsWithinLOSInMap(me))
            me->Relocate(*target);

        if (doCast(target, REZZ))//rezzing it
        {
            BotWhisper("Rezzing You", master);
            rezz_cd = 60;
        }
        return;
    }
    for (GroupReference* itr = pGroup->GetFirstMember(); itr != NULL; itr = itr->next())
    {
        Player* tPlayer = itr->GetSource();
        Unit* target = tPlayer;
        if (!tPlayer || tPlayer->IsAlive()) continue;
        if (tPlayer->IsResurrectRequested()) continue; //resurrected
        if (Rand() > 5) continue;
        if (tPlayer->HasFlag(PLAYER_FLAGS, PLAYER_FLAGS_GHOST))
            target = (Unit*)tPlayer->GetCorpse();
        if (!target || !target->IsInWorld()) continue;
        if (master->GetMap() != target->FindMap()) continue;
        if (me->GetDistance(target) > 30)
        {
            me->GetMotionMaster()->MovePoint(master->GetMapId(), *target);
            rezz_cd = 3;//6-9 sec reset
            return;
        }
        else if (!target->IsWithinLOSInMap(me))
            me->Relocate(*target);

        if (doCast(target, REZZ))//rezzing it
        {
            BotWhisper("Rezzing You", tPlayer);
            if (tPlayer != master)
            {
                std::string rezstr = "Rezzing ";
                rezstr += tPlayer->GetName();
                BotWhisper(rezstr.c_str(), master);
            }
            rezz_cd = 60;
            return;
        }
    }
}
// CURES
//cycle through the group sending members for cure
void bot_minion_ai::CureGroup(Player* pTarget, uint32 cureSpell, uint32 diff)
{
    if (!cureSpell || GC_Timer > diff) return;
    if (me->getLevel() < 10 || pTarget->getLevel() < 10) return;
    if (me->IsMounted()) return;
    if (IsCasting() || Feasting()) return;

    if (IAmFree())
    {
        if (CureTarget(me, cureSpell, diff))
            return;
        if (Creature* pet = me->GetBotsPet())
            if (CureTarget(pet, cureSpell, diff))
                return;

        if (me->HasAura(BERSERK))
            return;
        /* stop spam buff/dispell from uncontrolled bots
        GuidList targets;
        GetNearbyFriendlyTargetsList(targets, 38);
        for (GuidList::const_iterator itr = targets.begin(); itr != targets.end(); ++itr)
            if (Unit* u = ObjectAccessor::GetUnit(*me, *itr))
                if (CureTarget(u, cureSpell, diff))
                    return;
        */
        return;
    }

    if (!master->GetMap()->IsRaid() && Rand() > 75) return;
    //TC_LOG_ERROR("entities.player", "%s: CureGroup() on %s", me->GetName().c_str(), pTarget->GetName().c_str());
    Group* pGroup = pTarget->GetGroup();
    if (!pGroup)
    {
        if (CureTarget(master, cureSpell, diff))
            return;
        BotMap const* map = master->GetBotMgr()->GetBotMap();
        for (BotMap::const_iterator itr = map->begin(); itr != map->end(); ++itr)
        {
            Creature* cre = itr->second;
            if (!cre || !cre->IsInWorld() || me->GetDistance(cre) > 30) continue;
            if (CureTarget(cre, cureSpell, diff))
                return;
        }
    }
    else
    {
        bool Bots = false;
        for (GroupReference* itr = pGroup->GetFirstMember(); itr != NULL; itr = itr->next())
        {
            Player* tPlayer = itr->GetSource();
            if (!tPlayer || (tPlayer->isDead() && !tPlayer->HaveBot())) continue;
            if (!Bots && tPlayer->HaveBot())
                Bots = true;
            if (!tPlayer->IsInWorld() || tPlayer->IsBeingTeleported()) continue;
            if (me->GetMap() != tPlayer->FindMap()) continue;
            if (me->GetDistance(tPlayer) > 30) continue;
            if (CureTarget(tPlayer, cureSpell, diff))
                return;
        }
        if (!Bots) return;
        for (GroupReference* itr = pGroup->GetFirstMember(); itr != NULL; itr = itr->next())
        {
            Player* tPlayer = itr->GetSource();
            if (tPlayer == NULL || !tPlayer->HaveBot()) continue;
            if (!tPlayer->IsInWorld() || tPlayer->IsBeingTeleported()) continue;
            if (me->GetMap() != tPlayer->FindMap()) continue;
            BotMap const* map = tPlayer->GetBotMgr()->GetBotMap();
            for (BotMap::const_iterator it = map->begin(); it != map->end(); ++it)
            {
                Creature* cre = it->second;
                if (!cre || !cre->IsInWorld() || me->GetDistance(cre) > 30) continue;
                if (CureTarget(cre, cureSpell, diff))
                    return;
            }
        }
    }
}

bool bot_minion_ai::CureTarget(Unit* target, uint32 cureSpell, uint32 diff)
{
    return _canCureTarget(target, cureSpell, diff) ? doCast(target, cureSpell) : false;
}
// determines if unit has something to cure
bool bot_minion_ai::_canCureTarget(Unit* target, uint32 cureSpell, uint32 diff) const
{
    if (!cureSpell || GC_Timer > diff) return false;
    if (!target || !target->IsAlive()) return false;
    if (me->getLevel() < 10 || target->getLevel() < 10) return false;
    if (me->IsMounted()) return false;
    if (IsCasting() || Feasting()) return false;
    if (me->GetDistance(target) > 30) return false;
    if (!IsInBotParty(target)) return false;

    SpellInfo const* info = sSpellMgr->GetSpellInfo(cureSpell);
    if (!info)
        return false;

    uint32 dispelMask = 0;
    for (uint8 i = 0; i != MAX_SPELL_EFFECTS; ++i)
        if (info->Effects[i].Effect == SPELL_EFFECT_DISPEL)
            dispelMask |= SpellInfo::GetDispelMask(DispelType(info->Effects[i].MiscValue));

    if (dispelMask == 0)
        return false;

    std::list<std::pair<Aura*, uint8>> dispel_list;
    _getBotDispellableAuraList(target, me, dispelMask, dispel_list);

    return !(dispel_list.empty());
}

void bot_minion_ai::_getBotDispellableAuraList(Unit* target, Unit* caster, uint32 dispelMask, std::list<std::pair<Aura*, uint8>>& dispelList) const
{
    if (dispelMask & (1 << DISPEL_DISEASE) && target->HasAura(50536))
        dispelMask &= ~(1 << DISPEL_DISEASE);

    Unit::AuraMap const& auras = target->GetOwnedAuras();
    for (Unit::AuraMap::const_iterator itr = auras.begin(); itr != auras.end(); ++itr)
    {
        Aura* aura = itr->second;

        if (aura->IsPassive())
            continue;

        AuraApplication* aurApp = aura->GetApplicationOfTarget(target->GetGUID());
        if (!aurApp)
            continue;

        if (aura->GetSpellInfo()->GetDispelMask() & dispelMask)
        {
            //do not dispel positive auras from enemies and negative ones from friends
            if (aurApp->IsPositive() == target->IsFriendlyTo(caster))
                continue;

            //skip Vampiric Touch to prevent being CCed just heal it out
            if (aura->GetSpellInfo()->IsRankOf(sSpellMgr->GetSpellInfo(34914)))
                continue;

            uint8 charges = (aura->GetSpellInfo()->AttributesEx7 & SPELL_ATTR7_DISPEL_CHARGES) ? aura->GetCharges() : aura->GetStackAmount();
            if (charges > 0)
                dispelList.push_back(std::make_pair(aura, charges));
        }
    }
}
//protected
bool bot_ai::HasAuraName(Unit* unit, uint32 spellId, ObjectGuid casterGuid, bool exclude) const
{
    ASSERT(spellId);

    SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(spellId);
    if (!spellInfo)
    {
        TC_LOG_ERROR("entities.player", "bot_ai::HasAuraName(uint32): no spellInfo found for spell %u!", spellId);
        ASSERT(false);
    }

    uint8 loc = IAmFree() ? sWorld->GetDefaultDbcLocale() : master->GetSession()->GetSessionDbcLocale();
    std::string const name = spellInfo->SpellName[loc];

    return _hasAuraName(unit, name, casterGuid, exclude);
}
//private
bool bot_ai::_hasAuraName(Unit* unit, std::string const spell, ObjectGuid casterGuid, bool exclude) const
{
    ASSERT(unit);
    ASSERT(spell.length() != 0);

    uint8 loc = IAmFree() ? sWorld->GetDefaultDbcLocale() : master->GetSession()->GetSessionDbcLocale();

    Unit::AuraMap const& vAuras = unit->GetOwnedAuras();
    SpellInfo const* spellInfo;
    std::string name;

    for (Unit::AuraMap::const_iterator itr = vAuras.begin(); itr != vAuras.end(); ++itr)
    {
        spellInfo = itr->second->GetSpellInfo();
        name = spellInfo->SpellName[loc];
        if (spell == name)
            if (!casterGuid || (exclude == (casterGuid != itr->second->GetCasterGUID())))
                return true;
    }

    return false;
}
//LIST AURAS
// Debug: Returns bot's info to called player
void bot_ai::_listAuras(Player* player, Unit* unit) const
{
    //if (player->GetSession()->GetSecurity() == SEC_PLAYER) return;
    if (!player->IsGameMaster() && (IAmFree() || !IsInBotParty(player))) return;
    if (!IsInBotParty(unit)) return;
    ChatHandler ch(player->GetSession());
    std::ostringstream botstring;
    if (unit->GetTypeId() == TYPEID_PLAYER)
        botstring << "player";
    else if (unit->GetTypeId() == TYPEID_UNIT)
    {
        if (unit->ToCreature()->GetIAmABot())
        {
            botstring << "minion bot, master: ";
            Player* owner = unit->ToCreature()->GetBotAI()->GetBotOwner();
            botstring << (owner != unit ? owner->GetName() : "none");
        }
        else if (unit->ToCreature()->GetIAmABotsPet())
        {
            Player* owner = unit->ToCreature()->GetBotAI()->GetBotOwner();
            Creature* creowner = unit->ToCreature()->GetBotPetAI()->GetCreatureOwner();
            std::string const& ownername = owner != unit ? owner->GetName() : "none";
            std::string const& creownername = creowner ? creowner->GetName() : "none";
            botstring << "pet bot, master: ";
            botstring << ownername;
            botstring << ", creature owner: ";
            botstring << creownername;
            if (creowner)
                botstring << " (" << creowner->GetGUID().GetCounter() << ')';
        }
    }
    uint32 const bot_pet_player_class = unit->GetTypeId() == TYPEID_PLAYER ? unit->getClass() : unit->ToCreature()->GetBotAI()->GetBotClass();
    ch.PSendSysMessage("ListAuras for %s (class: %u), %s", unit->GetName().c_str(), bot_pet_player_class, botstring.str().c_str());
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
        std::ostringstream spellmsg;
        spellmsg << id << " - |cffffffff|Hspell:" << id << "|h[" << name;
        spellmsg << ' ' << localeNames[locale] << "]|h|r";
        uint32 talentcost = GetTalentSpellCost(id);
        uint32 rank = 0;
        if (talentcost > 0 && spellInfo->GetNextRankSpell())
            rank = talentcost;
        else if (learnSpellInfo && learnSpellInfo->GetNextRankSpell())
            rank = spellInfo->GetRank();
        else if (spellInfo->GetNextRankSpell())
            rank = spellInfo->GetRank();
        if (rank > 0)
            spellmsg << " Rank " << rank;
        if (talentcost > 0)
            spellmsg << " [talent]";
        if (spellInfo->IsPassive())
            spellmsg << " [passive]";
        if ((spellInfo->Attributes & SPELL_ATTR0_HIDDEN_CLIENTSIDE) ||
            (spellInfo->AttributesEx & SPELL_ATTR1_DONT_DISPLAY_IN_AURA_BAR))
            spellmsg << " [hidden]";
        if (unit->GetTypeId() == TYPEID_PLAYER && unit->ToPlayer()->HasSpell(id))
            spellmsg << " [known]";
        else if (unit == me && GetSpell(spellInfo->GetFirstRankSpell()->Id))
            spellmsg << " [known]";

        ch.PSendSysMessage(spellmsg.str().c_str());
    }
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
        float totalstat = unit->GetTotalStatValue(Stats(i));
        if (unit == me && IsMinionAI())
        {
            int8 t = -1;
            switch (i)
            {
                case STAT_STRENGTH:     t = BOT_ITEM_MOD_STRENGTH;  break;
                case STAT_AGILITY:      t = BOT_ITEM_MOD_AGILITY;   break;
                case STAT_STAMINA:      t = BOT_ITEM_MOD_STAMINA;   break;
                case STAT_INTELLECT:    t = BOT_ITEM_MOD_INTELLECT; break;
                case STAT_SPIRIT:       t = BOT_ITEM_MOD_SPIRIT;    break;
                default:                                            break;
            }

            if (t >= BOT_ITEM_MOD_MANA)
                totalstat += GetMinionAI()->GetTotalBotStat(t);
        }
        ch.PSendSysMessage("total %s: %.1f", mystat.c_str(), totalstat);
    }
    ch.PSendSysMessage("Melee AP: %.1f", unit->GetTotalAttackPowerValue(BASE_ATTACK));
    ch.PSendSysMessage("Ranged AP: %.1f", unit->GetTotalAttackPowerValue(RANGED_ATTACK));
    ch.PSendSysMessage("armor: %u", unit->GetArmor());
    ch.PSendSysMessage("crit: %.2f pct", unit->GetUnitCriticalChance(BASE_ATTACK, me));
    ch.PSendSysMessage("dodge: %.2f pct", unit->GetUnitDodgeChance(BASE_ATTACK, me));
    ch.PSendSysMessage("parry: %.2f pct", unit->GetUnitParryChance(BASE_ATTACK, me));
    ch.PSendSysMessage("block: %.2f pct", unit->GetUnitBlockChance(BASE_ATTACK, me));
    ch.PSendSysMessage("block value: %u", unit->GetShieldBlockValue());
    ch.PSendSysMessage("Damage taken melee: %.3f", unit->GetTotalAuraMultiplierByMiscMask(SPELL_AURA_MOD_DAMAGE_PERCENT_TAKEN, SPELL_SCHOOL_MASK_NORMAL));
    ch.PSendSysMessage("Damage taken spell: %.3f", unit->GetTotalAuraMultiplierByMiscMask(SPELL_AURA_MOD_DAMAGE_PERCENT_TAKEN, SPELL_SCHOOL_MASK_MAGIC));
    if (unit != me || ap_mod > 0.0f)
    {
        WeaponAttackType type = BASE_ATTACK;
        float attSpeed = (unit->GetAttackTime(type) * unit->m_modAttackSpeedPct[type])/1000.f;
        ch.PSendSysMessage("Damage range mainhand: min: %.0f, max: %.0f", unit->GetFloatValue(UNIT_FIELD_MINDAMAGE), unit->GetFloatValue(UNIT_FIELD_MAXDAMAGE));
        ch.PSendSysMessage("Damage mult mainhand: %.3f", unit->GetPctModifierValue(UNIT_MOD_DAMAGE_MAINHAND, BASE_PCT)*unit->GetPctModifierValue(UNIT_MOD_DAMAGE_MAINHAND, TOTAL_PCT));
        ch.PSendSysMessage("Attack time mainhand: %.2f (%.1f DPS)", attSpeed,
            ((unit->GetFloatValue(UNIT_FIELD_MINDAMAGE) + unit->GetFloatValue(UNIT_FIELD_MAXDAMAGE)) / 2) * unit->GetPctModifierValue(UNIT_MOD_DAMAGE_MAINHAND, BASE_PCT) * unit->GetPctModifierValue(UNIT_MOD_DAMAGE_MAINHAND, TOTAL_PCT) / attSpeed);
        if (unit->haveOffhandWeapon())
        {
            type = OFF_ATTACK;
            attSpeed = (unit->GetAttackTime(type) * unit->m_modAttackSpeedPct[type])/1000.f;
            ch.PSendSysMessage("Damage range offhand: min: %.0f, max: %.0f", unit->GetFloatValue(UNIT_FIELD_MINOFFHANDDAMAGE), unit->GetFloatValue(UNIT_FIELD_MAXOFFHANDDAMAGE));
            ch.PSendSysMessage("Damage mult offhand: %.3f", unit->GetPctModifierValue(UNIT_MOD_DAMAGE_OFFHAND, BASE_PCT)*unit->GetPctModifierValue(UNIT_MOD_DAMAGE_OFFHAND, TOTAL_PCT));
            ch.PSendSysMessage("Attack time offhand: %.2f (%.1f DPS)", attSpeed,
                ((unit->GetFloatValue(UNIT_FIELD_MINOFFHANDDAMAGE) + unit->GetFloatValue(UNIT_FIELD_MAXOFFHANDDAMAGE)) / 2) * unit->GetPctModifierValue(UNIT_MOD_DAMAGE_OFFHAND, BASE_PCT) * unit->GetPctModifierValue(UNIT_MOD_DAMAGE_OFFHAND, TOTAL_PCT) / attSpeed);
        }
        if (unit != me ||
            (me->GetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID + 2) &&
            GetBotClass() != BOT_CLASS_PALADIN &&
            GetBotClass() != BOT_CLASS_DEATH_KNIGHT &&
            GetBotClass() != BOT_CLASS_DRUID &&
            GetBotClass() != BOT_CLASS_SHAMAN))
        {
            type = RANGED_ATTACK;
            attSpeed = (unit->GetAttackTime(type) * unit->m_modAttackSpeedPct[type])/1000.f;
            ch.PSendSysMessage("Damage range ranged: min: %.1f, max: %.1f", unit->GetFloatValue(UNIT_FIELD_MINRANGEDDAMAGE), unit->GetFloatValue(UNIT_FIELD_MAXRANGEDDAMAGE));
            ch.PSendSysMessage("Damage mult ranged: %.3f", unit->GetPctModifierValue(UNIT_MOD_DAMAGE_RANGED, BASE_PCT)*unit->GetPctModifierValue(UNIT_MOD_DAMAGE_RANGED, TOTAL_PCT));
            ch.PSendSysMessage("Attack time ranged: %.2f (%.1f DPS)", attSpeed,
                ((unit->GetFloatValue(UNIT_FIELD_MINRANGEDDAMAGE) + unit->GetFloatValue(UNIT_FIELD_MAXRANGEDDAMAGE)) / 2) * unit->GetPctModifierValue(UNIT_MOD_DAMAGE_RANGED, BASE_PCT) * unit->GetPctModifierValue(UNIT_MOD_DAMAGE_RANGED, TOTAL_PCT) / attSpeed);
        }
    }
    ch.PSendSysMessage("base hp: %u", unit->GetCreateHealth());
    ch.PSendSysMessage("total hp: %u", unit->GetMaxHealth());
    ch.PSendSysMessage("base mana: %u", unit->GetCreateMana());
    ch.PSendSysMessage("total mana: %u", unit->GetMaxPower(POWER_MANA));
    if (unit->GetShapeshiftForm() != FORM_NONE && unit->getPowerType() != POWER_MANA)
        ch.PSendSysMessage("cur mana: %u", unit->GetPower(POWER_MANA));
    //DEBUG1
    //ch.PSendSysMessage("STATS: ");
    //ch.PSendSysMessage("Health");
    //ch.PSendSysMessage("base value: %f", unit->GetModifierValue(UNIT_MOD_HEALTH, BASE_VALUE));
    //ch.PSendSysMessage("base pct: %f", unit->GetModifierValue(UNIT_MOD_HEALTH, BASE_PCT));
    //ch.PSendSysMessage("total value: %f", unit->GetModifierValue(UNIT_MOD_HEALTH, TOTAL_VALUE));
    //ch.PSendSysMessage("total pct: %f", unit->GetModifierValue(UNIT_MOD_HEALTH, TOTAL_PCT));
    //ch.PSendSysMessage("Mana");
    //ch.PSendSysMessage("base value: %f", unit->GetModifierValue(UNIT_MOD_MANA, BASE_VALUE));
    //ch.PSendSysMessage("base pct: %f", unit->GetModifierValue(UNIT_MOD_MANA, BASE_PCT));
    //ch.PSendSysMessage("total value: %f", unit->GetModifierValue(UNIT_MOD_MANA, TOTAL_VALUE));
    //ch.PSendSysMessage("total pct: %f", unit->GetModifierValue(UNIT_MOD_MANA, TOTAL_PCT));
    //ch.PSendSysMessage("Stamina");
    //ch.PSendSysMessage("base value: %f", unit->GetModifierValue(UNIT_MOD_STAT_STAMINA, BASE_VALUE));
    //ch.PSendSysMessage("base pct: %f", unit->GetModifierValue(UNIT_MOD_STAT_STAMINA, BASE_PCT));
    //ch.PSendSysMessage("total value: %f", unit->GetModifierValue(UNIT_MOD_STAT_STAMINA, TOTAL_VALUE));
    //ch.PSendSysMessage("total pct: %f", unit->GetModifierValue(UNIT_MOD_STAT_STAMINA, TOTAL_PCT));
    //ch.PSendSysMessage("Intellect");
    //ch.PSendSysMessage("base value: %f", unit->GetModifierValue(UNIT_MOD_STAT_INTELLECT, BASE_VALUE));
    //ch.PSendSysMessage("base pct: %f", unit->GetModifierValue(UNIT_MOD_STAT_INTELLECT, BASE_PCT));
    //ch.PSendSysMessage("total value: %f", unit->GetModifierValue(UNIT_MOD_STAT_INTELLECT, TOTAL_VALUE));
    //ch.PSendSysMessage("total pct: %f", unit->GetModifierValue(UNIT_MOD_STAT_INTELLECT, TOTAL_PCT));
    //ch.PSendSysMessage("Spirit");
    //ch.PSendSysMessage("base value: %f", unit->GetModifierValue(UNIT_MOD_STAT_SPIRIT, BASE_VALUE));
    //ch.PSendSysMessage("base pct: %f", unit->GetModifierValue(UNIT_MOD_STAT_SPIRIT, BASE_PCT));
    //ch.PSendSysMessage("total value: %f", unit->GetModifierValue(UNIT_MOD_STAT_SPIRIT, TOTAL_VALUE));
    //ch.PSendSysMessage("total pct: %f", unit->GetModifierValue(UNIT_MOD_STAT_SPIRIT, TOTAL_PCT));
    //END DEBUG1
    if (unit == me)
    {
        ch.PSendSysMessage("melee damage mult: %.3f", _mult_dmg_melee);
        ch.PSendSysMessage("spell damage mult: %.3f", _mult_dmg_spell);
        ch.PSendSysMessage("healing done mult: %.3f", _mult_healing);
        ch.PSendSysMessage("spell power: %i", me->SpellBaseDamageBonusDone(SPELL_SCHOOL_MASK_MAGIC));
        ch.PSendSysMessage("mana regen: %.2f", float(regen_mp) + me->GetFloatValue(UNIT_FIELD_POWER_REGEN_FLAT_MODIFIER) * sWorld->getRate(RATE_POWER_MANA) * 0.001f);
        ch.PSendSysMessage("haste: %s%.2f pct", (haste >= 0 ? "+" : ""), float(haste));
        ch.PSendSysMessage("hit: +%.2f pct", hit);
        ch.PSendSysMessage("expertise: %i (-%.2f pct)", expertise, float(expertise) * 0.25f);
        ch.PSendSysMessage("spell penetration: %u", spellpen);

        for (uint8 i = SPELL_SCHOOL_HOLY; i != MAX_SPELL_SCHOOL; ++i)
        {
            uint32 curresist = me->GetResistance(SpellSchools(i));

            const char* resist = NULL;
            switch (i)
            {
                case 1: resist = "holy";   break;
                case 2: resist = "fire";   break;
                case 3: resist = "nature"; break;
                case 4: resist = "frost";  break;
                case 5: resist = "shadow"; break;
                case 6: resist = "arcane"; break;
            }
            ch.PSendSysMessage("Resistance %s: %u", resist, curresist);
        }
        ch.PSendSysMessage("BotCommandState: %s", m_botCommandState == COMMAND_FOLLOW ? "Follow" : m_botCommandState == COMMAND_ATTACK ? "Attack" : m_botCommandState == COMMAND_STAY ? "Stay" : m_botCommandState == COMMAND_ABANDON ? "Reset" : "none");
        if (!IAmFree())
            ch.PSendSysMessage("Follow distance: %u", master->GetBotFollowDist());

        ch.PSendSysMessage("Boot timer: %i", _bootTimer);

        //debug
        //for (uint32 i = 0; i != 148; ++i)
        //{
        //    float val = me->GetFloatValue(i);
        //    ch.PSendSysMessage("Float value at %u: %.9f", i, val);
        //}

        //ch.PSendSysMessage("healTargetIconFlags: %u", healTargetIconFlags);

        //ch.PSendSysMessage("Roles:");
        //for (uint8 i = BOT_MAX_ROLE; i != BOT_ROLE_NONE; i >>= 1)
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
}
//SetStats
// Health, Armor, Powers, Combat Ratings, and global update setup
void bot_minion_ai::SetStats(bool force, bool shapeshift)
{
    uint8 myclass = _botclass;
    uint8 mylevel = std::min<uint8>(master->getLevel(), 80);
    if (myclass == BOT_CLASS_DRUID && GetBotStance() != BOT_STANCE_NONE)
        myclass = GetBotStance();
    if (myclass != DRUID_BEAR_FORM && myclass != DRUID_CAT_FORM && (master->isDead() || (!shouldUpdateStats && !force)))
        return;
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

    //Do not remove this code under any circumstances! You've been warned.
    if (myclass == BOT_CLASS_DEATH_KNIGHT)
        mylevel = std::max<uint8>(mylevel, 55);

    //LEVEL
    if (me->getLevel() != mylevel)
    {
        me->SetLevel(mylevel);
        //thesawolf - lets add a ding here
        me->HandleEmoteCommand(EMOTE_ONESHOT_CHEER);
        BotYell("DING!", master);        
        force = true; //reinit spells/passives/other
    }
    if (force)
    {
        InitPowers();
        InitSpells(); //this must stay before class passives
        //ApplyPassives(_botclass);
        ApplyClassPassives();
    }

    //PHASE
    if (!IsTempBot() && master->GetPhaseMask() != me->GetPhaseMask())
        me->SetPhaseMask(master->GetPhaseMask(), true);

    //INIT STATS
    //partially receive master's stats and get base class stats, we'll need all this later
    uint8 tempclass = myclass == uint8(DRUID_BEAR_FORM) || myclass == uint8(DRUID_CAT_FORM) ? uint8(BOT_CLASS_DRUID) : myclass;
    if (myclass >= BOT_CLASS_NORMAL_END)
        sObjectMgr->GetPlayerClassLevelInfo(GetPlayerClass(), std::min<uint8>(mylevel, 80), _classinfo);
    else
        sObjectMgr->GetPlayerClassLevelInfo(tempclass, std::min<uint8>(mylevel, 80), _classinfo);
    const CreatureBaseStats* const classstats = sObjectMgr->GetCreatureBaseStats(mylevel, me->getClass()); //use creature class

    if (force)
    {
        PlayerLevelInfo info;
        sObjectMgr->GetPlayerLevelInfo(me->getRace(), GetPlayerClass(), std::min<uint8>(mylevel, 80), &info);
        for (uint8 i = STAT_STRENGTH; i != MAX_STATS; i++)
            me->SetCreateStat(Stats(i), info.stats[i]);
    }

    float value;
    float tempval;

    //INIT CLASS MODIFIERS
    switch (myclass)
    {
        case BOT_CLASS_WARRIOR:      ap_mod = 1.0f; spp_mod = 0.0f; armor_mod = 1.4f;  crit_mod = 1.0f; haste_mod = 0.9f;  dodge_mod = 0.8f; parry_mod = 1.1f;  break;
        case BOT_CLASS_DEATH_KNIGHT: ap_mod = 1.1f; spp_mod = 0.0f; armor_mod = 1.05f; crit_mod = 0.9f; haste_mod = 1.0f;  dodge_mod = 0.7f; parry_mod = 1.25f; break;
        case BOT_CLASS_PALADIN:      ap_mod = 1.3f; spp_mod = 1.2f; armor_mod = 1.2f;  crit_mod = 0.8f; haste_mod = 0.85f; dodge_mod = 0.7f; parry_mod = 1.0f;  break;
        case BOT_CLASS_ROGUE:        ap_mod = 1.3f; spp_mod = 0.3f; armor_mod = 0.9f;  crit_mod = 1.5f; haste_mod = 1.35f; dodge_mod = 1.5f; parry_mod = 0.8f;  break;
        case BOT_CLASS_HUNTER:       ap_mod = 1.4f; spp_mod = 0.5f; armor_mod = 1.2f;  crit_mod = 1.2f; haste_mod = 1.5f;  dodge_mod = 1.1f; parry_mod = 1.15f; break;
        case BOT_CLASS_SHAMAN:       ap_mod = 1.0f; spp_mod = 0.8f; armor_mod = 1.2f;  crit_mod = 1.0f; haste_mod = 1.3f;  dodge_mod = 1.0f; parry_mod = 0.8f;  break;
        case BOT_CLASS_DRUID:        ap_mod = 0.0f; spp_mod = 1.3f; armor_mod = 0.9f;  crit_mod = 0.7f; haste_mod = 1.35f; dodge_mod = 0.5f; parry_mod = 0.0f;  break;
        case BOT_CLASS_MAGE:         ap_mod = 0.0f; spp_mod = 0.9f; armor_mod = 0.7f;  crit_mod = 0.7f; haste_mod = 1.45f; dodge_mod = 0.5f; parry_mod = 0.0f;  break;
        case BOT_CLASS_PRIEST:       ap_mod = 0.0f; spp_mod = 1.2f; armor_mod = 0.7f;  crit_mod = 0.7f; haste_mod = 1.45f; dodge_mod = 0.5f; parry_mod = 0.0f;  break;
        case BOT_CLASS_WARLOCK:      ap_mod = 0.0f; spp_mod = 1.0f; armor_mod = 0.7f;  crit_mod = 0.7f; haste_mod = 1.45f; dodge_mod = 0.5f; parry_mod = 0.0f;  break;
        case DRUID_BEAR_FORM:        ap_mod = 1.2f; spp_mod = 1.0f; armor_mod = 1.85f; crit_mod = 1.0f; haste_mod = 0.75f; dodge_mod = 1.6f; parry_mod = 0.0f;  break;
        case DRUID_CAT_FORM:         ap_mod = 1.5f; spp_mod = 1.0f; armor_mod = 1.2f;  crit_mod = 1.5f; haste_mod = 2.25f; dodge_mod = 1.4f; parry_mod = 0.0f;  break;

        case BOT_CLASS_BM:           ap_mod = 2.5f; spp_mod = 0.0f; armor_mod = 0.8f;  crit_mod = 0.0f; haste_mod = 2.50f; dodge_mod = 0.0f; parry_mod = 0.0f;  break;

        default:
            TC_LOG_ERROR("entities.player", "minion_ai: *etStats():Init - unknown bot class %u, real class: %u, _botclass: %u", myclass, GetPlayerClass(), _botclass);
            ap_mod = 0.0f; spp_mod = 0.0f; armor_mod = 0.0f;  crit_mod = 0.0f; haste_mod = 0.0f; dodge_mod = 0.0f;  parry_mod = 0.0f;  break;
    }

    //DAMAGE
    _OnMeleeDamageUpdate(myclass);

    //ARMOR
    value = IAmFree() ? classstats->BaseArmor : me->getLevel() * 25; //over9000/2000 at 80
    value += 2.f * (me->GetTotalStatValue(STAT_AGILITY) - 18 + _getTotalBotStat(BOT_ITEM_MOD_AGILITY));
    value += _getTotalBotStat(BOT_ITEM_MOD_ARMOR);

    //class-specified
    if (GetBotStance() == DEATH_KNIGHT_FROST_PRESENCE)
        armor_mod += 0.6f;
    if (GetPlayerClass() == BOT_CLASS_DRUID)
    {
        armor_mod += 0.1f;
        if (myclass == DRUID_BEAR_FORM)
            armor_mod += 0.33f;
    }

    value *= armor_mod;
    me->SetStatFlatModifier(UNIT_MOD_ARMOR, BASE_VALUE, value);
    me->UpdateArmor(); //buffs will be took in consideration here

    //RESISTANCES
    for (uint8 i = SPELL_SCHOOL_HOLY; i != MAX_SPELL_SCHOOL; ++i)
    {
        value = IAmFree() ? mylevel + 40 : std::max<int8>(int8(mylevel) - 20, 0);
        value += _getTotalBotStat(BOT_ITEM_MOD_RESIST_HOLY + (i - 1));
        me->SetStatFlatModifier(UnitMods(UNIT_MOD_RESISTANCE_START + i), BASE_VALUE, value);
        me->UpdateResistances(i);
    }

    //DAMAGE TAKEN
    value = IAmFree() ? 0.65f : 1.f;
    if (mylevel > 77)
        value -= ((mylevel - 77) * 0.05f); // +15% dmg reduction at 80

    //class-specified
    //Protector of the Pack
    if (mylevel >= 45 && myclass == DRUID_BEAR_FORM)
        value -= 0.12f;

    dmg_taken = value;

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

    value = std::max<int32>(int32(mylevel) - (IAmFree() ? 60 : 75), 0); //+20%/+5% haste at 80

    //25.5 HR = 1% haste at 80
    tempval = _getTotalBotStat(BOT_ITEM_MOD_HASTE_MELEE_RATING) + _getTotalBotStat(BOT_ITEM_MOD_HASTE_RANGED_RATING) + _getTotalBotStat(BOT_ITEM_MOD_HASTE_SPELL_RATING) + _getTotalBotStat(BOT_ITEM_MOD_HASTE_RATING);
    tempval += me->GetTotalAuraModifierByMiscMask(SPELL_AURA_MOD_RATING, (1 << CR_HASTE_MELEE) | (1 << CR_HASTE_RANGED) | (1 << CR_HASTE_SPELL));
    value += tempval * (myclass == BOT_CLASS_HUNTER ? _getRatingMultiplier(CR_HASTE_RANGED) : std::max<float>(_getRatingMultiplier(CR_HASTE_MELEE), _getRatingMultiplier(CR_HASTE_SPELL)));
    //value += (tempval / (25.5f * (mylevel < 11 ? 1.125f : mylevel - 5) / 75.f));
    //value += (tempval / (25.5f * (float(mylevel - 5) / 75.f)));

    value *= haste_mod;

    if (myclass == DRUID_CAT_FORM) //give cat lots of haste
        value += (mylevel/16) * 10.f; //or (mylevel/16) (+40...50% haste for cat);
    if (myclass == CLASS_HUNTER)
        value += 15.f; //ammo pouch haste bonus 15% for hunters (still applies to all haste types)

    haste = int32(value);

    if (haste)
    {
        //apply new haste
        for (uint8 att = BASE_ATTACK; att != MAX_ATTACK; ++att)
            me->ApplyAttackTimePercentMod(WeaponAttackType(att), float(haste), true);
        me->ApplyCastTimePercentMod(float(haste), true);
    }

    //HIT
    value = IAmFree() ? mylevel / 8 : mylevel / 16; // 10%/5% at 80

    //32.5 HR = 1% hit at 80
    tempval = _getTotalBotStat(BOT_ITEM_MOD_HIT_MELEE_RATING) + _getTotalBotStat(BOT_ITEM_MOD_HIT_RANGED_RATING) + _getTotalBotStat(BOT_ITEM_MOD_HIT_SPELL_RATING) + _getTotalBotStat(BOT_ITEM_MOD_HIT_RATING);
    tempval += me->GetTotalAuraModifierByMiscMask(SPELL_AURA_MOD_RATING, (1 << CR_HIT_MELEE) | (1 << CR_HIT_RANGED) | (1 << CR_HIT_SPELL));
    value += tempval * (myclass == BOT_CLASS_HUNTER ? _getRatingMultiplier(CR_HIT_RANGED) : std::max<float>(_getRatingMultiplier(CR_HIT_MELEE), _getRatingMultiplier(CR_HIT_SPELL)));
    //value += (tempval / (32.5f * (mylevel < 11 ? 0.72f : mylevel - 8) / 72.f));
    //value += (tempval / (32.5f * (float(mylevel - 5) / 75.f)));

    hit = value;

    //EXPERTISE
    if (IsMelee())
    {
        value = IAmFree() ? mylevel / 2 : mylevel / 20; //-10%/-1% dodge/parry at 80

        //~8.0 ER = 1 expertise at 80
        tempval = _getTotalBotStat(BOT_ITEM_MOD_EXPERTISE_RATING);
        tempval += me->GetTotalAuraModifierByMiscMask(SPELL_AURA_MOD_RATING, (1 << CR_EXPERTISE));
        value += tempval * _getRatingMultiplier(CR_EXPERTISE);
        //value += (tempval / (8.0f * (mylevel < 11 ? 0.9f : mylevel - 8) / 72.f));
        //value += (tempval / (8.0f * (float(mylevel - 5) / 75.f)));

        expertise = value;
    }

    //CRIT
    if (crit_mod > 0.0f)
    {
        value = IAmFree() ? mylevel / 4 : mylevel / 16; //+20%/+5% at 80

        if (GtChanceToMeleeCritEntry const* critRatio = sGtChanceToMeleeCritStore.LookupEntry((GetPlayerClass()-1)*GT_MAX_LEVEL + mylevel-1))
            value += (me->GetTotalStatValue(STAT_AGILITY) - 18 + _getTotalBotStat(BOT_ITEM_MOD_AGILITY)) * critRatio->ratio * 100.0f;

        //crit from intellect
        if (GtChanceToSpellCritEntry const* critRatio = sGtChanceToSpellCritStore.LookupEntry((GetPlayerClass()-1)*GT_MAX_LEVEL + mylevel-1))
            value += (me->GetTotalStatValue(STAT_INTELLECT) - 18 + _getTotalBotStat(BOT_ITEM_MOD_INTELLECT)) * critRatio->ratio * 100.f;

        //45 CR = 1% crit at 80
        float tempval = _getTotalBotStat(BOT_ITEM_MOD_CRIT_MELEE_RATING) + _getTotalBotStat(BOT_ITEM_MOD_CRIT_RANGED_RATING) + _getTotalBotStat(BOT_ITEM_MOD_CRIT_SPELL_RATING) + _getTotalBotStat(BOT_ITEM_MOD_CRIT_RATING);
        tempval += me->GetTotalAuraModifierByMiscMask(SPELL_AURA_MOD_RATING, (1 << CR_CRIT_MELEE) | (1 << CR_CRIT_RANGED) | (1 << CR_CRIT_SPELL));
        value += tempval * (myclass == BOT_CLASS_HUNTER ? _getRatingMultiplier(CR_CRIT_RANGED) : std::max<float>(_getRatingMultiplier(CR_CRIT_MELEE), _getRatingMultiplier(CR_CRIT_SPELL)));
        //value += (tempval / (45.f * (mylevel < 11 ? 0.8f : mylevel - 8) / 72.f));
        //value += (tempval / (45.f * (float(mylevel - 5) / 75.f)));

        crit = value * crit_mod;
    }

    //PARRY
    if (parry_mod > 0.0f)
    {
        value = 5.0f + (IAmFree() ? mylevel / 8 : mylevel / 16); //+10%/+5% at 80

        if (mylevel >= 10)
        {
            //67 PR = 1% parry at 80
            float tempval = _getTotalBotStat(BOT_ITEM_MOD_PARRY_RATING);
            tempval += me->GetTotalAuraModifierByMiscMask(SPELL_AURA_MOD_RATING, (1 << CR_PARRY));
            value += tempval * _getRatingMultiplier(CR_PARRY);
            //value += (tempval / (67.f * (mylevel < 35 ? 5.5f : mylevel - 25) / 55.f));
            //value += (tempval / (67.f * (float(mylevel - 5) / 75.f)));
            //125 DR = 1% block/parry/dodge at 80
            tempval = _getTotalBotStat(BOT_ITEM_MOD_DEFENSE_SKILL_RATING);
            tempval += me->GetTotalAuraModifierByMiscMask(SPELL_AURA_MOD_RATING, (1 << CR_DEFENSE_SKILL));
            value += tempval * _getRatingMultiplier(CR_DEFENSE_SKILL) * 0.04f;
            value += me->GetTotalAuraModifierByMiscValue(SPELL_AURA_MOD_SKILL, SKILL_DEFENSE) * 0.04f;
            //value += (tempval / (125.f * (mylevel < 35 ? 8.25f : mylevel - 25) / 55.f));
            //value += (tempval / (125.f * (float(mylevel - 5) / 75.f)));
        }

        //if (IsTank()) //tanking bonus
        //    value += 5.f;

        //Forceful Deflection: 25% of strength goes to parry rating (~1% parry per 67 rating at 80)
        if (myclass == BOT_CLASS_DEATH_KNIGHT/* && mylevel >= 55*/)
            value += ((me->GetTotalStatValue(STAT_STRENGTH) - 18 + _getTotalBotStat(BOT_ITEM_MOD_STRENGTH)) / 4.f) / (float(mylevel) - (13.f / (float(mylevel - 40) / 40.f))); //~20 at 55, ~34 at 60 and 67 at 80

        parry = value * parry_mod;
    }

    //DODGE
    if (dodge_mod > 0.0f)
    {
        value = 5.0f + (IAmFree() ? mylevel / 8 : mylevel / 16); //+10%/+5% at 80

        if (GtChanceToMeleeCritEntry  const* dodgeRatio = sGtChanceToMeleeCritStore.LookupEntry((GetPlayerClass()-1)*GT_MAX_LEVEL + mylevel-1))
            value += (me->GetTotalStatValue(STAT_AGILITY) - 18 + _getTotalBotStat(BOT_ITEM_MOD_AGILITY)) * dodgeRatio->ratio * 100.0f;

        if (mylevel >= 10)
        {
            //53 DR = 1% dodge at 80
            float tempval = _getTotalBotStat(BOT_ITEM_MOD_DODGE_RATING);
            tempval += me->GetTotalAuraModifierByMiscMask(SPELL_AURA_MOD_RATING, (1 << CR_DODGE));
            value += tempval * _getRatingMultiplier(CR_DODGE);
            //value += (tempval / (53.f * (mylevel < 35 ? 7.15f : mylevel - 25) / 55.f));
            //value += (tempval / (53.f * (float(mylevel - 5) / 75.f)));
            //125 DR = 1% block/parry/dodge at 80
            tempval = _getTotalBotStat(BOT_ITEM_MOD_DEFENSE_SKILL_RATING);
            tempval += me->GetTotalAuraModifierByMiscMask(SPELL_AURA_MOD_RATING, (1 << CR_DEFENSE_SKILL));
            value += tempval * _getRatingMultiplier(CR_DEFENSE_SKILL) * 0.04f;
            value += me->GetTotalAuraModifierByMiscValue(SPELL_AURA_MOD_SKILL, SKILL_DEFENSE) * 0.04f;
            //value += (tempval / (125.f * (mylevel < 35 ? 8.25f : mylevel - 25) / 55.f));
            //value += (tempval / (125.f * (float(mylevel - 5) / 75.f)));
        }

        //if (IsTank())
        //    value += 5.f;

        dodge = value * dodge_mod;
    }

    //BLOCK
    if (!(me->GetCreatureTemplate()->flags_extra & CREATURE_FLAG_EXTRA_NO_BLOCK))
    {
        value = 5.0f + (IAmFree() ? mylevel / 4 : mylevel/ 16); //+20%/+5% at 80

        if (mylevel >= 10)
        {
            //16.5 BR = 1% block at 80
            float tempval = _getTotalBotStat(BOT_ITEM_MOD_BLOCK_RATING);
            tempval += me->GetTotalAuraModifierByMiscMask(SPELL_AURA_MOD_RATING, (1 << CR_BLOCK));
            value += tempval * _getRatingMultiplier(CR_BLOCK);
            //value += (tempval / (16.5f * (mylevel < 35 ? 8.25f : mylevel - 25) / 55.f));
            //value += (tempval / (16.5f * (float(mylevel - 5) / 75.f)));
            //125 DR = 1% block/parry/dodge at 80
            tempval = _getTotalBotStat(BOT_ITEM_MOD_DEFENSE_SKILL_RATING);
            tempval += me->GetTotalAuraModifierByMiscMask(SPELL_AURA_MOD_RATING, (1 << CR_DEFENSE_SKILL));
            value += tempval * _getRatingMultiplier(CR_DEFENSE_SKILL) * 0.04f;
            value += me->GetTotalAuraModifierByMiscValue(SPELL_AURA_MOD_SKILL, SKILL_DEFENSE) * 0.04f;
            //value += (tempval / (125.f * (mylevel < 35 ? 8.25f : mylevel - 25) / 55.f));
            //value += (tempval / (125.f * (float(mylevel - 5) / 75.f)));

            value += IsTank() * 10; //tank bonus
        }

        block = std::min<float>(value, 75.0f);

        //BLOCK VALUE
        value = float(mylevel + (mylevel >> 2)); //100 at 80
        value += 0.5f * (me->GetTotalStatValue(STAT_STRENGTH) - 18);
        value += 0.5f *_getTotalBotStat(BOT_ITEM_MOD_STRENGTH);
        value += _getTotalBotStat(BOT_ITEM_MOD_BLOCK_VALUE);

        //Shield Mastery
        if (mylevel >= 20 && myclass == BOT_CLASS_WARRIOR)
            value *= 1.3f;
        //Redoubt
        if (mylevel >= 45 && myclass == BOT_CLASS_PALADIN)
            value *= 1.3f;

        blockvalue = std::max<int32>(int32(value) - 10, 1);
    }

    //MANA
    _OnManaUpdate(shapeshift);

    //MANA REGEN
    if (me->GetMaxPower(POWER_MANA) > 1)
    {
        value = IAmFree() ? mylevel * 5 : 0; //400/0 at 80
        value += _getTotalBotStat(BOT_ITEM_MOD_MANA_REGENERATION);
        //regen from spirit: 15 base, 1 per 5 spirit
        value += 15.f + 0.2f * (me->GetTotalStatValue(STAT_SPIRIT) - 18 + _getTotalBotStat(BOT_ITEM_MOD_SPIRIT));
        //hunters just spend all mana in no time
        //if (myclass == BOT_CLASS_HUNTER && mylevel > 20)
        //    value += float((mylevel - 20) * 5); //300
        if (myclass >= BOT_CLASS_EX_START)
        {
            if (myclass == BOT_CLASS_BM)
                value = std::max<float>(value / 20, 1); //0.2 per sec
        }

        //regen from intellect: 1 int = 0.01 mana per second = 0.05 mp5
        value += 0.05f * (me->GetTotalStatValue(STAT_INTELLECT) - 18 + _getTotalBotStat(BOT_ITEM_MOD_INTELLECT));

        regen_mp = uint32(value);
    }

    //SPELL PENETRATION
    value = IAmFree() ? mylevel : std::max<int32>((int8(mylevel) - 20), 0) / 3; //80/20 at 80
    //~1 SPPR = 1 spell penetration
    value += _getTotalBotStat(BOT_ITEM_MOD_SPELL_PENETRATION);
    spellpen = uint32(value);

    //SPELL POWER
    if (spp_mod > 0.f)
    {
        value = IAmFree() ? std::max<int32>((int8(mylevel) - 30) * 80, 0) : std::max<int32>((int8(mylevel) - 30) * 3, 0); //+4000spp/+150spp at 80
        value += _getTotalBotStat(BOT_ITEM_MOD_SPELL_POWER);

        //class-specified mods
        if (myclass == BOT_CLASS_PALADIN && mylevel >= 50)
        {
            //Touched by the Light / Sheath of Light - 60% of strength (30% attack power) to spell power
            if (HasRole(BOT_ROLE_TANK | BOT_ROLE_DPS))
                value += 0.3f * me->GetTotalAttackPowerValue(BASE_ATTACK);
            //Holy Guidance - 20% Intellect to spell power
            else if (HasRole(BOT_ROLE_HEAL))
                value += 0.2f * me->GetTotalStatValue(STAT_INTELLECT);
        }
        if (myclass == BOT_CLASS_PRIEST && mylevel >= 55)
        {
            //Spiritual Guidance - 25% Spirit to spell power
            if (HasRole(BOT_ROLE_HEAL))
                value += 0.25f * me->GetTotalStatValue(STAT_SPIRIT);
            //Twisted Faith - 20% Spirit to spell power
            else if (HasRole(BOT_ROLE_DPS))
                value += 0.2f * me->GetTotalStatValue(STAT_SPIRIT);
        }
        if (myclass == BOT_CLASS_SHAMAN && mylevel >= 50)
        {
            //Mental Quickness - 30% attack power to spell power (only enhancement)
            if (HasRole(BOT_ROLE_DPS) && !HasRole(BOT_ROLE_RANGED))
                value += 0.3f * me->GetTotalAttackPowerValue(BASE_ATTACK);
        }
        if (myclass == BOT_CLASS_DRUID && mylevel >= 30)
        {
            //Lunar Guidance - 12% Intellect to spell power (balance and resto possible)
            if (HasRole(BOT_ROLE_DPS | BOT_ROLE_HEAL))
                value += 0.12f * me->GetTotalStatValue(STAT_INTELLECT);
        }
        if (myclass == BOT_CLASS_MAGE && mylevel >= 45)
        {
            //Mind Mastery - 15% Intellect to spell power
            //if (HasRole(BOT_ROLE_DPS))
                value += 0.15f * me->GetTotalStatValue(STAT_INTELLECT);
        }

        spellpower = uint32(value * spp_mod);
    }

    //if init
    if (force)
    {
        me->SetFullHealth();
        me->SetPower(POWER_MANA, me->GetMaxPower(POWER_MANA));
    }

    //SetStats for pet
    if (Creature* pet = me->GetBotsPet())
        if (bot_pet_ai* petai = pet->GetBotPetAI())
            petai->SetStats(force);

    shouldUpdateStats = false;
}

void bot_pet_ai::SetStats(bool force, bool /*unk*/)
{
    uint8 mylevel = m_creatureOwner->getLevel();
    uint8 petType = GetPetType(me);
    if (petType == PET_TYPE_NONE || petType >= MAX_PET_TYPES) return;
    if (!shouldUpdateStats && !force) return;
    //TC_LOG_ERROR("entities.player", "*etStats(): Updating pet bot %s, type: %u, level %u, owner: %s, master: %s", me->GetName().c_str(), petType, mylevel, m_creatureOwner->GetName().c_str(), master->GetName().c_str());

    //LEVEL
    if (me->getLevel() != mylevel)
    {
        me->SetLevel(mylevel);
        force = true; //restore powers on lvl update
    }
    if (force)
    {
        InitPowers();
        InitSpells();
        //ApplyPassives(_botclass);
        ApplyClassPassives();
    }

    //PHASE
    if (master->GetPhaseMask() != me->GetPhaseMask())
        me->SetPhaseMask(master->GetPhaseMask(), true);

    ////INIT STATS
    if (force)
        for (uint8 i = STAT_STRENGTH; i != MAX_STATS; i++)
            me->SetCreateStat(Stats(i), 0.5f * m_creatureOwner->GetCreateStat(Stats(i)));

    //INIT CLASS MODIFIERS
    //STAT -- 'mod' -- used stat values to apply
    //WARLOCK
    //Stamina x0.3  -- health
    //Armor   x0.35 -- armor
    //Int     x0.3  -- crit/mana
    //Spd     x0.15 -- spd (if has mana)
    //AP      x0.57 -- attack power (if melee pet)
    //Resist  x0.4  -- resistances
    //MAGE
    //
    //SHAMAN
    //
    //HUNTER
    //

    switch (petType)
    {
        case PET_TYPE_VOIDWALKER:       ap_mod = 0.57f; spp_mod = 0.15f; crit_mod = 1.0f; break;
        //case PET_TYPE_FELHUNTER:        ap_mod = 0.57f; spp_mod = 0.15f; crit_mod = 1.0f; break;//NYI
        //case PET_TYPE_FELGUARD:         ap_mod = 0.57f; spp_mod = 0.15f; crit_mod = 1.0f; break;//NYI
        //case PET_TYPE_SUCCUBUS:         ap_mod = 0.57f; spp_mod = 0.15f; crit_mod = 1.0f; break;//NYI
        case PET_TYPE_IMP:              ap_mod = 0.f;   spp_mod = 0.15f; crit_mod = 1.0f; break;

        //case PET_TYPE_WATER_ELEMENTAL:  ap_mod = 0.0f;  spp_mod = 0.0f; crit_mod = 0.0f; break;//NYI

        //case PET_TYPE_FIRE_ELEMENTAL:   ap_mod = 0.0f;  spp_mod = 0.0f; crit_mod = 0.0f; break;//NYI
        //case PET_TYPE_EARTH_ELEMENTAL:  ap_mod = 0.0f;  spp_mod = 0.0f; crit_mod = 0.0f; break;//NYI

        //case PET_TYPE_VULTURE:          ap_mod = 0.9f;  spp_mod = 1.0f; crit_mod = 1.2f; break;//NYI
        default:
            TC_LOG_ERROR("entities.player", "pet_ai: *etStats():Init - unknown pet type %u", petType);
            ap_mod = 0.0f;  spp_mod = 0.0f; crit_mod = 0.0f; break;
    }

    //DAMAGE
    if (ap_mod > 0.f)//do not bother casters
    {
        switch (m_creatureOwner->GetBotClass())
        {
            case BOT_CLASS_WARLOCK:
                value = float(m_creatureOwner->GetBotAI()->GetBotSpellPower());
                break;
            case BOT_CLASS_DEATH_KNIGHT:
                value = m_creatureOwner->GetTotalAttackPowerValue(BASE_ATTACK);
                break;
            case BOT_CLASS_HUNTER:
                value = m_creatureOwner->GetTotalAttackPowerValue(RANGED_ATTACK);
                break;
            default: //some weird class or NYI
                TC_LOG_ERROR("entities.player", "*etStats():Damage - unknown bot owner class %u", uint8(m_creatureOwner->GetBotClass()));
                value = 0.0f;
                break;
        }

        me->SetStatFlatModifier(UNIT_MOD_STAT_STRENGTH, BASE_VALUE, me->GetCreateStat(STAT_STRENGTH) - 9.f);
        atpower = (me->GetTotalAuraModValue(UNIT_MOD_STAT_STRENGTH) * 2.f + value) * ap_mod;
        me->SetStatFlatModifier(UNIT_MOD_ATTACK_POWER, BASE_VALUE, atpower);
        me->UpdateAttackPowerAndDamage();
    }

    //ARMOR
    value = float(basearmor);
    //get minion's armor and give 35% to pet (just as for real pets)
    value += m_creatureOwner->GetFlatModifierValue(UNIT_MOD_ARMOR, BASE_VALUE) * 0.35f;
    me->SetStatFlatModifier(UNIT_MOD_ARMOR, BASE_VALUE, value);
    me->UpdateArmor();

    //RESISTANCES
    //based on minion's resistances gain x0.4
    for (uint8 i = SPELL_SCHOOL_HOLY; i != MAX_SPELL_SCHOOL; ++i)
    {
        value = float(m_creatureOwner->GetResistance(SpellSchools(i)));
        me->SetStatFlatModifier(UnitMods(UNIT_MOD_RESISTANCE_START + i), BASE_VALUE, 0.4f * value);
        me->UpdateResistances(i);
    }

    //DAMAGE TAKEN
    dmg_taken = m_creatureOwner->GetBotAI()->GetBotDamageTakenMod();

    //HEALTH
    _OnHealthUpdate();

    //HASTE
    if (haste)
    {
        for (uint8 att = BASE_ATTACK; att != MAX_ATTACK; ++att)
            me->ApplyAttackTimePercentMod(WeaponAttackType(att), float(haste), false);
        me->ApplyCastTimePercentMod(float(haste), false);
    }

    haste = m_creatureOwner->GetBotAI()->GetHaste();

    if (haste)
    {
        for (uint8 att = BASE_ATTACK; att != MAX_ATTACK; ++att)
            me->ApplyAttackTimePercentMod(WeaponAttackType(att), float(haste), true);
        me->ApplyCastTimePercentMod(float(haste), true);
    }

    //HIT
    hit = m_creatureOwner->GetBotAI()->GetHitRating();

    //CRIT
    if (CanCrit())
    {
        value = m_creatureOwner->GetUnitCriticalChance((BASE_ATTACK), me);
        crit = value * crit_mod;
    }

    //PARRY
    if (CanParry())
    {
        value = m_creatureOwner->GetUnitParryChance(BASE_ATTACK, me);
        parry = value;
    }

    //DODGE
    if (CanDodge())
    {
        value = m_creatureOwner->GetUnitDodgeChance(BASE_ATTACK, me);
        value += IsTank() * 10;
        dodge = value;
    }

    //MANA
    _OnManaUpdate(false);

    //MANA REGEN
    regen_mp = m_creatureOwner->GetBotAI()->GetManaRegen();

    //SPELL PENETRATION
    spellpen = m_creatureOwner->GetBotAI()->GetBotSpellPenetration();

    //SPELL POWER
    if (spp_mod > 0.f)
    {
        switch (m_creatureOwner->GetBotClass())
        {
            case BOT_CLASS_WARLOCK:
                value = m_creatureOwner->GetBotAI()->GetBotSpellPower();
                break;
            case BOT_CLASS_DEATH_KNIGHT:
                value = m_creatureOwner->GetTotalAttackPowerValue(BASE_ATTACK);
                break;
            case BOT_CLASS_HUNTER:
                value = m_creatureOwner->GetTotalAttackPowerValue(RANGED_ATTACK);
                break;
            default: //some weird class or NYI
                TC_LOG_ERROR("entities.player", "*etStats():Spellpower - unknown bot owner class %u", uint8(m_creatureOwner->GetBotClass()));
                value = 0.f;
                break;
        }

        spellpower = uint32(value * spp_mod);
    }

    if (force)
    {
        me->SetFullHealth();
        me->SetPower(POWER_MANA, me->GetMaxPower(POWER_MANA));
    }

    shouldUpdateStats = false;
}
//Emotion-based action
void bot_ai::ReceiveEmote(Player* player, uint32 emote)
{
    // thesawolf - lets clear any running emotes first
    me->HandleEmoteCommand(EMOTE_ONESHOT_NONE);
    switch (emote)
    {
        // thesawolf - lets make the AI more personable
        case TEXT_EMOTE_BONK:
            me->HandleEmoteCommand(EMOTE_ONESHOT_CRY);
            _listAuras(player, me);
            break;
        case TEXT_EMOTE_SALUTE:
            me->HandleEmoteCommand(EMOTE_ONESHOT_SALUTE);
            _listAuras(player, player);
            break;
        case TEXT_EMOTE_WAIT:
            if (!IsMinionAI())
                return;
            if (master != player)
            {
                me->HandleEmoteCommand(EMOTE_ONESHOT_RUDE);
                return;
            }
            SetBotCommandState(COMMAND_STAY);
            BotWhisper("Fine.. I'll stay right here..", player);
            break;
        case TEXT_EMOTE_BECKON:
        case TEXT_EMOTE_FOLLOW:
            if (!IsMinionAI())
                return;
            if (master != player)
            {
                me->HandleEmoteCommand(EMOTE_ONESHOT_RUDE);
                return;
            }
            SetBotCommandState(COMMAND_FOLLOW, true);
            BotWhisper("Wherever you go, I'll follow..", player);
            break;
        case TEXT_EMOTE_WAVE:
        case TEXT_EMOTE_GREET:
        case TEXT_EMOTE_HAIL:
        case TEXT_EMOTE_HELLO:
        case TEXT_EMOTE_WELCOME:
        case TEXT_EMOTE_INTRODUCE:
            me->HandleEmoteCommand(EMOTE_ONESHOT_WAVE);
            BotSay("Hey there!", player);
            break;
        case TEXT_EMOTE_DANCE:
            me->HandleEmoteCommand(EMOTE_ONESHOT_DANCE);
            BotSay("Shake what your mama gave you!", player);
            break;
        case TEXT_EMOTE_FLIRT:
        case TEXT_EMOTE_KISS:
        case TEXT_EMOTE_HUG:
        case TEXT_EMOTE_BLUSH:
        case TEXT_EMOTE_SMILE:
        case TEXT_EMOTE_LOVE:
        case TEXT_EMOTE_HOLDHAND:
            me->HandleEmoteCommand(EMOTE_ONESHOT_SHY);
            BotSay("Awwwww...", player);
            break;
        case TEXT_EMOTE_FLEX:
            me->HandleEmoteCommand(EMOTE_ONESHOT_APPLAUD);
            BotSay("Hercules! Hercules!", player);
            break;
        case TEXT_EMOTE_ANGRY:
        case TEXT_EMOTE_FACEPALM:
        case TEXT_EMOTE_GLARE:
        case TEXT_EMOTE_BLAME:
        case TEXT_EMOTE_FAIL:
        case TEXT_EMOTE_REGRET:
        case TEXT_EMOTE_SCOLD:
        case TEXT_EMOTE_CROSSARMS:
            me->HandleEmoteCommand(EMOTE_ONESHOT_QUESTION);
            BotSay("Did I do thaaaaat?", player);
            break;
        case TEXT_EMOTE_FART:
        case TEXT_EMOTE_BURP:
        case TEXT_EMOTE_GASP:
        case TEXT_EMOTE_NOSEPICK:
        case TEXT_EMOTE_SNIFF:
        case TEXT_EMOTE_STINK:
            me->HandleEmoteCommand(EMOTE_ONESHOT_POINT);
            BotSay("Wasn't me! Just sayin'..", player);
            break;
        case TEXT_EMOTE_JOKE:
            me->HandleEmoteCommand(EMOTE_ONESHOT_LAUGH);
            BotSay("Oh.. was I not supposed to laugh so soon?", player);
            break;
        case TEXT_EMOTE_CHICKEN:
            me->HandleEmoteCommand(EMOTE_ONESHOT_RUDE);
            BotSay("We'll see who's chicken soon enough!", player);
            break;
        case TEXT_EMOTE_APOLOGIZE:
            me->HandleEmoteCommand(EMOTE_ONESHOT_POINT); 
            BotSay("You damn right you're sorry!", player);
            break;
        case TEXT_EMOTE_APPLAUD:
        case TEXT_EMOTE_CLAP:
        case TEXT_EMOTE_CONGRATULATE:
        case TEXT_EMOTE_HAPPY:
        case TEXT_EMOTE_GOLFCLAP:
            me->HandleEmoteCommand(EMOTE_ONESHOT_BOW);
            BotSay("Thank you.. Thank you.. I'm here all week.", player);
            break;
        case TEXT_EMOTE_BEG:
        case TEXT_EMOTE_GROVEL:
        case TEXT_EMOTE_PLEAD:
            me->HandleEmoteCommand(EMOTE_ONESHOT_NO);
            BotSay("Beg all you want.. I have nothing for you.", player);
            break;
        case TEXT_EMOTE_BITE:
        case TEXT_EMOTE_POKE:
        case TEXT_EMOTE_SCRATCH:
        case TEXT_EMOTE_PINCH:
        case TEXT_EMOTE_PUNCH:
            me->HandleEmoteCommand(EMOTE_ONESHOT_ROAR);
            BotYell("OUCH! Dammit, that hurt!", player);
            break;
        case TEXT_EMOTE_BORED:
            me->HandleEmoteCommand(EMOTE_ONESHOT_NO); 
            BotSay("My job description doesn't include entertaining you..", player);
            break;
        case TEXT_EMOTE_BOW:
        case TEXT_EMOTE_CURTSEY:
            me->HandleEmoteCommand(EMOTE_ONESHOT_BOW);
            break;
        case TEXT_EMOTE_BRB:
        case TEXT_EMOTE_SIT:
            //me->HandleEmoteCommand(EMOTE_STATE_SIT); // replace if state doesn't break
            me->HandleEmoteCommand(EMOTE_ONESHOT_EAT);
            BotSay("Looks like time for an AFK break..", player);
            break;
        case TEXT_EMOTE_AGREE:
        case TEXT_EMOTE_NOD:
            me->HandleEmoteCommand(EMOTE_ONESHOT_EXCLAMATION);
            BotSay("At least SOMEONE agrees with me!", player);
            break;
        case TEXT_EMOTE_AMAZE:
        case TEXT_EMOTE_COWER:
        case TEXT_EMOTE_CRINGE:
        case TEXT_EMOTE_EYE:
        case TEXT_EMOTE_KNEEL:
        case TEXT_EMOTE_PEER:
        case TEXT_EMOTE_SURRENDER:
        case TEXT_EMOTE_PRAISE:
        case TEXT_EMOTE_SCARED:
        case TEXT_EMOTE_COMMEND:
        case TEXT_EMOTE_AWE:
        case TEXT_EMOTE_JEALOUS:
        case TEXT_EMOTE_PROUD:
            me->HandleEmoteCommand(EMOTE_ONESHOT_FLEX);
            BotSay("Yes, Yes. I know I'm amazing..", player);
            break;
        case TEXT_EMOTE_BLEED:
        case TEXT_EMOTE_MOURN:
        case TEXT_EMOTE_FLOP:
        case TEXT_EMOTE_FAINT:
        case TEXT_EMOTE_PULSE:
            me->HandleEmoteCommand(EMOTE_ONESHOT_KNEEL);
            BotYell("MEDIC! Stat!", player);
            break;
        case TEXT_EMOTE_BLINK:
            me->HandleEmoteCommand(EMOTE_ONESHOT_KICK);
            BotSay("What? You got something in your eye?", player);
            break;
        case TEXT_EMOTE_BOUNCE:
        case TEXT_EMOTE_BARK:
            me->HandleEmoteCommand(EMOTE_ONESHOT_POINT);
            BotSay("Who's a good doggy? You're a good doggy!", player);
            break;
        case TEXT_EMOTE_BYE:
            me->HandleEmoteCommand(EMOTE_ONESHOT_WAVE);
            BotSay("Umm.... wait! Where are you going?!", player);
            break;
        case TEXT_EMOTE_CACKLE:
        case TEXT_EMOTE_LAUGH:
        case TEXT_EMOTE_CHUCKLE:
        case TEXT_EMOTE_GIGGLE:
        case TEXT_EMOTE_GUFFAW:
        case TEXT_EMOTE_ROFL:
        case TEXT_EMOTE_SNICKER:
        case TEXT_EMOTE_SNORT:
            me->HandleEmoteCommand(EMOTE_ONESHOT_LAUGH);
            BotSay("Wait... what are we laughing at again?", player);
            break;
        case TEXT_EMOTE_CONFUSED:
        case TEXT_EMOTE_CURIOUS:
        case TEXT_EMOTE_FIDGET:
        case TEXT_EMOTE_FROWN:
        case TEXT_EMOTE_SHRUG:
        case TEXT_EMOTE_SIGH:
        case TEXT_EMOTE_STARE:
        case TEXT_EMOTE_TAP:
        case TEXT_EMOTE_SURPRISED:
        case TEXT_EMOTE_WHINE:
        case TEXT_EMOTE_BOGGLE:
        case TEXT_EMOTE_LOST:
        case TEXT_EMOTE_PONDER:
        case TEXT_EMOTE_SNUB:
        case TEXT_EMOTE_SERIOUS:
        case TEXT_EMOTE_EYEBROW:
            me->HandleEmoteCommand(EMOTE_ONESHOT_QUESTION);
            BotSay("Don't look at  me.. I just work here", player);
            break;
        case TEXT_EMOTE_COUGH:
        case TEXT_EMOTE_DROOL:
        case TEXT_EMOTE_SPIT:
        case TEXT_EMOTE_LICK:
        case TEXT_EMOTE_BREATH:
        case TEXT_EMOTE_SNEEZE:
        case TEXT_EMOTE_SWEAT:
            me->HandleEmoteCommand(EMOTE_ONESHOT_POINT);
            BotSay("Ewww! Keep your nasty germs over there!", player);
            break;
        case TEXT_EMOTE_CRY:
            me->HandleEmoteCommand(EMOTE_ONESHOT_CRY);
            BotSay("Don't you start crying or it'll make me start crying!", player);
            break;
        case TEXT_EMOTE_CRACK:
            me->HandleEmoteCommand(EMOTE_ONESHOT_ROAR);
            BotSay("It's clobbering time!", player);
            break;
        case TEXT_EMOTE_EAT:
        case TEXT_EMOTE_DRINK:
            me->HandleEmoteCommand(EMOTE_ONESHOT_EAT);
            BotSay("I hope you brought enough for the whole class...", player);
            break;
        case TEXT_EMOTE_GLOAT:
        case TEXT_EMOTE_MOCK:
        case TEXT_EMOTE_TEASE:
        case TEXT_EMOTE_EMBARRASS:
            me->HandleEmoteCommand(EMOTE_ONESHOT_CRY);
            BotSay("Doesn't mean you need to be an ass about it..", player);
            break;
        case TEXT_EMOTE_HUNGRY:
            me->HandleEmoteCommand(EMOTE_ONESHOT_EAT);
            BotSay("What? You want some of this?", player);
            break;
        case TEXT_EMOTE_LAYDOWN:
        case TEXT_EMOTE_TIRED:
        case TEXT_EMOTE_YAWN:
            me->HandleEmoteCommand(EMOTE_ONESHOT_KNEEL);
            BotSay("Is it break time already?", player);
            break;
        case TEXT_EMOTE_MOAN:
        case TEXT_EMOTE_MOON:
        case TEXT_EMOTE_SEXY:
        case TEXT_EMOTE_SHAKE:
        case TEXT_EMOTE_WHISTLE:
        case TEXT_EMOTE_CUDDLE:
        case TEXT_EMOTE_PURR:
        case TEXT_EMOTE_SHIMMY:
        case TEXT_EMOTE_SMIRK:
        case TEXT_EMOTE_WINK:
        case TEXT_EMOTE_CHARM:
            me->HandleEmoteCommand(EMOTE_ONESHOT_NO);
            BotSay("Keep it in your pants, boss..", player);
            break;
        case TEXT_EMOTE_NO:
        case TEXT_EMOTE_VETO:
        case TEXT_EMOTE_DISAGREE:
        case TEXT_EMOTE_DOUBT:
            me->HandleEmoteCommand(EMOTE_ONESHOT_QUESTION);
            BotSay("Aww.... why not?!", player);
            break;
        case TEXT_EMOTE_PANIC:
            me->HandleEmoteCommand(EMOTE_ONESHOT_EXCLAMATION);
            BotSay("Now is NOT the time to panic!", player);
            break;
        case TEXT_EMOTE_POINT:
            me->HandleEmoteCommand(EMOTE_ONESHOT_POINT);
            BotSay("What?! I can do that TOO!", player);
            break;
        case TEXT_EMOTE_RUDE:
        case TEXT_EMOTE_RASP:
            me->HandleEmoteCommand(EMOTE_ONESHOT_RUDE);
            BotSay("Right back at you, bub!", player);
            break;
        case TEXT_EMOTE_ROAR:
        case TEXT_EMOTE_THREATEN:
        case TEXT_EMOTE_CALM:
        case TEXT_EMOTE_DUCK:
        case TEXT_EMOTE_TAUNT:
        case TEXT_EMOTE_PITY:
        case TEXT_EMOTE_GROWL:
        case TEXT_EMOTE_TRAIN:
        case TEXT_EMOTE_INCOMING:
        case TEXT_EMOTE_CHARGE:
        case TEXT_EMOTE_FLEE:
        case TEXT_EMOTE_ATTACKMYTARGET:
        case TEXT_EMOTE_OPENFIRE:
        case TEXT_EMOTE_ENCOURAGE:
        case TEXT_EMOTE_ENEMY:
        case TEXT_EMOTE_CHALLENGE:
        case TEXT_EMOTE_REVENGE:
        case TEXT_EMOTE_SHAKEFIST:
            me->HandleEmoteCommand(EMOTE_ONESHOT_ROAR);
            BotYell("RAWR!", player);
            break;
        case TEXT_EMOTE_TALK:
        case TEXT_EMOTE_TALKEX:
        case TEXT_EMOTE_TALKQ:
        case TEXT_EMOTE_LISTEN:
            me->HandleEmoteCommand(EMOTE_ONESHOT_TALK);
            BotSay("Blah Blah Blah Yakety Smackety..", player);
            break;
        case TEXT_EMOTE_THANK:
            me->HandleEmoteCommand(EMOTE_ONESHOT_BOW);
            BotSay("You are quite welcome!", player);
            break;
        case TEXT_EMOTE_VICTORY:
        case TEXT_EMOTE_CHEER:
        case TEXT_EMOTE_TOAST:
        case TEXT_EMOTE_HIGHFIVE:
        case TEXT_EMOTE_DING:
            me->HandleEmoteCommand(EMOTE_ONESHOT_CHEER);
            BotSay("Yay!", player);
            break;
        case TEXT_EMOTE_COLD:
        case TEXT_EMOTE_SHIVER:
        case TEXT_EMOTE_THIRSTY:
        case TEXT_EMOTE_OOM:
        case TEXT_EMOTE_HEALME:
        case TEXT_EMOTE_POUT:
            me->HandleEmoteCommand(EMOTE_ONESHOT_QUESTION);
            BotSay("And what exactly am I supposed to do about that?", player);
            break;
        case TEXT_EMOTE_COMFORT:
        case TEXT_EMOTE_SOOTHE:
        case TEXT_EMOTE_PAT:
            me->HandleEmoteCommand(EMOTE_ONESHOT_CRY);
            BotSay("Thanks...", player);
            break;
        case TEXT_EMOTE_INSULT:
            me->HandleEmoteCommand(EMOTE_ONESHOT_CRY);
            BotSay("You hurt my feelings..", player);
            break;
        case TEXT_EMOTE_JK:
            me->HandleEmoteCommand(EMOTE_ONESHOT_POINT);
            BotSay("You.....", player);
            break;
        case TEXT_EMOTE_RAISE:
            me->HandleEmoteCommand(EMOTE_ONESHOT_POINT);
            BotSay("Yes.. you.. at the back of the class..", player);
            break;
        case TEXT_EMOTE_READY:
            me->HandleEmoteCommand(EMOTE_ONESHOT_SALUTE);
            BotSay("Ready here, too!", player);
            break;
        case TEXT_EMOTE_SHOO:
            me->HandleEmoteCommand(EMOTE_ONESHOT_KICK);
            BotSay("Shoo yourself!", player);
            break;
        case TEXT_EMOTE_SLAP:
        case TEXT_EMOTE_SMACK:
            me->HandleEmoteCommand(EMOTE_ONESHOT_CRY);
            BotSay("What did I do to deserve that?", player);
            break;
        case TEXT_EMOTE_STAND:
            me->HandleEmoteCommand(EMOTE_ONESHOT_NONE);
            BotSay("What? Break time's over? Fine..", player);
            break;
        case TEXT_EMOTE_TICKLE:
            me->HandleEmoteCommand(EMOTE_ONESHOT_LAUGH);
            BotSay("Hey! Stop that!", player);
            break;
        case TEXT_EMOTE_VIOLIN:
            me->HandleEmoteCommand(EMOTE_ONESHOT_TALK);
            BotSay("Har Har.. very funny..", player);
            break;
        case TEXT_EMOTE_HELPME:
            me->HandleEmoteCommand(EMOTE_ONESHOT_POINT);
            BotYell("Quick! Someone HELP!", player);
            break;
        case TEXT_EMOTE_GOODLUCK:
        case TEXT_EMOTE_LUCK:
            me->HandleEmoteCommand(EMOTE_ONESHOT_TALK);
            BotSay("Thanks... I'll need it..", player);
            break;
        case TEXT_EMOTE_BRANDISH:
        case TEXT_EMOTE_MERCY:
            me->HandleEmoteCommand(EMOTE_ONESHOT_BEG);
            BotSay("Please don't kill me!", player);
            break;
        case TEXT_EMOTE_BADFEELING:
            me->HandleEmoteCommand(EMOTE_ONESHOT_QUESTION);
            BotSay("I'm just waiting for the ominous music now...", player);
            break;
        case TEXT_EMOTE_MAP:
            me->HandleEmoteCommand(EMOTE_ONESHOT_NO);
            BotSay("Noooooooo.. you just couldn't ask for direction, huh?", player);
            break;
        case TEXT_EMOTE_IDEA:
        case TEXT_EMOTE_THINK:
            me->HandleEmoteCommand(EMOTE_ONESHOT_NO);
            BotSay("Oh boy.. another genius idea...", player);
            break;
        case TEXT_EMOTE_OFFER:
            me->HandleEmoteCommand(EMOTE_ONESHOT_NO);
            BotSay("No thanks.. I had some back at the last village", player);
            break;
        case TEXT_EMOTE_PET:
            me->HandleEmoteCommand(EMOTE_ONESHOT_ROAR);
            BotSay("Do I look like a dog to you?!", player);
            break;
        case TEXT_EMOTE_ROLLEYES:
            me->HandleEmoteCommand(EMOTE_ONESHOT_POINT);
            BotSay("Keep doing that and I'll roll those eyes right out of your head..", player);
            break;
        case TEXT_EMOTE_SING:
            me->HandleEmoteCommand(EMOTE_ONESHOT_APPLAUD);
            BotSay("Lovely... just lovely..", player);
            break;
        case TEXT_EMOTE_COVEREARS:
            me->HandleEmoteCommand(EMOTE_ONESHOT_EXCLAMATION);
            BotYell("You think that's going to help you?!", player);
            break;
        default:
            me->HandleEmoteCommand(EMOTE_ONESHOT_QUESTION);
            BotSay("Mmmmmkaaaaaay...", player);
            break;
    }
}

//ISINBOTPARTY
//Returns group members (and their npcbots too)
//For now all your puppets are in your group automatically
bool bot_ai::IsInBotParty(Unit const* unit) const
{
    if (!unit) return false;
    if (unit == me || unit == master) return true;

    if (IAmFree())
    {
        if (unit == me->GetBotsPet())
            return true;

        Player const* owner = NULL;

        Creature const* bot = unit->ToCreature();
        if (bot)
        {
            //controlled bot case
            if (bot->GetBotAI() && !bot->IsFreeBot())
                owner = bot->GetBotOwner();

            //free bot / neutral case
            if (bot->GetFaction() == me->GetFaction())
                return true;
        }

        if (!owner)
            owner = unit->GetCharmerOrOwnerPlayerOrPlayerItself();
        if (owner && (owner->GetFaction() == me->GetFaction() || me->GetReactionTo(owner) >= REP_FRIENDLY))
            return true;

        if (unit->GetCharmerOrOwnerGUID() == me->GetGUID())
            return true;

        return false;
    }

    //cheap check
    if (Group* gr = master->GetGroup())
    {
        //group member case
        if (gr->IsMember(unit->GetGUID()))
            return true;
        //pointed target case
        for (uint8 i = 0; i != TARGETICONCOUNT; ++i)
            if (_healTargetIconFlags & GroupIconsFlags[i])
                if (ObjectGuid guid = gr->GetTargetIcons()[i])//check this one
                    if (guid == unit->GetGUID())
                        if (unit->GetReactionTo(master) >= REP_NEUTRAL &&
                            master->GetVictim() != unit &&
                            unit->GetVictim() != master)
                            return true;
    }

    //Player-controlled creature case
    if (Creature const* cre = unit->ToCreature())
    {
        //npcbot/npcbot's pet case
        if (Player* owner = cre->GetBotOwner())
        {
            if (owner == master)
                return true;
        }
        //pets, minions, guardians etc.
        else
        {
            ObjectGuid ownerGuid = unit->GetOwnerGUID();
            //controlled by group member
            if (Group* gr = master->GetGroup())
                if (gr->IsMember(ownerGuid))
                    return true;
        }
    }

    return false;
}

//REFRESHAURA
//Applies/reapplies aura stacks
bool bot_ai::RefreshAura(uint32 spellId, int8 count) const
{
    if (!spellId)
        return false;
    SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(spellId);
    if (!spellInfo)
    {
        TC_LOG_ERROR("entities.player", "bot_ai::RefreshAura(): Invalid spellInfo for spell %u! Bot - %s (botclass: %u, entry: %u)",
            spellId, me->GetName().c_str(), _botclass, me->GetEntry());
        return false;
    }

    if (me->HasAura(spellId))
        me->RemoveAurasDueToSpell(spellId);

    for (int8 i = 0; i < count; ++i)
        me->AddAura(spellInfo, MAX_EFFECT_MASK, me);

    return true;
}
//CHECKAURAS
//Updates bot's condition once a while
void bot_minion_ai::CheckAuras(bool force)
{
    opponent = me->GetVictim(); //safe

    if (!force)
    {
        Regenerate();
        _updateRations(); //safe
    }

    if (checkAurasTimer == 0)
    {
        checkAurasTimer = 10 + (IAmFree() ? 5 : master->GetNpcBotsCount() / 2);

        if (needparty)
        {
            needparty = false;
            if (!IAmFree()) //we could lose master
                master->GetBotMgr()->AddBotToGroup(me);
        }

        if (_bootTimer == 0)
        {
            //timer will be cancelled at bot removal so we are always free here
            //_bootTimer = -1; //Set in AbortTeleport()
            master->m_Controlled.erase(me);
            BotMgr::TeleportBot(me, master->GetMap(), master);
            return;
        }

        if (m_botCommandState != COMMAND_FOLLOW && m_botCommandState != COMMAND_STAY && opponent && !CCed(me, true))
        {
            if (IsMelee())
            {
                if (me->GetDistance(opponent) > 1.5f)
                    GetInPosition(true);
            }
            else
            {
                CalculateAttackPos(opponent, attackpos);
                if (me->GetDistance(attackpos) > 8)
                    GetInPosition(true, opponent, &attackpos);
            }
        }
        if (shouldUpdateStats && me->GetPhaseMask() == master->GetPhaseMask())
            SetStats(false);
        else if (!_powersTimer)
        {
            _powersTimer = 2000;
            UpdateHealth();
            UpdateMana();
        }
        if (rezz_cd > 0)
            --rezz_cd;
        if (clear_cd > 0)
            --clear_cd;
        else
            clear_cd = 15;
        if (_atHome && Rand() < 10)
            _atHome = false;
        return;
    }
    else if (force)
    {
        if (!opponent && !IAmFree())
        {
            if (master->isDead())
            {
                //If ghost move to corpse, else move to dead player
                if (master->HasFlag(PLAYER_FLAGS, PLAYER_FLAGS_GHOST))
                {
                    Corpse* corpse = master->GetCorpse();
                    if (corpse && me->GetMap() == corpse->FindMap() && !me->IsInCombat() && !me->HasUnitState(UNIT_STATE_MOVING) && !IsCasting() && !CCed(me) && me->GetDistance(corpse) > 5)
                        me->GetMotionMaster()->MovePoint(corpse->GetMapId(), *corpse);
                }
                else
                {
                    if (m_botCommandState != COMMAND_FOLLOW || me->GetDistance(master) > 30 - 20 * (!me->IsWithinLOSInMap(master)))
                        Follow(true);
                }
            }
            else if (m_botCommandState != COMMAND_STAY && !IsCasting())
            {
                _calculatePos(pos);
                uint8 followdist = master->GetBotFollowDist();
                if (me->GetExactDist(&pos) > (followdist > 8 ? 4 + followdist/2*(!master->isMoving()) : 8))
                    Follow(true, &pos); //check if doing nothing
            }
        }
        if (!IsCasting())
        {
            if (me->IsInCombat() || !CanSheath())
            {
                if (!me->IsStandState())
                {
                    if (_botclass == BOT_CLASS_HUNTER)
                    {
                        // thesawolf - testing a hunter ranged state bug
                        if (me->GetSheath() != SHEATH_STATE_RANGED)
                            me->SetSheath(SHEATH_STATE_RANGED);
                    }
                    else if (me->GetSheath() != SHEATH_STATE_MELEE)
                        me->SetSheath(SHEATH_STATE_MELEE);
                }
            }
            else if (me->IsStandState() && me->GetSheath() != SHEATH_STATE_UNARMED && Rand() < 50)
            {
                me->SetSheath(SHEATH_STATE_UNARMED);
                if (_botclass == BOT_CLASS_HUNTER)
                    me->HandleEmoteCommand(EMOTE_ONESHOT_CHEER);
            }
        }

        _updateMountedState();
        _updateStandState();

        //update flags
        if (!me->IsInCombat() && !_evadeMode && _atHome && !me->HasFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP))
            me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
    }
}
void bot_pet_ai::CheckAuras(bool /*force*/)
{
    Regenerate();

    if (checkAurasTimer > 0) return;
    checkAurasTimer = 10 + IAmFree() ? 5 : master->GetNpcBotsCount() / 2;

    if (m_botCommandState != COMMAND_FOLLOW && m_botCommandState != COMMAND_STAY)
    {
        opponent = me->GetVictim();
        if (opponent)
        {
            switch (GetPetType(me))
            {
                case PET_TYPE_IMP:
                    CalculateAttackPos(opponent, attackpos);
                    if (me->GetDistance(attackpos) > 8)
                        GetInPosition(true, opponent, &attackpos);
                    break;
                default:
                    if (me->GetDistance(opponent) > 1.5f)
                        GetInPosition(true);
                    break;
            }
        }
    }
    if (clear_cd > 0)
        --clear_cd;
    else
        clear_cd = 15;

    return;
}

bool bot_ai::CanBotAttack(Unit const* target, int8 byspell) const
{
    if (!target)
        return false;
    if (!_botPvP && !IAmFree() && target->IsControlledByPlayer())
        return false;
    uint8 followdist = IAmFree() ? 100 : master->GetBotFollowDist();
    float foldist = _getAttackDistance(float(followdist));
    return
       (target->IsAlive() &&
       target->IsVisible() &&
       //me->IsValidAttackTarget(target) &&
       ((me->CanSeeOrDetect(target) && target->InSamePhase(me)) || CanSeeEveryone()) &&
       //!target->HasStealthAura() && !target->HasInvisibilityAura() &&
       (master->isDead() || target->GetTypeId() == TYPEID_PLAYER || target->IsPet() ||
       (target->GetDistance(master) < foldist && me->GetDistance(master) < followdist)) &&//if master is killed pursue to the end
        target->isTargetableForAttack() &&
        !IsInBotParty(target) &&
        (target->IsHostileTo(master) ||
        (target->GetReactionTo(master) < REP_FRIENDLY/* && master->GetVictim() == target*/ && (master->IsInCombat() || target->IsInCombat())) ||//master has pointed this target
        target->IsHostileTo(me)) &&//if master is controlled
        //target->IsWithinLOSInMap(me) &&
        (byspell == -1 || !target->IsImmunedToDamage(byspell ? SPELL_SCHOOL_MASK_MAGIC : SPELL_SCHOOL_MASK_NORMAL)));
}
//GETTARGET
//Returns attack target or 'no target'
Unit* bot_ai::_getTarget(bool byspell, bool ranged, bool &reset) const
{
    if (_evadeMode) //IAmFree() case only
        return NULL;

    Unit* u = master->GetVictim();
    Unit* mytar = me->GetVictim();

    //check if no need to change target
    if (!mytar && IsMinionAI())
        if (Creature* pet = me->GetBotsPet())
            mytar = pet->GetVictim();
    if (!mytar && IsPetAI())
        mytar = me->GetBotPetAI()->GetCreatureOwner()->GetVictim();

    //TC_LOG_ERROR("entities.player", "bot_ai::getTarget(): bot: %s, PvP = %u", me->GetName().c_str(), PvP);

    if (u && u == mytar && !IAmFree())
    {
        //TC_LOG_ERROR("entities.player", "bot %s continues attack common target %s", me->GetName().c_str(), u->GetName().c_str());
        return u;//forced
    }
    //Follow if...
    uint8 followdist = IAmFree() ? 100 : master->GetBotFollowDist();
    float foldist = _getAttackDistance(float(followdist));
    if (!u && master->IsAlive() && (me->GetDistance(master) > foldist || (mytar && master->GetDistance(mytar) > foldist && me->GetDistance(master) > foldist)))
    {
        //TC_LOG_ERROR("entities.player", "bot %s cannot attack target %s, too far away", me->GetName().c_str(), mytar ? mytar->GetName().c_str() : "");
        return NULL;
    }

    if (u && !IAmFree() && (master->IsInCombat() || u->IsInCombat()) && !InDuel(u) && !IsInBotParty(u) && !(!_botPvP && !IAmFree() && u->IsControlledByPlayer()))
    {
        //TC_LOG_ERROR("entities.player", "bot %s starts attack master's target %s", me->GetName().c_str(), u->GetName().c_str());
        return u;
    }

    if (mytar && (!IAmFree() || me->GetDistance(mytar) < BOT_MAX_CHASE_RANGE) && CanBotAttack(mytar, byspell) && !InDuel(mytar))
    {
        //TC_LOG_ERROR("entities.player", "bot %s continues attack its target %s", me->GetName().c_str(), mytar->GetName().c_str());
        if (me->GetDistance(mytar) > (ranged ? 20.f : 5.f) && m_botCommandState != COMMAND_STAY && m_botCommandState != COMMAND_FOLLOW)
            reset = true;
        return mytar;
    }

    if (followdist == 0 && master->IsAlive())
        return NULL; //do not bother

    //check group
    if (!IAmFree())
    {
        Group* gr = master->GetGroup();
        if (!gr)
        {
            BotMap const* map = master->GetBotMgr()->GetBotMap();
            for (BotMap::const_iterator itr = map->begin(); itr != map->end(); ++itr)
            {
                Creature* bot = itr->second;
                if (!bot || !bot->InSamePhase(me) || bot == me) continue;
                u = bot->GetVictim();
                if (u && CanBotAttack(u, byspell) &&
                    (bot->IsInCombat() || u->IsInCombat()) &&
                    (master->isDead() || master->GetDistance(u) < foldist))
                {
                    //TC_LOG_ERROR("entities.player", "bot %s hooked %s's victim %s", me->GetName().c_str(), bot->GetName().c_str(), u->GetName().c_str());
                    return u;
                }
                Creature* pet = bot->GetIAmABot() ? bot->GetBotsPet() : NULL;
                if (!pet || !pet->InSamePhase(me)) continue;
                u = pet->GetVictim();
                if (u && CanBotAttack(u, byspell) &&
                    (pet->IsInCombat() || u->IsInCombat()) &&
                    (master->isDead() || master->GetDistance(u) < foldist))
                {
                    //TC_LOG_ERROR("entities.player", "bot %s hooked %s's victim %s", me->GetName().c_str(), pet->GetName().c_str(), u->GetName().c_str());
                    return u;
                }
            }
        }
        else
        {
            for (GroupReference* ref = gr->GetFirstMember(); ref != NULL; ref = ref->next())
            {
                Player* pl = ref->GetSource();
                if (!pl || !pl->IsInWorld() || pl->IsBeingTeleported()) continue;
                if (me->GetMap() != pl->FindMap() || !pl->InSamePhase(me)) continue;
                u = pl->GetVictim();
                if (u && pl != master && CanBotAttack(u, byspell) &&
                    (pl->IsInCombat() || u->IsInCombat()) &&
                    (master->isDead() || master->GetDistance(u) < foldist))
                {
                    //TC_LOG_ERROR("entities.player", "bot %s hooked %s's victim %s", me->GetName().c_str(), pl->GetName().c_str(), u->GetName().c_str());
                    return u;
                }
                if (!pl->HaveBot()) continue;
                BotMap const* map = pl->GetBotMgr()->GetBotMap();
                for (BotMap::const_iterator it = map->begin(); it != map->end(); ++it)
                {
                    Creature* bot = it->second;
                    if (!bot || !bot->InSamePhase(me) || bot == me) continue;
                    if (!bot->IsInWorld()) continue;
                    if (me->GetMap() != bot->FindMap()) continue;
                    u = bot->GetVictim();
                    if (u && CanBotAttack(u, byspell) &&
                        (bot->IsInCombat() || u->IsInCombat()) &&
                        (master->isDead() || master->GetDistance(u) < foldist))
                    {
                        //TC_LOG_ERROR("entities.player", "bot %s hooked %s's victim %s", me->GetName().c_str(), bot->GetName().c_str(), u->GetName().c_str());
                        return u;
                    }
                    Creature* pet = bot->GetIAmABot() ? bot->GetBotsPet() : NULL;
                    if (!pet || !pet->InSamePhase(me)) continue;
                    if (!pet->IsInWorld()) continue;
                    if (me->GetMap() != pet->FindMap()) continue;
                    u = pet->GetVictim();
                    if (u && CanBotAttack(u, byspell) &&
                        (pet->IsInCombat() || u->IsInCombat()) &&
                        (master->isDead() || master->GetDistance(u) < foldist))
                    {
                        //TC_LOG_ERROR("entities.player", "bot %s hooked %s's victim %s", me->GetName().c_str(), pet->GetName().c_str(), u->GetName().c_str());
                        return u;
                    }
                }
            }
        }
    }

    //check targets around
    Unit* t = NULL;
    float maxdist = InitAttackRange(float(followdist), ranged);
    //first cycle we search non-cced target, then, if not found, check all
    for (uint8 i = 0; i != 2; ++i)
    {
        if (!t)
        {
            bool attackCC = i;

            CellCoord p(Trinity::ComputeCellCoord(me->GetPositionX(), me->GetPositionY()));
            Cell cell(p);
            cell.SetNoCreate();

            NearestHostileUnitCheck check(me, maxdist, byspell, this, attackCC);
            Trinity::UnitLastSearcher <NearestHostileUnitCheck> searcher(master, t, check);
            me->VisitNearbyObject(maxdist, searcher);
        }
    }

    if (t && opponent && t != opponent)
        reset = true;

    //if (t)
    //    TC_LOG_ERROR("entities.player", "bot %s has Found new target %s", me->GetName().c_str(), t->GetName().c_str());

    return t;
}
//'CanAttack' function
bool bot_ai::CheckAttackTarget(uint8 botOrPetType)
{
    if (IsDuringTeleport()/* || _evadeMode*/)
    {
        //me->AttackStop(); //already in CombatStop()
        me->CombatStop(true);
        return false;
    }

    if (IAmFree() && Feasting())
        return false;

    bool byspell = false, ranged = false, reset = false;

    if (IsMinionAI())
    {
        switch (botOrPetType)
        {
            case BOT_CLASS_DRUID:
                byspell = me->GetShapeshiftForm() == FORM_NONE ||
                    me->GetShapeshiftForm() == FORM_TREE ||
                    me->GetShapeshiftForm() == FORM_MOONKIN;
                ranged = byspell;
                break;
            case BOT_CLASS_PRIEST:
            case BOT_CLASS_MAGE:
            case BOT_CLASS_WARLOCK:
            case BOT_CLASS_SHAMAN:
                byspell = true;
                break;
            case BOT_CLASS_HUNTER:
                ranged = true;
                break;
            case BOT_CLASS_DEATH_KNIGHT:
            case BOT_CLASS_PALADIN:
            case BOT_CLASS_WARRIOR:
            case BOT_CLASS_ROGUE:
            case BOT_CLASS_BM:
                break;
            default:
                TC_LOG_ERROR("entities.player", "bot_ai: CheckAttackTarget() - unknown bot class %u", botOrPetType);
                return false;
        }
    }
    else
    {
        switch (botOrPetType)
        {
            case PET_TYPE_IMP:
                byspell = true;
                ranged = true;
                break;
            case PET_TYPE_VOIDWALKER:
                byspell = false;
                ranged = false;
                break;
            default:
                TC_LOG_ERROR("entities.player", "bot_ai: CheckAttackTarget() - unknown pet type %u", botOrPetType);
                return false;
        }
    }
    opponent = _getTarget(byspell, ranged, reset);
    if (!opponent)
    {
        //TC_LOG_ERROR("entities.player", "bot_ai: CheckAttackTarget() - bot %s lost target", me->GetName().c_str());
        if (me->GetVictim() || me->IsInCombat()/* || !me->getThreatManager().isThreatListEmpty()*/)
        {
            if (me->GetVictim())
                me->AttackStop();
            else if (me->IsInCombat())
                Evade(true);
        }

        return false;
    }
    if (reset)
        m_botCommandState = COMMAND_ABANDON;//reset AttackStart()

    if (opponent != me->GetVictim())
        me->Attack(opponent, !ranged);

    return true;
}
//POSITION
void bot_ai::CalculateAttackPos(Unit* target, Position& pos) const
{
    uint8 followdist = IAmFree() ? 100 : master->GetBotFollowDist();
    float x(0),y(0),z(0),
        dist = float(6 + urand(followdist/4, followdist/3)),
        angle = target->GetAngle(me);
    dist = std::min(dist, 20.f);
    if (me->GetIAmABotsPet())
        dist *= 0.5f;
    float clockwise = RAND(1.f,-1.f);
    for (uint8 i = 0; i != 5; ++i)
    {
        target->GetNearPoint(me, x, y, z, me->GetObjectSize()/2.f, dist, angle);
        bool toofaraway = master->GetDistance(x,y,z) > (followdist > 28 ? 28.f : followdist < 20 ? 20.f : float(followdist));
        bool outoflos = !target->IsWithinLOS(x,y,z);
        if (toofaraway || outoflos)
        {
            if (toofaraway)
                angle = target->GetAngle(master) + frand(0.f, M_PI*0.5f) * clockwise;
            if (outoflos)
                dist *= 0.5f;
        }
        else
        {
            dist *= 0.75f;
            break;
        }
    }
    pos.m_positionX = x;
    pos.m_positionY = y;
    pos.m_positionZ = z;
}
// Forces bot to chase opponent (if ranged then distance depends on follow distance)
void bot_ai::GetInPosition(bool force, Unit* newtarget, Position* mypos)
{
    if (CCed(me, true) || JumpingFlyingOrFalling())
        return;
    if (!newtarget)
        newtarget = me->GetVictim();
    if (!newtarget)
        return;
    if ((!newtarget->IsInCombat() || m_botCommandState == COMMAND_STAY) && !force)
        return;
    if (IsCasting())
        return;
    if (UpdateImpossibleChase(newtarget))
        return;
    bool ranged = !IsMelee();
    if (IsPetAI())
    {
        if (bot_pet_ai::GetPetType(me) == PET_TYPE_VOIDWALKER)
            ranged = false;
    }
    uint8 followdist = IAmFree() ? 100 : master->GetBotFollowDist();
    if (ranged)
    {
        if (!force && newtarget->GetTypeId() == TYPEID_PLAYER &&
            me->GetDistance(newtarget) < 6 + urand(followdist/4, followdist/3)) return;//do not allow constant runaway from player
        if (!mypos)
        {
            CalculateAttackPos(newtarget, attackpos);
        }
        else
        {
            attackpos.m_positionX = mypos->m_positionX;
            attackpos.m_positionY = mypos->m_positionY;
            attackpos.m_positionZ = mypos->m_positionZ;
        }
        if (me->GetDistance(attackpos) > (_botclass == BOT_CLASS_HUNTER ? 4 : 8))
            me->GetMotionMaster()->MovePoint(newtarget->GetMapId(), attackpos);
    }
    else if (!me->HasUnitState(UNIT_STATE_CHASE) || !me->HasUnitState(UNIT_STATE_CHASE_MOVE))
        me->GetMotionMaster()->MoveChase(newtarget);

    if (newtarget != me->GetVictim())
        me->Attack(newtarget, !ranged);
}

void bot_ai::CheckAttackState()
{
    if (me->GetVictim())
    {
        if (HasRole(BOT_ROLE_DPS))
            DoMeleeAttackIfReady();
    }
    else
        Evade();
}

bool bot_ai::MoveBehind(Unit &target) const
{
    if (CCed(me, true)) return false;
    if (JumpingFlyingOrFalling()) return false;
    if (target.HasUnitState(UNIT_STATE_CASTING)) return false;
    if (target.IsWithinCombatRange(me, ATTACK_DISTANCE) &&
        target.HasInArc(M_PI, me)                       &&
        !IsTank()                                       &&
        (_botclass == BOT_CLASS_ROGUE ? target.GetVictim() != me || CCed(&target) : target.GetVictim() != me && !CCed(&target)))
    {
        float x(0),y(0),z(0);
        target.GetNearPoint(me, x, y, z, me->GetObjectSize()/3, 0.1f, me->GetAngle(&target));
        me->GetMotionMaster()->MovePoint(target.GetMapId(), x, y, z);
        return true;
    }
    return false;
}
//MOUNT SUPPORT
void bot_minion_ai::_updateMountedState()
{
    if (IAmFree())
        return;
    if (GetBotCommandState() != COMMAND_FOLLOW)
        return;

    bool aura = me->HasAuraType(SPELL_AURA_MOUNTED);
    bool mounted = me->IsMounted();

    //allow dismount
    if (!CanMount() && !aura && !mounted)
        return;

    if ((!master->IsMounted() || aura != mounted || (me->IsInCombat() && opponent)) && (aura || mounted))
    {
        const_cast<CreatureTemplate*>(me->GetCreatureTemplate())->InhabitType &= ~INHABIT_AIR;
        me->RemoveAurasByType(SPELL_AURA_MOUNTED);
        //me->RemoveUnitMovementFlag(MOVEMENTFLAG_HOVER);
        me->SetCanFly(false);
        me->SetDisableGravity(false);
        me->RemoveUnitMovementFlag(MOVEMENTFLAG_FALLING);
        me->Dismount();
        return;
    }
    if (me->IsInCombat() || IsCasting() || me->HasUnitMovementFlag(MOVEMENTFLAG_SWIMMING)) //IsInWater() is too much calculations
        return;

    if (master->IsMounted() && !me->IsMounted() && !master->IsInCombat() && !me->IsInCombat() && !me->GetVictim())
    {
        uint32 mount = 0;
        Unit::AuraEffectList const& mounts = master->GetAuraEffectsByType(SPELL_AURA_MOUNTED);
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
            if (Feasting())
            {
                me->RemoveAurasDueToSpell(DRINK);
                me->RemoveAurasDueToSpell(EAT);
            }

            if (!GetSpell(mount))
                InitSpellMap(mount, true); //learn
            
            //thesawolf - docast wasn't applying mount aura properly
            //if doCast(me, mount))
            if (me->AddAura(mount, me))
            {
                // thesawolf - let's give it some personality
                me->HandleEmoteCommand(EMOTE_ONESHOT_CHEER);                
                BotSay("Let's roll out!", master);
                return;
            } else {
                BotSay("I have an issue with that mount, so I'm going to ride my chicken..", master);
                me->AddAura(65927, me); //summons chicken mount
                return;
            }
        }
    }
}
//STANDSTATE
void bot_minion_ai::_updateStandState() const
{
    if (IAmFree())
    {
        //if (!(me->GetInterruptMask() & AURA_INTERRUPT_FLAG_NOT_SEATED) && !me->IsStandState())
        //    me->SetStandState(UNIT_STAND_STATE_STAND);
        return;
    }
    if (master->GetStandState() == UNIT_STAND_STATE_STAND &&
        me->GetStandState() == UNIT_STAND_STATE_SIT &&
        !(me->GetInterruptMask() & AURA_INTERRUPT_FLAG_NOT_SEATED))
        me->SetStandState(UNIT_STAND_STATE_STAND);
    if (CanSit() && !me->IsInCombat() && !me->isMoving() &&
        (master->GetStandState() == UNIT_STAND_STATE_SIT || (me->GetInterruptMask() & AURA_INTERRUPT_FLAG_NOT_SEATED) || Feasting()) &&
        me->GetStandState() == UNIT_STAND_STATE_STAND	)
        me->SetStandState(UNIT_STAND_STATE_SIT);
}
//RATIONS
void bot_minion_ai::_updateRations()
{
    bool noFeast = me->IsInCombat() || CCed(me);
    if (noFeast || me->IsStandState())
    {
        if (feast_health)
        {
            feast_health = false;
            me->RemoveAurasDueToSpell(EAT);
        }
        if (feast_mana)
        {
            feast_mana = false;
            me->RemoveAurasDueToSpell(DRINK);
        }

        if (noFeast)
            return;
    }

    //drink
    if (!feast_mana && me->GetMaxPower(POWER_MANA) > 1 && !me->IsMounted() && !me->isMoving() && CanDrink() &&
        !me->IsInCombat() && !IsCasting() && GetManaPCT(me) < 80 && urand(0, 100) < 20 &&
        !me->HasAura(DRINK))
    {
        feast_mana = true;
        mana_cd = 0;
        me->CastSpell(me, DRINK);
        me->SetStandState(UNIT_STAND_STATE_SIT);
    }
    if (feast_mana)
    {
        mana_cd += lastdiff;
        if (mana_cd >= RATIONS_CD && me->GetMaxPower(POWER_MANA) > 1 && me->GetPower(POWER_MANA) < me->GetMaxPower(POWER_MANA) && me->HasAura(DRINK))
        {
            while (mana_cd >= RATIONS_CD)
            {
                mana_cd -= RATIONS_CD;
                //25000 / 1000 = 25: 4%
                //25000 / 2000 = 12: 8.5%
                me->ModifyPower(POWER_MANA, me->GetMaxPower(POWER_MANA) / (25000 / RATIONS_CD)); //4% per second if 1000
            }
        }
    }

    //eat
    if (!feast_health && !me->IsMounted() && !me->isMoving() && CanEat() &&
        !me->IsInCombat() && !IsCasting() && GetHealthPCT(me) < 80 && urand(0, 100) < 20 &&
        !me->HasAura(EAT))
    {
        feast_health = true;
        health_cd = 0;
        me->CastSpell(me, EAT);
        me->SetStandState(UNIT_STAND_STATE_SIT);
    }
    if (feast_health)
    {
        health_cd += lastdiff;
        if (health_cd >= RATIONS_CD && me->GetHealth() < me->GetMaxHealth() && me->HasAura(EAT))
        {
            while (health_cd >= RATIONS_CD)
            {
                health_cd -= RATIONS_CD;
                //20000 / 1000 = 20: 5%
                //20000 / 2000 = 10: 10%
                me->SetHealth(me->GetHealth() + me->GetMaxHealth() / (20000 / RATIONS_CD)); //5% per second if 1000
            }
        }
    }

    //check
    if (feast_mana && me->GetMaxPower(POWER_MANA) > 1 && me->GetPower(POWER_MANA) >= me->GetMaxPower(POWER_MANA))
    {
        feast_mana = false;
        me->RemoveAurasDueToSpell(DRINK);
    }
    if (feast_health && me->GetHealth() >= me->GetMaxHealth())
    {
        feast_health = false;
        me->RemoveAurasDueToSpell(EAT);
    }
}

void bot_minion_ai::Regenerate()
{
    if ((!me->IsInCombat() || me->IsPolymorphed()) && me->GetHealth() < me->GetMaxHealth())
    {
        regenTimer_hp += lastdiff;
        while (regenTimer_hp >= 2000)
        {
            regenTimer_hp -= 2000;
            int32 add = me->IsPolymorphed() ? me->GetMaxHealth() / 3 : IAmFree() ? me->GetMaxHealth() / 5 : me->GetCreateHealth() / 50 + me->getLevel() / 3;
            me->SetHealth(me->GetHealth() + add);
        }
    }

    if (me->GetMaxPower(POWER_MANA) > 1 && me->GetPower(POWER_MANA) < me->GetMaxPower(POWER_MANA))
    {
        regenTimer_mp += lastdiff;
        while (regenTimer_mp >= 5000)
        {
            regenTimer_mp -= 5000;
            int32 add = (!me->IsInCombat() && IAmFree()) ? me->GetMaxPower(POWER_MANA) / 5 : int32(regen_mp);
            me->ModifyPower(POWER_MANA, add);
        }
    }

    if (me->GetBotClass() == BOT_CLASS_ROGUE && me->GetPower(POWER_ENERGY) < me->GetMaxPower(POWER_ENERGY))
    {
        regenTimer_nrg += lastdiff;
        while (regenTimer_nrg >= 2000)
        {
            regenTimer_nrg -= 2000;
            if ((me->GetMaxPower(POWER_ENERGY)-me->GetPower(POWER_ENERGY)) < 20)
                me->SetPower(POWER_ENERGY, me->GetMaxPower(POWER_ENERGY));
            else
                me->ModifyPower(POWER_ENERGY, 20);
        }
    }
}
void bot_pet_ai::Regenerate()
{
    if (!regenTimer_hp && (!me->IsInCombat() || me->IsPolymorphed()) && me->GetHealth() < me->GetMaxHealth())
    {
        regenTimer_hp = 2000;
        int32 add = me->IsPolymorphed() ? me->GetMaxHealth() / 3 : me->GetCreateHealth() / 33 + me->getLevel() / 3;
        me->SetHealth(me->GetHealth() + add);
    }

    if (!regenTimer_mp && me->GetMaxPower(POWER_MANA) > 1 && me->GetPower(POWER_MANA) < me->GetMaxPower(POWER_MANA))
    {
        regenTimer_mp = 5000;
        me->ModifyPower(POWER_MANA, regen_mp); //mp5
    }
}
//PASSIVES
// Used to apply common passives (run once)
void bot_ai::ApplyPassives() const
{
    //me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_TAUNT, true);
    //me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_ATTACK_ME, true);

    ////DEPRECATEDmovement speed
    //if (master->HasAuraType(SPELL_AURA_MOD_SPEED_ALWAYS) ||
    //    master->HasAuraType(SPELL_AURA_MOD_SPEED_NOT_STACK) ||
    //    master->HasAuraType(SPELL_AURA_MOD_INCREASE_SPEED))
    //    RefreshAura(BOAR);

    ////apply +healing taken
    //RefreshAura(BOR, me->getLevel() >= 40 ? 1 : 0);//+40%

    //if (IsTempBot())
    //    return;

    if (IsMinionAI())
    {
        //apply -threat mod
        switch (_botclass)
        {
            case BOT_CLASS_WARRIOR:
            case BOT_CLASS_DEATH_KNIGHT:
                RefreshAura(RCP, 1 * !IsTank()); //-27%
                break;
            case BOT_CLASS_WARLOCK:
            case BOT_CLASS_PRIEST:
            case BOT_CLASS_MAGE:
            case BOT_CLASS_ROGUE:
            case BOT_CLASS_HUNTER:
            case BOT_CLASS_SHAMAN:
                RefreshAura(RCP, 3 * !IsTank()); //-87%
                break;
            case CLASS_PALADIN:
            case CLASS_DRUID:
            case BOT_CLASS_BM:
                RefreshAura(RCP, 2 * !IsTank()); //-54%
                break;
            default:
                TC_LOG_ERROR("entities.player", "bot_ai: ApplyPassives() - unknown bot class %u for bot %s (id: %u)",
                    uint32(_botclass), me->GetName().c_str(), me->GetEntry());
                break;
        }
        //apply +threat mods (1.43 * 1.45 = 2.0735; 1.0 + 0.43 + 0.45 = 1.88)
        RefreshAura(THREAT, 1 * IsTank()); //+43%
        RefreshAura(DEFENSIVE_STANCE_PASSIVE, 1 * IsTank()); //+45%
    }
    else
    {
        switch (bot_pet_ai::GetPetType(me))
        {
            case PET_TYPE_VOIDWALKER:
                break;
            case PET_TYPE_IMP:
                break;
            default:
                TC_LOG_ERROR("entities.player", "bot_ai: ApplyPassives() - unknown pet type %u for bot %s (id: %u)",
                    uint32(bot_pet_ai::GetPetType(me)), me->GetName().c_str(), me->GetEntry());
                break;
        }

        RefreshAura(THREAT, 1 * IsTank()); //+43%
        RefreshAura(DEFENSIVE_STANCE_PASSIVE, 2 * IsTank()); //+90%/-20%
    }
}
//check if our party players are in duel. if so - ignore them, their opponents and any bots they have
bool bot_ai::InDuel(Unit const* target) const
{
    if (!target) return false;
    bool isbot = target->GetTypeId() == TYPEID_UNIT && target->ToCreature()->GetBotAI();
    Player const* player = target->GetTypeId() == TYPEID_PLAYER ? target->ToPlayer() : isbot ? target->ToCreature()->GetBotOwner()->ToPlayer() : NULL;
    if (!player)
    {
        if (!target->IsControlledByPlayer())
            return false;
        player = target->GetCharmerOrOwnerPlayerOrPlayerItself();
    }

    return (player && player->duel && (IsInBotParty(player) || IsInBotParty(player->duel->opponent)));
}
////////////////
//GRID SEARCHERS
////////////////
//Finds player or it's corpse for resurrection returned as WorldObject*
WorldObject* bot_minion_ai::GetNearbyRezTarget(float dist) const
{
    CellCoord p(Trinity::ComputeCellCoord(me->GetPositionX(), me->GetPositionY()));
    Cell cell(p);
    cell.SetNoCreate();

    WorldObject* target = NULL;

    NearbyRezTargetCheck check(me, dist, this);
    Trinity::WorldObjectSearcher <NearbyRezTargetCheck> searcher(me, target, check);

    TypeContainerVisitor<Trinity::WorldObjectSearcher <NearbyRezTargetCheck>, WorldTypeMapContainer > world_unit_searcher(searcher);

    cell.Visit(p, world_unit_searcher, *me->GetMap(), *me, dist);

    return target;
}
//Used to find target for priest's dispels, mage's spellsteal and shaman's purge
//Returns dispellable/stealable 'Any Hostile Unit Attacking BotParty'
Unit* bot_minion_ai::FindHostileDispelTarget(float dist, bool stealable) const
{
    CellCoord p(Trinity::ComputeCellCoord(me->GetPositionX(), me->GetPositionY()));
    Cell cell(p);
    cell.SetNoCreate();

    Unit* unit = NULL;

    HostileDispelTargetCheck check(me, dist, stealable, this);
    Trinity::UnitLastSearcher <HostileDispelTargetCheck> searcher(me, unit, check);

    TypeContainerVisitor<Trinity::UnitLastSearcher <HostileDispelTargetCheck>, WorldTypeMapContainer > world_unit_searcher(searcher);
    TypeContainerVisitor<Trinity::UnitLastSearcher <HostileDispelTargetCheck>, GridTypeMapContainer >  grid_unit_searcher(searcher);

    cell.Visit(p, world_unit_searcher, *me->GetMap(), *me, dist);
    cell.Visit(p, grid_unit_searcher, *me->GetMap(), *me, dist);

    return unit;
}
//Finds single target affected by given spell (and given caster if is)
//Can check:
//    hostile targets  (hostile = 0) <default>
//    our party players (hostile = 1)
//    our party members  (hostile = 2)
//    any friendly target (hostile = 3)
//    any target in range  (hostile = any other value)
Unit* bot_minion_ai::FindAffectedTarget(uint32 spellId, ObjectGuid caster, float dist, uint8 hostile) const
{
    if (!spellId)
        return NULL;
    if ((hostile == 2 || hostile == 1) && IAmFree())
    {
        TC_LOG_ERROR("entities.player", "bot_ai::FindAffectedTarget(): hostile = %u while bot is free! Setting to 3...", hostile);
        hostile = 3;
    }
    if (master->GetMap()->Instanceable())
        dist = DEFAULT_VISIBILITY_INSTANCE;

    CellCoord p(Trinity::ComputeCellCoord(master->GetPositionX(), master->GetPositionY()));
    Cell cell(p);
    cell.SetNoCreate();

    Unit* unit = NULL;

    AffectedTargetCheck check(caster, dist, spellId, master, hostile);
    Trinity::UnitLastSearcher <AffectedTargetCheck> searcher(master, unit, check);

    TypeContainerVisitor<Trinity::UnitLastSearcher <AffectedTargetCheck>, WorldTypeMapContainer > world_unit_searcher(searcher);
    TypeContainerVisitor<Trinity::UnitLastSearcher <AffectedTargetCheck>, GridTypeMapContainer >  grid_unit_searcher(searcher);

    cell.Visit(p, world_unit_searcher, *master->GetMap(), *master, dist);
    cell.Visit(p, grid_unit_searcher, *master->GetMap(), *master, dist);

    return unit;
}
//Finds target for mage's polymorph or shaman's hex
Unit* bot_minion_ai::FindPolyTarget(float dist, Unit* currTarget) const
{
    if (!currTarget)
        return NULL;

    CellCoord p(Trinity::ComputeCellCoord(me->GetPositionX(), me->GetPositionY()));
    Cell cell(p);
    cell.SetNoCreate();

    Unit* unit = NULL;

    PolyUnitCheck check(me, dist, currTarget);
    Trinity::UnitLastSearcher <PolyUnitCheck> searcher(me, unit, check);

    TypeContainerVisitor<Trinity::UnitLastSearcher <PolyUnitCheck>, WorldTypeMapContainer > world_unit_searcher(searcher);
    TypeContainerVisitor<Trinity::UnitLastSearcher <PolyUnitCheck>, GridTypeMapContainer >  grid_unit_searcher(searcher);

    cell.Visit(p, world_unit_searcher, *me->GetMap(), *me, dist);
    cell.Visit(p, grid_unit_searcher, *me->GetMap(), *me, dist);

    return unit;
}
//Finds target for direct fear (warlock)
Unit* bot_minion_ai::FindFearTarget(float dist) const
{
    CellCoord p(Trinity::ComputeCellCoord(me->GetPositionX(), me->GetPositionY()));
    Cell cell(p);
    cell.SetNoCreate();

    Unit* unit = NULL;

    FearUnitCheck check(me, dist);
    Trinity::UnitLastSearcher <FearUnitCheck> searcher(me, unit, check);

    TypeContainerVisitor<Trinity::UnitLastSearcher <FearUnitCheck>, WorldTypeMapContainer > world_unit_searcher(searcher);
    TypeContainerVisitor<Trinity::UnitLastSearcher <FearUnitCheck>, GridTypeMapContainer >  grid_unit_searcher(searcher);

    cell.Visit(p, world_unit_searcher, *me->GetMap(), *me, dist);
    cell.Visit(p, grid_unit_searcher, *me->GetMap(), *me, dist);

    return unit;
}
//Finds target for paladin's repentance
Unit* bot_minion_ai::FindStunTarget(float dist) const
{
    CellCoord p(Trinity::ComputeCellCoord(me->GetPositionX(), me->GetPositionY()));
    Cell cell(p);
    cell.SetNoCreate();

    Unit* unit = NULL;

    StunUnitCheck check(me, dist);
    Trinity::UnitLastSearcher <StunUnitCheck> searcher(me, unit, check);

    TypeContainerVisitor<Trinity::UnitLastSearcher <StunUnitCheck>, WorldTypeMapContainer > world_unit_searcher(searcher);
    TypeContainerVisitor<Trinity::UnitLastSearcher <StunUnitCheck>, GridTypeMapContainer >  grid_unit_searcher(searcher);

    cell.Visit(p, world_unit_searcher, *me->GetMap(), *me, dist);
    cell.Visit(p, grid_unit_searcher, *me->GetMap(), *me, dist);

    return unit;
}
//Finds target for priest's shackles
Unit* bot_minion_ai::FindUndeadCCTarget(float dist, uint32 spellId/* = 0*/) const
{
    CellCoord p(Trinity::ComputeCellCoord(me->GetPositionX(), me->GetPositionY()));
    Cell cell(p);
    cell.SetNoCreate();

    Unit* unit = NULL;

    UndeadCCUnitCheck check(me, dist, spellId);
    Trinity::UnitLastSearcher <UndeadCCUnitCheck> searcher(me, unit, check);

    TypeContainerVisitor<Trinity::UnitLastSearcher <UndeadCCUnitCheck>, WorldTypeMapContainer > world_unit_searcher(searcher);
    TypeContainerVisitor<Trinity::UnitLastSearcher <UndeadCCUnitCheck>, GridTypeMapContainer >  grid_unit_searcher(searcher);

    cell.Visit(p, world_unit_searcher, *me->GetMap(), *me, dist);
    cell.Visit(p, grid_unit_searcher, *me->GetMap(), *me, dist);

    return unit;
}
//Finds target for druid's Entangling Roots
Unit* bot_minion_ai::FindRootTarget(float dist, uint32 spellId) const
{
    CellCoord p(Trinity::ComputeCellCoord(me->GetPositionX(), me->GetPositionY()));
    Cell cell(p);
    cell.SetNoCreate();

    Unit* unit = NULL;

    RootUnitCheck check(me, me->GetVictim(), dist, spellId);
    Trinity::UnitLastSearcher <RootUnitCheck> searcher(me, unit, check);

    TypeContainerVisitor<Trinity::UnitLastSearcher <RootUnitCheck>, WorldTypeMapContainer > world_unit_searcher(searcher);
    TypeContainerVisitor<Trinity::UnitLastSearcher <RootUnitCheck>, GridTypeMapContainer >  grid_unit_searcher(searcher);

    cell.Visit(p, world_unit_searcher, *me->GetMap(), *me, dist);
    cell.Visit(p, grid_unit_searcher, *me->GetMap(), *me, dist);

    return unit;
}
//Finds casting target (friend or enemy)
Unit* bot_minion_ai::FindCastingTarget(float maxdist, float mindist, bool isFriend, uint32 spellId) const
{
    CellCoord p(Trinity::ComputeCellCoord(me->GetPositionX(), me->GetPositionY()));
    Cell cell(p);
    cell.SetNoCreate();

    Unit* unit = NULL;

    CastingUnitCheck check(me, mindist, maxdist, isFriend, spellId);
    Trinity::UnitLastSearcher <CastingUnitCheck> searcher(me, unit, check);

    TypeContainerVisitor<Trinity::UnitLastSearcher <CastingUnitCheck>, WorldTypeMapContainer > world_unit_searcher(searcher);
    TypeContainerVisitor<Trinity::UnitLastSearcher <CastingUnitCheck>, GridTypeMapContainer >  grid_unit_searcher(searcher);

    cell.Visit(p, world_unit_searcher, *me->GetMap(), *me, maxdist);
    cell.Visit(p, grid_unit_searcher, *me->GetMap(), *me, maxdist);

    return unit;
}
// Returns target for AOE spell (blizzard, hurricane etc.) based on attackers count
// Cycles through BotParty, first checks player and, if checked, npcbots
// If checked, can return friendly target as target for AOE spell
Unit* bot_minion_ai::FindAOETarget(float dist, bool checkbots, bool targetfriend) const
{
    if (IsCasting() || IAmFree())
        return NULL;

    Unit* unit = NULL;
    Group* pGroup = master->GetGroup();
    if (!pGroup)
    {
        AttackerSet m_attackers = master->getAttackers();
        if (m_attackers.size() > 1)
        {
            uint32 mCount = 0;
            for(AttackerSet::iterator iter = m_attackers.begin(); iter != m_attackers.end(); ++iter)
            {
                if (!(*iter) || !(*iter)->IsAlive()) continue;
                if ((*iter)->isMoving()) continue;
                if ((*iter)->HasBreakableByDamageCrowdControlAura())
                    continue;
                if (me->GetDistance(*iter) < dist)
                    ++mCount;
            }
            if (mCount > 1)
            {
                Unit* u = master->GetVictim();
                if (mCount > 3 && targetfriend == true)
                    unit = master;
                else if (u && FindSplashTarget(dist + 8, u))
                    unit = u;
            }//end if
        }//end if
        if (!checkbots)
            return unit;
        BotMap const* map = master->GetBotMgr()->GetBotMap();
        for (BotMap::const_iterator itr = map->begin(); itr != map->end(); ++itr)
        {
            Creature* bot = itr->second;
            if (!bot || !bot->IsAlive() || !bot->IsInWorld() || me->GetDistance(bot) > dist) continue;

            AttackerSet b_attackers = bot->getAttackers();
            if (b_attackers.size() > 1)
            {
                uint32 mCount = 0;
                for(AttackerSet::iterator iter = b_attackers.begin(); iter != b_attackers.end(); ++iter)
                {
                    if (!(*iter) || !(*iter)->IsAlive()) continue;
                    if ((*iter)->isMoving()) continue;
                    if ((*iter)->HasBreakableByDamageCrowdControlAura())
                        continue;
                    if (me->GetDistance(*iter) < dist)
                        ++mCount;
                }
                if (mCount > 1)
                {
                    Unit* u = bot->GetVictim();
                    if (mCount > 3 && targetfriend == true)
                        unit = bot;
                    else if (u && FindSplashTarget(dist + 8, u))
                        unit = u;
                }//end if
            }//end if
            if (unit) return unit;
        }//end for
        return unit;
    }
    bool Bots = false;
    for (GroupReference* itr = pGroup->GetFirstMember(); itr != NULL; itr = itr->next())
    {
        Player* tPlayer = itr->GetSource();
        if (!tPlayer) continue;
        if (checkbots && tPlayer->HaveBot())
            Bots = true;
        if (!tPlayer->IsInWorld() || tPlayer->IsBeingTeleported()) continue;
        if (!tPlayer->IsAlive() || me->GetMap() != tPlayer->FindMap()) continue;
        if (me->GetDistance(tPlayer) > 40) continue;

        AttackerSet m_attackers = tPlayer->getAttackers();
        if (m_attackers.size() > 1)
        {
            uint32 mCount = 0;
            for (AttackerSet::iterator iter = m_attackers.begin(); iter != m_attackers.end(); ++iter)
            {
                if (!(*iter) || !(*iter)->IsAlive()) continue;
                if ((*iter)->isMoving()) continue;
                if (me->GetDistance(*iter) < dist)
                    ++mCount;
            }
            if (mCount > 1)
            {
                Unit* u = tPlayer->GetVictim();
                if (mCount > 3 && targetfriend == true)
                    unit = tPlayer;
                else if (u && FindSplashTarget(dist + 8, u))
                    unit = u;
            }//end if
        }//end if
        if (unit) return unit;
    }//end for
    if (!Bots) return NULL;
    for (GroupReference* itr = pGroup->GetFirstMember(); itr != NULL; itr = itr->next())
    {
        Player* tPlayer = itr->GetSource();
        if (tPlayer == NULL || !tPlayer->HaveBot()) continue;
        if (!tPlayer->IsInWorld() || tPlayer->IsBeingTeleported()) continue;
        if (me->GetMap() != tPlayer->FindMap()) continue;
        BotMap const* map = tPlayer->GetBotMgr()->GetBotMap();
        for (BotMap::const_iterator it = map->begin(); it != map->end(); ++it)
        {
            Creature* bot = it->second;
            if (!bot || !bot->IsAlive() || me->GetMap() != bot->FindMap()) continue;
            if (!bot->IsInWorld()) continue;
            if (me->GetDistance(bot) > 40) continue;

            AttackerSet b_attackers = bot->getAttackers();
            if (b_attackers.size() > 1)
            {
                uint32 mCount = 0;
                for(AttackerSet::iterator iter = b_attackers.begin(); iter != b_attackers.end(); ++iter)
                {
                    if (!(*iter) || !(*iter)->IsAlive()) continue;
                    if ((*iter)->isMoving()) continue;
                    if (me->GetDistance(*iter) < dist)
                        ++mCount;
                }
                if (mCount > 1)
                {
                    Unit* u = bot->GetVictim();
                    if (mCount > 3 && targetfriend == true)
                        unit = bot;
                    else if (u && FindSplashTarget(dist + 8, u))
                        unit = u;
                }//end if
            }//end if
        }//end for
        if (unit) return unit;
    }//end for
    return unit;
}
// Finds secondary target for spells like Cleave, Swipe, Mind Sear etc.
Unit* bot_minion_ai::FindSplashTarget(float dist, Unit* To, float splashdist) const
{
    if (!To)
        To = me->GetVictim();
    if (!To)
        return NULL;

    if (me->GetDistance(To) > dist)
        return NULL;

    CellCoord p(Trinity::ComputeCellCoord(me->GetPositionX(), me->GetPositionY()));
    Cell cell(p);
    cell.SetNoCreate();

    Unit* unit = NULL;

    SecondEnemyCheck check(me, dist, splashdist, To, this);
    Trinity::UnitLastSearcher <SecondEnemyCheck> searcher(me, unit, check);

    TypeContainerVisitor<Trinity::UnitLastSearcher <SecondEnemyCheck>, WorldTypeMapContainer > world_unit_searcher(searcher);
    TypeContainerVisitor<Trinity::UnitLastSearcher <SecondEnemyCheck>, GridTypeMapContainer >  grid_unit_searcher(searcher);

    cell.Visit(p, world_unit_searcher, *me->GetMap(), *me, dist);
    cell.Visit(p, grid_unit_searcher, *me->GetMap(), *me, dist);

    return unit;
}
//Finds target for hunter's Tranquilizing Shot (has dispellable magic or enrage effect)
Unit* bot_minion_ai::FindTranquilTarget(float mindist, float maxdist) const
{
    CellCoord p(Trinity::ComputeCellCoord(me->GetPositionX(), me->GetPositionY()));
    Cell cell(p);
    cell.SetNoCreate();

    Unit* unit = NULL;

    TranquilTargetCheck check(me, mindist, maxdist, this);
    Trinity::UnitLastSearcher <TranquilTargetCheck> searcher(me, unit, check);

    TypeContainerVisitor<Trinity::UnitLastSearcher <TranquilTargetCheck>, WorldTypeMapContainer > world_unit_searcher(searcher);
    TypeContainerVisitor<Trinity::UnitLastSearcher <TranquilTargetCheck>, GridTypeMapContainer >  grid_unit_searcher(searcher);

    cell.Visit(p, world_unit_searcher, *me->GetMap(), *me, maxdist);
    cell.Visit(p, grid_unit_searcher, *me->GetMap(), *me, maxdist);

    return unit;
}
//Finds all targets within given range with option for not having CC breaking auras
//used for finding targets for spells which need reasonable amount of targets (ex. Death Knight AOE spells)
void bot_minion_ai::GetNearbyTargetsList(std::list<Unit*> &targets, float maxdist, float mindist, bool forCC) const
{
    CellCoord p(Trinity::ComputeCellCoord(me->GetPositionX(), me->GetPositionY()));
    Cell cell(p);
    cell.SetNoCreate();

    NearbyHostileUnitCheck check(me, maxdist, mindist, this, forCC);
    Trinity::UnitListSearcher <NearbyHostileUnitCheck> searcher(me, targets, check);

    TypeContainerVisitor<Trinity::UnitListSearcher <NearbyHostileUnitCheck>, WorldTypeMapContainer > world_unit_searcher(searcher);
    TypeContainerVisitor<Trinity::UnitListSearcher <NearbyHostileUnitCheck>, GridTypeMapContainer >  grid_unit_searcher(searcher);

    cell.Visit(p, world_unit_searcher, *me->GetMap(), *me, maxdist);
    cell.Visit(p, grid_unit_searcher, *me->GetMap(), *me, maxdist);
}
//Finds all friendly targets within given range
//used for finding targets to heal/buff for uncontrolled bots
void bot_minion_ai::GetNearbyFriendlyTargetsList(std::list<Unit*> &targets, float maxdist) const
{
    CellCoord p(Trinity::ComputeCellCoord(me->GetPositionX(), me->GetPositionY()));
    Cell cell(p);
    cell.SetNoCreate();

    NearbyFriendlyUnitCheck check(me, maxdist, this);
    Trinity::UnitListSearcher <NearbyFriendlyUnitCheck> searcher(me, targets, check);

    TypeContainerVisitor<Trinity::UnitListSearcher <NearbyFriendlyUnitCheck>, WorldTypeMapContainer > world_unit_searcher(searcher);
    TypeContainerVisitor<Trinity::UnitListSearcher <NearbyFriendlyUnitCheck>, GridTypeMapContainer >  grid_unit_searcher(searcher);

    cell.Visit(p, world_unit_searcher, *me->GetMap(), *me, maxdist);
    cell.Visit(p, grid_unit_searcher, *me->GetMap(), *me, maxdist);
}
//////////
//SPELLMAP
//////////
//Using first-rank spell as source, returns spell of max rank allowed for given caster
uint32 bot_ai::InitSpell(Unit const* caster, uint32 spell)
{
    SpellInfo const* info = sSpellMgr->GetSpellInfo(spell);
    if (!info)
    {
        TC_LOG_ERROR("entities.player", "InitSpell(): No SpellInfo found for spell %u", spell);
        return 0; //weird spell with no info, disable it
    }

    uint8 lvl = caster->getLevel();
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
//Using first-rank spell as source, returns spell of max rank allowed for given caster in given spellmap
void bot_ai::InitSpellMap(uint32 basespell, bool forceadd, bool forwardRank)
{
    SpellInfo const* info = sSpellMgr->GetSpellInfo(basespell);
    if (!info)
    {
        TC_LOG_ERROR("entities.player", "InitSpellMap(): No SpellInfo found for base spell %u", basespell);
        return; //invalid spell id
    }

    uint8 lvl = me->getLevel();
    uint32 spellId = 0;

    while (info != NULL && forwardRank && (forceadd || lvl >= info->BaseLevel))
    {
        spellId = info->Id; //can use this spell
        info = info->GetNextRankSpell(); //check next rank
    }

    BotSpell newSpell;
    newSpell.first = spellId;
    newSpell.second = GetSpellCooldown(basespell);
    spells[basespell] = newSpell;
}
//Using first-rank spell as source, return current spell id
uint32 bot_ai::GetSpell(uint32 basespell) const
{
    BotSpellMap::const_iterator itr = spells.find(basespell);
    return itr != spells.end() ? itr->second.first : 0;
}
//Using first-rank spell as source, returns cooldown on current spell
uint32 bot_ai::GetSpellCooldown(uint32 basespell) const
{
    BotSpellMap::const_iterator itr = spells.find(basespell);
    return itr != spells.end() ? itr->second.second : 0;
}
bool bot_ai::IsSpellReady(uint32 basespell, uint32 diff, bool checkGCD, uint32 forcedTime) const
{
    BotSpellMap::const_iterator itr = spells.find(basespell);

    if (itr != spells.end())
    {
        return
        (itr->second.first != 0 &&
        (!checkGCD || GC_Timer <= diff) &&
        itr->second.second <= (forcedTime ? forcedTime : diff));
    }

    return false;
}
//Using first-rank spell as source, sets cooldown for current spell
void bot_ai::SetSpellCooldown(uint32 basespell, uint32 msCooldown)
{
    //if (!msCooldown)
    //    return;

    BotSpellMap::iterator itr = spells.find(basespell);
    if (itr != spells.end())
    {
        itr->second.second = msCooldown;
        return;
    }

    InitSpellMap(basespell, true, false);

    if (!GetSpell(basespell))
        return;

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
    for (BotSpellMap::iterator itr = spells.begin(); itr != spells.end(); ++itr)
    {
        //skip spell which has triggered this category cooldown
        if (itr->second.first == spellInfo->Id && itr->second.second >= msCooldown)
            continue;

        info = sSpellMgr->GetSpellInfo(itr->second.first);
        if (info && info->GetCategory() == category && itr->second.second < msCooldown)
            itr->second.second = msCooldown;
    }
}
//Using first-rank spell as source, disables certain spell for this bot
void bot_ai::RemoveSpell(uint32 basespell)
{
    BotSpellMap::iterator itr = spells.find(basespell);
    if (itr != spells.end())
    {
        itr->second.first = 0;
        itr->second.second = 0; //unneeded
    }
}
//Look in Creature::Update() for common timers
void bot_ai::SpellTimers(uint32 diff)
{
    // spell must be initialized!!!
    for (BotSpellMap::iterator itr = spells.begin(); itr != spells.end(); ++itr)
    {
        if (itr->second.second > diff)
            itr->second.second -= diff;
        else if (itr->second.second > 0)
            itr->second.second = 0;
    }
}
//Health magement for minions
//Including health calcs, set
void bot_minion_ai::_OnHealthUpdate() const
{
    if (IsTempBot())
        return;

    uint8 myclass = _botclass;
    uint8 mylevel = master->getLevel();
    if (myclass == BOT_CLASS_DRUID && GetBotStance() != BOT_STANCE_NONE)
        myclass = GetBotStance();
    //TC_LOG_ERROR("entities.player", "_OnHealthUpdate(): updating bot %s", me->GetName().c_str());
    float pct = me->GetHealthPct(); // needs for regeneration
    uint32 m_basehp = _classinfo->basehealth;
    //TC_LOG_ERROR("entities.player", "class base health: %u", m_basehp);
    me->SetCreateHealth(m_basehp);

    float stamValue = std::max(me->GetTotalStatValue(STAT_STAMINA) - 18.f, 1.f); //remove base stamina (not calculated into health)
    stamValue += _getTotalBotStat(BOT_ITEM_MOD_STAMINA);

    //class-specified
    if (GetPlayerClass() == BOT_CLASS_DRUID && myclass == DRUID_BEAR_FORM)
    {
        //Heart of the Wild: 10% stam bonus for bear
        if (mylevel >= 35)
            stamValue *= 1.1f;
    }

    //TC_LOG_ERROR("entities.player", "bot's stats to health add: Stamina (%f), value: %f", stamValue, stamValue * 10.f);
    int32 hp_add = int32(stamValue) * 10;
    hp_add += IAmFree() ? mylevel * 250.f : 0; //+20000/+0 hp at 80
    hp_add += _getTotalBotStat(BOT_ITEM_MOD_HEALTH);
    int32 miscVal = mylevel * 3 - 1;
    hp_add += miscVal;
    //TC_LOG_ERROR("entities.player", "health to add after slot mod: %i", hp_add);
    uint32 m_totalhp = m_basehp + hp_add; //m_totalhp = uint32(float(m_basehp + hp_add) * stammod);
    //TC_LOG_ERROR("entities.player", "total base health: %u", m_totalhp);
    uint8 bonuspct = 0;
    //bonuspct += 35 * IsTank();
    bonuspct += 8 * (GetBotStance() == DEATH_KNIGHT_FROST_PRESENCE);
    if (bonuspct)
        m_totalhp = (m_totalhp * (100 + bonuspct)) / 100;
    m_totalhp = float(uint32(m_totalhp) + (10 - (uint32(m_totalhp) % 10)));
    me->SetStatFlatModifier(UNIT_MOD_HEALTH, BASE_VALUE, float(m_totalhp)); //replaces base hp at max lvl
    me->UpdateMaxHealth(); //will use our values we just set (update base health and buffs)
    //TC_LOG_ERROR("entities.player", "overall hp: %u", me->GetMaxHealth());
    me->SetHealth(uint32(0.5f + float(me->GetMaxHealth()) * pct / 100.f)); //restore pct
}
//Mana management for minions
//Including calcs and set
void bot_minion_ai::_OnManaUpdate(bool /*shapeshift*/)
{
    if (me->GetMaxPower(POWER_MANA) <= 1)
        return;

    if (IsTempBot())
        return;

    uint8 myclass = _botclass;
    uint8 mylevel = master->getLevel();
    if (myclass == BOT_CLASS_DRUID && GetBotStance() != BOT_STANCE_NONE)
        myclass = GetBotStance();

    //TC_LOG_ERROR("entities.player", "_OnManaUpdate(): updating bot %s", me->GetName().c_str());
    float pct = me->GetMaxPower(POWER_MANA) == 0 ? 100 : (float(me->GetPower(POWER_MANA)) * 100.f) / float(me->GetMaxPower(POWER_MANA));
    float m_basemana = _classinfo->basemana;
    if (myclass == BOT_CLASS_BM)
        m_basemana = std::max<int32>(240 + (int32(mylevel - 20) * 5) - 225, 255); // 240 at 1, 540 at 81
    //TC_LOG_ERROR("entities.player", "classinfo base mana = %f", m_basemana);

    //decrease base mana for bots (allows using more mana)
    me->SetCreateMana(uint32(m_basemana * 0.667f)); //set base mana, critical

    float intValue = me->GetTotalStatValue(STAT_INTELLECT) - 18.f; //remove base int (not calculated into mana)
    intValue += _getTotalBotStat(BOT_ITEM_MOD_INTELLECT);
    m_basemana += intValue * 15.0f;
    m_basemana += IAmFree() ? mylevel * 125.f : 0; //+10000/+0 mana at 80
    m_basemana += _getTotalBotStat(BOT_ITEM_MOD_MANA);
    m_basemana = float(uint32(m_basemana) - (uint32(m_basemana) % 5));
    me->SetStatFlatModifier(UNIT_MOD_MANA, BASE_VALUE, m_basemana);
    me->UpdateMaxPower(POWER_MANA);
    me->SetPower(POWER_MANA, uint32(0.5f + float(me->GetMaxPower(POWER_MANA)) * pct / 100.f)); //restore pct
}
//Melee damage for minions (melee classes only)
//Calculation is based on master's attack power if melee/hunter or spellpower
void bot_minion_ai::_OnMeleeDamageUpdate(uint8 myclass) const
{
    if (IsTempBot())
        return;

    if (ap_mod < 0.1f) return; //do not bother casters
    //TC_LOG_ERROR("entities.player", "_OnMeleeDamageUpdate: Updating bot %s", me->GetName().c_str());

    for (uint8 i = 0; i != MAX_EQUIPMENT_ITEMS; ++i)
    {
        float weap_damage_base = _getBotStat(i, BOT_ITEM_MOD_DAMAGE);
        weap_damage_base += IAmFree() ? me->getLevel() * 3.75f : 0; //+300/+20 dam at 80
        me->SetStatFlatModifier(UnitMods(UNIT_MOD_DAMAGE_MAINHAND + i), BASE_VALUE, _getBotStat(i, BOT_ITEM_MOD_DAMAGE));
    }

    float atpower = IAmFree() ? me->getLevel() * 75.f : std::max(me->getLevel() - 40.f, 0.f) * 10.f; //+6000/+400 base ap at 80
    atpower += _getTotalBotStat(BOT_ITEM_MOD_ATTACK_POWER) + _getTotalBotStat(BOT_ITEM_MOD_RANGED_ATTACK_POWER);
    atpower += 2.f * ((me->GetTotalStatValue(STAT_STRENGTH) - 18) + (me->GetTotalStatValue(STAT_AGILITY) - 18));
    atpower += 2.f * (_getTotalBotStat(BOT_ITEM_MOD_STRENGTH) + _getTotalBotStat(BOT_ITEM_MOD_AGILITY));

    Unit::AuraEffectList const& mAPbyStat = me->GetAuraEffectsByType(SPELL_AURA_MOD_ATTACK_POWER_OF_STAT_PERCENT);
    for (Unit::AuraEffectList::const_iterator i = mAPbyStat.begin(); i != mAPbyStat.end(); ++i)
        atpower += CalculatePct(me->GetStat(Stats((*i)->GetMiscValue())), (*i)->GetAmount());

    Unit::AuraEffectList const& mAPbyArmor = me->GetAuraEffectsByType(SPELL_AURA_MOD_ATTACK_POWER_OF_ARMOR);
    for (Unit::AuraEffectList::const_iterator iter = mAPbyArmor.begin(); iter != mAPbyArmor.end(); ++iter)
        atpower += int32(me->GetArmor() / (*iter)->GetAmount());

    if (GetPlayerClass() == CLASS_DRUID && (GetBotStance() == DRUID_BEAR_FORM || GetBotStance() == DRUID_CAT_FORM))
    {
        atpower += _getTotalBotStat(BOT_ITEM_MOD_FERAL_ATTACK_POWER);
        //Predatory Strikes
        if (me->getLevel() >= 25)
        {
            atpower += me->getLevel() * 2 / 3;
            atpower += 0.2f * (
                _getBotStat(BOT_SLOT_MAINHAND, BOT_ITEM_MOD_FERAL_ATTACK_POWER)
                + _getBotStat(BOT_SLOT_MAINHAND, BOT_ITEM_MOD_ATTACK_POWER)
                + _getBotStat(BOT_SLOT_MAINHAND, BOT_ITEM_MOD_RANGED_ATTACK_POWER)
                );
        }
    }

    atpower *= ap_mod;
    me->SetStatFlatModifier(UNIT_MOD_ATTACK_POWER, BASE_VALUE, atpower);
    me->UpdateAttackPowerAndDamage();
    if (myclass == BOT_CLASS_HUNTER || myclass == BOT_CLASS_ROGUE)
    {
        me->SetStatFlatModifier(UNIT_MOD_ATTACK_POWER_RANGED, BASE_VALUE, atpower);
        me->UpdateAttackPowerAndDamage(true);
    }
}
//Health for pets
//Same as for minions just simplified (modified to match real pets' values)
void bot_pet_ai::_OnHealthUpdate() const
{
    uint8 mylevel = master->getLevel();
    float hp_mult;
    switch (GetPetType(me))
    {
        case PET_TYPE_VOIDWALKER:   hp_mult = 11.f; break;
        default:                    hp_mult = 10.f; break;
    }
    float pct = me->GetHealthPct();
    uint32 m_basehp = me->GetCreateHealth();
    float stamValue = me->GetTotalStatValue(STAT_STAMINA) - 18.f; //remove base stamina (not calculated into health)
    uint32 hp_add = uint32(stamValue * hp_mult);
    hp_add += (m_creatureOwner->GetMaxHealth() - m_creatureOwner->GetCreateHealth()) / 3;
    uint8 miscVal = GetPetType(me) * mylevel;
    hp_add += miscVal;
    uint32 m_totalhp = m_basehp + hp_add;
    if (IsTank())
        m_totalhp = (m_totalhp * 135) / 100; //35% hp bonus for tanks
    me->SetStatFlatModifier(UNIT_MOD_HEALTH, BASE_VALUE, float(m_totalhp));
    me->UpdateMaxHealth(); //will use values set (update base health and buffs)
    me->SetHealth(uint32(0.5f + float(me->GetMaxHealth()) * pct / 100.f)); //restore pct
}
//Mana for pets
//Same as for minions just simplified (modified to match real pets' values)
void bot_pet_ai::_OnManaUpdate(bool /*shapeshift*/)
{
    if (me->GetMaxPower(POWER_MANA) <= 1)
        return;

    uint8 mylevel = m_creatureOwner->getLevel();
    float mana_mult;
    switch (GetPetType(me))
    {
        case PET_TYPE_VOIDWALKER:   mana_mult = 11.5f;  break;
        default:                    mana_mult = 15.f;   break;
    }
    float pct = me->GetMaxPower(POWER_MANA) == 0 ? 100 : (float(me->GetPower(POWER_MANA)) * 100.f) / float(me->GetMaxPower(POWER_MANA));
    float m_basemana = float(me->GetCreateMana());
    m_basemana += me->GetTotalStatValue(STAT_INTELLECT) * mana_mult; //remove base stamina (not calculated into mana)
    m_basemana += (m_creatureOwner->GetMaxPower(POWER_MANA) - m_creatureOwner->GetCreateMana()) / 3;
    m_basemana += (GetPetType(me) * mylevel);
    me->SetStatFlatModifier(UNIT_MOD_MANA, BASE_VALUE, m_basemana);
    me->UpdateMaxPower(POWER_MANA);
    me->SetPower(POWER_MANA, uint32(0.5f + float(me->GetMaxPower(POWER_MANA)) * pct / 100.f));//restore pct
}
//Sends all master's bots a message to not try to evade for a certain period of time
//void bot_ai::SendPartyEvadeAbort() const
//{
//    ASSERT(!IAmFree());
//
//    BotMap const* map = master->GetBotMgr()->GetBotMap();
//    for (BotMap::const_iterator itr = map->begin(); itr != map->end(); ++itr)
//        if (Creature* bot = itr->second)
//            if (bot_minion_ai* ai = bot->GetBotMinionAI())
//                ai->SetEvadeTimer(50);
//}
//Removes buggy bots' threat from party, so no 'stuck in combat' bugs form bot mod
//optionally interrupts casted spell if target is dead for bot and it's pet
void bot_minion_ai::Evade(bool force)
{
    if (me->HasUnitState(UNIT_STATE_CASTING))
    {
        for (uint8 i = CURRENT_FIRST_NON_MELEE_SPELL; i != CURRENT_AUTOREPEAT_SPELL; ++i)
            if (Spell* spell = me->GetCurrentSpell(CurrentSpellTypes(i)))
                if (!spell->GetSpellInfo()->IsChanneled())
                    if (Unit* u = spell->m_targets.GetUnitTarget())
                        if (!u->IsAlive() && !IsInBotParty(u))
                            me->InterruptSpell(CurrentSpellTypes(i), false, false);
    }

    Creature* m_botsPet = me->GetBotsPet();
    if (m_botsPet && m_botsPet->HasUnitState(UNIT_STATE_CASTING))
    {
        for (uint8 i = CURRENT_FIRST_NON_MELEE_SPELL; i != CURRENT_AUTOREPEAT_SPELL; ++i)
            if (Spell* spell = m_botsPet->GetCurrentSpell(CurrentSpellTypes(i)))
                if (!spell->GetSpellInfo()->IsChanneled())
                    if (Unit* u = spell->m_targets.GetUnitTarget())
                        if (!u->IsAlive() && !IsInBotParty(u))
                            m_botsPet->InterruptSpell(CurrentSpellTypes(i), false, false);
    }

    if (CCed(me)) return;
    if (!force && Rand() > 10) return;
    EnterEvadeMode(force);
    if (!force && !master->IsInCombat() && !me->IsInCombat() && (!m_botsPet || !m_botsPet->IsInCombat())) return;
    if (!force && CheckAttackTarget(_botclass)) return;

    if (master->IsInCombat() && !IAmFree())
    {
        if (!master->getHostileRefManager().isEmpty())
        {
            GuidSet Set;
            HostileReference* ref = master->getHostileRefManager().getFirst();
            while (ref)
            {
                Set.insert(ref->GetSource()->GetOwner()->GetGUID());
                Set.insert(ref->getUnitGuid());
                ref = ref->next();
            }
            for (GuidSet::const_iterator i = Set.begin(); i != Set.end(); ++i)
            {
                Unit* unit = ObjectAccessor::FindConnectedPlayer(*i);
                if (unit && (unit->IsFriendlyTo(me) || IsInBotParty(unit) || !unit->IsInCombat()))
                {
                    master->getHostileRefManager().deleteReference(unit);
                    //unit->getHostileRefManager().deleteReference(master);
                }
            }
        }

        return;
    }

    if (!master->IsInCombat() || IAmFree())
    {
        if (IAmFree())
        {
            //me->DeleteThreatList();
            if (!me->getHostileRefManager().isEmpty())
            {
                GuidSet Set;
                HostileReference* ref = me->getHostileRefManager().getFirst();
                while (ref)
                {
                    Set.insert(ref->GetSource()->GetOwner()->GetGUID());
                    Set.insert(ref->getUnitGuid());
                    ref = ref->next();
                }
                for (GuidSet::const_iterator i = Set.begin(); i != Set.end(); ++i)
                {
                    Unit* unit = ObjectAccessor::FindConnectedPlayer(*i);
                    if (!unit || !unit->InSamePhase(me)) continue;
                    if (unit->IsFriendlyTo(me) || IsInBotParty(unit) || !unit->IsInCombat())
                    {
                        me->getHostileRefManager().deleteReference(unit);
                        //unit->getHostileRefManager().deleteReference(me);
                    }
                }
            }
            if (Creature* m_botsPet = me->GetBotsPet())
            {
                //m_botsPet->DeleteThreatList();
                if (!m_botsPet->getHostileRefManager().isEmpty())
                {
                    GuidSet Set;
                    HostileReference* ref = m_botsPet->getHostileRefManager().getFirst();
                    while (ref)
                    {
                        Set.insert(ref->GetSource()->GetOwner()->GetGUID());
                        Set.insert(ref->getUnitGuid());
                        ref = ref->next();
                    }
                    for (GuidSet::const_iterator i = Set.begin(); i != Set.end(); ++i)
                    {
                        Unit* unit = ObjectAccessor::FindConnectedPlayer(*i);
                        if (!unit || !unit->InSamePhase(me)) continue;
                        if (unit->IsFriendlyTo(me) || IsInBotParty(unit) || !unit->IsInCombat())
                        {
                            m_botsPet->getHostileRefManager().deleteReference(unit);
                            //unit->getHostileRefManager().deleteReference(m_botsPet);
                        }
                    }
                }
            }

            return;
        }
        //SendPartyEvadeAbort();
        BotMap const* map = master->GetBotMgr()->GetBotMap();
        for (BotMap::const_iterator it = map->begin(); it != map->end(); ++it)
        {
            Creature* cre = it->second;
            if (!cre) continue;
            if (cre->IsInCombat())
            {
                //cre->DeleteThreatList();
                if (!cre->getHostileRefManager().isEmpty())
                {
                    GuidSet Set;
                    HostileReference* ref = cre->getHostileRefManager().getFirst();
                    while (ref)
                    {
                        Set.insert(ref->GetSource()->GetOwner()->GetGUID());
                        Set.insert(ref->getUnitGuid());
                        ref = ref->next();
                    }
                    for (GuidSet::const_iterator i = Set.begin(); i != Set.end(); ++i)
                    {
                        Unit* unit = ObjectAccessor::FindConnectedPlayer(*i);
                        if (!unit || !unit->InSamePhase(me)) continue;
                        if (unit->IsFriendlyTo(me) || IsInBotParty(unit) || !unit->IsInCombat())
                        {
                            cre->getHostileRefManager().deleteReference(unit);
                            //unit->getHostileRefManager().deleteReference(cre);
                        }
                    }
                }
            }

            Creature* m_botsPet = cre->GetBotsPet();
            if (!m_botsPet || !m_botsPet->IsInCombat()) continue;
            //m_botsPet->DeleteThreatList();
            if (!m_botsPet->getHostileRefManager().isEmpty())
            {
                GuidSet Set;
                HostileReference* ref = m_botsPet->getHostileRefManager().getFirst();
                while (ref)
                {
                    Set.insert(ref->GetSource()->GetOwner()->GetGUID());
                    Set.insert(ref->getUnitGuid());
                    ref = ref->next();
                }
                for (GuidSet::const_iterator i = Set.begin(); i != Set.end(); ++i)
                {
                    Unit* unit = ObjectAccessor::FindConnectedPlayer(*i);
                    if (!unit || !unit->InSamePhase(me)) continue;
                    if (unit->IsFriendlyTo(me) || IsInBotParty(unit) || !unit->IsInCombat())
                    {
                        m_botsPet->getHostileRefManager().deleteReference(unit);
                        //unit->getHostileRefManager().deleteReference(m_botsPet);
                    }
                }
            }
        }
    }
}
//SpellHit()... OnSpellHit()
void bot_ai::OnSpellHit(Unit* caster, SpellInfo const* spell)
{
    for (uint8 i = 0; i != MAX_SPELL_EFFECTS; ++i)
    {
        uint32 auraname = spell->Effects[i].ApplyAuraName;
        //remove pet on mount
        if (auraname == SPELL_AURA_MOUNTED)
        {
            me->SetBotsPetDied();
            if (master->HasAuraType(SPELL_AURA_MOD_INCREASE_VEHICLE_FLIGHT_SPEED) ||
                master->HasAuraType(SPELL_AURA_MOD_INCREASE_MOUNTED_FLIGHT_SPEED))
            {
                const_cast<CreatureTemplate*>(me->GetCreatureTemplate())->InhabitType |= INHABIT_AIR;
                //me->AddUnitMovementFlag(MOVEMENTFLAG_HOVER);
                me->SetCanFly(true);
                me->SetDisableGravity(true);
                me->SetSpeed(MOVE_FLIGHT, master->GetSpeedRate(MOVE_FLIGHT) * 1.37f);
                me->SetSpeed(MOVE_RUN, master->GetSpeedRate(MOVE_FLIGHT) * 1.37f);
            }
            else
                me->SetSpeed(MOVE_RUN, master->GetSpeedRate(MOVE_RUN) * 1.25f);
                me->SetSpeed(MOVE_WALK, master->GetSpeedRate(MOVE_RUN) * 1.25f);
        }

        //update stats
        if (auraname == SPELL_AURA_MOD_STAT || auraname == SPELL_AURA_MOD_PERCENT_STAT ||
            auraname == SPELL_AURA_MOD_TOTAL_STAT_PERCENTAGE || auraname == SPELL_AURA_MOD_SKILL ||
            auraname == SPELL_AURA_MOD_ATTACK_POWER || auraname == SPELL_AURA_MOD_ATTACK_POWER_PCT ||
            auraname == SPELL_AURA_MOD_ATTACK_POWER_OF_STAT_PERCENT || auraname == SPELL_AURA_MOD_ATTACK_POWER_OF_ARMOR ||
            auraname == SPELL_AURA_MOD_RATING/* || auraname == SPELL_AURA_MOD_RATING_FROM_STAT*/) //NYI TODO:
        {
            shouldUpdateStats = true;
        }
        else
        {
            if (auraname == SPELL_AURA_MOD_INCREASE_HEALTH ||
                auraname == SPELL_AURA_MOD_INCREASE_HEALTH_2 ||
                auraname == SPELL_AURA_230 ||//SPELL_AURA_MOD_INCREASE_HEALTH_2
                auraname == SPELL_AURA_MOD_INCREASE_HEALTH_PERCENT)
                doHealth = true;
            else if (auraname == SPELL_AURA_MOD_INCREASE_ENERGY ||
                auraname == SPELL_AURA_MOD_INCREASE_ENERGY_PERCENT)
                doMana = true;
        }
    }

    //TODO:
    if (/*!(spell->AttributesEx & SPELL_ATTR1_NO_THREAT) &&
        !(spell->AttributesEx3 & SPELL_ATTR3_NO_INITIAL_AGGRO) &&*/
        IsMinionAI() && /*!CCed(me) && */(me->IsHostileTo(caster) || caster->IsHostileTo(me)))
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
//Messed up
//Hp + Mana update
//target update
//returns fake wait time between overall AI updates (if it is even understandable)
uint8 bot_ai::GetWait(bool bypassGetCount)
{
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
    CheckAuras(true);
    FindMaster();
    //SavePosition();
    if (bypassGetCount)
        return IAmFree() ? 3 : (1 + (irand(0,100) <= 50)*int8(RAND(-1,1)));
    else
    //0 to 2 plus 1 for every 3 bots except first one
        return IAmFree() ? 3 : (1 + (master->GetNpcBotsCount() - 1)/3 + (irand(0,100) <= 50)*int8(RAND(-1,1)));
}
//Damage/Healing Mods
//1) Apply class-specified damage/healing/crit chance/crit damage/crit healing bonuses
//2) Apply bot damage/healing multipliers
//Bug with config reload (creatures do not update their damage on reload) is not bot-related but still annoying
void bot_ai::ApplyBotDamageMultiplierMelee(uint32& damage, CalcDamageInfo& damageinfo) const
{
    //WHITE ATTACKS damage bonus
    ApplyClassDamageMultiplierMelee(damage, damageinfo);
    damage = uint32(damage * _mult_dmg_melee);
}
void bot_ai::ApplyBotDamageMultiplierMelee(int32& damage, SpellNonMeleeDamage& damageinfo, SpellInfo const* spellInfo, WeaponAttackType attackType, bool& crit) const
{
    //MELEE ABILITIES damage/crit bonus
    ApplyClassDamageMultiplierMelee(damage, damageinfo, spellInfo, attackType, crit);
    damage = int32(damage * _mult_dmg_melee);
}
void bot_ai::ApplyBotDamageMultiplierSpell(int32& damage, SpellNonMeleeDamage& damageinfo, SpellInfo const* spellInfo, WeaponAttackType attackType, bool& crit) const
{
    //DAMAGE SPELLS damage/crit bonus
    ApplyClassDamageMultiplierSpell(damage, damageinfo, spellInfo, attackType, crit);
    damage = int32(damage * _mult_dmg_spell);
}
void bot_ai::ApplyBotDamageMultiplierHeal(Unit const* victim, float& heal, SpellInfo const* spellInfo, DamageEffectType damagetype, uint32 stack) const
{
    //HEALING SPELLS amount bonus
    ApplyClassDamageMultiplierHeal(victim, heal, spellInfo, damagetype, stack);
    heal = (heal * _mult_healing);
}
void bot_ai::ApplyBotCritMultiplierAll(Unit const* victim, float& crit_chance, SpellInfo const* spellInfo, SpellSchoolMask schoolMask, WeaponAttackType attackType) const
{
    //ALL SPELLS crit base
    //for base use bot_ai::crit, for healing spells crit bonus use class specified func
    //bonuses for damage spells are handled in ApplyBotDamageMultiplierSpell()
    ApplyClassCritMultiplierHeal(victim, crit_chance, spellInfo, schoolMask, attackType);
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
//////////
//GOSSIP//
//////////
//GossipHello (static)
bool bot_minion_ai::OnGossipHello(Player* player, Creature* creature, uint32 /*option*/)
{
    TC_LOG_DEBUG("entities.player", "entering gossip hello");
    ASSERT(player);
    ASSERT(creature);

    if (!_enableNpcBots || creature->IsInCombat() || bot_ai::CCed(creature) || creature->GetBotAI()->IsDuringTeleport())
    {
        CloseGossipMenuFor(player);
        return true;
    }

    if (creature->GetBotAI()->IsTempBot()) //Blademaster illusion etc.
    {
        CloseGossipMenuFor(player);
        return true;
    }

    if (creature->isMoving())
        creature->StopMoving();

    uint32 gossipTextId = (player->GetGUID().GetCounter() == creature->GetBotAI()->GetBotOwnerGuid() || !creature->GetBotAI()->IAmFree()) ? GOSSIP_SERVE_MASTER : GOSSIP_NEED_SMTH;

    bool menus = false;

    if (player->IsGameMaster() &&
        (creature->IsFreeBot() || player->GetGUID().GetCounter() != creature->GetBotAI()->GetBotOwnerGuid()))
    {
        AddGossipItemFor(player, GOSSIP_ICON_CHAT, "<Debug>", GOSSIP_SENDER_DEBUG, GOSSIP_ACTION_INFO_DEF + 1);
        menus = true;
    }

    if (player->GetGUID().GetCounter() != creature->GetBotAI()->GetBotOwnerGuid())
    {
        if (creature->IsFreeBot() && !player->IsGameMaster())
        {
            uint32 cost = BotMgr::GetNpcBotCost(player->getLevel(), creature);

            int8 reason = 0;
            if (creature->IsHostileTo(player) || player->IsHostileTo(creature) ||
                creature->HasAura(BERSERK))
                reason = -1;
            if (!reason && (player->GetGUID().GetCounter() != creature->GetBotAI()->GetBotOwnerGuid()) && (creature->GetBotAI()->GetBotOwnerGuid() != 0))
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
                    if (itr->second->GetBotClass() == creature->GetBotClass())
                        ++count;

                if (!reason && count >= _maxClassNpcBots)
                    reason = 4;
            }

            if (!reason)
            {
                std::ostringstream message;
                message << "Do you wish to hire " << creature->GetName() << '?';
                player->PlayerTalkClass->GetGossipMenu().AddMenuItem(-1, GOSSIP_ICON_TAXI, "Will you follow me? (hire)",
                    GOSSIP_SENDER_HIRE, GOSSIP_ACTION_INFO_DEF + 0, message.str().c_str(), cost, false);
            }
            else
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "Will you follow me? (hire)", GOSSIP_SENDER_HIRE, GOSSIP_ACTION_INFO_DEF + reason);

            if (creature->GetBotClass() >= BOT_CLASS_EX_START)
                AddGossipItemFor(player, GOSSIP_ICON_TALK, "<Take a better look at this one>", GOSSIP_SENDER_SCAN, GOSSIP_ACTION_INFO_DEF + 1);
            
            //thesawolf - add set faction option to gossip
            AddGossipItemFor(player, GOSSIP_ICON_TALK, "Pick a side! (set faction)", GOSSIP_SENDER_FACTION, GOSSIP_ACTION_INFO_DEF + 1);
            //thesawolf - a delete for good measure
            AddGossipItemFor(player, GOSSIP_ICON_TAXI, "You can go now... (delete)", GOSSIP_SENDER_EARLYDISMISS, GOSSIP_ACTION_INFO_DEF + 1);            

            menus = true;
        }
    }

    if (creature->GetBotAI()->GetBotOwnerGuid())
    {
        Group const* gr = player->GetGroup();

        if (player == creature->GetBotOwner())
        {
            AddGossipItemFor(player, GOSSIP_ICON_TALK, "Manage equipment...", GOSSIP_SENDER_EQUIPMENT, GOSSIP_ACTION_INFO_DEF + 1);
            AddGossipItemFor(player, GOSSIP_ICON_TALK, "Manage roles...", GOSSIP_SENDER_ROLES, GOSSIP_ACTION_INFO_DEF + 1);
            AddGossipItemFor(player, GOSSIP_ICON_TALK, "Manage formation...", GOSSIP_SENDER_FORMATION, GOSSIP_ACTION_INFO_DEF + 1);
            AddGossipItemFor(player, GOSSIP_ICON_TALK, "Use ability...", GOSSIP_SENDER_ABILITIES, GOSSIP_ACTION_INFO_DEF + 1);
            if (creature->GetBotClass() >= BOT_CLASS_EX_START)
                AddGossipItemFor(player, GOSSIP_ICON_TALK, "Abilities status...", GOSSIP_SENDER_SCAN_OWNER, GOSSIP_ACTION_INFO_DEF + 1);

            if (!gr)
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "<Create group>", GOSSIP_SENDER_JOIN_GROUP, GOSSIP_ACTION_INFO_DEF + 1);
            else if (!gr->IsMember(creature->GetGUID()))
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "<Add to group>", GOSSIP_SENDER_JOIN_GROUP, GOSSIP_ACTION_INFO_DEF + 2);
            else
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "<Remove from group>", GOSSIP_SENDER_LEAVE_GROUP, GOSSIP_ACTION_INFO_DEF + 1);

            menus = true;
        }
        if (player == creature->GetBotOwner() || (gr && gr->IsMember(creature->GetBotOwner()->GetGUID())))
        {
            switch (creature->GetBotClass())
            {
                case BOT_CLASS_MAGE:
                    AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "I need food", GOSSIP_SENDER_CLASS, GOSSIP_ACTION_INFO_DEF + 1);
                    AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "I need drink", GOSSIP_SENDER_CLASS, GOSSIP_ACTION_INFO_DEF + 2);
                    AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "Can we get a refreshment table?", GOSSIP_SENDER_TABLE, GOSSIP_ACTION_INFO_DEF + 3);
                    AddGossipItemFor(player, GOSSIP_ICON_TRAINER, "Can we get a portal?", GOSSIP_SENDER_PORTAL, GOSSIP_ACTION_INFO_DEF + 4);
                    menus = true;
                    break;
                case BOT_CLASS_WARLOCK:
                    AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "I need a healthstone", GOSSIP_SENDER_CLASS, GOSSIP_ACTION_INFO_DEF + 1);
                    AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "I need a firestone", GOSSIP_SENDER_CLASS, GOSSIP_ACTION_INFO_DEF + 2);
                    AddGossipItemFor(player, GOSSIP_ICON_TRAINER, "Can we get a soulwell?", GOSSIP_SENDER_SOULWELL, GOSSIP_ACTION_INFO_DEF + 3);
                    menus = true;
                    break;
                default:
                    break;
            }
        }

        if (player == creature->GetBotOwner())
        {
            std::ostringstream astr;
            astr << "Are you going to DISMISS " << creature->GetName() << "?";
            player->PlayerTalkClass->GetGossipMenu().AddMenuItem(-1, GOSSIP_ICON_TAXI, "You are dismissed",
                GOSSIP_SENDER_DISMISS, GOSSIP_ACTION_INFO_DEF + 1, astr.str().c_str(), 0, false);

            std::ostringstream rstr;
            rstr << "Are you going to RELEASE " << creature->GetName() << "?";
            player->PlayerTalkClass->GetGossipMenu().AddMenuItem(-1, GOSSIP_ICON_TAXI, "You are free to go (reset owner)",
                GOSSIP_SENDER_RELEASE, GOSSIP_ACTION_INFO_DEF + 1, rstr.str().c_str(), 0, false);

            std::ostringstream fstr;
            fstr << "Are you going to FIRE " << creature->GetName() << "?!";
            player->PlayerTalkClass->GetGossipMenu().AddMenuItem(-1, GOSSIP_ICON_TAXI, "You are fired! (remove)",
                GOSSIP_SENDER_FIRE, GOSSIP_ACTION_INFO_DEF + 1, fstr.str().c_str(), 0, false);

            menus = true;
        }
    }

    if (menus)
        AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Nevermind", 0, GOSSIP_ACTION_INFO_DEF + 1);

    player->PlayerTalkClass->SendGossipMenu(gossipTextId, creature->GetGUID());
    return true;
}

//GossipSelect
bool bot_minion_ai::OnGossipSelect(Player* player, Creature* creature/* == me*/, uint32 sender, uint32 action)
{
    TC_LOG_DEBUG("entities.player", "entering gossip select");
    //if (!IsInBotParty(player))
    //{
    //    CloseGossipMenuFor(player);
    //    return true;
    //}

    if (!_enableNpcBots || CCed(me) || IsDuringTeleport())
    {
        CloseGossipMenuFor(player);
        return true;
    }

    uint32 gossipTextId = (player->GetGUID().GetCounter() == _ownerGuid || !IAmFree()) ? GOSSIP_SERVE_MASTER : GOSSIP_NEED_SMTH;

    player->PlayerTalkClass->ClearMenus();
    bool subMenu = false;

    switch (sender)
    {
        case 0: //any kind of fail
        {
            me->HandleEmoteCommand(EMOTE_ONESHOT_NO);
            BotSay("Ok then...", player);
            break;
        }
        case 1: //return to main menu
        {
            return bot_minion_ai::OnGossipHello(player, creature, 0);
        }
        case GOSSIP_SENDER_RELEASE:
        {
            //thesawolf - release npcbot (reset owner)
            if (!IAmFree())
                master->GetBotMgr()->RemoveBot(me->GetGUID(), BOT_REMOVE_DISMISS);
            else
            {
                ResetBotAI(BOTAI_RESET_DISMISS);
                PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_NPCBOT_OWNER);
                //"UPDATE characters_npcbot SET owner = ? WHERE entry = ?", CONNECTION_ASYNC
                stmt->setUInt32(0, uint32(0));
                stmt->setUInt32(1, me->GetEntry());
                CharacterDatabase.Execute(stmt);
                me->HandleEmoteCommand(EMOTE_ONESHOT_NONE);
                me->HandleEmoteCommand(EMOTE_ONESHOT_FLEX);
                BotSay("I'm out of here!", player);
            }
            break;        
        }
        case GOSSIP_SENDER_EARLYDISMISS:
        {
            //thesawolf - early dismissal/delete
            me->HandleEmoteCommand(EMOTE_ONESHOT_NONE);
            me->HandleEmoteCommand(EMOTE_ONESHOT_FLEX);
            BotSay("We would've been good together...", player);
            me->CombatStop();
            me->DeleteFromDB();
            me->AddObjectToRemoveList();
            uint32 id = me->GetEntry();
            
            PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_NPCBOT);
            //"DELETE FROM characters_npcbot WHERE entry = ?", CONNECTION_ASYNC
            stmt->setUInt32(0, id);
            CharacterDatabase.Execute(stmt);

            break;
        }
        case GOSSIP_SENDER_FACTION: //thesawolf - set faction from gossip
        {
            subMenu = true;
            
            AddGossipItemFor(player, GOSSIP_ICON_TABARD, "Alliance", GOSSIP_SENDER_FACTION_ALLIANCE, GOSSIP_ACTION_INFO_DEF + 1);
            AddGossipItemFor(player, GOSSIP_ICON_BATTLE, "Horde", GOSSIP_SENDER_FACTION_HORDE, GOSSIP_ACTION_INFO_DEF + 1);
            AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "Monster", GOSSIP_SENDER_FACTION_MONSTER, GOSSIP_ACTION_INFO_DEF + 1);
            AddGossipItemFor(player, GOSSIP_ICON_TRAINER, "Friend to all", GOSSIP_SENDER_FACTION_FRIEND, GOSSIP_ACTION_INFO_DEF + 1);
            AddGossipItemFor(player, GOSSIP_ICON_TALK, "(BACK)", 1, GOSSIP_ACTION_INFO_DEF + 1);

            break;
        }
        case GOSSIP_SENDER_FACTION_ALLIANCE: //set alliance
        {
            uint32 faction = 1802;
            me->SetFaction(faction);
            PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_NPCBOT_FACTION);
            //"UPDATE characters_npcbot SET faction = ? WHERE entry = ?", CONNECTION_SYNCH
            stmt->setUInt32(0, faction);
            stmt->setUInt32(1, me->GetEntry());
            CharacterDatabase.DirectExecute(stmt);
            
            const_cast<CreatureTemplate*>(me->GetCreatureTemplate())->faction = faction;
            me->HandleEmoteCommand(EMOTE_ONESHOT_NONE);
            me->HandleEmoteCommand(EMOTE_ONESHOT_SALUTE);
            BotSay("For the Alliance!", player);
            break;
        }
        case GOSSIP_SENDER_FACTION_HORDE: //set horde
        {
            uint32 faction = 1801;
            me->SetFaction(faction);
            PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_NPCBOT_FACTION);
            //"UPDATE characters_npcbot SET faction = ? WHERE entry = ?", CONNECTION_SYNCH
            stmt->setUInt32(0, faction);
            stmt->setUInt32(1, me->GetEntry());
            CharacterDatabase.DirectExecute(stmt);
                        
            const_cast<CreatureTemplate*>(me->GetCreatureTemplate())->faction = faction;
            me->HandleEmoteCommand(EMOTE_ONESHOT_ROAR);
            BotSay("For the Horde!", player);
            break;
        }
        case GOSSIP_SENDER_FACTION_MONSTER: //set monster
        {
            uint32 faction = 14;
            me->SetFaction(faction);
            PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_NPCBOT_FACTION);
            //"UPDATE characters_npcbot SET faction = ? WHERE entry = ?", CONNECTION_SYNCH
            stmt->setUInt32(0, faction);
            stmt->setUInt32(1, me->GetEntry());
            CharacterDatabase.DirectExecute(stmt);
                        
            const_cast<CreatureTemplate*>(me->GetCreatureTemplate())->faction = faction;
            me->HandleEmoteCommand(EMOTE_ONESHOT_RUDE);
            BotSay("I hate everyone!", player);
            break;
        }
        case GOSSIP_SENDER_FACTION_FRIEND: //set friendly to all
        {
            uint32 faction = 35;
            me->SetFaction(faction);
            PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_NPCBOT_FACTION);
            //"UPDATE characters_npcbot SET faction = ? WHERE entry = ?", CONNECTION_SYNCH
            stmt->setUInt32(0, faction);
            stmt->setUInt32(1, me->GetEntry());
            CharacterDatabase.DirectExecute(stmt);
                        
            const_cast<CreatureTemplate*>(me->GetCreatureTemplate())->faction = faction;
            me->HandleEmoteCommand(EMOTE_ONESHOT_FLEX);
            BotSay("Everyone loves me!", player);
            break;
        }
        case GOSSIP_SENDER_PORTAL: //thesawolf - add in group portals for mages
        {
            subMenu = true;

            //thesawolf - need to do faction/level-specific portals listing
            uint32 portside = player->GetFaction();
            uint32 plevel = player->getLevel();

            if (plevel < 40) // level check
            {
                BotWhisper("I can't summon portals yet.. sorry.", player);
                //player->PlayerTalkClass->ClearMenus();
                //return OnGossipHello(player, me);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "BACK", 1, GOSSIP_ACTION_INFO_DEF + 1);
                break;            
            } 
                        
            switch (portside) // faction check
            {
                case 1:
                case 3:
                case 4:
                case 115:
                case 1629: //alliance portals
                {
                    subMenu = true;
                    
                    AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Stormwind City", GOSSIP_SENDER_PORTCHOICE, GOSSIP_ACTION_INFO_DEF + 1);
                    AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Ironforge",  GOSSIP_SENDER_PORTCHOICE, GOSSIP_ACTION_INFO_DEF + 2);
                    AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Darnassus",  GOSSIP_SENDER_PORTCHOICE, GOSSIP_ACTION_INFO_DEF + 3);
                    AddGossipItemFor(player, GOSSIP_ICON_CHAT, "The Exodar",  GOSSIP_SENDER_PORTCHOICE, GOSSIP_ACTION_INFO_DEF + 4);
                    AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Theramore",  GOSSIP_SENDER_PORTCHOICE, GOSSIP_ACTION_INFO_DEF + 5);
                    if (plevel > 65) 
                    {
                        AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Shattrath City",  GOSSIP_SENDER_PORTCHOICE, GOSSIP_ACTION_INFO_DEF + 6);
                    }
                    if (plevel > 73)
                    {
                        AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Dalaran",  GOSSIP_SENDER_PORTCHOICE, GOSSIP_ACTION_INFO_DEF + 7);
                    }
                    AddGossipItemFor(player, GOSSIP_ICON_TALK, "(BACK)", 1, GOSSIP_ACTION_INFO_DEF + 1); 
                    break;
                }
                case 2:
                case 5:
                case 6:
                case 116:
                case 1610: //horde portals
                {
                    subMenu = true;
                    
                    AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Orgrimmar", GOSSIP_SENDER_PORTCHOICE, GOSSIP_ACTION_INFO_DEF + 8);
                    AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Thunder Bluff",  GOSSIP_SENDER_PORTCHOICE, GOSSIP_ACTION_INFO_DEF + 9);
                    AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Undercity",  GOSSIP_SENDER_PORTCHOICE, GOSSIP_ACTION_INFO_DEF + 10);
                    AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Silvermoon City",  GOSSIP_SENDER_PORTCHOICE, GOSSIP_ACTION_INFO_DEF + 11);
                    AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Stonard",  GOSSIP_SENDER_PORTCHOICE, GOSSIP_ACTION_INFO_DEF + 12);
                    if (plevel > 65)
                    {
                        AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Shattrath City",  GOSSIP_SENDER_PORTCHOICE, GOSSIP_ACTION_INFO_DEF + 13);
                    }
                    if (plevel > 73)
                    {
                        AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Dalaran",  GOSSIP_SENDER_PORTCHOICE, GOSSIP_ACTION_INFO_DEF + 14);
                    }
                    AddGossipItemFor(player, GOSSIP_ICON_TALK, "(BACK)", 1, GOSSIP_ACTION_INFO_DEF + 1);
                    break;
                }
                default:
                    break;
            }
            break;
        }
        case GOSSIP_SENDER_PORTCHOICE: //thesawolf - do the actual porting for mages
        {
            std::string locname;
            uint32 portdest = 0;
            
            switch (action - GOSSIP_ACTION_INFO_DEF)
            {
                case 1:
                {
                    portdest = 176296;
                    locname = "Stormwind City";
                    break;
                }
                case 2:
                {
                    portdest = 176497;
                    locname = "Ironforge";
                    break;
                }
                case 3:
                {
                    portdest = 176498;
                    locname = "Darnassus";
                    break;
                }
                case 4:
                {
                    portdest = 182351;
                    locname = "Exodar";
                    break;
                }
                case 5:
                {
                    portdest = 189993;
                    locname = "Theramore";
                    break;
                }
                case 6: 
                {
                    portdest = 184594;
                    locname = "Shattrath City";
                    break;
                }
                case 7:
                case 14:
                {
                    portdest = 195682;
                    locname = "Dalaran";
                    break;
                }
                case 8:
                {
                    portdest = 176499;
                    locname = "Orgrimmar";
                    break;
                }
                case 9:
                {
                    portdest = 176500;
                    locname = "Thunder Bluff";
                    break;
                }
                case 10:
                {
                    portdest = 176501;
                    locname = "Undercity";
                    break;
                }
                case 11:
                {
                    portdest = 182352;
                    locname = "Silvermoon City";
                    break;
                }
                case 12:
                {
                    portdest = 189994;
                    locname = "Stonard";
                    break;
                }
                case 13:
                {
                    portdest = 184594;
                    locname = "Shattrath City";
                    break;
                }
                default:
                    break;
            }

            InitSpellMap(7078);
                        
            if (!doCast(me, 7078))
            {
                BotSay("Oops! Something went wrong!", player);
            }
            else
            {
                //thesawolf - It works.. but not group clickable due to npcbot pseudo-group
                // so made a hacky way by making it a gameobject by player with 90s removal
                if (GameObject* go = player->SummonGameObject(portdest, me->GetPositionX()+2, me->GetPositionY(), me->GetPositionZ(), me->GetOrientation(), QuaternionData(), 90))
                PlaySound(TEXT_EMOTE_TRAIN);
                std::ostringstream chootext;
                chootext << "All aboard the " << locname << " Express!";
                BotYell(chootext.str().c_str(), player);
            }
            break;
        }        
        case GOSSIP_SENDER_SOULWELL: //thesawolf - add in soulwell for locks
        {
            subMenu = true;

            uint32 plevel = player->getLevel();

            if (plevel < 70) // level check
            {
                BotWhisper("I can't create soulwells yet.. sorry.", player);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "BACK", 1, GOSSIP_ACTION_INFO_DEF + 1);
                break;            
            } 
                        
            InitSpellMap(29893);
            if (!doCast(me, 29893))
            {
                BotWhisper("Oops! Something went wrong!", player);
            }
            else
            {
                uint32 wwell;
                if (plevel >= 79)
                    wwell = 193169; // well for lvl 79 stones
                else 
                    wwell = 181621; //well for lvl 70 stones

                //thesawolf - It works.. but not group clickable due to npcbot pseudo-group
                // so made a hacky way by making it a gameobject by player with 2 min removal
                if (GameObject* go = player->SummonGameObject(wwell, me->GetPositionX()+1, me->GetPositionY(), me->GetPositionZ(), me->GetOrientation(), QuaternionData(), 120))
                PlaySound(TEXT_EMOTE_TRAIN);
                BotYell("Get your stones from the soulwell here!", player);
            }
            break;
        }        
        case GOSSIP_SENDER_TABLE: //thesawolf - add in mage table for mages
        {
            subMenu = true;

            uint32 plevel = player->getLevel();

            if (plevel < 72) // level check
            {
                BotWhisper("I can't create refreshment tables yet.. sorry.", player);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "BACK", 1, GOSSIP_ACTION_INFO_DEF + 1);
                break;            
            } 
                        
            InitSpellMap(43987);
            if (!doCast(me, 43987))
            {
                BotWhisper("Oops! Something went wrong!", player);
            }
            else
            {
                uint32 wtable;
                if (plevel >= 80)
                    wtable = 193061; // table with lvl 80 food
                else
                    wtable = 186812; // table with lvl 65 food

                //thesawolf - It works.. but not group clickable due to npcbot pseudo-group
                // so made a hacky way by making it a gameobject by player with 3 min removal
                if (GameObject* go = player->SummonGameObject(wtable, me->GetPositionX()+1, me->GetPositionY(), me->GetPositionZ(), me->GetOrientation(), QuaternionData(), 180))
                PlaySound(TEXT_EMOTE_TRAIN);
                BotYell("Get your yummies from the table here!", player);
            }
            break;
        }        
        case GOSSIP_SENDER_CLASS: //food/drink (classes: MAGE)
        {
            switch (_botclass)
            {
                case BOT_CLASS_MAGE:
                {
                    //Prevent high-leveled consumables for low-level characters
                    Unit* checker;
                    if (player->getLevel() < me->getLevel())
                        checker = player;
                    else
                        checker = me;

                    // Conjure Refreshment rank 1
                    uint32 food = InitSpell(checker, 42955);
                    bool iswater = (action == GOSSIP_ACTION_INFO_DEF + 2);
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
                        break;
                    }
                    SpellInfo const* Info = sSpellMgr->GetSpellInfo(food);
                    Spell* foodspell = new Spell(me, Info, TRIGGERED_NONE, player->GetGUID());
                    SpellCastTargets targets;
                    targets.SetUnitTarget(player);
                    //TODO implement checkcast for bots
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
                        foodspell->prepare(&targets); 
                        //thesawolf - fix for straight-to-inventory summoning
                        if (aftercastTargetGuid)
                        {
                            std::string summonstr = "Summoning ";
                            summonstr += iswater ? "water" : "food";
                            summonstr +=" for you...";
                            BotWhisper(summonstr.c_str(), player);
                            Player* pTarget = ObjectAccessor::FindPlayer(aftercastTargetGuid);
                            aftercastTargetGuid.Clear();

                            if (!pTarget/* || me->GetDistance(pTarget) > 15*/)
                            {
                                BotWhisper("You are too far away for me to give you this..", player);
                                break;
                            }

                            //handle effects
                            for (uint8 i = 0; i != MAX_SPELL_EFFECTS; ++i)
                            {
                                switch (Info->Effects[i].Effect)
                                {
                                    case SPELL_EFFECT_CREATE_ITEM:
                                    case SPELL_EFFECT_CREATE_ITEM_2:
                                    {
                                        uint32 newitemid = Info->Effects[i].ItemType;
                                        if (newitemid)
                                        {
                                            ItemPosCountVec dest;
                                            ItemTemplate const* pProto = sObjectMgr->GetItemTemplate(newitemid);
                                            if (!pProto)
                                                break;
                                            uint32 count = pProto->GetMaxStackSize();
                                            uint32 no_space = 0;
                                            InventoryResult msg = pTarget->CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, newitemid, count, &no_space);
                                            if (msg != EQUIP_ERR_OK)
                                            {
                                                if (msg == EQUIP_ERR_INVENTORY_FULL || msg == EQUIP_ERR_CANT_CARRY_MORE_OF_THIS)
                                                {
                                                    BotWhisper("No space in your bags!", player);                                
                                                    count -= no_space;
                                                }
                                                else
                                                {
                                                    // if not created by another reason from full inventory or unique items amount limitation
                                                    BotWhisper("There was an issue giving this to you!", player);                                
                                                    pTarget->SendEquipError(msg, NULL, NULL, newitemid);
                                                    continue;
                                                }
                                            }
                                            if (count)
                                            {
                                                Item* pItem = pTarget->StoreNewItem(dest, newitemid, true, Item::GenerateItemRandomPropertyId(newitemid));
                                                if (!pItem)
                                                {
                                                    BotWhisper("Can't seem to find the item now to give to you!", player);                                
                                                    pTarget->SendEquipError(EQUIP_ERR_ITEM_NOT_FOUND, NULL, NULL);
                                                    continue;
                                                }
                                                //unsafe possible
                                                pItem->SetUInt32Value(ITEM_FIELD_CREATOR, me->GetGUID().GetCounter());
                                                        
                                                pTarget->SendNewItem(pItem, count, true, false, true);
                                                BotWhisper("Here you go...", player);
                                            }
                                        }
                                        break;
                                    }
                                    default:
                                        break;
                                }
                            }
                            break;
                        }
                    }
                    break;
                }
                case BOT_CLASS_WARLOCK: //thesawolf - stone summoning 
                {
                    //Prevent high-leveled consumables for low-level characters
                    Unit* checker;
                    if (player->getLevel() < me->getLevel())
                        checker = player;
                    else
                        checker = me;

                    // Create Healthstone
                    uint32 stone = InitSpell(checker, 34130/*6201*/);
                    bool isfire = (action == GOSSIP_ACTION_INFO_DEF + 2);
                    if (!isfire)// Create Healthstone
                    {
                        //thesawolf - issue with rank healthstone conjuring
                        // doesn't go to inventory.. only these 2 stones are working
                        // FIXME
                        if(player->getLevel() < 69)
                        { 
                            stone = InitSpell(checker, 34130); //lvl 60 stone
                        }
                        else
                        {
                            stone = InitSpell(checker, 58890); //lvl 69 stone
                        }
                    }
                    else// Create Firestone
                        stone = InitSpell(checker, 6366);

                    if (!stone)
                    {
                        std::string stonestr = "I can't create ";
                        stonestr += isfire ? "fire" : "health";
                        stonestr += "stones yet...";
                        BotWhisper(stonestr.c_str(), player);
                        break;
                    }
                    SpellInfo const* Info = sSpellMgr->GetSpellInfo(stone);
                    Spell* stonespell = new Spell(me, Info, TRIGGERED_NONE, player->GetGUID());
                    SpellCastTargets targets;
                    targets.SetUnitTarget(player);
                    //TODO implement checkcast for bots
                    SpellCastResult result = me->IsMounted() || CCed(me) ? SPELL_FAILED_CUSTOM_ERROR : stonespell->CheckPetCast(player);
                    if (result != SPELL_CAST_OK)
                    {
                        stonespell->finish(false);
                        delete stonespell;
                        BotWhisper("I can't do it right now", player);
                    }
                    else
                    {
                        aftercastTargetGuid = player->GetGUID();
                        stonespell->prepare(&targets);

                        //thesawolf - kludgy fix to healthstones.. can't find a spell
                        //that actually makes the stones.. just the cast effect OR just a stone
                        if (!isfire) 
                        {
                            stone = InitSpell(checker, 6201); // this is only for appearance
                            SpellInfo const* Info = sSpellMgr->GetSpellInfo(stone);
                            Spell* stonespell = new Spell(me, Info, TRIGGERED_NONE, player->GetGUID());
                            SpellCastTargets targets;
                            targets.SetUnitTarget(player);                            
                            stonespell->prepare(&targets);
                        } 
                        //thesawolf - fix straight-to-inventory summoning
                        if (aftercastTargetGuid)
                        {
                            std::string wstonestr = "Creating ";
                            wstonestr += isfire ? "fire" : "health";
                            wstonestr += "stone for you...";
                            BotWhisper(wstonestr.c_str(), player);
                            Player* pTarget = ObjectAccessor::FindPlayer(aftercastTargetGuid);
                            aftercastTargetGuid.Clear();

                            if (!pTarget/* || me->GetDistance(pTarget) > 15*/)
                            {
                                BotWhisper("You are too far away for me to give you this..", player);
                                break;
                            }

                            //handle effects
                            for (uint8 i = 0; i != MAX_SPELL_EFFECTS; ++i)
                            {
                                switch (Info->Effects[i].Effect)
                                {
                                    case SPELL_EFFECT_CREATE_ITEM:
                                    case SPELL_EFFECT_CREATE_ITEM_2:
                                    {
                                        uint32 newitemid = Info->Effects[i].ItemType;
                                        if (newitemid)
                                        {
                                            ItemPosCountVec dest;
                                            ItemTemplate const* pProto = sObjectMgr->GetItemTemplate(newitemid);
                                            if (!pProto)
                                                break;
                                            uint32 count = pProto->GetMaxStackSize();
                                            uint32 no_space = 0;
                                            InventoryResult msg = pTarget->CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, newitemid, count, &no_space);
                                            if (msg != EQUIP_ERR_OK)
                                            {
                                                if (msg == EQUIP_ERR_INVENTORY_FULL) 
                                                {
                                                    BotWhisper("No space in your bags!", player);                                
                                                    count -= no_space;
                                                }
                                                else if (msg == EQUIP_ERR_CANT_CARRY_MORE_OF_THIS)
                                                {
                                                    BotWhisper("You can only have one of those at a time!", player);
                                                    count -= no_space;
                                                }
                                                else
                                                {
                                                    // if not created by another reason from full inventory or unique items amount limitation
                                                    //BotWhisper("There was an issue giving this to you!", player);                                
                                                    /*
                                                    std::string dstone = "DEBUG: ";
                                                    dstone += msg;
                                                    dstone += " equip error";
                                                    BotWhisper(dstone.c_str(), player);
                                                    */
                                                    pTarget->SendEquipError(msg, NULL, NULL, newitemid);
                                                    continue;
                                                }
                                            }
                                            if (count)
                                            {
                                                Item* pItem = pTarget->StoreNewItem(dest, newitemid, true, Item::GenerateItemRandomPropertyId(newitemid));
                                                if (!pItem)
                                                {
                                                    BotWhisper("Can't seem to find the item now to give to you!", player);                                
                                                    pTarget->SendEquipError(EQUIP_ERR_ITEM_NOT_FOUND, NULL, NULL);
                                                    continue;
                                                }
                                                //unsafe possible
                                                pItem->SetUInt32Value(ITEM_FIELD_CREATOR, me->GetGUID().GetCounter());
                                                        
                                                pTarget->SendNewItem(pItem, count, true, false, true);
                                                BotWhisper("Here you go...", player);
                                            }
                                        }
                                        break;
                                    }
                                    default:
                                        break;
                                }
                            }
                            break;
                        }
                    }
                    break;
                }
                default:
                    break;
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
            else
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
            AddGossipItemFor(player, GOSSIP_ICON_TALK, "Back...", GOSSIP_SENDER_EQUIPMENT_SHOW, GOSSIP_ACTION_INFO_DEF + BOT_SLOT_BACK);
            AddGossipItemFor(player, GOSSIP_ICON_TALK, "Shirt...", GOSSIP_SENDER_EQUIPMENT_SHOW, GOSSIP_ACTION_INFO_DEF + BOT_SLOT_BODY);
            AddGossipItemFor(player, GOSSIP_ICON_TALK, "Finger1...", GOSSIP_SENDER_EQUIPMENT_SHOW, GOSSIP_ACTION_INFO_DEF + BOT_SLOT_FINGER1);
            AddGossipItemFor(player, GOSSIP_ICON_TALK, "Finger2...", GOSSIP_SENDER_EQUIPMENT_SHOW, GOSSIP_ACTION_INFO_DEF + BOT_SLOT_FINGER2);
            AddGossipItemFor(player, GOSSIP_ICON_TALK, "Trinket1...", GOSSIP_SENDER_EQUIPMENT_SHOW, GOSSIP_ACTION_INFO_DEF + BOT_SLOT_TRINKET1);
            AddGossipItemFor(player, GOSSIP_ICON_TALK, "Trinket2...", GOSSIP_SENDER_EQUIPMENT_SHOW, GOSSIP_ACTION_INFO_DEF + BOT_SLOT_TRINKET2);
            AddGossipItemFor(player, GOSSIP_ICON_TALK, "Neck...", GOSSIP_SENDER_EQUIPMENT_SHOW, GOSSIP_ACTION_INFO_DEF + BOT_SLOT_NECK);

            //if (player->IsGameMaster())
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Unequip all", GOSSIP_SENDER_UNEQUIP_ALL, GOSSIP_ACTION_INFO_DEF + 1);

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

            for (uint8 i = 0; i != BOT_INVENTORY_SIZE; ++i)
            {
                Item* item = _equips[i];
                if (!item) continue;
                std::ostringstream msg;
                _AddItemLink(player, item, msg);
                msg << " in slot " << uint32(i) << " (" << _getNameForSlot(i + 1) << ')';
                if (i < BOT_SLOT_RANGED && einfo->ItemEntry[i] == item->GetEntry())
                    msg << " |cffe6cc80|h[!standard item!]|h|r";
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

            uint8 slot = action - (GOSSIP_ACTION_INFO_DEF + 1);
            Item* item = _equips[slot];
            ASSERT(item);

            std::ostringstream msg;
            _AddItemLink(player, item, msg);

            if (slot < BOT_SLOT_RANGED && einfo->ItemEntry[slot] == item->GetEntry())
                msg << " |cffe6cc80|h[!standard item!]|h|r";

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
                if (Item* pItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, i))
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
                    if (_canEquip(pItem->GetTemplate(), action - GOSSIP_ACTION_INFO_DEF, true) && itemList.find(pItem->GetGUID().GetCounter()) == itemList.end() && idsList.find(pItem->GetEntry()) == idsList.end())
                    {
                        itemList.insert(pItem->GetGUID().GetCounter());
                        idsList.insert(pItem->GetEntry());
                    }
                }
            }

            //s2.1.2: other bags
            for (uint8 i = INVENTORY_SLOT_BAG_START; i != INVENTORY_SLOT_BAG_END; i++)
            {
                if (Bag* pBag = player->GetBagByPos(i))
                {
                    for (uint32 j = 0; j != pBag->GetBagSize(); j++)
                    {
                        if (Item* pItem = player->GetItemByPos(i, j))
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
                            if (_canEquip(pItem->GetTemplate(), action - GOSSIP_ACTION_INFO_DEF, true) && itemList.find(pItem->GetGUID().GetCounter()) == itemList.end() && idsList.find(pItem->GetEntry()) == idsList.end())
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
            uint8 slot = action - (GOSSIP_ACTION_INFO_DEF + 1);
            std::ostringstream str;
            str << "Equipped: ";
            if (Item* item = _equips[slot])
            {
                _AddItemLink(player, item, str);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, str.str().c_str(), GOSSIP_SENDER_EQUIPMENT_INFO, action);
            }
            else
            {
                str << "nothing";
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, str.str().c_str(), GOSSIP_SENDER_EQUIPMENT_SHOW, action);
            }

            //s2.2.1 add unequip option if have weapon (GMs only) removed GM only
            if (action - GOSSIP_ACTION_INFO_DEF <= BOT_SLOT_RANGED)
                //if (player->IsGameMaster())
                    AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Use your old equipment", GOSSIP_SENDER_EQUIP_RESET, action);

            //s2.2.2 add unequip option for non-weapons
            if (slot >= BOT_SLOT_RANGED && _equips[slot])
                //if (player->IsGameMaster())
                    AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Unequip it", GOSSIP_SENDER_UNEQUIP, action);

            //s2.2.3a: add an empty submenu with info if no items are found
            if (itemList.empty())
            {
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Hm... I have nothing to give you", 0, GOSSIP_ACTION_INFO_DEF + 1);
            }
            else
            {
                uint32 counter = 0;
                uint32 maxcounter = GOSSIP_MAX_MENU_ITEMS - 4; //unequip, reset, current, back
                uint32 slot = action - GOSSIP_ACTION_INFO_DEF;
                Item* item;
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
                            AddGossipItemFor(player, GOSSIP_ICON_CHAT, name.str().c_str(), GOSSIP_SENDER_EQUIP + (slot - 1), GOSSIP_ACTION_INFO_DEF + item->GetGUID().GetCounter());
                            ++counter;
                            found = true;
                            break;
                        }
                    }

                    if (found)
                        continue;

                    for (uint8 i = INVENTORY_SLOT_BAG_START; i != INVENTORY_SLOT_BAG_END; i++)
                    {
                        if (Bag* pBag = player->GetBagByPos(i))
                        {
                            for (uint32 j = 0; j != pBag->GetBagSize(); j++)
                            {
                                item = player->GetItemByPos(i, j);
                                if (item && item->GetGUID().GetCounter() == (*itr))
                                {
                                    std::ostringstream name;
                                    _AddItemLink(player, item, name);
                                    AddGossipItemFor(player, GOSSIP_ICON_CHAT, name.str().c_str(), GOSSIP_SENDER_EQUIP + (slot - 1), GOSSIP_ACTION_INFO_DEF + item->GetGUID().GetCounter());
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
            if (_unequip(action - (GOSSIP_ACTION_INFO_DEF + 1)))
                BotSay("Hm...", player);
            break;
        }
        case GOSSIP_SENDER_UNEQUIP_ALL:
        {
            bool suc = true;
            for (uint8 i = 0; i != BOT_INVENTORY_SIZE; ++i)
            {
                if (!(i < BOT_SLOT_RANGED ? _resetEquipment(i) : _unequip(i)))
                {
                    suc = false;
                    std::ostringstream estr;
                    estr << "Cannot reset equipment in slot " << uint32(i) << " (" << _getNameForSlot(i + 1) << ")!";
                    BotWhisper(estr.str().c_str(), player);
                }

                if (suc)
                    me->HandleEmoteCommand(EMOTE_ONESHOT_CRY);
            }
            break;
        }
        //autoequips change s5b: AtoEquip item
        //base is GOSSIP_SENDER_EQUIP_AUTOEQUIP + 0...1...2... etc.
        case GOSSIP_SENDER_EQUIP_AUTOEQUIP_MHAND:     //1 - 1 main hand
        case GOSSIP_SENDER_EQUIP_AUTOEQUIP_OHAND:     //2 - 1 off hand
        case GOSSIP_SENDER_EQUIP_AUTOEQUIP_RANGED:    //3 - 1 ranged
        case GOSSIP_SENDER_EQUIP_AUTOEQUIP_HEAD:      //4 - 1 head
        case GOSSIP_SENDER_EQUIP_AUTOEQUIP_SHOULDERS: //5 - 1 shoulders
        case GOSSIP_SENDER_EQUIP_AUTOEQUIP_CHEST:     //6 - 1 chest
        case GOSSIP_SENDER_EQUIP_AUTOEQUIP_WAIST:     //7 - 1 waist
        case GOSSIP_SENDER_EQUIP_AUTOEQUIP_LEGS:      //8 - 1 legs
        case GOSSIP_SENDER_EQUIP_AUTOEQUIP_FEET:      //9 - 1 feet
        case GOSSIP_SENDER_EQUIP_AUTOEQUIP_WRIST:     //10 - 1 wrist
        case GOSSIP_SENDER_EQUIP_AUTOEQUIP_HANDS:     //11 - 1 hands
        case GOSSIP_SENDER_EQUIP_AUTOEQUIP_BACK:      //12 - 1 back
        case GOSSIP_SENDER_EQUIP_AUTOEQUIP_BODY:      //13 - 1 body
        case GOSSIP_SENDER_EQUIP_AUTOEQUIP_FINGER1:   //14 - 1 finger
        case GOSSIP_SENDER_EQUIP_AUTOEQUIP_FINGER2:   //15 - 1 finger
        case GOSSIP_SENDER_EQUIP_AUTOEQUIP_TRINKET1:  //16 - 1 trinket
        case GOSSIP_SENDER_EQUIP_AUTOEQUIP_TRINKET2:  //17 - 1 trinket
        case GOSSIP_SENDER_EQUIP_AUTOEQUIP_NECK:      //18 - 1 neck
        {
            Item* item = NULL;
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
                    if (Bag* pBag = player->GetBagByPos(i))
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

            //break;
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
                if (Item* pItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, i))
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

                    for (uint8 k = 0; k != BOT_INVENTORY_SIZE; ++k)
                    {
                        if (_canEquip(pItem->GetTemplate(), k + 1))
                        {
                            canEquip = true;
                            break;
                        }
                    }

                    if (canEquip && itemList.find(pItem->GetGUID().GetCounter()) == itemList.end() && idsList.find(pItem->GetEntry()) == idsList.end())
                    {
                        itemList.insert(pItem->GetGUID().GetCounter());
                        idsList.insert(pItem->GetEntry());
                    }
                }
            }

            //1.2: other bags
            for (uint8 i = INVENTORY_SLOT_BAG_START; i != INVENTORY_SLOT_BAG_END; i++)
            {
                if (Bag* pBag = player->GetBagByPos(i))
                {
                    for (uint32 j = 0; j != pBag->GetBagSize(); j++)
                    {
                        if (Item* pItem = player->GetItemByPos(i, j))
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

                            for (uint8 k = 0; k != BOT_INVENTORY_SIZE; ++k)
                            {
                                if (_canEquip(pItem->GetTemplate(), k + 1))
                                {
                                    canEquip = true;
                                    break;
                                }
                            }

                            if (canEquip && itemList.find(pItem->GetGUID().GetCounter()) == itemList.end() && idsList.find(pItem->GetEntry()) == idsList.end())
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
                uint32 maxcounter = GOSSIP_MAX_MENU_ITEMS - 1; // back
                Item* item;
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
                                if (_canEquip(item->GetTemplate(), k + 1))
                                    break;

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
                        if (Bag* pBag = player->GetBagByPos(i))
                        {
                            for (uint32 j = 0; j != pBag->GetBagSize(); j++)
                            {
                                item = player->GetItemByPos(i, j);
                                if (item && item->GetGUID().GetCounter() == (*itr))
                                {
                                    uint8 k = 0;
                                    for (; k != BOT_INVENTORY_SIZE; ++k)
                                        if (_canEquip(item->GetTemplate(), k + 1))
                                            break;

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
            if (_resetEquipment(action - (GOSSIP_ACTION_INFO_DEF + 1))){}
            break;
        }
        //equips change s4b: Equip item
        //base is GOSSIP_SENDER_EQUIP + 0...1...2... etc.
        case GOSSIP_SENDER_EQUIP_MHAND:     //1 - 1 main hand
        case GOSSIP_SENDER_EQUIP_OHAND:     //2 - 1 off hand
        case GOSSIP_SENDER_EQUIP_RANGED:    //3 - 1 ranged
        case GOSSIP_SENDER_EQUIP_HEAD:      //4 - 1 head
        case GOSSIP_SENDER_EQUIP_SHOULDERS: //5 - 1 shoulders
        case GOSSIP_SENDER_EQUIP_CHEST:     //6 - 1 chest
        case GOSSIP_SENDER_EQUIP_WAIST:     //7 - 1 waist
        case GOSSIP_SENDER_EQUIP_LEGS:      //8 - 1 legs
        case GOSSIP_SENDER_EQUIP_FEET:      //9 - 1 feet
        case GOSSIP_SENDER_EQUIP_WRIST:     //10 - 1 wrist
        case GOSSIP_SENDER_EQUIP_HANDS:     //11 - 1 hands
        case GOSSIP_SENDER_EQUIP_BACK:      //12 - 1 back
        case GOSSIP_SENDER_EQUIP_BODY:      //13 - 1 body
        case GOSSIP_SENDER_EQUIP_FINGER1:   //14 - 1 finger
        case GOSSIP_SENDER_EQUIP_FINGER2:   //15 - 1 finger
        case GOSSIP_SENDER_EQUIP_TRINKET1:  //16 - 1 trinket
        case GOSSIP_SENDER_EQUIP_TRINKET2:  //17 - 1 trinket
        case GOSSIP_SENDER_EQUIP_NECK:      //18 - 1 neck
        {
            Item* item = NULL;
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
                    if (Bag* pBag = player->GetBagByPos(i))
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
        case GOSSIP_SENDER_ROLES_TOGGLE: //ROLES 2: set/unset
        {
            ToggleRole(action - GOSSIP_ACTION_INFO_DEF, false);

            //break;
        }
        case GOSSIP_SENDER_ROLES: //ROLES 1: list
        {
            subMenu = true;

            uint8 role = BOT_ROLE_TANK;

            for (; role != BOT_MAX_ROLE; role <<= 1)
            {
                if (role == BOT_ROLE_PARTY) //hidden
                    continue;
                if (role == BOT_ROLE_HEAL && !CanHeal())
                    continue;

                AddGossipItemFor(player, _onOffIcon(role), GetRoleString(role), GOSSIP_SENDER_ROLES_TOGGLE, GOSSIP_ACTION_INFO_DEF + role);
            }

            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "BACK", 1, GOSSIP_ACTION_INFO_DEF + role + 1);

            break;
        }
        case GOSSIP_SENDER_ABILITIES_USE:
        {
            if (uint32 basespell = action - GOSSIP_ACTION_INFO_DEF)
                //if (CheckBotCast(me, basespell, me->GetBotClass()) == SPELL_CAST_OK)
                    if (IsSpellReady(basespell, lastdiff, true))
                        doCast(player, GetSpell(basespell));

            //break;
        }
        case GOSSIP_SENDER_ABILITIES:
        {
            subMenu = true;

            uint32 basespell;
            SpellInfo const* spellInfo;
            BotSpellMap const& myspells = GetSpellMap();
            for (BotSpellMap::const_iterator itr = myspells.begin(); itr != myspells.end(); ++itr)
            {
                //if (currentSpell == itr->second.first) continue; //prevent spam
                basespell = itr->first; //always valid
                if (!CanUseManually(basespell)) continue;
                if (!IsSpellReady(basespell, 0, false, 5000)) continue;
                spellInfo = sSpellMgr->GetSpellInfo(basespell); //always valid

                std::ostringstream name;
                _AddSpellLink(player, spellInfo, name);
                AddGossipItemFor(player, GOSSIP_ICON_TRAINER, name.str().c_str(), GOSSIP_SENDER_ABILITIES_USE, GOSSIP_ACTION_INFO_DEF + basespell);
            }

            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Update", GOSSIP_SENDER_ABILITIES_USE, GOSSIP_ACTION_INFO_DEF);
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "BACK", 1, GOSSIP_ACTION_INFO_DEF + 2);

            break;
        }
        case GOSSIP_SENDER_HIRE:
        {
            int32 reason = action - GOSSIP_ACTION_INFO_DEF;
            if (!reason)
            {
                if (_ownerGuid)
                {
                    std::ostringstream ostr;
                    std::string name;
                    ostr << "Go away. I serve my master ";
                    if (sObjectMgr->GetPlayerNameByGUID(ObjectGuid(HighGuid::Player, _ownerGuid), name))
                        ostr << name;
                    else
                        ostr << "unknown (" << _ownerGuid << ')';
                    BotSay(ostr.str().c_str(), player);
                    ChatHandler ch(player->GetSession());
                    ch.PSendSysMessage("%s will not join you until owner dismisses %s", me->GetName().c_str(), (me->getGender() == GENDER_MALE ? "him" : "her"));
                    break;
                }

                if (SetBotOwner(player))
                    BotWhisper("I am ready", player);
                else
                    BotSay("...", player);
            }
            else if (reason == -1)
            {
                me->SetFaction(35);
                if (Creature* pet = me->GetBotsPet())
                    pet->SetFaction(35);
                // thesawolf - stop unhired reset npcbot from killing player
                // BotYell("Die!", player);
                // me->Attack(player, IsMelee());
                BotSay("Do I really look like I'd join you?!", player);
                break;
            }
            else
            {
                ChatHandler ch(player->GetSession());
                switch (reason)
                {
                    case 1: //has owner, unexpected
                        ch.PSendSysMessage("%s will not join you, already has master: %s",
                            //me->GetName().c_str(), master->GetName().c_str());
                            me->GetName().c_str(), me->GetBotOwner()->GetName().c_str());
                        break;
                    case 2: //max npcbots exceed
                        ch.PSendSysMessage("You exceed max npcbots (%u)", BotMgr::GetMaxNpcBots());
                        break;
                    case 3: //not enough money
                    {
                        std::string str = "You don't have enough money (";
                        str += BotMgr::GetNpcBotCostStr(player->getLevel(), me);
                        str += ")!";
                        ch.SendSysMessage(str.c_str());
                        player->SendBuyError(BUY_ERR_NOT_ENOUGHT_MONEY, 0, 0, 0);
                        break;
                    }
                    case 4: //class bots exceed
                    {
                        uint8 count = 0;
                        BotMap const* map = player->GetBotMgr()->GetBotMap();
                        for (BotMap::const_iterator itr = map->begin(); itr != map->end(); ++itr)
                            if (itr->second->GetBotClass() == GetBotClass())
                                ++count;

                        ch.PSendSysMessage("You cannot have more bots of that class! %u of %u",
                            count, _maxClassNpcBots);
                        break;
                    }
                    default:
                        break;
                }

                BotSay("...", player);
            }
            break;
        }
        case GOSSIP_SENDER_DISMISS:
        {
            BotMgr* mgr = player->GetBotMgr();
            ASSERT(mgr);

            //send items to owner -- Unequip all
            bool abort = false;
            /* thesawolf - maintain gearset
            for (uint8 i = 0; i != BOT_INVENTORY_SIZE; ++i)
            {
                if (!(i < BOT_SLOT_RANGED ? _resetEquipment(i) : _unequip(i)))
                {
                    std::ostringstream estr;
                    estr << "Cannot reset equipment in slot " << uint32(i) << " (" << _getNameForSlot(i + 1) << ")! Cannot dismiss bot!";
                    ChatHandler ch(player->GetSession());
                    ch.SendSysMessage(estr.str().c_str());
                    abort = true;
                    break;
                }
            }
            */
            
            if (abort)
                break;
            mgr->RemoveBot(me->GetGUID(), BOT_REMOVE_DISMISS);
            /* remove this hire lockout
            if (Aura* bers = me->AddAura(BERSERK, me))
            {
                uint32 dur = 1 * HOUR * IN_MILLISECONDS;
                bers->SetDuration(dur);
                bers->SetMaxDuration(dur);
            }
            */
            
            me->SetFaction(35);
            if (Creature* pet = me->GetBotsPet())
                pet->SetFaction(35);
            me->HandleEmoteCommand(EMOTE_ONESHOT_WAVE);
            BotSay("You are going to miss me...", player);
            
            break;
        }
        case GOSSIP_SENDER_FIRE:
        {
            BotMgr* mgr = player->GetBotMgr();
            ASSERT(mgr);

            //send items to owner -- Unequip all
            bool abort = false;
            for (uint8 i = 0; i != BOT_INVENTORY_SIZE; ++i)
            {
                if (!(i < BOT_SLOT_RANGED ? _resetEquipment(i) : _unequip(i)))
                {
                    std::ostringstream estr;
                    estr << "Cannot reset equipment in slot " << uint32(i) << " (" << _getNameForSlot(i + 1) << ")! Cannot dismiss bot!";
                    ChatHandler ch(player->GetSession());
                    ch.SendSysMessage(estr.str().c_str());
                    abort = true;
                    break;
                }
            }

            if (abort)
                break;
            // thesawolf - dismiss is annoying.. just delete
            mgr->RemoveBot(me->GetGUID(), BOT_REMOVE_DISMISS);
            if (Aura* bers = me->AddAura(BERSERK, me))
            {
                uint32 dur = 1 * HOUR * IN_MILLISECONDS;
                bers->SetDuration(dur);
                bers->SetMaxDuration(dur);
            }
            me->SetFaction(35);
            if (Creature* pet = me->GetBotsPet())
                pet->SetFaction(35);
            // thesawolf - 80 npcbot slaughtering you, isn't funny, make them passive aggressive
            me->HandleEmoteCommand(EMOTE_ONESHOT_RUDE);
            BotSay("You sucked anyways...", player);
            //me->Attack(player, IsMelee());
            
            //thesawolf - instead of dismissing.. delete
            me->CombatStop();
            me->DeleteFromDB();
            me->AddObjectToRemoveList();
            uint32 id = me->GetEntry();
            
            PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_NPCBOT);
            //"DELETE FROM characters_npcbot WHERE entry = ?", CONNECTION_ASYNC
            stmt->setUInt32(0, id);
            CharacterDatabase.Execute(stmt);
            break;
        
        }
        case GOSSIP_SENDER_JOIN_GROUP:
        {
            player->GetBotMgr()->AddBotToGroup(me);
            break;
        }
        case GOSSIP_SENDER_LEAVE_GROUP:
        {
            player->GetBotMgr()->RemoveBotFromGroup(me);
            break;
        }
        case GOSSIP_SENDER_FORMATION:
        {
            subMenu = true;
            std::ostringstream diststr;
            diststr << "Set distance (current: " << uint32(player->GetBotFollowDist()) << ')';
            player->PlayerTalkClass->GetGossipMenu().AddMenuItem(-1, GOSSIP_ICON_CHAT, diststr.str(),
                GOSSIP_SENDER_FORMATION_DISTANCE, GOSSIP_ACTION_INFO_DEF + 1, "", 0, true);
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "BACK", 1, GOSSIP_ACTION_INFO_DEF + 2);
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
                        ResetBotAI(BOTAI_RESET_DISMISS);
                        PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_NPCBOT_OWNER);
                        //"UPDATE characters_npcbot SET owner = ? WHERE entry = ?", CONNECTION_ASYNC
                        stmt->setUInt32(0, uint32(0));
                        stmt->setUInt32(1, me->GetEntry());
                        CharacterDatabase.Execute(stmt);
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
                    for (uint8 i = BOT_MAX_ROLE; i != BOT_ROLE_NONE; i >>= 1)
                    {
                        if (_roleMask & i)
                        {
                            switch (i)
                            {
                                case BOT_ROLE_TANK:
                                    ch.PSendSysMessage("BOT_ROLE_TANK");
                                    break;
                                case BOT_ROLE_DPS:
                                    ch.PSendSysMessage("BOT_ROLE_DPS");
                                    break;
                                case BOT_ROLE_HEAL:
                                    ch.PSendSysMessage("BOT_ROLE_HEAL");
                                    break;
                                //case BOT_ROLE_MELEE:
                                //    ch.PSendSysMessage("BOT_ROLE_MELEE");
                                //    break;
                                case BOT_ROLE_RANGED:
                                    ch.PSendSysMessage("BOT_ROLE_RANGED");
                                    break;
                                case BOT_ROLE_PARTY:
                                    ch.PSendSysMessage("BOT_ROLE_PARTY");
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
                        ++counter;
                        std::ostringstream sstr;
                        spellInfo = sSpellMgr->GetSpellInfo(itr->first); //always valid
                        _AddSpellLink(player, spellInfo, sstr);
                        sstr << " id: " <<  itr->second.first << ", base: " << itr->first
                            << ", cd: " << itr->second.second << ", base: " << std::max<uint32>(spellInfo->RecoveryTime, spellInfo->CategoryRecoveryTime);
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
            if (_ownerGuid && sObjectMgr->GetPlayerNameByGUID(ObjectGuid(HighGuid::Player, _ownerGuid), name))
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
            //!!! player != owner !!!
            subMenu = true;

            //ListAbilities(true);
            switch (_botclass)
            {
                case BOT_CLASS_BM:
                    gossipTextId = GOSSIP_CLASS_BM;
                    break;
                default:
                    break;
            }

            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "BACK", 1, GOSSIP_ACTION_INFO_DEF + 1);

            break;
        }
        case GOSSIP_SENDER_SCAN_OWNER_ABILITY:
        {
            uint32 Id = action - GOSSIP_ACTION_INFO_DEF;
            SpellInfo const* info = sSpellMgr->GetSpellInfo(Id);
            ASSERT(info);

            ChatHandler ch(player->GetSession());
            std::ostringstream smsg1, smsg2;
            switch (Id)
            {
                //Blademaster
                case SPELL_NETHERWALK:
                    _AddSpellLink(player, info, smsg1, false, "ffffff00"/*yellow*/);
                    smsg2 << "    Invisibilty: |cff00ff00" << uint32(100 + (me->getLevel() * 5) / 2) << "|r, speed: +|cff00ff00" << uint32(10 + me->getLevel() / 2) << "|r%, |cff00ff00150|r% normal damage";
                    ch.SendSysMessage(smsg1.str().c_str());
                    ch.SendSysMessage("Allows Blademaster to become invisible, and move faster for a set amount of time. When the Blademaster attacks a unit to break invisibility, he will deal bonus damage.");
                    ch.SendSysMessage(smsg2.str().c_str());
                    break;
                case SPELL_MIRROR_IMAGE_BM:
                    _AddSpellLink(player, info, smsg1, false, "ffffff00"/*yellow*/);
                    smsg2 << "    |cff00ff00" << uint32(GetSpellMiscValue(Id)) << "|r " << (GetSpellMiscValue(Id) == 1 ? "illusion" : "illusions");
                    ch.SendSysMessage(smsg1.str().c_str());
                    ch.SendSysMessage("Confuses the enemy by creating illusions of the Blademaster and dispelling all magic from the Blademaster.");
                    ch.SendSysMessage(smsg2.str().c_str());
                    break;
                case SPELL_CRITICAL_STRIKE:
                    _AddSpellLink(player, info, smsg1, false, "ffff0000"/*red*/);
                    smsg1 << " |cffffff00(Passive)|r";
                    smsg2 << "    |cff00ff0015|r% chance to deal |cff00ff00" << uint32(GetSpellMiscValue(Id)) << "|r times normal damage";
                    ch.SendSysMessage(smsg1.str().c_str());
                    ch.SendSysMessage("Gives a 15% chance that the Blademaster will do more damage on his attacks.");
                    ch.SendSysMessage(smsg2.str().c_str());
                    break;
                //case SPELL_BLADESTORM_BM: TODO:
                default:
                    break;
            }

            //break;
        }
        case GOSSIP_SENDER_SCAN_OWNER:
        {
            subMenu = true;

            std::ostringstream abmsg1, abmsg2, abmsg3/*, abmsg4*/;
            switch (_botclass)
            {
                case BOT_CLASS_BM:
                    if (me->getLevel() >= 10)
                    {
                        _AddSpellLink(player, sSpellMgr->GetSpellInfo(SPELL_NETHERWALK), abmsg1);
                        AddGossipItemFor(player, GOSSIP_ICON_CHAT, abmsg1.str().c_str(), GOSSIP_SENDER_SCAN_OWNER_ABILITY, GOSSIP_ACTION_INFO_DEF + SPELL_NETHERWALK);
                    }
                    if (me->getLevel() >= 20)
                    {
                        _AddSpellLink(player, sSpellMgr->GetSpellInfo(SPELL_MIRROR_IMAGE_BM), abmsg2);
                        AddGossipItemFor(player, GOSSIP_ICON_CHAT, abmsg2.str().c_str(), GOSSIP_SENDER_SCAN_OWNER_ABILITY, GOSSIP_ACTION_INFO_DEF + SPELL_MIRROR_IMAGE_BM);
                    }
                    if (me->getLevel() >= 10)
                    {
                        _AddSpellLink(player, sSpellMgr->GetSpellInfo(SPELL_CRITICAL_STRIKE), abmsg3);
                        AddGossipItemFor(player, GOSSIP_ICON_CHAT, abmsg3.str().c_str(), GOSSIP_SENDER_SCAN_OWNER_ABILITY, GOSSIP_ACTION_INFO_DEF + SPELL_CRITICAL_STRIKE);
                    }
                    //TODO:
                    //_AddSpellLink(player, sSpellMgr->GetSpellInfo(SPELL_CRITICAL_STRIKE), abmsg4);
                    //AddGossipItemFor(player, GOSSIP_ICON_CHAT, abmsg4.str().c_str(), GOSSIP_SENDER_SCAN_OWNER_ABILITY, GOSSIP_ACTION_INFO_DEF + SPELL_BLADESTORM_BM);
                    break;
                default:
                    break;
            }

            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "BACK", 1, GOSSIP_ACTION_INFO_DEF + 1);

            break;
        }
        default:
            break;
    }

    //if we add submenus send them else we should return
    if (subMenu)
        player->PlayerTalkClass->SendGossipMenu(gossipTextId, me->GetGUID());
    else
        CloseGossipMenuFor(player);

    return true;
}

//GossipSelectCode
bool bot_minion_ai::OnGossipSelectCode(Player* player, Creature* creature/* == me*/, uint32 sender, uint32 action, char const* code)
{
    if (!*code)
        return true;

    if (!_enableNpcBots || CCed(me) || IsDuringTeleport())
    {
        CloseGossipMenuFor(player);
        return true;
    }

    uint32 gossipTextId = (player->GetGUID().GetCounter() == _ownerGuid || !IAmFree()) ? GOSSIP_SERVE_MASTER : GOSSIP_NEED_SMTH;

    player->PlayerTalkClass->ClearMenus();

    bool subMenu = false;

    switch (sender)
    {
        case GOSSIP_SENDER_FORMATION_DISTANCE:
        {
            char* dist = strtok((char*)code, "");
            int8 distance = std::min<uint8>((uint8)atoi(dist), 75);

            player->SetBotFollowDist(distance);

            CloseGossipMenuFor(player);
            return OnGossipSelect(player, creature, GOSSIP_SENDER_FORMATION, action);
        }
        default:
            break;
    }

    if (subMenu)
        player->PlayerTalkClass->SendGossipMenu(gossipTextId, me->GetGUID());
    else
        CloseGossipMenuFor(player);
    return true;
}
//Summons pet for bot
void bot_minion_ai::SummonBotsPet(uint32 entry)
{
    Creature* m_botsPet = me->GetBotsPet();
    if (m_botsPet)
        me->SetBotsPetDied();

    uint8 mylevel = std::min<uint8>(master->getLevel(), 80);
    uint32 originalentry = bot_pet_ai::GetPetOriginalEntry(entry);
    if (!originalentry)
    {
        //annoy master
        if (!IAmFree())
            BotWhisper("Why am I trying to summon unknown pet!?", master);
        return;
    }
    float x(0),y(0),z(0);
    me->GetClosePoint(x, y, z, me->GetObjectSize());
    //m_botsPet = me->SummonCreature(entry, x, y, z, 0, TEMPSUMMON_DEAD_DESPAWN);
    m_botsPet = me->SummonCreature(entry, me->GetPosition(), TEMPSUMMON_DEAD_DESPAWN);
    if (!m_botsPet)
    {
        if (!IAmFree())
            BotWhisper("Failed to summon pet!", master);
        return;
    }
    else
        BotWhisper("Summoned a pet for myself", master);

    //std::string name = sObjectMgr->GeneratePetName(originalentry);//voidwalker
    //if (!name.empty())
    //    m_botsPet->SetName(name);

    PreparedStatement* stmt = WorldDatabase.GetPreparedStatement(WORLD_SEL_NPCBOT_PET_LEVELSTATS);
    stmt->setUInt32(0, originalentry);
    stmt->setUInt8(1, mylevel);
    PreparedQueryResult result = WorldDatabase.Query(stmt);
    //QueryResult result = WorldDatabase.PQuery("SELECT hp, mana, armor, str, agi, sta, inte, spi FROM `pet_levelstats` WHERE `creature_entry` = '%u' AND `level` = '%u'", originalentry, mylevel);

    if (result)
    {
        Field* fields = result->Fetch();
        uint32 hp = fields[0].GetUInt16();
        uint32 mana = fields[1].GetUInt16();
        //armor = fields[2].GetUInt32();
        uint32 str = fields[3].GetUInt16();
        uint32 agi = fields[4].GetUInt16();
        uint32 sta = fields[5].GetUInt16();
        uint32 inte = fields[6].GetUInt16();
        uint32 spi = fields[7].GetUInt16();

        m_botsPet->SetCreateHealth(hp);
        m_botsPet->SetMaxHealth(hp);
        m_botsPet->SetCreateMana(mana);
        m_botsPet->SetMaxPower(POWER_MANA, mana);

        m_botsPet->SetCreateStat(STAT_STRENGTH, str);
        m_botsPet->SetCreateStat(STAT_AGILITY, agi);
        m_botsPet->SetCreateStat(STAT_STAMINA, sta);
        m_botsPet->SetCreateStat(STAT_INTELLECT, inte);
        m_botsPet->SetCreateStat(STAT_SPIRIT, spi);
    }

    m_botsPet->SetBotOwner(master);
    m_botsPet->SetCreatureOwner(me);
    //m_botsPet->SetBotClass(bot_pet_ai::GetPetClass(m_botsPet));
    master->SetMinion((Minion*)m_botsPet, true);
    m_botsPet->SetGuidValue(UNIT_FIELD_CREATEDBY, me->GetGUID());
    //m_botsPet->DeleteThreatList();
    m_botsPet->AddUnitTypeMask(UNIT_MASK_MINION);
    //m_botsPet->SetLevel(master->getLevel());
    m_botsPet->AIM_Initialize();
    //m_botsPet->InitBotAI(true);
    m_botsPet->SetFaction(master->GetFaction());
    //bot_pet_ai* petai = m_botsPet->GetBotPetAI();
    //petai->SetCreatureOwner(me);
    //petai->SetBaseArmor(armor);
    m_botsPet->SetBotCommandState(COMMAND_FOLLOW, true);

    me->SetBotsPet(m_botsPet);

    m_botsPet->SendUpdateToPlayer(master);
}

//Returns pet type (maybe unneeded)
uint8 bot_pet_ai::GetPetType(Creature* pet)
{
    switch (pet->GetEntry())
    {
        case PET_VOIDWALKER:
            return PET_TYPE_VOIDWALKER;
        case PET_IMP:
            return PET_TYPE_IMP;
    }
    return PET_TYPE_NONE;
}
//Returns pet's class
uint8 bot_pet_ai::GetPetClass(Creature* pet)
{
    switch (GetPetType(pet))
    {
        case PET_TYPE_IMP:
            return BOT_CLASS_MAGE;
        case PET_TYPE_VOIDWALKER:
            return BOT_CLASS_WARRIOR;
        default:
            return BOT_CLASS_PALADIN;
    }
}
//Return entry used to summon real pets
uint32 bot_pet_ai::GetPetOriginalEntry(uint32 entry)
{
    switch (entry)
    {
        case PET_VOIDWALKER:
            return ORIGINAL_ENTRY_VOIDWALKER;
        case PET_IMP:
            return ORIGINAL_ENTRY_IMP;
        default:
            return 0;
    }
}
//PvP trinket for minions
void bot_minion_ai::BreakCC(uint32 diff)
{
    if (pvpTrinket_cd <= diff && CCed(me, true) && (me->GetVictim() || !me->getAttackers().empty()))
    {
        temptimer = GC_Timer;
        if (doCast(me, PVPTRINKET))
        {
            pvpTrinket_cd = 120000; //2 minutes default pvp trinket CD
            GC_Timer = temptimer;
            return;
        }
    }
}
//Returns attack range based on given range
//If mounted: 20%
//If ranged: 125%
//If master is dead: max range
float bot_ai::InitAttackRange(float origRange, bool ranged) const
{
    if (me->IsMounted())
        origRange *= 0.2f;
    else
    {
        if (ranged)
            origRange *= 1.25f;
        if (master->isDead())
            origRange += sWorld->GetMaxVisibleDistanceOnContinents();
        else if (IAmFree())
        {
            origRange =
                //me->GetMap()->IsBattlegroundOrArena() ? sWorld->GetMaxVisibleDistanceInBGArenas() :
                //me->GetMap()->Instanceable() ? sWorld->GetMaxVisibleDistanceInInstances() :
                sWorld->GetMaxVisibleDistanceOnContinents();
        }
    }
    return origRange;
}
//Force bots to start attack anyone who tries to DAMAGE me or master
//This means that anyone who attacks party will be attacked by whole bot party (see GetTarget())
void bot_minion_ai::OnOwnerDamagedBy(Unit* attacker)
{
    if (me->GetVictim() && (!IAmFree() || me->GetDistance(me->GetVictim()) < me->GetDistance(attacker)))
        return;
    if (InDuel(attacker))
        return;

    bool byspell = false;
    bool ranged = !IsMelee();
    switch (_botclass)
    {
        case BOT_CLASS_DRUID:
            byspell = GetBotStance() == BOT_STANCE_NONE || GetBotStance() == DRUID_MOONKIN_FORM;
            break;
        case BOT_CLASS_PRIEST:
        case BOT_CLASS_MAGE:
        case BOT_CLASS_WARLOCK:
        case BOT_CLASS_SHAMAN:
            byspell = true;
            break;
        default:
            //TC_LOG_ERROR("entities.player", "minion_ai: OnOwnerDamagedBy() - unknown bot class %u", uint8(_botclass));
            break;
    }
    float maxdist = InitAttackRange(float(IAmFree() ? 100 : master->GetBotFollowDist()), ranged); //use increased range
    if (!attacker->IsWithinDist(me, maxdist))
        return;
    if (!CanBotAttack(attacker, byspell))
        return;

    m_botCommandState = COMMAND_ABANDON; //reset AttackStart()
    me->Attack(attacker, !ranged);
}

bool bot_minion_ai::_canUseOffHand() const
{
    if (_botclass == BOT_CLASS_BM)
        return false;

    //warriot can wield any offhand with titan's grip
    if (_botclass == BOT_CLASS_WARRIOR && me->getLevel() >= 60)
        return true;

    //no offhand: check we are using one-handed weapon in main hand
    if (!_equips[1])
    {
        ItemTemplate const* proto = _equips[0] ? _equips[0]->GetTemplate() : NULL;
        //no mainhand weapon - can use offhand
        //mainhand is an one-hand weapon
        if (!proto)
            return true;
        else if (proto->Class == ITEM_CLASS_WEAPON &&
            (proto->SubClass == ITEM_SUBCLASS_WEAPON_AXE ||
            proto->SubClass == ITEM_SUBCLASS_WEAPON_DAGGER ||
            proto->SubClass == ITEM_SUBCLASS_WEAPON_FIST ||
            proto->SubClass == ITEM_SUBCLASS_WEAPON_MACE ||
            proto->SubClass == ITEM_SUBCLASS_WEAPON_SWORD))
            return true;
    }
    else if (ItemTemplate const* proto = _equips[1]->GetTemplate())
    {
        //Now we have something in off-hand
        //1 check if it is one-handed weapon
        if (proto->Class == ITEM_CLASS_WEAPON &&
            (proto->SubClass == ITEM_SUBCLASS_WEAPON_AXE ||
            proto->SubClass == ITEM_SUBCLASS_WEAPON_DAGGER ||
            proto->SubClass == ITEM_SUBCLASS_WEAPON_FIST ||
            proto->SubClass == ITEM_SUBCLASS_WEAPON_MACE ||
            proto->SubClass == ITEM_SUBCLASS_WEAPON_SWORD))
            return true;
        //2 check of it is a shield
        if (proto->Class == ITEM_CLASS_ARMOR && proto->SubClass == ITEM_SUBCLASS_ARMOR_SHIELD)
            return true;
        //3 check of it is a 'held in off-hand' item
        if (proto->InventoryType == INVTYPE_HOLDABLE)
            return true;
    }

    //NO
    return false;
}

bool bot_minion_ai::_canUseRanged() const
{
    return (_botclass == BOT_CLASS_HUNTER || _botclass == BOT_CLASS_ROGUE ||
        _botclass == BOT_CLASS_WARRIOR || _botclass == BOT_CLASS_PRIEST ||
        _botclass == BOT_CLASS_MAGE || _botclass == BOT_CLASS_WARLOCK);
}
//slot = BotEquipSlot
bool bot_minion_ai::_canEquip(ItemTemplate const* item, uint8 slot, bool ignoreItemLevel) const
{
    int8 id = 1;
    EquipmentInfo const* einfo = sObjectMgr->GetEquipmentInfo(me->GetEntry(), id);

    if (Item* oldItem = _equips[slot - 1])
    {
        ItemTemplate const* oldProto = oldItem->GetTemplate();
        //prevent reequipping same items
        if (item->ItemId == oldProto->ItemId)
            return false;
        //prevent equipping worse items (only standard or not)
        if (!ignoreItemLevel)
            if (slot > BOT_SLOT_RANGED || einfo->ItemEntry[slot - 1] != oldProto->ItemId)
                if (IAmFree() || !master->IsGameMaster())
                    if (oldProto->GetItemLevelIncludingQuality() > item->GetItemLevelIncludingQuality())
                        return false;
    }

    //level requirements
    if (me->getLevel() < item->RequiredLevel)
        return false;

    //class requirements
    if (!(item->AllowableClass & (1<<(GetPlayerClass()-1))))
        return false;

    //skip race requirements
    //Weapons requirements
    if (item->Class == ITEM_CLASS_WEAPON)
    {
        if (slot > BOT_SLOT_RANGED)
            return false;
        //polearms cannot be equipped into offhand
        if (slot == BOT_SLOT_OFFHAND && item->SubClass == ITEM_SUBCLASS_WEAPON_POLEARM)
            return false;
        //only some classes can use offhand
        if (slot == BOT_SLOT_OFFHAND && _botclass != BOT_CLASS_WARRIOR &&
            _botclass != BOT_CLASS_ROGUE && _botclass != BOT_CLASS_HUNTER &&
            _botclass != BOT_CLASS_SHAMAN && _botclass != BOT_CLASS_DEATH_KNIGHT)
            return false;
        //bot rogues only use daggers in mainhand
        if (slot == BOT_SLOT_MAINHAND && item->SubClass != ITEM_SUBCLASS_WEAPON_DAGGER &&
            _botclass == BOT_CLASS_ROGUE)
            return false;
        //simple check for ranged weapon
        if (item->InventoryType == INVTYPE_THROWN ||
            item->InventoryType == INVTYPE_RANGED ||
            item->InventoryType == INVTYPE_RANGEDRIGHT)
        {
            if (slot != BOT_SLOT_RANGED || !_canUseRanged())
                return false;

            if (item->SubClass == ITEM_SUBCLASS_WEAPON_GUN ||
                item->SubClass == ITEM_SUBCLASS_WEAPON_BOW ||
                item->SubClass == ITEM_SUBCLASS_WEAPON_CROSSBOW)
                return (_botclass == BOT_CLASS_HUNTER || _botclass == BOT_CLASS_ROGUE ||
                    _botclass == BOT_CLASS_WARRIOR/* || _botclass == BOT_CLASS_PRIEST ||
                    _botclass == BOT_CLASS_MAGE || _botclass == BOT_CLASS_WARLOCK*/);

            if (item->SubClass == ITEM_SUBCLASS_WEAPON_THROWN)
                return (/*_botclass == BOT_CLASS_HUNTER || */_botclass == BOT_CLASS_ROGUE ||
                    _botclass == BOT_CLASS_WARRIOR/* || _botclass == BOT_CLASS_PRIEST ||
                    _botclass == BOT_CLASS_MAGE || _botclass == BOT_CLASS_WARLOCK*/);

            if (item->SubClass == ITEM_SUBCLASS_WEAPON_WAND)
                return (/*_botclass == BOT_CLASS_HUNTER || _botclass == BOT_CLASS_ROGUE ||
                    _botclass == BOT_CLASS_WARRIOR || */_botclass == BOT_CLASS_PRIEST ||
                    _botclass == BOT_CLASS_MAGE || _botclass == BOT_CLASS_WARLOCK);
        }
        else if (item->InventoryType == INVTYPE_2HWEAPON)
        {
            //warriors can equip any 2H weapon in any hand
            if (_botclass == BOT_CLASS_WARRIOR && me->getLevel() >= 60 &&
                (slot == BOT_SLOT_MAINHAND || slot == BOT_SLOT_OFFHAND))
                return true;
            //2H weapons for casters - only staves
            if ((_botclass == BOT_CLASS_MAGE || _botclass == BOT_CLASS_PRIEST ||
                _botclass == BOT_CLASS_WARLOCK || _botclass == BOT_CLASS_DRUID) &&
                item->SubClass != ITEM_SUBCLASS_WEAPON_STAFF)
                return false;
            //can equip 2H only in mainhand
            return (slot == BOT_SLOT_MAINHAND);
        }
        else if (item->InventoryType == INVTYPE_WEAPON ||
            item->InventoryType == INVTYPE_WEAPONMAINHAND ||
            item->InventoryType == INVTYPE_WEAPONOFFHAND)
        {
            //separate classes which can equip weapons or shields in offhand
            return (slot == BOT_SLOT_MAINHAND ||
                (slot == BOT_SLOT_OFFHAND/* && _botclass != BOT_CLASS_PALADIN*/ && _canUseOffHand()));
        }
    }
    else if (item->Class == ITEM_CLASS_ARMOR)
    {
        //conditions for inventory slots
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
                break;
            case INVTYPE_TRINKET:
                if (slot != BOT_SLOT_TRINKET1 && slot != BOT_SLOT_TRINKET2)
                    return false;
                break;
            case INVTYPE_NECK:
                if (slot != BOT_SLOT_NECK)
                    return false;
                break;
            case INVTYPE_CLOAK:
                if (slot != BOT_SLOT_BACK)
                    return false;
                break;
            case INVTYPE_HOLDABLE:
            case INVTYPE_SHIELD:
                if (slot != BOT_SLOT_OFFHAND)
                    return false;
                break;
            case INVTYPE_RELIC:
                if (slot != BOT_SLOT_RANGED)
                    return false;
                break;
            default:
                break;
        }

        //Shields
        if (item->SubClass == ITEM_SUBCLASS_ARMOR_SHIELD)
        {
            if (slot == BOT_SLOT_OFFHAND) //wtf? mainhand shield?
            {
                //Only classes which can use shield
                return _canUseOffHand() &&
                    (_botclass == BOT_CLASS_WARRIOR ||
                    _botclass == BOT_CLASS_PALADIN ||
                    _botclass == BOT_CLASS_SHAMAN);
            }
        }
        else if (item->SubClass == ITEM_SUBCLASS_ARMOR_PLATE)
        {
            //Plate wearers
            return (me->getLevel() >= 40 &&
                (_botclass == BOT_CLASS_WARRIOR ||
                _botclass == BOT_CLASS_DEATH_KNIGHT ||
                _botclass == BOT_CLASS_PALADIN ||
                _botclass == BOT_CLASS_BM));
        }
        else if (item->SubClass == ITEM_SUBCLASS_ARMOR_MAIL)
        {
            //has mail skill by default
            if (_botclass == BOT_CLASS_WARRIOR ||
                _botclass == BOT_CLASS_DEATH_KNIGHT ||
                _botclass == BOT_CLASS_PALADIN ||
                _botclass == BOT_CLASS_BM)
                return true;
            //Mail wearers
            return (me->getLevel() >= 40 &&
                (_botclass == BOT_CLASS_SHAMAN ||
                _botclass == BOT_CLASS_HUNTER));
        }
        else if (item->SubClass == ITEM_SUBCLASS_ARMOR_LEATHER)
        {
            //exclude classes which can never use leather
            return (_botclass != BOT_CLASS_WARLOCK &&
                _botclass != BOT_CLASS_MAGE &&
                _botclass != BOT_CLASS_PRIEST);
        }
        else if (item->SubClass == ITEM_SUBCLASS_ARMOR_CLOTH)
        {
            //All classes can wear cloth lol
            return true;
        }
        else if (item->SubClass == ITEM_SUBCLASS_ARMOR_MISC)
        {
            if (item->InventoryType == INVTYPE_FEET && slot == BOT_SLOT_FEET)
                return true;
            if (item->InventoryType == INVTYPE_BODY && slot == BOT_SLOT_BODY)
                return true;
            if (item->InventoryType == INVTYPE_FINGER &&
                (slot == BOT_SLOT_FINGER1 || slot == BOT_SLOT_FINGER2))
                return true;
            if (item->InventoryType == INVTYPE_TRINKET &&
                (slot == BOT_SLOT_TRINKET1 || slot == BOT_SLOT_TRINKET2))
                return true;
            if (item->InventoryType == INVTYPE_NECK && slot == BOT_SLOT_NECK)
                return true;
            if (item->InventoryType == INVTYPE_HOLDABLE && slot == BOT_SLOT_OFFHAND && _canUseOffHand())
                return true;
        }
        else if (item->SubClass == ITEM_SUBCLASS_ARMOR_LIBRAM)
            return _botclass == BOT_CLASS_PALADIN && slot == BOT_SLOT_RANGED;
        else if (item->SubClass == ITEM_SUBCLASS_ARMOR_IDOL)
            return _botclass == BOT_CLASS_DRUID && slot == BOT_SLOT_RANGED;
        else if (item->SubClass == ITEM_SUBCLASS_ARMOR_TOTEM)
            return _botclass == BOT_CLASS_SHAMAN && slot == BOT_SLOT_RANGED;
        else if (item->SubClass == ITEM_SUBCLASS_ARMOR_SIGIL)
            return _botclass == BOT_CLASS_DEATH_KNIGHT && slot == BOT_SLOT_RANGED;
        //misc inv items TODO:
    }

    return false;
}

bool bot_minion_ai::_unequip(uint8 slot)
{
    ASSERT(!IAmFree());

    int8 id = 1;
    EquipmentInfo const* einfo = sObjectMgr->GetEquipmentInfo(me->GetEntry(), id);
    ASSERT(einfo && "Trying to unequip item for bot with no equip info!");

    Item* item = _equips[slot];
    if (!item)
        return true; //already unequipped

    uint32 itemId = item->GetEntry();

    //hand old weapon to master
    if (slot >= BOT_SLOT_RANGED || einfo->ItemEntry[slot] != itemId)
    {
        ItemPosCountVec dest;
        uint32 no_space = 0;
        InventoryResult msg = master->CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, itemId, 1, &no_space);
        if (msg != EQUIP_ERR_OK)
        {
            std::ostringstream istr, iistr;
            istr << "Cannot unequip ";
            _AddItemLink(master, item, iistr);
            istr << iistr.str() << " for some stupid reason! Sending through mail";
            ChatHandler ch(master->GetSession());
            ch.SendSysMessage(istr.str().c_str());

            SQLTransaction trans = CharacterDatabase.BeginTransaction();
            MailDraft(iistr.str(), "").AddItem(item).SendMailTo(trans, MailReceiver(master), MailSender(me));
            CharacterDatabase.CommitTransaction(trans);

            //master->SendEquipError(msg, NULL, NULL, itemId);
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
        //item = NULL; //already in "_updateEquips(slot, NULL);"
    }

    //only for non-standard items
    if (slot >= BOT_SLOT_RANGED || einfo->ItemEntry[slot] != itemId)
        RemoveItemBonuses(slot);

    if (slot < BOT_SLOT_RANGED && CanChangeEquip(slot + 1)) //weapons
    {
        me->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID + slot, 0);
        me->SetAttackTime(WeaponAttackType(slot), 2000); //without weapon
    }

    _updateEquips(slot, NULL);

    //offhand check
    if (slot + 1 == BOT_SLOT_OFFHAND)
    {
        if (me->CanDualWield())
            me->SetCanDualWield(false);
        if (!(me->GetCreatureTemplate()->flags_extra & CREATURE_FLAG_EXTRA_NO_BLOCK))
            const_cast<CreatureTemplate*>(me->GetCreatureTemplate())->flags_extra |= CREATURE_FLAG_EXTRA_NO_BLOCK;
    }

    return true;
}

bool bot_minion_ai::_equip(uint8 slot, Item* newItem)
{
    ASSERT(!IAmFree());

    if (!newItem)
        return true; //nothing to equip

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

    if (Item* oldItem = _equips[slot])
    {
        //same id
        if (oldItem->GetEntry() == newItemId)
            return false;
    }

    if (!_unequip(slot))
    {
        BotSay("You have no space for my current item", master);
        return false;
    }

    if (slot >= BOT_SLOT_RANGED || einfo->ItemEntry[slot] != newItemId)
    {
        //cheating
        if (newItem->GetOwnerGUID() != master->GetGUID() || !master->HasItemCount(newItemId, 1))
        {
            std::ostringstream msg;
            msg << "Cannot find ";
            _AddItemLink(master, newItem, msg);
            msg << " (id: " << uint32(newItemId) << ")!";
            BotWhisper(msg.str().c_str(), master);

            TC_LOG_ERROR("entities.player",
                "minion_ai::_equip(): player %s (guidLow: %u) is trying to make bot %s (id: %u) equip item: %s (id: %u, guidLow: %u) but either does not have this item or does not own it",
                master->GetName().c_str(), master->GetGUID().GetCounter(), me->GetName().c_str(), me->GetEntry(), proto->Name1.c_str(), proto->ItemId, newItem->GetGUID().GetCounter());
            return false;
        }

        master->MoveItemFromInventory(newItem->GetBagSlot(), newItem->GetSlot(), true);
        //Item is removed from inventory table in _updateEquips(slot, newItem);
        newItem->SetGuidValue(ITEM_FIELD_OWNER, ObjectGuid::Empty);
    }

    if (slot < BOT_SLOT_RANGED)
    {
        if (CanChangeEquip(slot + 1))
            me->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID + slot, newItemId);
        uint32 delay =
            /*einfo->ItemEntry[slot] != newItemId || */!IgnoreEquipsAttackTime() || slot + 1 == BOT_SLOT_OFFHAND ? proto->Delay :
            slot + 1 == BOT_SLOT_RANGED ? me->GetCreatureTemplate()->RangeAttackTime : me->GetCreatureTemplate()->BaseAttackTime;
        me->SetAttackTime(WeaponAttackType(slot), delay); //set attack speed
    }

    _updateEquips(slot, newItem);

    //only for non-standard items
    if (slot >= BOT_SLOT_RANGED || einfo->ItemEntry[slot] != newItemId)
        ApplyItemBonuses(slot);

    if (slot + 1 == BOT_SLOT_OFFHAND)
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
    else if (slot + 1 == BOT_SLOT_MAINHAND && proto->InventoryType == INVTYPE_2HWEAPON && !(_botclass == BOT_CLASS_WARRIOR && me->getLevel() >= 60))
    {
        //if have incompatible offhand unequip it
        if (_equips[BOT_SLOT_OFFHAND - 1] != NULL)
            _unequip(BOT_SLOT_OFFHAND - 1);
    }

    return true;
}

void bot_minion_ai::_updateEquips(uint8 slot, Item* item)
{
    int8 id = 1;
    EquipmentInfo const* einfo = sObjectMgr->GetEquipmentInfo(me->GetEntry(), id);
    ASSERT(einfo && "Trying to update equips for bot with no equip info!");

    _equips[slot] = item;

    SQLTransaction trans = CharacterDatabase.BeginTransaction();

    //Commit to DB
    PreparedStatement* bstmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_NPCBOT_EQUIP);
    //"UPDATE character_npcbot SET equipMhEx = ?, equipOhEx = ?, equipRhEx = ?, equipHead = ?, equipShoulders = ?, equipChest = ?, equipWaist = ?, equipLegs = ?, equipFeet = ?, equipWrist = ?, equipHands = ?, equipBack = ?, equipBody = ?, equipFinger1 = ?, equipFinger2 = ?, equipTrinket1 = ?, equipTrinket2 = ?, equipNeck = ? WHERE entry = ?", CONNECTION_ASYNC
    PreparedStatement* stmt;
    uint8 k;
    for (k = 0; k != BOT_INVENTORY_SIZE; ++k)
    {
        if (Item* botitem = _equips[k])
        {
            bool standard = false;
            for (uint8 i = 0; i != MAX_EQUIPMENT_ITEMS; ++i)
            {
                if (einfo->ItemEntry[i] == botitem->GetEntry())
                {
                    bstmt->setUInt32(k, 0);
                    standard = true;
                    break;
                }
            }
            if (standard)
                continue;

            uint8 index = 0;
            stmt = CharacterDatabase.GetPreparedStatement(CHAR_REP_ITEM_INSTANCE);
            //REPLACE INTO item_instance (itemEntry, owner_guid, creatorGuid, giftCreatorGuid, count, duration, charges, flags, enchantments, randomPropertyId, durability, playedTime, text, guid)
            //VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)", CONNECTION_ASYNC : 0-13
            stmt->setUInt32(  index, botitem->GetEntry());
            stmt->setUInt32(++index, botitem->GetOwnerGUID().GetCounter());
            stmt->setUInt32(++index, botitem->GetGuidValue(ITEM_FIELD_CREATOR).GetCounter());
            stmt->setUInt32(++index, botitem->GetGuidValue(ITEM_FIELD_GIFTCREATOR).GetCounter());
            stmt->setUInt32(++index, botitem->GetCount());
            stmt->setUInt32(++index, botitem->GetUInt32Value(ITEM_FIELD_DURATION));

            std::ostringstream ssSpells;
            for (uint8 i = 0; i < MAX_ITEM_PROTO_SPELLS; ++i)
                ssSpells << botitem->GetSpellCharges(i) << ' ';
            stmt->setString(++index, ssSpells.str());

            stmt->setUInt32(++index, botitem->GetUInt32Value(ITEM_FIELD_FLAGS));

            std::ostringstream ssEnchants;
            for (uint8 i = 0; i < MAX_ENCHANTMENT_SLOT; ++i)
            {
                ssEnchants << botitem->GetEnchantmentId(EnchantmentSlot(i)) << ' ';
                ssEnchants << botitem->GetEnchantmentDuration(EnchantmentSlot(i)) << ' ';
                ssEnchants << botitem->GetEnchantmentCharges(EnchantmentSlot(i)) << ' ';
            }
            stmt->setString(++index, ssEnchants.str());

            stmt->setInt16 (++index, botitem->GetItemRandomPropertyId());
            stmt->setUInt16(++index, botitem->GetUInt32Value(ITEM_FIELD_DURABILITY));
            stmt->setUInt32(++index, botitem->GetUInt32Value(ITEM_FIELD_CREATE_PLAYED_TIME));
            stmt->setString(++index, botitem->GetText());
            stmt->setUInt32(++index, botitem->GetGUID().GetCounter());

            trans->Append(stmt);

            botitem->DeleteFromInventoryDB(trans); //prevent duplicates

            bstmt->setUInt32(k, botitem->GetGUID().GetCounter());
        }
        else
            bstmt->setUInt32(k, uint32(0));
    }

    bstmt->setUInt32(k, me->GetEntry());

    trans->Append(bstmt);
    CharacterDatabase.CommitTransaction(trans);
}
//Called from gossip menu only (applies only to weapons)
bool bot_minion_ai::_resetEquipment(uint8 slot)
{
    ASSERT(!IAmFree());
    ASSERT(slot < BOT_SLOT_RANGED);

    int8 id = 1;
    EquipmentInfo const* einfo = sObjectMgr->GetEquipmentInfo(me->GetEntry(), id);
    ASSERT(einfo && "Trying to reset equipment for bot with no equip info!");

    uint32 itemId = einfo->ItemEntry[slot];
    if (!itemId)
        return _unequip(slot);
    else if (Item* oldItem = _equips[slot])
        if (oldItem->GetEntry() == itemId)
            return true;

    if (slot + 1 == BOT_SLOT_MAINHAND && !(_botclass == BOT_CLASS_WARRIOR && me->getLevel() >= 60))
    {
        if (ItemTemplate const* proto = sObjectMgr->GetItemTemplate(itemId))
        {
            if (proto->Class == ITEM_CLASS_WEAPON &&
                (proto->SubClass == ITEM_SUBCLASS_WEAPON_AXE2 || proto->SubClass == ITEM_SUBCLASS_WEAPON_MACE2 ||
                proto->SubClass == ITEM_SUBCLASS_WEAPON_SWORD2 || proto->SubClass == ITEM_SUBCLASS_WEAPON_POLEARM ||
                proto->SubClass == ITEM_SUBCLASS_WEAPON_STAFF || proto->SubClass == ITEM_SUBCLASS_WEAPON_SPEAR))
            {
                if (!_unequip(BOT_SLOT_OFFHAND - 1))
                    return false;
            }
        }
    }

    //we have our standard weapon itemId which we should use to create new item
    Item* stItem = Item::CreateItem(itemId, 1, NULL);
    ASSERT(stItem && "Failed to create standard Item for bot!");

    if (!_equip(slot, stItem))
    {
        TC_LOG_ERROR("entities.player", "minion_ai::_resetEquipment(): player %s (guidLow: %u) failed to reset equipment for bot %s (id: %u) in slot %u",
                master->GetName().c_str(), master->GetGUID().GetCounter(), me->GetName().c_str(), me->GetEntry(), slot);
        return false;
    }
    return true;
}

void bot_minion_ai::ApplyItemBonuses(uint8 slot)
{
    //ensurance to set zeros
    RemoveItemBonuses(slot);

    Item* item = _equips[slot];
    if (!item)
        return;

    ItemTemplate const* proto = sObjectMgr->GetItemTemplate(item->GetEntry());
    if (!proto)
        return;

    ScalingStatDistributionEntry const* ssd = proto->ScalingStatDistribution ? sScalingStatDistributionStore.LookupEntry(proto->ScalingStatDistribution) : NULL;

    uint32 ssd_level = me->getLevel();
    if (ssd && ssd_level > ssd->MaxLevel)
        ssd_level = ssd->MaxLevel;

    ScalingStatValuesEntry const* ssv = proto->ScalingStatValue ? sScalingStatValuesStore.LookupEntry(ssd_level) : NULL;

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

    _stats[slot][BOT_ITEM_MOD_RESIST_HOLY] += proto->HolyRes;
    _stats[slot][BOT_ITEM_MOD_RESIST_FIRE] += proto->FireRes;
    _stats[slot][BOT_ITEM_MOD_RESIST_NATURE] += proto->NatureRes;
    _stats[slot][BOT_ITEM_MOD_RESIST_FROST] += proto->FrostRes;
    _stats[slot][BOT_ITEM_MOD_RESIST_SHADOW] += proto->ShadowRes;
    _stats[slot][BOT_ITEM_MOD_RESIST_ARCANE] += proto->ArcaneRes;

    _stats[slot][BOT_ITEM_MOD_DAMAGE] += (proto->Damage[0].DamageMin + proto->Damage[0].DamageMax) / 2;
    _stats[slot][BOT_ITEM_MOD_ARMOR] += proto->Armor;
    _stats[slot][BOT_ITEM_MOD_BLOCK_VALUE] += proto->Block;

    if (GetPlayerClass() == BOT_CLASS_DRUID)
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
            _stats[slot][BOT_ITEM_MOD_FERAL_ATTACK_POWER] += feral_bonus;
            //ApplyFeralAPBonus(feral_bonus, apply);
    }

    ApplyItemEnchantments(item, slot);
    ApplyItemEquipSpell(item, true);

    shouldUpdateStats = true;
}

void bot_minion_ai::RemoveItemBonuses(uint8 slot)
{
    Item* item = _equips[slot];
    if (!item)
        return;

    ItemTemplate const* proto = sObjectMgr->GetItemTemplate(item->GetEntry());
    if (!proto)
        return;

    for (uint8 i = 0; i != MAX_BOT_ITEM_MOD; ++i)
        _stats[slot][i] = 0;

    RemoveItemEnchantments(item, slot); //remove spells
    ApplyItemEquipSpell(item, false);

    shouldUpdateStats = true;
}

void bot_minion_ai::ApplyItemEnchantments(Item* item, uint8 slot)
{
    for (uint8 i = 0; i != MAX_ENCHANTMENT_SLOT; ++i)
        ApplyItemEnchantment(item, EnchantmentSlot(i), slot);
}

void bot_minion_ai::ApplyItemEnchantment(Item* item, EnchantmentSlot eslot, uint8 slot)
{
    uint32 enchant_id = item->GetEnchantmentId(eslot);
    if (!enchant_id)
        return;

    SpellItemEnchantmentEntry const* pEnchant = sSpellItemEnchantmentStore.LookupEntry(enchant_id);
    if (!pEnchant)
        return;

    if (pEnchant->requiredLevel > me->getLevel())
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
                _stats[slot][BOT_ITEM_MOD_DAMAGE] += enchant_amount;
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
                    if (basepoints)
                        me->CastCustomSpell(me, enchant_spell_id, &basepoints, &basepoints, &basepoints, true, item);
                    else
                        me->CastSpell(me, enchant_spell_id, true, item);
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
                _stats[slot][BOT_ITEM_MOD_RESISTANCE_START + enchant_spell_id] += enchant_amount;
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

void bot_minion_ai::RemoveItemEnchantments(Item* item, uint8 slot)
{
    for (uint8 i = 0; i != MAX_ENCHANTMENT_SLOT; ++i)
        RemoveItemEnchantment(item, EnchantmentSlot(i), slot);
}

void bot_minion_ai::RemoveItemEnchantment(Item* item, EnchantmentSlot eslot, uint8 /*slot*/)
{
    uint32 enchant_id = item->GetEnchantmentId(eslot);
    if (!enchant_id)
        return;

    SpellItemEnchantmentEntry const* pEnchant = sSpellItemEnchantmentStore.LookupEntry(enchant_id);
    if (!pEnchant)
        return;

    ////skip level reqs
    //if (pEnchant->requiredLevel > me->getLevel())
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

void bot_minion_ai::ApplyItemEquipSpell(Item* item, bool apply)
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

        if (apply)
            me->CastSpell(me, spellInfo, true, item);
        else
            me->RemoveAurasDueToItemSpell(spellInfo->Id, item->GetGUID());  // un-apply all spells, not only at-equipped
    }
}

void bot_minion_ai::ApplyItemsSpells()
{
    int8 id = 1;
    EquipmentInfo const* einfo = sObjectMgr->GetEquipmentInfo(me->GetEntry(), id);

    //only for non-standard items
    for (uint8 slot = 0; slot != BOT_INVENTORY_SIZE; ++slot)
        if (Item* item = _equips[slot])
            if (slot >= BOT_SLOT_RANGED || einfo->ItemEntry[slot] != item->GetEntry())
                ApplyItemEquipSpell(item, true);
}

inline float bot_minion_ai::_getBotStat(uint8 slot, uint8 stat) const
{
    return float(static_cast<BotStat>(_stats[slot])[stat]);
}

inline float bot_minion_ai::_getTotalBotStat(uint8 stat) const
{
    int32 value = 0;
    for (uint8 slot = 0; slot != BOT_INVENTORY_SIZE; ++slot)
        value += static_cast<BotStat>(_stats[slot])[stat];

    return float(value);
}

inline float bot_minion_ai::_getRatingMultiplier(CombatRating cr) const
{
    GtCombatRatingsEntry const* Rating =
        sGtCombatRatingsStore.LookupEntry(cr*GT_MAX_LEVEL + (me->getLevel()-1));
    GtOCTClassCombatRatingScalarEntry const* classRating =
        sGtOCTClassCombatRatingScalarStore.LookupEntry((GetPlayerClass()-1)*GT_MAX_RATING + cr + 1);
    if (!Rating || !classRating)
        return 1.0f;

    //bots gain 20% increased bonus from rating mods
    return 1.2f * classRating->ratio / Rating->ratio;
}

char const* bot_minion_ai::_getNameForSlot(uint8 slot) const
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

uint8 bot_minion_ai::_onOffIcon(uint8 role) const
{
    return HasRole(role) ? BOT_ICON_ON : BOT_ICON_OFF;
}

bool bot_minion_ai::CanHeal() const
{
    return
        (_botclass == BOT_CLASS_PRIEST || _botclass == BOT_CLASS_DRUID ||
        _botclass == BOT_CLASS_SHAMAN || _botclass == BOT_CLASS_PALADIN);
}

char const* bot_ai::GetRoleString(uint8 role) const
{
    switch (role)
    {
        case BOT_ROLE_NONE:
            return "???";
        case BOT_ROLE_TANK:
            return "Tanking";
        case BOT_ROLE_DPS:
            return "DPS";
        case BOT_ROLE_HEAL:
            return "Heal";
        //case BOT_ROLE_MELEE:
        //    return "Melee";
        case BOT_ROLE_RANGED:
            return "Ranged";
        default:
        {
            std::ostringstream str;
            str << "role " << uint32(role);
            return str.str().c_str();
        }
    }
}

void bot_ai::DefaultInit()
{
    //only once
    if (spawned) return;
    spawned = true;

    if (!firstspawn)
    {
        me->RemoveAllAuras();
        if (IsMinionAI())
            ToMinionAI()->ApplyItemsSpells();
    }

    //*etStats() has *pplyClassPassives() in it
    //needed to be before InitEquips for some classes (warrior TG)
    me->SetPvP(true);
    InitRoles();
    SetStats(true);
    //InitPowers(); //already in *etStats();
    ApplyPassives();

    if (firstspawn)
    {
        firstspawn = false;
        ASSERT(!me->GetBotAI());
        me->SetBotAI(this);
        InitFaction();
        InitOwner();
        InitEquips();

        InitSpellMap(PVPTRINKET, true);
    }
}

void bot_minion_ai::InitFaction()
{
    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_NPCBOT_FACTION);
    //"SELECT faction FROM characters_npcbot WHERE entry = ?", CONNECTION_SYNCH
    stmt->setUInt32(0, me->GetEntry());
    PreparedQueryResult result = CharacterDatabase.Query(stmt);
    ASSERT(result);
    
    Field* field = result->Fetch();        
    uint32 faction = field[0].GetUInt32();
    me->SetFaction(faction);
    const_cast<CreatureTemplate*>(me->GetCreatureTemplate())->faction = faction;
}

void bot_minion_ai::InitOwner()
{
    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_NPCBOT_OWNER);
    //"SELECT owner FROM character_npcbot WHERE entry = ?", CONNECTION_SYNCH
    stmt->setUInt32(0, me->GetEntry());
    PreparedQueryResult result = CharacterDatabase.Query(stmt);
    ASSERT(result);

    Field* field = result->Fetch();
    _ownerGuid = field[0].GetUInt32();
}

void bot_minion_ai::InitRoles()
{
    if (IAmFree())
    {
        //default roles
        _roleMask = BOT_ROLE_DPS;
        if (!IsMeleeClass(_botclass))
            _roleMask |= BOT_ROLE_RANGED;
        if (CanHeal())
            _roleMask |= BOT_ROLE_HEAL;

        return;
    }

    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_NPCBOT_ROLES);
    //"SELECT roles FROM character_npcbot WHERE entry = ?", CONNECTION_SYNC
    stmt->setUInt32(0, me->GetEntry());
    PreparedQueryResult result = CharacterDatabase.Query(stmt);
    if (!result)
    {
        //default roles
        _roleMask = BOT_ROLE_DPS;
        if (!IsMeleeClass(_botclass))
            _roleMask |= BOT_ROLE_RANGED;
        if (CanHeal())
            _roleMask |= BOT_ROLE_HEAL;

        return;
    }

    Field* field = result->Fetch();
    _roleMask = field[0].GetInt8();
}

void bot_pet_ai::InitRoles()
{
    _roleMask = BOT_ROLE_DPS;
    if (!IsMeleeClass(GetPetClass(me)))
        _roleMask |= BOT_ROLE_RANGED;
    if (CanHeal())
        _roleMask |= BOT_ROLE_HEAL;
}

void bot_minion_ai::InitEquips()
{
    int8 id = 1;
    EquipmentInfo const* einfo = sObjectMgr->GetEquipmentInfo(me->GetEntry(), id);
    ASSERT(einfo && "Trying to spawn bot with no equip info!");

    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_NPCBOT_EQUIP);
    //"SELECT equipMhEx, equipOhEx, equipRhEx, equipHead, equipShoulders, equipChest, equipWaist, equipLegs, equipFeet, equipWrist, equipHands, equipBack, equipBody, equipFinger1, equipFinger2, equipTrinket1, equipTrinket2, equipNeck
    //FROM character_npcbot WHERE entry = ?", CONNECTION_SYNCH
    stmt->setUInt32(0, me->GetEntry());
    PreparedQueryResult cnresult = CharacterDatabase.Query(stmt);
    if (!cnresult)
    {
        TC_LOG_ERROR("entities.player", "bot_minion_ai::InitEquips(): Failed to initialize equips for bot %s (id: %u, guidLow: %u), not found in `characters_npcbots table`!!!",
            me->GetName().c_str(), me->GetEntry(), me->GetGUID().GetCounter());
        ASSERT(false);
    }
    stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_NPCBOT_EQUIP_BY_ITEM_INSTANCE);
    //                    0                   1         2            3           4         5                6                    7              8             9        10       11            12             13
    //SELECT ii.creatorGuid, ii.giftCreatorGuid, ii.count, ii.duration, ii.charges, ii.flags, ii.enchantments, ii.randomPropertyId, ii.durability, ii.playedTime, ii.text, ii.guid, ii.itemEntry, ii.owner_guid "
    //  "FROM item_instance ii JOIN characters_npcbot cn ON ii.guid IN "
    //  "(cn.equipMhEx, cn.equipOhEx, cn.equipRhEx, cn.equipHead, cn.equipShoulders, cn.equipChest, cn.equipWaist, cn.equipLegs, cn.equipFeet, cn.equipWrist, cn.equipHands, cn.equipBack, cn.equipBody, cn.equipFinger1, cn.equipFinger2, cn.equipTrinket1, cn.equipTrinket2, cn.equipNeck) "
    //  "WHERE cn.entry = ?", CONNECTION_SYNCH
    stmt->setUInt32(0, me->GetEntry());
    PreparedQueryResult iiresult = CharacterDatabase.Query(stmt);

    Field* fields1 = cnresult->Fetch();
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

            item = Item::CreateItem(itemId, 1, NULL);
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
            uint8 i = 0;
            for (; i != BOT_INVENTORY_SIZE; ++i)
            {
                if (fields1[i].GetUInt32() == itemGuidLow && !_equips[i])
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
    for (uint8 i = 0; i != BOT_SLOT_RANGED; ++i)
    {
        if (CanChangeEquip(i + 1) && _equips[i])
            me->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID + i, _equips[i]->GetEntry());
        else if (einfo->ItemEntry[i])
            me->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID + i, einfo->ItemEntry[i]);
    }

    //apply weapons' parameters
    if (Item* MH = _equips[0])
    {
        itemId = MH->GetEntry();
        if (einfo->ItemEntry[0] != itemId)
        {
            if (ItemTemplate const* proto = sObjectMgr->GetItemTemplate(itemId))
            {
                me->SetAttackTime(BASE_ATTACK, proto->Delay);
                ApplyItemBonuses(0);
            }
        }
    }
    if (Item* OH = _equips[1])
    {
        itemId = OH->GetEntry();
        if (ItemTemplate const* proto = sObjectMgr->GetItemTemplate(itemId))
        {
            if (einfo->ItemEntry[1] != itemId)
                ApplyItemBonuses(1);

            if (proto->Class == ITEM_CLASS_WEAPON)
            {
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
    if (Item* RH = _equips[2])
    {
        itemId = RH->GetEntry();
        if (einfo->ItemEntry[2] != itemId)
        {
            if (ItemTemplate const* proto = sObjectMgr->GetItemTemplate(itemId))
            {
                if (proto->Class == ITEM_CLASS_WEAPON)
                    me->SetAttackTime(RANGED_ATTACK, proto->Delay);

                ApplyItemBonuses(2);
            }
        }
    }

    for (uint8 i = 3; i != BOT_INVENTORY_SIZE; ++i)
        ApplyItemBonuses(i);

    for (uint8 i = 0; i != MAX_EQUIPMENT_ITEMS; ++i)
    {
        if (_equips[i] == NULL && einfo->ItemEntry[i] != 0)
        {
            if (i == 1 && !_canUseOffHand())
                continue;

            //if bot has no equips but equip template then write these to bot map
            item = Item::CreateItem(einfo->ItemEntry[i], 1, NULL);
            ASSERT(item && "Failed to init standard Item for bot point 2!");
            _equips[i] = item;

            me->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID + i, einfo->ItemEntry[i]);
            if (i == 1)
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

void bot_ai::ToggleRole(uint8 role, bool force)
{
    if (!force && roleTimer > 0)
        return;

    roleTimer = 350; //delay next attempt (prevent abuse)

    HasRole(role) ? _roleMask &= ~role : _roleMask |= role;

    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_NPCBOT_ROLES);
    //"UPDATE character_npcbot SET roles = ? WHERE entry = ?", CONNECTION_ASYNC
    stmt->setUInt8(0, _roleMask);
    stmt->setUInt32(1, me->GetEntry());
    CharacterDatabase.Execute(stmt);

    //Update passives
    ApplyPassives();
    shouldUpdateStats = true;
}

bool bot_ai::IsTank(Unit* unit) const
{
    if (!unit)
        unit = me;

    if (unit == me)
        return HasRole(BOT_ROLE_TANK);

    if (Creature* bot = unit->ToCreature())
        if (bot->GetIAmABot() || bot->GetIAmABotsPet())
            return bot->GetBotAI()->HasRole(BOT_ROLE_TANK);

    if (Player* player = unit->ToPlayer())
    {
        if (Group* gr = player->GetGroup())
        {
            Group::MemberSlotList const& slots = gr->GetMemberSlots();
            for (Group::member_citerator itr = slots.begin(); itr != slots.end(); ++itr)
                if (itr->guid == player->GetGUID())
                    return itr->flags & MEMBER_FLAG_MAINTANK;
        }
    }

    return false;
}

void bot_ai::FindMaster(bool force)
{
    if (!force)
    {
        //totally free
        if (!_ownerGuid)
            return;
        if (!_atHome || _evadeMode)
            return;

        //delay
        if (checkMasterTimer > 0)
            return;

        checkMasterTimer = urand(5000, 15000);
    }

    //already have master
    if (!IAmFree())
        return;

    if (Player* player = sObjectMgr->GetPlayerByLowGUID(_ownerGuid))
    {
        //prevent bot being screwed up because of wrong flags
        if (player->IsGameMaster() || player->GetSession()->isLogingOut())
            return;

        SetBotOwner(player);

        //fail
        if (master != player)
            return;

        if (!IsTempBot())
            BotWhisper("Hey...", master);
        return;
    }
}

bool bot_minion_ai::IAmFree() const
{
    if (!_ownerGuid)
        return true;
    if (_ownerGuid != master->GetGUID())
        return true;
    if (!me->HasUnitTypeMask(UNIT_MASK_MINION))
        return true;

    return false;
    //return (!_ownerGuid || _ownerGuid != master->GetGUID() || !me->HasUnitTypeMask(UNIT_MASK_MINION));
    //        //has owner   and   //owner is found          and        //bound to owner
}

void bot_minion_ai::SavePosition()
{
    if (_saveTimer > 0) return;
    if (!me->IsPositionValid()) return;
    if (me->IsInCombat() || !me->IsInWorld())
    {
        _saveTimer = 3000;
        return;
    }

    _saveTimer = sWorld->getIntConfig(CONFIG_INTERVAL_SAVE);

    uint16 mapid = me->GetMapId();
    float x = me->GetPositionX();
    float y = me->GetPositionY();
    float z = me->GetPositionZ();
    float o = me->GetOrientation();

    if (CreatureData const* data = sObjectMgr->GetCreatureData(me->GetSpawnId()))
    {
        //const_cast<CreatureData*>(data)->spawnPoint.GetMapId() = mapid;
        //const_cast<CreatureData*>(data)->spawnPoint.GetPositionX() = x;
        //const_cast<CreatureData*>(data)->spawnPoint.GetPositionY() = y;
        //const_cast<CreatureData*>(data)->spawnPoint.GetPositionZ() = z;
        //const_cast<CreatureData*>(data)->spawnPoint.GetOrientation() = o;
        const_cast<CreatureData*>(data)->spawnPoint = WorldLocation(mapid, x, y, z, o);
    }

    PreparedStatement* stmt = WorldDatabase.GetPreparedStatement(WORLD_UPD_NPCBOT_POSITION);
    //"UPDATE creature SET map = ?, position_x = ?, position_y = ?, position_z = ?, orientation = ? WHERE guid = ?", CONNECTION_ASYNC
    stmt->setUInt16(0, mapid);
    stmt->setFloat(1, x);
    stmt->setFloat(2, y);
    stmt->setFloat(3, z);
    stmt->setFloat(4, o);
    stmt->setUInt32(5, me->GetSpawnId());

    WorldDatabase.Execute(stmt);
}

//UTILITIES
void bot_ai::_AddItemTemplateLink(Player* forPlayer, ItemTemplate const* item, std::ostringstream &str) const
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
// |color|Hitem:item_id:perm_ench_id:gem1:gem2:gem3:0:random_property:0:reporter_level|h[name]|h|r
// |cffa335ee|Hitem:812:0:0:0:0:0:0:0:70|h[Glowing Brightwood Staff]|h|r
void bot_ai::_AddItemLink(Player* forPlayer, Item const* item, std::ostringstream &str) const
{
    ItemTemplate const* proto = item->GetTemplate();

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

    //gems (3)
    uint32 g1 = 0, g2 = 0, g3 = 0;
    for (uint32 slot = SOCK_ENCHANTMENT_SLOT; slot != SOCK_ENCHANTMENT_SLOT + MAX_ITEM_PROTO_SOCKETS; ++slot)
    {
        uint32 eId = item->GetEnchantmentId(EnchantmentSlot(slot));

// |color|Hitem:item_id:perm_ench_id:gem1:gem2:gem3:0:random_property:0:reporter_level|h[name]|h|r
        switch (slot - SOCK_ENCHANTMENT_SLOT)
        {
            case 0: g1 = eId;   break;
            case 1: g2 = eId;   break;
            case 2: g3 = eId;   break;
        }
    }
    //permanent enchantment
    str << item->GetEnchantmentId(PERM_ENCHANTMENT_SLOT) << ':';
    //gems 3
    str << g1 << ':' << g2 << ':' << g3 << ':';
    //gems bonus - useless
    //str << item->GetEnchantmentId(BONUS_ENCHANTMENT_SLOT) << ':';
    str << 0 << ':';
    //random property
    str << item-> GetItemRandomPropertyId() << ':';
    //item suffix
    //str << item->GetItemSuffixFactor() << ':';
    //temp enchantment (i.e. windfury weapon)
    //str << item->GetEnchantmentId(TEMP_ENCHANTMENT_SLOT) << ':';
    //str << 0 << ':';

    ItemRandomSuffixEntry const* item_rand = sItemRandomSuffixStore.LookupEntry(abs(item->GetItemRandomPropertyId()));
    uint32 bpoints = 0;
    if (item_rand)
    {
        // Search enchant_amount
        for (uint8 k = 0; k != 3; ++k)
        {
            if (item_rand->enchant_id[k])
            {
                uint32 basepoints = int32((item_rand->prefix[k] * item->GetItemSuffixFactor()) / 10000);
                if (basepoints > bpoints)
                    bpoints = basepoints;
            }
        }
    }

    str << bpoints << ':';

    //reporter level
    str << proto->RequiredLevel;

    //name
    std::string name = proto->Name1;
    std::string suffix;
    _LocalizeItem(forPlayer, name, suffix, item);

    str << "|h[" << name << suffix << "]|h|r";

    //quantity
    if (item->GetCount() > 1)
        str << "x" << item->GetCount() << ' ';
}

void bot_ai::_AddQuestLink(Player* forPlayer, Quest const* quest, std::ostringstream &str) const
{
    std::string questTitle = quest->GetTitle();
    _LocalizeQuest(forPlayer, questTitle, quest->GetQuestId());
    str << "|cFFEFFD00|Hquest:" << quest->GetQuestId() << ':' << quest->GetQuestLevel() << "|h[" << questTitle << "]|h|r";
}

void bot_ai::_AddWeaponSkillLink(Player* forPlayer, SpellInfo const* spellInfo, std::ostringstream &str, uint32 skillid) const
{
    uint32 loc = forPlayer->GetSession()->GetSessionDbcLocale();
    str << "|cff00ffff|Hspell:" << spellInfo->Id << "|h[" << spellInfo->SpellName[loc] << " : " << master->GetSkillValue(skillid) << " /" << master->GetMaxSkillValue(skillid) << "]|h|r";
}
//|cff71d5ff|Hspell:21563|h[Command]|h|r
void bot_ai::_AddSpellLink(Player* forPlayer, SpellInfo const* spellInfo, std::ostringstream &str, bool color/* = true*/, const std::string& colorstr/* = "ffffffff"*/) const
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
        str << colorstr; //explicit color default white


    str << "|Hspell:" << spellInfo->Id << "|h[" << spellInfo->SpellName[loc] << "]|h|r";
}

void bot_ai::_AddProfessionLink(Player* forPlayer, SpellInfo const* spellInfo, std::ostringstream &str, uint32 skillId) const
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
void bot_ai::_LocalizeItem(Player* forPlayer, std::string &itemName, uint32 entry) const
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

void bot_ai::_LocalizeItem(Player* forPlayer, std::string &itemName, std::string &suffix, Item const* item) const
{
    uint32 loc = forPlayer->GetSession()->GetSessionDbLocaleIndex();
    std::wstring wnamepart;

    ItemLocale const* itemInfo = sObjectMgr->GetItemLocale(item->GetEntry());
    if (!itemInfo)
        return;

    if (itemInfo->Name.size() > loc && !itemInfo->Name[loc].empty())
    {
        const std::string name = itemInfo->Name[loc];
        if (Utf8FitTo(name, wnamepart))
            itemName = name;
    }

    int32 randomPropId = item->GetItemRandomPropertyId();
    if (!randomPropId)
        return;

    if (randomPropId > 0)
    {
        if (ItemRandomPropertiesEntry const* item_rand = sItemRandomPropertiesStore.LookupEntry(randomPropId))
            suffix = item_rand->nameSuffix[loc];
    }
    else
    {
        if (ItemRandomSuffixEntry const* item_rand = sItemRandomSuffixStore.LookupEntry(-randomPropId))
             suffix = item_rand->nameSuffix[loc];
    }
}

void bot_ai::_LocalizeQuest(Player* forPlayer, std::string &questTitle, uint32 entry) const
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

void bot_ai::_LocalizeCreature(Player* forPlayer, std::string &creatureName, uint32 entry) const
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

void bot_ai::_LocalizeGameObject(Player* forPlayer, std::string &gameobjectName, uint32 entry) const
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

void bot_ai::BotSpeak(std::string const& text, uint8 msgtype, uint32 language, ObjectGuid speaker, ObjectGuid receiver)
{
    if (msgtype == CHAT_MSG_WHISPER)
        language = LANG_UNIVERSAL;

    std::string _text(text);
    //sScriptMgr->OnPlayerChat(this, CHAT_MSG_SAY, language, _text);

    WorldPacket data(SMSG_MESSAGECHAT, 200);
    //BuildPlayerChat(&data, msgType, _text, language);
    data << uint8(msgtype);
    data << uint32(language);
    data << uint64(speaker);
    data << uint32(0);                 // constant unknown time
    data << uint64(speaker);
    data << uint32(text.length() + 1);
    data << text;
    data << uint8(0);

    if (msgtype == CHAT_MSG_WHISPER)
    {
        ASSERT(receiver && "BotSpeak(): no receiver for whisper!");
        ASSERT(receiver.IsPlayer() && "BotSpeak(): whisper receiver is not a player!");

        if (Player* res = ObjectAccessor::FindPlayer(receiver))
            res->GetSession()->SendPacket(&data);
    }
    else
    {
        if (Unit* snd = ObjectAccessor::FindConnectedPlayer(speaker))
        {
            float dist = std::max<float>(sWorld->getFloatConfig(CONFIG_LISTEN_RANGE_SAY), sWorld->getFloatConfig(CONFIG_LISTEN_RANGE_YELL) * 0.5f);
            Trinity::MessageDistDeliverer notifier(snd, &data, dist, false);
            snd->VisitNearbyWorldObject(dist, notifier);
        }
    }
    //SendMessageToSetInRange(&data, sWorld->getFloatConfig(CONFIG_LISTEN_RANGE_SAY), true);
}

void bot_minion_ai::BotJump(Position* pos)
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

bool bot_minion_ai::UpdateImpossibleChase(Unit* target)
{
    if (_chaseTimer || me->isMoving() || !IAmFree())
        return false;

    if (me->IsFalling() || JumpingFlyingOrFalling())
        return false;

    if (!me->IsWithinDist(target, IsMelee() ? 50 : 75) || (me->GetDistance(target) < (IsMelee() ? 5 : 25)))
    {
        ResetChaseTimer(target);
        me->GetMotionMaster()->MovePoint(me->GetMapId(), *target, false);
        return true;
    }

    if (_jumpCount >= 3)
    {
        me->AttackStop();
        Evade(true);
        return true;
    }

    ResetChaseTimer(target);
    BotJump(target);
    return true;
}

void bot_minion_ai::ResetChaseTimer(Position* /*pos*/)
{
    _chaseTimer = 10000;//std::max<uint32>(5000, me->GetDistance2d(pos->m_positionX, pos->m_positionY) * 400);
    //me->GetDistance2d(pos->m_positionX, pos->m_positionY) * 1000 / me->GetSpeed(MOVE_WALK);
}

void bot_minion_ai::ResetChase(Position* pos)
{
    if (!IAmFree())
        return;

    ResetChaseTimer(pos);
    _jumpCount = 0;
}

void bot_minion_ai::OnStartAttack(Unit* u)
{
    if (u->GetGUID() != _lastTargetGuid)
    {
        ResetChase(u);
        _lastTargetGuid = u->GetGUID();
    }
}

void bot_minion_ai::EnterCombat(Unit* u)
{
    _atHome = false;

    //clear gossip during combat. See CheckAuras() for restore
    if (me->HasFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP))
        me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
    //disable evade mode just in case
    //me->ClearUnitState(UNIT_STATE_EVADE);
    //if (Creature* pet = me->GetBotsPet())
    //    pet->ClearUnitState(UNIT_STATE_EVADE);

    if (!IAmFree())
        return;

    _evadeMode = false;
    AbortTeleport();

    ResetChase(u);
}

void bot_minion_ai::JustDied(Unit*)
{
    events.KillAllEvents(false);
    _reviveTimer = IAmFree() ? 180000 : 30000; //3min/30sec
    _atHome = false;
    _evadeMode = false;
    spawned = false;

    if (IsTempBot())
    {
        //TC_LOG_ERROR("entities.player", "Unsummoning temp bot %s (guidLow: %u), owner: %s (guidLow: %u)...",
        //    me->GetName().c_str(), me->GetGUID().GetCounter(), master->GetName().c_str(), master->GetGUID().GetCounter());

        if (!IAmFree())
            master->GetBotMgr()->RemoveBot(me->GetGUID(), BOT_REMOVE_UNSUMMON);

        me->AddObjectToRemoveList();
    }
    else if (!IAmFree())
    {
        if (Group* gr = master->GetGroup())
            if (gr->IsMember(me->GetGUID()))
                gr->SendUpdate();
    }
}

void bot_minion_ai::MoveInLineOfSight(Unit* /*u*/)
{
}

void bot_ai::DamageDealt(Unit* victim, uint32& damage, DamageEffectType /*damageType*/)
{
    if (victim == me)
        return;

    if (damage)
        if (Creature* cre = victim->ToCreature())
            if (!cre->hasLootRecipient())
                cre->SetLootRecipient(master);

    if (victim->GetTypeId() == TYPEID_PLAYER)
        ResetChase(victim);
}
//This function is called after Spell::SendSpellCooldown() call for players
void bot_ai::OnBotSpellGo(Spell const* spell)
{
    SpellInfo const* curInfo = spell->GetSpellInfo();
    uint32 rec = curInfo->GetRecoveryTime();
    uint32 catrec = curInfo->CategoryRecoveryTime;

    if (rec > 0)
        ApplyBotSpellCooldownMods(curInfo, rec);
    if (catrec > 0 && !(curInfo->AttributesEx6 & SPELL_ATTR6_IGNORE_CATEGORY_COOLDOWN_MODS))
        ApplyBotSpellCategoryCooldownMods(curInfo, catrec);

    //Set cooldown
    SetSpellCooldown(curInfo->GetFirstRankSpell()->Id, rec);
    SetSpellCategoryCooldown(curInfo->GetFirstRankSpell(), catrec);

    OnClassSpellGo(curInfo);
}

void bot_ai::OnBotSpellInterrupted(SpellSchoolMask schoolMask, uint32 unTimeMs)
{
    SpellInfo const* info;

    for (BotSpellMap::iterator itr = spells.begin(); itr != spells.end(); ++itr)
    {
        info = sSpellMgr->GetSpellInfo(itr->second.first);
        if (!info || !(info->GetSchoolMask() & schoolMask)) continue;
        if (info->IsCooldownStartedOnEvent()) continue;
        if (info->PreventionType != SPELL_PREVENTION_TYPE_SILENCE) continue;

        itr->second.second += unTimeMs;
        //TC_LOG_ERROR("entities.player", "OnBotSpellInterrupted(): Adding cooldown (%u, new: %u) to spell %s (id: %u, schoolmask: %u), reqSchoolMask = %u",
        //    unTimeMs, itr->second.second, info->SpellName[0], info->Id, info->SchoolMask, schoolMask);
    }
}

void bot_minion_ai::CastBotItemCombatSpell(Unit* target, WeaponAttackType attType, uint32 procVictim, uint32 procEx, Spell const* spell/* = NULL*/)
{
    if (!target || !target->IsAlive() || target == me)
        return;

    if (!me->CanUseAttackType(attType))
        return;

    Item* item;
    ItemTemplate const* proto;
    uint8 slot;
    int8 id = 1;
    EquipmentInfo const* einfo = sObjectMgr->GetEquipmentInfo(me->GetEntry(), id);

    for (uint8 i = 0; i != BOT_INVENTORY_SIZE; ++i)
    {
        item = _equips[i];
        if (!item)
            continue;

        //skip standard items
        if (i < BOT_SLOT_RANGED && einfo->ItemEntry[i] == item->GetEntry())
            continue;

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
                default:            slot = BOT_MAX_SLOTS;       break;
            }
            if (slot - 1 != i)
                continue;
        }

        CastBotItemCombatSpell(target, attType, procVictim, procEx, item, proto, spell);
    }
}

void bot_minion_ai::CastBotItemCombatSpell(Unit* target, WeaponAttackType attType, uint32 procVictim, uint32 procEx, Item* item, ItemTemplate const* proto, Spell const* /*spell*//* = NULL*/)
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

            // not allow proc extra attack spell at extra attack
            if (me->m_extraAttacks && spellInfo->HasEffect(SPELL_EFFECT_ADD_EXTRA_ATTACKS))
                return;

            float chance = float(spellInfo->ProcChance);

            if (spellData.SpellPPMRate)
            {
                uint32 WeaponSpeed = me->GetAttackTime(attType);
                chance = me->GetPPMProcChance(WeaponSpeed, spellData.SpellPPMRate, spellInfo);
            }
            else if (chance > 100.0f)
                chance = me->GetWeaponProcChance();

            if (roll_chance_f(chance))
                me->CastSpell(target, spellInfo->Id, true, item);
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
                    chance = me->GetPPMProcChance(proto->Delay, entry->ProcsPerMinute, spellInfo);
                else if (entry->Chance)
                    chance = float(entry->Chance);
            }

            //// Apply spell mods
            //ApplySpellMod(pEnchant->spellid[s], SPELLMOD_CHANCE_OF_SUCCESS, chance);

            // Shiv has 100% chance to apply the poison
            if (me->FindCurrentSpellBySpellId(5938) && e_slot == TEMP_ENCHANTMENT_SLOT)
                chance = 100.0f;

            if (roll_chance_f(chance))
            {
                if (spellInfo->IsPositive())
                    me->CastSpell(me, spellInfo, true, item);
                else
                    me->CastSpell(target, spellInfo, true, item);
            }
        }
    }
}

bool bot_minion_ai::GlobalUpdate(uint32 diff)
{
    lastdiff = diff;

    if (_updateTimerMedium <= diff)
    {
        _updateTimerMedium = 500;

        //Medium-timed updates

        //send stats update for group frames
        if (me->IsInWorld() && !IAmFree())
        {
            if (Group* gr = master->GetGroup())
            {
                if (gr->IsMember(me->GetGUID()))
                {
                    WorldPacket data;
                    BuildGrouUpdatePacket(&data);

                    Player* member;
                    for (GroupReference* itr = gr->GetFirstMember(); itr != NULL; itr = itr->next())
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

    return true;
}

void bot_minion_ai::CommonTimers(uint32 diff)
{
    events.Update(diff);
    SpellTimers(diff);

    if (Potion_cd > diff && (Potion_cd < POTION_CD || !me->IsInCombat()))
        Potion_cd -= diff;

    if (pvpTrinket_cd > diff)       pvpTrinket_cd -= diff;
    if (GC_Timer > diff)            GC_Timer -= diff;
    if (temptimer > diff)           temptimer -= diff;
    if (checkAurasTimer != 0)       --checkAurasTimer;
    if (wait != 0)                  --wait;

    if (roleTimer > diff)           roleTimer -= diff;
    else if (roleTimer > 0)         roleTimer = 0;

    if (_saveTimer > diff)          _saveTimer -= diff;
    else if (_saveTimer > 0)        _saveTimer = 0;

    if (_powersTimer > diff)        _powersTimer -= diff;
    else if (_powersTimer > 0)      _powersTimer = 0;

    if (_chaseTimer > diff)         _chaseTimer -= diff;
    else if (_chaseTimer > 0)       _chaseTimer = 0;

    if (checkMasterTimer > diff)    checkMasterTimer -= diff;
    else if (checkMasterTimer > 0)  checkMasterTimer = 0;

    if (IAmFree())
        UpdateReviveTimer(diff);

    if (_bootTimer > int32(diff))   _bootTimer -= diff;
    else if (_bootTimer > 0)        _bootTimer = 0;

    if (_updateTimerMedium > diff)  _updateTimerMedium -= diff;
}

void bot_pet_ai::CommonTimers(uint32 diff)
{
    events.Update(diff);
    SpellTimers(diff);

    if (GC_Timer > diff)            GC_Timer -= diff;
    if (temptimer > diff)           temptimer -= diff;
    if (roleTimer > diff)           roleTimer -= diff;
    if (checkAurasTimer != 0)       --checkAurasTimer;
    if (wait != 0)                  --wait;

    if (regenTimer_mp > diff)       regenTimer_mp -= diff;
    else if (regenTimer_mp > 0)     regenTimer_mp = 0;
    if (regenTimer_hp > diff)       regenTimer_hp -= diff;
    else if (regenTimer_hp > 0)     regenTimer_hp = 0;
    if (regenTimer_nrg > diff)       regenTimer_nrg -= diff;
    else if (regenTimer_nrg > 0)     regenTimer_nrg = 0;
}

void bot_minion_ai::UpdateReviveTimer(uint32 diff)
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

void bot_minion_ai::EnterEvadeMode(bool /* force */)
{
    //if (me->IsInCombat())
    //    return;
    if (me->GetVictim())
        return;
    if (IsCasting())
        return;
    if (CCed(me, true))
        return;

    if (_atHome && !_evadeMode)
        return;

    _atHome = true;

    if (!IAmFree())
    {
        _evadeMode = false;
        return;
    }

    Creature* pet = me->GetBotsPet();

    //me->CombatStop();
    //if (pet)
    //    pet->CombatStop();

    //if (!_evadeMode)
    //{
    //    ASSERT(!evadeEvent);
    //    evadeEvent = new EvadeEvent(me->GetGUID(), true);
    //    events.AddEvent(evadeEvent, events.CalculateTime(0));
    //    events.Update(0);
    //}

    uint16 mapid;
    Position pos;
    GetHomePosition(mapid, &pos);

    if (mapid != me->GetMapId() || me->GetDistance(pos) > 30.f || _evadeCount >= 3)
    {
        //TeleportHome();
        // thesawolf - TC commit adjustment
        //if (!teleHomeEvent || teleHomeEvent->to_Abort) .. there's no more bool
        if (!teleHomeEvent)
        {
            teleHomeEvent = new TeleportHomeEvent(this);
            events.AddEvent(teleHomeEvent, events.CalculateTime(1000));
            me->CastSpell(me, COSMETIC_TELEPORT_EFFECT, true);
        }
        _evadeMode = false;
        return;
    }

    float dist = me->GetDistance(pos);
    if (dist > 1.5f)
    {
        if (!_evadeMode)
            ++_evadeCount;
        else if (me->isMoving() && Rand() > 30)
            return;

        _evadeMode = true;

        //me->AddUnitState(UNIT_STATE_EVADE);
        //if (pet)
        //    pet->AddUnitState(UNIT_STATE_EVADE);

        me->BotStopMovement();
        if (pet)
            pet->BotStopMovement();

        bool farpoint = true;
        if (dist > 50)
        {
            float dx = pos.m_positionX - me->m_positionX;
            float dy = pos.m_positionY - me->m_positionY;
            float fdx = fabs(dx); float fdy = fabs(dy);
            float divider =
                fdx > 1800 || fdy > 1800 ? 120.0f :
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
        {
            me->GetMotionMaster()->MovePoint(mapid, pos);
            if (pet)
                pet->SetBotCommandState(COMMAND_FOLLOW, true);
        }

        return;
    }

    if (me->isMoving())
        return;

    _evadeMode = false;
    _evadeCount = 0;

    me->SetFacingTo(pos.GetOrientation());
    me->SetStandState(UNIT_STAND_STATE_SIT);

    //if (evadeEvent)
    //{
    //    evadeEvent->to_Abort = true;
    //    evadeEvent->Execute(evadeEvent->m_addTime, evadeEvent->m_execTime);
    //}

    //me->ClearUnitState(UNIT_STATE_EVADE);
    //if (pet)
    //    pet->ClearUnitState(UNIT_STATE_EVADE);

    me->SetFaction(me->GetCreatureTemplate()->faction);
    if (pet)
        pet->SetFaction(pet->GetCreatureTemplate()->faction);

    //RestorePositionMods();
}
//TeleportHome() ONLY CALLED THROUGH EVENTPROCESSOR
void bot_minion_ai::TeleportHome()
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

    //Reset();
}
//FinishTeleport(uint32, float, float, float, float) ONLY CALLED THROUGH EVENTPROCESSOR
bool bot_minion_ai::FinishTeleport(/*uint32 mapId, uint32 instanceId, float x, float y, float z, float o*/)
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
        events.AddEvent(teleHomeEvent, events.CalculateTime(0)); //make sure event will be deleted
        //thesawolf - recent commit adjustment
        //teleHomeEvent->to_Abort = true; //make sure event will not be executed twice
//        teleHomeEvent->ScheduleAbort();
        teleHomeEvent->Execute(0,0);
        _evadeMode = false;

        return false;
    }

    Map* map = master->FindMap();
    //2) Cannot teleport: map not found or forbidden - delay teleport
    if (!map || master->GetBotMgr()->RestrictBots(me, true))
    {
        //ChatHandler ch(master->GetSession());
        //ch.PSendSysMessage("Your bot %s cannot teleport to you. Restricted bot access on this map...", me->GetName().c_str());
        teleFinishEvent = new TeleportFinishEvent(this/*, master->GetMapId(), x, y, z, o*/);
        events.AddEvent(teleFinishEvent, events.CalculateTime(5000));
        return false;
    }

    me->SetMap(map);
    me->Relocate(master);
    map->AddToMap(me);
    me->BotStopMovement();
    //bot->SetAI(oldAI);
    me->IsAIEnabled = true;

    master->m_Controlled.insert(me);
    me->CastSpell(me, COSMETIC_TELEPORT_EFFECT, true);

    //update group member online state
    if (Group* gr = master->GetGroup())
        if (gr->IsMember(me->GetGUID()))
            gr->SendUpdate();

    return true;
}

void bot_minion_ai::AbortTeleport()
{
    if (teleHomeEvent)
    {
        //teleHomeEvent->to_Abort = true; //thesawolf
//        teleHomeEvent->ScheduleAbort();
        teleHomeEvent = NULL;
    }

    if (teleFinishEvent)
    {
        //teleFinishEvent->to_Abort = true; //thesawolf
//        teleHomeEvent->ScheduleAbort();
        teleFinishEvent = NULL;
    }

    CancelBoot();
}

void bot_ai::GetHomePosition(uint16& mapid, Position* pos)
{
    CreatureData const* data = me->GetCreatureData();
    mapid = data->spawnPoint.GetMapId();
    pos->Relocate(data->spawnPoint.GetPositionX(), data->spawnPoint.GetPositionY(), data->spawnPoint.GetPositionZ(), data->spawnPoint.GetOrientation());

}

void bot_ai::KillEvents(bool force)
{
    events.KillAllEvents(force);
}

bool bot_ai::IsBotImmuneToSpell(SpellInfo const* spellInfo) const
{
    if (spellInfo->_IsPositiveSpell())
        return false;

    if (_botclass >= BOT_CLASS_EX_START)
    {
        //bots of W3 classes will not be easily CCed
        if (spellInfo->GetDuration() > 0 && spellInfo->GetDuration() <= 3000 &&
            (spellInfo->HasAura(SPELL_AURA_MOD_STUN) ||
            spellInfo->HasAura(SPELL_AURA_MOD_CONFUSE) ||
            spellInfo->HasAura(SPELL_AURA_MOD_CHARM) ||
            spellInfo->HasAura(SPELL_AURA_MOD_FEAR) ||
            spellInfo->HasAura(SPELL_AURA_MOD_PACIFY) ||
            spellInfo->HasAura(SPELL_AURA_MOD_ROOT) ||
            spellInfo->HasAura(SPELL_AURA_AOE_CHARM)))
            return true;
    }
    return false;
}

MeleeHitOutcome bot_ai::BotRollCustomMeleeOutcomeAgainst(Unit const* victim, WeaponAttackType attType) const
{
    if (GetNextAttackMeleeOutCome() != MELEE_HIT_CRUSHING)
        return GetNextAttackMeleeOutCome();
    return me->RollMeleeOutcomeAgainst(victim, attType);
}

void bot_ai::BotJumpInPlaceInFrontOf(Position* pos, float speedXY, float maxHeight)
{
    float sign = (me->GetPositionX() < pos->GetPositionX()) ? 1.f : -1.f;
    float x = me->GetPositionX() + 0.14f * sign;
    sign = (me->GetPositionY() < pos->GetPositionY()) ? 1.f : -1.f;
    float y = me->GetPositionY() + 0.14f * sign;
    float z = me->GetPositionZ() - 0.01f;
    //float floorz = Map::GetHeight(x, y, z, true, 5.f);

    //me->AttackStop();
    me->BotStopMovement();
    me->GetMotionMaster()->MoveJump(x, y, z, speedXY, maxHeight);
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
    *data << me->GetPackGUID();
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

    Powers powerType = me->getPowerType();
    if (mask & GROUP_UPDATE_FLAG_POWER_TYPE)
        *data << uint8(powerType);

    if (mask & GROUP_UPDATE_FLAG_CUR_POWER)
        *data << uint16(me->GetPower(powerType));

    if (mask & GROUP_UPDATE_FLAG_MAX_POWER)
        *data << uint16(me->GetMaxPower(powerType));

    if (mask & GROUP_UPDATE_FLAG_LEVEL)
        *data << uint16(me->getLevel());

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
    //    for (uint32 i = 0; i < MAX_AURAS; ++i)
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
    //BotCustomSpells.insert(BLIZZARD_VISUAL_PERSISTENT_AURA);
    //BotCustomSpells.insert(BLIZZARD_VISUAL_PROC);

    //BotCustomSpells.insert(SPELL_COMBAT_SPECIAL_2H_ATTACK); //exclusive
    BotCustomSpells.insert(SPELL_TRANSPARENCY_50);//3.1
    BotCustomSpells.insert(SPELL_NETHERWALK);//3
    BotCustomSpells.insert(SPELL_MIRROR_IMAGE_BM);//4

    uint32 trig;
    SpellInfo* trigInfo;
    uint32 spellId;
    SpellInfo* sinfo;

    //1) BLIZZARD
    //1.1) BLIZZARD PROC
    //trig = BLIZZARD_VISUAL_PROC; //rain
    //trigInfo = const_cast<SpellInfo*>(sSpellMgr->GetSpellInfo(trig));

    //trigInfo->Dispel = DISPEL_NONE;
    //trigInfo->Mechanic = MECHANIC_NONE;
    //trigInfo->RangeEntry = sSpellRangeStore.LookupEntry(6); //6 - 100 yds

    //trigInfo->CastTimeEntry = sSpellCastTimesStore.LookupEntry(1); //1 - instant //3 - 0.5 sec
    //trigInfo->ManaCost = 0;
    //trigInfo->ManaCostPercentage = 0;
    //trigInfo->ManaCostPerlevel = 0;

    //trigInfo->Effects[0].Effect = SPELL_EFFECT_DUMMY;
    //trigInfo->Effects[0].BasePoints = 1;
    //trigInfo->Effects[0].TargetA = SpellImplicitTargetInfo(TARGET_DEST_CHANNEL_TARGET);
    //trigInfo->Effects[0].TargetB = SpellImplicitTargetInfo(TARGET_UNIT_DEST_AREA_ENEMY);
    //trigInfo->Effects[0].ApplyAuraName = SPELL_AURA_NONE;
    //trigInfo->Effects[0].Amplitude = 0;
    //trigInfo->Effects[0].TriggerSpell = 0;
    //trigInfo->Effects[0].RadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_8_YARDS); //14
    ////1.1) END BLIZZARD PROC

    //spellId = BLIZZARD_VISUAL_PERSISTENT_AURA; //34167, 34183
    //sinfo = const_cast<SpellInfo*>(sSpellMgr->GetSpellInfo(spellId));

    //sinfo->Dispel = DISPEL_NONE;
    //sinfo->Mechanic = MECHANIC_NONE;
    //sinfo->RangeEntry = sSpellRangeStore.LookupEntry(6); //6 - 100 yds

    //sinfo->CastTimeEntry = sSpellCastTimesStore.LookupEntry(3); //3 - 0.5 sec
    //sinfo->DurationEntry = sSpellDurationStore.LookupEntry(1); //1 - 10 sec //32 - 6 seconds
    //sinfo->ManaCost = 0;
    //sinfo->ManaCostPercentage = 74;
    //sinfo->ManaCostPerlevel = 0;
    //sinfo->AttributesEx2 |= SPELL_ATTR2_UNK22;
    //sinfo->AttributesEx5 |= SPELL_ATTR5_HASTE_AFFECT_DURATION;
    //sinfo->ExplicitTargetMask = TARGET_FLAG_DEST_LOCATION;
    //sinfo->InterruptFlags = 0x0000000F; //15
    //sinfo->ChannelInterruptFlags = 0x00007C3C; //31788

    //sinfo->Effects[0].Effect = SPELL_EFFECT_PERSISTENT_AREA_AURA;
    //sinfo->Effects[0].BasePoints = 1;
    //sinfo->Effects[0].TargetA = SpellImplicitTargetInfo(TARGET_DEST_DYNOBJ_ENEMY);
    //sinfo->Effects[0].TargetB = SpellImplicitTargetInfo(0);
    //sinfo->Effects[0].ApplyAuraName = SPELL_AURA_DUMMY;
    //sinfo->Effects[0].Amplitude = 0;
    //sinfo->Effects[0].TriggerSpell = 0;
    //sinfo->Effects[0].RadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_8_YARDS); //14

    //sinfo->Effects[1].Effect = SPELL_EFFECT_APPLY_AURA;
    //sinfo->Effects[1].BasePoints = 1;
    //sinfo->Effects[1].TargetA = SpellImplicitTargetInfo(TARGET_UNIT_CASTER);
    //sinfo->Effects[1].TargetB = SpellImplicitTargetInfo(0);
    //sinfo->Effects[1].ApplyAuraName = SPELL_AURA_PERIODIC_TRIGGER_SPELL;
    //sinfo->Effects[1].Amplitude = 2000;
    //sinfo->Effects[1].TriggerSpell = trig;
    //sinfo->Effects[1].RadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_8_YARDS); //14
    //1) END BLIZZARD
    {}
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
    sinfo->MaxLevel = 80;
    sinfo->RecoveryTime = 5000;
    sinfo->PowerType = POWER_MANA;
    sinfo->ManaCost = 75;
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
    sinfo->ManaCost = 125;
    sinfo->ManaCostPercentage = 0;
    sinfo->ManaCostPerlevel = 0;
    sinfo->Attributes |= (SPELL_ATTR0_NOT_SHAPESHIFT/* | SPELL_ATTR0_CASTABLE_WHILE_SITTING | SPELL_ATTR0_UNAFFECTED_BY_INVULNERABILITY*/);
    sinfo->AttributesEx2 &= ~(SPELL_ATTR2_CAN_TARGET_NOT_IN_LOS);
    sinfo->AttributesEx3 |= SPELL_ATTR3_DONT_DISPLAY_RANGE;

    sinfo->Effects[0].Effect = SPELL_EFFECT_DUMMY;
    sinfo->Effects[0].TargetA = SpellImplicitTargetInfo(TARGET_UNIT_CASTER);
    sinfo->Effects[0].MiscValue = 0;
    sinfo->Effects[0].MiscValueB = 0;
    sinfo->Effects[0].RadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_0_YARDS);
    //4) END MIRROR IMAGE (BLADEMASTER)
}
