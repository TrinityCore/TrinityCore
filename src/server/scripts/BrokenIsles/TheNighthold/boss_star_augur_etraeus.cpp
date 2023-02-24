///*
// * Copyright 2023 AzgathCore
// *
// * This program is free software; you can redistribute it and/or modify it
// * under the terms of the GNU General Public License as published by the
// * Free Software Foundation; either version 2 of the License, or (at your
// * option) any later version.
// *
// * This program is distributed in the hope that it will be useful, but WITHOUT
// * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
// * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
// * more details.
// *
// * You should have received a copy of the GNU General Public License along
// * with this program. If not, see <http://www.gnu.org/licenses/>.
// */
//
//#include "AreaTriggerAI.h"
//#include "thenighthold.h"
//#include "Packets/MiscPackets.h"
//#include "AreaTrigger.h"
//#include "AreaTriggerTemplate.h"
//#include "SpellAuraDefines.h"
//#include "SpellAuraEffects.h"
//#include "GameObject.h"
//
//enum Misc
//{
//    EVENT_1 = 1,
//    EVENT_2,
//};
//
//enum Spells
//{
//    SpellStarBurst                      = 205486,
//    SpellCoronalEjection                = 205554,
//    SpellCoronalEjectionSummon          = 205556,
//    SpellCoronalEjectionDmg             = 206464,
//    SpellCoronalEjectionFilter          = 208276,
//    SpellCoronalEjectionVisual          = 205563, //xVisual: 95991, 96687, 96777, 96440
//
//    SpellPhase2Conversation             = 222130,
//    SpellIceBurst                       = 206921,
//    SpellCometImpact                    = 206628,
//    SpellAbsoluteZero                   = 206585,
//    SpellChilled                        = 206589,
//    SpellFrozenSolid                    = 206603,
//    SpellIcyEjection                    = 206936,
//    SpellShatter                        = 206938,
//    SpellFrigidNove                     = 206949, //Heroic+
//    SpellFrigidNoveDamage               = 206954,
//
//    SpellPhase3Conversation             = 222133,
//    SpellFelBurst                       = 206388,
//    SpellFelEjection                    = 205649,
//    SpellFelFlameAtSpawn                = 206399,
//    SpellFelFlameAreaDamage             = 206398,
//    SpellFelImpact                      = 208426,
//    SpellFelImpactMissile               = 206433,
//    SpellFelNove                        = 206517,
//
//    SpellPhase4Conversation             = 222134,
//    SpellVoidBurst                      = 214486,
//    SpellVoidBurstDot                   = 206965,
//    SpellVoidBurstVisual_1              = 214425,
//    SpellVoidBurstVisual_2              = 214426,
//    SpellVoidEjection                   = 207143, //Deprecated?
//    SpellVoidImpact                     = 207768, //207813,
//    SpellWitnessTheVoid                 = 207720,
//    SpellVoidShiftAT                    = 207716,
//    SpellVoidShiftAT_2                  = 208438, //Boss
//    SpellVoidShiftMod                   = 207714,
//    SpellVoidEruption                   = 207145,
//    SpellVoidNova                       = 207439,
//    SpellBurstingVoid                   = 227492,
//
//    SpellGravitationalPull              = 205984,
//    SpellNetherTraversal                = 221875,
//    SpellBigBang                        = 222761,
//
//    SpellPreCombatVisual                = 232550,
//
//    //Mythic
//    SPELL_GRAND_CONJUNCTION             = 205408,
//    SPELL_GRAND_TRINE                   = 207831,
//    SPELL_STAR_SIGN_CRAB                = 205429,
//    SPELL_STAR_SIGN_WOLF                = 205445,
//    SPELL_STAR_SIGN_DRAGON              = 216344,
//    SPELL_STAR_SIGN_HUNTER              = 216345,
//    SPELL_FEL_EMBER_AURA                = 227446,
//
//    //Ice Crystal
//    SPELL_ICE_CRYSTAL_AURA              = 216696,
//
//    //Eye of the Void (109082, 109088)
//    SPELL_WORLD_DEVOURING_FORCE         = 216909, //Damage
//    SPELL_VOID_DISSOLVE_IN              = 216900, //Visual Spawn
//    SPELL_EYE_VOID_DISSOLVE             = 216984, //Visual Despawn
//    SPELL_WORLD_DEVOURING_FORCE_DUMMY   = 217039, //Npc passenger 109088
//
//    //Remnant of the Void
//    SPELL_DEVOURING_REMNANT_FILTER      = 217048,
//    SPELL_DEVOURING_REMNANT_CHANELL     = 217046,
//    SPELL_DEVOURING_REMNANT_DMG         = 217054,
//};
//
//enum Phases
//{
//    Phase0 = 1,
//    Phase1 = 2,
//    Phase2 = 3,
//    Phase3 = 4
//};
//
//enum MiscData
//{
//    AreaTiggerFelFlameID        = 10916,
//    NpcThingThatShouldNotBe     = 104880,
//
//    DATA_ETRAEUS_CONJUNCTION_COUNT
//};
//
//Position const centrPos = {607.76f, 3187.98f, 195.95f};
//
//inline void SetZoneOverrideLight(Creature* creature, uint32 areaLightID, uint32 lightID, uint32 fadeInTime)
//{
//    WorldPackets::Misc::OverrideLight overrideLight;
//    overrideLight.AreaLightID = areaLightID;
//    overrideLight.OverrideLightID = lightID;
//    overrideLight.TransitionMilliseconds = fadeInTime;
//    overrideLight.Write();
//
//    auto const& playerList = creature->GetMap()->GetPlayers();
//    if (playerList.isEmpty())
//        return;
//
//    std::list<Player*> temp;
//    for (auto& itr : playerList)
//        if (auto player = itr.GetSource())
//            player->SendDirectMessage(overrideLight.GetRawPacket());
//}
//
////103758
//struct boss_star_augur_etraeus : BossAI
//{
//    explicit boss_star_augur_etraeus(Creature* creature) : BossAI(creature, DATA_ETRAEUS)
//    {
//        PhaseID = Phase0;
//        me->SetUnitMovementFlags(MOVEMENTFLAG_DISABLE_GRAVITY | MOVEMENTFLAG_ROOT);
//        me->SetUnitFlags2(UNIT_FLAG2_REGENERATE_POWER);
//        me->SetUnitFlags2(UNIT_FLAG2_UNK5);
//        me->SetUnitFlags(UNIT_FLAG_REMOVE_CLIENT_CONTROL); // hack btw
//        me->SetReactState(REACT_DEFENSIVE);
//
//        //instance->SetData(DATA_STAR_AUGUR_ETRAEUS_PHASE, PhaseID);
//        //instance->SetData(DATA_STAR_AUGUR_ETRAEUS_GRAVITY_PULL_COUNTER, 0);
//        me->CastSpell(me, SpellPreCombatVisual, false);
//    }
//
//    std::vector<uint32> IcyEjectionTime = {35200, 6600, 4800, 51200, 2100, 3000, 24200, 2100, 2200};
//    std::vector<uint32> FelEjectionTime = {3900, 2900, 2600, 9700, 2100, 1500, 32700, 1800, 2000, 13700, 3200, 1900, 21800, 7300, 11100, 2900, 2100, 23300, 2000, 2000};
//
//    uint8 PhaseID = 0;
//    uint8 HealthPct = 0;
//    uint8 conjunctionCount = 0;
//    uint8 ejectionCount = 0;
//    TaskScheduler scheduler;
//
//    void ScheduleTasks() override
//    {
//        me->GetScheduler().Schedule(Seconds(2), Phase0, [this](TaskContext context)
//        {
//            context.Repeat();
//            DoCast(SpellStarBurst);
//        });
//        me->GetScheduler().Schedule(Seconds(7), Phase0, [this](TaskContext context)
//        {
//            context.Repeat(Seconds(14), Seconds(18));
//            me->CastSpell(me, SpellCoronalEjectionFilter, true);
//        });
//
//        if (IsMythicRaid())
//        {
//            me->GetScheduler().Schedule(Seconds(16), Phase0, [this](TaskContext context) //GRAND_CONJUNCTION
//            {
//                if (conjunctionCount < 2)
//                    context.Repeat(Seconds(12));
//                DoCast(SPELL_GRAND_CONJUNCTION);
//                ++conjunctionCount;
//            });
//        }
//    }
//
//    void CallPhase1Tasks()
//    {
//        
//        me->GetScheduler().Schedule(Milliseconds(10), Phase1, [this](TaskContext /*context*/)
//        {
//            SetZoneOverrideLight(me, 7008, 0, 3000);
//        });
//        me->GetScheduler().Schedule(Seconds(1), Phase1, [this](TaskContext /*context*/)
//        {
//            SetZoneOverrideLight(me, 7008, 7003, 1000);
//        });
//        me->GetScheduler().Schedule(Seconds(2), Phase1, [this](TaskContext context)
//        {
//            context.Repeat();
//            me->CastSpell(me->GetVictim(), SpellIceBurst);
//        });
//        me->GetScheduler().Schedule(Seconds(21), Phase1, [this](TaskContext context)
//        {
//            context.Repeat(Seconds(28));
//            me->CastSpell(me->GetVictim(), SpellGravitationalPull);
//        });
//        me->GetScheduler().Schedule(Seconds(12), Phase1, [this](TaskContext context)
//        {
//            if (ejectionCount > IcyEjectionTime.size())
//                ejectionCount = 0;
//            context.Repeat(Milliseconds(IcyEjectionTime[ejectionCount++]));
//            DoCast(me, SpellCoronalEjectionFilter, true);
//        });
//
//        if (IsHeroicPlusRaid())
//        {
//            scheduler
//                .Schedule(Seconds(40), Phase1, [this](TaskContext context)
//            {
//                context.DelayGroup(Phase1, Seconds(3));
//                context.Repeat(Seconds(60));
//                DoCast(SpellFrigidNove);
//            });
//        }
//
//        if (IsMythicRaid())
//        {
//            scheduler
//                .Schedule(Seconds(17), Phase1, [this](TaskContext context) //GRAND_CONJUNCTION
//            {
//                if (conjunctionCount < 2)
//                    context.Repeat(Seconds(!conjunctionCount ? 45 : 58));
//                DoCast(SPELL_GRAND_CONJUNCTION);
//                ++conjunctionCount;
//            });
//        }
//    }
//
//    void CallPhase2Tasks()
//    {
//        scheduler
//            .Schedule(Seconds(2), Phase2, [this](TaskContext context)
//        {
//            context.Repeat();
//            DoCast(SpellFelBurst);
//        })
//            .Schedule(Milliseconds(10), Phase2, [this](TaskContext /*context*/)
//        {
//            SetZoneOverrideLight(me, 7008, 0, 3000);
//        })
//            .Schedule(Seconds(1), Phase2, [this](TaskContext /*context*/)
//        {
//            SetZoneOverrideLight(me, 7008, 7004, 1000);
//        })
//            .Schedule(Seconds(30), Phase2, [this](TaskContext context)
//        {
//            context.Repeat();
//            me->CastSpell(me->GetVictim(), SpellGravitationalPull);
//        })
//            .Schedule(Seconds(7), Phase2, [this](TaskContext context)
//        {
//            if (ejectionCount > FelEjectionTime.size())
//                ejectionCount = 0;
//            context.Repeat(Milliseconds(FelEjectionTime[ejectionCount++]));
//            DoCast(me, SpellCoronalEjectionFilter, true);
//        });
//
//        if (IsHeroicPlusRaid())
//        {
//            scheduler
//                .Schedule(Seconds(60), Phase2, [this](TaskContext context)
//            {
//                context.DelayGroup(Phase2, Seconds(2));
//                context.Repeat(Seconds(50));
//                DoCast(SpellFelNove);
//            });
//        }
//
//        if (IsMythicRaid())
//        {
//            scheduler
//                .Schedule(Seconds(50), Phase2, [this](TaskContext context) //GRAND_CONJUNCTION
//            {
//                if (conjunctionCount < 2)
//                    context.Repeat(Seconds(42));
//                DoCast(SPELL_GRAND_CONJUNCTION);
//                ++conjunctionCount;
//            });
//        }
//    }
//
//    void CallPhase3Tasks()
//    {
//        scheduler
//            .Schedule(Seconds(2), Phase3, [this](TaskContext context)
//        {
//            context.Repeat(Milliseconds(2500));
//            if (auto target = SelectTarget(SELECT_TARGET_RANDOM, 0, 150.f, true))
//                DoCast(target, SpellVoidBurst);
//        })
//            .Schedule(Milliseconds(10), Phase3, [this](TaskContext /*context*/)
//        {
//            SetZoneOverrideLight(me, 7008, 0, 3000);
//        })
//            .Schedule(Seconds(1), Phase3, [this](TaskContext /*context*/)
//        {
//            SetZoneOverrideLight(me, 7008, 7005, 1000);
//        })
//            .Schedule(Minutes(3), Phase3, [this](TaskContext /*context*/)
//        {
//            DoCast(SpellBigBang);
//        })
//            .Schedule(Seconds(30), Phase3, [this](TaskContext context)
//        {
//            context.Repeat(Seconds(65));
//            me->CastSpell(me->GetVictim(), SpellGravitationalPull);
//        })
//            .Schedule(Seconds(6), Phase3, [this](TaskContext context)
//        {
//            uint32 timer = 10;
//            if (++ejectionCount >= 3)
//            {
//                ejectionCount = 0;
//                timer = 42;
//            }
//            context.Repeat(Seconds(timer));
//            DoCast(me, SpellCoronalEjectionFilter, true);
//        });
//
//        if (IsHeroicPlusRaid())
//        {
//            scheduler
//                .Schedule(Seconds(60), Phase3, [this](TaskContext context)
//            {
//                context.DelayGroup(Phase3, Seconds(2));
//                context.Repeat(Seconds(50));
//                DoCast(SpellVoidNova);
//                summons.DespawnEntry(NPC_CORONAL_EJECTION);
//            });
//        }
//
//        if (IsMythicRaid())
//        {
//            scheduler
//                .Schedule(Seconds(40), Phase3, [this](TaskContext context) //GRAND_CONJUNCTION
//            {
//                if (conjunctionCount < 2)
//                    context.Repeat(Seconds(58));
//                DoCast(SPELL_GRAND_CONJUNCTION);
//                ++conjunctionCount;
//            })
//                .Schedule(Seconds(8), Phase3, [this](TaskContext context) //Summon NPC_EYE_OF_THE_VOID
//            {
//                context.Repeat(Seconds(!conjunctionCount ? 42 : 58));
//                Position pos;
//                float orientation = urand(0,1) ? frand(0.0f, 3.13f) : frand(4.58f, 6.28f);
//                float angle = pos.GetAngle(me);
//                me->SummonCreature(NPC_EYE_OF_THE_VOID, pos.GetPositionX(), pos.GetPositionY(), 196.74f, angle);
//            });
//        }
//    }
//
//    void RemoveDebuffs()
//    {
//        instance->DoRemoveAurasDueToSpellOnPlayers(SpellGravitationalPull);
//        instance->DoRemoveAurasDueToSpellOnPlayers(SpellFelFlameAreaDamage);
//        instance->DoRemoveAurasDueToSpellOnPlayers(SpellFelEjection);
//        instance->DoRemoveAurasDueToSpellOnPlayers(SpellAbsoluteZero);
//        instance->DoRemoveAurasDueToSpellOnPlayers(SpellChilled);
//        instance->DoRemoveAurasDueToSpellOnPlayers(SpellIcyEjection);
//        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_GRAND_TRINE);
//        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_STAR_SIGN_CRAB);
//        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_STAR_SIGN_WOLF);
//        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_STAR_SIGN_DRAGON);
//        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_STAR_SIGN_HUNTER);
//    }
//
//    void ModerateGoVisuals(bool close = false)
//    {
//        if (auto go = me->FindNearestGameObject(251401, 100.0f))
//            go->EnableCollision(!close);
//    }
//
//    void ChangePhase()
//    {
//        scheduler.CancelGroup(PhaseID);
//        me->CastStop();
//        me->CastSpell(me, std::vector<uint32>{ SpellPhase2Conversation, SpellPhase3Conversation, SpellPhase4Conversation }[PhaseID - 1], true);
//        PhaseID++;
//        me->CastSpell(me, SpellNetherTraversal);
//        ModerateGoVisuals(true);
//        //instance->SetData(DATA_STAR_AUGUR_ETRAEUS_PHASE, PhaseID);
//    }
//
//    void DamageTaken(Unit* /*attacker*/, uint32& /*damage*/)
//    {
//        if (!me->HealthBelowPct(HealthPct))
//            return;
//
//        switch (HealthPct)
//        {
//            case 91:
//            case 61:
//            case 31:
//                scheduler.CancelAll();
//                scheduler.Async(std::bind(&boss_star_augur_etraeus::ChangePhase, this));
//                RemoveDebuffs();
//                HealthPct -= 30;
//                break;
//            default:
//                break;
//        }
//    }
//
//    void SpellFinishCast(SpellInfo const* spellInfo)
//    {
//        switch (spellInfo->Id)
//        {
//            case SpellNetherTraversal:
//            {
//                conjunctionCount = 0;
//                ejectionCount = 0;
//
//                switch (PhaseID)
//                {
//                    case Phase1:
//                        me->m_Events.KillAllEvents(true);
//                        CallPhase1Tasks();
//                        ModerateGoVisuals();
//                        break;
//                    case Phase2:
//                        me->m_Events.KillAllEvents(true);
//                        CallPhase2Tasks();
//                        ModerateGoVisuals();
//                        summons.DespawnEntry(NPC_ICE_CRYSTAL);
//                        if (IsMythicRaid())
//                            DoCast(me, SPELL_FEL_EMBER_AURA, true);
//                        break;
//                    case Phase3:
//                        me->m_Events.KillAllEvents(true);
//                        CallPhase3Tasks();
//                        ModerateGoVisuals();
//                        DoCast(me, SpellVoidShiftAT_2, true);
//                        me->RemoveDynObject(SpellFelFlameAtSpawn);
//                        me->RemoveAurasDueToSpell(SPELL_FEL_EMBER_AURA);
//                        break;
//                    default:
//                        break;
//                }
//                break;
//            }
//            default:
//                break;
//        }
//    }
//
//    void SpellHitTarget(Unit* target, SpellInfo const* spell) override
//    {
//        if (spell->Id == SpellVoidNova)
//            DoCast(target, SpellVoidBurstDot, true);
//    }
//
//    uint32 GetData(uint32 type) const override
//    {
//        switch (type)
//        {
//            case DATA_ETRAEUS_CONJUNCTION_COUNT:
//                return conjunctionCount;
//        }
//        return 0;
//    }
//
//    
//    void Reset() override
//    {
//        _Reset();
//        PhaseID = Phase0;
//        //instance->SetData(DATA_STAR_AUGUR_ETRAEUS_PHASE, PhaseID);
//        HealthPct = 91;
//        conjunctionCount = 0;
//    }
//
//    void JustEngagedWith(Unit* /*who*/) override
//    {
//        _JustEngagedWith();
//        me->RemoveAura(SpellPreCombatVisual);
//        SetZoneOverrideLight(me, 7008, 0, 5000);
//        Talk(0);
//    }
//
//    void JustDied(Unit* /*killer*/) override
//    {
//        _JustDied();
//        SetZoneOverrideLight(me, 7008, 0, 3000);
//        ModerateGoVisuals(true);
//        Talk(6);
//        RemoveDebuffs();
//    }
//
//    void EnterEvadeMode(EvadeReason w) 
//    {
//        SetZoneOverrideLight(me, 7008, 0, 3000);
//        ModerateGoVisuals(true);
//        RemoveDebuffs();
//
//        _DespawnAtEvade(Seconds(15));
//        BossAI::EnterEvadeMode();
//    }
//
//    void UpdateAI(uint32 diff) override
//    {
//        if (UpdateVictim())
//            scheduler.Update(diff);
//    }
//};
//
////103790
//struct npc_coronal_ejection : ScriptedAI
//{
//    explicit npc_coronal_ejection(Creature* creature) : ScriptedAI(creature)
//    {
//        instance = me->GetInstanceScript();
//        me->SetReactState(REACT_PASSIVE);
//    }
//
//    void IsSummonedBy(Unit* summoner) override
//    {
//        if (!instance || instance->GetBossState(DATA_ETRAEUS) != IN_PROGRESS)
//        {
//            me->DespawnOrUnsummon(100);
//            return;
//        }
//
//        DoCast(me, SpellCoronalEjectionVisual, true);
//
//        //auto phaseId = instance->GetData(DATA_STAR_AUGUR_ETRAEUS_PHASE);
//
//       /* _scheduler
//            .Schedule(Seconds(2), [this, summoner, phaseId](TaskContext context)
//        {
//            if (summoner)
//            {
//                switch (phaseId)
//                {
//                    case Phase0:
//                        me->CastSpell(me, SpellCoronalEjectionDmg, true, nullptr, nullptr, summoner->GetGUID());
//                        break;
//                    case Phase1:
//                        me->CastSpell(me, SpellIcyEjection, true, nullptr, nullptr, summoner->GetGUID());
//                        break;
//                    case Phase2:
//                        me->CastSpell(me, SpellFelEjection, true, nullptr, nullptr, summoner->GetGUID());
//                        break;
//                    case Phase3:
//                        me->CastSpell(me, SpellVoidEruption, true, nullptr, nullptr, summoner->GetGUID());
//                        context.Repeat(Seconds(11));
//                        break;
//                }
//            }
//        })
//            .Schedule(Seconds(4), [this, phaseId](TaskContext)
//        {
//            if (phaseId < Phase3)
//                me->DespawnOrUnsummon();
//        });*/
//    }
//
//    void UpdateAI(uint32 diff) override
//    {
//        _scheduler.Update(diff);
//    }
//
//private:
//    TaskScheduler _scheduler;
//    InstanceScript* instance;
//};
//
////104880
//struct npc_star_augur_thing_that_should_not_be : ScriptedAI
//{
//    explicit npc_star_augur_thing_that_should_not_be(Creature* creature) : ScriptedAI(creature)
//    {
//        instance = me->GetInstanceScript();
//
//        scheduler.SetValidator([this]
//        {
//            return !me->HasUnitState(UNIT_STATE_CASTING);
//        });
//    }
//
//    void Reset() override
//    {
//        scheduler.CancelAll();
//    }
//
//    void IsSummonedBy(Unit* /*summoner*/) override
//    {
//        DoCast(me, SpellVoidShiftAT, true);
//    }
//
//    void UpdateAI(uint32 diff) override
//    {
//        if (!UpdateVictim())
//            return;
//
//        DoMeleeAttackIfReady();
//    }
//
//    void JustEngagedWith(Unit* /*attacker*/) override
//    {
//        if (instance)
//            instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me, 2);
//
//        scheduler
//            .Schedule(Seconds(10), [this](TaskContext context)
//        {
//            context.Repeat();
//            DoCast(SpellWitnessTheVoid);
//        });
//    }
//
//    void JustDied(Unit* /*killer*/) override
//    {
//        if (instance)
//            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
//
//        me->DespawnOrUnsummon(100);
//    }
//
//    void EnterEvadeMode(EvadeReason w)
//    {
//        if (instance)
//            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
//        me->DespawnOrUnsummon(100);
//    }
//
//private:
//    TaskScheduler scheduler;
//    InstanceScript* instance;
//};
//
////104688
//struct npc_augur_voidling : ScriptedAI
//{
//    explicit npc_augur_voidling(Creature* creature) : ScriptedAI(creature) {}
//
//    void IsSummonedBy(Unit* summoner) override
//    {
//        if (summoner)
//            me->CastSpell(me, SpellBurstingVoid, true, nullptr, nullptr, summoner->GetGUID());
//
//        DoZoneInCombat(me, 100.0f);
//    }
//
//    void UpdateAI(uint32 diff) override
//    {
//        if (!UpdateVictim())
//            return;
//
//        DoMeleeAttackIfReady();
//    }
//
//private:
//    TaskScheduler scheduler;
//};
//
////109088
//struct npc_augur_eye_of_the_void : ScriptedAI
//{
//    explicit npc_augur_eye_of_the_void(Creature* creature) : ScriptedAI(creature)
//    {
//        me->SetReactState(REACT_PASSIVE);
//    }
//
//    void IsSummonedBy(Unit* summoner) override
//    {
//        me->CastSpell(me, SPELL_VOID_DISSOLVE_IN, TriggerCastFlags(TRIGGERED_IGNORE_CASTER_MOUNTED_OR_ON_VEHICLE));
//
//        ObjectGuid summonerGUID = summoner->GetGUID();
//        scheduler
//            .Schedule(Seconds(6), [this, summonerGUID](TaskContext context)
//        {
//            if (Unit* summoner = ObjectAccessor::GetUnit(*me, summonerGUID))
//            {
//                if (InstanceScript* instance = me->GetInstanceScript())
//                    if (Creature* augur = instance->instance->GetCreature(instance->GetGuidData(DATA_ETRAEUS)))
//                        summoner->CastSpell(summoner, SPELL_WORLD_DEVOURING_FORCE, false, nullptr, nullptr, augur->GetGUID());
//            }
//        })
//            .Schedule(Seconds(9), [this, summoner](TaskContext context)
//        {
//            me->CastSpell(me, SPELL_EYE_VOID_DISSOLVE, TriggerCastFlags(TRIGGERED_IGNORE_CASTER_MOUNTED_OR_ON_VEHICLE));
//        })
//            .Schedule(Seconds(11), [this, summoner](TaskContext context)
//        {
//            if (summoner && summoner->IsCreature())
//                summoner->ToCreature()->DespawnOrUnsummon();
//            me->DespawnOrUnsummon();
//        });
//    }
//
//    void UpdateAI(uint32 diff) override
//    {
//        scheduler.Update(diff);
//    }
//
//private:
//    TaskScheduler scheduler;
//};
//
////109151
//struct npc_augur_remnant_of_the_void : ScriptedAI
//{
//    explicit npc_augur_remnant_of_the_void(Creature* creature) : ScriptedAI(creature)
//    {
//        me->SetReactState(REACT_PASSIVE);
//        me->SetSpeed(MOVE_RUN, 0.6f);
//    }
//
//    void IsSummonedBy(Unit* summoner) override
//    {
//        events.RescheduleEvent(EVENT_1, 1000);
//        events.RescheduleEvent(EVENT_2, 5000);
//    }
//
//    void SpellHitTarget(Unit* target, SpellInfo const* spell) override
//    {
//        if (spell->Id == SPELL_DEVOURING_REMNANT_FILTER)
//        {
//            me->SetFacingToObject(target);
//            DoCast(target, SPELL_DEVOURING_REMNANT_CHANELL, true);
//        }
//    }
//
//    void UpdateAI(uint32 diff) override
//    {
//        events.Update(diff);
//
//        if (uint32 eventId = events.ExecuteEvent())
//        {
//            switch (eventId)
//            {
//                case EVENT_1:
//                {
//                    Position pos;
//                    me->GetMotionMaster()->MovePoint(1, pos);
//                    break;
//                }
//                case EVENT_2:
//                    me->StopMoving();
//                    events.CancelEvent(EVENT_1);
//                    DoCast(SPELL_DEVOURING_REMNANT_FILTER);
//                    events.RescheduleEvent(EVENT_1, 8000);
//                    events.RescheduleEvent(EVENT_2, 16000);
//                    break;
//            }
//        }
//    }
//
//private:
//    EventMap events;
//};
//
////205984
//class spell_star_augur_gravity_pull : public AuraScript
//{
//    PrepareAuraScript(spell_star_augur_gravity_pull);
//
//    /*bool UpdateGravityPull(InstanceScript* instance)
//    {
//        instance->SetData(DATA_STAR_AUGUR_ETRAEUS_GRAVITY_PULL_COUNTER, instance->GetData(DATA_STAR_AUGUR_ETRAEUS_GRAVITY_PULL_COUNTER) + 1);
//        if (instance->GetData(DATA_STAR_AUGUR_ETRAEUS_GRAVITY_PULL_COUNTER) > 3)
//        {
//            instance->SetData(DATA_STAR_AUGUR_ETRAEUS_GRAVITY_PULL_COUNTER, 0);
//            return false;
//        }
//
//        return true;
//    }*/
//
//    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
//    {
//        Unit* caster = GetCaster();
//
//        AuraRemoveMode remove = GetTargetApplication()->GetRemoveMode();
//
//        if (!caster || remove != AURA_REMOVE_BY_EXPIRE)
//            return;
//
//        auto target = GetTarget();
//
//        auto instance = caster->GetInstanceScript();
//        if (!instance)
//            return;
//
//        /*switch (instance->GetData(DATA_STAR_AUGUR_ETRAEUS_PHASE))
//        {
//            case Phase1:
//                caster->CastSpell(target, SpellCometImpact, true);
//                //if (UpdateGravityPull(instance))
//                //    caster->CastSpell(target, SpellGravitationalPull, true);
//                break;
//            case Phase2:
//                caster->CastSpell(target, SpellFelImpact, true);
//                //if (UpdateGravityPull(instance))
//                //    caster->CastSpell(target, SpellGravitationalPull, true);
//                break;
//            case Phase3:
//                caster->CastSpell(target, SpellVoidImpact, true);
//                break;
//            default:
//                break;
//        }*/
//    }
//
//    void Register() override
//    {
//        OnEffectRemove += AuraEffectRemoveFn(spell_star_augur_gravity_pull::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
//    }
//};
//
////206936
//class spell_star_augur_icy_ejection : public AuraScript
//{
//    PrepareAuraScript(spell_star_augur_icy_ejection);
//
//    float amount = 0;
//
//    void OnTick(AuraEffect const* /*aurEff*/)
//    {
//        if (auto aurEff = this->GetEffect(EFFECT_2))
//        {
//            amount = aurEff->GetAmount() + aurEff->GetBaseAmount();
//            aurEff->ChangeAmount(amount);
//        }
//    }
//
//    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
//    {
//        AuraRemoveMode remove = GetTargetApplication()->GetRemoveMode();
//
//        if (!GetTarget() || remove != AURA_REMOVE_BY_EXPIRE)
//            return;
//
//        if (InstanceScript* instance = GetCaster()->GetInstanceScript())
//        {
//            if (instance->GetBossState(DATA_ETRAEUS) != IN_PROGRESS)
//                return;
//
//            if (Creature* etraeus = Creature::GetCreature(*GetTarget(), instance->GetGuidData(DATA_ETRAEUS)))
//            {
//                GetTarget()->CastSpell(GetTarget(), SpellShatter, true);
//
//                if (GetTarget()->GetMap()->IsMythic())
//                    if (auto crystal = etraeus->SummonCreature(NPC_ICE_CRYSTAL, GetTarget()->GetPosition()))
//                        crystal->CastSpell(crystal, SPELL_ICE_CRYSTAL_AURA, true);
//            }
//        }
//        
//    }
//
//    void Register() override
//    {
//        OnEffectPeriodic += AuraEffectPeriodicFn(spell_star_augur_icy_ejection::OnTick, EFFECT_1, SPELL_AURA_PERIODIC_DAMAGE);
//        OnEffectRemove += AuraEffectRemoveFn(spell_star_augur_icy_ejection::OnRemove, EFFECT_2, SPELL_AURA_MOD_DECREASE_SPEED, AURA_EFFECT_HANDLE_REAL);
//    }
//};
//
////205649
//class spell_star_augur_fel_ejection_filter : public SpellScript
//{
//    PrepareSpellScript(spell_star_augur_fel_ejection_filter);
//
//    void FilterTargets(std::list<WorldObject*>& targets)
//    {
//        if (!GetCaster())
//            return;
//
//        std::list<WorldObject*> tempList;
//
//        for (auto const& target : targets)
//            if (Player* player = target->ToPlayer())
//                if (!player->HasAura(GetSpellInfo()->Id))
//                    tempList.push_back(target);
//
//        targets.clear();
//        targets = tempList;
//
//        if (!targets.empty())
//        {
//            if (targets.size() > 3)
//                targets.resize(3);
//        }
//    }
//
//    void Register() override
//    {
//        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_star_augur_fel_ejection_filter::FilterTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ENEMY);
//        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_star_augur_fel_ejection_filter::FilterTargets, EFFECT_1, TARGET_UNIT_DEST_AREA_ENEMY);
//    }
//};
//
////205649
//class spell_star_augur_fel_ejection : public AuraScript
//{
//    PrepareAuraScript(spell_star_augur_fel_ejection);
//
//    void OnTick(AuraEffect const* /*aurEff*/)
//    {
//        if (InstanceScript* instance = GetCaster()->GetInstanceScript())
//        {
//            if (instance->GetBossState(DATA_ETRAEUS) != IN_PROGRESS)
//                return;
//
//            if (auto target = GetTarget())
//                if (Creature* etraeus = Creature::GetCreature(*target, instance->GetGuidData(DATA_ETRAEUS)))
//                    etraeus->CastSpell(target, SpellFelFlameAtSpawn, true);
//        }
//    }
//
//    void Register() override
//    {
//        OnEffectPeriodic += AuraEffectPeriodicFn(spell_star_augur_fel_ejection::OnTick, EFFECT_1, SPELL_AURA_PERIODIC_DAMAGE);
//    }
//};
//
////206433
//class spell_star_augur_etraeus_fel_impact : public SpellScript
//{
//    PrepareSpellScript(spell_star_augur_etraeus_fel_impact);
//
//    void HandleScript(SpellEffIndex /*effIndex*/)
//    {
//        std::list<AreaTrigger*> list;
//        GetHitUnit()->GetAreaTriggerListWithSpellIDInRange(list, AreaTiggerFelFlameID, 5.0f);
//        if (list.empty())
//            return;
//
//        for (auto itr : list)
//            itr->Remove();
//    }
//
//    void Register() override
//    {
//        OnEffectHitTarget += SpellEffectFn(spell_star_augur_etraeus_fel_impact::HandleScript, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
//    }
//};
//
////207143
//class spell_star_augur_void_ejection_aura : public AuraScript
//{
//    PrepareAuraScript(spell_star_augur_void_ejection_aura);
//
//    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
//    {
//        AuraRemoveMode remove = GetTargetApplication()->GetRemoveMode();
//
//        if (remove != AURA_REMOVE_BY_EXPIRE)
//            return;
//
//        if (InstanceScript* instance = GetCaster()->GetInstanceScript())
//        {
//            if (instance->GetBossState(DATA_ETRAEUS) != IN_PROGRESS)
//                return;
//
//            if (auto target = GetTarget())
//                if (Creature* etraeus = Creature::GetCreature(*target, instance->GetGuidData(DATA_ETRAEUS)))
//                    target->CastSpell(target, SpellVoidEruption, true, nullptr, nullptr, etraeus->GetGUID());
//        }
//    }
//
//    void Register() override
//    {
//        OnEffectRemove += AuraEffectRemoveFn(spell_star_augur_void_ejection_aura::OnRemove, EFFECT_1, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);
//    }
//};
//
//// 214486
//class spell_star_augur_void_burst : public SpellScript
//{
//    PrepareSpellScript(spell_star_augur_void_burst);
//
//    void HandleScript(SpellEffIndex /*effIndex*/)
//    {
//        if (auto hitUnit = GetHitUnit())
//            GetCaster()->CastSpell(hitUnit, SpellVoidBurstDot, true);
//    }
//
//    void Register() override
//    {
//        OnEffectHitTarget += SpellEffectFn(spell_star_augur_void_burst::HandleScript, EFFECT_1, SPELL_EFFECT_SCRIPT_EFFECT);
//    }
//};
//
//
//// 206953
//class spell_star_augur_frigid_nova_dmg_trigger : public SpellScript
//{
//    PrepareSpellScript(spell_star_augur_frigid_nova_dmg_trigger);
//
//    void FilterTargets(std::list<WorldObject*>& targets)
//    {
//        if (!GetCaster() || !GetCaster()->IsPlayer())
//            return;
//
//        uint8 count = targets.size() < 5 ? targets.size() : 4;
//
//        if (InstanceScript* instance = GetCaster()->GetInstanceScript())
//            if (Creature* augur = instance->instance->GetCreature(instance->GetGuidData(DATA_ETRAEUS)))
//            {
//                int32 baseDamage = GetSpellInfo()->GetEffect(EFFECT_0)->CalcValue();
//                int32 damage = count ? baseDamage / count : baseDamage;
//                augur->CastCustomSpell(GetCaster(), SpellFrigidNoveDamage, &damage, nullptr, true);
//            }
//    }
//
//    void Register() override
//    {
//        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_star_augur_frigid_nova_dmg_trigger::FilterTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ALLY);
//    }
//};
//
////206517
//class spell_star_augur_fel_nova_dmg : public SpellScript
//{
//    PrepareSpellScript(spell_star_augur_fel_nova_dmg);
//
//    void HandleDamage(SpellEffIndex /*effIndex*/)
//    {
//        auto caster = GetCaster();
//        auto target = GetHitUnit();
//        if (!caster || !target)
//            return;
//
//        auto distance = caster->GetExactDist2d(target) * 3.0f;
//        if (distance > 90.0f)
//            distance = 90.0f;
//        auto pctModifier = 100.0f - distance;
//
//        SetHitDamage(CalculatePct(GetHitDamage(), pctModifier));
//    }
//
//    void Register() override
//    {
//        OnEffectHitTarget += SpellEffectFn(spell_star_augur_fel_nova_dmg::HandleDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
//    }
//};
//
////207720
//class spell_augur_witness_the_void : public SpellScript
//{
//    PrepareSpellScript(spell_augur_witness_the_void);
//
//    void HandleScriptEffect(SpellEffIndex effIndex)
//    {
//        if (GetCaster() && GetHitUnit())
//        {
//            if (!GetHitUnit()->isInFront(GetCaster(), 3.14f / 2.0f))
//                PreventHitDefaultEffect(EFFECT_1);
//        }
//    }
//
//    void Register()
//    {
//        OnEffectHitTarget += SpellEffectFn(spell_augur_witness_the_void::HandleScriptEffect, EFFECT_1, SPELL_EFFECT_APPLY_AURA);
//    }
//};
//
////205408
//class spell_augur_grand_conjunction : public SpellScript
//{
//    PrepareSpellScript(spell_augur_grand_conjunction);
//
//    void FilterTargets(std::list<WorldObject*>& targets)
//    {
//        if (!GetCaster() || !GetCaster()->GetAI())
//            return;
//
//        std::list<Player*> playerList;
//
//        for (auto const& object : targets)
//        {
//            if (auto const& player = object->ToPlayer())
//            {
//                if (!player->HasAura(SPELL_STAR_SIGN_CRAB) && !player->HasAura(SPELL_STAR_SIGN_WOLF) &&
//                    !player->HasAura(SPELL_STAR_SIGN_HUNTER) && !player->HasAura(SPELL_STAR_SIGN_DRAGON))
//                    {
//                        playerList.push_back(object->ToPlayer());
//                    }
//            }
//        }
//
//        if (playerList.empty())
//            return;
//
//        auto counter = 0;
//
//        switch (GetCaster()->GetAI()->GetData(DATA_ETRAEUS_CONJUNCTION_COUNT))
//        {
//            case 1:
//            {
//                if (playerList.size() > 8)
//                    Trinity::Containers::RandomResize(playerList, 8);
//
//                while (playerList.size() > 1)
//                {
//                    for (uint8 i = 0; i < 2; ++i)
//                    {
//                        auto const& player = Trinity::Containers::SelectRandomContainerElement(playerList);
//                        playerList.remove(player);
//                        GetCaster()->CastSpell(player, counter < 4 ? SPELL_STAR_SIGN_CRAB : SPELL_STAR_SIGN_WOLF, true);
//                        ++counter;
//                    }
//                }
//                break;
//            }
//            case 2:
//            {
//                if (playerList.size() > 12)
//                    Trinity::Containers::RandomResize(playerList, 12);
//
//                while (playerList.size() > 1)
//                {
//                    for (uint8 i = 0; i < 2; ++i)
//                    {
//                        auto const& player = Trinity::Containers::SelectRandomContainerElement(playerList);
//                        playerList.remove(player);
//
//                        if (counter < 4)
//                            GetCaster()->CastSpell(player, SPELL_STAR_SIGN_CRAB, true);
//                        else if (counter < 8)
//                            GetCaster()->CastSpell(player, SPELL_STAR_SIGN_WOLF, true);
//                        else if (counter < 12)
//                            GetCaster()->CastSpell(player, SPELL_STAR_SIGN_HUNTER, true);
//
//                        ++counter;
//                    }
//                }
//                break;
//            }
//            case 3:
//            {
//                if (playerList.size() > 16)
//                    Trinity::Containers::RandomResize(playerList, 16);
//
//                while (playerList.size() > 1)
//                {
//                    for (uint8 i = 0; i < 2; ++i)
//                    {
//                        auto const& player = Trinity::Containers::SelectRandomContainerElement(playerList);
//                        playerList.remove(player);
//
//                        if (counter < 4)
//                            GetCaster()->CastSpell(player, SPELL_STAR_SIGN_CRAB, true);
//                        else if (counter < 8)
//                            GetCaster()->CastSpell(player, SPELL_STAR_SIGN_WOLF, true);
//                        else if (counter < 12)
//                            GetCaster()->CastSpell(player, SPELL_STAR_SIGN_HUNTER, true);
//                        else if (counter < 16)
//                            GetCaster()->CastSpell(player, SPELL_STAR_SIGN_DRAGON, true);
//
//                        ++counter;
//                    }
//                }
//                break;
//            }
//            default:
//                break;
//        }
//    }
//
//    void Register() override
//    {
//        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_augur_grand_conjunction::FilterTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ENEMY);
//    }
//};
//
////205429, 205445, 216344, 216345
//class spell_star_augur_star_sign : public AuraScript
//{
//    PrepareAuraScript(spell_star_augur_star_sign);
//
//    std::list<uint32> StarSignSpell = { SPELL_STAR_SIGN_CRAB, SPELL_STAR_SIGN_WOLF, SPELL_STAR_SIGN_DRAGON, SPELL_STAR_SIGN_HUNTER };
//    uint32 tickTimer = 500;
//
//    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
//    {
//        if (!GetTarget() || GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_EXPIRE)
//            return;
//
//        GetTarget()->CastSpell(GetTarget(), SPELL_GRAND_TRINE, true);
//    }
//
//    //Hack
//    void OnUpdate(AuraEffect const* aurEff)
//    {
//        auto player = GetUnitOwner();
//        if (!player)
//            return;
//
//        std::list<Player*> playerList;
//        player->GetPlayerListInGrid(playerList, 2.0f);
//
//        for (auto const& affectedTarget : playerList)
//        {
//            if (player->GetGUID() == affectedTarget->GetGUID())
//                continue;
//
//            for (auto id : StarSignSpell)
//            {
//                if (GetId() == id && affectedTarget->HasAura(id))
//                {
//                    affectedTarget->RemoveAurasDueToSpell(id);
//                    aurEff->GetBase()->Remove(AURA_REMOVE_BY_DEFAULT);
//                    return;
//                }
//                else if (GetId() != id && affectedTarget->HasAura(id))
//                {
//                    affectedTarget->RemoveAurasDueToSpell(id, ObjectGuid::Empty, 0, AURA_REMOVE_BY_EXPIRE);
//                    aurEff->GetBase()->Remove(AURA_REMOVE_BY_EXPIRE);
//                    return;
//                }
//            }
//        }
//    }
//    
//    void Register() override
//    {
//        OnEffectRemove += AuraEffectRemoveFn(spell_star_augur_star_sign::OnRemove, EFFECT_0, SPELL_AURA_AREA_TRIGGER, AURA_EFFECT_HANDLE_REAL);
//        OnEffectPeriodic += AuraEffectPeriodicFn(spell_star_augur_star_sign::OnUpdate, EFFECT_0, SPELL_AURA_AREA_TRIGGER);
//    }
//};
//
////217054
//class spell_augur_devouring_remnant_filter : public SpellScript
//{
//    PrepareSpellScript(spell_augur_devouring_remnant_filter);
//
//    uint8 count = 0;
//
//    void FilterTargets(std::list<WorldObject*>& targets)
//    {
//        count = targets.size();
//    }
//
//    void HandleDamage(SpellEffIndex /*effIndex*/)
//    {
//        int32 baseDamage = GetSpellInfo()->GetEffect(EFFECT_0)->CalcValue();
//        int32 damage = count ? baseDamage / count : baseDamage;
//        SetHitDamage(damage);
//    }
//
//    void Register() override
//    {
//        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_augur_devouring_remnant_filter::FilterTargets, EFFECT_0, TARGET_UNIT_CASTER);
//        OnEffectHitTarget += SpellEffectFn(spell_augur_devouring_remnant_filter::HandleDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
//    }
//};
//
////217046
//class spell_augur_devouring_remnant : public AuraScript
//{
//    PrepareAuraScript(spell_augur_devouring_remnant);
//
//    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
//    {
//        if (!GetCaster() || !GetTarget() || GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_EXPIRE)
//            return;
//
//        GetCaster()->SetFacingToObject(GetTarget());
//        GetCaster()->CastSpell(GetTarget(), SPELL_DEVOURING_REMNANT_DMG, true);
//    }
//
//    void Register() override
//    {
//        OnEffectRemove += AuraEffectRemoveFn(spell_augur_devouring_remnant::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
//    }
//};
//
////216768
//class spell_augur_fel_ember : public SpellScript
//{
//    PrepareSpellScript(spell_augur_fel_ember);
//    
//    void HandleScript(SpellEffIndex effIndex)
//    {
//        if (!GetCaster() || !GetCaster()->IsInCombat())
//            return;
//
//        /*if (InstanceScript* instance = GetCaster()->GetInstanceScript())
//            if (instance->GetData(DATA_STAR_AUGUR_ETRAEUS_PHASE) != Phase2)
//                return;*/
//
//        WorldLocation* loc = GetHitDest();
//        GetCaster()->CastSpell(loc->GetPosition(), SpellFelFlameAtSpawn, true);
//    }
//    
//    void Register() override
//    {
//        OnEffectHit += SpellEffectFn(spell_augur_fel_ember::HandleScript, EFFECT_0, SPELL_EFFECT_TRIGGER_MISSILE);
//    }
//};
//
////10947
//struct at_augur_absolute_zero : AreaTriggerAI
//{
//    at_augur_absolute_zero(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) {}
//
//    void ActionOnUpdate(GuidList& affectedPlayers)
//    {
//        Unit* caster = at->GetCaster();
//        if (!caster || caster->IsPlayer())
//            return;
//
//        Unit* target = at->GetTarget();
//        if (!target)
//            return;
//
//        if (affectedPlayers.size() > 1)
//        {
//            for (GuidList::iterator itr = affectedPlayers.begin(); itr != affectedPlayers.end(); ++itr)
//            {
//                if (Unit* affectedTarget = ObjectAccessor::GetUnit(*at, *itr))
//                {
//                    if (target->GetGUID() == affectedTarget->GetGUID())
//                        continue;
//
//                    if (affectedTarget->HasAura(SpellChilled))
//                        caster->CastSpell(affectedTarget, SpellFrozenSolid, true);
//                    else
//                        caster->CastSpell(affectedTarget, SpellChilled, true);
//                }
//            }
//            target->RemoveAurasDueToSpell(SpellAbsoluteZero);
//        }
//    }
//};
//
////10797
//struct at_augur_star_sign : AreaTriggerAI
//{
//    at_augur_star_sign(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) {}
//
//    std::list<uint32> StarSignSpell = { SPELL_STAR_SIGN_CRAB, SPELL_STAR_SIGN_WOLF, SPELL_STAR_SIGN_DRAGON, SPELL_STAR_SIGN_HUNTER };
//
//    /* bool IsValidTarget(Unit* caster, Unit* target, AreaTriggerActionMoment actionM) override
//    {
//        auto player = at->GetTarget(); //Player Owner
//        if (!player || !target || player->GetGUID() == target->GetGUID())
//            return false;
//
//        for (auto id : StarSignSpell)
//        {
//            if (at->GetSpellId() == id && target->HasAura(id))
//            {
//                target->RemoveAurasDueToSpell(id);
//                player->RemoveAurasDueToSpell(id);
//                return true;
//            }
//            else if (at->GetSpellId() != id && target->HasAura(id))
//            {
//                target->RemoveAurasDueToSpell(id, ObjectGuid::Empty, 0, AURA_REMOVE_BY_EXPIRE);
//                player->RemoveAurasDueToSpell(at->GetSpellId(), ObjectGuid::Empty, 0, AURA_REMOVE_BY_EXPIRE);
//                return true;
//            }
//        }
//        return false;
//    } */
//
//    void ActionOnUpdate(GuidList& affectedPlayers)
//    {
//        auto player = at->GetTarget();
//        if (!player)
//            return;
//
//        if (affectedPlayers.empty())
//            return;
//
//        for (auto guid : affectedPlayers)
//        {
//            if (auto affectedTarget = ObjectAccessor::GetUnit(*at, guid))
//            {
//                if (player->GetGUID() == affectedTarget->GetGUID())
//                    continue;
//
//                for (auto id : StarSignSpell)
//                {
//                    if (at->GetSpellId() == id && affectedTarget->HasAura(id))
//                    {
//                        affectedTarget->RemoveAurasDueToSpell(id);
//                        player->RemoveAurasDueToSpell(id);
//                        return;
//                    }
//                    else if (at->GetSpellId() != id && affectedTarget->HasAura(id))
//                    {
//                        affectedTarget->RemoveAurasDueToSpell(id, ObjectGuid::Empty, 0, AURA_REMOVE_BY_EXPIRE);
//                        player->RemoveAurasDueToSpell(at->GetSpellId(), ObjectGuid::Empty, 0, AURA_REMOVE_BY_EXPIRE);
//                        return;
//                    }
//                }
//            }
//        }
//    }
//};
//
//void AddSC_boss_star_augur_etraeus()
//{
//    RegisterCreatureAI(boss_star_augur_etraeus);
//    RegisterCreatureAI(npc_coronal_ejection);
//    RegisterCreatureAI(npc_star_augur_thing_that_should_not_be);
//    RegisterCreatureAI(npc_augur_voidling);
//    RegisterCreatureAI(npc_augur_eye_of_the_void);
//    RegisterCreatureAI(npc_augur_remnant_of_the_void);
//    RegisterAuraScript(spell_star_augur_gravity_pull);
//    RegisterAuraScript(spell_star_augur_icy_ejection);
//    RegisterSpellAndAuraScriptPair(spell_star_augur_fel_ejection_filter, spell_star_augur_fel_ejection);
//    RegisterSpellScript(spell_star_augur_etraeus_fel_impact);
//    RegisterAuraScript(spell_star_augur_void_ejection_aura);
//    RegisterSpellScript(spell_star_augur_void_burst);
//    RegisterSpellScript(spell_star_augur_frigid_nova_dmg_trigger);
//    RegisterSpellScript(spell_star_augur_fel_nova_dmg);
//    RegisterSpellScript(spell_augur_witness_the_void);
//    RegisterSpellScript(spell_augur_grand_conjunction);
//    RegisterAuraScript(spell_star_augur_star_sign);
//    RegisterSpellScript(spell_augur_devouring_remnant_filter);
//    RegisterAuraScript(spell_augur_devouring_remnant);
//    RegisterSpellScript(spell_augur_fel_ember);
//    RegisterAreaTriggerAI(at_augur_absolute_zero);
//    //RegisterAreaTriggerAI(at_augur_star_sign);
//}
