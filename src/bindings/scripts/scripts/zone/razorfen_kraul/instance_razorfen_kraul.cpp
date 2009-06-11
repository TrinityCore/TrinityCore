/* Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

/* ScriptData
SDName: Instance_Razorfen_Kraul
SD%Complete:
SDComment:
SDCategory: Razorfen Kraul
EndScriptData */

#include "precompiled.h"
#include "def_razorfen_kraul.h"


#define WARD_KEEPERS_NR 2

struct TRINITY_DLL_DECL instance_razorfen_kraul : public ScriptedInstance
{
    instance_razorfen_kraul(Map *map) : ScriptedInstance(map) {Initialize();};

    uint64 DoorWardGUID;
    uint32 WardCheck_Timer;
    int WardKeeperAlive;

    void Initialize()
    {
        WardKeeperAlive = 1;
        WardCheck_Timer = 4000;
        DoorWardGUID = 0;
    }

    Player* GetPlayerInMap()
    {
        Map::PlayerList const& players = instance->GetPlayers();

        if (!players.isEmpty())
        {
            for(Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
            {
                if (Player* plr = itr->getSource())
                    return plr;
            }
        }
        debug_log("TSCR: Instance Razorfen Kraul: GetPlayerInMap, but PlayerList is empty!");
        return NULL;
    }

    void OnObjectCreate(GameObject *go)
    {
        switch(go->GetEntry())
        {
        case 21099: DoorWardGUID = go->GetGUID(); break;
        }
    }

    void HandleGameObject(uint64 guid, uint32 state)
    {
        Player *player = GetPlayerInMap();

        if (!player || !guid)
        {
            debug_log("SD2: Instance Razorfen Kraul: HandleGameObject fail");
            return;
        }

        if (GameObject *go = GameObject::GetGameObject(*player,guid))
            go->SetGoState(state);
    }

    void Update(uint32 diff)
    {
        if (WardCheck_Timer < diff)
        {
            HandleGameObject(DoorWardGUID, WardKeeperAlive);
            WardKeeperAlive = 0;
            WardCheck_Timer = 4000;
        }else
            WardCheck_Timer -= diff;
    }     

    void SetData(uint32 type, uint32 data)
    {
        switch(type)
        {
            case TYPE_WARD_KEEPERS:
                if (data == NOT_STARTED)
                    WardKeeperAlive = 1;
                break;
        }
    }

};

InstanceData* GetInstanceData_instance_razorfen_kraul(Map* map)
{
    return new instance_razorfen_kraul(map);
}

void AddSC_instance_razorfen_kraul()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "instance_razorfen_kraul";
    newscript->GetInstanceData = &GetInstanceData_instance_razorfen_kraul;
    newscript->RegisterSelf();
}