/*
 * Copyright (C) 2017-2019 AshamaneProject <https://github.com/AshamaneProject>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 *  ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "Creature.h"
#include "GameObject.h"
#include "Map.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "cathedral_of_eternal_night.h"
  /*
   REPLACE INTO `instance_template` (`map`,`parent`,`script`,`allowMount`) VALUES (1677,1220,'instance_cathedral_of_eternal_night',0);
 UPDATE `instance_template` SET `script`='instance_cathedral_of_eternal_night' WHERE `map`=1677;
   */
DoorData const doorData[] =
{
{ GO_BOSS1_DOOR_1,          DATA_AGRONOX,      DOOR_TYPE_ROOM },
{ GO_BOSS1_DOOR_2,          DATA_AGRONOX,      DOOR_TYPE_ROOM },
{ GO_BOSS1_DOOR_3,          DATA_AGRONOX,      DOOR_TYPE_ROOM },
{ GO_BOSS1_DOOR_4,          DATA_AGRONOX,      DOOR_TYPE_ROOM },
{ GO_BOSS1_POST_BOSS_DOOR,  DATA_AGRONOX,      DOOR_TYPE_ROOM },
{ GO_PORTCULLIS_001,        DATA_AGRONOX,      DOOR_TYPE_ROOM },
{ GO_PORTCULLIS_002,        DATA_THRASHBITE_THE_SCORNFUL,      DOOR_TYPE_ROOM },
{ GO_PORTCULLIS_003,        DATA_THRASHBITE_THE_SCORNFUL,            DOOR_TYPE_ROOM },
{ GO_KOBOLD_SACKSMALL_001,  DATA_THRASHBITE_THE_SCORNFUL,  DOOR_TYPE_ROOM },
{ GO_BOSS2_DOOR_1,          DATA_THRASHBITE_THE_SCORNFUL,  DOOR_TYPE_ROOM },
{ GO_BOSS2_DOOR_2,          DATA_THRASHBITE_THE_SCORNFUL,  DOOR_TYPE_ROOM },
{ GO_BOSS2_DOOR_3,          DATA_THRASHBITE_THE_SCORNFUL,  DOOR_TYPE_ROOM },
{ GO_BOSS3_POST_BOSS_DOOR,  DATA_DOMATRAX,            DOOR_TYPE_ROOM },
{ GO_BOSS3_DOOR,            DATA_DOMATRAX,            DOOR_TYPE_ROOM },
{ GO_BOSS4_DOOR,            DATA_MEPHISTROTH,         DOOR_TYPE_ROOM }
};

Position const pos1 = { -518.0295f, 2525.428f, 534.6553f, 3.235034f }; ///summon NPC_MEPHISTROTH

class instance_cathedral_of_eternal_night : public InstanceMapScript
{
    public:
        instance_cathedral_of_eternal_night() : InstanceMapScript("instance_cathedral_of_eternal_night", 1677) { }

        struct instance_cathedral_of_eternal_night_InstanceMapScript : public InstanceScript
        {
            instance_cathedral_of_eternal_night_InstanceMapScript(InstanceMap* map) : InstanceScript(map) { }

            void Initialize() override
            {
       SetHeaders(DataHeader);
                SetBossNumber(DATA_MAX_ENCOUNTERS);
                //LoadDoorData(doorData);
            }
            /*
            void OnGameObjectCreate(GameObject* go) override
            {
                switch (go->GetEntry())
                {
                case GO_BOSS1_DOOR_1:
                case GO_BOSS1_DOOR_2:
                case GO_BOSS1_DOOR_3:
                case GO_BOSS1_DOOR_4:
                case GO_BOSS1_POST_BOSS_DOOR:
                case GO_PORTCULLIS_001:
                case GO_PORTCULLIS_002:
                case GO_PORTCULLIS_003:
                case GO_KOBOLD_SACKSMALL_001:
                case GO_BOSS2_DOOR_1:
                case GO_BOSS2_DOOR_2:
                case GO_BOSS2_DOOR_3:
                case GO_BOSS3_POST_BOSS_DOOR:
                case GO_BOSS3_DOOR:
                case GO_BOSS4_DOOR:
                    AddDoor(go, true);
                    break;
                case GO_FONT_OF_POWER:
                    AddObject(go, true);
                    break;
                default:
                    break;
                }
            }
            void OnGameObjectRemove(GameObject* go) override
            {
                switch (go->GetEntry())
                {
                case GO_BOSS1_DOOR_1:
                case GO_BOSS1_DOOR_2:
                case GO_BOSS1_DOOR_3:
                case GO_BOSS1_DOOR_4:
                case GO_BOSS1_POST_BOSS_DOOR:
                case GO_PORTCULLIS_001:
                case GO_PORTCULLIS_002:
                case GO_PORTCULLIS_003:
                case GO_KOBOLD_SACKSMALL_001:
                case GO_BOSS2_DOOR_1:
                case GO_BOSS2_DOOR_2:
                case GO_BOSS2_DOOR_3:
                case GO_BOSS3_POST_BOSS_DOOR:
                case GO_BOSS3_DOOR:
                case GO_BOSS4_DOOR:
                    AddDoor(go, false);
                    break;
                case GO_FONT_OF_POWER:
                    AddObject(go, false);
                    break;
                default:
                    break;
                }
            }
            */
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
            return new instance_cathedral_of_eternal_night_InstanceMapScript(map);
        }
};

void AddSC_instance_cathedral_of_eternal_night()
{
    new instance_cathedral_of_eternal_night();
}
