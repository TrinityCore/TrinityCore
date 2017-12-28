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

#include "Creature.h"
#include "darkheart_thicket.h"
#include "GameObject.h"
#include "InstanceScript.h"
#include "Map.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"

DoorData const doorData[] =
{
    { GO_DOOR_ROOM_GLAIDALIS_1,        DATA_ARCHDRUID_GLAIDALIS,   DOOR_TYPE_ROOM },
    { GO_DOOR_ROOM_GLAIDALIS_2,        DATA_ARCHDRUID_GLAIDALIS,   DOOR_TYPE_ROOM },
    { GO_DOOR_ROOM_GLAIDALIS_3,        DATA_ARCHDRUID_GLAIDALIS,   DOOR_TYPE_ROOM },
    { GO_DOOR_ROOM_GLAIDALIS_4,        DATA_ARCHDRUID_GLAIDALIS,   DOOR_TYPE_ROOM },
    { GO_DOOR_ROOM_GLAIDALIS_5,        DATA_ARCHDRUID_GLAIDALIS,   DOOR_TYPE_ROOM },
    { GO_DOOR_ROOM_GLAIDALIS_6,        DATA_ARCHDRUID_GLAIDALIS,   DOOR_TYPE_ROOM },
    { GO_DOOR_ROOM_GLAIDALIS_7,        DATA_ARCHDRUID_GLAIDALIS,   DOOR_TYPE_ROOM },
    { GO_DOOR_ROOM_GLAIDALIS_8,        DATA_ARCHDRUID_GLAIDALIS,   DOOR_TYPE_ROOM },
    { GO_DOOR_ROOM_GLAIDALIS_9,        DATA_ARCHDRUID_GLAIDALIS,   DOOR_TYPE_ROOM },
    { GO_DOOR_ROOM_GLAIDALIS_10,       DATA_ARCHDRUID_GLAIDALIS,   DOOR_TYPE_ROOM },
    { GO_DOOR_ROOM_GLAIDALIS_11,       DATA_ARCHDRUID_GLAIDALIS,   DOOR_TYPE_ROOM },
    { GO_DOOR_ROOM_GLAIDALIS_12,       DATA_ARCHDRUID_GLAIDALIS,   DOOR_TYPE_ROOM },
    { GO_DOOR_ROOM_GLAIDALIS_13,       DATA_ARCHDRUID_GLAIDALIS,   DOOR_TYPE_ROOM },
    { GO_DOOR_ROOM_GLAIDALIS_14,       DATA_ARCHDRUID_GLAIDALIS,   DOOR_TYPE_ROOM },
    { GO_DOOR_ROOM_GLAIDALIS_15,       DATA_ARCHDRUID_GLAIDALIS,   DOOR_TYPE_ROOM },
    { GO_DOOR_ROOM_GLAIDALIS_16,       DATA_ARCHDRUID_GLAIDALIS,   DOOR_TYPE_ROOM },
    { GO_DOOR_ROOM_DRESARON_1,         DATA_DRESARON,              DOOR_TYPE_ROOM },
    { GO_DOOR_ROOM_DRESARON_2,         DATA_DRESARON,              DOOR_TYPE_ROOM },
    { GO_DOOR_ROOM_XAVIUS,             DATA_SHADE_OF_XAVIUS,       DOOR_TYPE_ROOM }
};

class instance_darkheart_thicket : public InstanceMapScript
{
    public:
        instance_darkheart_thicket() : InstanceMapScript("instance_darkheart_thicket", 1466) { }

        struct instance_darkheart_thicket_InstanceMapScript : public InstanceScript
        {
            instance_darkheart_thicket_InstanceMapScript(Map* map) : InstanceScript(map) { }

            void Initialize() override
            {
                SetBossNumber(DATA_MAX_ENCOUNTERS);
                LoadDoorData(doorData);
            }

            void OnCreatureCreate(Creature* creature) override
            {
                switch (creature->GetEntry())
                {
                    case NPC_ARCHDRUID_GLAIDALIS:
                        archdruidGUID = creature->GetGUID();
                        break;
                    case NPC_OAKHEART:
                        oakheartGUID = creature->GetGUID();
                        break;
                    case NPC_DRESARON:
                        dresaronGUID = creature->GetGUID();
                        break;
                    case NPC_SHADE_OF_XAVIUS:
                        xaviusGUID = creature->GetGUID();
                        break;
                    case NPC_MALFURION_STORMRAGE:
                        malfurionGUID = creature->GetGUID();
                        break;
                    case NPC_TRIGGER_SHIELD:
                        triggerShieldGUID = creature->GetGUID();
                        break;
                    default:
                        break;
                }
            }

