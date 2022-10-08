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

#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "instance_bloodmaul.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"
#include "SpellAuraEffects.h"

namespace Instances { namespace Bloodmaul
{
    /// Forgemaster Gog'duh <Bloodmaul Slave Traders> - 74366
    class boss_forgemaster_gogduh : public CreatureScript
    {
        public:
            boss_forgemaster_gogduh() : CreatureScript("boss_forgemaster_gogduh") { }

            enum Spells
            {
                MagmaBarrage    = 150004,
                ThrowFlame      = 150078,
                ThrowEarth      = 150076,
            };

            enum Events
            {
                MagmaBarrageCast    = 1,
                SpawnRuination      = 2,
                SpawnCalamity       = 3,
            };

            enum NPCs
            {
                Ruination           = 74570,
                Calamity            = 74571,
                Magmolatus          = 74475,
                ForgemasterGogduh   = 74366
            };
                
            enum Yells
            {
                Aggro           = 0,
                RuinationSpawn  = 1,
                RuinationDeath  = 2,
                CalamitySpawn   = 3,
                CalamityDeath   = 4,
                Death           = 5
            };

            CreatureAI* GetAI(Creature* creature) const override
            {
                return new boss_AI(creature);
            }

            struct boss_AI : public BossAI
            {
                boss_AI(Creature* creature) : BossAI(creature, BossIds::BossForgemasterGogduh)
                {
                    m_SaidAggro = false;
                    m_SaidMagmolatusAggro = false;
                    m_MagmolatusStarted = false;

                    if (instance)
                        instance->SetBossState(BossIds::BossForgemasterGogduh, EncounterState::TO_BE_DECIDED);
                }

                void MoveInLineOfSight(Unit* who) override
                {
                    if (!m_SaidAggro && me->IsWithinDist2d(who, 30.f))
                    {
                        m_SaidAggro = true;
                        Talk((uint8)Yells::Aggro);
                    }
                }

                void DamageTaken(Unit* /*doneBy*/, uint32& damage) override
                {
                    if (!m_SaidMagmolatusAggro && me->HealthBelowPctDamaged(50, damage))
                    {
                        m_SaidMagmolatusAggro = true;

                        if (Unit* p_Boss = me->FindNearestCreature((uint32)NPCs::Magmolatus, VISIBLE_RANGE, true))
                        {
                            if (BossAI* p_AI = CAST_AI(BossAI, p_Boss->GetAI()))
                                p_AI->Talk(Yells::Aggro);
                        }
                    }

                    if (damage > me->GetHealth())
                    {
                        if (!m_MagmolatusStarted)
                        {
                            if (Unit* p_Boss = me->FindNearestCreature((uint32)NPCs::Magmolatus, VISIBLE_RANGE, true))
                            {
                                if (UnitAI* p_AI = p_Boss->GetAI())
                                {
                                    p_AI->DoAction(0);
                                    m_MagmolatusStarted = true;
                                }
                            }
                        }

                        me->SetHealth(1);
                        damage = 0;
                    }
                }

                void Reset() override
                {
                    m_MagmolatusStarted = false;
                    _Reset();
                }

                void JustReachedHome() override
                {
                    _JustReachedHome();

                    if (instance)
                    {
                        instance->SetBossState(BossIds::BossForgemasterGogduh, FAIL);
                        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                    }
                }

                void JustDied(Unit*) override
                {
                    Talk(Yells::Death);

                    if (instance)
                        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                }

                void EnterCombat(Unit*) override
                {
                    _EnterCombat();

                    if (instance)
                        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);

                    events.ScheduleEvent((uint32)Events::MagmaBarrageCast, 4000);
                    events.ScheduleEvent((uint32)Events::SpawnRuination, 6000);
                    events.ScheduleEvent((uint32)Events::SpawnCalamity, 25000);
                }

                void UpdateAI(const uint32 diff) override
                {
                    if (!UpdateVictim())
                    {
                        if (me->HasUnitState(UNIT_STATE_ROOT))
                            me->SetControlled(false, UNIT_STATE_ROOT);
                        return;
                    }

                    events.Update(diff);

                    switch ((Events)events.ExecuteEvent())
                    {
                        case Events::MagmaBarrageCast:
                        {
                            me->SetControlled(true, UNIT_STATE_ROOT);
                            DoCast(me, Spells::MagmaBarrage, false);
                            events.ScheduleEvent((uint32)Events::MagmaBarrageCast, 10000);
                            break;
                        }
                        case Events::SpawnRuination:
                        {
                            Talk((uint8)Yells::RuinationSpawn);
                            DoCastAOE((uint32)Spells::ThrowEarth, true);
                            break;
                        }
                        case Events::SpawnCalamity:
                        {
                            Talk((uint8)Yells::CalamitySpawn);
                            DoCastAOE((uint32)Spells::ThrowFlame, true);
                            break;
                        }
                        default:
                            break;
                    }

                    if (me->HasUnitState(UNIT_STATE_CASTING) || me->GetCurrentSpell(CURRENT_CHANNELED_SPELL))
                        return;

                    if (me->HasUnitState(UNIT_STATE_ROOT))
                        me->SetControlled(false, UNIT_STATE_ROOT);

                    DoMeleeAttackIfReady();
                }

