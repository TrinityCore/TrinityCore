#ifndef SC_PLAYER_H
#define SC_PLAYER_H

#include "../ScriptMgr.h"
#include "Player.h"
#include "GossipDef.h"
#include "QuestDef.h"

// Gossip Text
#define GOSSIP_TEXT_BANK                "银行 "
#define GOSSIP_TEXT_WINDRIDER           "风骑士管理员 "
#define GOSSIP_TEXT_GRYPHON             "狮鹫管理员 "
#define GOSSIP_TEXT_BATHANDLER          "蝙蝠管理员 "
#define GOSSIP_TEXT_HIPPOGRYPH          "角鹰兽管理员 "
#define GOSSIP_TEXT_FLIGHTMASTER        "飞行管理员 "
#define GOSSIP_TEXT_AUCTIONHOUSE        "拍卖行 "
#define GOSSIP_TEXT_GUILDMASTER         "公会管理员 "
#define GOSSIP_TEXT_INN                 "旅店 "
#define GOSSIP_TEXT_MAILBOX             "邮箱 "
#define GOSSIP_TEXT_STABLEMASTER        "兽栏 "
#define GOSSIP_TEXT_WEAPONMASTER        "武器训练师 "
#define GOSSIP_TEXT_BATTLEMASTER        "将领 "
#define GOSSIP_TEXT_CLASSTRAINER        "等级训练师 "
#define GOSSIP_TEXT_PROFTRAINER         "专业训练师 "
#define GOSSIP_TEXT_OFFICERS            "休闲室 "

#define GOSSIP_TEXT_ALTERACVALLEY       "奥特呵科山谷 "
#define GOSSIP_TEXT_ARATHIBASIN         "阿瑞斯盆地 " 
#define GOSSIP_TEXT_WARSONGULCH         "战歌峡谷 "
#define GOSSIP_TEXT_ARENA               "竞技场 "
#define GOSSIP_TEXT_EYEOFTHESTORM       "风暴之眼 "

#define GOSSIP_TEXT_DRUID               "小德 " 
#define GOSSIP_TEXT_HUNTER              "猎人 "
#define GOSSIP_TEXT_PRIEST              "牧师 "
#define GOSSIP_TEXT_ROGUE               "盗贼 "
#define GOSSIP_TEXT_WARRIOR             "战士 "
#define GOSSIP_TEXT_PALADIN             "骑士 "
#define GOSSIP_TEXT_SHAMAN              "萨满 "
#define GOSSIP_TEXT_MAGE                "法师 "
#define GOSSIP_TEXT_WARLOCK             "术士 "

#define GOSSIP_TEXT_ALCHEMY             "炼金 "
#define GOSSIP_TEXT_BLACKSMITHING       "锻造 "
#define GOSSIP_TEXT_COOKING             "烹饪 "
#define GOSSIP_TEXT_ENCHANTING          "附魔 "
#define GOSSIP_TEXT_ENGINEERING         "工程 "
#define GOSSIP_TEXT_FIRSTAID            "急救 "
#define GOSSIP_TEXT_HERBALISM           "药剂 "
#define GOSSIP_TEXT_LEATHERWORKING      "制皮 "
#define GOSSIP_TEXT_POISONS             "毒药 "
#define GOSSIP_TEXT_TAILORING           "裁缝 "
#define GOSSIP_TEXT_MINING              "采矿 "
#define GOSSIP_TEXT_FISHING             "钓鱼 "
#define GOSSIP_TEXT_SKINNING            "剥皮 "
#define GOSSIP_TEXT_JEWELCRAFTING       "珠宝 "

#define GOSSIP_TEXT_IRONFORGE_BANK      "铁炉堡银行 "
#define GOSSIP_TEXT_STORMWIND_BANK      "暴风城银行 "
#define GOSSIP_TEXT_DEEPRUNTRAM         "矿道地铁 "
#define GOSSIP_TEXT_ZEPPLINMASTER       "飞艇管理员 "
#define GOSSIP_TEXT_FERRY               "鲁特拉渡口 "

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
