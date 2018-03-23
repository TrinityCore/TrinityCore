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

#include "instance_bloodmaul.h"

namespace Instances { namespace Bloodmaul
{
    /// Slagna - 75406
    class mob_Slagna : public CreatureScript
    {
        public:
            mob_Slagna() : CreatureScript("mob_Slagna") { }

            enum class Spells : uint32
            {
                SubmergeVisual  = 139832,
                LavaSpit        = 152183
            };

            enum class Events : uint32
            {
                LavaSpit = 1
            };

            CreatureAI* GetAI(Creature* p_Creature) const override
            {
                return new mob_AI(p_Creature);
            }

            struct mob_AI : public ScriptedAI
            {
                mob_AI(Creature* p_Creature) : ScriptedAI(p_Creature)
                {
                    me->AddAura(uint32(Spells::SubmergeVisual), me);
                }

                void Reset() override
                {
                    events.Reset();

                    me->AddUnitState(UNIT_STATE_ROOT);
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_UNK_6 | UNIT_FLAG_UNK_15 | UNIT_FLAG_NOT_SELECTABLE);
                }

                void SetData(uint32 p_Type, uint32) override
                {
                    if (p_Type == uint32(Data::SpawnSlagna))
                    {
                        me->RemoveAura(uint32(Spells::SubmergeVisual));
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_UNK_6 | UNIT_FLAG_UNK_15 | UNIT_FLAG_NOT_SELECTABLE);

                        if (Unit* l_Target = me->SelectNearestPlayer(20.0f))
                            AttackStart(l_Target);
                    }
                }

                void EnterCombat(Unit*) override
                {
                    me->RemoveAura(uint32(Spells::SubmergeVisual));
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_UNK_6 | UNIT_FLAG_UNK_15 | UNIT_FLAG_NOT_SELECTABLE);

                    events.ScheduleEvent(uint32(Events::LavaSpit), urand(2000, 2500));
                }

