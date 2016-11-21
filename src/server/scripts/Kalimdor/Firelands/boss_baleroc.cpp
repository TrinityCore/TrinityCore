/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
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
#include "PassiveAI.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "GridNotifiers.h"
#include "firelands.h"

enum Spells
{
    // Baleroc Trash
    SPELL_FLAME_TORRENT             = 100795,
    SPELL_FIERY_TORMENT             = 100797,
    SPELL_FIERY_TORMENT_DAMAGE      = 100802,
    SPELL_EARTHQUAKE                = 100724,
    SPELL_MAGMA_CONDUIT             = 100728,
    SPELL_ERUPTION                  = 100755,
    SPELL_SUMMON_MAGMAKIN           = 100746,

    // Baleroc
    //SPELL_LEASH                   = 101514, // Server-side, used to keep him in his encounter area? TrinityCore does not need a spell to handle this
    SPELL_BLADES_OF_BALEROC         = 99342,
    SPELL_INFERNO_BLADE             = 99350,
    SPELL_INFERNO_STRIKE            = 99351,
    SPELL_DECIMATION_BLADE          = 99352,
    SPELL_DECIMATION_BLADE_2        = 99405,
    SPELL_DECIMATING_STRIKE         = 99353,
    SPELL_BLAZE_OF_GLORY            = 99252,
    SPELL_INCENDIARY_SOUL           = 99369,
    SPELL_SHARDS_OF_TORMENT         = 99259,
    SPELL_SHARDS_OF_TORMENT_SUMMON  = 99260,
    SPELL_TORMENT_PRE_VISUAL        = 99258,
    SPELL_TORMENT_ACTIVE            = 99254,
    SPELL_TORMENT_PERIODIC          = 99255,
    SPELL_WAVE_OF_TORMENT           = 99261,
    SPELL_TORMENTED                 = 99257,
    SPELL_TORMENT                   = 99256,
    SPELL_COUNTDOWN                 = 99515,
    SPELL_COUNTDOWN_AURA            = 99516,
    SPELL_COUNTDOWN_3               = 99517,
    SPELL_COUNTDOWN_AOE_EXPLOSION   = 99518,
    SPELL_COUNTDOWN_VISUAL_LINK     = 99519,
    SPELL_VITAL_SPARK               = 99262,
    SPELL_VITAL_FLAME               = 99263,
    SPELL_BERSERK                   = 26662,
};

enum Emotes
{
    SAY_AGGRO                       = 0,
    SAY_SHARDS_OF_TORMENT           = 1,
    SAY_INFERNO_BLADE               = 2,
    SAY_DECIMATION_BLADE            = 3,
    SAY_KILL                        = 4,
    SAY_DEATH                       = 5,
    SAY_ENRAGE                      = 6,
    EMOTE_ENRAGE                    = 7,
    EMOTE_DECIMATION_BLADE          = 8,
    EMOTE_INFERNO_BLADE             = 9,
};

enum Guids
{
    GUID_TORMENTED                  = 1,
};

enum Actions
{
    ACTION_EQUIP_DEFAULT            = 1,
    ACTION_EQUIP_INFERNO_BLADE      = 2,
    ACTION_EQUIP_DECIMATION_BLADE   = 3,
};


enum Misc
{
    EQUIP_DEFAULT                   = 1,
    EQUIP_INFERNO_BLADE             = 2,
    EQUIP_DECIMATION_BLADE          = 3,
};

enum Phases
{
    PHASE_NONE                      = 0,
    PHASE_ONE                       = 1
};

// http://www.wowhead.com/npc=54161/flame-archon
class npc_firelands_flame_archon : public CreatureScript
{
    public:
        npc_firelands_flame_archon() : CreatureScript("npc_firelands_flame_archon") { }

        struct npc_firelands_flame_archonAI : public ScriptedAI
        {
            npc_firelands_flame_archonAI(Creature* creature) : ScriptedAI(creature)
            {
                scheduler.SetValidator([this]
                {
                    return !me->HasUnitState(UNIT_STATE_CASTING);
                });
            }

            void EnterCombat(Unit* /*attacker*/) override
            {
                scheduler.Schedule(Seconds(10), Seconds(12), [this](TaskContext context)
                {
                    DoCastAOE(SPELL_FLAME_TORRENT);
                    context.Repeat(Seconds(15), Seconds(17));
                });
                scheduler.Schedule(Seconds(25), [this](TaskContext context)
                {
                    DoCastAOE(SPELL_FIERY_TORMENT);
                    context.Repeat(Seconds(45));
                });
            }

            void JustDied(Unit* killer) override
            {
                scheduler.CancelAll();
                ScriptedAI::JustDied(killer);
            }

