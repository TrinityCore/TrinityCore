#include "ScriptMgr.h"
#include "Player.h"

class dk_down : public GameObjectScript
{
    public:

        dk_down(): GameObjectScript("dk_down"){}

        bool OnGossipHello(Player* player, GameObject* go) OVERRIDE
        {
            player->ADD_GOSSIP_ITEM(0, "Ir abajo", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+13);
			player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, go->GetGUID());
            return true;
        }

		bool OnGossipSelect(Player* player, GameObject* go, uint32 sender, uint32 action) OVERRIDE
		{
			player->PlayerTalkClass->ClearMenus();
			switch(action)
			{
			case GOSSIP_ACTION_INFO_DEF+13:
				player->TeleportTo(609,2399.383057f,-5634.744141f,377.020997f,0.618091f);
			default:
				player->CLOSE_GOSSIP_MENU();
			}
			return true;
		}
};

void AddSC_dk_down()
{
    new dk_down();
}