/*
Copyright (C) 2019 HeronCore
*
*
Completed:0%
*/

#include "Player.h"
#include "Creature.h"
#include "ScriptedGossip.h"

class npc_lady_jaina_proudmoore_120590 : public CreatureScript
{
public:
	npc_lady_jaina_proudmoore_120590() : CreatureScript("npc_lady_jaina_proudmoore_120590") { }

	bool OnGossipHello(Player* player, Creature* creature) override
	{
		if (creature->IsQuestGiver())
			player->PrepareQuestMenu(creature->GetGUID());
		AddGossipItemFor(player, GOSSIP_ICON_CHAT, "I am ready to set sail!", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);
		SendGossipMenuFor(player, player->GetGossipTextId(creature), creature->GetGUID());
		return true;
	}
	
	bool OnGossipSelect(Player* player, Creature* creature, uint32, uint32 action) override
	{
		player->PlayerTalkClass->ClearMenus();
		switch (action)
		{
		case GOSSIP_ACTION_INFO_DEF:
			player->KilledMonsterCredit(120590); //KillCredit
			player->TeleportTo(1643, 727.69f, -446.35f, 15.06f, 1.93f);
			CloseGossipMenuFor(player);
			break;
		}
		return true;
	}
};

void AddSC_zone_tiragarde_sound()
{
	new npc_lady_jaina_proudmoore_120590();
};
