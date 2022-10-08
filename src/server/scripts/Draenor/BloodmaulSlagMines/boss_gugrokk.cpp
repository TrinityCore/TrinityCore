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
#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "SpellScript.h"
#include "SpellAuras.h"
#include "instance_bloodmaul.h"

namespace Instances { namespace Bloodmaul
{
    /// Gug'rokk <Bloodmaul Slave Traders> - 74790
    class boss_gugrokk : public CreatureScript
    {
        public:
            boss_gugrokk() : CreatureScript("boss_gugrokk") { }

            enum eSpells
            {
                /// Magma Eruption
                SpellMagmaEruptionDummy     = 150776,   ///< 3s cast on self
                SpellMagmaEruptionVisual    = 150777,   ///< Magma visual on 74967

                /// Flame Buffet - Only in Heroic
                SpellFlameBuffet            = 163802,

                /// Molten Blast
                SpellMoltenBlast            = 150677,
                SpellMoltenCore             = 150678,
                SpellMoltenBarrage          = 150682,

                /// Summon Unstable Slag
                SpellSummonUnstableSlag     = 150755    ///< 1.5s cast and summon 74927
            };

            enum eEvents
            {
                EventMagmaEruption = 1,
                EventFlameBuffet,   ///< Only in Heroic
                EventMoltenBlast,
                EventSummonUnstableSlag
            };

            enum eTalks
            {
                TalkIntro,
                TalkAggro,
                TalkMagmaEruption,
                TalkUnstableSlag,
                TalkSlay,
                TalkDeath
            };

            enum eCreatures
            {
                NpcMagmaEruption    = 74967,
                NpcUnstableSlag     = 74927
            };

            enum eEquips
            {
                MainEquipID = 107424
            };

            struct boss_gugrokkAI : public BossAI
            {
                boss_gugrokkAI(Creature* creature) : BossAI(creature, BossIds::BossGugrokk)
                {
                    m_Instance = creature->GetInstanceScript();
                }

                InstanceScript* m_Instance;
                EventMap m_Events;

                void Reset() override
                {
                    m_Events.Reset();

                    _Reset();

                    summons.DespawnAll();

                    if (m_Instance != nullptr)
                        m_Instance->SendEncounterUnit(EncounterFrameType::ENCOUNTER_FRAME_DISENGAGE, me);

                    //me->RemoveAllAreaTriggers();

                    SetEquipmentSlots(false, eEquips::MainEquipID);
                }

                void JustDied(Unit*) override
                {
                    _JustDied();

                    summons.DespawnAll();

                    //me->RemoveAllAreaTriggers();

                    if (m_Instance != nullptr)
                        m_Instance->SendEncounterUnit(EncounterFrameType::ENCOUNTER_FRAME_DISENGAGE, me);

                    Talk(eTalks::TalkDeath);
                }

                void EnterCombat(Unit*) override
                {
                    _EnterCombat();

                    if (m_Instance != nullptr)
                        m_Instance->SendEncounterUnit(EncounterFrameType::ENCOUNTER_FRAME_ENGAGE, me);

                    Talk(eTalks::TalkAggro);

                    if (IsHeroic())
                        m_Events.ScheduleEvent(eEvents::EventFlameBuffet, 6 * TimeConstants::IN_MILLISECONDS);

                    m_Events.ScheduleEvent(eEvents::EventMagmaEruption, 7 * TimeConstants::IN_MILLISECONDS);
                    m_Events.ScheduleEvent(eEvents::EventMoltenBlast, 1 * TimeConstants::IN_MILLISECONDS);
                    m_Events.ScheduleEvent(eEvents::EventSummonUnstableSlag, 20 * TimeConstants::IN_MILLISECONDS);
                }

                void KilledUnit(Unit* killed) override
                {
                    if (killed->IsPlayer())
                        Talk(eTalks::TalkSlay);
                }

                void SpellHitTarget(Unit* target, SpellInfo const* spellInfo) override
                {
                    if (target == nullptr)
                        return;

                    switch (spellInfo->Id)
                    {
                        case eSpells::SpellMoltenBlast:
                        {
                            me->CastSpell(me, eSpells::SpellMoltenCore, true);

                            if (Aura* l_MoltenCore = me->GetAura(eSpells::SpellMoltenCore))
                            {
                                if (l_MoltenCore->GetStackAmount() >= 3)
                                {
                                    me->CastSpell(me, eSpells::SpellMoltenBarrage, true);
                                    me->RemoveAura(eSpells::SpellMoltenCore);
                                    //me->TextEmote(LangGugrokkWarnMoltenBarrage, 0, true);
                                }
                            }
                            break;
                        }
                        default:
                            break;
                    }
                }

