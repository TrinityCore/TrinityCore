/*
* Copyright (C) 2008-2018 TrinityCore <http://www.trinitycore.org/>
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

#include "GridNotifiers.h"
#include "ObjectMgr.h"
#include "PassiveAI.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellAuras.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "SpellMgr.h"
#include "Vehicle.h"
#include "bastion_of_twilight.h"

enum Texts
{
    // Cho'Gall
    SAY_THERALION_VALIONA_INTRO             = 0,
    SAY_THERALION_VALIONA_DEATH             = 1,
    SAY_ASCENDANT_COUNCIL_INTRO_1           = 2,
    SAY_ASCENDANT_COUNCIL_INTRO_2           = 3,
    SAY_ASCENDANT_COUNCIL_INTRO_3           = 4,
    SAY_INTRO                               = 5,
    SAY_AGGRO                               = 6,
    SAY_ABSORB_FIRE_ELEMENTAL               = 7,
    SAY_ABSORB_SHADOW_LORD                  = 8,
    SAY_ANNOUNCE_SUMMON_CORRUPTING_ADHERENT = 9,
    SAY_SUMMON_CORRUPTING_ADHERENT          = 10,
    SAY_ANNOUNCE_CONVERSION                 = 11,
    SAY_ANNOUNCE_FESTER_BLOOD               = 12,
    SAY_CONSUME_BLOOD_OF_THE_OLD_GODS       = 13,
    SAY_ANNOUNCE_DARKENED_CREATIONS         = 14,
    SAY_DARKENED_CREATIONS                  = 15,
    SAY_SLAY                                = 16,
    SAY_EVADE                               = 17,
    SAY_DEATH_NORMAL                        = 18,
    SAY_DEATH_HEROIC                        = 19
};

enum BroadCastText
{
    ANNOUNCE_CORRUPTION_SICKNESS = 52818
};

enum Spells
{
    // Cho'Gall
    SPELL_CORRUPTED_BLOOD                           = 93104,
    SPELL_BOSS_HITTIN_YA                            = 73878,
    SPELL_FURY_OF_CHOGALL                           = 82524,
    SPELL_FLAMES_ORDERS                             = 81171,
    SPELL_SHADOWS_ORDERS                            = 81556,
    SPELL_SUMMON_CORRUPTING_ADHERENT                = 81628,
    SPELL_SUMMON_CORRUPTING_ADHERENT_LEFT           = 81611,
    SPELL_SUMMON_CORRUPTING_ADHERENT_RIGHT          = 81618,
    SPELL_FESTER_BLOOD                              = 82299,
    SPELL_CONVERSION                                = 91303,
    SPELL_WORSHIPPING                               = 91317,
    SPELL_WORSHIPPING_LINKED                        = 92314,
    SPELL_CONSUME_BLOOD_OF_THE_OLD_GODS             = 82630,
    SPELL_CORRUPTED_CHOGALL                         = 95821,
    SPELL_CORRUPTED_BLOOD_DAMAGE_INCREASE           = 93187,
    SPELL_CORRUPTION_ACCELERATED                    = 81836,
    SPELL_CORRUPTION_SICKNESS                       = 81829,
    SPELL_CORRUPTION_MALFORMATION                   = 82125,
    SPELL_CORRUPTION_ABSOLUTE_1                     = 82170,
    SPELL_CORRUPTION_ABSOLUTE_2                     = 82193,
    SPELL_DARKENED_CREATIONS                        = 82414,
    SPELL_SUMMON_SPIKED_TENTACLE_TRIGGER            = 93315,
    SPELL_SWAGGER_WALK                              = 93338,
    SPELL_QUITE_SUICIDE                             = 3617,

    // Corrupting Adherent
    SPELL_CORRUPTING_CRASH                          = 81685,
    SPELL_SPILLED_BLOOD_OF_THE_OLD_GODS_1           = 81771,
    SPELL_SPILLED_BLOOD_OF_THE_OLD_GODS_2           = 81757,
    SPELL_CONSUME_BLOOD_OF_THE_OLD_GOD_TRIGGERED    = 82659,

    // Fire Portal
    SPELL_FLAMES_ORDERS_SUMMON                      = 81186,

    // Shadow Portal
    SPELL_SHADOWS_ORDERS_SUMMON                     = 81558,

    // Fire Elemental
    SPELL_FIRE_POWER                                = 93245,
    SPELL_ABSORB_FIRE_REVERSE_CAST                  = 81233,

    // Shadow Lord
    SPELL_SHADOW_POWER                              = 93301,
    SPELL_ABSORB_SHADOW_REVERSE_CAST                = 81565,

    // Malformation
    SPELL_SHADOW_BOLT                               = 82151,

    // Darkened Creation
    SPELL_DARKENED_CREATION_SUMMON_VISUAL           = 82452,
    SPELL_TRANSFORM_EYE_TENTACLE                    = 82451,
    SPELL_VOID_ZONE_VISUAL                          = 82397,
    SPELL_DEBILITATING_BEAM                         = 82411
};

#define SPELL_DEPRAVITY         RAID_MODE<uint32>(81713, 93175, 93176, 93177)
#define SPELL_DEBILITATING_BEAM RAID_MODE<int32>(82411, 93132, 93133, 93134)

enum Events
{
    // Cho'Gall
    EVENT_FURY_OF_CHOGALL = 1,
    EVENT_FLAMES_ORDER,
    EVENT_SHADOWS_ORDERS,
    EVENT_SUMMON_CORRUPTING_ADHERENT,
    EVENT_FESTER_BLOOD,
    EVENT_CONVERSION,
    EVENT_CONSUME_BLOOD_OF_THE_OLD_GOD,
    EVENT_CHECK_BLOOD_OF_THE_OLD_GOD_BUFF,
    EVENT_DARKENED_CREATIONS,
    EVENT_SUMMON_SPIKED_TENTACLE,

    // Corrupting Adherent / Blood of the Old God
    EVENT_ENGAGE_PLAYERS,
    EVENT_CORRUPTING_CRASH,
    EVENT_DEPRAVITY,

    // Portals
    EVENT_SUMMON_ELEMENTAL,
    EVENT_PREPARE_DESPAWN,

    // Elementals
    EVENT_ABSORB_ELEMENTAL,

    // Malformation
    EVENT_SHADOW_BOLT,

    // Darkened Creation
    EVENT_TRANSFORM,
    EVENT_DEBILITATING_BEAM
};

enum Phases
{
    PHASE_1 = 1,
    PHASE_2 = 2,
    PHASE_HEROIC_DEATH
};

enum Actions
{
    // 1 - 6 used by header file
    ACTION_FAIL_ACHIEVEMENT = 7
};

enum Data
{
    DATA_ELEMENTAL_POWER_STACKS     = 0,
    DATA_ABYSS_WILL_GAZE_INTO_YOU   = 1
};

enum Corruption
{
    MAX_CORRUPTION                  = 100,
    CORRUPTION_ACHIEVEMENT_CAP      = 30,

    CORRUPTION_NORMAL               = 1,
    CORRUPTION_SIGNIFICANT          = 10,

    CORRUPTION_LEVEL_ACCELERATED    = 25,
    CORRUPTION_LEVEL_SICKNESS       = 50,
    CORRUPTION_LEVEL_MALFORMATION   = 75,
    CORRUPTION_LEVEL_ABSOLUTE       = 100
};

enum MovePoints
{
    POINT_BREAK_PLATFORM = 1
};

enum Seats
{
    SEAT_0 = 0
};

namespace CorruptionHandler
{
    bool IsCorruptionStage(uint8 power)
    {
        return (power == CORRUPTION_LEVEL_ACCELERATED
            || power == CORRUPTION_LEVEL_SICKNESS
            || power == CORRUPTION_LEVEL_MALFORMATION
            || power == CORRUPTION_LEVEL_ABSOLUTE);
    }

    uint32 GetSpellIdForCorruptionLevel(uint8 power, uint8 additionalPower)
    {
        for (uint8 i = power; i <= (power + additionalPower); i++)
        {
            switch (i)
            {
                case CORRUPTION_LEVEL_ACCELERATED:
                    return SPELL_CORRUPTION_ACCELERATED;
                case CORRUPTION_LEVEL_SICKNESS:
                    return SPELL_CORRUPTION_SICKNESS;
                case CORRUPTION_LEVEL_MALFORMATION:
                    return SPELL_CORRUPTION_MALFORMATION;
                case CORRUPTION_LEVEL_ABSOLUTE:
                    return SPELL_CORRUPTION_ABSOLUTE_1;
            }
        }

        return 0;
    }

    void AddCorruption(Unit* target, uint8 corruptionAmount)
    {
        uint8 power = target->GetPower(POWER_ALTERNATE_POWER);

        if (power == MAX_CORRUPTION)
            return;

        // Checking for a corruption spell for current corruption stage and cast it
        if (uint32 spellId = GetSpellIdForCorruptionLevel(power, corruptionAmount))
        {
            target->CastSpell(target, spellId, true);

            if (spellId == SPELL_CORRUPTION_ABSOLUTE_1)
                target->CastSpell(target, SPELL_CORRUPTION_ABSOLUTE_2, true);
        }

        // Add power to target
        power += corruptionAmount;
        target->SetPower(POWER_ALTERNATE_POWER, std::min(power, uint8(MAX_CORRUPTION)));
        target->CastCustomSpell(SPELL_CORRUPTED_BLOOD_DAMAGE_INCREASE, SPELLVALUE_AURA_STACK, corruptionAmount, target, true);

        // Achievement check
        if (power > CORRUPTION_ACHIEVEMENT_CAP)
            if (InstanceScript* instance = target->GetInstanceScript())
                if (Creature* chogall = instance->GetCreature(DATA_CHOGALL))
                    chogall->AI()->DoAction(ACTION_FAIL_ACHIEVEMENT);
    }
}

Position const HeroicDeathPos       = { -1161.89f, -798.441f, 835.8751f };
Position const HeroicTeleportPos    = { -1130.75f, -817.314f, 467.747f, 5.191174f };

class BreakTrapDoorEvent : public BasicEvent
{
    public:
        explicit BreakTrapDoorEvent(Creature* owner): _owner(owner) { }

        bool Execute(uint64 /*time*/, uint32 /*diff*/)
        {
            if (InstanceScript* instance = _owner->GetInstanceScript())
                if (GameObject* trapDoor = instance->GetGameObject(DATA_GRIM_BATOL_RAID_TRAP_DOOR))
                    trapDoor->SetGoState(GO_STATE_ACTIVE);

            _owner->GetMotionMaster()->MoveFall();
            return true;
        }

    private:
        Creature* _owner;
};

