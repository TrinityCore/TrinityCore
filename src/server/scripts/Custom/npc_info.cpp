/*
  _____                        ____               
 |  ___| __ ___ _______ _ __  / ___|___  _ __ ___ 
 | |_ | '__/ _ \_  / _ \ '_ \| |   / _ \| '__/ _ \
 |  _|| | | (_) / /  __/ | | | |__| (_) | | |  __/
 |_|  |_|  \___/___\___|_| |_|\____\___/|_|  \___|
	 Lightning speed and strength
		 conjured directly from the depths of logic!   
			Infusion-WoW 2011 - 2013 (C)
<--------------------------------------------------------------------------->
 - Developer(s): Ghostcrawler336
 - Complete: %100
 - ScriptName: 'Ingame Support NPC(npc_info)' 
 - Comment: N/A
<--------------------------------------------------------------------------->
*/
#include "ScriptPCH.h"

class npc_info : public CreatureScript
{
	public:
		npc_info() : CreatureScript("npc_info")
		{
		}

		bool OnGossipHello(Player * pPlayer, Creature * pCreature)
		{
			pPlayer->ADD_GOSSIP_ITEM(4, "WoW-Smash Introduction.", GOSSIP_SENDER_MAIN, 0);
			pPlayer->ADD_GOSSIP_ITEM(4, "How do I make a ticket?", GOSSIP_SENDER_MAIN, 1);
			pPlayer->ADD_GOSSIP_ITEM(4, "How do I gear up?", GOSSIP_SENDER_MAIN, 2);
			pPlayer->ADD_GOSSIP_ITEM(0, "Bye...", GOSSIP_SENDER_MAIN, 3);
			pPlayer->PlayerTalkClass->SendGossipMenu(9425, pCreature->GetGUID());
			return true;
		}

		bool OnGossipSelect(Player * Player, Creature * Creature, uint32 /*uiSender*/, uint32 uiAction)
		{
			if(!Player)
				return true;
			
			switch(uiAction)
			{
				case 0: // This case will send the support message for "How Do I get Gold?"
					{
						ChatHandler(Player->GetSession()).PSendSysMessage("Welcome to the world of WoW-Smash!We are glad to introduce you the new reworked server which was made since 2009. Generally server is based on PvP including some cool features which you are going to experience while you are playing.", Player->GetName());
						Player->PlayerTalkClass->SendCloseGossip();
					}break;
				case 1: // This case will send the support message for "How Do I Make A Ticket?
					{

						ChatHandler(Player->GetSession()).PSendSysMessage("Don't be shy to write a ticket to our Gm's they are aways ready to answer you. To start writing a ticket just click on the red questinmark in the bottom. ", Player->GetName());
						Player->PlayerTalkClass->SendCloseGossip();
					}break;
				case 2: // This case will send the support message for "How Do I Gear Up?"
					{
						ChatHandler(Player->GetSession()).PSendSysMessage("Actually to gear up it's pretty easy you just need to farm honor,badges and arena rating depends on what you want to get.", Player->GetName());
						Player->PlayerTalkClass->SendCloseGossip();
					}break;
				case 3:
					{
						Player->PlayerTalkClass->SendCloseGossip();
					}break;
			}
			return true;
		}

};

void AddSC_npc_info()
{
	new npc_info();
}