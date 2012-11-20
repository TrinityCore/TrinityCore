/*
*	Custom gurubashi arena event by Dessus
*/

#include "ScriptPCH.h"


enum EncounterTypes{
	GURU_2VX	= 1,
	GURU_3VX	= 2,
	GURU_5VX	= 3,
	GURU_7VX	= 4
};

struct GuruAnnouncerMenus{
	std::string text;
	EncounterTypes encounterType;

};

static GuruAnnouncerMenus _messages[] = {
	{"You've chosen a battle against 2 Heroes! It's the easiest battle there so a reward will not be the best! Good Luck and Have Fun!", GURU_2VX},
	{"You've chosen a battle against 3 Heroes! Good Luck and Have Fun!", GURU_3VX},
	{"You've chosen a battle against 3 Heroes! Good Luck and Have Fun!", GURU_5VX},
	{"You've chosen a battle against 7 Heroes! It's the hardest battle there so a reward will be the best! Good Luck and Have Fun!", GURU_7VX}

};


class npc_guru_announcer : public CreatureScript
{
public:
    npc_guru_announcer() : CreatureScript("npc_guru_announcer") { }

    bool OnGossipHello(Player *player, Creature *_creature)
    {
        
        return true;
    }


    
    bool OnGossipSelect(Player *player, Creature *_creature, uint32 sender, uint32 uiAction)
    {
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