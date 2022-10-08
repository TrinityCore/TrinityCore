/*
 * Copyright (C) 2017-2019 AshamaneProject <https://github.com/AshamaneProject>
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

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "AreaTriggerTemplate.h"
#include "AreaTriggerAI.h"
#include "SpellMgr.h"
#include <G3D/Vector3.h>
#include <G3D/Triangle.h>
#include <G3D/Plane.h>
#include <G3D/CollisionDetection.h>
#include "AreaTrigger.h"
#include "karazhan_legion.h"
#include "Cell.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"

enum Spells
{
    // All Phase
    SPELL_DISINTEGRATE                      = 229151,
    SPELL_BURNING_BLAST                     = 229083,
    SPELL_CHAOTIC_SHADOWS                   = 229159,
    SPELL_EXPLOSIVE_SHADOWS_AREA            = 229160,
    SPELL_EXPLOSIVE_SHADOWS_DMG             = 229161,
    SPELL_DEMONIC_PORTAL                    = 229610,
    SPELL_DEMONIC_PORTAL_AREA               = 229591,
    SPELL_DEMONIC_PORTAL_SUMMON             = 229607,
    SPELL_DEMONIC_PORTAL_PLAYER             = 229599,

    // Phase One
    SPELL_COMMAND_BOMBARDMENT               = 229284,
    SPELL_COMMAND_FEL_BEAM                  = 229242,

    SPELL_BOMBARDMENT_CHARGE                = 229283,
    SPELL_BOMBARDMENT_AURA                  = 229287,
    SPELL_BOMBARDMENT_MISSILE               = 229291,

    SPELL_FEL_BEAM_VISUAL                   = 229246,
    SPELL_FEL_BEAM_MARKED                   = 229241,
    SPELL_FEL_BEAM_CHANNELED                = 229244,
    SPELL_FEL_BEAM_DMG                      = 229248,
    SPELL_FEL_FLAMES_AREA                   = 229249,
    SPELL_FEL_FLAMES_DMG                    = 229250,

    SPELL_SOUL_HARVEST                      = 229906,
    SPELL_SOUL_HARVEST_DMG                  = 229905,

    // Phase Two
    SPELL_STABILIZE_RIFT                    = 230084,
    SPELL_STABILIZE_RIFT_SIZE               = 230258,
    SPELL_STABILIZE_RIFT_VISUAL             = 230086
};

enum Events
{
    // All Phases
    EVENT_DISINTEGRATE                      = 1,
    EVENT_CHAOTIC_SHADOWS                   = 2,
    EVENT_BURNING_BLAST                     = 3,
    EVENT_DEMONIC_PORTAL                    = 4,

    // Phase One
    EVENT_FEL_BEAM                          = 5,
    EVENT_BOMBARDMENT                       = 6,
    EVENT_DISINTEGRATE_SHIP                 = 7,
    EVENT_CHECK_PLAYER_NEAR                 = 8,

    // Phase Two
    EVENT_STABILIZE_RIFT                    = 9,
    EVENT_CHECK_PLAYERS                     = 10,
    EVENT_RESTORE_STATE                     = 11,
    EVENT_FELGUARD_SENTRY                   = 12
};

enum Adds
{
    NPC_DEMONIC_PORTAL                      = 115493,
    NPC_INVISIBLE_VEHICLE                   = 115361,
    NPC_SOUL_HARVESTER                      = 115694,
    NPC_STABILIZE_RIFT                      = 115789,
    NPC_FELGUARD_SENTRY                     = 115730
};

enum Points
{
    POINT_DEMONIC_PORTAL                    = 30,
    POINT_FIRST_SHIP                        = 2,
    POINT_SECOND_SHIP                       = 3
};

enum Paths
{
    FIRST_SHIP_PATH                         = 11479010,
    SECOND_SHIP_PATH                        = 11479020
};

enum Actions
{
    ACTION_OPENED_RIFT                      = 1,
    ACTION_CLOSED_RIFT                      = 2
};

enum Data
{
    DATA_SHIP_PATH                          = 1,
    DATA_FELBEAM_TARGET                     = 2
};

const Position FirstPath[] =
{
    { 3731.286f, -2091.646f, 834.0523f },
    { 3782.628f, -2038.703f, 912.1886f },
    { 3964.107f, -2046.733f, 941.9396f },
    { 4003.561f, -2056.113f, 933.3297f },
    { 4001.103f, -2052.984f, 930.3838f },
};

const Position SecondPath[] =
{
    { 3807.376f, -2014.140f, 941.105f },
    { 3702.795f, -1974.346f, 988.726f },
    { 3606.173f, -1924.877f, 1038.816f},
    { 3529.201f, -1906.505f, 1050.536f},
};

using OrbInfo = std::pair<float, uint32>;

const OrbInfo Angles[] =
{
    { 45.f,  8939 },
    { 90.f,  8940 },
    { 135.f, 8941 },
    { 180.f, 8942 },
    { 225.f, 8943 },
    { 270.f, 8944 },
    { 315.f, 8945 },
    { 360.f, 8946 },
};

class boss_new_vizaduum : public CreatureScript
{
    public:
        boss_new_vizaduum() : CreatureScript("boss_new_vizaduum") { }

        struct boss_new_vizaduum_AI : public BossAI
        {
            explicit boss_new_vizaduum_AI(Creature* creature) : BossAI(creature, DATA_VIZADUUM)
            {
                _homePosition = creature->GetPosition();
            }

            void Reset() override
            {
                _isFlying = false;
                _firstPhase = false;
                _secondPhase = false;
                _Reset();
            }

            void EnterCombat(Unit* /**/) override
            {
                me->SetReactState(REACT_AGGRESSIVE);

                _EnterCombat();
                _times = 1;
                instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
                events.ScheduleEvent(EVENT_DISINTEGRATE, 8s);
                events.ScheduleEvent(EVENT_CHAOTIC_SHADOWS, 10s);
                events.ScheduleEvent(EVENT_BURNING_BLAST, 5s);
                events.ScheduleEvent(EVENT_FEL_BEAM, 5s);
                events.ScheduleEvent(EVENT_BOMBARDMENT, 30s);
            }

            void EnterEvadeMode(EvadeReason why) override
            {
                me->SetHomePosition(_homePosition);
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                me->RemoveAllAreaTriggers();
                CreatureAI::EnterEvadeMode(why);
            }

            void JustDied(Unit* /**/) override
            {
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                me->RemoveAllAreaTriggers();
                _JustDied();
            }

            void DesactivateShips()
            {
                ObjectGuid guid = instance->GetGuidData(DATA_FIRST_SHIP);

                if (auto* ptr = ObjectAccessor::GetCreature(*me, guid))
                {
                    ptr->CastStop();
                    ptr->RemoveAllAuras();
                }

                guid = instance->GetGuidData(DATA_SECOND_SHIP);

                if (auto* ptr = ObjectAccessor::GetCreature(*me, guid))
                {
                    ptr->CastStop();
                    ptr->RemoveAllAuras();
                }
            }

            void DamageTaken(Unit* /**/, uint32 & damage) override
            {
                if (me->HealthBelowPct(66) && !_firstPhase)
                {
                    _firstPhase = true;
                    events.Reset();
                    DesactivateShips();
                    events.ScheduleEvent(EVENT_DEMONIC_PORTAL, 100ms);
                }
                else if (me->HealthBelowPct(33) && !_secondPhase)
                {
                    _secondPhase = true;
                    DesactivateShips();
                    events.Reset();
                    events.ScheduleEvent(EVENT_DEMONIC_PORTAL, 100ms);
                }
            }

            void ShipReached()
            {
                me->SetSpeedRate(MOVE_WALK, 1.f);
                me->SetSpeedRate(MOVE_FLIGHT, 1.f);
                me->SetSpeedRate(MOVE_RUN, 1.f);
                me->RemoveUnitMovementFlag(MOVEMENTFLAG_FLYING);
                _isFlying = false;
            }

            void HandleHarvesters(bool state)
            {
                std::list<Creature*> harvesters;
                me->GetCreatureListWithEntryInGrid(harvesters, NPC_SOUL_HARVESTER);

                if (harvesters.empty())
                    return;

                for (auto & it : harvesters)
                {
                    if (state)
                        it->CastSpell(it, SPELL_SOUL_HARVEST, true);
                    else
                        it->RemoveAurasDueToSpell(SPELL_SOUL_HARVEST);
                }
            }

            void MovementInform(uint32 type, uint32 id) override
            {
                if (!_isFlying)
                    return;

                if (type == POINT_MOTION_TYPE || WAYPOINT_MOTION_TYPE)
                {
                    switch (id)
                    {
                        case POINT_DEMONIC_PORTAL:
                        {
                            me->SetSpeedRate(MOVE_WALK, 8.5f);
                            me->SetSpeedRate(MOVE_FLIGHT, 8.5f);
                            me->SetSpeedRate(MOVE_RUN, 8.5f);
                            me->SetCanFly(true);
                            me->SetDisableGravity(true);
                            me->SetReactState(REACT_PASSIVE);
                            me->AddUnitMovementFlag(MOVEMENTFLAG_FLYING);
                            me->GetMotionMaster()->MovePath(_pathChosen, false);
                            break;
                        }

                        case POINT_FIRST_SHIP:
                        {
                            if (_pathChosen != FIRST_SHIP_PATH)
                                return;

                            ShipReached();
                            _times = 2;
                            events.ScheduleEvent(EVENT_DISINTEGRATE_SHIP, 1s);
                            events.ScheduleEvent(EVENT_CHECK_PLAYER_NEAR, 500ms);
                            break;
                        }

                        case POINT_SECOND_SHIP:
                        {
                            ShipReached();
                            _times = 3;
                            events.ScheduleEvent(EVENT_STABILIZE_RIFT, 1s);
                            break;
                        }
                    }
                }
            }

            uint32 GetData(uint32 id) const override
            {
                if (id == DATA_SHIP_PATH)
                    return _pathChosen;

                return 0;
            }

            ObjectGuid GetGUID(int32 id) const override
            {
                if (id == DATA_FELBEAM_TARGET)
                    return _TargetFelBeam;

                return ObjectGuid::Empty;
            }

            void ExecuteEvent(uint32 eventId) override
            {
                switch (eventId)
                {
                    case EVENT_CHECK_PLAYER_NEAR:
                    {
                        std::list<Player*> players;
                        me->GetPlayerListInGrid(players, 10.f);
                        if (!players.empty())
                        {
                            HandleHarvesters(false);
                            events.CancelEvent(EVENT_CHECK_PLAYER_NEAR);
                            events.CancelEvent(EVENT_DISINTEGRATE_SHIP);
                            me->SetReactState(REACT_AGGRESSIVE);
                            events.ScheduleEvent(EVENT_BOMBARDMENT, 20s);
                            events.ScheduleEvent(EVENT_DISINTEGRATE, 10s);
                            events.ScheduleEvent(EVENT_BURNING_BLAST, 5s);
                            events.ScheduleEvent(EVENT_CHAOTIC_SHADOWS, 8s, 12s);
                        }
                        else
                            events.ScheduleEvent(EVENT_CHECK_PLAYER_NEAR, 500ms);
                        break;
                    }

                    case EVENT_DISINTEGRATE:
                    {
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0, true))
                        {
                            me->SetReactState(REACT_PASSIVE);
                            me->SetFacingToObject(target);
                            DoCast(target, SPELL_DISINTEGRATE);
                            events.ScheduleEvent(EVENT_RESTORE_STATE, 100ms);
                        }

                        events.ScheduleEvent(EVENT_DISINTEGRATE, 10s);
                        break;
                    }

                    case EVENT_RESTORE_STATE:
                    {
                        me->SetReactState(REACT_AGGRESSIVE);
                        break;
                    }

                    case EVENT_DISINTEGRATE_SHIP:
                    {
                        DoCastAOE(SPELL_DISINTEGRATE);
                        events.ScheduleEvent(EVENT_DISINTEGRATE_SHIP, 3s);
                        break;
                    }

                    case EVENT_BURNING_BLAST:
                    {
                        DoCastVictim(SPELL_BURNING_BLAST);
                        events.ScheduleEvent(EVENT_BURNING_BLAST, 5s);
                        break;
                    }

                    case EVENT_CHAOTIC_SHADOWS:
                    {
                        _angle = 0;

                        for (uint8 i = 0; i < _times; ++i)
                        {
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0, true, true, -SPELL_CHAOTIC_SHADOWS))
                                DoCast(target, SPELL_CHAOTIC_SHADOWS);
                        }

                        events.ScheduleEvent(EVENT_CHAOTIC_SHADOWS, 20s, 25s);
                        break;
                    }

                    case EVENT_FEL_BEAM:
                    {
                        ObjectGuid guid = instance->GetGuidData(DATA_FIRST_SHIP);

                        if (auto* ptr = ObjectAccessor::GetCreature(*me, guid))
                        {
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0, true))
                            {
                                ptr->CastSpell(ptr, SPELL_FEL_BEAM_VISUAL, true);
                                _TargetFelBeam = target->GetGUID();
                                DoCast(target, SPELL_FEL_BEAM_MARKED, true);
                            }
                        }
                        events.ScheduleEvent(EVENT_FEL_BEAM, 40s);
                        break;
                    }

                    case EVENT_BOMBARDMENT:
                    {
                        ObjectGuid guid = instance->GetGuidData(DATA_SECOND_SHIP);

                        if (auto* ptr = ObjectAccessor::GetCreature(*me, guid))
                            ptr->CastSpell(ptr, SPELL_BOMBARDMENT_CHARGE, true);
                        events.ScheduleEvent(EVENT_BOMBARDMENT, _firstPhase ? 20s : 40s);
                        break;
                    }

                    case EVENT_DEMONIC_PORTAL:
                    {
                        me->SetReactState(REACT_PASSIVE);
                        me->AttackStop();
                        me->StopMoving();
                        _isFlying = true;

                        if (_firstPhase && !_secondPhase)
                            _pathChosen = FIRST_SHIP_PATH;
                        else
                            _pathChosen = SECOND_SHIP_PATH;

                        DoCast(me, SPELL_DEMONIC_PORTAL_SUMMON, true);

                        Creature* portal = me->FindNearestCreature(NPC_DEMONIC_PORTAL, 125.f, true);

                        if (portal)
                            DoCast(portal, SPELL_DEMONIC_PORTAL);

                        break;
                    }

                    case EVENT_STABILIZE_RIFT:
                    {
                        if (Creature* rift = me->FindNearestCreature(NPC_STABILIZE_RIFT, 250.f))
                            DoCast(rift, SPELL_STABILIZE_RIFT);

                        me->SetReactState(REACT_AGGRESSIVE);
                        events.ScheduleEvent(EVENT_DISINTEGRATE, 10s);
                        events.ScheduleEvent(EVENT_BURNING_BLAST, 5s);
                        events.ScheduleEvent(EVENT_CHAOTIC_SHADOWS, 8s, 12s);
                        break;
                    }
                }
            }

            private:
                ObjectGuid _TargetFelBeam;
                uint32 _pathChosen;
                bool _firstPhase, _secondPhase, _isFlying;
                float _angle, _times;
                Position _homePosition;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new boss_new_vizaduum_AI(creature);
        }
};

