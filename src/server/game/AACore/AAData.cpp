#include "AAData.h"
#include "Player.h"

using namespace std;

AAData* AAData::instance()
{
    static AAData instance;
    return &instance;
}
void AAData::AA_UPD_Character_Paihang(Player* player, CharacterDatabaseTransaction& trans)
{
    ObjectGuid::LowType guidlow = player->GetGUIDLow();
    {
        CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(_AA_UPD_Character_Paihang_Jisha);
        //stmt->SetData(0, aaCenter.aa_jishas[guidlow]);
        //stmt->SetData(1, guidlow);
        trans->Append(stmt);
    }
    {
        CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(_AA_UPD_Character_Paihang_Renwu);
        //stmt->SetData(0, aaCenter.aa_renwus[guidlow]);
        //stmt->SetData(1, guidlow);
        trans->Append(stmt);
    }
}
void AAData::AA_REP_Character_Instance(Player* player, CharacterDatabaseTransaction& trans)
{
    ObjectGuid::LowType guidlow = player->GetGUIDLow();
    for (auto iter : aaCenter.aa_character_instances) {
        AA_Character_Instance conf = iter.second;
        if (!conf.isUpdate || guidlow != conf.owner_guid) {
            continue;
        }
        aaCenter.aa_character_instances[iter.first].isUpdate = false;
        CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(_AA_REP_Character_Instance);
        //stmt->SetData(0, iter.first);
        //stmt->SetData(1, conf.itemEntry);
        //stmt->SetData(2, conf.owner_guid);
        //stmt->SetData(3, conf.name);
        //stmt->SetData(4, conf.fugai_zu);
        //stmt->SetData(5, conf.fugai);
        //stmt->SetData(6, conf.jd_zu);
        //stmt->SetData(7, conf.jd_id);
        //stmt->SetData(8, conf.jd_level);
        //stmt->SetData(9, conf.jd_values);
        //stmt->SetData(10, conf.qh_zu);
        //stmt->SetData(11, conf.qh_id);
        //stmt->SetData(12, conf.qh_level);
        //stmt->SetData(13, conf.qh_values);
        //stmt->SetData(14, conf.qh_reward_value);
        //stmt->SetData(15, conf.qh_reward_point);
        //stmt->SetData(16, conf.qh_reward_spell);
        //stmt->SetData(17, conf.cz_zu);
        //stmt->SetData(18, conf.cz_id);
        //stmt->SetData(19, conf.cz_level);
        //stmt->SetData(20, conf.cz_exp);
        //stmt->SetData(21, conf.cz_values);
        //stmt->SetData(22, conf.cz_reward_value);
        //stmt->SetData(23, conf.cz_reward_point);
        //stmt->SetData(24, conf.cz_reward_spell);
        //stmt->SetData(25, conf.fm_spell_count);
        //stmt->SetData(26, conf.fm_spells);
        //stmt->SetData(27, conf.fm_value_count);
        //stmt->SetData(28, conf.fm_values);
        //stmt->SetData(29, conf.chongzhu_count);
        //stmt->SetData(30, conf.chongzhu_value);
        //stmt->SetData(31, conf.chongzhu_spell);
        //stmt->SetData(32, conf.fw_count);
        //stmt->SetData(33, conf.fw_values);
        //stmt->SetData(34, conf.fwzh_values);
        //stmt->SetData(35, conf.cuiqu_pos);
        //stmt->SetData(36, conf.baoshi_entry);
        //stmt->SetData(37, conf.item_set);
        //stmt->SetData(38, conf.update_time);
        trans->Append(stmt);
    }
}
void AAData::AA_REP_Characters(Player* player, CharacterDatabaseTransaction& trans)
{
    ObjectGuid::LowType guidlow = player->GetGUIDLow();
    for (auto iter : aaCenter.aa_characterss) {
        AA_Characters conf = iter.second;
        if (!conf.isUpdate || iter.first != guidlow) {
            continue;
        }
        aaCenter.aa_characterss[iter.first].isUpdate = false;
        CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(_AA_REP_Characters);
        //stmt->SetData(0, iter.first);
        //stmt->SetData(1, conf.playtime);
        //stmt->SetData(2, conf.shengji);
        //stmt->SetData(3, conf.tianfu);
        //stmt->SetData(4, conf.choujiang);
        //stmt->SetData(5, conf.choujianglq);
        //stmt->SetData(6, conf.buy_time);
        //stmt->SetData(7, conf.buy_time_yj);
        //stmt->SetData(8, conf.zhaomu);
        //stmt->SetData(9, conf.diy_guid);
        //stmt->SetData(10, conf.name_pre);
        //stmt->SetData(11, conf.name_suf);
        //stmt->SetData(12, conf.update_time);
        trans->Append(stmt);
    }
}
void AAData::AA_REP_Character_Juanxian(Player* player, CharacterDatabaseTransaction& trans)
{
    ObjectGuid::LowType guidlow = player->GetGUIDLow();
    for (auto iter : aaCenter.aa_character_juanxians) {
        AA_Character_Juanxian conf = iter.second;
        if (!conf.isUpdate || iter.first != guidlow) {
            continue;
        }
        aaCenter.aa_character_juanxians[iter.first].isUpdate = false;
        CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(_AA_REP_Character_Juanxian);
        //stmt->SetData(0, iter.first);
        //stmt->SetData(1, conf.name);
        //stmt->SetData(2, conf.juanxian);
        //stmt->SetData(3, conf.update_time);
        trans->Append(stmt);
    }
}
void AAData::AA_REP_Systems(CharacterDatabaseTransaction& trans)
{
    AA_System conf = aaCenter.aa_system_conf;
    if (!conf.isUpdate) {
        return;
    }
    aaCenter.aa_system_conf.isUpdate = false;
    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(_AA_REP_Systems);
    //stmt->SetData(0, 0);
    //stmt->SetData(1, conf.diy_system);
    //stmt->SetData(2, conf.update_time);
    trans->Append(stmt);
}
void AAData::AA_REP_Characters_Dianfeng(Player* player, CharacterDatabaseTransaction& trans)
{
    ObjectGuid::LowType guidlow = player->GetGUIDLow();
    for (auto iter : aaCenter.aa_characters_dianfengs) {
        AA_Characters_Dianfeng conf = iter.second;
        if (!conf.isUpdate || iter.first != guidlow) {
            continue;
        }
        aaCenter.aa_characters_dianfengs[iter.first].isUpdate = false;
        CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(_AA_REP_Characters_Dianfeng);
        //stmt->SetData(0, iter.first);
        //stmt->SetData(1, conf.level);
        //stmt->SetData(2, conf.exp);
        //stmt->SetData(3, conf.dianshu_all);
        //stmt->SetData(4, conf.dianshu);
        //stmt->SetData(5, conf.tianfu);
        //stmt->SetData(6, conf.value);
        //stmt->SetData(7, conf.update_time);
        trans->Append(stmt);
    }
}
void AAData::AA_REP_Characters_Douqi(Player* player, CharacterDatabaseTransaction& trans)
{
    ObjectGuid::LowType guidlow = player->GetGUIDLow();
    for (auto iter : aaCenter.aa_characters_douqis) {
        AA_Characters_Douqi conf = iter.second;
        if (!conf.isUpdate || iter.first != guidlow) {
            continue;
        }
        aaCenter.aa_characters_douqis[iter.first].isUpdate = false;
        CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(_AA_REP_Characters_Douqi);
        //stmt->SetData(0, iter.first);
        //stmt->SetData(1, conf.level);
        //stmt->SetData(2, conf.exp);
        //stmt->SetData(3, conf.dianshu_all);
        //stmt->SetData(4, conf.dianshu);
        //stmt->SetData(5, conf.tianfu);
        //stmt->SetData(6, conf.value);
        //stmt->SetData(7, conf.update_time);
        trans->Append(stmt);
    }
}
void AAData::AA_REP_Characters_Junxian(Player* player, CharacterDatabaseTransaction& trans)
{
    ObjectGuid::LowType guidlow = player->GetGUIDLow();
    for (auto iter : aaCenter.aa_characters_junxians) {
        AA_Characters_Junxian conf = iter.second;
        if (!conf.isUpdate || iter.first != guidlow) {
            continue;
        }
        aaCenter.aa_characters_junxians[iter.first].isUpdate = false;
        CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(_AA_REP_Characters_Junxian);
        //stmt->SetData(0, iter.first);
        //stmt->SetData(1, conf.level);
        //stmt->SetData(2, conf.exp);
        //stmt->SetData(3, conf.dianshu_all);
        //stmt->SetData(4, conf.dianshu);
        //stmt->SetData(5, conf.tianfu);
        //stmt->SetData(6, conf.value);
        //stmt->SetData(7, conf.update_time);
        trans->Append(stmt);
    }
}
void AAData::AA_REP_Account(Player* player, LoginDatabaseTransaction& trans)
{
    if (!player || !player->IsInWorld()) {
        return;
    }
    uint32 accountid = player->GetSession()->GetAccountId();
    for (auto iter : aaCenter.aa_accounts) {
        AA_Account conf = iter.second;
        if (!conf.isUpdate || iter.first != accountid) {
            continue;
        }
        aaCenter.aa_accounts[iter.first].isUpdate = false;
        LoginDatabasePreparedStatement* stmt = LoginDatabase.GetPreparedStatement(_AA_REP_Account);
        //stmt->SetData(0, iter.first);
        //stmt->SetData(1, conf.vip);
        //stmt->SetData(2, conf.jifen);
        //stmt->SetData(3, conf.jifen_cz);
        //stmt->SetData(4, conf.jifen_all);
        //stmt->SetData(5, conf.paodian);
        //stmt->SetData(6, conf.mobi);
        //stmt->SetData(7, conf.battlecore);
        //stmt->SetData(8, conf.jifen_day);
        //stmt->SetData(9, conf.shouchong_day);
        //stmt->SetData(10, conf.shouchong);
        //stmt->SetData(11, conf.leichong);
        //stmt->SetData(12, conf.denglu_day);
        //stmt->SetData(13, conf.denglu);
        //stmt->SetData(14, conf.denglu_qiandao);
        //stmt->SetData(15, conf.licai_day);
        //stmt->SetData(16, conf.licai);
        //stmt->SetData(17, conf.buy_time);
        //stmt->SetData(18, conf.buy_time_yj);
        //stmt->SetData(19, conf.diy_account);
        //stmt->SetData(20, conf.update_time);

        //stmt->SetData(21, conf.vip);
        //stmt->SetData(22, conf.jifen);
        //stmt->SetData(23, conf.jifen_all);
        //stmt->SetData(24, conf.paodian);
        //stmt->SetData(25, conf.mobi);
        //stmt->SetData(26, conf.battlecore);
        //stmt->SetData(27, conf.jifen_day);
        //stmt->SetData(28, conf.shouchong_day);
        //stmt->SetData(29, conf.shouchong);
        //stmt->SetData(30, conf.leichong);
        //stmt->SetData(31, conf.denglu_day);
        //stmt->SetData(32, conf.denglu);
        //stmt->SetData(33, conf.denglu_qiandao);
        //stmt->SetData(34, conf.licai_day);
        //stmt->SetData(35, conf.licai);
        //stmt->SetData(36, conf.buy_time);
        //stmt->SetData(37, conf.buy_time_yj);
        //stmt->SetData(38, conf.diy_account);
        //stmt->SetData(39, conf.update_time);
        trans->Append(stmt);
    }
}