            void EnterEvadeMode(EvadeReason why) override
            {
                scheduler.CancelAll();
                ScriptedAI::EnterEvadeMode(why);
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                scheduler.Update(diff);

                if (!me->HasUnitState(UNIT_STATE_CASTING))
                    DoMeleeAttackIfReady();
            }

        private:
            TaskScheduler scheduler;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetFirelandsAI<npc_firelands_flame_archonAI>(creature);
        }
};

// http://www.wowhead.com/npc=54143/molten-flamefather
class npc_firelands_molten_flamefather : public CreatureScript
{
    public:
        npc_firelands_molten_flamefather() : CreatureScript("npc_firelands_molten_flamefather") { }

        struct npc_firelands_molten_flamefatherAI : public ScriptedAI
        {
            npc_firelands_molten_flamefatherAI(Creature* creature) : ScriptedAI(creature)
            {
                scheduler.SetValidator([this]
                {
                    return !me->HasUnitState(UNIT_STATE_CASTING);
                });
            }

            void JustSummoned(Creature* summon) override
            {
                if (summon->GetEntry() != NPC_MAGMA_CONDUIT)
                    return;

                summon->CastSpell(summon, SPELL_SUMMON_MAGMAKIN);
            }

            void SummonedCreatureDies(Creature* summon, Unit* /*killer*/) override
            {
                if (summon->GetEntry() != NPC_MAGMA_CONDUIT)
                    return;

                summon->DespawnOrUnsummon();
            }

            void EnterCombat(Unit* /*attacker*/) override
            {
                scheduler.Schedule(Seconds(5), [this](TaskContext context)
                {
                    DoCastAOE(SPELL_MAGMA_CONDUIT);
                    if (me->GetMap()->Is25ManRaid())
                        DoCastAOE(SPELL_MAGMA_CONDUIT);
                    context.Repeat(Seconds(25));
                });
                scheduler.Schedule(Milliseconds(12800), [this](TaskContext context)
                {
                    DoCastAOE(SPELL_EARTHQUAKE);
                    context.Repeat(Milliseconds(32500));
                });
            }

            void JustDied(Unit* killer) override
            {
                scheduler.CancelAll();
                ScriptedAI::JustDied(killer);
            }

            void EnterEvadeMode(EvadeReason why) override
            {
                scheduler.CancelAll();
                ScriptedAI::EnterEvadeMode(why);
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                scheduler.Update(diff);

                if (!me->HasUnitState(UNIT_STATE_CASTING))
                    DoMeleeAttackIfReady();
            }

        private:
            TaskScheduler scheduler;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetFirelandsAI<npc_firelands_molten_flamefatherAI>(creature);
        }
};

// http://www.wowhead.com/npc=54144/magmakin
class npc_firelands_magmakin : public CreatureScript
{
    public:
        npc_firelands_magmakin() : CreatureScript("npc_firelands_magmakin") { }

        struct npc_firelands_magmakinAI : public ScriptedAI
        {
            npc_firelands_magmakinAI(Creature* creature) : ScriptedAI(creature) { }

            void IsSummonedBy(Unit* /*summoner*/) override
            {
                //Not actually sniffed behavior
                Unit* target = me->SelectNearestTarget(50.0f, true);
                if (!target)
                    return;

                me->AddThreat(target, 50000000.0f);
                me->TauntApply(target);
            }

            void UpdateAI(uint32 /*diff*/) override
            {
                if (!UpdateVictim())
                    return;

                DoSpellAttackIfReady(SPELL_ERUPTION);
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return GetFirelandsAI<npc_firelands_magmakinAI>(creature);
        }
};

// http://www.wowhead.com/npc=53494/baleroc
class boss_baleroc : public CreatureScript
{
    public:
        boss_baleroc() : CreatureScript("boss_baleroc") { }

        struct boss_balerocAI : public firelands_bossAI
        {
            boss_balerocAI(Creature* creature) : firelands_bossAI(creature, DATA_BALEROC), _canYellKilledPlayer(true)
            {
                scheduler.SetValidator([this]
                {
                    return !me->HasUnitState(UNIT_STATE_CASTING);
                });
            }

            void Reset() override
            {
                firelands_bossAI::Reset();
                _canYellKilledPlayer = true;
                EquipWeapon(EQUIP_DEFAULT);
            }

            void EnterCombat(Unit* target) override
            {
                firelands_bossAI::EnterCombat(target);

                Talk(SAY_AGGRO);
                PreparePhase(PHASE_ONE);

                _sharedThePain.clear();
            }

