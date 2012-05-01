#include "ScriptPCH.h"
#include <cstring>

extern WorldDatabaseWorkerPool WorldDatabase;

#define MSG_GOSSIP_TELE          "Телепортироваться в ГильдХаус"
#define MSG_GOSSIP_BUY           "Купить ГильдХаус (10000 золота)"
#define MSG_GOSSIP_SELL          "Продать ГильдХаус (5000 золота)"
#define MSG_GOSSIP_NEXTPAGE      "Следующая -->"
#define MSG_INCOMBAT             "Вы находитесь в бою!"
#define MSG_NOGUILDHOUSE         "Ваша гильдия не имеет ГильдХауса!"
#define MSG_NOFREEGH             "К сожалению, все ГильдХаусы заняты."
#define MSG_ALREADYHAVEGH        "Извините, но у вас уже есть ГильдХаус (%s)."
#define MSG_NOTENOUGHMONEY       "Не хватает денег. Нужно %u золота чтобы купить ГильдХаус."
#define MSG_GHOCCUPIED           "К сожалению, этот ГильдХаус уже занят."
#define MSG_CONGRATULATIONS      "Поздравляем! Вы сейчас в ГильдХаусе."
#define MSG_SOLD                 "Вы продали ГильдХаус. Вот ваше %u золото."
#define MSG_NOTINGUILD           "Вы не состоите в гильдии. Вступите или создайте гильдию."

#define MSG_NO_TOKEN             "Вы должны быть Гильд-мастером, чтобы иметь возможность просматривать список лотов."

#define CODE_SELL                "SELL"
#define MSG_CODEBOX_SELL         "Введите \"" CODE_SELL "\"если вы хотите продать свой ГильдХаус."

#define OFFSET_GH_ID_TO_ACTION   1500
#define OFFSET_SHOWBUY_FROM      10000

#define ACTION_TELE              1001
#define ACTION_SHOW_BUYLIST      1002  //deprecated. Use (OFFSET_SHOWBUY_FROM + 0) instead
#define ACTION_SELL_GUILDHOUSE   1003
#define ACTION_SELL_GUILDHOUSE_OPT 1004
#define ACTION_SELL_GUILDHOUSE_YES 1005
#define ACTION_SELL_GUILDHOUSE_NO 1006

#define ACTION_TELE 1001
#define ACTION_SHOW_BUYLIST 1002 //deprecated. Use (OFFSET_SHOWBUY_FROM + 0) instead
#define ACTION_SELL_GUILDHOUSE 1003

#define ICON_GOSSIP_BALOON       0
#define ICON_GOSSIP_WING         2
#define ICON_GOSSIP_BOOK         3
#define ICON_GOSSIP_WHEEL1       4
#define ICON_GOSSIP_WHEEL2       5
#define ICON_GOSSIP_GOLD         6
#define ICON_GOSSIP_BALOONDOTS   7
#define ICON_GOSSIP_TABARD       8
#define ICON_GOSSIP_XSWORDS      9

#define COST_GH_BUY 100000000 //10000 g.
#define COST_GH_SELL 50000000 // 5000 g.

#define GOSSIP_COUNT_MAX         10

char str[200];

bool isPlayerGuildLeader(Player *player)
{
    return (player->GetRank() == 0) && (player->GetGuildId() != 0);
}

bool getGuildHouseCoords(uint32 guildId, float &x, float &y, float &z, uint32 &map)
{
    if (guildId == 0)
    {
        //if player has no guild
        return false;
    }

    QueryResult result;
    result = WorldDatabase.PQuery("SELECT `x`, `y`, `z`, `map` FROM `guildhouses` WHERE `guildId` = %u", guildId);
    if (result)
    {
        Field *fields = result->Fetch();
        x = fields[0].GetFloat();
        y = fields[1].GetFloat();
        z = fields[2].GetFloat();
        map = fields[3].GetUInt32();
        return true;
    }

    return false;
}

