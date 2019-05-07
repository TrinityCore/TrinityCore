/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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

#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "Player.h"
#include "Vehicle.h"
#include "blackwing_descent.h"

enum Spells
{
    // Magmaw
    SPELL_RIDE_VEHICLE                          = 77901,
    SPELL_BIRTH                                 = 26586,
    SPELL_MAGMA_SPIT_TARGETING                  = 95280,
    SPELL_MAGMA_SPIT_MISSILE                    = 78359,
    SPELL_LAVA_SPEW                             = 77839,
    SPELL_MAGMA_SPIT_MOLTEN_TANTRUM             = 78068,
    SPELL_MANGLE_1                              = 89773,
    SPELL_MANGLE_2                              = 78412,
    SPELL_MANGLE_TARGETING                      = 92047,
    SPELL_SWELTERING_ARMOR                      = 78199,
    SPELL_PILLAR_OF_FLAME                       = 77998,
    SPELL_PILLAR_OF_FLAME_MISSILE_PERIODIC      = 78006,
    SPELL_PILLAR_OF_FLAME_SET_VEHICLE_ID        = 77994,
    SPELL_MASSIVE_CRASH                         = 88253,
    SPELL_IMPALE_SELF                           = 77907,
    SPELL_EJECT_PASSENGER_3                     = 95204,

    // Exposed Head of Magmaw
    SPELL_POINT_OF_VULNERABILITY_SHARE_DAMAGE   = 79010,
    SPELL_POINT_OF_VULNERABILITY                = 79011,
    SPELL_RIDE_VEHICLE_EXPOSED_HEAD             = 89743,
    SPELL_QUEST_INVIS_5                         = 95478,
    SPELL_RIDE_VEHICLE_HEAD                     = 94996,

    // Pillar of Flame
    SPELL_PILLAR_OF_FLAME_DUMMY                 = 78017,
    SPELL_PILLAR_OF_FLAME_PERIODIC              = 77970,

    // Magmaw's Pincer
    SPELL_LAUNCH_HOOK_1                         = 77917,
    SPELL_LAUNCH_HOOK_2                         = 77941,
    SPELL_EJECT_PASSENGER_1                     = 77946,

    // Magmaw Spike Stalker
    SPELL_CHAIN_VISUAL_1                        = 77940,
    SPELL_CHAIN_VISUAL_2                        = 77929,

    // Lava Parasite
    SPELL_LAVA_PARASITE_PROC_AURA               = 78019,
    SPELL_LAVA_PARASITE_RIDE_VEHICLE            = 78020,
    SPELL_PARASITIC_INFECTION_VOMIT             = 78097,
    SPELL_PARASITIC_INFECTION_DAMAGE            = 78941,

    // Nefarian
    SPELL_BLAZING_INFERNO_TARGETING             = 94317,
    SPELL_BLAZING_INFERNO                       = 92153,
    SPELL_SHADOW_BREATH_TARGETING               = 95536,
    SPELL_SHADOW_BREATH                         = 92173,

    // Blazing Bone Contruct
    SPELL_IGNITION                              = 92119,
    SPELL_FIERY_SLASH                           = 92144,
    SPELL_ARMAGEDDON                            = 92177
};

enum Events
{
    // Magmaw
    EVENT_MAGMA_PROJECTILE = 1,
    EVENT_LAVA_SPEW,
    EVENT_MANGLE,
    EVENT_PREPARE_MASSIVE_CRASH,
    EVENT_MASSIVE_CRASH,
    EVENT_ANNOUNCE_PINCERS_EXPOSED,
    EVENT_FINISH_MASSIVE_CRASH,
    EVENT_IMPALE_SELF,
    EVENT_EJECT_PASSENGER_1,
    EVENT_EXPOSE_HEAD,
    EVENT_HIDE_HEAD,
    EVENT_FINISH_IMPALE_SELF,

    // Nefarian
    EVENT_TALK_HEROIC_INTRO_1,
    EVENT_TALK_HEROIC_INTRO_2,
    EVENT_BLAZING_INFERNO,
    EVENT_SHADOW_BREATH,
    EVENT_TALK_MAGMAW_DEAD,

    // Lava Parasite
    EVENT_PREPARE_PARASITE,
    EVENT_ENGAGE_PLAYERS,

    // Blazing Bone Construct
    EVENT_FIERY_SLASH
};

enum Actions
{
    // Magmaw
    ACTION_IMPALE_MAGMAW            = 0,
    ACTION_FAIL_ACHIEVEMT           = 1,

    // Nefarian
    ACTION_SCHEDULE_SHADOW_BREATH   = 0,
    ACTION_MAGMAW_DEAD              = 1
};

enum Texts
{
    // Magmaw
    SAY_ANNOUNCE_LAVA_PARASITES = 0,
    SAY_ANNOUNCE_EXPOSE_PINCERS = 1,
    SAY_ANNOUNCE_EXPOSED_HEAD   = 2,

