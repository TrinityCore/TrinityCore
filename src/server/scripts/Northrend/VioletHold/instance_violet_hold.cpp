/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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
#include "Creature.h"
#include "CreatureAI.h"
#include "GameObject.h"
#include "InstanceScript.h"
#include "Map.h"
#include "MotionMaster.h"
#include "Player.h"
#include "TaskScheduler.h"
#include "TemporarySummon.h"
#include "WorldStatePackets.h"
#include "violet_hold.h"

/*
 * TODO:
 * - replace bosses by dummy npcs also after grid unload
 */

Position const DefenseSystemLocation  = { 1888.146f, 803.382f,  58.60389f, 3.071779f }; // sniff

Position const CyanigosaSpawnLocation = { 1922.109f, 804.4493f, 52.49254f, 3.176499f }; // sniff
Position const CyanigosaJumpLocation  = { 1888.32f,  804.473f,  38.3578f,  0.0f      }; // sniff

Position const SaboteurSpawnLocation  = { 1886.251f, 803.0743f, 38.42326f, 3.211406f }; // sniff

uint32 const PortalPositionsSize = 5;
Position const PortalPositions[PortalPositionsSize] = // sniff
{
    { 1877.523f, 850.1788f, 45.36822f, 4.34587f   }, // 0
    { 1890.679f, 753.4202f, 48.771f,   1.675516f  }, // 1
    { 1936.09f,  803.1875f, 54.09715f, 3.054326f  }, // 2
    { 1858.243f, 770.2379f, 40.42146f, 0.9075712f }, // 3
    { 1907.288f, 831.1111f, 40.22015f, 3.560472f  }  // 4
};

uint32 const PortalElitePositionsSize = 3;
Position const PortalElitePositions[PortalElitePositionsSize] = // sniff
{
    { 1911.281f, 800.9722f, 39.91673f, 3.01942f  }, // 5
    { 1926.516f, 763.6616f, 52.35725f, 2.251475f }, // 6
    { 1922.464f, 847.0699f, 48.50161f, 3.961897f }  // 7
};

uint32 const PortalIntroPositionsSize = 5;
Position const PortalIntroPositions[PortalIntroPositionsSize] = // sniff
{
    { 1877.51f,  850.1042f, 44.65989f, 4.782202f }, // 0 - Intro
    { 1890.637f, 753.4705f, 48.72239f, 1.710423f }, // 1 - Intro
    { 1936.073f, 803.1979f, 53.37491f, 3.124139f }, // 2 - Intro
    { 1886.545f, 803.2014f, 40.40931f, 3.159046f }, // 3 - Boss 1/2
    { 1924.096f, 804.3707f, 54.29256f, 3.228859f }  // 4 - Boss 3
};

uint32 const EncouterPortalsCount = PortalPositionsSize + PortalElitePositionsSize;

uint32 const MoraggPathSize = 3;
Position const MoraggPath[MoraggPathSize] = // sniff
{
    { 1893.895f, 728.1261f, 47.75016f },
    { 1892.997f, 738.4987f, 47.66684f },
    { 1889.76f,  758.1089f, 47.66684f }
};

uint32 const ErekemPathSize = 3;
Position const ErekemPath[ErekemPathSize] = // sniff
{
    { 1871.456f, 871.0361f, 43.41524f },
    { 1874.948f, 859.5452f, 43.33349f },
    { 1877.245f, 851.967f,  43.3335f  }
};

uint32 const ErekemGuardLeftPathSize = 3;
Position const ErekemGuardLeftPath[ErekemGuardLeftPathSize] = // sniff
{
    { 1853.752f, 862.4528f, 43.41614f },
    { 1866.931f, 854.577f,  43.3335f  },
    { 1872.973f, 850.7875f, 43.3335f  }
};

uint32 const ErekemGuardRightPathSize = 3;
Position const ErekemGuardRightPath[ErekemGuardRightPathSize] = // sniff
{
    { 1892.418f, 872.2831f, 43.41563f },
    { 1885.639f, 859.0245f, 43.3335f  },
    { 1882.432f, 852.2423f, 43.3335f  }
};

uint32 const IchoronPathSize = 5;
Position const IchoronPath[IchoronPathSize] = // sniff
{
    { 1942.041f, 749.5228f, 30.95229f },
    { 1930.571f, 762.9065f, 31.98814f },
    { 1923.657f, 770.6718f, 34.07256f },
    { 1910.631f, 784.4096f, 37.09015f },
    { 1906.595f, 788.3828f, 37.99429f }
};

