#include "precompiled.h"
#include "WorldPacket.h"

#define GOSSIP_UP      "My Lord, I must go to the upper floor of the temple."
#define GOSSIP_DOWN    "I would like to take a flight to the ground, Lord Afrasastrasz."
#define GOSSIP_MIDDLE  "Can you spare a drake to travel to Lord Afrasastrasz, in the middle of the temple?"
#define GOSSIP_TOP     "Please, Let me take one of these dragons to the top floor of the temple."
#define GOSSIP_BOTTOM  "Yes, Please. I would like to return to the ground floor of the temple."
#define GOSSIP_ONEDOWN "I would like to see Lord Afrasastrasz, in the middle of the temple."

bool GossipHello_npc_wyrmresttempel_middle_taxi(Player* pPlayer, Creature* pCreature)
{
pPlayer->SetTaxiCheater(true);

pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_UP, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_DOWN, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
        pPlayer->SEND_GOSSIP_MENU(12887, pCreature->GetGUID()); 
        
    return true;
}

bool GossipSelect_npc_wyrmresttempel_middle_taxi(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction)
{
    if (uiAction == GOSSIP_ACTION_INFO_DEF + 1)
    {          
        pPlayer->GetSession()->SendDoFlight(6376, 881);
    }
    

    if (uiAction == GOSSIP_ACTION_INFO_DEF + 2)
    {
      pPlayer->GetSession()->SendDoFlight(6376, 882);

    }
return true;
}

bool GossipHello_npc_wyrmresttempel_bottom_taxi(Player* pPlayer, Creature* pCreature)
{
pPlayer->SetTaxiCheater(true);

pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TOP, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 4);
pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_MIDDLE, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
        pPlayer->SEND_GOSSIP_MENU(12713, pCreature->GetGUID());
        
    return true;
}



bool GossipSelect_npc_wyrmresttempel_bottom_taxi(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction)
{
    if (uiAction == GOSSIP_ACTION_INFO_DEF + 4)
    {         
        pPlayer->GetSession()->SendDoFlight(6376, 878);
    }
    

    if (uiAction == GOSSIP_ACTION_INFO_DEF + 3)
    {
      pPlayer->GetSession()->SendDoFlight(6376, 883);

    }
return true;
}

bool GossipHello_npc_wyrmresttempel_top_taxi(Player* pPlayer, Creature* pCreature)
{
pPlayer->SetTaxiCheater(true);

pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_BOTTOM, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 5);
pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ONEDOWN, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 6);
        pPlayer->SEND_GOSSIP_MENU(12714, pCreature->GetGUID());

    return true;
}

bool GossipSelect_npc_wyrmresttempel_top_taxi(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction)
{
    if (uiAction == GOSSIP_ACTION_INFO_DEF + 5)
    {      
        pPlayer->GetSession()->SendDoFlight(6376, 879);
    }

    if (uiAction == GOSSIP_ACTION_INFO_DEF + 6)

    {
      pPlayer->GetSession()->SendDoFlight(6376, 880);

    }
return true;
}

void AddSC_npc_wyrmresttempel_taxi()
{
    Script *newscript;

newscript = new Script;
newscript->Name="npc_wyrmresttempelmiddle_taxi";
newscript->pGossipHello = &GossipHello_npc_wyrmresttempel_middle_taxi;
newscript->pGossipSelect = &GossipSelect_npc_wyrmresttempel_middle_taxi;
newscript->RegisterSelf();

newscript = new Script;
newscript->Name="npc_wyrmresttempelbottom_taxi";
newscript->pGossipHello = &GossipHello_npc_wyrmresttempel_bottom_taxi;
newscript->pGossipSelect = &GossipSelect_npc_wyrmresttempel_bottom_taxi;
newscript->RegisterSelf();

newscript = new Script;
newscript->Name="npc_wyrmresttempeltop_taxi";
newscript->pGossipHello = &GossipHello_npc_wyrmresttempel_top_taxi;
newscript->pGossipSelect = &GossipSelect_npc_wyrmresttempel_top_taxi;
newscript->RegisterSelf();

}
