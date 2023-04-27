#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "GameEventMgr.h"
#include "Player.h"
#include "WorldSession.h"
#include "AuctionHouseMgr.h"
#include "ObjectMgr.h"
#include "World.h"
#include "Language.h"
using namespace std;

class aa_creature_pet : public CreatureScript
{
public:
    aa_creature_pet() : CreatureScript("aa_creature_pet") { }

    bool OnGossipHello(Player* player, Creature* creature) override
    {
        player->PlayerTalkClass->ClearMenus();

        if (1) {
            AddGossipItemFor(player, GossipOptionNpc(0), "∑宠物加点：", 1, 4);
            AddGossipItemFor(player, GossipOptionNpc(0), "∑宠物加点：", 1, 4);
            AddGossipItemFor(player, GossipOptionNpc(0), "宠物等级：剩余点数：", 1, 4);
            AddGossipItemFor(player, GossipOptionNpc(0), "力量加点：1000", 1, 4);
            AddGossipItemFor(player, GossipOptionNpc(0), "智力加点：1000", 1, 4);
            AddGossipItemFor(player, GossipOptionNpc(0), "耐力加点：1000", 1, 4);
            AddGossipItemFor(player, GossipOptionNpc(0), "敏捷加点：1000", 1, 4);

            AddGossipItemFor(player, GossipOptionNpc(0), "∑宠物技能：", 1, 4);
            AddGossipItemFor(player, GossipOptionNpc(0), "1、未开启", 1, 4);
            AddGossipItemFor(player, GossipOptionNpc(0), "2、未开启", 1, 4);
            AddGossipItemFor(player, GossipOptionNpc(0), "3、未开启", 1, 4);
            AddGossipItemFor(player, GossipOptionNpc(0), "4、未开启", 1, 4);
            AddGossipItemFor(player, GossipOptionNpc(0), "5、未开启", 1, 4);
            AddGossipItemFor(player, GossipOptionNpc(0), "6、未开启", 1, 4);
            AddGossipItemFor(player, GossipOptionNpc(0), "7、未开启", 1, 4);
            AddGossipItemFor(player, GossipOptionNpc(0), "8、未开启", 1, 4);
            AddGossipItemFor(player, GossipOptionNpc(0), "9、未开启", 1, 4);
            AddGossipItemFor(player, GossipOptionNpc(0), "10、未开启", 1, 4);

            AddGossipItemFor(player, GossipOptionNpc(0), "宠物重生", 1, 4);
        }
        else {
            AddGossipItemFor(player, GossipOptionNpc(0), "姓名：球球", 1, 4);
            AddGossipItemFor(player, GossipOptionNpc(0), "战力：99999", 1, 4);
            AddGossipItemFor(player, GossipOptionNpc(0), "∑一般信息：", 1, 4);
            AddGossipItemFor(player, GossipOptionNpc(0), "等级：1", 1, 4);
            AddGossipItemFor(player, GossipOptionNpc(0), "经验：1/1000", 1, 4);
            AddGossipItemFor(player, GossipOptionNpc(0), "物理伤害：10", 1, 4);
            AddGossipItemFor(player, GossipOptionNpc(0), "魔法伤害：10", 1, 4);
            AddGossipItemFor(player, GossipOptionNpc(0), "生命：10", 1, 4);
            AddGossipItemFor(player, GossipOptionNpc(0), "防御：10", 1, 4);
            AddGossipItemFor(player, GossipOptionNpc(0), "成长：1.01", 1, 4);
            AddGossipItemFor(player, GossipOptionNpc(0), "契合：30.0", 1, 4);

            AddGossipItemFor(player, GossipOptionNpc(0), "∑宠物资质：", 1, 4);
            AddGossipItemFor(player, GossipOptionNpc(0), "攻击资质：1000", 1, 4);
            AddGossipItemFor(player, GossipOptionNpc(0), "法力资质：1000", 1, 4);
            AddGossipItemFor(player, GossipOptionNpc(0), "体力资质：1000", 1, 4);
            AddGossipItemFor(player, GossipOptionNpc(0), "防御资质：1000", 1, 4);

            AddGossipItemFor(player, GossipOptionNpc(0), "∑宠物技能：", 1, 4);

        }

        //player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "比武大会排行榜", 1, 4);

        //if (player->m_topmc == 999)
        //{
        //    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "你已报名", 1, 1);
        //}
        //else if (player->m_topmc > 0 && player->m_topmc < 999)
        //{
        //    if (IsEventActive(sSwitch->GetValue(TOP_93)))
        //    {
        //        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "比武大会已经开始", 1, 1);
        //    }
        //    else
        //    {
        //        const CTopSys* cccc = sCharPvpTop->FindTopSys(player->m_topmc);
        //        if (cccc && cccc->itemid)
        //        {
        //            if (ItemTemplate const* pProto = sObjectMgr->GetItemTemplate(cccc->itemid))
        //            {
        //                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "领取比武大会奖励", 1, 2);
        //            }
        //            else
        //            {
        //                creature->MonsterSay("奖励物品ID设置出错...", LANG_UNIVERSAL, 0);
        //                return false;
        //            }
        //        }
        //        else
        //            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "比武大会报名", 1, 3);
        //    }

        //}
        //else if (!player->m_topmc)
        //{
        //    if (!IsEventActive(sSwitch->GetValue(TOP_93)))
        //        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "比武大会报名", 1, 3);
        //    else
        //        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "比武大会已经开始", 1, 1);
        //}

        SendGossipMenuFor(player, DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
        return true;
    }
    bool OnGossipSelect(Player* player, Creature* creature, uint32 sender, uint32 action) override
    {
        //if (action == 1)
        //    OnGossipHello(player, creature);
        //else if (action == 2)
        //{
        //    const CTopSys* cccc = sCharPvpTop->FindTopSys(player->m_topmc);
        //    if (cccc && cccc->itemid)
        //    {
        //        if (ItemTemplate const* pProto = sObjectMgr->GetItemTemplate(cccc->itemid))
        //            player->AddItem(cccc->itemid, 1);
        //    }

        //    player->m_topmc = 0;
        //    CharacterDatabase.PExecute("update _xlchar set top = %u where guid = %u", player->m_topmc, player->GetGUIDLow());
        //    creature->MonsterWhisper("比武大会奖励领取成功...", player);
        //    OnGossipHello(player, creature);
        //    return false;
        //}
        //else if (action == 3)
        //{
        //    player->m_topmc = 999;
        //    CharacterDatabase.PExecute("update _xlchar set top = %u where guid = %u", player->m_topmc, player->GetGUIDLow());
        //    creature->MonsterWhisper("比武大会报名成功...", player);
        //    OnGossipHello(player, creature);
        //    return false;
        //}
        //else if (action == 4)
        //{
        //    player->PlayerTalkClass->ClearMenus();
        //    if (sCharPvpTop->m_playertopph.size())
        //    {
        //        for (int i = 1; i < sCharPvpTop->m_playertopph.size() + 1; i++)
        //        {
        //            if (i > 10)
        //                continue;

        //            uint32 guid = sCharPvpTop->m_playertopph[i];
        //            if (guid)
        //            {
        //                GlobalPlayerData const* playerData = sWorld->GetGlobalPlayerData(guid);
        //                if (playerData)
        //                {
        //                    std::ostringstream hsfdata;

        //                    bool hastouxian = false;
        //                    const CTopSys* cccc = sCharPvpTop->FindTopSys(i);
        //                    if (cccc && cccc->text != "")
        //                        hastouxian = true;

        //                    if (hastouxian)
        //                        hsfdata << cccc->text << ";" << playerData->name.c_str();
        //                    else
        //                        hsfdata << "第" << i << "名;" << playerData->name.c_str();

        //                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, hsfdata.str().c_str(), 1, 5);
        //                }

        //            }
        //        }
        //    }
        //    else
        //        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "暂无排行榜", 1, 5);

        //    player->SEND_GOSSIP_MENU(20000, creature->GetGUID());
        //}
        //else if (action == 5)
        //{
        //    OnGossipHello(player, creature);
        //    return false;
        //}
        return true;
    }
};

void AddAA_Creature_Pet()
{
    new aa_creature_pet();
}