class npc_kara_fel_cannon : public CreatureScript
{
    public:
        npc_kara_fel_cannon() : CreatureScript("npc_kara_fel_cannon") { }

        struct npc_kara_fel_cannon_AI : public ScriptedAI
        {
            explicit npc_kara_fel_cannon_AI(Creature* me) : ScriptedAI(me)
            {
                _timerCheck = 0;
            }

            void IsSummonedBy(Unit* summoner) override
            {
                if (!summoner)
                    return;

                if (Creature* vizaduum = me->GetInstanceScript()->GetCreature(DATA_VIZADUUM))
                {
                    _TargetGuid = vizaduum->GetAI()->GetGUID(DATA_FELBEAM_TARGET);

                    Player* target = ObjectAccessor::GetPlayer(*me, _TargetGuid);

                    if (target)
                        me->GetMotionMaster()->MoveFollow(target, 0, 0);
                }
            }

            void UpdateAI(uint32 diff) override
            {
                _timerCheck += diff;

                if (_timerCheck >= 1.5 * IN_MILLISECONDS)
                {
                    _timerCheck = 0;
                    Player* ptr = ObjectAccessor::GetPlayer(*me, _TargetGuid);

                    if (ptr)
                        me->GetMotionMaster()->MoveFollow(ptr, 0, 0);
                }
            }

