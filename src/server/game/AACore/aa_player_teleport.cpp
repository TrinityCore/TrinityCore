#include "ObjectMgr.h"
#include "WorldSession.h"
#include "Configuration/Config.h"


#include "Define.h"
#include "GossipDef.h"
#include "Item.h"
#include "Spell.h"
#include "Player.h"
#include "ScriptedGossip.h"
#include "ScriptMgr.h"

using namespace std;

class aa_player_teleport : public PlayerScript
{
private:
    void show_teleport(Player* player, uint32 menu_id, uint32 action) {
        // 传送石
        uint32 entry = menu_id;
        vector<uint32> menus = aaCenter.aa_teleport_targets[entry];
        ClearGossipMenuFor(player); // Clears old options
        int pId = -1;
        AA_Message aa_message;
        //排名显示
        AA_Paihang p_conf;
        for (size_t i = 0;i<menus.size();i++) {
            uint32 menuid = menus[i];
            AA_Teleport_Conf conf = aaCenter.aa_teleports[menuid];
            if (conf.title.find("排行") != string::npos || conf.subtitle.find("排行") != string::npos) {
                p_conf = aaCenter.AA_GetPaihangs();
                p_conf.isOk = true;
                break;
            }
        }
        for (size_t i = 0;i<menus.size();i++) {
            uint32 menuid = menus[i];
            AA_Teleport_Conf conf = aaCenter.aa_teleports[menuid];
            if (conf.menuid != action || conf.is_visible == 2) {
                continue;
            }
            if (conf.need > 0) {
                if (!aaCenter.M_CanNeed(player, conf.need, 1 ,false) && conf.is_visible == 1) {
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
                } else {
                    AddGossipItemFor(player, GossipOptionNpc(conf.icon1), title, action, menuid, subtitle, 0, false);
                }
            } else {
                if (conf.script == "兑换码" || conf.script == "招募" || conf.script == "变身" || conf.script == "解卡") {
                    AddGossipItemFor(player, GossipOptionNpc(conf.icon1), title, action, menuid, "", 0, true);
                } else {
                    AddGossipItemFor(player, GossipOptionNpc(conf.icon1), title, action, menuid);
                }
            }
            pId = aaCenter.aa_teleports[conf.menuid].menuid;
        }
        if (action > 0) {
            AddGossipItemFor(player, GossipOptionNpc(0), "返回上一页", GOSSIP_SENDER_MAIN, pId);
        }
        SendGossipMenuFor(player, DEFAULT_GOSSIP_MESSAGE, player->GetGUID());
    }
public:
    aa_player_teleport() : PlayerScript("aa_player_teleport") { }
    void OnGossipSelect(Player* player, uint32 menu_id, uint32 sender, uint32 action) override
    {
        //执行功能
        AA_Teleport_Conf conf = aaCenter.aa_teleports[action];
        if (player->IsInCombat() && (conf.gm.find("解除战斗") == std::string::npos && conf.is_zhandou == 0)) {
            aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000战斗中无法使用!");
            return;
        }

        // 需要刷新当前页面 ，没有子菜单
        vector<uint32> menus = aaCenter.aa_teleport_targets[player->aa_menuId];
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
            show_teleport(player, player->aa_menuId, action);
        }
        else {
            show_teleport(player, player->aa_menuId, sender);
        }

        aaCenter.AA_TelScript(player, conf);
        if (conf.notice > 0) {
            AA_Message aa_message;
            AA_Notice notice = aaCenter.aa_notices[conf.notice];
            aaCenter.AA_SendNotice(player, notice, true, aa_message);
        }
        // 需要关闭页面  '装备解绑','使用物品成长券','使用物品强化券','使用物品鉴定券'
        if (conf.script == "宝石拆卸1号" ||
            conf.script == "宝石拆卸2号" ||
            conf.script == "宝石拆卸3号" ||
            conf.script == "宝石一键拆卸x" ||
            conf.script == "装备解绑" ||
            conf.script == "使用物品成长券" ||
            conf.script == "使用物品强化券" ||
            conf.script == "使用物品鉴定券" ||
            conf.script == "装备合成"  ||
            conf.script == "物品回收") {
            player->aa_menuId = 0;
            CloseGossipMenuFor(player);
        }
    }
    // Called when a player selects an option in a player gossip window
    void OnGossipSelectCode(Player* player, uint32 menu_id, uint32 sender, uint32 action, const char* code) override
    {
        AA_Teleport_Conf conf = aaCenter.aa_teleports[action];
        if (conf.script == "兑换码") {
            std::string codestr = code;
            std::string gm = ".组合 *.兑换码 "+codestr+"<$自身>";
            aaCenter.AA_DoCommand(player, gm.c_str());
        } else if (conf.script == "招募") {
            std::string codestr = code;
            std::string gm = ".组合 *.招募 "+codestr+"<$自身>";
            aaCenter.AA_DoCommand(player, gm.c_str());
        } else if (conf.script == "变身") {
            std::string codestr = code;
            std::string gm = ".组合 *.变身 "+codestr+"<$自身>";
            aaCenter.AA_DoCommand(player, gm.c_str());
        }
        else if (conf.script == "解卡") {
            std::string codestr = code;
            std::string gm = ".组合 *.解卡 " + codestr + "<$自身>";
            aaCenter.AA_DoCommand(player, gm.c_str());
        }
    }
};

void AddAA_Player_Teleport()
{
    new aa_player_teleport();
}
