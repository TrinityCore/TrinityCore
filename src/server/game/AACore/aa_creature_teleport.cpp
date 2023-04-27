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
class aa_creature_teleport : public CreatureScript
{
public:
    aa_creature_teleport() : CreatureScript("aa_creature_teleport") { }
    
    struct aa_creature_teleportAI : public ScriptedAI
    {
        aa_creature_teleportAI(Creature* creature) : ScriptedAI(creature) { }

        void show_teleport(Player* player, Creature* item, uint32 action) {
            // 传送石
            uint32 entry = item->GetEntry();
            vector<uint32> menus = aaCenter.aa_teleport_targets[entry];
            ClearGossipMenuFor(player); // Clears old options
            int pId = -1;

            //排名显示
            AA_Paihang p_conf;
            for (size_t i = 0; i < menus.size(); i++) {
                uint32 menuid = menus[i];
                AA_Teleport_Conf conf = aaCenter.aa_teleports[menuid];
                if (conf.title.find("排行") != string::npos || conf.subtitle.find("排行") != string::npos) {
                    p_conf = aaCenter.AA_GetPaihangs();
                    p_conf.isOk = true;
                    break;
                }
            }


            AA_Message aa_message;
            aa_message.use_creature = item;
            for (size_t i = 0; i < menus.size(); i++) {
                uint32 menuid = menus[i];
                AA_Teleport_Conf conf = aaCenter.aa_teleports[menuid];
                if (conf.menuid != action || conf.is_visible == 2) {
                    continue;
                }
                if (conf.need > 0) {
                    if (!aaCenter.M_CanNeed(player, conf.need, 1, false) && conf.is_visible == 1) {
                        continue;
                    }
                }
                std::string title = aaCenter.GetMyInfo(player, conf.title, aa_message);
                if (p_conf.isOk) {
                    aaCenter.AA_GetPaihangInfo(title, p_conf);
                }
                std::string subtitle = conf.subtitle;
                if (subtitle != "") {
                    subtitle = aaCenter.GetMyInfo(player, subtitle, aa_message);
                    if (p_conf.isOk) {
                        aaCenter.AA_GetPaihangInfo(subtitle, p_conf);
                    }
                    if (conf.script == "兑换码" || conf.script == "招募" || conf.script == "变身" || conf.script == "解卡") {
                        AddGossipItemFor(player, GossipOptionNpc(conf.icon1), title, action, menuid, subtitle, 0, true);
                    }
                    else {
                        AddGossipItemFor(player, GossipOptionNpc(conf.icon1), title, action, menuid, subtitle, 0, false);
                    }
                }
                else {
                    if (conf.script == "兑换码" || conf.script == "招募" || conf.script == "变身" || conf.script == "解卡") {
                        AddGossipItemFor(player, GossipOptionNpc(conf.icon1), title, action, menuid, "", 0, true);
                    }
                    else {
                        AddGossipItemFor(player, GossipOptionNpc(conf.icon1), title, action, menuid);
                    }
                }
                pId = aaCenter.aa_teleports[conf.menuid].menuid;
            }
            if (action > 0) {
                AddGossipItemFor(player, GossipOptionNpc(0), "返回上一页", GOSSIP_SENDER_MAIN, pId);
            }

            player->TalkedToCreature(item->GetEntry(), item->GetGUID());
            SendGossipMenuFor(player, DEFAULT_GOSSIP_MESSAGE, item->GetGUID());
        }

        bool OnGossipHello(Player* player) override
        {
            Creature* item = me;
            if (!player || !player->IsInWorld() || !item || !item->IsInWorld()) {
                return false;
            }
            if (player && item) {
                vector<uint32> menus = aaCenter.aa_teleport_targets[item->GetEntry()];
                size_t size = menus.size();
                if (size == 0) {
                    return false;
                }
                if (size == 1) {
                    uint32 id = menus[0];
                    AA_Teleport_Conf conf = aaCenter.aa_teleports[id];
                    aaCenter.AA_TelScript(player, conf);
                    if (conf.notice > 0) {
                        AA_Message aa_message;
                        aa_message.use_creature = item;
                        AA_Notice notice = aaCenter.aa_notices[conf.notice];
                        aaCenter.AA_SendNotice(player, notice, true, aa_message);
                    }
                    return true;
                }
                else {
                    show_teleport(player, item, 0);
                }
            }
            return true; // Cast the spell on use normally
        }

        bool OnGossipSelect(Player* player, uint32 sender, uint32 action) override
        {
            Creature* item = me;
            //执行功能
            AA_Teleport_Conf conf = aaCenter.aa_teleports[action];
            if (player->IsInCombat() && (conf.gm.find("解除战斗") == std::string::npos && conf.is_zhandou == 0)) {
                aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000战斗中无法使用!");
                return false;
            }

            // 需要刷新当前页面 ，没有子菜单
            vector<uint32> menus = aaCenter.aa_teleport_targets[item->GetEntry()];
            bool isOk = false;
            for (size_t i = 0; i < menus.size(); i++) {
                uint32 menuid = menus[i];
                AA_Teleport_Conf conf = aaCenter.aa_teleports[menuid];
                if (conf.menuid == action)
                {
                    isOk = true;
                    break;
                }
            }
            if (isOk) {
                show_teleport(player, item, action);
            }
            else {
                show_teleport(player, item, sender);
            }

            aaCenter.AA_TelScript(player, conf);
            if (conf.notice > 0) {
                AA_Message aa_message;
                aa_message.use_creature = item;
                AA_Notice notice = aaCenter.aa_notices[conf.notice];
                aaCenter.AA_SendNotice(player, notice, true, aa_message);
            }
            // 需要关闭页面
            if (conf.script == "宝石拆卸1号" ||
                conf.script == "宝石拆卸2号" ||
                conf.script == "宝石拆卸3号" ||
                conf.script == "宝石一键拆卸x" ||
                conf.script == "装备解绑" ||
                conf.script == "使用物品成长券" ||
                conf.script == "使用物品强化券" ||
                conf.script == "使用物品鉴定券" ||
                conf.script == "装备合成") {
                CloseGossipMenuFor(player);
            }
            return true;
        }
        bool OnGossipSelectCode(Player* player, uint32 /*sender*/, uint32 action, const char* code) override
        {
            AA_Teleport_Conf conf = aaCenter.aa_teleports[action];
            if (conf.script == "兑换码") {
                std::string codestr = code;
                std::string gm = ".组合 *.兑换码 " + codestr + "<$自身>";
                aaCenter.AA_DoCommand(player, gm.c_str());
            }
            else if (conf.script == "招募") {
                std::string codestr = code;
                std::string gm = ".组合 *.招募 " + codestr + "<$自身>";
                aaCenter.AA_DoCommand(player, gm.c_str());
            }
            else if (conf.script == "变身") {
                std::string codestr = code;
                std::string gm = ".组合 *.变身 " + codestr + "<$自身>";
                aaCenter.AA_DoCommand(player, gm.c_str());
            }
            else if (conf.script == "解卡") {
                std::string codestr = code;
                std::string gm = ".组合 *.解卡 " + codestr + "<$自身>";
                aaCenter.AA_DoCommand(player, gm.c_str());
            }
            return true;
        }
    };
    
    CreatureAI* GetAI(Creature* creature) const override
    {
        return new aa_creature_teleportAI(creature);
    }
};

void AddAA_Creature_Teleport()
{
    new aa_creature_teleport();
}