    // Nefarian
    SAY_INTRO_1                 = 0,
    SAY_INTRO_2                 = 1,
    SAY_MAGMAW_LOW_HEALTH       = 2,
    SAY_MAGMAW_DEAD             = 3
};

enum VehicleSeats
{
    // Magmaw
    SEAT_MAGMAWS_PINCER_1           = 0,
    SEAT_MAGMAWS_PINCER_2           = 1,
    SEAT_MANGLE                     = 2,
    SEAT_EXPOSED_HEAD_OF_MAGMAW_1   = 3,
    SEAT_EXPOSED_HEAD_OF_MAGMAW_2   = 4,

    // Magmaw's Pincer
    SEAT_PINCER                     = 0
};

enum Data
{
    DATA_FREE_PINCER        = 0,
    DATA_ACHIEVEMENT_STATE  = 1
};

enum MovePoints
{
    POINT_NONE = 0
};

enum SplineChains
{
    SPLINE_CHAIN_NEFARIAN_INTRO = 1
};

Position const ExposedHeadOfMagmawPos   = { -299.0f,    -28.9861f,  191.0293f, 4.118977f };
Position const MagmawVehicleExitPos     = { -311.4653f, -48.59722f, 212.8065f, 1.064651f };
Position const NefarianIntroSummonPos   = { -390.1042f, 40.88411f,  207.8586f, 0.196609f };

#define SPELL_PARASITIC_INFECTION_PERIODIC_DAMAGE RAID_MODE<uint32>(78941, 91913, 94678, 94679)

struct boss_magmaw : public BossAI
{
    boss_magmaw(Creature* creature) : BossAI(creature, DATA_MAGMAW)
    {
        Initialize();
    }

    void Initialize()
    {
        _magmaProjectileCount = 0;
        _exposedHead1 = nullptr;
        _exposedHead2 = nullptr;
        _pincer1 = nullptr;
        _pincer2 = nullptr;
        _hasExposedHead = false;
        _headEngaged = false;
        _achievementEnligible = true;
        _heroicPhaseTwoActive = !IsHeroic();
        me->SetReactState(REACT_PASSIVE);
    }

    void Reset() override
    {
        _Reset();
        Initialize();
    }

    void JustAppeared() override
    {
        SetupBody();
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _JustEngagedWith();
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
        me->SetReactState(REACT_AGGRESSIVE);
        events.ScheduleEvent(EVENT_MAGMA_PROJECTILE, 6s);
        events.ScheduleEvent(EVENT_LAVA_SPEW, 19s);
        events.ScheduleEvent(EVENT_MANGLE, 1min + 30s);
        events.ScheduleEvent(EVENT_PREPARE_MASSIVE_CRASH, 1min + 35s);

        _exposedHead1->SetInCombatWithZone();
        _exposedHead2->SetInCombatWithZone();

        if (IsHeroic())
            DoSummon(NPC_NEFARIAN_MAGMAW, NefarianIntroSummonPos, 0, TEMPSUMMON_MANUAL_DESPAWN);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        _EnterEvadeMode();
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        if (_headEngaged)
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, _exposedHead1);

        DoCastSelf(SPELL_EJECT_PASSENGER_3, true);
        _pincer1->CastSpell(_pincer1, SPELL_EJECT_PASSENGER_1, true);
        _pincer2->CastSpell(_pincer2, SPELL_EJECT_PASSENGER_1, true);

