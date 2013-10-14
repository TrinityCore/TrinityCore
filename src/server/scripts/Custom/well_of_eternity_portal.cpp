#include "ScriptMgr.h"
#include "Player.h"

class well_of_eternity_portal : public GameObjectScript
{
    public:

        well_of_eternity_portal(): GameObjectScript("well_of_eternity_portal"){}

        bool OnGossipHello(Player* player, GameObject* go) OVERRIDE
        {
            player->ADD_GOSSIP_ITEM(0, "¡Estoy listo para enfrentar a  Mannoroth y Varo'then!", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+13);
			player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, go->GetGUID());
            return true;
        }

		bool OnGossipSelect(Player* player, GameObject* go, uint32 sender, uint32 action) OVERRIDE
		{
			player->PlayerTalkClass->ClearMenus();
			switch(action)
			{
			case GOSSIP_ACTION_INFO_DEF+13:
				player->TeleportTo(939,3066.029f,-5565.5718f,18.22f,0.0f);
			default:
				player->CLOSE_GOSSIP_MENU();
			}
			return true;
		}
};

void AddSC_well_of_eternity_portal()
{
    new well_of_eternity_portal();
}
