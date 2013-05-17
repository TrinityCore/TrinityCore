/*
*	Custom gurubashi arena event by Dessus
*/

#include "ScriptPCH.h"
#include "Group.h"


enum Heroes{
	NPC_GURU_SHAMAN = 500500,
};

enum EncounterTypes{
	GURU_2VX	= 1,
	GURU_3VX	= 2,
	GURU_5VX	= 3,
	GURU_7VX	= 4
};

enum AnnouncerSpells{
	SPELL_ANNOUNCER_AURA1				= 72521,		// SM low
	SPELL_ANNOUNCER_AURA2				= 72523,		// SM high
	SPELL_ANNOUNCER_SUMMONING_OBJECT	= 62019,		// pink obj
	SPELL_ANNOUNCER_SOULGUARD_CHANNEL	= 68797,



};

enum SummonerSpells{
	SPELL_SUMMONER_SUMMON_SKELETONS		= 58071,		// channel summon skeletons


};

enum GuruActions{
	GURU_ACTION_GO_DOWN			= 1,	// go down
	GURU_ACTION_2VX				= 10,	// 2VX battle selected
	GURU_ACTION_3VX				= 11,	// 3VX battle selected
	GURU_ACTION_5VX				= 12,	// 5VX battle selected
	GURU_ACTION_7VX				= 13,	// 7VX battle selected


	GURU_GOTO_START_POSITION	= 20,	// start battle position
	GURU_ANNOUNCER_SAY			= 21,	// say battle
	GURU_SET_ORIENTATION		= 22,	// set oriantation 

	GURU_SUMMON_1				= 23,	// set rune 1
	GURU_SUMMON_2				= 24,	// set rune 2
	GURU_SUMMON_3				= 25,	// summon channeling, object
	GURU_SUMMON_4				= 26,	// last actions before summoning
	GURU_SUMMON_CREATURES		= 27,	// summon creatures

	GURU_ACTION_REWARD			= 28,	// averyone was killed ->reward action
};



// texts
struct GuruAnnouncerTexts{
	std::string text;
	uint32 nextTextId;
	uint32 delay;

};
static GuruAnnouncerTexts texts[] = {
	/*0*/ {"Well, I'm glad to see here some heroes able to fight with my apprentices!", 1, 5000},
	/*1*/ {"I think, You never saw me before. I tell you something about me ... ", 2,  5000},
	/*2*/ {"I'm from a small isle from the Great Sea and my father and I have there the best barracks on the whole World.", 3, 8000},
	/*3*/ {"We train our apprentices since the age of the Old Naxxramas for battles like here.", 4, 7000},
	/*4*/ {"We specialize for 4 types of battles. These battles have only specified count of our apprentices and we fight against more opponents.", 5, 8000},
	/*5*/ {"If you defeat my apprentices you'll get very good items. A count and a quality of these items depends only on the count of my apprentices you've defeated. ", 99, 5000},
	/*6*/ {"Ok, Let's Begin!"},
	/*7*/ {"Oou, that's hard, I need mor runes ... I ho-ho-pe"},
	/*8*/ {"Yeah! Slay them all my apprentices!"},
	/*9*/ {"Nooooo!"},
	/*10*/ {"Ok, you won! My vassal gaves you your reward!"},
};

// gossip menu texts
struct GuruAnnouncerMenus{
	std::string text;
	uint32 action;

};
static GuruAnnouncerMenus gossip[] = {
	{"Summon 2 apprentices!", GURU_ACTION_2VX},
	{"Summon 3 apprentices!", GURU_ACTION_3VX},
	{"Summon 5 apprentices!", GURU_ACTION_5VX},
	{"Summon 7 apprentices!", GURU_ACTION_7VX}

};

struct SummonPositions{
	float x;
	float y;
	float z;
	float o;
};

static SummonPositions summonPosition[] = {
	{-13198.40f, 296.20f, 22.0f, 4.20f},
	{-13189.40f, 291.20f, 22.0f, 4.20f},
	{-13185.40f, 289.20f, 22.0f, 4.20f},
	{-13203.40f, 298.20f, 22.0f, 4.20f},
	{-13180.40f, 285.20f, 22.0f, 4.20f},
	{-13207.40f, 300.20f, 22.0f, 4.20f},
	{-13213.40f, 301.20f, 22.0f, 4.20f},
};



enum MovementId{
	MOVEMENT_1 = 1,
};
// move for announcer
struct AnnouncerMovement{
	uint32 id;
	float x;
	float y;
	float z;
	uint32 actions_delay;	// delay between next action
};

