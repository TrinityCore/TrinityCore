/*
*	Custom gurubashi arena event by Dessus
*/

#include "ScriptPCH.h"
#include "Group.h"

enum guruQuests{
	GURU_QUEST_2VX = 100001,
	GURU_QUEST_3VX = 100002,
	GURU_QUEST_5VX = 100003,
	GURU_QUEST_7VX = 100004
};

enum EncounterTypes{
	GURU_2VX	= 1,
	GURU_3VX	= 2,
	GURU_5VX	= 3,
	GURU_7VX	= 4
};

enum GuruActions{
	GURU_ACTION_2VX		= 10,	// 2VX battle start
	GURU_ACTION_3VX		= 11,	// 3VX battle start
	GURU_ACTION_5VX		= 12,	// 5VX battle start
	GURU_ACTION_7VX		= 13	// 7VX battle start
};



// yells
struct GuruAnnouncerYells{
	std::string text;
	EncounterTypes encounterType;

};
static GuruAnnouncerYells yells[] = {
	{"You've chosen a battle against 2 Heroes! It's the easiest battle there so a reward will not be the best! Good Luck and Have Fun!", GURU_2VX},
	{"You've chosen a battle against 3 Heroes! Good Luck and Have Fun!", GURU_3VX},
	{"You've chosen a battle against 3 Heroes! Good Luck and Have Fun!", GURU_5VX},
	{"You've chosen a battle against 7 Heroes! It's the hardest battle there so a reward will be the best! Good Luck and Have Fun!", GURU_7VX}

};

// gossip menu texts
struct GuruAnnouncerMenus{
	std::string text;
	GuruActions action;

};
static GuruAnnouncerMenus gossip[] = {
	{"Summon 2 heroes!", GURU_ACTION_2VX},
	{"Summon 3 heroes!", GURU_ACTION_3VX},
	{"Summon 5 heroes!", GURU_ACTION_5VX},
	{"Summon 7 heroes!", GURU_ACTION_7VX}

};


class npc_guru_announcer : public CreatureScript
{
public:
    npc_guru_announcer() : CreatureScript("npc_guru_announcer") { }

	bool addGossipMenu(Player* player, Creature* creature){


		Group* group = player->GetGroup();
		

		if(player->isInCombat())
        {
            player->CLOSE_GOSSIP_MENU();
            creature->MonsterWhisper("You are in a combat!", player->GetGUID());
			return false;
        }
        else
        {
			if(group){
				if(!group->IsLeader(player->GetGUID())){
					creature->MonsterWhisper("You are not a party leader!", player->GetGUID());	
					player->CLOSE_GOSSIP_MENU();
					return false;
				}

			}
			if(CheckEventState()){
				player->ADD_GOSSIP_ITEM(7, "Yes! I Want to start the battle!", 1, 1);
			}
        }
        player->SEND_GOSSIP_MENU(60000, creature->GetGUID());	
		return true;
	}




    bool OnGossipHello(Player *player, Creature *_creature)
    {
        addGossipMenu(player, _creature);
        return true;
    }

    bool OnGossipSelect(Player *player, Creature *_creature, uint32 sender, uint32 uiAction)
    {
		if(uiAction == 1){
			// select count of heroes
			int len = sizeof(gossip) / sizeof(int);
			for(int i = 0; i < len; i++){
				player->ADD_GOSSIP_ITEM(7, gossip[i].text, gossip[i].action, 2);
			}
		}
        return true;
    }


	bool CheckEventState(){
		return true;
	
	}

};

class npc_guru_shaman : public CreatureScript
{
public:
    npc_guru_shaman() : CreatureScript("npc_guru_shaman") { }

    bool OnGossipHello(Player *player, Creature *_creature)
    {
         
        return true;
    }


    
    bool OnGossipSelect(Player *player, Creature *_creature, uint32 sender, uint32 uiAction)
    {
        return true;
    }
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

class npc_guru_controller : public CreatureScript
{
public:
    npc_guru_controller() : CreatureScript("npc_guru_controller") { }

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
	new npc_guru_controller();
}