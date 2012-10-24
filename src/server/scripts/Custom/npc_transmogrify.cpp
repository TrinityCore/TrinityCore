#include "ScriptPCH.h"

#define MSG_GOSSIP_TEXT_GETTING_STARTED	"Приветствую тебя странник..."
#define MSG_GOSSIP_TEXT_ADD_GOSSIP_ITEM "Исказить пространство!"
#define MSG_GOSSIP_TEXT_ADD_GOSSIP_ITEM2 "Вы действительно хотите исказить пространство?"
#define MSG_GOSSIP_TEXT_GOSSIP_ITEM_EXTENDED "Отменить искажение."
#define MSG_GOSSIP_TEXT_INVENTORY_SLOT_BAG "Положите предметы в первый и второй слот!"
#define MSG_GOSSIP_TEXT_FAKE_ERR_CANT_FIND_ITEM "Не найден предмет!"
#define MSG_GOSSIP_TEXT_FAKE_ERR_WRONG_QUALITY "Предметы имеют разные свойства!"
#define MSG_GOSSIP_TEXT_FAKE_ERR_DIFF_SLOTS "Предметы предназначены для разных слотов!"
#define MSG_GOSSIP_TEXT_FAKE_ERR_DIFF_CLASS "Предметы предназначены для разных классов!" 
#define MSG_GOSSIP_TEXT_FAKE_ERR_DIFF_RACE "Предметы предназначены для разных рас!" 
#define MSG_GOSSIP_TEXT_INVENTORY_SLOT_BAG_0 "Положите предмет в первый слот!"
 
enum TransmogrifyActions {
    ACTION_TRANSMOGRIFY_ADD_DISPLAY,
    ACTION_TRANSMOGRIFY_REMOVE_DISPLAY
};

uint32 PriceInGold = 10000000; // 1k golds

class npc_transmogrify : public CreatureScript
{
    public:
        npc_transmogrify() : CreatureScript("npc_transmogrify") { }

        bool OnGossipHello(Player* pPlayer, Creature* pCreature)
        {
            pPlayer->PlayerTalkClass->ClearMenus();
		     pCreature->MonsterWhisper(MSG_GOSSIP_TEXT_GETTING_STARTED, pPlayer->GetGUID());
            pPlayer->ADD_GOSSIP_ITEM_EXTENDED(GOSSIP_ICON_INTERACT_1, MSG_GOSSIP_TEXT_ADD_GOSSIP_ITEM, GOSSIP_SENDER_MAIN, ACTION_TRANSMOGRIFY_ADD_DISPLAY, MSG_GOSSIP_TEXT_ADD_GOSSIP_ITEM2, PriceInGold, false);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, MSG_GOSSIP_TEXT_GOSSIP_ITEM_EXTENDED, GOSSIP_SENDER_MAIN, ACTION_TRANSMOGRIFY_REMOVE_DISPLAY);
            pPlayer->SEND_GOSSIP_MENU(51000, pCreature->GetGUID());
            return true;
        }

        bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action)
        {
            player->PlayerTalkClass->SendCloseGossip();
            switch (action)
            {
                case ACTION_TRANSMOGRIFY_ADD_DISPLAY:
                    TransmogrifyItem(player, creature);
                    break;
                case ACTION_TRANSMOGRIFY_REMOVE_DISPLAY:
                    ClearItem(player, creature);
                    break;
            }
            return true;
        }

        void TransmogrifyItem(Player* player, Creature* creature)
        {
            ChatHandler handler(player);
            Item *trItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, INVENTORY_SLOT_ITEM_START);
            Item *displayItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, INVENTORY_SLOT_ITEM_START + 1);
            if (!trItem || !displayItem)
            {
            creature->MonsterWhisper(MSG_GOSSIP_TEXT_INVENTORY_SLOT_BAG, player->GetGUID());
                return;
            }

            if (!player->HasEnoughMoney(PriceInGold))
            {
                player->SendBuyError(BUY_ERR_NOT_ENOUGHT_MONEY, 0, 0, 0);
                return;
            }

            uint8 result = trItem->SetFakeDisplay(displayItem->GetTemplate()->ItemId);
            switch (result)
            {
                case FAKE_ERR_CANT_FIND_ITEM:
					 creature->MonsterWhisper(MSG_GOSSIP_TEXT_FAKE_ERR_CANT_FIND_ITEM, player->GetGUID());
                    break;
                case FAKE_ERR_WRONG_QUALITY:
					 creature->MonsterWhisper(MSG_GOSSIP_TEXT_FAKE_ERR_WRONG_QUALITY, player->GetGUID());
                    break;
                case FAKE_ERR_DIFF_SLOTS:
					 creature->MonsterWhisper(MSG_GOSSIP_TEXT_FAKE_ERR_DIFF_SLOTS, player->GetGUID());
                    break;
                case FAKE_ERR_DIFF_CLASS:
					 creature->MonsterWhisper(MSG_GOSSIP_TEXT_FAKE_ERR_DIFF_CLASS, player->GetGUID());
                    break;
                case FAKE_ERR_DIFF_RACE:
					 creature->MonsterWhisper(MSG_GOSSIP_TEXT_FAKE_ERR_DIFF_RACE, player->GetGUID());
                    break;
                case FAKE_ERR_OK:
                {
                    WorldPacket data;
                    data << uint8(INVENTORY_SLOT_BAG_0);
                    data << uint8(trItem->GetSlot());
                    player->GetSession()->HandleAutoEquipItemOpcode(data);

                    player->ModifyMoney(-1 * PriceInGold);
                    creature->GetAI()->DoCast(63491);

                    break;
                }
            }
        }

        void ClearItem(Player *player, Creature* creature)
        {
            ChatHandler handler(player);
            Item *trItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, INVENTORY_SLOT_ITEM_START);
            if (!trItem)
            {
				creature->MonsterWhisper(MSG_GOSSIP_TEXT_INVENTORY_SLOT_BAG_0, player->GetGUID());
                return;
            }

            trItem->RemoveFakeDisplay();

            WorldPacket data;
            data << uint8(INVENTORY_SLOT_BAG_0);
            data << uint8(trItem->GetSlot());
            player->GetSession()->HandleAutoEquipItemOpcode(data);

            creature->GetAI()->DoCast(63491);
        }
};

void AddSC_transmogrify_script()
{
   new npc_transmogrify;
}