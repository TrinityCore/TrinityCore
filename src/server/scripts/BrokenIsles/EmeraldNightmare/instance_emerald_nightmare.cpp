/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
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
#include "emerald_nightmare.h"
#include "GameObject.h"
#include "InstanceScript.h"
#include "Map.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"

/*DoorData const doorData[] =
{
};*/

class instance_emerald_nightmare : public InstanceMapScript
{
    public:
        instance_emerald_nightmare() : InstanceMapScript("instance_emerald_nightmare", 1520) { }

        struct instance_emerald_nightmare_InstanceMapScript : public InstanceScript
        {
            instance_emerald_nightmare_InstanceMapScript(Map* map) : InstanceScript(map) { }

            void Initialize() override
            {
                SetBossNumber(DATA_MAX_ENCOUNTERS);
                //LoadDoorData(doorData);
            }

            void OnCreatureCreate(Creature* creature) override
            {
                switch (creature->GetEntry())
                {
                    case NPC_NYTHENDRA:
                    case NPC_ILGYNOTH:
                    case NPC_ELERETHE_RENFERAL:
                    case NPC_URSOC:
                    case NPC_YSONDRE:
                    case NPC_EMERISS:
                    case NPC_LETHON:
                    case NPC_TAERAR:
                    case NPC_CENARIUS:
                    case NPC_XAVIUS:
                        AddObject(creature, true);
                        break;
                    default:
                        break;
                }
            }

            /*void OnGameObjectCreate(GameObject* go) override
            {
                switch (go->GetEntry())
                {
                    case GO_DOOR_ROOM_XAVIUS:
                        AddDoor(go, true);
                        break;
                    default:
                        break;
                }
            }*/

           /* void OnGameObjectRemove(GameObject* go) override
            {
                switch (go->GetEntry())
                {
                    case GO_DOOR_ROOM_XAVIUS:
                        AddDoor(go, false);
                        break;
                    default:
                        break;
                }
            }*/
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
            return new instance_emerald_nightmare_InstanceMapScript(map);
        }
};

void AddSC_instance_emerald_nightmare()
{
    new instance_emerald_nightmare();
}
