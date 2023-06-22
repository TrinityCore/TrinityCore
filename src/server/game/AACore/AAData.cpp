#include "AAData.h"
#include "Player.h"


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
        stmt->setUInt32(0, aaCenter.aa_jishas[guidlow]);
        stmt->setUInt64(1, guidlow);
        trans->Append(stmt);
    }
    {
        CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(_AA_UPD_Character_Paihang_Renwu);
        stmt->setUInt32(0, aaCenter.aa_renwus[guidlow]);
        stmt->setUInt64(1, guidlow);
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
        stmt->setUInt64(0, iter.first);
        stmt->setUInt32(1, conf.itemEntry);
        stmt->setUInt64(2, conf.owner_guid);
        stmt->setString(3, conf.name);
        stmt->setUInt32(4, conf.fugai_zu);
        stmt->setString(5, conf.fugai);
        stmt->setUInt32(6, conf.jd_zu);
        stmt->setUInt32(7, conf.jd_id);
        stmt->setUInt32(8, conf.jd_level);
        stmt->setString(9, conf.jd_values);
        stmt->setUInt32(10, conf.qh_zu);
        stmt->setUInt32(11, conf.qh_id);
        stmt->setUInt32(12, conf.qh_level);
        stmt->setString(13, conf.qh_values);
        stmt->setUInt32(14, conf.qh_reward_value);
        stmt->setUInt32(15, conf.qh_reward_point);
        stmt->setString(16, conf.qh_reward_spell);
        stmt->setUInt32(17, conf.cz_zu);
        stmt->setUInt32(18, conf.cz_id);
        stmt->setUInt32(19, conf.cz_level);
        stmt->setUInt32(20, conf.cz_exp);
        stmt->setString(21, conf.cz_values);
        stmt->setUInt32(22, conf.cz_reward_value);
        stmt->setUInt32(23, conf.cz_reward_point);
        stmt->setString(24, conf.cz_reward_spell);
        stmt->setUInt32(25, conf.fm_spell_count);
        stmt->setString(26, conf.fm_spells);
        stmt->setUInt32(27, conf.fm_value_count);
        stmt->setString(28, conf.fm_values);
        stmt->setUInt32(29, conf.chongzhu_count);
        stmt->setUInt32(30, conf.chongzhu_value);
        stmt->setUInt32(31, conf.chongzhu_spell);
        stmt->setUInt32(32, conf.fw_count);
        stmt->setString(33, conf.fw_values);
        stmt->setString(34, conf.fwzh_values);
        stmt->setInt32(35, conf.cuiqu_pos);
        stmt->setUInt32(36, conf.baoshi_entry);
        stmt->setUInt32(37, conf.item_set);
        stmt->setUInt32(38, conf.update_time);
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
        stmt->setUInt64(0, iter.first);
        stmt->setUInt32(1, conf.playtime);
        stmt->setString(2, conf.shengji);
        stmt->setUInt32(3, conf.tianfu);
        stmt->setUInt32(4, conf.choujiang);
        stmt->setUInt32(5, conf.choujianglq);
        stmt->setString(6, conf.buy_time);
        stmt->setString(7, conf.buy_time_yj);
        stmt->setString(8, conf.zhaomu);
        stmt->setString(9, conf.diy_guid);
        stmt->setString(10, conf.name_pre);
        stmt->setString(11, conf.name_suf);
        stmt->setUInt32(12, conf.update_time);
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
        stmt->setUInt64(0, iter.first);
        stmt->setString(1, conf.name);
        stmt->setUInt32(2, conf.juanxian);
        stmt->setUInt32(3, conf.update_time);
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
    stmt->setUInt32(0, 0);
    stmt->setString(1, conf.diy_system);
    stmt->setUInt32(2, conf.update_time);
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
        stmt->setUInt64(0, iter.first);
        stmt->setUInt32(1, conf.level);
        stmt->setUInt32(2, conf.exp);
        stmt->setUInt32(3, conf.dianshu_all);
        stmt->setInt32(4, conf.dianshu);
        stmt->setUInt32(5, conf.tianfu);
        stmt->setString(6, conf.value);
        stmt->setUInt32(7, conf.update_time);
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
        stmt->setUInt64(0, iter.first);
        stmt->setUInt32(1, conf.level);
        stmt->setUInt32(2, conf.exp);
        stmt->setUInt32(3, conf.dianshu_all);
        stmt->setInt32(4, conf.dianshu);
        stmt->setUInt32(5, conf.tianfu);
        stmt->setString(6, conf.value);
        stmt->setUInt32(7, conf.update_time);
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
        stmt->setUInt64(0, iter.first);
        stmt->setUInt32(1, conf.level);
        stmt->setUInt32(2, conf.exp);
        stmt->setUInt32(3, conf.dianshu_all);
        stmt->setInt32(4, conf.dianshu);
        stmt->setUInt32(5, conf.tianfu);
        stmt->setString(6, conf.value);
        stmt->setUInt32(7, conf.update_time);
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
        stmt->setUInt64(0, iter.first);
        stmt->setUInt32(1, conf.vip);
        stmt->setUInt32(2, conf.jifen);
        stmt->setUInt32(3, conf.jifen_cz);
        stmt->setUInt32(4, conf.jifen_all);
        stmt->setUInt32(5, conf.paodian);
        stmt->setUInt32(6, conf.mobi);
        stmt->setUInt32(7, conf.battlecore);
        stmt->setUInt32(8, conf.jifen_day);
        stmt->setUInt32(9, conf.shouchong_day);
        stmt->setUInt32(10, conf.shouchong);
        stmt->setString(11, conf.leichong);
        stmt->setUInt32(12, conf.denglu_day);
        stmt->setString(13, conf.denglu);
        stmt->setUInt32(14, conf.denglu_qiandao);
        stmt->setUInt32(15, conf.licai_day);
        stmt->setUInt32(16, conf.licai);
        stmt->setString(17, conf.buy_time);
        stmt->setString(18, conf.buy_time_yj);
        stmt->setString(19, conf.diy_account);
        stmt->setUInt32(20, conf.update_time);

        stmt->setUInt32(21, conf.vip);
        stmt->setUInt32(22, conf.jifen);
        stmt->setUInt32(23, conf.jifen_all);
        stmt->setUInt32(24, conf.paodian);
        stmt->setUInt32(25, conf.mobi);
        stmt->setUInt32(26, conf.battlecore);
        stmt->setUInt32(27, conf.jifen_day);
        stmt->setUInt32(28, conf.shouchong_day);
        stmt->setUInt32(29, conf.shouchong);
        stmt->setString(30, conf.leichong);
        stmt->setUInt32(31, conf.denglu_day);
        stmt->setString(32, conf.denglu);
        stmt->setUInt32(33, conf.denglu_qiandao);
        stmt->setUInt32(34, conf.licai_day);
        stmt->setUInt32(35, conf.licai);
        stmt->setString(36, conf.buy_time);
        stmt->setString(37, conf.buy_time_yj);
        stmt->setString(38, conf.diy_account);
        stmt->setUInt32(39, conf.update_time);
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
            stmt->setUInt64(0, guidlow);
            stmt->setInt32(1, mapid);
            stmt->setString(2, conf.valueb);
            stmt->setString(3, conf.valuev);
            stmt->setUInt32(4, conf.update_time);
            stmt->setString(5, conf.valueb);
            stmt->setString(6, conf.valuev);
            stmt->setUInt32(7, conf.update_time);
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
            stmt->setUInt64(0, guidlow);
            stmt->setInt32(1, mapid);
            stmt->setString(2, conf.valueb);
            stmt->setString(3, conf.valuev);
            stmt->setUInt32(4, conf.update_time);
            stmt->setString(5, conf.valueb);
            stmt->setString(6, conf.valuev);
            stmt->setUInt32(7, conf.update_time);
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
            stmt->setUInt64(0, guidlow);
            stmt->setInt32(1, mapid);
            stmt->setString(2, conf.valueb);
            stmt->setString(3, conf.valuev);
            stmt->setUInt32(4, conf.update_time);
            stmt->setString(5, conf.valueb);
            stmt->setString(6, conf.valuev);
            stmt->setUInt32(7, conf.update_time);
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
            stmt->setUInt64(0, guidlow);
            stmt->setInt32(1, mapid);
            stmt->setString(2, conf.valueb);
            stmt->setString(3, conf.valuev);
            stmt->setUInt32(4, conf.update_time);
            stmt->setString(5, conf.valueb);
            stmt->setString(6, conf.valuev);
            stmt->setUInt32(7, conf.update_time);
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
        stmt->setUInt64(0, iter.first);
        stmt->setString(1, conf.valueb);
        stmt->setString(2, conf.valuev);
        stmt->setUInt32(3, conf.update_time);
        stmt->setString(4, conf.valueb);
        stmt->setString(5, conf.valuev);
        stmt->setUInt32(6, conf.update_time);
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
        stmt->setUInt64(0, iter.first);
        stmt->setString(1, conf.valueb);
        stmt->setString(2, conf.valuev);
        stmt->setUInt32(3, conf.update_time);
        stmt->setString(4, conf.valueb);
        stmt->setString(5, conf.valuev);
        stmt->setUInt32(6, conf.update_time);
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
        stmt->setUInt64(0, iter.first);
        stmt->setString(1, conf.valueb);
        stmt->setString(2, conf.valuev);
        stmt->setUInt32(3, conf.update_time);
        stmt->setString(4, conf.valueb);
        stmt->setString(5, conf.valuev);
        stmt->setUInt32(6, conf.update_time);
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
        stmt->setUInt64(0, iter.first);
        stmt->setString(1, conf.valueb);
        stmt->setString(2, conf.valuev);
        stmt->setUInt32(3, conf.update_time);
        stmt->setString(4, conf.valueb);
        stmt->setString(5, conf.valuev);
        stmt->setUInt32(6, conf.update_time);
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
        stmt->setUInt64(0, conf.guid);
        stmt->setUInt32(1, conf.itemEntry);
        stmt->setUInt64(2, conf.owner_guid);
        stmt->setUInt64(3, conf.creatorGuid);
        stmt->setUInt64(4, conf.giftCreatorGuid);
        stmt->setUInt32(5, conf.count);
        stmt->setUInt32(6, conf.duration);
        stmt->setString(7, conf.charges);
        stmt->setUInt32(8, conf.flags);
        stmt->setString(9, conf.enchantments);
        stmt->setUInt32(10, conf.randomBonusListId);
        stmt->setUInt32(11, conf.durability);
        stmt->setUInt32(12, conf.playedTime);
        stmt->setString(13, conf.text);
        stmt->setUInt32(14, conf.transmogrification);
        stmt->setUInt32(15, conf.enchantIllusion);
        stmt->setUInt32(16, conf.battlePetSpeciesId);
        stmt->setUInt32(17, conf.battlePetBreedData);
        stmt->setUInt16(18, conf.battlePetLevel);
        stmt->setUInt32(19, conf.battlePetDisplayId);
        stmt->setUInt8(20, conf.context);
        stmt->setString(21, conf.bonusListIDs);
        stmt->setString(22, conf.weizhi);
        stmt->setUInt32(23, conf.update_time);
        trans->Append(stmt);
    }
}
