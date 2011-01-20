/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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
#include "oculus.h"

#define MAX_ENCOUNTER 4

/* The Occulus encounters:
0 - Drakos the Interrogator
1 - Varos Cloudstrider
2 - Mage-Lord Urom
3 - Ley-Guardian Eregos */

class instance_oculus : public InstanceMapScript
{
public:
    instance_oculus() : InstanceMapScript("instance_oculus", 578) { }

    InstanceScript* GetInstanceScript(InstanceMap* pMap) const
    {
        return new instance_oculus_InstanceMapScript(pMap);
    }

    struct instance_oculus_InstanceMapScript : public InstanceScript
    {
        instance_oculus_InstanceMapScript(Map* pMap) : InstanceScript(pMap) {Initialize();};

        void Initialize()
        {
            drakosGUID = 0;
            varosGUID = 0;
            uromGUID = 0;
            eregosGUIDs = 0;

            platformUrom = 0;

            azureDragonsList.clear();
            gameObjectList.clear();
        }

        void ProcessEvent(Unit* /*unit*/, uint32 eventId)
        {
            if (eventId != EVENT_CALL_DRAGON)
                return;

            if (azureDragonsList.empty())
                return;

            Creature* nearestDragon = NULL;
            Creature* varos = instance->GetCreature(varosGUID);

            for (std::list<uint64>::const_iterator itr = azureDragonsList.begin(); itr != azureDragonsList.end(); ++itr)
            {
                if (Creature* dragon = instance->GetCreature(*itr))
                {
                    if (!dragon->isAlive() && dragon->isInCombat())
                        continue;

                    if (!nearestDragon)
                        nearestDragon = dragon;
                    else if (varos)
                    {
                        if (nearestDragon->GetExactDist(varos) > dragon->GetExactDist(varos))
                            nearestDragon = dragon;
                    }
                }
            }

            if (nearestDragon)
                nearestDragon->AI()->DoAction(ACTION_CALL_DRAGON_EVENT);
           
        }

        void OnCreatureCreate(Creature* creature)
        {
            switch(creature->GetEntry())
            {
                case NPC_DRAKOS:
                    drakosGUID = creature->GetGUID();
                    break;
                case NPC_VAROS:
                    varosGUID = creature->GetGUID();
                    break;
                case NPC_UROM:
                    uromGUID = creature->GetGUID();
                    break;
                case NPC_EREGOS:
                    eregosGUIDs = creature->GetGUID();
                    break;
                case NPC_AZURE_RING_GUARDIAN:
                    azureDragonsList.push_back(creature->GetGUID());
                    break;
            }
        }

        void OnGameObjectCreate(GameObject* go)
        {
            if (go->GetEntry() == GO_DRAGON_CAGE_DOOR)
            {
                if (GetData(DATA_DRAKOS_EVENT) == DONE)
                    go->SetGoState(GO_STATE_ACTIVE);
                else
                    go->SetGoState(GO_STATE_READY);

                gameObjectList.push_back(go->GetGUID());
            }
        }

        void SetData(uint32 type, uint32 data)
        {
            switch(type)
            {
                case DATA_DRAKOS_EVENT:
                    encounter[0] = data;
                    if (data == DONE)
                        OpenCageDoors();
                    break;
                case DATA_VAROS_EVENT:
                    encounter[1] = data;
                    break;
                case DATA_UROM_EVENT:
                    encounter[2] = data;
                    break;
                case DATA_EREGOS_EVENT:
                    encounter[3] = data;
                    break;
                case DATA_UROM_PLATAFORM:
                    platformUrom = data;
                    break;
            }

            if (data == DONE)
                SaveToDB();
        }

        uint32 GetData(uint32 type)
        {
            switch(type)
            {
                case DATA_DRAKOS_EVENT:                return encounter[0];
                case DATA_VAROS_EVENT:                 return encounter[1];
                case DATA_UROM_EVENT:                  return encounter[2];
                case DATA_EREGOS_EVENT:                return encounter[3];
                case DATA_UROM_PLATAFORM:              return platformUrom;
            }

            return 0;
        }

        uint64 GetData64(uint32 identifier)
        {
            switch(identifier)
            {
                case DATA_DRAKOS:                 return drakosGUID;
                case DATA_VAROS:                  return varosGUID;
                case DATA_UROM:                   return uromGUID;
                case DATA_EREGOS:                 return eregosGUIDs;
            }

            return 0;
        }

        void OpenCageDoors()
        {
            if (gameObjectList.empty())
                return;

            for (std::list<uint64>::const_iterator itr = gameObjectList.begin(); itr != gameObjectList.end(); ++itr)
            {
                if (GameObject* go = instance->GetGameObject(*itr))
                    go->SetGoState(GO_STATE_ACTIVE);
            }
        }

        std::string GetSaveData()
        {
            OUT_SAVE_INST_DATA;

            std::ostringstream saveStream;
            saveStream << "T O " << encounter[0] << " " << encounter[1] << " " << encounter[2] << " " << encounter[3];

            str_data = saveStream.str();

            OUT_SAVE_INST_DATA_COMPLETE;
            return str_data;
        }

        void Load(const char* in)
        {
            if (!in)
            {
                OUT_LOAD_INST_DATA_FAIL;
                return;
            }

            OUT_LOAD_INST_DATA(in);

            char dataHead1, dataHead2;
            uint16 data0, data1, data2, data3;

            std::istringstream loadStream(in);
            loadStream >> dataHead1 >> dataHead2 >> data0 >> data1 >> data2 >> data3;

            if (dataHead1 == 'T' && dataHead2 == 'O')
            {
                encounter[0] = data0;
                encounter[1] = data1;
                encounter[2] = data2;
                encounter[3] = data3;

                for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
                    if (encounter[i] == IN_PROGRESS)
                        encounter[i] = NOT_STARTED;

            } else OUT_LOAD_INST_DATA_FAIL;

            OUT_LOAD_INST_DATA_COMPLETE;
        }
        private:
            uint64 drakosGUID;
            uint64 varosGUID;
            uint64 uromGUID;
            uint64 eregosGUIDs;

            uint8 platformUrom;

            uint16 encounter[MAX_ENCOUNTER];
            std::string str_data;

            std::list<uint64> gameObjectList;
            std::list<uint64> azureDragonsList;
    };

};


void AddSC_instance_oculus()
{
    new instance_oculus();
}