            void PreparePhase(Phases phase)
            {
                //events.SetPhase(phase);

                switch (phase)
                {
                    case PHASE_ONE:
                        scheduler.Schedule(Milliseconds(8500), [this](TaskContext context)
                        {
                            me->AddAura(SPELL_INCENDIARY_SOUL, me); // No cast
                            DoCastVictim(SPELL_BLAZE_OF_GLORY);
                            context.Repeat(Milliseconds(11500));
                        });
                        scheduler.Schedule(Seconds(5), [this](TaskContext context)
                        {
                            DoCastAOE(SPELL_SHARDS_OF_TORMENT);
                            context.Repeat(Seconds(34));
                        });
                        if (me->GetMap()->IsHeroic())
                        {
                            scheduler.Schedule(Seconds(26), [this](TaskContext context)
                            {
                                DoCastAOE(SPELL_COUNTDOWN);
                                context.Repeat(Seconds(48));
                            });
                        }
                        scheduler.Schedule(Milliseconds(30500), [this](TaskContext context)
                        {
                            DoCast(SPELL_BLADES_OF_BALEROC);
                            context.Repeat(Seconds(47));
                        });
                        scheduler.Schedule(Minutes(6), [this](TaskContext)
                        {
                            Talk(SAY_ENRAGE);
                            Talk(EMOTE_ENRAGE);
                            DoCast(me, SPELL_BERSERK);
                        });
                        break;
                    default:
                        break;
                }
            }

            void DoAction(int32 action) override
            {
                switch (action)
                {
                    case ACTION_EQUIP_DEFAULT:
                    case ACTION_EQUIP_INFERNO_BLADE:
                    case ACTION_EQUIP_DECIMATION_BLADE:
                        EquipWeapon(action);
                        break;
                    default:
                        break;
                }
            }

            void KilledUnit(Unit* who) override
            {
                if (who->GetTypeId() == TYPEID_PLAYER && _canYellKilledPlayer)
                {
                    _canYellKilledPlayer = false;
                    Talk(SAY_KILL);

                    separateScheduler.Schedule(Seconds(8), [this](TaskContext)
                    {
                        _canYellKilledPlayer = true;
                    });
                }
            }

            void JustDied(Unit* killer) override
            {
                Talk(SAY_DEATH);
                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_BLAZE_OF_GLORY);
                firelands_bossAI::JustDied(killer);
            }

            void EnterEvadeMode(EvadeReason reason) override
            {
                summons.DespawnAll();
                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_BLAZE_OF_GLORY);
                firelands_bossAI::EnterEvadeMode(reason);
            }

            void UpdateAI(uint32 diff) override
            {
                scheduler.Update(diff);
                separateScheduler.Update(diff);
                firelands_bossAI::UpdateAI(diff);
            }

            void SetGUID(ObjectGuid guid, int32 type = 0) override
            {
                switch (type)
                {
                    case GUID_TORMENTED:
                        ++_sharedThePain[guid];
                        break;
                    default:
                        break;
                }
            }

            bool SharedThePain() const
            {
                for (auto const& entry : _sharedThePain)
                    if (entry.second > 3)
                        return false;

                return true;
            }

            private:
                void EquipWeapon(uint8 equipment) const
                {
                    switch (equipment)
                    {
                        case EQUIP_DEFAULT:
                            me->LoadEquipment(equipment);
                            me->SetCanDualWield(true);
                            break;
                        case EQUIP_INFERNO_BLADE:
                        case EQUIP_DECIMATION_BLADE:
                            me->LoadEquipment(equipment);
                            me->SetCanDualWield(false);
                            break;
                        default:
                            break;
                    }
                }
                // Our default TaskScheduler has a UNIT_STATE_CASTING validator that would get in the way of certain tasks, run them on a separate track.
                TaskScheduler separateScheduler;
                bool _canYellKilledPlayer;
                std::unordered_map<ObjectGuid, uint32> _sharedThePain;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetFirelandsAI<boss_balerocAI>(creature);
        }
};

// http://www.wowhead.com/npc=53495/shard-of-torment
class npc_shard_of_torment : public CreatureScript
{
    public:
        npc_shard_of_torment() : CreatureScript("npc_shard_of_torment") { }

        struct npc_shard_of_tormentAI : public NullCreatureAI
        {
            npc_shard_of_tormentAI(Creature* creature) : NullCreatureAI(creature) { }

