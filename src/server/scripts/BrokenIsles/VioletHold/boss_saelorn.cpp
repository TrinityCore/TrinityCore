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
#include "ScriptedCreature.h"
#include "AreaTriggerTemplate.h"
#include "AreaTriggerAI.h"
#include "violet_hold_assault.h"

enum Spells
{
    SPELL_VENOM_SPRAY               = 202414,
    SPELL_WEB_GRAB                  = 202462,
    SPELL_FEL_DETONATION            = 202473,
    SPELL_TOXIC_BLOOD               = 210504,
    SPELL_TOXIC_BLOOD_DMG           = 210505,

    SPELL_CREEPING_SLAUGHTER        = 202306,
    SPELL_CREEPING_SLAUGHTER_STUN   = 202309,
};

enum Events
{
    EVENT_VENOM_SPRAY       = 1,
    EVENT_WEB_GRAB          = 2,
    EVENT_FEL_DETONATION    = 3,
    EVENT_TOXIC_BLOOD       = 4,
    EVENT_PHASE_SPIDER      = 5,

    // Phase Spider
    EVENT_FOLLOW_TARGET     = 6,
};

enum Adds
{
    NPC_PHASE_SPIDER    = 102434,
};

enum Says
{
    SAY_AGGRO               = 0,
    SAY_VENOM_SPRAY         = 1,
    SAY_WEB_GRAB            = 2,
    SAY_TOXIC_BLOOD         = 3,
    SAY_CREEPING_SLAUGHTER  = 4,
    SAY_SPIDER_KITING       = 5,
    SAY_HIT_SPIDER          = 6,
    SAY_KILL                = 7,
    SAY_DEATH               = 8,
};

enum Actions
{
    ACTION_FIND_NEW_TARGET = 1,
};

class boss_saelorn : public CreatureScript
{
    public:
        boss_saelorn() : CreatureScript("boss_saelorn")
        {}

        struct boss_saelorn_AI : public BossAI
        {
            boss_saelorn_AI(Creature* creature) : BossAI(creature, DATA_SAELORN)
            {}

            void Reset() override
            {
                _Reset();
            }

            void JustDied(Unit* /**/) override
            {
                Talk(SAY_DEATH);
                _JustDied();
            }

            void KilledUnit(Unit* victim) override
            {
                if (victim && victim->GetTypeId() == TYPEID_PLAYER)
                    Talk(SAY_KILL);
            }

            void EnterCombat(Unit* /**/) override
            {
                Talk(SAY_AGGRO);
                _EnterCombat();
                events.ScheduleEvent(EVENT_PHASE_SPIDER, Seconds(18));
                events.ScheduleEvent(EVENT_FEL_DETONATION, Seconds(20));
                events.ScheduleEvent(EVENT_WEB_GRAB, Seconds(15));
                events.ScheduleEvent(EVENT_VENOM_SPRAY, Seconds(6));

                if (IsHeroic())
                    events.ScheduleEvent(EVENT_TOXIC_BLOOD, Seconds(10));
            }

            void ExecuteEvent(uint32 eventId) override
            {
                switch (eventId)
                {
                    case EVENT_VENOM_SPRAY:
                    {
                        Talk(SAY_VENOM_SPRAY);
                        DoCastVictim(SPELL_VENOM_SPRAY);
                        events.ScheduleEvent(EVENT_VENOM_SPRAY, Seconds(20));
                        break;
                    }

                    case EVENT_WEB_GRAB:
                    {
                        Talk(SAY_WEB_GRAB);
                        DoCastVictim(SPELL_WEB_GRAB);
                        events.ScheduleEvent(EVENT_WEB_GRAB, Seconds(urand(30,40)));
                        break;
                    }

                    case EVENT_FEL_DETONATION:
                    {
                        DoCast(me, SPELL_FEL_DETONATION);
                        events.ScheduleEvent(EVENT_FEL_DETONATION, Seconds(30));
                        break;
                    }

                    case EVENT_TOXIC_BLOOD:
                    {
                        Talk(SAY_TOXIC_BLOOD);
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0, true))
                            DoCast(target, SPELL_TOXIC_BLOOD);
                        events.ScheduleEvent(EVENT_TOXIC_BLOOD, Seconds(15));
                        break;
                    }

