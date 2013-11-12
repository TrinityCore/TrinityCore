#include "ScriptMgr.h"
#include "Player.h"
#include "ScriptedCreature.h"

class dk_up : public CreatureScript
{
    public:

        dk_up(): CreatureScript("dk_up"){}

        bool OnGossipHello(Player* player, Creature* go) OVERRIDE
        {
            player->ADD_GOSSIP_ITEM(0, "Ir arriba", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+13);
			player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, go->GetGUID());
            return true;
        }

		bool OnGossipSelect(Player* player, Creature* go, uint32 sender, uint32 action) OVERRIDE
		{
			player->PlayerTalkClass->ClearMenus();
			switch(action)
			{
			case GOSSIP_ACTION_INFO_DEF+13:
				player->TeleportTo(609,2399.383057f,-5634.744141f,420.671052f,0.618091f);
			default:
				player->CLOSE_GOSSIP_MENU();
			}
			return true;
		}
};

void AddSC_dk_up()
{
    new dk_up();
}
