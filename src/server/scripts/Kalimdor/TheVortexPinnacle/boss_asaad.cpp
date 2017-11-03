/*
* Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
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
#include"the_vortex_pinnacle.h"
#include "ObjectMgr.h"

enum ScriptTexts
{
    SAY_AGGRO   = 0,
    SAY_KILL    = 1,
    SAY_SPELL   = 2,
    SAY_DEATH   = 3,
};

enum Spells
{
    SPELL_CHAIN_LIGHTNING                       = 87622,
    SPELL_CHAIN_LIGHTNING_H                     = 93993,
    SPELL_UNSTABLE_GROUNDING_FIELD              = 86911,
    SPELL_GROUNDING_FIELD_VISUAL_BEAMS          = 87517,

    SPELL_SUPREMACY_OF_THE_STORM                = 86930,

    SPELL_SUPREMACY_OF_THE_STORM_DUMMY          = 86715,
    SPELL_SUPREMACY_OF_THE_STORM_DMG            = 87553,
    SPELL_SUPREMACY_OF_THE_STORM_DMG_H          = 93994,

    SPELL_SUPREMACY_OF_THE_STORM_DUMMY_1        = 87521,
    SPELL_SUPREMACY_OF_THE_STORM_SUM            = 87518,
    SPELL_SUPREMACY_OF_THE_STORM_TELE           = 87328,

    SPELL_STATIC_CLING                          = 87618,
};

enum Events
{
    EVENT_FIELD             = 1,
    EVENT_FIELD_1           = 2,
    EVENT_FIELD_2           = 3,
    EVENT_FIELD_3           = 4,
    EVENT_FIELD_4           = 5,
    EVENT_FIELD_5           = 6,
    EVENT_FIELD_6           = 7,
    EVENT_CHAIN_LIGHTNING   = 8,
    EVENT_STATIC_CLING      = 9,
    EVENT_SUMMON_STAR       = 10,
};

enum Adds
{
    NPC_UNSTABLE_GROUNDING_FIELD    = 46492,
    NPC_SKYFALL_STAR                = 52019,
    NPC_STORM_TARGET                = 46387,
    NPC_GROUNDING_FIELD             = 47000,
};

const Position fieldPos[4]    =
{
    {-644.20f, 489.00f, 646.63f, 0.0f },
    {-638.38f, 480.68f, 646.63f, 0.0f },
    {-635.43f, 492.11f, 646.63f, 0.0f },
    {-639.23f, 488.13f, 656.63f, 0.0f },
};

const Position starPos[6] =
{
    {-583.77f, 516.56f, 649.51f, 5.65f },
    {-591.65f, 476.39f, 649.19f, 4.39f },
    {-617.69f, 544.79f, 650.12f, 0.11f },
    {-652.62f, 532.48f, 649.03f, 1.53f },
    {-618.65f, 463.05f, 650.63f, 0.0f  },
    {-649.24f, 474.11f, 649.63f, 0.0f  },
};

class boss_asaad : public CreatureScript
{
    public:
        boss_asaad() : CreatureScript("boss_asaad") { }

        CreatureAI* GetAI(Creature* pCreature) const override
        {
            return new boss_asaadAI(pCreature);
        }
        struct boss_asaadAI : public BossAI
        {
            boss_asaadAI(Creature* pCreature) : BossAI(pCreature, DATA_ASAAD)
            {
                me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_STUN, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FEAR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_ROOT, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FREEZE, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_POLYMORPH, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_HORROR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SAPPED, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_CHARM, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISORIENTED, true);
                me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_CONFUSE, true);
                me->setActive(true);
            }

            bool bField;
            ObjectGuid _field1;
            ObjectGuid _field2;
            ObjectGuid _field3;

            void InitializeAI() override
            {
                if (!instance || static_cast<InstanceMap*>(me->GetMap())->GetScriptId() != sObjectMgr->GetScriptId(VPScriptName))
                    me->IsAIEnabled = false;
                else if (!me->isDead())
                    Reset();
            }

            void Reset() override
            {
                _Reset();
                me->SetCanFly(false);
                bField = false;
            }

            void EnterCombat(Unit* /*pWho*/) override
            {
                events.ScheduleEvent(EVENT_SUMMON_STAR, urand(10000, 20000));
                events.ScheduleEvent(EVENT_CHAIN_LIGHTNING, urand(5000, 10000));
                events.ScheduleEvent(EVENT_FIELD, 45000);
                if (IsHeroic())
                    events.ScheduleEvent(EVENT_STATIC_CLING, urand(12000, 18000));
                Talk(SAY_AGGRO);
                bField = false;
                DoZoneInCombat();
                instance->SetBossState(DATA_ASAAD, IN_PROGRESS);
            }

            void KilledUnit(Unit* /*killer*/) override
            {
                Talk(SAY_KILL);
            }

            void JustDied(Unit* /*pWho*/) override
            {
                _JustDied();
                me->SetCanFly(false);
                Talk(SAY_DEATH);
            }


            void UpdateAI(const uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING) && !bField)
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_CHAIN_LIGHTNING:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                                DoCast(target, SPELL_CHAIN_LIGHTNING);
                            events.ScheduleEvent(EVENT_CHAIN_LIGHTNING, urand(15000, 20000));
                            break;
                        case EVENT_SUMMON_STAR:
                            me->SummonCreature(NPC_SKYFALL_STAR, starPos[urand(0, 5)]);
                            events.ScheduleEvent(EVENT_SUMMON_STAR, urand(24000, 30000));
                            break;
                        case EVENT_STATIC_CLING:
                            DoCast(SPELL_STATIC_CLING);
                            events.ScheduleEvent(EVENT_STATIC_CLING, urand(20000, 23000));
                            break;
                        case EVENT_FIELD:
                            bField = true;
                            events.CancelEvent(EVENT_CHAIN_LIGHTNING);
                            events.CancelEvent(EVENT_STATIC_CLING);
                            events.CancelEvent(EVENT_SUMMON_STAR);
                            me->InterruptNonMeleeSpells(false);
                            Talk(SAY_SPELL);
                            me->AttackStop();
                            me->SetReactState(REACT_PASSIVE);
                            if (Creature*c  = me->SummonCreature(NPC_UNSTABLE_GROUNDING_FIELD, fieldPos[0]))
                            {
                                _field1 = c->GetGUID();
                                DoCast(c, SPELL_UNSTABLE_GROUNDING_FIELD);
                            }
                            events.ScheduleEvent(EVENT_FIELD_4, 20000);
                            events.ScheduleEvent(EVENT_FIELD_1, 6000);
                            break;
                        case EVENT_FIELD_1:
                            if (Creature*c = me->SummonCreature(NPC_UNSTABLE_GROUNDING_FIELD, fieldPos[1]))
                            {
                                _field2 = c->GetGUID();

                                if (Creature*c2 = me->GetMap()->GetCreature(_field1))
                                    c2->CastSpell(c, SPELL_UNSTABLE_GROUNDING_FIELD, true);
                            }
                            events.ScheduleEvent(EVENT_FIELD_2, 6000);
                            break;
                        case EVENT_FIELD_2:
                            if (Creature*c = me->SummonCreature(NPC_UNSTABLE_GROUNDING_FIELD, fieldPos[2]))
                            {
                                _field3 = c->GetGUID();
                                if (Creature* c2 = me->GetMap()->GetCreature(_field2))
                                    c2->CastSpell(c, SPELL_UNSTABLE_GROUNDING_FIELD, true);
                            }
                            events.ScheduleEvent(EVENT_FIELD_3, 6000);
                            break;
                        case EVENT_FIELD_3:
                        {
                            Creature* c1 = me->GetMap()->GetCreature(_field1);
                            Creature* c2 = me->GetMap()->GetCreature(_field3);
                            if (c1 && c2)
                                c2->CastSpell(c1, SPELL_UNSTABLE_GROUNDING_FIELD, true);

                            break;
                        }
                        case EVENT_FIELD_4:
                            me->SetCanFly(true);
                            me->SetDisableGravity(true);
                            me->NearTeleportTo(
                                fieldPos[3].GetPositionX(),
                                fieldPos[3].GetPositionY(),
                                fieldPos[3].GetPositionZ(),
                                0.0f);
                            events.ScheduleEvent(EVENT_FIELD_5, 800);
                            break;
                        case EVENT_FIELD_5:
                            DoCast(SPELL_SUPREMACY_OF_THE_STORM);
                            events.ScheduleEvent(EVENT_FIELD_6, 6000);
                            break;
                        case EVENT_FIELD_6:
                            if (Creature* c = me->GetMap()->GetCreature(_field1))
                                c->DespawnOrUnsummon();
                            if (Creature* c = me->GetMap()->GetCreature(_field2))
                                c->DespawnOrUnsummon();
                            if (Creature* c = me->GetMap()->GetCreature(_field3))
                                c->DespawnOrUnsummon();
                            bField = false;
                            me->SetCanFly(false);
                            me->SetDisableGravity(false);
                            me->SetReactState(REACT_AGGRESSIVE);
                            AttackStart(me->GetVictim());
                            events.ScheduleEvent(EVENT_FIELD, 45000);
                            events.ScheduleEvent(EVENT_SUMMON_STAR, urand(10000, 20000));
                            events.ScheduleEvent(EVENT_CHAIN_LIGHTNING, urand(5000, 10000));
                            if (IsHeroic())
                                events.ScheduleEvent(EVENT_STATIC_CLING, urand(12000, 18000));
                            break;
                        }
                }

                DoMeleeAttackIfReady();
            }
        };
};