                void JustSummoned(Creature* summon) override
                {
                    BossAI::JustSummoned(summon);

                    if (summon->GetEntry() == eCreatures::NpcUnstableSlag && summon->AI())
                    {
                        std::list<Creature*> l_SLGList;
                        me->GetCreatureListWithEntryInGrid(l_SLGList, MobEntries::SLGGenricMoPLargeAoI, 150.0f);

                        if (l_SLGList.empty())
                            return;

                        l_SLGList.sort(Trinity::ObjectDistanceOrderPred(summon, false));
                        summon->AI()->SetGUID(l_SLGList.front()->GetGUID());
                    }
                }

                void UpdateAI(uint32 const diff) override
                {
                    if (!UpdateVictim())
                        return;

                    m_Events.Update(diff);

                    if (me->HasUnitState(UnitState::UNIT_STATE_CASTING))
                        return;

                    switch (m_Events.ExecuteEvent())
                    {
                        case eEvents::EventMagmaEruption:
                        {
                            Talk(eTalks::TalkMagmaEruption);
                            me->CastSpell(me, eSpells::SpellMagmaEruptionDummy, false);
                            m_Events.ScheduleEvent(eEvents::EventMagmaEruption, 28 * TimeConstants::IN_MILLISECONDS);

                            std::list<Player*> playerList;
                            me->GetPlayerListInGrid(playerList, 100.0f);

                            for (Player* player : playerList)
                            {
                                Position pos = player->GetPosition();

                                if (Creature* l_MagmaEruption = me->SummonCreature(eCreatures::NpcMagmaEruption, pos))
                                    l_MagmaEruption->CastSpell(l_MagmaEruption, eSpells::SpellMagmaEruptionVisual, true);
                            }

                            break;
                        }
                        case eEvents::EventFlameBuffet:
                            me->CastSpell(me, eSpells::SpellFlameBuffet, false);
                            m_Events.ScheduleEvent(eEvents::EventFlameBuffet, 12 * TimeConstants::IN_MILLISECONDS);
                            break;
                        case eEvents::EventMoltenBlast:
                            if (Unit* target = SelectTarget(SelectAggroTarget::SELECT_TARGET_RANDOM))
                                me->CastSpell(target, eSpells::SpellMoltenBlast, false);
                            m_Events.ScheduleEvent(eEvents::EventMoltenBlast, 16 * TimeConstants::IN_MILLISECONDS);
                            break;
                        case eEvents::EventSummonUnstableSlag:
                            me->CastSpell(me, eSpells::SpellSummonUnstableSlag, false);
                            Talk(eTalks::TalkUnstableSlag);
                            m_Events.ScheduleEvent(eEvents::EventSummonUnstableSlag, 25 * TimeConstants::IN_MILLISECONDS);
                            break;
                        default:
                            break;
                    }

                    DoMeleeAttackIfReady();
                }
            };

            CreatureAI* GetAI(Creature* creature) const override
            {
                return new boss_gugrokkAI(creature);
            }
    };

    /// Magma Eruption - 74967
    class npc_gugrokk_magma_eruption : public CreatureScript
    {
        public:
            npc_gugrokk_magma_eruption() : CreatureScript("npc_gugrokk_magma_eruption") { }

            struct npc_gugrokk_magma_eruptionAI : public ScriptedAI
            {
                npc_gugrokk_magma_eruptionAI(Creature* creature) : ScriptedAI(creature) { }

                enum eSpells
                {
                    SpellMagmaEruptionAura  = 150783,
                    SpellPeriodicDamage     = 150784
                };

                enum eEvents
                {
                    EventCheckPlayers = 1,
                    EventDespawn,
                    EventActivate
                };

                EventMap m_Events;

                void Reset() override
                {
                    m_Events.ScheduleEvent(eEvents::EventActivate, 3 * TimeConstants::IN_MILLISECONDS);
                    m_Events.ScheduleEvent(eEvents::EventDespawn, 2 * TimeConstants::MINUTE * TimeConstants::IN_MILLISECONDS);

                    me->SetReactState(ReactStates::REACT_PASSIVE);
                    me->AddUnitFlag(UnitFlags(UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE));
                }

