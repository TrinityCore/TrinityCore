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

#include "highmaul.h"
#include "InstanceScript.h"
#include "Group.h"
#include "WorldStatePackets.h"

DoorData const g_DoorData[] =
{
    { eHighmaulGameobjects::GateArenaExit,      eHighmaulDatas::BossKargathBladefist,   DoorType::DOOR_TYPE_PASSAGE     },
    { eHighmaulGameobjects::EarthenPillar,      eHighmaulDatas::BossTheButcher,         DoorType::DOOR_TYPE_ROOM        },
    { eHighmaulGameobjects::FungalGiantDoor,    eHighmaulDatas::BossTheButcher,         DoorType::DOOR_TYPE_PASSAGE     },
    { eHighmaulGameobjects::WindDoor,           eHighmaulDatas::BossTheButcher,         DoorType::DOOR_TYPE_PASSAGE     },
    { eHighmaulGameobjects::WindDoor,           eHighmaulDatas::BossBrackenspore,       DoorType::DOOR_TYPE_ROOM        },
    { eHighmaulGameobjects::Earthwall1,         eHighmaulDatas::BossTectus,             DoorType::DOOR_TYPE_ROOM        },
    { eHighmaulGameobjects::Earthwall2,         eHighmaulDatas::BossTectus,             DoorType::DOOR_TYPE_ROOM        },
    { eHighmaulGameobjects::Earthwall3,         eHighmaulDatas::BossTectus,             DoorType::DOOR_TYPE_ROOM        },
    { eHighmaulGameobjects::Earthwall4,         eHighmaulDatas::BossTectus,             DoorType::DOOR_TYPE_ROOM        },
    { eHighmaulGameobjects::HighmaulLFRDoor,    eHighmaulDatas::BossTectus,             DoorType::DOOR_TYPE_PASSAGE     },
    { eHighmaulGameobjects::TwinOgronEntrance,  eHighmaulDatas::BossTwinOgron,          DoorType::DOOR_TYPE_ROOM        },
    { eHighmaulGameobjects::TwinOgronExit,      eHighmaulDatas::BossTwinOgron,          DoorType::DOOR_TYPE_PASSAGE     },
    { eHighmaulGameobjects::FelBreakerEntrance, eHighmaulDatas::BossKoragh,             DoorType::DOOR_TYPE_ROOM        },
    { eHighmaulGameobjects::FelBreakerExitDoor, eHighmaulDatas::BossKoragh,             DoorType::DOOR_TYPE_PASSAGE     },
    { eHighmaulGameobjects::ThroneRoomDoor,     eHighmaulDatas::BossImperatorMargok,    DoorType::DOOR_TYPE_ROOM        },
    { eHighmaulGameobjects::StairBlockingDoor,  eHighmaulDatas::BossImperatorMargok,    DoorType::DOOR_TYPE_ROOM        },
    { eHighmaulGameobjects::StairBlockingDoor,  eHighmaulDatas::BossImperatorMargok,    DoorType::DOOR_TYPE_ROOM        },
    { eHighmaulGameobjects::StairBlockingDoor,  eHighmaulDatas::BossImperatorMargok,    DoorType::DOOR_TYPE_ROOM        },
    { 0,                                        0,                                      DoorType::DOOR_TYPE_ROOM        } ///< End
};

class instance_highmaul : public InstanceMapScript
{
    public:
        instance_highmaul() : InstanceMapScript("instance_highmaul", 1228) { }

        struct instance_highmaul_InstanceMapScript : public InstanceScript
        {
            instance_highmaul_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
            {
                m_Initialized               = false;
                m_ForTests                  = false;
                m_KargathAchievement        = true;
                m_ArenaElevatorActivated    = false;

                m_IronBombersCount          = 0;
                m_DrunkenBileslingerCount   = 0;
                m_MaggotKilled              = 0;
                m_BrackensporeAchievement   = false;
                m_MoteOfTectusTime          = 0;
                m_TectusAchievement         = false;
                m_GuardiansGuids.resize(eHighmaulDatas::MaxTectusGuardians);
                m_TwinOgronAchievement      = true;

                m_OverflowingEnergies       = 0;
                m_NullificationBarrier      = false;

                m_ImperatorAchievement      = false;

                m_PlayerPhases.clear();
            }

