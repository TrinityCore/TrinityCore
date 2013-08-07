/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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

/*
 * Comment: @todo spawn troll waves
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
    //SPELL_SUMMON_INVADER_C              = 49458, // can't find any sniffs

    H_SPELL_CORPSE_EXPLODE              = 59807,
    H_SPELL_CONSUME                     = 59803,
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
    DATA_CONSUMPTION_JUNCTION           = 1
};

Position AddSpawnPoint = { -260.493011f, -622.968018f, 26.605301f, 3.036870f };

class boss_trollgore : public CreatureScript
{
public:
    boss_trollgore() : CreatureScript("boss_trollgore") { }

    struct boss_trollgoreAI : public ScriptedAI
    {
        boss_trollgoreAI(Creature* creature) : ScriptedAI(creature), lSummons(me)
        {
            instance = creature->GetInstanceScript();
        }

        uint32 uiConsumeTimer;
        uint32 uiAuraCountTimer;
        uint32 uiCrushTimer;
        uint32 uiInfectedWoundTimer;
        uint32 uiExplodeCorpseTimer;
        uint32 uiSpawnTimer;

        bool consumptionJunction;

        SummonList lSummons;

        InstanceScript* instance;

        void Reset() OVERRIDE
        {
            uiConsumeTimer = 15*IN_MILLISECONDS;
            uiAuraCountTimer = 15500;
            uiCrushTimer = urand(1*IN_MILLISECONDS, 5*IN_MILLISECONDS);
            uiInfectedWoundTimer = urand(10*IN_MILLISECONDS, 60*IN_MILLISECONDS);
            uiExplodeCorpseTimer = 3*IN_MILLISECONDS;
            uiSpawnTimer = urand(30*IN_MILLISECONDS, 40*IN_MILLISECONDS);

            consumptionJunction = true;

            lSummons.DespawnAll();

            me->RemoveAura(SPELL_CONSUME_BUFF_HELPER);

            instance->SetBossState(DATA_TROLLGORE, NOT_STARTED);
        }

        void EnterCombat(Unit* /*who*/) OVERRIDE
        {
            Talk(SAY_AGGRO);
            instance->SetBossState(DATA_TROLLGORE, IN_PROGRESS);
        }

        void UpdateAI(uint32 diff) OVERRIDE
        {
            //Return since we have no target
            if (!UpdateVictim())
                return;

            if (uiSpawnTimer <= diff)
            {
                uint32 spawnNumber = urand(2, DUNGEON_MODE(3, 5));
                for (uint8 i = 0; i < spawnNumber; ++i)
                    DoSummon(RAND(NPC_DRAKKARI_INVADER_A, NPC_DRAKKARI_INVADER_B), AddSpawnPoint, 0, TEMPSUMMON_DEAD_DESPAWN);
                uiSpawnTimer = urand(30*IN_MILLISECONDS, 40*IN_MILLISECONDS);
            } else uiSpawnTimer -= diff;

            if (uiConsumeTimer <= diff)
            {
                Talk(SAY_CONSUME);
                DoCast(SPELL_CONSUME);
                uiConsumeTimer = 15*IN_MILLISECONDS;
            } else uiConsumeTimer -= diff;

            if (consumptionJunction)
            {
                Aura* ConsumeAura = me->GetAura(SPELL_CONSUME_BUFF_HELPER);
                if (ConsumeAura && ConsumeAura->GetStackAmount() > 9)
                    consumptionJunction = false;
            }

            if (uiCrushTimer <= diff)
            {
                DoCastVictim(SPELL_CRUSH);
                uiCrushTimer = urand(10*IN_MILLISECONDS, 15*IN_MILLISECONDS);
            } else uiCrushTimer -= diff;

            if (uiInfectedWoundTimer <= diff)
            {
                DoCastVictim(SPELL_INFECTED_WOUND);
                uiInfectedWoundTimer = urand(25*IN_MILLISECONDS, 35*IN_MILLISECONDS);
            } else uiInfectedWoundTimer -= diff;

            if (uiExplodeCorpseTimer <= diff)
            {
                DoCast(SPELL_CORPSE_EXPLODE);
                Talk(SAY_EXPLODE);
                uiExplodeCorpseTimer = urand(15*IN_MILLISECONDS, 19*IN_MILLISECONDS);
            } else uiExplodeCorpseTimer -= diff;

            DoMeleeAttackIfReady();
        }

        void JustDied(Unit* /*killer*/) OVERRIDE
        {
            Talk(SAY_DEATH);

            lSummons.DespawnAll();

            instance->SetBossState(DATA_TROLLGORE, DONE);
        }

        uint32 GetData(uint32 type) const OVERRIDE
        {
            if (type == DATA_CONSUMPTION_JUNCTION)
                return consumptionJunction ? 1 : 0;

            return 0;
        }

        void KilledUnit(Unit* victim) OVERRIDE
        {
            if (victim->GetTypeId() != TYPEID_PLAYER)
                return;

            Talk(SAY_KILL);
        }

        void JustSummoned(Creature* summon) OVERRIDE
        {
            lSummons.Summon(summon);
            if (summon->AI())
                summon->AI()->AttackStart(me);
        }
    };

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return GetDrakTharonKeepAI<boss_trollgoreAI>(creature);
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

            bool Validate(SpellInfo const* /*spellInfo*/) OVERRIDE
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

            void Register() OVERRIDE
            {
                OnEffectHitTarget += SpellEffectFn(spell_trollgore_consume_SpellScript::HandleConsume, EFFECT_1, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const OVERRIDE
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

            bool Validate(SpellInfo const* /*spellInfo*/) OVERRIDE
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

            void Register() OVERRIDE
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_trollgore_corpse_explode_AuraScript::PeriodicTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
                AfterEffectRemove += AuraEffectRemoveFn(spell_trollgore_corpse_explode_AuraScript::HandleRemove, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const OVERRIDE
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

            bool Validate(SpellInfo const* spellInfo) OVERRIDE
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

            void Register() OVERRIDE
            {
                OnEffectHitTarget += SpellEffectFn(spell_trollgore_invader_taunt_SpellScript::HandleTaunt, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const OVERRIDE
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

        bool OnCheck(Player* /*player*/, Unit* target) OVERRIDE
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
    new spell_trollgore_consume();
    new spell_trollgore_corpse_explode();
    new spell_trollgore_invader_taunt();
    new achievement_consumption_junction();
}