                void UpdateAI(uint32 const diff) override
                {
                    m_Events.Update(diff);

                    switch (m_Events.ExecuteEvent())
                    {
                        case eEvents::EventCheckPlayers:
                        {
                            std::list<Player*> playerList;
                            me->GetPlayerListInGrid(playerList, 3.0f);

                            for (Player* player : playerList)
                                me->CastSpell(player, eSpells::SpellPeriodicDamage, true);

                            m_Events.ScheduleEvent(eEvents::EventCheckPlayers, 1 * TimeConstants::IN_MILLISECONDS);
                            break;
                        }
                        case eEvents::EventDespawn:
                            me->DespawnOrUnsummon();
                            break;
                        case eEvents::EventActivate:
                            me->CastSpell(me, eSpells::SpellMagmaEruptionAura, true);
                            m_Events.ScheduleEvent(eEvents::EventCheckPlayers, 100);
                            break;
                        default:
                            break;
                    }
                }
            };

            CreatureAI* GetAI(Creature* creature) const override
            {
                return new npc_gugrokk_magma_eruptionAI(creature);
            }
    };

    /// Unstable Slag - 74927
    class npc_gugrokk_unstable_slag : public CreatureScript
    {
        public:
            npc_gugrokk_unstable_slag() : CreatureScript("npc_gugrokk_unstable_slag") { }

            struct npc_gugrokk_unstable_slagAI : public ScriptedAI
            {
                npc_gugrokk_unstable_slagAI(Creature* creature) : ScriptedAI(creature) { }

                enum eSpells
                {
                    SpellEnslaveSlag        = 150756,   ///< Spawn visual
                    SpellSiphonFlames       = 150732,   ///< Fire channel to SLG
                    SpellEmpoweredFlames    = 152091
                };

                enum eEvents
                {
                    EventCheckSLG = 1
                };

                EventMap m_Events;

                ObjectGuid m_FollowingSLG;

                void Reset() override
                {
                    me->SetReactState(ReactStates::REACT_PASSIVE);

                    m_Events.ScheduleEvent(eEvents::EventCheckSLG, 1 * TimeConstants::IN_MILLISECONDS);

                    me->SetSpeed(UnitMoveType::MOVE_WALK, 0.7f);
                    me->SetSpeed(UnitMoveType::MOVE_RUN, 0.7f);
                }

                void SetGUID(ObjectGuid guid, int32 /*id*/) override
                {
                    m_FollowingSLG = guid;

                    if (Creature* l_SLG = ObjectAccessor::GetCreature(*me, m_FollowingSLG))
                    {
                        me->CastSpell(l_SLG, eSpells::SpellSiphonFlames, false);
                        me->GetMotionMaster()->MoveChase(l_SLG, 2.5f);
                    }
                }

                void UpdateAI(uint32 const diff) override
                {
                    m_Events.Update(diff);

                    switch (m_Events.ExecuteEvent())
                    {
                        case eEvents::EventCheckSLG:
                        {
                            if (Creature* l_SLG = ObjectAccessor::GetCreature(*me, m_FollowingSLG))
                            {
                                if (me->GetDistance(l_SLG) > 3.0f)
                                {
                                    me->CastSpell(l_SLG, eSpells::SpellSiphonFlames, false);
                                    me->GetMotionMaster()->MoveChase(l_SLG, 2.5f);
                                    m_Events.ScheduleEvent(eEvents::EventCheckSLG, 1 * TimeConstants::IN_MILLISECONDS);
                                    break;
                                }
                            }
                            else
                                break;

                            me->CastSpell(me, eSpells::SpellEmpoweredFlames, true);
                            me->SetReactState(ReactStates::REACT_AGGRESSIVE);

                            if (Unit* target = me->SelectNearestPlayer(60.0f))
                                AttackStart(target);

                            m_FollowingSLG = ObjectGuid::Empty;
                            break;
                        }
                        default:
                            break;
                    }

                    if (!m_FollowingSLG && me->GetReactState() == ReactStates::REACT_AGGRESSIVE)
                        DoMeleeAttackIfReady();
                }
            };

            CreatureAI* GetAI(Creature* creature) const override
            {
                return new npc_gugrokk_unstable_slagAI(creature);
            }
    };
}
} ///< namespace Instances

void AddSC_boss_gugrokk()
{
    new Instances::Bloodmaul::boss_gugrokk();
    new Instances::Bloodmaul::npc_gugrokk_magma_eruption();
    new Instances::Bloodmaul::npc_gugrokk_unstable_slag();
}
