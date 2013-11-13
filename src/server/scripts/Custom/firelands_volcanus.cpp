#include "ScriptMgr.h"
#include "Player.h"

class firelands_volcanus : public GameObjectScript
{
    public:

        firelands_volcanus(): GameObjectScript("firelands_volcanus"){}

        bool OnGossipHello(Player* player, GameObject* go) OVERRIDE
        {
            player->ADD_GOSSIP_ITEM(0, "Ir al Yunque de la Conflagracion", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+13);
			player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, go->GetGUID());
            return true;
        }

		bool OnGossipSelect(Player* player, GameObject* go, uint32 sender, uint32 action) OVERRIDE
		{
			player->PlayerTalkClass->ClearMenus();
			switch(action)
			{
			case GOSSIP_ACTION_INFO_DEF+13:
				player->TeleportTo(720,506.415955f,473.274536f,246.745899f,2.358165f);
			default:
				player->CLOSE_GOSSIP_MENU();
			}
			return true;
		}
};

void AddSC_firelands_volcanus()
{
    new firelands_volcanus();
}