static AnnouncerMovement AnnouncerPoints[] = {
	{MOVEMENT_1, -13193.75, 294.0f, 21.86f}, // battle start position 

};



class npc_guru_announcer : public CreatureScript
{
public:
    npc_guru_announcer() : CreatureScript("npc_guru_announcer") { }

	CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_guru_announcerAI (pCreature);
    }

    struct npc_guru_announcerAI : public ScriptedAI
    {
        npc_guru_announcerAI(Creature *c) : ScriptedAI(c){}

		uint32 timer;
		uint32 path_count;
		uint32 path;
		bool active;
		uint32 nextTextId;
		uint32 nextAction;
		uint32 orientation;
		uint32 phase;
		int summonsCount;
		uint32 aliveCount;
		bool fighting;
		uint32 timerState;		
		Creature* summons[7];
		bool creaturesState[7]; // true- alive, false - dead
		bool done_2vx;
		bool done_3vx;
		bool done_5vx;
		bool done_7vx;

		void Reset(){
			timer = 0;	
			path_count = 1;
			path = 0;
			active = false;
			nextTextId = 0;
			nextAction = GURU_GOTO_START_POSITION;
			orientation = me->GetOrientation();
			phase = 0;
			summonsCount = 0;
			aliveCount = 0;
			fighting = false;
			timerState = 500;
			done_2vx = false;
			done_3vx = false;
			done_5vx = false;
			done_7vx = false;

		}

		void EnterCombat(Unit* who){}
		uint32 GetData(uint32 dataId){
			switch (dataId){
				case 1:
					return phase;
					break;
				case GURU_ACTION_2VX:
					return done_2vx;
					break;
				case GURU_ACTION_3VX:
					return done_3vx;
					break;
				case GURU_ACTION_5VX:
					return done_5vx;
					break;
				case GURU_ACTION_7VX:
					return done_7vx;
					break;
				default:
					return 0;		
			}
		}
		void SetData(uint32 uiId, uint32 uiValue)
        {            
			if(uiId == 1) // battle start 
			{
				switch (uiValue){
					case GURU_ACTION_GO_DOWN:
						me->SetWalk(true);
						active = true;
						timer = 50;					
						break;
				}
			}
			else if(uiId == 2){ // set summons count
				switch (uiValue){
					case GURU_ACTION_2VX:
						summonsCount = 2;
						break;
					case GURU_ACTION_3VX:
						summonsCount = 3;
						break;
					case GURU_ACTION_5VX:
						summonsCount = 5;
						break;
					case GURU_ACTION_7VX:
						summonsCount = 7;
						break;
				}

				// pre-summon event start 
				nextAction = GURU_SUMMON_1;
				timer = 2000;
			}
			
        }

		void UpdateAI(const uint32 uiDiff)
        {
			ScriptedAI::UpdateAI(uiDiff);

			// check battle state
			if(timerState <= uiDiff){
				for(int i = 1; i <= summonsCount; i++){
					if(summons[i-1]->GetHealth() < 1){
						if(creaturesState[i-1]){
							aliveCount -= 1;
							me->MonsterSay(texts[9].text.c_str() ,LANG_UNIVERSAL, 0);
							creaturesState[i-1] = false;
						}
					}									
				}
				if(aliveCount == 0){
					fighting = false;
					timer = 500;
					nextAction = GURU_ACTION_REWARD;
				}
				timerState = 500;
			}
			else
				if(fighting)
					timerState -= uiDiff;

			if(timer == 0)
				return;


			if (timer <= uiDiff && active)
                {
					switch (nextAction){					
						case GURU_GOTO_START_POSITION:
							me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
							me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
							me->GetMotionMaster()->MovePoint(AnnouncerPoints[0].id, AnnouncerPoints[0].x, AnnouncerPoints[0].y, AnnouncerPoints[0].z);
							timer = 2000;
							nextAction = GURU_ANNOUNCER_SAY;
							break;

						case GURU_ANNOUNCER_SAY:
							if(nextTextId == 99){
								me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);		
								me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
								phase = 1;
								me->SetOrientation(4.20f);
								timer = 0;
							}
							else{
								me->MonsterSay(texts[nextTextId].text.c_str() ,LANG_UNIVERSAL, 0);
								timer = texts[nextTextId].delay;
								nextTextId = texts[nextTextId].nextTextId;	
							}
													
							break;

						case GURU_SET_ORIENTATION:
							me->SetOrientation(orientation);
							me->SendMovementFlagUpdate();
							if(phase == 1){
								timer = 0;
							}
							break;

						case GURU_SUMMON_1:
							me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
							me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
							me->AddAura(SPELL_ANNOUNCER_AURA1, me);
							me->MonsterYell(texts[6].text.c_str(), LANG_UNIVERSAL, 0);
							timer = 4000;
							nextAction = GURU_SUMMON_2;
							break;

						case GURU_SUMMON_2:
							me->MonsterYell(texts[7].text.c_str(), LANG_UNIVERSAL, 0);
							me->AddAura(SPELL_ANNOUNCER_AURA2, me);
							timer = 4000;
							nextAction = GURU_SUMMON_3;
							break;

						case GURU_SUMMON_3:
							DoCast(SPELL_ANNOUNCER_SUMMONING_OBJECT);
							DoCast(SPELL_ANNOUNCER_SOULGUARD_CHANNEL);
							timer = 12000;
							nextAction = GURU_SUMMON_4;
							break;

						case GURU_SUMMON_4:
							me->RemoveAura(SPELL_ANNOUNCER_AURA2);
							me->RemoveAura(SPELL_ANNOUNCER_AURA1);							
							DoCast(71935);

							me->MonsterYell(texts[8].text.c_str(), LANG_UNIVERSAL, 0);
							timer = 10;
							nextAction = GURU_SUMMON_CREATURES;
							break;

						case GURU_SUMMON_CREATURES:
							switch (summonsCount){
							case 2:
								aliveCount = 2;
								for(int i = 1; i <= 2; i++){
									summons[i-1] = me->SummonCreature(NPC_GURU_SHAMAN, summonPosition[i-1].x, summonPosition[i-1].y, summonPosition[i-1].z, summonPosition[i-1].o, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 660000);
									summons[i-1]->SetOwnerGUID(me->GetGUID());
									summons[i-1]->AI()->AttackStart(me->SelectNearestPlayer(100));										
								}
								break;							
							}
							fighting = true;
							timer = 0;
							nextAction = GURU_SUMMON_CREATURES;
							
							for(int i = 1; i <= 7; i++){
								creaturesState[i-1] = true;
							}
							break;		

						case GURU_ACTION_REWARD:
							me->MonsterYell(texts[10].text.c_str(), LANG_UNIVERSAL, 0);							
							switch(summonsCount){
								case 2:
									done_2vx = true;
									break;
								case 3:
									done_3vx = true;
									break;
								case 5:
									done_5vx = true;
									break;
								case 7:
									done_7vx = true;
									break;
							}
							me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);		
							me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
							timer = 0;	
							path_count = 1;
							path = 0;
							active = false;
							nextTextId = 0;
							nextAction = GURU_GOTO_START_POSITION;
							orientation = me->GetOrientation();
							phase = 1;
							summonsCount = 0;
							aliveCount = 0;
							fighting = false;
							timerState = 500;

							break;
					}
					
                }
                else
                    timer -= uiDiff;

		}
	};
	
    bool OnGossipSelect(Player *player, Creature *_creature, uint32 sender, uint32 uiAction)
    {
			player->PlayerTalkClass->ClearMenus();
			if(uiAction == 1)	// main menu
			{
				
				switch (sender){
				case 1:{
					int BattleTypes = 4;
					
					// select count of heroes
					int len = BattleTypes;
					for(int i = 0; i < len; i++){
						player->ADD_GOSSIP_ITEM(7, gossip[i].text, gossip[i].action, 2);
					}
					player->SEND_GOSSIP_MENU(60001, _creature->GetGUID());
					break;   
				}
				case 2:{
					player->CLOSE_GOSSIP_MENU();
					break;	   
				}
				case 3:{
					_creature->AI()->SetData(1, GURU_ACTION_GO_DOWN);
					player->CLOSE_GOSSIP_MENU();
					break;	   
				}
				}
			return true;
		}
		else	// select count of heroes ...
		{			
			switch (sender){
				case GURU_ACTION_2VX:{
					_creature->AI()->SetData(2, GURU_ACTION_2VX);
					player->CLOSE_GOSSIP_MENU();
					break;				 
				}
			}
			return true;

		}
	}

	bool CheckEventState(){
		return true;
	
	}
	
	 bool OnGossipHello(Player *player, Creature *_creature)
    {
		Group* group = player->GetGroup();

		if(player->isInCombat())
        {
            _creature->MonsterWhisper("You are in a combat!", player->GetGUID());
			return true;
        }
        
		if(group){
			if(!group->IsLeader(player->GetGUID())){
				_creature->MonsterWhisper("You are not a party leader!", player->GetGUID());	
				return true;
			}
		}
		int phase = _creature->AI()->GetData(1);
		if(phase == 0){
			player->ADD_GOSSIP_ITEM(7, "I want to start a battle!", 3, 1);
		}
		else if(phase == 1){
			int BattleTypes = 4;

			for(int i = 0; i < BattleTypes; i++){
				if(!_creature->AI()->GetData(gossip[i].action))
					player->ADD_GOSSIP_ITEM(7, gossip[i].text, gossip[i].action, 2);
			}
		}
		
		player->ADD_GOSSIP_ITEM(7, "No, I do not want to start a battle yet!", 2, 1);
        player->SEND_GOSSIP_MENU(60000, _creature->GetGUID());
        return true;
    }

 
};

