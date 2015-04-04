/*
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
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
SDName: Instance_Razorfen_Kraul
SD%Complete:
SDComment:
SDCategory: Razorfen Kraul
EndScriptData */

#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "razorfen_kraul.h"
#include "Player.h"

#define WARD_KEEPERS_NR 2

class instance_razorfen_kraul : public InstanceMapScript
{
public:
    instance_razorfen_kraul() : InstanceMapScript("instance_razorfen_kraul", 47) { }

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_razorfen_kraul_InstanceMapScript(map);
    }

    struct instance_razorfen_kraul_InstanceMapScript : public InstanceScript
    {
        instance_razorfen_kraul_InstanceMapScript(Map* map) : InstanceScript(map)
        {
            SetHeaders(DataHeader);
            WardKeeperDeath = 0;
        }

        ObjectGuid DoorWardGUID;
        int WardKeeperDeath;

        Player* GetPlayerInMap()
        {
            Map::PlayerList const& players = instance->GetPlayers();

            if (!players.isEmpty())
            {
                for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                {
                    if (Player* player = itr->GetSource())
                        return player;
                }
            }
            TC_LOG_DEBUG("scripts", "Instance Razorfen Kraul: GetPlayerInMap, but PlayerList is empty!");
            return NULL;
        }

        void OnGameObjectCreate(GameObject* go) override
        {
            switch (go->GetEntry())
            {
                case 21099: DoorWardGUID = go->GetGUID(); break;
                case 20920: go->SetUInt32Value(GAMEOBJECT_FACTION, 0); break; // big fat fugly hack
            }
        }

        void Update(uint32 /*diff*/) override
        {
            if (WardKeeperDeath == WARD_KEEPERS_NR)
                if (GameObject* go = instance->GetGameObject(DoorWardGUID))
                {
                    go->SetUInt32Value(GAMEOBJECT_FLAGS, 33);
                    go->SetGoState(GO_STATE_ACTIVE);
                }
        }

        void SetData(uint32 type, uint32 /*data*/) override
        {
            switch (type)
            {
                case EVENT_WARD_KEEPER: WardKeeperDeath++; break;
            }
        }

    };

};

void AddSC_instance_razorfen_kraul()
{
    new instance_razorfen_kraul();
}