            bool m_Initialized;
            bool m_ForTests;

            uint32 m_DungeonID;

            ObjectGuid m_ArenaMasterGuid;

            /// The Coliseum
            ObjectGuid m_KargathBladefistGuid;
            bool   m_KargathAchievement;
            ObjectGuid m_JhornTheMadGuid;
            ObjectGuid m_ThoktarIronskullGuid;
            ObjectGuid m_ArenaElevatorGuid;
            bool   m_ArenaElevatorActivated;
            ObjectGuid m_CollisionWallGuid;
            ObjectGuid m_VulgorGuid;
            ObjectGuid m_GateArenaInnerGuid;
            ObjectGuid m_CrowdAreatriggerGuid;
            ObjectGuid m_MargokCosmeticGuid;
            ObjectGuid m_RaidGrateGuids[4];
            uint8  m_IronBombersCount;
            uint8  m_DrunkenBileslingerCount;

            /// The Underbelly
            ObjectGuid m_TheButcherGuid;
            uint8  m_MaggotKilled;

            /// Gorian Strand
            ObjectGuid m_BrackensporeGuid;
            bool   m_BrackensporeAchievement;

            /// The Market
            ObjectGuid m_TectusGuid;
            uint32 m_MoteOfTectusTime;
            bool   m_TectusAchievement;
            std::vector<ObjectGuid> m_GuardiansGuids;
            ObjectGuid m_ColiseumLFRDoor;

            /// The Gorthenon
            ObjectGuid m_PhemosGuid;
            ObjectGuid m_PolGuid;
            bool   m_TwinOgronAchievement;

            /// Chamber of Nullification
            ObjectGuid m_KoraghGuid;
            uint8  m_OverflowingEnergies;
            bool   m_NullificationBarrier;

            /// Throne of the Imperator
            ObjectGuid m_ImperatorMargokGuid;
            ObjectGuid m_HighCouncilorMalgris;
            bool   m_ImperatorAchievement;

            /// Phasing
            std::map<uint32, uint32> m_PlayerPhases;

            void Initialize() override
            {
                SetBossNumber(eHighmaulDatas::MaxHighmaulBosses);
                LoadDoorData(g_DoorData);
            }

