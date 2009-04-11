#include "precompiled.h"
#include "WorldPacket.h"

#define GOSSIP_FLIGHT "I need a ride"

bool GossipHello_npc_acherus_taxi(Player *player, Creature *_Creature)
{
player->SetTaxiCheater(true);

player->ADD_GOSSIP_ITEM(0, GOSSIP_FLIGHT, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
        player->SEND_GOSSIP_MENU(9978,_Creature->GetGUID());
    return true;
}

bool GossipSelect_npc_acherus_taxi(Player *player, Creature *_Creature, uint32 sender, uint32 action )
{
    if (action == GOSSIP_ACTION_INFO_DEF + 1)
    { 
       if (player->GetPositionZ() >=316)       
        {
        player->GetSession()->SendDoFlight(24446, 1053); 
        }else{
        player->GetSession()->SendDoFlight(24446, 1054);
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
