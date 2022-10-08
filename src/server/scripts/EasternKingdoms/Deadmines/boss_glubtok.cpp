/*
 * Copyright (C) 2022 BfaCore Reforged
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
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "GameObject.h"
#include "GridNotifiers.h"
#include "deadmines.h"
#include "MoveSplineInit.h"
#include "VMapFactory.h"
#include "Vehicle.h"
#include <G3D/Vector3.h>
#include "SpellHistory.h"

enum Spells
{
    SPELL_FIRE_BLOSSOM               = 88129,
    SPELL_FIRE_BLOSSOM_VISUAL        = 88164,
    SPELL_FROST_BLOSSOM              = 88169,
    SPELL_FROST_BLOSSOM_VISUAL       = 88165,
    SPELL_TELEPORT_VISUAL            = 88002,
    SPELL_ARCANE_POWER               = 88009,
    SPELL_FIST_OF_FLAME              = 87859,
    SPELL_FIST_OF_FROST              = 87861,
    SPELL_BLINK                      = 87925,

    SPELL_BLOSSOM_TARGETTING         = 88140,

    SPELL_ARCANE_FIRE                = 88007,
    SPELL_ARCANE_FIRE_BEAM           = 88072,
    SPELL_ARCANE_FROST_BEAM          = 88093,
    SPELL_TRIGGER_FIRE_WALL          = 91398,
    SPELL_FIRE_WALL_TRIGGERED        = 91397,

    SPELL_ARCANE_OVERLOAD_INITIAL    = 88183,
    SPELL_FEIGN_DEATH                = 70628,
    SPELL_ARCANE_OVERLOAD_SUICIDE    = 88185,
    SPELL_ARCANE_OVERLOAD_BOOM       = 90520,
};

enum Creatures
{
    NPC_GLUBTOK_MAIN_PLATTER    = 48974,
    NPC_FROST_BLOSSOM_DUMMY     = 47284,
    NPC_FIRE_BLOSSOM_DUMMY      = 47282,

    NPC_BEAM_BUNNY              = 47242,
};

const Position Phase2Pos = {-193.368f, -441.828f, 53.5931f, 1.692970f};

enum Events
{
    EVENT_ELEMENTAL_FISTS               = 1,
    EVENT_BLINK,

    EVENT_TRANSITION_SAY_1,
    EVENT_TRANSITION_SAY_2,
    EVENT_TRANSITION_CAST,
    EVENT_SAY_FIREWALL,
    EVENT_SUMMON_BLOSSOM,

    EVENT_FALL_GROUND,
    EVENT_DIE,

    //Main Platter
    EVENT_START_PART_1,
    EVENT_START_PART_2,
    EVENT_START_PART_3,
};

enum  Actions
{
    ACTION_START_FIREWALL = 1,
    ACTION_STOP_FIREWALL,
};

enum Points
{
    POINT_FALL_GROUND = 1,
};

enum Texts
{
    SAY_AGGRO   = 0,
    SAY_DEATH,
    SAY_KILL,
    SAY_FISTS_OF_FROST,
    SAY_FISTS_OF_FLAME,
    SAY_TRANSITION_1,
    SAY_TRANSITION_2,
    SAY_ARCANE_POWER,
    SAY_SUMMON_FIRE_WALL

};

typedef bool LastElement;
#define Flame false
#define Frost true

class DelayedCastEvent : public BasicEvent
{
public:
    DelayedCastEvent(Unit* trigger, uint32 spellId) : _trigger(trigger), _spellId(spellId) { }

    bool Execute(uint64 /*time*/, uint32 /*diff*/) override
    {
        _trigger->CastSpell(_trigger, _spellId, TRIGGERED_IGNORE_CASTER_MOUNTED_OR_ON_VEHICLE);
        return true;
    }

private:
    Unit* _trigger;
    uint32 _spellId;
};

class boss_glubtok : public CreatureScript
{
public:
    boss_glubtok() : CreatureScript("boss_glubtok") { }

    struct boss_glubtokAI : public BossAI
    {
        boss_glubtokAI(Creature* creature) : BossAI(creature, DATA_GLUBTOK)
        {
            me->SetCanDualWield(true);
            platter = me->SummonCreature(NPC_GLUBTOK_MAIN_PLATTER, Phase2Pos.GetPositionX(), Phase2Pos.GetPositionY(), Phase2Pos.GetPositionZ() + 2.0f);
            platter->setActive(true);
        }

