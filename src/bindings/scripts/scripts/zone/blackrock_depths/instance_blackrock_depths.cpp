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
SDName: Instance_Blackrock_Depths
SD%Complete: 100
SDComment:
SDCategory: Blackrock Depths
EndScriptData */

/*
update `creature_template` set `npcflag`='1',`ScriptName`='npc_dughal_stormwing' where `entry`='9022';
update `creature_template` set `ScriptName`='npc_marshal_windsor' where `entry`='9023';
update `creature_template` set `ScriptName`='npc_marshal_reginald_windsor' where `entry`='9682';
update `creature_template` set `npcflag`='1',`ScriptName`='npc_tobias_seecher' where `entry`='9679';
update `instance_template` set `script`='instance_blackrock_depths' where `map`='230';
*/

#include "precompiled.h"
#include "def_blackrock_depths.h"

#define ENCOUNTERS              6

#define C_EMPEROR               9019
#define C_PHALANX               9502

#define GO_ARENA1               161525
#define GO_ARENA2               161522
#define GO_ARENA3               161524
#define GO_ARENA4               161523
#define GO_SHADOW_LOCK          161460
#define GO_SHADOW_MECHANISM     161461
#define GO_SHADOW_GIANT_DOOR    157923
#define GO_SHADOW_DUMMY         161516
#define GO_BAR_KEG_SHOT         170607
#define GO_BAR_KEG_TRAP         171941
#define GO_BAR_DOOR             170571
#define GO_TOMB_ENTER           170576
#define GO_TOMB_EXIT            170577
#define GO_LYCEUM               170558
#define GO_GOLEM_ROOM_N         170573
#define GO_GOLEM_ROOM_S         170574
#define GO_THONE_ROOM           170575

struct TRINITY_DLL_DECL instance_blackrock_depths : public ScriptedInstance
{
    instance_blackrock_depths(Map *map) : ScriptedInstance(map) {Initialize();};

    uint32 Encounter[ENCOUNTERS];
    std::string str_data;

    uint64 EmperorGUID;
    uint64 PhalanxGUID;

    uint64 GoArena1GUID;
    uint64 GoArena2GUID;
    uint64 GoArena3GUID;
    uint64 GoArena4GUID;
    uint64 GoShadowLockGUID;
    uint64 GoShadowMechGUID;
    uint64 GoShadowGiantGUID;
    uint64 GoShadowDummyGUID;
    uint64 GoBarKegGUID;
    uint64 GoBarKegTrapGUID;
    uint64 GoBarDoorGUID;
    uint64 GoTombEnterGUID;
    uint64 GoTombExitGUID;
    uint64 GoLyceumGUID;
    uint64 GoGolemNGUID;
    uint64 GoGolemSGUID;
    uint64 GoThoneGUID;

    uint32 BarAleCount;

    void Initialize()
    {
        EmperorGUID = 0;
        PhalanxGUID = 0;

        GoArena1GUID = 0;
        GoArena2GUID = 0;
        GoArena3GUID = 0;
        GoArena4GUID = 0;
        GoShadowLockGUID = 0;
        GoShadowMechGUID = 0;
        GoShadowGiantGUID = 0;
        GoShadowDummyGUID = 0;
        GoBarKegGUID = 0;
        GoBarKegTrapGUID = 0;
        GoBarDoorGUID = 0;
        GoTombEnterGUID = 0;
        GoTombExitGUID = 0;
        GoLyceumGUID = 0;
        GoGolemNGUID = 0;
        GoGolemSGUID = 0;
        GoThoneGUID = 0;

        BarAleCount = 0;

        for(uint8 i = 0; i < ENCOUNTERS; i++)
            Encounter[i] = NOT_STARTED;
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

        debug_log("TSCR: Instance Blackrock Depths: GetPlayerInMap, but PlayerList is empty!");
        return NULL;
    }

    void OnCreatureCreate(Creature *creature, uint32 creature_entry)
    {
        switch(creature->GetEntry())
        {
        case C_EMPEROR: EmperorGUID = creature->GetGUID(); break;
        case C_PHALANX: PhalanxGUID = creature->GetGUID(); break;
        }
    }

