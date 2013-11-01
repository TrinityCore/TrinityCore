#include "ScriptMgr.h"
#include "Player.h"
#include "ScriptedCreature.h"

class h_o_t_portal : public CreatureScript
{
    public:

        h_o_t_portal(): CreatureScript("h_o_t_portal"){}

        bool OnGossipHello(Player* player, Creature* go) OVERRIDE
        {
            player->ADD_GOSSIP_ITEM(0, "¡Estoy listo para ir a derrotar al verdadero mal!", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+13);
			player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, go->GetGUID());
            return true;
        }

		bool OnGossipSelect(Player* player, Creature* go, uint32 sender, uint32 action) OVERRIDE
		{
			player->PlayerTalkClass->ClearMenus();
			switch(action)
			{
			case GOSSIP_ACTION_INFO_DEF+13:
				player->TeleportTo(940,3957.755859f,286.416748f,14.283696f,0.0f);
			default:
				player->CLOSE_GOSSIP_MENU();
			}
			return true;
		}
};

void AddSC_h_o_t_portal()
{
    new h_o_t_portal();
}