uint32 const LavanthorPathSize = 3;
Position const LavanthorPath[LavanthorPathSize] = // sniff
{
    { 1844.557f, 748.7083f, 38.74205f },
    { 1854.618f, 761.5295f, 38.65631f },
    { 1862.17f,  773.2255f, 38.74879f }
};

uint32 const XevozzPathSize = 3;
Position const XevozzPath[XevozzPathSize] = // sniff
{
    { 1908.417f, 845.8502f, 38.71947f },
    { 1905.557f, 841.3157f, 38.65529f },
    { 1899.453f, 832.533f,  38.70752f }
};

uint32 const ZuramatPathSize = 3;
Position const ZuramatPath[ZuramatPathSize] = // sniff
{
    { 1934.151f, 860.9463f, 47.29499f },
    { 1927.085f, 852.1342f, 47.19214f },
    { 1923.226f, 847.3297f, 47.15541f }
};

enum Yells
{
    SAY_CYANIGOSA_SPAWN                         = 3,
    SAY_XEVOZZ_SPAWN                            = 3,
    SAY_EREKEM_SPAWN                            = 3,
    SAY_ICHORON_SPAWN                           = 3,
    SAY_ZURAMAT_SPAWN                           = 3,

    SOUND_MORAGG_SPAWN                          = 10112
};

enum Spells
{
    SPELL_CYANIGOSA_TRANSFORM                   = 58668,
    SPELL_CYANIGOSA_ARCANE_POWER_STATE          = 49411,
    SPELL_MORAGG_EMOTE_ROAR                     = 48350,
    SPELL_LAVANTHOR_SPECIAL_UNARMED             = 33334,
    SPELL_ZURAMAT_COSMETIC_CHANNEL_OMNI         = 57552
};

ObjectData const creatureData[] =
{
    { NPC_XEVOZZ,           DATA_XEVOZZ           },
    { NPC_LAVANTHOR,        DATA_LAVANTHOR        },
    { NPC_ICHORON,          DATA_ICHORON          },
    { NPC_ZURAMAT,          DATA_ZURAMAT          },
    { NPC_EREKEM,           DATA_EREKEM           },
    { NPC_MORAGG,           DATA_MORAGG           },
    { NPC_CYANIGOSA,        DATA_CYANIGOSA        },
    { NPC_SINCLARI,         DATA_SINCLARI         },
    { NPC_SINCLARI_TRIGGER, DATA_SINCLARI_TRIGGER },
    { 0,                    0                     } // END
};

ObjectData const gameObjectData[] =
{
    { GO_EREKEM_GUARD_1_DOOR, DATA_EREKEM_LEFT_GUARD_CELL  },
    { GO_EREKEM_GUARD_2_DOOR, DATA_EREKEM_RIGHT_GUARD_CELL },
    { GO_EREKEM_DOOR,         DATA_EREKEM_CELL             },
    { GO_ZURAMAT_DOOR,        DATA_ZURAMAT_CELL            },
    { GO_LAVANTHOR_DOOR,      DATA_LAVANTHOR_CELL          },
    { GO_MORAGG_DOOR,         DATA_MORAGG_CELL             },
    { GO_ICHORON_DOOR,        DATA_ICHORON_CELL            },
    { GO_XEVOZZ_DOOR,         DATA_XEVOZZ_CELL             },
    { GO_MAIN_DOOR,           DATA_MAIN_DOOR               },
    { 0,                      0                            } // END
};

MinionData const minionData[] =
{
    { NPC_EREKEM_GUARD, DATA_EREKEM },
    { 0,                0           } // END
};

class instance_violet_hold : public InstanceMapScript
{
    public:
        instance_violet_hold() : InstanceMapScript(VioletHoldScriptName, 608) { }

        struct instance_violet_hold_InstanceMapScript : public InstanceScript
        {
            instance_violet_hold_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
            {
                SetHeaders(DataHeader);
                SetBossNumber(EncounterCount);
                LoadObjectData(creatureData, gameObjectData);
                LoadMinionData(minionData);

                FirstBossId         = 0;
                SecondBossId        = 0;

                DoorIntegrity       = 100;
                WaveCount           = 0;
                EventState          = NOT_STARTED;

                LastPortalLocation  = urand(0, EncouterPortalsCount - 1);

                Defenseless         = true;
            }

