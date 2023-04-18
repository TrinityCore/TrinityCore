#ifndef SC_PLAYER_H
#define SC_PLAYER_H

#include "../ScriptMgr.h"
#include "Player.h"
#include "GossipDef.h"
#include "QuestDef.h"

// Gossip Text
#define GOSSIP_TEXT_BANK                "���� "
#define GOSSIP_TEXT_WINDRIDER           "����ʿ����Ա "
#define GOSSIP_TEXT_GRYPHON             "ʨ�չ���Ա "
#define GOSSIP_TEXT_BATHANDLER          "�������Ա "
#define GOSSIP_TEXT_HIPPOGRYPH          "��ӥ�޹���Ա "
#define GOSSIP_TEXT_FLIGHTMASTER        "���й���Ա "
#define GOSSIP_TEXT_AUCTIONHOUSE        "������ "
#define GOSSIP_TEXT_GUILDMASTER         "�������Ա "
#define GOSSIP_TEXT_INN                 "�õ� "
#define GOSSIP_TEXT_MAILBOX             "���� "
#define GOSSIP_TEXT_STABLEMASTER        "���� "
#define GOSSIP_TEXT_WEAPONMASTER        "����ѵ��ʦ "
#define GOSSIP_TEXT_BATTLEMASTER        "���� "
#define GOSSIP_TEXT_CLASSTRAINER        "�ȼ�ѵ��ʦ "
#define GOSSIP_TEXT_PROFTRAINER         "רҵѵ��ʦ "
#define GOSSIP_TEXT_OFFICERS            "������ "

#define GOSSIP_TEXT_ALTERACVALLEY       "���غǿ�ɽ�� "
#define GOSSIP_TEXT_ARATHIBASIN         "����˹��� " 
#define GOSSIP_TEXT_WARSONGULCH         "ս��Ͽ�� "
#define GOSSIP_TEXT_ARENA               "������ "
#define GOSSIP_TEXT_EYEOFTHESTORM       "�籩֮�� "

#define GOSSIP_TEXT_DRUID               "С�� " 
#define GOSSIP_TEXT_HUNTER              "���� "
#define GOSSIP_TEXT_PRIEST              "��ʦ "
#define GOSSIP_TEXT_ROGUE               "���� "
#define GOSSIP_TEXT_WARRIOR             "սʿ "
#define GOSSIP_TEXT_PALADIN             "��ʿ "
#define GOSSIP_TEXT_SHAMAN              "���� "
#define GOSSIP_TEXT_MAGE                "��ʦ "
#define GOSSIP_TEXT_WARLOCK             "��ʿ "

#define GOSSIP_TEXT_ALCHEMY             "���� "
#define GOSSIP_TEXT_BLACKSMITHING       "���� "
#define GOSSIP_TEXT_COOKING             "��� "
#define GOSSIP_TEXT_ENCHANTING          "��ħ "
#define GOSSIP_TEXT_ENGINEERING         "���� "
#define GOSSIP_TEXT_FIRSTAID            "���� "
#define GOSSIP_TEXT_HERBALISM           "ҩ�� "
#define GOSSIP_TEXT_LEATHERWORKING      "��Ƥ "
#define GOSSIP_TEXT_POISONS             "��ҩ "
#define GOSSIP_TEXT_TAILORING           "�÷� "
#define GOSSIP_TEXT_MINING              "�ɿ� "
#define GOSSIP_TEXT_FISHING             "���� "
#define GOSSIP_TEXT_SKINNING            "��Ƥ "
#define GOSSIP_TEXT_JEWELCRAFTING       "�鱦 "

#define GOSSIP_TEXT_IRONFORGE_BANK      "��¯������ "
#define GOSSIP_TEXT_STORMWIND_BANK      "��������� "
#define GOSSIP_TEXT_DEEPRUNTRAM         "������� "
#define GOSSIP_TEXT_ZEPPLINMASTER       "��ͧ����Ա "
#define GOSSIP_TEXT_FERRY               "³�����ɿ� "

// Skill defines

#define TRADESKILL_ALCHEMY                  1
#define TRADESKILL_BLACKSMITHING            2
#define TRADESKILL_COOKING                  3
#define TRADESKILL_ENCHANTING               4
#define TRADESKILL_ENGINEERING              5
#define TRADESKILL_FIRSTAID                 6
#define TRADESKILL_HERBALISM                7
#define TRADESKILL_LEATHERWORKING           8
#define TRADESKILL_POISONS                  9
#define TRADESKILL_TAILORING                10
#define TRADESKILL_MINING                   11
#define TRADESKILL_FISHING                  12
#define TRADESKILL_SKINNING                 13
#define TRADESKILL_JEWLCRAFTING             14

