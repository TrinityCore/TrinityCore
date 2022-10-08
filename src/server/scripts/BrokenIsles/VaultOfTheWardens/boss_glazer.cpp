/*
* Copyright (C) 2021 BfaCore Reforged
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
#include "vault_of_the_wardens.h"

enum Says
{
    SAY_AGGRO = 0,
    SAY_LINGERING = 1,
    SAY_ENERGIZE = 2,
    SAY_STOP_ENERGIZE = 3,
    //SAY_   = 4, That didn\'t look that close...
    SAY_PULSE = 5,
    //SAY_   = 6, |TInterface\\Icons\\Ability_Hunter_MasterMarksman:20|t%s starts |cFFFF0000|Hspell:194289|h[Focusing]|h|r a beam of energy, use the mirrors to redirect the beam to %s\'s back!
    SAY_DEATH = 7,
};

enum Spells
{
    SPELL_PULSE = 194849,
    SPELL_PULSE_AT = 194853,
    SPELL_LINGERING_GAZE = 194942,
    SPELL_TELEPORT_CENTR = 194149,
    SPELL_ENERGIZE = 193443,
    SPELL_FOCUSED = 194289,
    SPELL_FOCUSED_AURA = 194323,
    SPELL_BEAM_CHECK_BW = 194463,
    SPELL_BEAM_VIS_1 = 194261,
    SPELL_BEAM_VIS_2 = 201042,

    //Lens
    SPELL_ACTIVATE_GO = 197151,
    SPELL_DEACTIVATE_GO = 198165,
    SPELL_LENS_SPAWN_VIS = 203926, //Visual spawn
    SPELL_BEAM_VIS_3 = 193373,
    SPELL_BEAM_VIS_4 = 194333, //Target boss
    SPELL_BEAM_CHECK_PLR_1 = 194523,
    SPELL_BEAM_CHECK_PLR_2 = 194468,
    SPELL_BEAM_DMG = 202046,
};

enum eEvents
{
    EVENT_PULSE = 1,
    EVENT_LINGERING_GAZE = 2,
    EVENT_TELEPORT = 3,
    EVENT_ENERGIZE = 4,
    EVENT_FOCUSED = 5,
};

Position const beamPos[4] =
{
    //Version 1
    {4486.56f, -708.61f, 117.23f},
    {4507.93f, -669.62f, 117.54f},

    //Version 2
    {4451.38f, -628.36f, 117.81f},
    {4421.46f, -643.74f, 117.46f}
};

Position const lensPos[8] =
{
    //Version 1
    {4451.21f, -638.68f, 117.23f, 0.78f},
    {4433.92f, -655.97f, 117.23f, 2.35f},
    {4485.78f, -673.26f, 117.23f, 5.49f},

    //Version 2
    {4451.21f, -707.84f, 117.23f, 5.49f},
    {4468.50f, -690.55f, 117.23f, 0.78f},
    {4433.92f, -655.97f, 117.23f, 3.14f},
    {4442.56f, -699.19f, 117.23f, 1.26f},
    {4468.50f, -655.97f, 117.23f, 0.0f},
};

class boss_glazer : public CreatureScript
{
public:
    boss_glazer() : CreatureScript("boss_glazer") {}

    struct boss_glazerAI : public BossAI
    {
        boss_glazerAI(Creature* creature) : BossAI(creature, DATA_GLAZER), randLensPosition(0), lensMovePoint(0)
        {
        }

        uint8 randLensPosition;
        uint8 lensMovePoint;

        void Reset() override
        {
            _Reset();
            me->SetReactState(REACT_DEFENSIVE);
            me->SetControlled(0, UNIT_STATE_ROOT);
        }

        void EnterCombat(Unit* /*who*/) override
        {
            Talk(SAY_AGGRO);
            _EnterCombat();
            me->SetReactState(REACT_AGGRESSIVE);

            events.RescheduleEvent(EVENT_PULSE, 6000);
            events.RescheduleEvent(EVENT_LINGERING_GAZE, 12000);
            events.RescheduleEvent(EVENT_TELEPORT, 30000);
        }

        void JustDied(Unit* /*killer*/) override
        {
            _JustDied();
        }

        void SpellHit(Unit* caster, const SpellInfo* spell) override
        {
            switch (spell->Id)
            {
            case SPELL_TELEPORT_CENTR:
                events.RescheduleEvent(EVENT_ENERGIZE, 500);
                break;
            case SPELL_ENERGIZE:
                DoCast(me, SPELL_FOCUSED_AURA, true);
                events.RescheduleEvent(EVENT_FOCUSED, 500);
                break;
            case SPELL_BEAM_VIS_4:
            {
                Talk(SAY_STOP_ENERGIZE);
                me->InterruptNonMeleeSpells(false, SPELL_BEAM_VIS_2);
                me->RemoveAurasDueToSpell(SPELL_FOCUSED_AURA);
                me->SetReactState(REACT_AGGRESSIVE);
                me->SetControlled(0, UNIT_STATE_ROOT);
                EntryCheckPredicate pred(NPC_LENS);
                summons.DoAction(true, pred);
                events.RescheduleEvent(EVENT_TELEPORT, 30000);
                break;
            }
            }
        }

        void SpellHitTarget(Unit* target, const SpellInfo* spell) override
        {
            switch (spell->Id)
            {
            case SPELL_PULSE:
                me->SetFacingToObject(target);
                DoCast(me, SPELL_PULSE_AT, true);
                break;
            case SPELL_FOCUSED:
                me->SetFacingToObject(target);
                DoCast(target, SPELL_BEAM_VIS_2, true);
                me->SetControlled(1, UNIT_STATE_ROOT);
                if (target->GetEntry() == NPC_GLAZER_BEAM)
                    target->GetMotionMaster()->MovePoint(1, beamPos[lensMovePoint]);
                break;
            }
        }

        void SummonedCreatureDespawn(Creature* summon) override
        {
            summon->CastSpell(summon, SPELL_DEACTIVATE_GO, true);
        }

        void VariateLensPosition()
        {
            randLensPosition = urand(0, 1);

            switch (randLensPosition)
            {
            case 0:
            {
                for (uint8 i = 0; i < 3; i++)
                    me->SummonCreature(NPC_LENS, lensPos[i]);
                me->SummonCreature(NPC_GLAZER_BEAM, beamPos[0]);
                lensMovePoint = 1;
                break;
            }
            case 1:
            {
                for (uint8 i = 3; i < 8; i++)
                    me->SummonCreature(NPC_LENS, lensPos[i]);
                me->SummonCreature(NPC_GLAZER_BEAM, beamPos[2]);
                lensMovePoint = 3;
                break;
            }
            default:
                break;
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            //if (CheckHomeDistToEvade(diff, 32.0f))
              //  return;

            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_PULSE:
                    Talk(SAY_PULSE);
                    DoCast(SPELL_PULSE);
                    events.RescheduleEvent(EVENT_PULSE, 12000);
                    break;
                case EVENT_LINGERING_GAZE:
                    Talk(SAY_LINGERING);
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 60.0f, true))
                        DoCast(target, SPELL_LINGERING_GAZE);
                    events.RescheduleEvent(EVENT_LINGERING_GAZE, 18000);
                    break;
                case EVENT_TELEPORT:
                    me->SetReactState(REACT_PASSIVE);
                    DoCast(SPELL_TELEPORT_CENTR);
                    break;
                case EVENT_ENERGIZE:
                    Talk(SAY_ENERGIZE);
                    DoCast(SPELL_ENERGIZE);
                    break;
                case EVENT_FOCUSED:
                    VariateLensPosition();
                    DoCast(SPELL_FOCUSED);
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_glazerAI(creature);
    }
};