class npc_unstable_grounding_field : public CreatureScript
{
    public:
        npc_unstable_grounding_field() : CreatureScript("npc_unstable_grounding_field") { }

        CreatureAI* GetAI(Creature* pCreature) const override
        {
            return new npc_unstable_grounding_fieldAI(pCreature);
        }
        struct npc_unstable_grounding_fieldAI : public Scripted_NoMovementAI
        {
            npc_unstable_grounding_fieldAI(Creature* pCreature) : Scripted_NoMovementAI(pCreature)
            {
                me->SetReactState(REACT_PASSIVE);
            }

            void Reset() override
            {
            }

            void UpdateAI(const uint32 /*diff*/) override
            {
            }
     };
};

class spell_asaad_supremacy_of_the_storm: public SpellScriptLoader
{
    public:
        spell_asaad_supremacy_of_the_storm() : SpellScriptLoader("spell_asaad_supremacy_of_the_storm") { }


        class spell_asaad_supremacy_of_the_storm_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_asaad_supremacy_of_the_storm_SpellScript);


            void HandleScript(SpellMissInfo /*missInfo*/)
            {
                if (!GetCaster() || !GetHitUnit())
                    return;

                if (GetCaster()->GetDistance2d(GetHitUnit()) < 5.0f)
                    SetHitDamage(0);
            }

            void Register() override
            {
                BeforeHit += BeforeSpellHitFn(spell_asaad_supremacy_of_the_storm_SpellScript::HandleScript);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_asaad_supremacy_of_the_storm_SpellScript();
        }
};

void AddSC_boss_asaad()
{
    new boss_asaad();
    new npc_unstable_grounding_field();
    new spell_asaad_supremacy_of_the_storm();
}
