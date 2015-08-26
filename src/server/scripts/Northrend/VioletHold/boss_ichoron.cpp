/*
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
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
#include "SpellAuraEffects.h"
#include "SpellScript.h"
#include "violet_hold.h"

enum Spells
{
    SPELL_WATER_BLAST                           = 54237,
    SPELL_WATER_BOLT_VOLLEY                     = 54241,
    SPELL_SPLATTER                              = 54259,
    SPELL_PROTECTIVE_BUBBLE                     = 54306,
    SPELL_FRENZY                                = 54312,
    SPELL_BURST                                 = 54379,
    SPELL_DRAINED                               = 59820,
    SPELL_THREAT_PROC                           = 61732,
    SPELL_SHRINK                                = 54297,

    SPELL_WATER_GLOBULE_SUMMON_1                = 54258,
    SPELL_WATER_GLOBULE_SUMMON_2                = 54264,
    SPELL_WATER_GLOBULE_SUMMON_3                = 54265,
    SPELL_WATER_GLOBULE_SUMMON_4                = 54266,
    SPELL_WATER_GLOBULE_SUMMON_5                = 54267,
    SPELL_WATER_GLOBULE_TRANSFORM               = 54268,
    SPELL_WATER_GLOBULE_VISUAL                  = 54260,

    SPELL_MERGE                                 = 54269,
    SPELL_SPLASH                                = 59516
};

enum Yells
{
    SAY_AGGRO                                   = 0,
    SAY_SLAY                                    = 1,
    SAY_DEATH                                   = 2,
    SAY_SPAWN                                   = 3,
    SAY_ENRAGE                                  = 4,
    SAY_SHATTER                                 = 5,
    SAY_BUBBLE                                  = 6,
    EMOTE_SHATTER                               = 7
};

enum Actions
{
    ACTION_WATER_GLOBULE_HIT                    = 1,
    ACTION_PROTECTIVE_BUBBLE_SHATTERED          = 2,
    ACTION_DRAINED                              = 3
};

enum Misc
{
    DATA_DEHYDRATION                            = 1
};

class boss_ichoron : public CreatureScript
{
    public:
        boss_ichoron() : CreatureScript("boss_ichoron") { }

        struct boss_ichoronAI : public BossAI
        {
            boss_ichoronAI(Creature* creature) : BossAI(creature, DATA_ICHORON)
            {
                Initialize();

                /// for some reason ichoron can't walk back to it's water basin on evade
                me->AddUnitState(UNIT_STATE_IGNORE_PATHFINDING);
            }

            void Initialize()
            {
                _isFrenzy = false;
                _dehydration = true;
            }

            void Reset() override
            {
                Initialize();
                BossAI::Reset();

                DoCast(me, SPELL_THREAT_PROC, true);
            }

            void EnterCombat(Unit* who) override
            {
                BossAI::EnterCombat(who);
                Talk(SAY_AGGRO);
            }

            void JustReachedHome() override
            {
                BossAI::JustReachedHome();
                instance->SetData(DATA_HANDLE_CELLS, DATA_ICHORON);
            }

            void DoAction(int32 actionId) override
            {
                switch (actionId)
                {
                    case ACTION_WATER_GLOBULE_HIT:
                        if (!me->IsAlive())
                            break;

                        me->ModifyHealth(int32(me->CountPctFromMaxHealth(3)));
                        _dehydration = false;
                        break;
                    case ACTION_PROTECTIVE_BUBBLE_SHATTERED:
                    {
                        Talk(SAY_SHATTER);
                        Talk(EMOTE_SHATTER);

                        DoCastAOE(SPELL_SPLATTER, true);
                        DoCastAOE(SPELL_BURST, true);
                        DoCast(me, SPELL_DRAINED, true);

                        uint32 damage = me->CountPctFromMaxHealth(30);
                        me->LowerPlayerDamageReq(damage);
                        me->ModifyHealth(-std::min<int32>(damage, me->GetHealth() - 1));

                        scheduler.DelayAll(Seconds(15));
                        break;
                    }
                    case ACTION_DRAINED:
                        if (HealthAbovePct(30))
                        {
                            Talk(SAY_BUBBLE);
                            DoCast(me, SPELL_PROTECTIVE_BUBBLE, true);
                        }
                        break;
                    default:
                        break;
                }
            }

            uint32 GetData(uint32 type) const override
            {
                if (type == DATA_DEHYDRATION)
                    return _dehydration ? 1 : 0;
                return 0;
            }

            void KilledUnit(Unit* victim) override
            {
                if (victim->GetTypeId() == TYPEID_PLAYER)
                    Talk(SAY_SLAY);
            }

            void JustDied(Unit* killer) override
            {
                BossAI::JustDied(killer);
                Talk(SAY_DEATH);
            }

            void JustSummoned(Creature* summon) override
            {
                summons.Summon(summon);

                if (summon->GetEntry() == NPC_ICHOR_GLOBULE)
                    DoCast(summon, SPELL_WATER_GLOBULE_VISUAL);
            }

            void SummonedCreatureDespawn(Creature* summon) override
            {
                BossAI::SummonedCreatureDespawn(summon);

                if (summons.empty())
                    me->RemoveAurasDueToSpell(SPELL_DRAINED, ObjectGuid::Empty, 0, AURA_REMOVE_BY_EXPIRE);
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                if (!_isFrenzy && HealthBelowPct(25) && !me->HasAura(SPELL_DRAINED))
                {
                    Talk(SAY_ENRAGE);
                    DoCast(me, SPELL_FRENZY, true);
                    _isFrenzy = true;
                }

                scheduler.Update(diff,
                    std::bind(&BossAI::DoMeleeAttackIfReady, this));
            }

            void ScheduleTasks() override
            {
                scheduler.Async([this]
                {
                    DoCast(me, SPELL_SHRINK);
                    DoCast(me, SPELL_PROTECTIVE_BUBBLE);
                });

                scheduler.Schedule(Seconds(10), Seconds(15), [this](TaskContext task)
                {
                    DoCastAOE(SPELL_WATER_BOLT_VOLLEY);
                    task.Repeat(Seconds(10), Seconds(15));
                });

                scheduler.Schedule(Seconds(6), Seconds(9), [this](TaskContext task)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 50.0f))
                        DoCast(target, SPELL_WATER_BLAST);
                    task.Repeat(Seconds(6), Seconds(9));
                });
            }

        private:
            bool _isFrenzy;
            bool _dehydration;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetVioletHoldAI<boss_ichoronAI>(creature);
        }
};

class npc_ichor_globule : public CreatureScript
{
    public:
        npc_ichor_globule() : CreatureScript("npc_ichor_globule") { }

        struct npc_ichor_globuleAI : public ScriptedAI
        {
            npc_ichor_globuleAI(Creature* creature) : ScriptedAI(creature)
            {
                _instance = creature->GetInstanceScript();
                creature->SetReactState(REACT_PASSIVE);
            }

            void SpellHit(Unit* caster, SpellInfo const* spellInfo) override
            {
                if (spellInfo->Id == SPELL_WATER_GLOBULE_VISUAL)
                {
                    DoCast(me, SPELL_WATER_GLOBULE_TRANSFORM);
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                    me->GetMotionMaster()->MoveFollow(caster, 0.0f, 0.0f);
                }
            }

            void MovementInform(uint32 type, uint32 id) override
            {
                if (type != FOLLOW_MOTION_TYPE)
                    return;

                if (_instance->GetObjectGuid(DATA_ICHORON).GetCounter() != id)
                    return;

                me->CastSpell(me, SPELL_MERGE);
                me->DespawnOrUnsummon(1);
            }

            // on retail spell casted on a creature's death are not casted after death but keeping mob at 1 health, casting it and then letting the mob die.
            // this feature should be still implemented
            void DamageTaken(Unit* /*attacker*/, uint32& damage) override
            {
                if (damage >= me->GetHealth())
                    DoCastAOE(SPELL_SPLASH);
            }

            void UpdateAI(uint32 /*diff*/) override { }

        private:
            InstanceScript* _instance;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetVioletHoldAI<npc_ichor_globuleAI>(creature);
        }
};