//102310
class npc_glazer_beam : public CreatureScript
{
public:
    npc_glazer_beam() : CreatureScript("npc_glazer_beam") {}

    struct npc_glazer_beamAI : public ScriptedAI
    {
        npc_glazer_beamAI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetReactState(REACT_PASSIVE);
            me->SetDisplayId(11686);
        }

        void Reset() override {}

        void MovementInform(uint32 type, uint32 id) override
        {
            if (type != POINT_MOTION_TYPE)
                return;

            if (me->GetOwner())
                if (Creature* summoner = me->GetOwner()->ToCreature())
                {
                    summoner->InterruptNonMeleeSpells(false, SPELL_FOCUSED);
                    summoner->InterruptNonMeleeSpells(false, SPELL_BEAM_VIS_2);
                    if (Creature* lens = me->FindNearestCreature(NPC_LENS, 25.0f))
                        summoner->CastSpell(lens, SPELL_BEAM_VIS_2, true);
                }

            me->DespawnOrUnsummon();
        }

        void UpdateAI(uint32 diff) override {}
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_glazer_beamAI(creature);
    }
};

//98082
class npc_glazer_lens : public CreatureScript
{
public:
    npc_glazer_lens() : CreatureScript("npc_glazer_lens") {}

    struct npc_glazer_lensAI : public ScriptedAI
    {
        npc_glazer_lensAI(Creature* creature) : ScriptedAI(creature), target(nullptr)
        {
            me->SetReactState(REACT_PASSIVE);
            me->SetDisplayId(11686);
        }