            private:
                uint32 _timerCheck = 0;
                ObjectGuid _TargetGuid;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_kara_fel_cannon_AI(creature);
        }
};

class npc_kara_invisible_vehicle : public CreatureScript
{
    public:
        npc_kara_invisible_vehicle() : CreatureScript("npc_kara_invisible_vehicle") { }

        struct npc_kara_invisible_vehicle_AI : public ScriptedAI
        {
            explicit npc_kara_invisible_vehicle_AI(Creature* me) : ScriptedAI(me) { }

            void PassengerBoarded(Unit* passenger, int8 /**/, bool /**/) override
            {
                if (!passenger)
                    return;

                _passengerGUID = passenger->GetGUID();

                uint32 path = me->GetInstanceScript()->GetCreature(DATA_VIZADUUM)->GetAI()->GetData(DATA_SHIP_PATH);
                if (path == FIRST_SHIP_PATH)
                    me->GetMotionMaster()->MoveSmoothPath(1, FirstPath, 5, false);
                else if (path == SECOND_SHIP_PATH)
                    me->GetMotionMaster()->MoveSmoothPath(1, SecondPath, 4, false);
            }

            void MovementInform(uint32 type, uint32 id) override
            {
                if (type == EFFECT_MOTION_TYPE && id == 1)
                {
                    Player* passenger = ObjectAccessor::GetPlayer(*me, _passengerGUID);

                    if (passenger)
                        passenger->RemoveAurasDueToSpell(SPELL_DEMONIC_PORTAL_PLAYER);

                    me->DespawnOrUnsummon(100);
                }
            }

