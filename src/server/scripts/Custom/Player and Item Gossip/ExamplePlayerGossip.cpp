#include "ScriptPCH.h"

#define MENU_ID 123 // Our menuID used to match the sent menu to select hook (playerscript)

class example_PlayerGossip : public PlayerScript
{
public: 
    example_PlayerGossip() : PlayerScript("example_PlayerGossip") {}

    void OnLevelChanged(Player* player, uint8 oldlevel) override            // Any hook here
    {
        player->PlayerTalkClass->ClearMenus();                              // Clears old options
        player->ADD_GOSSIP_ITEM(0, "Morph", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
        player->ADD_GOSSIP_ITEM(0, "Demorph", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2);
                                                                            // SetMenuId must be after clear menu and before send menu!!
        player->PlayerTalkClass->GetGossipMenu().SetMenuId(MENU_ID);        // Sets menu ID so we can identify our menu in Select hook. Needs unique number for the menu
        player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, player->GetGUID());
    }

    void OnGossipSelect(Player* player, uint32 menu_id, uint32 sender, uint32 action) override
    {
        if (menu_id != MENU_ID) // Not the menu coded here? stop.
            return;
        player->PlayerTalkClass->ClearMenus();

        switch(action)
        {
        case GOSSIP_ACTION_INFO_DEF+1:
            player->SetDisplayId(999);
            break;
        case GOSSIP_ACTION_INFO_DEF+2:
            player->DeMorph();
            break;
        }
        player->CLOSE_GOSSIP_MENU();
    }
};

void AddSC_example_PlayerGossip() // Add to scriptloader normally
{
    new example_PlayerGossip();
}
