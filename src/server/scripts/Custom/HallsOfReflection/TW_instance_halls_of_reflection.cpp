/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
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
#include "TW_halls_of_reflection.h"

#define MAX_ENCOUNTER 3

/* Halls of Reflection encounters:
0- Falric
1- Marwyn
2- The Lich King
*/

enum Events
{
    EVENT_NONE,
    EVENT_NEXT_WAVE,
};

#define PI 3.14159265
#define SPAWN_POS_X	5310.52f
#define SPAWN_POS_Y	2006.15f
#define SPAWN_POS_Z	709.0f

uint32 hor_mobIDs[] = {
	38175,	//Ghostly Priest
	38172,	//Phantom Mage
	38177,	//Shadowy Mercenary
	38173,	//Spectral Footman
	38176	//Tortured Rifleman
};
#define MOBIDS_SIZE	5

#define NPC_SYLVANAS_A		37221
#define NPC_SYLVANAS_H		37223
#define NPC_SYLVANAS		(uiTeamInInstance==ALLIANCE?NPC_SYLVANAS_A:NPC_SYLVANAS_H)
#define POS_SYLVANAS_INIT	5262.203f,	1947.806f,	707.70f,		3.7657f

#define POS_FALRIC		5277.170f,	2037.408f,	710.0f,		5.515f
#define POS_MARWYN		5339.479f,	1978.653f,	710.0f,		2.472f
#define POS_GENERAL		5413.81f,	2116.033f,	708.0f,		4.021f

#include<deque>
using namespace std;

enum DelayedCall{
	DELAYED_CALL_NONE,
	DELAYED_CALL_SPAWN_SYL,
	DELAYED_CALL_SPAWN_BEGIN,
	DELAYED_CALL_SPAWN_GENERAL,
	DELAYED_CALL_SPAWN_LICHKING,
};

class TW_instance_halls_of_reflection : public InstanceMapScript
{
public:
    TW_instance_halls_of_reflection() : InstanceMapScript("TW_instance_halls_of_reflection", 668) { }

    InstanceScript* GetInstanceScript(InstanceMap* map) const
    {
        return new TW_instance_halls_of_reflection_InstanceMapScript(map);
    }

    struct TW_instance_halls_of_reflection_InstanceMapScript : public InstanceScript
    {
        TW_instance_halls_of_reflection_InstanceMapScript(Map* map) : InstanceScript(map) {/*printf("InstanceScript Constructor\n");*/};

        //BEGIN Variables
        uint64 uiFalric;
        uint64 uiMarwyn;
        uint64 uiJainaPart1;
        uint64 uiSylvanasPart1;

        uint64 uiFrostmourne;
        uint64 uiFrostmourneAltar;
        uint64 uiArthasDoor;
        uint64 uiFrontDoor;

        uint32 uiEncounter[MAX_ENCOUNTER];
        uint32 uiTeamInInstance;
        uint32 uiWaveCount;
        bool bIntroDone;

        EventMap events;
	InstanceState state;
	uint32 statecheck_timer;
        
        deque<uint64> marwynAdds;
        deque<uint64> falricAdds;
        deque<uint64> activeAdds;
        uint32 wave_num_mobs;
	uint32 wave_counter;
	uint64 generalGUID;
	uint64 lichkingGUID;
	uint64 sylvanas2GUID;
	deque<uint64> icewallGUIDs;
	uint8 LK_wave_counter;
	uint8 LK_num_mobs;
	DelayedCall delayedCall;
	uint64 LK_chest_A, LK_chest_H;
	//END Variables
	
	//BEGIN General Instance stuff
        void Initialize()
        {
// 		printf("Initialize\n");
            events.Reset();

            uiFalric = 0;
            uiMarwyn = 0;
            uiJainaPart1 = 0;
            uiSylvanasPart1 = 0;

            uiFrostmourne = 0;
            uiFrostmourneAltar = 0;
            uiArthasDoor = 0;
            uiFrontDoor = 0;
            uiTeamInInstance = 0;
            uiWaveCount = 0;
            bIntroDone = false;

            for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
                uiEncounter[i] = NOT_STARTED;
            
            wave_num_mobs = 0;
	    wave_counter = 0;
	    generalGUID = 0;
	    lichkingGUID = 0;
	    sylvanas2GUID = 0;
	    icewallGUIDs.clear();
	    for(uint8 i = 0; i < 4; i++)
		icewallGUIDs.push_back(0);
	    LK_wave_counter = 0;
	    LK_num_mobs = 0;
	    delayedCall = DELAYED_CALL_NONE;
	    LK_chest_A = LK_chest_H = 0;
	    
	    state = ISTATE_BEGIN;
	    statecheck_timer = 0;
        }
        