class npc_guru_shaman : public CreatureScript
{
public:
    npc_guru_shaman() : CreatureScript("npc_guru_shaman") { }
	
	CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_guru_shamanAI (pCreature);
    }

    struct npc_guru_shamanAI : public ScriptedAI
    {
        npc_guru_shamanAI(Creature *c) : ScriptedAI(c){}
			
		uint32 announcerGuid;
		void EnterCombat(Unit* who){
			
		}
		void SetData(uint32 uiId, uint32 uiValue)
        {   
			switch(uiId){
			case 1:
				
				break;
			}
		}

		void JustDied(Unit* /*killer*/)
        {
				
        }


	};
	
};

class npc_guru_hunter : public CreatureScript
{
public:
    npc_guru_hunter() : CreatureScript("npc_guru_hunter") { }

    bool OnGossipHello(Player *player, Creature *_creature)
    {
         
        return true;
    }


    
    bool OnGossipSelect(Player *player, Creature *_creature, uint32 sender, uint32 uiAction)
    {
        return true;
    }
};

class npc_guru_priest : public CreatureScript
{
public:
    npc_guru_priest() : CreatureScript("npc_guru_priest") { }

    bool OnGossipHello(Player *player, Creature *_creature)
    {
         
        return true;
    }


    
    bool OnGossipSelect(Player *player, Creature *_creature, uint32 sender, uint32 uiAction)
    {
        return true;
    }
};