                void UpdateAI(const uint32 p_Diff) override
                {
                    if (!UpdateVictim())
                        return;

                    events.Update(p_Diff);

                    if (me->HasUnitState(UNIT_STATE_CASTING) || me->GetCurrentSpell(CurrentSpellTypes::CURRENT_CHANNELED_SPELL))
                        return;

                    switch (events.ExecuteEvent())
                    {
                        case uint32(Events::LavaSpit):
                            if (Unit* l_Plr = SelectTarget(SELECT_TARGET_RANDOM, 0))
                                me->CastSpell(l_Plr, uint32(Spells::LavaSpit));
                            events.ScheduleEvent(uint32(Events::LavaSpit), urand(2000, 2500));
                            break;
                        default:
                            break;
                    }

                    DoMeleeAttackIfReady();
                }
            };
    };

    /// Captured Miner - 74355
    class mob_CapturedMiner : public CreatureScript
    {
        public:
            mob_CapturedMiner() : CreatureScript("mob_CapturedMiner") { }

            CreatureAI* GetAI(Creature* p_Creature) const override
            {
                return new mob_AI(p_Creature);
            }

            enum eEvents
            {
                EventTraumaticStrike = 1
            };

            enum eSpells
            {
                SpellTraumaticStrike = 151092
            };

            struct mob_AI : public ScriptedAI
            {
                mob_AI(Creature* p_Creature) : ScriptedAI(p_Creature)
                {
                    me->SetUInt32Value(UNIT_FIELD_FLAGS, 0);
                }

                EventMap m_Events;

                void EnterCombat(Unit* p_Target) override
                {
                    me->getThreatManager().addThreat(p_Target, 1000.0f);

                    m_Events.Reset();

                    m_Events.ScheduleEvent(eEvents::EventTraumaticStrike, 4000);
                }

                void UpdateAI(const uint32 p_Diff) override
                {
                    if (!UpdateVictim())
                        return;

                    m_Events.Update(p_Diff);

                    switch (m_Events.ExecuteEvent())
                    {
                        case eEvents::EventTraumaticStrike:
                            DoCastVictim(eSpells::SpellTraumaticStrike);
                            break;
                        default:
                            break;
                    }

                    DoMeleeAttackIfReady();
                }
            };
    };

    /// Bloodmaul Ogre Mage - 75272
    class mob_BloodmaulOgreMage : public CreatureScript
    {
        public:
            mob_BloodmaulOgreMage() : CreatureScript("mob_BloodmaulOgreMage") { }

            enum class Spells : uint32
            {
                LavaBurst = 151558,
                BloodRage = 151548
            };

            enum class Events : uint32
            {
                BloodRage = 1
            };

            CreatureAI* GetAI(Creature* p_Creature) const override
            {
                return new mob_AI(p_Creature);
            }

            struct mob_AI : public ScriptedAI
            {
                mob_AI(Creature* p_Creature) : ScriptedAI(p_Creature) { }

                void Reset() override
                {
                    events.Reset();
                }

                void AttackStart(Unit* victim) override
                {
                    AttackStartCaster(victim, 15.0f);
                }

                void EnterCombat(Unit*) override
                {
                    events.ScheduleEvent(uint32(Events::BloodRage), urand(10000, 12000));
                }

                void UpdateAI(const uint32 p_Diff) override
                {
                    if (!UpdateVictim())
                        return;

                    events.Update(p_Diff);

                    if (me->HasUnitState(UNIT_STATE_CASTING) || me->GetCurrentSpell(CurrentSpellTypes::CURRENT_CHANNELED_SPELL))
                        return;

                    switch (events.ExecuteEvent())
                    {
                        case uint32(Events::BloodRage):
                            me->CastSpell(me, uint32(Spells::BloodRage));
                            events.ScheduleEvent(uint32(Events::BloodRage), urand(10000, 12000));
                            break;
                        default:
                            break;
                    }

                    DoSpellAttackIfReady((uint32)Spells::LavaBurst);
                }
            };
    };

    /// Bloodmaul Warder - 75210
    class mob_BloodmaulWarder : public CreatureScript
    {
        public:
            mob_BloodmaulWarder() : CreatureScript("mob_BloodmaulWarder") { }

            enum class Spells : uint32
            {
                Cleave          = 40505,
                FrighteningRoar = 151545
            };

            enum class Events : uint32
            {
                Cleave = 1,
                FrighteningRoar
            };

            CreatureAI* GetAI(Creature* p_Creature) const override
            {
                return new mob_AI(p_Creature);
            }

            struct mob_AI : public ScriptedAI
            {
                mob_AI(Creature* p_Creature) : ScriptedAI(p_Creature) { }

                void Reset() override
                {
                    events.Reset();
                }

                void EnterCombat(Unit*) override
                {
                    events.ScheduleEvent(uint32(Events::Cleave), urand(500, 1500));
                    events.ScheduleEvent(uint32(Events::FrighteningRoar), urand(14000, 16000));
                }

                void UpdateAI(const uint32 p_Diff) override
                {
                    if (!UpdateVictim())
                        return;

                    events.Update(p_Diff);

                    if (me->HasUnitState(UNIT_STATE_CASTING) || me->GetCurrentSpell(CurrentSpellTypes::CURRENT_CHANNELED_SPELL))
                        return;

                    switch (events.ExecuteEvent())
                    {
                        case uint32(Events::Cleave):
                            me->CastSpell(me->GetVictim(), uint32(Spells::Cleave));
                            events.ScheduleEvent(uint32(Events::Cleave), urand(7500, 9500));
                            break;
                        case uint32(Events::FrighteningRoar):
                            me->CastSpell(me, uint32(Spells::FrighteningRoar));
                            events.ScheduleEvent(uint32(Events::FrighteningRoar), urand(26000, 29000));
                            break;
                        default:
                            break;
                    }

                    DoMeleeAttackIfReady();
                }
            };
    };

    /// Bloodmaul Geomancer - 75198
    class mob_BloodmaulGeomancer : public CreatureScript
    {
        public:
            mob_BloodmaulGeomancer() : CreatureScript("mob_BloodmaulGeomancer") { }

            enum class Spells : uint32
            {
                StoneBolt       = 164592,
                StoneBulwark    = 164597
            };

            enum class Events : uint32
            {
                StoneBulwark = 1
            };

            CreatureAI* GetAI(Creature* p_Creature) const override
            {
                return new mob_AI(p_Creature);
            }

            struct mob_AI : public ScriptedAI
            {
                mob_AI(Creature* p_Creature) : ScriptedAI(p_Creature) { }

                void Reset() override
                {
                    events.Reset();
                }

                void AttackStart(Unit* victim) override
                {
                    AttackStartCaster(victim, 15.0f);
                }

                void EnterCombat(Unit*) override
                {
                    events.ScheduleEvent(uint32(Events::StoneBulwark), urand(6000, 7000));
                }

                void UpdateAI(const uint32 p_Diff) override
                {
                    if (!UpdateVictim())
                        return;

                    events.Update(p_Diff);

                    if (me->HasUnitState(UNIT_STATE_CASTING) || me->GetCurrentSpell(CurrentSpellTypes::CURRENT_CHANNELED_SPELL))
                        return;

                    switch (events.ExecuteEvent())
                    {
                        case uint32(Events::StoneBulwark):
                        {
                            Unit* l_Target = me;
                            /*if (Unit* l_Unit = MS::ScriptUtils::SelectNearestFriendExcluededMe(me, 40.0f))
                            {
                                if (l_Unit->IsInCombat())
                                    l_Target = l_Unit;
                            }*/
                            
                            me->CastSpell(l_Target, uint32(Spells::StoneBulwark));

                            events.ScheduleEvent(uint32(Events::StoneBulwark), urand(3000, 35000));
                            break;
                        }
                        default:
                            break;
                    }

                    DoSpellAttackIfReady((uint32)Spells::StoneBolt);
                }
            };
    };

    /// Bloodmaul Overseer - 75426
    class mob_BloodmaulOverseer : public CreatureScript
    {
        public:
            mob_BloodmaulOverseer() : CreatureScript("mob_BloodmaulOverseer") { }

            enum class Spells : uint32
            {
                SuppresionField = 151581,
                Subjugate       = 151697
            };

            enum class Events : uint32
            {
                SuppresionField = 1,
                Subjugate,

                EVENT_OVERSEER_TEXT,
                EVENT_SLAVE_NO,
                EVENT_LAUGH,
                EVENT_MOVE
            };

            enum class Texts : uint32
            {
                TEXT_SLAVE_MERCY = 0,
                TEXT_SLAVE_NO = 1,

                TEXT_OVERSEER       = 0
            };

            enum class Npcs : uint32
            {
                NPC_ENSLAVED_MINER  = 75427
            };

            CreatureAI* GetAI(Creature* p_Creature) const override
            {
                return new mob_AI(p_Creature);
            }

            // Todo : more research on vehicle
            struct mob_AI : public ScriptedAI
            {
                mob_AI(Creature* p_Creature) : ScriptedAI(p_Creature) { }

                bool eventStarted = false;
                ObjectGuid slaveGuid;

                void Reset() override
                {
                    events.Reset();

                    if (me->GetEntry() != MobEntries::BloodmaulOverseer)
                        return;

                    if (!eventStarted)
                    {
                        //Position pos = me->GetPosition();
                        Position pos = { 1892.26f, -217.18f, 239.85f, 1.687212f };
                        if (Creature* enslavedMiner = me->SummonCreature((uint32)Npcs::NPC_ENSLAVED_MINER, pos))
                        {
                            slaveGuid = enslavedMiner->GetGUID();
                            //enslavedMiner->EnterVehicle(me, -1);
                        }
                    }

                    me->SetWalk(true);

                    std::list<Creature*> creatureList;
                    me->GetCreatureListWithEntryInGrid(creatureList, 75191, 10.0f);

                    for (auto creature : creatureList)
                    {
                        creature->SetWalk(true);
                    }
                }

                void DoAction(const int32 action) override
                {
                    if (me->GetEntry() != MobEntries::BloodmaulOverseer)
                        return;

                    if (eventStarted)
                        return;

                    eventStarted = true;

                    if (Creature* enslavedMiner = me->GetMap()->GetCreature(slaveGuid))
                        if (enslavedMiner->IsAIEnabled)
                            enslavedMiner->AI()->Talk((uint32)Texts::TEXT_SLAVE_MERCY);

                    events.ScheduleEvent((uint32)Events::EVENT_OVERSEER_TEXT,   2000);
                    events.ScheduleEvent((uint32)Events::EVENT_SLAVE_NO,        4000);
                    events.ScheduleEvent((uint32)Events::EVENT_LAUGH,           5000);
                    events.ScheduleEvent((uint32)Events::EVENT_MOVE,            7000);
                }

                void EnterCombat(Unit*) override
                {
                    events.ScheduleEvent(uint32(Events::SuppresionField), urand(500, 1500));
                    events.ScheduleEvent(uint32(Events::Subjugate), urand(15000, 17000));
                }

                void UpdateAI(const uint32 p_Diff) override
                {
                    events.Update(p_Diff);

                    uint32 eventId = events.ExecuteEvent();

                    if (DoSlaveEvent(eventId))
                        return;

                    if (!UpdateVictim())
                        return;

                    if (me->HasUnitState(UNIT_STATE_CASTING) || me->GetCurrentSpell(CurrentSpellTypes::CURRENT_CHANNELED_SPELL))
                        return;

                    switch (eventId)
                    {
                        case uint32(Events::SuppresionField):
                        {
                            if (Unit* l_Plr = SelectTarget(SELECT_TARGET_RANDOM, 0))
                                me->CastSpell(l_Plr, uint32(Spells::SuppresionField));
                            events.ScheduleEvent(uint32(Events::SuppresionField), urand(16000, 18000));
                            break;
                        }
                        case uint32(Events::Subjugate):
                        {
                            me->CastSpell(me->GetVictim(), uint32(Spells::Subjugate));
                            events.ScheduleEvent(uint32(Events::Subjugate), urand(21000, 24000));
                            break;
                        }
                        default:
                            break;
                    }

                    DoMeleeAttackIfReady();
                }

                bool DoSlaveEvent(uint32 eventId)
                {
                    switch (eventId)
                    {
                        case (uint32)Events::EVENT_OVERSEER_TEXT:
                        {
                            Talk((uint32)Texts::TEXT_OVERSEER);
                            return true;
                        }
                        case (uint32)Events::EVENT_SLAVE_NO:
                        {
                            if (Creature* enslavedMiner = me->GetMap()->GetCreature(slaveGuid))
                            {
                                //enslavedMiner->ExitVehicle();
                                enslavedMiner->GetMotionMaster()->MoveKnockbackFrom(me->GetPositionX(), me->GetPositionY(), 10.0f, 10.0f);
                                if (enslavedMiner->IsAIEnabled)
                                    enslavedMiner->AI()->Talk((uint32)Texts::TEXT_SLAVE_NO);
                                enslavedMiner->DespawnOrUnsummon(1000);
                            }
                            return true;
                        }
                        case (uint32)Events::EVENT_LAUGH:
                        {
                            me->HandleEmoteCommand(EMOTE_ONESHOT_LAUGH);

                            std::list<Creature*> creatureList;
                            me->GetCreatureListWithEntryInGrid(creatureList, 75191, 10.0f);

                            for (auto creature : creatureList)
                            {
                                creature->HandleEmoteCommand(EMOTE_ONESHOT_LAUGH);
                            }

                            return true;
                        }
                        case (uint32)Events::EVENT_MOVE:
                        {
                            Position middlePos = { 1904.01f, -207.57f, 239.71f };
                            me->GetMotionMaster()->MovePoint(1, middlePos);

                            std::list<Creature*> creatureList;
                            me->GetCreatureListWithEntryInGrid(creatureList, 75191, 10.0f);

                            for (auto creature : creatureList)
                            {
                                if (creature->GetPositionX() > 1890.0f) // Gauche
                                    creature->GetMotionMaster()->MoveFollow(me, 1.0f, 2.355f);
                                else // Droite
                                    creature->GetMotionMaster()->MoveFollow(me, 1.0f, 3.925f);
                            }
                            return true;
                        }
                    }

                    return false;
                }

                void MovementInform(uint32 p_Type, uint32 p_Id) override
                {
                    if (p_Type != POINT_MOTION_TYPE)
                        return;

                    switch (p_Id)
                    {
                        case 1:
                        {
                            Position pos = { 1974.75f, -205.12f, 243.28f };
                            me->GetMotionMaster()->MovePoint(2, pos);
                            break;
                        }
                        case 2:
                        {
                            Position pos = { 1963.60f, -205.03f, 243.3865f };
                            me->GetMotionMaster()->MovePoint(3, pos);

                            std::list<Creature*> creatureList;
                            me->GetCreatureListWithEntryInGrid(creatureList, 75191, 10.0f);

                            for (auto creature : creatureList)
                            {
                                creature->GetMotionMaster()->Clear();
                            }
                            break;
                        }
                    }
                }
            };
    };

    /// Bloodmaul Slaver - 75191
    class mob_BloodmaulSlaver : public CreatureScript
    {
        public:
            mob_BloodmaulSlaver() : CreatureScript("mob_BloodmaulSlaver") { }

            enum class Spells : uint32
            {
                ChainGrip   = 151990,
                SlaversRage = 151965,
                ShockBola   = 152073
            };

            enum class Events : uint32
            {
                ChainGrip = 1,
                SlaversRage,
                ShockBola
            };

            CreatureAI* GetAI(Creature* p_Creature) const override
            {
                return new mob_AI(p_Creature);
            }

            struct mob_AI : public ScriptedAI
            {
                mob_AI(Creature* p_Creature) : ScriptedAI(p_Creature) { }

                void Reset() override
                {
                    events.Reset();
                }

                void EnterCombat(Unit*) override
                {
                    events.ScheduleEvent(uint32(Events::ChainGrip), urand(500, 1500));
                    events.ScheduleEvent(uint32(Events::ShockBola), urand(15000, 17000));
                    events.ScheduleEvent(uint32(Events::SlaversRage), 6000);
                }

                void UpdateAI(const uint32 p_Diff) override
                {
                    if (!UpdateVictim())
                        return;

                    events.Update(p_Diff);

                    if (me->HasUnitState(UNIT_STATE_CASTING))
                        return;

                    switch (events.ExecuteEvent())
                    {
                        case uint32(Events::ChainGrip):
                            if (Unit* l_Plr = SelectTarget(SELECT_TARGET_FARTHEST, 0, 5.0f))
                                me->CastSpell(l_Plr, uint32(Spells::ChainGrip));
                            events.ScheduleEvent(uint32(Events::ChainGrip), urand(16000, 18000));
                            break;
                        case uint32(Events::SlaversRage):
                            me->CastSpell(me->GetVictim(), uint32(Spells::SlaversRage));
                            events.ScheduleEvent(uint32(Events::SlaversRage), urand(21000, 24000));
                            break;
                        case uint32(Events::ShockBola):
                            if (Unit* l_Plr = SelectTarget(SELECT_TARGET_RANDOM, 0, 15.0f))
                                me->CastSpell(l_Plr, uint32(Spells::ShockBola));
                            events.ScheduleEvent(uint32(Events::ShockBola), urand(15000, 17000));
                            break;
                        default:
                            break;
                    }

                    DoMeleeAttackIfReady();
                }
            };
    };

    /// Bloodmaul Enforcer - 84978
    class mob_BloodmaulEnforcer : public CreatureScript
    {
        public:
            mob_BloodmaulEnforcer() : CreatureScript("mob_BloodmaulEnforcer") { }

            enum class Spells : uint32
            {
                Beatdown            = 151415,
                Crush               = 151447,
                LumberingLeap       = 151542,
                LumberingLeapDmg    = 151541
            };

            enum class Events : uint32
            {
                Beatdown = 1,
                Crush,
                LumberingLeap
            };

            CreatureAI* GetAI(Creature* p_Creature) const override
            {
                return new mob_AI(p_Creature);
            }

            struct mob_AI : public ScriptedAI
            {
                mob_AI(Creature* p_Creature) : ScriptedAI(p_Creature) { }

                void Reset() override
                {
                    events.Reset();

                    m_TargetGUID = ObjectGuid::Empty;
                }

                void EnterCombat(Unit*) override
                {
                    events.ScheduleEvent(uint32(Events::Beatdown), urand(500, 1500));
                    events.ScheduleEvent(uint32(Events::Crush), urand(4500, 5500));
                    events.ScheduleEvent(uint32(Events::LumberingLeap), urand(15000, 17000));
                }

                void MovementInform(uint32 p_Type, uint32 p_Id) override
                {
                    switch (p_Type)
                    {
                        case EFFECT_MOTION_TYPE:
                            if (Player* l_Plr = ObjectAccessor::FindPlayer(m_TargetGUID))
                            {
                                me->CastSpell(l_Plr, uint32(Spells::LumberingLeapDmg));
                                m_TargetGUID = ObjectGuid::Empty;

                                std::list<Player*> players = me->SelectNearestPlayers(200.0f, true);
                                for (Player* player : players)
                                    if (me->GetExactDist2d(player) <= 5.0f)
                                        player->GetMotionMaster()->MoveKnockbackFrom(me->GetPositionX(), me->GetPositionY(), 2.0f, 2.0f);
                            }
                            break;
                    }
                }

                void UpdateAI(const uint32 p_Diff) override
                {
                    if (!UpdateVictim())
                        return;

                    events.Update(p_Diff);

                    if (me->HasUnitState(UNIT_STATE_CASTING))
                        return;

                    switch (events.ExecuteEvent())
                    {
                        case uint32(Events::Beatdown):
                            me->CastSpell(me->GetVictim(), uint32(Spells::Beatdown));
                            events.ScheduleEvent(uint32(Events::Beatdown), urand(22000, 26000));
                            break;
                        case uint32(Events::Crush):
                            me->CastSpell(me->GetVictim(), uint32(Spells::Crush));
                            events.ScheduleEvent(uint32(Events::Crush), urand(10000, 11000));
                            break;
                        case uint32(Events::LumberingLeap):
                            if (Unit* l_Plr = SelectTarget(SELECT_TARGET_FARTHEST, 0, 8.0f))
                            {
                                m_TargetGUID = l_Plr->GetGUID();
                                me->CastSpell(l_Plr, uint32(Spells::LumberingLeap));
                            }
                            events.ScheduleEvent(uint32(Events::LumberingLeap), urand(15000, 17000));
                            break;
                        default:
                            break;
                    }

                    DoMeleeAttackIfReady();
                }

                ObjectGuid m_TargetGUID;
            };
    };

    /// Bloodmaul Ogron - 81750
    class mob_bloodmaul_ogron : public CreatureScript
    {
        public:
            mob_bloodmaul_ogron() : CreatureScript("mob_bloodmaul_ogron") { }

            struct mob_bloodmaul_ogronAI : public ScriptedAI
            {
                mob_bloodmaul_ogronAI(Creature* p_Creature) : ScriptedAI(p_Creature) { }

                enum eSpells
                {
                    SpellColossalRoar = 164582,
                    SpellMassiveStomp = 164587
                };

                enum eEvents
                {
                    EventColossalRoar = 1,
                    EventMassiveStomp
                };

                EventMap m_Events;

                void Reset() override
                {
                    m_Events.Reset();
                }

                void EnterCombat(Unit*) override
                {
                    m_Events.ScheduleEvent(eEvents::EventColossalRoar, 5000);
                    m_Events.ScheduleEvent(eEvents::EventMassiveStomp, 9000);
                }

                void UpdateAI(const uint32 p_Diff) override
                {
                    if (!UpdateVictim())
                        return;

                    m_Events.Update(p_Diff);

                    if (me->HasUnitState(UnitState::UNIT_STATE_CASTING) || me->HasUnitState(UnitState::UNIT_STATE_STUNNED))
                        return;

                    switch (m_Events.ExecuteEvent())
                    {
                        case eEvents::EventColossalRoar:
                            me->CastSpell(me, eSpells::SpellColossalRoar, true);
                            m_Events.ScheduleEvent(eEvents::EventColossalRoar, 10000);
                            break;
                        case eEvents::EventMassiveStomp:
                            me->CastSpell(me, eSpells::SpellMassiveStomp, true);
                            m_Events.ScheduleEvent(eEvents::EventMassiveStomp, 15000);
                            break;
                        default:
                            break;
                    }

                    DoMeleeAttackIfReady();
                }
            };

            CreatureAI* GetAI(Creature* p_Creature) const override
            {
                return new mob_bloodmaul_ogronAI(p_Creature);
            }
    };

    /// Bloodmaul Flamespeaker - 81767
    class mob_bloodmaul_flamespeaker : public CreatureScript
    {
        public:
            mob_bloodmaul_flamespeaker() : CreatureScript("mob_bloodmaul_flamespeaker") { }

            struct mob_bloodmaul_flamespeakerAI : public ScriptedAI
            {
                mob_bloodmaul_flamespeakerAI(Creature* p_Creature) : ScriptedAI(p_Creature) { }

                enum eSpells
                {
                    SpellChannelFlames      = 164615,
                    SpellExplodingFlames    = 164617
                };

                enum eEvents
                {
                    EventChannelFlames = 1,
                    EventExplodingFlames
                };

                EventMap m_Events;

                void Reset() override
                {
                    m_Events.Reset();
                }

                void EnterCombat(Unit*) override
                {
                    m_Events.ScheduleEvent(eEvents::EventChannelFlames, 5000);
                    m_Events.ScheduleEvent(eEvents::EventExplodingFlames, 10000);
                }

                void UpdateAI(uint32 const p_Diff) override
                {
                    if (!UpdateVictim())
                        return;

                    m_Events.Update(p_Diff);

                    if (me->HasUnitState(UnitState::UNIT_STATE_CASTING))
                        return;

                    switch (m_Events.ExecuteEvent())
                    {
                        case eEvents::EventChannelFlames:
                            me->SetFacingTo(me->GetOrientation());
                            me->CastSpell(me, eSpells::SpellChannelFlames, false);
                            m_Events.ScheduleEvent(eEvents::EventChannelFlames, 30000);
                            break;
                        case eEvents::EventExplodingFlames:
                            if (Unit* l_Target = SelectTarget(SelectAggroTarget::SELECT_TARGET_RANDOM))
                                me->CastSpell(l_Target, eSpells::SpellExplodingFlames, false);
                            m_Events.ScheduleEvent(eEvents::EventExplodingFlames, 20000);
                            break;
                        default:
                            break;
                    }

                    DoMeleeAttackIfReady();
                }
            };

            CreatureAI* GetAI(Creature* p_Creature) const override
            {
                return new mob_bloodmaul_flamespeakerAI(p_Creature);
            }
    };

    /// Exploding Flames - 83808
    class mob_bloodmaul_exploding_flames : public CreatureScript
    {
        public:
            mob_bloodmaul_exploding_flames() : CreatureScript("mob_bloodmaul_exploding_flames") { }

            struct mob_bloodmaul_exploding_flamesAI : public ScriptedAI
            {
                mob_bloodmaul_exploding_flamesAI(Creature* p_Creature) : ScriptedAI(p_Creature) { }

                enum eSpells
                {
                    ExplodingFlamesPeriodic = 167701
                };

                void Reset() override
                {
                    me->CastSpell(me, eSpells::ExplodingFlamesPeriodic, true);

                    me->SetReactState(ReactStates::REACT_PASSIVE);
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_REMOVE_CLIENT_CONTROL | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);
                }

                void UpdateAI(uint32 const p_Diff) override { }
            };

            CreatureAI* GetAI(Creature* p_Creature) const override
            {
                return new mob_bloodmaul_exploding_flamesAI(p_Creature);
            }
    };

    /// Molten Earth Elemental - 75209
    class mob_molten_earth_elemental : public CreatureScript
    {
        public:
            mob_molten_earth_elemental() : CreatureScript("mob_molten_earth_elemental") { }

            struct mob_molten_earth_elementalAI : public ScriptedAI
            {
                mob_molten_earth_elementalAI(Creature* p_Creature) : ScriptedAI(p_Creature) { }

                enum Spells
                {
                    SpellLavaArc = 151720,
                };

                enum Events
                {
                    EventLavaArc = 1,
                };

                EventMap m_Events;

                void Reset() override
                {
                    m_Events.Reset();
                }

                void EnterCombat(Unit*) override
                {
                    m_Events.ScheduleEvent(Events::EventLavaArc, 3000);
                }

                void UpdateAI(const uint32 p_Diff) override
                {
                    if (!UpdateVictim())
                        return;

                    m_Events.Update(p_Diff);

                    if (me->HasUnitState(UnitState::UNIT_STATE_CASTING) || me->HasUnitState(UnitState::UNIT_STATE_STUNNED))
                        return;

                    switch ((Events)m_Events.ExecuteEvent())
                    {
                        case Events::EventLavaArc:
                        {
                            /*if (Map* l_Map = me->GetMap())
                                if (!l_Map->IsHeroic() && !l_Map->IsChallengeMode())
                                    break;

                            me->CastSpell(me, Spells::SpellLavaArc, false);
                            m_Events.ScheduleEvent(Events::EventLavaArc, 12000);*/
                            break;
                        }
                        default:
                            break;
                    }

                    DoMeleeAttackIfReady();
                }
            };

            CreatureAI* GetAI(Creature* p_Creature) const override
            {
                return new mob_molten_earth_elementalAI(p_Creature);
            }
    };

    /// Vengeful Magma Elemental - 75820
    class mob_vengeful_magma_elemental : public CreatureScript
    {
        public:
            mob_vengeful_magma_elemental() : CreatureScript("mob_vengeful_magma_elemental") { }

            struct mob_vengeful_magma_elementalAI : public ScriptedAI
            {
                mob_vengeful_magma_elementalAI(Creature* p_Creature) : ScriptedAI(p_Creature) { }

                enum Spells
                {
                    SpellArmorDent = 151685,
                    SpellCinderSplash = 152298,
                };

                enum Events
                {
                    EventArmorDent = 1,
                    EventCinderSplash = 2
                };

                EventMap m_Events;

                void Reset() override
                {
                    m_Events.Reset();

                    if (Map* l_Map = me->GetMap())
                        m_IsHC = l_Map->IsHeroic()/* || l_Map->IsChallengeMode()*/;
                    else
                        m_IsHC = false;
                }

                void EnterCombat(Unit*) override
                {
                    m_Events.ScheduleEvent(Events::EventArmorDent, 3000);
                }

                void UpdateAI(const uint32 p_Diff) override
                {
                    if (!UpdateVictim())
                        return;

                    m_Events.Update(p_Diff);

                    if (me->HasUnitState(UnitState::UNIT_STATE_CASTING) || me->HasUnitState(UnitState::UNIT_STATE_STUNNED))
                        return;

                    switch ((Events)m_Events.ExecuteEvent())
                    {
                        case Events::EventArmorDent:
                            me->CastSpell(me->GetVictim(), Spells::SpellArmorDent, false);
                            m_Events.ScheduleEvent(m_IsHC ? urand(Events::EventArmorDent, Events::EventCinderSplash) : Events::EventArmorDent, 6000);
                            break;
                        case Events::EventCinderSplash:
                            me->CastSpell(me->GetVictim(), Spells::SpellCinderSplash, false);
                            m_Events.ScheduleEvent(urand(Events::EventArmorDent, Events::EventCinderSplash), 6000);
                            break;
                        default:
                            break;
                    }

                    DoMeleeAttackIfReady();
                }

                bool m_IsHC;
            };

            CreatureAI* GetAI(Creature* p_Creature) const override
            {
                return new mob_vengeful_magma_elementalAI(p_Creature);
            }
    };

    /// Magma Lord - 75211
    class mob_magma_lord : public CreatureScript
    {
        public:
            mob_magma_lord() : CreatureScript("mob_magma_lord") { }

            struct mob_magma_lordAI : public ScriptedAI
            {
                mob_magma_lordAI(Creature* p_Creature) : ScriptedAI(p_Creature) { }

                enum Spells
                {
                    SpellFireball       = 152427,
                    SpellPillarOfFlames = 151623
                };

                void Reset() override
                {
                }

                void EnterCombat(Unit*) override
                {
                    me->CastSpell(me, Spells::SpellPillarOfFlames, true);
                }

                void UpdateAI(const uint32 p_Diff) override
                {
                    if (!UpdateVictim())
                        return;

                    if (me->HasUnitState(UnitState::UNIT_STATE_CASTING) || me->HasUnitState(UnitState::UNIT_STATE_STUNNED))
                        return;

                    DoSpellAttackIfReady((uint32)Spells::SpellFireball);
                }
            };

            CreatureAI* GetAI(Creature* p_Creature) const override
            {
                return new mob_magma_lordAI(p_Creature);
            }
    };

    /// Pillar Of Flame - 75327
    class mob_pillar_of_flame : public CreatureScript
    {
        public:
            mob_pillar_of_flame() : CreatureScript("mob_pillar_of_flame") { }

            struct mob_pillar_of_flameAI : public ScriptedAI
            {
                mob_pillar_of_flameAI(Creature* p_Creature) : ScriptedAI(p_Creature) { }

                enum Spells
                {
                    SpellATSummon   = 145844,
                    SpellDebuff     = 145843
                };

                enum Events
                {
                    EventDamage = 1,
                };

                EventMap m_Events;

                void Reset() override
                {
                    m_Events.Reset();
                    m_CanDamage = false;
                    me->SetControlled(true, UNIT_STATE_ROOT);
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NON_ATTACKABLE);
                    m_Events.ScheduleEvent(Events::EventDamage, 3000);
                    me->CastSpell(me, Spells::SpellATSummon, false);
                    me->DespawnOrUnsummon(6000);
                }

                void MoveInLineOfSight(Unit* p_Who) override
                {
                    if (p_Who->GetTypeId() == TYPEID_PLAYER && me->IsWithinDist2d(p_Who, 5.f) && !p_Who->HasAura(Spells::SpellDebuff))
                        me->CastSpell(p_Who, Spells::SpellDebuff, true);
                }

                void UpdateAI(const uint32 p_Diff) override
                {
                    if (!UpdateVictim())
                        return;

                    m_Events.Update(p_Diff);

                    if (me->HasUnitState(UnitState::UNIT_STATE_CASTING) || me->HasUnitState(UnitState::UNIT_STATE_STUNNED))
                        return;

                    switch ((Events)m_Events.ExecuteEvent())
                    {
                        case Events::EventDamage:
                        {
                            if (Map* l_Map = me->GetMap())
                                if (!l_Map->IsHeroic()/* && !l_Map->IsChallengeMode()*/)
                                    break;

                            m_CanDamage = true;
                            break;
                        }
                        default:
                            break;
                    }

                    //DoMeleeAttackIfReady();
                }

                bool m_CanDamage;
            };

            CreatureAI* GetAI(Creature* p_Creature) const override
            {
                return new mob_pillar_of_flameAI(p_Creature);
            }
    };

    /// Lava Explosion Stalker - 75846
    class mob_lava_explosion_stalker : public CreatureScript
    {
    public:
        mob_lava_explosion_stalker() : CreatureScript("mob_lava_explosion_stalker") { }

        struct mob_lava_explosion_stalkerAI : public ScriptedAI
        {
            mob_lava_explosion_stalkerAI(Creature* p_Creature) : ScriptedAI(p_Creature)
            {
                explosionDone = false;
            }

            bool explosionDone;

            enum Spells
            {
                SPELL_EXPLOSION = 152864,
            };

            void DoAction(const int32 action) override
            {
                if (explosionDone)
                    return;

                explosionDone = true;

                me->CastSpell(me, Spells::SPELL_EXPLOSION, false);

                uint32 eventPnjEntries[3] = { 83622, 83620, 83624 };

                for (int i = 0; i < 3; ++i)
                {
                    if (Creature* eventMob = me->FindNearestCreature(eventPnjEntries[i], 100.0f))
                    {
                        eventMob->AddAura(83613, eventMob); // Aura de peur
                        eventMob->AddAura(152148, eventMob); // Trainée de feu
                        eventMob->GetMotionMaster()->MovePoint(1, eventMob->GetPositionX(), -140.0f + frand(-10.0f, 10.0f), 231.0f);
                    }
                }
            }
        };

        CreatureAI* GetAI(Creature* p_Creature) const override
        {
            return new mob_lava_explosion_stalkerAI(p_Creature);
        }
    };

    /// Trois mobs de l'event : 83622, 83620, 83624
    class mob_lava_explosion_event : public CreatureScript
    {
    public:
        mob_lava_explosion_event() : CreatureScript("mob_lava_explosion_event") { }

        struct mob_lava_explosion_eventAI : public ScriptedAI
        {
            mob_lava_explosion_eventAI(Creature* p_Creature) : ScriptedAI(p_Creature) { }

            void MovementInform(uint32 p_Type, uint32 p_Id) override
            {
                if (p_Type != POINT_MOTION_TYPE)
                    return;

                if (p_Id == 1)
                    me->Kill(me);
            }
        };

        CreatureAI* GetAI(Creature* p_Creature) const override
        {
            return new mob_lava_explosion_eventAI(p_Creature);
        }
    };

    /// Channel Flames - 164615
    class spell_bloodmaul_channel_flames : public SpellScriptLoader
    {
        public:
            spell_bloodmaul_channel_flames() : SpellScriptLoader("spell_bloodmaul_channel_flames") { }

            class spell_bloodmaul_channel_flames_AuraScript : public AuraScript
            {
                PrepareAuraScript(spell_bloodmaul_channel_flames_AuraScript);

                enum eSpells
                {
                    ChannelFlamesDoT = 164616
                };

                uint32 waitTime = 500;

                void OnUpdate(uint32 p_diff)
                {
                    if (waitTime > p_diff)
                    {
                        waitTime -= p_diff;
                        return;
                    }

                    waitTime = 500;

                    if (Unit* caster = GetCaster())
                    {
                        std::list<Unit*> l_TargetList;
                        caster->GetAttackableUnitListInRange(l_TargetList, 15.0f);

                        if (l_TargetList.empty())
                            return;

                        l_TargetList.remove_if([this, caster](Unit* unit) -> bool
                        {
                            if (unit == nullptr || !caster->isInFront(unit, float(M_PI) / 6))
                                return true;

                            return false;
                        });

                        for (Unit* l_Unit : l_TargetList)
                            caster->CastSpell(l_Unit, eSpells::ChannelFlamesDoT, true);
                    }
                }

                void Register() override
                {
                    OnAuraUpdate += AuraUpdateFn(spell_bloodmaul_channel_flames_AuraScript::OnUpdate);
                }
            };

            AuraScript* GetAuraScript() const override
            {
                return new spell_bloodmaul_channel_flames_AuraScript();
            }
    };
}
} ///< namespace Instances