            private:
                ObjectGuid _passengerGUID;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_kara_invisible_vehicle_AI(creature);
        }
};

class npc_kara_stabilize_rift : public CreatureScript
{
    public:
        npc_kara_stabilize_rift() : CreatureScript("npc_kara_stabilize_rift") { }

        struct npc_kara_stabilize_rift_AI : public ScriptedAI
        {
            public:
                npc_kara_stabilize_rift_AI(Creature* me) : ScriptedAI(me), _summons(me), _riftOpened(false) { }

                void JustSummoned(Creature* summon) override
                {
                    if (!summon)
                        return;

                    DoZoneInCombat(summon);
                    _summons.Summon(summon);
                }

                void SummonedCreatureDespawn(Creature* summon) override
                {
                    if (!summon)
                        return;

                    _summons.Despawn(summon);
                }

                void Reset()
                {
                    _riftOpened = false;
                    me->RemoveAllAuras();
                    _summons.DespawnAll();
                    _events.Reset();
                }

                void DoAction(int32 action) override
                {
                    if (action == ACTION_OPENED_RIFT)
                    {
                        _riftOpened = true;
                        me->CastSpell(me, SPELL_STABILIZE_RIFT_SIZE, true);
                        me->CastSpell(me, SPELL_STABILIZE_RIFT_VISUAL, true);
                        _events.ScheduleEvent(EVENT_FELGUARD_SENTRY, 5s);
                    }
                    else if (action == ACTION_CLOSED_RIFT)
                    {
                        _riftOpened = false;
                        _events.ScheduleEvent(EVENT_FELGUARD_SENTRY, 5s);
                    }
                }