            void IsSummonedBy(Unit* /*summoner*/) override
            {
                DoCastAOE(SPELL_TORMENT_PRE_VISUAL);
                scheduler.Schedule(Milliseconds(4400), [this](TaskContext)
                {
                    me->RemoveAurasDueToSpell(SPELL_TORMENT_PRE_VISUAL);
                    DoCastAOE(SPELL_TORMENT_ACTIVE);
                    scheduler.Schedule(Milliseconds(1100), [this](TaskContext context)
                    {
                        DoCastAOE(SPELL_WAVE_OF_TORMENT);
                        context.Repeat(Seconds(1));
                    });
                });
            }

            void SpellHitTarget(Unit* /*target*/, const SpellInfo* spell) override
            {
                if (spell->Id != SPELL_TORMENT)
                    return;

                scheduler.CancelAll();
                scheduler.Schedule(Milliseconds(1100), [this](TaskContext context)
                {
                    DoCastAOE(SPELL_WAVE_OF_TORMENT);
                    context.Repeat(Seconds(1));
                });
            }

            void UpdateAI(uint32 diff) override
            {
                scheduler.Update(diff);
            }

        private:
            TaskScheduler scheduler;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetFirelandsAI<npc_shard_of_tormentAI>(creature);
        }
};

// http://www.wowhead.com/spell=100799/fiery-torment
class spell_firelands_fiery_torment : public SpellScriptLoader
{
    public:
        spell_firelands_fiery_torment() : SpellScriptLoader("spell_firelands_fiery_torment") { }

        class spell_firelands_fiery_torment_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_firelands_fiery_torment_SpellScript);

            void HandleScript(SpellEffIndex /*effIndex*/)
            {
                if (GetHitUnit())
                    GetCaster()->CastSpell(GetHitUnit(), SPELL_FIERY_TORMENT_DAMAGE, true);
            }

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                if (targets.empty())
                    return;

                targets.sort(Trinity::ObjectDistanceOrderPred(GetCaster(), true));
                targets.resize(1);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_firelands_fiery_torment_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_DUMMY);
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_firelands_fiery_torment_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_firelands_fiery_torment_SpellScript();
        }
};

// http://www.wowhead.com/spell=99342/blades-of-baloroc
class spell_baleroc_blades_of_baleroc : public SpellScriptLoader
{
    public:
        spell_baleroc_blades_of_baleroc() : SpellScriptLoader("spell_baleroc_blades_of_baleroc") { }

        class spell_baleroc_blades_of_baleroc_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_baleroc_blades_of_baleroc_SpellScript);

            void ChooseBlade(SpellEffIndex /*effIndex*/)
            {
                Creature* caster = GetCaster()->ToCreature();
                if (!caster || !caster->IsAIEnabled)
                    return;

                switch (urand(1, 2))
                {
                    case 1:
                        caster->AI()->DoCast(SPELL_INFERNO_BLADE);
                        caster->AI()->Talk(SAY_INFERNO_BLADE);
                        caster->AI()->Talk(EMOTE_INFERNO_BLADE);
                        break;
                    case 2:
                        caster->AI()->DoCast(SPELL_DECIMATION_BLADE);
                        caster->AI()->Talk(SAY_DECIMATION_BLADE);
                        caster->AI()->Talk(EMOTE_DECIMATION_BLADE);
                        break;
                    default:
                        break;
                }
            }

            void Register() override
            {
                OnEffectHit += SpellEffectFn(spell_baleroc_blades_of_baleroc_SpellScript::ChooseBlade, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_baleroc_blades_of_baleroc_SpellScript();
        }
};

// http://www.wowhead.com/spell=99350/inferno-blade
class spell_baleroc_inferno_blade : public SpellScriptLoader
{
    public:
        spell_baleroc_inferno_blade() : SpellScriptLoader("spell_baleroc_inferno_blade") { }

        class spell_baleroc_inferno_blade_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_baleroc_inferno_blade_AuraScript);

            bool Load() override
            {
                return GetCaster()->GetTypeId() == TYPEID_UNIT;
            }

            void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (GetTarget()->IsAIEnabled)
                    GetTarget()->GetAI()->DoAction(ACTION_EQUIP_INFERNO_BLADE);
            }

            void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (GetTarget()->IsAIEnabled)
                    GetTarget()->GetAI()->DoAction(ACTION_EQUIP_DEFAULT);
            }

            void Register() override
            {
                OnEffectApply += AuraEffectApplyFn(spell_baleroc_inferno_blade_AuraScript::OnApply, EFFECT_0, SPELL_AURA_OVERRIDE_AUTOATTACK_WITH_MELEE_SPELL, AURA_EFFECT_HANDLE_REAL);
                OnEffectRemove += AuraEffectRemoveFn(spell_baleroc_inferno_blade_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_OVERRIDE_AUTOATTACK_WITH_MELEE_SPELL, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_baleroc_inferno_blade_AuraScript();
        }
};