            void OnCreatureCreate(Creature* creature) override
            {
                InstanceScript::OnCreatureCreate(creature);

                switch (creature->GetEntry())
                {
                    case NPC_EREKEM_GUARD:
                        for (uint8 i = 0; i < ErekemGuardCount; ++i)
                            if (ErekemGuardGUIDs[i].IsEmpty())
                            {
                                ErekemGuardGUIDs[i] = creature->GetGUID();
                                break;
                            }
                        break;
                    default:
                        break;
                }
            }

            void OnCreatureRemove(Creature* creature) override
            {
                InstanceScript::OnCreatureRemove(creature);

                switch (creature->GetEntry())
                {
                    case NPC_EREKEM_GUARD:
                        for (uint8 i = 0; i < ErekemGuardCount; ++i)
                            if (ErekemGuardGUIDs[i] == creature->GetGUID())
                            {
                                ErekemGuardGUIDs[i].Clear();
                                break;
                            }
                        break;
                    default:
                        break;
                }
            }

            void OnGameObjectCreate(GameObject* go) override
            {
                InstanceScript::OnGameObjectCreate(go);

                switch (go->GetEntry())
                {
                    case GO_ACTIVATION_CRYSTAL:
                        for (uint8 i = 0; i < ActivationCrystalCount; ++i)
                            if (ActivationCrystalGUIDs[i].IsEmpty())
                            {
                                ActivationCrystalGUIDs[i] = go->GetGUID();
                                break;
                            }
                        break;
                    default:
                        break;
                }
            }

            void OnGameObjectRemove(GameObject* go) override
            {
                InstanceScript::OnGameObjectRemove(go);

                switch (go->GetEntry())
                {
                    case GO_ACTIVATION_CRYSTAL:
                        for (uint8 i = 0; i < ActivationCrystalCount; ++i)
                            if (ActivationCrystalGUIDs[i] == go->GetGUID())
                            {
                                ActivationCrystalGUIDs[i].Clear();
                                break;
                            }
                        break;
                    default:
                        break;
                }
            }

            void FillInitialWorldStates(WorldPackets::WorldState::InitWorldStates& data) override
            {
                data.Worldstates.emplace_back(uint32(WORLD_STATE_VH_SHOW), uint32(EventState == IN_PROGRESS ? 1 : 0));
                data.Worldstates.emplace_back(uint32(WORLD_STATE_VH_PRISON_STATE), uint32(DoorIntegrity));
                data.Worldstates.emplace_back(uint32(WORLD_STATE_VH_WAVE_COUNT), uint32(WaveCount));
            }

            bool CheckRequiredBosses(uint32 bossId, Player const* player = nullptr) const override
            {
                if (_SkipCheckRequiredBosses(player))
                    return true;

                switch (bossId)
                {
                    case DATA_MORAGG:
                    case DATA_EREKEM:
                    case DATA_ICHORON:
                    case DATA_LAVANTHOR:
                    case DATA_XEVOZZ:
                    case DATA_ZURAMAT:
                        /// old code used cell door state to check this
                        if (!(WaveCount == 6 && FirstBossId == bossId) && !(WaveCount == 12 && SecondBossId == bossId))
                            return false;
                        break;
                    case DATA_CYANIGOSA:
                        if (WaveCount < 18)
                            return false;
                        break;
                    default:
                        break;
                }

                return true;
            }

            bool SetBossState(uint32 type, EncounterState state) override
            {
                if (!InstanceScript::SetBossState(type, state))
                    return false;

                switch (type)
                {
                    case DATA_1ST_BOSS:
                        if (state == DONE)
                            UpdateEncounterStateForKilledCreature(NPC_EREKEM, nullptr);
                        break;
                    case DATA_2ND_BOSS:
                        if (state == DONE)
                            UpdateEncounterStateForKilledCreature(NPC_MORAGG, nullptr);
                        break;
                    case DATA_CYANIGOSA:
                        if (state == DONE)
                            SetData(DATA_MAIN_EVENT_STATE, DONE);
                        break;
                    case DATA_MORAGG:
                    case DATA_EREKEM:
                    case DATA_ICHORON:
                    case DATA_LAVANTHOR:
                    case DATA_XEVOZZ:
                    case DATA_ZURAMAT:
                        // this won't work correctly because bossstate was initializd with TO_BE_DECIDED
                        if (WaveCount == 6)
                            SetBossState(DATA_1ST_BOSS, state);
                        else if (WaveCount == 12)
                            SetBossState(DATA_2ND_BOSS, state);

                        if (state == DONE)
                            SetData(DATA_WAVE_COUNT, WaveCount + 1);
                        break;
                    default:
                        break;
                }

                return true;
            }

