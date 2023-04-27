/*
 经济套餐a1ba2ba3ba4ba5ba6ba7ba8b
 a1b累计充值奖励
 a2b个人理财奖励
 a3b每日首充奖励
 a4b高级升级奖励
 a5b超级Ai系统
 a6b超级GM命令
 a7b暗黑成长
 a8b暗黑符文

 至尊套餐a1ba2ba3ba4ba5ba6ba7ba8ba100ba101ba102ba103b
 a100b高级幸运抽奖
 a101b副本闯关奖励
 a102b生物伤害排行
 a103b暗黑萃取
 a104b翻牌
 a105b商城

 其他定制
 a200b排行榜奖励
 a201b暗黑机器人
 a202b每日购买次数
 a203b合成保留附魔宝石
 a204b成就点数货币
 a205b觉醒属性400+
 a206b野外平衡战场
 a207b排行光环
 a208b队伍光环
 a209b觉醒卡牌
 
 */



#include "AACenter.h"
#include "Chat.h"
#include "WorldSession.h"
#include "GroupMgr.h"
#include "Player.h"
#include "Language.h"
#include "GameEventMgr.h"
#include "Pet.h"
#include "Creature.h"
#include "Object.h"
#include "SpellInfo.h"
#include "SpellAuras.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"
#include "CellImpl.h"
#include "LootItemStorage.h"
#include "AAData.h"
#include "Configuration/Config.h"
#include "AchievementMgr.h"
#include "World.h"
#include "Realm.h"
#include "GameTime.h"
#include "ArenaTeam.h"
#include "Group.h"
#include "ObjectAccessor.h"
#include "Bag.h"
#include "MapManager.h"
#include "DuelPackets.h"
#include "LFGMgr.h"
#include "Loot.h"
#include "SpellHistory.h"
#include "Player.h"

#include <iostream>
#include <sstream>

//竞技场
#include "ArenaTeamMgr.h"
#include "DisableMgr.h"
#include "BattlegroundMgr.h"
#include "Battleground.h"
#include "BattlegroundQueue.h"
#include "ArenaTeam.h"

using namespace std;

#define MSG_COLOR_DRUID        "|cffff7d0a"
#define MSG_COLOR_HUNTER       "|cffabd473"
#define MSG_COLOR_MAGE         "|cff69ccf0"
#define MSG_COLOR_PALADIN      "|cfff58cba"
#define MSG_COLOR_PRIEST       "|cffffffff"
#define MSG_COLOR_ROGUE        "|cfffff569"
#define MSG_COLOR_SHAMAN       "|cff0070de"
#define MSG_COLOR_WARLOCK      "|cff9482c9"
#define MSG_COLOR_WARRIOR      "|cffc79c6e"
#define MSG_COLOR_DEATH_KNIGHT "|cffc41f3b"
#define MSG_COLOR_MONK         "|cff00ff96"

constexpr uint32 ARENA_TEAM_5V5 = 5;

bool cmpbiwu(pair<ObjectGuid::LowType, uint32> a, pair<ObjectGuid::LowType, uint32> b) {
    return a.second > b.second;
}

bool cmp(pair<ObjectGuid, uint32> a, pair<ObjectGuid, uint32> b) {
    return a.second > b.second;
}

void paihangbiwu(std::vector<std::pair<ObjectGuid::LowType, uint32>>& v, std::map<ObjectGuid::LowType, uint32> mp)
{
    std::vector< pair<ObjectGuid::LowType, uint32> > vec; vec.clear();
    for (std::map<ObjectGuid::LowType, uint32>::iterator it = mp.begin(); it != mp.end(); it++) {
        vec.push_back(pair<ObjectGuid::LowType, uint32>(it->first, it->second));
    }
    sort(vec.begin(), vec.end(), cmpbiwu);
    v = vec;
}

void paihangpx(std::vector<std::pair<ObjectGuid, uint32>>& v, std::map<ObjectGuid, uint32> mp)
{
    std::vector< pair<ObjectGuid, uint32> > vec; vec.clear();
    for (std::map<ObjectGuid, uint32>::iterator it = mp.begin(); it != mp.end(); it++) {
        vec.push_back(pair<ObjectGuid, uint32>(it->first, it->second));
    }
    sort(vec.begin(), vec.end(), cmp);
    v = vec;
}

//野外战场
//std::unordered_map<uint32, uint32>
bool yewai_cmp(pair<uint32, uint32> a, pair<uint32, uint32> b) {
    return a.second > b.second;
}

void yewai_paihangpx(std::vector<std::pair<uint32, uint32>>& v, std::map<uint32, uint32> mp)
{
    std::vector< pair<uint32, uint32> > vec; vec.clear();
    for (std::map<uint32, uint32>::iterator it = mp.begin(); it != mp.end(); it++) {
        vec.push_back(pair<uint32, uint32>(it->first, it->second));
    }
    sort(vec.begin(), vec.end(), yewai_cmp);
    v = vec;
}

void zudui_paihangpx(std::vector<std::pair<uint32, uint32>>& v, std::map<int32, int32> mp)
{
    std::vector< pair<uint32, uint32> > vec; vec.clear();
    for (std::map<int32, int32>::iterator it = mp.begin(); it != mp.end(); it++) {
        vec.push_back(pair<uint32, uint32>(it->first, it->second));
    }
    sort(vec.begin(), vec.end(), yewai_cmp);
    v = vec;
}


void AACenter::Update(Unit* unit, uint32 diff)
{
    if (!unit || !unit->IsInWorld() || (unit->GetTypeId() != TYPEID_PLAYER && unit->GetTypeId() != TYPEID_UNIT)) {
        return;
    }

    if (Player* p = unit->ToPlayer()) {
        {
            //狂暴者
            p->isKuangbao = false;
            if (aaCenter.aa_world_confs[83].value1 > 0) {
                if (p->HasAura(aaCenter.aa_world_confs[83].value1)) {
                    p->isKuangbao = true;
                }
            }
            //排名光环
            if (aaCenter.AA_VerifyCode("a303b")) {
                ObjectGuid::LowType guidlow = p->GetGUIDLow();
                uint32 paiming = aaCenter.aa_juanxian_players[guidlow];
                if (paiming > 0) {
                    AA_UI_Juanxian_Paiming conf = aaCenter.aa_ui_juanxian_paimings[paiming];
                    if (conf.guanghuans != "" && conf.guanghuans != "0") {
                        std::vector<int32> spells; spells.clear();
                        aaCenter.AA_StringToVectorInt(conf.guanghuans, spells, ",");
                        for (auto spell : spells) {
                            if (!p->HasAura(spell)) {
                                p->AddAura(spell, p);
                            }
                        }
                    }
                }
                for (size_t i = 1; i < 6; i++)
                {
                    AA_UI_Juanxian_Paiming conf = aaCenter.aa_ui_juanxian_paimings[i];
                    if (paiming == i) {
                        continue;
                    }
                    if (conf.guanghuans != "" && conf.guanghuans != "0") {
                        std::vector<int32> spells; spells.clear();
                        aaCenter.AA_StringToVectorInt(conf.guanghuans, spells, ",");
                        for (auto spell : spells) {
                            if (p->HasAura(spell)) {
                                p->RemoveAura(spell);
                            }
                        }
                    }
                }
                //排名数量光环
                if (aaCenter.aa_character_juanxians.find(guidlow) != aaCenter.aa_character_juanxians.end())
                {
                    AA_Character_Juanxian conf = aaCenter.aa_character_juanxians[guidlow];
                    if (conf.juanxian > 0) {
                        for (auto itr : aaCenter.aa_ui_juanxian_shuliangs) {
                            AA_UI_Juanxian_Shuliang jconf = itr.second;
                            std::vector<int32> spells; spells.clear();
                            if (jconf.guanghuans != "" && jconf.guanghuans != "0") {
                                aaCenter.AA_StringToVectorInt(jconf.guanghuans, spells, ",");
                            }
                            if (jconf.id > 0 && conf.juanxian >= jconf.id) {
                                for (auto it : spells) {
                                    if (!p->HasAura(it)) {
                                        p->AddAura(it, p);
                                    }
                                }
                            }
                            else {
                                for (auto it : spells) {
                                    if (p->HasAura(it)) {
                                        p->RemoveAura(it);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        //组队奖励光环
        {
            if (aaCenter.AA_VerifyCode("a208b")) {
                if (aaCenter.aa_world_confs[88].value2 != "") {
                    std::map<int32, int32> m; m.clear();
                    aaCenter.AA_StringToMap(aaCenter.aa_world_confs[88].value2, m);
                    if (p->GetGroup()) {
                        std::map<std::string, uint32> address_counts; address_counts.clear();
                        Group::MemberSlotList const& members = p->GetGroup()->GetMemberSlots();
                        uint32 count = 0;
                        for (Group::MemberSlotList::const_iterator itr = members.begin(); itr != members.end(); ++itr)
                        {
                            if (Player* player = ObjectAccessor::FindPlayer((*itr).guid)) {
                                if (!player->IsInWorld()) { continue; }
                                if (aaCenter.aa_world_confs[88].value1 > 0) {
                                    std::string ip = player->GetSession()->GetRemoteAddress();
                                    if (ip != "") {
                                        address_counts[ip]++;
                                        if (address_counts[ip] > aaCenter.aa_world_confs[88].value1) {
                                            continue;
                                        }
                                    }
                                }
                                count++;
                            }
                        }
                        std::vector<std::pair<uint32, uint32>> m1; m1.clear();
                        zudui_paihangpx(m1, m);
                        uint32 spell_old = 0;
                        for (uint32 i = 0; i < m1.size(); i++) {
                            std::pair<uint32, uint32> sc = m1[i];
                            uint32 count1 = sc.first;
                            uint32 spellid = sc.second;
                            if (count >= count1) {
                                if (spellid > 0) {
                                    if (!p->HasAura(spellid)) {
                                        p->AddAura(spellid, p);
                                    }
                                }
                                if (spell_old > 0) {
                                    if (p->HasAura(spellid)) {
                                        p->RemoveAura(spellid);
                                    }
                                }
                                spell_old = spellid;
                            }
                            else {
                                if (spellid > 0) {
                                    if (p->HasAura(spellid)) {
                                        p->RemoveAura(spellid);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        //双甲系统光环
        {
            std::vector<ObjectGuid::LowType> guids = aa_item_instance_owner[p->GetGUIDLow()];
            std::map<int32, int32> items; items.clear();
            if (guids.size() > 0) {
                for (auto it : guids) {
                    AA_Item_Instance conf = aaCenter.aa_item_instances[it];
                    if (conf.weizhi != "") {
                        std::map<int32, int32> m; m.clear();
                        aaCenter.AA_StringToMap(conf.weizhi, m);
                        int32 lan = m.begin()->first;
                        int32 index = m.begin()->second;
                        if (m.begin()->first > 0 && m.begin()->second > 0) {
                            items[lan] = items[lan] + 1;
                        }
                    }
                }
            }
            for (auto it : items) {
                int32 lan = it.first;
                int32 count = it.second;
                AA_Item_Shuangjia conf = aaCenter.aa_item_shuangjias[lan];
                if (conf.items != "" && conf.guanghuans != "") {
                    std::vector<int32> v; v.clear();
                    aaCenter.AA_StringToVectorInt(conf.items, v, ",");
                    int32 c = v.size();
                    if (c > 0) {
                        if (c == count) {
                            std::vector<int32> spells; spells.clear();
                            aaCenter.AA_StringToVectorInt(conf.guanghuans, spells, ",");
                            if (spells.size() > 0) {
                                for (auto itr : spells) {
                                    if (itr > 0) {
                                        if (!p->HasAura(itr)) {
                                            p->AddAura(itr, p);
                                        }
                                    }
                                }
                            }
                        }
                        else {
                            std::vector<int32> spells; spells.clear();
                            aaCenter.AA_StringToVectorInt(conf.guanghuans, spells, ",");
                            if (spells.size() > 0) {
                                for (auto itr : spells) {
                                    if (itr > 0) {
                                        if (p->HasAura(itr)) {
                                            p->RemoveAura(itr);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }

            }
        }
        AA_Map_Player_Conf map_conf = aaCenter.AA_GetAA_Map_Player_Conf(p);
        //更新阵营平衡光环
        if (lmcount || blcount) {
            std::vector<int32> spellids1; spellids1.clear();
            std::vector<int32> spellids2; spellids2.clear();
            if (aaCenter.aa_world_confs[86].value2 != "") {
                aaCenter.AA_StringToVectorInt(aaCenter.aa_world_confs[86].value2, spellids1, ",");
            }
            if (aaCenter.aa_world_confs[87].value2 != "") {
                aaCenter.AA_StringToVectorInt(aaCenter.aa_world_confs[87].value2, spellids2, ",");
            }
            if (spellids1.size() || spellids2.size()) {
                if (p->GetTeamId() == TEAM_ALLIANCE) { //联盟
                    if (lmcount > blcount) {
                        for (auto spellid : spellids2) { //联盟人多，给多的BUFF联盟
                            if (!p->HasAura(spellid)) {
                                p->AddAura(spellid, p);
                            }
                        }
                        for (auto spellid : spellids1) { //联盟人多，取消联盟少的buff
                            if (p->HasAura(spellid)) {
                                p->RemoveAura(spellid);
                            }
                        }
                    }
                    else if (lmcount < blcount) {
                        for (auto spellid : spellids1) { //联盟人少，给少的BUFF联盟
                            if (!p->HasAura(spellid)) {
                                p->AddAura(spellid, p);
                            }
                        }
                        for (auto spellid : spellids2) { //联盟人少，取消联盟多的buff
                            if (p->HasAura(spellid)) {
                                p->RemoveAura(spellid);
                            }
                        }
                    }
                    else if (blcount && lmcount == blcount) { //人数一样，取消所有buff
                        for (auto spellid : spellids1) {
                            if (p->HasAura(spellid)) {
                                p->RemoveAura(spellid);
                            }
                        }
                        for (auto spellid : spellids2) { //部落人多，取消部落少的buff
                            if (p->HasAura(spellid)) {
                                p->RemoveAura(spellid);
                            }
                        }
                    }
                }
                else if (p->GetTeamId() == TEAM_HORDE) { //部落
                    if (lmcount > blcount) {
                        for (auto spellid : spellids1) { //部落人少，给少的BUFF部落
                            if (!p->HasAura(spellid)) {
                                p->AddAura(spellid, p);
                            }
                        }
                        for (auto spellid : spellids2) { //部落人少，取消部落多的buff
                            if (p->HasAura(spellid)) {
                                p->RemoveAura(spellid);
                            }
                        }
                    }
                    else if (lmcount < blcount) {
                        for (auto spellid : spellids2) { //部落人多，给多的BUFF部落
                            if (!p->HasAura(spellid)) {
                                p->AddAura(spellid, p);
                            }
                        }
                        for (auto spellid : spellids1) { //部落人多，取消部落少的buff
                            if (p->HasAura(spellid)) {
                                p->RemoveAura(spellid);
                            }
                        }
                    }
                    else if (blcount && lmcount == blcount) { //人数一样，取消所有buff
                        for (auto spellid : spellids1) {
                            if (p->HasAura(spellid)) {
                                p->RemoveAura(spellid);
                            }
                        }
                        for (auto spellid : spellids2) { //部落人多，取消部落少的buff
                            if (p->HasAura(spellid)) {
                                p->RemoveAura(spellid);
                            }
                        }
                    }
                }
            }
        }

        if (aaCenter.aa_world_confs[85].value1 > 0) {
            if (p->HasAura(aaCenter.aa_world_confs[85].value1) && p->GetAreaId() != 876) { //小黑屋传送
                p->TeleportTo(1, 16222.1, 16252.1, 12.5872, 0);
            }
        }

        if (aaCenter.aa_bianshen3[p->GetGUIDLow()] > 1) {
            if (aaCenter.aa_bianshen3[p->GetGUIDLow()] > diff) {
                aaCenter.aa_bianshen3[p->GetGUIDLow()] -= diff;
            }
            else {
                aaCenter.aa_bianshen3[p->GetGUIDLow()] = 1;
            }
        }
        if (aaCenter.aa_bianshen3[p->GetGUIDLow()] == 0 || aaCenter.aa_bianshen3[p->GetGUIDLow()] > 1) { //0永久变身 1临时变身
            if (uint32 displayid = aa_bianshen1[p->GetGUIDLow()]) {
                if (displayid != p->GetDisplayId()) { //变身
                    p->SetDisplayId(displayid);
                    float scale = aa_bianshen2[p->GetGUIDLow()];
                    if (scale > 0) {
                        p->SetObjectScale(scale);
                    }
                }
            }
        }
        else { //变身还原
            if (aaCenter.aa_bianshen1[p->GetGUIDLow()] != 0 && aaCenter.aa_bianshen2[p->GetGUIDLow()] != 0) {
                aaCenter.aa_bianshen1[p->GetGUIDLow()] = 0;
                aaCenter.aa_bianshen2[p->GetGUIDLow()] = 0;
                p->RestoreDisplayId();
                p->SetObjectScale(1);

                std::string gm = ".组合 *.变量 角色 modelid =0<$自身>";
                aaCenter.AA_DoCommand(p, gm.c_str());
                gm = ".组合 *.变量 角色 scale =0<$自身>";
                aaCenter.AA_DoCommand(p, gm.c_str());
            }
        }
        if (p->vendorSummonTime > 0) { //取消随身商人
            p->vendorSummonTime -= diff;
            if (p->vendorSummonTime <= 0) {
                p->vendorSummonTime = 0;
                Unit* pet = ObjectAccessor::GetCreatureOrPetOrVehicle(*p, p->GetCritterGUID());
                if (pet && pet->IsInWorld() && pet->GetEntry() == 36911)
                {
                    if (pet->GetTypeId() == TYPEID_UNIT && pet->IsSummon())
                        pet->ToTempSummon()->UnSummon();
                }
            }
        }

        //光环加百分比，只对玩家有效
        for (auto itr : aaCenter.aa_aura_confs) { //_属性调整_光环
            AA_Aura_Conf conf = itr.second;
            if (conf.spellid > 0 && conf.values != "" && conf.values != "0") {
                uint32 count = 1;
                if (p->HasAura(conf.spellid)) {
                    count = p->GetAuraCount(conf.spellid); //应有数量
                }
                else {
                    count = 0;
                }
                uint32 count1 = p->aa_aura_values[conf.spellid]; //当前数量
                if (count > 0 && count1 < count) { //如果有光环，并且当前数量小于应有数量 ，增加属性
                    uint32 c = count - count1;
                    std::map<int32, int32> values;
                    aaCenter.AA_StringToMap(conf.values, values);
                    for (auto v : values) {
                        if (v.second > 0) {
                            aaCenter.AddValue(p, v.first, v.second * c, true);
                        }
                    }
                    p->aa_aura_values[conf.spellid] = count;
                }
                else if (count1 > 0 && count1 > count) { //如果当前数量大于0，并且当前数量大于应有数量，减少属性
                    uint32 c = count1 - count;
                    std::map<int32, int32> values;
                    aaCenter.AA_StringToMap(conf.values, values);
                    for (auto v : values) {
                        if (v.second > 0) {
                            aaCenter.AddValue(p, v.first, v.second * c, false);
                        }
                    }
                    p->aa_aura_values[conf.spellid] = count;
                }
            }
        }

        ObjectGuid::LowType guidlow = p->GetGUIDLow();
        p->aa_lj_time += diff;
        p->aa_zhenshi_time += diff;
        p->aa_xixue_time += diff;
        std::vector<AA_Event_Map> mapeventconfs = aaCenter.aa_event_maps["累计时间"];
        if (Map* map = p->GetMap()) {
            for (auto conf : mapeventconfs) {
                if (map->aa_map_time_status[guidlow][conf.value] == false) {
                    if ((conf.mapid == -1 && conf.zoneid == -1 && conf.areaid == -1) ||
                        (int32)p->GetMapId() == conf.mapid ||
                        (int32)p->GetZoneId() == conf.zoneid ||
                        (int32)p->GetAreaId() == conf.areaid) {
                        uint32 mapid = map->GetId();
                        uint32 nanduid = map_conf.nanduid;
                        aaCenter.aa_map_times[mapid][nanduid] += diff;
                        uint32 time = aaCenter.aa_map_times[mapid][nanduid];
                        if (conf.value > 0 && time >= uint32(conf.value * 1000)) {
                            aaCenter.AA_EventMapStart(p, conf);
                            map->aa_map_time_status[guidlow][conf.value] = true;
                        }
                    }
                }
            }
        }

        { //刷新副本通关显示
            if (aaCenter.AA_VerifyCode("a101b")) {
                if (map_conf.dietime > 0 || map_conf.xianzhitime > 0 || (map_conf.jindu_exp != "" && map_conf.jindu_exp != "0") || (map_conf.jindu_reward != "" && map_conf.jindu_reward != "0")) {
                    if (map_conf.m_xianzhitime && map_conf.m_xianzhitime < 2 * diff) {
                        aaCenter.M_SendMap_Jindu(p);
                    }
                    p->jindu_time += diff;
                    if (p->jindu_time >= 5000) {
                        p->jindu_time = 0;
                        aaCenter.M_SendMap_Jindu(p);
                    }
                }
            }
        }
        if (!p->IsGameMaster()) {
            //防脚本
            if (aaCenter.aa_world_confs[33].value1 == 1) {
                std::vector<int32> maps; maps.clear();
                aaCenter.AA_StringToVectorInt(aaCenter.aa_world_confs[32].value2, maps, ",");
                if (aaCenter.aa_world_confs[32].value2 == "" || std::find(maps.begin(), maps.end(), p->GetAreaId()) == maps.end()) {
                    uint32 fgj = aaCenter.aa_world_confs[31].value1 * 1000 * 60;//分钟转毫秒
                    //防挂机检测，达到挂机时间后，每30秒发送验证框
                    if (p->guajiTime > fgj) {
                        p->guajiyanzhengtime += diff;
                        if (p->guajiyanzhengtime >= 30 * 1000) {
                            p->guajiyanzhengtime = 0;
                            uint32 codeindex = rand() % 618 + 1;
                            p->codeindex = codeindex;
                            aaCenter.M_SendClientAddonData(p, "301", std::to_string(codeindex));
                        }
                    }
                    bool isOK = false;
                    //拾取次数
                    uint32 maxcount = aaCenter.AA_StringUint32(aaCenter.aa_world_confs[31].value2);
                    if (maxcount > 0 && p->lootcount >= maxcount) {
                        isOK = true;
                    }
                    //挂机时间
                    p->guajiTime += diff;
                    if (p->guajiTime > fgj && p->m_guajis["Script"] == false) { //满足时间条件，发送弹窗
                        isOK = true;
                    }
                    if (isOK) { //满足条件后，2分钟内不处理，并且不在检测区，掉线
                        p->codetime += diff;
                        if (p->codetime > 120 * 1000) { //验证框出现后2分钟内不点踢出玩家
                            p->codetime = 0;
                            if (aaCenter.aa_world_confs[30].value2 == "0" || aaCenter.aa_world_confs[30].value2 == "") {
                                p->GetSession()->KickPlayer("kick");
                            }
                            else {
                                if (aaCenter.aa_world_confs[30].value2 != "" && aaCenter.aa_world_confs[30].value2 != "0") {
                                    aaCenter.AA_DoCommand(p, aaCenter.aa_world_confs[30].value2.c_str());
                                }
                            }
                        }
                    }
                    else {
                        p->codetime = 0;
                    }
                }
            }
        }
        {
            // aawow 快速点击间隔时间
            p->combatTime = p->combatTime + diff;
            if (p->combatTime > 9000000) { p->combatTime = 0; }
        }
        {
            // aawow 快速点击间隔时间
            p->clickTime = p->clickTime + diff;
            if (p->clickTime > 9000000) { p->clickTime = 0; }
        }
        // 泡点奖励
        {
            for (auto itr : p->paodianTimes) {
                p->paodianTimes[itr.first] += diff;
            }
            std::vector<AA_Event_Map> mapeventconfs = aaCenter.aa_event_maps["间隔时间"];
            for (auto mapconf : mapeventconfs) {
                bool isReward = false;
                if (p->paodianTimes[mapconf.id] >= uint32(mapconf.value * 1000)) {
                    aaCenter.AA_EventMapStart(p, mapconf);
                    p->paodianTimes[mapconf.id] = 0;
                    isReward = true;
                }
                if (isReward && p->IsInWorld()) {
                    // vip 额外触发活动
                    uint32 accountid = p->GetSession()->GetAccountId();
                    AA_Account a_conf = aaCenter.aa_accounts[accountid];
                    AA_Vip_Conf vipconf = aaCenter.aa_vip_confs[a_conf.vip];
                    if (vipconf.paodian > 0) {
                        aaCenter.M_Reward(p, vipconf.paodian);
                    }
                }
            }
        }
        {
            // 累计奖励
            p->leijiTime = p->leijiTime + diff;
            if (p->leijiTime > 30000) {
                p->leijiTime = 0;
                try {
                    {
                        //每30秒触发，发放累计时长奖励
                        //获取上次领取奖励的时间
                        ObjectGuid::LowType guidlow = p->GetGUIDLow();
                        uint32 time_o = aaCenter.aa_characterss[guidlow].playtime;
                        //获取累计登录时间
                        uint32 ljtime = p->GetTotalPlayedTime();
                        //获取下次领取的奖励
                        AA_Event_Playtime tconf;
                        for (auto tconf1 : aaCenter.aa_event_playtimes) {
                            //累计登录时间》奖励时间  奖励时间》上次领取奖励时间
                            if (tconf1.time > 0 && ljtime >= tconf1.time * 60 && tconf1.time > time_o) {
                                tconf = tconf1;
                                break;
                            }
                        }
                        if (tconf.time > 0 && tconf.gm != "" && tconf.gm != "0") {
                            aaCenter.aa_characterss[guidlow].playtime = tconf.time;
                            aaCenter.AA_DoCommand(p, tconf.gm.c_str());
                        }
                    }
                }
                catch (std::exception const& e) {}
            }
        }
        {
            //aawow 地图限制pvp状态
            AA_Map_Player_Conf conf = aaCenter.AA_GetAA_Map_Player_Conf(p);
            if (conf.GroupOnOff == 1) {// 是否允许组队
                if (p->GetGroup()) {
                    p->RemoveFromGroup();
                }
            }
            if (conf.FlyOnOff == 1) {// 是否允许飞行
                p->SetCanFly(false);
            }
            if (conf.need > 0) {//条件需求 传送到新手区域
                if (!aaCenter.M_CanNeed(p, conf.need)) {
                    p->TeleportTo(p->m_homebind.GetMapId(), p->m_homebind.GetPositionX(), p->m_homebind.GetPositionY(), p->m_homebind.GetPositionZ(), p->GetOrientation());
                }
            }
        }
    }
    else if (Creature* creature = unit->ToCreature()) {
        { //boss排行
            if (aaCenter.AA_VerifyCode("a102b")) {
                if (creature->aa_boss_id > 0) {
                    AA_Boss_Conf conf = aaCenter.aa_boss_confs[creature->aa_boss_id];
                    if (conf.reward != "" && conf.reward != "0") {
                        aaCenter.aa_boss_time[creature->GetGUIDLow()] += diff;
                        creature->aa_boss_time += diff;
                        if (aaCenter.aa_boss_time[creature->GetGUIDLow()] >= 5000) {
                            aaCenter.aa_boss_time[creature->GetGUIDLow()] = 0;
                            std::vector<std::pair<ObjectGuid, uint32>> aa_boss_dmg; aa_boss_dmg.clear();
                            paihangpx(aa_boss_dmg, creature->aa_boss_dmg);
                            std::list<Player*> list; list.clear();
                            aaCenter.BB_GetPlayerListInGrid(creature, list, 300, true);
                            if (conf.show == 1) {
                                aaCenter.M_SendBoss_Paihang(list, creature, aa_boss_dmg);
                            }
                            if (!creature->IsAlive()) {
                                creature->aa_boss_dmg.clear();// 发送排行奖励
                                std::vector<int32> indexs; indexs.clear();
                                std::vector<int32> rewars; rewars.clear();
                                aaCenter.AA_StringToVector2(conf.reward, indexs, rewars);
                                size_t count = indexs.size();
                                std::unordered_map<int32, int32> rewardks; rewardks.clear();
                                if (count > 0) {
                                    for (size_t i = 0; i < count; i++) {
                                        int32 index = AA_SafeObjectAtIndex(indexs, i);
                                        int32 reward = AA_SafeObjectAtIndex(rewars, i);
                                        rewardks[index] = reward;
                                    }
                                }
                                size_t p_count = aa_boss_dmg.size();
                                for (size_t i = 0; i < p_count; i++) {
                                    std::pair<ObjectGuid, uint32> itr = aa_boss_dmg[i];
                                    int32 reward = rewardks[i + 1];
                                    if (Player* p = ObjectAccessor::FindPlayer(itr.first)) {
                                        if (p && p->IsInWorld()) {
                                            if (reward == 0) {
                                                reward = rewardks[0];
                                            }
                                            if (reward > 0) {
                                                aaCenter.M_Reward(p, reward);
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        if (!creature->IsPet() && !creature->IsTotem() && !creature->IsVehicle()) {
            if (aaCenter.aa_world_confs[76].value1 > 0 &&
                std::find(aaCenter.m_ai_creatures.begin(), aaCenter.m_ai_creatures.end(), creature) == aaCenter.m_ai_creatures.end()) {
                return;
            }
        }
    }
    if (!unit || !unit->IsInWorld() || (unit->GetTypeId() != TYPEID_PLAYER && unit->GetTypeId() != TYPEID_UNIT)) {
        return;
    }
    {
        std::set<uint32> aiids = aaCenter.AA_GetAis(unit, "无条件,战斗中,范围内出现玩家,范围内出现生物,在区域中,属性值,生命值");
        std::list<Player*> plist; plist.clear();
        std::list<Creature*> clist; clist.clear();
        for (auto id : aiids) {
            if (id > 0) {
                AA_Ai conf = aaCenter.aa_ais[id];
                if (conf.event_type == "无条件") {
                    if (conf.event_param1 > 0) {
                        aaCenter.AA_AiStart(unit, nullptr, id);
                    }
                }
                else if (conf.event_type == "战斗中") {
                    if (conf.event_param1 > 0) {
                        if (unit->IsInCombat()) {
                            aaCenter.AA_AiStart(unit, nullptr, id);
                        }
                    }
                }
                else if (conf.event_type == "范围内出现玩家") {
                    if (conf.event_param1 > 0) {
                        if (plist.empty()) {
                            aaCenter.BB_GetPlayerListInGrid(unit, plist, conf.event_param1, true);
                        }
                        if ((int32)plist.size() >= conf.event_param2) {
                            aaCenter.AA_AiStart(unit, nullptr, id);
                        }
                    }
                }
                else if (conf.event_type == "范围内出现生物") {
                    if (conf.event_param1 > 0) {
                        if (clist.empty()) {
                            aaCenter.BB_GetCreatureListInGrid(unit, clist, conf.event_param1);
                        }
                        if ((int32)clist.size() >= conf.event_param2) {
                            aaCenter.AA_AiStart(unit, nullptr, id);
                        }
                    }
                }
                else if (conf.event_type == "在区域中") {
                    if (conf.event_param1 > 0) {
                        uint32 areaid = unit->GetAreaId();
                        if ((int32)areaid != conf.event_param1) {
                            continue;
                        }
                        aaCenter.AA_AiStart(unit, nullptr, id);
                    }
                }
                else if (conf.event_type == "属性值") {
                    if (Player* p = unit->ToPlayer()) {
                        if (conf.event_param2 > 0 || conf.event_param3 > 0) {
                            CombatRating type = (CombatRating)(conf.event_param1);
                            float value = p->GetRatingBonusValue(type);
                            if (value < conf.event_param2 && value > conf.event_param3) {
                                aaCenter.AA_AiStart(unit, nullptr, id);
                            }
                        }
                    }
                }
                else if (conf.event_type == "生命值") {
                    uint32 health = unit->GetHealth();
                    uint32 maxhealth = unit->GetMaxHealth() > 0 ? unit->GetMaxHealth() : 1.0;
                    float persent = (float)health / (float)maxhealth * 100;
                    if (conf.event_param1 > 0 && (int32)health >= conf.event_param1) {
                        continue;
                    }
                    if (conf.event_param2 > 0 && persent >= conf.event_param2) {
                        continue;
                    }
                    if (conf.event_param3 > 0 && health <= conf.event_param3) {
                        continue;
                    }
                    if (conf.event_param4 > 0 && persent <= conf.event_param4) {
                        continue;
                    }
                    aaCenter.AA_AiStart(unit, nullptr, id);
                }
            }
        }
        {
            //ai冷却时间
            std::unordered_map<uint32, uint32>::iterator iter;
            ObjectGuid guid = unit->GetGUID();
            if (m_aiTimes.find(guid) != m_aiTimes.end()) {
                for (iter = m_aiTimes[guid].begin(); iter != m_aiTimes[guid].end(); iter++) {
                    if (iter->second >= 1) {
                        m_aiTimes[guid][iter->first] += diff;
                    }
                }
            }
            //ai公共冷却时间
            if (m_aiGGTimes.find(guid) != m_aiGGTimes.end()) {
                for (iter = m_aiGGTimes[guid].begin(); iter != m_aiGGTimes[guid].end(); iter++) {
                    if (iter->second >= 1) {
                        m_aiGGTimes[guid][iter->first] += diff;
                    }
                }
            }
        }
    }
}

bool AACenter::AA_DoCommand(Player* player, char const* text)
{
    if (!player) {
        std::set<Player*> players = aaCenter.GetOnlinePlayers();
        for (auto p : players) {
            player = p;
            break;
        }
    }
    if (!player || !player->IsInWorld()) {
        return false;
    }
    std::string s = text;
    if (s.find(".展示") == std::string::npos) {
        player->SetSelection(player->GetGUID());
    }
    ChatHandler handler(player->GetSession());
    handler.isOk = true;
    return handler.ParseCommands(text);
}

std::string AACenter::AA_GetRewardText(uint32 rewardid, uint32 count)
{
    std::string text = "";
    try {
        AA_Reward_Conf conf = aaCenter.aa_rewards[rewardid];
        if (conf.id > 0) {
            if (conf.text == "") {
                std::string s1 = conf.exp > 0 ? aa_color_yellow + "· " + aa_color_blues + "[经验]" + aa_color_yellow + " x " + std::to_string(conf.exp * count) + "&" : "";
                std::string s200 = conf.jxexp > 0 ? aa_color_yellow + "· " + aa_color_blues + "[军衔经验]" + aa_color_yellow + " x " + std::to_string(conf.jxexp * count) + "&" : "";
                std::string s201 = conf.dqexp > 0 ? aa_color_yellow + "· " + aa_color_blues + "[斗气经验]" + aa_color_yellow + " x " + std::to_string(conf.dqexp * count) + "&" : "";
                std::string s202 = conf.dfexp > 0 ? aa_color_yellow + "· " + aa_color_blues + "[巅峰经验]" + aa_color_yellow + " x " + std::to_string(conf.dfexp * count) + "&" : "";
                std::string s203 = conf.vip_level > 0 ? aa_color_yellow + "· " + aa_color_blues + "[会员等级]" + aa_color_yellow + " x " + std::to_string(conf.vip_level) + "&" : "";
                std::string s204 = conf.tianfu > 0 ? aa_color_yellow + "· " + aa_color_blues + "[天赋点]" + aa_color_yellow + " x " + std::to_string(conf.tianfu * count) + "&" : "";
                std::string s205 = conf.jxds > 0 ? aa_color_yellow + "· " + aa_color_blues + "[军衔点数]" + aa_color_yellow + " x " + std::to_string(conf.jxds * count) + "&" : "";
                std::string s206 = conf.dqds > 0 ? aa_color_yellow + "· " + aa_color_blues + "[斗气点数]" + aa_color_yellow + " x " + std::to_string(conf.dqds * count) + "&" : "";
                std::string s207 = conf.dfds > 0 ? aa_color_yellow + "· " + aa_color_blues + "[巅峰点数]" + aa_color_yellow + " x " + std::to_string(conf.dfds * count) + "&" : "";
                std::string s208 = conf.touxian > 0 ? aa_color_yellow + "· " + aa_color_blues + "[头衔]" + aa_color_yellow + " x " + std::to_string(conf.touxian) + "&" : "";
                std::string s209 = conf.czexp > 0 ? aa_color_yellow + "· " + aa_color_blues + "[成长经验]" + aa_color_yellow + " x " + std::to_string(conf.czexp * count) + "&" : "";
                std::string s3 = conf.money > 0 ? aa_color_yellow + "· " + aa_color_blues + "[金钱]" + aa_color_yellow + " x " + aaCenter.AA_GetMoneyLink(conf.money * count) + "&" : "";
                std::string s4 = conf.paodian > 0 ? aa_color_yellow + "· " + aa_color_blues + "[" + aaCenter.aa_world_confs[62].value2 + "]" + aa_color_yellow + " x " + std::to_string(conf.paodian) + "&" : "";
                std::string s5 = conf.mobi > 0 ? aa_color_yellow + "· " + aa_color_blues + "[" + aaCenter.aa_world_confs[63].value2 + "]" + aa_color_yellow + " x " + std::to_string(conf.mobi * count) + "&" : "";
                std::string s6 = conf.jifen > 0 ? aa_color_yellow + "· " + aa_color_blues + "[" + aaCenter.aa_world_confs[64].value2 + "]" + aa_color_yellow + " x " + std::to_string(conf.jifen * count) + "&" : "";
                std::string s7 = conf.battlecore > 0 ? aa_color_yellow + "· " + aa_color_blues + "[" + aaCenter.aa_world_confs[65].value2 + "]" + aa_color_yellow + " x " + std::to_string(conf.battlecore * count) + "&" : "";
                std::string s8 = conf.honorcore > 0 ? aa_color_yellow + "· " + aa_color_blues + "[荣誉点数]" + aa_color_yellow + " x " + std::to_string(conf.honorcore * count) + "&" : "";
                std::string itemstr = "";
                if (conf.items != "" && conf.items != "0") {
                    std::map<int32, int32> items; items.clear();
                    aaCenter.AA_StringToMap(conf.items, items);
                    for (auto itr : items) {
                        if (itr.first <= 0 || itr.second <= 0) {
                            continue;
                        }
                        ItemTemplate const* pProto = sObjectMgr->GetItemTemplate(itr.first);
                        if (!pProto) {
                            continue;
                        }
                        std::string name = aaCenter.AA_GetItemLink(itr.first);
                        std::string item = aa_color_blues + name + aa_color_yellow + " x " + std::to_string(itr.second * count) + "&";
                        itemstr = itemstr + item;
                    }
                }
                std::string s14 = conf.spells != "0" && conf.spells != "" ? "学习技能&" : "";
                std::string s15 = conf.buffs != "0" && conf.buffs != "" ? "获得Buff&" : "";
                std::string ss = s1 + s200 + s201 + s202 + s203 + s204 + s205 + s206 + s207 + s208 + s209 + s3 + s4 + s5 + s6 + s7 + s8 + itemstr + s14 + s15;//+s16;
                aaCenter.AA_StringReplaceLast(ss, "&", "");
                text = ss;
            }
            else {
                text = conf.text;
            }
        }
    }
    catch (std::exception const& e) {}
    return text;
}

std::string AACenter::AA_GetNeedText(uint32 needid, uint32 count)
{
    std::string text = "";
    try {
        AA_Need_Conf conf = aaCenter.aa_needs[needid];
        if (conf.id > 0) {
            if (conf.text == "") {
                std::string s1 = conf.level > 0 ? aa_color_red + "· 需要" + aa_color_blues + "[等级]" + aa_color_yellow + " x " + std::to_string(conf.level) + "&" : "";
                std::string s200 = conf.jxlevel > 0 ? aa_color_red + "· 需要" + aa_color_blues + "[军衔等级]" + aa_color_yellow + " x " + std::to_string(conf.jxlevel) + "&" : "";
                std::string s201 = conf.dqlevel > 0 ? aa_color_red + "· 需要" + aa_color_blues + "[斗气等级]" + aa_color_yellow + " x " + std::to_string(conf.dqlevel) + "&" : "";
                std::string s202 = conf.dflevel > 0 ? aa_color_red + "· 需要" + aa_color_blues + "[巅峰等级]" + aa_color_yellow + " x " + std::to_string(conf.dflevel) + "&" : "";
                std::string s3 = conf.viplevel > 0 ? aa_color_red + "· 需要" + aa_color_blues + "[会员等级]" + aa_color_yellow + " x " + std::to_string(conf.viplevel) + "&" : "";
                std::string s301 = conf.jifen_all > 0 ? aa_color_red + "· 需要" + aa_color_blues + "[累计" + aaCenter.aa_world_confs[64].value2 + "]" + aa_color_yellow + " x " + std::to_string(conf.jifen_all) + "&" : "";
                std::string s400 = conf.level_item_ItemLevel > 0 ? aa_color_red + "· 需要" + aa_color_blues + "[物品等级]" + aa_color_yellow + " x " + std::to_string(conf.level_item_ItemLevel) + "&" : "";
                std::string s401 = conf.level_item_Quality > 0 ? aa_color_red + "· 需要" + aa_color_blues + "[物品品质]" + aa_color_yellow + " x " + std::to_string(conf.level_item_Quality) + "&" : "";
                std::string s402 = conf.level_item_jd > 0 ? aa_color_red + "· 需要" + aa_color_blues + "[物品鉴定等级]" + aa_color_yellow + " x " + std::to_string(conf.level_item_jd) + "&" : "";
                std::string s403 = conf.level_item_qh > 0 ? aa_color_red + "· 需要" + aa_color_blues + "[物品强化等级]" + aa_color_yellow + " x " + std::to_string(conf.level_item_qh) + "&" : "";
                std::string s404 = conf.level_item_cz > 0 ? aa_color_red + "· 需要" + aa_color_blues + "[物品成长等级]" + aa_color_yellow + " x " + std::to_string(conf.level_item_cz) + "&" : "";
                std::string s405 = conf.level_item_jxsx > 0 ? aa_color_red + "· 需要" + aa_color_blues + "[物品觉醒属性等级]" + aa_color_yellow + " x " + std::to_string(conf.level_item_jxsx) + "&" : "";
                std::string s406 = conf.level_item_jxjn > 0 ? aa_color_red + "· 需要" + aa_color_blues + "[物品觉醒技能等级]" + aa_color_yellow + " x " + std::to_string(conf.level_item_jxjn) + "&" : "";
                std::string s407 = conf.level_pet_jh > 0 ? aa_color_red + "· 需要" + aa_color_blues + "[宠物进化等级]" + aa_color_yellow + " x " + std::to_string(conf.level_pet_jh) + "&" : "";
                std::string s408 = conf.level_pet_qh > 0 ? aa_color_red + "· 需要" + aa_color_blues + "[宠物强化等级]" + aa_color_yellow + " x " + std::to_string(conf.level_pet_qh) + "&" : "";
                std::string s409 = conf.level_pet_jx > 0 ? aa_color_red + "· 需要" + aa_color_blues + "[宠物觉醒等级]" + aa_color_yellow + " x " + std::to_string(conf.level_pet_jx) + "&" : "";
                std::string s5 = "";
                if (conf.gender == 1) {
                    s5 = aa_color_red + aa_color_red + "· 需要" + aa_color_blues + "[性别]" + aa_color_yellow + " 男&";
                }
                else if (conf.gender == 2) {
                    s5 = aa_color_red + aa_color_red + "· 需要" + aa_color_blues + "[性别]" + aa_color_yellow + " 女&";
                }
                std::string s6 = "";
                if (conf.team == 2) {
                    s6 = aa_color_red + aa_color_red + "· 需要" + aa_color_blues + "[阵营]" + aa_color_yellow + " 部落&";
                }
                else if (conf.team == 1) {
                    s6 = aa_color_red + aa_color_red + "· 需要" + aa_color_blues + "[阵营]" + aa_color_yellow + " 联盟&";
                }
                std::string s7 = "";
                switch (conf.race) {
                case RACE_HUMAN:
                    s7 = aa_color_red + aa_color_red + "· 需要" + aa_color_blues + "[种族]" + aa_color_yellow + " 人类&";
                    break;
                case RACE_ORC:
                    s7 = aa_color_red + "· 需要" + aa_color_blues + "[种族]" + aa_color_yellow + " 兽人&";
                    break;
                case RACE_DWARF:
                    s7 = aa_color_red + "· 需要" + aa_color_blues + "[种族]" + aa_color_yellow + " 矮人&";
                    break;
                case RACE_NIGHTELF:
                    s7 = aa_color_red + "· 需要" + aa_color_blues + "[种族]" + aa_color_yellow + " 暗夜精灵&";
                    break;
                case RACE_UNDEAD_PLAYER:
                    s7 = aa_color_red + "· 需要" + aa_color_blues + "[种族]" + aa_color_yellow + " 亡灵&";
                    break;
                case RACE_TAUREN:
                    s7 = aa_color_red + "· 需要" + aa_color_blues + "[种族]" + aa_color_yellow + " 牛头人&";
                    break;
                case RACE_GNOME:
                    s7 = aa_color_red + "· 需要" + aa_color_blues + "[种族]" + aa_color_yellow + " 侏儒&";
                    break;
                case RACE_TROLL:
                    s7 = aa_color_red + "· 需要" + aa_color_blues + "[种族]" + aa_color_yellow + " 巨魔&";
                    break;
                case RACE_BLOODELF:
                    s7 = aa_color_red + "· 需要" + aa_color_blues + "[种族]" + aa_color_yellow + " 血精灵&";
                    break;
                case RACE_DRAENEI:
                    s7 = aa_color_red + "· 需要" + aa_color_blues + "[种族]" + aa_color_yellow + " 德莱尼&";
                    break;
                default:
                    break;
                }
                std::string s8 = "";
                switch (conf.class1) {
                case CLASS_WARRIOR:
                    s8 = aa_color_red + "· 需要" + aa_color_blues + "[职业]" + MSG_COLOR_WARRIOR + " 战士&";
                    break;
                case CLASS_PALADIN:
                    s8 = aa_color_red + "· 需要" + aa_color_blues + "[职业]" + MSG_COLOR_PALADIN + " 圣骑士&";
                    break;
                case CLASS_HUNTER:
                    s8 = aa_color_red + "· 需要" + aa_color_blues + "[职业]" + MSG_COLOR_HUNTER + " 猎人&";
                    break;
                case CLASS_ROGUE:
                    s8 = aa_color_red + "· 需要" + aa_color_blues + "[职业]" + MSG_COLOR_ROGUE + " 潜行者&";
                    break;
                case CLASS_PRIEST:
                    s8 = aa_color_red + "· 需要" + aa_color_blues + "[职业]" + MSG_COLOR_PRIEST + " 牧师&";
                    break;
                case CLASS_DEATH_KNIGHT:
                    s8 = aa_color_red + "· 需要" + aa_color_blues + "[职业]" + MSG_COLOR_DEATH_KNIGHT + " 死亡骑士&";
                    break;
                case CLASS_SHAMAN:
                    s8 = aa_color_red + "· 需要" + aa_color_blues + "[职业]" + MSG_COLOR_SHAMAN + " 萨满&";
                    break;
                case CLASS_MAGE:
                    s8 = aa_color_red + "· 需要" + aa_color_blues + "[职业]" + MSG_COLOR_MAGE + " 法师&";
                    break;
                case CLASS_WARLOCK:
                    s8 = aa_color_red + "· 需要" + aa_color_blues + "[职业]" + MSG_COLOR_WARLOCK + " 术士&";
                    break;
                case CLASS_DRUID:
                    s8 = aa_color_red + "· 需要" + aa_color_blues + "[职业]" + MSG_COLOR_DRUID + " 德鲁伊&";
                    break;
                default:
                    break;
                }
                std::string s9 = conf.guild > 0 ? "限制：指定公会&" : "";
                std::string s10 = conf.mapid > -1 || conf.zoneid > -1 || conf.areaid > -1 ? "限制：指定地图&" : "";
                std::string sp = conf.deplete == 0 ? aa_color_red + "· 消耗" : aa_color_red + "· 持有";
                std::string s11 = conf.money > 0 ? aa_color_yellow + "· 消耗" + aa_color_blues + "[金钱]" + aa_color_yellow + " x " + aaCenter.AA_GetMoneyLink(conf.money * count) + "&" : "";
                std::string s12 = conf.paodian > 0 ? (aa_color_red + "· 消耗" + aa_color_blues + "[" + aaCenter.aa_world_confs[62].value2 + "]" + aa_color_yellow + " x " + std::to_string(conf.paodian * count) + "&") : "";
                std::string s13 = conf.mobi > 0 ? (aa_color_red + "· 消耗" + aa_color_blues + "[" + aaCenter.aa_world_confs[63].value2 + "]" + aa_color_yellow + " x " + std::to_string(conf.mobi * count) + "&") : "";
                std::string s14 = conf.jifen > 0 ? (aa_color_red + "· 消耗" + aa_color_blues + "[" + aaCenter.aa_world_confs[64].value2 + "]" + aa_color_yellow + " x " + std::to_string(conf.jifen * count) + "&") : "";
                std::string s15 = conf.battlecore > 0 ? (aa_color_red + "· 消耗" + aa_color_blues + "[" + aaCenter.aa_world_confs[65].value2 + "]" + aa_color_yellow + " x " + std::to_string(conf.battlecore * count) + "&") : "";
                std::string s16 = conf.honorcore > 0 ? (aa_color_red + "· 消耗" + aa_color_blues + "[荣誉点数]" + aa_color_yellow + " x " + std::to_string(conf.honorcore * count) + "&") : "";
                std::string itemstr = "";
                if (conf.items != "" && conf.items != "0") {
                    std::map<int32, int32> items; items.clear();
                    aaCenter.AA_StringToMap(conf.items, items);
                    for (auto itr : items) {
                        if (itr.first <= 0 || itr.second <= 0) {
                            continue;
                        }
                        ItemTemplate const* pProto = sObjectMgr->GetItemTemplate(itr.first);
                        if (!pProto) {
                            continue;
                        }
                        std::string name = aaCenter.AA_GetItemLink(itr.first);
                        std::string item = aa_color_blues + name + aa_color_yellow + " x " + std::to_string(itr.second * count);
                        std::string s = sp + item + "&";
                        itemstr = itemstr + s;
                    }
                }
                std::string s22 = conf.quests != "0" && conf.quests != "" ? "完成：指定任务&" : "";
                std::string s23 = conf.achievements != "0" && conf.achievements != "" ? "完成：指定成就&" : "";
                std::string s24 = conf.spells != "0" && conf.spells != "" ? "学习：指定技能&" : "";
                std::string s25 = conf.buffs != "0" && conf.buffs != "" ? "携带：指定Buff&" : "";
                std::string s26 = conf.group_count > 0 ? aa_color_red + "· 需要" + aa_color_blues + "[队伍人数]" + aa_color_yellow + " x " + std::to_string(conf.group_count) + "&" : "";
                std::string s27 = conf.group_duizhang > 0 ? aa_color_red + "· 需要" + aa_color_blues + "[队长]&" : "";
                std::string ss = s1 + s200 + s201 + s202 + s3 + s301 + s400 + s401 + s402 + s403 + s404 + s405 + s406 + s407 + s408 + s409 + s5 + s6 + s7 + s8 + s9 + s10 + s11 + s12 + s13 + s14 + s15 + s16 + itemstr + s22 + s23 + s24 + s25 + s26 + s27;
                aaCenter.AA_StringReplaceLast(ss, "&", "");
                text = ss;
            }
            else {
                text = conf.text;
            }
        }
    }
    catch (std::exception const& e) {}
    return text;
}

/*item*/
Item* AACenter::AA_AddItem(Player* player, uint32 itemId, uint32 count)
{
    uint32 noSpaceForCount = 0;
    ItemPosCountVec dest;
    InventoryResult msg = player->CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, itemId, count, &noSpaceForCount);
    if (msg != EQUIP_ERR_OK)
        count -= noSpaceForCount;

    if (count == 0 || dest.empty())
    {
        // -- TODO: Send to mailbox if no space
        ChatHandler(player->GetSession()).PSendSysMessage("你没有足够的背包空间.");
        return nullptr;
    }

    Item* item = player->StoreNewItem(dest, itemId, true);
    if (item)
        player->SendNewItem(item, count, true, false);
    else
        return nullptr;
    return item;
}

std::string AACenter::AA_GetItemName(Item* item)
{
    try {
        ObjectGuid::LowType guid = item->GetGUIDLow();
        std::string textpre = "";
        std::string textsuf = "";
        AA_Character_Instance char_conf = aaCenter.aa_character_instances[guid];
        if (char_conf.guid > 0) {
            uint32 nonsuch_id = char_conf.jd_id;
            AA_Item_Nonsuch conf = aaCenter.aa_item_nonsuchs[nonsuch_id];
            if (conf.text != "") {
                textpre = conf.textpre;
                textsuf = conf.textsuf;
            }
            ItemTemplate const* pProto = item->GetTemplate();
            std::string name = "";
            if (pProto) {
                name = pProto->GetName(LOCALE_zhCN);
            }
            name = textpre + name + textsuf;
            return name;
        }
        else {
            ItemTemplate const* pProto = item->GetTemplate();
            std::string name = "";
            if (pProto) {
                name = pProto->GetName(LOCALE_zhCN);
            }
            return name;
        }
    }
    catch (std::exception const& e) {}
    return "";
}
std::string AACenter::AA_GetItemLink(uint32 itemid)
{
    const ItemTemplate* temp = sObjectMgr->GetItemTemplate(itemid);
    if (!temp) {
        return "";
    }
    std::string name = temp->GetName(LOCALE_zhCN);

    std::ostringstream oss;
    oss << "|c" << std::hex << ItemQualityColors[temp->GetQuality()] << std::dec <<
        "|Hitem:" << itemid << ":0:0:0:0:0:0:0:0:0|h[" << name << "]|h|r";

    return oss.str();
}
std::string AACenter::AA_GetItemLinkJd(Item* item)
{
    if (!item) {
        return "";
    }
    ItemTemplate const* pProto = item->GetTemplate();
    if (!pProto) {
        return "";
    }
    try {
        uint32 itemId = pProto->GetId();
        ObjectGuid::LowType guid = item->GetGUIDLow();
        ObjectGuid::LowType guidlowH = guid / 10000;
        ObjectGuid::LowType guidlowL = guid - guidlowH * 10000;
        std::string name = pProto->GetName(LOCALE_zhCN);
        std::ostringstream ss;
        ss << "|c" << std::hex << ItemQualityColors[pProto->GetQuality()] << std::dec;
        std::string q_color = "";
        if (ss) {
            q_color = ss.str();
        }
        AA_Character_Instance char_conf = aaCenter.aa_character_instances[guid];
        if (char_conf.guid > 0) {
            uint32 nonsuch_id = char_conf.jd_id;
            AA_Item_Nonsuch conf = aaCenter.aa_item_nonsuchs[nonsuch_id];
            std::string textpre = conf.textpre;
            std::string textsuf = conf.textsuf;
            if (textpre != "" || textsuf != "") {
                name = "[" + textpre + name + textsuf + "]|r";
            }
            else {
                name = q_color + "[" + name + "]|r";
            }
        }
        else {
            name = q_color + "[" + name + "]|r";
        }
        std::string itemlink = "|Hitem:" + std::to_string(itemId) + ":0:0:" + std::to_string(guidlowH + 5000) + ":" + std::to_string(guidlowL + 5000) + ":0:0:0|h" + name + "|h|r";
        return itemlink;
    }
    catch (std::exception const& e) {}
    return "";
}

std::string AACenter::AA_GetMoneyLink(uint32 money)
{
    uint32 jinbi = money / 10000;
    uint32 yinbi = (money - jinbi * 10000) / 100;
    uint32 tongbi = money - jinbi * 10000 - yinbi * 100;
    std::string str = "";
    if (jinbi > 0) {
        str = str + std::to_string(jinbi) + "金";
    }
    if (yinbi > 0) {
        str = str + std::to_string(yinbi) + "银";
    }
    if (tongbi > 0) {
        str = str + std::to_string(tongbi) + "铜";
    }
    return str;
}

std::set<uint32> AACenter::M_GetAllItemSpell(ObjectGuid::LowType guidlow)
{
    std::set<uint32> spells;
    spells.clear();
    try {
        AA_Character_Instance conf = aaCenter.aa_character_instances[guidlow];
        //附魔技能
        uint32 fm_count = conf.fm_spell_count;
        if (fm_count > 0 && conf.fm_spells != "" && conf.fm_spells != "0") {
            std::vector<int32> fmids; fmids.clear();
            aaCenter.AA_StringToVectorInt(conf.fm_spells, fmids, ",");
            for (size_t i = 0; i < fmids.size(); i++) {
                uint32 spellid = fmids[i];
                if (spellid == 0) { continue; }
                spells.insert(spellid);
            }
        }
        //符文技能
        uint32 fw_count = conf.fw_count;
        if (fw_count > 0 && conf.fw_values != "" && conf.fw_values != "0") {
            std::vector<int32> fwids; fwids.clear();
            aaCenter.AA_StringToVectorInt(conf.fw_values, fwids, ",");
            for (size_t i = 0; i < fwids.size(); i++) {
                uint32 fwid = fwids[i];
                if (fwid == 0) { continue; }
                AA_Fw_Conf fwconf = aaCenter.aa_fw_confs[fwid];
                std::vector<int32> spellids; spellids.clear();
                aaCenter.AA_StringToVectorInt(fwconf.spells, spellids, ",");
                for (size_t j = 0; j < spellids.size(); j++) {
                    if (spellids[j] == 0) {
                        continue;
                    }
                    spells.insert(spellids[j]);
                }
            }
        }
        //符文组合技能
        if (conf.fwzh_values != "" && conf.fwzh_values != "0") {
            std::vector<int32> fwzhids; fwzhids.clear();
            aaCenter.AA_StringToVectorInt(conf.fwzh_values, fwzhids, ",");
            for (size_t i = 0; i < fwzhids.size(); i++) {
                uint32 fwid = fwzhids[i];
                if (fwid == 0) { continue; }
                AA_FwZh_Conf fwconf = aaCenter.aa_fwzh_confs[fwid];
                std::vector<int32> spellids; spellids.clear();
                aaCenter.AA_StringToVectorInt(fwconf.spells, spellids, ",");
                for (size_t j = 0; j < spellids.size(); j++) {
                    if (spellids[j] == 0) {
                        continue;
                    }
                    spells.insert(spellids[j]);
                }
            }
        }
        //装备强化技能
        std::string zbqhstr = conf.qh_reward_spell;
        if (zbqhstr != "" && zbqhstr != "0") {
            std::vector<int32> zbqhids; zbqhids.clear();
            aaCenter.AA_StringToVectorInt(zbqhstr, zbqhids, ",");
            for (size_t i = 0; i < zbqhids.size(); i++) {
                uint32 spellid = zbqhids[i];
                if (spellid == 0) { continue; }
                spells.insert(spellid);
            }
        }
        //装备成长技能
        if (conf.cz_reward_spell != "" && conf.cz_reward_spell != "0") {
            std::vector<int32> zbczids; zbczids.clear();
            aaCenter.AA_StringToVectorInt(conf.cz_reward_spell, zbczids, ",");
            for (size_t i = 0; i < zbczids.size(); i++) {
                uint32 spellid = zbczids[i];
                if (spellid == 0) { continue; }
                spells.insert(spellid);
            }
        }
    }
    catch (std::exception const& e) {}
    return spells;
}

bool AACenter::AA_UnequipItem(Player* player, Item* item)
{
    if (player->CanUnequipItem(item->GetPos(), false) != EQUIP_ERR_OK)
        return false;
    uint8 slot = aaCenter.AA_GetEmptyBag(player);
    if (slot > 0) {
        item->SetSlot(slot);
    }
    return true;
}

uint32 AACenter::AA_GetRealItemGuid(uint32 id, uint32 entry)
{
    return id;
    //    if (aaCenter.aa_item_pets[entry].entry > 0) { //宠物
    //        std::set<uint32> guids = aaCenter.aa_character_pet_ids[id];
    //        for (ObjectGuid::LowType guid : guids) {
    //            AA_Character_Pet conf = aaCenter.aa_character_pets[guid];
    //            if (conf.itemEntry == entry) {
    //                return guid;
    //            }
    //        }
    //    } else {
    //        std::set<uint32> guids = aaCenter.aa_character_instance_ids[id];
    //        for (ObjectGuid::LowType guid : guids) {
    //            AA_Character_Instance conf = aaCenter.aa_character_instances[guid];
    //            if (conf.itemEntry == entry) {
    //                return guid;
    //            }
    //        }
    //    }
    //    return 0;
}

uint8 AACenter::AA_GetEmptyBag(Player* player)
{
    uint8 slot = 0;

    // bags not have durability
        // for (int i = INVENTORY_SLOT_BAG_START; i < INVENTORY_SLOT_BAG_END; i++)

    uint8 inventoryEnd = INVENTORY_SLOT_ITEM_START + player->GetInventorySlotCount();
    for (uint8 i = INVENTORY_SLOT_ITEM_START; i < inventoryEnd; i++)
        if (!player->GetItemByPos(INVENTORY_SLOT_BAG_0, i))
            slot++;

    for (uint8 i = INVENTORY_SLOT_BAG_START; i < INVENTORY_SLOT_BAG_END; i++)
        if (Bag* pBag = player->GetBagByPos(i))
            for (uint32 j = 0; j < pBag->GetBagSize(); j++)
                if (!player->GetItemByPos(i, j))
                    slot++;

    return slot;
}

bool AACenter::AA_IsShenQiItem(Item const* pItem)
{
    uint8 bagslot = pItem->GetBagSlot();
    uint8 slot = pItem->GetSlot();
    if (bagslot == INVENTORY_SLOT_BAG_0 && slot < INVENTORY_SLOT_BAG_END) {
        return false;
    }
    ItemTemplate const* pProto = pItem->GetTemplate();
    if (!pProto) {
        return false;
    }

    AA_Item_Bag conf = aaCenter.aa_item_bags[pProto->GetId()];

    if (conf.entry == 0) {
        return false;
    }

    //0所有背包物品 1所有银行物品 2所有背包+银行物品 18主背包 19-22副背包
    if (bagslot == INVENTORY_SLOT_BAG_0 && slot >= INVENTORY_SLOT_ITEM_START && slot < INVENTORY_SLOT_ITEM_END) { //主背包
        if (conf.bag != 0 && conf.bag != 2 && conf.bag != 18) {
            return false;
        }
    }
    if (bagslot >= INVENTORY_SLOT_BAG_START && bagslot < INVENTORY_SLOT_BAG_END) { //19-22副背包
        if (conf.bag != 0 && conf.bag != 2 && conf.bag != bagslot) {
            return false;
        }
    }
    if ((bagslot == INVENTORY_SLOT_BAG_0 && slot >= BANK_SLOT_ITEM_START && slot < BANK_SLOT_ITEM_END) ||
        (bagslot >= BANK_SLOT_BAG_START && bagslot < BANK_SLOT_BAG_END)) { //银行物品
        if (conf.bag != 1 && conf.bag != 2) {
            return false;
        }
    }
    return true;
}

void AA_ReplaceStr(Player* player, std::string& message, std::string s)
{
    try {
        std::string prestr = "<$" + s + "@";
        std::string nums = aaCenter.AA_StringGet(message, prestr, ">");
        if (nums != "") {
            int num = atoi(nums.c_str());
            ObjectGuid::LowType guidlow = player->GetGUIDLow();
            std::string fulstr = prestr + nums + ">";
            if (s.find("巅峰加点") != std::string::npos ||
                s.find("斗气加点") != std::string::npos ||
                s.find("军衔加点") != std::string::npos) {
                if (num >= 0) {
                    if (s.find("巅峰加点") != std::string::npos) {
                        std::string c_value = aaCenter.aa_characters_dianfengs[guidlow].value;
                        std::map<int32, int32> values; values.clear();
                        aaCenter.AA_StringToMap(c_value, values);
                        aaCenter.AA_StringReplace(message, fulstr, std::to_string(values[num]));
                    }
                    else if (s.find("斗气加点") != std::string::npos) {
                        std::string c_value = aaCenter.aa_characters_douqis[guidlow].value;
                        std::map<int32, int32> values; values.clear();
                        aaCenter.AA_StringToMap(c_value, values);
                        aaCenter.AA_StringReplace(message, fulstr, std::to_string(values[num]));
                    }
                    else if (s.find("军衔加点") != std::string::npos) {
                        std::string c_value = aaCenter.aa_characters_junxians[guidlow].value;
                        std::map<int32, int32> values; values.clear();
                        aaCenter.AA_StringToMap(c_value, values);
                        aaCenter.AA_StringReplace(message, fulstr, std::to_string(values[num]));
                    }
                }
            }
            else if (s.find("需求") != std::string::npos) {
                if (num > 0) {
                    std::string need = aaCenter.AA_GetNeedText((int32)num);
                    if (need != "") {
                        aaCenter.AA_StringReplace(need, "&", "\n");
                        aaCenter.AA_StringReplace(message, fulstr, need);
                    }
                }
            }
            else if (s.find("奖励") != std::string::npos) {
                if (num > 0) {
                    std::string reward = aaCenter.AA_GetRewardText((int32)num);
                    if (reward != "") {
                        aaCenter.AA_StringReplace(reward, "&", "\n");
                        aaCenter.AA_StringReplace(message, fulstr, reward);
                    }
                }
            }
        }
    }
    catch (std::exception const& e) {}
}

/*工具*/
void AACenter::AA_SendMessage(Player* p, int type, const char* Text, ...)
{
    if (Text == nullptr || (Text != nullptr && Text[0] == '\0')) {
        return;
    }
    std::set<Player*> players;
    players.clear();
    if (p) {
        players.insert(p);
    }
    else {
        const HashMapHolder<Player>::MapType& m = ObjectAccessor::GetPlayers();
        for (HashMapHolder<Player>::MapType::const_iterator it = m.begin(); it != m.end(); ++it)
        {
            if (Player* player = it->second)
            {
                players.insert(player);
            }
        }
    }
    for (Player* p : players) {
        if (!p->IsInWorld()) { continue; }
        if (type == 0) { //聊天框
            sWorld->SendServerMessage(SERVER_MSG_STRING, Text, p);
        }
        else if (type == 1) { //屏幕中央
            sWorld->SendGlobalText(Text, p->GetSession());
        }
        else if (type == 2) {
            sWorld->SendServerMessage(SERVER_MSG_STRING, Text, p);
            sWorld->SendGlobalText(Text, p->GetSession());
        }
    }
}

uint32 AACenter::AA_FindMapValueUint32(std::map<uint32, uint32> m, uint32 key)
{
    if (m.find(key) != m.end())
        return m.find(key)->second;
    return 0;
}

void AACenter::AA_StringToLower(std::string& s) {
    try {
        int len = s.size();
        for (int i = 0; i < len; i++) {
            if (s[i] >= 'A' && s[i] <= 'Z') {
                s[i] += 32;
            }
        }
    }
    catch (std::exception const& e) {}
}
std::string AACenter::AA_StringFromFloat(const float dbNum)
{
    try {
        char* chCode;
        chCode = new(std::nothrow)char[20];
        sprintf(chCode, "%.2f", dbNum);  // .2 是控制输出精度的，两位小数
        string strCode(chCode);
        delete[]chCode;
        return strCode;
    }
    catch (std::exception const& e) {
        return "";
    }
}

/* 功能：将map转化为s
 */
void AACenter::AA_MapToString(const std::map<int32, int32> m, std::string& s)
{
    try {
        if (m.size() == 0) {
            s = "";
            return;
        }
        std::string str = "";
        for (auto itr : m) {
            str = str + std::to_string(itr.first) + " " + std::to_string(itr.second);
            str = str + ",";
        }
        aaCenter.AA_StringReplaceLast(str, ",", "");
        s = str;
    }
    catch (std::exception const& e) { s = ""; }
}
void AACenter::AA_StringMapToString(const std::map<std::string, std::string> m, std::string& s)
{
    try {
        if (m.size() == 0) {
            s = "";
            return;
        }
        std::string str = "";
        for (auto itr : m) {
            str = str + itr.first + " " + itr.second;
            str = str + ",";
        }
        aaCenter.AA_StringReplaceLast(str, ",", "");
        s = str;
    }
    catch (std::exception const& e) { s = ""; }
}

/* 功能：将s转化为map
 */
void AACenter::AA_StringToMap(const std::string s, std::map<int32, int32>& m)
{
    if (s == "") {
        return;
    }
    std::vector<int32> v1; v1.clear();
    std::vector<int32> v2; v2.clear();
    aaCenter.AA_StringToVector2(s, v1, v2);
    if (v1.size() > 0 && v1.size() == v2.size()) {
        for (int i = 0; i < v1.size(); i++) {
            m[v1[i]] = v2[i];
        }
    }
}
void AACenter::AA_StringToMapFloat(const std::string s, std::map<float, float>& m)
{
    if (s == "") {
        return;
    }
    std::vector<float> v1; v1.clear();
    std::vector<float> v2; v2.clear();
    aaCenter.AA_StringToVectorFloat(s, v1, v2);
    if (v1.size() > 0 && v1.size() == v2.size()) {
        for (int i = 0; i < v1.size(); i++) {
            m[v1[i]] = v2[i];
        }
    }
}

void AACenter::AA_StringToStringMap(const std::string s, std::map<std::string, std::string>& m)
{
    if (s == "") {
        return;
    }
    std::vector<std::string> v1; v1.clear();
    std::vector<std::string> v2; v2.clear();
    aaCenter.AA_StringToVector3(s, v1, v2);
    if (v1.size() > 0 && v1.size() == v2.size()) {
        for (int i = 0; i < v1.size(); i++) {
            m[v1[i]] = v2[i];
        }
    }
}

/* 功 能：将s字符串以c为分隔符，转换为v数组
 */
void AACenter::AA_StringToVectorString(const std::string s, std::vector<std::string>& v, const std::string c)
{
    try {
        if (s == "") {
            return;
        }
        std::string::size_type pos1, pos2;
        pos2 = s.find(c);
        if (std::string::npos == pos2) {
            v.push_back(s);
            return;
        }
        pos1 = 0;
        while (std::string::npos != pos2)
        {
            v.push_back(s.substr(pos1, pos2 - pos1));
            pos1 = pos2 + c.size();
            pos2 = s.find(c, pos1);
        }
        if (pos1 != s.length())
            v.push_back(s.substr(pos1));
    }
    catch (std::exception const& e) {}
}

void AACenter::AA_StringToVectorInt(const std::string s, std::vector<int32>& v, const std::string c)
{
    try {
        if (s == "") {
            return;
        }
        std::string::size_type pos1, pos2;
        pos2 = s.find(c);
        if (std::string::npos == pos2) {
            v.push_back(aaCenter.AA_StringUint32(s));
            return;
        }
        pos1 = 0;
        while (std::string::npos != pos2)
        {
            v.push_back(aaCenter.AA_StringUint32(s.substr(pos1, pos2 - pos1)));
            pos1 = pos2 + c.size();
            pos2 = s.find(c, pos1);
        }
        if (pos1 != s.length())
            v.push_back(aaCenter.AA_StringUint32(s.substr(pos1)));
    }
    catch (std::exception const& e) {}
}
void AACenter::AA_StringToVectorFloat(const std::string s, std::vector<float>& v, const std::string c)
{
    try {
        if (s == "") {
            return;
        }
        std::string::size_type pos1, pos2;
        pos2 = s.find(c);
        if (std::string::npos == pos2) {
            v.push_back(aaCenter.AA_StringFloat(s));
            return;
        }
        pos1 = 0;
        while (std::string::npos != pos2)
        {
            v.push_back(aaCenter.AA_StringFloat(s.substr(pos1, pos2 - pos1)));
            pos1 = pos2 + c.size();
            pos2 = s.find(c, pos1);
        }
        if (pos1 != s.length())
            v.push_back(aaCenter.AA_StringFloat(s.substr(pos1)));
    }
    catch (std::exception const& e) {}
}
void AACenter::AA_VectorIntToString(std::string& s, const std::vector<int32> v, const std::string c)
{
    try {
        if (v.size() == 0) {
            s = "";
            return;
        }
        std::string ss = "";
        for (size_t i = 0; i < v.size(); i++) {
            ss = ss + std::to_string(v[i]) + c;
        }
        aaCenter.AA_StringReplaceLast(ss, c, "");
        s = ss;
    }
    catch (std::exception const& e) {}
}

void AACenter::AA_VectorStringToString(std::string& s, const std::vector<std::string> v, const std::string c)
{
    try {
        if (v.size() == 0) {
            s = "";
            return;
        }
        std::string ss = "";
        for (size_t i = 0; i < v.size(); i++) {
            ss = ss + v[i] + c;
        }
        aaCenter.AA_StringReplaceLast(ss, c, "");
        s = ss;
    }
    catch (std::exception const& e) {}
}

uint32 AACenter::AA_StringRandom(const std::string& s)
{
    if (s == "") {
        return 0;
    }
    try {
        std::vector<std::string> v;
        v.clear();
        std::string c = ",";
        std::string::size_type pos1, pos2;
        pos2 = s.find(c);
        if (std::string::npos == pos2) {
            return aaCenter.AA_StringUint32(s);
        }
        pos1 = 0;
        while (std::string::npos != pos2)
        {
            v.push_back(s.substr(pos1, pos2 - pos1));

            pos1 = pos2 + c.size();
            pos2 = s.find(c, pos1);
        }
        if (pos1 != s.length())
            v.push_back(s.substr(pos1));

        size_t size = v.size();
        size_t i = rand() % size;
        return aaCenter.AA_StringUint32(v[i]);
    }
    catch (std::exception const& e) {
        return 0;
    }
}

void AACenter::AA_FugaiStringToVector(const std::string s, std::vector<int32>& v1, std::vector<int32>& v2, std::vector<int32>& v3, std::vector<int32>& v4)
{
    std::vector<std::string> strs; strs.clear();
    aaCenter.AA_StringToVectorString(s, strs, ",");
    for (auto str : strs) {
        std::vector<int32> vals; vals.clear();
        aaCenter.AA_StringToVectorInt(str, vals, " ");
        if (vals.size() == 4) {
            v1.push_back(vals[0]);
            v2.push_back(vals[1]);
            v3.push_back(vals[2]);
            v4.push_back(vals[3]);
        }
    }
}

void AACenter::AA_StringToVectorFloat(const std::string s, std::vector<float>& v1, std::vector<float>& v2)
{
    std::vector<std::string> strs; strs.clear();
    aaCenter.AA_StringToVectorString(s, strs, ",");
    for (auto str : strs) {
        std::vector<float> vals; vals.clear();
        aaCenter.AA_StringToVectorFloat(str, vals, " ");
        if (vals.size() == 2) {
            v1.push_back(vals[0]);
            v2.push_back(vals[1]);
        }
    }
}

void AACenter::AA_StringToVector3(const std::string s, std::vector<std::string>& v1, std::vector<std::string>& v2)
{
    std::vector<std::string> strs; strs.clear();
    aaCenter.AA_StringToVectorString(s, strs, ",");
    for (auto str : strs) {
        std::vector<std::string> vals; vals.clear();
        aaCenter.AA_StringToVectorString(str, vals, " ");
        if (vals.size() == 2) {
            v1.push_back(vals[0]);
            v2.push_back(vals[1]);
        }
    }
}

void AACenter::AA_StringToVector2(const std::string s, std::vector<int32>& v1, std::vector<int32>& v2)
{
    std::vector<std::string> strs; strs.clear();
    aaCenter.AA_StringToVectorString(s, strs, ",");
    for (auto str : strs) {
        std::vector<int32> vals; vals.clear();
        aaCenter.AA_StringToVectorInt(str, vals, " ");
        if (vals.size() == 2) {
            v1.push_back(vals[0]);
            v2.push_back(vals[1]);
        }
    }
}

void AACenter::AA_VectorToString(std::string& s, const std::vector<int32>& v1, const std::vector<int32>& v2)
{
    try {
        if (v1.size() == 0 || v1.size() != v2.size()) {
            s = "";
            return;
        }
        size_t count = v1.size();
        std::string str = "";
        for (size_t i = 0; i < count; i++) {
            uint32 key = v1[i];
            int32 value = v2[i];
            str = str + std::to_string(key) + " " + std::to_string(value);
            str = str + ",";
        }
        aaCenter.AA_StringReplaceLast(str, ",", "");
        s = str;
        //        std::unordered_map<uint32, int32> kv; kv.clear();
        //        std::string str = "";
        //        size_t count = v1.size();
        //        std::vector<uint32> keys; keys.clear();
        //        for (size_t i = 0; i<count; i++) {
        //            uint32 key = v1[i];
        //            kv[key] = v2[i];
        //            keys.push_back(key);
        //        }
        //        std::sort(keys.begin(),keys.end());
        //        for (size_t i = 0; i<count; i++) {
        //            uint32 key = keys[i];
        //            str = str+std::to_string(key)+" "+std::to_string(kv[key]);
        //            str = str+",";
        //        }
        //        aaCenter.AA_StringReplaceLast(str, ",", "");
        //        s = str;
    }
    catch (std::exception const& e) { s = ""; }
}

void AACenter::AA_VectorToStringSort(std::string& s, const std::vector<int32>& v1, const std::vector<int32>& v2)
{
    try {
        if (v1.size() == 0 || v1.size() != v2.size()) {
            s = "";
            return;
        }
        //            size_t count = v1.size();
        //            std::string str = "";
        //            for (size_t i = 0; i<count; i++) {
        //                uint32 key = v1[i];
        //                int32 value = v2[i];
        //                str = str+std::to_string(key)+" "+std::to_string(value);
        //                str = str+",";
        //            }
        //            aaCenter.AA_StringReplaceLast(str, ",", "");
        //            s = str;
        std::unordered_map<uint32, int32> kv; kv.clear();
        std::string str = "";
        size_t count = v1.size();
        std::vector<uint32> keys; keys.clear();
        for (size_t i = 0; i < count; i++) {
            uint32 key = v1[i];
            kv[key] = v2[i];
            keys.push_back(key);
        }
        std::sort(keys.begin(), keys.end());
        for (size_t i = 0; i < count; i++) {
            uint32 key = keys[i];
            str = str + std::to_string(key) + " " + std::to_string(kv[key]);
            str = str + ",";
        }
        aaCenter.AA_StringReplaceLast(str, ",", "");
        s = str;
    }
    catch (std::exception const& e) { s = ""; }
}

/*
 将s1中的s2替换为s3
 */
void AACenter::AA_StringReplace(std::string& s1, const std::string& s2, const std::string& s3)
{
    try {
        std::string::size_type pos = 0;
        pos = s1.find(s2);
        if (std::string::npos == pos) {
            return;
        }
        std::string::size_type a = s2.size();
        std::string::size_type b = s3.size();
        while ((pos = s1.find(s2, pos)) != std::string::npos)
        {
            s1.erase(pos, a);
            s1.insert(pos, s3);
            pos += b;
        }
    }
    catch (std::exception const& e) {}
}
/*
 将s1中的第一个s2替换为s3
 */
void AACenter::AA_StringReplaceFirst(std::string& s1, const std::string& s2, const std::string& s3)
{
    try {
        std::size_t found = s1.find(s2);
        if (found != std::string::npos) {
            s1.replace(found, s2.size(), s3);
        }
    }
    catch (std::exception const& e) {}
}
/*
 将s1中的最后一个s2替换为s3
 */
void AACenter::AA_StringReplaceLast(std::string& s1, const std::string& s2, const std::string& s3)
{
    try {
        std::size_t found = s1.rfind(s2);
        if (found != std::string::npos) {
            s1.replace(found, s2.size(), s3);
        }
    }
    catch (std::exception const& e) {}
}
/*
 string 转 float
 */
float AACenter::AA_StringFloat(std::string s)
{
    if (s == "") {
        return 0;
    }
    try {
        double result;
        stringstream ss;
        ss << s;
        ss >> result;
        result = round(result * 100) / 100;//四舍五入保留两位小数
        return result;
    }
    catch (std::exception const& e)
    {
        return 0;
    }
}
/*
 string 转 int32
 */
int32 AACenter::AA_StringInt32(std::string s)
{
    if (s == "") {
        return 0;
    }
    try {
        return std::stoi(s);
    }
    catch (std::exception const& e)
    {
        return 0;
    }
}
/*
 string 转 uint32
 */
uint32 AACenter::AA_StringUint32(std::string s)
{
    if (s == "") {
        return 0;
    }
    try {
        return std::stoi(s);
    }
    catch (std::exception const& e)
    {
        return 0;
    }
}
/*
 string 转 uint64
 */
uint64 AACenter::AA_StringUint64(std::string s)
{
    if (s == "") {
        return 0;
    }
    try {
        return std::stoul(s);
    }
    catch (std::exception const& e)
    {
        return 0;
    }
}

std::string AACenter::AA_StringGet(std::string& s1, const std::string& s2, const std::string& s3)
{
    try {
        int nPos_1 = s1.find(s2);
        std::string nStr = s1.substr(nPos_1 + s2.length(), s1.length() - s2.length() - nPos_1);
        int nPos_2 = nStr.find(s3);
        if (nPos_2 <= 0 || int(nStr.length()) <= nPos_2) {
            return "";
        }
        return nStr.substr(0, nPos_2);
    }
    catch (std::exception const& e) {}
    return "";
}

bool AACenter::AA_StringHasString(std::string s1, std::string s2) {
    try {
        std::string::size_type idx = s1.find(s2);
        if (idx == std::string::npos)
            return false;
        else//存在。
            return true;
    }
    catch (std::exception const& e) {}
    return false;
}

/*objectmgr*/
void AACenter::AA_SendNotice(Unit* me, AA_Notice notice, bool succes, AA_Message aa_message)
{
    //    uint32 type1 = 0; //0个人1队伍2本阵营3全服
    //    uint32 type2 = 0; //0发送到聊天框 1发送到屏幕中央

    std::string message = succes ? notice.content_default1 : notice.content_default2;

    if (message == "") { return; }

    if (notice.target == -1) { return; }
    if (me) {
        message = GetMyInfo(me, message, aa_message);
    }
    if (notice.msg != "") {
        aaCenter.AA_StringReplace(message, "<$聊天信息>", notice.msg);
    }

    std::set<Player*> players;

    players.clear();
    if (notice.target == 3 || (me && me->GetTypeId() != TYPEID_PLAYER)) { // 全服触发
        players = aaCenter.GetOnlinePlayers();
    }
    else if (me && me->IsInWorld() && notice.target == 4) {
        if (me->GetTypeId() == TYPEID_PLAYER) {
            me->ToPlayer()->Say(message, LANG_UNIVERSAL);
        }
        else if (me->GetTypeId() == TYPEID_UNIT) {
            me->ToCreature()->Say(message.c_str(), LANG_UNIVERSAL, nullptr);
        }
    }
    else if (me && me->IsInWorld() && me->GetTypeId() == TYPEID_PLAYER) {
        Player* player = me->ToPlayer();
        if (!player) return;
        if (!player->IsInWorld()) return;
        players.insert(player);
        switch (notice.target) {
        case 0: // 个人
        { } break;
        case 1: // 团队
        {
            if (player->GetGroup()) {
                Group::MemberSlotList const& members = player->GetGroup()->GetMemberSlots();
                for (Group::MemberSlotList::const_iterator itr = members.begin(); itr != members.end(); ++itr)
                {
                    if (Player* p = ObjectAccessor::FindPlayer((*itr).guid)) {
                        if (!p->IsInWorld()) { continue; }
                        players.insert(p);
                    }
                }
            }
        }
        break;
        case 2: // 阵营
        {
            TeamId team = player->GetTeamId();
            const HashMapHolder<Player>::MapType& m = ObjectAccessor::GetPlayers();
            std::set<Player*> players;
            players.clear();
            for (HashMapHolder<Player>::MapType::const_iterator it = m.begin(); it != m.end(); ++it)
            {
                if (Player* player = it->second)
                {
                    if (!player->IsInWorld()) { continue; }
                    if (team != player->GetTeamId()) { continue; }
                    players.insert(player);
                }
            }
        }
        break;
        default:
            break;
        }
    }
    if (players.size() == 0) return;
    for (Player* p : players) {
        aaCenter.AA_SendMessage(p, notice.type, message.c_str());
    }
}

/*account*/
bool AACenter::AA_HasBattlegroundIp(Player* player)
{
    if (!player || !player->IsInWorld()) {
        return false;
    }
    std::string ip = player->GetSession()->GetRemoteAddress();
    if (ip != "") {
        std::set<std::string>::iterator itor;
        for (itor = aaCenter.aa_battleground_ips.begin(); itor != aaCenter.aa_battleground_ips.end(); itor++)
        {
            if (*itor == ip)
            {
                return true;
            }
        }
    }
    return false;
}

bool AACenter::AA_TeleportDied(Player* player)
{
    //二、_属性调整_地图
    AA_Map_Player_Conf m_conf = aaCenter.AA_GetAA_Map_Player_Conf(player);
    if (m_conf.zuobiao_lm == "" || m_conf.zuobiao_lm == "0" || m_conf.zuobiao_bl == "" || m_conf.zuobiao_bl == "0") {
        return false;
    }
    if (player->GetTeamId() == TEAM_ALLIANCE) {
        uint32 zuobiao_lm = aaCenter.AA_StringRandom(m_conf.zuobiao_lm);
        aaCenter.AA_TeleportMoban(player, zuobiao_lm);
    }
    else { //TEAM_HORDE
        uint32 zuobiao_bl = aaCenter.AA_StringRandom(m_conf.zuobiao_bl);
        aaCenter.AA_TeleportMoban(player, zuobiao_bl);
    }
    return true;
}

bool AACenter::AA_HasItemInBagCount(Player* player, uint32 item, uint32 count, uint32 bag) const
{
    uint32 tempcount = 0;
    //0所有背包物品 1所有银行物品 2所有背包+银行物品 18主背包 19-22副背包
    if (bag == 0 || bag == 2 || bag == 18) //检测主背包
    {
        for (uint8 i = INVENTORY_SLOT_ITEM_START; i < INVENTORY_SLOT_ITEM_END; i++) {
            Item* pItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, i);
            if (pItem && pItem->GetEntry() == item && !pItem->IsInTrade())
            {
                tempcount += pItem->GetCount();
                if (tempcount >= count)
                    return true;
            }
        }
    }
    if (bag == 0 || bag == 2 || (bag >= 19 && bag <= 22)) { //检测1-4背包物品
        for (uint8 i = INVENTORY_SLOT_BAG_START; i < INVENTORY_SLOT_BAG_END; i++)
        {
            Bag* pBag = player->GetBagByPos(i);
            if (pBag && (bag == 0 || i == bag))
            {
                for (uint32 j = 0; j < pBag->GetBagSize(); j++)
                {
                    Item* pItem = player->GetItemByPos(i, j);
                    if (pItem && pItem->GetEntry() == item && !pItem->IsInTrade())
                    {
                        tempcount += pItem->GetCount();
                        if (tempcount >= count)
                            return true;
                    }
                }
            }
        }
    }
    //检测银行物品
    if (bag == 1 || bag == 2) { //检测银行物品
        for (uint8 i = BANK_SLOT_ITEM_START; i < BANK_SLOT_ITEM_END; i++) {
            if (Item* pItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, i))
            {
                tempcount += pItem->GetCount();
                if (tempcount >= count)
                    return true;
            }
        }
        for (uint8 i = BANK_SLOT_BAG_START; i < BANK_SLOT_BAG_END; ++i)
        {
            if (Bag* pBag = player->GetBagByPos(i))
            {
                for (uint32 j = 0; j < pBag->GetBagSize(); ++j)
                {
                    if (Item* pItem = pBag->GetItemByPos(j))
                    {
                        tempcount += pItem->GetCount();
                        if (tempcount >= count)
                            return true;
                    }
                }
            }
        }
    }
    return false;
}

void AACenter::AA_DestroyItemInBagCount(Player* player, uint32 itemEntry, uint32 count, bool update, bool unequip_check)
{
    TC_LOG_DEBUG("entities.player.items", "Player::DestroyItemCount: Player '{}' ({}), Item: {}, Count: {}",
        player->GetName(), player->GetGUID().ToString(), itemEntry, count);
    uint32 remcount = 0;

    // in inventory
    uint8 inventoryEnd = INVENTORY_SLOT_ITEM_START + player->GetInventorySlotCount();
    for (uint8 i = INVENTORY_SLOT_ITEM_START; i < inventoryEnd; ++i)
    {
        if (Item* item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, i))
        {
            if (item->GetEntry() == itemEntry && !item->IsInTrade())
            {
                if (item->GetCount() + remcount <= count)
                {
                    // all items in inventory can unequipped
                    remcount += item->GetCount();
                    player->DestroyItem(INVENTORY_SLOT_BAG_0, i, update);

                    if (remcount >= count)
                        return;
                }
                else
                {
                    item->SetCount(item->GetCount() - count + remcount);
                    player->ItemRemovedQuestCheck(item->GetEntry(), count - remcount);
                    if (player->IsInWorld() && update)
                        item->SendUpdateToPlayer(player);
                    item->SetState(ITEM_CHANGED, player);
                    return;
                }
            }
        }
    }

    // in inventory bags
    for (uint8 i = INVENTORY_SLOT_BAG_START; i < INVENTORY_SLOT_BAG_END; i++)
    {
        if (Bag* bag = player->GetBagByPos(i))
        {
            for (uint32 j = 0; j < bag->GetBagSize(); j++)
            {
                if (Item* item = bag->GetItemByPos(j))
                {
                    if (item->GetEntry() == itemEntry && !item->IsInTrade())
                    {
                        // all items in bags can be unequipped
                        if (item->GetCount() + remcount <= count)
                        {
                            remcount += item->GetCount();
                            player->DestroyItem(i, j, update);

                            if (remcount >= count)
                                return;
                        }
                        else
                        {
                            item->SetCount(item->GetCount() - count + remcount);
                            player->ItemRemovedQuestCheck(item->GetEntry(), count - remcount);
                            if (player->IsInWorld() && update)
                                item->SendUpdateToPlayer(player);
                            item->SetState(ITEM_CHANGED, player);
                            return;
                        }
                    }
                }
            }
        }
    }
}

std::set<Creature*> AACenter::AA_GetCreatureRange(Player* me, std::string gm)
{
    std::set<Creature*> creatures; creatures.clear();
    if (gm.find("<$地图生物") != std::string::npos) {
        int32 mapId = me->GetMapId();
        int32 mapId1 = mapId;
        if (gm.find("<$地图生物@") != std::string::npos) {
            std::string prestr = "<$地图生物@";
            std::string tmpstr = aaCenter.AA_StringGet(gm, prestr, ">");
            if (tmpstr != "") {
                mapId1 = int32(std::atoi(tmpstr.c_str()));
            }
        }
        std::list<Creature*> list; list.clear();
        aaCenter.BB_GetCreatureListInMap(me, list, mapId1);
        for (Creature* c : list)
        {
            if (!c || !c->IsInWorld() || !c->IsAlive()) {
                continue;
            }
            creatures.insert(c);
        }
    }
    return creatures;
}

std::set<Player*> AACenter::AA_GetPlayerRange(Player* me, std::string gm)
{
    std::set<Player*> players; players.clear();
    if (gm.find("<$队长") != std::string::npos) {
        if (me->GetGroup()) {
            Group::MemberSlotList const& members = me->GetGroup()->GetMemberSlots();
            for (Group::MemberSlotList::const_iterator itr = members.begin(); itr != members.end(); ++itr)
            {
                if (Player* p = ObjectAccessor::FindPlayer((*itr).guid)) {
                    if (!p->IsInWorld() || p->GetGUID() != me->GetGroup()->GetLeaderGUID()) { continue; }
                    players.insert(p);
                }
            }
        }
        else {
            me->SetTarget(me->GetGUID());
            me->SetSelection(me->GetGUID());
            players.insert(me);
        }
    }
    if (gm.find("<$队伍") != std::string::npos) {
        if (me->GetGroup()) {
            Group::MemberSlotList const& members = me->GetGroup()->GetMemberSlots();
            for (Group::MemberSlotList::const_iterator itr = members.begin(); itr != members.end(); ++itr)
            {
                if (Player* p = ObjectAccessor::FindPlayer((*itr).guid)) {
                    if (!p->IsInWorld()) { continue; }
                    players.insert(p);
                }
            }
        }
    }
    if (gm.find("<$公会") != std::string::npos) {
        std::string guild = me->GetGuildName();
        std::string guild1 = "";
        if (gm.find("<$公会@") != std::string::npos) {
            std::string prestr = "<$公会@";
            guild1 = aaCenter.AA_StringGet(gm, prestr, ">");
        }
        const HashMapHolder<Player>::MapType& m = ObjectAccessor::GetPlayers();
        for (HashMapHolder<Player>::MapType::const_iterator it = m.begin(); it != m.end(); ++it)
        {
            if (Player* p = it->second)
            {
                if (!p->IsInWorld()) { continue; }
                if (guild1 != "") { //输入了第三参数公会名，则按第三参数匹配
                    if (guild1 != p->GetGuildName()) { continue; }
                }
                else { //否则按自身的公会名，作为参数匹配
                    if (guild != p->GetGuildName()) { continue; }
                }
                players.insert(p);
            }
        }
    }
    if (gm.find("<$阵营") != std::string::npos) {
        TeamId team = me->GetTeamId();
        TeamId team1 = TEAM_NEUTRAL;
        if (gm.find("<$阵营@") != std::string::npos) {
            std::string prestr = "<$阵营@";
            std::string tmpstr = aaCenter.AA_StringGet(gm, prestr, ">");
            if (tmpstr == "部落") {
                team1 = TEAM_HORDE;
            }
            else if (tmpstr == "联盟") {
                team1 = TEAM_ALLIANCE;
            }
            else {
                team1 = TEAM_NEUTRAL;
            }
        }
        const HashMapHolder<Player>::MapType& m = ObjectAccessor::GetPlayers();
        for (HashMapHolder<Player>::MapType::const_iterator it = m.begin(); it != m.end(); ++it)
        {
            if (Player* p = it->second)
            {
                if (!p->IsInWorld()) { continue; }
                if (team1 != TEAM_NEUTRAL) { //输入了第三参数阵营，则按第三参数匹配
                    if (team1 != p->GetTeamId()) { continue; }
                }
                else { //否则按自身的阵营，作为参数匹配
                    if (team != p->GetTeamId()) { continue; }
                }
                players.insert(p);
            }
        }
    }
    if (gm.find("<$性别") != std::string::npos) {
        uint8 gender = me->GetGender();
        uint8 gender1 = GENDER_NONE;
        if (gm.find("<$性别@") != std::string::npos) {
            std::string prestr = "<$性别@";
            std::string tmpstr = aaCenter.AA_StringGet(gm, prestr, ">");
            if (tmpstr == "男") {
                gender1 = GENDER_MALE;
            }
            else if (tmpstr == "女") {
                gender1 = GENDER_FEMALE;
            }
            else {
                gender1 = GENDER_NONE;
            }
        }
        const HashMapHolder<Player>::MapType& m = ObjectAccessor::GetPlayers();
        for (HashMapHolder<Player>::MapType::const_iterator it = m.begin(); it != m.end(); ++it)
        {
            if (Player* p = it->second)
            {
                if (!p->IsInWorld()) { continue; }
                if (gender1 != GENDER_NONE) { //输入了第三参数男女，则按第三参数匹配
                    if (gender1 != p->GetGender()) { continue; }
                }
                else { //否则按自身的性别，作为参数匹配
                    if (gender != p->GetGender()) { continue; }
                }
                players.insert(p);
            }
        }
    }
    if (gm.find("<$种族") != std::string::npos) {
        uint8 race = me->GetRace();
        uint8 race1 = RACE_NONE;
        if (gm.find("<$种族@") != std::string::npos) {
            std::string prestr = "<$种族@";
            std::string tmpstr = aaCenter.AA_StringGet(gm, prestr, ">");
            if (tmpstr != "") {
                race1 = uint8(std::atoi(tmpstr.c_str()));
            }
        }
        const HashMapHolder<Player>::MapType& m = ObjectAccessor::GetPlayers();
        for (HashMapHolder<Player>::MapType::const_iterator it = m.begin(); it != m.end(); ++it)
        {
            if (Player* p = it->second)
            {
                if (!p->IsInWorld()) { continue; }
                if (race1 != RACE_NONE) { //输入了第三参数种族，则按第三参数匹配
                    if (race1 != p->GetRace()) { continue; }
                }
                else { //否则按自身的种族，作为参数匹配
                    if (race != p->GetRace()) { continue; }
                }
                players.insert(p);
            }
        }
    }
    if (gm.find("<$职业") != std::string::npos) {
        uint8 race = me->GetClass();
        uint8 race1 = RACE_NONE;
        if (gm.find("<$职业@") != std::string::npos) {
            std::string prestr = "<$职业@";
            std::string tmpstr = aaCenter.AA_StringGet(gm, prestr, ">");
            if (tmpstr != "") {
                race1 = uint8(std::atoi(tmpstr.c_str()));
            }
        }
        const HashMapHolder<Player>::MapType& m = ObjectAccessor::GetPlayers();
        for (HashMapHolder<Player>::MapType::const_iterator it = m.begin(); it != m.end(); ++it)
        {
            if (Player* p = it->second)
            {
                if (!p->IsInWorld()) { continue; }
                if (race1 != RACE_NONE) { //输入了第三参数种族，则按第三参数匹配
                    if (race1 != p->GetClass()) { continue; }
                }
                else { //否则按自身的种族，作为参数匹配
                    if (race != p->GetClass()) { continue; }
                }
                players.insert(p);
            }
        }
    }
    else if (gm.find("<$IP") != std::string::npos) {
        std::string ip = me->GetSession()->GetRemoteAddress();
        if (ip != "") {
            std::string ip1 = "";
            if (gm.find("<$IP@") != std::string::npos) {
                std::string prestr = "<$IP@";
                std::string tmpstr = aaCenter.AA_StringGet(gm, prestr, ">");
                if (tmpstr != "") {
                    ip1 = tmpstr;
                }
            }
            const HashMapHolder<Player>::MapType& m = ObjectAccessor::GetPlayers();
            for (HashMapHolder<Player>::MapType::const_iterator it = m.begin(); it != m.end(); ++it)
            {
                if (Player* p = it->second)
                {
                    std::string ip = p->GetSession()->GetRemoteAddress();
                    if (ip != "") {
                        if (!p->IsInWorld()) { continue; }
                        if (ip1 != "") { //输入了第三参数IP，则按第三参数匹配
                            if (ip1 != p->GetSession()->GetRemoteAddress()) { continue; }
                        }
                        else { //否则按自身的IP，作为参数匹配
                            if (ip != p->GetSession()->GetRemoteAddress()) { continue; }
                        }
                        players.insert(p);
                    }
                }
            }
        }
    }
    if (gm.find("<$在线玩家>") != std::string::npos) {
        const HashMapHolder<Player>::MapType& m = ObjectAccessor::GetPlayers();
        for (HashMapHolder<Player>::MapType::const_iterator it = m.begin(); it != m.end(); ++it)
        {
            if (Player* p = it->second)
            {
                if (!p->IsInWorld()) { continue; }
                players.insert(p);
            }
        }
    }
    if (gm.find("<$在线玩家IP>") != std::string::npos) {
        const HashMapHolder<Player>::MapType& m = ObjectAccessor::GetPlayers();
        std::set<std::string> ips; ips.clear();
        for (HashMapHolder<Player>::MapType::const_iterator it = m.begin(); it != m.end(); ++it)
        {
            if (Player* p = it->second)
            {
                if (!p->IsInWorld()) { continue; }
                std::string ip = p->GetSession()->GetRemoteAddress();
                if (ip != "") {
                    if (std::find(ips.begin(), ips.end(), ip) == ips.end()) {
                        players.insert(p);
                    }
                    ips.insert(ip);
                }
            }
        }
    }
    if (gm.find("<$名字") != std::string::npos) {
        if (gm.find("<$名字@") != std::string::npos) {
            std::string prestr = "<$名字@";
            std::string tmpstr = aaCenter.AA_StringGet(gm, prestr, ">");
            if (Player* p = ObjectAccessor::FindPlayerByName(tmpstr)) {
                if (p->IsInWorld()) {
                    players.insert(p);
                }
            }
        }
    }
    if (gm.find("<$自身>") != std::string::npos) {
        me->SetTarget(me->GetGUID());
        me->SetSelection(me->GetGUID());
        players.insert(me);
    }
    if (gm.find("<$目标>") != std::string::npos) {
        if (Unit* unit = me->GetSelectedUnit()) {
            me->SetTarget(unit->GetGUID());
            me->SetSelection(unit->GetGUID());
            if (Player* p = unit->ToPlayer()) {
                players.insert(p);
            }
        }
    }
    if (gm.find("<$招募者>") != std::string::npos) {
        ObjectGuid::LowType guidlow = me->GetGUIDLow();
        QueryResult result = CharacterDatabase.PQuery("SELECT 招募者姓名 from _玩家角色数据 where guid = {}", guidlow);
        if (result) {
            Field* fields = result->Fetch();
            std::string zhaomu = fields[0].GetString();
            if (zhaomu != "") {
                if (Player* p = ObjectAccessor::FindPlayerByName(zhaomu))
                {
                    if (p->IsInWorld()) {
                        players.insert(p);
                    }
                }
            }
        }
    }
    if (gm.find("<$被招募者>") != std::string::npos) {
        std::string name = me->GetName();
        QueryResult result = CharacterDatabase.PQuery("SELECT guid from _玩家角色数据 where 招募者姓名 = '{}'", name);
        std::set<uint32> guids; guids.clear();
        if (result) {
            do {
                Field* fields = result->Fetch();
                ObjectGuid::LowType guid = fields[0].GetUInt32();
                if (guid > 0) {
                    guids.insert(guid);
                }
            } while (result->NextRow());
        }
        const HashMapHolder<Player>::MapType& m = ObjectAccessor::GetPlayers();
        for (HashMapHolder<Player>::MapType::const_iterator it = m.begin(); it != m.end(); ++it)
        {
            if (Player* p = it->second)
            {
                if (!p->IsInWorld()) { continue; }
                if (std::find(guids.begin(), guids.end(), p->GetGUIDLow()) != guids.end()) {
                    continue;
                }
                players.insert(p);
            }
        }
    }
    return players;
}
std::string AACenter::AA_GetPlayerColor(Player* player)
{
    uint8 class1 = player->GetClass();
    switch (class1) {
    case CLASS_NONE:
        return "";
    case CLASS_WARRIOR:
        return MSG_COLOR_WARRIOR;
    case CLASS_PALADIN:
        return MSG_COLOR_PALADIN;
    case CLASS_HUNTER:
        return MSG_COLOR_HUNTER;
    case CLASS_ROGUE:
        return MSG_COLOR_ROGUE;
    case CLASS_PRIEST:
        return MSG_COLOR_PRIEST;
    case CLASS_DEATH_KNIGHT:
        return MSG_COLOR_DEATH_KNIGHT;
    case CLASS_SHAMAN:
        return MSG_COLOR_SHAMAN;
    case CLASS_MAGE:
        return MSG_COLOR_MAGE;
    case CLASS_WARLOCK:
        return MSG_COLOR_WARLOCK;
    case CLASS_DRUID:
        return MSG_COLOR_DRUID;
    default:
        return "";
    }
}

std::string AACenter::AA_GetPlayerNameLink(Player* player)
{
    std::string name = player->GetName();
    std::string namecolor = AA_GetPlayerColor(player);
    return namecolor + "|Hplayer:" + name + "|h" + name + "|h|r";
}

void AACenter::AA_ApplyItemBonuses(Player* player, Item* pItem, bool apply, bool isShuangjia)
{
    uint8 slot = pItem->GetSlot();
    ItemTemplate const* pProto = pItem->GetTemplate();

    if (!pProto) {
        return;
    }

    uint8 bagslot = pItem->GetBagSlot();
    if (bagslot != INVENTORY_SLOT_BAG_0 || (bagslot == INVENTORY_SLOT_BAG_0 && slot >= INVENTORY_SLOT_BAG_END)) {
        if (!isShuangjia && !aaCenter.AA_IsShenQiItem(pItem)) {
            return;
        }
    }

    //基础属性，极品，强化，成长，附魔，符文，符文组合
    ObjectGuid::LowType guidlow = pItem->GetGUIDLow();
    AA_Character_Instance conf = aaCenter.aa_character_instances[guidlow];
    std::vector<int32> types; types.clear();
    std::vector<int32> values; values.clear();
    aaCenter.AA_StringToVector2(conf.fugai, types, values);
    std::vector<int32> jd_values; jd_values.clear();
    aaCenter.AA_StringToVectorInt(conf.jd_values, jd_values, ",");
    std::vector<int32> qh_values; qh_values.clear();
    aaCenter.AA_StringToVectorInt(conf.qh_values, qh_values, ",");
    std::vector<int32> cz_values; cz_values.clear();
    aaCenter.AA_StringToVectorInt(conf.cz_values, cz_values, ",");
    std::vector<int32> fm_types; fm_types.clear();
    std::vector<int32> fm_values; fm_values.clear();
    aaCenter.AA_StringToVector2(conf.fm_values, fm_types, fm_values);
    std::vector<int32> fw_values; fw_values.clear();
    aaCenter.AA_StringToVectorInt(conf.fw_values, fw_values, ",");
    std::vector<int32> fwzh_values; fwzh_values.clear();
    aaCenter.AA_StringToVectorInt(conf.fwzh_values, fwzh_values, ",");
    //数组初始化，防错
    size_t typesize = types.size();
    if (jd_values.size() == 0) {
        for (size_t i = 0; i < typesize; i++) {
            jd_values.push_back(0);
        }
    }
    if (qh_values.size() == 0) {
        for (size_t i = 0; i < typesize; i++) {
            qh_values.push_back(0);
        }
    }
    if (cz_values.size() == 0) {
        for (size_t i = 0; i < typesize; i++) {
            cz_values.push_back(0);
        }
    }

    //随机附魔
    if (fm_types.size() == fm_values.size()) {
        if (fm_types.size() == conf.fm_value_count) {
            for (uint32 i = 0; i < conf.fm_value_count; ++i)
            {
                uint32 statType = 0;
                int32  val = 0;
                uint32 statid = fm_types[i];
                val = fm_values[i];
                statType = aaCenter.aa_stats[statid].type;
                if (val == 0)
                    continue;
                aaCenter.AddValue(player, statType, val, apply);
            }
        }
    }
    //符文
    if (conf.fw_count > 0 && conf.fw_values != "" && conf.fw_values != "0") {
        std::vector<int32> fwids; fwids.clear();
        aaCenter.AA_StringToVectorInt(conf.fw_values, fwids, ",");
        for (size_t i = 0; i < fwids.size(); i++) {
            uint32 fwid = fwids[i];
            if (fwid == 0) { continue; }

            AA_Fw_Conf fwconf = aaCenter.aa_fw_confs[fwid];
            std::vector<int32> types; types.clear();
            std::vector<int32> values; values.clear();
            aaCenter.AA_StringToVector2(fwconf.values, types, values);
            for (size_t j = 0; j < values.size(); j++) {
                if (values[j] == 0) {
                    continue;
                }
                int32 type = types[j];
                aaCenter.AddValue(player, type, values[j], apply);
            }
        }
    }

    //符文组合
    if (conf.fwzh_values != "" && conf.fwzh_values != "0") {
        std::vector<int32> fwids; fwids.clear();
        aaCenter.AA_StringToVectorInt(conf.fwzh_values, fwids, ",");
        for (size_t i = 0; i < fwids.size(); i++) {
            uint32 fwid = fwids[i];
            if (fwid == 0) { continue; }
            AA_FwZh_Conf fwconf = aaCenter.aa_fwzh_confs[fwid];
            std::vector<int32> types; types.clear();
            std::vector<int32> values; values.clear();
            aaCenter.AA_StringToVector2(fwconf.values, types, values);
            for (size_t j = 0; j < values.size(); j++) {
                if (values[j] == 0) {
                    continue;
                }
                int32 type = types[j];
                aaCenter.AddValue(player, type, values[j], apply);
            }
        }
    }
    //宝石
    if (uint32 entry = aaCenter.AA_GetBaoshiEntry(pItem, 0)) {
        ItemTemplate const* pProto = sObjectMgr->GetItemTemplate(entry);
        if (pProto) {
            AA_Baoshi_Conf conf = aaCenter.aa_baoshi_confs[entry];
            if (conf.itemid > 0 && conf.values != "" && conf.values != "0") {
                std::map<int32, int32> baoshis; baoshis.clear();
                aaCenter.AA_StringToMap(conf.values, baoshis);
                for (auto itr : baoshis) {
                    if (itr.second <= 0) {
                        continue;
                    }
                    aaCenter.AddValue(player, itr.first, itr.second, apply);
                }
            }
        }
    }
    //强化、极品、成长
    float minDamage0 = 0;
    float maxDamage0 = 0;
    float minDamage1 = 0;
    float maxDamage1 = 0;
    uint32 delay = 0;
    if (types.size() > 0 && types.size() == values.size()) {
        for (size_t i = 0; i < types.size(); i++)
        {
            uint32 statTypeId = 0;
            int32  val = 0;
            // If set ScalingStatDistribution need get stats and values from it
            statTypeId = types[i];
            val = values[i];
            //极品
            int32 nonsuch_val = jd_values[i];
            val = val + nonsuch_val;
            //强化
            int32 upgrade_val = qh_values[i];
            val = val + upgrade_val;
            int32 upgrade_id = conf.qh_id;
            uint32 upgrade_percent = aaCenter.aa_item_upgrades[upgrade_id].reward_percent;
            val = val + qh_values[i] * (upgrade_percent / 100.0); //强化百分比奖励
            uint32 upgrade_value = aaCenter.aa_item_upgrades[upgrade_id].reward_value;
            val += upgrade_value; //强化数值奖励
            //成长
            int32 cz_val = cz_values[i];
            val = val + cz_val;
            int32 cz_id = conf.cz_id;
            uint32 cz_percent = aaCenter.aa_item_levels[cz_id].reward_percent;
            val = val + cz_values[i] * (cz_percent / 100.0); //强化百分比奖励
            uint32 cz_value = aaCenter.aa_item_levels[cz_id].reward_value;
            val += cz_value; //强化数值奖励

            if (val == 0)
                continue;

            AA_Stat stat_conf = aaCenter.aa_stats[statTypeId];
            aaCenter.AddValue(player, stat_conf.type, val, apply);

            switch (stat_conf.type)
            {
            case 120://速度
                delay = values[i];
                break;
            case 121:
                minDamage0 = val;
                break;
            case 123:
            case 125:
            case 127:
            case 129:
            case 131:
            case 133://最小伤害
                minDamage1 = val;
                break;
            case 122:
                maxDamage0 = val;
                break;
            case 124:
            case 126:
            case 128:
            case 130:
            case 132:
            case 134://最大伤害
                maxDamage1 = val;
                break;
            case 135://护甲
            {
                uint32 armor = val;
                player->HandleStatFlatModifier(UNIT_MOD_ARMOR, TOTAL_VALUE, float(armor), apply);
            }
            break;
            case 136://盾牌格挡值
                player->HandleBaseModFlatValue(SHIELD_BLOCK_VALUE, float(val), apply);
                break;
            default:
                break;
            }
        }
    }

    WeaponAttackType attType = Player::GetAttackBySlot(slot, pProto->GetInventoryType());
    if (!player->IsInFeralForm() && apply && !player->CanUseAttackType(attType))
        return;

    float damage = 0.0f;
    uint32 itemLevel = pItem->GetItemLevel(player);

    if (minDamage1 > 0)
    {
        damage = apply ? minDamage1 : BASE_MINDAMAGE;
        player->SetBaseWeaponDamage(attType, MINDAMAGE, damage);
    }

    if (maxDamage1 > 0)
    {
        damage = apply ? maxDamage1 : BASE_MAXDAMAGE;
        player->SetBaseWeaponDamage(attType, MAXDAMAGE, damage);
    }

    SpellShapeshiftFormEntry const* shapeshift = sSpellShapeshiftFormStore.LookupEntry(player->GetShapeshiftForm());
    if (delay && !(shapeshift && shapeshift->CombatRoundTime))
        player->SetBaseAttackTime(attType, apply ? delay : BASE_ATTACK_TIME);

    int32 weaponBasedAttackPower = apply ? int32(pProto->GetDPS(itemLevel) * 6.0f) : 0;
    switch (attType)
    {
    case BASE_ATTACK:
        player->SetMainHandWeaponAttackPower(weaponBasedAttackPower);
        break;
    case OFF_ATTACK:
        player->SetOffHandWeaponAttackPower(weaponBasedAttackPower);
        break;
    case RANGED_ATTACK:
        player->SetRangedWeaponAttackPower(weaponBasedAttackPower);
        break;
    default:
        break;
    }

    if (player->CanModifyStats() && (damage || pProto->GetDelay()))
        player->UpdateDamagePhysical(attType);
}

std::string AACenter::GetPlayerClass(uint8 class1)
{
    std::string s8 = "";
    switch (class1) {
    case CLASS_WARRIOR:
        s8 = "战士";
        break;
    case CLASS_PALADIN:
        s8 = "圣骑士";
        break;
    case CLASS_HUNTER:
        s8 = "猎人";
        break;
    case CLASS_ROGUE:
        s8 = "潜行者";
        break;
    case CLASS_PRIEST:
        s8 = "牧师";
        break;
    case CLASS_DEATH_KNIGHT:
        s8 = "死亡骑士";
        break;
    case CLASS_SHAMAN:
        s8 = "萨满";
        break;
    case CLASS_MAGE:
        s8 = "法师";
        break;
    case CLASS_WARLOCK:
        s8 = "术士";
        break;
    case CLASS_DRUID:
        s8 = "德鲁伊";
        break;
    default:
        break;
    }
    return s8;
}
std::string AACenter::GetPlayerRace(Player* player)
{
    std::string s7 = "";
    switch (player->GetRace()) {
    case RACE_HUMAN:
        s7 = "人类";
        break;
    case RACE_ORC:
        s7 = "兽人";
        break;
    case RACE_DWARF:
        s7 = "矮人";
        break;
    case RACE_NIGHTELF:
        s7 = "暗夜精灵";
        break;
    case RACE_UNDEAD_PLAYER:
        s7 = "亡灵";
        break;
    case RACE_TAUREN:
        s7 = "牛头人";
        break;
    case RACE_GNOME:
        s7 = "侏儒";
        break;
    case RACE_TROLL:
        s7 = "巨魔";
        break;
    case RACE_BLOODELF:
        s7 = "血精灵";
        break;
    case RACE_DRAENEI:
        s7 = "德莱尼";
        break;
    default:
        break;
    }
    return s7;
}
std::string AACenter::GetPlayerFaction(Player* player)
{
    std::string s6 = "";
    //    #ifdef AZEROTHCORE
    if (player->GetTeamId() == TEAM_HORDE) {
        s6 = "部落";
    }
    else if (player->GetTeamId() == TEAM_ALLIANCE) {
        s6 = "联盟";
    }
    //    #else
    //        if (player->GetTeam() == HORDE) {
    //            s6 = "部落";
    //        } else if (player->GetTeam() == ALLIANCE) {
    //            s6 = "联盟";
    //        }
    //    #endif
    return s6;
}
AA_Player_Stats_Conf AACenter::AA_GetPlayerStatConfWithMap(Unit const* unit)
{
    AA_Player_Stats_Conf conf;
    if (!unit || !unit->IsInWorld() || !unit->GetMap()) {
        return conf;
    }
    int32 class1 = -1;
    int32 areaId = unit->GetAreaId();
    int32 zoneId = unit->GetZoneId();
    int32 mapId = unit->GetMapId();
    if (Player const*p = unit->ToPlayer()) {
        class1 = p->GetClass();
    }

    if (class1 == -1) return conf;

    uint32 statid = 0;
    if (statid == 0) {
        statid = aa_player_stats_conf_areas[areaId][class1];
    }
    if (statid == 0) {
        statid = aa_player_stats_conf_zones[zoneId][class1];
    }
    if (statid == 0) {
        statid = aa_player_stats_conf_maps[mapId][class1];
    }
    if (statid == 0) {
        statid = aa_player_stats_conf_alls[class1];
    }
    if (statid > 0) {
        conf = aaCenter.aa_player_stats_confs[statid];
    }
    return conf;
}

std::string AACenter::GetMyInfo(Unit* me, std::string message, AA_Message aa_message, bool nnn) {
    if (!me) {
        return "";
    }
    if (me->GetTypeId() == TYPEID_UNIT || me->GetTypeId() == TYPEID_PLAYER) {
        if (message.find("<$地图>") != std::string::npos) {
            aaCenter.AA_StringReplace(message, "<$地图>", me->GetMap()->GetMapName());
        }
        if (message.find("<$x>") != std::string::npos) {
            aaCenter.AA_StringReplace(message, "<$x>", std::to_string(me->GetPositionX()));
        }
        if (message.find("<$y>") != std::string::npos) {
            aaCenter.AA_StringReplace(message, "<$y>", std::to_string(me->GetPositionY()));
        }
        if (message.find("<$z>") != std::string::npos) {
            aaCenter.AA_StringReplace(message, "<$z>", std::to_string(me->GetPositionZ()));
        }
        if (message.find("<$o>") != std::string::npos) {
            aaCenter.AA_StringReplace(message, "<$o>", std::to_string(me->GetOrientation()));
        }
    }
    if (me->GetTypeId() == TYPEID_UNIT) {
        if (Creature* creature = me->ToCreature()) {
            if (message.find("<$生物名称>") != std::string::npos) {
                aaCenter.AA_StringReplace(message, "<$生物名称>", creature->GetName());
            }
        }
    }
    if (me->GetTypeId() == TYPEID_PLAYER) {
        Player* player = me->ToPlayer();
        ObjectGuid::LowType guidlow = player->GetGUIDLow();
        uint32 accountid = player->GetSession()->GetAccountId();
        AA_Account aconf = aaCenter.aa_accounts[accountid];
        AA_Characters cconf = aaCenter.aa_characterss[guidlow];

        AA_Characters_Junxian jxcconf = aaCenter.aa_characters_junxians[guidlow];
        AA_Characters_Dianfeng dfcconf = aaCenter.aa_characters_dianfengs[guidlow];
        AA_Characters_Douqi dqcconf = aaCenter.aa_characters_douqis[guidlow];

        AA_Vip_Conf vipconf = aaCenter.aa_vip_confs[aconf.vip];
        AA_Junxian_Conf jxconf = aaCenter.aa_junxian_confs[jxcconf.level];
        AA_Dianfeng_Conf dfconf = aaCenter.aa_dianfeng_confs[dfcconf.level];
        AA_Douqi_Conf dqconf = aaCenter.aa_douqi_confs[dqcconf.level];

        //角色种族，角色职业，角色
        if (!nnn) {
            aaCenter.AA_StringReplace(message, "\\n", "\n");
        }
        if (message.find("<$角色全名>") != std::string::npos) {
            aaCenter.AA_StringReplace(message, "<$角色全名>", cconf.name_pre + player->GetName() + cconf.name_suf);
        }
        if (message.find("<$角色姓名黑色>") != std::string::npos) {
            aaCenter.AA_StringReplace(message, "<$角色姓名黑色>", player->GetName());
        }
        if (message.find("<$角色姓名>") != std::string::npos) {
            aaCenter.AA_StringReplace(message, "<$角色姓名>", AA_GetPlayerNameLink(player));
        }
        if (message.find("<$角色种族>") != std::string::npos) {
            aaCenter.AA_StringReplace(message, "<$角色种族>", GetPlayerRace(player));
        }
        if (message.find("<$角色阵营>") != std::string::npos) {
            aaCenter.AA_StringReplace(message, "<$角色阵营>", GetPlayerFaction(player));
        }
        if (message.find("<$角色职业>") != std::string::npos) {
            aaCenter.AA_StringReplace(message, "<$角色职业>", GetPlayerClass(player->GetClass()));
        }
        if (message.find("<$角色等级>") != std::string::npos) {
            aaCenter.AA_StringReplace(message, "<$角色等级>", std::to_string(player->GetLevel()));
        }
        if (message.find("<$连杀数量>") != std::string::npos) {
            aaCenter.AA_StringReplace(message, "<$连杀数量>", std::to_string(player->liansha));
        }
        if (message.find("<$地图>") != std::string::npos) {
            aaCenter.AA_StringReplace(message, "<$地图>", player->GetMap()->GetMapName());
        }
        if (message.find("<$x>") != std::string::npos) {
            aaCenter.AA_StringReplace(message, "<$x>", std::to_string(player->GetPositionX()));
        }
        if (message.find("<$y>") != std::string::npos) {
            aaCenter.AA_StringReplace(message, "<$y>", std::to_string(player->GetPositionY()));
        }
        if (message.find("<$z>") != std::string::npos) {
            aaCenter.AA_StringReplace(message, "<$z>", std::to_string(player->GetPositionZ()));
        }
        if (message.find("<$o>") != std::string::npos) {
            aaCenter.AA_StringReplace(message, "<$o>", std::to_string(player->GetOrientation()));
        }
        if (message.find("<$会员等级>") != std::string::npos) {
            aaCenter.AA_StringReplace(message, "<$会员等级>", std::to_string(vipconf.level));
        }

        //自定义关键字
        if (message.find("<$自定义角色@") != string::npos) {
            std::string prestr = "<$自定义角色@";
            std::string nums = aaCenter.AA_StringGet(message, prestr, ">");
            if (nums != "") {
                std::string fulstr = prestr + nums + ">";
                std::string m_diy_guids = cconf.diy_guid;
                std::map<std::string, std::string> mdiy_guids; mdiy_guids.clear();
                aaCenter.AA_StringToStringMap(m_diy_guids, mdiy_guids);
                std::string diy_value = mdiy_guids[nums];
                diy_value = diy_value == "" ? "0" : diy_value;
                int value = aaCenter.AA_StringInt32(diy_value);
                aaCenter.AA_StringReplace(message, fulstr, std::to_string(value));
            }
        }
        if (message.find("<$自定义账号@") != string::npos) {
            std::string prestr = "<$自定义账号@";
            std::string nums = aaCenter.AA_StringGet(message, prestr, ">");
            if (nums != "") {
                std::string fulstr = prestr + nums + ">";
                std::string m_diy_accounts = aconf.diy_account;
                std::map<std::string, std::string> mdiy_accounts; mdiy_accounts.clear();
                aaCenter.AA_StringToStringMap(m_diy_accounts, mdiy_accounts);
                std::string diy_value = mdiy_accounts[nums];
                diy_value = diy_value == "" ? "0" : diy_value;
                int value = aaCenter.AA_StringInt32(diy_value);
                aaCenter.AA_StringReplace(message, fulstr, std::to_string(value));
            }
        }
        if (message.find("<$自定义系统@") != string::npos) {
            std::string prestr = "<$自定义系统@";
            std::string nums = aaCenter.AA_StringGet(message, prestr, ">");
            if (nums != "") {
                std::string fulstr = prestr + nums + ">";
                std::string m_diy_systems = aaCenter.aa_system_conf.diy_system;
                std::map<std::string, std::string> mdiy_systems; mdiy_systems.clear();
                aaCenter.AA_StringToStringMap(m_diy_systems, mdiy_systems);
                std::string diy_value = mdiy_systems[nums];
                diy_value = diy_value == "" ? "0" : diy_value;
                int value = aaCenter.AA_StringInt32(diy_value);
                aaCenter.AA_StringReplace(message, fulstr, std::to_string(value));
            }
        }
        if (message.find("<$会员升级需求>") != std::string::npos) {
            std::string xq = "<$需求@" + std::to_string(vipconf.need) + ">";
            aaCenter.AA_StringReplace(message, "<$会员升级需求>", xq);
        }
        if (message.find("<$会员达到等级角色奖励>") != std::string::npos) {
            std::string xq = "<$奖励@" + std::to_string(vipconf.reward) + ">";
            aaCenter.AA_StringReplace(message, "<$会员达到等级角色奖励>", xq);
        }
        if (message.find("<$会员创建角色奖励>") != std::string::npos) {
            std::string xq = "<$奖励@" + std::to_string(vipconf.add_reward) + ">";
            aaCenter.AA_StringReplace(message, "<$会员创建角色奖励>", xq);
        }
        if (message.find("<$会员泡点额外的奖励>") != std::string::npos) {
            std::string xq = "<$奖励@" + std::to_string(vipconf.paodian) + ">";
            aaCenter.AA_StringReplace(message, "<$会员泡点额外的奖励>", xq);
        }
        if (message.find("<$会员天赋点>") != std::string::npos) {
            aaCenter.AA_StringReplace(message, "<$会员天赋点>", std::to_string(vipconf.talent));
        }
        if (message.find("<$会员经验倍数>") != std::string::npos) {
            aaCenter.AA_StringReplace(message, "<$会员经验倍数>", aaCenter.AA_StringFromFloat(vipconf.exp));
        }
        if (message.find("<$会员增加专业技能数量>") != std::string::npos) {
            aaCenter.AA_StringReplace(message, "<$会员增加专业技能数量>", std::to_string(vipconf.zhuanye));
        }
        if (message.find("<$会员掉落几率倍率>") != std::string::npos) {
            aaCenter.AA_StringReplace(message, "<$会员掉落几率倍率>", aaCenter.AA_StringFromFloat(vipconf.loot));
        }
        if (message.find("<$会员掉落数量倍率>") != std::string::npos) {
            aaCenter.AA_StringReplace(message, "<$会员掉落数量倍率>", std::to_string(vipconf.shuliang));
        }
        if (message.find("<$会员掉落数量触发几率>") != std::string::npos) {
            aaCenter.AA_StringReplace(message, "<$会员掉落数量触发几率>", aaCenter.AA_StringFromFloat(vipconf.shuliang_chance));
        }
        if (message.find("<$会员增加强化几率>") != std::string::npos) {
            aaCenter.AA_StringReplace(message, "<$会员增加强化几率>", AA_StringFromFloat(vipconf.qianghua));
        }
        if (message.find("<$会员增加合成几率>") != std::string::npos) {
            aaCenter.AA_StringReplace(message, "<$会员增加合成几率>", AA_StringFromFloat(vipconf.hecheng));
        }
        if (message.find("<$会员增加雇佣兵数量>") != std::string::npos) {
            aaCenter.AA_StringReplace(message, "<$会员增加雇佣兵数量>", AA_StringFromFloat(vipconf.botcount));
        }
        if (message.find("<$军衔等级>") != std::string::npos) {
            aaCenter.AA_StringReplace(message, "<$军衔等级>", std::to_string(jxconf.level));
        }
        if (message.find("<$斗气等级>") != std::string::npos) {
            aaCenter.AA_StringReplace(message, "<$斗气等级>", std::to_string(dqconf.level));
        }
        if (message.find("<$巅峰等级>") != std::string::npos) {
            aaCenter.AA_StringReplace(message, "<$巅峰等级>", std::to_string(dfconf.level));
        }
        if (message.find("<$军衔经验>") != std::string::npos) {
            aaCenter.AA_StringReplace(message, "<$军衔经验>", std::to_string(jxcconf.exp));
        }
        if (message.find("<$军衔升级经验>") != std::string::npos) {
            aaCenter.AA_StringReplace(message, "<$军衔升级经验>", std::to_string(jxconf.exp));
        }
        if (message.find("<$斗气经验>") != std::string::npos) {
            aaCenter.AA_StringReplace(message, "<$斗气经验>", std::to_string(dqcconf.exp));
        }
        if (message.find("<$斗气升级经验>") != std::string::npos) {
            aaCenter.AA_StringReplace(message, "<$斗气升级经验>", std::to_string(dqconf.exp));
        }
        if (message.find("<$巅峰经验>") != std::string::npos) {
            aaCenter.AA_StringReplace(message, "<$巅峰经验>", std::to_string(dfcconf.exp));
        }
        if (message.find("<$巅峰升级经验>") != std::string::npos) {
            aaCenter.AA_StringReplace(message, "<$巅峰升级经验>", std::to_string(dfconf.exp));
        }
        if (message.find("<$" + aaCenter.aa_world_confs[64].value2 + ">") != std::string::npos) {
            aaCenter.AA_StringReplace(message, "<$" + aaCenter.aa_world_confs[64].value2 + ">", std::to_string(aconf.jifen));
        }
        if (message.find("<$充值" + aaCenter.aa_world_confs[64].value2 + ">") != std::string::npos) {
            aaCenter.AA_StringReplace(message, "<$充值" + aaCenter.aa_world_confs[64].value2 + ">", std::to_string(aconf.jifen_cz));
        }
        if (message.find("<$累计" + aaCenter.aa_world_confs[64].value2 + ">") != std::string::npos) {
            aaCenter.AA_StringReplace(message, "<$累计" + aaCenter.aa_world_confs[64].value2 + ">", std::to_string(aconf.jifen_all));
        }
        if (message.find("<$" + aaCenter.aa_world_confs[62].value2 + ">") != std::string::npos) {
            aaCenter.AA_StringReplace(message, "<$" + aaCenter.aa_world_confs[62].value2 + ">", std::to_string(aconf.paodian));
        }
        if (message.find("<$" + aaCenter.aa_world_confs[63].value2 + ">") != std::string::npos) {
            aaCenter.AA_StringReplace(message, "<$" + aaCenter.aa_world_confs[63].value2 + ">", std::to_string(aconf.mobi));
        }
        if (message.find("<$" + aaCenter.aa_world_confs[65].value2 + ">") != std::string::npos) {
            aaCenter.AA_StringReplace(message, "<$" + aaCenter.aa_world_confs[65].value2 + ">", std::to_string(aconf.battlecore));
        }
        if (message.find("<$会员描述>") != std::string::npos) {
            std::string str = vipconf.text;
            if (!nnn) {
                aaCenter.AA_StringReplace(str, "\\n", "\n");
            }
            aaCenter.AA_StringReplace(message, "<$会员描述>", str);
        }
        if (message.find("<$斗气描述>") != std::string::npos) {
            std::string str = dqconf.text;
            if (!nnn) {
                aaCenter.AA_StringReplace(str, "\\n", "\n");
            }
            aaCenter.AA_StringReplace(message, "<$斗气描述>", str);
        }
        if (message.find("<$巅峰描述>") != std::string::npos) {
            std::string str = dfconf.text;
            if (!nnn) {
                aaCenter.AA_StringReplace(str, "\\n", "\n");
            }
            aaCenter.AA_StringReplace(message, "<$巅峰描述>", str);
        }
        if (message.find("<$军衔描述>") != std::string::npos) {
            std::string str = jxconf.text;
            if (!nnn) {
                aaCenter.AA_StringReplace(str, "\\n", "\n");
            }
            aaCenter.AA_StringReplace(message, "<$军衔描述>", str);
        }
        if (message.find("<$斗气点数>") != std::string::npos) {
            aaCenter.AA_StringReplace(message, "<$斗气点数>", std::to_string((dqcconf.dianshu_all - dqcconf.dianshu > dqcconf.dianshu_all ? dqcconf.dianshu_all : dqcconf.dianshu_all - dqcconf.dianshu)));
        }
        if (message.find("<$巅峰点数>") != std::string::npos) {
            aaCenter.AA_StringReplace(message, "<$巅峰点数>", std::to_string(dfcconf.dianshu_all - dfcconf.dianshu > dfcconf.dianshu_all ? dfcconf.dianshu_all : dfcconf.dianshu_all - dfcconf.dianshu));
        }
        if (message.find("<$军衔点数>") != std::string::npos) {
            aaCenter.AA_StringReplace(message, "<$军衔点数>", std::to_string(jxcconf.dianshu_all - jxcconf.dianshu > jxcconf.dianshu_all ? jxcconf.dianshu_all : jxcconf.dianshu_all - jxcconf.dianshu));
        }

        if (aa_message.use_item && aa_message.use_item->IsInWorld()) {
            ItemTemplate const* pProto = aa_message.use_item->GetTemplate();
            if (message.find("<$物品名称>") != std::string::npos) {
                aaCenter.AA_StringReplace(message, "<$物品名称>", aaCenter.AA_GetItemLinkJd(aa_message.use_item));
            }
            if (pProto) {
                if (message.find("<$物品等级>") != std::string::npos) {

                    aaCenter.AA_StringReplace(message, "<$物品等级>", std::to_string(pProto->GetBaseItemLevel()));
                }
            }
            if (message.find("<$物品数量>") != std::string::npos) {
                aaCenter.AA_StringReplace(message, "<$物品数量>", std::to_string(aa_message.use_item->GetCount()));
            }
            ObjectGuid::LowType guidlow = aa_message.use_item->GetGUIDLow();
            uint32 entry = aa_message.use_item->GetEntry();
            AA_Character_Instance conf = aaCenter.aa_character_instances[guidlow];
            if (message.find("<$强化等级>") != std::string::npos) {
                aaCenter.AA_StringReplace(message, "<$强化等级>", std::to_string(conf.qh_level));
            }
            if (message.find("<$成长等级>") != std::string::npos) {
                aaCenter.AA_StringReplace(message, "<$成长等级>", std::to_string(conf.cz_level));
            }
            if (message.find("<$重铸次数>") != std::string::npos) {
                aaCenter.AA_StringReplace(message, "<$重铸次数>", std::to_string(conf.chongzhu_count));
            }
            if (message.find("<$物品改名名称>") != std::string::npos) {
                aaCenter.AA_StringReplace(message, "<$物品改名名称>", conf.name);
            }
            if (message.find("<$觉醒属性数量>") != std::string::npos) {
                aaCenter.AA_StringReplace(message, "<$觉醒属性数量>", std::to_string(conf.fm_value_count));
            }
            if (message.find("<$觉醒技能数量>") != std::string::npos) {
                aaCenter.AA_StringReplace(message, "<$觉醒技能数量>", std::to_string(conf.fm_spell_count));
            }
            {
                AA_Qianghua_Item conf = aaCenter.aa_qianghua_items[entry];
                if (conf.itemid > 0) {
                    if (message.find("<$强化等级券几率>") != std::string::npos) {
                        aaCenter.AA_StringReplace(message, "<$强化等级券几率>", AA_StringFromFloat(conf.chance));
                    }
                    if (message.find("<$强化等级券等级>") != std::string::npos) {
                        aaCenter.AA_StringReplace(message, "<$强化等级券等级>", std::to_string(conf.level));
                    }
                    if (conf.need > 0) {
                        if (message.find("@强化等级券需求>") != std::string::npos) {
                            std::string need = "@" + std::to_string(conf.need) + ">";
                            aaCenter.AA_StringReplace(message, "@强化等级券需求>", need);
                        }
                    }
                }
            }
            {
                AA_Chengzhang_Item conf = aaCenter.aa_chengzhang_items[entry];
                if (conf.itemid > 0) {
                    if (message.find("<$成长经验券经验>") != std::string::npos) {
                        aaCenter.AA_StringReplace(message, "<$成长经验券经验>", std::to_string(conf.exp));
                    }
                    if (conf.need > 0) {
                        if (message.find("@成长经验券需求>") != std::string::npos) {
                            std::string need = "@" + std::to_string(conf.need) + ">";
                            aaCenter.AA_StringReplace(message, "@成长经验券需求>", need);
                        }
                    }
                }
            }
            {
                AA_Jianding_Item conf = aaCenter.aa_jianding_items[entry];
                if (conf.itemid > 0) {
                    if (message.find("<$鉴定品质券几率>") != std::string::npos) {
                        aaCenter.AA_StringReplace(message, "<$鉴定品质券几率>", AA_StringFromFloat(conf.chance));
                    }
                    if (message.find("<$鉴定品质券品质>") != std::string::npos) {
                        AA_Item_Nonsuch nconf = aaCenter.aa_item_nonsuchs[conf.nonsuchid];
                        aaCenter.AA_StringReplace(message, "<$鉴定品质券品质>", nconf.text);
                    }
                    if (conf.need > 0) {
                        if (message.find("@鉴定品质券需求>") != std::string::npos) {
                            std::string need = "@" + std::to_string(conf.need) + ">";
                            aaCenter.AA_StringReplace(message, "@鉴定品质券需求>", need);
                        }
                    }
                }
            }
        }
        if (aa_message.target_item && aa_message.target_item->IsInWorld()) {
            uint32 entry = aa_message.target_item->GetEntry();
            if (message.find("<$目标名称>") != std::string::npos) {
                if (ItemTemplate const* pItemProto = aa_message.target_item->GetTemplate()) {
                    aaCenter.AA_StringReplace(message, "<$目标名称>", aaCenter.AA_GetItemLink(pItemProto->GetId()));
                }
            }
            {
                AA_Hecheng_Conf conf = aaCenter.aa_hecheng_confs[entry];
                if (conf.itemid > 0) {
                    if (message.find("<$合成物品>") != std::string::npos) {
                        if (ItemTemplate const* pItemProto = sObjectMgr->GetItemTemplate(conf.itemid)) {
                            aaCenter.AA_StringReplace(message, "<$合成物品>", aaCenter.AA_GetItemLink(pItemProto->GetId()));
                        }
                    }
                    if (message.find("<$合成几率>") != std::string::npos) {
                        float chance = conf.chance;
                        if (aaCenter.AA_FindMapValueUint32(player->aa_fm_values, 406) > 0) {
                            chance += aaCenter.AA_FindMapValueUint32(player->aa_fm_values, 406);
                        }
                        std::string jilv = aaCenter.AA_StringFromFloat(chance) + "%";
                        aaCenter.AA_StringReplace(message, "<$合成几率>", jilv);
                    }
                    if (message.find("<$合成后物品>") != std::string::npos) {
                        if (conf.itemid1 > 0) {
                            if (ItemTemplate const* pItemProto = sObjectMgr->GetItemTemplate(conf.itemid1)) {
                                aaCenter.AA_StringReplace(message, "<$合成后物品>", aaCenter.AA_GetItemLink(pItemProto->GetId()));
                            }
                        }
                    }
                    if (message.find("<$合成失败处理>") != std::string::npos) {
                        std::string destroy = conf.destroy == 0 ? "摧毁" : "保留";
                        aaCenter.AA_StringReplace(message, "<@合成失败处理>", destroy);
                    }
                    if (message.find("@合成需求>") != std::string::npos) {
                        if (conf.need > 0) {
                            std::string need = "@" + std::to_string(conf.need) + ">";
                            aaCenter.AA_StringReplace(message, "@合成需求>", need);
                        }
                    }
                }
            }
            {
                uint32 entry = AA_GetBaoshiEntry(aa_message.target_item, 0);
                if (entry > 0) {
                    AA_Chaixie_Conf conf = aaCenter.aa_chaixie_confs[entry];
                    if (conf.itemid > 0) {
                        if (message.find("<$宝石1号>") != std::string::npos) {
                            if (conf.itemid == entry) {
                                ItemTemplate const* proto = sObjectMgr->GetItemTemplate(entry);
                                std::string name = "";
                                if (proto) {
                                    name = aaCenter.AA_GetItemLink(proto->GetId());
                                }
                                aaCenter.AA_StringReplace(message, "<$宝石1号>", name);
                            }
                        }
                        if (message.find("@宝石1号需求>") != std::string::npos) {
                            if (conf.need > 0) {
                                std::string need = "@" + std::to_string(conf.need) + ">";
                                aaCenter.AA_StringReplace(message, "@宝石1号需求>", need);
                            }
                        }
                        if (message.find("@宝石1号奖励>") != std::string::npos) {
                            if (conf.reward > 0) {
                                std::string reward = "@" + std::to_string(conf.reward) + ">";
                                aaCenter.AA_StringReplace(message, "@宝石1号奖励>", reward);
                            }
                        }
                    }
                }
            }
            {
                uint32 entry = AA_GetBaoshiEntry(aa_message.target_item, 1);
                if (entry > 0) {
                    AA_Chaixie_Conf conf = aaCenter.aa_chaixie_confs[entry];
                    if (conf.itemid > 0) {
                        if (message.find("<$宝石2号>") != std::string::npos) {
                            if (conf.itemid == entry) {
                                ItemTemplate const* proto = sObjectMgr->GetItemTemplate(entry);
                                std::string name = "";
                                if (proto) {
                                    name = aaCenter.AA_GetItemLink(proto->GetId());
                                }
                                aaCenter.AA_StringReplace(message, "<$宝石2号>", name);
                            }
                        }
                        if (message.find("@宝石2号需求>") != std::string::npos) {
                            if (conf.need > 0) {
                                std::string need = "@" + std::to_string(conf.need) + ">";
                                aaCenter.AA_StringReplace(message, "@宝石2号需求>", need);
                            }
                        }
                        if (message.find("@宝石2号奖励>") != std::string::npos) {
                            if (conf.reward > 0) {
                                std::string reward = "@" + std::to_string(conf.reward) + ">";
                                aaCenter.AA_StringReplace(message, "@宝石2号奖励>", reward);
                            }
                        }
                    }
                }
            }
            {
                uint32 entry = AA_GetBaoshiEntry(aa_message.target_item, 2);
                if (entry > 0) {
                    AA_Chaixie_Conf conf = aaCenter.aa_chaixie_confs[entry];
                    if (conf.itemid > 0) {
                        if (message.find("<$宝石3号>") != std::string::npos) {
                            if (conf.itemid == entry) {
                                ItemTemplate const* proto = sObjectMgr->GetItemTemplate(entry);
                                std::string name = "";
                                if (proto) {
                                    name = aaCenter.AA_GetItemLink(proto->GetId());
                                }
                                aaCenter.AA_StringReplace(message, "<$宝石3号>", name);
                            }
                        }
                        if (message.find("@宝石3号需求>") != std::string::npos) {
                            if (conf.need > 0) {
                                std::string need = "@" + std::to_string(conf.need) + ">";
                                aaCenter.AA_StringReplace(message, "@宝石3号需求>", need);
                            }
                        }
                        if (message.find("@宝石3号奖励>") != std::string::npos) {
                            if (conf.reward > 0) {
                                std::string reward = "@" + std::to_string(conf.reward) + ">";
                                aaCenter.AA_StringReplace(message, "@宝石3号奖励>", reward);
                            }
                        }
                    }
                }
            }
            if (message.find("@解绑需求>") != std::string::npos) {
                AA_Jiebang_Conf conf = aaCenter.aa_jiebang_confs[entry];
                if (conf.need > 0) {
                    std::string need = "@" + std::to_string(conf.need) + ">";
                    aaCenter.AA_StringReplace(message, "@解绑需求>", need);
                }
            }
        }

        Player* target_player = aa_message.target_player ? aa_message.target_player : nullptr;
        Creature* target_creature = aa_message.target_creature ? aa_message.target_creature : nullptr;
        if (target_player && target_player->IsInWorld()) {
            if (message.find("<$目标名称>") != std::string::npos) {
                aaCenter.AA_StringReplace(message, "<$目标名称>", target_player->GetName());
            }
            if (message.find("<$目标地图>") != std::string::npos) {
                aaCenter.AA_StringReplace(message, "<$目标地图>", target_player->GetMap()->GetMapName());
            }
            if (message.find("<$目标x>") != std::string::npos) {
                aaCenter.AA_StringReplace(message, "<$目标x>", std::to_string(target_player->GetPositionX()));
            }
            if (message.find("<$目标y>") != std::string::npos) {
                aaCenter.AA_StringReplace(message, "<$目标y>", std::to_string(target_player->GetPositionY()));
            }
            if (message.find("<$目标z>") != std::string::npos) {
                aaCenter.AA_StringReplace(message, "<$目标z>", std::to_string(target_player->GetPositionZ()));
            }
            if (message.find("<$目标o>") != std::string::npos) {
                aaCenter.AA_StringReplace(message, "<$目标o>", std::to_string(target_player->GetOrientation()));
            }
        }
        if (target_creature && target_creature->IsInWorld()) {
            if (message.find("<$目标名称>") != std::string::npos) {
                aaCenter.AA_StringReplace(message, "<$目标名称>", target_creature->GetName());
            }
            if (message.find("<$目标地图>") != std::string::npos) {
                aaCenter.AA_StringReplace(message, "<$目标地图>", target_creature->GetMap()->GetMapName());
            }
            if (message.find("<$目标x>") != std::string::npos) {
                aaCenter.AA_StringReplace(message, "<$目标x>", std::to_string(target_creature->GetPositionX()));
            }
            if (message.find("<$目标y>") != std::string::npos) {
                aaCenter.AA_StringReplace(message, "<$目标y>", std::to_string(target_creature->GetPositionY()));
            }
            if (message.find("<$目标z>") != std::string::npos) {
                aaCenter.AA_StringReplace(message, "<$目标z>", std::to_string(target_creature->GetPositionZ()));
            }
            if (message.find("<$目标o>") != std::string::npos) {
                aaCenter.AA_StringReplace(message, "<$目标o>", std::to_string(target_creature->GetOrientation()));
            }
        }

        if (!target_player && player->GetSelectedPlayer()) {
            target_player = player->GetSelectedPlayer();
        }
        if (!target_creature && player->GetSelectedUnit()) {
            target_creature = player->GetSelectedUnit()->ToCreature();
        }
        if (target_player && target_player->IsInWorld()) {
            if (message.find("<$目标名称>") != std::string::npos) {
                aaCenter.AA_StringReplace(message, "<$目标名称>", target_player->GetName());
            }
            if (message.find("<$目标地图>") != std::string::npos) {
                aaCenter.AA_StringReplace(message, "<$目标地图>", target_player->GetMap()->GetMapName());
            }
            if (message.find("<$目标x>") != std::string::npos) {
                aaCenter.AA_StringReplace(message, "<$目标x>", std::to_string(target_player->GetPositionX()));
            }
            if (message.find("<$目标y>") != std::string::npos) {
                aaCenter.AA_StringReplace(message, "<$目标y>", std::to_string(target_player->GetPositionY()));
            }
            if (message.find("<$目标z>") != std::string::npos) {
                aaCenter.AA_StringReplace(message, "<$目标z>", std::to_string(target_player->GetPositionZ()));
            }
            if (message.find("<$目标o>") != std::string::npos) {
                aaCenter.AA_StringReplace(message, "<$目标o>", std::to_string(target_player->GetOrientation()));
            }
        }
        if (target_creature && target_creature->IsInWorld()) {
            if (message.find("<$目标名称>") != std::string::npos) {
                aaCenter.AA_StringReplace(message, "<$目标名称>", target_creature->GetName());
            }
            if (message.find("<$目标地图>") != std::string::npos) {
                aaCenter.AA_StringReplace(message, "<$目标地图>", target_creature->GetMap()->GetMapName());
            }
            if (message.find("<$目标x>") != std::string::npos) {
                aaCenter.AA_StringReplace(message, "<$目标x>", std::to_string(target_creature->GetPositionX()));
            }
            if (message.find("<$目标y>") != std::string::npos) {
                aaCenter.AA_StringReplace(message, "<$目标y>", std::to_string(target_creature->GetPositionY()));
            }
            if (message.find("<$目标z>") != std::string::npos) {
                aaCenter.AA_StringReplace(message, "<$目标z>", std::to_string(target_creature->GetPositionZ()));
            }
            if (message.find("<$目标o>") != std::string::npos) {
                aaCenter.AA_StringReplace(message, "<$目标o>", std::to_string(target_creature->GetOrientation()));
            }
        }

        //比武排名
        for (int i = 0; i < 10; i++) {
            std::string search = "<$比武第" + std::to_string(i + 1) + "名>";
            std::string search1 = "比武排名" + std::to_string(i + 1);
            if (message.find(search) != std::string::npos) {
                std::string m_diy_systems = aaCenter.aa_system_conf.diy_system;
                std::map<std::string, std::string> mdiy_systems; mdiy_systems.clear();
                aaCenter.AA_StringToStringMap(m_diy_systems, mdiy_systems);
                std::string str = mdiy_systems[search1];
                ObjectGuid::LowType guidlow = aaCenter.AA_StringInt32(str);
                if (guidlow) {
                    std::string name = "无";
                    {
                        QueryResult result = CharacterDatabase.PQuery("SELECT name FROM characters WHERE deleteDate IS NULL AND guid = {}", guidlow);
                        if (result)
                        {
                            Field* fields = result->Fetch();
                            name = fields[0].GetString();
                        }
                    }
                    aaCenter.AA_StringReplace(message, search, name);
                }
            }
        }
        for (int i = 0; i < 10; i++) {
            std::string search = "<$比武第" + std::to_string(i + 1) + "名>";
            aaCenter.AA_StringReplace(message, search, "无");
        }

        aaCenter.AA_StringReplace(message, "<$角色姓名>", "无");
        aaCenter.AA_StringReplace(message, "<$角色种族>", "无");
        aaCenter.AA_StringReplace(message, "<$角色阵营>", "无");
        aaCenter.AA_StringReplace(message, "<$角色职业>", "无");
        aaCenter.AA_StringReplace(message, "<$角色等级>", "无");
        aaCenter.AA_StringReplace(message, "<$连杀数量>", "无");
        aaCenter.AA_StringReplace(message, "<$地图>", "无");
        aaCenter.AA_StringReplace(message, "<$x>", "无");
        aaCenter.AA_StringReplace(message, "<$y>", "无");
        aaCenter.AA_StringReplace(message, "<$z>", "无");
        aaCenter.AA_StringReplace(message, "<$o>", "无");
        aaCenter.AA_StringReplace(message, "<$会员等级>", "无");
        aaCenter.AA_StringReplace(message, "<$目标名称>", "无");
        aaCenter.AA_StringReplace(message, "<$目标地图>", "无");
        aaCenter.AA_StringReplace(message, "<$目标x>", "无");
        aaCenter.AA_StringReplace(message, "<$目标y>", "无");
        aaCenter.AA_StringReplace(message, "<$目标z>", "无");
        aaCenter.AA_StringReplace(message, "<$目标o>", "无");
        aaCenter.AA_StringReplace(message, "<$目标名称>", "无");

        aaCenter.AA_StringReplace(message, "<$合成几率>", "无");
        aaCenter.AA_StringReplace(message, "<$合成物品>", "无");
        aaCenter.AA_StringReplace(message, "<$合成后物品>", "无");
        aaCenter.AA_StringReplace(message, "<@合成失败处理>", "无");
        aaCenter.AA_StringReplace(message, "<$宝石1号>", "无");
        aaCenter.AA_StringReplace(message, "<$宝石2号>", "无");
        aaCenter.AA_StringReplace(message, "<$宝石3号>", "无");

        AA_ReplaceStr(player, message, "巅峰加点");
        AA_ReplaceStr(player, message, "斗气加点");
        AA_ReplaceStr(player, message, "军衔加点");
        AA_ReplaceStr(player, message, "需求");
        AA_ReplaceStr(player, message, "奖励");
    }
    return message;
}

bool AACenter::M_CanNeed(Player* player, uint32 needid, uint32 count, bool notice, ObjectGuid::LowType itemGuidlow)
{
    if (needid <= 0) {
        return true;
    }
    if (!player || !player->ToPlayer() || !player->GetSession()) {
        return false;
    }
    std::string needstr = "";
    bool isOk = M_CanNeedDo(player, needstr, needid, count, itemGuidlow);
    AA_Need_Conf conf = aaCenter.aa_needs[needid];
    if (!isOk && notice && !conf.notice) {
        std::string need = aaCenter.AA_GetNeedText(needid, count);
        if (need != "") {
            aaCenter.AA_StringReplace(need, "&", "\n");
            aaCenter.AA_SendMessage(player, 0, "╔┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈╗");
            need = aa_color_red + "· 需要条件：|r\n" + need;
            aaCenter.AA_SendMessage(player, 0, need.c_str());
            if (needstr != "") {
                std::string str = aa_color_red + "· 当前不足：|r\n" + needstr;
                aaCenter.AA_StringReplaceLast(str, "\n", "");
                aaCenter.AA_SendMessage(player, 0, str.c_str());
            }
            aaCenter.AA_SendMessage(player, 0, "╚┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈╝");
            aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000条件不足|r");
        }
    }

    return isOk;
}
bool AACenter::M_CanNeedDo(Player* player, std::string& needstr, uint32 needid, uint32 count, ObjectGuid::LowType itemGuidlow)
{
    AA_Need_Conf conf = aaCenter.aa_needs[needid];
    AA_Account a_conf = aaCenter.aa_accounts[player->GetSession()->GetAccountId()];
    ObjectGuid::LowType guidlow = player->GetGUIDLow();
    AA_Characters_Dianfeng dfconf = aaCenter.aa_characters_dianfengs[guidlow];
    AA_Characters_Douqi dqconf = aaCenter.aa_characters_douqis[guidlow];
    AA_Characters_Junxian jxconf = aaCenter.aa_characters_junxians[guidlow];

    bool isOk = true;
    if (player->GetLevel() < conf.level) {
        needstr = needstr + aa_color_blues + "· [等级]" + aa_color_yellow + " x " + std::to_string(player->GetLevel()) + "|r\n";
        isOk = false;
    }

    if (a_conf.vip < conf.viplevel) {
        needstr = needstr + aa_color_blues + "· [会员等级]" + aa_color_yellow + " x " + std::to_string(a_conf.vip) + "|r\n";
        isOk = false;
    }
    if (a_conf.jifen < conf.jifen * count) {
        needstr = needstr + aa_color_blues + "· [" + aaCenter.aa_world_confs[64].value2 + "]" + aa_color_yellow + " x " + std::to_string(a_conf.jifen) + "|r\n";
        isOk = false;
    }
    if (a_conf.jifen_all < conf.jifen_all) {
        needstr = needstr + aa_color_blues + "· [累计" + aaCenter.aa_world_confs[64].value2 + "]" + aa_color_yellow + " x " + std::to_string(a_conf.jifen_all) + "|r\n";
        isOk = false;
    }
    if (a_conf.paodian < conf.paodian * count) {
        needstr = needstr + aa_color_blues + "· [" + aaCenter.aa_world_confs[62].value2 + "]" + aa_color_yellow + " x " + std::to_string(a_conf.paodian) + "|r\n";
        isOk = false;
    }
    if (a_conf.mobi < conf.mobi * count) {
        needstr = needstr + aa_color_blues + "· [" + aaCenter.aa_world_confs[63].value2 + "]" + aa_color_yellow + " x " + std::to_string(a_conf.mobi) + "|r\n";
        isOk = false;
    }
    if (a_conf.battlecore < conf.battlecore * count) {
        needstr = needstr + aa_color_blues + "· [" + aaCenter.aa_world_confs[65].value2 + "]" + aa_color_yellow + " x " + std::to_string(a_conf.battlecore) + "|r\n";
        isOk = false;
    }
    if (dfconf.level < conf.dflevel) {
        needstr = needstr + aa_color_blues + "· [巅峰等级]" + aa_color_yellow + " x " + std::to_string(dfconf.level) + "|r\n";
        isOk = false;
    }
    if (dqconf.level < conf.dqlevel) {
        needstr = needstr + aa_color_blues + "· [斗气等级]" + aa_color_yellow + " x " + std::to_string(dqconf.level) + "|r\n";
        isOk = false;
    }
    if (jxconf.level < conf.jxlevel) {
        needstr = needstr + aa_color_blues + "· [军衔等级]" + aa_color_yellow + " x " + std::to_string(jxconf.level) + "|r\n";
        isOk = false;
    }

    if (conf.gender > 0) { // 0没有 1男 2女
        if (conf.gender == 1 && player->GetGender() != GENDER_MALE) {
            //            return "需要性别男性";
            needstr = needstr + aa_color_blues + "· [性别] " + aa_color_yellow + "男" + "|r\n";
            isOk = false;
        }
        if (conf.gender == 2 && player->GetGender() != GENDER_FEMALE) {
            //            return "需要性别女性";
            needstr = needstr + aa_color_blues + "· [性别] " + aa_color_yellow + "女" + "|r\n";
            isOk = false;
        }
    }
    if (conf.team > 0) { // 阵营
        //        HORDE               = 2,
        //        ALLIANCE            = 1,
        if ((conf.team == 1 && player->GetTeamId() != TEAM_ALLIANCE) ||
            (conf.team == 2 && player->GetTeamId() != TEAM_HORDE)) {
            isOk = false;
        }
    }
    if (conf.race > 0) {
        if (conf.race != player->GetRace()) {
            needstr = needstr + aa_color_blues + "· [种族] " + aa_color_yellow + aaCenter.GetPlayerRace(player) + "|r\n";
            //            return "种族不匹配";
            isOk = false;
        }
    }
    if (conf.class1 > 0 && conf.class1 != player->GetClass()) {
        //        return "当前职业不匹配";
        needstr = needstr + aa_color_blues + "· [职业] " + aa_color_yellow + aaCenter.GetPlayerClass(player->GetClass()) + "|r\n";
        isOk = false;
    }
    if (conf.guild > 0 && conf.guild != player->GetGuildId()) {
        //        return "所在公会不匹配";
        needstr = needstr + aa_color_blues + "· [公会] " + player->GetGuildName() + "|r\n";
        isOk = false;
    }
    if (conf.mapid > -1 && uint32(conf.mapid) != player->GetMapId()) {
        //        return "当前地图不匹配";
        needstr = needstr + aa_color_blues + "· [地图] " + aa_color_yellow + player->GetMap()->GetMapName() + "|r\n";
        isOk = false;
    }
    else if (conf.zoneid > -1 && uint32(conf.zoneid) != player->GetZoneId()) {
        needstr = needstr + aa_color_blues + "· [区域] " + aa_color_yellow + "不在范围内\n";
        isOk = false;
    }
    else if (conf.areaid > -1 && uint32(conf.areaid) != player->GetAreaId()) {
        //        return "当前地区不匹配";
        needstr = needstr + aa_color_blues + "· [地区] " + aa_color_yellow + "不在范围内\n";
        isOk = false;
    }
    if (conf.quests != "0" && conf.quests != "") {
        std::vector<int32> v;
        aaCenter.AA_StringToVectorInt(conf.quests, v, ",");
        for (size_t i = 0; i < v.size(); i++) {
            uint32 questid = v[i];
            QuestStatus status = player->GetQuestStatus(questid);
            if (status != QUEST_STATUS_COMPLETE && status != QUEST_STATUS_REWARDED) {
                //                return "任务未完成";
                needstr = needstr + aa_color_blues + "· [任务] " + aa_color_yellow + "未完成" + "|r\n";
                isOk = false;
            }
        }
    }

    if (conf.achievements != "0" && conf.achievements != "") {
        std::vector<int32> v;
        aaCenter.AA_StringToVectorInt(conf.achievements, v, ",");
        for (size_t i = 0; i < v.size(); i++) {
            uint32 achievementid = v[i];
            if (!player->HasAchieved(achievementid)) {
                //                return "成就未完成";
                needstr = needstr + aa_color_blues + "· [成就] " + aa_color_yellow + "未完成" + "|r\n";
                isOk = false;
            }
        }
    }

    if (conf.spells != "0" && conf.spells != "") {
        std::vector<int32> v;
        aaCenter.AA_StringToVectorInt(conf.spells, v, ",");
        for (size_t i = 0; i < v.size(); i++) {
            uint32 spellid = v[i];
            if (!player->HasSpell(spellid)) {
                //                return "技能条件不满足";
                needstr = needstr + aa_color_blues + "· [学习技能] " + aa_color_yellow + "未完成" + "|r\n";
                isOk = false;
            }
        }
    }

    if (conf.buffs != "0" && conf.buffs != "") {
        std::vector<int32> v;
        aaCenter.AA_StringToVectorInt(conf.buffs, v, ",");
        for (size_t i = 0; i < v.size(); i++) {
            uint32 buffid = v[i];
            if (!player->HasAura(buffid)) {
                //                return "Buff条件不满足";
                needstr = needstr + aa_color_blues + "· [携带光环] " + aa_color_yellow + "未完成" + "|r\n";
                isOk = false;
            }
        }
    }

    if (player->GetMoney() < conf.money * count) { //return "金币不足";
        needstr = needstr + aa_color_blues + "· [金钱]" + aa_color_yellow + " x " + aaCenter.AA_GetMoneyLink(player->GetMoney()) + "|r\n";
        isOk = false;
    }
    std::string itemstr = "";
    if (conf.items != "" && conf.items != "0") {
        std::map<int32, int32> items; items.clear();
        aaCenter.AA_StringToMap(conf.items, items);
        for (auto itr : items) {
            if (itr.first <= 0 || itr.second <= 0) {
                continue;
            }
            ItemTemplate const* pProto = sObjectMgr->GetItemTemplate(itr.first);
            if (!pProto) {
                continue;
            }
            if (!aaCenter.AA_HasItemInBagCount(player, itr.first, itr.second * count)) {
                std::string name = aaCenter.AA_GetItemLink(itr.first);
                needstr = needstr + aa_color_blues + "·|r " + name + aa_color_yellow + " x " + std::to_string(player->GetItemCount(itr.first)) + "|r\n";
                isOk = false; //return "材料不足";
            }
        }
    }
    if (conf.level_item_ItemLevel > 0) {
        ItemTemplate const* pProto = nullptr;
        if (itemGuidlow > 0) {
            AA_Character_Instance c_conf = aaCenter.aa_character_instances[itemGuidlow];
            if (c_conf.itemEntry > 0) {
                pProto = sObjectMgr->GetItemTemplate(c_conf.itemEntry);
            }
        }
        if (pProto) {
            uint32 level = pProto->GetBaseItemLevel();
            if (level < conf.level_item_ItemLevel) {
                needstr = needstr + aa_color_blues + "· [物品等级]" + aa_color_yellow + " x " + std::to_string(level) + "|r\n";
                isOk = false;
            }
        }
        else {
            uint32 level = aaCenter.GetAll_level_item_ItemLevel(player);
            if (level < conf.level_item_ItemLevel) {
                needstr = needstr + aa_color_blues + "· [物品等级]" + aa_color_yellow + " x " + std::to_string(level) + "|r\n";
                isOk = false;
            }
        }
    }
    if (conf.level_item_Quality > 0) {
        ItemTemplate const* pProto = nullptr;
        if (itemGuidlow > 0) {
            AA_Character_Instance c_conf = aaCenter.aa_character_instances[itemGuidlow];
            if (c_conf.itemEntry > 0) {
                pProto = sObjectMgr->GetItemTemplate(c_conf.itemEntry);
            }
        }
        if (pProto) {
            uint32 level = pProto->GetBaseItemLevel();
            if (level < conf.level_item_Quality) {
                needstr = needstr + aa_color_blues + "· [物品品质等级]" + aa_color_yellow + " x " + std::to_string(level) + "|r\n";
                isOk = false;
            }
        }
        else {
            uint32 level = aaCenter.GetAll_level_item_Quality(player);
            if (level < conf.level_item_Quality) {
                needstr = needstr + aa_color_blues + "· [物品品质等级]" + aa_color_yellow + " x " + std::to_string(level) + "|r\n";
                isOk = false;
            }
        }
    }
    if (conf.level_item_jd > 0) {
        if (itemGuidlow > 0) {
            uint32 level = aaCenter.aa_character_instances[itemGuidlow].jd_level;
            if (level < conf.level_item_jd) {
                needstr = needstr + aa_color_blues + "· [物品鉴定等级]" + aa_color_yellow + " x " + std::to_string(level) + "|r\n";
                isOk = false;
            }
        }
        else {
            uint32 level = aaCenter.GetAll_level_item_jd(player);
            if (level < conf.level_item_jd) {
                needstr = needstr + aa_color_blues + "· [物品鉴定等级]" + aa_color_yellow + " x " + std::to_string(level) + "|r\n";
                isOk = false;
            }
        }
    }
    if (conf.level_item_qh > 0) {
        if (itemGuidlow > 0) {
            uint32 level = aaCenter.aa_character_instances[itemGuidlow].qh_level;
            if (level < conf.level_item_qh) {
                needstr = needstr + aa_color_blues + "· [物品强化等级]" + aa_color_yellow + " x " + std::to_string(level) + "|r\n";
                isOk = false;
            }
        }
        else {
            uint32 level = aaCenter.GetAll_level_item_qh(player);
            if (level < conf.level_item_qh) {
                needstr = needstr + aa_color_blues + "· [物品强化等级]" + aa_color_yellow + " x " + std::to_string(level) + "|r\n";
                isOk = false;
            }
        }
    }
    if (conf.level_item_cz > 0) {
        if (itemGuidlow > 0) {
            uint32 level = aaCenter.aa_character_instances[itemGuidlow].cz_level;
            if (level < conf.level_item_cz) {
                needstr = needstr + aa_color_blues + "· [物品成长等级]" + aa_color_yellow + " x " + std::to_string(level) + "|r\n";
                isOk = false;
            }
        }
        else {
            uint32 level = aaCenter.GetAll_level_item_cz(player);
            if (level < conf.level_item_cz) {
                needstr = needstr + aa_color_blues + "· [物品成长等级]" + aa_color_yellow + " x " + std::to_string(level) + "|r\n";
                isOk = false;
            }
        }
    }
    if (conf.level_item_jxsx > 0) {
        if (itemGuidlow > 0) {
            uint32 level = aaCenter.aa_character_instances[itemGuidlow].fm_value_count;
            if (level < conf.level_item_jxsx) {
                needstr = needstr + aa_color_blues + "· [物品觉醒属性等级]" + aa_color_yellow + " x " + std::to_string(level) + "|r\n";
                isOk = false;
            }
        }
        else {
            uint32 level = aaCenter.GetAll_level_item_jxsx(player);
            if (level < conf.level_item_jxsx) {
                needstr = needstr + aa_color_blues + "· [物品觉醒属性等级]" + aa_color_yellow + " x " + std::to_string(level) + "|r\n";
                isOk = false;
            }
        }
    }
    if (conf.level_item_jxjn > 0) {
        if (itemGuidlow > 0) {
            uint32 level = aaCenter.aa_character_instances[itemGuidlow].fm_spell_count;
            if (level < conf.level_item_jxjn) {
                needstr = needstr + aa_color_blues + "· [物品觉醒技能等级]" + aa_color_yellow + " x " + std::to_string(level) + "|r\n";
                isOk = false;
            }
        }
        else {
            uint32 level = aaCenter.GetAll_level_item_jxjn(player);
            if (level < conf.level_item_jxjn) {
                needstr = needstr + aa_color_blues + "· [物品觉醒技能等级]" + aa_color_yellow + " x " + std::to_string(level) + "|r\n";
                isOk = false;
            }
        }
    }
    if (conf.diy_guid != "" && conf.diy_guid != "0") {
        std::map<std::string, std::string> diy_guids; diy_guids.clear();
        aaCenter.AA_StringToStringMap(conf.diy_guid, diy_guids);

        std::string m_diy_guids = aaCenter.aa_characterss[guidlow].diy_guid;
        std::map<std::string, std::string> mdiy_guids; mdiy_guids.clear();
        aaCenter.AA_StringToStringMap(m_diy_guids, mdiy_guids);

        for (auto itr : diy_guids) {
            std::string k = itr.first;
            std::string v = itr.second;
            std::string v2 = mdiy_guids[k];
            if (v.find(">") == string::npos && v.find("<") == string::npos && v.find("!=") == string::npos && v.find("=") == string::npos) { //大于等于，消耗
                float value = aaCenter.AA_StringFloat(v) * count;
                float value2 = aaCenter.AA_StringFloat(v2);
                if (value2 < value) {
                    needstr = needstr + aa_color_blues + "· [" + k + "]" + aa_color_yellow + " x " + aaCenter.AA_StringFromFloat(value2) + "|r\n";
                    isOk = false;
                }
            }
            else {
                if (v.find(">") != string::npos) { //大于
                    aaCenter.AA_StringReplaceFirst(v, ">", "");
                    float value = aaCenter.AA_StringFloat(v) * count;
                    float value2 = aaCenter.AA_StringFloat(v2);
                    if (value2 <= value) {
                        needstr = needstr + aa_color_blues + "· [" + k + "]" + aa_color_yellow + " x " + aaCenter.AA_StringFromFloat(value2) + "|r\n";
                        isOk = false;
                    }
                }
                if (v.find("<") != string::npos) { //小于
                    aaCenter.AA_StringReplaceFirst(v, "<", "");
                    float value = aaCenter.AA_StringFloat(v) * count;
                    float value2 = aaCenter.AA_StringFloat(v2);
                    if (value2 >= value) {
                        needstr = needstr + aa_color_blues + "· [" + k + "]" + aa_color_yellow + " x " + aaCenter.AA_StringFromFloat(value2) + "|r\n";
                        isOk = false;
                    }
                }
                if (v.find("!=") != string::npos) { //不等于
                    aaCenter.AA_StringReplaceFirst(v, "!=", "");
                    float value = aaCenter.AA_StringFloat(v) * count;
                    float value2 = aaCenter.AA_StringFloat(v2);
                    if (value2 == value) {
                        needstr = needstr + aa_color_blues + "· [" + k + "]" + aa_color_yellow + " x " + aaCenter.AA_StringFromFloat(value2) + "|r\n";
                        isOk = false;
                    }
                }
                if (v.find("=") != string::npos) { //等于
                    aaCenter.AA_StringReplaceFirst(v, "=", "");
                    float value = aaCenter.AA_StringFloat(v) * count;
                    float value2 = aaCenter.AA_StringFloat(v2);
                    if (value2 != value) {
                        needstr = needstr + aa_color_blues + "· [" + k + "]" + aa_color_yellow + " x " + aaCenter.AA_StringFromFloat(value2) + "|r\n";
                        isOk = false;
                    }
                }
            }
        }
    }
    if (conf.diy_system != "" && conf.diy_system != "0") {
        std::map<std::string, std::string> diy_systems; diy_systems.clear();
        aaCenter.AA_StringToStringMap(conf.diy_system, diy_systems);

        std::string m_diy_systems = aaCenter.aa_system_conf.diy_system;
        std::map<std::string, std::string> mdiy_systems; mdiy_systems.clear();
        aaCenter.AA_StringToStringMap(m_diy_systems, mdiy_systems);

        for (auto itr : diy_systems) {
            std::string k = itr.first;
            std::string v = itr.second;
            std::string v2 = mdiy_systems[k];
            if (v.find(">") == string::npos && v.find("<") == string::npos && v.find("!=") == string::npos && v.find("=") == string::npos) { //大于等于，消耗
                float value = aaCenter.AA_StringFloat(v) * count;
                float value2 = aaCenter.AA_StringFloat(v2);
                if (value2 < value) {
                    needstr = needstr + aa_color_blues + "· [" + k + "]" + aa_color_yellow + " x " + aaCenter.AA_StringFromFloat(value2) + "|r\n";
                    isOk = false;
                }
            }
            else {
                if (v.find(">") != string::npos) { //大于
                    aaCenter.AA_StringReplaceFirst(v, ">", "");
                    float value = aaCenter.AA_StringFloat(v) * count;
                    float value2 = aaCenter.AA_StringFloat(v2);
                    if (value2 <= value) {
                        needstr = needstr + aa_color_blues + "· [" + k + "]" + aa_color_yellow + " x " + aaCenter.AA_StringFromFloat(value2) + "|r\n";
                        isOk = false;
                    }
                }
                if (v.find("<") != string::npos) { //小于
                    aaCenter.AA_StringReplaceFirst(v, "<", "");
                    float value = aaCenter.AA_StringFloat(v) * count;
                    float value2 = aaCenter.AA_StringFloat(v2);
                    if (value2 >= value) {
                        needstr = needstr + aa_color_blues + "· [" + k + "]" + aa_color_yellow + " x " + aaCenter.AA_StringFromFloat(value2) + "|r\n";
                        isOk = false;
                    }
                }
                if (v.find("!=") != string::npos) { //不等于
                    aaCenter.AA_StringReplaceFirst(v, "!=", "");
                    float value = aaCenter.AA_StringFloat(v) * count;
                    float value2 = aaCenter.AA_StringFloat(v2);
                    if (value2 == value) {
                        needstr = needstr + aa_color_blues + "· [" + k + "]" + aa_color_yellow + " x " + aaCenter.AA_StringFromFloat(value2) + "|r\n";
                        isOk = false;
                    }
                }
                if (v.find("=") != string::npos) { //等于
                    aaCenter.AA_StringReplaceFirst(v, "=", "");
                    float value = aaCenter.AA_StringFloat(v) * count;
                    float value2 = aaCenter.AA_StringFloat(v2);
                    if (value2 != value) {
                        needstr = needstr + aa_color_blues + "· [" + k + "]" + aa_color_yellow + " x " + aaCenter.AA_StringFromFloat(value2) + "|r\n";
                        isOk = false;
                    }
                }
            }
        }
    }
    if (conf.diy_account != "" && conf.diy_account != "0") {
        std::map<std::string, std::string> diy_accounts; diy_accounts.clear();
        aaCenter.AA_StringToStringMap(conf.diy_account, diy_accounts);

        std::string m_diy_accounts = aaCenter.aa_accounts[player->GetSession()->GetAccountId()].diy_account;
        std::map<std::string, std::string> mdiy_accounts; mdiy_accounts.clear();
        aaCenter.AA_StringToStringMap(m_diy_accounts, mdiy_accounts);

        for (auto itr : diy_accounts) {
            std::string k = itr.first;
            std::string v = itr.second;
            std::string v2 = mdiy_accounts[k];
            if (v.find(">") == string::npos && v.find("<") == string::npos && v.find("!=") == string::npos && v.find("=") == string::npos) { //大于等于，消耗
                float value = aaCenter.AA_StringFloat(v) * count;
                float value2 = aaCenter.AA_StringFloat(v2);
                if (value2 < value) {
                    needstr = needstr + aa_color_blues + "· [" + k + "]" + aa_color_yellow + " x " + aaCenter.AA_StringFromFloat(value2) + "|r\n";
                    isOk = false;
                }
            }
            else {
                if (v.find(">") != string::npos) { //大于
                    aaCenter.AA_StringReplaceFirst(v, ">", "");
                    float value = aaCenter.AA_StringFloat(v) * count;
                    float value2 = aaCenter.AA_StringFloat(v2);
                    if (value2 <= value) {
                        needstr = needstr + aa_color_blues + "· [" + k + "]" + aa_color_yellow + " x " + aaCenter.AA_StringFromFloat(value2) + "|r\n";
                        isOk = false;
                    }
                }
                if (v.find(">") != string::npos) { //大于
                    aaCenter.AA_StringReplaceFirst(v, ">", "");
                    float value = aaCenter.AA_StringFloat(v);
                    float value2 = aaCenter.AA_StringFloat(v2);
                    if (value2 <= value) {
                        needstr = needstr + aa_color_blues + "· [" + k + "]" + aa_color_yellow + " x " + aaCenter.AA_StringFromFloat(value2) + "|r\n";
                        isOk = false;
                    }
                }
                if (v.find("<") != string::npos) { //小于
                    aaCenter.AA_StringReplaceFirst(v, "<", "");
                    float value = aaCenter.AA_StringFloat(v);
                    float value2 = aaCenter.AA_StringFloat(v2);
                    if (value2 >= value) {
                        needstr = needstr + aa_color_blues + "· [" + k + "]" + aa_color_yellow + " x " + aaCenter.AA_StringFromFloat(value2) + "|r\n";
                        isOk = false;
                    }
                }
                if (v.find("!=") != string::npos) { //不等于
                    aaCenter.AA_StringReplaceFirst(v, "!=", "");
                    float value = aaCenter.AA_StringFloat(v);
                    float value2 = aaCenter.AA_StringFloat(v2);
                    if (value2 == value) {
                        needstr = needstr + aa_color_blues + "· [" + k + "]" + aa_color_yellow + " x " + aaCenter.AA_StringFromFloat(value2) + "|r\n";
                        isOk = false;
                    }
                }
                if (v.find("=") != string::npos) { //等于
                    aaCenter.AA_StringReplaceFirst(v, "=", "");
                    float value = aaCenter.AA_StringFloat(v);
                    float value2 = aaCenter.AA_StringFloat(v2);
                    if (value2 != value) {
                        needstr = needstr + aa_color_blues + "· [" + k + "]" + aa_color_yellow + " x " + aaCenter.AA_StringFromFloat(value2) + "|r\n";
                        isOk = false;
                    }
                }
            }
        }
    }
    if (conf.game_event != "" && conf.game_event != "0") {
        std::vector<int32> v;
        aaCenter.AA_StringToVectorInt(conf.game_event, v, ",");
        for (auto itr : v) {
            if (itr > 0) {
                if (!sGameEventMgr->IsActiveEvent(itr)) {
                    needstr = needstr + aa_color_blues + "· [事件] " + aa_color_yellow + "未开始|r\n";
                    isOk = false;
                }
            }
        }
    }
    if (conf.group_count > 0) {
        uint32 count = 0;
        if (!player->GetGroup()) {
            count = 0;
            isOk = false;
        }
        else if (player->GetGroup()->GetMembersCount() < conf.group_count) {
            count = player->GetGroup()->GetMembersCount();
            isOk = false;
        }
        if (!isOk) {
            needstr = needstr + aa_color_blues + "· [队伍人数]" + aa_color_yellow + " x " + std::to_string(count) + "|r\n";
        }

    }

    if (conf.group_duizhang != 0) {
        if (player->GetGroup() && player->GetGroup()->GetMembersCount() > 1 && player->GetGroup()->GetLeaderGUID() != player->GetGUID()) {
            needstr = needstr + aa_color_blues + "· [队长] " + aa_color_yellow + "未满足\n";
            isOk = false;
        }
    }

    if (conf.is_yongbing == 1) {
        needstr = needstr + aa_color_blues + "· [雇佣兵专属] " + aa_color_yellow + "未满足\n";
        isOk = false;
    }

    if (isOk) {
        std::vector<AA_Event_Map> mapeventconfs = aaCenter.aa_event_maps["达到需求"];
        for (auto mapconf : mapeventconfs) {
            aaCenter.AA_EventMapStart(player, mapconf);
        }
    }
    return isOk;
}

void AACenter::M_Need(Player* player, uint32 needid, uint32 count)
{
    try {
        if (!player || !player->ToPlayer()) {
            return;
        }
        AA_Need_Conf conf = aaCenter.aa_needs[needid];
        player->ModifyMoney(-int32(conf.money * count));
        ObjectGuid::LowType guidlow = player->GetGUIDLow();
        uint32 accountid = player->GetSession()->GetAccountId();
        int32 jf = (int32)aaCenter.aa_accounts[accountid].jifen - (int32)conf.jifen * count;
        jf = jf < 0 ? 0 : jf;
        aaCenter.aa_accounts[accountid].jifen = jf;
        int32 pd = (int32)aaCenter.aa_accounts[accountid].paodian - (int32)conf.paodian * count;
        pd = pd < 0 ? 0 : pd;
        aaCenter.aa_accounts[accountid].paodian = pd;
        int32 mb = (int32)aaCenter.aa_accounts[accountid].mobi - (int32)conf.mobi * count;
        mb = mb < 0 ? 0 : mb;
        aaCenter.aa_accounts[accountid].mobi = mb;
        int32 zc = (int32)aaCenter.aa_accounts[accountid].battlecore - (int32)conf.battlecore * count;
        zc = zc < 0 ? 0 : zc;
        aaCenter.aa_accounts[accountid].battlecore = zc;
        if (conf.jifen > 0 || conf.paodian > 0 || conf.mobi > 0 || conf.battlecore > 0) {
            time_t timep;
            time(&timep); /*当前time_t类型UTC时间*/
            aaCenter.aa_accounts[accountid].update_time = timep;
            aaCenter.aa_accounts[accountid].isUpdate = true;
        }
        if (conf.deplete == 0) {
            std::string itemstr = "";
            if (conf.items != "" && conf.items != "0") {
                std::map<int32, int32> items; items.clear();
                aaCenter.AA_StringToMap(conf.items, items);
                for (auto itr : items) {
                    if (itr.first <= 0 || itr.second <= 0) {
                        continue;
                    }
                    ItemTemplate const* pProto = sObjectMgr->GetItemTemplate(itr.first);
                    if (!pProto) {
                        continue;
                    }
                    uint32 count_need = itr.second * count;
                    aaCenter.AA_DestroyItemInBagCount(player, itr.first, count_need, true, false);
                }
            }
        }
        if (conf.diy_guid != "" && conf.diy_guid != "0") {
            std::map<std::string, std::string> diy_guids; diy_guids.clear();
            aaCenter.AA_StringToStringMap(conf.diy_guid, diy_guids);

            std::string m_diy_guids = aaCenter.aa_characterss[guidlow].diy_guid;
            std::map<std::string, std::string> mdiy_guids; mdiy_guids.clear();
            aaCenter.AA_StringToStringMap(m_diy_guids, mdiy_guids);

            for (auto itr : diy_guids) {
                std::string k = itr.first;
                std::string v = itr.second;
                std::string v2 = mdiy_guids[k];
                if (v.find(">") == string::npos && v.find("<") == string::npos && v.find("!=") == string::npos && v.find("=") == string::npos) { //大于等于
                    uint32 value = aaCenter.AA_StringUint32(v) * count;
                    uint32 value2 = aaCenter.AA_StringUint32(v2);
                    if (value2 >= value) {
                        value2 -= value;
                    }
                    else {
                        value2 = 0;
                    }
                    mdiy_guids[k] = std::to_string(value2);
                }
            }
            time_t timep;
            time(&timep); /*当前time_t类型UTC时间*/
            aaCenter.aa_characterss[guidlow].update_time = timep;
            aaCenter.aa_characterss[guidlow].isUpdate = true;
            std::string str = "";
            aaCenter.AA_StringMapToString(mdiy_guids, str);
            aaCenter.aa_characterss[guidlow].diy_guid = str;
        }
        if (conf.diy_system != "" && conf.diy_system != "0") {
            std::map<std::string, std::string> diy_systems; diy_systems.clear();
            aaCenter.AA_StringToStringMap(conf.diy_system, diy_systems);

            std::string m_diy_systems = aaCenter.aa_system_conf.diy_system;
            std::map<std::string, std::string> mdiy_systems; mdiy_systems.clear();
            aaCenter.AA_StringToStringMap(m_diy_systems, mdiy_systems);

            for (auto itr : diy_systems) {
                std::string k = itr.first;
                std::string v = itr.second;
                std::string v2 = mdiy_systems[k];
                if (v.find(">") == string::npos && v.find("<") == string::npos && v.find("!=") == string::npos && v.find("=") == string::npos) { //大于等于
                    uint32 value = aaCenter.AA_StringUint32(v) * count;
                    uint32 value2 = aaCenter.AA_StringUint32(v2);
                    if (value2 >= value) {
                        value2 -= value;
                    }
                    else {
                        value2 = 0;
                    }
                    mdiy_systems[k] = std::to_string(value2);
                }
            }
            time_t timep;
            time(&timep); /*当前time_t类型UTC时间*/
            aaCenter.aa_system_conf.update_time = timep;
            aaCenter.aa_system_conf.isUpdate = true;
            std::string str = "";
            aaCenter.AA_StringMapToString(mdiy_systems, str);
            aaCenter.aa_system_conf.diy_system = str;
        }
        if (conf.diy_account != "" && conf.diy_account != "0") {
            std::map<std::string, std::string> diy_accounts; diy_accounts.clear();
            aaCenter.AA_StringToStringMap(conf.diy_account, diy_accounts);

            std::string m_diy_accounts = aaCenter.aa_accounts[accountid].diy_account;
            std::map<std::string, std::string> mdiy_accounts; mdiy_accounts.clear();
            aaCenter.AA_StringToStringMap(m_diy_accounts, mdiy_accounts);

            for (auto itr : diy_accounts) {
                std::string k = itr.first;
                std::string v = itr.second;
                std::string v2 = mdiy_accounts[k];
                if (v.find(">") == string::npos && v.find("<") == string::npos && v.find("!=") == string::npos && v.find("=") == string::npos) { //大于等于
                    uint32 value = aaCenter.AA_StringUint32(v) * count;
                    uint32 value2 = aaCenter.AA_StringUint32(v2);
                    if (value2 >= value) {
                        value2 -= value;
                    }
                    else {
                        value2 = 0;
                    }
                    mdiy_accounts[k] = std::to_string(value2);
                }
            }
            time_t timep;
            time(&timep); /*当前time_t类型UTC时间*/
            aaCenter.aa_accounts[accountid].update_time = timep;
            aaCenter.aa_accounts[accountid].isUpdate = true;
            std::string str = "";
            aaCenter.AA_StringMapToString(mdiy_accounts, str);
            aaCenter.aa_accounts[accountid].diy_account = str;
        }
    }
    catch (std::exception const& e) {}
}

bool AACenter::M_Reward(Player* player, uint32 rewardid, uint32 count)
{
    if (!player || !player->ToPlayer()) {
        return false;
    }
    if (rewardid <= 0) {
        return false;
    }
    M_RewardDo(player, rewardid, count);
    return true;
}

void AACenter::M_RewardDo(Player* player, uint32 rewardid, uint32 count)
{
    try {
        if (!player || !player->ToPlayer()) {
            return;
        }
        AA_Reward_Conf conf = aaCenter.aa_rewards[rewardid];
        if (conf.exp > 0) {
            player->GiveXP(conf.exp, nullptr);
        }
        if (conf.money > 0) {
            player->ModifyMoney(conf.money * count);
        }
        uint32 accountid = player->GetSession()->GetAccountId();
        ObjectGuid::LowType guidlow = player->GetGUIDLow();
        time_t timep;
        time(&timep);
        if (conf.vip_level > 0 && aaCenter.aa_accounts[accountid].vip < conf.vip_level) {
            aaCenter.aa_accounts[accountid].vip = conf.vip_level;
            AA_Vip_Conf vip_conf = aaCenter.aa_vip_confs[conf.vip_level];
            if (vip_conf.reward > 0) {
                aaCenter.M_Reward(player, vip_conf.reward);
            }
            aaCenter.aa_accounts[accountid].update_time = timep;
            aaCenter.aa_accounts[accountid].isUpdate = true;
        }
        if (conf.jxds > 0) {
            aaCenter.aa_characters_junxians[guidlow].dianshu_all = conf.jxds * count + aaCenter.aa_characters_junxians[guidlow].dianshu_all;
            aaCenter.aa_characters_junxians[guidlow].update_time = timep;
            aaCenter.aa_characters_junxians[guidlow].isUpdate = true;
        }
        if (conf.dqds > 0) {
            aaCenter.aa_characters_douqis[guidlow].dianshu_all = conf.dqds * count + aaCenter.aa_characters_douqis[guidlow].dianshu_all;
            aaCenter.aa_characters_douqis[guidlow].update_time = timep;
            aaCenter.aa_characters_douqis[guidlow].isUpdate = true;
        }
        if (conf.dfds > 0) {
            aaCenter.aa_characters_dianfengs[guidlow].dianshu_all = conf.dfds * count + aaCenter.aa_characters_dianfengs[guidlow].dianshu_all;
            aaCenter.aa_characters_dianfengs[guidlow].update_time = timep;
            aaCenter.aa_characters_dianfengs[guidlow].isUpdate = true;
        }

        uint32 vipxp = 0;
        if (accountid > 0) {
            AA_Account conf = aaCenter.aa_accounts[accountid];
            AA_Vip_Conf vipconf = aaCenter.aa_vip_confs[conf.vip];
            vipxp = vipconf.exp;
        }
        if (conf.jxexp > 0) {
            if (vipxp > 0) {
                aaCenter.GiveJXXP(player, conf.jxexp * count * vipxp / 100.0);
            }
            else {
                aaCenter.GiveJXXP(player, conf.jxexp * count);
            }
        }
        if (conf.dqexp > 0) {
            if (vipxp > 0) {
                aaCenter.GiveDQXP(player, conf.dqexp * count * vipxp / 100.0);
            }
            else {
                aaCenter.GiveDQXP(player, conf.dqexp * count);
            }
        }
        if (conf.dfexp > 0) {
            if (vipxp > 0) {
                aaCenter.GiveDFXP(player, conf.dfexp * count * vipxp / 100.0);
            }
            else {
                aaCenter.GiveDFXP(player, conf.dfexp * count);
            }
        }
        if (conf.czexp > 0) {
            if (vipxp > 0) {
                aaCenter.GiveCZXP(player, conf.czexp * count * vipxp / 100.0);
            }
            else {
                aaCenter.GiveCZXP(player, conf.czexp * count);
            }
        }
        aaCenter.aa_accounts[accountid].jifen += conf.jifen * count;
        aaCenter.aa_accounts[accountid].paodian += conf.paodian * count;
        aaCenter.aa_accounts[accountid].mobi += conf.mobi * count;
        aaCenter.aa_accounts[accountid].battlecore += conf.battlecore * count;
        if (conf.jifen > 0 || conf.paodian > 0 || conf.mobi > 0 || conf.battlecore > 0) {
            aaCenter.aa_accounts[accountid].update_time = timep;
            aaCenter.aa_accounts[accountid].isUpdate = true;
        }
        if (conf.items != "" && conf.items != "0") {
            std::map<int32, int32> items; items.clear();
            aaCenter.AA_StringToMap(conf.items, items);
            for (auto itr : items) {
                if (itr.first <= 0 || itr.second <= 0) {
                    continue;
                }
                ItemTemplate const* pProto = sObjectMgr->GetItemTemplate(itr.first);
                if (!pProto) {
                    continue;
                }
                player->AddItem(itr.first, itr.second * count);
            }
        }
        if (conf.spells != "0" && conf.spells != "") {
            std::vector<int32> v;
            aaCenter.AA_StringToVectorInt(conf.spells, v, ",");
            for (size_t i = 0; i < v.size(); i++) {
                uint32 spellid = v[i];
                player->LearnSpell(spellid, true);
            }
        }

        if (conf.buffs != "0" && conf.buffs != "") {
            std::vector<int32> v;
            aaCenter.AA_StringToVectorInt(conf.buffs, v, ",");
            for (size_t i = 0; i < v.size(); i++) {
                uint32 buffid = v[i];
                player->AddAura(buffid, player);
            }
        }

        if (conf.teleport_id > 0) {
            AA_Teleport_Conf tconf = aaCenter.aa_teleports[conf.teleport_id];
            aaCenter.AA_TelScript(player, tconf);
        }

        if (conf.touxian > 0) {
            if (CharTitlesEntry const* titleInfo = sCharTitlesStore.LookupEntry(conf.touxian)) {
                player->SetTitle(titleInfo);
            }
        }

        if (conf.gm != "") {
            aaCenter.AA_DoCommand(player, conf.gm.c_str());
        }

        if (conf.diy_guid != "" && conf.diy_guid != "0") {
            std::map<std::string, std::string> diy_guids; diy_guids.clear();
            aaCenter.AA_StringToStringMap(conf.diy_guid, diy_guids);

            std::string m_diy_guids = aaCenter.aa_characterss[guidlow].diy_guid;
            std::map<std::string, std::string> mdiy_guids; mdiy_guids.clear();
            aaCenter.AA_StringToStringMap(m_diy_guids, mdiy_guids);

            for (auto itr : diy_guids) {
                std::string k = itr.first;
                std::string v = itr.second;
                std::string v2 = mdiy_guids[k];
                uint32 value2 = aaCenter.AA_StringUint32(v2);
                if (v.find("+") != string::npos || (v.find("+") == string::npos && v.find("-") == string::npos && v.find("=") == string::npos)) { //加
                    aaCenter.AA_StringReplaceFirst(v, "+", "");
                    uint32 value = aaCenter.AA_StringUint32(v) * count;
                    value2 += value;
                }
                if (v.find("-") != string::npos) { //减
                    aaCenter.AA_StringReplaceFirst(v, "-", "");
                    uint32 value = aaCenter.AA_StringUint32(v) * count;
                    if (value2 >= value) {
                        value2 -= value;
                    }
                    else {
                        value2 = 0;
                    }
                }
                if (v.find("=") != string::npos) { //赋值
                    aaCenter.AA_StringReplaceFirst(v, "=", "");
                    uint32 value = aaCenter.AA_StringUint32(v);
                    value2 = value;
                }
                mdiy_guids[k] = std::to_string(value2);
            }
            time_t timep;
            time(&timep); /*当前time_t类型UTC时间*/
            aaCenter.aa_characterss[guidlow].update_time = timep;
            aaCenter.aa_characterss[guidlow].isUpdate = true;
            std::string str = "";
            aaCenter.AA_StringMapToString(mdiy_guids, str);
            aaCenter.aa_characterss[guidlow].diy_guid = str;
        }
        if (conf.diy_system != "" && conf.diy_system != "0") {
            std::map<std::string, std::string> diy_systems; diy_systems.clear();
            aaCenter.AA_StringToStringMap(conf.diy_system, diy_systems);

            std::string m_diy_systems = aaCenter.aa_system_conf.diy_system;
            std::map<std::string, std::string> mdiy_systems; mdiy_systems.clear();
            aaCenter.AA_StringToStringMap(m_diy_systems, mdiy_systems);

            for (auto itr : diy_systems) {
                std::string k = itr.first;
                std::string v = itr.second;
                std::string v2 = mdiy_systems[k];
                uint32 value2 = aaCenter.AA_StringUint32(v2);
                if (v.find("+") != string::npos || (v.find("+") == string::npos && v.find("-") == string::npos && v.find("=") == string::npos)) { //加
                    aaCenter.AA_StringReplaceFirst(v, "+", "");
                    uint32 value = aaCenter.AA_StringUint32(v) * count;
                    value2 += value;
                }
                if (v.find("-") != string::npos) { //减
                    aaCenter.AA_StringReplaceFirst(v, "-", "");
                    uint32 value = aaCenter.AA_StringUint32(v) * count;
                    if (value2 >= value) {
                        value2 -= value;
                    }
                    else {
                        value2 = 0;
                    }
                }
                if (v.find("=") != string::npos) { //赋值
                    aaCenter.AA_StringReplaceFirst(v, "=", "");
                    uint32 value = aaCenter.AA_StringUint32(v);
                    value2 = value;
                }
                mdiy_systems[k] = std::to_string(value2);
            }
            time_t timep;
            time(&timep); /*当前time_t类型UTC时间*/
            aaCenter.aa_system_conf.update_time = timep;
            aaCenter.aa_system_conf.isUpdate = true;
            std::string str = "";
            aaCenter.AA_StringMapToString(mdiy_systems, str);
            aaCenter.aa_system_conf.diy_system = str;
        }
        if (conf.diy_account != "" && conf.diy_account != "0") {
            std::map<std::string, std::string> diy_accounts; diy_accounts.clear();
            aaCenter.AA_StringToStringMap(conf.diy_account, diy_accounts);

            std::string m_diy_accounts = aaCenter.aa_accounts[accountid].diy_account;
            std::map<std::string, std::string> mdiy_accounts; mdiy_accounts.clear();
            aaCenter.AA_StringToStringMap(m_diy_accounts, mdiy_accounts);

            for (auto itr : diy_accounts) {
                std::string k = itr.first;
                std::string v = itr.second;
                std::string v2 = mdiy_accounts[k];
                uint32 value2 = aaCenter.AA_StringUint32(v2);
                if (v.find("+") != string::npos || (v.find("+") == string::npos && v.find("-") == string::npos && v.find("=") == string::npos)) { //加
                    aaCenter.AA_StringReplaceFirst(v, "+", "");
                    uint32 value = aaCenter.AA_StringUint32(v) * count;
                    value2 += value;
                }
                if (v.find("-") != string::npos) { //减
                    aaCenter.AA_StringReplaceFirst(v, "-", "");
                    uint32 value = aaCenter.AA_StringUint32(v) * count;
                    if (value2 >= value) {
                        value2 -= value;
                    }
                    else {
                        value2 = 0;
                    }
                }
                if (v.find("=") != string::npos) { //赋值
                    aaCenter.AA_StringReplaceFirst(v, "=", "");
                    uint32 value = aaCenter.AA_StringUint32(v);
                    value2 = value;
                }
                mdiy_accounts[k] = std::to_string(value2);
            }
            time_t timep;
            time(&timep); /*当前time_t类型UTC时间*/
            aaCenter.aa_accounts[accountid].update_time = timep;
            aaCenter.aa_accounts[accountid].isUpdate = true;
            std::string str = "";
            aaCenter.AA_StringMapToString(mdiy_accounts, str);
            aaCenter.aa_accounts[accountid].diy_account = str;
        }

        if (conf.game_event != "" && conf.game_event != "0") {
            std::vector<int32> v;
            aaCenter.AA_StringToVectorInt(conf.game_event, v, ",");
            for (auto itr : v) {
                if (itr > 0) {
                    if (!sGameEventMgr->StartEvent(itr)) {
                        return;
                    }
                }
            }
        }

        std::string reward = aaCenter.AA_GetRewardText(rewardid, count);
        if (reward != "") {
            aaCenter.AA_SendMessage(player, 0, "╔┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈╗");
            aaCenter.AA_StringReplace(reward, "&", "\n");
            reward = aaCenter.aa_color_green + "· 获得奖励：|r\n" + reward;
            aaCenter.AA_SendMessage(player, 0, reward.c_str());
            aaCenter.AA_SendMessage(player, 0, "╚┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈╝");
        }
    }
    catch (std::exception const& e) {}
}

Item* AACenter::GetItemByGUIDLow(Player* player, ObjectGuid::LowType guid)
{
    ItemSearchLocation where = ItemSearchLocation::Everywhere;
    Item* result = nullptr;
    player->ForEachItem(where, [&result, guid](Item* item)
    {
        if (item->GetGUIDLow() == guid)
        {
            result = item;
            return ItemSearchCallbackResult::Stop;
        }

        return ItemSearchCallbackResult::Continue;
    });
    return result;
}


// aawow 拾取鉴定，购买制造，洗炼，品质券 (type 拾取鉴定-3，购买制造-2，洗炼-1 zu > 0) (品质券type>0 zu=0)int32 type
// 拾取鉴定，购买制造，洗炼（改变装备的覆盖属性，后缀，极品，附魔属性，附魔技能，强化组，成长组），清空所有属性
// 品质券（改变装备的覆盖属性，后缀，极品，附魔属性，附魔技能，强化组，成长组）清空所有属性，获得指定品质
// 覆盖属性，极品属性，附魔属性，附魔技能，强化组，成长组
uint32 AACenter::M_NonsuchItem(Player* player, Item* pItem, uint32 zu, int32 type)
{
    try {
        if (!pItem) { aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000物品不存在。"); return 0; }
        ItemTemplate const* pProto = pItem->GetTemplate();
        if (!pProto) { aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000物品不存在。"); return 0; }
        //1、过滤不参与鉴定的物品
        AA_Item_Nonsuch conf;
        AA_Character_Instance a_conf = aaCenter.aa_character_instances[pItem->GetGUIDLow()];
        uint32 itemlevel = pItem->GetItemLevel(player);
        //2、获取鉴定conf
        if (type > 0) { //使用了品质券id
            conf = aaCenter.aa_item_nonsuchs[type];
        }
        else {
            if (type == -1) { //洗炼
                uint32 needid = aaCenter.aa_world_confs[25].value1;
                if (needid > 0) {
                    if (aaCenter.M_CanNeed(player, needid)) {
                        aaCenter.M_Need(player, needid);
                    }
                    else {
                        return 0;
                    }
                }
                uint32 xlzu = aaCenter.aa_item_jianding_xls[pProto->GetId()].zu;
                zu = xlzu > 0 ? xlzu : zu;
                aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFFFF00洗炼成功");
            }
            std::vector<uint32> conf_ids = aaCenter.aa_item_nonsuch_zus[zu];
            //获取总chance，分母
            int count = conf_ids.size();
            if (count == 0) { //这里是防错验证，Bug，有组，不可能找不到
                conf = aaCenter.aa_item_nonsuchs[a_conf.jd_id];
            }
            else {
                uint32 chanceMax = 0;
                for (int i = 0; i < count; i++) {
                    uint32 id = conf_ids[i];
                    AA_Item_Nonsuch conf = aaCenter.aa_item_nonsuchs[id];
                    chanceMax += conf.chance;
                }
                if (chanceMax == 0) { chanceMax = 1; }
                //获取随机chance，分子
                uint32 chanceVal = rand() % chanceMax;
                //获取Index
                uint32 max = 0;
                uint32 min = 0;
                int index = -1;
                for (int i = 0; i < count; i++) {
                    uint32 id = conf_ids[i];
                    AA_Item_Nonsuch conf = aaCenter.aa_item_nonsuchs[id];
                    max = conf.chance + max;
                    min = 0;
                    if (i == 0) {
                        min = 0;
                    }
                    else {
                        uint32 id = conf_ids[i - 1];
                        AA_Item_Nonsuch conf = aaCenter.aa_item_nonsuchs[id];
                        min = conf.chance + min;
                    }

                    if (min <= chanceVal && chanceVal < max) {
                        index = i;
                        break;
                    }
                }
                uint32 id = conf_ids[index];
                conf = aaCenter.aa_item_nonsuchs[id];
            }
        }
        //3、成长、强化组
        uint32 qh_zu = 0;
        if (aaCenter.aa_world_confs[37].value1 == 1) {
            qh_zu = aaCenter.AA_StringRandom(aa_item_qh_ids[pProto->GetId()].zus);
            if (qh_zu == 0 && aaCenter.aa_item_nojiandings[pProto->GetId()].itemid == 0) {
                if (conf.qh_zus != "") { qh_zu = aaCenter.AA_StringRandom(conf.qh_zus); }
            }
        }
        uint32 cz_zu = 0;
        if (aaCenter.aa_world_confs[57].value1 == 1) {
            cz_zu = aaCenter.AA_StringRandom(aa_item_level_ids[pProto->GetId()].zus);
            if (cz_zu == 0 && aaCenter.aa_item_nojiandings[pProto->GetId()].itemid == 0) {
                if (conf.cz_zus != "") { cz_zu = aaCenter.AA_StringRandom(conf.cz_zus); }
            }
        }
        //4、覆盖属性，根据装备类型判断，比如如果是武器，必有 伤害和速度，且不消耗覆盖属性数量
        std::vector<int32> types; types.clear();
        std::vector<int32> values; values.clear();
        std::vector<uint32> confids = aaCenter.aa_stat_zus[conf.fg_statzu];
        for (auto it = confids.begin(); it != confids.end(); it++)
        {
            AA_Stat stat_conf = aaCenter.aa_stats[*it];
            uint32 statVal = 0;
            if (conf.fg_value1 >= conf.fg_value2) {
                statVal = conf.fg_value1;
            }
            else { statVal = (rand() % (conf.fg_value2 - conf.fg_value1 + 1)) + conf.fg_value1; }
            statVal = statVal * (stat_conf.value / 100.0);
            if (stat_conf.value < 0 && stat_conf.point < 0 && stat_conf.point <= stat_conf.value) {
                uint32 value1 = abs(stat_conf.value);
                uint32 value2 = abs(stat_conf.point);
                uint32 value = (rand() % (value2 - value1 + 1)) + value1;
                statVal = value;
            }
            switch (pProto->GetClass()) {
            case ITEM_CLASS_WEAPON: //武器
            {
                if (stat_conf.type == 120) {
                    if (pProto->GetDelay() > 0) {
                        types.push_back(stat_conf.id);
                        values.push_back(statVal);
                    }
                }
                float damageMin = 0; float damageMax = 0;
                pProto->GetDamage(itemlevel, damageMin, damageMax);
                for (uint32 type = 0; type < 7; type++) {
                    if (stat_conf.type == 121 + type * 2 || stat_conf.type == 122 + type * 2) {
                        for (int i = 0; i < 2; i++) { //type 0-6
                            if (damageMax > 0) {
                                if (pProto->GetDamageType() == type) {
                                    types.push_back(stat_conf.id);
                                    values.push_back(statVal);
                                }
                            }
                        }
                    }
                }
            }
            break;
            case ITEM_CLASS_ARMOR: //护甲
            {
                if (stat_conf.type == 135) {
                    if (pProto->GetArmor(itemlevel) > 0) {
                        types.push_back(stat_conf.id);
                        values.push_back(statVal);
                    }
                }
            }
            break;
            default:
                break;
            }
        }
        for (auto it = confids.begin(); it != confids.end();)
        {
            AA_Stat stat_conf = aaCenter.aa_stats[*it];
            if (stat_conf.type >= 120 && stat_conf.type <= 136) {
                it = confids.erase(it);
            }
            else {
                ++it;
            }
        }
        if (conf.fg_count1 > 0 || conf.fg_count2 > 0) {
            uint32 fg_count = 0;
            if (conf.fg_count1 >= conf.fg_count2) {
                fg_count = conf.fg_count1;
            }
            else {
                fg_count = (rand() % (conf.fg_count2 - conf.fg_count1 + 1)) + conf.fg_count1;
            }
            for (uint32 i = 0; i < fg_count; i++) {
                if (confids.size() == 0) { break; }
                //获取总chance，分母
                uint32 chanceMax = 0;
                for (auto it = confids.begin(); it != confids.end(); it++)
                {
                    AA_Stat conf = aaCenter.aa_stats[*it];
                    chanceMax += conf.chance;
                }
                if (chanceMax == 0) { chanceMax = 1; }
                //获取随机chance，分子
                uint32 chanceVal = rand() % chanceMax; uint32 max = 0; uint32 min = 0;
                std::vector<uint32>::iterator rit;
                for (auto it = confids.begin(); it != confids.end(); it++)
                {
                    AA_Stat conf = aaCenter.aa_stats[*it];
                    max = conf.chance + max; min = 0;
                    if (it == confids.begin()) { min = 0; }
                    else {
                        AA_Stat conf = aaCenter.aa_stats[*it - 1];
                        min = conf.chance + min;
                    }
                    if (min <= chanceVal && chanceVal < max) { rit = it; break; }
                }
                AA_Stat stat_conf = aaCenter.aa_stats[*rit];
                uint32 statVal = 0;
                if (conf.fg_value1 >= conf.fg_value2) {
                    statVal = conf.fg_value1;
                }
                else { statVal = (rand() % (conf.fg_value2 - conf.fg_value1 + 1)) + conf.fg_value1; }
                statVal = statVal * (stat_conf.value / 100.0);
                if (stat_conf.value < 0 && stat_conf.point < 0 && stat_conf.point <= stat_conf.value) {
                    uint32 value1 = abs(stat_conf.value);
                    uint32 value2 = abs(stat_conf.point);
                    uint32 value = (rand() % (value2 - value1 + 1)) + value1;
                    statVal = value;
                }
                types.push_back(stat_conf.id);
                values.push_back(statVal);
                if (conf.fg_only == 1) {
                    confids.erase(rit);
                }
            }
        }
        else {
            for (uint8 i = 0; i < MAX_ITEM_PROTO_STATS; ++i)
            {
                int32 statType = pItem->GetItemStatType(i);
                if (statType == -1)
                    continue;

                float val = pItem->GetItemStatValue(i, player);
                if (val == 0)
                    continue;

                uint32 type_id = aaCenter.aa_stat_types[conf.fg_statzu][statType];
                for (size_t j = 0; j < types.size(); j++) {
                    uint32 t_id = types[j];
                    if (t_id == type_id) {
                        types.erase(types.begin() + j);
                        values.erase(values.begin() + j);
                        --j;
                    }
                }
                AA_Stat stat_conf = aaCenter.aa_stats[type_id];
                if (stat_conf.value > 0) {
                    val = val * (stat_conf.value / 100.0);
                }
                if (stat_conf.value < 0 && stat_conf.point < 0 && stat_conf.point <= stat_conf.value) {
                    uint32 value1 = -stat_conf.value;
                    uint32 value2 = -stat_conf.point;
                    uint32 value = (rand() % (value2 - value1 + 1)) + value1;
                    val = value;
                }
                types.push_back(type_id);
                values.push_back(val);
            }
            if (pProto->GetDelay() > 0) {
                uint32 type_id = aaCenter.aa_stat_types[conf.fg_statzu][120];
                for (size_t j = 0; j < types.size(); j++) {
                    uint32 t_id = types[j];
                    if (t_id == type_id) {
                        types.erase(types.begin() + j);
                        values.erase(values.begin() + j);
                        --j;
                    }
                }
                AA_Stat stat_conf = aaCenter.aa_stats[type_id];
                uint32 statVal = pProto->GetDelay();
                if (stat_conf.value > 0) {
                    statVal = statVal * (stat_conf.value / 100.0);
                }
                if (stat_conf.value < 0 && stat_conf.point < 0 && stat_conf.point <= stat_conf.value) {
                    uint32 value1 = -stat_conf.value;
                    uint32 value2 = -stat_conf.point;
                    uint32 value = (rand() % (value2 - value1 + 1)) + value1;
                    statVal = value;
                }
                types.push_back(type_id);
                values.push_back(statVal);
            }
            float damageMin = 0; float damageMax = 0;
            pProto->GetDamage(itemlevel, damageMin, damageMax);
            for (uint32 type = 0; type < 7; type++) {
                for (int i = 0; i < 2; i++) {
                    if (damageMin > 0) {
                        if (pProto->GetDamageType() == type) {
                            uint32 type_id = aaCenter.aa_stat_types[conf.fg_statzu][type * 2 + 121];
                            for (size_t j = 0; j < types.size(); j++) {
                                uint32 t_id = types[j];
                                if (t_id == type_id) {
                                    types.erase(types.begin() + j);
                                    values.erase(values.begin() + j);
                                    --j;
                                }
                            }
                            AA_Stat stat_conf = aaCenter.aa_stats[type_id];
                            uint32 statVal = damageMin;
                            if (stat_conf.value > 0) {
                                statVal = statVal * (stat_conf.value / 100.0);
                            }
                            if (stat_conf.value < 0 && stat_conf.point < 0 && stat_conf.point <= stat_conf.value) {
                                uint32 value1 = -stat_conf.value;
                                uint32 value2 = -stat_conf.point;
                                uint32 value = (rand() % (value2 - value1 + 1)) + value1;
                                statVal = value;
                            }
                            types.push_back(type_id);
                            values.push_back(statVal);
                        }
                    }
                    if (damageMax > 0) {
                        if (pProto->GetDamageType() == type) {
                            uint32 type_id = aaCenter.aa_stat_types[conf.fg_statzu][type * 2 + 122];
                            for (size_t j = 0; j < types.size(); j++) {
                                uint32 t_id = types[j];
                                if (t_id == type_id) {
                                    types.erase(types.begin() + j);
                                    values.erase(values.begin() + j);
                                    --j;
                                }
                            }
                            AA_Stat stat_conf = aaCenter.aa_stats[type_id];
                            uint32 statVal = damageMax;
                            if (stat_conf.value > 0) {
                                statVal = statVal * (stat_conf.value / 100.0);
                            }
                            if (stat_conf.value < 0 && stat_conf.point < 0 && stat_conf.point <= stat_conf.value) {
                                uint32 value1 = -stat_conf.value;
                                uint32 value2 = -stat_conf.point;
                                uint32 value = (rand() % (value2 - value1 + 1)) + value1;
                                statVal = value;
                            }
                            types.push_back(type_id);
                            values.push_back(statVal);
                        }
                    }
                }
            }
            if (pProto->GetArmor(itemlevel) > 0) {
                uint32 type_id = aaCenter.aa_stat_types[conf.fg_statzu][135];
                for (size_t j = 0; j < types.size(); j++) {
                    uint32 t_id = types[j];
                    if (t_id == type_id) {
                        types.erase(types.begin() + j);
                        values.erase(values.begin() + j);
                        --j;
                    }
                }
                AA_Stat stat_conf = aaCenter.aa_stats[type_id];
                uint32 statVal = pProto->GetArmor(itemlevel);
                if (stat_conf.value > 0) {
                    statVal = statVal * (stat_conf.value / 100.0);
                }
                if (stat_conf.value < 0 && stat_conf.point < 0 && stat_conf.point <= stat_conf.value) {
                    uint32 value1 = -stat_conf.value;
                    uint32 value2 = -stat_conf.point;
                    uint32 value = (rand() % (value2 - value1 + 1)) + value1;
                    statVal = value;
                }
                types.push_back(type_id);
                values.push_back(statVal);
            }
        }
        ObjectGuid::LowType guidlow = pItem->GetGUIDLow();
        time_t timep;
        time(&timep); /*当前time_t类型UTC时间*/
        aaCenter.aa_character_instances[guidlow].update_time = timep;
        aaCenter.aa_character_instances[guidlow].isUpdate = true;
        aaCenter.aa_character_instances[guidlow].qh_zu = qh_zu;
        aaCenter.aa_character_instances[guidlow].cz_zu = cz_zu;
        //9、清空强化和成长等级属性
        aaCenter.aa_character_instances[guidlow].qh_id = 0;
        aaCenter.aa_character_instances[guidlow].qh_level = 0;
        aaCenter.aa_character_instances[guidlow].qh_values = "";
        aaCenter.aa_character_instances[guidlow].qh_reward_value = 0; //强化奖励属性
        aaCenter.aa_character_instances[guidlow].qh_reward_point = 0; //强化奖励属性百分比
        aaCenter.aa_character_instances[guidlow].qh_reward_spell = ""; //强化奖励技能
        aaCenter.aa_character_instances[guidlow].cz_id = 0;
        aaCenter.aa_character_instances[guidlow].cz_level = 0;
        aaCenter.aa_character_instances[guidlow].cz_exp = 0;
        aaCenter.aa_character_instances[guidlow].cz_values = "";
        aaCenter.aa_character_instances[guidlow].cz_reward_value = 0;
        aaCenter.aa_character_instances[guidlow].cz_reward_point = 0;
        aaCenter.aa_character_instances[guidlow].cz_reward_spell = "";
        std::string fugai = "";
        aaCenter.AA_VectorToStringSort(fugai, types, values);
        aaCenter.aa_character_instances[guidlow].fugai_zu = conf.fg_statzu;
        aaCenter.aa_character_instances[guidlow].fugai = fugai;

        //拾取鉴定或购买制造鉴定的物品有符文凹槽
        if ((conf.fw_count1 > 0 || conf.fw_count2 > 0) && (type == -3 || type == -2)) {
            uint32 fw_count = 0;
            if (conf.fw_count1 >= conf.fw_count2) {
                fw_count = conf.fw_count1;
            }
            else {
                fw_count = (rand() % (conf.fw_count2 - conf.fw_count1 + 1)) + conf.fw_count1;
            }
            aaCenter.aa_character_instances[guidlow].fw_count = fw_count;
        }

        //拾取鉴定或购买制造鉴定的物品有强化等级
        if ((type == -3 || type == -2) && qh_zu > 0) {
            std::vector<uint32> conf_ids = aaCenter.aa_item_upgrade_zus[qh_zu];
            //获取总chance，分母
            int count = conf_ids.size();
            if (count > 0) { //这里是防错验证，Bug，有组，不可能找不到
                uint32 chanceMax = 0;
                for (int i = 0; i < count; i++) {
                    uint32 id = conf_ids[i];
                    AA_Item_Upgrade conf = aaCenter.aa_item_upgrades[id];
                    chanceMax += conf.chance_jd;
                }
                if (chanceMax > 0) {
                    //获取随机chance，分子
                    uint32 chanceVal = rand() % chanceMax;
                    //获取Index
                    uint32 max = 0;
                    uint32 min = 0;
                    int index = -1;
                    for (int i = 0; i < count; i++) {
                        uint32 id = conf_ids[i];
                        AA_Item_Upgrade conf = aaCenter.aa_item_upgrades[id];
                        max = conf.chance_jd + max;
                        min = 0;
                        if (i == 0) {
                            min = 0;
                        }
                        else {
                            uint32 id = conf_ids[i - 1];
                            AA_Item_Upgrade conf = aaCenter.aa_item_upgrades[id];
                            min = conf.chance_jd + min;
                        }

                        if (min <= chanceVal && chanceVal < max) {
                            index = i;
                            break;
                        }
                    }
                    uint32 id = conf_ids[index];
                    AA_Item_Upgrade conf = aaCenter.aa_item_upgrades[id];
                    if (id > 0) {
                        aaCenter.M_UpgradeItem(player, pItem, conf.level);
                    }
                }
            }
        }

        //如果拾取或制造。没有设置过鉴定的物品，只设置基础属性，强化组，成长组
        if (((type == -3 || type == -2) && zu == 0) || aaCenter.aa_item_nojiandings[pProto->GetId()].itemid > 0) {
            return 0;
        }
        //5设置 基础属性，极品，成长，强化，附魔属性，附魔技能
        aaCenter.aa_character_instances[guidlow].jd_zu = zu;
        aaCenter.aa_character_instances[guidlow].jd_id = conf.id;
        aaCenter.aa_character_instances[guidlow].jd_level = conf.level;
        //6、极品属性
        aaCenter.M_NonsuchItemJipin(player, pItem, conf.id, type);
        //7、附魔属性
        aaCenter.M_NonsuchItemFmValue(player, pItem, conf.id, type);
        //8、附魔技能
        aaCenter.M_NonsuchItemFmSpell(player, pItem, conf.id, type);
        //9、随机套装
        aaCenter.M_NonsuchItemSet(player, pItem, conf.id, type);

        return conf.notice;
    }
    catch (std::exception const& e) {
        aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000异常错误cz001");
        return 0;
    }
}

bool AACenter::M_NonsuchItemSet(Player* player, Item* pItem, uint32 nonsuchId, int32 type)
{
    ItemTemplate const* pProto = pItem->GetTemplate();
    if (!pProto) return false;

    AA_Item_Nonsuch conf = aaCenter.aa_item_nonsuchs[nonsuchId];
    AA_Character_Instance a_conf = aaCenter.aa_character_instances[pItem->GetGUIDLow()];
    if (type == 0) { //重铸
        return false;
    }
    if (conf.itemsets != "" && conf.itemsets != "0") {
        uint32 zu = aaCenter.AA_StringRandom(conf.itemsets);
        if (zu > 0) {
            ObjectGuid::LowType guidlow = pItem->GetGUIDLow();
            time_t timep;
            time(&timep); /*当前time_t类型UTC时间*/
            aaCenter.aa_character_instances[guidlow].update_time = timep;
            aaCenter.aa_character_instances[guidlow].isUpdate = true;
            aaCenter.aa_character_instances[guidlow].item_set = zu;
        }
    }
    return true;
}

void AACenter::M_NonsuchItemJipin(Player* player, Item* pItem, uint32 nonsuchId, int32 type)
{
    AA_Item_Nonsuch conf = aaCenter.aa_item_nonsuchs[nonsuchId];
    AA_Character_Instance a_conf = aaCenter.aa_character_instances[pItem->GetGUIDLow()];
    if (type == 0) { //重铸
        if (a_conf.chongzhu_count == 0) {
            aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000该物品无法重铸");
            return;
        }
        uint32 needid = aaCenter.aa_world_confs[67].value1;
        if (needid > 0) {
            if (aaCenter.M_CanNeed(player, needid)) {
                aaCenter.M_Need(player, needid);
            }
            else {
                return;
            }
        }
        // 消耗重铸次数
        aaCenter.aa_character_instances[pItem->GetGUIDLow()].chongzhu_count -= 1;
    }
    //基础属性
    std::vector<int32> types; types.clear();
    std::vector<int32> values; values.clear();
    aaCenter.AA_StringToVector2(a_conf.fugai, types, values);
    //极品
    std::vector<int32> jd_values; jd_values.clear();
    size_t count = types.size();
    for (size_t i = 0; i < count; i++) {
        jd_values.push_back(0);
    }
    //增加极品百分比
    if (conf.jp_percent1 > 0 || conf.jp_percent2 > 0) {
        if (conf.jp_percent1 >= conf.jp_percent2) {
            for (uint32 i = 0; i < count; i++) {
                uint32 fg_typeid = types[i];
                uint32 fg_type = aaCenter.aa_stats[fg_typeid].type;
                uint32 qh_typeid = aaCenter.aa_stat_types[conf.jp_statzu][fg_type];
                AA_Stat aconf = aaCenter.aa_stats[qh_typeid];
                jd_values[i] = values[i] * (conf.jp_percent1 / 100.0) * (aconf.point / 100.0);
            }
        }
        else {
            if (conf.jp_type == 0) {
                uint32 val = (rand() % (conf.jp_percent2 - conf.jp_percent1 + 1)) + conf.jp_percent1;
                for (uint32 i = 0; i < count; i++) {
                    uint32 fg_typeid = types[i];
                    uint32 fg_type = aaCenter.aa_stats[fg_typeid].type;
                    uint32 qh_typeid = aaCenter.aa_stat_types[conf.jp_statzu][fg_type];
                    AA_Stat aconf = aaCenter.aa_stats[qh_typeid];
                    jd_values[i] = values[i] * (val / 100.0) * (aconf.point / 100.0);
                }
            }
            else if (conf.jp_type == 1) {
                for (uint32 i = 0; i < count; i++) {
                    uint32 fg_typeid = types[i];
                    uint32 fg_type = aaCenter.aa_stats[fg_typeid].type;
                    uint32 qh_typeid = aaCenter.aa_stat_types[conf.jp_statzu][fg_type];
                    AA_Stat aconf = aaCenter.aa_stats[qh_typeid];
                    uint32 val = (rand() % (conf.jp_percent2 - conf.jp_percent1 + 1)) + conf.jp_percent1;
                    jd_values[i] = values[i] * (val / 100.0) * (aconf.point / 100.0);
                }
            }
        }
    }
    //增加极品数值
    if (conf.jp_value1 > 0 || conf.jp_value2 > 0)
    {
        if (conf.jp_value1 >= conf.jp_value2) {
            for (uint32 i = 0; i < count; i++) {
                uint32 type = types[i];
                AA_Stat aconf = aaCenter.aa_stats[type];
                jd_values[i] += conf.jp_value1 * (aconf.value / 100.0);
            }
        }
        else {
            uint32 val = 0;
            if (conf.jp_type == 0) {
                val = (rand() % (conf.jp_value2 - conf.jp_value1 + 1)) + conf.jp_value1;
                for (uint32 i = 0; i < count; i++) {
                    uint32 fg_typeid = types[i];
                    uint32 fg_type = aaCenter.aa_stats[fg_typeid].type;
                    uint32 qh_typeid = aaCenter.aa_stat_types[conf.jp_statzu][fg_type];
                    AA_Stat aconf = aaCenter.aa_stats[qh_typeid];
                    jd_values[i] += val * (aconf.value / 100.0);
                }
            }
            else if (conf.jp_type == 1) {
                for (uint32 i = 0; i < count; i++) {
                    uint32 fg_typeid = types[i];
                    uint32 fg_type = aaCenter.aa_stats[fg_typeid].type;
                    uint32 qh_typeid = aaCenter.aa_stat_types[conf.jp_statzu][fg_type];
                    AA_Stat aconf = aaCenter.aa_stats[qh_typeid];
                    val = (rand() % (conf.jp_value2 - conf.jp_value1 + 1)) + conf.jp_value1;
                    jd_values[i] += val * (aconf.value / 100.0);
                }
            }
        }
    }
    ObjectGuid::LowType guidlow = pItem->GetGUIDLow();
    std::string jdvalues = "";
    aaCenter.AA_VectorIntToString(jdvalues, jd_values, ",");
    aaCenter.aa_character_instances[guidlow].jd_values = jdvalues;
    time_t timep;
    time(&timep); /*当前time_t类型UTC时间*/
    aaCenter.aa_character_instances[guidlow].update_time = timep;
    aaCenter.aa_character_instances[guidlow].isUpdate = true;
}

bool AACenter::M_NonsuchItemFmValue(Player* player, Item* pItem, uint32 nonsuchId, int32 type)
{
    AA_Item_Nonsuch conf = aaCenter.aa_item_nonsuchs[nonsuchId];
    AA_Character_Instance a_conf = aaCenter.aa_character_instances[pItem->GetGUIDLow()];
    if (type == 0) { //重铸
        if (a_conf.chongzhu_count == 0) {
            aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000该物品无法重铸");
            return false;
        }
        ObjectGuid::LowType guidlow = pItem->GetGUID().GetCounter();
        AA_Character_Instance conf = aaCenter.aa_character_instances[guidlow];
        uint32 needid = conf.chongzhu_value;
        if (needid > 0) {
            if (aaCenter.M_CanNeed(player, needid)) {
                aaCenter.M_Need(player, needid);
            }
            else {
                return false;
            }
        }
        // 消耗重铸次数
        aaCenter.aa_character_instances[pItem->GetGUIDLow()].chongzhu_count -= 1;
    }
    //附魔属性
    std::vector<int32> types; types.clear();
    std::vector<int32> values; values.clear();
    uint32 last_count = 0;
    if (conf.fmval_count1 > 0 || conf.fmval_count2 > 0) {
        uint32 fmval_count = 0;
        if (conf.fmval_count1 >= conf.fmval_count2) {
            fmval_count = conf.fmval_count1;
        }
        else {
            fmval_count = (rand() % (conf.fmval_count2 - conf.fmval_count1 + 1)) + conf.fmval_count1;
        }

        std::vector<int32> fmval_statzus; fmval_statzus.clear();
        aaCenter.AA_StringToVectorInt(conf.fmval_statzu, fmval_statzus, ",");
        size_t max = fmval_statzus.size();
        std::set<uint32> eraseid; eraseid.clear();
        for (uint32 i = 0; i < fmval_count; i++) {
            uint32 fmval_statzu = 0;
            if (max > 0) {
                if (max > i) {
                    fmval_statzu = fmval_statzus[i];
                }
                else {
                    fmval_statzu = fmval_statzus[max - 1];
                }
            }
            std::vector<uint32> confids = aaCenter.aa_stat_zus[fmval_statzu];
            for (auto it = confids.begin(); it != confids.end();)
            {
                AA_Stat stat_conf = aaCenter.aa_stats[*it];
                //120-136用于基础属性，不参与随机附魔
                if (stat_conf.type >= 120 && stat_conf.type <= 136) {
                    it = confids.erase(it);
                }
                else if (std::find(eraseid.begin(), eraseid.end(), *it) != eraseid.end()) {
                    it = confids.erase(it);
                }
                else {
                    it++;
                }
            }
            if (confids.size() == 0) { break; }
            //获取总chance，分母
            uint32 chanceMax = 0;
            for (auto it = confids.begin(); it != confids.end(); it++)
            {
                AA_Stat conf = aaCenter.aa_stats[*it];
                chanceMax += conf.chance;
            }
            if (chanceMax == 0) { chanceMax = 1; }
            //获取随机chance，分子
            uint32 chanceVal = rand() % chanceMax; uint32 max = 0; uint32 min = 0;
            std::vector<uint32>::iterator rit;
            for (auto it = confids.begin(); it != confids.end(); it++)
            {
                AA_Stat conf = aaCenter.aa_stats[*it];
                max = conf.chance + max; min = 0;
                if (it == confids.begin()) { min = 0; }
                else {
                    AA_Stat conf = aaCenter.aa_stats[*it - 1];
                    min = conf.chance + min;
                }
                if (min <= chanceVal && chanceVal < max) { rit = it; break; }
            }
            AA_Stat stat_conf = aaCenter.aa_stats[*rit];
            uint32 statVal = 0;
            if (conf.fmval_value1 >= 0 && conf.fmval_value2 >= 0) {
                if (conf.fmval_value1 >= conf.fmval_value2) {
                    statVal = conf.fmval_value1;
                }
                else {
                    statVal = (rand() % (conf.fmval_value2 - conf.fmval_value1 + 1)) + conf.fmval_value1;
                }
                statVal = statVal * (stat_conf.value / 100.0);
            }
            else {
                ItemTemplate const* pProto = pItem->GetTemplate();
                uint32 itemLevel = pItem->GetItemLevel(player);
                if (pProto && itemLevel)
                {
                    uint32 value11 = abs(conf.fmval_value1);
                    uint32 value22 = abs(conf.fmval_value2);

                    uint32 value1 = itemLevel * (value11 / 100);
                    uint32 value2 = itemLevel * (value22 / 100);
                    uint32 value = (rand() % (value2 - value1 + 1)) + value1;
                    statVal = value;
                }
            }
            if (stat_conf.value < 0 && stat_conf.point < 0 && stat_conf.point <= stat_conf.value) {
                uint32 value1 = abs(stat_conf.value);
                uint32 value2 = abs(stat_conf.point);
                uint32 value = (rand() % (value2 - value1 + 1)) + value1;
                statVal = value;
            }
            types.push_back(stat_conf.id);
            values.push_back(statVal);
            last_count++;
            if (conf.fmval_only == 1) {
                eraseid.insert(*rit);
            }
        }
        ObjectGuid::LowType guidlow = pItem->GetGUIDLow();
        time_t timep;
        time(&timep); /*当前time_t类型UTC时间*/
        aaCenter.aa_character_instances[guidlow].update_time = timep;
        aaCenter.aa_character_instances[guidlow].isUpdate = true;
        std::string fmvalues = "";
        aaCenter.AA_VectorToString(fmvalues, types, values);
        aaCenter.aa_character_instances[guidlow].fm_value_count = last_count;
        aaCenter.aa_character_instances[guidlow].fm_values = fmvalues;
    }
    return true;
}

bool AACenter::M_NonsuchItemFmSpell(Player* player, Item* pItem, uint32 nonsuchId, int32 type)
{
    ItemTemplate const* pProto = pItem->GetTemplate();
    if (!pProto) return false;

    AA_Item_Nonsuch conf = aaCenter.aa_item_nonsuchs[nonsuchId];
    AA_Character_Instance a_conf = aaCenter.aa_character_instances[pItem->GetGUIDLow()];
    if (type == 0) { //重铸
        if (a_conf.chongzhu_count == 0) {
            aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000该物品无法重铸");
            return false;
        }
        ObjectGuid::LowType guidlow = pItem->GetGUID().GetCounter();
        AA_Character_Instance conf = aaCenter.aa_character_instances[guidlow];
        uint32 needid = conf.chongzhu_spell;
        if (needid > 0) {
            if (aaCenter.M_CanNeed(player, needid)) {
                aaCenter.M_Need(player, needid);
            }
            else {
                return false;
            }
        }
        // 消耗重铸次数
        aaCenter.aa_character_instances[pItem->GetGUIDLow()].chongzhu_count -= 1;
    }
    //1、覆盖技能
    std::vector<int32> values; values.clear();
    uint32 last_count = 0;
    if (conf.fmspell_count1 > 0 || conf.fmspell_count2 > 0) {
        std::vector<uint32> confids; confids.clear();
        std::vector<int32> fmspell_spellzus; fmspell_spellzus.clear();
        aaCenter.AA_StringToVectorInt(conf.fmspell_spellzu, fmspell_spellzus, ",");
        bool isOneSpellInZu = conf.fmspell_count1 == conf.fmspell_count2 && conf.fmspell_only == 1 && conf.fmspell_count1 == fmspell_spellzus.size();
        if (isOneSpellInZu) {
            //if (conf.fmspell_only == 1 && fmspell_count == confidsCount && fmspell_count == fmspell_zuCount) {//当不重复附魔时，附魔数量等于附魔技能数组时，直接排序
            //    sort(values.begin(), values.end());
            //}
            uint32 fmspell_count = conf.fmspell_count1;
            for (auto fmspell_spellzu : fmspell_spellzus) {
                std::vector<uint32> confids1 = aaCenter.aa_spell_zus[fmspell_spellzu];
                std::vector<uint32> tmp_confids; tmp_confids.clear();
                for (auto it : confids1) {
                    AA_Spell conf = aaCenter.aa_spells[it];
                    if (conf.class1 != "-1") {
                        std::vector<int32> spells; spells.clear();
                        aaCenter.AA_StringToVectorInt(conf.class1, spells, ",");
                        if (std::find(spells.begin(), spells.end(), pProto->GetClass()) == spells.end())
                        {
                            continue;
                        }
                    }
                    if (conf.subclass != "-1") {
                        std::vector<int32> spells; spells.clear();
                        aaCenter.AA_StringToVectorInt(conf.subclass, spells, ",");
                        if (std::find(spells.begin(), spells.end(), pProto->GetSubClass()) == spells.end())
                        {
                            continue;
                        }
                    }
                    if (conf.inventoryType != "-1") {
                        std::vector<int32> inventoryTypes; inventoryTypes.clear();
                        aaCenter.AA_StringToVectorInt(conf.inventoryType, inventoryTypes, ",");
                        if (std::find(inventoryTypes.begin(), inventoryTypes.end(), pProto->GetInventoryType()) == inventoryTypes.end())
                        {
                            continue;
                        }
                    }
                    tmp_confids.push_back(it);
                }
                if (tmp_confids.size() == 0) {
                    break;
                }
                //获取总chance，分母
                uint32 chanceMax = 0;
                for (auto it = tmp_confids.begin(); it != tmp_confids.end(); it++)
                {
                    AA_Spell conf = aaCenter.aa_spells[*it];
                    chanceMax += conf.chance;
                }
                if (chanceMax == 0) { chanceMax = 1; }
                //获取随机chance，分子
                uint32 chanceVal = rand() % chanceMax; uint32 max = 0; uint32 min = 0;
                std::vector<uint32>::iterator rit;
                for (auto it = tmp_confids.begin(); it != tmp_confids.end(); it++)
                {
                    AA_Spell conf = aaCenter.aa_spells[*it];
                    max = conf.chance + max; min = 0;
                    if (it == tmp_confids.begin()) { min = 0; }
                    else {
                        AA_Spell conf = aaCenter.aa_spells[*it - 1];
                        min = conf.chance + min;
                    }
                    if (min <= chanceVal && chanceVal < max) { rit = it; break; }
                }
                values.push_back(*rit);
                last_count++;
            }
            sort(values.begin(), values.end());
        }
        else {
            for (auto fmspell_spellzu : fmspell_spellzus) {
                std::vector<uint32> confids1 = aaCenter.aa_spell_zus[fmspell_spellzu];
                for (auto it : confids1) {
                    AA_Spell conf = aaCenter.aa_spells[it];
                    if (conf.class1 != "-1") {
                        std::vector<int32> spells; spells.clear();
                        aaCenter.AA_StringToVectorInt(conf.class1, spells, ",");
                        if (std::find(spells.begin(), spells.end(), pProto->GetClass()) == spells.end())
                        {
                            continue;
                        }
                    }
                    if (conf.subclass != "-1") {
                        std::vector<int32> spells; spells.clear();
                        aaCenter.AA_StringToVectorInt(conf.subclass, spells, ",");
                        if (std::find(spells.begin(), spells.end(), pProto->GetSubClass()) == spells.end())
                        {
                            continue;
                        }
                    }
                    if (conf.inventoryType != "-1") {
                        std::vector<int32> inventoryTypes; inventoryTypes.clear();
                        aaCenter.AA_StringToVectorInt(conf.inventoryType, inventoryTypes, ",");
                        if (std::find(inventoryTypes.begin(), inventoryTypes.end(), pProto->GetInventoryType()) == inventoryTypes.end())
                        {
                            continue;
                        }
                    }
                    confids.push_back(it);
                }
            }
            uint32 fmspell_count = 0;
            if (conf.fmspell_count1 >= conf.fmspell_count2) {
                fmspell_count = conf.fmspell_count1;
            }
            else {
                fmspell_count = (rand() % (conf.fmspell_count2 - conf.fmspell_count1 + 1)) + conf.fmspell_count1;
            }
            std::set<uint32> eraseid; eraseid.clear();
            for (uint32 i = 0; i < fmspell_count; i++) {
                for (auto it = confids.begin(); it != confids.end();)
                {
                    if (std::find(eraseid.begin(), eraseid.end(), *it) != eraseid.end()) {
                        it = confids.erase(it);
                    }
                    else {
                        it++;
                    }
                }
                if (confids.size() == 0) { break; }
                //获取总chance，分母
                uint32 chanceMax = 0;
                for (auto it = confids.begin(); it != confids.end(); it++)
                {
                    AA_Spell conf = aaCenter.aa_spells[*it];
                    chanceMax += conf.chance;
                }
                if (chanceMax == 0) { chanceMax = 1; }
                //获取随机chance，分子
                uint32 chanceVal = rand() % chanceMax; uint32 max = 0; uint32 min = 0;
                std::vector<uint32>::iterator rit;
                for (auto it = confids.begin(); it != confids.end(); it++)
                {
                    AA_Spell conf = aaCenter.aa_spells[*it];
                    max = conf.chance + max; min = 0;
                    if (it == confids.begin()) { min = 0; }
                    else {
                        AA_Spell conf = aaCenter.aa_spells[*it - 1];
                        min = conf.chance + min;
                    }
                    if (min <= chanceVal && chanceVal < max) { rit = it; break; }
                }
                values.push_back(*rit);
                last_count++;
                if (conf.fmspell_only == 1) {
                    eraseid.insert(*rit);
                }
            }
        }
        ObjectGuid::LowType guidlow = pItem->GetGUIDLow();
        time_t timep;
        time(&timep); /*当前time_t类型UTC时间*/
        aaCenter.aa_character_instances[guidlow].update_time = timep;
        aaCenter.aa_character_instances[guidlow].isUpdate = true;
        std::string fmvalues = "";
        aaCenter.AA_VectorIntToString(fmvalues, values, ",");
        aaCenter.aa_character_instances[guidlow].fm_spell_count = last_count;
        aaCenter.aa_character_instances[guidlow].fm_spells = fmvalues;
    }
    return true;
}

void AACenter::M_UpgradeItem(Player* player, Item* pItem, uint32 qhjlevel)
{
    if (!player || !player->IsInWorld()) {
        return;
    }
    try {
        if (!pItem)
        {
            aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000物品不存在。"); return;
        }
        ItemTemplate const* pProto = pItem->GetTemplate();
        if (!pProto)
        {
            aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000物品不存在。"); return;
        }
        //        if (pItem->IsEquipped())
        //        {aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000请将物品放入背包再操作。"); return;}
        ObjectGuid::LowType guidlow = pItem->GetGUIDLow();
        AA_Character_Instance a_conf = aa_character_instances[guidlow];
        uint32 zu = a_conf.qh_zu;
        if (zu == 0)
        {
            aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000该物品无法强化"); return;
        }
        if (a_conf.fugai == "" || a_conf.fugai == "0")
        {
            aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000该物品无法强化"); return;
        }
        std::vector<int32> types; types.clear();
        std::vector<int32> values; values.clear();
        aaCenter.AA_StringToVector2(a_conf.fugai, types, values);
        if (values.size() == 0)
        {
            aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000该物品无法强化"); return;
        }
        std::vector<int32> upgrade_values; upgrade_values.clear();
        aaCenter.AA_StringToVectorInt(a_conf.qh_values, upgrade_values, ",");
        if (upgrade_values.size() == 0) {
            for (size_t i = 0; i < types.size(); i++) {
                upgrade_values.push_back(0);
            }
        }
        if (qhjlevel > 0) {
            //设置物品强化属性
            uint32 qhid = AA_SafeObjectAtIndex(aaCenter.aa_item_upgrade_zus[zu], qhjlevel - 1);
            AA_Item_Upgrade mconf = aaCenter.aa_item_upgrades[qhid];
            if (mconf.level == 0)
            {
                aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000该物品无法强化"); return;
            }
            for (uint32 i = 1; i <= qhjlevel; i++) {
                uint32 qhid = AA_SafeObjectAtIndex(aaCenter.aa_item_upgrade_zus[zu], i - 1);
                AA_Item_Upgrade conf = aaCenter.aa_item_upgrades[qhid];
                //增加百分比
                if (conf.percent1 > 0 || conf.percent2 > 0) {
                    if (conf.percent1 >= conf.percent2) {
                        for (uint32 i = 0; i < upgrade_values.size(); i++) {
                            uint32 fg_typeid = types[i];
                            uint32 fg_type = aaCenter.aa_stats[fg_typeid].type;
                            uint32 qh_typeid = aaCenter.aa_stat_types[conf.stat_group][fg_type];
                            AA_Stat aconf = aaCenter.aa_stats[qh_typeid];
                            upgrade_values[i] = upgrade_values[i] + values[i] * (conf.percent1 / 100.0) * (aconf.point / 100.0);
                        }
                    }
                    else {
                        if (conf.distribution == 0) {
                            uint32 val = (rand() % (conf.percent2 - conf.percent1 + 1)) + conf.percent1;
                            for (uint32 i = 0; i < upgrade_values.size(); i++) {
                                uint32 fg_typeid = types[i];
                                uint32 fg_type = aaCenter.aa_stats[fg_typeid].type;
                                uint32 qh_typeid = aaCenter.aa_stat_types[conf.stat_group][fg_type];
                                AA_Stat aconf = aaCenter.aa_stats[qh_typeid];
                                upgrade_values[i] = upgrade_values[i] + values[i] * (val / 100.0) * (aconf.point / 100.0);
                            }
                        }
                        else if (conf.distribution == 1) {
                            for (uint32 i = 0; i < upgrade_values.size(); i++) {
                                uint32 fg_typeid = types[i];
                                uint32 fg_type = aaCenter.aa_stats[fg_typeid].type;
                                uint32 qh_typeid = aaCenter.aa_stat_types[conf.stat_group][fg_type];
                                AA_Stat aconf = aaCenter.aa_stats[qh_typeid];
                                uint32 val = (rand() % (conf.percent2 - conf.percent1 + 1)) + conf.percent1;
                                upgrade_values[i] = upgrade_values[i] + values[i] * (val / 100.0) * (aconf.point / 100.0);
                            }
                        }
                    }
                }
                //增加数值
                if (conf.value1 > 0 || conf.value2 > 0)
                {
                    if (conf.value1 >= conf.value2) {
                        for (uint32 i = 0; i < upgrade_values.size(); i++) {
                            uint32 type = types[i];
                            AA_Stat aconf = aaCenter.aa_stats[type];
                            upgrade_values[i] += conf.value1 * (aconf.value / 100.0);
                        }
                    }
                    else {
                        uint32 val = 0;
                        if (conf.distribution == 0) {
                            val = (rand() % (conf.value2 - conf.value1 + 1)) + conf.value1;
                            for (uint32 i = 0; i < upgrade_values.size(); i++) {
                                uint32 fg_typeid = types[i];
                                uint32 fg_type = aaCenter.aa_stats[fg_typeid].type;
                                uint32 qh_typeid = aaCenter.aa_stat_types[conf.stat_group][fg_type];
                                AA_Stat aconf = aaCenter.aa_stats[qh_typeid];
                                upgrade_values[i] += val * (aconf.value / 100.0);
                            }
                        }
                        else if (conf.distribution == 1) {
                            for (uint32 i = 0; i < upgrade_values.size(); i++) {
                                uint32 fg_typeid = types[i];
                                uint32 fg_type = aaCenter.aa_stats[fg_typeid].type;
                                uint32 qh_typeid = aaCenter.aa_stat_types[conf.stat_group][fg_type];
                                AA_Stat aconf = aaCenter.aa_stats[qh_typeid];
                                val = (rand() % (conf.value2 - conf.value1 + 1)) + conf.value1;
                                upgrade_values[i] += val * (aconf.value / 100.0);
                            }
                        }
                    }
                }
            }
            //装备强化技能
            aaCenter.aa_character_instances[guidlow].qh_id = mconf.id;
            aaCenter.aa_character_instances[guidlow].qh_level = mconf.level;
            aaCenter.aa_character_instances[guidlow].qh_reward_value = mconf.reward_value;
            aaCenter.aa_character_instances[guidlow].qh_reward_point = mconf.reward_percent;
            aaCenter.aa_character_instances[guidlow].qh_reward_spell = mconf.upgrade_spell;
            std::string qh_values = "";
            aaCenter.AA_VectorIntToString(qh_values, upgrade_values, ",");
            aaCenter.aa_character_instances[guidlow].qh_values = qh_values;
        }
        else {
            //设置物品强化属性
            uint32 upgradeid = aaCenter.aa_character_instances[guidlow].qh_id;
            AA_Item_Upgrade oldconf = aaCenter.aa_item_upgrades[upgradeid];
            uint32 level = oldconf.level < 0 ? 0 : oldconf.level;
            uint32 confid = AA_SafeObjectAtIndex(aaCenter.aa_item_upgrade_zus[zu], level);
            AA_Item_Upgrade conf = aaCenter.aa_item_upgrades[confid];
            if (conf.distribution != 0 && conf.distribution != 1)
            {
                aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000系统错误qh002"); return;
            }
            if (conf.zu != oldconf.zu && oldconf.level > 0)
            {
                aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000已达到最大等级"); return;
            }
            if (conf.need > 0) {
                if (aaCenter.M_CanNeed(player, conf.need)) {
                    aaCenter.M_Need(player, conf.need);
                }
                else { return; }
            }
            uint32 accountid = player->GetSession()->GetAccountId();
            AA_Account aconf = aaCenter.aa_accounts[accountid];
            AA_Vip_Conf vconf = aaCenter.aa_vip_confs[aconf.vip];
            float chance = conf.chance + vconf.qianghua;
            if (aaCenter.AA_FindMapValueUint32(player->aa_fm_values, 405)) {
                chance += aaCenter.AA_FindMapValueUint32(player->aa_fm_values, 405);
            }
            if (!roll_chance_f(chance)) {
                if (conf.notice > 0) {
                    AA_Message aa_message;
                    aa_message.use_item = pItem;
                    AA_Notice notice = aaCenter.aa_notices[conf.notice];
                    aaCenter.AA_SendNotice(player, notice, false, aa_message);
                }
                if (conf.destroy == 0) {
                    aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000强化失败"); return;
                }
                else if (conf.destroy == 1) { //等级清0
                    aaCenter.M_CleanUpgradeItem(pItem);
                    aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000强化失败"); return;
                }
                else if (conf.destroy == 2) { //物品消失
                    uint32 item = aaCenter.aa_world_confs[21].value1;
                    uint32 count = 1;
                    if (!aaCenter.AA_HasItemInBagCount(player, item, count)) {
                        player->DestroyItemCount(pItem, count, true);
                        aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000强化失败,装备被摧毁"); return;
                    }
                    else {
                        aaCenter.M_CleanUpgradeItem(pItem);
                        aaCenter.AA_DestroyItemInBagCount(player, item, count, true, false);
                        aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000强化失败,保护生效"); return;
                    }
                }
            }
            else
            {
                aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFFFF00强化成功");
            }
            //增加百分比
            if (conf.percent1 > 0 || conf.percent2 > 0) {
                if (conf.percent1 >= conf.percent2) {
                    for (uint32 i = 0; i < upgrade_values.size(); i++) {
                        uint32 fg_typeid = types[i];
                        uint32 fg_type = aaCenter.aa_stats[fg_typeid].type;
                        uint32 qh_typeid = aaCenter.aa_stat_types[conf.stat_group][fg_type];
                        AA_Stat aconf = aaCenter.aa_stats[qh_typeid];
                        upgrade_values[i] = upgrade_values[i] + values[i] * (conf.percent1 / 100.0) * (aconf.point / 100.0);
                    }
                }
                else {
                    if (conf.distribution == 0) {
                        uint32 val = (rand() % (conf.percent2 - conf.percent1 + 1)) + conf.percent1;
                        for (uint32 i = 0; i < upgrade_values.size(); i++) {
                            uint32 fg_typeid = types[i];
                            uint32 fg_type = aaCenter.aa_stats[fg_typeid].type;
                            uint32 qh_typeid = aaCenter.aa_stat_types[conf.stat_group][fg_type];
                            AA_Stat aconf = aaCenter.aa_stats[qh_typeid];
                            upgrade_values[i] = upgrade_values[i] + values[i] * (val / 100.0) * (aconf.point / 100.0);
                        }
                    }
                    else if (conf.distribution == 1) {
                        for (uint32 i = 0; i < upgrade_values.size(); i++) {
                            uint32 fg_typeid = types[i];
                            uint32 fg_type = aaCenter.aa_stats[fg_typeid].type;
                            uint32 qh_typeid = aaCenter.aa_stat_types[conf.stat_group][fg_type];
                            AA_Stat aconf = aaCenter.aa_stats[qh_typeid];
                            uint32 val = (rand() % (conf.percent2 - conf.percent1 + 1)) + conf.percent1;
                            upgrade_values[i] = upgrade_values[i] + values[i] * (val / 100.0) * (aconf.point / 100.0);
                        }
                    }
                }
            }
            //增加数值
            if (conf.value1 > 0 || conf.value2 > 0)
            {
                if (conf.value1 >= conf.value2) {
                    for (uint32 i = 0; i < upgrade_values.size(); i++) {
                        uint32 fg_typeid = types[i];
                        uint32 fg_type = aaCenter.aa_stats[fg_typeid].type;
                        uint32 qh_typeid = aaCenter.aa_stat_types[conf.stat_group][fg_type];
                        AA_Stat aconf = aaCenter.aa_stats[qh_typeid];
                        upgrade_values[i] += conf.value1 * (aconf.value / 100.0);
                    }
                }
                else {
                    uint32 val = 0;
                    if (conf.distribution == 0) {
                        val = (rand() % (conf.value2 - conf.value1 + 1)) + conf.value1;
                        for (uint32 i = 0; i < upgrade_values.size(); i++) {
                            uint32 fg_typeid = types[i];
                            uint32 fg_type = aaCenter.aa_stats[fg_typeid].type;
                            uint32 qh_typeid = aaCenter.aa_stat_types[conf.stat_group][fg_type];
                            AA_Stat aconf = aaCenter.aa_stats[qh_typeid];
                            upgrade_values[i] += val * (aconf.value / 100.0);
                        }
                    }
                    else if (conf.distribution == 1) {
                        for (uint32 i = 0; i < upgrade_values.size(); i++) {
                            uint32 fg_typeid = types[i];
                            uint32 fg_type = aaCenter.aa_stats[fg_typeid].type;
                            uint32 qh_typeid = aaCenter.aa_stat_types[conf.stat_group][fg_type];
                            AA_Stat aconf = aaCenter.aa_stats[qh_typeid];
                            val = (rand() % (conf.value2 - conf.value1 + 1)) + conf.value1;
                            upgrade_values[i] += val * (aconf.value / 100.0);
                        }
                    }
                }
            }
            //装备强化技能
            aaCenter.aa_character_instances[guidlow].qh_id = conf.id;
            aaCenter.aa_character_instances[guidlow].qh_level = conf.level;
            aaCenter.aa_character_instances[guidlow].qh_reward_value = conf.reward_value;
            aaCenter.aa_character_instances[guidlow].qh_reward_point = conf.reward_percent;
            aaCenter.aa_character_instances[guidlow].qh_reward_spell = conf.upgrade_spell;
            std::string qh_values = "";
            aaCenter.AA_VectorIntToString(qh_values, upgrade_values, ",");
            aaCenter.aa_character_instances[guidlow].qh_values = qh_values;
            if (conf.notice > 0) {
                AA_Message aa_message;
                aa_message.use_item = pItem;
                AA_Notice notice = aaCenter.aa_notices[conf.notice];
                aaCenter.AA_SendNotice(player, notice, true, aa_message);
            }
        }
        time_t timep;
        time(&timep); /*当前time_t类型UTC时间*/
        aaCenter.aa_character_instances[guidlow].update_time = timep;
        aaCenter.aa_character_instances[guidlow].isUpdate = true;
    }
    catch (std::exception const& e)
    {
        aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000异常错误qh001");
    }
}

void AACenter::M_CleanUpgradeItem(Item* pItem)
{
    if (!pItem || !pItem->IsInWorld()) { return; }
    time_t timep;
    time(&timep); /*当前time_t类型UTC时间*/
    ObjectGuid::LowType guidlow = pItem->GetGUIDLow();
    aaCenter.aa_character_instances[guidlow].qh_id = 0;
    aaCenter.aa_character_instances[guidlow].qh_level = 0;
    aaCenter.aa_character_instances[guidlow].qh_values = "";
    aaCenter.aa_character_instances[guidlow].qh_reward_spell = "";
    aaCenter.aa_character_instances[guidlow].qh_reward_point = 0;
    aaCenter.aa_character_instances[guidlow].qh_reward_value = 0;
    aaCenter.aa_character_instances[guidlow].update_time = timep;
    aaCenter.aa_character_instances[guidlow].isUpdate = true;
}

//物品成长
bool AACenter::GiveCZXP(Player* player, uint32 xp, Item* pItem)
{
    std::set<Item*> items; items.clear();
    if (pItem == nullptr) {
        items = aaCenter.M_GetEquipItems(player);
    }
    else {
        if (!pItem || !pItem->IsInWorld()) {
            return false;
        }
        items.insert(pItem);
    }
    for (auto item : items) {
        if (item) {
            if (!item || !item->IsInWorld()) {
                continue;
            }
            ObjectGuid::LowType guidlow = item->GetGUIDLow();
            uint32 zu = aaCenter.aa_character_instances[guidlow].cz_zu;
            if (zu == 0) {
                continue;
            }
            aaCenter.aa_character_instances[guidlow].cz_exp += xp;
            AA_Item_Level conf_n;
            uint32 level = aaCenter.aa_character_instances[guidlow].cz_level;
            do {
                level++;
                std::vector<uint32> confids = aaCenter.aa_item_level_zus[zu];
                if (confids.size() >= level) {
                    int32 confid = confids[level - 1];
                    if (confid == 0) {
                        continue;
                    }
                    conf_n = aaCenter.aa_item_levels[confid];
                    if (conf_n.level > 0 && aaCenter.aa_character_instances[guidlow].cz_exp >= conf_n.exp) {
                        aaCenter.M_LevelItem(player, item);
                        aaCenter.aa_character_instances[guidlow].cz_exp -= conf_n.exp;
                    }
                    else {
                        break;
                    }
                }
                else {
                    break;
                }

            } while (aa_item_level_zus[zu].size() >= level);
            time_t timep;
            time(&timep);
            aaCenter.aa_character_instances[guidlow].update_time = timep;
            aaCenter.aa_character_instances[guidlow].isUpdate = true;
        }
    }
    return true;
}

void AACenter::M_LevelItem(Player* player, Item* pItem)
{
    try {
        if (!pItem || !pItem->IsInWorld())
        {
            aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000物品不存在。"); return;
        }
        ObjectGuid::LowType guidlow = pItem->GetGUIDLow();
        AA_Character_Instance a_conf = aa_character_instances[guidlow];
        uint32 zu = a_conf.cz_zu;
        if (zu == 0) { return; }
        if (a_conf.fugai == "" || a_conf.fugai == "0") { return; }
        std::vector<int32> types; types.clear();
        std::vector<int32> values; values.clear();
        aaCenter.AA_StringToVector2(a_conf.fugai, types, values);
        if (values.size() == 0) { return; }
        std::vector<int32> upgrade_values; upgrade_values.clear();
        aaCenter.AA_StringToVectorInt(a_conf.cz_values, upgrade_values, ",");
        if (upgrade_values.size() == 0) {
            for (size_t i = 0; i < types.size(); i++) {
                upgrade_values.push_back(0);
            }
        }
        //设置物品强化属性
        uint32 upgradeid = aaCenter.aa_character_instances[guidlow].cz_id;
        AA_Item_Level oldconf = aaCenter.aa_item_levels[upgradeid];
        uint32 level = oldconf.level < 0 ? 0 : oldconf.level;

        uint32 confid = AA_SafeObjectAtIndex(aaCenter.aa_item_level_zus[zu], level);
        AA_Item_Level conf = aaCenter.aa_item_levels[confid];
        if (conf.distribution != 0 && conf.distribution != 1)
        {
            aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000系统错误qh002"); return;
        }
        if (conf.zu != oldconf.zu && oldconf.level > 0) { return; }
        //增加百分比
        if (conf.percent1 > 0 || conf.percent2 > 0) {
            if (conf.percent1 >= conf.percent2) {
                for (uint32 i = 0; i < upgrade_values.size(); i++) {
                    uint32 fg_typeid = types[i];
                    uint32 fg_type = aaCenter.aa_stats[fg_typeid].type;
                    uint32 qh_typeid = aaCenter.aa_stat_types[conf.stat_group][fg_type];
                    AA_Stat aconf = aaCenter.aa_stats[qh_typeid];
                    upgrade_values[i] = upgrade_values[i] + values[i] * (conf.percent1 / 100.0) * (aconf.point / 100.0);
                }
            }
            else {
                if (conf.distribution == 0) {
                    uint32 val = (rand() % (conf.percent2 - conf.percent1 + 1)) + conf.percent1;
                    for (uint32 i = 0; i < upgrade_values.size(); i++) {
                        uint32 fg_typeid = types[i];
                        uint32 fg_type = aaCenter.aa_stats[fg_typeid].type;
                        uint32 qh_typeid = aaCenter.aa_stat_types[conf.stat_group][fg_type];
                        AA_Stat aconf = aaCenter.aa_stats[qh_typeid];
                        upgrade_values[i] = upgrade_values[i] + values[i] * (val / 100.0) * (aconf.point / 100.0);
                    }
                }
                else if (conf.distribution == 1) {
                    for (uint32 i = 0; i < upgrade_values.size(); i++) {
                        uint32 fg_typeid = types[i];
                        uint32 fg_type = aaCenter.aa_stats[fg_typeid].type;
                        uint32 qh_typeid = aaCenter.aa_stat_types[conf.stat_group][fg_type];
                        AA_Stat aconf = aaCenter.aa_stats[qh_typeid];
                        uint32 val = (rand() % (conf.percent2 - conf.percent1 + 1)) + conf.percent1;
                        upgrade_values[i] = upgrade_values[i] + values[i] * (val / 100.0) * (aconf.point / 100.0);
                    }
                }
            }
        }
        //增加数值
        if (conf.value1 > 0 || conf.value2 > 0)
        {
            if (conf.value1 >= conf.value2) {
                for (uint32 i = 0; i < upgrade_values.size(); i++) {
                    uint32 fg_typeid = types[i];
                    uint32 fg_type = aaCenter.aa_stats[fg_typeid].type;
                    uint32 qh_typeid = aaCenter.aa_stat_types[conf.stat_group][fg_type];
                    AA_Stat aconf = aaCenter.aa_stats[qh_typeid];
                    upgrade_values[i] += conf.value1 * (aconf.value / 100.0);
                }
            }
            else {
                uint32 val = 0;
                if (conf.distribution == 0) {
                    val = (rand() % (conf.value2 - conf.value1 + 1)) + conf.value1;
                    for (uint32 i = 0; i < upgrade_values.size(); i++) {
                        uint32 fg_typeid = types[i];
                        uint32 fg_type = aaCenter.aa_stats[fg_typeid].type;
                        uint32 qh_typeid = aaCenter.aa_stat_types[conf.stat_group][fg_type];
                        AA_Stat aconf = aaCenter.aa_stats[qh_typeid];
                        upgrade_values[i] += val * (aconf.value / 100.0);
                    }
                }
                else if (conf.distribution == 1) {
                    for (uint32 i = 0; i < upgrade_values.size(); i++) {
                        uint32 fg_typeid = types[i];
                        uint32 fg_type = aaCenter.aa_stats[fg_typeid].type;
                        uint32 qh_typeid = aaCenter.aa_stat_types[conf.stat_group][fg_type];
                        AA_Stat aconf = aaCenter.aa_stats[qh_typeid];
                        val = (rand() % (conf.value2 - conf.value1 + 1)) + conf.value1;
                        upgrade_values[i] += val * (aconf.value / 100.0);
                    }
                }
            }
        }
        if (pItem->IsEquipped()) {
            player->_ApplyItemMods(pItem, pItem->GetSlot(), false);
        }
        //装备强化技能
        time_t timep;
        time(&timep); /*当前time_t类型UTC时间*/
        aaCenter.aa_character_instances[guidlow].update_time = timep;
        aaCenter.aa_character_instances[guidlow].isUpdate = true;
        aaCenter.aa_character_instances[guidlow].cz_id = conf.id;
        aaCenter.aa_character_instances[guidlow].cz_level = conf.level;
        aaCenter.aa_character_instances[guidlow].cz_reward_value = conf.reward_value;
        aaCenter.aa_character_instances[guidlow].cz_reward_point = conf.reward_percent;
        aaCenter.aa_character_instances[guidlow].cz_reward_spell = conf.spell;
        std::string qh_values = "";
        aaCenter.AA_VectorIntToString(qh_values, upgrade_values, ",");
        aaCenter.aa_character_instances[guidlow].cz_values = qh_values;
        if (pItem->IsEquipped()) {
            player->_ApplyItemMods(pItem, pItem->GetSlot(), true);
        }
        if (conf.notice > 0) {
            AA_Message aa_message;
            aa_message.use_item = pItem;
            AA_Notice notice = aaCenter.aa_notices[conf.notice];
            aaCenter.AA_SendNotice(player, notice, true, aa_message);
        }
    }
    catch (std::exception const& e)
    {
        aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000异常错误qh001");
    }
}

//符文开槽
void AACenter::M_FuWenKaichao(Player* player, Item* pItem, uint32 count)
{
    if (!pItem || !pItem->IsInWorld()) { return; }
    if (pItem->IsEquipped())
    {
        aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000请将物品放入背包再操作。"); return;
    }
    //符文功能是否开启
    if (aaCenter.aa_world_confs[39].value1 == 0) {
        return;
    }
    AA_Character_Instance c_conf = aaCenter.aa_character_instances[pItem->GetGUIDLow()];
    if (c_conf.fw_count + count > 9) {
        aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000最多只能开启9个凹槽。"); return;
    }

    if (aaCenter.aa_world_confs[41].value2 != "" && aaCenter.aa_world_confs[41].value2 != "0") {
        uint32 index = c_conf.fw_count + count - 1;
        std::vector<int32> needs; needs.clear();
        aaCenter.AA_StringToVectorInt(aaCenter.aa_world_confs[41].value2, needs, ",");
        uint32 need = AA_SafeObjectAtIndex(needs, index);
        if (need > 0) {
            if (aaCenter.M_CanNeed(player, need)) {
                aaCenter.M_Need(player, need);
            }
            else {
                return;
            }
        }
    }

    c_conf.fw_count += count;
    aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFFFF00成功增加凹槽");
    time_t timep;
    time(&timep); /*当前time_t类型UTC时间*/
    c_conf.update_time = timep;
    c_conf.isUpdate = true;
    ObjectGuid::LowType guidlow = pItem->GetGUIDLow();
    aaCenter.aa_character_instances[guidlow] = c_conf;
}
//符文拆卸,符文清理
void AACenter::M_FuWenChaixie(Player* player, Item* pItem, uint32 index, bool clear)
{
    if (!pItem || !pItem->IsInWorld() || index > 8) { return; }
    if (pItem->IsEquipped())
    {
        aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000请将物品放入背包再操作。"); return;
    }
    //符文功能是否开启
    if (aaCenter.aa_world_confs[39].value1 == 0) {
        return;
    }
    AA_Character_Instance c_conf = aaCenter.aa_character_instances[pItem->GetGUIDLow()];
    std::vector<int32> fw_ids; fw_ids.clear();
    aaCenter.AA_StringToVectorInt(c_conf.fw_values, fw_ids, ",");
    if (clear) {
        bool isOk = false;
        for (size_t i = 0; i < fw_ids.size(); i++) {
            if (fw_ids[i] > 0) {
                isOk = true;
            }
        }
        if (!isOk) {
            aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000没有可拆卸的符文。");
            return;
        }
    }
    else {
        if (fw_ids.size() > index && fw_ids[index] == 0) {
            aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000没有可拆卸的符文。");
            return;
        }
    }
    if (clear) {
        for (size_t i = 0; i < fw_ids.size(); i++) {
            player->AddItem(fw_ids[i], 1);
            fw_ids[i] = 0;
        }
    }
    else {
        if (aaCenter.M_CanNeed(player, aaCenter.aa_world_confs[40].value1)) {
            aaCenter.M_Need(player, aaCenter.aa_world_confs[40].value1);
        }
        else {
            return;
        }
        if (fw_ids.size() > index) {
            player->AddItem(fw_ids[index], 1);
            fw_ids[index] = 0;
        }
    }
    aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFFFF00符文拆卸成功");
    std::string fw_values = "";
    aaCenter.AA_VectorIntToString(fw_values, fw_ids, ",");
    c_conf.fw_values = fw_values;
    std::string fwzhs = aaCenter.M_GetFuWenZuheSpell(pItem->GetTemplate(), c_conf);
    c_conf.fwzh_values = fwzhs;
    time_t timep;
    time(&timep); /*当前time_t类型UTC时间*/
    c_conf.update_time = timep;
    c_conf.isUpdate = true;
    ObjectGuid::LowType guidlow = pItem->GetGUIDLow();
    aaCenter.aa_character_instances[guidlow] = c_conf;
}
//符文镶嵌
void AACenter::M_FuWenXiangqian(Player* player, Item* pItem, std::vector<int32> fwItems, std::vector<int32> fwEntrys)
{
    //符文功能是否开启
    if (aaCenter.aa_world_confs[39].value1 == 0) { return; }
    if (fwItems.size() != fwEntrys.size()) { return; }
    AA_Character_Instance c_conf = aaCenter.aa_character_instances[pItem->GetGUIDLow()];
    std::vector<int32> fw_ids; fw_ids.clear();
    aaCenter.AA_StringToVectorInt(c_conf.fw_values, fw_ids, ",");
    if (fw_ids.size() != fwItems.size()) {
        size_t count = fwItems.size() - fw_ids.size();
        for (size_t i = 0; i < count; i++) {
            fw_ids.push_back(0);
        }
    }
    if (!pItem || !pItem->IsInWorld() || c_conf.fw_count == 0 || fwItems.size() == 0 || fwItems.size() > 9) { return; }
    if (pItem->IsEquipped())
    {
        aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000请将物品放入背包再操作。"); return;
    }
    for (size_t i = 0; i < fwItems.size(); i++) {
        int32 fw_id = fwItems[i];
        int32 fw_entry = fwEntrys[i];
        if (fw_id > 0) {
            if (fw_ids[i] > 0 && fw_id != fw_ids[i]) { // 有符文
                aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000凹槽已经装备符文"); return;
            }
            if (i > (c_conf.fw_count - 1)) {
                aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000凹槽未开启"); return;
            }
            //问题代码
            ObjectGuid::LowType guidlow = aaCenter.AA_GetRealItemGuid(fw_id, fw_entry);
            Item* fwItem = aaCenter.GetItemByGUIDLow(player, guidlow);
            if (!fwItem) {
                return;
            }
        }
    }
    bool isOk = false;
    for (size_t i = 0; i < fwItems.size(); i++) {
        uint32 fw_id = fwItems[i];
        uint32 fw_entry = fwEntrys[i];
        if (fw_id > 0) {
            //问题代码
            ObjectGuid::LowType guidlow = aaCenter.AA_GetRealItemGuid(fw_id, fw_entry);
            Item* fwItem = aaCenter.GetItemByGUIDLow(player, guidlow);
            if (fwItem && fwItem->IsInWorld()) {
                uint32 entry = fwItem->GetEntry();
                if (entry <= 0) {
                    continue;
                }
                ItemTemplate const* pProto = sObjectMgr->GetItemTemplate(entry);
                if (!pProto) {
                    continue;
                }
                AA_Fw_Conf conf = aaCenter.aa_fw_confs[entry];
                if (conf.itemid <= 0) {
                    continue;
                }
                if (conf.class1 != "-1") {
                    std::vector<int32> spells; spells.clear();
                    aaCenter.AA_StringToVectorInt(conf.class1, spells, ",");
                    if (std::find(spells.begin(), spells.end(), pProto->GetClass()) == spells.end())
                    {
                        continue;
                    }
                }
                if (conf.subclass != "-1") {
                    std::vector<int32> spells; spells.clear();
                    aaCenter.AA_StringToVectorInt(conf.subclass, spells, ",");
                    if (std::find(spells.begin(), spells.end(), pProto->GetSubClass()) == spells.end())
                    {
                        continue;
                    }
                }
                if (conf.inventoryType != "-1") {
                    std::vector<int32> inventoryTypes; inventoryTypes.clear();
                    aaCenter.AA_StringToVectorInt(conf.inventoryType, inventoryTypes, ",");
                    if (std::find(inventoryTypes.begin(), inventoryTypes.end(), pProto->GetInventoryType()) == inventoryTypes.end())
                    {
                        continue;
                    }
                }
                fw_ids[i] = entry;
                uint32 count = 1;
                player->DestroyItemCount(fwItem, count, true);
                isOk = true;
            }
        }
    }
    if (isOk) {
        aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFFFF00符文镶嵌成功");
        std::string fw_values = "";
        aaCenter.AA_VectorIntToString(fw_values, fw_ids, ",");
        c_conf.fw_values = fw_values;
        ItemTemplate const* pProto = pItem->GetTemplate();
        std::string fwzhs = aaCenter.M_GetFuWenZuheSpell(pProto, c_conf);
        c_conf.fwzh_values = fwzhs;
        time_t timep;
        time(&timep); /*当前time_t类型UTC时间*/
        c_conf.update_time = timep;
        c_conf.isUpdate = true;
        ObjectGuid::LowType guidlow = pItem->GetGUIDLow();
        aaCenter.aa_character_instances[guidlow] = c_conf;
    }
}
//获取符文组合技能id
std::string AACenter::M_GetFuWenZuheSpell(ItemTemplate const* pProto, AA_Character_Instance c_conf)
{
    if (c_conf.fw_count == 0) { return ""; }
    //符文功能是否开启
    if (aaCenter.aa_world_confs[39].value1 == 0) {
        return "";
    }
    std::vector<int32> fw_ids; fw_ids.clear();
    aaCenter.AA_StringToVectorInt(c_conf.fw_values, fw_ids, ",");
    std::string zuheids = "";
    for (auto& it : aaCenter.aa_fwzh_confs)
    {
        AA_FwZh_Conf conf = it.second;
        if (conf.class1 != "-1") {
            std::vector<int32> spells; spells.clear();
            aaCenter.AA_StringToVectorInt(conf.class1, spells, ",");
            if (std::find(spells.begin(), spells.end(), pProto->GetClass()) == spells.end())
            {
                continue;
            }
        }
        if (conf.subclass != "-1") {
            std::vector<int32> spells; spells.clear();
            aaCenter.AA_StringToVectorInt(conf.subclass, spells, ",");
            if (std::find(spells.begin(), spells.end(), pProto->GetSubClass()) == spells.end())
            {
                continue;
            }
        }
        if (conf.inventoryType != "-1") {
            std::vector<int32> inventoryTypes; inventoryTypes.clear();
            aaCenter.AA_StringToVectorInt(conf.inventoryType, inventoryTypes, ",");
            if (std::find(inventoryTypes.begin(), inventoryTypes.end(), pProto->GetInventoryType()) == inventoryTypes.end())
            {
                continue;
            }
        }

        bool isOk = false;
        std::vector<int32> itemids; itemids.clear();
        aaCenter.AA_StringToVectorInt(conf.items, itemids, ",");
        for (size_t j = 0; j < itemids.size(); j++) {
            uint32 zhitemid = itemids[j];
            if (zhitemid > 0) {
                //判断是否包含
                isOk = false;
                for (size_t c = 0; c < c_conf.fw_count; c++) {
                    uint32 itemid = fw_ids[c];
                    if (itemid == zhitemid) {
                        isOk = true;
                        break;
                    }
                }
                if (!isOk) {
                    break;
                }
            }
        }
        if (isOk) {
            zuheids = zuheids + std::to_string(conf.id);
            zuheids += ",";
        }
    }
    aaCenter.AA_StringReplaceLast(zuheids, ",", "");

    return zuheids;
}
bool AACenter::AA_IsFuwenItem(Item* pItem)
{
    ObjectGuid::LowType guidlow = pItem->GetGUIDLow();
    AA_Character_Instance iconf = aaCenter.aa_character_instances[guidlow];
    std::vector<int32> fw_ids; fw_ids.clear();
    aaCenter.AA_StringToVectorInt(iconf.fw_values, fw_ids, ",");
    if (iconf.fw_count == 0) {
        return false;
    }
    for (auto fw : fw_ids) {
        if (fw > 0) {
            return true;
        }
    }
    return false;
}
bool AACenter::AA_HasFwItem(Player* player, uint32 fwid)
{
    // 判断是不是符文
    AA_Fw_Conf conf = aaCenter.aa_fw_confs[fwid];
    if (conf.itemid == 0) {
        return false;
    }
    // 判断装备装备是否包含符文
    std::set<Item*> items = M_GetEquipItems(player);
    for (auto item : items) {
        ObjectGuid::LowType guidlow = item->GetGUIDLow();
        AA_Character_Instance iconf = aaCenter.aa_character_instances[guidlow];
        std::vector<int32> fw_ids; fw_ids.clear();
        aaCenter.AA_StringToVectorInt(iconf.fw_values, fw_ids, ",");
        if (iconf.fw_count == 0) {
            continue;
        }
        for (uint32 i = 0; i < fw_ids.size(); i++) {
            uint32 fw = fw_ids[i];
            if (fw == fwid) {
                return true;
            }
        }
    }
    return false;
}
/*拍卖行*/
std::string AACenter::AA_GetAuctionUnit()
{
    std::string danwei = "";
    if (aaCenter.aa_world_confs[60].value1 == 1) {
        danwei = aaCenter.aa_world_confs[62].value2;
    }
    else if (aaCenter.aa_world_confs[60].value1 == 2) {
        danwei = aaCenter.aa_world_confs[63].value2;
    }
    else if (aaCenter.aa_world_confs[60].value1 == 3) {
        danwei = aaCenter.aa_world_confs[64].value2;
    }
    else if (aaCenter.aa_world_confs[60].value1 == 4) {
        danwei = aaCenter.aa_world_confs[65].value2;
    }
    else {
        danwei = "铜币";
    }
    return danwei;
}
uint32 AACenter::AA_GetAuctionMoney(Player* player)
{
    if (!player || !player->IsInWorld()) {
        return 0;
    }
    uint32 accountid = player->GetSession()->GetAccountId();
    AA_Account conf = aaCenter.aa_accounts[accountid];
    if (aaCenter.aa_world_confs[60].value1 == 1) {
        return conf.paodian;
    }
    else if (aaCenter.aa_world_confs[60].value1 == 2) {
        return conf.mobi;
    }
    else if (aaCenter.aa_world_confs[60].value1 == 3) {
        return conf.jifen;
    }
    else if (aaCenter.aa_world_confs[60].value1 == 4) {
        return conf.battlecore;
    }
    else {
        return player->GetMoney();
    }
}

void AACenter::AA_AuctionModifyMoney(Player* player, int32 money)
{
    if (!player || !player->IsInWorld()) {
        return;
    }
    uint32 accountid = player->GetSession()->GetAccountId();
    AA_Account conf = aaCenter.aa_accounts[accountid];
    if (aaCenter.aa_world_confs[60].value1 == 1) {
        aaCenter.aa_accounts[accountid].paodian += money;
    }
    else if (aaCenter.aa_world_confs[60].value1 == 2) {
        aaCenter.aa_accounts[accountid].mobi += money;
    }
    else if (aaCenter.aa_world_confs[60].value1 == 3) {
        aaCenter.aa_accounts[accountid].jifen += money;
    }
    else if (aaCenter.aa_world_confs[60].value1 == 4) {
        aaCenter.aa_accounts[accountid].battlecore += money;
    }
    else {
        player->ModifyMoney(money);
    }
    time_t timep;
    time(&timep); /*当前time_t类型UTC时间*/
    aaCenter.aa_accounts[accountid].update_time = timep;
    aaCenter.aa_accounts[accountid].isUpdate = true;
}

/*宝石相关*/
bool AACenter::AA_HasBaoshi(Player* player, uint32 itemid)
{
    ItemTemplate const* pProto = sObjectMgr->GetItemTemplate(itemid);
    if (!pProto) {
        return false;
    }
    if (pProto->GetClass() != 3) {
        return false;
    }
    std::set<Item*> items = M_GetEquipItems(player);
    for (auto item : items) {
        for (int i = 0; i < 3; i++) {
            uint32 entry = AA_GetBaoshiEntry(item, i);
            if (entry == itemid) {
                return true;
            }
        }
    }
    return false;
}

void AACenter::M_ChangeItemName(Player* player, Item* pItem, std::string name)
{
    if (!pItem || !pItem->IsInWorld()) {
        aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000物品不存在。");
        return;
    }
    if (name.length() == 0 || name.length() > 36) {
        aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000输入名字过长");
        return;
    }
    uint32 needid = aaCenter.aa_world_confs[22].value1;
    if (needid > 0) {
        if (aaCenter.M_CanNeed(player, needid)) {
            aaCenter.M_Need(player, needid);
        }
        else {
            return;
        }
    }
    time_t timep;
    time(&timep); /*当前time_t类型UTC时间*/
    ObjectGuid::LowType guidlow = pItem->GetGUIDLow();
    aaCenter.aa_character_instances[guidlow].name = name;
    aaCenter.aa_character_instances[guidlow].update_time = timep;
    aaCenter.aa_character_instances[guidlow].isUpdate = true;
    aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFFFF00改名成功");
}

void AACenter::M_GetSpellText(Player* player, std::vector<uint32> spellIds, std::vector<uint32> spellTimes)
{
    try {
        std::string spells = "{";
        int count = spellIds.size();
        if (count == 0) { return; }
        int j = 0;
        for (int i = 0; i < count; i++) {
            uint32 spellid = spellIds[i];
            uint32 time1 = spellTimes[i];
            AA_Spell conf;
            QueryResult result = WorldDatabase.PQuery("SELECT id,客户端显示,update_time FROM _模板_物品技能 where id = {} and update_time != {} ORDER BY id", spellid, time1);
            if (result) {
                Field* fields = result->Fetch();
                conf.id = fields[0].GetUInt32();
                conf.text = fields[1].GetString();
                conf.update_time = fields[2].GetUInt32();
                if (conf.id > 0 && conf.text != "") {
                    std::string spell = "";
                    spell += "[";
                    spell += std::to_string(conf.id);
                    spell += "]={\"";
                    spell += conf.text;
                    spell += "\",";
                    spell += std::to_string(conf.update_time);
                    spell += "},";
                    spells += spell;
                }
            }
            if ((j > 10 || i == (count - 1)) && spells != "{") {
                spells += "}";
                aaCenter.AA_StringReplaceLast(spells, ",}", "}");
                aaCenter.M_SendClientAddonData(player, "11", spells);
                spells = "}";
                j = 0;
            }
        }
    }
    catch (std::exception const& e) {}
}

void AACenter::M_GetItemText(Player* player, std::vector<uint32> itemIds, std::vector<uint32> itemEntrys, std::vector<uint32> itemTimes)
{
    try {
        std::string items = "{";
        int count = itemIds.size(); int count1 = itemEntrys.size(); int count2 = itemTimes.size();
        if (count == 0 || count != count1 || count != count2) { return; }
        int j = 0;
        for (int i = 0; i < count; i++) {
            uint32 id = itemIds[i];
            ObjectGuid::LowType guid = aaCenter.AA_GetRealItemGuid(id, 0);
            AA_Character_Instance conf = aaCenter.aa_character_instances[guid];
            uint32 entry = conf.itemEntry;
            if (conf.guid == 0 || conf.itemEntry == 0) continue;
            uint32 time = conf.update_time;
            uint32 time1 = itemTimes[i];
            //            {[vendor]={[id]=need,[id]=need},[vendor]={[id]=need,[id]=need}}
            //            {[itemid]={},[itemid]={}}
            if (time != time1) {
                ItemTemplate const* pProto = sObjectMgr->GetItemTemplate(conf.itemEntry);
                std::string stat_count = "";
                if (pProto) {
                    uint32 count07 = 0;
                    uint32 count78 = 0;
                    uint32 statsCount = aaCenter.AA_GetItemValueCount(pProto->GetId());
                    stat_count = std::to_string(count07) + "," + std::to_string(count78);
                }
                std::string item = "[";
                item += std::to_string(conf.guid); item += "]={[";
                item += std::to_string(conf.itemEntry); item += "]={";
                item += std::to_string(id); item += ",";
                item += std::to_string(conf.itemEntry); item += ",";
                item += std::to_string(conf.owner_guid); item += ",\"";
                item += conf.name; item += "\",\"";
                item += conf.fugai; item += "\",";
                item += std::to_string(conf.jd_zu); item += ",";
                item += std::to_string(conf.jd_id); item += ",";
                item += std::to_string(conf.jd_level); item += ",\"";
                item += conf.jd_values; item += "\",";
                item += std::to_string(conf.qh_zu); item += ",";
                item += std::to_string(conf.qh_id); item += ",";
                item += std::to_string(conf.qh_level); item += ",\"";
                item += conf.qh_values; item += "\",";
                item += std::to_string(conf.qh_reward_value); item += ",";
                item += std::to_string(conf.qh_reward_point); item += ",\"";
                item += conf.qh_reward_spell; item += "\",";
                item += std::to_string(conf.cz_zu); item += ",";
                item += std::to_string(conf.cz_id); item += ",";
                item += std::to_string(conf.cz_level); item += ",";
                item += std::to_string(conf.cz_exp); item += ",\"";
                item += conf.cz_values; item += "\",";
                item += std::to_string(conf.cz_reward_value); item += ",";
                item += std::to_string(conf.cz_reward_point); item += ",\"";
                item += conf.cz_reward_spell; item += "\",";
                item += std::to_string(conf.fm_spell_count); item += ",\"";
                item += conf.fm_spells; item += "\",";
                item += std::to_string(conf.fm_value_count); item += ",\"";
                item += conf.fm_values; item += "\",";
                item += std::to_string(conf.chongzhu_count); item += ",";
                item += std::to_string(conf.chongzhu_value); item += ",";
                item += std::to_string(conf.chongzhu_spell); item += ",";
                item += std::to_string(conf.fw_count); item += ",\"";
                item += conf.fw_values; item += "\",\"";
                item += conf.fwzh_values; item += "\",\"";
                item += stat_count; item += "\",";
                item += std::to_string(conf.cuiqu_pos); item += ",";
                item += std::to_string(conf.baoshi_entry); item += ",";
                item += std::to_string(conf.item_set); item += ",";
                item += std::to_string(conf.update_time); item += "}";
                items += item;
                items += "},";
            }
            if ((j > 10 || i == (count - 1)) && items != "{") {
                items += "}";
                aaCenter.AA_StringReplaceLast(items, ",}", "}");
                aaCenter.M_SendClientAddonData(player, "12", items);
                items = "{";
                j = 0;
            }
        }
    }
    catch (std::exception const& e) {}
}

void AACenter::M_GetItemTextPet(Player* player, std::vector<uint32> itemIds, std::vector<uint32> itemEntrys, std::vector<uint32> itemTimes)
{
}

void AACenter::M_SendMap_Jindu(Player* player)
{
    if (Map* map = player->GetMap())
    {
        //死亡次数、总次数、剩余时间、当前进度、总进度、进度奖励
        //{}
        AA_Map_Player_Conf conf = aaCenter.AA_GetAA_Map_Player_Conf(player);
        uint32 dietime1 = conf.m_dietime;
        uint32 dietime2 = conf.dietime;
        uint32 xianzhitime = 0;
        uint32 xianzhitime2 = conf.xianzhitime * 1000;
        if (xianzhitime2 >= conf.m_xianzhitime) {
            xianzhitime = xianzhitime2 - conf.m_xianzhitime;
        }
        else {
            xianzhitime = 0;
        }
        uint32 jindu1 = conf.m_jindu_exp;

        std::map<int32, int32> rewards; rewards.clear();
        aaCenter.AA_StringToMap(conf.jindu_reward, rewards);
        uint32 jindu2 = 0;
        if (rewards.size() > 0) {
            auto iter = rewards.end();
            iter--;
            jindu2 = iter->first;
        }
        std::string jindu_reward = conf.jindu_reward;
        std::string msg = "{" + std::to_string(dietime1) + "," + std::to_string(dietime2) + "," + std::to_string(xianzhitime) + "," + std::to_string(jindu1) + "," + std::to_string(jindu2) + ",\"" + jindu_reward + "\"}";
        if (dietime2 > 0 || jindu2 > 0 || (jindu_reward != "" && jindu_reward != "0")) {
            aaCenter.M_SendClientAddonData(player, "1010", msg);
        }
        else {
            aaCenter.M_SendClientAddonData(player, "1010", "{}");
        }
    }
}

void AACenter::M_SendBoss_Paihang(std::list<Player*> list, Creature* creature, std::vector<std::pair<ObjectGuid, uint32>> aa_boss_dmg)
{
    try {
        if (!creature || !creature->IsAlive() || !creature->IsInWorld()) {
            return;
        }
        if (aa_boss_dmg.empty()) {
            return;
        }
        std::map<Player*, uint32> aa_boss_dmg_copy; aa_boss_dmg_copy.clear();
        for (auto itr : aa_boss_dmg) {
            if (Player* p = ObjectAccessor::FindPlayer(itr.first)) {
                if (p && p->IsInWorld()) {
                    aa_boss_dmg_copy[p] = itr.second;
                }
            }
        }

        //        std::map<Player *, uint32> aa_boss_dmg;
        //      排名=排名，class，姓名，伤害值，伤害百分比
        float health = (float)creature->GetMaxHealth();
        health = health > 0 ? health : 1.0;
        AA_Boss_Conf conf = aaCenter.aa_boss_confs[creature->aa_boss_id];
        std::string items1 = "{";
        uint32 i = 0;
        for (auto itr : aa_boss_dmg) {
            if (i > 9) {
                break;
            }
            Player* player = ObjectAccessor::FindPlayer(itr.first);
            if (!player || !player->IsInWorld()) {
                continue;
            }
            uint32 dmg = itr.second;
            std::string item = "[";
            item += std::to_string(i + 1); item += "]={";
            item += std::to_string(i + 1); item += ",";
            item += std::to_string(player->GetClass()); item += ",\"";
            item += player->GetName(); item += "\",";
            item += std::to_string(dmg); item += ",";
            item += AA_StringFromFloat(dmg / health * 100.0); item += "},";
            items1 += item;
            i++;
        }
        items1 += "}";
        aaCenter.AA_StringReplaceLast(items1, ",}", "}");

        for (Player* player : list) {
            if (!player || !player->IsInWorld()) {
                continue;
            }
            aaCenter.M_SendClientAddonData(player, "1008", items1);
            std::string items2 = "{";
            //生物id，时间，人数，当前伤害，当前伤害百分比，奖励ids
            items2 += std::to_string(creature->GetEntry()); items2 += ",";//生物id
            uint32 shengyutime = creature->aa_boss_time_max - (creature->aa_boss_time / 60000);
            items2 += std::to_string(shengyutime); items2 += ",";//时间
            items2 += std::to_string(creature->aa_boss_dmg.size()); items2 += ",";//人数
            uint32 dmg = aa_boss_dmg_copy[player];
            items2 += std::to_string(dmg); items2 += ",";//当前伤害
            items2 += AA_StringFromFloat(dmg / health * 100.0); items2 += ",\"";//当前伤害百分比
            items2 += conf.reward; items2 += "\"}";//奖励ids
            aaCenter.M_SendClientAddonData(player, "1009", items2);
        }
    }
    catch (std::exception const& e) {}
}

void AACenter::M_SendAA_Conf(Player* player, std::string prefix)
{
    if (!player || !player->IsInWorld()) {
        return;
    }
    if (prefix == "14") { //获取nonsuch配置
        std::string result = "{";//{[id]="text",[id]="text"}
        int j = 0; size_t i = 0;
        for (auto& it : aaCenter.aa_item_nonsuchs)
        {
            i++; j++;
            result += "["; result += std::to_string(it.first); result += "]={\"";
            result += it.second.text; result += "\",\"";
            result += it.second.textpre; result += "\",\"";
            result += it.second.textsuf; result += "\",\"";
            result += it.second.detail; result += "\",";
            result += std::to_string(it.second.chuandai); result += "},";
            if (j > 10 || i == aaCenter.aa_item_nonsuchs.size()) {
                result += "}";
                aaCenter.AA_StringReplaceLast(result, ",}", "}");
                aaCenter.M_SendClientAddonData(player, prefix, result);
                result = "{";
                j = 0;
            }
        }
    }
    else if (prefix == "15") { //获取upgrade配置
        std::string result = "{";//{[id]="text",[id]="text"}
        int j = 0; size_t i = 0;
        for (auto& it : aaCenter.aa_item_upgrades)
        {
            i++; j++;
            result += "["; result += std::to_string(it.first); result += "]={";
            result += std::to_string(it.second.level); result += ",";
            result += std::to_string(it.second.chance); result += ",";
            result += std::to_string(it.second.value1); result += ",";
            result += std::to_string(it.second.value2); result += ",";
            result += std::to_string(it.second.percent1); result += ",";
            result += std::to_string(it.second.percent2); result += ",";
            result += std::to_string(it.second.reward_value); result += ",";
            result += std::to_string(it.second.reward_percent); result += ",";
            result += "\""; result += it.second.upgrade_spell; result += "\",";
            result += std::to_string(it.second.destroy); result += ",";
            result += std::to_string(it.second.need); result += ",";
            result += std::to_string(it.second.zu); result += "},";
            if (j > 10 || i == aaCenter.aa_item_upgrades.size()) {
                result += "}";
                aaCenter.AA_StringReplaceLast(result, ",}", "}");
                aaCenter.M_SendClientAddonData(player, prefix, result);
                result = "{";
                j = 0;
            }
        }
    }
    else if (prefix == "17") { //获取stat配置
        std::string result = "{";//{[id]="text",[id]="text"}
        int j = 0; size_t i = 0;
        for (auto& it : aaCenter.aa_stats)
        {
            i++; j++;
            result += "["; result += std::to_string(it.first); result += "]={";
            result += std::to_string(it.second.type); result += ",\"";
            result += it.second.text; result += "\"},";
            if (j > 10 || i == aaCenter.aa_stats.size()) {
                result += "}";
                aaCenter.AA_StringReplaceLast(result, ",}", "}");
                aaCenter.M_SendClientAddonData(player, prefix, result);
                result = "{";
                j = 0;
            }
        }
    }
    else if (prefix == "18") { //获取worldconf
        uint32 accountid = player->GetSession()->GetAccountId();
        AA_Account a_conf = aaCenter.aa_accounts[accountid];
        AA_Vip_Conf conf = aaCenter.aa_vip_confs[a_conf.vip];
        uint32 xlitem = aaCenter.aa_world_confs[25].value1;
        uint32 gmitem = aaCenter.aa_world_confs[22].value1;
        uint32 csitem = aaCenter.aa_world_confs[9].value1;
        uint32 jbitem = aaCenter.aa_world_confs[24].value1;
        std::string result = "{" +
            std::to_string(xlitem) + "," +
            std::to_string(gmitem) + "," +
            std::to_string(csitem) + "," +
            std::to_string(jbitem) + "," +
            std::to_string(aaCenter.aa_world_confs[36].value1) + "," +
            std::to_string(aaCenter.aa_world_confs[37].value1) + "," +
            std::to_string(aaCenter.aa_world_confs[38].value1) + "," +
            std::to_string(aaCenter.aa_world_confs[39].value1) + "," +
            std::to_string(aaCenter.aa_world_confs[40].value1) + ",\"" +
            aaCenter.aa_world_confs[41].value2 + "\",\"" +
            aaCenter.AA_StringFromFloat(conf.qianghua) + "\"," +
            std::to_string(aaCenter.aa_world_confs[57].value1) + ",\"" +
            aaCenter.aa_world_confs[62].value2 + "\",\"" +//13泡点
            aaCenter.aa_world_confs[63].value2 + "\",\"" +//14魔币
            aaCenter.aa_world_confs[64].value2 + "\",\"" +//15积分
            aaCenter.aa_world_confs[65].value2 + "\"," +
            std::to_string(aaCenter.aa_world_confs[60].value1) + "," +//17货币类型
            std::to_string(aaCenter.aa_world_confs[67].value1) + "," +
            std::to_string(aaCenter.aa_world_confs[68].value1) + "," +
            std::to_string(aaCenter.aa_world_confs[69].value1) + "," +
            std::to_string(aaCenter.aa_world_confs[80].value1) + "}";
        aaCenter.M_SendClientAddonData(player, prefix, result);
    }
    else if (prefix == "19") { //获取needconf
        std::string result = "{";//{[id]={1,"2",3}, [id]={1,3,"3"}}
        int j = 0; size_t i = 0;
        for (auto& it : aaCenter.aa_needs)
        {
            i++; j++;
            if (it.second.text != "") {
                result += "["; result += std::to_string(it.first); result += "]=\"";
                result += it.second.text; result += "\",";
            }
            else {
                result += "["; result += std::to_string(it.first); result += "]={";
                result += std::to_string(it.second.level); result += ",";
                result += std::to_string(it.second.jxlevel); result += ",";
                result += std::to_string(it.second.dqlevel); result += ",";
                result += std::to_string(it.second.dflevel); result += ",";
                result += std::to_string(it.second.viplevel); result += ",";
                result += std::to_string(it.second.jifen_all); result += ",";
                result += std::to_string(it.second.money); result += ",";
                result += std::to_string(it.second.paodian); result += ",";
                result += std::to_string(it.second.mobi); result += ",";
                result += std::to_string(it.second.jifen); result += ",";
                result += std::to_string(it.second.battlecore); result += ",";
                result += std::to_string(it.second.honorcore); result += ",";
                result += std::to_string(it.second.deplete); result += ",";
                result += "\""; result += it.second.items; result += "\",";
                result += std::to_string(it.second.level_item_ItemLevel); result += ","; //物品ItemLevel
                result += std::to_string(it.second.level_item_Quality); result += ","; //物品Quality
                result += std::to_string(it.second.level_item_jd); result += ","; //物品鉴定等级
                result += std::to_string(it.second.level_item_qh); result += ","; //物品强化等级
                result += std::to_string(it.second.level_item_cz); result += ","; //物品成长等级
                result += std::to_string(it.second.level_item_jxsx); result += ","; //物品觉醒属性等级
                result += std::to_string(it.second.level_item_jxjn); result += ","; //物品觉醒技能等级
                result += std::to_string(it.second.level_pet_jh); result += ","; //宠物进化等级
                result += std::to_string(it.second.level_pet_qh); result += ","; //宠物强化等级
                result += std::to_string(it.second.level_pet_jx); result += ","; //宠物觉醒等级
                result += "\""; result += it.second.quests; result += "\",";
                result += "\""; result += it.second.achievements; result += "\",";
                result += "\""; result += it.second.spells; result += "\",";
                result += "\""; result += it.second.buffs; result += "\",";
                result += std::to_string(it.second.gender); result += ",";
                result += std::to_string(it.second.team); result += ",";
                result += std::to_string(it.second.race); result += ",";
                result += std::to_string(it.second.class1); result += ",";
                result += std::to_string(it.second.guild); result += ",";
                result += std::to_string(it.second.mapid); result += ",";
                result += std::to_string(it.second.areaid); result += ",";
                result += std::to_string(it.second.zoneid); result += "},";
            }
            if (j > 10 || i == aaCenter.aa_needs.size()) {
                result += "}";
                aaCenter.AA_StringReplaceLast(result, ",}", "}");
                aaCenter.M_SendClientAddonData(player, prefix, result);
                result = "{";
                j = 0;
            }
        }
    }
    else if (prefix == "20") { //获取rewardconf
        std::string result = "{";//{[id]="text",[id]="text"}
        int j = 0; size_t i = 0;
        for (auto& it : aaCenter.aa_rewards)
        {
            i++; j++;
            if (it.second.text != "") {
                result += "["; result += std::to_string(it.first); result += "]=\"";
                result += it.second.text; result += "\",";
            }
            else {
                result += "["; result += std::to_string(it.first); result += "]={";
                result += std::to_string(it.second.chance); result += ",";
                result += std::to_string(it.second.exp); result += ",";
                result += std::to_string(it.second.jxexp); result += ",";
                result += std::to_string(it.second.dqexp); result += ",";
                result += std::to_string(it.second.dfexp); result += ",";
                result += std::to_string(it.second.czexp); result += ",";
                result += std::to_string(it.second.money); result += ",";
                result += std::to_string(it.second.paodian); result += ",";
                result += std::to_string(it.second.mobi); result += ",";
                result += std::to_string(it.second.jifen); result += ",";
                result += std::to_string(it.second.battlecore); result += ",";
                result += std::to_string(it.second.honorcore); result += ",";
                result += "\""; result += it.second.items; result += "\",";
                result += "\""; result += it.second.spells; result += "\",";
                result += "\""; result += it.second.buffs; result += "\",";
                result += std::to_string(it.second.teleport_id); result += ",";
                result += std::to_string(it.second.vip_level); result += ",";
                result += std::to_string(it.second.tianfu); result += ",";
                result += std::to_string(it.second.jxds); result += ",";
                result += std::to_string(it.second.dqds); result += ",";
                result += std::to_string(it.second.dfds); result += ",";
                result += std::to_string(it.second.touxian); result += ",";
                result += "\""; result += it.second.gm; result += "\"},";
            }
            if (j > 10 || i == aaCenter.aa_rewards.size()) {
                result += "}";
                aaCenter.AA_StringReplaceLast(result, ",}", "}");
                aaCenter.M_SendClientAddonData(player, prefix, result);
                result = "{";
                j = 0;
            }
        }
    }
    else if (prefix == "21") {
        std::string result = "{";//{[id]="aa_spellid",[id]="aa_spellid"}
        int j = 0; size_t i = 0;
        for (auto& it : aaCenter.aa_fw_confs)
        {
            i++; j++;
            result += "["; result += std::to_string(it.first); result += "]=\"";
            result += it.second.text; result += "\",";
            if (j > 10 || i == aaCenter.aa_fw_confs.size()) {
                result += "}";
                aaCenter.AA_StringReplaceLast(result, ",}", "}");
                aaCenter.M_SendClientAddonData(player, prefix, result);
                result = "{";
                j = 0;
            }
        }
    }
    else if (prefix == "22") {
        std::string result = "{";//{[id]="text",[id]="text"}
        int j = 0; size_t i = 0;
        for (auto& it : aaCenter.aa_fwzh_confs)
        {
            i++; j++;
            result += "["; result += std::to_string(it.first); result += "]=\"";
            result += it.second.text; result += "\",";
            if (j > 10 || i == aaCenter.aa_fwzh_confs.size()) {
                result += "}";
                aaCenter.AA_StringReplaceLast(result, ",}", "}");
                aaCenter.M_SendClientAddonData(player, prefix, result);
                result = "{";
                j = 0;
            }
        }
    }
    else if (prefix == "23") {
        std::string result = "{";//{[id]="text",[id]="text"}
        int j = 0; size_t i = 0;
        for (auto& it : aaCenter.aa_item_levels)
        {
            i++; j++;
            result += "{"; \
                result += std::to_string(it.second.zu); result += ",";//1
            result += std::to_string(it.second.level); result += ",";
            result += std::to_string(it.second.exp); result += ",";
            result += std::to_string(it.second.value1); result += ",";
            result += std::to_string(it.second.value2); result += ",";//5
            result += std::to_string(it.second.percent1); result += ",";
            result += std::to_string(it.second.percent2); result += ",";
            result += std::to_string(it.second.reward_value); result += ",";
            result += std::to_string(it.second.reward_percent); result += ",";
            result += "\""; result += it.second.spell; result += "\"},";//10
            if (j > 10 || i == aaCenter.aa_item_levels.size()) {
                result += "}";
                aaCenter.AA_StringReplaceLast(result, ",}", "}");
                aaCenter.M_SendClientAddonData(player, prefix, result);
                result = "{";
                j = 0;
            }
        }
    }
    else if (prefix == "24") {
        std::string result = "{";//{[vendor]={[id]=need,[id]=need},[vendor]={[id]=need,[id]=need}}
        int j = 0; size_t i = 0;
        for (auto& it1 : aaCenter.aa_item_buy_needs)
        {
            result += "["; result += std::to_string(it1.first); result += "]={";
            for (auto& it : it1.second) {   // { {vendor:{id:conf}, vendor:{id:conf} }
                i++; j++;
                result += "[";
                result += std::to_string(it.second.entry); result += "]=";//1
                result += std::to_string(it.second.need); result += ",";
                if (j > 10 || i == it1.second.size()) {
                    result += "}}";
                    aaCenter.AA_StringReplaceLast(result, ",}", "}");
                    aaCenter.M_SendClientAddonData(player, prefix, result);
                    if (i == it1.second.size()) {
                        result = "{";
                        i = 0;
                    }
                    else {
                        result = "{["; result += std::to_string(it1.first); result += "]={";
                    }
                    j = 0;
                }
            }
        }
    }
    else if (prefix == "26") {
        std::string result = "{";//{[id]="text",[id]="text"}
        int j = 0; size_t i = 0;
        for (auto& it : aaCenter.aa_baoshi_confs)
        {
            i++; j++;
            result += "["; result += std::to_string(it.first); result += "]=\"";
            result += it.second.text; result += "\",";
            if (j > 10 || i == aaCenter.aa_baoshi_confs.size()) {
                result += "}";
                aaCenter.AA_StringReplaceLast(result, ",}", "}");
                aaCenter.M_SendClientAddonData(player, prefix, result);
                result = "{";
                j = 0;
            }
        }
    }
    else if (prefix == "28") {
        std::string result = "{";//{[id]={id,zu,count,text},[id]="id,zu,count,text"}}
        int j = 0; size_t i = 0;
        for (auto& it : aaCenter.aa_item_sets)
        {
            uint32 id = it.first;
            AA_Item_Set conf = it.second;
            i++; j++;
            result += "["; result += std::to_string(conf.id); result += "]={";
            result += std::to_string(conf.id); result += ",";
            result += std::to_string(conf.zu); result += ",";
            result += std::to_string(conf.count); result += ",\"";
            result += conf.text; result += "\"},";
            if (j > 10 || i == aaCenter.aa_item_sets.size()) {
                result += "}";
                aaCenter.AA_StringReplaceLast(result, ",}", "}");
                aaCenter.M_SendClientAddonData(player, prefix, result);
                result = "{";
                j = 0;
            }
        }
    }
    else if (prefix == "29") {
        std::string result = "{";//{[id]={id,zu,count,text},[id]="id,zu,count,text"}}
        int j = 0; size_t i = 0;
        for (auto& it : aaCenter.aa_item_set_confs)
        {
            uint32 id = it.first;
            AA_Item_Set_Conf conf = it.second;
            i++; j++;
            result += "["; result += std::to_string(conf.zu); result += "]={\"";
            result += conf.text; result += "\"},";
            if (j > 10 || i == aaCenter.aa_item_set_confs.size()) {
                result += "}";
                aaCenter.AA_StringReplaceLast(result, ",}", "}");
                aaCenter.M_SendClientAddonData(player, prefix, result);
                result = "{";
                j = 0;
            }
        }
    }
    else if (prefix == "1000") { //获取桌面图标
        std::string result = "{";//{[id]="text",[id]="text"}
        int j = 0;
        size_t count = aaCenter.aa_desktops.size();
        for (size_t i = 0; i < count; i++) {
            int32 index = aaCenter.aa_desktops[i];
            AA_Desktop_Conf it = aaCenter.aa_desktop_confs[index];
            j++;
            result += "["; result += std::to_string(it.id); result += "]={";
            result += std::to_string(it.type); result += ",";
            result += std::to_string(it.open); result += ",\"";
            result += it.title; result += "\",\"";
            result += it.icon_path; result += "\",";
            result += std::to_string(it.icon_spell); result += ",";
            result += std::to_string(it.icon_item); result += ",\"";
            result += it.www; result += "\"},";
            if (j > 20 || i == count - 1) {
                result += "}";
                aaCenter.AA_StringReplaceLast(result, ",}", "}");
                aaCenter.M_SendClientAddonData(player, prefix, result);
                result = "{";
                j = 0;
            }
        }
    }
    else if (prefix == "1002") { //等级奖励
        std::vector<int32> levelv; levelv.clear();
        ObjectGuid::LowType guidlow = player->GetGUIDLow();
        AA_Characters conf = aaCenter.aa_characterss[guidlow];
        AA_Characters_Junxian jxconf = aaCenter.aa_characters_junxians[guidlow];
        AA_Characters_Douqi dqconf = aaCenter.aa_characters_douqis[guidlow];
        AA_Characters_Dianfeng dfconf = aaCenter.aa_characters_dianfengs[guidlow];
        std::string levels = conf.shengji;
        aaCenter.AA_StringToVectorInt(levels, levelv, ",");
        std::string result = "{";//{[id]="text",[id]="text"}
        int j = 0;
        size_t count = aaCenter.aa_reward_levels.size();
        for (size_t i = 0; i < count; i++) {
            uint32 index = aaCenter.aa_reward_levels[i];
            AA_Reward_Level_Conf it = aaCenter.aa_reward_level_confs[index];
            int status = 0; // 0可领取 1已领取 2未达到
            if (it.type == 0) { //等级类型(0普通1vip2军衔3斗气4巅峰)
                if (player->GetLevel() < index) {
                    status = 2;
                }
            }
            else if (it.type == 1) {
                uint32 accountid = player->GetSession()->GetAccountId();
                AA_Account a_conf = aaCenter.aa_accounts[accountid];
                if (a_conf.vip < index) {
                    status = 2;
                }
            }
            else if (it.type == 2) {
                if (jxconf.level < index) {
                    status = 2;
                }
            }
            else if (it.type == 3) {
                if (dqconf.level < index) {
                    status = 2;
                }
            }
            else if (it.type == 4) {
                if (dfconf.level < index) {
                    status = 2;
                }
            }
            for (size_t i = 0; i < levelv.size(); i++) {
                uint32 leveli = levelv[i];
                if (leveli == it.level) {
                    status = 1; break;
                }
            }
            j++;
            result += "["; result += std::to_string(it.level); result += "]={";
            result += std::to_string(status); result += ",";
            result += std::to_string(it.type); result += ",\"";
            result += it.text; result += "\"},";
            if (j > 20 || i == count - 1) {
                result += "}";
                aaCenter.AA_StringReplaceLast(result, ",}", "}");
                aaCenter.M_SendClientAddonData(player, prefix, result);
                result = "{";
                j = 0;
            }
        }
    }
    else if (prefix == "1003") { //个人理财
        uint32 accountid = player->GetSession()->GetAccountId();
        AA_Account a_conf = aaCenter.aa_accounts[accountid];
        AA_Reward_Licai_Conf it = aaCenter.aa_reward_licai_confs[1];
        std::string status = "0"; // 0可领取 1已领取 2未达到
        if (a_conf.licai_day == 0) {
            status = "2";
        }
        if (a_conf.licai == 1) {
            status = "1";
        }
        std::string result = "{";
        result += status; result += ",";
        result += std::to_string(a_conf.licai_day); result += ",\"";
        result += it.text; result += "\"}";
        aaCenter.M_SendClientAddonData(player, prefix, result);
    }
    else if (prefix == "1004") { //首充奖励
        uint32 accountid = player->GetSession()->GetAccountId();
        AA_Account a_conf = aaCenter.aa_accounts[accountid];
        time_t time1 = time(NULL);//获取系统时间，单位为秒;
        struct tm* time = localtime(&time1);//转换成tm类型的结构体;
        uint32 day = time->tm_wday == 0 ? 7 : time->tm_wday;
        AA_Reward_Shouchong_Conf it = aaCenter.aa_reward_shouchong_confs[day];
        std::string status = "0"; // 0可领取 1已领取 2未达到
        if (a_conf.shouchong_day < it.jifen) {
            status = "2";
        }
        if (a_conf.shouchong == 1) {
            status = "1";
        }
        std::string result = "{";
        result += status; result += ",";
        result += std::to_string(it.jifen); result += ",\"";
        result += it.text; result += "\"}";
        aaCenter.M_SendClientAddonData(player, prefix, result);
    }
    else if (prefix == "1005") { //累计充值 当前累计积分，按钮状态，积分，描述
        std::vector<int32> levelv; levelv.clear();
        uint32 accountid = player->GetSession()->GetAccountId();
        AA_Account conf = aaCenter.aa_accounts[accountid];
        std::string levels = conf.leichong;
        aaCenter.AA_StringToVectorInt(levels, levelv, ",");
        std::string result = "{";//{[id]="text",[id]="text"}
        int j = 0;
        size_t count = aaCenter.aa_reward_leijis.size();
        for (size_t i = 0; i < count; i++) {
            uint32 index = aaCenter.aa_reward_leijis[i];
            AA_Reward_Leiji_Conf it = aaCenter.aa_reward_leiji_confs[index];
            int status = 0; // 0可领取 1已领取 2未达到
            if (conf.jifen_all < it.jifen) {
                status = 2;
            }
            for (size_t i = 0; i < levelv.size(); i++) {
                uint32 leveli = levelv[i];
                if (leveli == it.jifen) {
                    status = 1; break;
                }
            }
            j++;
            result += "["; result += std::to_string(it.jifen); result += "]={";
            result += std::to_string(status); result += ",";
            result += std::to_string(conf.jifen_all); result += ",\"";
            result += it.text; result += "\"},";
            if (j > 20 || i == count - 1) {
                result += "}";
                aaCenter.AA_StringReplaceLast(result, ",}", "}");
                aaCenter.M_SendClientAddonData(player, prefix, result);
                result = "{";
                j = 0;
            }
        }
    }
    else if (prefix == "1006") { //每日签到
        std::vector<int32> levelv; levelv.clear();
        uint32 accountid = player->GetSession()->GetAccountId();
        AA_Account conf = aaCenter.aa_accounts[accountid];
        std::string levels = conf.denglu;
        aaCenter.AA_StringToVectorInt(levels, levelv, ",");
        std::string result = "{";//{[id]="text",[id]="text"}
        int j = 0;
        size_t count = aaCenter.aa_reward_qiandaos.size();
        for (size_t i = 0; i < count; i++) {
            uint32 index = aaCenter.aa_reward_qiandaos[i];
            AA_Reward_Qiandao_Conf it = aaCenter.aa_reward_qiandao_confs[index];
            int status = 0; // 0可签到 1已领取 2未达到
            if (conf.denglu_day < it.day) {
                status = 2;
            }
            for (size_t i = 0; i < levelv.size(); i++) {
                uint32 leveli = levelv[i];
                if (leveli == it.day) {
                    status = 1; break;
                }
            }
            j++; // 天数  状态, 总天数，签到 说明
            result += "["; result += std::to_string(it.day); result += "]={";
            result += std::to_string(status); result += ",";
            result += std::to_string(conf.denglu_day); result += ",";
            result += std::to_string(conf.denglu_qiandao); result += ",\"";
            result += it.text; result += "\"},";
            if (j > 20 || i == count - 1) {
                result += "}";
                aaCenter.AA_StringReplaceLast(result, ",}", "}");
                aaCenter.M_SendClientAddonData(player, prefix, result);
                result = "{";
                j = 0;
            }
        }
    }
    else if (prefix == "10071") { //幸运抽奖,展示物品+系统提示
        std::vector<uint32> ids = aaCenter.aa_choujiang_zus[aaCenter.aa_world_confs[74].value1];
        std::string items = "{\"";
        std::string sysstr = aaCenter.aa_world_confs[74].value2;
        items += sysstr; items += "\",";
        for (uint32 id : ids) {
            AA_Choujiang conf = aaCenter.aa_choujiangs[id];
            if (conf.itemid > 0) {
                items += "\""; items = items + aaCenter.AA_GetItemLink(conf.itemid); items += "\",";
            }
        }
        items += "}";
        aaCenter.AA_StringReplaceLast(items, ",}", "}");
        aaCenter.M_SendClientAddonData(player, prefix, items);
    }
    else if (prefix == "10072") { //幸运抽奖,抽奖公告
        std::string items = "{";
        if (aaCenter.aa_choujiangStrs.size() > 0) {
            for (std::string str : aaCenter.aa_choujiangStrs) {
                items += "\""; items += str; items += "\",";
            }
        }
        items += "}";
        aaCenter.AA_StringReplaceLast(items, ",}", "}");
        aaCenter.M_SendClientAddonData(player, prefix, items);
    }
    else if (prefix == "1011") { //获取活动公告栏
 //        --静态：活动id，图标，名字，标题，按钮名字
 //        --动态：活动id，距离开始的时间秒
        std::string result = "{";//{[id]="name","title","icon","button",[id]="text"}
        int j = 0; size_t i = 0;
        for (auto& it : aaCenter.aa_huodong_confs)
        {
            i++; j++;
            result += "["; result += std::to_string(it.first); result += "]={\"";
            result += it.second.name; result += "\",\"";
            result += it.second.title; result += "\",\"";
            result += it.second.icon; result += "\",\"";
            result += it.second.button; result += "\"},";
            if (j > 10 || i == aaCenter.aa_huodong_confs.size()) {
                result += "}";
                aaCenter.AA_StringReplaceLast(result, ",}", "}");
                aaCenter.M_SendClientAddonData(player, prefix, result);
                result = "{";
                j = 0;
            }
        }
    }
    else if (prefix == "1014") { //游戏登录：请求栏目1014
        std::string result = "{";//{[id]={"name","总页数"},[id]={"name","总页数"}}
        int j = 0; size_t i = 0;
        for (auto it : aaCenter.aa_shop_zus)
        {
            i++; j++;
            std::string name = "";
            std::set<uint32> s; s.clear();
            for (auto iter : it.second) {
                uint32 ye = iter.first;
                s.insert(ye);
                if (iter.second.size() > 0) {
                    uint32 confid = iter.second[0];
                    AA_Shop conf = aaCenter.aa_shops[confid];
                    name = conf.name;
                }
            }
            result += "["; result += std::to_string(it.first); result += "]={\"";
            result += name; result += "\",";
            result += std::to_string(s.size()); result += "},";
            if (j > 10 || i == aaCenter.aa_shop_zus.size()) {
                result += "}";
                aaCenter.AA_StringReplaceLast(result, ",}", "}");
                aaCenter.M_SendClientAddonData(player, prefix, result);
                result = "{";
                j = 0;
            }
        }
    }
    else if (prefix == "1015") { //点开商城，点击栏目，请求当前栏目的详情
        std::string result = "{";//{[lan]={第几页，物品id，物品guid，物品名称，购买需求，购买奖励}},[id]={"name","总页数"}}
        //std::unordered_map<uint32, std::unordered_map<uint32, std::vector<uint32>>> aa_shop_zus;
        //it1.s = std::unordered_map<uint32, std::vector<uint32>
        //it.s = std::vector<uint32>
        //iter = uint32
        for (auto it1 : aaCenter.aa_shop_zus)
        {
            result += "["; result += std::to_string(it1.first); result += "]={";
            uint32 count = 0;
            int j = 0; size_t i = 0;
            uint32 index = 0;
            {
                std::unordered_map<uint32, std::vector<uint32>> v = it1.second;
                for (auto it : v) {   // { {vendor:{id:conf}, vendor:{id:conf} }
                    std::vector<uint32> v1 = it.second;
                    count += v1.size();
                }
            }
            std::unordered_map<uint32, std::vector<uint32>> v = it1.second;
            for (auto it : v) {   // { {vendor:{id:conf}, vendor:{id:conf} }
                std::vector<uint32> v1 = it.second;
                if (v1.size() > 0) {
                    for (auto iter : v1) {
                        index++;
                        i++; j++;
                        uint32 confid = iter;
                        AA_Shop conf = aaCenter.aa_shops[confid];
                        result += "[";
                        result += std::to_string(index); result += "]={";//1
                        result += std::to_string(conf.ye); result += ",";//1
                        result += std::to_string(conf.entry); result += ",";
                        result += std::to_string(conf.guidlow); result += ",\"";
                        std::string itemlink = aaCenter.AA_GetItemLink(conf.entry);
                        if (conf.guidlow > 0)
                            if (Item* item = aaCenter.GetItemByGUIDLow(player, conf.guidlow))
                                itemlink = aaCenter.AA_GetItemLinkJd(item);
                        result += itemlink; result += "\",";
                        result += std::to_string(conf.need); result += ",";
                        result += std::to_string(conf.reward); result += "},";
                        if (j > 5 || i == count) {
                            result += "}}";
                            aaCenter.AA_StringReplaceLast(result, ",}", "}");
                            aaCenter.M_SendClientAddonData(player, prefix, result);
                            if (i == count) {
                                result = "{";
                                i = 0;
                            }
                            else {
                                result = "{["; result += std::to_string(it1.first); result += "]={";
                            }
                            j = 0;
                        }
                    }
                }
            }
        }
    }
    else if (prefix == "1020") { //魂玉激活
        std::string result = "{";//{[id]="name","title","icon","button",[id]="text"}
        for (auto& it : aaCenter.aa_item_shuangjias)
        {
            result += "["; result += std::to_string(it.first); result += "]=\"";
            std::string link = aaCenter.AA_GetItemLink(it.second.guanghuan_item);
            result += link; result += "\",";
        }
        result += "}";
        aaCenter.AA_StringReplaceLast(result, ",}", "}");
        aaCenter.M_SendClientAddonData(player, prefix, result);
    }
    else if (prefix == "3050") { //集结号队伍信息
        //index，id，活动信息,队长姓名，队伍情况，倒计时时间
        std::vector<std::vector<uint32>> duiwus; duiwus.clear();
        if (aa_jijie_guidlows.size() == 0) {
            aaCenter.M_SendClientAddonData(player, prefix, "{}");
            return;
        }
        for (int ii = 0; ii < aaCenter.aa_jijie_guidlows.size(); ii++) {
            std::vector<uint32> v; v.clear();
            for (size_t j = 0; j < 10; j++)
            {
                v.push_back(0);
            }
            duiwus.push_back(v);
        }
        std::set<Player*> players = GetOnlinePlayers();
        for (auto player : players) {
            if (player->aa_jijie_guidlow == 0) {
                continue;
            }
            int32 index = -1;
            for (int i = 0; i < aaCenter.aa_jijie_guidlows.size(); i++) {
                ObjectGuid::LowType guidlow_dz = aaCenter.aa_jijie_guidlows[i];
                if (guidlow_dz == player->aa_jijie_guidlow) {
                    index = i;
                }
            }
            if (index != -1) {
                uint32 class1 = player->GetClass();
                if (class1 == 11) {
                    class1 = 10;
                }
                class1--;
                duiwus[index][class1] = duiwus[index][class1] + 1;
            }
        }
        std::string result = "{";
        int j = 0; size_t i = 0; uint32 g = 0;
        for (auto it : aaCenter.aa_jijie_guidlows) {
            i++; j++;
            ObjectGuid::LowType guidlow = aaCenter.aa_jijie_guidlows[g];
            std::string name = "";
            if (guidlow > 0) {
                if (Player* p = ObjectAccessor::FindPlayerByLowGUID(guidlow)) {
                    name = AA_GetPlayerColor(p) + p->GetName() + "|r";
                }
            }
            uint32 id = aaCenter.aa_jijie_ids[g];
            uint32 time = aaCenter.aa_jijie_times[g] / 1000;
            uint32 isJiaru = 0;
            if (player->aa_jijie_guidlow == it) {
                isJiaru = 1;
            }
            std::string msg = aaCenter.aa_jijie_msgs[g];
            std::vector<uint32> counts = duiwus[g];
            std::string count = "";
            for (auto itr : counts)
            {
                count += std::to_string(itr);
                count += ",";
            }
            //index，id，队长姓名，队伍情况，倒计时时间
            result += "["; result += std::to_string(i); result += "]={";
            result += std::to_string(id); result += ",\"";
            result += msg; result += "\",\"";
            result += name; result += "\",";
            result += count;
            result += std::to_string(isJiaru); result += ",";
            result += std::to_string(time); result += "},";

            if (j > 10 || i == aaCenter.aa_jijie_guidlows.size()) {
                result += "}";
                aaCenter.AA_StringReplaceLast(result, ",}", "}");
                aaCenter.M_SendClientAddonData(player, prefix, result);
                result = "{";
                j = 0;
            }
            g = g + 1;
        }
    }
    else if (prefix == "3051") { //集结号列表信息
        //id，图标，title，
        if (aaCenter.aa_ui_jijies.size() == 0) {
            aaCenter.M_SendClientAddonData(player, prefix, "{}");
            return;
        }
        std::string result = "{";//{[id]={"id","title","icon"},[id]={"name","总页数"}}
        int j = 0; size_t i = 0;
        for (auto it : aaCenter.aa_ui_jijies)
        {
            i++; j++;
            AA_UI_Jijie conf = it.second;
            result += "["; result += std::to_string(i); result += "]={";
            result += std::to_string(conf.id); result += ",\"";
            result += conf.icon; result += "\",\"";
            result += conf.name; result += "\",\"";
            result += conf.title; result += "\"},";
            if (j > 10 || i == aaCenter.aa_ui_jijies.size()) {
                result += "}";
                aaCenter.AA_StringReplaceLast(result, ",}", "}");
                aaCenter.M_SendClientAddonData(player, prefix, result);
                result = "{";
                j = 0;
            }
        }
    }
}

bool AACenter::M_SendClientAddonData(Player* player, std::string command, std::string msg)
{
    if (!player || !player->IsInWorld()) {
        return false;
    }
    if (msg == "" || command == "") { return false; }
    std::string fullmsg = command + "\t" + msg;
    player->WhisperAddon(fullmsg, "", false, player);
    return true;
}

Item* AACenter::GetEquipItemByEntry(Player* player, uint32 entry)
{
    for (uint8 i = EQUIPMENT_SLOT_START; i < INVENTORY_SLOT_BAG_END; ++i)
        if (Item* pItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, i))
        {
            if (!pItem || !pItem->IsInWorld()) {
                continue;
            }
            if (pItem->GetEntry() == entry && pItem->IsEquipped())
                return pItem;
        }
    return nullptr;
}
uint32 AACenter::GetAll_level_item_ItemLevel(Player* player)
{
    uint32 itemlevel = 0;
    //过滤不计算装等的位置
    std::vector<int32> InventoryTypes; InventoryTypes.clear();
    if (aaCenter.aa_world_confs[27].value2 != "") {
        aaCenter.AA_StringToVectorInt(aaCenter.aa_world_confs[27].value2, InventoryTypes, ",");
    }
    for (uint8 i = EQUIPMENT_SLOT_START; i < INVENTORY_SLOT_BAG_END; ++i)
        if (Item* pItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, i))
        {
            if (!pItem || !pItem->IsInWorld()) {
                continue;
            }
            if (ItemTemplate const* pProto = pItem->GetTemplate()) {
                if (std::find(InventoryTypes.begin(), InventoryTypes.end(), pProto->GetInventoryType()) != InventoryTypes.end()) {
                    continue;
                }
                itemlevel = itemlevel + pItem->GetItemLevel(player);
            }
        }
    return itemlevel;
}
uint32 AACenter::GetAll_level_item_Quality(Player* player)
{
    uint32 itemlevel = 0;
    for (uint8 i = EQUIPMENT_SLOT_START; i < INVENTORY_SLOT_BAG_END; ++i)
        if (Item* pItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, i))
        {
            if (!pItem || !pItem->IsInWorld()) {
                continue;
            }
            if (ItemTemplate const* pProto = pItem->GetTemplate()) {
                itemlevel = itemlevel + pProto->GetQuality();
            }
        }
    return itemlevel;
}
uint32 AACenter::GetAll_level_item_jd(Player* player)
{
    uint32 itemlevel = 0;
    for (uint8 i = EQUIPMENT_SLOT_START; i < INVENTORY_SLOT_BAG_END; ++i)
        if (Item* pItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, i))
        {
            if (!pItem || !pItem->IsInWorld()) {
                continue;
            }
            ObjectGuid::LowType guidlow = pItem->GetGUIDLow();
            itemlevel = itemlevel + aaCenter.aa_character_instances[guidlow].jd_level;
        }
    return itemlevel;
}
uint32 AACenter::GetAll_level_item_qh(Player* player)
{
    uint32 itemlevel = 0;
    for (uint8 i = EQUIPMENT_SLOT_START; i < INVENTORY_SLOT_BAG_END; ++i)
        if (Item* pItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, i))
        {
            if (!pItem || !pItem->IsInWorld()) {
                continue;
            }
            ObjectGuid::LowType guidlow = pItem->GetGUIDLow();
            itemlevel = itemlevel + aaCenter.aa_character_instances[guidlow].qh_level;
        }
    return itemlevel;
}
uint32 AACenter::GetAll_level_item_cz(Player* player)
{
    uint32 itemlevel = 0;
    for (uint8 i = EQUIPMENT_SLOT_START; i < INVENTORY_SLOT_BAG_END; ++i)
        if (Item* pItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, i))
        {
            if (!pItem || !pItem->IsInWorld()) {
                continue;
            }
            ObjectGuid::LowType guidlow = pItem->GetGUIDLow();
            itemlevel = itemlevel + aaCenter.aa_character_instances[guidlow].cz_level;
        }
    return itemlevel;
}
uint32 AACenter::GetAll_level_item_jxsx(Player* player)
{
    uint32 itemlevel = 0;
    for (uint8 i = EQUIPMENT_SLOT_START; i < INVENTORY_SLOT_BAG_END; ++i)
        if (Item* pItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, i))
        {
            if (!pItem || !pItem->IsInWorld()) {
                continue;
            }
            ObjectGuid::LowType guidlow = pItem->GetGUIDLow();
            itemlevel = itemlevel + aaCenter.aa_character_instances[guidlow].fm_value_count;
        }
    return itemlevel;
}
uint32 AACenter::GetAll_level_item_jxjn(Player* player)
{
    uint32 itemlevel = 0;
    for (uint8 i = EQUIPMENT_SLOT_START; i < INVENTORY_SLOT_BAG_END; ++i)
        if (Item* pItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, i))
        {
            if (!pItem || !pItem->IsInWorld()) {
                continue;
            }
            ObjectGuid::LowType guidlow = pItem->GetGUIDLow();
            itemlevel = itemlevel + aaCenter.aa_character_instances[guidlow].fm_spell_count;
        }
    return itemlevel;
}

std::string AACenter::M_GetItemTemplateGuid(Player* player, std::vector<uint32> itemGuids, std::vector<uint32> itemEntrys)
{
    try {
        std::string items = "{";
        int count = itemGuids.size();
        if (count == 0) { return "{}"; }
        if (!player) { return "{}"; }
        for (int i = 0; i < count; i++) {
            uint32 itemGuid = itemGuids[i];
            uint32 itemEntry = itemEntrys[i];
            if (itemGuid == 0) {
                continue;
            }
            AA_Huishou_Conf hsconf = aaCenter.AA_GetHuiShouConf(player, itemGuid, itemEntry);
            if (hsconf.reward == 0) {
                continue;
            }
            //孵化1，强化1，进化1，重生1
            std::string item = "[";
            item += std::to_string(itemGuid); item += "]={";
            item += std::to_string(hsconf.reward);
            items += item;
            items += "},";
        }
        items += "}";
        aaCenter.AA_StringReplaceLast(items, ",}", "}");
        return items;
    }
    catch (std::exception const& e)
    {
        return "{}";
    }
    return "{}";
}

std::string AACenter::M_GetItemTemplate(std::set<uint32> itemIds)
{
    try {
        std::string items = "{";
        int count = itemIds.size();
        if (count == 0) { return "{}"; }
        for (auto itemEntry : itemIds) {
            if (itemEntry == 0) {
                continue;
            }
            ItemTemplate const* proto = sObjectMgr->GetItemTemplate(itemEntry);
            if (!proto) { continue; }
            //强化1，合成，回收，重铸1
            AA_Hecheng_Conf hcconf = aaCenter.aa_hecheng_confs[proto->GetId()];
            //孵化1，强化1，进化1，重生1
            std::string item = "[";
            item += std::to_string(proto->GetId()); item += "]={";
            item += std::to_string(1); item += ",";
            item += std::to_string(0); item += ",";
            item += std::to_string(aaCenter.aa_item_use_needs[itemEntry].need); item += ",";//使用需要3
            item += std::to_string(aaCenter.aa_item_use_rewards[itemEntry].reward); item += ",";//使用奖励4
            item += std::to_string(aaCenter.aa_item_buy_rewards[itemEntry].reward); item += ",";//出售奖励5
            item += std::to_string(hcconf.itemid1); item += ",";//合成物品6
            item += std::to_string(hcconf.need); item += ",";//合成需要7
            item += std::to_string(aaCenter.aa_item_bags[proto->GetId()].entry); item += ",\"";
            item += proto->GetName(LOCALE_zhCN); item += "\""; //物品成长组
            items += item;
            items += "},";
        }
        items += "}";
        aaCenter.AA_StringReplaceLast(items, ",}", "}");
        return items;
    }
    catch (std::exception const& e)
    {
        return "{}";
    }
    return "{}";
}

std::set<Item*> AACenter::M_GetBagItems(Player* player)
{
    std::set<Item*> items;
    items.clear();
    if (!player) {
        return items;
    }

    for (uint8 i = INVENTORY_SLOT_ITEM_START; i < INVENTORY_SLOT_ITEM_END; i++) {
        if (Item* pItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, i))
        {
            items.insert(pItem);
        }
    }
    for (uint8 i = INVENTORY_SLOT_BAG_START; i < INVENTORY_SLOT_BAG_END; ++i)
    {
        if (Bag* pBag = player->GetBagByPos(i))
        {
            for (uint32 j = 0; j < pBag->GetBagSize(); ++j)
            {
                if (Item* pItem = pBag->GetItemByPos(j))
                {
                    items.insert(pItem);
                }
            }
        }
    }
    return items;
}

std::set<Item*> AACenter::M_GetEquipItems(Player* player)
{
    std::set<Item*> items;
    items.clear();
    for (uint8 i = EQUIPMENT_SLOT_START; i < EQUIPMENT_SLOT_END; i++) {
        if (Item* pItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, i))
        {
            if (!pItem->IsInWorld()) {
                continue;
            }
            items.insert(pItem);
        }
    }
    return items;
}

std::set<Item*> AACenter::M_GetBankItems(Player* player)
{
    std::set<Item*> items;
    items.clear();
    if (!player) {
        return items;
    }

    for (uint8 i = BANK_SLOT_ITEM_START; i < BANK_SLOT_ITEM_END; i++) {
        if (Item* pItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, i))
        {
            items.insert(pItem);
        }
    }
    for (uint8 i = BANK_SLOT_BAG_START; i < BANK_SLOT_BAG_END; ++i)
    {
        if (Bag* pBag = player->GetBagByPos(i))
        {
            for (uint32 j = 0; j < pBag->GetBagSize(); ++j)
            {
                if (Item* pItem = pBag->GetItemByPos(j))
                {
                    items.insert(pItem);
                }
            }
        }
    }
    return items;
}

std::set<Item*> AACenter::M_GetBagAndEquipItems(Player* player)
{
    std::set<Item*> items;
    items.clear();
    std::set<Item*> items1 = M_GetBagItems(player);
    std::set<Item*> items2 = M_GetEquipItems(player);
    for (Item* pItem : items1) {
        if (!pItem || !pItem->IsInWorld()) {
            continue;
        }
        items.insert(pItem);
    }
    for (Item* pItem : items2) {
        if (!pItem || !pItem->IsInWorld()) {
            continue;
        }
        items.insert(pItem);
    }
    return items;
}

std::set<Item*> AACenter::M_GetBagAndEquipAndBankItems(Player* player)
{
    std::set<Item*> items;
    items.clear();
    std::set<Item*> items1 = M_GetBagItems(player);
    std::set<Item*> items2 = M_GetEquipItems(player);
    std::set<Item*> items3 = M_GetBankItems(player);
    for (Item* pItem : items1) {
        if (!pItem || !pItem->IsInWorld()) {
            continue;
        }
        items.insert(pItem);
    }
    for (Item* pItem : items2) {
        if (!pItem || !pItem->IsInWorld()) {
            continue;
        }
        items.insert(pItem);
    }
    for (Item* pItem : items3) {
        if (!pItem || !pItem->IsInWorld()) {
            continue;
        }
        items.insert(pItem);
    }
    return items;
}

void AACenter::GiveJXXP(Player* player, uint32 xp)
{
    if (!player || !player->IsInWorld() || !player->ToPlayer()) {
        return;
    }
    ObjectGuid::LowType guidlow = player->GetGUIDLow();
    //剩余军衔经验
    aaCenter.aa_characters_junxians[guidlow].exp += xp;
    AA_Junxian_Conf conf;
    AA_Junxian_Conf conf_n;
    //当前军衔等级
    uint32 level = aaCenter.aa_characters_junxians[guidlow].level;
    bool isLevel = false;
    do {
        //下级军衔信息
        conf = aaCenter.aa_junxian_confs[level];
        level++;
        conf_n = aaCenter.aa_junxian_confs[level];
        //剩余军衔经验 > 下级军衔经验
        if (aaCenter.aa_characters_junxians[guidlow].exp >= conf.exp && conf_n.level > 0) {
            //当前军衔等级+1，触发升级
            aaCenter.aa_characters_junxians[guidlow].level = level;
            if (conf.notice > 0) {
                AA_Message aa_message;
                AA_Notice notice = aaCenter.aa_notices[conf.notice];
                aaCenter.AA_SendNotice(player, notice, true, aa_message);
            }
            isLevel = true;
            //剩余军衔经验,减去下级军衔经验
            aaCenter.aa_characters_junxians[guidlow].exp -= conf.exp;
            //触发升级奖励
            if (conf.reward > 0) {
                aaCenter.M_Reward(player, conf.reward);
            }
        }
    } while (conf_n.level > 0);
    if (isLevel && player->IsAlive()) {
        player->CastSpell(player, 47292);

        //更新客户端玩家信息
        ObjectGuid::LowType guidlow = player->GetGUIDLow();
        uint32 accountid = player->GetSession()->GetAccountId();
        AA_Account a_conf = aaCenter.aa_accounts[accountid];
        AA_Characters_Dianfeng df_conf = aaCenter.aa_characters_dianfengs[guidlow];
        AA_Characters_Douqi dq_conf = aaCenter.aa_characters_douqis[guidlow];
        AA_Characters_Junxian jx_conf = aaCenter.aa_characters_junxians[guidlow];
        std::string result = "{" + std::to_string(df_conf.level) + "," + std::to_string(dq_conf.level) + "," + std::to_string(jx_conf.level) + "," + std::to_string(a_conf.vip) + "}";
        aaCenter.M_SendClientAddonData(const_cast<Player*>(player), "10012", result);
    }
    time_t timep;
    time(&timep);
    aaCenter.aa_characters_junxians[guidlow].update_time = timep;
    aaCenter.aa_characters_junxians[guidlow].isUpdate = true;
}

void AACenter::GiveDQXP(Player* player, uint32 xp)
{
    if (!player || !player->IsInWorld() || !player->ToPlayer()) {
        return;
    }
    ObjectGuid::LowType guidlow = player->GetGUIDLow();
    //剩余军衔经验
    aaCenter.aa_characters_douqis[guidlow].exp += xp;
    AA_Douqi_Conf conf;
    AA_Douqi_Conf conf_n;
    //当前军衔等级
    uint32 level = aaCenter.aa_characters_douqis[guidlow].level;
    bool isLevel = false;
    do {
        //下级军衔信息
        conf = aaCenter.aa_douqi_confs[level];
        level++;
        conf_n = aaCenter.aa_douqi_confs[level];
        //剩余军衔经验 > 下级军衔经验
        if (aaCenter.aa_characters_douqis[guidlow].exp >= conf.exp && conf_n.level > 0) {
            //当前军衔等级+1
            aaCenter.aa_characters_douqis[guidlow].level = level;
            if (conf.notice > 0) {
                AA_Message aa_message;
                AA_Notice notice = aaCenter.aa_notices[conf.notice];
                aaCenter.AA_SendNotice(player, notice, true, aa_message);
            }
            isLevel = true;
            //剩余军衔经验,减去下级军衔经验
            aaCenter.aa_characters_douqis[guidlow].exp -= conf.exp;
            //触发升级奖励
            if (conf.reward > 0) {
                aaCenter.M_Reward(player, conf.reward);
            }
        }
    } while (conf_n.level > 0);
    if (isLevel && player->IsAlive()) {
        player->CastSpell(player, 47292);

        //更新客户端玩家信息
        ObjectGuid::LowType guidlow = player->GetGUIDLow();
        uint32 accountid = player->GetSession()->GetAccountId();
        AA_Account a_conf = aaCenter.aa_accounts[accountid];
        AA_Characters_Dianfeng df_conf = aaCenter.aa_characters_dianfengs[guidlow];
        AA_Characters_Douqi dq_conf = aaCenter.aa_characters_douqis[guidlow];
        AA_Characters_Junxian jx_conf = aaCenter.aa_characters_junxians[guidlow];
        std::string result = "{" + std::to_string(df_conf.level) + "," + std::to_string(dq_conf.level) + "," + std::to_string(jx_conf.level) + "," + std::to_string(a_conf.vip) + "}";
        aaCenter.M_SendClientAddonData(const_cast<Player*>(player), "10012", result);
    }
    time_t timep;
    time(&timep);
    aaCenter.aa_characters_douqis[guidlow].update_time = timep;
    aaCenter.aa_characters_douqis[guidlow].isUpdate = true;
}

void AACenter::GiveDFXP(Player* player, uint32 xp)
{
    if (!player || !player->IsInWorld() || !player->ToPlayer()) {
        return;
    }
    ObjectGuid::LowType guidlow = player->GetGUIDLow();
    //剩余军衔经验
    aaCenter.aa_characters_dianfengs[guidlow].exp += xp;
    AA_Dianfeng_Conf conf;
    AA_Dianfeng_Conf conf_n;
    //当前军衔等级
    uint32 level = aaCenter.aa_characters_dianfengs[guidlow].level;
    bool isLevel = false;
    do {
        //下级军衔信息
        conf = aaCenter.aa_dianfeng_confs[level];
        level++;
        conf_n = aaCenter.aa_dianfeng_confs[level];
        //剩余军衔经验 > 下级军衔经验
        if (aaCenter.aa_characters_dianfengs[guidlow].exp >= conf.exp && conf_n.level > 0) {
            //当前军衔等级+1
            aaCenter.aa_characters_dianfengs[guidlow].level = level;
            if (conf.notice > 0) {
                AA_Message aa_message;
                AA_Notice notice = aaCenter.aa_notices[conf.notice];
                aaCenter.AA_SendNotice(player, notice, true, aa_message);
            }
            isLevel = true;
            //剩余军衔经验,减去下级军衔经验
            aaCenter.aa_characters_dianfengs[guidlow].exp -= conf.exp;
            //触发升级奖励
            if (conf.reward > 0) {
                aaCenter.M_Reward(player, conf.reward);
            }
        }
    } while (conf_n.level > 0);
    if (isLevel && player->IsAlive()) {
        player->CastSpell(player, 47292);

        //更新客户端玩家信息
        ObjectGuid::LowType guidlow = player->GetGUIDLow();
        uint32 accountid = player->GetSession()->GetAccountId();
        AA_Account a_conf = aaCenter.aa_accounts[accountid];
        AA_Characters_Dianfeng df_conf = aaCenter.aa_characters_dianfengs[guidlow];
        AA_Characters_Douqi dq_conf = aaCenter.aa_characters_douqis[guidlow];
        AA_Characters_Junxian jx_conf = aaCenter.aa_characters_junxians[guidlow];
        std::string result = "{" + std::to_string(df_conf.level) + "," + std::to_string(dq_conf.level) + "," + std::to_string(jx_conf.level) + "," + std::to_string(a_conf.vip) + "}";
        aaCenter.M_SendClientAddonData(const_cast<Player*>(player), "10012", result);
    }
    time_t timep;
    time(&timep);
    aaCenter.aa_characters_dianfengs[guidlow].update_time = timep;
    aaCenter.aa_characters_dianfengs[guidlow].isUpdate = true;
}

void AACenter::AddValue(Player* player, uint32 statType, int32 val, bool apply)
{
    if (!player) {
        return;
    }
    if (statType >= 500 && statType <= 599) { //百分比属性
        player->aa_fm_values[statType] += (apply ? val : (-val));
        player->UpdateAllStats();
        return;
    }
    if (statType >= 200) { //自定义技能
        player->aa_fm_values[statType] += (apply ? val : (-val));
        return;
    }
    float combatRatingMultiplier = 1.0f;

    switch (statType)
    {
    case ITEM_MOD_MANA:
        player->HandleStatFlatModifier(UNIT_MOD_MANA, BASE_VALUE, float(val), apply);
        break;
    case ITEM_MOD_HEALTH:                           // modify HP
        player->HandleStatFlatModifier(UNIT_MOD_HEALTH, BASE_VALUE, float(val), apply);
        break;
    case ITEM_MOD_AGILITY:                          // modify agility
        player->HandleStatFlatModifier(UNIT_MOD_STAT_AGILITY, BASE_VALUE, float(val), apply);
        player->UpdateStatBuffMod(STAT_AGILITY);
        break;
    case ITEM_MOD_STRENGTH:                         //modify strength
        player->HandleStatFlatModifier(UNIT_MOD_STAT_STRENGTH, BASE_VALUE, float(val), apply);
        player->UpdateStatBuffMod(STAT_STRENGTH);
        break;
    case ITEM_MOD_INTELLECT:                        //modify intellect
        player->HandleStatFlatModifier(UNIT_MOD_STAT_INTELLECT, BASE_VALUE, float(val), apply);
        player->UpdateStatBuffMod(STAT_INTELLECT);
        break;
        // case ITEM_MOD_SPIRIT:                           //modify spirit
        //     HandleStatModifier(UNIT_MOD_STAT_SPIRIT, BASE_VALUE, float(val), apply);
        //     ApplyStatBuffMod(STAT_SPIRIT, CalculatePct(val, GetModifierValue(UNIT_MOD_STAT_SPIRIT, BASE_PCT_EXCLUDE_CREATE)), apply);
        //     break;
    case ITEM_MOD_STAMINA:                          //modify stamina
    {
        player->HandleStatFlatModifier(UNIT_MOD_STAT_STAMINA, BASE_VALUE, float(val), apply);
        player->UpdateStatBuffMod(STAT_STAMINA);
        break;
    }
    case ITEM_MOD_DEFENSE_SKILL_RATING:
        player->ApplyRatingMod(CR_DEFENSE_SKILL, int32(val * combatRatingMultiplier), apply);
        break;
    case ITEM_MOD_DODGE_RATING:
        player->ApplyRatingMod(CR_DODGE, int32(val * combatRatingMultiplier), apply);
        break;
    case ITEM_MOD_PARRY_RATING:
        player->ApplyRatingMod(CR_PARRY, int32(val * combatRatingMultiplier), apply);
        break;
    case ITEM_MOD_BLOCK_RATING:
        player->ApplyRatingMod(CR_BLOCK, int32(val * combatRatingMultiplier), apply);
        break;
    case ITEM_MOD_HIT_MELEE_RATING:
        player->ApplyRatingMod(CR_HIT_MELEE, int32(val * combatRatingMultiplier), apply);
        break;
    case ITEM_MOD_HIT_RANGED_RATING:
        player->ApplyRatingMod(CR_HIT_RANGED, int32(val * combatRatingMultiplier), apply);
        break;
    case ITEM_MOD_HIT_SPELL_RATING:
        player->ApplyRatingMod(CR_HIT_SPELL, int32(val * combatRatingMultiplier), apply);
        break;
    case ITEM_MOD_CRIT_MELEE_RATING:
        player->ApplyRatingMod(CR_CRIT_MELEE, int32(val * combatRatingMultiplier), apply);
        break;
    case ITEM_MOD_CRIT_RANGED_RATING:
        player->ApplyRatingMod(CR_CRIT_RANGED, int32(val * combatRatingMultiplier), apply);
        break;
    case ITEM_MOD_CRIT_SPELL_RATING:
        player->ApplyRatingMod(CR_CRIT_SPELL, int32(val * combatRatingMultiplier), apply);
        break;
        // case ITEM_MOD_HIT_TAKEN_MELEE_RATING:
        //     ApplyRatingMod(CR_HIT_TAKEN_MELEE, int32(val), apply);
        //     break;
        // case ITEM_MOD_HIT_TAKEN_RANGED_RATING:
        //     ApplyRatingMod(CR_HIT_TAKEN_RANGED, int32(val), apply);
        //     break;
        // case ITEM_MOD_HIT_TAKEN_SPELL_RATING:
        //     ApplyRatingMod(CR_HIT_TAKEN_SPELL, int32(val), apply);
        //     break;
        // case ITEM_MOD_CRIT_TAKEN_MELEE_RATING:
        //     ApplyRatingMod(CR_CRIT_TAKEN_MELEE, int32(val), apply);
        //     break;
    case ITEM_MOD_CRIT_TAKEN_RANGED_RATING:
        player->ApplyRatingMod(CR_RESILIENCE_PLAYER_DAMAGE, int32(val), apply);
        break;
        // case ITEM_MOD_CRIT_TAKEN_SPELL_RATING:
        //     ApplyRatingMod(CR_CRIT_TAKEN_SPELL, int32(val), apply);
        //     break;
    case ITEM_MOD_HASTE_MELEE_RATING:
        player->ApplyRatingMod(CR_HASTE_MELEE, int32(val), apply);
        break;
    case ITEM_MOD_HASTE_RANGED_RATING:
        player->ApplyRatingMod(CR_HASTE_RANGED, int32(val), apply);
        break;
    case ITEM_MOD_HASTE_SPELL_RATING:
        player->ApplyRatingMod(CR_HASTE_SPELL, int32(val), apply);
        break;
    case ITEM_MOD_HIT_RATING:
        player->ApplyRatingMod(CR_HIT_MELEE, int32(val * combatRatingMultiplier), apply);
        player->ApplyRatingMod(CR_HIT_RANGED, int32(val * combatRatingMultiplier), apply);
        player->ApplyRatingMod(CR_HIT_SPELL, int32(val * combatRatingMultiplier), apply);
        break;
    case ITEM_MOD_CRIT_RATING:
        player->ApplyRatingMod(CR_CRIT_MELEE, int32(val * combatRatingMultiplier), apply);
        player->ApplyRatingMod(CR_CRIT_RANGED, int32(val * combatRatingMultiplier), apply);
        player->ApplyRatingMod(CR_CRIT_SPELL, int32(val * combatRatingMultiplier), apply);
        break;
        // case ITEM_MOD_HIT_TAKEN_RATING: // Unused since 3.3.5
        //     ApplyRatingMod(CR_HIT_TAKEN_MELEE, int32(val), apply);
        //     ApplyRatingMod(CR_HIT_TAKEN_RANGED, int32(val), apply);
        //     ApplyRatingMod(CR_HIT_TAKEN_SPELL, int32(val), apply);
        //     break;
        // case ITEM_MOD_CRIT_TAKEN_RATING: // Unused since 3.3.5
        //     ApplyRatingMod(CR_CRIT_TAKEN_MELEE, int32(val), apply);
        //     ApplyRatingMod(CR_CRIT_TAKEN_RANGED, int32(val), apply);
        //     ApplyRatingMod(CR_CRIT_TAKEN_SPELL, int32(val), apply);
        //     break;
    case ITEM_MOD_RESILIENCE_RATING:
        player->ApplyRatingMod(CR_RESILIENCE_PLAYER_DAMAGE, int32(val * combatRatingMultiplier), apply);
        break;
    case ITEM_MOD_HASTE_RATING:
        player->ApplyRatingMod(CR_HASTE_MELEE, int32(val * combatRatingMultiplier), apply);
        player->ApplyRatingMod(CR_HASTE_RANGED, int32(val * combatRatingMultiplier), apply);
        player->ApplyRatingMod(CR_HASTE_SPELL, int32(val * combatRatingMultiplier), apply);
        break;
    case ITEM_MOD_EXPERTISE_RATING:
        player->ApplyRatingMod(CR_EXPERTISE, int32(val * combatRatingMultiplier), apply);
        break;
    case ITEM_MOD_ATTACK_POWER:
        player->HandleStatFlatModifier(UNIT_MOD_ATTACK_POWER, TOTAL_VALUE, float(val), apply);
        player->HandleStatFlatModifier(UNIT_MOD_ATTACK_POWER_RANGED, TOTAL_VALUE, float(val), apply);
        break;
    case ITEM_MOD_RANGED_ATTACK_POWER:
        player->HandleStatFlatModifier(UNIT_MOD_ATTACK_POWER_RANGED, TOTAL_VALUE, float(val), apply);
        break;
    case ITEM_MOD_VERSATILITY:
        player->ApplyRatingMod(CR_VERSATILITY_DAMAGE_DONE, int32(val * combatRatingMultiplier), apply);
        player->ApplyRatingMod(CR_VERSATILITY_DAMAGE_TAKEN, int32(val * combatRatingMultiplier), apply);
        player->ApplyRatingMod(CR_VERSATILITY_HEALING_DONE, int32(val * combatRatingMultiplier), apply);
        break;
    case ITEM_MOD_MANA_REGENERATION:
        player->ApplyManaRegenBonus(int32(val), apply);
        break;
    case ITEM_MOD_ARMOR_PENETRATION_RATING:
        player->ApplyRatingMod(CR_ARMOR_PENETRATION, int32(val), apply);
        break;
    case ITEM_MOD_SPELL_POWER:
        player->ApplySpellPowerBonus(int32(val), apply);
        break;
    case ITEM_MOD_HEALTH_REGEN:
        player->ApplyHealthRegenBonus(int32(val), apply);
        break;
    case ITEM_MOD_SPELL_PENETRATION:
        player->ApplySpellPenetrationBonus(val, apply);
        break;
    case ITEM_MOD_MASTERY_RATING:
        player->ApplyRatingMod(CR_MASTERY, int32(val * combatRatingMultiplier), apply);
        break;
    case ITEM_MOD_EXTRA_ARMOR:
        player->HandleStatFlatModifier(UNIT_MOD_ARMOR, TOTAL_VALUE, float(val), apply);
        break;
    case ITEM_MOD_FIRE_RESISTANCE:
        player->HandleStatFlatModifier(UNIT_MOD_RESISTANCE_FIRE, BASE_VALUE, float(val), apply);
        break;
    case ITEM_MOD_FROST_RESISTANCE:
        player->HandleStatFlatModifier(UNIT_MOD_RESISTANCE_FROST, BASE_VALUE, float(val), apply);
        break;
    case ITEM_MOD_HOLY_RESISTANCE:
        player->HandleStatFlatModifier(UNIT_MOD_RESISTANCE_HOLY, BASE_VALUE, float(val), apply);
        break;
    case ITEM_MOD_SHADOW_RESISTANCE:
        player->HandleStatFlatModifier(UNIT_MOD_RESISTANCE_SHADOW, BASE_VALUE, float(val), apply);
        break;
    case ITEM_MOD_NATURE_RESISTANCE:
        player->HandleStatFlatModifier(UNIT_MOD_RESISTANCE_NATURE, BASE_VALUE, float(val), apply);
        break;
    case ITEM_MOD_ARCANE_RESISTANCE:
        player->HandleStatFlatModifier(UNIT_MOD_RESISTANCE_ARCANE, BASE_VALUE, float(val), apply);
        break;
    case ITEM_MOD_PVP_POWER:
        player->ApplyRatingMod(CR_PVP_POWER, int32(val), apply);
        break;
    case ITEM_MOD_CORRUPTION:
        player->ApplyRatingMod(CR_CORRUPTION, int32(val), apply);
        break;
    case ITEM_MOD_CORRUPTION_RESISTANCE:
        player->ApplyRatingMod(CR_CORRUPTION_RESISTANCE, int32(val), apply);
        break;
    case ITEM_MOD_CR_SPEED:
        player->ApplyRatingMod(CR_SPEED, int32(val * combatRatingMultiplier), apply);
        break;
    case ITEM_MOD_CR_LIFESTEAL:
        player->ApplyRatingMod(CR_LIFESTEAL, int32(val * combatRatingMultiplier), apply);
        break;
    case ITEM_MOD_CR_AVOIDANCE:
        player->ApplyRatingMod(CR_AVOIDANCE, int32(val * combatRatingMultiplier), apply);
        break;
    case ITEM_MOD_CR_STURDINESS:
        player->ApplyRatingMod(CR_STURDINESS, int32(val * combatRatingMultiplier), apply);
        break;
    case ITEM_MOD_AGI_STR_INT:
        player->HandleStatFlatModifier(UNIT_MOD_STAT_AGILITY, BASE_VALUE, float(val), apply);
        player->HandleStatFlatModifier(UNIT_MOD_STAT_STRENGTH, BASE_VALUE, float(val), apply);
        player->HandleStatFlatModifier(UNIT_MOD_STAT_INTELLECT, BASE_VALUE, float(val), apply);
        player->UpdateStatBuffMod(STAT_AGILITY);
        player->UpdateStatBuffMod(STAT_STRENGTH);
        player->UpdateStatBuffMod(STAT_INTELLECT);
        break;
    case ITEM_MOD_AGI_STR:
        player->HandleStatFlatModifier(UNIT_MOD_STAT_AGILITY, BASE_VALUE, float(val), apply);
        player->HandleStatFlatModifier(UNIT_MOD_STAT_STRENGTH, BASE_VALUE, float(val), apply);
        player->UpdateStatBuffMod(STAT_AGILITY);
        player->UpdateStatBuffMod(STAT_STRENGTH);
        break;
    case ITEM_MOD_AGI_INT:
        player->HandleStatFlatModifier(UNIT_MOD_STAT_AGILITY, BASE_VALUE, float(val), apply);
        player->HandleStatFlatModifier(UNIT_MOD_STAT_INTELLECT, BASE_VALUE, float(val), apply);
        player->UpdateStatBuffMod(STAT_AGILITY);
        player->UpdateStatBuffMod(STAT_INTELLECT);
        break;
    case ITEM_MOD_STR_INT:
        player->HandleStatFlatModifier(UNIT_MOD_STAT_STRENGTH, BASE_VALUE, float(val), apply);
        player->HandleStatFlatModifier(UNIT_MOD_STAT_INTELLECT, BASE_VALUE, float(val), apply);
        player->UpdateStatBuffMod(STAT_STRENGTH);
        player->UpdateStatBuffMod(STAT_INTELLECT);
        break;
    }
}

void AACenter::AA_EventMapStart(Player* eventer, AA_Event_Map conf)
{
    if ((conf.mapid == -1 && conf.zoneid == -1 && conf.areaid == -1) ||
        (int32)eventer->GetMapId() == conf.mapid ||
        (int32)eventer->GetZoneId() == conf.zoneid ||
        (int32)eventer->GetAreaId() == conf.areaid) {
        if (conf.need > 0) {
            if (!aaCenter.M_CanNeed(eventer, conf.need)) {
                return;
            }
        }
        if (conf.gm != "" && conf.gm != "0") {
            aaCenter.AA_DoCommand(eventer, conf.gm.c_str());
        }
        if (conf.need > 0) {
            aaCenter.M_Need(eventer, conf.need);
        }
    }
}

bool AACenter::AA_EventStart(Player* eventer, uint32 eventid)
{
    AA_Event_Conf conf = aaCenter.aa_event_confs[eventid];
    if (conf.id == 0) return false;
    try {
        if (rand() % 100 >= conf.chance) { return false; }
        std::set<Player*> players;
        players.clear();
        if (conf.target == 3) { // 全服触发
            players = GetOnlinePlayers();
        }
        else if (conf.target == 4) { // 随机一个玩家
            const HashMapHolder<Player>::MapType& m = ObjectAccessor::GetPlayers();
            for (HashMapHolder<Player>::MapType::const_iterator it = m.begin(); it != m.end(); ++it)
            {
                if (Player* player = it->second)
                {
                    if (!player->IsInWorld() || !player->GetSession())
                        continue;
                    players.insert(player);
                    break;
                }
            }
        }
        else {
            if (!eventer) return false;
            if (!eventer->IsInWorld()) return false;
            players.insert(eventer);
            switch (conf.target) {
            case 0: // 个人
            {
            }
            break;
            case 1: // 团队
            {
                if (eventer->GetGroup()) {
                    Group::MemberSlotList const& members = eventer->GetGroup()->GetMemberSlots();
                    for (Group::MemberSlotList::const_iterator itr = members.begin(); itr != members.end(); ++itr)
                    {
                        if (Player* p = ObjectAccessor::FindPlayer((*itr).guid)) {
                            if (!p->IsInWorld()) { continue; }
                            players.insert(p);
                        }
                    }
                }
            }
            break;
            case 2: // 阵营
            {
                TeamId team = eventer->GetTeamId();
                const HashMapHolder<Player>::MapType& m = ObjectAccessor::GetPlayers();
                std::set<Player*> players;
                players.clear();
                for (HashMapHolder<Player>::MapType::const_iterator it = m.begin(); it != m.end(); ++it)
                {
                    if (Player* player = it->second)
                    {
                        if (!player->IsInWorld()) { continue; }
                        if (team != player->GetTeamId()) { continue; }
                        players.insert(player);
                    }
                }
            }
            break;
            default:
                break;
            }
        }

        for (Player* player : players) {
            AA_Message aa_message;
            aa_message.target_player = player;
            if (conf.need > 0) {
                if (!aaCenter.M_CanNeed(player, conf.need)) {
                    continue;
                }
                else {
                    aaCenter.M_Need(player, conf.need);
                }
            }
            if (conf.gm != "" && conf.gm != "0") {
                aaCenter.AA_DoCommand(player, conf.gm.c_str());
            }
            if (conf.notice > 0) { // 公告待写
                AA_Notice notice = aaCenter.aa_notices[conf.notice];
                aaCenter.AA_SendNotice(player, notice, true, aa_message);
            }
            if (eventer && eventer->IsInWorld()) {
                aaCenter.AA_SendEvent(player, conf.title, conf.text, conf.id, eventer->GetGUID());
            }
            else {
                aaCenter.AA_SendEvent(player, conf.title, conf.text, conf.id);
            }
        }

        return true;
    }
    catch (std::exception const& e) {}
    return false;
}

void AACenter::AA_SendEvent(Player* player, std::string title, std::string text, uint32 id, ObjectGuid guid)
{
    time_t timep;
    time(&timep); /*当前time_t类型UTC时间*/
    if (title != "" || text != "") {
        AA_Message aa_message;
        aa_message.target_player = player;
        //{id,time,"title","text"}
        title = GetMyInfo(player, title, aa_message, true);
        text = GetMyInfo(player, text, aa_message, true);
        std::string msg = "{" + std::to_string(id) + "," + std::to_string(timep + player->GetGUIDLow()) + ",\"" + title + "\"," + "\"" + text + "\"}";
        aaCenter.M_SendClientAddonData(player, "202", msg);
    }
    if (id > 0 && player && player->IsInWorld()) {
        uint32 time = timep + player->GetGUIDLow();
        aaCenter.aa_event_stats[id][time] = 1;
        if (guid != ObjectGuid::Empty) {
            if (Player* p = ObjectAccessor::FindPlayer(guid)) {
                if (p->IsInWorld() && p->GetMap()) {
                    AA_Caiji_Zuobiao conf;
                    conf.text = "-1";
                    conf.map = p->GetMapId();
                    conf.position_x = p->GetPositionX();
                    conf.position_y = p->GetPositionY();
                    conf.position_z = p->GetPositionZ();
                    conf.orientation = p->GetOrientation();
                    aaCenter.aa_event_senders[time] = conf;
                }
            }
        }
    }
}

void AACenter::AA_CallBack_Event(Player* eventer, uint32 eventid, uint32 timep, uint32 button)
{
    //    <playerid, <eventtime, stat>> stat=1未处理 2完成 3取消
    //    button 1完成 2取消
    try {
        uint32 event_stat = aaCenter.aa_event_stats[eventid][timep];

        switch (button) {
        case 1: // 点击完成
        {
            if (event_stat != 1) {
                return;
            }
            AA_Event_Conf conf = aaCenter.aa_event_confs[eventid];

            if (conf.id == 0) return;

            if (!eventer) return;
            if (!eventer->IsInWorld()) return;

            if (conf.done_need > 0) {
                if (!aaCenter.M_CanNeed(eventer, conf.done_need)) {
                    return;
                }
                else {
                    aaCenter.M_Need(eventer, conf.done_need);
                }
            }
            if (conf.done_gm != "" && conf.done_gm != "0") {
                aaCenter.AA_DoCommand(eventer, conf.done_gm.c_str());
                if (conf.done_gm.find("传送 触发者") != string::npos) {
                    AA_Caiji_Zuobiao z_conf = aaCenter.aa_event_senders[timep];
                    eventer->TeleportTo(z_conf.map, z_conf.position_x, z_conf.position_y, z_conf.position_z, z_conf.orientation);
                }
            }
            if (conf.done_notice > 0) { // 公告待写
                AA_Message aa_message;
                AA_Notice notice = aaCenter.aa_notices[conf.done_notice];
                aaCenter.AA_SendNotice(eventer, notice, true, aa_message);
            }
            aaCenter.aa_event_stats[eventid][timep + eventer->GetGUIDLow()] = 2;
        }
        break;
        case 2: // 点击取消
        {
            aaCenter.aa_event_stats[eventid][timep + eventer->GetGUIDLow()] = 3;
        }
        break;
        default:
            break;
        }
    }
    catch (std::exception const& e) {}
}

std::set<uint32> AACenter::AA_GetAis(Unit* att, std::string eventtype)
{
    std::set<uint32> aisets;
    aisets.clear();
    if (!att || !att->IsInWorld() || (att->GetTypeId() != TYPEID_UNIT && att->GetTypeId() != TYPEID_PLAYER)) {
        return aisets;
    }
    if (eventtype == "0" || eventtype == "") {
        return aisets;
    }
    std::vector<std::string> eventtypes; eventtypes.clear();
    aaCenter.AA_StringToVectorString(eventtype, eventtypes, ",");
    if (eventtypes.empty()) {
        return aisets;
    }
    Unit* attacker = const_cast<Unit*>(att);
    if (Creature* creature = attacker->ToCreature()) {
        if (!creature->GetOwner() && !creature->IsTotem()) {
            //生物
            {
                AA_Ai_Creature conf = aaCenter.aa_ai_creatures[creature->GetEntry()];
                if (conf.ais != "" && conf.ais != "0") {
                    uint32 aizu = aaCenter.AA_StringRandom(conf.ais);
                    if (aizu > 0) {
                        std::set<uint32> ais = aaCenter.aa_ai_zus[aizu];
                        for (uint32 ai : ais) {
                            AA_Ai conf = aaCenter.aa_ais[ai];
                            if (std::find(eventtypes.begin(), eventtypes.end(), conf.event_type) != eventtypes.end()) {
                                aisets.insert(ai);
                            }
                        }
                    }
                }
            }
            {
                //生物自身绑定的属性ai
                uint32 aa_id = creature->aa_id;
                if (aa_id > 0) {
                    AA_Creature conf = aaCenter.aa_creatures[aa_id];
                    if (conf.ais != "" && conf.ais != "0") {
                        uint32 aizu = aaCenter.AA_StringRandom(conf.ais);
                        if (aizu > 0) {
                            std::set<uint32> ais = aaCenter.aa_ai_zus[aizu];
                            for (uint32 ai : ais) {
                                AA_Ai conf = aaCenter.aa_ais[ai];
                                if (std::find(eventtypes.begin(), eventtypes.end(), conf.event_type) != eventtypes.end()) {
                                    aisets.insert(ai);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    else if (Player* player = attacker->ToPlayer()) {
        //物品
        for (auto i = aaCenter.aa_ai_items.begin(); i != aaCenter.aa_ai_items.end(); ++i)
        {
            if (i->first == 0) {
                continue;
            }
            if (i->second.ais == "" || i->second.ais == "0") {
                continue;
            }
            AA_Item_Bag b_conf = aaCenter.aa_item_bags[i->first];
            //放背包生效
            if (std::find(aaCenter.aa_allitems[player->GetGUID()].begin(), aaCenter.aa_allitems[player->GetGUID()].end(), i->first) != aaCenter.aa_allitems[player->GetGUID()].end())
            {
                if (i->second.ais != "" && i->second.ais != "0") {
                    uint32 aizu = aaCenter.AA_StringRandom(i->second.ais);
                    if (aizu > 0) {
                        std::set<uint32> ais = aaCenter.aa_ai_zus[aizu];
                        for (uint32 ai : ais) {
                            AA_Ai conf = aaCenter.aa_ais[ai];
                            if (std::find(eventtypes.begin(), eventtypes.end(), conf.event_type) != eventtypes.end()) {
                                aisets.insert(ai);
                            }
                        }
                    }
                }
            }
        }

        std::set<uint32> allItemsSpells = aaCenter.aa_allspells[player->GetGUID()];
        if (allItemsSpells.size() > 0) {
            //_自定义ai_物品技能带ai
            for (auto i = aaCenter.aa_ai_spell_items.begin(); i != aaCenter.aa_ai_spell_items.end(); ++i)
            {
                if (i->first == 0) {
                    continue;
                }
                if (i->second.ais == "" || i->second.ais == "0") {
                    continue;
                }

                if (allItemsSpells.find(i->first) == allItemsSpells.end()) {
                    continue;
                }

                uint32 aizu = aaCenter.AA_StringRandom(i->second.ais);
                if (aizu > 0) {
                    std::set<uint32> ais = aaCenter.aa_ai_zus[aizu];
                    for (uint32 ai : ais) {
                        AA_Ai conf = aaCenter.aa_ais[ai];
                        if (std::find(eventtypes.begin(), eventtypes.end(), conf.event_type) != eventtypes.end()) {
                            aisets.insert(ai);
                        }
                    }
                }
            }
        }
    }
    //光环
    for (auto i = aaCenter.aa_ai_spells.begin(); i != aaCenter.aa_ai_spells.end(); ++i)
    {
        if (i->first == 0) {
            continue;
        }
        if (i->second.ais == "" || i->second.ais == "0") {
            continue;
        }
        //是否有光环
        if (!attacker->HasAura(i->first)) {
            continue;
        }

        uint32 aizu = aaCenter.AA_StringRandom(i->second.ais);
        if (aizu > 0) {
            std::set<uint32> ais = aaCenter.aa_ai_zus[aizu];
            for (uint32 ai : ais) {
                AA_Ai conf = aaCenter.aa_ais[ai];
                if (std::find(eventtypes.begin(), eventtypes.end(), conf.event_type) != eventtypes.end()) {
                    aisets.insert(ai);
                }
            }
        }
    }
    //_自定义ai_学习技能带ai
    for (auto i = aaCenter.aa_ai_spell_learns.begin(); i != aaCenter.aa_ai_spell_learns.end(); ++i)
    {
        if (i->first == 0) {
            continue;
        }
        if (i->second.ais == "" || i->second.ais == "0") {
            continue;
        }
        //是否有技能
        if (!attacker->HasSpell(i->first)) {
            continue;
        }

        uint32 aizu = aaCenter.AA_StringRandom(i->second.ais);
        if (aizu > 0) {
            std::set<uint32> ais = aaCenter.aa_ai_zus[aizu];
            for (uint32 ai : ais) {
                AA_Ai conf = aaCenter.aa_ais[ai];
                if (std::find(eventtypes.begin(), eventtypes.end(), conf.event_type) != eventtypes.end()) {
                    aisets.insert(ai);
                }
            }
        }
    }
    //地图
    for (auto aimap : aaCenter.aa_ai_maps)
    {
        if (aimap.ais == "0" || aimap.ais == "" || aimap.target == "") {
            continue;
        }
        if (aimap.target == "生物") {
            if (attacker->GetTypeId() != TYPEID_UNIT) {
                continue;
            }
            if (attacker->IsPet() || attacker->IsTotem() || attacker->IsVehicle()) {
                continue;
            }
        }
        if (aimap.target == "玩家") {
            if (attacker->GetTypeId() != TYPEID_PLAYER) {
                continue;
            }
        }
        if (aimap.target == "宠物") {
            if (!attacker->IsPet()) {
                continue;
            }
        }
        if ((aimap.map == -1 && aimap.zone == -1 && aimap.area == -1) ||
            aimap.map == (int32)attacker->GetMapId() || aimap.zone == (int32)attacker->GetZoneId() ||
            aimap.area == (int32)attacker->GetAreaId()) {
            if (aimap.ais != "" && aimap.ais != "0") {
                uint32 aizu = aaCenter.AA_StringRandom(aimap.ais);
                if (aizu > 0) {
                    std::set<uint32> ais = aaCenter.aa_ai_zus[aizu];
                    for (uint32 ai : ais) {
                        AA_Ai conf = aaCenter.aa_ais[ai];
                        if (std::find(eventtypes.begin(), eventtypes.end(), conf.event_type) != eventtypes.end()) {
                            aisets.insert(ai);
                        }
                    }
                }
            }
        }
    }

    //删除冷却逻辑，不让刷新冷却的时候 有循环
    std::unordered_map<uint32, uint32>::iterator iter;
    ObjectGuid guid = attacker->GetGUID();
    if (m_aiTimes.find(guid) != m_aiTimes.end()) {
        for (auto iter = m_aiTimes[guid].begin(); iter != m_aiTimes[guid].end();)
        {
            if (aisets.find(iter->first) == aisets.end()) {
                AA_Ai conf = aaCenter.aa_ais[iter->first];
                if (aaCenter.m_aiTimes[guid][iter->first] > conf.event_cooldown * 1000)
                {
                    iter = m_aiTimes[guid].erase(iter);
                }
                else {
                    iter++;
                }
            }
            else {
                iter++;
            }
        }
    }
    return aisets;
}

void AACenter::AA_AiStart(Unit* attacker, Unit* victim, uint32 aiid, int32 value, bool isOK)
{
    if (!aaCenter.AA_VerifyCode("a5b")) {
        return;
    }
    if (!attacker || !attacker->IsInWorld()) {
        return;
    }
    ObjectGuid guid = attacker->GetGUID();
    try {
        AA_Ai conf = aaCenter.aa_ais[aiid];
        if (conf.id == 0) {
            return;
        }
        if (!isOK) {
            if (!roll_chance_f(conf.event_chance)) {
                return;
            }
            //冷却中
            if (m_aiTimes[guid].find(conf.id) != m_aiTimes[guid].end() && m_aiTimes[guid][conf.id] >= 1 && m_aiTimes[guid][conf.id] < conf.event_cooldown * 1000) {
                return;
            }
            //公共冷却中
            if (m_aiGGTimes[guid].find(conf.gg_zu) != m_aiGGTimes[guid].end() && m_aiGGTimes[guid][conf.gg_zu] >= 1 && m_aiGGTimes[guid][conf.gg_zu] < conf.gg_cooldown * 1000) {
                return;
            }
            //公共冷却
            bool ggOk = false;
            //第一次进入公共冷却
            if (conf.gg_zu > 0) {
                if (m_aiGGTimes.find(guid) == m_aiGGTimes.end() || m_aiGGTimes[guid].find(conf.gg_zu) == m_aiGGTimes[guid].end())
                {
                    ggOk = true;
                }
                else if (m_aiGGTimes[guid][conf.gg_zu] >= 1 && m_aiGGTimes[guid][conf.gg_zu] >= conf.gg_cooldown * 1000) {//再次进入公共冷却
                    ggOk = true;
                }
            }
            if (conf.gg_zu == 0) {
                ggOk = true;
            }
            if (!ggOk) {
                return;
            }
            if (conf.gg_zu > 0) {
                m_aiGGTimes[guid][conf.gg_zu] = 1;
            }

            //第一次进入冷却
            if (m_aiTimes.find(guid) == m_aiTimes.end() || m_aiTimes[guid].find(conf.id) == m_aiTimes[guid].end()) {
                m_aiTimes[guid][conf.id] = 1;
            }
            else if (m_aiTimes[guid][conf.id] >= 1 && m_aiTimes[guid][conf.id] >= conf.event_cooldown * 1000) { //再次进入冷却
                m_aiTimes[guid][conf.id] = 1;
            }
            else {
                return;
            }
        }

        std::set<Unit*> targets;
        targets.clear();
        if (conf.action_target == "自身") {
            targets.insert(attacker);
        }
        else if (conf.action_target == "目标") {
            if (victim == nullptr) {
                if (attacker->GetTypeId() == TYPEID_UNIT) {
                    Creature* c = attacker->ToCreature();
                    victim = ObjectAccessor::GetUnit(*c, c->GetTarget());
                }
                else if (attacker->GetTypeId() == TYPEID_PLAYER) {
                    Player* p = attacker->ToPlayer();
                    victim = p->GetSelectedUnit();
                    if (victim == nullptr) {
                        victim = p->GetSelectedPlayer();
                    }
                }
                if (victim == nullptr) {
                    victim = attacker;
                }
            }
            if (victim != nullptr && victim->IsInWorld()) {
                targets.insert(victim);
            }
        }
        else if (conf.action_target == "主人") {
            if (attacker->GetTypeId() == TYPEID_UNIT) {
                if (Creature* creature = attacker->ToCreature()) {
                    if (Unit* u = attacker->GetOwner()) {
                        if (u->ToPlayer() && u->IsInWorld()) {
                            targets.insert(u);
                        }
                    }
                }
            }
        }
        else if (conf.action_target == "宠物") {
            if (attacker->GetTypeId() == TYPEID_PLAYER) {
                Player* p = attacker->ToPlayer();
                if (Pet* pet = p->GetPet()) {
                    if (pet->IsInWorld()) {
                        targets.insert(pet);
                    }
                }
            }
        }
        else if (conf.action_target == "队友") {
            if (attacker->GetTypeId() == TYPEID_PLAYER) {
                Player* pg = attacker->ToPlayer();
                if (pg->GetGroup()) {
                    Group::MemberSlotList const& members = pg->GetGroup()->GetMemberSlots();
                    for (Group::MemberSlotList::const_iterator itr = members.begin(); itr != members.end(); ++itr)
                    {
                        if (Player* p = ObjectAccessor::FindPlayer((*itr).guid)) {
                            if (!p->IsInWorld()) { continue; }
                            targets.insert(p);
                        }
                    }
                }
            }
        }
        if (targets.empty()) {
            return;
        }
        std::vector<int32> action_target_ids; action_target_ids.clear();
        aaCenter.AA_StringToVectorInt(conf.action_target_ids, action_target_ids, ",");
        if (!action_target_ids.empty()) {
            for (auto it = targets.begin(); it != targets.end();)
            {
                if (Player* p = (*it)->ToPlayer()) {
                    if (std::find(action_target_ids.begin(), action_target_ids.end(), p->GetClass()) == action_target_ids.end()) {
                        it = targets.erase(it);
                    }
                    else {
                        it++;
                    }
                }
            }
        }
        for (auto unit : targets) {
            if (!unit || !unit->IsInWorld() || !attacker || !attacker->IsInWorld()) {
                continue;
            }
            //'施放技能','说话','改变血量','改变属性','改变等级','随机取下装备','随机抢夺目标装备','召唤生物','奖励','消耗'
            if (conf.action_type == "施放技能") {
                if (!unit->IsAlive() || (conf.action_param4 == 0 && unit->IsMounted())) {
                    return;
                }
                if (conf.action_param2 == 0) {
                    if (conf.action_param1 > 0) {
                        if (conf.action_param3 > 0) { //不检测重复
                            attacker->aa_spells[conf.action_param1] = true;
                            attacker->CastSpell(unit, conf.action_param1, true);
                        }
                        else {
                            if (!unit->HasAura(conf.action_param1)) {
                                attacker->aa_spells[conf.action_param1] = true;
                                attacker->CastSpell(unit, conf.action_param1, true);
                            }
                        }
                    }
                }
                else if (conf.action_param2 == 1) {
                    if (conf.action_param5 != "" && conf.action_param5 != "0") {
                        uint32 spellid = aaCenter.AA_StringRandom(conf.action_param5);
                        attacker->aa_spells[spellid] = true;
                        attacker->CastSpell(unit, spellid, true);
                    }
                    else {
                        if (conf.action_param1 > 0) {
                            if (conf.action_param3 > 0) { //不检测重复
                                attacker->aa_spells[conf.action_param1] = true;
                                attacker->CastSpell(unit, conf.action_param1, true);
                            }
                            else {
                                if (!unit->HasAura(conf.action_param1)) {
                                    attacker->aa_spells[conf.action_param1] = true;
                                    attacker->CastSpell(unit, conf.action_param1, true);
                                }
                            }
                        }
                    }
                }
                else if (conf.action_param2 == 2) {
                    if (conf.action_param5 != "" && conf.action_param5 != "0") {
                        std::vector<int32> spells; spells.clear();
                        aaCenter.AA_StringToVectorInt(conf.action_param5, spells, ",");
                        for (auto spellid : spells) {
                            if (spellid > 0) {
                                if (conf.action_param3 > 0) { //不检测重复
                                    attacker->aa_spells[spellid] = true;
                                    attacker->CastSpell(unit, spellid, true);
                                }
                                else {
                                    if (!unit->HasAura(spellid)) {
                                        attacker->aa_spells[spellid] = true;
                                        attacker->CastSpell(unit, spellid, true);
                                    }
                                }
                            }
                        }
                    }
                    else {
                        if (conf.action_param1 > 0) {
                            if (conf.action_param3 > 0) { //不检测重复
                                attacker->aa_spells[conf.action_param1] = true;
                                attacker->CastSpell(unit, conf.action_param1, true);
                            }
                            else {
                                if (!unit->HasAura(conf.action_param1)) {
                                    attacker->aa_spells[conf.action_param1] = true;
                                    attacker->CastSpell(unit, conf.action_param1, true);
                                }
                            }
                        }
                    }
                }
                else if (conf.action_param2 == 3) {
                }
                else {
                    if (conf.action_param5 != "" && conf.action_param5 != "0") {
                        uint32 spellid = aaCenter.AA_StringRandom(conf.action_param5);
                        attacker->aa_spells[spellid] = true;
                        attacker->CastSpell(unit, spellid, true);
                    }
                    else {
                        if (conf.action_param1 > 0) {
                            attacker->aa_spells[conf.action_param1] = true;
                            attacker->CastSpell(unit, conf.action_param1, true);
                        }
                    }
                }
            }
            else if (conf.action_type == "出生光环") {
                if (!unit->IsAlive()) {
                    for (auto spellid : unit->aa_auras[conf.id]) {
                        if (unit->HasAura(spellid)) {
                            unit->RemoveAura(spellid);
                        }
                    }
                    unit->aa_auras[conf.id].clear();
                    continue;
                }
                int32 spellcount = conf.action_param2 > 0 ? conf.action_param2 : 1;
                if (spellcount <= 0) {
                    return;
                }
                if ((int32)unit->aa_auras[conf.id].size() < spellcount) {
                    if (conf.action_param5 != "" && conf.action_param5 != "0") {
                        std::vector<int32> spells; spells.clear();
                        aaCenter.AA_StringToVectorInt(conf.action_param5, spells, ",");
                        for (auto it = spells.begin(); it != spells.end();)
                        {
                            if (std::find(unit->aa_auras[conf.id].begin(), unit->aa_auras[conf.id].end(), *it) != unit->aa_auras[conf.id].end()) {
                                spells.erase(it);
                            }
                            else {
                                it++;
                            }
                        }
                        int32 index = rand() % spells.size();
                        uint32 spellid = spells[index];
                        unit->aa_auras[conf.id].insert(spellid);
                    }
                    else if (conf.action_param1 > 0) {
                        unit->aa_auras[conf.id].insert(conf.action_param1);
                    }
                }
                for (uint32 spellid : unit->aa_auras[conf.id]) {
                    if (!unit->HasAura(spellid)) {
                        attacker->AddAura(spellid, unit);
                    }
                }
            }
            else if (conf.action_type == "说话") {
                if (!unit->IsAlive()) {
                    return;
                }
                if (conf.action_param5 != "") {
                    if (unit->GetTypeId() == TYPEID_PLAYER) {
                        Player* p = unit->ToPlayer();
                        p->Say(conf.action_param5, LANG_UNIVERSAL);
                    }
                    else if (unit->GetTypeId() == TYPEID_UNIT) {
                        Creature* c = unit->ToCreature();
                        c->Say(conf.action_param5.c_str(), LANG_UNIVERSAL, nullptr);
                    }
                }
            }
            else if (conf.action_type == "改变血量") {
                if (!unit->IsAlive()) {
                    return;
                }
                int32 val = 0;
                if (conf.action_param1 != 0) {
                    val += conf.action_param1;
                }
                if (conf.action_param2 != 0) {
                    val += (unit->GetHealth() * (conf.action_param2 / 100.0));
                }
                val += unit->GetHealth();
                if (val < 1) {
                    attacker->Kill(attacker, unit);
                }
                else {
                    unit->SetHealth(val);
                }
                int32 valm = 0;
                if (conf.action_param3 != 0) {
                    valm += conf.action_param3;
                }
                if (conf.action_param4 != 0) {
                    valm += (unit->GetMaxHealth() * (conf.action_param4 / 100.0));
                }
                valm += unit->GetMaxHealth();
                if (valm < 1) {
                    attacker->Kill(attacker, unit);
                }
                else {
                    unit->SetMaxHealth(valm);
                }
            }
            else if (conf.action_type == "吸血") {
                if (!unit->IsAlive()) {
                    return;
                }
                int32 val = 0;
                if (conf.action_param1 == 0) {//0 造成伤害值
                    val = value;
                }
                else if (conf.action_param1 == 1) {//1 造成伤害的百分比
                    val = value * (conf.action_param2 / 100.0);
                }
                else if (conf.action_param1 == 2) {//2 当前生命值百分比
                    val = unit->GetHealth() * (conf.action_param2 / 100.0);
                }
                else if (conf.action_param1 == 3) {//3 最大生命值百分比
                    val = unit->GetMaxHealth() * (conf.action_param2 / 100.0);
                }
                else if (conf.action_param1 == 4) {//4 固定值
                    val = conf.action_param2;
                }
                if (val > 0) {
                    SpellInfo const* synhealInfo = sSpellMgr->GetSpellInfo(28839, DIFFICULTY_NONE);
                    HealInfo healInfo(unit, unit, val, synhealInfo, synhealInfo->GetSchoolMask());
                    unit->HealBySpell(healInfo);
                }
            }
            else if (conf.action_type == "转换属性") {
                if (!unit->IsAlive()) {
                    return;
                }
                if (unit->GetTypeId() == TYPEID_PLAYER) {
                    Player* player = unit->ToPlayer();
                    if (conf.event_param3 != 0) {
                        CombatRating type = (CombatRating)(conf.event_param1);
                        float value = player->GetRatingBonusValue(type);
                        float v = value * (conf.event_param3 / 100.0);
                        v = v > value ? value : v;
                        aaCenter.AddValue(player, conf.event_param2, v, true);
                        aaCenter.AddValue(player, conf.event_param1, v, false);
                    }
                }
            }
            else if (conf.action_type == "改变属性") {
                if (!unit->IsAlive()) {
                    return;
                }
                if (unit->GetTypeId() == TYPEID_PLAYER) {
                    Player* player = unit->ToPlayer();
                    if (conf.action_param2 != 0 || conf.action_param3 != 0) {
                        CombatRating type = (CombatRating)(conf.action_param1);
                        float value = player->GetRatingBonusValue(type);
                        float v = value * (conf.action_param3 / 100.0);
                        if (conf.action_param3 > 0) {
                            aaCenter.AddValue(player, conf.action_param1, v, true);
                        }
                        else if (conf.event_param3 < 0) {
                            aaCenter.AddValue(player, conf.action_param1, v, false);
                        }
                        if (conf.action_param2 > 0) {
                            aaCenter.AddValue(player, conf.action_param1, conf.action_param2, true);
                        }
                        else if (conf.action_param2 < 0) {
                            aaCenter.AddValue(player, conf.action_param1, conf.action_param2, false);
                        }
                    }
                }
            }
            else if (conf.action_type == "改变等级") {
                if (conf.action_param4 != 0) {
                    int8 level = unit->GetLevel() + conf.action_param4;
                    level = level > 0 ? level : 1;
                    unit->SetLevel(level);
                }
            }
            else if (conf.action_type == "随机取下装备") {
                if (!unit->IsAlive()) {
                    return;
                }
                if (attacker != unit && attacker->GetTypeId() == TYPEID_PLAYER && unit->GetTypeId() == TYPEID_PLAYER && conf.action_param1 != 0) {
                    Player* target = unit->ToPlayer();
                    Item* item = nullptr;
                    std::set<Item*> items = aaCenter.M_GetEquipItems(target);
                    item = *(items.begin());
                    aaCenter.AA_UnequipItem(target, item);
                }
            }
            else if (conf.action_type == "改变技能冷却") {
            }
            else if (conf.action_type == "随机抢夺目标装备") {
                if (!unit->IsAlive()) {
                    return;
                }
                if (attacker != unit && attacker->GetTypeId() == TYPEID_PLAYER && unit->GetTypeId() == TYPEID_PLAYER && conf.action_param1 != 0) {
                    Player* target = unit->ToPlayer();
                    Item* item = nullptr;
                    switch (conf.action_param1) {
                    case 1: // 身上
                    {
                        std::set<Item*> items = aaCenter.M_GetEquipItems(target);
                        item = *(items.begin());
                    }
                    break;
                    case 2: // 背包
                    {
                        std::set<Item*> items = aaCenter.M_GetBagItems(target);
                        item = *(items.begin());
                    }
                    break;
                    case 3: // 背包+身上
                    {
                        std::set<Item*> items = aaCenter.M_GetBagAndEquipItems(target);
                        item = *(items.begin());
                    }
                    break;

                    default:
                        break;
                    }
                    uint8 slot = aaCenter.AA_GetEmptyBag(attacker->ToPlayer());
                    if (slot > 0) {
                        item->SetOwnerGUID(guid);
                        item->SetSlot(slot);
                    }
                }
            }
            else if (conf.action_type == "召唤生物") {
                if (conf.action_param1 > 0) {
                    unit->SummonCreature(conf.action_param1, unit->GetPositionX() + conf.action_param2, unit->GetPositionY() + conf.action_param2, unit->GetPositionZ(), 0.0f, TEMPSUMMON_TIMED_DESPAWN, conf.action_param3 * 1000s);
                }
            }
            else if (conf.action_type == "奖励") {
                if (unit->GetTypeId() == TYPEID_PLAYER && conf.action_param1 > 0) {
                    Player* p = unit->ToPlayer();
                    aaCenter.M_Reward(p, conf.action_param1);
                }
            }
            else if (conf.action_type == "消耗") {
                if (unit->GetTypeId() == TYPEID_PLAYER && conf.action_param1 > 0) {
                    Player* p = unit->ToPlayer();
                    if (aaCenter.M_CanNeed(p, conf.action_param1)) {
                        aaCenter.M_Need(p, conf.action_param1);
                    }
                }
            }
            else if (conf.action_type == "GM命令") {
                if (conf.action_param5 != "" && conf.action_param5 != "0") {
                    if (Player* p = unit->ToPlayer()) {
                        aaCenter.AA_DoCommand(p, conf.action_param5.c_str());
                    }
                }
            }
        }
        if (conf.notice > 0) {
            AA_Message aa_message;
            AA_Notice notice = aaCenter.aa_notices[conf.notice];
            aaCenter.AA_SendNotice(attacker, notice, true, aa_message);
        }
    }
    catch (std::exception const& e) {}
}

std::set<Player*> AACenter::GetOnlinePlayers()
{
    const HashMapHolder<Player>::MapType& m = ObjectAccessor::GetPlayers();
    std::set<Player*> players;
    players.clear();
    for (HashMapHolder<Player>::MapType::const_iterator it = m.begin(); it != m.end(); ++it)
    {
        if (Player* player = it->second)
        {
            if (!player->GetSession()) {
                continue;
            }
            if (!player->IsInWorld())
                continue;
            players.insert(player);
        }
    }
    return players;
}

void AACenter::AA_TelScript(Player* player, AA_Teleport_Conf conf, Item *item) {
    if (conf.id == 0 || !player || !player->IsInWorld()) {
        return;
    }
    try {
        if (conf.script == "装备合成" ||
            conf.script == "宝石拆卸1号" ||
            conf.script == "宝石拆卸2号" ||
            conf.script == "宝石拆卸3号" ||
            conf.script == "装备解绑" ||
            conf.script == "使用物品成长券" ||
            conf.script == "使用物品强化券" ||
            conf.script == "使用物品鉴定券") {
            if (!player->aa_target_item || !player->aa_target_item->IsInWorld()) {
                return;
            }
            if (player->aa_target_item->IsEquipped()) {
                aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000请将物品放入背包再操作。"); return;
            }
        }
        if (conf.need > 0) {
            if (!M_CanNeed(player, conf.need)) {
                return;
            }
        }
        bool isOk = true;
        if (conf.gm != "" && conf.gm != "0") {
            isOk = AA_DoCommand(player, conf.gm.c_str());
        }
        if (conf.script == "m_dz_service") { // 锻造
            isOk = aaCenter.M_SendClientAddonData(player, "999", "1");
        }
        else if (conf.script == "m_pet_service") { // 宠物
            isOk = aaCenter.M_SendClientAddonData(player, "999", "2");
        }
        else if (conf.script == "m_level_service") { // 等级奖励
            isOk = aaCenter.M_SendClientAddonData(player, "999", "4");
        }
        else if (conf.script == "m_licai_service") { // 个人理财
            isOk = aaCenter.M_SendClientAddonData(player, "999", "5");
        }
        else if (conf.script == "m_shouchong_service") { // 首充奖励
            isOk = aaCenter.M_SendClientAddonData(player, "999", "6");
        }
        else if (conf.script == "m_leichong_service") { // 累充奖励
            isOk = aaCenter.M_SendClientAddonData(player, "999", "7");
        }
        else if (conf.script == "m_qiandao_service") { // 签到奖励
            isOk = aaCenter.M_SendClientAddonData(player, "999", "8");
        }
        else if (conf.script == "装备合成") { //装备合成
            isOk = AA_Hecheng(player);
        }
        else if (conf.script == "宝石拆卸1号") { //宝石拆卸1号
            isOk = AA_Chaixie(player, 0);
        }
        else if (conf.script == "宝石拆卸2号") { //宝石拆卸2号
            isOk = AA_Chaixie(player, 1);
        }
        else if (conf.script == "宝石拆卸3号") { //宝石拆卸3号
            isOk = AA_Chaixie(player, 2);
        }
        else if (conf.script == "宝石一键拆卸x") { //宝石拆卸3号
            isOk = AA_Chaixie(player, -1);
        }
        else if (conf.script == "装备解绑") { //装备解绑
            isOk = AA_Jiebang(player);
        }
        else if (conf.script == "使用物品成长券") { //装备成长经验卷
            isOk = AA_Chengzhang_Item_Do(player);
        }
        else if (conf.script == "使用物品强化券") { //装备强化等级卷
            isOk = AA_Qianghua_Item_Do(player);
        }
        else if (conf.script == "使用物品鉴定券") { //装备鉴定卷
            isOk = AA_Jianding_Item_Do(player);
        }
        else if (conf.script == "物品回收") {
            isOk = AA_Huishou(player);
        }
        if (true && conf.need > 0) {
            M_Need(player, conf.need);
        }
        player->m_guajis["Script"] = true;
    }
    catch (std::exception const& e) {}
}

bool AACenter::AA_Huishou(Player* player)
{
    if (!player || !player->IsInWorld()) {
        return false;
    }
    if (aaCenter.AA_GetEmptyBag(player) < 5) {
        aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000背包剩余空间不足5个。");
        return false;
    }
    bool isOk = false;
    if (player->aa_item && player->aa_item->IsInWorld() && player->aa_target_item && player->aa_target_item->IsInWorld() && player->aa_item != player->aa_target_item) {
        std::string gm = ".组合 *.物品回收 " + std::to_string(player->aa_target_item->GetGUIDLow()) + "<$自身>";
        isOk = aaCenter.AA_DoCommand(player, gm.c_str());
    }
    return isOk;
}

bool AACenter::AA_Hecheng(Player* player)
{
    if (!player || !player->IsInWorld()) {
        return false;
    }
    if (aaCenter.AA_GetEmptyBag(player) < 5) {
        aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000背包剩余空间不足5个。");
        return false;
    }
    if (player->aa_item && player->aa_item->IsInWorld() && player->aa_target_item && player->aa_target_item->IsInWorld()) {
        uint32 entry = player->aa_target_item->GetEntry();
        ObjectGuid::LowType guidlow_target = player->aa_target_item->GetGUIDLow();
        AA_Character_Instance conf_target = aaCenter.aa_character_instances[guidlow_target];
        uint32 accountid = player->GetSession()->GetAccountId();
        AA_Account a_conf = aaCenter.aa_accounts[accountid];
        AA_Vip_Conf vconf = aaCenter.aa_vip_confs[a_conf.vip];
        AA_Hecheng_Conf conf = aaCenter.aa_hecheng_confs[entry];
        if (conf.itemid == 0) {
            return false;
        }
        if (conf.need > 0) {
            if (!aaCenter.M_CanNeed(player, conf.need, 1, true, player->aa_target_item->GetGUIDLow())) {
                return false;
            }
        }
        float chance = vconf.hecheng + conf.chance;
        if (aaCenter.AA_FindMapValueUint32(player->aa_fm_values, 406) > 0) {
            chance += aaCenter.AA_FindMapValueUint32(player->aa_fm_values, 406);
        }
        bool isOk = roll_chance_f(chance);

        if (conf.notice > 0) {
            AA_Message aa_message;
            aa_message.target_item = player->aa_target_item;
            AA_Notice notice = aaCenter.aa_notices[conf.notice];
            aaCenter.AA_SendNotice(player, notice, isOk, aa_message);
        }

        uint32 enchantmentId = player->aa_target_item->GetEnchantmentId(EnchantmentSlot(0));
        uint32 enchantmentDuration = player->aa_target_item->GetEnchantmentDuration(EnchantmentSlot(0));
        uint32 enchantmentCharges = player->aa_target_item->GetEnchantmentCharges(EnchantmentSlot(0));
        //成功 或者 失败并且消耗
        if (isOk || (!isOk && conf.destroy == 0)) {
            if (ItemTemplate const* pProto = player->aa_target_item->GetTemplate()) {
                uint32 count_max = player->aa_target_item->GetCount();
                uint32 count = 1;
                player->DestroyItemCount(player->aa_target_item, count, true);
                if (count_max == 1) {
                    player->aa_target_item = nullptr;
                }
            }
        }

        if (conf.need > 0) {
            aaCenter.M_Need(player, conf.need);
        }

        if (isOk) {
            Item *item = aaCenter.AA_AddItem(player, conf.itemid1, 1);
            if (aaCenter.AA_VerifyCode("a203b") && conf.is_baoliu == "是" && item) {
                ObjectGuid::LowType guidlow = item->GetGUIDLow();
                aaCenter.aa_character_instances[guidlow].fm_spell_count = conf_target.fm_spell_count;// = 0; //附魔技能数量-----拾取鉴定
                aaCenter.aa_character_instances[guidlow].fm_spells = conf_target.fm_spells;// = ""; //附魔技能-----拾取鉴定
                aaCenter.aa_character_instances[guidlow].fm_value_count = conf_target.fm_value_count;// = 0; //附魔属性数量-----拾取鉴定
                aaCenter.aa_character_instances[guidlow].fm_values = conf_target.fm_values;// = ""; //附魔属性-----拾取鉴定
                aaCenter.aa_character_instances[guidlow].fw_values = conf_target.fw_values;// ""; //符文属性
                aaCenter.aa_character_instances[guidlow].fwzh_values = conf_target.fwzh_values;//""; //符文组合属性
                aaCenter.aa_character_instances[guidlow].baoshi_entry = conf_target.baoshi_entry;
                aaCenter.aa_character_instances[guidlow].item_set = conf_target.item_set;
                time_t timep;
                time(&timep); /*当前time_t类型UTC时间*/
                aaCenter.aa_character_instances[guidlow].update_time = timep;
                aaCenter.aa_character_instances[guidlow].isUpdate = true;
                item->SetEnchantment(EnchantmentSlot(0), enchantmentId, enchantmentDuration, enchantmentCharges);
            }
        }

        player->aa_item = nullptr;
        player->aa_target_item = nullptr;
        return true;
    }
    return false;
}

bool AACenter::AA_Chaixie(Player* player, int32 index)
{
    if (player->aa_target_item && player->aa_target_item->GetState() != ITEM_REMOVED && player->aa_target_item->IsInWorld()) {
        if (aaCenter.AA_GetEmptyBag(player) < 5) {
            aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000背包剩余空间不足5个。");
            return false;
        }
        uint32 m_index = 0;
        for (uint32 i = 0; i < 1; i++) {
            if (index == -1) {
                m_index = i;
            }
            else {
                m_index = index;
            }
            uint32 entry = AA_GetBaoshiEntry(player->aa_target_item, m_index);
            AA_Chaixie_Conf conf = aaCenter.aa_chaixie_confs[entry];
            if (entry == 0) { continue; }
            if (conf.itemid == 0) {
                return false;
            }
            if (conf.need > 0) {
                if (aaCenter.M_CanNeed(player, conf.need, 1, true, player->aa_target_item->GetGUIDLow())) {
                    aaCenter.M_Need(player, conf.need);
                }
                else {
                    return false;
                }
            }
            bool isOk = roll_chance_f(conf.chance);
            if (conf.notice > 0) {
                AA_Message aa_message;
                aa_message.target_item = player->aa_target_item;
                AA_Notice notice = aaCenter.aa_notices[conf.notice];
                aaCenter.AA_SendNotice(player, notice, isOk, aa_message);
            }
            if (isOk) {
                if (conf.reward > 0) {
                    aaCenter.M_Reward(player, conf.reward);
                }
                player->aa_target_item->ClearEnchantment(EnchantmentSlot(SOCK_ENCHANTMENT_SLOT + m_index));
                player->AddItem(entry, 1);
            }
            if (index != -1) {
                break;
            }
        }
        ObjectGuid::LowType guidlow = player->aa_target_item->GetGUIDLow();
        time_t timep;
        time(&timep); /*当前time_t类型UTC时间*/
        aaCenter.aa_character_instances[guidlow].update_time = timep;
        aaCenter.aa_character_instances[guidlow].isUpdate = true;
        aaCenter.aa_character_instances[guidlow].baoshi_entry = 0;
        return true;
    }
    return false;
}

uint32 AACenter::AA_GetBaoshiEntry(Item* pItem, uint32 index)
{
    uint32 entry = 0;
    if (!pItem) {
        return entry;
    }
    ObjectGuid::LowType guidlow = pItem->GetGUIDLow();
    entry = aaCenter.aa_character_instances[guidlow].baoshi_entry;
    //    uint32 enchant_id = pItem->GetEnchantmentId(EnchantmentSlot(SOCK_ENCHANTMENT_SLOT + index));
    //    SpellItemEnchantmentEntry const* enchantEntry = sSpellItemEnchantmentStore.LookupEntry(enchant_id);
    //    if (enchantEntry) {
    //        entry = enchantEntry->GemID;
    //    }
    return entry;
}

bool AACenter::AA_Jiebang(Player* player)
{
    if (player->aa_item && player->aa_item->IsInWorld() && player->aa_target_item && player->aa_target_item->IsInWorld()) {
        uint32 entry = player->aa_target_item->GetEntry();
        AA_Jiebang_Conf conf = aaCenter.aa_jiebang_confs[entry];
        if (conf.itemid == 0) {
            aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000该物品无法解绑。");
            return false;
        }
        if (conf.need > 0) {
            if (aaCenter.M_CanNeed(player, conf.need, 1, true, player->aa_target_item->GetGUIDLow())) {
                aaCenter.M_Need(player, conf.need);
            }
            else {
                return false;
            }
        }
        player->aa_target_item->SetState(ITEM_CHANGED, player);
        player->aa_target_item->SetBinding(false);
        if (conf.notice > 0) {
            AA_Message aa_message;
            aa_message.target_item = player->aa_target_item;
            AA_Notice notice = aaCenter.aa_notices[conf.notice];
            aaCenter.AA_SendNotice(player, notice, true, aa_message);
        }
        if (conf.reward > 0) {
            aaCenter.M_Reward(player, conf.reward);
        }
        uint32 count = 1;
        player->DestroyItemCount(player->aa_item, count, true);
        player->aa_item = nullptr;
        player->aa_target_item = nullptr;
        return true;
    }
    return false;
}

bool AACenter::AA_Chengzhang_Item_Do(Player* player)
{
    if (player->aa_item && player->aa_item->IsInWorld() && player->aa_target_item && player->aa_target_item->IsInWorld()) {
        AA_Chengzhang_Item conf = aaCenter.aa_chengzhang_items[player->aa_item->GetEntry()];
        if (conf.itemid == 0 || conf.exp == 0) {
            return false;
        }
        if (ItemTemplate const* pProto = player->aa_target_item->GetTemplate()) {
            if (conf.items != "" && conf.items != "0") {
                std::vector<int32> items; items.clear();
                aaCenter.AA_StringToVectorInt(conf.items, items, ",");
                if (std::find(items.begin(), items.end(), pProto->GetId()) == items.end()) {
                    aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000无法对该物品使用。");
                    return false;
                }
            }
            if (conf.pcitems != "" && conf.pcitems != "0") {
                std::vector<int32> items; items.clear();
                aaCenter.AA_StringToVectorInt(conf.pcitems, items, ",");
                if (std::find(items.begin(), items.end(), pProto->GetId()) != items.end()) {
                    aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000无法对该物品使用。");
                    return false;
                }
            }
        }
        if (conf.need > 0) {
            if (!aaCenter.M_CanNeed(player, conf.need, 1, true, player->aa_target_item->GetGUIDLow())) {
                return false;
            }
        }
        if (!GiveCZXP(player, conf.exp, player->aa_target_item))
        {
            aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000无法对该物品使用。");
            return false;
        }
        if (conf.notice > 0) {
            AA_Message aa_message;
            aa_message.use_item = player->aa_item;
            aa_message.target_item = player->aa_target_item;
            AA_Notice notice = aaCenter.aa_notices[conf.notice];
            aaCenter.AA_SendNotice(player, notice, true, aa_message);
        }
        uint32 count = 1;
        player->DestroyItemCount(player->aa_item, count, true);
        player->aa_item = nullptr;
        player->aa_target_item = nullptr;
        if (conf.need > 0) {
            aaCenter.M_Need(player, conf.need);
        }
        return true;
    }
    return false;
}

bool AACenter::AA_Jianding_Item_Do(Player* player)
{
    if (player->aa_item && player->aa_item->IsInWorld() && player->aa_target_item && player->aa_target_item->IsInWorld()) {
        uint32 entry = player->aa_item->GetEntry();
        AA_Jianding_Item conf = aaCenter.aa_jianding_items[entry];
        if (conf.itemid == 0 || conf.nonsuchid == 0) {
            return false;
        }
        if (ItemTemplate const* pProto = player->aa_target_item->GetTemplate()) {
            if (conf.items != "" && conf.items != "0") {
                std::vector<int32> items; items.clear();
                aaCenter.AA_StringToVectorInt(conf.items, items, ",");
                if (std::find(items.begin(), items.end(), pProto->GetId()) == items.end()) {
                    aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000无法对该物品使用。");
                    return false;
                }
            }
            if (conf.pcitems != "" && conf.pcitems != "0") {
                std::vector<int32> items; items.clear();
                aaCenter.AA_StringToVectorInt(conf.pcitems, items, ",");
                if (std::find(items.begin(), items.end(), pProto->GetId()) != items.end()) {
                    aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000无法对该物品使用。");
                    return false;
                }
            }
        }
        if (conf.need > 0) {
            if (!aaCenter.M_CanNeed(player, conf.need, 1, true, player->aa_target_item->GetGUIDLow())) {
                return false;
            }
        }
        bool isOk = roll_chance_f(conf.chance);
        AA_Message aa_message;
        aa_message.use_item = player->aa_target_item;
        if (conf.notice > 0) {
            AA_Notice notice = aaCenter.aa_notices[conf.notice];
            aaCenter.AA_SendNotice(player, notice, isOk, aa_message);
        }
        if (isOk) {
            uint32 noticeid = aaCenter.M_NonsuchItem(player, player->aa_target_item, 0, conf.nonsuchid);
            if (noticeid > 0) {
                AA_Notice notice = aa_notices[noticeid];
                aaCenter.AA_SendNotice(player, notice, false, aa_message);
            }
        }
        uint32 count = 1;
        player->DestroyItemCount(player->aa_item, count, true);
        player->aa_item = nullptr;
        player->aa_target_item = nullptr;
        if (conf.need > 0) {
            aaCenter.M_Need(player, conf.need);
        }
        return true;
    }
    return false;
}

AA_Huishou_Conf AACenter::AA_GetHuiShouConf(Player* player, ObjectGuid::LowType guidlow, uint32 itemEntry)
{
    AA_Huishou_Conf conf;
    if (guidlow == 0) {
        return conf;
    }
    AA_Character_Instance a_conf = aaCenter.aa_character_instances[guidlow];
    uint32 entry = 0;
    if (a_conf.itemEntry > 0) {
        entry = a_conf.itemEntry;
    }
    if (entry == 0) {
        entry = itemEntry;
    }
    if (entry == 0) {
        return conf;
    }
    ItemTemplate const* pProto = sObjectMgr->GetItemTemplate(entry);
    if (!pProto) {
        return conf;
    }
    uint32 count = 1;
    //如果没有id，按需求回收
    for (auto confid : aaCenter.aa_huishou_desc) {
        AA_Huishou_Conf conf1 = aaCenter.aa_huishou_confs[confid];
        if (conf1.need > 0) {
            if (!aaCenter.M_CanNeed(player, conf1.need, count, false, guidlow)) {
                continue;
            }
            return conf1;
        }
    }
    uint32 confid = aaCenter.aa_huishou_entrys[entry];
    //如果有id，按id+需求回收
    if (confid > 0) {
        conf = aaCenter.aa_huishou_confs[confid];
        if (conf.need > 0) {
            if (aaCenter.M_CanNeed(player, conf.need, count, false, guidlow)) {
                return conf;
            }
            else {
                AA_Huishou_Conf conf1;
                return conf1;
            }
        }
        return conf;
    }
    return conf;
}

bool AACenter::AA_Qianghua_Item_Do(Player* player)
{
    if (player->aa_item && player->aa_item->IsInWorld() && player->aa_target_item && player->aa_target_item->IsInWorld()) {
        uint32 entry = player->aa_item->GetEntry();
        AA_Qianghua_Item conf = aaCenter.aa_qianghua_items[entry];
        if (conf.itemid == 0 || conf.level == 0) {
            return false;
        }
        if (ItemTemplate const* pProto = player->aa_target_item->GetTemplate()) {
            if (conf.items != "" && conf.items != "0") {
                std::vector<int32> items; items.clear();
                aaCenter.AA_StringToVectorInt(conf.items, items, ",");
                if (std::find(items.begin(), items.end(), pProto->GetId()) == items.end()) {
                    aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000无法对该物品使用。");
                    return false;
                }
            }
            if (conf.pcitems != "" && conf.pcitems != "0") {
                std::vector<int32> items; items.clear();
                aaCenter.AA_StringToVectorInt(conf.pcitems, items, ",");
                if (std::find(items.begin(), items.end(), pProto->GetId()) != items.end()) {
                    aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000无法对该物品使用。");
                    return false;
                }
            }
        }
        if (conf.need > 0) {
            if (!aaCenter.M_CanNeed(player, conf.need, 1, true, player->aa_target_item->GetGUIDLow())) {
                return false;
            }
        }
        bool isOk = roll_chance_f(conf.chance);
        if (conf.notice > 0) {
            AA_Message aa_message;
            aa_message.use_item = player->aa_item;
            aa_message.target_item = player->aa_target_item;
            AA_Notice notice = aaCenter.aa_notices[conf.notice];
            aaCenter.AA_SendNotice(player, notice, isOk, aa_message);
        }
        if (isOk) {
            ObjectGuid::LowType guidlow = player->aa_target_item->GetGUIDLow();
            aaCenter.aa_character_instances[guidlow].qh_values = "";
            aaCenter.aa_character_instances[guidlow].qh_reward_spell = "";
            aaCenter.aa_character_instances[guidlow].qh_reward_point = 0;
            aaCenter.aa_character_instances[guidlow].qh_reward_value = 0;
            aaCenter.M_UpgradeItem(player, player->aa_target_item, conf.level);
        }
        uint32 count = 1;
        player->DestroyItemCount(player->aa_item, count, true);
        player->aa_item = nullptr;
        player->aa_target_item = nullptr;
        if (conf.need > 0) {
            aaCenter.M_Need(player, conf.need);
        }
        return true;
    }
    return false;
}

void _AA_Shuangjia_1017(Player* player, uint32 ye)
{
    std::string result = "{";//{[lan]={[index]={entry,guid},[index]={entry,guid}},[lan]={[index]={entry,guid},[index]={entry,guid}}}
    int j = 0; size_t i = 0;
    ObjectGuid::LowType guidlow = player->GetGUIDLow();
    std::vector<ObjectGuid::LowType> guids = aaCenter.aa_item_instance_owner[guidlow];
    std::map<int32, std::map<int32, ObjectGuid::LowType> > w; w.clear();
    for (auto guid : guids) {
        AA_Item_Instance conf = aaCenter.aa_item_instances[guid];
        if (conf.weizhi != "") {
            i++; j++;
            std::map<int32, int32> m; m.clear();
            aaCenter.AA_StringToMap(conf.weizhi, m);
            int32 id = m.begin()->first;
            int32 index = m.begin()->second;
            w[id][index] = conf.guid;
        }
    }
    for (auto it : aaCenter.aa_item_shuangjias) {
        int32 id = it.first;
        if (id <= ((ye-1) * 6)) {
            continue;
        }
        if (id > (ye * 6)) {
            break;
        }
        result += "["; result += std::to_string(id); result += "]={";
        AA_Item_Shuangjia conf = it.second;
        if (conf.display_items != "") {
            std::vector<int32> v; v.clear();
            aaCenter.AA_StringToVectorInt(conf.display_items, v, ",");
            std::vector<int32> v1; v1.clear();
            aaCenter.AA_StringToVectorInt(conf.need_xiangqian, v1, ",");
            std::vector<int32> v2; v2.clear();
            aaCenter.AA_StringToVectorInt(conf.need_chaixie, v2, ",");
            if (v.size() > 0) {
                for (int i = 0; i < v.size(); i++) {
                    uint32 need_xiangqian = 0;
                    if (v1.size() > i) {
                        need_xiangqian = v1[i];
                    }
                    uint32 need_chaixie = 0;
                    if (v2.size() > i) {
                        need_chaixie = v2[i];
                    }
                    uint32 entry = v[i];
                    int32 index = i + 1;
                    ObjectGuid::LowType guid = w[id][index];
                    result += "[";
                    result += std::to_string(index); result += "]={\"";//1
                    std::string link = aaCenter.AA_GetItemLink(entry);
                    if (guid > 0) {
                        AA_Item_Instance conf = aaCenter.aa_item_instances[guid];
                        if (conf.itemEntry > 0) {
                            ItemTemplate const* pProto = sObjectMgr->GetItemTemplate(conf.itemEntry);
                            if (pProto)
                            {
                                Item* pItem = NewItemOrBag(pProto);
                                if (pItem->AA_LoadFromDB(guid, ObjectGuid::Empty, conf.itemEntry))
                                {
                                    link = aaCenter.AA_GetItemLinkJd(pItem);
                                    delete pItem;
                                }
                            }
                        }
                    }
                    result += link; result += "\",";
                    result += std::to_string(need_xiangqian); result += ",";
                    result += std::to_string(need_chaixie); result += "},";
                }
            }
        }
        result += "}}";
        aaCenter.AA_StringReplaceLast(result, ",}", "}");
        aaCenter.M_SendClientAddonData(player, "1017", result);
        result = "{";
    }
}

void _AA_Shizhuang_3023(Player *player, uint32 lan)
{
    std::set<uint32> ids; ids.clear();
    for (auto itr : aaCenter.aa_ui_shizhuangs) {
        if (itr.first == 0) {
            continue;
        }
        ids.insert(itr.first);
    }
    ObjectGuid::LowType ownerguidlow = player->GetGUIDLow();
    std::map<uint32, AA_UI_Shizhuang> confs = aaCenter.aa_ui_shizhuangs[lan - 101 + 1];
    std::vector<std::string> weizhis; weizhis.clear();
    std::vector<ObjectGuid::LowType> guids = aaCenter.aa_item_instance_owner[ownerguidlow];
    std::string result = "{["; result += std::to_string(lan); result += "]={[";
    if (confs.size() == 0)
    {
        aaCenter.M_SendClientAddonData(player, "3020", "{[" + std::to_string(lan)+ "]={}}");
        return;
    }
    bool isconf = false;
    for (auto itr : confs) {
        AA_UI_Shizhuang conf = itr.second;
        if (conf.item == 0) break;

        if (ItemTemplate const* pProto = sObjectMgr->GetItemTemplate(conf.item)) {
            std::string weizhi = std::to_string(lan) + " " + std::to_string(conf.id);
            ObjectGuid::LowType guidlow = 0;
            for (auto guid : guids)
            {
                AA_Item_Instance iconf = aaCenter.aa_item_instances[guid];
                if (iconf.weizhi == weizhi) {
                    guidlow = guid;
                    break;
                }
            }
            std::string itemlink = "";
            if (guidlow > 0) {
                ObjectGuid::LowType guidlowH = guidlow / 10000;
                ObjectGuid::LowType guidlowL = guidlow - guidlowH * 10000;
                itemlink = "|Hitem:" + std::to_string(conf.item) + ":0:0:" + std::to_string(guidlowH + 5000) + ":" + std::to_string(guidlowL + 5000) + ":0:0:0|h" + pProto->GetName(LOCALE_zhCN) + "|h|r";
            }
            else {
                itemlink = "|Hitem:" + std::to_string(conf.item) + ":0:0:0:0:0:0:0|h" + pProto->GetName(LOCALE_zhCN) + "|h|r";
            }
            if (isconf) {
                result += ",[";
            }
            result += std::to_string(conf.id); result += "]={\"";
            result += itemlink; result += "\",\"";
            std::string items = "";
            if (conf.needs != "" && conf.needs != "0") {
                std::vector<int32> types; types.clear();
                std::vector<int32> values; values.clear();
                aaCenter.AA_StringToVector2(conf.needs, types, values);
                if (types.size() > 0) {
                    bool isOk = false;
                    for (size_t i = 0; i < types.size(); i++)
                    {
                        if (isOk) {
                            items += ",";
                        }
                        uint32 entry = types[i];
                        std::string itemLink = aaCenter.AA_GetItemLink(entry);
                        uint32 count = values[i];
                        items += "\\\""; items += itemLink; items += "\\\"";
                        items += " ";
                        items += std::to_string(count);
                        isOk = true;
                    }
                }
            }
            result += items; result += "\",";
            result += std::to_string(lan); result += ",";
            result += std::to_string(ids.size()); result += "}";
            isconf = true;
        }
    }
    result += "}}";
    aaCenter.M_SendClientAddonData(player, "3020", result);
}

void _AA_Shenqi_3031(Player* player, uint32 lan)
{
    std::set<uint32> ids; ids.clear();
    for (auto itr : aaCenter.aa_ui_shenqis) {
        if (itr.first == 0) {
            continue;
        }
        ids.insert(itr.first);
    }
    ObjectGuid::LowType ownerguidlow = player->GetGUIDLow();
    std::map<uint32, std::map<uint32, AA_UI_Shenqi>> confs = aaCenter.aa_ui_shenqis[lan - 201 + 1];
    std::vector<ObjectGuid::LowType> guids = aaCenter.aa_item_instance_owner[ownerguidlow];
    std::string result = "{["; result += std::to_string(lan); result += "]={[";
    bool isconf = false;
    //条件1如果未激活，显示1级itemlink，1级图片 和 1级需求
    //条件2如果已激活，显示当前等级物品itemlink，当前等级图片 和 下一级需求
    //条件3如果已满级，显示当前等级物品itemlink，当前等级图片 和 当前需求
    //获取当前激活物品，如果未获取，条件1，如果已获取，并且有下一级条件2，如果已激活，并且没有下一级，条件3
    for (auto itr : confs) {
        int32 next = -1; //0激活 1升级 2已满级
        for (size_t i = 1; i < 10000; i++)
        {
            AA_UI_Shenqi conf = aaCenter.aa_ui_shenqis[lan - 201 + 1][itr.first][i];
            if (conf.level == 0) {
                break;
            }
            if (ItemTemplate const* pProto = sObjectMgr->GetItemTemplate(conf.item)) {
                std::string weizhi = std::to_string(lan) + " " + std::to_string(conf.id);
                ObjectGuid::LowType guidlow = 0;
                AA_Item_Instance iconf;
                for (auto guid : guids)
                {
                    AA_Item_Instance iconf = aaCenter.aa_item_instances[guid];
                    if (iconf.weizhi == weizhi) {
                        guidlow = guid;
                        AA_UI_Shenqi cconf = aaCenter.aa_ui_shenqi_entrys[iconf.itemEntry];
                        conf = cconf;
                        i = conf.level;
                        break;
                    }
                }
                if (guidlow > 0) {
                    AA_UI_Shenqi cconf = aaCenter.aa_ui_shenqis[lan - 201 + 1][conf.id][conf.level + 1];
                    if (cconf.item > 0) { //有下一级
                        next = 1;
                    }
                    else {
                        next = 2;
                    }
                }
                else {
                    next = 0;
                }
                if (isconf) {
                    result += ",[";
                }
                std::string itemlink = "";
                std::string name = pProto->GetName(LOCALE_zhCN);
                if (ItemTemplate const* pProto1 = sObjectMgr->GetItemTemplate(conf.item)) {
                    name = pProto1->GetName(LOCALE_zhCN);
                }
                if (guidlow > 0) { //已经激活，如果有下一级，显示升级。如果没有下一级，显示已满级
                    ObjectGuid::LowType guidlowH = guidlow / 10000;
                    ObjectGuid::LowType guidlowL = guidlow - guidlowH * 10000;
                    itemlink = "|Hitem:" + std::to_string(conf.item) + ":0:0:" + std::to_string(guidlowH + 5000) + ":" + std::to_string(guidlowL + 5000) + ":0:0:0|h" + name + "|h|r";
                }
                else { //没有激活，显示激活
                    itemlink = "|Hitem:" + std::to_string(conf.item) + ":0:0:0:0:0:0:0|h" + name + "|h|r";
                }
                result += std::to_string(conf.id); result += "]={\"";
                result += itemlink; result += "\",\"";
                std::string items = "";
                AA_UI_Shenqi needconf;
                if (next == 1) {
                    needconf = aaCenter.aa_ui_shenqis[lan - 201 + 1][conf.id][i+1];
                }
                else {
                    needconf = conf;
                }
                if (needconf.needs != "" && needconf.needs != "0") {
                    std::vector<int32> types; types.clear();
                    std::vector<int32> values; values.clear();
                    aaCenter.AA_StringToVector2(needconf.needs, types, values);
                    if (types.size() > 0) {
                        bool isOk = false;
                        for (size_t i = 0; i < types.size(); i++)
                        {
                            if (isOk) {
                                items += ",";
                            }
                            uint32 entry = types[i];
                            std::string itemLink = aaCenter.AA_GetItemLink(entry);
                            uint32 count = values[i];
                            items += "\\\""; items += itemLink; items += "\\\"";
                            items += " ";
                            items += std::to_string(count);
                            isOk = true;
                        }
                    }
                }
                result += items; result += "\",";
                result += std::to_string(lan); result += ",";
                result += std::to_string(ids.size()); result += ",\"";
                result += conf.image; result += "\",";
                result += std::to_string(conf.count); result += ",";
                result += std::to_string(conf.x); result += ",";
                result += std::to_string(conf.y); result += ",";
                result += std::to_string(next); result += "}";
                isconf = true;
                if (next > -1) {
                    break;
                }
            }
        }
    }
    result += "}}";
    aaCenter.M_SendClientAddonData(player, "3030", result);
}

void AACenter::AA_ReceiveAddon(Player* player, std::string& prefix, std::string& receivemsg)
{
    if (!player || !player->IsInWorld()) {
        return;
    }
    if (prefix == "" || receivemsg == "" || receivemsg.length() == 0) { return; }
    //    if (prefix == "1" || prefix == "2" || prefix == "3" || prefix == "4" || prefix == "5" || prefix == "6" || prefix == "7" || prefix == "8" || prefix == "9" || prefix == "10") {
    //        if (!aaCenter.AA_VerifyCode("a5b")) {
    //            return;
    //        }
    //    }
    try {
        std::string msg = receivemsg;
        std::vector<std::string> msgs;
        msgs.clear();
        aaCenter.AA_StringToVectorString(msg, msgs, "\t");
        //限制 锻造每3秒点击一次，物品请求每1秒请求一次
        if (prefix == "200") { //活动窗口，点击确定
            if (msgs.size() < 2) { return; }
            uint32 eventid = aaCenter.AA_StringUint32(msgs[0]);
            uint32 t = aaCenter.AA_StringUint32(msgs[1]);
            aaCenter.AA_CallBack_Event(player, eventid, t, 1);
            aaCenter.M_SendClientAddonData(player, prefix, "0");
        }
        else if (prefix == "201") { //活动窗口，点击取消
            if (msgs.size() < 2) { return; }
            uint32 eventid = aaCenter.AA_StringUint32(msgs[0]);
            uint32 t = aaCenter.AA_StringUint32(msgs[1]);
            aaCenter.AA_CallBack_Event(player, eventid, t, 2);
            aaCenter.M_SendClientAddonData(player, prefix, "0");
        }
        else if (prefix == "1" || prefix == "2" || prefix == "3" || prefix == "4" || prefix == "5" || prefix == "6" || prefix == "7" || prefix == "8" || prefix == "9" || prefix == "10" || prefix == "100" || prefix == "101" || prefix == "102" || prefix == "103" || prefix == "104" || prefix == "3020" || prefix == "3021" || prefix == "3022") {
            if (player->clickTime >= 300) {
                player->clickTime = 0;
            }
            else {
                AA_Message aa_message;
                AA_Notice notice = aaCenter.aa_notices[16];
                aaCenter.AA_SendNotice(player, notice, true, aa_message);
                return;
            }
        }
        for (auto itr : aaCenter.aa_desktop_confs) {
            AA_Desktop_Conf conf = itr.second;
            if (conf.gm != "" && conf.gm != "0" && std::to_string(conf.type) == prefix) {
                aaCenter.AA_DoCommand(player, conf.gm.c_str());
                break;
            }
        }
        if (prefix == "1") { //强化
            if (aaCenter.aa_world_confs[37].value1 == 1) {
                if (msgs.size() < 2) { return; }
                uint32 id = aaCenter.AA_StringUint32(msgs[0]);
                uint32 entry = aaCenter.AA_StringUint32(msgs[1]);
                ObjectGuid::LowType guidlow = aaCenter.AA_GetRealItemGuid(id, entry);
                //                ObjectGuid::LowType guidlow = aaCenter.aa_character_instance_ids[id];
                if (Item* pItem = aaCenter.GetItemByGUIDLow(player, guidlow)) {
                    if (!pItem->IsInWorld()) {
                        return;
                    }
                    if (pItem->IsEquipped()) {
                        aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000请将物品放入背包再操作。"); return;
                    }
                    aaCenter.M_UpgradeItem(player, pItem);
                    aaCenter.M_SendClientAddonData(player, prefix, "0");
                }
            }
        }
        else if (prefix == "3") { //洗炼
            if (aaCenter.aa_world_confs[38].value1 == 1) {
                if (msgs.size() < 2) { return; }
                uint32 id = aaCenter.AA_StringUint32(msgs[0]);
                uint32 entry = aaCenter.AA_StringUint32(msgs[1]);
                ObjectGuid::LowType guidlow = aaCenter.AA_GetRealItemGuid(id, entry);
                //                ObjectGuid::LowType guidlow = aaCenter.aa_character_instance_ids[id];
                if (Item* pItem = aaCenter.GetItemByGUIDLow(player, guidlow)) {
                    if (ItemTemplate const* pProto = pItem->GetTemplate()) {
                        if (!pItem->IsInWorld()) {
                            return;
                        }
                        AA_Character_Instance a_conf = aaCenter.aa_character_instances[pItem->GetGUIDLow()];
                        if (a_conf.jd_zu == 0) {
                            aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000该物品无法洗炼。"); return;
                        }
                        if (pItem->IsEquipped()) {
                            aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000请将物品放入背包再操作。"); return;
                        }
                        uint32 noticeid = aaCenter.M_NonsuchItem(player, pItem, a_conf.jd_zu, -1);
                        if (noticeid > 0) {
                            AA_Message aa_message;
                            aa_message.use_item = pItem;
                            AA_Notice notice = aaCenter.aa_notices[noticeid];
                            aaCenter.AA_SendNotice(player, notice, false, aa_message);
                        }
                        aaCenter.M_SendClientAddonData(player, prefix, "0");
                    }
                }
            }
        }
        else if (prefix == "4") { //改名
            if (msgs.size() < 3) { return; }
            uint32 id = aaCenter.AA_StringUint32(msgs[0]);
            uint32 entry = aaCenter.AA_StringUint32(msgs[1]);
            ObjectGuid::LowType guidlow = aaCenter.AA_GetRealItemGuid(id, entry);
            //            ObjectGuid::LowType guidlow = aaCenter.aa_character_instance_ids[id];
            if (Item* pItem = aaCenter.GetItemByGUIDLow(player, guidlow)) {
                if (!pItem->IsInWorld()) {
                    return;
                }
                if (pItem->IsEquipped()) {
                    aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000请将物品放入背包再操作。"); return;
                }
                aaCenter.M_ChangeItemName(player, pItem, msgs[2]);
                aaCenter.M_SendClientAddonData(player, prefix, "0");
            }
        }
        else if (prefix == "5") { //解绑
            if (msgs.size() < 2) { return; }
            uint32 id = aaCenter.AA_StringUint32(msgs[0]);
            uint32 entry = aaCenter.AA_StringUint32(msgs[1]);
            ObjectGuid::LowType guidlow = aaCenter.AA_GetRealItemGuid(id, entry);
            //            ObjectGuid::LowType guidlow = aaCenter.aa_character_instance_ids[id];
            Item* pItem = aaCenter.GetItemByGUIDLow(player, guidlow);
            if (!pItem || !pItem->IsInWorld()) {
                return;
            }
            player->aa_target_item = pItem;
            aaCenter.AA_Jiebang(player);
        }
        else if (prefix == "6") { //符文拆卸
            if (msgs.size() < 3) { return; }
            uint32 id = aaCenter.AA_StringUint32(msgs[0]);
            uint32 entry = aaCenter.AA_StringUint32(msgs[1]);
            ObjectGuid::LowType guidlow = aaCenter.AA_GetRealItemGuid(id, entry);
            //            ObjectGuid::LowType guidlow = aaCenter.aa_character_instance_ids[id];
            uint32 index = aaCenter.AA_StringUint32(msgs[2]);
            if (Item* pItem = aaCenter.GetItemByGUIDLow(player, guidlow)) {
                if (!pItem->IsInWorld()) {
                    return;
                }
                if (pItem->IsEquipped()) {
                    aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000请将物品放入背包再操作。"); return;
                }
                aaCenter.M_FuWenChaixie(player, pItem, index, false);
                aaCenter.M_SendClientAddonData(player, prefix, "0");
            }
        }
        else if (prefix == "7") { //符文开槽
            if (msgs.size() < 2) { return; }
            uint32 id = aaCenter.AA_StringUint32(msgs[0]);
            uint32 entry = aaCenter.AA_StringUint32(msgs[1]);
            ObjectGuid::LowType guidlow = aaCenter.AA_GetRealItemGuid(id, entry);
            //            ObjectGuid::LowType guidlow = aaCenter.aa_character_instance_ids[id];
            if (Item* pItem = aaCenter.GetItemByGUIDLow(player, guidlow)) {
                if (!pItem->IsInWorld()) {
                    return;
                }
                if (pItem->IsEquipped()) {
                    aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000请将物品放入背包再操作。"); return;
                }
                aaCenter.M_FuWenKaichao(player, pItem, 1);
                aaCenter.M_SendClientAddonData(player, prefix, "0");
            }
        }
        else if (prefix == "8") { //符文镶嵌
            if (msgs.size() < 3) { return; }
            uint32 id = aaCenter.AA_StringUint32(msgs[0]);
            uint32 entry = aaCenter.AA_StringUint32(msgs[1]);
            ObjectGuid::LowType guidlow = aaCenter.AA_GetRealItemGuid(id, entry);
            //            ObjectGuid::LowType guidlow = aaCenter.aa_character_instance_ids[id];
            std::string fwstr = msgs[2];
            Item* pItem = aaCenter.GetItemByGUIDLow(player, guidlow);
            if (!pItem || !pItem->IsInWorld() || fwstr == "") {
                return;
            }
            if (pItem->IsEquipped()) {
                aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000请将物品放入背包再操作。"); return;
            }
            std::vector<std::string> fwstrs;
            fwstrs.clear();
            aaCenter.AA_StringToVectorString(fwstr, fwstrs, ",");
            std::vector<int32> fwids; fwids.clear();
            std::vector<int32> fwentrys; fwentrys.clear();
            for (std::string fws : fwstrs) {
                std::vector<int32> fwss; fwss.clear();
                aaCenter.AA_StringToVectorInt(fws, fwss, "\f");
                if (fwss.size() >= 2) {
                    fwids.push_back(fwss[0]);
                    fwentrys.push_back(fwss[1]);
                }
            }

            if (pItem && fwids.size() > 0) {
                aaCenter.M_FuWenXiangqian(player, pItem, fwids, fwentrys);
            }
            aaCenter.M_SendClientAddonData(player, prefix, "0");
        }
        else if (prefix == "9") { //重铸属性
            if (aaCenter.aa_world_confs[36].value1 == 1) {
                if (msgs.size() < 2) { return; }
                uint32 id = aaCenter.AA_StringUint32(msgs[0]);
                uint32 entry = aaCenter.AA_StringUint32(msgs[1]);
                ObjectGuid::LowType guidlow = aaCenter.AA_GetRealItemGuid(id, entry);
                //                ObjectGuid::LowType guidlow = aaCenter.aa_character_instance_ids[id];
                if (Item* pItem = aaCenter.GetItemByGUIDLow(player, guidlow)) {
                    if (!pItem->IsInWorld()) {
                        return;
                    }
                    if (pItem->IsEquipped()) {
                        aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000请将物品放入背包再操作。"); return;
                    }
                    uint32 jdid = aaCenter.aa_character_instances[guidlow].jd_id;
                    if (jdid == 0) {
                        aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000d该物品无法重铸。"); return;
                    }
                    if (aaCenter.M_NonsuchItemFmValue(player, pItem, jdid, 0)) {
                        aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFFFF00重铸成功");
                    }
                    aaCenter.M_SendClientAddonData(player, prefix, "0");
                }
            }
        }
        else if (prefix == "10") { //重铸技能
            if (aaCenter.aa_world_confs[36].value1 == 1) {
                if (msgs.size() < 2) { return; }
                uint32 id = aaCenter.AA_StringUint32(msgs[0]);
                uint32 entry = aaCenter.AA_StringUint32(msgs[1]);
                ObjectGuid::LowType guidlow = aaCenter.AA_GetRealItemGuid(id, entry);
                //                ObjectGuid::LowType guidlow = aaCenter.aa_character_instance_ids[id];
                if (Item* pItem = aaCenter.GetItemByGUIDLow(player, guidlow)) {
                    if (!pItem->IsInWorld()) {
                        return;
                    }
                    if (pItem->IsEquipped()) {
                        aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000请将物品放入背包再操作。"); return;
                    }
                    uint32 jdid = aaCenter.aa_character_instances[guidlow].jd_id;
                    if (jdid == 0) {
                        aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000d该物品无法重铸。"); return;
                    }
                    if (aaCenter.M_NonsuchItemFmSpell(player, pItem, jdid, 0)) {
                        aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFFFF00重铸成功");
                    }
                    aaCenter.M_SendClientAddonData(player, prefix, "0");
                }
            }
        }
        else if (prefix == "11") { //获取指定spell
            if (msgs.size() < 2) { return; }
            std::vector<uint32> spellids, spelltimes;
            spellids.clear();
            spelltimes.clear();
            size_t count = msgs.size() * 0.5;
            for (size_t i = 0; i < count; i++) {
                uint32 spellid = AA_StringUint32(AA_SafeStringAtIndex(msgs, i * 2));
                uint32 spelltime = AA_StringUint32(AA_SafeStringAtIndex(msgs, i * 2 + 1));
                if (spellid > 0) {
                    spellids.push_back(spellid);
                    spelltimes.push_back(spelltime);
                }
            }
            aaCenter.M_GetSpellText(player, spellids, spelltimes);
        }
        else if (prefix == "12") { //获取指定item
            if (msgs.size() < 3) { return; }
            std::vector<uint32> itemids, itementrys, itemtimes;
            itemids.clear();
            itementrys.clear();
            itemtimes.clear();
            size_t count = msgs.size() / 3;
            for (size_t i = 0; i < count; i++) {
                uint32 itemid = AA_StringUint32(AA_SafeStringAtIndex(msgs, i * 3));
                uint32 itementry = AA_StringUint32(AA_SafeStringAtIndex(msgs, i * 3 + 1));
                uint32 itemtime = AA_StringUint32(AA_SafeStringAtIndex(msgs, i * 3 + 2));
                if (itemid > 0) {
                    itemids.push_back(itemid);
                    itementrys.push_back(itementry);
                    itemtimes.push_back(itemtime);
                }
            }
            aaCenter.M_GetItemText(player, itemids, itementrys, itemtimes);
            std::string str = aaCenter.M_GetItemTemplateGuid(player, itemids, itementrys);
            if (str != "" && str != "{}") {
                aaCenter.M_SendClientAddonData(player, "25", str);
            }
        }
        else if (prefix == "13") { //获取itemtemplate
            if (msgs.size() == 0) { return; }
            std::set<uint32> itemEntrys;
            itemEntrys.clear();
            size_t count = msgs.size();
            for (size_t i = 0; i < count; i++) {
                uint32 itemEntry = aaCenter.AA_StringUint32(msgs[i]);
                if (itemEntry > 0) {
                    itemEntrys.insert(itemEntry);
                }
            }
            string sendmsg = aaCenter.M_GetItemTemplate(itemEntrys);
            aaCenter.M_SendClientAddonData(player, prefix, sendmsg);
        }
        else if (prefix == "14") { //获取nonsuch配置
            aaCenter.M_SendAA_Conf(player, prefix);
        }
        else if (prefix == "15") { //获取upgrade配置
            aaCenter.M_SendAA_Conf(player, prefix);
        }
        else if (prefix == "17") { //获取stat配置
            aaCenter.M_SendAA_Conf(player, prefix);
        }
        else if (prefix == "18") { //获取worldserverconf
            aaCenter.M_SendAA_Conf(player, prefix);
        }
        else if (prefix == "19") { //获取needconf
            aaCenter.M_SendAA_Conf(player, prefix);
        }
        else if (prefix == "20") { //获取rewardconf
            aaCenter.M_SendAA_Conf(player, prefix);
        }
        else if (prefix == "21") { //获取符文物品
            aaCenter.M_SendAA_Conf(player, prefix);
        }
        else if (prefix == "22") { //获取符文组合信息
            aaCenter.M_SendAA_Conf(player, prefix);
        }
        else if (prefix == "23") { //获取物品成长信息
            aaCenter.M_SendAA_Conf(player, prefix);
        }
        else if (prefix == "24") { //获取物品购买信息
            aaCenter.M_SendAA_Conf(player, prefix);
        }
        else if (prefix == "25") { //获取itemlink
            aaCenter.M_SendAA_Conf(player, prefix);
        }
        else if (prefix == "26") { //获取itemlink
            aaCenter.M_SendAA_Conf(player, prefix);
        }
        else if (prefix == "27") { //获取itemsets
            if (msgs.size() < 1) { return; }
            uint32 itemset = aaCenter.AA_StringUint32(msgs[0]);
            if (itemset == 0) return;
            std::set<ObjectGuid::LowType> itemguids = aaCenter.aa_allsetitems[player->GetGUID()][itemset];
            std::string result = "{";//{[itemset]={itemlink,itemlink}}
            result += "["; result += std::to_string(itemset); result += "]={";
            if (itemguids.size() == 0) {
                result += "}}";
                aaCenter.M_SendClientAddonData(player, prefix, result);
                return;
            }
            for (auto& it : itemguids)
            {
                Item* pItem = aaCenter.GetItemByGUIDLow(player, it);
                if (!pItem || !pItem->IsInWorld()) {
                    return;
                }
                std::string itemLink = aaCenter.AA_GetItemLinkJd(pItem);
                result += "\"\\\""; result += itemLink; result += "\\\"\",";
            }
            result += "}}";
            aaCenter.AA_StringReplaceLast(result, ",}", "}");
            aaCenter.M_SendClientAddonData(player, prefix, result);
        }
        else if (prefix == "28") { //获取itemset_list
            aaCenter.M_SendAA_Conf(player, prefix);
        }
        else if (prefix == "29") { //获取itemset_conf
            aaCenter.M_SendAA_Conf(player, prefix);
        }
        else if (prefix == "301") { //获取防脚本验证码
            if (msgs.size() == 0) { return; }
            if (aaCenter.aa_world_confs[33].value1 == 1) {
                std::vector<int32> maps; maps.clear();
                aaCenter.AA_StringToVectorInt(aaCenter.aa_world_confs[32].value2, maps, ",");
                if (aaCenter.aa_world_confs[32].value2 == "" || std::find(maps.begin(), maps.end(), player->GetAreaId()) == maps.end()) {
                    uint32 codeindex = aaCenter.AA_StringUint32(msgs[0]);
                    if (codeindex > 0 && codeindex == player->codeindex) {
                        player->codecishu = 3;
                        player->lootcount = 0;
                        player->guajiTime = 0;
                        player->guajiyanzhengtime = 0;
                        player->codetime = 0;
                        aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFFFF00验证成功");
                        return;
                    }
                    int32 cishu = player->codecishu - 1;
                    cishu = cishu <= 0 ? 0 : cishu;
                    player->codecishu = cishu;
                    if (cishu <= 0) {
                        if (aaCenter.aa_world_confs[30].value2 == "0" || aaCenter.aa_world_confs[30].value2 == "") {
                            player->GetSession()->KickPlayer("kick");
                        }
                        else {
                            if (aaCenter.aa_world_confs[30].value2 != "" && aaCenter.aa_world_confs[30].value2 != "0") {
                                aaCenter.AA_DoCommand(player, aaCenter.aa_world_confs[30].value2.c_str());
                            }
                        }
                    }
                    else {
                        std::string m1 = "|cff00FFFF[系统提示]|cffFF0000验证错误，你还有" + std::to_string(player->codecishu) + "次验证机会";
                        aaCenter.AA_SendMessage(player, 1, m1.c_str());
                        aaCenter.AA_SendMessage(player, 1, m1.c_str());
                        aaCenter.AA_SendMessage(player, 1, m1.c_str());
                        uint32 sendindex = rand() % 618 + 1;
                        player->codeindex = sendindex;
                        aaCenter.M_SendClientAddonData(player, "301", std::to_string(sendindex));
                    }
                }
            }
        }
        else if (prefix == "999") { //点击桌面图标
            if (msgs.size() == 0) { return; }
            uint32 type = aaCenter.AA_StringUint32(msgs[0]);
            for (auto itr : aaCenter.aa_desktop_confs) {
                AA_Desktop_Conf conf = itr.second;
                if (conf.id > 0 && conf.type == type) {
                    if (conf.gm != "" && conf.gm != "0") {
                        aaCenter.AA_DoCommand(player, conf.gm.c_str());
                    }
                }
            }
        }
        else if (prefix == "1000") { //获取桌面图标
            aaCenter.M_SendAA_Conf(player, prefix);
        }
        else if (prefix == "1001") { //获取在线奖励
         //                aaCenter.M_SendAA_Conf(player, prefix);
        }
        else if (prefix == "10001") { //领取在线奖励

        }
        else if (prefix == "1002") { //获取等级奖励
            aaCenter.M_SendAA_Conf(player, prefix);
        }
        else if (prefix == "10002") { //领取升级奖励
            if (msgs.size() == 0) { return; }
            std::string gm = ".组合 *.领取等级 " + msgs[0] + "<$自身>";
            aaCenter.AA_DoCommand(player, gm.c_str());
        }
        else if (prefix == "1003") { //获取个人理财
            aaCenter.M_SendAA_Conf(player, prefix);
        }
        else if (prefix == "10003") { //领取和购买个人理财奖励
            std::string gm = ".组合 *.领取理财<$自身>";
            aaCenter.AA_DoCommand(player, gm.c_str());
        }
        else if (prefix == "1004") { //获取首充奖励
            aaCenter.M_SendAA_Conf(player, prefix);
        }
        else if (prefix == "10004") { //领取首充奖励
            std::string gm = ".组合 *.领取首充<$自身>";
            aaCenter.AA_DoCommand(player, gm.c_str());
        }
        else if (prefix == "1005") { //领取累充奖励
            aaCenter.M_SendAA_Conf(player, prefix);
        }
        else if (prefix == "10005") { //获取累充奖励
            if (msgs.size() == 0) { return; }
            std::string gm = ".组合 *.领取累充 " + msgs[0] + "<$自身>";
            aaCenter.AA_DoCommand(player, gm.c_str());
        }
        else if (prefix == "1006") { //获取签到奖励
            aaCenter.M_SendAA_Conf(player, prefix);
        }
        else if (prefix == "10006") { //领取签到奖励
            if (msgs.size() == 0) { return; }
            std::string gm = ".组合 *.领取签到 " + msgs[0] + "<$自身>";
            aaCenter.AA_DoCommand(player, gm.c_str());
        }
        else if (prefix == "10071") { //获取幸运抽奖
            aaCenter.M_SendAA_Conf(player, prefix);
        }
        else if (prefix == "10072") { //获取幸运抽奖
            aaCenter.M_SendAA_Conf(player, prefix);
        }
        else if (prefix == "1007") { //幸运抽奖
            if (msgs.size() == 0) { return; }
            std::string gm = ".组合 *.抽奖 1 " + msgs[0] + "<$自身>";
            aaCenter.AA_DoCommand(player, gm.c_str());
        }
        else if (prefix == "1011") { //获取活动公告栏
            aaCenter.M_SendAA_Conf(player, prefix);
        }
        else if (prefix == "10011") { //点击活动公告栏接受
            if (player->IsInCombat()) {
                aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000战斗中无法使用!");
                return;
            }
            if (msgs.size() == 0) { return; }
            uint32 huodong_id = aaCenter.AA_StringUint32(msgs[0]);
            AA_Huodong_Conf conf = aaCenter.aa_huodong_confs[huodong_id];
            if (conf.id > 0) {
                //判断活动是否激活
                if (!sGameEventMgr->IsActiveEvent(conf.game_event)) {
                    aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000当前活动还未开始!");
                    return;
                }
                //开始执行
                if (conf.need > 0) {
                    if (aaCenter.M_CanNeed(player, conf.need)) {
                        aaCenter.M_Need(player, conf.need);
                    }
                    else {
                        return;
                    }
                }
                if (conf.reward > 0) {
                    aaCenter.M_Reward(player, conf.reward);
                }
            }
        }
        else if (prefix == "1012") { //.翻牌 秘钥 牌子序号
            if (msgs.size() < 2) { return; }
            uint64 miyao = aaCenter.AA_StringUint64(msgs[0]);
            uint32 index = aaCenter.AA_StringUint32(msgs[1]);
            ObjectGuid::LowType guidlow = player->GetGUIDLow();
            if (index >= 1 && index <= 4) {//已经翻过普通牌，不能再翻
                for (auto itr : aaCenter.aa_fanpai_pai[miyao][guidlow]) {
                    if (itr >= 1 && itr <= 4) {
                        return;
                    }
                }
                std::string gm = ".组合 *.翻牌 " + std::to_string(miyao) + " " + std::to_string(index) + "<$自身>";
                aaCenter.AA_DoCommand(player, gm.c_str());
                uint32 needid = aaCenter.aa_world_confs[79].value1;
                if (needid > 0) {
                    if (!aaCenter.M_CanNeed(player, needid, 1, false)) {
                        return;
                    }
                    aaCenter.M_Need(player, needid);
                }
                std::string gm1 = ".组合 *.翻牌 " + std::to_string(miyao) + " " + std::to_string(index + 4) + "<$自身>";
                aaCenter.AA_DoCommand(player, gm1.c_str());
            }
            else if (index >= 9 && index <= 12) {
                uint32 needid = aaCenter.aa_world_confs[80].value1;
                if (needid > 0) {
                    if (!aaCenter.M_CanNeed(player, needid)) {
                        return;
                    }
                    aaCenter.M_Need(player, needid);
                }
                std::string gm = ".组合 *.翻牌 " + std::to_string(miyao) + " " + std::to_string(index) + "<$自身>";
                aaCenter.AA_DoCommand(player, gm.c_str());
            }
        }
        else if (prefix == "1014") { //：请求栏目1014
            aaCenter.M_SendAA_Conf(player, prefix);
        }
        else if (prefix == "1015") { //点开商城：-点击翻页-请求页数 1015 当前栏目，选中页数 --- 点击栏目-请求页数 1015 当前栏目，页数1
            if (msgs.size() < 1) { return; }
            uint32 lan = aaCenter.AA_StringUint32(msgs[0]);
            if (lan == 0) {
                return;
            }
            aaCenter.M_SendAA_Conf(player, prefix);
        }
        else if (prefix == "1016") { //点开商城-购买商品-物品id
            if (!aaCenter.AA_VerifyCode("a105b")) {
                aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000请联系QQ643125009开通!");
                return;
            }
            if (msgs.size() < 3) { return; }
            uint32 lan = aaCenter.AA_StringUint32(msgs[0]);
            uint32 ye = aaCenter.AA_StringUint32(msgs[1]);
            uint32 index = aaCenter.AA_StringUint32(msgs[2]);
            if (lan == 0 || ye == 0 || index == 0) {
                return;
            }
            index = index - 1;
            uint32 confid = 0;
            if (aaCenter.aa_shop_zus[lan][ye].size() > index) {
                confid = aaCenter.aa_shop_zus[lan][ye][index];
            }
            if (confid == 0) {
                return;
            }
            AA_Shop conf = aaCenter.aa_shops[confid];
            if (conf.id) {
                if (player->IsInCombat() && conf.is_zhandou == 0) {
                    aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000战斗中无法使用!");
                    return;
                }
                if (conf.need > 0) {
                    if (!aaCenter.M_CanNeed(player, conf.need)) {
                        return;
                    }
                    else {
                        aaCenter.M_Need(player, conf.need);
                    }
                }
                Item* item = nullptr;
                if (conf.reward > 0) {
                    aaCenter.M_Reward(player, conf.reward);
                }
                else if (conf.entry > 0) {
                    item = aaCenter.AA_AddItem(player, conf.entry, 1);
                }
                if (conf.gm != "" && conf.gm != "0") {
                    aaCenter.AA_DoCommand(player, conf.gm.c_str());
                }
                if (conf.tanchuang > 0) {
                    aaCenter.AA_EventStart(player, conf.tanchuang);
                }
                if (conf.notice > 0) {
                    AA_Message aa_message;
                    if (item) {
                        aa_message.use_item = item;
                    }
                    AA_Notice notice = aaCenter.aa_notices[conf.notice];
                    aaCenter.AA_SendNotice(player, notice, true, aa_message);
                }
            }
        }
        else if (prefix == "1017") { //获取一页双甲数据
            //aaCenter.M_SendAA_Conf(player, prefix);
            if (!aaCenter.AA_VerifyCode("a106b")) {
                aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000请联系QQ643125009开通!");
                return;
            }
            if (msgs.size() < 1) { return; }
            uint32 ye = aaCenter.AA_StringUint32(msgs[0]);
            if (ye == 0) {
                return;
            }
            //总页数
            uint32 count = aaCenter.aa_item_shuangjias.size() / 6;
            if (aaCenter.aa_item_shuangjias.size() % 6 > 0) {
                count = count + 1;
            }
            //请求页数小于等于总页数，发送当前页数据
            if (ye <= count) {
                _AA_Shuangjia_1017(player, ye);
                std::string result = "{" + std::to_string(ye) + "," + std::to_string(count) + "}";
                //发送当前页数， 总页数
                aaCenter.M_SendClientAddonData(player, "1021", result);
            }
        }
        else if (prefix == "1018") { //镶嵌魂玉，如果有魂玉，就拆除魂玉再镶嵌
            if (!aaCenter.AA_VerifyCode("a106b")) {
                aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000请联系QQ643125009开通!");
                return;
            }
            if (msgs.size() < 5) { return; }
            uint32 id = aaCenter.AA_StringUint32(msgs[0]);
            uint32 index = aaCenter.AA_StringUint32(msgs[1]);
            ObjectGuid::LowType guidlow = aaCenter.AA_StringUint32(msgs[2]);
            ObjectGuid::LowType owner_guid = player->GetGUID().GetCounter();
            uint32 entry = aaCenter.AA_StringUint32(msgs[3]);
            uint32 ye = aaCenter.AA_StringUint32(msgs[4]);
            time_t timep;
            time(&timep); /*当前time_t类型UTC时间*/
            if (id == 0 || index == 0 || guidlow == 0 || entry == 0) {
                return;
            }
            AA_Item_Shuangjia conf = aaCenter.aa_item_shuangjias[id];
            if (conf.id == 0 || conf.items == "") {
                return;
            }
            std::vector<int32> v; v.clear();
            aaCenter.AA_StringToVectorInt(conf.items, v, ",");
            if (index > v.size()) {
                aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000插槽错误");
                return;
            }
            AA_Caiji_Item cj_conf;
            {
                int32 zu = v[index - 1];
                std::vector<uint32> conf_ids; conf_ids.clear();
                if (zu == 0) {
                    for (auto it : aaCenter.aa_caiji_items) {
                        AA_Caiji_Item conf = it.second;
                        if (conf.is_shuangjia > 0) {
                            conf_ids.push_back(conf.id);
                        }
                    }
                }
                else {
                    conf_ids = aaCenter.aa_caiji_item_zus[zu];
                }
                bool isOk = false;
                for (auto it : conf_ids) {
                    AA_Caiji_Item conf1 = aaCenter.aa_caiji_items[it];
                    if (conf1.entry == entry) {
                        cj_conf = conf1;
                        if (cj_conf.is_shuangjia == 0) {
                            aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000该物品无法进行此操作");
                            return;
                        }
                        isOk = true;
                    }
                    std::vector<ObjectGuid::LowType> guids = aa_item_instance_owner[owner_guid];
                    for (auto guid : guids) {
                        AA_Item_Instance i_conf = aaCenter.aa_item_instances[guid];
                        if (i_conf.weizhi != "") {
                            std::map<int32, int32> m; m.clear();
                            aaCenter.AA_StringToMap(i_conf.weizhi, m);
                            if (conf1.entry == i_conf.itemEntry) {
                                AA_Item_Shuangjia_Xianzhi conf = aaCenter.aa_item_shuangjia_xianzhis[zu];
                                if (conf.xiangqian == 1 && m.begin()->first == id) {
                                    aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000该类型物品每页只允许镶嵌1个");
                                    return;
                                }
                                if (conf.xiangqian == 2) {
                                    aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000该类型物品只允许镶嵌1个");
                                    return;
                                }
                            }
                        }
                    }
                }
                if (!isOk) {
                    aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000该物品无法进行此操作");
                    return;
                }

                uint32 needid = 0;
                if (conf.need_xiangqian != "") {
                    std::vector<int32> v; v.clear();
                    aaCenter.AA_StringToVectorInt(conf.need_xiangqian, v, ",");
                    if (v.size() > (index - 1)) {
                        needid = v[index - 1];
                    }
                }
                if (needid > 0) {
                    if (!aaCenter.M_CanNeed(player, needid)) {
                        return;
                    }
                }
                if (Item* item = aaCenter.GetItemByGUIDLow(player, guidlow))
                {
                    bool isOk = aaCenter.AA_Item_Shuangjia_Chaixie(player, id, index);
                    if (isOk) {
                        //镶嵌模式0表示不限制，1 表示每个页同一组的允许镶嵌1个，2表示所有页同一组的允许镶嵌1个
                        std::vector<ObjectGuid::LowType> guids = aa_item_instance_owner[owner_guid];
                        for (auto guid : guids) {
                            AA_Item_Instance i_conf = aaCenter.aa_item_instances[guid];
                            if (i_conf.weizhi != "") {
                                std::map<int32, int32> m; m.clear();
                                aaCenter.AA_StringToMap(i_conf.weizhi, m);
                                if (cj_conf.xiangqian == 1 && m.begin()->first == id && entry == i_conf.itemEntry) {
                                    aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000该物品每页只允许镶嵌1个");
                                    return;
                                }
                                if (cj_conf.xiangqian == 2 && entry == i_conf.itemEntry) {
                                    aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000该物品只允许镶嵌1个");
                                    return;
                                }
                            }
                        }
                        if (needid > 0) {
                            if (aaCenter.M_CanNeed(player, needid)) {
                                aaCenter.M_Need(player, needid);
                            }
                        }
                        AA_Item_Instance conf;
                        conf.guid = guidlow;
                        conf.itemEntry = entry;
                        conf.owner_guid = owner_guid;
                        conf.creatorGuid = item->GetCreator().GetCounter();
                        conf.giftCreatorGuid = item->GetGiftCreator().GetCounter();
                        conf.count = item->GetCount();
                        conf.duration = item->m_itemData->Expiration;

                        std::ostringstream ssSpells;
                        for (uint8 i = 0; i < item->m_itemData->SpellCharges.size() && i < item->GetBonus()->EffectCount; ++i)
                            ssSpells << item->GetSpellCharges(i) << ' ';

                        conf.charges = ssSpells.str();
                        conf.flags = item->m_itemData->DynamicFlags;
                        std::ostringstream ssEnchants;
                        for (uint8 i = 0; i < MAX_ENCHANTMENT_SLOT; ++i)
                        {
                            if (SpellItemEnchantmentEntry const* enchantment = sSpellItemEnchantmentStore.LookupEntry(item->GetEnchantmentId(EnchantmentSlot(i)));
                                enchantment && !enchantment->GetFlags().HasFlag(SpellItemEnchantmentFlags::DoNotSaveToDB))
                            {
                                ssEnchants << item->GetEnchantmentId(EnchantmentSlot(i)) << ' ';
                                ssEnchants << item->GetEnchantmentDuration(EnchantmentSlot(i)) << ' ';
                                ssEnchants << item->GetEnchantmentCharges(EnchantmentSlot(i)) << ' ';
                            }
                            else
                            {
                                ssEnchants << "0 0 0 ";
                            }
                        }
                        conf.enchantments = ssEnchants.str();
                        conf.randomPropertyId = item->GetItemRandomBonusListId();
                        conf.durability = item->m_itemData->Durability;
                        uint32 playedTime = item->m_itemData->CreatePlayedTime;
                        std::string text = item->GetText();

                        std::string weizhi = std::to_string(id) + " " + std::to_string(index);
                        conf.weizhi = weizhi;
                        conf.update_time = timep;
                        conf.isUpdate = true;
                        aaCenter.aa_item_instances[guidlow] = conf;
                        if (std::find(aa_item_instance_owner[owner_guid].begin(), aa_item_instance_owner[owner_guid].end(), guidlow) == aa_item_instance_owner[owner_guid].end()) {
                            aa_item_instance_owner[owner_guid].push_back(guidlow);
                        }
                        uint32 count = 1;
                        player->DestroyItemCount(item, count, true);
                        ItemTemplate const* pProto = sObjectMgr->GetItemTemplate(conf.itemEntry);
                        if (pProto)
                        {
                            Item* pItem = NewItemOrBag(pProto);
                            if (pItem->AA_LoadFromDB(guidlow, ObjectGuid::Empty, conf.itemEntry))
                            {
                                aaCenter.AA_ApplyItemBonuses(player, pItem, true, true);
                                player->ApplyItemEquipSpell(pItem, true);
                                player->ApplyEnchantment(pItem, true);
                                delete pItem;
                            }
                        }
                    }
                    _AA_Shuangjia_1017(player, ye);
                }
            }
        }
        else if (prefix == "1019") { //双击魂玉，拆除魂玉
            if (!aaCenter.AA_VerifyCode("a106b")) {
                aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000请联系QQ643125009开通!");
                return;
            }
            if (msgs.size() < 3) { return; }
            uint32 id = aaCenter.AA_StringUint32(msgs[0]);
            uint32 index = aaCenter.AA_StringUint32(msgs[1]);
            uint32 ye = aaCenter.AA_StringUint32(msgs[2]);
            aaCenter.AA_Item_Shuangjia_Chaixie(player, id, index);
            _AA_Shuangjia_1017(player, ye);
        }
        else if (prefix == "1020") { //获取魂玉激活icon
            aaCenter.M_SendAA_Conf(player, prefix);
        }
        else if (prefix == "3001") { //自定义ui传送点击传送
            if (!aaCenter.AA_VerifyCode("a300b")) {
                aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000请联系QQ643125009开通!");
                return;
            }
            if (msgs.size() < 2) { return; }
            uint32 miyao = aaCenter.AA_StringUint32(msgs[0]);
            uint32 id = aaCenter.AA_StringUint32(msgs[1]);
            if (aaCenter.aa_ui_miyaos.find(miyao) != aaCenter.aa_ui_miyaos.end()) {
                if (aaCenter.aa_ui_miyaos[miyao] == 1) {
                    AA_UI_Chuansong conf = aaCenter.aa_ui_chuansongs[id];
                    if (conf.gm != "") {
                        aaCenter.AA_DoCommand(player, conf.gm.c_str());
                    }
                }
                aaCenter.aa_ui_miyaos.erase(miyao);
            }
        }
        else if (prefix == "3020") { //自定义ui时装点击激活
            if (!aaCenter.AA_VerifyCode("a301b")) {
                aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000请联系QQ643125009开通!");
                return;
            }
            if (msgs.size() < 2) { return; }
            uint32 lan = aaCenter.AA_StringUint32(msgs[0]);
            uint32 index = aaCenter.AA_StringUint32(msgs[1]);
            //ObjectGuid::LowType guidlow = aaCenter.AA_StringUint32(msgs[2]);
            ObjectGuid::LowType owner_guid = player->GetGUIDLow();
            //uint32 entry = aaCenter.AA_StringUint32(msgs[3]);
            time_t timep;
            time(&timep); /*当前time_t类型UTC时间*/
            if (lan < 101 || index < 1) {
                return;
            }
            AA_UI_Shizhuang uiconf = aaCenter.aa_ui_shizhuangs[lan - 101 + 1][index];
            if (uiconf.item == 0)
                return;

            if (uiconf.need > 0) {
                if (!aaCenter.M_CanNeed(player, uiconf.need)) {
                    return;
                }
            }
            bool isOk = aaCenter.AA_Item_Shuangjia_Chaixie(player, lan, index, true);
            if (isOk) {
                if (uiconf.need > 0) {
                    if (aaCenter.M_CanNeed(player, uiconf.need)) {
                        aaCenter.M_Need(player, uiconf.need);
                    }
                }
                Item* item = aaCenter.AA_AddItem(player, uiconf.item, 1);
                if (item)
                {
                    ObjectGuid::LowType guidlow = item->GetGUIDLow();
                    AA_Item_Instance conf;
                    conf.guid = guidlow;
                    conf.itemEntry = uiconf.item;
                    conf.owner_guid = owner_guid;
                    conf.creatorGuid = item->GetCreator().GetCounter();
                    conf.giftCreatorGuid = item->GetGiftCreator().GetCounter();
                    conf.count = item->GetCount();
                    conf.duration = item->m_itemData->Expiration;

                    std::ostringstream ssSpells;
                    for (uint8 i = 0; i < item->m_itemData->SpellCharges.size() && i < item->GetBonus()->EffectCount; ++i)
                        ssSpells << item->GetSpellCharges(i) << ' ';

                    conf.charges = ssSpells.str();
                    conf.flags = item->m_itemData->DynamicFlags;
                    std::ostringstream ssEnchants;
                    for (uint8 i = 0; i < MAX_ENCHANTMENT_SLOT; ++i)
                    {
                        if (SpellItemEnchantmentEntry const* enchantment = sSpellItemEnchantmentStore.LookupEntry(item->GetEnchantmentId(EnchantmentSlot(i)));
                            enchantment && !enchantment->GetFlags().HasFlag(SpellItemEnchantmentFlags::DoNotSaveToDB))
                        {
                            ssEnchants << item->GetEnchantmentId(EnchantmentSlot(i)) << ' ';
                            ssEnchants << item->GetEnchantmentDuration(EnchantmentSlot(i)) << ' ';
                            ssEnchants << item->GetEnchantmentCharges(EnchantmentSlot(i)) << ' ';
                        }
                        else
                        {
                            ssEnchants << "0 0 0 ";
                        }
                    }
                    conf.enchantments = ssEnchants.str();
                    conf.randomPropertyId = item->GetItemRandomBonusListId();
                    conf.durability = item->m_itemData->Durability;
                    uint32 playedTime = item->m_itemData->CreatePlayedTime;
                    std::string text = item->GetText();

                    std::string weizhi = std::to_string(lan) + " " + std::to_string(index);
                    conf.weizhi = weizhi;
                    conf.update_time = timep;
                    conf.isUpdate = true;
                    aaCenter.aa_item_instances[guidlow] = conf;
                    if (std::find(aa_item_instance_owner[owner_guid].begin(), aa_item_instance_owner[owner_guid].end(), guidlow) == aa_item_instance_owner[owner_guid].end()) {
                        aa_item_instance_owner[owner_guid].push_back(guidlow);
                    }
                    uint32 count = 1;
                    player->DestroyItemCount(item, count, true);
                    ItemTemplate const* pProto = sObjectMgr->GetItemTemplate(conf.itemEntry);
                    if (pProto)
                    {
                        Item* pItem = NewItemOrBag(pProto);
                        if (pItem->AA_LoadFromDB(guidlow, ObjectGuid::Empty, conf.itemEntry))
                        {
                            aaCenter.AA_ApplyItemBonuses(player, pItem, true, true);
                            player->ApplyItemEquipSpell(pItem, true);
                            player->ApplyEnchantment(pItem, true);
                            if (uiconf.notice > 0) {
                                AA_Message aa_message;
                                aa_message.use_item = pItem;
                                AA_Notice notice = aaCenter.aa_notices[uiconf.notice];
                                aaCenter.AA_SendNotice(player, notice, true, aa_message);
                            }
                            delete pItem;
                        }
                    }
                }
                _AA_Shizhuang_3023(player, lan);
                if (uiconf.modelid > 0) {
                    aaCenter.aa_bianshen1[player->GetGUIDLow()] = 0;
                    aaCenter.aa_bianshen2[player->GetGUIDLow()] = 0;
                    aaCenter.aa_bianshen3[player->GetGUIDLow()] = 0;
                    player->RestoreDisplayId();
                    player->SetObjectScale(1);
                    std::string gm = ".组合 *.变身 " + std::to_string(uiconf.modelid) + " " + std::to_string(uiconf.scale) + "<$自身>";
                    aaCenter.AA_DoCommand(player, gm.c_str());
                }
            }
        }
        else if (prefix == "3021") { //自定义ui时装点击保存形象
            if (!aaCenter.AA_VerifyCode("a301b")) {
                aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000请联系QQ643125009开通!");
                return;
            }
            if (msgs.size() < 2) { return; }
            uint32 lan = aaCenter.AA_StringUint32(msgs[0]);
            uint32 index = aaCenter.AA_StringUint32(msgs[1]);
            if (lan < 101 || index < 1) {
                return;
            }
            ObjectGuid::LowType ownerguidlow = player->GetGUIDLow();
            AA_UI_Shizhuang conf = aaCenter.aa_ui_shizhuangs[lan - 101 + 1][index];
            if (conf.modelid == 0) {
                return;
            }
            std::string weizhi = std::to_string(lan) + " " + std::to_string(index);
            bool isOk = false;
            for (auto guidlow : aa_item_instance_owner[ownerguidlow])
            {
                if (guidlow == 0) {
                    continue;
                }
                AA_Item_Instance iconf = aa_item_instances[guidlow];
                if (iconf.weizhi == "" || iconf.weizhi != weizhi) {
                    continue;
                }
                isOk = true;
                break;
            }
            if (isOk) {
                if (conf.modelid > 0) {
                    aaCenter.aa_bianshen1[player->GetGUIDLow()] = 0;
                    aaCenter.aa_bianshen2[player->GetGUIDLow()] = 0;
                    aaCenter.aa_bianshen3[player->GetGUIDLow()] = 0;
                    player->RestoreDisplayId();
                    player->SetObjectScale(1);
                    std::string gm = ".组合 *.变身 " + std::to_string(conf.modelid) + " " + std::to_string(conf.scale) + "<$自身>";
                    aaCenter.AA_DoCommand(player, gm.c_str());
                }
            }
            else {
                aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000无法保存外观，没有激活!");
            }
        }
        else if (prefix == "3022") { //自定义ui时装点击切换外观
            if (!aaCenter.AA_VerifyCode("a301b")) {
                aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000请联系QQ643125009开通!");
                return;
            }
            if (msgs.size() < 2) { return; }
            uint32 lan = aaCenter.AA_StringUint32(msgs[0]);
            uint32 index = aaCenter.AA_StringUint32(msgs[1]);
            if (lan < 101 || index < 1) {
                return;
            }
            ObjectGuid::LowType ownerguidlow = player->GetGUIDLow();
            AA_UI_Shizhuang conf = aaCenter.aa_ui_shizhuangs[lan - 101 + 1][index];
            if (conf.modelid == 0) {
                return;
            }
            aaCenter.aa_bianshen1[player->GetGUIDLow()] = 0;
            aaCenter.aa_bianshen2[player->GetGUIDLow()] = 0;
            aaCenter.aa_bianshen3[player->GetGUIDLow()] = 0;
            player->RestoreDisplayId();
            player->SetObjectScale(1);
            std::string gm = ".组合 *.变身 " + std::to_string(conf.modelid) + " " + std::to_string(conf.scale) + " " + "5<$自身>";
            aaCenter.AA_DoCommand(player, gm.c_str());
        }
        else if (prefix == "3023") { //自定义ui时装 获取一页数据
            if (!aaCenter.AA_VerifyCode("a301b")) {
                aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000请联系QQ643125009开通!");
                return;
            }
            if (msgs.size() < 1) { return; }
            uint32 lan = aaCenter.AA_StringUint32(msgs[0]);
            if (lan < 101) {
                return;
            }
            _AA_Shizhuang_3023(player, lan);
        }
        else if (prefix == "3030") { //自定义ui神器 点击激活
            if (!aaCenter.AA_VerifyCode("a302b")) {
                aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000请联系QQ643125009开通!");
                return;
            }
            if (msgs.size() < 2) { return; }
            uint32 lan = aaCenter.AA_StringUint32(msgs[0]);
            uint32 index = aaCenter.AA_StringUint32(msgs[1]);
            //ObjectGuid::LowType guidlow = aaCenter.AA_StringUint32(msgs[2]);
            ObjectGuid::LowType owner_guid = player->GetGUIDLow();
            uint32 entry = 0;
            if (lan < 201 || index < 1) {
                return;
            }
            ObjectGuid::LowType guidlow = player->GetGUID().GetCounter();
            std::vector<ObjectGuid::LowType> guids = aa_item_instance_owner[guidlow];
            time_t timep;
            time(&timep); /*当前time_t类型UTC时间*/
            for (auto guid : guids) {
                AA_Item_Instance conf = aaCenter.aa_item_instances[guid];
                if (conf.weizhi != "") {
                    std::map<int32, int32> m; m.clear();
                    aaCenter.AA_StringToMap(conf.weizhi, m);
                    if (m.begin()->first == lan && m.begin()->second == index) { //查找到已有的装备
                        ItemTemplate const* pProto = sObjectMgr->GetItemTemplate(conf.itemEntry);
                        if (pProto) {
                            entry = conf.itemEntry;
                        }
                    }
                }
            }
            AA_UI_Shenqi uiconf;
            if (entry > 0) { //如果已经激活，计算出升级后装备的entry，找到升级后装备的conf
                AA_UI_Shenqi conf = aa_ui_shenqi_entrys[entry];
                uint32 level = conf.level + 1;
                if (aaCenter.aa_ui_shenqis[lan - 201 + 1][index][level].item > 0) {
                    uiconf = aaCenter.aa_ui_shenqis[lan - 201 + 1][index][level];
                }
            }
            else { //如果没有激活，升级conf=等级1的conf
                uiconf = aaCenter.aa_ui_shenqis[lan - 201 + 1][index][1];
            }
            if (uiconf.item == 0)
                return;

            if (uiconf.need > 0) {
                if (!aaCenter.M_CanNeed(player, uiconf.need)) {
                    return;
                }
            }
            bool isOk = aaCenter.AA_Item_Shuangjia_Chaixie(player, lan, index, true);
            if (isOk) {
                if (uiconf.need > 0) {
                    if (aaCenter.M_CanNeed(player, uiconf.need)) {
                        aaCenter.M_Need(player, uiconf.need);
                    }
                }
                Item* item = aaCenter.AA_AddItem(player, uiconf.item, 1);
                if (item)
                {
                    ObjectGuid::LowType guidlow = item->GetGUIDLow();
                    AA_Item_Instance conf;
                    conf.guid = guidlow;
                    conf.itemEntry = uiconf.item;
                    conf.owner_guid = owner_guid;
                    conf.creatorGuid = item->GetCreator().GetCounter();
                    conf.giftCreatorGuid = item->GetGiftCreator().GetCounter();
                    conf.count = item->GetCount();
                    conf.duration = item->m_itemData->Expiration;

                    std::ostringstream ssSpells;
                    for (uint8 i = 0; i < item->m_itemData->SpellCharges.size() && i < item->GetBonus()->EffectCount; ++i)
                        ssSpells << item->GetSpellCharges(i) << ' ';

                    conf.charges = ssSpells.str();
                    conf.flags = item->m_itemData->DynamicFlags;
                    std::ostringstream ssEnchants;
                    for (uint8 i = 0; i < MAX_ENCHANTMENT_SLOT; ++i)
                    {
                        if (SpellItemEnchantmentEntry const* enchantment = sSpellItemEnchantmentStore.LookupEntry(item->GetEnchantmentId(EnchantmentSlot(i)));
                            enchantment && !enchantment->GetFlags().HasFlag(SpellItemEnchantmentFlags::DoNotSaveToDB))
                        {
                            ssEnchants << item->GetEnchantmentId(EnchantmentSlot(i)) << ' ';
                            ssEnchants << item->GetEnchantmentDuration(EnchantmentSlot(i)) << ' ';
                            ssEnchants << item->GetEnchantmentCharges(EnchantmentSlot(i)) << ' ';
                        }
                        else
                        {
                            ssEnchants << "0 0 0 ";
                        }
                    }
                    conf.enchantments = ssEnchants.str();
                    conf.randomPropertyId = item->GetItemRandomBonusListId();
                    conf.durability = item->m_itemData->Durability;
                    uint32 playedTime = item->m_itemData->CreatePlayedTime;
                    std::string text = item->GetText();

                    std::string weizhi = std::to_string(lan) + " " + std::to_string(index);
                    conf.weizhi = weizhi;
                    conf.update_time = timep;
                    conf.isUpdate = true;

                    aaCenter.aa_item_instances[guidlow] = conf;
                    if (std::find(aa_item_instance_owner[owner_guid].begin(), aa_item_instance_owner[owner_guid].end(), guidlow) == aa_item_instance_owner[owner_guid].end()) {
                        aa_item_instance_owner[owner_guid].push_back(guidlow);
                    }
                    uint32 count = 1;
                    player->DestroyItemCount(item, count, true);
                    ItemTemplate const* pProto = sObjectMgr->GetItemTemplate(conf.itemEntry);
                    if (pProto)
                    {
                        Item* pItem = NewItemOrBag(pProto);
                        if (pItem->AA_LoadFromDB(guidlow, ObjectGuid::Empty, conf.itemEntry))
                        {
                            aaCenter.AA_ApplyItemBonuses(player, pItem, true, true);
                            player->ApplyItemEquipSpell(pItem, true);
                            player->ApplyEnchantment(pItem, true);
                            delete pItem;
                        }
                    }
                }
                _AA_Shenqi_3031(player, lan);
            }
        }
        else if (prefix == "3031") { //自定义ui神器 获取一页数据
            if (!aaCenter.AA_VerifyCode("a302b")) {
                aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000请联系QQ643125009开通!");
                return;
            }
            if (msgs.size() < 1) { return; }
            uint32 lan = aaCenter.AA_StringUint32(msgs[0]);
            if (lan < 201) {
                return;
            }
            _AA_Shenqi_3031(player, lan);
        }
        else if (prefix == "3040") { //自定义ui捐献 获取个人数据
            if (!aaCenter.AA_VerifyCode("a303b")) {
                aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000请联系QQ643125009开通!");
                return;
            }
            //1、单位，个人捐献，最少捐献
            //2、排名，玩家信息，捐赠数量，称号物品
            //3、是否激活，光环描述
            std::string result = "{\"";
            std::string danwei = aaCenter.aa_world_confs[64].value2;
            uint32 zuishao = aaCenter.aa_world_confs[94].value1;
            uint32 juanxian = 0;
            if (aaCenter.aa_character_juanxians.find(player->GetGUIDLow()) != aaCenter.aa_character_juanxians.end())
            {
                AA_Character_Juanxian conf = aa_character_juanxians[player->GetGUIDLow()];
                juanxian = conf.juanxian;
            }
            result += danwei; result += "\",";
            result += std::to_string(juanxian); result += ",";
            result += std::to_string(zuishao); result += "}";
            aaCenter.M_SendClientAddonData(player, "3041", result);
            result = "{[";
            std::vector<std::string> names; names.clear();
            std::vector<uint32> juanxians; juanxians.clear();
            for (size_t i = 0; i < 5; i++)
            {
                if (aaCenter.aa_juanxians.size() > i) {
                    std::pair<uint32, uint32> itr = aaCenter.aa_juanxians[i];
                    ObjectGuid::LowType guidlow = itr.first;
                    uint32 juanxian = itr.second;
                    uint32 paiming = i + 1;
                    std::string name = "";
                    {
                        QueryResult result = CharacterDatabase.PQuery("SELECT name FROM characters WHERE deleteDate IS NULL AND guid = {}", guidlow);
                        if (result)
                        {
                            Field* fields = result->Fetch();
                            name = fields[0].GetString();
                        }
                    }
                    names.push_back(name);
                    juanxians.push_back(juanxian);
                }
            }
            for (size_t i = 0; i < 5; i++)
            {
                AA_UI_Juanxian_Paiming conf = aaCenter.aa_ui_juanxian_paimings[i + 1];
                if (conf.guanghuans == "" || conf.guanghuans == "0") {
                    break;
                }
                std::string name = "";
                if (names.size() > i) {
                    name = names[i];
                }
                uint32 juanxian = 0;
                if (juanxians.size() > i) {
                    juanxian = juanxians[i];
                }
                result += std::to_string(i + 1); result += "]={\"";
                result += name; result += "\",";
                result += std::to_string(juanxian); result += ",";
                uint32 entry = conf.guanghuan_item;
                std::string itemLink = aaCenter.AA_GetItemLink(entry);
                result += "\"\\\""; result += itemLink; result += "\\\"\"}";
                result += ",[";
            }
            if (result != "") {
                aaCenter.AA_StringReplaceLast(result, ",[", "");
            }
            result += "}";
            if (result != "{[}") {
                aaCenter.M_SendClientAddonData(player, "3042", result);
            }

            result = "{[";
            for (auto itr : aaCenter.aa_ui_juanxian_shuliangs) {
                AA_UI_Juanxian_Shuliang conf = itr.second;
                uint32 id = itr.first;
                if (conf.guanghuans == "" || conf.guanghuans == "0") {
                    break;
                }
                uint32 isJx = 0;
                if (juanxian >= conf.id) {
                    isJx = 1;
                }
                result += std::to_string(id); result += "]={";
                result += std::to_string(isJx); result += ",\"";
                result += conf.guanghuan_details;  result += "\"}";
                result += ",[";
            }
            if (result != "") {
                aaCenter.AA_StringReplaceLast(result, ",[", "");
            }
            result += "}";
            if (result != "{[") {
                aaCenter.M_SendClientAddonData(player, "3043", result);
            }
        }
        else if (prefix == "3041") { //自定义ui捐献 捐献
            if (!aaCenter.AA_VerifyCode("a303b")) {
                aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000请联系QQ643125009开通!");
                return;
            }
            if (msgs.size() < 1) { return; }
            ObjectGuid::LowType guidlow = player->GetGUIDLow();
            uint32 juanxian = aaCenter.AA_StringUint32(msgs[0]);
            if (juanxian == 0) {
                return;
            }
            std::string danwei = aaCenter.aa_world_confs[64].value2;
            AA_Character_Juanxian jconf;
            if (aaCenter.aa_character_juanxians.find(guidlow) != aaCenter.aa_character_juanxians.end())
            {
                jconf = aaCenter.aa_character_juanxians[guidlow];
            }
            if (jconf.juanxian == 0) {
                uint32 zuishao = aaCenter.aa_world_confs[94].value1;
                if (juanxian < zuishao) {
                    std::string zs = "|cff00FFFF[系统提示]|cffFF0000第一次最少捐献" + std::to_string(zuishao) + danwei;
                    aaCenter.AA_SendMessage(player, 1, zs.c_str());
                    return;
                }
            }
            uint32 accountid = player->GetSession()->GetAccountId();
            AA_Account conf = aaCenter.aa_accounts[accountid];
            if (conf.jifen >= juanxian) {
                time_t timep;
                time(&timep); /*当前time_t类型UTC时间*/
                uint32 val = conf.jifen - juanxian;
                uint32 jx = jconf.juanxian + juanxian;
                conf.jifen = val;
                aaCenter.aa_accounts[accountid].jifen = val;
                LoginDatabase.PExecute("UPDATE _aa_account SET 当前积分 = {}, 更新时间=0 WHERE id = {};", val, accountid);
                aaCenter.aa_character_juanxians[guidlow].guid = guidlow;
                aaCenter.aa_character_juanxians[guidlow].juanxian = jx;
                aaCenter.aa_character_juanxians[guidlow].name = player->GetName();
                aaCenter.aa_character_juanxians[guidlow].isUpdate = true;
                aaCenter.aa_character_juanxians[guidlow].update_time = timep;
                aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFFFF00捐献成功!");
                aaCenter.M_SendClientAddonData(player, "3044", "{1}");

                //刷新数据，重置当前玩家捐献数量属性，重置所有玩家排行光环
                aaCenter.AA_UpdateJuanxianPaihang();
            } else {
                std::string msg = "|cff00FFFF[系统提示]|cffFF0000你的" + danwei + "不足"+ std::to_string(juanxian) +"，无法捐献。|r";
                aaCenter.AA_SendMessage(player, 1, msg.c_str());
            }
        }
        else if (prefix == "3050") { //自定义ui集结号 请求队伍信息
            if (!aaCenter.AA_VerifyCode("a304b")) {
                aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000请联系QQ643125009开通!");
                return;
            }
            aaCenter.M_SendAA_Conf(player, prefix);
        }
        else if (prefix == "3051") { //自定义ui集结号 请求列表信息
            aaCenter.M_SendAA_Conf(player, prefix);
        }
        else if (prefix == "3052") { //自定义ui集结号 创建活动
            if (!aaCenter.AA_VerifyCode("a304b")) {
                aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000请联系QQ643125009开通!");
                return;
            }
            if (msgs.size() < 2) { return; }
            uint32 id = aaCenter.AA_StringUint32(msgs[0]);
            std::string msg = msgs[1];
            if (id == 0) {
                aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000请选择你要创建的活动地图!"); return;
            }
            AA_UI_Jijie conf = aaCenter.aa_ui_jijies[id];
            if (conf.id == 0) {
                aaCenter.M_SendAA_Conf(player, "3050");
                aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000系统错误3052"); return;
            }
            if (conf.time == 0) {
                aaCenter.M_SendAA_Conf(player, "3050");
                aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000系统错误3052"); return;
            }
            if (msg == "" || msg == "输入活动说明") {
                aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000请输入活动说明!");
                return;
            }
            if (conf.need > 0) {
                if (aaCenter.M_CanNeed(player, conf.need)) {
                    aaCenter.M_Need(player, conf.need);
                }
                else {
                    return;
                }
            }
            //屏蔽聊天信息
            std::unordered_map<std::string, AA_Chat>::iterator iter;
            for (iter = aaCenter.aa_chats.begin(); iter != aaCenter.aa_chats.end(); iter++)
            {
                AA_Chat conf = iter->second;
                if (conf.msg == "") {
                    continue;
                }
                aaCenter.AA_StringToLower(conf.msg);
                string::size_type idx = msg.find(conf.msg);//在a中查找b.
                if (idx != string::npos) {
                    msg = conf.tomsg;
                }
            }
            ObjectGuid::LowType guidlow = player->GetGUIDLow();
            if (std::find(aaCenter.aa_jijie_guidlows.begin(), aaCenter.aa_jijie_guidlows.end(), guidlow) != aaCenter.aa_jijie_guidlows.end()) {
                aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000你无法创建多个活动"); return;
            }
            aaCenter.aa_jijie_guidlows.push_back(guidlow);
            player->aa_jijie_guidlow = guidlow;
            aaCenter.aa_jijie_times.push_back(conf.time * 1000);
            aaCenter.aa_jijie_ids.push_back(id);
            aaCenter.aa_jijie_msgs.push_back(msg);

            //发送队伍列表信息
            std::set<Player*> players = aaCenter.GetOnlinePlayers();
            for (auto p : players) {
                aaCenter.M_SendAA_Conf(p, "3050");
            }
        }
        else if (prefix == "3053") { //自定义ui集结号 加入活动
            if (!aaCenter.AA_VerifyCode("a304b")) {
                aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000请联系QQ643125009开通!");
                return;
            }
            if (msgs.size() < 1) { return; }
            uint32 index = aaCenter.AA_StringUint32(msgs[0]);
            if (index == 0) {
                return;
            }
            index = index - 1;
            if (player->aa_jijie_guidlow > 0) {
                aaCenter.M_SendAA_Conf(player, "3050");
                aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000无法加入多个活动!");
                return;
            }
            if (aaCenter.aa_jijie_guidlows.size() <= index) {
                aaCenter.M_SendAA_Conf(player, "3050");
                aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000该活动不存在!");
                return;
            }
            ObjectGuid::LowType guidlow_dz = aaCenter.aa_jijie_guidlows[index];
            uint32 id = aaCenter.aa_jijie_ids[index];
            AA_UI_Jijie conf = aaCenter.aa_ui_jijies[id];
            if (guidlow_dz == 0) {
                aaCenter.M_SendAA_Conf(player, "3050");
                aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000该活动不存在!");
                return;
            }
            if (aaCenter.aa_jijie_times[index] == 0) {
                aaCenter.M_SendAA_Conf(player, "3050");
                aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000该活动已经结束!");
                return;
            }
            if (conf.need > 0) {
                if (aaCenter.M_CanNeed(player, conf.need)) {
                    aaCenter.M_Need(player, conf.need);
                }
                else {
                    return;
                }
            }
            player->aa_jijie_guidlow = guidlow_dz;

            aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFFFF00加入成功，请等待活动开启！");

            //集结号
            //2、人数满了强行开启活动
            std::set<Player*> players = aaCenter.GetOnlinePlayers();
            std::set<Player*> ps; ps.clear();
            std::map<ObjectGuid::LowType, std::set<Player*>> jj_players; jj_players.clear();
            for (auto p : players)
            {
                if (p->aa_jijie_guidlow == guidlow_dz) {
                    ps.insert(p);
                }
            }
            if (conf.count_max > 0 && ps.size() >= conf.count_max) {
                if (ps.size() > 1) {
                    if (Player* p_dz = ObjectAccessor::FindPlayerByLowGUID(guidlow_dz)) {
                        //解散队长的队伍，创建一个新队伍
                        Group* group = p_dz->GetGroup();
                        if (group && group->IsMember(p_dz->GetGUID())) {
                            group->RemoveMember(p_dz->GetGUID());
                        }
                        Group* new_group = new Group;
                        if (new_group->Create(p_dz))
                        {
                            new_group->ConvertToRaid();
                        }
                        for (auto p : ps) {
                            p->aa_jijie_guidlow = 0;
                            if (p != p_dz) {
                                //解散队员的队伍，加入队长的队伍
                                Group* group = p->GetGroup();
                                if (group && group->IsMember(p->GetGUID())) {
                                    group->RemoveMember(p->GetGUID());
                                }
                                if (!new_group->IsFull()) {
                                    new_group->AddMember(p);
                                }
                            }
                        }
                    }
                }
                for (auto p : ps) {
                    //执行gm命令
                    if (conf.gm != "" && conf.gm != "") {
                        aaCenter.AA_DoCommand(p, conf.gm.c_str());
                    }
                }
                aaCenter.aa_jijie_guidlows.erase(aaCenter.aa_jijie_guidlows.begin() + index);
                aaCenter.aa_jijie_ids.erase(aaCenter.aa_jijie_ids.begin() + index);
                aaCenter.aa_jijie_times.erase(aaCenter.aa_jijie_times.begin() + index);
                aaCenter.aa_jijie_msgs.erase(aaCenter.aa_jijie_msgs.begin() + index);
            }

            //发送队伍列表信息
            for (auto p : players) {
                aaCenter.M_SendAA_Conf(p, "3050");
            }
        }
        else if (prefix == "3054") { //自定义ui集结号 离开活动
            if (!aaCenter.AA_VerifyCode("a304b")) {
                aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000请联系QQ643125009开通!");
                return;
            }
            if (msgs.size() < 1) { return; }
            uint32 index = aaCenter.AA_StringUint32(msgs[0]);
            if (index == 0) {
                return;
            }
            index = index - 1;
            if (aaCenter.aa_jijie_guidlows.size() <= index) {
                return;
            }

            ObjectGuid::LowType guidlow_dz = aaCenter.aa_jijie_guidlows[index];
            std::set<Player*> players = aaCenter.GetOnlinePlayers();
            bool isOk = true;
            if (guidlow_dz == 0) {
                isOk = false;
            }
            if (isOk) {
                for (auto p : players)
                {
                    if (p == player) {
                        continue;
                    }
                    if (p->aa_jijie_guidlow == player->aa_jijie_guidlow) {
                        isOk = false; //队伍里有人
                        break;
                    }
                }
            }
            player->aa_jijie_guidlow = 0;
            if (isOk) {
                //如果离开队伍，队伍里没人了，解散队伍
                aaCenter.aa_jijie_guidlows.erase(aaCenter.aa_jijie_guidlows.begin() + index);
                aaCenter.aa_jijie_ids.erase(aaCenter.aa_jijie_ids.begin() + index);
                aaCenter.aa_jijie_times.erase(aaCenter.aa_jijie_times.begin() + index);
                aaCenter.aa_jijie_msgs.erase(aaCenter.aa_jijie_msgs.begin() + index);
            }
            else {
                //如果自己是队长离开队伍，切换队长
                if (player->GetGUIDLow() == guidlow_dz) {
                    ObjectGuid::LowType new_guidlow = 0;
                    for (auto p : players)
                    {
                        if (p->aa_jijie_guidlow == guidlow_dz) {
                            new_guidlow = p->GetGUIDLow();
                            break;
                        }
                    }
                    if (new_guidlow > 0) {
                        for (auto p : players)
                        {
                            if (p->aa_jijie_guidlow == guidlow_dz) {
                                p->aa_jijie_guidlow = new_guidlow;
                            }
                        }
                        for (size_t i = 0; i < aaCenter.aa_jijie_guidlows.size(); i++)
                        {
                            if (aaCenter.aa_jijie_guidlows[i] == guidlow_dz) {
                                aaCenter.aa_jijie_guidlows[i] = new_guidlow;
                                break;
                            }
                        }
                    }
                }
            }

            //发送队伍列表信息、
            for (auto p : players) {
                aaCenter.M_SendAA_Conf(p, "3050");
            }
        }
    }
    catch (std::exception const& e) {}
}

bool AACenter::AA_UpdateJuanxianShuliang(Player *p)
{
    ObjectGuid::LowType guidlow = p->GetGUIDLow();
    if (aaCenter.aa_character_juanxians.find(p->GetGUIDLow()) == aaCenter.aa_character_juanxians.end())
    {
        return false;
    }
    AA_Character_Juanxian conf = aaCenter.aa_character_juanxians[guidlow];
    if (conf.juanxian > 0) {
        for (auto itr : aaCenter.aa_ui_juanxian_shuliangs) {
            AA_UI_Juanxian_Shuliang jconf = itr.second;
            std::vector<int32> spells; spells.clear();
            if (jconf.guanghuans != "" && jconf.guanghuans != "0") {
                aaCenter.AA_StringToVectorInt(jconf.guanghuans, spells, ",");
            }
            if (jconf.id > 0 && conf.juanxian >= jconf.id) {
                for (auto it : spells) {
                    if (!p->HasAura(it)) {
                        p->AddAura(it, p);
                    }
                }
            }
            else {
                for (auto it : spells) {
                    if (p->HasAura(it)) {
                        p->RemoveAura(it);
                    }
                }
            }
        }
    }

    return true;
}

bool AACenter::AA_UpdateJuanxianPaihang()
{
    aaCenter.aa_juanxians.clear();
    aaCenter.aa_juanxian_players.clear();

    std::map<uint32, uint32> juanxians1; juanxians1.clear();
    for (auto itr : aaCenter.aa_character_juanxians) {
        AA_Character_Juanxian conf = itr.second;
        juanxians1[conf.guid] = conf.juanxian;
    }
    yewai_paihangpx(aaCenter.aa_juanxians, juanxians1);

    uint32 i = 1;
    for (size_t i = 0; i < 5; i++)
    {
        if (aaCenter.aa_juanxians.size() > i) {
            std::pair<uint32, uint32> itr = aaCenter.aa_juanxians[i];
            ObjectGuid::LowType guidlow = itr.first;
            uint32 paiming = i + 1;
            aaCenter.aa_juanxian_players[guidlow] = paiming;
        }
    }
    return true;
}

void AACenter::DeleteAAData_Characters()
{
    {
        TC_LOG_INFO("server.loading", "正在清除垃圾数据 _aa_account...");
        uint32 oldMSTime = getMSTime();
        LoginDatabase.Execute("DELETE FROM _aa_account WHERE id not in (select id from account)");
        TC_LOG_INFO("server.loading", ">> 成功清除垃圾数据 _aa_account 用时 {} 毫秒", GetMSTimeDiffToNow(oldMSTime));
    }
    {
        TC_LOG_INFO("server.loading", "正在清除垃圾数据 _玩家宠物数据...");
        uint32 oldMSTime = getMSTime();
        CharacterDatabase.Execute("DELETE FROM _玩家宠物数据 WHERE guid not in (select guid from item_instance)");
        TC_LOG_INFO("server.loading", ">> 成功清除垃圾数据 _玩家宠物数据 用时 {} 毫秒", GetMSTimeDiffToNow(oldMSTime));
    }
    {
        TC_LOG_INFO("server.loading", "正在清除垃圾数据 _玩家双甲数据x...");
        uint32 oldMSTime = getMSTime();
        CharacterDatabase.Execute("DELETE FROM _玩家双甲数据x WHERE 装备位置 = ''");
        TC_LOG_INFO("server.loading", ">> 成功清除垃圾数据 _玩家双甲数据x 用时 {} 毫秒", GetMSTimeDiffToNow(oldMSTime));
    }
    {
        TC_LOG_INFO("server.loading", "正在清除垃圾数据 _玩家装备数据...");
        uint32 oldMSTime = getMSTime();
        CharacterDatabase.Execute("DELETE FROM _玩家装备数据 WHERE guid not in (SELECT guid FROM item_instance UNION ALL SELECT guid FROM _玩家双甲数据x)");
        TC_LOG_INFO("server.loading", ">> 成功清除垃圾数据 _玩家装备数据 用时 {} 毫秒", GetMSTimeDiffToNow(oldMSTime));
    }
    {
        TC_LOG_INFO("server.loading", "正在清除垃圾数据 _玩家巅峰属性...");
        uint32 oldMSTime = getMSTime();
        CharacterDatabase.Execute("DELETE FROM _玩家巅峰属性 WHERE guid not in (select guid from characters)");
        TC_LOG_INFO("server.loading", ">> 成功清除垃圾数据 _玩家巅峰属性 用时 {} 毫秒", GetMSTimeDiffToNow(oldMSTime));
    }
    {
        TC_LOG_INFO("server.loading", "正在清除垃圾数据 _玩家斗气属性...");
        uint32 oldMSTime = getMSTime();
        CharacterDatabase.Execute("DELETE FROM _玩家斗气属性 WHERE guid not in (select guid from characters)");
        TC_LOG_INFO("server.loading", ">> 成功清除垃圾数据 _玩家斗气属性 用时 {} 毫秒", GetMSTimeDiffToNow(oldMSTime));
    }
    {
        TC_LOG_INFO("server.loading", "正在清除垃圾数据 _玩家军衔属性...");
        uint32 oldMSTime = getMSTime();
        CharacterDatabase.Execute("DELETE FROM _玩家军衔属性 WHERE guid not in (select guid from characters)");
        TC_LOG_INFO("server.loading", ">> 成功清除垃圾数据 _玩家军衔属性 用时 {} 毫秒", GetMSTimeDiffToNow(oldMSTime));
    }
    {
        TC_LOG_INFO("server.loading", "正在清除垃圾数据 _玩家角色数据...");
        uint32 oldMSTime = getMSTime();
        CharacterDatabase.Execute("DELETE FROM _玩家角色数据 WHERE guid not in (select guid from characters)");
        TC_LOG_INFO("server.loading", ">> 成功清除垃圾数据 _玩家角色数据 用时 {} 毫秒", GetMSTimeDiffToNow(oldMSTime));
    }
}
/*DB*/
void AACenter::LoadAAData_Jindu()
{
    {
        TC_LOG_INFO("server.loading", "正在清除垃圾数据 玩家进度数据...");
        uint32 oldMSTime = getMSTime();
        std::map<ObjectGuid::LowType, std::vector<uint32>> instances; instances.clear();
        QueryResult result = CharacterDatabase.Query("SELECT guid, instance FROM character_instance");
        if (result)
        {
            do
            {
                Field* fields = result->Fetch();
                if (fields) {
                    ObjectGuid::LowType guidlow = fields[0].GetUInt32();
                    uint32 instanceId = fields[1].GetUInt32();
                    instances[guidlow].push_back(instanceId);
                }
            } while (result->NextRow());
        }

        std::vector<uint32> instanceids; instanceids.clear();
        result = CharacterDatabase.Query("SELECT * FROM _数据玩家instance");
        if (result) {
            do {
                Field* fields = result->Fetch();
                ObjectGuid::LowType guidlow = fields[0].GetUInt64();
                int32 instance = fields[1].GetInt32();
                std::vector<uint32> ins = instances[guidlow];
                if (std::find(ins.begin(), ins.end(), instance) != ins.end())
                {
                    instanceids.push_back(instance);
                }
            } while (result->NextRow());
        }

        std::string instancestr = "";
        for (auto instanceid : instanceids) {
            instancestr = std::to_string(instanceid) + ",";
        }
        if (instancestr != "") {
            aaCenter.AA_StringReplaceLast(instancestr, ",", "");
        }
        TC_LOG_INFO("server.loading", ">> 成功清除垃圾数据 玩家进度数据 用时 {} 毫秒", GetMSTimeDiffToNow(oldMSTime));

        std::string sqlstr1 = "";
        std::string sqlstr2 = "";
        if (instancestr != "") {
            sqlstr1 = "DELETE FROM _数据地图instance WHERE instance NOT IN (" + instancestr + ")";
            sqlstr2 = "DELETE FROM _数据玩家instance WHERE instance NOT IN (" + instancestr + ")";
            CharacterDatabase.Execute(sqlstr1.c_str());
            CharacterDatabase.Execute(sqlstr2.c_str());
        }
        else {
            sqlstr1 = "DELETE FROM _数据地图instance WHERE instance != -1";
            sqlstr2 = "DELETE FROM _数据玩家instance WHERE instance != -1";
            CharacterDatabase.Execute(sqlstr1.c_str());
            CharacterDatabase.Execute(sqlstr2.c_str());
        }
    }

    {
        TC_LOG_INFO("server.loading", "正在加载 _数据地图area...");
        uint32 oldMSTime = getMSTime();
        aa_map_area_values.clear();
        aa_mareabools.clear();
        aa_mareavalues.clear();
        QueryResult result = CharacterDatabase.Query("SELECT * FROM _数据地图area");
        if (result) {
            do {
                Field* fields = result->Fetch();
                AA_Map_Area_Value conf;
                conf.mapid = fields[0].GetInt32();
                conf.valueb = fields[1].GetString();
                conf.valuev = fields[2].GetString();
                conf.update_time = fields[3].GetUInt32();
                aa_map_area_values[conf.mapid] = conf;
                {
                    std::map<int32, int32> m; m.clear();
                    aaCenter.AA_StringToMap(conf.valueb, m);
                    for (auto iter : m) {
                        aaCenter.aa_mareabools[conf.mapid][iter.first] = m[iter.first];
                    }
                }
                {
                    std::map<int32, int32> m; m.clear();
                    aaCenter.AA_StringToMap(conf.valuev, m);
                    for (auto iter : m) {
                        aaCenter.aa_mareavalues[conf.mapid][iter.first] = m[iter.first];
                    }
                }
            } while (result->NextRow());
            TC_LOG_INFO("server.loading", ">> 成功加载 {}条 _数据地图area 用时 {} 毫秒", (unsigned long)aa_map_area_values.size(), GetMSTimeDiffToNow(oldMSTime));
        }
    }
    {
        TC_LOG_INFO("server.loading", "正在加载 _数据地图zone...");
        uint32 oldMSTime = getMSTime();
        aa_map_zone_values.clear();
        aa_mzonebools.clear();
        aa_mzonevalues.clear();
        QueryResult result = CharacterDatabase.Query("SELECT * FROM _数据地图zone");
        if (result) {
            do {
                Field* fields = result->Fetch();
                AA_Map_Zone_Value conf;
                conf.mapid = fields[0].GetInt32();
                conf.valueb = fields[1].GetString();
                conf.valuev = fields[2].GetString();
                conf.update_time = fields[3].GetUInt32();
                aa_map_zone_values[conf.mapid] = conf;
                {
                    std::map<int32, int32> m; m.clear();
                    aaCenter.AA_StringToMap(conf.valueb, m);
                    for (auto iter : m) {
                        aaCenter.aa_mzonebools[conf.mapid][iter.first] = m[iter.first];
                    }
                }
                {
                    std::map<int32, int32> m; m.clear();
                    aaCenter.AA_StringToMap(conf.valuev, m);
                    for (auto iter : m) {
                        aaCenter.aa_mzonevalues[conf.mapid][iter.first] = m[iter.first];
                    }
                }
            } while (result->NextRow());
            TC_LOG_INFO("server.loading", ">> 成功加载 {}条 _数据地图zone 用时 {} 毫秒", (unsigned long)aa_map_zone_values.size(), GetMSTimeDiffToNow(oldMSTime));
        }
    }
    {
        TC_LOG_INFO("server.loading", "正在加载 _数据地图map...");
        uint32 oldMSTime = getMSTime();
        aa_map_map_values.clear();
        aa_mmapbools.clear();
        aa_mmapvalues.clear();
        QueryResult result = CharacterDatabase.Query("SELECT * FROM _数据地图map");
        if (result) {
            do {
                Field* fields = result->Fetch();
                AA_Map_Map_Value conf;
                conf.mapid = fields[0].GetInt32();
                conf.valueb = fields[1].GetString();
                conf.valuev = fields[2].GetString();
                conf.update_time = fields[3].GetUInt32();
                aa_map_map_values[conf.mapid] = conf;
                {
                    std::map<int32, int32> m; m.clear();
                    aaCenter.AA_StringToMap(conf.valueb, m);
                    for (auto iter : m) {
                        aaCenter.aa_mmapbools[conf.mapid][iter.first] = m[iter.first];
                    }
                }
                {
                    std::map<int32, int32> m; m.clear();
                    aaCenter.AA_StringToMap(conf.valuev, m);
                    for (auto iter : m) {
                        aaCenter.aa_mmapvalues[conf.mapid][iter.first] = m[iter.first];
                    }
                }
            } while (result->NextRow());
            TC_LOG_INFO("server.loading", ">> 成功加载 {}条 _数据地图map 用时 {} 毫秒", (unsigned long)aa_map_map_values.size(), GetMSTimeDiffToNow(oldMSTime));
        }
    }
    {
        TC_LOG_INFO("server.loading", "正在加载 _数据地图instance...");
        uint32 oldMSTime = getMSTime();
        aa_map_instance_values.clear();
        aa_minstancebools.clear();
        aa_minstancevalues.clear();
        QueryResult result = CharacterDatabase.Query("SELECT * FROM _数据地图instance");
        if (result) {
            do {
                Field* fields = result->Fetch();
                AA_Map_Instance_Value conf;
                conf.mapid = fields[0].GetInt32();
                conf.valueb = fields[1].GetString();
                conf.valuev = fields[2].GetString();
                conf.update_time = fields[3].GetUInt32();
                aa_map_instance_values[conf.mapid] = conf;
                {
                    std::map<int32, int32> m; m.clear();
                    aaCenter.AA_StringToMap(conf.valueb, m);
                    for (auto iter : m) {
                        aaCenter.aa_minstancebools[conf.mapid][iter.first] = m[iter.first];
                    }
                }
                {
                    std::map<int32, int32> m; m.clear();
                    aaCenter.AA_StringToMap(conf.valuev, m);
                    for (auto iter : m) {
                        aaCenter.aa_minstancevalues[conf.mapid][iter.first] = m[iter.first];
                    }
                }
            } while (result->NextRow());
            TC_LOG_INFO("server.loading", ">> 成功加载 {}条 _数据地图instance 用时 {} 毫秒", (unsigned long)aa_map_instance_values.size(), GetMSTimeDiffToNow(oldMSTime));
        }
    }
    {
        TC_LOG_INFO("server.loading", "正在加载 _数据玩家area...");
        uint32 oldMSTime = getMSTime();
        aa_player_area_values.clear();
        aa_pareabools.clear();
        aa_pareavalues.clear();
        QueryResult result = CharacterDatabase.Query("SELECT * FROM _数据玩家area");
        if (result) {
            do {
                Field* fields = result->Fetch();
                AA_Player_Area_Value conf;
                conf.guidlow = fields[0].GetUInt64();
                conf.mapid = fields[1].GetInt32();
                conf.valueb = fields[2].GetString();
                conf.valuev = fields[3].GetString();
                conf.update_time = fields[4].GetUInt32();
                aa_player_area_values[conf.mapid][conf.guidlow] = conf;
                {
                    std::map<int32, int32> m; m.clear();
                    aaCenter.AA_StringToMap(conf.valueb, m);
                    for (auto iter : m) {
                        aaCenter.aa_pareabools[conf.mapid][conf.guidlow][iter.first] = m[iter.first];
                    }
                }
                {
                    std::map<int32, int32> m; m.clear();
                    aaCenter.AA_StringToMap(conf.valuev, m);
                    for (auto iter : m) {
                        aaCenter.aa_pareavalues[conf.mapid][conf.guidlow][iter.first] = m[iter.first];
                    }
                }
            } while (result->NextRow());
            TC_LOG_INFO("server.loading", ">> 成功加载 {}条 _数据玩家area 用时 {} 毫秒", (unsigned long)aa_player_area_values.size(), GetMSTimeDiffToNow(oldMSTime));
        }
    }
    {
        TC_LOG_INFO("server.loading", "正在加载 _数据玩家zone...");
        uint32 oldMSTime = getMSTime();
        aa_player_zone_values.clear();
        aa_pzonebools.clear();
        aa_pzonevalues.clear();
        QueryResult result = CharacterDatabase.Query("SELECT * FROM _数据玩家zone");
        if (result) {
            do {
                Field* fields = result->Fetch();
                AA_Player_Zone_Value conf;
                conf.guidlow = fields[0].GetUInt64();
                conf.mapid = fields[1].GetInt32();
                conf.valueb = fields[2].GetString();
                conf.valuev = fields[3].GetString();
                conf.update_time = fields[4].GetUInt32();
                aa_player_zone_values[conf.mapid][conf.guidlow] = conf;
                {
                    std::map<int32, int32> m; m.clear();
                    aaCenter.AA_StringToMap(conf.valueb, m);
                    for (auto iter : m) {
                        aaCenter.aa_pzonebools[conf.mapid][conf.guidlow][iter.first] = m[iter.first];
                    }
                }
                {
                    std::map<int32, int32> m; m.clear();
                    aaCenter.AA_StringToMap(conf.valuev, m);
                    for (auto iter : m) {
                        aaCenter.aa_pzonevalues[conf.mapid][conf.guidlow][iter.first] = m[iter.first];
                    }
                }
            } while (result->NextRow());
            TC_LOG_INFO("server.loading", ">> 成功加载 {}条 _数据玩家zone 用时 {} 毫秒", (unsigned long)aa_player_zone_values.size(), GetMSTimeDiffToNow(oldMSTime));
        }
    }
    {
        TC_LOG_INFO("server.loading", "正在加载 _数据玩家map...");
        uint32 oldMSTime = getMSTime();
        aa_player_map_values.clear();
        aa_pmapbools.clear();
        aa_pmapvalues.clear();
        QueryResult result = CharacterDatabase.Query("SELECT * FROM _数据玩家map");
        if (result) {
            do {
                Field* fields = result->Fetch();
                AA_Player_Map_Value conf;
                conf.guidlow = fields[0].GetUInt64();
                conf.mapid = fields[1].GetInt32();
                conf.valueb = fields[2].GetString();
                conf.valuev = fields[3].GetString();
                conf.update_time = fields[4].GetUInt32();
                aa_player_map_values[conf.mapid][conf.guidlow] = conf;
                {
                    std::map<int32, int32> m; m.clear();
                    aaCenter.AA_StringToMap(conf.valueb, m);
                    for (auto iter : m) {
                        aaCenter.aa_pmapbools[conf.mapid][conf.guidlow][iter.first] = m[iter.first];
                    }
                }
                {
                    std::map<int32, int32> m; m.clear();
                    aaCenter.AA_StringToMap(conf.valuev, m);
                    for (auto iter : m) {
                        aaCenter.aa_pmapvalues[conf.mapid][conf.guidlow][iter.first] = m[iter.first];
                    }
                }
            } while (result->NextRow());
            TC_LOG_INFO("server.loading", ">> 成功加载 {}条 _数据玩家map 用时 {} 毫秒", (unsigned long)aa_player_map_values.size(), GetMSTimeDiffToNow(oldMSTime));
        }
    }
    {
        TC_LOG_INFO("server.loading", "正在加载 _数据玩家instance...");
        uint32 oldMSTime = getMSTime();
        aa_player_instance_values.clear();
        aa_pinstancebools.clear();
        aa_pinstancevalues.clear();
        QueryResult result = CharacterDatabase.Query("SELECT * FROM _数据玩家instance");
        if (result) {
            do {
                Field* fields = result->Fetch();
                AA_Player_Instance_Value conf;
                conf.guidlow = fields[0].GetUInt64();
                conf.mapid = fields[1].GetInt32();
                conf.valueb = fields[2].GetString();
                conf.valuev = fields[3].GetString();
                conf.update_time = fields[4].GetUInt32();
                aa_player_instance_values[conf.mapid][conf.guidlow] = conf;
                {
                    std::map<int32, int32> m; m.clear();
                    aaCenter.AA_StringToMap(conf.valueb, m);
                    for (auto iter : m) {
                        aaCenter.aa_pinstancebools[conf.mapid][conf.guidlow][iter.first] = m[iter.first];
                    }
                }
                {
                    std::map<int32, int32> m; m.clear();
                    aaCenter.AA_StringToMap(conf.valuev, m);
                    for (auto iter : m) {
                        aaCenter.aa_pinstancevalues[conf.mapid][conf.guidlow][iter.first] = m[iter.first];
                    }
                }
            } while (result->NextRow());
            TC_LOG_INFO("server.loading", ">> 成功加载 {}条 _数据玩家instance 用时 {} 毫秒", (unsigned long)aa_player_instance_values.size(), GetMSTimeDiffToNow(oldMSTime));
        }
    }
}

void AACenter::LoadAAData_Characters()
{
    {
        aa_realmlists.clear();
        QueryResult result = LoginDatabase.Query("SELECT id,name,address,port FROM realmlist");
        if (result) {
            do {
                Field* fields = result->Fetch();
                AA_Realmlist conf;
                conf.id = fields[0].GetUInt32();
                conf.name = fields[1].GetString();
                conf.address = fields[2].GetString();
                conf.port = fields[3].GetUInt32();
                aa_realmlists[conf.id] = conf;
            } while (result->NextRow());
        }
    }
    {
        aa_accounts.clear();
        QueryResult result = LoginDatabase.Query("SELECT * FROM _aa_account ORDER BY id");
        if (result) {
            do {
                Field* fields = result->Fetch();
                AA_Account conf;
                conf.id = fields[0].GetUInt32();
                conf.vip = fields[1].GetUInt32();
                conf.jifen = fields[2].GetUInt32();
                conf.jifen_cz = fields[3].GetUInt32();
                conf.jifen_all = fields[4].GetUInt32();
                conf.paodian = fields[5].GetUInt32();
                conf.mobi = fields[6].GetUInt32();
                conf.battlecore = fields[7].GetUInt32();
                conf.jifen_day = fields[8].GetUInt32();
                conf.shouchong_day = fields[9].GetUInt32();
                conf.shouchong = fields[10].GetUInt32();
                conf.leichong = fields[11].GetString();
                conf.denglu_day = fields[12].GetUInt32();
                conf.denglu = fields[13].GetString();
                conf.denglu_qiandao = fields[14].GetUInt32();
                conf.licai_day = fields[15].GetUInt32();
                conf.licai = fields[16].GetUInt32();
                conf.buy_time = fields[17].GetString();
                conf.buy_time_yj = fields[18].GetString();
                conf.diy_account = fields[19].GetString();
                conf.update_time = fields[20].GetUInt32();
                aa_accounts[conf.id] = conf;
            } while (result->NextRow());
        }
    }

    {
        TC_LOG_INFO("server.loading", "正在加载 _系统数据...");
        uint32 oldMSTime = getMSTime();
        AA_System conf;
        aaCenter.aa_system_conf = conf;
        QueryResult result = CharacterDatabase.Query("SELECT * FROM _系统数据");
        if (result) {
            Field* fields = result->Fetch();
            aaCenter.aa_system_conf.diy_system = fields[1].GetString();
            aaCenter.aa_system_conf.update_time = fields[2].GetUInt32();
        }
        TC_LOG_INFO("server.loading", ">> 成功加载 _系统数据 用时 {} 毫秒", GetMSTimeDiffToNow(oldMSTime));
    }
    {
        //        _玩家排行数据x
        TC_LOG_INFO("server.loading", "正在加载 _玩家排行数据x...");
        uint32 oldMSTime = getMSTime();
        aaCenter.aa_jishas.clear();
        aaCenter.aa_renwus.clear();
        QueryResult result = CharacterDatabase.Query("SELECT * FROM _玩家排行数据x");
        if (result) {
            do {
                Field* fields = result->Fetch();
                aaCenter.aa_jishas[fields[0].GetUInt32()] = fields[1].GetUInt32();
                aaCenter.aa_renwus[fields[0].GetUInt32()] = fields[2].GetUInt32();
            } while (result->NextRow());
            TC_LOG_INFO("server.loading", ">> 成功加载 {}条 _玩家排行数据x 用时 {} 毫秒", (unsigned long)aaCenter.aa_jishas.size(), GetMSTimeDiffToNow(oldMSTime));
        }
    }
    {
        TC_LOG_INFO("server.loading", "正在加载 _玩家捐献数据...");
        uint32 oldMSTime = getMSTime();
        aa_character_juanxians.clear();
        QueryResult result = CharacterDatabase.Query("SELECT * FROM _玩家捐献数据 ORDER BY 捐献数量");
        if (result) {
            do {
                Field* fields = result->Fetch();
                AA_Character_Juanxian conf;
                conf.guid = fields[0].GetUInt64();
                conf.name = fields[1].GetString();
                conf.juanxian = fields[2].GetUInt32();
                conf.update_time = fields[3].GetUInt32();
                aa_character_juanxians[conf.guid] = conf;
            } while (result->NextRow());
            TC_LOG_INFO("server.loading", ">> 成功加载 {}条 _玩家捐献数据 用时 {} 毫秒", (unsigned long)aa_character_juanxians.size(), GetMSTimeDiffToNow(oldMSTime));
        }
    }
    {
        TC_LOG_INFO("server.loading", "正在加载 _玩家角色数据...");
        uint32 oldMSTime = getMSTime();
        aa_characterss.clear();
        QueryResult result = CharacterDatabase.Query("SELECT * FROM _玩家角色数据 ORDER BY guid");
        if (result) {
            do {
                Field* fields = result->Fetch();
                AA_Characters conf;
                int i = 0;
                conf.guid = fields[i++].GetUInt64();
                conf.playtime = fields[i++].GetUInt32();
                conf.shengji = fields[i++].GetString();
                conf.tianfu = fields[i++].GetUInt32();
                conf.choujiang = fields[i++].GetUInt32();
                conf.choujianglq = fields[i++].GetUInt32();
                conf.buy_time = fields[i++].GetString();
                conf.buy_time_yj = fields[i++].GetString();
                conf.zhaomu = fields[i++].GetString();
                conf.diy_guid = fields[i++].GetString();
                conf.name_pre = fields[i++].GetString();
                conf.name_suf = fields[i++].GetString();
                conf.duel_diy = fields[i++].GetUInt32();
                conf.update_time = fields[i++].GetUInt32();
                aa_characterss[conf.guid] = conf;
            } while (result->NextRow());
            TC_LOG_INFO("server.loading", ">> 成功加载 {}条 _玩家角色数据 用时 {} 毫秒", (unsigned long)aa_characterss.size(), GetMSTimeDiffToNow(oldMSTime));
        }
    }
    {
        TC_LOG_INFO("server.loading", "正在加载 _玩家巅峰属性...");
        uint32 oldMSTime = getMSTime();
        aa_characters_dianfengs.clear();
        QueryResult result = CharacterDatabase.Query("SELECT * FROM _玩家巅峰属性 ORDER BY guid");
        if (result) {
            do {
                Field* fields = result->Fetch();
                AA_Characters_Dianfeng conf;
                conf.guid = fields[0].GetUInt64();
                conf.level = fields[1].GetUInt32();
                conf.exp = fields[2].GetUInt32();
                conf.dianshu_all = fields[3].GetUInt32();
                conf.dianshu = fields[4].GetInt32();
                conf.tianfu = fields[5].GetUInt32();
                conf.value = fields[6].GetString();
                conf.update_time = fields[7].GetUInt32();
                aa_characters_dianfengs[conf.guid] = conf;
            } while (result->NextRow());
            TC_LOG_INFO("server.loading", ">> 成功加载 {}条 _玩家巅峰属性 用时 {} 毫秒", (unsigned long)aa_characters_dianfengs.size(), GetMSTimeDiffToNow(oldMSTime));
        }
    }
    {
        TC_LOG_INFO("server.loading", "正在加载 _玩家斗气属性...");
        uint32 oldMSTime = getMSTime();
        aa_characters_douqis.clear();
        QueryResult result = CharacterDatabase.Query("SELECT * FROM _玩家斗气属性 ORDER BY guid");
        if (result) {
            do {
                Field* fields = result->Fetch();
                AA_Characters_Douqi conf;
                conf.guid = fields[0].GetUInt64();
                conf.level = fields[1].GetUInt32();
                conf.exp = fields[2].GetUInt32();
                conf.dianshu_all = fields[3].GetUInt32();
                conf.dianshu = fields[4].GetInt32();
                conf.tianfu = fields[5].GetUInt32();
                conf.value = fields[6].GetString();
                conf.update_time = fields[7].GetUInt32();
                aa_characters_douqis[conf.guid] = conf;
            } while (result->NextRow());
            TC_LOG_INFO("server.loading", ">> 成功加载 {}条 _玩家斗气属性 用时 {} 毫秒", (unsigned long)aa_characters_douqis.size(), GetMSTimeDiffToNow(oldMSTime));
        }
    }
    {
        TC_LOG_INFO("server.loading", "正在加载 _玩家军衔属性...");
        uint32 oldMSTime = getMSTime();
        aa_characters_junxians.clear();
        QueryResult result = CharacterDatabase.Query("SELECT * FROM _玩家军衔属性 ORDER BY guid");
        if (result) {
            do {
                Field* fields = result->Fetch();
                AA_Characters_Junxian conf;
                conf.guid = fields[0].GetUInt64();
                conf.level = fields[1].GetUInt32();
                conf.exp = fields[2].GetUInt32();
                conf.dianshu_all = fields[3].GetUInt32();
                conf.dianshu = fields[4].GetInt32();
                conf.tianfu = fields[5].GetUInt32();
                conf.value = fields[6].GetString();
                conf.update_time = fields[7].GetUInt32();
                aa_characters_junxians[conf.guid] = conf;
            } while (result->NextRow());
            TC_LOG_INFO("server.loading", ">> 成功加载 {}条 _玩家军衔属性 用时 {} 毫秒", (unsigned long)aa_characters_junxians.size(), GetMSTimeDiffToNow(oldMSTime));
        }
    }
    {
        TC_LOG_INFO("server.loading", "正在加载 _玩家装备数据...");
        uint32 oldMSTime = getMSTime();
        aa_character_instances.clear();
        aa_character_instance_ids.clear();
        aa_character_instance_owner.clear();
        QueryResult result = CharacterDatabase.Query("SELECT * FROM _玩家装备数据");
        if (result) {
            do {
                Field* fields = result->Fetch();
                AA_Character_Instance conf;
                conf.guid = fields[0].GetUInt64();
                conf.itemEntry = fields[1].GetUInt32();
                conf.owner_guid = fields[2].GetUInt64();
                conf.name = fields[3].GetString();
                conf.fugai_zu = fields[4].GetUInt32();
                conf.fugai = fields[5].GetString();
                conf.jd_zu = fields[6].GetUInt32();
                conf.jd_id = fields[7].GetUInt32();
                conf.jd_level = fields[8].GetUInt32();
                conf.jd_values = fields[9].GetString();
                conf.qh_zu = fields[10].GetUInt32();
                conf.qh_id = fields[11].GetUInt32();
                conf.qh_level = fields[12].GetUInt32();
                conf.qh_values = fields[13].GetString();
                conf.qh_reward_value = fields[14].GetUInt32();
                conf.qh_reward_point = fields[15].GetUInt32();
                conf.qh_reward_spell = fields[16].GetString();
                conf.cz_zu = fields[17].GetUInt32();
                conf.cz_id = fields[18].GetUInt32();
                conf.cz_level = fields[19].GetUInt32();
                conf.cz_exp = fields[20].GetUInt32();
                conf.cz_values = fields[21].GetString();
                conf.cz_reward_value = fields[22].GetUInt32();
                conf.cz_reward_point = fields[23].GetUInt32();
                conf.cz_reward_spell = fields[24].GetString();
                conf.fm_spell_count = fields[25].GetUInt32();
                conf.fm_spells = fields[26].GetString();
                conf.fm_value_count = fields[27].GetUInt32();
                conf.fm_values = fields[28].GetString();
                conf.chongzhu_count = fields[29].GetUInt32();
                conf.chongzhu_value = fields[30].GetUInt32();
                conf.chongzhu_spell = fields[31].GetUInt32();
                conf.fw_count = fields[32].GetUInt32();
                conf.fw_values = fields[33].GetString();
                conf.fwzh_values = fields[34].GetString();
                conf.cuiqu_pos = fields[35].GetInt32();
                conf.baoshi_entry = fields[36].GetInt32();
                conf.item_set = fields[37].GetInt32();
                conf.update_time = fields[38].GetUInt32();
                aa_character_instances[conf.guid] = conf;
                aa_character_instance_owner[conf.owner_guid].push_back(conf.guid);
            } while (result->NextRow());
            TC_LOG_INFO("server.loading", ">> 成功加载 {}条 _玩家装备数据 用时 {} 毫秒", (unsigned long)aa_character_instances.size(), GetMSTimeDiffToNow(oldMSTime));
        }
    }
    {
        TC_LOG_INFO("server.loading", "正在加载 _玩家双甲数据x...");
        uint32 oldMSTime = getMSTime();
        aa_item_instances.clear();
        aa_item_instance_owner.clear();
        QueryResult result = CharacterDatabase.Query("SELECT * FROM _玩家双甲数据x ORDER BY guid");
        if (result) {
            do {
                Field* fields = result->Fetch();
                AA_Item_Instance conf;
                conf.guid = fields[0].GetUInt64();
                conf.itemEntry = fields[1].GetUInt32();
                conf.owner_guid = fields[2].GetUInt64();
                conf.creatorGuid = fields[3].GetUInt64();
                conf.giftCreatorGuid = fields[4].GetUInt64();
                conf.count = fields[5].GetUInt32();
                conf.duration = fields[6].GetInt32();
                conf.charges = fields[7].GetString();
                conf.flags = fields[8].GetUInt32();
                conf.enchantments = fields[9].GetString();
                conf.randomPropertyId = fields[10].GetInt16();
                conf.durability = fields[11].GetUInt16();
                conf.playedTime = fields[12].GetUInt32();
                conf.text = fields[13].GetString();
                conf.weizhi = fields[14].GetString();
                conf.update_time = fields[15].GetUInt32();
                aa_item_instances[conf.guid] = conf;
                aa_item_instance_owner[conf.owner_guid].push_back(conf.guid);
            } while (result->NextRow());
            TC_LOG_INFO("server.loading", ">> 成功加载 {}条 _玩家双甲数据x 用时 {} 毫秒", (unsigned long)aa_item_instances.size(), GetMSTimeDiffToNow(oldMSTime));
        }
    }
}

void AACenter::LoadAAData_World()
{

    {
        TC_LOG_INFO("server.loading", "正在加载 _模板_光环...");
        uint32 oldMSTime = getMSTime();
        aa_auraid_confs.clear();
        aa_auraid_conf_zus.clear();
        QueryResult result = WorldDatabase.Query("SELECT * FROM _模板_光环 ORDER BY id");
        if (result) {
            do {
                Field* fields = result->Fetch();
                AA_AuraId_Conf conf;
                conf.id = fields[1].GetUInt32();
                conf.zu = fields[2].GetUInt32();
                conf.chance = fields[3].GetFloat();
                conf.auraid = fields[4].GetUInt32();
                aa_auraid_confs[conf.id] = conf;
                aa_auraid_conf_zus[conf.zu].push_back(conf.id);
            } while (result->NextRow());
            TC_LOG_INFO("server.loading", ">> 成功加载 {}条 _模板_光环 用时 {} 毫秒", (unsigned long)aa_auraid_confs.size(), GetMSTimeDiffToNow(oldMSTime));
        }
    }
    {
        TC_LOG_INFO("server.loading", "正在加载 _模板_技能...");
        uint32 oldMSTime = getMSTime();
        aa_spellid_confs.clear();
        aa_spellid_conf_zus.clear();
        QueryResult result = WorldDatabase.Query("SELECT * FROM _模板_技能 ORDER BY id");
        if (result) {
            do {
                Field* fields = result->Fetch();
                AA_SpellId_Conf conf;
                conf.id = fields[1].GetUInt32();
                conf.zu = fields[2].GetUInt32();
                conf.chance = fields[3].GetFloat();
                conf.spellid = fields[4].GetUInt32();
                aa_spellid_confs[conf.id] = conf;
                aa_spellid_conf_zus[conf.zu].push_back(conf.id);
            } while (result->NextRow());
            TC_LOG_INFO("server.loading", ">> 成功加载 {}条 _模板_技能 用时 {} 毫秒", (unsigned long)aa_spellid_confs.size(), GetMSTimeDiffToNow(oldMSTime));
        }
    }
    {
        TC_LOG_INFO("server.loading", "正在加载 _活动_比武大会...");
        uint32 oldMSTime = getMSTime();
        aa_biwu_confs.clear();
        QueryResult result = WorldDatabase.Query("SELECT * FROM _活动_比武大会");
        if (result) {
            do {
                Field* fields = result->Fetch();
                AA_Biwu_Conf conf;
                int i = 1;
                conf.event_id = fields[i++].GetUInt32();//活动进场事件
                conf.area = fields[i++].GetUInt32();//区域id
                conf.guid = fields[i++].GetUInt64();//比武大会GOB的GUID
                conf.player_min = fields[i++].GetUInt32();//最少人数
                conf.alert_id = fields[i++].GetUInt32();//_弹窗_id
                conf.wait_time = fields[i++].GetUInt32();//单位秒，到达等待时间后开始战斗
                conf.juedou_time = fields[i++].GetUInt32();//每场决斗限制时间
                conf.gm_win = fields[i++].GetString();//决斗胜利调用GM命令
                conf.gm_lose = fields[i++].GetString();//决斗失败调用GM命令
                conf.gm_1 = fields[i++].GetString();//第一名调用GM命令
                aa_biwu_confs[conf.event_id] = conf;
            } while (result->NextRow());
            TC_LOG_INFO("server.loading", ">> 成功加载 {}条 _活动_比武大会 用时 {} 毫秒", (unsigned long)aa_biwu_confs.size(), GetMSTimeDiffToNow(oldMSTime));
        }
    }
    {
        TC_LOG_INFO("server.loading", "正在加载 _自定义_阵营...");
        uint32 oldMSTime = getMSTime();
        aa_diy_duels.clear();
        QueryResult result = WorldDatabase.Query("SELECT * FROM _自定义_阵营");
        if (result) {
            do {
                Field* fields = result->Fetch();
                AA_Diy_Duel conf;
                int i = 1;
                conf.id = fields[i++].GetUInt32();
                conf.name = fields[i++].GetString();
                conf.namepre = fields[i++].GetString();
                conf.namesuf = fields[i++].GetString();
                conf.need_add = fields[i++].GetUInt32();
                conf.gm_add = fields[i++].GetString();
                conf.need_exit = fields[i++].GetUInt32();
                conf.gm_exit = fields[i++].GetString();
                aa_diy_duels[conf.id] = conf;
            } while (result->NextRow());
            TC_LOG_INFO("server.loading", ">> 成功加载 {}条 _自定义_阵营 用时 {} 毫秒", (unsigned long)aa_diy_duels.size(), GetMSTimeDiffToNow(oldMSTime));
        }
    }
    {
        TC_LOG_INFO("server.loading", "正在加载 __系统_自动组队...");
        uint32 oldMSTime = getMSTime();
        aa_item_set_confs.clear();
        QueryResult result = WorldDatabase.Query("SELECT * FROM __系统_自动组队 ORDER BY id");
        if (result) {
            do {
                Field* fields = result->Fetch();
                AA_Xitong_Group conf;
                conf.id = fields[1].GetUInt32();
                conf.game_event = fields[2].GetUInt32();
                conf.count = fields[3].GetUInt32();
                conf.zoneid = fields[4].GetInt32(); 
                conf.iszhenying = fields[5].GetUInt32();
                conf.isgonghui = fields[5].GetUInt32();
                aa_xitong_groups[conf.id] = conf;
            } while (result->NextRow());
            TC_LOG_INFO("server.loading", ">> 成功加载 {}条 __系统_自动组队 用时 {} 毫秒", (unsigned long)aa_xitong_groups.size(), GetMSTimeDiffToNow(oldMSTime));
        }
    }
    {
        TC_LOG_INFO("server.loading", "正在加载 _模板_随机套装_配置...");
        uint32 oldMSTime = getMSTime();
        aa_item_set_confs.clear();
        QueryResult result = WorldDatabase.Query("SELECT * FROM _模板_随机套装_配置 ORDER BY 组");
        if (result) {
            do {
                Field* fields = result->Fetch();
                AA_Item_Set_Conf conf;
                conf.zu = fields[2].GetUInt32();
                conf.text = fields[1].GetString();
                aa_item_set_confs[conf.zu] = conf;
            } while (result->NextRow());
            TC_LOG_INFO("server.loading", ">> 成功加载 {}条 _模板_随机套装_配置 用时 {} 毫秒", (unsigned long)aa_item_set_confs.size(), GetMSTimeDiffToNow(oldMSTime));
        }
    }
    {
        TC_LOG_INFO("server.loading", "正在加载 _模板_随机套装...");
        uint32 oldMSTime = getMSTime();
        aa_item_sets.clear();
        aa_item_set_zus.clear();
        QueryResult result = WorldDatabase.Query("SELECT * FROM _模板_随机套装 ORDER BY id");
        if (result) {
            do {
                Field* fields = result->Fetch();
                AA_Item_Set conf;
                conf.id = fields[2].GetUInt32();
                conf.zu = fields[3].GetUInt32();
                conf.count = fields[4].GetUInt32();
                conf.spells = fields[5].GetString();
                conf.text = fields[1].GetString();
                conf.update_time = fields[6].GetUInt32();
                aa_item_sets[conf.id] = conf;
                aa_item_set_zus[conf.zu].push_back(conf.id);
            } while (result->NextRow());
            TC_LOG_INFO("server.loading", ">> 成功加载 {}条 _模板_随机套装 用时 {} 毫秒", (unsigned long)aa_item_sets.size(), GetMSTimeDiffToNow(oldMSTime));
        }
    }
    {
        TC_LOG_INFO("server.loading", "正在加载 _自定义ui_捐献_排名奖励x...");
        uint32 oldMSTime = getMSTime();
        aa_ui_juanxian_paimings.clear();
        QueryResult result = WorldDatabase.Query("SELECT * FROM _自定义ui_捐献_排名奖励x ORDER BY id");
        if (result) {
            do {
                Field* fields = result->Fetch();
                AA_UI_Juanxian_Paiming conf;
                conf.id = fields[1].GetUInt32();
                conf.guanghuans = fields[2].GetString();
                conf.guanghuan_item = fields[3].GetUInt32();
                aa_ui_juanxian_paimings[conf.id] = conf;
            } while (result->NextRow());
            TC_LOG_INFO("server.loading", ">> 成功加载 {}条 _自定义ui_捐献_排名奖励x 用时 {} 毫秒", (unsigned long)aa_ui_juanxian_paimings.size(), GetMSTimeDiffToNow(oldMSTime));
        }
    }
    {
        TC_LOG_INFO("server.loading", "正在加载 _自定义ui_捐献_数量奖励x...");
        uint32 oldMSTime = getMSTime();
        aa_ui_juanxian_shuliangs.clear();
        QueryResult result = WorldDatabase.Query("SELECT * FROM _自定义ui_捐献_数量奖励x ORDER BY id");
        if (result) {
            do {
                Field* fields = result->Fetch();
                AA_UI_Juanxian_Shuliang conf;
                conf.id = fields[1].GetUInt32();
                conf.guanghuans = fields[2].GetString();
                conf.guanghuan_details = fields[3].GetString();
                aa_ui_juanxian_shuliangs[conf.id] = conf;
            } while (result->NextRow());
            TC_LOG_INFO("server.loading", ">> 成功加载 {}条 _自定义ui_捐献_数量奖励x 用时 {} 毫秒", (unsigned long)aa_ui_juanxian_shuliangs.size(), GetMSTimeDiffToNow(oldMSTime));
        }
    }
    {
        TC_LOG_INFO("server.loading", "正在加载 _自定义ui_集结号x...");
        uint32 oldMSTime = getMSTime();
        aa_ui_jijies.clear();
        QueryResult result = WorldDatabase.Query("SELECT * FROM _自定义ui_集结号x ORDER BY id");
        if (result) {
            do {
                Field* fields = result->Fetch();
                AA_UI_Jijie conf;
                conf.id = fields[1].GetUInt32();
                conf.name = fields[2].GetString();
                conf.title = fields[3].GetString();
                conf.icon = fields[4].GetString();
                conf.count_min = fields[5].GetUInt32();
                conf.count_max = fields[6].GetUInt32();
                conf.time = fields[7].GetUInt32();
                conf.need = fields[8].GetUInt32();
                conf.gm = fields[9].GetString();
                aa_ui_jijies[conf.id] = conf;
            } while (result->NextRow());
            TC_LOG_INFO("server.loading", ">> 成功加载 {}条 _自定义ui_集结号x 用时 {} 毫秒", (unsigned long)aa_ui_jijies.size(), GetMSTimeDiffToNow(oldMSTime));
        }
    }
    {
        TC_LOG_INFO("server.loading", "正在加载 _自定义ui_神器x...");
        uint32 oldMSTime = getMSTime();
        aa_ui_shenqis.clear();
        aa_ui_shenqi_entrys.clear();
        QueryResult result = WorldDatabase.Query("SELECT * FROM _自定义ui_神器x ORDER BY id");
        if (result) {
            do {
                Field* fields = result->Fetch();
                AA_UI_Shenqi conf;
                conf.id = fields[1].GetUInt32();
                conf.lan = fields[2].GetUInt32();
                conf.level = fields[3].GetUInt32();
                conf.item = fields[4].GetUInt32();
                conf.image = fields[5].GetString();
                conf.count = fields[6].GetUInt32();
                conf.x = fields[7].GetInt32();
                conf.y = fields[8].GetInt32();
                conf.needs = fields[9].GetString();
                conf.need = fields[10].GetUInt32();
                conf.notice = fields[11].GetUInt32();
                aa_ui_shenqis[conf.lan][conf.id][conf.level] = conf;
                aa_ui_shenqi_entrys[conf.item] = conf;
            } while (result->NextRow());
            TC_LOG_INFO("server.loading", ">> 成功加载 {}条 _自定义ui_神器x 用时 {} 毫秒", (unsigned long)aa_ui_shenqis.size(), GetMSTimeDiffToNow(oldMSTime));
        }
    }
    {
        TC_LOG_INFO("server.loading", "正在加载 _自定义ui_时装x...");
        uint32 oldMSTime = getMSTime();
        aa_ui_shizhuangs.clear();
        QueryResult result = WorldDatabase.Query("SELECT * FROM _自定义ui_时装x ORDER BY id");
        if (result) {
            do {
                Field* fields = result->Fetch();
                AA_UI_Shizhuang conf;
                conf.id = fields[1].GetUInt32();
                conf.lan = fields[2].GetUInt32();
                conf.item = fields[3].GetUInt32();
                conf.modelid = fields[4].GetUInt32();
                conf.scale = fields[5].GetFloat();
                conf.needs = fields[6].GetString();
                conf.need = fields[7].GetUInt32();
                conf.notice = fields[8].GetUInt32();
                aa_ui_shizhuangs[conf.lan][conf.id] = conf;
            } while (result->NextRow());
            TC_LOG_INFO("server.loading", ">> 成功加载 {}条 _自定义ui_时装x 用时 {} 毫秒", (unsigned long)aa_ui_shizhuangs.size(), GetMSTimeDiffToNow(oldMSTime));
        }
    }
    {
        TC_LOG_INFO("server.loading", "正在加载 _自定义ui_传送x...");
        uint32 oldMSTime = getMSTime();
        aa_ui_chuansongs.clear();
        QueryResult result = WorldDatabase.Query("SELECT * FROM _自定义ui_传送x ORDER BY id");
        if (result) {
            do {
                Field* fields = result->Fetch();
                AA_UI_Chuansong conf;
                conf.id = fields[1].GetUInt32();
                conf.title = fields[2].GetString();
                conf.detail1 = fields[3].GetString();
                conf.detail2 = fields[4].GetString();
                conf.detail3 = fields[5].GetString();
                conf.detail4 = fields[6].GetString();
                conf.detail5 = fields[7].GetString();
                conf.items = fields[8].GetString();
                conf.gm = fields[9].GetString();
                aa_ui_chuansongs[conf.id] = conf;
            } while (result->NextRow());
            TC_LOG_INFO("server.loading", ">> 成功加载 {}条 _自定义ui_传送x 用时 {} 毫秒", (unsigned long)aa_ui_chuansongs.size(), GetMSTimeDiffToNow(oldMSTime));
        }
    }
    {
        TC_LOG_INFO("server.loading", "正在加载 _自定义ui_收集x...");
        uint32 oldMSTime = getMSTime();
        aa_item_shuangjias.clear();
        QueryResult result = WorldDatabase.Query("SELECT * FROM _自定义ui_收集x ORDER BY id");
        if (result) {
            do {
                Field* fields = result->Fetch();
                AA_Item_Shuangjia conf;
                conf.id = fields[1].GetUInt32();
                conf.items = fields[2].GetString();
                conf.display_items = fields[3].GetString();
                conf.need_xiangqian = fields[4].GetString();
                conf.need_chaixie = fields[5].GetString();
                conf.guanghuans = fields[6].GetString();
                conf.guanghuan_item = fields[7].GetUInt32();
                aa_item_shuangjias[conf.id] = conf;
            } while (result->NextRow());
            TC_LOG_INFO("server.loading", ">> 成功加载 {}条 _自定义ui_收集x 用时 {} 毫秒", (unsigned long)aa_item_shuangjias.size(), GetMSTimeDiffToNow(oldMSTime));
        }
    }
    {
        TC_LOG_INFO("server.loading", "正在加载 _自定义ui_收集_限制x...");
        uint32 oldMSTime = getMSTime();
        aa_item_shuangjia_xianzhis.clear();
        QueryResult result = WorldDatabase.Query("SELECT * FROM _自定义ui_收集_限制x");
        if (result) {
            do {
                Field* fields = result->Fetch();
                AA_Item_Shuangjia_Xianzhi conf;
                conf.zu = fields[1].GetUInt32();
                conf.xiangqian = fields[2].GetUInt32();
                aa_item_shuangjia_xianzhis[conf.zu] = conf;
            } while (result->NextRow());
            TC_LOG_INFO("server.loading", ">> 成功加载 {}条 _自定义ui_收集_限制x 用时 {} 毫秒", (unsigned long)aa_item_shuangjias.size(), GetMSTimeDiffToNow(oldMSTime));
        }
    }
    {
        TC_LOG_INFO("server.loading", "正在加载 _商城x...");
        uint32 oldMSTime = getMSTime();
        aa_shops.clear();
        aa_shop_zus.clear();
        QueryResult result = WorldDatabase.Query("SELECT * FROM _商城x ORDER BY id");
        if (result) {
            do {
                Field* fields = result->Fetch();
                AA_Shop conf;
                conf.id = fields[1].GetUInt32();
                conf.name = fields[2].GetString();
                conf.zu = fields[3].GetUInt32();
                conf.ye = fields[4].GetUInt32();
                conf.entry = fields[5].GetUInt32();
                conf.guidlow = fields[6].GetUInt64();
                conf.need = fields[7].GetUInt32();
                conf.reward = fields[8].GetUInt32();
                conf.tanchuang = fields[9].GetUInt32();
                conf.gm = fields[10].GetString();
                conf.is_zhandou = fields[11].GetUInt32();
                conf.notice = fields[12].GetUInt32();
                aa_shops[conf.id] = conf;
                aa_shop_zus[conf.zu][conf.ye].push_back(conf.id);
            } while (result->NextRow());
            TC_LOG_INFO("server.loading", ">> 成功加载 {}条 _商城x 用时 {} 毫秒", (unsigned long)aa_shops.size(), GetMSTimeDiffToNow(oldMSTime));
        }
    }
    {
        TC_LOG_INFO("server.loading", "正在加载 _属性调整_光环...");
        uint32 oldMSTime = getMSTime();
        aa_aura_confs.clear();
        aa_aura_conf_zus.clear();
        aa_aura_conf_spell_pvps.clear();
        aa_aura_conf_spell_pves.clear();
        aa_aura_conf_heal_pvps.clear();
        aa_aura_conf_heal_pves.clear();
        aa_aura_conf_dies.clear();
        QueryResult result = WorldDatabase.Query("SELECT * FROM _属性调整_光环");
        if (result) {
            do {
                Field* fields = result->Fetch();
                AA_Aura_Conf conf;
                conf.spellid = fields[1].GetUInt32();
                conf.values = fields[2].GetString();
                conf.spell_pvp = fields[3].GetString();
                conf.spell_pve = fields[4].GetString();
                conf.heal_pvp = fields[5].GetString();
                conf.heal_pve = fields[6].GetString();
                conf.diejia_ceng = fields[7].GetUInt32();
                conf.diejia_spell = fields[8].GetString();
                conf.diejia_gm = fields[9].GetString();
                conf.yichu_ceng = fields[10].GetUInt32();
                conf.die = fields[11].GetUInt32();
                conf.dietime = fields[12].GetUInt32();
                conf.zu = fields[13].GetUInt32();
                aa_aura_conf_zus[conf.zu].push_back(conf.spellid);
                if (conf.die == 1) {
                    aaCenter.aa_aura_conf_dies.insert(conf.spellid);
                }
                aa_aura_confs[conf.spellid] = conf;
                std::map<float, float> spell_pvp; spell_pvp.clear();
                if (conf.spell_pvp != "" && conf.spell_pvp != "0") {
                    aaCenter.AA_StringToMapFloat(conf.spell_pvp, spell_pvp);
                }
                for (auto itr : spell_pvp) {
                    if (itr.second > 0) {
                        aa_aura_conf_spell_pvps[itr.first].insert(conf.spellid);
                    }
                }
                std::map<float, float> spell_pve; spell_pve.clear();
                if (conf.spell_pve != "" && conf.spell_pve != "0") {
                    aaCenter.AA_StringToMapFloat(conf.spell_pve, spell_pve);
                }
                for (auto itr : spell_pve) {
                    if (itr.second > 0) {
                        aa_aura_conf_spell_pves[itr.first].insert(conf.spellid);
                    }
                }
                std::map<float, float> heal_pvp; heal_pvp.clear();
                if (conf.heal_pvp != "" && conf.heal_pvp != "0") {
                    aaCenter.AA_StringToMapFloat(conf.heal_pvp, heal_pvp);
                }
                for (auto itr : heal_pvp) {
                    if (itr.second > 0) {
                        aa_aura_conf_heal_pvps[itr.first].insert(conf.spellid);
                    }
                }
                std::map<float, float> heal_pve; heal_pve.clear();
                if (conf.heal_pve != "" && conf.heal_pve != "0") {
                    aaCenter.AA_StringToMapFloat(conf.heal_pve, heal_pve);
                }
                for (auto itr : heal_pve) {
                    if (itr.second > 0) {
                        aa_aura_conf_heal_pves[itr.first].insert(conf.spellid);
                    }
                }
            } while (result->NextRow());
            TC_LOG_INFO("server.loading", ">> 成功加载 {}条 _属性调整_光环 用时 {} 毫秒", (unsigned long)aa_aura_confs.size(), GetMSTimeDiffToNow(oldMSTime));
        }
    }
    {
        TC_LOG_INFO("server.loading", "正在加载 _奖励_翻牌x...");
        uint32 oldMSTime = getMSTime();
        aa_fanpais.clear();
        aa_fanpai_zus.clear();
        QueryResult result = WorldDatabase.Query("SELECT * FROM _奖励_翻牌x");
        if (result) {
            do {
                Field* fields = result->Fetch();
                AA_Fanpai conf;
                conf.id = fields[1].GetUInt32();
                conf.zu = fields[2].GetUInt32();
                conf.chance = fields[3].GetUInt32();
                conf.itemid = fields[4].GetUInt32();
                conf.gm = fields[5].GetString();
                aa_fanpais[conf.id] = conf;
                aa_fanpai_zus[conf.zu].push_back(conf.id);
            } while (result->NextRow());
            TC_LOG_INFO("server.loading", ">> 成功加载 {}条 _奖励_翻牌x 用时 {} 毫秒", (unsigned long)aa_fanpais.size(), GetMSTimeDiffToNow(oldMSTime));
        }
    }
    {
        TC_LOG_INFO("server.loading", "正在加载 _活动_公告栏x...");
        uint32 oldMSTime = getMSTime();
        aa_huodong_confs.clear();
        QueryResult result = WorldDatabase.Query("SELECT * FROM _活动_公告栏x");
        if (result) {
            do {
                Field* fields = result->Fetch();
                AA_Huodong_Conf conf;
                conf.id = fields[1].GetUInt32();
                conf.game_event = fields[2].GetUInt32();
                conf.time = fields[3].GetUInt32();
                conf.name = fields[4].GetString();
                conf.title = fields[5].GetString();
                conf.icon = fields[6].GetString();
                conf.button = fields[7].GetString();
                conf.need = fields[8].GetUInt32();
                conf.reward = fields[9].GetUInt32();
                aa_huodong_confs[conf.id] = conf;
            } while (result->NextRow());
            TC_LOG_INFO("server.loading", ">> 成功加载 {}条 _活动_公告栏x 用时 {} 毫秒", (unsigned long)aa_huodong_confs.size(), GetMSTimeDiffToNow(oldMSTime));
        }
    }
    {
        TC_LOG_INFO("server.loading", "正在加载 _物品_每日购买次数x...");
        uint32 oldMSTime = getMSTime();
        aa_buy_times.clear();
        QueryResult result = WorldDatabase.Query("SELECT * FROM _物品_每日购买次数x");
        if (result) {
            do {
                Field* fields = result->Fetch();
                AA_Buy_Time conf;
                conf.entry = fields[1].GetUInt32();
                conf.buy_a = fields[2].GetUInt32();
                conf.buy_c = fields[3].GetUInt32();
                conf.yongjiu_a = fields[4].GetUInt32();
                conf.yongjiu_c = fields[5].GetUInt32();
                aa_buy_times[conf.entry] = conf;
            } while (result->NextRow());
            TC_LOG_INFO("server.loading", ">> 成功加载 {}条 _物品_每日购买次数x 用时 {} 毫秒", (unsigned long)aa_buy_times.size(), GetMSTimeDiffToNow(oldMSTime));
        }
    }
    {
        TC_LOG_INFO("server.loading", "正在加载 _奖励_兑换码...");
        uint32 oldMSTime = getMSTime();
        aa_duihuanmas.clear();
        QueryResult result = WorldDatabase.Query("SELECT * FROM _奖励_兑换码");
        if (result) {
            do {
                Field* fields = result->Fetch();
                AA_Duihuanma conf;
                conf.cdk = fields[1].GetString();
                conf.zu = fields[2].GetUInt32();
                conf.need = fields[3].GetUInt32();
                conf.reward = fields[4].GetUInt32();
                conf.guid = fields[5].GetString();
                conf.account = fields[6].GetString();
                conf.ip = fields[7].GetString();
                conf.time = fields[8].GetUInt32();
                conf.notice = fields[9].GetUInt32();
                aa_duihuanmas[conf.cdk] = conf;
            } while (result->NextRow());
            TC_LOG_INFO("server.loading", ">> 成功加载 {}条 _奖励_兑换码 用时 {} 毫秒", (unsigned long)aa_duihuanmas.size(), GetMSTimeDiffToNow(oldMSTime));
        }
    }
    {
        TC_LOG_INFO("server.loading", "正在加载 _奖励_兑换码_领取限制...");
        uint32 oldMSTime = getMSTime();
        aa_duihuanma_confs.clear();
        QueryResult result = WorldDatabase.Query("SELECT * FROM _奖励_兑换码_领取限制");
        if (result) {
            do {
                Field* fields = result->Fetch();
                AA_Duihuanma_Conf conf;
                conf.zu = fields[1].GetUInt32();
                conf.guid = fields[2].GetUInt64();
                conf.account = fields[3].GetUInt32();
                conf.ip = fields[4].GetUInt32();
                aa_duihuanma_confs[conf.zu] = conf;
            } while (result->NextRow());
            TC_LOG_INFO("server.loading", ">> 成功加载 {}条 _奖励_兑换码_领取限制 用时 {} 毫秒", (unsigned long)aa_duihuanma_confs.size(), GetMSTimeDiffToNow(oldMSTime));
        }
    }
    {
        TC_LOG_INFO("server.loading", "正在加载 _奖励_抽奖x...");
        uint32 oldMSTime = getMSTime();
        aa_choujiangs.clear();
        aa_choujiang_zus.clear();
        QueryResult result = WorldDatabase.Query("SELECT * FROM _奖励_抽奖x");
        if (result) {
            do {
                Field* fields = result->Fetch();
                AA_Choujiang conf;
                conf.id = fields[1].GetUInt32();
                conf.zu = fields[2].GetUInt32();
                conf.chance = fields[3].GetUInt32();
                conf.itemid = fields[4].GetUInt32();
                conf.reward = fields[5].GetUInt32();
                conf.notice = fields[6].GetUInt32();
                aa_choujiangs[conf.id] = conf;
                aa_choujiang_zus[conf.zu].push_back(conf.id);
            } while (result->NextRow());
            TC_LOG_INFO("server.loading", ">> 成功加载 {}条 _奖励_抽奖x 用时 {} 毫秒", (unsigned long)aa_choujiangs.size(), GetMSTimeDiffToNow(oldMSTime));
        }
    }
    {
        TC_LOG_INFO("server.loading", "正在加载 _奖励_排行榜x...");
        uint32 oldMSTime = getMSTime();
        aa_paihangxs.clear();
        aa_paihangx_guids.clear();
        aa_paihangx_accounts.clear();
        QueryResult result = WorldDatabase.Query("SELECT * FROM _奖励_排行榜x order by 排名");
        if (result) {
            do {
                Field* fields = result->Fetch();
                AA_PaihangX conf;
                conf.id = fields[1].GetUInt32();
                conf.type = fields[2].GetString();
                conf.type_diy_guid = fields[3].GetString();
                conf.type_diy_account = fields[4].GetString();
                conf.reward = fields[5].GetUInt32();
                conf.auras = fields[6].GetString();
                conf.notice = fields[7].GetUInt32();
                if (conf.type != "") {
                    aa_paihangxs[conf.id][conf.type] = conf;
                }
                if (conf.type_diy_guid != "") {
                    aa_paihangx_guids[conf.id][conf.type_diy_guid] = conf;
                }
                if (conf.type_diy_account != "") {
                    aa_paihangx_accounts[conf.id][conf.type_diy_account] = conf;
                }
            } while (result->NextRow());
            TC_LOG_INFO("server.loading", ">> 成功加载 {}条 _奖励_排行榜x 用时 {} 毫秒", (unsigned long)aa_paihangxs.size(), GetMSTimeDiffToNow(oldMSTime));
        }
    }
    {
        TC_LOG_INFO("server.loading", "正在加载 _物品_鉴定_排除鉴定列表...");
        uint32 oldMSTime = getMSTime();
        aa_item_nojiandings.clear();
        QueryResult result = WorldDatabase.Query("SELECT * FROM _物品_鉴定_排除鉴定列表");
        if (result) {
            do {
                Field* fields = result->Fetch();
                AA_Item_NoJianding conf;
                conf.itemid = fields[1].GetUInt32();
                aa_item_nojiandings[conf.itemid] = conf;
            } while (result->NextRow());
            TC_LOG_INFO("server.loading", ">> 成功加载 {}条 _物品_鉴定_排除鉴定列表 用时 {} 毫秒", (unsigned long)aa_item_nojiandings.size(), GetMSTimeDiffToNow(oldMSTime));
        }
    }
    {
        TC_LOG_INFO("server.loading", "正在加载 _生物_经验值...");
        uint32 oldMSTime = getMSTime();
        aa_creature_exps.clear();
        QueryResult result = WorldDatabase.Query("SELECT * FROM _生物_经验值");
        if (result) {
            do {
                Field* fields = result->Fetch();
                AA_Creature_Exp conf;
                conf.creatureid = fields[1].GetUInt32();
                conf.expdf = fields[2].GetUInt32();
                conf.exppdf = fields[3].GetFloat();
                conf.expdq = fields[4].GetUInt32();
                conf.exppdq = fields[5].GetFloat();
                conf.expjx = fields[6].GetUInt32();
                conf.exppjx = fields[7].GetFloat();
                conf.expcz = fields[8].GetUInt32();
                conf.exppcz = fields[9].GetFloat();
                aa_creature_exps[conf.creatureid] = conf;
            } while (result->NextRow());
            TC_LOG_INFO("server.loading", ">> 成功加载 {}条 _生物_经验值 用时 {} 毫秒", (unsigned long)aa_creature_exps.size(), GetMSTimeDiffToNow(oldMSTime));
        }
    }
    {
        TC_LOG_INFO("server.loading", "正在加载 _生物_随机creature_template...");
        uint32 oldMSTime = getMSTime();
        aa_creature_templates.clear();
        QueryResult result = WorldDatabase.Query("SELECT * FROM _生物_随机creature_template");
        if (result) {
            do {
                Field* fields = result->Fetch();
                AA_CreatureTemplate conf;
                conf.entry = fields[1].GetUInt32();
                conf.entry1 = fields[2].GetUInt32();
                conf.chance = fields[3].GetUInt32();
                aa_creature_templates[conf.entry].push_back(conf);
            } while (result->NextRow());
            TC_LOG_INFO("server.loading", ">> 成功加载 {}条 _生物_随机creature_template 用时 {} 毫秒", (unsigned long)aa_creature_templates.size(), GetMSTimeDiffToNow(oldMSTime));
        }
    }
    {
        TC_LOG_INFO("server.loading", "正在加载 __转职保留技能...");
        uint32 oldMSTime = getMSTime();
        aa_zhuanzhi_spells.clear();
        QueryResult result = WorldDatabase.Query("SELECT * FROM __转职保留技能");
        if (result) {
            do {
                Field* fields = result->Fetch();
                AA_Zhuanzhi_Spell conf;
                conf.spellid = fields[1].GetUInt32();
                aa_zhuanzhi_spells[conf.spellid] = conf;
            } while (result->NextRow());
            TC_LOG_INFO("server.loading", ">> 成功加载 {}条 __转职保留技能 用时 {} 毫秒", (unsigned long)aa_zhuanzhi_spells.size(), GetMSTimeDiffToNow(oldMSTime));
        }
    }
    {
        TC_LOG_INFO("server.loading", "正在加载 _物品_鉴定_品质券...");
        uint32 oldMSTime = getMSTime();
        aa_jianding_items.clear();
        QueryResult result = WorldDatabase.Query("SELECT * FROM _物品_鉴定_品质券");
        if (result) {
            do {
                Field* fields = result->Fetch();
                AA_Jianding_Item conf;
                conf.itemid = fields[1].GetUInt32();
                conf.need = fields[2].GetUInt32();
                conf.chance = fields[3].GetFloat();
                conf.nonsuchid = fields[4].GetUInt32();
                conf.items = fields[5].GetString();
                conf.pcitems = fields[6].GetString();
                conf.notice = fields[7].GetUInt32();
                aa_jianding_items[conf.itemid] = conf;
            } while (result->NextRow());
            TC_LOG_INFO("server.loading", ">> 成功加载 {}条 _物品_鉴定_品质券 用时 {} 毫秒", (unsigned long)aa_jianding_items.size(), GetMSTimeDiffToNow(oldMSTime));
        }
    }
    {
        TC_LOG_INFO("server.loading", "正在加载 _物品_成长_经验券...");
        uint32 oldMSTime = getMSTime();
        aa_chengzhang_items.clear();
        QueryResult result = WorldDatabase.Query("SELECT * FROM _物品_成长_经验券");
        if (result) {
            do {
                Field* fields = result->Fetch();
                AA_Chengzhang_Item conf;
                conf.itemid = fields[1].GetUInt32();
                conf.need = fields[2].GetUInt32();
                conf.exp = fields[3].GetUInt32();
                conf.items = fields[4].GetString();
                conf.pcitems = fields[5].GetString();
                conf.notice = fields[6].GetUInt32();
                aa_chengzhang_items[conf.itemid] = conf;
            } while (result->NextRow());
            TC_LOG_INFO("server.loading", ">> 成功加载 {}条 _物品_成长_经验券 用时 {} 毫秒", (unsigned long)aa_chengzhang_items.size(), GetMSTimeDiffToNow(oldMSTime));
        }
    }
    {
        TC_LOG_INFO("server.loading", "正在加载 _物品_萃取x...");
        uint32 oldMSTime = getMSTime();
        aa_cuiqu_items.clear();
        QueryResult result = WorldDatabase.Query("SELECT * FROM _物品_萃取x");
        if (result) {
            do {
                Field* fields = result->Fetch();
                AA_Cuiqu_Item conf;
                conf.itemid = fields[1].GetUInt32();
                conf.need = fields[2].GetUInt32();
                conf.cuiqu_pos = fields[3].GetString();
                conf.items = fields[4].GetString();
                conf.pcitems = fields[5].GetString();
                aa_cuiqu_items[conf.itemid] = conf;
            } while (result->NextRow());
            TC_LOG_INFO("server.loading", ">> 成功加载 {}条 _物品_萃取x 用时 {} 毫秒", (unsigned long)aa_cuiqu_items.size(), GetMSTimeDiffToNow(oldMSTime));
        }
    }
    //    _物品_放背包加属性
    {
        TC_LOG_INFO("server.loading", "正在加载 _物品_放背包加属性...");
        uint32 oldMSTime = getMSTime();
        aa_item_bags.clear();
        QueryResult result = WorldDatabase.Query("SELECT * FROM _物品_放背包加属性");
        if (result) {
            do {
                Field* fields = result->Fetch();
                AA_Item_Bag conf;
                conf.entry = fields[1].GetUInt32();
                conf.bag = fields[2].GetUInt32();
                aa_item_bags[conf.entry] = conf;
            } while (result->NextRow());
            TC_LOG_INFO("server.loading", ">> 成功加载 {}条 _物品_放背包加属性 用时 {} 毫秒", (unsigned long)aa_item_bags.size(), GetMSTimeDiffToNow(oldMSTime));
        }
    }
    //    _物品_使用获得
    {
        TC_LOG_INFO("server.loading", "正在加载 _物品_使用获得...");
        uint32 oldMSTime = getMSTime();
        aa_item_use_rewards.clear();
        QueryResult result = WorldDatabase.Query("SELECT * FROM _物品_使用获得");
        if (result) {
            do {
                Field* fields = result->Fetch();
                AA_Item_Use_Reward conf;
                conf.entry = fields[1].GetUInt32();
                conf.reward = fields[2].GetUInt32();
                conf.gm = fields[3].GetString();
                aa_item_use_rewards[conf.entry] = conf;
            } while (result->NextRow());
            TC_LOG_INFO("server.loading", ">> 成功加载 {}条 _物品_使用获得 用时 {} 毫秒", (unsigned long)aa_item_use_rewards.size(), GetMSTimeDiffToNow(oldMSTime));
        }
    }
    //    _物品_使用条件
    {
        TC_LOG_INFO("server.loading", "正在加载 _物品_使用条件...");
        uint32 oldMSTime = getMSTime();
        aa_item_use_needs.clear();
        QueryResult result = WorldDatabase.Query("SELECT * FROM _物品_使用条件");
        if (result) {
            do {
                Field* fields = result->Fetch();
                AA_Item_Use_Need conf;
                conf.entry = fields[1].GetUInt32();
                conf.need = fields[2].GetUInt32();
                aa_item_use_needs[conf.entry] = conf;
            } while (result->NextRow());
            TC_LOG_INFO("server.loading", ">> 成功加载 {}条 _物品_使用条件 用时 {} 毫秒", (unsigned long)aa_item_use_needs.size(), GetMSTimeDiffToNow(oldMSTime));
        }
    }
    //    _物品_售卖获得
    {
        TC_LOG_INFO("server.loading", "正在加载 _物品_售卖获得...");
        uint32 oldMSTime = getMSTime();
        aa_item_buy_rewards.clear();
        QueryResult result = WorldDatabase.Query("SELECT * FROM _物品_售卖获得");
        if (result) {
            do {
                Field* fields = result->Fetch();
                AA_Item_Buy_Reward conf;
                conf.entry = fields[1].GetUInt32();
                conf.reward = fields[2].GetUInt32();
                aa_item_buy_rewards[conf.entry] = conf;
            } while (result->NextRow());
            TC_LOG_INFO("server.loading", ">> 成功加载 {}条 _物品_售卖获得 用时 {} 毫秒", (unsigned long)aa_item_buy_rewards.size(), GetMSTimeDiffToNow(oldMSTime));
        }
    }
    //    _物品_购买条件
    {
        TC_LOG_INFO("server.loading", "正在加载 _物品_购买条件...");
        uint32 oldMSTime = getMSTime();
        aa_item_buy_needs.clear();
        QueryResult result = WorldDatabase.Query("SELECT * FROM _物品_购买条件");
        if (result) {
            do {
                Field* fields = result->Fetch();
                AA_Item_Buy_Need conf;
                conf.vendor = fields[1].GetUInt32();
                conf.entry = fields[2].GetUInt32();
                conf.need = fields[3].GetUInt32();
                aa_item_buy_needs[conf.vendor][conf.entry] = conf;
            } while (result->NextRow());
            TC_LOG_INFO("server.loading", ">> 成功加载 {}条 _物品_购买条件 用时 {} 毫秒", (unsigned long)aa_item_buy_needs.size(), GetMSTimeDiffToNow(oldMSTime));
        }
    }
    //    _物品_鉴定_重铸
    {
        TC_LOG_INFO("server.loading", "正在加载 _物品_鉴定_重铸...");
        uint32 oldMSTime = getMSTime();
        aa_item_jianding_czs.clear();
        QueryResult result = WorldDatabase.Query("SELECT * FROM _物品_鉴定_重铸");
        if (result) {
            do {
                Field* fields = result->Fetch();
                AA_Item_Jianding_Cz conf;
                conf.entry = fields[1].GetUInt32();
                conf.cishu = fields[2].GetUInt32();
                conf.need_value = fields[3].GetUInt32();
                conf.need_spell = fields[4].GetUInt32();
                aa_item_jianding_czs[conf.entry] = conf;
            } while (result->NextRow());
            TC_LOG_INFO("server.loading", ">> 成功加载 {}条 _物品_鉴定_重铸 用时 {} 毫秒", (unsigned long)aa_item_jianding_czs.size(), GetMSTimeDiffToNow(oldMSTime));
        }
    }
    //    _物品_鉴定_洗炼
    {
        TC_LOG_INFO("server.loading", "正在加载 _物品_鉴定_洗炼...");
        uint32 oldMSTime = getMSTime();
        aa_item_jianding_xls.clear();
        QueryResult result = WorldDatabase.Query("SELECT * FROM _物品_鉴定_洗炼");
        if (result) {
            do {
                Field* fields = result->Fetch();
                AA_Item_Jianding_Xl conf;
                conf.entry = fields[1].GetUInt32();
                conf.zu = fields[2].GetUInt32();
                aa_item_jianding_xls[conf.entry] = conf;
            } while (result->NextRow());
            TC_LOG_INFO("server.loading", ">> 成功加载 {}条 _物品_鉴定_洗炼 用时 {} 毫秒", (unsigned long)aa_item_jianding_xls.size(), GetMSTimeDiffToNow(oldMSTime));
        }
    }
    //    _物品_鉴定_购买
    {
        TC_LOG_INFO("server.loading", "正在加载 _物品_鉴定_购买...");
        uint32 oldMSTime = getMSTime();
        aa_item_jianding_buys.clear();
        QueryResult result = WorldDatabase.Query("SELECT * FROM _物品_鉴定_购买");
        if (result) {
            do {
                Field* fields = result->Fetch();
                AA_Item_Jianding_Buy conf;
                conf.entry = fields[1].GetUInt32();
                conf.zus = fields[2].GetString();
                aa_item_jianding_buys[conf.entry] = conf;
            } while (result->NextRow());
            TC_LOG_INFO("server.loading", ">> 成功加载 {}条 _物品_鉴定_购买 用时 {} 毫秒", (unsigned long)aa_item_jianding_buys.size(), GetMSTimeDiffToNow(oldMSTime));
        }
    }
    //    _物品_强化组
    {
        TC_LOG_INFO("server.loading", "正在加载 _物品_强化_按ID控制...");
        uint32 oldMSTime = getMSTime();
        aa_item_qh_ids.clear();
        QueryResult result = WorldDatabase.Query("SELECT * FROM _物品_强化_按ID控制");
        if (result) {
            do {
                Field* fields = result->Fetch();
                AA_Item_Qh_Id conf;
                conf.entry = fields[1].GetUInt32();
                conf.zus = fields[2].GetString();
                aa_item_qh_ids[conf.entry] = conf;
            } while (result->NextRow());
            TC_LOG_INFO("server.loading", ">> 成功加载 {}条 _物品_强化_按ID控制 用时 {} 毫秒", (unsigned long)aa_item_qh_ids.size(), GetMSTimeDiffToNow(oldMSTime));
        }
    }
    //    _物品_成长组
    {
        TC_LOG_INFO("server.loading", "正在加载 _物品_成长_按ID控制...");
        uint32 oldMSTime = getMSTime();
        aa_item_level_ids.clear();
        QueryResult result = WorldDatabase.Query("SELECT * FROM _物品_成长_按ID控制");
        if (result) {
            do {
                Field* fields = result->Fetch();
                AA_Item_Level_Id conf;
                conf.entry = fields[1].GetUInt32();
                conf.zus = fields[2].GetString();
                aa_item_level_ids[conf.entry] = conf;
            } while (result->NextRow());
            TC_LOG_INFO("server.loading", ">> 成功加载 {}条 _物品_成长_按ID控制 用时 {} 毫秒", (unsigned long)aa_item_level_ids.size(), GetMSTimeDiffToNow(oldMSTime));
        }
    }
    {
        TC_LOG_INFO("server.loading", "正在加载 __系统_聊天屏蔽...");
        uint32 oldMSTime = getMSTime();
        aa_chats.clear();
        QueryResult result = WorldDatabase.Query("SELECT * FROM __系统_聊天屏蔽");
        if (result) {
            do {
                Field* fields = result->Fetch();
                AA_Chat conf;
                conf.msg = fields[1].GetString();
                conf.tomsg = fields[2].GetString();
                conf.show = fields[3].GetUInt32();
                aa_chats[conf.msg] = conf;
            } while (result->NextRow());
            TC_LOG_INFO("server.loading", ">> 成功加载 {}条 __系统_聊天屏蔽 用时 {} 毫秒", (unsigned long)aa_chats.size(), GetMSTimeDiffToNow(oldMSTime));
        }
    }
    {
        TC_LOG_INFO("server.loading", "正在加载 _奖励_连杀...");
        uint32 oldMSTime = getMSTime();
        aa_lianshas.clear();
        QueryResult result = WorldDatabase.Query("SELECT * FROM _奖励_连杀");
        if (result) {
            do {
                Field* fields = result->Fetch();
                AA_Liansha conf;
                conf.count = fields[1].GetUInt32();
                conf.reward_liansha = fields[2].GetUInt32();
                conf.quyu_liansha = fields[3].GetString();
                conf.notice_liansha = fields[4].GetUInt32();
                conf.reward_zhongjie = fields[5].GetUInt32();
                conf.quyu_zhongjie = fields[6].GetString();
                conf.notice_zhongjie = fields[7].GetUInt32();
                aa_lianshas[conf.count] = conf;
            } while (result->NextRow());
            TC_LOG_INFO("server.loading", ">> 成功加载 {}条 _奖励_连杀 用时 {} 毫秒", (unsigned long)aa_lianshas.size(), GetMSTimeDiffToNow(oldMSTime));
        }
    }
    {
        TC_LOG_INFO("server.loading", "正在加载 __系统_配置...");

        uint32 oldMSTime = getMSTime();

        aa_world_confs.clear();                              // need for reload case

        //                                               0      1       2     3
        QueryResult result = WorldDatabase.Query("SELECT * FROM __系统_配置 ORDER BY id");
        if (result) {
            do {
                Field* fields = result->Fetch();

                AA_World_Conf conf;

                conf.id = fields[1].GetUInt32();
                conf.value1 = fields[2].GetInt32();
                conf.value2 = fields[3].GetString();

                aa_world_confs[conf.id] = conf;

            } while (result->NextRow());


            TC_LOG_INFO("server.loading", ">> 成功加载 {}条 __系统_配置 用时 {} 毫秒", (unsigned long)aa_world_confs.size(), GetMSTimeDiffToNow(oldMSTime));
        }
    }
    {
        TC_LOG_INFO("server.loading", "正在加载 _会员...");

        uint32 oldMSTime = getMSTime();

        aa_vip_confs.clear();

        QueryResult result = WorldDatabase.Query("SELECT * FROM _会员 ORDER BY level");
        if (result) {
            do {
                Field* fields = result->Fetch();

                AA_Vip_Conf conf;
                conf.level = fields[1].GetUInt32();
                conf.need = fields[2].GetUInt32();
                conf.talent = fields[3].GetUInt32();
                conf.reward = fields[4].GetUInt32();
                conf.add_reward = fields[5].GetUInt32();
                conf.exp = fields[6].GetFloat();
                conf.zhuanye = fields[7].GetUInt32();
                conf.loot = fields[8].GetFloat();
                conf.shuliang = fields[9].GetUInt32();
                conf.shuliang_chance = fields[10].GetFloat();
                conf.paodian = fields[11].GetUInt32();
                conf.qianghua = fields[12].GetFloat();
                conf.hecheng = fields[13].GetFloat();
                conf.spells = fields[14].GetString();
                conf.botcount = fields[15].GetUInt32();
                conf.notice = fields[16].GetUInt32();
                conf.text = fields[17].GetString();
                aa_vip_confs[conf.level] = conf;

            } while (result->NextRow());


            TC_LOG_INFO("server.loading", ">> 成功加载 {}条 _会员 用时 {} 毫秒", (unsigned long)aa_vip_confs.size(), GetMSTimeDiffToNow(oldMSTime));
        }
    }

    {
        TC_LOG_INFO("server.loading", "正在加载 _角色_斗气...");

        uint32 oldMSTime = getMSTime();

        aa_douqi_confs.clear();

        QueryResult result = WorldDatabase.Query("SELECT * FROM _角色_斗气 ORDER BY level");
        if (result) {
            do {
                Field* fields = result->Fetch();

                AA_Douqi_Conf conf;
                conf.level = fields[1].GetUInt32();
                conf.exp = fields[2].GetUInt32();
                conf.reward = fields[3].GetUInt32();
                conf.spells = fields[4].GetString();
                conf.notice = fields[5].GetUInt32();
                conf.text = fields[6].GetString();
                aa_douqi_confs[conf.level] = conf;

            } while (result->NextRow());


            TC_LOG_INFO("server.loading", ">> 成功加载 {}条 _角色_斗气 用时 {} 毫秒", (unsigned long)aa_douqi_confs.size(), GetMSTimeDiffToNow(oldMSTime));
        }
    }

    {
        TC_LOG_INFO("server.loading", "正在加载 _角色_军衔...");

        uint32 oldMSTime = getMSTime();

        aa_junxian_confs.clear();

        QueryResult result = WorldDatabase.Query("SELECT * FROM _角色_军衔 ORDER BY level");
        if (result) {
            do {
                Field* fields = result->Fetch();

                AA_Junxian_Conf conf;
                conf.level = fields[1].GetUInt32();
                conf.exp = fields[2].GetUInt32();
                conf.reward = fields[3].GetUInt32();
                conf.spells = fields[4].GetString();
                conf.notice = fields[5].GetUInt32();
                conf.text = fields[6].GetString();
                aa_junxian_confs[conf.level] = conf;

            } while (result->NextRow());


            TC_LOG_INFO("server.loading", ">> 成功加载 {}条 _角色_军衔 用时 {} 毫秒", (unsigned long)aa_junxian_confs.size(), GetMSTimeDiffToNow(oldMSTime));
        }
    }

    {
        TC_LOG_INFO("server.loading", "正在加载 _角色_巅峰...");

        uint32 oldMSTime = getMSTime();

        aa_dianfeng_confs.clear();

        QueryResult result = WorldDatabase.Query("SELECT * FROM _角色_巅峰 ORDER BY level");
        if (result) {
            do {
                Field* fields = result->Fetch();

                AA_Dianfeng_Conf conf;
                conf.level = fields[1].GetUInt32();
                conf.exp = fields[2].GetUInt32();
                conf.reward = fields[3].GetUInt32();
                conf.spells = fields[4].GetString();
                conf.notice = fields[5].GetUInt32();
                conf.text = fields[6].GetString();
                aa_dianfeng_confs[conf.level] = conf;

            } while (result->NextRow());


            TC_LOG_INFO("server.loading", ">> 成功加载 {}条 _角色_巅峰 用时 {} 毫秒", (unsigned long)aa_dianfeng_confs.size(), GetMSTimeDiffToNow(oldMSTime));
        }
    }

    {
        TC_LOG_INFO("server.loading", "正在加载 _属性调整_技能...");
        uint32 oldMSTime = getMSTime();
        aa_spell_confs.clear();
        QueryResult result = WorldDatabase.Query("SELECT * FROM _属性调整_技能");
        if (result) {
            do {
                Field* fields = result->Fetch();
                AA_Spell_Conf conf;
                conf.spellid = fields[1].GetUInt32();
                conf.need = fields[2].GetUInt32();
                conf.spell_cast = fields[3].GetString();
                conf.gm_cast = fields[4].GetString();
                conf.gm_learn = fields[5].GetString();
                conf.gm_unlearn = fields[6].GetString();
                conf.target = fields[7].GetString();
                conf.dmg_pvp = fields[8].GetFloat();
                conf.dmg_pve = fields[9].GetFloat();
                conf.healing_pvp = fields[10].GetFloat();
                conf.healing_pve = fields[11].GetFloat();
                conf.isOk = fields[12].GetString();
                conf.time_shifa = fields[13].GetUInt32();
                conf.time_chixu = fields[14].GetUInt32();
                conf.time_lengque = fields[15].GetUInt32();
                conf.chance = fields[16].GetFloat();
                conf.shifangxianzhi = fields[17].GetUInt32();
                for (size_t i = 0; i < MAX_SPELL_EFFECTS; i++)
                {
                    conf.Periodic[i] = fields[i+15].GetUInt32();
                }
                
                aa_spell_confs[conf.spellid] = conf;
            } while (result->NextRow());
            TC_LOG_INFO("server.loading", ">> 成功加载 {}条 _属性调整_技能 用时 {} 毫秒", (unsigned long)aa_spell_confs.size(), GetMSTimeDiffToNow(oldMSTime));
        }
    }
    {
        TC_LOG_INFO("server.loading", "正在加载 _属性调整_宠物...");

        uint32 oldMSTime = getMSTime();

        aa_pet_confs.clear();                              // need for reload case

        QueryResult result = WorldDatabase.Query("SELECT * FROM _属性调整_宠物");
        if (result) {
            do {
                Field* fields = result->Fetch();

                AA_Pet_Conf conf;
                conf.class1 = fields[1].GetUInt32();
                conf.agility = fields[2].GetFloat();
                conf.strength = fields[3].GetFloat();
                conf.intellect = fields[4].GetFloat();
                conf.spirit = fields[5].GetFloat();
                conf.stamina = fields[6].GetFloat();
                aa_pet_confs[conf.class1] = conf;
            } while (result->NextRow());

            TC_LOG_INFO("server.loading", ">> 成功加载 {}条 _属性调整_宠物 用时 {} 毫秒", (unsigned long)aa_pet_confs.size(), GetMSTimeDiffToNow(oldMSTime));
        }
    }

    {
        TC_LOG_INFO("server.loading", "正在加载 _模板_宠物技能...");
        uint32 oldMSTime = getMSTime();
        aa_pet_spells.clear();
        aa_pet_spell_group.clear();
        QueryResult result = WorldDatabase.Query("SELECT * FROM _模板_宠物技能 ORDER BY id");
        if (result) {
            do {
                Field* fields = result->Fetch();
                AA_Pet_Spell conf;
                conf.id = fields[1].GetUInt32();
                conf.group = fields[2].GetUInt32();
                conf.chance = fields[3].GetUInt32();
                conf.spellid = fields[4].GetUInt32();
                aa_pet_spells[conf.id] = conf;
                aa_pet_spell_group[conf.group].push_back(conf);
            } while (result->NextRow());
            TC_LOG_INFO("server.loading", ">> 成功加载 {}条 _模板_宠物技能 用时 {} 毫秒", (unsigned long)aa_pet_spells.size(), GetMSTimeDiffToNow(oldMSTime));
        }
    }

    {
        TC_LOG_INFO("server.loading", "正在加载 _模板_物品属性...");
        uint32 oldMSTime = getMSTime();
        aa_stats.clear();
        aa_stat_zus.clear();
        aa_stat_types.clear();
        QueryResult result = WorldDatabase.Query("SELECT * FROM _模板_物品属性 ORDER BY id");
        if (result) {
            do {
                Field* fields = result->Fetch();
                AA_Stat conf;
                conf.text = fields[1].GetString();
                conf.id = fields[2].GetUInt32();
                conf.zu = fields[3].GetUInt32();
                conf.type = fields[4].GetUInt32();
                conf.chance = fields[5].GetUInt32();
                conf.value = fields[6].GetInt32();
                conf.point = fields[7].GetInt32();
                conf.cuiqu_need = fields[8].GetUInt32();
                conf.cuiqu_only = fields[9].GetUInt32();
                conf.update_time = fields[10].GetUInt32();
                aa_stats[conf.id] = conf;
                aa_stat_zus[conf.zu].push_back(conf.id);
                aa_stat_types[conf.zu][conf.type] = conf.id;
            } while (result->NextRow());
            TC_LOG_INFO("server.loading", ">> 成功加载 {}条 _模板_物品属性 用时 {} 毫秒", (unsigned long)aa_stats.size(), GetMSTimeDiffToNow(oldMSTime));
        }
    }
    {
        TC_LOG_INFO("server.loading", "正在加载 _模板_物品属性_限制...");
        uint32 oldMSTime = getMSTime();
        aa_stat_xianzhis.clear();
        QueryResult result = WorldDatabase.Query("SELECT * FROM _模板_物品属性_限制");
        if (result) {
            do {
                Field* fields = result->Fetch();
                AA_Stat_Xianzhi conf;
                conf.type = fields[1].GetUInt32();
                conf.value = fields[2].GetInt32();
                aa_stat_xianzhis[conf.type] = conf;
            } while (result->NextRow());
            TC_LOG_INFO("server.loading", ">> 成功加载 {}条 _模板_物品属性_限制 用时 {} 毫秒", (unsigned long)aa_stat_xianzhis.size(), GetMSTimeDiffToNow(oldMSTime));
        }
    }
    {
        TC_LOG_INFO("server.loading", "正在加载 _模板_物品技能...");
        uint32 oldMSTime = getMSTime();
        aa_spells.clear();
        aa_spell_values.clear();
        aa_spell_zus.clear();
        QueryResult result = WorldDatabase.Query("SELECT * FROM _模板_物品技能 ORDER BY id");
        if (result) {
            do {
                Field* fields = result->Fetch();
                AA_Spell conf;
                int i = 2;
                conf.text = "";
                conf.id = fields[i++].GetUInt32();
                conf.zu = fields[i++].GetUInt32();
                conf.class1 = fields[i++].GetString();
                conf.subclass = fields[i++].GetString();
                conf.inventoryType = fields[i++].GetString();
                conf.values = fields[i++].GetString();
                conf.chance = fields[i++].GetUInt32();
                conf.LegacySlotIndex = fields[i++].GetUInt8();
                conf.TriggerType = fields[i++].GetInt8();
                conf.Charges = fields[i++].GetInt16();
                conf.CoolDownMSec = fields[i++].GetInt32();
                conf.CategoryCoolDownMSec = fields[i++].GetInt32();
                conf.SpellCategoryID = fields[i++].GetUInt16();
                conf.ChrSpecializationID = fields[i++].GetUInt16();
                conf.cuiqu_need = fields[i++].GetUInt32();
                conf.cuiqu_only = fields[i++].GetUInt32();
                conf.update_time = fields[i++].GetUInt32();
                aa_spells[conf.id] = conf;
                aa_spell_zus[conf.zu].push_back(conf.id);
                if (conf.values != "" && conf.values != "0") {
                    aa_spell_values.insert(conf.id);
                }
            } while (result->NextRow());
            TC_LOG_INFO("server.loading", ">> 成功加载 {}条 _模板_物品技能 用时 {} 毫秒", (unsigned long)aa_spells.size(), GetMSTimeDiffToNow(oldMSTime));
        }
    }
    {
        TC_LOG_INFO("server.loading", "正在加载 _物品_鉴定...");
        uint32 oldMSTime = getMSTime();
        aa_item_nonsuchs.clear();
        aa_item_nonsuch_zus.clear();
        QueryResult result = WorldDatabase.Query("SELECT * FROM _物品_鉴定 ORDER BY 等级");
        if (result) {
            do {
                Field* fields = result->Fetch();
                AA_Item_Nonsuch conf;
                conf.id = fields[1].GetUInt32();
                conf.zu = fields[2].GetUInt32();
                conf.level = fields[3].GetUInt32();
                conf.chance = fields[4].GetUInt32();
                conf.cz_zus = fields[5].GetString();
                conf.qh_zus = fields[6].GetString();
                conf.fg_statzu = fields[7].GetUInt32();
                conf.fg_count1 = fields[8].GetUInt32();
                conf.fg_count2 = fields[9].GetUInt32();
                conf.fg_value1 = fields[10].GetUInt32();
                conf.fg_value2 = fields[11].GetUInt32();
                conf.fg_only = fields[12].GetUInt32();
                conf.jp_statzu = fields[13].GetUInt32();
                conf.jp_type = fields[14].GetUInt32();
                conf.jp_value1 = fields[15].GetUInt32();
                conf.jp_value2 = fields[16].GetUInt32();
                conf.jp_percent1 = fields[17].GetUInt32();
                conf.jp_percent2 = fields[18].GetUInt32();
                conf.fmval_statzu = fields[19].GetString();
                conf.fmval_count1 = fields[20].GetUInt32();
                conf.fmval_count2 = fields[21].GetUInt32();
                conf.fmval_value1 = fields[22].GetInt32();
                conf.fmval_value2 = fields[23].GetInt32();
                conf.fmval_only = fields[24].GetUInt32();
                conf.fmspell_spellzu = fields[25].GetString();
                conf.fmspell_count1 = fields[26].GetUInt32();
                conf.fmspell_count2 = fields[27].GetUInt32();
                conf.fmspell_only = fields[28].GetUInt32();
                conf.text = fields[29].GetString();
                conf.textpre = fields[30].GetString();
                conf.textsuf = fields[31].GetString();
                conf.detail = fields[32].GetString();
                conf.chuandai = fields[33].GetUInt32();
                conf.fw_count1 = fields[34].GetUInt32();
                conf.fw_count2 = fields[35].GetUInt32();
                conf.itemsets = fields[36].GetString();
                conf.notice = fields[37].GetUInt32();
                aa_item_nonsuchs[conf.id] = conf;
                aa_item_nonsuch_zus[conf.zu].push_back(conf.id);
            } while (result->NextRow());
            TC_LOG_INFO("server.loading", ">> 成功加载 {}条 _物品_鉴定 用时 {} 毫秒", (unsigned long)aa_item_nonsuchs.size(), GetMSTimeDiffToNow(oldMSTime));
        }
    }
    {
        TC_LOG_INFO("server.loading", "正在加载 _物品_鉴定_按ID控制...");
        uint32 oldMSTime = getMSTime();
        aa_item_nonsuch_ids.clear();
        QueryResult result = WorldDatabase.Query("SELECT * FROM _物品_鉴定_按ID控制");
        if (result) {
            do {
                Field* fields = result->Fetch();
                AA_Item_Nonsuch_Id conf;
                conf.entry = fields[1].GetUInt32();
                conf.zu = fields[2].GetUInt32();
                aa_item_nonsuch_ids[conf.entry] = conf;
            } while (result->NextRow());
            TC_LOG_INFO("server.loading", ">> 成功加载 {}条 _物品_鉴定_按ID控制 用时 {} 毫秒", (unsigned long)aa_item_nonsuch_ids.size(), GetMSTimeDiffToNow(oldMSTime));
        }
    }
    {
        TC_LOG_INFO("server.loading", "正在加载 _物品_强化...");
        uint32 oldMSTime = getMSTime();
        aa_item_upgrades.clear();
        aa_item_upgrade_zus.clear();
        QueryResult result = WorldDatabase.Query("SELECT * FROM _物品_强化 ORDER BY 等级");
        if (result) {
            do {
                Field* fields = result->Fetch();
                AA_Item_Upgrade conf;
                conf.id = fields[1].GetUInt32();
                conf.zu = fields[2].GetUInt32();
                conf.level = fields[3].GetUInt32();
                conf.chance = fields[4].GetFloat();
                conf.stat_group = fields[5].GetUInt32();
                conf.distribution = fields[6].GetUInt32();
                conf.value1 = fields[7].GetUInt32();
                conf.value2 = fields[8].GetUInt32();
                conf.percent1 = fields[9].GetUInt32();
                conf.percent2 = fields[10].GetUInt32();
                conf.reward_value = fields[11].GetUInt32();
                conf.reward_percent = fields[12].GetUInt32();
                conf.upgrade_spell = fields[13].GetString();
                conf.destroy = fields[14].GetUInt32();//0升级失败不变 1升级失败清零 2升级失败消失
                conf.need = fields[15].GetUInt32();
                conf.chance_jd = fields[16].GetFloat();
                conf.notice = fields[17].GetUInt32();
                aa_item_upgrades[conf.id] = conf;
                aa_item_upgrade_zus[conf.zu].push_back(conf.id);
            } while (result->NextRow());
            TC_LOG_INFO("server.loading", ">> 成功加载 {}条 _物品_强化 用时 {} 毫秒", (unsigned long)aa_item_upgrades.size(), GetMSTimeDiffToNow(oldMSTime));
        }
    }
    {
        TC_LOG_INFO("server.loading", "正在加载 _物品_成长...");
        uint32 oldMSTime = getMSTime();
        aa_item_levels.clear();
        aa_item_level_zus.clear();
        QueryResult result = WorldDatabase.Query("SELECT * FROM _物品_成长 ORDER BY 等级");
        if (result) {
            do {
                Field* fields = result->Fetch();
                AA_Item_Level conf;
                conf.id = fields[1].GetUInt32();
                conf.zu = fields[2].GetUInt32();
                conf.level = fields[3].GetUInt32();
                conf.exp = fields[4].GetUInt32();
                conf.stat_group = fields[5].GetUInt32();
                conf.distribution = fields[6].GetUInt32();
                conf.value1 = fields[7].GetUInt32();
                conf.value2 = fields[8].GetUInt32();
                conf.percent1 = fields[9].GetUInt32();
                conf.percent2 = fields[10].GetUInt32();
                conf.reward_value = fields[11].GetUInt32();
                conf.reward_percent = fields[12].GetUInt32();
                conf.spell = fields[13].GetString();
                conf.notice = fields[14].GetUInt32();
                aa_item_levels[conf.id] = conf;
                aa_item_level_zus[conf.zu].push_back(conf.id);
            } while (result->NextRow());
            TC_LOG_INFO("server.loading", ">> 成功加载 {}条 _物品_成长 用时 {} 毫秒", (unsigned long)aa_item_levels.size(), GetMSTimeDiffToNow(oldMSTime));
        }
    }
    {
        TC_LOG_INFO("server.loading", "正在加载 __系统_公告...");

        uint32 oldMSTime = getMSTime();

        aa_notices.clear();                              // need for reload case

        //                                               0      1       2     3
        QueryResult result = WorldDatabase.Query("SELECT * FROM __系统_公告 ORDER BY entry");
        if (result) {
            do {
                Field* fields = result->Fetch();

                AA_Notice conf;

                conf.entry = fields[1].GetUInt32();
                conf.content_default1 = fields[2].GetString();
                conf.content_default2 = fields[3].GetString();
                conf.target = fields[4].GetInt32();
                conf.type = fields[5].GetUInt32();

                aa_notices[conf.entry] = conf;

            } while (result->NextRow());


            TC_LOG_INFO("server.loading", ">> 成功加载 {}条 __系统_公告 用时 {} 毫秒", (unsigned long)aa_notices.size(), GetMSTimeDiffToNow(oldMSTime));
        }
    }
    {
        TC_LOG_INFO("server.loading", "正在加载 _传送...");
        uint32 oldMSTime = getMSTime();
        aa_teleports.clear();
        aa_teleport_targets.clear();
        QueryResult result = WorldDatabase.Query("SELECT * FROM _传送 ORDER BY id");
        if (result) {
            do
            {
                Field* fields = result->Fetch();
                AA_Teleport_Conf conf;
                conf.id = fields[1].GetUInt32();
                conf.menuid = fields[2].GetUInt32();
                conf.targetid = fields[3].GetUInt32();
                conf.title = fields[4].GetString();
                conf.subtitle = fields[5].GetString();
                conf.icon1 = fields[6].GetUInt32();
                conf.script = fields[7].GetString();
                conf.gm = fields[8].GetString();
                conf.need = fields[9].GetUInt32();
                conf.is_visible = fields[10].GetUInt32();
                conf.is_zhandou = fields[11].GetUInt32();
                conf.notice = fields[12].GetUInt32();
                aa_teleports[conf.id] = conf;
                aa_teleport_targets[conf.targetid].push_back(conf.id);
            } while (result->NextRow());
            TC_LOG_INFO("server.loading", ">> 成功加载 {}条 _传送 用时 {} 毫秒", (unsigned long)aa_teleports.size(), GetMSTimeDiffToNow(oldMSTime));
        }
    }
    {
        TC_LOG_INFO("server.loading", "正在加载 _属性调整_生物...");
        uint32 oldMSTime = getMSTime();
        aa_creatures.clear();
        aa_creature_zus.clear();
        QueryResult result = WorldDatabase.Query("SELECT * FROM _属性调整_生物 ORDER BY id");
        if (result) {
            do
            {
                Field* fields = result->Fetch();
                AA_Creature conf;
                conf.id = fields[1].GetUInt32();
                conf.zu = fields[2].GetUInt32();
                conf.chance = fields[3].GetFloat();
                conf.level = fields[4].GetUInt32();
                conf.walk_speed = fields[5].GetFloat();
                conf.walk_speed1 = fields[6].GetFloat();
                conf.attack_speed = fields[7].GetUInt32();
                conf.attack_speed1 = fields[8].GetUInt32();
                conf.health = fields[9].GetUInt32();
                conf.health1 = fields[10].GetUInt32();
                conf.mana = fields[11].GetUInt32();
                conf.mana1 = fields[12].GetUInt32();
                conf.armor = fields[13].GetUInt32();
                conf.armor1 = fields[14].GetUInt32();
                conf.resistance = fields[15].GetInt32();
                conf.resistance1 = fields[16].GetInt32();
                conf.damage_min = fields[17].GetUInt32();
                conf.damage_max = fields[18].GetUInt32();
                conf.damage = fields[19].GetFloat();
                conf.damage_spell_min = fields[20].GetUInt32();
                conf.damage_spell_max = fields[21].GetUInt32();
                conf.damage_spell = fields[22].GetFloat();
                conf.health_spell_min = fields[23].GetUInt32();
                conf.health_spell_max = fields[24].GetUInt32();
                conf.health_spell = fields[25].GetFloat();
                conf.jianshang_wl = fields[26].GetInt32();
                conf.jianshang_mf = fields[27].GetInt32();
                conf.shangxian = fields[28].GetUInt32();
                conf.qiege = fields[29].GetUInt32();
                conf.ais = fields[30].GetString();
                conf.nonsuch_group = fields[31].GetUInt32();
                conf.lootid = fields[32].GetString();
                conf.lootid1 = fields[33].GetString();
                conf.old_loot = fields[34].GetString();
                conf.moxing = fields[35].GetString();
                conf.moxing1 = fields[36].GetString();
                conf.moxing2 = fields[37].GetString();
                conf.moxing3 = fields[38].GetString();
                conf.scale = fields[39].GetFloat();
                conf.type = fields[40].GetUInt32();
                conf.reward = fields[41].GetUInt32();
                conf.reward_chance = fields[42].GetFloat();
                conf.reward_dz = fields[43].GetUInt32();
                conf.reward_dz_chance = fields[44].GetFloat();
                conf.reward_dw = fields[45].GetUInt32();
                conf.reward_dw_chance = fields[46].GetFloat();
                conf.tanchuang = fields[47].GetUInt32();
                conf.notice = fields[48].GetUInt32();
                conf.notice_sx = fields[49].GetUInt32();
                aa_creatures[conf.id] = conf;
                aa_creature_zus[conf.zu].push_back(conf);
            } while (result->NextRow());
            TC_LOG_INFO("server.loading", ">> 成功加载 {}条 _属性调整_生物 用时 {} 毫秒", (unsigned long)aa_creatures.size(), GetMSTimeDiffToNow(oldMSTime));
        }
    }
    {
        TC_LOG_INFO("server.loading", "正在加载 _属性调整_按ID调整生物...");
        uint32 oldMSTime = getMSTime();
        aa_creature_ids.clear();
        QueryResult result = WorldDatabase.Query("SELECT * FROM _属性调整_按ID调整生物");
        if (result) {
            do {
                Field* fields = result->Fetch();
                AA_Creature_Id conf;
                uint32 i = 1;
                conf.entry = fields[i++].GetUInt32();
                conf.nanduid = fields[i++].GetUInt32();
                conf.zus = fields[i++].GetString();
                conf.pet_moxing = fields[i++].GetString();
                conf.pet_moxing1 = fields[i++].GetString();
                conf.pet_moxing2 = fields[i++].GetString();
                conf.pet_moxing3 = fields[i++].GetString();
                conf.pet_scale = fields[i++].GetFloat();
                aa_creature_ids[conf.entry][conf.nanduid] = conf;
            } while (result->NextRow());
            TC_LOG_INFO("server.loading", ">> 成功加载 {}条 _属性调整_按ID调整生物 用时 {} 毫秒", (unsigned long)aa_creature_ids.size(), GetMSTimeDiffToNow(oldMSTime));
        }
    }
    {
        TC_LOG_INFO("server.loading", "正在加载 _属性调整_按地图调整生物物体...");
        uint32 oldMSTime = getMSTime();
        aa_creature_maps.clear();
        aa_creature_map_areas.clear();
        aa_creature_map_zones.clear();
        aa_creature_map_maps.clear();
        aa_creature_map_alls.clear();
        aa_creature_map_yewai_areas.clear();
        aa_creature_map_yewai_zones.clear();
        aa_creature_map_yewai_maps.clear();
        aa_creature_map_yewai_alls.clear();
        QueryResult result = WorldDatabase.Query("SELECT * FROM _属性调整_按地图调整生物物体");
        if (result) {
            do
            {
                Field* fields = result->Fetch();
                AA_Creature_Map conf;
                conf.id = fields[1].GetUInt32();
                conf.nandumoshi = fields[2].GetString();
                conf.nanduid = fields[3].GetUInt32();
                conf.playercount = fields[4].GetUInt32();
                conf.rank = fields[5].GetString();
                conf.map = fields[6].GetInt32();
                conf.zone = fields[7].GetInt32();
                conf.area = fields[8].GetInt32();
                conf.c_zus = fields[9].GetString();
                conf.o_zus = fields[10].GetString();
                conf.factions = fields[11].GetString();
                conf.entrys = fields[12].GetString();
                aa_creature_maps[conf.id] = conf;
                if (conf.area != -1) {
                    aaCenter.aa_creature_map_areas[conf.area][conf.nandumoshi][conf.rank][conf.nanduid][conf.playercount] = conf.id;
                    if (conf.nanduid == 0 && conf.nandumoshi == "全部") {
                        aa_creature_map_yewai_areas[conf.area][conf.rank] = conf.id;
                    }
                }
                if (conf.zone != -1) {
                    aaCenter.aa_creature_map_zones[conf.zone][conf.nandumoshi][conf.rank][conf.nanduid][conf.playercount] = conf.id;
                    if (conf.nanduid == 0 && conf.nandumoshi == "全部") {
                        aa_creature_map_yewai_zones[conf.zone][conf.rank] = conf.id;
                    }
                }
                if (conf.map != -1) {
                    aaCenter.aa_creature_map_maps[conf.map][conf.nandumoshi][conf.rank][conf.nanduid][conf.playercount] = conf.id;
                    if (conf.nanduid == 0 && conf.nandumoshi == "全部") {
                        aa_creature_map_yewai_maps[conf.map][conf.rank] = conf.id;
                    }
                }
                if (conf.area == -1 && conf.zone == -1 && conf.map == -1) {
                    aaCenter.aa_creature_map_alls[conf.nandumoshi][conf.rank][conf.nanduid][conf.playercount] = conf.id;
                    if (conf.nanduid == 0 && conf.nandumoshi == "全部") {
                        aa_creature_map_yewai_alls[conf.rank] = conf.id;
                    }
                }
            } while (result->NextRow());
            TC_LOG_INFO("server.loading", ">> 成功加载 {}条 _属性调整_按地图调整生物物体 用时 {} 毫秒", (unsigned long)aa_creature_maps.size(), GetMSTimeDiffToNow(oldMSTime));
        }
    }
    {
        TC_LOG_INFO("server.loading", "正在加载 _属性调整_物体...");
        uint32 oldMSTime = getMSTime();
        aa_objects.clear();
        aa_object_zus.clear();
        QueryResult result = WorldDatabase.Query("SELECT * FROM _属性调整_物体 ORDER BY id");
        if (result) {
            do
            {
                Field* fields = result->Fetch();
                AA_Object conf;
                conf.id = fields[1].GetUInt32();
                conf.zu = fields[2].GetUInt32();
                conf.chance = fields[3].GetFloat();
                conf.nonsuch_group = fields[4].GetUInt32();
                conf.lootid = fields[5].GetString();
                conf.lootid1 = fields[6].GetString();
                conf.old_loot = fields[7].GetString();
                conf.scale = fields[8].GetFloat();
                conf.reward = fields[9].GetUInt32();
                conf.reward_chance = fields[10].GetFloat();
                conf.reward_dz = fields[11].GetUInt32();
                conf.reward_dz_chance = fields[12].GetFloat();
                conf.reward_dw = fields[13].GetUInt32();
                conf.reward_dw_chance = fields[14].GetFloat();
                conf.tanchuang = fields[15].GetUInt32();
                conf.notice = fields[16].GetUInt32();
                aa_objects[conf.id] = conf;
                aa_object_zus[conf.zu].push_back(conf);
            } while (result->NextRow());
            TC_LOG_INFO("server.loading", ">> 成功加载 {}条 _属性调整_物体 用时 {} 毫秒", (unsigned long)aa_objects.size(), GetMSTimeDiffToNow(oldMSTime));
        }
    }
    {
        TC_LOG_INFO("server.loading", "正在加载 _属性调整_宝箱...");
        uint32 oldMSTime = getMSTime();
        aa_items.clear();
        QueryResult result = WorldDatabase.Query("SELECT * FROM _属性调整_宝箱");
        if (result) {
            do
            {
                Field* fields = result->Fetch();
                AA_Item conf;
                conf.id = fields[1].GetUInt32();
                conf.nonsuch_group = fields[2].GetUInt32();
                conf.lootid = fields[3].GetString();
                conf.lootid1 = fields[4].GetString();
                conf.old_loot = fields[5].GetString();
                conf.reward = fields[6].GetUInt32();
                conf.reward_chance = fields[7].GetFloat();
                conf.reward_dz = fields[8].GetUInt32();
                conf.reward_dz_chance = fields[9].GetFloat();
                conf.reward_dw = fields[10].GetUInt32();
                conf.reward_dw_chance = fields[11].GetFloat();
                conf.tanchuang = fields[12].GetUInt32();
                conf.notice = fields[13].GetUInt32();
                aa_items[conf.id] = conf;
            } while (result->NextRow());
            TC_LOG_INFO("server.loading", ">> 成功加载 {}条 _属性调整_宝箱 用时 {} 毫秒", (unsigned long)aa_items.size(), GetMSTimeDiffToNow(oldMSTime));
        }
    }
    {
        TC_LOG_INFO("server.loading", "正在加载 _属性调整_按ID调整物体...");
        uint32 oldMSTime = getMSTime();
        aa_object_ids.clear();
        QueryResult result = WorldDatabase.Query("SELECT * FROM _属性调整_按ID调整物体");
        if (result) {
            do {
                Field* fields = result->Fetch();
                AA_Object_Id conf;
                conf.entry = fields[1].GetUInt32();
                conf.nanduid = fields[2].GetUInt32();
                conf.zus = fields[3].GetString();
                aa_object_ids[conf.entry][conf.nanduid] = conf;
            } while (result->NextRow());
            TC_LOG_INFO("server.loading", ">> 成功加载 {}条 _属性调整_按ID调整物体 用时 {} 毫秒", (unsigned long)aa_object_ids.size(), GetMSTimeDiffToNow(oldMSTime));
        }
    }
    {
        TC_LOG_INFO("server.loading", "正在加载 _属性调整_地图...");
        uint32 oldMSTime = getMSTime();
        aa_map_player_confs.clear();
        aa_map_player_conf_areas.clear();
        aa_map_player_conf_zones.clear();
        aa_map_player_conf_maps.clear();
        aa_map_player_conf_alls.clear();
        aa_map_player_conf_yewai_areas.clear();
        aa_map_player_conf_yewai_zones.clear();
        aa_map_player_conf_yewai_maps.clear();
        aa_map_player_conf_yewai_all_id = 0;
        QueryResult result = WorldDatabase.Query("SELECT * FROM _属性调整_地图 ORDER BY id");
        if (result) {
            do
            {
                Field* fields = result->Fetch();
                AA_Map_Player_Conf conf;
                int i = 1;
                conf.id = fields[i++].GetUInt32();
                conf.nandumoshi = fields[i++].GetString();
                conf.nanduid = fields[i++].GetUInt32();
                conf.playercount = fields[i++].GetUInt32();
                conf.map = fields[i++].GetInt32();
                conf.zone = fields[i++].GetInt32();
                conf.area = fields[i++].GetInt32();
                conf.need = fields[i++].GetUInt32();
                conf.PvpType = fields[i++].GetString();
                conf.isMaxHealth = fields[i++].GetUInt32();
                conf.namePre = fields[i++].GetString();
                conf.nameSuf = fields[i++].GetString();
                conf.GroupOnOff = fields[i++].GetInt32();
                conf.FlyOnOff = fields[i++].GetInt32();
                conf.jyjineng = fields[i++].GetString();
                conf.jywupin = fields[i++].GetString();
                conf.hdguanghuan = fields[i++].GetString();
                conf.zuoqis = fields[i++].GetString();
                conf.visibility_dist = fields[i++].GetFloat();
                conf.zuobiao_lm = fields[i++].GetString();
                conf.zuobiao_bl = fields[i++].GetString();
                conf.dietime = fields[i++].GetUInt32();
                conf.xianzhitime = fields[i++].GetUInt32();
                conf.jindu_exp = fields[i++].GetString();
                conf.jindu_reward = fields[i++].GetString();
                conf.jindu_reward_duixiang = fields[i++].GetString();
                conf.jindu_notice = fields[i++].GetUInt32();
                conf.notice_jr = fields[i++].GetUInt32();
                aa_map_player_confs[conf.id] = conf;
                if (conf.area != -1) {
                    aaCenter.aa_map_player_conf_areas[conf.area][conf.nandumoshi][conf.nanduid][conf.playercount] = conf.id;
                    aa_map_player_conf_yewai_areas[conf.area] = conf.id;
                }
                if (conf.zone != -1) {
                    aaCenter.aa_map_player_conf_zones[conf.zone][conf.nandumoshi][conf.nanduid][conf.playercount] = conf.id;
                    aa_map_player_conf_yewai_zones[conf.zone] = conf.id;
                }
                if (conf.map != -1) {
                    aaCenter.aa_map_player_conf_maps[conf.map][conf.nandumoshi][conf.nanduid][conf.playercount] = conf.id;
                    aa_map_player_conf_yewai_maps[conf.map] = conf.id;
                }
                if (conf.area == -1 && conf.zone == -1 && conf.map == -1) {
                    aaCenter.aa_map_player_conf_alls[conf.nandumoshi][conf.nanduid][conf.playercount] = conf.id;
                    aa_map_player_conf_yewai_all_id = conf.id;
                }
            } while (result->NextRow());
            TC_LOG_INFO("server.loading", ">> 成功加载 {}条 _属性调整_地图 用时 {} 毫秒", (unsigned long)aa_map_player_confs.size(), GetMSTimeDiffToNow(oldMSTime));
        }
    }

    {
        TC_LOG_INFO("server.loading", "正在加载 _活动_战场...");
        uint32 oldMSTime = getMSTime();
        aa_battleground_confs.clear();
        QueryResult result = WorldDatabase.Query("SELECT * FROM _活动_战场 ORDER BY id");
        if (result) {
            do
            {
                Field* fields = result->Fetch();
                AA_Battleground_Conf conf;
                int i = 1;
                conf.id = fields[i++].GetUInt32();
                conf.name = fields[i++].GetString();
                conf.player_count = fields[i++].GetUInt32();
                conf.is_open = fields[i++].GetUInt32();
                conf.is_randomzy = fields[i++].GetUInt32();
                conf.join_need = fields[i++].GetUInt32();
                conf.alert_jiange = fields[i++].GetUInt32();
                conf.event_id = fields[i++].GetUInt32();
                conf.stop_time = fields[i++].GetUInt32();
                conf.max_time = fields[i++].GetUInt32();
                conf.Reqkillcount = fields[i++].GetUInt32();
                conf.ReqkillCreature_lm = fields[i++].GetUInt32();
                conf.ReqkillCreature_bl = fields[i++].GetUInt32();
                conf.reward_damage = fields[i++].GetUInt32();
                conf.reward_healing = fields[i++].GetUInt32();
                conf.kill_reward = fields[i++].GetUInt32();
                conf.die_reward = fields[i++].GetUInt32();
                conf.win_reward = fields[i++].GetUInt32();
                conf.lose_reward = fields[i++].GetUInt32();
                aa_battleground_confs[conf.id][conf.stop_time] = conf;
            } while (result->NextRow());
            TC_LOG_INFO("server.loading", ">> _活动_战场 加载成功{}条 ,用时 {} 毫秒", (unsigned  long)aa_battleground_confs.size(), GetMSTimeDiffToNow(oldMSTime));
        }
    }

    {
        TC_LOG_INFO("server.loading", "正在加载 _模板_需求...");
        uint32 oldMSTime = getMSTime();
        aa_needs.clear();
        QueryResult result = WorldDatabase.Query("SELECT * FROM _模板_需求 ORDER BY id");
        if (result) {
            do {
                Field* fields = result->Fetch();
                AA_Need_Conf conf;
                conf.id = fields[1].GetUInt32();
                conf.level = fields[2].GetUInt32();
                conf.jxlevel = fields[3].GetUInt32();
                conf.dqlevel = fields[4].GetUInt32();
                conf.dflevel = fields[5].GetUInt32();
                conf.viplevel = fields[6].GetUInt32();
                conf.jifen_all = fields[7].GetUInt32();
                conf.money = fields[8].GetUInt32();
                conf.paodian = fields[9].GetUInt32();
                conf.mobi = fields[10].GetUInt32();
                conf.jifen = fields[11].GetUInt32();
                conf.battlecore = fields[12].GetUInt32();
                conf.honorcore = fields[13].GetUInt32();
                conf.deplete = fields[15].GetUInt32();
                conf.items = fields[16].GetString();
                conf.level_item_ItemLevel = fields[17].GetUInt32();
                conf.level_item_Quality = fields[18].GetUInt32();
                conf.level_item_jd = fields[19].GetUInt32();
                conf.level_item_cz = fields[20].GetUInt32();
                conf.level_item_qh = fields[21].GetUInt32();
                conf.level_item_jxsx = fields[22].GetUInt32();
                conf.level_item_jxjn = fields[23].GetUInt32();
                conf.level_pet_jh = fields[24].GetUInt32();
                conf.level_pet_qh = fields[25].GetUInt32();
                conf.level_pet_jx = fields[26].GetUInt32();
                conf.quests = fields[27].GetString();
                conf.achievements = fields[28].GetString();
                conf.spells = fields[29].GetString();
                conf.buffs = fields[30].GetString();
                conf.gender = fields[31].GetUInt32();
                conf.team = fields[32].GetUInt8();
                conf.race = fields[33].GetUInt32();
                conf.class1 = fields[34].GetUInt32();
                conf.guild = fields[35].GetUInt32();
                conf.mapid = fields[36].GetInt32();
                conf.areaid = fields[37].GetInt32();
                conf.zoneid = fields[38].GetInt32();
                conf.diy_guid = fields[39].GetString();
                conf.diy_account = fields[40].GetString();
                conf.diy_system = fields[41].GetString();
                conf.game_event = fields[42].GetString();
                conf.group_count = fields[43].GetUInt32();
                conf.group_duizhang = fields[44].GetUInt32();
                conf.is_yongbing = fields[45].GetUInt32();
                conf.notice = fields[46].GetUInt32();
                conf.text = fields[47].GetString();
                aa_needs[conf.id] = conf;
            } while (result->NextRow());
            TC_LOG_INFO("server.loading", ">> 成功加载 {}条 _模板_需求 用时 {} 毫秒", (unsigned long)aa_needs.size(), GetMSTimeDiffToNow(oldMSTime));
        }
    }

    {
        TC_LOG_INFO("server.loading", "正在加载 _模板_奖励...");
        uint32 oldMSTime = getMSTime();
        aa_rewards.clear();
        QueryResult result = WorldDatabase.Query("SELECT * FROM _模板_奖励 ORDER BY id");
        if (result) {
            do {
                Field* fields = result->Fetch();
                AA_Reward_Conf conf;
                int i = 1;
                conf.id = fields[i++].GetUInt32();
                conf.chance = fields[i++].GetUInt32();
                conf.exp = fields[i++].GetUInt32();
                conf.jxexp = fields[i++].GetUInt32();
                conf.dqexp = fields[i++].GetUInt32();
                conf.dfexp = fields[i++].GetUInt32();
                conf.czexp = fields[i++].GetUInt32();
                conf.money = fields[i++].GetUInt32();
                conf.paodian = fields[i++].GetUInt32();
                conf.mobi = fields[i++].GetUInt32();
                conf.jifen = fields[i++].GetUInt32();
                conf.battlecore = fields[i++].GetUInt32();
                conf.honorcore = fields[i++].GetUInt32();
                conf.items = fields[i++].GetString();
                conf.spells = fields[i++].GetString();
                conf.buffs = fields[i++].GetString();
                conf.teleport_id = fields[i++].GetInt32();
                conf.vip_level = fields[i++].GetUInt32();
                conf.tianfu = fields[i++].GetUInt32();
                conf.jxds = fields[i++].GetUInt32();
                conf.dqds = fields[i++].GetUInt32();
                conf.dfds = fields[i++].GetUInt32();
                conf.touxian = fields[i++].GetUInt32();
                conf.gm = fields[i++].GetString();
                conf.diy_guid = fields[i++].GetString();
                conf.diy_account = fields[i++].GetString();
                conf.diy_system = fields[i++].GetString();
                conf.game_event = fields[i++].GetString();
                conf.text = fields[i++].GetString();
                aa_rewards[conf.id] = conf;

                AA_Need_Conf n_conf;
                n_conf.id = conf.id + 10000000;
                //                n_conf.level = fields[2].GetUInt32();
                //                n_conf.jxlevel = fields[3].GetUInt32();
                //                n_conf.dqlevel = fields[4].GetUInt32();
                //                n_conf.dflevel = fields[5].GetUInt32();
                //                n_conf.viplevel = fields[6].GetUInt32();
                //                n_conf.jifen_all = fields[7].GetUInt32();
                n_conf.money = conf.money;
                n_conf.paodian = conf.paodian;
                n_conf.mobi = conf.mobi;
                n_conf.jifen = conf.jifen;
                n_conf.battlecore = conf.battlecore;
                n_conf.honorcore = conf.honorcore;
                //                n_conf.deplete = fields[14].GetUInt32();
                n_conf.items = conf.items;
                //                n_conf.level_item = fields[25].GetUInt32();
                //                n_conf.level_up = fields[26].GetUInt32();
                //                n_conf.level_cz = fields[27].GetUInt32();
                //                n_conf.level_pet = fields[28].GetUInt32();
                //                n_conf.level_pet_jh = fields[29].GetUInt32();
                //                n_conf.quests = fields[30].GetString();
                //                n_conf.achievements = fields[31].GetString();
                //                n_conf.spells = fields[32].GetString();
                //                n_conf.buffs = fields[33].GetString();
                //                n_conf.gender = fields[34].GetUInt32();
                //                n_conf.team = fields[35].GetUInt8();
                //                n_conf.race = fields[36].GetUInt32();
                //                n_conf.class1 = fields[37].GetUInt32();
                //                n_conf.guild = fields[38].GetUInt32();
                //                n_conf.mapid = fields[39].GetInt32();
                //                n_conf.areaid = fields[40].GetInt32();
                //                n_conf.zoneid = fields[41].GetInt32();
                //                n_conf.text = fields[42].GetString();
                aa_needs[n_conf.id] = n_conf;
            } while (result->NextRow());
            TC_LOG_INFO("server.loading", ">> 成功加载 {}条 _模板_奖励 用时 {} 毫秒", (unsigned long)aa_rewards.size(), GetMSTimeDiffToNow(oldMSTime));
        }
    }

    {
        TC_LOG_INFO("server.loading", "正在加载 _模板_弹窗...");
        uint32 oldMSTime = getMSTime();
        aa_event_confs.clear();
        QueryResult result = WorldDatabase.Query("SELECT * FROM _模板_弹窗 ORDER BY id");
        if (result) {
            do {
                Field* fields = result->Fetch();
                AA_Event_Conf conf;
                conf.id = fields[1].GetUInt32();
                conf.chance = fields[2].GetUInt32();
                conf.target = fields[3].GetUInt32();
                conf.need = fields[4].GetUInt32();
                conf.gm = fields[5].GetString();
                conf.notice = fields[6].GetUInt32();
                conf.done_need = fields[7].GetUInt32();
                conf.done_gm = fields[8].GetString();
                conf.done_notice = fields[9].GetUInt32();
                conf.title = fields[10].GetString();
                conf.text = fields[11].GetString();
                aa_event_confs[conf.id] = conf;
            } while (result->NextRow());
            TC_LOG_INFO("server.loading", ">> 成功加载 {}条 _模板_弹窗 用时 {} 毫秒", (unsigned long)aa_event_confs.size(), GetMSTimeDiffToNow(oldMSTime));
        }
    }
    {
        TC_LOG_INFO("server.loading", "正在加载 _事件_触发方式_在地图中发生动作...");
        uint32 oldMSTime = getMSTime();
        aa_event_maps.clear();
        QueryResult result = WorldDatabase.Query("SELECT * FROM _事件_触发方式_在地图中发生动作");
        if (result) {
            do {
                Field* fields = result->Fetch();
                AA_Event_Map conf;
                conf.id = fields[1].GetUInt32();
                conf.type = fields[2].GetString();
                conf.value = fields[3].GetInt32();
                conf.mapid = fields[4].GetInt32();
                conf.zoneid = fields[5].GetInt32();
                conf.areaid = fields[6].GetInt32();
                conf.need = fields[7].GetUInt32();
                conf.gm = fields[8].GetString();
                aa_event_maps[conf.type].push_back(conf);
            } while (result->NextRow());
            TC_LOG_INFO("server.loading", ">> 成功加载 {}条 _事件_触发方式_在地图中发生动作 用时 {} 毫秒", (unsigned long)aa_event_maps.size(), GetMSTimeDiffToNow(oldMSTime));
        }
    }
    {
        TC_LOG_INFO("server.loading", "正在加载 _事件_触发方式_累计在线...");
        uint32 oldMSTime = getMSTime();
        aa_event_playtimes.clear();
        QueryResult result = WorldDatabase.Query("SELECT * FROM _事件_触发方式_累计在线 ORDER BY 累计时间");
        if (result) {
            do {
                Field* fields = result->Fetch();
                AA_Event_Playtime conf;
                conf.time = fields[1].GetUInt32();
                conf.gm = fields[2].GetString();
                aa_event_playtimes.push_back(conf);
            } while (result->NextRow());
            TC_LOG_INFO("server.loading", ">> 成功加载 {}条 _事件_触发方式_累计在线 用时 {} 毫秒", (unsigned long)aa_event_playtimes.size(), GetMSTimeDiffToNow(oldMSTime));
        }
    }
    {
        TC_LOG_INFO("server.loading", "正在加载 _事件_触发方式_game_event...");
        uint32 oldMSTime = getMSTime();
        aa_event_gameevents.clear();
        QueryResult result = WorldDatabase.Query("SELECT * FROM _事件_触发方式_game_event");
        if (result) {
            do {
                Field* fields = result->Fetch();
                AA_Event_GameEvent conf;
                conf.entry = fields[1].GetUInt32();
                conf.target = fields[2].GetUInt32();
                conf.gm1 = fields[3].GetString();
                conf.gm2 = fields[4].GetString();
                aa_event_gameevents[conf.entry] = conf;
            } while (result->NextRow());
            TC_LOG_INFO("server.loading", ">> 成功加载 {}条 _事件_触发方式_game_event 用时 {} 毫秒", (unsigned long)aa_event_gameevents.size(), GetMSTimeDiffToNow(oldMSTime));
        }
    }
    {
        TC_LOG_INFO("server.loading", "正在加载 _属性调整_职业...");
        uint32 oldMSTime = getMSTime();
        aa_player_stats_confs.clear();
        aa_player_stats_conf_areas.clear();
        aa_player_stats_conf_zones.clear();
        aa_player_stats_conf_maps.clear();
        aa_player_stats_conf_alls.clear();
        QueryResult result = WorldDatabase.Query("SELECT * FROM _属性调整_职业 ORDER BY class");
        if (result) {
            do {
                Field* fields = result->Fetch();
                AA_Player_Stats_Conf conf;
                conf.id = fields[1].GetUInt32();
                conf.class1 = fields[2].GetUInt8();
                conf.map = fields[3].GetInt32();
                conf.zone = fields[4].GetInt32();
                conf.area = fields[5].GetInt32();
                conf.liliang = fields[6].GetUInt32();
                conf.liliangbl = fields[7].GetUInt32();
                conf.minjie = fields[8].GetUInt32();
                conf.minjiebl = fields[9].GetUInt32();
                conf.zhili = fields[10].GetUInt32();
                conf.zhilibl = fields[11].GetUInt32();
                conf.jingshen = fields[12].GetUInt32();
                conf.jingshenbl = fields[13].GetUInt32();
                conf.naili = fields[14].GetUInt32();
                conf.nailibl = fields[15].GetUInt32();
                conf.faqiang = fields[16].GetUInt32();
                conf.faqiangbl = fields[17].GetUInt32();
                conf.gongqiang = fields[18].GetUInt32();
                conf.gongqiangbl = fields[19].GetUInt32();
                conf.zhiliao = fields[20].GetUInt32();
                conf.zhiliaobl = fields[21].GetUInt32();
                conf.shensheng = fields[22].GetUInt32();
                conf.shenshengbl = fields[23].GetUInt32();
                conf.huoyan = fields[24].GetUInt32();
                conf.huoyanbl = fields[25].GetUInt32();
                conf.ziran = fields[26].GetUInt32();
                conf.ziranbl = fields[27].GetUInt32();
                conf.bingshuang = fields[28].GetUInt32();
                conf.bingshuangbl = fields[29].GetUInt32();
                conf.anying = fields[30].GetUInt32();
                conf.anyingbl = fields[31].GetUInt32();
                conf.aoshu = fields[32].GetUInt32();
                conf.aoshubl = fields[33].GetUInt32();
                conf.blocksx = fields[34].GetUInt32();
                conf.parrysx = fields[35].GetUInt32();
                conf.dodgesx = fields[36].GetUInt32();
                conf.bjsx = fields[37].GetUInt32();
                conf.renxingsx = fields[38].GetUInt32();
                conf.renxingbl = fields[39].GetUInt32();
                conf.hujiasx = fields[40].GetUInt32();
                conf.hujiabl = fields[41].GetUInt32();
                conf.jzsx = fields[42].GetUInt32();
                conf.jzbl = fields[43].GetUInt32();
                conf.hpsx = fields[44].GetUInt32();
                conf.hpbl = fields[45].GetUInt32();
                conf.jssx = fields[46].GetUInt32();
                conf.jsbl = fields[47].GetUInt32();
                conf.ptshsx = fields[48].GetUInt32();
                conf.ptshbl = fields[49].GetUInt32();
                conf.cptshbl = fields[50].GetUInt32();
                conf.jnshsx = fields[51].GetUInt32();
                conf.jnshbl = fields[52].GetUInt32();
                conf.cjnshbl = fields[53].GetUInt32();
                conf.zlshsx = fields[54].GetUInt32();
                conf.zlshbl = fields[55].GetUInt32();
                conf.czlshbl = fields[56].GetUInt32();
                conf.jianshangpvp = fields[57].GetInt32();
                conf.jianshangpve = fields[58].GetInt32();
                conf.lltofq = fields[59].GetFloat();// 力量转法强，
                conf.mjtofq = fields[60].GetFloat();// 敏捷转法强，
                conf.nltofq = fields[61].GetFloat();// 耐力转法强，
                conf.zltofq = fields[62].GetFloat();// 智力转法强，
                conf.jstofq = fields[63].GetFloat();// 精神转法强，
                conf.lltogq = fields[64].GetFloat();// 力量转攻强，
                conf.mjtogq = fields[65].GetFloat();// 敏捷转攻强，
                conf.nltogq = fields[66].GetFloat();// 耐力转攻强，
                conf.zltogq = fields[67].GetFloat();// 智力转攻强，
                conf.jstogq = fields[68].GetFloat();// 精神转攻强，
                aa_player_stats_confs[conf.id] = conf;
                if (conf.area != -1) {
                    aa_player_stats_conf_areas[conf.area][conf.class1] = conf.id;
                }
                if (conf.zone != -1) {
                    aa_player_stats_conf_zones[conf.area][conf.class1] = conf.id;
                }
                if (conf.map != -1) {
                    aa_player_stats_conf_maps[conf.area][conf.class1] = conf.id;
                }
                if (conf.area == -1 && conf.zone == -1 && conf.map == -1) {
                    aa_player_stats_conf_alls[conf.class1] = conf.id;
                }
            } while (result->NextRow());
            TC_LOG_INFO("server.loading", ">> 成功加载 {}条 _属性调整_职业 用时 {} 毫秒", (unsigned long)aa_player_stats_confs.size(), GetMSTimeDiffToNow(oldMSTime));
        }
    }
    {
        TC_LOG_INFO("server.loading", "正在加载 _物品_回收...");
        uint32 oldMSTime = getMSTime();
        aa_huishou_desc.clear();
        aa_huishou_confs.clear();
        aa_huishou_entrys.clear();
        QueryResult result = WorldDatabase.Query("SELECT * FROM _物品_回收 ORDER BY 优先级 ASC");
        if (result) {
            do {
                Field* fields = result->Fetch();
                AA_Huishou_Conf conf;
                conf.id = fields[1].GetUInt32();
                conf.youxianji = fields[2].GetUInt32();
                conf.itemid = fields[3].GetUInt32();
                conf.need = fields[4].GetUInt32();
                conf.reward = fields[5].GetUInt32();
                aa_huishou_confs[conf.id] = conf;
                if (conf.itemid > 0) {
                    aa_huishou_entrys[conf.itemid] = conf.id;
                }
                else {
                    aa_huishou_desc.push_back(conf.id);
                }
            } while (result->NextRow());
            TC_LOG_INFO("server.loading", ">> 成功加载 {}条 _物品_回收 用时 {} 毫秒", (unsigned long)aa_huishou_confs.size(), GetMSTimeDiffToNow(oldMSTime));
        }
    }
    {
        TC_LOG_INFO("server.loading", "正在加载 _自定义Ai...");
        uint32 oldMSTime = getMSTime();
        aa_ais.clear();
        aa_ai_zus.clear();
        QueryResult result = WorldDatabase.Query("SELECT * FROM _自定义Ai ORDER BY id");
        if (result) {
            do {
                Field* fields = result->Fetch();
                AA_Ai conf;
                conf.id = fields[1].GetUInt32();
                conf.zu = fields[2].GetUInt32();
                conf.event_chance = fields[3].GetFloat();
                conf.event_cooldown = fields[4].GetUInt32();
                conf.gg_zu = fields[5].GetUInt32();
                conf.gg_cooldown = fields[6].GetUInt32();
                conf.event_type = fields[7].GetString();
                conf.event_param1 = fields[8].GetInt32();
                conf.event_param2 = fields[9].GetInt32();
                conf.event_param3 = fields[10].GetUInt32();
                conf.event_param4 = fields[11].GetUInt32();
                conf.event_param5 = fields[12].GetString();
                conf.action_target = fields[13].GetString();
                conf.action_target_ids = fields[14].GetString();
                conf.action_type = fields[15].GetString();
                conf.action_param1 = fields[16].GetInt32();
                conf.action_param2 = fields[17].GetInt32();
                conf.action_param3 = fields[18].GetInt32();
                conf.action_param4 = fields[19].GetInt8();
                conf.action_param5 = fields[20].GetString();
                conf.notice = fields[21].GetUInt32();
                aa_ais[conf.id] = conf;
                aa_ai_zus[conf.zu].insert(conf.id);
            } while (result->NextRow());
            TC_LOG_INFO("server.loading", ">> 成功加载 {}条 _自定义Ai 用时 {} 毫秒", (unsigned long)aa_ais.size(), GetMSTimeDiffToNow(oldMSTime));
        }
    }
    {
        TC_LOG_INFO("server.loading", "正在加载 _自定义Ai_地图带Ai...");
        uint32 oldMSTime = getMSTime();
        aa_ai_maps.clear();
        QueryResult result = WorldDatabase.Query("SELECT * FROM _自定义Ai_地图带Ai");
        if (result) {
            do {
                Field* fields = result->Fetch();
                AA_Ai_Map conf;
                conf.target = fields[1].GetString();
                conf.map = fields[2].GetInt32();
                conf.zone = fields[3].GetInt32();
                conf.area = fields[4].GetInt32();
                conf.ais = fields[5].GetString();
                aa_ai_maps.push_back(conf);
            } while (result->NextRow());
            TC_LOG_INFO("server.loading", ">> 成功加载 {}条 _自定义Ai_地图带Ai 用时 {} 毫秒", (unsigned long)aa_ai_maps.size(), GetMSTimeDiffToNow(oldMSTime));
        }
    }
    {
        TC_LOG_INFO("server.loading", "正在加载 _自定义Ai_物品带Ai...");
        uint32 oldMSTime = getMSTime();
        aa_ai_items.clear();
        QueryResult result = WorldDatabase.Query("SELECT * FROM _自定义Ai_物品带Ai");
        if (result) {
            do {
                Field* fields = result->Fetch();
                AA_Ai_Item conf;
                conf.id = fields[1].GetUInt32();
                conf.ais = fields[2].GetString();
                aa_ai_items[conf.id] = conf;
            } while (result->NextRow());
            TC_LOG_INFO("server.loading", ">> 成功加载 {}条 _自定义Ai_物品带Ai 用时 {} 毫秒", (unsigned long)aa_ai_items.size(), GetMSTimeDiffToNow(oldMSTime));
        }
    }
    {
        TC_LOG_INFO("server.loading", "正在加载 _自定义Ai_生物带Ai...");
        uint32 oldMSTime = getMSTime();
        aa_ai_creatures.clear();
        QueryResult result = WorldDatabase.Query("SELECT * FROM _自定义Ai_生物带Ai");
        if (result) {
            do {
                Field* fields = result->Fetch();
                AA_Ai_Creature conf;
                conf.id = fields[1].GetUInt32();
                conf.ais = fields[2].GetString();
                aa_ai_creatures[conf.id] = conf;
            } while (result->NextRow());
            TC_LOG_INFO("server.loading", ">> 成功加载 {}条 _自定义Ai_生物带Ai 用时 {} 毫秒", (unsigned long)aa_ai_creatures.size(), GetMSTimeDiffToNow(oldMSTime));
        }
    }
    {
        TC_LOG_INFO("server.loading", "正在加载 _自定义Ai_光环带Ai...");
        uint32 oldMSTime = getMSTime();
        aa_ai_spells.clear();
        QueryResult result = WorldDatabase.Query("SELECT * FROM _自定义Ai_光环带Ai");
        if (result) {
            do {
                Field* fields = result->Fetch();
                AA_Ai_Spell conf;
                conf.id = fields[1].GetUInt32();
                conf.ais = fields[2].GetString();
                aa_ai_spells[conf.id] = conf;
            } while (result->NextRow());
            TC_LOG_INFO("server.loading", ">> 成功加载 {}条 _自定义Ai_光环带Ai 用时 {} 毫秒", (unsigned long)aa_ai_spells.size(), GetMSTimeDiffToNow(oldMSTime));
        }
    }
    {
        TC_LOG_INFO("server.loading", "正在加载 _自定义ai_学习技能带ai...");
        uint32 oldMSTime = getMSTime();
        aa_ai_spell_learns.clear();
        QueryResult result = WorldDatabase.Query("SELECT * FROM _自定义ai_学习技能带ai");
        if (result) {
            do {
                Field* fields = result->Fetch();
                AA_Ai_Spell_Learn conf;
                conf.id = fields[1].GetUInt32();
                conf.ais = fields[2].GetString();
                aa_ai_spell_learns[conf.id] = conf;
            } while (result->NextRow());
            TC_LOG_INFO("server.loading", ">> 成功加载 {}条 _自定义ai_学习技能带ai 用时 {} 毫秒", (unsigned long)aa_ai_spell_learns.size(), GetMSTimeDiffToNow(oldMSTime));
        }
    }
    {
        TC_LOG_INFO("server.loading", "正在加载 _自定义ai_物品技能带ai...");
        uint32 oldMSTime = getMSTime();
        aa_ai_spell_items.clear();
        QueryResult result = WorldDatabase.Query("SELECT * FROM _自定义ai_物品技能带ai");
        if (result) {
            do {
                Field* fields = result->Fetch();
                AA_Ai_Spell_Item conf;
                conf.id = fields[1].GetUInt32();
                conf.ais = fields[2].GetString();
                aa_ai_spell_items[conf.id] = conf;
            } while (result->NextRow());
            TC_LOG_INFO("server.loading", ">> 成功加载 {}条 _自定义ai_物品技能带ai 用时 {} 毫秒", (unsigned long)aa_ai_spell_items.size(), GetMSTimeDiffToNow(oldMSTime));
        }
    }
    {
        TC_LOG_INFO("server.loading", "正在加载 _自定义Ai_宠物带Ai...");
        uint32 oldMSTime = getMSTime();
        aa_ai_pets.clear();
        QueryResult result = WorldDatabase.Query("SELECT * FROM _自定义Ai_宠物带Ai");
        if (result) {
            do {
                Field* fields = result->Fetch();
                AA_Ai_Pet conf;
                conf.id = fields[1].GetUInt32();
                conf.ais = fields[2].GetString();
                aa_ai_pets[conf.id] = conf;
            } while (result->NextRow());
            TC_LOG_INFO("server.loading", ">> 成功加载 {}条 _自定义Ai_宠物带Ai 用时 {} 毫秒", (unsigned long)aa_ai_pets.size(), GetMSTimeDiffToNow(oldMSTime));
        }
    }
    {
        TC_LOG_INFO("server.loading", "正在加载 _客户端_图标...");

        uint32 oldMSTime = getMSTime();

        aa_desktop_confs.clear();                              // need for reload case
        aa_desktops.clear();

        //                                               0      1       2     3
        QueryResult result = WorldDatabase.Query("SELECT * FROM _客户端_图标 ORDER BY id");
        if (result) {
            do {
                Field* fields = result->Fetch();

                AA_Desktop_Conf conf;
                conf.id = fields[1].GetUInt32();
                conf.type = fields[2].GetUInt32();
                conf.open = fields[3].GetUInt32();
                conf.title = fields[4].GetString();
                conf.icon_path = fields[5].GetString();
                conf.icon_spell = fields[6].GetUInt32();
                conf.icon_item = fields[7].GetUInt32();
                conf.gm = fields[8].GetString();
                conf.www = fields[9].GetString();
                aa_desktops.push_back(conf.id);
                aa_desktop_confs[conf.id] = conf;
            } while (result->NextRow());

            TC_LOG_INFO("server.loading", ">> 成功加载 {}条 _客户端_图标 用时 {} 毫秒", (unsigned long)aa_desktop_confs.size(), GetMSTimeDiffToNow(oldMSTime));
        }
    }
    {
        TC_LOG_INFO("server.loading", "正在加载 _奖励_等级...");

        uint32 oldMSTime = getMSTime();

        aa_reward_levels.clear();
        aa_reward_level_confs.clear();                              // need for reload case

        //                                               0      1       2     3
        QueryResult result = WorldDatabase.Query("SELECT * FROM _奖励_等级 ORDER BY level");
        if (result) {
            do {
                Field* fields = result->Fetch();

                AA_Reward_Level_Conf conf;
                conf.level = fields[1].GetUInt32();
                conf.type = fields[2].GetUInt32();
                conf.reward = fields[3].GetUInt32();
                conf.count = fields[4].GetUInt32();
                conf.notice = fields[5].GetUInt32();
                conf.text = fields[6].GetString();
                aa_reward_levels.push_back(conf.level);
                aa_reward_level_confs[conf.level] = conf;
            } while (result->NextRow());

            TC_LOG_INFO("server.loading", ">> 成功加载 {}条 _奖励_等级 用时 {} 毫秒", (unsigned long)aa_reward_level_confs.size(), GetMSTimeDiffToNow(oldMSTime));
        }
    }
    {
        TC_LOG_INFO("server.loading", "正在加载 _奖励_首充...");

        uint32 oldMSTime = getMSTime();

        aa_reward_shouchongs.clear();
        aa_reward_shouchong_confs.clear();                              // need for reload case

        //                                               0      1       2     3
        QueryResult result = WorldDatabase.Query("SELECT * FROM _奖励_首充 ORDER BY id");
        if (result) {
            do {
                Field* fields = result->Fetch();

                AA_Reward_Shouchong_Conf conf;
                conf.id = fields[1].GetUInt32();
                conf.jifen = fields[2].GetUInt32();
                conf.reward = fields[3].GetUInt32();
                conf.notice = fields[4].GetUInt32();
                conf.text = fields[5].GetString();
                aa_reward_shouchongs.push_back(conf.id);
                aa_reward_shouchong_confs[conf.id] = conf;
            } while (result->NextRow());

            TC_LOG_INFO("server.loading", ">> 成功加载 {}条 _奖励_首充 用时 {} 毫秒", (unsigned long)aa_reward_shouchong_confs.size(), GetMSTimeDiffToNow(oldMSTime));
        }
    }
    {
        TC_LOG_INFO("server.loading", "正在加载 _奖励_理财...");

        uint32 oldMSTime = getMSTime();

        aa_reward_licais.clear();
        aa_reward_licai_confs.clear();                              // need for reload case

        //                                               0      1       2     3
        QueryResult result = WorldDatabase.Query("SELECT * FROM _奖励_理财 ORDER BY id");
        if (result) {
            do {
                Field* fields = result->Fetch();

                AA_Reward_Licai_Conf conf;
                conf.id = fields[1].GetUInt32();
                conf.need = fields[2].GetUInt32();
                conf.reward = fields[3].GetUInt32();
                conf.day = fields[4].GetUInt32();
                conf.notice = fields[5].GetUInt32();
                conf.text = fields[6].GetString();
                aa_reward_licais.push_back(conf.id);
                aa_reward_licai_confs[conf.id] = conf;
            } while (result->NextRow());

            TC_LOG_INFO("server.loading", ">> 成功加载 {}条 _奖励_理财 用时 {} 毫秒", (unsigned long)aa_reward_licai_confs.size(), GetMSTimeDiffToNow(oldMSTime));
        }
    }
    {
        TC_LOG_INFO("server.loading", "正在加载 _奖励_累充...");

        uint32 oldMSTime = getMSTime();

        aa_reward_leijis.clear();
        aa_reward_leiji_confs.clear();                              // need for reload case

        //                                               0      1       2     3
        QueryResult result = WorldDatabase.Query("SELECT * FROM _奖励_累充 ORDER BY jifen");
        if (result) {
            do {
                Field* fields = result->Fetch();

                AA_Reward_Leiji_Conf conf;
                conf.jifen = fields[1].GetUInt32();
                conf.reward = fields[2].GetUInt32();
                conf.notice = fields[3].GetUInt32();
                conf.text = fields[4].GetString();
                aa_reward_leijis.push_back(conf.jifen);
                aa_reward_leiji_confs[conf.jifen] = conf;
            } while (result->NextRow());

            TC_LOG_INFO("server.loading", ">> 成功加载 {}条 _奖励_累充 用时 {} 毫秒", (unsigned long)aa_reward_leiji_confs.size(), GetMSTimeDiffToNow(oldMSTime));
        }
    }
    {
        TC_LOG_INFO("server.loading", "正在加载 _奖励_签到...");
        uint32 oldMSTime = getMSTime();
        aa_reward_qiandaos.clear();
        aa_reward_qiandao_confs.clear();
        QueryResult result = WorldDatabase.Query("SELECT * FROM _奖励_签到 ORDER BY day");
        if (result) {
            do {
                Field* fields = result->Fetch();

                AA_Reward_Qiandao_Conf conf;
                conf.day = fields[1].GetUInt32();
                conf.reward = fields[2].GetUInt32();
                conf.notice = fields[3].GetUInt32();
                conf.text = fields[4].GetString();
                aa_reward_qiandaos.push_back(conf.day);
                aa_reward_qiandao_confs[conf.day] = conf;
            } while (result->NextRow());

            TC_LOG_INFO("server.loading", ">> 成功加载 {}条 _奖励_签到 用时 {} 毫秒", (unsigned long)aa_reward_qiandao_confs.size(), GetMSTimeDiffToNow(oldMSTime));
        }
    }
    {
        TC_LOG_INFO("server.loading", "正在加载 _物品_宝石...");
        uint32 oldMSTime = getMSTime();
        aa_baoshi_confs.clear();
        QueryResult result = WorldDatabase.Query("SELECT * FROM _物品_宝石 ORDER BY 物品id");
        if (result) {
            do {
                Field* fields = result->Fetch();
                AA_Baoshi_Conf conf;
                conf.itemid = fields[1].GetUInt32();
                conf.spells = fields[2].GetString();
                conf.values = fields[3].GetString();
                conf.text = fields[4].GetString();
                aa_baoshi_confs[conf.itemid] = conf;
            } while (result->NextRow());
            TC_LOG_INFO("server.loading", ">> 成功加载 {}条 _物品_宝石 用时 {} 毫秒", (unsigned long)aa_baoshi_confs.size(), GetMSTimeDiffToNow(oldMSTime));
        }
    }
    {
        TC_LOG_INFO("server.loading", "正在加载 _物品_符文...");
        uint32 oldMSTime = getMSTime();
        aa_fw_confs.clear();
        QueryResult result = WorldDatabase.Query("SELECT * FROM _物品_符文 ORDER BY 物品id");
        if (result) {
            do {
                Field* fields = result->Fetch();
                AA_Fw_Conf conf;
                conf.itemid = fields[1].GetUInt32();
                conf.class1 = fields[2].GetString();
                conf.subclass = fields[3].GetString();
                conf.inventoryType = fields[4].GetString();
                conf.spells = fields[5].GetString();
                conf.values = fields[6].GetString();
                conf.text = fields[7].GetString();
                aa_fw_confs[conf.itemid] = conf;
            } while (result->NextRow());
            TC_LOG_INFO("server.loading", ">> 成功加载 {}条 _物品_符文 用时 {} 毫秒", (unsigned long)aa_fw_confs.size(), GetMSTimeDiffToNow(oldMSTime));
        }
    }
    {
        TC_LOG_INFO("server.loading", "正在加载 _物品_符文组合...");
        uint32 oldMSTime = getMSTime();
        aa_fwzh_confs.clear();
        QueryResult result = WorldDatabase.Query("SELECT * FROM _物品_符文组合");
        if (result) {
            do {
                Field* fields = result->Fetch();
                AA_FwZh_Conf conf;
                conf.id = fields[1].GetUInt32();
                conf.items = fields[2].GetString();
                conf.class1 = fields[3].GetString();
                conf.subclass = fields[4].GetString();
                conf.inventoryType = fields[5].GetString();
                conf.spells = fields[6].GetString();
                conf.values = fields[7].GetString();
                conf.text = fields[8].GetString();
                aa_fwzh_confs[conf.id] = conf;
            } while (result->NextRow());
            TC_LOG_INFO("server.loading", ">> 成功加载 {}条 _物品_符文组合 用时 {} 毫秒", (unsigned long)aa_fwzh_confs.size(), GetMSTimeDiffToNow(oldMSTime));
        }
    }
    {
        TC_LOG_INFO("server.loading", "正在加载 _生物_伤害排行x...");
        uint32 oldMSTime = getMSTime();
        aa_boss_confs.clear();
        QueryResult result = WorldDatabase.Query("SELECT * FROM _生物_伤害排行x");
        if (result) {
            do {
                Field* fields = result->Fetch();
                AA_Boss_Conf conf;
                conf.id = fields[1].GetUInt32();
                conf.reward = fields[2].GetString();
                conf.show = fields[3].GetUInt32();
                aa_boss_confs[conf.id] = conf;
            } while (result->NextRow());
            TC_LOG_INFO("server.loading", ">> 成功加载 {}条 _生物_伤害排行x 用时 {} 毫秒", (unsigned long)aa_boss_confs.size(), GetMSTimeDiffToNow(oldMSTime));
        }
    }
    {
        TC_LOG_INFO("server.loading", "正在加载 _物品_合成...");

        uint32 oldMSTime = getMSTime();

        aa_hecheng_confs.clear();

        //                                               0      1       2     3
        QueryResult result = WorldDatabase.Query("SELECT * FROM _物品_合成");
        if (result) {
            do {
                Field* fields = result->Fetch();

                AA_Hecheng_Conf conf;
                conf.itemid = fields[1].GetUInt32();
                conf.chance = fields[2].GetFloat();
                conf.itemid1 = fields[3].GetUInt32();
                conf.need = fields[4].GetUInt32();
                conf.destroy = fields[5].GetUInt32();
                conf.is_baoliu = fields[6].GetString();
                conf.notice = fields[7].GetUInt32();
                aa_hecheng_confs[conf.itemid] = conf;

            } while (result->NextRow());

            TC_LOG_INFO("server.loading", ">> 成功加载 {}条 _物品_合成 用时 {} 毫秒", (unsigned long)aa_hecheng_confs.size(), GetMSTimeDiffToNow(oldMSTime));
        }
    }
    {
        TC_LOG_INFO("server.loading", "正在加载 _物品_移除宝石...");
        uint32 oldMSTime = getMSTime();
        aa_chaixie_confs.clear();
        QueryResult result = WorldDatabase.Query("SELECT * FROM _物品_移除宝石");
        if (result) {
            do {
                Field* fields = result->Fetch();
                AA_Chaixie_Conf conf;
                conf.itemid = fields[1].GetUInt32();
                conf.chance = fields[2].GetFloat();
                conf.need = fields[3].GetUInt32();
                conf.reward = fields[4].GetUInt32();
                conf.notice = fields[5].GetUInt32();
                aa_chaixie_confs[conf.itemid] = conf;
            } while (result->NextRow());
            TC_LOG_INFO("server.loading", ">> 成功加载 {}条 _物品_移除宝石 用时 {} 毫秒", (unsigned long)aa_chaixie_confs.size(), GetMSTimeDiffToNow(oldMSTime));
        }
    }
    {
        TC_LOG_INFO("server.loading", "正在加载 _物品_解除绑定...");
        uint32 oldMSTime = getMSTime();
        aa_jiebang_confs.clear();
        QueryResult result = WorldDatabase.Query("SELECT * FROM _物品_解除绑定");
        if (result) {
            do {
                Field* fields = result->Fetch();
                AA_Jiebang_Conf conf;
                conf.itemid = fields[1].GetUInt32();
                conf.need = fields[2].GetUInt32();
                conf.reward = fields[3].GetUInt32();
                conf.notice = fields[4].GetUInt32();
                aa_jiebang_confs[conf.itemid] = conf;
            } while (result->NextRow());
            TC_LOG_INFO("server.loading", ">> 成功加载 {}条 _物品_解除绑定 用时 {} 毫秒", (unsigned long)aa_jiebang_confs.size(), GetMSTimeDiffToNow(oldMSTime));
        }
    }
    {
        TC_LOG_INFO("server.loading", "正在加载 _物品_强化_等级券...");
        uint32 oldMSTime = getMSTime();
        aa_qianghua_items.clear();
        QueryResult result = WorldDatabase.Query("SELECT * FROM _物品_强化_等级券");
        if (result) {
            do {
                Field* fields = result->Fetch();
                AA_Qianghua_Item conf;
                conf.itemid = fields[1].GetUInt32();
                conf.need = fields[2].GetUInt32();
                conf.chance = fields[3].GetFloat();
                conf.level = fields[4].GetUInt32();
                conf.items = fields[5].GetString();
                conf.pcitems = fields[6].GetString();
                conf.notice = fields[7].GetUInt32();
                aa_qianghua_items[conf.itemid] = conf;
            } while (result->NextRow());
            TC_LOG_INFO("server.loading", ">> 成功加载 {}条 _物品_强化_等级券 用时 {} 毫秒", (unsigned long)aa_qianghua_items.size(), GetMSTimeDiffToNow(oldMSTime));
        }
    }
    {
        TC_LOG_INFO("server.loading", "正在加载 __采集_物品...");
        uint32 oldMSTime = getMSTime();
        aa_caiji_items.clear();
        aa_caiji_item_zus.clear();
        QueryResult result = WorldDatabase.Query("SELECT * FROM __采集_物品");
        if (result) {
            do {
                Field* fields = result->Fetch();
                AA_Caiji_Item conf;
                conf.text = fields[0].GetString();
                conf.id = fields[1].GetUInt32();
                conf.zu = fields[2].GetUInt32();
                conf.chance = fields[3].GetUInt32();
                conf.count = fields[4].GetUInt32();
                conf.entry = fields[5].GetUInt32();
                conf.class1 = fields[6].GetUInt32();
                conf.subclass = fields[7].GetUInt32();
                conf.name = fields[8].GetString();
                conf.displayid = fields[9].GetUInt32();
                conf.Quality = fields[10].GetUInt32();
                conf.notice = fields[11].GetUInt32();
                conf.xiangqian = fields[12].GetUInt32();
                conf.is_shuangjia = fields[13].GetUInt32();
                aa_caiji_items[conf.id] = conf;
                aa_caiji_item_zus[conf.zu].push_back(conf.id);
            } while (result->NextRow());
            TC_LOG_INFO("server.loading", ">> 成功加载 {}条 __采集_物品 用时 {} 毫秒", (unsigned long)aa_caiji_items.size(), GetMSTimeDiffToNow(oldMSTime));
        }
    }
    {
        TC_LOG_INFO("server.loading", "正在加载 __采集_坐标...");
        uint32 oldMSTime = getMSTime();
        aa_caiji_zuobiaos.clear();
        aa_caiji_zuobiao_zus.clear();
        QueryResult result = WorldDatabase.Query("SELECT * FROM __采集_坐标");
        if (result) {
            do {
                Field* fields = result->Fetch();
                AA_Caiji_Zuobiao conf;
                conf.text = fields[0].GetString();
                conf.id = fields[1].GetUInt32();
                conf.zu = fields[2].GetUInt32();
                conf.chance = fields[3].GetUInt32();
                conf.name = fields[4].GetString();
                conf.map = fields[5].GetUInt32();
                conf.zone = fields[6].GetUInt32();
                conf.area = fields[7].GetUInt32();
                conf.position_x = fields[8].GetFloat();
                conf.position_y = fields[9].GetFloat();
                conf.position_z = fields[10].GetFloat();
                conf.orientation = fields[11].GetFloat();
                conf.instanceId = fields[12].GetUInt32();
                aa_caiji_zuobiaos[conf.id] = conf;
                aa_caiji_zuobiao_zus[conf.zu].push_back(conf.id);
            } while (result->NextRow());
            TC_LOG_INFO("server.loading", ">> 成功加载 {}条 __采集_坐标 用时 {} 毫秒", (unsigned long)aa_caiji_zuobiaos.size(), GetMSTimeDiffToNow(oldMSTime));
        }
    }
    {
        TC_LOG_INFO("server.loading", "正在加载 __采集_玩家...");
        uint32 oldMSTime = getMSTime();
        aa_caiji_players.clear();
        QueryResult result = WorldDatabase.Query("SELECT * FROM __采集_玩家");
        if (result) {
            do {
                Field* fields = result->Fetch();
                AA_Caiji_Player conf;
                conf.text = fields[0].GetString();
                conf.id = fields[1].GetUInt32();
                conf.account = fields[2].GetUInt32();
                conf.guid = fields[3].GetUInt64();
                conf.zu = fields[4].GetUInt32();
                conf.chance = fields[5].GetUInt32();
                conf.name = fields[6].GetString();
                conf.ip = fields[7].GetString();
                aa_caiji_players[conf.id] = conf;
            } while (result->NextRow());
            TC_LOG_INFO("server.loading", ">> 成功加载 {}条 __采集_玩家 用时 {} 毫秒", (unsigned long)aa_caiji_players.size(), GetMSTimeDiffToNow(oldMSTime));
        }
    }
    {
        TC_LOG_INFO("server.loading", "正在加载 __采集_生物...");
        uint32 oldMSTime = getMSTime();
        aa_caiji_creatures.clear();
        aa_caiji_creature_zus.clear();
        QueryResult result = WorldDatabase.Query("SELECT * FROM __采集_生物");
        if (result) {
            do {
                Field* fields = result->Fetch();
                AA_Caiji_Creature conf;
                conf.text = fields[0].GetString();
                conf.id = fields[1].GetUInt32();
                conf.zu = fields[2].GetUInt32();
                conf.chance = fields[3].GetUInt32();
                conf.name = fields[4].GetString();
                conf.subname = fields[5].GetString();
                conf.entry = fields[6].GetInt32();
                conf.faction = fields[7].GetUInt32();
                conf.displayid = fields[8].GetUInt32();
                conf.map = fields[9].GetUInt32();
                conf.zone = fields[10].GetUInt32();
                conf.area = fields[11].GetUInt32();
                conf.nandu = fields[12].GetUInt32();
                conf.position_x = fields[13].GetFloat();
                conf.position_y = fields[14].GetFloat();
                conf.position_z = fields[15].GetFloat();
                conf.orientation = fields[16].GetFloat();
                conf.instanceId = fields[17].GetUInt32();
                aa_caiji_creatures[conf.id] = conf;
                aa_caiji_creature_zus[conf.zu].push_back(conf.id);
            } while (result->NextRow());
            TC_LOG_INFO("server.loading", ">> 成功加载 {}条 __采集_生物 用时 {} 毫秒", (unsigned long)aa_caiji_creatures.size(), GetMSTimeDiffToNow(oldMSTime));
        }
    }
}

AA_Object AACenter::AA_GetGameObjectConf(GameObject* gameObject, GameObjectTemplate const* goinfo)
{
    //物体属性调整
    AA_Object conf;
    try {
        if (!gameObject || !goinfo) {
            return conf;
        }
        Map* map = gameObject->GetMap();
        if (!map) {
            return conf;
        }
        AA_Creature_Map m_conf;
        uint32 mapid = gameObject->GetMapId();
        uint32 zoneid = gameObject->GetZoneId();
        uint32 areaid = gameObject->GetAreaId();
        std::string rank = "全部类型";
        uint32 confid = 0;
        AA_Object_Id idconf;
        if (map->IsDungeon()) {
            uint32 instanceid = gameObject->GetInstanceId();
            uint32 nanduid = aaCenter.aa_minstancevalues[instanceid][3];
            idconf = aaCenter.aa_object_ids[goinfo->entry][nanduid];
        }
        else {
            idconf = aaCenter.aa_object_ids[goinfo->entry][0];
        }
        if (idconf.entry > 0 && idconf.zus != "" && idconf.zus != "0") {
            uint32 zu = aaCenter.AA_StringRandom(idconf.zus);
            if (zu > 0) {
                std::vector<AA_Object> confs = aaCenter.aa_object_zus[zu];
                //获取总chance，分母
                int count = confs.size();
                if (count > 0) {
                    uint32 chanceMax = 0;
                    for (int i = 0; i < count; i++) {
                        AA_Object conf = confs[i];
                        chanceMax += conf.chance;
                    }
                    //获取随机chance，分子
                    if (chanceMax == 0) { // 数据库的chance都为0
                        chanceMax = 1;
                    }
                    uint32 chanceVal = rand() % chanceMax;
                    //获取Index
                    uint32 max = 0;
                    uint32 min = 0;
                    int index = 0;
                    for (int i = 0; i < count; i++) {
                        AA_Object conf = confs[i];
                        max = conf.chance + max;
                        min = 0;
                        if (i == 0) {
                            min = 0;
                        }
                        else {
                            AA_Object conf = confs[i - 1];
                            min = conf.chance + min;
                        }
                        if (min <= chanceVal && chanceVal < max) {
                            index = i;
                            break;
                        }
                    }
                    conf = confs[index];
                }
            }
        }
        if (conf.id == 0) {
            if (map->IsDungeon()) {
                Difficulty diff = DIFFICULTY_NONE;
                //Difficulty diff = map->GetDifficulty();
                //uint32 instanceid = gameObject->GetInstanceId();
                //uint32 nanduid = aaCenter.aa_minstancevalues[instanceid][3];
                //std::string moshi = "";
                //if (diff == RAID_DIFFICULTY_25MAN_HEROIC) {
                //    moshi = "英雄25人";
                //}
                //else if (diff == RAID_DIFFICULTY_25MAN_NORMAL) {
                //    moshi = "普通25人";
                //}
                //else if (diff == DUNGEON_DIFFICULTY_HEROIC || diff == RAID_DIFFICULTY_10MAN_HEROIC || diff == DUNGEON_DIFFICULTY_EPIC) {
                //    moshi = "英雄5或10人";
                //}
                //else if (diff == DUNGEON_DIFFICULTY_NORMAL || diff == RAID_DIFFICULTY_10MAN_NORMAL || diff == REGULAR_DIFFICULTY) {
                //    moshi = "普通5或10人";
                //}
                uint32 nanduid = 0;
                std::string moshi = "全部";
                if (confid == 0)
                {
                    confid = aaCenter.aa_creature_map_areas[areaid][moshi][rank][nanduid][0];
                }
                if (confid == 0)
                {
                    confid = aaCenter.aa_creature_map_zones[zoneid][moshi][rank][nanduid][0];
                }
                if (confid == 0)
                {
                    confid = aaCenter.aa_creature_map_maps[mapid][moshi][rank][nanduid][0];
                }
                if (confid == 0)
                {
                    confid = aaCenter.aa_creature_map_alls[moshi][rank][nanduid][0];
                }
                if (confid == 0)
                {
                    confid = aaCenter.aa_creature_map_areas[areaid]["全部"][rank][nanduid][0];
                }
                if (confid == 0)
                {
                    confid = aaCenter.aa_creature_map_zones[zoneid]["全部"][rank][nanduid][0];
                }
                if (confid == 0)
                {
                    confid = aaCenter.aa_creature_map_maps[mapid]["全部"][rank][nanduid][0];
                }
                if (confid == 0)
                {
                    confid = aaCenter.aa_creature_map_alls["全部"][rank][nanduid][0];
                }
                if (confid > 0) {
                    m_conf = aaCenter.aa_creature_maps[confid];
                }
            }
            else {
                if (confid == 0)
                {
                    confid = aaCenter.aa_creature_map_yewai_areas[areaid][rank];
                }
                if (confid == 0)
                {
                    confid = aaCenter.aa_creature_map_yewai_zones[zoneid][rank];
                }
                if (confid == 0)
                {
                    confid = aaCenter.aa_creature_map_yewai_maps[mapid][rank];
                }
                if (confid == 0)
                {
                    confid = aaCenter.aa_creature_map_yewai_alls[rank];
                }
                if (confid > 0) {
                    m_conf = aaCenter.aa_creature_maps[confid];
                }
            }
            if (confid > 0) {
                AA_Creature_Map conf;

                bool isOk = true;

                if (m_conf.entrys != "" && m_conf.entrys != "0") {
                    std::vector<int32> entrys; entrys.clear();
                    aaCenter.AA_StringToVectorInt(m_conf.entrys, entrys, ",");
                    if (std::find(entrys.begin(), entrys.end(), idconf.entry) != entrys.end())
                    {
                        isOk = false;
                    }
                }

                if (!isOk) {
                    m_conf = conf;
                }
            }
            if (m_conf.o_zus != "" && m_conf.o_zus != "0") {
                uint32 zu = aaCenter.AA_StringRandom(m_conf.o_zus);
                if (zu > 0) {
                    std::vector<AA_Object> confs = aaCenter.aa_object_zus[zu];
                    //获取总chance，分母
                    int count = confs.size();
                    if (count > 0) {
                        uint32 chanceMax = 0;
                        for (int i = 0; i < count; i++) {
                            AA_Object conf = confs[i];
                            chanceMax += conf.chance;
                        }
                        //获取随机chance，分子
                        if (chanceMax == 0) { // 数据库的chance都为0
                            chanceMax = 1;
                        }
                        uint32 chanceVal = rand() % chanceMax;
                        //获取Index
                        uint32 max = 0;
                        uint32 min = 0;
                        int index = 0;
                        for (int i = 0; i < count; i++) {
                            AA_Object conf = confs[i];
                            max = conf.chance + max;
                            min = 0;
                            if (i == 0) {
                                min = 0;
                            }
                            else {
                                AA_Object conf = confs[i - 1];
                                min = conf.chance + min;
                            }
                            if (min <= chanceVal && chanceVal < max) {
                                index = i;
                                break;
                            }
                        }
                        conf = confs[index];
                    }
                }
            }
        }
        return conf;
    }
    catch (std::exception const& e) {
        return conf;
    }
    return conf;
}

AA_Creature AACenter::AA_GetCreatureConf(Creature* creature)
{
    //id -> creature-map传送 -> map
    AA_Creature conf;
    if (!creature) {
        return conf;
    }
    Map* map = creature->GetMap();
    if (!map) {
        return conf;
    }
    AA_Creature_Map m_conf;
    uint32 mapid = creature->GetMapId();
    uint32 zoneid = creature->GetZoneId();
    uint32 areaid = creature->GetAreaId();
    uint32 rankid = creature->GetCreatureTemplate()->rank;
    std::string rank = "";
    if (rankid == 0) {
        rank = "普通";
    }
    else if (rankid == 1) {
        rank = "精英";
    }
    else if (rankid == 2) {
        rank = "稀有精英";
    }
    else if (rankid == 3) {
        rank = "boss";
    }
    else if (rankid == 4) {
        rank = "稀有";
    }
    uint32 confid = 0;
    AA_Creature_Id idconf;
    CreatureTemplate const* normalInfo = creature->GetCreatureTemplate();
    if (map->IsDungeon()) {
        CreatureTemplate const* cinfo = normalInfo;
        uint8 diff = uint8(map->GetDifficultyID());
        if (diff > 0 && normalInfo->DifficultyEntry[diff - 1] > 0) {
            cinfo = sObjectMgr->GetCreatureTemplate(normalInfo->DifficultyEntry[diff - 1]);
        }
        uint32 instanceid = creature->GetInstanceId();
        uint32 nanduid = aaCenter.aa_minstancevalues[instanceid][3];
        idconf = aaCenter.aa_creature_ids[cinfo->Entry][nanduid];
    }
    else {
        idconf = aaCenter.aa_creature_ids[normalInfo->Entry][0];
    }
    if (idconf.entry > 0 && idconf.zus != "" && idconf.zus != "0") {
        uint32 zu = aaCenter.AA_StringRandom(idconf.zus);
        if (zu > 0) {
            std::vector<AA_Creature> confs = aaCenter.aa_creature_zus[zu];
            //获取总chance，分母
            int count = confs.size();
            if (count > 0) {
                uint32 chanceMax = 0;
                for (int i = 0; i < count; i++) {
                    AA_Creature conf = confs[i];
                    chanceMax += conf.chance;
                }
                //获取随机chance，分子
                if (chanceMax == 0) { // 数据库的chance都为0
                    chanceMax = 1;
                }
                uint32 chanceVal = rand() % chanceMax;
                //获取Index
                uint32 max = 0;
                uint32 min = 0;
                int index = 0;
                for (int i = 0; i < count; i++) {
                    AA_Creature conf = confs[i];
                    max = conf.chance + max;
                    min = 0;
                    if (i == 0) {
                        min = 0;
                    }
                    else {
                        AA_Creature conf = confs[i - 1];
                        min = conf.chance + min;
                    }
                    if (min <= chanceVal && chanceVal < max) {
                        index = i;
                        break;
                    }
                }
                conf = confs[index];
            }
        }
    }
    if (conf.id == 0) {
        if (map->IsDungeon()) {
            uint8 diff = uint8(map->GetDifficultyID());
            CreatureTemplate const* cinfo = normalInfo;
            if (diff > 0 && normalInfo->DifficultyEntry[diff - 1] > 0) {
                cinfo = sObjectMgr->GetCreatureTemplate(normalInfo->DifficultyEntry[diff - 1]);
            }
            uint32 instanceid = creature->GetInstanceId();
            uint32 nanduid = aaCenter.aa_minstancevalues[instanceid][3];
            std::string moshi = "";
            //if (diff == RAID_DIFFICULTY_25MAN_HEROIC) {
            //    moshi = "英雄25人";
            //}
            //else if (diff == RAID_DIFFICULTY_25MAN_NORMAL) {
            //    moshi = "普通25人";
            //}
            //else if (diff == DUNGEON_DIFFICULTY_HEROIC || diff == RAID_DIFFICULTY_10MAN_HEROIC || diff == DUNGEON_DIFFICULTY_EPIC) {
            //    moshi = "英雄5或10人";
            //}
            //else if (diff == DUNGEON_DIFFICULTY_NORMAL || diff == RAID_DIFFICULTY_10MAN_NORMAL || diff == REGULAR_DIFFICULTY) {
            //    moshi = "普通5或10人";
            //}
            if (confid == 0)
            {
                confid = aaCenter.aa_creature_map_areas[areaid][moshi][rank][nanduid][0];
            }
            if (confid == 0)
            {
                confid = aaCenter.aa_creature_map_zones[zoneid][moshi][rank][nanduid][0];
            }
            if (confid == 0)
            {
                confid = aaCenter.aa_creature_map_maps[mapid][moshi][rank][nanduid][0];
            }
            if (confid == 0)
            {
                confid = aaCenter.aa_creature_map_alls[moshi][rank][nanduid][0];
            }
            if (confid == 0)
            {
                confid = aaCenter.aa_creature_map_areas[areaid]["全部"][rank][nanduid][0];
            }
            if (confid == 0)
            {
                confid = aaCenter.aa_creature_map_zones[zoneid]["全部"][rank][nanduid][0];
            }
            if (confid == 0)
            {
                confid = aaCenter.aa_creature_map_maps[mapid]["全部"][rank][nanduid][0];
            }
            if (confid == 0)
            {
                confid = aaCenter.aa_creature_map_alls["全部"][rank][nanduid][0];
            }
            if (confid == 0)
            {
                confid = aaCenter.aa_creature_map_areas[areaid]["全部"]["所有类型"][nanduid][0];
            }
            if (confid == 0)
            {
                confid = aaCenter.aa_creature_map_zones[zoneid]["全部"]["所有类型"][nanduid][0];
            }
            if (confid == 0)
            {
                confid = aaCenter.aa_creature_map_maps[mapid]["全部"]["所有类型"][nanduid][0];
            }
            if (confid == 0)
            {
                confid = aaCenter.aa_creature_map_alls["全部"]["所有类型"][nanduid][0];
            }
            if (confid > 0) {
                m_conf = aaCenter.aa_creature_maps[confid];
            }
        }
        else {
            if (confid == 0)
            {
                confid = aaCenter.aa_creature_map_yewai_areas[areaid][rank];
            }
            if (confid == 0)
            {
                confid = aaCenter.aa_creature_map_yewai_zones[zoneid][rank];
            }
            if (confid == 0)
            {
                confid = aaCenter.aa_creature_map_yewai_maps[mapid][rank];
            }
            if (confid == 0)
            {
                confid = aaCenter.aa_creature_map_yewai_alls[rank];
            }
            if (confid == 0)
            {
                confid = aaCenter.aa_creature_map_yewai_areas[areaid]["所有类型"];
            }
            if (confid == 0)
            {
                confid = aaCenter.aa_creature_map_yewai_zones[zoneid]["所有类型"];
            }
            if (confid == 0)
            {
                confid = aaCenter.aa_creature_map_yewai_maps[mapid]["所有类型"];
            }
            if (confid == 0)
            {
                confid = aaCenter.aa_creature_map_yewai_alls["所有类型"];
            }
            if (confid > 0) {
                m_conf = aaCenter.aa_creature_maps[confid];
            }
        }
        if (confid > 0) {
            AA_Creature_Map conf;

            bool isOk = true;
            if (m_conf.factions != "" && m_conf.factions != "0") {
                std::vector<int32> factions; factions.clear();
                aaCenter.AA_StringToVectorInt(m_conf.factions, factions, ",");
                if (std::find(factions.begin(), factions.end(), normalInfo->faction) != factions.end())
                {
                    isOk = false;
                }
            }

            if (m_conf.entrys != "" && m_conf.entrys != "0") {
                std::vector<int32> entrys; entrys.clear();
                aaCenter.AA_StringToVectorInt(m_conf.entrys, entrys, ",");
                if (std::find(entrys.begin(), entrys.end(), normalInfo->Entry) != entrys.end())
                {
                    isOk = false;
                }
            }

            if (!isOk) {
                m_conf = conf;
            }
        }
        if (m_conf.c_zus != "" && m_conf.c_zus != "0") {
            uint32 zu = aaCenter.AA_StringRandom(m_conf.c_zus);
            if (zu > 0) {
                std::vector<AA_Creature> confs = aaCenter.aa_creature_zus[zu];
                //获取总chance，分母
                int count = confs.size();
                if (count > 0) {
                    uint32 chanceMax = 0;
                    for (int i = 0; i < count; i++) {
                        AA_Creature conf = confs[i];
                        chanceMax += conf.chance;
                    }
                    //获取随机chance，分子
                    if (chanceMax == 0) { // 数据库的chance都为0
                        chanceMax = 1;
                    }
                    uint32 chanceVal = rand() % chanceMax;
                    //获取Index
                    uint32 max = 0;
                    uint32 min = 0;
                    int index = 0;
                    for (int i = 0; i < count; i++) {
                        AA_Creature conf = confs[i];
                        max = conf.chance + max;
                        min = 0;
                        if (i == 0) {
                            min = 0;
                        }
                        else {
                            AA_Creature conf = confs[i - 1];
                            min = conf.chance + min;
                        }
                        if (min <= chanceVal && chanceVal < max) {
                            index = i;
                            break;
                        }
                    }
                    conf = confs[index];
                }
            }
        }
    }
    return conf;
}

void AACenter::AA_ModifyGameObject(GameObject* gameObject, AA_Object conf)
{
    //物体属性调整
    try {
        if (!gameObject) {
            return;
        }
        if (conf.id == 0) {
            return;
        }
        //aawow 物体属性调整
        gameObject->aa_id = conf.id;
        Loot* loot = const_cast<Loot*>(gameObject->m_loot.get());
        loot->aa_id_o = conf.id;
        gameObject->m_loot.reset(loot);
        //模型大小
        if (conf.scale != 1) {
            gameObject->SetObjectScale(conf.scale);
        }
    }
    catch (std::exception const& e) {}
}

void AACenter::AA_ModifyCreature(Creature* creature, AA_Creature conf)
{
    try {
        //aawow 生物属性调整
        if (!creature) {
            return;
        }
        if (conf.id == 0) {
            return;
        }
        CreatureTemplate const* cInfo = creature->GetCreatureTemplate();
        if (!cInfo) {
            return;
        }
        creature->SetCanModifyStats(false);
        creature->aa_id = conf.id;
        Loot *loot = const_cast<Loot *>(creature->m_loot.get());
        loot->aa_id_c = conf.id;
        creature->m_loot.reset(loot);
        if (conf.level > 0) {
            creature->SetLevel(conf.level);
        }
        //移动
        float speed_walk = cInfo->speed_walk;
        float speed_run = cInfo->speed_run;
        if (conf.walk_speed > 0) {
            speed_walk = conf.walk_speed;
            speed_run = conf.walk_speed;
        }
        if (conf.walk_speed1 > 0 && conf.walk_speed1 != 100) {
            speed_walk = speed_walk * (conf.walk_speed1 / 100.0);
            speed_run = speed_run * (conf.walk_speed1 / 100.0);
        }
        creature->SetSpeed(MOVE_WALK, speed_walk);
        creature->SetSpeed(MOVE_RUN, speed_run);

        //生命
        uint32 CreateHealth = creature->GetCreateHealth();
        uint32 MaxHealth = creature->GetMaxHealth();
        uint32 Health = creature->GetHealth();
        if (conf.health > 0) {
            CreateHealth = conf.health;
            MaxHealth = conf.health;
            Health = conf.health;
        }
        if (conf.health1 > 0 && conf.health1 != 100) {
            CreateHealth = CreateHealth * (conf.health1 / 100.0);
            MaxHealth = MaxHealth * (conf.health1 / 100.0);
            Health = Health * (conf.health1 / 100.0);
        }
        creature->SetCreateHealth(CreateHealth);
        creature->SetMaxHealth(MaxHealth);
        creature->SetHealth(Health);
        creature->ResetPlayerDamageReq();

        // mana
        uint32 CreateMana = creature->GetCreateMana();
        uint32 maxmana = creature->GetMaxPower(POWER_MANA);
        uint32 mana = creature->GetPower(POWER_MANA);
        if (conf.mana > 0) {
            CreateMana = conf.mana;
            maxmana = conf.mana;
            mana = conf.mana;
        }
        if (conf.mana1 > 0 && conf.mana1 != 100) {
            CreateMana = CreateMana * (conf.mana1 / 100.0);
            maxmana = maxmana * (conf.mana1 / 100.0);
            mana = mana * (conf.mana1 / 100.0);
        }
        creature->SetCreateMana(CreateMana);
        creature->SetMaxPower(POWER_MANA, maxmana);
        creature->SetPower(POWER_MANA, mana);

        //creature->SetModifierValue(UNIT_MOD_HEALTH, BASE_VALUE, (float)CreateHealth);
        creature->SetStatFlatModifier(UNIT_MOD_MANA, BASE_VALUE, (float)CreateMana);

        //攻击间隔
        uint32 BaseAttackTime = cInfo->BaseAttackTime;
        uint32 RangeAttackTime = cInfo->RangeAttackTime;
        if (conf.attack_speed > 0) {
            BaseAttackTime = conf.attack_speed;
            RangeAttackTime = conf.attack_speed;
        }
        if (conf.attack_speed1 > 0 && conf.attack_speed1 != 100) {
            BaseAttackTime = BaseAttackTime * (conf.attack_speed1 / 100.0);
            RangeAttackTime = RangeAttackTime * (conf.attack_speed1 / 100.0);
        }
        creature->SetBaseAttackTime(BASE_ATTACK, BaseAttackTime);
        creature->SetBaseAttackTime(OFF_ATTACK, BaseAttackTime);
        creature->SetBaseAttackTime(RANGED_ATTACK, RangeAttackTime);

        //护甲
        uint32 armor = creature->GetArmor();
        if (conf.armor > 0) {
            armor = conf.armor;
        }
        if (conf.armor1 > 0 && conf.armor1 != 100) {
            armor = armor * (conf.armor1 / 100.0);
        }
        creature->SetStatFlatModifier(UNIT_MOD_ARMOR, BASE_VALUE, armor);
        //抗性
        int32 resistance1 = cInfo->resistance[SPELL_SCHOOL_HOLY];
        int32 resistance2 = cInfo->resistance[SPELL_SCHOOL_FIRE];
        int32 resistance3 = cInfo->resistance[SPELL_SCHOOL_NATURE];
        int32 resistance4 = cInfo->resistance[SPELL_SCHOOL_FROST];
        int32 resistance5 = cInfo->resistance[SPELL_SCHOOL_SHADOW];
        int32 resistance6 = cInfo->resistance[SPELL_SCHOOL_ARCANE];
        if (conf.resistance > 0) {
            resistance1 = conf.resistance;
            resistance2 = conf.resistance;
            resistance3 = conf.resistance;
            resistance4 = conf.resistance;
            resistance5 = conf.resistance;
            resistance6 = conf.resistance;
        }
        if (conf.resistance1 > 0 && conf.resistance1 != 100) {
            resistance1 = resistance1 * (conf.resistance1 / 100.0);
            resistance2 = resistance2 * (conf.resistance1 / 100.0);
            resistance3 = resistance3 * (conf.resistance1 / 100.0);
            resistance4 = resistance4 * (conf.resistance1 / 100.0);
            resistance5 = resistance5 * (conf.resistance1 / 100.0);
            resistance6 = resistance6 * (conf.resistance1 / 100.0);
        }
        creature->SetStatFlatModifier(UNIT_MOD_RESISTANCE_HOLY, BASE_VALUE, float(resistance1));
        creature->SetStatFlatModifier(UNIT_MOD_RESISTANCE_FIRE, BASE_VALUE, float(resistance2));
        creature->SetStatFlatModifier(UNIT_MOD_RESISTANCE_NATURE, BASE_VALUE, float(resistance3));
        creature->SetStatFlatModifier(UNIT_MOD_RESISTANCE_FROST, BASE_VALUE, float(resistance4));
        creature->SetStatFlatModifier(UNIT_MOD_RESISTANCE_SHADOW, BASE_VALUE, float(resistance5));
        creature->SetStatFlatModifier(UNIT_MOD_RESISTANCE_ARCANE, BASE_VALUE, float(resistance6));

        //模型
        if (conf.moxing != "0" && conf.moxing != "") {
            uint32 moxing = aaCenter.AA_StringRandom(conf.moxing);
            CreatureModelInfo const* minfo = sObjectMgr->GetCreatureModelInfo(moxing);
            if (minfo && !creature->IsTotem())                               // Cancel load if no model defined or if totem
            {
                creature->SetDisplayId(moxing);
            }
        }
        else {
            uint32 moxing = cInfo->GetFirstValidModel()->CreatureDisplayID;
            CreatureModelInfo const* minfo = sObjectMgr->GetCreatureModelInfo(moxing);
            creature->SetDisplayId(moxing);
            creature->RestoreDisplayId();
        }
        //武器外观主手
        if (conf.moxing1 != "" && conf.moxing1 != "0") {
            uint32 moxing = aaCenter.AA_StringRandom(conf.moxing1);
            creature->SetVirtualItem(0, moxing, 0, 0);
        }
        else {
            CreatureData const* creData = sObjectMgr->GetCreatureData(creature->GetGUIDLow());
            if (creData) {
                int8 equipmentId = int8(creData->equipmentId);
                EquipmentInfo const* einfo = sObjectMgr->GetEquipmentInfo(creature->GetEntry(), equipmentId);
                if (einfo) {
                    creature->SetVirtualItem(0, einfo->Items[0].ItemId, einfo->Items[0].AppearanceModId, einfo->Items[0].ItemVisual);
                }
            }
        }
        //武器外观副手
        if (conf.moxing2 != "" && conf.moxing2 != "0") {
            uint32 moxing = aaCenter.AA_StringRandom(conf.moxing2);
            creature->SetVirtualItem(1, moxing, 0, 0);
        }
        else {
            CreatureData const* creData = sObjectMgr->GetCreatureData(creature->GetGUIDLow());
            if (creData) {
                int8 equipmentId = int8(creData->equipmentId);
                EquipmentInfo const* einfo = sObjectMgr->GetEquipmentInfo(creature->GetEntry(), equipmentId);
                if (einfo) {
                    creature->SetVirtualItem(1, einfo->Items[1].ItemId, einfo->Items[1].AppearanceModId, einfo->Items[1].ItemVisual);
                }
            }
        }
        //武器外观远程
        if (conf.moxing3 != "" && conf.moxing3 != "0") {
            uint32 moxing = aaCenter.AA_StringRandom(conf.moxing2);
            creature->SetVirtualItem(2, moxing, 0, 0);
        }
        else {
            CreatureData const* creData = sObjectMgr->GetCreatureData(creature->GetGUIDLow());
            if (creData) {
                int8 equipmentId = int8(creData->equipmentId);
                EquipmentInfo const* einfo = sObjectMgr->GetEquipmentInfo(creature->GetEntry(), equipmentId);
                if (einfo) {
                    creature->SetVirtualItem(2, einfo->Items[2].ItemId, einfo->Items[2].AppearanceModId, einfo->Items[2].ItemVisual);
                }
            }
        }
        //模型大小
        if (conf.scale != 1 && conf.scale > 0) {
            creature->SetObjectScale(conf.scale);
        }
        else {
            creature->SetObjectScale(cInfo->scale);
        }
        creature->SetCanModifyStats(true);
        creature->UpdateAllStats();
    }
    catch (std::exception const& e) {
    }
}

void AACenter::AA_ModifySpellCooldown(Player* caster, SpellInfo const* spellInfo, int32 cooldown)
{
    int32 time1 = spellInfo->RecoveryTime;
    int32 time2 = spellInfo->CategoryRecoveryTime;
    int32 time3 = spellInfo->StartRecoveryTime;
    time1 = time1 > time2 ? time1 : time2;
    time1 = time1 > time3 ? time1 : time3;
    time1 = cooldown - time1;
    caster->GetSpellHistory()->ModifyCooldown(spellInfo->Id, Seconds(time1));
}

uint32 AACenter::AA_GetCreatureRandomEntry(uint32 entry)
{
    try {
        if (entry > 0) {
            std::vector<AA_CreatureTemplate> confs = aaCenter.aa_creature_templates[entry];
            //获取总chance，分母
            int count = confs.size();
            if (count > 0) {
                AA_CreatureTemplate conf;
                uint32 chanceMax = 0;
                for (int i = 0; i < count; i++) {
                    AA_CreatureTemplate conf = confs[i];
                    chanceMax += conf.chance;
                }
                if (chanceMax == 0) { // 数据库的chance都为0
                    chanceMax = 1;
                }
                //获取随机chance，分子
                uint32 chanceVal = rand() % chanceMax;

                //获取Index
                uint32 max = 0;
                uint32 min = 0;
                int index = -1;
                for (int i = 0; i < count; i++) {
                    AA_CreatureTemplate conf = confs[i];
                    max = conf.chance + max;
                    min = 0;
                    if (i == 0) {
                        min = 0;
                    }
                    else {
                        AA_CreatureTemplate conf = confs[i - 1];
                        min = conf.chance + min;
                    }

                    if (min <= chanceVal && chanceVal < max) {
                        index = i;
                        break;
                    }
                }
                conf = confs[index];
                return conf.entry1;
            }
            else {
                return 0;
            }
        }
    }
    catch (std::exception const& e) {}
    return 0;
}

//命令相关
void AACenter::AA_TeleportMoban(Player* player, uint32 mobanid)
{
    if (mobanid > 0) {
        AA_Caiji_Zuobiao conf = aaCenter.aa_caiji_zuobiaos[mobanid];
        if (conf.map || conf.position_x > 0 || conf.position_y > 0 || conf.position_z > 0 || conf.orientation > 0) {
            player->TeleportTo(conf.map, conf.position_x, conf.position_y, conf.position_z, conf.orientation);
        }
    }
}

bool AACenter::AA_VerifyCode(std::string code)
{
    if (aaCenter.aa_version.status.find(code) != string::npos) {
        return true;
    }
    return false;
}

AA_Paihang AACenter::AA_GetPaihangs()
{
    AA_Paihang aa_paihang;
    aa_paihang.aa_money.clear();
    aa_paihang.aa_health.clear();
    aa_paihang.aa_zaixianshijian.clear();
    aa_paihang.aa_jisha.clear();
    aa_paihang.aa_jx_level.clear();
    aa_paihang.aa_dq_level.clear();
    aa_paihang.aa_df_level.clear();
    aa_paihang.aa_leichong.clear();
    aa_paihang.aa_jinrileichong.clear();
    aa_paihang.aa_renwu.clear();
    aa_paihang.aa_level_item_ItemLevel.clear();
    aa_paihang.aa_level_item_Quality.clear();
    aa_paihang.aa_level_item_jd.clear();
    aa_paihang.aa_level_item_qh.clear();
    aa_paihang.aa_level_item_cz.clear();
    aa_paihang.aa_level_item_jxsx.clear();
    aa_paihang.aa_level_item_jxjn.clear();
    aa_paihang.aa_level_pet_jh.clear();
    aa_paihang.aa_level_pet_qh.clear();
    aa_paihang.aa_level_pet_jx.clear();
    aa_paihang.aa_diy_guids.clear();
    aa_paihang.aa_diy_accounts.clear();

    std::set<Player*> players; players.clear();
    const HashMapHolder<Player>::MapType& m = ObjectAccessor::GetPlayers();
    for (HashMapHolder<Player>::MapType::const_iterator it = m.begin(); it != m.end(); ++it)
    {
        if (Player* p = it->second)
        {
            if (!p->IsInWorld()) { continue; }
            players.insert(p);
        }
    }
    //缺少成就和声望
    std::map<ObjectGuid, uint32> aa_money;
    std::map<ObjectGuid, uint32> aa_health;
    std::map<ObjectGuid, uint32> aa_zaixianshijian;
    std::map<ObjectGuid, uint32> aa_jisha;
    std::map<ObjectGuid, uint32> aa_jx_level;
    std::map<ObjectGuid, uint32> aa_dq_level;
    std::map<ObjectGuid, uint32> aa_df_level;
    std::map<ObjectGuid, uint32> aa_leichong;
    std::map<ObjectGuid, uint32> aa_jinrileichong;
    std::map<ObjectGuid, uint32> aa_renwu;
    std::map<ObjectGuid, uint32> aa_level_item_ItemLevel;
    std::map<ObjectGuid, uint32> aa_level_item_Quality;
    std::map<ObjectGuid, uint32> aa_level_item_jd;
    std::map<ObjectGuid, uint32> aa_level_item_qh;
    std::map<ObjectGuid, uint32> aa_level_item_cz;
    std::map<ObjectGuid, uint32> aa_level_item_jxsx;
    std::map<ObjectGuid, uint32> aa_level_item_jxjn;
    std::map<ObjectGuid, uint32> aa_level_pet_jh;
    std::map<ObjectGuid, uint32> aa_level_pet_qh;
    std::map<ObjectGuid, uint32> aa_level_pet_jx;
    std::map< std::string, std::map<ObjectGuid, uint32> > aa_diy_guids;
    std::map< std::string, std::map<ObjectGuid, uint32> > aa_diy_accounts;

    for (Player* p : players) {
        AA_Account a_conf = aaCenter.aa_accounts[p->GetSession()->GetAccountId()];
        AA_Characters_Junxian jx_conf = aaCenter.aa_characters_junxians[p->GetGUIDLow()];
        AA_Characters_Douqi dq_conf = aaCenter.aa_characters_douqis[p->GetGUIDLow()];
        AA_Characters_Dianfeng df_conf = aaCenter.aa_characters_dianfengs[p->GetGUIDLow()];
        aa_money[p->GetGUID()] = p->GetMoney();
        aa_health[p->GetGUID()] = p->GetMaxHealth();
        aa_zaixianshijian[p->GetGUID()] = p->GetTotalPlayedTime();
        aa_jisha[p->GetGUID()] = aa_jishas[p->GetGUIDLow()];
        aa_jx_level[p->GetGUID()] = jx_conf.level;
        aa_dq_level[p->GetGUID()] = dq_conf.level;
        aa_df_level[p->GetGUID()] = df_conf.level;
        aa_leichong[p->GetGUID()] = a_conf.jifen_all;
        aa_jinrileichong[p->GetGUID()] = a_conf.jifen_day;
        aa_renwu[p->GetGUID()] = aa_renwus[p->GetGUIDLow()];
        aa_level_item_ItemLevel[p->GetGUID()] = aaCenter.GetAll_level_item_ItemLevel(p);
        aa_level_item_Quality[p->GetGUID()] = aaCenter.GetAll_level_item_Quality(p);
        aa_level_item_jd[p->GetGUID()] = aaCenter.GetAll_level_item_jd(p);
        aa_level_item_qh[p->GetGUID()] = aaCenter.GetAll_level_item_qh(p);
        aa_level_item_cz[p->GetGUID()] = aaCenter.GetAll_level_item_cz(p);
        aa_level_item_jxsx[p->GetGUID()] = aaCenter.GetAll_level_item_jxsx(p);
        aa_level_item_jxjn[p->GetGUID()] = aaCenter.GetAll_level_item_jxjn(p);

        std::string diy_guid = aaCenter.aa_characterss[p->GetGUIDLow()].diy_guid;
        if (diy_guid != "") {
            std::map<std::string, std::string> diy_guids; diy_guids.clear();
            aaCenter.AA_StringToStringMap(diy_guid, diy_guids);
            if (!diy_guids.empty()) {
                for (auto itr : diy_guids) {
                    aa_diy_guids[itr.first][p->GetGUID()] = aaCenter.AA_StringUint32(itr.second);
                }
            }
        }
        std::string diy_account = aaCenter.aa_accounts[p->GetSession()->GetAccountId()].diy_account;
        if (diy_account != "") {
            std::map<std::string, std::string> diy_accounts; diy_accounts.clear();
            aaCenter.AA_StringToStringMap(diy_account, diy_accounts);
            if (!diy_accounts.empty()) {
                for (auto itr : diy_accounts) {
                    aa_diy_accounts[itr.first][p->GetGUID()] = aaCenter.AA_StringUint32(itr.second);
                }
            }
        }
    }
    { //自定义变量
        for (auto itr : aa_diy_guids) {
            std::string diy_key = itr.first;
            std::map<ObjectGuid, uint32> diy_value = itr.second;
            std::vector<std::pair<ObjectGuid, uint32>> aa_diy; aa_diy.clear();
            paihangpx(aa_diy, diy_value);
            aa_paihang.aa_diy_guids[diy_key] = aa_diy;
        }
        for (auto itr : aa_diy_accounts) {
            std::string diy_key = itr.first;
            std::map<ObjectGuid, uint32> diy_value = itr.second;
            std::vector<std::pair<ObjectGuid, uint32>> aa_diy; aa_diy.clear();
            paihangpx(aa_diy, diy_value);
            aa_paihang.aa_diy_accounts[diy_key] = aa_diy;
        }
    }
    paihangpx(aa_paihang.aa_money, aa_money);
    paihangpx(aa_paihang.aa_health, aa_health);
    paihangpx(aa_paihang.aa_zaixianshijian, aa_zaixianshijian);
    paihangpx(aa_paihang.aa_jisha, aa_jisha);
    paihangpx(aa_paihang.aa_jx_level, aa_jx_level);
    paihangpx(aa_paihang.aa_dq_level, aa_dq_level);
    paihangpx(aa_paihang.aa_df_level, aa_df_level);
    paihangpx(aa_paihang.aa_leichong, aa_leichong);
    paihangpx(aa_paihang.aa_jinrileichong, aa_jinrileichong);
    paihangpx(aa_paihang.aa_renwu, aa_renwu);
    paihangpx(aa_paihang.aa_level_item_ItemLevel, aa_level_item_ItemLevel);
    paihangpx(aa_paihang.aa_level_item_Quality, aa_level_item_Quality);
    paihangpx(aa_paihang.aa_level_item_jd, aa_level_item_jd);
    paihangpx(aa_paihang.aa_level_item_qh, aa_level_item_qh);
    paihangpx(aa_paihang.aa_level_item_cz, aa_level_item_cz);
    paihangpx(aa_paihang.aa_level_item_jxsx, aa_level_item_jxsx);
    paihangpx(aa_paihang.aa_level_item_jxjn, aa_level_item_jxjn);
    paihangpx(aa_paihang.aa_level_pet_jh, aa_level_pet_jh);
    paihangpx(aa_paihang.aa_level_pet_qh, aa_level_pet_qh);
    paihangpx(aa_paihang.aa_level_pet_jx, aa_level_pet_jx);
    return aa_paihang;
}

std::string AACenter::AA_GetPaihangInfo(std::string& message, AA_Paihang conf)
{
    if (!aaCenter.AA_VerifyCode("a200b")) {
        return "请联系QQ643125009开通";
    }
    if (message.find("<$自定义角色排行数量") != string::npos) {
        std::string prestr = "<$自定义角色排行数量";
        std::string diy_key = aaCenter.AA_StringGet(message, prestr, "@");
        std::string nums = aaCenter.AA_StringGet(message, prestr + diy_key + "@", ">");
        std::string fulstr = prestr + diy_key + "@" + nums + ">";
        if (nums != "") {
            int num = atoi(nums.c_str());
            if (num > 0 && (int)conf.aa_diy_guids[diy_key].size() >= num) {
                std::pair<ObjectGuid, uint32> m = conf.aa_diy_guids[diy_key][num - 1];
                aaCenter.AA_StringReplace(message, fulstr, std::to_string(m.second));
            }
            else {
                aaCenter.AA_StringReplace(message, fulstr, "无");
            }
        }
        else {
            aaCenter.AA_StringReplace(message, fulstr, "无");
        }
    }
    if (message.find("<$自定义角色排行姓名") != string::npos) {
        std::string prestr = "<$自定义角色排行姓名";
        std::string diy_key = aaCenter.AA_StringGet(message, prestr, "@");
        std::string nums = aaCenter.AA_StringGet(message, prestr + diy_key + "@", ">");
        std::string fulstr = prestr + diy_key + "@" + nums + ">";
        if (nums != "") {
            int num = atoi(nums.c_str());
            if (num > 0 && (int)conf.aa_diy_guids[diy_key].size() >= num) {
                std::pair<ObjectGuid, uint32> m = conf.aa_diy_guids[diy_key][num - 1];
                if (Player* p = ObjectAccessor::FindPlayer(m.first)) {
                    if (p && p->IsInWorld()) {
                        std::string name = p->GetName();
                        aaCenter.AA_StringReplace(message, fulstr, name);
                    }
                }
            }
            else {
                aaCenter.AA_StringReplace(message, fulstr, "无");
            }
        }
        else {
            aaCenter.AA_StringReplace(message, fulstr, "无");
        }
    }
    if (message.find("<$自定义账号排行数量") != string::npos) {
        std::string prestr = "<$自定义账号排行数量";
        std::string diy_key = aaCenter.AA_StringGet(message, prestr, "@");
        std::string nums = aaCenter.AA_StringGet(message, prestr + diy_key + "@", ">");
        std::string fulstr = prestr + diy_key + "@" + nums + ">";
        if (nums != "") {
            int num = atoi(nums.c_str());
            if (num > 0 && (int)conf.aa_diy_accounts[diy_key].size() >= num) {
                std::pair<ObjectGuid, uint32> m = conf.aa_diy_accounts[diy_key][num - 1];
                aaCenter.AA_StringReplace(message, fulstr, std::to_string(m.second));
            }
            else {
                aaCenter.AA_StringReplace(message, fulstr, "无");
            }
        }
        else {
            aaCenter.AA_StringReplace(message, fulstr, "无");
        }
    }
    if (message.find("<$自定义账号排行姓名") != string::npos) {
        std::string prestr = "<$自定义账号排行姓名";
        std::string diy_key = aaCenter.AA_StringGet(message, prestr, "@");
        std::string nums = aaCenter.AA_StringGet(message, prestr + diy_key + "@", ">");
        std::string fulstr = prestr + diy_key + "@" + nums + ">";
        if (nums != "") {
            int num = atoi(nums.c_str());
            if (num > 0 && (int)conf.aa_diy_accounts[diy_key].size() >= num) {
                std::pair<ObjectGuid, uint32> m = conf.aa_diy_accounts[diy_key][num - 1];
                if (Player* p = ObjectAccessor::FindPlayer(m.first)) {
                    if (p && p->IsInWorld()) {
                        std::string name = p->GetName();
                        aaCenter.AA_StringReplace(message, fulstr, name);
                    }
                }
            }
            else {
                aaCenter.AA_StringReplace(message, fulstr, "无");
            }
        }
        else {
            aaCenter.AA_StringReplace(message, fulstr, "无");
        }
    }
    if (message.find("<$金币排行姓名@") != string::npos) {
        std::string prestr = "<$金币排行姓名@";
        std::string nums = aaCenter.AA_StringGet(message, prestr, ">");
        std::string fulstr = prestr + nums + ">";
        if (nums != "") {
            int num = atoi(nums.c_str());
            if (num > 0 && (int)conf.aa_money.size() >= num) {
                std::pair<ObjectGuid, uint32> m = conf.aa_money[num - 1];
                if (Player* p = ObjectAccessor::FindPlayer(m.first)) {
                    if (p && p->IsInWorld()) {
                        std::string name = p->GetName();
                        aaCenter.AA_StringReplace(message, fulstr, name);
                    }
                }
            }
            else {
                aaCenter.AA_StringReplace(message, fulstr, "无");
            }
        }
        else {
            aaCenter.AA_StringReplace(message, fulstr, "无");
        }
    }
    if (message.find("<$金币排行数量@") != string::npos) {
        std::string prestr = "<$金币排行数量@";
        std::string nums = aaCenter.AA_StringGet(message, prestr, ">");
        std::string fulstr = prestr + nums + ">";
        if (nums != "") {
            int num = atoi(nums.c_str());
            if (num > 0 && (int)conf.aa_money.size() >= num) {
                std::pair<ObjectGuid, uint32> m = conf.aa_money[num - 1];
                aaCenter.AA_StringReplace(message, fulstr, aaCenter.AA_GetMoneyLink(m.second));
            }
            else {
                aaCenter.AA_StringReplace(message, fulstr, "无");
            }
        }
        else {
            aaCenter.AA_StringReplace(message, fulstr, "无");
        }
    }

    if (message.find("<$生命排行姓名@") != string::npos) {
        std::string prestr = "<$生命排行姓名@";
        std::string nums = aaCenter.AA_StringGet(message, prestr, ">");
        std::string fulstr = prestr + nums + ">";
        if (nums != "") {
            int num = atoi(nums.c_str());
            if (num > 0 && (int)conf.aa_health.size() >= num) {
                std::pair<ObjectGuid, uint32> m = conf.aa_health[num - 1];
                if (Player* p = ObjectAccessor::FindPlayer(m.first)) {
                    if (p && p->IsInWorld()) {
                        std::string name = p->GetName();
                        aaCenter.AA_StringReplace(message, fulstr, name);
                    }
                }
            }
            else {
                aaCenter.AA_StringReplace(message, fulstr, "无");
            }
        }
        else {
            aaCenter.AA_StringReplace(message, fulstr, "无");
        }
    }
    if (message.find("<$生命排行数量@") != string::npos) {
        std::string prestr = "<$生命排行数量@";
        std::string nums = aaCenter.AA_StringGet(message, prestr, ">");
        std::string fulstr = prestr + nums + ">";
        if (nums != "") {
            int num = atoi(nums.c_str());
            if (num > 0 && (int)conf.aa_health.size() >= num) {
                std::pair<ObjectGuid, uint32> m = conf.aa_health[num - 1];
                aaCenter.AA_StringReplace(message, fulstr, std::to_string(m.second));
            }
            else {
                aaCenter.AA_StringReplace(message, fulstr, "无");
            }
        }
        else {
            aaCenter.AA_StringReplace(message, fulstr, "无");
        }
    }

    if (message.find("<$在线时间排行姓名@") != string::npos) {
        std::string prestr = "<$在线时间排行姓名@";
        std::string nums = aaCenter.AA_StringGet(message, prestr, ">");
        std::string fulstr = prestr + nums + ">";
        if (nums != "") {
            int num = atoi(nums.c_str());
            if (num > 0 && (int)conf.aa_zaixianshijian.size() >= num) {
                std::pair<ObjectGuid, uint32> m = conf.aa_zaixianshijian[num - 1];
                if (Player* p = ObjectAccessor::FindPlayer(m.first)) {
                    if (p && p->IsInWorld()) {
                        std::string name = p->GetName();
                        aaCenter.AA_StringReplace(message, fulstr, name);
                    }
                }
            }
            else {
                aaCenter.AA_StringReplace(message, fulstr, "无");
            }
        }
        else {
            aaCenter.AA_StringReplace(message, fulstr, "无");
        }
    }
    if (message.find("<$在线时间排行数量@") != string::npos) {
        std::string prestr = "<$在线时间排行数量@";
        std::string nums = aaCenter.AA_StringGet(message, prestr, ">");
        std::string fulstr = prestr + nums + ">";
        if (nums != "") {
            int num = atoi(nums.c_str());
            if (num > 0 && (int)conf.aa_zaixianshijian.size() >= num) {
                std::pair<ObjectGuid, uint32> m = conf.aa_zaixianshijian[num - 1];
                aaCenter.AA_StringReplace(message, fulstr, std::to_string(m.second));
            }
            else {
                aaCenter.AA_StringReplace(message, fulstr, "无");
            }
        }
        else {
            aaCenter.AA_StringReplace(message, fulstr, "无");
        }
    }

    if (message.find("<$击杀排行姓名@") != string::npos) {
        std::string prestr = "<$击杀排行姓名@";
        std::string nums = aaCenter.AA_StringGet(message, prestr, ">");
        std::string fulstr = prestr + nums + ">";
        if (nums != "") {
            int num = atoi(nums.c_str());
            if (num > 0 && (int)conf.aa_jisha.size() >= num) {
                std::pair<ObjectGuid, uint32> m = conf.aa_jisha[num - 1];
                if (Player* p = ObjectAccessor::FindPlayer(m.first)) {
                    if (p && p->IsInWorld()) {
                        std::string name = p->GetName();
                        aaCenter.AA_StringReplace(message, fulstr, name);
                    }
                }
            }
            else {
                aaCenter.AA_StringReplace(message, fulstr, "无");
            }
        }
        else {
            aaCenter.AA_StringReplace(message, fulstr, "无");
        }
    }
    if (message.find("<$击杀排行数量@") != string::npos) {
        std::string prestr = "<$击杀排行数量@";
        std::string nums = aaCenter.AA_StringGet(message, prestr, ">");
        std::string fulstr = prestr + nums + ">";
        if (nums != "") {
            int num = atoi(nums.c_str());
            if (num > 0 && (int)conf.aa_jisha.size() >= num) {
                std::pair<ObjectGuid, uint32> m = conf.aa_jisha[num - 1];
                aaCenter.AA_StringReplace(message, fulstr, std::to_string(m.second));
            }
            else {
                aaCenter.AA_StringReplace(message, fulstr, "无");
            }
        }
        else {
            aaCenter.AA_StringReplace(message, fulstr, "无");
        }
    }

    if (message.find("<$军衔等级排行姓名@") != string::npos) {
        std::string prestr = "<$军衔等级排行姓名@";
        std::string nums = aaCenter.AA_StringGet(message, prestr, ">");
        std::string fulstr = prestr + nums + ">";
        if (nums != "") {
            int num = atoi(nums.c_str());
            if (num > 0 && (int)conf.aa_jx_level.size() >= num) {
                std::pair<ObjectGuid, uint32> m = conf.aa_jx_level[num - 1];
                if (Player* p = ObjectAccessor::FindPlayer(m.first)) {
                    if (p && p->IsInWorld()) {
                        std::string name = p->GetName();
                        aaCenter.AA_StringReplace(message, fulstr, name);
                    }
                }
            }
            else {
                aaCenter.AA_StringReplace(message, fulstr, "无");
            }
        }
        else {
            aaCenter.AA_StringReplace(message, fulstr, "无");
        }
    }
    if (message.find("<$军衔等级排行数量@") != string::npos) {
        std::string prestr = "<$军衔等级排行数量@";
        std::string nums = aaCenter.AA_StringGet(message, prestr, ">");
        std::string fulstr = prestr + nums + ">";
        if (nums != "") {
            int num = atoi(nums.c_str());
            if (num > 0 && (int)conf.aa_jx_level.size() >= num) {
                std::pair<ObjectGuid, uint32> m = conf.aa_jx_level[num - 1];
                aaCenter.AA_StringReplace(message, fulstr, std::to_string(m.second));
            }
            else {
                aaCenter.AA_StringReplace(message, fulstr, "无");
            }
        }
        else {
            aaCenter.AA_StringReplace(message, fulstr, "无");
        }
    }

    if (message.find("<$斗气等级排行姓名@") != string::npos) {
        std::string prestr = "<$斗气等级排行姓名@";
        std::string nums = aaCenter.AA_StringGet(message, prestr, ">");
        std::string fulstr = prestr + nums + ">";
        if (nums != "") {
            int num = atoi(nums.c_str());
            if (num > 0 && (int)conf.aa_dq_level.size() >= num) {
                std::pair<ObjectGuid, uint32> m = conf.aa_dq_level[num - 1];
                if (Player* p = ObjectAccessor::FindPlayer(m.first)) {
                    if (p && p->IsInWorld()) {
                        std::string name = p->GetName();
                        aaCenter.AA_StringReplace(message, fulstr, name);
                    }
                }
            }
            else {
                aaCenter.AA_StringReplace(message, fulstr, "无");
            }
        }
        else {
            aaCenter.AA_StringReplace(message, fulstr, "无");
        }
    }
    if (message.find("<$斗气等级排行数量@") != string::npos) {
        std::string prestr = "<$斗气等级排行数量@";
        std::string nums = aaCenter.AA_StringGet(message, prestr, ">");
        std::string fulstr = prestr + nums + ">";
        if (nums != "") {
            int num = atoi(nums.c_str());
            if (num > 0 && (int)conf.aa_dq_level.size() >= num) {
                std::pair<ObjectGuid, uint32> m = conf.aa_dq_level[num - 1];
                aaCenter.AA_StringReplace(message, fulstr, std::to_string(m.second));
            }
            else {
                aaCenter.AA_StringReplace(message, fulstr, "无");
            }
        }
        else {
            aaCenter.AA_StringReplace(message, fulstr, "无");
        }
    }

    if (message.find("<$巅峰等级排行姓名@") != string::npos) {
        std::string prestr = "<$巅峰等级排行姓名@";
        std::string nums = aaCenter.AA_StringGet(message, prestr, ">");
        std::string fulstr = prestr + nums + ">";
        if (nums != "") {
            int num = atoi(nums.c_str());
            if (num > 0 && (int)conf.aa_df_level.size() >= num) {
                std::pair<ObjectGuid, uint32> m = conf.aa_df_level[num - 1];
                if (Player* p = ObjectAccessor::FindPlayer(m.first)) {
                    if (p && p->IsInWorld()) {
                        std::string name = p->GetName();
                        aaCenter.AA_StringReplace(message, fulstr, name);
                    }
                }
            }
            else {
                aaCenter.AA_StringReplace(message, fulstr, "无");
            }
        }
        else {
            aaCenter.AA_StringReplace(message, fulstr, "无");
        }
    }
    if (message.find("<$巅峰等级排行数量@") != string::npos) {
        std::string prestr = "<$巅峰等级排行数量@";
        std::string nums = aaCenter.AA_StringGet(message, prestr, ">");
        std::string fulstr = prestr + nums + ">";
        if (nums != "") {
            int num = atoi(nums.c_str());
            if (num > 0 && (int)conf.aa_df_level.size() >= num) {
                std::pair<ObjectGuid, uint32> m = conf.aa_df_level[num - 1];
                aaCenter.AA_StringReplace(message, fulstr, std::to_string(m.second));
            }
            else {
                aaCenter.AA_StringReplace(message, fulstr, "无");
            }
        }
        else {
            aaCenter.AA_StringReplace(message, fulstr, "无");
        }
    }

    if (message.find("<$累充排行姓名@") != string::npos) {
        std::string prestr = "<$累充排行姓名@";
        std::string nums = aaCenter.AA_StringGet(message, prestr, ">");
        std::string fulstr = prestr + nums + ">";
        if (nums != "") {
            int num = atoi(nums.c_str());
            if (num > 0 && (int)conf.aa_leichong.size() >= num) {
                std::pair<ObjectGuid, uint32> m = conf.aa_leichong[num - 1];
                if (Player* p = ObjectAccessor::FindPlayer(m.first)) {
                    if (p && p->IsInWorld()) {
                        std::string name = p->GetName();
                        aaCenter.AA_StringReplace(message, fulstr, name);
                    }
                }
            }
            else {
                aaCenter.AA_StringReplace(message, fulstr, "无");
            }
        }
        else {
            aaCenter.AA_StringReplace(message, fulstr, "无");
        }
    }
    if (message.find("<$累充排行数量@") != string::npos) {
        std::string prestr = "<$累充排行数量@";
        std::string nums = aaCenter.AA_StringGet(message, prestr, ">");
        std::string fulstr = prestr + nums + ">";
        if (nums != "") {
            int num = atoi(nums.c_str());
            if (num > 0 && (int)conf.aa_leichong.size() >= num) {
                std::pair<ObjectGuid, uint32> m = conf.aa_leichong[num - 1];
                aaCenter.AA_StringReplace(message, fulstr, std::to_string(m.second));
            }
            else {
                aaCenter.AA_StringReplace(message, fulstr, "无");
            }
        }
        else {
            aaCenter.AA_StringReplace(message, fulstr, "无");
        }
    }

    if (message.find("<$今日累充排行姓名@") != string::npos) {
        std::string prestr = "<$今日累充排行姓名@";
        std::string nums = aaCenter.AA_StringGet(message, prestr, ">");
        std::string fulstr = prestr + nums + ">";
        if (nums != "") {
            int num = atoi(nums.c_str());
            if (num > 0 && (int)conf.aa_jinrileichong.size() >= num) {
                std::pair<ObjectGuid, uint32> m = conf.aa_jinrileichong[num - 1];
                if (Player* p = ObjectAccessor::FindPlayer(m.first)) {
                    if (p && p->IsInWorld()) {
                        std::string name = p->GetName();
                        aaCenter.AA_StringReplace(message, fulstr, name);
                    }
                }
            }
            else {
                aaCenter.AA_StringReplace(message, fulstr, "无");
            }
        }
        else {
            aaCenter.AA_StringReplace(message, fulstr, "无");
        }
    }
    if (message.find("<$今日累充排行数量@") != string::npos) {
        std::string prestr = "<$今日累充排行数量@";
        std::string nums = aaCenter.AA_StringGet(message, prestr, ">");
        std::string fulstr = prestr + nums + ">";
        if (nums != "") {
            int num = atoi(nums.c_str());
            if (num > 0 && (int)conf.aa_jinrileichong.size() >= num) {
                std::pair<ObjectGuid, uint32> m = conf.aa_jinrileichong[num - 1];
                aaCenter.AA_StringReplace(message, fulstr, std::to_string(m.second));
            }
            else {
                aaCenter.AA_StringReplace(message, fulstr, "无");
            }
        }
        else {
            aaCenter.AA_StringReplace(message, fulstr, "无");
        }
    }

    if (message.find("<$任务排行姓名@") != string::npos) {
        std::string prestr = "<$任务排行姓名@";
        std::string nums = aaCenter.AA_StringGet(message, prestr, ">");
        std::string fulstr = prestr + nums + ">";
        if (nums != "") {
            int num = atoi(nums.c_str());
            if (num > 0 && (int)conf.aa_renwu.size() >= num) {
                std::pair<ObjectGuid, uint32> m = conf.aa_renwu[num - 1];
                if (Player* p = ObjectAccessor::FindPlayer(m.first)) {
                    if (p && p->IsInWorld()) {
                        std::string name = p->GetName();
                        aaCenter.AA_StringReplace(message, fulstr, name);
                    }
                }
            }
            else {
                aaCenter.AA_StringReplace(message, fulstr, "无");
            }
        }
        else {
            aaCenter.AA_StringReplace(message, fulstr, "无");
        }
    }
    if (message.find("<$任务排行数量@") != string::npos) {
        std::string prestr = "<$任务排行数量@";
        std::string nums = aaCenter.AA_StringGet(message, prestr, ">");
        std::string fulstr = prestr + nums + ">";
        if (nums != "") {
            int num = atoi(nums.c_str());
            if (num > 0 && (int)conf.aa_renwu.size() >= num) {
                std::pair<ObjectGuid, uint32> m = conf.aa_renwu[num - 1];
                aaCenter.AA_StringReplace(message, fulstr, std::to_string(m.second));
            }
            else {
                aaCenter.AA_StringReplace(message, fulstr, "无");
            }
        }
        else {
            aaCenter.AA_StringReplace(message, fulstr, "无");
        }
    }

    if (message.find("<$物品等级排行姓名@") != string::npos) {
        std::string prestr = "<$物品等级排行姓名@";
        std::string nums = aaCenter.AA_StringGet(message, prestr, ">");
        std::string fulstr = prestr + nums + ">";
        if (nums != "") {
            int num = atoi(nums.c_str());
            if (num > 0 && (int)conf.aa_level_item_ItemLevel.size() >= num) {
                std::pair<ObjectGuid, uint32> m = conf.aa_level_item_ItemLevel[num - 1];
                if (Player* p = ObjectAccessor::FindPlayer(m.first)) {
                    if (p && p->IsInWorld()) {
                        std::string name = p->GetName();
                        aaCenter.AA_StringReplace(message, fulstr, name);
                    }
                }
            }
            else {
                aaCenter.AA_StringReplace(message, fulstr, "无");
            }
        }
        else {
            aaCenter.AA_StringReplace(message, fulstr, "无");
        }
    }
    if (message.find("<$物品等级排行数量@") != string::npos) {
        std::string prestr = "<$物品等级排行数量@";
        std::string nums = aaCenter.AA_StringGet(message, prestr, ">");
        std::string fulstr = prestr + nums + ">";
        if (nums != "") {
            int num = atoi(nums.c_str());
            if (num > 0 && (int)conf.aa_level_item_ItemLevel.size() >= num) {
                std::pair<ObjectGuid, uint32> m = conf.aa_level_item_ItemLevel[num - 1];
                aaCenter.AA_StringReplace(message, fulstr, std::to_string(m.second));
            }
            else {
                aaCenter.AA_StringReplace(message, fulstr, "无");
            }
        }
        else {
            aaCenter.AA_StringReplace(message, fulstr, "无");
        }
    }

    if (message.find("<$物品品质排行姓名@") != string::npos) {
        std::string prestr = "<$物品品质排行姓名@";
        std::string nums = aaCenter.AA_StringGet(message, prestr, ">");
        std::string fulstr = prestr + nums + ">";
        if (nums != "") {
            int num = atoi(nums.c_str());
            if (num > 0 && (int)conf.aa_level_item_Quality.size() >= num) {
                std::pair<ObjectGuid, uint32> m = conf.aa_level_item_Quality[num - 1];
                if (Player* p = ObjectAccessor::FindPlayer(m.first)) {
                    if (p && p->IsInWorld()) {
                        std::string name = p->GetName();
                        aaCenter.AA_StringReplace(message, fulstr, name);
                    }
                }
            }
            else {
                aaCenter.AA_StringReplace(message, fulstr, "无");
            }
        }
        else {
            aaCenter.AA_StringReplace(message, fulstr, "无");
        }
    }
    if (message.find("<$物品品质排行数量@") != string::npos) {
        std::string prestr = "<$物品品质排行数量@";
        std::string nums = aaCenter.AA_StringGet(message, prestr, ">");
        std::string fulstr = prestr + nums + ">";
        if (nums != "") {
            int num = atoi(nums.c_str());
            if (num > 0 && (int)conf.aa_level_item_Quality.size() >= num) {
                std::pair<ObjectGuid, uint32> m = conf.aa_level_item_Quality[num - 1];
                aaCenter.AA_StringReplace(message, fulstr, std::to_string(m.second));
            }
            else {
                aaCenter.AA_StringReplace(message, fulstr, "无");
            }
        }
        else {
            aaCenter.AA_StringReplace(message, fulstr, "无");
        }
    }

    if (message.find("<$物品鉴定等级排行姓名@") != string::npos) {
        std::string prestr = "<$物品鉴定等级排行姓名@";
        std::string nums = aaCenter.AA_StringGet(message, prestr, ">");
        std::string fulstr = prestr + nums + ">";
        if (nums != "") {
            int num = atoi(nums.c_str());
            if (num > 0 && (int)conf.aa_level_item_jd.size() >= num) {
                std::pair<ObjectGuid, uint32> m = conf.aa_level_item_jd[num - 1];
                if (Player* p = ObjectAccessor::FindPlayer(m.first)) {
                    if (p && p->IsInWorld()) {
                        std::string name = p->GetName();
                        aaCenter.AA_StringReplace(message, fulstr, name);
                    }
                }
            }
            else {
                aaCenter.AA_StringReplace(message, fulstr, "无");
            }
        }
        else {
            aaCenter.AA_StringReplace(message, fulstr, "无");
        }
    }
    if (message.find("<$物品鉴定等级排行数量@") != string::npos) {
        std::string prestr = "<$物品鉴定等级排行数量@";
        std::string nums = aaCenter.AA_StringGet(message, prestr, ">");
        std::string fulstr = prestr + nums + ">";
        if (nums != "") {
            int num = atoi(nums.c_str());
            if (num > 0 && (int)conf.aa_level_item_jd.size() >= num) {
                std::pair<ObjectGuid, uint32> m = conf.aa_level_item_jd[num - 1];
                aaCenter.AA_StringReplace(message, fulstr, std::to_string(m.second));
            }
            else {
                aaCenter.AA_StringReplace(message, fulstr, "无");
            }
        }
        else {
            aaCenter.AA_StringReplace(message, fulstr, "无");
        }
    }

    if (message.find("<$物品强化等级排行姓名@") != string::npos) {
        std::string prestr = "<$物品强化等级排行姓名@";
        std::string nums = aaCenter.AA_StringGet(message, prestr, ">");
        std::string fulstr = prestr + nums + ">";
        if (nums != "") {
            int num = atoi(nums.c_str());
            if (num > 0 && (int)conf.aa_level_item_qh.size() >= num) {
                std::pair<ObjectGuid, uint32> m = conf.aa_level_item_qh[num - 1];
                if (Player* p = ObjectAccessor::FindPlayer(m.first)) {
                    if (p && p->IsInWorld()) {
                        std::string name = p->GetName();
                        aaCenter.AA_StringReplace(message, fulstr, name);
                    }
                }
            }
            else {
                aaCenter.AA_StringReplace(message, fulstr, "无");
            }
        }
        else {
            aaCenter.AA_StringReplace(message, fulstr, "无");
        }
    }
    if (message.find("<$物品强化等级排行数量@") != string::npos) {
        std::string prestr = "<$物品强化等级排行数量@";
        std::string nums = aaCenter.AA_StringGet(message, prestr, ">");
        std::string fulstr = prestr + nums + ">";
        if (nums != "") {
            int num = atoi(nums.c_str());
            if (num > 0 && (int)conf.aa_level_item_qh.size() >= num) {
                std::pair<ObjectGuid, uint32> m = conf.aa_level_item_qh[num - 1];
                aaCenter.AA_StringReplace(message, fulstr, std::to_string(m.second));
            }
            else {
                aaCenter.AA_StringReplace(message, fulstr, "无");
            }
        }
        else {
            aaCenter.AA_StringReplace(message, fulstr, "无");
        }
    }

    if (message.find("<$物品成长等级排行姓名@") != string::npos) {
        std::string prestr = "<$物品成长等级排行姓名@";
        std::string nums = aaCenter.AA_StringGet(message, prestr, ">");
        std::string fulstr = prestr + nums + ">";
        if (nums != "") {
            int num = atoi(nums.c_str());
            if (num > 0 && (int)conf.aa_level_item_cz.size() >= num) {
                std::pair<ObjectGuid, uint32> m = conf.aa_level_item_cz[num - 1];
                if (Player* p = ObjectAccessor::FindPlayer(m.first)) {
                    if (p && p->IsInWorld()) {
                        std::string name = p->GetName();
                        aaCenter.AA_StringReplace(message, fulstr, name);
                    }
                }
            }
            else {
                aaCenter.AA_StringReplace(message, fulstr, "无");
            }
        }
        else {
            aaCenter.AA_StringReplace(message, fulstr, "无");
        }
    }
    if (message.find("<$物品成长等级排行数量@") != string::npos) {
        std::string prestr = "<$物品成长等级排行数量@";
        std::string nums = aaCenter.AA_StringGet(message, prestr, ">");
        std::string fulstr = prestr + nums + ">";
        if (nums != "") {
            int num = atoi(nums.c_str());
            if (num > 0 && (int)conf.aa_level_item_cz.size() >= num) {
                std::pair<ObjectGuid, uint32> m = conf.aa_level_item_cz[num - 1];
                aaCenter.AA_StringReplace(message, fulstr, std::to_string(m.second));
            }
            else {
                aaCenter.AA_StringReplace(message, fulstr, "无");
            }
        }
        else {
            aaCenter.AA_StringReplace(message, fulstr, "无");
        }
    }

    if (message.find("<$物品觉醒属性等级排行姓名@") != string::npos) {
        std::string prestr = "<$物品觉醒属性等级排行姓名@";
        std::string nums = aaCenter.AA_StringGet(message, prestr, ">");
        std::string fulstr = prestr + nums + ">";
        if (nums != "") {
            int num = atoi(nums.c_str());
            if (num > 0 && (int)conf.aa_level_item_jxsx.size() >= num) {
                std::pair<ObjectGuid, uint32> m = conf.aa_level_item_jxsx[num - 1];
                if (Player* p = ObjectAccessor::FindPlayer(m.first)) {
                    if (p && p->IsInWorld()) {
                        std::string name = p->GetName();
                        aaCenter.AA_StringReplace(message, fulstr, name);
                    }
                }
            }
            else {
                aaCenter.AA_StringReplace(message, fulstr, "无");
            }
        }
        else {
            aaCenter.AA_StringReplace(message, fulstr, "无");
        }
    }
    if (message.find("<$物品觉醒属性等级排行数量@") != string::npos) {
        std::string prestr = "<$物品觉醒属性等级排行数量@";
        std::string nums = aaCenter.AA_StringGet(message, prestr, ">");
        std::string fulstr = prestr + nums + ">";
        if (nums != "") {
            int num = atoi(nums.c_str());
            if (num > 0 && (int)conf.aa_level_item_jxsx.size() >= num) {
                std::pair<ObjectGuid, uint32> m = conf.aa_level_item_jxsx[num - 1];
                aaCenter.AA_StringReplace(message, fulstr, std::to_string(m.second));
            }
            else {
                aaCenter.AA_StringReplace(message, fulstr, "无");
            }
        }
        else {
            aaCenter.AA_StringReplace(message, fulstr, "无");
        }
    }

    if (message.find("<$物品觉醒技能等级排行姓名@") != string::npos) {
        std::string prestr = "<$物品觉醒技能等级排行姓名@";
        std::string nums = aaCenter.AA_StringGet(message, prestr, ">");
        std::string fulstr = prestr + nums + ">";
        if (nums != "") {
            int num = atoi(nums.c_str());
            if (num > 0 && (int)conf.aa_level_item_jxjn.size() >= num) {
                std::pair<ObjectGuid, uint32> m = conf.aa_level_item_jxjn[num - 1];
                if (Player* p = ObjectAccessor::FindPlayer(m.first)) {
                    if (p && p->IsInWorld()) {
                        std::string name = p->GetName();
                        aaCenter.AA_StringReplace(message, fulstr, name);
                    }
                }
            }
            else {
                aaCenter.AA_StringReplace(message, fulstr, "无");
            }
        }
        else {
            aaCenter.AA_StringReplace(message, fulstr, "无");
        }
    }
    if (message.find("<$物品觉醒技能等级排行数量@") != string::npos) {
        std::string prestr = "<$物品觉醒技能等级排行数量@";
        std::string nums = aaCenter.AA_StringGet(message, prestr, ">");
        std::string fulstr = prestr + nums + ">";
        if (nums != "") {
            int num = atoi(nums.c_str());
            if (num > 0 && (int)conf.aa_level_item_jxjn.size() >= num) {
                std::pair<ObjectGuid, uint32> m = conf.aa_level_item_jxjn[num - 1];
                aaCenter.AA_StringReplace(message, fulstr, std::to_string(m.second));
            }
            else {
                aaCenter.AA_StringReplace(message, fulstr, "无");
            }
        }
        else {
            aaCenter.AA_StringReplace(message, fulstr, "无");
        }
    }

    if (message.find("<$宠物进化等级排行姓名@") != string::npos) {
        std::string prestr = "<$宠物进化等级排行姓名@";
        std::string nums = aaCenter.AA_StringGet(message, prestr, ">");
        std::string fulstr = prestr + nums + ">";
        if (nums != "") {
            int num = atoi(nums.c_str());
            if (num > 0 && (int)conf.aa_level_pet_jh.size() >= num) {
                std::pair<ObjectGuid, uint32> m = conf.aa_level_pet_jh[num - 1];
                if (Player* p = ObjectAccessor::FindPlayer(m.first)) {
                    if (p && p->IsInWorld()) {
                        std::string name = p->GetName();
                        aaCenter.AA_StringReplace(message, fulstr, name);
                    }
                }
            }
            else {
                aaCenter.AA_StringReplace(message, fulstr, "无");
            }
        }
        else {
            aaCenter.AA_StringReplace(message, fulstr, "无");
        }
    }
    if (message.find("<$宠物进化等级排行数量@") != string::npos) {
        std::string prestr = "<$宠物进化等级排行数量@";
        std::string nums = aaCenter.AA_StringGet(message, prestr, ">");
        std::string fulstr = prestr + nums + ">";
        if (nums != "") {
            int num = atoi(nums.c_str());
            if (num > 0 && (int)conf.aa_level_pet_jh.size() >= num) {
                std::pair<ObjectGuid, uint32> m = conf.aa_level_pet_jh[num - 1];
                aaCenter.AA_StringReplace(message, fulstr, std::to_string(m.second));
            }
            else {
                aaCenter.AA_StringReplace(message, fulstr, "无");
            }
        }
        else {
            aaCenter.AA_StringReplace(message, fulstr, "无");
        }
    }

    if (message.find("<$宠物强化等级排行姓名@") != string::npos) {
        std::string prestr = "<$宠物强化等级排行姓名@";
        std::string nums = aaCenter.AA_StringGet(message, prestr, ">");
        std::string fulstr = prestr + nums + ">";
        if (nums != "") {
            int num = atoi(nums.c_str());
            if (num > 0 && (int)conf.aa_level_pet_qh.size() >= num) {
                std::pair<ObjectGuid, uint32> m = conf.aa_level_pet_qh[num - 1];
                if (Player* p = ObjectAccessor::FindPlayer(m.first)) {
                    if (p && p->IsInWorld()) {
                        std::string name = p->GetName();
                        aaCenter.AA_StringReplace(message, fulstr, name);
                    }
                }
            }
            else {
                aaCenter.AA_StringReplace(message, fulstr, "无");
            }
        }
        else {
            aaCenter.AA_StringReplace(message, fulstr, "无");
        }
    }
    if (message.find("<$宠物强化等级排行数量@") != string::npos) {
        std::string prestr = "<$宠物强化等级排行数量@";
        std::string nums = aaCenter.AA_StringGet(message, prestr, ">");
        std::string fulstr = prestr + nums + ">";
        if (nums != "") {
            int num = atoi(nums.c_str());
            if (num > 0 && (int)conf.aa_level_pet_qh.size() >= num) {
                std::pair<ObjectGuid, uint32> m = conf.aa_level_pet_qh[num - 1];
                aaCenter.AA_StringReplace(message, fulstr, std::to_string(m.second));
            }
            else {
                aaCenter.AA_StringReplace(message, fulstr, "无");
            }
        }
        else {
            aaCenter.AA_StringReplace(message, fulstr, "无");
        }
    }

    if (message.find("<$宠物觉醒等级排行姓名@") != string::npos) {
        std::string prestr = "<$宠物觉醒等级排行姓名@";
        std::string nums = aaCenter.AA_StringGet(message, prestr, ">");
        std::string fulstr = prestr + nums + ">";
        if (nums != "") {
            int num = atoi(nums.c_str());
            if (num > 0 && (int)conf.aa_level_pet_jx.size() >= num) {
                std::pair<ObjectGuid, uint32> m = conf.aa_level_pet_jx[num - 1];
                if (Player* p = ObjectAccessor::FindPlayer(m.first)) {
                    if (p && p->IsInWorld()) {
                        std::string name = p->GetName();
                        aaCenter.AA_StringReplace(message, fulstr, name);
                    }
                }
            }
            else {
                aaCenter.AA_StringReplace(message, fulstr, "无");
            }
        }
        else {
            aaCenter.AA_StringReplace(message, fulstr, "无");
        }
    }
    if (message.find("<$宠物觉醒等级排行数量@") != string::npos) {
        std::string prestr = "<$宠物觉醒等级排行数量@";
        std::string nums = aaCenter.AA_StringGet(message, prestr, ">");
        std::string fulstr = prestr + nums + ">";
        if (nums != "") {
            int num = atoi(nums.c_str());
            if (num > 0 && (int)conf.aa_level_pet_jx.size() >= num) {
                std::pair<ObjectGuid, uint32> m = conf.aa_level_pet_jx[num - 1];
                aaCenter.AA_StringReplace(message, fulstr, std::to_string(m.second));
            }
            else {
                aaCenter.AA_StringReplace(message, fulstr, "无");
            }
        }
        else {
            aaCenter.AA_StringReplace(message, fulstr, "无");
        }
    }

    return "";
}

void AACenter::AA_PaihangReward(bool isAura)
{
    std::vector<uint32> spell_all; spell_all.clear();
    if (isAura) {
        for (auto it : aaCenter.aa_paihangxs) {
            if (it.first > 0) {
                for (auto it1 : it.second) {
                    AA_PaihangX conf = it1.second;
                    if (conf.auras != "" && conf.auras != "0") {
                        std::vector<int32> spells; spells.clear();
                        aaCenter.AA_StringToVectorInt(conf.auras, spells, ",");
                        if (spells.size() > 0) {
                            for (auto s : spells) {
                                if (s > 0) {
                                    spell_all.push_back(s);
                                }
                            }
                        }
                    }
                }
            }
        }
        for (auto it : aaCenter.aa_paihangx_guids) {
            if (it.first > 0) {
                for (auto it1 : it.second) {
                    AA_PaihangX conf = it1.second;
                    if (conf.auras != "" && conf.auras != "0") {
                        std::vector<int32> spells; spells.clear();
                        aaCenter.AA_StringToVectorInt(conf.auras, spells, ",");
                        if (spells.size() > 0) {
                            for (auto s : spells) {
                                if (s > 0) {
                                    spell_all.push_back(s);
                                }
                            }
                        }
                    }
                }
            }
        }
        for (auto it : aaCenter.aa_paihangx_guids) {
            if (it.first > 0) {
                for (auto it1 : it.second) {
                    AA_PaihangX conf = it1.second;
                    if (conf.auras != "" && conf.auras != "0") {
                        std::vector<int32> spells; spells.clear();
                        aaCenter.AA_StringToVectorInt(conf.auras, spells, ",");
                        if (spells.size() > 0) {
                            for (auto s : spells) {
                                if (s > 0) {
                                    spell_all.push_back(s);
                                }
                            }
                        }
                    }
                }
            }
        }
        std::set<Player*> players = aaCenter.GetOnlinePlayers();
        for (auto p : players) {
            for (auto itr : spell_all) {
                if (itr > 0) {
                    if (p->HasAura(itr)) {
                        p->RemoveAura(itr);
                    }
                }
            }
        }
    }
    AA_Paihang p_conf = aaCenter.AA_GetPaihangs();
    for (auto itr : p_conf.aa_diy_guids) {
        std::string diy_key = itr.first;
        std::vector<std::pair<ObjectGuid, uint32>> diy_value = itr.second;
        for (size_t i = 0; i < diy_value.size(); i++) {
            //获取玩家，和数值
            std::pair<ObjectGuid, uint32> p = diy_value[i];
            Player* player = ObjectAccessor::FindPlayer(p.first);
            if (!player || !player->IsInWorld()) {
                continue;
            }
            if (p.second <= 0) {
                continue;
            }
            //获取配置
            AA_PaihangX px_conf = aaCenter.aa_paihangx_guids[i + 1][diy_key];
            if (px_conf.id != i + 1) {
                continue;
            }
            if (isAura) {
                if (px_conf.auras != "" && px_conf.auras != "0") {
                    std::vector<int32> spells; spells.clear();
                    aaCenter.AA_StringToVectorInt(px_conf.auras, spells, ",");
                    for (auto itr : spells) {
                        if (itr > 0) {
                            if (!player->HasAura(itr)) {
                                player->AddAura(itr, player);
                            }
                        }
                    }
                }
                continue;
            }
            if (px_conf.reward == 0) {
                continue;
            }
            aaCenter.M_Reward(player, px_conf.reward, 1);
            if (px_conf.notice == 0) {
                continue;
            }
            AA_Message aa_message;
            AA_Notice notice = aaCenter.aa_notices[px_conf.notice];
            aaCenter.AA_SendNotice(player, notice, true, aa_message);
        }
    }
    for (auto itr : p_conf.aa_diy_accounts) {
        std::string diy_key = itr.first;
        std::vector<std::pair<ObjectGuid, uint32>> diy_value = itr.second;
        for (size_t i = 0; i < diy_value.size(); i++) {
            //获取玩家，和数值
            std::pair<ObjectGuid, uint32> p = diy_value[i];
            Player* player = ObjectAccessor::FindPlayer(p.first);
            if (!player || !player->IsInWorld()) {
                continue;
            }
            if (p.second <= 0) {
                continue;
            }
            //获取配置
            AA_PaihangX px_conf = aaCenter.aa_paihangx_accounts[i + 1][diy_key];
            if (px_conf.id != i + 1) {
                continue;
            }
            if (isAura) {
                if (px_conf.auras != "" && px_conf.auras != "0") {
                    std::vector<int32> spells; spells.clear();
                    aaCenter.AA_StringToVectorInt(px_conf.auras, spells, ",");
                    for (auto itr : spells) {
                        if (itr > 0) {
                            if (!player->HasAura(itr)) {
                                player->AddAura(itr, player);
                            }
                        }
                    }
                }
                continue;
            }
            if (px_conf.reward == 0) {
                continue;
            }
            aaCenter.M_Reward(player, px_conf.reward, 1);
            if (px_conf.notice == 0) {
                continue;
            }
            AA_Message aa_message;
            AA_Notice notice = aaCenter.aa_notices[px_conf.notice];
            aaCenter.AA_SendNotice(player, notice, true, aa_message);
        }
    }
    for (size_t i = 0; i < p_conf.aa_money.size(); i++) {
        //获取玩家，和数值
        std::pair<ObjectGuid, uint32> p = p_conf.aa_money[i];
        Player* player = ObjectAccessor::FindPlayer(p.first);
        if (!player || !player->IsInWorld()) {
            continue;
        }
        if (p.second <= 0) {
            continue;
        }
        //获取配置
        AA_PaihangX px_conf = aaCenter.aa_paihangxs[i + 1]["金币"];
        if (px_conf.id != i + 1) {
            continue;
        }
        if (isAura) {
            if (px_conf.auras != "" && px_conf.auras != "0") {
                std::vector<int32> spells; spells.clear();
                aaCenter.AA_StringToVectorInt(px_conf.auras, spells, ",");
                for (auto itr : spells) {
                    if (itr > 0) {
                        if (!player->HasAura(itr)) {
                            player->AddAura(itr, player);
                        }
                    }
                }
            }
            continue;
        }
        if (px_conf.reward == 0) {
            continue;
        }
        aaCenter.M_Reward(player, px_conf.reward, 1);
        if (px_conf.notice == 0) {
            continue;
        }
        AA_Message aa_message;
        AA_Notice notice = aaCenter.aa_notices[px_conf.notice];
        aaCenter.AA_SendNotice(player, notice, true, aa_message);
    }
    for (size_t i = 0; i < p_conf.aa_health.size(); i++) {
        //获取玩家，和数值
        std::pair<ObjectGuid, uint32> p = p_conf.aa_health[i];
        Player* player = ObjectAccessor::FindPlayer(p.first);
        if (!player || !player->IsInWorld()) {
            continue;
        }
        if (p.second <= 0) {
            continue;
        }
        //获取配置
        AA_PaihangX px_conf = aaCenter.aa_paihangxs[i + 1]["生命"];
        if (px_conf.id != i + 1) {
            continue;
        }
        if (isAura) {
            if (px_conf.auras != "" && px_conf.auras != "0") {
                std::vector<int32> spells; spells.clear();
                aaCenter.AA_StringToVectorInt(px_conf.auras, spells, ",");
                for (auto itr : spells) {
                    if (itr > 0) {
                        if (!player->HasAura(itr)) {
                            player->AddAura(itr, player);
                        }
                    }
                }
            }
            continue;
        }
        if (px_conf.reward == 0) {
            continue;
        }
        aaCenter.M_Reward(player, px_conf.reward, 1);
        if (px_conf.notice == 0) {
            continue;
        }
        AA_Message aa_message;
        AA_Notice notice = aaCenter.aa_notices[px_conf.notice];
        aaCenter.AA_SendNotice(player, notice, true, aa_message);
    }
    for (size_t i = 0; i < p_conf.aa_df_level.size(); i++) {
        //获取玩家，和数值
        std::pair<ObjectGuid, uint32> p = p_conf.aa_df_level[i];
        Player* player = ObjectAccessor::FindPlayer(p.first);
        if (!player || !player->IsInWorld()) {
            continue;
        }
        if (p.second <= 0) {
            continue;
        }
        //获取配置
        AA_PaihangX px_conf = aaCenter.aa_paihangxs[i + 1]["巅峰等级"];
        if (px_conf.id != i + 1) {
            continue;
        }
        if (isAura) {
            if (px_conf.auras != "" && px_conf.auras != "0") {
                std::vector<int32> spells; spells.clear();
                aaCenter.AA_StringToVectorInt(px_conf.auras, spells, ",");
                for (auto itr : spells) {
                    if (itr > 0) {
                        if (!player->HasAura(itr)) {
                            player->AddAura(itr, player);
                        }
                    }
                }
            }
            continue;
        }
        if (px_conf.reward == 0) {
            continue;
        }
        aaCenter.M_Reward(player, px_conf.reward, 1);
        if (px_conf.notice == 0) {
            continue;
        }
        AA_Message aa_message;
        AA_Notice notice = aaCenter.aa_notices[px_conf.notice];
        aaCenter.AA_SendNotice(player, notice, true, aa_message);
    }
    for (size_t i = 0; i < p_conf.aa_jx_level.size(); i++) {
        //获取玩家，和数值
        std::pair<ObjectGuid, uint32> p = p_conf.aa_jx_level[i];
        Player* player = ObjectAccessor::FindPlayer(p.first);
        if (!player || !player->IsInWorld()) {
            continue;
        }
        if (p.second <= 0) {
            continue;
        }
        //获取配置
        AA_PaihangX px_conf = aaCenter.aa_paihangxs[i + 1]["军衔等级"];
        if (px_conf.id != i + 1) {
            continue;
        }
        if (isAura) {
            if (px_conf.auras != "" && px_conf.auras != "0") {
                std::vector<int32> spells; spells.clear();
                aaCenter.AA_StringToVectorInt(px_conf.auras, spells, ",");
                for (auto itr : spells) {
                    if (itr > 0) {
                        if (!player->HasAura(itr)) {
                            player->AddAura(itr, player);
                        }
                    }
                }
            }
            continue;
        }
        if (px_conf.reward == 0) {
            continue;
        }
        aaCenter.M_Reward(player, px_conf.reward, 1);
        if (px_conf.notice == 0) {
            continue;
        }
        AA_Message aa_message;
        AA_Notice notice = aaCenter.aa_notices[px_conf.notice];
        aaCenter.AA_SendNotice(player, notice, true, aa_message);
    }
    for (size_t i = 0; i < p_conf.aa_dq_level.size(); i++) {
        //获取玩家，和数值
        std::pair<ObjectGuid, uint32> p = p_conf.aa_dq_level[i];
        Player* player = ObjectAccessor::FindPlayer(p.first);
        if (!player || !player->IsInWorld()) {
            continue;
        }
        if (p.second <= 0) {
            continue;
        }
        //获取配置
        AA_PaihangX px_conf = aaCenter.aa_paihangxs[i + 1]["斗气等级"];
        if (px_conf.id != i + 1) {
            continue;
        }
        if (isAura) {
            if (px_conf.auras != "" && px_conf.auras != "0") {
                std::vector<int32> spells; spells.clear();
                aaCenter.AA_StringToVectorInt(px_conf.auras, spells, ",");
                for (auto itr : spells) {
                    if (itr > 0) {
                        if (!player->HasAura(itr)) {
                            player->AddAura(itr, player);
                        }
                    }
                }
            }
            continue;
        }
        if (px_conf.reward == 0) {
            continue;
        }
        aaCenter.M_Reward(player, px_conf.reward, 1);
        if (px_conf.notice == 0) {
            continue;
        }
        AA_Message aa_message;
        AA_Notice notice = aaCenter.aa_notices[px_conf.notice];
        aaCenter.AA_SendNotice(player, notice, true, aa_message);
    }
    for (size_t i = 0; i < p_conf.aa_leichong.size(); i++) {
        //获取玩家，和数值
        std::pair<ObjectGuid, uint32> p = p_conf.aa_leichong[i];
        Player* player = ObjectAccessor::FindPlayer(p.first);
        if (!player || !player->IsInWorld()) {
            continue;
        }
        if (p.second <= 0) {
            continue;
        }
        //获取配置
        AA_PaihangX px_conf = aaCenter.aa_paihangxs[i + 1]["累充积分"];
        if (px_conf.id != i + 1) {
            continue;
        }
        if (isAura) {
            if (px_conf.auras != "" && px_conf.auras != "0") {
                std::vector<int32> spells; spells.clear();
                aaCenter.AA_StringToVectorInt(px_conf.auras, spells, ",");
                for (auto itr : spells) {
                    if (itr > 0) {
                        if (!player->HasAura(itr)) {
                            player->AddAura(itr, player);
                        }
                    }
                }
            }
            continue;
        }
        if (px_conf.reward == 0) {
            continue;
        }
        aaCenter.M_Reward(player, px_conf.reward, 1);
        if (px_conf.notice == 0) {
            continue;
        }
        AA_Message aa_message;
        AA_Notice notice = aaCenter.aa_notices[px_conf.notice];
        aaCenter.AA_SendNotice(player, notice, true, aa_message);
    }
    for (size_t i = 0; i < p_conf.aa_jinrileichong.size(); i++) {
        //获取玩家，和数值
        std::pair<ObjectGuid, uint32> p = p_conf.aa_jinrileichong[i];
        Player* player = ObjectAccessor::FindPlayer(p.first);
        if (!player || !player->IsInWorld()) {
            continue;
        }
        if (p.second <= 0) {
            continue;
        }
        //获取配置
        AA_PaihangX px_conf = aaCenter.aa_paihangxs[i + 1]["今日累充积分"];
        if (px_conf.id != i + 1) {
            continue;
        }
        if (isAura) {
            if (px_conf.auras != "" && px_conf.auras != "0") {
                std::vector<int32> spells; spells.clear();
                aaCenter.AA_StringToVectorInt(px_conf.auras, spells, ",");
                for (auto itr : spells) {
                    if (itr > 0) {
                        if (!player->HasAura(itr)) {
                            player->AddAura(itr, player);
                        }
                    }
                }
            }
            continue;
        }
        if (px_conf.reward == 0) {
            continue;
        }
        aaCenter.M_Reward(player, px_conf.reward, 1);
        if (px_conf.notice == 0) {
            continue;
        }
        AA_Message aa_message;
        AA_Notice notice = aaCenter.aa_notices[px_conf.notice];
        aaCenter.AA_SendNotice(player, notice, true, aa_message);
    }
    for (size_t i = 0; i < p_conf.aa_zaixianshijian.size(); i++) {
        //获取玩家，和数值
        std::pair<ObjectGuid, uint32> p = p_conf.aa_zaixianshijian[i];
        Player* player = ObjectAccessor::FindPlayer(p.first);
        if (!player || !player->IsInWorld()) {
            continue;
        }
        if (p.second <= 0) {
            continue;
        }
        //获取配置
        AA_PaihangX px_conf = aaCenter.aa_paihangxs[i + 1]["在线时间"];
        if (px_conf.id != i + 1) {
            continue;
        }
        if (isAura) {
            if (px_conf.auras != "" && px_conf.auras != "0") {
                std::vector<int32> spells; spells.clear();
                aaCenter.AA_StringToVectorInt(px_conf.auras, spells, ",");
                for (auto itr : spells) {
                    if (itr > 0) {
                        if (!player->HasAura(itr)) {
                            player->AddAura(itr, player);
                        }
                    }
                }
            }
            continue;
        }
        if (px_conf.reward == 0) {
            continue;
        }
        aaCenter.M_Reward(player, px_conf.reward, 1);
        if (px_conf.notice == 0) {
            continue;
        }
        AA_Message aa_message;
        AA_Notice notice = aaCenter.aa_notices[px_conf.notice];
        aaCenter.AA_SendNotice(player, notice, true, aa_message);
    }
    for (size_t i = 0; i < p_conf.aa_jisha.size(); i++) {
        //获取玩家，和数值
        std::pair<ObjectGuid, uint32> p = p_conf.aa_jisha[i];
        Player* player = ObjectAccessor::FindPlayer(p.first);
        if (!player || !player->IsInWorld()) {
            continue;
        }
        if (p.second <= 0) {
            continue;
        }
        //获取配置
        AA_PaihangX px_conf = aaCenter.aa_paihangxs[i + 1]["杀敌数量"];
        if (px_conf.id != i + 1) {
            continue;
        }
        if (isAura) {
            if (px_conf.auras != "" && px_conf.auras != "0") {
                std::vector<int32> spells; spells.clear();
                aaCenter.AA_StringToVectorInt(px_conf.auras, spells, ",");
                for (auto itr : spells) {
                    if (itr > 0) {
                        if (!player->HasAura(itr)) {
                            player->AddAura(itr, player);
                        }
                    }
                }
            }
            continue;
        }
        if (px_conf.reward == 0) {
            continue;
        }
        aaCenter.M_Reward(player, px_conf.reward, 1);
        if (px_conf.notice == 0) {
            continue;
        }
        AA_Message aa_message;
        AA_Notice notice = aaCenter.aa_notices[px_conf.notice];
        aaCenter.AA_SendNotice(player, notice, true, aa_message);
    }
    for (size_t i = 0; i < p_conf.aa_renwu.size(); i++) {
        //获取玩家，和数值
        std::pair<ObjectGuid, uint32> p = p_conf.aa_renwu[i];
        Player* player = ObjectAccessor::FindPlayer(p.first);
        if (!player || !player->IsInWorld()) {
            continue;
        }
        if (p.second <= 0) {
            continue;
        }
        //获取配置
        AA_PaihangX px_conf = aaCenter.aa_paihangxs[i + 1]["任务数量"];
        if (px_conf.id != i + 1) {
            continue;
        }
        if (isAura) {
            if (px_conf.auras != "" && px_conf.auras != "0") {
                std::vector<int32> spells; spells.clear();
                aaCenter.AA_StringToVectorInt(px_conf.auras, spells, ",");
                for (auto itr : spells) {
                    if (itr > 0) {
                        if (!player->HasAura(itr)) {
                            player->AddAura(itr, player);
                        }
                    }
                }
            }
            continue;
        }
        if (px_conf.reward == 0) {
            continue;
        }
        aaCenter.M_Reward(player, px_conf.reward, 1);
        if (px_conf.notice == 0) {
            continue;
        }
        AA_Message aa_message;
        AA_Notice notice = aaCenter.aa_notices[px_conf.notice];
        aaCenter.AA_SendNotice(player, notice, true, aa_message);
    }
    for (size_t i = 0; i < p_conf.aa_level_item_ItemLevel.size(); i++) {
        //获取玩家，和数值
        std::pair<ObjectGuid, uint32> p = p_conf.aa_level_item_ItemLevel[i];
        Player* player = ObjectAccessor::FindPlayer(p.first);
        if (!player || !player->IsInWorld()) {
            continue;
        }
        if (p.second <= 0) {
            continue;
        }
        //获取配置
        AA_PaihangX px_conf = aaCenter.aa_paihangxs[i + 1]["物品等级数量"];
        if (px_conf.id != i + 1) {
            continue;
        }
        if (isAura) {
            if (px_conf.auras != "" && px_conf.auras != "0") {
                std::vector<int32> spells; spells.clear();
                aaCenter.AA_StringToVectorInt(px_conf.auras, spells, ",");
                for (auto itr : spells) {
                    if (itr > 0) {
                        if (!player->HasAura(itr)) {
                            player->AddAura(itr, player);
                        }
                    }
                }
            }
            continue;
        }
        if (px_conf.reward == 0) {
            continue;
        }
        aaCenter.M_Reward(player, px_conf.reward, 1);
        if (px_conf.notice == 0) {
            continue;
        }
        AA_Message aa_message;
        AA_Notice notice = aaCenter.aa_notices[px_conf.notice];
        aaCenter.AA_SendNotice(player, notice, true, aa_message);
    }
    for (size_t i = 0; i < p_conf.aa_level_item_Quality.size(); i++) {
        //获取玩家，和数值
        std::pair<ObjectGuid, uint32> p = p_conf.aa_level_item_Quality[i];
        Player* player = ObjectAccessor::FindPlayer(p.first);
        if (!player || !player->IsInWorld()) {
            continue;
        }
        if (p.second <= 0) {
            continue;
        }
        //获取配置
        AA_PaihangX px_conf = aaCenter.aa_paihangxs[i + 1]["物品品质数量"];
        if (px_conf.id != i + 1) {
            continue;
        }
        if (isAura) {
            if (px_conf.auras != "" && px_conf.auras != "0") {
                std::vector<int32> spells; spells.clear();
                aaCenter.AA_StringToVectorInt(px_conf.auras, spells, ",");
                for (auto itr : spells) {
                    if (itr > 0) {
                        if (!player->HasAura(itr)) {
                            player->AddAura(itr, player);
                        }
                    }
                }
            }
            continue;
        }
        if (px_conf.reward == 0) {
            continue;
        }
        aaCenter.M_Reward(player, px_conf.reward, 1);
        if (px_conf.notice == 0) {
            continue;
        }
        AA_Message aa_message;
        AA_Notice notice = aaCenter.aa_notices[px_conf.notice];
        aaCenter.AA_SendNotice(player, notice, true, aa_message);
    }
    for (size_t i = 0; i < p_conf.aa_level_item_jd.size(); i++) {
        //获取玩家，和数值
        std::pair<ObjectGuid, uint32> p = p_conf.aa_level_item_jd[i];
        Player* player = ObjectAccessor::FindPlayer(p.first);
        if (!player || !player->IsInWorld()) {
            continue;
        }
        if (p.second <= 0) {
            continue;
        }
        //获取配置
        AA_PaihangX px_conf = aaCenter.aa_paihangxs[i + 1]["物品鉴定等级数量"];
        if (px_conf.id != i + 1) {
            continue;
        }
        if (isAura) {
            if (px_conf.auras != "" && px_conf.auras != "0") {
                std::vector<int32> spells; spells.clear();
                aaCenter.AA_StringToVectorInt(px_conf.auras, spells, ",");
                for (auto itr : spells) {
                    if (itr > 0) {
                        if (!player->HasAura(itr)) {
                            player->AddAura(itr, player);
                        }
                    }
                }
            }
            continue;
        }
        if (px_conf.reward == 0) {
            continue;
        }
        aaCenter.M_Reward(player, px_conf.reward, 1);
        if (px_conf.notice == 0) {
            continue;
        }
        AA_Message aa_message;
        AA_Notice notice = aaCenter.aa_notices[px_conf.notice];
        aaCenter.AA_SendNotice(player, notice, true, aa_message);
    }
    for (size_t i = 0; i < p_conf.aa_level_item_qh.size(); i++) {
        //获取玩家，和数值
        std::pair<ObjectGuid, uint32> p = p_conf.aa_level_item_qh[i];
        Player* player = ObjectAccessor::FindPlayer(p.first);
        if (!player || !player->IsInWorld()) {
            continue;
        }
        if (p.second <= 0) {
            continue;
        }
        //获取配置
        AA_PaihangX px_conf = aaCenter.aa_paihangxs[i + 1]["物品强化等级数量"];
        if (px_conf.id != i + 1) {
            continue;
        }
        if (isAura) {
            if (px_conf.auras != "" && px_conf.auras != "0") {
                std::vector<int32> spells; spells.clear();
                aaCenter.AA_StringToVectorInt(px_conf.auras, spells, ",");
                for (auto itr : spells) {
                    if (itr > 0) {
                        if (!player->HasAura(itr)) {
                            player->AddAura(itr, player);
                        }
                    }
                }
            }
            continue;
        }
        if (px_conf.reward == 0) {
            continue;
        }
        aaCenter.M_Reward(player, px_conf.reward, 1);
        if (px_conf.notice == 0) {
            continue;
        }
        AA_Message aa_message;
        AA_Notice notice = aaCenter.aa_notices[px_conf.notice];
        aaCenter.AA_SendNotice(player, notice, true, aa_message);
    }
    for (size_t i = 0; i < p_conf.aa_level_item_cz.size(); i++) {
        //获取玩家，和数值
        std::pair<ObjectGuid, uint32> p = p_conf.aa_level_item_cz[i];
        Player* player = ObjectAccessor::FindPlayer(p.first);
        if (!player || !player->IsInWorld()) {
            continue;
        }
        if (p.second <= 0) {
            continue;
        }
        //获取配置
        AA_PaihangX px_conf = aaCenter.aa_paihangxs[i + 1]["物品成长等级数量"];
        if (px_conf.id != i + 1) {
            continue;
        }
        if (isAura) {
            if (px_conf.auras != "" && px_conf.auras != "0") {
                std::vector<int32> spells; spells.clear();
                aaCenter.AA_StringToVectorInt(px_conf.auras, spells, ",");
                for (auto itr : spells) {
                    if (itr > 0) {
                        if (!player->HasAura(itr)) {
                            player->AddAura(itr, player);
                        }
                    }
                }
            }
            continue;
        }
        if (px_conf.reward == 0) {
            continue;
        }
        aaCenter.M_Reward(player, px_conf.reward, 1);
        if (px_conf.notice == 0) {
            continue;
        }
        AA_Message aa_message;
        AA_Notice notice = aaCenter.aa_notices[px_conf.notice];
        aaCenter.AA_SendNotice(player, notice, true, aa_message);
    }
    for (size_t i = 0; i < p_conf.aa_level_item_jxsx.size(); i++) {
        //获取玩家，和数值
        std::pair<ObjectGuid, uint32> p = p_conf.aa_level_item_jxsx[i];
        Player* player = ObjectAccessor::FindPlayer(p.first);
        if (!player || !player->IsInWorld()) {
            continue;
        }
        if (p.second <= 0) {
            continue;
        }
        //获取配置
        AA_PaihangX px_conf = aaCenter.aa_paihangxs[i + 1]["物品觉醒属性等级数量"];
        if (px_conf.id != i + 1) {
            continue;
        }
        if (isAura) {
            if (px_conf.auras != "" && px_conf.auras != "0") {
                std::vector<int32> spells; spells.clear();
                aaCenter.AA_StringToVectorInt(px_conf.auras, spells, ",");
                for (auto itr : spells) {
                    if (itr > 0) {
                        if (!player->HasAura(itr)) {
                            player->AddAura(itr, player);
                        }
                    }
                }
            }
            continue;
        }
        if (px_conf.reward == 0) {
            continue;
        }
        aaCenter.M_Reward(player, px_conf.reward, 1);
        if (px_conf.notice == 0) {
            continue;
        }
        AA_Message aa_message;
        AA_Notice notice = aaCenter.aa_notices[px_conf.notice];
        aaCenter.AA_SendNotice(player, notice, true, aa_message);
    }
    for (size_t i = 0; i < p_conf.aa_level_item_jxjn.size(); i++) {
        //获取玩家，和数值
        std::pair<ObjectGuid, uint32> p = p_conf.aa_level_item_jxjn[i];
        Player* player = ObjectAccessor::FindPlayer(p.first);
        if (!player || !player->IsInWorld()) {
            continue;
        }
        if (p.second <= 0) {
            continue;
        }
        //获取配置
        AA_PaihangX px_conf = aaCenter.aa_paihangxs[i + 1]["物品觉醒技能等级数量"];
        if (px_conf.id != i + 1) {
            continue;
        }
        if (isAura) {
            if (px_conf.auras != "" && px_conf.auras != "0") {
                std::vector<int32> spells; spells.clear();
                aaCenter.AA_StringToVectorInt(px_conf.auras, spells, ",");
                for (auto itr : spells) {
                    if (itr > 0) {
                        if (!player->HasAura(itr)) {
                            player->AddAura(itr, player);
                        }
                    }
                }
            }
            continue;
        }
        if (px_conf.reward == 0) {
            continue;
        }
        aaCenter.M_Reward(player, px_conf.reward, 1);
        if (px_conf.notice == 0) {
            continue;
        }
        AA_Message aa_message;
        AA_Notice notice = aaCenter.aa_notices[px_conf.notice];
        aaCenter.AA_SendNotice(player, notice, true, aa_message);
    }
    for (size_t i = 0; i < p_conf.aa_level_pet_jh.size(); i++) {
        //获取玩家，和数值
        std::pair<ObjectGuid, uint32> p = p_conf.aa_level_pet_jh[i];
        Player* player = ObjectAccessor::FindPlayer(p.first);
        if (!player || !player->IsInWorld()) {
            continue;
        }
        if (p.second <= 0) {
            continue;
        }
        //获取配置
        AA_PaihangX px_conf = aaCenter.aa_paihangxs[i + 1]["宠物进化等级"];
        if (px_conf.id != i + 1) {
            continue;
        }
        if (isAura) {
            if (px_conf.auras != "" && px_conf.auras != "0") {
                std::vector<int32> spells; spells.clear();
                aaCenter.AA_StringToVectorInt(px_conf.auras, spells, ",");
                for (auto itr : spells) {
                    if (itr > 0) {
                        if (!player->HasAura(itr)) {
                            player->AddAura(itr, player);
                        }
                    }
                }
            }
            continue;
        }
        if (px_conf.reward == 0) {
            continue;
        }
        aaCenter.M_Reward(player, px_conf.reward, 1);
        if (px_conf.notice == 0) {
            continue;
        }
        AA_Message aa_message;
        AA_Notice notice = aaCenter.aa_notices[px_conf.notice];
        aaCenter.AA_SendNotice(player, notice, true, aa_message);
    }
    for (size_t i = 0; i < p_conf.aa_level_pet_qh.size(); i++) {
        //获取玩家，和数值
        std::pair<ObjectGuid, uint32> p = p_conf.aa_level_pet_qh[i];
        Player* player = ObjectAccessor::FindPlayer(p.first);
        if (!player || !player->IsInWorld()) {
            continue;
        }
        if (p.second <= 0) {
            continue;
        }
        //获取配置
        AA_PaihangX px_conf = aaCenter.aa_paihangxs[i + 1]["宠物强化等级数量"];
        if (px_conf.id != i + 1) {
            continue;
        }
        if (isAura) {
            if (px_conf.auras != "" && px_conf.auras != "0") {
                std::vector<int32> spells; spells.clear();
                aaCenter.AA_StringToVectorInt(px_conf.auras, spells, ",");
                for (auto itr : spells) {
                    if (itr > 0) {
                        if (!player->HasAura(itr)) {
                            player->AddAura(itr, player);
                        }
                    }
                }
            }
            continue;
        }
        if (px_conf.reward == 0) {
            continue;
        }
        aaCenter.M_Reward(player, px_conf.reward, 1);
        if (px_conf.notice == 0) {
            continue;
        }
        AA_Message aa_message;
        AA_Notice notice = aaCenter.aa_notices[px_conf.notice];
        aaCenter.AA_SendNotice(player, notice, true, aa_message);
    }
    for (size_t i = 0; i < p_conf.aa_level_pet_jx.size(); i++) {
        //获取玩家，和数值
        std::pair<ObjectGuid, uint32> p = p_conf.aa_level_pet_jx[i];
        Player* player = ObjectAccessor::FindPlayer(p.first);
        if (!player || !player->IsInWorld()) {
            continue;
        }
        if (p.second <= 0) {
            continue;
        }
        //获取配置
        AA_PaihangX px_conf = aaCenter.aa_paihangxs[i + 1]["宠物觉醒等级数量"];
        if (px_conf.id != i + 1) {
            continue;
        }
        if (isAura) {
            if (px_conf.auras != "" && px_conf.auras != "0") {
                std::vector<int32> spells; spells.clear();
                aaCenter.AA_StringToVectorInt(px_conf.auras, spells, ",");
                for (auto itr : spells) {
                    if (itr > 0) {
                        if (!player->HasAura(itr)) {
                            player->AddAura(itr, player);
                        }
                    }
                }
            }
            continue;
        }
        if (px_conf.reward == 0) {
            continue;
        }
        aaCenter.M_Reward(player, px_conf.reward, 1);
        if (px_conf.notice == 0) {
            continue;
        }
        AA_Message aa_message;
        AA_Notice notice = aaCenter.aa_notices[px_conf.notice];
        aaCenter.AA_SendNotice(player, notice, true, aa_message);
    }
}

//随机副本人数
uint32 AACenter::AA_GetMaxGroupSize()
{
    uint32 count = aaCenter.aa_world_confs[75].value1;
    return count == 0 ? MAX_GROUP_SIZE : count;
}

//bad
void AACenter::BB_GetCreatureListInGrid(WorldObject* object, std::list<Creature*>& creatureList, float fMaxSearchRange) const
{
    CellCoord pair(Trinity::ComputeCellCoord(object->GetPositionX(), object->GetPositionY()));
    Cell cell(pair);
    cell.SetNoCreate();

    Trinity::AA_AllCreaturesInRange check(object, fMaxSearchRange);
    Trinity::CreatureListSearcher<Trinity::AA_AllCreaturesInRange> searcher(object, creatureList, check);
    TypeContainerVisitor<Trinity::CreatureListSearcher<Trinity::AA_AllCreaturesInRange>, GridTypeMapContainer> visitor(searcher);

    cell.Visit(pair, visitor, *(object->GetMap()), *object, fMaxSearchRange);
}

void AACenter::BB_GetCreatureListInMap(WorldObject* object, std::list<Creature*>& creatureList, int32 mapId) const
{
    CellCoord pair(Trinity::ComputeCellCoord(object->GetPositionX(), object->GetPositionY()));
    Cell cell(pair);
    cell.SetNoCreate();

    Trinity::AA_AllCreaturesInMap check(object, mapId);
    Trinity::CreatureListSearcher<Trinity::AA_AllCreaturesInMap> searcher(object, creatureList, check);
    TypeContainerVisitor<Trinity::CreatureListSearcher<Trinity::AA_AllCreaturesInMap>, GridTypeMapContainer> visitor(searcher);

    cell.Visit(pair, visitor, *(object->GetMap()), *object, 1000000);
}

void AACenter::BB_GetPlayerListInGrid(WorldObject* object, std::list<Player*>& playerList, float maxSearchRange, bool reqAlive) const
{
    Trinity::AnyPlayerInObjectRangeCheck checker(object, maxSearchRange, reqAlive);
    Trinity::PlayerListSearcher<Trinity::AnyPlayerInObjectRangeCheck> searcher(object, playerList, checker);
    Cell::VisitWorldObjects(object, searcher, maxSearchRange);
}

//获取AA_Map_Player_Conf
AA_Map_Player_Conf AACenter::AA_GetAA_Map_Player_Conf(WorldObject* object)
{
    AA_Map_Player_Conf conf0;
    if (!object) {
        return conf0;
    }
    Map* map = object->GetMap();
    if (!map) {
        return conf0;
    }
    uint32 mapid = object->GetMapId();
    uint32 zoneid = object->GetZoneId();
    uint32 areaid = object->GetAreaId();
    ObjectGuid::LowType guidlow = 0;

    //如果没有玩家副本变量，清空副本数据
    if (Player* p = object->ToPlayer()) {
        guidlow = p->GetGUIDLow();
    }
    if (map->IsDungeon()) { //副本或战场
        uint32 instanceid = object->GetInstanceId();
        uint32 confid1 = aaCenter.aa_minstancevalues[instanceid][0];
        if (confid1) {
            AA_Map_Player_Conf conf = aaCenter.aa_map_player_confs[confid1];
            conf.m_mapid = instanceid;
            conf.m_mapmoshi = 3;
            if (guidlow) {
                conf.m_dietime = aaCenter.aa_pinstancevalues[instanceid][guidlow][0];
            }
            for (auto iter : aaCenter.aa_minstancebools[instanceid])
                conf.m_jindu_status[iter.first] = iter.second;
            conf.m_xianzhitime = aaCenter.aa_minstancevalues[instanceid][1];
            conf.m_jindu_exp = aaCenter.aa_minstancevalues[instanceid][2];
            return conf;
        }
        Difficulty diff = DIFFICULTY_NONE;
        //Difficulty diff = object->GetMap()->GetDifficulty();
        std::string moshi = "";
        //if (diff == RAID_DIFFICULTY_25MAN_HEROIC) {
        //    moshi = "英雄25人";
        //}
        //else if (diff == RAID_DIFFICULTY_25MAN_NORMAL) {
        //    moshi = "普通25人";
        //}
        //else if (diff == DUNGEON_DIFFICULTY_HEROIC || diff == RAID_DIFFICULTY_10MAN_HEROIC || diff == DUNGEON_DIFFICULTY_EPIC) {
        //    moshi = "英雄5或10人";
        //}
        //else if (diff == DUNGEON_DIFFICULTY_NORMAL || diff == RAID_DIFFICULTY_10MAN_NORMAL || diff == REGULAR_DIFFICULTY) {
        //    moshi = "普通5或10人";
        //}
        uint32 nanduid = aaCenter.aa_minstancevalues[instanceid][3];
        uint32 confid = 0;
        if (confid == 0) 
        {
            confid = aaCenter.aa_map_player_conf_areas[areaid][moshi][nanduid][0];
        }
        if (confid == 0)
        {
            confid = aaCenter.aa_map_player_conf_zones[zoneid][moshi][nanduid][0];
        }
        if (confid == 0)
        {
            confid = aaCenter.aa_map_player_conf_maps[mapid][moshi][nanduid][0];
        }
        if (confid == 0)
        {
            confid = aaCenter.aa_map_player_conf_alls[moshi][nanduid][0];
        }
        if (confid == 0)
        {
            confid = aaCenter.aa_map_player_conf_areas[areaid]["全部"][nanduid][0];
        }
        if (confid == 0)
        {
            confid = aaCenter.aa_map_player_conf_zones[zoneid]["全部"][nanduid][0];
        }
        if (confid == 0)
        {
            confid = aaCenter.aa_map_player_conf_maps[mapid]["全部"][nanduid][0];
        }
        if (confid == 0)
        {
            confid = aaCenter.aa_map_player_conf_alls["全部"][nanduid][0];
        }
        if (confid > 0) {
            conf0 = aaCenter.aa_map_player_confs[confid];
        }
        conf0.m_mapid = instanceid;
        conf0.m_mapmoshi = 3;
        //设置当前instance变量
        aaCenter.aa_minstancevalues[instanceid][0] = conf0.id;
        //倒计时开始
        if (conf0.xianzhitime) {
            conf0.m_xianzhitime = 1;
            aaCenter.aa_minstancevalues[instanceid][1] = 1;
        }
        aaCenter.AA_UpdateValueBools(instanceid, 3, true);
    }
    else { //野外
        uint32 confid = 0;
        if (confid == 0)
        {
            confid = aaCenter.aa_map_player_conf_yewai_areas[areaid];
            if (confid > 0) {
                conf0 = aaCenter.aa_map_player_confs[confid];
                conf0.m_mapid = areaid;
                conf0.m_mapmoshi = 2;
                if (guidlow) {
                    conf0.m_dietime = aaCenter.aa_pareavalues[areaid][guidlow][0];
                }
                for (auto iter : aa_mmapbools[areaid])
                    conf0.m_jindu_status[iter.first] = iter.second;
                conf0.m_xianzhitime = aaCenter.aa_mareavalues[areaid][1];
                conf0.m_jindu_exp = aaCenter.aa_mareavalues[areaid][2];
            }
        }
        if (confid == 0)
        {
            confid = aaCenter.aa_map_player_conf_yewai_zones[zoneid];
            if (confid > 0) {
                conf0 = aaCenter.aa_map_player_confs[confid];
                conf0.m_mapid = zoneid;
                conf0.m_mapmoshi = 1;
                if (guidlow) {
                    conf0.m_dietime = aaCenter.aa_pzonevalues[zoneid][guidlow][0];
                }
                for (auto iter : aa_mzonebools[zoneid])
                    conf0.m_jindu_status[iter.first] = iter.second;
                conf0.m_xianzhitime = aaCenter.aa_mzonevalues[zoneid][1];
                conf0.m_jindu_exp = aaCenter.aa_mzonevalues[zoneid][2];
            }
        }
        if (confid == 0)
        {
            confid = aaCenter.aa_map_player_conf_yewai_maps[mapid];
            if (confid > 0) {
                conf0 = aaCenter.aa_map_player_confs[confid];
                conf0.m_mapid = mapid;
                conf0.m_mapmoshi = 0;
                if (guidlow) {
                    conf0.m_dietime = aaCenter.aa_pmapvalues[mapid][guidlow][0];
                }
                for (auto iter : aa_mmapbools[mapid])
                    conf0.m_jindu_status[iter.first] = iter.second;
                conf0.m_xianzhitime = aaCenter.aa_mmapvalues[mapid][1];
                conf0.m_jindu_exp = aaCenter.aa_mmapvalues[mapid][2];
            }
        }
        if (confid == 0)
        {
            confid = aaCenter.aa_map_player_conf_yewai_all_id;
            if (confid > 0) {
                conf0 = aaCenter.aa_map_player_confs[confid];
                conf0.m_mapid = mapid;
                conf0.m_mapmoshi = 0;
                if (guidlow) {
                    conf0.m_dietime = aaCenter.aa_pmapvalues[mapid][guidlow][0];
                }
                for (auto iter : aa_mmapbools[mapid])
                    conf0.m_jindu_status[iter.first] = iter.second;
                conf0.m_xianzhitime = aaCenter.aa_mmapvalues[mapid][1];
                conf0.m_jindu_exp = aaCenter.aa_mmapvalues[mapid][2];
            }
        }
    }
    return conf0;
}

void AACenter::AA_UpdateValueBools(int32 mapid, uint32 moshi, bool isValue, ObjectGuid::LowType guidlow)
{
    //mapmoshi  0map 1zone 2area 3instanceid
    if (moshi == 0) {
        if (guidlow) {
            AA_Player_Map_Value conf = aaCenter.aa_player_map_values[mapid][guidlow];
            time_t timep;
            time(&timep); /*当前time_t类型UTC时间*/
            conf.update_time = timep;
            conf.isUpdate = true;
            if (isValue) {
                std::string str = "";
                aaCenter.AA_MapToString(aaCenter.aa_pmapvalues[mapid][guidlow], str);
                conf.valuev = str;
            }
            else {
                std::string str = "";
                aaCenter.AA_MapToString(aaCenter.aa_pmapbools[mapid][guidlow], str);
                conf.valueb = str;
            }
            aaCenter.aa_player_map_values[mapid][guidlow] = conf;
        }
        else {
            AA_Map_Map_Value conf = aaCenter.aa_map_map_values[mapid];
            time_t timep;
            time(&timep); /*当前time_t类型UTC时间*/
            conf.update_time = timep;
            conf.isUpdate = true;
            if (isValue) {
                std::string str = "";
                aaCenter.AA_MapToString(aaCenter.aa_mmapvalues[mapid], str);
                conf.valuev = str;
            }
            else {
                std::string str = "";
                aaCenter.AA_MapToString(aaCenter.aa_mmapbools[mapid], str);
                conf.valueb = str;
            }
            aaCenter.aa_map_map_values[mapid] = conf;
        }
    }
    else if (moshi == 1) {
        if (guidlow) {
            AA_Player_Zone_Value conf = aaCenter.aa_player_zone_values[mapid][guidlow];
            time_t timep;
            time(&timep); /*当前time_t类型UTC时间*/
            conf.update_time = timep;
            conf.isUpdate = true;
            if (isValue) {
                std::string str = "";
                aaCenter.AA_MapToString(aaCenter.aa_pzonevalues[mapid][guidlow], str);
                conf.valuev = str;
            }
            else {
                std::string str = "";
                aaCenter.AA_MapToString(aaCenter.aa_pzonebools[mapid][guidlow], str);
                conf.valueb = str;
            }
            aaCenter.aa_player_zone_values[mapid][guidlow] = conf;
        }
        else {
            AA_Map_Zone_Value conf = aaCenter.aa_map_zone_values[mapid];
            time_t timep;
            time(&timep); /*当前time_t类型UTC时间*/
            conf.update_time = timep;
            conf.isUpdate = true;
            if (isValue) {
                std::string str = "";
                aaCenter.AA_MapToString(aaCenter.aa_mzonevalues[mapid], str);
                conf.valuev = str;
            }
            else {
                std::string str = "";
                aaCenter.AA_MapToString(aaCenter.aa_mzonebools[mapid], str);
                conf.valueb = str;
            }
        }
    }
    else if (moshi == 2) {
        if (guidlow) {
            AA_Player_Area_Value conf = aaCenter.aa_player_area_values[mapid][guidlow];
            time_t timep;
            time(&timep); /*当前time_t类型UTC时间*/
            conf.update_time = timep;
            conf.isUpdate = true;
            if (isValue) {
                std::string str = "";
                aaCenter.AA_MapToString(aaCenter.aa_pareavalues[mapid][guidlow], str);
                conf.valuev = str;
            }
            else {
                std::string str = "";
                aaCenter.AA_MapToString(aaCenter.aa_pareabools[mapid][guidlow], str);
                conf.valueb = str;
            }
            aaCenter.aa_player_area_values[mapid][guidlow] = conf;
        }
        else {
            AA_Map_Area_Value conf = aaCenter.aa_map_area_values[mapid];
            time_t timep;
            time(&timep); /*当前time_t类型UTC时间*/
            conf.update_time = timep;
            conf.isUpdate = true;
            if (isValue) {
                std::string str = "";
                aaCenter.AA_MapToString(aaCenter.aa_mareavalues[mapid], str);
                conf.valuev = str;
            }
            else {
                std::string str = "";
                aaCenter.AA_MapToString(aaCenter.aa_mareabools[mapid], str);
                conf.valueb = str;
            }
        }
    }
    else if (moshi == 3) {
        if (guidlow) {
            AA_Player_Instance_Value conf = aaCenter.aa_player_instance_values[mapid][guidlow];
            time_t timep;
            time(&timep); /*当前time_t类型UTC时间*/
            conf.update_time = timep;
            conf.isUpdate = true;
            if (isValue) {
                std::string str = "";
                aaCenter.AA_MapToString(aaCenter.aa_pinstancevalues[mapid][guidlow], str);
                conf.valuev = str;
            }
            else {
                std::string str = "";
                aaCenter.AA_MapToString(aaCenter.aa_pinstancebools[mapid][guidlow], str);
                conf.valueb = str;
            }
            aaCenter.aa_player_instance_values[mapid][guidlow] = conf;
        }
        else {
            AA_Map_Instance_Value conf = aaCenter.aa_map_instance_values[mapid];
            time_t timep;
            time(&timep); /*当前time_t类型UTC时间*/
            conf.update_time = timep;
            conf.isUpdate = true;
            if (isValue) {
                std::string str = "";
                aaCenter.AA_MapToString(aaCenter.aa_minstancevalues[mapid], str);
                conf.valuev = str;
            }
            else {
                std::string str = "";
                aaCenter.AA_MapToString(aaCenter.aa_minstancebools[mapid], str);
                conf.valueb = str;
            }
            aaCenter.aa_map_instance_values[mapid] = conf;
        }
    }
}

//卸载魂玉
bool AACenter::AA_Item_Shuangjia_Chaixie(Player* player, int32 lan, int32 index, bool destroy)
{
    if (!player || !lan || !index) {
        return false;
    }
    ObjectGuid::LowType guidlow = player->GetGUID().GetCounter();
    std::vector<ObjectGuid::LowType> guids = aa_item_instance_owner[guidlow];
    time_t timep;
    time(&timep); /*当前time_t类型UTC时间*/
    for (auto guid : guids) {
        AA_Item_Instance conf = aaCenter.aa_item_instances[guid];
        if (conf.weizhi != "") {
            std::map<int32, int32> m; m.clear();
            aaCenter.AA_StringToMap(conf.weizhi, m);
            if (m.begin()->first == lan && m.begin()->second == index) { //拆卸已有的装备
                ItemTemplate const* pProto = sObjectMgr->GetItemTemplate(conf.itemEntry);
                if (pProto)
                {
                    Item* pItem = NewItemOrBag(pProto);
                    if (pItem->AA_LoadFromDB(guid, player->GetGUID(), conf.itemEntry))
                    {
                        if (!destroy) {
                            uint32 count = 1;
                            uint32 noSpaceForCount = 0;
                            ItemPosCountVec dest;
                            InventoryResult msg = player->CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, conf.itemEntry, count, &noSpaceForCount);
                            if (msg != EQUIP_ERR_OK)
                                count -= noSpaceForCount;

                            if (count == 0 || dest.empty())
                            {
                                // -- TODO: Send to mailbox if no space
                                ChatHandler(player->GetSession()).PSendSysMessage("你没有足够的背包空间.");
                                return false;
                            }
                            AA_Item_Shuangjia s_conf = aaCenter.aa_item_shuangjias[lan];
                            if (s_conf.need_chaixie != "") {
                                std::vector<int32> v; v.clear();
                                aaCenter.AA_StringToVectorInt(s_conf.need_chaixie, v, ",");
                                if (v.size() > (index - 1)) {
                                    uint32 needid = v[index - 1];
                                    if (needid > 0) {
                                        if (aaCenter.M_CanNeed(player, needid)) {
                                            aaCenter.M_Need(player, needid);
                                        }
                                        else {
                                            return false;
                                        }
                                    }
                                }
                            }
                            player->ApplyItemEquipSpell(pItem, false);
                            player->ApplyEnchantment(pItem, false);
                            pItem->SetOwnerGUID(player->GetGUID());
                            pItem->FSetState(ITEM_NEW);
                            player->StoreItem(dest, pItem, true);
                            pItem->SetState(ITEM_CHANGED, player);
                            pItem->SetBinding(true);
                        }
                        aaCenter.aa_item_instances[guid].weizhi = "";
                        aaCenter.aa_item_instances[guid].update_time = timep;
                        aaCenter.aa_item_instances[guid].isUpdate = true;
                        for (auto it = aa_item_instance_owner[guidlow].begin(); it != aa_item_instance_owner[guidlow].end();)
                        {
                            if ((*it) == guid) {
                                it = aa_item_instance_owner[guidlow].erase(it);
                            }
                            else {
                                it++;
                            }
                        }
                        aaCenter.AA_ApplyItemBonuses(player, pItem, false, true);
                    }
                }
            }
        }
    }
    return true;
}

uint32 AACenter::AA_GetItemValueCount(uint32 entry)
{
    uint32 count = 0;
    //ItemTemplate const* pProto = sObjectMgr->GetItemTemplate(entry);
    //for (int i = 0; i < 10; i++) {
    //    if (pProto->ItemStat[i].ItemStatValue > 0) {
    //        count++;
    //    }
    //}
    return count;
}

//比武专区
GameObject* AACenter::AA_Biwu_SpawnGob(ObjectGuid::LowType guid, bool created)
{
    GameObject* obj = nullptr;

    //GameObjectData const* data = sObjectMgr->GetGameObjectData(guid);
    //if (!data)
    //    return obj;
    ////Get map object
    //Map* map = sMapMgr->CreateBaseMap(data->mapid);
    //if (!map)
    //    return obj;

    //if (created)
    //{
    //    obj = new GameObject;

    //    if (!obj->Create(sObjectMgr->GenerateGameObjectSpawnId(), data->id, map, data->phaseMask, data->posX, data->posY, data->posZ, data->orientation, G3D::Quat(), 0, GO_STATE_READY))
    //    {
    //        delete obj;
    //        return nullptr;
    //    }

    //    map->AddToMap(obj);
    //    obj->setActive(true);
    //    obj->SetPhaseMask(1, true);
    //    aa_biwu_guid = obj->GetGUID();
    //}
    //else
    //{
    //    obj = map->GetGameObject(aa_biwu_guid);
    //}
    return obj;
}

void AACenter::AA_Biwu_Go(uint32 teamid)
{
    Player* pl1 = ObjectAccessor::FindPlayerByLowGUID(aaCenter.aa_biwu_teams[teamid].p1);
    Player* pl2 = ObjectAccessor::FindPlayerByLowGUID(aaCenter.aa_biwu_teams[teamid].p2);

    if (!pl1 || !pl2)
        return;

    if (pl1->duel || pl2->duel)
        return;

    GameObject* obj = pl1->GetMap()->GetGameObject(aaCenter.aa_biwu_guid);
    if (!obj)
        return;

    pl1->duel = std::make_unique<DuelInfo>(pl2, pl1, 0, true);
    pl2->duel = std::make_unique<DuelInfo>(pl1, pl2, 0, true);

    pl1->SetDuelArbiter(obj->GetGUID());
    pl2->SetDuelArbiter(obj->GetGUID());

    time_t now = GameTime::GetGameTime();
    pl1->duel->StartTime = now + 10;
    pl2->duel->StartTime = now + 10;

    pl1->duel->State = DUEL_STATE_COUNTDOWN;
    pl2->duel->State = DUEL_STATE_COUNTDOWN;

    WorldPackets::Duel::DuelCountdown packet(10000); // milliseconds
    WorldPacket const* worldPacket = packet.Write();
    pl1->GetSession()->SendPacket(worldPacket);
    pl2->GetSession()->SendPacket(worldPacket);
    pl1->EnablePvpRules();
    pl2->EnablePvpRules();
}

std::unordered_map<uint32, AA_Biwu_Team> AACenter::AA_Biwu_Fenzu()
{
    std::unordered_map<uint32, AA_Biwu_Team> aa_biwu_teams; aa_biwu_teams.clear();

    //1、获取所有winners
    std::vector<Player*> players; players.clear();
    for (auto guidlow : aaCenter.aa_biwu_winners) {
        if (Player* p = ObjectAccessor::FindPlayerByLowGUID(guidlow)) {
            p->aa_biwu_teamid = 0;
            if (!p->IsInWorld() || !p->IsAlive()) {
                continue;
            }
            players.push_back(p);
        }
    }
    //如果只剩一个赢家，比武结束
    if (players.size() <= 1) {
        return aa_biwu_teams;
    }

    //2、22分组
    uint32 index = 1;
    uint32 teamid = 1;
    Player* p1 = nullptr;
    Player* p2 = nullptr;
    uint32 count = players.size();
    if (count % 2 == 1) {
        count = count - 1;
    }
    for (size_t i = 0; i < players.size(); i++)
    {
        Player* p = players[i];
        if (i < count) {
            if (p) {
                p->aa_biwu_teamid = teamid;
            }
            if (index == 1) {
                aa_biwu_teams[teamid].p1 = p->GetGUIDLow();
                index = 2;
            }
            else if (index == 2) {
                aa_biwu_teams[teamid].p2 = p->GetGUIDLow();
                index = 1;
                teamid = teamid + 1;
            }
        }
        else {
            aaCenter.aa_biwu_score[p->GetGUIDLow()] += 2;
            std::string msg = "|cff00FFFF[比武擂台]|cffFFFF00恭喜你，获得躺赢资格，请等待下一轮开始。";
            aaCenter.AA_SendMessage(p, 0, msg.c_str());
        }
    }

    return aa_biwu_teams;
}

void AACenter::AA_Biwu_Update(uint32 diff)
{
    if (aaCenter.aa_biwu_event_id == 0) {
        return;
    }
    if (aaCenter.aa_biwu_isstart == false) {
        //如果事件还未到
        AA_Biwu_Conf conf = aaCenter.aa_biwu_confs[aaCenter.aa_biwu_event_id];
        if (conf.event_id > 0 && sGameEventMgr->IsActiveEvent(conf.event_id) && conf.area > 0) {
            //比武前，超过等待时间，开始战斗
            aaCenter.aa_biwu_start_time -= diff;
            //比武中，距离结束提示
            if (aaCenter.aa_biwu_start_time > -1) {
                uint32 time = aaCenter.aa_biwu_start_time / 1000;
                if (time == 10 || time == 20 || time == 30 || time == 40 || time == 50 || time == 60 || time == 90 || time == 120) {
                    if (aaCenter.aa_biwu_isnotice != time) {
                        aaCenter.aa_biwu_isnotice = time;
                        std::string msg = "|cff00FFFF[比武擂台]|cffFFFF00比武大会将在" + std::to_string(time) + "秒后开始，进入活动地图后，自动报名参加。";
                        std::set<Player*> players = aaCenter.GetOnlinePlayers();
                        for (auto player : players) {
                            aaCenter.AA_SendMessage(player, 0, msg.c_str());
                        }
                    }
                }
            }
            if (aaCenter.aa_biwu_start_time < -1) {
                aaCenter.aa_biwu_start_time = -1;
                aaCenter.aa_biwu_winners.clear();

                //获取地图所有人
                std::set<Player*> players = aaCenter.GetOnlinePlayers();
                for (auto p : players) {
                    if (p->GetAreaId() != conf.area) {
                        continue;
                    }
                    aaCenter.aa_biwu_players.insert(p->GetGUIDLow());
                    aaCenter.aa_biwu_winners.insert(p->GetGUIDLow());
                }

                if (aaCenter.aa_biwu_winners.size() >= conf.player_min) {
                    //开始比武
                    aaCenter.AA_Biwu_Start();
                    aaCenter.aa_biwu_isstart = true;
                }
            }
        }
    }
    else {
        AA_Biwu_Conf conf = aaCenter.aa_biwu_confs[aaCenter.aa_biwu_event_id];
        //比武中，超过决斗时间，结算
        aaCenter.aa_biwu_time += diff;
        uint32 aa_biwu_next_time = conf.juedou_time * 1000 + 10000;

        //比武中，距离结束提示
        if (conf.juedou_time * 1000 > aaCenter.aa_biwu_time) {
            uint32 length = conf.juedou_time * 1000 - aaCenter.aa_biwu_time;
            uint32 time = length / 1000;
            if (time == 10 || time == 20 || time == 30 || time == 40 || time == 50 || time == 60 || time == 90 || time == 120) {
                if (aaCenter.aa_biwu_isnotice != time) {
                    aaCenter.aa_biwu_isnotice = time;
                    std::string msg = "|cff00FFFF[比武擂台]|cffFFFF00第" + std::to_string(aaCenter.aa_biwu_index) + "轮比拼，还剩" + std::to_string(time) + "秒结束。";
                    for (auto guidlow : aaCenter.aa_biwu_players) {
                        if (Player* player = ObjectAccessor::FindPlayerByLowGUID(guidlow)) {
                            aaCenter.AA_SendMessage(player, 0, msg.c_str());
                        }
                    }
                }
            }
        }

        //1、选出胜负，发出公告
        if (aaCenter.aa_biwu_time >= conf.juedou_time * 1000 && aaCenter.aa_biwu_status == false) {
            std::unordered_map<uint32, AA_Biwu_Team> teams; teams.clear();
            for (auto itr : aaCenter.aa_biwu_teams) {
                teams[itr.first] = itr.second;
            }
            for (auto itr : aaCenter.aa_biwu_teams) {
                teams.erase(itr.first);
                Player* pl1 = ObjectAccessor::FindPlayerByLowGUID(itr.second.p1);
                Player* pl2 = ObjectAccessor::FindPlayerByLowGUID(itr.second.p2);
                //如果掉线，算输
                if (!pl1) {
                    aaCenter.aa_biwu_winners.erase(itr.second.p1);
                }
                if (!pl2) {
                    aaCenter.aa_biwu_winners.erase(itr.second.p2);
                }
                pl1->aa_biwu_teamid = 0;
                pl2->aa_biwu_teamid = 0;
                //根据血量百分比 或 血量，判断出胜负
                if (pl1->GetHealthPct() > pl2->GetHealthPct()) {
                    aaCenter.aa_biwu_score[itr.second.p1] += 2;
                    aaCenter.aa_biwu_score[itr.second.p2] += 1;
                    if (pl2) {
                        pl2->DuelComplete(DUEL_FLED);
                    }
                    aaCenter.aa_biwu_winners.erase(itr.second.p2);
                }
                else if (pl1->GetHealthPct() < pl2->GetHealthPct()) {
                    aaCenter.aa_biwu_score[itr.second.p1] += 1;
                    aaCenter.aa_biwu_score[itr.second.p2] += 2;
                    if (pl1) {
                        pl1->DuelComplete(DUEL_FLED);
                    }
                    aaCenter.aa_biwu_winners.erase(itr.second.p1);
                }
                else {
                    if (pl1->GetHealth() > pl2->GetHealth()) {
                        aaCenter.aa_biwu_score[itr.second.p1] += 2;
                        aaCenter.aa_biwu_score[itr.second.p2] += 1;
                        if (pl2) {
                            pl2->DuelComplete(DUEL_FLED);
                        }
                        aaCenter.aa_biwu_winners.erase(itr.second.p2);
                    }
                    else {
                        aaCenter.aa_biwu_score[itr.second.p1] += 1;
                        aaCenter.aa_biwu_score[itr.second.p2] += 2;
                        if (pl1) {
                            pl1->DuelComplete(DUEL_FLED);
                        }
                        aaCenter.aa_biwu_winners.erase(itr.second.p1);
                    }
                }
            }
            aaCenter.aa_biwu_teams = teams;
            aaCenter.aa_biwu_index = aaCenter.aa_biwu_index + 1;
            if (aaCenter.aa_biwu_winners.size() > 1) {
                for (auto guidlow : aaCenter.aa_biwu_players) {
                    if (Player* player = ObjectAccessor::FindPlayerByLowGUID(guidlow)) {
                        std::string msg = "|cff00FFFF[比武擂台]|cffFFFF00第" + std::to_string(aaCenter.aa_biwu_index) + "轮比拼，将在10秒后开启。";
                        aaCenter.AA_SendMessage(player, 0, msg.c_str());
                    }
                }
            }
            aaCenter.aa_biwu_status = true;
        }

        //2、10秒后开始下一轮
        if (aaCenter.aa_biwu_time >= aa_biwu_next_time) {
            aaCenter.aa_biwu_status = false;
            aaCenter.aa_biwu_time = 0;
            aaCenter.AA_Biwu_Complete();
        }
    }
}

void AACenter::AA_Biwu_Start()
{
    //1、分组
    aaCenter.aa_biwu_teams.clear();
    aaCenter.aa_biwu_teams = aaCenter.AA_Biwu_Fenzu();
    //2、开始比武
    for (auto itr : aaCenter.aa_biwu_teams) {
        uint32 teamid = itr.first;
        aaCenter.AA_Biwu_Go(teamid);
    }
}

void AACenter::AA_Biwu_Complete()
{
    if (!aaCenter.AA_VerifyCode("a211b")) {
        aaCenter.AA_SendMessage(nullptr, 1, "|cff00FFFF[系统提示]|cffFF0000请联系QQ643125009开通!");
        return;
    }
    //计算排名
    paihangbiwu(aaCenter.aa_biwu_paiming, aaCenter.aa_biwu_score);
    for (int i = 0; i < 10; i++) {
        if (aaCenter.aa_biwu_paiming.size() > i) {
            std::pair<ObjectGuid::LowType, uint32> aa_biwu_score = aaCenter.aa_biwu_paiming[i];
            std::string gm = ".变量 系统 比武排名" + std::to_string(i + 1) + " =" + std::to_string(aa_biwu_score.first);
            aaCenter.AA_DoCommand(nullptr, gm.c_str());
        }
        else {
            std::string gm = ".变量 系统 比武排名" + std::to_string(i + 1) + " =0";
            aaCenter.AA_DoCommand(nullptr, gm.c_str());
        }
    }
    //判断winners，teams 是否重开
    //如果决斗全部结束，重新开始
    if (aaCenter.aa_biwu_teams.size() == 0)
    {
        aaCenter.AA_Biwu_Start();
    }
    //如果没有队伍了，比武结束
    if (aaCenter.aa_biwu_teams.size() == 0) {
        aaCenter.AA_Biwu_End();
    }
}
void AACenter::AA_Biwu_End()
{
    if (aaCenter.aa_biwu_event_id == 0) {
        return;
    }
    AA_Biwu_Conf conf = aaCenter.aa_biwu_confs[aaCenter.aa_biwu_event_id];

    if (GameObject* gob = aaCenter.AA_Biwu_SpawnGob(conf.guid, false)) {
        gob->Delete();
    }

    aaCenter.AA_SendMessage(nullptr, 0, "╔┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈╗");
    aaCenter.AA_SendMessage(nullptr, 0, "· 比武大会结束，排名前十更新");
    std::set<ObjectGuid::LowType> players; players.clear();
    //排名前10公告
    std::string m_diy_systems = aaCenter.aa_system_conf.diy_system;
    std::map<std::string, std::string> mdiy_systems; mdiy_systems.clear();
    aaCenter.AA_StringToStringMap(m_diy_systems, mdiy_systems);
    for (int i = 0; i < 10; i++) {
        std::string search1 = "比武排名" + std::to_string(i + 1);
        std::string str = mdiy_systems[search1];
        ObjectGuid::LowType guidlow = aaCenter.AA_StringInt32(str);
        if (guidlow > 0) {
            std::string name = "无";
            {
                QueryResult result = CharacterDatabase.PQuery("SELECT name FROM characters WHERE deleteDate IS NULL AND guid = {}", guidlow);
                if (result)
                {
                    Field* fields = result->Fetch();
                    name = fields[0].GetString();
                }
            }
            std::string msg = "";
            std::string msg1 = "第" + std::to_string(i + 1) + "名：" + name;
            if (i == 0) {
                msg = "· " + aa_color_red + msg1;
            }
            else if (i == 1) {
                msg = "· " + aa_color_red1 + msg1;
            }
            else if (i == 2) {
                msg = "· " + aa_color_reds + msg1;
            }
            else {
                msg = "· " + aa_color_white + msg1;
            }
            aaCenter.AA_SendMessage(nullptr, 0, msg.c_str());
        }
    }
    bool isOk = false;
    if (conf.gm_1 != "" && conf.gm_1 != "0") {
        std::map<int32, int32> rewards; rewards.clear();
        aaCenter.AA_StringToMap(conf.gm_1, rewards);

        //比武排名
        uint32 index = 1;

        for (int i = 0; i < 10; i++) {
            std::string search1 = "比武排名" + std::to_string(i + 1);
            std::string str = mdiy_systems[search1];
            ObjectGuid::LowType guidlow = aaCenter.AA_StringInt32(str);
            if (guidlow > 0) {
                players.insert(guidlow);
                if (rewards[i + 1] > 0) {
                    if (Player* p = ObjectAccessor::FindPlayerByLowGUID(guidlow)) {
                        if (p->IsInWorld()) {
                            isOk = true;
                            std::string msg = "· 你获得了第" + std::to_string(i + 1) + "名奖励";
                            aaCenter.AA_SendMessage(p, 0, msg.c_str());
                            aaCenter.AA_SendMessage(p, 0, "╚┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈╝");
                            aaCenter.M_RewardDo(p, rewards[i + 1]);
                        }
                    }
                }
            }
        }
        if (rewards[0] > 0) {
            for (auto guidlow : aaCenter.aa_biwu_players) {
                //比武参与奖
                if (std::find(players.begin(), players.end(), guidlow) != players.end()) {
                    continue;
                }
                if (Player* p = ObjectAccessor::FindPlayerByLowGUID(guidlow)) {
                    if (p->IsInWorld()) {
                        isOk = true;
                        std::string msg = "· 你获得了参与奖励";
                        aaCenter.AA_SendMessage(p, 0, msg.c_str());
                        aaCenter.AA_SendMessage(p, 0, "╚┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈╝");
                        aaCenter.M_RewardDo(p, rewards[0]);
                    }
                }
            }
        }
    }
    if (!isOk){
        aaCenter.AA_SendMessage(nullptr, 0, "╚┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈╝");
    }

    aaCenter.aa_biwu_winners.clear();
    aaCenter.aa_biwu_teams.clear();
    aaCenter.aa_biwu_guid = ObjectGuid::Empty;
    aaCenter.aa_biwu_status = false;
    aaCenter.aa_biwu_event_id = 0;
    aaCenter.aa_biwu_time = 0;
    aaCenter.aa_biwu_players.clear();
    aaCenter.aa_biwu_isstart = false;
    aaCenter.aa_biwu_isnotice = 0;
    aaCenter.aa_biwu_start_time = -1;
}
