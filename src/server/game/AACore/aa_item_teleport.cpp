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

class aa_item_teleport : public ItemScript
{
private:
    void show_teleport(Player* player, Item* item, uint32 action) {
        // 传送石
        uint32 entry = item->GetEntry();
        vector<uint32> menus = aaCenter.aa_teleport_targets[entry];
        ClearGossipMenuFor(player); // Clears old options
        int pId = -1;
        AA_Message aa_message;
        aa_message.use_item = item;
        if (player->aa_target_item && player->aa_target_item->GetState() != ITEM_REMOVED && player->aa_target_item->IsInWorld()) {
            aa_message.target_item = player->aa_target_item;
        }
        
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
        
        SendGossipMenuFor(player, DEFAULT_GOSSIP_MESSAGE, item->GetGUID());
    }
public:
    aa_item_teleport() : ItemScript("aa_item_teleport") { }
    
    // Called when a player uses the item.
    bool OnUse(Player* player, Item* item, SpellCastTargets const& targets, ObjectGuid castId) override
    {
        if (!player || !player->IsInWorld() || !item || !item->IsInWorld()) {
            return false;
        }
        Item* target = targets.GetItemTarget();
        if (player && item) {
            //获取menus
            vector<uint32> menus = aaCenter.aa_teleport_targets[item->GetEntry()];
            size_t size = menus.size();
            if (size == 0) {
                return false;
            }
            //赋值 item 和 targetitem
            player->aa_item = item;
            if (target) {
                player->aa_target_item = target;
            } else {
                player->aa_target_item = nullptr;
            }
            //如果只有一项m，直接执行功能
            for (auto id : menus) {
                AA_Teleport_Conf conf = aaCenter.aa_teleports[id];
                if (conf.script == "宝石拆卸1号") {
                    if (player->aa_target_item) {
                        uint32 entry = aaCenter.AA_GetBaoshiEntry(player->aa_target_item, 0);
                        AA_Chaixie_Conf conf = aaCenter.aa_chaixie_confs[entry];
                        if (conf.itemid == 0) {
                            aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000该物品无法操作!");
                            player->aa_item = nullptr;
                            player->aa_target_item = nullptr;
                            return false;
                        }
                    } else {
                        aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000该物品无法操作!");
                        player->aa_item = nullptr;
                        player->aa_target_item = nullptr;
                        return false;
                    }
                } else if (conf.script == "装备合成") {
                    if (player->aa_target_item && player->aa_target_item->GetState() != ITEM_REMOVED && player->aa_target_item->IsInWorld()) {
                        uint32 entry = player->aa_target_item->GetEntry();
                        uint32 accountid = player->GetSession()->GetAccountId();
                        AA_Account a_conf = aaCenter.aa_accounts[accountid];
                        AA_Vip_Conf vconf = aaCenter.aa_vip_confs[a_conf.vip];
                        AA_Hecheng_Conf conf = aaCenter.aa_hecheng_confs[entry];
                        if (conf.itemid > 0) {
                            aaCenter.AA_SendMessage(player, 0, "╔┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈╗");
                            std::string item1 = aaCenter.aa_color_reds + "· 可合成为：" + aaCenter.AA_GetItemLink(conf.itemid1);
                            aaCenter.AA_SendMessage(player, 0, item1.c_str());
                            std::string jilv = aaCenter.aa_color_blues + "· 成功几率："+aaCenter.AA_StringFromFloat(conf.chance)+"%";
                            if (vconf.hecheng > 0) {
                                jilv = jilv + aaCenter.aa_color_green + "(" + "会员+" + aaCenter.AA_StringFromFloat(vconf.hecheng) + "%)";
                            }
                            aaCenter.AA_SendMessage(player, 0, jilv.c_str());
                            if (conf.destroy == 0) {
                                std::string msg = aaCenter.aa_color_red + "· 合成失败：物品被摧毁|r";
                                aaCenter.AA_SendMessage(player, 0, msg.c_str());
                            }
                            if (conf.is_baoliu == "是") {
                                std::string msg = aaCenter.aa_color_green + "· 成功奖励：" + aaCenter.aa_color_reds+"新物品继承原物品的附魔|r";
                                aaCenter.AA_SendMessage(player, 0, msg.c_str());
                            }
                            if (conf.need > 0) {
                                std::string need = aaCenter.AA_GetNeedText(conf.need);
                                if (need != "") {
                                    aaCenter.AA_StringReplace(need, "&", "\n");
                                    aaCenter.AA_SendMessage(player, 0, need.c_str());
                                }
                            }
                            aaCenter.AA_SendMessage(player, 0, "╚┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈╝");
                        } else {
                            aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000该物品无法操作!");
                            player->aa_item = nullptr;
                            player->aa_target_item = nullptr;
                            return false;
                        }
                    } else {
                        aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000该物品无法操作!");
                        player->aa_item = nullptr;
                        player->aa_target_item = nullptr;
                        return false;
                    }
                    break;
                }
                else if (conf.script == "物品回收") {
                    if (player->aa_target_item && player->aa_target_item->GetState() != ITEM_REMOVED && player->aa_target_item->IsInWorld()) {
                        AA_Huishou_Conf conf = aaCenter.AA_GetHuiShouConf(player, player->aa_target_item->GetGUIDLow(), player->aa_target_item->GetEntry());
                        if (conf.reward > 0) {
                            std::string reward = aaCenter.AA_GetRewardText(conf.reward);
                            if (reward != "") {
                                aaCenter.AA_SendMessage(player, 0, "╔┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈╗");
                                std::string itemstr = aaCenter.aa_color_reds + "· 当前回收物品：" + aaCenter.AA_GetItemLinkJd(player->aa_target_item);
                                aaCenter.AA_SendMessage(player, 0, itemstr.c_str());
                                std::string reward = aaCenter.AA_GetRewardText(conf.reward);
                                aaCenter.AA_StringReplace(reward, "&", "\n");
                                aaCenter.AA_SendMessage(player, 0, reward.c_str());
                                aaCenter.AA_SendMessage(player, 0, "╚┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈╝");
                            }
                        }
                        else {
                            aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000该物品无法操作!");
                            player->aa_item = nullptr;
                            player->aa_target_item = nullptr;
                            return false;
                        }
                    }
                    else {
                        aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000该物品无法操作!");
                        player->aa_item = nullptr;
                        player->aa_target_item = nullptr;
                        return false;
                    }
                }
            }
            if (size == 1) {
                uint32 id = menus[0];
                AA_Teleport_Conf conf = aaCenter.aa_teleports[id];
                aaCenter.AA_TelScript(player, conf);
                if (conf.notice > 0) {
                    AA_Message aa_message;
                    aa_message.use_item = item;
                    if (player->aa_target_item && player->aa_target_item->GetState() != ITEM_REMOVED && player->aa_target_item->IsInWorld()) {
                        aa_message.target_item = player->aa_target_item;
                    }
                    AA_Notice notice = aaCenter.aa_notices[conf.notice];
                    aaCenter.AA_SendNotice(player, notice, true, aa_message);
                }
                return true;
            } else {
                //否则显示菜单
                show_teleport(player, item, 0);
            }
        }
        return target != nullptr;
    }
    
    void OnGossipSelect(Player* player, Item* item, uint32 sender, uint32 action) override
    {
        //执行功能
        AA_Teleport_Conf conf = aaCenter.aa_teleports[action];
        if (player->IsInCombat() && (conf.gm.find("解除战斗") == std::string::npos && conf.is_zhandou == 0)) {
            aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000战斗中无法使用!");
            return;
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

        aaCenter.AA_TelScript(player, conf, item);
        if (conf.notice > 0) {
            AA_Message aa_message;
            aa_message.use_item = item;
            if (player->aa_target_item && player->aa_target_item->GetState() != ITEM_REMOVED && player->aa_target_item->IsInWorld()) {
                aa_message.target_item = item;
            }
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
            conf.script == "物品回收" ||
            conf.script == "召唤宠物") {
            CloseGossipMenuFor(player);
        }
    }
    
    void OnGossipSelectCode(Player* player, Item* /*item*/, uint32 /*sender*/, uint32 action, const char* code) override
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

void AddAA_Item_Teleport()
{
    new aa_item_teleport();
}
