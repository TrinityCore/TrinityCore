/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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

/* ScriptData
SDName: Instance_Shattered_Halls
SD%Complete: 50
SDComment: instance not complete
SDCategory: Hellfire Citadel, Shattered Halls
EndScriptData */

#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "shattered_halls.h"

class instance_shattered_halls : public InstanceMapScript
{
    public:
        instance_shattered_halls() : InstanceMapScript("instance_shattered_halls", 540) { }

        InstanceScript* GetInstanceScript(InstanceMap* map) const OVERRIDE
        {
            return new instance_shattered_halls_InstanceMapScript(map);
        }

        struct instance_shattered_halls_InstanceMapScript : public InstanceScript
        {
            instance_shattered_halls_InstanceMapScript(Map* map) : InstanceScript(map) { }

            void Initialize()
            {
                SetBossNumber(EncounterCount);
                nethekurseGUID      = 0;
                nethekurseDoor1GUID = 0;
                nethekurseDoor2GUID = 0;
            }

            void OnGameObjectCreate(GameObject* go)
            {
                switch (go->GetEntry())
                {
                    case GO_GRAND_WARLOCK_CHAMBER_DOOR_1:
                        nethekurseDoor1GUID = go->GetGUID();
                        break;
                    case GO_GRAND_WARLOCK_CHAMBER_DOOR_2:
                        nethekurseDoor2GUID = go->GetGUID();
                        break;
                }
            }

            void OnCreatureCreate(Creature* creature)
            {
                switch (creature->GetEntry())
                {
                    case NPC_GRAND_WARLOCK_NETHEKURSE:
                        nethekurseGUID = creature->GetGUID();
                        break;
                }
            }

            bool SetBossState(uint32 type, EncounterState state)
            {
                if (!InstanceScript::SetBossState(type, state))
                    return false;

                switch (type)
                {
                    case DATA_NETHEKURSE:
                        if (state == IN_PROGRESS)
                        {
                            HandleGameObject(nethekurseDoor1GUID, false);
                            HandleGameObject(nethekurseDoor2GUID, false);
                        }
                        else
                        {
                            HandleGameObject(nethekurseDoor1GUID, true);
                            HandleGameObject(nethekurseDoor2GUID, true);
                        }
                        break;
                    case DATA_OMROGG:
                        break;
                }
                return true;
            }

            uint64 GetData64(uint32 data) const OVERRIDE
            {
                switch (data)
                {
                    case NPC_GRAND_WARLOCK_NETHEKURSE:
                        return nethekurseGUID;
                        break;
                    case GO_GRAND_WARLOCK_CHAMBER_DOOR_1:
                        return nethekurseDoor1GUID;
                        break;
                    case GO_GRAND_WARLOCK_CHAMBER_DOOR_2:
                        return nethekurseDoor2GUID;
                        break;
                }
                return 0;
            }

            std::string GetSaveData()
            {
                OUT_SAVE_INST_DATA;

                std::ostringstream saveStream;
                saveStream << "S H " << GetBossSaveData();

                OUT_SAVE_INST_DATA_COMPLETE;
                return saveStream.str();
            }

            void Load(const char* strIn)
            {
                if (!strIn)
                {
                    OUT_LOAD_INST_DATA_FAIL;
                    return;
                }

                OUT_LOAD_INST_DATA(strIn);

                char dataHead1, dataHead2;

                std::istringstream loadStream(strIn);
                loadStream >> dataHead1 >> dataHead2;

                if (dataHead1 == 'S' && dataHead2 == 'H')
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
                uint32 encounter[EncounterCount];
                uint64 nethekurseGUID;
                uint64 nethekurseDoor1GUID;
                uint64 nethekurseDoor2GUID;
        };
};

void AddSC_instance_shattered_halls()
{
    new instance_shattered_halls();
}

