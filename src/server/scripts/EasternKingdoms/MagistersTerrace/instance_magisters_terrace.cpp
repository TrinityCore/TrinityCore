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
#include "magisters_terrace.h"

/*
0  - Selin Fireheart
1  - Vexallus
2  - Priestess Delrissa
3  - Kael'thas Sunstrider
*/

DoorData const doorData[] =
{
    { GO_SELIN_DOOR,           DATA_SELIN,    DOOR_TYPE_PASSAGE, BOUNDARY_NONE },
    { GO_SELIN_ENCOUNTER_DOOR, DATA_SELIN,    DOOR_TYPE_ROOM,    BOUNDARY_NONE },
    { GO_VEXALLUS_DOOR,        DATA_VEXALLUS, DOOR_TYPE_PASSAGE, BOUNDARY_NONE },
    { GO_DELRISSA_DOOR,        DATA_DELRISSA, DOOR_TYPE_PASSAGE, BOUNDARY_NONE },
    { GO_KAEL_DOOR,            DATA_KAELTHAS, DOOR_TYPE_ROOM,    BOUNDARY_NONE },
    { 0,                       0,             DOOR_TYPE_ROOM,    BOUNDARY_NONE } // END
};

class instance_magisters_terrace : public InstanceMapScript
{
    public:
        instance_magisters_terrace() : InstanceMapScript("instance_magisters_terrace", 585) { }

        struct instance_magisters_terrace_InstanceMapScript : public InstanceScript
        {
            instance_magisters_terrace_InstanceMapScript(Map* map) : InstanceScript(map)
            {
                SetHeaders(DataHeader);
                SetBossNumber(EncounterCount);
                LoadDoorData(doorData);

                DelrissaDeathCount = 0;
            }

            uint32 GetData(uint32 type) const override
            {
                switch (type)
                {
                    case DATA_DELRISSA_DEATH_COUNT:
                        return DelrissaDeathCount;
                    default:
                        break;
                }
                return 0;
            }

            void SetData(uint32 type, uint32 data) override
            {
                switch (type)
                {
                    case DATA_DELRISSA_DEATH_COUNT:
                        if (data == SPECIAL)
                            ++DelrissaDeathCount;
                        else
                            DelrissaDeathCount = 0;
                        break;
                    case DATA_KAELTHAS_STATUES:
                        HandleGameObject(KaelStatue[0], data != 0);
                        HandleGameObject(KaelStatue[1], data != 0);
                        break;
                    default:
                        break;
                }
            }

            void OnCreatureCreate(Creature* creature) override
            {
                switch (creature->GetEntry())
                {
                    case NPC_SELIN:
                        SelinGUID = creature->GetGUID();
                        break;
                    case NPC_DELRISSA:
                        DelrissaGUID = creature->GetGUID();
                        break;
                    default:
                        break;
                }
            }

            void OnGameObjectCreate(GameObject* go) override
            {
                switch (go->GetEntry())
                {
                    case GO_VEXALLUS_DOOR:
                    case GO_SELIN_DOOR:
                    case GO_SELIN_ENCOUNTER_DOOR:
                    case GO_DELRISSA_DOOR:
                    case GO_KAEL_DOOR:
                        AddDoor(go, true);
                        break;
                    case GO_KAEL_STATUE_1:
                        KaelStatue[0] = go->GetGUID();
                        break;
                    case GO_KAEL_STATUE_2:
                        KaelStatue[1] = go->GetGUID();
                        break;
                    case GO_ESCAPE_ORB:
                        EscapeOrbGUID = go->GetGUID();
                        break;
                    default:
                        break;
                }
            }

            void OnGameObjectRemove(GameObject* go) override
            {
                switch (go->GetEntry())
                {
                    case GO_VEXALLUS_DOOR:
                    case GO_SELIN_DOOR:
                    case GO_SELIN_ENCOUNTER_DOOR:
                    case GO_DELRISSA_DOOR:
                    case GO_KAEL_DOOR:
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
                    case DATA_DELRISSA:
                        if (state == IN_PROGRESS)
                            DelrissaDeathCount = 0;
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
                    case DATA_SELIN:
                        return SelinGUID;
                    case DATA_DELRISSA:
                        return DelrissaGUID;
                    case DATA_KAEL_STATUE_LEFT:
                        return KaelStatue[0];
                    case DATA_KAEL_STATUE_RIGHT:
                        return KaelStatue[1];
                    case DATA_ESCAPE_ORB:
                        return EscapeOrbGUID;
                    default:
                        break;
                }
                return 0;
            }

        protected:
            ObjectGuid SelinGUID;
            ObjectGuid DelrissaGUID;
            ObjectGuid KaelStatue[2];
            ObjectGuid EscapeOrbGUID;
            uint32 DelrissaDeathCount;
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
            return new instance_magisters_terrace_InstanceMapScript(map);
        }
};

void AddSC_instance_magisters_terrace()
{
    new instance_magisters_terrace();
}