void teleportPlayerToGuildHouse(Player *player, Creature *_creature)
{
    if (player->GetGuildId() == 0)
    {
        //if player has no guild
        _creature->MonsterWhisper(MSG_NOTINGUILD, player->GetGUID());
        sprintf(str,"Очень жаль %u, но вы должны быть членом  одной из гильдий!", player->GetName());
        return;
    }

    if (!player->getAttackers().empty())
    {
        //if player in combat
        _creature->MonsterSay(MSG_INCOMBAT, LANG_UNIVERSAL, player->GetGUID());
        return;
    }

    float x, y, z;
    uint32 map;

    if (getGuildHouseCoords(player->GetGuildId(), x, y, z, map))
    {
        //teleport player to the specified location
        player->TeleportTo(map, x, y, z, 0.0f);
    }
    else
        _creature->MonsterWhisper(MSG_NOGUILDHOUSE, player->GetGUID());
}

bool showBuyList(Player *player, Creature *_creature, uint32 showFromId = 0)
{
    //show not occupied guildhouses

    QueryResult result;
    result = WorldDatabase.PQuery("SELECT `id`, `comment` FROM `guildhouses` WHERE `guildId` = 0 AND `id` > %u ORDER BY `id` ASC LIMIT %u",
        showFromId, GOSSIP_COUNT_MAX);

    if (result)
    {
        uint32 guildhouseId = 0;
        std::string comment = "";
        do
        {
            Field *fields = result->Fetch();
            guildhouseId = fields[0].GetInt32();
            comment = fields[1].GetString();

            //send comment as a gossip item
            //transmit guildhouseId in Action variable
            player->ADD_GOSSIP_ITEM(ICON_GOSSIP_TABARD, comment, GOSSIP_SENDER_MAIN,
                guildhouseId + OFFSET_GH_ID_TO_ACTION);
        }
        while (result->NextRow());

        if (result->GetRowCount() == GOSSIP_COUNT_MAX)
        {
            //assume that we have additional page
            //add link to next GOSSIP_COUNT_MAX items
            player->ADD_GOSSIP_ITEM(ICON_GOSSIP_BALOONDOTS, MSG_GOSSIP_NEXTPAGE, GOSSIP_SENDER_MAIN,
                guildhouseId + OFFSET_SHOWBUY_FROM);
        }

        player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _creature->GetGUID());

        return true;
    }
    else
    {
        if (showFromId = 0)
        {
            //all guildhouses are occupied
            _creature->MonsterWhisper(MSG_NOFREEGH, player->GetGUID());
            player->CLOSE_GOSSIP_MENU();
        }
        else
        {
            //this condition occurs when COUNT(guildhouses) % GOSSIP_COUNT_MAX == 0
            //just show GHs from beginning
            showBuyList(player, _creature, 0);
        }
    }

    return false;
}

bool isPlayerHasGuildhouse(Player *player, Creature *_creature, bool whisper = false)
{
    QueryResult result;
    result = WorldDatabase.PQuery("SELECT `comment` FROM `guildhouses` WHERE `guildId` = %u",
        player->GetGuildId());

    if (result)
    {
        if (whisper)
        {
            //whisper to player "already have etc..."
            Field *fields = result->Fetch();
            char msg[100];
            sprintf(msg, MSG_ALREADYHAVEGH, fields[0].GetCString());
            _creature->MonsterWhisper(msg, player->GetGUID());
        }

        return true;
    }

    return false;
}

void buyGuildhouse(Player *player, Creature *_creature, uint32 guildhouseId)
{
    if (player->GetMoney() < COST_GH_BUY)
    {
        //show how much money player need to buy GH (in gold)
        char msg[100];
        sprintf(msg, MSG_NOTENOUGHMONEY, COST_GH_BUY / 10000);
        _creature->MonsterWhisper(msg, player->GetGUID());
        return;
    }

    if (isPlayerHasGuildhouse(player, _creature, true))
    {
        //player already have GH
        return;
    }

    QueryResult result;

    //check if somebody already occupied this GH
    result = WorldDatabase.PQuery("SELECT `id` FROM `guildhouses` WHERE `id` = %u AND `guildId` <> 0", guildhouseId);

    if (result)
    {
        _creature->MonsterWhisper(MSG_GHOCCUPIED, player->GetGUID());
        return;
    }

    //update DB
    result = WorldDatabase.PQuery("UPDATE `guildhouses` SET `guildId` = %u WHERE `id` = %u",
        player->GetGuildId(), guildhouseId);
    player->ModifyMoney(-COST_GH_BUY);

    if (result)
        //player->ModifyMoney(-COST_GH_BUY);
        _creature->MonsterSay(MSG_CONGRATULATIONS, LANG_UNIVERSAL, player->GetGUID());
}

