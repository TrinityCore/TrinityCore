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

#include "instance_bloodmaul.h"
#include "GameObject.h"

namespace Instances
{
    namespace Bloodmaul
    {
        enum MaxEncounter
        {
            Number = 4
        };

        static const DoorData k_DoorData[] =
        {
            //{ GameObjects::RoltallBridge,       BossIds::BossForgemasterGogduh, DoorType::DOOR_TYPE_PASSAGE   },
            //{ GameObjects::RoltallEntranceWall, BossIds::BossForgemasterGogduh, DoorType::DOOR_TYPE_PASSAGE   },
            { GameObjects::RoltallExitWall,     BossIds::BossRoltall,           DoorType::DOOR_TYPE_PASSAGE },
            { 0,                                0,                              DoorType::DOOR_TYPE_ROOM    }  // EOF
        };

        /*static const uint32 g_MinerEntry[] =
        {
            MobEntries::CapturedMinerAlliance,
            MobEntries::CapturedMinerHorde,
            MobEntries::CapturedMinerNeutral
        };*/

        class instance_Bloodmaul : public InstanceMapScript
        {
            public:
                instance_Bloodmaul() : InstanceMapScript("instance_Bloodmaul", 1175) { }

                struct instance_BloodmaulInstanceMapScript : public InstanceScript
                {
                    uint32 m_BeginningTime;
                    bool m_CanUpdate;
                    ObjectGuid m_InstanceGuid;

                    /// Scenario handling.
                    uint32 m_CreatureKilled;

                    /// Slave Watcher Crushto
                    std::vector<ObjectGuid> m_MinerSpawnGuids;
                    std::list<ObjectGuid> m_CapturedMinerGuids;
                    uint32 m_OgreMageDeads;
                    std::list<ObjectGuid> m_NearestWarderGuids;
                    ObjectGuid m_slaveWatcherCrushtoGuid;

                    ObjectGuid m_roltallBridge;
                    ObjectGuid m_roltallEntranceWall;
                    uint32 m_openRoltallTimer;

                    ObjectGuid m_explosionStalkerGuid;
                    std::list<ObjectGuid> m_rightStalkerGuid;
                    std::list<ObjectGuid> m_leftStalkerGuid;

                    /// Gog'Duh
                    ObjectGuid m_gogduhGuid;

                    /// Slagna
                    bool m_SlagnaSpawned;

                    /// Gug'rokk
                    ObjectGuid m_GugrokkGuid;
                    uint32 m_UnstableSlagKilled;

                    uint32 m_CheckZPosTimer;

                    uint8 playersTeamId;

                    instance_BloodmaulInstanceMapScript(InstanceMap* map)
                        : InstanceScript(map),
                        m_BeginningTime(0),
                        m_CanUpdate(false),
                        m_CreatureKilled(0),
                        m_OgreMageDeads(0),
                        m_openRoltallTimer(0),
                        m_SlagnaSpawned(false),
                        m_UnstableSlagKilled(0),
                        m_CheckZPosTimer(1000),
                        playersTeamId(TEAM_NEUTRAL)
                    {
                        SetBossNumber(MaxEncounter::Number);
                        LoadDoorData(k_DoorData);

                        m_MinerSpawnGuids.reserve(3);
                    }