        instance->SetBossState(DATA_MAGMAW, FAIL);
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_PARASITIC_INFECTION_VOMIT);
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_PARASITIC_INFECTION_PERIODIC_DAMAGE);
        _exposedHead1->DespawnOrUnsummon();
        summons.DespawnAll();

        if (Creature* nefarian = instance->GetCreature(DATA_NEFARIAN_MAGMAW))
            nefarian->DespawnOrUnsummon();
        _DespawnAtEvade();
    }

    void JustDied(Unit* /*killer*/) override
    {
        if (_headEngaged)
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, _exposedHead1);

        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_PARASITIC_INFECTION_VOMIT);
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_PARASITIC_INFECTION_PERIODIC_DAMAGE);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);

        if (Creature* nefarian = instance->GetCreature(DATA_NEFARIAN_MAGMAW))
            nefarian->AI()->DoAction(ACTION_MAGMAW_DEAD);

        me->StopMoving(); // Tempfix to prevent Magmaw from falling into the lava
        _JustDied();
    }

    void JustSummoned(Creature* summon) override
    {
        switch (summon->GetEntry())
        {
            case NPC_PILLAR_OF_FLAME:
                summon->CastSpell(summon, SPELL_PILLAR_OF_FLAME_DUMMY);
                summon->SetDisplayId(summon->GetCreatureTemplate()->Modelid1);
                summon->DespawnOrUnsummon(7s);
                Talk(SAY_ANNOUNCE_LAVA_PARASITES);
                summons.Summon(summon);
                break;
            case NPC_NEFARIAN_MAGMAW:
            case NPC_EXPOSED_HEAD_OF_MAGMAW:
                break;
            default:
                summons.Summon(summon);
                break;
        }
    }

    void SpellHit(Unit* caster, SpellInfo const* spell) override
    {
        switch (spell->Id)
        {
            case SPELL_MASSIVE_CRASH:
            {
                me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_SPELLCLICK);
                me->SetFlag(UNIT_FIELD_FLAGS_2, UNIT_FLAG2_ALLOW_ENEMY_INTERACT);
                _exposedHead1->CastSpell(_exposedHead1, SPELL_RIDE_VEHICLE_HEAD, true);
                events.ScheduleEvent(EVENT_ANNOUNCE_PINCERS_EXPOSED, 1s);
                events.ScheduleEvent(EVENT_FINISH_MASSIVE_CRASH, 7s);
                Unit* head = _exposedHead1;
                head->m_Events.AddEventAtOffset([head]()
                {
                    head->CastSpell(head, SPELL_RIDE_VEHICLE_EXPOSED_HEAD, true);
                }, 6s);

                break;
            }
            case SPELL_IMPALE_SELF:
                DoCastSelf(SPELL_EJECT_PASSENGER_3, true);
                Talk(SAY_ANNOUNCE_EXPOSED_HEAD);
                me->RemoveAurasDueToSpell(SPELL_CHAIN_VISUAL_1);
                me->RemoveAurasDueToSpell(SPELL_CHAIN_VISUAL_2);
                events.ScheduleEvent(EVENT_HIDE_HEAD, 29s);
                events.ScheduleEvent(EVENT_FINISH_IMPALE_SELF, 33s);
                break;
            default:
                break;
        }
    }

    uint32 GetData(uint32 type) const override
    {
        if (type == DATA_ACHIEVEMENT_STATE)
            return _achievementEnligible;

        return 0;
    }

    ObjectGuid GetGUID(int32 type) const override
    {
        switch (type)
        {
            case DATA_FREE_PINCER:
                if (_pincer1->GetVehicleKit() && _pincer1->GetVehicleKit()->GetAvailableSeatCount())
                    return _pincer1->GetGUID();
                else if (_pincer2->GetVehicleKit() && _pincer2->GetVehicleKit()->GetAvailableSeatCount())
                    return _pincer2->GetGUID();
            default:
                return ObjectGuid::Empty;
        }

        return ObjectGuid::Empty;
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage) override
    {
        if (me->HealthBelowPctDamaged(30, damage) && !_heroicPhaseTwoActive)
        {
            if (Creature* nefarian = instance->GetCreature(DATA_NEFARIAN_MAGMAW))
                nefarian->AI()->DoAction(ACTION_SCHEDULE_SHADOW_BREATH);
            _heroicPhaseTwoActive = true;
        }

        if (damage >= me->GetHealth())
        {
            // Make sure we eject all passengers nicely before we die so they wont end up in the lava
            DoCastSelf(SPELL_EJECT_PASSENGER_3, true);
            _pincer1->CastSpell(_pincer1, SPELL_EJECT_PASSENGER_1, true);
            _pincer2->CastSpell(_pincer2, SPELL_EJECT_PASSENGER_1, true);
        }
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_IMPALE_MAGMAW:
                events.CancelEvent(EVENT_MAGMA_PROJECTILE);
                events.CancelEvent(EVENT_LAVA_SPEW);
                events.CancelEvent(EVENT_MASSIVE_CRASH);
                me->AttackStop();
                me->SetReactState(REACT_PASSIVE);
                me->CastStop();
                me->RemoveAurasDueToSpell(SPELL_MASSIVE_CRASH);
                me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_SPELLCLICK);
                me->RemoveFlag(UNIT_FIELD_FLAGS_2, UNIT_FLAG2_ALLOW_ENEMY_INTERACT);
                me->RemoveAurasDueToSpell(SPELL_PILLAR_OF_FLAME_MISSILE_PERIODIC);

                if (Creature* spikeStalker = me->FindNearestCreature(NPC_MAGMAW_SPIKE_STALKER, 60.0f))
                    me->SetFacingToObject(spikeStalker);

                events.ScheduleEvent(EVENT_IMPALE_SELF, 1s);
                events.ScheduleEvent(EVENT_EJECT_PASSENGER_1, 2s + 300ms);
                events.ScheduleEvent(EVENT_EXPOSE_HEAD, 4s + 700ms);
                _hasExposedHead = true;
                break;
            case ACTION_FAIL_ACHIEVEMT:
                _achievementEnligible = false;
                break;
            default:
                break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING) && !_hasExposedHead)
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_MAGMA_PROJECTILE:
                    if (_magmaProjectileCount < 4)
                    {
                        DoCastAOE(SPELL_MAGMA_SPIT_TARGETING);
                        _magmaProjectileCount++;
                        events.Repeat(6s);
                    }
                    else
                    {
                        DoCastAOE(SPELL_PILLAR_OF_FLAME);
                        DoCastAOE(SPELL_PILLAR_OF_FLAME_SET_VEHICLE_ID);
                        _magmaProjectileCount = 0;
                        events.Repeat(8s);
                    }
                    break;
                case EVENT_LAVA_SPEW:
                    DoCastAOE(SPELL_LAVA_SPEW);
                    events.Repeat(27s, 28s);
                    break;
                case EVENT_MANGLE:
                    if (SelectTarget(SELECT_TARGET_RANDOM, 0, NonTankTargetSelector(me)))
                        DoCastAOE(SPELL_MANGLE_TARGETING);
                    events.Repeat(1min + 35s);
                    break;
                case EVENT_PREPARE_MASSIVE_CRASH:
                    if (ObjectGuid guid = instance->GetGuidData(DATA_PREPARE_MASSIVE_CRASH_AND_GET_TARGET_GUID))
                    {
                        if (Creature* stalker = ObjectAccessor::GetCreature(*me, guid))
                        {
                            me->AttackStop();
                            me->SetReactState(REACT_PASSIVE);
                            me->SetFacingToObject(stalker, true);
                            events.ScheduleEvent(EVENT_MASSIVE_CRASH, 5s);
                            events.CancelEvent(EVENT_MAGMA_PROJECTILE);
                            events.CancelEvent(EVENT_LAVA_SPEW);
                            events.Repeat(1min + 35s);
                        }
                    }
                    break;
                case EVENT_MASSIVE_CRASH:
                    DoCast(SPELL_MASSIVE_CRASH);
                    _pincer1->CastSpell(_pincer1, SPELL_EJECT_PASSENGER_1, true);
                    _pincer2->CastSpell(_pincer2, SPELL_EJECT_PASSENGER_1, true);
                    break;
                case EVENT_ANNOUNCE_PINCERS_EXPOSED:
                    Talk(SAY_ANNOUNCE_EXPOSE_PINCERS);
                    break;
                case EVENT_FINISH_MASSIVE_CRASH:
                    me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_SPELLCLICK);
                    me->RemoveFlag(UNIT_FIELD_FLAGS_2, UNIT_FLAG2_ALLOW_ENEMY_INTERACT);
                    me->SetReactState(REACT_AGGRESSIVE);
                    events.ScheduleEvent(EVENT_LAVA_SPEW, 1ms);
                    events.ScheduleEvent(EVENT_MAGMA_PROJECTILE, 8s);
                    break;
                case EVENT_IMPALE_SELF:
                    DoCastSelf(SPELL_IMPALE_SELF);
                    break;
                case EVENT_EJECT_PASSENGER_1:
                    _pincer1->CastSpell(_pincer1, SPELL_EJECT_PASSENGER_1, true);
                    _pincer2->CastSpell(_pincer2, SPELL_EJECT_PASSENGER_1, true);
                    break;
                case EVENT_EXPOSE_HEAD:
                    if (!_headEngaged)
                    {
                        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, _exposedHead1, 2);
                        instance->SendEncounterUnit(ENCOUNTER_FRAME_UPDATE_PRIORITY, me);
                        _headEngaged = true;
                    }
                    _exposedHead1->CastSpell(_exposedHead1, SPELL_RIDE_VEHICLE_HEAD, true);
                    _exposedHead1->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                    break;
                case EVENT_HIDE_HEAD:
                    _exposedHead1->CastSpell(_exposedHead1, SPELL_RIDE_VEHICLE_EXPOSED_HEAD, true);
                    _exposedHead1->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                    break;
                case EVENT_FINISH_IMPALE_SELF:
                    _hasExposedHead = false;
                    me->SetReactState(REACT_AGGRESSIVE);
                    events.ScheduleEvent(EVENT_LAVA_SPEW, 1ms);
                    events.ScheduleEvent(EVENT_MAGMA_PROJECTILE, 4s);
                    events.ScheduleEvent(EVENT_MASSIVE_CRASH, 40s);
                    break;
                default:
                    break;
            }
        }

        if (Unit* victim = me->GetVictim())
        {
            if (me->IsWithinMeleeRange(victim))
                DoMeleeAttackIfReady();
            else
                DoSpellAttackIfReady(SPELL_MAGMA_SPIT_MOLTEN_TANTRUM);
        }
    }