void AAData::AA_REP_Player_Map_Value(Player* player, CharacterDatabaseTransaction& trans)
{
    ObjectGuid::LowType guidlow = player->GetGUIDLow();
    for (auto iter : aaCenter.aa_player_map_values) {
        int32 mapid = iter.first;
        for (auto itr : iter.second) {
            AA_Player_Map_Value conf = itr.second;
            if (!conf.isUpdate || itr.first != guidlow) {
                continue;
            }
            aaCenter.aa_player_map_values[mapid][guidlow].isUpdate = false;
            CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(_AA_REP_Player_Map_Value);
            //stmt->SetData(0, guidlow);
            //stmt->SetData(1, mapid);
            //stmt->SetData(2, conf.valueb);
            //stmt->SetData(3, conf.valuev);
            //stmt->SetData(4, conf.update_time);
            //stmt->SetData(5, conf.valueb);
            //stmt->SetData(6, conf.valuev);
            //stmt->SetData(7, conf.update_time);
            trans->Append(stmt);
        }
    }
}
void AAData::AA_REP_Player_Zone_Value(Player* player, CharacterDatabaseTransaction& trans)
{
    ObjectGuid::LowType guidlow = player->GetGUIDLow();
    for (auto iter : aaCenter.aa_player_zone_values) {
        int32 mapid = iter.first;
        for (auto itr : iter.second) {
            AA_Player_Zone_Value conf = itr.second;
            if (!conf.isUpdate || itr.first != guidlow) {
                continue;
            }
            aaCenter.aa_player_zone_values[mapid][guidlow].isUpdate = false;
            CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(_AA_REP_Player_Zone_Value);
            //stmt->SetData(0, guidlow);
            //stmt->SetData(1, mapid);
            //stmt->SetData(2, conf.valueb);
            //stmt->SetData(3, conf.valuev);
            //stmt->SetData(4, conf.update_time);
            //stmt->SetData(5, conf.valueb);
            //stmt->SetData(6, conf.valuev);
            //stmt->SetData(7, conf.update_time);
            trans->Append(stmt);
        }
    }
}
void AAData::AA_REP_Player_Area_Value(Player* player, CharacterDatabaseTransaction& trans)
{
    ObjectGuid::LowType guidlow = player->GetGUIDLow();
    for (auto iter : aaCenter.aa_player_area_values) {
        int32 mapid = iter.first;
        for (auto itr : iter.second) {
            AA_Player_Area_Value conf = itr.second;
            if (!conf.isUpdate || itr.first != guidlow) {
                continue;
            }
            aaCenter.aa_player_area_values[mapid][guidlow].isUpdate = false;
            CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(_AA_REP_Player_Area_Value);
            //stmt->SetData(0, guidlow);
            //stmt->SetData(1, mapid);
            //stmt->SetData(2, conf.valueb);
            //stmt->SetData(3, conf.valuev);
            //stmt->SetData(4, conf.update_time);
            //stmt->SetData(5, conf.valueb);
            //stmt->SetData(6, conf.valuev);
            //stmt->SetData(7, conf.update_time);
            trans->Append(stmt);
        }
    }
}
void AAData::AA_REP_Player_Instance_Value(Player* player, CharacterDatabaseTransaction& trans)
{
    ObjectGuid::LowType guidlow = player->GetGUIDLow();
    for (auto iter : aaCenter.aa_player_instance_values) {
        int32 mapid = iter.first;
        for (auto itr : iter.second) {
            AA_Player_Instance_Value conf = itr.second;
            if (!conf.isUpdate || itr.first != guidlow) {
                continue;
            }
            aaCenter.aa_player_instance_values[mapid][guidlow].isUpdate = false;
            CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(_AA_REP_Player_Instance_Value);
            //stmt->SetData(0, guidlow);
            //stmt->SetData(1, mapid);
            //stmt->SetData(2, conf.valueb);
            //stmt->SetData(3, conf.valuev);
            //stmt->SetData(4, conf.update_time);
            //stmt->SetData(5, conf.valueb);
            //stmt->SetData(6, conf.valuev);
            //stmt->SetData(7, conf.update_time);
            trans->Append(stmt);
        }
    }
}
void AAData::AA_REP_Map_Map_Value(CharacterDatabaseTransaction& trans)
{
    for (auto iter : aaCenter.aa_map_map_values) {
        AA_Map_Map_Value conf = iter.second;
        if (!conf.isUpdate) {
            continue;
        }
        aaCenter.aa_map_map_values[iter.first].isUpdate = false;
        CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(_AA_REP_Map_Map_Value);
        //stmt->SetData(0, iter.first);
        //stmt->SetData(1, conf.valueb);
        //stmt->SetData(2, conf.valuev);
        //stmt->SetData(3, conf.update_time);
        //stmt->SetData(4, conf.valueb);
        //stmt->SetData(5, conf.valuev);
        //stmt->SetData(6, conf.update_time);
        trans->Append(stmt);
    }
}
void AAData::AA_REP_Map_Zone_Value(CharacterDatabaseTransaction& trans)
{
    for (auto iter : aaCenter.aa_map_zone_values) {
        AA_Map_Zone_Value conf = iter.second;
        if (!conf.isUpdate) {
            continue;
        }
        aaCenter.aa_map_zone_values[iter.first].isUpdate = false;
        CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(_AA_REP_Map_Zone_Value);
        //stmt->SetData(0, iter.first);
        //stmt->SetData(1, conf.valueb);
        //stmt->SetData(2, conf.valuev);
        //stmt->SetData(3, conf.update_time);
        //stmt->SetData(4, conf.valueb);
        //stmt->SetData(5, conf.valuev);
        //stmt->SetData(6, conf.update_time);
        trans->Append(stmt);
    }
}
void AAData::AA_REP_Map_Area_Value(CharacterDatabaseTransaction& trans)
{
    for (auto iter : aaCenter.aa_map_area_values) {
        AA_Map_Area_Value conf = iter.second;
        if (!conf.isUpdate) {
            continue;
        }
        aaCenter.aa_map_area_values[iter.first].isUpdate = false;
        CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(_AA_REP_Map_Area_Value);
        //stmt->SetData(0, iter.first);
        //stmt->SetData(1, conf.valueb);
        //stmt->SetData(2, conf.valuev);
        //stmt->SetData(3, conf.update_time);
        //stmt->SetData(4, conf.valueb);
        //stmt->SetData(5, conf.valuev);
        //stmt->SetData(6, conf.update_time);
        trans->Append(stmt);
    }
}
void AAData::AA_REP_Map_Instance_Value(CharacterDatabaseTransaction& trans)
{
    for (auto iter : aaCenter.aa_map_instance_values) {
        AA_Map_Instance_Value conf = iter.second;
        if (!conf.isUpdate) {
            continue;
        }
        aaCenter.aa_map_instance_values[iter.first].isUpdate = false;
        CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(_AA_REP_Map_Instance_Value);
        //stmt->SetData(0, iter.first);
        //stmt->SetData(1, conf.valueb);
        //stmt->SetData(2, conf.valuev);
        //stmt->SetData(3, conf.update_time);
        //stmt->SetData(4, conf.valueb);
        //stmt->SetData(5, conf.valuev);
        //stmt->SetData(6, conf.update_time);
        trans->Append(stmt);
    }
}
void AAData::AA_REP_Item_Instance(CharacterDatabaseTransaction& trans)
{
    for (auto iter : aaCenter.aa_item_instances) {
        AA_Item_Instance conf = iter.second;
        if (!conf.isUpdate) {
            continue;
        }
        aaCenter.aa_item_instances[iter.first].isUpdate = false;
        CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(_AA_REP_Item_Instance);
        //stmt->SetData(0, conf.guid);
        //stmt->SetData(1, conf.itemEntry);
        //stmt->SetData(2, conf.owner_guid);
        //stmt->SetData(3, conf.creatorGuid);
        //stmt->SetData(4, conf.giftCreatorGuid);
        //stmt->SetData(5, conf.count);
        //stmt->SetData(6, conf.duration);
        //stmt->SetData(7, conf.charges);
        //stmt->SetData(8, conf.flags);
        //stmt->SetData(9, conf.enchantments);
        //stmt->SetData(10, conf.randomPropertyId);
        //stmt->SetData(11, conf.durability);
        //stmt->SetData(12, conf.playedTime);
        //stmt->SetData(13, conf.text);
        //stmt->SetData(14, conf.weizhi);
        //stmt->SetData(15, conf.update_time);
        trans->Append(stmt);
    }
}
