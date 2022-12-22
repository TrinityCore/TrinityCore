/*
* Copyright 2023 AzgathCore
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
#include "InstanceScript.h"
#include "siege_of_the_niuzao_temple.h"

#define MAX_ENCOUNTER 4
enum SiegeOfNiuzaoTempleCreatures
{
    NPC_VIZIER_JINBAK = 61567,
    NPC_COMMANDER_VOJAK = 61634,
    NPC_GENERAL_PAVALAK = 61485,
    NPC_WING_LEADER_NERONOK = 62205,
};

enum SiegeOfNiuzaoTempleData
{
    DATA_VIZIER_JINBAK = 0,
    DATA_COMMANDER_VOJAK,
    DATA_GENERAL_PAVALAK,
    DATA_WING_LEADER_NERONOK,
};

class instance_siege_of_niuzao_temple : public InstanceMapScript
{
public:
    instance_siege_of_niuzao_temple() : InstanceMapScript("instance_siege_of_niuzao_temple", 1011) { }

    struct instance_siege_of_niuzao_temple_InstanceMapScript : public InstanceScript
    {
        instance_siege_of_niuzao_temple_InstanceMapScript(InstanceMap* map) : InstanceScript(map) { }

        uint32 encounters[MAX_ENCOUNTER];

        std::string str_data;

        std::list<ObjectGuid> pavalakReinforcementSummonerGuids;

        ObjectGuid bossGuids[MAX_ENCOUNTER];

        void Initialize()
        {
            memset(&encounters, 0, sizeof(encounters));

            pavalakReinforcementSummonerGuids.clear();
        }

        bool IsEncounterInProgress() const
        {
            for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
                if (encounters[i] == IN_PROGRESS)
                    return true;

            return false;
        }

        void OnCreatureCreate(Creature* creature)
        {
            switch (creature->GetEntry())
            {
            case 61483: pavalakReinforcementSummonerGuids.push_back(creature->GetGUID());
            case NPC_VIZIER_JINBAK:
                bossGuids[DATA_VIZIER_JINBAK] = creature->GetGUID();
                break;
            case NPC_COMMANDER_VOJAK:
                bossGuids[DATA_COMMANDER_VOJAK] = creature->GetGUID();
                break;
            case NPC_GENERAL_PAVALAK:
                bossGuids[DATA_GENERAL_PAVALAK] = creature->GetGUID();
                break;
            case NPC_WING_LEADER_NERONOK:
                bossGuids[DATA_WING_LEADER_NERONOK] = creature->GetGUID();
                break;
            }
        }

        void OnGameObjectCreate(GameObject* /*go*/)
        {
        }

        uint32 GetData(uint32 type) const
        {
            switch (type)
            {
            case DATA_VIZIER_JINBAK:
            case DATA_COMMANDER_VOJAK:
            case DATA_GENERAL_PAVALAK:
            case DATA_WING_LEADER_NERONOK:
                return encounters[type];
            }

            return 0;
        }

        ObjectGuid GetObjectGuid(uint32 type) const
        {
            if (type < MAX_ENCOUNTER)
                return bossGuids[type];
        }

        std::string GetSaveData()
        {

            std::ostringstream saveStream;
            saveStream << "V H "
                << (uint16)encounters[0]
                << ' ' << (uint16)encounters[1]
                << ' ' << (uint16)encounters[2]
                << ' ' << (uint16)encounters[3];

            str_data = saveStream.str();

            return str_data;
        }

        void Load(const char* in)
        {

            char dataHead1, dataHead2;
            uint16 data0, data1, data2;

            std::istringstream loadStream(in);
            loadStream >> dataHead1 >> dataHead2 >> data0 >> data1 >> data2;

            if (dataHead1 == 'V' && dataHead2 == 'H')
            {
                encounters[0] = data0;
                encounters[1] = data1;
                encounters[2] = data2;
                encounters[3] = data2;

                for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
                    if (encounters[i] == IN_PROGRESS)
                        encounters[i] = NOT_STARTED;
            }
        }
    };

    InstanceScript* GetInstanceScript(InstanceMap* map) const
    {
        return new instance_siege_of_niuzao_temple_InstanceMapScript(map);
    }
};

void AddSC_instance_siege_of_the_niuzao_temple()
{
    new instance_siege_of_niuzao_temple();
}