            void OnGameObjectCreate(GameObject* go) override
            {
                switch (go->GetEntry())
                {
                    case GO_DOOR_ROOM_GLAIDALIS_1:
                    case GO_DOOR_ROOM_GLAIDALIS_2:
                    case GO_DOOR_ROOM_GLAIDALIS_3:
                    case GO_DOOR_ROOM_GLAIDALIS_4:
                    case GO_DOOR_ROOM_GLAIDALIS_5:
                    case GO_DOOR_ROOM_GLAIDALIS_6:
                    case GO_DOOR_ROOM_GLAIDALIS_7:
                    case GO_DOOR_ROOM_GLAIDALIS_8:
                    case GO_DOOR_ROOM_GLAIDALIS_9:
                    case GO_DOOR_ROOM_GLAIDALIS_10:
                    case GO_DOOR_ROOM_GLAIDALIS_11:
                    case GO_DOOR_ROOM_GLAIDALIS_12:
                    case GO_DOOR_ROOM_GLAIDALIS_13:
                    case GO_DOOR_ROOM_GLAIDALIS_14:
                    case GO_DOOR_ROOM_GLAIDALIS_15:
                    case GO_DOOR_ROOM_GLAIDALIS_16:
                    case GO_DOOR_ROOM_DRESARON_1:
                    case GO_DOOR_ROOM_DRESARON_2:
                    case GO_DOOR_ROOM_XAVIUS:
                        AddDoor(go, true);
                        break;
                    case GO_GLAIDALIS_EVENT:
                        goGlaidalisEventGUID = go->GetGUID();
                        break;
                    default:
                        break;
                }
            }

            void OnGameObjectRemove(GameObject* go) override
            {
                switch (go->GetEntry())
                {
                    case GO_DOOR_ROOM_GLAIDALIS_1:
                    case GO_DOOR_ROOM_GLAIDALIS_2:
                    case GO_DOOR_ROOM_GLAIDALIS_3:
                    case GO_DOOR_ROOM_GLAIDALIS_4:
                    case GO_DOOR_ROOM_GLAIDALIS_5:
                    case GO_DOOR_ROOM_GLAIDALIS_6:
                    case GO_DOOR_ROOM_GLAIDALIS_7:
                    case GO_DOOR_ROOM_GLAIDALIS_8:
                    case GO_DOOR_ROOM_GLAIDALIS_9:
                    case GO_DOOR_ROOM_GLAIDALIS_10:
                    case GO_DOOR_ROOM_GLAIDALIS_11:
                    case GO_DOOR_ROOM_GLAIDALIS_12:
                    case GO_DOOR_ROOM_GLAIDALIS_13:
                    case GO_DOOR_ROOM_GLAIDALIS_14:
                    case GO_DOOR_ROOM_GLAIDALIS_15:
                    case GO_DOOR_ROOM_GLAIDALIS_16:
                    case GO_DOOR_ROOM_DRESARON_1:
                    case GO_DOOR_ROOM_DRESARON_2:
                    case GO_DOOR_ROOM_XAVIUS:
                        AddDoor(go, false);
                        break;
                    default:
                        break;
                }
            }

            bool SetBossState(uint32 type, EncounterState state) override
            {
                if (!InstanceScript::SetBossState(type, state))
                    return false;

                switch (type)
                {
                    case DATA_ARCHDRUID_GLAIDALIS:
                    case DATA_OAKHEART:
                    case DATA_DRESARON:
                        break;
                    case DATA_SHADE_OF_XAVIUS:
                        if (state == DONE)
                        {
                            if (Creature* malfurion = instance->GetCreature(malfurionGUID))
                                malfurion->AI()->DoAction(ACTION_MALFURION_OUTRO);
                        }
                        break;
                    default:
                        break;
                }

                return true;
            }

            ObjectGuid GetGuidData(uint32 type) const override
            {
                switch (type)
                {
                    case DATA_ARCHDRUID_GLAIDALIS:
                        return archdruidGUID;
                    case DATA_OAKHEART:
                        return oakheartGUID;
                    case DATA_DRESARON:
                        return dresaronGUID;
                    case DATA_SHADE_OF_XAVIUS:
                        return xaviusGUID;
                    case DATA_SHIELD_TRIGGER:
                        return triggerShieldGUID;
                    case GO_EVENT_GLAIDALIS:
                        return goGlaidalisEventGUID;
                    default:
                        break;
                }

                return ObjectGuid::Empty;
            }

        private:
            ObjectGuid archdruidGUID;
            ObjectGuid oakheartGUID;
            ObjectGuid dresaronGUID;
            ObjectGuid xaviusGUID;
            ObjectGuid malfurionGUID;
            ObjectGuid triggerShieldGUID;
            ObjectGuid goGlaidalisEventGUID;
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
            return new instance_darkheart_thicket_InstanceMapScript(map);
        }
};

void AddSC_instance_darkheart_thicket()
{
    new instance_darkheart_thicket();
}
