#include "precompiled.h"
#include "WorldPacket.h"

#define GOSSIP_FLIGHT "I need a ride"

bool GossipHello_npc_acherus_taxi(Player* pPlayer, Creature* pCreature)
{
pPlayer->SetTaxiCheater(true);

pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_FLIGHT, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
        pPlayer->SEND_GOSSIP_MENU(9978, pCreature->GetGUID());
    return true;
}

bool GossipSelect_npc_acherus_taxi(Player* pPlayer, Creature* pCreature, uint32 sender, uint32 action)
{
    if (action == GOSSIP_ACTION_INFO_DEF + 1)
    { 
       if (pPlayer->GetPositionZ() >=316)       
        {
        pPlayer->GetSession()->SendDoFlight(24446, 1053); 
        }else{
        pPlayer->GetSession()->SendDoFlight(24446, 1054);
        }

    }
    return true;
}

void AddSC_npc_acherus_taxi()
{
    Script *newscript;

newscript = new Script;
newscript->Name="npc_acherus_taxi";
newscript->pGossipHello = &GossipHello_npc_acherus_taxi;
newscript->pGossipSelect = &GossipSelect_npc_acherus_taxi;
newscript->RegisterSelf();
}