                void UpdateAI(uint32 diff) override
                {
                    _events.Update(diff);

                    if (me->HasUnitState(UNIT_STATE_CASTING))
                        return;

                    if (uint32 eventId = _events.ExecuteEvent())
                    {
                        if (eventId == EVENT_FELGUARD_SENTRY)
                        {
                            me->SummonCreature(NPC_FELGUARD_SENTRY, me->GetPosition(), TEMPSUMMON_CORPSE_DESPAWN, 5000);
                            me->SummonCreature(NPC_FELGUARD_SENTRY, me->GetPosition(), TEMPSUMMON_CORPSE_DESPAWN, 5000);

                            if (_riftOpened)
                                _events.ScheduleEvent(EVENT_FELGUARD_SENTRY, 5s);
                            else
                                _events.ScheduleEvent(EVENT_FELGUARD_SENTRY, 25s);
                        }
                    }
                }

                private:
                    bool _riftOpened;
                    SummonList _summons;
                    EventMap _events;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_kara_stabilize_rift_AI(creature);
        }
};

class spell_vizaduum_chaotic_shadows : public SpellScriptLoader
{
    public:
        spell_vizaduum_chaotic_shadows() : SpellScriptLoader("spell_vizaduum_chaotic_shadows") { }

        class spell_chaotic_shadows_AuraScript : public AuraScript
        {
            public:
                PrepareAuraScript(spell_chaotic_shadows_AuraScript);

                void HandleOnRemove(AuraEffect const* /**/, AuraEffectHandleModes /**/)
                {
                    if (!GetUnitOwner())
                        return;

                    GetCaster()->CastSpell(GetUnitOwner(), SPELL_EXPLOSIVE_SHADOWS_AREA, true);
                }