// http://www.wowhead.com/spell=99352/decimation-blade
class spell_baleroc_decimation_blade : public SpellScriptLoader
{
    public:
        spell_baleroc_decimation_blade() : SpellScriptLoader("spell_baleroc_decimation_blade") { }

        class spell_baleroc_decimation_blade_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_baleroc_decimation_blade_AuraScript);

            bool Load() override
            {
                return GetCaster()->GetTypeId() == TYPEID_UNIT;
            }

            void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (GetTarget()->IsAIEnabled)
                    GetTarget()->GetAI()->DoAction(ACTION_EQUIP_DECIMATION_BLADE);
            }

            void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (GetTarget()->IsAIEnabled)
                    GetTarget()->GetAI()->DoAction(ACTION_EQUIP_DEFAULT);
            }

            void Register() override
            {
                OnEffectApply += AuraEffectApplyFn(spell_baleroc_decimation_blade_AuraScript::OnApply, EFFECT_1, SPELL_AURA_OVERRIDE_AUTOATTACK_WITH_MELEE_SPELL, AURA_EFFECT_HANDLE_REAL);
                OnEffectRemove += AuraEffectRemoveFn(spell_baleroc_decimation_blade_AuraScript::OnRemove, EFFECT_1, SPELL_AURA_OVERRIDE_AUTOATTACK_WITH_MELEE_SPELL, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_baleroc_decimation_blade_AuraScript();
        }
};

// http://www.wowhead.com/spell=99353/decimating-strike
class spell_baleroc_decimating_strike : public SpellScriptLoader
{
    public:
        spell_baleroc_decimating_strike() : SpellScriptLoader("spell_baleroc_decimating_strike") { }

        class spell_baleroc_decimating_strike_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_baleroc_decimating_strike_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/)
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_DECIMATING_STRIKE))
                    return false;
                return true;
            }

            void ChangeDamage()
            {
                int32 healthPctDmg = GetHitUnit()->CountPctFromMaxHealth(GetSpellInfo()->GetEffect(EFFECT_0)->BasePoints);
                int32 flatDmg = GetSpellInfo()->GetEffect(EFFECT_2)->BasePoints;

                SetHitDamage(healthPctDmg < flatDmg ? flatDmg : healthPctDmg);
            }

            void Register()
            {
                OnHit += SpellHitFn(spell_baleroc_decimating_strike_SpellScript::ChangeDamage);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_baleroc_decimating_strike_SpellScript();
        }
};

// http://www.wowhead.com/spell=99515/countdown
class spell_baleroc_countdown_aoe_dummy : public SpellScriptLoader
{
    public:
        spell_baleroc_countdown_aoe_dummy() : SpellScriptLoader("spell_baleroc_countdown_aoe_dummy") { }

        class spell_baleroc_countdown_aoe_dummy_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_baleroc_countdown_aoe_dummy_SpellScript);

            void CastSpellLink()
            {
                Unit* firstTarget = ObjectAccessor::GetUnit(*GetCaster(), _targets.front());
                Unit* secondTarget = ObjectAccessor::GetUnit(*GetCaster(), _targets.back());
                if (!firstTarget || !secondTarget)
                    return;

                firstTarget->CastSpell(secondTarget, SPELL_COUNTDOWN_VISUAL_LINK, true);
            }

            void HandleScript(SpellEffIndex /*effIndex*/)
            {
                GetCaster()->CastSpell(GetHitUnit(), SPELL_COUNTDOWN_AURA);
            }

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                Creature* caster = GetCaster()->ToCreature();
                if (!caster)
                    return;

                if (WorldObject* tank = caster->AI()->SelectTarget(SELECT_TARGET_TOPAGGRO))
                    targets.remove(tank);

                if (targets.size() < 2)
                {
                    FinishCast(SPELL_FAILED_NO_VALID_TARGETS);
                    return;
                }

                Trinity::Containers::RandomResizeList(targets, 2);

                _targets.push_back(targets.front()->GetGUID());
                _targets.push_back(targets.back()->GetGUID());
            }

            void Register() override
            {
                AfterCast += SpellCastFn(spell_baleroc_countdown_aoe_dummy_SpellScript::CastSpellLink);
                OnEffectHitTarget += SpellEffectFn(spell_baleroc_countdown_aoe_dummy_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_DUMMY);
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_baleroc_countdown_aoe_dummy_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
            }
            
            GuidList _targets;
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_baleroc_countdown_aoe_dummy_SpellScript();
        }
};

// http://www.wowhead.com/spell=99516/countdown
class spell_baleroc_countdown : public SpellScriptLoader
{
    public:
        spell_baleroc_countdown() : SpellScriptLoader("spell_baleroc_countdown") { }

