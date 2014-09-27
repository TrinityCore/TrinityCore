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
                SetHeaders(DataHeader);
                SetBossNumber(EncounterCount);
                LoadDoorData(doorData);

                DalliahGUID       = 0;
                SoccothratesGUID  = 0;
                MellicharGUID     = 0;
                WardensShieldGUID = 0;

                ConversationState = NOT_STARTED;

                memset(StasisPodGUIDs, 0, 5 * sizeof(uint64));
                memset(StasisPodStates, NOT_STARTED, 5 * sizeof(uint8));
            }

            void OnCreatureCreate(Creature* creature) override
            {
                switch (creature->GetEntry())
                {
                    case NPC_DALLIAH:
                        DalliahGUID = creature->GetGUID();
                        break;
                    case NPC_SOCCOTHRATES:
                        SoccothratesGUID = creature->GetGUID();
                        break;
                    case NPC_MELLICHAR:
                        MellicharGUID = creature->GetGUID();
                        break;
                    default:
                        break;
                }
            }

            void OnGameObjectCreate(GameObject* go) override
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

            void OnGameObjectRemove(GameObject* go) override
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

            void SetData(uint32 type, uint32 data) override
            {
                switch (type)
                {
                    case DATA_WARDEN_1:
                    case DATA_WARDEN_2:
                    case DATA_WARDEN_3:
                    case DATA_WARDEN_4:
                    case DATA_WARDEN_5:
                        if (data == IN_PROGRESS)
                            HandleGameObject(StasisPodGUIDs[type - DATA_WARDEN_1], true);
                        StasisPodStates[type - DATA_WARDEN_1] = uint8(data);
                        break;
                    case DATA_CONVERSATION:
                        ConversationState = uint8(data);
                        break;
                    default:
                        break;
                }
            }

            uint32 GetData(uint32 type) const override
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

            uint64 GetData64(uint32 data) const override
            {
                switch (data)
                {
                    case DATA_DALLIAH:
                        return DalliahGUID;
                    case DATA_SOCCOTHRATES:
                        return SoccothratesGUID;
                    case DATA_MELLICHAR:
                        return MellicharGUID;
                    case DATA_WARDENS_SHIELD:
                        return WardensShieldGUID;
                    default:
                        break;
                }
                return 0;
            }

            bool SetBossState(uint32 type, EncounterState state) override
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

        protected:
            uint64 DalliahGUID;
            uint64 SoccothratesGUID;
            uint64 StasisPodGUIDs[5];
            uint64 MellicharGUID;
            uint64 WardensShieldGUID;

            uint8 ConversationState;
            uint8 StasisPodStates[5];
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
            return new instance_arcatraz_InstanceMapScript(map);
        }
};

void AddSC_instance_arcatraz()
{
    new instance_arcatraz();
}