                void Register() override
                {
                    OnEffectRemove += AuraEffectRemoveFn(spell_chaotic_shadows_AuraScript::HandleOnRemove, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);
                }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_chaotic_shadows_AuraScript();
        }
};

class spell_vizaduum_fel_beam_charge : public SpellScriptLoader
{
    public:
        spell_vizaduum_fel_beam_charge() : SpellScriptLoader("spell_vizaduum_fel_beam_charge") { }

        class spell_fel_beam_charge_AuraScript : public AuraScript
        {
            public:
                PrepareAuraScript(spell_fel_beam_charge_AuraScript);

                void HandleOnRemove(AuraEffect const* /**/, AuraEffectHandleModes /**/)
                {
                    if (!GetUnitOwner())
                        return;

                    Creature* dummy = GetUnitOwner()->GetInstanceScript()->GetCreature(DATA_FEL_CANNON);

                    if (dummy)
                        GetUnitOwner()->CastSpell(dummy, SPELL_FEL_BEAM_CHANNELED, true);
                }

                void Register() override
                {
                    OnEffectRemove += AuraEffectRemoveFn(spell_fel_beam_charge_AuraScript::HandleOnRemove, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
                }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_fel_beam_charge_AuraScript();
        }
};

class spell_vizaduum_bombardment_charge : public SpellScriptLoader
{
    public:
        spell_vizaduum_bombardment_charge() : SpellScriptLoader("spell_vizaduum_bombardment_charge") { }

        class spell_bombardment_charge_AuraScript : public AuraScript
        {
            public:
                PrepareAuraScript(spell_bombardment_charge_AuraScript);

                void HandleOnRemove(AuraEffect const* /**/, AuraEffectHandleModes /**/)
                {
                    if (!GetUnitOwner())
                        return;

                    GetUnitOwner()->CastSpell(GetUnitOwner(), SPELL_BOMBARDMENT_AURA, true);
                }

                void Register() override
                {
                    OnEffectRemove += AuraEffectRemoveFn(spell_bombardment_charge_AuraScript::HandleOnRemove, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
                }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_bombardment_charge_AuraScript();
        }
};

class spell_vizaduum_bombardment_aura : public SpellScriptLoader
{
    public:
        spell_vizaduum_bombardment_aura() : SpellScriptLoader("spell_vizaduum_bombardment_aura") { }

        class spell_bombardment_periodic_AuraScript : public AuraScript
        {
            public:
                PrepareAuraScript(spell_bombardment_periodic_AuraScript);

                bool Load()
                {
                    _radius = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_50_YARDS);
                    return true;
                }

                void HandlePeriodic(AuraEffect const* /**/)
                {
                    PreventDefaultAction();

                    Creature* vizaduum = GetUnitOwner()->GetInstanceScript()->GetCreature(DATA_VIZADUUM);

                    SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(SPELL_BOMBARDMENT_MISSILE, vizaduum->GetMap()->GetDifficultyID());
                    Position pos = vizaduum->GetRandomNearPosition(_radius->Radius);

                    _target.SetDst(pos);

                    GetUnitOwner()->CastSpell(_target, spellInfo, nullptr, TRIGGERED_FULL_MASK);
                }

                void Register() override
                {
                    OnEffectPeriodic += AuraEffectPeriodicFn(spell_bombardment_periodic_AuraScript::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
                }

            private:
                SpellCastTargets _target;
                SpellRadiusEntry const* _radius;
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_bombardment_periodic_AuraScript();
        }
};

class spell_vizaduum_disintegrate : public SpellScriptLoader
{
    public:
        spell_vizaduum_disintegrate() : SpellScriptLoader("spell_vizaduum_disintegrate") { }

        class spell_disintegrate_SpellScript : public SpellScript
        {
            public:
                PrepareSpellScript(spell_disintegrate_SpellScript);

                void FilterTargets(SpellTargets & targets)
                {
                    if (targets.empty())
                        return;

                    Unit* caster = GetCaster();

                    targets.remove_if([&] (WorldObject*& target)
                    {
                        return !caster->isInFront(target, 0.1745f);
                    });
                }

                void Register() override
                {
                    OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_disintegrate_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_CONE_ENEMY_104);
                    OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_disintegrate_SpellScript::FilterTargets, EFFECT_1, TARGET_UNIT_CONE_ENEMY_104);
                }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_disintegrate_SpellScript();
        }
};

