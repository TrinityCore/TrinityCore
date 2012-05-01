#include "ScriptPCH.h"
#include "Config.h"

class npc_vip : public CreatureScript
{
public:
    npc_vip() : CreatureScript("npc_vip") { }

    bool OnGossipHello(Player* player, Creature* creature)
    {
        if (!player->GetSession()->IsVIP() && !player->isGameMaster())
        {
            player->CLOSE_GOSSIP_MENU();
            creature->MonsterWhisper("Извините $N, только для VIP-персон.", player->GetGUID(), false);
            return true;
        }

        if (creature->isVendor())
        {
            player->CLOSE_GOSSIP_MENU();
            player->GetSession()->SendListInventory(creature->GetGUID());
            return true;
        }

        if (creature->isQuestGiver())
            player->PrepareQuestMenu(creature->GetGUID());

        player->ADD_GOSSIP_ITEM(9, "Исцеление"      , GOSSIP_SENDER_MAIN, 1202);
        player->ADD_GOSSIP_ITEM(5, "Сброс талантов" , GOSSIP_SENDER_MAIN, 4035);
        player->ADD_GOSSIP_ITEM(7, "[Морфы] ->"     , GOSSIP_SENDER_MAIN, 1203);
        player->ADD_GOSSIP_ITEM(7, "[Баффы] ->"     , GOSSIP_SENDER_MAIN, 1206);

        player->SEND_GOSSIP_MENU(player->GetGossipTextId(creature), creature->GetGUID());
        return true;
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action)
    {
        player->PlayerTalkClass->ClearMenus();

        switch(action)
        {
        case 1202: // Heal
            if (player->HasAura(45523))
            {
                player->CLOSE_GOSSIP_MENU();
                creature->MonsterWhisper("Извините $N, я не могу это сделать это сейчас.", player->GetGUID(), false);
            }
            else
            {
                player->CLOSE_GOSSIP_MENU();
                player->CastSpell(player, 39321, true); // Исцеление себя
                player->CastSpell(player, 45523, true);
            }
            break;
        case 4035: // Reset talents
            player->CLOSE_GOSSIP_MENU();
            player->SendTalentWipeConfirm(creature->GetGUID());
            break;
        case 1203: // Morphs
            //player->ADD_GOSSIP_ITEM(5, "Иллидан", GOSSIP_SENDER_MAIN, 500);
            player->ADD_GOSSIP_ITEM(5, "Акама", GOSSIP_SENDER_MAIN, 502);
            player->ADD_GOSSIP_ITEM(5, "Рыцарь смерти", GOSSIP_SENDER_MAIN, 503);
            player->ADD_GOSSIP_ITEM(5, "Таурен", GOSSIP_SENDER_MAIN, 504);
            player->ADD_GOSSIP_ITEM(5, "Нежить", GOSSIP_SENDER_MAIN, 505);
            player->ADD_GOSSIP_ITEM(5, "Человек", GOSSIP_SENDER_MAIN, 506);
            player->ADD_GOSSIP_ITEM(5, "Король-лич", GOSSIP_SENDER_MAIN, 507);
            player->ADD_GOSSIP_ITEM(5, "Тирион", GOSSIP_SENDER_MAIN, 508);
            player->ADD_GOSSIP_ITEM(5, "Рыцарь ордена Серебряной Длани", GOSSIP_SENDER_MAIN, 509);
            player->ADD_GOSSIP_ITEM(5, "Артас", GOSSIP_SENDER_MAIN, 510);
            player->ADD_GOSSIP_ITEM(5, "СНЯТЬ МОРФ", GOSSIP_SENDER_MAIN, 511);

            player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());

            break;
            //case 500:
            //    player->CLOSE_GOSSIP_MENU();
            //    player->SetDisplayId(21135);
            //    break;
        case 502:
            player->CLOSE_GOSSIP_MENU();
            player->SetDisplayId(20681);
            break;
        case 503:
            player->CLOSE_GOSSIP_MENU();
            player->SetDisplayId(16508);
            break;
        case 504:
            player->CLOSE_GOSSIP_MENU();
            player->SetDisplayId(17332);
            break;
        case 505:
            player->CLOSE_GOSSIP_MENU();
            player->SetDisplayId(2789);
            break;
        case 506:
            player->CLOSE_GOSSIP_MENU();
            player->SetDisplayId(16280);
            break;
        case 507:
            player->CLOSE_GOSSIP_MENU();
            player->SetDisplayId(24191);
            break;
        case 508:
            player->CLOSE_GOSSIP_MENU();
            player->SetDisplayId(22209);
            break;
        case 509:
            player->CLOSE_GOSSIP_MENU();
            player->SetDisplayId(23889);
            break;
        case 510:
            player->CLOSE_GOSSIP_MENU();
            player->SetDisplayId(24949);
            break;
        case 511:
            player->CLOSE_GOSSIP_MENU();
            player->DeMorph();
            break;
        case 1206: // Buffs
            player->ADD_GOSSIP_ITEM(5, "Слово силы: Стойкость, Rank 8", GOSSIP_SENDER_MAIN, 4000);
            player->ADD_GOSSIP_ITEM(5, "Великое благословение королей", GOSSIP_SENDER_MAIN, 4001);
            player->ADD_GOSSIP_ITEM(5, "Великое благословение могущества", GOSSIP_SENDER_MAIN, 4002);
            player->ADD_GOSSIP_ITEM(5, "Великое благословение мудрости", GOSSIP_SENDER_MAIN, 4003);
            player->ADD_GOSSIP_ITEM(5, "Знак дикой природы, Rank 9", GOSSIP_SENDER_MAIN, 4004);
            player->ADD_GOSSIP_ITEM(5, "Чародейский интеллект, Rank 7", GOSSIP_SENDER_MAIN, 4005);
            player->ADD_GOSSIP_ITEM(5, "Божественный дух, Rank 8", GOSSIP_SENDER_MAIN, 4006);

            player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());

            break;
        case 4000:
            player->CLOSE_GOSSIP_MENU();
            player->CastSpell(player, 48161, true);
            break;
        case 4001:
            player->CLOSE_GOSSIP_MENU();
            player->CastSpell(player, 25898, true);
            break;
        case 4002:
            player->CLOSE_GOSSIP_MENU();
            player->CastSpell(player, 48934, true);
            break;
        case 4003:
            player->CLOSE_GOSSIP_MENU();
            player->CastSpell(player, 48938, true);
            break;
        case 4004:
            player->CLOSE_GOSSIP_MENU();
            player->CastSpell(player, 48469, true);
            break;
        case 4005:
            player->CLOSE_GOSSIP_MENU();
            player->CastSpell(player, 42995, true);
            break;
        case 4006:
            player->CLOSE_GOSSIP_MENU();
            player->CastSpell(player, 48073, true);
            break;
        }

        return true;
    }
};

void AddSC_npc_vip()
{
    new npc_vip;
}
