/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "drak_tharon_keep.h"

enum Spells
{
    SPELL_INFECTED_WOUND                = 49637,
    SPELL_CRUSH                         = 49639,
    SPELL_CORPSE_EXPLODE                = 49555,
    SPELL_CORPSE_EXPLODE_DAMAGE         = 49618,
    SPELL_CONSUME                       = 49380,
    SPELL_CONSUME_BUFF                  = 49381,
    SPELL_CONSUME_BUFF_H                = 59805,

    SPELL_SUMMON_INVADER_A              = 49456,
    SPELL_SUMMON_INVADER_B              = 49457,
    SPELL_SUMMON_INVADER_C              = 49458, // can't find any sniffs

    SPELL_INVADER_TAUNT                 = 49405
};

#define SPELL_CONSUME_BUFF_HELPER DUNGEON_MODE<uint32>(SPELL_CONSUME_BUFF, SPELL_CONSUME_BUFF_H)

enum Yells
{
    SAY_AGGRO                           = 0,
    SAY_KILL                            = 1,
    SAY_CONSUME                         = 2,
    SAY_EXPLODE                         = 3,
    SAY_DEATH                           = 4
};

enum Misc
{
    DATA_CONSUMPTION_JUNCTION           = 1,
    POINT_LANDING                       = 1
};

enum Events
{
    EVENT_CONSUME = 1,
    EVENT_CRUSH,
    EVENT_INFECTED_WOUND,
    EVENT_CORPSE_EXPLODE,
    EVENT_SPAWN
};

Position const Landing = { -263.0534f, -660.8658f, 26.50903f, 0.0f };

class boss_trollgore : public CreatureScript
{
    public:
        boss_trollgore() : CreatureScript("boss_trollgore") { }

        struct boss_trollgoreAI : public BossAI
        {
            boss_trollgoreAI(Creature* creature) : BossAI(creature, DATA_TROLLGORE)
            {
                Initialize();
            }

            void Initialize()
            {
                _consumptionJunction = true;
            }

            void Reset() override
            {
                _Reset();
                Initialize();
            }

            void EnterCombat(Unit* /*who*/) override
            {
                _EnterCombat();
                Talk(SAY_AGGRO);

                events.ScheduleEvent(EVENT_CONSUME, 15000);
                events.ScheduleEvent(EVENT_CRUSH, urand(1000, 5000));
                events.ScheduleEvent(EVENT_INFECTED_WOUND, urand(10000, 60000));
                events.ScheduleEvent(EVENT_CORPSE_EXPLODE, 3000);
                events.ScheduleEvent(EVENT_SPAWN, urand(30000, 40000));
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
                        case EVENT_CONSUME:
                            Talk(SAY_CONSUME);
                            DoCastAOE(SPELL_CONSUME);
                            events.ScheduleEvent(EVENT_CONSUME, 15000);
                            break;
                        case EVENT_CRUSH:
                            DoCastVictim(SPELL_CRUSH);
                            events.ScheduleEvent(EVENT_CRUSH, urand(10000, 15000));
                            break;
                        case EVENT_INFECTED_WOUND:
                            DoCastVictim(SPELL_INFECTED_WOUND);
                            events.ScheduleEvent(EVENT_INFECTED_WOUND, urand(25000, 35000));
                            break;
                        case EVENT_CORPSE_EXPLODE:
                            Talk(SAY_EXPLODE);
                            DoCastAOE(SPELL_CORPSE_EXPLODE);
                            events.ScheduleEvent(EVENT_CORPSE_EXPLODE, urand(15000, 19000));
                            break;
                        case EVENT_SPAWN:
                            for (uint8 i = 0; i < 3; ++i)
                                if (Creature* trigger = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_TROLLGORE_INVADER_SUMMONER_1 + i)))
                                    trigger->CastSpell(trigger, RAND(SPELL_SUMMON_INVADER_A, SPELL_SUMMON_INVADER_B, SPELL_SUMMON_INVADER_C), true, NULL, NULL, me->GetGUID());

                            events.ScheduleEvent(EVENT_SPAWN, urand(30000, 40000));
                            break;
                        default:
                            break;
                    }
                }

                if (_consumptionJunction)
                {
                    Aura* ConsumeAura = me->GetAura(SPELL_CONSUME_BUFF_HELPER);
                    if (ConsumeAura && ConsumeAura->GetStackAmount() > 9)
                        _consumptionJunction = false;
                }

                DoMeleeAttackIfReady();
            }

            void JustDied(Unit* /*killer*/) override
            {
                _JustDied();
                Talk(SAY_DEATH);
            }

            uint32 GetData(uint32 type) const override
            {
                if (type == DATA_CONSUMPTION_JUNCTION)
                    return _consumptionJunction ? 1 : 0;

                return 0;
            }

            void KilledUnit(Unit* victim) override
            {
                if (victim->GetTypeId() != TYPEID_PLAYER)
                    return;

                Talk(SAY_KILL);
            }

            void JustSummoned(Creature* summon) override
            {
                summon->GetMotionMaster()->MovePoint(POINT_LANDING, Landing);
                summons.Summon(summon);
            }

            private:
                bool _consumptionJunction;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetDrakTharonKeepAI<boss_trollgoreAI>(creature);
        }
};

