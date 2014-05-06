/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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
#include "InstanceScript.h"
#include "utgarde_keep.h"

DoorData const doorData[] =
{
    { GO_GIANT_PORTCULLIS_1,    DATA_INGVAR,    DOOR_TYPE_PASSAGE,  BOUNDARY_NONE },
    { GO_GIANT_PORTCULLIS_2,    DATA_INGVAR,    DOOR_TYPE_PASSAGE,  BOUNDARY_NONE },
    { 0,                        0,              DOOR_TYPE_ROOM,     BOUNDARY_NONE } // END
};

MinionData const minionData[] =
{
    { NPC_SKARVALD,     DATA_SKARVALD_DALRONN },
    { NPC_DALRONN,      DATA_SKARVALD_DALRONN }
};

class instance_utgarde_keep : public InstanceMapScript
{
    public:
        instance_utgarde_keep() : InstanceMapScript(UKScriptName, 574) { }

        struct instance_utgarde_keep_InstanceMapScript : public InstanceScript
        {
            instance_utgarde_keep_InstanceMapScript(Map* map) : InstanceScript(map)
            {
                SetBossNumber(EncounterCount);
                LoadDoorData(doorData);
                LoadMinionData(minionData);

                PrinceKelesethGUID  = 0;
                SkarvaldGUID        = 0;
                DalronnGUID         = 0;
                IngvarGUID          = 0;
            }

            void OnCreatureCreate(Creature* creature) override
            {
                switch (creature->GetEntry())
                {
                    case NPC_PRINCE_KELESETH:
                        PrinceKelesethGUID = creature->GetGUID();
                        break;
                    case NPC_SKARVALD:
                        SkarvaldGUID = creature->GetGUID();
                        AddMinion(creature, true);
                        break;
                    case NPC_DALRONN:
                        DalronnGUID = creature->GetGUID();
                        AddMinion(creature, true);
                        break;
                    case NPC_INGVAR:
                        IngvarGUID = creature->GetGUID();
                        break;
                    default:
                        break;
                }
            }

            void OnCreatureRemove(Creature* creature) override
            {
                switch (creature->GetEntry())
                {
                    case NPC_SKARVALD:
                    case NPC_DALRONN:
                        AddMinion(creature, false);
                        break;
                    default:
                        break;
                }
            }

            void OnGameObjectCreate(GameObject* go) override
            {
                switch (go->GetEntry())
                {
                    case GO_BELLOW_1:
                        Forges[0].BellowGUID = go->GetGUID();
                        HandleGameObject(0, Forges[0].Event != NOT_STARTED, go);
                        break;
                    case GO_BELLOW_2:
                        Forges[1].BellowGUID = go->GetGUID();
                        HandleGameObject(0, Forges[1].Event != NOT_STARTED, go);
                        break;
                    case GO_BELLOW_3:
                        Forges[2].BellowGUID = go->GetGUID();
                        HandleGameObject(0, Forges[2].Event != NOT_STARTED, go);
                        break;
                    case GO_FORGEFIRE_1:
                        Forges[0].FireGUID = go->GetGUID();
                        HandleGameObject(0, Forges[0].Event != NOT_STARTED, go);
                        break;
                    case GO_FORGEFIRE_2:
                        Forges[1].FireGUID = go->GetGUID();
                        HandleGameObject(0, Forges[1].Event != NOT_STARTED, go);
                        break;
                    case GO_FORGEFIRE_3:
                        Forges[2].FireGUID = go->GetGUID();
                        HandleGameObject(0, Forges[2].Event != NOT_STARTED, go);
                        break;
                    case GO_GLOWING_ANVIL_1:
                        Forges[0].AnvilGUID = go->GetGUID();
                        HandleGameObject(0, Forges[0].Event != NOT_STARTED, go);
                        break;
                    case GO_GLOWING_ANVIL_2:
                        Forges[1].AnvilGUID = go->GetGUID();
                        HandleGameObject(0, Forges[1].Event != NOT_STARTED, go);
                        break;
                    case GO_GLOWING_ANVIL_3:
                        Forges[2].AnvilGUID = go->GetGUID();
                        HandleGameObject(0, Forges[2].Event != NOT_STARTED, go);
                        break;
                    case GO_GIANT_PORTCULLIS_1:
                    case GO_GIANT_PORTCULLIS_2:
                        AddDoor(go, true);
                        break;
                    default:
                        break;
                }
            }

            void OnGameObjectRemove(GameObject* go) override
            {
                switch (go->GetEntry())
                {
                    case GO_GIANT_PORTCULLIS_1:
                    case GO_GIANT_PORTCULLIS_2:
                        AddDoor(go, false);
                        break;
                    default:
                        break;
                }
            }

            uint64 GetData64(uint32 type) const override
            {
                switch (type)
                {
                    case DATA_PRINCE_KELESETH:
                        return PrinceKelesethGUID;
                    case DATA_SKARVALD:
                        return SkarvaldGUID;
                    case DATA_DALRONN:
                        return DalronnGUID;
                    case DATA_INGVAR:
                        return IngvarGUID;
                    default:
                        break;
                }

                return 0;
            }

            void SetData(uint32 type, uint32 data) override
            {
                switch (type)
                {
                    case DATA_FORGE_1:
                    case DATA_FORGE_2:
                    case DATA_FORGE_3:
                    {
                        uint8 i = type - DATA_FORGE_1;
                        HandleGameObject(Forges[i].AnvilGUID, data != NOT_STARTED);
                        HandleGameObject(Forges[i].BellowGUID, data != NOT_STARTED);
                        HandleGameObject(Forges[i].FireGUID, data != NOT_STARTED);
                        Forges[i].Event = data;

                        if (data == DONE)
                            SaveToDB();
                        break;
                    }
                    default:
                        break;
                }
            }

            std::string GetSaveData() override
            {
                OUT_SAVE_INST_DATA;

                std::ostringstream saveStream;
                saveStream << "U K " << GetBossSaveData();

                for (uint8 i = 0; i < 3; ++i)
                    saveStream << Forges[i].Event << ' ';

                OUT_SAVE_INST_DATA_COMPLETE;
                return saveStream.str();
            }

            void Load(char const* str) override
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

                if (dataHead1 == 'U' && dataHead2 == 'K')
                {
                    for (uint32 i = 0; i < EncounterCount; ++i)
                    {
                        uint32 tmpState;
                        loadStream >> tmpState;
                        if (tmpState == IN_PROGRESS || tmpState > SPECIAL)
                            tmpState = NOT_STARTED;
                        SetBossState(i, EncounterState(tmpState));
                    }

                    for (uint8 i = 0; i < 3; ++i)
                         loadStream >> Forges[i].Event;
                }
                else
                    OUT_LOAD_INST_DATA_FAIL;

                OUT_LOAD_INST_DATA_COMPLETE;
            }

        protected:
            ForgeInfo Forges[3];

            uint64 PrinceKelesethGUID;
            uint64 SkarvaldGUID;
            uint64 DalronnGUID;
            uint64 IngvarGUID;
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
           return new instance_utgarde_keep_InstanceMapScript(map);
        }
};

void AddSC_instance_utgarde_keep()
{
    new instance_utgarde_keep();
}