class TeleportAfterFallEvent : public BasicEvent
{
    public:
        explicit TeleportAfterFallEvent(Creature* owner): _owner(owner) { }

        bool Execute(uint64 /*time*/, uint32 /*diff*/)
        {
            _owner->NearTeleportTo(HeroicTeleportPos);
            return true;
        }

    private:
        Creature* _owner;
};

struct boss_chogall : public BossAI
{
    boss_chogall(Creature* creature) : BossAI(creature, DATA_CHOGALL)
    {
        Initialize();
    }

    void Initialize()
    {
        _elementalPowerStacks = 0;
        _firstDarkenedCreations = true;
        _allowDeath = true;
        _achievementEnligibe = true;
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _JustEngagedWith();
        Talk(SAY_AGGRO);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
        DoCastSelf(SPELL_CORRUPTED_BLOOD);
        events.SetPhase(PHASE_1);
        events.ScheduleEvent(EVENT_FURY_OF_CHOGALL, 57s + 800ms);
        events.ScheduleEvent(EVENT_FLAMES_ORDER, 6s + 100ms, 0, PHASE_1);
        events.ScheduleEvent(EVENT_SHADOWS_ORDERS, 20s + 800ms, 0, PHASE_1);
        events.ScheduleEvent(EVENT_SUMMON_CORRUPTING_ADHERENT, 2min + 4s, 0, PHASE_1);
        events.ScheduleEvent(EVENT_CONVERSION, 11s, 0, PHASE_1);

        if (instance->GetData(DATA_FULL_HEROIC_ID) && IsHeroic())
            _allowDeath = false;
    }

