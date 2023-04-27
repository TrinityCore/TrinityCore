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
class aa_item_cuiqu : public ItemScript
{
private:
    std::vector<int32> type_ids;
    uint32 vcount = 0;
    uint32 scount = 0;
public:
    aa_item_cuiqu() : ItemScript("aa_item_cuiqu") { }
    
    // Called when a player uses the item.
    bool OnUse(Player* player, Item* item, SpellCastTargets const& targets, ObjectGuid /*castId*/) override {
        if (!aaCenter.AA_VerifyCode("a103b")) {
            return true;
        }
        if (!player || !player->IsInWorld() || !item || !item->IsInWorld()) {
            return true;
        }
        ClearGossipMenuFor(player);
        ItemTemplate const* pProto = item->GetTemplate();
        AA_Cuiqu_Item conf_c;
        if (pProto) {
            uint32 itemid = pProto->GetId();
            AA_Character_Instance conf = aaCenter.aa_character_instances[item->GetGUIDLow()];
            conf_c = aaCenter.aa_cuiqu_items[itemid];
            if (itemid == 0 || conf.itemEntry != itemid || conf_c.itemid != itemid) {
                aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000道具不正确!");
                return true;
            }
        } else {
            aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000物品不存在!");
            return true;
        }
        //赋值 item 和 targetitem
        if (targets.GetItemTarget()) {
            Item* target = targets.GetItemTarget();
            if (target && target->IsEquipped()) {
                aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000请将物品放入背包再操作。"); return true;
            }
            if (ItemTemplate const* pProto = target->GetTemplate()) {

                if (conf_c.items != "" && conf_c.items != "0") {
                    std::vector<int32> items; items.clear();
                    aaCenter.AA_StringToVectorInt(conf_c.items, items, ",");
                    if (std::find(items.begin(), items.end(), pProto->GetId()) == items.end()) {
                        aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000无法对该物品使用。");
                        return true;
                    }
                }
                if (conf_c.pcitems != "" && conf_c.pcitems != "0") {
                    std::vector<int32> items; items.clear();
                    aaCenter.AA_StringToVectorInt(conf_c.pcitems, items, ",");
                    if (std::find(items.begin(), items.end(), pProto->GetId()) != items.end()) {
                        aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000无法对该物品使用。");
                        return true;
                    }
                }
            }
            player->aa_item = item;
            player->aa_target_item = target;
            if (conf_c.need > 0) {
                if (!aaCenter.M_CanNeed(player, conf_c.need, 1, true, player->aa_target_item->GetGUIDLow())) {
                    return true;
                }
            }
            AA_Character_Instance conf = aaCenter.aa_character_instances[target->GetGUIDLow()];
            AA_Character_Instance conf2 = aaCenter.aa_character_instances[item->GetGUIDLow()];
            std::string val2 = aaCenter.aa_cuiqu_items[item->GetEntry()].cuiqu_pos;
            if (val2 != "0" && val2 != "" && target) {
                std::vector<int32> vals; vals.clear();
                aaCenter.AA_StringToVectorInt(val2, vals, ",");
                ItemTemplate const* tpProto = target->GetTemplate();
                if (tpProto) {
                    if (conf2.cuiqu_pos != -1 && conf2.cuiqu_pos != (int32)tpProto->GetInventoryType()) {
                        aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000附魔的装备部位不正确!");
                        return true;
                    }
                }
            }
            
            //弹框
            int32 vindex = 0;
            int32 sindex = 10000;
            type_ids.clear();
            //获取属性
            std::string vtitle = "";
            std::string stitle = "";
            if (conf.fm_value_count > 0) {
                std::vector<int32> types; types.clear();
                std::vector<int32> values; values.clear();
                aaCenter.AA_StringToVector2(conf.fm_values, types, values);
                if (conf.fm_value_count == types.size() && conf.fm_value_count == values.size()) {
                    for (uint32 i = 0; i<conf.fm_value_count; i++) {
                        int32 type_id = types[i];
                        int32 value = values[i];
                        AA_Stat statconf = aaCenter.aa_stats[type_id];
                        std::string vtitle = "";
                        if (type_id == 999999) {
                            vtitle = statconf.text;
                        } else {
                            vtitle = "+" + std::to_string(value) + statconf.text;
                        }
                        
                        AddGossipItemFor(player, GossipOptionNpc(0), vtitle, vindex, 0);
                        vindex++;
                        type_ids.push_back(type_id);
                    }
                    vcount = vindex;
                }
            }
            if (conf.fm_spell_count > 0) {
                std::vector<int32> spells; spells.clear();
                aaCenter.AA_StringToVectorInt(conf.fm_spells, spells, ",");
                if (conf.fm_spell_count == spells.size()) {
                    for (uint32 i = 0; i<conf.fm_spell_count; i++) {
                        int32 spellid = spells[i];
                        QueryResult result = WorldDatabase.PQuery("SELECT 客户端显示 FROM _模板_物品技能 where id = {}", spellid);
                        if (result) {
                            Field* fields = result->Fetch();
                            std::string text = fields[0].GetString();
                            AddGossipItemFor(player, GossipOptionNpc(0), text, sindex, 0);
                            sindex++;
                            type_ids.push_back(spellid);
                        }
                    }
                    scount = sindex - 10000;
                }
            }
            if (vindex > 0 || sindex > 0) {
                SendGossipMenuFor(player, DEFAULT_GOSSIP_MESSAGE, item->GetGUID());
            } else {
                aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000该装备无法萃取!");
            }
        }
        return true; // Cast the spell on use normally
    }
    