class spell_vizaduum_stabilize_rift : public SpellScriptLoader
{
    public:
        spell_vizaduum_stabilize_rift() : SpellScriptLoader("spell_vizaduum_stabilize_rift") { }

        class spell_stabilize_rift_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_stabilize_rift_AuraScript);

            void HandleOnRemove(AuraEffect const* /**/, AuraEffectHandleModes /**/)
            {
                int32 restantTime = GetDuration();

                if (restantTime <= 1)
                    GetUnitOwner()->GetAI()->DoAction(ACTION_OPENED_RIFT);
                else
                    GetUnitOwner()->GetAI()->DoAction(ACTION_CLOSED_RIFT);
            }

            void Register() override
            {
                OnEffectRemove += AuraEffectRemoveFn(spell_stabilize_rift_AuraScript::HandleOnRemove, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_stabilize_rift_AuraScript();
        }
};

class at_kara_explosive_shadows : public AreaTriggerEntityScript
{
    public:
        at_kara_explosive_shadows() : AreaTriggerEntityScript("at_kara_explosive_shadows") { }

        struct at_kara_explosive_shadows_AI : public AreaTriggerAI
        {
            explicit at_kara_explosive_shadows_AI(AreaTrigger* at) : AreaTriggerAI(at)
            {
                _timerBorn = 0;
                _borned = false;
                _enableCast = false;
            }

            void SetAngleToMove()
            {
                for (auto & it : Angles)
                {
                    if (it.second == at->GetEntry())
                    {
                        float angle = (it.first * float(M_PI))/180.f;
                        at->SetOrientation(at->GetOrientation() + angle);
                        break;
                    }
                }
            }

            void SetupSpline()
            {
                if (!at->GetCaster())
                    return;

                std::vector<G3D::Vector3> points;
                float dist = 100.f;

                G3D::Vector3 src = { at->GetPositionX(), at->GetPositionY(), at->GetPositionZ() };
                G3D::Vector3 tgt;

                SetAngleToMove();
                tgt.x = src.x + (dist * cosf(at->GetOrientation()));
                tgt.y = src.y + (dist * sinf(at->GetOrientation()));
                tgt.z = src.z;

                float dx = (tgt.x - src.x);
                float dy = (tgt.y - src.y);
                float dz = (tgt.z - src.z);

                for (uint32 i = 0; i < 100; ++i)
                {
                    src.x += (dx/dist);
                    src.y += (dy/dist);

                    points.push_back(src);
                }

                at->InitSplines(points, at->GetDuration() * 0.5);
            }

            void OnInitialize() override { }

            void OnUpdate(uint32 diff) override
            {
                if (_borned && _enableCast)
                    return;

                _timerBorn += diff;

                if (_timerBorn >= 500 && !_borned)
                {
                    _borned = true;
                    SetupSpline();
                }
                else if (_timerBorn >= IN_MILLISECONDS && !_enableCast)
                    _enableCast = true;
            }

            void OnUnitEnter(Unit* target) override
            {
                if (!_enableCast)
                    return;

                if (!target)
                    return;

                if (target->GetTypeId() == TYPEID_PLAYER)
                    at->GetCaster()->CastSpell(target, SPELL_EXPLOSIVE_SHADOWS_DMG, true);
            }

            private:
                uint32 _timerBorn;
                bool _borned, _enableCast;
        };

        AreaTriggerAI* GetAI(AreaTrigger* at) const override
        {
            return new at_kara_explosive_shadows_AI(at);
        }
};

class at_kara_demonic_portal : public AreaTriggerEntityScript
{
    public:
        at_kara_demonic_portal() : AreaTriggerEntityScript("at_kara_demonic_portal") { }

        struct at_kara_demonic_portal_AI : public AreaTriggerAI
        {
            explicit at_kara_demonic_portal_AI(AreaTrigger* at) : AreaTriggerAI(at)
            {}

            void OnInitialize()
            {
                at->GetCaster()->GetInstanceScript()->GetCreature(DATA_VIZADUUM)->GetMotionMaster()->MovePoint(POINT_DEMONIC_PORTAL, at->GetPosition());
            }