    void Reset()
    {
        _Reset();
        Initialize();
        DoCastSelf(SPELL_BOSS_HITTIN_YA, true);
    }

    void KilledUnit(Unit* who) override
    {
        if (who->GetTypeId() == TYPEID_PLAYER)
            Talk(SAY_SLAY);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        _EnterEvadeMode();
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        summons.DespawnAll();
        Talk(SAY_EVADE);

        if (Creature* corruption = instance->GetCreature(DATA_CORRUPTION))
            corruption->RemoveAllAuras();

        _DespawnAtEvade();
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        if (Creature* corruption = instance->GetCreature(DATA_CORRUPTION))
            corruption->RemoveAllAuras();

        if (!instance->GetData(DATA_FULL_HEROIC_ID) || !IsHeroic())
            Talk(SAY_DEATH_NORMAL);
    }

    void SpellHit(Unit* /*caster*/, SpellInfo const* spell) override
    {
        switch (spell->Id)
        {
            case SPELL_ABSORB_FIRE_REVERSE_CAST:
                Talk(SAY_ABSORB_FIRE_ELEMENTAL);
                break;
            case SPELL_ABSORB_SHADOW_REVERSE_CAST:
                if (roll_chance_i(20))
                    Talk(SAY_ABSORB_SHADOW_LORD);
                break;
            default:
                break;
        }
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_TALK_THERALION_AND_VALIONA_INTRO:
                Talk(SAY_THERALION_VALIONA_INTRO);
                break;
            case ACTION_TALK_THERALION_AND_VALIONA_DEAD:
                Talk(SAY_THERALION_VALIONA_DEATH);
                break;
            case ACTION_TALK_ASCENDANT_COUNCIL_INTRO_1:
                Talk(SAY_ASCENDANT_COUNCIL_INTRO_1);
                break;
            case ACTION_TALK_ASCENDANT_COUNCIL_INTRO_2:
                Talk(SAY_ASCENDANT_COUNCIL_INTRO_2);
                break;
            case ACTION_TALK_ASCENDANT_COUNCIL_INTRO_3:
                Talk(SAY_ASCENDANT_COUNCIL_INTRO_3);
                break;
            case ACTION_TALK_CHOGALL_INTRO:
                Talk(SAY_INTRO);
                break;
            case ACTION_FAIL_ACHIEVEMENT:
                _achievementEnligibe = false;
                break;
            default:
                break;
        }
    }

    void PassengerBoarded(Unit* passenger, int8 /*seatId*/, bool apply) override
    {
        if (!passenger || !apply)
            return;

        uint32 spellId = SPELL_SHADOW_POWER;
        if (passenger->GetEntry() == NPC_FIRE_ELEMENTAL)
            spellId = SPELL_FIRE_POWER;

        if (Aura* aura = passenger->GetAura(spellId))
        {
            _elementalPowerStacks = aura->GetStackAmount();
            aura->Remove();
        }
    }

    uint32 GetData(uint32 type) const override
    {
        switch (type)
        {
            case DATA_ELEMENTAL_POWER_STACKS:
                return _elementalPowerStacks;
            case DATA_ABYSS_WILL_GAZE_INTO_YOU:
                return _achievementEnligibe;
        }
        return 0;
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage) override
    {
        if (me->HealthBelowPctDamaged(25, damage) && !events.IsInPhase(PHASE_2) && !events.IsInPhase(PHASE_HEROIC_DEATH))
        {
            events.SetPhase(PHASE_2);
            events.ScheduleEvent(EVENT_CONSUME_BLOOD_OF_THE_OLD_GOD, 1ms, 0, PHASE_2);
        }


        if (damage >= me->GetHealth() && !_allowDeath)
        {
            damage = me->GetHealth() - 1;

            if (!events.IsInPhase(PHASE_HEROIC_DEATH))
            {
                events.SetPhase(PHASE_HEROIC_DEATH);
                me->AttackStop();
                me->SetReactState(REACT_PASSIVE);
                Talk(SAY_DEATH_HEROIC);
                DoCastSelf(SPELL_SWAGGER_WALK, true);
                me->SetWalk(true);
                me->GetMotionMaster()->MovePoint(POINT_BREAK_PLATFORM, HeroicDeathPos, false);
            }
        }
    }

    void MovementInform(uint32 type, uint32 id) override
    {
        if (type != POINT_MOTION_TYPE && type != EFFECT_MOTION_TYPE)
            return;

        if (id == POINT_BREAK_PLATFORM)
        {
            _allowDeath = true;
            DoCastSelf(SPELL_QUITE_SUICIDE, true);
            me->m_Events.AddEvent(new BreakTrapDoorEvent(me), me->m_Events.CalculateTime(3000));
            me->m_Events.AddEvent(new TeleportAfterFallEvent(me), me->m_Events.CalculateTime(4000));
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_FURY_OF_CHOGALL:
                    DoCastVictim(SPELL_FURY_OF_CHOGALL);
                    events.Repeat(47s + 500ms);
                    break;
                case EVENT_FLAMES_ORDER:
                    DoCastSelf(SPELL_FLAMES_ORDERS);
                    events.Repeat(40s);
                    break;
                case EVENT_SHADOWS_ORDERS:
                    DoCastSelf(SPELL_SHADOWS_ORDERS);
                    events.Repeat(40s);
                    break;
                case EVENT_SUMMON_CORRUPTING_ADHERENT:
                    Talk(SAY_ANNOUNCE_SUMMON_CORRUPTING_ADHERENT);
                    Talk(SAY_SUMMON_CORRUPTING_ADHERENT);
                    DoCastAOE(SPELL_SUMMON_CORRUPTING_ADHERENT);
                    events.Repeat(1min + 32s + 300ms);
                    events.ScheduleEvent(EVENT_FESTER_BLOOD, 39s, 0, PHASE_1);
                    break;
                case EVENT_FESTER_BLOOD:
                    Talk(SAY_ANNOUNCE_FESTER_BLOOD);
                    DoCastAOE(SPELL_FESTER_BLOOD);
                    break;
                case EVENT_CONVERSION:
                    Talk(SAY_ANNOUNCE_CONVERSION);
                    DoCastAOE(SPELL_CONVERSION);
                    events.Repeat(21s, 25s);
                    break;
                case EVENT_CONSUME_BLOOD_OF_THE_OLD_GOD:
                    Talk(SAY_CONSUME_BLOOD_OF_THE_OLD_GODS);
                    DoCastAOE(SPELL_CONSUME_BLOOD_OF_THE_OLD_GODS);
                    events.ScheduleEvent(EVENT_CHECK_BLOOD_OF_THE_OLD_GOD_BUFF, 5s + 100ms, 0, PHASE_2);
                    events.ScheduleEvent(EVENT_DARKENED_CREATIONS, 6s, 0, PHASE_2);
                    if (IsHeroic())
                        events.ScheduleEvent(EVENT_SUMMON_SPIKED_TENTACLE, 16s + 800ms, 0, PHASE_2);
                    break;
                case EVENT_CHECK_BLOOD_OF_THE_OLD_GOD_BUFF:
                    // Make sure that we always get the Blood of the Old God triggered aura in case that
                    // Phase 2 has been triggered before any Corrupting Adherent has been spawned.
                    if (!me->HasAura(SPELL_CONSUME_BLOOD_OF_THE_OLD_GOD_TRIGGERED))
                        DoCastSelf(SPELL_CONSUME_BLOOD_OF_THE_OLD_GOD_TRIGGERED);
                    break;
                case EVENT_DARKENED_CREATIONS:
                    if (_firstDarkenedCreations)
                        _firstDarkenedCreations = false;
                    else
                    {
                        Talk(SAY_ANNOUNCE_DARKENED_CREATIONS);
                        Talk(SAY_DARKENED_CREATIONS);
                    }

                    DoCastAOE(SPELL_DARKENED_CREATIONS);
                    events.Repeat(IsHeroic() ? 30s : 40s);
                    break;
                case EVENT_SUMMON_SPIKED_TENTACLE:
                    DoCastAOE(SPELL_SUMMON_SPIKED_TENTACLE_TRIGGER);
                    events.Repeat(20s);
                    break;
                default:
                    break;
            }
        }
        DoMeleeAttackIfReady();
    }