private:
    void SetupBody()
    {
        if (_pincer1 = DoSummon(NPC_MAGMAWS_PINCER_1, me->GetPosition()))
        {
            _pincer1->EnterVehicle(me, SEAT_MAGMAWS_PINCER_1);
            _pincer1->SetDisplayId(_pincer1->GetCreatureTemplate()->Modelid3);
        }

        if (_pincer2 = DoSummon(NPC_MAGMAWS_PINCER_2, me->GetPosition()))
        {
            _pincer2->EnterVehicle(me, SEAT_MAGMAWS_PINCER_2);
            _pincer2->SetDisplayId(_pincer2->GetCreatureTemplate()->Modelid3);
        }

        _exposedHead1 = DoSummon(NPC_EXPOSED_HEAD_OF_MAGMAW, ExposedHeadOfMagmawPos);
        _exposedHead2 = DoSummon(NPC_EXPOSED_HEAD_OF_MAGMAW_2, me->GetPosition());

        if (!_exposedHead1 || !_exposedHead2)
            return;

        _exposedHead1->SetReactState(REACT_PASSIVE);
        _exposedHead2->SetReactState(REACT_PASSIVE);

        _exposedHead2->EnterVehicle(me, SEAT_EXPOSED_HEAD_OF_MAGMAW_2);
        DoCastSelf(SPELL_BIRTH);

        // First we link the real exposed head
        _exposedHead1->CastSpell(me, SPELL_POINT_OF_VULNERABILITY_SHARE_DAMAGE);
        _exposedHead1->CastSpell(_exposedHead1, SPELL_POINT_OF_VULNERABILITY);
        _exposedHead1->CastSpell(_exposedHead2, SPELL_POINT_OF_VULNERABILITY_SHARE_DAMAGE);
        // ... now the dummy exposed head
        _exposedHead2->CastSpell(me, SPELL_POINT_OF_VULNERABILITY_SHARE_DAMAGE);
        _exposedHead2->CastSpell(_exposedHead2, SPELL_POINT_OF_VULNERABILITY);
        // ... and now Magmaw
        DoCast(_exposedHead2, SPELL_POINT_OF_VULNERABILITY_SHARE_DAMAGE);
        DoCast(_exposedHead1, SPELL_POINT_OF_VULNERABILITY_SHARE_DAMAGE);

        _exposedHead2->CastSpell(_exposedHead2, SPELL_QUEST_INVIS_5);

        ObjectGuid guid = me->GetGUID();
        Unit* head = _exposedHead1;
        head->m_Events.AddEventAtOffset([head, guid]()
        {
            if (Unit* target = ObjectAccessor::GetUnit(*head, guid))
                head->CastSpell(target, SPELL_RIDE_VEHICLE_EXPOSED_HEAD, true);
        }, 1s + 200ms);
    }

    Creature* _exposedHead1;
    Creature* _exposedHead2;
    Creature* _pincer1;
    Creature* _pincer2;
    uint8 _magmaProjectileCount;
    bool _achievementEnligible;
    bool _hasExposedHead;
    bool _headEngaged;
    bool _heroicPhaseTwoActive;
};