                    void OnCreatureCreate(Creature* creature) override
                    {
                        switch (creature->GetEntry())
                        {
                            case uint32(MobEntries::SlaveWatcherCrushto):
                                m_slaveWatcherCrushtoGuid = creature->GetGUID();
                                break;
                            case uint32(MobEntries::MinesBat):
                                creature->SetDisableGravity(true);
                                creature->SetCanFly(true);
                                creature->SetAnimTier(UnitBytes1_Flags(UNIT_BYTE1_FLAG_ALWAYS_STAND | UNIT_BYTE1_FLAG_HOVER), true);
                                break;
                            case uint32(MobEntries::AllianceMinerSpawn):
                                m_MinerSpawnGuids[TEAM_ALLIANCE] = creature->GetGUID();
                                break;
                            case uint32(MobEntries::HordeMinerSpawn):
                                m_MinerSpawnGuids[TEAM_HORDE] = creature->GetGUID();
                                break;
                            case uint32(MobEntries::NeutralMinerSpawn):
                                m_MinerSpawnGuids[TEAM_NEUTRAL] = creature->GetGUID();
                                break;
                            case uint32(MobEntries::EarthCrushStalker):
                                creature->SetFaction(2102);
                                creature->SetReactState(ReactStates::REACT_PASSIVE);
                                break;
                            case uint32(MobEntries::BloodmaulWarder):
                            {
                                static const Position k_CrushtoPosition = { 2038.51f, -361.126f, 223.f };

                                if (k_CrushtoPosition.GetExactDist2d(creature) < 50.0f)
                                    m_NearestWarderGuids.emplace_back(creature->GetGUID());
                                break;
                            }
                            case uint32(MobEntries::MoltenEarthElemental):
                                /*if (Unit* unit = MS::ScriptUtils::SelectNearestCreatureWithEntry(creature, uint32(MobEntries::BloodmaulWarder), 50.0f))
                                    creature->Attack(unit, false);*/
                                break;
                            case uint32(MobEntries::Gogduh):
                                m_gogduhGuid = creature->GetGUID();
                                break;
                            case uint32(MobEntries::Gugrokk):
                                m_GugrokkGuid = creature->GetGUID();
                                break;
                            case uint32(MobEntries::LavaExplosionStalker):
                            {
                                if (creature->GetPositionY() < -50)
                                    m_explosionStalkerGuid = creature->GetGUID();
                                else if (creature->GetPositionY() < 0)
                                    m_rightStalkerGuid.push_back(creature->GetGUID());
                                else
                                    m_leftStalkerGuid.push_back(creature->GetGUID());
                            }
                            default:
                                break;
                        }
                    }

                    void OnGameObjectCreate(GameObject* gameObject) override
                    {
                        switch (gameObject->GetEntry())
                        {
                            case GameObjects::RoltallExitWall:
                                AddDoor(gameObject, true);
                                break;
                            case GameObjects::RoltallBridge:
                                m_roltallBridge = gameObject->GetGUID();
                                break;
                            case GameObjects::RoltallEntranceWall:
                                m_roltallEntranceWall = gameObject->GetGUID();
                                break;
                            /*case GameObjects::ChallengeDoor:
                                m_ChallengeDoorGuid = gameObject->GetGUID();
                                break;*/
                            default:
                                break;
                        }
                    }

                    void OnUnitDeath(Unit* unit) override
                    {
                        if (!unit->IsCreature())
                            return;

                        switch (unit->GetEntry())
                        {
                            case uint32(MobEntries::CapturedMinerAlliance):
                            case uint32(MobEntries::CapturedMinerHorde):
                            case uint32(MobEntries::CapturedMinerNeutral):
                                m_CapturedMinerGuids.remove(unit->GetGUID());
                                unit->ToCreature()->DespawnOrUnsummon();
                                break;
                            case uint32(MobEntries::BloodmaulOgreMage):
                            {
                                if (!m_NearestWarderGuids.empty())
                                {
                                    auto l_Itr = std::begin(m_NearestWarderGuids);
                                    std::advance(l_Itr, m_OgreMageDeads);
                                    if (Creature* l_Warder = ObjectAccessor::GetCreature(*unit, *l_Itr))
                                    {
                                        /*l_Warder->GetMotionMaster()->MoveChase(player);
                                        l_Warder->Attack(player, true);*/

                                        if (l_Warder->AI())
                                            l_Warder->AI()->Talk(uint32(Talks::WarderAttack));
                                    }

                                    ++m_OgreMageDeads;

                                    if (m_OgreMageDeads == 2)
                                    {
                                        m_OgreMageDeads = 0;

                                        if (Creature* l_Boss = ObjectAccessor::GetCreature(*unit, m_slaveWatcherCrushtoGuid))
                                        {
                                            if (l_Boss->AI())
                                                l_Boss->AI()->Talk(uint32(SlaverWatcherCrushto::Texts::TalkIntro));
                                        }
                                    }
                                }
                                break;
                            }
                            case MobEntries::UnstableSlag:
                                ++m_UnstableSlagKilled;
                                break;
                            default:
                                break;
                        }

                        /*if (!instance->IsChallengeMode() || !IsChallengeModeStarted() || m_CreatureKilled >= eScenarioDatas::BloodmaulKillCount)
                            return;*/

                        if (unit == nullptr)
                            return;

                        if (!unit->ToCreature()->isElite() || unit->ToCreature()->IsDungeonBoss())
                            return;

                        ++m_CreatureKilled;
                        /*SendScenarioProgressUpdate(CriteriaProgressData(eScenarioDatas::BloodmaulEnnemies, m_CreatureKilled, m_InstanceGuid, time(NULL), m_BeginningTime, 0));

                        if (m_CreatureKilled >= eScenarioDatas::BloodmaulKillCount)
                            m_ConditionCompleted = true;*/
                    }

