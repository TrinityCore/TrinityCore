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
#include "ScriptedCreature.h"
#include "InstanceScript.h"
#include "ahnkahet.h"

DoorData const doorData[] =
{
    { GO_PRINCE_TALDARAM_GATE, DATA_PRINCE_TALDARAM, DOOR_TYPE_PASSAGE, BOUNDARY_NONE },
    { 0,                       0,                    DOOR_TYPE_ROOM,    BOUNDARY_NONE } // END
};

class instance_ahnkahet : public InstanceMapScript
{
    public:
        instance_ahnkahet() : InstanceMapScript(AhnKahetScriptName, 619) { }

        struct instance_ahnkahet_InstanceScript : public InstanceScript
        {
            instance_ahnkahet_InstanceScript(Map* map) : InstanceScript(map)
            {
                SetBossNumber(EncounterCount);
                LoadDoorData(doorData);

                ElderNadoxGUID              = 0;
                PrinceTaldaramGUID          = 0;
                JedogaShadowseekerGUID      = 0;
                AmanitarGUID                = 0;
                HeraldVolazjGUID            = 0;

                PrinceTaldaramPlatformGUID  = 0;
                JedogaSacrifices            = 0;
                JedogaTarget                = 0;
                SwitchTrigger               = 0;

                SpheresState[0]             = 0;
                SpheresState[1]             = 0;

                InitiandGUIDs.clear();
            }

            void OnCreatureCreate(Creature* creature) override
            {
                switch (creature->GetEntry())
                {
                    case NPC_ELDER_NADOX:
                        ElderNadoxGUID = creature->GetGUID();
                        break;
                    case NPC_PRINCE_TALDARAM:
                        PrinceTaldaramGUID = creature->GetGUID();
                        break;
                    case NPC_JEDOGA_SHADOWSEEKER:
                        JedogaShadowseekerGUID = creature->GetGUID();
                        break;
                    case NPC_AMANITAR:
                        AmanitarGUID = creature->GetGUID();
                        break;
                    case NPC_HERALD_VOLAZJ:
                        HeraldVolazjGUID = creature->GetGUID();
                        break;
                    case NPC_INITIAND:
                        InitiandGUIDs.insert(creature->GetGUID());
                        break;
                    default:
                        break;
                }
            }

            void OnGameObjectCreate(GameObject* go) override
            {
                switch (go->GetEntry())
                {
                    case GO_PRINCE_TALDARAM_PLATFORM:
                        PrinceTaldaramPlatformGUID = go->GetGUID();
                        if (GetBossState(DATA_PRINCE_TALDARAM) == DONE)
                            HandleGameObject(0, true, go);
                        break;
                    case GO_SPHERE_1:
                        if (SpheresState[0])
                        {
                            go->SetGoState(GO_STATE_ACTIVE);
                            go->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
                        }
                        else
                            go->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
                        break;
                    case GO_SPHERE_2:
                        if (SpheresState[1])
                        {
                            go->SetGoState(GO_STATE_ACTIVE);
                            go->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
                        }
                        else
                            go->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
                        break;
                    case GO_PRINCE_TALDARAM_GATE:
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
                    case GO_PRINCE_TALDARAM_GATE:
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
                    case DATA_SPHERE_1:
                    case DATA_SPHERE_2:
                        SpheresState[type - DATA_SPHERE_1] = data;
                        break;
                    case DATA_JEDOGA_TRIGGER_SWITCH:
                        SwitchTrigger = data;
                        break;
                    case DATA_JEDOGA_RESET_INITIANDS:
                        for (uint64 guid : InitiandGUIDs)
                        {
                            if (Creature* creature = instance->GetCreature(guid))
                            {
                                creature->Respawn();
                                if (!creature->IsInEvadeMode())
                                    creature->AI()->EnterEvadeMode();
                            }
                        }
                        break;
                    default:
                        break;
                }
            }