class npc_drakkari_invader : public CreatureScript
{
    public:
        npc_drakkari_invader() : CreatureScript("npc_drakkari_invader") { }

        struct npc_drakkari_invaderAI : public ScriptedAI
        {
            npc_drakkari_invaderAI(Creature* creature) : ScriptedAI(creature) { }

            void MovementInform(uint32 type, uint32 pointId) override
            {
                if (type == POINT_MOTION_TYPE && pointId == POINT_LANDING)
                {
                    me->Dismount();
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC);
                    DoCastAOE(SPELL_INVADER_TAUNT);
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetDrakTharonKeepAI<npc_drakkari_invaderAI>(creature);
        }
};

// 49380, 59803 - Consume
class spell_trollgore_consume : public SpellScriptLoader
{
    public:
        spell_trollgore_consume() : SpellScriptLoader("spell_trollgore_consume") { }

        class spell_trollgore_consume_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_trollgore_consume_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_CONSUME_BUFF))
                    return false;
                return true;
            }

            void HandleConsume(SpellEffIndex /*effIndex*/)
            {
                if (Unit* target = GetHitUnit())
                    target->CastSpell(GetCaster(), SPELL_CONSUME_BUFF, true);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_trollgore_consume_SpellScript::HandleConsume, EFFECT_1, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_trollgore_consume_SpellScript();
        }
};

// 49555, 59807 - Corpse Explode
class spell_trollgore_corpse_explode : public SpellScriptLoader
{
    public:
        spell_trollgore_corpse_explode() : SpellScriptLoader("spell_trollgore_corpse_explode") { }

        class spell_trollgore_corpse_explode_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_trollgore_corpse_explode_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_CORPSE_EXPLODE_DAMAGE))
                    return false;
                return true;
            }

            void PeriodicTick(AuraEffect const* aurEff)
            {
                if (aurEff->GetTickNumber() == 2)
                    if (Unit* caster = GetCaster())
                        caster->CastSpell(GetTarget(), SPELL_CORPSE_EXPLODE_DAMAGE, true, NULL, aurEff);
            }

            void HandleRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (Creature* target = GetTarget()->ToCreature())
                    target->DespawnOrUnsummon();
            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_trollgore_corpse_explode_AuraScript::PeriodicTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
                AfterEffectRemove += AuraEffectRemoveFn(spell_trollgore_corpse_explode_AuraScript::HandleRemove, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_trollgore_corpse_explode_AuraScript();
        }
};

// 49405 - Invader Taunt Trigger
class spell_trollgore_invader_taunt : public SpellScriptLoader
{
    public:
        spell_trollgore_invader_taunt() : SpellScriptLoader("spell_trollgore_invader_taunt") { }

        class spell_trollgore_invader_taunt_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_trollgore_invader_taunt_SpellScript);

            bool Validate(SpellInfo const* spellInfo) override
            {
                if (!sSpellMgr->GetSpellInfo(spellInfo->Effects[EFFECT_0].CalcValue()))
                    return false;
                return true;
            }

            void HandleTaunt(SpellEffIndex /*effIndex*/)
            {
                if (Unit* target = GetHitUnit())
                    target->CastSpell(GetCaster(), uint32(GetEffectValue()), true);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_trollgore_invader_taunt_SpellScript::HandleTaunt, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_trollgore_invader_taunt_SpellScript();
        }
};

class achievement_consumption_junction : public AchievementCriteriaScript
{
    public:
        achievement_consumption_junction() : AchievementCriteriaScript("achievement_consumption_junction")
        {
        }

        bool OnCheck(Player* /*player*/, Unit* target) override
        {
            if (!target)
                return false;

            if (Creature* Trollgore = target->ToCreature())
                if (Trollgore->AI()->GetData(DATA_CONSUMPTION_JUNCTION))
                    return true;

            return false;
        }
};

void AddSC_boss_trollgore()
{
    new boss_trollgore();
    new npc_drakkari_invader();
    new spell_trollgore_consume();
    new spell_trollgore_corpse_explode();
    new spell_trollgore_invader_taunt();
    new achievement_consumption_junction();
}
