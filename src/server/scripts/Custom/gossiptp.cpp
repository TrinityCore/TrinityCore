/*
*  EXAMPLE OF NPC GOSSIP //NPC闲聊示例
* 
*/

#include "ScriptedGossip.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"

class npc_gossip_holly_dew : public CreatureScript
{
public:
    npc_gossip_holly_dew() : CreatureScript("npc_gossip_holly_dew ") { }

    bool OnGossipHello(Player* player, Creature* creature) //override
    {
        
        //AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Ny'alotha, the walking City", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 0);
        AddGossipItemFor(player, GossipOptionNpc::Vendor, "Ny'alotha, the walking City", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 0);
        //AddGossipItemFor(player, GOSSIP_ICON_CHAT, "The Ruined Sanctum", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
        AddGossipItemFor(player, GossipOptionNpc::Vendor, "The Ruined Sanctum", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
        //AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Main City StormWind", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
        AddGossipItemFor(player, GossipOptionNpc::Vendor, "Main City StormWind", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);

        SendGossipMenuFor(player, 34711, creature->GetGUID());

        player->PrepareQuestMenu(creature->GetGUID());

        return true;
    }

    bool OnGossipSelect(Player* player, Creature* /*creature*/ , uint32 /*sender*/ , uint32 action) //override
    {
        if (action == GOSSIP_ACTION_INFO_DEF + 0)
        {
            player->TeleportTo(2217, -17.1430f, -49.4510f, -251.0879f, 3.0393f); // Ny'alotha, the walking City  MAP/ X"f" / Y"f" / Z"f" / Orient"f"

        }
        if (action == GOSSIP_ACTION_INFO_DEF + 1)// 2
        {
            player->TeleportTo(1220, -219.274f, 5601.44f, 61.1099f, 2.9442f); // Legion Saturn

        }
        if (action == GOSSIP_ACTION_INFO_DEF + 2)//3
        {
            player->TeleportTo(1519, -8833.07f, 622.778f, 93.9317f, 1.06194f); // 

        }

        return true;
    }
};

void AddSC_gossiptp()
{
    new npc_gossip_holly_dew();
}