private:
    uint8 _elementalPowerStacks;
    bool _firstDarkenedCreations;
    bool _allowDeath;
    bool _achievementEnligibe;
};

class SpilledBloodAuraEvent : public BasicEvent
{
    public:
        explicit SpilledBloodAuraEvent(Creature* owner): _owner(owner) { }

        bool Execute(uint64 /*time*/, uint32 /*diff*/)
        {
            _owner->CastSpell(_owner, SPELL_SPILLED_BLOOD_OF_THE_OLD_GODS_2, true);
            return true;
        }

    private:
        Creature* _owner;
};

struct npc_chogall_corrupting_adherent : public ScriptedAI
{
    npc_chogall_corrupting_adherent(Creature* creature) : ScriptedAI(creature)
    {
        Initialize();
    }

    void Initialize()
    {
        me->MakeInterruptable(false);
        me->SetReactState(REACT_PASSIVE);
        DoZoneInCombat();
    }

    void IsSummonedBy(Unit* /*summoner*/) override
    {
        me->SetCorpseDelay(HOUR);
        DoCastSelf(SPELL_BOSS_HITTIN_YA, true);
        _events.ScheduleEvent(EVENT_ENGAGE_PLAYERS, 2s);
        _events.ScheduleEvent(EVENT_CORRUPTING_CRASH, 9s + 600ms);
    }

    void OnSpellCastInterrupt(SpellInfo const* spell) override
    {
        if (spell->Id == SPELL_DEPRAVITY)
            me->MakeInterruptable(false);
    }

    void OnSuccessfulSpellCast(SpellInfo const* spell) override
    {
        if (spell->Id == SPELL_DEPRAVITY)
            me->MakeInterruptable(false);
    }

    void SpellHit(Unit* /*caster*/, SpellInfo const* spell) override
    {
        if (spell->Id == SPELL_CONSUME_BLOOD_OF_THE_OLD_GODS)
        {
            _events.Reset();
            me->AttackStop();
            me->SetReactState(REACT_PASSIVE);
            me->DespawnOrUnsummon(6s + 750ms);
        }
    }

    void JustDied(Unit* /*killer*/) override
    {
        _events.Reset();
        DoCastSelf(SPELL_SPILLED_BLOOD_OF_THE_OLD_GODS_1, true);
        me->m_Events.AddEvent(new SpilledBloodAuraEvent(me), me->m_Events.CalculateTime(5100));
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_ENGAGE_PLAYERS:
                    me->SetReactState(REACT_AGGRESSIVE);
                    if (Unit* target = me->SelectNearbyTarget(nullptr, 100.0f))
                        AttackStart(target);
                    break;
                case EVENT_CORRUPTING_CRASH:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true, 0))
                        DoCast(target, SPELL_CORRUPTING_CRASH);
                    _events.Repeat(11s);
                    _events.ScheduleEvent(EVENT_DEPRAVITY, 1s + 400ms);
                    break;
                case EVENT_DEPRAVITY:
                    me->MakeInterruptable(true);
                    DoCastAOE(SPELL_DEPRAVITY);
                    break;
                default:
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }
private:
    EventMap _events;
};