        void Reset() override
        {
            _Reset();
            _lastElement = Frost;
            _phase2 = false;
            _dying = false;
            _transitionDone = false;
            me->SetReactState(REACT_AGGRESSIVE);
            me->SetDisableGravity(false);
            me->SetCanFly(false);

            me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_IMMUNE_TO_PC));
            me->RemoveDynamicFlag(UNIT_DYNFLAG_DEAD);
            me->RemoveUnitFlag2(UNIT_FLAG2_FEIGN_DEATH);
            me->ClearUnitState(UNIT_STATE_CANNOT_TURN);

            platter->AI()->DoAction(ACTION_STOP_FIREWALL);
        }

        void EnterCombat(Unit* /*who*/) override
        {
            Talk(SAY_AGGRO);
            events.ScheduleEvent(EVENT_ELEMENTAL_FISTS, 5000);
        }

        void JustDied(Unit* killer) override
        {
            BossAI::JustDied(killer);
            platter->AI()->DoAction(ACTION_STOP_FIREWALL);
        }

        void KilledUnit(Unit* victim) override
        {
            if (victim != me)
                Talk(SAY_KILL);
        }

        void EnterEvadeMode(EvadeReason /*why*/) override
        {
            me->ClearUnitState(UNIT_STATE_CANNOT_TURN);
            platter->AI()->DoAction(ACTION_STOP_FIREWALL);
            BossAI::EnterEvadeMode();
        }

        void JustSummoned(Creature* summon) override
        {
            if (!me->IsInCombat())
            {
                summon->DespawnOrUnsummon();
                return;
            }
            BossAI::JustSummoned(summon);
            summon->AI()->AttackStart(me->GetVictim());
        }

        void DamageTaken(Unit* /*attacker*/, uint32& damage) override
        {
            if (!_phase2 && me->HealthBelowPctDamaged(50, damage) && !me->HasUnitState(UNIT_STATE_CASTING))
            {
                _phase2 = true;
                events.Reset();
                me->SetReactState(REACT_PASSIVE);
                me->AttackStop();
                me->GetMotionMaster()->Clear();
                float x, y, z, o;
                Phase2Pos.GetPosition(x, y, z, o);
                me->NearTeleportTo(x, y, z, o);
                DoCast(SPELL_TELEPORT_VISUAL);
                DoResetThreat();
                events.ScheduleEvent(EVENT_TRANSITION_SAY_1, 4000);
                events.ScheduleEvent(EVENT_TRANSITION_SAY_2, 6000);
                events.ScheduleEvent(EVENT_TRANSITION_CAST, 8000);
            }

            if (me->HealthBelowPctDamaged(1, damage))
            {
                if (!_dying && _transitionDone)
                {
                    platter->AI()->DoAction(ACTION_STOP_FIREWALL);
                    events.Reset();
                    DoCast(me, SPELL_ARCANE_OVERLOAD_INITIAL, true);
                    SummonBeams();
                    Talk(SAY_DEATH);
                    _dying = true;
                    events.ScheduleEvent(EVENT_FALL_GROUND, 5000);
                }
            }
        }

        G3D::Vector3 GenerateTargetForBeamBunny(bool left)
        {
            float angle;
            G3D::Vector3 pos;

            for (uint8 i = 0; i < 8; ++i)
            {
                if (left)
                    angle = me->GetOrientation() - float(M_PI) / 2  + frand(-float(M_PI) / 3.0, float(M_PI) / 6.0f);
                else
                    angle = me->GetOrientation() + float(M_PI) / 2  + frand(-float(M_PI) / 6.0f, float(M_PI) / 3.0f);

                pos.z = me->GetPositionZ() + frand(4.0f, 23.0f);

                me->GetNearPoint2D(pos.x, pos.y, 25.0f, angle);
                VMAP::VMapFactory::createOrGetVMapManager()->getObjectHitPos(me->GetMapId(), me->m_positionX, me->m_positionY, me->m_positionZ + 0.5f, pos.x, pos.y, pos.z + 0.5f, pos.x, pos.y, pos.z, -1.5f);

                if (me->GetExactDist2d(pos.x, pos.y) >= 7.5f)
                    break;
            }
            return pos;
        }

        void SummonBeams()
        {
            G3D::Vector3 pos1, pos2, pos3;
            uint32 spellID;
            for (int i = 0; i < 8; ++i)
            {
                if (i < 4)
                {
                    pos1 = GenerateTargetForBeamBunny(true);
                    pos2 = GenerateTargetForBeamBunny(true);
                    pos3 = GenerateTargetForBeamBunny(true);
                    spellID = SPELL_ARCANE_FIRE_BEAM;
                } else
                {
                    pos1 = GenerateTargetForBeamBunny(false);
                    pos2 = GenerateTargetForBeamBunny(false);
                    pos3 = GenerateTargetForBeamBunny(false);
                    spellID = SPELL_ARCANE_FROST_BEAM;
                }

                if (Creature* dummy = me->SummonCreature(NPC_BEAM_BUNNY, pos1.x, pos1.y, pos1.z, 0.0f, TEMPSUMMON_TIMED_DESPAWN, 7000))
                {
                    dummy->CastSpell(me, spellID, true);
                    dummy->ClearUnitState(UNIT_STATE_CASTING);
                    Movement::MoveSplineInit init(dummy);
                    init.Path().push_back(pos1);
                    init.Path().push_back(pos2);
                    init.Path().push_back(pos3);
                    init.SetVelocity(1.5f);
                    init.SetFly();
                    init.SetCyclic();
                    init.Launch();
                }
            }
        }

        void MovementInform(uint32 type, uint32 id) override
        {
            if (type != EFFECT_MOTION_TYPE)
                return;

            if (id == POINT_FALL_GROUND)
            {
                me->AddUnitFlag(UNIT_FLAG_IMMUNE_TO_PC);
                DoCast(SPELL_FEIGN_DEATH);

                me->GetScheduler().Schedule(Seconds(1), [this](TaskContext /*context*/)
                {
                    me->CastSpell(me, SPELL_ARCANE_OVERLOAD_BOOM, true);
                });

                me->GetScheduler().Schedule(Seconds(2), [this](TaskContext /*context*/)
                {
                    me->CastSpell(me, SPELL_ARCANE_OVERLOAD_SUICIDE, true);
                });
            }
        }


        void AttackStart(Unit* victim) override
        {
            if (me->HasUnitState(UNIT_STATE_CASTING))
            {
                AttackStartNoMove(victim);
            } else
                BossAI::AttackStart(victim);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING) && !me->GetCurrentSpell(CURRENT_CHANNELED_SPELL))
                return;

            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_ELEMENTAL_FISTS:
                        if (_lastElement == Flame)
                        {
                            DoCast(SPELL_FIST_OF_FROST);
                            Talk(SAY_FISTS_OF_FROST);
                        } else
                        {
                            DoCast(SPELL_FIST_OF_FLAME);
                            Talk(SAY_FISTS_OF_FLAME);
                        }
                        me->SetReactState(REACT_AGGRESSIVE);
                        AttackStart(me->SelectVictim());
                        _lastElement = !_lastElement;
                        events.ScheduleEvent(EVENT_BLINK, 12000);
                        break;
                    case EVENT_BLINK:
                        if (Unit* random = SelectTarget(SELECT_TARGET_RANDOM))
                        {
                            DoCast(random, SPELL_BLINK);
                            me->SetReactState(REACT_PASSIVE);
                            me->AttackStop();
                            me->SetFacingToObject(random);
                            if (IsHeroic())
                            {
                                DoResetThreat();
                            }
                        }
                        events.ScheduleEvent(EVENT_ELEMENTAL_FISTS, 1000);
                        break;
                    case EVENT_TRANSITION_SAY_1:
                        Talk(SAY_TRANSITION_1);
                        break;
                    case EVENT_TRANSITION_SAY_2:
                        Talk(SAY_TRANSITION_2);
                        break;
                    case EVENT_TRANSITION_CAST:
                    {
                        me->AddUnitState(UNIT_STATE_CANNOT_TURN);
                        Talk(SAY_ARCANE_POWER);
                        DoCast(SPELL_ARCANE_POWER);
                        SummonBeams();

                        Movement::MoveSplineInit init(me);
                        init.MoveTo(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ() + 2.0f);
                        init.SetVelocity(1.5f);
                        init.Launch();
                        me->SetDisableGravity(true);

                        _transitionDone = true;

                        if (IsHeroic())
                        {
                            platter->AI()->DoAction(ACTION_STOP_FIREWALL);
                            platter->AI()->DoAction(ACTION_START_FIREWALL);
                            events.ScheduleEvent(EVENT_SAY_FIREWALL, 3500);
                        }
                        events.ScheduleEvent(EVENT_SUMMON_BLOSSOM, 4000);
                        break;
                    }
                    case EVENT_SUMMON_BLOSSOM:
                    {
                        events.ScheduleEvent(EVENT_SUMMON_BLOSSOM, urand(0, 2500));

                        uint32 targetEntry = 0;
                        uint32 targetSpellID = 0;
                        uint32 indicatorSpellID = 0;
                        if (roll_chance_i(50))
                        {
                            targetEntry = NPC_FROST_BLOSSOM_DUMMY;
                            targetSpellID = SPELL_FROST_BLOSSOM;
                            indicatorSpellID = SPELL_FROST_BLOSSOM_VISUAL;
                        } else
                        {
                            targetEntry = NPC_FIRE_BLOSSOM_DUMMY;
                            targetSpellID = SPELL_FIRE_BLOSSOM;
                            indicatorSpellID = SPELL_FIRE_BLOSSOM_VISUAL;
                        }

                        std::list<Creature*> cList;
                        me->GetCreatureListWithEntryInGrid(cList, targetEntry, 100.0f);

                        cList.remove_if(Trinity::UnitAuraCheck(true, indicatorSpellID));

                        if (cList.empty())
                            break;

                        if (Creature* target = Trinity::Containers::SelectRandomContainerElement(cList))
                        {
                            target->CastSpell(target, indicatorSpellID, true);
                            me->CastSpell(target, targetSpellID);
                        }
                        break;
                    }
                    case EVENT_SAY_FIREWALL:
                        Talk(SAY_SUMMON_FIRE_WALL);
                        break;
                    case EVENT_FALL_GROUND:
                        me->ClearUnitState(UNIT_STATE_CANNOT_TURN);
                        me->GetMotionMaster()->MoveFall(POINT_FALL_GROUND);
                        break;
                }

            }

            DoMeleeAttackIfReady();
        }

    private:
        bool _phase2, _dying, _transitionDone;
        LastElement _lastElement;
        Creature* platter;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_glubtokAI(creature);
    }

};

