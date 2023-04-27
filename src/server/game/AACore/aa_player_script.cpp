#include "ScriptMgr.h"
#include "ObjectMgr.h"
#include "Language.h"
#include "DisableMgr.h"
#include "WorldSession.h"
#include "Player.h"
#include "World.h"
#include "Guild.h"
#include "GuildMgr.h"


using namespace std;

class aa_player_script : public PlayerScript
{
public:
    aa_player_script() : PlayerScript("aa_player_script") { } 
    // CHARACTER_LOGIN = 8
    void OnLogin(Player* player, bool firstLogin) override
    {
        if (!player || !player->IsInWorld()/* || player->GetSession()->IsBot()*/) {
            return;
        }

        if (firstLogin) {
            //aawow出生光环
            uint32 accountid = player->GetSession()->GetAccountId();
            AA_Account conf = aaCenter.aa_accounts[accountid];
            AA_Message aa_message;
            AA_Notice notice = aaCenter.aa_notices[1];
            aaCenter.AA_SendNotice(player, notice, true, aa_message);
            // aawow 普通玩家奖励
            AA_Vip_Conf vipconf = aaCenter.aa_vip_confs[conf.vip];
            if (vipconf.add_reward > 0) {
                aaCenter.M_Reward(player, vipconf.add_reward);
            }
        }

        //玩家上线，刷新排行光环
        aaCenter.AA_UpdateJuanxianPaihang();
        //狂暴者上线提示
        if (aaCenter.aa_world_confs[83].value1 > 0) {
            if (player->isKuangbao || player->HasAura(aaCenter.aa_world_confs[83].value1)) {
                AA_Message aa_message;
                AA_Notice notice = aaCenter.aa_notices[24];
                aaCenter.AA_SendNotice(player, notice, true, aa_message);
            }
        }
        // aawow 自动加入公会
        if (!player->GetGuild() && aaCenter.aa_world_confs[6].value1 == 1) {
            uint32 blguild = aaCenter.aa_world_confs[5].value1;
            uint32 lmguild = aaCenter.aa_world_confs[4].value1;
            if (blguild > 0) {
                if (Guild* guild = sGuildMgr->GetGuildById(blguild)) {
                    if (player->GetTeamId() == TEAM_HORDE) {
                        CharacterDatabaseTransaction trans(nullptr);
                        guild->AddMember(trans, player->GetGUID());
                        std::string message = "|cff00FFFF[系统提示]|cffFFFF00你已加入公会["+guild->GetName()+"]";
                        sWorld->SendServerMessage(SERVER_MSG_STRING, message.c_str(), player);
                    }
                }
            }
            if (lmguild > 0) {
                if (Guild* guild = sGuildMgr->GetGuildById(lmguild)) {
                    if (player->GetTeamId() == TEAM_ALLIANCE) {
                        CharacterDatabaseTransaction trans(nullptr);
                        guild->AddMember(trans, player->GetGUID());
                        std::string message = "|cff00FFFF[系统提示]|cffFFFF00你已加入公会["+guild->GetName()+"]";
                        sWorld->SendServerMessage(SERVER_MSG_STRING, message.c_str(), player);
                    }
                }
            }
        }
        ObjectGuid::LowType guidlow = player->GetGUIDLow();
        uint32 accountid = player->GetSession()->GetAccountId();
        //排行数据表，初始化
        CharacterDatabase.PExecute("INSERT INTO _玩家排行数据x (guid, 每日战场击杀, 每日完成任务, update_time) VALUES ({}, 0, 0, 0) ON DUPLICATE KEY UPDATE update_time = 0,guid = {}", guidlow, guidlow);
        //aawow出生光环
        if (guidlow > 0) {
            {
                //变身
                std::string m_diy_guids = aaCenter.aa_characterss[guidlow].diy_guid;
                std::map<std::string, std::string> mdiy_guids; mdiy_guids.clear();
                aaCenter.AA_StringToStringMap(m_diy_guids, mdiy_guids);
                std::string displayidstr = mdiy_guids["modelid"];
                uint32 displayid = aaCenter.AA_StringUint32(displayidstr);
                std::string scalestr = mdiy_guids["scale"];
                float scale = aaCenter.AA_StringFloat(scalestr);
                if (displayid > 0 && displayid != player->GetDisplayId()) { //变身
                    player->SetDisplayId(displayid);
                    if (scale > 0) {
                        player->SetObjectScale(scale);
                    }
                }
            }
            {
                // 巅峰，斗气，军衔点数加成
                try {
                    AA_Characters_Dianfeng df_conf = aaCenter.aa_characters_dianfengs[guidlow];
                    AA_Characters_Douqi dq_conf = aaCenter.aa_characters_douqis[guidlow];
                    AA_Characters_Junxian jx_conf = aaCenter.aa_characters_junxians[guidlow];
                    if (df_conf.dianshu == -1) {
                        aaCenter.aa_characters_dianfengs[guidlow].dianshu = 0;
                    }
                    if (dq_conf.dianshu == -1) {
                        aaCenter.aa_characters_douqis[guidlow].dianshu = 0;
                    }
                    if (jx_conf.dianshu == -1) {
                        aaCenter.aa_characters_junxians[guidlow].dianshu = 0;
                    }
                    {
                        std::map<int32, int32> values; values.clear();
                        aaCenter.AA_StringToMap(df_conf.value, values);
                        for (auto itr : values) {
                            if (itr.second > 0) {
                                aaCenter.AddValue(player, itr.first, itr.second, true);
                            }
                        }
                    }
                    {
                        std::map<int32, int32> values; values.clear();
                        aaCenter.AA_StringToMap(dq_conf.value, values);
                        for (auto itr : values) {
                            if (itr.second > 0) {
                                aaCenter.AddValue(player, itr.first, itr.second, true);
                            }
                        }
                    }
                    {
                        std::map<int32, int32> values; values.clear();
                        aaCenter.AA_StringToMap(jx_conf.value, values);
                        for (auto itr : values) {
                            if (itr.second > 0) {
                                aaCenter.AddValue(player, itr.first, itr.second, true);
                            }
                        }
                    }
                } catch (std::exception const& e) { }
                
                {
                    std::vector<AA_Event_Map> mapeventconfs = aaCenter.aa_event_maps["玩家上线"];
                    for (auto mapconf : mapeventconfs) {
                        aaCenter.AA_EventMapStart(player, mapconf);
                    }
                }
            }
            {
                for (auto vipconf : aaCenter.aa_vip_confs) {
                    if (vipconf.second.spells != "" && vipconf.second.spells != "0") {
                        std::vector<int32> spellids; spellids.clear();
                        aaCenter.AA_StringToVectorInt(vipconf.second.spells, spellids, ",");
                        for (size_t i = 0; i<spellids.size(); i++) {
                            int32 spellid = spellids[i];
                            if (spellid == 0) {
                                continue;
                            }
                            if(player->HasAura(spellid)) {
                                player->RemoveAura(spellid);
                            }
                        }
                    }
                }
                AA_Account conf = aaCenter.aa_accounts[accountid];
                AA_Vip_Conf vipconf = aaCenter.aa_vip_confs[conf.vip];
                if (vipconf.spells != "" && vipconf.spells != "0") {
                    std::vector<int32> spellids; spellids.clear();
                    aaCenter.AA_StringToVectorInt(vipconf.spells, spellids, ",");
                    for (size_t i = 0; i < spellids.size(); i++) {
                        int32 spellid = spellids[i];
                        if (spellid == 0) {
                            continue;
                        }
                        player->AddAura(spellid, player);
                    }
                }
                if (conf.vip > 0) {
                    AA_Message aa_message;
                    AA_Notice notice = aaCenter.aa_notices[3];
                    aaCenter.AA_SendNotice(player, notice, true, aa_message);
                } else {
                    AA_Message aa_message;
                    AA_Notice notice = aaCenter.aa_notices[2];
                    aaCenter.AA_SendNotice(player, notice, true, aa_message);
                }
            }
            {
                for (auto vipconf : aaCenter.aa_junxian_confs) {
                    if (vipconf.second.spells != "" && vipconf.second.spells != "0") {
                        std::vector<int32> spellids; spellids.clear();
                        aaCenter.AA_StringToVectorInt(vipconf.second.spells, spellids, ",");
                        for (size_t i = 0; i<spellids.size(); i++) {
                            int32 spellid = spellids[i];
                            if (spellid == 0) {
                                continue;
                            }
                            if(player->HasAura(spellid)) {
                                player->RemoveAura(spellid);
                            }
                        }
                    }
                }
                AA_Characters_Junxian conf = aaCenter.aa_characters_junxians[guidlow];
                if (conf.level > 0) {
                    AA_Junxian_Conf vipconf = aaCenter.aa_junxian_confs[conf.level];
                    if (vipconf.spells != "" && vipconf.spells != "0") {
                        std::vector<int32> spellids; spellids.clear();
                        aaCenter.AA_StringToVectorInt(vipconf.spells, spellids, ",");
                        for (size_t i = 0; i<spellids.size(); i++) {
                            int32 spellid = spellids[i];
                            if (spellid == 0) {
                                continue;
                            }
                            player->AddAura(spellid, player);
                        }
                    }
                }
            }
            {
                for (auto vipconf : aaCenter.aa_douqi_confs) {
                    if (vipconf.second.spells != "" && vipconf.second.spells != "0") {
                        std::vector<int32> spellids; spellids.clear();
                        aaCenter.AA_StringToVectorInt(vipconf.second.spells, spellids, ",");
                        for (size_t i = 0; i<spellids.size(); i++) {
                            int32 spellid = spellids[i];
                            if (spellid == 0) {
                                continue;
                            }
                            if(player->HasAura(spellid)) {
                                player->RemoveAura(spellid);
                            }
                        }
                    }
                }
                AA_Characters_Douqi conf = aaCenter.aa_characters_douqis[guidlow];
                if (conf.level > 0) {
                    AA_Douqi_Conf vipconf = aaCenter.aa_douqi_confs[conf.level];
                    if (vipconf.spells != "" && vipconf.spells != "0") {
                        std::vector<int32> spellids; spellids.clear();
                        aaCenter.AA_StringToVectorInt(vipconf.spells, spellids, ",");
                        for (size_t i = 0; i<spellids.size(); i++) {
                            int32 spellid = spellids[i];
                            if (spellid == 0) {
                                continue;
                            }
                            player->AddAura(spellid, player);
                        }
                    }
                }
            }
            {
                for (auto vipconf : aaCenter.aa_dianfeng_confs) {
                    if (vipconf.second.spells != "" && vipconf.second.spells != "0") {
                        std::vector<int32> spellids; spellids.clear();
                        aaCenter.AA_StringToVectorInt(vipconf.second.spells, spellids, ",");
                        for (size_t i = 0; i<spellids.size(); i++) {
                            int32 spellid = spellids[i];
                            if (spellid == 0) {
                                continue;
                            }
                            if(player->HasAura(spellid)) {
                                player->RemoveAura(spellid);
                            }
                        }
                    }
                }
                AA_Characters_Dianfeng conf = aaCenter.aa_characters_dianfengs[guidlow];
                if (conf.level > 0) {
                    AA_Dianfeng_Conf vipconf = aaCenter.aa_dianfeng_confs[conf.level];
                    if (vipconf.spells != "" && vipconf.spells != "0") {
                        std::vector<int32> spellids; spellids.clear();
                        aaCenter.AA_StringToVectorInt(vipconf.spells, spellids, ",");
                        for (size_t i = 0; i<spellids.size(); i++) {
                            int32 spellid = spellids[i];
                            if (spellid == 0) {
                                continue;
                            }
                            player->AddAura(spellid, player);
                        }
                    }
                }
            }
        }
    }
    // CHARACTER_LOGOUT = 9
    void OnLogout(Player* player) override
    {
        if (!player)
        {
            return;
        }

        //析构参数
        ObjectGuid guid = player->GetGUID();
        aaCenter.aa_allsetitems.erase(guid);
        aaCenter.aa_allsetitems1.erase(guid);
        aaCenter.aa_allsetspells_old.erase(guid);
        aaCenter.aa_allsetspells_new.erase(guid);
        aaCenter.aa_allspells.erase(guid);
        aaCenter.aa_allspells1.erase(guid);
        aaCenter.aa_allitemspells.erase(guid);
        aaCenter.aa_allitemspells1.erase(guid);
        aaCenter.aa_allitems.erase(guid);
        aaCenter.aa_allitems1.erase(guid);
        aaCenter.aa_vendor_guid.erase(guid);
        aaCenter.m_aiTimes.erase(guid);
        aaCenter.m_aiGGTimes.erase(guid);

        if (!player || !player->IsInWorld()/* || player->GetSession()->IsBot()*/) {
            return;
        }
    }
    void OnUpdateArea(Player* player, uint32 oldArea, uint32 newArea) override
    {
        player->UpdateAllStats();
    }
    void OnUpdateZone(Player* player, uint32 newZone, uint32 /*newArea*/) override
    {
        player->UpdateAllStats();
    }
};

void AddAA_player_Script()
{
    new aa_player_script();
}