                    case EVENT_PHASE_SPIDER:
                    {
                        Position pos = me->GetRandomNearPosition(30);
                        DoSummon(NPC_PHASE_SPIDER, pos, 0, TEMPSUMMON_MANUAL_DESPAWN);
                        events.ScheduleEvent(EVENT_PHASE_SPIDER, Seconds(15));
                        break;
                    }

                    default : break;
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new boss_saelorn_AI(creature);
        }
};

class npc_vha_phase_spider : public CreatureScript
{
    public:
        npc_vha_phase_spider() : CreatureScript("npc_vha_phase_spider")
        {}

        struct npc_vha_phase_spider_AI : public ScriptedAI
        {
            npc_vha_phase_spider_AI(Creature* creature) : ScriptedAI(creature)
            {
            }

            void DoAction(int32 action) override
            {
                if (action == ACTION_FIND_NEW_TARGET)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0, true))
                        DoCast(target, SPELL_CREEPING_SLAUGHTER);
                }
            }

            void IsSummonedBy(Unit* /**/) override
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0, true))
                    DoCast(target, SPELL_CREEPING_SLAUGHTER);
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_vha_phase_spider_AI(creature);
        }
};

class spell_vha_creeping_slaughter : public SpellScriptLoader
{
    public:
        spell_vha_creeping_slaughter() : SpellScriptLoader("spell_vha_creeping_slaughter")
        {}

        class spell_creeping_slaughter_AuraScript : public AuraScript
        {
            public:
                PrepareAuraScript(spell_creeping_slaughter_AuraScript);

                void HandleOnRemove(AuraEffect const* /**/, AuraEffectHandleModes /**/)
                {
                    if (!GetCaster() || !GetUnitOwner())
                        return;

                    GetCaster()->GetAI()->DoAction(ACTION_FIND_NEW_TARGET);
                }

                void HandlePeriodic(AuraEffect const* /**/)
                {
                    if (!GetUnitOwner() || !GetCaster())
                        return;

                    Unit* owner = GetUnitOwner();
                    Unit* caster = GetCaster();

                    if (owner->isInFront(caster, float(M_PI)/4.0f))
                    {
                        caster->GetMotionMaster()->Clear();
                        caster->StopMoving();
                    }
                    else
                    {
                        if (!caster->IsWithinMeleeRange(owner))
                            caster->GetMotionMaster()->MoveFollow(owner, 0, 0);
                        else
                            caster->GetAI()->AttackStart(owner);
                    }
                }

                void Register()
                {
                    OnEffectRemove += AuraEffectRemoveFn(spell_creeping_slaughter_AuraScript::HandleOnRemove, EFFECT_2, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
                    OnEffectPeriodic += AuraEffectPeriodicFn(spell_creeping_slaughter_AuraScript::HandlePeriodic, EFFECT_2, SPELL_AURA_PERIODIC_DUMMY);
                }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_creeping_slaughter_AuraScript();
        }
};

class spell_saelorn_toxic_blood : public SpellScriptLoader
{
    public:
        spell_saelorn_toxic_blood() : SpellScriptLoader("spell_saelorn_toxic_blood")
        {}

        class spell_saelorn_toxic_blood_AuraScript : public AuraScript
        {
            public:
                PrepareAuraScript(spell_saelorn_toxic_blood_AuraScript);

                void HandlePeriodic(AuraEffect const* /**/)
                {
                    if (!GetUnitOwner() || !GetCaster())
                        return;

                    GetCaster()->CastSpell(GetUnitOwner(), SPELL_TOXIC_BLOOD_DMG, true);
                }

                void Register() override
                {
                    OnEffectPeriodic += AuraEffectPeriodicFn(spell_saelorn_toxic_blood_AuraScript::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
                }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_saelorn_toxic_blood_AuraScript();
        }
};

void AddSC_boss_saelorn()
{
    new boss_saelorn();
    new npc_vha_phase_spider();
    new spell_vha_creeping_slaughter();
    new spell_saelorn_toxic_blood();
}