    void OnGossipSelect(Player* player, Item* item, uint32 action, uint32 /*menuid*/) override
    {
        if (!aaCenter.AA_VerifyCode("a103b")) {
            return;
        }
        if (!player->aa_target_item || player->aa_target_item->GetState() == ITEM_REMOVED || !player->aa_target_item->IsInWorld()) {
            aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000该装备无法萃取!");
            return;
        }
        
        std::string name = "";
        //判断萃取或传承
        AA_Character_Instance conf = aaCenter.aa_character_instances[item->GetGUIDLow()];
        AA_Character_Instance conf2 = aaCenter.aa_character_instances[player->aa_target_item->GetGUIDLow()];
        if (conf.fm_value_count > 0 || conf.fm_spell_count > 0) { //传承
            size_t vaction = 0;
            size_t saction = 0;
            if (action >= 10000) {
                saction = action - 10000;
            } else {
                vaction = action;
            }
            std::string vstr = "";
            std::string sstr = "";
            std::string name = "";
            //清空mu
            if (action < 10000 && type_ids.size() > vaction && conf.fm_value_count > 0 && conf2.fm_value_count > 0) { //传承属性
                std::vector<int32> types; types.clear();
                std::vector<int32> values; values.clear();
                aaCenter.AA_StringToVector2(conf.fm_values, types, values);
                
                std::vector<int32> types2; types2.clear();
                std::vector<int32> values2; values2.clear();
                aaCenter.AA_StringToVector2(conf2.fm_values, types2, values2);
                
                int32 type = AA_SafeObjectAtIndex(types, 0);
                int32 value = AA_SafeObjectAtIndex(values, 0);
                if (value == 0) {
                    aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000该物品没有觉醒属性，无法传承!");
                    return;
                }
                std::map<int32, int32> cuiqus; cuiqus.clear();
                for (size_t i = 0; i < types2.size(); i++)
                {
                    uint32 type = types2[i];
                    AA_Stat conf = aaCenter.aa_stats[type];
                    cuiqus[i] = conf.cuiqu_only;
                }
                AA_Stat a_conf = aaCenter.aa_stats[type];
                if (types2.size() > action && types2.size() == values2.size()) {
                    for (size_t i = 0; i<types.size(); i++) {
                        uint32 type_id = types[i];
                        AA_Stat s_conf = aaCenter.aa_stats[type_id];
                        for (auto itr : cuiqus) {
                            int32 index = itr.first;
                            uint32 only = itr.second;
                            if (only > 0 && only == s_conf.cuiqu_only) {
                                vaction = index;
                            }
                        }
                    }
                    types2[vaction] = type;
                    values2[vaction] = value;
                    std::string fm_values = "";
                    aaCenter.AA_VectorToString(fm_values, types2, values2);
                    aaCenter.aa_character_instances[player->aa_target_item->GetGUIDLow()].fm_values = fm_values;
                    time_t timep;
                    time(&timep);
                    aaCenter.aa_character_instances[player->aa_target_item->GetGUIDLow()].isUpdate = true;
                    aaCenter.aa_character_instances[player->aa_target_item->GetGUIDLow()].update_time = timep;
                    name = "+"+std::to_string(value)+a_conf.text;
                    AA_Message aa_message;
                    aa_message.use_item = item;
                    aa_message.target_item = player->aa_target_item;
                    AA_Notice notice = aaCenter.aa_notices[23];
                    notice.msg = name;
                    aaCenter.AA_SendNotice(player, notice, true, aa_message);
                    uint32 count = 1;
                    player->DestroyItemCount(item, count, true);
                }
            } else if ( type_ids.size() > saction && conf.fm_spell_count > 0 && conf2.fm_spell_count > 0) { //传承技能
                std::vector<int32> spells; spells.clear();
                aaCenter.AA_StringToVectorInt(conf.fm_spells, spells, ",");
                
                std::vector<int32> spells2; spells2.clear();
                aaCenter.AA_StringToVectorInt(conf2.fm_spells, spells2, ",");
                
                uint32 spellid = AA_SafeObjectAtIndex(spells, 0);
                if (spellid == 0) {
                    aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000该物品没有觉醒技能，无法传承!");
                    return;
                }
                std::map<int32, int32> cuiqus; cuiqus.clear();
                for (size_t i = 0; i < spells2.size(); i++)
                {
                    uint32 spellid = spells2[i];
                    AA_Spell conf = aaCenter.aa_spells[spellid];
                    cuiqus[i] = conf.cuiqu_only;
                }
                if (spells2.size() > saction) {
                    for (size_t i = 0; i<spells.size(); i++) {
                        uint32 spell_id = spells[i];
                        AA_Spell s_conf = aaCenter.aa_spells[spell_id];
                        for (auto itr : cuiqus) {
                            int32 index = itr.first;
                            uint32 only = itr.second;
                            if (only > 0 && only == s_conf.cuiqu_only) {
                                saction = index;
                            }
                        }
                    }
                    
                    spells2[saction] = spellid;
                    std::string fm_spells = "";
                    aaCenter.AA_VectorIntToString(fm_spells, spells2, ",");
                    aaCenter.aa_character_instances[player->aa_target_item->GetGUIDLow()].fm_spells = fm_spells;
                    time_t timep;
                    time(&timep);
                    aaCenter.aa_character_instances[player->aa_target_item->GetGUIDLow()].isUpdate = true;
                    aaCenter.aa_character_instances[player->aa_target_item->GetGUIDLow()].update_time = timep;
                    QueryResult result = WorldDatabase.PQuery("SELECT 客户端显示 FROM _模板_物品技能 where id = {}", spellid);
                    if (result) {
                        Field* fields = result->Fetch();
                        name = fields[0].GetString();
                    }
                    AA_Message aa_message;
                    aa_message.use_item = item;
                    aa_message.target_item = player->aa_target_item;
                    AA_Notice notice = aaCenter.aa_notices[23];
                    notice.msg = name;
                    aaCenter.AA_SendNotice(player, notice, true, aa_message);
                    uint32 count = 1;
                    player->DestroyItemCount(item, count, true);
                }
            }
            player->aa_item = nullptr;
            player->aa_target_item = nullptr;
        } else { //萃取
            //装备萃取
            size_t vaction = 0;
            size_t saction = 0;
            if (action >= 10000) {
                saction = action - 10000;
            } else {
                vaction = action;
            }
            std::string vstr = "";
            std::string sstr = "";
            //清空mu
            AA_Character_Instance conf = aaCenter.aa_character_instances[player->aa_target_item->GetGUIDLow()];
            if (action < 10000 && type_ids.size() > vaction) { //萃取属性
                std::vector<int32> types; types.clear();
                std::vector<int32> values; values.clear();
                aaCenter.AA_StringToVector2(conf.fm_values, types, values);
                if (types.size() > action && types.size() == values.size()) {
                    int32 type = types[action];
                    int32 value = values[action];
                    if (type == 999999) {
                        aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000无法萃取插槽!");
                        CloseGossipMenuFor(player);
                        return;
                    }
                    vstr = std::to_string(type) + " " + std::to_string(value);
                    AA_Stat conf = aaCenter.aa_stats[type];
                    if (conf.cuiqu_need > 0) {
                        if (!aaCenter.M_CanNeed(player, conf.cuiqu_need)) {
                            return;
                        } else {
                            aaCenter.M_Need(player, conf.cuiqu_need);
                        }
                    }
                    name = "+"+std::to_string(value)+conf.text;
                    types[action] = 999999;
                    values[action] = 0;
                    std::string fm_values = "";
                    aaCenter.AA_VectorToString(fm_values, types, values);
                    aaCenter.aa_character_instances[player->aa_target_item->GetGUIDLow()].fm_values = fm_values;
                }
            } else if ( type_ids.size() > saction) { //萃取技能
                std::vector<int32> spells; spells.clear();
                aaCenter.AA_StringToVectorInt(conf.fm_spells, spells, ",");
                if (spells.size() > (action-10000)) {
                    int32 spellid = spells[action-10000];
                    if (spellid == 999999) {
                        aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000无法萃取插槽!");
                        CloseGossipMenuFor(player);
                        return;
                    }
                    sstr = std::to_string(spellid);
                    AA_Spell conf = aaCenter.aa_spells[spellid];
                    if (conf.cuiqu_need > 0) {
                        if (!aaCenter.M_CanNeed(player, conf.cuiqu_need)) {
                            return;
                        } else {
                            aaCenter.M_Need(player, conf.cuiqu_need);
                        }
                    }
                    QueryResult result = WorldDatabase.PQuery("SELECT 客户端显示 FROM _模板_物品技能 where id = {}", spellid);
                    if (result) {
                        Field* fields = result->Fetch();
                        name = fields[0].GetString();
                    }
                    spells[action - 10000] = 999999;
                    std::string fm_spells = "";
                    aaCenter.AA_VectorIntToString(fm_spells, spells, ",");
                    aaCenter.aa_character_instances[player->aa_target_item->GetGUIDLow()].fm_spells = fm_spells;
                }
            }
            time_t timep;
            time(&timep);
            aaCenter.aa_character_instances[player->aa_target_item->GetGUIDLow()].isUpdate = true;
            aaCenter.aa_character_instances[player->aa_target_item->GetGUIDLow()].update_time = timep;
            //萃取券
            if (vstr != "") { // 属性
                aaCenter.aa_character_instances[item->GetGUIDLow()].fm_value_count = 1;
            } else {
                aaCenter.aa_character_instances[item->GetGUIDLow()].fm_value_count = 0;
            }
            if (sstr != "") { // 技能
                aaCenter.aa_character_instances[item->GetGUIDLow()].fm_spell_count = 1;
            } else {
                aaCenter.aa_character_instances[item->GetGUIDLow()].fm_spell_count = 0;
            }
            std::string val2 = aaCenter.aa_cuiqu_items[item->GetEntry()].cuiqu_pos;
            if (val2 != "0" && val2 != "" && player->aa_target_item) {
                std::vector<int32> vals; vals.clear();
                aaCenter.AA_StringToVectorInt(val2, vals, ",");
                ItemTemplate const* tpProto = player->aa_target_item->GetTemplate();
                if (tpProto) {
                    if (std::find(vals.begin(), vals.end(), tpProto->GetInventoryType()) != vals.end()) {
                        aaCenter.aa_character_instances[item->GetGUIDLow()].cuiqu_pos = tpProto->GetInventoryType();
                    }
                }
            }
            aaCenter.aa_character_instances[item->GetGUIDLow()].fm_values = vstr;
            aaCenter.aa_character_instances[item->GetGUIDLow()].fm_spells = sstr;
            aaCenter.aa_character_instances[item->GetGUIDLow()].isUpdate = true;
            aaCenter.aa_character_instances[item->GetGUIDLow()].update_time = timep;
            ItemTemplate const* pProto = item->GetTemplate();
            if (pProto) {
                AA_Cuiqu_Item conf_c;
                uint32 itemid = pProto->GetId();
                conf_c = aaCenter.aa_cuiqu_items[itemid];
                if (conf_c.need > 0) {
                    aaCenter.M_Need(player, conf_c.need);
                }
            }
            AA_Message aa_message;
            aa_message.use_item = item;
            aa_message.target_item = player->aa_target_item;
            AA_Notice notice = aaCenter.aa_notices[23];
            notice.msg = name;
            aaCenter.AA_SendNotice(player, notice, false, aa_message);
            player->aa_item = nullptr;
            player->aa_target_item = nullptr;
        }
        
        CloseGossipMenuFor(player);
    }
};

void AddAA_Item_Cuiqu()
{
    new aa_item_cuiqu();
}