            void SetData(uint32 type, uint32 data) override
            {
                switch (type)
                {
                    case DATA_WAVE_COUNT:
                        WaveCount = data;
                        if (WaveCount)
                        {
                            Scheduler.Schedule(Seconds(IsBossWave(WaveCount - 1) ? 45 : 5), [this](TaskContext /*task*/)
                            {
                                AddWave();
                            });
                        }
                        break;
                    case DATA_DOOR_INTEGRITY:
                        DoorIntegrity = data;
                        Defenseless = false;
                        DoUpdateWorldState(WORLD_STATE_VH_PRISON_STATE, DoorIntegrity);
                        break;
                    case DATA_START_BOSS_ENCOUNTER:
                        switch (WaveCount)
                        {
                            case 6:
                                StartBossEncounter(FirstBossId);
                                break;
                            case 12:
                                StartBossEncounter(SecondBossId);
                                break;
                        }
                        break;
                    case DATA_MAIN_EVENT_STATE:
                        EventState = data;
                        if (data == IN_PROGRESS) // Start event
                        {
                            DoUpdateWorldState(WORLD_STATE_VH_WAVE_COUNT, WaveCount);
                            DoUpdateWorldState(WORLD_STATE_VH_PRISON_STATE, DoorIntegrity);
                            DoUpdateWorldState(WORLD_STATE_VH_SHOW, 1);

                            WaveCount = 1;
                            Scheduler.Async(std::bind(&instance_violet_hold_InstanceMapScript::AddWave, this));

                            for (uint8 i = 0; i < ActivationCrystalCount; ++i)
                                if (GameObject* crystal = instance->GetGameObject(ActivationCrystalGUIDs[i]))
                                    crystal->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
                        }
                        else if (data == NOT_STARTED)
                        {
                            if (GameObject* mainDoor = GetGameObject(DATA_MAIN_DOOR))
                            {
                                mainDoor->SetGoState(GO_STATE_ACTIVE);
                                mainDoor->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_LOCKED);
                            }

                            DoUpdateWorldState(WORLD_STATE_VH_SHOW, 0);
                            DoUpdateWorldState(WORLD_STATE_VH_WAVE_COUNT, WaveCount);
                            DoUpdateWorldState(WORLD_STATE_VH_PRISON_STATE, DoorIntegrity);

                            for (uint8 i = 0; i < ActivationCrystalCount; ++i)
                                if (GameObject* crystal = instance->GetGameObject(ActivationCrystalGUIDs[i]))
                                    crystal->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
                        }
                        else if (data == DONE)
                        {
                            if (GameObject* mainDoor = GetGameObject(DATA_MAIN_DOOR))
                            {
                                mainDoor->SetGoState(GO_STATE_ACTIVE);
                                mainDoor->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_LOCKED);
                            }

                            DoUpdateWorldState(WORLD_STATE_VH_SHOW, 0);

                            for (uint8 i = 0; i < ActivationCrystalCount; ++i)
                                if (GameObject* crystal = instance->GetGameObject(ActivationCrystalGUIDs[i]))
                                    crystal->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);