struct npc_chogall_blood_of_the_old_god : public ScriptedAI
{
    npc_chogall_blood_of_the_old_god(Creature* creature) : ScriptedAI(creature), _instance(me->GetInstanceScript())
    {
        Initialize();
    }

    void Initialize()
    {
        me->SetReactState(REACT_PASSIVE);
    }

    void IsSummonedBy(Unit* /*summoner*/) override
    {
        if (Creature* chogall = _instance->GetCreature(DATA_CHOGALL))
            chogall->AI()->JustSummoned(me);

        DoZoneInCombat();
        _events.ScheduleEvent(EVENT_ENGAGE_PLAYERS, 2s + 200ms);
    }

    void JustDied(Unit* /*killer*/) override
    {
        me->DespawnOrUnsummon(2s + 500ms);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_ENGAGE_PLAYERS:
                    me->SetReactState(REACT_AGGRESSIVE);
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true, 0))
                    {
                        me->AddThreat(target, 100000000.0f); // sniffed value
                        AttackStart(target);
                    }
                    break;
                default:
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }

private:
    EventMap _events;
    InstanceScript* _instance;
};

struct npc_chogall_portal : public ScriptedAI
{
    npc_chogall_portal(Creature* creature) : ScriptedAI(creature) { }

    void IsSummonedBy(Unit* /*summoner*/) override
    {
        _events.ScheduleEvent(EVENT_SUMMON_ELEMENTAL, 6s + 100ms);
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_SUMMON_ELEMENTAL:
                    DoCastSelf(me->GetEntry() == NPC_FIRE_PORTAL ? SPELL_FLAMES_ORDERS_SUMMON : SPELL_SHADOWS_ORDERS_SUMMON);
                    _events.ScheduleEvent(EVENT_PREPARE_DESPAWN, 5s + 800ms);
                    break;
                case EVENT_PREPARE_DESPAWN:
                    me->RemoveAllAuras();
                    me->DespawnOrUnsummon(1s + 200ms);
                    break;
                default:
                    break;
            }
        }
    }

private:
    EventMap _events;
};

struct npc_chogall_elemental : public PassiveAI
{
    npc_chogall_elemental(Creature* creature) : PassiveAI(creature), _instance(me->GetInstanceScript()) { }

    void IsSummonedBy(Unit* /*summoner*/) override
    {
        DoZoneInCombat();
        if (Creature* chogall = _instance->GetCreature(DATA_CHOGALL))
            chogall->AI()->JustSummoned(me);

        if (me->GetEntry() == NPC_FIRE_ELEMENTAL)
            me->CastCustomSpell(SPELL_FIRE_POWER, SPELLVALUE_AURA_STACK, 10, me, true);
        else
            me->CastCustomSpell(SPELL_SHADOW_POWER, SPELLVALUE_AURA_STACK, 10, me, true);

        _events.ScheduleEvent(EVENT_ABSORB_ELEMENTAL, 10s + 500ms);
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage) override
    {
        if (damage >= me->GetHealth())
            damage = me->GetHealth() - 1;
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_ABSORB_ELEMENTAL:
                    if (Creature* chogall = _instance->GetCreature(DATA_CHOGALL))
                    {
                        if (!chogall->HasUnitState(UNIT_STATE_CASTING))
                        {
                            if (me->GetEntry() == NPC_FIRE_ELEMENTAL)
                                DoCastSelf(SPELL_ABSORB_FIRE_REVERSE_CAST);
                            else
                                DoCastSelf(SPELL_ABSORB_SHADOW_REVERSE_CAST);
                            me->DespawnOrUnsummon(2s + 600ms);
                        }
                        else
                            _events.Repeat(1s);
                    }
                    break;
                default:
                    break;
            }
        }
    }

private:
    EventMap _events;
    InstanceScript* _instance;
};

struct npc_chogall_malformation : public ScriptedAI
{
    npc_chogall_malformation(Creature* creature) : ScriptedAI(creature), _instance(me->GetInstanceScript()) { }

    void IsSummonedBy(Unit* /*summoner*/) override
    {
        _events.ScheduleEvent(EVENT_SHADOW_BOLT, 1s + 500ms);
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_SHADOW_BOLT:
                    DoCastAOE(EVENT_SHADOW_BOLT);
                    _events.Repeat(2s);
                    break;
                default:
                    break;
            }
        }
    }

private:
    EventMap _events;
    InstanceScript* _instance;
};

struct npc_chogall_darkened_creation : public ScriptedAI
{
    npc_chogall_darkened_creation(Creature* creature) : ScriptedAI(creature), _instance(me->GetInstanceScript())
    {
        Initialize();
    }

    void Initialize()
    {
        me->SetReactState(REACT_PASSIVE);
    }

    void IsSummonedBy(Unit* /*summoner*/) override
    {
        if (Creature* chogall = _instance->GetCreature(DATA_CHOGALL))
            chogall->AI()->JustSummoned(me);

        DoZoneInCombat();
        DoCastSelf(SPELL_DARKENED_CREATION_SUMMON_VISUAL);

        _events.ScheduleEvent(EVENT_TRANSFORM, 3s + 500ms);
        me->SetCorpseDelay(4);
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_TRANSFORM:
                    DoCastSelf(SPELL_TRANSFORM_EYE_TENTACLE);
                    DoCastSelf(SPELL_VOID_ZONE_VISUAL);
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                    _events.ScheduleEvent(EVENT_DEBILITATING_BEAM, 1s + 300ms);
                    break;
                case EVENT_DEBILITATING_BEAM:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true, -SPELL_DEBILITATING_BEAM))
                    {
                        me->SetFacingToObject(target);
                        DoCast(target, SPELL_DEBILITATING_BEAM);
                    }
                    _events.Repeat(1s + 500ms);
                    break;
                default:
                    break;
            }
        }
    }

private:
    EventMap _events;
    InstanceScript* _instance;
};