class npc_glubtok_main_platter : public CreatureScript
{
public:
    npc_glubtok_main_platter() : CreatureScript("npc_glubtok_main_platter") { }

    struct npc_glubtok_main_platterAI : public Scripted_NoMovementAI
    {
        npc_glubtok_main_platterAI(Creature* creature) : Scripted_NoMovementAI(creature)
        {
            _turnTimer = 100;
            me->SetDisableGravity(true);
        }

        void Reset() override
        {
            ScriptedAI::Reset();
            _events.Reset();
        }

        void PassengerBoarded(Unit* who, int8 /*seatId*/, bool /*apply*/) override
        {
            who->SetDisableGravity(true);
        }

        void ActivateFireOnSeat(uint8 seat)
        {
            if (Unit* passenger = me->GetVehicleKit()->GetPassenger(seat))
                passenger->GetAI()->DoAction(ACTION_START_FIREWALL);
        }

        void DoAction(int32 const actionID) override
        {
            if (actionID == ACTION_STOP_FIREWALL)
            {
                for (uint8 i = 0; i < 8; ++i)
                {
                    if (Unit* passenger = me->GetVehicleKit()->GetPassenger(i))
                        passenger->GetAI()->DoAction(ACTION_STOP_FIREWALL);
                }
                Reset();

            } else if (actionID == ACTION_START_FIREWALL)
            {
                _events.ScheduleEvent(EVENT_START_PART_1, 4000);
                _events.ScheduleEvent(EVENT_START_PART_2, 8000);
                _events.ScheduleEvent(EVENT_START_PART_3, 12000);
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (_turnTimer <= diff)
            {
                me->SetFacingTo(me->GetOrientation() - M_PI / 150);
                _turnTimer = 100;
            } else
                _turnTimer -= diff;

            _events.Update(diff);

            if (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_START_PART_1:
                        ActivateFireOnSeat(0);
                        ActivateFireOnSeat(4);
                        break;
                    case EVENT_START_PART_2:
                        ActivateFireOnSeat(1);
                        ActivateFireOnSeat(5);
                        break;
                    case EVENT_START_PART_3:
                        ActivateFireOnSeat(2);
                        ActivateFireOnSeat(6);
                        ActivateFireOnSeat(3);
                        ActivateFireOnSeat(7);
                        break;
                }
            }
        }