                    bool SetBossState(uint32 id, EncounterState state) override
                    {
                        if (!InstanceScript::SetBossState(id, state))
                            return false;

                        switch (id)
                        {
                            case BossIds::BossSlaveWatcherCrushto:
                            {
                                if (state == EncounterState::NOT_STARTED)
                                {
                                    /*for (ObjectGuid guid : m_CapturedMinerGuids)
                                    {
                                        if (Creature* l_CapturedMiner = ObjectAccessor::GetCreature(guid))
                                            l_CapturedMiner->DespawnOrUnsummon();
                                    }*/

                                    m_CapturedMinerGuids.clear();
                                    m_OgreMageDeads = 0;
                                }
                                else if (state == EncounterState::DONE)
                                {
                                    /*for (ObjectGuid guid : m_CapturedMinerGuids)
                                    {
                                        if (Creature* l_CapturedMiner = ObjectAccessor::GetCreature(guid))
                                        {
                                            //if (l_CapturedMiner->AI())
                                            //    l_CapturedMiner->AI()->Talk(uint32(Talks::CapturedMinerReleased));
                                            l_CapturedMiner->CombatStop();
                                            l_CapturedMiner->SetReactState(ReactStates::REACT_PASSIVE);
                                        }
                                    }*/

                                    CheckRoltallSpawn((BossIds)id);
                                }
                                break;
                            }
                            case BossIds::BossForgemasterGogduh:
                            {
                                if (state == EncounterState::DONE)
                                    CheckRoltallSpawn((BossIds)id);

                                break;
                            }
                            case BossIds::BossGugrokk:
                            {
                                if (state == EncounterState::NOT_STARTED)
                                    m_UnstableSlagKilled = 0;
                                else if (state == EncounterState::DONE && m_UnstableSlagKilled == 0 && instance->IsHeroic())
                                    DoCompleteAchievement(eAchievements::IsDraenorOnFire);
                                break;
                            }
                            default:
                                break;
                        }

                        return true;
                    }

                    void CheckRoltallSpawn(BossIds lastKilled)
                    {
                        if (GetBossState(BossIds::BossSlaveWatcherCrushto) != EncounterState::DONE ||
                            GetBossState(BossIds::BossForgemasterGogduh) != EncounterState::DONE)
                            return;

                        DoPlayScenePackageIdOnPlayers(lastKilled == BossIds::BossSlaveWatcherCrushto ? eSceneDatas::SCENE_CRUSHTO_BRAWBRIDGE : eSceneDatas::SCENE_MAGMOLATUS_BRAWBRIDGE);
                        m_openRoltallTimer = 10000;
                    }

                    void SetData(uint32 type, uint32 /*data*/) override
                    {
                        switch (type)
                        {
                            case uint32(Data::RaiseTheMiners):
                            {
                                for (uint8 i = TEAM_ALLIANCE; i <= TEAM_NEUTRAL; ++i)
                                {
                                    /*if (Creature* l_Spawn = ObjectAccessor::GetCreature(m_MinerSpawnGuids[i]))
                                    {
                                        if (TempSummon* summon = l_Spawn->SummonCreature(g_MinerEntry[i], l_Spawn->GetPosition()))
                                        {
                                            bool mustAttackBoss = false;

                                            if (i == TEAM_ALLIANCE && playersTeamId == TEAM_ALLIANCE)
                                            {
                                                summon->SetFaction(FACTION_A);
                                                mustAttackBoss = true;
                                            }
                                            else if (i == TEAM_HORDE && playersTeamId == TEAM_HORDE)
                                            {
                                                summon->SetFaction(FACTION_H);
                                                mustAttackBoss = true;
                                            }

                                            if (mustAttackBoss)
                                            {
                                                summon->AddAura(150816, summon); // Soulevement des mineurs
                                                if (Creature* boss = instance->GetCreature(m_slaveWatcherCrushtoGuid))
                                                    summon->AI()->AttackStart(boss);
                                            }
                                            else
                                            {
                                                if (Player* l_Plr = MS::ScriptUtils::SelectRandomPlayerIncludedTank(summon, 200.0f, false))
                                                    summon->AI()->AttackStart(l_Plr);
                                            }

                                            summon->SetHealth(summon->GetMaxHealth() / 2.0f);
                                            m_CapturedMinerGuids.emplace_back(summon->GetGUID());
                                        }
                                    }*/
                                }
                                break;
                            }
                            case uint32(Data::SpawnSlagna):
                            {
                                if (m_SlagnaSpawned)
                                    break;

                                static const Position k_SpawnSlagna = { 2191.21f, -191.67f, 213.72f };
                                if (Creature* l_Slagna = instance->SummonCreature(uint32(MobEntries::Slagna), k_SpawnSlagna))
                                {
                                    m_SlagnaSpawned = true;
                                    if (l_Slagna->GetAI())
                                        l_Slagna->GetAI()->SetData(uint32(Data::SpawnSlagna), 0);
                                }

                                break;
                            }
                        }
                    }

