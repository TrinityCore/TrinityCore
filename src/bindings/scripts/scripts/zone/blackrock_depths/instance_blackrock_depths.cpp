/* Copyright (C) 2006 - 2008 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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

#define ENCOUNTERS 7

struct TRINITY_DLL_DECL instance_blackrock_depths : public ScriptedInstance
{
	instance_blackrock_depths(Map *map) : ScriptedInstance(map) {Initialize();};

	uint64 GateDughal;
	uint64 SupplyRoomGate;
	uint64 GateJaz;
	uint64 GateShill;
	uint64 GateCrest;
	uint64 GateTobias;
	uint64 SupplyCrate;

	uint64 Jaz;
	uint64 Ograbisi;
	uint64 ShillDinger;
	uint64 CrestKiller;

	uint32 state;

	bool Encounters[ENCOUNTERS];

	void Initialize()
    {   
	
		GateDughal = 0;
		SupplyRoomGate = 0;
		GateJaz = 0;
		GateShill = 0;
		GateCrest = 0;
		GateTobias = 0;
		SupplyCrate = 0;

		Jaz = 0;
		Ograbisi = 0;
		ShillDinger = 0;
		CrestKiller = 0;

		state = 0;

		for(uint8 i = 0; i < ENCOUNTERS; i++)
			Encounters[i] = false;
    }
	
	bool IsEncounterInProgress() const
	{
		for(uint8 i = 0; i < ENCOUNTERS; i++)
            if(Encounters[i]) return true;

        return false;
    }

	void OpenGO(uint64 DoorGUID, bool open)
    {
        if(GameObject *Door = instance->GetGameObjectInMap(DoorGUID))
            Door->SetGoState(open ? 0 : 1);
    }

    void CloseGO(uint64 DoorGUID, bool close)
    {
        if(GameObject *Door = instance->GetGameObjectInMap(DoorGUID))
            Door->SetGoState(close ? 1 : 0);
    }

	uint32 GetData(uint32 type)
	{
		switch(type)
		{
		case DATA_DUGHAL:			return Encounters[0];break;
		case DATA_SUPPLY_ROOM:		return Encounters[1];break;
		case DATA_JAZ:				return Encounters[2];break;
		case DATA_SHILL:			return Encounters[3];break;
		case DATA_CREST:			return Encounters[4];break;
		case DATA_TOBIAS:			return Encounters[5];break;
		case DATA_QUEST_JAIL_BREAK: return Encounters[6];break;
		case DATA_GATE_D:			return GateDughal;	break;
		case DATA_GATE_T:			return GateTobias;	break;
		case DATA_GATE_C:			return GateCrest;	break;
		case DATA_GATE_J:			return GateJaz;		break;
		case DATA_GATE_S:			return GateShill;	break;
		case DATA_CREATURE_JAZ:
			if((((Creature*)Jaz)->isDead()))
				state = 1;
			else
				state = 0;
			break;
		case DATA_CREATURE_OGRABISI:
			if((((Creature*)Ograbisi)->isDead()))
				state = 1;
			else
				state = 0;
			break;
		case DATA_CREATURE_CREST:
			if((((Creature*)CrestKiller)->isDead()))
				state = 1;
			else
				state = 0;
			break;
		case DATA_CREATURE_SHILL:
			if((((Creature*)ShillDinger)->isDead()))
				state = 1;
			else
				state = 0;
			break;
		}
		return 0;
	}

	void OnObjectCreate(GameObject *go)
	{
		switch(go->GetEntry())
		{
		case 170561: SupplyRoomGate = go->GetGUID(); state = go->GetGoState(); break; 
		case 170562: GateDughal = go->GetGUID(); state = go->GetGoState();	break;
		case 170566: GateTobias = go->GetGUID(); state = go->GetGoState();	break;
		case 170567: GateCrest = go->GetGUID(); state = go->GetGoState(); break;
		case 170568: GateJaz = go->GetGUID(); state = go->GetGoState(); break;
		case 170569: GateShill = go->GetGUID(); state = go->GetGoState(); break;
		case 166872: SupplyCrate = go->GetGUID(); state = go->GetGoState(); break;
		}
	}

    void OnCreatureCreate(Creature *creature, uint32 creature_entry) 
	{
		switch(creature_entry)
        {
         case 9680: CrestKiller = creature->GetGUID(); break; 
		 case 9677: Ograbisi = creature->GetGUID(); break;
         case 9681: Jaz = creature->GetGUID(); break;
         case 9678: ShillDinger = creature->GetGUID(); break;
        }		
	}

    void SetData(uint32 type, uint32 data)
    {
        switch(type)
        {
        case DATA_DUGHAL: Encounters[0] = data; break;
        case DATA_SUPPLY_ROOM: Encounters[1] = data; break;
        case DATA_JAZ: Encounters[2] = data; break;
        case DATA_SHILL: Encounters[3] = data; break;
        case DATA_CREST: Encounters[4] = data; break;
        case DATA_TOBIAS: Encounters[5] = data; break;
        case DATA_QUEST_JAIL_BREAK: Encounters[6] = data; break;
		case DATA_GATE_SR:
            if(SupplyRoomGate)
            {
               if(data == NOT_STARTED)
					OpenGO(SupplyRoomGate, true);
			   else
					CloseGO(SupplyRoomGate, true);
            }
	        break;
         case DATA_GATE_SC:
            if(SupplyCrate)
            {
               if(data == NOT_STARTED)
					OpenGO(SupplyCrate, true);
			   else
					CloseGO(SupplyCrate, true);
            }
	        break;
		 case DATA_CREATURE_JAZ:
			 if(data)
			 {
				 (((Creature*)Jaz)->setFaction(54));
				 (((Creature*)Ograbisi)->setFaction(54));
				 (((Creature*)Ograbisi)->Say("Ograbisi needs new hat", LANG_UNIVERSAL, NULL));
			 }
			 else
			 {
				 (((Creature*)Jaz)->setFaction(35));
				 (((Creature*)Ograbisi)->setFaction(35));
			 }
			 break;
 		 case DATA_CREATURE_SHILL:
			 if(data)
				(((Creature*)ShillDinger)->setFaction(54));
			 else
				(((Creature*)ShillDinger)->setFaction(35));
			 break;
 		 case DATA_CREATURE_CREST:
			 if(data)
				(((Creature*)CrestKiller)->setFaction(54));
			 else
				(((Creature*)CrestKiller)->setFaction(35));
			 break;
        }
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