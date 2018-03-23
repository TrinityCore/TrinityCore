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

        static const uint32 g_MinerEntry[] =
        {
            MobEntries::CapturedMinerAlliance,
            MobEntries::CapturedMinerHorde,
            MobEntries::CapturedMinerNeutral
        };

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

                    instance_BloodmaulInstanceMapScript(Map* p_Map)
                        : InstanceScript(p_Map),
                        m_BeginningTime(0),
                        m_CanUpdate(false),
                        m_CreatureKilled(0),
                        m_CapturedMinerGuids(),
                        m_OgreMageDeads(0),
                        m_NearestWarderGuids(),
                        m_SlagnaSpawned(false),
                        m_UnstableSlagKilled(0),
                        m_CheckZPosTimer(1000),
                        m_openRoltallTimer(0),
                        playersTeamId(TEAM_NEUTRAL)
                    {
                        SetBossNumber(MaxEncounter::Number);
                        LoadDoorData(k_DoorData);

                        m_MinerSpawnGuids.reserve(3);
                    }

                    void OnCreatureCreate(Creature* p_Creature) override
                    {
                        switch (p_Creature->GetEntry())
                        {
                            case uint32(MobEntries::SlaveWatcherCrushto):
                                m_slaveWatcherCrushtoGuid = p_Creature->GetGUID();
                                break;
                            case uint32(MobEntries::MinesBat):
                                p_Creature->SetDisableGravity(true);
                                p_Creature->SetCanFly(true);
                                p_Creature->SetByteFlag(UNIT_FIELD_BYTES_1, 3, UNIT_BYTE1_FLAG_ALWAYS_STAND | UNIT_BYTE1_FLAG_HOVER);
                                break;
                            case uint32(MobEntries::AllianceMinerSpawn):
                                m_MinerSpawnGuids[TEAM_ALLIANCE] = p_Creature->GetGUID();
                                break;
                            case uint32(MobEntries::HordeMinerSpawn):
                                m_MinerSpawnGuids[TEAM_HORDE] = p_Creature->GetGUID();
                                break;
                            case uint32(MobEntries::NeutralMinerSpawn):
                                m_MinerSpawnGuids[TEAM_NEUTRAL] = p_Creature->GetGUID();
                                break;
                            case uint32(MobEntries::EarthCrushStalker):
                                p_Creature->setFaction(2102);
                                p_Creature->SetReactState(ReactStates::REACT_PASSIVE);
                                break;
                            case uint32(MobEntries::BloodmaulWarder):
                            {
                                static const Position k_CrushtoPosition = { 2038.51f, -361.126f, 223.f };

                                if (k_CrushtoPosition.GetExactDist2d(p_Creature) < 50.0f)
                                    m_NearestWarderGuids.emplace_back(p_Creature->GetGUID());
                                break;
                            }
                            case uint32(MobEntries::MoltenEarthElemental):
                                /*if (Unit* l_Unit = MS::ScriptUtils::SelectNearestCreatureWithEntry(p_Creature, uint32(MobEntries::BloodmaulWarder), 50.0f))
                                    p_Creature->Attack(l_Unit, false);*/
                                break;
                            case uint32(MobEntries::Gogduh):
                                m_gogduhGuid = p_Creature->GetGUID();
                                break;
                            case uint32(MobEntries::Gugrokk):
                                m_GugrokkGuid = p_Creature->GetGUID();
                                break;
                            case uint32(MobEntries::LavaExplosionStalker):
                            {
                                if (p_Creature->GetPositionY() < -50)
                                    m_explosionStalkerGuid = p_Creature->GetGUID();
                                else if (p_Creature->GetPositionY() < 0)
                                    m_rightStalkerGuid.push_back(p_Creature->GetGUID());
                                else
                                    m_leftStalkerGuid.push_back(p_Creature->GetGUID());
                            }
                            default:
                                break;
                        }
                    }

                    void OnGameObjectCreate(GameObject* p_GameObject) override
                    {
                        switch (p_GameObject->GetEntry())
                        {
                            case GameObjects::RoltallExitWall:
                                AddDoor(p_GameObject, true);
                                break;
                            case GameObjects::RoltallBridge:
                                m_roltallBridge = p_GameObject->GetGUID();
                                break;
                            case GameObjects::RoltallEntranceWall:
                                m_roltallEntranceWall = p_GameObject->GetGUID();
                                break;
                            /*case GameObjects::ChallengeDoor:
                                m_ChallengeDoorGuid = p_GameObject->GetGUID();
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
                                        /*l_Warder->GetMotionMaster()->MoveChase(p_Player);
                                        l_Warder->Attack(p_Player, true);*/

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

                    bool SetBossState(uint32 p_ID, EncounterState p_State) override
                    {
                        if (!InstanceScript::SetBossState(p_ID, p_State))
                            return false;

                        switch (p_ID)
                        {
                            case BossIds::BossSlaveWatcherCrushto:
                            {
                                if (p_State == EncounterState::NOT_STARTED)
                                {
                                    /*for (ObjectGuid l_Guid : m_CapturedMinerGuids)
                                    {
                                        if (Creature* l_CapturedMiner = ObjectAccessor::GetCreature(l_Guid))
                                            l_CapturedMiner->DespawnOrUnsummon();
                                    }*/

                                    m_CapturedMinerGuids.clear();
                                    m_OgreMageDeads = 0;
                                }
                                else if (p_State == EncounterState::DONE)
                                {
                                    for (ObjectGuid l_Guid : m_CapturedMinerGuids)
                                    {
                                        /*if (Creature* l_CapturedMiner = ObjectAccessor::GetCreature(l_Guid))
                                        {
                                            //if (l_CapturedMiner->AI())
                                            //    l_CapturedMiner->AI()->Talk(uint32(Talks::CapturedMinerReleased));
                                            l_CapturedMiner->CombatStop();
                                            l_CapturedMiner->SetReactState(ReactStates::REACT_PASSIVE);
                                        }*/
                                    }

                                    CheckRoltallSpawn((BossIds)p_ID);
                                }
                                break;
                            }
                            case BossIds::BossForgemasterGogduh:
                            {
                                if (p_State == EncounterState::DONE)
                                    CheckRoltallSpawn((BossIds)p_ID);

                                break;
                            }
                            case BossIds::BossGugrokk:
                            {
                                if (p_State == EncounterState::NOT_STARTED)
                                    m_UnstableSlagKilled = 0;
                                else if (p_State == EncounterState::DONE && m_UnstableSlagKilled == 0 && instance->IsHeroic())
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

                    void SetData(uint32 p_Type, uint32 p_Data) override
                    {
                        switch (p_Type)
                        {
                            case uint32(Data::RaiseTheMiners):
                            {
                                for (uint8 i = TEAM_ALLIANCE; i <= TEAM_NEUTRAL; ++i)
                                {
                                    /*if (Creature* l_Spawn = ObjectAccessor::GetCreature(m_MinerSpawnGuids[i]))
                                    {
                                        if (TempSummon* l_Summon = l_Spawn->SummonCreature(g_MinerEntry[i], l_Spawn->GetPosition()))
                                        {
                                            bool mustAttackBoss = false;

                                            if (i == TEAM_ALLIANCE && playersTeamId == TEAM_ALLIANCE)
                                            {
                                                l_Summon->setFaction(FACTION_A);
                                                mustAttackBoss = true;
                                            }
                                            else if (i == TEAM_HORDE && playersTeamId == TEAM_HORDE)
                                            {
                                                l_Summon->setFaction(FACTION_H);
                                                mustAttackBoss = true;
                                            }

                                            if (mustAttackBoss)
                                            {
                                                l_Summon->AddAura(150816, l_Summon); // Soulevement des mineurs
                                                if (Creature* boss = instance->GetCreature(m_slaveWatcherCrushtoGuid))
                                                    l_Summon->AI()->AttackStart(boss);
                                            }
                                            else
                                            {
                                                if (Player* l_Plr = MS::ScriptUtils::SelectRandomPlayerIncludedTank(l_Summon, 200.0f, false))
                                                    l_Summon->AI()->AttackStart(l_Plr);
                                            }

                                            l_Summon->SetHealth(l_Summon->GetMaxHealth() / 2.0f);
                                            m_CapturedMinerGuids.emplace_back(l_Summon->GetGUID());
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

                    void SetGuidData(uint32 p_Type, ObjectGuid p_Data) override
                    {
                        switch (p_Type)
                        {
                            case uint32(Data::RaiseTheMinersChangeTarget):
                                if (Player* l_Plr = ObjectAccessor::FindPlayer(p_Data))
                                {
                                    /*for (auto l_Guid : m_CapturedMinerGuids)
                                    {
                                        if (Creature* l_Summon = ObjectAccessor::GetCreature(l_Guid))
                                            l_Summon->GetMotionMaster()->MoveChase(l_Plr);
                                    }*/
                                }
                                break;
                        }
                    }

                    ObjectGuid GetGuidData(uint32 p_Type) const override
                    {
                        switch (p_Type)
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

                    void OnPlayerEnter(Player* p_Player) override
                    {
                        if (!p_Player->IsInWorld())
                            return;

                        InstanceScript::OnPlayerEnter(p_Player);
                        m_CanUpdate = true;

                        if (playersTeamId == TEAM_NEUTRAL)
                            playersTeamId = p_Player->GetTeamId();
                    }

                    void Update(uint32 p_Diff) override
                    {
                        CheckPositionZForPlayers(p_Diff);
                        /*ScheduleBeginningTimeUpdate(p_Diff);
                        ScheduleChallengeStartup(p_Diff);
                        ScheduleChallengeTimeUpdate(p_Diff);*/

                        if (!m_CanUpdate)
                            return;

                        m_BeginningTime += p_Diff;

                        if (m_openRoltallTimer)
                        {
                            if (m_openRoltallTimer <= p_Diff)
                            {
                                DoUseDoorOrButton(m_roltallEntranceWall, 24 * 60 * 60 * 1000);
                                DoUseDoorOrButton(m_roltallBridge, 24 * 60 * 60 * 1000);

                                m_openRoltallTimer = 0;
                            }
                            else
                                m_openRoltallTimer -= p_Diff;
                        }
                    }

                    void CheckPositionZForPlayers(uint32 p_Diff)
                    {
                        if (!m_CheckZPosTimer)
                            return;

                        if (m_CheckZPosTimer <= p_Diff)
                        {
                            Map::PlayerList const& playerList = instance->GetPlayers();
                            for (Map::PlayerList::const_iterator l_Iter = playerList.begin(); l_Iter != playerList.end(); ++l_Iter)
                            {
                                if (Player* player = l_Iter->GetSource())
                                {
                                    if (player->GetPositionZ() <= 150.0f)
                                        player->Kill(player);
                                }
                            }

                            m_CheckZPosTimer = 1000;
                        }
                        else
                            m_CheckZPosTimer -= p_Diff;
                    }
                };

                InstanceScript* GetInstanceScript(InstanceMap* p_Map) const
                {
                    return new instance_BloodmaulInstanceMapScript(p_Map);
                }
        };
    }
}

void AddSC_instance_Bloodmaul()
{
    new Instances::Bloodmaul::instance_Bloodmaul();
}