        class spell_baleroc_countdown_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_baleroc_countdown_AuraScript);

            void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                GetTarget()->ToPlayer()->RemoveAurasDueToSpell(SPELL_COUNTDOWN_VISUAL_LINK);
                if (GetTargetApplication()->GetRemoveMode() == AURA_REMOVE_BY_EXPIRE)
                    GetTarget()->CastSpell(static_cast<Unit*>(nullptr), SPELL_COUNTDOWN_AOE_EXPLOSION, true);
            }

            void Register() override
            {
                AfterEffectRemove += AuraEffectRemoveFn(spell_baleroc_countdown_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_baleroc_countdown_AuraScript();
        }
};

// http://www.wowhead.com/spell=99517/countdown
class spell_baleroc_countdown_proximity_check : public SpellScriptLoader
{
    public:
        spell_baleroc_countdown_proximity_check() : SpellScriptLoader("spell_baleroc_countdown_proximity_check") { }

        class spell_baleroc_countdown_proximity_check_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_baleroc_countdown_proximity_check_SpellScript);

            void HandleScript(SpellEffIndex effIndex)
            {
                PreventHitDefaultEffect(effIndex);
                GetCaster()->RemoveAurasDueToSpell(SPELL_COUNTDOWN_AURA);
                GetHitUnit()->RemoveAurasDueToSpell(SPELL_COUNTDOWN_AURA);
            }

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                targets.remove(GetCaster());
                targets.remove_if(Trinity::UnitAuraCheck(false, SPELL_COUNTDOWN_AURA));
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_baleroc_countdown_proximity_check_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_baleroc_countdown_proximity_check_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ALLY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_baleroc_countdown_proximity_check_SpellScript();
        }
};

// http://www.wowhead.com/spell=99259/shards-of-torment
class spell_baleroc_shards_of_torment_target_search : public SpellScriptLoader
{
    public:
        spell_baleroc_shards_of_torment_target_search() : SpellScriptLoader("spell_baleroc_shards_of_torment_target_search") { }

        class spell_baleroc_shards_of_torment_target_search_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_baleroc_shards_of_torment_target_search_SpellScript);

            bool Load() override
            {
                _hasTarget = false;
                return GetCaster()->GetTypeId() == TYPEID_UNIT;
            }

            void OnSpellCast()
            {
                if (_hasTarget)
                    ENSURE_AI(boss_baleroc::boss_balerocAI, GetCaster()->GetAI())->Talk(SAY_SHARDS_OF_TORMENT);
            }

            void HandleScript(SpellEffIndex effIndex)
            {
                PreventHitDefaultEffect(effIndex);
                GetCaster()->CastSpell(GetHitUnit(), SPELL_SHARDS_OF_TORMENT_SUMMON, true);
            }

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                // Shards of torment seems to target tanks if no other targets are available as of Warlords of Draenor
                if (targets.size() <= 1)
                {
                    _hasTarget = !targets.empty();
                    return;
                }

                Creature* caster = GetCaster()->ToCreature();
                if (!caster || !caster->IsAIEnabled)
                    return;

                if (WorldObject* tank = caster->AI()->SelectTarget(SELECT_TARGET_TOPAGGRO))
                    targets.remove(tank);

                std::list<WorldObject*> melee, ranged;
                for (auto target : targets)
                {
                    if (caster->IsWithinMeleeRange(target->ToUnit()))
                    {
                        melee.push_back(target);
                    }
                    else
                    {
                        ranged.push_back(target);
                    }
                }

                targets.clear();

                if (caster->GetMap()->Is25ManRaid())
                    if (WorldObject* target = GetRandomContainerElement(ranged, melee))
                        targets.push_back(target);

                if (WorldObject* target = GetRandomContainerElement(melee, ranged))
                    targets.push_back(target);

                _hasTarget = !targets.empty();
            }

            void Register() override
            {
                OnCast += SpellCastFn(spell_baleroc_shards_of_torment_target_search_SpellScript::OnSpellCast);
                OnEffectHitTarget += SpellEffectFn(spell_baleroc_shards_of_torment_target_search_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_DUMMY);
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_baleroc_shards_of_torment_target_search_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
            }

            bool _hasTarget;
            WorldObject* GetRandomContainerElement(std::list<WorldObject*>& priority1, std::list<WorldObject*>& priority2) const
            {
                WorldObject* target = static_cast<WorldObject*>(nullptr);
                target = GetRandomContainerElement(&priority1);
                if (target)
                    priority1.remove(target);
                else
                {
                    target = GetRandomContainerElement(&priority2);
                    priority2.remove(target);
                }

                return target;
            }

            static WorldObject* GetRandomContainerElement(std::list<WorldObject*> const* list)
            {
                if (!list->empty())
                    return Trinity::Containers::SelectRandomContainerElement(*list);

                return nullptr;
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_baleroc_shards_of_torment_target_search_SpellScript();
        }
};