                bool m_SaidAggro = false;
                bool m_SaidMagmolatusAggro = false;
                bool m_MagmolatusStarted = false;
            };
    };

    /// Magmolatus <Son of Slag> - 74475
    class boss_magmolatus : public CreatureScript
    {
        public:
            boss_magmolatus() : CreatureScript("boss_magmolatus") { }

            enum Spells
            {
                WitheringFlames = 150032,
                MoltenImpact    = 150045,
                SpellSlagSmash  = 150023
            };

            enum Events
            {
                CastFlames  = 1,
                CastImpact  = 2,
                CastSmash   = 3
            };

            enum Yells
            {
                Aggro           = 0,
                Release         = 1,
                SlagSmashYell   = 2,
                Elemental       = 3,
                Kill            = 4,
                Death           = 5
            };

            enum Achievements
            {
                AGiftOfEarthAndFire = 8993
            };

            CreatureAI* GetAI(Creature* creature) const override
            {
                return new boss_AI(creature);
            }

            struct boss_AI : public BossAI
            {
                boss_AI(Creature* creature) : BossAI(creature, BossIds::BossForgemasterGogduh)
                {
                    me->SetControlled(true, UNIT_STATE_ROOT);
                    me->AddUnitFlag(UNIT_FLAG_PACIFIED);
                    me->SetReactState(REACT_PASSIVE);

                    if (instance)
                        instance->SetBossState(BossIds::BossForgemasterGogduh, EncounterState::TO_BE_DECIDED);
                }

                void DoAction(const int32 /*action*/) override
                {
                    Talk((uint8)Yells::Release);
                    me->SetControlled(false, UNIT_STATE_ROOT);

                    if (Creature* forgemaster = me->GetMap()->GetCreature(instance->GetGuidData((uint32)MobEntries::Gogduh)))
                        me->GetMotionMaster()->MoveCharge(forgemaster->GetPositionX(), forgemaster->GetPositionY(), forgemaster->GetPositionZ(), 42.0f, 1);
                    else
                        me->GetMotionMaster()->MovePoint(1, 2082.f, 116.f, 225.f);
                }

                void JustReachedHome() override
                {
                    me->SetControlled(true, UNIT_STATE_ROOT);
                    me->AddUnitFlag(UNIT_FLAG_PACIFIED);
                    me->SetReactState(REACT_PASSIVE);
                    _JustReachedHome();

                    if (Creature* p_Gogduh = me->FindNearestCreature((uint32)boss_forgemaster_gogduh::NPCs::ForgemasterGogduh, VISIBLE_RANGE, false))
                    {
                        p_Gogduh->Respawn(true);
                        p_Gogduh->GetMotionMaster()->MoveTargetedHome();
                    }

                    if (instance)
                    {
                        instance->SetBossState(uint32(BossIds::BossForgemasterGogduh), FAIL);
                        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                    }
                }

                void KilledUnit(Unit* p_Victim) override
                {
                    if (p_Victim->GetTypeId() == TypeID::TYPEID_PLAYER)
                        Talk((uint8)Yells::Kill);
                }

                void JustDied(Unit*) override
                {
                    Talk((uint8)Yells::Death);

                    if (instance)
                        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);

                    Creature* l_Calamity = me->FindNearestCreature((uint32)boss_forgemaster_gogduh::NPCs::Calamity, VISIBLE_RANGE, true);
                    Creature* l_Ruination = me->FindNearestCreature((uint32)boss_forgemaster_gogduh::NPCs::Ruination, VISIBLE_RANGE, true);

                    if (l_Calamity && l_Ruination && instance && me->GetMap()->IsHeroic())
                        instance->DoCompleteAchievement((uint32)Achievements::AGiftOfEarthAndFire);

                    if (l_Calamity)
                        l_Calamity->DisappearAndDie();

                    if (l_Ruination)
                        l_Ruination->DisappearAndDie();

                    _JustDied();
                }