#define TRADESKILL_LEVEL_NONE               0
#define TRADESKILL_LEVEL_APPRENTICE         1
#define TRADESKILL_LEVEL_JOURNEYMAN         2
#define TRADESKILL_LEVEL_EXPERT             3
#define TRADESKILL_LEVEL_ARTISAN            4
#define TRADESKILL_LEVEL_MASTER             5

// Gossip defines

#define GOSSIP_ACTION_TRADE                 1
#define GOSSIP_ACTION_TRAIN                 2
#define GOSSIP_ACTION_TAXI                  3
#define GOSSIP_ACTION_GUILD                 4
#define GOSSIP_ACTION_BATTLE                5
#define GOSSIP_ACTION_BANK                  6
#define GOSSIP_ACTION_INN                   7
#define GOSSIP_ACTION_HEAL                  8
#define GOSSIP_ACTION_TABARD                9
#define GOSSIP_ACTION_AUCTION               10
#define GOSSIP_ACTION_INN_INFO              11
#define GOSSIP_ACTION_UNLEARN               12
#define GOSSIP_ACTION_INFO_DEF              1000

#define GOSSIP_SENDER_MAIN                  1
#define GOSSIP_SENDER_INN_INFO              2
#define GOSSIP_SENDER_INFO                  3
#define GOSSIP_SENDER_SEC_PROFTRAIN         4
#define GOSSIP_SENDER_SEC_CLASSTRAIN        5
#define GOSSIP_SENDER_SEC_BATTLEINFO        6
#define GOSSIP_SENDER_SEC_BANK              7
#define GOSSIP_SENDER_SEC_INN               8
#define GOSSIP_SENDER_SEC_MAILBOX           9
#define GOSSIP_SENDER_SEC_STABLEMASTER      10
#define GOSSIP_SENDER_SUB1_BATTLEINFO       11
#define GOSSIP_SENDER_SUB2_BATTLEINFO       12

#define DEFAULT_GOSSIP_MESSAGE              0xffffff

extern uint32 GetSkillLevel(Player *player,uint32 skill);

// Defined fuctions to use with player.

// This fuction add's a menu item,
// a - Icon Id
// b - Text
// c - Sender(this is to identify the current Menu with this item)
// d - Action (identifys this Menu Item)
// e - Text to be displayed in pop up box
// f - Money value in pop up box
#define ADD_GOSSIP_ITEM(a,b,c,d)   PlayerTalkClass->GetGossipMenu()->AddMenuItem(a,b,c,d,"",0)
#define ADD_GOSSIP_ITEM_EXTENDED(a,b,c,d,e,f)   PlayerTalkClass->GetGossipMenu()->AddMenuItem(a,b,c,d,e,f)

// This fuction Sends the current menu to show to client, a - NPCTEXTID(uint32) , b - npc guid(uint64)
#define SEND_GOSSIP_MENU(a,b)      PlayerTalkClass->SendGossipMenu(a,b)

// This fuction shows POI(point of interest) to client.
// a - position X
// b - position Y
// c - Icon Id
// d - Flags
// e - Data
// f - Location Name
#define SEND_POI(a,b,c,d,e,f)      PlayerTalkClass->SendPointOfInterest(a,b,c,d,e,f)

// Closes the Menu
#define CLOSE_GOSSIP_MENU()        PlayerTalkClass->CloseGossip()

// Fuction to tell to client the details
// a - quest object
// b - npc guid(uint64)
// c - Activate accept(bool)
#define SEND_QUEST_DETAILS(a,b,c)  PlayerTalkClass->SendQuestDetails(a,b,c)

// Fuction to tell to client the requested items to complete quest
// a - quest object
// b - npc guid(uint64)
// c - Iscompletable(bool)
// d - close at cancel(bool) - in case single incomplite ques
#define SEND_REQUESTEDITEMS(a,b,c,d) PlayerTalkClass->SendRequestedItems(a,b,c,d)

// Fuctions to send NPC lists, a - is always the npc guid(uint64)
#define SEND_VENDORLIST(a)         GetSession()->SendListInventory(a)
#define SEND_TRAINERLIST(a)        GetSession()->SendTrainerList(a)
#define SEND_BANKERLIST(a)         GetSession()->SendShowBank(a)
#define SEND_TABARDLIST(a)         GetSession()->SendTabardVendorActivate(a)
#define SEND_AUCTIONLIST(a)        GetSession()->SendAuctionHello(a)
#define SEND_TAXILIST(a)           GetSession()->SendTaxiStatus(a)

// Ressurect's the player if is dead.
#define SEND_SPRESURRECT()         GetSession()->SendSpiritResurrect()

// Get the player's honor rank.
#define GET_HONORRANK()            GetHonorRank()
// -----------------------------------

// defined fuctions to use with Creature

#define QUEST_DIALOG_STATUS(a,b,c)   GetSession()->getDialogStatus(a,b,c)
#endif