class npc_guru_warrior : public CreatureScript
{
public:
    npc_guru_warrior() : CreatureScript("npc_guru_warrior") { }

    bool OnGossipHello(Player *player, Creature *_creature)
    {
         
        return true;
    }


    
    bool OnGossipSelect(Player *player, Creature *_creature, uint32 sender, uint32 uiAction)
    {
        return true;
    }
};

class npc_guru_mage : public CreatureScript
{
public:
    npc_guru_mage() : CreatureScript("npc_guru_mage") { }

    bool OnGossipHello(Player *player, Creature *_creature)
    {
         
        return true;
    }


    
    bool OnGossipSelect(Player *player, Creature *_creature, uint32 sender, uint32 uiAction)
    {
        return true;
    }
};

class npc_guru_warlock : public CreatureScript
{
public:
    npc_guru_warlock() : CreatureScript("npc_guru_warlock") { }

    bool OnGossipHello(Player *player, Creature *_creature)
    {
         
        return true;
    }


    
    bool OnGossipSelect(Player *player, Creature *_creature, uint32 sender, uint32 uiAction)
    {
        return true;
    }
};


class npc_guru_paladin : public CreatureScript
{
public:
    npc_guru_paladin() : CreatureScript("npc_guru_paladin") { }

    bool OnGossipHello(Player *player, Creature *_creature)
    {
         
        return true;
    }


    
    bool OnGossipSelect(Player *player, Creature *_creature, uint32 sender, uint32 uiAction)
    {
        return true;
    }

};

class npc_guru_thief : public CreatureScript
{
public:
    npc_guru_thief() : CreatureScript("npc_guru_thief") { }

    bool OnGossipHello(Player *player, Creature *_creature)
    {
         
        return true;
    }


    
    bool OnGossipSelect(Player *player, Creature *_creature, uint32 sender, uint32 uiAction)
    {
        return true;
    }
};


void AddSC_guru_event()
{
    new npc_guru_announcer();
	new npc_guru_shaman();
	new npc_guru_hunter();
	new npc_guru_priest();
	new npc_guru_warrior();
	new npc_guru_mage();
	new npc_guru_warlock();
	new npc_guru_paladin();
	new npc_guru_thief();
}
