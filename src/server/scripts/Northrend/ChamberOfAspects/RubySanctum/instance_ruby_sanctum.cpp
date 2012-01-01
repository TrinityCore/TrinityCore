/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
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

#include "ScriptPCH.h"
#include "ruby_sanctum.h"


DoorData const doorData[] =
{
    {GO_FIRE_FIELD,     DATA_BALTHARUS_THE_WARBORN, DOOR_TYPE_PASSAGE,  BOUNDARY_E   },
    {0,                 0,                          DOOR_TYPE_ROOM,     BOUNDARY_NONE},
};

class instance_ruby_sanctum : public InstanceMapScript
{
    public:
        instance_ruby_sanctum() : InstanceMapScript(RSScriptName, 724) { }

        struct instance_ruby_sanctum_InstanceMapScript : public InstanceScript
        {
            instance_ruby_sanctum_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
            {
                SetBossNumber(EncounterCount);
                LoadDoorData(doorData);
                BaltharusTheWarbornGUID = 0;
                GeneralZarithrianGUID   = 0;
                SavianaRagefireGUID     = 0;
                HalionGUID              = 0;
                HalionControllerGUID    = 0;
                CrystalChannelTargetGUID = 0;
                XerestraszaGUID         = 0;
                BaltharusSharedHealth   = 0;
                FlameWallsGUID          = 0;
                FlameRingGUID           = 0;
                memset(ZarithianSpawnStalkerGUID, 0, 2*sizeof(uint64));
                memset(BurningTreeGUID, 0, 4*sizeof(uint64));
            }

            void OnCreatureCreate(Creature* creature)
            {
                switch (creature->GetEntry())
                {
                    case NPC_BALTHARUS_THE_WARBORN:
                        BaltharusTheWarbornGUID = creature->GetGUID();
                        break;
                    case NPC_GENERAL_ZARITHRIAN:
                        GeneralZarithrianGUID = creature->GetGUID();
                        break;
                    case NPC_SAVIANA_RAGEFIRE:
                        SavianaRagefireGUID = creature->GetGUID();
                        break;
                    case NPC_HALION:
                        HalionGUID = creature->GetGUID();
                        break;
                    case NPC_HALION_CONTROLLER:
                        HalionControllerGUID = creature->GetGUID();
                    case NPC_BALTHARUS_TARGET:
                        CrystalChannelTargetGUID = creature->GetGUID();
                        break;
                    case NPC_XERESTRASZA:
                        XerestraszaGUID = creature->GetGUID();
                        break;
                    case NPC_ZARITHIAN_SPAWN_STALKER:
                        if (!ZarithianSpawnStalkerGUID[0])
                            ZarithianSpawnStalkerGUID[0] = creature->GetGUID();
                        else
                            ZarithianSpawnStalkerGUID[1] = creature->GetGUID();
                        break;
                    default:
                        break;
                }
            }

            void OnGameObjectCreate(GameObject* go)
            {
                switch (go->GetEntry())
                {
                    case GO_FIRE_FIELD:
                        AddDoor(go, true);
                        break;
                    case GO_FLAME_WALLS:
                        FlameWallsGUID = go->GetGUID();
                        if (GetBossState(DATA_SAVIANA_RAGEFIRE) == DONE && GetBossState(DATA_BALTHARUS_THE_WARBORN) == DONE)
                            HandleGameObject(FlameWallsGUID, true, go);
                        break;
                    case GO_FLAME_RING:
                        FlameRingGUID = go->GetGUID();
                        break;
                    case GO_BURNING_TREE_1:
                        BurningTreeGUID[0] = go->GetGUID();
                        if (GetBossState(DATA_GENERAL_ZARITHRIAN) == DONE)
                            HandleGameObject(BurningTreeGUID[0], true);
                        break;
                    case GO_BURNING_TREE_2:
                        BurningTreeGUID[1] = go->GetGUID();
                        if (GetBossState(DATA_GENERAL_ZARITHRIAN) == DONE)
                            HandleGameObject(BurningTreeGUID[1], true);
                        break;
                    case GO_BURNING_TREE_3:
                        BurningTreeGUID[2] = go->GetGUID();
                        if (GetBossState(DATA_GENERAL_ZARITHRIAN) == DONE)
                            HandleGameObject(BurningTreeGUID[2], true);
                        break;
                    case GO_BURNING_TREE_4:
                        BurningTreeGUID[3] = go->GetGUID();
                        if (GetBossState(DATA_GENERAL_ZARITHRIAN) == DONE)
                            HandleGameObject(BurningTreeGUID[3], true);
                        break;
                    default:
                        break;
                }
            }

            void OnGameObjectRemove(GameObject* go)
            {
                switch (go->GetEntry())
                {
                    case GO_FIRE_FIELD:
                        AddDoor(go, false);
                        break;
                    default:
                        break;
                }
            }

