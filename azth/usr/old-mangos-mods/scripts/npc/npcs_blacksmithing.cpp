#include "precompiled.h"
#include "Player.h"
#include "sc_gossip.h"

/*######
## npcs_blacksmithing
######*/

#define GOSSIP_ITEM_HAMMERSMITH         "Perfavore insegnami come diventare un Hammersmith, Lilith."
#define GOSSIP_ITEM_AXESMITH            "Perfavore insegnami come diventare un axesmith, Kilram."
#define GOSSIP_ITEM_SWORDSMITH          "Perfavore insegnami come diventare un swordsmith, Seril."
#define GOSSIP_ITEM_UNLEARN_HAMMERSMITH "Vorrei disimparare Hammersmithing!"
#define GOSSIP_ITEM_UNLEARN_AXESMITH    "Vorrei disimparare Axesmithing!"
#define GOSSIP_ITEM_UNLEARN_SWORDSMITH  "Vorrei disimparare Swordsmithing!"

bool GossipHello_npcs_blacksmithing(Player *player, Creature *_Creature )
{
    if ((player->getLevel() > 49) && (player->GetSkillValue(164) > 249) && player->HasSpell(9787))
    {
        switch (_Creature->GetEntry())
        {
            case 11191: //Lilith the Lithe - Master Hammersmith
                if (!player->HasSpell(17040))
                    player->ADD_GOSSIP_ITEM( 0, GOSSIP_ITEM_HAMMERSMITH, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);
                if (player->HasSpell(17041))
                {
                    player->ADD_GOSSIP_ITEM( 0, GOSSIP_ITEM_UNLEARN_AXESMITH, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
                }
                else if (player->HasSpell(17039))
                {
                    player->ADD_GOSSIP_ITEM( 0, GOSSIP_ITEM_UNLEARN_SWORDSMITH, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
                }
                break;
            case 11192: //Kilram - Master Axesmith
                if (!player->HasSpell(17041))
                    player->ADD_GOSSIP_ITEM( 0, GOSSIP_ITEM_AXESMITH, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);
                if (player->HasSpell(17040))
                {
                    player->ADD_GOSSIP_ITEM( 0, GOSSIP_ITEM_UNLEARN_HAMMERSMITH, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
                }
                else if (player->HasSpell(17039))
                {
                    player->ADD_GOSSIP_ITEM( 0, GOSSIP_ITEM_UNLEARN_SWORDSMITH, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
                }
                break;
            case 11193: //Seril Scourgebane - Master Swordsmith
                if (!player->HasSpell(17039))
                    player->ADD_GOSSIP_ITEM( 0, GOSSIP_ITEM_SWORDSMITH, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);
                if (player->HasSpell(17041))
                {
                    player->ADD_GOSSIP_ITEM( 0, GOSSIP_ITEM_UNLEARN_AXESMITH, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
                }
                else if (player->HasSpell(17040))
                {
                    player->ADD_GOSSIP_ITEM( 0, GOSSIP_ITEM_UNLEARN_HAMMERSMITH, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
                }
                break;
        }
    }

    switch (_Creature->GetEntry())
    {
        case 11191: //Lilith the Lithe - Master Hammersmith
            player->PlayerTalkClass->SendGossipMenu(7245,_Creature->GetObjectGuid());
            break;
        case 11192: //Kilram - Master Axesmith
            player->PlayerTalkClass->SendGossipMenu(7243,_Creature->GetObjectGuid());
            break;
        case 11193: //Seril Scourgebane - Master Swordsmith
            player->PlayerTalkClass->SendGossipMenu(7247,_Creature->GetObjectGuid());
            break;  
    }
    return true;
}

void SendDefaultMenu_npcs_blacksmithing(Player *player, Creature *_Creature, uint32 action )
{
    switch (action)
    {
        case GOSSIP_ACTION_INFO_DEF:
            switch (_Creature->GetEntry())
            {
                case 11191: //Lilith the Lithe - Master Hammersmith
                    if (player->HasSpell(17041) || player->HasSpell(17039))
                    {
                        player->CLOSE_GOSSIP_MENU();
                        //player->PlayerTalkClass->SendGossipMenu(xxx,_Creature->GetObjectGuid());
                    }
                    else 
                    {
                        player->CLOSE_GOSSIP_MENU();
                        _Creature->CastSpell(player, 39099, true);
                        player->SetQuestStatus(5305,QUEST_STATUS_COMPLETE);
                        //player->PlayerTalkClass->SendGossipMenu(xxx,_Creature->GetObjectGuid());
                    }
                    break;
                case 11192: //Kilram - Master Axesmith
                    if (player->HasSpell(17040) || player->HasSpell(17039))
                    {
                        player->CLOSE_GOSSIP_MENU();
                        //player->PlayerTalkClass->SendGossipMenu(xxx,_Creature->GetObjectGuid());
                    }
                    else
                    {
                        player->CLOSE_GOSSIP_MENU();
                        _Creature->CastSpell(player, 39098, true);
                        player->SetQuestStatus(5306,QUEST_STATUS_COMPLETE);
                        //player->PlayerTalkClass->SendGossipMenu(xxx,_Creature->GetObjectGuid());
                    }
                    break;
                case 11193: //Seril Scourgebane - Master Swordsmith
                    if (player->HasSpell(17041) || player->HasSpell(17040))
                    {
                        player->CLOSE_GOSSIP_MENU();
                        //player->PlayerTalkClass->SendGossipMenu(xxx,_Creature->GetObjectGuid());
                    }
                    else
                    {
                        player->CLOSE_GOSSIP_MENU();
                        _Creature->CastSpell(player, 39097, true);
                        player->SetQuestStatus(5307,QUEST_STATUS_COMPLETE);
                        //player->PlayerTalkClass->SendGossipMenu(xxx,_Creature->GetObjectGuid());
                    }
                    break;
            }
            break;
        case GOSSIP_ACTION_INFO_DEF+1: 
            uint32 cost;
            player->CLOSE_GOSSIP_MENU();
            if (player->getLevel() < 66)
                cost = 500000;
            else
                cost = 1000000;

            if (player->GetMoney() < cost) 
            {
                player->SendBuyError( BUY_ERR_NOT_ENOUGHT_MONEY, _Creature, 0, 0);
                //player->PlayerTalkClass->SendGossipMenu(xxx,_Creature->GetObjectGuid());
                return;
            }
            if (player->HasSpell(17039))
                player->removeSpell(17039);
            else if (player->HasSpell(17040))
                player->removeSpell(17040);
            else if (player->HasSpell(17041))
                player->removeSpell(17041);
            player->ModifyMoney(-(int32)cost);
            //player->PlayerTalkClass->SendGossipMenu(xxx,_Creature->GetObjectGuid());
            break;
    }
    return;
}

bool GossipSelect_npcs_blacksmithing(Player *player, Creature *_Creature, uint32 sender, uint32 action )
{
    if (sender == GOSSIP_SENDER_MAIN)
        SendDefaultMenu_npcs_blacksmithing(player, _Creature, action );

    return true;
}

void AddSC_npcs_blacksmithing()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name="npcs_blacksmithing";
    newscript->pGossipHello =  &GossipHello_npcs_blacksmithing;
    newscript->pGossipSelect = &GossipSelect_npcs_blacksmithing;
    newscript->RegisterSelf();
}