        EventMap events;
        Unit* target;

        void Reset() override {}

        void IsSummonedBy(Unit* summoner) override
        {
            events.RescheduleEvent(1, 500);
            events.RescheduleEvent(2, 1000);
            events.RescheduleEvent(3, 3000);
        }

        void DoAction(int32 const action) override
        {
            InterruptBeam();
            me->RemoveAurasDueToSpell(SPELL_LENS_SPAWN_VIS);
            me->DespawnOrUnsummon(2000);
        }

     /*   void OnSpellClick(Unit* clicker) override
        {
            InterruptBeam();
            me->SetFacingTo(me->GetOrientation() - 1.57f);
        }
        */
        void InterruptBeam()
        {
            me->InterruptNonMeleeSpells(false, SPELL_BEAM_VIS_3);
            me->InterruptNonMeleeSpells(false, SPELL_BEAM_VIS_4);
        }

        void SearchBeamTarget()
        {
            if (!me->HasAura(SPELL_BEAM_VIS_2) && !me->HasAura(SPELL_BEAM_VIS_3))
            {
                InterruptBeam();
                return;
            }

            target = nullptr;

            std::list<Creature*> creatureList;
            me->GetCreatureListWithEntryInGrid(creatureList, NPC_BEAM_TARGET_TRIGGER, 100.0f);
            me->GetCreatureListWithEntryInGrid(creatureList, NPC_LENS, 100.0f);
            me->GetCreatureListWithEntryInGrid(creatureList, NPC_GLAZER, 100.0f);

            if (creatureList.empty())
                return;

            for (auto creature : creatureList)
            {
                if (me->isInFront(creature, 0.1f))
                {
                    if (creature->GetGUID() == me->GetGUID())
                        continue;

                    if (target)
                    {
                        if (me->GetDistance(target) < me->GetDistance(creature))
                            continue;
                    }

                    target = creature;
                }
            }
            if (target)
            {
                if (target->HasAura(SPELL_BEAM_VIS_2) || target->HasAura(SPELL_BEAM_VIS_3) || target->HasAura(SPELL_BEAM_VIS_4))
                    return;

                if (target->GetEntry() != NPC_GLAZER)
                {
                    DoCast(target, SPELL_BEAM_VIS_3, true);
                }
                else
                    DoCast(target, SPELL_BEAM_VIS_4, true);
            }
        }

        void UpdateAI(uint32 diff) override
        {
            events.Update(diff);

            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case 1:
                    DoCast(me, SPELL_ACTIVATE_GO, true);
                    break;
                case 2:
                    DoCast(me, SPELL_LENS_SPAWN_VIS, true);
                    break;
                case 3:
                    SearchBeamTarget();
                    events.RescheduleEvent(3, 1000);
                    break;
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_glazer_lensAI(creature);
    }
};

//194463, 194468
class spell_glazer_beam : public SpellScriptLoader
{
public:
    spell_glazer_beam() : SpellScriptLoader("spell_glazer_beam") { }

    class spell_glazer_beam_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_glazer_beam_SpellScript);

        void HandleOnHit()
        {
            if (!GetCaster() || !GetHitUnit() || GetCaster()->GetTypeId() != TYPEID_PLAYER)
                return;

            GetCaster()->CastSpell(GetHitUnit(), SPELL_BEAM_DMG, true);
        }

        void Register() override
        {
            OnHit += SpellHitFn(spell_glazer_beam_SpellScript::HandleOnHit);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_glazer_beam_SpellScript();
    }
};

//195032
class spell_glazer_radiation : public SpellScriptLoader
{
public:
    spell_glazer_radiation() : SpellScriptLoader("spell_glazer_radiation") { }

    class spell_glazer_radiation_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_glazer_radiation_SpellScript);

        uint8 stack = 0;
        int32 damage = 0;

        void RecalculateDamage()
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            if (Aura* aura = caster->GetAura(195034))
               // stack = aura->GetStackAmount();

            damage = CalculatePct(GetHitDamage(), stack);
            SetHitDamage(GetHitDamage() + damage);
        }

        void Register() override
        {
            OnHit += SpellHitFn(spell_glazer_radiation_SpellScript::RecalculateDamage);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_glazer_radiation_SpellScript();
    }
};

void AddSC_boss_glazer()
{
    new boss_glazer();
    new npc_glazer_beam();
    new npc_glazer_lens();
    new spell_glazer_beam();
    new spell_glazer_radiation();
}