    private:
        uint32 _turnTimer;
        EventMap _events;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_glubtok_main_platterAI(creature);
    }
};


class npc_glubtok_secondary_platter : public CreatureScript
{
public:
    npc_glubtok_secondary_platter() : CreatureScript("npc_glubtok_secondary_platter") { }

    struct npc_glubtok_secondary_platterAI : public Scripted_NoMovementAI
    {
        npc_glubtok_secondary_platterAI(Creature* creature) : Scripted_NoMovementAI(creature) { }

        void DoAction(int32 const actionID) override
        {
            if (actionID != ACTION_START_FIREWALL && actionID != ACTION_STOP_FIREWALL)
                return;

            switch (actionID)
            {
                case ACTION_START_FIREWALL:
                    for (uint8 i = 0; i < 8; ++i)
                    {
                        if (Unit* passenger =  me->GetVehicleKit()->GetPassenger(i))
                            passenger->CastSpell(passenger, SPELL_TRIGGER_FIRE_WALL, TRIGGERED_IGNORE_CASTER_MOUNTED_OR_ON_VEHICLE);
                    }
                    break;
                case ACTION_STOP_FIREWALL:
                    for (uint8 i = 0; i < 8; ++i)
                    {
                        if (Unit* passenger = me->GetVehicleKit()->GetPassenger(i))
                        {
                            passenger->RemoveAllAuras();
                            passenger->CastStop();
                            Movement::MoveSplineInit init(passenger);
                            init.DisableTransportPathTransformations();
                            init.MoveTo(passenger->GetTransOffsetX(), passenger->GetTransOffsetY(), passenger->GetTransOffsetZ());
                            init.SetFacing(0.0f);
                            init.Launch();
                        }
                    }
                    break;
            }


        }