void sellGuildhouse(Player *player, Creature *_creature)
{
    QueryResult result;
    result = WorldDatabase.PQuery("UPDATE `guildhouses` SET `guildId` = 0 WHERE `guildId` = %u", player->GetGuildId());

    if (result)
        //player->ModifyMoney(COST_GH_SELL);
        _creature->MonsterSay(MSG_SOLD, LANG_UNIVERSAL, player->GetGUID());
    player->CLOSE_GOSSIP_MENU();
}

class guildmaster : public CreatureScript
{
public:
    guildmaster() : CreatureScript("guildmaster") { }

    bool GossipSelectWithCode(Player *player, Creature *_creature, uint32 sender, uint32 action, const char* sCode)
    {
        if (sender == GOSSIP_SENDER_MAIN)
        {
            if (action == ACTION_SELL_GUILDHOUSE)
            {
                int i = -1;
                try
                {
                    //compare code

                    if (strlen(sCode) + 1 == sizeof CODE_SELL)
                        i = strcmp(CODE_SELL, sCode);
                }

                catch(char *str) {sLog->outErrorDb(str);
                }

                if (i == 0)
                {
                    //right code
                    sellGuildhouse(player, _creature);
                }

                player->CLOSE_GOSSIP_MENU();
                return true;
            }
        }
        return false;
    }

    bool OnGossipSelect(Player *player, Creature *_creature, uint32 sender, uint32 action)
    {
        player->PlayerTalkClass->ClearMenus();
        if (sender != GOSSIP_SENDER_MAIN)
            return false;

        switch (action)
        {
        case ACTION_TELE:
            //teleport player to GH
            player->CLOSE_GOSSIP_MENU();
            teleportPlayerToGuildHouse(player, _creature);
            break;
        case ACTION_SHOW_BUYLIST:
            //show list of GHs which currently not occupied
            showBuyList(player, _creature);
            break;

        case ACTION_SELL_GUILDHOUSE_OPT:
            player->CLOSE_GOSSIP_MENU();
            player->ADD_GOSSIP_ITEM(0, "Да, продать свой ГильдХаус!", GOSSIP_SENDER_MAIN, ACTION_SELL_GUILDHOUSE_YES);
            player->ADD_GOSSIP_ITEM(0, "Нет, я передумал!", GOSSIP_SENDER_MAIN, ACTION_SELL_GUILDHOUSE_NO);
            player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _creature->GetGUID());
            break;

        case ACTION_SELL_GUILDHOUSE_YES:
            sellGuildhouse(player, _creature);
            player->CLOSE_GOSSIP_MENU();
            player->ModifyMoney(COST_GH_SELL);
            break;

        case ACTION_SELL_GUILDHOUSE_NO:
            player->CLOSE_GOSSIP_MENU();
            break;

        default:
            if (action > OFFSET_SHOWBUY_FROM)
            {
                showBuyList(player, _creature, action - OFFSET_SHOWBUY_FROM);
            }
            else if (action > OFFSET_GH_ID_TO_ACTION)
            {
                //player clicked on buy list
                player->CLOSE_GOSSIP_MENU();

                //get guildhouseId from action
                //guildhouseId = action - OFFSET_GH_ID_TO_ACTION
                buyGuildhouse(player, _creature, action - OFFSET_GH_ID_TO_ACTION);
            }
            break;
        }

        return true;
    }

    bool OnGossipHello(Player *player, Creature *_creature)
    {
        player->ADD_GOSSIP_ITEM(ICON_GOSSIP_BALOON, MSG_GOSSIP_TELE,
            GOSSIP_SENDER_MAIN, ACTION_TELE);

        if (isPlayerGuildLeader(player))
        {
            if (isPlayerHasGuildhouse(player, _creature))
            {
                player->ADD_GOSSIP_ITEM(0, "Продать ГильдХаус!", GOSSIP_SENDER_MAIN, ACTION_SELL_GUILDHOUSE_OPT);
            }
            else
            {
                //show additional menu for guild leader
                player->ADD_GOSSIP_ITEM(ICON_GOSSIP_GOLD, MSG_GOSSIP_BUY,
                    GOSSIP_SENDER_MAIN, ACTION_SHOW_BUYLIST);
            }
        }

        player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _creature->GetGUID());
        return true;
    }
};

void AddSC_guildmaster()
{
    new guildmaster();
}