                    /*void SetGuidData(uint32 type, ObjectGuid data) override
                    {
                        switch (type)
                        {
                            case uint32(Data::RaiseTheMinersChangeTarget):
                                if (Player* l_Plr = ObjectAccessor::FindPlayer(data))
                                {
                                    for (auto guid : m_CapturedMinerGuids)
                                    {
                                        if (Creature* summon = ObjectAccessor::GetCreature(guid))
                                            summon->GetMotionMaster()->MoveChase(l_Plr);
                                    }
                                }
                                break;
                        }
                    }*/

                    ObjectGuid GetGuidData(uint32 type) const override
                    {
                        switch (type)
                        {
                            case (uint32)MobEntries::Gogduh:
                                return m_gogduhGuid;
                            case (uint32)MobEntries::Gugrokk:
                                return m_GugrokkGuid;
                            case (uint32)MobEntries::LavaExplosionStalker:
                                return m_explosionStalkerGuid;
                            default:
                                break;
                        }

                        return ObjectGuid::Empty;
                    }

                    void OnPlayerEnter(Player* player) override
                    {
                        if (!player->IsInWorld())
                            return;

                        InstanceScript::OnPlayerEnter(player);
                        m_CanUpdate = true;

                        if (playersTeamId == TEAM_NEUTRAL)
                            playersTeamId = player->GetTeamId();
                    }

                    void Update(uint32 diff) override
                    {
                        CheckPositionZForPlayers(diff);
                        /*ScheduleBeginningTimeUpdate(diff);
                        ScheduleChallengeStartup(diff);
                        ScheduleChallengeTimeUpdate(diff);*/

                        if (!m_CanUpdate)
                            return;

                        m_BeginningTime += diff;

                        if (m_openRoltallTimer)
                        {
                            if (m_openRoltallTimer <= diff)
                            {
                                DoUseDoorOrButton(m_roltallEntranceWall, 24 * 60 * 60 * 1000);
                                DoUseDoorOrButton(m_roltallBridge, 24 * 60 * 60 * 1000);

                                m_openRoltallTimer = 0;
                            }
                            else
                                m_openRoltallTimer -= diff;
                        }
                    }

                    void CheckPositionZForPlayers(uint32 diff)
                    {
                        if (!m_CheckZPosTimer)
                            return;

                        if (m_CheckZPosTimer <= diff)
                        {
                            Map::PlayerList const& playerList = instance->GetPlayers();
                            for (Map::PlayerList::const_iterator itr = playerList.begin(); itr != playerList.end(); ++itr)
                            {
                                if (Player* player = itr->GetSource())
                                {
                                    if (player->GetPositionZ() <= 150.0f)
                                        player->Kill(player);
                                }
                            }

                            m_CheckZPosTimer = 1000;
                        }
                        else
                            m_CheckZPosTimer -= diff;
                    }
                };

                InstanceScript* GetInstanceScript(InstanceMap* map) const
                {
                    return new instance_BloodmaulInstanceMapScript(map);
                }
        };
    }
}

void AddSC_instance_Bloodmaul()
{
    new Instances::Bloodmaul::instance_Bloodmaul();
}