// 59820 - Drained
class spell_ichoron_drained : public SpellScriptLoader
{
    public:
        spell_ichoron_drained() : SpellScriptLoader("spell_ichoron_drained") { }

        class spell_ichoron_drained_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_ichoron_drained_AuraScript);

            bool Load() override
            {
                return GetOwner()->GetEntry() == NPC_ICHORON || GetOwner()->GetEntry() == NPC_DUMMY_ICHORON;
            }

            void HandleApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                GetTarget()->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_UNK_31);
                GetTarget()->SetFlag(UNIT_FIELD_FLAGS_2, UNIT_FLAG2_FEIGN_DEATH);
            }

            void HandleRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                GetTarget()->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_UNK_31);
                GetTarget()->RemoveFlag(UNIT_FIELD_FLAGS_2, UNIT_FLAG2_FEIGN_DEATH);

                if (GetTargetApplication()->GetRemoveMode() == AURA_REMOVE_BY_EXPIRE)
                    if (GetTarget()->IsAIEnabled)
                        GetTarget()->GetAI()->DoAction(ACTION_DRAINED);
            }

            void Register() override
            {
                AfterEffectApply += AuraEffectApplyFn(spell_ichoron_drained_AuraScript::HandleApply, EFFECT_0, SPELL_AURA_MOD_STUN, AURA_EFFECT_HANDLE_REAL);
                AfterEffectRemove += AuraEffectRemoveFn(spell_ichoron_drained_AuraScript::HandleRemove, EFFECT_0, SPELL_AURA_MOD_STUN, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_ichoron_drained_AuraScript();
        }
};