            uint32 GetData(uint32 type) const override
            {
                switch (type)
                {
                    case DATA_SPHERE_1:
                    case DATA_SPHERE_2:
                        return SpheresState[type - DATA_SPHERE_1];
                    case DATA_ALL_INITIAND_DEAD:
                        for (uint64 guid : InitiandGUIDs)
                        {
                            Creature* cr = instance->GetCreature(guid);
                            if (!cr || cr->IsAlive())
                                return 0;
                        }
                        return 1;
                    case DATA_JEDOGA_TRIGGER_SWITCH:
                        return SwitchTrigger;
                    default:
                        break;
                }
                return 0;
            }

            void SetData64(uint32 type, uint64 data) override
            {
                switch (type)
                {
                    case DATA_ADD_JEDOGA_OPFER:
                        JedogaSacrifices = data;
                        break;
                    case DATA_PL_JEDOGA_TARGET:
                        JedogaTarget = data;
                        break;
                    default:
                        break;
                }
            }

            uint64 GetData64(uint32 type) const override
            {
                switch (type)
                {
                    case DATA_ELDER_NADOX:
                        return ElderNadoxGUID;
                    case DATA_PRINCE_TALDARAM:
                        return PrinceTaldaramGUID;
                    case DATA_JEDOGA_SHADOWSEEKER:
                        return JedogaShadowseekerGUID;
                    case DATA_AMANITAR:
                        return AmanitarGUID;
                    case DATA_HERALD_VOLAZJ:
                        return HeraldVolazjGUID;
                    case DATA_PRINCE_TALDARAM_PLATFORM:
                        return PrinceTaldaramPlatformGUID;
                    case DATA_ADD_JEDOGA_INITIAND:
                    {
                        std::vector<uint64> vInitiands;
                        vInitiands.clear();
                        for (uint64 guid : InitiandGUIDs)
                        {
                            Creature* cr = instance->GetCreature(guid);
                            if (cr && cr->IsAlive())
                                vInitiands.push_back(guid);
                        }
                        if (vInitiands.empty())
                            return 0;

                        return Trinity::Containers::SelectRandomContainerElement(vInitiands);
                    }
                    case DATA_ADD_JEDOGA_OPFER:
                        return JedogaSacrifices;
                    case DATA_PL_JEDOGA_TARGET:
                        return JedogaTarget;
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
                    case DATA_JEDOGA_SHADOWSEEKER:
                        if (state == DONE)
                        {
                            for (uint64 guid : InitiandGUIDs)
                            {
                                if (Creature* cr = instance->GetCreature(guid))
                                    cr->DespawnOrUnsummon();
                            }
                        }
                        break;
                    default:
                        break;
                }
                return true;
            }

            std::string GetSaveData() override
            {
                OUT_SAVE_INST_DATA;

                std::ostringstream saveStream;
                saveStream << "A K " << GetBossSaveData() << SpheresState[0] << ' ' << SpheresState[1];

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

                if (dataHead1 == 'A' && dataHead2 == 'K')
                {
                    for (uint32 i = 0; i < EncounterCount; ++i)
                    {
                        uint32 tmpState;
                        loadStream >> tmpState;
                        if (tmpState == IN_PROGRESS || tmpState > SPECIAL)
                            tmpState = NOT_STARTED;
                        SetBossState(i, EncounterState(tmpState));
                    }

                    loadStream >> SpheresState[0];
                    loadStream >> SpheresState[1];
                }
                else
                    OUT_LOAD_INST_DATA_FAIL;

                OUT_LOAD_INST_DATA_COMPLETE;
            }

        protected:
            uint64 ElderNadoxGUID;
            uint64 PrinceTaldaramGUID;
            uint64 JedogaShadowseekerGUID;
            uint64 AmanitarGUID;
            uint64 HeraldVolazjGUID;

            uint64 PrinceTaldaramPlatformGUID;
            uint64 JedogaSacrifices;
            uint64 JedogaTarget;

            std::set<uint64> InitiandGUIDs;

            uint8 SpheresState[2];
            uint8 SwitchTrigger;
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
           return new instance_ahnkahet_InstanceScript(map);
        }
};

void AddSC_instance_ahnkahet()
{
    new instance_ahnkahet();
}
