/*
<--------------------------------------------------------------------------->
 - Developer(s): Ghostcrawler336
 - Complete: 100%
 - ScriptName: 'Faction / Race Changer' 
 - Comment: Untested
 - Updated - 8/7/2013 or 7/8/2013
<--------------------------------------------------------------------------->
*/
#include "ScriptPCH.h"

enum  defines
{
 faction_token = 29434, // Faction Change Token
 race_token = 29434 // Race Change Token
};

class npc_changer : public CreatureScript
{
	public:
		npc_changer() : CreatureScript("npc_changer"){}

		bool OnGossipHello(Player * pPlayer, Creature * pCreature)
		{
			
			
			pPlayer->ADD_GOSSIP_ITEM(4, "|TInterface/ICONS/Achievement_Arena_2v2_7:30|t Change My Race ", GOSSIP_SENDER_MAIN, 0);
		    pPlayer->ADD_GOSSIP_ITEM(4, "|TInterface/ICONS/Achievement_Arena_2v2_7:30|t Change My Faction", GOSSIP_SENDER_MAIN, 1);
			pPlayer->PlayerTalkClass->SendGossipMenu(9425, pCreature->GetGUID());
			return true;
		}

		bool OnGossipSelect(Player * Player, Creature * Creature, uint32 /*uiSender*/, uint32 uiAction)
		{
			if(!Player)
				return true;

			switch(uiAction)
			{
				case 0:
					if(Player->HasItemCount(race_token, 25))
					{
						Player->DestroyItemCount(race_token, 25, true, false);
						Player->SetAtLoginFlag(AT_LOGIN_CHANGE_RACE);
						Player->GetSession()->SendNotification("You need to relog, to change your race!");
						Player->PlayerTalkClass->SendCloseGossip();
					}
					else
					{
						Player->GetSession()->SendNotification("You need atleast one race change token!");
						Player->PlayerTalkClass->SendCloseGossip();
					}
					break;
				case 1:
					if(Player->HasItemCount(faction_token, 25))
					{
						Player->DestroyItemCount(faction_token, 25, true, false);
						Player->SetAtLoginFlag(AT_LOGIN_CHANGE_FACTION);
						Player->GetSession()->SendNotification("You need to relog, to change your faction!");
						Player->PlayerTalkClass->SendCloseGossip();
					}
					else
					{
						Player->GetSession()->SendNotification("You need atleast one faction change token!");
						Player->PlayerTalkClass->SendCloseGossip();
					}
					break;
			}
			return true;
		}

};

void AddSC_npc_changer()
{
	new npc_changer();
}