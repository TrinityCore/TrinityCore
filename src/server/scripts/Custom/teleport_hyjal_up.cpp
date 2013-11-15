#include "ScriptMgr.h"
#include "Player.h"

class teleport_hyjal_up : public GameObjectScript
{
    public:

        teleport_hyjal_up(): GameObjectScript("teleport_hyjal_up"){}

        bool OnGossipHello(Player* player, GameObject* go) OVERRIDE
        {
            player->ADD_GOSSIP_ITEM(0, "volver al saliente de relampagos", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+13);
			player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, go->GetGUID());
            return true;
        }

		bool OnGossipSelect(Player* player, GameObject* go, uint32 sender, uint32 action) OVERRIDE
		{
			player->PlayerTalkClass->ClearMenus();
			switch(action)
			{
			case GOSSIP_ACTION_INFO_DEF+13:
				player->TeleportTo(1,5039.843750f,-2048.064453f,1367.360112f,5.533869f);
			default:
				player->CLOSE_GOSSIP_MENU();
			}
			return true;
		}
};

void AddSC_teleport_hyjal_up()
{
    new teleport_hyjal_up();
}