struct npc_magmaw_nefarian : public ScriptedAI
{
    npc_magmaw_nefarian(Creature* creature) : ScriptedAI(creature), _instance(me->GetInstanceScript())
    {
        Initialize();
    }

    void Initialize()
    {
        me->SetReactState(REACT_PASSIVE);
    }

    void IsSummonedBy(Unit* /*summoner*/) override
    {
        me->GetMotionMaster()->MoveAlongSplineChain(POINT_NONE, SPLINE_CHAIN_NEFARIAN_INTRO, false);
        _events.ScheduleEvent(EVENT_TALK_HEROIC_INTRO_1, 11s);
        _events.ScheduleEvent(EVENT_BLAZING_INFERNO, 27s);
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_SCHEDULE_SHADOW_BREATH:
                Talk(SAY_MAGMAW_LOW_HEALTH);
                _events.ScheduleEvent(EVENT_SHADOW_BREATH, 9s);
                break;
            case ACTION_MAGMAW_DEAD:
                _events.Reset();
                _events.ScheduleEvent(EVENT_TALK_MAGMAW_DEAD, 2s + 400ms);
                me->DespawnOrUnsummon(6s);
                break;
            default:
                break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_TALK_HEROIC_INTRO_1:
                    Talk(SAY_INTRO_1);
                    _events.ScheduleEvent(EVENT_TALK_HEROIC_INTRO_2, 16s);
                    break;
                case EVENT_TALK_HEROIC_INTRO_2:
                    Talk(SAY_INTRO_2);
                    break;
                case EVENT_BLAZING_INFERNO:
                    DoCastAOE(SPELL_BLAZING_INFERNO_TARGETING, true);
                    _events.Repeat(36s);
                    break;
                case EVENT_SHADOW_BREATH:
                    DoCastAOE(SPELL_SHADOW_BREATH_TARGETING);
                    _events.Repeat(1s + 200ms);
                    break;
                case EVENT_TALK_MAGMAW_DEAD:
                    Talk(SAY_MAGMAW_DEAD);
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

struct npc_magmaw_lava_parasite : public ScriptedAI
{
    npc_magmaw_lava_parasite(Creature* creature) : ScriptedAI(creature), _instance(me->GetInstanceScript())
    {
        Initialize();
    }

    void Initialize()
    {
        me->SetReactState(REACT_PASSIVE);
    }

    void IsSummonedBy(Unit* /*summoner*/) override
    {
        // I have no idea why Blizzard is delaying it but they do so we comply here as well
        _events.ScheduleEvent(EVENT_PREPARE_PARASITE, 1s + 700ms);
    }

    void JustDied(Unit* /*killer*/) override
    {
        _events.Reset();
        me->DespawnOrUnsummon(2s + 500ms);
    }

    void SpellHitTarget(Unit* /*target*/, SpellInfo const* spell) override
    {
        if (spell->Id == SPELL_LAVA_PARASITE_RIDE_VEHICLE)
        {
            me->AttackStop();
            me->SetReactState(REACT_PASSIVE);
            me->DespawnOrUnsummon(4s);
            if (Creature* magmaw = _instance->GetCreature(DATA_MAGMAW))
                magmaw->AI()->DoAction(ACTION_FAIL_ACHIEVEMT);
        }
    }

    void UpdateAI(uint32 diff) override
    {
        UpdateVictim();

        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_PREPARE_PARASITE:
                    DoCastSelf(SPELL_LAVA_PARASITE_PROC_AURA);
                    _events.ScheduleEvent(EVENT_ENGAGE_PLAYERS, 2s);
                    break;
                case EVENT_ENGAGE_PLAYERS:
                    me->SetReactState(REACT_AGGRESSIVE);
                    DoZoneInCombat();
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

struct npc_magmaw_blazing_bone_construct : public ScriptedAI
{
    npc_magmaw_blazing_bone_construct(Creature* creature) : ScriptedAI(creature), _instance(me->GetInstanceScript())
    {
        Initialize();
    }

    void Initialize()
    {
        me->SetReactState(REACT_PASSIVE);
        _armageddonTriggered = false;
    }

    void IsSummonedBy(Unit* /*summoner*/) override
    {
        if (_instance->GetBossState(DATA_MAGMAW) == IN_PROGRESS)
        {
            for (uint8 i = 0; i < 20; i++)
            {
                Position const pos = me->GetRandomNearPosition(10.0f);
                me->CastSpell(pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(), SPELL_IGNITION, true);
            }
            _events.ScheduleEvent(EVENT_ENGAGE_PLAYERS, 1s);
        }
        else
            me->DespawnOrUnsummon();
    }

    void JustSummoned(Creature* summon) override
    {
        if (summon->GetEntry() == NPC_IGNITION)
        {
            summon->m_Events.AddEventAtOffset([summon]()
            {
                summon->GetMotionMaster()->MoveCirclePath(summon->GetPositionX(), summon->GetPositionY(), summon->GetPositionZ(), 2.5f, bool(urand(0, 1)), 8);
            }, 4s + 500ms);
        }
    }

    void JustDied(Unit* /*killer*/) override
    {
        _events.Reset();
        me->DespawnOrUnsummon(2s + 500ms);
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage) override
    {
        if (!_armageddonTriggered && me->HealthBelowPctDamaged(20, damage))
        {
            _armageddonTriggered = true;
            DoCastSelf(SPELL_ARMAGEDDON);
        }
    }

    void UpdateAI(uint32 diff) override
    {
        UpdateVictim();

        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_ENGAGE_PLAYERS:
                    me->SetReactState(REACT_AGGRESSIVE);
                    DoZoneInCombat();
                    _events.ScheduleEvent(EVENT_FIERY_SLASH, 2s);
                    break;
                case EVENT_FIERY_SLASH:
                    DoCastVictim(SPELL_FIERY_SLASH);
                    _events.Repeat(2s, 8s);
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
    bool _armageddonTriggered;
};

class IsOnVehicleCheck
{
    public:
        IsOnVehicleCheck() { }

        bool operator()(WorldObject* object)
        {
            return object->ToUnit()->GetVehicle();
        }
};

class spell_magmaw_magma_spit: public SpellScript
{
    PrepareSpellScript(spell_magmaw_magma_spit);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_MAGMA_SPIT_MISSILE });
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
            return;

        targets.remove_if(IsOnVehicleCheck());

        if (targets.empty())
            return;

        Trinity::Containers::RandomResize(targets, GetCaster()->GetMap()->Is25ManRaid() ? 8 : 3);
    }

    void HandleHit(SpellEffIndex /*effIndex*/)
    {
        if (Unit* caster = GetCaster())
            caster->CastSpell(GetHitUnit(), SPELL_MAGMA_SPIT_MISSILE, true);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_magmaw_magma_spit::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        OnEffectHitTarget += SpellEffectFn(spell_magmaw_magma_spit::HandleHit, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

class VictimCheck
{
    public:
        VictimCheck(Unit* attacker) : _attacker(attacker)  { }

        bool operator()(WorldObject* object)
        {
            return (_attacker->GetVictim() && _attacker->GetVictim() != object->ToUnit());
        }
    private:
        Unit* _attacker;
};

class spell_magmaw_mangle : public SpellScript
{
    PrepareSpellScript(spell_magmaw_mangle);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_MANGLE_1,
                SPELL_MANGLE_2,
                SPELL_SWELTERING_ARMOR
            });
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
            return;

        targets.remove_if(VictimCheck(GetCaster()));
    }

    void HandleHit(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        Unit* target = GetHitUnit();
        caster->CastSpell(target, SPELL_MANGLE_1, true);
        target->CastSpell(target, SPELL_MANGLE_2, true);
        target->CastSpell(target, SPELL_SWELTERING_ARMOR, true);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_magmaw_mangle::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        OnEffectHitTarget += SpellEffectFn(spell_magmaw_mangle::HandleHit, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

class spell_magmaw_pillar_of_flame_dummy : public SpellScript
{
    PrepareSpellScript(spell_magmaw_pillar_of_flame_dummy);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_PILLAR_OF_FLAME_MISSILE_PERIODIC,
                SPELL_PILLAR_OF_FLAME_PERIODIC
            });
    }

    void HandleHit(SpellEffIndex /*effIndex*/)
    {
        GetHitUnit()->CastSpell(GetHitUnit(), SPELL_PILLAR_OF_FLAME_MISSILE_PERIODIC);
        if (Unit* caster = GetCaster())
            caster->m_Events.AddEventAtOffset([caster]()
            {
                caster->CastSpell(caster, SPELL_PILLAR_OF_FLAME_PERIODIC);
            }, 2s);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_magmaw_pillar_of_flame_dummy::HandleHit, EFFECT_1, SPELL_EFFECT_DUMMY);
    }
};

class DistanceCheck
{
    public:
        DistanceCheck(Unit* caster) : _caster(caster)  { }

