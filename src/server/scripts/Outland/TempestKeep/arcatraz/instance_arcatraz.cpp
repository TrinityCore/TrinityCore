/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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
#include "arcatraz.h"

DoorData const doorData[] =
{
    { GO_CONTAINMENT_CORE_SECURITY_FIELD_ALPHA, DATA_SOCCOTHRATES,  DOOR_TYPE_PASSAGE,  BOUNDARY_NONE },
    { GO_CONTAINMENT_CORE_SECURITY_FIELD_BETA,  DATA_DALLIAH,       DOOR_TYPE_PASSAGE,  BOUNDARY_NONE },
    { 0,                                        0,                  DOOR_TYPE_ROOM,     BOUNDARY_NONE } // END
};

class instance_arcatraz : public InstanceMapScript
{
    public:
        instance_arcatraz() : InstanceMapScript(ArcatrazScriptName, 552) { }

        struct instance_arcatraz_InstanceMapScript : public InstanceScript
        {
            instance_arcatraz_InstanceMapScript(Map* map) : InstanceScript(map)
            {
                SetBossNumber(EncounterCount);
                LoadDoorData(doorData);

                MellicharGUID     = 0;
                WardensShieldGUID = 0;

                ConversationState = NOT_STARTED;

                memset(StasisPodGUIDs, 0, 5 * sizeof(uint64));
                memset(StasisPodStates, NOT_STARTED, 5 * sizeof(uint8));
            }

            void OnCreatureCreate(Creature* creature) OVERRIDE
            {
                if (creature->GetEntry() == NPC_MELLICHAR)
                    MellicharGUID = creature->GetGUID();
            }

            void OnGameObjectCreate(GameObject* go) OVERRIDE
            {
                switch (go->GetEntry())
                {
                    case GO_CONTAINMENT_CORE_SECURITY_FIELD_ALPHA:
                    case GO_CONTAINMENT_CORE_SECURITY_FIELD_BETA:
                        AddDoor(go, true);
                        break;
                    case GO_STASIS_POD_ALPHA:
                        StasisPodGUIDs[0] = go->GetGUID();
                        break;
                    case GO_STASIS_POD_BETA:
                        StasisPodGUIDs[1] = go->GetGUID();
                        break;
                    case GO_STASIS_POD_DELTA:
                        StasisPodGUIDs[2] = go->GetGUID();
                        break;
                    case GO_STASIS_POD_GAMMA:
                        StasisPodGUIDs[3] = go->GetGUID();
                        break;
                    case GO_STASIS_POD_OMEGA:
                        StasisPodGUIDs[4] = go->GetGUID();
                        break;
                    case GO_WARDENS_SHIELD:
                        WardensShieldGUID = go->GetGUID();
                        break;
                    default:
                        break;
                }
            }

            void OnGameObjectRemove(GameObject* go) OVERRIDE
            {
                switch (go->GetEntry())
                {
                    case GO_CONTAINMENT_CORE_SECURITY_FIELD_ALPHA:
                    case GO_CONTAINMENT_CORE_SECURITY_FIELD_BETA:
                        AddDoor(go, false);
                        break;
                    default:
                        break;
                }
            }

            void SetData(uint32 type, uint32 data) OVERRIDE
            {
                switch (type)
                {
                    case DATA_WARDEN_1:
                        if (data == IN_PROGRESS)
                            HandleGameObject(StasisPodGUIDs[0], true);
                        StasisPodStates[0] = uint8(data);
                        break;
                    case DATA_WARDEN_2:
                        if (data == IN_PROGRESS)
                            HandleGameObject(StasisPodGUIDs[1], true);
                        StasisPodStates[1] = uint8(data);
                        break;
                    case DATA_WARDEN_3:
                        if (data == IN_PROGRESS)
                            HandleGameObject(StasisPodGUIDs[2], true);
                        StasisPodStates[2] = uint8(data);
                        break;
                    case DATA_WARDEN_4:
                        if (data == IN_PROGRESS)
                            HandleGameObject(StasisPodGUIDs[3], true);
                        StasisPodStates[3] = uint8(data);
                        break;
                    case DATA_WARDEN_5:
                        if (data == IN_PROGRESS)
                            HandleGameObject(StasisPodGUIDs[4], true);
                        StasisPodStates[4] = uint8(data);
                        break;
                    case DATA_CONVERSATION:
                        ConversationState = uint8(data);
                        break;
                    default:
                        break;
                }
            }

            uint32 GetData(uint32 type) const OVERRIDE
            {
                switch (type)
                {
                    case DATA_WARDEN_1:
                    case DATA_WARDEN_2:
                    case DATA_WARDEN_3:
                    case DATA_WARDEN_4:
                    case DATA_WARDEN_5:
                        return StasisPodStates[type - DATA_WARDEN_1];
                    case DATA_CONVERSATION:
                        return ConversationState;
                    default:
                        break;
                }
                return 0;
            }

            uint64 GetData64(uint32 data) const OVERRIDE
            {
                switch (data)
                {
                    case DATA_MELLICHAR:
                        return MellicharGUID;
                    case DATA_WARDENS_SHIELD:
                        return WardensShieldGUID;
                    default:
                        break;
                }
                return 0;
            }

            bool SetBossState(uint32 type, EncounterState state) OVERRIDE
            {
                if (!InstanceScript::SetBossState(type, state))
                    return false;

                switch (type)
                {
                    case DATA_HARBINGER_SKYRISS:
                        if (state == NOT_STARTED || state == FAIL)
                        {
                            SetData(DATA_WARDEN_1, NOT_STARTED);
                            SetData(DATA_WARDEN_2, NOT_STARTED);
                            SetData(DATA_WARDEN_3, NOT_STARTED);
                            SetData(DATA_WARDEN_4, NOT_STARTED);
                            SetData(DATA_WARDEN_5, NOT_STARTED);
                        }
                        break;
                    default:
                        break;
                }
                return true;
            }

            std::string GetSaveData() OVERRIDE
            {
                OUT_SAVE_INST_DATA;

                std::ostringstream saveStream;
                saveStream << "A Z " << GetBossSaveData();

                OUT_SAVE_INST_DATA_COMPLETE;
                return saveStream.str();
            }

            void Load(char const* str) OVERRIDE
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

                if (dataHead1 == 'A' && dataHead2 == 'Z')
                {
                    for (uint32 i = 0; i < EncounterCount; ++i)
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
            uint64 StasisPodGUIDs[5];
            uint64 MellicharGUID;
            uint64 WardensShieldGUID;

            uint8 ConversationState;
            uint8 StasisPodStates[5];
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const OVERRIDE
        {
            return new instance_arcatraz_InstanceMapScript(map);
        }
};

void AddSC_instance_arcatraz()
{
    new instance_arcatraz();
}

