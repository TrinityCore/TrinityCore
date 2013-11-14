#include "ScriptMgr.h"
#include "Player.h"

class teleport_hyjal : public GameObjectScript
{
    public:

        teleport_hyjal(): GameObjectScript("teleport_hyjal"){}

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
				player->TeleportTo(1,5029.450195f,-2029.359986f,1148.969975f,3.620060f);
			default:
				player->CLOSE_GOSSIP_MENU();
			}
			return true;
		}
};

void AddSC_teleport_hyjal()
{
    new teleport_hyjal();
}