                void MovementInform(uint32 type_Id, uint32 id) override
                {
                    if (id == 1 && (type_Id == POINT_MOTION_TYPE || type_Id == EFFECT_MOTION_TYPE))
                    {
                        if (Creature* forgemaster = me->GetMap()->GetCreature(instance->GetGuidData((uint32)MobEntries::Gogduh)))
                            me->Kill(forgemaster);

                        if (instance)
                            instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);

                        me->SetReactState(REACT_AGGRESSIVE);
                        me->RemoveUnitFlag(UNIT_FLAG_PACIFIED);

                        if (Unit* l_Victim = me->SelectNearestPlayer(VISIBLE_RANGE))
                            AttackStart(l_Victim);

                        events.ScheduleEvent((uint32)Events::CastFlames, 5000);
                    }
                }

                void NextEvent()
                {
                    switch (urand(0, 2))
                    {
                        case 0:
                            events.ScheduleEvent(uint32(Events::CastFlames), 5000);
                            break;
                        case 1:
                            events.ScheduleEvent(uint32(Events::CastImpact), 10000);
                            break;
                        case 2:
                            events.ScheduleEvent(uint32(Events::CastSmash), 5000);
                            break;
                        default:
                            break;
                                
                    }
                }

                void UpdateAI(const uint32 diff) override
                {
                    if (!UpdateVictim())
                        return;

                    if (me->HasUnitState(UNIT_STATE_CASTING) || me->GetCurrentSpell(CURRENT_CHANNELED_SPELL))
                        return;

                    events.Update(diff);

                    switch ((Events)events.ExecuteEvent())
                    {
                        case Events::CastFlames:
                        {
                            DoCast(me, (uint32)Spells::WitheringFlames, false);
                            NextEvent();
                            break;
                        }
                        case Events::CastImpact:
                        {
                            Talk((uint8)Yells::Elemental);

                            if (Unit* target = me->SelectNearbyTarget(nullptr, VISIBLE_RANGE))
                                me->CastSpell(target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), (uint32)Spells::MoltenImpact, false);

                            NextEvent();
                            break;
                        }
                        case Events::CastSmash:
                        {
                            Talk((uint8)Yells::SlagSmashYell);
                            DoCastAOE((uint32)Spells::SpellSlagSmash);
                            NextEvent();
                            break;
                        }
                        default:
                            break;
                    }