struct npc_chogall_spiked_tentacle : public ScriptedAI
{
    npc_chogall_spiked_tentacle(Creature* creature) : ScriptedAI(creature), _instance(me->GetInstanceScript())
    {
        Initialize();
    }

    void Initialize()
    {
        me->SetReactState(REACT_PASSIVE);
    }

    void IsSummonedBy(Unit* /*summoner*/) override
    {
        if (Creature* chogall = _instance->GetCreature(DATA_CHOGALL))
            chogall->AI()->JustSummoned(me);

        DoZoneInCombat();
        _events.ScheduleEvent(EVENT_ENGAGE_PLAYERS, 2s + 200ms);
    }

    void JustDied(Unit* /*killer*/) override
    {
        me->DespawnOrUnsummon(4s);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_ENGAGE_PLAYERS:
                    me->SetReactState(REACT_AGGRESSIVE);
                    break;
                default:
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }

private:
    EventMap _events;
    InstanceScript* _instance;
};

class spell_chogall_absorb_elemental_reverse_cast : public SpellScript
{
    PrepareSpellScript(spell_chogall_absorb_elemental_reverse_cast);

    void HandleScriptEffect(SpellEffIndex effIndex)
    {
        GetHitUnit()->CastSpell(GetHitUnit(), GetSpellInfo()->Effects[effIndex].BasePoints);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_chogall_absorb_elemental_reverse_cast::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

class spell_chogall_absorb_elemental : public SpellScript
{
    PrepareSpellScript(spell_chogall_absorb_elemental);

    void HandleScriptEffect(SpellEffIndex effIndex)
    {
        if (Unit* caster = GetCaster())
            GetHitUnit()->CastSpell(caster, GetSpellInfo()->Effects[effIndex].BasePoints, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_chogall_absorb_elemental::HandleScriptEffect, EFFECT_2, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

class spell_chogall_absorb_elemental_heroic : public SpellScript
{
    PrepareSpellScript(spell_chogall_absorb_elemental_heroic);

    void HandleScriptEffect(SpellEffIndex effIndex)
    {
        if (Unit* caster = GetCaster())
            GetHitUnit()->CastSpell(caster, GetSpellInfo()->Effects[effIndex].BasePoints, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_chogall_absorb_elemental_heroic::HandleScriptEffect, EFFECT_2, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

class spell_chogall_absorb_elemental_heroic_AuraScript : public AuraScript
{
    PrepareAuraScript(spell_chogall_absorb_elemental_heroic_AuraScript);

    void HandlePeriodic(AuraEffect const* /*aurEff*/)
    {
        Unit* target = GetTarget();
        InstanceScript* instance = target->GetInstanceScript();
        if (!instance)
            return;

        if (Creature* chogall = instance->GetCreature(DATA_CHOGALL))
            if (uint8 stacks = chogall->AI()->GetData(DATA_ELEMENTAL_POWER_STACKS))
                target->CastCustomSpell(GetSpellInfo()->Effects[EFFECT_0].TriggerSpell, SPELLVALUE_AURA_STACK, stacks, target, true);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_chogall_absorb_elemental_heroic_AuraScript::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

class spell_chogall_elemental_power : public AuraScript
{
    PrepareAuraScript(spell_chogall_elemental_power);

    void HandlePeriodic(AuraEffect const* /*aurEff*/)
    {
        if (uint8 stackAmount = std::ceil(GetTarget()->GetHealthPct() / 10))
            if (GetStackAmount() > stackAmount)
                SetStackAmount(stackAmount);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_chogall_elemental_power::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

class spell_chogall_flaming_destruction_heroic : public AuraScript
{
    PrepareAuraScript(spell_chogall_flaming_destruction_heroic);

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();

        Unit* caster = GetTarget();

        Unit* target = eventInfo.GetProcTarget();
        if (!target)
            return;

        uint32 spellId = sSpellMgr->GetSpellIdForDifficulty(GetSpellInfo()->Effects[aurEff->GetEffIndex()].TriggerSpell, caster);
        SpellInfo const* spell = sSpellMgr->AssertSpellInfo(spellId);

        uint8 stacks = GetStackAmount();
        int32 bp = spell->Effects[EFFECT_0].CalcValue();
        bp += CalculatePct(bp, stacks * 10);
        caster->CastCustomSpell(spell->Id, SPELLVALUE_BASE_POINT0, bp, target, true, nullptr, aurEff);
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_chogall_flaming_destruction_heroic::HandleProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
    }
};

class spell_chogall_empowered_shadows_heroic : public AuraScript
{
    PrepareAuraScript(spell_chogall_empowered_shadows_heroic);

    void HandlePeriodic(AuraEffect const* aurEff)
    {
        PreventDefaultAction();

        Unit* caster = GetTarget();

        uint32 spellId = sSpellMgr->GetSpellIdForDifficulty(GetSpellInfo()->Effects[aurEff->GetEffIndex()].TriggerSpell, caster);
        SpellInfo const* spell = sSpellMgr->AssertSpellInfo(spellId);

        uint8 stacks = GetStackAmount();
        int32 bp = spell->Effects[EFFECT_0].CalcValue();
        bp += CalculatePct(bp, stacks * 5);
        caster->CastCustomSpell(spell->Id, SPELLVALUE_BASE_POINT0, bp, caster, true, nullptr, aurEff);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_chogall_empowered_shadows_heroic::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
};

class spell_chogall_summon_corrupted_adherent : public SpellScript
{
    PrepareSpellScript(spell_chogall_summon_corrupted_adherent);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_SUMMON_CORRUPTING_ADHERENT_LEFT,
                SPELL_SUMMON_CORRUPTING_ADHERENT_RIGHT,
            });
    }

    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        if (Unit* caster = GetCaster())
        {
            if (caster->GetMap()->Is25ManRaid() && caster->GetMap()->IsHeroic())
            {
                caster->CastSpell(caster, SPELL_SUMMON_CORRUPTING_ADHERENT_LEFT, true);
                caster->CastSpell(caster, SPELL_SUMMON_CORRUPTING_ADHERENT_RIGHT, true);
            }
            else
            {
                bool left = RAND(0, 1) == 0;
                caster->CastSpell(caster, left ? SPELL_SUMMON_CORRUPTING_ADHERENT_LEFT : SPELL_SUMMON_CORRUPTING_ADHERENT_RIGHT, true);
            }
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_chogall_summon_corrupted_adherent::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

class CorruptorDeathStateCheck
{
    public:
        CorruptorDeathStateCheck(bool alive) : _alive(alive) { }

        bool operator()(WorldObject* object)
        {
            if (Unit* target = object->ToUnit())
                return _alive ? target->IsAlive() : target->isDead();

            return false;
        }
    private:
        bool _alive;

};

class spell_chogall_fester_blood : public SpellScript
{
    PrepareSpellScript(spell_chogall_fester_blood);

    void FilterAliveTargets(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
            return;

        targets.remove_if(CorruptorDeathStateCheck(true));
    }

    void FilterDeadTargets(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
            return;

        targets.remove_if(CorruptorDeathStateCheck(false));
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_chogall_fester_blood::FilterAliveTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_chogall_fester_blood::FilterDeadTargets, EFFECT_1, TARGET_UNIT_SRC_AREA_ENTRY);
    }
};

class spell_chogall_fester_blood_summon : public SpellScript
{
    PrepareSpellScript(spell_chogall_fester_blood_summon);

    void HandleScriptEffect(SpellEffIndex effIndex)
    {
        for (uint8 i = 0; i < 4; i++)
            GetHitUnit()->CastSpell(GetHitUnit(), GetSpellInfo()->Effects[effIndex].BasePoints, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_chogall_fester_blood_summon::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

class spell_chogall_conversion : public SpellScript
{
    PrepareSpellScript(spell_chogall_conversion);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_WORSHIPPING });
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
            return;

        Trinity::Containers::RandomResize(targets, GetCaster()->GetMap()->Is25ManRaid() ? 4 : 2);
    }

    void HandleScriptEffect(SpellEffIndex effIndex)
    {
        if (Unit* target = GetHitUnit())
        {
            target->CastStop();
            target->StopMoving();
            target->CastSpell(target, SPELL_WORSHIPPING, true);
        }
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_chogall_conversion::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        OnEffectHitTarget += SpellEffectFn(spell_chogall_conversion::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

class spell_chogall_worshipping : public AuraScript
{
    PrepareAuraScript(spell_chogall_worshipping);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_WORSHIPPING });
    }

    void AfterApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();

        target->CastSpell(target, SPELL_WORSHIPPING_LINKED, true);
        if (Player* player = target->ToPlayer())
            player->SetClientControl(player, false);

        if (InstanceScript* instance = target->GetInstanceScript())
            if (Creature* chogall = instance->GetCreature(DATA_CHOGALL))
                target->SetFacingToObject(chogall, true);
    }

    void AfterRemmove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();

        target->RemoveAurasDueToSpell(SPELL_WORSHIPPING_LINKED);
        if (Player* player = target->ToPlayer())
            player->SetClientControl(player, true);
    }

    void Register() override
    {
        AfterEffectApply += AuraEffectApplyFn(spell_chogall_worshipping::AfterApply, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
        AfterEffectRemove += AuraEffectRemoveFn(spell_chogall_worshipping::AfterRemmove, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
    }
};

class spell_chogall_consume_blood_of_the_old_god : public AuraScript
{
    PrepareAuraScript(spell_chogall_consume_blood_of_the_old_god);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_CONSUME_BLOOD_OF_THE_OLD_GOD_TRIGGERED });
    }

    void AfterRemmove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->CastSpell(GetTarget(), SPELL_CONSUME_BLOOD_OF_THE_OLD_GOD_TRIGGERED, true);
    }

    void HandlePeriodic(AuraEffect const* /*aurEff*/)
    {
        // Blizzard is using two different periodic auras, one for the alive adherents and one for the dead ones.
        // Since we cannot filter the targets reliably without risking getting a no-target error when one
        // of the target lists is empty, we handle both of them in EFFECT_0 instead.
        // On the other hand, we cannot see in sniffs which effect gets applied on which target so we have to assume
        // that it works like this so we do not need a duplicate triggered spell in this case
        PreventDefaultAction();
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_chogall_consume_blood_of_the_old_god::AfterRemmove, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_chogall_consume_blood_of_the_old_god::HandlePeriodic, EFFECT_1, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
};

class spell_chogall_consume_blood_of_the_old_god_triggered : public SpellScript
{
    PrepareSpellScript(spell_chogall_consume_blood_of_the_old_god_triggered);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_CORRUPTED_CHOGALL });
    }

    void HandleScriptEffect(SpellEffIndex effIndex)
    {
        if (Unit* target = GetHitUnit())
        {
            target->CastSpell(target, GetSpellInfo()->Effects[effIndex].BasePoints, true);
            target->CastSpell(target, SPELL_CORRUPTED_CHOGALL, true);
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_chogall_consume_blood_of_the_old_god_triggered::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

class spell_chogall_corruption_significant : public SpellScript
{
    PrepareSpellScript(spell_chogall_corruption_significant);

    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        CorruptionHandler::AddCorruption(GetHitUnit(), CORRUPTION_SIGNIFICANT);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_chogall_corruption_significant::HandleScriptEffect, EFFECT_1, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

class spell_chogall_corruption_normal : public SpellScript
{
    PrepareSpellScript(spell_chogall_corruption_normal);

    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        CorruptionHandler::AddCorruption(GetHitUnit(), CORRUPTION_NORMAL);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_chogall_corruption_normal::HandleScriptEffect, EFFECT_1, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

class spell_chogall_corruption_normal_alternative : public SpellScript
{
    PrepareSpellScript(spell_chogall_corruption_normal_alternative);

    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        CorruptionHandler::AddCorruption(GetHitUnit(), CORRUPTION_NORMAL);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_chogall_corruption_normal_alternative::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

class spell_chogall_corruption_of_the_old_god : public SpellScript
{
    PrepareSpellScript(spell_chogall_corruption_of_the_old_god);

    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        CorruptionHandler::AddCorruption(GetHitUnit(), CORRUPTION_NORMAL);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_chogall_corruption_of_the_old_god::HandleScriptEffect, EFFECT_1, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

class spell_chogall_corruption_sickness : public AuraScript
{
    PrepareAuraScript(spell_chogall_corruption_sickness);

    void AfterApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (Player* player = GetTarget()->ToPlayer())
            player->Whisper(ANNOUNCE_CORRUPTION_SICKNESS, player, true);
    }

    void Register() override
    {
        AfterEffectApply += AuraEffectApplyFn(spell_chogall_corruption_sickness::AfterApply, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
    }
};

class spell_chogall_corruption_malformation : public AuraScript
{
    PrepareAuraScript(spell_chogall_corruption_malformation);

    void AfterApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();
        if (InstanceScript* instance = target->GetInstanceScript())
            if (Creature* chogall = instance->GetCreature(DATA_CHOGALL))
                if (Creature* malformation = chogall->SummonCreature(NPC_MALFORMATION, target->GetPosition()))
                    malformation->EnterVehicle(target);
    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (Vehicle* vehicle = GetTarget()->GetVehicleKit())
            if (Unit* passenger = vehicle->GetPassenger(SEAT_0))
                if (Creature* creature = passenger->ToCreature())
                    creature->DespawnOrUnsummon();
    }

    void Register() override
    {
        AfterEffectApply += AuraEffectApplyFn(spell_chogall_corruption_malformation::AfterApply, EFFECT_0, SPELL_AURA_SET_VEHICLE_ID, AURA_EFFECT_HANDLE_REAL);
        OnEffectRemove += AuraEffectRemoveFn(spell_chogall_corruption_malformation::OnRemove, EFFECT_0, SPELL_AURA_SET_VEHICLE_ID, AURA_EFFECT_HANDLE_REAL);
    }
};

class VehicleCheck
{
    public:
        VehicleCheck(Unit* _passenger) : passenger(_passenger)  { }

        bool operator()(WorldObject* object)
        {
            return (passenger->GetVehicleBase() && passenger->GetVehicleBase() == object->ToUnit());
        }
    private:
        Unit* passenger;
};

class spell_chogall_shadow_bolt : public SpellScript
{
    PrepareSpellScript(spell_chogall_shadow_bolt);

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
            return;

        targets.remove_if(VehicleCheck(GetCaster()));

        Trinity::Containers::RandomResize(targets, 1);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_chogall_shadow_bolt::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
    }
};

class spell_chogall_debilitating_beam : public AuraScript
{
    PrepareAuraScript(spell_chogall_debilitating_beam);

    void HandlePeriodic(AuraEffect const* /*aurEff*/)
    {
        CorruptionHandler::AddCorruption(GetTarget(), CORRUPTION_NORMAL);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_chogall_debilitating_beam::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE);
    }
};

class achievement_the_abyss_will_gaze_into_you : public AchievementCriteriaScript
{
    public:
        achievement_the_abyss_will_gaze_into_you() : AchievementCriteriaScript("achievement_the_abyss_will_gaze_into_you") { }

        bool OnCheck(Player* /*source*/, Unit* target) override
        {
            if (!target)
                return false;

            if (target->IsAIEnabled)
                return target->GetAI()->GetData(DATA_ABYSS_WILL_GAZE_INTO_YOU);

            return false;
        }
};

void AddSC_boss_chogall()
{
    RegisterBastionOfTwilightCreatureAI(boss_chogall);
    RegisterBastionOfTwilightCreatureAI(npc_chogall_corrupting_adherent);
    RegisterBastionOfTwilightCreatureAI(npc_chogall_blood_of_the_old_god);
    RegisterBastionOfTwilightCreatureAI(npc_chogall_portal);
    RegisterBastionOfTwilightCreatureAI(npc_chogall_elemental);
    RegisterBastionOfTwilightCreatureAI(npc_chogall_malformation);
    RegisterBastionOfTwilightCreatureAI(npc_chogall_darkened_creation);
    RegisterBastionOfTwilightCreatureAI(npc_chogall_spiked_tentacle);
    RegisterSpellScript(spell_chogall_absorb_elemental_reverse_cast);
    RegisterSpellScript(spell_chogall_absorb_elemental);
    RegisterSpellAndAuraScriptPair(spell_chogall_absorb_elemental_heroic, spell_chogall_absorb_elemental_heroic_AuraScript);
    RegisterAuraScript(spell_chogall_elemental_power);
    RegisterAuraScript(spell_chogall_flaming_destruction_heroic);
    RegisterAuraScript(spell_chogall_empowered_shadows_heroic);
    RegisterSpellScript(spell_chogall_summon_corrupted_adherent);
    RegisterSpellScript(spell_chogall_fester_blood);
    RegisterSpellScript(spell_chogall_fester_blood_summon);
    RegisterSpellScript(spell_chogall_conversion);
    RegisterAuraScript(spell_chogall_worshipping);
    RegisterAuraScript(spell_chogall_consume_blood_of_the_old_god);
    RegisterSpellScript(spell_chogall_consume_blood_of_the_old_god_triggered);
    RegisterSpellScript(spell_chogall_corruption_significant);
    RegisterSpellScript(spell_chogall_corruption_normal);
    RegisterSpellScript(spell_chogall_corruption_normal_alternative);
    RegisterSpellScript(spell_chogall_corruption_of_the_old_god);
    RegisterAuraScript(spell_chogall_corruption_sickness);
    RegisterAuraScript(spell_chogall_corruption_malformation);
    RegisterSpellScript(spell_chogall_shadow_bolt);
    RegisterAuraScript(spell_chogall_debilitating_beam);
    new achievement_the_abyss_will_gaze_into_you();
}