            void OnCreatureCreate(Creature* creature) override
            {
                switch (creature->GetEntry())
                {
                    case eHighmaulCreatures::GhargArenaMaster:
                        m_ArenaMasterGuid = creature->GetGUID();
                        break;
                    case eHighmaulCreatures::KargathBladefist:
                        m_KargathBladefistGuid = creature->GetGUID();
                        break;
                    case eHighmaulCreatures::JhornTheMad:
                        m_JhornTheMadGuid = creature->GetGUID();
                        break;
                    case eHighmaulCreatures::ThoktarIronskull:
                        m_ThoktarIronskullGuid = creature->GetGUID();
                        break;
                    case eHighmaulCreatures::Vulgor:
                        m_VulgorGuid = creature->GetGUID();
                        break;
                    case eHighmaulCreatures::CrowdAreatrigger:
                        m_CrowdAreatriggerGuid = creature->GetGUID();
                        break;
                    case eHighmaulCreatures::MargokCosmetic:
                        m_MargokCosmeticGuid = creature->GetGUID();
                        break;
                    case eHighmaulCreatures::IronBomberSpawner:
                        creature->SetReactState(ReactStates::REACT_PASSIVE);
                        creature->AddUnitFlag(UnitFlags(UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE));
                        break;
                    case eHighmaulCreatures::IronBomber:
                        if (!m_IronBombersCount)
                            SendUpdateWorldState(eHighmaulWorldStates::IronBomberEnable, 1);
                        ++m_IronBombersCount;
                        SendUpdateWorldState(eHighmaulWorldStates::IronBomberRemaining, m_IronBombersCount);
                        break;
                    case eHighmaulCreatures::DrunkenBileslinger:
                        if (!m_DrunkenBileslingerCount)
                            SendUpdateWorldState(eHighmaulWorldStates::DrunkenBileslingerEnable, 1);
                        ++m_DrunkenBileslingerCount;
                        SendUpdateWorldState(eHighmaulWorldStates::DrunkenBileslingerRemaining, m_DrunkenBileslingerCount);
                        break;
                    case eHighmaulCreatures::TheButcher:
                        m_TheButcherGuid = creature->GetGUID();
                        break;
                    case eHighmaulCreatures::Brackenspore:
                        m_BrackensporeGuid = creature->GetGUID();
                        break;
                    case eHighmaulCreatures::Tectus:
                        m_TectusGuid = creature->GetGUID();
                        break;
                    case eHighmaulCreatures::Rokka:
                    case eHighmaulCreatures::Oro:
                    case eHighmaulCreatures::Lokk:
                        m_GuardiansGuids[creature->GetEntry() - eHighmaulCreatures::Rokka] = creature->GetGUID();
                        break;
                    case eHighmaulCreatures::Phemos:
                        m_PhemosGuid = creature->GetGUID();
                        break;
                    case eHighmaulCreatures::Pol:
                        m_PolGuid = creature->GetGUID();
                        break;
                    case eHighmaulCreatures::Koragh:
                        m_KoraghGuid = creature->GetGUID();
                        break;
                    case eHighmaulCreatures::IronGrunt:
                    case eHighmaulCreatures::BlackrockGrunt:
                    case eHighmaulCreatures::LowBatchDeadPale:
                    case eHighmaulCreatures::NightTwistedPaleVis:
                    case eHighmaulCreatures::CosmeticGorianWarr:
                    case eHighmaulCreatures::GorianCivilian:
                    case eHighmaulCreatures::RuneOfNullification:
                        creature->SetReactState(ReactStates::REACT_PASSIVE);
                        creature->AddUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC));
                        creature->AddUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE));
                        break;
                    case eHighmaulCreatures::ImperatorMargok:
                        m_ImperatorMargokGuid = creature->GetGUID();
                        break;
                    case eHighmaulCreatures::HighCouncilorMalgris:
                        m_HighCouncilorMalgris = creature->GetGUID();
                        break;
                    default:
                        break;
                }
            }

            void OnCreatureRemove(Creature* creature) override
            {
                switch (creature->GetEntry())
                {
                    case eHighmaulCreatures::IronBomber:
                    {
                        if (!m_IronBombersCount)
                            break;

                        --m_IronBombersCount;
                        SendUpdateWorldState(eHighmaulWorldStates::IronBomberRemaining, m_IronBombersCount);

                        if (!m_IronBombersCount)
                        {
                            SendUpdateWorldState(eHighmaulWorldStates::IronBomberEnable, 0);
                            break;
                        }

                        break;
                    }
                    case eHighmaulCreatures::DrunkenBileslinger:
                    {
                        if (!m_DrunkenBileslingerCount)
                            break;

                        --m_DrunkenBileslingerCount;
                        SendUpdateWorldState(eHighmaulWorldStates::DrunkenBileslingerRemaining, m_DrunkenBileslingerCount);

                        if (!m_DrunkenBileslingerCount)
                        {
                            SendUpdateWorldState(eHighmaulWorldStates::DrunkenBileslingerEnable, 0);
                            break;
                        }

                        break;
                    }
                    default:
                        break;
                }
            }

            void OnGameObjectCreate(GameObject* gameObject) override
            {
                switch (gameObject->GetEntry())
                {
                    case eHighmaulGameobjects::GateArenaExit:
                        if (!instance->IsLFR())
                            AddDoor(gameObject, true);
                        break;
                    case eHighmaulGameobjects::FungalGiantDoor:
                    case eHighmaulGameobjects::EarthenPillar:
                    case eHighmaulGameobjects::WindDoor:
                    case eHighmaulGameobjects::Earthwall1:
                    case eHighmaulGameobjects::Earthwall2:
                    case eHighmaulGameobjects::Earthwall3:
                    case eHighmaulGameobjects::Earthwall4:
                    case eHighmaulGameobjects::TwinOgronEntrance:
                    case eHighmaulGameobjects::TwinOgronExit:
                    case eHighmaulGameobjects::FelBreakerEntrance:
                    case eHighmaulGameobjects::FelBreakerExitDoor:
                    case eHighmaulGameobjects::ThroneRoomDoor:
                    case eHighmaulGameobjects::StairBlockingDoor:
                    case eHighmaulGameobjects::HighmaulLFRDoor:
                        AddDoor(gameObject, true);
                        break;
                    case eHighmaulGameobjects::ArenaElevator:
                        m_ArenaElevatorGuid = gameObject->GetGUID();
                        gameObject->SetTransportState(GOState::GO_STATE_TRANSPORT_ACTIVE);
                        break;
                    case eHighmaulGameobjects::CollisionWall:
                        m_CollisionWallGuid = gameObject->GetGUID();
                        gameObject->SetGoState(GOState::GO_STATE_ACTIVE);
                        break;
                    case eHighmaulGameobjects::GateArenaInner:
                        m_GateArenaInnerGuid = gameObject->GetGUID();
                        break;
                    case eHighmaulGameobjects::RaidGrate1:
                        m_RaidGrateGuids[eHighmaulDatas::RaidGrate001] = gameObject->GetGUID();
                        break;
                    case eHighmaulGameobjects::RaidGrate2:
                        m_RaidGrateGuids[eHighmaulDatas::RaidGrate002] = gameObject->GetGUID();
                        break;
                    case eHighmaulGameobjects::RaidGrate3:
                        m_RaidGrateGuids[eHighmaulDatas::RaidGrate003] = gameObject->GetGUID();
                        break;
                    case eHighmaulGameobjects::RaidGrate4:
                        m_RaidGrateGuids[eHighmaulDatas::RaidGrate004] = gameObject->GetGUID();
                        break;
                    case eHighmaulGameobjects::HighmaulLFRDoorColiseum:
                        m_ColiseumLFRDoor = gameObject->GetGUID();
                        break;
                    default:
                        break;
                }
            }

            void OnGameObjectRemove(GameObject* gameObject) override
            {
                switch (gameObject->GetEntry())
                {
                    case eHighmaulGameobjects::GateArenaExit:
                        if (!instance->IsLFR())
                            AddDoor(gameObject, false);
                        break;
                    case eHighmaulGameobjects::FungalGiantDoor:
                    case eHighmaulGameobjects::EarthenPillar:
                    case eHighmaulGameobjects::WindDoor:
                    case eHighmaulGameobjects::Earthwall1:
                    case eHighmaulGameobjects::Earthwall2:
                    case eHighmaulGameobjects::Earthwall3:
                    case eHighmaulGameobjects::Earthwall4:
                    case eHighmaulGameobjects::TwinOgronEntrance:
                    case eHighmaulGameobjects::TwinOgronExit:
                    case eHighmaulGameobjects::FelBreakerEntrance:
                    case eHighmaulGameobjects::FelBreakerExitDoor:
                    case eHighmaulGameobjects::ThroneRoomDoor:
                    case eHighmaulGameobjects::StairBlockingDoor:
                    case eHighmaulGameobjects::HighmaulLFRDoor:
                        AddDoor(gameObject, false);
                        break;
                    default:
                        break;
                }
            }

            bool SetBossState(uint32 bossId, EncounterState state) override
            {
                if (!InstanceScript::SetBossState(bossId, state))
                    return false;

                switch (bossId)
                {
                    case eHighmaulDatas::BossKargathBladefist:
                    {
                        switch (state)
                        {
                            case EncounterState::FAIL:
                            case EncounterState::NOT_STARTED:
                            {
                                m_KargathAchievement = true;
                                break;
                            }
                            case EncounterState::DONE:
                            {
                                SendUpdateWorldState(eHighmaulWorldStates::DisableCrowdSound, 1);
                                SendUpdateWorldState(eHighmaulWorldStates::UnknownHighmaulWorldState, 0);
                                SendUpdateWorldState(eHighmaulWorldStates::UnknownHighmaulWorldState2, 0);
                                PlaySceneForPlayers(g_PlayScenePos, 1338);
                                DoCastSpellOnPlayers(eHighmaulSpells::ChogallNight);

                                if (!instance->IsLFR() && m_KargathAchievement)
                                    DoCompleteAchievement(eHighmaulAchievements::FlameOn);

                                break;
                            }
                            default:
                                break;
                        }

                        break;
                    }
                    case eHighmaulDatas::BossTheButcher:
                    {
                        switch (state)
                        {
                            case EncounterState::FAIL:
                            case EncounterState::NOT_STARTED:
                            {
                                m_MaggotKilled = 0;
                                break;
                            }
                            case EncounterState::DONE:
                            {
                                if (!instance->IsLFR() && m_MaggotKilled >= eHighmaulDatas::MaxMaggotToKill)
                                    DoCompleteAchievement(eHighmaulAchievements::HurryUpMaggot);

                                break;
                            }
                            default:
                                break;
                        }

                        break;
                    }
                    case eHighmaulDatas::BossTectus:
                    {
                        switch (state)
                        {
                            case EncounterState::FAIL:
                            case EncounterState::NOT_STARTED:
                            {
                                m_MoteOfTectusTime  = 0;
                                m_TectusAchievement = false;
                                break;
                            }
                            case EncounterState::DONE:
                            {
                                if (!instance->IsLFR() && m_TectusAchievement)
                                    DoCompleteAchievement(eHighmaulAchievements::MoreLikeWreckedUs);

                                break;
                            }
                            default:
                                break;
                        }

                        break;
                    }
                    case eHighmaulDatas::BossBrackenspore:
                    {
                        switch (state)
                        {
                            case EncounterState::FAIL:
                            case EncounterState::NOT_STARTED:
                            {
                                m_BrackensporeAchievement = false;
                                break;
                            }
                            case EncounterState::DONE:
                            {
                                if (!instance->IsLFR() && m_BrackensporeAchievement)
                                    DoCompleteAchievement(eHighmaulAchievements::AFungusAmongUs);

                                break;
                            }
                            default:
                                break;
                        }

                        break;
                    }
                    case eHighmaulDatas::BossTwinOgron:
                    {
                        switch (state)
                        {
                            case EncounterState::FAIL:
                            case EncounterState::NOT_STARTED:
                            {
                                m_TwinOgronAchievement = true;
                                break;
                            }
                            case EncounterState::DONE:
                            {
                                if (!instance->IsLFR() && m_TwinOgronAchievement)
                                    DoCompleteAchievement(eHighmaulAchievements::BrothersInArms);

                                break;
                            }
                            default:
                                break;
                        }

                        break;
                    }
                    case eHighmaulDatas::BossKoragh:
                    {
                        switch (state)
                        {
                            case EncounterState::FAIL:
                            case EncounterState::NOT_STARTED:
                            {
                                m_OverflowingEnergies = 0;
                                m_NullificationBarrier = false;
                                break;
                            }
                            case EncounterState::DONE:
                            {
                                if (!instance->IsLFR() && m_NullificationBarrier && m_OverflowingEnergies < eHighmaulDatas::MaxOverflowingEnergy)
                                    DoCompleteAchievement(eHighmaulAchievements::PairAnnihilation);

                                break;
                            }
                            default:
                                break;
                        }

                        break;
                    }
                    case eHighmaulDatas::BossImperatorMargok:
                    {
                        switch (state)
                        {
                            case EncounterState::FAIL:
                            case EncounterState::NOT_STARTED:
                            {
                                m_ImperatorAchievement = false;
                                break;
                            }
                            case EncounterState::DONE:
                            {
                                if (!instance->IsLFR() && m_ImperatorAchievement)
                                    DoCompleteAchievement(eHighmaulAchievements::LineageOfPower);

                                if (instance->IsMythic())
                                {
                                    DoCompleteAchievement(eHighmaulAchievements::AheadOfTheCurve);
                                    DoCompleteAchievement(eHighmaulAchievements::CuttingEdge);
                                }
                                else if (instance->IsHeroic())
                                    DoCompleteAchievement(eHighmaulAchievements::AheadOfTheCurve);

                                break;
                            }
                            default:
                                break;
                        }

                        break;
                    }
                    default:
                        break;
                }

                return true;
            }

            void SetData(uint32 type, uint32 data) override
            {
                switch (type)
                {
                    case eHighmaulDatas::ElevatorActivated:
                    {
                        m_ArenaElevatorActivated = data;
                        break;
                    }
                    case eHighmaulDatas::KargathAchievement:
                    {
                        /// Defeat Kargath Bladefist in Highmaul without destroying any Fire Pillars on Normal difficulty or higher.
                        m_KargathAchievement = false;
                        break;
                    }
                    case eHighmaulDatas::ButcherAchievement:
                    {
                        /// Cause the Butcher in Highmaul to slay 6 Maggots before defeating him on Normal difficulty or higher.
                        m_MaggotKilled++;
                        break;
                    }
                    case eHighmaulDatas::TectusAchievement:
                    {
                        if (!m_MoteOfTectusTime)
                            m_MoteOfTectusTime = data;
                        else
                        {
                            /// Defeat Tectus in Highmaul by destroying all eight Motes of Tectus within 10 seconds of each other on Normal difficulty or higher.
                            if (data > (m_MoteOfTectusTime + 10))
                                m_TectusAchievement = false;
                            else
                                m_TectusAchievement = true;
                        }
                        break;
                    }
                    case eHighmaulDatas::BrackensporeAchievement:
                    {
                        /// Gain 15 stacks of Burning Infusion and then defeat Brackenspore in Highmaul on Normal difficulty or higher.
                        m_BrackensporeAchievement = true;
                        break;
                    }
                    case eHighmaulDatas::TwinOgronAchievement:
                    {
                        /// Defeat the Twin Ogron in Highmaul without their Disposition ever exceeding 30% on Normal difficulty or higher.
                        m_TwinOgronAchievement = false;
                        break;
                    }
                    /// Defeat Ko'ragh in Highmaul with fewer than 15 Overflowing Energy orbs touching the ground or players without Nullification Barrier, on Normal difficulty or higher.
                    case eHighmaulDatas::KoraghOverflowingEnergy:
                    {
                        ++m_OverflowingEnergies;
                        break;
                    }
                    case eHighmaulDatas::KoraghNullificationBarrier:
                    {
                        m_NullificationBarrier = true;
                        break;
                    }
                    case eHighmaulDatas::ImperatorAchievement:
                    {
                        /// Empower and defeat a Fortified Replicating Gorian Warmage and then defeat Imperator Mar'gok in Highmaul on Normal difficulty or higher.
                        m_ImperatorAchievement = true;
                        break;
                    }
                    default:
                        break;
                }
            }

            uint32 GetData(uint32 type) const override
            {
                switch (type)
                {
                    case eHighmaulDatas::ElevatorActivated:
                        return m_ArenaElevatorActivated;
                    case eHighmaulDatas::TestsActivated:
                        return m_ForTests;
                    case eHighmaulDatas::KoraghAchievement:
                        return !instance->IsLFR() && m_NullificationBarrier && m_OverflowingEnergies < eHighmaulDatas::MaxOverflowingEnergy;
                    default:
                        return 0;
                }
            }

            ObjectGuid GetGuidData(uint32 type) const override
            {
                switch (type)
                {
                    case eHighmaulCreatures::GhargArenaMaster:
                        return m_ArenaMasterGuid;
                    case eHighmaulCreatures::KargathBladefist:
                        return m_KargathBladefistGuid;
                    case eHighmaulCreatures::JhornTheMad:
                        return m_JhornTheMadGuid;
                    case eHighmaulCreatures::ThoktarIronskull:
                        return m_ThoktarIronskullGuid;
                    case eHighmaulCreatures::Vulgor:
                        return m_VulgorGuid;
                    case eHighmaulGameobjects::ArenaElevator:
                        return m_ArenaElevatorGuid;
                    case eHighmaulGameobjects::CollisionWall:
                        return m_CollisionWallGuid;
                    case eHighmaulGameobjects::GateArenaInner:
                        return m_GateArenaInnerGuid;
                    case eHighmaulCreatures::CrowdAreatrigger:
                        return m_CrowdAreatriggerGuid;
                    case eHighmaulCreatures::MargokCosmetic:
                        return m_MargokCosmeticGuid;
                    case eHighmaulCreatures::TheButcher:
                        return m_TheButcherGuid;
                    case eHighmaulCreatures::Brackenspore:
                        return m_BrackensporeGuid;
                    case eHighmaulGameobjects::RaidGrate1:
                        return m_RaidGrateGuids[eHighmaulDatas::RaidGrate001];
                    case eHighmaulGameobjects::RaidGrate2:
                        return m_RaidGrateGuids[eHighmaulDatas::RaidGrate002];
                    case eHighmaulGameobjects::RaidGrate3:
                        return m_RaidGrateGuids[eHighmaulDatas::RaidGrate003];
                    case eHighmaulGameobjects::RaidGrate4:
                        return m_RaidGrateGuids[eHighmaulDatas::RaidGrate004];
                    case eHighmaulCreatures::Tectus:
                        return m_TectusGuid;
                    case eHighmaulCreatures::Rokka:
                    case eHighmaulCreatures::Oro:
                    case eHighmaulCreatures::Lokk:
                        return m_GuardiansGuids[type - eHighmaulCreatures::Rokka];
                    case eHighmaulCreatures::Phemos:
                        return m_PhemosGuid;
                    case eHighmaulCreatures::Pol:
                        return m_PolGuid;
                    case eHighmaulCreatures::Koragh:
                        return m_KoraghGuid;
                    case eHighmaulCreatures::ImperatorMargok:
                        return m_ImperatorMargokGuid;
                    case eHighmaulCreatures::HighCouncilorMalgris:
                        return m_HighCouncilorMalgris;
                    default:
                        break;
                }

                return ObjectGuid::Empty;
            }

            bool CheckRequiredBosses(uint32 bossId, Player const* player = nullptr) const override
            {
                /// Bypass required bosses for PTR tests
                if (m_ForTests)
                    return true;

                if (!InstanceScript::CheckRequiredBosses(bossId, player))
                    return false;

                /// Highmaul has 4 main encounters (Kargath Bladefist, Ko'ragh, Twin Ogron, Imperator Mar'gok).
                /// There are also three optional encounters - The Butcher, Brackenspore and Tectus.
                switch (bossId)
                {
                    case eHighmaulDatas::BossTwinOgron:
                        if (m_DungeonID != eHighmaulDungeons::ArcaneSanctum && GetBossState(eHighmaulDatas::BossKargathBladefist) != EncounterState::DONE)
                            return false;
                        break;
                    case eHighmaulDatas::BossKoragh:
                        if (GetBossState(bossId - 1) != EncounterState::DONE)
                            return false;
                        break;
                    case eHighmaulDatas::BossImperatorMargok:
                        if (m_DungeonID != eHighmaulDungeons::ImperatorsFall && GetBossState(bossId - 1) != EncounterState::DONE)
                            return false;
                        break;
                    default:
                        break;
                }

                return true;
            }

            void FillInitialWorldStates(WorldPackets::WorldState::InitWorldStates& packet) override
            {
                packet.Worldstates.emplace_back(uint32(eHighmaulWorldStates::IronBomberEnable), 0);
                packet.Worldstates.emplace_back(uint32(eHighmaulWorldStates::IronBomberRemaining), 0);
                packet.Worldstates.emplace_back(uint32(eHighmaulWorldStates::DrunkenBileslingerEnable), 0);
                packet.Worldstates.emplace_back(uint32(eHighmaulWorldStates::DrunkenBileslingerRemaining), 0);
            }

            void OnPlayerEnter(Player* player) override
            {
                InstanceScript::OnPlayerEnter(player);

                bool chogallNight = false;
                if (GetBossState(eHighmaulDatas::BossKargathBladefist) == EncounterState::DONE)
                {
                    chogallNight = true;

                    /// We don't need to update the enter pos if player is summoned by his allies
                    if (!player->IsSummon())
                    {
                        ObjectGuid guid = player->GetGUID();
                        AddTimedDelayedOperation(200, [this, guid]() -> void
                        {
                            if (Player* player = ObjectAccessor::FindPlayer(guid))
                            {
                                if (GetBossState(eHighmaulDatas::BossKoragh) == EncounterState::DONE)
                                    player->NearTeleportTo(eHighmaulLocs::FelBreakerRoom);
                                else if (GetBossState(eHighmaulDatas::BossTectus) == EncounterState::DONE)
                                    player->NearTeleportTo(eHighmaulLocs::PalaceFrontGate);
                                else if (GetBossState(eHighmaulDatas::BossTheButcher) == EncounterState::DONE)
                                    player->NearTeleportTo(eHighmaulLocs::BeachEntrance);
                                else
                                    player->NearTeleportTo(eHighmaulLocs::KargathDefeated);
                            }
                        });
                    }
                }

                /// Disable non available bosses for LFR
                /*if (!m_Initialized)
                {
                    m_Initialized = true;

                    m_DungeonID = player->GetGroup() ? sLFGMgr->GetDungeon(player->GetGroup()->GetGUID()) : 0;

                    if (!instance->IsLFR())
                        m_DungeonID = 0;

                    switch (m_DungeonID)
                    {
                        case eHighmaulDungeons::WalledCity:
                        {
                            uint32 l_DisabledMask = 0;

                            l_DisabledMask |= (1 << eHighmaulDatas::BossTectus);
                            l_DisabledMask |= (1 << eHighmaulDatas::BossTwinOgron);
                            l_DisabledMask |= (1 << eHighmaulDatas::BossKoragh);
                            l_DisabledMask |= (1 << eHighmaulDatas::BossImperatorMargok);

                            SetDisabledBosses(l_DisabledMask);
                            break;
                        }
                        case eHighmaulDungeons::ArcaneSanctum:
                        {
                            uint32 l_DisabledMask = 0;

                            l_DisabledMask |= (1 << eHighmaulDatas::BossKargathBladefist);
                            l_DisabledMask |= (1 << eHighmaulDatas::BossTheButcher);
                            l_DisabledMask |= (1 << eHighmaulDatas::BossBrackenspore);
                            l_DisabledMask |= (1 << eHighmaulDatas::BossImperatorMargok);

                            SetDisabledBosses(l_DisabledMask);

                            if (GameObject* l_Door = ObjectAccessor::GetGameObject(*mem_ColiseumLFRDoor))
                                l_Door->SetGoState(GOState::GO_STATE_ACTIVE);

                            break;
                        }
                        case eHighmaulDungeons::ImperatorsFall:
                        {
                            uint32 l_DisabledMask = 0;

                            l_DisabledMask |= (1 << eHighmaulDatas::BossKargathBladefist);
                            l_DisabledMask |= (1 << eHighmaulDatas::BossTheButcher);
                            l_DisabledMask |= (1 << eHighmaulDatas::BossBrackenspore);
                            l_DisabledMask |= (1 << eHighmaulDatas::BossTectus);
                            l_DisabledMask |= (1 << eHighmaulDatas::BossTwinOgron);
                            l_DisabledMask |= (1 << eHighmaulDatas::BossKoragh);

                            SetDisabledBosses(l_DisabledMask);
                            break;
                        }
                        default:
                            break;
                    }
                }*/

                switch (m_DungeonID)
                {
                    case eHighmaulDungeons::ArcaneSanctum:
                    case eHighmaulDungeons::ImperatorsFall:
                        chogallNight = true;
                        break;
                    default:
                        break;
                }

                if (chogallNight)
                {
                    player->GetPhaseShift().AddPhase(eHighmaulDatas::PhaseKargathDefeated, PhaseFlags::None, nullptr);
                    player->CastSpell(player, eHighmaulSpells::ChogallNight, true);
                }
                else
                {
                    player->GetPhaseShift().RemovePhase(eHighmaulDatas::PhaseKargathDefeated);
                    player->RemoveAura(eHighmaulSpells::PlayChogallScene);
                    player->RemoveAura(eHighmaulSpells::ChogallNight);
                }
            }

            void OnPlayerExit(Player* player) override
            {
                InstanceScript::OnPlayerExit(player);

                player->RemoveAura(eHighmaulSpells::PlayChogallScene);
                player->RemoveAura(eHighmaulSpells::ChogallNight);
                player->GetPhaseShift().RemovePhase(eHighmaulDatas::PhaseKargathDefeated);
            }

            void SendUpdateWorldState(uint32 p_Field, uint32 value)
            {
                Map::PlayerList const& players = instance->GetPlayers();
                for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                {
                    if (Player* player = itr->GetSource())
                        player->SendUpdateWorldState(p_Field, value);
                }
            }

            void PlaySceneForPlayers(Position const /*pos*/, uint32 scenePackageID)
            {
                Map::PlayerList const& players = instance->GetPlayers();
                for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                {
                    if (Player* player = itr->GetSource())
                    {
                        player->GetSceneMgr().PlaySceneByPackageId(scenePackageID);
                        player->GetPhaseShift().AddPhase(eHighmaulDatas::PhaseKargathDefeated, PhaseFlags::None, nullptr);
                    }
                }
            }

            void Update(uint32 diff) override
            {
                UpdateOperations(diff);
                UpdateCombatResurrection(diff);
            }
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
            return new instance_highmaul_InstanceMapScript(map);
        }
};

void AddSC_instance_highmaul()
{
    new instance_highmaul();
}
