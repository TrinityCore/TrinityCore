/*
* Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
*
* This program is free software; you can redistribute it and/or modify it
* under the terms of the GNU General Public License as published by the
* Free Software Foundation; either version 3 of the License, or (at your
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

#include "baradin_hold.h"
#include "InstanceScript.h"
#include "ScriptMgr.h"

DoorData const doorData[] =
{
    {GO_ARGALOTH_DOOR,  DATA_ARGALOTH, DOOR_TYPE_ROOM,  BOUNDARY_NONE},
    {GO_OCCUTHAR_DOOR,  DATA_OCCUTHAR, DOOR_TYPE_ROOM,  BOUNDARY_NONE},
};

class instance_baradin_hold: public InstanceMapScript
{
public:
    instance_baradin_hold() : InstanceMapScript("instance_baradin_hold", 757) { }

    InstanceScript* GetInstanceScript(InstanceMap* map) const
    {
        return new instance_baradin_hold_InstanceMapScript(map);
    }

    struct instance_baradin_hold_InstanceMapScript: public InstanceScript
    {
        instance_baradin_hold_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
        {
            SetBossNumber(MAX_ENCOUNTERS);
            LoadDoorData(doorData);
            _argalothGUID = 0;
            _occutharGUID = 0;
            _alizabalGUID = 0;
            _argalothDoor = 0;
            _occutharDoor = 0;
        }

        void Initialize()
        {
        }

        void OnCreatureCreate(Creature* creature)
        {
            switch(creature->GetEntry())
            {
                case BOSS_ARGALOTH:
                    _argalothGUID = creature->GetGUID();
                    break;
                case BOSS_OCCUTHAR:
                    _occutharGUID = creature->GetGUID();
                    break;
                case BOSS_ALIZABAL:
                    _alizabalGUID = creature->GetGUID();
                    break;
            }
        }

        void OnGameObjectCreate(GameObject* go)
        {
            switch(go->GetEntry())
            {
                case GO_ARGALOTH_DOOR:
                    _argalothDoor = go->GetGUID();
                    AddDoor(go, true);
                    break;
                case GO_OCCUTHAR_DOOR:
                    _occutharDoor = go->GetGUID();
                    AddDoor(go, true);
                    break;
            }
        }

        uint64 GetData64(uint32 data) const
        {
            switch (data)
            {
                case DATA_ARGALOTH:
                    return _argalothGUID;
                case DATA_OCCUTHAR:
                    return _occutharGUID;
                case DATA_ALIZABAL:
                    return _alizabalGUID;
                default:
                    break;
            }

            return 0;
        }

        void OnGameObjectRemove(GameObject* go)
        {
            switch(go->GetEntry())
            {
                case GO_ARGALOTH_DOOR:
                    AddDoor(go, false);
                    break;
                case GO_OCCUTHAR_DOOR:
                    AddDoor(go, false);
                    break;
            }
        }

        std::string GetSaveData()
        {
            OUT_SAVE_INST_DATA;

            std::ostringstream saveStream;
            saveStream << "B H " << GetBossSaveData();

            OUT_SAVE_INST_DATA_COMPLETE;
            return saveStream.str();
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

            std::istringstream loadStream(in);
            loadStream >> dataHead1 >> dataHead2;

            if (dataHead1 == 'B' && dataHead2 == 'H')
            {
                for (uint8 i = 0; i < MAX_ENCOUNTERS; ++i)
                {
                    uint32 tmpState;
                    loadStream >> tmpState;
                    if (tmpState == IN_PROGRESS || tmpState > SPECIAL)
                        tmpState = NOT_STARTED;

                    SetBossState(i, EncounterState(tmpState));
                }

            } else OUT_LOAD_INST_DATA_FAIL;

            OUT_LOAD_INST_DATA_COMPLETE;
        }

    private:
        uint64 _argalothGUID;
        uint64 _occutharGUID;
        uint64 _alizabalGUID;
        uint64 _argalothDoor;
        uint64 _occutharDoor;
    };
};

void AddSC_instance_baradin_hold()
{
    new instance_baradin_hold();
}