        bool operator()(WorldObject* object)
        {
            return (object->GetExactDist2d(_caster) >= 15.0f);
        }
    private:
        Unit* _caster;
};

class spell_magmaw_pillar_of_flame_forcecast : public SpellScript
{
    PrepareSpellScript(spell_magmaw_pillar_of_flame_forcecast);

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
            return;

        targets.remove_if(IsOnVehicleCheck());

        if (targets.empty())
            return;

        // Hotfix (2010-12-21): Magmaw's Pillar of Flame now prefers targets further than 15 yards away
        std::list<WorldObject*> targetsCopy = targets;
        targetsCopy.remove_if(DistanceCheck(GetCaster()));
        if (!targetsCopy.empty())
            targets = targetsCopy;

        Trinity::Containers::RandomResize(targets, 1);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_magmaw_pillar_of_flame_forcecast::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
    }
};

class spell_magmaw_ride_vehicle : public SpellScript
{
    PrepareSpellScript(spell_magmaw_ride_vehicle);

    void SetTarget(WorldObject*& target)
    {
        if (InstanceScript* instance = GetCaster()->GetInstanceScript())
        {
            if (Creature* magmaw = instance->GetCreature(DATA_MAGMAW))
            {
                if (Creature* pincer = ObjectAccessor::GetCreature(*GetCaster(), magmaw->AI()->GetGUID(DATA_FREE_PINCER)))
                    target = pincer;
                else
                    target = nullptr;
            }
        }
    }