            uint64 GetData64(uint32 type)
            {
                switch (type)
                {
                    case DATA_BALTHARUS_THE_WARBORN:
                        return BaltharusTheWarbornGUID;
                    case DATA_CRYSTAL_CHANNEL_TARGET:
                        return CrystalChannelTargetGUID;
                    case DATA_XERESTRASZA:
                        return XerestraszaGUID;
                    case DATA_SAVIANA_RAGEFIRE:
                        return SavianaRagefireGUID;
                    case DATA_GENERAL_ZARITHRIAN:
                        return GeneralZarithrianGUID;
                    case DATA_ZARITHIAN_SPAWN_STALKER_1:
                        return ZarithianSpawnStalkerGUID[0];
                    case DATA_ZARITHIAN_SPAWN_STALKER_2:
                        return ZarithianSpawnStalkerGUID[1];
                    case DATA_HALION:
                        return HalionGUID;
                    case DATA_HALION_CONTROLLER:
                        return HalionControllerGUID;
                    case DATA_BURNING_TREE_1:
                        return BurningTreeGUID[0];
                    case DATA_BURNING_TREE_2:
                        return BurningTreeGUID[1];
                    case DATA_BURNING_TREE_3:
                        return BurningTreeGUID[2];
                    case DATA_BURNING_TREE_4:
                        return BurningTreeGUID[3];
                    case DATA_FLAME_RING:
                        return FlameRingGUID;
                    default:
                        break;
                }

                return 0;
            }

            bool SetBossState(uint32 type, EncounterState state)
            {
                if (!InstanceScript::SetBossState(type, state))
                    return false;

                switch (type)
                {
                    case DATA_BALTHARUS_THE_WARBORN:
                    {
                        if (state == DONE && GetBossState(DATA_SAVIANA_RAGEFIRE) == DONE)
                        {
                            HandleGameObject(FlameWallsGUID, true);
                            if (Creature* zarithrian = instance->GetCreature(GeneralZarithrianGUID))
                                zarithrian->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                        }
                        break;
                    }
                    case DATA_SAVIANA_RAGEFIRE:
                    {
                        if (state == DONE && GetBossState(DATA_BALTHARUS_THE_WARBORN) == DONE)
                        {
                            HandleGameObject(FlameWallsGUID, true);
                            if (Creature* zarithrian = instance->GetCreature(GeneralZarithrianGUID))
                                zarithrian->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                        }
                        break;
                    }
                    case DATA_GENERAL_ZARITHRIAN:
                        if (GetBossState(DATA_SAVIANA_RAGEFIRE) == DONE && GetBossState(DATA_BALTHARUS_THE_WARBORN) == DONE)
                            HandleGameObject(FlameWallsGUID, state != IN_PROGRESS);
                        /*
                        if (state == DONE)
                            if (Creature* halionController = instance->SummonCreature(NPC_HALION_CONTROLLER, HalionControllerSpawnPos))
                                halionController->AI()->DoAction(ACTION_INTRO_HALION);
                        */
                        break;
                    case DATA_HALION:
                        /*
                        if (state != IN_PROGRESS)
                            HandleGameObject(FlameRingGUID, true);
                        */
                        break;
                    default:
                        break;
                }

                return true;
            }

            void SetData(uint32 type, uint32 data)
            {
                switch (type)
                {
                    case DATA_BALTHARUS_SHARED_HEALTH:
                        BaltharusSharedHealth = data;
                        break;
                }
            }

            uint32 GetData(uint32 type)
            {
                switch (type)
                {
                    case DATA_BALTHARUS_SHARED_HEALTH:
                        return BaltharusSharedHealth;
                    default:
                        break;
                }

                return 0;
            }

            std::string GetSaveData()
            {
                OUT_SAVE_INST_DATA;

                std::ostringstream saveStream;
                saveStream << "R S " << GetBossSaveData();

                OUT_SAVE_INST_DATA_COMPLETE;
                return saveStream.str();
            }

            void Load(char const* str)
            {
                if (!str)
                {
                    OUT_LOAD_INST_DATA_FAIL;
                    return;
                }

                OUT_LOAD_INST_DATA(str);

                char dataHead1, dataHead2;

                std::istringstream loadStream(str);
                loadStream >> dataHead1 >> dataHead2;

                if (dataHead1 == 'R' && dataHead2 == 'S')
                {
                    for (uint8 i = 0; i < EncounterCount; ++i)
                    {
                        uint32 tmpState;
                        loadStream >> tmpState;
                        if (tmpState == IN_PROGRESS || tmpState > SPECIAL)
                            tmpState = NOT_STARTED;

                        SetBossState(i, EncounterState(tmpState));
                    }
                }
                else
                    OUT_LOAD_INST_DATA_FAIL;

                OUT_LOAD_INST_DATA_COMPLETE;
            }

        protected:
            uint64 BaltharusTheWarbornGUID;
            uint64 GeneralZarithrianGUID;
            uint64 SavianaRagefireGUID;
            uint64 HalionGUID;
            uint64 HalionControllerGUID;
            uint64 CrystalChannelTargetGUID;
            uint64 XerestraszaGUID;
            uint64 FlameWallsGUID;
            uint64 ZarithianSpawnStalkerGUID[2];
            uint64 BurningTreeGUID[4];
            uint64 FlameRingGUID;
            uint32 BaltharusSharedHealth;
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const
        {
            return new instance_ruby_sanctum_InstanceMapScript(map);
        }
};

void AddSC_instance_ruby_sanctum()
{
    new instance_ruby_sanctum();
}