            void OnUnitEnter(Unit* target) override
            {
                if (!target)
                    return;

                if (target->GetTypeId() == TYPEID_PLAYER)
                {
                    Creature* vehicle = at->GetCaster()->SummonCreature(NPC_INVISIBLE_VEHICLE, at->GetPosition());

                    if (vehicle)
                    {
                        target->CastSpell(target, SPELL_DEMONIC_PORTAL_PLAYER, true);
                        target->EnterVehicle(vehicle);
                    }
                }
            }
        };

        AreaTriggerAI* GetAI(AreaTrigger* at) const override
        {
            return new at_kara_demonic_portal_AI(at);
        }
};

class at_kara_fel_beam : public AreaTriggerEntityScript
{
    public:
        at_kara_fel_beam() : AreaTriggerEntityScript("at_kara_fel_beam") { }

        struct at_kara_fel_beam_AI : public AreaTriggerAI
        {
            explicit at_kara_fel_beam_AI(AreaTrigger* at) : AreaTriggerAI(at) { }

            void OnUnitEnter(Unit* target) override
            {
                if (target && target->GetTypeId() == TYPEID_PLAYER)
                    at->GetCaster()->CastSpell(target, SPELL_FEL_BEAM_DMG, true);
            }
        };

        AreaTriggerAI* GetAI(AreaTrigger* at) const override
        {
            return new at_kara_fel_beam_AI(at);
        }
};

class at_kara_fel_flames : public AreaTriggerEntityScript
{
    public:
        at_kara_fel_flames() : AreaTriggerEntityScript("at_kara_fel_flames") { }

        struct at_kara_fel_flames_AI : public AreaTriggerAI
        {
            explicit at_kara_fel_flames_AI(AreaTrigger* at) : AreaTriggerAI(at) { }

            void OnCreate()
            {
                at->GetCaster()->_UnregisterAreaTrigger(at);
                at->GetCaster()->GetInstanceScript()->GetCreature(DATA_VIZADUUM)->_RegisterAreaTrigger(at);
            }

            void OnUnitEnter(Unit* target) override
            {
                if (target && target->GetTypeId() == TYPEID_PLAYER)
                    target->CastSpell(target, SPELL_FEL_FLAMES_DMG, true);
            }

            void OnUnitExit(Unit* target) override
            {
                if (target && target->GetTypeId() == TYPEID_PLAYER)
                    target->RemoveAurasDueToSpell(SPELL_FEL_FLAMES_DMG);
            }
        };

        AreaTriggerAI* GetAI(AreaTrigger* at) const override
        {
            return new at_kara_fel_flames_AI(at);
        }
};

class at_kara_soul_harvest : public AreaTriggerEntityScript
{
    public:
        at_kara_soul_harvest() : AreaTriggerEntityScript("at_kara_soul_harvest") { }

        struct at_kara_soul_harvest_AI : public AreaTriggerAI
        {
            explicit at_kara_soul_harvest_AI(AreaTrigger* at) : AreaTriggerAI(at), _timerCheck(0)
            {
                _timerCheck = 0;
            }

            void OnUpdate(uint32 diff) override
            {
                _timerCheck += diff;

                if (_timerCheck >= IN_MILLISECONDS)
                {
                    _timerCheck = 0;
                    for (auto & it : at->GetInsideUnits())
                    {
                        if (Player* ptr = ObjectAccessor::GetPlayer(*at->GetCaster(), it))
                            at->GetCaster()->CastSpell(ptr, SPELL_SOUL_HARVEST_DMG, true);
                    }
                }
            }

            private:
                uint32 _timerCheck;
        };

        AreaTriggerAI* GetAI(AreaTrigger* at) const override
        {
            return new at_kara_soul_harvest_AI(at);
        }
};

void AddSC_boss_vizaduum_karazhan_legion()
{
    new boss_new_vizaduum();
    new npc_kara_fel_cannon();
    new npc_kara_invisible_vehicle();
    new npc_kara_stabilize_rift();
    new spell_vizaduum_chaotic_shadows();
    new spell_vizaduum_fel_beam_charge();
    new spell_vizaduum_bombardment_charge();
    new spell_vizaduum_bombardment_aura();
    new spell_vizaduum_disintegrate();
    new spell_vizaduum_stabilize_rift();
    new at_kara_explosive_shadows();
    new at_kara_demonic_portal();
    new at_kara_fel_beam();
    new at_kara_fel_flames();
    new at_kara_soul_harvest();
}