                            if (Creature* sinclari = GetCreature(DATA_SINCLARI))
                                sinclari->AI()->DoAction(ACTION_SINCLARI_OUTRO);
                        }
                        break;
                    case DATA_HANDLE_CELLS:
                        HandleCells(data, false);
                        break;
                }
            }

            uint32 GetData(uint32 type) const override
            {
                switch (type)
                {
                    case DATA_1ST_BOSS:
                        return FirstBossId;
                    case DATA_2ND_BOSS:
                        return SecondBossId;
                    case DATA_MAIN_EVENT_STATE:
                        return EventState;
                    case DATA_WAVE_COUNT:
                        return WaveCount;
                    case DATA_DOOR_INTEGRITY:
                        return DoorIntegrity;
                    case DATA_DEFENSELESS:
                        return Defenseless ? 1 : 0;
                    default:
                        break;
                }

                return 0;
            }

            ObjectGuid GetGuidData(uint32 type) const override
            {
                switch (type)
                {
                    case DATA_EREKEM_GUARD_1:
                    case DATA_EREKEM_GUARD_2:
                        return ErekemGuardGUIDs[type - DATA_EREKEM_GUARD_1];
                    default:
                        break;
                }

                return InstanceScript::GetGuidData(type);
            }

            void SpawnPortal()
            {
                LastPortalLocation = (LastPortalLocation + urand(1, EncouterPortalsCount - 1)) % (EncouterPortalsCount);
                if (Creature* sinclari = GetCreature(DATA_SINCLARI))
                {
                    if (LastPortalLocation < PortalPositionsSize)
                    {
                        if (Creature* portal = sinclari->SummonCreature(NPC_TELEPORTATION_PORTAL, PortalPositions[LastPortalLocation], TEMPSUMMON_CORPSE_DESPAWN))
                            portal->AI()->SetData(DATA_PORTAL_LOCATION, LastPortalLocation);
                    }
                    else
                    {
                        if (Creature* portal = sinclari->SummonCreature(NPC_TELEPORTATION_PORTAL_ELITE, PortalElitePositions[LastPortalLocation - PortalPositionsSize], TEMPSUMMON_CORPSE_DESPAWN))
                            portal->AI()->SetData(DATA_PORTAL_LOCATION, LastPortalLocation);
                    }
                }
            }

            void HandleCells(uint8 bossId, bool open = true)
            {
                switch (bossId)
                {
                    case DATA_MORAGG:
                        HandleGameObject(GetObjectGuid(DATA_MORAGG_CELL), open);
                        break;
                    case DATA_EREKEM:
                        HandleGameObject(GetObjectGuid(DATA_EREKEM_CELL), open);
                        HandleGameObject(GetObjectGuid(DATA_EREKEM_LEFT_GUARD_CELL), open);
                        HandleGameObject(GetObjectGuid(DATA_EREKEM_RIGHT_GUARD_CELL), open);
                        break;
                    case DATA_ICHORON:
                        HandleGameObject(GetObjectGuid(DATA_ICHORON_CELL), open);
                        break;
                    case DATA_LAVANTHOR:
                        HandleGameObject(GetObjectGuid(DATA_LAVANTHOR_CELL), open);
                        break;
                    case DATA_XEVOZZ:
                        HandleGameObject(GetObjectGuid(DATA_XEVOZZ_CELL), open);
                        break;
                    case DATA_ZURAMAT:
                        HandleGameObject(GetObjectGuid(DATA_ZURAMAT_CELL), open);
                        break;
                    default:
                        break;
                }
            }

            void StartBossEncounter(uint8 bossId)
            {
                switch (bossId)
                {
                    case DATA_MORAGG:
                        Scheduler.Schedule(Seconds(2), [this](TaskContext task)
                        {
                            if (Creature* moragg = GetCreature(DATA_MORAGG))
                            {
                                moragg->PlayDirectSound(SOUND_MORAGG_SPAWN);
                                moragg->CastSpell(moragg, SPELL_MORAGG_EMOTE_ROAR);
                            }

                            task.Schedule(Seconds(3), [this](TaskContext task)
                            {
                                if (Creature* moragg = GetCreature(DATA_MORAGG))
                                    moragg->GetMotionMaster()->MoveSmoothPath(POINT_INTRO, MoraggPath, MoraggPathSize, true);

                                task.Schedule(Seconds(8), [this](TaskContext /*task*/)
                                {
                                    if (Creature* moragg = GetCreature(DATA_MORAGG))
                                    {
                                        moragg->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC);
                                        moragg->AI()->DoZoneInCombat(moragg, 200.0f);
                                    }
                                });
                            });
                        });
                        break;
                    case DATA_EREKEM:
                        Scheduler.Schedule(Seconds(3), [this](TaskContext task)
                        {
                            if (Creature* erekem = GetCreature(DATA_EREKEM))
                                erekem->AI()->Talk(SAY_EREKEM_SPAWN);

                            task.Schedule(Seconds(5), [this](TaskContext task)
                            {
                                if (Creature* erekem = GetCreature(DATA_EREKEM))
                                    erekem->GetMotionMaster()->MoveSmoothPath(POINT_INTRO, ErekemPath, ErekemPathSize, true);

                                if (Creature* guard = instance->GetCreature(GetGuidData(DATA_EREKEM_GUARD_1)))
                                    guard->GetMotionMaster()->MoveSmoothPath(POINT_INTRO, ErekemGuardLeftPath, ErekemGuardLeftPathSize, true);
                                if (Creature* guard = instance->GetCreature(GetGuidData(DATA_EREKEM_GUARD_2)))
                                    guard->GetMotionMaster()->MoveSmoothPath(POINT_INTRO, ErekemGuardRightPath, ErekemGuardRightPathSize, true);

                                task.Schedule(Seconds(6), [this](TaskContext task)
                                {
                                    if (Creature* erekem = GetCreature(DATA_EREKEM))
                                        erekem->HandleEmoteCommand(EMOTE_ONESHOT_ROAR);

                                    task.Schedule(Seconds(1), [this](TaskContext /*task*/)
                                    {
                                        for (uint32 i = DATA_EREKEM_GUARD_1; i <= DATA_EREKEM_GUARD_2; ++i)
                                        {
                                            if (Creature* guard = instance->GetCreature(GetGuidData(i)))
                                                guard->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC);
                                        }

                                        if (Creature* erekem = GetCreature(DATA_EREKEM))
                                        {
                                            erekem->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC);
                                            erekem->AI()->DoZoneInCombat(erekem, 200.0f);
                                        }
                                    });
                                });
                            });
                        });
                        break;
                    case DATA_ICHORON:
                        Scheduler.Schedule(Seconds(2), [this](TaskContext task)
                        {
                            if (Creature* ichoron = GetCreature(DATA_ICHORON))
                                ichoron->AI()->Talk(SAY_ICHORON_SPAWN);

                            task.Schedule(Seconds(3), [this](TaskContext task)
                            {
                                if (Creature* ichoron = GetCreature(DATA_ICHORON))
                                    ichoron->GetMotionMaster()->MoveSmoothPath(POINT_INTRO, IchoronPath, IchoronPathSize, true);

                                task.Schedule(Seconds(14), [this](TaskContext /*task*/)
                                {
                                    if (Creature* ichoron = GetCreature(DATA_ICHORON))
                                    {
                                        ichoron->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC);
                                        ichoron->AI()->DoZoneInCombat(ichoron, 200.0f);
                                    }
                                });
                            });
                        });
                        break;
                    case DATA_LAVANTHOR:
                        Scheduler.Schedule(Seconds(1), [this](TaskContext task)
                        {
                            if (Creature* lavanthor = GetCreature(DATA_LAVANTHOR))
                                lavanthor->CastSpell(lavanthor, SPELL_LAVANTHOR_SPECIAL_UNARMED);

                            task.Schedule(Seconds(3), [this](TaskContext task)
                            {
                                if (Creature* lavanthor = GetCreature(DATA_LAVANTHOR))
                                    lavanthor->GetMotionMaster()->MoveSmoothPath(POINT_INTRO, LavanthorPath, LavanthorPathSize, true);

                                task.Schedule(Seconds(8), [this](TaskContext /*task*/)
                                {
                                    if (Creature* lavanthor = GetCreature(DATA_LAVANTHOR))
                                    {
                                        lavanthor->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC);
                                        lavanthor->AI()->DoZoneInCombat(lavanthor, 200.0f);
                                    }
                                });
                            });
                        });
                        break;
                    case DATA_XEVOZZ:
                        Scheduler.Schedule(Seconds(2), [this](TaskContext task)
                        {
                            if (Creature* xevozz = GetCreature(DATA_XEVOZZ))
                                xevozz->AI()->Talk(SAY_XEVOZZ_SPAWN);

                            task.Schedule(Seconds(3), [this](TaskContext task)
                            {
                                if (Creature* xevozz = GetCreature(DATA_XEVOZZ))
                                    xevozz->HandleEmoteCommand(EMOTE_ONESHOT_TALK_NO_SHEATHE);

                                task.Schedule(Seconds(4), [this](TaskContext task)
                                {
                                    if (Creature* xevozz = GetCreature(DATA_XEVOZZ))
                                        xevozz->GetMotionMaster()->MoveSmoothPath(POINT_INTRO, XevozzPath, XevozzPathSize, true);

                                    task.Schedule(Seconds(4), [this](TaskContext /*task*/)
                                    {
                                        if (Creature* xevozz = GetCreature(DATA_XEVOZZ))
                                        {
                                            xevozz->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC);
                                            xevozz->AI()->DoZoneInCombat(xevozz, 200.0f);
                                        }
                                    });
                                });
                            });
                        });
                        break;
                    case DATA_ZURAMAT:
                        Scheduler.Schedule(Seconds(2), [this](TaskContext task)
                        {
                            if (Creature* zuramat = GetCreature(DATA_ZURAMAT))
                            {
                                zuramat->CastSpell(zuramat, SPELL_ZURAMAT_COSMETIC_CHANNEL_OMNI);
                                zuramat->AI()->Talk(SAY_ZURAMAT_SPAWN);
                            }

                            task.Schedule(Seconds(6), [this](TaskContext task)
                            {
                                if (Creature* zuramat = GetCreature(DATA_ZURAMAT))
                                    zuramat->GetMotionMaster()->MoveSmoothPath(POINT_INTRO, ZuramatPath, ZuramatPathSize, true);

                                task.Schedule(Seconds(4), [this](TaskContext /*task*/)
                                {
                                    if (Creature* zuramat = GetCreature(DATA_ZURAMAT))
                                    {
                                        zuramat->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC);
                                        zuramat->AI()->DoZoneInCombat(zuramat, 200.0f);
                                    }
                                });
                            });
                        });
                        break;
                    default:
                        return;
                }

                HandleCells(bossId);
            }

            void ResetBossEncounter(uint8 bossId)
            {
                if (bossId < DATA_CYANIGOSA || bossId > DATA_ZURAMAT)
                    return;

                Creature* boss = GetCreature(bossId);
                if (!boss)
                    return;

                switch (bossId)
                {
                    case DATA_CYANIGOSA:
                        boss->DespawnOrUnsummon();
                        break;
                    case DATA_EREKEM:
                        for (uint32 i = DATA_EREKEM_GUARD_1; i <= DATA_EREKEM_GUARD_2; ++i)
                        {
                            if (Creature* guard = instance->GetCreature(GetGuidData(i)))
                            {
                                if (guard->isDead())
                                    guard->Respawn();

                                if (GetBossState(bossId) == DONE)
                                    UpdateKilledBoss(guard);

                                guard->GetMotionMaster()->MoveTargetedHome();
                                guard->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC);
                            }
                        }
                        // no break
                    default:
                        if (boss->isDead())
                        {
                            // respawn and update to a placeholder npc to avoid be looted again
                            boss->Respawn();
                            UpdateKilledBoss(boss);
                        }

                        boss->GetMotionMaster()->MoveTargetedHome();
                        boss->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC);
                        break;
                }
            }

            void AddWave()
            {
                DoUpdateWorldState(WORLD_STATE_VH_WAVE_COUNT, WaveCount);

                switch (WaveCount)
                {
                    case 6:
                        if (FirstBossId == 0)
                            FirstBossId = urand(DATA_MORAGG, DATA_ZURAMAT);
                        if (Creature* sinclari = GetCreature(DATA_SINCLARI))
                        {
                            sinclari->SummonCreature(NPC_TELEPORTATION_PORTAL_INTRO, PortalIntroPositions[3], TEMPSUMMON_TIMED_DESPAWN, 3000);
                            sinclari->SummonCreature(NPC_SABOTEOUR, SaboteurSpawnLocation, TEMPSUMMON_DEAD_DESPAWN);
                        }
                        break;
                    case 12:
                        if (SecondBossId == 0)
                            do
                            {
                                SecondBossId = urand(DATA_MORAGG, DATA_ZURAMAT);
                            } while (SecondBossId == FirstBossId);
                        if (Creature* sinclari = GetCreature(DATA_SINCLARI))
                        {
                            sinclari->SummonCreature(NPC_TELEPORTATION_PORTAL_INTRO, PortalIntroPositions[3], TEMPSUMMON_TIMED_DESPAWN, 3000);
                            sinclari->SummonCreature(NPC_SABOTEOUR, SaboteurSpawnLocation, TEMPSUMMON_DEAD_DESPAWN);
                        }
                        break;
                    case 18:
                        if (Creature* sinclari = GetCreature(DATA_SINCLARI))
                        {
                            sinclari->SummonCreature(NPC_TELEPORTATION_PORTAL_INTRO, PortalIntroPositions[4], TEMPSUMMON_TIMED_DESPAWN, 6000);
                            if (Creature* cyanigosa = sinclari->SummonCreature(NPC_CYANIGOSA, CyanigosaSpawnLocation, TEMPSUMMON_DEAD_DESPAWN))
                                cyanigosa->CastSpell(cyanigosa, SPELL_CYANIGOSA_ARCANE_POWER_STATE, true);
                            ScheduleCyanigosaIntro();
                        }
                        break;
                    default:
                        SpawnPortal();
                        break;
                }
            }

            void WriteSaveDataMore(std::ostringstream& data) override
            {
                data << FirstBossId << ' ' << SecondBossId;
            }

            void ReadSaveDataMore(std::istringstream& data) override
            {
                data >> FirstBossId;
                data >> SecondBossId;
            }

            bool CheckWipe() const
            {
                Map::PlayerList const& players = instance->GetPlayers();
                for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                {
                    Player* player = itr->GetSource();
                    if (player->IsGameMaster())
                        continue;

                    if (player->IsAlive())
                        return false;
                }

                return true;
            }

            void UpdateKilledBoss(Creature* boss)
            {
                switch (boss->GetEntry())
                {
                    case NPC_XEVOZZ:
                        boss->UpdateEntry(NPC_DUMMY_XEVOZZ);
                        break;
                    case NPC_LAVANTHOR:
                        boss->UpdateEntry(NPC_DUMMY_LAVANTHOR);
                        break;
                    case NPC_ICHORON:
                        boss->UpdateEntry(NPC_DUMMY_ICHORON);
                        break;
                    case NPC_ZURAMAT:
                        boss->UpdateEntry(NPC_DUMMY_ZURAMAT);
                        break;
                    case NPC_EREKEM:
                        boss->UpdateEntry(NPC_DUMMY_EREKEM);
                        break;
                    case NPC_MORAGG:
                        boss->UpdateEntry(NPC_DUMMY_MORAGG);
                        break;
                    case NPC_EREKEM_GUARD:
                        boss->UpdateEntry(NPC_DUMMY_EREKEM_GUARD);
                        break;
                    default:
                        break;
                }
            }

            void Update(uint32 diff) override
            {
                if (!instance->HavePlayers())
                    return;

                // if main event is in progress and players have wiped then reset instance
                if ((EventState == IN_PROGRESS && CheckWipe()) || EventState == FAIL)
                {
                    ResetBossEncounter(FirstBossId);
                    ResetBossEncounter(SecondBossId);
                    ResetBossEncounter(DATA_CYANIGOSA);

                    WaveCount = 0;
                    DoorIntegrity = 100;
                    Defenseless = true;
                    SetData(DATA_MAIN_EVENT_STATE, NOT_STARTED);

                    Scheduler.CancelAll();

                    if (Creature* sinclari = GetCreature(DATA_SINCLARI))
                        sinclari->AI()->EnterEvadeMode();
                }

                Scheduler.Update(diff);

                if (EventState == IN_PROGRESS)
                {
                    // if door is destroyed, event is failed
                    if (!GetData(DATA_DOOR_INTEGRITY))
                        EventState = FAIL;
                }
            }

            void ScheduleCyanigosaIntro()
            {
                Scheduler.Schedule(Seconds(2), [this](TaskContext task)
                {
                    if (Creature* cyanigosa = GetCreature(DATA_CYANIGOSA))
                        cyanigosa->AI()->Talk(SAY_CYANIGOSA_SPAWN);

                    task.Schedule(Seconds(6), [this](TaskContext task)
                    {
                        if (Creature* cyanigosa = GetCreature(DATA_CYANIGOSA))
                            cyanigosa->GetMotionMaster()->MoveJump(CyanigosaJumpLocation, 10.0f, 27.44744f);

                        task.Schedule(Seconds(7), [this](TaskContext /*task*/)
                        {
                            if (Creature* cyanigosa = GetCreature(DATA_CYANIGOSA))
                            {
                                cyanigosa->RemoveAurasDueToSpell(SPELL_CYANIGOSA_ARCANE_POWER_STATE);
                                cyanigosa->CastSpell(cyanigosa, SPELL_CYANIGOSA_TRANSFORM, true);
                                cyanigosa->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC);
                            }
                        });
                    });
                });
            }

            void ProcessEvent(WorldObject* /*go*/, uint32 eventId) override
            {
                if (eventId == EVENT_ACTIVATE_CRYSTAL)
                {
                    instance->SummonCreature(NPC_DEFENSE_SYSTEM, DefenseSystemLocation);
                    Defenseless = false;
                }
            }

            static bool IsBossWave(uint8 wave)
            {
                return wave && ((wave % 6) == 0);
            }

        protected:
            TaskScheduler Scheduler;

            static uint8 const ErekemGuardCount = 2;
            ObjectGuid ErekemGuardGUIDs[ErekemGuardCount];

            static uint8 const ActivationCrystalCount = 5;
            ObjectGuid ActivationCrystalGUIDs[ActivationCrystalCount];

            uint32 FirstBossId;
            uint32 SecondBossId;

            uint8 DoorIntegrity;
            uint8 WaveCount;
            uint8 EventState;
            uint8 LastPortalLocation;

            bool Defenseless;
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
            return new instance_violet_hold_InstanceMapScript(map);
        }
};

void AddSC_instance_violet_hold()
{
    new instance_violet_hold();
}