// http://www.wowhead.com/spell=99253/torment
class spell_baleroc_torment_target_search : public SpellScriptLoader
{
    public:
        spell_baleroc_torment_target_search() : SpellScriptLoader("spell_baleroc_torment_target_search") { }

        class spell_baleroc_torment_target_search_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_baleroc_torment_target_search_SpellScript);

            bool Load() override
            {
                _target = static_cast<WorldObject*>(nullptr);
                return true;
            }

            void OnHit(SpellEffIndex /*effIndex*/)
            {
                Spell* spell = GetCaster()->GetCurrentSpell(CURRENT_CHANNELED_SPELL);
                if (spell)
                {
                    SpellCastTargets targets = spell->m_targets;
                    if (targets.GetUnitTarget() == _target)
                        return;
                }

                if (GetHitUnit() == _target)
                    GetCaster()->CastSpell(GetHitUnit(), SPELL_TORMENT_PERIODIC);
            }

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                targets.remove_if(PlayerCheck());
                if (targets.empty())
                    return;

                targets.sort(Trinity::ObjectDistanceOrderPred(GetCaster()));
                _target = targets.front();
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_baleroc_torment_target_search_SpellScript::OnHit, EFFECT_0, SPELL_EFFECT_DUMMY);
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_baleroc_torment_target_search_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
            }

            WorldObject* _target;
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_baleroc_torment_target_search_SpellScript();
        }
};

// http://www.wowhead.com/spell=99256/torment
class spell_baleroc_torment : public SpellScriptLoader
{
    public:
        spell_baleroc_torment() : SpellScriptLoader("spell_baleroc_torment") { }

        class spell_baleroc_torment_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_baleroc_torment_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_TORMENT))
                    return false;
                return true;
            }
            
            void ModifyDamage()
            {
                SetHitDamage(GetHitDamage()*GetHitUnit()->GetAuraCount(SPELL_TORMENT));
            }

            void Register() override
            {
                OnHit += SpellHitFn(spell_baleroc_torment_SpellScript::ModifyDamage);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_baleroc_torment_SpellScript();
        }

        class spell_baleroc_torment_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_baleroc_torment_AuraScript);

            void HandleProc(AuraEffect const* /*aurEff*/, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                Unit* healer = eventInfo.GetProcTarget();
                if (healer->HasAura(SPELL_VITAL_FLAME))
                    return;

                bool Is25ManHeroic = healer->GetMap()->IsHeroic() && healer->GetMap()->Is25ManRaid();
                uint32 stacks = healer->GetAuraCount(SPELL_VITAL_SPARK) + std::min(uint8(ceil(GetAura()->GetStackAmount() / (Is25ManHeroic ? 5 : 3))), uint8(255));

                healer->SetAuraStack(SPELL_VITAL_SPARK, healer, stacks);
                healer->GetAura(SPELL_VITAL_SPARK)->RefreshDuration();
            }

            void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_DEATH)
                    GetTarget()->CastSpell(GetTarget(), SPELL_TORMENTED, true);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_baleroc_torment_AuraScript::HandleProc, EFFECT_1, SPELL_AURA_DUMMY);
                OnEffectRemove += AuraEffectRemoveFn(spell_baleroc_torment_AuraScript::OnRemove, EFFECT_1, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_baleroc_torment_AuraScript();
        }
};
// http://www.wowhead.com/spell=99257/tormented
class spell_baleroc_tormented : public SpellScriptLoader
{
    public:
        spell_baleroc_tormented() : SpellScriptLoader("spell_baleroc_tormented") { }

        class spell_baleroc_tormented_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_baleroc_tormented_AuraScript);

            void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (InstanceScript* instance = GetTarget()->GetInstanceScript())
                    if (Creature* baleroc = ObjectAccessor::GetCreature(*GetTarget(), instance->GetGuidData(DATA_BALEROC)))
                        baleroc->AI()->SetGUID(GetTarget()->GetGUID(), GUID_TORMENTED);
            }

            void Register() override
            {
                OnEffectApply += AuraEffectApplyFn(spell_baleroc_tormented_AuraScript::OnApply, EFFECT_0, SPELL_AURA_MOD_DAMAGE_PERCENT_TAKEN, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_baleroc_tormented_AuraScript();
        }
};