        void OnPlayerEnter(Player *player){
// 		printf("OnPlayerEnter(%s)\n", player->GetName());
		if(uiEncounter[0]==NOT_STARTED && uiJainaPart1==0 && uiSylvanasPart1==0)
			SpawnSylvanas();
        }

        void OnCreatureCreate(Creature* creature)
        {
// 		printf("OnCreatureCreate %s\n", creature->GetName());
            Map::PlayerList const &players = instance->GetPlayers();
            if (!players.isEmpty())
                if (Player* player = players.begin()->GetSource())
                    uiTeamInInstance = player->GetTeam();

            switch (creature->GetEntry())
            {
                case NPC_FALRIC:
                    uiFalric = creature->GetGUID();
                    break;
                case NPC_MARWYN:
                    uiMarwyn = creature->GetGUID();
                    break;
                case NPC_JAINA_PART1:
                    uiJainaPart1 = creature->GetGUID();
                    break;
                case NPC_SYLVANAS_PART1:
                    uiSylvanasPart1 = creature->GetGUID();
                    break;
            }
        }

        void OnGameObjectCreate(GameObject* go)
        {
            // TODO: init state depending on encounters
            switch (go->GetEntry())
            {
                case GO_FROSTMOURNE:
                    uiFrostmourne = go->GetGUID();
                    go->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_INTERACT_COND);
                    HandleGameObject(0, false, go);
                    break;
                case GO_FROSTMOURNE_ALTAR:
                    uiFrostmourneAltar = go->GetGUID();
                    go->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_INTERACT_COND);
                    HandleGameObject(0, true, go);
                    break;
                case GO_FRONT_DOOR:
                    uiFrontDoor = go->GetGUID();
                    go->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_INTERACT_COND);
                    HandleGameObject(0, true, go);
                    break;
                case GO_ARTHAS_DOOR:
                    uiArthasDoor = go->GetGUID();
                    go->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_INTERACT_COND);

                    if (uiEncounter[1] == DONE)
                        HandleGameObject(0, true, go);
                    else
                        HandleGameObject(0, false, go);
                    break;
                case GO_ICE_WALL:
			if( go->GetDistance( WP_SYL_1 ) <= 30.0 )
				icewallGUIDs[0] = go->GetGUID();
			else if( go->GetDistance( WP_SYL_2 ) <= 30.0 )
				icewallGUIDs[1] = go->GetGUID();
			else if( go->GetDistance( WP_SYL_3 ) <= 30.0 )
				icewallGUIDs[2] = go->GetGUID();
			else
				icewallGUIDs[3] = go->GetGUID();
			
			if( GetData(DATA_LICHKING_EVENT) != DONE ){
				go->SetGoState( GO_STATE_READY );
				go->SetPhaseMask( 2, true );
			}
			break;
		case GO_CHEST_A_1:
		case GO_CHEST_A_2:
			LK_chest_A = go->GetGUID();
			break;
		case GO_CHEST_H_1:
		case GO_CHEST_H_2:
			LK_chest_H = go->GetGUID();
			break;
            }
        }

        void SetData(uint32 type, uint32 data)
        {
// 		printf("SetData(%u, %u)\n", type, data);
            if (type == DATA_WAVE_COUNT && data == SPECIAL)
            {
				if(!bIntroDone){///Takes care of spawning the entire first part of the instance.
					SpawnBeginMobs();
					Creature *c = 0;
					if(uiJainaPart1!=0)
						c = instance->GetCreature(uiJainaPart1);
					else if(uiSylvanasPart1)
						c = instance->GetCreature(uiSylvanasPart1);
					c->MonsterYell("Begin mobs should be spawned now.", LANG_UNIVERSAL, 0);
					//assert(0);
				}
                bIntroDone = true;
                events.ScheduleEvent(EVENT_NEXT_WAVE, 10000);
                return;
            }
            
            ///Ruben: This is called upon creature death, but probably can be used to detect wipes too, TODO
            if(type==DATA_WAVE_CHECK && data == 1)
		WaveActivityCheck();

            switch (type)
            {
                case DATA_FALRIC_EVENT:
                    uiEncounter[0] = data;
                    if (data == DONE){///First boss down, one minute rest, then spawn next.
				events.ScheduleEvent(EVENT_NEXT_WAVE, 60000);
				state = ISTATE_MARWYN_TRASH;
		    }else if(data==FAIL){
				DoWipeBeforeMarwyn();
				uiEncounter[0] = NOT_STARTED;
				state = ISTATE_FALRIC_TRASH;
                    }else if(data==IN_PROGRESS)
			    state = ISTATE_FALRIC;
                    break;
                case DATA_MARWYN_EVENT:
			uiEncounter[1] = data;
			if (data == DONE){///Second boss down, open the door and spawn the general.
				HandleGameObject(uiArthasDoor, true);
				SpawnGeneral();
				state = ISTATE_GENERAL;
                    }else if(data==FAIL){
			DoWipeBeforeMarwyn();
			uiEncounter[1] = NOT_STARTED;
			state = ISTATE_MARWYN_TRASH;
                    }else if(data==IN_PROGRESS)
			    state = ISTATE_MARWYN;
                    break;
                case DATA_LICHKING_EVENT:
			if(data==DONE){///Lich King gauntlet done, TODO
				state = ISTATE_DONE;
				if(Creature *c = instance->GetCreature(lichkingGUID))
					c->DisappearAndDie();
				DoRespawnGameObject(uiTeamInInstance==ALLIANCE?LK_chest_A:LK_chest_H, 7*DAY);
			}else if(data==NOT_STARTED && uiEncounter[2] != NOT_STARTED){
				DoWipeOnLichKing();
				state = ISTATE_LICHKING;
			}
			uiEncounter[2] = data;
			break;
                case DATA_GENERAL_EVENT:///Used only for spawning the Lich King, etc.
			if(data == DONE){
				SpawnLichKing();
				state = ISTATE_LICHKING;
			}
			break;
		///Used for sending waves in LK event
		case DATA_LK_SEND_WAVE:
			SendLKWave( data );
			break;
		case DATA_LK_ADD_MOB:
			LK_num_mobs++;
			break;
		case DATA_LK_DEL_MOB:
			LK_num_mobs--;
			if(LK_num_mobs==0)
				BreakIceWall();
			break;
            }

            if (data == DONE)
                SaveToDB();
        }

        uint32 GetData(uint32 type)const
        {
            switch (type)
            {
                case DATA_FALRIC_EVENT:         return uiEncounter[0];
                case DATA_MARWYN_EVENT:         return uiEncounter[1];
                case DATA_LICHKING_EVENT:       return uiEncounter[2];
                case DATA_WAVE_COUNT:           return uiWaveCount;
                case DATA_TEAM_IN_INSTANCE:     return uiTeamInInstance;
            }

            return 0;
        }

        uint64 GetData64(uint32 identifier)const
        {
            switch (identifier)
            {
                case DATA_FALRIC:               return uiFalric;
                case DATA_MARWYN:               return uiMarwyn;
                case DATA_FROSTMOURNE:          return uiFrostmourne;
                case NPC_LICHKING2:		return lichkingGUID;
                case DATA_SYLVANAS2:		return sylvanas2GUID;
            }

            return 0;
        }
        
        void SetData64(uint32 identifier, uint64 data){
		switch(identifier){
			case DATA_SYLVANAS2:
				sylvanas2GUID = data;
				break;
			default:
				break;
		}
        }
        
        void Update(uint32 diff)
        {
            if (!instance->HavePlayers())
                return;
            
            if(delayedCall!=DELAYED_CALL_NONE){
		Map::PlayerList const &players = instance->GetPlayers();
		if (!players.isEmpty())
			if (Player* player = players.begin()->GetSource())
				uiTeamInInstance = player->GetTeam();
            }
            
            switch(delayedCall){
		case DELAYED_CALL_NONE:
			break;
		case DELAYED_CALL_SPAWN_SYL:
			delayedCall = DELAYED_CALL_NONE;
			SpawnSylvanas();
			break;
		case DELAYED_CALL_SPAWN_BEGIN:
			delayedCall = DELAYED_CALL_NONE;
			SpawnBeginMobs();
			break;
		case DELAYED_CALL_SPAWN_GENERAL:
			delayedCall = DELAYED_CALL_NONE;
			SpawnGeneral();
			break;
		case DELAYED_CALL_SPAWN_LICHKING:
			delayedCall = DELAYED_CALL_NONE;
			SpawnLichKing();
			break;
            }
            
            statecheck_timer += diff;
	    if(statecheck_timer > 10000){
		statecheck_timer = 0;
		DoStateCheck();
	    }

            events.Update(diff);

            switch (events.ExecuteEvent())
            {
                case EVENT_NEXT_WAVE:
                    uiWaveCount++;
                    AddWave();
                    break;
            }
        }
        
        void DoStateCheck(){
		bool reset = false;
		switch(state){
			case ISTATE_BEGIN:
				//Nothing to do here, I suppose.
				break;
			case ISTATE_FALRIC_TRASH:
				if(falricAdds.size() == 0 && activeAdds.size() == 0){
					//Not sure what to do.
				}
				break;
			case ISTATE_FALRIC:
				if(uiFalric==0 || instance->GetCreature(uiFalric)==0){
					//Not sure what to do.
				}
				break;
			case ISTATE_MARWYN_TRASH:
				if(marwynAdds.size() == 0 && activeAdds.size() == 0){
					//Not sure what to do.
				}
				break;
			case ISTATE_MARWYN:
				if(uiMarwyn==0 || instance->GetCreature(uiMarwyn)==0){
					//Not sure what to do.
				}
				break;
			case ISTATE_GENERAL:
				if(generalGUID == 0 || instance->GetCreature(generalGUID) == 0){
					SpawnGeneral();
				}
				break;
			case ISTATE_LICHKING:
				if( lichkingGUID == 0 || instance->GetCreature(lichkingGUID) == 0 ){
					lichkingGUID = 0;
					reset = true;
					if(sylvanas2GUID&&instance->GetCreature(sylvanas2GUID))
						instance->GetCreature(sylvanas2GUID)->DespawnOrUnsummon();
				}else if( sylvanas2GUID == 0 || instance->GetCreature(sylvanas2GUID) == 0 ){
					sylvanas2GUID = 0;
					reset = true;
				}
				if(reset)
					SpawnLichKing();
				break;
			case ISTATE_DONE:
				//Nothing to do here.
				break;
		}
	}
        //END General Instance Stuff

        //BEGIN Load/Save Stuff
        std::string GetSaveData()
        {
            OUT_SAVE_INST_DATA;

            std::ostringstream saveStream;
            saveStream << "H R 1 " << uiEncounter[0] << ' ' << uiEncounter[1] << ' ' << uiEncounter[2];

            OUT_SAVE_INST_DATA_COMPLETE;
            return saveStream.str();
        }

        void Load(const char* in)
        {
		printf("Load\n");
            if (!in)
            {
                OUT_LOAD_INST_DATA_FAIL;
                return;
            }

            OUT_LOAD_INST_DATA(in);

            char dataHead1, dataHead2;
            uint16 version;
            uint16 data0, data1, data2;

            std::istringstream loadStream(in);
            loadStream >> dataHead1 >> dataHead2 >> version >> data0 >> data1 >> data2;

            if (dataHead1 == 'H' && dataHead2 == 'R')
            {
                uiEncounter[0] = data0;
                uiEncounter[1] = data1;
                uiEncounter[2] = data2;

                for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
                    if (uiEncounter[i] == IN_PROGRESS)
                        uiEncounter[i] = NOT_STARTED;

            } else OUT_LOAD_INST_DATA_FAIL;

            if (uiEncounter[0] == DONE || uiEncounter[1] == DONE)
                bIntroDone = true;

            OUT_LOAD_INST_DATA_COMPLETE;
         printf("e\n");   
            SetupInstanceAfterLoad();
            printf("f\n");
        }
        
        
        void SetupInstanceAfterLoad(){
// 		printf("SetupInstanceAfterLoad\n");
		if(GetData(DATA_FALRIC_EVENT) != DONE || GetData(DATA_MARWYN_EVENT) != DONE)
			SpawnSylvanas();
		else if(GetData(DATA_LICHKING_EVENT) != DONE)
			SpawnGeneral();
        }
        //END Load/Save Stuff
        
        void SpawnSylvanas(){
// 		printf("SpawnSylvanas\n");
		Map::PlayerList const &PlayerList = instance->GetPlayers();
		
		if(PlayerList.isEmpty()){
			delayedCall = DELAYED_CALL_SPAWN_SYL;
			return;
		}
		
		Player *player = PlayerList.begin()->GetSource();
		if( player == 0 ){
			delayedCall = DELAYED_CALL_SPAWN_SYL;
			return;
		}
		
		DespawnMob(uiJainaPart1);uiJainaPart1=0;
		DespawnMob(uiSylvanasPart1);uiSylvanasPart1=0;
		
		
		/*Creature *mob = 0;
		mob = */player->SummonCreature( NPC_SYLVANAS, POS_SYLVANAS_INIT, TEMPSUMMON_DEAD_DESPAWN, 0 );
		bIntroDone=false;
		
        }

        void AddWave()
        {
            DoUpdateWorldState(WORLD_STATE_HOR, 1);
//             if(uiWaveCount < 12)
// 		DoUpdateWorldState(WORLD_STATE_HOR_WAVE_COUNT, uiWaveCount > 5 ? uiWaveCount-1:uiWaveCount);
	    DoUpdateWorldState(WORLD_STATE_HOR_WAVE_COUNT, uiWaveCount);

            switch (uiWaveCount)
            {
                case 1:
                case 2:
                case 3:
                case 4:
                    if (Creature* pFalric = instance->GetCreature(uiFalric))
                        SpawnWave(pFalric);
                    break;
                case 5:
                    if (GetData(DATA_FALRIC_EVENT) == DONE){
                        events.ScheduleEvent(EVENT_NEXT_WAVE, 10000);
                    }else if (Creature* pFalric = instance->GetCreature(uiFalric)){
                        if (pFalric->AI())
                            pFalric->AI()->DoAction(ACTION_ENTER_COMBAT);
//                         else
// 				printf("Falric not found\n");
                    }
                    wave_counter = 0;
                    break;
                case 6:
                case 7:
                case 8:
                case 9:
                    if (Creature* pMarwyn  = instance->GetCreature(uiMarwyn))
                        SpawnWave(pMarwyn);
                    break;
                case 10:
                    if (GetData(DATA_MARWYN_EVENT) != DONE) // wave should not have been started if DONE. Check anyway to avoid bug exploit!
                        if (Creature* pMarwyn = instance->GetCreature(uiMarwyn))
                            if (pMarwyn->AI())
                                pMarwyn->AI()->DoAction(ACTION_ENTER_COMBAT);
                    break;
            }
        }

        // spawn a wave on behalf of the summoner.
        void SpawnWave(Creature* summoner)
        {
		if(summoner->GetGUID() == uiFalric)
			ActivateWaveFalric();
		else
			ActivateWaveMarwyn();
        }

        
        
        ///Spawns all begin trash and bosses.
        void SpawnBeginMobs(){
// 		printf("SpawnBeginMobs\n");
		Map::PlayerList const &PlayerList = instance->GetPlayers();
		
		if(PlayerList.isEmpty()){
			delayedCall = DELAYED_CALL_SPAWN_BEGIN;
			return;
		}
		
		Player *player = PlayerList.begin()->GetSource();
		if( player == 0 ){
			delayedCall = DELAYED_CALL_SPAWN_BEGIN;
			return;
		}
		
		
		
		///It is possible this function is called after Falric was killed...
		Creature *mob = 0;
		if(GetData(DATA_FALRIC_EVENT)!=DONE){
			mob = player->SummonCreature( NPC_FALRIC, POS_FALRIC, TEMPSUMMON_DEAD_DESPAWN, 0 );
			mob->SetVisible(true);
			mob->MonsterYell( "As you wish, My Lord.", LANG_UNIVERSAL, 0 );
			((ScriptedAI*)mob->AI())->DoPlaySoundToSet( mob, 16717 );
			uiFalric = mob->GetGUID();
		}else
			uiWaveCount = 6;
		
		
		if(GetData(DATA_MARWYN_EVENT)==DONE){
			/*Player *player = PlayerList.begin()->GetSource();
			player->MonsterYell("FATAL in TW_instance_halls_of_reflection.cpp: SpawnBeginMobs() called when DATA_MARWYN_EVENT==TRUE.\n", LANG_UNIVERSAL, true);*/
			printf("FATAL in TW_instance_halls_of_reflection.cpp: SpawnBeginMobs() called when DATA_MARWYN_EVENT==TRUE.\n");
			return;
		}
		mob = player->SummonCreature( NPC_MARWYN, POS_MARWYN, TEMPSUMMON_DEAD_DESPAWN, 0 );
		mob->SetVisible(true);
		mob->MonsterYell( "As you wish, My Lord.", LANG_UNIVERSAL, 0 );
		((ScriptedAI*)mob->AI())->DoPlaySoundToSet( mob, 16741 );
		uiMarwyn = mob->GetGUID();
		
		///TODO: Spawn 8 less.
		int counter = 0;
		for( int i = 0; i < 4; i++ ){
			for(int alpha = -21 + i * 90; alpha - i * 90 < 21; alpha += 6){
// 			for( int alpha = -18 + i * 90; alpha - i * 90 < 18; alpha += 4 ){
				float dist = /*alpha%8 ? 37.5 : */35.0;
				float a = alpha / 180.0 * PI;
				float x = cos(a) * dist;
				float y = sin(a) * dist;
				SpawnBeginMob( x, y, a, counter++, mob );
			}
		}
	}

	///Helper function
	///TODO: Check if correct
	void SpawnBeginMob( float x, float y, float a, int counter, Unit *summoner ){
		//If Falric event completed, only spawn mobs for Marwyn
		if( GetData(DATA_FALRIC_EVENT) == DONE && counter % 2 == 1 )
			return;

		//printf("SpawnBeginMob called...\n");
		//summoner->MonsterYell("SpawnBeginMob called...\n", LANG_UNIVERSAL, 0);


		//Retrieve ID of mob to spawn
		uint32 id = hor_mobIDs[ counter % MOBIDS_SIZE ];

		//Spawn the mob
		Creature *mob = summoner->SummonCreature( id, x + SPAWN_POS_X, y + SPAWN_POS_Y, SPAWN_POS_Z, a + PI, TEMPSUMMON_DEAD_DESPAWN, 0 );
		/*if(mob!=0&&mob->GetGUID()!=0)
			//printf("\tMob should have been properly spawned.\n");
				summoner->MonsterYell("\tMob should have been properly spawned.\n", LANG_UNIVERSAL, 0);
		else
			//printf("Error spawning mob o.o!!!\n");
			summoner->MonsterYell("Error spawning mob o.o!!!\n", LANG_UNIVERSAL, 0);*/

		//Set its 'owner'
		if( counter % 2 == 0 )
			marwynAdds.push_back( mob->GetGUID() );
		else
			falricAdds.push_back( mob->GetGUID() );
	}
	
	///Should take care of throwing events to spawn new waves
	///TODO: Should check for wipe too (?)
	void WaveActivityCheck(){
		bool wipe=false;
		while(activeAdds.size() > 0){
			Creature *c = instance->GetCreature(activeAdds[0]);
			if(c==0||c->isDead())
				activeAdds.pop_front();
			else{
 				c->MonsterYell("Still active", LANG_UNIVERSAL, 0);
 				if(c->IsInCombat())
 					c->MonsterYell("In combat", LANG_UNIVERSAL, 0);
 				else
 					c->MonsterYell("Not In combat", LANG_UNIVERSAL, 0);
 				if(c->IsInEvadeMode())
 					c->MonsterYell("In evade mode", LANG_UNIVERSAL, 0);
 				else
 					c->MonsterYell("Not in evade mode", LANG_UNIVERSAL, 0);
				if(!c->IsInCombat()||c->IsInEvadeMode()){
					DoWipeBeforeMarwyn();
					wipe=true;
				}
				break;
			}
		}
	
		if( !wipe && activeAdds.size() == 0 )
			events.ScheduleEvent(EVENT_NEXT_WAVE, 10000);
	}
	
	void DoWipeBeforeMarwyn(){
		DespawnDeque(activeAdds);
		DespawnDeque(marwynAdds);
		DespawnDeque(falricAdds);
		DespawnMob(uiFalric);
		uiFalric=0;
		DespawnMob(uiMarwyn);
		uiMarwyn=0;
		if(GetData(DATA_FALRIC_EVENT)==DONE)
			uiWaveCount = 5;
		else
			uiWaveCount = 0;
		wave_counter = 0;
		delayedCall = DELAYED_CALL_SPAWN_SYL;
	}
	
	void DespawnDeque(deque<uint64> &mobs){
		while(mobs.size()){
			DespawnMob(mobs[0]);
			mobs.pop_front();
		}
	}
	
	void DespawnMob(const uint64 &guid){
		Creature *c = instance->GetCreature(guid);
		if(c)
			c->DisappearAndDie();
	}
	
	void DoWipeOnLichKing(){
		ResetIceWalls();
		delayedCall = DELAYED_CALL_SPAWN_LICHKING;
	}
	
	///Activates a mob.
	void ActivateMob(Creature *c){
		c->AI()->DoAction(ACTION_ENTER_COMBAT);
	}
	
	void ActivateWaveFalric(){
		if( wave_counter == 5 ){
			Creature *add = instance->GetCreature( uiFalric );
			if( add != 0 )
				ActivateMob(add);
			wave_counter++;
			return;
		}else if( wave_counter > 5 )
			return;//Do nothing...
		else if( wave_counter == 0 ){
			Creature *add = instance->GetCreature( uiFalric );
			if( add != 0 ){
				add->MonsterYell( "Soldiers of Lordaeron, rise to meet your master's call!", LANG_UNIVERSAL, 0 );
				((ScriptedAI*)add->AI())->DoPlaySoundToSet( add, 16714 );
			}
		}
		
		int num_to_spawn = 4;
		if( wave_counter < 2 )
			num_to_spawn--;//3 mobs in 1st 2 waves.

		for( int counter = 0; counter < num_to_spawn && falricAdds.size() > 0; counter++ ){
			int mobID = rand() % falricAdds.size();
			uint64 mobGUID = falricAdds[mobID];
			falricAdds[mobID] = falricAdds[0];
			falricAdds.pop_front();
			activeAdds.push_back( mobGUID );

			Creature *add = instance->GetCreature( mobGUID );
			if( add != 0 ){
				ActivateMob(add);
			}
		}

		wave_counter++;
	}

	void ActivateWaveMarwyn(){
		if( wave_counter == 5 ){
			Creature *add = instance->GetCreature( uiMarwyn );
			if( add != 0 )
				ActivateMob(add);
			wave_counter++;
			return;
		}else if( wave_counter > 5 )
			return;//Do nothing...
		else if( wave_counter == 0 ){
			Creature *add = instance->GetCreature( uiMarwyn );
			if( add != 0 ){
				add->MonsterYell( "The master surveyed his kingdom and found it... Lacking. His judgement was swift and without mercy: DEATH TO ALL!", LANG_UNIVERSAL, 0 );
				((ScriptedAI*)add->AI())->DoPlaySoundToSet( add, 16738 );
			}
		}

		int num_to_spawn = 4;
		if( wave_counter < 2 )
			num_to_spawn--;//3 mobs in 1st 2 waves.

		for( int counter = 0; counter < num_to_spawn && marwynAdds.size() > 0; counter++ ){
			int mobID = rand() % marwynAdds.size();
			uint64 mobGUID = marwynAdds[mobID];
			marwynAdds[mobID] = marwynAdds[0];
			marwynAdds.pop_front();
			activeAdds.push_back( mobGUID );

			Creature *add = instance->GetCreature( mobGUID );
			if( add != 0 ){
				ActivateMob(add);
			}
		}

		wave_counter++;
	}
	
	void SpawnGeneral(){
		if( generalGUID == 0 ){
			Map::PlayerList const &PlayerList = instance->GetPlayers();
			if(PlayerList.isEmpty()){
				delayedCall = DELAYED_CALL_SPAWN_GENERAL;
				return;
			}
			Player *player = PlayerList.begin()->GetSource();
			if( player == 0 )
				return;
			Creature *mob = player->SummonCreature( NPC_GENERAL, POS_GENERAL, TEMPSUMMON_DEAD_DESPAWN, 0 );
			generalGUID = mob->GetGUID();
		}else
			printf("Error in TW_instance_halls_of_reflection.cpp: Attempted spawning General where generalGUID not NULL.\n");
	}
	
	///MANGOS CODE UNDER HERE
	void SpawnLichKing(){
		DebugPlayerSay("Spawning Lich King...");
		Map::PlayerList const &PlayerList = instance->GetPlayers();
		Player *player = PlayerList.begin()->GetSource();
		if(PlayerList.isEmpty()){
			delayedCall = DELAYED_CALL_SPAWN_LICHKING;
			return;
		}
		if( player == 0 )
			return;
		
		Creature *lichking, *sylvanas;
		if( lichkingGUID != 0 && (lichking = instance->GetCreature(lichkingGUID)) )
			lichking->RemoveFromWorld();
		if( sylvanas2GUID != 0 && (sylvanas = instance->GetCreature(sylvanas2GUID)) )
			sylvanas->RemoveFromWorld();
		
		sylvanas = player->SummonCreature( NPC_SYLVANAS2, LK_SPAWN_SYLVANAS_POS, TEMPSUMMON_MANUAL_DESPAWN, 0 );
		sylvanas2GUID = sylvanas->GetGUID();
		sylvanas->setActive(true);

		lichking = player->SummonCreature( NPC_LICHKING2, LK_SPAWN_LICHKING_POS, TEMPSUMMON_MANUAL_DESPAWN, 0 );
		lichkingGUID = lichking->GetGUID();
		lichking->setActive(true);

		sylvanas->AI()->AttackStart( lichking );
		sylvanas->CombatStart(lichking, true);
		lichking->CombatStart(sylvanas, true);
	}

	void DebugPlayerSay(const char *text){
		Map::PlayerList const &PlayerList = instance->GetPlayers();
		Player *player = PlayerList.begin()->GetSource();
		if(PlayerList.isEmpty()){
			delayedCall = DELAYED_CALL_SPAWN_LICHKING;
			return;
		}
		if( player == 0 )
			return;
		player->Say(text, LANG_UNIVERSAL);
	}
	
	void ResetIceWalls(){
// 		printf("ResetIceWalls\n");
		for( uint8 i = 0; i < 4; i++ ){
			GameObject *wall = instance->GetGameObject( icewallGUIDs[i] );
			if( wall == 0 )
				break;//ERROR :S
			wall->SetGoState( GO_STATE_READY );
			wall->SetPhaseMask( 2, true );
		}
	}
	
	//BEGIN LK-running code
	void GetLKNumbers( uint32 wave_num, uint32 &num_ghoul, uint32 &num_doctor, uint32 &num_abomination ){
		num_ghoul = num_doctor = num_abomination = 0;
		switch( wave_num ){
			case 1:
				num_ghoul = 3;
				num_doctor = 1;
				num_abomination = 0;
				break;
			case 2:
				num_ghoul = 5;
				num_doctor = 2;
				num_abomination = 1;
				break;
			case 3:
				num_ghoul = 7;
				num_doctor = 4;
				num_abomination = 2;
				break;
			case 4:
				num_ghoul = 8;
				num_doctor = 6;
				num_abomination = 4;
				break;
		}
	}

	
	void SummonLKWave( Creature *lichking, Creature *sylvanas, uint32 num_mobs, uint32 mobid, float activation_range = 0.0 ){
// 		printf("SummonLKWave\n");
		float fx, fy, fz;
		Position pos;
		lichking->GetPosition(&pos);
		for( uint8 i = 0; i < num_mobs; i++ ){
			lichking->GetRandomPoint(pos, 10.0f, fx, fy, fz);
			Creature *add = lichking->SummonCreature( mobid, fx, fy, fz, 0.0, TEMPSUMMON_DEAD_DESPAWN, 0 );
			add->setActive(true);
			uint32 activation_timer = (uint32) (500 + (i * activation_range) / num_mobs );
			((TW_mob_hor_lk_dummyAI*)add->AI())->Activate( activation_timer );
		}
	}

	void PhaseIceWall( uint32 wave_num ){
// 		printf("PhaseIceWall %u\n", wave_num);
		GameObject *wall = instance->GetGameObject( icewallGUIDs[wave_num-1] );
		if( wall != 0 )
			wall->SetPhaseMask( 1, true );
	}
	
	void BreakIceWall(){
// 		printf("BreakIceWall\n");
		bool done = false;
		for( uint8 i = 0; i < 4 && !done; i++ ){
			GameObject *wall = instance->GetGameObject( icewallGUIDs[i] );
			if( wall == 0 )
				break;//ERROR :S
			if( wall->GetGoState() == GO_STATE_READY ){
				done = true;
				DoUseDoorOrButton( icewallGUIDs[i] );
			}
		}
		SetData( DATA_LICHKING_EVENT, SPECIAL );
	}
	
	void SendLKWave( uint32 wave_num ){//Wave num goes from 1 to 4
// 		printf("SendLKWave %u\n", wave_num);
		if( wave_num == 0 || wave_num > 4 || wave_num <= LK_wave_counter )
			return;
		Creature *lichking = instance->GetCreature( lichkingGUID );
		if( lichking == 0 )
			return;
		Creature *sylvanas = instance->GetCreature( sylvanas2GUID );
		if( sylvanas == 0 )
			return;
// 		printf("\tsending wave...\n");
		
		///TODO: This might have to be tweaked.
		LK_wave_counter++;
		uint32 num_ghoul, num_abomination, num_doctor;
		GetLKNumbers( wave_num, num_ghoul, num_doctor, num_abomination );
		SummonLKWave( lichking, sylvanas, num_ghoul, NPC_GHOUL, wave_num * 5.0 * 1000 );
		SummonLKWave( lichking, sylvanas, num_doctor, NPC_DOCTOR, wave_num * 5.0 * 1000 );
		SummonLKWave( lichking, sylvanas, num_abomination, NPC_ABOMINATION, wave_num * 5.0 * 1000 );
		PhaseIceWall( wave_num );
	}
	//END LK-running code
    };

};

void AddSC_TW_instance_halls_of_reflection()
{
    new TW_instance_halls_of_reflection();
}