void AddSC_mob_Bloodmaul()
{
    /// Creatures
    new Instances::Bloodmaul::mob_BloodmaulEnforcer();
    new Instances::Bloodmaul::mob_BloodmaulSlaver();
    new Instances::Bloodmaul::mob_BloodmaulOverseer();
    new Instances::Bloodmaul::mob_BloodmaulGeomancer();
    new Instances::Bloodmaul::mob_BloodmaulWarder();
    new Instances::Bloodmaul::mob_BloodmaulOgreMage();
    new Instances::Bloodmaul::mob_CapturedMiner();
    new Instances::Bloodmaul::mob_Slagna();
    new Instances::Bloodmaul::mob_bloodmaul_ogron();
    new Instances::Bloodmaul::mob_bloodmaul_flamespeaker();
    new Instances::Bloodmaul::mob_bloodmaul_exploding_flames();
    new Instances::Bloodmaul::mob_molten_earth_elemental();
    new Instances::Bloodmaul::mob_vengeful_magma_elemental();
    new Instances::Bloodmaul::mob_magma_lord();
    new Instances::Bloodmaul::mob_pillar_of_flame();
    new Instances::Bloodmaul::mob_lava_explosion_stalker();
    new Instances::Bloodmaul::mob_lava_explosion_event();

    /// Spells
    new Instances::Bloodmaul::spell_bloodmaul_channel_flames();
}