// http://www.wowhead.com/spell=99489/tormented
class spell_baleroc_tormented_spread : public SpellScriptLoader
{
    public:
        spell_baleroc_tormented_spread() : SpellScriptLoader("spell_baleroc_tormented_spread") { }

        class spell_baleroc_tormented_spread_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_baleroc_tormented_spread_SpellScript);

            void HandleScript(SpellEffIndex effIndex)
            {
                PreventHitDefaultEffect(effIndex);
                GetHitUnit()->CastSpell(GetHitUnit(), SPELL_TORMENTED, true);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_baleroc_tormented_spread_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_baleroc_tormented_spread_SpellScript();
        }
};

// http://www.wowhead.com/spell=99262/vital-spark
class spell_baleroc_vital_spark : public SpellScriptLoader
{
    public:
        spell_baleroc_vital_spark() : SpellScriptLoader("spell_baleroc_vital_spark") { }

        class spell_baleroc_vital_spark_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_baleroc_vital_spark_AuraScript);

            void HandleProc(AuraEffect const* /*aurEff*/, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                if (Unit* target = eventInfo.GetProcTarget())
                    if (target->HasAura(SPELL_BLAZE_OF_GLORY))
                        GetCaster()->CastSpell(GetCaster(), SPELL_VITAL_FLAME, true);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_baleroc_vital_spark_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_baleroc_vital_spark_AuraScript();
        }
};

// http://www.wowhead.com/spell=99263/vital-flame
class spell_baleroc_vital_flame : public SpellScriptLoader
{
    public:
        spell_baleroc_vital_flame() : SpellScriptLoader("spell_baleroc_vital_flame") { }

        class spell_baleroc_vital_flame_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_baleroc_vital_flame_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_VITAL_SPARK))
                    return false;
                return true;
            }

            void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (!GetCaster()->HasAura(SPELL_VITAL_SPARK))
                {
                    stacks = 0;
                    return;
                }

                uint32 auraCnt = GetCaster()->GetAuraCount(SPELL_VITAL_SPARK);
                int32 healingPct = sSpellMgr->GetSpellInfo(SPELL_VITAL_SPARK)->GetEffect(EFFECT_0)->BasePoints * auraCnt;

                if (GetAura()->GetEffect(EFFECT_0)->GetAmount() < healingPct)
                    GetAura()->GetEffect(EFFECT_0)->SetAmount(healingPct);

                stacks = auraCnt;
                GetCaster()->RemoveAura(SPELL_VITAL_SPARK);
            }

            void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (GetTargetApplication()->GetRemoveMode() == AURA_REMOVE_BY_EXPIRE)
                    GetCaster()->SetAuraStack(SPELL_VITAL_SPARK, GetCaster(), stacks);
            }

            void Register() override
            {
                OnEffectApply += AuraEffectApplyFn(spell_baleroc_vital_flame_AuraScript::OnApply, EFFECT_0, SPELL_AURA_359, AURA_EFFECT_HANDLE_REAL);
                OnEffectRemove += AuraEffectRemoveFn(spell_baleroc_vital_flame_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_359, AURA_EFFECT_HANDLE_REAL);
            }

            uint32 stacks;
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_baleroc_vital_flame_AuraScript();
        }
};

// http://www.wowhead.com/achievement=5830/share-the-pain //17577
class achievement_share_the_pain : public AchievementCriteriaScript
{
    public:
        achievement_share_the_pain() : AchievementCriteriaScript("achievement_share_the_pain") { }

        bool OnCheck(Player* /*source*/, Unit* target) override
        {
            if (!target)
                return false;

            return ENSURE_AI(boss_baleroc::boss_balerocAI, target->GetAI())->SharedThePain();
        }
};

void AddSC_boss_baleroc()
{
    new npc_firelands_flame_archon();
    new npc_firelands_molten_flamefather();
    new npc_firelands_magmakin();

    new boss_baleroc();
    new npc_shard_of_torment();

    new spell_firelands_fiery_torment();
    new spell_baleroc_blades_of_baleroc();
    new spell_baleroc_inferno_blade();
    new spell_baleroc_decimation_blade();
    new spell_baleroc_decimating_strike();
    new spell_baleroc_countdown_aoe_dummy();
    new spell_baleroc_countdown();
    new spell_baleroc_countdown_proximity_check();
    new spell_baleroc_shards_of_torment_target_search();
    new spell_baleroc_torment_target_search();
    new spell_baleroc_torment();
    new spell_baleroc_tormented();
    new spell_baleroc_tormented_spread();
    new spell_baleroc_vital_spark();
    new spell_baleroc_vital_flame();

    new achievement_share_the_pain();
};
