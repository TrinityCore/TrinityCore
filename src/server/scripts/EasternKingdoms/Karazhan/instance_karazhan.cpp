/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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
#include "karazhan.h"
#include "Map.h"

/*
0  - Attumen + Midnight (optional)
1  - Moroes
2  - Maiden of Virtue (optional)
3  - Hyakiss the Lurker /  Rokad the Ravager  / Shadikith the Glider
4  - Opera Event
5  - Curator
6  - Shade of Aran (optional)
7  - Terestian Illhoof (optional)
8  - Netherspite (optional)
9  - Chess Event
10 - Prince Malchezzar
11 - Nightbane
*/

static constexpr ObjectData creatureData[] =
{
    { NPC_BARNES,                 DATA_BARNES                },
    { NPC_JULIANNE,               DATA_JULIANNE              },
    { NPC_ROMULO,                 DATA_ROMULO                },
    { 0,                          0                          } // END
};

static constexpr ObjectData gameObjectData[] =
{
    { GO_STAGE_CURTAIN,           DATA_GO_STAGE_CURTAIN      },
    { GO_STAGE_DOOR_LEFT,         DATA_GO_STAGE_DOOR_LEFT    },
    { GO_STAGE_DOOR_RIGHT,        DATA_GO_STAGE_DOOR_RIGHT   },
    { GO_SIDE_ENTRANCE_DOOR,      DATA_GO_SIDE_ENTRANCE_DOOR },
    { 0,                          0                          } // END
};

const Position OptionalSpawn[] =
{
    { -10960.981445f, -1940.138428f, 46.178097f, 4.12f  }, // Hyakiss the Lurker
    { -10945.769531f, -2040.153320f, 49.474438f, 0.077f }, // Shadikith the Glider
    { -10899.903320f, -2085.573730f, 49.474449f, 1.38f  }  // Rokad the Ravager
};