// 54269 - Merge
class spell_ichoron_merge : public SpellScriptLoader
{
    public:
        spell_ichoron_merge() : SpellScriptLoader("spell_ichoron_merge") { }

        class spell_ichoron_merge_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_ichoron_merge_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_SHRINK))
                    return false;
                return true;
            }

            void HandleScript(SpellEffIndex /*effIndex*/)
            {
                if (Creature* target = GetHitCreature())
                {
                    if (Aura* aura = target->GetAura(SPELL_SHRINK))
                        aura->ModStackAmount(-1);

                    target->AI()->DoAction(ACTION_WATER_GLOBULE_HIT);
                }
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_ichoron_merge_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_ichoron_merge_SpellScript();
        }
};

// 54306 - Protective Bubble
class spell_ichoron_protective_bubble : public SpellScriptLoader
{
    public:
        spell_ichoron_protective_bubble() : SpellScriptLoader("spell_ichoron_protective_bubble") { }

        class spell_ichoron_protective_bubble_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_ichoron_protective_bubble_AuraScript);

            bool Load() override
            {
                return GetOwner()->GetEntry() == NPC_ICHORON || GetOwner()->GetEntry() == NPC_DUMMY_ICHORON;
            }

            void HandleShatter(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                //if (GetTargetApplication()->GetRemoveMode() == AURA_REMOVE_BY_ENEMY_SPELL)
                if (GetAura()->GetCharges() <= 1)
                    if (GetTarget()->IsAIEnabled)
                        GetTarget()->GetAI()->DoAction(ACTION_PROTECTIVE_BUBBLE_SHATTERED);
            }

            void Register() override
            {
                AfterEffectRemove += AuraEffectRemoveFn(spell_ichoron_protective_bubble_AuraScript::HandleShatter, EFFECT_0, SPELL_AURA_MOD_DAMAGE_PERCENT_TAKEN, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_ichoron_protective_bubble_AuraScript();
        }
};

// 54259 - Splatter
class spell_ichoron_splatter : public SpellScriptLoader
{
    public:
        spell_ichoron_splatter() : SpellScriptLoader("spell_ichoron_splatter") { }

        class spell_ichoron_splatter_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_ichoron_splatter_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_WATER_GLOBULE_SUMMON_1)
                    || !sSpellMgr->GetSpellInfo(SPELL_WATER_GLOBULE_SUMMON_2)
                    || !sSpellMgr->GetSpellInfo(SPELL_WATER_GLOBULE_SUMMON_3)
                    || !sSpellMgr->GetSpellInfo(SPELL_WATER_GLOBULE_SUMMON_4)
                    || !sSpellMgr->GetSpellInfo(SPELL_WATER_GLOBULE_SUMMON_5)
                    || !sSpellMgr->GetSpellInfo(SPELL_SHRINK))
                    return false;
                return true;
            }

            void PeriodicTick(AuraEffect const* /*aurEff*/)
            {
                PreventDefaultAction();
                GetTarget()->CastSpell(GetTarget(), RAND(SPELL_WATER_GLOBULE_SUMMON_1, SPELL_WATER_GLOBULE_SUMMON_2, SPELL_WATER_GLOBULE_SUMMON_3, SPELL_WATER_GLOBULE_SUMMON_4, SPELL_WATER_GLOBULE_SUMMON_5), true);
            }

            void HandleRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (GetTargetApplication()->GetRemoveMode() == AURA_REMOVE_BY_EXPIRE)
                    if (Aura* aura = GetTarget()->GetAura(SPELL_SHRINK))
                        aura->ModStackAmount(10);
            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_ichoron_splatter_AuraScript::PeriodicTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
                AfterEffectRemove += AuraEffectRemoveFn(spell_ichoron_splatter_AuraScript::HandleRemove, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_ichoron_splatter_AuraScript();
        }
};

class achievement_dehydration : public AchievementCriteriaScript
{
    public:
        achievement_dehydration() : AchievementCriteriaScript("achievement_dehydration") { }

        bool OnCheck(Player* /*player*/, Unit* target) override
        {
            if (!target)
                return false;

            if (Creature* Ichoron = target->ToCreature())
                if (Ichoron->AI()->GetData(DATA_DEHYDRATION))
                    return true;

            return false;
        }
};

void AddSC_boss_ichoron()
{
    new boss_ichoron();
    new npc_ichor_globule();
    new spell_ichoron_drained();
    new spell_ichoron_merge();
    new spell_ichoron_protective_bubble();
    new spell_ichoron_splatter();
    new achievement_dehydration();
}