        void PassengerBoarded(Unit* who, int8 /*seatId*/, bool /*apply*/) override
        {
            who->SetDisableGravity(true);
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_glubtok_secondary_platterAI(creature);
    }
};

class spell_glubtok_generic_proc : public SpellScriptLoader
{
public:
    spell_glubtok_generic_proc() : SpellScriptLoader("spell_glubtok_generic_proc") { }

    class spell_glubtok_generic_proc_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_glubtok_generic_proc_AuraScript);

        bool CheckProc(ProcEventInfo& /*eventInfo*/)
        {
            if (GetTarget()->GetSpellHistory()->HasCooldown(GetSpellInfo()->Id))
                return false;

            GetTarget()->GetSpellHistory()->AddCooldown(GetSpellInfo()->Id, 0, Seconds(4));
            return true;
        }

        void Register() override
        {
            DoCheckProc += AuraCheckProcFn(spell_glubtok_generic_proc_AuraScript::CheckProc);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_glubtok_generic_proc_AuraScript();
    }
};

class FirewallCooldownCheck
{
public:
    FirewallCooldownCheck() { }

    bool operator()(WorldObject* target)
    {
        if (target->ToUnit() && target->ToUnit()->GetSpellHistory()->HasCooldown(SPELL_FIRE_WALL_TRIGGERED))
            return true;

        if (target->ToUnit())
            target->ToUnit()->GetSpellHistory()->AddCooldown(SPELL_FIRE_WALL_TRIGGERED, 0, Seconds(1));
        return false;
    }
};

class spell_glubtok_firewall_targetting : public SpellScriptLoader
{
public:
    spell_glubtok_firewall_targetting() : SpellScriptLoader("spell_glubtok_firewall_targetting") { }

    class spell_glubtok_firewall_targetting_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_glubtok_firewall_targetting_SpellScript);

        void SelectTarget(std::list<WorldObject*>& targets)
        {
            targets.remove_if(FirewallCooldownCheck());
        }

        void Register() override
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_glubtok_firewall_targetting_SpellScript::SelectTarget, EFFECT_0, TARGET_UNIT_DEST_AREA_ENTRY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_glubtok_firewall_targetting_SpellScript();
    }
};


void AddSC_boss_glubtok()
{
    new boss_glubtok();
    new npc_glubtok_main_platter();
    new npc_glubtok_secondary_platter();
    new spell_glubtok_generic_proc();
    new spell_glubtok_firewall_targetting();
}