                    DoMeleeAttackIfReady();
                }
            };
    };

    /// Ruination <Servant of the Earth> - 74570
    class npc_ruination : public CreatureScript
    {
        public:
            npc_ruination() : CreatureScript("npc_ruination") { }

            enum Spells
            {
                ShatterEarth    = 150324,
                EarthSmash      = 149941
            };

            enum Events
            {
                CastSpell = 1
            };

            CreatureAI* GetAI(Creature* creature) const override
            {
                return new npc_ruinationAI(creature);
            }

            struct npc_ruinationAI : public ScriptedAI
            {
                npc_ruinationAI(Creature* creature) : ScriptedAI(creature) { }

                void Reset() override
                {
                    events.Reset();
                    events.ScheduleEvent((uint32)Events::CastSpell, 6000);
                }

                void JustDied(Unit* /* killer */) override
                {
                    if (Creature* l_Boss = me->FindNearestCreature((uint32)boss_forgemaster_gogduh::NPCs::ForgemasterGogduh, VISIBLE_RANGE))
                    {
                        if (CreatureAI* l_AI = CAST_AI(CreatureAI, l_Boss->GetAI()))
                            l_AI->Talk((uint8)boss_forgemaster_gogduh::Yells::RuinationDeath);
                    }
                }

                void UpdateAI(const uint32 diff) override
                {
                    if (!UpdateVictim())
                    {
                        if (me->HasUnitState(UNIT_STATE_ROOT))
                            me->SetControlled(false, UNIT_STATE_ROOT);
                        return;
                    }

                    if (me->HasUnitState(UNIT_STATE_CASTING) || me->GetCurrentSpell(CURRENT_CHANNELED_SPELL))
                        return;

                    if (me->HasUnitState(UNIT_STATE_ROOT))
                        me->SetControlled(false, UNIT_STATE_ROOT);

                    events.Update(diff);

                    if ((Events)events.ExecuteEvent() == Events::CastSpell)
                    {
                        me->SetControlled(true, UNIT_STATE_ROOT);
                        DoCast(me->GetVictim(), urand(0, 1) ? Spells::ShatterEarth : Spells::EarthSmash, false);
                        events.ScheduleEvent((uint32)Events::CastSpell, 5000);
                    }

                    DoMeleeAttackIfReady();
                }
            };
    };

    /// Calamity <Servant of the Flame> - 74571
    class npc_calamity : public CreatureScript
    {
        public:
            npc_calamity() : CreatureScript("npc_calamity") { }

            enum Spells
            {
                DancingFlames   = 149975,
                Firestorm       = 149997,
                Scorch          = 150290
            };

            enum Events
            {
                CastSpell = 1,
                CastScorch,
                RefreshFlames
            };

            enum Action
            {
                ActionJumpFlames
            };

            CreatureAI* GetAI(Creature* creature) const override
            {
                return new npc_calamityAI(creature);
            }

            struct npc_calamityAI : public ScriptedAI
            {
                npc_calamityAI(Creature* creature) : ScriptedAI(creature) { }

                void Reset() override
                {
                    events.Reset();
                    events.ScheduleEvent((uint32)Events::CastSpell, 12000);
                    events.ScheduleEvent((uint32)Events::CastScorch, 3000);
                }

                void JustDied(Unit*) override
                {
                    if (Creature* l_Boss = me->FindNearestCreature((uint32)boss_forgemaster_gogduh::NPCs::ForgemasterGogduh, VISIBLE_RANGE))
                    {
                        if (CreatureAI* l_AI = CAST_AI(CreatureAI, l_Boss->GetAI()))
                            l_AI->Talk((uint8)boss_forgemaster_gogduh::Yells::CalamityDeath);
                    }
                }

                void DoAction(int32 const action) override
                {
                    if (action == Action::ActionJumpFlames)
                        events.ScheduleEvent(Events::RefreshFlames, 100);
                }

                void UpdateAI(const uint32 diff) override
                {
                    if (!UpdateVictim())
                        return;

                    events.Update(diff);

                    switch ((Events)events.ExecuteEvent())
                    {
                        case Events::CastSpell:
                        {
                            me->InterruptNonMeleeSpells(false);
                            me->CastSpell(me, uint32(urand(0, 1) ? Spells::DancingFlames : Spells::Firestorm), false);
                            events.ScheduleEvent((uint32)Events::CastSpell, 12000);
                            break;
                        }
                        case Events::CastScorch:
                        {
                            events.ScheduleEvent((uint32)Events::CastScorch, 3000);

                            if (me->HasUnitState(UNIT_STATE_CASTING) || me->GetCurrentSpell(CURRENT_CHANNELED_SPELL))
                                break;

                            me->CastSpell(me->GetVictim(), (uint32)Spells::Scorch, false);
                            break;
                        }
                        case Events::RefreshFlames:
                        {
                            me->CastSpell(me, Spells::DancingFlames, true);
                            break;
                        }
                        default:
                            break;
                    }

                    DoMeleeAttackIfReady();
                }
            };
    };

    /// Firestorm - 71971
    class npc_calamity_firestorm : public CreatureScript
    {
        public:
            npc_calamity_firestorm() : CreatureScript("npc_calamity_firestorm") { }

            enum Spells
            {
                Firestorm = 144463
            };

            CreatureAI* GetAI(Creature* creature) const override
            {
                return new npc_calamity_firestormAI(creature);
            }

            struct npc_calamity_firestormAI : public ScriptedAI
            {
                npc_calamity_firestormAI(Creature* creature) : ScriptedAI(creature) { }

                void Reset() override
                {
                    me->CastSpell(me, (uint32)Spells::Firestorm, true);
                    m_Timer = 12000;
                }

                void UpdateAI(uint32 const diff) override
                {
                    if (m_Timer <= diff)
                        me->DisappearAndDie();
                    else
                        m_Timer -= diff;
                }

                uint32 m_Timer;
            };
    };

    /// Shatter Earth - 74766
    class npc_shatter_earth : public CreatureScript
    {
        public:
            npc_shatter_earth() : CreatureScript("npc_shatter_earth") { }

            enum Spells
            {
                ShatterEarthDamage  = 149963
            };

            CreatureAI* GetAI(Creature* creature) const override
            {
                return new npc_shatter_earthAI(creature);
            }

            struct npc_shatter_earthAI : public ScriptedAI
            {
                npc_shatter_earthAI(Creature* creature) : ScriptedAI(creature) { }

                void Reset() override
                {
                    if (Unit* target = me->SelectNearbyTarget(nullptr, 4.f/*, (uint32)Spells::ShatterEarthDamage*/))
                        me->CastSpell(target, (uint32)Spells::ShatterEarthDamage, true);
                    m_DeathTimer = 2000;
                }

                void UpdateAI(const uint32 diff) override
                {
                    if (me->isDead())
                        return;

                    if (m_DeathTimer <= 0)
                    {
                        me->DealDamage(me, me->GetHealth(), NULL, NODAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
                        me->DespawnOrUnsummon(0);
                    }
                    else
                        m_DeathTimer -= diff;
                }

                int32 m_DeathTimer;
            };
    };

    /// Molten Elemental - 74579
    class npc_gugdoh_molten_elemental : public CreatureScript
    {
        public:
            npc_gugdoh_molten_elemental() : CreatureScript("npc_gugdoh_molten_elemental") { }

            enum Spells
            {
                MagmaBarrage    = 150004,
                VolcanicTantrum = 150048
            };

            enum Events
            {
                CastSpell = 1
            };

            CreatureAI* GetAI(Creature* creature) const override
            {
                return new npc_gugdoh_molten_elementalAI(creature);
            }

            struct npc_gugdoh_molten_elementalAI : public ScriptedAI
            {
                npc_gugdoh_molten_elementalAI(Creature* creature) : ScriptedAI(creature) { }

                void Reset() override
                {
                    events.Reset();
                    events.ScheduleEvent((uint32)Events::CastSpell, 100);
                }

                void UpdateAI(const uint32 diff) override
                {
                    if (!UpdateVictim())
                        return;

                    if (me->HasUnitState(UNIT_STATE_CASTING) || me->GetCurrentSpell(CURRENT_CHANNELED_SPELL))
                        return;

                    events.Update(diff);

                    if ((Events)events.ExecuteEvent() == Events::CastSpell)
                    {
                        me->CastSpell(me, uint32(urand(0, 1) ? Spells::VolcanicTantrum : Spells::MagmaBarrage), false);
                        events.ScheduleEvent((uint32)Events::CastSpell, 5000);
                    }

                    DoMeleeAttackIfReady();
                }
            };
    };

    /// Magma Barrage - 150004
    class spell_magma_barrage: public SpellScriptLoader
    {
        public:
            spell_magma_barrage() : SpellScriptLoader("spell_magma_barrage") { }

            class spell_magma_barrage_AuraScript : public AuraScript
            {
                PrepareAuraScript(spell_magma_barrage_AuraScript);

                void OnPeriodic(AuraEffect const* aurEff)
                {
                    Unit* caster = GetCaster();
                    if (!caster)
                        return;

                    if (Unit* target = caster->SelectNearbyTarget(nullptr, VISIBLE_RANGE))
                        caster->CastSpell(target, GetSpellInfo()->GetEffect(aurEff->GetEffIndex())->TriggerSpell, true);
                }

                void Register() override
                {
                    OnEffectPeriodic += AuraEffectPeriodicFn(spell_magma_barrage_AuraScript::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
                }
            };

            AuraScript* GetAuraScript() const override
            {
                return new spell_magma_barrage_AuraScript();
            }
    };

    /// Rough Smash - 149941
    class spell_rough_smash: public SpellScriptLoader
    {
        public:
            spell_rough_smash() : SpellScriptLoader("spell_rough_smash") { }

            class spell_rough_smash_SpellScript : public SpellScript
            {
                PrepareSpellScript(spell_rough_smash_SpellScript);

                class RoughSmashTargetFilter
                {
                    public:
                        explicit RoughSmashTargetFilter(Position* p_CasterPosition) : m_CasterPosition(p_CasterPosition) { }

                        bool operator()(WorldObject* unit) const
                        {
                            return !m_CasterPosition->HasInArc(float(M_PI) / 3.f, unit);
                        }

                    private:
                        Position* m_CasterPosition;
                };

                void FilterTargets(std::list<WorldObject*>& targets)
                {
                    targets.remove_if(RoughSmashTargetFilter(&m_CastPosition));
                }

                void HandleOnPrepare()
                {
                    m_CastPosition = GetCaster()->GetPosition();
                }

                Position m_CastPosition;

                void Register() override
                {
                    OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_rough_smash_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_CONE_ENEMY_104);
                    OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_rough_smash_SpellScript::FilterTargets, EFFECT_1, TARGET_UNIT_CONE_ENEMY_104);
                    OnPrepare += SpellOnPrepareFn(spell_rough_smash_SpellScript::HandleOnPrepare);
                }
            };
    };

    /// Shatter Earth - 150324
    class spell_shatter_earth: public SpellScriptLoader
    {
        public:
            spell_shatter_earth() : SpellScriptLoader("spell_shatter_earth") { }

            enum Spells
            {
                ShatterEarthDamage = 150344,
                ShatterEarthNE     = 149959,
                ShatterEarthNW     = 149968,
                ShatterEarthSW     = 149970,
                ShatterEarthSE     = 149969
            };

            class spell_shatter_earth_SpellScript : public SpellScript
            {
                PrepareSpellScript(spell_shatter_earth_SpellScript);

                void OnSpellHit()
                {
                    if (Unit* caster = GetCaster())
                    {
                        uint32 const ShatterEarthSpikeSpells[] { (uint32)Spells::ShatterEarthNE, (uint32)Spells::ShatterEarthNW, (uint32)Spells::ShatterEarthSW, (uint32)Spells::ShatterEarthSE };

                        if (Unit* target = caster->SelectNearbyTarget(nullptr, VISIBLE_RANGE))
                        {
                            for (uint8 l_I = 0; l_I < 4; l_I++)
                                caster->CastSpell(target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), ShatterEarthSpikeSpells[l_I], true);
                        }

                        caster->CastSpell(caster, (uint32)Spells::ShatterEarthDamage, true);
                    }
                }

                void Register() override
                {
                    OnHit += SpellHitFn(spell_shatter_earth_SpellScript::OnSpellHit);
                }
            };

            SpellScript* GetSpellScript() const override
            {
                return new spell_shatter_earth_SpellScript();
            }
    };

    /// Dancing Flames - 149975
    class spell_dancing_flames: public SpellScriptLoader
    {
        public:
            spell_dancing_flames() : SpellScriptLoader("spell_dancing_flames") { }

            enum Spells
            {
                DancingFlames = 149975
            };

            enum Action
            {
                ActionJumpFlames
            };

            class spell_dancing_flames_AuraScript : public AuraScript
            {
                PrepareAuraScript(spell_dancing_flames_AuraScript);

                void HandleApplyEffect(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
                {
                    m_Dispelled = false;
                }

                void HandleDispel(DispelInfo* /*dispelInfo*/)
                {
                    m_Dispelled = true;
                }

                void HandleRemoveEffect(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
                {
                    if (m_Dispelled || !GetCaster())
                        return;

                    if (Creature* caster = GetCaster()->ToCreature())
                    {
                        if (caster->IsAIEnabled)
                            caster->AI()->DoAction(Action::ActionJumpFlames);
                    }
                }

                bool m_Dispelled;

                void Register() override
                {
                    OnEffectApply += AuraEffectApplyFn(spell_dancing_flames_AuraScript::HandleApplyEffect, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);
                    OnDispel += AuraDispelFn(spell_dancing_flames_AuraScript::HandleDispel);
                    OnEffectRemove += AuraEffectRemoveFn(spell_dancing_flames_AuraScript::HandleRemoveEffect, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);
                }
            };

            AuraScript* GetAuraScript() const override
            {
                return new spell_dancing_flames_AuraScript();
            }
    };

    /// Withering Flames - 150032
    class spell_withering_flames: public SpellScriptLoader
    {
        public:
            spell_withering_flames() : SpellScriptLoader("spell_withering_flames") { }
 
            enum Spells
            {
                ChokingAshes = 150034
            };

            class spell_withering_flames_AuraScript : public AuraScript
            {
                PrepareAuraScript(spell_withering_flames_AuraScript);

                void OnPeriodic(AuraEffect const*)
                {
                    Unit* caster = GetCaster();
                    if (!caster)
                        return;

                    if (Unit* target = caster->SelectNearbyTarget(GetOwner()->ToUnit(), VISIBLE_RANGE/*, (uint32)Spells::ChokingAshes*/))
                        caster->CastSpell(target, (uint32)Spells::ChokingAshes, true);
                }
 
                void Register() override
                {
                    OnEffectPeriodic += AuraEffectPeriodicFn(spell_withering_flames_AuraScript::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE);
                }
            };

            AuraScript* GetAuraScript() const override
            {
                return new spell_withering_flames_AuraScript();
            }
    };

    /// Molten Impact - 150045
    class spell_molten_impact: public SpellScriptLoader
    {
        public:
            spell_molten_impact() : SpellScriptLoader("spell_molten_impact") { }

            class spell_molten_impact_SpellScript : public SpellScript
            {
                PrepareSpellScript(spell_molten_impact_SpellScript);

                void HandleScript(SpellEffIndex)
                {
                    SetHitDamage((float)GetHitDamage() * (30.f - std::min((float)GetHitDest()->GetExactDist(GetHitUnit()), 30.f)) / 30.f);
                }

                void Register() override
                {
                    OnEffectHitTarget += SpellEffectFn(spell_molten_impact_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
                }
            };

            SpellScript* GetSpellScript() const override
            {
                return new spell_molten_impact_SpellScript();
            }
    };

    /// Magma Barrage (triggered) - 150007, 150306
    class spell_magma_barrage_trigger: public SpellScriptLoader
    {
        public:
            spell_magma_barrage_trigger() : SpellScriptLoader("spell_magma_barrage_trigger") { }

            enum Spells
            {
                MagmaBarrageTrigger = 167465
            };

            class spell_magma_barrage_trigger_SpellScript : public SpellScript
            {
                PrepareSpellScript(spell_magma_barrage_trigger_SpellScript);

                void OnSpellHit(SpellEffIndex)
                {
                    Unit* caster = GetCaster();
                    WorldLocation const* l_Dest = GetExplTargetDest();

                    if (!caster || !l_Dest)
                        return;

                    caster->CastSpell(l_Dest->m_positionX, l_Dest->m_positionY, l_Dest->m_positionZ, (uint32)Spells::MagmaBarrageTrigger, true);
                }

                void Register() override
                {
                    OnEffectHitTarget += SpellEffectFn(spell_magma_barrage_trigger_SpellScript::OnSpellHit, EFFECT_0, SPELL_EFFECT_TRIGGER_MISSILE);
                }
            };

            SpellScript* GetSpellScript() const override
            {
                return new spell_magma_barrage_trigger_SpellScript();
            }
    };

    /// Magma Barrage (damage) - 150011
    class spell_magma_barrage_damage: public SpellScriptLoader
    {
        public:
            spell_magma_barrage_damage() : SpellScriptLoader("spell_magma_barrage_damage") { }

            enum Spells
            {
                MagmaBarrageAreaTrigger = 167465
            };

            class spell_magma_barrage_damage_AuraScript : public AuraScript
            {
                PrepareAuraScript(spell_magma_barrage_damage_AuraScript);

                void OnPeriodic(AuraEffect const* aurEff)
                {
                    Unit* l_Owner = GetOwner()->ToPlayer();
                    if (!l_Owner)
                        return;

                    std::list<AreaTrigger*> areaTriggerList;
                    l_Owner->GetAreaTriggerListWithSpellIDInRange(areaTriggerList, (uint32)Spells::MagmaBarrageAreaTrigger, 3.f);

                    if (areaTriggerList.size() == 0)
                        aurEff->GetBase()->Remove();
                }

                void Register() override
                {
                    OnEffectPeriodic += AuraEffectPeriodicFn(spell_magma_barrage_damage_AuraScript::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE);
                }
            };

            AuraScript* GetAuraScript() const override
            {
                return new spell_magma_barrage_damage_AuraScript();
            }
    };

    /// Shatter Earth - 149959, 149968, 149969, 149970
    class areatrigger_shatter_earth : public AreaTriggerAI
    {
        enum Spells
        {
            ShatterEarthNE     = 149959,
            ShatterEarthNW     = 149968,
            ShatterEarthSW     = 149970,
            ShatterEarthSE     = 149969,
            ShatterEarthSpawn  = 150325,
            ShatterEarthDamage = 149963
        };

        public:
            areatrigger_shatter_earth(AreaTrigger* areaTrigger) : AreaTriggerAI(areaTrigger) { }

            void OnCreate() override
            {
                if (!at->GetCaster())
                    return;

                float orientation;
                switch ((Spells)at->GetSpellId())
                {
                    case Spells::ShatterEarthNW:
                        orientation = float(M_PI) / 4.f; // 45°
                        break;
                    case Spells::ShatterEarthSW:
                        orientation = float(M_PI) / 4.f * 3.f; // 135°
                        break;
                    case  Spells::ShatterEarthSE:
                        orientation = float(M_PI) / 4.f * 5.f; // 225°
                        break;
                    case Spells::ShatterEarthNE:
                        orientation = float(M_PI) / 4.f * 7.f; // 315°
                        break;
                    default:
                        orientation = 0.f;
                }

                Position destinationPosition;
                destinationPosition.m_positionX = at->GetPositionX() + (cos(orientation) * 20.f);
                destinationPosition.m_positionY = at->GetPositionY() + (sin(orientation) * 20.f);
                destinationPosition.m_positionZ = at->GetPositionZ();
                at->GetCaster()->UpdateGroundPositionZ(destinationPosition.m_positionX, destinationPosition.m_positionY, destinationPosition.m_positionZ);
                destinationPosition.SetOrientation(orientation);
                at->SetDestination(destinationPosition, 2000);
            }

            void OnUpdate(uint32 /*diff*/) override
            {
                Unit* caster = at->GetCaster();
                std::list<Unit*> targetList;

                if (!caster)
                    return;

                caster->GetAttackableUnitListInRange(targetList, 3.f);
                bool l_HasTarget = false;

                for (auto& l_Itr : targetList)
                {
                    if (!l_Itr->HasAura((uint32)Spells::ShatterEarthDamage))
                    {
                        l_HasTarget = true;
                        break;
                    }
                }

                if (l_HasTarget)
                    caster->CastSpell(at->GetPositionX(), at->GetPositionY(), at->GetPositionZ(), (uint32)Spells::ShatterEarthSpawn, true);
            }
    };

    /// Volcanic Trantum - 150050, 150051, 150052, 150053
    class areatrigger_volcanic_trantum : public AreaTriggerAI
    {
        enum Spells
        {
            VolcanicTrantrumNE      = 150050,
            VolcanicTrantrumNW      = 150051,
            VolcanicTrantrumSW      = 150052,
            VolcanicTrantrumSE      = 150053,
            VolcanicTrantrumDamage  = 150055
        };

        public:
            areatrigger_volcanic_trantum(AreaTrigger* areaTrigger) : AreaTriggerAI(areaTrigger) { }

            void OnCreate() override
            {
                if (!at->GetCaster())
                    return;

                float orientation;
                switch ((Spells)at->GetSpellId())
                {
                    case Spells::VolcanicTrantrumNW:
                        orientation = float(M_PI) / 4.f; // 45°
                        break;
                    case Spells::VolcanicTrantrumSW:
                        orientation = float(M_PI) / 4.f * 3.f; // 135°
                        break;
                    case Spells::VolcanicTrantrumSE:
                        orientation = float(M_PI) / 4.f * 5.f; // 225°
                        break;
                    case Spells::VolcanicTrantrumNE:
                        orientation = float(M_PI) / 4.f * 7.f; // 315°
                        break;
                    default:
                        orientation = 0.f;
                }

                Position destinationPosition;
                destinationPosition.m_positionX = at->GetPositionX() + (cos(orientation) * 20.f);
                destinationPosition.m_positionY = at->GetPositionY() + (sin(orientation) * 20.f);
                destinationPosition.m_positionZ = at->GetPositionZ();
                at->GetCaster()->UpdateGroundPositionZ(destinationPosition.m_positionX, destinationPosition.m_positionY, destinationPosition.m_positionZ);
                destinationPosition.SetOrientation(orientation);
                at->SetDestination(destinationPosition, 2000);
            }

            void OnUpdate(uint32 /*diff*/) override
            {
                Unit* caster = at->GetCaster();
                Unit* target = nullptr;
                std::list<Unit*> targetList;

                if (!caster)
                    return;
                caster->GetAttackableUnitListInRange(targetList, 3.f);

                for (auto& l_Itr : targetList)
                {
                    if (!l_Itr->HasAura((uint32)Spells::VolcanicTrantrumDamage))
                    {
                        target = l_Itr;
                        break;
                    }
                }

                if (target)
                    caster->CastSpell(target, (uint32)Spells::VolcanicTrantrumDamage, true);
            }
    };

    /// Magma Barrage - 167465
    class areatrigger_magma_barrage : public AreaTriggerAI
    {
        enum Spells
        {
            MagmaBarrageDamage = 150011
        };

        public:
            areatrigger_magma_barrage(AreaTrigger* areaTrigger) : AreaTriggerAI(areaTrigger) { }

            void OnUpdate(uint32 /*diff*/) override
            {
                Unit* caster = at->GetCaster();
                std::list<Unit*> targetList;

                if (!caster)
                    return;
                caster->GetAttackableUnitListInRange(targetList, 3.f);

                for (auto& l_Itr : targetList)
                {
                    if (!l_Itr->HasAura((uint32)Spells::MagmaBarrageDamage))
                        caster->CastSpell(l_Itr, (uint32)Spells::MagmaBarrageDamage, true);
                }
            }
    };
}
} ///< namespace Instances

void AddSC_boss_forgemaster_gogduh()
{
    /// Bosses
    new Instances::Bloodmaul::boss_forgemaster_gogduh();
    new Instances::Bloodmaul::boss_magmolatus();

    /// Summons
    new Instances::Bloodmaul::npc_ruination();
    new Instances::Bloodmaul::npc_calamity_firestorm();
    new Instances::Bloodmaul::npc_calamity();
    new Instances::Bloodmaul::npc_shatter_earth();
    new Instances::Bloodmaul::npc_gugdoh_molten_elemental();

    /// Spells
    new Instances::Bloodmaul::spell_magma_barrage();
    new Instances::Bloodmaul::spell_rough_smash();
    new Instances::Bloodmaul::spell_shatter_earth();
    new Instances::Bloodmaul::spell_dancing_flames();
    new Instances::Bloodmaul::spell_withering_flames();
    new Instances::Bloodmaul::spell_molten_impact();
    new Instances::Bloodmaul::spell_magma_barrage_damage();
    new Instances::Bloodmaul::spell_magma_barrage_trigger();

    /// AreaTriggers
    RegisterAreaTriggerAI(Instances::Bloodmaul::areatrigger_shatter_earth);
    RegisterAreaTriggerAI(Instances::Bloodmaul::areatrigger_volcanic_trantum);
    RegisterAreaTriggerAI(Instances::Bloodmaul::areatrigger_magma_barrage);
}