    void OnObjectCreate(GameObject* go)
    {
        switch(go->GetEntry())
        {
        case GO_ARENA1: GoArena1GUID = go->GetGUID(); break;
        case GO_ARENA2: GoArena2GUID = go->GetGUID(); break;
        case GO_ARENA3: GoArena3GUID = go->GetGUID(); break;
        case GO_ARENA4: GoArena4GUID = go->GetGUID(); break;
        case GO_SHADOW_LOCK: GoShadowLockGUID = go->GetGUID(); break;
        case GO_SHADOW_MECHANISM: GoShadowMechGUID = go->GetGUID(); break;
        case GO_SHADOW_GIANT_DOOR: GoShadowGiantGUID = go->GetGUID(); break;
        case GO_SHADOW_DUMMY: GoShadowDummyGUID = go->GetGUID(); break;
        case GO_BAR_KEG_SHOT: GoBarKegGUID = go->GetGUID(); break;
        case GO_BAR_KEG_TRAP: GoBarKegTrapGUID = go->GetGUID(); break;
        case GO_BAR_DOOR: GoBarDoorGUID = go->GetGUID(); break;
        case GO_TOMB_ENTER: GoTombEnterGUID = go->GetGUID(); break;
        case GO_TOMB_EXIT: GoTombExitGUID = go->GetGUID(); break;
        case GO_LYCEUM: GoLyceumGUID = go->GetGUID(); break;
        case GO_GOLEM_ROOM_N: GoGolemNGUID = go->GetGUID(); break;
        case GO_GOLEM_ROOM_S: GoGolemSGUID = go->GetGUID(); break;
        case GO_THONE_ROOM: GoThoneGUID = go->GetGUID(); break;
        }
    }

    void SetData(uint32 type, uint32 data)
    {
        Player *player = GetPlayerInMap();

        if (!player)
        {
            debug_log("TSCR: Instance Blackrock Depths: SetData (Type: %u Data %u) cannot find any player.", type, data);
            return;
        }

        debug_log("TSCR: Instance Blackrock Depths: SetData update (Type: %u Data %u)", type, data);

        switch(type)
        {
        case TYPE_RING_OF_LAW:
            Encounter[0] = data;
            break;
        case TYPE_VAULT:
            Encounter[1] = data;
            break;
        case TYPE_BAR:
            if (data == SPECIAL)
                ++BarAleCount;
            else
                Encounter[2] = data;
            break;
        case TYPE_TOMB_OF_SEVEN:
            Encounter[3] = data;
            break;
        case TYPE_LYCEUM:
            Encounter[4] = data;
            break;
        case TYPE_IRON_HALL:
            Encounter[5] = data;
            break;
        }

        if (data == DONE)
        {
            OUT_SAVE_INST_DATA;

            std::ostringstream saveStream;
            saveStream << Encounter[0] << " " << Encounter[1] << " " << Encounter[2] << " "
                << Encounter[3] << " " << Encounter[4] << " " << Encounter[5];

            str_data = saveStream.str();

            SaveToDB();
            OUT_SAVE_INST_DATA_COMPLETE;
        }
    }

    uint32 GetData(uint32 type)
    {
        switch(type)
        {
        case TYPE_RING_OF_LAW:
            return Encounter[0];
        case TYPE_VAULT:
            return Encounter[1];
        case TYPE_BAR:
            if (Encounter[2] == IN_PROGRESS && BarAleCount == 3)
                return SPECIAL;
            else
                return Encounter[2];
        case TYPE_TOMB_OF_SEVEN:
            return Encounter[3];
        case TYPE_LYCEUM:
            return Encounter[4];
        case TYPE_IRON_HALL:
            return Encounter[5];
        }
        return 0;
    }

    uint64 GetData64(uint32 data)
    {
        switch(data)
        {
        case DATA_EMPEROR:
            return EmperorGUID;
        case DATA_PHALANX:
            return PhalanxGUID;
        case DATA_ARENA1:
            return GoArena1GUID;
        case DATA_ARENA2:
            return GoArena2GUID;
        case DATA_ARENA3:
            return GoArena3GUID;
        case DATA_ARENA4:
            return GoArena4GUID;
        case DATA_GO_BAR_KEG:
            return GoBarKegGUID;
        case DATA_GO_BAR_KEG_TRAP:
            return GoBarKegTrapGUID;
        case DATA_GO_BAR_DOOR:
            return GoBarDoorGUID;
        }
        return 0;
    }

    const char* Save()
    {
        return str_data.c_str();
    }

    void Load(const char* in)
    {
        if (!in)
        {
            OUT_LOAD_INST_DATA_FAIL;
            return;
        }

        OUT_LOAD_INST_DATA(in);

        std::istringstream loadStream(in);
        loadStream >> Encounter[0] >> Encounter[1] >> Encounter[2] >> Encounter[3]
        >> Encounter[4] >> Encounter[5];

        for(uint8 i = 0; i < ENCOUNTERS; ++i)
            if (Encounter[i] == IN_PROGRESS)
                Encounter[i] = NOT_STARTED;

        OUT_LOAD_INST_DATA_COMPLETE;
    }
};

InstanceData* GetInstanceData_instance_blackrock_depths(Map* map)
{
    return new instance_blackrock_depths(map);
}

   void AddSC_instance_blackrock_depths()
   {
       Script *newscript;
       newscript = new Script;
       newscript->Name = "instance_blackrock_depths";
       newscript->GetInstanceData = &GetInstanceData_instance_blackrock_depths;
       newscript->RegisterSelf();
   }

