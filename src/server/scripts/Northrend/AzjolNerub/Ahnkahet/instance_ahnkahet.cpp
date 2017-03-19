/*
 * Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
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
    { GO_PRINCE_TALDARAM_GATE, DATA_PRINCE_TALDARAM, DOOR_TYPE_PASSAGE },
    { 0,                       0,                    DOOR_TYPE_ROOM } // END
};

class instance_ahnkahet : public InstanceMapScript
{
    public:
        instance_ahnkahet() : InstanceMapScript(AhnKahetScriptName, 619) { }

        struct instance_ahnkahet_InstanceScript : public InstanceScript
        {
            instance_ahnkahet_InstanceScript(Map* map) : InstanceScript(map)
            {
                SetHeaders(DataHeader);
                SetBossNumber(EncounterCount);
                LoadDoorData(doorData);

                SwitchTrigger               = 0;

                SpheresState[0]             = 0;
                SpheresState[1]             = 0;
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
                            HandleGameObject(ObjectGuid::Empty, true, go);
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
                        for (ObjectGuid guid : InitiandGUIDs)
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
                        for (ObjectGuid guid : InitiandGUIDs)
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

            void SetGuidData(uint32 type, ObjectGuid  data) override
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

            ObjectGuid GetGuidData(uint32 type) const override
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
                        GuidVector vInitiands;
                        vInitiands.reserve(InitiandGUIDs.size());
                        for (ObjectGuid guid : InitiandGUIDs)
                        {
                            Creature* cr = instance->GetCreature(guid);
                            if (cr && cr->IsAlive())
                                vInitiands.push_back(guid);
                        }
                        if (vInitiands.empty())
                            return ObjectGuid::Empty;

                        return Trinity::Containers::SelectRandomContainerElement(vInitiands);
                    }
                    case DATA_ADD_JEDOGA_OPFER:
                        return JedogaSacrifices;
                    case DATA_PL_JEDOGA_TARGET:
                        return JedogaTarget;
                    default:
                        break;
                }
                return ObjectGuid::Empty;
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
                            for (ObjectGuid guid : InitiandGUIDs)
                                if (Creature* cr = instance->GetCreature(guid))
                                    cr->DespawnOrUnsummon();
                        }
                        break;
                    default:
                        break;
                }
                return true;
            }

            void WriteSaveDataMore(std::ostringstream& data) override
            {
                data << SpheresState[0] << ' ' << SpheresState[1];
            }

            void ReadSaveDataMore(std::istringstream& data) override
            {
                data >> SpheresState[0];
                data >> SpheresState[1];
            }

        protected:
            ObjectGuid ElderNadoxGUID;
            ObjectGuid PrinceTaldaramGUID;
            ObjectGuid JedogaShadowseekerGUID;
            ObjectGuid AmanitarGUID;
            ObjectGuid HeraldVolazjGUID;

            ObjectGuid PrinceTaldaramPlatformGUID;
            ObjectGuid JedogaSacrifices;
            ObjectGuid JedogaTarget;

            GuidSet InitiandGUIDs;

            uint32 SpheresState[2];
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