class instance_karazhan : public InstanceMapScript
{
public:
    instance_karazhan() : InstanceMapScript(KZScriptName, 532) { }

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_karazhan_InstanceMapScript(map);
    }

    struct instance_karazhan_InstanceMapScript : public InstanceScript
    {
        instance_karazhan_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
        {
            SetHeaders(DataHeader);
            SetBossNumber(EncounterCount);
            LoadObjectData(creatureData, gameObjectData);

            OperaEvent = RAND(EVENT_HOOD, EVENT_OZ, EVENT_RAJ);
            OzDeathCount = 0;
            OptionalBossCount = 0;
        }

        void OnCreatureCreate(Creature* creature) override
        {
            InstanceScript::OnCreatureCreate(creature);

            switch (creature->GetEntry())
            {
                case NPC_KILREK:
                    KilrekGUID = creature->GetGUID();
                    break;
                case NPC_TERESTIAN_ILLHOOF:
                    TerestianGUID = creature->GetGUID();
                    break;
                case NPC_MOROES:
                    MoroesGUID = creature->GetGUID();
                    break;
                case NPC_NIGHTBANE:
                    NightbaneGUID = creature->GetGUID();
                    break;
                default:
                    break;
            }
        }

        void OnUnitDeath(Unit* unit) override
        {
            Creature* creature = unit->ToCreature();
            if (!creature)
                return;

            switch (creature->GetEntry())
            {
                case NPC_COLDMIST_WIDOW:
                case NPC_COLDMIST_STALKER:
                case NPC_SHADOWBAT:
                case NPC_VAMPIRIC_SHADOWBAT:
                case NPC_GREATER_SHADOWBAT:
                case NPC_PHASE_HOUND:
                case NPC_DREADBEAST:
                case NPC_SHADOWBEAST:
                    if (GetBossState(DATA_OPTIONAL_BOSS) == TO_BE_DECIDED)
                    {
                        ++OptionalBossCount;
                        if (OptionalBossCount == OPTIONAL_BOSS_REQUIRED_DEATH_COUNT)
                        {
                            switch (urand(NPC_HYAKISS_THE_LURKER, NPC_ROKAD_THE_RAVAGER))
                            {
                                case NPC_HYAKISS_THE_LURKER:
                                    instance->SummonCreature(NPC_HYAKISS_THE_LURKER, OptionalSpawn[0]);
                                    break;
                                case NPC_SHADIKITH_THE_GLIDER:
                                    instance->SummonCreature(NPC_SHADIKITH_THE_GLIDER, OptionalSpawn[1]);
                                    break;
                                case NPC_ROKAD_THE_RAVAGER:
                                    instance->SummonCreature(NPC_ROKAD_THE_RAVAGER, OptionalSpawn[2]);
                                    break;
                            }
                        }
                    }
                    break;
                case NPC_HYAKISS_THE_LURKER:
                case NPC_SHADIKITH_THE_GLIDER:
                case NPC_ROKAD_THE_RAVAGER:
                    SetBossState(DATA_OPTIONAL_BOSS, DONE);
                    break;
                default:
                    break;
            }
        }

        void SetData(uint32 type, uint32 data) override
        {
            switch (type)
            {
                case DATA_OPERA_VARIATION:
                    OperaEvent = data;
                    break;
                case DATA_OPERA_OZ_DEATH_COUNT:
                    if (data == SPECIAL)
                        ++OzDeathCount;
                    break;
                default:
                    break;
            }
        }

        bool SetBossState(uint32 type, EncounterState state) override
        {
            if (!InstanceScript::SetBossState(type, state))
                return false;

            switch (type)
            {
                case DATA_OPERA_PERFORMANCE:
                    if (state == DONE)
                    {
                        if (GameObject* go = GetGameObject(DATA_GO_STAGE_DOOR_LEFT))
                            HandleGameObject(ObjectGuid::Empty, true, go);
                        if (GameObject* go = GetGameObject(DATA_GO_STAGE_DOOR_RIGHT))
                            HandleGameObject(ObjectGuid::Empty, true, go);
                        if (GameObject* go = GetGameObject(DATA_GO_SIDE_ENTRANCE_DOOR))
                            go->ActivateObject(GameObjectActions::Unlock);
                        if (Creature* barnes = GetCreature(DATA_BARNES))
                            barnes->AI()->DoAction(ACTION_OPERA_FINISHED);
                        UpdateEncounterStateForKilledCreature(NPC_BARNES, nullptr);
                    }
                    else if (state == FAIL)
                    {
                        OzDeathCount = 0;
                        if (GameObject* go = GetGameObject(DATA_GO_STAGE_DOOR_LEFT))
                            HandleGameObject(ObjectGuid::Empty, true, go);
                        if (GameObject* go = GetGameObject(DATA_GO_STAGE_CURTAIN))
                            HandleGameObject(ObjectGuid::Empty, false, go);
                        if (Creature* barnes = GetCreature(DATA_BARNES))
                            barnes->AI()->DoAction(ACTION_OPERA_FINISHED);
                    }
                    break;
                case DATA_CHESS:
                    if (state == DONE)
                        DoRespawnGameObject(DustCoveredChest, 24h);
                    break;
                default:
                    break;
            }

            return true;
        }

         void SetGuidData(uint32 type, ObjectGuid data) override
         {
             if (type == DATA_IMAGE_OF_MEDIVH)
                 ImageGUID = data;
         }

        void OnGameObjectCreate(GameObject* go) override
        {
            InstanceScript::OnGameObjectCreate(go);

            switch (go->GetEntry())
            {
                case GO_STAGE_DOOR_LEFT:
                    if (GetBossState(DATA_OPERA_PERFORMANCE) == DONE || GetBossState(DATA_OPERA_PERFORMANCE) == FAIL)
                        HandleGameObject(ObjectGuid::Empty, true, go);
                    break;
                case GO_STAGE_DOOR_RIGHT:
                    if (GetBossState(DATA_OPERA_PERFORMANCE) == DONE)
                        HandleGameObject(ObjectGuid::Empty, true, go);
                    break;
                case GO_PRIVATE_LIBRARY_DOOR:
                    LibraryDoor = go->GetGUID();
                    break;
                case GO_MASSIVE_DOOR:
                    MassiveDoor = go->GetGUID();
                    break;
                case GO_GAMESMAN_HALL_DOOR:
                    GamesmansDoor = go->GetGUID();
                    break;
                case GO_GAMESMAN_HALL_EXIT_DOOR:
                    GamesmansExitDoor = go->GetGUID();
                    break;
                case GO_NETHERSPACE_DOOR:
                    NetherspaceDoor = go->GetGUID();
                    break;
                case GO_MASTERS_TERRACE_DOOR:
                    MastersTerraceDoor[0] = go->GetGUID();
                    break;
                case GO_MASTERS_TERRACE_DOOR2:
                    MastersTerraceDoor[1] = go->GetGUID();
                    break;
                case GO_SIDE_ENTRANCE_DOOR:
                    if (GetBossState(DATA_OPERA_PERFORMANCE) == DONE)
                        go->ActivateObject(GameObjectActions::Unlock);
                    break;
                case GO_DUST_COVERED_CHEST:
                    DustCoveredChest = go->GetGUID();
                    break;
                case GO_BLACKENED_URN:
                    BlackenedUrnGUID = go->GetGUID();
                    break;
            }
        }

        uint32 GetData(uint32 type) const override
        {
            switch (type)
            {
                case DATA_OPERA_VARIATION:
                    return OperaEvent;
                case DATA_OPERA_OZ_DEATH_COUNT:
                    return OzDeathCount;
            }

            return 0;
        }

        ObjectGuid GetGuidData(uint32 type) const override
        {
            switch (type)
            {
                case DATA_KILREK:
                    return KilrekGUID;
                case DATA_TERESTIAN:
                    return TerestianGUID;
                case DATA_MOROES:
                    return MoroesGUID;
                case DATA_NIGHTBANE:
                    return NightbaneGUID;
                case DATA_GO_LIBRARY_DOOR:
                    return LibraryDoor;
                case DATA_GO_MASSIVE_DOOR:
                    return MassiveDoor;
                case DATA_GO_GAME_DOOR:
                    return GamesmansDoor;
                case DATA_GO_GAME_EXIT_DOOR:
                    return GamesmansExitDoor;
                case DATA_GO_NETHER_DOOR:
                    return NetherspaceDoor;
                case DATA_MASTERS_TERRACE_DOOR_1:
                    return MastersTerraceDoor[0];
                case DATA_MASTERS_TERRACE_DOOR_2:
                    return MastersTerraceDoor[1];
                case DATA_IMAGE_OF_MEDIVH:
                    return ImageGUID;
                case DATA_GO_BLACKENED_URN:
                    return BlackenedUrnGUID;
            }

            return ObjectGuid::Empty;
        }

    private:
        uint32 OptionalBossCount;
        ObjectGuid KilrekGUID;
        ObjectGuid TerestianGUID;
        ObjectGuid MoroesGUID;
        ObjectGuid NightbaneGUID;
        ObjectGuid LibraryDoor;                 // Door at Shade of Aran
        ObjectGuid MassiveDoor;                 // Door at Netherspite
        ObjectGuid GamesmansDoor;               // Door before Chess
        ObjectGuid GamesmansExitDoor;           // Door after Chess
        ObjectGuid NetherspaceDoor;             // Door at Malchezaar
        ObjectGuid MastersTerraceDoor[2];
        ObjectGuid ImageGUID;
        ObjectGuid DustCoveredChest;
        ObjectGuid BlackenedUrnGUID;

    protected:
        uint32 OperaEvent;
        uint32 OzDeathCount;
    };
};

void AddSC_instance_karazhan()
{
    new instance_karazhan();
}