    void Register() override
    {
        OnObjectTargetSelect += SpellObjectTargetSelectFn(spell_magmaw_ride_vehicle::SetTarget, EFFECT_0, TARGET_UNIT_TARGET_ANY);
    }
};

class spell_magmaw_launch_hook : public AuraScript
{
    PrepareAuraScript(spell_magmaw_launch_hook);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_LAUNCH_HOOK_1,
                SPELL_LAUNCH_HOOK_2,
                SPELL_CHAIN_VISUAL_1,
                SPELL_CHAIN_VISUAL_2
            });
    }

    void AfterApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();

        if (target->HasAura(SPELL_LAUNCH_HOOK_1) && target->HasAura(SPELL_LAUNCH_HOOK_2))
        {
            if (InstanceScript* instance = target->GetInstanceScript())
                if (Creature* magmaw = instance->GetCreature(DATA_MAGMAW))
                    magmaw->AI()->DoAction(ACTION_IMPALE_MAGMAW);

            target->RemoveAllAuras();
            target->CastSpell(target, SPELL_CHAIN_VISUAL_1);
            target->CastSpell(target, SPELL_CHAIN_VISUAL_2);
        }
    }

    void Register() override
    {
        AfterEffectApply += AuraEffectApplyFn(spell_magmaw_launch_hook::AfterApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

class spell_magmaw_eject_passenger_1 : public SpellScript
{
    PrepareSpellScript(spell_magmaw_eject_passenger_1);

    void EjectPassenger(SpellEffIndex /*effIndex*/)
    {
        if (Vehicle* vehicle = GetHitUnit()->GetVehicleKit())
        {
            if (Unit* passenger = vehicle->GetPassenger(SEAT_PINCER))
                passenger->_ExitVehicle(&MagmawVehicleExitPos);
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_magmaw_eject_passenger_1::EjectPassenger, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

class spell_magmaw_eject_passenger_3 : public SpellScript
{
    PrepareSpellScript(spell_magmaw_eject_passenger_3);

    void EjectPassenger(SpellEffIndex /*effIndex*/)
    {
        if (Vehicle* vehicle = GetHitUnit()->GetVehicleKit())
        {
            if (Unit* passenger = vehicle->GetPassenger(SEAT_MANGLE))
                passenger->_ExitVehicle(&MagmawVehicleExitPos);
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_magmaw_eject_passenger_3::EjectPassenger, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

class spell_magmaw_lava_parasite : public AuraScript
{
    PrepareAuraScript(spell_magmaw_lava_parasite);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_PARASITIC_INFECTION_DAMAGE,
                SPELL_PARASITIC_INFECTION_VOMIT,
            });
    }

    void HandleProc(AuraEffect const* /*aurEff*/, ProcEventInfo& eventInfo)
    {
        // Hotfix (2010-12-21): Lava Parasites are functioning normally and cannot infest a player with more than 3 Parasite debuffs active
        PreventDefaultAction();

        Unit* caster = GetTarget();
        Unit* target = eventInfo.GetProcTarget();
        if (Vehicle* vehicle = target->GetVehicleKit())
        {
            if (vehicle->GetAvailableSeatCount())
            {
                caster->CastSpell(target, GetSpellInfo()->Effects[EFFECT_0].TriggerSpell, true);
                caster->CastSpell(target, SPELL_PARASITIC_INFECTION_DAMAGE, true);
                caster->CastSpell(target, SPELL_PARASITIC_INFECTION_VOMIT, true);
            }
        }
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_magmaw_lava_parasite::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

class spell_magmaw_blazing_inferno_targeting : public SpellScript
{
    PrepareSpellScript(spell_magmaw_blazing_inferno_targeting);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_BLAZING_INFERNO });
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
            return;

        targets.remove_if(IsOnVehicleCheck());

        if (targets.empty())
            return;

        // Hotfix (2010-03-16): In addition, on Heroic difficulty, Nefarian will now prefer ranged targets when spawning Blazing Bone Constructs.
        InstanceScript* instance = GetCaster()->GetInstanceScript();
        if (!instance)
            return;

        Creature* magmaw = instance->GetCreature(DATA_MAGMAW);
        if (!magmaw)
            return;

        std::list<WorldObject*> targetsCopy = targets;
        targetsCopy.remove_if(DistanceCheck(magmaw));
        if (!targetsCopy.empty())
            targets = targetsCopy;

        Trinity::Containers::RandomResize(targets, 1);
    }

    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        if (Unit* caster = GetCaster())
            caster->CastSpell(GetHitUnit(), SPELL_BLAZING_INFERNO);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_magmaw_blazing_inferno_targeting::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        OnEffectHitTarget += SpellEffectFn(spell_magmaw_blazing_inferno_targeting::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

class spell_magmaw_shadow_breath_targeting : public SpellScript
{
    PrepareSpellScript(spell_magmaw_shadow_breath_targeting);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SHADOW_BREATH });
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
            return;

        targets.remove_if(IsOnVehicleCheck());

        if (targets.empty() || targets.size() < 2)
            return;

        Trinity::Containers::RandomResize(targets, 2);
    }

    void HandleDummyEffect(SpellEffIndex /*effIndex*/)
    {
        if (Unit* caster = GetCaster())
            caster->CastSpell(GetHitUnit(), SPELL_SHADOW_BREATH, true);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_magmaw_shadow_breath_targeting::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        OnEffectHitTarget += SpellEffectFn(spell_magmaw_shadow_breath_targeting::HandleDummyEffect, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

class achievement_parasite_evening : public AchievementCriteriaScript
{
    public:
        achievement_parasite_evening() : AchievementCriteriaScript("achievement_parasite_evening") { }

        bool OnCheck(Player* source, Unit* target) override
        {
            if (!target)
                return false;

            if (target->IsAIEnabled)
                return target->GetAI()->GetData(DATA_ACHIEVEMENT_STATE);

            return false;
        }
};

void AddSC_boss_magmaw()
{
    RegisterBlackwingDescentCreatureAI(boss_magmaw);
    RegisterBlackwingDescentCreatureAI(npc_magmaw_nefarian);
    RegisterBlackwingDescentCreatureAI(npc_magmaw_lava_parasite);
    RegisterBlackwingDescentCreatureAI(npc_magmaw_blazing_bone_construct);
    RegisterSpellScript(spell_magmaw_magma_spit);
    RegisterSpellScript(spell_magmaw_mangle);
    RegisterSpellScript(spell_magmaw_pillar_of_flame_dummy);
    RegisterSpellScript(spell_magmaw_pillar_of_flame_forcecast);
    RegisterSpellScript(spell_magmaw_ride_vehicle);
    RegisterAuraScript(spell_magmaw_launch_hook);
    RegisterSpellScript(spell_magmaw_eject_passenger_1);
    RegisterSpellScript(spell_magmaw_eject_passenger_3);
    RegisterAuraScript(spell_magmaw_lava_parasite);
    RegisterSpellScript(spell_magmaw_blazing_inferno_targeting);
    RegisterSpellScript(spell_magmaw_shadow_breath_targeting);
    new achievement_parasite_evening();
}
